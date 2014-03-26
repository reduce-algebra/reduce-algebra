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

let pochhammer!*rules;


endmodule;

end;
