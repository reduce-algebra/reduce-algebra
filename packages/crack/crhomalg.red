%********************************************************************
module homalgsys$
%********************************************************************
%  Routines for the efficient solution of homogeneous algebraic systems
%  Author: Thomas Wolf
%  May 2000

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

symbolic fluid '(tr_hom_alg)$

lisp(tr_hom_alg:=t)$

algebraic procedure bi_lin_expt(p)$
if p=1 then 0 else
if  arglength(p)<2 then 1 else
if (arglength(p)=2) and (part(p,0)=expt) then part(p,2)
                                         else write"error!"$

symbolic procedure find_hom_deg_sf(p)$
% p is supposed to be a standard form,
% returns {total degree of flin_ functions,
%          total degree of all other functions}
% in first term of p.
begin scalar tm,f,sb,l1,l2$
 tm:=first_term_sf p$
 l1:=gensym()$
 l2:=gensym()$
 for each f in flin_ do 
    sb:=cons((f . {'times,f,l1}), sb)$
 for each f in setdiff(fhom_,flin_) do 
    sb:=cons((f . {'times,f,l2}), sb)$
 tm:=numr quotsq(simp {'!*sq,subf(tm,sb),nil}, (tm . 1))$

 return
 if not pairp tm then {0,0} else
 if mvar tm = l1 then if (domainp lc tm) or
                         ((pairp tm) and (car tm = '!:gi!:))
                      then {ldeg tm, 0        }
                      else {ldeg tm,ldeg lc tm}
                 else if (domainp lc tm) or 
                         ((pairp tm) and (car tm = '!:gi!:))
                      then { 0,        ldeg tm}
                      else {ldeg lc tm,ldeg tm}
end$

%algebraic procedure find_hom_deg(p)$
%% returns {dg1,dg2} where dg1 is the degree of     flin_ functions
%%                         dg2 is the degree of non-flin_ functions
%begin scalar tm,f$
% % take first term only
% if (arglength(p)<0) or (part(p,0) neq plus) then tm:=p 
%                                             else tm:=part(p,1)$
% l1:=lisp gensym()$
% l2:=lisp gensym()$
% sb:=append(for each f in lisp(cons('LIST,              flin_ )) collect f=f*l1,
%            for each f in lisp(cons('LIST,setdiff(ftem_,flin_))) collect f=f*l2)$
% tm:=sub(sb,tm)/tm$
 
% if freeof(tm,l1) then <<
%  dg1:=0;
%  dg2:=bi_lin_expt(tm);
% >>               else
% if freeof(tm,l2) then <<
%  dg1:=bi_lin_expt(tm);
%  dg2:=0;
% >>               else
% if (arglength(tm)=2) and (part(tm,0)=TIMES) then 
% if freeof(part(tm,1),l2) then <<dg1:=bi_lin_expt(part(tm,1));
%                                 dg2:=bi_lin_expt(part(tm,2)) >>
%                          else <<dg1:=bi_lin_expt(part(tm,2));
%                                 dg2:=bi_lin_expt(part(tm,1)) >>
%                                             else write"error3";
% % The next two lines are a test whether the equation is still
% % homogeneous. This is currently commented out to save time.
% % tm:=sub(sb,p)/l1**dg1/l2**dg2$
% % if tm neq p then write"INHOMOGENEOUS!"$
%
% return {dg1,dg2}
%end$


symbolic procedure find_homo_weights(pdes)$
% We assume that equations are algebraic polynomial and that 
% denominators are homogeneous
if null alg_poly then nil else
begin 
 scalar w,p,s,
        sf,   % numerator of an equation (minus first terms..)
        tf,   % (first) term of sf
        wl,   % list of all weight names (needed for solveeval)
        ali,  % association list of (unknown . weight_name) 
        wtli, % list of conditions resulting from one equation
        wt,   % weight of one term in one equation
        eli   % list of all condiltions on weights
$
 for each f in ftem_ do <<
  w:=mkid('w_,f);
  wl:=cons(w,wl);
  ali:=cons((f . w), ali);
 >>;

 for each p in pdes do 
 if (get(p,'terms)>1) and 
    (null get(p,'nonrational)) then <<
  sf:=numr get(p,'sqval);   % sf is the numerator of the equation
  wtli:=nil;
  while sf do <<
   tf:=first_term_sf sf; sf:=subtrf(sf,tf); % tf is the first term

   wt:=nil;
   while tf and not domainp tf do <<
    w:=assoc(mvar tf,ali);
    if w then <<
     wt:=cons({'times,ldeg tf,cdr w},wt)
    >>;
    tf:=lc tf
   >>;
   wt:=if null wt then 0              else
       if cdr  wt then cons('plus,wt) else 
                       car wt$
   wtli:=cons(wt,wtli)
  >>;

  if wtli and cdr wtli then % ie. if there are at least 2 terms
  % then formulate a weight condition for each term to have
  % the same weight as the first term, eli is the resulting
  % list of conditions
  for each w in cdr wtli do
  eli:=cons(reval {'difference,car wtli,w}, eli) 

 >>;

 % solving the system of conditions
 !!arbint:=0;
 s:=solveeval {cons('list,eli),cons('list,wl)};

 if !!arbint=0 then write"This system is not homogeneous." else
 if !!arbint=1 then write"This system has the following homogeneity:" else
                    write"The following are possible homogeneities:"$
 mathprint s$

 % One could print all homogeneities individually by setting all but one
 % arbcomplex(i) variable to zero and replace the one by the lowest
 % common multiple of all numerical denominators of all rhs's.

 return nil
end$


symbolic operator make_hom_ansatz$
symbolic procedure make_hom_ansatz(f_1,f_2,d1,d2)$
begin scalar ans,ans1,ans2,h,fl,rply;

 if null f_1 then ans1:=1 else
 if null cdr f_1 then ans1:={'expt,car f_1,d1} else
 ans1:={'expt,cons('plus,f_1),d1}$

 if null f_2 then ans2:=1 else
 if null cdr f_2 then ans2:={'expt,car f_1,d2} else
 ans2:={'expt,cons('plus,f_2),d2}$

 ans:=reval {'times,ans1,ans2}$

 return
 if (not pairp ans) or (car ans neq 'plus) then <<
  h:=gensym();
  {'list,{'times,h,ans},{'list,h}}
 >>                                        else <<
  ans:=cdr ans$
  for each f in ans do <<
   h:=gensym()$
   fl:=cons(h,fl)$
   rply:=cons({'times,h,f},rply)
  >>$
  {'list,cons('plus,rply),cons('list,fl)}
 >>
end$

% symbolic procedure bi_lin_sep(p,fl_1,fl_2)$
% % separation of p wrt all fl_1, fl_2
% begin scalar fl_1,fl_2,f1,f2,f,su,pcp,sepli,cnd;
%
%  for each f1 in fl_1 do <<
%   if print_ then write "Separation wrt. ",f1,". "$
%   su:=nil;
%   for each f in fl_1 do 
%   su:=cons(if f=f1 then {'EQUAL,f,1}
%		     else {'EQUAL,f,0},su);
%   su:=cons('LIST,su);
%   pcp:=algebraic(sub(su,p));
%   if print_ then <<write "Substitution done."$terpri()>>$
%
%   for each f2 in fl_2 do <<
%    su:=nil;
%    for each f in fl_2 do 
%    su:=cons(if f=f2 then {'EQUAL,f,1}
%		      else {'EQUAL,f,0},su);
%    su:=cons('LIST,su);
%    cnd:=algebraic(sub(su,pcp));
%    if pairp cnd and car cnd='MINUS then cnd:=cadr cnd;
%    sepli:=union(list cnd,sepli);
%
%   >>$
%  >>$
%  return cons('LIST,sepli)
% end$

symbolic procedure bi_lin_eqn_lin_comb(pdes)$
% generates a linear combination of all pdes
% returns also list of unknown coefficients
begin scalar p,fl,rs,h$
 if print_ then <<
  write "Formulating a linear combination of all equations."$
  terpri()
 >>$
 rs:=(nil . 1)$
 for each p in pdes do
 <<h:=gensym()$  %p$  % gensym()$    %#?#
   fl:=cons(h,fl)$
%  rs:=cons({'TIMES,h,get(p,'val)},rs)
   rs:=addsq(multsq(simp h,get(p,'sqval)),rs)
 >>$
%rs:=cons('PLUS,rs)$
%return {'LIST,reval rs,cons('LIST,fl)}
 return {'list,{'!*sq,rs,t},cons('list,fl)}
end$

symbolic procedure drop_dep_bi_lin(arglist)$
begin scalar pdes,cnd,fl,f,cndcp,c,linde,again$
 pdes:=car arglist$
 if pdes and cdr pdes then 
 repeat <<
  again:=nil$    % #?#
  cnd:=bi_lin_eqn_lin_comb(pdes)$
  fl:=caddr cnd$
% cnd:=bi_lin_sep(cadr cnd,fl_1,fl_2)$ 
%  cnd:=split_simplify({{'LIST,cadr cnd},{'LIST},
%                       cons('LIST,append(fl_1,fl_2)),{'LIST},t})$
  cnd:=split_simplify({{'list,cadr cnd},{'list},
                       fl,cons('list,ftem_),t})$

  if print_ then <<write"Now solving the linear system."$terpri()>>$
  !!arbint:=0;
  cnd:=cadr solveeval list(cnd,fl)$

  if cnd then <<
   cnd:=car cnd$  % the first 
   for f:=1:!!arbint do <<
    cndcp:=cnd;
    for c:=1:!!arbint do
    if c neq f then cndcp:=algebraic(sub(arbcomplex(c)=0,cndcp));
    cndcp:=cdr cndcp;

    while cndcp and 
          ((zerop caddar cndcp) or
           (not freeof(linde,cadar cndcp))) do cndcp:=cdr cndcp;
    if null cndcp then <<
     write"The computation to find redundant equations has to be done again."$
     % again:=t$    % #?#????
     terpri()
    >>            else linde:=cons(reval cadar cndcp,linde);
   >>$
   if null linde then write"No equations deleted."
                 else write"Deleted redundant equations: ",linde$
   terpri()$
   for each f in linde do pdes:=drop_pde(f,pdes,nil)$
   if again then <<  % #?# con not become nil currently
    write"This computation has to be repeated"$
    terpri()
   >>
  >>
 >> until null again;

 return if linde then cons(pdes,cdr arglist)
                 else nil
end$

symbolic procedure find_factor_bi_lin(arglist)$
begin scalar h,pdes,fc,rhs,lhs,lhsfl,cnd,cndcp,fl,fl_1,fl_2,
      hdg,dg1,dg2,indx1,indx2,again,foundsome$

 write"Before starting to determine factorizable equations with "$terpri()$
 write"a given factor (preferably one known to be non-zero), all"$terpri()$
 write"redundant equations have to be dropped."$terpri()$
 write"Has this already been done? (y/n) "$

 change_prompt_to ""$ 
 repeat h:=termread() until (h='y) or (h='n)$
 if h='n then arglist:=drop_dep_bi_lin(arglist)$
 terpri()$

 fl_1:=flin_;
 fl_2:=setdiff_according_to(ftem_,flin_,ftem_);
 pdes:=car arglist$
 write"Start of determining factorizable equations."$terpri()$ 
 repeat <<
  
  write"Give a factor of the sum of equations to be found: (terminate with ; ) "$
  terpri()$
  fc:=termxread()$

  if null rhs then <<
   rhs:=bi_lin_eqn_lin_comb(pdes)$
   fl:=caddr rhs;  % alg mode list
   rhs:=cadr rhs;  % expression
  >>$

  hdg:=find_hom_deg_sf(numr simp fc)$
  dg1:=1-car  hdg$
  dg2:=1-cadr hdg$
  lhs:=make_hom_ansatz(fl_1,fl_2,dg1,dg2)$
  lhsfl:=caddr lhs;
  lhs:=cadr lhs$

% cnd:=bi_lin_sep(algebraic(fc*lhs-rhs),fl_1,fl_2)$ 
%  cnd:=split_simplify({{'LIST,algebraic(fc*lhs-rhs)},{'LIST},
%                       cons('LIST,append(fl_1,fl_2)),{'LIST},t})$
  cnd:=split_simplify({{'list,algebraic(fc*lhs-rhs)},{'list},
                       fl,cons('list,ftem_),t})$

  if print_ then <<write"Now solving the linear system."$terpri()>>$
  !!arbint:=0;
  cnd:=cdr solveeval list(cnd,cons('list,append(cdr lhsfl,cdr fl)))$
  if cnd then <<
  
   cnd:=car cnd; % i.e. take the first solution
   lhs:=algebraic(sub(cnd,lhs));

   for indx1:=1:!!arbint do <<
    cndcp:=lhs;
    for indx2:=1:!!arbint do
    if indx2 neq indx1 then cndcp:=algebraic(sub(arbcomplex(indx2)=0,cndcp))
                       else cndcp:=algebraic(sub(arbcomplex(indx2)=1,cndcp))$
    if not zerop cndcp then <<
%    cndcp:={'TIMES,fc,cndcp}$
     cndcp:={'!*sq,multsq(simp fc,cndcp),t}$

     pdes:=eqinsert(h:=mkeqsq(cndcp,nil,nil,ftem_,vl_,
                              allflags_,t,list(0),nil,pdes),pdes)$
     if h and not freeof(pdes,h) then <<

      foundsome:=t;
% Drop one redundant equation

%     write"New equation: ",h$ mathprint get(h,'val)$
      write"New equation: ",h$ mathprint {'!*sq,get(h,'sqval),t}$
      rhs:=nil;
     >>
    >>
   >>
  >>;
  write"Do you want to find further factorizable equations ",
       "with other factors? (y/n) "$
  repeat h:=termread() until (h='y) or (h='n)$
  if h='y then again:=t
          else again:=nil$
 >> until null again$

 restore_interactive_prompt()$ 
 return if foundsome then cons(pdes,cdr arglist)
                     else nil
end$

symbolic procedure eligible_eqn(p,allnzf,fewest_f_so_far)$
% This procedure returns a list of non-zero functions
% if the equation is eligible.
begin scalar hd,maxdeg,maxdegderivs,alld,der;
  hd:=get(p,'hom_deg); 
  return
  if get(p,'nonrational)                   or % non-rational
     (null hd)                             or % not homogeneous
     (car  get(p,'hom_deg) neq 0)          or % involves flin_ functions
     (cadr get(p,'hom_deg)  <  2)          or % is lin in non-flin_ functions
     (length get(p,'fct_hom) > 3)          or % more than 3 functions
     ((fewest_f_so_far=2)            and 
      (length get(p,'fct_hom) neq 2)     ) or % does not have 2 fnc if needed
     freeoflist(get(p,'fct_hom),allnzf)       % no function is non-zero
  then nil else 
  if (length get(p,'fct_hom) = 2) then cons(2,smemberl(allnzf,get(p,'fct_hom)))
                                  else <<     % 3 functions

    % We want to introduce a non-homogeneous function only if it is worth it, i.e. 
    % if one non-zero function occurs with a higher power than all other functions

    % Find all functions with the highest power
    alld:=get(p,'derivs);
    % derivs is a list of ((f) . 5)  or ((f x y 2) . 2)
    maxdeg:=0;
    maxdegderivs:=nil;
    while alld do <<
      der:=car alld;   alld:=cdr alld;
      if null cdar der then % i.e. this is just the function, not a derivative  
      if cdr der = maxdeg then maxdegderivs:=cons(der,maxdegderivs) else
      if cdr der > maxdeg then <<maxdegderivs:={der};maxdeg:=cdr der>>
    >>$

    % From those return the ones that are non-zero
    cons(3,smemberl(allnzf,maxdegderivs))
  >>
end$
 
symbolic procedure para_solve_hom_equ(arglist)$
% This procedure prepares for substitutions fi=c*f1 to be done where 
% - f1,fi are known functions in which the equations are homogeneous, 
% - f1 is known to be non-zero, and 
% - there are equations that satisfy the criteria listed in procedure 
%   eligible_eqn().
% It could be that there are equations which satisfy all that except 
% there is no function known to be non-zero. For this case a procedure
% generating case distinctions like 65 or 74 should be in the proc_list_
% but with a lower priority.
% 
% The following two lines are necessary at least as long as the property
% 'hom_deg in undefined if fhom_=nil
if null fhom_ then 
if print_ then 
write"This function is only applicable to homogeneous problems." 
          else   else 
begin scalar p,h,f,fp,bestf,l1,pdes,forg,nzf,allnzf,
             pli,allf,newf,newe,vl,fewest_f_so_far$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then l1:=selectpdes(pdes,1)
                else l1:=cadddr arglist$
 for each p in ineq_ do
 if no_number_atom_sq p then allnzf:=cons(mvar numr p,allnzf);

 % Find a rational equation with only 2 or 3 functions of all variables
 % with homogeneity degree (0 n). Find a case where one of the 
 % functions is known to be non-zero

 % nzf is an assoc list of non-zero functions with the number of 
 % eligible equations they occur in.

 fewest_f_so_far:=100;
 while l1 do << % l1 is the list of PDEs to be considered for substitution
  p:=car l1; l1:=cdr l1;
  h:=eligible_eqn(p,allnzf,fewest_f_so_far);
  if h then <<
   fewest_f_so_far:=car h;
   pli:=cons(p,pli);       
   for each f in cdr h do <<  % cdr h = list of functions
    fp:=assoc(f,nzf);
    if null fp then nzf:=cons((f . 1),nzf)
               else nzf:=cons((f . add1 cdr fp),delete(fp,nzf))
   >>
  >>
 >>;

 if null nzf then return 
 if print_ then <<
  write"Either the equations do involve more than 3 functions,"$terpri()$
  write" or they do not involve functions that are known"$terpri()$
  write"to be globally homogeneous, or none of the homogeneous"$terpri()$
  write"functions in the equations is known to be non-zero."$terpri()$
  write"In that case a case distinction 44 for one of these"$terpri()$
  write"functions would help."$terpri()$
  nil
 >>        else nil
             else <<
  bestf:=car nzf; nzf:=cdr nzf;
  while nzf do <<
   if cdar nzf > cdr bestf then bestf:=car nzf;
   nzf:=cdr nzf
  >>
 >>$
 bestf:=car bestf$

 % get the list of all other functions occuring in the equations
 % in which bestf occurs
 for each p in pli do allf:=union(get(p,'fct_hom),allf)$

 if null cdr allf then return nil$

 vl:=fctargs(bestf)$
 for each f in allf do 
 if f neq bestf then <<
  newf:=newfct(fname_,vl,nfct_)$  nfct_:=add1 nfct_$
  ftem_:=append(ftem_,list newf)$
  newe:=mkeqsq(simp {'difference,f,{'times,newf,bestf}},nil,nil,
               {f,newf,bestf},vl,allflags_,t,list(0),nil,pdes);
  pdes:=eqinsert(newe,pdes)$ 
  % The substitution f=>newf*bestf is (unfortunately) done in all
  % equations, also in equations where bestf does initially not occur,
  % i.e. where
  to_do_list:=cons(list('subst_level_35,list newe),to_do_list)$
 >>$

 return list(pdes,forg)
end$

endmodule$

end$

