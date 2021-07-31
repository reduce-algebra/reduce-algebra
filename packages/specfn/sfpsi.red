module sfpsi; % Procedures relevant to the digamma, polygamma & zeta
              % functions.

% Author: Chris Cannam, Sept/Oct '92.

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

% Added: PSI_SIMP.RED  F.J.Wright, 2 July 1993
%        The polygamma rules are added by Y.K. Man on 9 July 1993

%        Yiu K. Man's email is: myk@maths.qmw.ac.uk

imports sq2bf!*, sf!*eval;
exports rdpsi!*, crpsi!*, do!*polygamma, do!*trigamma!*halves,
   do!*zeta, do!*zeta!*pos!*intcalc;


%
% A couple of global values are used (from specfns.red) which can speed
% up psi calculations (a bit) when repeated calculations are made at the
% same level of precision.

global '(bfz!* bfhalf!* bftwo!*);

fluid '(compute!-bernoulli !*!*roundbf !*roundbf);

%%fluid '(psi!*ld!*0 psi!*ld!*1);

%%flag('(psi!*ld!*0 psi!*ld!*1),'share);

%
% Here's an approximation sufficiently good for most purposes
%   (assuming it's right, that is); if it isn't good enough, it
%   won't be used.  This approximation is to 506 dec. places.
%

COMMENT 

The original code ran in algebraic mode and consequently defined rules and variable
assignments (e.g., to euler!*constant in algebraic mode. This conflicted with
autoloading, since autoloading can happen at any time, even during rule processing
when algebraic mode assignments are not possible
;

% bigfloat approximation to 500 digits
set!:const('!:euler_gamma,
           '(-1 57721 566490 1532 86060 65120 90082 40243 10
                42159 33593 99235 98805 76723 48848 67726 7776
      	        64670 93694 70632 91746 74951 46314 47249 80708
                24809 605040 1448 65428 36224 17399 76449 23536
                253500 3337 42937 33773 76739 42792 59525 82470
                9491 600873 52039 48165 67085 32331 51776 61152
                86211 99501 50798 47937 45085 7057400 299 21354
                78614 66940 29604 32542 15190 58775 53526 73313
                992540 1296 74205 13754 13954 91116 85102 80798
                42348 77587 20503 84310 93997 36137 25530 60889
                33126 76001 72479 53783 67592 71351 57722 61027
                34929 13940 798430 1034 17771 77808 81549 57066
                10750 10161 91663 34015 22789 35868) );

symbolic procedure !:euler_gamma k;
% This function calculates the value of the constant "Euler_gamma",
%      by calculating the value of the digamma function at point 1.
% K is a positive integer.
if not fixp k or k <= 0 then bflerrmsg '!:euler_gamma
 else begin scalar u;
    u := get!:const('!:euler_gamma, k);
    if u neq 'not_found then return u;
    u := rdpsi!:(bfone!*,k);
    if denr u neq 1 or not rdp u then bflerrmsg '!:euler_gamma
     else <<u:= !:minus numr u;
    	    save!:const('!:euler_gamma,u);
            return u>>;
 end;

symbolic procedure rd_euler!*;
   mkround if !*!*roundbf then !:euler_gamma !:bprec!: else bf2flr !:euler_gamma !!nbfpd;

symbolic procedure cr_euler!*;
  mkcr(rd_euler!*(),rdzero!*());


%
% Define some suitable rules for initial simplification of psi
%   (digamma) function expressions.
%
% Comments:
%
%  When rounded mode is on, psi(number) is always computed
%     directly unless it simplifies to an expression in psi(1/2) or
%     psi(1), in which case it is simplified. Expressions in psi(1/2)
%     and psi(1) are expanded into expressions in euler!*constant.
%     If, however, the precision is greater than 500, then
%     euler!*constant is not stored sufficiently precisely, and all
%     such expressions will be computed without simplification.
%
% When rounded mode is off, psi(number) will _never_ be expanded
%     into an expression involving euler!*constant, but will always
%     be expanded into some form involving psi(p), where 0<p<1.
%     It should be borne in mind that computations which will need
%     numerical results could do without such expansion, and there-
%     fore such computations should be performed in rounded mode
%     as soon as possible.
%
% Expressions for the derivative and integral of psi are included.
%

%% rules moved to alg/spcfnint.red
%%
%%algebraic operator psi, polygamma;
%%symbolic operator psi!*calc;
%%
%%algebraic (psi!*rules := {
%%
%%   psi(~x,~xx) => polygamma(x,xx),
%%
%%   psi(~z)  =>  infinity
%%      when repart z = floor repart z and impart z = 0 and z < 1,
%%
%%   psi(~z)  =>  -euler!*constant
%%      when numberp z and z = 1
%%               and symbolic !*rounded and precision(0) < 501,
%%
%%   psi(~z)  =>  -euler!*constant - 2 * log(2)
%%      when numberp z and z = (1/2)
%%               and symbolic !*rounded and precision(0) < 501,
%%
%%   psi(~z)  =>  do!*psi(z)
%%      when numberp z and impart z = 0 and symbolic !*rounded,
%%
%%   psi(~z)  =>  (psi(z/2) + psi((z+1)/2) + 2 * log(2)) / 2
%%      when numberp z and impart z = 0
%%               and (z/2) = floor (z/2)
%%                  and z > 0 and not symbolic !*rounded,
%%
%%   psi(~z)  =>  psi(z-1) + (1 / (z-1))
%%      when numberp z and impart z = 0
%%               and z > 1 and not symbolic !*rounded,
%%
%%   psi(~z)  =>  psi(1-z) + pi*cot(pi*(1-z))
%%      when numberp z and impart z = 0
%%               and z < 0 and not symbolic !*rounded,
%%
%%   psi(~z)  =>  psi(1-z) + pi*cot(pi*(1-z))
%%      when numberp z and impart z = 0
%%         and z > 1/2 and z < 1 and not symbolic !*rounded,
%%
%%   df(psi(~z),z)  =>  polygamma(1, z),
%%
%%   int(psi(~z),z)  =>  log gamma(~z)
%%
%%})$
%%
%%algebraic (let psi!*rules);


% PSI_SIMP.RED  F.J.Wright, 2 July 1993
% The polygamma rules are added by Y.K. Man on 9 July 1993

% Support for the psi operator.
% =============================
% psi(x) = df(log Gamma(x), x) as in specfn package, etc.
% The specfn package does not currently provide the required
% simplifications.

%% algebraic;

% Simplify to "standard form" in which argument is allowed a numeric
% shift in the range 0 <= shift < 1:

%%psi_rules := {
%%   % Rule for integer shifts (x + 3), and non-integer shifts (x + 3/2)in
%%   % a non-integer number domain (on rational) or with "on intstr, div":
%%   psi(~x+~n) => psi(x+n-1) + 1/(x+n-1) when numberp n and n >= 1,
%%   psi(~x+~n) => psi(x+n+1) - 1/(x+n) when numberp n and n < 0,
%%   polygamma(~m,~x+~n) => polygamma(m,x+n-1)+(-1)^m*factorial(m)
%%        /(x+n-1)^(m+1) when numberp n and fixp m and n >= 1,
%%   polygamma(~m,~x+~n) => polygamma(m,x+n+1)-(-1)^(m)*factorial(m)
%%        /(x+n)^(m+1) when numberp n and fixp m and n < 0,
%%   % Rule for rational shifts (x + 3/2) in the default (integer) number
%%   % domain and rational arguments (x/y + 3):
%%   psi((~x+~n)/~d) => psi((x+n-d)/d) + d/(x+n-d) when
%%      numberp(n/d) and n/d >= 1,
%%   psi((~x+~n)/~d) => psi((x+n+d)/d) - d/(x+n) when
%%      numberp(n/d) and n/d < 0,
%%   polygamma(~m,(~x+~n)/~d) => polygamma(m,(x+n-d)/d) +
%%      (-1)^m*factorial(m)*d^(m+1)/(x+n-d)^(m+1) when
%%      fixp m and numberp(n/d) and n/d >= 1,
%%   polygamma(~m,(~x+~n)/~d) => polygamma(m,(x+n+d)/d) -
%%      (-1)^m*factorial(m)*d^(m+1)/(x+n)^(m+1) when
%%      fixp m and numberp(n/d) and n/d < 0
%%};
%%% NOTE: The rational-shift rule does not work with "on intstr, div".
%%
%%let psi_rules;

%%symbolic;

%
% Rules for initial manipulation of polygamma functions.
%

symbolic (operator polygamma!*calc, trigamma!*halves, polygamma!:error,
        polygamma_aux, psi!:error);

symbolic procedure psi!:error(x);
    rerror('specfn,0,{"Psi undefined for nonpositive integer argument",x});

symbolic procedure polygamma!:error(n,x);
   if not fixp n then rerror('specfn,0,
                             {"Index of Polygamma must be an integer >= 0, not",n})
    else rerror('specfn,0,
                {"Polygamma undefined for nonpositive integer argument",x});

algebraic procedure polygamma_aux(n,m);
        for ii:=1:(n-1) sum (1/ii**(m+1));

%%algebraic (polygamma!*rules := {
%%
%%   polygamma(~n,~x)  =>  polygamma!:error(n,x)
%%        when numberp n and (not fixp n or n < -1),
%%
%%   polygamma(~n,~x)  =>  psi(x)
%%      when numberp n and n = 0,
%%
%%   polygamma(~n,~x)  =>  infinity
%%      when numberp x and impart x = 0 and x = floor x and x < 1,
%%
%%   polygamma(~n,~x)  =>  do!*trigamma!*halves(x)
%%      when numberp n and n = 1 and numberp x and impart x = 0
%%               and (not (x = floor x) and ((2*x) = floor (2*x))) and x > 1,
%%
%%   polygamma(~n,~x)  =>  ((-1) ** (n)) * (factorial n) * (- zeta(n+1) +
%%                         polygamma_aux(x,n))
%%      when fixp x and x >= 1 and not symbolic !*rounded,
%%
%%   polygamma(~n,~x)  => ((-1)**n) * factorial n * (-2 * (2**n) *
%%               zeta(n+1) + 2 * (2**n) + zeta(n+1))
%%      when numberp x and x = (3/2) and not symbolic !*rounded,
%%
%%   polygamma(~n,~x)  =>  do!*polygamma(n,x)
%%      when numberp x and symbolic !*rounded
%%               and numberp n and impart n = 0 and n = floor n,
%%
%%   df(polygamma(~n,~x), ~x)  =>  polygamma(n+1, x),
%%
%%   int(polygamma(~n,~x),~x)  =>  polygamma(n-1,x)
%%
%%})$
%%
%%algebraic (let polygamma!*rules);



%
% Set up rules for the initial manipulation of zeta.
%
% Comments:
%
%     Zeta of positive even numbers and negative odd numbers
%     is evaluated (in terms of pi) always when its argument
%     has magnitude less than 31, and only in rounded mode
%     otherwise.  (This is because the coefficients get a bit
%     big when the argument is over about 30.)
%

%%algebraic operator zeta;
%%symbolic (operator zeta!*calc, zeta!*pos!*intcalc);
%%
%%
%%algebraic (zeta!*rules := {
%%
%%   zeta(~x)  =>  (- (1/2))
%%      when numberp x and x = 0,
%%
%%   zeta(~x)  =>  (pi ** 2) / 6
%%      when numberp x and x = 2,
%%
%%   zeta(~x)  =>  (pi ** 4) / 90
%%      when numberp x and x = 4,
%%
%%   zeta(~x)  =>  infinity
%%      when numberp x and x = 1,
%%
%%   zeta(~x)  =>  0
%%      when numberp x and impart x = 0 and x < 0 and (x/2) = floor(x/2),
%%
%%   zeta(~x)  =>  ((2*pi)**x) / (2*factorial x)*(abs bernoulli!*calc x)
%%      when numberp x and impart x = 0 and x > 0
%%               and (x/2) = floor (x/2) and x < 31,
%%
%%   zeta(~x)  =>  - (bernoulli!*calc (1-x)) / (1-x)
%%      when numberp x and impart x = 0 and x < 0
%%               and x = floor x and x > -31,
%%
%%   zeta(~x)  =>  ((2*pi)**x)/(2 * factorial x)*(abs bernoulli!*calc x)
%%      when numberp x and impart x = 0 and x > 0
%%               and (x/2) = floor(x/2) and x < 201 and symbolic !*rounded,
%%
%%   zeta(~x)  =>  - (bernoulli!*calc (1-x)) / (1-x)
%%      when numberp x and impart x = 0 and x < 0
%%               and x = floor x and x > -201 and symbolic !*rounded,
%%
%%   zeta(~x)  =>  (2**x)*(pi**(x-1))*sin(pi*x/2)*gamma(1-x)*zeta(1-x)
%%      when numberp x and impart x = 0 and x < 0
%%               and (x neq floor x or x < -200) and symbolic !*rounded,
%%
%%   zeta(~x)  =>  do!*zeta!*pos!*intcalc(fix x)
%%      when symbolic !*rounded and numberp x and impart(x) = 0 and x > 1
%%               and x = floor x and (x <= 15 or precision 0 > 100
%%                  or 2*x < precision 0),
%%
%%   zeta(~x)  =>  do!*zeta(x)
%%      when numberp x and impart x = 0% and x > 1
%%               and symbolic !*rounded,
%%
%%   df(zeta(~x),x)  =>  -(1/2)*log(2*pi)
%%      when numberp x and x = 0
%%
%%})$
%%
%%algebraic (let zeta!*rules);



%%algebraic procedure do!*psi(z);
%%   algebraic sf!*eval('psi!*calc,{z});

algebraic procedure do!*polygamma(n,z);
   algebraic sf!*eval('polygamma!*calc,{n,z});

algebraic procedure do!*trigamma!*halves(z);
   algebraic sf!*eval('trigamma!*halves,{z});

algebraic procedure do!*zeta(z);
   (if z <= 1.5 and precision(0) <= floor(4+3*z)
    then raw!*zeta(z)
    else if (3*z) > (10*precision(0)) then 1.0
    else if z > 100 then algebraic sf!*eval('zeta!*calc,{z})
    else algebraic sf!*eval('zeta!*general!*calc,{z}));

algebraic procedure do!*zeta!*pos!*intcalc(z);
   algebraic sf!*eval('zeta!*pos!*intcalc,{z});



%
% algebraic procedure psi!*calc(z);
%
%     Compute a value of psi. Works by first computing the
%     smallest positive integral x at which psi(x) is easily
%     computable to the current precision using no more
%     than the first 200 bernoulli numbers, then scaling up
%     the given argument (if necessary) so that it can be
%     computed, scaling down again afterwards.
%
%     Does not work for complex arguments.
%

%%remflag('(psi!*ld!*0 psi!*ld!*1),'reserved);
%%
%%psi!*ld!*0 := -1;   % precision at which last psi was calc'd
%%psi!*ld!*1 :=  0;   % lowest post-scale value acceptable at
%%                                % that precision
%%
%%
%%algebraic procedure psi!*calc(z);
%%   begin scalar result, admissable, bern300, alglist!*, precom;
%%      integer prepre, scale, lowest;
%%      precom := complex!*off!*switch();
%%      prepre := precision 0;
%%      if prepre < !!nfpd then precision (!!nfpd + 1);
%%      % The following is  8*rd!-tolerance!*
%%      admissable := (1 / (10 ** prepre)) / 2;
%%      if prepre = psi!*ld!*0 then lowest := psi!*ld!*1
%%      else
%%               << bern300 := abs bernoulli!*calc 300;
%%                  lowest := 1 +
%%                     symbolic conv!:bf2i exp!:
%%                               (divbf(log!:(divbf(sq2bf!* bern300,
%%                                          timbf(i2bf!: 150,
%%                                             sq2bf!* admissable)), 4),
%%                     i2bf!: 300), 3);  % Use symbolic mode so as to
%%                                    % force less accuracy for more speed
%%                  psi!*ld!*0 := prepre;
%%                  psi!*ld!*1 := lowest >> ;
%%      if lowest>repart z then scale := ceiling(lowest - repart z) + 20;
%%      z := z + scale;
%%      result := algebraic symbolic psi!*calc!*sub(z, scale, admissable);
%%
%%      precision prepre;
%%      complex!*restore!*switch(precom);
%%      return result;
%%   end;
%%

%%symbolic procedure psi!*calc!*sub(z, scale, admissable);
%%   begin scalar result, zsq, zsqp, this, bk;
%%      integer k, orda, rp; k := 2;
%%      z := sq2bf!* z;
%%      admissable := sq2bf!* admissable;
%%      zsq := timbf(z,z); zsqp := zsq;
%%      this := plubf(admissable, bfone!*);
%%      result := difbf (log!* z, divbf(bfone!*, timbf(bftwo!*, z)));
%%      orda := order!: admissable - 5; rp := !:bprec!:;
%%      while greaterp!: (abs!: this, admissable) do
%%               << bk := sq2bf!* symbolic algebraic bernoulli!*calc k;
%%                  this := divide!:(bk, timbf(i2bf!: k, zsqp), rp);
%%                  result := difbf(result, this);
%%                  k := k + 2; rp := order!: this - orda;
%%                  zsqp := timbf(zsqp, zsq) >>;
%%      for n := 1:scale do
%%               result := difbf(result, divbf(bfone!*, difbf(z, i2bf!: n)));
%%      return mk!*sq !*f2q mkround result;
%%   end;
%%
%%flag('(psi!*ld!*0 psi!*ld!*1),'reserved);

%
% numeric computation of digamma function: force bigfloat arithmetic 
%
symbolic procedure rdpsi!* u;
   %
   % handle special cases psi(1) => -euler_gamma
   %     and psi(1/2) => -euler_gamma - 2*log(2)
   %  rd_euler!* will call rdpsi!:(1) if necessary and save the computed value for later use
   if rd!:onep u then rd!:minus rd_euler!*()
    else if rd!:onep rd!:times(bftwo!*,u)
     then rd!:minus rd!:plus(rd_euler!*(),rd!:times(bftwo!*,rdlog!* rdtwo!*()))
    else (rdpsi!:(convprec u,!:bprec!:) where !*!*roundbf := t);

Comment

The following procedure computes from its argument eps a bound k such that

   abs(bernoulli(300)/(300*k^300)) < eps
	 
i.e.
	 
   k = e^(1/300 * log(abs(bernoulli(300))/(300*eps)))

We precompute 

   bern300!: := abs(bernoulli(300)/300
   i300!: := 1/300 

as bigfloats with standard smallfloat precision (12).

The results are 

   bern300!: := '(!:rd!: 213317478489793 . 1191)
   i300!: := '(!:rd!: 480383960252853 . -57)

   ;

global '(bern300!: i300!:);

bern300!: := round!:mt (read!:lnum '(372 71738 33244 27),48);
i300!:    := read!:lnum '(-3 33333 33333 33333);

symbolic procedure rdpsi!:compute!-lowerbound eps;
   exp!:(timbf(log!:(divide!:(bern300!:,eps,32),32),i300!:),32);
   

symbolic procedure rdpsi!:(z,k);
   if bfzerop!: z or rd!:minusp z and integerp!: z then bflerrmsg 'rdpsi!:
    else begin scalar result, admissable, lb, refl, pival;
      integer shift, k7;
      k7 := k+7;
      % For negative z, use the reflection formula
      % psi(z) = psi(1-z) - pi/tan(pi*z)
      % unless z is a negative integer
      if rd!:minusp z
	then  << pival := !:pi k7;
	         refl := divide!:(pival,tan!:(times!:(pival,z),k7),k7);
	         z := difference!:(bfone!*,z); >>;
      % The following is  rd!-tolerance!*
      admissable := make!:ibf(1, 6-k);
      lb :=  rdpsi!:compute!-lowerbound admissable;
      if greaterp!:(lb,z) then <<
	 % make 20 extra shift steps to be on the safe side
         shift := 20 + conv!:bf2i difference!:(lb,z);
 	 z := plus!:(z,i2bf!: shift) >>;
      result := plus!:(difference!: (log!:(z,k7), divide!:(bfone!*, times!:(bftwo!*, z), k7)),
	       	       rdpsi!:1(divide!:(bfone!*,times!:(z,z),k7),k,admissable));
      for n := 1:shift do
	 result := difference!:(result, divide!:(bfone!*, difference!:(z, i2bf!: n), k7));
      if refl then result := difference!:(result,refl);
      return round!:mt(result,k);
   end;

% 
% Use asymptotic expansion http://dlmf.nist.gov/5.11.E2
%

symbolic procedure rdpsi!:1(zsq,kp,admissable);
   begin scalar result, zsqp, this, bk;
      integer k, k7; k := 2; k7:=kp+7;
      zsqp := zsq;
      result := bfz!*;
      repeat <<
	 % bernoulli!*calc may change the precision which resets !*!*roundbf, so bind it to itself
	 % use bfloat since sq2bf!* may return a system float
	 bk := bfloat sq2bf!* bernoulli!*calc k where !*!*roundbf:=!*!*roundbf;
	 this := divide!:(times!:(bk,zsqp),i2bf!: k, k7);
	 result := difference!:(result, this);
	 k := k + 2;
	 zsqp := cut!:mt(times!:(zsqp, zsq),k7)
      >> until lessp!:(abs!: this,admissable);
      return result;
   end;

symbolic procedure crpsi!* u;
   % shortcut for real argument
   if rd!:zerop tagim u then !*rd2cr rdpsi!* u
   % For negative repart(z), use the reflection formula
   % psi(z) = psi(1-z) - pi/tan(pi*z)
   % unless z is a negative integer
    else if rd!:minusp tagrl u
     then cr!:differ(
	   (gfpsi!:(crprcd cr!:differ(!*rd2cr bfone!*,u),!:bprec!:) where !*!*roundbf := t),
	   (cr!:quotient(crpi,crtan!*(cr!:times(crpi,u))) where crpi:=!*rd2cr pi!*()))
    else  (gfpsi!:(crprcd u,!:bprec!:) where !*!*roundbf := t);

symbolic procedure gfpsi!:(z,k);
   if rd!:minusp tagrl z then rerror('specfn,0,{"Internal error in psi computation: gfpsi!: argument is negative: ",z})
    else begin scalar result, admissable, gfnorm, gflog, lb;
      integer shift, k7;
      k7 := k+7;
      % The following is  rd!-tolerance!*
      admissable := make!:ibf(1, 6-k);
      lb :=  rdpsi!:compute!-lowerbound admissable;
      % this is the lower bound l for the norm of z = x +i*y where (x > 0)
      % ie. we need to compute the shift for n for x via (x+n)^2 + y^2 > l^2
      % obviously, scaling is necessary only if |x| < l and |y| < l,
      % otherwise shift s > sqrt(l^2-y^2) - x , but only if sqrt(l^2-y^2) - x > 0
      if lessp!:(gfrl z, lb) and lessp!:(abs!: gfim z, lb) then <<
	 shift := conv!:bf2i difference!:(bfsqrt difference!:(times!:(lb,lb),times!:(gfim z,gfim z)),gfrl z);
         if shift > 0 then <<
            % make 20 extra shift steps to be on the safe side
	    shift := shift + 20;
 	    z := gfplus(z,mkgf(i2bf!: shift,bfz!*)) >> >>;
      gfnorm := rdhypot!*(gfrl z,gfim z);
      gflog := mkgf(log!:(gfnorm,k7),rdatan2!*(gfim z,gfrl z));
      result := gfplus(gfdiffer (gflog, gfquotient(rl2gfc bfone!*, gftimes(rl2gfc bftwo!*, z))),
	       	       gfpsi!:1(gfquotient(rl2gfc bfone!*,gftimes(z,z)),k,admissable));
      for n := 1:shift do
	 result := gfdiffer(result, gfquotient(rl2gfc bfone!*, gfdiffer(z, mkgf(i2bf!: n,bfz!*))));
      return gf2cr!: result;
   end;

% 
% Use asymptotic expansion http://dlmf.nist.gov/5.11.E2
%

symbolic procedure gfpsi!:1(zsq,kp,admissable);
   begin scalar result, zsqp, this, bk;
      integer k, k7; k := 2; k7:=kp+7;
      zsqp := zsq;
      result := rl2gfc bfz!*;
      repeat <<
	 bk := rl2gfc bfloat sq2bf!* bernoulli!*calc k where !*!*roundbf:=!*!*roundbf;
	 this := gfquotient(gftimes(bk,zsqp), rl2gfc i2bf!: k);
	 result := gfdiffer(result, this);
	 k := k + 2;
	 zsqp := gftimes(zsqp, zsq)
      >> until lessp!:(rdhypot!*(gfrl this,gfim this),admissable);
      return result;
   end;


put('psi,'!:rd!:,'rdpsi!*);
put('psi,'!:cr!:,'crpsi!*);

%
% algebraic procedure polygamma!*aux(n,z);
%
%     Used by the procedure below, to implement the Reflection
%     Formula. This obtains an expression for
%                 n
%                d
%                --- ( cot  ( pi * x ) )
%                  n
%                dx
%     and substitutes z for x into it, returning the result.
%

%%algebraic procedure polygamma!*aux(n,z);
%%   begin scalar poly;
%%      clear dummy!*arg;
%%      poly := cot(pi * dummy!*arg);
%%      for k := 1:n do poly := df(poly, dummy!*arg);
%%      dummy!*arg := z;
%%      return poly;
%%   end;

%
% The nth derivative of cot(pi*z) at point z=z0 is 
%
%   pi**n * df(cot(x),x) at x=pi*z0
%
% 


remflag('(dummy!*arg),'reserved);

symbolic procedure polygamma!*aux(n,z0);
   begin scalar poly,x,y,pival;
      z0 := sq2bf!* z0;
      poly := simp '(cot dummy!*arg);
      if not kernp poly then rerror('specfn,0, {"Internal error in polygamma:",n,z0,prepsq y});
      y := mvar numr poly;
      for k := 1:n do poly := diffsq(poly, 'dummy!*arg);
      %
      % compute x=pi*z0
      %
      pival := rdpi!*();
      x := rdcot!*(rd!:times(pival,z0));
      %
      % now replace cot(dummy!*arg) by x=cot(pi*z0) and multiply by pi**n
      %
      x := subsq(poly,{y . x});
      if denr x=1 and domainp numr x
        then return rd!:times(numr x,texpt!:(pival,n))
       else rerror('specfn,0, {"Internal error in polygamma:",n,z0,prepsq x});
   end;

flag('(dummy!*arg),'reserved);

%
% algebraic procedure polygamma!*calc(n,z);
%
%     Computes a value of the polygamma function, order n,
%     at z.  N must be an integer, and z must be real.  If
%     z is negative, the Reflection Formula is applied by
%     a call to polygamma!*aux (above); then the positive
%     argument is fed to polygamma!*calc!*s which does the
%     real work.
%

algebraic procedure polygamma!*calc(n,z);
  if fixp z and z<=0 then polygamma!:error(n,z)
   else begin scalar result, z0, prepre, precom;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if prepre < !!nfpd then precision (!!nfpd + 3)
      else precision (prepre + 3 + floor(prepre/50));
      if z > 0 then
               << z0 := z;
                  result := algebraic symbolic polygamma!*calc!*s(n,z0) >>
      else
               << z0 := 1-z;
                  result := pi*algebraic symbolic polygamma!*aux(n,z0) +
                            algebraic symbolic polygamma!*calc!*s(n,z0);
 	          if not evenp n then result := -result >>;
      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;




%
% symbolic procedure polygamma!*calc!*s(n,z);
%
%     Implementation of an asymptotic series for the poly-
%     gamma functions.  Computes a scale factor which should
%     (hopefully) provide a minimum argument for which this
%     series is valid at the given order and precision; then
%     computes the series for that argument and scales down
%     again using the Recurrence Formula.
%

symbolic procedure polygamma!*calc!*s(n,z);
   begin scalar result, this, admissable, partial,
         zexp, zexp1, zsq, nfac, nfac1, kfac, rescale, signer, z0;
      integer k, nm1, nm2, rp, orda, min, scale;

      z := sq2bf!* z; signer := i2bf!:((-1)**(n-1));
      admissable := divide!:(bfone!*,make!:ibf(1,!:bprec!:),8);

      min := 10 + conv!:bf2i
              exp!:(times!:(divide!:(bfone!*,i2bf!:(300+n),8),
              log!:(divide!:(timbf(round!:mt(i2bf!: factorial(300+n),8),
                  abs!: sq2bf!* symbolic algebraic bernoulli 300),
                times!:(admissable,round!:mt(i2bf!: factorial 300,8)),
                  8),8)),8);     % In which Chris approximates to 8 bits
                                 % and hopes to get away with it...
      scale := min - (1 + conv!:bf2i z);
      if scale < 0 then scale := 0;
      z0 := plubf(z,i2bf!: scale);

      nfac := round!:mt(i2bf!: factorial(n-1),!:bprec!:);
      zexp := texpt!:any(z0,n);
      result := plubf(divbf(nfac,zexp),
         divbf((nfac1 := timbf(i2bf!: n,nfac)),
            timbf(bftwo!*,(zexp1 := timbf(zexp,z0)))));
      nfac := nfac1; zexp := zexp1;

      nm1 := n-1; nm2 := n-2; rp := !:bprec!:;
      nfac := timbf(nfac, i2bf!: (n+1));
      kfac := bftwo!*; zexp := timbf(zexp,z0);
      zsq := timbf(z0,z0);

      partial := divbf(nfac,timbf(kfac,zexp));
      k := 2; orda := order!: admissable - 5;
      this := bfone!*;

      if null compute!-bernoulli then
         <<errorset!*('(load_package '(specfaux)), nil); nil>>;

      while greaterp!:(abs!: this, admissable) do
         << result := plubf(result,
               (this := timbf(sq2bf!* retrieve!*bern k,partial)));
            k := k + 2;
            partial := divide!:(timbf(partial,i2bf!:((nm2+k)*(nm1+k))),
               timbf(zsq,i2bf!:((k-1)*k)),rp);
            rp := order!: this - orda >>;

      result := times!:(signer,result);

      if scale neq 0 then
         << rescale := bfz!*;
            nfac := round!:mt(i2bf!: factorial n,!:bprec!:);
            for k := 1:scale do
               <<rescale := plus!:(rescale,timbf(nfac,texpt!:(z,-n-1)));
                  z := plubf(z,bfone!*) >>;
            result := plubf(result,times!:(signer,rescale)) >>;

      return mk!*sq !*f2q mkround result;
   end;


%
% algebraic procedure trigamma!*halves(x);
%
%     Applies a formula to derive the exact value of the trigamma
%     function at x where x = n+(1/2) for n = 1, 2, ...
%

algebraic procedure trigamma!*halves(x);
   begin integer prepre; scalar result, alglist!*;
      result := (1/2) * (pi ** 2) - (4 * (for k := 1:(round (x-(1/2)))
               sum ((2*k - 1) ** (-2))));
      return result;
   end;




%
% algebraic procedure zeta!*calc(s);
%
%     Calculate zeta(s). Only valid for repart(s) > 1.
%
%     This function uses the system !*primelist!* of the first
%     500 primes.  If the system variable disappears or changes,
%     this function is helpless.
%

algebraic procedure zeta!*calc(z);
   begin scalar result, admissable, primelist,
               partialpl, this, modify, spl, alglist!*;
      integer prepre, j, rflag, thisprime, nexti;
      share spl;
      prepre := precision(0);
      precision prepre + 3;
      admissable := (1 / (10 ** (prepre + 2)));

      symbolic (spl := !*primelist!*);
      primelist := {};
      result := 1; modify := 1;
      for k := 1:10 do
               << j := symbolic car spl;
                  symbolic (spl := cdr spl);
                  primelist := (j . primelist);
                  modify := modify * (1 - (1 / (j**z))) >>;
      modify := 1 / modify;

      this := admissable + 1;
      if not symbolic cdr divide (j, 3) then j := j + 2;
      nexti := (if not symbolic cdr divide (j+1, 3) then 2 else 4);
      while ((abs this) > admissable) do
               << rflag := 1; partialpl := primelist;
                  while ((partialpl neq {}) and rflag) do
                     << thisprime := first partialpl;
                               rflag := symbolic cdr divide(j, thisprime);
                               partialpl := rest partialpl >>;
                  if rflag then result := result + (this := (1 / (j**z)));
                  j := j + nexti; nexti := 6 - nexti >>;
      result := result * modify;
      precision prepre;
      return result;
   end;


algebraic procedure zeta!*pos!*intcalc(m);
   (((-1)**m)*polygamma(m-1,3)/factorial(m-1)
      + 1 + (1/(2**m)));


algebraic procedure zeta!*error(z,terms);
   (((-1) ** (terms+2)) / ((terms+1) ** z));


algebraic procedure zeta!*general!*calc(z);
   begin scalar result, zp, admissable, z0;
               integer pre, k;
      pre := precision(0);
      admissable := algebraic symbolic
               (mk!*sq !*f2q mkround divide!:(bfone!*,i2bf!:(10 ** pre),8));
      if (z**2) < admissable
      then result := ((-1/2) - ((log(2*pi))*z)/2)
      else if pre < !!nfpd
                 then begin scalar sstt, stt;
                                sstt := (for k := 2:(pre-1) sum (k**(-z)));
                                precision (!!nfpd + 2);
                         z0 := z; zp := pre**(-z); stt := sstt + 1;
                                result := algebraic symbolic
                     zeta!*general!*calc!*sub(z0,zp,admissable,pre,stt);
                      end
           else <<z0 := z; zp := pre**(-z);
                  result := algebraic symbolic
                   zeta!*general!*calc!*sub(z0,zp,admissable,pre,'())>>;
      precision pre;
      return result;
   end;


symbolic procedure zeta!*general!*calc!*sub(z,zp,admissable,pre,stt);
   begin scalar result, prere, this, fac, pre, zk1, zk2;
               integer k;

      z := sq2bf!* z;
      zp := sq2bf!* zp;
      admissable := sq2bf!* admissable;

      if stt = nil then
               << result := bfone!*; k := 1;
                  this := plus!:(admissable,bfone!*);
                  while greaterp!: (abs!: this,admissable) and k < pre-1 do
                     << k := k + 1;
                               this := texpt!:any(i2bf!: k, minus!: z);
                               result := plubf(result, this) >> >>
      else result := sq2bf!* stt;

      pre := i2bf!: pre;
      zk1 := plubf(z,bftwo!*); zk2 := plubf(z,bfone!*);
      result := plubf(result,
               timbf(zp,plubf(bfhalf!*,divbf(pre,difbf(z,bfone!*)))));
      fac := divbf(bfone!*,timbf(pre,pre));
      this := timbf(divbf(z,bftwo!*),divbf(zp,pre));
      result := plubf(result,divbf(this,i2bf!: 6));
      k := 4; prere := plubf(result,bfone!*);

      while greaterp!: (abs!: difbf(prere,result), admissable) do
               << this := divbf(timbf(this,timbf(fac,timbf(zk1,zk2))),
                                            i2bf!:(k*(k-1)));
                  prere := result;
                  result := plubf(result,timbf(
                     sq2bf!* symbolic algebraic bernoulli!*calc k, this));
                  zk1 := plus!:(zk1,bftwo!*);
                  zk2 := plus!:(zk2,bftwo!*);
                  k := k + 2; >>;

      return mk!*sq !*f2q mkround result;
   end;

COMMENT The following procedure computes the value of the zeta function according
        to formula 25.2.4 of https://dlmf.nist.gov/ , which is the expansion of the
        zeta function about z=1.
        See also
             http://mathworld.wolfram.com/StieltjesConstants.html .
        It is used only for small values of precision. 

        The constants Stieltjes!:(n) are defined via the classical Stieltjes constants
        as

              Stieltjes!:(n) := (-1)^n*gamma_n / n! 

;

algebraic;

array Stieltjes!: (5);  % for use in raw zeta computations

Stieltjes!: (0) := +0.577215664901532860606512$ % Euler's constant
Stieltjes!: (1) := +0.072815845483676724860586$
Stieltjes!: (2) := -0.00484518159643616136422750173551$
Stieltjes!: (3) := -0.000342305736717224331350228894166$
Stieltjes!: (4) := +0.0000968904193944708054646771285453$
Stieltjes!: (5) := -0.00000661103181084218943121035468498$

algebraic procedure raw!*zeta(z);
   << z := z-1;
     1/z + for m := 0:5 sum (Stieltjes!:(m) * z**m)
   >>;

symbolic;

endmodule;

end;

