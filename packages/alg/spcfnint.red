module spcfnint; % Simplification rules for special functions.

% Copyright (c) 1993 The RAND Corporation. All rights reserved.

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


algebraic;

% from specfn/sfconsts.red

symbolic procedure compute!:Euler!:gamma ();
  if not(!*rounded) then mk!*sq('((((Euler_gamma . 1) . 1)) . 1))
         else aeval '(minus (psi 1));

symbolic operator compute!:Euler!:gamma;

let Euler_gamma => compute!:Euler!:gamma();

let  Golden_Ratio = (1 + sqrt(5))/2; % for Architects


symbolic procedure compute!:catalan ();
  if not(!*rounded) then mk!*sq('((((catalan . 1) . 1)) . 1)) else
   begin scalar ii,j,p,tt,s,g,!*rounded;
      g := !:prec!: + length explode !:prec!: + 3;
      p := 10^g/2;
      tt := p; s := tt; j :=1; ii := 1;
      while tt > 0 do
        << j := j+2; p := (p*ii) / j; tt := (tt * ii + p)/j;
           s := s + tt; ii := ii + 1 >>;
      return list('quotient,s,10^(g));
  end;

symbolic operator compute!:catalan;

let catalan => compute!:catalan();


% Khinchin's constant =(prod((1+1/(n*(n+2)))^(ln n/ln2),n,1,infinity))
%
% translated from a (Maple code) posting by Paul Zimmermann
%       in sci.math.symbolic
%

symbolic procedure compute!:Khinchin();
 (if not(!*rounded) then mk!*sq('((((Khinchin . 1) . 1)) . 1)) else
    aeval ('compute!:Khinchin1 . nil)) where !:prec!: = !:prec!: ;

symbolic operator compute!:Khinchin;

let Khinchin => compute!:Khinchin();


% from specfn/sfgen.red

operator bernoulli;
symbolic operator bernoulli!*calc;

bernoullirules := {

   bernoulli(~n)  =>  1 when numberp n and n = 0,
   bernoulli(~n)  =>  -1/2 when numberp n and n = 1,
   bernoulli(~n)  =>  0 when numberp n and impart n = 0
      and n = floor n and n/2 neq floor (n/2) and n > 0,
   bernoulli(~n)  =>  bernoulli!*calc n when numberp n
      and impart n = 0 and n = floor n and n > 0

};

let bernoullirules;

operator Euler;

let {   Euler(0)  => 1,
        Euler(~n) => Euler!:aux(n) when fixp n and n > 0};

symbolic operator euler!:aux;


% Gamma function and friends

operator gamma,m_gamma; % m_gamma is the incomplete gamma
 % function which happens to be produced by definite integration.

symbolic (operator do!*gamma);

gamma!*rules := {

   gamma(~x)  =>  1 when numberp x and x = 1,
   gamma(~x)  =>  sqrt(pi) when numberp x and x = (1/2),

   gamma(~x)  =>  factorial (x-1)
      when numberp x and impart x = 0
         and x = floor x and x > 0,

%  gamma(~x)  =>  infinity
%     when numberp x and impart x = 0
%        and x = floor x and x < 1,

   gamma(~x)  =>  gamma(x-1) * (x-1)
      when numberp x and not symbolic !*rounded
       and impart x = 0 and (64*x) = floor(64*x) and x > 1 and x < 50,

   gamma(~x)  =>  pi / (sin(pi*x) * gamma(-x) * (-x))
      when numberp x and x < 0 and not (fixp x and x < 1),

   gamma(~x)  =>  do!*gamma(x)
      when numberp x and not (fixp x and x < 1) and symbolic !*rounded,

   df(gamma(~x), x)  =>  gamma(x) * psi(x)

};

let gamma!*rules;


% beta function

operator beta;

beta!*rules := {

beta(~z,~w)  =>  (gamma(z) * gamma(w)) / gamma(z+w)
   when (numberp z and numberp w and impart z = 0 and impart w = 0
         and not ((z = floor z and z < 1)
               or (w = floor w and w < 1)
               or (z+w = floor (z+w) and (z+w) < 1)))
     or (numberp z and numberp w
         and (impart z neq 0 or impart w neq 0))
     or not (numberp z and numberp w),

beta(~z,~w)  =>  0
   when numberp z and numberp w and impart z = 0 and impart w = 0
      and not ((z = floor z and z < 1)
            or (w = floor w and w < 1))
      and (z+w = floor (z+w) and (z+w) < 1)

%beta(~z,~w)  =>  Infinity
%   when numberp z and numberp w and impart z = 0 and impart w = 0
%      and ((z = floor z and z < 1)
%        or (w = floor w and w < 1))
%      and not (z+w = floor (z+w) and (z+w) < 1)

};

let beta!*rules;


Comment Ruleset for calculating the Pochhammer symbol
        Author:  Wolfram Koepf, Freie Universitaet Berlin 1992,
        Translated to Reduce syntax by Winfried Neun, ZIB Berlin.
        Made generally safer (and uglier) by Chris Cannam, ZIB.
        ;


algebraic operator pochhammer;
symbolic operator do!*pochhammer;

pochhammer!*rules := {

df(pochhammer(~z,~k),~z) => pochhammer(~z,~k) * (Psi(z+k)-Psi(z)),

pochhammer(~z,~k)  => (-1)^k*factorial(-z)/factorial(-z-k)
   when fixp z and z<0,

pochhammer(~z,~k)  =>  ( for i:=0:(k-1) product(z + i))
   when numberp k and k < 20 and k > 0,

pochhammer(~z,~k)  =>  1
   when numberp k and k = 0,

pochhammer(~z,~k)  => factorial(z+k-1)/factorial(z-1)
   when fixp z and z > 0,

pochhammer(~z,~k -1)  =>
   2 * pochhammer(1/2,k) / (2*k -1)
      when numberp z and z = 1/2,

pochhammer(~a,~k)  =>
   factorial(2k)/((4^k) * factorial(k))
      when numberp a and a = 1/2,

pochhammer(~n,~k)  =>
   do!*pochhammer(n,k)
      when numberp n and numberp k
         and impart n = 0 and impart k = 0
            and n = floor n and k = floor k
               and n > -1 and k > 0,

pochhammer(~a,~k)  =>
   do!*pochhammer(a,k)
      when symbolic !*rounded
         and numberp k and numberp a
            and impart a = 0 and impart k = 0
               and ((a neq floor a) or (a > 0))
                  and k = floor k and k > 0,

pochhammer(~n,~k)  =>
   (-1)^k * factorial(-n) / factorial(-n-k)
      when numberp n and numberp k
         and impart n = 0
            and n = floor n and n < 1 and (-n-k) >= 0,

pochhammer(~a,~k)  =>
   pochhammer(2*a-1,2k)/((4^k) * pochhammer((2 a -1)/2,k))
      when numberp a and impart a = 0
         and (a+1/2) = floor (a+1/2) and a > 0,

pochhammer(~a,~k)  =>
   (-1)^(-a+1/2) * Pochhammer(1-a-(-a+1/2),(-a+1/2)) *
                   Pochhammer(a+(-a+1/2),k-(-a+1/2))
      when numberp a and impart a = 0
         and (a+1/2) = floor (a+1/2) and a < 0

};

special!*pochhammer!*rules := {

        % these special rules are normally disabled because
        % they produce a lot of load for the algebraic mode

pochhammer(~a,~k)*pochhammer(~b,~k)  =>
   pochhammer(2a,2k)/(4^k)
      when (b-a)=1/2,

pochhammer(~a,~k)  =>
   (-1)^(-a+1/2) * pochhammer(1-a-(-a+1/2),-a+1/2) *
      pochhammer(a +(-a +1/2),k-(-a+1/2))
         when numberp a and impart a = 0
            and (a+1/2) = floor (a+1/2) and a<0,

pochhammer(~z,~k) * pochhammer(~cz,~k)  =>
   do!*poch!*conj!*calc(z,k)
      when numberp z and numberp cz and numberp k
         and not(impart z = 0) and z = conj cz
            and impart k = 0 and k = floor k and k >= 0,

pochhammer(~a,~k)*pochhammer(~aa,~k)  =>
   factorial(3 k)/(factorial(k) * 27^k)
      when numberp a and a = 1/3 and numberp aa and aa = 2/3,

pochhammer(~a,~k) * pochhammer(~aa,~k)  =>
   factorial(1 + 3 k)/(27 ^k * factorial(k))
      when numberp a and a = 2/3 and numberp aa and aa = 4/3,

pochhammer(~b,~k) * pochhammer(~c,~k)  =>
   pochhammer(3*b,3*k)/( 27^k * pochhammer(b +2/3,k))
      when numberp b and numberp c
         and (c-b)=1/3 and (b-1/3) = floor (b-1/3) and not (b-1/3 = 0),

pochhammer(~a,~k)*pochhammer(~aa,~k)*pochhammer(~aaa,~k)  =>
   factorial(4*k)/(factorial(k) * 64^k)
      when numberp a and numberp aa and numberp aaa
         and a = 1/4 and aa = 1/2 and aaa = 3/4,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   factorial(5*k)/(factorial(k) * 3125^k)
      when numberp a and numberp aa
         and numberp aaa and numberp aaaa
            and a = 1/5 and aa = 2/5 and aaa = 3/5 and aaaa = 4/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   5*(1/5 +k)*factorial(5*k)/(factorial(k) * 3125^k)
      when numberp a and numberp aa
         and numberp aaa and numberp aaaa
            and a = 2/5 and aa = 3/5 and aaa = 4/5 and aaaa = 6/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   (25 *(1/5+k)*(2/5 +k)*factorial(5*k)) / (factorial(k) * 2* 3125^k)
      when numberp a and numberp aa
         and numberp aaa and numberp aaaa
            and a = 3/5 and aa = 4/5 and aaa = 6/5 and aaaa = 7/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   (125*(1/5+k)*(2/5+k)*(3/5+k)*factorial(5*k)) /
      (factorial(k) * 6 *3125^k)
         when numberp a and numberp aa
            and numberp aaa and numberp aaaa
               and a = 4/5 and aa = 6/5 and aaa = 7/5 and aaaa = 8/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   (625*(1/5+k)*(2/5+k)*(3/5+k)*(4/5+k)*factorial(5*k)) /
      (factorial(k) * 24 *3125^k)
         when numberp a and numberp aa
            and numberp aaa and numberp aaaa
               and a = 6/5 and aa = 7/5 and aaa = 8/5 and aaaa = 9/5,

Pochhammer(~a,~k)//Pochhammer(~b,~k)  => (a + k -1)/(a - 1)
                        when (a - b)=1,

Pochhammer(~a,~k)//Pochhammer(~b,~k)  => (b - 1)/(b + k -1)
                        when (b - a)=1
};

let pochhammer!*rules;


% from specfn/sfpsi.red

algebraic operator psi, polygamma;

psi!*rules := {

   psi(~x,~xx) => polygamma(x,xx),

   psi(~z)  =>  infinity
      when repart z = floor repart z and impart z = 0 and z < 1,

   psi(~z)  =>  -euler!*constant
      when numberp z and z = 1
               and symbolic !*rounded and precision(0) < 501,

   psi(~z)  =>  -euler!*constant - 2 * log(2)
      when numberp z and z = (1/2)
               and symbolic !*rounded and precision(0) < 501,

   psi(~z)  =>  do!*psi(z)
      when numberp z and impart z = 0 and symbolic !*rounded,

   psi(~z)  =>  (psi(z/2) + psi((z+1)/2) + 2 * log(2)) / 2
      when numberp z and impart z = 0
               and (z/2) = floor (z/2)
                  and z > 0 and not symbolic !*rounded,

   psi(~z)  =>  psi(z-1) + (1 / (z-1))
      when numberp z and impart z = 0
               and z > 1 and not symbolic !*rounded,

   psi(~z)  =>  psi(1-z) + pi*cot(pi*(1-z))
      when numberp z and impart z = 0
               and z < 0 and not symbolic !*rounded,

   psi(~z)  =>  psi(1-z) + pi*cot(pi*(1-z))
      when numberp z and impart z = 0
         and z > 1/2 and z < 1 and not symbolic !*rounded,

   df(psi(~z),z)  =>  polygamma(1, z),

   int(psi(~z),z)  =>  log gamma(~z)

};

let psi!*rules;

psi_rules := {
   % Rule for integer shifts (x + 3), and non-integer shifts (x + 3/2)in
   % a non-integer number domain (on rational) or with "on intstr, div":
   psi(~x+~n) => psi(x+n-1) + 1/(x+n-1) when numberp n and n >= 1,
   psi(~x+~n) => psi(x+n+1) - 1/(x+n) when numberp n and n < 0,
   polygamma(~m,~x+~n) => polygamma(m,x+n-1)+(-1)^m*factorial(m)
        /(x+n-1)^(m+1) when numberp n and fixp m and n >= 1,
   polygamma(~m,~x+~n) => polygamma(m,x+n+1)-(-1)^(m)*factorial(m)
        /(x+n)^(m+1) when numberp n and fixp m and n < 0,
   % Rule for rational shifts (x + 3/2) in the default (integer) number
   % domain and rational arguments (x/y + 3):
   psi((~x+~n)/~d) => psi((x+n-d)/d) + d/(x+n-d) when
      numberp(n/d) and n/d >= 1,
   psi((~x+~n)/~d) => psi((x+n+d)/d) - d/(x+n) when
      numberp(n/d) and n/d < 0,
   polygamma(~m,(~x+~n)/~d) => polygamma(m,(x+n-d)/d) +
      (-1)^m*factorial(m)*d^(m+1)/(x+n-d)^(m+1) when
      fixp m and numberp(n/d) and n/d >= 1,
   polygamma(~m,(~x+~n)/~d) => polygamma(m,(x+n+d)/d) -
      (-1)^m*factorial(m)*d^(m+1)/(x+n)^(m+1) when
      fixp m and numberp(n/d) and n/d < 0
};
% NOTE: The rational-shift rule does not work with "on intstr, div".

let psi_rules;

symbolic operator polygamma!*calc, trigamma!*halves, polygamma!:error,
                  polygamma_aux;

polygamma!*rules := {

   polygamma(~n,~x)  =>  polygamma!:error(n,x)
        when numberp n and (not fixp n or n < -1),

   polygamma(~n,~x)  =>  psi(x)
      when numberp n and n = 0,

   polygamma(~n,~x)  =>  infinity
      when numberp x and impart x = 0 and x = floor x and x < 1,

   polygamma(~n,~x)  =>  do!*trigamma!*halves(x)
      when numberp n and n = 1 and numberp x and impart x = 0
               and (not (x = floor x) and ((2*x) = floor (2*x))) and x > 1,

   polygamma(~n,~x)  =>  ((-1) ** (n)) * (factorial n) * (- zeta(n+1) +
                         polygamma_aux(x,n))
      when fixp x and x >= 1 and not symbolic !*rounded,

   polygamma(~n,~x)  => ((-1)**n) * factorial n * (-2 * (2**n) *
               zeta(n+1) + 2 * (2**n) + zeta(n+1))
      when numberp x and x = (3/2) and not symbolic !*rounded,

   polygamma(~n,~x)  =>  do!*polygamma(n,x)
      when numberp x and symbolic !*rounded
               and numberp n and impart n = 0 and n = floor n,

   df(polygamma(~n,~x), ~x)  =>  polygamma(n+1, x),

   int(polygamma(~n,~x),~x)  =>  polygamma(n-1,x)

};

let polygamma!*rules;

operator zeta;
symbolic operator zeta!*calc, zeta!*pos!*intcalc;

zeta!*rules := {

   zeta(~x)  =>  (- (1/2))
      when numberp x and x = 0,

   zeta(~x)  =>  (pi ** 2) / 6
      when numberp x and x = 2,

   zeta(~x)  =>  (pi ** 4) / 90
      when numberp x and x = 4,

   zeta(~x)  =>  infinity
      when numberp x and x = 1,

   zeta(~x)  =>  0
      when numberp x and impart x = 0 and x < 0 and (x/2) = floor(x/2),

   zeta(~x)  =>  ((2*pi)**x) / (2*factorial x)*(abs bernoulli!*calc x)
      when numberp x and impart x = 0 and x > 0
               and (x/2) = floor (x/2) and x < 31,

   zeta(~x)  =>  - (bernoulli!*calc (1-x)) / (1-x)
      when numberp x and impart x = 0 and x < 0
               and x = floor x and x > -31,

   zeta(~x)  =>  ((2*pi)**x)/(2 * factorial x)*(abs bernoulli!*calc x)
      when numberp x and impart x = 0 and x > 0
               and (x/2) = floor(x/2) and x < 201 and symbolic !*rounded,

   zeta(~x)  =>  - (bernoulli!*calc (1-x)) / (1-x)
      when numberp x and impart x = 0 and x < 0
               and x = floor x and x > -201 and symbolic !*rounded,

   zeta(~x)  =>  (2**x)*(pi**(x-1))*sin(pi*x/2)*gamma(1-x)*zeta(1-x)
      when numberp x and impart x = 0 and x < 0
               and (x neq floor x or x < -200) and symbolic !*rounded,

   zeta(~x)  =>  do!*zeta!*pos!*intcalc(fix x)
      when symbolic !*rounded and numberp x and impart(x) = 0 and x > 1
               and x = floor x and (x <= 15 or precision 0 > 100
                  or 2*x < precision 0),

   zeta(~x)  =>  do!*zeta(x)
      when numberp x and impart x = 0% and x > 1
               and symbolic !*rounded,

   df(zeta(~x),x)  =>  -(1/2)*log(2*pi)
      when numberp x and x = 0

};

let zeta!*rules;


% from specfn/sfigamma.red

operator igamma, ibeta;

% Set up rule definitions for igamma and ibeta functions.

let
{
 igamma(~a,~x) => igamma!:eval(a,x)
        when numberp(a) and numberp(x) and a>0 and x>=0 and lisp !*rounded,

 igamma(~a,0) => 0,

% igamma(0,~x) => -ei(-x),

 igamma(~a,~x) => erf(sqrt(x)) when numberp(a) and a=1/2,

 igamma(1,~x) => 1-exp(-x),

 df(igamma(~a,~x),~x) => x^(a-1)*exp(-z) / gamma(a)
};

let
{
 ibeta(~a,~b,~x) => ibeta!:eval(a,b,x)
        when numberp(a) and numberp(b) and numberp(x) and lisp !*rounded
             and repart(a)>0 and repart(b)>0 and x>=0 and x<=1,

 ibeta(~a,1,~x) => x^a,
 ibeta(1,~b,~x) => 1 - (1-x)^b,

 df(ibeta(~a,~b,~x),~x) => (1-x)^(b-1)*x^(a-1) / beta(a,b),

 ibeta(~a,~b,~x) => int(t^(a-1)*(1-t)^(b-1),t,0,x) / beta(a,b)
        when numberp a and fixp a and a>0 and a<6 and
             numberp b and fixp b and b>0 and b<6
};

endmodule;

end;
