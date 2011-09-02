% Some test examples calling GNUPLOT from REDUCE.

plot(x**2);

 % with pole

plot(cos x / x);

 % title (once title, title forever in this session)

plot(y=x**2,x=(1 .. 4),y=(0 .. 4),title="hugo");

 % polar coordinates

plot(x**2,polar);

 % 3 dim

plot(z=x**2+y,x=(1 .. 2),y=(3 .. 4));

 % 3 dim parametric

plot(x=u**2,y=v+1,z=u*v);

 % 2 dim parametric

plot(x=t*sin(5*t),y=t*cos(5*t),t=(0 .. 10));

 % 3 dim with contour

plot(x*y,contour);

 % 3 dim, with range

plot(sin x * cos y,x=(-2 .. 2),y=(-2 .. 2));

plot(sin(x**2+y**2),x=(-1.5 .. 1.5),y=(-1.5 .. 1.5),contour);

plot((sin x + sin y)/(x**2 + y**2),x=(-0.1 .. 0.1), y=(-0.1 .. 0.1));

plot(x=u, y=v*cos (-u), z=v* sin(-u), u=(0 .. 3), v =(-0.1 .. 0.1),
    samples = 50);

 % high degree polynomial

plot((x-1)**10);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 % several curves in one diagram (family)
 
 plot(family(x,x**2,x**3,x**4,x**5,x**6,x**7,
               x**8,x**9,x**10),x=(0 .. 1));

 % Legendre polynomials 0 .. 5

lb := {1,
       X,
       (4*X**2 - 1)/2,
       (X*(12*X**2 - 5))/3,
       (192*X**4 - 116*X**2 + 9)/24,
       (X*(960*X**4 - 772*X**2 + 125))/60}$

plot(family lb,x=(-1 .. 1));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 % Fourier basis

tb := for i:=-3:3 collect 
      if i>0 then sin(i*pi*x) else cos(-i*pi*x)$

plot(family tb,x=(0 .. 1 ));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%  plotting a curve given by a set of points:

% simple approximation of y' = f(x,y) with Euler's method:
 
on rounded;
f := y * x;
 
yy := 1;     % starting point
dx := 0.05;  % step width

points :=
 for xx := 0 step dx until 1 collect 
         {xx,<<aux := yy; 
               yy:=yy + dx * sub(y=yy,x=xx,f); 
               aux>>};
 
plot(points,x=(0 .. 1));

% for comparison the true algebraic solution (to be computed
% by the odesolve packate):

plot(e**(x**2/2),x=(0 .. 1));

end;
