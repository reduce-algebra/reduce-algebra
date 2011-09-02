%********************************************************************
module utilities$
%********************************************************************
%  Routines for finding leading derivatives and others
%  Author: Andreas Brand
%  1990 1994
%  Updates by Thomas Wolf
%
%  $Id: crutil.red,v 1.23 1998/06/25 18:20:43 tw Exp tw $
%

%%%%%%%%%%%%%%%%%%%%%%%%%
%  properties of pde's  %
%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure drop_dec_with(de1,de2,rl)$
% drop de1 from the 'dec_with or 'dec_with_rl list of de2
begin scalar a,b,c$
  a:=if rl then get(de2,'dec_with_rl)
           else get(de2,'dec_with)$
  for each b in a do <<
    b:=delete(de1,b);
    if length b>1 then c:=cons(b,c);
  >>; 
  if rl then put(de2,'dec_with_rl,c)
        else put(de2,'dec_with   ,c)
end$

symbolic procedure add_dec_with(f,de1,de2,rl)$
% add (f de1) to 'dec_with or 'dec_with_rl of de2 
begin scalar a,b$
  a:=if rl then get(de2,'dec_with_rl)
           else get(de2,'dec_with)$
  b:=assoc(f,a)$
  a:=delete(b,a)$
  if b then b:=cons(f,cons(de1,cdr b))
       else b:=list(f,de1)$
  if rl then put(de2,'dec_with_rl,cons(b,a))
        else put(de2,'dec_with   ,cons(b,a))$
end$

symbolic procedure add_both_dec_with(f,de1,de2,rl)$
% add (f de1) to 'dec_with or 'dec_with_rl of de2  and 
% add (f de2) to 'dec_with or 'dec_with_rl of de1 
begin
  add_dec_with(f,de1,de2,rl)$
  add_dec_with(f,de2,de1,rl)$
end$

symbolic procedure drop_rl_with(de1,de2)$
% drop de1 from the 'rl_with list of de2
put(de2,'rl_with,delete(de1,get(de2,'rl_with)))$

symbolic procedure add_rl_with(de1,de2)$
% add de1 to 'rl_with of de2 and vice versa
<<put(de2,'rl_with,cons(de1,get(de2,'rl_with)))$
  put(de1,'rl_with,cons(de2,get(de1,'rl_with)))>>$

symbolic procedure prevent_simp(v,de1,de2)$
% it is df(de1,v) = de2
% add dec_with such that de2
% will not be simplified to 0=0
begin scalar a,b$
  a:=get(de1,'fcts)$
  for each b in a do if member(v,fctargs(b)) then 
  <<add_dec_with(b,de2,de1,nil);add_dec_with(b,de2,de1,t)>>;
  a:=get(de2,'fcts)$
  for each b in a do if member(v,fctargs(b)) then 
  <<add_dec_with(b,de1,de2,nil);add_dec_with(b,de1,de2,t)>>;
end$

symbolic procedure termread$
begin scalar val, !*echo;  % Don't re-echo tty input
 rds nil; wrs nil$         % Switch I/O to terminal
 val := read()$
 if ifl!* then rds cadr ifl!*$  %  Resets I/O streams
 if ofl!* then wrs cdr ofl!*$
 history_:=cons(val,history_)$
 return val
end$

symbolic procedure termxread$
begin scalar val, !*echo;  % Don't re-echo tty input
 rds nil; wrs nil$         % Switch I/O to terminal
 val := xread(nil)$
 if ifl!* then rds cadr ifl!*$  %  Resets I/O streams
 if ofl!* then wrs cdr ofl!*$
 history_:=cons(compress(append(explode val,list('$))),history_)$
 return val
end$

symbolic procedure mkeqlist(vallist,ftem,vl,flaglist,simp_flag,orderl)$
%  make a list of equations
%    vallist:  list of expressions
%    ftem:     list of functions
%    vl:       list of variables
%    flaglist: list of flags
%    orderl:   list of orderings where the equations are valid
begin scalar l1$
 for each a in vallist do
     l1:=eqinsert(mkeq(a,ftem,vl,flaglist,simp_flag,orderl),l1)$
return l1 
end$

symbolic procedure mkeq(val,ftem,vl,flaglist,simp_flag,orderl)$
%  make a new equation
%    val:      expression
%    ftem:     list of functions
%    vl:       list of variables
%    flaglist: list of flags
%    orderl:   list of orderings where the equation is valid
begin scalar s$
 s:=mkid(eqname_,nequ_)$
 nequ_:=add1 nequ_$
 setprop(s,nil)$
 for each a in flaglist do flag(list s,a)$
 if not update(s,val,ftem,vl,simp_flag,orderl) then 
   <<nequ_:=sub1 nequ_$
   setprop(s,nil)$
   s:=nil>>$
 return s
end$

symbolic procedure update(equ,val,ftem,vl,simp_flag,orderl)$
%  update the properties of a pde
%    equ:      pde
%    val:      expression
%    ftem:     list of functions
%    vl:       list of variables
%    orderl:   list of orderings where the equation is valid
begin scalar l$
  if val and not zerop val then <<
    ftem:=reverse union(smemberl(ftem,val),nil)$
    put(equ,'terms,no_of_terms(val))$    
    if simp_flag then <<
      % the following test to avoid factorizing big equations
      val:=if get(equ,'terms)>max_factor % get(equ,'starde)
      then simplifypde(val,ftem,nil)
      else simplifypde(val,ftem,t)$  
      if val and not zerop val then <<
	ftem:=reverse union(smemberl(ftem,val),nil)$
        put(equ,'terms,no_of_terms(val))$    
      >>
    >>$
  >>$
  if val and not zerop val then <<
    put(equ,'val,val)$
    put(equ,'fcts,ftem)$
    for each v in vl do
      if not my_freeof(val,v) then l:=cons(v,l)$
    vl:=reverse l$
    put(equ,'vars,vl)$  
    put(equ,'nvars,length vl)$
    put(equ,'level,level_)$
    put(equ,'derivs,sort_derivs(all_deriv_search(val,ftem),ftem,vl))$
    put(equ,'fcteval_lin,nil)$
    put(equ,'fcteval_nca,nil)$
    put(equ,'fcteval_nli,nil)$
%    put(equ,'terms,no_of_terms(val))$    
    put(equ,'length,pdeweight(val,ftem))$    
    put(equ,'printlength,delength val)$
    put(equ,'rational,nil)$
    put(equ,'nonrational,nil)$
    put(equ,'allvarfcts,nil)$
    put(equ,'orderings,orderl)$	% Orderings !
    for each f in reverse ftem do
      if rationalp(val,f) then 
	 <<put(equ,'rational,cons(f,get(equ,'rational)))$
	   if fctlength f=get(equ,'nvars) then
	      put(equ,'allvarfcts,cons(f,get(equ,'allvarfcts)))>>
      else put(equ,'nonrational,cons(f,get(equ,'nonrational)))$
%    put(equ,'degrees,          % too expensive
%     if linear_pr then cons(1,for each l in get(equ,'rational) 
%                              collect (l . 1))
%                  else fct_degrees(val,get(equ,'rational))    )$
    put(equ,'starde,stardep(ftem,vl))$
    if (l:=get(equ,'starde)) then
       <<%remflag1(equ,'to_eval)$
       remflag1(equ,'to_int)$
       if simp_flag and (zerop cdr l) then flag1(equ,'to_sep)$
       % remflag1(equ,'to_diff)
       >>
    else remflag1(equ,'to_gensep)$
    if get(equ,'starde) and
       (zerop cdr get(equ,'starde) or (get(equ,'length)<=gensep_)) 
       then % remflag1(equ,'to_decoup)
       else remflag1(equ,'to_sep)$
    if get(equ,'nonrational) then 
       <<%remflag1(equ,'to_decoup)$
       if not freeoflist(get(equ,'allvarfcts),get(equ,'nonrational)) then
	  remflag1(equ,'to_eval)>>$
%    if not get(equ,'allvarfcts) then remflag1(equ,'to_eval)$
    if (not get(equ,'rational)) or
       ((l:=get(equ,'starde)) and (cdr l = 0)) then remflag1(equ,'to_eval)$
    if homogen_ then 
       <<for each f in get(equ,'fcts) do val:=subst(0,f,val)$
       if not zerop reval reval val then
	  <<contradiction_:=t$
	  terpri()$
	  write "Contradiction in ",equ,
	  "!!! PDE has to be homogeneous!!!">> >>$
    remprop(equ,'full_int)$
    return equ
  >>
end$

symbolic procedure fct_degrees(pv,ftem)$
% ftem are to be the rational functions
begin
 scalar f,l,ll,h,degs$
 if den pv then pv:=num pv$
 for each f in ftem do <<
  l:=gensym()$
  ll:=cons((f . l),ll)$
  pv:=subst({'TIMES,l,f},f,pv)$
 >>$
 pv:=reval pv$
 for each l in ll do <<
  degs:=cons((car l . deg(pv,cdr l)),degs)$ 
 >>;
 h:=cdar ll$
 for each l in cdr ll do pv:=subst(h,cdr l,pv)$
 pv:=reval pv$
 return cons(deg(pv,h),degs)
end$

symbolic procedure pde_degree(pv,ftem)$
% ftem are to be the rational functions
begin
 scalar f,h$
 if den pv neq 1 then pv:=num pv$
 h:=gensym()$
 for each f in ftem do pv:=subst({'TIMES,h,f},f,pv)$
 pv:=reval pv$
 return deg(pv,h)
end$

symbolic procedure dfsubst_update(f,der,equ)$
%  miniml update of some properties of a pde
%    equ:      pde
%    der:      derivative
%    f:        f new function
begin scalar l$
  for each d in get(equ,'derivs) do
    if not member(cadr der,car d) then l:=cons(d,l)
    else
      <<l:=cons(cons(cons(f,df_int(cdar d,cddr der)),cdr d),l)$
      put(equ,'val,
          subst(reval cons('DF,caar l),reval cons('DF,car d),
                get(equ,'val)))>>$
  put(equ,'fcts,subst(f,cadr der,get(equ,'fcts)))$
  put(equ,'allvarfcts,subst(f,cadr der,get(equ,'allvarfcts)))$
  if get(equ,'allvarfcts) then flag(list equ,'to_eval)$
%  This would reactivate equations which resulted due to
%  substitution of derivative by a function.
%  8.March 98: change again: the line 3 lines above has been reactivated
  put(equ,'rational,subst(f,cadr der,get(equ,'rational)))$
  put(equ,'nonrational,subst(f,cadr der,get(equ,'nonrational)))$
  put(equ,'derivs,sort_derivs(l,get(equ,'fcts),get(equ,'vars)))$
  return equ
end$

symbolic procedure eqinsert(s,l)$
% l is a sorted list
if not (s or get(s,'val)) or zerop get(s,'length) or member(s,l) then l
else if not l then list s
else begin scalar l1,n$
% if print_ and tr_main then
%  <<terpri()$write "inserting ",s," in the pde list: ">>$
 l1:=proddel(s,l)$
 if car l1 then
  <<n:=get(s,'length)$
    l:=cadr l1$
    l1:=nil$
%    if print_ and tr_main then write s," is inserted."$
    while l and (n>get(car l,'length)) do
     <<l1:=cons(car l,l1)$
       l:=cdr l>>$
    l1:=append(reverse l1,cons(s,l))$
  >>
 else if l1 then l1:=cadr l1  % or reverse of it
            else l1:=l$
 return l1$
end$

symbolic procedure not_included(a,b)$
% Are all elements of a also in b? If yes then return nil else t
% This could be done with setdiff(a,b), only setdiff
% copies expressions and needs extra memory whereas here we only
% want to know one bit (included or not)
begin scalar c$
 c:=t;
 while a and c do <<
  c:=b;
  while c and ((car a) neq (car c)) do c:=cdr c;
  % if c=nil then car a is not in b
  a:=cdr a;
 >>;
 return if c then nil
             else t
end$

symbolic procedure proddel(s,l)$
% delete all pdes from l with s as factor
% delete s if it is a consequence of any known pde from l
begin scalar l1,l2,l3,n,lnew,go_on$
 if pairp(lnew:=get(s,'val)) and (car lnew='TIMES) then lnew:=cdr lnew
                                                   else lnew:=list lnew$
 n:=length lnew$
 go_on:=t$
 while l do << % while l and go_on do << % in case one wants to stop if s
                                         % is found to be a consequence of l 
  if pairp(l1:=get(car l,'val)) and (car l1='TIMES) then l1:=cdr  l1
                                                    else l1:=list l1$
  if n<length l1 then   % s has less factors than car l
    if not_included(lnew,l1) then 
    l2:=cons(car l,l2)    % car l is not a consequ. of s
                             else 
    <<l3:=cons(car l,l3); % car l is a consequ. of s
      setprop(car l,nil)
    >>
  else <<
    if null not_included(l1,lnew) then % s is a consequence of car l
    <<if print_ and tr_main then
      <<terpri()$write s," is a consequence of ",car l,".">>$
      % l2:=append(reverse l,l2); 
      % one could stop here but continuation can still be useful
      go_on:=nil$
    >>$
    % else 
    l2:=cons(car l,l2)$
  >>;
  l:=cdr l
 >>$
 if print_ and tr_main and l3 then <<
  terpri()$listprint l3$
  if cdr l3 then write " are consequences of ",s
            else write " is a consequence of ",s
 >>$
 if null go_on then <<setprop(s,nil);s:=nil>>$
 return list(s,reverse l2)$
end$


symbolic procedure myprin2l(l,trenn)$
if l then 
   <<if pairp l then
        while l do
          <<write car l$
          l:=cdr l$
          if l then write trenn>> 
   else write l>>$

symbolic procedure typeeq(s)$
%  print equation 
 if get(s,'printlength)>print_ then begin scalar a,b$
   write "expr. with ",(a:=get(s,'terms))," terms"$
   if a neq (b:=get(s,'length)) then write", ",b," factors"$
   write" in "$ 
   myprin2l(get(s,'fcts),", ")$
   terpri()$
 end                     else
 mathprint list('EQUAL,0,get(s,'val))$

symbolic procedure typeeqlist(l)$
%  print equations and its property lists
<<terpri()$
for each s in l do
 <<%terpri()$
 write s," : "$ typeeq(s)$%terpri()$

% write s," : weight = ",get(s,'length),", "$
% if print_ and (get(s,'printlength)>print_) then
%    <<write "expr. with ",get(s,'terms)," terms in "$ 
%    myprin2l(get(s,'fcts),", ")$
%    terpri()>>
% else
%    mathprint list('EQUAL,0,get(s,'val))$

 if print_all then
    <<
             write "   fcts       : ",get(s,'fcts)$
    terpri()$write "   vars       : ",get(s,'vars)$
    terpri()$write "   nvars      : ",get(s,'nvars)$
    terpri()$write "   derivs     : ",get(s,'derivs)$
    terpri()$write "   terms      : ",get(s,'terms)$
    terpri()$write "   length     : ",get(s,'length)$
    terpri()$write "   printlength: ",get(s,'printlength)$
    terpri()$write "   level      : ",get(s,'level)$
    terpri()$write "   allvarfcts : ",get(s,'allvarfcts)$
    terpri()$write "   rational   : ",get(s,'rational)$ 
    terpri()$write "   nonrational: ",get(s,'nonrational)$ 
    terpri()$write "   degrees    : ",get(s,'degrees)$
    terpri()$write "   starde     : ",get(s,'starde)$ 
    terpri()$write "   fcteval_lin: ",get(s,'fcteval_lin)$
    terpri()$write "   fcteval_nca: ",get(s,'fcteval_nca)$
    terpri()$write "   fcteval_nli: ",get(s,'fcteval_nli)$
    terpri()$write "   rl_with    : ",get(s,'rl_with)$ 
    terpri()$write "   dec_with   : ",get(s,'dec_with)$ 
    terpri()$write "   dec_with_rl: ",get(s,'dec_with_rl)$
    terpri()$write "   dec_info   : ",get(s,'dec_info)$ 
    terpri()$write "   to_int     : ",flagp(s,'to_int)$ 
    terpri()$write "   to_sep     : ",flagp(s,'to_sep)$ 
    terpri()$write "   to_gensep  : ",flagp(s,'to_gensep)$ 
    terpri()$write "   to_decoup  : ",flagp(s,'to_decoup)$
    terpri()$write "   to_drop    : ",flagp(s,'to_drop)$
    terpri()$write "   to_eval    : ",flagp(s,'to_eval)$
    terpri()$write "   not_to_eval: ",get(s,'not_to_eval)$
    terpri()$write "   used_      : ",flagp(s,'used_)$
    terpri()$write "   orderings  : ",get(s,'orderings)$
    terpri()>>
 >> >>$

symbolic procedure rationalp(p,f)$
%  tests if p is rational in f and its derivatives
not pairp p
or
((car p='QUOTIENT) and 
 polyp(cadr p,f) and polyp(caddr p,f))
or 
((car p='EQUAL) and
 rationalp(cadr p,f) and rationalp(caddr p,f)) 
or 
polyp(p,f)$

symbolic procedure ratexp(p,ftem)$
if null ftem then t
             else if rationalp(p,car ftem) then ratexp(p,cdr ftem)
                                           else nil$

symbolic procedure polyp(p,f)$
%  tests if p is a polynomial in f and its derivatives
%    p: expression
%    f: function
if my_freeof(p,f) then t
else
begin scalar a$
if atom p then a:=t
else
if member(car p,list('EXPT,'PLUS,'MINUS,'TIMES,'QUOTIENT,'DF)) then
                                        %  erlaubte Funktionen
        <<if (car p='PLUS) or (car p='TIMES) then
                <<p:=cdr p$
                while p do
                    if a:=polyp(car p,f) then p:=cdr p
                                         else p:=nil>>
        else if (car p='MINUS) then
                a:=polyp(cadr p,f)
        else if (car p='QUOTIENT) then
                <<if freeof(caddr p,f) then a:=polyp(cadr p,f)>>
        else if car p='EXPT then        %  Exponent
                <<if (fixp caddr p) then
                   if caddr p>0 then a:=polyp(cadr p,f)>>
        else if car p='DF then          %  Ableitung
                if (cadr p=f) or freeof(cadr p,f) then a:=t>>
else a:=(p=f)$
return a
end$

symbolic procedure starp(ft,n)$
%  yields T if all functions from ft have less than n arguments 
begin scalar b$
  while not b and ft do                % searching a fct of all vars
  if fctlength car ft=n then b:=t
			else ft:=cdr ft$
  return not b
end$

symbolic procedure stardep(ftem,vl)$
%  yields: nil, if a function (from ftem) in p depends
%               on all variables (from vl)
%          cons(v,n) otherweise, with v being the list of variables
%               which occur in a minimal number of n functions
begin scalar b,v,n$
  if starp(ftem,length vl) then
  <<n:=sub1 length ftem$
    while vl do                % searching var.s on which depend a
			       % minimal number of functions
    <<if n> (b:=for each h in ftem sum
				   if member(car vl,fctargs h) then 1
							       else 0)
    then
       <<n:=b$                         % a new minimum
       v:=list car vl>>
    else if b=n then v:=cons(car vl,v)$
    vl:=cdr vl>> >>$
return if v then cons(v,n)             % on each varible from v depend n
				       % functions
	    else nil
end$

symbolic operator parti_fn$
symbolic procedure parti_fn(fl,el)$
% fl ... alg. list of functions, el ... alg. list of equations
% partitions fl such that all functions that are somehow dependent on
% each other through equations in el are grouped in lists, 
% returns alg. list of these lists
begin
 scalar f1,f2,f3,f4,f5,e1,e2;
 fl:=cdr fl;
 el:=cdr el;
 while fl do <<
  f1:=nil;         % f1 is the sublist of functions depending on each other
  f2:=list car fl; % f2 ... func.s to be added to f1, not yet checked
  fl:=cdr fl;
  while f2 and fl do <<
   f3:=car f2; f2:=cdr f2;
   f1:=cons(f3,f1);
   for each f4 in  
   % smemberl will be all functions not registered yet that occur in 
   % an equation in which the function f3 occurs
   smemberl(fl,    % fl ... the remaining functions not known yet to depend
            <<e1:=nil;  % equations in which f3 occurs
              for each e2 in el do 
              if smember(f3,e2) then e1:=cons(e2,e1);
              e1
            >>
           )        do <<
    f2:=cons(f4,f2);
    fl:=delete(f4,fl)
   >>
  >>;
  if f2 then f1:=append(f1,f2);
  f5:=cons(cons('LIST,f1),f5)
 >>;
 return cons('LIST,f5)
end$


%%%%%%%%%%%%%%%%%%%%%%%%%
%  leading derivatives  %
%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure listrel(a,b,l)$
%   a>=b  w.r.t list l; e.g. l='(a b c) ->  a>=a, b>=c 
member(b,member(a,l))$

%symbolic procedure abs_dfrel(p,q,ftem,vl)$
symbolic procedure abs_dfrel(p,q,vl)$
%   the relation "p is a lower derivative than q" (total deg. ord.)
%     p,q  : derivatives or functions from ftem
%     ftem : list of fcts
%     vl   : list of vars
begin scalar a$
return 
if lex_ then dfrel1(p,q,vl) else
if zerop (a:=absdeg(cdar p)-absdeg(cdar q)) then dfrel1(p,q,vl)   
else a<0$
end$

%%symbolic procedure lower_lderiv(p,q,ftem,vl)$
%symbolic procedure lower_lderiv(p,q,vl)$
%%   the relation "p has a lower (absolute) derivative than q" 
%if abs_ld_deriv(p) and abs_ld_deriv(q) then 
%%   abs_dfrel(car get(p,'derivs),car get(q,'derivs),ftem,vl)
%   abs_dfrel(car get(p,'derivs),car get(q,'derivs),vl)
%else if abs_ld_deriv(q) then t$

symbolic procedure mult_derivs(a,b)$
% multiplies deriv. of a and b 
% a,b list of derivs of the form ((fct var1 n1 ...).pow)
begin scalar l$
 return 
  if not b then a
  else if not a then b
  else
   <<
   for each s in a do 
      for each r in b do
        if car s=car r then l:=union(list cons(car r,plus(cdr r,cdr s)),l)
                       else l:=union(list(r,s),l)$
   l>>$
end$

symbolic procedure all_deriv_search(p,ftem)$
%  yields all derivatives occuring polynomially in a pde  p 
begin scalar a$
if not pairp p then 
 <<if member(p,ftem) then a:=list cons(list p,1)>>
else
<<if member(car p,'(PLUS QUOTIENT EQUAL)) then
    for each q in cdr p do
	  a:=union(all_deriv_search(q,ftem),a)
  else if car p='MINUS then a:=all_deriv_search(cadr p,ftem)
  else if car p='TIMES then
    for each q in cdr p do
	  a:=mult_derivs(all_deriv_search(q,ftem),a)
  else if (car p='EXPT) and numberp caddr p then 
      for each b in all_deriv_search(cadr p,ftem) do
          <<if numberp cdr b then 
               a:=cons(cons(car b,times(caddr p,cdr b)),a)>>
  else if (car p='DF) and member(cadr p,ftem) then a:=list cons(cdr p,1) 
>>$
return a
end$

symbolic procedure abs_ld_deriv(p)$
if get(p,'derivs) then reval cons('DF,caar get(p,'derivs))$

symbolic procedure abs_ld_deriv_pow(p)$
if get(p,'derivs) then cdar get(p,'derivs)
                  else 0$

symbolic procedure which_first(a,b,l)$
if null l then nil else
if a = car l then a else
if b = car l then b else which_first(a,b,cdr l)$

symbolic procedure sort_derivs(l,ftem,vl)$
% yields a sorted list of all derivatives in p
begin scalar l1,l2,a,fa$
return
if null l then nil
else
<<a:=car l$
  fa:=caar a$
  l:=cdr l$
  while l do
   <<if fa=caaar l then
%     if abs_dfrel(a,car l,ftem,vl) then l1:=cons(car l,l1)
%                                   else l2:=cons(car l,l2)
     if abs_dfrel(a,car l,vl) then l1:=cons(car l,l1)
                              else l2:=cons(car l,l2)
                   else
     if fa=which_first(fa,caaar l,ftem) then l2:=cons(car l,l2)
                                        else l1:=cons(car l,l1)$
   l:=cdr l>>$
  append(sort_derivs(l1,ftem,vl),cons(a,sort_derivs(l2,ftem,vl)))>>
end$


symbolic procedure dfmax(p,q,vl)$
%   yields the higher derivative
%   vl list of variables e.g. p=((x 2 y 3 z).2), q=((x y 4 z).1)
%                             df(f,x,2,y,3,z)^2, df(f,x,y,4,z)
if dfrel(p,q,vl) then q
		 else p$

symbolic procedure dfrel(p,q,vl)$
%   the relation "p is lower than q"
%   vl list of vars e.g. p=((x 2 y 3 z).2), q=((x y 4 z).1)
if cdr p='infinity then nil
else if cdr q='infinity then t
else begin scalar a$
 return 
  if lex_ then dfrel1(p,q,vl) else
  if zerop(a:=absdeg(car p)-absdeg(car q)) then dfrel1(p,q,vl)
                                           else if a<0 then t
                                                       else nil
end$

symbolic procedure diffrelp(p,q,v)$
%   liefert t, falls p einfacherer Differentialausdruck, sonst nil
%   p, q Paare (liste.power), v Liste der Variablen
%   liste Liste aus Var. und Ordn. der Ableit. in Diff.ausdr.,
%   power Potenz des Differentialausdrucks
if cdr p='infinity then nil
else if cdr q='infinity then t
     else dfrel1(p,q,v)$

symbolic procedure dfrel1(p,q,v)$
if null v then                          %  same derivatives,
   if cdr p>cdr q then nil              %  considering powers
		  else t
else begin
	scalar a,b$
	a:=dfdeg(car p, car v)$
	b:=dfdeg(car q,car v)$
	return if a<b then t
	else if b<a then nil
		else dfrel1(p,q,cdr v)  %  same derivative w.r.t car v
end$

symbolic procedure absdeg(p)$
if null p then 0
else eval cons('PLUS,for each v in p collect if fixp(v) then sub1(v)
                                                        else 1)$

symbolic procedure maxderivs(numberlist,deriv,varlist)$
if null numberlist then 
 for each v in varlist collect dfdeg(deriv,v)
else begin scalar l$
 for each v in varlist do
  <<l:=cons(max(car numberlist,dfdeg(deriv,v)),l)$
  numberlist:=cdr numberlist>>$
 return reverse l
end$
   
symbolic procedure dfdeg(p,v)$
%   yields degree of deriv. wrt. v$
%   e.g p='(x 2 y z 3), v='x --> 2
if null(p:=member(v,p)) then 0           
else if null(cdr p) or not fixp(cadr p) 
        then 1                          %  v without degree
        else cadr p$                    %  v with degree

symbolic procedure df_int(d1,d2)$
begin scalar n,l$
return 
 if d1 then
  if d2 then
   <<n:=dfdeg(d1,car d1)-dfdeg(d2,car d1)$
   l:=df_int(if cdr d1 and numberp cadr d1 then cddr d1
                                           else cdr d1 ,d2)$
   if n<=0 then l
   else if n=1 then cons(car d1,l)
   else cons(car d1,cons(n,l))
   >>
  else d1$
end$

symbolic procedure linear_fct(p,f)$
begin scalar l$
 l:=ld_deriv(p,f)$
 return ((car l=f) and (cdr l=1))
end$

% not used anymore:
%
%symbolic procedure dec_ld_deriv(p,f,vl)$
%%  gets leading derivative of f in p wrt. vars order vl
%%  result: derivative , e.g. '(x 2 y 3 z)
%begin scalar l,d,ld$
% l:=get(p,'derivs)$
% vl:=intersection(vl,get(p,'vars))$
% while caaar l neq f do l:=cdr l$
% ld:=car l$l:=cdr l$
% % --> if lex_ then dfrel1() else
% d:=absdeg(cdar ld)$
% while l and (caaar l=f) and (d=absdeg cdaar l) do
%   <<if dfrel1(ld,car l,vl) then ld:=car l$
%   l:=cdr l>>$
% return cdar ld$
%end$

symbolic procedure ld_deriv(p,f)$
%  gets leading derivative of f in p
%  result: derivative + power , e.g. '((DF f x 2 y 3 z).3)
begin scalar l$
 return if l:=get(p,'derivs) then 
    <<while caaar l neq f do l:=cdr l$
      if l then cons(reval cons('DF,caar l),cdar l)>>
 else cons(nil,0)$
end$

symbolic procedure ldiffp(p,f)$
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion
ld_deriv_search(p,f,fctargs f)$

symbolic procedure ld_deriv_search(p,f,vl)$
%  gets leading derivative of funktion f in expr. p w.r.t
%  list of variables vl
begin scalar a$
if p=f then a:=cons(nil,1)
else
<<a:=cons(nil,0)$
if pairp p then
  if member(car p,'(PLUS TIMES QUOTIENT EQUAL)) then
     <<p:=cdr p$
       while p do
	 <<a:=dfmax(ld_deriv_search(car p,f,vl),a,vl)$    
	   if cdr a='infinity then p:=nil
			      else p:=cdr p
	 >>
     >>
  else if car p='MINUS then a:=ld_deriv_search(cadr p,f,vl)
  else if car p='EXPT then 
     <<a:=ld_deriv_search(cadr p,f,vl)$    
       if numberp cdr a then
	  if numberp caddr p
	  then a:=cons(car a,times(caddr p,cdr a))
	  else if not zerop cdr a
	    then a:=cons(nil,'infinity)
	    else if not my_freeof(caddr p,f)
	            then a:=cons(nil,'infinity)
     >>
  else if car p='DF then 
	   if cadr p=f then a:=cons(cddr p,1) 
	   else if my_freeof(cadr p,f) 
		then a:=cons(nil,0)                       %  a constant
		else a:=cons(nil,'infinity)
  else if my_freeof(p,f) then a:=cons(nil,0)
		       else a:=cons(nil,'infinity)
>>$
return a
end$

symbolic procedure lderiv(p,f,vl)$
%  fuehrende Ableitung in LISP-Notation mit Potenz (als dotted pair)
begin scalar l$
l:=ld_deriv_search(p,f,vl)$
return cons(if car l then cons('DF,cons(f,car l))
		  else if zerop cdr l then nil
			  else f
		,cdr l)
end$

symbolic procedure splitinhom(q,ftem,vl)$
% Splitting the equation q into the homogeneous and inhom. part
% returns dotted pair qhom . qinhom
begin scalar qhom,qinhom,denm;
  vl:=varslist(q,ftem,vl)$
  if pairp q and (car q = 'QUOTIENT) then 
  if starp(smemberl(ftem,caddr q),length vl) then 
  <<denm:=caddr q; q:=cadr q>>        else return (q . 0)
                                     else denm:=1;

  if pairp q and (car q = 'PLUS) then q:=cdr q
				 else q:=list q;
  while q do <<
   if starp(smemberl(ftem,car q),length vl) then qinhom:=cons(car q,qinhom)
      	       	     	      	     else qhom  :=cons(car q,qhom);
   q:=cdr q
  >>;
  if null qinhom then qinhom:=0
		 else
  if length qinhom > 1 then qinhom:=cons('PLUS,qinhom)
		       else qinhom:=car qinhom;
  if null qhom then qhom:=0
	       else
  if length qhom   > 1 then qhom:=cons('PLUS,qhom)
		       else qhom:=car qhom;
  if denm neq 1 then <<qhom  :=list('QUOTIENT,  qhom,denm);
                       qinhom:=list('QUOTIENT,qinhom,denm)>>;
  return qhom . qinhom
end$

symbolic procedure search_den(l)$
% get all denominators and arguments of LOG,... anywhere in a list l
begin scalar l1$
if pairp l then 
 if car l='quotient then 
  l1:=union(cddr l,union(search_den(cadr l),search_den(caddr l)))
 else if member(car l,'(log ln logb log10)) then 
  if pairp cadr l and (caadr l='QUOTIENT) then 
   l1:=union(list cadadr l,search_den(cadr l))
  else l1:=union(cdr l,search_den(cadr l))
 else for each s in l do l1:=union(search_den(s),l1)$
return l1$
end$

symbolic procedure zero_den(l,ftem,vl)$
begin scalar cases$
 l:=search_den(l)$
 while l do <<
  if not freeofzero(car l,ftem,vl) then cases:=cons(car l,cases);
  l:=cdr l
 >>$
 return cases
end$

symbolic procedure forg_int (forg,fges)$
for each ex in forg collect
 if pairp ex and pairp cadr ex then forg_int_f(ex,smemberl(fges,ex))
                             else ex$

symbolic procedure forg_int_f(ex,fges)$
% try to integrate expr. ex of the form df(f,...)=expr.
begin scalar p,h,f$
 p:=caddr ex$
 f:=cadadr ex$
 if pairp p and (car p='PLUS)
    then p:=reval cons('PLUS,cons(list('MINUS,cadr ex),cdr p))
    else p:=reval list('DIFFERENCE,p,cadr ex)$
 p:=integratepde(p,cons(f,fges),nil,nil,nil)$
 if p and (car p) and not cdr p then 
    <<h:=car lderiv(car p,f,fctargs f)$
    p:=reval list('PLUS,car p,h)$
    ftem_:=reverse ftem_$
    for each ff in reverse fnew_ do
      if not member(ff,ftem_) then ftem_:=fctinsert(ff,ftem_)$
    ftem_:=reverse ftem_$
    ex:=list('EQUAL,h,p)>>$
 return ex
end$

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  general purpose procedures  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure smemberl(fl,ex)$
%  smember for a list
if fl and ex then
if smember(car fl,ex) then cons(car fl,smemberl(cdr fl,ex))
                       else smemberl(cdr fl,ex)$
                       
symbolic operator my_freeof$
symbolic procedure my_freeof(u,v)$
%  a patch for FREEOF in REDUCE 3.5
not(smember(v,u)) and freeofdepl(depl!*,u,v)$

lisp flag('(my_freeof),'BOOLEAN)$

symbolic procedure freeoflist(l,m)$
%   liefert t, falls kein Element aus m in l auftritt
if null m then t
else if freeof(l,car m) then freeoflist(l,cdr m)
                        else nil$

symbolic procedure freeofdepl(de,u,v)$
if null de then t
else if smember(v,cdar de) and smember(caar de,u) then nil
else freeofdepl(cdr de,u,v)$

symbolic procedure fctinsert(f,ftem)$
% isert a function f in the function list ftem
if null ftem then list f
else if fctlength car ftem >= fctlength f then cons(f,ftem)
else cons(car ftem,fctinsert(f,cdr ftem))$

symbolic procedure newfct(id,l,nfct)$
begin scalar f$
f:=mkid(id,nfct)$
depl!*:=delete(assoc(f,depl!*),depl!*)$
%put(f,'simpfn,'simpiden)$
%if pairp l then f:=cons(f,l)$
if pairp l then depl!*:=cons(cons(f,l),depl!*)$
if print_ then
   <<terpri()$
   if pairp l then
     <<write "new function: "$
     fctprint list f>>
   else
     write "new constant: ",f>>$
return f$
end$

symbolic procedure varslist(p,ftem,vl)$
begin scalar l$
ftem:=argset smemberl(ftem,p)$
for each v in vl do
  if not my_freeof(p,v) or member(v,ftem) then l:=cons(v,l)$
return reverse l$
end$

symbolic procedure var_list(pdes,forg,vl)$
begin scalar l,l1$
for each p in pdes do l:=union(get(p,'vars),l)$
for each v in vl do
  if member(v,l) or not my_freeof(forg,v) then l1:=cons(v,l1)$
return reverse l1$
end$

symbolic procedure fctlist(ftem,pdes,forg)$
begin scalar fges,l$
 for each p in pdes do l:=union(get(p,'fcts),l)$
 for each f in ftem do
     if not my_freeof(forg,f) or member(f,l) then fges:=fctinsert(f,fges)$ 
 for each f in forg do
     if not pairp f and not member(f,fges) then fges:=fctinsert(f,fges)$
 for each f in l do
     if not member(f,fges) then fges:=fctinsert(f,fges)$
 return reverse fges$
end$   

symbolic operator fargs$
symbolic procedure fargs f$
cons('LIST,fctargs f)$

symbolic procedure fctargs f$
%  arguments of a function
if (f:=assoc(f,depl!*)) then cdr f$

symbolic procedure fctlength f$
%  number of arguments
length fctargs f$

symbolic procedure fctsort(l)$
% list sorting
begin scalar l1,l2,l3,m,n$
return
if null l then nil
else
<<n:=fctlength car l$
  l2:=list car l$
  l:=cdr l$
  while l do
   <<m:=fctlength car l$
   if m<n then l1:=cons(car l,l1)
   else if m>n then l3:=cons(car l,l3)
   else l2:=cons(car l,l2)$
   l:=cdr l>>$
  append(fctsort reverse l3,append(reverse l2,fctsort reverse l1))>>
end$

symbolic procedure listprint(l)$
%   print a funktion
if pairp l then
 <<write car l$
 for each v in cdr l do
   <<write ","$write v>> >>$ 

symbolic procedure fctprint1(f)$
%   print a funktion
if f then
 if pairp f then
  <<write car f$
  if pairp cdr f then
   <<write "("$
   listprint cdr f$
   write ")">>
  >>
 else write f$

symbolic procedure fctprint(fl)$
%   Ausdrucken der Funktionen aus fl
begin scalar n,l,f$
n:=0$
while fl do
   <<f:=car fl$
   fl:=cdr fl$
   if pairp f then
      if car f='EQUAL then
        <<n:=delength f$
        if (null print_) or (n>print_) then
          <<terpri()$write cadr f,"= expr. with ",n," terms"$
          if (l:=get(cadr f,'fcts)) then
             <<write " in "$
             myprin2l(l,", ")>>$
          terpri()>>
        else mathprint f$
        n:=0>>
      else
         <<if n eq 4 then
              <<terpri()$n:=0>>$
         fctprint1 f$
         if fl then write ", "$
         n:=add1 n>>
   else 
       <<if n eq 4 then
            <<terpri()$n:=0>>$
       l:=assoc(f,depl!*)$
       fctprint1 if l then l
                      else f$
       if fl then write ", "$
       n:=add1 n>>
   >>$
%if n neq 0 then terpri()
end$

symbolic procedure deprint(l)$
%   Ausdrucken der Gl. aus der Liste l
if l and print_ then for each x in l do eqprint list('EQUAL,0,x)$

symbolic procedure eqprint(e)$
%   Ausdrucken der Gl. e
if print_ then
 begin scalar n$
 n:=delength e$
 if n>print_ then
        <<write "expr. with "$write n$write " terms"$
          terpri()
        >>
 else
        mathprint e$
end$

symbolic procedure print_level$
if print_ and level_ then <<
 terpri()$
 write "New level : "$
 for each m in reverse level_ do write m,"."$
>>$

symbolic procedure print_statistic(pdes,fcts)$
if print_ then begin
 integer j,k,le,r,s$
 scalar n,m,p,el,fl,vl$

 %--- printing the stats of equations:
 if pdes then <<
  terpri()$write "number of equations : ",length pdes$
  terpri()$write "total no of terms   : ",
  j:=for each p in pdes sum get(p,'terms)$
  k:=for each p in pdes sum get(p,'length)$
  if k neq j then <<terpri()$write "total no of factors :  ",k>>$

  while pdes do <<
   j:=0;
   el:=nil;
   for each p in pdes do <<
    vl:=get(p,'vars);
    if vl then le:=length vl
          else le:=0;
    if ((j=0) and null vl) or
       (j=le) then el:=cons(p,el)
              else if j<le then <<
     j:=le;
     el:=list(p)
    >>
   >>;
   pdes:=setdiff(pdes,el);
   if el then <<
    n:=length el$
    terpri()$write n," equation"$
    if n>1 then write"s"$write" in ",j," variable"$
    if j neq 1 then write"s"$
    write": "$
    k:=0;
    while el do <<
     if k=4 then <<k:=0;terpri()>>
            else k:=add1 k$
     write car el,"(",get(car el,'length)$
     if (s:=get(car el,'starde)) then 
     for r:=1:(1+cdr s) do write"*"$
     write")"$
     el:=cdr el$
     if el then write","$
    >>
   >>$
   j:=add1 j;
  >>
 >>
 else <<terpri()$write "no equations">>$
 %--- printing the stats of functions:
 for each f in fcts do if not pairp f then fl:=cons(f,fl)$
 if fl then <<
  fl:=fctsort reverse fl$
  m:=fctlength car fl$
  while m>=0 do <<
   n:=0$
   el:=nil;
   while fl and (fctlength car fl=m) do <<
    n:=add1 n$
    el:=cons(car fl,el)$
    fl:=cdr fl
   >>$
   if n>0 then
   if m>0 then <<
    terpri()$
    write n," function"$
    if n>1 then write"s"$
    write" with ",m," argument",if m>1 then "s : "
                                       else "  : "
   >>     else <<
    terpri()$
    write n," constant"$
    if n>1 then write"s"$
    write" : "
   >>$
   k:=0;
   while el do <<
    if k=10 then <<k:=0;terpri()>>
            else k:=add1 k$
    write car el$
    el:=cdr el$
    if el then write","$
   >>$
   m:=if fl then fctlength car fl
            else -1
  >> 
 >>    else <<terpri()$write "no functions or constants">>$
 terpri()$
end$

symbolic procedure print_pde_ineq(pdes,ineqs)$
% print all pdes and ineqs
<<if pdes then
      <<terpri()$terpri()$write "equations : "$
      typeeqlist(pdes)>>
   else
      <<terpri()$terpri()$write "no equations">>$
 if ineqs then
    <<terpri()$write "non-vanishing expressions: "$
    for each aa in ineqs do eqprint aa>>$
>>$

symbolic procedure print_fcts(fcts,vl)$
% print all fcts and vars
<<if fcts then
         <<terpri()$write "functions : "$
         fctprint(fcts)>>$
 if vl then
         <<terpri()$write "variables : "$
         fctprint(vl)>>$
>>$

symbolic procedure print_pde_fct_ineq(pdes,ineqs,fcts,vl)$
% print all pdes, ineqs and fcts
if print_ then begin$
 print_pde_ineq(pdes,ineqs)$
 print_fcts(fcts,vl)$
 print_statistic(pdes,fcts)
end$ 

symbolic procedure no_of_terms(d)$
if not pairp d then if d then 1
                         else 0
               else if car d='PLUS then length d - 1
                                   else 1$

symbolic procedure delength(d)$
%   Laenge eines Polynoms in LISP - Notation
if not pairp d then 
 if d then 1
      else 0
else
if (car d='PLUS) or (car d='TIMES) or (car d='QUOTIENT) 
   or (car d='MINUS) or (car d='EQUAL)
   then for each a in cdr d sum delength(a) 
else 1$

symbolic procedure pdeweight(d,ftem)$
%   Laenge eines Polynoms in LISP - Notation
if not smemberl(ftem,d) then 0
else if not pairp d then 1
else if (car d='PLUS) or (car d='TIMES) or (car d='EQUAL)
        or (car d='QUOTIENT) then
         for each a in cdr d sum pdeweight(a,ftem)
else if (car d='EXPT) then 
        if numberp caddr d then
         caddr d*pdeweight(cadr d,ftem)
        else 1
else 1$

symbolic procedure desort(l)$
% list sorting
begin scalar l1,l2,l3,m,n$
return
if null l then nil
else
<<n:=delength car l$
  l2:=list car l$
  l:=cdr l$
  while l do
   <<m:=delength car l$
   if m<n then l1:=cons(car l,l1)
   else if m>n then l3:=cons(car l,l3)
   else l2:=cons(car l,l2)$
   l:=cdr l>>$
  append(desort(l1),append(l2,desort(l3)))>>
end$

symbolic procedure argset(ftem)$
%  List of arguments of all functions in ftem
if ftem then union(reverse fctargs car ftem,argset(cdr ftem))
        else nil$

symbolic procedure backup_pdes(pdes,forg)$
%  make a backup of all pdes
begin scalar cop$
 cop:=list(nequ_,
           for each p in pdes collect 
               list(p,
                    for each q in prop_list collect cons(q,get(p,q)),
                    for each q in allflags_ collect if flagp(p,q) then q),
           for each f in forg collect
               if pairp f then cons(cadr f,get(cadr f,'fcts))
                          else cons(f,get(f,'fcts)),
           ftem_,
           ineq_)$
 return cop
end$ 

symbolic procedure restore_pdes(cop)$
%  restore the pde list cop 
%  first element must be the old value of nequ_ 
%  the elements must have the form (p . property_list_of_p)
begin scalar pdes$
  % delete all new produced pdes
  for i:=car cop:sub1 nequ_ do setprop(mkid(eqname_,i),nil)$
  nequ_:=car cop$
  for each c in cadr cop do
    <<pdes:=cons(car c,pdes)$
    for each s in cadr c do
        put(car c,car s,cdr s)$
    for each s in caddr c do 
        if s then flag1(car c,s)$
    >>$
  for each c in caddr cop do
    put(car c,'fcts,cdr c)$
  ftem_:=cadddr cop$
  ineq_:=car cddddr cop$
  return reverse pdes$
end$

symbolic procedure copy_from_backup(copie)$
%  restore the pde list copie
%  first element must be the old value of nequ_ 
%  the elements must have the form (p . property_list_of_p)
begin scalar l,pdes,cop$
  cop:=cadr copie$         
  l:=cop$
  for i:=1:length cop do
    <<pdes:=cons(mkid(eqname_,nequ_),pdes)$
    setprop(car pdes,nil)$
    nequ_:=add1 nequ_>>$
  pdes:=reverse pdes$
  for each p in pdes do  
    <<cop:=subst(p,caar l,cop)$
    l:=cdr l>>$
  for each c in cop do
    <<for each s in cadr c do
        put(car c,car s,cdr s)$
    for each s in caddr c do 
        if s then flag1(car c,s)$
    >>$
  for each c in caddr copie do
    put(car c,'fcts,cdr c)$
  ftem_:=cadddr copie$
  return pdes$
end$

symbolic procedure deletepde(pdes)$
begin scalar s,ps$
 ps:=promptstring!*$
 promptstring!*:=""$ 
 terpri()$
 write "pde to be deleted: "$
 s:=termread()$
 promptstring!*:=ps$
 if member(s,pdes) then setprop(s,nil)$
 return delete(s,pdes)$
end$

symbolic procedure addfunction(ft)$
begin scalar f,l,ps$
 ps:=promptstring!*$
 promptstring!*:=""$ 
 terpri()$
 write "What is the name of the new function? "$
 terpri()$
 write "(terminate with Enter, no ; or $) "$
 f:=termread()$
 depl!*:=delete(assoc(f,depl!*),depl!*)$
 terpri()$
 write "Give a list of variables ",f," depends on, for example x,y,z;  "$ 
 terpri()$
 write "If ",f," shall be constant then just input ;  "$
 l:=termxread()$
 if (pairp l) and (car l='!*comma!*) then l:=cdr l;
 if pairp l then depl!*:=cons(cons(f,l),depl!*) else
 if l then depl!*:=cons(list(f,l),depl!*)$
 ft:=fctinsert(f,ft)$
 promptstring!*:=ps$
 return ft
end$

symbolic procedure change_pde_flag(pdes)$
begin scalar p,fla$
 repeat <<
  terpri()$
  write "From which PDE do you want to change a flag, e.g. e23?"$
  terpri()$
  p:=termread()$
 >> until not freeof(pdes,p)$
 repeat <<
  terpri()$
  write "Type in one of the following flags which should be flipped:"$
  terpri()$
  write allflags_;
  terpri()$
  fla:=termread()$
 >> until not freeof(allflags_,fla)$
 if flagp(p,fla) then remflag1(p,fla)
                 else flag(list(p),fla)
end$

symbolic procedure write_in_file(pdes,ftem)$
begin scalar p,pl,s,h,ps,wn$
  ps:=promptstring!*$
  promptstring!*:=""$ 
  terpri()$
  write "Enter a list of equations, like e2,e5,e35; from: "$terpri()$
  fctprint pdes$terpri()$
  write "To write all equations just enter ; "$terpri()$
  repeat <<
    s:=termxread()$
    h:=s;
    if s=nil then pl:=pdes else
    if s and (car s='!*comma!*) then <<
      s:=cdr s;
      pl:=nil;h:=nil$
      if (null s) or pairp s then <<
        for each p in s do
        if member(p,pdes) then pl:=cons(p,pl);
        h:=setdiff(pl,pdes);
      >> else h:=s;
    >>;
    if h then <<write "These are no equations: ",h,"   Try again."$terpri()>>$
  >> until null h$
  write"Shall the name of the equation be written? (y/n) "$
  repeat s:=termread()
  until (s='y) or (s='Y) or (s='n) or (s='N)$
  if (s='y) or (s='Y) then wn:=t$
  write"Please give the name of the file (without ;) : "$
  s:=termread()$
  off nat;
  out s;
  for each h in ftem do 
  if assoc(h,depl!*) then <<
    p:=pl;
    while p and freeof(get(car p,'val),h) do p:=cdr p;
    if p then <<
      write"depend ",h$
      for each v in cdr assoc(h,depl!*) do write ",",v$
      write"$"$terpri()
    >>
  >>$
  if wn then
  for each h in pl do algebraic write h,":=",lisp get(h,'val)
        else
  for each h in pl do algebraic write lisp get(h,'val)$
  write"end$"$terpri()$
  shut s;
  on nat;
  promptstring!*:=ps$
end$

symbolic procedure replacepde(pdes,ftem,vl)$
begin scalar p,q,ex,ps,h$
 ps:=promptstring!*$
 promptstring!*:=""$ 
 repeat <<
  terpri()$
  write "Is there a (further) new function in the changed/new PDE that"$
  terpri()$
  write "is to be calculated (y/n)? "$
  p:=termread()$
  if (p='y) or (p='Y) then ftem:=addfunction(ftem)
 >> until (p='n) or (p='N)$
 terpri()$
 write "If you want to replace a pde then type its name, e.g. e23."$
 terpri()$
 write "If you want to add a pde then type `new_pde'. "$
 terpri()$
 write "In both cases terminate with Enter (no ; or $) : "$
 p:=termread()$
 if (p='NEW_PDE) or member(p,pdes) then
  <<terpri()$write "Input of a value for "$
  if p='new_pde then write "the new pde."
                else write p,"."$
  terpri()$
  write "You can use names of other pds, e.g. 3*e12 - df(e13,x)."$
  terpri()$
  write "Terminate the expression with ; or $ : "$
  terpri()$
  ex:=termxread()$
  for each a in pdes do ex:=subst(get(a,'val),a,ex)$
  terpri()$
  write "Do you want the equation to be"$terpri()$
  write "- left completely unchanged"$
  terpri()$
  write "  (e.g. to keep the structure of a product to "$
  terpri()$
  write "   investigate subcases)                        (1)"$
  terpri()$
  write "- simplified (e.g. e**log(x) -> x) without"$
  terpri()$
  write "  dropping non-zero factors and denominators"$
  terpri()$
  write "  (e.g. to introduce integrating factors)       (2)"$
  terpri()$
  write "- simplified completely                         (3) "$
  h:=termread()$
  if h=2 then ex:=reval ex$
  if h<3 then h:=nil
         else h:=t$
  if p neq 'NEW_PDE then <<setprop(p,nil)$pdes:=delete(p,pdes)>>$
  q:=mkeq(ex,ftem,vl,allflags_,h,list(0))$
  terpri()$write q$
  if p='NEW_PDE then write " is added"
                else write " replaces ",p$
  pdes:=eqinsert(q,pdes)>>
 else <<terpri()$
        write "A pde ",p," does not exist! (Back to previous menu)">>$
 promptstring!*:=ps$
 return list(pdes,ftem)
end$

symbolic procedure selectpdes(pdes,n)$
% interactive selection of n pdes  
% n may be an integer or nil. If nil then the
% number of pdes is free.
if pdes then
begin scalar l,s,ps,m$
 ps:=promptstring!*$
 promptstring!*:=""$ 
 terpri()$
 if null n then <<
  write "How many equations do you want to select? "$terpri()$
  write "(number <ENTER>) : "$terpri()$
  n:=termread()$
 >>$ 
 write "Please select ",n," equation"$
 if n>1 then write "s"$write " from: "$
 fctprint pdes$terpri()$
 m:=0$
 s:=t$
 while (m<n) and s do
  <<m:=add1 m$
  if n>1 then write m,". "$
  write "pde: "$
  s:=termread()$
  while not member(s,pdes) do
   <<write "Error!!! Please select a pde from: "$
   fctprint pdes$
   terpri()$if n>1 then write m,". "$
   write "pde: "$
   s:=termread()>>$
  if s then
   <<pdes:=delete(s,pdes)$
   l:=cons(s,l)>> >>$
 promptstring!*:=ps$
 return reverse l$
end$

symbolic operator nodepnd$
symbolic procedure nodepnd(fl)$
for each f in cdr fl do
depl!*:=delete(assoc(reval f,depl!*),depl!*)$

symbolic operator err_catch_sub$
symbolic procedure err_catch_sub(h2,h6,h3)$
% do sub(h2=h6,h3) with error catching
begin scalar h4,h5;
 h4 := list('EQUAL,h2,h6);
 h5:=errorset({'subeval,mkquote{reval h4, 
                                reval h3 }},nil,nil)
     where !*protfg=t;
 erfg!*:=nil;
 return if errorp h5 then nil
                     else car h5   
end$

symbolic operator low_mem$
% if garbage collection recovers only 500000 cells then backtrace
% to be used only on workstations, not PCs i.e. under LINUX, Windows

symbolic procedure newreclaim()$
   <<oldreclaim();
     if (known!-free!-space() < 500000 ) then backtrace()
   >>$

symbolic procedure low_mem()$
if not( getd 'oldreclaim) then <<
    copyd('oldreclaim,'!%reclaim);
    copyd('!%reclaim,'newreclaim);
>>$

symbolic operator polyansatz$
symbolic procedure polyansatz(ev,iv,fn,ordr)$
% ev, iv are algebraic mode lists
% generates a polynomial in the variables ev of order ordr
% with functions of the variables iv
begin scalar a,fi,el1,el2,f,fl,p,pr;
 a:=reval list('EXPT,cons('PLUS,cons(1,cdr ev)),ordr)$
 a:=reverse cdr a$
 fi:=0$
 iv:=cdr iv$
 for each el1 in a collect <<
  if (not pairp el1) or
     (car el1 neq 'TIMES) then el1:=list el1
                          else el1:=cdr el1;
  f:=newfct(fn,iv,fi);
  fi:=add1 fi;
  fl:=cons(f,fl)$
  pr:=list f$
  for each el2 in el1 do
  if not fixp el2 then pr:=cons(el2,pr);
  if length pr>1 then pr:=cons('TIMES,pr)
                 else pr:=car pr;
  p:=cons(pr,p)
 >>$
 p:=reval cons('PLUS,p)$
 return list('LIST,p,cons('LIST,fl))
end$

symbolic operator polyans$
symbolic procedure polyans(ordr,dgr,x,y,d_y,fn)$
% generates a polynom
% for i:=0:dgr sum fn"i"(x,y,d_y(1),..,d_y(ordr-1))*d_y(ordr)**i
% with fn as the function names and d_y as names or derivatives of y
% w.r.t. x
begin scalar ll,fl,a,i,f$
    i:=sub1 ordr$
    while i>0 do
	  <<ll:=cons(list(d_y,i),ll)$
	  i:=sub1 i>>$
    ll:=cons(y,ll)$
    ll:=reverse cons(x,ll)$
    fl:=nil$
    i:=0$
    while i<=dgr do
    <<f:=newfct(fn,ll,i)$
      fl:=(f . fl)$
      a:=list('PLUS,list('TIMES,f,list('EXPT,list(d_y,ordr),i)),a)$
      i:=add1 i>>$
    return list('list,reval a,cons('list,fl))
end$ % of polyans

symbolic operator sepans$
symbolic procedure sepans(kind,v1,v2,fn)$
% Generates a separation ansatz
% v1,v2 = lists of variables, fn = new function name + index added
% The first variable of v1 occurs only in one sort of the two sorts of
% functions and the remaining variables of v1 in the other sort of
% functios.
% The variables of v2 occur in all functions.
% Returned is a sum of products of each one function of both sorts.
% form: fn1(v11;v21,v22,v23,..)*fn2(v12,..,v1n;v21,v22,v23,..)+...
% the higher "kind", the more general and difficult the ansatz is
% kind = 0 is the full case
begin scalar n,vl1,vl2,h1,h2,h3,h4,fl$
  if cdr v1 = nil then <<vl1:=cdr v2$vl2:=cdr v2>>
		  else <<vl1:=cons(cadr v1,cdr v2)$
			 vl2:=append(cddr v1,cdr v2)>>$
  return
  if kind = 0 then <<vl1:=append(cdr v1,cdr v2)$
		     h1:=newfct(fn,vl1,'_)$
		     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 1 then <<h1:=newfct(fn,vl1,1)$
		     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 2 then <<h1:=newfct(fn,vl2,1)$
		     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 3 then <<h1:=newfct(fn,vl1,1)$
		     h2:=newfct(fn,vl2,2)$
		     list('LIST,reval list('PLUS,h1,h2),
			  list('LIST,h1,h2))>>
  else
  if kind = 4 then <<h1:=newfct(fn,vl1,1)$
		     h2:=newfct(fn,vl2,2)$
		     list('LIST,reval list('TIMES,h1,h2),
			  list('LIST,h1,h2))>>
  else
  if kind = 5 then <<h1:=newfct(fn,vl1,1)$
		     h2:=newfct(fn,vl2,2)$
		     h3:=newfct(fn,vl1,3)$
		     list('LIST,reval list('PLUS,list('TIMES,h1,h2),h3),
			  list('LIST,h1,h2,h3))>>
  else
  if kind = 6 then <<h1:=newfct(fn,vl1,1)$
		     h2:=newfct(fn,vl2,2)$
		     h3:=newfct(fn,vl2,3)$
		     list('LIST,reval list('PLUS,list('TIMES,h1,h2),h3),
			  list('LIST,h1,h2,h3))>>
  else
  if kind = 7 then <<h1:=newfct(fn,vl1,1)$
		     h2:=newfct(fn,vl2,2)$
		     h3:=newfct(fn,vl1,3)$
		     h4:=newfct(fn,vl2,4)$
		     list('LIST,reval list('PLUS,
			  list('TIMES,h1,h2),h3,h4),
			  list('LIST,h1,h2,h3,h4))>>
  else
% ansatz of the form FN = FN1(v11,v2) + FN2(v12,v2) + ... + FNi(v1i,v2)
  if kind = 8 then <<n:=1$ vl1:=cdr v1$ vl2:=cdr v2$
		    fl:=()$
		     while vl1 neq () do <<
		       h1:=newfct(fn,cons(car vl1,vl2),n)$
		       vl1:=cdr vl1$
		       fl:=cons(h1, fl)$
		       n:=n+1 
		     >>$
		     list('LIST, cons('PLUS,fl), cons('LIST,fl))>>
		       

  else
		   <<h1:=newfct(fn,vl1,1)$
		     h2:=newfct(fn,vl2,2)$
		     h3:=newfct(fn,vl1,3)$
		     h4:=newfct(fn,vl2,4)$
		     list('LIST,reval list('PLUS,list('TIMES,h1,h2),
						 list('TIMES,h3,h4)),
			  list('LIST,h1,h2,h3,h4))>>
end$ % of sepans

%
% Orderings support!
%
% change_derivs_ordering(pdes,vl,fl) changes the ordering of the
% list of derivatives depending on the current ordering (this
% is detected "automatically" by sort_derivs using the lex_ flag to
% toggle between total-degree and lexicogrpahic.
%
symbolic procedure change_derivs_ordering(pdes,fl,vl)$
begin scalar p, dl;
   for each p in pdes do <<
      if tr_orderings then <<
	 terpri()$
	 write "Old: ", get(p,'derivs)$
      >>$
      dl := sort_derivs(get(p,'derivs),fl,vl)$
      if tr_orderings then <<
	 terpri()$
	 write "New: ", dl$
      >>$
      put(p,'derivs,dl)$
   >>$
   return pdes
end$

%
% check_globals() is used to check that the values with which CRACK is
% being called are coherent and/or valid.
%
% !FIXME! would be nice if we had a list which we could use to store
% the global variables and the associated valid values.
%
symbolic procedure check_globals()$
begin scalar flag$
   flag := nil$
   if !*batch_mode neq nil and !*batch_mode neq t then
   <<   
      terpri()$
      write "!*batch_mode needs to be a boolean: ",
	 !*batch_mode," is invalid"$
      flag := t$
   >>$
   if printmenu_ neq nil and printmenu_ neq t then
   <<
      terpri()$
      write "printmenu_ needs to be a boolean: ",
	 printmenu_," is invalid"$
      flag := t$
   >>$
   if expert_mode neq nil and expert_mode neq t then
   <<
      terpri()$
      write "expert_mode needs to be a boolean: ",
	 expert_mode," is invalid"$
      flag := t$
   >>$
   if repeat_mode neq nil and repeat_mode neq t then
   <<
      terpri()$
      write "repeat_mode needs to be a boolean: ",
	 repeat_mode," is invalid"$
      flag := t$
   >>$
   if not fixp genint_ and genint_ neq nil then
   <<
      terpri()$
      write "genint_ needs to be an integer or nil: ",
	 genint_," is invalid"$
      flag := t$
   >>$
   if not fixp facint_ and facint_ neq nil then
   <<
      terpri()$
      write "facint_ needs to be an integer or nil: ",
	 facint_," is invalid"$
      flag := t$
   >>$
   if potint_ neq nil and potint_ neq t then
   <<
      terpri()$
      write "potint_ needs to be a boolean: ",
	 potint_," is invalid"$ 
      flag := t$
   >>$
   if safeint_ neq nil and safeint_ neq t then
   <<
      terpri()$
      write "safeint_ needs to be a boolean: ",
	 safeint_," is invalid"$
      flag := t$
   >>$
   if freeint_ neq nil and freeint_ neq t then
   <<
      terpri()$
      write "potint_ needs to be a boolean: ",
	 potint_," is invalid"$
      flag := t$
   >>$
   if not fixp odesolve_ then
   <<
      terpri()$
      write "odesolve_ needs to be an integer: ",
	 odesolve_," is invalid"$
      flag := t$
   >>$
   if not fixp max_factor then
   <<
      terpri()$
      write "max_factor needs to be an integer: ",
	 max_factor," is invalid"$
      flag := t$
   >>$
   if not fixp gensep_ then
   <<
      terpri()$
      write "gensep_ needs to be an integer: ",
	 gensep_," is invalid"$
      flag := t$
   >>$
   if not fixp new_gensep and new_gensep neq nil then
   <<
      terpri()$
      write "new_gensep needs to be an integer or nil: ",
	 new_gensep," is invalid"$
      flag := t$
   >>$
   if not fixp subst_0 then
   <<
      terpri()$
      write "subst_0 needs to be an integer: ",
	 subst_0," is invalid"$
      flag := t$
   >>$      
   if not fixp subst_1 then
   <<
      terpri()$
      write "subst_1 needs to be an integer: ",
	 subst_1," is invalid"$
      flag := t$
   >>$      
   if not fixp subst_2 then
   <<
      terpri()$
      write "subst_2 needs to be an integer: ",
	 subst_2," is invalid"$
      flag := t$
   >>$      
   if not fixp subst_3 then
   <<
      terpri()$
      write "subst_3 needs to be an integer: ",
	 subst_3," is invalid"$
      flag := t$
   >>$      
   if not fixp subst_4 then
   <<
      terpri()$
      write "subst_4 needs to be an integer: ",
	 subst_4," is invalid"$
      flag := t$
   >>$      
   if not fixp cost_limit5 then
   <<
      terpri()$
      write "cost_limit5 needs to be an integer: ",
	 cost_limit5," is invalid"$ 
      flag := t$
   >>$      
   if not fixp max_red_len then
   <<
      terpri()$
      write "max_red_len needs to be an integer: ",
	 max_red_len," is invalid"$ 
      flag := t$
   >>$
   if not fixp pdelimit_0 and pdelimit_0 neq nil then
   <<
      terpri()$
      write "pdelimit_0 needs to be an integer or nil: ",
	 pdelimit_0," is invalid"$ 
      flag := t$
   >>$
   if not fixp pdelimit_1 and pdelimit_1 neq nil then
   <<
      terpri()$
      write "pdelimit_1 needs to be an integer or nil: ",
	 pdelimit_1," is invalid"$ 
      flag := t$
   >>$
   if not fixp pdelimit_2 and pdelimit_2 neq nil then
   <<
      terpri()$
      write "pdelimit_2 needs to be an integer or nil: ",
	 pdelimit_2," is invalid"$ 
      flag := t$
   >>$
   if not fixp pdelimit_3 and pdelimit_3 neq nil then
   <<
      terpri()$
      write "pdelimit_3 needs to be an integer or nil: ",
	 pdelimit_3," is invalid"$ 
      flag := t$
   >>$
   if not fixp pdelimit_4 and pdelimit_4 neq nil then
   <<
      terpri()$
      write "pdelimit_4 needs to be an integer or nil: ",
	 pdelimit_4," is invalid"$ 
      flag := t$
   >>$
   if not numberp length_inc then
   <<
      terpri()$
      write "length_inc needs to be an number: ",
	 length_inc," is invalid"$ 
      flag := t$
   >>$
   if tr_main neq t and tr_main neq nil then
   <<
      terpri()$
      write "tr_main needs to be a boolean: ",
	 tr_main," is invalid"$
      flag := t$
   >>$
   if tr_gensep neq t and tr_gensep neq nil then
   <<
      terpri()$
      write "tr_gensep needs to be a boolean: ",
	 tr_gensep," is invalid"$
      flag := t$
   >>$
   if tr_genint neq t and tr_genint neq nil then
   <<
      terpri()$
      write "tr_genint needs to be a boolean: ",
	 tr_genint," is invalid"$
      flag := t$
   >>$
   if tr_decouple neq t and tr_decouple neq nil then
   <<
      terpri()$
      write "tr_decouple needs to be a boolean: ",
	 tr_decouple," is invalid"$
      flag := t$
   >>$
   if tr_redlength neq t and tr_redlength neq nil then
   <<
      terpri()$
      write "tr_redlength needs to be a boolean: ",
	 tr_redlength," is invalid"$
      flag := t$
   >>$
   if tr_orderings neq t and tr_orderings neq nil then
   <<
      terpri()$
      write "tr_orderings needs to be a boolean: ",
	 tr_orderings," is invalid"$
      flag := t$
   >>$
   if homogen_ neq t and homogen_ neq nil then
   <<
      terpri()$
      write "homogen_ needs to be a boolean: ",
	 homogen_," is invalid"$
      flag := t$
   >>$
   if solvealg_ neq t and solvealg_ neq nil then
   <<
      terpri()$
      write "solvealg_ needs to be a boolean: ",
	 solvealg_," is invalid"$
      flag := t$
   >>$
   if print_more neq t and print_more neq nil then
   <<
      terpri()$
      write "print_more needs to be a boolean: ",
	 print_more," is invalid"$
      flag := t$
   >>$
   if print_all neq t and print_all neq nil then
   <<
      terpri()$
      write "print_all needs to be a boolean: ",
	 print_all," is invalid"$
      flag := t$
   >>$
   if logoprint_ neq t and logoprint_ neq nil then
   <<
      terpri()$
      write "logoprint_ needs to be a boolean: ",
	 logoprint_," is invalid"$
      flag := t$
   >>$
   if poly_only neq t and poly_only neq nil then
   <<
      terpri()$
      write "poly_only needs to be a boolean: ",
	 poly_only," is invalid"$
      flag := t$
   >>$
   if time_ neq t and time_ neq nil then
   <<
      terpri()$
      write "time_ needs to be a boolean: ",
	 time_," is invalid"$
      flag := t$
   >>$
   if (not null print_) and (not fixp print_) then
   <<
      terpri()$
      write "print_ needs to be an integer: ",
	 print_," is invalid"$
      flag := t$
   >>$
   if not fixp dec_hist then
   <<
      terpri()$
      write "dec_hist needs to be an integer: ",
	 dec_hist," is invalid"$
      flag := t$
   >>$
   if not fixp maxalgsys_ then
   <<
      terpri()$
      write "maxalgsys_ needs to be an integer: ",
	 maxalgsys_," is invalid"$
      flag := t$
   >>$
   if adjust_fnc neq t and adjust_fnc neq nil then
   <<
      terpri()$
      write "adjust_fnc needs to be a boolean: ",
	 adjust_fnc," is invalid"$
      flag := t$
   >>$
   if not vectorp orderings_ and orderings_ neq nil then
   <<
      terpri()$
      write "orderings_ needs to be a vector: ",
	 orderings_," is invalid"$
      flag := t$
   >>$
   if simple_orderings neq t and simple_orderings neq nil then
   <<
      terpri()$
      write "simple_orderings needs to be a boolean: ",
	 simple_orderings," is invalid"$
      flag := t$
   >>$
   if lex_ neq t and lex_ neq nil then
   <<
      terpri()$
      write "lex_ needs to be a boolean: ",
	 lex_," is invalid"$
      flag := t$
   >>$
   if collect_sol neq t and collect_sol neq nil then
   <<
      terpri()$
      write "lex_ needs to be a boolean: ",
	 lex_," is invalid"$
      flag := t$
   >>$
   if flag then
      return nil
   else
      return t$
end$

endmodule$

end$
