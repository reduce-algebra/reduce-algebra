module ghyper;   % Generalized Hypergeometric Functions.

% Author : Victor Adamchik, Byelorussian University Minsk, Byelorussia.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%


% Major modifications by: Winfried Neun, ZIB Berlin.

% Oct 22, 2001, hypergeometric({a,b},{0},z) returns
%         unevaluated (without error) as requested by Francis Wright


 put('ghf,'simpfn,'simpghf)$

   symbolic procedure simpghf u;
   if null cddr u then
        rerror('specialf,125,
              "WRONG NUMBER OF ARGUMENTS TO GHF-FUNCTION")
       else
   if or(not numberp car u,not numberp cadr u) then
        rerror('specialf,126,"INVALID AS INTEGER")
       else
   begin scalar vv,v;
   v:=redpar1(cddr u,car u);
   vv:=redpar1(cdr v,cadr u);
   if null cddr vv then return
      ghfsq(list(car u,cadr u),listsq car v,
      listsq car vv, simp cadr vv);
      return rerror ('specialf,127,
        "WRONG NUMBER OF ARGUMENTS TO GHF-FUNCTION");
   end$

 symbolic procedure ghfexit(a,b,z);
 begin scalar aa,bb;
  aa:= 'list . listprepsq a;
  bb:= 'list . listprepsq b;
  return mksqnew({'hypergeometric,aa,bb,prepsq z});
  end;

%***********************************************************************
%*                      GHF as a polynomial                            *
%***********************************************************************

symbolic procedure listmaxsq u;
 % u - list of numbers of SQ.
 % return - max value.
 if null cdr u then car u else
 if null caar u then car u else
 if null caadr u then cadr u else
 if caar u > caadr u or car u = cadr u then
            listmaxsq((car u) . cddr u) else
            listmaxsq((cadr u) . cddr u)$

 symbolic procedure ghfpolynomp (u,a);
 begin scalar w1,w2;
m1:
 if null u then
   if null w1 then <<u:=w2; return (nil . a) >>
              else <<u:=listmaxsq(w1);
                     a:=u . append(delete(u,w1),w2);
                     return (t . a)>>
           else
 if parfool(car u) then (w1:=(car u) . w1)
                   else (w2:=(car u) . w2);
 u:=cdr u;
 goto m1;
 end$

 symbolic procedure polynom(u,a,b,z);
 % u - list of SQ.
 begin scalar s; integer k;
 if null caar(u) then return '(1 . 1) else
   s := ghfpolynomp (b,a);
   a := cdr s;
   if car s then
     if null caar a or greaterp(caar a,caar u) then
     <<%rerror('special,124,
       %        "zero in the denominator of the GHF-function");
       b:=a; a:=u;
       return ghfexit(a,b,z);
     >>
   else b:=a;
  k:=1;  s:=1 . 1;
m:
    s:=addsq(s,quotsq(multsq(multpochh(u,simp k),exptsq(z,k)),
        multpochh(append(list('(1 . 1)),b),simp k)));
    k:=k+1;
    if greaterp(k,numr negsq(car u)) then return s else goto m;
   end$

%***********************************************************************
%*                   Lowering of the order GHF                         *
%***********************************************************************

% This assigns to a and b!
 symbolic smacro procedure ghflowering1p;
  begin scalar sa,sb,w1,w2;
  sa:=a;   sb:=b;
 m1:  if null b then << a:=sa; b:=sb; return nil
                     >>;
 m2:  if null a then << w2:= (car b) . w2;
                        b:=cdr b;
                        a:=sa; w1:=nil;
                        goto m1
                     >>
                 else
      if numberp(prepsq subtrsq(car a,car b)) and
         greaterp(car(subtrsq(car a,car b)),0) then
                        <<
                         b:=car b . append(w2,cdr b);
                         a:=subtrsq(car a,car b) . append(w1,cdr a);
                         return t
                        >> else
                        <<
                         w1:=(car a) . w1;
                         a:=cdr a;
                         goto m2
                        >>;
   end$

 symbolic procedure lowering1(x,y,u,z);
  % x -- (m . a).
  % y -- (g . b).
  addsq(ghfsq(u,append(list(subtrsq(addsq(car x,car y),'(1 . 1))),
                            cdr x),
                append(list(car y),cdr y),z),
        multsq(ghfsq(u,append(list(addsq(car x,car y)),listplus(cdr x,
                        '(1 . 1))),
                       append(list(addsq(car y,'(1 . 1))),
                              listplus(cdr y,'(1 . 1))),z),
               quotsq(multsq(z,multlist(cdr x)),
                      multsq(car y,multlist(cdr y)))))$

% This assigns to a and b
 symbolic smacro procedure ghflowering2p;
  begin scalar sa,sb,w1,wa,fl;
  if equal(z,'(1 . 1)) then return nil;
  sa:=a;   sb:=b;
 m1:  if null b then
         << b:=sb;
            if fl then a:=wa . sa else a:= sa;
            return nil
         >>;
 m2:  if null a then
         << b:=cdr b;
            a:=sa; w1:=nil;
            goto m1
         >>
                else
      if numberp(prepsq subtrsq(car b,car a)) and
         lessp(car(subtrsq(car a,car b)),0) then
               if fl then
                 if not equal(wa,car a) then
                    << b:=sb;
                       a:=list(wa,car a) . append(w1,cdr a);
                       return t
                    >>
                    else
                    <<
                       w1:=(car a) . w1;
                       a:=cdr a;
                       goto m2
                    >>
                 else
                 << fl:=t;
                    sa:=append(w1,cdr a);
                    wa:=car a;
                    b:=cdr b; a:=sa; w1:=nil;
                    goto m1
                 >>
              else
              << w1:= (car a) .w1;
                 a:=cdr a;
                 goto m2
              >>;
   end$

   symbolic procedure lowering2(x,b,u,z);
   % x -- (r s).(a).
  subtrsq(multsq(ghfsq(u,append(list(caar x,addsq('(1 . 1),cadar x)),
                        cdr x),b,z),
                  quotsq(cadar x,subtrsq(cadar x,caar x))),
           multsq(ghfsq(u,append(list(addsq('(1 . 1),caar x),cadar x),
                        cdr x),b,z),
                  quotsq(caar x,subtrsq(cadar x,caar x))))$

% This assigns to a and b
  symbolic smacro procedure ghflowering3p;
  %return a = (mmm . a1).
   begin scalar sa,w,mmm;    % MM used in SPDE as a global.
   sa:=a;
m1: if null a then << a:=sa; return nil >>
              else
    if not numberp(prepsq car a) then
                   <<w:= (car a) . w; a:=cdr a; goto m1 >>;

    if member ('(1 . 1), a) then <<mmm := '(1 . 1);
                                   a:= delete('(1 . 1),a)>>
                else << mmm:= car a;  a:=cdr a >>; % WN 2.2 94

m2:  if null a then
        if listnumberp b then << a:=mmm . w; return t >>
                         else << a:=sa; return nil>>
                else
        if equal(car a,'(1 . 1)) then
                         <<a:=sa; return nil>>
                                else
                         <<w:=(car a) . w;
                           a:=cdr a;
                           goto m2
                         >>;
  end$

  symbolic procedure listnumberp(v);
  % v -- list of SQ.
  % value is T if numberp exist in (v).
   if null v then nil
             else
   if numberp(prepsq car v)  then t
                             else listnumberp(cdr v)$

  symbolic procedure lowering3(a,b,u,z);
  multsq(quotsq(multlist(difflist(b,'(1 . 1))),multsq(z,multlist(
                         difflist(cdr a,'(1 . 1))))),
         subtrsq(ghfsq(u, (car a) . difflist(cdr a,'(1 . 1)),
                         difflist(b,'(1 . 1)),z),
                 ghfsq(u,append(list(subtrsq(car a,'(1 . 1))),
                    difflist(cdr a,'(1 . 1))),difflist(b,'(1 . 1)),z)))$

%***********************************************************************
%*                      GHFsq, main entry                              *
%***********************************************************************

   symbolic procedure ghfsq(u,a,b,z);
   % u -- (p q) PF.
   % a,b -- lists of SQ.
   % z -- SQ.
   begin scalar c,aaa;
   u:=redpar(a,b);
   a:=car u;b:=cadr u;u:=list(length(a), length(b));
   if null numr z then return '(1 . 1) else
   if listparfool(b,(nil .1)) and not listparfool(a,(nil . 1)) then
       % return rerror('specialf,128,
        %"zero in the denominator of the GHF-function")
       return ghfexit(a,b,z)
      else
   aaa := ghfpolynomp(a,a);
   a := cdr aaa;
   if car aaa         then return polynom(a,a,b,z) else
   if ghflowering1p() then return lowering1(a,b,u,z) else
   if ghflowering2p() then return lowering2(a,b,u,z) else
   if ghflowering3p() then return lowering3(a,b,u,z) else
   if car u = 0 and cadr u = 0 then return expdeg(simp 'e,z) else
   if car u = 0 and cadr u = 1 then return ghf01(a,b,z) else
   if car u = 1 and cadr u = 0 then
       if  z='(1 . 1) then return ghfexit(a,b,z)
       else
          return expdeg(subtrsq('(1 . 1),z),if null a then '(nil . 1)
                                          else negsq(car a))
                                                          else
   if car u = 1 and cadr u = 1 then return ghf11(a,b,z)  else
   if car u = 1 and cadr u = 2 then return ghf12(a,b,z)  else
   if car u = 2 and cadr u = 1 then return ghf21(a,b,z)  else
   if car u = cadr u + 1 then
      if (c:=ghfmid(a,b,z)) = 'fail
                        then return ghfexit(a,b,z)
                        else return c;

   if car u <= cadr u then return ghfexit(a,b,z);
   return rerror('specialf,131,"hypergeometric series diverges");
   end$


%***********************************************************************
%                        p = q+1                                       *
%***********************************************************************

 symbolic procedure ghfmid(a,b,z);
 begin scalar c;
  c:= redpar(a,difflist(b, '(1 . 1)));
   if length(cadr c) > 0 or length(car c) > 1 then return 'fail
     else
      return formulaformidcase(length(b), caar c,
                               subtrsq(car b,'(1 . 1)), z);
 end$

 symbolic procedure formulaformidcase(p,b,a,z);
 if not(p = 1) and b = '(1 . 1) and z = '(1 . 1) then
        multsq(simpx1(prepsq(multsq('(-1 . 1),a)),p,1),
               quotsq(dfpsisq(a,simp(p-1)),gamsq(simp p)))
   else
 if b = '(1 . 1) and z='(-1 . 1) then
    quotsq(multsq(simpx1(prepsq(multsq('(-1 . 2),a)),p,1),
               subtrsq(dfpsisq(multsq(a, '(1 . 2)),simp(p-1)),
                    dfpsisq(multsq(addsq('(1 . 1),a),'(1 . 2)),
                            simp(p-1)))),
           gamsq(simp p))
   else
 if z = '(1 . 1) and not numberp(prepsq b) then
    multsq(
    subsqnew(
     derivativesq(
       quotsq(gamsq(simp 'r),gamsq(addsq(simp 'r,subtrsq('(1 . 1),b)))),
       'r,simp(p-1)),
     a,'r),
    quotsq(
      multsq(multsq(simpx1(prepsq(multsq('(-1 . 1),a)),p,1), '(-1 . 1)),
             gamsq(subtrsq('(1 . 1),b))),
     gamsq(simp p)))
   else
 if z='(-1 . 1) and numberp prepsq(b) then
    begin scalar c; integer k;
    return multsq(
     subsqnew(
      derivativesq( addsq(
             <<
               k:=prepsq(b) - 1; c:='(nil . 1);
               while prepsq(k)>0 do
                <<
                c:=addsq(c, multsq(gamsq(b),
                simppochh(subtrsq(simp(1+k),simp 'r),
                          simp(prepsq(b)-1-k))));
                k:=k-1
                >>;
              c
             >>,
             quotsq(
               multsq(gamsq(subtrsq(b,simp 'r)),
                subtrsq(psisq(multsq(addsq(simp 'r,'(1 . 1)),'(1 . 2))),
                             psisq(multsq(simp 'r,'(1 . 2))))),
               multsq((2 . 1), gamsq(subtrsq('(1 . 1),simp 'r))))),
      'r,p-1), a, 'r),
    quotsq(
           multsq(simpx1(prepsq(multsq('(-1 . 1),a)),p,1), '(-1 . 1)),
           multsq(gamsq(simp p),gamsq(simp b))))
  end
 else 'fail$

%***********************************************************************
%*                       Particular cases                              *
%***********************************************************************

 symbolic procedure ghf01(a,b,z);
  if znak z then
   multsq(gamsq(car b),multsq(bessmsq(subtrsq(car b,'(1 . 1)),
   multsq('(2 . 1),simpx1(prepsq z,1,2))),
          expdeg(z,multsq(subtrsq('(1 . 1),car b),'(1 . 2)))))
                     else
   multsq(gamsq(car b),multsq(besssq(subtrsq(car b,'(1 . 1)),
   multsq('(2 . 1),simpx1(prepsq(negsq z),1,2))),expdeg(negsq z,
   multsq(subtrsq('(1 . 1),car b),'(1 . 2))))) $

  symbolic procedure ghf11(a,b,z);
  if equal(car b,multsq('(2 . 1),car a)) then
     multsq(multsq(gamsq(addsq('(1 . 2),car a)),expdeg(simp 'e,
                       multsq(z,'(1 . 2)))),
            multsq(expdeg(multsq(z,'(1 . 4)),subtrsq('(1 . 2),car a)),
                   bessmsq(subtrsq(car a,'(1 . 2)),multsq(z,'(1 . 2)))))
  else
  if equal(car a,'(1 . 2)) and equal(car b,'(3 . 2)) then
     multsq(multsq(simpx1('pi,1,2),'(1 . 2)),
     if znak z then
       quotsq(simpfunc('erfi,simpx1(prepsq z,1,2)),simpx1(prepsq z,1,2))
               else
        quotsq(simpfunc('erf,simpx1(prepsq(negsq z),1,2)),
               simpx1(prepsq(negsq z),1,2)))
  else
  if equal(car a,'(1 . 1)) and equal(car b,'(3 . 2)) and znak z then
     multsq(multsq('(1 . 2),expdeg(simp 'e,z)),
            multsq(simpfunc('erf,simpx1(prepsq z,1,2)),simpx1(prepsq
            quotsq(simp('pi),z),1,2)))
                   else ghfexit(a,b,z)$

  symbolic procedure ghf21(a,b,z);
  if and(equal(car a,'(1 . 2)),equal(cadr a,'(1 . 2)),
         equal(car b,'(3 . 2)),znak(z))
    then
     quotsq(simpfunc('asin,simpx1(prepsq(z),1,2)),
       simpx1(prepsq(z),1,2))
    else
  if ((equal(car a,'(1 . 2)) and equal(cadr a,'(1 . 1))) or
      (equal(car a,'(1 . 1)) and equal(cadr a,'(1 . 2)))) and
       equal(car b,'(3 . 2))
    then
    <<
    if not znak(z) then
        quotsq(simpfunc('atan,simpx1(prepsq(negsq z),1,2)),
        simpx1(prepsq(negsq z),1,2)) else
%    if not equal(z,'(1 . 1)) then
%       quotsq(simpfunc('log,addsq('(1 . 1),simpx1(prepsq z,1,2))),
%       multsq(simpfunc('log,subtrsq('(1 . 1),simpx1(prepsq z,1,2))),
%       multsq('(2 . 1),simpx1(prepsq z,1,2)))) else
     if not equal(z,'(1 . 1)) then
       multsq(simpfunc('log,quotsq(addsq('(1 . 1),simpx1(prepsq z,1,2)),
                            subtrsq('(1 . 1),simpx1(prepsq z,1,2)))),
              invsq(multsq('(2 . 1),simpx1(prepsq z,1,2)))) else
    ghfexit(a,b,z)
    >>
    else
  if and(equal(car a,'(1 . 1)),equal(cadr a,'(1 . 1)),
         equal(car b,'(2 . 1)),not equal(z,'(1 . 1)))
    then
       quotsq(simpfunc('log,addsq('(1 . 1),negsq z)),negsq z)
    else
  if equal(subtrsq(addsq(car a,cadr a),car b),'(-1 . 2)) and
     (equal(multsq('(2 . 1),car a),car b) or
      equal(multsq('(2 . 1),cadr a),car b))
    then
       multsq(expdeg(addsq('(1 . 1),
              simpx1(prepsq(subtrsq('(1 . 1),z)),1,2)),
       subtrsq('(1 . 1),car b)),expdeg('(2 . 1),addsq(car b,'(-1 . 1))))
    else
  if z='(1 . 1)
     and (not numberp prepsq subtrsq(car b,addsq(car a, cadr a))
          or prepsq(subtrsq(car b,addsq(car a, cadr a))) > 0 )
    then quotsq(multsq(gamsq(car b),
                       gamsq(subtrsq(car b,addsq(car a,cadr a))) ),
                multsq(gamsq(subtrsq(car b,car a)),
                       gamsq(subtrsq(car b,cadr a))))
    else
  if car a='(1 . 1) and cadr a='(1 . 1) and numberp prepsq car b and
     prepsq car(b) > 0 and not(z='(1 . 1)) then
        formula136(prepsq car b,z) else
ghfexit(a,b,z)$

 symbolic procedure formula136(m,z);
 begin scalar c; integer k;
 c:='(nil . 1); k:=2;
 while k<=m-1 do
   << c:=addsq(c,quotsq(exptsq(subtrsq(z,'(1 . 1)),k),
                        multsq(exptsq(z,k),simp(m-k))));
      k:=k+1
   >>;
 c:=subtrsq(c,multsq(exptsq(quotsq(subtrsq(z,'(1 . 1)),z),m),
                     simpfunc('log,subtrsq('(1 . 1),z))));
 return
  multsq(c,
         quotsq(multsq(simp(m-1),z),exptsq(subtrsq(z,'(1 . 1)),2)));
 end$

  symbolic procedure ghf12(a,b,z);
  if equal(car a,'(3 . 4)) and (equal(car b,'(3 . 2)) and equal(cadr b,
     '(7 . 4)) or equal(car b,'(7 . 4)) and equal(cadr b,'(3 . 2)))
     and not znak z  then
     <<z:=multsq('(2 . 1),simpx1(prepsq(negsq z),1,2));
     multsq(quotsq(multsq('(3 . 1),simpx1('pi,1,2)),
                   multsq(simpx1(2,1,2),simpx1(prepsq z,3,2))),
            simpfunc('intfs,z)) >>
                    else
  if equal(car a,'(1 . 4)) and (equal(car b,'(1 . 2)) and equal(cadr b,
     '(5 . 4)) or equal(car b,'(5 . 4)) and equal(cadr b,'(1 . 2)))
     and not znak z  then
     <<z:=multsq((2 . 1),simpx1(prepsq(negsq z),1,2));
     multsq(quotsq(simpx1('pi,1,2),multsq(simpx1(2,1,2),
     simpx1(prepsq z,1,2))),simpfunc('intfc,z)) >>
            else ghfexit(a,b,z)$

symbolic inline procedure ghyper_fehlerf();
        rerror('specialf,139,"Wrong arguments to hypergeometric");

symbolic procedure hypergeom(u);

begin scalar list1,list2,res,res1;

if not (length(u) = 3) then ghyper_fehlerf();
if pairp u then list1 :=car u else ghyper_fehlerf();
if pairp cdr u then list2 := cadr u else ghyper_fehlerf();
if not pairp cddr u then  ghyper_fehlerf();

if not eqcar(list1,'list) then ghyper_fehlerf();
if not eqcar(list2,'list) then ghyper_fehlerf();

list1 := for each x in cdr list1 collect simp reval x;
list2 := for each x in cdr list2 collect simp reval x;
res := ghfsq(list (length list1,length list2),
                        list1,list2,simp caddr u);
res1 := prepsq res;
return if eqcar(res1,'hypergeometric) then res else simp res1;
                        end;

remflag('(hypergeometric),'full);
put('hypergeometric,'simpfn,'hypergeom);

% differentiation of hypergeometric function

symbolic procedure dfform_hypergeometric(ghfform,dfvar,n);
  begin scalar a,b,var,fct,result;
    a:= cdr cadr ghfform;
    b:= cdr caddr ghfform;
    var := cadddr ghfform;
    % diff. w.r.t. one of indizes --> return unchanged
    if depends(a,dfvar) or depends(b,dfvar)
      then result := !*kk2q {'df,ghfform,dfvar}
     else << fct := simp!* {'quotient,retimes a,retimes b};
             result := simp!* {'hypergeometric,
		         'list . for each el in a collect {'plus, el, 1},
		         'list . for each el in b collect {'plus, el, 1},
                         var};
             result := multsq(fct,result) >>;
    if n neq 1
      then result := multsq(!*t2q((ghfform .** (n-1)) .* n),result);
    return result;
  end;

put('hypergeometric,'dfform,'dfform_hypergeometric);


% something is missing:

algebraic let {hypergeometric({1/2,1/2},{3/2},-(~x)^2) => asinh(x)/x };

algebraic let hypergeometric({~a,~b},{~c},-(~z/(1-~z))) =>
                hypergeometric({a,c-b},{c},z) * (1-z)^a;
                % Pfaff's reflection law

flag ('(permutationof),'boolean);

symbolic procedure permutationof(set1,set2);
        length set1 = length set2
         and not setdiff(set1,set2);

algebraic let {
 hypergeometric({},~lowerind,~z) =>
        3/(32*sqrt(2)*(-z)^(3/4))*
         (cosh(2*(-z*4)^(1/4))*sin(2*(-z*4)^(1/4)) -
         sinh(2*(-z*4)^(1/4))*cos(2*(-z*4)^(1/4)))
        when permutationof(lowerind,{5/4,3/2,7/4})
        and numberp z and z < 0,

 hypergeometric({},~lowerind,~z) =>
        1/(4*(-4*z)^(1/4))*
          (sinh(2*(-z*4)^(1/4))*cos(2*(-z*4)^(1/4)) +
           cosh(2*(-z*4)^(1/4))*sin(2*(-z*4)^(1/4)))
        when permutationof(lowerind,{5/4,1/2,3/4})
             and numberp z and z < 0,

 hypergeometric({},~lowerind,~z) =>
         1/(8*(-z)^(1/2))*sinh(2*(-z*4)^(1/4))*sin(2*(-z*4)^(1/4))
        when permutationof(lowerind,{3/4,5/4,3/2})
            and numberp z and z < 0,

 hypergeometric({},~lowerind,~z) =>
         cosh(2*(-z*4)^(1/4))*cos(2*(-z*4)^(1/4))
        when permutationof(lowerind,{1/4,1/2,3/4})
           and numberp z and z < 0,

 hypergeometric({},~lowerind,~z) =>
         3/(64*z^(3/4))*(sinh(4*z^(1/4)) -sin(4*z^(1/4)))
               when permutationof(lowerind,{5/4,3/2,7/4}),

 hypergeometric({},~lowerind,~z) =>
          1/(8*z^(1/4))*(sinh(4*z^(1/4)) +sin(4*z^(1/4)))
               when permutationof(lowerind,{5/4,1/2,3/4}),

 hypergeometric({},~lowerind,~z) =>
          1/(16*z^(1/2))*(cosh(4*z^(1/4)) -cos(4*z^(1/4)))
             when permutationof(lowerind,{3/4,5/4,3/2}),

 hypergeometric({},~lowerind,~z) =>
          1/2*(cosh(4*z^(1/4)) + cos(4*z^(1/4)))
            when permutationof(lowerind,{1/4,1/2,3/4})
};


algebraic
<< hypergeometric_rules:=

{ hypergeometric({~a},{},~x) => (1-x)^(-a) when not(numberp x and x=1),

% F(a;b;z)

  hypergeometric({1/2},{5/2},~x) =>
        3/(4*x)*((1+2*x)/2*sqrt(pi/x)*erfi(sqrt(x))-e^x),

  hypergeometric({1},{1/2},~x) =>
        1+sqrt(pi*x)*e^x*erf(sqrt(x)),

  hypergeometric({1},{3/2},~x) =>
        1/2*sqrt(pi/x)*e^x*erf(sqrt(x)),

  hypergeometric({1},{5/2},~x) =>
        3/(2*x)*(1/2*sqrt(pi/x)*e^(x)*erf(sqrt(x))-1),

  hypergeometric({1},{7/2},~x) =>
        5/(4*x^2)*(3/2*sqrt(pi/x)*e^x*erf(sqrt(x))-3-2*x),

  hypergeometric({3/2},{5/2},-~x) =>
        e^(-x)*hypergeometric({1},{5/2},x),

  hypergeometric({3/2},{5/2},~x) =>
        3/(2*x)*(e^x-1/2*sqrt(pi/x)*erfi(sqrt(x))),

  hypergeometric({5/2},{7/2},-~x) =>
        e^(-x)*hypergeometric({1},{7/2},x),

  hypergeometric({7/2},{9/2},-~x) =>
        e^(-x)*hypergeometric({1},{9/2},x),

  hypergeometric({~a},{~b},~x) =>
        a*(-x)^(-a)*m_gamma(a,-x) when b = a + 1,

  hypergeometric({~a},{~b},~x) =>
        (a+1)*(e^(x)+(-x-a)*(-x)^(-a-1)*m_gamma(a+1,-x))
        when b = a + 2,

% F(a,b;c;z)

  hypergeometric({-1/2,1},{3/2},-~x) =>
       (1/2)*(1+(1+x)*(atan(sqrt(x))/sqrt(x))),

  hypergeometric({-1/2,1},{3/2},~x) =>
       (1/2)*(1+(1-x)*(atanh(sqrt(x))/sqrt(x))),

  hypergeometric({1/2,1},{5/2},-~x) =>
       (3/2*-x)*(1-(1+x)*(atan(sqrt(x))/sqrt(x))),

  hypergeometric({1/2,1},{5/2},~x) =>
       (3/2*x)*(1-(1-x)*(atanh(sqrt(x))/sqrt(x))),

  hypergeometric({~a + 1/2,~a},{1/2},~x) =>
    (1-x)^(-a)*cos(2*a*atan(sqrt(-x))),

  hypergeometric({5/4,3/4},{1/2},~x) =>
    (1-x)^(-3/4)*cos(3/2*atan(sqrt(-x))),

  hypergeometric({(~n+1)/2 + 1/2,(~n+1)/2},{1/2},~x) =>
     (1-x)^(-(n+1)/2)*cos((n+1)*atan(sqrt(-x))),


  hypergeometric({7/4,5/4},{3/2},~x) =>
     2/3*(1-x)^(-3/4)/sqrt(-x)*sin(3/2*atan(sqrt(-x))),

  hypergeometric({~a + 1/2,~a},{3/2},~x) =>
    ((1-x)^(1/2-a))/((2*a-1)*sqrt(-x))*sin((2*a-1)*atan(sqrt(-x))),

  hypergeometric({(~n+2)/2 + 1/2,(~n+2)/2},{3/2},~x) =>
    ((1-x)^(1/2-(n+2)/2))/((2*(n+2)/2-1)*sqrt(-x))*sin((2*(n+2)/2-1)
                                                *atan(sqrt(-x))),

% F(a;b,c;z);

  hypergeometric({-1/2},{1/2,1/2},-~x) =>
       cos(2*sqrt(x))+2*sqrt(x)*si(2*sqrt(x)),

  hypergeometric({-1/2},{1/2,1/2},~x) =>
       cosh(2*sqrt(x))-2*x*shi(2*sqrt(x)),

  hypergeometric({-1/2},{1/2,3/2},-~x) =>
       (1/2)*(cos(2*sqrt(x))+(sin(2*sqrt(x)))/(2*sqrt(x))
                                        +2*sqrt(x)*si(2*sqrt(x))),

  hypergeometric({-1/2},{1/2,3/2},~x) =>
       (1/2)*(cosh(2*sqrt(x))+(sinh(2*sqrt(x)))/(2*sqrt(x))
                                        -2*sqrt(x)*shi(2*sqrt(x))),

  hypergeometric({-1/2},{3/2,3/2},-~x) =>
       (1/4)*(cos(2*sqrt(x))+(sin(2*sqrt(x)))/(2*sqrt(x))
                                +(1+2*x)*(si(2*sqrt(x)))/sqrt(x)),

  hypergeometric({-1/2},{3/2,3/2},~x) =>
       (1/4)*(cosh(2*sqrt(x)) +(sinh(2*sqrt(x)))/(2*sqrt(x))
                                +(1-2*x)*(shi(2*sqrt(x)))/sqrt(x)),


  hypergeometric({1/2},{3/2,3/2},-~x) =>
       si(2*sqrt(x))/(2*sqrt(x)),

  hypergeometric({1/2},{3/2,3/2},~x) =>
       shi(2*sqrt(x))/(2*sqrt(x)),


  hypergeometric({1/2},{5/2,3/2},-~x) =>
       3/(8*-x)*(2*sqrt(x)*si(2*sqrt(x))-cos(2*sqrt(x))+
                                (sin(2*sqrt(x)))/(2*sqrt(x))),

  hypergeometric({1/2},{5/2,3/2},~x) =>
       3/(8*x)*(2*sqrt(x)*shi(2*sqrt(x))-cosh(2*sqrt(x))+
                                (sinh(2*sqrt(x)))/(2*sqrt(x))),


  hypergeometric({1},{3/4,5/4},~x) =>
    1/2*sqrt(pi/sqrt(-x))*(cos(2*sqrt(-x))*Fresnel_C(2*sqrt(-x))
        + sin(2*sqrt(-x))*Fresnel_S(2*sqrt(-x))),

  hypergeometric({1},{5/4,7/4},~x) =>
    3*sqrt(pi)/(8*(sqrt(-x))^(3/2))*(sin(2*sqrt(-x))
        *Fresnel_C(2*sqrt(-x))-cos(2*sqrt(-x))*Fresnel_S(2*sqrt(-x))),

  hypergeometric({5/2},{7/2,7/2},-~x) =>
       (75/(16*x^2))*(3*si(2*sqrt(x))/(2*sqrt(x))
                - 2*sin(2*sqrt(x))/sqrt(x) + cos(2*sqrt(x))),

  hypergeometric({5/2},{7/2,7/2},~x) =>
       (75/(16*x^2))*(3*shi(2*sqrt(x))/(2*sqrt(x))
                        - 2*sinh(2*sqrt(x))/sqrt(x) + cosh(2*sqrt(x))),


  hypergeometric({~a},{~b,3/2},~x) =>
    -2^(1-2*a)*a*(sqrt(-x))^(-2*a)*
                (gamma(2*a-1)*cos(a*pi)+Fresnel_S(2*sqrt(-x),2*a-1))

    when b = a + 1,

  hypergeometric({~a},{~b,1/2},~x) =>
    2^(1-2*a)*a*(sqrt(-x))^(-2*a)*
                (gamma(2*a)*cos(a*pi)-Fresnel_C(2*sqrt(-x),2*a))

    when b = a + 1
};

let hypergeometric_rules;

operator poisson!-charlier, toronto;

let { toronto(~m,~n,~x) =>
           gamma(m/2 + 1/2)/factorial n * x^(2*n-2*m+1)*exp(-x^2) *
           KummerM(m/2+1/2,1+n,x^2),

      poisson!-charlier(~n,~nu,~x) =>
           Pochhammer(1 + nu-n,n)/(sqrt factorial n * x^(n/2))*
               sum(Pochhammer(-n,i)*x^i/
                (Pochhammer(1+nu-n,i) * factorial i)
           ,i,0,n)
    };
>>;


endmodule;

end;




