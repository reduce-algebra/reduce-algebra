%********************************************************************
module simplifications$
%********************************************************************
%  Routines for simplifications, contradiction testing
%  and substitution of functions
%  Author: Andreas Brand   1991 1993 1994
%          Thomas Wolf since 1996

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

symbolic procedure signchange(g)$  %  #### to be dropped? still used in crint
%  ensure, that the first term is positive
if pairp g then
 if (car g='minus) then cadr g
 else if (car g='plus) and (pairp cadr g) and (caadr g='minus)
      then reval list('minus,g)
      else g
else g$

%-------------------------------

symbolic procedure raise_contradiction(g,text)$
<<contradiction_:=t$
  if print_ then
     <<terpri()$if text then write text
                        else write "contradiction : "$
  deprint list g>> >>$ 

%----------------------------

symbolic procedure fcteval(p)$      
%  looks for a function which can be eliminated
%  if one is found, it is stored in p as (coeff_of_f . f)
%  'to_eval neq nil iff not checked yet for substitution
%                   or if subst. possible
%               i.e. 'to_eval=nil if checked and not possible
%  'fcteval_lin includes subst. with coefficients that do not
%               include ftem functions/constants
%  'fcteval_nca includes subst. with non-vanishing coefficients
%               and therefore no case distinctions (linearity)
%  'fcteval_nli includes subst. with possibly vanishing coefficients
%               and therefore case distinctions (non-linearity)
%  'fcteval_n2l =t if a function not in flin_ is to be replaced and
%               the equation contains allvarfcts in flin_, otherwise nil

if flagp(p,'to_eval) then
if pairp get(p,'fac) then remflag1(p,'to_eval) % factorizable equations should
                                               % not be used for substitutions
                     else
begin scalar ft,a,fl,li,nc,nl,f,cpf,fv,fc,f_is_in_flin,flin_sub_found$

  if (not get(p,'fcteval_lin)) and
     (not get(p,'fcteval_nca)) and
     (not get(p,'fcteval_nli)) then << % otherwise already determined
    ft:=get(p,'allvarfcts)$ 
    % if flin_ and (fl:=intersection(ft,flin_)) then <<ft:=fl; fl:=nil>>$
    % This strict condition never to substitute a non-flin_ function by
    % an expression including flin_ functions is eased below.
    if null ft then <<
      ft:=setdiff(get(p,'rational),get(p,'not_to_eval))$   
      % i.e. for example, no functions that replace a derivative
      
      % drop all functions f from ft for which there is another
      % function which is a function of all variables of f + at
      % least one extra variable
      if vl_ then <<
        for each f in ft do <<
          cpf:=get(p,'fcts)$
          fv:=fctargs f$
          while cpf and 
                (not_included(fv,fc:=fctargs car cpf) or
                 (length fv >= length fc)                ) do 
          cpf:=cdr cpf; 
          if null cpf then fl:=cons(f,cpf)
        >>$
        ft:=fl
      >>
    >>$
    li:=nc:=nl:=nil$
    for each f in ft do 
    if null member(f,get(p,'not_to_eval)) then % i.e. not a function just
                                       % introduced through this equation
    if alg_linear_fct(p,f) then % i.e. only linear algebr. fcts
    if confirm_subst or (null flin_) or 
       <<f_is_in_flin:=member(f,flin_)$
         if flin_sub_found and null f_is_in_flin then nil 
                                                 else <<
           % either f is in flin_ or no fnc in flin_ is found yet
           if f_is_in_flin and null flin_sub_found then <<
             % f is the first fct in flin_ that is found
             li:=nc:=nl:=nil$
             % That means that a case generating substitution of a
             % flin_ function has a higher priority than a non-case
             % generating substitution of a non-flin_ function in
             % terms of flin_ functions
             flin_sub_found:=t
           >>$
           t
         >>
       >> then 
    <<a:=coeffn({'!*sq,get(p,'sqval),t},f,1)$
      a:=if pairp a and (car a='!*sq) then cadr a
                                      else simp a;
      if null (fl:=smemberl(delete(f,get(p,'fcts)),a)) then 
      li:=cons(cons(a,f),li)                           else
      if can_not_become_zeroSQ(a,fl) then nc:=cons(cons(a,f),nc)
                                     else nl:=cons(cons(a,f),nl)
    >>$

    if flin_ and null flin_sub_found and vl_ and % the 'and vl_' test is
     % made to avoid the more time expensive intersection test if possible
       (fl:=intersection(ft,flin_)) then <<

     % We can not get to here for purely algebraic problems
     % because a case generating substitution of a flin_function
     % would have a higher priority than a substitution of a
     % non-flin_ function.

     % At this point it is not clear whether this substitution will be selected
     % in get_subst, so it is not investigated now whether f is not actually
     % occuring only linearly wrt. flin_. Also, such an investigation would 
     % potentially be repeated many times for the same function if done here.
     % --> For informing get_subst() that this substitution is potentially
     % replacing a non-flin_ function by an flin_ function :
     put(p,'fcteval_n2l,t)

    >>$
    if li then put(p,'fcteval_lin,reverse li); % else
    if nc then put(p,'fcteval_nca,reverse nc); % else
    if nl then put(p,'fcteval_nli,reverse nl);
    if not (li or nc or nl) then remflag1(p,'to_eval)
  >>$ 

  return (get(p,'fcteval_lin) or 
          get(p,'fcteval_nca) or 
          get(p,'fcteval_nli)    )
end$

%----------------------------

symbolic procedure best_mdu(p)$
if get(p,'fcteval_lin) then 1 else
if get(p,'fcteval_nca) then 2 else
if get(p,'fct_nli_lin) then 3 else
if get(p,'fct_nli_nca) then 4 else
if get(p,'fct_nli_nli) then 5 else
if get(p,'fct_nli_nus) then 6 else 7$

%----------------------------

symbolic procedure get_subst(pdes,l,length_limit,less_vars,no_df,no_cases)$ 
% --> new version to minimize no of terms substituted, old version to minimize 
%     no of cases see at end
% get the most simple pde from l which leads to a function substitution
% if less_vars neq nil: the expr. to subst. has only fcts. of fewer vars
% if no_df neq nil:     the expr. to subst. has no derivatives

% Requirements for substitutions are potentially contradicting:
% - not to generate cases
% - not to multiply with extra factors, i.e. not to have no-number coefficients
% - to replace by as few terms as possible
% - not to replace a function that is known to be non-vanishing
% - not to replace a non-flin_ function/constant by an expression 
%   involving flin_ functions 
% - to use equations involving the highest number of independent variables
begin scalar p,q,h,l1,l2,m,ntms,mdu,ineq_cp,rtn,lcop,fcteval_cop,necount,
      found_non_ineq_sub,found_non_n2l_sub,is_non_ineq_sub,is_non_n2l_sub$
  % mdu=(1:lin, 2:nca, 3:nli_lin, 4:nli_nca, 5:nli_nli, 6:nli_nus)
  lcop:=l;
  % next: if less_vars then pick only equations with one allvarfcts
  %       or no independent variables
  if less_vars then <<
    while l do <<
      if get(car l,'nvars)=0 then l1:=cons(car l,l1)
                             else <<
        l2:=get(car l,'allvarfcts)$
        if l2 and null cdr l2 then l1:=cons(car l,l1)$
      >>;
      l:=cdr l
    >>$
    l:=reverse l1
  >>$

  % next: drop all equations longer than length_limit
  if length_limit then <<
    l1:=nil; 
    while l do
    if (h:=get(car l,'length))>length_limit then 
    if h>2*length_limit then l:=nil 
                        else l:=cdr l

                                            else <<
      l1:=cons(car l,l1)$
      l:=cdr l
    >>$
    l:=reverse l1
  >>$
  % l is now the list of equations <= length_limit

  % next: substitution only if no_df=nil or 
  %       no derivative of any function occurs
  if no_df then <<
    l1:=nil; 
    for each s in l do << 
      l2:=get(s,'derivs)$
      while l2 do 
 	if pairp(cdaar l2) then
 	   <<l2:=nil;
           l1:=cons(s,l1)>>
        else l2:=cdr l2>>$
    l:=setdiff(l,l1)
  >>$

  % next: initialize 'fcteval_lin,...
  %       if no_cases then restrict to substitutions that don't lead to cases.

  l1:=nil; 
  necount:=0;
  for each s in l do 
  if fcteval(s) then
  if get(s,'fcteval_lin) or get(s,'fcteval_nca) then l1:=cons(s,l1) else
  if null no_cases then 
  if (h:=get(s,'fcteval_nli)) then <<
    if (null get(s,'fct_nli_lin)) and
       (null get(s,'fct_nli_nca)) and
       (null get(s,'fct_nli_nli)) and
       (null get(s,'fct_nli_nus)) then <<
      ineq_cp:=ineq_; ineq_:=nil;
      % partition of get(s,'fcteval_nli) into the above 4 cases
      for each l2 in h do <<
        q:=mkeqSQ(car l2,nil,nil,get(s,'fcts),get(s,'vars),allflags_,
		  t,list(0),nil,nil);
	% the pdes-argument in mkeqSQ() is nil to avoid lasting effect on pdes
	necount:=add1 necount$
	fcteval(q)$ % less_vars
	if get(q,'fcteval_lin) then 
	put(s,'fct_nli_lin,cons(l2,get(s,'fct_nli_lin))) else
	if get(q,'fcteval_nca) then 
	put(s,'fct_nli_nca,cons(l2,get(s,'fct_nli_nca))) else
	if get(q,'fcteval_nli) then 
	put(s,'fct_nli_nli,cons(l2,get(s,'fct_nli_nli))) else
	put(s,'fct_nli_nus,cons(l2,get(s,'fct_nli_nus)))$
	drop_pde(q,nil,nil)$
	if necount>100 then <<
	 clean_prop_list(pdes)$
	 necount:=0
	>>
      >>$
      ineq_:=ineq_cp
    >>$
    l1:=cons(s,l1)$ % Before the number of splitting was minimized. Now the 
                    % number of indep. variables is max.ed and length min.ed.
  >>$
  l:=l1$

  % next: find an equation with the following priority list:
  %       - as many as possible variables 
  %       - few as possible terms for substitution    
  %       - generating as few as possible cases
  %       - not substituting a non-flin_ function by flin_ functions
  m:=-1$ mdu:=8$
  for each s in l do <<
   l1:=get(s,'nvars);
   if get(s,'starde) then l1:=sub1 l1;
   if l1>m then m:=l1$
  >>$

  while m>=0 do <<
    l1:=l$
    ntms:=10000000$
    found_non_ineq_sub:=nil$  % whether a possibly vanishing function can be substituted
    found_non_n2l_sub :=nil$  % whether it can be avoided to substitute a non-flin_
                              % function by an expression involving flin_ functions
    while l1 do               % check each suitable equation car l1
    if ((get(car l1,'nvars) -
         if get(car l1,'starde) then 1 
                                else 0) = m   ) and 
       (q:=fcteval(car l1))                     and
       ((is_non_ineq_sub:=null member(simp cdar q,ineq_)) or
        null found_non_ineq_sub
        % Try to find a substitution which does not replace a
        % non-vanishing function. 
        % if  one is found then is_non_ineq_sub <> nil (good)
        % if none is found then is_non_ineq_sub =  nil ( bad)
        % Only the first of the possible substitutions of this equation is
        % checked because non-vanishing functions have a low priority and
        % should coming only later in q.
       )                                        and
       ((is_non_n2l_sub:=null get(car l1,'fcteval_n2l)) or
        null found_non_n2l_sub
        % Try to find a substitution which does not replace a 
        % non-flin_ function by an expression invloving allvarfcts
        % flin_ functions
        % if  one is found then is_non_n2l_sub <> nil (good)
        % if none is found then is_non_n2l_sub =  nil ( bad)
       )                                        and
       ((get(car l1,'terms) < ntms       ) or
        ((get(car l1,'terms) = ntms) and
         (best_mdu(car l1) < mdu   )     )    ) then 
    <<p:=car l1$  l1:=cdr l1$
      ntms:=get(p,'terms)$
      mdu:=best_mdu(p)$
      if null found_non_ineq_sub then found_non_ineq_sub:=is_non_ineq_sub$
      if null found_non_n2l_sub  then found_non_n2l_sub:=is_non_n2l_sub
    >>                                          else l1:=cdr l1$
    m:=if p then -1
            else sub1 m
  >>$

  if p then return <<

    fcteval_cop:=if mdu=1 then get(p,'fcteval_lin) else
                 if mdu=2 then get(p,'fcteval_nca) else
                 if mdu=3 then get(p,'fct_nli_lin) else
                 if mdu=4 then get(p,'fct_nli_nca) else
                 if mdu=5 then get(p,'fct_nli_nli) else
                 if mdu=6 then get(p,'fct_nli_nus); 
    rtn:={mdu,p,pick_fcteval(pdes,mdu,fcteval_cop)};
    % prevent the substitution of a function<>0
    if rtn and fhom_ and 
       setdiff(for each h in get(p,'fcts) collect simp h,ineq_) and 
       cdr pdes and (get(p,'terms)>1) then <<
      % i.e. not all ftem_ have to be non-zero
      % and it is not the last pde

      % n0f:=setdiff(ineq_,setdiff(ineq_,for each h in ftem_ collect simp h));
      % if freeof(n0f,cdaddr rtn) then rtn
      if not member(simp cdaddr rtn,ineq_) then rtn
                                           else
      if null cdr fcteval_cop then % rtn was the only substitution of this eqn.
      if cdr lcop then             % there are other eqn.s to choose from
      <<h:=get_subst(pdes,delete(p,lcop),length_limit,less_vars,no_df,no_cases);
        if null h then rtn else h
      >>          else rtn % nil   % no substitution --> changed to rtn
	                      else <<
        fcteval_cop:=delete(caddr rtn,fcteval_cop);
	{mdu,p,pick_fcteval(pdes,mdu,fcteval_cop)} 
      >>
    >>                                else rtn
  >>
end$

symbolic procedure total_deg_of_first_tm(sf)$
if domainp sf then 0 else
ldeg sf + total_deg_of_first_tm lc sf$

symbolic procedure nco_SF(sf)$
% returns the numerical coefficient of the first term
<< while pairp sf and not domainp sf and not domainp lc sf do sf:=lc sf; sf>>$

symbolic procedure pick_fcteval(pdes,mdu,fctli)$ 
if fctli then
if (not expert_mode) or (length  fctli = 1) then 
% automatic pick of all the possible substitutions
if null cdr fctli then car fctli else
if mdu<3 then begin % substitute the function coming first in ftem_
 scalar best, besth1, besth2, besth3, h1, h2, h3$

 besth1:=100000000$
 while fctli do <<
  if besth1 > (h1:=no_of_tm_sf numr caar fctli) then <<
   best:=car fctli;
   besth1:=h1;
   if h1=1 then <<
    besth2:=total_deg_of_first_tm numr caar fctli$ 
    besth3:=nco_SF numr caar fctli
   >>
  >>                                            else
  if besth1=h1 then % else car fctli is not better than best
  if h1>1 then      % besth2 and besth3 are not determined
  if which_first(cdr best,cdar fctli,ftem_) neq cdr best then best:=car fctli else
          else      % besth1=h1=1, then besth2, besth3 are determined      
  if besth2>(h2:=total_deg_of_first_tm numr caar fctli) then <<
   best:=car fctli;
   besth2:=h2;
   besth3:=nco_SF numr caar fctli
  >>                                                    else 
  if besth2=h2 then % else car fctli is not better than best
  if (fixp(h3:=nco_SF numr caar fctli) and not fixp besth3) or
     (fixp h3 and fixp besth3 and (abs h3 < abs besth3)   ) then <<
   best:=car fctli;
   besth3:=h3
  >>;
  fctli:=cdr fctli
 >>;
 return best
end      else 
begin scalar co,minfinco,minnofinco,finco,nofinco,fctlilen,
      n,maxnopdes,nopdes,f,bestn$
 % 1. find a substitution where the coefficient involves as few as possible functions
 fctlilen:=length fctli$
 minnofinco:=10000$
 for n:=1:fctlilen do <<
  co:=nth(fctli,n)$
  finco:=smemberl(ftem_,car co);
  nofinco:=length finco;
  if nofinco<minnofinco then <<minfinco:=list(cons(n,finco));
                               minnofinco:=nofinco>> else
  if nofinco=minnofinco then minfinco:=cons(cons(n,finco),minfinco);
 >>$
 if (length minfinco=1) or (minnofinco>1) 
 % if there is only one substitution where the coefficient has a
 % minimal number of ftem_ functions or
 % if the minimal number of functions in any coefficient is >1
 then return nth(fctli,caar minfinco) % return any ony one of the minimal ones
 else return << % find the one with the ftem_ function that occurs in the
	        % fewest equations, to complicate as few as possible equations
  maxnopdes:=1000000;
  for each su in minfinco do <<
   f:=cadr su;
   nopdes:=0;
   for each p in pdes do if not freeof(get(p,'fcts),f) then nopdes:=add1 nopdes;
   if nopdes<maxnopdes then <<maxnopdes:=nopdes;bestn:=car su>>;
  >>$
  nth(fctli,bestn)
 >>
end                                           else 
begin scalar fl,a,h;
 fl:=for each a in fctli collect cdr a$
 write"Choose a function to be substituted from "$
 listprint(fl)$terpri()$
 change_prompt_to ""$ 
 repeat h:=termread() until not freeof(fl,h);
 restore_interactive_prompt()$ 
 while h neq cdar fctli do fctli:=cdr fctli;
 return car fctli 
end$

symbolic procedure do_one_subst(ex,f,a,ftem,vl,level,eqn,pdes)$ 
% substitute ex for f in a
% ex is in {'!*sq,SQ,t} form, f is a kernel, a is in SQ form
begin scalar l,l1,p,oldstarde$
 % l is the list of factors of a
 l:=get(a,'fac)$
 if not pairp l then l:={get(a,'sqval)}$
 oldstarde:=get(a,'starde)$
 while l do <<  % for each factor
  if smember(f,car l) then <<   
   % p:=subsq(car l,{(f . ex)})$ 
   p:=simp!* {'!*sq,subsq(car l,{(f . ex)}),nil}$ 
   % - simp!* {'!*sq,..,nil} to simplify poly using identities, like i^2 -> -1
   if sqzerop p then <<l:=list nil$l1:=list 0>>
                else <<
    l1:=cons(p,l1)
   >> 
  >>                  else l1:=cons(car l,l1)$
  l:=cdr l
 >>$
 l:=nil$
 while l1 do <<
  if not member(car l1,cdr l1) then
  l:=union(simplifySQ(car l1,ftem,t,nil,nil),l)$
  l1:=cdr l1
 >>$
 l:=delete((1 . 1),l)$  % delete all non-vanishing factors
 if null l then <<
  if print_ then <<
   terpri()$  % new
   write"Substitution of "$
   fctprint list f$
   if cdr get(eqn,'fcts) then <<
    write " by an expression in "$terpri()$
    fctprint delete(f,get(eqn,'fcts))
   >>$
   write " found in ",eqn," : "$
   eqprint(list('equal,f,ex))
  >>$
  raise_contradiction({'!*sq,get(a,'sqval),t},
                      "leads to a contradiction in : ")$
  a:=nil
 >>        else 
 if member((nil . 1),l) then << % one factor is zero
  drop_pde(a,nil,0)$
  a:=nil
 >>                     else << 
%  if pairp cdr l then l:=cons('times,l)
%                 else l:=car l$
  if get(a,'level) neq level then <<
   pdes:=drop_pde(a,pdes,0)$ % pdes updated as it is used in mkeqSQ:
   a:=mkeqSQ(nil,l,nil,ftem,vl,allflags_,nil,list(0),nil,pdes)
  >>                         else <<
   p:=get(a,'derivs);    % keep the leading derivative to check 
   if p then p:=caar p;  % whether it changed in the substitution
   for each b in allflags_ do flag(list a,b)$
   if null updateSQ(a,nil,l,nil,ftem,vl,nil,list(0),pdes) then <<
    % l is a list of sq-form factors 
    drop_pde(a,pdes,0)$
    a:=nil
   >>                                      else <<
    % If the leading derivative has changed then drop
    % the 'dec_with and the 'dec_with_rl list.
    l1:=get(a,'derivs);
    if l1 then l1:=caar l1;
    if l1 neq p then <<
     put(a,'dec_with,nil);
     put(a,'dec_with_rl,nil);
     for each l1 in pdes do if l1 neq a then <<
      drop_dec_with(a,l1,t)$
      drop_dec_with(a,l1,nil)
     >>
    >>;
    drop_pde_from_idties(a,pdes,nil)$
    % nil as second argument for safety, for not knowing better
    put(a,'rl_with,nil);
    for each l1 in pdes do if l1 neq a then drop_rl_with(a,l1)
   >>
  >>$
  put(a,'level,level)
 >>$
 if oldstarde and not get(a,'starde) then put(a,'dec_with,nil);
 return a$
end$

symbolic procedure sub_in_forg(f,ex,forg);
% f is the function to be substituted in forg
% ex has form {'!*sq,..,t}
begin scalar fl,h,was_subst,dnr$
 % fl:=delete(f,smemberl(ftem_,ex))$ % functs occur. in ex, delete should not be necess.
 fl:=smemberl(append(ftem_,for each h in fsub_ collect car h),ex)$  % functions occuring in ex
 forg:=for each h in forg collect
       if atom h then
       if f=h then <<put(f,'fcts,fl)$was_subst:=t$
                     list('equal,f,if pairp ex and (car ex='!*sq) then cadr   ex 
                                                                  else simp!* ex )>>
              else h
                 else 
       if (car h='equal) and member(f,get(cadr h,'fcts)) then <<
        was_subst:=t$
        dnr:=simp!* {'!*sq,subf(denr caddr h,{(f . ex)}),nil};
        if sqzerop dnr then <<contradiction_:=t$
         terpri()$write"##### ERROR: When substituting ",f," by ",ex,
                       " in the denominator of the forg entry: ",h,
                       " then the denominator becomes zero!! #####"$ 
         terpri()$
         nil
        >>             else <<
         h:=list('equal,cadr h,
                 simp!* {'!*sq,quotsq(subf(numr caddr h,{(f . ex)}),dnr),nil});
         % h:=list('equal,cadr h,simp!* {'!*sq,subsq(caddr h,{(f . ex)}),nil});
         % - simp!* {'!*sq,..,nil} to simplify poly using identities, like i^2 -> -1
         put(cadr h,'fcts,
             smemberl(union(fl,delete(f,get(cadr h,'fcts))),caddr h));
         h
        >>
       >>                                                else h$
 return (forg . was_subst)
end$

symbolic procedure do_subst(md,p,l,pde,forg,vl,plim,keep_eqn)$
% md is the mode of substitution (1='fcteval_lin,..., 6='fct_nli_nus)
% (md is needed in case of an ISE)
% Use equation p for substitution.
% l incodes the substitution itself = (cf . f)
% Substitute a function in all pdes.
begin scalar f,fl,h,ex,res,slim,too_large,was_subst,new_user_rules,
             ruli,ise,cf,vl,nof,stde,partial_subs,ineq_bak,ineq_or_bak$
% l:=get(p,'fcteval_lin)$
% if null l then l:=get(p,'fcteval_nca)$
% if null l then l:=get(p,'fcteval_nli)$
% if l then << % l:=car l$
  f:=cdr l$
  cf:=car l$

  % at first check whether f can be added to flin_
  if flin_ and vl_ 
  % - We can not do a test 'if get(p,'fcteval_n2l) then '
  %   because fcteval_n2l does only know about allvarfct functions in flin_
  % - We test 'and vl_' because this is much cheaper than freeof and
  %   currently (Dec 2010) non-linear substitutions have a lower priority
  %   than any flin_ substitutions, even if they are case generating.
     and freeof(flin_,f) and null add2flin(pde,f) then << 
   % f is not occuring linearly wrt. flin_ therefore remove all functions 
   % of this equation from flin_ 
   for each h in get(p,'fcts) do
   if not freeof(flin_,h) then flin_:=delete(h,flin_)
  >>$

  if get(p,'starde) then ise:=t;
  slim:=get(p,'length)$
  ruli:=start_let_rules()$
  if modular_comp then on modular$
  ex:={'!*sq,subs2 quotsq(subtrsq(multsq(cf,simp f),get(p,'sqval)),cf),t};
  % ex:={'!*sq,simp!* {'!*sq,quotsq(subtrsq(multsq(cf,simp f),get(p,'sqval)),cf),nil},t};
  % - simp!* {'!*sq,..,nil} to simplify poly using identities, like i^2 -> -1

  % When the right hand side of a substitution becomes identical to the left
  % hand side due to LET rules then there is no point in performing the
  % substitution. But the equation used to formulate the substitution 
  % is deleted because it is used for the substitution so all that is left is
  % the set of LET rules. :-(

%#######################
% CHECK WHETHER f==ex and then drop all LET RULES and add them as equations.
%#######################

  % This substitution might give a contradiction when being done to an
  % equation. But if this equation is used as a LET rule then that
  % contradicting substitution may turn a denominator of in forg to zero when
  % the contradicted LET rule is used in the substitution in forg. To avoid
  % the error message that a denominator in forg is zero, in the following 
  % it is checked whether a LET rule is contradicted by the substitution.

  for each h in cdr userrules_ do  %  h = {replaceby,cadr h,caddr h}, cadr h => caddr h
  if not freeof(cdr h,f) and
     ({(1 . 1)} = simplifySQ(subsq(subtrsq(simp cadr h,simp caddr h),
                                   {(f . ex)}), ftem_, t, nil, nil)) then <<
   contradiction_:=t$
   if print_ then <<
    write"The current substitution"$terpri()$
    algebraic(write lisp f," = ", lisp ex)$
    write"results in a contradiction in the LET rule:"$
    algebraic (write lisp {'list,h})$
   >> 
  >>$

  %---- specification of substitution in case of expert_mode (user guided)
  if not contradiction_ then 
  if expert_mode then <<
   terpri()$
   write"Enter a list of equations in which substitution should take place."$
   terpri()$
   write"Substitution into the expressions for the original functions and"$
   terpri()$
   write"the inequalities is only done if you select all equations with `;' ."$
   l:=select_from_list(pde,nil)$
   if l then <<
    if not_included(pde,l) then partial_subs:=t
                           else partial_subs:=nil;
    l:=delete(p,l)
   >>;
   if partial_subs then <<
    change_prompt_to ""$ 
    terpri()$
    write"Should substitutions be done in the inequalities? (y/nil)"$
    repeat h:=reval termread() until (h=t) or (h=nil)$
    restore_interactive_prompt()
   >>
  >>             else l:=delete(p,pde)$

  %---- substitution in LET-rules
  if not contradiction_ then <<
   for each h in cdr userrules_ do  %  h = {replaceby,cadr h,caddr h}, cadr h => caddr h
   if freeof(cadr  h,f) then 
   if freeof(caddr h,f) then new_user_rules:=cons(h,new_user_rules)
                        else <<
    if print_ then <<
     terpri()$
     write"The current substitution"$terpri()$
     algebraic(write lisp f," = ", lisp ex)$
     write"affects the following LET rule:"$terpri()$
     algebraic (write lisp {'list,h})
    >>$
    algebraic(clearrules lisp {'list,h});
    h:={car h, cadr h, mk!*sq subsq(simp caddr h,{(f . ex)})};
    if print_ then <<
     write"which therefore is modified to:"$
     algebraic (write lisp {'list,h})$
    >>$
    new_user_rules:=cons(h,new_user_rules);
    algebraic(let lisp {'list,h});
   >>                   else <<
   if print_ then <<
     terpri()$
     write"The current substitution affects the following LET rule"$terpri()$
     write"which therefore has to be deleted:"$
     algebraic (write lisp {'list,h})
    >>$
    pde:=moverule2eqn(h,pde)$ 
   >>$
   userrules_:=cons('list,reverse new_user_rules)$
  >>$

  %---- substitution in inequalities
  if not contradiction_ then <<
   ineq_bak:=ineq_$             % for the case that no substitution is done
   ineq_or_bak:=ineq_or$        %                   "
   if (not ise) and ((not partial_subs) or h) then %ineqsubst(ex,f,ftem_,pde)$
                                        simp_all_ineq_with_subst_SQ(ex,f,pde)$
  >>$

  if not contradiction_ then <<

   %--- substitution in forg
   if (not ise) and (not partial_subs) then 
   if lazy_eval and null lin_problem then <<
    was_subst:=t$
    fsub_:=cons((f . ex),fsub_)$
    % alternatively:
    %h:=cons(0,forg)$
    %forg:=h$
    %while cdr h and f neq cadr forg do h:=cdr h$
    %if cdr h then <<% f is found and still unevaluated
    % replacd(h,cons((f . ex),cddr forg))$
    % put(f,'fcts,smemberl(ftem_,ex))
    %>>       else fsub_:=cons((f . ex),fsub_)$
    %forg:=cdr forg$
   >>           else <<
    was_subst:=sub_in_forg(f,ex,forg);
    forg:=car was_subst;
    was_subst:=cdr was_subst
   >>$

   % The following test depends on the global structure, taken out
   % for the time being:
   %% no substitution in equations which do not include all functions
   %% of all variables in ex
   %h:=nil;
   %fl:=get(p,'allvarfcts);
   %while l do <<
   % if not_included(fl,get(car l,'fcts)) then too_large:=t
   %                                      else h:=cons(car l,h);
   % l:=cdr l
   %>>;
   %l:=h;
   % Do the substitution in all suitable equations

   if ise and not contradiction_ then << % if the equation to be used, ie. p, 
    % is a star-equation then collecting suitable equations for substitution
    h:=nil;
    vl:=get(p,'vars)$
    fl:=get(p,'fcts)$
    nof:=caar get(p,'starde)$
    while l do <<
     if (stde:=get(car l,'starde)) and
        (nof<=caar stde) and
        (not not_included(vl,get(car l,'vars))) and
        (not not_included(fl,get(car l,'fcts))) then h:=cons(car l,h);
     l:=cdr l
    >>$
    l:=h;
   >>$

   while l and not contradiction_ do <<
   if member(f,get(car l,'fcts)) then
    if not expert_mode and plim and (slim*get(car l,'length)>plim)
    then too_large:=t
    else <<
     pde:=eqinsert(do_one_subst(ex,f,car l,ftem_,union(vl,get(car l,'vars)),
                                get(p,'level),p,pde),delete(car l,pde))$
     for each h in pde do drop_rl_with(car l,h);         
     put(car l,'rl_with,nil);
     for each h in pde do drop_dec_with(car l,h,'dec_with_rl);     
     put(car l,'dec_with_rl,nil);
     flag(list car l,'to_int);
     was_subst:=t
    >>$
    l:=cdr l
   >>$
   if print_ and (not contradiction_) and was_subst then <<
    terpri()$write "Substitution of "$
    fctprint list f$
    if cdr get(p,'fcts) then <<
     write " by an "$
     if ise then write"(separable) "$
     write "expression in "$terpri()$
     fctprint delete(f,get(p,'fcts))
    >>$
    write " found in ",p," : "$
    eqprint(list('equal,f,ex))
   >>$
   % To avoid using p repeatedly for substitutions of different
   % functions in the same equations:
   if ise and not contradiction_ then <<
    put(p,'fcteval_lin,nil);
    put(p,'fcteval_nca,nil);
    put(p,'fcteval_nli,nil);
    remflag1(p,'to_eval)$ % otherwise 'fcteval_??? would be computed again
    md:=md;   % only in order to do something with md if the next
              % statement is commented out
    % if too_large then
    % if md=1 then put(p,'fcteval_lin,list((cf . f))) else
    % if md=2 then put(p,'fcteval_nca,list((cf . f))) else
    %              put(p,'fcteval_nli,list((cf . f)))$  
    % could probably unnecessarily be repeated
   >>;
   % delete f and p if not anymore needed
   if (not ise) and 
      (not keep_eqn) and
      (not too_large) and 
      (not partial_subs) and
      (not contradiction_) then <<
    %if not assoc(f,depl_copy_) then <<
    if (null lazy_eval) or lin_problem then <<
      h:=t;
      for each l in forg do 
      if pairp l then if cadr l=f then h:=nil else
                 else if l=f then h:=nil;
      if h then drop_fct(f)$
    >>$
    %>>$
    was_subst:=t$            % in the sense that pdes have been updated
    ftem_:=delete(f,ftem_)$
    flin_:=delete(f,flin_)$
    pde:=drop_pde(p,pde,0)$
   >>$
%   if was_subst then 
   res:=list(pde,forg,p)  
   % also if not used to delete the pde if the function to be
   % substituted does not appear anymore
  >>$
  if modular_comp then off modular$
  stop_let_rules(ruli)$
% >>$
 if null was_subst then <<ineq_:=ineq_bak; ineq_or:=ineq_or_bak>>$
 if not contradiction_ then return cons(was_subst,res)$
end$


symbolic procedure make_subst(pdes,forg,vl,l1,length_limit,pdelimit,
                              less_vars,no_df,no_cases,lin_subst,
                              min_growth,cost_limit,keep_eqn,sub_fc)$
% make a subst. 
% l1 is the list of possible "candidates"
begin scalar p,q,r,l,h,hh,h3,cases_,w,md,tempchng,plim,mod_switched$   % ,ineq,cop,newfdep

  for each h in l1 do
  if not freeof(pdes,h) then l:=cons(h,l);
  if l1 and null l then return nil
                   else l1:=reverse l$
  l:=nil;
  if expert_mode then <<
   write"Which PDE should be used for substitution?"$ terpri()$
   l1:=selectpdes(pdes,1)$
  >>;
  % a fully specified substitution from to_do_list
  if sub_fc and % a specific function sub_fc is to be substituted using a
                % specific equation car l1
     l1 and null cdr l1 then <<
   p:=car l1$

   if null fcteval(p) then 
   if print_ then <<
    write"##### Strange: equation ",p," was to be solved for ",sub_fc,
         " but facteval says that is not possible."$ 
    terpri()
   >>$

   h:=get(p,'fcteval_lin);
   while h and (sub_fc neq cdar h) do h:=cdr h;
   if h then hh:=1 
        else <<
    h:=get(p,'fcteval_nca);
    while h and (sub_fc neq cdar h) do h:=cdr h;
    if h then hh:=2
         else <<
     h:=get(p,'fcteval_nli);
     while h and (sub_fc neq cdar h) do h:=cdr h;
     if h then hh:=3
    >>
   >>;
   if h then w:={hh,car l1,car h}
  >>;

  if sub_fc and null w then return nil;

again:
  if (sub_fc and w)                                                       or
     (min_growth and (w:=err_catch_minsub(pdes,l1,cost_limit,no_cases)) ) or
     ((null min_growth                                            ) and
      (w:=get_subst(pdes,l1,length_limit,less_vars,no_df,no_cases))     ) then 
      % w has form {mdu,p,(cf . f)} , cf is in SQ form
  if null !*batch_mode and null expert_mode and confirm_subst and <<

    if print_ then <<
      terpri()$
      write"Proposal: Substitution of  ",cdaddr w$terpri()$
      write"          using equation ",cadr  w,": "$
    >>;
    if print_ and (get(cadr w,'printlength)<=print_) then print_stars(cadr w)$
    if print_ then <<typeeq(cadr  w)$terpri()>>$

    if car w<=2 then write"No case distinctions will be necessary."
                else write"Case distinctions will be necessary."$
    terpri()$
    write"The coefficient is:"$ mathprint factorize {'!*sq,caaddr w,t}$
    write"Accept? (Enter y or n or p for stopping substitution) "$
    change_prompt_to ""$ 
    repeat h:=termread() until (h='y) or (h='n) or (h='p);
    restore_interactive_prompt()$ 
    if h='n then <<
      tempchng:=cons(w,tempchng);
      if car w=1 then <<hh:=get(cadr w,'fcteval_lin);
                        hh:=delete(caddr w,hh);
                        put(cadr w,'fcteval_lin,hh)>> else
      if car w=2 then <<hh:=get(cadr w,'fcteval_nca);
                        hh:=delete(caddr w,hh);
                        put(cadr w,'fcteval_nca,hh)>> else
                      <<hh:=get(cadr w,'fcteval_nli);
                        hh:=delete(caddr w,hh);
                        put(cadr w,'fcteval_nli,hh);
        if car w=3 then <<hh:=get(cadr w,'fct_nli_lin);
                          hh:=delete(caddr w,hh);
                          put(cadr w,'fct_nli_lin,hh)
                        >> else
        if car w=4 then <<hh:=get(cadr w,'fct_nli_nca);
                          hh:=delete(caddr w,hh);
                          put(cadr w,'fct_nli_nca,hh)
                        >> else
        if car w=5 then <<hh:=get(cadr w,'fct_nli_nli);
                          hh:=delete(caddr w,hh);
                          put(cadr w,'fct_nli_nli,hh)
                        >> else
        if car w=6 then <<hh:=get(cadr w,'fct_nli_nus);
                          hh:=delete(caddr w,hh);
                          put(cadr w,'fct_nli_nus,hh)
                        >> 
                      >>;
      if null hh and
         null get(cadr w,'fcteval_lin) and 
         null get(cadr w,'fcteval_nca) and 
         null get(cadr w,'fcteval_nli) then remflag1(cadr w,'to_eval)
      % otherwise 'fcteval_lin,... will be reassigned
    >>;
    if (h='p) then l1:=nil;
    if (h='n) or (h='p) then t else nil 
  >> then goto again
     else
  if (   car w = 1)                             or
     ((lin_subst=nil)                     and
      ( (car w = 2)                  or
       ((car w > 2)            and 
        member(caaddr w,ineq_)     )    )     ) then <<

   if pdelimit and in_cycle({'subst,stepcounter_,cdaddr w,
                             get(cadr w,'printlength),pdelimit})
                             % function, printlength of equation
   then plim:=nil
   else plim:=pdelimit;

   l:=do_subst(car w,cadr w,caddr w,pdes,forg,vl,plim,keep_eqn)$
   if l and null car l then << % not contradiction but not used
    l1:=delete(cadr w,l1);
    if l1 then <<
     pdes:=cadr l;
     forg:=caddr l;     
     l:=nil;
     goto again
    >>    else l:=nil
   >>;
   if l then <<
    l:=cdr l;
    add_to_last_steps({'subst,stepcounter_,cdaddr w,
                       get(cadr w,'printlength),pdelimit})
   >>
  >>                                            else 
  if (null lin_subst) and (null no_cases) then <<
    md:=car w;   % md = type of substitution, needed in case of ISE
    p:=cadr  w;  % p = the equation
    w:=caddr w;  % w = (coeff . function)
    if pdelimit and in_cycle({'subst,stepcounter_,w,
                              get(p,'printlength),pdelimit}) % (eqn,function)
    then pdelimit:=nil;
    backup_to_file(pdes,forg,nil)$

    % make an equation from the coefficient
    q:=mkeqSQ(car w,nil,nil,get(p,'fcts),get(p,'vars),allflags_,
              t,list(0),nil,pdes)$
    % and an equation from the remainder
    r:=nil;
    if not contradiction_ then <<
      hh:=subtrsq(get(p,'sqval),multsq(car w,simp cdr w))$
      if not sqzerop hh then 
      r:=mkeqSQ(hh,nil,nil,get(p,'fcts),get(p,'vars),
                allflags_,t,list(0),nil,pdes)
    >>;
    if contradiction_ then <<
      if print_ then << 
       write"Therefore no special investigation whether the "$
       terpri()$
       write"coefficient of a function to be substituted is zero."$
      >>$
      contradiction_:=nil$
      h:=restore_backup_from_file(pdes,forg,nil)$
      pdes:= car h; 
      forg:=cadr h;
      delete_backup()$
      if null q then h:={car w}
                else <<
       h:=get(q,'fac)$
       if not pairp h then h:={get(q,'sqval)}
      >>$
      for each l in h do % (was: .. in cdr h) % pdes:=  %  <=<=<=<=
      addSQineq(pdes,l,if q then nil else t)$ % nil if l already simplified
      drop_pde(q,nil,nil)$
      if r then drop_pde(r,nil,nil)$
      l:=do_subst(md,p,w,pdes,forg,vl,pdelimit,keep_eqn)$

      if l and null car l then << % not contradiction but not used
       l1:=delete(p,l1);
       if l1 then <<
	pdes:=cadr l;
	forg:=caddr l;     
        l:=nil;
	goto again
       >>    
      >>;
      if l then <<
       l:=cdr l;
       add_to_last_steps({'subst,stepcounter_,cdr w,
                          get(p,'printlength),pdelimit})
      >>

    >>                else <<
      % Generation of two equation does not instantly generate a contradiction
      remflag1(p,'to_eval)$
      if print_ then <<
        terpri()$
        write "for the substitution of ",cdr w," by ",p$
        write " we have to consider the case 0=",q,": "$
        eqprint list('equal,0,{'!*sq,car w,t})
      >>$
      pdes:=eqinsert(q,drop_pde(p,pdes,nil))$
      if freeof(pdes,q) then <<
        % The coefficient must be zero --> only one case, no substitution
        if print_ then <<
          terpri()$
          write "It turns out that the coefficient of ",cdr w," in ",
                p," is zero due"$
          terpri()$
          write "to other equations. Therefore no substitution is made and"$
          terpri()$
          write "equation ",p," will be updated instead."$
          terpri()
        >>$
        h:=restore_backup_from_file(pdes,forg,nil)$
        pdes:= car h; 
        forg:=cadr h;
        delete_backup()$
        if modular_comp and null !*modular then <<on modular$ mod_switched:=t>>$
        hh:=subtrsq(get(p,'sqval),multsq(car w,simp cdr w))$
        if mod_switched then off modular$
        if sqzerop hh then <<drop_pde(p,pdes,nil); pdes:=delete(p,pdes)>>
                      else <<
          updateSQ(p,hh,nil,nil,get(p,'fcts),get(p,'vars),t,list(0),pdes)$
          drop_pde_from_idties(p,pdes,nil)$ % new history is nil as r has no history
          drop_pde_from_properties(p,pdes)
        >>$
        drop_pde(q,pdes,nil); % q is not in pdes but nevertheless
        if r then drop_pde(r,pdes,nil); % r is not in pdes but nevertheless
        l:=list(pdes,forg,p)  
      >>                else <<
        % Setting the coefficient to zero does not give a contradiction
        % and is not an obvious consequence of other equations
        if r then pdes:=eqinsert(r,pdes)$      
        if print_ then <<
          write"The coefficient to be set = 0 in the first subcase is:"$
          %h:=print_all;          print_all:=t;
          hh:=print_;            print_:=30;
          typeeqlist(list q);
          %print_all:=h;
          print_:=hh
        >>$
        % To try to use q=0 for a substitution if possible:
        to_do_list:=cons(list('subst_level_35,{q}),to_do_list)$
        cp_sq2p_val(q)$
        h3:=get(q,'pval)$
        start_level(1,list {'equal,0,h3})$

        h:=get(q,'fac)$    % to add it to ineq_ afterwards
        if not pairp h then h:={get(q,'sqval)}$

        recycle_fcts:=nil$
        l:=crackmain_if_possible_remote(pdes,forg)$
        hh:=restore_and_merge(l,pdes,forg)$

        pdes:= car hh; 
        forg:=cadr hh; % was not assigned above as it has not changed probably
        delete_backup()$
        start_level(2,list {'ineq,0,h3})$
        if print_ then <<
          terpri()$
	  write "now back to the substitution of ",cdr w," by ",p$
        >>$
        for each h3 in h do % pdes:=  % <=<=<=<=
        addSQineq(pdes,h3,nil); 
        fcteval p$ % fcteval_... properties were deleted in addSQineq
        if contradiction_ then <<cases_:=t$contradiction_:=nil>> % but no
                               % further investigation of this case
                          else <<
	  % If one of the factors of q was an overall factor of the 
	  % equation, i.e. if car w is not anymore the coefficient of f 
	  % in p then new determination of car w (coeff. of f) is needed
	  hh:=coeffn({'!*sq,get(p,'sqval),t},cdr w,1);
	  w:=(if pairp hh and (car hh='!*sq) then cadr hh
					     else simp hh) . cdr w;

% The following lines are commented out (16.5.2008) because:
% - if contradiction_ then this must come from addSQineq (because it was
%   set to nil in restore_and_merge()) and then there is no solution in
%   this case,
% - if the substitution crashes then there is no backup file for this
%   second case, so the substitution should be done in the crackmain() call
% - there should be no jump to again: and no misslabeling of cases occur
% instead this substitution is written into the to_do list to be done first
% in the crackmain call
%
%	  if contradiction_ or null l then <<
%	      contradiction_:=nil$
%	      l:=do_subst(md,p,w,pdes,forg,vl,pdelimit,keep_eqn)$
%%	      if l and null car l then << % not contradiction but not used
%		l1:=delete(p,l1);
%		if l1 then <<
%		  pdes:=cadr l;
%		  forg:=caddr l;     
%		  l:=nil;
%		  goto again
%		>>    
%	      >>;
%	      if l then <<
%		l:=cdr l;
%		add_to_last_steps({'subst,stepcounter_,cdr w,
%                                  get(p,'printlength),pdelimit})
%	      >>
%
%	  >>                else <<

%         New, instead of substitution:
          to_do_list:=cons(cons('subst_level_35,
                                if sub_fc then {{p},sub_fc}
                                          else {{p}}),
                           to_do_list)$

	    % To avoid a loop the picked w='fcteval_nli is now stored as
	    % w='fcteval_nca
	    if md>2 then <<
	      h:=get(p,'fcteval_nli)$
	      if member(w,h) then << % otherwise p had just one term
		% where the non-zero coefficient was a factor which
		% is dropped by now, i.e. no further fix needed.
		% More generally, in addineq() and updateSQfcteval()
		% the following should be unnecessary by now
		h:=delete(w,h)$
		put(p,'fcteval_nli,h)$
		put(p,'fcteval_nca,cons(w,get(p,'fcteval_nca)))$
		if md=3 then <<          
		  h:=get(p,'fct_nli_lin)$
		  h:=delete(w,h)$
		  put(p,'fct_nli_lin,h)$
		>>      else
		if md=4 then <<          
		  h:=get(p,'fct_nli_nca)$
		  h:=delete(w,h)$
		  put(p,'fct_nli_nca,h)$
		>>      else
		if md=5 then <<          
		  h:=get(p,'fct_nli_nli)$
		  h:=delete(w,h)$
		  put(p,'fct_nli_nli,h)$
		>>      else
		if md=6 then <<          
		  h:=get(p,'fct_nli_nus)$
		  h:=delete(w,h)$
		  put(p,'fct_nli_nus,h)$
		>>
	      >> 
	    >>$
	    cases_:=t$
	    % no backup of global data
	    h:=crackmain_if_possible_remote(pdes,forg)$
	    % No recovery of global data as this crackmain will end now too.

	    % Because no data are changed, computation could just continue
	    % without crackmain() sub-call but then combining the
	    % different results would be difficult.
	    % No delete_backup() as this has already been done.
	    if contradiction_ then contradiction_:=nil
			      else l:=merge_crack_returns(h,l)
%	  >>
	>>
      >>
    >>$
  >>$

  if null !*batch_mode and null expert_mode and confirm_subst then
  while tempchng do <<
    w:=car tempchng; tempchng:=cdr tempchng;
    if car w=1 then <<hh:=get(cadr w,'fcteval_lin);
                      hh:=cons(caddr w,hh);
                      put(cadr w,'fcteval_lin,hh)>> else
    if car w=2 then <<hh:=get(cadr w,'fcteval_nca);
                      hh:=cons(caddr w,hh);
                      put(cadr w,'fcteval_nca,hh)>> else
                    <<hh:=get(cadr w,'fcteval_nli);
                      hh:=cons(caddr w,hh);
                      put(cadr w,'fcteval_nli,hh);
      if car w=3 then <<hh:=get(cadr w,'fct_nli_lin);
                        hh:=cons(caddr w,hh);
                        put(cadr w,'fct_nli_lin,hh)>> else
      if car w=4 then <<hh:=get(cadr w,'fct_nli_nca);
                        hh:=cons(caddr w,hh);
                        put(cadr w,'fct_nli_nca,hh)>> else
      if car w=5 then <<hh:=get(cadr w,'fct_nli_nli);
                        hh:=cons(caddr w,hh);
                        put(cadr w,'fct_nli_nli,hh)>> else
      if car w=6 then <<hh:=get(cadr w,'fct_nli_nus);
                        hh:=cons(caddr w,hh);
                        put(cadr w,'fct_nli_nus,hh)>> 
                    >>;
    flag1(cadr w,'to_eval)
  >>$

  return if contradiction_  then nil % list(nil,nil) 
                            else if cases_ then list l
                                           else l$
end$


symbolic procedure subst_level_0(arglist)$             % module 3
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_0,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            t,                                         % less_vars
            nil,                                       % no_df
            t,                                         % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_03(arglist)$            % module 4
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_0,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            t,                                         % no_df
            t,                                         % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_04(arglist)$            % module 45
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_1,                                   % length_limit for pde to use
            target_limit_1,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            t,                                         % no_df
            t,                                         % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_05(arglist)$            % module 5
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_3,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            t,                                         % no_df
            t,                                         % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_1(arglist)$             % module 15
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_1,                                   % length_limit for pde to use
            target_limit_2,                            % pdelimit for pdes to be changed
            t,                                         % less_vars
            nil,                                       % no_df
            nil,                                       % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_2(arglist)$             % module 18
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_3,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            t,                                         % less_vars
            nil,                                       % no_df
            t,                                         % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_3(arglist)$             % module 16
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_2,                                   % length_limit for pde to use
            target_limit_1,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            nil,                                       % no_df
            nil,                                       % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_33(arglist)$            % module 19
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_3,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            nil,                                       % no_df
            t,                                         % no_cases
            t,                                         % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_35(arglist)$            % module 20
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_3,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            nil,                                       % no_df
            t,                                         % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_4(arglist)$             % module 21
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_3,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            nil,                                       % no_df
            nil,                                       % no_cases
            nil,                                       % lin_subst
            nil,                                       % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_45(arglist)$            % module 6
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_3,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            nil,                                       % no_df
            t,                                         % no_cases
            nil,                                       % lin_subst
            t,                                         % min_growth
            cost_limit5,                               % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$

symbolic procedure subst_level_5(arglist)$             % module 17
make_subst( car arglist,                               % all pdes
            cadr arglist,caddr arglist,                % forg,vl
            cadddr arglist,                            % pdes to choose from
            subst_3,                                   % length_limit for pde to use
            target_limit_3,                            % pdelimit for pdes to be changed
            nil,                                       % less_vars
            nil,                                       % no_df
            nil,                                       % no_cases
            nil,                                       % lin_subst
            t,                                         % min_growth
            nil,                                       % cost_limit
            nil,                                       % keep_eqn
            if length arglist > 4 then nth(arglist,5) 
                                  else nil             % sub_fc
           )$


symbolic procedure best_fac_pde(pdes)$
% pdes must be pdes for which their 'fac property is pairp
begin scalar p,md,mdgr,mtm,f,dgr,f,tm,bestp;
 md:=1000; mtm:=100000;
 for each p in pdes do <<
  % compute the max degree of any factor
  mdgr:=0$ 
  for each f in get(p,'fac) do <<
   dgr:=pde_degree_SQ(f,smemberl(get(p,'rational),f))$
   if dgr>mdgr then mdgr:=dgr
  >>$
  tm:=get(p,'length)$
  if (mdgr<md) or ((mdgr=md) and (tm<mtm)) then 
  <<bestp:=p; md:=mdgr; mtm:=tm>>;
 >>;
 return {bestp,md,mtm}
end$

algebraic procedure start_let_rules$
begin scalar ruli;
  lisp (oldrules!*:=nil)$  % to fix a REDUCE bug
  ruli:={};
  if cot(!%x) neq (1/tan(!%x)) then let explog_$
  if lisp(userrules_) neq {} then let lisp userrules_$
  if sin(!%x)**2+cos(!%x)**2 neq 1         then <<ruli:=cons(1,ruli);let trig1_>> else ruli:=cons(0,ruli)$
  if cosh(!%x)**2 neq (sinh(!%x)**2 + 1)   then <<ruli:=cons(1,ruli);let trig2_>> else ruli:=cons(0,ruli)$
  if sin(!%x)*tan(!%x/2)+cos(!%x) neq 1    then <<ruli:=cons(1,ruli);let trig3_>> else ruli:=cons(0,ruli)$
  if sin(!%x)*cot(!%x/2)-cos(!%x) neq 1    then <<ruli:=cons(1,ruli);let trig4_>> else ruli:=cons(0,ruli)$
  if cos(2*!%x) + 2*sin(!%x)**2   neq 1    then <<ruli:=cons(1,ruli);let trig5_>> else ruli:=cons(0,ruli)$
  if sin(2*!%x) neq 2*cos(!%x)*sin(!%x)    then <<ruli:=cons(1,ruli);let trig6_>> else ruli:=cons(0,ruli)$
  if sinh(2*!%x) neq 2*sinh(!%x)*cosh(!%x) then <<ruli:=cons(1,ruli);let trig7_>> else ruli:=cons(0,ruli)$
  if cosh(2*!%x) neq 2*cosh(!%x)**2-1      then <<ruli:=cons(1,ruli);let trig8_>> else ruli:=cons(0,ruli)$
  if sqrt(!%x*!%y) neq sqrt(!%x)*sqrt(!%y) then <<ruli:=cons(1,ruli);let sqrt1_>> else ruli:=cons(0,ruli)$
  if sqrt(!%x/!%y) neq sqrt(!%x)/sqrt(!%y) then <<ruli:=cons(1,ruli);let sqrt2_>> else ruli:=cons(0,ruli)$
  return ruli;
end$

algebraic procedure stop_let_rules(ruli)$
begin
  clearrules explog_$
  if (lisp(userrules_) neq {}) and
     (lisp (zerop reval {'difference,
                         car  cdadr userrules_,
                         cadr cdadr userrules_}))
                    then clearrules lisp userrules_$
  if first ruli = 1 then clearrules sqrt2_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules sqrt1_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig8_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig7_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig6_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig5_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig4_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig3_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig2_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig1_$ ruli:=rest ruli$
end$

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  procedures  for finding an optimal substitution  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure fbts(a,b)$
% fbts ... first better than second
(cadr   a <= cadr   b) and 
(caddr  a <= caddr  b) and 
(cadddr a <= cadddr b)$


symbolic procedure list_subs(p,fevl,fli,mdu)$
% p is an equation, fevl a substitution list of p,
% fli is a list of lists (f,p1,p2,..) where 
%   f is a function, 
%   pi are lists (eqn,nco,nte,mdu) where
%   eqn is an equation that can be used for substituting f
%   nco is the number of terms of the coefficient of f in the eqn
%   nte is the number of terms without f in the eqn
%   mdu is the kind of substitution (1:lin, 2:nca, 3:nli)
% returns an extended fli
%
begin
 scalar a,f,nco,nte,cpy,cc,ntry;
 for each a in fevl do <<
  f:=cdr a;
%  nco:=no_of_terms(car a);   
  nco:=no_of_tm_sf numr car a; 
  nte:=get(p,'terms);
  nte:=if nte=1 then 0 
                else nte-nco$
  ntry:={p,nco,nte,mdu}$

  % Is there already any substitution list for f?
  cpy:=fli;
  while cpy and (f neq caar cpy) do cpy:=cdr cpy$
  if null cpy then fli:=cons({f,ntry},fli) % no, there was not
              else <<                      % yes, there was one
   cc:=cdar cpy$
   while cc and (null fbts(car cc,ntry)) do cc:=cdr cc$
   if null cc then << % ntry is at least in one criterium better 
                      % than a known one
    rplaca(cpy,cons(f,cons(ntry,cdar cpy)));
    cc:=cdar cpy$ % just the list of derivatives with ntry as the first
    while cdr cc do 
    if fbts(ntry,cadr cc) then rplacd(cc,cddr cc)
                          else cc:=cdr cc$
   >>
  >>
 >>;
 return fli
end$

symbolic procedure cwrno(n,r)$
% number of terms of (a1+a2+..+an)**r if ai are pairwise prime
% number of combinations of r factors out of n possible factors
% with repititions and without order = (n+r-1 over r)
<<n:=n+r-1;
  % The rest of the procedure computes binomial(n,r).
  if 2*r>n then r:=n-r;
  (for i:=1:r product (n+1-i))/
  (for i:=1:r product    i   )
>>$

symbolic procedure besu(ic1,mdu1,ic2,mdu2)$
% Is the first substitution better than the second?
((mdu1<mdu2) and (ic1<=ic2)) or
((mdu1=mdu2) and (ic1< ic2)) or
% ########## difficult + room for improvement as the decision is
% actually dependent on how precious memory is 
% (more memory --> less cases and less time):
((mdu1=2) and (ic1<(ic2+ 4))) or
((mdu1=3) and (ic1<(ic2+25)))$

symbolic procedure search_subs(pdes,sbpdes,cost_limit,no_cases)$
% returns a list {mdu ,p ,car get(p,'fcteval_???)}, i.e. the 3rd argument is SQ
begin
 scalar fli,p,el,f,fpl,dv,drf,d,ffl,hp,ff,nco,be,s,nte,ic,fp,
        rm,mc,subli,mdu,tr_search,h$

 % at first find the list of all functions that could be substituted
 % using one of the equations sbpdes together with 
 % a list of such sbpdes, the number of terms in the coeff and 
 % the type of substitution

% tr_search:=t$

 for each p in sbpdes do fcteval(p)$

 % assuming that equations in sbpdes are sorted by size beginning with shortest
 fp:=sbpdes;
 h:=nil;
 while fp and null h do
 if get(car fp,'terms)>2 then fp:=nil else
 if null (h:=get(car fp,'fcteval_lin)) then fp:=cdr fp;
 if fp then return {1,car fp,car h}$

 while sbpdes do <<
  p:=car sbpdes; sbpdes:=cdr sbpdes;
  fli:=list_subs(p,get(p,'fcteval_lin),fli,1)$
  fli:=list_subs(p,get(p,'fcteval_nca),fli,2)$
  if null no_cases then fli:=list_subs(p,get(p,'fcteval_nli),fli,3)$

  if s then if get(p,'length)>(3*s) then sbpdes:=nil else else
  if fli then s:=get(p,'length)
 >>$

 if tr_search then <<
  write"equations substitution: (eqn, no of coeff. t., no of other t., mdu)"$
  terpri()$
  for each el in fli do <<write el;terpri()>>$
 >>$

 if fli then
 if (null cdr   fli) and  % one function
    (null cddar fli) then % one equation, i.e. no choice
 return <<
  fli:=cadar fli;  % fli is now (eqn,nco,nte,mdu)
  mdu:=cadddr fli;
  {mdu,car fli,car get(car fli,if mdu = 1 then 'fcteval_lin else
                               if mdu = 2 then 'fcteval_nca else
                                               'fcteval_nli)     }
 >>                  else
 % (more than 1 fct.) or (only 1 function and more than 1 eqn.)
 for each el in fli do << % for any function to be substituted
                          % (for the format of fli see proc list_subs)

  f:=car el$ el:=cdr el$  
  % el is now a list of possible eqn.s to use for subst. of f

  fpl:=nil$ % fpl will be a list  of lists (p,hp,a1,a2,..) where 
            % p is an equation that involves f,
            % hp the highest power of f in p
            % ai are lists {ff,cdr d,nco} where ff is a derivative of f, 
            % cdr d its power and nco the number of coefficients
  for each p in pdes do << % for each equation in which f could be subst.
   dv:=get(p,'derivs)$    %   ((fct var1 n1 ...).pow)
   drf:=nil$
   for each d in dv do 
   if caar d = f then drf:=cons(d,drf)$
   % drf is now the list of powers of derivatives of f in p

   ffl:=nil$      % ffl will be a list of derivatives of f in p
                  % together with the power of f and number of 
                  % terms in the coeff.
   if drf then << % f occurs in this equation and we estimate the increase
    hp:=0$
    for each d in drf do <<
     if cdar d then ff:=cons('df,car d)
               else ff:=caar d; 
     nco:=coeffn({'!*sq,get(p,'sqval),t},ff,cdr d);
     nco:=if pairp nco and (car nco='!*sq) then no_of_tm_sf numr cadr nco
                                           else 1;
     if cdr d > hp then hp:=cdr d$
     ffl:=cons({ff,cdr d,nco},ffl);
    >>
   >>;

   if drf then fpl:=cons(cons(p,cons(hp,ffl)),fpl);
  >>$

  % now all information about all occurences of f is collected and for
  % all possible substitutions of f the cost will be estimated and the 
  % cheapest substitution for f will be determined

  be:=nil; % be will be the best equation with an associated min. cost mc
  for each s in el do << 
   % for each possible equation that can be used to subst. for f

   % number of terms of (a1+a2+..+an)**r = n+r-1 over r
   % f = (a1+a2+..+a_nte) / (b1+b2+..+b_nco)
   nco:=cadr s; 
   nte:=caddr s;
   ic:= - get(car s,'terms);  % ic will be the cost associated with
                              % substituting f by car s and car s
                              % will be dropped after the substitution
   for each fp in fpl do 
   if (car s) neq (car fp) then <<
    rm:=get(car fp,'terms);   % to become the number of terms without f
    hp:=cadr fp;
    ic:=ic - rm;              % as the old eqn. car fp will be replaced
    for each ff in cddr fp do << % for each power of each deriv. of f
     ic:=ic + (caddr ff)*           % number of terms of coefficient of ff
              cwrno(nte,cadr ff)*      % (numerator of f)**(power of ff)
              cwrno(nco,hp - cadr ff); % (denom. of f)**(hp - power of ff)
     rm:=rm - caddr ff;       % caddr ff is the number of terms with ff 
    >>;
    % Now all terms containing f in car fp have been considered. The
    % remaining terms are multiplied with (denom. of f)**hp
    ic:=ic + rm*cwrno(nco,hp)
   >>;

   % Is this substitution better than the best previous one?
   if (null be) or besu(ic,cadddr s,mc,mdu) then 
   <<be:=car s; mc:=ic; mdu:=cadddr s>>;

  >>;

  % It has been estimated that the substitution of f using the 
  % best eqn be has an additional cost of ic terms 

  if tr_search and (length el > 1) then <<
   terpri()$
   write"Best substitution for ",f," : ",{ic,f,be,mdu}$
  >>$

  if (null cost_limit) or (ic<cost_limit) then 
  subli:=cons({ic,mdu,f,be},subli)$
 >>$

 % Now pick the best substitution
 if subli then <<
  s:=car subli;
  subli:=cdr subli;
  for each el in subli do
  if besu(car el,cadr el,car s,cadr s) then s:=el$

  if tr_search then <<
   terpri()$
   write"Optimal substitution:"$terpri()$
   write"  replace ",caddr s," with the help of ",cadddr s,","$terpri()$
   if car s < 0 then write"  saving ", - car s," terms, "
                else write"  with a cost of ",car s," additional terms, "$
   terpri()$
   write if cadr s = 1 then "  linear substitution" else
         if cadr s = 2 then "  nonlinearity inceasing substitution" else
                            "  with case distinction"  $
  >>$

  el:=get(cadddr s,if (cadr s) = 1 then 'fcteval_lin else
                   if (cadr s) = 2 then 'fcteval_nca else
                                        'fcteval_nli);
  while (caddr s) neq (cdar el) do el:=cdr el;

  return {cadr s,cadddr s,car el}
     % = {mdu   ,p       ,car get(p,'fcteval_???)}
 >>$

end$

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  procedures for doing a substitution `bottom up'  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure bottom_up_subst(arglist)$
% This procedure uses the gobal variable largest_fully_substituted_in
% which is the latest/largest equation in the list pdes of
% equations (when starting to count from the shortest) in which
% all possible substitutions of shorter equations have been done
% that do not lead to case distinctions.
% Only one substitution will be made because the result could be
% big and then it would be better to continue substituting in a 
% different shorter equation.

if currently_to_be_substituted_in = '!*SUBST_DONE!* then nil else

if (null car arglist) or (null cdar arglist)            then
<<currently_to_be_substituted_in:='!*SUBST_DONE!*;nil>> else

begin scalar pcp,found,pdes,fns,p,a,h;
 currently_to_be_substituted_in:=nil; % <-- for now as not in list 
                                      %     not_passed_back in crinit.red
 if null currently_to_be_substituted_in then
 currently_to_be_substituted_in:=cadar arglist;
 fns:=get(currently_to_be_substituted_in,'fcts);

 pcp:=car arglist;
 while (currently_to_be_substituted_in neq '!*SUBST_DONE!*) and
       null found do 

 if car pcp=currently_to_be_substituted_in then
 if null cdr pcp then currently_to_be_substituted_in:='!*SUBST_DONE!*
                 else <<
  currently_to_be_substituted_in:=cadr pcp;
  fns:=get(currently_to_be_substituted_in,'fcts);
  pcp:=car arglist
 >>                                        else 
 if << % Is substitution possible?
  p:=car pcp;
  if get(p,'starde) then nil
                    else <<
   a:=get(p,'fcteval_lin);
   if null a or freeof(fns,cdar a) then <<
    a:=get(p,'fcteval_nca);
    if a and freeof(fns,cdar a) then a:=nil
   >>;
   a
  >>
 >> then << % do substitution
  pdes:=car arglist$
  pdes:=eqinsert(do_one_subst(car a,cdr a,currently_to_be_substituted_in,
                              ftem_,get(currently_to_be_substituted_in,'vars),
                              get(p,'level),p,pdes),
                 delete(currently_to_be_substituted_in,pdes))$
  for each h in pdes do drop_rl_with(currently_to_be_substituted_in,h);         
  put(currently_to_be_substituted_in,'rl_with,nil);
  for each h in pdes do drop_dec_with(currently_to_be_substituted_in,h,'dec_with_rl);     
  put(currently_to_be_substituted_in,'dec_with_rl,nil);
  flag(list currently_to_be_substituted_in,'to_int);
  found:=t  
 >> else pcp:=cdr pcp; % Check next equation for substitution

 return
 if currently_to_be_substituted_in='!*SUBST_DONE!* then nil 
 else {pdes,cadr arglist}
end$


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  procedures  for substitution of a derivative by a new function  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure check_subst_df(pdes,forg)$       
%  yields a list of derivatives which occur in all
%  pdes and in forg
begin scalar l,l1,l2,n,cp,not_to_substdf$
 if pdes then <<
  for each s in pdes do l:=union(for each a in get(s,'derivs) 
                                   collect car a,l)$    % all derivs
  for each s in forg do 
  if pairp s then 
  l:=union(for each a in all_deriv_search_SF(numr caddr s,ftem_) collect car a,
     union(for each a in all_deriv_search_SF(denr caddr s,ftem_) collect car a,
     l))$

  for each s in fsub_ do 
  l:=union(for each a in all_deriv_search_SF(numr cadr cdr s,ftem_) collect car a,
     union(for each a in all_deriv_search_SF(denr cadr cdr s,ftem_) collect car a,
     l))$

  l1:=df_min_list(l)$
  l:=nil$
  for each s in l1 do 
  if pairp s and not member(car s,not_to_substdf) then <<
    l:=cons(cons('df,s),l)$
    not_to_substdf:=cons(car s,not_to_substdf)
  >> $

  % Derivatives of functions should only be substituted if the
  % function occurs in at least 2 equations or forg functions
  while l do <<
   n:=0; % counter
   cp:=pdes;
   while cp and (n<2) do <<
    if member(cadar l,get(car cp,'fcts)) then n:=add1 n;
    cp:=cdr cp
   >>;
   cp:=forg;
   while cp and (n<2) do <<
    if (pairp car cp) and (caar cp = 'equal) and
       member(cadar l,get(cadr car cp,'fcts)) then n:=add1 n;
    cp:=cdr cp
   >>;
   if n=2 then l2:=cons(car l,l2);
   l:=cdr l
  >>
 >>$
 return l2$
end$

symbolic procedure df_min_list(dflist)$     
%  yields the intersection of the derivatives of each function 
%  in the list of deriv. dflist.
%   e.g. dflist='((f x z) (g x) (g) (f y) (h x y) (h x z)) 
%   ==> result='(f g (h x))
if dflist then
begin scalar l,d,m,lmax$
while dflist do 
 <<m:=car dflist$
   dflist:=cdr dflist$
   l:=nil$
   while dflist do
    <<if (d:=df_min(car dflist,m)) then m:=d
       	     	      	       	   else l:=cons(car dflist,l)$
    dflist:=cdr dflist$
    >>$
   if pairp m and null cdr m then lmax:=cons(car m,lmax)
                             else lmax:=cons(m,lmax)$
   dflist:=l$
 >>$
return lmax$
end$

symbolic procedure df_min(df1,df2)$     
%  yields the intersection of derivatives df1,df2
%  e.g. df_min('(f x y),'(f x z))='(f x), df_min('(f x z),'(g x))=nil
<<if not pairp df1 then df1:=list df1$
  if not pairp df2 then df2:=list df2$
  if car df1=car df2 then 
  if (df1:=df_min1(cdr df1,cdr df2)) then cons(car df2,df1)
                                     else car df2
>>$

symbolic procedure df_min1(df1,df2)$    
begin scalar l,a$
while df1 do
 <<a:=car df1$
 if not zerop (a:=min(dfdeg(df1,car df1),dfdeg(df2,car df1))) then 
  l:=cons(car df1,l)$
 if a>1 then l:=cons(a,l)$
 df1:=cdr df1$
 if df1 and numberp car df1 then df1:=cdr df1>>$
return reverse l$
end$

symbolic procedure dfsubst_forg(p,g,d,forg)$   
% substitute the function d in forg by an integral g
% of the function p
for each h in forg collect
if pairp h and member(d,get(cadr h,'fcts)) then <<
 put(cadr h,'fcts,fctinsert(p,delete(d,get(cadr h,'fcts))))$
 % reval subst(g,d,h)
 {'equal,cadr h,simp {'!*sq,subsq(caddr h,{(d . {'!*sq,g,t})}),nil}}
 % {'equal,cadr h,simp!* {'!*sq,subsq(caddr h,{(d . {'!*sq,g,t})}),nil}}
 % - simp!* {'!*sq,..,nil} to simplify poly using identities, like i^2 -> -1
>>                                         else h$

symbolic procedure expand_INT(p,varlist)$  
if null varlist then p
else begin scalar v,n$
  v:=car varlist$
  varlist:=cdr varlist$
  if pairp(varlist) and numberp(car varlist) then
     <<n:=car varlist$
       varlist:=cdr varlist>>
  else n:=1$
  for i:=1:n do p:=list('int,p,v)$
  return expand_INT(p,varlist)
end$

symbolic procedure rational_less(a,b)$  
% a and b are two reval'ued rational numbers in prefix form
% It returns the boolean value of a<b
if (pairp a) and 
   (car a='quotient) then rational_less(cadr a,reval{'times,caddr a,b}) else 
if (pairp b) and
   (car b='quotient) then rational_less(reval{'times,caddr b,a},cadr b) else 
if (pairp a) and (car a='minus) then 
if (pairp b) and (car b='minus) then cadr a > cadr b 
                                else not rational_less(cadr a,reval{'minus,b})
                                else
if (pairp b) and (car b='minus) then 
if a<0 then not rational_less(reval{'minus,a},cadr b)
       else nil
                                else a<b$

symbolic procedure substitution_weight(k,l,m,n,p,q)$   
 % This function computes a weight for an equation to 
 % be used for a substitution
 % k .. number of occurences as factor, 
 % l .. total degree of factor as homogeneous polynomial, 
 % m .. number of appearances in eqns,
 % n .. number of terms
 % p .. a factor taking care of the number of lists in ineq_or
 %      and their length of which f is an element
 % q .. =1 if contains flin_ unknowns else =0
reval {'quotient,{'times,l,n,q},{'times,p,{'expt,{'plus,{'times,2,k},m},2}}}$

symbolic procedure test_factors_for_substitution(p,pv)$  
%  p is the equation, pv the list of factors
begin scalar h,h1,h4,h3$
% pv:=get(p,'fac)$
% if not pairp pv then return nil;
 h:=get(p,'split_test);
 if null h then << % check all factors whether they can be used for subst.
  h1:=pv$  % the list of factors in p
  h4:=t$
  % make an equation from the coefficient
  while h1 and h4 do <<
   h3:=mkeqSQ(car h1,nil,nil,get(p,'fcts),get(p,'vars),allflags_,
              t,list(0),nil,nil)$
   contradiction_:=nil$
   % the last argument is nil to avoid having a lasting effect on pdes
   h1:=cdr h1$
   fcteval(h3)$
   if not(get(h3,'fcteval_lin) or get(h3,'fcteval_nca)) then h4:=nil;
   drop_pde(h3,nil,nil)
  >>$
  h:=if h4 then 1  % p can be splited into substitutable equations
           else 0; % p can not be splited into only  "   equations
  put(p,'split_test,h)
 >>;
 return h
end$

symbolic procedure get_fact_pde(pdes,aim_at_subst)$   
% look for pde in pdes which can be factorized
begin scalar p,pv,f,fcl,fcc,h,h1,h2,h3,h4,h5,h6,h7,h8,eql,tr_gf$
 % tr_gf:=t$

 h1:=pdes;
 if null aim_at_subst then

 % Highest priority has an equation with a case2sep entry, i.e. which
 % allows to conclude either the independence of a function on a
 % variable or allows to do a direct separation.

 while h1 and null h2 do <<
  h3:=get(car h1,'case2sep)$ 
  if h3 then if not member(h3,ineq_) then h2:=car h1
                                     else <<
   put(car h1,'case2sep,nil)$
   h4:=stardep3(get(car h1,'vars),get(car h1,'kern),get(car h1,'derivs))$
   if h4 then <<put(car h1,'starde,{(0 . car h4)})$  flag1(car h1,'to_sep)>>$
   h1:=cdr h1
  >>    else h1:=cdr h1  
 >>$
 if h2 then return h2$        

 % now choose an equation that minimizes a weight computed from 
 % the weights of its factors, 
 % the weight of a factor = 
 % (if an atom then number of all equations it occurs 
 %  else the number of equations it occurs as a factor)/
 %  the total degree of this factor/
 %  the number of factors of the equation
 % The factor with the highest weight is to be set to 0 first.

 % 1) collecting a list of all suitable equations eql and a list
 %    of all factors of any equation, listing for each factor
 %    in how many equations it appears
 for each p in pdes do <<
  pv:=get(p,'fac)$
  if pairp pv then <<  % otherwise not (simply) factorizable 
   % increment the counter of appearances of each factor
   h1:=pv$
   while h1 do <<  % for each factor
    f:=car h1; h1:=cdr h1;     % f is in SQ form

    fcc:=fcl$      

    % fcl is list of lists 
    %   (factor itself, 
    %    no of occurences as factor, 
    %    total degree of factor as homogeneous polynomial, 
    %    number of appearances in eqns,
    %    number of terms in factor
    %    a factor taking care of the number of lists in ineq_or
    %      and their length of which f is an element
    %    does the factor contain flin_ (=1) or not (=0) )

    while fcc and (caar fcc neq f) do fcc:=cdr fcc$

    if fcc then <<      % factor had already appeared
     h:=cons(f,cons(add1 cadar fcc,cddar fcc));
     rplaca(fcc,h);
    >>     else <<      % factor is new
     % Computing the total degree of the factor
     if fhom_ then <<
      h2:=find_hom_deg_SF(numr f)$ 
      h2:=(car h2) + (cadr h2)
     >>          else h2:=1;
     % If f is a function then counting in how many equations it appears
     if no_number_atom_SQ f then << % count in how many equations f does occur
      h5:=mvar numr f; % the function
      h3:=0;           % the counter
      h4:=pdes;
      while h4 do <<
       if not freeof(get(car h4,'fcts),h5) then h3:=add1 h3;
       h4:=cdr h4
      >>
     >>        else h3:=1$

     % The number of terms of f:
     h4:=no_of_tm_sf numr f$

     % Is f element of a list-element (with at most 8 elements) of ineq_or?
     h5:=1$
     h6:=ineq_or$
     while h6 do <<
      h7:=length h6;
      if h7 < 9 then
      if member({f},car h6) then h5:={'times,h5,{'expt,2,{'difference,9,h7}}}$
      h6:=cdr h6
     >>$
     h5:=reval h5;

     if flin_ and not freeoflist(f,flin_) then h6:=1 else h6:=0$

     fcl:=cons({f,1,h2,h3,h4,h5,h6},fcl)
    >>
   >>$    % done for all factors

   % check whether each factor can be used for subst., i.e. whether
   % this equation should be factorized
   if null aim_at_subst then h:=1
                        else h:=test_factors_for_substitution(p,pv)$
   
   % adding the equation to the ones suited for factorization
   if not zerop h then eql:=cons(p,eql)

  >>
 >>$  % looked at all factorizable equations

 % Any equation worth to be case-split?
 if null eql then return nil;

 % Now that it is known how often each factor appears in all equations, 
 % each factor can be given a weight and each equation be given a weight

 fcl:=for each h in fcl collect cons(car h,cons(
      substitution_weight(cadr h,caddr h,cadddr h,car cddddr h,
                          cadr cddddr h,caddr cddddr h),
      cdr h                                    ))$

 % fcl is now list of lists 
 %   (factor itself, 
 %    substitution_weight,
 %    no of occurences as factor, 
 %    total degree of factor as homogeneous polynomial, 
 %    number of appearances in eqns,
 %    number of terms in factor
 %    a factor taking care of the number of lists in ineq_or
 %      and their length of which f is an element
 %    does the factor contain flin_ (=1) or not (=0) )

 h2:=nil;    % h2 is the best equation, its weight will be h3 and the
             % factors of the best equation sorted by weight will be h4
             % in the new order they will be set to zero 

 for each p in eql do <<
  pv:=get(p,'fac)$        % list of factors in SQ-form
  h8:=length pv$          % number of factors of p
  h5:=nil;                % the list of (weight of factor . factor)
  h6:=1;                  % the weight of equation p, the less the better
  while pv do <<          % for each factor
   h:=assoc(car pv,fcl);  % the properties of the factor
   if tr_gf then << write "h assoc= ",h$terpri()>>$
   h5:=cons(cons(reval cadr h,car h),h5); % cadr h is substitution_weight
   % h6:={'plus,h6,cadr h}; % if adding up the weights for the factors and
   % then taking the equation with the minimal SUM of weights will
   % favour equations where the weight of the highest weight factor in
   % the equation is lowest. So, how good the best of the factors is
   % does little matter. We therefore change to product.
   h6:={'times,h6,cadr h}; 
   %if not zerop nth(h,8) then h6:={'times,30,h6};  
   % The following change was made to use an equation less 
   % if more flin_ functions appear.
   if (null lin_problem) and 
      (not zerop nth(h,8)) then h6:={'times,
                                     {'expt,2,{'plus,4,
                                               get(p,'nfct_lin)}},
                                     h6};  
   % evaluating flin_ functions
   % has lower priority as quicker progress is made by evaluating the
   % fewer non-flin_ unknowns (at least in bi-lin alg problems)
   pv:=cdr pv
  >>$
  h6:=reval {'times,{'expt,2,h8},h6};     % punishment of many factors
  if null h2 or rational_less(h6,h3) then <<
   h2:=p;
   h3:=h6;
   h4:=h5
  >>
 >>$

 % sort factors of the equation (h2) by their substitution_weight,
 h4:=rat_idx_sort h4$
 if tr_gf then << write "h4(rat_idx_sort'ed)= ",h4$terpri()>>$

 % Putting the flin_ factor last is bad if this factor comes up in
 % many equations, like in the case of bi-linear systems when at the
 % end only one flin_ function is left being a factor of all equations
 %
% if flin_ then <<
%  h5:=h4;       % car h5 will be the factor involving flin_ functions
%  while h5 and freeoflist(cdar h5,flin_) do h5:=cdr h5;
%  if h5 then h4:=append(delete(car h5,h4),list car h5)
% >>$

 put(h2,'fac,for each a in h4 collect cdr a)$
 return h2
end$

endmodule$

end$

------------------------------------------------------------------------------------------------------
Substitutions with:

procedure       # length_li pdelimit less_vars no_df no_cases lin_subst min_growth cost_limit keep_eqn

subst_level_0   3 subst_0  target_limit_3   t    nil     t       nil       nil         nil       nil
subst_level_03  4 subst_0  target_limit_3  nil    t      t       nil       nil         nil       nil
subst_level_04 45 subst_1  target_limit_1  nil    t      t       nil       nil         nil       nil
subst_level_05  5 subst_3  target_limit_3  nil    t      t       nil       nil         nil       nil
subst_level_1  15 subst_1  target_limit_2   t    nil    nil      nil       nil         nil       nil
subst_level_2  18 subst_3  target_limit_3   t    nil     t       nil       nil         nil       nil
subst_level_3  16 subst_2  target_limit_1  nil   nil    nil      nil       nil         nil       nil
subst_level_33 19 subst_3  target_limit_3  nil   nil     t        t        nil         nil       nil
subst_level_35 20 subst_3  target_limit_3  nil   nil     t       nil       nil         nil       nil
subst_level_4  21 subst_3  target_limit_3  nil   nil    nil      nil       nil         nil       nil
subst_level_45  6 subst_3  target_limit_3  nil   nil     t       nil        t      cost_limit5   nil
subst_level_5  17 subst_3  target_limit_3  nil   nil    nil      nil        t          nil       nil

subst_0:=2$        maximal printlength of an expression to be substituted
subst_1:=8$    
subst_2:=20$   
subst_3:=10^3$ 
subst_4:=nil$
cost_limit5:=100$       % maximal number of extra terms generated by a subst.
target_limit_0:=10^2$   % maximal product length(pde)*length(subst_expr)
target_limit_1:=10^3$   % nil=no length limit
target_limit_2:=10^5$
target_limit_3:=nil$ 

make_subst
  get_subst
  do_subst
    simp_all_ineq_with_subst_SQ
    do_one_subst
      mkeqSQ
      updatesq
  mkeqSQ
    updatesq


tr make_subst 
tr get_subst 
tr do_subst 
tr do_one_subst 
tr mkeqSQ 
tr updatesq 
tr fcteval
tr simp_all_ineq_with_subst_SQ
