% This file tests some of the patches included in the patches.red file.
% If the latter file has been correctly installed, none of these should
% give an error.

% 26 Jun 04.

% This used to give a catastrophic error.

on rounded; precision 25;

solve({- 1.999994390224005889280191x1*y + 7.979376557069442737297309x1
   - x2*y^2 + 7.974996524843785878673843x2*y - 15.90005560267478176018537
   x2 - 1.999994390224005889280191x3*y + 7.974974155871756786131486x3
   - 0.9999943902318732859562161,
   - 0.9999943902318732859562161x1 - 1.999994390224005889280191x2*y
   + 7.974974155871756786131486x2 - x3*y^2 + 7.974996524843785878673843
   x3*y - 15.90005560267478176018537x3 - 1.999994390224005889280191y
   + 7.979376557069442737297309,
   - 0.9999943902318732859562161x2 - 1.999994390224005889280191x3*y
   + 8.005202587362861321828448x3 - y^2 + 8.009627454668455757619651y
   - 15.03852566251722658450117},
      {x1,x2,x3})$

off rounded; precision 12;

% 8 Jul 04;

% This used to return zero.

int(e^(a^(1/3)*x)*sin x,x);

% 5 Aug 04.

% This used to give an "invalid as operator" error;

load rlfi; on latex;

procedure fac n;
  if not(fixp n and n>=0) then rederr "non negative integer required"
   else for i:= 1:n product i;

fac 10;

off latex;

% 2 Sep 04.

% In rare circumstances, floating point conversion could give an
%  extraneous error.

symbolic read!:num 3.14;

%  6 Sep 04.

% With rational on, some non-zero factorizations could produce
% a zero coefficient.

on rational; factorize(r^((1/4*n^2 - 1/4*n + 1)/(n - 1))); off rational;

% 28 Sep 04.

% This did not produce a closed form solution.

load_package algint; int(sqrt(x-1)/(sqrt x*(x-1)),x); off algint;

% 10 Dec 04.

% This used to produce an erroneous output.

depend {f,b,k},x;

on dfprint;

{df(f,x,~n) => df(k*b,x,n)};

nodepend {f,b,k},x;

off dfprint;

% 31 Jan 05.  Some integrals involving square roots could run forever.

% There is no simple example of this error.

% 12 Feb 05.  SOLVE could produce a spurious recursive loop.

solve((4*e^(y^3/3)*cte+2x^2+y^3+3)/e^(y^3/3),y);

% 20 Apr 05. This gave a DIVISION FAILED error.

int(e^(-a^(1/4)*(-1)^(1/4)*x),x);

% 2 May 05. This gave a DIVISION FAILED error.

int(e^(-a^(1/4)*(-1)^(1/4)*i*x)*b+(1/4)*e^(-a^(1/4)
     *(-1)^(1/4)*i*x)*x,x);

% 22 May 05.  This integral never completed.

int(e^((3sqrt 5+1)*x)*(sqrt 5+1)+e^((3sqrt 5-1)*x)*(sqrt 5+1),x);

% 30 May 05.  This used to give a spurious "Zero divisor" error.

solve({log tan(y/2),y+1/x},{x,y});

% 4 Oct 05.  DEG did not work with rational coefficients.

deg(x^3/a-x/5+1/4,x);

% 5 Oct 05.  Some SOLVE calculations gave a spurious "Zero Divisor" error.

ex0:= sqrt(a^2-y^2);

solve((-log(( - x + a + y)/ex0) + log((x + a + y)/ex0) + x
   - (a^2 - y^2)/ex0),y);

clear ex0;

% 16 Nov 05. System errors could occur with rounded and combineexpt on.

on rounded,combineexpt;

0.183*e^x*t^4.39;

off rounded,combineexpt;

% 22 Nov 05. Some definite integrals with variables other than x could
%            give a wrong answer.

int(e^(-y),y,0,x);

%  9 Dec 05. With combineexpt on, expressions could be dropped.

on combineexpt; 4*e^(-3*h/2) - 3*h*e^(-h) + 2*e^(-h); off combineexpt;

% 20 Feb 06.  The rule for df(Jacobidn(~u,~m),~u) was wrong.

df(Jacobidn(x,y),x);

% 23 May 06. Derivatives and integrals of matrices were not computed.

m := mat((x,x^2),(x^3,x^4));

df(m,x);

int(m,x);

% 18 Aug 06. After nospur, some traces were still evaluated.

load_package hephys;

nospur f;

x := a*g(f,k,k1)+g(f,k,k2);

procedure tst x; begin scalar y; spur f; y:=x; nospur f; return x end;

tst x;

clear x;

% 29 Sep 06. With dfprint on, derivatives of integrals would print in a
%            truncated form.

depend f,x,y$

on dfprint;

df(int(f,y),x,y);

off dfprint; nodepend f,x,y;

% 11 Jan 07. With rounded arithmetic and factor on, a non-numeric
%            argument error could occur.

on factor,rounded;

0.72*(1.44*p1^2 + 0.096*p1 + 0.28*q0 + 0.0016)^0.5*p1 +
0.0032*(1.44*p1^2 + 0.096*p1 + 0.28*q0 + 0.0016)^0.5 +
1.84*p1^2 -0.0236*p1 + 0.09*q0 + 0.00004;

off factor,rounded;

end;
