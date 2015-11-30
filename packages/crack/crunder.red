%********************************************************************
module underdetde$
%********************************************************************
%  Routines for the solution of underdetermined ODEs and PDEs
%  Author: Thomas Wolf
%  August 1998, since February 1999

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

symbolic procedure undetalg(arglist)$
% parametric solution of single underdetermined algebraic equations
% checking whether there is one equation with 2 functions with at least 
% 2 terms of degree at least 2 but with as low as possible max degree
% of any function.
begin scalar pdes,forg,l,l1,p,h,f1,f2,f3,f4,f5$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then <<l1:=selectpdes(pdes,1);flag(l1,'to_under)>>
                else l1:=cadddr arglist$

 % We have different tests and procedures to apply, each relying on the
 % equation being rather special. We therefore just check each equation one 
 % by one, concerning all tests not searching for the most promising equation 
 % for one method before trying the other method. The purpose is to be able to
 % to have only one flag 'to_under which includes all these tests.

 while l1 and null l do 
 if null flagp(car l1,'to_under) and 
    (get(car l1,'nvars)=0) then l1:=cdr l1 
                           else <<
  p:=car l1; l1:=cdr l1;
  remflag1(p,'to_under)$

  % Currently both methods require that the equation is a polynomial
  % in 2 unknowns with more than one term
  h:=get(p,'fcts);
  if (get(p,'terms)>1) and 
     (null get(p,'nonrational)) and 
     cdr h and 
     null cddr h then << % polynomial in exactly 2 unknowns else done
   f1:=car h;
   f2:=cadr h;
   f3:=nil; f4:=nil; f5:=nil;
   
   % Currently for both methods the equation needs to be at least
   % quadratic for each unknown

   h:=get(p,'derivs);
   while h do <<
    if cdar h > 1 then f3:=union(list caaar h,f3);
    if cdar h = 2 then f4:=union(list caaar h,f4) else 
    if cdar h > 2 then f5:=union(list caaar h,f5); 
    h:=cdr h
   >>;

   % 1. Test whether the equation is a polynomial in one variable
   %    which itself is a polynomial in more than one variable.

   if member(f1,f3) and member(f2,f3) then l:=tryalg1(p,pdes);

   % 2. Test whether the equation is itself quadratic and quadratic
   %    in each unknown to compute a complete parametric solution.

   if null l and null f5 and 
      member(f1,f4) and member(f2,f4) then l:=tryalg2(p,pdes)
  >>
 >>;
 if null l then return nil;

 if print_ then <<
  write"Parametric solution of the 'underdetermined' algebraic equation ",p$
  terpri();
  write"giving the new algebraic equation(s) "$
  listprint l;
  terpri()
 >>$
 for each h in l do <<
  pdes:=eqinsert(h,pdes)$
  if member(h,pdes) then 
  to_do_list:=cons(list('subst_level_4,list h),to_do_list)$
 >>$

 return list(pdes,forg)
end$


symbolic procedure tryalg1(p,pdes)$
begin scalar f1,f2,f1d,f2d,d1,d2,gd,phi,newf,q$

 f2:=get(p,'fcts); 
 f1:=car f2;  f1d:=mvar car mksq(f1,1);
 f2:=cadr f2; f2d:=mvar car mksq(f2,1);

 d1:=diffsq(get(p,'sqval),f1d);  
 d2:=diffsq(get(p,'sqval),f2d);  

 gd:=err_catch_gcd({'!*sq,d1,t},{'!*sq,d2,t});

 return
 if freeof(gd,f1) or freeof(gd,f2) then nil 
                                   else <<
  d1:=quotsq(d1,cadr gd);
  d2:=quotsq(d2,cadr gd);
   
  if not sqzerop subtrsq(diffsq(d1,f2d),diffsq(d2,f1d)) then nil
                                                        else <<
   phi:=simp reval list('int,prepsq d1,f1)$
   phi:=addsq(phi,simp reval list('int,prepsq subtrsq(d2,diffsq(phi,f2d)),f2));
   newf:=newfct(fname_,nil,nfct_)$
   nfct_:=add1 nfct_;
   ftem_:=fctinsert(newf,ftem_)$
   q:=mkeqsq(subtrsq(simp newf,phi),nil,nil,{newf,f1,f2},nil,allflags_,nil,
             list(0),nil,pdes);
   put(q,'not_to_eval,{newf})$
   {q}
  >>
 >>
end$


symbolic procedure tryalg2(p,pdes)$
begin scalar h,f1,f2,f3,s,k,l,d,q$

 h:=get(p,'fcts);
 f1:=car h;
 f2:=cadr h;

 % Is the whole equation only 2nd degree?
 s:=gensym()$
 k:=setkorder {s}$
 h:=simp!* {'!*sq,subsq(get(p,'sqval),
		        {(f1 . {'times,f1,s}), 
			 (f2 . {'times,f2,s}) }),nil}$
 setkorder k$

 return
 if (mvar numr h neq s) or
    (ldeg numr h neq 2) then nil
                        else << % the equation is of 2nd degree
  h:=mksq(lc numr h,1);         % the sum of the quadratic terms
  d:=solveeval list({'!*sq,h,t},f1);

  if not freeof(d,'abs) then <<
   algebraic (let abs_);
   d:=algebraic lisp d;
   algebraic(clearrules abs_);
  >>$

  l:=nil;
  if d and (car d='list) then for each h in cdr d do <<
   % i.e. for each of the two equalities f1=.., f1=..

   f3:=newfct(fname_,get(p,'vars),nfct_)$
   nfct_:=add1 nfct_$
   ftem_:=fctinsert(f3,ftem_)$ 

   % currently h={'equal,f1,rhs}
   q:=mkeqsq(addsq(simp f3,subtrsq(simp cadr h,simp caddr h)),nil,nil,
	     {f1,f2,f3},get(p,'vars),allflags_,t,list(0),nil,pdes)$
   put(q,'not_to_eval,{f3})$
   l:=cons(q,l)
  >>;

  l
 >>
end$


symbolic procedure undetlinode(arglist)$
% parametric solution of underdetermined ODEs
begin scalar l,l1,p,pdes,forg,s$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then <<l1:=selectpdes(pdes,1);flag(l1,'to_under)>>
                else l1:=cadddr arglist$
 while l1 do 
 if null (p:=get_ulode(l1)) then l1:=nil
                            else <<
  l:=underode(p,pdes)$
  p:=car p$
  if null l then <<remflag1(p,'to_under);l1:=delete(p,l1)>>
            else <<
   if print_ then <<
    write"Parametric solution of the underdetermined ODE ",p$
    terpri();
    write"giving the new ODEs "$
    s:=l;
    while s do <<
     write car s;
     s:=cdr s;
     if s then write ","
    >>$
    terpri()
   >>$
   pdes:=drop_pde(p,pdes,nil)$
   for each s in l do pdes:=eqinsert(s,pdes)$
   l:=list(pdes,forg)$
   l1:=nil;
  >>
 >>$
 return l$
end$

symbolic procedure undetlinpde(arglist)$
% parametric solution of underdetermined PDEs
begin scalar l,l1,p,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then <<l1:=selectpdes(pdes,1);flag(l1,'to_under)>>
                else l1:=cadddr arglist$
 while l1 do 
 if null (p:=get_ulpde(l1)) then l1:=nil
                            else <<
  l:=underpde(p,pdes)$  % l has to be the list of new pdes
  p:=car p$        
  if null l then <<remflag1(p,'to_under);l1:=delete(p,l1)>>
            else <<
   pdes:=drop_pde(p,pdes,nil)$
   for each s in l do pdes:=eqinsert(s,pdes)$
   l:=list(pdes,forg)$
   l1:=nil;
  >>
 >>$
 return l$
end$

%symbolic procedure get_udalg(pdes)$
%% It looks for an algebraic equation (no independent variables) with as 
%% low as possible maximum degree of any variable but at least
%begin scalar h,best_udalg;
% for each p in pdes do
% if flagp(p,'to_under) and (get(p,'nvars)=0) then
% if null (h:=udalgp(p)) then remflag1(p,'to_under)
%                        else
% if ((null best_udalg) or (car h < car best_udalg)) then best_udalg:=h;
% return if best_udalg then cdr best_udalg % return the name of the equation
%                      else nil
%end$

symbolic procedure get_ulode(pdes)$
begin scalar h,best_ulode;
 for each p in pdes do
 if flagp(p,'to_under) % and (get(p,'nvars)=1) 
 then
 if null (h:=ulodep(p)) then remflag1(p,'to_under)
                        else
 if ((null best_ulode) or (car h < car best_ulode)) then best_ulode:=h;
 return if best_ulode then cdr best_ulode
                      else nil
end$

symbolic procedure get_ulpde(pdes)$
begin scalar h,best_ulpde;
 for each p in pdes do
 if flagp(p,'to_under) and (get(p,'nvars)>1) then
 if null (h:=ulpdep(p)) then remflag1(p,'to_under)
                        else
 if ((null best_ulpde) or (car h < car best_ulpde)) then best_ulpde:=h; 
 return if best_ulpde then cdr best_ulpde
                      else nil
end$

symbolic procedure udalgp(p)$
if (get(p,'terms)<2) or 
   get(p,'nonrational) or 
   ((length get(p,'fcts)) neq 2) then nil else 
begin scalar mxdeg,dfs$
 mxdeg:=0$
 dfs:=get(p,'derivs)$
 while dfs do <<
  if cdar dfs>mxdeg then mxdeg:=cdar dfs;
  dfs:=cdr dfs
 >>;
 return if mxdeg<2 then nil
                   else (mxdeg . p)
end$

symbolic procedure ulodep(p)$
begin
 scalar tr_ulode,drvs,ulode,allvarf,minord,dv,f,x,h,found,minordf,totalorder$
 % minord and minordf are currently not needed later on

% tr_ulode:=t;

 % Is it an underdetermined linear ODE for the allvarfcts?
 drvs:=get(p,'derivs)$
 ulode:=t$
 allvarf:=get(p,'allvarfcts);
 if tr_ulode then <<
  write"allvarf=",allvarf$
  terpri()$
 >>$

 minord:=1000;
 if not (allvarf and cdr allvarf) then ulode:=nil
                                  else % at least two allvar-fcts
 while ulode and drvs do <<
  dv:=caar drvs;
  f:=car dv$
  if tr_ulode then <<
   write"car drvs=",car drvs,"  dv=",dv,"  f=",f,
        "  member(f,allvarf)=",member(f,allvarf)$
   terpri()$
  >>$
  if member(f,allvarf) then
  if (cdar drvs neq 1) or % not linear
                          % x is already determined and it is not x:
     (cdr dv and ((x and (x neq cadr dv)                  ) or
                          % there are other differentiation variables:
                  ((cddr dv) and ((not fixp caddr dv) or
                                  cdddr dv               ))    )
     ) then <<            % no ODE:
   ulode:=nil;
   if tr_ulode then <<
    write"new ulode=",ulode$
    terpri()$
   >>$
  >>   else               % can be an ODE
  if null cdr dv then     % f has no derivatives
  if not member(f,found) then ulode:=nil % no ODE --> substitition
                         else % f has already been found with a
                              % consequently higher x-derivative
                 else     % this is an x-derivative of f
  if null x then <<       % x had not yet been determined
   if tr_ulode then <<
    write"null x"$
    terpri()$
   >>$
   found:=cons(f,found)$
   x:=cadr dv;
   minordf:=car dv;
   if null cddr dv then minord:=1
                   else minord:=caddr dv;
   totalorder:=minord
  >>        else                  % x has already been determined
  if not member(f,found) then <<  % only leading derivatives matter
   found:=cons(f,found)$          % and the first deriv. of f is leading
   if null cddr dv then h:=1
                   else h:=caddr dv;
   totalorder:=totalorder+h;
   if h<minord then <<
    minord:=h;
    minordf:=car dv
   >>          
  >>                     else
                       else % not member(f,allvarf)
  if null x or              % then there are only derivatives
                            % of non-allvarfcts left
     member(x,fctargs f) then ulode:=nil; % no x-dependent non-allvarfcts
  if tr_ulode then <<
   write"found=",found,"  minord=",minord,"  minordf=",minordf$
   terpri()$
  >>$

  drvs:=cdr drvs;
 >>$
 if ulode and null get(p,'linear_) and null lin_check_sq(get(p,'sqval),get(p,'allvarfcts))
 then ulode:=nil$

 if tr_ulode then <<
  write"ulode=",ulode$
  terpri()$
 >>$
 return if ulode then {totalorder,p,x,minord,minordf}
                 else nil
end$ % of ulodep

symbolic procedure ulpdep_(p)$
begin
 scalar tr_ulpde,drvs,drv,ulpde,allvarf,allvarfcop,
        vld,vl,v,pdo,fn,f,no_of_drvs,no_of_tms,ordr,maxordr,parti$
%tr_ulpde:=t;

 % Is it an underdetermined linear PDE for the allvarfcts?
 drvs:=get(p,'derivs)$
 ulpde:=t$
 allvarf:=get(p,'allvarfcts);
 if tr_ulpde then <<
  write"allvarf=",allvarf$
  terpri()$
 >>$

 if not (allvarf and cdr allvarf) then ulpde:=nil
                                  else << % at least two allvar-fcts
  allvarfcop:=allvarf$
  no_of_tms:=0; % total number of terms of all diff operators
  vl:=get(p,'vars)$
  
  while ulpde and allvarfcop do <<
   % extracting the differential operator for car allvarfcop
   pdo:=get(p,'sqval);

   fn:=car allvarfcop;     allvarfcop:=cdr allvarfcop;
   for each f in allvarf do 
   if f neq fn then pdo:=subsq(pdo,{(f . 0)});

   % Is pdo linear in fn?
   if not lin_check_sq(pdo,{fn}) then <<
    if tr_ulpde then <<write"not linear in ",f$terpri()>>$
    ulpde:=nil
   >>                            else <<
    % add up the number of terms
    no_of_tms:=no_of_tms + no_of_tm_sf numr pdo$

    % What are all variables in pdo? This is needed to test later
    % whether they are disjunct from all variables from another 
    % diff. operator
    vld:=nil;
    for each v in vl do if not freeof(pdo,v) then vld:=cons(v,vld);

    % What is the number of derivatives of fn?
    % What order is the highest derivative of fn?
    no_of_drvs:=0;
    for each drv in drvs do 
    if fn=caar drv then <<
     ordr:=absodeg(cdar drv);
     if (no_of_drvs=0) or (ordr>maxordr) then maxordr:=ordr;
     no_of_drvs:=add1 no_of_drvs;
    >>;

    % collect the differential operators with properties in parti
    parti:=cons({pdo,fn,vld,no_of_drvs,maxordr},parti);
    % commutativity of differential operators
   >>
  >>;
  if no_of_tms neq get(p,'terms) then <<
   if tr_ulpde then <<
    write"not a lin. homog. PDE"$terpri()
   >>$
   ulpde:=nil; % not a lin. homog. PDE
  >>$
  if tr_ulpde then <<
   write"parti="$
   prettyprint parti$
  >>$
 >>$
 return if null ulpde then nil 
                      else parti
end$

 
symbolic procedure ulpdep(p)$
begin
 scalar tr_ulpde,drvs,drv,ulpde,parti,pde,
        difop1,difop2,commu,disjn,totalcost$
%tr_ulpde:=t;
 % Is it an underdetermined linear PDE for the allvarfcts?
 drvs:=get(p,'derivs)$
 ulpde:=ulpdep_(p)$
 if ulpde then <<
  parti:=ulpde$ ulpde:=t$
  % Find a differential operator pde in parti
  pde:=nil;
  for each difop1 in parti do <<
   commu:=t;
   % which does commute with all other diff. operators
   for each difop2 in parti do
   if (cadr difop1 neq cadr difop2) and
      not sqzerop 
          subtrsq(      subsq(car difop2,{(cadr difop2 . {'!*sq,car difop1,t})}),
                  subsq(subsq(car difop1,{(cadr difop1 . {'!*sq,car difop2,t})}),
                        {(cadr difop2 . cadr difop1)}   
                       ))        % if car()<>nil then ()<>0
   then <<
    commu:=nil;
    if tr_ulpde then <<
     write"no commutation of:"$terpri()$
     prettyprint difop1$
     write"and "$terpri()$
     prettyprint difop2
    >>
   >>$
   % and is variable-disjunct with at least one other diff. operator
   if commu then <<
    disjn:=nil;
    for each difop2 in parti do
    if (cadr difop1 neq cadr difop2) and 
       freeoflist(caddr difop1,caddr difop2) then disjn:=t;
    if disjn then 
    if null pde then pde:=difop1 else
    if (  car cddddr difop1) < (car cddddr pde) or   % minimal maxord
       (((car cddddr difop1) = (car cddddr pde)) and % minimal number of terms
        ((cadddr difop1) < (cadddr pde))             ) then pde:=difop1
   >>
  >>;
  if null pde then ulpde:=nil
 >>;

 if tr_ulpde then <<
  write"ulpde=",ulpde$
  terpri()$
 >>$
 % as a first try we take as cost for the PDE p the sum of all orders
 % of all derivatives of all functions in p
 totalcost:=0;
 for each drv in drvs do totalcost:=totalcost+absodeg(cdar drv);

 return if ulpde then {totalcost,p,pde,parti}
                 else nil
end$ % of ulpdep

symbolic procedure min_ord_f(ode,allvarf,vl)$
begin scalar minord,minordf,newallvarf,f,h,tr_ulode$
% tr_ulode:=t;
 % does any function not occur anymore? 
 % Which function does occur with lowest derivative: minord, minordf?
 minord:=1000;
 minordf:=nil;
 newallvarf:=nil;
 for each f in allvarf do <<
  h:=ld_deriv_search(ode,f,vl)$
  if tr_ulode then <<
   write"ld_deriv_search(",f,")=",h$
   terpri()$
  >>$
  if not zerop cdr h then <<  % otherwise f does not occur anymore in ode
   newallvarf:=cons(f,newallvarf)$
   h:=car h$
   h:=if null h then 0 else
      if null cdr h then 1 else cadr h$ % asuming that car h = x
   if h<minord then <<minord:=h;minordf:=f>>
  >>
 >>$
 return {minord,minordf,newallvarf}
end$

symbolic procedure underode(pchar,pdes)$
% pchar has the form {p,x,minord,minordf}
begin
 scalar tr_ulode,p,x,allvarf,orgallvarf,ode,vl,%noallvarf,
        minord,minordf,adj,f,h,newf,sol,sublist,rtnlist,
        freeint_bak,freeabs_bak$

% tr_ulode:=t;

 p      :=car pchar;
 x      :=cadr pchar;
 minord :=caddr pchar;
 minordf:=cadddr pchar;

 allvarf:=get(p,'allvarfcts);
 orgallvarf:=allvarf;
 freeint_bak:=freeint_; freeint_:=nil; % to avoid intpde()=>nil
 freeabs_bak:=freeabs_; freeabs_:=nil; %           "

%ode:=get(p,'val);
 cp_sq2p_val(p)$
 ode:=get(p,'pval);
 %noallvarf:=length(allvarf);
 vl:=get(p,'vars);
 while (minord>0) and 
       % (length(allvarf)=noallvarf) 
       (length(allvarf) > 1) 
 do <<
  if tr_ulode then <<
   write "x=",x,"  minord=",minord,"  minordf=",minordf,
         "  allvarf=", allvarf$ 
   terpri()$
  >>$
  repeat <<
   adj:=intpde(ode,allvarf,vl,x,t);
   if tr_ulode then <<
    write"car adj = new_function = "$mathprint car adj$
    write"cadr adj = - df(new_function,",x,")="$mathprint cadr adj$ % #?#
    terpri()$
   >>$

   h:=nil;
   for each f in allvarf do if not freeof(cadr adj,f) then h:=cons(f,h);
   if null h then  % exact ode --> should do better then what is done now
   ode:=reval {'times,x,ode};
  >> until h;

  minordf:=cadr min_ord_f(ode,h,vl)$

  % a new function (potential) is needed:
  newf:=newfct(fname_,vl,nfct_)$
  nfct_:=add1 nfct_;

  if tr_ulode then <<
   algebraic write"eqn=",{'list,{'plus,{'df,newf,x},lisp cadr adj}}$
   algebraic write"var=",{'list,minordf                      }
  >>$
  sol:=cadr solveeval list({'list,{'plus,{'df,newf,x},cadr adj}},
                           {'list,minordf                      } );
  allvarf:=delete(minordf,allvarf)$
  allvarf:=cons(newf,allvarf)$
  % assuming that there is exacly one solution to the lin. alg. equation
  if tr_ulode then <<
   terpri()$
   write"sol=",sol$
   terpri()$
  >>$
  sublist:=cons(sol,sublist)$
  ode:=reval num reval 
       {'plus,newf,{'minus,subst(caddr sol,cadr sol,car adj)}}$
  if tr_ulode then algebraic(write"ode=",ode)$

  h:=min_ord_f(ode,allvarf,vl)$
  minord:=car h; minordf:=cadr h; allvarf:=caddr h;

  if minord=0 then 
  sublist:=cons(cadr solveeval list({'list,ode},{'list,minordf}),sublist)$

  if tr_ulode then <<
   write"allvarf=",allvarf,"  minord=",minord,"  minordf=",minordf$
   terpri()$
  >>$

 >>$

 if (minord neq 0) and (not zerop ode) then rtnlist:=list ode;
 ode:=nil;
 if tr_ulode then <<write"rtnlist=", rtnlist;terpri()>>$
 if tr_ulode then algebraic(write"sublist=",cons('list,sublist));
 while sublist do <<
  if member(cadar sublist,orgallvarf) then 
  rtnlist:=cons(reval num reval {'plus,cadar sublist,
                                 {'minus,caddar sublist}},rtnlist)$
  sublist:=cdr reval cons('list,
                          subst(caddar sublist,cadar sublist,cdr sublist))$
  if tr_ulode then algebraic(write"sublist=",cons('list,sublist))
 >>$

 allvarf:=smemberl(allvarf,rtnlist)$
 if tr_ulode then <<
  write"allvarf=",allvarf$
  terpri()$
 >>$
 for each h in allvarf do <<
  ftem_:=fctinsert(h,ftem_)$
  flin_:=sort_according_to(cons(h,flin_),ftem_)
 >>$
 if tr_ulode then algebraic(write"rtnlist=",cons('list,rtnlist));
 h:=for each h in rtnlist collect
    mkeqsq(nil,nil,h,union(get(p,'fcts),allvarf),vl,allflags_,t,
           list(0),nil,pdes)$
 if print_ then terpri()$
 freeint_:=freeint_bak;
 freeabs_:=freeabs_bak;
 return h
end$

symbolic procedure underpde(pchar,pdes)$
% pchar has the form {p,difop,parti} where p is the name of the equation, 
% difop is the main differential operator in p and parti is a partition
% of p, i.e. the list of all differential operators. Each differential
% operator has the form
%  {pde,fn,vld,no_of_drvs,maxordr}
% where pde are all terms in p with fn, vld is a list of all variables
% in pde, no_of_dervs is the number of different derivatives of fn, 
% maxord is the maximal order of derivatives of fn (order of pde)

begin
 scalar tr_ulpde,ldo,parti,fn,lcond,difop,h,fl,eqlist,vl$
% has to return list of new pde just like in underode
% tr_ulpde:=t;
 ldo:=cadr pchar;
 parti:=caddr pchar$
 vl:=get(car pchar,'vars)$
 fn:=cadr ldo$
 lcond:={fn}$
 if tr_ulpde then <<
  write"ldo="$prettyprint parti$
  write"parti="$prettyprint parti
 >>$
 for each difop in parti do
 if cadr difop neq fn then <<
  h:=newfct(fname_,vl,nfct_)$
  nfct_:=add1 nfct_$
  if print_ then terpri()$
  fl:=cons(h,fl)$
  eqlist:=cons(cons({cadr difop,h}, 
                    reval {'difference,cadr difop,subst(h,fn,prepsq car ldo)}),
               eqlist)$
  lcond:=cons(subst(h,cadr difop,prepsq car difop),lcond)
 >>$
 eqlist:=cons(cons(append(get(car pchar,'fcts),fl),
                   cons('plus,lcond)),eqlist)$
 if tr_ulpde then <<
  write"eqlist="$prettyprint eqlist$
 >>$

 for each h in fl do <<
  ftem_:=fctinsert(h,ftem_)$
  flin_:=sort_according_to(cons(h,flin_),ftem_)
 >>$
 h:=for each h in eqlist collect 
 mkeqsq(nil,nil,cdr h,car h,get(car pchar,'vars),allflags_,
        t,list(0),nil,pdes)$
 if print_ then terpri()$
 return h
end$

endmodule$

end$

tr undetalg
tr tryalg1
tr tryalg2
tr undetlinode
tr undetlinpde
tr get_udalg
tr get_ulode
tr get_ulpde
tr udalgp
tr ulodep
tr ulpdep_
tr ulpdep
tr min_ord_f
tr underode
tr underpde
