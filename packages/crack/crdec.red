%********************************************************************
module decoupling$
%********************************************************************
%  Routines for decoupling de's
%  Author: Thomas Wolf, Andreas Brand until 1995, 

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

symbolic fluid '(form_chnpair)$  % channel pair for piping into FORM

symbolic procedure which_deriv(p,q)$    
%  yields a list of variables and orders 
%  such that one gets at least q by differentiating p w.r.t. the vars 
%  p,q: lists of variables and orders
begin scalar l,n,a$
 while q do
 if (a:=member(car q,p)) then <<
  q:=cdr q$
  if q and numberp(car q) then <<
   n:=car q$
   q:=cdr q
  >>                      else n:=1$
  n:=n-(if pairp cdr a and numberp cadr a then cadr a else 1)$
  if n>0 then <<
   l:=cons(car a,l)$
   if n>1 then l:=cons(n,l)
  >> 
 >>                      else <<
  l:=cons(car q,l)$
  q:=cdr q$
  if q and numberp(car q) then <<
   l:=cons(car q,l)$
   q:=cdr q
  >> 
 >>$
 return append(reverse l,q)$
end$

symbolic procedure dec_ld_info(p,q,simpp,simpq,f,vl,rl)$  
%  gets leading derivatives of f in p and q wrt. vars order vl
%  and the lists of variables and orders for differentiation
begin scalar s,l,l1,l1d,l2,l2d,vl1,vl2,d1,d2,ld1,ld2,wd1,wd2,
             caar_ld,found$
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

 % collect all powers of all derivatives of f
 %
 for each a in get(p,'derivs) do if caar a=f then l1:=cons(a,l1)$
 l1:=sort_derivs(reverse l1,list f,vl1)$
 %
 % l1 is a list of _all_ derivatives of f in p _sorted_ stored as a
 % dotted pair, e.g. ((f x 2 y) . 5) would be f_{xxy}^5, or more
 % generally ((f_1 . power) (f_2 . power) ... )
 %
 %terpri()$write "l10=",l1$ 
 %
 % keep only highest power of each derivative in l1 
 l:=nil$
 for each a in l1 do if not member(cdar a,l) then <<
  l:=cons(cdar a,l)$
  l1d:=cons(list(cdar a,absodeg(cdar a),cdr a),l1d)
 >>$
 % 
 % cdar a is the list of derivatives so we are making sure that our
 % list l1 has no repetitions
 %
 l1:=reverse l$   % e.g. l1  = ( (x 2 y)       (x y 2)      ...)
 l1d:=reverse l1d$ % e.g. l1d = (((x 2 y),3,1) ((x y 2),3,2) ...)

 %
 % The above now applies but with q and l2 instead of p and l1
 %
 % collect all powers of all derivatives of f
 %
 for each a in get(q,'derivs) do if caar a=f then l2:=cons(a,l2)$
 l2:=sort_derivs(reverse l2,list f,vl2)$
 %terpri()$write "l20=",l2$ 
 % keep only highest power of each derivative in l2 
 l:=nil$
 for each a in l2 do if not member(cdar a,l) then <<
  l:=cons(cdar a,l)$
  l2d:=cons(list(cdar a,absodeg(cdar a),cdr a),l2d)
 >>$
 l2:=reverse l$   % e.g. l2 =  ( (x 2 y)       (x y 2)      ...)
 l2d:=reverse l2d$ % e.g. l2d = (((x 2 y),3,1) ((x y 2),3,2) ...)

 % At this point we have two lists, l1d and l2d resp. containing the
 % sorted list of all derivatives of the function f in p and q 
 % together with their highest power 

 % At first we note the leading derivative in l1d with its power
 % and check whether there is a derivative in l2d which has in no variable
 % a lower derivative or and either has a higher derivative in at least
 % one variable, or is not of lower degree.

 if not simpp then << 
   %p may be differentiated and q be substituted or new equ. added 
   caar_ld:=caar l1d$
   d1:=cadar  l1d$
   d2:=caddar l1d$
   l:=l2d$
   while l and ((d1<cadar l) or ((d1=cadar l) and (d2<=caddar l))) do
   <<s:=which_deriv(caar_ld,caar l)$
     %
     % which_deriv(a,b) takes two lists of derivatives and returns how
     % often you need to diff. a in order to get at least the
     % derivatives in b.
     % e.g. which_deriv((x 2 y), (x y 2)) returns y
     %
     if (absodeg s + d1)=cadar l then <<ld2:=caar l$ found:=t$ l:=nil>>
     % At this point we compare the degree of the highest
     % derivative of l1 + number of diff. in order to get the
     % leading deriv. of l2 (aliased to l)
                                 else l:=cdr l
   >> 
 >>$

 if simpq and null found then return nil;

 % Now, either l is nil and ld2 = leading deriv. of l2 (i.e. highest
 % deriv. of f in q) [this is the case in which leading deriv. in l2 
 % can be obtained by diff. of the leading deriv. in l1] OR 
 % ld2 is nil and l contains the rest of the deriv. of l2 except the 
 % leading one [in this case we _cannot_ obtain the leading deriv. in 
 % l2 by diff. the leading deriv. in l1].

 if (not ld2) and (not simpq) then <<
   %
   % We cannot get to the leading deriv. in l2 by diff. of leading
   % deriv. in l1.
   % We now try the opposite way, we try to diff. something in l2 to
   % get into l1.
   %
   caar_ld:=caar l2d$
   d1:=cadar  l2d$
   d2:=caddar l2d$
   l:=l1d$
   found:=nil$
   while l and ((d1<cadar l) or ((d1=cadar l) and (d2<=caddar l))) do 
   <<s:=which_deriv(caar_ld,caar l)$
     if (absodeg s + d1)=cadar l then <<ld1:=caar l$ found:=t$ l:=nil>>
                                 else l:=cdr l
   >> 
 >>$

 if simpp and null found then return nil;

 % We now have either ld2 non-nil, i.e. we can get to leading derv. in
 % l2 by differentiation of terms in l1 OR we have ld1 non-nil in
 % which case we have the opposite situation. If neither are non-nil
 % then we have to cross-differentiate to get the ld to match.
 %
 % What we return is
 %
 % ( (s ld(l1)) (nil ld(l2)) )                [ld2 non-nil] or
 % ( (nil ld(l1)) (s ld(l2)) )                [ld1 non-nil] or
 % ( (v ld(l1)) (w ld(l2)) )                  [both ld1 _and_ ld2 nil]
 %
 % where v and w are the required diff. to get to ld2 and ld1 resp.
 % and s is the required diff. for the non-nil cases.
 %
 % It is to be interpreted as:
 %
 % Either        "diff. ld(l1) by s to get ld(l2)" or
 %                "diff. ld(l2) by s to get ld(l1)" or
 %                "diff. ld(l1) by wd1 and ld(l2) by wd2 to get the 
 %                ld's to match".
 %

 return
 if ld2 then cons(cons(s,caar l1d),cons(nil,ld2)) else 
 if ld1 then cons(cons(nil,ld1),cons(s,caar l2d)) else <<
   wd1:=which_deriv(caar l1d,caar l2d)$
   wd2:=which_deriv(caar l2d,caar l1d)$
   if (simpq and wd2) or 
      (simpp and wd1) or
      (rl and wd1 and wd2) then nil 
   else cons(cons(wd1,caar l1d),
             cons(wd2,caar l2d))
 >>
end$

symbolic procedure diffeq(f,sd,r)$      
% input of how often equation r is to be differentiated
% sd is the resulting derivative that is to be substituted
% with another equation, eg   sd=(x,2,y)
begin scalar rdif,rd,contradic,a,ad,b,bd,resu,must_be_subst$
  terpri()$
  write"How often is equation ",r," to be differentiated?"$
  terpri()$
  write"(just `;' for no differentiation or, for example, `x,y,2;' ): "$
  rdif:=termlistread()$
  rd:=get(r,'derivs)$
  while rd and null contradic do <<
    a:=caar rd;  % only the differentiations, not the degree
    rd:=cdr rd$
    if f=car a then <<
      ad:=cdr a$
      if cdr a then a:=cons('DF,a) 
               else a:=car a; % a is now the function/full derivative
      if null rdif then b:=a else 
                        b:=reval cons('DF,cons(a,rdif));
      if pairp b then bd:=cddr b
                 else bd:=nil$
      % There must not result a derivative from differentiating
      % equation r which is a derivative of sd
      if zerop b then <<
        write "The function ",f," differentiated that way gives zero."$
        contradic:=t$
      >>         else
      if (null which_deriv(bd,sd)) and 
               which_deriv(sd,bd)  then 
      if null rdif then must_be_subst:=b
                   else <<
        contradic:=t$ % sd,r,rdif are not compatible
        terpri()$
        write"This differentiation of equation ",r,
             " will generate a derivative ",b$
        terpri()$
        write" which is a derivative of the derivative to be eliminated."$
        terpri()$
      >>                      else 
      if bd = sd then resu:={r,rdif,ad}
    >>
  >>$
  return if contradic or null resu then nil
                                   else resu . must_be_subst
end$

symbolic procedure read_sub_diff(p,q)$   
begin scalar s,l0,l,m0,m1,f,sd,info_p,info_q,contradic,let_conflict$
  change_prompt_to ""$ 
  terpri()$
  write"What is the derivative to be eliminated? "$
  write"(e.g.  df(f,x,y,2); or f; ) "$terpri()$
  l0:=termxread()$
  l:=reval l0$
  % tests whether the input l is ok
  if null l then return nil else
  if not pairp l then if l0 neq l then let_conflict:=t else
                 else % pairp l
  if car l neq 'DF then if car l0 neq 'DF then <<
    write"Not a derivative!"$ terpri()$
    return nil
  >>                                      else let_conflict:=t 
                   else
  if cadr l neq cadr l0 then let_conflict:=t
                        else <<
   m0:=cddr l0; m1:=cddr l;
   while m1 and null let_conflict do
   if fixp car m1 then m1:=cdr m1 else <<
    if no_of_v(car m1,m1) neq no_of_v(car m1,m0) then let_conflict:=t;
    m1:=cdr m1
   >>
  >>$
  if let_conflict then <<
   write "Due to a LET-rule in operation this elimination ",
         "is not possible."$terpri()$
   write "To delete a LET-rule use 'cr'."$terpri()$
   return nil
  >>$ 
  if pairp l then <<f:=cadr l;sd:=cddr l>> 
             else <<f:=l;sd:=nil>>$
  info_p:=diffeq(f,sd,p)$
  if info_p then info_q:=diffeq(f,sd,q)$

  restore_interactive_prompt()$
  return 
  if info_p and info_q then <<
    if null cadar info_p and cadar info_q then s:=p else
    if null cadar info_q and cadar info_p then s:=q else
    if cadar info_p and cadar info_q then s:=nil else <<
      terpri()$
      write"Which equation is to be substituted (if that is possible)? Input ",
           p," or ",q,": "$
      repeat 
      s:=reval termread()
      until (s=p) or (s=q)
    >>$
    if s=p and cdr info_q then <<
      contradic:=t$
      terpri()$
      write"The derivative ",cdr info_q," would enter ",p$
      terpri()$
      write" which is a derivative of the derivative to be substituted."$
    >>$
    if s=q and cdr info_p then <<
      contradic:=t;
      terpri()$
      write"The derivative ",cdr info_p," would enter ",q$
      terpri()$
      write" which is a derivative of the derivative to be substituted."$
    >>$
    if contradic then nil
                 else {car info_p,car info_q,l,s,nil} . 1
    % returns the same kind of result as dec_info
  >>                   else nil
end$

symbolic procedure dec_info(p,q,f,vl,rl,ordering)$ 
% yields information for a decouple reduction step
% i.e. ((info_1 
%        info_2 
%        deriv_to_eliminate 
%        equ_to_be_subst 
%        whether_one_equation_must_be_substituted % important for elim. techn.
%       ).num_value)
% where num_value is a measure of cost, e.g.
% result has form (((e4 (x 2 y) (y z)) 
%                   (e5 (z) (x 2 y 2)) (df f x 2 y 2 z) nil nil) . num_value)
% Criteria:   a) the function f must depend on all vars
%             b) the function and all their derivatives must occur
%                polynomially
begin scalar a,b,l,l1,info,m,n,fp,fq,fpmq,fqmp,s,lenp,lenq,dp,dq,
             simpp,simpq,let_conflict$
  %
  % 'length is the property containing the expression length
  %
  if expert_mode then return read_sub_diff(p,q)$
  lenp:=get(p,'length)$
  lenq:=get(q,'length)$
  if rl and ((lenp*lenq)>max_red_len) then return nil;

  a:=get(p,'vars); b:=get(q,'vars);
  simpp:=(null get(p,'allvarfcts)) or (f neq caaar get(p,'derivs))$
  simpq:=(null get(q,'allvarfcts)) or (f neq caaar get(q,'derivs))$
         % star-equn. or f is not leading function
  l:=dec_ld_info(p,q,simpp,simpq,f,vl,rl)$
  if not l then <<
    add_both_dec_with(ordering,p,q,rl)$
    return nil
  >>$
  %
  % l:= dec_ld_info(p,q,f,vl,rl) returns a list of lists, from which
  % a:= caar l sets a to be the differentiations required to get
  % the ld(p) w.r.t. f to match that of ld(q) w.r.t. f,
  % b:= caadr l sets b to be the differentiations required to get
  % the ld(q) w.r.t. f to match that of ld(q) w.r.t. f.
  %
  % l1:= cadadr l sets l1 to be the derivative in q which we
  % eliminate, similarly l is the derivative in p which we elim.
  %
  a:=caar l$             % a are the differentiations of p
  b:=cadr l$             % b are the differentiations of q
  if struc_eqn and 
     ((a and b and (not freeof(algebraic struc_done,f))) or
      % no integrab. cond.s for functions in struc_done
      ((get(p,'no_derivs)>0) and (get(q,'no_derivs)=0))  or
      ((get(p,'no_derivs)=0) and (get(q,'no_derivs)>0))
      % not using algebr. conditions to simplify diff. cond.
     ) then return nil;
  l1:=cddr l$
  l:=cdar l$
  % Test whether there is a let-rule in operation which changes the
  % target derivative
  if (null a) and (null l) then 
  if f neq reval f then let_conflict:=t
                   else    else <<
   m:=reval cons('DF,cons(f,append(l,a)));
   if (not pairp m) or 
      (car m neq 'DF) or 
      (cadr m neq f) then let_conflict:=t
                     else <<
    m:=cddr m$
    while m and null let_conflict do
    if fixp car m then m:=cdr m else <<
     if (no_of_v(car m,a)+no_of_v(car m,l)) neq 
         no_of_v(car m,m)                       then let_conflict:=t;
     m:=cdr m
    >>
   >>
  >>$
  if let_conflict then <<
   if print_ then <<
    write "Due to a let-rule in operation equations ",
          p,",",q," will not be paired."$terpri()$
   >>$
   add_both_dec_with(ordering,p,q,rl)$
   return nil
  >>$

  % s is the equation to be substituted
  if a and not b then s:=q                 % p will be diff.
  else if b and not a then s:=p            % q will be diff.
  else if not (a or b) then                % no diff., only reduction
  if struc_eqn and l and l1 then <<  
    % 2 structural equations, both with one or more derivatives 
    % --> equation with more derivatives is substituted
    % The case below would work, only this may need fewer substitutions
    m:=get(p,'no_derivs)$
    n:=get(q,'no_derivs)$
    if m>n then s:=p else
    if m<n then s:=q else
%    if cons(f,l ) neq caar get(q,'derivs) then s:=q else
%    if cons(f,l1) neq caar get(p,'derivs) then s:=p else
    if get(p,'length)>get(q,'length) then s:=p
                                     else s:=q
  >>           else <<
    % determination of s:
    dp:=get(p,'derivs)$
    dq:=get(q,'derivs)$
    repeat <<
      s:=total_less_dfrel(car dp,car dq,ftem_,vl)$
      dp:=cdr dp$
      dq:=cdr dq
    >> until (s neq 0) or (null dp) or (null dq)$
    if (s=t) % or ((null dp) and dq) % this had to be commented out
    then s:=q
    else s:=p
  >>$

  fp:=get(p,'allvarfcts)$ % functions of all vars in p
  fq:=get(q,'allvarfcts)$ % functions of all vars in q

  % If a pde will be replaced by a pde with more fcts of all vars
  % then this pairing will have a lowered priority
  fqmp:=length setdiff_according_to(fq,fp,ftem_);
  fpmq:=length setdiff_according_to(fp,fq,ftem_);
  if nil then
  if tr_decouple then << 
    terpri()$
    write"p=",p," q=",q," s=",s," lfp=",length fp,
         " lfq=",length fq," lfu=",length union(fp,fq),
         " fqmp=",fqmp," fpmq=",fpmq
  >>$

  if (null a) and (null b) then <<
   dp:=get(p,'derivs)$ while dp and (caaar dp neq f) do dp:=cdr dp;
   dq:=get(q,'derivs)$ while dp and (caaar dq neq f) do dq:=cdr dq;
   % the absolute value of the difference of leading degrees cdar dp - cdar dq:
   m:=cdar dp - cdar dq$ if m<0 then m:=-m$
   % the length of both equations:
   m:=2^m*(lenq+lenp);
   % the number of different powers of f in p and q:
   while dp and (caaar dp = f) do <<m:=m*2$ dp:=cdr dp>>$
   while dq and (caaar dq = f) do <<m:=m*2$ dq:=cdr dq>>$
   % extra other functions in the other equation
   if (fqmp>0) then m:=m*3**(2*fqmp);
   if (fpmq>0) then m:=m*3**(2*fpmq);
  >>                       else 
  m:=(1.5^absodeg(a)*lenp+1.5^absodeg(b)*lenq)*
     (length union(fp,fq))**20$ 
  if nil then
  if tr_decouple then write" m2=",m;
  if s then << 
    % the equation s will be replaced by the new one
    % --> if (null struc_eqn) and fcteval(s) then m:=m*10**7; 
    % The above line has been commented out because fcteval takes
    % much time the first time it is called and substitutions
    % are to be done before decoupling anyway
    if (s=q) and (lenp>lenq) then m:=(m*lenp)/lenq else
    if (s=p) and (lenq>lenp) then m:=(m*lenq)/lenp;
    if (s=p) and (fqmp>0) then m:=m*10**(2*fqmp) else
    if (s=q) and (fpmq>0) then m:=m*10**(2*fpmq);
    if struc_eqn then
    if ((a and is_algebraic(p)) or
        (b and is_algebraic(q))    ) then m:=m*10**100 else
    if is_algebraic(p) and is_algebraic(q) then m:=m/10**5
  >>   else 
  % Enlarge m because extra equation is generated (temp. idea)
  m:=m*10$
  % The case the linearity of flin_ functions is destroyed
  if flin_ and freeof(flin_,f) and not freeoflist(fp,flin_)
                               and not freeoflist(fq,flin_) then m:=m*100;
  % Non-linearity in largest derivative not taken care of.
  if nil then
  if tr_decouple then write" m3=",m;
  info:=cons(list(list(p,a,l),
                  list(q,b,l1),
                  if (null a) and 
                     (null l) then f
                              else reval cons('DF,cons(f,append(l,a))),
                  s,
                  simpp or simpq
                 ),
             m)$
  return info$
end$

%symbolic procedure dec_put_info(l,rl)$   
%% l has form ((e4 (x 2 y) (y z)) 
%%             (e5 (z) (x 2 y 2)) (df f x 2 y 2 z) nil)
%% puts informations for decouple reduction step
%% result: ((df f x 2 y 2 z) e4 e5 nil)
%if l then
%begin scalar f$
%  put(caar l,'dec_info,cadar l)$     % saves (x 2 y) for e4
%  put(caadr l,'dec_info,cadadr l)$   % saves (z)     for e5
%  if (cadar l) and (cadadr l) then << % if both eq. are diff.
%    f:=caddr l;
%    if pairp f then f:=cadr f;
%    add_both_dec_with(f,caar l,caadr l,rl)$
%  >>$
%  return list(caddr l,caar l,caadr l,cadddr l)$
%end$

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

symbolic procedure dec_and_fct_select(pdes,vl,rl,hp,ordering)$  
% select 2 pdes for decoupling
% if rl then one pde must be simplified with the help of 
% another one and reduce its length
% if hp then only high priority decouplings (eqns with max 3-4 functions)
begin scalar min,f,l,l1,l2,done_pdes,car_pdes,len,
      d_car_pdes,val_car_pdes,val_p,d_p,w1,w2,rtn,f_in_flin,allvarfl$
  while pdes and null rtn do <<
    car_pdes:=car pdes;
    allvarfl:=get(car_pdes,'allvarfcts);
    if expert_mode or
       (flagp(car_pdes,'to_decoup) and allvarfl and
        ((null hp) or 
         ((length(allvarfl)<4) and (get(car_pdes,'terms)<10)) or
         (length(allvarfl)=1)
        )) then
    <<f:=caaar get(car_pdes,'derivs)$
      if not flin_ or (f_in_flin:=not freeof(flin_,f)) or
         (     fhom_ and (zerop car get(car_pdes,'hom_deg))) or
         (null fhom_ and freeoflist(get(car_pdes,'fcts),flin_)) or
         freeoflist(allvarfl,flin_) then <<
       % initializations for the special case of car_pdes:  0=df(f,...)
       len:=get(car_pdes,'printlength)$
       if (null record_hist) and (len=1) then <<
         val_car_pdes:=car get(car_pdes,'sqval);  % we drop the denominator
         if null cdr val_car_pdes and    % ie. only one term
            cdar val_car_pdes eq 1 and   % 2nd factor is 1     ### needed??
            cdaar val_car_pdes eq 1 and  % ie exponent is one  ### needed??
            pairp caaar val_car_pdes and
            (caaaar val_car_pdes='DF) and 
            (cadr caaar val_car_pdes=f) then
         d_car_pdes:=cddr caaar val_car_pdes else 
         if caaar val_car_pdes=f then d_car_pdes:=nil
                                 else len:=1000    
       >>$
       l:=assoc(ordering,get(car_pdes,'dec_with))$
       if rl then l:=append(l,assoc(ordering,get(car_pdes,'dec_with_rl)))$
       % unchecked pairings 
       for each p in cdr pdes do
% It should be possible that f is leading function in car_pdes but not
% in others
%       if not flin_ or f_in_flin or
%          (     fhom_ and (zerop car get(p,'hom_deg))) or
%          (null fhom_ and freeoflist(get(p,'fcts),flin_)) then 
       if expert_mode or
          (flagp(p,'to_decoup) and 
           member(f,get(p,'rational)) and
           ((null hp) or 
            (((l1:=length(union(allvarfl,get(p,'allvarfcts))))<4) and 
             (get(p,'terms)<10)                                       ) or 
            (l1=1) 
           ) and
           ((not member(p,l)) or
            ((not member(car_pdes,assoc(ordering,get(p,'dec_with)))) and
             ((null rl) or 
              (not member(car_pdes,assoc(ordering,get(p,'dec_with_rl)))))  
            ) 
           )
          )  
       then 
       % If both equations consist of a derivative of f only then
       % instant decision possible
       if (null record_hist) and (len=1) and (get(p,'printlength)=1) then <<
         val_p:=car get(p,'sqval);      % we drop the denominator
          d_p:=0$

         if null cdr val_p and   % ie. only one term
            cdar val_p eq 1 and  % 2nd factor is 1     ### needed??
            cdaar val_p eq 1 and % ie exponent is one  ### needed??
            pairp caaar val_p and
            (caaaar val_p='DF) and 
            (cadr caaar val_p=f) then
         d_p:=cddr caaar val_p else 
         if caaar val_p=f then d_p:=nil$

%         if (pairp val_p) and 
%            (car val_p = 'DF) and
%            (cadr val_p = f)    then 
%         d_p:=cddr val_p else
%         if val_p=f then d_p:=nil$

         if d_p neq 0 then <<
           w1:=which_deriv(d_p,d_car_pdes)$
           w2:=which_deriv(d_car_pdes,d_p)$
           if w1 and w2 then add_both_dec_with(ordering,car_pdes,p,rl) else
           % returns eg. ((e5 nil (x 2 y 2 z)) (e4 (x 2 y) (y z)) 
           %              (df f x 2 y 2 z) e5)
           if null w1 then rtn:={{p,nil,d_p},{car_pdes,w2,d_car_pdes},
                                 mvar val_p,p,nil}                %&&&&&&
                      else rtn:={{p,w1,d_p},{car_pdes,nil,d_car_pdes},
                                 mvar val_car_pdes,car_pdes,nil}  %&&&&&&
         >>
       >>                                     else 
       % The general case
       <<l1:=dec_info(car_pdes,p,f,vl,rl,ordering)$
         if expert_mode and null l1 then <<pdes:={nil};done_pdes:=nil;l2:=nil>>
                                    else
         if expert_mode or
            (quick_decoup and l1 and cadddr car l1 and
             ((null struc_eqn)                    or
              ((null is_algebraic(car_pdes)) and 
               (null is_algebraic(p       ))     )  )) 
         then rtn:=car l1 
         else if l1 then l2:=cons(l1,l2)
       >>$
       % Check pairings where f is *not* the leading function in 
       % car done_pdes. This has not been checked when this pairing 
       % was tested before.
       if null rtn then
       for each p in done_pdes do
% It should be possible that f is leading function in car_pdes but not
% in others
%       if not flin_ or f_in_flin or
%          (     fhom_ and (zerop car get(p,'hom_deg))) or
%          (null fhom_ and freeoflist(get(p,'fcts),flin_)) then 
       if flagp(p,'to_decoup) and 
          member(f,get(p,'rational))       and
          ((null hp) or 
           (((l1:=length(union(allvarfl,get(p,'allvarfcts))))<4) and 
            (get(p,'terms)<10)                                       ) or 
           (l1=1) 
          ) and
          ((not member(p,l)) or
           ((not member(car_pdes,assoc(ordering,get(p,'dec_with)))) and
            ((null rl) or 
             (not member(car_pdes,assoc(ordering,get(p,'dec_with_rl)))))  
           ) 
          )                                and
          ((null get(p,'allvarfcts)) or
           (f neq car get(p,'allvarfcts))) 
       then <<l1:=dec_info(car_pdes,p,f,vl,rl,ordering)$
              if expert_mode and null l1 then 
              <<pdes:={nil};done_pdes:=nil;l2:=nil>>
                                         else
              if quick_decoup and l1 and cadddr car l1 and
                 ((null struc_eqn)                    or
                  ((null is_algebraic(car_pdes)) and 
                   (null is_algebraic(p       ))     )  )
              then rtn:=car l1 
              else if l1 then l2:=cons(l1,l2)
       >>
      >>

    >>$
    done_pdes:=cons(car_pdes,done_pdes)$
    pdes:=cdr pdes
  >>$
  if rtn then return rtn$
 
  %--- l2 is the list of possible pairings of 2 equations
  %--- pick one of these pairings
  l1:=nil;  
  %--- l1 is the list of equations which still can be reduced
  %--- and where f=car get(equ,'allvarfcts), i.e. equations
  %--- which must not be used for generating new equations
  %
  %--- each l in l2 has the form
  %--- (((e4 (x 2 y) (y z)) (e5 (z) (x 2 y 2)) 
  %---  (df f x 2 y 2 z) nil nil) . num_value)
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
  if min then <<
   l:=car min$
   if (cadar l) and (cadadr l) then << % if both eq. are diff.
     f:=caddr l;
     if pairp f then f:=cadr f;
     add_both_dec_with(ordering,caar l,caadr l,rl)$
   >>$
   return l     % dec_put_info(car min,rl)$
  >>
end$

symbolic procedure err_catch_elimin(ddpcp,p,ltp,dgp,ddqcp,q,ltq,dgq,x,once)$  
begin scalar h,bak,kernlist!*bak,kord!*bak,bakup_bak;
 bak:=max_gc_counter$ max_gc_counter:=my_gc_counter+max_gc_elimin;
 kernlist!*bak:=kernlist!*$
 kord!*bak:=kord!*$
 bakup_bak:=backup_;backup_:='max_gc_elimin$
 h:=errorset({'elimin,mkquote ddpcp,mkquote p,mkquote ltp,mkquote dgp,
                      mkquote ddqcp,mkquote q,mkquote ltq,mkquote dgq,
                      mkquote x,mkquote once},t,t) % t,t for backtrace and message if error 
    where !*protfg=t;
 kernlist!*:=kernlist!*bak$
 kord!*:=kord!*bak;
 erfg!*:=nil; 
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then nil
                    else car h
end$

symbolic procedure err_catch_loadform2$
begin scalar h$
 if null crack_load_command then crack_load_cmd()$
 h:=compress reverse cons('!",cddddr cdddr reverse explode
                                        crack_load_command)$
 if and(member('csl,lispsystem!*), member('sixty!-four,lispsystem!*)) or
    and(member('psl,lispsystem!*), betap lshift(1,20)) 
 then h:=bldmsg("%w/form2_64",h)  % 64:
 else h:=bldmsg("%w/form2_32",h); % 32:
 h:=errorset({'load,h},t,t)$
 % 26 Sep 2010, h is currently = 99, i.e. error in loading
 if atom h then form_pipe := nil;
end$

symbolic procedure elimin(ddpcp,p,ltp,dgp,ddqcp,q,ltq,dgq,x,once)$  
% returns {resulting_eqn, multiplier_of_ddpcp, multiplier_of_ddqcp}
begin
 scalar dgs,s,flg,quoti,lts,xsq,lco,natbak,formputfile,formszefile,
        formgetfile,ss,sze,current_dir,t0,t1,t2,t3,t4,eqn_input,oldinpu,intbak,
        uncachedbak,fcpp,fcqp,fcsp,fcpq,fcqq,fcsq,h,klist,slist,flist,
        oprtch,chnout,all_rational_kernels,xtrnlcall$  %,form_handle$

 if dgp > dgq then << flg:=t; dgs:=dgq >>
              else dgs:=dgp$
 fcpp:=simp 1; fcpq:=simp 0;
 fcqq:=simp 1; fcqp:=simp 0;
 xsq:=mksq(x,1);

%algebraic write"p=",{'!*SQ,p,t}$algebraic write"ltp=",{'!*SQ,ltp,t}$
%algebraic write"q=",{'!*SQ,q,t}$algebraic write"ltq=",{'!*SQ,ltq,t}$

 if null get(ddpcp,'non_rat_kern) and
    null get(ddqcp,'non_rat_kern) then all_rational_kernels:=t$

 while dgs neq 0 do <<
  quoti:=quotsq(ltp,ltq);

  % !!! the most time-consuming statement (computation of the S-polynomial): !!!
  % to use FORM for it needs only: 
  % lisp <<form_comp:=t;
  %        form_pipe:=..;    % whether communication FEDUCE-->FORM through pipe
  %        form_max_read:=.. % depending on available memory, default 10000
  % >>$
  if form_comp and all_rational_kernels then << 
   t0:=time()$         
   natbak:=!*nat;     
   if !*nat then algebraic(off nat)$
   %write "Start writing FORM input"$terpri()$

   %--- Generation of file names for the data exchange
   ss:=level_string(session_)$
   current_dir:=if form_tmp_dir neq "" then form_tmp_dir
                                       else pwd()$
   form_eqn_idx:=add1 form_eqn_idx$
   %-- the file that buffers input into FORM:
   setq(formputfile,bldmsg("%w%w_%d%w",current_dir,ss,form_eqn_idx,".frm"));
   %-- the file into which FORM will write the size of the result:
   setq(formszefile,bldmsg("%w%w_%d%w",current_dir,ss,form_eqn_idx,".sze"));
   %-- the file into which FORM will write the potentially long result:
   setq(formgetfile,bldmsg("%w%w_%d%w",current_dir,ss,form_eqn_idx,".red"));

   if form_pipe then err_catch_loadform2()$
   if form_pipe then <<
         % maybe the Tempdir directive in FORM is enough, just cautious.
    system bldmsg ("mkdir -p /tmp/formtempdir.%w",getpid());
    cd bldmsg ("/tmp/formtempdir.%w",getpid()); 
  %  if null form_chnpair then <<
    if form_chnpair then << close cadr form_chnpair; close caddr form_chnpair>>;
    form_chnpair := start_form();  % return an algebraic channelpair (list out in)
                             % as seen by FORM, vice versa for REDUCE
    chnout := wrs caddr form_chnpair$
    lisp linelength 1000000$   % for now, should not be necessary in future.
   >>           else algebraic(out formputfile)$                               

   %--- Formerly used file commands
   %   setq(ss,bldmsg("rm %w",formszefile));            system ss$     
   %   setq(ss,bldmsg("mkfifo -m 777 %w",formputfile)); system ss; 
   %   setq(ss,bldmsg("form -q %w &",formputfile));     system ss; 
   %   chnout= open(formputfile,'output);                   
   %   ofl!*bak:=ofl!*$                                      
   %   ofl!*:=formputfile$  % any value neq nil, to avoid problem with redfront 
   %   chnout:= wrs chnout;                                  

   comment
   - All FORM related files are written in a dedicated directory.
   - How about working with expressions that involve derivatives, i.e. how can FORM
     be told the REDUCE kernel ordering of different derivatives? This would speed
     up the reading of FORM output that involves derivatives.
   - if piping to FORM then FORM is started form with flag  -pipe in the form2 file
   - (There is also a #pipe and #system preprocessor command for FORM.)
   - to have form write into standard output use #write without file name
   - There is a format output command in form:

     Type                 Output control statement
     Syntax         fo[rmat] <option>      semicolon
     See also         print (7.86)

     fo reduce semicolon  (according to Sergey still problems with long numbers when continuation 
     line starts with spaces)
     but there is an option: nospaces
   - The form command 
	 Print +f                
     prints only in log-file.
   - For embedding form in other applications see
     http://www.nikhef.nl/~form/maindir/documentation/reference/online/man.html#SECTION001690000000000000000
   - hint: FORM can find coefficients of monomials which might be more efficient
     than in REDUCE;

   %--- Change ** to ^ in REDUCE output
   oprtch:= get('expt,'prtch);
   put('expt,'prtch,'!^);

   %--- Redefine the comment character and specify other parameters
   write "#: CommentChar %"$       terpri()$
   if form_tmp_dir neq "" then <<
    write bldmsg("%w%w","#: TempDir ",form_tmp_dir);terpri()
   >>;
   % write "#: SmallSize 5000000"$   terpri()$
   % write "#: LargeSize 20000000"$  terpri()$
   % write "#: TermsInSmall 200000"$ terpri()$
   % write "#: WorkSpace 40000000"$  terpri()$
   % write "#: MaxTermSize 1000000"$ terpri()$
   % write "#: MaxNumberSize 300000"$terpri()$
   % write "on lowfirst;"$   terpri()$  % to have form output sorted
                                        % with lower powers first (is default)
   write "on highfirst;"$  terpri()$    % to have form output sorted with 
                                        % higher powers first, slightly faster
   % give directory for temporary FORM files with -t

   %--- Collect all atomic and non-atomic kernels
   klist:=union(get(ddpcp,'kern),get(ddqcp,'kern));
   for each h in klist do
   if atom h then slist:=union({h},slist)
             else <<
    if car h = 'DF then slist:=union({cadr h},slist)$
    flist:=union({car h},flist);
   >>$
   slist:=kernel_sort union(vl_,slist);  
   %slist:=kernel_sort slist;  
   flist:=kernel_sort flist;

   %--- Write the declarations
   write "Off statistics;"$terpri()$   
   if flist then <<
    write "CFunctions"$
    for each h in flist do write" ",h$
    write ";"$ terpri()    
   >>$
   write "Symbols"$
   for each h in slist do write" ",h$
   write ";"$ terpri()$    

   %--- Write the equations and multipliers (see module writefrm in crutil.red)
   write "L p ="$ writesqfrm p$  
   write ".sort"$                                               terpri()$
   write "L mp="$ writesqfrm (cdr quoti ./ 1)$
   write ".sort"$                                               terpri()$
   write "L q ="$ writesqfrm q$
   write ".sort"$                                               terpri()$
   write "L mq="$ writesqfrm (car quoti ./ 1)$
   write ".sort"$                                               terpri()$
   write "L rez=p*mp-q*mq;"$                                    terpri()$
   write ".sort"$                                     terpri()$ terpri()$

   %--- Write the FORM output commands
   write "skip;"$                                               terpri()$
   write "L nt=termsin_(rez);"$                                 terpri()$
   write ".sort"$                                               terpri()$

   write "skip;"$                                               terpri()$
   if form_pipe  then <<
    write "#toexternal ""%e $ "", nt "$                          terpri()$
    write "#toexternal ""     ""     "$                          terpri()$
    write "#toexternal "" end$""     "$ 		         terpri()$
    write "#toexternal ""     ""     "$                terpri()$ terpri()$
   >>            else <<
    write "#write <",formszefile,"> ""%E $ "", nt "$             terpri()$
    write "#write <",formszefile,"> ""     ""     "$             terpri()$
    write "#write <",formszefile,"> "" end$""     "$             terpri()$
    write "#write <",formszefile,"> ""     ""     "$   terpri()$ terpri()$
   >>;

   write "#write <",formgetfile,"> ""%E $ "", rez"$             terpri()$
   write "#write <",formgetfile,"> ""     ""     "$             terpri()$
   write "#write <",formgetfile,"> "" end$""     "$             terpri()$
   write "#write <",formgetfile,"> ""     ""     "$   terpri()$ terpri()$

   write ".end"$                                                terpri()$

   % ofl!*:=ofl!*bak$                    % These 2 lines are needed for the
   % close wrs chnout;                   % formerly used file commands above.

   if form_pipe then <<
    wrs chnout;
    channelflush caddr form_chnpair
   >>           else algebraic(shut formputfile);                             

   %--- Change back ^ to ** in REDUCE output
   put('expt,'prtch,oprtch);
   if natbak then algebraic(on nat)$
   t1:=time()$
   %if print_ then <<
   % terpri()$write"  time to write FORM input:    ",t1-t0," msec"$terpri()$
   % write"  FORM comment about time: "$terpri()
   %>>$

   %--- Call FORM
   if not form_pipe then <<

    % Check the installation of FORM:
    % FORM is distributed together with Crack and is called by
    % 'crack-directory'/form32/form      or
    % 'crack-directory'/form64/form
    % This has to be done >after< loading crack because the
    % global variable options!*; does store the crack call command
    % only after crack is loaded and that is needed to find the
    % directory name where crack and thus form32/form and form64/form
    % are stored.

    xtrnlcall := getenv "FormCall";
    if null xtrnlcall then <<
     % set the environment variable FormCall
     if null crack_load_command then crack_load_cmd()$
     xtrnlcall:=compress reverse cons('!",cddddr cdddr reverse explode 
                                                    crack_load_command)$
     if and(member('csl,lispsystem!*), member('sixty!-four,lispsystem!*)) or
        and(member('psl,lispsystem!*), betap lshift(1,20)) 
     then setenv("FormCall",bldmsg("%w/form64/form",xtrnlcall))  % 64:
     else setenv("FormCall",bldmsg("%w/form32/form",xtrnlcall)); % 32:
     xtrnlcall := getenv "FormCall"
    >>$

    if null xtrnlcall then
    rederr("The environment variable FormCall is not set.",t,t);
    if null filep xtrnlcall then
    rederr({"No file ",xtrnlcall,
            " was found. Probably form is not installed.",
            " This should have been distributed with CRACK."},t,t);

    setq(ss,bldmsg("%w -q %w",xtrnlcall,formputfile));  system ss
   >>$
   t2:=t1$
   % The following time test is useless, as REDUCE did not compute since measuring
   % t1, therefore t2=t1, because time() measures CPU usage time by REDUCE
   %t2:=time()$
   %if print_ then <<write"  time for FORM computation:   ",t2-t1," msec"$terpri()>>$
   if not form_pipe then <<
%    setq(ss,bldmsg("rm %w",formputfile));  system ss$ % delete the FORM input file
%#################################
   >>$

   %-- Preparing REDUCE for reading
   uncachedbak:=!*uncached$  !*uncached:=t;
   intbak:=!*int$            !*int:=nil$

   %--- reading in the FORM comment on the number of terms:
   if form_pipe then <<
    oldinpu := rds cadr form_chnpair$
    sze:= xread(t)
   >>           else <<
    eqn_input:= open (formszefile,'input);
    oldinpu:= rds eqn_input; % backup of old input source
    sze:= xread(t)$
    close eqn_input
   >>; 
   rds oldinpu; 
   if print_ then <<write"  FORM computed ",sze," term(s)."$terpri()>>$
   if not form_pipe then <<
    setq(ss,bldmsg("rm %w",formszefile)); 
    system ss    % delete the FORM size file
   >>;
   form_eqn_on_disk:=cons((sze . formgetfile),form_eqn_on_disk)$

   %--- reading in the FORM result: (see module parseformoutput in crutil.red)
   % The following read statement is currently commented out as either the
   % expression is too big to be read in and to be used further on, or it is
   % not too large and then computing this expression will be faster than
   % reading it from a file. It would be beneficial to have a interactive
   % possibility to specify and read in single large expressions.

   % s:= simp formoutputread formgetfile;  % simp drops !*SQ if there is one and
   t3:=time()$                             % generates sq-form if value is a number
   % if print_ then <<write"  time to read FORM output:    ",t3-t2," msec"$terpri()>>$

   %-- Re-setting REDUCE configuration
   !*int:=intbak;
   !*uncached:=uncachedbak;
  >>;   % else 

  if form_comp and 
     (sze>form_max_read) then <<
   if print_ then <<
    write"Because the equation with ",sze," terms computed by FORM is too big, it"$terpri()$ 
    write"is not read into REDUCE but also not computed in REDUCE --> different try."$terpri()$
   >>$
  >>                     else << % computing is faster than reading from file
   s:=subtrsq(multsq(p,(cdr quoti . 1)), multsq(q,(car quoti . 1)))$           
   if null all_rational_kernels then s:=simp!* {'!*SQ,s,nil}$

   % form file loeschen % If some interactive bookkeeping of long equations would
   if form_comp then << % be available then the file would not be deleted here.
    t4:=time()$
    %if print_ then <<write"  time for CRACK computation:  ",t4-t3," msec"$terpri()>>$
    setq(ss,bldmsg("rm %w",formgetfile));  system ss$ % delete the FORM output file
    form_eqn_on_disk:=cdr form_eqn_on_disk
   >>
  >>$

  % Different tests about the correctness of the FORM computation 
  if nil then                  % i.e. currently disabled
  if form_comp then <<        
   %write"s =",s $terpri()$
   %write"ss=",ss$terpri()$
   if s=ss then write"FORM is CORRECT!"
           else write"FORM was WRONG!"$  terpri()$
   if sqzerop subtrsq(s,ss) then write"FORM is CORRECT!"
                            else write"FORM was WRONG!"$  terpri()$
   if sqzerop subtrsq(s,resimp ss) then write"FORM is CORRECT!"
                                   else write"FORM was WRONG!"$  terpri()$
   if sqzerop resimp subtrsq(s,ss) then write"FORM is CORRECT!"
                                   else write"FORM was WRONG!"$  terpri()$
  >>$

  fcsp:=subtrsq(multsq(fcpp,(cdr quoti . 1)),
                multsq(fcqp,(car quoti . 1)) )$
  fcsq:=subtrsq(multsq(fcpq,(cdr quoti . 1)),
                multsq(fcqq,(car quoti . 1)) )$

  if once                % doing only one step, i.e. eliminating only one leading derivative 
     or t then dgs:=0    % or t to do a slower decoupling of high degree but very overdetermined 
                         % systems 
          else << 
   lco:=coeff1({'!*sq,s,t},{'!*sq,xsq,t},nil)$  
   dgs:=hipow!*$ 
   lco:=nth(cdr lco,add1 dgs)$ 
   lco:=if pairp lco and (car lco='!*SQ) then cadr lco 
                                         else simp lco; 
   lts:=multsq(lco, mksq(x,dgs))$ 

   if flg=t then << 
    p:=s;                                                                 % only for once=nil
    ltp:=lts;                                                             % only for once=nil
    dgp:=dgs;                                                             % only for once=nil
    fcpp:=fcsp;                                                           % only for once=nil
    fcpq:=fcsq;                                                           % only for once=nil
    if dgq>dgp then flg:=nil                                              % only for once=nil
   >>       else <<
    q:=s;                                                                 % only for once=nil
    ltq:=lts;                                                             % only for once=nil
    dgq:=dgs;                                                             % only for once=nil
    fcqp:=fcsp;                                                           % only for once=nil
    fcqq:=fcsq;                                                           % only for once=nil
    if dgp>dgq then flg:=t                                                % only for once=nil
   >>
  >>
 >>;
 quoti:=err_catch_gcd({'!*sq,fcsp,t},{'!*sq,fcsq,t});  
 quoti:=if pairp quoti and (car quoti='!*SQ) then cadr quoti % to get rid of '!*SQ
                                             else simp quoti$
 return {quotsq(s   ,quoti),
         quotsq(fcsp,quoti),
         quotsq(fcsq,quoti) }
end$  % elimin

symbolic procedure dec_new_equation(l,rl)$  
% l has form ((e4 (x 2 y) (y z)) (e5 (z) (x 2 y 2)) (df f x 2 y 2 z) nil nil)
% This means: e4 has df(f,y,z) and is differ. wrt. xxy
%             e5 has df(f,x,2,y,2) and is diff. wrt. z 
%             to eliminate df(f,x,2,y,2,z),  
%             nil is substituted,
%             nil: do NOT stop after lowering the power of the leading deriv once
% rl: do a length reduction decoupling step
%
begin scalar ld,f,ip,iq,s,nvl,lco,p,ddp,ddpcp,ldp,ldpsq,ltp,dgp,pfac,
                                  q,ddq,ddqcp,ldq,ldqsq,ltq,dgq,qfac,
             h,once$
  % ld       common leading derivative after differentiations

  % ddpcp    will be the name of the equation, e.g.  e4
  % p        at first the value of the equation, later df(p,ip)
  % ddp      will be the history value of the equation
  % ip       is a list of differentiations to be done with p
  % ldp      is the leading derivative in p
  % ldpsq    is ldp in sq-form
  % ltp      at first the lead. term of p then is the leading term in df(p,ip)
  % dgp      at first highpow of ldp in p then highpow of df(ldp,ip) in ltp
  % lco      is the coefficient of ldp**dgp in ltp (and the same for q)
  % pfac     an overall factor of p that has been dropped but that may vanish

  % similar with q

  ld:=caddr l$
  f:=if pairp ld then cadr ld
                 else ld$
  ip:=cadar l$
  iq:=cadadr l$
  s:=cadddr l$
  once:=car cddddr l$
  ddp:=caar l$  ddpcp:=ddp$
  ddq:=caadr l$ ddqcp:=ddq$
  p:=get(ddp,'sqval)$
  q:=get(ddq,'sqval)$
  if record_hist then <<
   nvl:=get(ddp,'nvars)$
   if get(ddq,'nvars)<nvl then nvl:=get(ddq,'nvars)$
   if s=ddp then ddp:=get(ddp,'histry_) else
   if s=ddq then ddq:=get(ddq,'histry_)
  >>$
  ddp:=simp ddp$
  ddq:=simp ddq$

  if print_ and ((null rl and tr_decouple) or 
                 (     rl and tr_redlength)  ) then
  <<terpri()$write "  first pde ",caar l,": "$
    typeeq caar l$ 
    if ip then write "is diff. wrt. ",ip,","
          else write "is not differentiated,"$
    write "  second pde ",caadr l,": "$
    typeeq caadr l$
    if iq then write "is diff. wrt. ",iq," "
          else write "is not differentiated, "$
    write"to eliminate "$mathprint ld$
  >>$

  if atom ld then ldp:=ld else <<
   ldp:=cadr ld;
   if caddar l then ldp:=cons('DF,cons(ldp,caddar l))
  >>;

  ldpsq:=mksq(ldp,1)$
  lco:=coeff1({'!*sq,p,t},{'!*sq,ldpsq,t},nil)$
  dgp:=hipow!*$

  pfac:=simp 1;
  if null ip then <<
    lco:=nth(cdr lco,add1 dgp)$
    lco:=if pairp lco and (car lco='!*SQ) then cadr lco
                                          else simp lco; 
    ltp:=multsq(lco, mksq(ldp,dgp))$
  >>         else 
  if (dgp=1) and % (not fixp lco) 
                  ((not fixp car lco) or (not fixp cdr lco)) % or should one test constancy?
  then << 
    lco:=nth(cdr lco,add1 dgp)$
    lco:=if pairp lco and (car lco='!*SQ) then cadr lco
                                          else simp lco; 
    ltp:=multsq(lco, mksq(ldp,dgp))$
    p:=multiple_diffsq( quotsq( subtrsq(p,ltp), lco), ip)$
    if record_hist then
    ddp:=multiple_diffsq( quotsq(ddp,lco),ip);
    h:=(cdr p . 1)$
    pfac:=lco$ %quotsq(lco,h)$  may drop factors and solutions
    if (not can_not_become_zeroSQ(pfac,get(ddpcp,'fcts))) and 
       (s=ddqcp) then s:=nil;
    ltp:=multsq(simp ld,h)$
    p:=addsq(ltp, (car p . 1))$
    if record_hist then ddp:=multsq(ddp,h)
  >> else <<
    dgp:=1;
    ltp:=multsq(diffsq(p,mvar car mksq(ldp,1)),multiple_diffsq(ldpsq,ip)); 
    p:=multiple_diffsq(p,ip);
    if record_hist then ddp:=multiple_diffsq(ddp,ip)
  >>$

  if atom ld then ldq:=ld else <<
   ldq:=cadr ld;
   if caddar cdr l then ldq:=cons('DF,cons(ldq,caddar cdr l))
  >>;

  ldqsq:=mksq(ldq,1)$
  lco:=coeff1({'!*sq,q,t},{'!*sq,ldqsq,t},nil)$
  dgq:=hipow!*$

  qfac:=simp 1;
  if null iq then <<
    lco:=nth(cdr lco,add1 dgq)$
    lco:=if pairp lco and (car lco='!*SQ) then cadr lco
                                          else simp lco; 
    ltq:=multsq(lco,mksq(ldq,dgq))$
  >>         else
  if (dgq=1) and % (not fixp lco) 
                  ((not fixp car lco) or (not fixp cdr lco)) % or should one test constancy?
  then << 
    lco:=nth(cdr lco,add1 dgq)$
    lco:=if pairp lco and (car lco='!*SQ) then cadr lco
                                          else simp lco; 
    ltq:=multsq(lco,mksq(ldq,dgq))$
    q:=multiple_diffsq( quotsq( subtrsq(q,ltq), lco), iq)$
    if record_hist then
    ddq:=multiple_diffsq( quotsq(ddq,lco),iq);
    h:=(cdr q . 1)$       % the new lco
    qfac:=lco$ % quotsq(lco,h)$ may drop factors and solutions
    if (not can_not_become_zeroSQ(qfac,get(ddqcp,'fcts))) and 
       (s=ddpcp) then s:=nil;
    ltq:=multsq(simp ld,h)$
    q:=addsq(ltq, (car q . 1))$
    if record_hist then ddq:=multsq(ddq,h)
  >> else <<
    dgq:=1;
    ltq:=multsq(diffsq(q,mvar car mksq(ldq,1)),multiple_diffsq(ldqsq,iq)); %##### does this work with resimp?
    q:=multiple_diffsq(q,iq);
    if record_hist then ddq:=multiple_diffsq(ddq,iq)
  >>$

  % l:=list(caar l,caadr l)$
  % if iq then q:=simplifypde(reval cons('DF,cons(q,iq)),ftem,nil,nil (?))$
  % if ip then p:=simplifypde(reval cons('DF,cons(p,ip)),ftem,nil,nil (?))$
  % contradiction_:=nil$
 
  % h:=reval !*q2a simpresultant list(p,q,ld)$
  return 
  if (l:=err_catch_elimin(ddpcp,p,ltp,dgp,ddqcp,q,ltq,dgq,ld,once)) then
     list(l,s,ddpcp,ddqcp,ddp,ddq,ld,pfac,qfac)                     else nil$
end$ % of dec_new_equation

symbolic procedure dec_reduction(h,pdes,ftem,%forg,              
                                 vl,rl,ordering)$
% do a reduction step or a cross differentiation either
% h is the result of dec_new_equation() and has the structure
%   list(elimin(p,ltp,dgp,q,ltq,dgq,ld),s,p,q,ddp,ddq,ld,pfac,qfac)$
% if rl then one pde must be simplified with the help of 
% another one and reduce its length
begin scalar s,p,q,ddp,ddq,ld,len,a,ip,iq,pfac,qfac,f$
 s:=cadr h$        % eg.  e_4 or nil
 p:=caddr h$       % eg.  e_5
 q:=cadddr h$      %    "
 ddp:=nth(h,5)$    % in sq-form
 ddq:=nth(h,6)$    %    "
 ld:=nth(h,7)$     % eg. (df f x 2 y z)
 if pairp ld then f:=cadr ld else f:=ld;
 pfac:=nth(h,8)$   % in sq-form
 qfac:=nth(h,9)$   % in sq-form
 h:=car h$
 % If an equation is to be substituted then the new system must 
 % be sufficient after replacing one equations through another one.
 % --> the replaced equation must not have been multiplied with
 % possibly vanishing factors

 if s and (null rl) and % (sufficient_decouple) and
    % for rl=t already checked
    (((s=p) and not can_not_become_zeroSQ(cadr  h,get(q,'fcts))) or
     ((s=q) and not can_not_become_zeroSQ(caddr h,get(p,'fcts)))    ) 
 then s:=nil$

 % tracing comments
 
 if (null rl and tr_decouple) or
    (     rl and tr_redlength) then <<
  terpri()$
  write p," (resp its derivative) is multiplied with"$terpri()$
  a:=if qfac=(1 . 1) then cadr h
                     else multsq(qfac,cadr h)$ 
  len:=delengthSQ a$
  if print_ and len<print_ then mathprint {'!*SQ,a,t} 
                           else <<write "expr. with ",len," terms."$terpri()>>$

  write q," (resp its derivative) is multiplied with"$terpri()$
  a:=if pfac=(1 . 1) then caddr h
                     else multsq(pfac,caddr h)$ 
  len:=delengthSQ a$
  if print_ and len<print_ then mathprint {'!*SQ,a,t} 
                           else <<write "expr. with ",len," terms."$terpri()>>
 >>$

 % If an equation is used for a substitution of a derivative which is
 % not a leading derivative and the length of the equation is
 % increased then drop the new equation

 if (null rl) and % for rl=t the length comparison is already done
    (null expert_mode) and % not explicitly ordered by user
    (car h) and s and ((null struc_eqn) or (atom ld)) 
 then <<
  len:=no_of_terms(car h);
  if pairp(ld) and (car ld = 'DF) then ld:=cdr ld
                                  else ld:=list ld;
  if ((s=p) and 
      (ld neq caar get(p,'derivs)) and
      (len>get(p,'terms))) or
     ((s=q) and 
      (ld neq caar get(q,'derivs)) and
      (len>get(q,'terms))) then 
  return <<
   if print_ then <<
    write"The tried reduction of a non-leading derivative"$terpri()$
    write"would have only increased the equation's length."$terpri()
   >>$
   add_both_dec_with(ordering,p,q,rl);
   list(nil)
  >>;
  if cdr ld then ld:=cons('DF,ld)
            else ld:=car ld;
 >>$

 % the case of a resulting identity 0=0

 if car h then
 if sqzerop car h and null rl then <<
  % for rl=t the case that the multipliers contain ftem_ has already
  % been checked
  if print_ then <<terpri()$write" An identity 0=0 results. ">>$
  if null ip and null iq and null s and
   % if s<>nil then multipliers can not be ftem_ dependent
   (!*batch_mode or 
    (batchcount_>=stepcounter_)) then << % i.e. only if batch_mode
   a:=proc_list_;
   % Have already all normal factorizations be tried?
   while a and (car a neq 8) and (car a neq 30) do a:=cdr a;
   if a and (car a = 8) then
   to_do_list:=cons(list('factorize_any,%pdes,forg,vl_,
                         list if get(p,'fac) then p else q),
                    to_do_list);
  >>;
  a:=nil;
  add_both_dec_with(ordering,p,q,rl);
 >>             else <<
  a:=mkeqSQ(if pfac neq (1 . 1) then if qfac neq (1 . 1) then multsq(multsq(pfac,qfac),car h)
                                                         else multsq(pfac,car h)
                                else if qfac neq (1 . 1) then multsq(qfac,car h)
                                                         else                   car h ,
            nil,nil,ftem,vl,allflags_,t,list(0),
            prepsq addsq(multsq(cadr  h,ddp),
                         multsq(caddr h,ddq) ),pdes)$
  if print_ and ((null rl and tr_decouple ) or 
                 (     rl and tr_redlength)    ) then
  <<terpri()$mathprint reval {'EQUAL,a,get(a,'histry_)}>>
 >>$

 if record_hist and (car h) and (sqzerop car h) then 
%new_idty({'PLUS,{'TIMES,cadr  h,ddp},{'TIMES,caddr h,ddq} }, pdes, t);
 new_idty(prepsq addsq( multsq(cadr  h,ddp), multsq(caddr h,ddq) ), pdes, t);

 % also if car h is not identical 0 but with less variables.
 % It still can be the case that some functions of fewer variables
 % still depend on all the differentiation variables of the divergence
 % Then integration of the curl is not done(possible?)

 % The following lines have been commented out 9.9.2001 as the
 % cycle-test with dec_hist_list is too crude. It is necessary to
 % record which method (decoupling or length-reduction-decoupling or
 % shortening) leads to a repetition, or better just to check only 
 % when doing length-reduction because straightforward decoupling
 % should be done anyway.
  
 %if a and (null s) and member(get(a,'val),dec_hist_list) then <<
 %  drop_pde(a,nil,nil)$
 %  add_both_dec_with(ordering,car l,cadr l,rl);
 %  if print_ and tr_decouple then <<
 %    terpri()$write "the resulting pde would lead to a cycle"$
 %  >> 
 %>>                                                      else <<
 if print_ then <<
  write"Eliminate "$
  mathprint ld$
  write"from ",if ip then cons('DF,cons(p,ip))
                     else p, " and ",
               if iq then cons('DF,cons(q,iq))
                     else q, ". "$
  if a then <<
   if s then << 
    write s,": "$terpri()$
    typeeq s; 
    write"is replaced by ",a,": "
   >>   else write a," is added: "$
   terpri()$
   typeeq a
  >>   else 
  if s then <<write s," is deleted.";terpri()>>$
 >>$
 if null s then add_both_dec_with(ordering,p,q,rl)
           else <<      % reduction, s is the equation to be replaced 
  % The following was commented out as in_cycle() is to take care of
  % preventing cycles, l had the value which is now the input of
  % dec_new_equation() 
  %
  % l:=delete(s,l)$
  %
  % if not (ip or iq) then << 
  %  % The equations wrt which s has already been decoupled
  %  % are to be listed under dec_with wrt to the equation
  %  % of both that is kept which is car l
  %  % purpose: These decouplings should not be done again
  %  % with car l as this may result in a cycle
  %  dwsa:=get(    s,'dec_with)$  
  %  dwla:=get(car l,'dec_with)$  
  %  for each el in dwsa do <<     
  %   % el are the different orderings, if more than one are
  %   % in use then something must be changed probably
  %   dwlb:=assoc(car el,dwla)$
  %   dwla:=delete(dwlb,dwla)$
  %   if dwlb then dwlb:=cons(car el,union(cdr el,cdr dwlb))
  %           else dwlb:=el$
  %   dwla:=cons(dwlb,dwla)
  %  >>$ 
  %  put(car l,'dec_with,dwla)$
  % >>$

  % The following was taken out some time ago (now 9.9.2001)
  % because it probably prevented a complete computation
  % % If other than the leading derivatives are reduced then
  % % the new equ. a must inherit 'dec_with from equ. s
  % if a and get(a,'derivs) and 
  %    (car get(a,'derivs) = car get(s,'derivs)) then <<
  %  dwsa:=get(s,'dec_with)$
  %  put(a,'dec_with,dwsa)$
  % >>$

  % The following has been taken out with the dec_hist_list test above
  % if dec_hist>0 then <<
  %  if length dec_hist_list>dec_hist then
  %     dec_hist_list:=cdr dec_hist_list$
  %  dec_hist_list:=reverse cons(get(s,'val),reverse dec_hist_list)$
  % >>$

  drop_pde(s,if a then cons(a,pdes) else pdes,nil)

 >>$
 %>>$ commented out together with code from above

 % Update of flin_
 % if a and flin_ and null member(f,flin_) then 
 % if not lin_check(get(a,'val),smemberl(flin_,get(a,'fcts))) then 
 % for each h in get(a,'fcts) do flin_:=delete(h,flin_);
 % maybe one could drop just some but then one would have to investigate
 % all subsets to find the smallest subset to drop

 return list(a) 
 % a is either a new equation or nil if s has beed reduced to an identity
end$ % of dec_reduction

symbolic procedure dec_fct_check(a,l)$    
% checks, if a function occurs in only one pde
begin scalar ft,n$
  ft:=get(a,'fcts)$
  while ft and l do
    <<if flagp(car l,'to_decoup) then
        ft:=setdiff_according_to(ft,get(car l,'fcts),ftem_)$
    l:=cdr l>>$
  n:=get(a,'nvars)$
  while ft and (n<=length fctargs(car ft)) do ft:=cdr ft$
  if ft then remflag1(a,'to_decoup)$
  return ft$
end$

symbolic procedure check_cases_for_separant(l)$  % called only from one place  
% l has form ( (e4 (x 2 y) (y z))   
%              (e5 (z) (x 2 y 2))   
%              (df f x 2 y 2 z)    nil    nil)
% This means: e4 has df(f,y,z) and is differ. wrt. xxy
%             e5 has df(f,x,2,y,2) and is diff. wrt. z 
%             to eliminate df(f,x,2,y,2,z),  
%             nil is substituted,
%             substitution is not essential
begin scalar s,h,lde,sy$
 % Is a case-distinction to be made about whether the separant
 % is zero or non-zero?
 s:=cadddr l;                 % the equation to be substituted

 return
 if lin_problem or            % then definitely no cases
    (null s) or               % both equations are differentiated --> no cases
    (not pairp caddr l) or    % purely algebraic decoupling
                              % ### BUT THAT CAN LEAD TO CASES AS WELL, OR? 
                              % ### but they are probably taken care of otherwise
    (null flagp(if s=caar l then caadr l              % see comments on to_separant
                            else caar  l,'to_separant)) % in crinit.red
 then nil                     % no case-distinction
 else <<
  if s=caar l then h:=cadr l  % h are the data of the lower priority (e.g. order)
              else h:=car  l$ % equation that gets differentiated
  if min_nu_of_eqn or 
     null cadr h then nil     % no differentiation -> no case-distinction
                 else <<      % lower order equ. is not diff.
   lde:=if null caddr h then cadr caddr l    % lead. deriv. is algebraic
                        else cons('DF,cons(cadr caddr l,caddr h));
   sy:=diffsq(get(car h,'sqval),mvar car mksq(lde,1));  

   if can_not_become_zeroSQ(sy,get(car h,'fcts)) then 
   <<remflag1(car h,'to_separant)$ nil>>           else 
   <<to_do_list:=cons(list('split_into_cases,sy),to_do_list); 
    if print_ then <<
     write"To reduce the leading derivative"$terpri()$
     mathprint caddr l$
     write"in ",s," using ",car h," a case distinction will be made."$terpri()
    >>$
    t
   >>   
  >>
 >>
end$

symbolic procedure dec_one_step(pdes,ftem,%forg,  
                                vl,hp,ordering)$
% do one decouple step for 2 pdes from l, differentiate them
% and add the new pde or replace an original one
begin scalar l0,l1,l2,l,ruli,cntr$ %,f$
 l:=pdes;
 if not expert_mode then l0:=l
                    else <<
  l0:=selectpdes(l,2)$
  drop_dec_with(car  l0,cadr l0,nil)$
  drop_dec_with(cadr l0,car  l0,nil)$
 >>$
 ruli:=start_let_rules()$
 cntr:=0$
again:
 l1:=dec_and_fct_select(l0,vl,nil,hp,ordering)$
 if null l1 then l:=nil else 
 if check_cases_for_separant(l1) then return l 
 % i.e. dec_one_step pretends to have been successful even if only a
 % case splitting was written in the to_do list, so that to_do is done next
                               else
 if null (l2:=dec_new_equation(l1,nil)) then         
 <<l:=nil;         % e.g. elimin too slow --> err_catch
   add_both_dec_with(ordering,caar l1,caadr l1,nil)$
   cntr:=add1 cntr;
   if cntr<4 then goto again
 >>                                     else 
 if null (l2:=dec_reduction(l2,pdes,ftem,%forg,
                        vl,nil,ordering)) then l:=nil else <<
  l:=pdes;
  if (cadddr l1) and get(cadddr l1,'sqval)=nil then l:=delete(cadddr l1,l)$
  for each a in l2 do if a then <<
   l:=eqinsert(a,l)$
%  % equations which are added and are still to be reduced and still
%  % contain the function to be decoupled shall not be integrated:
%  if null cadddr l1 then <<% no equation was reduced only a new one is added
%   f:=if pairp caddr l1 then cadr caddr l1 % leading deriv. was a deriv
%                        else caddr l1;     % leading deriv. was a function
%   if not freeof(get(a,'fcts),f) then <<
%    remflag1(a,'to_int)$
%    remflag1(a,'to_fullint)
%   >>$
  >>
  % the following breaks the ordering 
  % for each a in l2 do dec_fct_check(a,l)$
 >>$
 stop_let_rules(ruli);
 % if anything has changed then l must be the new pde-list
 return l$
end$

symbolic procedure dec_try_to_red_len(pdes_to_choose_from,vl,ordering)$  
begin scalar l1,l2,l3,p,q,s,cntr$
 cntr:=0$
again:
 l1:=dec_and_fct_select(pdes_to_choose_from,vl,t,nil,ordering)$
 % eg. l1 = ((e_4 (x 2 y) (y z)) 
 %           (e_5 (z) (x 2 y 2)) (df f x 2 y 2 z) nil nil)
 if l1 then <<
  if in_cycle({27,stepcounter_,get(caar l1,'printlength),
              get(caadr l1,'printlength),
              caddr l1,get(cadddr l1,'printlength),
              length get(cadddr l1,'fcts)}) then <<
   add_both_dec_with(ordering,caar l1,caadr l1,t)$
   goto again;
  >>;
  l2:=dec_new_equation(l1,t)$
  % possible length measures to use:
  %    put(equ,'length,pdeweight(val,ftem))$    
  %    put(equ,'printlength,delength val)$
  %    put(equ,'terms,no_of_terms(val))$    
  p:=caar   l1$   % eg. e_4
  q:=caadr  l1$   % eg. e_5
  s:=cadddr l1$   % eg. e_4 or nil
  l3:=union(get(p,'fcts),get(q,'fcts))$
%  if ( no_of_terms(caar l2)   > 
%       get(cadddr l1,'terms)       ) or  % * length_inc
%  disadvantage of 'terms: a big product is one term
  if (null l2) or
     ( pdeweight(caar l2,l3) > 
       get(cadddr l1,'length)        ) or  % * length_inc
%    ((s=p) and may_vanish( cadar l2)) or
%    ((s=q) and may_vanish(caddar l2)) then <<
     ((s=p) and not can_not_become_zeroSQ( cadar l2,l3)) or
     ((s=q) and not can_not_become_zeroSQ(caddar l2,l3)) then <<
   if null l2 then cntr:=add1 cntr;
   l2:=nil;
   add_both_dec_with(ordering,p,q,t);
   last_steps:=cdr last_steps; % last_steps had already been updated
                               % in add_to_last_steps() in in_cycle()
   if cntr<2 then goto again
  >>
 >>;
 return l2
end$

symbolic procedure err_catch_red_len(a1,a2,a3)$        
begin scalar h,bak,kernlist!*bak,kord!*bak,bakup_bak;
 bak:=max_gc_counter$ max_gc_counter:=my_gc_counter+max_gc_red_len;
 kernlist!*bak:=kernlist!*$
 kord!*bak:=kord!*$
 bakup_bak:=backup_;backup_:='max_gc_red_len$
 h:=errorset({'dec_try_to_red_len,mkquote a1,mkquote a2,mkquote a3},nil,nil) 
    where !*protfg=t;
 kernlist!*:=kernlist!*bak$
 kord!*:=kord!*bak;
 erfg!*:=nil; 
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then nil
                    else car h
end$

symbolic procedure dec_and_red_len_one_step(pdes,ftem,%forg, 
                                            vl,ordering)$
% do one length-reducing decouple step for 2 pdes from l, 
% differentiate at most one and replace the other one which must
% become shorter, the one replaced must not be multiplied with a 
% potentially zero factor
begin scalar l,l1,l2,l3,ruli$ %,f$
  l:=pdes;
  if not expert_mode then l1:=l
                     else <<
    l1:=selectpdes(l,2)$
    drop_dec_with(car  l1,cadr l1,t)$
    drop_dec_with(cadr l1,car  l1,t)$
  >>$
  ruli:=start_let_rules()$
again:
  l2:=err_catch_red_len(l1,vl,ordering)$

  if null l2 then return nil;

  if (l3:=dec_reduction(l2,pdes,ftem,%forg,
                        vl,t,ordering)) then <<
   l:=delete(cadr l2,l)$
   for each a in l3 do if a then <<
    l:=eqinsert(a,l)$
%   % equations which are added and are still to be reduced and still
%   % contain the function to be decoupled shall not be integrated:
%   if null cadddr l1 then <<% no equation was reduced only a new one is added
%    f:=if pairp caddr l1 then cadr caddr l1 % leading deriv. was a deriv
%                         else caddr l1;     % leading deriv. was a function
%    if not freeof(get(a,'fcts),f) then <<
%     remflag1(a,'to_int)$
%     remflag1(a,'to_fullint)
%    >>$
%   >>
   >>$
   % the following breaks the ordering 
   % for each a in l3 do dec_fct_check(a,l)$
  >>                                             else 
  <<last_steps:=cdr last_steps;
    if not expert_mode then <<l1:=l;goto again>> 
  >>;
  stop_let_rules(ruli);
  % if anything has changed then l must be the new pde-list
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
% if null setdiff_according_to(get(p,'allvarfcts),get(q,'allvarfcts),ftem_) and
%    null setdiff_according_to(get(q,'allvarfcts),get(p,'allvarfcts),ftem_) and
%    ((length setdiff_according_to(lp,lq,ftem_)+
%      length setdiff_according_to(lq,lp,ftem_) )*100 <
%    (length lp+length lq)*same_fcts) then
%    <<lp:=get(p,'derivs)$
%      lq:=get(q,'derivs)$
%      if (length setdiff(lp,lq)+length setdiff(lq,lp))*100 <
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

%********************************************************************
module resultante$
%********************************************************************
%  Routines for computing the resultant as a list of factors
%  Author: Eberhard Schruefer March 2008
%

% Routines for calculating the resultant using Bezout's method.
% Whenever a row of the Bezout matrix is calculated a common
% factor of the head polynomials is calculated and divided out.
% Then a common factor of each Bezout polynomial and their
% successive exterior product is determined and taken out.
% Before calculating a common factor, a trial divison of previously
% found factors is performed (suggested by Thomas).
% A list of factors of the Resultant with their multiplicities is
% returned. 
% Note that it is not attempted to calculate a factorization
% of the last factor.
% For non square matrices the code still could be improved.

% Author: Eberhard Schruefer, June 2008

% Code status: experimental.

% bresultant returns a list of lists. (The first element is a
% numerical factor). I.e. 
% {{num factor},{factor_1,multiplicity_1},....,{factor_n,multiplicity_n}}


flag('(bresultant),'opfn)$

%-------------------------------
symbolic procedure err_catch_resul(l1,l2,v)$
begin scalar h,bak,bakup_bak$
 bak:=max_gc_counter;max_gc_counter:=my_gc_counter+max_gc_elimin;
 bakup_bak:=backup_;backup_:='max_gc_elimin$
 h:=errorset({'bresultant,mkquote l1,mkquote l2,mkquote v},nil,nil)
    where !*protfg=t;
 erfg!*:=nil; 
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then nil
                    else car h  
end$
%-------------------------------

symbolic procedure comp_resultant(pdes)$
begin scalar s,l,h,ezgcd_bak,rational_bak,gcd_bak$%,bezout_bak;
 l:=selectpdes(pdes,2)$

 if length(s:=get(car  l,'derivs))=1 then <<
  s:=caar s;
  s:=if null cdr s then car s else cons('DF,s);
  if freeof(get(cadr l,'kern),s) then <<
   write"No common kernel in both equations."$terpri()
  >>
 >>                                  else
 if length(s:=get(cadr l,'derivs))=1 then <<
  s:=caar s;
  s:=if null cdr s then car s else cons('DF,s);
  if freeof(get(car l,'kern),s) then <<
   write"No common kernel in both equations."$terpri()
  >>
 >>                                 else <<
  change_prompt_to "Which function/derivative shall be eliminated? "$ 
  s:=termread()$
  restore_interactive_prompt()$
  if freeof(get(car  l,'kern),s) or
     freeof(get(cadr l,'kern),s) then <<
   write"This is not a kernel in both equations."$terpri()
  >>
 >>$

 % The call of the resultant should be put into an call of errorset()
 % on ezgcd$ on gcd$ 
 on bezout$

 if !*rational then <<algebraic off rational;rational_bak:=t>>$
 if !*ezgcd  then  ezgcd_bak:=t else algebraic on  ezgcd$
 if !*gcd    then    gcd_bak:=t else algebraic on    gcd$
% if !*bezout then bezout_bak:=t else algebraic on bezout$
% !*b!:headpolys_red:=t$
 s:=bresultant({'!*SQ,get(car  l,'sqval),nil},
               {'!*SQ,get(cadr l,'sqval),nil},s)$
% s:=err_catch_resul({`!*SQ,get(car  l,'sqval),t},
%                    {`!*SQ,get(cadr l,'sqval),t},s)$
 if null  ezgcd_bak then algebraic off  ezgcd$
 if null    gcd_bak then algebraic off    gcd$
% if null bezout_bak then algebraic off bezout$
 if rational_bak then algebraic on rational$

 s:=for each h in cdr s collect simp!* cadr h;
 s:=mkeqSQ(nil,s,nil,union(get(car l,'fcts),get(cadr l,'fcts)),
           union(get(car l,'vars),get(cadr l,'vars)),allflags_,
           t,list(0),nil,pdes)$

 return eqinsert(s,pdes)
end$

symbolic procedure bresultant(u,v,var)$
   begin scalar x,!*exp;
     !*exp := t;
     u := numr simp!* u;
     v := numr simp!* v;
     var := !*a2k var;
     if domainp u and domainp v
      then return {'list,1};
       kord!* := var . kord!*; 
       if null domainp u and null(mvar u eq var)
	 then u := reorder u;
       if null domainp v and null(mvar v eq var)
	 then v := reorder v;
       x := bezout_resultant_fac(u,v,var);
       setkorder cdr kord!*;
       return x
   end$

symbolic procedure bezout_resultant_fac(u,v,w)$
   % U and v are standard forms. Result is resultant of u and v
   % w.r.t. kernel w. Method is Bezout's determinant using exterior
   % multiplication for its calculation.
   begin integer n,nm; scalar ap,ep,uh,ut,vh,vt,x,cx,cxf,cep,cuh,cvh;
     write "entering bezout."; terpri();
     !*exp := t;
     if domainp u or null(mvar u eq w)
        then return if not domainp v and mvar v eq w
                       then {'list,mk!*sq(exptf(u,ldeg v) ./ 1)}
                     else {'list,1}
      else if domainp v or null(mvar v eq w)
        then return if mvar u eq w then {'list,mk!*sq(exptf(v,ldeg u) ./ 1)} 
                     else {'list,1};
     n := ldeg v - ldeg u;
     cxf := '(1);
     if n < 0 then <<x := u; u := v; v := x; cxf := '(-1); n := -n>>;
     ep := 1;
     nm := ldeg v;
     uh := lc u;
     vh := lc v;
     ut := if n neq 0 then multpf(w to n,red u) else red u;
     vt := red v;
     cx := 1;
     cuh := uh;
     cvh := vh;
     cx := gcdf!*(uh,vh);
     if cx = 1 then <<write "Found trivial factor from headpolys only. "; terpri()>>
      else <<write "Found factor from headpolys with ",termsf cx," terms."; terpri();
             cxf := fctrf cx>>;
     ap := addf(multf(quotf1(uh,cx),vt),negf multf(quotf1(vh,cx),ut));
     x := !*sf2exb(ap,w);
     if cdr cxf then x := b!:try_previous_factors(x,cdr cxf);
     cx := b!:comfac x;
     if cx neq 1 then <<cxf := bfac!-merge(fctrf cx,cxf);
                        write "commom factor cx found. ",tmsf cx," terms."; terpri()>>;
     x := b!:cquot(x,cx);
     ep := b!:extmult(x,ep);
     ep := b!:try_previous_factors(ep,cdr cxf);
     for j := (nm - 1) step -1 until (n + 1) do
        <<if degr(ut,w) = j then
             <<uh := addf(lc ut,multf(!*k2f w,uh));
               if null(cuh = 1 or cvh = 1) then cuh := gcdf!*(lc ut,cuh);
               ut := red ut>>
           else uh := multf(!*k2f w,uh);
          if degr(vt,w) = j then
             <<vh := addf(lc vt,multf(!*k2f w,vh));
               if null(cuh = 1 or cvh = 1) then cvh := gcdf!*(lc vt,cvh);
               vt := red vt>>
           else vh := multf(!*k2f w,vh);
          cx := 1;
          cx := gcdf!*(cuh,cvh); 
          if cx = 1 then <<write "Found trivial factor from headpolys only. "; terpri()>>
           else <<write "Found factor from headpolys with ",termsf cx," terms."; terpri();
                  cxf := bfac!-merge(fctrf cx,cxf)>>;
          x := !*sf2exb(addf(multf(quotf1(uh,cx),vt),
                             negf multf(quotf1(vh,cx),ut)),w);
          x := b!:try_previous_factors(x,cdr cxf);
          cx := b!:comfac x;
          if cx neq 1 then 
             <<write "commom factor cx found. ",tmsf cx," terms."; 
               cxf := bfac!-merge(fctrf cx,cxf);
               terpri()>>;
          x := b!:cquot(x,cx);
          ep := b!:extmult(x,ep);
          ep := b!:try_previous_factors(ep,cdr cxf);
          if j neq 1 then
             <<cep := b!:comfac ep;
               if cep neq 1 then 
                  <<cxf := bfac!-merge(fctrf cep,cxf);
                    write "commom factor cep found. ",tmsf cep," terms."; terpri()>>;
                ep := b!:cquot(ep,cep)>>
                                       >>;
      if n neq 0
         then <<x := !*sf2exb(u,w);
                cx := b!:comfac x;
                if cx neq 1 then 
                   <<write "commom factor cx found.",tmsf cx," terms"; terpri();
                     cxf := bfac!-merge(fctrf cx,cxf)>>;
                x := b!:cquot(x,cx);
                ep := b!:extmult(x,ep);
          cep := b!:comfac ep;
          if cep neq 1 then 
             <<write "commom factor cep found. ",tmsf cep," terms."; terpri();
               cxf := bfac!-merge(fctrf cep,cxf)>>;
          ep := b!:cquot(ep,cep);
                for j := 1:(n-1) do
                  <<x := !*sf2exb(multpf(w to j,u),w);
                    cx := b!:comfac x;
                    if cx neq 1 then 
                       <<write "commom factor cx found. ",tmsf cx," terms."; terpri();
                         cxf := bfac!-merge(fctrf cx,cxf)>>;
                    x := b!:cquot(x,cx);
                    ep := b!:extmult(x,ep);
                    cep := b!:comfac ep;
                    if cep neq 1 then 
                       <<cxf := bfac!-merge(fctrf cep,cxf);
                         write "commom factor cep found. ",tmsf cep," terms."; terpri()>>;
                    ep := b!:cquot(ep,cep);
                    >>>>; 
      return if null ep then {'list,0} 
              else if domainp lc ep
                then 'list . {'list,multf(car cxf,lc ep)} .
                               for each j in cdr cxf 
                                   collect {'list,mk!*sq(car j ./ 1),cdr j}
              else 'list . {'list,car cxf} . {'list,mk!*sq(lc ep ./ 1),1} . 
                    for each j in cdr cxf collect {'list,mk!*sq(car j ./ 1),cdr j}
   end$

symbolic procedure b!:comfac u$
   begin scalar !*ezgcd,x;
     write "entered comfac."; terpri();
     !*ezgcd := t;
     if null u then return 1;
     x := lc u;
     a: u := red u;
        if null u then <<write "left comfac."; terpri(); return x>>;
        x := gcdf!*(lc u,x);
        go to a
   end$

symbolic procedure b!:cquot(u,v)$
   if null u then nil
    else lpow u .* quotf1(lc u,v) .+ b!:cquot(red u,v)$

symbolic procedure b!:try_previous_factors(u,v)$
   begin scalar x;
     b: x := b!:ctrialdiv(u,caar v);
        if null x then go to a;
        write "successful trial div. "; terpri();
        u := x;
        rplacd(car v,cdar v + 1);
        go to b;
     a: v := cdr v;
        if null v then return u;
        go to b
   end$

symbolic procedure b!:ctrialdiv(u,v)$
   begin scalar res,w,x;
     if domainp u then return quotf1(u,v);
     if x := quotf1(lc u,v) then res := w := lpow u .* x .+ nil
      else return nil;
     a: u := red u;
        if null u then return res;
        if domainp u then if x := quotf1(u,v) then <<rplacd(w,x); return res>>
                           else return nil;
        if x := quotf1(lc u,v) then rplacd(w,lpow u .* x .+ nil)
         else return nil;
        w := red w;
       go to a;
   end$

symbolic procedure bfac!-merge(u,v)$
   if null cdr v then multf(car u,car v) . cdr u 
    else multf(car u,car v) . bfac!-merge2(cdr u,cdr v)$

symbolic procedure bfac!-merge2(u,v)$
   begin scalar x,y,r;
     if null u then return v;
     c: x := car u;
        y := v;
     b: if car x = caar y 
           then <<rplacd(car y,cdar y + cdr x);
                  go to a>>;
        y := cdr y;
        if y then go to b;
        r := x . r;
     a: u := cdr u;
        if null u then return append(v,r);
        go to c;
   end$

endmodule$

end$

----------------------------
decoupling 
  dec_one_step
    dec_and_fct_select
      dec_info
        dec_ld_info
    check_cases_for_separant
      can_not_become_zeroSQ
    dec_new_equation
      can_not_become_zeroSQ
      coeff1
      err_catch_elimin
        elimin
        err_catch_gcd
    dec_reduction
      mkeqSQ
    eqinsert
------------------------------------------------
tr decoupling
tr dec_one_step
tr dec_and_fct_select
tr dec_info
tr dec_ld_info
tr check_cases_for_separant
tr can_not_become_zeroSQ
tr dec_new_equation
tr err_catch_elimin
tr elimin
tr err_catch_gcd
tr dec_reduction
tr mkeqSQ
tr eqinsert
tr dec_try_to_red_len
