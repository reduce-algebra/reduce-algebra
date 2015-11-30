module sfpolys;   % Assorted Polynomials
                  % will be a package of its own one day
%
% Author: Winfried Neun, Feb 1993
%

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

% Revision 6. April 1995, using explicit formulae for the orthogonal
%                       polynomials (Abramowitz/Stegun 22.3)
% Revision  December 1995 by Wolfram Koepf
%           June 1996 by Wolfram Koepf : improved numeric codes
%           added Fibonacci numbers and Polys, W.N,  September 1998

fluid '(powlis1!*);

% Bernoulli Polynomials (see e.g. Abramowitz Stegun , chapter 23

algebraic operator bernoullip;

algebraic <<
let {   bernoullip (~n,0) => bernoulli n     when fixp n and n >=0,
        bernoullip (~n,~x) => (for k:=0:n sum (binomial(n,k) *
                         bernoulli(k) * x^(n-k)))
                                          when fixp n and n >=0} >>;

% Euler Polynomials (see e.g. Abramowitz Stegun , chapter 23

algebraic operator eulerp ;

algebraic <<
let {   eulerp (~n,1/2) => Euler(n)/2^n when fixp n and n >=0,
        eulerp (~n,~x) => (for k:=0:n sum (binomial(n,k) *
                         Euler(k)/2^k * (x -1/2)^(n-k)))
                                    when fixp n and n >=0}
>>;

 % Univariate orthogonal bases (for approximation etc).

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1993, all rights resrved


algebraic procedure monomial_base(x,n);
     for i:=0:n collect x**i;

algebraic procedure trigonometric_base(x,n);
     1 . for i:=1:n join list(sin(i*x),cos(i*x));

algebraic procedure bernstein_base(x,n);
     for i:=0:n collect
         binomial(n,i)*(1-x)**(n-i)*x**i;

algebraic procedure legendre_base(x,n,a,b);
     legendre_base1(x,n,{a/2-b/2 + (1+a/2+b/2)*x,1},1,a,b);

algebraic procedure legendre_base1(x,n,base,r,a,b);
     if r>=n then reverse base else
     legendre_base1(x,n,
       (((2*r+a+b+1)*(a**2-b**2)+(2*r+a+b)*(2*r+1+a+b)*(2*r+2+a+b)*x)/
                (2*(r+1)*(r+1+a+b)*(2*r+a+b))*first base -
                2*(r+a)*(r+b)*(2r+2+a+b)/(2*(r+1)*(r+1+a+b)*
                        (2*r+a+b))*second base)
              . base, r+1,a,b);

algebraic procedure laguerre_base(x,n,a);
     laguerre_base1(x,n,{1-x+a,1},1,a);

algebraic procedure laguerre_base1(x,n,base,r,a);
     if r>=n then reverse base else
     laguerre_base1(x,n,
        ((1+2r-x+a)/(r+1)*first base - (r+a)/(r+1)*second base )
              . base, r+1,a);

algebraic procedure hermite_base(x,n);
     hermite_base1(x,n,{2*x,1},1);

algebraic procedure hermite_base1(x,n,base,r);
     if r>=n then reverse base else
     hermite_base1(x,n,
        (2x*first base - 2r*second base)
              . base, r+1);

algebraic procedure chebyshev_base_t(x,n);
     chebyshev_base_t1(x,n,{x,1},1);

algebraic procedure chebyshev_base_t1(x,n,base,r);
     if r>=n then reverse base else
     chebyshev_base_t1(x,n,
        (2x*first base - second base )
              . base, r+1);

algebraic procedure chebyshev_base_u(x,n);
     chebyshev_base_t1(x,n,{2x,1},1);

algebraic procedure gegenbauer_base1(x,n,base,r,a);
     if r>=n then reverse base else
     gegenbauer_base1(x,n,
        (2*(r+a)/(r+1)*x*first base - (r+2*a-1)/(r + 1)*second base )
              . base, r+1,a);

algebraic procedure gegenbauer_base(x,n,a);
     gegenbauer_base1(x,n,{2*a*x,1},1,a);


algebraic <<

operator HermiteP,JacobiP,LegendreP,LegendreQ, !~f,
         LaguerreP,ChebyshevT,ChebyshevU,GegenbauerP;

let limit(~f(~n,~x),~x,~lim) => f(n,lim) when freeof (lim,infinity)
       and member (f,{LegendreP,ChebyshevT,ChebyshevU,HermiteP,
              LaguerreP,bernoullip,eulerp,LaguerreP});

let limit(~f(~n,~m,~x),~x,~lim) => f(n,m,lim) when freeof (lim,infinity)
         and member (f,{LegendreP,LegendreQ,GegenbauerP,LaguerreP});

let limit(~f(~n,~m,~mm,~x),~x,~lim) => f(n,m,mm,lim)
      when freeof (lim,infinity) and member (f,{JacobiP});

let { % AS (22.4)
LegendreP(~n,0,0) => cos(n*pi/2)*factorial(n)/(2^n*(factorial(n/2))^2),
% AS (8.6.1)
LegendreP(~n,~m,0) =>
        2^m/sqrt(pi)*cos((n+m)*pi/2)*gamma((n+m+1)/2)/gamma((n-m+2)/2),
% AS (8.6.2)
LegendreQ(~n,~m,0) =>
        2^(m-1)/sqrt(pi)*sin((n+m)*pi/2)*gamma((n+m+1)/2)
          /gamma((n-m+2)/2),
% AS (8.6.1)
LegendreP(~n,0) =>
        1/sqrt(pi)*cos((n)*pi/2)*gamma((n+1)/2)/gamma((n+2)/2),
LegendreP(~n,1) => 1,
LegendreP(~n,-1) => (-1)^n,

% AS (22.4)
GegenbauerP(~n,0,0) => 2*cos(n*pi/2)/n,
GegenbauerP(~n,~a,0)=> cos(n*pi/2)*gamma(a+n/2)
                                /(gamma(a)*factorial(n/2)),
ChebyshevT(~n,0) => cos(n*pi/2),
ChebyshevU(~n,0) => cos(n*pi/2),
ChebyshevT(~n,1) => 1,
ChebyshevU(~n,1) => n + 1 ,
ChebyshevT(~n,-1) => (-1)^n,
ChebyshevU(~n,-1) => (n+1)* (-1)^n,

LaguerreP(~n,~a,0) => binomial(n+a,n),
LaguerreP(~n,0) => 1,
LaguerreP(0,~x) => 1,
HermiteP(~n,0) => cos(n*pi/2)*factorial(n)/factorial(n/2) }$

let  {  HermiteP (~n,~x)=> (begin scalar b1,b2,bex,r;
                                r := 1; b1 := 2x; b2 := 1;
                                for i:= 1:(n-1) do <<
                                bex := 2x*b1 - 2*r*b2;
                                r := r+1; b2 := b1; b1 := bex;
                                >>;
                                return b1; end)
                when fixp n and n > 0 and numberp x ,
    % hermitep (~n,~x)=> sub(!=z = x,first reverse hermite_base (!=z,n))
    %       (factorial n * for ii:=0:floor(n/2) sum ((-1)^ii/(factorial ii *
    %     factorial(n -2ii)) * (2*x)^(n-2ii)))
    %               when fixp n and n > 0 and lisp !*rounded,
     HermiteP (~n,~x)=> (begin scalar k,tmp,result,ratio,oldslash,
                                      powlis1!*;
                        lisp setq(oldslash,remprop('slash,'opmtch));
                          % tmp:=subs(k=0,term);
                          tmp:=(2*x)**n;
                          result:=tmp;
                          % Ratio:=ratio(term,k);
                          ratio:=-1/4/(k+1)*(n-2*k)*(n-2*k-1)/x**2;
                          for k:=0:n/2 do
                          <<
                          % tmp:=tmp*Ratio;
                            tmp:=-tmp*1/4/(k+1)*(n-2*k)*(n-2*k-1)/x**2;
                            result:=result+tmp;
                          >>;
                        lisp put('slash,'opmtch,oldslash); % restore
                          return(result);
                        end)
                       when fixp n and n > 0 ,
     HermiteP (0,~x)=> 1};

let{ LegendreP (~n,~x) =>
        %       (1/2^n * for ii:=0:floor(n/2) sum (binomial(n,ii) *
        %          binomial(2n-2ii,n)*(-1)^ii *x^(n-2ii)))
        (begin
        scalar k,tmp,result,ratio,oldslash,powlis1!*;
         lisp setq(oldslash,remprop('slash,'opmtch));
         tmp:=2**(-n)*factorial(2*n)/factorial(n)**2*x**n;
         result:=tmp;
         % Ratio:=ratio(term,k);
         ratio:=-1/2/x**2*(n-2*k-1)*(n-2*k)/(k+1)/(2*n-2*k-1);
         for k:=0:n/2 do
         <<
         % tmp:=tmp*eval(Ratio);
         tmp:=-tmp/2/x**2*(n-2*k-1)*(n-2*k)/(k+1)/(2*n-2*k-1);
         result:=result+tmp;
         >>;
         lisp put('slash,'opmtch,oldslash); % restore
         return(result);
         end) when fixp n and n > 0,

     LegendreP (~n,~m,~x) => (-1)^m *(1-x^2)^(m/2)*
                                sub(!=z = x,df(LegendreP (n,!=z),!=z,m))
                        when fixp n and n > 0 and fixp m and m > 0,
     JacobiP (~n,~a,~b,~x) =>
            (1/2^n * for ii:=0:n sum (binomial(n+a,ii) *
                binomial(n+b,n-ii)*(x-1)^(n-ii)*(x+1)^ii))
                when fixp n and n > 0 and numberp a and a > -1
                and numberp b and b > -1,
     JacobiP (~n,~a,~b,~x) => sub(!=z = x
                        ,first reverse legendre_base (!=z,n,a,b))
                        when fixp n and n > 0,
     LegendreP (0,~x) => 1,
     LegendreP (0,0,~x) => 1,
     JacobiP (0,~a,~b,~x) => 1};

let{ LaguerreP(~n,~x) =>  LaguerreP(~n,0,~x) when fixp n and n > 0,
        %  (for ii:=0:n sum (binomial(n,n-ii) *
        %        (-1)^ii/factorial ii *x^(ii)))
        %               when fixp n and n > 0,

     LaguerreP(~n,~alpha,~x) => (begin scalar b1,b2,bex,r;
                                r := 1; b1 := 1-x+alpha; b2 := 1;
                                for i:= 1:(n-1) do <<
                                bex := (1+2r-x+alpha)/(r+1)*b1 -
                                         (r+alpha)/(r+1)*b2;
                                r := r+1; b2 := b1; b1 := bex;
                                >>;
                                return b1; end)
                when fixp n and n > 0 and numberp alpha and numberp x ,

     LaguerreP(~n,~alpha,~x) =>
        %  (for ii:=0:n sum (binomial(n+alpha,n-ii) *
        %        (-1)^ii/factorial ii *x^(ii)))
        %               when fixp n and n > 0,
        (begin scalar k,tmp,result,ratio,oldslash,powlis1!*;
          lisp setq(oldslash,remprop('slash,'opmtch));
          % tmp:=subs(k=0,term);
          if n=0 then return(1);
          tmp:=(for j:=1:n product (j+alpha))/factorial(n);
          % tmp:=prod(j+alpha,j,1,n)/factorial(n);
          result:=tmp;
          % Ratio:=ratio(term,k);
          ratio:=-1/(alpha+k+1)*(n-k)*x/(k+1);
          for k:=0:n do
          <<
          % tmp:=tmp*Ratio;
            tmp:=-tmp/(alpha+k+1)*(n-k)*x/(k+1);
            result:=result+tmp;
          >>;
          lisp put('slash,'opmtch,oldslash); % restore
          return(result);
          end)  when fixp n and n > 0,

     LaguerreP(0,~a,~x) => 1};

let {ChebyshevT (~n,~x) =>
        %(n/2*for ii:=0:floor(n/2) sum ((-1)^ii*factorial (n-ii-1) /
        %   (factorial(ii) *factorial(n -2ii))* (2*x)^(n-2ii)))
        (begin
        scalar k,tmp,result,ratio,oldslash,powlis1!*;
          lisp setq(oldslash,remprop('slash,'opmtch));
          if n=0 then return(1);
          if n=1 then return(x);
          % tmp:=subs(k=0,term);
          tmp:=2**(n-1)*x**n;
          result:=tmp;
          % Ratio:=ratio(term,k);
          ratio:=-1/4*(n-2*k)*(n-2*k-1)/x**2/(n-k-1)/(k+1);
          for k:=0:n/2-1 do
          <<
          % tmp:=tmp*eval(Ratio);
            tmp:=-tmp/4*(n-2*k)*(n-2*k-1)/x**2/(n-k-1)/(k+1);
            result:=result+tmp;
          >>;
          lisp put('slash,'opmtch,oldslash); % restore
          return(result);
        end) when fixp n and n > 0 and not numberp x,

        ChebyshevT (~n,~x) =>
         (begin
           if n=0 then return(1) else if n=1 then return(x) else
           if (floor(n/2)=n/2) then return(2*ChebyshevT(n/2,x)^2-1)
           else return(2*ChebyshevT((n-1)/2,x)*ChebyshevT((n+1)/2,x)-x)
          end) when fixp n and n > 0 and numberp x,

     ChebyshevT (0,~x) => 1};

let {ChebyshevU (~n,~x) =>
        %(for ii:=0:floor(n/2) sum ((-1)^ii*factorial (n-ii) /
        % (factorial(ii) *factorial(n -2ii))* (2*x)^(n-2ii)))
        (begin
        scalar k,tmp,result,ratio,oldslash,powlis1!*;
          lisp setq(oldslash,remprop('slash,'opmtch));
          if n=0 then return(1);
          % tmp:=subs(k=0,term);
          tmp:=2**n*x**n;
          result:=tmp;
          % Ratio:=ratio(term,k);
          ratio:=-1/4/(n-k)*(n-2*k)*(n-2*k-1)/x**2/(k+1);
          for k:=0:n/2 do
          <<
          % tmp:=tmp*eval(Ratio);
            tmp:=-tmp/4/(n-k)*(n-2*k)*(n-2*k-1)/x**2/(k+1);
            result:=result+tmp;
          >>;
          lisp put('slash,'opmtch,oldslash); % restore
          return(result);
        end) when fixp n and n > 0 and not numberp x,

        ChebyshevU (~n,~x) =>
        ( begin
          if n=0 then return(1) else if n=1 then return(2*x) else
          if evenp n
            then return(2*ChebyshevT(n/2,x)*ChebyshevU(n/2,x)-1)
          else return(2*ChebyshevU((n-1)/2,x)*ChebyshevT((n+1)/2,x))
        end) when fixp n and n > 0 and numberp x,

     ChebyshevU (0,~x) => 1};

let { GegenbauerP (~n,~a,~x) => (begin scalar b1,b2,bex,r;
                                r := 1; b1 := 2*a*x; b2 := 1;
                                for i:= 1:(n-1) do <<
                                bex := 2*(r+a)/(r+1)*x*b1 -
                                         (r+2*a-1)/(r + 1)*b2;
                                r := r+1; b2 := b1; b1 := bex;
                                >>;
                                return b1; end)
                when fixp n and n > 0 and numberp a and numberp x ,
        GegenbauerP (~n,~a,~x) =>
        %       (1/Gamma(a)*for ii:=0:floor(n/2) sum
        %((-1)^ii* gamma(a+n-ii)/(factorial ii *factorial(n-2ii))*
        % (2*x)^(n-2ii)))
        (begin scalar k,tmp,result,ratio,oldslash,powlis1!*;
          lisp setq(oldslash,remprop('slash,'opmtch));
          % tmp:=subs(k=0,term);
          tmp:=(for j:=1:n product (a+j-1))/factorial(n)*2**n*x**n;
          % tmp:=prod(a+j-1,j,1,n)/factorial(n)*2**n*x**n;
          result:=tmp;
          % Ratio:=ratio(term,k);
          ratio:=-1/4/(a+n-k-1)*(n-2*k)*(n-2*k-1)/x**2/(k+1);
          for k:=0:n/2 do
          <<
          % tmp:=tmp*eval(Ratio);
            tmp:=-tmp/4/(a+n-k-1)*(n-2*k)*(n-2*k-1)/x**2/(k+1);
            result:=result+tmp;
          >>;
          lisp put('slash,'opmtch,oldslash); % restore
          return(result);
        end)
        when fixp n and n > 0 and not(a=0),

     GegenbauerP (~n,0,~x) =>
        %(for ii:=0:floor(n/2) sum
        %((-1)^ii* factorial(n-ii-1)/(factorial ii *factorial(n-2ii))*
        %        (2*x)^(n-2ii)))
        (begin
        scalar k,tmp,result,ratio,oldslash,powlis1!*;
          lisp setq(oldslash,remprop('slash,'opmtch));
          % tmp:=subs(k=0,term);
          tmp:=2**n*x**n/n;
          result:=tmp;
          % Ratio:=ratio(term,k);
          ratio:=-1/4*(n-2*k)*(n-2*k-1)/x**2/(n-k-1)/(k+1);
          for k:=0:n/2 do
          <<
          % tmp:=tmp*eval(Ratio);
            tmp:=-tmp/4*(n-2*k)*(n-2*k-1)/x**2/(n-k-1)/(k+1);
            result:=result+tmp;
          >>;
          lisp put('slash,'opmtch,oldslash);
          return(result);
        end) when fixp n and n > 0 ,

%    gegenbauerP (~n,~a,~x) => sub(!=z = x,
%                               first reverse gegenbauer_base(!=z,n,a))
%                       when fixp n and n > 0,

     GegenbauerP (0,~a,~x) => 1};

% rules for differentiation

let {% AS (8.5.4)
df(LegendreP(~a,~b,~z),z)  => 1/(1-z^2)*
        ((a+b)*LegendreP(a-1,b,z) - a*z*LegendreP(a,b,z)),
df(LegendreP(~n,~z),z) => n/(1-z^2)*(LegendreP(n-1,z)-z*LegendreP(n,z)),
df(LegendreQ(~a,~b,~z),z)  => 1/(1-z^2)*
        ((a+b)*LegendreQ(a-1,b,z) - a*z*LegendreQ(a,b,z)),
% AS (22.8)
df(JacobiP(~n,~a,~b,~z),z) => 1/((1-z^2)*(2*n+a+b))*
        (2*(n+a)*(n+b)*JacobiP(n-1,a,b,z)+n*(a-b-(2*n+a+b)*z)
          *JacobiP(n,a,b,z)),
df(GegenbauerP(~n,~a,~z),z) => 1/(1-z^2)*
        ((n+2*a-1)*GegenbauerP(n-1,a,z)-n*z*GegenbauerP(n,a,z)),
df(ChebyshevT(~n,~z),z) =>
                   1/(1-z^2)*(n*ChebyshevT(n-1,z)-n*z*ChebyshevT(n,z)),
df(ChebyshevU(~n,~z),z) => 1/(1-z^2)*
        ((n+1)*ChebyshevU(n-1,z)-n*z*ChebyshevU(n,z)),
df(LaguerreP(~n,~a,~z),z) =>
        1/z*(-(n+a)*LaguerreP(n-1,a,z)+n*LaguerreP(n,a,z)),
df(LaguerreP(~n,~z),z) => 1/z*(-(n)*LaguerreP(n-1,z)+n*LaguerreP(n,z)),
df(HermiteP(~n,~z),z) => 2*n*HermiteP(n-1,z),
% AS (23.1.5)
df(bernoullip(~n,~z),z) => n*bernoullip(n-1,z),
% AS (23.1.5)
df(eulerp(~n,~z),z) => n*eulerp(n-1,z) };
>>;

% following ideas from John Abbott and Wolfram Koepf
% FIBONACCI NUMBERS (and Polynoms)

flag('(fibonacci fibonaccip),'opfn);
flag('(fibonacci),'integer);
put('fibonacci,'number!-of!-args,1);

symbolic procedure fibonacci(n);
 if not fixp n then mk!*sq !*kk2q list('fibonacci, n)
  else if n=0 then 0
  else if n=1 or n=-1 then 1
  else
  begin integer i3; scalar sgn;
   if n < 0 then << sgn := t; n := -n >>;
   i3 := fibonacci!:aux1 (n);
   return if sgn and evenp n then (-i3) else i3;
  end;

global '(fibonacci!:alist);

symbolic << fibonacci!:alist := '((0 . 0)
                (1 . 1) (2 . 1) (3 . 2) (4 . 3) (5 . 5)
                (6 . 8) (7 . 13) (8 . 21) (9 . 34)) >>;

symbolic procedure fibonacci!:aux1 (n);
   begin scalar fi;
         fi := atsoc (n,fibonacci!:alist);
         if fi then return cdr fi;
         fi :=  fibonacci!:aux2 n;
         fibonacci!:alist := (n . fi) . fibonacci!:alist;
         return fi;
      end;

symbolic procedure fibonacci!:aux2 (n); % from Wolfram Koepf, Sep 1998
                % d'apres Knuth & Patachnik: Concrete Mathematics
  if evenp n then (f*(f+2*fibonacci!:aux1(n/2-1))) where f=fibonacci!:aux1(n/2)
   else (fibonacci!:aux1((n+1)/2)^2 + fibonacci!:aux1((n-1)/2)^2);

symbolic procedure fibonaccip(n,x);
 if not fixp n or not idp x then mk!*sq !*kk2q list('fibonaccip,n,x)
  else if n=0 or n=1 then n
  else begin scalar i3,i2,i1,sgn;
   if n < 0 then << sgn := t; n := -n >>;
   i2 := 1; i1 := 0; i3 := 0;
   for i:=2:n do << i3 := aeval list('plus,list('times, x ,i2),i1);
                    i1 := i2; i2 := i3 >>;
%   return reval (list('times,list('expt,m1,list('plus,n,1)),i3));
   return if sgn and evenp n then aeval list('minus,i3) else i3;
  end;


endmodule;

end;
