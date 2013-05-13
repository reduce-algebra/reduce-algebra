%********************************************************************
module inequalities$
%********************************************************************
%  Routines for updating inequalities
%  Author: Thomas Wolf since 1996, rewrite 2006 for SQ-form

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

symbolic procedure simplifySQ(p,ftem,fctr,en,sepa)$ 
%
% - p is a standard quotient which is simplified so that the 
%   new expression=0 iff p=0, so p can be an equation or an inequality.
% - *** important ***: if p is an equation p=0 then check whether
%   list simp 1={(1 . 1)} is returned, in this case set contradiction_:=t
% - The procedure tries simple factorization iff fctr=t.
% - returns always a list of factors, each in SQ form, even if there is only one
% - uses ineq_ but does not change it
% - If p is an equation p=0 and en<>nil then en is the name of the 
%   equation p=0 for which the history will be updated (unless p<>0, 
%   i.e. contradiction).
% - If p is an expression which is to be tested whether it can become zero,
%   i.e. if p is an inequality (i.e. en=nil) then if sepa=t then p is tested 
%   for separability. If sepa=t then only binary outcome should be of interest, 
%   i.e. whether result is {(1 . 1)} or not.
%
begin scalar enhi,si,sf,s,print_bak; 
 if en and record_hist then enhi:=get(en,'histry_)$

 return
 if not p or sqzerop p then list simp 0 else 
 if not pairp p then 
 if freeof(ftem,p) then list simp 1   % contradiction if p is an equation
                   else list simp p else
 if denr p neq 1 then <<              % drop non-zero denominator
  if enhi then put(en,'histry_,{'TIMES,enhi,prepf denr p});
  simplifySQ((numr p . 1),ftem,fctr,en,sepa) 
 >>              else 
 if minusf numr p then <<             % drop leading minus
  if enhi then put(en,'histry_,{'MINUS,enhi});
  simplifySQ(negsq p,ftem,fctr,en,sepa)
 >>               else
 if freeoflist(p,ftem) or 
    member(p,ineq_) then list simp 1  % contradiction if p is an equation
                    else 
 if (null red numr p) and         % no other terms
    (1 = lc numr p) then          % leading coefficient = 1

  if 1 neq ldeg numr p then <<    % leading degree (integer>0) neq 1
   if enhi then put(en,'histry_,{'EXPT,enhi,{'QUOTIENT,1,ldeg numr p}});
   simplifySQ(mksq(mvar numr p,1),ftem,fctr,en,sepa)
  >>		       else 
  if not pairp mvar numr p then list p % p = an element of ftem as SQ 
                           else        % i.e. no value change

  if car mvar numr p = 'EXPT then
  if freeoflist(caddr mvar numr p,ftem) then <<  % drop constant exponents
   if enhi then put(en,'histry_,{'EXPT,enhi,{'QUOTIENT,1,caddr mvar numr p}});
   simplifySQ(simp cadr mvar numr p,ftem,fctr,en,sepa) 
  >>                                    else     % drop term is base is const
  if freeoflist(cadr mvar numr p,ftem) then list simp 1
                                       else list p
                             else 
  if (car mvar numr p = 'LOG) or 
     (car mvar numr p = 'LN)    then <<
   if enhi then put(en,'histry_,reval {'PLUS,{'EXPT,'E,enhi},-1});
   simplifySQ(simp {'DIFFERENCE,cadr mvar numr p,1},ftem,fctr,en,sepa) 
  >>                            else 
  if (car mvar numr p = 'LOG10) then <<
   if enhi then put(en,'histry_,reval {'PLUS,{'EXPT,10,enhi},-1});   
   simplifySQ(simp {'DIFFERENCE,cadr mvar numr p,1},ftem,fctr,en,sepa) 
  >>                            else list p % unknown, like sin(f)

                    else <<

  % factorization is tried first, then separability 
  if null fctr then sf:=list p
	       else <<      % factorize 
   if more_than_x_terms(numr p,if !*complex then max_term_to_fac_complex
                                            else max_term_to_fac_real   ) 
   then si:=sffac numr p
   else <<
    s:=cdr err_catch_fac2 {'!*SQ,(numr p . 1),t};
    if null s or
       (null !*complex and
        ((not freeof(s,'i)) or (not freeof(s,'!:gi!:)))) then si:=nil
                                                         else while s do <<
     sf:=simp cadar s;
     if enhi and denr sf neq 1 then <<
      write"##### Unexpectedly a denominator is not =1 . As a consequence"$
      terpri()$
      write"      the histry_ value of equation ",en," will be wrong. #####"$
      terpri()
     >>$
     sf:=numr sf$
     for n:=1:(caddar s) do si:=cons(sf,si);  
     % We consider all factors, even numbers. 
     % works if cadar s={'!*SQ,..} or =integer
     s:=cdr s
    >>
   >>;

   if null si then sf:=list p
	      else <<       % sf (will be a list of SQ) is still nil
    sf:=nil;
    while si do <<
     % We want to simplify car si but not to factorize it again, and the 
     % update of history is to be done in this routine, not the subcall.
     % so we call simplifySQ(..,nil,nil,sepa).
     s:=simplifySQ((car si . 1),ftem,nil,nil,sepa); % s is a list with 1 element
                                                   % as called with fctr=nil
     if car s = (1 . 1) then 
     if enhi then put(en,'histry_,{'QUOTIENT,get(en,'histry_),prepf car si}) else
	 	        else
     if sqzerop car s then <<sf:=list simp 0; si:=list nil>> % cannot happen(?)
	 	      else 
     if member(car s,sf) then % drop this multiple factor
     if enhi then put(en,'histry_,{'QUOTIENT,get(en,'histry_),prepf car si}) 
	     else              else <<
      if enhi and (car s neq (car si . 1)) then 
      put(en,'histry_,reval {'TIMES,{'QUOTIENT,get(en,'histry_),prepf car si},
                             prepf caar s});
      sf:=cons(car s,sf)
     >>;
     si:=cdr si
    >>;
    if null sf then sf:={(1 . 1)} % because all factors are = (1 . 1), ie. <> 0
   >>
  >>;  % end of factorization try

  % sf is now a list of simplified factors, each in SQ form
  if sepa and vl_       % no separability possible if vl_=nil
          and null fctr % otherwise separability already tested in sub-call
          and (sf neq {(0 . 1)}) % otherwise p=0
          and (sf neq {(1 . 1)}) % otherwise p known to be non-zero
          and (red numr car sf)  % car sf has more than one term
          and <<si:=kernels numr car sf; % car si has purely explicit indep var.
                setdiff(smemberl(vl_,si),argset smemberl(ftem,si))>>
  then <<                        % try for separability now
   print_bak:=print_; print_:=nil;
   % sf is only changed to {(1 . 1)} or not at all
   si:=separ(reval {'!*SQ,car sf,nil},ftem,vl_,nil,nil);% nonrat=nil, ie. no cases
   if cdr si then                              % otherwise no splitting occured
   while si do % si is a list of pairs (explicit_x_dep_factor . x_indep_factor)
   if {(1 . 1)}=simplifySQ(simp cdar si,ftem,t,nil,nil) then 
   <<si:=nil; sf:={(1 . 1)}>>                           else si:=cdr si;
   print_:=print_bak
  >>;

  sf
 >>
end$

%------------------------------- 

symbolic procedure simplifypdeSQ(p,ftem,fctr,en,sepa)$ 
% expects p to represent an equation p=0, p is in standard quotient form,
% returns r with: 
%     car r = the simplified expression in standard quotient form
%     cdr r = / 1 if no nontrivial factors
%             \ lisp list of non-trivial factors in SQ-form, 
%             i.e. cdr r can be assigned to the 'fac property of equations
% 
% and assigns contradiction_:=t if p is known to be non-zero.
% This is done by multiplying the factors returned by simplifySQ.
begin scalar l$
 l:=simplifySQ(subs2 p,ftem,fctr,en,sepa)$
 return
 if l={(1 . 1)} then <<contradiction_:=t; (car l . 1)>>
                     % raise_contradiction({'!*sq,p,t},nil)$ % with print
                else 
 if null cdr l then (car l . 1) % no non-trivial factors
               else <<
  p:=car l$ 
  for each h in cdr l do p:=multsq(p,h);
  cons(p,l)
 >>
end$

%-------------------------------

symbolic procedure can_not_become_zeroSQ(p,ftem)$ 
if simplifySQ(p,ftem,t,nil,t)={(1 . 1)} then t
                                        else nil$

%-------------------------------

symbolic procedure add_to_ineq_or(new_or,ineq_or_tmp)$
begin scalar iocp$
 iocp:=ineq_or_tmp$
 while iocp do 
 % Is the non-vanishing of all elements of car iocp less or equally 
 % restrictive than the non-vanishing of new_or? Then new_or is obsolete.
 if null not_included(car iocp,new_or) then <<new_or:=nil; iocp:=nil>>
                                       else <<
  % Is the non-vanishing of all elements of new_or less restrictive than
  % the non-vanishing of all elements of car iocp? Then car iocp is obsolete.
  if null not_included(new_or,car iocp) then delete(car iocp,ineq_or_tmp);
  iocp:=cdr iocp
 >>$
 if new_or then ineq_or_tmp:=cons(new_or,ineq_or_tmp)$
 return ineq_or_tmp
end$

%-------------------------------

symbolic procedure simpSQineq_or_adhoc(pdes)$  
% ineq_or is a list of lists of expressions, not factorized yet
% they will be factorized and non-zero factors dropped,...

begin scalar l1,l1cp,l2,l2cp,l3,icp,keep_l1,new_scalar_ineq,is_zero;

 icp:=ineq_or; ineq_or:=nil;

 while icp do <<
  l1:=car icp; icp:=cdr icp;
  % l1 is a single or-inequality, ie a list of expressions, at least one of 
  % which must be <>0
  
  keep_l1:=t;
  l1cp:=l1; 
  l1:=nil$ % new 26.2.2011
  while l1cp do <<
   l2:=car l1cp; l1cp:=cdr l1cp;
   % l2 is one potentially vanishing expression of the list l1cp
   l2cp:=nil; % l2cp becomes a list of factors of l2
   is_zero:=nil;
   for each l3 in l2 do <<
    l3:=simplifySQ(l3,ftem_,t,nil,t);
    if l3 = {(nil . 1)} then is_zero:=t$             % l3 = 0
    if l3 neq {(1 . 1)} then l2cp:=union(l3,l2cp)    % l3 = 1
   >>$

%   if is_zero then l1:=delete(l2,l1) % i.e. l2 is not one of the elements of l1
%                                     % that could become a non-zero product
%              else
   if null is_zero then % new 26.2.2011
   if null l2cp then <<keep_l1:=nil;l1cp:=nil>> % ie all factors of l2 are known
   % to be non-zero, i.e. at least one element of l1 is known to be non-zero, 
   % i.e. l1 is redundand, i.e. keep_l1:=nil
                else 
%  new 26.2.2011 to comment out:
%  if l2cp neq l2 then         
   l1:=add_to_ineq_or(l2cp,l1) % The potentially non-vanishing expression 
  >>; 

  if keep_l1 then % otherwise at least one non-zero element of l1 (i.e.
                  % product of factors of an element of l1) is known
  if null l1 then contradiction_:=t % i.e. all or-expressions vanish
             else
  if null cdr l1 then new_scalar_ineq:=union(car l1,new_scalar_ineq) 
  % car l1 is the new non-vanishing expression which is a list of factors each 
  % of which must not vanish --> union(car l1,..) and not union({car l1},..)
                 else ineq_or:=cons(l1,ineq_or)
 >>;
 if null contradiction_ then 
 for each l2 in new_scalar_ineq do % pdes:= %<=<=<=<=
 addSQineq(pdes,l2,nil)  

 % return pdes  %<=<=<=<=
end$

%-------------------------------

symbolic procedure simpSQineq_or(pdes,newin)$  
% newin is a new (scalar) already simplified inequality which is used
% to simplify ineq_or, simply by checking whether factors can be dropped
% in factor lists of expression lists in each single or-inequality

begin scalar l1,l1cp,l2,l2cp,l3,icp,keep_l1,new_scalar_ineq;

 icp:=ineq_or; ineq_or:=nil;

 while icp do <<
  l1:=car icp; icp:=cdr icp;
  % l1 is a single or-inequality, ie a list of expressions, at least one of 
  % which must be <>0
  
  keep_l1:=t;
  l1cp:=l1;
  while l1cp do <<
   l2:=car l1cp; l1cp:=cdr l1cp;
   % l2 is a list of factors corresponding to one expression in the ineq_or 
   % list l1cp. newin can not be a product as otherwise each factor would be 
   % a newin. If newin is a factor of l2 (i.e. an element of l2) then this 
   % factor should be dropped from l2
   
   l2cp:=l2; 
   for each l3 in l2 do 
   if newin=l3 then l2cp:=delete(l3,l2cp); 
 
   if null l2cp then <<keep_l1:=nil;l1cp:=nil>> %ie all factors of l2 are known
   % to be non-zero, i.e. at least one element of l1 is known to be non-zero, 
   % i.e. l1 is redundand, i.e. keep_l1:=nil
                else 
   % old: if l2cp neq l2 then l1:=union({l2cp},delete(l2,l1)) 
   if l2cp neq l2 then         % The potentially non-vanishing expression 
   l1:=add_to_ineq_or(l2cp,l1) % (i.e. the list of factors) has changed.
  >>; 
 
  % The number of expressions in an OR-list can be reduced if some expressions 
  % become equal and are dropped (the case that one of the expressions of an
  % or-inequality is dropped because it is zero occurs only if new equations
  % are known, not like here when new in-equalities are known).
  if keep_l1 then 
  if null cdr l1 then new_scalar_ineq:=union(car l1,new_scalar_ineq) 
  % car l1 is the new non-vanishing expression which is a list of factors each 
  % of which must not vanish --> union(car l1,..) and not union({car l1},..)
                 else ineq_or:=cons(l1,ineq_or)
 >>;
 for each l2 in new_scalar_ineq do % pdes:=  %<=<=<=<=
 addSQineq(pdes,l2,nil);  

 % return pdes  %<=<=<=<=
end$

%-------------------------------

symbolic procedure all_sub_derivatives(a)$
% a has the form {'DF,f,x,...}
% returns a (lisp) list of all derivatives of f of lower order including f
if null cddr a then list cadr a else 
begin
 scalar f,x,n,dl,dldone,all_deri;
 f:=cadr a$
 dl:=cddr a$

 while dl do <<
  x:=car dl; dl:=cdr dl;
  if null dl then n:=1 else 
  if fixp car dl then <<n:=car dl$ dl:=cdr dl>>
                 else n:=1$
  all_deri:=union(all_sub_derivatives cons('DF,cons(f,append(dldone,
		  if n=1 then dl else
		  if n=2 then cons(x,dl)
			 else cons(x,cons(sub1 n,dl))      ))),
                  all_deri)$
  if n=1 then dldone:=nconc(dldone,{x})
         else dldone:=nconc(dldone,{x,n})
 >>;

 return cons(a,all_deri)

end$

%-------------------------------

symbolic procedure checkcase2sep(pdes,newinesq)$
begin scalar h,p$
 for each p in pdes do
 if newinesq=get(p,'case2sep) then <<
  put(p,'case2sep,nil);
  h:=stardep3(get(p,'vars),get(p,'kern),get(p,'derivs))$
  if h then <<
   put(p,'starde,({car h} . 0))$
   flag1(p,'to_sep)
  >>
 >>
end$

%-------------------------------

symbolic procedure addSQineq(pdes,newineq,simpli)$
begin scalar h1,h2,h3,p,q$
 % - adds newineq as new inequality and simplifies it iff simpli=t
 % - it can be assumed that none of the expressions of ineq_ factorize
 %   as they have already been factorized
 % - may change contradiction_
 if simpli then h1:=simplifySQ(newineq,ftem_,t,nil,t) % h1 is a list of factors
           else h1:=list newineq$
 % trivial cases:
 if null cdr h1 then % just one factor
 if car h1=(1 . 1) then return nil else
 if sqzerop car h1 then return <<
  if print_ then <<
   write"Added inequality is actually zero --> contradiction"$
   terpri()
  >>$
  contradiction_:=t;
  nil
 >>$
 
 % If a high order derivative is non-zero then all corresponding lower order
 % derivatives must be non-zero and are added to h1.
 h3:=nil;
 if vl_ then
 for each h2 in h1 do 
 if (one_termpSF numr h2) and (lc numr h2 = 1) then <<
  checkcase2sep(pdes,h2)$
  if pairp mvar numr h2 and
     car mvar numr h2='DF then h3:=union(cdr all_sub_derivatives mvar numr h2,h3)$
 >>$
 for each h2 in h3 do <<
  h2:=mksq(h2,1);
  % Check all pdes whether h2 is their case2sep value
  checkcase2sep(pdes,h2)$
  h1:=cons(h2,h1);
 >>$

 h3:=nil;
 for each h2 in h1 do 
 if not member(h2,ineq_) then <<h3:=cons(h2,h3);ineq_:=cons(h2,ineq_)>>$

 if print_ and h3 then <<
  terpri()$ % was commended out but is needed, e.g. after: new constant: ...
  write"The list of inequalities got extended by: "$ 
  for each h2 in h3 do
  if delengthSQ h2 > print_ then <<terpri()$
   write "An expression with ",no_of_terms h2," terms"$ terpri()
  >>                        else mathprint {'!*SQ,h2,t}
 >>$

 if pdes then for each h2 in h3 do % pdes:=  %<=<=<=<=
 updateSQfcteval(pdes,h2); 

 if pdes and null lin_problem then
 for each h2 in h3 do
 if no_number_atom_SQ h2 and member((h1:=mvar numr h2),ftem_) then <<

  % h3 is the list of all new non-zero expressions
  % if any one of these expressions is an element of ftem_ then it
  % should get a low priority in the lexicographical ordering for
  % non-linear problems
  % h2 gets a low priority so that it is eliminated late in decoupling
  % to be available as non-zero coefficient as long as possible to
  % allow substitutions of other functions without case-distinctions:

  give_low_priority(pdes,h1);  

  for each p in pdes do 
  if not get(p,'linear_) and 
     not freeof(get(p,'fcts),h1) then <<

   % The question whether 2 equations (at least one of which non_linear)
   % can be shortened with each other does depend on which ftem_ are
   % known to be non-zero. So if a new ftem_ function is known to be non-zero
   % then all non-linear equations should be dropped from all rl_with lists
   % which involve this function:
   % only if p is non-linear other equations have to be multiplied with h1:

   put(p,'rl_with,nil);
   for each q in pdes do if q neq p then drop_rl_with(p,q)$

   % Collecting new inequalities from special equations
   % For all elements in h3 which are atoms (kernels) find all 
   % non-linear inhomogeneous non-factorizable equations with only
   % 2 functions and hom_deg = (0 . ?) of which the element of h3
   % is one of the 2 functions. Then the other one is non-zero as well.

   q:=get(p,'fct_hom);
   if (length q=2) and (fixp get(p,'fac)) and  
      (length get(p,'fcts)=2) and  % <-- in case fhom_ neq ftem_
      (car get(p,'hom_deg)=0) then 
   if h1=car q then addSQineq(pdes,simp cadr q,nil) else % h1=cadr q (see above test)
                    addSQineq(pdes,simp car  q,nil)
  >>

 >>$

 % Collecting new inequalities from special equations

 % If one term of the equation is non-zero then the sum of the 
 % remaining terms has to be non-zero too
 if h3 and pdes then for each h2 in pdes do 
 if get(h2,'terms)=2 then new_ineq_from_equ_SQ(h2,pdes)$ 

 % Update ineq_or
 if ineq_or then
 for each h2 in h3 do simpSQineq_or(pdes,h2)

 % return pdes %<=<=<=<=
end$

%-------------------------------

symbolic procedure simp_ineq_with_pdes(a1,avoid,pdes)$
% This simplifies and returns a list a1 which is the result of a call 
% to simplifySQ(). avoid is a function name that should not enter a1
% 
if a1 then
if sqzerop car a1 then list car a1  % full contradiction, checked outside
                  else 
begin scalar a,a2,occur,p,k,fns,kernellist,akernels,ftem_cp,ok,ak$

 % so far only limited further reduction:
 for each a in a1 do 
 if (fhom_ and % i.e. not a fully linear problem
     not freeoflist(a,flin_)) or % not further reduced now in order
                                 % not to make linear functions non-linear
    more_than_x_terms(numr a,max_term_to_pred) or 
                                 % otherwise preduce too slow
    (null alg_poly and 
     <<akernels:=kernels numr a;
       ok:=t;
       for each ak in akernels do 
       if ok then << % to shortcut if not ok
        ftem_cp:=ftem_;
        while ftem_cp and ( freeof(ak,car ftem_cp) or 
                           polynop(ak,car ftem_cp)    ) do 
        ftem_cp:=cdr ftem_cp;
        if ftem_cp then ok:=nil
       >>;
       if ok then nil
	     else t
     >>) 
 then a2:=cons(a,a2) 
 else <<
     % collect all equations whose function in their leading term is
     % occuring in a  
  occur:=nil$
  for each p in pdes do 
  if ((null fhom_) or zerop car get(p,'hom_deg)) and 
     (get(p,'terms)<=max_term_to_pred) and % to avoid unlikely simplifications
     null get(p,'starde) and
     null get(p,'nonrational) and
     not freeof(a,caaar get(p,'derivs)) and
     (null avoid or freeof(get(p,'fcts),avoid)) and % not to invert a 
                                 % substitution by bringing in 'avoid'
     freeof(get(p,'kern),'EXPT)  % to avoid: ***** p invalid as 
                                 % distributive polynomial exponent
  then <<
   if not alg_poly then <<
    fns:=get(p,'fcts);
    for each k in get(p,'kern) do 
    if not freeoflist(k,fns) then kernellist:=union({k},kernellist)
   >>$
   occur:=cons({'!*SQ,get(p,'sqval),t},occur)$
  >>$
  if occur then <<
   if alg_poly then algebraic torder(lisp(cons('LIST,ftem_)),lex)
               else <<
    for each k in akernels do
    if not freeoflist(k,ftem_) then kernellist:=union({k},kernellist)$
    algebraic(torder(lisp cons('LIST,kernellist),lex))$
   >>$
   p:=err_catch_preduce({'!*SQ,a,nil},cons('LIST,occur))$
   a2:=if p then append(simplifySQ(simp p,ftem_,t,nil,t),a2)
            else cons(a,a2)
%   a2:=append(simplifySQ(simp algebraic (preduce(lisp {'!*SQ,a,nil},
%                                                 lisp cons('LIST,occur))),
%                         ftem_,t,nil,t),a2)
  >>       else a2:=cons(a,a2)
 >>$
 return a2
end$

%-------------------------------

symbolic procedure simp_ineq_with_equ_SQ(l,eqn,pdes)$
% l is a list of expressions, each of which must not vanish
% eqn is a new equation that should be used to simplify each element of l
% This procedure returns a pair (kept . newin) where kept is a list of 
% remaining unchanged inequalities and newin is the list of new inequalities.
% This is done so that one could ignore kept and add only newin afterwards to 
% ineq_.
%
% Returns: 
% - if contradiction:        (nil . {(0 . 1)}) 
% - if simplification to 1:  (nil .    nil   )
% - else                     (kept . newin)
% no conditions get lost.

% If eqn consists of nothing but a function=0 then do this substitution   
% in all inequalities:                                                    
if (get(eqn,'terms)=1) and                                                
   no_number_atom_SF numr get(eqn,'sqval) then                            
   simp_ineq_with_subst_SQ(l,0,mvar numr get(eqn,'sqval),pdes)      
                                          else                            

%if (get(eqn,'terms) > max_term_to_pred) or
%    not freeof(get(eqn,'kern),'EXPT) % to avoid: ***** p invalid as distributive 
%                                     % polynomial exponent (in preduce)
%then (l . nil)      % already tested in simp_all_ineq_with_equ_SQ
%else 

begin scalar f,a,a1,a2,kept,newin$

 f:=caaar get(eqn,'derivs); 
 while l do <<

  if freeof(car l, f) or 
     (one_termpSF numr car l and
      (2<get(eqn,'terms))        ) or  
     (more_than_x_terms(numr car l,max_term_to_pred) = nil)
  then kept:=cons(car l,kept)
  else <<

   % when the inequality is not just a variable and the function f in
   % the leading term of the equation does appear in the inequality

   a1:=err_catch_preduce({'!*SQ,car l,t},{'LIST,{'!*SQ,get(eqn,'sqval),t}})$
   a1:=simplifySQ(if a1 then simp a1
                        else car l,ftem_,t,nil,t)$
%   a1:=simplifySQ(simp algebraic   % simp needed to convert prefix into sq-form
%      preduce(lisp        {'!*SQ,car l,          t},
%              lisp {'LIST,{'!*SQ,get(eqn,'sqval),t}}),ftem_,t,nil,t)$

   % `a1' is a list of possibly more than one inequality

   if cdr a1 or (car a1 neq (1 . 1)) then % else car l = 1 mod ineq_+eqn
                                          % i.e. car l=(1 . 1) is not kept
   if null cdr a1 and (car a1=car l) then kept:=cons(car l,kept) 
                                     else << % something new resulted
    a2:=simp_ineq_with_pdes(a1,nil,pdes)$
    for each a in a2 do
    if sqzerop a then <<
     if print_ then <<
     terpri()$write "The new equation:"$
      eqprint list('EQUAL,0,{'!*SQ,get(eqn,'sqval),t})$
      write "transformed one factor:"$
      eqprint {'!*SQ,car l,t}$
      write"of one expression within one OR-inequality modulo"$terpri()$ 
      write"all other equations to zero."$terpri()
     >>$
     l:={car l}$
     kept:=nil$
     newin:={(0 . 1)}
    >>         else  
    if a neq (1 . 1) then newin:=cons(a,newin)
   >>;
  >>;
  l:=cdr l
 >>$
  
 return (kept . newin)
end$

%-------------------------------

symbolic procedure simp_all_ineq_with_equ_SQ(eqn,pdes)$
% Use a new equation eqn to reduce all inequalities.
% This procedure is very similar to ineqsubst.
% This procedure can give contradiction_:=t which has to be tested afterwards
% Any new simplified inequalities do not replace old inequalities but they are
% added. Otherwise it can happen that: If more than one equation is generated 
% at a time and one of them clearly contradicts an inequality, but other new 
% equations are used first to simplify inequalities then the contradiction is 
% not recognized anymore and the new contradicting equation is then used for 
% substitutions which can cause 0/0 in forg. 

if alg_poly and                           % new, taken out of body of procedure
   (get(eqn,'terms)<max_term_to_pred) and % otherwise preduce becomes VERY slow
   % (null get(eqn,'nonrational)) and (<-- needed?)
   freeof(get(eqn,'kern),'EXPT) and % to avoid: ***** p invalid as distributive 
                                    % polynomial exponent (in preduce)                                   
   null get(eqn,'starde) and get(eqn,'derivs) then
begin scalar l,l1,l2,a,newor$

 if alg_poly then algebraic torder(lisp(cons('LIST,ftem_)),lex)
             else <<
 >>$

 % at first normal inequalities
 l1:=ineq_;ineq_:=nil; % inequ_ is set temporarily to nil so that inequalities
 % are not simplified to 1 in simplifySQ() in the following simp_ineq_with_subst_SQ()
 l:=simp_ineq_with_equ_SQ(l1,eqn,pdes)$
 if cdr l = {(0 . 1)} then <<ineq_:=l1;contradiction_:=t>> % complete stop of procedure
                      else <<
  ineq_:=car l;
  for each a in cdr l do % pdes:= %<=<=<=<=
  addSQineq(pdes,a,nil)$  

  % now OR-inequalities
  l:=ineq_or; ineq_or:=nil;
  while l do <<
   newor:=nil;    % will be the new single or-inequality
   l1:=car l;     % l1 is one or-inequality
   while l1 do << % all elements of the single or-inequality
    l2:=car l1;   % l2 is a list of factors which all must be non-zero.
    l1:=cdr l1;   
    l2:=simp_ineq_with_equ_SQ(l2,eqn,pdes)$  % Returns: 
				  % - if contradiction:       (nil . {(0 . 1)})
				  % - if simplification to 1: (nil .    nil   )
				  % - else                    (kept . newin)
    if cdr l2 neq {(0 . 1)} then  % otherwise contradiction for this inequality
                                  % --> no action
    if null car l2 and null cdr l2 then % this or-inequality is satisfied
    <<newor:={{(1 . 1)}}; l1:=nil >> else 
    newor:=union({nconc(car l2,cdr l2)},newor)
   >>$
   if null newor then << % all expressions are zero --> contradiction
    if print_ then <<
     terpri()$write "Contradiction: The equation:"$
     eqprint list('EQUAL,0,{'!*SQ,get(eqn,'sqval),t})$
     write "transformed all expressions, each given as a list of factors:"$
     mathprint cons('LIST,for each l1 in car l collect 
               cons('LIST,for each l2 in    l1 collect {'!*SQ,l2,t}))$
     write"within one OR-inequality modulo all other equations to zero."$terpri()
    >>$
    contradiction_:=t;
    l:={nil}
   >>            else
   if null cdr newor then 
   if car newor neq {(1 . 1)} then <<
    if print_ then <<
     terpri()$write"Due to vanishing expressions an OR-inequality is now"$
     terpri()$write"converted to a normal inequality where each of the"$
     terpri()$write"following factors must not vanish: "$
     mathprint cons('LIST,for each l2 in car newor collect {'!*SQ,l2,t})$
    >>$
    for each l2 in car newor do addSQineq(pdes,l2,nil) 
   >>                         else % or-inequality is satisfied
                     else ineq_or:=cons(newor,ineq_or);
   l:=cdr l
  >>
 >>   
end$

%-------------------------------

symbolic procedure new_ineq_from_equ_SQ(equ,pdes)$
% currently only effective for equations with 2 terms
% If one term of the equation is non-zero then the sum of the 
% remaining terms has to be non-zero too
if pdes and 
   null lin_problem and 
   (fixp get(equ,'fac)) then % only if there is no factor that could vanish
if get(equ,'terms)=2 then    % if there are two terms
begin scalar sf,t1,t2;
 sf:=numr get(equ,'sqval)$
 t1:=first_term_SF sf$
 t2:=if red sf then first_term_SF red sf
               else first_term_SF addf(sf,negf t1)$

 t1:=simplifySQ((t1 . 1),get(equ,'fcts),t,nil,nil); 
 t2:=simplifySQ((t2 . 1),get(equ,'fcts),t,nil,nil);
 % Last argument is nil as no separability of a single term.

 if t1  =  {(1 . 1)} then 
 if t2 neq {(1 . 1)} then for each h in t2 do addSQineq(pdes,h,nil) else
                     else 
 if t2  =  {(1 . 1)} then for each h in t1 do addSQineq(pdes,h,nil)
end                  else
if null get(equ,'fct_hom) and  % only if no homogeneous unknowns occur
   (get(equ,'nvars)=0) then    % only for algebraic problems (not necessary)
begin scalar sf,t1,t2,h;
 sf:=numr get(equ,'sqval)$
 t1:=num_term_SF sf$
 if t1 then <<
  t2:=addf(sf,negf t1);
  t2:=simplifySQ((t2 . 1),get(equ,'fcts),t,nil,nil);
  if % t2 neq {(1 . 1)} and
     cdr t2                    % i.e. more than one factor
  then for each h in t2 do 
  if no_of_tm_sf h < 5 then addSQineq(pdes,h,nil)
 >>
end$

%-------------------------------

symbolic procedure simp_ineq_with_subst_SQ(l,new,old,pdes)$
% - l is a list of expressions, each of which must not vanish
%   In calls is either l=ineq_ or l is one non-vanishing list which is
%   element on one or-inequality which is one element of ineq_or
% - old must be a kernel
% - new is either in prefix form or prefixed SQ: {'!*SQ, .. ,t}
% - new --> old is a substitution to be done in l
% This procedure returns a pair (kept . newin) where kept is a list of 
% remaining unchanged inequalities and newin is the list of new inequalities.
% This is done so that one could - if the input parameter l=ineq_ then - 
% afterwards set ineq_:=kept and add only newin afterwards to ineq_. 
%
% Returns: 
% - if contradiction:        (nil . {(0 . 1)}) 
% - if simplification to 1:  (nil .    nil   )
% - else                     (kept . newin)
% no conditions get lost.

begin scalar a,a1,a2,kept,newin$

 while l do <<
  if freeof(car l, old) then kept:=cons(car l,kept)
                        else <<
   a1:=simplifySQ(subsq(car l,{(old . new)}),ftem_,t,nil,t)$
   % a1:=simplifySQ(simp!* {'!*SQ,subsq(car l,{(old . new)}),nil},ftem_,t,nil,t)$  
   % - simp!* {'!*SQ,..,nil} to simplify poly using identities, like i^2 -> -1
   % - `a1' is a list of possibly more than one inequality
   if cdr a1 or (car a1 neq (1 . 1)) then << % something new resulted
                                   % else car l = 1 mod ineq_ + eqn
                                   %      and nothing to be saved 
    a2:=simp_ineq_with_pdes(a1,old,pdes)$
    for each a in a2 do
    if sqzerop a then <<
     if print_ then <<
      terpri()$write "The substitution:"$
      eqprint list('EQUAL,old,new)$
      write "transformed one factor:"$
      eqprint {'!*SQ,car l,t}$
      write"of one expression within one OR-inequality modulo"$terpri()$ 
      write"all other equations to zero."$terpri()
     >>$
     l:={car l}$
     kept:=nil$
     newin:={(0 . 1)}
    >>         else  
    if a neq (1 . 1) then newin:=cons(a,newin)
   >>;
  >>;
  l:=cdr l
 >>$
  
 return (kept . newin)
end$

%-------------------------------

symbolic procedure simp_all_ineq_with_subst_SQ(new,old,pdes)$
% - substitutes old by new in ineq_ and ineq_or
% - old must be a kernel
% - new is either in prefix form or prefixed SQ: {'!*SQ, .. ,t}
% - new --> old is a substitution to be done in l
%

begin scalar l,l1,l2,l3,a,newor$

 if alg_poly then algebraic torder(lisp(cons('LIST,ftem_)),lex)
             else <<
 >>$

 % at first normal inequalities
 l1:=ineq_;ineq_:=nil; % inequ_ is set temporarily to nil so that inequalities
 % are not simplified to 1 in simplifySQ() in the following simp_ineq_with_subst_SQ()
 l:=simp_ineq_with_subst_SQ(l1,new,old,pdes)$
 if cdr l = {(0 . 1)} then <<ineq_:=l1;contradiction_:=t>> % complete stop of procedure
                      else <<
  ineq_:=car l; 
  for each a in cdr l do addSQineq(pdes,a,nil)$

  % now OR-inequalities
  l:=ineq_or; ineq_or:=nil;

  if member(old,flin_) and 
     member(old,fhom_) then l3:={simp old};

  while l do <<
   l1:=car l;     % l1 is one or-inequality
   if l3 and member(l3,l1) then newor:=delete(l3,l1) % new single or-inequality
                           else <<
    newor:=nil;    % will be the new single or-inequality
    while l1 do << % all elements of the single or-inequality
     l2:=car l1;   % l2 is a list of factors which all must be non-zero.
     l1:=cdr l1;   
     l2:=simp_ineq_with_subst_SQ(l2,new,old,pdes)$ % Returns: 
	 		   % - if contradiction:       (nil . {(0 . 1)})
			   % - if simplification to 1: (nil .    nil   )
			   % - else                    (kept . newin)
     if cdr l2 neq {(0 . 1)} then % otherwise contradiction to this inequality
                                  % --> no action
     if null car l2 and null cdr l2 then % this or-inequality is satisfied
     <<newor:={{(1 . 1)}};l1:=nil>> else 
     newor:=add_to_ineq_or(nconc(car l2,cdr l2),newor)
    >>
   >>$

   if null newor then << % all expressions are zero --> contradiction
    if print_ then <<
     terpri()$write "Contradiction: The substitution:"$
     eqprint list('EQUAL,old,new)$
     write "transformed all expressions, each given as a list of factors:"$
     mathprint cons('LIST,for each l1 in car l collect 
               cons('LIST,for each l2 in    l1 collect {'!*SQ,l2,t}))$
     write"within one OR-inequality modulo all other equations to zero."$terpri()
    >>$
    contradiction_:=t;
    l:={nil}
   >>            else
   if null cdr newor then 
   if car newor neq {(1 . 1)} then <<
    if print_ then <<
     terpri()$write"Due to vanishing expressions an OR-inequality is now"$
     terpri()$write"converted to a normal inequality where each of the"$
     terpri()$write"following factors must not vanish: "$
     mathprint cons('LIST,for each l2 in car newor collect {'!*SQ,l2,t})$
    >>$
    for each l2 in car newor do addSQineq(pdes,l2,nil) 
   >>                         else % or-inequality is satisfied
                     else ineq_or:=cons(newor,ineq_or);
   l:=cdr l
  >>
 >>   
end$

%-------------------------------

symbolic procedure newinequ(pdes)$
begin scalar ex$
 change_prompt_to ""$ 
 write "Input of a value for the new non-vanishing expression."$
 terpri()$
 write "You can use names of pds, e.g. 3*e_12 - df(e_13,x) + 8; "$
 terpri()$
 write "Terminate the expression with ; or $ : "$
 terpri()$
 ex:=simp termxread()$
 for each a in pdes do ex:=subsq(ex,{(a . {'!*sq,get(a,'sqval),t})})$
 % for each a in pdes do ex:=simp!* {'!*SQ,subsq(ex,{(a . {'!*sq,get(a,'sqval),t})}),nil}$
 % - simp!* {'!*SQ,..,nil} to simplify poly using identities, like i^2 -> -1
 terpri()$
 restore_interactive_prompt()$ 
 addSQineq(pdes,ex,t)
end$

%-------------------------------

symbolic procedure preduce_list(l,eqns)$
% returns the first expression of l that is reduced to zero otherwise nil
% CALL ONLY WITH eqns WITH NOT MORE THAN max_term_to_pred TERMS AS PREDUCE
% BECOMES TOO SLOW
begin scalar viol,p$
 while null viol and l do
 if more_than_x_terms(numr car l,max_term_to_pred) then l:=cdr l 
                                                   else <<
  p:=err_catch_preduce({'!*sq,car l,t},eqns)$
  if sqzerop p then viol:=car l
               else    l:=cdr l % includes p=nil, i.e. crash of preduce
 >>$

% if (not more_than_x_terms(numr car l,max_term_to_pred)) and
%    algebraic(preduce((lisp {'!*sq,car l,t}),eqns)=0) then viol:=car l
%                                                      else    l:=cdr l$
 return viol
end$

%-------------------------------

symbolic procedure check_ineq(arglist)$
% This function is only called as an element of proc_list_
% or interactively.

if vl_ then 
if print_ then lisp <<
 write"This module is only applicable to algebraic problems."$terpri()$
 write"The global list of independent variables vl_ is not empty"$terpri()$
 write"which indicates this is a differential system, so the module"$terpri()$
 write"is not applied."$terpri()
>>        else
       else  
begin scalar eqns,g,h,vanishes$

 for each h in car arglist do if get(h,'terms)<=max_term_to_pred then
 eqns:=cons({'!*SQ,get(h,'sqval),t},eqns);
 if null eqns then return nil;
 eqns:=cons('LIST,eqns);

 algebraic torder(lisp(cons('LIST,ftem_)),revgradlex);
 if h:=preduce_list(ineq_,eqns) then return << 
  if print_ then <<
   write"The inequality 0 <> "$
   eqprint {'!*SQ,h,t}$
   write" is violated."$terpri()
  >>$
  contradiction_:=t$
 >>$ % to return nil

 h:=ineq_or$
 while h and null contradiction_ do <<
  vanishes:=t$
  g:=car h$                    % g is one or-inequality
  while vanishes and g do <<   % car g is one expression in form 
                               % of a list of factors
   vanishes:=preduce_list(car g,eqns); % returns non-nil if at least one
   g:=cdr g                            % factor of car g reduces to zero
  >>;
  if vanishes then << % All expressions in the or-inequality g vanish    
   contradiction_:=t$
   write"The OR-inequality {"$
   for each g in car h do eqprint g$ 
   write"} is violated as each expression vanishes modulo all equations."$ 
   terpri()
  >>          else h:=cdr h % no contradiction_
 >>$ % to return nil
end$

%-------------------------------

symbolic procedure delete_ineq(pdes)$
begin scalar n,p$
 print_ineq((ineq_ . nil))$
 change_prompt_to ""$ 
 terpri()$
 write "Select an inequality to be dropped through a number 1 - ",
       length ineq_$terpri()$
 write"based on the order in which they are printed above. "$terpri()$
 write"To return to main menu input 0. "$
 n:=termread()$
 if zerop n then return nil;
 if not fixp n then return <<write "This was not a number!"$terpri()$nil>>$
 ineq_:=delete(nth(ineq_,n),ineq_);
 if yesp("Shall possible substitution be re-determined (not recommended) ? ") 
 then for each p in pdes do <<
  flag1(p,'to_eval)$
  put(p,'fcteval_lin,nil)$
  put(p,'fcteval_nca,nil)$
  put(p,'fcteval_nli,nil)$
  put(p,'fcteval_n2l,nil)$
  put(p,'fct_nli_lin,nil)$
  put(p,'fct_nli_nca,nil)$ 
  put(p,'fct_nli_nli,nil)$
  put(p,'fct_nli_nus,nil)$
 >>;

 if ineq_or then <<
  print_ineq((nil . ineq_or))$
  terpri()$
  write "Select an OR-inequality to be dropped through a number 1 - ",
        length ineq_or$terpri()$
  write"based on the order in which they are printed above. "$terpri()$
  write"Input a 0 if no inequality shall be deleted: "$
  n:=termread()$
  if zerop n then return nil;
  if not fixp n then return <<write "This was not a number!"$terpri()$nil>>$
  ineq_or:=delete(nth(ineq_or,n),ineq_or);
 >>$

 restore_interactive_prompt()
end$

%-------------------------------

endmodule$

end$

can_not_become_zeroSQ
  simplifySQ

simplifypdeSQ
  simplifySQ

simplifySQ
  separ
  err_catch_fac2
  sffac

simp_ineq_with_pdes
  simplifySQ
  preduce

simpSQineq_or_adhoc
  simplifySQ
  addSQineq

simpSQineq_or
  addSQineq

addSQineq
  simplifySQ
  updateSQfcteval
  new_ineq_from_equ_SQ
  simpSQineq_or

simp_ineq_with_pdes
  torder
  preduce
  simplifySQ

simp_ineq_with_equ_SQ
  simplifySQ
  preduce
  simp_ineq_with_pdes
  
simp_all_ineq_with_equ_SQ
  torder
  simp_ineq_with_equ_SQ
  addSQineq
  
new_ineq_from_equ_SQ
  simplifySQ
  addSQineq

simp_ineq_with_subst_SQ
  simplifySQ
  simp_ineq_with_pdes
  
simp_all_ineq_with_subst_SQ
  torder
  simp_ineq_with_subst_SQ
  addSQineq
  
newinequ
  addSQineq

preduce_list
  preduce

check_ineq
  torder
  preduce_list

delete_ineq
--------------------------------------
tr delete_ineq
tr check_ineq
tr preduce_list
tr newinequ
tr simp_all_ineq_with_subst_SQ
tr simp_ineq_with_subst_SQ
tr new_ineq_from_equ_SQ
tr simp_all_ineq_with_equ_SQ
tr simp_ineq_with_equ_SQ
tr simp_ineq_with_pdes
tr addSQineq
tr simpSQineq_or
tr simpSQineq_or_adhoc
tr simp_ineq_with_pdes
tr simplifySQ
tr can_not_become_zeroSQ
tr more_than_x_terms
tr updatesqfctevalo
tr give_low_priority
