on errcont;
bounds (x,x=(1 .. 2));
bounds (2*x,x=(1 .. 2));
bounds (x**3,x=(1 .. 2));
bounds (x*y,x=(1 .. 2),y=(-1 .. 0));
bounds (x**3+y,x=(1 .. 2),y=(-1 .. 0));
bounds (x**3/y,{x=(1 .. 2),y=(-1 .. -0.5)});
bounds (x**3/y,x=(1 .. 2),y=(-1 .. -0.5));
   % unbounded expression (pole at y=0)
bounds (x**3/y,x=(1 .. 2),y=(-1 .. 0.5));

on rounded;
bounds(e**x,x=(1 .. 2));
bounds((1/2)**x,x=(1 .. 2));
off rounded;

bounds(abs x,x=(1 .. 2));
bounds(abs x,x=(-3 .. 2));
bounds(abs x,x=(-3 .. -2));

bounds(sin x,x=(1 .. 2));
 
on rounded;

bounds(sin x,x=(1 .. 2));
bounds(sin x,x=(1 .. 10));
bounds(sin x,x=(1001 .. 1002));

bounds(log x,x=(1 .. 10));

bounds(tan x,x=(1 .. 1.1));

bounds(cot x,x=(1 .. 1.1));
bounds(asin x,x=(-0.6 .. 0.6));
bounds(acos x,x=(-0.6 .. 0.6));

bounds(sqrt(x),x=(1 .. 1.1));
bounds(x**(7/3),x=(1 .. 1.1));
bounds(x**y,x=(1 .. 1.1),y=(2 .. 4));
 
off rounded;


% MINIMA  (steepest descent)

% Rosenbrock function (minimum extremely hard to find).
fktn := 100*(x1^2-x2)^2 + (1-x1)^2;
num_min(fktn, x1=-1.2, x2=1, accuracy=6);

% infinitely many local minima
num_min(sin(x)+x/5, x=1);

% bivariate polynomial
num_min(x^4 + 3 x^2 * y + 5 y^2 + x + y, x=0.1, y=0.2);


% ROOTS (non polynomial: damped Newton)

 num_solve (cos x -x, x=0,accuracy=6);

   % automatically randomized starting point
num_solve (cos x -x,x, accuracy=6);  
 
   % syntactical errors: forms do not evaluate to purely 
   % numerical values
num_solve (cos x -x, x=a);
num_solve (cos x -a, x=0);

num_solve (sin x = 0, x=3);

  % blows up: no real solution exists
num_solve(sin x = 2, x=1);

  % solution in complex plane(only fond with complex starting point):
on complex;
num_solve(sin x = 2, x=1+i);
off complex;

  % blows up for derivative 0 in starting point 
num_solve(x^2-1, x=0);

  % succeeds because of perturbed starting point
num_solve(x^2-1, x=0.1);

  % bivariate equation system
num_solve({sin x=cos y, x + y = 1},{x=1,y=2});
on evallhseqp;  % So both sides of equation evaluate.
sub(ws,{sin x=cos y, x + y = 1});
 
 
% INTEGRALS
 
num_int( x**2,x=(1 .. 2),accuracy=3);

   % critical function: almost flat line with one
   % high narrow needle.
needle := 1/(10**-4 + x**2);
num_int(needle,x=(-1 .. 1),accuracy=3);           % 312.16

num_int(exp(-x**2),x=(-10 .. 10),accuracy=3);     % 1.772

num_int(exp(-x**2),x=(-10**2 .. 10**2));         % 1.7461
off roundbf;

   % cases with singularities

num_int(1/sqrt x ,x=(0 .. 1));          % 1.999

num_int(1/sqrt abs x ,x=(-1 .. 1));     % 3.999

   % simple multidimensional integrals
num_int(x+y,x=(0 .. 1),y=(2 .. 3));

num_int(sin(x+y),x=(0 .. 1),y=(0 .. 1));

 
% APPROXIMATION
 
  %approximate sin x by a cubic polynomial 
num_fit(sin x,{1,x,x**2,x**3},x=for i:=0:20 collect 0.1*i);
 
  % approximate x**2 by a harmonic series in the interval [0,1]
num_fit(x**2,1 . for i:=1:5 join {sin(i*x), cos(i*x)},
               x=for i:=0:10 collect i/10);
 
  % approximate a set of points by a polynomial
pts:=for i:=1 step 0.1 until 3 collect i$
vals:=for each p in pts collect (p+2)**3$
num_fit(vals,{1,x,x**2,x**3},x=pts);
first ws - (x+2)**3;


 
% ODE SOLUTION (Runge-Kutta)
 
depend(y,x);

   % approximate y=y(x) with df(y,x)=2y in interval [0 : 5]
num_odesolve(df(y,x)=y,y=2,x=(0 .. 5),iterations=20);
 
   % same with negative direction
num_odesolve(df(y,x)=y,y=2,x=(0 .. -5),iterations=20);

   % giving a nice picture when plotted
num_odesolve(df(y,x)=1- x*y**2 ,y=0,x=(0 .. 4),iterations=20);

end;
