%********************************************************************
module transform$
%********************************************************************
%  Routines for performing transformations
%  Author: Thomas Wolf
%  March 1999
%

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

symbolic procedure Input_Trafo(pdes)$
begin scalar ulist,vlist,u,v,ylist,xlist,yslist,xslist,xl2,
             notallowed,full_simplify,singul,h,vl_bak,yplist,xplist$
 change_prompt_to ""$ 

 for each h in pdes do <<
  yplist:=union(get(h,'fcts),yplist);
  xplist:=union(get(h,'vars),xplist)
 >>;

 write"Under the following conditions this program performs arbitrary"$
 terpri()$
 write"transformations."$
 terpri()$terpri()$

 write"If not only variables but also functions are transformed then it"$
 terpri()$
 write"is assumed that all new functions depend on the same new variables"$
 terpri()$
 write"and that all old functions depend on the same old variables."$
 terpri()$ terpri()$

 write"For these procedures to be applicable the old functions and variables"$
 terpri()$
 write"must be given in terms of the new ones explicitly, i.e. not involving"$
 terpri()$
 write"unspecified functions of the new ones. Also, the differential "$
 terpri()$
 write"equations to be transformed must contain the old independent and"$ 
 terpri()$
 write"dependent variables and their partial derivatives explicitly."$
 terpri()$
 terpri()$
 write"The old (i.e. current) list of functions is "$ terpri()$
 fctprint_SQ(yplist)$ terpri()$
 write"and the list of old (i.e. current) variables is "$ terpri()$
 fctprint(xplist)$terpri()$

% write"Hint: Splitting a single transformation involving many"$
% terpri()$
% write"variables into many transformations involving each only few"$
% terpri()$
% write"variables speeds the whole transformation up."$
% terpri()$

 terpri()$
 write"Give a list of new functions (i.e. dependent variables), "$
 terpri()$
 write"e.g. `u1,u2,u3;' in the order to be used to sort dervatives. "$
 terpri()$
 write"Use new function names which have not been used before in this"$
 terpri()$
 write"computation. If there are no new functions enter ;"$
 terpri()$

% write"The current total list of functions (not necessarily all still appearing"$
% terpri()$
% write"in the remaining equations) and the independent variables (also"$
% terpri()$
% write"not necessarily all still appearing in the remaining equations) are:"$
% terpri()$
% print_forg(ftem_,vl_);

 repeat <<
  ulist := termlistread()$
  h:=ulist;
  if h then
  if (length ulist) neq (length yplist) then <<
   write"If you specify new functions then you need as many as ",length yplist,"."$
   terpri()$
   write"Please try again."$
   terpri()
  >>                                           else <<
   while h and atom car h and freeof(done_trafo,car h) and 
               freeof(ftem_,car h) and freeof(vl_,car h) do h:=cdr h;
   if h then <<
    if not atom car h then 
    write"The function ",car h," is not an identifier."
                      else 
    write"The function name ",car h," is already in use."$terpri()$ 
    write"Please try again and choose a different function name."$
    terpri()
   >>   else <<
    h:=ulist;
    while h and freeof(cdr h,car h) do h:=cdr h;
    if h then <<
     write"The function ",car h," is listed more than once. Please try again."$
     terpri()
    >>
   >>
  >>
 >> until null h$

 terpri()$
 write"Give a list of all new variables (i.e. independent variables), "$
 terpri()$
 write"e.g. 'v1,v2,v3;' in the order to be used to sort derivatives."$
 terpri()$
 write"If there are no new variables enter ;"$
 terpri()$
 repeat <<
  vlist := termlistread()$
  h:=vlist;
  if h then
  if (length vlist) neq (length xplist) then <<
   write"If you specify new variables then you need as many as ",length xplist,"."$
   terpri()$
   write"Please try again."$
   terpri()
  >>                                         else <<
  while h and atom car h and freeof(done_trafo,car h) and 
               freeof(ftem_,car h) and freeof(vl_,car h) do h:=cdr h;
   if h then <<
    if not atom car h then 
    write"The variable ",car h," is not an identifier."
                      else 
    write"The variable name ",car h," is already in use."$
    terpri()$ 
    write"Please try again and choose a different variable name."$
    terpri()
   >>   else <<
    h:=vlist;
    while h and freeof(cdr h,car h) do h:=cdr h;
    if h then <<
     write"The function ",car h," is listed more than once. Please try again."$
     terpri()
    >>
   >>
  >>
 >> until null h$

 vl_bak:=vl_;
 vl_:=union(vl_,vlist);  % for the zero_den() test

 if ulist then <<
  for each u in ulist do
  if vlist then for each v in vlist do depend u,v 
           else for each v in vl_   do depend u,v$

  terpri()$
  write"Give a list of all substitutions of old functions in terms of"$
  terpri()$
  write"new functions and new variables, e.g. y1=2*u1+u2*v2, y2=u2-u1*v1;"$
  terpri()$
  write"If there are no substitutions of old functions enter ;"$
  terpri()$
  yslist := termlistread()$

  % Check whether all old functions do depend on the same variables
  ylist:=for each u in yslist collect cadr u$
  xlist:=fctargs car ylist$
  for each u in cdr ylist do <<
   xl2:=fctargs u$
   if not_included(xlist,xl2) or
      not_included(xl2,xlist) then <<
    notallowed:=t$
    terpri()$
    write"Functions ",car ylist,",",u," do not depend on the same variables!"$ 
   >>
  >>;

  % Check for possible singularities of the rhs's
  for each u in yslist do 
  if (v:=zero_den(reval caddr u,union(ftem_,ulist))) then 
  singul:=union(v,singul)$
 >>$

 if notallowed then return nil;
 
 if vlist then <<
  terpri()$
  write"Give a list of all substitutions of old variables in terms of"$
  terpri()$
  write"new functions and new variables, e.g. x1=v1-v2*u2, x2=3*v2+v1*u1;"$
  terpri()$
  xslist := termlistread()$

  % Check for possible singularities of the rhs's
  for each u in xslist do 
  if (v:=zero_den(reval caddr u,union(ftem_,ulist))) then 
  singul:=union(v,singul)$

  % Check that only old variables are on lhs's and only new variables are on rhs's:
  if (length vlist) neq (length xslist) then <<
   write"The number of substitutions is not ",length vlist$
   notallowed:=t;
  >>$

  xlist:=for each v in xslist collect cadr v$

%  write"vlist = ",vlist$terpri()$
%  write"xlist = ",xlist$terpri()$
%  write"xplist = ",xplist$terpri()$
%  write"xslist = ",xslist$terpri()$

  if not_included(xplist,xlist) or 
     not_included(xlist,xplist) then <<
   write"The set of left hand side variables is not the set of old variables."$
   notallowed:=t;
  >>$

  for each v in xslist do 
  if not freeoflist(caddr v,xlist) then <<
   write"A right hand side involves old variables."$
   notallowed:=t;
  >>
 >>$

 if notallowed then return nil;

 vl_:=vl_bak$

 if singul then <<
  terpri()$
  write"The right hand sides of transformations may become singular."$
  terpri()$
  write"Therefore the following expressions are assumed to be non-zero"$
  terpri()$
  write"from now on:"$
  for each u in singul do <<ineq_:=cons(u,ineq_);
   mathprint {'!*SQ,u,nil}
  >>
 >>$

 terpri()$
 write"Shall the transformed equation be fully simplified,"$
 terpri()$
 write"i.e. redundand non-vanishing factors be dropped y/n : "$
 full_simplify:=termread()$
 if (full_simplify='n) then full_simplify:=nil;
 terpri()$

 % Dependence of the new dependent variables on old independent variables
 % which are not transformed
 for each v in xslist do xlist:=setdiff(xlist,list cadr v);
 for each u in ulist do
 for each v in xlist do depend u,v$

 % Also non-changing old variables must enter the transformation as
 % partial derivatives wrt them will have a different meaning
 vlist:=append(vlist,xlist)$
 for each v in xlist do xslist:=cons({'EQUAL,v,v},xslist)$

 % If a test is necessary that all old variables are replaced then do
 % if (not not_included(ftem_,newli)) and 
 %    (not not_included(newli,ftem_)) then 
 restore_interactive_prompt()$ 

 if print_ then <<
  write"The transformation:"$terpri()$
  if vlist then <<
   write"The new variables: "$
   listprint(vlist)$terpri()
  >>;
  if ulist then <<
   write"The new functions: "$
   listprint(ulist)$terpri()
  >>;
  if xslist then <<
   write"The old variables expressed:"$terpri()$
   mathprint cons('LIST,xslist)
  >>;
  if yslist then <<
   write"The old functions expressed:"$terpri()$
   mathprint cons('LIST,yslist)
  >>;
 >>;

 h:=err_catch_solve(cons('LIST,append(
    for each h in xslist collect {'DIFFERENCE, cadr h,caddr h},
    for each h in yslist collect {'DIFFERENCE, cadr h,caddr h} )),
                    cons('LIST,append(vlist,ulist)));
 if h then done_trafo:=cons('LIST,cons(car h,cdr done_trafo))
      else <<
  inverse_trafo_list_incomplete:=t;
  done_trafo:=cons('LIST,cons(cons('LIST,append(xslist,yslist)),
                              cdr done_trafo))
 >>$
 return {'LIST,cons('LIST,ulist),
               cons('LIST,vlist),
               cons('LIST,yslist),
               cons('LIST,xslist),
               full_simplify }
end$

%----------------------------

symbolic procedure adddep(xlist)$
% all functions depending on old variables get a dependency on
% the new variables 
% xlist is a lisp list ((x1,v1,v4,v5),(x2,v2,v3,v4),...)
begin scalar newdep,xs,dp;
 for each xs in xlist do <<
  newdep:=nil$
  while depl!* do <<
   dp:=car depl!*;
   depl!*:=cdr depl!*;
   if not freeof(dp,car xs) then 
   dp:=cons(car dp,union(cdr xs,cdr dp))$
   newdep:=cons(dp,newdep);
  >>;
  depl!*:=reverse newdep;
 >>;
end$

%----------------------------

symbolic procedure add_dep_and_eqn(xlist)$ 
% xlist is a lisp list of old variables
% all functions depending on SOME BUT NOT ALL old variables get a 
% dependency on ALL old variables and compensating extra equations 
% get collected which state that the derivative wrt. to the extra 
% old variables are zero.
begin scalar newdep,neweq,dp,x;
 while depl!* do <<
  dp:=car depl!*;
  depl!*:=cdr depl!*;
  if member(car dp,ftem_) and not freeoflist(cdr dp,xlist) then 
  for each x in xlist do 
  if freeof(cdr dp,x) then <<
   neweq:=cons({'DF,car dp,x},neweq);
   dp:=cons(car dp,cons(x,cdr dp))
  >>$ 
  newdep:=cons(dp,newdep);
 >>;
 depl!*:=reverse newdep;
 % neweq:=for each x in neweq collect simp x$
 return neweq
end$

%----------------------------

symbolic procedure dropdep(xlist)$
% xlist is a lisp list
begin scalar x,dp,newdep$
 for each x in xlist do <<
  newdep:=nil$
  while depl!* do <<
   dp:=car depl!*;
   depl!*:=cdr depl!*;
   if not freeof(dp,x) then 
   dp:=delete(x,dp)$
   newdep:=cons(dp,newdep);
  >>;
  depl!*:=reverse newdep
 >>;
end$

%----------------------------

%symbolic operator TransfoDf$
symbolic procedure TransfoDf(dy,yslist,xlist,vlist)$
% - dy is the derivative to be transformed
% - yslist is a list of already computed substitutions for the old
%   functions and their derivatives
% - xlist is a list of the old variables
% - vlist is a list of the new variables
% All parameters are in prefix form.
% yslist,xlist,vlist are lisp lists
% returns cons(substitution for dy, complete list of substitutions)
begin
 scalar cpy,x,dym1,m,n,newdy,v$
 cpy:=yslist$
 while cpy and
       (dy neq cadar cpy) do cpy:=cdr cpy;
 return
 if not null cpy then cons(car cpy,yslist)          else  % found rule
 if not pairp dy then cons({'EQUAL,dy,simp dy},yslist) else << % no dy-rule
  % dym1 is one lower x-derivative than dy
  if ( length dy = 3      ) or
     ((length dy = 4) and 
      (cadddr dy = 1)     ) then <<x:=caddr dy;dym1:=cadr dy>> 
                            else <<
   cpy:=reverse dy;
   dym1:=reverse
   if not numberp car cpy then <<x:= car cpy;  cdr cpy >> else
   if (car cpy = 1)       then <<x:=cadr cpy; cddr cpy >> else
   if (car cpy = 2)       then <<x:=cadr cpy;  cdr cpy >> else
                               <<x:=cadr cpy; cons(sub1 car cpy,
                                                   cdr cpy)>>
  >>;
  yslist:=TransfoDf(dym1,yslist,xlist,vlist);
  dym1:=car yslist;      % dym1 is now a substitution rule for dym1 above
  dym1:=caddr dym1;      % dym1 is now the expression to be substituted
  yslist:=cdr yslist;    % the new substitution list
  % computation of the subst. rule for dy
  m:=1;
  while xlist and (x neq car xlist) do <<m:=add1 m; xlist:=cdr xlist >>$
  if null xlist then newdy:=diffsq(dym1,x)
                else <<
   newdy:=(nil . 1)$
   n:=0;
   for each v in vlist do <<
    n:=add1 n;
    if not zerop algebraic(Dv!/Dx(n,m)) then 
    newdy:=addsq(multsq(diffsq(dym1,v),simp algebraic(Dv!/Dx(n,m))),newdy)$
    % diffsq(dym1,v) is the full total derivative as it should be
    % provided all functions depend directly on v (as stored in depl!*)
    % or they do not depend on v but not like f(u(v)) with an
    % unspecified f(u)
   >>
  >>$

  % return the new subst. rule and the new yslist
  cons({'EQUAL,dy,newdy},cons({'EQUAL,dy,newdy},yslist))
  % newdy is in sq-form
 >>
end$ % of TransfoDf

%----------------------------
 
symbolic procedure Do_Trafo(arglist,x)$
% arglist={pdes,forg,vl_,pdes}
% x      ={ulist,vlist,yslist,xslist,full_simplify}
begin
 scalar yslist,xslist,ulist,vlist,xlist,ylist,m,n,ovar,nvar,e1,e2,e3,e4,x,detpd,
        pdes,hval,trfo,newforg,newineq_,neweq,drvs,full_simplify,depl!*bak$
        %dyx!/duv,Dv!/Dx
 x:=cdr x$
 ulist :=car x$     % (list g!%1  ...
 vlist :=cadr x$    % (list z!%1  ...
 yslist:=caddr x$   % (list (equal f (!*sq ((((g!%1 . 1) ...
 xslist:=cadddr x$  % (list (equal z (!*sq ((((x!%1 . 1) ...
 full_simplify:=cadddr cdr x$  % = t/nil
 x:=nil$
 depl!*bak:=depl!*$
 % add dependencies and equations
 xlist:=for each e1 in cdr xslist collect cadr e1;
 neweq:=add_dep_and_eqn(xlist)$  

 % update of depl!*
 xlist:=      % becomes ((z x%1 y%1) (y x%1 z%1) (x x%1))
 for each e1 in cdr xslist collect <<
  x:=caddr e1$  % x={'!*SQ,..,t}
  e3:=nil;
  for each e2 in cdr vlist do 
  if not freeof(x,e2) then e3:=cons(e2,e3);
  cons(cadr e1,e3)
 >>$
 adddep(xlist)$

 algebraic <<
  % checking regularity of the transformation
  m:=length(xslist); n:=length(yslist)+m;
  clear dyx!/duv,Dv!/Dx;
  matrix dyx!/duv(n,n);
  matrix Dv!/Dx(m,m);
  ovar:=append(yslist,xslist);
  nvar:=append(ulist,vlist);
  n:=0;
  for each e1 in ovar do <<
   n:=n+1;m:=0;
   for each e2 in nvar do <<
    m:=m+1;
    dyx!/duv(m,n):=df(rhs e1,e2)
   >>
  >>;

  detpd:=det(dyx!/duv);
  if detpd=0 then return <<
   write"The proposed transformation is not regular!"$
   lisp(depl!*:=depl!*bak);
   nil
  >>;
  clear dyx!/duv;
  % computation of Dv/Dx:=(Dx/Dv)^(-1)
  n:=0;
  for each e1 in xslist do <<
   n:=n+1;m:=0;
   for each e2 in vlist do <<
    m:=m+1;
    Dv!/Dx(n,m):=total_alg_mode_deriv(rhs e1,e2)
                % It is assumed that ulist does depend on vlist
   >>
  >>;
  Dv!/Dx:=Dv!/Dx**(-1)
 >>$
 xslist:=cdr xslist$
 yslist:=cdr yslist$
 vlist :=cdr vlist$
 ulist :=cdr ulist$

 % update of global data ftem_, vl_
 if ulist then <<
  for each e1 in yslist do ftem_:=delete(cadr e1,ftem_);
  for each e1 in  ulist do ftem_:=fctinsert(e1,ftem_)$
 >>$

 xlist:=for each e1 in xslist collect reval cadr e1$
 for each e1 in xlist do vl_:=delete(e1,vl_);
 vl_:=append(vl_,vlist)$
 
 ylist:=for each e1 in yslist collect reval cadr e1$

 % adding extra equations due to making all old
 % functions to depend on all old variables
 if neweq then 
 neweq:=mkeqSQlist(nil,nil,neweq,ftem_,vl_,allflags_,t,
                   %orderings_prop_list_all()
                   list(0),nil)$

 % update of the pdes
 pdes:=append(neweq,car arglist)$
 for each e1 in pdes do <<
  hval:=get(e1,'sqval)$

  drvs:=append(search_li2(hval,'DF),ylist)$
  for each e3 in drvs do <<
   trfo:=TransfoDf(e3,yslist,xlist,vlist)$
   hval:=subsq(hval,{(cadar trfo . {'!*sq,caddar trfo,t})})$ 
   % #?# one may even change back TransfoDf if needed
   % but this version is probably faster
   yslist:=cdr trfo
  >>$

  e3:=nil;
  for each e2 in xslist do 
  if not freeof(hval,cadr e2) then e3:=cons((cadr e2 . caddr e2), e3);
  hval:=subsq(hval,e3);

  put(e1,'sqval,hval)
 >>$

 % update of forg
 for each e1 in cadr arglist do
 if (pairp e1) and (car e1 = 'EQUAL) then <<
  hval:=caddr e1;
  drvs:=append(search_li2(hval,'DF),ylist)$
  for each e3 in drvs do <<
   trfo:=TransfoDf(e3,yslist,xlist,vlist)$
   hval:=subsq(hval,{(cadar trfo . {'!*sq,caddar trfo,t})});
   yslist:=cdr trfo
  >>$
  for each e2 in xslist do
  if not freeof(hval,cadr e2) then
  hval:=subsq(hval,{(cadr e2 . reval caddr e2)});
  newforg:=cons({'EQUAL,cadr e1,hval},newforg)$
  e2:=nil;
  for each e3 in ftem_ do 
  if not freeof(hval,e3) then e2:=cons(e3,e2);
  put(cadr e1,'fcts,e2)
 >>                                  else 
 if not freeof(ylist,e1) then <<
  e3:=yslist;
  while e3 and cadar e3 neq e1 do e3:=cdr e3$
  if e3 then newforg:=cons(car e3,newforg)
        else newforg:=cons(e1,newforg)
 >>                                  else 
 newforg:=cons(e1,newforg); 

 % update of ineq_or
 ineq_or:=
 for each e1 in ineq_or collect % e1 is an or_inequality
 for each e2 in e1 collect      % e2 is an expression in an or_equality
 for each e3 in e2 collect <<   % e3 is a factor in e2
  drvs:=append(search_li2(e3,'DF),ylist)$
  for each e4 in drvs do <<
   trfo:=TransfoDf(e4,yslist,xlist,vlist)$
   e3:=subsq(e3,{(cadar trfo . {'!*sq,caddar trfo,t})});
   yslist:=cdr trfo
  >>$
  for each e4 in xslist do
  if not freeof(e3,cadr e4) then
  e3:=subsq(e3,{(cadr e4 . reval caddr e4)});
  e3
 >>$
 simpSQineq_or_adhoc(pdes)$ 

 % update of ineq_
 newineq_:=nil;
 for each e1 in ineq_ do <<
  drvs:=append(search_li2(e1,'DF),ylist)$
  for each e3 in drvs do <<
   trfo:=TransfoDf(e3,yslist,xlist,vlist)$
   e1:=subsq(e1,{(cadar trfo . {'!*sq,caddar trfo,t})});
   yslist:=cdr trfo
  >>$
  for each e2 in xslist do
  if not freeof(e1,cadr e2) then
  e1:=subsq(e1,{(cadr e2 . reval caddr e2)});
  newineq_:=cons((numr e1 . 1),newineq_)
 >>$
 ineq_:=nil;
 for each e1 in newineq_ do addSQineq(pdes,e1,t);

 xlist:=nil;
 for each e1 in xslist do
 if cadr e1 neq caddr e1 then xlist:=cons(cadr e1,xlist);
 dropdep(xlist)$

 for each e1 in pdes do <<
  for each e2 in allflags_ do flag1(e1,e2)$
  updateSQ(e1,get(e1,'sqval),nil,nil,ftem_,vl_,full_simplify,list(0),pdes)$
  drop_pde_from_idties(e1,pdes,nil);
  drop_pde_from_properties(e1,pdes)
 >>$

 % cleanup
 algebraic clear Dv!/Dx;
 return {pdes,newforg,vl_}

end$ % of Do_Trafo

%----------------------------
 
symbolic procedure Find_Trafo(arglist)$
begin 
 scalar dli,avf,f,sol,pde,pdes,forg,batch_bak,print_bak,vlist,
        xslist,vl,h1,h2,h3,h4,trtr,eligfncs,eligpdes,epdes,remain,
        old_history_bak,proc_list_bak,epdescp,eligpdescp;

%       ,ps,maxvno;
% trtr:=t$
 pdes:=car arglist$
 % If there are functions of fewer variables then transformations can
 % make them to functions of more variables which can add solutions.
 % One could first compute the transformation and then check whether
 % there is an ftem_ function which has an enlarged set of dependent
 % variables and in this case either drops the transformation or one
 % adds extra conditions df(f,y)=0 (where d/dy is to be transformed) 
 % for these functions. Instead a preliminary simpler routs is taken
 % in the following, ftem_ may contain only constants or functions
 % of the same number of variables.

% maxvno:=0;
% h1:=ftem_;
% while h1 and <<
%  h3:=fctlength car h1$
%  if h3=0 then t else
%  if maxvno=0 then <<maxvno:=h3;t>> else 
%  if h3=maxvno then t else nil
% >> do h1:=cdr h1;
% if h1 then return <<
%  if print_ then <<
%   write"Non-constant functions of fewer variables prevent"$terpri()$ 
%   write"the application of this technique."$terpri()
%  >>$
%  nil
% >>$
% if trtr then <<write"111"$terpri()>>$

 % Find eligible PDEs
 while pdes do <<
  pde:=car pdes;pdes:=cdr pdes;
%  if get(pde,'nvars)=maxvno then <<
   eligfncs:=nil;
   avf:=get(pde,'allvarfcts)$
   if avf and null cdr avf then <<
    % There must only be one function of all variables because
    % the other one would be part of the inhomogeneity and 
    % derivatives of this function would give errors in quasilinpde
    % when the differentiation variable becomes a function in the
    % characteristic ODE system and substitutions are done where
    % the function is substituted by an expression that has been
    % computed. But also if no derivatives occur, crack is strictly
    % speaking not able to deal with funtions of functions.
    % Therefore only one function apart from constants is allowed.
    f:=car avf; 
    avf:=get(pde,'fcts)$  % (re-use avf)
    while avf and ((car avf=f) or 
                   (null fctargs car avf)) do avf:=cdr avf$
    if null avf then << % ie. only constants apart from the single fnc f
     dli:=get(pde,'derivs);
     h1:=t; h2:=0;  % h2 counts the first order derivatives of f
     while dli and h1 do  
     if (not pairp caar dli) or 
	(caaar dli neq f) then dli:=cdr dli else
     if null cdaar dli then dli:=cdr dli else % f algebraic 
     if null cddaar dli then <<h2:=add1 h2;dli:=cdr dli>>
			else h1:=nil;
     if null dli and (h2 > 1) then eligfncs:=cons(f,eligfncs)

    >>$
    if eligfncs then <<
     eligpdes:=cons(cons(pde,eligfncs),eligpdes);
     epdes:=cons(pde,epdes)
    >>
   >>
%  >>
 >>$
 if trtr then <<write"222"$terpri()>>$
 if null epdes then return nil;

 epdescp:=epdes;
 eligpdescp:=eligpdes;
 % It may be that an initially good looking PDE turns out not 
 % to be integrable and another one has to be tried which
 % then is tried by returning to 'again:'.
again:
 if null epdescp then return nil;
 epdes:=epdescp;
 eligpdes:=eligpdescp;

 if expert_mode then 
 if null (pde:=selectpdes(epdes,1)) then return nil
                                    else <<
  pde:=car pde$
  f:=get(pde,'allvarfcts);
  if null f then pde:=nil
            else f:=car f
 >>             else << 
  if trtr then <<write"333"$terpri()>>$
 
  % Find PDEs with min number of allvar functions
  h2:=10000;
  remain:=nil;
  for each h1 in epdes do <<
   h3:=length get(h1,'allvarfcts);
   if h3<h2 then <<h2:=h3;remain:={h1}>> else
   if h3=h2 then remain:=cons(h1,remain);
  >>; 
  epdes:=remain;
  if trtr then <<write"444"$terpri()>>$

  % Find PDEs with max number of variables
  h2:=0;
  for each h1 in epdes do <<
   h3:=get(h1,'nvars);
   if h3>h2 then <<h2:=h3;remain:={h1}>> else
   if h3=h2 then remain:=cons(h1,remain);
  >>;
  epdes:=remain;
  if trtr then <<write"555"$terpri()>>$

  % Find PDEs with fewest number of functions of fewer variables
  h2:=10000;
  for each h1 in epdes do <<
   h3:=length get(h1,'fcts) - length get(h1,'allvarfcts);
   if h3<h2 then <<h2:=h3;remain:={h1}>> else
   if h3=h2 then remain:=cons(h1,remain);
  >>;
  epdes:=remain;
  if trtr then <<write"5a5a5a"$terpri()>>$

  % Find shortest of these PDEs
  h2:=10000;
  for each h1 in epdes do <<
   h3:=get(h1,'terms);
   if h3<h2 then <<h2:=h3;remain:={h1}>> else
   if h3=h2 then remain:=cons(h1,remain);
  >>;
  epdes:=remain;
  if trtr then <<write"666"$terpri()>>$
  pde:=car epdes$   % One could select further the one with the 
                    % fewest variables involved in the transformation
  while eligpdes and caar eligpdes neq pde do eligpdes:=cdr eligpdes;
  f:=cadar eligpdes;

 >>$

 if trtr then <<write"777"$terpri()>>$
 if null pde then return nil;
 if trtr then <<write"888"$terpri()>>$

 epdescp:=delete(pde,epdescp); 

 if print_ then <<
  write"Finding a transformation to integrate the 1st order PDE ",pde,":"$
  terpri()$
 >>$

 old_history_bak:=old_history; old_history:=nil;
 proc_list_bak:=proc_list_;    proc_list_:=default_proc_list_$
 print_bak:=print_;      
 if !*batch_mode and null batch_mode_sub then print_:=8
                                         else print_:=nil$
 batch_bak:=!*batch_mode; !*batch_mode:=batch_mode_sub$
 pdes:=car arglist$
 forg:=cadr arglist$

 h1:=level_string(session_)$
 h1:=bldmsg("%s%s.",h1,"qlp")$
 backup_to_file(pdes,forg,h1)$ % moved before again:, should be ok
 if trtr then <<write"999"$terpri()>>$
%sol:=reval algebraic(quasilinpde(lisp(get(pde,'val)),f,
 sol:=reval algebraic(quasilinpde(lisp({'!*sq,get(pde,'sqval),t}),f,
                                  lisp(cons('LIST,get(pde,'vars)))))$
 % This provides the substitutions to be done in Do_Trafo which have
 % to be given in prefix form in the subsq statements --> sol:=reval ...
 restore_backup_from_file(pdes,forg,h1)$
 system bldmsg ("rm '%s'",h1);
 if trtr then <<write"000"$terpri()>>$ 
 if trtr then <<write"sol0="$mathprint sol$terpri()>>$   

 old_history:=old_history_bak;
 proc_list_:=proc_list_bak; 
 !*batch_mode:=batch_bak$ 
 print_:=print_bak$

 if null sol or null cdr sol or null cdadr sol then return nil$

 sol:=cdr sol$  % getting rid of 'LIST

 % sol is a list of solutions of which the first will be used.  
 % If an unresolved integration occurs then this will give
 % too much trouble potentially everywhere, for example, in crint.red.
 if freeint_ and (null freeof(car sol,'INT)) then <<
  write"The found point transformation includes an unperformed integration:"$
  mathprint car sol$
  if !*nat then <<
   algebraic(off nat);
   write"and again in machine readable form:"$
   mathprint car sol$
   algebraic(on nat);
  >>$
  write"This will probably cause problems later on in the"$terpri()$
  write"computation. If you want to enforce using this"$terpri()$
  write"substitution you would have to set the flag"$terpri()$
  write"freeint_ to nil using the 'as' command and"$terpri()$
  write"re-do this step."$terpri()$
  goto again
 >>$

 % Would the transformation require inequalities?
 h1:=zero_den(sol,ftem_)$
 h3:=nil$
 for each h2 in h1 do 
 h3:=union(simplifySQ(h2,ftem_,t,nil,t),h3)$
 if h3 then return <<
  for each h2 in h3 do
  if h2 neq {(1 . 1)} then <<
   if print_ then <<
    write"The intended transformation "$terpri()$
    mathprint sol$
    write"leads to a case distinction whether :"$terpri()$
    mathprint {'!*SQ,h2,t}$
    write"vanishes or not. This case distinction is done next."$
    terpri()
   >>$
   to_do_list:=cons(list('split_into_cases,h2),to_do_list)
  >>$
  nil
 >>$

 sol:=cdar sol;  % taking the first solution and dropping 'LIST   
 
 h1:=sol;
 % We delete that single element which includes the function f of the PDE
 % because we want to do a point transformation only of the independent
 % variables, not involing the function of the PDE. As a consequence
 % we will have to add one of the independent variables to have
 % equally many expressions as independent variables to define the
 % transformation.
 for each h2 in h1 do 
 if not freeof(h2,f) then sol:=delete(h2,sol);

 if trtr then <<write"f=",f$terpri()$
  write"h1=",h1$terpri()$
  write"sol0="$mathprint cons('LIST,sol)       
 >>$

 % Make a list of all variables occuring in these expressions
 % these are all the variables to occur in the transformation.
 % Keep only the algebraic expressions in sol, drop the single variables.
 h2:=get(pde,'vars)$
 h4:=nil;
 for each f in h2 do if member(f,sol) then <<
  h4:=cons(f,h4);
  h2:=delete(f,h2);
  sol:=delete(f,sol); 
 >>$
 if trtr then <<write"sol1="$mathprint cons('LIST,sol)>>$   

 % find the variable for which the algebraic expressions are 
 % most easily solved  
 if trtr then <<write"h2=",h2$terpri()>>$
 xslist:=err_catch_solve(cons('LIST,sol),cons('LIST,h2))$
 if null xslist then return <<
  write"REDUCE was not able to solve"$mathprint cons('LIST,sol)$ 
  write"for one of "$listprint(h2)$terpri()$
  nil
 >>             else xslist:=cdr reval car xslist$

 % sol is a list of solutions of which the first will be used.  
 % If an unresolved integration occurs then this will give
 % too much trouble potentially everywhere, for example, in crint.red.

 if trtr then <<write"xslist=",xslist$terpri()>>$

 h3:=nil;
 while xslist do <<
  f:=car xslist; xslist:=cdr xslist;

  if (pairp f) and (car f='EQUAL) and 
     ((pairp caddr f) and 
      (caaddr f = 'ARBCOMPLEX)) then <<
   h2:=delete(cadr f,h2);
   h3:=cons(cadr f,h3);
   xslist:=subst(1,caddr f,xslist)
  >>
 >>$

 if trtr then <<write"h3new=",h3$terpri()$
                write"h2new=",h2$terpri()>>$

 sol:=append(h4,sol);
 if trtr then <<write"sol3=",sol$terpri()>>$

 if trtr then <<write"before: h4=",h4$terpri()>>$
 h3:=append(h4,append(h2,h3));
 if trtr then <<write"new: h3=",h3$terpri()>>$
 h4:=h3;
 for h1:=1:(length sol) do h4:=cdr h4$
 sol:=append(sol,h4)$
 if trtr then <<write"new: h4=",h4$terpri()>>$

 h4:=mkid('!%,length done_trafo);
 vlist:=for each f in h3 collect mkid(f,h4);
 if trtr then <<write"vlist=",vlist$terpri()>>$

 h1:=vlist$
 if trtr then <<write"sol-2="$mathprint cons('LIST,sol)$terpri()>>$
 h2:=sol;
 while sol do << % The allocation of new variable names to expressions
                 % in sol is not very intelligent but does not matter
  vl:=cons({'DIFFERENCE,car sol,car h1},vl);
  sol:=cdr sol;
  h1:=cdr h1;
 >>$

 if trtr then <<write"2nd SOLVE: vl="$mathprint cons('LIST,vl)$terpri()$
                write"h3=",h3>>$
 h4:=!!arbint$
 xslist:=err_catch_solve(cons('LIST,vl),cons('LIST,h3))$

 if null xslist then return <<
  write"REDUCE was not able to solve"$mathprint cons('LIST,vl)$
  write"for the variables "$listprint(h3);
  nil
 >>;

 xslist:=cons('LIST,xslist)$
 for h1:=(h4+1):!!arbint do 
 xslist:=algebraic(sub(arbint(lisp h1)=0,lisp xslist))$
 xslist:=cdr reval xslist;

 % If the solution contains unperformed substitutions then this will lead
 % to problems later on.
 if not freeof(xslist,'sub) then <<
               write"'sub check ++++++++++",xslist$terpri()$
               write"freeof(xslist,'sub) = ",freeof(xslist,'sub)$terpri()$
               if freeof(xslist,'sub) then write"free" else write"not free"$terpri()$
  write"The found point transformation includes an uncompleted substitution:"$
  mathprint xslist$
  if !*nat then <<
   algebraic(off nat);
   write"and again in machine readable form:"$
   mathprint xslist$
   algebraic(on nat);
  >>$
  write"Because this will probably cause problems later on in the"$terpri()$
  write"computation, you will need to input it manually using the"$terpri()$
  write"pt-command."$terpri()$
  goto again
 >>                         else 
 if not freeof(xslist,'root_of) then return <<
  write"The following variable transformation expresses variables"$
  terpri()$
  listprint(h3);
  write"  through variables  "$
  listprint(vlist); write" :"$terpri()$
  for each f in cdr car xslist do mathprint f$
  write"BUT the transformation could not be done explicitly."$terpri()$
  write"The user is recommended to try finding a transformation"$terpri()$
  write"manually and input it with the 'pt' command."$terpri()
 >>                             else
 xslist:=car xslist$
 
 if trtr or print_ then <<
  write"The following variable transformation expresses variables"$
  terpri()$
  listprint(h3);
  write"  through variables  "$
  listprint(vlist); write" :"$terpri()$
  for each f in cdr xslist do mathprint f
 >>$

 h3:=for each h1 in vl collect {'EQUAL,caddr h1,cadr h1};
 done_trafo:=cons('LIST,cons(cons('LIST,h3),cdr done_trafo));
 
 return Do_Trafo(arglist,{'LIST,{'LIST},cons('LIST,vlist),
                          {'LIST},xslist,t %full_simplify 
                         });

end$ % of Find_Trafo

%----------------------------

symbolic procedure General_Trafo(arglist)$
% Doing a transformation for all data relevant in CRACK
% Tramsformation rule for partial derivatives d using total
% derivatives D:
%
%          /   p \ -1
%   d     |  Dx   |    D
%   --- = |  ---  |  * ---
%     p   |    i  |      i
%   dx     \ Dv  /     Dv
%
begin
 scalar x;
 x:=Input_Trafo(car arglist)$
 if null x then return 
 <<terpri()$write"No proper input --> no transformation"$nil>>$
 return Do_Trafo(arglist,x)
end$

%----------------------------

endmodule$

end$

General_Trafo
  Input_Trafo
  Do_Trafo

Find_Trafo
  Do_Trafo
   total_alg_mode_deriv  -> tot_alg_deri
    mkeqSQlist
    TransfoDf
     total_alg_mode_deriv  -> tot_alg_deri
    simpSQineq_or_adhoc
    updateSQ

tr Find_Trafo
tr quasilinpde
tr Do_Trafo
tr total_alg_mode_deriv
tr tot_alg_deri
tr mkeqSQlist
tr TransfoDf
tr simpSQineq_or_adhoc
tr updateSQ

