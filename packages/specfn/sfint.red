module sfint;     % Assorted Integral Functions, Ei, Si, Ci, Li etc.
                  % Includes rules and limited rounded mode evaluation
                  % for Ei, Si, si (called s_i here!), Ci, Chi, Shi,
                  % Fresnel_S, Fresnel_C and Erf;
                  % the numerical part to be improved!
%
% Author: Winfried Neun, Jun 1993
% email : neun@ZIB.de

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
put('Ei, 'plain!-functionsymbol, '!Ei);
% $Id$
put('Ci, 'plain!-functionsymbol, '!Ci);
put('Si, 'plain!-functionsymbol, '!Si);
put('Chi, 'plain!-functionsymbol, '!Chi);
put('Shi, 'plain!-functionsymbol, '!Shi);

put('Ei, 'prifn, 'plain!-symbol);
put('Si, 'prifn, 'plain!-symbol);
put('Ci, 'prifn, 'plain!-symbol);
put('Shi, 'prifn, 'plain!-symbol);
put('Chi, 'prifn, 'plain!-symbol);

% added Li , Winfried Neun, Oct 1998

% The next 2 declarations enable better checking of number of arguments
% by simpiden

flag('(Ei Ci Si s_i Chi Shi Li erf erfc Fresnel_C Fresnel_S), 'specfn);

deflist('((Ei 1) (Si 1) (s_i 1) (Ci 1) (Chi 1) (Shi 1) (Li 1)
          (erf 1) (erfc 1) (Fresnel_S 1) (Fresnel_C 1)
         ), 'number!-of!-args);

% For Math References, see e.g. Abramowitz/Stegun, chapter 5 and 7

% Exponential Integral etc.

%algebraic operator Fresnel_C, Fresnel_S;%, erfc,erfi;

%algebraic operator li;%, s_i, shi, chi

algebraic let limit(si(~tt),~tt,infinity) => pi/2;

algebraic
let { int(sin(~~a*~tt)/~tt,~tt,0,~z) => si (a*z) when a freeof tt
%      int(cos(~a*~x)*sin(~b*~x)/x,x) => 1/2*si(a*x+b*x)-1/2*si(a*x-b*x),
%      int(cos(~a*~x)*sin(~x)/x,x) => 1/2*si(a*x+x)-1/2*si(a*x-x),
%      int(cos(~x)*sin(~b*~x)/x,x) => 1/2*si(x+b*x)-1/2*si(x-b*x),
%     int(cos(~x)*sin(~x)/x,x) => 1/2*si(2*x)
%      Si(0) => 0,
%      Si(-~x) => (- Si(x)),
%      df(Si(~x),~x) => sin(x)/x  ,
%      Si(~x) => compute!:int!:functions(x,Si)
%                 when numberp x and lisp !*rounded
    };

algebraic
let { int(sin(~tt)/~tt,~tt,~z,infinity) => - s_i (z),
      limit(s_i(~tt),x,infinity) => 0
%      s_i(~x) => si(x) - pi/2,
%      df(s_i(~x),~x) => sin(x)/x
    };

algebraic
let { int(exp(~tt)/~tt,~tt,-infinity,~z) =>  Ei (z)
%      df(Ei(~x),~x) => exp(x)/x,
%      Ei(~x) => compute!:int!:functions(x,Ei)
%         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int(1/ln(~tt),~tt,0,~z) =>  li (z)
%      li (~z) => Ei(log z)
    };

algebraic
let { int(cos(~tt)/~tt,~tt,~z,infinity) => - ci (z),
      int((cos(~tt) -1)/~tt,~tt,0,~z) => ci (z) + psi(1) -log(z)
% psi(1) may be replaced by euler_gamma one day ...

%      Ci(-~x) => - Ci(x) -i*pi,
%      df(Ci(~x),~x) => cos(x)/x,
%      Ci(~x) => compute!:int!:functions(x,Ci)
%         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int(sinh(~tt)/~tt,~tt,0,~z) => shi (z)
%      df(shi(~x),~x) => sinh(x)/x  ,
%      shi(~x) => compute!:int!:functions(x,shi)
%         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int((cosh(~tt) -1)/~tt,~tt,0,~z) => chi (z) + psi(1) -log(z)
% psi(1) may be replaced by euler_gamma one day ...
%      df(chi(~x),~x) => cosh(x)/x  ,
%      chi(~x) => compute!:int!:functions(x,chi)
%         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int(sin(pi/2*~tt^2),~tt,0,~z) => Fresnel_S (z),
%      Fresnel_S(-~x) => (- Fresnel_S (x)),
%      Fresnel_S(i* ~x) => (-i*Fresnel_S (x)),
      limit(Fresnel_S(~tt),~tt,infinity) => 1/2
%      df(Fresnel_S(~x),~x) => sin(pi/2*x^2) ,
%      Fresnel_S (~x) => compute!:int!:functions(x,Fresnel_S)
%              when numberp x and abs(x) <= 10 and lisp !*rounded
};

algebraic
let { int(cos(pi/2*~tt^2),~tt,0,~z) => Fresnel_C (z),
%      Fresnel_C(-~x) => (- Fresnel_C (x)),
%      Fresnel_C(i* ~x) => (i*Fresnel_C (x)),
      limit(Fresnel_C(~tt),~tt,infinity) => 1/2
%      df(Fresnel_C(~x),~x) => cos(pi/2*x^2) ,
%      Fresnel_C (~x) => compute!:int!:functions(x,Fresnel_C)
%               when numberp x and abs(x) <= 10 and lisp !*rounded
};

algebraic
let { limit (erf(~x),~x,infinity) => 1,
      limit (erfc(~x),~x,infinity) => 0,
%% Moved to alg/elem.red
%%      erfc (~x) => 1-erf(x),
%%      erfi(~z)  => -i * erf(i*z),
      int(1/e^(~tt^2),~tt,0,~z) => erf(z)/2*sqrt(pi) when z freeof infinity,
      int(1/e^(~tt^2),~tt,~z,infinity) => erfc(z)/2*sqrt(pi) when z freeof infinity
% RmS 2013-04-09: rule moved to alg/elem.red, compute!:int!:functions autoloaded
%      erf (~x) => compute!:int!:functions(x,erf)
%                when numberp x and abs(x)<5 and lisp !*rounded
    };

algebraic procedure compute!:int!:functions(x,f);
   begin scalar pre,!*uncached,scale,term,n,precis,result,interm;
   pre := precision 0; precision pre;
   precis := 10^(-2 * pre);
   lisp (!*uncached := t);
   if f = Si then
           if x < 0 then result :=
                        - compute!:int!:functions(-x,f) else
            << n:=1; term := x; result := x;
               while abs(term) > precis do
                 << term := -1 * (term * x*x)/(2n * (2n+1));
                    result := result + term/(2n+1);
                    n := n + 1>>; >>
   else if f = Ci then
           if x=0 then rerror('specfn,0,"Ci(0) is undefined")
            else if realvaluedp x and x < 0
             then result := compute!:int!:functions(-x,f) + i*pi
	    else
              << n:=1; term := 1; result := Euler_gamma + log(x);
               while abs(term) > precis do
                 << term := -1 * (term * x*x)/((2n-1) * 2n);
                    result := result + term/(2n);
                    n := n + 1>>; >>
    else  if f = Ei then
          << if x=0 then rerror('specfn,0,"Ei(0) is undefined")
              else if not realvaluedp x
               then symbolic rerror('specfn,0,"Ei undefined for complex argument");
             n:=1; term := 1; result := Euler_gamma + log(abs(x));
               while abs(term) > precis do
                 << term := (term * x)/n;
                    result := result + term/n;
                    n := n + 1>>; >>
    else  if f = Shi then
            << n:=1; term := x; result := x;
               while abs(term) > precis do
                 << term := (term * x*x)/(2n * (2n+1));
                    result := result + term/(2n+1);
                    n := n + 1>>; >>
    else  if f = Chi then
          if x=0 then rerror('specfn,0,"Chi(0) is undefined")
           else if realvaluedp x and x<0
            then result := compute!:int!:functions(-x,f) + i*pi
	   else << n:=1; term := 1; result := Euler_gamma + log(x);
               while abs(term) > precis do
                 << term := (term * x*x)/((2n-1) * 2n);
                    result := result + term/(2n);
                    n := n + 1>>; >>
    else if f = erf then
           if x < 0 then result := - compute!:int!:functions(-x,f) else
            << n:=1; term := x; result := x;
               if floor(x*7) > pre then precision  floor(x*7);
               interm := -1 *  x*x;
               while abs(term) > precis do
                 << term := (term * interm)/n;
                    result := result + term/(2n+1);
                    n := n + 1>>;
               precision pre;
               result := result*2/sqrt(pi) ;>>
    else  if f = Fresnel_S then
            << if x > 4.0 then precision max(pre,40);
               if x > 6.0 then precision max(pre,80);
               n:=1; term := x^3*pi/2; result := term/3;
                         interm := x^4*(pi/2)^2;
               while abs(term) > precis do
                 << term := -1 * (term * interm)/(2n * (2n+1));
                    result := result + term/(4n+3);
                    n := n + 1>>; >>
    else  if f = Fresnel_C then
            << if x > 4.0 then precision max(pre,40);
               if x > 6.0 then precision max(pre,80);
               n:=1; term := x; result := x; interm := x^4*(pi/2)^2;
               while abs(term) > precis do
                 << term := -1 * (term * interm)/(2n * (2n-1));
                    result := result + term/(4n+1);
                    n := n + 1>>;  >>;
    precision pre;
    return result
  end;

endmodule;

end;
