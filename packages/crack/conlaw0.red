
%            CONLAW file with subroutines for CONLAW1/2/3/4

%                   by Thomas Wolf, Sep 1997, Nov 2006

% BSDlicense: *****************************************************************
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

symbolic fluid '(reducefunctions_ print_)$ 

%-------------

symbolic procedure print_dropping_notice(h)$
% h is an algebraic list of the characteristic functions of the list of 
% input equations
% should also print the special values of parameters for this case
begin
 write"For this conservation law the characteristic function"$
 if cddr h then <<write"s:"$ algebraic write h>>   
           else <<write":"$ algebraic write first h>>$
 write"involve derivatives of functions of new variables. Currently, conserved"$
 terpri()$
 write"currents can not be computed from such "$
 if cddr h then write"characteristic functions."
           else write"a characteristic function."$ terpri()$
 write"One might transform the original system to these variables,"$
 terpri()$
 write"initialize the characteristic functions with the found"$terpri()$
 write"expressions and run conlaw3 to find the conserved current."$
 terpri()$
 write"======================================================"$terpri()$
end$

algebraic procedure print_claw(eqlist,qlist,plist,xlist)$
begin scalar n$
 write"  ( ",sqfirst qlist," ) * ( ",sqfirst eqlist," )"$
 qlist:=sqrest qlist; eqlist:=sqrest eqlist$
 while qlist neq {} do <<
  write"+ ( ",sqfirst qlist," ) * ( ",sqfirst eqlist," )"$
  qlist:=sqrest qlist; eqlist:=sqrest eqlist
 >>$
 write" = "$
 n:=length xlist$
 while plist neq {} do <<
  if length plist < n then write "+"$
  write"df( ",first plist,", ",first xlist," )"$
  plist:=sqrest plist;
  xlist:=sqrest xlist
 >>
end$

symbolic operator lhsli$
symbolic procedure lhsli(eqlist)$
% lhslist1 will be a list of all those lhs's which are a derivative or
%          a power of a derivative which is used to fix dependencies
%          of q_i or p_j
% lhslist2 will be a list of all lhs's of all equations in their
%          order with those lhs's set to 0 which can not be used 
%          for substitutions
begin scalar lhslist1,lhslist2,h1,flg1,flg2$
  for each h1 in cdr eqlist do <<
    flg1:=nil$    % no assignment to lhslist1 done yet
    if (pairp h1) and (car h1 = 'equal) then <<
      h1:=reval cadr h1;
      if (pairp h1) and 
         (car h1='expt) and 
         (numberp caddr h1) then <<flg2:=nil;h1:=cadr h1>>
                            else   flg2:=t;
      if (not numberp h1) and
         ((atom h1) or ((car h1='df) and (atom cadr h1) )) then 
      <<lhslist1:=cons(h1,lhslist1)$
        if flg2 then <<lhslist2:=cons(h1,lhslist2)$
                       flg1:=t>>
      >>
    >>;
    if null flg1 then lhslist2:=cons(0,lhslist2);
  >>$
  return list('list,cons('list,lhslist1),cons('list,lhslist2))
end$


put('chksub,'psopfn,'chksubstitution)$
symbolic procedure chksubstitution(inp)$
%
%symbolic operator chksub$
%symbolic procedure chksub(eqlist,ulist)$
%
% This is a psopfn procedure which does not evaluate the arguments
% automatically.
% The input equations should be in {!*sq,..,t} form (fast) but can be 
% in prefix form (slow).
% inp is a lisp list of 2 algebraic mode lists: eqlist, ulist
% the equations and functions/unknowns 
%
% eqlist is a list of equations   df(f,x,2,y) = ...
% this procedure tests whether 
% - for any equation a derivative on the rhs is equal or a derivative of
%   the lhs?
% - any lhs is equal or the derivative of any other lhs
begin scalar h1,h2,deril,complaint,eqlist,ulist,ls,rs$
 eqlist:=cdr aeval  car inp$   % new because of psopfn
 ulist :=cdr reval cadr inp$   % new because of psopfn
 for each e1 in eqlist do
 if not pairp e1 or (car e1 neq 'equal) then <<
  write"THE INPUT EQUATION "$deprint list e1$
  write"DOES NOT HAVE A FORM WHERE ONE DERIVATIVE IS ELIMINATED."$terpri()$
  write"AS A CONSEQUENCE CONSERVATION LAWS MAY BE LOST BY NOT"$terpri()$
  write"USING THE INPUT EQUATIONS TO ELIMINATE JET VARIABLES."$terpri()
 >>                                     else
 <<
  % cons( all_deriv_search(cadr  cdr e1,cdr ulist),      % lhs
  %       all_deriv_search(caddr cdr e1,cdr ulist) );    % rhs
  ls:=simp cadr  e1;
  rs:=simp caddr e1;
  deril:=cons(
  cons(                                         % lhs as {'!*SQ,..,t}
       append(all_deriv_search_sf(numr ls,ulist),   
              all_deriv_search_sf(denr ls,ulist) ),   
                                                % rhs as {'!*SQ,..,t}
       append(all_deriv_search_sf(numr rs,ulist),
              all_deriv_search_sf(denr rs,ulist) ) ),  deril)
 >>;

 %--- Is for any equation a derivative on the rhs equal to the lhs
 %--- or a derivative of the lhs?
 for each e1 in deril do 
 if car e1 then <<
  h1:=caaar e1;                  % e.g. h1 = (f x 2 y)
  for each h2 in cdr e1 do
  if (car h1 = caar h2) and null which_deriv(cdar h2,cdr h1) then <<
   complaint:=t;
   write "The left hand side ",
         if length h1 = 1 then car h1
                          else cons('df,h1)$terpri()$
   write " is not a leading derivative in its equation!"$ terpri()
  >>
 >>$
 %--- Is any lhs equal or the derivative of any other lhs? 
 if deril then
 while cdr deril do <<
  if caar deril then <<
   h1:=caaaar deril$
   for each h2 in cdr deril do
   if (car h2)           and
      (car h1=caaaar h2) and
      ((null which_deriv(cdr h1,cdaaar h2)) or
       (null which_deriv(cdaaar h2,cdr h1))    ) then <<
    complaint:=t;
    write"--> One left hand side (lhs) contains a derivative which"$
    terpri()$
    write"is equal or a derivative of a derivative on another lhs!"$
    terpri()$
   >>$
  >>$
  deril:=cdr deril
 >>;
 if complaint then terpri()$
end$

%==== Procedures as in LIEPDE:


symbolic operator listdifdif2$
symbolic procedure listdifdif2(lhslist,deplist)$
% lists all elements of deplist which are *not* derivatives
% of any element of lhslist
begin
  scalar h;
  deplist:=cdr reval deplist;
  lhslist:=cdr reval lhslist;
  for each h in lhslist do
  deplist:=listdifdif1(h,deplist);
  return cons('list,deplist)
end$ % of listdifdif2

%-------------

% symbolic operator totordpot$
% symbolic procedure totordpot(p,f)$
% %   Ordnung (total) der hoechsten Ableitung von f im Ausdruck p
% %   und hoechste Potenz der hoechsten Ableitung
% %   currently not used
% begin scalar a;
%  a:=ldifftot(reval p,reval f);
%  return
%  cons(eval(cons('PLUS,ldiff1(car a,fctargs reval f))), cdr a)
% end$

%-------------

algebraic procedure simppl(pllist,ulist,tt,xx)$
begin
 scalar pl,hh,td,xd,lulist,ltt,lxx,ltd,dv,newtd,e1,deno,ok,
        newpllist,contrace; 
 % contrace:=t;
 lisp <<
  lulist:=cdr reval algebraic ulist;
  lxx:=reval algebraic xx;
  ltt:=reval algebraic tt;
 >>;
 newpllist:={};
 for each pl in pllist do <<
  td:=first  pl;
  xd:=second pl;
  repeat <<
   lisp <<
    ltd:=reval algebraic td;
    if contrace then <<write"ltd1=",ltd;terpri()>>$
    dv:=nil;
    newtd:=nil;
    deno:=nil;
    if (pairp ltd) and (car ltd='quotient)   and
      my_freeof(caddr ltd,ltt) and
      my_freeof(caddr ltd,lxx) 
    then <<deno:=caddr ltd;ltd:=cadr ltd>>;
    ok:=t;

    if (pairp ltd) and (car ltd = 'plus) then ltd:= cdr ltd else
    if (pairp ltd) and (car ltd neq 'times) then ok:=nil
                                            else ltd:=list ltd;   
    if contrace then <<write"ltd2=",ltd;terpri()>>$
    if ok then <<
     for each e1 in ltd do <<
      hh:=intpde(e1, lulist, list(lxx,ltt), lxx, t);
      if null hh then hh:=list(nil,e1);
      dv   :=cons(car hh,dv);
      newtd:=cons(cadr hh,newtd);
     >>;
     dv   :=reval cons('plus,dv);
     newtd:=reval cons('plus,newtd);
     if deno then <<newtd:=list('quotient,newtd,deno);
                    dv   :=list('quotient,dv   ,deno) >>;
     if contrace then <<write"newtd=",newtd;terpri();
                        write"dv=",dv      ;terpri() >>$

     td:=newtd;
     if contrace then <<write"td=",td;terpri()>>$
     if (dv neq 0) and (dv neq nil) then <<
      xd:=reval(list('plus,xd,list('df,dv,tt)));
      if contrace then <<write"xd=",xd;terpri()>>$
      %algebraic mode:
      %hh:=lisp gensym()$
      %sbb:=absorbconst({td*hh,xd*hh},{hh})$
      %if (sbb neq nil) and (sbb neq 0) then
      %<<td:=sub(sbb,td*hh)/hh;  xd:=sub(sbb,xd*hh)/hh>>;
      % cllist would have to be scaled as well
     >>
    >>
   >>
  >>
  until lisp(dv)=0;
  newpllist:=cons({td,xd}, newpllist);
 >>;
 return reverse newpllist
end$ % simppl

%-------------

symbolic operator fdepterms$
symbolic procedure fdepterms(td,f)$
% fdepterms regards td as a fraction where f occurs only in the
% numerator. It determines all terms of the numerator in
% which f occurs divided through the denominator.
begin
  scalar nu,de,e1,sm;
  td:=reval td;
  if pairp td then
  if car td='quotient then <<nu:=cadr td;de:=caddr td>>;
  if null nu then nu:=td;
  if not pairp nu then if freeof(nu,f) then sm:=0
				       else sm:=nu
		  else <<
    if car nu = 'plus then nu:=cdr nu
		      else nu:=list nu;
    for each e1 in nu do
    if not freeof(e1,f) then sm:=cons(e1,sm);
    if null sm then sm:=0 else
    if length sm = 1 then sm:=car sm
		     else sm:=cons('plus,sm)
  >>;
  if de then sm:=list('quotient,sm,de);
  return sm
end$ % of fdepterms             

%-------------

symbolic procedure subtract_diff(d1,d2)$
% assumes d1,d2 to be equally long lists of numbers (at least one)
% that are orders of derivatives (which may be 0),
% These lists ca be produced using the procedure maxderivs(),
% returns nil if any number in d2 is bigger than the corresponding
% number in d1, returns list of differences otherwise
begin scalar d;
 return
 if car d2 > car d1 then nil else
 if null cdr d1 then {car d1 - car d2} else 
 if d:=subtract_diff(cdr d1,cdr d2) then cons(car d1 - car d2,d)
                                    else nil
end$

%-------------

symbolic procedure transfer_fctrs(h,flist)$
begin scalar fctr;
%algebraic write"begin: caar h=",lisp caar h," cdar h =",lisp cdar h;
 if (pairp cdar h) and (cadar h='minus) then 
 rplaca(h,cons(reval {'minus,caar h},cadr cdar h));

 if (pairp cdar h) and (cadar h='times) then 
 for each fc in cddar h do
 if freeoflist(fc,flist) then fctr:=cons(fc,fctr);
 if fctr then <<
  if cdr fctr then fctr:=cons('times,fctr)
              else fctr:=car fctr;
  rplaca(h,cons(reval {'times   ,caar h,fctr},
                reval {'quotient,cdar h,fctr} ))
 >>
%;algebraic write"end:   caar h=",lisp caar h," cdar h =",lisp cdar h;
end$

%-------------

symbolic operator partintdf$
symbolic procedure partintdf(eqlist,qlist,plist,xlist,flist,jlist,sb)$
% eqlist ... list of equations
% qlist  ... list of characteristic functions
% plist  ... list of components of conserved current
% xlist  ... list of independent variables
% flist  ... list of the arbitrary function occuring in this conservation law
% jlist  ... list of all jet-variables
% eqlist and qlist are in order.
% plist and xlist are in order.
% The aim is to remove all derivatives of f in the conservation law
% At first terms with derivatives of f in qlist are partially integrated.
% Then terms with derivatives of f in plist are partially integrated.
begin scalar f,n,d,deltali,subli,lhs,rhs,cof,x,y,cpy,newpl,lowd,su,vle,
             idty,idtysep,sbrev,dno,lsb,h0,h1,h2,h3,h4,h5,h6,h7,ldh1,ldh2,
             reductions_to_do,ld1,ld2,h0_changed,tr_pintd;
 % tr_pintd:=t$
 % 0. check that plist is homogeneous in flist
 algebraic <<
  cpy:=plist$
  for each f in flist do cpy:=sub(f=0,cpy)$
  while (cpy neq {}) and (first cpy = 0) do cpy:=rest cpy$ 
 >>$
 if cpy neq {'list} then return nil$

 eqlist:=cdr eqlist$
 qlist :=cdr  qlist$
 plist :=cdr  plist$
 xlist :=cdr  xlist$
 flist :=cdr  flist$
 jlist :=cdr  jlist$

 % 1. check that flist functions do only depend on xlist variables
 d:=t;
 for each f in flist do 
 if not_included(fctargs f,xlist) then d:=nil$
 if null d then return nil$

 terpri()$
 write"An attempt to factor out linear differential operators:"$terpri()$
 n:=0;
 while eqlist do <<
  n:=add1 n;
  su:=print_;print_:=nil;
  d:=newfct('eq_,xlist,n);
  print_:=su;
  deltali:=cons(d,deltali);
  algebraic write d,":=",lisp car eqlist$
  subli:=cons({'equal,d,car eqlist},subli)$
  lhs:=cons({'times,car qlist,d % car eqlist
     },lhs);
  eqlist:=cdr eqlist;
  qlist:=cdr qlist
 >>;
 lhs:=reval cons('plus,lhs)$
 subli:=cons('list,subli)$
 for each f in flist do << 
  f:=reval f$

  % removing f-derivatives from the lhs
  repeat <<
   d:=car ldiffp(lhs,f)$ %  liefert Liste der Variablen + Ordnungen mit Potenz
   if d then <<
    % correcting plist
    cpy:=d;
    while cpy and ((numberp car cpy) or freeof(xlist,car cpy)) do cpy:=cdr cpy;
    if null cpy then d:=nil
		else <<
     cof:=coeffn(lhs,cons('df,cons(f,d)),1);
     lhs:=reval {'difference,lhs,cons('df,cons({'times,cof,f},d))}$
     x:=car cpy;
     lowd:=lower_deg(d,x)$ % the derivative d reduced by one
     su:=if lowd then cons('df,cons({'times,cof,f},lowd))
		 else               {'times,cof,f}$

     cpy:=xlist;
     newpl:=nil;
     while cpy and (x neq car cpy) do <<
      newpl:=cons(car plist,newpl);
      plist:=cdr plist;
      cpy:=cdr cpy
     >>;
     plist:=cons({'difference,car plist,su},cdr plist);
     while newpl do <<
      plist:=cons(car newpl,plist)$
      newpl:=cdr newpl
     >>
    >>
   >>
  >> until null d;     % until no derivative of f occurs
  plist:=cdr algebraic(sub(subli,lisp cons('list,plist)))$

  % Now we add trivial conservation laws in order to get rid of
  % derivatives of f in the conserved current
  repeat <<
   newpl:=nil;
   cpy:=xlist;
   while plist and null(d:=car ldiffp(reval car plist,f)) do <<
    newpl:=cons(car plist,newpl);
    plist:=cdr plist;
    cpy:=cdr cpy
   >>;
   if d and (car d neq car cpy) then <<   % otherwise infinte loop
    cof:=coeffn(car plist,cons('df,cons(f,d)),1);
    x:=car d;
    lowd:=lower_deg(d,x)$ % the derivative d reduced by one
    su:=if lowd then {'times,cof,cons('df,cons(f,lowd))}
		else {'times,cof,              f       }$

    plist:=cons(reval reval {'difference,car plist,{'df,su,x}},cdr plist);
    while newpl do <<
     plist:=cons(car newpl,plist)$
     newpl:=cdr newpl
    >>$

    % adding the correction to the other component of plist
    y:=car cpy;
    cpy:=xlist;
    while x neq car cpy do <<
     newpl:=cons(car plist,newpl);
     plist:=cdr plist;
     cpy:=cdr cpy
    >>$
    plist:=cons(reval reval {'plus,car plist,{'df,su,y}},cdr plist);
    while newpl do <<
     plist:=cons(car newpl,plist)$
     newpl:=cdr newpl
    >>
   >> else <<d:=nil;plist:=append(reverse newpl,plist)>>
  >> until null d;
 >>;

 vle:=length xlist;

 newpl:=algebraic absorbconst(lisp cons('list,append(qlist,plist)),
                                   cons('list,flist))$
 if newpl then newpl:=cdadr newpl;

 % Now factorizing out a linear differential operator
 % 2. extend dependencies of functions from flist and add extra conditions
 for each f in flist do <<
  depl!*:=delete(assoc(f,depl!*),depl!*);
  depl!*:=cons(cons(f,xlist),depl!*);
 >>$
 % 3. compute coefficients of the conditions in the identity 
 idty:=algebraic(sub(subli,lhs))$
 for n:=1:vle do 
 if not zerop nth(plist,n) then 
 idty:={'difference,idty,{'df,nth(plist,n),nth(xlist,n)}}$
 % 4. separate idty into conditions with multiplicities
 sbrev:=cons('list,for each d in cdr sb collect {'equal,caddr d,cadr d})$
 idty:=reval reval idty$
 dno:=algebraic den idty;
 if dno neq 1 then idty:=algebraic num idty$

 idty:=algebraic(sub(sbrev,idty))$
 su:=print_;print_:=nil;
 idtysep:=separ(reval idty,flist,jlist,nil,nil)$
 print_:=su;
 idtysep:=for each d in idtysep collect 
 cons(reval algebraic(sub(sb,lisp car d)),cdr d);

 % 5. integrations of cdr of the elements of idty have to be done:
 %    - sufficiently often so that there are not more conditions
 %      than functions in flist
 %    - as few as possible to have factored out afterall an as
 %      high as possible operator

 reductions_to_do:=length idtysep - length flist;
 if reductions_to_do>0 then <<
  h0:=idtysep;
  while h0 do <<
   rplaca(h0,cons(reval caar h0, reval cdar h0));
   transfer_fctrs(h0,flist); h0:=cdr h0
  >>$

  if tr_pintd then <<
   write"Separation gives:"$terpri()$
   for each d in idtysep do 
   algebraic write "0 = (",lisp car d,") * (",lisp cdr d,")"$
  >>$

  h0:=idtysep;
  repeat <<  % check whether cdar h0 is a derivative of another condition
   h0_changed:=nil;
   h1:=cdar h0;
   if tr_pintd then 
   algebraic write"caar h0=",lisp caar h0," cdar h0 =",lisp cdar h0;

   % find a function appearing in h1 and its leading derivative
   cpy:=flist;
   while cpy and freeof(h1,car cpy) do cpy:=cdr cpy;
   % if null cpy then error!
     
   ld1:=car ldiffp(h1,car cpy)$
   ldh1:=maxderivs(nil,ld1,xlist)$
   ld1:=if null ld1 then car cpy
                    else cons('df,cons(car cpy,ld1))$
     
   h2:=idtysep;
   while h2 do 
   % is h1 a derivative of car h2 or car h2 a derivative of h1?
   if (h2 eq h0) or freeof(cdar h2,car cpy) then h2:=cdr h2
                                            else <<

    if tr_pintd then 
    algebraic write"caar h2=",lisp caar h2," cdar h2 =",lisp cdar h2;
    ld2:=car ldiffp(cdar h2,car cpy)$
    ldh2:=maxderivs(nil,ld2,xlist)$
    ld2:=if null ld2 then car cpy
                     else cons('df,cons(car cpy,ld2))$

    % is h1 a derivative of car h2?
    h3:=subtract_diff(ldh1,ldh2);
    if null h3 then h2:=cdr h2
               else << 
     % the leading derivative in h1 is a derivative of 
     % the leading derivative in cdar h2
     h4:=cdar h2;
     if pairp h4 and (car h4 = 'plus) then <<
      for n:=1:vle do if not zerop nth(h3,n) then
      h4:={'df,h4,nth(xlist,n),nth(h3,n)};
      if null freeoflist(h5:=algebraic(h1/h4),flist) then h2:=cdr h2
                                                     else <<
       % h1 = h5 * derivative of (cdar h2)
       h6:={'times,caar h0,reval h5};
       for n:=1:vle do <<
        h7:=nth(h3,n);
        if not zerop h7 then
        h6:={'times,{'expt,-1,h7},{'df,h6,nth(xlist,n),h7}};
       >>;
       rplaca(h2,cons(reval {'plus,caar h2,h6},cdar h2));
       rplaca(h0,cons(0,0));
       if tr_pintd then <<
	algebraic write"Change(1):"$
	algebraic write"caar h2=",lisp caar h2," cdar h2 =",lisp cdar h2;
	algebraic write"caar h0=",lisp caar h0," cdar h0 =",lisp cdar h0;
       >>$
       reductions_to_do:=sub1 reductions_to_do;
       h2:=nil
      >>
     >>                               else <<
      % Update of car h2
      h6:=algebraic(lisp(caar h0)*coeffn(h1,ld1,1));
      for n:=1:vle do <<
       h7:=nth(h3,n);
       if not zerop h7 then
       h6:={'times,{'expt,-1,h7},{'df,h6,nth(xlist,n),h7}};
      >>;
      rplaca(h2,cons(reval {'plus,caar h2,h6},cdar h2));
      if tr_pintd then <<
       algebraic write"Change(2):"$
       algebraic write"caar h2=",lisp caar h2," cdar h2 =",lisp cdar h2;
      >>$

      % Update of car h0
      h1:=reval {'difference,h1,{'times,coeffn(h1,ld1,1),ld1}}$

      if zerop h1 then <<rplaca(h0,cons(0,0));h2:=nil;
                         reductions_to_do:=sub1 reductions_to_do>>
                  else <<rplaca(h0,cons(caar h0,h1));
                         transfer_fctrs(h0,flist);
                         h1:=cdar h0;
                         cpy:=flist;
                         while cpy and freeof(h1,car cpy) do cpy:=cdr cpy;
                         ld1:=car ldiffp(h1,car cpy)$
                         ldh1:=maxderivs(nil,ld1,xlist)$
                         ld1:=if null ld1 then car cpy
                                          else cons('df,cons(car cpy,ld1))$
                         h2:=cdr h2;h0_changed:=t>>;
      if tr_pintd then 
      algebraic write"caar h0=",lisp caar h0," cdar h0 =",lisp cdar h0;
     >>

    >>
   >>;
   if (null h0_changed) or (zerop caar h0) then h0:=cdr h0
  >> until (reductions_to_do=0) or (null h0);

  if tr_pintd then <<
   write"After correction the separation gives:"$terpri()$
   for each d in idtysep do 
   if not zerop car d then
   algebraic write "0 = (",lisp car d,") * (",lisp cdr d,")"$
  >>
 >>$

 % Now the number of f in flist should be equal the number of conditions
 % or as low as possible
 n:=0;
 rhs:=nil;
 for each d in idtysep do 
 if not zerop car d then << % for each condition
  n:=add1 n;
  su:=print_;print_:=nil;
  x:=newfct('l_,xlist,n);
  print_:=su;
  su:=if dno=1 then car d 
               else reval {'quotient,car d,dno}$
  algebraic write x,":=",su$
  lsb:=cons({'equal,x,su},lsb);
  % 5. for each condition integrate all terms
  y:=cdr d;
  cpy:=flist;
  while y and not zerop y do <<
   repeat <<
    d:=ldiffp(y,car cpy)$
    if zerop cdr d then
    if null cpy then <<write"The backintegration is faulty."$terpri()>>
                else cpy:=cdr cpy
   >> until not zerop cdr d;
   if car d = nil then <<
    cof:=coeffn(y,car cpy,1);
    rhs:={'plus,{'times,x,cof,car cpy},rhs};
    y:=reval reval {'difference,y,{'times,cof,car cpy}}
   >>             else <<
    cof:=coeffn(y,cons('df,cons(car cpy,car d)),1);
    rhs:=reval {'plus,rhs,{'times,cons('df,cons({'times,x,cof},car d)),
                                  car cpy,{'expt,{'minus,1},absodeg(car d)}}};
    y:=reval reval {'difference,y,{'times,cof,cons('df,cons(car cpy,car d))}}
   >>
  >>
 >>$
 lsb:=cons('list,lsb)$
 flist:=cons('list,flist)$
 algebraic <<
  d:=gcd(den lhs,den rhs);
  lhs:=lhs*d; rhs:=rhs*d;

  %--- Correctness test
  d:=sub(subli,lhs)-sub(lsb,rhs);
  if d neq 0 then write "Not identically zero : ",d$

  for each f in flist do algebraic <<
   x:=coeffn(num lhs,f,1);  y:=coeffn(num rhs,f,1);
   d:=gcd(x,y);
   algebraic write x/d/den lhs," = ",y/d/den rhs$
  >>  
 >>$

end$

%-------------

end$

