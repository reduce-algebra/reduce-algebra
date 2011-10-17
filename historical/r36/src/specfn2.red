module specfn2;  % Part 2 of the Special functions package for REDUCE.
                 % The special Special functions.

% Author : Victor Adamchik, Byelorussian University Minsk, Byelorussia.

% Major modifications by: Winfried Neun, ZIB Berlin.


%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     Please report bugs to Winfried Neun,                       %
%                           Konrad-Zuse-Zentrum                  %
%                              fuer Informationstechnik Berlin,  %
%                           Heilbronner Str. 10                  %
%                           10711 Berlin - Wilmersdorf           %
%                           Federal Republic of Germany          %
%     or by email, neun@sc.ZIB-Berlin.de                         %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     This package provides algebraic                            %
%     manipulations upon some special functions:                 %
%                                                                %
%              -- Generalized Hypergeometric Functions           %
%              -- Meijer's G Function                            %
%              -- to be extended                                 %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %


create!-package ('(specfn2 ghyper meijerg),
                 '(contrib specfn));

load_package specfn;

%  Various help utilities and smacros for hypergeometric function
%  simplification.

symbolic smacro procedure diff1sq(u,v);
   addsq(u,negsq(v))$

symbolic smacro procedure mksqnew u;
  !*p2f(car fkern(u) .* 1) ./ 1;

symbolic smacro procedure gamsq(u);
 mksqnew('gamma . list(prepsq u));

symbolic smacro procedure multgamma u;
   %u -- list of SQ.
   <<for each pp in u do <<p := multsq(gamsq pp,p)>>; p>>
     where p = '(1 . 1);

symbolic smacro procedure besssq(v,u);
 mksqnew('besselj . list(prepsq v,prepsq u))$

symbolic smacro procedure bessmsq(v,u);
 mksqnew('besseli . list(prepsq v,prepsq u))$

symbolic smacro procedure simppochh(v,u);
 mksqnew('pochhammer . list(prepsq v,prepsq u))$

symbolic procedure multpochh(u,k);
 << for each pp in u do <<p := multsq (simppochh (pp,k),p)>>; p>>
                 where p = '(1 . 1);

symbolic smacro procedure psisq(v);
 mksqnew('psi . list(prepsq v))$

symbolic smacro procedure dfpsisq(v,u);
 mksqnew('dfpsi . list(prepsq v,prepsq u))$

symbolic procedure simpfunc(u,v);
 % u -- name of the function, PF.
 % v -- argument, SQ.
 begin scalar l,v1!wq;
 v1!wq:=prepsq v; l:=('a . v1!wq);
 u:=subf(car simp!* list(u,'a),list l);
 return u $
end$

algebraic operator intsin,intcos,ints,intfs,intfc$

symbolic procedure subsqnew(u,v,z);
% u,v -- SQ.
% z -- PF  .
begin scalar a!1,lp,a;
  a!1:=prepsq v; lp:=((z . a!1));
  a:=quotsq(subf(car u,list lp),subf(cdr u,list lp));
  return a;
end$

symbolic procedure expdeg(x,y);
% x,y -- SQ.
% value is the x**y.
 if null car y then '(1 . 1) else
 if numberp(car y) and numberp(cdr y) then
             simpx1(prepsq x,car y,cdr y) else
 quotsq(expdeg1(car x ./ 1 ,y),expdeg1(cdr x ./ 1 ,y))$

symbolic procedure expdeg1(x,y);
% x,y -- SQ.
% value is the x**y.
simp!*(prepsq(subsqnew(subsqnew(simp!*
      '(expt a!g9 b!!g9),x,'a!g9),y,'b!!g9)))$

symbolic smacro procedure difflist(u,v);
 % u -- list of SQ.
 % v -- SQ.
 % value is (u) - v.
 for each uu in u collect addsq(uu,negsq v);

symbolic procedure listplus(u,v);
% value is (u) + v.
 difflist(u,negsq v)$

 symbolic smacro procedure addlist u;
  % u -- list of PF.
  <<for each pp in u do <<p := addsq(simp!* pp,p)>>; p>>
    where p = '(nil . 1);

 symbolic smacro procedure listsq(u);
 % u - list of PF.
 % value is list of SQ.
 for each uu in u collect simp!* uu;

symbolic smacro procedure listmin(u);
 % u - list.
 % value is (-u).
 for each uu in u collect negsq uu;

symbolic smacro procedure multlist(u);
<< for each pp in u do <<p := multsq(pp,p)>>; p>> where p = '(1 . 1);

symbolic procedure parfool u;
  % u -- SQ.
  % value is T if u = 0,-1,-2,...
  if null car u then t
    else
  if and(numberp car u,eqn(cdr u,1),lessp(car u,0)) then t
    else nil$

 symbolic procedure znak u;
 % u -- SQ.
  if numberp u then
     if u > 0 then t else nil
               else
  if numberp car u then
     if car u > 0 then t else nil
                   else
  if not null cdar u then t
                     else
  if numberp cdaar u then
     if cdaar u > 0 then t else nil
                     else
     znak(cdaar u ./ 1)$

 symbolic procedure sdiff(a,b,n);
  % value is (1/b*d/db)**n(a)   .
  % a,n--SQ  b--PF              .
  if null car n then a else
  if and(numberp(car n),numberp(cdr n),eqn(cdr n,1),not lessp(car n,0))
                                        then
     multsq(invsq(simp!* b), diffsq(sdiff(a,b,diff1sq(n, '(1 . 1))),b))
     else
  rerror('specialf,130,"***** error parameter in sdiff")$

 symbolic procedure derivativesq(a,b,n);
  % a -- SQ.
  % b -- ATOM.
  % n -- order, SQ.
 if null n or null car n then a
 else derivativesq(diffsq(a,b),b,diff1sq(n,'(1 . 1)))$

 symbolic procedure addend( u,v,x);
  % u,v -- lists of SQ.
  % x -- SQ.
  cons(diff1sq(car u,x),difflist(v,diff1sq(car u,x)))$

 symbolic procedure parlistfool(u,v);
  %v -- list.
  %value is the T if u-(v)=0,-1,-2,...
  if null v then nil else
  if parfool(diff1sq(u,car v)) then t else
     parlistfool(u,cdr v)$

 symbolic procedure listparfool(u,v);
  %u -- list.
  %value is the T if (u)-v=0,-1,-2,...
  if null u then nil else
  if parfool(diff1sq(car u,v)) then t else
     listparfool(cdr u,v)$

 symbolic procedure listfool u;
  %u -- list.
  %value is the T if any two of the terms (u)
  %differ by an integer or zero.
  if null cdr u then nil else
  if parlistfool(car u,cdr u) or listparfool(cdr u,car u)
     then t else listfool(cdr u)$

 symbolic procedure listfooltwo(u,v);
  %u,v -- lists.
  %value is the T if (u)-(v)=0,-1,-2,...
  if null u then nil else
  if parlistfool(car u,v) then t else
     listfooltwo(cdr u,v)$

 symbolic smacro procedure pdifflist(u,v);
  % u -- SQ.
  % v -- list of SQ.
  %value is a list: u-(v).
 for each vv in v collect diff1sq(u,vv);

symbolic procedure redpar1(u,n);
 % value is a paire, car-part -- sublist of the length n
 %                   cdr-part --  .
 begin scalar bm;
  while u and not(n=0) do begin
    bm:=cons (car u,bm);
    u:=cdr u;
    n:=n-1;
  end;
  return cons(reverse bm,u);
end$

symbolic procedure redpar (l1,l2);
   begin scalar l3;
   while l2 do <<
         if member(car l2 , l1) then l1 := delete(car l2,l1)
                 else l3 := (car l2) . l3 ;
         l2 := cdr l2 >>;
   return list (l1,reverse l3);
   end;

algebraic operator lommel,heaviside;

symbolic smacro procedure heavisidesq(u);
 mksqnew('heaviside . list(prepsq u));

symbolic smacro procedure struvelsq(v,u);
 mksqnew('struvel . list(prepsq v,prepsq u));

symbolic smacro procedure struvehsq(v,u);
 mksqnew('struveh . list(prepsq v,prepsq u));

symbolic smacro procedure besssq(v,u);
 mksqnew('besselj . list(prepsq v,prepsq u));

symbolic smacro procedure bessmsq(v,u);
 mksqnew('besseli . list(prepsq v,prepsq u));

symbolic smacro procedure neumsq(v,u);
 mksqnew('bessely . list(prepsq v,prepsq u));

symbolic smacro procedure simppochh(v,u);
 mksqnew('pochhammer . list(prepsq v,prepsq u));

symbolic smacro procedure psisq(v);
 mksqnew('psi . list(prepsq v));

symbolic smacro procedure dfpsisq(v,u);
 mksqnew('polygamma . list(prepsq u,prepsq v));

symbolic smacro procedure lommel2sq (u,v,w);
 mksqnew('lommel2  . list(prepsq u,prepsq v,prepsq w));

symbolic smacro procedure tricomisq (u,v,w);
 mksqnew('kummeru . list(prepsq u,prepsq v,prepsq w));

symbolic smacro procedure macdsq (v,u);
 mksqnew('besselk . list(prepsq v,prepsq u));

fluid '(v1!wq,a!g9,b!!g9);

symbolic smacro procedure sumlist u;
   % u -- list of the PF
   <<for each pp in u do <<p := addsq(simp pp,p)>>; p>>
    where p = '(nil . 1);

symbolic smacro procedure difflist(u,v);
 % u -- list of SQ.
 % v -- SQ.
 % value is (u) - v.
 for each uu in u collect addsq(uu,negsq v);

symbolic smacro procedure addlist u;
   % u -- list of PF.
   <<for each pp in u do <<p := addsq(simp!* pp,p)>>; p>>
    where p = '(nil . 1);

symbolic smacro procedure diff1sq(u,v);
  addsq(u,negsq(v));

symbolic smacro procedure listsq(u);
 % u - list of PF.
 % value is list of SQ.
 for each uu in u collect simp!* uu;

symbolic smacro procedure listmin(u);
 % u - list.
 % value is (-u).
 for each uu in u collect negsq uu;

symbolic smacro procedure multlist(u);
<< for each pp in u do <<p := multsq(pp,p)>>; p>> where p = '(1 . 1);

symbolic smacro procedure pdifflist(u,v);
  % u -- SQ.
  % v -- list of SQ.
  %value is a list: u-(v).
 for each vv in v collect diff1sq(u,vv);

symbolic smacro procedure listprepsq(u);
 for each uu in u collect prepsq uu;

endmodule;


module ghyper;   % Generalized Hypergeometric Functions.

% Author : Victor Adamchik, Byelorussian University Minsk, Byelorussia.

% Major modifications by: Winfried Neun, ZIB Berlin.


 put('ghf,'simpfn,'simpghf)$

   symbolic procedure simpghf u;
   if null cddr u then
        rerror('specialf,125,
              "***** WRONG NUMBER OF ARGUMENTS TO GHF-FUNCTION")
       else
   if or(not numberp car u,not numberp cadr u) then
        rerror('specialf,126,"***** INVALID AS INTEGER")
       else
   begin scalar vv,v;
   v:=redpar1(cddr u,car u);
   vv:=redpar1(cdr v,cadr u);
   if null cddr vv then return
      ghfsq(list(car u,cadr u),listsq car v,
      listsq car vv, simp cadr vv);
      return rerror ('specialf,127,
        "***** WRONG NUMBER OF ARGUMENTS TO GHF-FUNCTION");
   end$

 symbolic procedure ghfexit(a,b,z);
 begin scalar aa,bb;
  aa:= 'list . listprepsq a;
  bb:= 'list . listprepsq b;
  return mksqnew('hypergeometric .
        append(list(aa,bb),list(prepsq z)))$
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
 if greaterp(caar u,caadr u) or equal(car u,cadr u) then
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
     <<rerror('special,124,
                "***** zero in the denominator of the GHF-function");
       b:=a; a:=u;
       return ghfexit(a,b,z);
     >>
   else b:=a;
  k:=1;  s:=1 . 1;
m:
    s:=addsq(s,quotsq(multsq(multpochh(u,simp k),exptsq(z,k)),
        multpochh(append(list('(1 . 1)),b),simp k)));
    k:=k+1;
    if greaterp(k,car negsq(car u)) then return s else goto m;
   end$

%***********************************************************************
%*                   Lowering of the order GHF                         *
%***********************************************************************

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
      if numberp(prepsq diff1sq(car a,car b)) and
         greaterp(car(diff1sq(car a,car b)),0) then
                        <<
                         b:=car b . append(w2,cdr b);
                         a:=diff1sq(car a,car b) . append(w1,cdr a);
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
  addsq(ghfsq(u,append(list(diff1sq(addsq(car x,car y),'(1 . 1))),
                            cdr x),
                append(list(car y),cdr y),z),
        multsq(ghfsq(u,append(list(addsq(car x,car y)),listplus(cdr x,
                        '(1 . 1))),
                       append(list(addsq(car y,'(1 . 1))),
                              listplus(cdr y,'(1 . 1))),z),
               quotsq(multsq(z,multlist(cdr x)),
                      multsq(car y,multlist(cdr y)))))$

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
      if numberp(prepsq diff1sq(car b,car a)) and
         lessp(car(diff1sq(car a,car b)),0) then
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
  diff1sq(multsq(ghfsq(u,append(list(caar x,addsq('(1 . 1),cadar x)),
                        cdr x),b,z),
                  quotsq(cadar x,diff1sq(cadar x,caar x))),
           multsq(ghfsq(u,append(list(addsq('(1 . 1),caar x),cadar x),
                        cdr x),b,z),
                  quotsq(caar x,diff1sq(cadar x,caar x))))$

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
         diff1sq(ghfsq(u, (car a) . difflist(cdr a,'(1 . 1)),
                         difflist(b,'(1 . 1)),z),
                 ghfsq(u,append(list(diff1sq(car a,'(1 . 1))),
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
   if null car(z) then return '(1 . 1) else
   if listparfool(b,(nil .1)) and not listparfool(a,(nil . 1)) then
      return rerror('specialf,128,
        "***** zero in the denominator of the GHF-function")
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
          return expdeg(diff1sq('(1 . 1),z),if null a then '(nil . 1)
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
                               diff1sq(car b,'(1 . 1)), z);
 end$

 symbolic procedure formulaformidcase(p,b,a,z);
 if not(p = 1) and b = '(1 . 1) and z = '(1 . 1) then
        multsq(simpx1(prepsq(multsq('(-1 . 1),a)),p,1),
               quotsq(dfpsisq(a,simp(p-1)),gamsq(simp p)))
   else
 if b = '(1 . 1) and z='(-1 . 1) then
    quotsq(multsq(simpx1(prepsq(multsq('(-1 . 2),a)),p,1),
               diff1sq(dfpsisq(multsq(a, '(1 . 2)),simp(p-1)),
                    dfpsisq(multsq(addsq('(1 . 1),a),'(1 . 2)),
                            simp(p-1)))),
           gamsq(simp p))
   else
 if z = '(1 . 1) and not numberp(prepsq b) then
    multsq(
    subsqnew(
     derivativesq(
       quotsq(gamsq(simp 'r),gamsq(addsq(simp 'r,diff1sq('(1 . 1),b)))),
       'r,simp(p-1)),
     a,'r),
    quotsq(
      multsq(multsq(simpx1(prepsq(multsq('(-1 . 1),a)),p,1), '(-1 . 1)),
             gamsq(diff1sq('(1 . 1),b))),
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
                simppochh(diff1sq(simp(1+k),simp 'r),
                          simp(prepsq(b)-1-k))));
                k:=k-1
                >>;
              c
             >>,
             quotsq(
               multsq(gamsq(diff1sq(b,simp 'r)),
                diff1sq(psisq(multsq(addsq(simp 'r,'(1 . 1)),'(1 . 2))),
                             psisq(multsq(simp 'r,'(1 . 2))))),
               multsq((2 . 1), gamsq(diff1sq('(1 . 1),simp 'r))))),
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
   multsq(gamsq(car b),multsq(bessmsq(diff1sq(car b,'(1 . 1)),
   multsq('(2 . 1),simpx1(prepsq z,1,2))),
          expdeg(z,quotsq(diff1sq('(1 . 1),car b),'(2 . 1)))))
                     else
   multsq(gamsq(car b),multsq(besssq(diff1sq(car b,'(1 . 1)),
   multsq('(2 . 1),simpx1(prepsq(negsq z),1,2))),expdeg(negsq z,
   quotsq(diff1sq('(1 . 1),car b),'(2 . 1))))) $

  symbolic procedure ghf11(a,b,z);
  if equal(car b,multsq('(2 . 1),car a)) then
     multsq(multsq(gamsq(addsq('(1 . 2),car a)),expdeg(simp 'e,
                       multsq(z,'(1 . 2)))),
            multsq(expdeg(multsq(z,'(1 . 4)),diff1sq('(1 . 2),car a)),
                   bessmsq(diff1sq(car a,'(1 . 2)),multsq(z,'(1 . 2)))))
  else
  if equal(car a,'(1 . 2)) and equal(car b,'(3 . 2)) then
     multsq(quotsq(simpx1('pi,1,2),'(2 . 1)),
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
%       multsq(simpfunc('log,diff1sq('(1 . 1),simpx1(prepsq z,1,2))),
%       multsq('(2 . 1),simpx1(prepsq z,1,2)))) else
     if not equal(z,'(1 . 1)) then
       multsq(simpfunc('log,quotsq(addsq('(1 . 1),simpx1(prepsq z,1,2)),
                            diff1sq('(1 . 1),simpx1(prepsq z,1,2)))),
              invsq(multsq('(2 . 1),simpx1(prepsq z,1,2)))) else
    ghfexit(a,b,z)
    >>
    else
  if and(equal(car a,'(1 . 1)),equal(cadr a,'(1 . 1)),
         equal(car b,'(2 . 1)),not equal(z,'(1 . 1)))
    then
       quotsq(simpfunc('log,addsq('(1 . 1),negsq z)),negsq z)
    else
  if equal(diff1sq(addsq(car a,cadr a),car b),'(-1 . 2)) and
     (equal(multsq('(2 . 1),car a),car b) or
      equal(multsq('(2 . 1),cadr a),car b))
    then
       multsq(expdeg(addsq('(1 . 1),
              simpx1(prepsq(diff1sq('(1 . 1),z)),1,2)),
       diff1sq('(1 . 1),car b)),expdeg('(2 . 1),addsq(car b,'(-1 . 1))))
    else
  if z='(1 . 1)
     and (not numberp prepsq diff1sq(car b,addsq(car a, cadr a))
          or prepsq(diff1sq(car b,addsq(car a, cadr a))) > 0 )
    then quotsq(multsq(gamsq(car b),
                       gamsq(diff1sq(car b,addsq(car a,cadr a))) ),
                multsq(gamsq(diff1sq(car b,car a)),
                       gamsq(diff1sq(car b,cadr a))))
    else
  if car a='(1 . 1) and cadr a='(1 . 1) and numberp prepsq car b and
     prepsq car(b) > 0 and not(z='(1 . 1)) then
        formula136(prepsq car b,z) else
ghfexit(a,b,z)$

 symbolic procedure formula136(m,z);
 begin scalar c; integer k;
 c:='(nil . 1); k:=2;
 while k<=m-1 do
   << c:=addsq(c,quotsq(exptsq(diff1sq(z,'(1 . 1)),k),
                        multsq(exptsq(z,k),simp(m-k))));
      k:=k+1
   >>;
 c:=diff1sq(c,multsq(exptsq(quotsq(diff1sq(z,'(1 . 1)),z),m),
                     simpfunc('log,diff1sq('(1 . 1),z))));
 return
  multsq(c,
         quotsq(multsq(simp(m-1),z),exptsq(diff1sq(z,'(1 . 1)),2)));
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

symbolic smacro procedure fehler();
        rerror('specialf,139,"Wrong arguments to hypergeometric");

symbolic procedure hypergeom(u);

begin scalar list1,list2,res,res1;

if not (length(u) = 3) then fehler();
if pairp u then list1 :=car u else fehler();
if pairp cdr u then list2 := cadr u else fehler();
if not pairp cddr u then  fehler();

if not eqcar(list1,'list) then fehler();
if not eqcar(list2,'list) then fehler();

list1 := for each x in cdr list1 collect simp reval x;
list2 := for each x in cdr list2 collect simp reval x;
res := ghfsq(list (length list1,length list2),
                        list1,list2,simp caddr u);
res1 := prepsq res;
return if eqcar(res1,'hypergeometric) then res else simp res1;
                        end;

put('hypergeometric,'simpfn,'hypergeom);

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
    1/2*sqrt(pi/sqrt(-x))*(cos(2*sqrt(-x))*fresnel_c(2*sqrt(-x))
        + sin(2*sqrt(-x))*fresnel_s(2*sqrt(-x))),

  hypergeometric({1},{5/4,7/4},~x) =>
    3*sqrt(pi)/(8*(sqrt(-x))^(3/2))*(sin(2*sqrt(-x))
        *fresnel_c(2*sqrt(-x))-cos(2*sqrt(-x))*fresnel_s(2*sqrt(-x))),

  hypergeometric({5/2},{7/2,7/2},-~x) =>
       (75/(16*x^2))*(3*si(2*sqrt(x))/(2*sqrt(x))
                - 2*sin(2*sqrt(x))/sqrt(x) + cos(2*sqrt(x))),

  hypergeometric({5/2},{7/2,7/2},~x) =>
       (75/(16*x^2))*(3*shi(2*sqrt(x))/(2*sqrt(x))
                        - 2*sinh(2*sqrt(x))/sqrt(x) + cosh(2*sqrt(x))),


  hypergeometric({~a},{~b,3/2},~x) =>
    -2^(1-2*a)*a*(sqrt(-x))^(-2*a)*
                (gamma(2*a-1)*cos(a*pi)+fresnel_s(2*sqrt(-x),2*a-1))

    when b = a + 1,

  hypergeometric({~a},{~b,1/2},~x) =>
    2^(1-2*a)*a*(sqrt(-x))^(-2*a)*
                (gamma(2*a)*cos(a*pi)-fresnel_c(2*sqrt(-x),2*a))

    when b = a + 1
};

let hypergeometric_rules;

operator poisson!-charlier, toronto;

let { toronto(~m,~n,~x) =>
           gamma(m/2 + 1/2)/factorial n * x^(2*n-2*m+1)*exp(-x^2) *
           kummerm(m/2+1/2,1+n,x^2),

      poisson!-charlier(~n,~nu,~x) =>
           pochhammer(1 + nu-n,n)/(sqrt factorial n * x^(n/2))*
           sum(pochhammer(-n,i)*x^i/
                (pochhammer(1+nu-n,i) * factorial i)
           ,i,0,n)
    };
>>;


endmodule;


module meijerg;  % Meijer's G-function.

% Author : Victor Adamchik, Byelorussian University Minsk, Byelorussia.

% Major modifications by: Winfried Neun, ZIB Berlin.

symbolic smacro procedure fehler();
        rerror('specialf,140,"Wrong arguments to operator MeijerG");

symbolic procedure simpmeijerg(u);

begin scalar list1,list2,list1a,list2a;

if pairp u then list1 :=car u else fehler();
if pairp cdr u then list2 := cadr u else fehler();
if not pairp cddr u then  fehler();

if not eqcar(list1,'list) then fehler();
if not eqcar(list2,'list) then fehler();

list1a := for each x in cdadr list1 collect simp reval x;
list2a := for each x in cdadr list2 collect simp reval x;

list1 := list1a . for each x in cddr list1 collect simp reval x;
list2 := list2a . for each x in cddr list2 collect simp reval x;

list1 :=gfmsq(list1,list2,simp caddr u);

if list1 = 'fail then return simp 'fail else
        list1 := prepsq list1;

if eqcar(list1,'meijerg) then return list1 else return
                simp list1;
                        end;

put('meijerg,'simpfn,'simpmeijerg);

if not getd('simpmeijerg) then
        flag('(f6 f8 f9 f10 f11 f12 f13 f14 f26 f27 f28 f29 f30
        f31 f32 f33 f34 f35 f36 f37 f38 f39),'internalfunction);

switch tracespecfns;

symbolic procedure gfmsq(a,b,z);
 begin scalar v1,v2; integer m,n,p,q,aa,bb;
  v1:=redpar(car b,cdr a);
  v2:=redpar(cdr b,car a);
  aa:= (cadr v2 . cadr v1);
  bb:= (car v1 . car v2);
  a := append (car aa,cdr aa);
  b := append (car bb,cdr bb);
  m:=length(car v1); n:=length(cadr v2);
  q:=m + length(car v2); p:=n + length(cadr v1);   %WN
  if !*tracespecfns then
        << prin2 list( "MeijerG<",m,n,p,q,">",a,"|",b,"|",z,"|aa=",aa,
                       "|bb=",bb);
        terpri()>>;
  if p=0 and q=0 then return
        << rerror('specialf,141,"DIVERGENT INTEGRAL");
          'fail
        >>;
  if greaterp(p,q) then return gfminvers(aa,bb,z) else
  if greaterp(q,3) or greaterp(p,3) then return
     simpgtoh(aa,bb,z) else
  if q=3 and p=1 then go to q3 else
  if q=2 and (p=0 or p=1) then go to q2 else
  if q=1 then go to q1 else
          return simpgtoh(aa,bb,z);

q1:if p=0 and n=0 and m=1 then return
      multsq(expdeg(z,car b),expdeg(simp!* 'e,negsq z)) else

   if p=1 and n=0 and m=1 and null caar b and car a = '(1 . 1)
        then return gfmexit(aa,bb,z) else
        % change in order to make defint(cos(x) *sin(x)/x) correct. WN

   if p=1 and n=0 and m=1 then return % WN
       multsq (heavisidesq diff1sq('(1 . 1),z),
               quotsq(multsq(expdeg(z,car b),
           expdeg(diff1sq('(1 . 1),z),
                  diff1sq(car a,addsq('(1 . 1),car b)))),
            gamsq(diff1sq(car a,car b))))
      else
   if p=1 and n=1 and m=0 then return  %WN
           multsq(heavisidesq diff1sq(z,'(1 . 1)),
            quotsq(multsq(expdeg(z,car b),expdeg(diff1sq
            (z,'(1 . 1)),diff1sq(car a,addsq('(1 . 1),car b)))),
            gamsq(diff1sq(car a,car b))))
   else
   if p=1 and n=1 and m=1 then return
      multsq(gamsq(diff1sq('(1 . 1),diff1sq(car a,car b))),
             multsq(expdeg(z,car b),expdeg(addsq('(1 . 1),z),
                      diff1sq(car a,addsq('(1 . 1),car b)))))
            else return  rerror('specialf,142,
                        "***** parameter error in G-function");
q2:  if p=2 then  return  simpgtoh(aa,bb,z) else
     if p=1 then go to q2p1 else
     if p=0 and m=1 then return f6(car b,cadr b,z) else
     if p=0 and m=2 then return f8(car b,cadr b,z) else
               return  rerror('specialf,143,
                        "***** parameter error in G-function");

q2p1: if m=1 and n=0 then return q2p1m1n0(a,b,z) else
      if m=2 and n=0 then return q2p1m2n0(a,b,z) else
      if m=2 and n=1 then return q2p1m2n1(a,b,z) else
                      return simpgtoh(aa,bb,z);

q3:   if p=1 then go to q3p1 else
                      return simpgtoh(aa,bb,z);

q3p1: if m=1 and n=1 then return q3p1m1n1(a,b,z) else
      if m=2 and n=0 then return q3p1m2n0(a,b,z) else
      if m=2 and n=1 then return q3p1m2n1(a,b,z) else
      if m=3 and n=0 then return q3p1m3n0(a,b,z) else
      if m=3 and n=1 then return q3p1m3n1(a,b,z) else
                      return simpgtoh(aa,bb,z);
end;

symbolic procedure gfminvers(a,b,z);
  gfmsq( (pdifflist(('1 . 1),car b) . pdifflist('(1 . 1),cdr b)),
         (pdifflist('(1 . 1),car a) . pdifflist('(1 . 1),cdr a)),
         invsq z);

symbolic procedure f6(a,b,z);
  multsq(expdeg(z,multsq('(1 . 2),addsq(a,b))),besssq(diff1sq(a,b),
  multsq('(2 . 1),simpx1(prepsq z,1,2))));

symbolic procedure f8(a,b,z);
  multsq('(2 . 1),multsq(expdeg(z,multsq('(1 . 2),addsq(a,b))),
         macdsq(diff1sq (a,b),multsq('(2 . 1),simpx1(prepsq z,1,2)))));

%***********************************************************************
%*     Representation G-function through hypergeometric functions      *
%***********************************************************************

symbolic procedure simpgtoh(a,b,z);
   %a=((a1,,,an).(an+1,,,ap)).
   %b=((b1,,,bm).(bm+1,,,bq)).
   %z -- argument.
   %value is the generalized hypergeometric function.
   if length(car b) + length(cdr b) >= length(car a) + length(cdr a)
     then fromgtoh(a,b,z)
   else
      fromgtoh(
        cons(pdifflist('(1 . 1),car b),pdifflist('(1 . 1),cdr b)),
        cons(pdifflist('(1 . 1),car a),pdifflist('(1 . 1),cdr a)),
        invsq z);

%symbolic procedure fromGtoH(a,b,z);
   %a=((a1,,,an).(an+1,,,ap)).
   %b=((b1,,,bm).(bm+1,,,bq)).
   %z -- argument.
   %value is the generalized hypergeometric function.
%   if null car b then gfmexit(a,b,z)
%     else
%   if not null a and listfooltwo(difflist(car b,'(-1 . 1)),car a)
%      then 'FAIL
%     else
% dont understand this W.N.
% but reopened nevertheless
%  if length(car b) > length(car a) then
%     fromGtoH(
%     (pdifflist('(1 . 1),car b ) . pdifflist('(1 . 1),cdr b )),
%     (pdifflist('(1 . 1),car a ) . pdifflist('(1 . 1),cdr a )),
%     invsq(z))
%    else
%  if listfool(car b) then GFMlogcase(a,b,z)
%                    else allsimplpoles(car b,a,b,z);

symbolic procedure fromgtoh(a,b,z);
  %a=((a1,,,an).(an+1,,,ap)).
  %b=((b1,,,bm).(bm+1,,,bq)).
  %z -- argument.
  %value is the generalized hypergeometric function.
  if null car b then gfmexit(a,b,z)
    else
  if not null a and listfooltwo(difflist(car b,'(-1 . 1)),car a)
     then 'fail
    else
 if listfool(car b) then gfmlogcase(a,b,z)

 else
  if length car a + length cdr a <= length car b + length cdr b then
      allsimplpoles(car b,a,b,z) else allsimplpoles(car a,a,b,z);

symbolic procedure gfmexit(a,b,z);
 begin scalar mnpq,aa,bb;
  if (length car a + length cdr a) > (length car b + length cdr b)
                then return gfmexitinvers(a,b,z);
   mnpq := 'lst . list(length car b,length car a,
                       length car a + length cdr a,
                       length car b + length cdr b);
  aa:= 'lst . append (listprepsq car a, listprepsq cdr a);
  bb:= 'lst . append (listprepsq car b, listprepsq cdr b);
  return mksqnew('gfm .
        list(mnpq,aa,bb,prepsq z));
  end;

symbolic procedure gfmexitinvers(a,b,z);
  gfmexit((pdifflist('(1 . 1),car b) . pdifflist('(1 . 1),cdr b)),
          (pdifflist('(1 . 1),car a) . pdifflist('(1 . 1),cdr a)),
           invsq z) ;

symbolic procedure allsimplpoles(v,a,b,z);
  if null v then '(nil . 1) else
     addsq(infinitysimplpoles(a,(car redpar(car b,list(car v)) . cdr b)
                        ,car v,z),
            allsimplpoles(cdr v,a,b,z));

symbolic procedure infinitysimplpoles(a,b,v,z);
 begin scalar coefgam;
   coefgam:=
     quotsq(
       multsq(
         multgamma(difflist(car b,v)),
         if null a or null car a then '(1 . 1) else
           multgamma(pdifflist(addsq('(1 . 1),v), car a))),
       multsq(
         if null cdr b then '(1 . 1) else
           multgamma(pdifflist(addsq('(1 . 1),v),cdr b)),
         if null a or null cdr a then '(1 . 1) else
           multgamma(difflist(cdr a,v))));
  return multsq(multsq(coefgam,expdeg(z,v)),
            ghfsq(list(length(car a) + length(cdr a),
                       length(car b) + length(cdr b)),
             if null a then nil else
             if null car a then pdifflist(addsq('(1 . 1),v),cdr a)
               else
             append(pdifflist(addsq('(1 . 1),v),car a),
                    pdifflist(addsq('(1 . 1),v),cdr a)),
             if null cdr b then
                    pdifflist(addsq('(1 . 1),v),car b)
               else
             append(pdifflist(addsq('(1 . 1),v),car b),
                    pdifflist(addsq('(1 . 1),v),cdr b)),
             multsq(z,
             exptsq('(-1 . 1),1+length(cdr a)-length(car b)))));
end;

%***********************************************************************
%*            PARTICULAR CASES FOR G-FUNCTION, Q=2                     *
%***********************************************************************

symbolic procedure q2p1m1n0(a,b,z);
  begin scalar v;
  v:=addend(a,b,'(1 . 2));
  if null car addsq(cadr v,caddr v) then
                 return f7(car v,cadr v,z) else
                 return simpgtoh((nil . a),redpar1(b,1),z);
  end;

symbolic procedure f7(a,b,z);
  multsq(quotsq(simpfunc('cos,multsq(b,simp!* 'pi)),simpx1('pi,1,2)),
  multsq(expdeg(z,a),multsq(expdeg(simp!* 'e,multsq(z,'(1 . 2))),
  bessmsq(b,multsq(z,'(1 . 2))))));

  symbolic procedure q2p1m2n0(a,b,z);
  begin scalar v;
  v:=addend(a,b,'(1 . 2));
    if null car addsq(cadr v,caddr v) then
                return f9(car v,cadr v,z) else
                return f11(car a,car b,cadr b,z);
 end;

symbolic procedure f9(a,b,z);
   multsq(quotsq(expdeg(z,a),simpx1('pi,1,2)),
     multsq(expdeg(simp!* 'e,multsq(
       '(1 . 2),negsq z)),macdsq(b,multsq(z,'(1 . 2)))));

 symbolic procedure f11(a,b,c,z);
 multsq(expdeg(z,b),multsq(expdeg(simp!* 'e,negsq z),
        tricomisq(diff1sq(a,c),addsq('(1 . 1),diff1sq(b,c)),z)));

symbolic procedure q2p1m2n1(a,b,z);
 begin scalar v;
 v:=addend(a,b,'(1 . 2));
 if null car addsq(cadr v,caddr v) and
    ((equal(cdadr v,2) and not numberp(cadar v)) or
    not equal(cdadr v,2)) then
               return f10(car v,cadr v,z) else
               return simpgtoh((a . nil),(b . nil),z);
 end;

symbolic procedure f10(a,b,z);
  multsq(quotsq(simpx1('pi,1,2),simpfunc('cos,multsq(simp!* 'pi,b))),
  multsq(expdeg(z,a),multsq(expdeg(simp!* 'e,multsq('(1 . 2),z)),
  macdsq(b,multsq('(1 . 2),z)))));

%***********************************************************************
%*                PARTICULAR CASES FOR G-FUNCTION, Q=3                 *
%***********************************************************************

symbolic procedure q3p1m2n1(a,b,z);
  begin scalar v,v1;
    if equal(diff1sq(car a,caddr b),'(1 . 2)) then
    if equal(car a,car b) and
       ((equal(cdr diff1sq(cadr b,caddr b),2) and
       not numberp(car diff1sq(cadr b,caddr b))) or
       not equal(cdr diff1sq(cadr b,caddr b),2))
                         then return f34(caddr b,cadr b,z) else
    if equal(car a,cadr b) and
       ((equal(cdr diff1sq(car b,caddr b),2) and
       not numberp(car diff1sq(car b,caddr b))) or
       not equal(cdr diff1sq(car b,caddr b),2))
                         then return f34(caddr b,car b,z) else goto m;
    if equal(diff1sq(car a,car b),'(1 . 2)) and equal(car a,cadr b) then
                              return f35(car b,caddr b,z) else
    if equal(diff1sq(car a,cadr b),'(1 . 2)) and equal(car a,car b) then
                              return f35(cadr b,caddr b,z) else
             return simpgtoh((a . nil),redpar1(b,2),z);
 m: v:=addend(a,b,'(1 . 2));   v1:=cdr v;
    if null caar v1 and null car addsq(cadr v1,caddr v1) then
                              return f32( car v,cadr v1,z) else
    if null caadr v1 and null car addsq(car v1,caddr v1) then
                              return f32(car v,car v1,z) else
    if null caaddr v1 and null car addsq(car v1,cadr v1) and
       ((not equal(cdar v1,1) and not equal(cdar v1,2)) or
         not numberp(caar v1))
                           then  return f33(car v,car v1,z);
             return simpgtoh((a . nil),redpar1(b,2),z);
  end;

symbolic procedure f34(a,b,z);
  multsq(quotsq(simp!* 'pi,
                simpfunc('cos,multsq(simp!* 'pi,diff1sq(b,a)))),
  multsq(expdeg(z,multsq('(1 . 2),addsq(a,b))),
    diff1sq(bessmsq(diff1sq(b,a),
       multsq('(2 . 1),simpx1(prepsq z,1,2))),struvelsq(diff1sq(a,b),
              multsq('(2 . 1),simpx1(prepsq z,1,2))))));

symbolic procedure f35(a,b,z);
  multsq(simp!* 'pi,
  multsq(expdeg(z,multsq('(1 . 2),addsq(a,b))),
         diff1sq(bessmsq(diff1sq(a,b),
  multsq('(2 . 1),simpx1(prepsq z,1,2))),struvelsq(diff1sq(a,b),
         multsq('(2 . 1),simpx1(prepsq z,1,2))))));

symbolic procedure f33(c,a,z);
  multsq(quotsq(simpx1('pi,3,2),simpfunc('sin,multsq('(2 . 1),multsq(a,
  simp!* 'pi)))),multsq(expdeg(z,c),
      diff1sq(multsq(bessmsq(negsq a,simpx1
  (prepsq z,1,2)),bessmsq(negsq a,simpx1(prepsq z,1,2))),
  multsq(bessmsq(a,simpx1(prepsq z,1,2)),
         bessmsq(a,simpx1(prepsq z,1,2))))));

symbolic procedure f32(c,a,z);
  multsq(multsq('(2 . 1),simpx1('pi,1,2)),multsq(expdeg(z,c),multsq(
  bessmsq(a,simpx1(prepsq z,1,2)),macdsq(a,simpx1(prepsq z,1,2)))));

symbolic procedure q3p1m2n0(a,b,z);
  begin scalar v,v1;
   if equal(car a,caddr b) then
   if equal(diff1sq(car b,car a),'(1 . 2))
     then return f29(car b,cadr b,z)
    else if equal(diff1sq(cadr b,car a),'(1 . 2)) then
                                        return f29(cadr b,car b,z);
   v:=addend(a,b,'(1 . 2));  v1:=cdr v;
   if null caar v1 and null car addsq(cadr v1,caddr v1) then
                                        return f31(car v,cadr v1,z) else
   if null caadr v1 and null car addsq(car v1,caddr v1) then
                                        return f31(car v,car v1,z) else
   if null caaddr v1 and null car addsq(cadr v1,car v1) and
       ((equal(cdar v1,1) and not numberp(caar v1)) or
       not equal(cdar v1,1))
                  then return f30(car v,car v1,z);
             return simpgtoh((nil . a),redpar1(b,2),z);
  end;

symbolic procedure f29(a,b,z);
  multsq(expdeg(z,multsq('(1 . 2),addsq(a,b))),neumsq(diff1sq(b,a),
         multsq('(2 . 1),simpx1(prepsq z,1,2))));

symbolic procedure f30(c,a,z);
  multsq(quotsq(simpx1('pi,1,2),multsq('(2 . 1),simpfunc('sin,multsq(a,
  simp!* 'pi)))),multsq(expdeg(z,c),diff1sq(multsq(besssq(negsq a,simpx1
  (prepsq z,1,2)),besssq(negsq a,simpx1(prepsq z,1,2))),multsq(besssq(a,
  simpx1(prepsq z,1,2)),besssq(a,simpx1(prepsq z,1,2))))));

symbolic procedure f31(c,a,z);
  multsq(negsq(simpx1('pi,1,2)),multsq(expdeg(z,c),multsq(
  besssq(a,simpx1(prepsq z,1,2)),neumsq(a,simpx1(prepsq z,1,2)))));

symbolic procedure q3p1m1n1(a,b,z);
  begin scalar v,v1;
  if equal(car a,car b) then
  if equal(diff1sq(car a,caddr b),'(1 . 2))
    then return f28(car a,cadr b,z)
   else if equal(diff1sq(car a,cadr b),'(1 . 2))
    then return f28(car a,caddr b,z);
  v:=addend(a,b,'(1 . 2));  v1:=cdr v;
    if null caar v1 and null car addsq(cadr v1,caddr v1) then
                             return f26(car v,cadr v1,z) else
    if (null caadr v1 or null caaddr v1)
      and (null car addsq(car v1,cadr v1)
    or null car addsq(car v1,caddr v1)) then return f27(car v,car v1,z);
                  return simpgtoh((a . nil),redpar1(b,1),z);
  end;

symbolic procedure f26(c,a,z);
  multsq(simpx1('pi,1,2),multsq(expdeg(z,c),
         multsq(besssq(a,simpx1(prepsq z,1,2)),
                besssq(negsq a,simpx1(prepsq z,1,2)))));

  symbolic procedure f27(c,a,z);
  multsq(simpx1('pi,1,2),multsq(expdeg(z,c),multsq(
  besssq(a,simpx1(prepsq z,1,2)),besssq(a,simpx1(prepsq z,1,2)))));

symbolic procedure f28(a,b,z);
 multsq(expdeg(z,multsq('(1 . 2),diff1sq(addsq(a,b),'(1 . 2)))),
 struvehsq(diff1sq(a,addsq(b,'(1 . 2))),multsq('(2 . 1),
                        simpx1(prepsq z,1,2))));

symbolic procedure q3p1m3n0(a,b,z);
  begin scalar v,v1;
  v:=addend(a,b,'(1 . 2));  v1:=cdr v;
    if (null car(addsq(car v1,cadr v1)) and null caaddr v1) or
       (null car(addsq(car v1,caddr v1)) and null caadr v1) then
                       return f36(car v,car v1,z) else
    if null car(addsq(cadr v1,caddr v1)) and null caar v1 then
                       return f36(car v,cadr v1,z);
                   return simpgtoh((nil . a),(b . nil),z);
  end;

symbolic procedure f36(a,b,z);
  multsq(quotsq('(2 . 1),simpx1('pi,1,2)),multsq(expdeg(z,a),multsq(
  macdsq(b,simpx1(prepsq z,1,2)),macdsq(b,simpx1(prepsq z,1,2)))));

symbolic procedure q3p1m3n1(a,b,z);
    if equal(car a,car b) and null car(addsq(cadr b,caddr b)) then
                            f38(car a,cadr b,z) else
    if (equal(car a,cadr b) and null car(addsq(car b,caddr b))) or
       (equal(car a,caddr b) and null car(addsq(car b,cadr b))) then
                            f38(car a,car b,z) else
    if equal(diff1sq(car a,caddr b),'(1 . 2)) and
       null numr(addsq(addsq(car b,cadr b),
                      multf(-2,caaddr b) ./ cdaddr b))
                       then f39(caddr b,car b,z) else
    if equal(diff1sq(car a,cadr b),'(1 . 2)) and
     null numr(addsq(addsq(car b,caddr b),multf(-2,caadr b) ./ cdadr b))
                       then f39(cadr b,car b,z) else
    if equal(diff1sq(car a,car b),'(1 . 2)) and
      null numr(addsq(addsq(cadr b,caddr b),multf(-2,caar b) ./ cdar b))
                       then f39(car b,cadr b,z) else
                       simpgtoh((a . nil),(b . nil),z);

symbolic procedure f38(a,b,z);
 if parfool(diff1sq('(1 . 1),addsq(a,b))) or
    parfool(addsq('(1 . 1),diff1sq(b,a))) then
   simpgtoh((list(a) . nil),(list(a,b,negsq b) . nil),z) else
 multsq(expdeg('(4 . 1),diff1sq('(1 . 1),a)),
        multsq(multgamma(list(diff1sq( '(1 . 1),addsq(a,b)),
                addsq(b,diff1sq('(1 . 1),a)))),
                lommel2sq(diff1sq(multsq('( 2 . 1),a),'(1 . 1))
                ,multsq('(2 . 1),b),multsq('(2 . 1),
                        simpx1(prepsq z,1,2)))));

symbolic procedure f39(a,b,z);
  if not numberp(car diff1sq(a,b)) or
     not equal(cdr diff1sq(a,b),2) then
  multsq(quotsq(multsq(simpx1('pi,5,2),expdeg(z,a)),multsq('(2 . 1),
  simpfunc('cos,multsq(simp!* 'pi,diff1sq(b,a))))),multsq(hankel1sq(
  diff1sq(b,a),simpx1(prepsq z,1,2)),hankel2sq(diff1sq(b,a),
  simpx1(prepsq z,1,2)))) else
       simpgtoh((list(addsq(a,'(1 . 2))) . nil),
       (list(b,a,diff1sq(multsq('(2 . 1),a),b)) . nil),z);

%***********************************************************************
%*           Logarithmic case of Meijer's G-function                   *
%***********************************************************************

fluid '(!*infinitymultpole);

symbolic smacro procedure priznak(u,v);
 for each uu in u collect ( uu . v) ;

symbolic procedure gfmlogcase(a,b,z);
 begin scalar w;
  w:=allpoles(logcase(append(priznak(cdr a,'n),priznak(car b,'p))));
  w:=sortpoles(w);
  if null !*infinitymultpole then
              return gfmlogcasemult(w,a,b,z)
     else << !*infinitymultpole := nil;
        % to prevent lots of integrals from failing.
             return 'fail>>;
 end;

array res(5);

symbolic procedure allpoles uu;
  for each u in uu join
   begin scalar w;integer kr;
   while u do <<
    if equal(cdar u,'n) then kr:=kr-1
                        else kr:=kr+1;
    if kr > 0 then
     if not null cdr u then
      if not equal(caadr u,caar u) then
           w:=cons(list(
              kr,prepsq diff1sq(caadr u,caar u),negsq caar u),w)
        else w:=w
       else
          <<    w:=cons(list(kr,'infinity,negsq caar u),w);
                if not eq(kr,1) then !*infinitymultpole:=t
          >>;
    u:=cdr u;
   >>;
  return w;
 end;

symbolic procedure logcase u;
   begin scalar blog,blognew,sb;
   sb:=u; u:=cdr sb;
 m1: if null sb then return blognew;

 m2: if null u then
           << if not null blog then
                        << blognew:=cons(blog,blognew);
                           blog:=nil
                        >>
                               else
                           blognew:=cons(list car sb,blognew);
              sb:=cdr sb;  if sb then u:=cdr sb;
              goto m1
           >>
          else
           if equal(caar sb,caar u) or
              and(numberp car diff1sq(caar sb,caar u),
                  equal(cdr diff1sq(caar sb,caar u),1))
             then
              << if null blog then
                    if equal(caar sb,caar u) or
                       car diff1sq(caar sb,caar u) < 0  then
                         blog:=list(car sb,car u)
                       else blog:=list(car u,car sb)
                            else
                    blog:=ordern(car u,blog);
                 sb:=delete(car u, sb);
                 if u then u:=cdr u;
                 goto m2
              >>
              else
              << if u then u:=cdr u;
                 goto m2;
              >>
end;

symbolic procedure ordern(u,v);
  %u - dotted pair (SQ . ATOM).
  %v - list of dotted pair.
  if null v then list(u)
    else
  if equal(car u,caar v) or car diff1sq(car u,caar v) > 0 then
              (car v) . ordern(u,cdr v)
    else
              u . v ;

symbolic procedure sortpoles(w);
 begin scalar w1,w2;
  while w do begin
   if equal(cadar w,'infinity) then w1:=(car w) . w1
     else w2:=(car w) . w2;
   w:=cdr w;
  end;
  return append(w2,w1);
 end;

symbolic procedure gfmlogcasemult(w,a,b,z);
  % w -- list of lists.
  if null w then (nil . 1) else
     addsq(groupresudes(car w,a,b,z),
           gfmlogcasemult(cdr w,a,b,z));

symbolic procedure groupresudes(w,a,b,z);
  % w -- (order number start).
   if not equal(cadr w,'infinity) then multpoles(w,a,b,z)
   else
   if equal(cadr w,'infinity) and car w = 1 then
      simplepoles(caddr w,a,b,z)
   else
      'fail;

symbolic procedure simplepoles(at,a,b,z);
 if member(at, car b) then
    infinitysimplpoles(a,(car redpar(car b,list(at)) . cdr b),
                          negsq at,z)
 else specialtransf(at,a,b,z);

symbolic procedure specialtransf(at,a,b,z);  %some changes by WN
 if listfooltwo(car b, cdr a) then
    begin scalar c, cc;
      c:=redpar(car b,cdr a);
      cc:=redpar(cdr b,car a);
      a:=(cadr cc . cadr c);
      b:=(car c . car cc);
      if listfooltwo(car b, cdr a) then
        <<
          c:=findtwoparams(car b, cdr a);
          a:=((car c) . car a ) .  car redpar(cdr a,list(car c));
          b:=(car redpar(car b,list(cadr c)) . (cadr c) . cdr b);
          return
%         multsq( expdeg('(-1 . 1), diff1sq(simp car c, simp cadr c)),
          multsq( expdeg('(-1 . 1), diff1sq(car c,  cadr c)),
                  specialtransf(at,a,b,z) )
        >>
      else
        return infinitysimplpoles( a,b,negsq at,z );
     end
 else
    begin scalar c;
      c:=redpar(cdr b,car a);
      a:=(cadr c . cdr a);
      b:=(car b . car c);
      return infinitysimplpoles( a,b,negsq at,z );
    end;

symbolic procedure findtwoparams(u, v);
 % u, v -- lists.
 begin scalar c;
   foreach uu in u do
      foreach vv in v do
        if parfool diff1sq(uu,vv)
          then << c := list(vv,uu); u := nil; v := nil>> ;
   return c;
end;

symbolic procedure multpoles (u,a,b,z);
  % u -- (order number start).
  if cadr u = 0 then (nil . 1) else
     addsq(multresude(list(car u, caddr u),a,b,z),
           multpoles(list(car u,cadr u-1,
                     diff1sq(caddr u,'(1 . 1))),a,b,z));

symbolic procedure multresude (u,a,b,z);
  % u -- (order start).
  % a,b -- parameters of G-function.
  % z - argument of G-function.
  <<
   for i:=0 step 1 until 5 do res(i):='(nil . 1);
   findresude(multlistasym(list(
          listtaylornom(listplus(car b,cadr u),simp 'eps,car u),
          listtaylornom(pdifflist(addsq('(1 . 1),negsq cadr u),car a),
                                 negsq simp 'eps,car u),
          listtaylorden(listplus(cdr a,cadr u),simp 'eps,car u),
          listtaylorden(pdifflist(addsq('(1 . 1),negsq cadr u),cdr b),
                                 negsq simp 'eps,car u),
          if equal(z,'(1 . 1)) then '(1 . 1) else
              multsq(expdeg(z,negsq cadr u),
                     seriesfordegree(car u,simp 'eps,z))),car u))
 >>;

symbolic procedure findresude u;
  begin scalar s,cc;
   cc:=prepsq(cdr u ./ 1);
   cc:= cdr algebraic coeff(cc,eps);
   while car cc = 0 do cc:=cdr cc;
   s:=if numberp car cc then simp car cc else cadr car cc;
   cc:=prepsq(car u ./ 1);
   cc:= cdr algebraic coeff(cc,eps);
   return
   multsq(invsq s,if numberp car cc then simp car cc
                                     else cadr car cc);
 end;

symbolic procedure seriesfordegree(n,v,z);
 if n=1 then '(1 . 1) else
    addsq(quotsq(multsq(exptsq(negsq v,n-1),
            exptsq(simpfunc('log,z),n-1)),gamsq((n . 1))),
          seriesfordegree(n-1,v,z));

symbolic procedure listtaylornom(u,v,n);
  % u -- list of SQ.
  % v -- EPS -> 0.
  % n -- order of the representation by the polynom.
  if null u then '(1 . 1) else
     multasym(taylornom(car u,v,n),listtaylornom(cdr u,v,n),n);

symbolic procedure multlistasym(u,n);
  if null u then '(1 . 1)
    else
     multasym(car u,multlistasym(cdr u,n),n);

symbolic procedure multasym(u,v,n);
  begin integer k;
  if null car u or null car v then return '(nil . 1);
  u:=multsq(u,v);
  if not oldpolstack(car u ./ 1) then return u;
  v:=res(0);
   while (k:=k+1) < n do
     v:=addsq(v,multsq(res(k),exptsq(simp 'eps,k)));
   return multsq(v,1 ./ cdr u);
  end;

symbolic procedure oldpolstack u;
  begin scalar cc; integer k;
   cc := prepsq u;
   cc:=cdr algebraic coeff(cc,eps);
   if null cc then return nil else k:=0;
   while not null cc do
      <<
      res(k):=if numberp car cc then simp(car cc)
                                else cadr car cc;
      cc:=cdr cc;k:=k+1;
      >>;
   return t;
  end;

symbolic procedure listtaylorden(u,v,n);
  % u -- list of SQ.
  % v -- EPS -> 0.
  % n -- order of the representation by the polynom.
  if null u then '(1 . 1) else
     multasym(taylorden(car u,v,n),listtaylorden(cdr u,v,n),n);

symbolic procedure taylornom(u,v,n);
  % u -- SQ.
  % v -- SQ is EPS -> 0.
  % n -- order of the representation by the polynom.
  if null car u then multsq(invsq v,taylorgamma('(1 . 1),v,n))
    else
  if parfool u then multlistasym(list(
     exptsq('(-1 . 1),if null car negsq u then 0 else car negsq u),
     invsq v,
     taylornom('(1 . 1),v,n),taylornom('(1 . 1),negsq v,n),
     taylorden(diff1sq('(1 . 1),u),negsq v,n)),n)
    else
     multsq(gamsq(u),taylorgamma(u,v,n));

symbolic procedure taylorden(u,v,n);
  % u -- SQ.
  % v -- SQ is EPS -> 0.
  % n -- order of the representation by the polynom.
  if parfool u then multlistasym(list(
     exptsq('(-1 . 1),if null car negsq u then 0 else car negsq u),
     v,
     taylornom(diff1sq('(1 . 1),u),negsq v,n),
     taylorden('(1 . 1),v,n),
     taylorden('(1 . 1),negsq v,n)),n)
               else
     quotsq(inversepol(taylorgamma(u,v,n),n),gamsq(u));

symbolic procedure inversepol(u,n);
  begin scalar sstack,c,w;integer k,m;
   if n=1 then return '(1 . 1);
   if null oldpolstack(car u ./ 1) then return u;
   sstack:=list('(1 . 1));  k:=2;
   while k <= n do begin
    w:=sstack;   m:=2; c:=nil . 1;
     while m <= k do begin
       c:=addsq(c,multsq(res(m-1),car w));
       m:=m+1; w:=cdr w;
     end;
    sstack:=(negsq c) . sstack;
    k:=k+1;
   end;
   w:=nil . 1;
   while sstack do begin
     w:=addsq(w,multsq(car sstack,exptsq(simp 'eps,n-1)));
     sstack:=cdr sstack;
     n:=n-1;
   end;
    return multsq(cdr u ./ 1,quotsq(w,res(0)));
  end;

symbolic procedure taylorgamma(u,v,n);
  % representation of gamma-function by the polynom of the
  % order  n  in  u  on the degree  v.
  if n=1 then '(1 . 1) else
     addsq(quotsq(multsq(exptsq(v,n-1),gammatopsi(u,n-1)),
              gamsq(n ./ 1)),
           taylorgamma(u,v,n-1));

symbolic procedure gammatopsi(u,n);
  if n=1 then psisq(u) else
     addsq(multsq(psisq(u),gammatopsi(u,n-1)),
           diffsq(gammatopsi(u,n-1),prepsq u));

algebraic <<
  operator lst,gfm;
  let gfm(lst(1,0,1,1),lst(1),lst(0),~z)=> (sign(1 + z) + sign(1 - z))/2
>>;

algebraic
   let meijerg({{},1},{{0,0},-1/2},~x) =>
        g_fresnel_s(2*sqrt(x),-1)/(2^(-2)*sqrt(pi));


endmodule;


end;
