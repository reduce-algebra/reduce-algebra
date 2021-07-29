module specfn2;  % Part 2 of the Special functions package for REDUCE.
                 % The special Special functions.

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

% $Id: $

% Major modifications by: Winfried Neun, ZIB Berlin.


%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     Please report bugs to Winfried Neun,                       %
%       Konrad-Zuse-Zentrum                                      %
%       fuer Informationstechnik Berlin,                         %
%       Heilbronner Str. 10                                      %
%       10711 Berlin - Wilmersdorf                               %
%       Federal Republic of Germany                              %
%     or by email, neun@sc.ZIB-Berlin.de                         %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     This package provides algebraic                            %
%     manipulations upon some special functions:                 %
%                                                                %
%      -- Generalized Hypergeometric Functions                   %
%      -- Meijer's G Function                                    %
%      -- to be extended                                         %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %


create!-package ('(specfn2 ghyper MeijerG),
                 '(contrib specfn));

load_package specfn;

%  Various help utilities and inlines for hypergeometric function
%  simplification.

% This is a duplicate of subtrsq, defined in poly/polrep.red
%symbolic inline procedure diff1sq(u,v);
%   addsq(u,negsq(v))$

symbolic inline procedure mksqnew u;
  !*p2q(car fkern(u) .* 1);

symbolic inline procedure gamsq(u);
  mksqnew({'gamma,prepsq u});

symbolic inline procedure multgamma u;
   %u -- list of SQ.
   <<for each pp in u do <<p := multsq(gamsq pp,p)>>; p>>
     where p = '(1 . 1);

symbolic inline procedure besssq(v,u);
  mksqnew({'BesselJ,prepsq v,prepsq u});

symbolic inline procedure bessmsq(v,u);
  mksqnew({'BesselI,prepsq v,prepsq u});

symbolic inline procedure simppochh(v,u);
  mksqnew({'Pochhammer,prepsq v,prepsq u});

symbolic procedure multpochh(u,k);
 << for each pp in u do <<p := multsq (simppochh (pp,k),p)>>; p>>
                 where p = '(1 . 1);

symbolic inline procedure psisq(v);
  mksqnew({'psi,prepsq v});

%symbolic inline procedure dfpsisq(v,u);
% mksqnew('dfpsi . list(prepsq v,prepsq u))$

symbolic procedure simpfunc(u,v);
 % u -- name of the function, PF.
 % v -- argument, SQ.
 begin scalar l,v1!wq;
 v1!wq:=prepsq v; l:=('!Adamchik . v1!wq);
 u:=subf(car simp!* list(u,'!Adamchik),list l);
 return u $
end$

algebraic operator intsin,intcos,ints,intfs,intfc$

symbolic procedure subsqnew(u,v,z);
% u,v -- SQ.
% z -- PF  .
begin scalar a!1,lp,a;
  a!1:=prepsq v; lp:=((z . a!1));
  a:=quotsq(subf(numr u,list lp),subf(denr u,list lp));
  return a;
end$

symbolic procedure expdeg(x,y);
% x,y -- SQ.
% value is the x**y.
 if null numr y then '(1 . 1) else
 if numberp numr y and numberp denr y then
             simpx1(prepsq x,numr y,denr y) else
 quotsq(expdeg1(numr x ./ 1 ,y),expdeg1(denr x ./ 1 ,y))$

symbolic procedure expdeg1(x,y);
% x,y -- SQ.
% value is the x**y.
simp!*(prepsq(subsqnew(subsqnew(simp!*
      '(expt a!g9 b!!g9),x,'a!g9),y,'b!!g9)))$

symbolic inline procedure difflist(u,v);
 % u -- list of SQ.
 % v -- SQ.
 % value is (u) - v.
 for each uu in u collect addsq(uu,negsq v);

%% Renamed from listplus which also defined in listvecops package
symbolic procedure specfn!-listplus(u,v);
% value is (u) + v.
  for each uu in u collect addsq(uu,v);

%%UNUSED
%% symbolic inline procedure addlist u;
%%  % u -- list of PF.
%%  <<for each pp in u do <<p := addsq(simp!* pp,p)>>; p>>
%%    where p = '(nil . 1);

 symbolic inline procedure listsq(u);
 % u - list of PF.
 % value is list of SQ.
 for each uu in u collect simp!* uu;

symbolic inline procedure listmin(u);
 % u - list.
 % value is (-u).
 for each uu in u collect negsq uu;

symbolic inline procedure multlist(u);
<< for each pp in u do <<p := multsq(pp,p)>>; p>> where p = '(1 . 1);

symbolic procedure parfool u;
  % u -- SQ.
  % value is T if u = 0,-1,-2,...
  if null numr u then t
    else
  if numberp numr u and denr u=1 and numr u<0 then t
    else nil;

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
  if null numr n then a else
  if and(numberp(numr n),numberp(denr n),eqn(denr n,1),not lessp(numr n,0))
                                        then
     multsq(invsq(simp!* b), diffsq(sdiff(a,b,subtrsq(n, '(1 . 1))),b))
     else
  rerror('specialf,130,"***** error parameter in sdiff")$

 symbolic procedure derivativesq(a,b,n);
  % a -- SQ.
  % b -- ATOM.
  % n -- order, SQ.
 if null n or null numr n then a
 else derivativesq(diffsq(a,b),b,subtrsq(n,'(1 . 1)))$

 symbolic procedure addend( u,v,x);
  % u,v -- lists of SQ.
  % x -- SQ.
  cons(subtrsq(car u,x),difflist(v,subtrsq(car u,x)))$

 symbolic procedure parlistfool(u,v);
  %v -- list.
  %value is the T if u-(v)=0,-1,-2,...
  if null v then nil else
  if parfool(subtrsq(u,car v)) then t else
     parlistfool(u,cdr v);

 symbolic procedure listparfool(u,v);
  %u -- list.
  %value is the T if (u)-v=0,-1,-2,...
  if null u then nil else
  if parfool(subtrsq(car u,v)) then t else
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

 symbolic inline procedure pdifflist(u,v);
  % u -- SQ.
  % v -- list of SQ.
  %value is a list: u-(v).
 for each vv in v collect subtrsq(u,vv);

symbolic procedure redpar1(u,n);
 % value is a pair, car-part -- first n elements of list u
 %                  cdr-part -- u .
 begin scalar bm;
  while u and n>0 do <<
    bm := car u . bm;
    u  := cdr u;
    n  := n-1>>;
  return reversip bm . u;
end;

symbolic procedure redpar (l1,l2);
  % value is the pair (la,lb)
  % where la consists of all elements in l1 that do not occur in l2
  % and lb of all elements of l1 that occur in l2
   begin scalar l3;
   while l2 do <<
         if member(car l2 , l1) then l1 := delete(car l2,l1)
                 else l3 := (car l2) . l3 ;
         l2 := cdr l2 >>;
   return list (l1,reverse l3);
   end;

algebraic operator lommel,Heaviside;

symbolic inline procedure heavisidesq(u);
  mksqnew({'Heaviside,prepsq u});

symbolic inline procedure struvelsq(v,u);
  mksqnew({'StruveL,prepsq v,prepsq u});

symbolic inline procedure struvehsq(v,u);
  mksqnew({'StruveH,prepsq v,prepsq u});

symbolic inline procedure neumsq(v,u);
  mksqnew({'BesselY,prepsq v,prepsq u});

symbolic inline procedure dfpsisq(v,u);
  mksqnew({'polygamma,prepsq u,prepsq v});

symbolic inline procedure Lommel2sq (u,v,w);
  mksqnew({'lommel2,prepsq u,prepsq v,prepsq w});

symbolic inline procedure tricomisq (u,v,w);
  mksqnew({'KummerU,prepsq u,prepsq v,prepsq w});

symbolic inline procedure macdsq (v,u);
  mksqnew({'BesselK,prepsq v,prepsq u});

fluid '(v1!wq a!g9 b!!g9);

symbolic inline procedure sumlist u;
   % u -- list of the PF
   <<for each pp in u do <<p := addsq(simp pp,p)>>; p>>
    where p = '(nil . 1);

symbolic inline procedure listprepsq(u);
  for each uu in u collect prepsq uu;

endmodule;

end;


