%********************************************************************
module simpsolution$
%********************************************************************
%  Routines for simplifying expressions by changing free functions
%  and constants of integration
%  Author: Thomas Wolf
%  Nov 1993

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

symbolic operator dropredundant$

symbolic procedure dropredundant(ex,fl,vl,unequ)$
COMMENT
 All arguments are algebraic, ex is the list of expressions or
 equations from which the right side is taken, fl is the list of
 functions to be sorted out, vl the list of all extra independent variables,
 not already included in fl.
 returns algebraic list of redundant functions/const.=0, new EX, new FL
         readable into algebraic code
 currently (June 2010) only called from liepde $
begin scalar a;
 vl:=union(reverse argset cdr fl,cdr vl)$
 if null ftem_ then ftem_:=cdr fl$
 a:=dropredund(list(for each a in cdr ex collect simp 
                    if (pairp a) and (car a='equal) then caddr a else a,{},
                    cdr fl,for each a in cdr unequ collect simp a),nil,vl);
 % dropredund() returns 
 % {{{EQUAL,f,0},..},{SQ-exp,..},{{EQUAL,f,SQ-exp},..},
 %  union(nofl_arbit,flstart),{ineq_ in SQ-form}}
 return if a then 
 {'list,cons('list,car    a),
	cons('list,for each b in caddr a collect
                   {'equal,cadr b,prepsq caddr b}),
	cons('list,cadddr a) }
	     else nil
end$


symbolic procedure del_redundant_fc(arglist)$
% prepares a call of dropredund() from within a crack run (module 40)
% as a side-effect all substitutions fsub_ are made in forg
begin
 scalar p,f,fli,nofl,fred,redu,dropped,oldpdes,newpdes,newpval,
        bak,prolibak,newforg$

% bak:=backup_pdes(car arglist,cadr arglist)$
% prolibak:=proc_list_;
% proc_list_:=default_proc_list_;
% if null ftem_ then ftem_:=cadr arglist$
%
% for each f in cadr arglist do 
% if not pairp f then nofl:=cons(f,nofl) else
% if car f='EQUAL then fli:=cons(f,fli)$
% fred:=setdiff(ftem_,nofl);

 % fsub_ substitutions are done in forg:
 bak:=fsub_;
 for each f in (newforg:=sub_fsub_in_itself_and_in_forg cadr arglist) do 
 % i.e. for each f in forg
 if not pairp f then nofl:=cons(f,nofl) else
 if car f='equal then fli:=cons(f,fli)$  
 % fli has the form {{EQUAL,f,SQ-form},...}
 fred:=setdiff(ftem_,nofl);
 if null fred then return if null bak then nil
                                      else {car arglist,newforg}; 
 % not always return nil because if fsub_ was not nil (i.e. if lazy_eval=t
 % and lin_problem=nil) then substitutions have been made in forg.
 fsub_:=bak;

 bak:=backup_pdes(car arglist,cadr arglist)$
 prolibak:=proc_list_;
 proc_list_:=default_proc_list_;

 if expert_mode then <<
  write"Which functions shall be checked for redundancy? "$
  f:=select_from_list(fred,nil)$
  if f then <<nofl:=append(nofl,setdiff(fred,f)); fred:=f>>;
 >>$

 redu:=
 dropredund({for each p in car  arglist collect get(p,'sqval),  
             fli,      % all of form: {EQUAL,f,SQ-form}
             fred,     % functions that can be dropped
             ineq_},
            nofl,vl_);
 % dropredund() returns 
 % {{{EQUAL,f,0},..},{SQ-exp,..},{{EQUAL,f,SQ-exp},..},
 %  union(nofl_arbit,flstart),{ineq_ in SQ-form}}

 oldpdes:=car restore_pdes(bak)$
 % This restores pass_on AND pass_back values.
 proc_list_:=prolibak;
 if redu and car redu then <<
  for each f in car redu do <<
   dropped:=cons(cadr f,dropped)$
   % none of the dropped functions is in forg so all can be put in:
   drop_fct(cadr f)
  >>$
  ftem_:=setdiff(ftem_,dropped);
  flin_:=setdiff(flin_,dropped);
  newpval:=cadr redu$        % a list of all SQ-form values of all equations

  while newpval do <<        % newpdes starts as nil
   newpdes:=if get(car oldpdes,'sqval) = car newpval 
            then eqinsert(car oldpdes,newpdes) 
            else <<for each f in allflags_ do flag1(car oldpdes,f)$ 
                   % initialization before calling update
                   p:=updatesq(car oldpdes,car newpval,nil,nil,get(car oldpdes,'fcts),
                               get(car oldpdes,'vars),t,{0},newpdes)$
                   if null p then <<
                    drop_pde_from_idties(car oldpdes,car arglist,nil);
                    drop_pde_from_properties(car oldpdes,car arglist)
                   >>        else eqinsert(p,newpdes) % cons(p,newpdes)
                 >>;
   newpval:=cdr newpval;
   oldpdes:=cdr oldpdes
  >>$  

  % delete the dropped functions in the property list of the forg functions
  for each f in dropped do
  for each p in caddr redu do <<
   if (pairp p) and (car p='equal) then
   put(cadr p,'fcts,delete(f,get(cadr p,'fcts)))
  >>$

  return {newpdes,append(caddr redu,setdiff(nofl,setdiff(nofl,cadr arglist)))}
  % appending only those nofl elements which have been in forg=cadr arglist
 >>
end$

symbolic procedure dropredund(a,nofl,vl)$   
% a has the structure of one solution of CRACK in symbolic mode,
% {{SQ-expressions},{{EQUAL,f,SQ-form}},{f},{ineq_ in SQ-form}}
% nofl is a list of functions not to be modified or dropped
%
% dropredund
% - makes a copy of the free constants and functions in the solution,
% - sets to zero the difference between the old solution and the new
%   with replaced constants and functions,
% - finds the non-essential constants/functions and
% - returns  cons(list of redundant fnc./cons=0,new solution)
%
% possible future generalizations are marked as +&+

% if no assignment or no function f then return of nil
if cadr  a then if length cadr  a > 0 then
if caddr a then if length caddr a > 0 then 
begin
 scalar sol,arbit,fl,el1,el2,el3,corres,b,b1,b2,condi,oldcon,
        redund,flstart,fldrop,fldupli2,newfu,newcorres,unequ,unsolved,
        vlf,vla,potold,newnewfu,fldupli,nofl_arbit,ineq_bak,ineq_or_bak,
        vl_bak,ftem_bak,proc_list_bak,session_bak,adjust_fnc_bak,level_bak,
        collect_sol_bak,batch_mode_old,printold,batchcount_bak,stepcounter_bak,
        flin_bak,old_hist_bak$

 printold:=print_;
 if null print_ and null batch_mode_sub then print_:=8$
 if print_ and batch_mode_sub then print_:=nil$
 batch_mode_old:=!*batch_mode;
 !*batch_mode:=batch_mode_sub;
 if not !*batch_mode then <<
  write"-------------------------------------------------------------"$
  terpri()$
  write" A new CRACK computation starts to find redundand functions. "$
  terpri()$
 >>$

 %
 for each el1 in append(car a,cadr a) do
 if el1 then b1:=cons(if pairp el1 then 
                      if car el1 = 'equal then caddr el1
                                          else el1
	                           else el1             ,b1);
 % b1 is the list of expressions in SQ-form to be invariant  
 % These are all equations and rhs's of assignments. Strictly speaking,
 % after a fix of redundand functions the new system need not 
 % reduce to exactly the same system but only an equivalent one
 % but for simplicity we require here the redundancy for each equation.
 b2:=b1;                            

 % arbit is the list of original free functions in the input solution
 arbit:=caddr a;
 flin_bak:=flin_$   

 % For the following comments an >eligible< function is a function that is
 % provided as a so far free function (arbint) but which is not in forg
 % i.e. which is not a so far unevaluated original function.
 %
 % flstart is the list of eligible functions that 
 %         turn up in the invariant expressions including the
 %         duplicates of these functions
 % fldrop is the list of eligible functions which do not
 %         turn up in invariant expressions and thus can be dropped
 % fldupli is a list of all new duplicate-functions, fldupli2 is a copy
 % b2      is a duplicate of the list of invariant expressions b1
 % fl      is the list of all functions (potentially dropable + their new copy)
 % corres  is a list of correspondences of functions and their dupl.

 for each el1 in arbit do 
 if not freeof(nofl,el1) then nofl_arbit:=cons(el1,nofl_arbit)
                         else
 if not my_freeof(b1,el1) then <<
  flstart:=cons(el1,flstart);
  el2:=newfct(fname_,fctargs(el1),nfct_)$
  if not freeof(flin_,el1) then flin_:=cons(el2,flin_);
  fldupli:=cons(el2,fldupli);
  nfct_:=add1 nfct_$
  b2:=for each b in b2 collect subsq(b,{(el1 . el2)});
  fl:=cons(el1,cons(el2,fl));
  corres:=cons((el1 . el2),corres);
 >>                       else
 fldrop:=cons(el1,fldrop);

 % condi is the set of conditions: difference of related expressions=0
 while b1 do <<
  condi:=cons(subtrsq(car b1,car b2),condi);
  b1:=cdr b1;
  b2:=cdr b2
 >>;
 b1:=nil;b2:=nil;
 potold:=potint_;
 % 28.8.2009: crack was not able to find redundand functions for the system:
 %
 % 0=c_12  + 2*c_9  + c_9 *a + c_9 *b
 %       a        t      x        x
 %
 % 0=c_12  + 2*c_8  + c_8 *a + c_8 *b + c_14
 %       b        t      x        x
 %
 % for c_9(b,a,x,t), c_8(b,a,x,t), c_12(b,a,t), c_14(b,t)
 % because in the crack computation below it could not integrate
 % 0=c_46  - c_47
 %       a      
 % therefore potint_ is switched back on for now.
 % potint_:=nil;
 potint_:=t;
 session_bak:=session_; 
 session_:=nil$   % to prevent interference with solutions and the casetree
 % orderings_:=mkvect(1)$
 % putv(orderings_,0,list(vl,fl,'default_ordering_function))$
 ineq_bak    :=ineq_;       ineq_      :=nil; 
 ineq_or_bak :=ineq_or;     ineq_or    :=nil; 
 vl_bak      :=vl_;         vl_        :=vl;
 old_hist_bak:=old_history; old_history:=nil$
 ftem_bak    :=ftem_;       ftem_      :=nil$
 level_bak   :=level_;      level_     :=nil;
 for each b in fldupli do ftem_:=fctinsert(b,ftem_)$
 flin_:=sort_according_to(flin_,ftem_);
 if not freeof(proc_list_,'stop_batch) then <<
  proc_list_bak:=proc_list_;
  proc_list_:=delete('stop_batch,proc_list_)
 >>;
 adjust_fnc_bak:=adjust_fnc; adjust_fnc:=nil;
 collect_sol_bak:=collect_sol$collect_sol:=t$
 batchcount_bak :=batchcount_$  batchcount_:=-1$
 stepcounter_bak:=stepcounter_$ stepcounter_:=0$
 b:=crackmain(mkeqsqlist(condi,nil,nil,fl,vl_,allflags_,t,
                         list(0),nil),fl);  %### each element of b has now 5 elements
 batchcount_:=batchcount_bak$
 stepcounter_:=stepcounter_bak$
 collect_sol:=collect_sol_bak$ flin_:=flin_bak;
 adjust_fnc:=adjust_fnc_bak;  level_:=level_bak;
 ineq_:=ineq_bak;  ineq_or:=ineq_or_bak;
 vl_:=vl_bak;      ftem_:=ftem_bak$ % temporarily 
 if proc_list_bak then proc_list_:=proc_list_bak;
 old_history:=old_hist_bak$

 % Now we look for a solution without inequalities and without remaining 
 % equations where each right hand side contains at least one fl-function.
 % All useful ones are copied into b2. If none is useful then only fldrop
 % functions are dropped else b:=car b2 is the solution to be investigated
 % further.
 
 for each b1 in b do                       
 if pairp b1 % then
% if ((not car b1) or         % no remaining equations or they involve  
%     freeoflist(car b1,fl))  % only functions just introduced in crack 
% apparently no need for this condition as appearance of new free functions
% in remaining conditions `unsolved' is tested below
    % and (not cadddr b1) % i.e. ineq_=nil has been dropped because the 
    %% functions to be checked whether they can be zero or not (e.g. c_30) 
    %% are not in ftem_ and thus can not become identical zero which, and in 
    %% the case of an equation 0=c_30-c_60 means that c_60 which is in ftem_
    %% can not become zero which means cadddr b1=(c_60) <> nil but
    %% which has no implication that this solution could not be used
    %% for dropping other functions than c_30, so the condition 
    %% (not cadddr b1) is dropped.
 then <<
  el1:=t;
  % if there is a right hand side of any computed assignment which is free 
  % of fl and free of all free variables from the solution b1 then el1:=nil .
  for each el2 in cadr b1 do % for each computed assignment
  if (pairp el2) and         % should always be true
     (car el2='equal) and    % should always be true
     (null smemberl(fl,caddr el2)) and
     (null smemberl(caddr b1,caddr el2)) then el1:=nil;
  if el1 then b2:=cons(b1,b2);  
 >>$
 potint_:=potold;
 session_:=session_bak;
 print_:=printold;
 if not !*batch_mode then <<
  terpri()$
  write" The CRACK computation to find redundand functions finished."$terpri()$
  write"------------------------------------------------------------"$terpri()$
 >>$
 !*batch_mode:=batch_mode_old;
 if null b2 then return <<   
  for each el1 in append(fldupli,fldrop) do 
  drop_fct(el1)$ % depl!*:=delete(assoc(el1,depl!*),depl!*)$
  if null fldrop then nil
                 else <<    % drop at least all functions fldrop
   redund:=for each el1 in fldrop collect list('equal,el1,0); 

   % `a' has the structure of one solution of CRACK in symbolic mode,
   % {{SQ-expressions},{{EQUAL,f,SQ-form}},{f},{ineq_ in SQ-form}}

   % substitution list for substitutions in SQ-expressions
   el2:=for each el1 in fldrop collect (el1 . 0);

   oldcon:=for each el3 in car a collect subsq(el3,el2);
   % so that oldcon is in exact same order as car a.

   % substitutions in assignments
   sol:=for each el3 in cadr a collect 
        {'equal,cadr el3, subsq(caddr el3,el2)};

   % substitutions in inequalities 
   unequ:=for each el3 in cadddr a collect subsq(el3,el2);

   list(redund,oldcon,sol,union(nofl_arbit,flstart),unequ)
  >>
 >>         else b:=car b2;

 % b is the first of the usable solutions and the only one considered
 % in the following. It has the form of a single solution of crackmain i.e.
 % b = list(for each a in pdes collect get(a,'sqval),
 %          forg,
 %          setdiff(ftem_,forg),
 %          ineq_,
 %          ineq_or)
 unsolved:=car b$               
 arbit:=caddr b;   % arbit are the free functions of the last CRACK run
                   % newfu are the assignments computed in the last CRACK run
 for each el1 in cadr b do
 if not((pairp el1       ) and
        (car el1 = 'equal)     ) then arbit:=cons(el1,arbit)
                                 else newfu:=cons(el1,newfu)$ 
 oldcon:=car a;   
 sol:=cadr a;     
 unequ:=cadddr a; 

 % flstart are the remaining essential free functions
 % redund are the functions to be dropped, they are set to 0 in
 % the old solution, redund starts here as nil
 fldupli2:=fldupli;
 for each el1 in corres do
 if member(car el1,arbit) and member(cdr el1,arbit) and
    freeof(unsolved,car el1) and freeof(unsolved,cdr el1) then <<
  % +&+ It probably is enough to test whether car el1 and cdr el1
  % do not appear in an equation of `unsolved' which has only as
  % independent variables the same as car el1 and cdr el1 depend on.

  redund:=cons(list('equal,car el1,0),redund);
  fldrop:=cons(car el1,fldrop);
  % the function and its copy are both not essential
  oldcon:=for each el2 in oldcon collect subsq(el2,{(car el1 . 0)});
  sol:=for each el2 in sol collect <<
   if (pairp el2) and (car el2='equal) then
   put(cadr el2,'fcts,delete(car el1,get(cadr el2,'fcts)));
   {'equal,cadr el2, subsq(caddr el2,{(car el1 . 0)})}
  >>$
  unequ:=for each el2 in unequ collect subsq(el2,{(car el1 . 0)});
  arbit:=delete(car el1,arbit);
  arbit:=delete(cdr el1,arbit);
  fl:=delete(car el1,fl);
  fl:=delete(cdr el1,fl);
  flstart:=delete(car el1,flstart);
  fldupli2:=delete(cdr el1,fldupli2); 
  % newfu is a list of assignments of the last crackmain run
  newfu:=for each el2 in newfu collect 
  {'equal,cadr el2, subsq(caddr el2,{(car el1 . 0),(cdr el1 . 0)})}
 >>                                                 else
 newcorres:=cons(el1,newcorres);

 % fldupli2 are the duplicated functions which are not deleted as 
 % redundand yet.
 % Eliminate from all equations the fldupli2 function in terms of
 % the corresponding flstart function and possibly other terms
 % newnewfu becomes a list of substitutions of new functions
 % by expressions in old functions.

 while newfu do <<
  el1:=car newfu; % el1: evaluated function = expression 
  el2:=cadr el1;  % el2: evaluated function 
  b:=newcorres;   % the remaining correspondences
  while b and (el2 neq cdar b) do b:=cdr b;
  if b then       % el2 = cdar b is a new function 
  if (not freeof(el1,caar b)) then newnewfu:=cons(el1,newnewfu)
                              else <<
   % The right hand side ex1 of equation el1: el2=ex1 does not 
   % contain the old function, say f, which corresponds to the 
   % new function el2
   % --> search for an equation car el3 in newfu of the form 
   % f = ex2, then add el2=ex1+f-ex2 to newnewfu
   el3:=newfu;
   while el3 and (cadar el3 neq caar b) do el3:=cdr el3;
   if el3 then <<
    newnewfu:=cons(list('equal,el2,
                        subtrsq(addsq(caddr el1,
                                      simp cadar el3),
                                caddar el3)),
                   newnewfu);
    newfu:=delete(car el3,newfu)
   >>     else newnewfu:=nil;  % means later that it can not be treated
  >>   else <<    % el2 is an old function 
   % like in the case above, only that in order to add equations of
   % the form new_fct = expr in old_fcts can be added to newnewfu,
   % the equations has to be solved for new_fct

   b:=newcorres;  % the correspondences of the remaining functions
   while el2 neq caar b do b:=cdr b; % caar b is now el2 (old function)

   if (not freeof(el1,cdar b)) then  % image function of el2 is in el1
   % solving el1 for the image function cdar b of el2
   newnewfu:=cons({'equal,
                   cdar b,
                   subtrsq(addsq(simp cdar b,
                                 simp el2),
                           caddr el1)},
                  newnewfu)
                               else <<
    % add an equ. to el1 with (the pri-image function of el2) = ...
    el3:=newfu;
    while el3 and (cadar el3 neq cdar b) do el3:=cdr el3;
    if el3 then <<
     newnewfu:=cons({'equal,
                     cdar b,
                     subtrsq(addsq(caddar el3,
                                   simp cadr el1),
                             caddr el1)},
                    newnewfu);
     newfu:=delete(car el3,newfu)
    >>     else newnewfu:=nil;  % means later that it can not be treated
   >>    
  >>;
  newfu:=cdr newfu
 >>;
 newfu:=newnewfu;

 % test, whether each new function has exactly one substitution
 % and no new function appears on a rhs
 if length fldupli2 = length newfu then 
 while newnewfu and freeoflist(caddar newnewfu,fldupli2) do 
 newnewfu:=cdr newnewfu;
   
 if newfu and (not newnewfu) then <<  
  % now the conditions have really been solved for the new 
  % functions, no new function is on the rhs

  % arbit are all free old and new functions after the above CRACK-run
  % fl are all functions at the start of the above CRACK-run
  % fldupli2 are all remaining new functions
  % flstart are all the old functions
  % new arbit: all functions which came in only through the
  %            last CRACK run
  arbit:=setdiff(setdiff(union(arbit,fl),fldupli2),flstart);

  % rewriting the substitutions as: old fct = expr in old fcts
  newfu:=
  for each el1 in newfu collect <<
   b:=cadr el1;     % b is a new function
   el2:=newcorres;  % caar el2 the corresponding old function
   while b neq cdar el2 do el2:=cdr el2; 
   list('equal,caar el2,caddr el1)
  >>;

  % arbit are now all functions which came in only through the
  % last CRACK run. From them we take only those who do not turn up in
  % remaining unsolved equations `unsolved'. The idea is to use them 
  % to compensate as many as possible functions flstart such that the
  % counterpart of the flstart function which is solved for in the
  % assignment can be made to zero. These are the new values of the
  % flstart functions and if they are zero then the flstart function
  % is redundant.

  % Specifying the functions in arbit which are free to get as many
  % as possible functions flstart to zero
  arbit:=fctsort(arbit)$  % to use the functions with most variables first
  for each el1 in arbit do 
  if freeof(unsolved,el1) then << % only if el1 is truely free
   % +&+ It probably is enough to test whether el1 does not 
   % appear in an equation of `unsolved' which has only as
   % independent variables the same as el1 depends on.
   vla:=fctargs el1; % variables of the function to be eliminated
   el2:=newfu;
   while el2 do 
   if freeof(car el2,el1) then el2:=cdr el2
                          else <<
    vlf:=fctargs cadar el2;
    if (null not_included(vla,vlf)) and
       (null not_included(vlf,vla)) then <<
     % cadar el2 is a function that shall be made to zero
     % by a choice for el1

     % It is checked whether the arbitrary function el1 occurs only
     % linearly algebraically, so that it can be computed by
     % solving equation car el2
     b:=lderiv(reval {'!*sq,caddar el2,t},el1,vla);
     if cdr b=1 then << % success!! cadar el2 can be set to zero!
      if (car b neq el1) and print_ then <<terpri()$
       write" It is assumed that the equation:";terpri()$
       deprint {{'!*sq,caddar el2,t}};
       write" has always a solution in ",el1;terpri()$
       write" functions: ";
       el3:=append(flstart,arbit); 
       b:=nil;
       while el3 do <<
        if not freeof(caddar el2,car el3) then b:=cons(car el3,b);
        el3:=cdr el3
       >>;
       fctprint b; b:=nil
      >>;
      redund:=cons(list('equal,cadar el2,0),redund);
      fldrop:=cons(cadar el2,fldrop);
      oldcon:=for each el3 in oldcon collect subsq(el3,{(cadar el2 . 0)});
      sol:=for each el3 in sol collect <<
       if (pairp el3) and (car el3='equal) then 
       put(cadr el3,'fcts,delete(cadar el2,get(cadr el3,'fcts)));
       {'equal,cadr el3, subsq(caddr el3,{(cadar el2 . 0)})}
      >>$
      unequ:=for each el3 in unequ collect subsq(el3,{(cadar el2 . 0)});
      flstart:=delete(cadar el2,flstart);
      newfu:=delete(car el2,newfu);     
      el2:=nil;
     >>
    >>;
    if el2 then el2:=cdr el2
   >>
  >>;

  % substituting all remaining functions arbit in the substitutions 
  % newfu to zero which are not already specified
  % 12.8.2007: I don't see how newfu is used after the substitution
  el2:=for each el1 in arbit collect (el1 . 0);
  newfu:=for each el1 in newfu collect 
         {'equal,cadr el1, subsq(caddr el1,el2)}
 >>;
 if fldrop and print_ then <<
  terpri()$
  write"non-essential dropped constant(s) or function(s): ";
  fctprint fldrop
 >>$
 for each el1 in append(fldupli,fldrop) do 
 depl!*:=delete(assoc(el1,depl!*),depl!*)$
 return
 if null fldrop then nil
	 else list(redund,oldcon,sol,union(nofl_arbit,flstart),unequ)
end$

symbolic operator ncontent$
symbolic procedure ncontent p$
% Return numeric content of expression p
% based on simpnprimitive in ezgcd.
<< p := simp!* p;
%   if polyzerop(numr p) then 0 else
   if p=('nil . 1) then 0 else
   mk!*sq(numeric!-content numr p ./ numeric!-content denr p)
>>$

algebraic procedure absorbconst(exlist,flist)$
% absorbing numerical factors into free constants/functions of flist
% if the list of expressions in exlist is known to be linear in flist
% returns an algebraic list of substitutions to be done
% ### This could be speeded up considerably but is not necessary.
begin
  scalar e1,e2,n,n1,n2,nu,sb,cs1,cs2,!*rational_bak;
  !*rational_bak:=!*rational;
  if !*rational then algebraic(off rational)$
  sb:={};
  for each e1 in flist do <<
    n1:=nil;
    % to make a change of sign at least one equation 
    % must demand it which is cs1=t
    % and no equation must forbit it which is cs2=nil
    cs1:=nil; cs2:=t;
    for each e2 in exlist do <<
      n:=coeffn(e2,e1,1);
      if n neq 0 then <<
	% if at least one equation does not demand a change of
	% sign then no change of sign is made

        if (numberp n) and (n<0) then cs1:=t
                                 else
	if lisp pairp reval algebraic n then <<
	  if part(n,0)='minus then cs1:=t else
	  if part(n,0)='quotient then
          <<nu:=part(n,1);
            if lisp( pairp reval algebraic nu) and 
               (part(nu,0)='minus) then cs1:=t else
            if (numberp nu) and (nu<0) then cs1:=t else
            if (arglength(nu)>0) and (part(nu,0)='plus) and 
               (arglength(part(nu,1))>0) and 
               (part(part(nu,1),0)='minus) then cs1:=t
                                           else cs2:=nil
          >>                     else 
	  if (part(n,0)='plus) and (arglength(part(n,1))>0) and 
             (part(part(n,1),0)='minus) then cs1:=t
                                        else cs2:=nil
	>>;
	n:=ncontent(n);
	if n1=nil then <<n1:=num n; n2:=den n>>
		  else <<
	  n1:=gcd(n1,num(n));
	  n2:=n2*den(n)/gcd(n2,den(n))
	>>
      >>
    >>;

    if n1 and ((n1 neq 1) or (n2 neq 1)) then <<
      if cs1 and cs2 then n2:=-n2;
      sb:=cons(e1=e1*n2/n1 , sb);
    >>                                   else
    if cs1 and cs2 then sb:=cons(e1=-e1, sb);

  >>;
  if !*rational_bak then algebraic(on rational);
  return if sb={} then nil else sb
end$ % of absorbconst

algebraic procedure drop_const(oldsoln, vars, additive)$
COMMENT
  oldsoln is the output of a CRACK call. In all solutions functions
  which are independent of all elements of vars are dropped from
  the list of free functions/constants and
  - set to zero if additive=t and they are additive or
  - set to 1 if additive=nil and they are multiplicative;

begin
  scalar soln, sl, fncn, h1, h2, newfl, vcopy, constnt, v, fcopy,f1,co,
         mcdold;
  soln := {};
  mcdold:=lisp !*mcd$
  off mcd;
  while oldsoln neq {} do <<
    sl := first oldsoln; oldsoln := rest oldsoln;
    fncn := second sl;
    h1 := third sl;
    newfl:={};
    for each h2 in h1 do <<
	      % is h2 constant ?
      vcopy := vars;
      constnt := t;
      while constnt and (vcopy neq {}) do <<
	v := first vcopy; vcopy := rest vcopy;
	if not my_freeof(co,v) then constnt := nil
      >>;
      if constnt then
      if (not my_freeof(first sl, h2)) or my_freeof(fncn, h2)
      then constnt := nil;
      if constnt then <<
	  % is the coefficient of h2 constant in all solved expressions
	  % and occurs h2 only linear ?
	fcopy := fncn;
	while constnt and (fcopy neq {}) do <<
	  f1 := rhs first fcopy; fcopy := rest fcopy;
          on mcd;
	  co:=coeffn(f1,h2,1);
	  if (not my_freeof(co,h2))                               or
	     (     additive  and (not my_freeof(f1 - co*h2, h2))) or
	     ((not additive) and ((f1 - co*h2) neq 0))
	  then constnt := nil;
          off mcd;
	  if constnt and additive then <<
	    vcopy := vars;
	    while constnt and (vcopy neq {}) do <<
	      v := first vcopy; vcopy := rest vcopy;
	      if not my_freeof(co,v) then constnt := nil
	    >>
	  >>
	>>
      >>;
      if constnt then if additive then fncn := sub(h2=0, fncn)
				  else fncn := sub(h2=1, fncn)
		 else newfl := cons(h2, newfl)
    >>;
    soln := cons({first sl, fncn, newfl}, soln)
  >>;
  if mcdold then on mcd;
  return soln
end$ % of drop_const

COMMENT
 The following are routines to help finding bugs. 
 Advantages and disadvantages of current routines:

 solution_check1: 
 it uses from the special external solution all assignments in
 equation form and is thus very general but also very slow.
                
 solution_check2: 
 checks whether the substitutions of the special solution 
 contradict inequalities. --> fast but limited in scope

 solution_check3:
 It only does substitutions based on assignments of the special
 solution in the current equations and in the current forg. --> fast
 but the special solution must express the current ftem_ in the
 assignments which will not work for testing all steps in a computation
 as ftem_ changes.
$

algebraic procedure sol_define1$
begin scalar a,b,assi$
  % This procedure contains the statements that specify a solution
  %
  %  %======= Example 1: Test whether s=hhh-y**2/t**2,  u=y/t 
  %  %                   is a solution where hhh=h(t) 
  %
  %  depend hhh,t$
  %  % returned is a list of 
  %  % - a list of vanishing expressions defining the solution to be tested, 
  %  % - a list of free constants, functions which can have any value except
  %  %   not a number of values excluded by inequalities
  %  %   for example:
  %  return {{u-(c_7-c_8*y**2/t**2),v-c_9*y/t},{c_7,c_8,c_9}}
  % 
  %  %======= Example 2: The solution is given in a file
  %
  %  in "so113-18-Nov-1.1.1.1.1.1.1.1."$
  %  return lisp <<
  %    % backup_:='(
  %    % - A list of dependencies: ((f x y) (g x))
  %    % - A list of unsolved equations:  ((plus (expt a11 2) ..) .. )
  %    % - A list of assignments:  ((equal r5232 0) ...)
  %    % - A list of free or unresolved functions:  (r546 r552 ...)
  %    % - A list of non-vanishing expressions
  %    % - A list of lists of which at least one element is non-vanishing
  %    %             but each element is represented as a list of factors
  %    %             all of which must not vanish (((a b c) (a c d))..)
  %    %           )
  %
  %    for each a in car backup_ do
  %    for each b in cdr a do
  %    algebraic(depend(lisp(car a),lisp b));
  %
  %    a:=cdr backup_;  backup_:=nil$  % to free space
  %    {'LIST,
  %     cons('LIST,
  %          append(car a,for each assi in cadr a 
  %	                  collect {'DIFFERENCE,caddr assi,cadr assi})),
  %     cons('LIST, caddr a)}
  %  >>
end$

symbolic procedure solution_check1(arglist)$
% arglist=(pdes,forg,vl_,pdes)

% This procedure tests whether a solution that is defined in
% an external procedure sol_define1() is still contained in the
% general solution of the currend system under investigation
% This procedure is useful to find an error in the computation
% where the system becomes suddenly more restrictive,
% The input is an algebraic list {A,B} of two algebraic lists A, B.
% A is a list of expressions that vanish and define the solution
%   (unsolved equations and expressions u-v that stand for assignments
%   u=v).
% B is a list of free parameters in the solution, i.e. the solution is
%   included in the current system if it is included for arbitrary
%   values of the free parameters up to a finite number of forbidden
%   values.)

begin scalar pdes,forg,a,fsub,solu,l1,l2,batch_bak,session_bak,
             proc_list_bak,print_bak,old_history_bak,batchcount_bak,
             stepcounter_bak,repeat_mode_bak,print_bak,freef$

 pdes:=car arglist$
 forg:=cadr arglist$
 batch_bak:=!*batch_mode$
 !*batch_mode:=batch_mode_sub$

 backup_to_file(pdes,forg,nil)$  % with all pdes deleted
 solu:=algebraic sol_define1()$
 freef:=cdr reval caddr solu;
 solu:=cadr solu;
 if null solu then return <<
  !*batch_mode:=batch_bak$
  print_:=print_bak$
  write"##### Before calling this module a solution must be read"$terpri()$
  write"##### into the procedure sol_define1. Please have a look"$terpri()$
  write"##### at this procedure in file crsimpso.red ."$terpri()$
  nil
 >>$

 forg:=sub_fsub_in_itself_and_in_forg forg$
 for each a in forg do
 if (pairp a) and (car a='equal) then 
 fsub:=cons({'equal,cadr a,{'!*sq,caddr a,t}},fsub)$

 if fsub then solu:=algebraic(sub(lisp cons('list,fsub),solu))$
 print_bak:=print_$
 if null !*batch_mode then print_:=8
                      else print_:=nil$
 session_bak:=session_$
 session_:=nil$ % to prevent interference with solutions and the casetree
                % in start_level
 start_level(1,list "Check whether a solution is contained.")$
 if print_ then <<
   terpri()$write "CRACK is now called to check whether a given"$
   terpri()$write "solution is included in the current system."
 >>;
 % further necessary step to call crackmain():
 recycle_fcts:=nil$  % such that functions generated in the sub-call 
                     % will not clash with existing functions
 % solu should be in {LIST,!*SQ-form,...} but to make sure it is
 % evaluated with aeval again
 solu:=for each l1 in cdr aeval solu collect
       if pairp l1 and (car l1='!*sq) then cadr l1
                                      else simp l1$
 ftem_:=setdiff(ftem_,freef)$
 a:=ftem_;
 for each l1 in forg do
 if not atom l1 then for each l2 in get(cadr l1,'fcts) do
                     if freeof(a,l2) and 
                        freeof(freef,l2) then a:=fctinsert(l2,a) 
                                         else                 
                else if freeof(a,l1) and
                        freeof(freef,l1) then a:=fctinsert(l1,a)$
 if freef then <<
  a:=setdiff(a,freef)$
  for each l1 in pdes do solu:=cons(get(l1,'sqval),solu)$
  pdes:=nil$
  pdes:=mkeqsqlist(solu,nil,nil,a,vl_,allflags_,t,list(0),pdes)$
 >>       else  
 pdes:=append(mkeqsqlist(solu,nil,nil,a,vl_,allflags_,t,list(0),pdes),pdes)$
 print_more:=nil$
 proc_list_:=delete('solution_check1,proc_list_);
 % It must be possible to specify the modules to be used with cp in order
 % to guarantee the correct computation
 proc_list_bak:=proc_list_$
 proc_list_:=default_proc_list_$
 if contradiction_ then <<level_:=cdr level_; l1:=nil>>
                   else <<
  old_history_bak:=old_history$ old_history:=nil$
  batchcount_bak:=batchcount_$ batchcount_:=-1$
  stepcounter_bak:=stepcounter_$ stepcounter_:=0$
  repeat_mode_bak:=repeat_mode$ repeat_mode:=nil$
  l1:=crackmain(pdes,forg)$
  old_history:=old_history_bak$
  batchcount_:=batchcount_bak$
  stepcounter_:=stepcounter_bak$
  repeat_mode:=repeat_mode_bak
 >>$
 session_:=session_bak$
 proc_list_:=proc_list_bak;
 print_:=print_bak$
 if l1 and not contradiction_ then write"+++++ Solution IS included."
                              else write"+++++ Solution is NOT included."$
 terpri()$
 contradiction_:=nil$ 
 session_:=session_bak$ % to restore the right session
 l1:=restore_backup_from_file(pdes,forg,nil)$
 % not needed: pdes:=car l1;  forg:=cadr l1;
 delete_backup()$
 !*batch_mode:=batch_bak
end$

algebraic procedure sol_define2$
% This procedure returns a substitution list which is to be used
% in solution_check2() to check whether it violates an inequality   
% The computation can be speeded up by making hsub global and
% calling this procedure only once initially.
begin 
% scalar hsub$
% return
% lisp <<
%  in "so28--9-Jul-2004-2.3.2."$
%  hsub:=nil$
%
%  for each h in caddr backup_ do 
%  if not freeof('(a11 a12 a13 a22 a23 a33 
%                  b11 b12 b13 b21 b22 b23 b31 b32 b33  
%                  c11 c12 c13 c22 c23 c33 n1 n2 n3 m1 m2 m3),cadr h) then 
%  hsub:=cons(h,hsub)$
%  cons('LIST,hsub)
% >>
end$

symbolic procedure solution_check2(arglist)$
% arglist=(pdes,forg,vl_,pdes)

% This procedure tests whether a solution that is defined in
% an external procedure sol_define2() is a solution of the 
% currend system under investigation by checking whether
% it violates the inequalities or not. This procedure is useful
% if CRACK looses an inequality and finds a solution which violates
% the lost inequality and the aim is to find when is it lost, or if
% extra wrong inequalities are generated and a valid solution is lost
% which is known to exist.The problem with this test is that ineq_ and
% ineq_or are formulated in terms of ftem_ whereas the special
% solution not.
%
begin scalar g,h,k,p,ineq_cp,hsub$
 g:=cadr arglist$ % just to suppress compiler warning
 hsub:=algebraic sol_define2()$
 if null hsub then return <<
  write"##### Before calling this module a solution must be read"$terpri()$
  write"##### into the procedure sol_define2. Please have a look"$terpri()$
  write"##### at this procedure in file crsimpso.red ."$terpri()$
  nil
 >>$
 ineq_cp:=ineq_$
 while ineq_cp and 
       not zerop(h:=algebraic(sub(hsub,lisp {'!*sq,car ineq_cp,t}))) do 
 ineq_cp:=cdr ineq_cp$
 if null ineq_cp then <<
  ineq_cp:=ineq_or$
  while ineq_cp and <<
   g:=car ineq_cp;   % g is a list of which at least one factor list
                     % must not vanish
   while g and 
         zerop (h:=algebraic(sub(hsub,lisp <<
           % car g is a factor list, we multiply all SQ-form factors
           p:=caar g;
           for each k in cdar g do p:=multsq(p,k);
           {'!*sq,p,t}
         >> ))) do g:=cdr g$
   g
  >> do ineq_cp:=cdr ineq_cp$
 >>$
 if null ineq_cp then 
 write".......... No inequality was violated. ............" else <<
  write"########## At least one inequality was violated: "$
  mathprint                    % car ineq_cp is a single or-inequality
  cons('list,for each g in car ineq_cp collect   % g is a factor list
      cons('list,for each k in g collect {'!*sq,k,t})) % k is a factor
 >>$
 terpri()$
end$

algebraic procedure sol_define3$
begin scalar a,b,c,h$
  % This procedure returns a list of two lists:
  % - an algebraic list of remaining conditions
  % - an algebraic list of assignments
  %
  %  %======= Example: The solution is given in a file
  %
  %  in "so113-18-Nov-1.1.1.1.1.1.1.1."$
  %  return lisp <<
  %    % backup_:='(
  %    % - A list of dependencies: ((f x y) (g x))
  %    % - A list of unsolved equations:  ((plus (expt a11 2) ..) .. )
  %    % - A list of assignments:  ((equal r5232 0) ...)
  %    % - A list of free or unresolved functions:  (r546 r552 ...)
  %    % - A list of non-vanishing expressions
  %    % - A list of lists of which at least one element is non-vanishing
  %    %             but each element is represented as a list of factors
  %    %             all of which must not vanish (((a b c) (a c d))..)
  %    %           )
  %
  %    for each a in car backup_ do
  %    for each b in cdr a do
  %    algebraic(depend(lisp(car a),lisp b));
  %    h:=cdr backup_;   backup_:=nil;   % to free space
  %
  %    {'LIST,cons('LIST,car h),cons('LIST,cadr h)}

  %  >>
end$

symbolic procedure solution_check3(arglist)$
% arglist=(pdes,forg,vl_,pdes)

% This procedure tests whether a solution that is defined in
% an external procedure sol_define3() is a solution of the 
% currend system under investigation.
% This procedure is useful to find an error in the computation
% where the system becomes suddenly less restrictive and allows
% more (wrong) solutions.
% The difference to solution_check1 is that in solution_check1
% it is checked whether at least something of the solution in
% sol_define1 survives whether in solution_check3 it is checked
% whether all of sol_define3 is a solution. (With 'all'/'something'
% we mean all/some of the free parameters of the solution defined
% in sol_define.
% solution_check3 performs substitutions directly, so that will
% only work in a system which does not have substitutions done yet. 

begin scalar solu,a,b,p,f,h,cpa$

 % the solution to be tested
 solu:=algebraic sol_define3()$
 if null solu then return <<
  write"##### Before calling this module a solution must be read"$terpri()$
  write"##### into the procedure sol_define3. Please have a look"$terpri()$
  write"##### at this procedure in file crsimpso.red ."$terpri()$
  nil
 >>$
 % solu is an algebraic list of
 % - an algebraic list of remaining conditions
 % - an algebraic list of assignments
 a:=caddr solu$ % a is algebraic list of assignments of solu
 b:=cdadr solu$ % b is a lisp list of remaining equations of solu
 solu:=nil;

 % test all pdes
 for each p in car arglist do <<                    
  h:=algebraic (sub(lisp a,lisp {'!*sq,get(p,'sqval),t}))$   
  % This will be tested later due to lack of time now and because
  % there are no remaining equations in the solution to be used now.
  % if not zerop h and b then ; % reduce h moulo b
  if null h or not zerop h then 
  <<write"***** Equation ",p," is violated! *****"$terpri()$
    algebraic write "0 = ",lisp h>>$
 >>$

 % collect all relations due to forg
 for each f in cadr arglist do 
 if pairp f then <<
  if denr caddr f = 1 then  
  % to speedup, we only substitute one bye one if the denominator is not 1
  h:=algebraic (sub(lisp a,lisp {'!*sq,subtrsq(caddr f,simp cadr f),t}))
                      else <<
   h:={'!*sq,subtrsq(caddr f,simp cadr f),t}$
   cpa:=cdr a$ 
   while cpa and 
         (h:=err_catch_sub(cadar cpa,caddar cpa,h)) do cpa:=cdr cpa$
  >>$
  % This will be tested later due to lack of time now and because
  % there are no remaining equations in the solution to be used now.
  % if not zerop h and b then ; % reduce h moulo b
  if null h or not zerop h then 
  <<write"***** Function ",cadr f," value is contradicted! *****"$
    terpri()>>$
 >>$
end$

endmodule$

end$
