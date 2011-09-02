% Tests of limits package.

limit(sin(x)/x,x,0);
limit(sin(x)^2/x,x,0);
limit(sin(x)/x,x,1);
limit(1/x,x,0);
limit(-1/x,x,0);
limit((sin(x)-x)/x^3,x,0);
limit(x*sin(1/x),x,infinity);
limit(sin x/x^2,x,0);
limit(x^2*sin(1/x),x,infinity);

% Simple examples from Schaum's Theory & Problems of Advanced Calculus

limit(x^2-6x+4,x,2);
limit((x+3)*(2x-1)/(x^2+3x-2),x,-1);
limit((sqrt(4+h)-2)/h,h,0);
limit((sqrt(x)-2)/(4-x),x,4);
limit((x^2-4)/(x-2),x,2);
limit(1/(2x-5),x,-1);
limit(sqrt(x)/(x+1),x,1);
limit((2x+5)/(3x-2),x,infinity);
limit((1/(x+3)-2/(3x+5))/(x-1),x,1);
limit(sin(3x)/x,x,0);
limit((1-cos(x))/x^2,x,0);
limit((6x-sin(2x))/(2x+3*sin(4x)),x,0);
limit((1-2*cos(x)+cos(2x))/x^2,x,0);
limit((3*sin(pi*x) - sin(3*pi*x))/x^3,x,0);
limit((cos(a*x)-cos(b*x))/x^2,x,0);
limit((e^x-1)/x,x,0);
limit((a^x-b^x)/x,x,0);

% Examples taken from Hyslop's Real Variable

limit(sinh(2x)^2/log(1+x^2),x,0);
limit(x^2*(e^(1/x)-1)*(log(x+2)-log(x)),x,infinity);
limit(x^alpha*log(x+1)^2/log(x),x,infinity);
  %% fails because answer depends in essential way on parameter.

limit((2*cosh(x)-2-x^2)/log(1+x^2)^2,x,0);
limit((x*sinh(x)-2+2*cosh(x))/(x^4+2*x^2),x,0);
limit((2*sinh(x)-tanh(x))/(e^x-1),x,0);
limit(x*tanh(x)/(sqrt(1-x^2)-1),x,0);
limit((2*log(1+x)+x^2-2*x)/x^3,x,0);
limit((e^(5*x)-2*x)^(1/x),x,0);
limit(log(log(x))/log(x)^2,x,infinity);

% These are adapted from Lession 4 from Stoutmyer

limit((e^x-1)/x, x, 0);

limit(((1-x)/log(x))**2, x, 1);

limit(x/(e**x-1), x, 0);

%% One sided limits
limit!+(sin(x)/sqrt(x),x,0);
limit!-(sin(x)/sqrt(x),x,0);


limit(x/log x,x,0);
limit(log(1 + x)/log x,x,infinity);
limit(log x/sqrt x,x,infinity);
limit!+(sqrt x/sin x,x,0);
limit(log x,x,0);
limit(x*log x,x,0);
limit(log x/log(2x),x,0);
limit(log x*log(1+x)*(1+x),x,0);
limit(log x/x,x,infinity);
limit(log x/sqrt x,x,infinity);
limit(log x,x,infinity);
limit(log(x+1)/sin x,x,0);
limit(log(1+1/x)*sin x,x,0);
limit(-log(1+x)*(x+2)/sin x,x,0);
limit(-log x*(3+x)/log(2x),x,0);
limit(log(x+1)^2/sqrt x,x,infinity);
limit(log(x + 1) - log x,x,infinity);
limit(-(log x)^2/log log x,x,infinity);
limit(log(x-1)/sin x,x,0); %% -> INFINITY, but what should it be?
limit!-(sqrt x/sin x,x,0);  % infinity
limit(log x-log(2x),x,0); % or any other limit!
limit(sqrt x-sqrt(x+1),x,infinity);
limit(sin sin x/x,x,0);
limit!-(sin x/cos x,x,pi/2); % this works!
limit!+(sin x/cos x,x,pi/2); % so does this!
  % but limit!+(tan x,x,pi/2) fails unless tan is defined using let.
limit(sin x/cosh x,x,infinity);
limit(sin x/x,x,infinity);
limit(x*sin(1/x),x,0);
limit(exp x/((exp x + exp(-x))/2),x,infinity);
% limit(exp x/cosh x,x,infinity); % fails in this form, but if cosh is
  %defined using let, then it works.
limit((sin(x^2)/(x*sinh x)),x,0);
limit(log x*sin(x^2)/(x*sinh x),x,0);
limit(sin(x^2)/(x*sinh x*log x),x,0);
limit(log x/log(x^2),x,0);
limit(log(x^2)-log(x^2+8x),x,0);
limit(log(x^2)-log(x^2+8x),x,infinity);
limit(sqrt(x+5)-sqrt x,x,infinity);
limit(2^(log x),x,0);

limit((sin tan x-tan sin x)/(asin atan x-atan asin x),x,0);

% This one has the value infinity, but fails with de L'Hospital's rule:

limit((e+1)^(x^2)/e^x,x,infinity);

showtime;

end;
