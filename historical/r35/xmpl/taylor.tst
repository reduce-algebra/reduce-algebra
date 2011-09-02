comment
        Test and demonstration file for the Taylor expansion package,
        by Rainer M. Schoepf.  Works with version 1.8b (03-Sep-93);

showtime;

on errcont; % disable interruption on errors

comment Simple Taylor expansion;

xx := taylor (e**x, x, 0, 4);
yy := taylor (e**y, y, 0, 4);

comment Basic operations, i.e. addition, subtraction, multiplication,
        and division are possible: this is not done automatically if
        the switch TAYLORAUTOCOMBINE is OFF.  In this case it is
        necessary to use taylorcombine;

taylorcombine (xx**2);
taylorcombine (ws - xx);

comment The result is again a Taylor kernel;

if taylorseriesp ws then write "OK";

comment It is not possible to combine Taylor kernels that were
        expanded with respect to different variables;

taylorcombine (xx**yy);

comment But we can take the exponential or the logarithm
        of a Taylor kernel;

taylorcombine (e**xx);
taylorcombine log ws;

comment A more complicated example;

hugo := taylor(log(1/(1-x)),x,0,5);
taylorcombine(exp(hugo/(1+hugo)));

comment We may try to expand about another point;

taylor (xx, x, 1, 2);

comment Arc tangent is one of the functions this package knows of;

xxa := taylorcombine atan ws;

comment The trigonometric functions;

taylor (tan x / x, x, 0, 2);

taylorcombine sin ws;

taylor (cot x / x, x, 0, 4);

comment Expansion with respect to more than one kernel is possible;

xy := taylor (e**(x+y), x, 0, 2, y, 0, 2);

taylorcombine (ws**2);

comment We take the inverse and convert back to REDUCE's standard
        representation;

taylorcombine (1/ws);
taylortostandard ws;

comment Some examples of Taylor kernel divsion;

xx1 := taylor (sin (x), x, 0, 4);
taylorcombine (xx/xx1);
taylorcombine (1/xx1);

tt1 := taylor (exp (x), x, 0, 3);
tt2 := taylor (sin (x), x, 0, 3);
tt3 := taylor (1 + tt2, x, 0, 3);
taylorcombine(tt1/tt2);
taylorcombine(tt1/tt3);
taylorcombine(tt2/tt1);
taylorcombine(tt3/tt1);


comment Here's what I call homogeneous expansion;

xx := taylor (e**(x*y), {x,y}, 0, 2);
xx1 := taylor (sin (x+y), {x,y}, 0, 2);
xx2 := taylor (cos (x+y), {x,y}, 0, 2);
temp := taylorcombine (xx/xx2);
taylorcombine (ws*xx2);

comment The following shows a principal difficulty:
        since xx1 is symmetric in x and y but has no constant term
        it is impossible to compute 1/xx1;

taylorcombine (1/xx1);

comment Substitution in Taylor expressions is possible;

sub (x=z, xy);

comment Expression dependency in substitution is detected;

sub (x=y, xy);

comment It is possible to replace a Taylor variable by a constant;

sub (x=4, xy);

sub (x=4, xx1);

comment This package has three switches:
        TAYLORKEEPORIGINAL, TAYLORAUTOEXPAND, and TAYLORAUTOCOMBINE;

on taylorkeeporiginal;

temp := taylor (e**(x+y), x, 0, 5);

taylorcombine (log (temp));

taylororiginal ws;

taylorcombine (temp * e**x);

on taylorautoexpand;

taylorcombine ws;

taylororiginal ws;

taylorcombine (xx1 / x);

on taylorautocombine;

xx / xx2;

ws * xx2;

comment Another example that shows truncation if Taylor kernels
        of different expansion order are combined;

comment First we increase the number of terms to be printed;

taylorprintterms := all;

p := taylor (x**2 + 2, x, 0, 10);
p - x**2;
p - taylor (x**2, x, 0, 5);
taylor (p - x**2, x, 0, 6);
off taylorautocombine;
taylorcombine(p-x**2);
taylorcombine(p - taylor(x**2,x,0,5));

comment Switch back to finite number of terms;

taylorprintterms := 6;

comment Some more examples;

taylor ((1 + x)**n, x, 0, 3);

taylor (e**(-a*t) * (1 + sin(t)), t, 0, 4);

operator f;

taylor (1 + f(t), t, 0, 3);

clear f;

taylor (sqrt(1 + a*x + sin(x)), x, 0, 3);

taylorcombine (ws**2);

taylor (sqrt(1 + x), x, 0, 5);

taylor ((cos(x) - sec(x))^3, x, 0, 5);

taylor ((cos(x) - sec(x))^-3, x, 0, 5);

taylor (sqrt(1 - k^2*sin(x)^2), x, 0, 6);

taylor (sin(x + y), x, 0, 3, y, 0, 3);

taylor (e^x - 1 - x,x,0,6);

taylorcombine sqrt ws;


comment A more complicated example contributed by Stan Kameny;

zz2 := (z*(z-2*pi*i)*(z-pi*i/2)^2)/(sinh z-i);
dz2 := df(zz2,z);
z0 := pi*i/2;
taylor(dz2,z,z0,6);


comment A problem are non-analytic terms: there are no precautions
        taken to detect or handle them;

taylor (sqrt (x), x, 0, 2);

taylor (e**(1/x), x, 0, 2);

comment Even worse: you can substitute a non analytical kernel;

sub (y = sqrt (x), yy);

comment Expansion about infinity is possible in principle...;

taylor (e**(1/x), x, infinity, 5);
xi := taylor (sin (1/x), x, infinity, 5);

y1 := taylor(x/(x-1), x, infinity, 3);
z := df(y1, x);

comment ...but far from being perfect;

taylor (1 / sin (x), x, infinity, 5);

clear z;

comment The template of a Taylor kernel can be extracted;

taylortemplate yy;

taylortemplate xxa;

taylortemplate xi;

taylortemplate xy;

taylortemplate xx1;

comment Here is a slightly less trivial example;

exp := (sin (x) * sin (y) / (x * y))**2;

taylor (exp, x, 0, 1, y, 0, 1);
taylor (exp, x, 0, 2, y, 0, 2);

tt := taylor (exp, {x,y}, 0, 2);

comment An example that uses factorization;

on factor;

ff := y**5 - 1;

zz := sub (y = taylor(e**x, x, 0, 3), ff);

on exp;

zz;

comment A simple example of Taylor kernel differentiation;

hugo := taylor(e^x,x,0,5);
df(hugo^2,x);

comment The following shows the (limited) capabilities to integrate
        Taylor kernels. Only a toplevel Taylor kernel is supported,
        in all other cases a warning is printed and the Taylor kernels
        are converted to standard representation;

zz := taylor (sin x, x, 0, 5);
ww := taylor (cos y, y, 0, 5);

int (zz, x);
int (ww, x);
int (zz + ww, x);


comment And here we present Taylor series reversion.
        We start with the example given by Knuth for the algorithm;

taylor (t - t**2, t, 0, 5);

taylorrevert (ws, t, x);

tan!-series := taylor (tan x, x, 0, 5);
taylorrevert (tan!-series, x, y);
atan!-series:=taylor (atan y, y, 0, 5);

tmp := taylor (e**x, x, 0, 5);

taylorrevert (tmp, x, y);

taylor (log y, y, 1, 5);


comment The following example calculates the perturbation expansion
        of the root x = 20 of the following polynomial in terms of
        EPS, in ROUNDED mode;

poly := for r := 1 : 20 product (x - r);

on rounded;

tpoly := taylor (poly, x, 20, 4);

taylorrevert (tpoly, x, eps);

comment Some more examples using rounded mode;

taylor(sin x/x,x,0,4);

taylor(sin x,x,pi/2,4);

taylor(tan x,x,pi/2,4);

off rounded;


comment An example that involves computing limits of type 0/0 if
        expansion is done via differentiation;


taylor(sqrt((e^x - 1)/x),x,0,15);


comment Examples involving non-analytical terms;

taylor(log(e^x-1),x,0,5);

taylor(e^(1/x)*(e^x-1),x,0,5);

taylor(log(x)*x^10,x,0,5);

taylor(log(x)*x^10,x,0,11);

taylor(log(x-a)/((a-b)*(a-c)) + log(2(x-b))/((b-c)*(b-a))
     + log(x-c)/((c-a)*(c-b)),x,infinity,2);

ss := (sqrt(x^(2/5) +1) - x^(1/3)-1)/x^(1/3);
taylor(exp ss,x,0,2);

taylor(exp sub(x=x^15,ss),x,0,2);


comment In the following we demonstrate the possibiblity to compute the
        expansion of a function which is given by a simple first order
        differential equation: the function myexp(x) is exp(-x^2);

operator myexp,myerf;
let {df(myexp(~x),~x) => -2*x*myexp(x), myexp(0) => 1,
     df(myerf(~x),~x) => 2/sqrt(pi)*myexp(x), myerf(0) => 0};
taylor(myexp(x),x,0,5);
taylor(myerf(x),x,0,5);
clear {df(myexp(~x),~x) => -2*x*myexp(x), myexp(0) => 1,
       df(myerf(~x),~x) => 2/sqrt(pi)*myexp(x), myerf(0) => 0};
clear myexp,erf;

showtime;


comment An application is the problem posed by Prof. Stanley:
        we prove that the finite difference expression below
        corresponds to the given derivative expression;

operator diff,a,f,gg;  % We use gg to avoid conflict with high energy
                       % physics operator.

let diff(~f,~arg) => df(f,arg);

derivative_expression :=
diff(a(x,y)*diff(gg(x,y),x)*diff(gg(x,y),y)*diff(f(x,y),y),x) +
diff(a(x,y)*diff(gg(x,y),x)*diff(gg(x,y),y)*diff(f(x,y),x),y) ;

finite_difference_expression :=
+a(x+dx,y+dy)*f(x+dx,y+dy)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
+a(x+dx,y)*f(x+dx,y+dy)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
+a(x,y+dy)*f(x+dx,y+dy)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
+a(x,y)*f(x+dx,y+dy)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x+dx,y+dy)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x+dx,y)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x,y+dy)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x+dx,y+dy)^2/(32*dx^2*dy^2)
-gg(x,y)*a(x+dx,y+dy)*f(x+dx,y+dy)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x+dx,y)*f(x+dx,y+dy)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x,y+dy)*f(x+dx,y+dy)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
-a(x,y)*gg(x,y)*f(x+dx,y+dy)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x+dx,y+dy)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x+dx,y)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x,y+dy)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x,y)*gg(x+dx,y+dy)/(16*dx^2*dy^2)
-gg(x+dx,y)^2*a(x+dx,y+dy)*f(x+dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y+dy)*gg(x+dx,y)*a(x+dx,y+dy)*f(x+dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y+dy)^2*a(x+dx,y+dy)*f(x+dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x+dx,y+dy)*f(x+dx,y+dy)/(32*dx^2*dy^2)
-a(x+dx,y)*gg(x+dx,y)^2*f(x+dx,y+dy)/(32*dx^2*dy^2)
-a(x,y+dy)*gg(x+dx,y)^2*f(x+dx,y+dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x+dx,y)^2*f(x+dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y+dy)*a(x+dx,y)*gg(x+dx,y)*f(x+dx,y+dy)/(16*dx^2*dy^2)
+a(x,y+dy)*gg(x,y+dy)*gg(x+dx,y)*f(x+dx,y+dy)/(16*dx^2*dy^2)
+a(x,y)*gg(x,y+dy)*gg(x+dx,y)*f(x+dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y+dy)^2*a(x+dx,y)*f(x+dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x+dx,y)*f(x+dx,y+dy)/(32*dx^2*dy^2)
-a(x,y+dy)*gg(x,y+dy)^2*f(x+dx,y+dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x,y+dy)^2*f(x+dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x,y+dy)*f(x+dx,y+dy)/(32*dx^2*dy^2)
+a(x,y)*gg(x,y)^2*f(x+dx,y+dy)/(32*dx^2*dy^2)
+f(x,y)*gg(x+dx,y)^2*a(x+dx,y+dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y+dy)*gg(x+dx,y)*a(x+dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y+dy)^2*a(x+dx,y+dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x+dx,y+dy)/(32*dx^2*dy^2)
+a(x+dx,y-dy)*f(x+dx,y-dy)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
+a(x+dx,y)*f(x+dx,y-dy)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
+a(x,y-dy)*f(x+dx,y-dy)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
+a(x,y)*f(x+dx,y-dy)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x+dx,y-dy)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x+dx,y)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x,y-dy)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x+dx,y-dy)^2/(32*dx^2*dy^2)
-gg(x,y)*a(x+dx,y-dy)*f(x+dx,y-dy)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x+dx,y)*f(x+dx,y-dy)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x,y-dy)*f(x+dx,y-dy)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
-a(x,y)*gg(x,y)*f(x+dx,y-dy)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x+dx,y-dy)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x+dx,y)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x,y-dy)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x,y)*gg(x+dx,y-dy)/(16*dx^2*dy^2)
-gg(x+dx,y)^2*a(x+dx,y-dy)*f(x+dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y-dy)*gg(x+dx,y)*a(x+dx,y-dy)*f(x+dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y-dy)^2*a(x+dx,y-dy)*f(x+dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x+dx,y-dy)*f(x+dx,y-dy)/(32*dx^2*dy^2)
-a(x+dx,y)*gg(x+dx,y)^2*f(x+dx,y-dy)/(32*dx^2*dy^2)
-a(x,y-dy)*gg(x+dx,y)^2*f(x+dx,y-dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x+dx,y)^2*f(x+dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y-dy)*a(x+dx,y)*gg(x+dx,y)*f(x+dx,y-dy)/(16*dx^2*dy^2)
+a(x,y-dy)*gg(x,y-dy)*gg(x+dx,y)*f(x+dx,y-dy)/(16*dx^2*dy^2)
+a(x,y)*gg(x,y-dy)*gg(x+dx,y)*f(x+dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y-dy)^2*a(x+dx,y)*f(x+dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x+dx,y)*f(x+dx,y-dy)/(32*dx^2*dy^2)
-a(x,y-dy)*gg(x,y-dy)^2*f(x+dx,y-dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x,y-dy)^2*f(x+dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x,y-dy)*f(x+dx,y-dy)/(32*dx^2*dy^2)
+a(x,y)*gg(x,y)^2*f(x+dx,y-dy)/(32*dx^2*dy^2)
+f(x,y)*gg(x+dx,y)^2*a(x+dx,y-dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y-dy)*gg(x+dx,y)*a(x+dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y-dy)^2*a(x+dx,y-dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x+dx,y-dy)/(32*dx^2*dy^2)
+f(x,y)*a(x+dx,y)*gg(x+dx,y)^2/(16*dx^2*dy^2)
+f(x,y)*a(x,y+dy)*gg(x+dx,y)^2/(32*dx^2*dy^2)
+f(x,y)*a(x,y-dy)*gg(x+dx,y)^2/(32*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x+dx,y)^2/(16*dx^2*dy^2)
-f(x,y)*gg(x,y+dy)*a(x+dx,y)*gg(x+dx,y)/(16*dx^2*dy^2)
-f(x,y)*gg(x,y-dy)*a(x+dx,y)*gg(x+dx,y)/(16*dx^2*dy^2)
-f(x,y)*a(x,y+dy)*gg(x,y+dy)*gg(x+dx,y)/(16*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x,y+dy)*gg(x+dx,y)/(16*dx^2*dy^2)
-f(x,y)*a(x,y-dy)*gg(x,y-dy)*gg(x+dx,y)/(16*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x,y-dy)*gg(x+dx,y)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y+dy)^2*a(x+dx,y)/(32*dx^2*dy^2)
+f(x,y)*gg(x,y-dy)^2*a(x+dx,y)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x+dx,y)/(16*dx^2*dy^2)
+a(x-dx,y+dy)*f(x-dx,y+dy)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
+a(x-dx,y)*f(x-dx,y+dy)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
+a(x,y+dy)*f(x-dx,y+dy)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
+a(x,y)*f(x-dx,y+dy)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x-dx,y+dy)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x-dx,y)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x,y+dy)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x-dx,y+dy)^2/(32*dx^2*dy^2)
-gg(x,y)*a(x-dx,y+dy)*f(x-dx,y+dy)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x-dx,y)*f(x-dx,y+dy)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x,y+dy)*f(x-dx,y+dy)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
-a(x,y)*gg(x,y)*f(x-dx,y+dy)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x-dx,y+dy)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x-dx,y)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x,y+dy)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x,y)*gg(x-dx,y+dy)/(16*dx^2*dy^2)
-gg(x-dx,y)^2*a(x-dx,y+dy)*f(x-dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y+dy)*gg(x-dx,y)*a(x-dx,y+dy)*f(x-dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y+dy)^2*a(x-dx,y+dy)*f(x-dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x-dx,y+dy)*f(x-dx,y+dy)/(32*dx^2*dy^2)
-a(x-dx,y)*gg(x-dx,y)^2*f(x-dx,y+dy)/(32*dx^2*dy^2)
-a(x,y+dy)*gg(x-dx,y)^2*f(x-dx,y+dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x-dx,y)^2*f(x-dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y+dy)*a(x-dx,y)*gg(x-dx,y)*f(x-dx,y+dy)/(16*dx^2*dy^2)
+a(x,y+dy)*gg(x,y+dy)*gg(x-dx,y)*f(x-dx,y+dy)/(16*dx^2*dy^2)
+a(x,y)*gg(x,y+dy)*gg(x-dx,y)*f(x-dx,y+dy)/(16*dx^2*dy^2)
-gg(x,y+dy)^2*a(x-dx,y)*f(x-dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x-dx,y)*f(x-dx,y+dy)/(32*dx^2*dy^2)
-a(x,y+dy)*gg(x,y+dy)^2*f(x-dx,y+dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x,y+dy)^2*f(x-dx,y+dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x,y+dy)*f(x-dx,y+dy)/(32*dx^2*dy^2)
+a(x,y)*gg(x,y)^2*f(x-dx,y+dy)/(32*dx^2*dy^2)
+f(x,y)*gg(x-dx,y)^2*a(x-dx,y+dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y+dy)*gg(x-dx,y)*a(x-dx,y+dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y+dy)^2*a(x-dx,y+dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x-dx,y+dy)/(32*dx^2*dy^2)
+a(x-dx,y-dy)*f(x-dx,y-dy)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
+a(x-dx,y)*f(x-dx,y-dy)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
+a(x,y-dy)*f(x-dx,y-dy)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
+a(x,y)*f(x-dx,y-dy)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x-dx,y-dy)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x-dx,y)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
-f(x,y)*a(x,y-dy)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x-dx,y-dy)^2/(32*dx^2*dy^2)
-gg(x,y)*a(x-dx,y-dy)*f(x-dx,y-dy)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x-dx,y)*f(x-dx,y-dy)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y)*a(x,y-dy)*f(x-dx,y-dy)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
-a(x,y)*gg(x,y)*f(x-dx,y-dy)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x-dx,y-dy)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x-dx,y)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y)*a(x,y-dy)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x,y)*gg(x-dx,y-dy)/(16*dx^2*dy^2)
-gg(x-dx,y)^2*a(x-dx,y-dy)*f(x-dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y-dy)*gg(x-dx,y)*a(x-dx,y-dy)*f(x-dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y-dy)^2*a(x-dx,y-dy)*f(x-dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x-dx,y-dy)*f(x-dx,y-dy)/(32*dx^2*dy^2)
-a(x-dx,y)*gg(x-dx,y)^2*f(x-dx,y-dy)/(32*dx^2*dy^2)
-a(x,y-dy)*gg(x-dx,y)^2*f(x-dx,y-dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x-dx,y)^2*f(x-dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y-dy)*a(x-dx,y)*gg(x-dx,y)*f(x-dx,y-dy)/(16*dx^2*dy^2)
+a(x,y-dy)*gg(x,y-dy)*gg(x-dx,y)*f(x-dx,y-dy)/(16*dx^2*dy^2)
+a(x,y)*gg(x,y-dy)*gg(x-dx,y)*f(x-dx,y-dy)/(16*dx^2*dy^2)
-gg(x,y-dy)^2*a(x-dx,y)*f(x-dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x-dx,y)*f(x-dx,y-dy)/(32*dx^2*dy^2)
-a(x,y-dy)*gg(x,y-dy)^2*f(x-dx,y-dy)/(32*dx^2*dy^2)
-a(x,y)*gg(x,y-dy)^2*f(x-dx,y-dy)/(32*dx^2*dy^2)
+gg(x,y)^2*a(x,y-dy)*f(x-dx,y-dy)/(32*dx^2*dy^2)
+a(x,y)*gg(x,y)^2*f(x-dx,y-dy)/(32*dx^2*dy^2)
+f(x,y)*gg(x-dx,y)^2*a(x-dx,y-dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y-dy)*gg(x-dx,y)*a(x-dx,y-dy)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y-dy)^2*a(x-dx,y-dy)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x-dx,y-dy)/(32*dx^2*dy^2)
+f(x,y)*a(x-dx,y)*gg(x-dx,y)^2/(16*dx^2*dy^2)
+f(x,y)*a(x,y+dy)*gg(x-dx,y)^2/(32*dx^2*dy^2)
+f(x,y)*a(x,y-dy)*gg(x-dx,y)^2/(32*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x-dx,y)^2/(16*dx^2*dy^2)
-f(x,y)*gg(x,y+dy)*a(x-dx,y)*gg(x-dx,y)/(16*dx^2*dy^2)
-f(x,y)*gg(x,y-dy)*a(x-dx,y)*gg(x-dx,y)/(16*dx^2*dy^2)
-f(x,y)*a(x,y+dy)*gg(x,y+dy)*gg(x-dx,y)/(16*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x,y+dy)*gg(x-dx,y)/(16*dx^2*dy^2)
-f(x,y)*a(x,y-dy)*gg(x,y-dy)*gg(x-dx,y)/(16*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x,y-dy)*gg(x-dx,y)/(16*dx^2*dy^2)
+f(x,y)*gg(x,y+dy)^2*a(x-dx,y)/(32*dx^2*dy^2)
+f(x,y)*gg(x,y-dy)^2*a(x-dx,y)/(32*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x-dx,y)/(16*dx^2*dy^2)
+f(x,y)*a(x,y+dy)*gg(x,y+dy)^2/(16*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x,y+dy)^2/(16*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x,y+dy)/(16*dx^2*dy^2)
+f(x,y)*a(x,y-dy)*gg(x,y-dy)^2/(16*dx^2*dy^2)
+a(x,y)*f(x,y)*gg(x,y-dy)^2/(16*dx^2*dy^2)
-f(x,y)*gg(x,y)^2*a(x,y-dy)/(16*dx^2*dy^2)
-a(x,y)*f(x,y)*gg(x,y)^2/(8*dx^2*dy^2)$

comment We define abbreviations for the partial derivatives;

operator ax,ay,fx,fy,gx,gy;
operator axx,axy,ayy,fxx,fxy,fyy,gxx,gxy,gyy;
operator axxx,axxy,axyy,ayyy,fxxx,fxxy,fxyy,fyyy,gxxx,gxxy,gxyy,gyyy;
operator axxxy,axxyy,axyyy,fxxxy,fxxyy,fxyyy,
         gxxxx,gxxxy,gxxyy,gxyyy,gyyyy;
operator axxxyy,axxyyy,fxxyyy,fxxxyy,gxxxxy,gxxxyy,gxxyyy,gxyyyy;
operator gxxxxyy,gxxxyyy,gxxyyyy;

operator_diff_rules := {
  df(a(~x,~y),~x) => ax(x,y),
  df(a(~x,~y),~y) => ay(x,y),
  df(f(~x,~y),~x) => fx(x,y),
  df(f(~x,~y),~y) => fy(x,y),
  df(gg(~x,~y),~x) => gx(x,y),
  df(gg(~x,~y),~y) => gy(x,y),

  df(ax(~x,~y),~x) => axx(x,y),
  df(ax(~x,~y),~y) => axy(x,y),
  df(ay(~x,~y),~x) => axy(x,y),
  df(ay(~x,~y),~y) => ayy(x,y),
  df(fx(~x,~y),~x) => fxx(x,y),
  df(fx(~x,~y),~y) => fxy(x,y),
  df(fy(~x,~y),~x) => fxy(x,y),
  df(fy(~x,~y),~y) => fyy(x,y),
  df(gx(~x,~y),~x) => gxx(x,y),
  df(gx(~x,~y),~y) => gxy(x,y),
  df(gy(~x,~y),~x) => gxy(x,y),
  df(gy(~x,~y),~y) => gyy(x,y),

  df(axx(~x,~y),~x) => axxx(x,y),
  df(axy(~x,~y),~x) => axxy(x,y),
  df(ayy(~x,~y),~x) => axyy(x,y),
  df(ayy(~x,~y),~y) => ayyy(x,y),
  df(fxx(~x,~y),~x) => fxxx(x,y),
  df(fxy(~x,~y),~x) => fxxy(x,y),
  df(fxy(~x,~y),~y) => fxyy(x,y),
  df(fyy(~x,~y),~x) => fxyy(x,y),
  df(fyy(~x,~y),~y) => fyyy(x,y),
  df(gxx(~x,~y),~x) => gxxx(x,y),
  df(gxx(~x,~y),~y) => gxxy(x,y),
  df(gxy(~x,~y),~x) => gxxy(x,y),
  df(gxy(~x,~y),~y) => gxyy(x,y),
  df(gyy(~x,~y),~x) => gxyy(x,y),
  df(gyy(~x,~y),~y) => gyyy(x,y),

  df(axyy(~x,~y),~x) => axxyy(x,y),
  df(axxy(~x,~y),~x) => axxxy(x,y),
  df(ayyy(~x,~y),~x) => axyyy(x,y),
  df(fxxy(~x,~y),~x) => fxxxy(x,y),
  df(fxyy(~x,~y),~x) => fxxyy(x,y),
  df(fyyy(~x,~y),~x) => fxyyy(x,y),
  df(gxxx(~x,~y),~x) => gxxxx(x,y),
  df(gxxy(~x,~y),~x) => gxxxy(x,y),
  df(gxyy(~x,~y),~x) => gxxyy(x,y),
  df(gyyy(~x,~y),~x) => gxyyy(x,y),
  df(gyyy(~x,~y),~y) => gyyyy(x,y),

  df(axxyy(~x,~y),~x) => axxxyy(x,y),
  df(axyyy(~x,~y),~x) => axxyyy(x,y),
  df(fxxyy(~x,~y),~x) => fxxxyy(x,y),
  df(fxyyy(~x,~y),~x) => fxxyyy(x,y),
  df(gxxxy(~x,~y),~x) => gxxxxy(x,y),
  df(gxxyy(~x,~y),~x) => gxxxyy(x,y),
  df(gxyyy(~x,~y),~x) => gxxyyy(x,y),
  df(gyyyy(~x,~y),~x) => gxyyyy(x,y),

  df(gxxxyy(~x,~y),~x) => gxxxxyy(x,y),
  df(gxxyyy(~x,~y),~x) => gxxxyyy(x,y),
  df(gxyyyy(~x,~y),~x) => gxxyyyy(x,y)
};

let operator_diff_rules;

texp := taylor (finite_difference_expression, dx, 0, 1, dy, 0, 1);

comment You may also try to expand further but this needs a lot
        of CPU time.  Therefore the following line is commented out;

%texp := taylor (finite_difference_expression, dx, 0, 2, dy, 0, 2);

factor dx,dy;

result := taylortostandard texp;

derivative_expression - result;


clear diff(~f,~arg);
clearrules operator_diff_rules;
clear diff,a,f,gg;
clear ax,ay,fx,fy,gx,gy;
clear axx,axy,ayy,fxx,fxy,fyy,gxx,gxy,gyy;
clear axxx,axxy,axyy,ayyy,fxxx,fxxy,fxyy,fyyy,gxxx,gxxy,gxyy,gyyy;
clear axxxy,axxyy,axyyy,fxxxy,fxxyy,fxyyy,gxxxx,gxxxy,gxxyy,gxyyy,gyyyy;
clear axxxyy,axxyyy,fxxyyy,fxxxyy,gxxxxy,gxxxyy,gxxyyy,gxyyyy;
clear gxxxxyy,gxxxyyy,gxxyyyy;

taylorprintterms := 5;

off taylorautoexpand,taylorkeeporiginal;

comment That's all, folks;

showtime;

end;
