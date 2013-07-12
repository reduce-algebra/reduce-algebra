load_package redlog;
rlset r;
off rlverbose, rldpepverbose;
on time, echo;

% A.1 Complete Example
a1 := ex(x, ex(y, e**x-y**2=0 and x-y=0));
rldpep a1;

% A.2 Properties of the Exponential Function
a21 := ex(x, e**x<=0);
rldpep a21;

a22 := all(x, e**x>=1+x);
rldpep a22;

a23 := all(x, (1-x)*e**x<=1 or x>=1);
rldpep a23;

% A.3 Exponential Systems
a31 := ex(x,ex(y,ex(z,(x-1)*(x-2)=0 and 2x+y-z=0 and e**(2x)*y-x*z=0)));
rldpep a31;

a32 := ex(x,ex(y,ex(z,2x-y+z+e**(2x)=0 and 3y-z=0 and 2x+y+3z+e**x=0)));
rldpep a32;

a33 := ex(x,e**(2x)-x*e**x-1=0 and e**(2x)+e**x-2x>0);
rldpep a33;

% A.4 Examples with Hyperbolic Functions
% cosh(x):
a41 := all(x,x>7 impl e**(2x)+1>2*e**x*x**3-8*x*e**x);
rldpep(a41,50);

% Additional Example: Verify the Intersection of cosh(x) and x^3-4*x.
add41 := ex(x,e**(2*x)+1=2*e**x*x**3-8*x*e**x and 5<x<6);
rldpep(add41,60);

% sinh(x):
a42 := all(x,x<=2 or e**(2x)-1<2*x**3*e**x);
rldpep(a42,55);

% Additional Example with sinh(x) and p(x) = -1/x+x-x^2-x^3
% \forall x[x < -6 -> p(x) > sinh(x)]
add42 := all(x, x < -6 impl 2*e**x*(-1+x**2-x**3-x**4) > -x*e**(2x)+ x);
rldpep(add42,70);

% tanh(x):
a43 := all(x,x>0 impl x*e**(2x)-x>(x-1)*e**(2x)+x-1);
rldpep a43;

% A.5 Examples with the Gauss Curve
a51 := ex(z,ex(x,4*x**2*e**z=1+x**2 and z+x**2=0));
rldpep a51;

a52 := ex(z,ex(x,10*e**z=-8*x**2+10 and x neq 0 and z+x**2=0));
rldpep a52;

% Additional Examples with the Gauss Curve
% \forall x[exp(-x^2) > 0].
add53 := all(z,all(x,x**2+z=0 impl e**z>0));
rldpep add53;

% \forall x[exp(-x^2)<1/(5x)].
add54 := all(z,all(x,x**2+z=0 impl (x>2 impl 5*x*e**z<1)));
rldpep(add54,30);

end;
