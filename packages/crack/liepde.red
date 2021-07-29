%******************************************************************************
%                                                                             *
% The program LIEPDE for computing point-, contact- and higher                *
% order symmetries of individual ODEs/PDEs or systems of ODEs/PDEs            *
%                                                                             *
% Author: Thomas Wolf                                                         *
% Date:   20. July 1996, 26. Nov 2006                                         *
%                                                                             *
% For details of how to use LIEPDE see the file LIEPDE.TXT or the             *
% header of the procedure LIEPDE below.                                       *
%                                                                             *
% BSDlicense:                                                                 *
%                                                                             *
% Redistribution and use in source and binary forms, with or without          *
% modification, are permitted provided that the following conditions are met: *
%                                                                             *
%    * Redistributions of source code must retain the relevant copyright      *
%      notice, this list of conditions and the following disclaimer.          *
%    * Redistributions in binary form must reproduce the above copyright      *
%      notice, this list of conditions and the following disclaimer in the    *
%      documentation and/or other materials provided with the distribution.   *
%                                                                             *
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE   *
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
% POSSIBILITY OF SUCH DAMAGE.                                                 *
%******************************************************************************

% $Id$
create!-package('(liepde), nil);     

symbolic fluid '(print_ logoprint_ adjust_fnc proc_list_
                 prelim_ individual_ prolong_order !*batch_mode
                 collect_sol flin_ lin_problem done_trafo 
                 etamn_al max_gc_fac batch_mode_sub
                 inverse_trafo_list_incomplete)$

lisp << !*batch_mode:=t$ prelim_:=nil$ 
        individual_:=nil$ prolong_order:=0;etamn_al:=nil >>$

%----------------------------

algebraic procedure equ_to_expr(a)$
% converts an equation into an expression
begin scalar lde;
 return
 if a=nil then a else
 <<lisp(lde:=reval algebraic a);
  if lisp(atom lde) then a else num
  if lisp(car lde = 'equal) then lhs a - rhs a
	      else a
 >>
end$ % of equ_to_expr


%********************************************************************
module pdesymmetry$
%********************************************************************
%  Routines for finding Symmetries of single or systems of ODEs/PDEs
%  Author: Thomas Wolf
%  July 1996

%---------------------

% Bei jedem totdf2-Aufruf pruefen, ob evtl. kuerzere dylist reicht
% evtl die combidiff-Kette und combi nicht mit in dylist, sond. erst in
% prolong jedesmal frisch generieren.

%---------------------

symbolic procedure comparedif3(du1,u2,u2list)$
% checks whether u2 differentiated wrt. u2list
% is a derivative of du1
begin
 scalar u1l;
 u1l:=combidif(du1)$ % u1l=(u1, 1, 1, ..)
 if car u1l neq u2 then return nil else
 return comparedif1(cdr u1l, u2list)
end$ % of comparedif3

%---------------------

%symbolic procedure orderofderiv(du)$
%if atom du then (length combidif(du))-1
%           else nil$

%---------------------

symbolic procedure mergedepli(li1,li2)$
% li1,li2 are lists of lists
% mergedepli merges the sublists to make one list of lists
begin scalar newdep;
  while li1 and li2 do <<
    newdep:=union(car li1, car li2) . newdep;
    li1:=cdr li1; li2:=cdr li2
  >>;
  return if li1 then nconc(reversip newdep,li1) else
         if li2 then nconc(reversip newdep,li2) else reversip newdep
end$

%---------------------

symbolic procedure adddepli(ex,revdylist)$
begin scalar a,b,c,d;
 for each a in revdylist do <<
  c:=nil;
  for each b in a do
  if not my_freeof(ex,b) then c:=b . c;
  if c or d then d:=c . d;
 >>;
 return list(ex,d)
end$

%---------------------

symbolic procedure add_xi_eta_depli(xilist,etalist,revdylist)$
begin
  scalar e1,g,h$
  for e1:=1:(length xilist) do <<
    g:=nth(xilist,e1);
    h:=pnth(g,4);
    rplaca(h,cadr adddepli(car g,revdylist))
  >>;
  for e1:=1:(length etalist) do <<
    g:=nth(etalist,e1);
    h:=pnth(g,3);
    rplaca(h,cadr adddepli(car g,revdylist))
  >>
end$

%---------------------

symbolic procedure subtest(uik,sb,xlist,ordok,subordinc)$
% uik is a derivative (jet variable)
% sb is a substitution list without prolongations
begin
  scalar el5,el6,el7,el8,el9,el10,sbc$
  el5:=combidif(uik);
  el6:=car el5; el5:=cdr el5;  % el6..function name, el5..var.list
  el7:=nil; el8:=100; el9:=nil;
  sbc:=sb;
  while sbc and
        ((caaar sbc neq el6) or
         (0 neq <<el7:=comparedif1(cdaar sbc,el5);
                  if el7 and (not zerop el7) and
                     (length(el7)<el8) then
                  <<el8 :=length el7;
                    el9 :=el7;
                    el10:=car sbc
                  >>    else el7
                >>)
        ) do sbc:=cdr sbc;
  return
  if sbc then ((simp!* cadar sbc) . caddar sbc)         % simple substitution
         else
  if el9 then <<    % uik is total deriv of car el10 wrt el9
    uik:=(simp!* cadr el10) . caddr el10;
    % car uik becomes the expr. to replace the former uik
    while el9 do <<
      uik:=totdf3(car uik, cdr uik, nth(xlist, car el9),
                  car el9, sb, xlist, ordok, subordinc);
      el9:=cdr el9
    >>;
    uik
  >>     else       % no substitution
  nil
end$

%---------------------

symbolic procedure totdf3(s,depli,x,n,sb,xlist,ordok,subordinc)$
% s is the expression to be differentiated wrt. x which is the nth
%   variable in xlist
% depli is a list of lists, each being the list of jet-variables
%   of order 0,1,2,..., such that s=s(xlist,depli), but
%   as little as possible jet-variables in depli
% xlist, depli are lisp lists, i.e. without 'list
% - totdf3 calculates total derivative of s(xlist,depli) w.r.t. x which
%   is the n'th variable, it returns (df(s,x), newdepli)
% - totdf3 drops jet-variables on which s does not depend
% - totdf3 automatically does substitutions using the list sb which
%   is updated if prolongations of substitutions are calculated,
%   i.e. sb is destructively changed!
% - structure of sb: lisp list of lisp lists:
%   ((to_be_replaced_jet_var_name, to_be_replaced_jet_var_deriv_1,..),
%    subst_expr_in_jet_space_coord, list_of_jet_vars_in_subst_expr)
% - subordinc is a number by how much the order may increase due to
%   substitutions sb.
% - ordok is the lowest order which must be accurate. If ordok>0 and
%   s is of lower order than ordok then from depli only derivatives
%   of order ordok-1-subordinc to ordok-1 are used.
begin
  scalar tdf,el1,el2,el3,el4,el5,newdepli,
         newdy,dy,ddy$ 
  newdepli:=nil;                 % the new dependence list
  newdy:=nil;                    % the new dep.list due to chain rule
  ddy:=nil;                      % ddy .. derivatives of jet-variables
                                 % resulting from diff. of lower order
  %--- Should only terms in the result be acurate that include
  %--- derivatives of order>=ordok?
  if ordok>0 then <<
    tdf:=simp!* 0;
    depli:=copy depli;
    el2:=length depli;
    if el2<(ordok-subordinc) then depli:=nil
                             else    
    for el1:=1:(ordok-1-subordinc) do <<
      dy:=pnth(depli,el1);
      rplaca(dy,nil);
    >>
  >>                                          else tdf:=diffsq(s,x);
  %--- The differentiations wrt. u-derivatives
  for each el1 in depli do       % for each order do
  <<dy:=union(ddy,el1); ddy:=nil;% dy .. occuring jet-var. of this order
    while el1 do
    <<el2:=car el1; el1:=cdr el1;% el2 is one jet-variable of this order
      el3:=diffsq(s,el2);
      if null car el3 then % It is tempting to do dy:=delete(el2,dy) but
      % that can lead to errors because, dy is a list of the derivatives that
      % appear in the total derivative of s, not necessarily in s itself. That
      % means, if s depends on a 2nd and 4th order derivative but not on a 3rd
      % order derivative, then the third order derivative may just have been
      % added through dy:=union(ddy,el1); so the fact that el3 is nil, i.e. s
      % does not depend on the 3rd order derivative should not result in
      % deleting the 3rd order derivative from dy.
                      else <<
        el4:=dif(el2,n);         % el4=df(el2,x)
        %----- Is el4 to be substituted by sb?
        if el5:=subtest(el4,sb,xlist,ordok,subordinc) then <<
          el4:=car el5;
          newdepli:=mergedepli(newdepli,cdr el5)
        >>                      else <<ddy:=el4 . ddy;el4:=simp!* el4>>;
        tdf:=addsq(tdf, multsq(el4, el3))
      >>
    >>;
    newdy:=dy . newdy
  >>;
  if ddy then newdy:=ddy . newdy;

  newdepli:=mergedepli(reversip newdy,newdepli);
  return (tdf . newdepli)
end$ % of totdf3

%---------------------

symbolic procedure joinsublists(a)$
% It is assumed, a is either nil or a list of lists or nils which
% have to be joined
if null a then nil 
          else append(car a,joinsublists(cdr a))$

%---------------------

algebraic procedure transeq(eqn,xlist,ylist,sb)$
<<for each el1 in sb do eqn:=sub(el1,eqn);
  for each el1 in ylist do
  for each el2 in xlist do nodepend el1,el2;
  eqn>>$

%---------------------

symbolic operator  drop$
symbolic procedure drop(a,vl)$
% liefert summe aller terme aus a, die von elementen von vl abhaengen
begin scalar b$
  if not((pairp a) and (car a='plus)) then b:=a
				      else
  <<vl:=cdr vl;             % because vl is an algebraic list
    for each c in cdr a do
    if not freeoflist(c,vl) then b:=cons(c,b)$
    if b then b:=cons('plus,reverse b)>>$
  return b$
end$

%---------------------

symbolic procedure etamn(u,indxlist,xilist,etalist,
                         ordok,truesub,subordinc,xlist)$
% determines etamn recursively
% At the end, ulist= list of df(u,i,cdr indxlist) for all i
begin
  scalar etam,x,h1,h2,h3,h4,h5,ulist,el,r,cplist,depli;

  % Has it already been computed?
%if nil then
  if ordok=0 then <<
   h5:=u$ h2:=indxlist$
   while h2 do <<h5:=mkid(h5,car h2); h2:=cdr h2>>; 
   h3:=assoc(h5,etamn_al)
  >>$
  if h3 then return cdr h3$

  if (null indxlist) or ((length indxlist)=1) then
  <<cplist:=etalist;
    while u neq cadar cplist do cplist:=cdr cplist;
    etam:=(caar cplist . caddar cplist) . nil;
  >>                                          else
  etam:=etamn(u,cdr indxlist,xilist,etalist,ordok,truesub,
              subordinc,xlist)$

  return

  if null indxlist then etam
                   else <<
    ulist:=nil;
    x:=cdr nth(xilist,car indxlist);    % e.g.  x := (v3,3,dylist)
    r:=if null car caar etam then <<depli:=nil;caar etam>>
                             else <<
      h2:=totdf3(caar etam,cdar etam,car x,cadr x,truesub,xlist,
                 ordok,subordinc)$
      depli:=cdr h2;
      car h2
    >>;
    etam:=cdr etam;      % = reverse ulist
    cplist:=xilist;

    h3:=nil;
    while cplist do
    <<el:=car cplist;  % e.g.  el=(xi_bz1 bz1 2 ((u)))
      cplist:=cdr cplist;
      if (length indxlist)=1 then h1:=dif(u,caddr el)
                             else <<
        h1:=dif(car etam,cadr indxlist);  % e.g.  h1:=u!`i!`n
        etam:=cdr etam;
      >>;

      ulist:=h1 . ulist;
      if not sqzerop car el then <<

        %--- substitution of h1?
        if h4:=subtest(h1,truesub,xlist,ordok,subordinc) 
        then <<h1:=car h4;depli:=mergedepli(depli,cdr h4)>>
        else h1:=simp!* h1;
        r:=subtrsq(r,multsq(h1,<<h2:=totdf3(car el,cadddr el,car x,
                                            cadr x,truesub,xlist,0,0)$
                                 if car car h2 then % ie. car h2 neq 0
                                 <<if h4 then depli:=mergedepli(depli,cdr h4)
                                         else h3:=prepsq h1 . h3;
                                   depli:=mergedepli(depli,cdr h2);
                                 >>$
                                 car h2
                               >>
                           )
                  );
      >>
    >>;
    if h3 then <<
      h3:=list h3;
      for h2:=1:(length indxlist) do h3:=nil . h3;
      depli:=mergedepli(depli,h3);
    >>;
    % (if not full then drop(r,'list . car revdylist) else r) .
    % (reverse ulist)
    h1:=(r . depli) . (reverse ulist)$
    if ordok=0 then etamn_al:=cons((h5 . h1),etamn_al);
    h1
  >>
end$ % of etamn

%---------------------

symbolic procedure callcrack(!*time,cpu,gc,lietrace_,symcon,
                             flist,vl,xilist,etalist,inequ,last_call)$
begin
  scalar g,h,oldbatch_mode,print_old;
  if !*time then <<terpri()$
    write "time to formulate conditions: ", time() - cpu,
          " ms    GC time : ", gctime() - gc," ms"$
  >>;
  if lietrace_ then algebraic <<
    write"Symmetry conditions before CRACK: ";
    write lisp ('list . symcon);
  >>;
  oldbatch_mode:=!*batch_mode$
  !*batch_mode:=batch_mode_sub$
  print_old:=print_$  
  if null batch_mode_sub and null print_ then print_:=8$

  % lex_df=nil gives shorter computation but lex_df=t gives system
  % that is easier to integrate, eg ODEs it they are in the diff ideal
  % so computation starts as lex_df=nil and is changed to lex_df=t at
  % end if necessary
  if freeof(proc_list_,'try_other_ordering) then 
  proc_list_:=append(proc_list_,list 'try_other_ordering)$
  h:=sq!*crack({'list . symcon,'list . inequ,'list . flist,'list . vl});

  !*batch_mode:=oldbatch_mode$
  print_:=print_old$

  if last_call then return h;

  if h neq list('list) then
  <<h:=cadr h;
    symcon:=cdadr h$
    for each g in cdaddr h do <<
      xilist :=for each k in  xilist collect cons(subsq(car k,{(cadr g . caddr g)}),cdr k)$ %!!
      etalist:=for each k in etalist collect cons(subsq(car k,{(cadr g . caddr g)}),cdr k)$ %!!
      inequ  :=subst(caddr g, cadr g,  inequ);
%--> Erkennung von 'e, 'x siehe:

%      h:=intern car explode cadr e1;
%write"h=",h;terpri()$
%      if (h='x) or (h='X) then
%      xilist :=subst(caddr e1, cadr e1,  xilist) else
%      if (h='e) or (h='E) or (h="e") or (h="E") then
%      etalist:=subst(caddr e1, cadr e1, etalist) else
%      rederr("One ansatz does not specify XI_ nor ETA_.")
    >>;

    if lietrace_ then <<
      write"symcon nachher: ",symcon;
      write"xilist=", xilist;
      write"etalist=", etalist;
    >>;
    flist:=cdr reval cadddr h;
    if print_ then
    <<terpri()$
      write"Remaining free functions after the last CRACK-run:";
      terpri()$
      fctprint flist;terpri()$terpri()>>;
  >>;

  return list(symcon,xilist,etalist,flist,inequ)
end$ % of callcrack

%---------------------

put('liepde,'psopfn,'liepde_psopfn)$
symbolic procedure liepde_psopfn(inp)$

 comment

 problem:  {{eq1,eq2, ...},   % equations
	    { y1, y2, ...},   % functions
	    { x1, x2, ...} }  % variables

           % Equations `eqi' can be given as single differential
           % expressions which have to vanish or they can be given
           % in the form df(..,..[,..]) = ..   .

           % If the equations are given as single differential
           % expressions then the program will try to bring it into
           % the `solved form' ..=.. automatically.

           % The solved forms (either from input or generated within 
           % LIEPDE) will be used for substitutions, to find 
           % all symmetries satisfied by solutions of the equations.
           % Sufficient conditions for this procedure to be correct, 
           % i.e. to get *all* symmetries of the specified type on the
           % solution space are:

           % - There are equally many equations and functions.
           % - Each function is used once for a substitution and
           %   each equation is used once for a substitution.
           % - All functions differentiated on the left hand sides 
           %   (lhs) depend on all variables.
           % - In no equation df(..,..[,..]) = .. does the right hand 
           %   side contain the derivative on the lhs nor any 
           %   derivative of it.
           % - No equation does contain a lhs or the derivative
           %   of a lhs of another equation.
           
           % These conditions are checked in LIEPDE and execution
           % is stoped if they are not satisfied, i.e. if the input
           % was not correct, or if the program was not able to
           % write the input expressions properly the solved 
           % form ..=..  . One then should find for each function
           % one derivative which occurs linearly in one equation.
           % The chosen derivatives should be as high as possible, 
           % at least there must no derivative of them occur in any 
           % equation. An easy way to get the equations in the
           % desired form is to use 
           % FIRST SOLVE({eq1,eq2,...},{list of derivatives})

           % NOTE that to improve efficiency it is advisable not to
           % express lower order derivatives on the left hand side
           % through higher order derivatives on the right hand side.
           % SEE also the implications on completeness for the
           % determination of generalized symmetries with
           % characteristic functions of a given order, as described
           % below and the two examples with the Burgers equation.

 symtype:  {"point"}          % for point   symmetries
           {"contact"}        % for contact symmetries, is only
                              % applicable if only one function,
                              % only one equation of order>1
           {"general",order}  % for generalized symmetries of
                              % order `order' which is an integer>0
                              % NOTE: Characteristic functions of
                              % generalized symmetries (i.e. the
                              % eta_.. if xi_..=0) are equivalent
                              % if they are equal on the solution
                              % manifold. Therefore all dependencies
                              % of characteristic functions on
                              % the substituted derivatives and their
                              % derivatives are dropped. This has the
                              % consequence that if, e.g. for the heat
                              % equation df(u,t)=df(u,x,2), df(u,t) is
                              % substituted by df(u,x,2) then
                              % {"general",2) would not include
                              % characteristic functions depending
                              % on df(u,t,x), or df(u,x,3). THEREFORE:
                              % If you want to find all symmetries up
                              % to a given order then 
                              % - either avoid substituting lower 
                              %   order derivatives by expressions
                              %   involving higher derivatives, or, 
                              % - go up in the order specified in 
                              %   symtype.
                              % 
                              % Example:
                              %
                              % depend u,t,x
                              % liepde({{df(u,t)=df(u,x,2)+df(u,x)**2},
                              %         {u},{t,x}},
                              %        {"general",3},{})
                              %
                              % will give 10 symmetries + one infinite
                              % family of symmetries whereas
                              %
                              % liepde({{df(u,x,2)=df(u,t)-df(u,x)**2},
                              %         {u},{t,x}},
                              %        {"general",3},{})
                              %
                              % will give 28 symmetries + one infinite
                              % family of symmetries.

           {xi!_x1 =...,
               ...
            eta!_y3=... }     % - An ansatz must specify all xi!_.. for
                              %   all indep. variables and all eta!_..
                              %   for all dep. variables in terms of
                              %   differential expressions which may
                              %   involve unknown functions/constants.
                              %   The dependencies of the unknown
                              %   functions have to declared earlier
                              %   using the DEPEND command.
                              % - If the ansatz should consist of the
                              %   characteristic functions then set
                              %   all xi!_..=0 and assign the charac-
                              %   teristic functions to the eta!_.. .

 flist:    {- all parameters and functions in the equations which are to
              be determined, such that there exist symmetries,
            - if an ansatz has been made in symtype then flist contains
              all unknown functions and constants in xi!_.. and eta!_..}

 inequ:    {all non-vanishing expressions which represent
            inequalities for the functions in flist}

 Further comments:

 The syntax of input is the usual REDUCE syntax. For example, the
 derivative of y3 wrt x1 once and x2 twice would be df(y3,x1,x2,2).
 --> One exception: If in the equations or in the ansatz the dependence
 of a free function F on a derivative, like df(y3,x1,x2,2) shall be
 declared then the declaration has to have the form:
 DEPEND F, Y3!`1!`2!`2
 - the ! has to preceede each special character, like `,
 - `i stands for the derivative with respect to the i'th variable in
   the list of variables (the third list in the problem above)

 If the flag individual_ is t then conditions are investigated for
 each equation of a system of equations at first individually before
 conditions resulting from other equations are added.

 If the flag prelim_ is t then preliminary conditions for equations
 of higher than 1st order are formulated and investigated before the
 full condition is formulated and investigated by CRACK.

 If the REDUCE switch TIME is set on with ON TIME then times for the
 individual steps in the calculation are shown.

 Further switches and parameters which can be changed to affect the
 output and performance of CRACK in solving the symmetry conditions
 are listed in the file CRINIT.RED.
;

begin
  scalar cpu, gc, lietrace_, oldadj, eqlist, ylist, xlist, pointp,
         contactp, generalp, ansatzp, symord, e1, e2, ordr, sb,
         dylist, revdylist, xi, eta, eqordr, eqordrcop, no, eqcopy1,
         truesub, deplist, xilist, etalist, dycopy, freelist, eqlen, 
         dylen, truesubno, minordr, n1, n2, n3, n4, n5, n, h, jetord, 
         allsub, subdy, lhslist, symcon, subordinc, eqn, depli, vl, occli, 
         revdycopy, subordinclist, xicop, etacop, flcop, etapqlist, 
         etapqcop, etapq, oldbatch_mode, allsym, symcon_s, xilist_s, 
         etalist_s, inequ_s, flist_s, truesub_s, oldcollect_sol, 
         oldprint_, flist_slin, flist_snli, return_list, last_call, 
         paralist, proc_list_bak, max_gc_fac_bak, flistorg,problem,
         symtype,flist,inequ$

  % lietrace_:=t;
  backup_reduce_flags()$
  cpu:=time()$ gc:=gctime()$
  oldadj:=adjust_fnc; adjust_fnc:=nil;
  oldcollect_sol:=collect_sol; collect_sol:=t;

  %--------- extracting input data
  problem:=aeval car inp$
  symtype:=reval cadr inp$
  flist  :=reval caddr inp$
  inequ  :=reval cadddr inp$
  eqlist:= 
  if atom cadr problem       then list cadr problem else
  if car  cadr problem='list then  cdr cadr problem else
                                  list cadr problem$
  ylist := reval maklist caddr  problem;
  xlist := reval maklist cadddr problem;

  if inequ then inequ:=cdr inequ;
  if flist then flist:=cdr flist;

  % Is this a non-linear problem?
  e1:=flist;
  while e1 and freeof(eqlist,car e1) do e1:=cdr e1;
  lin_problem:=if e1 then nil else t$

  eqlen:=length eqlist;

  %  if 1+eqlen neq length(ylist) then rederr(                          <--- taken out
  %  "Number of equations does not match number of unknown functions."); <--- taken out

  for each e1 in cdr ylist do
  for each e2 in cdr xlist do
  if my_freeof(e1,e2) then rederr(
  "Not all functions do depend on all variables.");

  if atom cadr symtype then                % default case
  if cadr symtype = "point"   then <<pointp  :=t;symord:=0>> else
  if cadr symtype = "contact" then <<contactp:=t;symord:=1;
 
  %  if eqlen>1 then rederr(                                        <--- taken out
  %  "Contact symmetries only in case of one equation for one function.") <--- taken out
  >>                          else
  if cadr symtype = "general" then <<generalp:=t;symord:=caddr symtype;
    if (not fixp symord) or (symord<1) then rederr(
    "The order of the generalized symmetry must be an integer > 0.")
  >>                          else rederr("Inconclusive symmetry type.")
                       else <<
    ansatzp:=t;    % an ansatz has been made
  % if length(ylist)+length(xlist) neq length(symtype)+1 then  <--- taken out
  % rederr("Number of assignments in the ansatz is wrong.");   <--- taken out

    % find the order of the ansatz
    symord:=0;
    % at first the max order of derivatives of elements of ylist
    for each e1 in cdr symtype do
    for each e2 in cdr ylist do
    <<n:=totdeg(caddr e1,e2);
      if n>symord then symord:=n>>;
    % then the max order of jet variables occuring in functions to be computed
    for each e1 in flist do <<
     e2:=fctargs e1$
     for each h in e2 do <<n2:=-1+length combidif h;if n2>symord then symord:=n2>>$
    >>$
    if  symord = 0                        then pointp  :=t else
    if (symord = 1) and (length(ylist)=2) then contactp:=t else
                                               generalp:=t;
    sb:=nil;
    for each e1 in flist do if freeof(eqlist,e1) then sb:=cons({'equal,e1,0},sb)$
    sb:=cons('list,sb);
    h:=nil;
    for each e1 in cdr symtype do <<
      n1:=algebraic(sub(lisp sb,lisp caddr e1))$ % substitution on the rhs of the sym.ansatz
      if not zerop n1 and 
         (not pairp n1 or
          (pairp n1 and ((car n1 neq 'equal) or (not zerop caddr n1)))) then <<
        h:=0;
        write"Your ansatz for the symmetry needs to be homogeneous, i.e. ",
             "substituting all unknown functions and constants to be computed ",
             "(which do not occur in the equation) to zero needs to make the ",
             "symmetry to zero. In your ansatz this is not ",
             "the case because the list of substitutions:"$
        algebraic(write lisp sb)$
        write"leaves this right hand side non-zero:"$
        algebraic(write lisp {'equal,cadr e1,n1})$
        write"To fix your ansatz you could, for example, simply multiply all ",
             "non-vanishing parts on all right hand sides in your ansatz with one ",
             "and the same unknown constant, say cc, and add cc to the list of unknowns ",
             "to be computed and to the list of non-vanishing expressions."
      >>
    >>
  >>$
  if h then return nil$
 
  problem:=0;

  %---- Are substitutions already given in the input?
  eqcopy1:=eqlist;
  while eqcopy1 and (pairp car eqcopy1) and (caar eqcopy1='equal) and
        (pairp cadar eqcopy1) and (caadar eqcopy1='df) do
  eqcopy1:=cdr eqcopy1;
  if null eqcopy1 then truesub:=eqlist;
  eqcopy1:=nil;

  %--------- initial printout
  if print_ and logoprint_ then <<terpri()$
    write "-----------------------------------------------",
    "---------------------------"$ terpri()$terpri()$
    write"This is LIEPDE - a program for calculating infinitesimal",
         " symmetries"; terpri()$
    write "of single differential equations or systems of de's";
  >>;
  terpri();terpri();
  if length xlist=2 then write"The ODE"
                    else write"The PDE";
  if length ylist>2 then write"-system";
  write " under investigation is :";terpri();
  for each e1 in eqlist do algebraic write lisp e1;
  terpri()$write "for the function(s) : ";terpri()$
  terpri()$fctprint cdr reval ylist;
  terpri()$terpri();
  eqlist:=for each e1 in eqlist collect algebraic equ_to_expr(lisp e1);
  if eqlen > 1 then eqlist:=desort eqlist;

  if !*time then <<terpri()$
    terpri()$terpri()$
    write"=============== Initializations" ;
  >>;  

  ordr:=0;
  for each e1 in eqlist do <<
    h:=0;
    for each e2 in cdr ylist do
    <<n:=totdeg(e1,e2);
      if n>h then h:=n>>;
    eqordr:=h . eqordr;
    if h>ordr then ordr:=h
  >>;
  eqordr:=reversip eqordr;

  if ordr>symord then jetord:=ordr
                 else jetord:=symord$
  sb:=subdif1(xlist,ylist,jetord)$
  eqlist:=cons('list,eqlist);
  if ansatzp then eqlist:=list('list,symtype,eqlist);
  if truesub then eqlist:=list('list,cons('list,truesub),eqlist);
  if inequ   then eqlist:=list('list,cons('list,inequ),eqlist);

  on evallhseqp;
  eqlist:=transeq(eqlist,xlist,ylist,sb); %<<<<<<----- slow
  off evallhseqp;

  if inequ   then <<inequ  :=cdadr eqlist;eqlist:=caddr eqlist>>;
  if truesub then <<truesub:=cdadr eqlist;eqlist:=caddr eqlist>>;
  if ansatzp then <<symtype:=cdadr eqlist;eqlist:=cdaddr eqlist>>
             else eqlist:=cdr eqlist;

  ylist:=cdr ylist;
  xlist:=cdr xlist;

  if lietrace_ and ansatzp then write"ansatz=",symtype;

  dylist:=ylist . reverse for each e1 in cdr sb collect
                          for each e2 in cdr e1 collect caddr e2;
  revdylist:=reverse dylist;  % dylist with decreasing order

  vl:=xlist;
  for each e1 in dylist do vl:=append(e1,vl);
  vl:='list . vl;

  if not ansatzp then
  deplist:=for n:=0:symord collect nth(dylist,n+1);
    % list of variables the xi_, eta_ depend on

  xi :=reval algebraic xi!_;
  eta:=reval algebraic eta!_;
  n:=0;
  xilist :=for each e1 in xlist collect
  <<n:=n+1;
    if pointp or ansatzp then <<
      h:=mkid('xi_,e1); %!!
      if not ansatzp then <<
        nodependlist {h};
        depnd(h,xlist . deplist);
        flist:=h . flist;
        flin_:=h . flin_;
        depli:=deplist;
      >>             else depli:=nil
    >>                   else <<h:=0;depli:=nil>>;
    {simp h,e1,n,depli}
  >>;
  depli:=if (not ansatzp) and (not generalp) then deplist
                                             else nil;
  n:=0;
  etalist:=for each e1 in ylist collect
  <<n:=n+1;
    h:=mkid('eta_,e1); %!!
    if not ansatzp then <<
      if not generalp then <<nodependlist {h};depnd(h,xlist . deplist)>>;
      % the generalp-case is done below when substitutions are known
      flist:=h . flist;
      flin_:=h . flin_;
    >>;
    {simp h,e1,depli}
  >>;
  flistorg:=flist;

  if ansatzp then <<
    for each e1 in symtype do <<
      xilist :=for each k in  xilist collect cons(subsq(car k,{(cadr e1 . caddr e1)}),cdr k)$ %!!
      etalist:=for each k in etalist collect cons(subsq(car k,{(cadr e1 . caddr e1)}),cdr k)$ %!!
      %--> Erkennung von 'e, 'x siehe:
      %      h:=intern car explode cadr e1;
      %write"h=",h;terpri()$
      %      if (h='x) or (h='X) then
      %      xilist :=subst(caddr e1, cadr e1,  xilist) else
      %      if (h='e) or (h='E) or (h="e") or (h="E") then
      %      etalist:=subst(caddr e1, cadr e1, etalist) else
      %      rederr("One ansatz does not specify XI_ nor ETA_.")
    >>;
    add_xi_eta_depli(xilist,etalist,revdylist)$
  >>;

  if lietrace_ then write"xilist=",xilist,"  etalist=",etalist;
  %---- Determining a substitution list for highest derivatives
  %---- from eqlist. Substitutions may not be optimal if starting
  %---- system is not in standard form

  comment: Counting in how many equations each highest
  derivative occurs. Those which do not occur allow Stephani-Trick,
  those which do occur once and there linearly are substituted by that
  equation.

  Because one derivative shall be assigned it must be one of
  the highest derivatives from each equation used, or one such that
  no other derivative in the equation is a derivative of it.

  Each equation must be used only once.

  Each derivative must be substituted by only one equation.

  At first determining the number of occurences of each highest
  derivative.

  The possiblity of substitutions is checked in each total derivative.

  $

  if truesub then <<       %--- determination of freelist %and occurlist
    dycopy:=car revdylist; %--- the highest derivatives
    while dycopy do
    <<e1:=car dycopy; dycopy:=cdr dycopy;
      eqcopy1:=eqlist;
      while eqcopy1 and my_freeof(car eqcopy1,e1) do
      eqcopy1:=cdr eqcopy1;

      if null eqcopy1 then freelist :=e1 . freelist
                      %else occurlist:=e1 . occurlist;
    >>
  >>         else <<

    no:=0;               % counter of the following repeat-loop
                         % freelist (and occurlist) are determined
                         % only in the first run
    eqordrcop:=copy eqordr;
                         % for bookkeeping which equation have been used

    repeat <<
      no:=no+1;        %--- incrementing the loop counter

      %--- truesubno is the number of substitutions so far found.
      %--- It is necessary at the end to check whether new substitutions
      %--- have been found.
      if null truesub then truesubno:=0
                      else truesubno:=length truesub;
      %--- substitutions of equations of minimal order are searched first
      minordr:=1000;   %--- minimal order of the so far unused equations
      for each e1 in eqordrcop do
      if (e1 neq 0) and (e1<minordr) then minordr:=e1;

      dycopy:=copy nth(dylist,minordr+1); %-- all deriv. of order minordr
      dylen:=length dycopy;

      allsub:=nil;

      for n1:=1:dylen do    %--- checking all deriv. of order minordr
      <<e1:=nth(dycopy,n1); %--- e1 is the current candidate
        %--- here test, whether e1 is not a derivative of a lhs of one
        %--- of the substitutions car e2 found so far
        h:=combidif(e1); n:=car h; h:=cdr h;
        e2:=truesub;
        while e2 and (null comparedif3(cadar e2,n,h)) do e2:=cdr e2;
        if null e2 then <<

          n2:=0; %-- number of equations in which the derivative e1 occurs
          subdy:=nil;
          for n3:=1:eqlen do
          if not my_freeof(nth(eqlist,n3),e1) then
          % here should also be tested whether derivatives of e1 occur
          % and not just my_freeof
          %-->
          <<n2:=n2+1;
            if nth(eqordrcop,n3)=minordr then
            %--- equation is not used yet and of the right order
            <<e2:=cdr algebraic coeff(lisp nth(eqlist,n3),lisp e1);
              if hipow!*=1 then
              subdy:=list(n1,n3,list('equal,e1,list('minus,
                          list('quotient, car e2, cadr e2)))) . subdy
            >>
          >>;
          if n2=0 then if no=1 then freelist:=e1 . freelist else
                  else
          <<%if no=1 then occurlist:=e1 . occurlist;
            if subdy then if n2=1 then
            <<h:=car subdy;
              truesub:=(caddr h) . truesub;
              n:=pnth(dycopy   ,car  h);rplaca(n,0);
              n:=pnth(eqordrcop,cadr h);rplaca(n,0);
            >>                    else
            allsub:=nconc(allsub,subdy);
          >>
        >>
      >>;

      %---- Taking the remaining known substitutions of highest deriv.
      h:=subdy:=0;
      for each h in allsub do
      if (nth(dycopy   , car h) neq 0) and
         (nth(eqordrcop,cadr h) neq 0) then
      <<truesub:=(caddr h) . truesub;
        n:=pnth(dycopy   ,car  h);rplaca(n,0);
        n:=pnth(eqordrcop,cadr h);rplaca(n,0);
      >>;
    >> until (truesub and (length(truesub)=eqlen)) % complete
             or (truesubno=length(truesub))$       % no progress
    allsub:=eqordrcop:=dycopy:=nil;

    if (null truesub) or
       (eqlen neq length(truesub)) then rederr(
  "Unable to find all substitutions. Input equations as df(..,..)=..!");
  >>;

  lhslist:=for each e1 in truesub collect cadr e1;

  %------ check that functions to be computed do not depend on
  %       lhs of the system
  chkflist(cons('list,flist),cons('list,lhslist))$

  %-- Bringing truesub into a specific form: lisp list of lisp lists:
  %   ((to_be_replaced_jet_var_name, to_be_replaced_jet_var_deriv_1,..),
  %    subst_expr_in_jet_space_coord, list_of_jet_vars_in_subst_expr)
  truesub:=for each e1 in truesub collect
  cons(combidif cadr e1, adddepli(caddr e1,revdylist))$

  %--- Checking that no rhs of a substitution contains any lhs or
  %--- derivative of a lhs
  h:=t;  %--- h=nil if lhs's are derivatives of each other
  no:=t; %--- no=nil if one lhs can be substituted in a rhs
  for each e1 in truesub do
  if h and no then <<
    n1:=caar e1; n2:=cdar e1; dylen:=length n2;
    for each e2 in truesub do <<
      %--- comparison of two lhs's
      if not(e1 eq e2) and (n1=caar e2) and
      comparedif1(n2,cdar e2) then h:=nil;   %--- truesub is not ok
      %--- can the lhs of e1 be substituted on the rhs?
      dycopy:=caddr e2;
      for n:=1:dylen do if dycopy then dycopy:=cdr dycopy;
      for each e3 in dycopy do
      for each e4 in e3 do
      if comparedif2(n1,n2,e4) then no:=nil;
    >>
  >>;
  if null h  then rederr(
  "One substitution can be made in the lhs of another substitution!");
  if null no then rederr(
  "One substitution can be made in the rhs of another substitution!");

  %????????????????????????????????????????????
  %  %--- Checking that a derivative of each dependent variable is
  %  %--- substituted once. This is a sufficient condition for having
  %  %--- a de-system that is a differential Groebner basis
  %  h:=nil;
  %  for each e1 in lhslist do h:=adjoin(car combidif e1,h);
  %  if length(h) neq length(lhslist) then rederr(
  %  "For at least one function there is more that one substituion!")$

  %--- Determine of how much the order may increase by a substitution
  subordinc:=0;
  subordinclist:=for each h in truesub collect <<
    n:=(length caddr h) - (length car h);
    if n>subordinc then subordinc:=n;
    n
  >>;
  if lietrace_ then <<terpri()$write"truesub=",truesub;
                      terpri()$write"freelist=",freelist;
                      %terpri()$write"occurlist=",occurlist
                    >>;
  %--- To avoid non-uniqueness in the case of the investigation of
  %--- generalized symmetries let the characteristics eta_.. (xi_..=0)
  %--- not depend on substituted derivatives
  if generalp and (null ansatzp) then <<
    deplist:=ylist .
             for each dycopy in cdr deplist collect <<
               for each h in lhslist do
               %---- delete h and derivatives of h
               dycopy:=listdifdif1(h,dycopy);
               dycopy
             >>;
    for e1:=1:(length etalist) do <<
      h:=nth(etalist,e1);
      e2:=prepsq car h$
      nodependlist {e2};
      depnd(e2,xlist . deplist);
      h:=pnth(h,3);
      rplaca(h,deplist)
    >>
  >>;
  % reduced set of solution techniques for preliminary conditions
  proc_list_:=delete('multintfac,proc_list_)$
  if !*time then <<terpri()$
    write "time for initializations: ", time() - cpu,
          " ms    GC time : ", gctime() - gc," ms"$
    cpu:=time()$ gc:=gctime()$
  >>;
  %------ Determining first short determining equations and solving them
  if prelim_ or individual_ then <<
   proc_list_bak:=proc_list_$
   proc_list_:='(to_do
                 separation
                 subst_level_0
                 subst_level_03
                 quick_integration
                 subst_level_33
                 gen_separation
   %              full_integration
                )$
   max_gc_fac_bak:=max_gc_fac$
   max_gc_fac:=0;
   inverse_trafo_list_incomplete:=nil  
  >>$
  symcon:=nil;
  n1:=0;
  if prelim_ and lin_problem then
  for each eqn in eqlist do
  <<n1:=n1+1;
    if !*time then <<terpri()$
      terpri()$terpri()$
      write"=============== Preconditions for the ",n1,". equation" ;
    >>;
    revdycopy:=revdylist;
    for e1:=(nth(eqordr,n1) + 1):ordr do revdycopy:=cdr revdycopy;
    n2:=cadr adddepli(eqn,revdycopy); % jet-variables in eqn
    vl:=n2;
    occli:=lastcar n2;
    freelist:=setdiff(car revdycopy,occli);
    if pointp and (subordinc=0) then
    eqn:=drop(eqn,occli) % dropp all terms without a highest deriv.
                                else occli:=joinsublists n2$
    % freelist must not contain substituted variables
    freelist:=setdiff(freelist,lhslist);
    % It must be possible to separate wrt freelist variables
    for each n4 in freelist do
    if not freeof(depl!*,n4) then freelist:=delete(n4,freelist);
    if freelist then <<
      n:=nth(eqordr,n1);   % order of this equation
      h:=simp 0;
      for each e1 in xilist do
      if (cadddr e1) and ((length cadddr e1) > n) then
      % xi (=car e1) is of order n
      h:=addsq(h,
               if sqzerop car e1 then simp 0
                                 else <<n3:=mergedepli(n3,cadddr e1);
                                        multsq(car e1,simpdf {eqn,cadr e1})
                                      >>
              );
      for each e2 in occli do
      h:=addsq(h,
               multsq(<<n5:=combidif(e2);     
                        n4:=car etamn(car n5,cdr n5,xilist,etalist,
                                      nth(eqordr,n1),truesub,subordinc,xlist);
                        vl:=mergedepli(vl,cdr n4);
                        car n4
                      >>,
                      simpdf {eqn,e2}
                     )
              );
      vl:=joinsublists(xlist . vl)$

      if n1>1 then
      for each e1 in reverse flistorg do
      if not freeof(symcon,e1) then flist:=union({e1},flist);

      for each e2 in freelist do
      <<e1:=((car diffsq(h,e2)) . 1);
        for n2:=1:eqlen do
        <<n4:=nth(lhslist,n2);
          if not my_freeof(eqn,n4) then
          e1:=((car subsq(e1,{(n4 . cadr nth(truesub,n2))})) . 1);
          vl:=delete(n4,vl)
        >>;

        % splitting
        if car e1 and (car e1 neq 0) then << % ie. e1<>0

          e1:=cdr split_simplify({{'list, mk!*sq e1},
                                   'list . nil,
                                   'list . flist,
                                   'list . vl, nil
                                 })$
          symcon:=nconc(e1,symcon)
        >>
      >>;
      if symcon and (individual_ or (n1=eqlen)) then <<
        h:=callcrack(!*time,cpu,gc,lietrace_,symcon,
                         flist,vl,xilist,etalist,inequ,nil);
        symcon :=car   h; xilist:=cadr   h;
        etalist:=caddr h; flist :=cadddr h;
        inequ  :=cadddr cdr h; h:=nil$
        cpu:=time()$ gc:=gctime()$
      >>
    >>
  >>;

  %------------ Determining the full symmetry conditions
  n1:=0;
  vl:=nil;
  for each eqn in eqlist do
  <<n1:=n1+1;
    if !*time then <<terpri()$
      terpri()$terpri()$
      write"=============== Full conditions for the ",n1,". equation" ;
    >>;
    n2:=cadr adddepli(eqn,revdylist);
    n3:=n2;  % n3 are the variables in the new condition

    h:=simp 0;
    for each e1 in xilist do
    h:=addsq(h,if sqzerop car e1 then simp 0
                                 else <<n3:=mergedepli(n3,cadddr e1);
                                        multsq(car e1,simpdf {eqn,cadr e1})
                                      >>);
    for each e1 in n2 do
    for each e2 in e1 do
    h:=addsq(h,multsq(<<  %<<<<<<----- slow?
                        n5:=combidif(e2);      
                        n4:=car etamn(car n5,cdr n5,xilist,etalist,0,
                                      truesub,0,xlist);
                        n3:=mergedepli(n3,cdr n4);      
                        car n4
                      >>,
                      simpdf {eqn,e2}   %<<<<<<----- slow
                     )
            );
    h:=(car h . 1);  % ie. take numerator

    n3:=joinsublists(xlist . n3)$
    for n2:=1:eqlen do
    <<n4:=nth(lhslist,n2);
      if not my_freeof(eqn,n4) then
      h:=car subsq(h,{(n4 . cadr nth(truesub,n2))}) . 1;   % take num
      n3:=delete(n4,n3)
    >>;
    vl:=union(vl,n3);

    if prelim_ or (n1>1) then
    for each e1 in reverse flistorg do
    if not freeof(symcon,e1) then flist:=union({e1},flist);

    % splitting
    if car h and (car h neq 0) then <<
      h:=cdr split_simplify({{'list,mk!*sq h},
                              'list . nil,
                              'list . flist,
                              'list . vl, nil
                             })$
      symcon:=nconc(h,symcon)
    >>$

    last_call:=if n1=eqlen then t else nil$
    if (individual_ and lin_problem) or last_call then <<
      if last_call then <<
       etamn_al:=nil$
       if prelim_ or individual_ then <<
        proc_list_:=proc_list_bak$
        max_gc_fac:=max_gc_fac_bak
       >>
      >>$
      allsym:=callcrack(!*time,cpu,gc,lietrace_,symcon,
                        flist,vl,xilist,etalist,inequ,last_call);
      cpu:=time()$ gc:=gctime()$
      if last_call then flist:=flistorg
                   else <<
        symcon :=car        allsym; xilist:=cadr   allsym;
        etalist:=caddr      allsym; flist :=cadddr allsym;  
        inequ  :=cadddr cdr allsym; allsym:=nil$
      >>
    >>
  >>;

  eqn:=sb:=e1:=e2:=n:=h:=dylist:=deplist:=symord:=nil;%occurlist:=nil;
  lisp 
  if done_trafo and cdr done_trafo then <<
   terpri()$
   if cddr done_trafo                                               then 
   write"The following transformations reverse the transformations" else
   write"The following transformation reverses the transformation"$
   terpri()$
   write"performed in the computation:"$
   algebraic write lisp done_trafo$
   if inverse_trafo_list_incomplete then
   write"***** The list 'done_trafo' of inverse transformations"$terpri()$
   write"      is not complete as at least one transformation"$terpri()$
   write"      could not be inverted"$terpri()
  >>$

  n1:=0;
  %  allsym is a list of solutions of crack
  if allsym and car allsym='list then allsym:=cdr allsym;

  % Sort the symmetries from most general to most special by
  % picking the most special first
  h:=for each e1 in allsym collect
     cons((length cdadr e1)+(length cdaddr e1),e1);
  h:=idx_sort h;
  allsym:=for each e1 in h collect cdr e1;
  while allsym do <<

    nodependlist ylist;
    symcon_s:=cdadar allsym;

    xilist_s :=xilist;
    etalist_s:=etalist;
    inequ_s  :=inequ;
    truesub_s:=truesub;
    paralist :=nil;
    for each g in cdaddr car allsym do 
    if not freeof(eqlist,cadr g) then <<
      truesub_s :=subst(caddr g, cadr g, truesub_s);
      paralist:=g . paralist
    >>                           else <<
      xilist_s :=for each k in  xilist_s collect cons(subsq(car k,{(cadr g . caddr g)}),cdr k)$ %!!
      etalist_s:=for each k in etalist_s collect cons(subsq(car k,{(cadr g . caddr g)}),cdr k)$ %!!
      inequ_s  :=subst(caddr g, cadr g,   inequ_s);
    >>;

    if lietrace_ then <<
      write"final symcon : ", symcon_s;  terpri()$
      write"final xilist = ", xilist_s;  terpri()$
      write"final etalist= ", etalist_s; terpri()$
    >>;
    flist_s:=cdr reval cadddr car allsym;
    allsym:=cdr allsym$
    oldprint_:=print_; print_:=nil; 
    if print_ then <<terpri()$
      write"Remaining free functions after the last CRACK-run:";
      terpri()$
      fctprint flist_s;terpri()$terpri()
    >>;

    %------- Calculation finished, simplification of the result
    h:=append(for each el in  xilist_s collect mk!*sq car el,    %!!
              for each el in etalist_s collect mk!*sq car el );  %!!
    if symcon_s then for each el in symcon_s do h:=cons(el,h);
    h:=cons('list,h); 

    %------- droping redundant constants or functions
    flist_slin:=nil;  % flist_slin are the new lin. constants and functions
    flist_snli:=nil;  % flist_snli are the non-lin. parameters in equations

    for each e1 in flist_s do 
    if freeof(paralist,e1) then flist_slin:=e1 . flist_slin
                           else flist_snli:=e1 . flist_snli;

    oldbatch_mode:=!*batch_mode$ !*batch_mode:=nil$
    if print_ then <<
      write"***** START OF A COMPUTATION TO DROP REDUNDANT *****"$terpri()$
      write"*****  CONSTANTS AND FUNCTIONS OF INTEGRATION  *****"$terpri()$
    >>$
    sb:=reval dropredundant(h,'list . flist_slin,'list . vl,list('list));
    if print_ then <<
      write"***** THE COMPUTATION TO DROP REDUNDANT CONSTANTS *****"$terpri()$
      write"*****    AND FUNCTIONS OF INTEGRATION FINISHED    *****"$terpri()$
    >>$
    !*batch_mode:=oldbatch_mode$

    if sb then <<
      flist_slin:=cdr cadddr sb;
      h:=caddr sb;
      sb:=cadr sb;
      e1:=nil
    >>;

    %------- absorbing numerical constants into free constants
    if (not freeoflist( xilist_s,flist)) or 
       (not freeoflist(etalist_s,flist)) then h:=nil else
    h:=reval absorbconst(h,'list . flist_slin);
    if h then if sb then sb:=append(sb,cdr h)
                    else sb:='list . cdr h;

    %------- doing the substitutions to drop and absorb 
    if sb then <<
      if print_ then <<terpri()$
        write"Free constants and/or functions have been rescaled. ">>$
      for each e1 in cdr sb do <<
        xilist_s :=for each k in  xilist_s collect cons(subsq(car k,{(reval cadr e1 . caddr e1)}),cdr k)$ %!!
        etalist_s:=for each k in etalist_s collect cons(subsq(car k,{(reval cadr e1 . caddr e1)}),cdr k)$ %!!
        symcon_s :=cdr reval cons('list,subst(caddr e1,reval cadr e1,symcon_s));
      >>;
    >>;

    symcon_s := for each e1 in symcon_s collect 
		car simplifypdeSQ(simp e1,append(flist_slin,flist_snli),t,nil,nil)$
    print_:=oldprint_;

    %------- Computing the prolongation of the symmetry vector
    etapqlist:=nil$
    if fixp(prolong_order) and (prolong_order>0) then <<
      % We can not do "for each e1 in ylist do depnd(e1,list(xlist));"
      % because otherwise the formulas generated by etamn are wrong
      %    on evallhseqp; % left hand sides not needed
      sb:=subdif1(cons('list,xlist),cons('list,ylist),prolong_order)$
      % sb is a list of substitutions, like df(y,x) = y`1
      % but with lhs=0 because y is x-independent

      for each e1 in cdr sb do
      for each e2 in cdr e1 do <<
	h:=combidif(caddr e2);
	n4:=mkid('eta_,car h);
	for each n2 in cdr h do
	n4:=mkid(n4,nth(xlist,n2));
	h:=car etamn(car h,cdr h,xilist_s,etalist_s,0,truesub_s,0,xlist)$
	n3:=(length cdr h) - 1;
	if n3>jetord then jetord:=n3$
	etapqlist:=cons(list('equal,n4,mk!*sq car h),etapqlist);
      >>
    >>$
    revdylist:=nil;

    %------- output
    if length flist_slin>1 then n:=t
			   else n:=nil;
    xilist_s:=for each el in  xilist_s collect
    <<e1:=mkid( 'xi_,cadr el);
      e1:=list('equal,e1,prepsq car el); %!!
      e1>>;
    etalist_s:=for each el in etalist_s collect
    <<e1:=mkid('eta_,cadr el);
      e1:=list('equal,e1,prepsq car el); %!!
      e1>>;
    %--- Backsubstitution of e.g. u`1`1 --> df(u,x,2) 
    for each e1 in ylist do depnd(e1,list(xlist));
    on evallhseqp;
    sb:=subdif1(cons('list,xlist),cons('list,ylist),jetord)$
    algebraic(
    sb:=for each e1 in sb join
        for each e2 in e1 collect(rhs e2 = lhs e2));
    off evallhseqp;
    xilist_s :=cdr algebraic(sub(sb,cons('list, xilist_s)));
    etalist_s:=cdr algebraic(sub(sb,cons('list,etalist_s)));
    etapqlist:=cdr algebraic(sub(sb,cons('list,etapqlist)));
    xicop   := xilist_s$
    etacop  :=etalist_s$
    etapqcop:=etapqlist$

    sb:=nil$
    flcop:=flist_slin;
    % Drop constants/functions of integration which may have come up
    % when integrating parametric functions in the equation:
    for each e1 in flist_slin do
    if not freeof(eqlist,e1) then flcop:=delete(e1,flcop);
    for each e1 in flcop do 
    <<% if null n2 then n2:=freeof(xicop,e1) and freeof(etacop,e1)$ 
      if freeof(symcon_s,e1) then <<
        n1:=n1+1;
        xi:=xicop;eta:=etacop;etapq:=etapqcop;
        for each e2 in flcop do 
        if e2 neq e1 then 
        <<xi:=subst(0,e2,xi);eta:=subst(0,e2,eta);etapq:=subst(0,e2,etapq)>>
                     else 
        if null cdr fargs e1 then
        <<xi:=subst(1,e2,xi);eta:=subst(1,e2,eta);etapq:=subst(1,e2,etapq)>>;
        terpri()$write"-------- ",n1,". Symmetry:";terpri()$
        for each e2 in paralist do algebraic write lisp {'equal,cadr e2,reval caddr e2};
        for each e2 in xi       do algebraic write lisp {'equal,cadr e2,reval caddr e2};
        for each e2 in eta      do algebraic write lisp {'equal,cadr e2,reval caddr e2};
        for each e2 in etapq    do algebraic write lisp {'equal,cadr e2,reval caddr e2};
        if cdr fargs e1 then <<terpri()$write"with ";fctprint list(e1);
                               terpri()>>$
        xicop   :=subst(0,e1,xicop   );
        etacop  :=subst(0,e1,etacop  );
        etapqcop:=subst(0,e1,etapqcop);
        flcop:=delete(e1,flcop);
        %depl!*:=delete(assoc(e1,depl!*),depl!*)$
      >>;
    >>;

    if flcop then <<
      if ((length flcop)+(length flist_snli))>1 then n:=t
                                                else n:=nil;
      terpri()$
      if flcop=flist_slin then write"-------- S"
                          else write"-------- Further s";
      write"ymmetr",if n then "ies:" else "y:"$
      terpri()$
      for each e1 in paralist do algebraic write lisp {'equal,cadr e1,reval caddr e1};
      for each e1 in xicop    do algebraic write lisp {'equal,cadr e1,reval caddr e1};
      for each e1 in etacop   do algebraic write lisp {'equal,cadr e1,reval caddr e1};
      for each e1 in etapqcop do algebraic write lisp {'equal,cadr e1,reval caddr e1}
    >>;

    terpri()$
    if flcop then
    <<write"with ";fctprint cdr reval ('list . append(flcop,flist_snli))>>;

    if null symcon_s then if flcop then
    <<write" which ",if n then "are" else "is"," free. ";
      terpri()>>                 else
                   else
    <<h:=print_;print_:=50$
      symcon_s:=for each a in symcon_s collect {'!*sq,a,t}$
      if print_ then
      <<terpri()$
        write"which still ",if n then "have" else "has"," to satisfy: ";
        terpri()$
        deprint symcon_s;
      >>        else    
      <<terpri()$
        write"which ",if n then "have" else "has",
             " to satisfy conditions. To see them set ";
        terpri()$
        write
        "lisp(print_= max. number of terms of an equation to print);";
        terpri()$
      >>;
      print_:=h
    >>;
    return_list:=list('list,
                      'list . symcon_s,
                      'list . append(paralist,append(xilist_s,etalist_s)),
                      'list . append(flist_slin,flist_snli)) . return_list;
    nodependlist ylist
  >>;

  terpri()$
  if (n1=0) and null symcon_s then <<
   if length eqlist=1 then write"The equation has no symmetry."
                      else write"The equations have no symmetry."$
   terpri()
  >>$
  write"-------- ";terpri();

  for each e1 in ylist do depnd(e1,list(xlist));
  recover_reduce_flags()$
  collect_sol:=oldcollect_sol;
  adjust_fnc:=oldadj;

  return 'list . return_list
end$ % of liepde

endmodule$

end$
