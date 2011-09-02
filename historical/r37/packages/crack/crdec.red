%********************************************************************
module decoupling$
%********************************************************************
%  Routines for decoupling de's
%  Author: Andreas Brand 1995, updates and extensions by Thomas Wolf
%  Comments on some routines by Arrigo.
%
%  $Id: crdec.red,v 1.10 1998/06/25 18:19:36 tw Exp tw $
%

symbolic procedure which_deriv(p,q)$
%  yields a list of variables and orders 
%  such that one gets at least q by differentiating p w.r.t. the vars 
%  p,q: lists of variables and orders
begin scalar l,n,a$
while q do
   if (a:=member(car q,p)) then
      <<q:=cdr q$
      if q and numberp(car q) then
      	 <<n:= car q$
         q:=cdr q>>
      else n:=1$
      n:=n-(if pairp cdr a and numberp cadr a then cadr a else 1)$
      if n>0 then
      	 <<l:=cons(car a,l)$
         if n>1 then l:=cons(n,l)>> >>
   else 
      <<l:=cons(car q,l)$
      q:=cdr q$
      if q and numberp(car q) then 
	 <<l:=cons(car q,l)$
	 q:=cdr q>> >>$
return append(reverse l,q)$
end$

symbolic procedure dec_ld_info(p,q,simpp,simpq,f,vl,rl)$
%  gets leading derivatives of f in p and q wrt. vars order vl
%  and the lists of variables and orders for differentiation
begin scalar s,l,l1,l2,vl1,vl2,d,ld1,ld2,wd1,wd2$
 %
 % if (p has more variables than q) or 
 %    (f is not leading function of p)
 % => simpp = t => p must be simplified with (deriv.s of) q 
 % if (q has more variables than p) or
 %    (f is not leading function of q)
 % => simpq = t => q must be simplified with (deriv.s of) p 
 %
 % vl1 holds the list of _ordered_ variables of p
 % vl2 holds the list of _ordered_ variables of q
 %
 % list all powers of derivatives of f in p as l1 and in q as l2
 %

 if simpp and simpq then return nil$

 vl1:=intersection(vl,get(p,'vars))$
 vl2:=intersection(vl,get(q,'vars))$

 % drop the powers from l1
 for each a in get(p,'derivs) do
  if caar a=f then l1:=cons(a,l1)$
 l1:=sort_derivs(reverse l1,list f,vl1)$
 %
 % l1 is a list of _all_ derivatives of f in p _sorted_ stored as a
 % dotted pair, e.g. ((f x 2 y) . 5) would be f_{xxy}^5, or more
 % generally ((f_1 . power) (f_2 . power) ... )
 %
 %terpri()$write "l10=",l1$ 
 l:=nil$
 for each a in l1 do
  if not member(cdar a,l) then l:=cons(cdar a,l)$
 % 
 % cdar a is the function in the pair so we are making sure that our
 % list l1 has no repetitions
 %
 l1:=reverse l$ % e.g. l1 = ((x 2 y) (x y 2) ...)
 %terpri()$write "l11=",l1$ 

 %
 % The above now applies but with q and l2 instead of p and l1
 %
 % drop the powers from l2
 for each a in get(q,'derivs) do
  if caar a=f then l2:=cons(a,l2)$
 l2:=sort_derivs(reverse l2,list f,vl2)$
 %terpri()$write "l20=",l2$ 
 l:=nil$
 for each a in l2 do
  if not member(cdar a,l) then l:=cons(cdar a,l)$
 l2:=reverse l$ % e.g. l2 = ((x 2 y) (x y 2) ...)
 %terpri()$write "l21=",l2$ 

 % At this point we have two lists, l1 and l2 resp. containing the
 % sorted list of all derivatives of the fn f in p and q and we
 % calculate the absolute degree of the highest derivative in l1

 if not simpp then << 
   %p may be differentiated and q be substituted or new equ. added 
   d:=absdeg(car l1)$
   %terpri()$write "d=",d$
   l:=l2$
   while l and (d<=absdeg car l) do
   <<s:=which_deriv(car l1,car l)$
     %terpri()$write "s1=",s$
     %
     % which_deriv(a,b) takes two lists of derivatives and returns how
     % often you need to diff. a in order to get at least the
     % derivatives in b.
     % e.g. which_deriv((x 2 y), (x y 2)) returns y
     %
     if (absdeg s + d)=absdeg car l then 
       %
       % At this point we compare the degree of the highest
       % derivative of l1 + number of diff. in order to get the
       % leading deriv. of l2 (aliased to l)
       %
       <<ld2:=car l$ l:=nil>>
     else l:=cdr l
   >> 
 >>$

 % Now, either l is nil and ld2 = leading deriv. of l2 (i.e. highest
 % deriv. of in q) [case in which leading deriv. in l2 can be obtained
 % by diff. of the leading deriv. in l1] OR ld2 is nil and l contains
 % the rest of the deriv. of l2 except the leading one [in this case
 % we _cannot_ obtain the leading deriv. in l2 by diff. the leading
 % deriv. in l1].

 if (not ld2) and (not simpq) then <<
   %
   % We cannot get to the leading deriv. in l2 by diff. of leading
   % deriv. in l1.
   %
   d:=absdeg(car l2)$
   %
   % We try the opposite way, we try to diff. something in l2 to get
   % into l1.
   %
   l:=l1$
   while l and (d<=absdeg car l) do
   <<s:=which_deriv(car l2,car l)$
     %terpri()$write "s2=",s$ 
     if (absdeg s + d)=absdeg car l then <<ld1:=car l$ l:=nil>>
                                    else l:=cdr l
   >> 
 >>$

 % We now have either ld2 non-nil, i.e. we can get to leading derv. in
 % l2 by differentiation of terms in l1 OR we have ld1 non-nil in
 % which case we have the opposite situation. If neither are non-nil
 % then we have to cross-differentiate to get the ld to match.
 %
 % What we return is
 %
 % ( (s ld(l1)) (nil ld(l2)) )		[ld2 non-nil] or
 % ( (nil ld(l1)) (s ld(l2)) )		[ld1 non-nil] or
 % ( (v ld(l1)) (w ld(l2)) )		[both ld1 _and_ ld2 nil]
 %
 % where v and w are the required diff. to get to ld2 and ld1 resp.
 % and s is the required diff. for the non-nil cases.
 %
 % It is to be interpreted as:
 %
 % Either	"diff. ld(l1) by s to get ld(l2)" or
 %		"diff. ld(l2) by s to get ld(l1)" or
 %		"diff. ld(l1) by wd1 and ld(l2) by wd2 to get the 
 %		ld's to match".
 %

 return
 if ld2 then list(list(s,car l1),list(nil,ld2)) else 
 if ld1 then list(list(nil,ld1),list(s,car l2)) else <<
   wd1:=which_deriv(car l1,car l2)$
   wd2:=which_deriv(car l2,car l1)$
   if (simpq and wd2) or 
      (simpp and wd1) or
      (rl and wd1 and wd2) then nil 
   else list(list(wd1,car l1),
             list(wd2,car l2))
 >>
end$

symbolic procedure dec_info(p,q,f,vl,rl)$
% yields information for a decouple reduction step
% i.e. ((info_1 info_2 deriv_to_eliminate equ_to_be_subst).num_value)
% where num_value is a measure of cost, e.g.
% (((e4 (x 2 y)) (e5 (z)) (df f x 2 y 2 z) nil) . num_value)
% Criteria:   a) the function f must depend on all vars
%             b) the function and all their derivatives must occur
%                polynomially
begin scalar a,b,l,l1,info,m,fp,fq,fpmq,fqmp,s,lenp,lenq$
  %
  % 'length is the property containing the expression length
  %
  lenp:=get(p,'length)$
  lenq:=get(q,'length)$
  if rl and ((lenp*lenq)>max_red_len) then return nil;

  a:=get(p,'vars); b:=get(q,'vars);
  l:=dec_ld_info(p,q,
                 (null get(p,'allvarfcts)) or    % star-equn.
                 (f neq car get(p,'allvarfcts)), % f not lead. fct.
                 (null get(q,'allvarfcts)) or
                 (f neq car get(q,'allvarfcts)),
                 f,vl,rl)$
  if not l then <<
    add_both_dec_with(f,p,q,rl)$
    return nil
  >>$
  %
  % l:= dec_ld_info(p,q,f,vl,rl) returns a list of lists, from which
  % a := caar l sets a to be the differentiations required to get
  % the ld(p) w.r.t. f to match that of ld(q) w.r.t. f,
  % b := caadr l sets b to be the differentiations required to get
  % the ld(q) w.r.t. f to match that of ld(q) w.r.t. f.
  %
  % l1 := cadadr l sets l1 to be the derivative in q which we
  % eliminate, similarly l is the derivative in p which we elim.
  %
  a:=caar l$             % a are the differentiations of p
  b:=caadr l$            % b are the differentiations of q
  l1:=cadadr l$
  l:=cadar l$
  % s is the equation to be substituted
  if a and not b then s:=q                 % p will be diff.
  else if b and not a then s:=p            % q will be diff.
  else if not (a or b) then                % no diff., only reduction
   if car get(p,'fcts) neq f then s:=p else  % no new leading fncts
   if car get(q,'fcts) neq f then s:=q else
   if car get(p,'derivs)=car get(q,'derivs) then
     if lenp<=lenq then s:=q
                   else s:=p                else 
%   if lower_lderiv(p,q,union(get(p,'fcts),get(q,'fcts)),vl) then s:=q
%                                                            else s:=p$
     if abs_dfrel(car get(p,'derivs),car get(q,'derivs),vl) then s:=q
                                                            else s:=p$

  fp:=get(p,'allvarfcts)$ % functions of all vars in p
  fq:=get(q,'allvarfcts)$ % functions of all vars in q

  % If a pde will be replaced by a pde with more fcts of all vars
  % then this pairing will have a lowered priority
  fqmp:=length setdiff(fq,fp);
  fpmq:=length setdiff(fp,fq);
%if nil then
  if tr_decouple then << terpri()$
    write"p=",p," q=",q," s=",s," lfp=",length fp,
         " lfq=",length fq," lfu=",length union(fp,fq),
         " fqmp=",fqmp," fpmq=",fpmq
  >>$
  m:=(1.5^absdeg(a)*lenp+1.5^absdeg(b)*lenq)*
     (length union(fp,fq))**3$ 
%if nil then
  if tr_decouple then write" m2=",m;
  if s then << 
    % the equation s will be replaced by the new one
    if fcteval(s,nil) then m:=m*10**7; 
    if (s=q) and (lenp>lenq) then m:=(m*lenp)/lenq else
    if (s=p) and (lenq>lenp) then m:=(m*lenq)/lenp;
    if (s=p) and (fqmp>0) then m:=m*10**(2*fqmp) else
    if (s=q) and (fpmq>0) then m:=m*10**(2*fpmq)
  >>   else 
  % Enlarge m because extra equation is generated (temp. idea)
  m:=m*10$
  % Non-linearity in largest derivative not taken care of.
%if nil then
  if tr_decouple then write" m3=",m;
  info:=cons(list(list(p,a),list(q,b),
                  reval cons('DF,cons(f,append(l,a))),s),m)$
  return info$
end$

symbolic procedure dec_put_info(l,rl)$
% l has form ((e4 (x 2 y)) (e5 (z)) (df f x 2 y 2 z) nil)
% puts informations for decouple reduction step
% result: ((df f x 2 y 2 z) e4 e5 nil)
if l then
begin scalar f$
  put(caar l,'dec_info,cadar l)$     % saves (x 2 y) for e4
  put(caadr l,'dec_info,cadadr l)$   % saves (z)     for e5
  if (cadar l) and (cadadr l) then << % if both eq. are diff.
    f:=caddr l;
    if pairp f then f:=cadr f;
    add_both_dec_with(f,caar l,caadr l,rl)$
  >>$
  return list(caddr l,caar l,caadr l,cadddr l)$
end$

% symbolic procedure dec_put_info(f,l)$
% % put informations for decouple reduction step
% % result: (deriv_to_eliminate pde_1 pde_2)
% if l then
% begin scalar a,b$
%    put(caar l,'dec_info,cadar l)$
%    a:=get(caar l,'dec_with)$
%    b:=assoc(f,a)$
%    a:=delete(b,a)$
%    if b then b:=cons(f,cons(caadr l,cdr b))
%         else b:=list(f,caadr l)$
%    put(caar l,'dec_with,cons(b,a))$
%    put(caadr l,'dec_info,cadadr l)$
%    a:=get(caadr l,'dec_with)$
%    b:=assoc(f,a)$
%    a:=delete(b,a)$
%    if b then b:=cons(f,cons(caar l,cdr b))
%         else b:=list(f,caar l)$
%    put(caadr l,'dec_with,cons(b,a))$
% return list(caddr l,caar l,caadr l)$
% end$

%% symbolic procedure dec_info_leq(p,q)$
%% %  relation "<=" for decouple informations
%% if p and q then 
%%    if not (cadar car p and cadadr car p) then 
%%       if not (cadar car q and cadadr car q) then (cdr p<=cdr q)
%%                                     else p
%%    else if cadar car q and cadadr car q then (cdr p<=cdr q)
%%                                 else nil
%% else p$ 

symbolic procedure dec_info_leq(p,q)$
%  relation "<=" for decouple informations
if p and q then (cdr p<=cdr q)
else if p then p
else q$

symbolic procedure dec_and_fct_select(pdes,vl,rl)$
% select 2 pdes for decoupling
% if rl then one pde must be simplified with the help of 
% another one and reduce its length
begin scalar min,f,l,l1,l2,done_pdes,car_pdes$
  while pdes do <<
    car_pdes:=car pdes;
    if flagp(car_pdes,'to_decoup) and 
       get  (car_pdes,'allvarfcts) then
    <<f:=car get(car_pdes,'allvarfcts)$
      l:=assoc(f,get(car_pdes,'dec_with))$
      if rl then l:=append(l,assoc(f,get(car_pdes,'dec_with_rl)))$
      %--- unchecked pairings 
      for each p in cdr pdes do
      if flagp(p,'to_decoup) and 
         member(f,get(p,'rational)) and
         not member(p,l) and
         not member(car_pdes,assoc(f,get(p,'dec_with))) 
      then <<l1:=dec_info(car_pdes,p,f,vl,rl)$
             if l1 then l2:=cons(l1,l2)
           >>$
      %--- checked pairings but where f is not the
      %--- leading function in car done_pdes which has not
      %--- been checked when this pairing was tested before
      for each p in done_pdes do
      if flagp(p,'to_decoup) and 
         member(f,get(p,'rational)) and
         not member(p,l) and
         not member(car_pdes,assoc(f,get(p,'dec_with))) and
         ((null get(p,'allvarfcts)) or
          (f neq car get(p,'allvarfcts)))  
      then <<l1:=dec_info(car_pdes,p,f,vl,rl)$
             if l1 then l2:=cons(l1,l2)
           >>$
    >>$
    done_pdes:=cons(car_pdes,done_pdes)$
    pdes:=cdr pdes
  >>$

  %--- l2 is the list of possible pairings of 2 equations
  %--- pick one of these pairings
  l1:=nil;  
  %--- l1 is the list of equations which still can be reduced
  %--- and where f=car get(equ,'allvarfcts), i.e. equations
  %--- which must not be used for generating new equations
  %
  %--- each l in l2 has the form
  %--- (((e4 (x 2 y)) (e5 (z)) (df f x 2 y 2 z) nil) . num_value)
  for each l in l2 do <<
    f:=caddar l;
    if pairp f then f:=cadr f;
    if (caaar l = cadddr car l) and  % if caaar  l will be subst.
       get(caaar l,'allvarfcts) and
       (f=car get(caaar l,'allvarfcts)) 
    then l1:=union(list(caaar l),l1);
    if (caadar l = cadddr car l) and % if caadar l will be subst.
       get(caadar l,'allvarfcts) and
       (f=car get(caadar l,'allvarfcts))
    then l1:=union(list(caadar l),l1);
  >>;
  %--- Test that no new equation will be generated from an
  %--- equation from which the leading derivative can still be
  %--- reduced
  for each l in l2 do
  if ((cadaar l = nil)                              or 
      (cadr cadar l = nil)                          or
      (freeof(l1,caaar  l) and freeof(l1,caadar l))    ) and
     dec_info_leq(l,min) 
  then min:=l;
  if min then return dec_put_info(car min,rl)$
end$

symbolic procedure elimin(p,q,x)$
begin
 scalar dgs,s,flg,quoti,lts,
        ltp,dgp,fcpp,fcqp,fcsp,
        ltq,dgq,fcpq,fcqq,fcsq$

 ltp:=reval{'LTERM,p,x};
 ltq:=reval{'LTERM,q,x};
 dgp:=reval{'DEG,ltp,x};
 dgq:=reval{'DEG,ltq,x};

 if dgp > dgq then << flg:=t; dgs:=dgq >>
              else dgs:=dgp$

 fcpp:=1; fcpq:=0;
 fcqq:=1; fcqp:=0;

 while dgs neq 0 do <<
  quoti:=reval{'QUOTIENT,ltp,ltq};
  s:=reval{'PLUS,{'TIMES,p,{'DEN,quoti}},
                 {'MINUS,{'TIMES,q,{'NUM,quoti}}}}$
  lts:=reval{'LTERM,s,x}$
  dgs:=reval{'DEG,lts,x}$
  fcsp:=reval{'PLUS,{'TIMES,fcpp,{'DEN,quoti}},
                    {'MINUS,{'TIMES,fcqp,{'NUM,quoti}}}}$
  fcsq:=reval{'PLUS,{'TIMES,fcpq,{'DEN,quoti}},
                    {'MINUS,{'TIMES,fcqq,{'NUM,quoti}}}}$

  if flg=t then <<
   p:=s;
   ltp:=lts;
   dgp:=dgs;
   fcpp:=fcsp;
   fcpq:=fcsq;
   if dgq>dgp then flg:=nil
  >>       else <<
   q:=s;
   ltq:=lts;
   dgq:=dgs;
   fcqp:=fcsp;
   fcqq:=fcsq;
   if dgp>dgq then flg:=t
  >>$
 >>;
 quoti:=reval{'GCD,fcsp,fcsq};
 return {reval{'QUOTIENT,s   ,quoti},
         reval{'QUOTIENT,fcsp,quoti},
         reval{'QUOTIENT,fcsq,quoti} }
end$

symbolic procedure dec_reduction(l,ftem,vl,rl)$
% do a reduction step or a cross differentiation either
% l has the form  ((df f x 2 y 2 z) e4 e5 nil)
% if rl then one pde must be simplified with the help of 
% another one and reduce its length
begin scalar p,q,ld,a,s,ip,iq,f,dwsa,dwla,dwlb,el,h$
  ld:=car l$    % ld=deriv. to be elim. after differentiation
  l:=cdr l$     % l=list of equations
  f:=if pairp ld then cadr ld
                 else ld$
  p:=get(car l,'val)$
  q:=get(cadr l,'val)$
  ip:=get(car l,'dec_info)$
  iq:=get(cadr l,'dec_info)$
  s:=caddr l;               % s is the equation to be deleted
  l:=list(car l,cadr l);
  if print_ and ((null rl and tr_decouple) or 
                 (     rl and tr_redlength)  ) then
  <<terpri()$write "  first pde ",car l,": "$
    typeeq car l$ 
    if ip then write "is diff. wrt. ",ip,","
          else write "is not differentiated,"$
    write "  second pde ",cadr l,": "$
    typeeq cadr l$
    if iq then write "is diff. wrt. ",iq," "
          else write "is not differentiated, "$
    write"to eliminate ",mathprint ld$
  >>$
  if iq then q:=simplifypde(reval cons('DF,cons(q,iq)),ftem,nil)$
  if ip then p:=simplifypde(reval cons('DF,cons(p,ip)),ftem,nil)$
%  h:=reval !*q2a simpresultant list(p,q,ld)$
  h:=car elimin(p,q,ld)$
  if h and not zerop h 
  then a:=mkeq(h,ftem,vl,allflags_,t,list(0))$
  % Orderings ! Problem: we need to understand the internals of this
  % functions to a better degree.

  if a and rl then <<
    if get(s,'length)*length_inc<get(a,'length) then <<
      add_both_dec_with(f,car l,cadr l,t);
      if tr_redlength and print_ then 
      <<%terpri()$
        write "  The resulting pde "$typeeq a$
        write"  would have had ",get(a,'length),
        " terms compared to ",get(s,'length)," terms">>;
      setprop(a,nil)$
      nequ_:=sub1 nequ_$
      return nil
    >>
  >>$

  if a and member(get(a,'val),dec_hist_list) then <<
    setprop(a,nil)$
    nequ_:=sub1 nequ_$
    add_both_dec_with(f,car l,cadr l,rl);
    if print_ and ((rl and tr_redlength) or (null rl and tr_decouple)) 
    then <<terpri()$write "the resulting pde would lead to a cycle"$>> >>
  else <<
    if print_ then <<
%      terpri()$write if rl then "Length-reduction" else "Decoupling",
%                     " step with "$
%      fctprint l$write" : "$
%      terpri()$write if rl then "Length-reduction:" else "Decoupling:"$
      write" Eliminate "$
      mathprint ld$
      write"from ",if ip then cons('DF,cons(car l,ip))
                         else car  l, " and ",
                   if iq then cons('DF,cons(cadr l,iq))
                         else cadr l, ". "$
      if a then <<
        if s then << 
          write s,": "$
          typeeq s; %terpri()$
          write"is replaced by ",a,": "
        >>   else write a," is added: "$
        typeeq a
      >>     else if s then write s," is deleted"
    >>$
    if s then <<      % reduction 
      l:=delete(s,l)$
      if not (ip or iq) then << 
        % The equations wrt which s has already been decoupled
        % are to be listed under dec_with wrt to the equation
        % of both that is kept which is car l
        % purpose: These decouplings should not be done again
        % with car l as this may result in a cycle
        dwsa:=get(    s,'dec_with)$  
        dwla:=get(car l,'dec_with)$  
        for each el in dwsa do <<           
          dwlb:=assoc(car el,dwla)$
          dwla:=delete(dwlb,dwla)$
          if dwlb then dwlb:=cons(car el,union(cdr el,cdr dwlb))
                  else dwlb:=el$
          dwla:=cons(dwlb,dwla)
        >>$ 
        put(car l,'dec_with,dwla)$
      >>$
      % If other than the leading derivatives are reduced then
      % the new equ. a must inherit 'dec_with from equ. s
      if a and get(a,'derivs) and 
         (car get(a,'derivs) = car get(s,'derivs)) then <<
        dwsa:=get(s,'dec_with)$
        put(a,'dec_with,dwsa)
      >>$
      if dec_hist>0 then <<
        if length dec_hist_list>dec_hist then
           dec_hist_list:=cdr dec_hist_list$
        dec_hist_list:=reverse cons(get(s,'val),reverse dec_hist_list)$
      >>$
      setprop(s,nil)>>$
    if a then l:=append(l,list a)$
  >>$
  return l$
end$

symbolic procedure dec_fct_check(a,l)$
% checks, if a function occurs in only one pde
begin scalar ft$
  ft:=get(a,'fcts)$
  while ft and l do
    <<if flagp(car l,'to_decoup) then
        ft:=setdiff(ft,get(car l,'fcts))$
    l:=cdr l>>$
  if ft then remflag1(a,'to_decoup)$
return ft$
end$

symbolic procedure dec_one_step(l,ftem,vl,rl)$
% do one decouple step for f; i.e. select 2 pdes, differentiate them
% and add the new pde or replace an original one
% if rl then one pde must be simplified with the help of 
% another one and reduce its length
begin scalar l1,l2$
  if not expert_mode then l1:=l
                     else <<
    l1:=selectpdes(l,2)$
    drop_dec_with(car  l1,cadr l1,rl)$
    drop_dec_with(cadr l1,car  l1,rl)$
  >>$
again:
  l1:=dec_and_fct_select(l1,vl,rl)$
  if not l1 then l:=nil
  else 
    if (l2:=dec_reduction(l1,ftem,vl,rl)) then
      <<for each a in cdr l1 do l:=delete(a,l)$
        for each a in l2 do l:=eqinsert(a,l)$
        for each a in l2 do dec_fct_check(a,l)$
      >>
    else if rl then <<l1:=l;goto again>>
               else l:=nil$
  return l$
end$

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  procedures for decoupling of similar pde                        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%symbolic procedure rel_length_diff(p,q)$
%% print length difference in pro cent
%(abs(get(p,'length)-get(q,'length))*100)/
%   (get(p,'length)+get(q,'length))$

%symbolic procedure nearly_same(p,q)$
%begin scalar lp,lq$
% lp:=get(p,'fcts)$
% lq:=get(q,'fcts)$ 
% if null setdiff(get(p,'allvarfcts),get(q,'allvarfcts)) and
%    null setdiff(get(q,'allvarfcts),get(p,'allvarfcts)) and
%    ((length setdiff(lp,lq)+length setdiff(lq,lp))*100<
%    (length lp+length lq)*same_fcts) then
%    <<lp:=get(p,'derivs)$
%      lq:=get(q,'derivs)$
%      if (length setdiff(lp,lq)+length setdiff(lq,lp))*100<
%         (length lp+length lq)*same_derivs then return t>>$
%end$
       
%symbolic procedure get_same_pdes(pdes)$
%begin scalar l,n,res$
% while pdes do
%  <<l:=cdr pdes$
%  while l do
%    if (n:=rel_length_diff(car pdes,car l))<=same_length then
%       if nearly_same(car pdes,car l) then
%          <<res:=list(car pdes,car l)$
%            l:=nil>>
%       else l:=cdr l
%    else if n>5*same_length then l:=nil
%                            else l:=cdr l$
%  if res then pdes:=nil
%         else pdes:=cdr pdes
%  >>$
% return res$
%end$ 

endmodule$
end$
