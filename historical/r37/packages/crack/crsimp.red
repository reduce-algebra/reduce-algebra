%********************************************************************
module simplifications$
%********************************************************************
%  Routines for simplifications, contradiction testing
%  and substitution of functions
%  Author: Andreas Brand
%  1991 1993 1994
%  Updates, changes, additions by Thomas Wolf
%
% $Id: crsimp.red,v 1.17 1998/06/25 18:16:41 tw Exp tw $
%

symbolic procedure signchange(g)$
%  ensure, that the first term is positive
if pairp g then
 if (car g='MINUS) then cadr g
 else if (car g='PLUS) and (pairp cadr g) and (caadr g='MINUS)
      then reval list('MINUS,g)
      else g
else g$

symbolic procedure simplifyterm(p,ftem)$
%  simplify a single factor p of g=p*q*r*...=0
if (ftem:=smemberl(ftem,p)) then
  if pairp p and member(car p,'(MINUS SQRT QUOTIENT))  
  then simplifyterm(cadr p,ftem)
  else if pairp p and (car p='EXPT) then
       if smemberl(ftem,cadr p) then simplifyterm(cadr p,ftem)
                                else 1
  else if member((p:=signchange p),ineq_) then 1
     	      	       	                  else p
else if not p or zerop p then 0
                         else 1$

symbolic procedure contradictioncheck(s,pdes)$
begin scalar v,p$
if s then 
 while pdes do
   <<p:=car pdes$pdes:=cdr pdes$
   v:=get(p,'val)$
   if pairp v and (car v='TIMES) then
     (if member(s,cdr v) then
       <<v:=delete(s,cdr v)$
       update(p,if length v=1 then car v else cons('TIMES,v),
              get(p,'fcts),get(p,'vars),nil,list(0))>>)
   else if s=v then
    <<raise_contradiction(v,nil)$
    pdes:=nil>>
   >>$
return contradiction_$
end$

symbolic procedure raise_contradiction(g,text)$
<<contradiction_:=t$
  if print_ then
     <<terpri()$if text then write text
                        else write "contradiction : "$
  deprint list g>> >>$ 

symbolic procedure simplifypde(g,ftem,tofactor)$
%  simplify g=0
begin scalar h,l,ruli$
 if rulelist_ then g:=reval evalwhereexp list(rulelist_,g)$
 ruli:=start_let_rules()$
 g:=reval aeval g$
 stop_let_rules(ruli)$
 if g and not zerop g and not (ftem:=smemberl(ftem,g)) then 
   <<raise_contradiction(g,nil)$g:=1>>
 else if pairp g then
  if member(car g,'(EXPT QUOTIENT MINUS SQRT)) then 
     g:=simplifypde(cadr g,ftem,tofactor)
  else if member(car g,'(LOG LN LOGB LOG10)) then
     g:=simplifypde(reval list('PLUS,cadr g,-1),ftem,tofactor)
  else if tofactor then
   <<if car g='TIMES 
     then l:=for each a in cdr g join 
                 cdr reval list('FACTORIZE,a)
     else l:=cdr reval list('FACTORIZE,g)$
     while l do 
       <<if not member(car l,cdr l) then
            h:=union(list simplifyterm(car l,ftem),h)$
       l:=cdr l>>$
     h:=delete(1,h)$
     if null h then 
        <<raise_contradiction(g,nil)$
        g:=1>>
     else
       if pairp cdr h then g:=cons('TIMES,reverse h)
                      else g:=car h>>$
return g$
end$ 
     
symbolic procedure fcteval(p,less_vars)$
%  looks for a function which can be eliminated
%  if one is found, it is stored in p as (coeff_of_f.f)
%  if less_vars neq nil then the expr. to be substituted 
%  must have only fcts. of less vars
%  'to_eval neq nil iff not checked yet for substitution
%                   of if subst. possible
%               i.e. 'to_eval=nil if checked and not possible
%  'fcteval_lin includes subst. with coefficients that do not
%               include ftem functions/constants
%  'fcteval_nca includes subst. with non-vanishing coefficients
%               and therefore no case distinctions (linearity)
%  'fcteval_nli includes subst. with possibly vanishing coefficients
%               and therefore case distinctions (non-linearity)
begin scalar ft,a,b,fl,li,nc,nl,f,cpf,fv,fc$
  if flagp(p,'to_eval) then <<  
    b:=get(p,'not_to_eval)$   % functions that replace a derivative
    if (not get(p,'fcteval_lin)) and
       (not get(p,'fcteval_nca)) and
       (not get(p,'fcteval_nli)) then << 
      ft:=get(p,'allvarfcts)$                     
      if null ft then <<
        ft:=get(p,'rational)$
        % drop all functions f from ft for which there is another
        % function which is a function of all variables of f + at
        % least one extra variable
        for each f in ft do <<
          cpf:=get(p,'fcts)$
          fv:=fctargs f$
          while cpf and 
                (not_included(fv,fc:=fctargs car cpf) or
                 (length fv >= length fc)                ) do 
          cpf:=cdr cpf; 
          if null cpf then fl:=cons(f,cpf)
        >>$
        ft:=fl$
      >>$
      if ft then <<
	if (not less_vars)       or 
	   (not cdr ft)          or
	   (zerop get(p,'nvars)) then <<  
	  % either all functions allowed or only one fnc of all vars
	  for each f in ft do        
	  if (f neq b) and linear_fct(p,f) then <<
            % only linear algebr. fcts
	    a:=reval coeffn(get(p,'val),f,1)$
	    if fl:=smemberl(delete(f,get(p,'fcts)),a) then 
	    if freeofzero(a,fl,get(p,'vars)) then nc:=cons(cons(a,f),nc) 
					     else nl:=cons(cons(a,f),nl) 
						      else 
						  li:=cons(cons(a,f),li)
	  >>$
	  if li then put(p,'fcteval_lin,reverse li); % else
	  if nc then put(p,'fcteval_nca,reverse nc); % else
	  if nl then put(p,'fcteval_nli,reverse nl);
	  if not (li or nc or nl) then remflag1(p,'to_eval)
	>> 
      >>$
    >>$
    return (get(p,'fcteval_lin) or 
            get(p,'fcteval_nca) or 
	    get(p,'fcteval_nli)    )
  >>
end$

symbolic procedure freeofzero(p,ft,vl)$
%   gets p (factorized), if p does not vanish identically
if null ft then p
else 
begin scalar a,b,fr,pri$
 pri:=print_$
 print_:=nil$
 for each s in cdr reval list('FACTORIZE,p) do 
    a:=union(list simplifyterm(s,ft),a)$
 if length a>1 then p:=cons('TIMES,a)$
 while a do
  if null smemberl(ft,car a) or member(car a,ineq_) then a:=cdr a
  else if pairp cdr
    (b:=union(for each s in separ(car a,ft,vl) collect cdr s,nil)) then
      <<fr:=nil$
      while b do if freeofzero(car b,ft,vl) then <<b:=nil$fr:=t>>
      	       	     	      	       	    else b:=cdr b$
      if fr then a:=cdr a
            else <<a:=nil$p:=nil>> >>
    else <<a:=nil$p:=nil>>$
 print_:=pri$
return p
end$

symbolic procedure get_subst(l,length_limit,less_vars,no_df)$
%
% get the most simple pde from l which leads to a function substitution
% if less_vars neq nil: the expr. to subst. has only fcts. of less vars
% if no_df neq nil:     the expr. to subst. has no derivatives
begin scalar p,l1,l2,m,ntms,mdu$
  % mdu=(1:lin, 2:nca, 3:nli)

  % drop all equations longer than length_limit
  if length_limit then <<
    while l do
    if get(car l,'length)>length_limit then l:=nil
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
    for each s in l do 
      <<l2:=get(s,'derivs)$
      while l2 do 
 	if pairp(cdaar l2) then
 	   <<l2:=nil;
           l1:=cons(s,l1)>>
        else l2:=cdr l2>>$
    l:=setdiff(l,l1)>>$

  % next: restrict to substitutions, if any, 
  %       that have a coefficient without ftem-dependence
  l1:=nil;
  for each s in l do 
  if fcteval(s,less_vars) and
     get(s,'fcteval_lin) then l1:=cons(s,l1)$
  if l1 then <<l:=l1;mdu:=1>>
        else <<
   % at least substitutions that do not lead to subcases?
   for each s in l do 
   if get(s,'fcteval_nca) then l1:=cons(s,l1)$
   if l1 then <<l:=l1;mdu:=2>>
         else mdu:=3 
  >>$

  % next: find an equation with as many as possible variables 
  %       and few as possible terms for substitution    
  m:=-1$
  for each s in l do <<
   l1:=get(s,'nvars);
   if get(s,'starde) then l1:=sub1 l1;
   if l1>m then m:=l1$
  >>$

  while m>=0 do <<
    l1:=l$
    ntms:=10000000$
    while l1 do
    if ((get(car l1,'nvars) -
         if get(car l1,'starde) then 1 
                                else 0) = m )   and 
       fcteval(car l1,less_vars)                and
       (get(car l1,'terms) < ntms)              then <<
      p:=car l1$
      l1:=cdr l1$
      ntms:=get(p,'terms)$
    >>                             else l1:=cdr l1$
    m:=if p then -1
            else sub1 m
  >>$

  if p then return if mdu=1 then {mdu,p,car get(p,'fcteval_lin)} else
                   if mdu=2 then {mdu,p,car get(p,'fcteval_nca)} else
                                 {mdu,p,car get(p,'fcteval_nli)}
end$

symbolic procedure ineqsplit(q,ftem)$
% q into factors and
% drop quotients
begin scalar l$
 if pairp q and (car q='QUOTIENT) then q:=cadr q$
 q:=cdr reval list('FACTORIZE,q)$
 for each s in q do
     if smemberl(ftem,s) then
        <<s:=signchange s$
        if not member(s,l) then l:=cons(s,l)>>$
return l$
end$

symbolic procedure ineqsubst(new,old,ftem)$
% tests all q's in ineq_ for subst(new, old,q)=0
% result: nil, if 0 occurs
%         otherwise list of the subst(car p,...)
begin scalar l,a$
while ineq_ do
 if not my_freeof(car ineq_,old) then
 <<a:=simplifyterm(reval reval subst(new, old,car ineq_),ftem)$
   if zerop a then
   <<if print_ then
     <<terpri()$write "contradiction from the substitution:"$
       eqprint list('EQUAL,old,new)$
       write "because of the non-vanishing expression:"$
       eqprint car ineq_>>$
     contradiction_:=t$
     l:=nil$
     ineq_:=nil>>
   else
   <<l:=union(ineqsplit(a,ftem),l)$
     ineq_:=cdr ineq_>> >>
 else
 <<l:=cons(car ineq_,l)$
   ineq_:=cdr ineq_>>$
ineq_:=reverse l$
end$

symbolic procedure do_one_subst(ex,f,a,ftem,vl,level,eqn)$
% substitute f by ex in a
begin scalar l,l1,p,oldstarde$
 l:=get(a,'val)$
 oldstarde:=get(a,'starde)$
 if pairp l and (car l='TIMES) then l:=cdr l
                               else l:=list l$
 while l do <<  % for each factor
  if smember(f,car l) then <<
   p:=reval reval subst(ex,f,car l)$
   if not p or zerop p then <<l:=list nil$l1:=list 0>>
                       else <<
    if pairp p and (car p='QUOTIENT) then p:=cadr p$
    l1:=if no_of_terms(p)>max_factor then cons(p,l1)
                                     else
    append(reverse cdr reval list('FACTORIZE,p),l1)
   >> 
  >>                  else l1:=cons(car l,l1)$
 l:=cdr l
 >>$
 l:=nil$
 while l1 do <<
  if not member(car l1,cdr l1) then
  l:=union(list simplifyterm(car l1,ftem),l)$
  l1:=cdr l1
 >>$
 l:=delete(1,l)$
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
   eqprint(list('EQUAL,f,ex))
  >>$
  raise_contradiction(get(a,'val),
                      "leads to a contradiction in : ")$
  a:=nil
 >>        else <<
  if pairp cdr l then l:=cons('TIMES,l)
                 else l:=car l$
  if get(a,'level) neq level then 
     a:=mkeq(l,ftem,vl,allflags_,nil,list(0))
  else <<
   for each b in allflags_ do flag(list a,b)$
   if null update(a,l,ftem,vl,nil,list(0)) then <<
    setprop(a,nil)$
    a:=nil
   >> 
  >>$
  put(a,'level,level)
 >>$
 if oldstarde and not get(a,'starde) then put(a,'dec_with,nil);
 return a$
end$

symbolic procedure do_subst(md,p,l,pde,ftem,forg,vl,plim)$
% md is the mode of substitution, needed in case of an ISE
% Substitute a function in all pdes 
begin scalar f,fl,h,ex,res,slim,too_large,was_subst,ps,
             ruli,ise,cf,vl,nof,stde$ %,l$
% l:=get(p,'fcteval_lin)$
% if null l then l:=get(p,'fcteval_nca)$
% if null l then l:=get(p,'fcteval_nli)$
% if l then << % l:=car l$
  f:=cdr l$
  cf:=car l$
  if get(p,'starde) then ise:=t;
  slim:=get(p,'length)$
  ruli:=start_let_rules()$
  ex:=reval aeval list('QUOTIENT,
                       list('PLUS,list('MINUS,get(p,'val)),
                                  list('TIMES,cf,f)),
                       cf)$
  if not ise then ineqsubst(ex,f,ftem)$
  if not contradiction_ then <<
   if not ise then <<
    fl:=delete(f,smemberl(ftem_,ex))$   % functions occuring in ex
    forg:=for each h in forg collect
          if atom h then
          if f=h then <<put(h,'fcts,fl)$was_subst:=t$list('EQUAL,f,ex)>>
                 else h
                    else 
          if (car h='EQUAL) and member(f,get(cadr h,'fcts)) then <<
           put(cadr h,'fcts,union(fl,delete(f,get(cadr h,'fcts))))$
           was_subst:=t$
           reval subst(ex,f,h)
          >>                                                else h$
   >>$
   if expert_mode then <<
    ps:=promptstring!*$
    promptstring!*:="pdes selected for substitution: "$
    l:=xread nil$ 
    promptstring!*:=ps$
    if idp l then <<if not member(l,pde) then l:=nil>>
             else if pairp l then
    if car l='!*comma!* then l:=intersection(pde,cdr l)
                        else l:=nil
                             else l:=nil$
    if not_included(pde,l) then too_large:=t$
    if not l then <<
     terpri()$
     write "This is not a pde (e.g. e2) or a list of pdes (e.g. e1,e2,e3)"
    >>
   >>             else l:=delete(p,pde)$
   % Do the substitution in all suitable equations
   if ise then <<
    h:=nil;
    vl:=get(p,'vars)$
    fl:=get(p,'fcts)$
    nof:=cdr get(p,'starde)$
    while l do <<
     if (stde:=get(car l,'starde)) and
        (nof<=cdr stde) and
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
     pde:=eqinsert(do_one_subst(ex,f,car l,ftem,vl,get(p,'level),p),
                   delete(car l,pde))$
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
    eqprint(list('EQUAL,f,ex))
   >>$
   % To avoid using p repeatedly for substitutions of different
   % functions in the same equations:
   if ise then <<
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
      (not too_large) and 
      (not contradiction_) then <<
    if not assoc(f,depl_copy_) then 
    depl!*:=delete(assoc(f,depl!*),depl!*)$
    was_subst:=t$            % in the sense that pdes have been updated
    ftem_:=delete(f,ftem_)$
    pde:=delete(p,pde)$
    setprop(p,nil)
   >>$
%   if was_subst then 
   res:=list(pde,forg)  
   % also if not used to delete the pde if the function to be
   % substituted does not appear anymore
  >>$
  stop_let_rules(ruli)$
% >>$
 if not contradiction_ then return cons(was_subst,res)$
end$

symbolic procedure make_subst(pdes,forg,vl,l1,length_limit,pdelimit,
                              less_vars,no_df,no_cases,lin_subst,
                              mingrowth,cost_limit)$
% make a subst. 
% l1 is the list of possible "candidates"
begin scalar p,q,r,l,h,cop,cases_,w,md$   % ,ineq
  if expert_mode then l1:=selectpdes(pdes,1)$
again:
  if (mingrowth and (w:=search_subs(l1,cost_limit,no_cases))) or
     ((null mingrowth) and
      (w:=get_subst(l1,length_limit,less_vars,no_df))) then 

  if (   car w = 1)                             or
     ((lin_subst=nil)                     and
      ( (car w = 2)                  or
       ((car w = 3)            and 
        member(caaddr w,ineq_)     )    )     ) then <<
   l:=do_subst(car w,cadr w,caddr w,pdes,ftem_,forg,vl,pdelimit)$
   if l and null car l then << % not contradiction but not used
    l1:=delete(cadr w,l1);
    if l1 then <<
     pdes:=cadr l;
     forg:=caddr l;     
     l:=nil;
     goto again
    >>    
   >>;
   if l then l:=cdr l
  >>                                            else 
  if (null lin_subst) and (null no_cases) then <<
    md:=car w;   % md = type of substitution, needed in case of ISE
    p:=cadr  w;  % p = the equation
    w:=caddr w;  % w = (coeff . function)
    % make an equation from the coefficient
    q:=mkeq(car w,get(p,'fcts),get(p,'vars),allflags_,t,list(0))$
    % and an equation from the remainder
    r:=mkeq(list('PLUS,get(p,'val),
                 list('TIMES,car w,
                             list('MINUS,cdr w))),
            get(p,'fcts),get(p,'vars),allflags_,t,list(0))$
    if contradiction_ then <<
      contradiction_:=nil$
      h:=get(q,'val)$
      if pairp h and (car h='TIMES) then ineq_:=union(cdr  h,ineq_)
                                    else ineq_:=union(list h,ineq_)$      
      setprop(q,nil)$
      setprop(r,nil)$
      l:=do_subst(md,p,w,pdes,ftem_,forg,vl,pdelimit)$
      if print_ then  write"therefore no special investigation"$

      if l and null car l then << % not contradiction but not used
       l1:=delete(p,l1);
       if l1 then <<
	pdes:=cadr l;
	forg:=caddr l;     
        l:=nil;
	goto again
       >>    
      >>;
      if l then l:=cdr l

    >>                else <<
      cop:=backup_pdes(pdes,forg)$
      remflag1(p,'to_eval)$
      if print_ then <<
        terpri()$
        write "for the substitution of ",cdr w," by ",p$
        write " we have to consider the case : "$
        eqprint list('EQUAL,0,car w)
      >>$
      pdes:=eqinsert(q,delete(p,pdes))$
      pdes:=eqinsert(r,pdes)$      
      level_:=cons(1,level_)$
      print_level()$
      h:=get(q,'val)$    % to add it to ineq_ afterwards
      l:=crackmain(pdes,ineq_,forg,vl)$
      level_:=cons(2,level_)$  
      if print_ then <<
	print_level()$
        terpri()$
	write "now back to the substitution of ",cdr w," by ",p$
      >>$
      pdes:=restore_pdes(cop)$
      if pairp h and (car h='TIMES) then ineq_:=union(cdr  h,ineq_)
                                    else ineq_:=union(list h,ineq_)$      
      setprop(q,nil);
      setprop(r,nil);

      if contradiction_ then <<
	 contradiction_:=nil$
	 l:=do_subst(md,p,w,pdes,ftem_,forg,vl,pdelimit)$

	 if l and null car l then << % not contradiction but not used
	  l1:=delete(p,l1);
	  if l1 then <<
	   pdes:=cadr l;
	   forg:=caddr l;     
           l:=nil;
	   goto again
	  >>    
	 >>;
	 if l then l:=cdr l

      >>                else <<
        cases_:=t$
        cop:=nil;     % to save memory
	h:=crackmain(pdes,ineq_,forg,vl)$
	if contradiction_ then contradiction_:=nil
			  else l:=union(h,l)
      >>
    >>$
  >>$

  return if contradiction_  then nil % list(nil,nil) 
                            else if cases_ then list l
                                           else l$
end$


symbolic procedure get_fact_pde(pdes)$
% look for pde in pdes which can be factorized
begin scalar m,p,pv,fdegl,pdeg,h,f,fcc,fcl,tf,pmdeg,fmdeg,tfm,fm,pm$
 m:=0;   % counts how often the factor occurs that occurs most
 while pdes do <<
  p:=car pdes$  pdes:=cdr pdes$
  pv:=get(p,'val)$
  if pairp pv and (car pv='TIMES) then <<
   pv:=cdr pv$  % the list of factors in p
   fdegl:=for each f in pv collect 
          pde_degree(f,smemberl(get(p,'rational),f))$
   pdeg:=for each h in fdegl sum h$

   for each f in pv do <<

    % counting how often f has occured as factor
    fcc:=fcl$
    while fcc and (caar fcc neq f) do fcc:=cdr fcc$
    if fcc then <<
     h:=add1 cadar fcc;
     rplaca(cdar fcc,h);
    >>     else <<
     fcl:=cons({f,1,p},fcl);
     h:=1
    >>;
    tf:=nil;
    % Is f the best factor so far and p the best equation?
    if ( h>m                                                       ) or 
       ((h=m                                                 ) and 
        ((  pdeg < pmdeg                                ) or
         (( pdeg = pmdeg                          ) and
          ((car fdegl < fmdeg                ) or
           ((car fdegl = fmdeg         ) and 
            ((tf:=no_of_terms(f)) < tfm)     )    )     )    )     ) then <<
     m:=h;
     fm:=f;
     pm:=p;
     pmdeg:=pdeg;
     fmdeg:=car fdegl; 
     tfm:=if tf then tf
                else no_of_terms(f)$
    >>$
    fdegl:=cdr fdegl
   >>
  >>$
 >>$
 return if m=0 then nil 
               else <<
  put(pm,'val,cons('TIMES,cons(fm,delete(fm,cdr get(pm,'val)))))$
  pm
 >>
end$

algebraic procedure start_let_rules$
begin scalar ruli;
  ruli:={};
  let explog_$
  if sin(!%x)**2+cos(!%x)**2 neq 1         then <<ruli:=cons(1,ruli);let trig1_>> else ruli:=cons(0,ruli)$
  if cosh(!%x)**2 neq (sinh(!%x)**2 + 1)   then <<ruli:=cons(1,ruli);let trig2_>> else ruli:=cons(0,ruli)$
  if sin(!%x)*tan(!%x/2)+cos(!%x) neq 1    then <<ruli:=cons(1,ruli);let trig3_>> else ruli:=cons(0,ruli)$
  if sin(!%x)*cot(!%x/2)-cos(!%x) neq 1    then <<ruli:=cons(1,ruli);let trig4_>> else ruli:=cons(0,ruli)$
  if cos(2*!%x) + 2*sin(!%x)**2   neq 1    then <<ruli:=cons(1,ruli);let trig5_>> else ruli:=cons(0,ruli)$
  if sin(2*!%x) neq 2*cos(!%x)*sin(!%x)    then <<ruli:=cons(1,ruli);let trig6_>> else ruli:=cons(0,ruli)$
  if sinh(2*!%x) neq 2*sinh(!%x)*cosh(!%x) then <<ruli:=cons(1,ruli);let trig7_>> else ruli:=cons(0,ruli)$
  if cosh(2*!%x) neq 2*cosh(!%x)**2-1      then <<ruli:=cons(1,ruli);let trig8_>> else ruli:=cons(0,ruli)$
  return ruli;
end$

algebraic procedure stop_let_rules(ruli)$
begin
  clearrules explog_$
  if first ruli = 1 then clearrules trig8_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig7_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig6_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig5_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig4_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig3_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig2_$ ruli:=rest ruli$
  if first ruli = 1 then clearrules trig1_$ 
end$


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  procedures  for finding an optimal substitution  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure fbts(a,b)$
% fbts ... first better than second
(cadr   a <= cadr   b) and 
(caddr  a <= caddr  b) and 
(cadddr a <= cadddr b);


symbolic procedure list_subs(p,fevl,fli,mdu)$
% p is an equation, fevl a substitution list of p,
% fli is a list of lists (f,p1,p2,..) where 
%   f is a function, 
%   pi are lists (eqn,nco,nte,mdu) where
%   eqn is an equation that can be used for substituting f
%   nco is the number of terms of the coefficient of f in the eqn
%   nte is the number of terms without f in the eqn
%   mdu is the kind of substitution (1:lin, 2:nca, 3:nli)
begin
 scalar a,f,nco,nte,cpy,cc,ntry;
 for each a in fevl do <<
  f:=cdr a;
  nco:=no_of_terms(car a);
  nte:=get(p,'terms);
  nte:=if nte=1 then 0 
                else nte-nco$

  % Is there already any substitution list for f?
  cpy:=fli;
  while cpy and (f neq caar cpy) do cpy:=cdr cpy$
  ntry:={p,nco,nte,mdu}$

  if null cpy then fli:=cons({f,ntry},fli) % no, there was not
              else <<                         % yes, there was one
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

algebraic procedure cwrno(n,r)$
% number of terms of (a1+a2+..+an)**r if ai are pairwise prime
% number of combinations of r factors out of n possible factors
% with repititions and without order = (n+r-1 over r)
<<n:=n+r-1;
  % The rest of the procedure computes binomial(n,r).
  if 2*r>n then k:=n-r;
  for i:=1:r product (n+1-i)/i
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

symbolic procedure search_subs(pdes,cost_limit,no_cases)$
begin
 scalar fli,p,el,f,fpl,dv,drf,d,ffl,hp,ff,nco,be,s,nte,ic,fp,
        rm,mc,subli,mdu,tr_search$

 % at first find the list of all functions that could be substituted
 % together with a list of pdes, the number of terms in the coeff and 
 % the type of substitution

% tr_search:=t$

 for each p in pdes do fcteval(p,nil)$

 fp:=pdes;
 while fp                                    and 
       ((get(car fp,'terms)>2)          or 
        (null get(car fp,'fcteval_lin))    ) do fp:=cdr fp;
 if fp then return {1,car fp,car get(car fp,'fcteval_lin)}$

 for each p in pdes do <<
  fli:=list_subs(p,get(p,'fcteval_lin),fli,1)$
  fli:=list_subs(p,get(p,'fcteval_nca),fli,2)$
  if null no_cases then fli:=list_subs(p,get(p,'fcteval_nli),fli,3)$
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
     if cdar d then ff:=cons('DF,car d)
               else ff:=caar d; 
     nco:=no_of_terms(coeffn(get(p,'val),ff,cdr d));
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
   if pairp s then l:=union(for each a in all_deriv_search(s,ftem_)
                                    collect car a,l)$
  l1:=df_min_list(l)$
  l:=nil$
  for each s in l1 do 
   if pairp s and not member(car s,not_to_substdf) then <<
    l:=cons(cons('DF,s),l)$
    not_to_substdf:=cons(car s,not_to_substdf)
  >> $

  % Derivatives of functions should only be substituted if the
  % function occurs in at least 2 equations
  while l do <<
   n:=0; % counter
   cp:=pdes;
   while cp and (n<2) do <<
    if member(car l,get(car cp,'fcts)) then n:=add1 n;
    cp:=cdr cp
   >>;
   if n=2 then l2:=cons(car l,l2);
   l:=cdr l
  >>
 >>$
 return l2$
end$

symbolic procedure df_min_list(dflist)$
%  yields the lowest derivative for each function in the list of
%  deriv. dflist.
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
%  yields the minimal derivative of d1,d2
%  e.g. df_min('(f x y),'(f x z))='(f x), df_min('(f x z),'(g x))=nil
<<if not pairp df1 then df1:=list df1$
if not pairp df2 then df2:=list df2$
if car df1=car df2 then 
  if (df1:=df_min1(cdr df1,cdr df2)) then cons(car df2,df1)
                                     else car df2>>$

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
  if pairp h and member(d,get(cadr h,'fcts)) then 
          <<put(cadr h,'fcts,
                cons(p,delete(d,get(cadr h,'fcts))))$
          reval subst(g,d,h)>>
  else h$

symbolic procedure expand_INT(p,varlist)$
if null varlist then p
else begin scalar v,n$
  v:=car varlist$
  varlist:=cdr varlist$
  if pairp(varlist) and numberp(car varlist) then
     <<n:=car varlist$
       varlist:=cdr varlist>>
  else n:=1$
  for i:=1:n do p:=list('INT,p,v)$
  return expand_INT(p,varlist)
end$


endmodule$

end$
