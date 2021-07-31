module recsimpl; % Simplification of expressions involving recursions
                 % for special functions.

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

% $Id$

% Wolfram Koepf, ZIB Berlin , May 1994

% Reduce version (developed from the Maple version) by Winfried Neun.

fluid '(spec_nnnnn);

flag ('(spec_check_n),'boolean);

algebraic procedure trim (u);

  if u = {} then {} else
      if member(first u,rest u) then trim rest u
         else first u . trim rest u;

algebraic procedure adelete (v,u);

  if u = {} then {} else
      if v = first u then adelete(v, rest u)
         else first u . adelete(v, rest u);

algebraic procedure RecursionSimplify (ex);

begin scalar eqq,l1,l2,l3,l4,l5,f,nargs,n,a,x,kern;

  eqq := ex;
  lisp (kern := union (kernels !*q2f  (numr simp eqq ./ 1),
                        kernels !*q2f (denr simp eqq ./ 1)));

  l1 := 'list . lisp  foreach k in kern join if atom k then nil else
                                list k;
  l2 := 'list . lisp foreach k in kern join if atom k then nil else
                                list (car k , -1 + length k);

  while not(l2 = {}) do <<

        f:=  first l2; l2 := rest l2;
        nargs := first l2; l2 := rest l2;
        l3 := foreach kk in l1 join
                 if part(kk,0) = f  and
                         lisp equal(-1 + length (prepsq cadr kk),nargs)
                 then list kk else list ('list);
       l4:= foreach kk in l3 collect lisp ('list . cddr prepsq cadr kk);
       l4 := trim l4;
       foreach kkk in l4 do  <<
          l5 := foreach kkkk in l3 join
                if kkk = lisp ('list . cddr prepsq cadr kkkk)
                then lisp list('list , cadr prepsq cadr kkkk)
                        else {};
         while length l5 > 2 do <<
                n := max(l5);
                if member(n-1,l5) and member(n-2,l5) then
                   <<   spec_nnnnn:= n;
                        eqq := (eqq where spec_recrules);
                        spec_nnnnn:= nil 
                   >>;
                l5 := adelete(n,l5);

                >>; >>; >>;
return eqq;
  end;

algebraic procedure spec_check_n(n);
   if n = spec_nnnnn then t else nil;


algebraic (
spec_recrules :={
% AS (9.1.27)

BesselJ(~n,~z) => - BesselJ(n-2,z) + (2*(n-1)/z)*BesselJ(n-1,z)
when spec_check_n(n),
% AS (9.1.27)

BesselY(~n,~z) => - BesselY(n-2,z) + (2*(n-1)/z)*BesselY(n-1,z)
when spec_check_n(n),
% AS (9.6.26)

BesselI(~n,~z) => BesselI(n-2,z) - (2*(n-1)/z)*BesselI(n-1,z)
when spec_check_n(n),
% AS (9.6.26)

BesselK(~n,~z) => BesselK(n-2,z) + (2*(n-1)/z)*BesselK(n-1,z)
when spec_check_n(n),
% AS (9.1.27)

hankel1(~n,~z) => - hankel1(n-2,z) + (2*(n-1)/z)*hankel1(n-1,z)
when spec_check_n(n),
% AS (9.1.27)

hankel2(~n,~z) => - hankel2(n-2,z) + (2*(n-1)/z)*hankel2(n-1,z)
when spec_check_n(n),
% AS (13.4.2)

KummerM(~a,~b,~z) => 1/(a-1)*
        ((b-a+1)*KummerM(a-2,b,z) + (2*a-2-b+z)*KummerM(a-1,b,z))
when spec_check_n(a),

% AS (13.4.15)
KummerU(~a,~b,~z) => -1/((a-1)*(a-b))*
        (KummerU(a-2,b,z) + (b-2*a+2-z)*KummerU(a-1,b,z))
when spec_check_n(a),
% AS (13.4.29)

WhittakerM(~n,~m,~z) => 1/(2*m+2*n-1)*
        ((3+2*m-2*n)*WhittakerM(n-2,m,z)
           + (4*n-4-2*z)*WhittakerM(n-1,m,z))
when spec_check_n(n),
% AS (13.4.31)

WhittakerW(~n,~m,~z) => 1/4*
((-9+4*m^2+12*n-4*n^2)*WhittakerW(n-2,m,z)
    - (8*n-8-4*z)*WhittakerW(n-1,m,z))
when spec_check_n(n),
% AS (8.5.3)

LegendreP(~a,~b,~z) => 1/(a-b)*
        (-(a-1+b)*LegendreP(a-2,b,z) + (2*a-1)*z*LegendreP(a-1,b,z))
when spec_check_n(a),

LegendreQ(~a,~b,~z) => 1/(a-b)*
        (-(a-1+b)*LegendreQ(a-2,b,z) + (2*a-1)*z*LegendreQ(a-1,b,z))
when spec_check_n(a),
% AS (22.7)

JacobiP(~n,~a,~b,~z) => 1/(2*n*(a + b + n)*(-2 + a + b + 2*n))*
((2*(1-a-n)*(-1+b+n)*(a+b+2*n)*JacobiP(n-2,a,b,z)) +
((a^2-b^2)*(-1+a+b+2*n)+(-2+a+b+2*n)*(-1+a+b+2*n)*(a+b+2*n)*z)*
JacobiP(n-1,a,b,z)) when spec_check_n(n),

GegenbauerP(~n,~a,~z) => 1/n*(
     -(n+2*a-2)*GegenbauerP(n-2,a,z) + 2*(n-1+a)*z*GegenbauerP(n-1,a,z))
when spec_check_n(n),

ChebyshevT(~n,~z) => - ChebyshevT(n-2,z) +2*z*ChebyshevT(n-1,z)
when spec_check_n(n),

ChebyshevU(~n,~z) => - ChebyshevU(n-2,z) +2*z*ChebyshevU(n-1,z)
when spec_check_n(n),

% Two arguments version:
 LegendreP(~n,~z) =>
 1/n*(-(n-1)*LegendreP(n-2,z)+(2*n-1)*z*LegendreP(n-1,z))
 when spec_check_n(n),

LaguerreP(~n,~a,~z) => 1/n*
        (-(n-1+a)*LaguerreP(n-2,a,z) + (2*n+a-1-z)*LaguerreP(n-1,a,z))
when spec_check_n(n),

LaguerreP(~n,~z) => 1/n*
        (-(n-1)*LaguerreP(n-2,z) + (2*n-1-z)*LaguerreP(n-1,z))
when spec_check_n(n),

HermiteP(~n,~z) => -2*(n-1)*HermiteP(n-2,z) + 2*z*HermiteP(n-1,z)
when spec_check_n(n) ,

StruveH(~nnnnn,~x)=>
((x^2*StruveH(-3 + nnnnn,x) + 5*x*StruveH(-2 + nnnnn,x) -
        4*nnnnn*x*StruveH(-2 + nnnnn,x) + 2*StruveH(-1 + nnnnn,x) -
        6*nnnnn*StruveH(-1 + nnnnn,x) + 4*nnnnn^2*StruveH(-1 + nnnnn,x)
        + x^2*StruveH(-1 + nnnnn,x))/(-x + 2*nnnnn*x))
  when spec_check_n(nnnnn),

%(* AS (12.2.4)-(12.2.5) *)

StruveL(~nnnnn,~x) => ((-(x*StruveL(-3 + nnnnn, x)) +
(-1 + 4*(-1 + nnnnn))*StruveL(-2 + nnnnn, x) +
((-2*(-1 + nnnnn) - 4*(-1 + nnnnn)^2 + x^2)*StruveL(-1 + nnnnn, x))/x)/
(1 + 2*(-1 + nnnnn))) when spec_check_n(nnnnn) } )$

% can be locally applied with where.

endmodule;

end;



