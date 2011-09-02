% This file tests some of the patches included in the patches.red file.
% If the latter file has been correctly installed, none of these should
% give an error.

%  7 Aug 99.

% This did not terminate.

df(tan((sqrt(1-x^2)*asin acos x + 2*sqrt(1-x^2)*x)/x),x);


% 20 Oct 99.

% This gave a wrong answer.

a1:=12x^2-16x+3;
a2:=3x-4;
off mcd;
on combineexpt;
e^(a1/a2);
on mcd; off combineexpt;
clear a1,a2;

%  8 Nov 99.

% This gave a catastrophic error.

factorize(2*c*s*u^3*v^5-2*c*s*u^3*v +2*c*s*u*v^5-2*c*s*u*v
	  -s^2*u^4*v^4+s^2*u^4+s^2*u^2*v^6-s^2*u^2*v^4-s^2*u^2*v^2
	  +s^2*u^2 +s^2*v^6-s^2*v^2+u^4*v^4-u^4*v^2 -v^4+v^2);


% 18 Dec 99.

% The following integration generated a catastrophic error.

load_package numeric;

on rounded;

f := exp(10*exp(-x)*(x+1-0.1))$

num_int(f,x=(0 .. 300));

off rounded;

clear f;

% 31 Jan 00.

% This gave an error that x was invalid as a kernel.

weight x=1,y=1; wtlevel 10; factor x;

symbolic(wtl!* := asymplis!* := nil);

remfac x;


% 5 Feb 00.

% This gave a spurious error.

matx := mat((1,2)); sign sqrt 42;


%  6 Feb 00.

% This gave a wrong answer.

on complex;

sqrt(i*sqrt(3)-1);

off complex;

% 10 Feb 00.

% This gave the error that "***** x= - 2.61803398875 invalid as scalar."

on rounded,fullroots;

solve(x^3+4*x^2+4*x+1,x);

off rounded,fullroots;


% 18 Feb 00.

% This used to cause a type mismatch error.

m := mat((a,b),(c,d)); det sub(a=1,m);

% 18 Apr 00.

% matchlength!* can now be set to match more products.

for all a let opr(a*v) = a*opr(v);

opr(a1*a2*a3*a4*a5*v);

matchlength!* := 6;

opr(a1*a2*a3*a4*a5*v);

% 22 Apr 00;

% This example created a long list in oldrules!*.

procedure hu (x); wq(x) := x^2; wq(2) := 20;

for i:=1:1000 do hu i; for i:=1:1000 do hu i;

lisp length oldrules!*;


% 28 Jul 00.

% A sum index within a derivative was treated as an identifier.

sum(x^n/factorial n*sub(x=0,df(cos x,x,n)),n,0,5);


% 2 Aug 00.

% With complex on, some factorizations seemed to run forever.

on complex;

factorize (400*y^12+400*y^10*z+40*y^9*z^2+100*y^8*z^2
	   +20*y^7*z^5+120*y^7*z^4+20*y^7*z^3+41*y^6*z^4+60*y^5*z^7
	   +60*y^5*z^5+20*y^4*z^7+6*y^4*z^6+20*y^4*z^5
	   +2*y^3*z^6+9*y^2*z^8+6*y*z^8+z^8);

off complex;


% 29 Aug 00.

% This caused a segmentation violation or similar error.

load_package gentran,scope;

matrix aaa(10,10);

on gentranopt;

gentran aaa(1,1) ::=: aaa(1,1);

off gentranopt;

% 19 Sep 00.

% This used to give a spurious "not found" message.

sqrt_:= {sqrt(~x/~y) => sqrt x/sqrt y};

clearrules sqrt_;

clear sqrt_;

% 20 Sep 00.

% The following caused a catastrophic error.

load_package algint;

int(1/sqrt((2*e^c-y)/(e^c*y)),y);


% 8 Nov 00.

% The following did not optimize completely.

load_package scope;

dX1 := - sqrt(abs(k_l*mttx1 - k_l*mttx2))*sign(k_l*mttx1 - k_l*mttx2)*f*mttu5 +
         sqrt(abs(k_l*mttx1 - k_s*mttx3 - mttu3))*
          sign( - k_l*mttx1 + k_s*mttx3 + mttu3)*f*mttu6 + 
         sqrt(abs(k_l*mttx1 - k_s*mttx4 - mttu4))*
          sign( - k_l*mttx1 + k_s*mttx4 + mttu4)*f*mttu7 - mttu2$
dX2 :=   sqrt(abs(k_l*mttx1 - k_l*mttx2))*sign(k_l*mttx1 - k_l*mttx2)*f*mttu5 
       - sqrt(abs(k_l*mttx2 - k_s*mttx3))*sign(k_l*mttx2 - k_s*mttx3)*f*mttu8 
       - sqrt(abs(k_l*mttx2 - k_s*mttx4))*sign(k_l*mttx2 - k_s*mttx4)*f*mttu9 +
          mttu1$
dX3 := f*( - sqrt(abs(k_l*mttx1 - k_s*mttx3 - mttu3))*
             sign( - k_l*mttx1 + k_s*mttx3 + mttu3)*mttu6 + 
             sqrt(abs(k_l*mttx2 - k_s*mttx3))*
             sign(k_l*mttx2 - k_s*mttx3)*mttu8)$
dX4 := f*( - sqrt(abs(k_l*mttx1 - k_s*mttx4 - mttu4))*
             sign( - k_l*mttx1 + k_s*mttx4 + mttu4)*mttu7 + 
             sqrt(abs(k_l*mttx2 - k_s*mttx4))*
             sign(k_l*mttx2 - k_s*mttx4)*mttu9)$

optimize
  dX1 :=: dX1,
  dX2 :=: dX2,
  dX3 :=: dX3,
  dX4 :=: dX4 
iname s$

remprop('!:rd!:,'intequivfn);

% 20 Nov 00.

% This used to return results in the wrong order.

noncom u,v;

sum(u(n)*v(1-n),n,0,1);

% 13 Dec 00.

% This used to go into an infinite loop.

on numval,rounded; y:=x^4+x3*x^3+x2*x^2+x1*x+x0;

on fullroots;

% This one takes a long time.

% solve(y,x)$

off numval,rounded,fullroots; clear y;


%  9 Jan 01.

solve({y=x+t^2,x=y+u^2},{x,y,u,t});

% 14 Jan 01.

% This caused an error.

resultant(p^3-3p^2-a,3p*(p-2),p);

% 19 Jan 01.

% Some algebraic integrals could produce a catastrophic error.

% Unfortunately, there is no simple example of this problem.

% 22 Jan 01.

% This used to give a spurious zero divisor error.

int((sqrt((-sqrt(a^4*x^2+4)+a^2*x)/(2*x))
       *(-sqrt(a^4*x^2+4)*a^2*x-a^4*x^2-4))/(2*(a^4*x^2+4)),x);

% This used to return an incorrect result.

noncom q;

1/mat((1,0,0),(x/p*q 1,1,0),(x*y/(2p*(p-1))*q 1*q 1,y/(p-2)*q 1,1));

% 2 Feb 01.

% This used to give a spurious zero divisor error.

solve(sqrt x*sqrt((4x^2*x+1)/x)-1=0,x);

% 9 Feb 01.

% The patched version of combine!-logs included an undefined macro.

% No test is included for this.

% 20 Feb 01.

% Even with combineexpt on, some expressions did not simplify adequately.

on combineexpt;

a*a^x;

e*e^(2/(2-x));

e^(x+3)*e^(3/(4-3*x))/e^(5*x-3);

off combineexpt;

%  6 Mar 01.

% This produced a stream of "***** Unexpected algebraic" messages and
% then aborted.

int((x^(2/3)*sqrt(sqrt(y)*sqrt(pi) + 2*pi*y*x)*sqrt( - sqrt(y)*sqrt(pi)
	     + 2pi*y*x))/(4pi*y*x^3 - x),x);

end;
