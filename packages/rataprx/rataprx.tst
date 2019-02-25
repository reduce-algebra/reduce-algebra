% Tests of the rataprx package.

% Authors: Lisa Temme, Wolfram Koepf (koepf@zib.de)

% periodic decimal representations
rational2periodic(1/3);
periodic2rational(ws);
rational2periodic(-1/3);
periodic2rational(ws);
rational2periodic(1.2/3);
periodic2rational(ws);
rational2periodic(1/3.4);
periodic2rational(ws);
rational2periodic(1.2/3.4);
periodic2rational(ws);
rational2periodic(352673/3124);
periodic2rational(ws);
rational2periodic(53765/5216);
periodic2rational(ws);

% continued fractions
% of numbers
cfrac pi;
cfrac(pi,3);
cfrac(pi,20);
oldprec:=precision 20;
!*b := cfrac pi;
cfrac(pi^2);
cfrac(pi*e*sqrt(2));
precision oldprec;

% of rational functions
cfrac((x+2/3)^2/(6*x-5),x);
cfrac((x+2/3)^2/(6*x-5),x,0);
cfrac((x+2/3)^2/(6*x-5),x,1);
cfrac((x+2/3)^2/(6*x-5),x,10);
cfrac((x*8-7/2)^4/(x^5-2/3),x);
cfrac((x*8-7/2)^4/(x^5-2/3),x,2);

% of analytic functions
cfrac(e^x,x,10);
% default order is 5
!*d := cfrac(e^x,x);
cfrac(x^2/(x-1)*e^x,x);
cfrac(x^2/(x-1)*e^x,x,2);
cfrac(atan(x),x,10);
cfrac(asin(x),x,5);

% not implemented
cfrac(log(x),x,4);
cfrac(asech(x),x,5);
cfrac(sin sqrt x,x,4);
% wrong input
cfrac(1,x);
cfrac(x,x,x);
cfrac(x,x,x,5);

% shows changes to continued_fraction 
continued_fraction(6/11);  % Used to crash at default precision
oldprec := precision 30;
continued_fraction(6/11);  % Result used to depend on precision
precision 50;
continued_fraction(6/11);  % Result used to depend on precision
precision oldprec;

% New operators cf etc. added by A. Barnes
!*a := cf pi;
cf_convergent(!*a);
cf_convlist(!*a);
cf_coeflist(!*a);
cf_expression(!*a);

% should also work with cfrac output
cf_convergent(!*b);
cf_convlist(!*b);
cf_coeflist(!*b);

% and with continued_fraction output
!*c := continued_fraction pi;
cf_convergent(!*c);
cf_convlist(!*c);
cf_coeflist(!*c);

% some well known expansions
cf(e);
cf(sqrt(2));
cf(sqrt(3));
cf((1+sqrt(5))/2);

% erroneous input
cf_expression(!*b);
cf_expression(!*c);
cf(e^x);
cf(e^x,x);
cf_coeflist({1/2,{1,2,x}});
cf_convlist(!*d);
cf_convergent((x+y)^2);

% Pade representations
pade(sin(x),x,0,3,3);
pade(tanh(x),x,0,5,5);
pade(atan(x),x,0,5,5);
pade(1/(x*sin(x)),x,0,3,2);
pade(sin(x)/x^2,x,0,10,1);
pade(sin(x)/x^2,x,0,10,2);
pade(sin(x)/x^2,x,0,10,3);
pade(exp(x),x,0,10,10);
pade(sin(x),x,0,20,20);
% no Pade Approximation exists 
pade(exp(1/x),x,0,5,5);
% wrong order
pade(sin(x)/x^2,x,0,10,0);
% not implemented
pade(factorial(x),x,1,3,3);
% extended Pade representations
pade(asech(x),x,0,3,3);
taylor(ws-asech(x),x,0,10);
pade(sin(sqrt(x)),x,0,3,3);
taylor(ws-sin(sqrt(x)),x,0,10);

end;
