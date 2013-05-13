%********************************************************************
module linalgsys$
%********************************************************************
%  Routines for the memory efficient solution of linear algebraic systems
%  Author: Thomas Wolf
%  December 1998

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

symbolic fluid '(count_tries tr_subsys max_losof matrix_849)$
lisp(tr_subsys:=nil)$

symbolic procedure trian_lin_alg(arglist)$
if not lin_problem then nil else
begin scalar h1,h2,h3,h4,f,fl,newfl,tr_opt,remain_pdes,remain_fl,li,
             total_terms;

 tr_opt:=t;

 % get a list h1 of purely algebraic equation by disregarding the
 % non-algebraic equations 
 h2:=car arglist;
 while h2 do <<
  if is_algebraic(car h2) then h1:=cons(car h2,h1);
  h2:=cdr h2
 >>;

% Just for testing spot_over_det():
spot_over_det(h1,nil,nil,nil)$
write "count_tries=",count_tries; terpri()$
return nil;

 % start with reducing the length of all equations as much as possible
 repeat <<
  h2:=alg_length_reduction({h1,nil,vl_,h1}); 
  % nil for forg which is not used in alg_length_reduction()
  if h2 then h1:=car h2
 >> until contradiction_ or null h2;
 
 remain_pdes:=h1;
 total_terms:=0;
 for each h2 in remain_pdes do total_terms:=total_terms+get(h2,'terms);

 % fl now becomes a list of lists: ((n1,f1,d11,d12,d13,..),
 % (n2,f2,d21,d22,d23,...),...) where fi are the functions, 
 % dij are equation names in which fi occurs and ni is the number of dij
 for each h2 in h1 do fl:=add_equ_to_fl(h2,fl)$

 % newfl is the final newly ordered list of functions 
 while fl and null contradiction_ do << 
  % re-order all functions, those occuring in the fewest equations
  % come first
  fl:=idx_sort fl;
  if tr_opt then <<terpri()$write"fl2="$prettyprint fl>>$
  if caar fl = 1 then << % the first function occurs in only one eqn.
   % If a function occurs in only one equation then drop the function
   % and the equation from all functions in fl
   while caar fl leq 1 do <<
    if tr_opt and (caar fl = 1) then <<
     write"equation ",caddar fl," determines ",cadar fl$terpri()
    >>$
    newfl:=cons(cadar fl,newfl);
    fl:=if caar fl = 0 then cdr fl
                       else <<remain_pdes:=delete(caddar fl,remain_pdes);
                              total_terms:=total_terms-get(caddar fl,'terms);
                              fl:=del_equ_from_fl(caddar fl,cdr fl)>>
   >>;
  >>             else << % all remaining functions occur in at least 2 eqn.
   % Find a subsystem of equations that has less or equally many
   % functions as equations
   % ...

   % Find a function which is easiest decoupled/substituted 
   %            (e.g. use min-growth-substitution for that)
   remain_fl:=for each h3 in fl collect cadr h3;

   % update 'fcteval_lin for all equations. This is a preparation to
   % find the cheapest substitution
   for each h1 in remain_pdes do <<
    h2:=get(h1,'fcteval_lin)$
    li:=nil;
    if null h2 then << % assign all allowed subst.
     for each f in remain_fl do
     if not freeof(get(h1,'rational),f) then    
%    li:=cons(cons(reval coeffn(get(h1,'val),f,1),f),li);
     li:=cons(cons(coeffn({'!*sq,get(h1,'sqval),t},f,1),f),li);  
    >>        else << % keep only substitutions related to fl-functions
     while h2 do <<
      if not freeof(cdar h2,remain_fl) then li:=cons(car h2,li);
      h2:=cdr h2  
     >>
    >>;
    if li then put(h1,'fcteval_lin,reverse li);
   >>;

   % Do the substitution with the lowest upper bound of increase in complexity 
   % make_subst(pdes,forg,vl,l1,length_limit,pdelimit,less_vars,no_df,no_cases,
   %            lin_subst,min_growth,cost_limit,keep_eqn)$
   h1:=make_subst(remain_pdes,remain_fl,vl_,remain_pdes,
                  nil,nil,nil,nil,t,t,t,nil,t,nil)$
   if null contradiction_ and h1 then << % update all data
    h2:=caddr h1; % h2 was used for substitution
    h3:=total_terms-get(h2,'terms)$
    remain_pdes:=delete(h2,car h1);
    total_terms:=0;
    for each h4 in remain_pdes do total_terms:=total_terms+get(h4,'terms);
    if tr_opt then <<
     write"equation ",h2," now disregarded"$ terpri()$
     write"growth: ",total_terms-h3," terms"$terpri()$
     write length remain_pdes," remaining PDEs: ",remain_pdes$ terpri()$
    >>$
    fl:=del_equ_from_fl(h2,fl);
    h2:=cadr h1;
    while (not pairp car h2) or (caar h2 neq 'EQUAL) do h2:=cdr h2;
    f:=cadar h2$
    remain_fl:=delete(f,remain_fl);
    if tr_opt then <<
     write length remain_fl," remaining functions: ",remain_fl$ terpri()$
    >>$

    % Drop the entry for function f from fl. h4 is the list of
    % equations with f
    if cadar fl = f then <<h4:=cddar fl;fl:=cdr fl>> 
                    else << 
     h3:=fl;
     while cadadr h3 neq f do h3:=cdr h3; 
     h4:=cddadr h3;     
     rplacd(h3,cddr h3);
    >>;
    % update the appearance of equations in fl in which f was substituted
    for each h3 in h4 do <<
     fl:=del_equ_from_fl(h3,fl);
     if not freeof(remain_pdes,h3) then fl:=add_equ_to_fl(h3,fl)
    >>$

    % Have length reductions become possible through substitution?
    repeat <<
     h2:=alg_length_reduction({remain_pdes,nil,vl_,remain_pdes}); 
     % nil for forg which is not used in alg_length_reduction()
     if h2 then <<
      % update fl:
      % at first deleting dropped redundand equations from fl
      h3:=setdiff(remain_pdes,car h2);
      for each h4 in h3 do fl:=del_equ_from_fl(h4,fl);
      remain_pdes:=car h2;
      % now updating the entry for the changed equations
      for each h3 in caddr h2 do <<
       fl:=del_equ_from_fl(h3,fl); 
       if not freeof(remain_pdes,h3) then fl:=add_equ_to_fl(h3,fl)
      >>
     >>
    >> until contradiction_ or null h2;

   >>    else rederr("make_subst=nil, what now???");
  >>
 >>$
 if newfl neq ftem_ then
 change_fcts_ordering(newfl,car arglist,vl_)
% clear dec_with????
end$

symbolic procedure flin_non_triv_cond(pdes)$
% This procedure computes necessary and sufficient conditions for
% the existence of non-trivial solutions for homogeneous linear
% equations with parametric potentially vanishing coefficients,
% in other words for the case 
% alg_poly=t, not null flin_, not null fhom_, hom_deg={1,..} .
if alg_poly and flin_ and fhom_ then
begin scalar oldorder,p,h,pcf,allcf,fl,u,v,tr_subsys,sysli,sy,r,s,ncondi,
             some_new,no_of_pdes,umax,minsize,fi$
%tr_subsys:=t$ 

 % determination of all coefficients of all flin_ in all equations
 oldorder:=setkorder flin_;
 u:=0; 
 for each p in pdes do 
 if (h:=get(p,'hom_deg)) and (car h = 1) then <<
  u:=add1 u;
  h:=reorder numr get(p,'sqval);
  fl:=flin_;
  pcf:=nil;
  while fl do << % we have no need to check: not domainp l because
                 % equations are supposed to be homogeneous (not null fhom_)
   if null h or (mvar h neq car fl) then   pcf:=cons(   0,pcf)
                                    else <<pcf:=cons({'!*SQ,(lc h . 1),t},pcf);
                                           h:=red h>>;
   fl:=cdr fl
  >>;
  allcf:=cons(pcf,allcf)
 >>$
 setkorder oldorder;
 v:=length flin_;
 if print_ then <<
  write"There will be ",algebraic(factorial(lisp u)/factorial(lisp u - lisp v)
                                                   /factorial(lisp v))," equations"$
  terpri()$
  change_prompt_to ""$ 
  write"How many shall be generated? "$
  umax:=termread()$
  restore_interactive_prompt()
 >>        else umax:=1000000$
 sysli:=out_off(v,u,allcf)$    % a list of all subsets of allcf
                               % each with v many equations
 u:=0;minsize:=10000000;

 % For saving new equations                              %@@
 fi:=level_string(session_)$                             %@@
 fi:=bldmsg("%s-",fi)$                                   %@@
 fi:=cdddr explode fi$                                   %@@
 fi:=compress cons('!",cons('c,cons('d,fi)))$            %@@

 % fi:="../in/cond"$               % on hane and beowulf %@@
 % fi:="/mnt/b/twolf/cond"$        % on lie              %@@
 % fi:="/scratch/twolf/cond"$      % on bull             %@@

 for i:=1:10 do <<                                       %@@
  r:=random 10$                                          %@@
  fi:=bldmsg("%w%d",fi,r)                                %@@
 >>$                                                     %@@
 algebraic <<off nat;out fi>>$                           %@@

 while sysli and (u<umax) do <<
  sy:=car sysli; sysli:=cdr sysli;
  u:=add1 u$
%  if print_ then write u,":"$
%  if tr_subsys then <<write"sy=",sy$terpri()>>$
  machematrix('matrix_849,v,v);
  for r:=1:v do 
  for s:=1:v do
  setzewert('matrix_849,r,s,nth(nth(sy,s),r));
  h:=determinante('matrix_849);
  p:=no_of_tm_sf numr h;
%if print_ then write p,"/",minsize," "$           %@@
%if p<minsize then <<                              %@@
%minsize:=p;                                       %@@
%if null ncondi then ncondi:={h}                   %@@
%               else ncondi:={h,car ncondi};       %@@
%                  >>$                             %@@
%  ncondi:=cons(determinante('matrix_849),ncondi)$ %@@

  algebraic write {'!*SQ,h,t};                          %@@

  setk('matrix_849,nil)
 >>;
 write"end$"$ terpri()$                                 %@@
 algebraic (shut fi)$                                   %@@
 equations_file:=fi;                                    %@@

 if tr_subsys then <<write"ncondi=",ncondi$ terpri()>>$

 no_of_pdes:=length pdes;
 s:=nil;
 for each h in ncondi do <<
  r:=mkeqSQ(h,nil,nil,ftem_,vl_,allflags_,t,list(0),nil,pdes);
  pdes:=eqinsert(r,pdes)$
  s:=cons(r,s)
 >>;
 for each h in s do
 if member(h,pdes) then some_new:=cons(h,some_new);

 if print_ and some_new then <<
  write"New equations due to vanishing coeff. determinants: ",car some_new$
  for each h in cdr some_new do write", ",h
 >>$

 return if some_new or (no_of_pdes neq length pdes) then 
 if in_cycle(<<u:=0;for each r in some_new do u:=u+get(r,'printlength);
               r:=length some_new;
               s:=0;h:=nil;
	       while (s<3) and some_new do <<
		s:=add1 s; 
		h:=cons(get(car some_new,'terms),h);
		some_new:=cdr some_new
	       >>$
	       cons('sub_sys,cons(stepcounter_,cons(r,cons(u,h))))
	     >>) then nil
                 else pdes
                                                    else nil

end$

symbolic procedure sublinfct(arglist)$
% arglist = list(pdes,forg,vl_,pdes)
if null flin_ then nil else
begin scalar pdes,flcp,p,f,h,coefgcd,pdescp,casesub,nocasub,s,ff,q$
 pdes:=car arglist$
 flcp:=flin_$

 % to have all coefficients of all flin_ functions available
 for each p in pdes do fcteval(p)$

 while flcp do <<
  % is there a simplifying substitution c*f --> fnew ?
  f:=car flcp; flcp:=cdr flcp;
  coefgcd:=nil;
  pdescp:=pdes;
  while pdescp and coefgcd neq 1 do <<
   p:=car pdescp; pdescp:=cdr pdescp;
   if member(f,get(p,'fcts)) then <<
    % get coefficient of f in p
    h:=get(p,'fcteval_lin);
    while h and f neq cdar h do h:=cdr h;
    if null h then <<
     h:=get(p,'fcteval_nca);
     while h and f neq cdar h do h:=cdr h;
     if null h then <<
      h:=get(p,'fcteval_nli);
      while h and f neq cdar h do h:=cdr h
     >>
    >>$
    if null h then write"### Error in sublinfct!"$terpri()$
    % The coefficient should have been found.
    coefgcd:=
    if null coefgcd then mk!*sq caar h
                    else err_catch_gcd(mk!*sq caar h,coefgcd);
   >>  % if member(f,get(p,'fcts)) 
  >>; % while pdescp

  if coefgcd neq 1 then <<
   if pairp coefgcd and car coefgcd='!*SQ then 
% better do a full factorization:
   h:=simplifySQ(cadr coefgcd,get(p,'fcts),t,nil,nil)
                                          else h:=(1 . 1)$

   if h neq {(1 . 1)} then casesub:=cons((coefgcd . f),casesub)
                      else nocasub:=cons((coefgcd . f),nocasub)
  >>
 >>$ % while flcp

 if print_ then <<
  if casesub then <<
   write"Case generating substitutions:"$terpri()$
   mathprint cons('LIST,for each s in casesub collect 
                        {'!*SQ,multsq(cadar s,simp cdr s),t})
  >>$
  if nocasub then <<
   write"Non-case generating substitutions:"$terpri()$
   mathprint cons('LIST,for each s in nocasub collect 
                        {'!*SQ,multsq(cadar s,simp cdr s),t})
  >>
 >>$

 if null casesub and null nocasub then return nil$

 % If there are substitutions which do not generate cases then do all of them,
 % If there are case-generating substitutions then do a case-distinction
 % for the coefficient in the first substitution to be zero or not.

 if casesub then <<
  if nocasub then <<
   s:=length nocasub$
   write"After ",s,if s=1 then " substitution"
                          else " substitutions"," a case distinction for "$
   terpri()$
   mathprint {'!*SQ,cadaar casesub,t}$
   write"is made. In the case <>0 the shortening substitution"$terpri()$
   write"should be performed again."$terpri()
  >>$
  to_do_list:=union(list(list('split_into_cases,cadaar casesub)),to_do_list);
 >>$

 if nocasub then
 for each s in nocasub do <<

  % new function 
  ff:=mkid(fname_,nfct_)$
  nfct_:=add1 nfct_$

  h:=assoc(cdr s,depl!*)$
  if pairp h then depl!*:=cons(cons(ff,cdr h),depl!*)$

  ftem_:=fctinsert(ff,ftem_)$
  flin_:=sort_according_to(cons(ff,flin_),ftem_)$  
  if member(cdr s,fhom_) then 
  fhom_:=sort_according_to(cons(ff,fhom_),ftem_)$  

  % new equation
  q:=mkeqSQ(subtrsq(multsq(cadar s,simp cdr s),simp ff),nil,nil,
            ftem_,vl_,allflags_,nil,list(0),nil,pdes)$
  put(q,'not_to_eval,{ff})$
  pdes:=eqinsert(q,pdes)$
  fcteval q$

  to_do_list:=cons(cons('subst_level_35,   % module 20
                        {{q},pdes,cdr s}),to_do_list)$ 

 >>$

 return {pdes,cadr arglist}

end$

endmodule$

end$



