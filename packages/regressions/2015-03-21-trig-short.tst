%%
%% Regression test files for improved trigonometric simplication
%%

% Start with tests of the standard rules

sin(a+3*pi); sin(a-3*pi);
cos(a+3*pi); cos(a-3*pi);
csc(a+3*pi); csc(a-3*pi);
sec(a+3*pi); sec(a-3*pi);
tan(a+3*pi); tan(a-3*pi);
cot(a+3*pi); cot(a-3*pi);

sin(a+3/2*pi); sin(a-3/2*pi);
cos(a+3/2*pi); cos(a-3/2*pi);
csc(a+3/2*pi); csc(a-3/2*pi);
sec(a+3/2*pi); sec(a-3/2*pi);
tan(a+3/2*pi); tan(a-3/2*pi);
cot(a+3/2*pi); cot(a-3/2*pi);

sin(a/2+3/2*pi); sin(a/2-3/2*pi);
cos(a/2+3/2*pi); cos(a/2-3/2*pi);
csc(a/2+3/2*pi); csc(a/2-3/2*pi);
sec(a/2+3/2*pi); sec(a/2-3/2*pi);
tan(a/2+3/2*pi); tan(a/2-3/2*pi);
cot(a/2+3/2*pi); cot(a/2-3/2*pi);

sin(a+1/2*pi); sin(a-1/2*pi);
cos(a+1/2*pi); cos(a-1/2*pi);
csc(a+1/2*pi); csc(a-1/2*pi);
sec(a+1/2*pi); sec(a-1/2*pi);
tan(a+1/2*pi); tan(a-1/2*pi);
cot(a+1/2*pi); cot(a-1/2*pi);

sin(a/2+1/2*pi); sin(a/2-1/2*pi);
cos(a/2+1/2*pi); cos(a/2-1/2*pi);
csc(a/2+1/2*pi); csc(a/2-1/2*pi);
sec(a/2+1/2*pi); sec(a/2-1/2*pi);
tan(a/2+1/2*pi); tan(a/2-1/2*pi);
cot(a/2+1/2*pi); cot(a/2-1/2*pi);

sinh(a+3*i*pi); sinh(a-3*i*pi);
cosh(a+3*i*pi); cosh(a-3*i*pi);
csch(a+3*i*pi); csch(a-3*i*pi);
sech(a+3*i*pi); sech(a-3*i*pi);
tanh(a+3*i*pi); tanh(a-3*i*pi);
coth(a+3*i*pi); coth(a-3*i*pi);

sinh(a+3/2*i*pi); sinh(a-3/2*i*pi);
cosh(a+3/2*i*pi); cosh(a-3/2*i*pi);
csch(a+3/2*i*pi); csch(a-3/2*i*pi);
sech(a+3/2*i*pi); sech(a-3/2*i*pi);
tanh(a+3/2*i*pi); tanh(a-3/2*i*pi);
coth(a+3/2*i*pi); coth(a-3/2*i*pi);

sinh(a/2+3/2*i*pi); sinh(a/2-3/2*i*pi);
cosh(a/2+3/2*i*pi); cosh(a/2-3/2*i*pi);
csch(a/2+3/2*i*pi); csch(a/2-3/2*i*pi);
sech(a/2+3/2*i*pi); sech(a/2-3/2*i*pi);
tanh(a/2+3/2*i*pi); tanh(a/2-3/2*i*pi);
coth(a/2+3/2*i*pi); coth(a/2-3/2*i*pi);

sinh(a+1/2*i*pi); sinh(a-1/2*i*pi);
cosh(a+1/2*i*pi); cosh(a-1/2*i*pi);
csch(a+1/2*i*pi); csch(a-1/2*i*pi);
sech(a+1/2*i*pi); sech(a-1/2*i*pi);
tanh(a+1/2*i*pi); tanh(a-1/2*i*pi);
coth(a+1/2*i*pi); coth(a-1/2*i*pi);

sinh(a/2+1/2*i*pi); sinh(a/2-1/2*i*pi);
cosh(a/2+1/2*i*pi); cosh(a/2-1/2*i*pi);
csch(a/2+1/2*i*pi); csch(a/2-1/2*i*pi);
sech(a/2+1/2*i*pi); sech(a/2-1/2*i*pi);
tanh(a/2+1/2*i*pi); tanh(a/2-1/2*i*pi);
coth(a/2+1/2*i*pi); coth(a/2-1/2*i*pi);

% The following input expressions did return wrong results, like
% sin(a/2+1/2*i*pi) --> cos(a/2)*sign(i)
% and
% sinh(a/2+1/2*pi)  --> -i*cosh(a/2)*sign(i)

sin(a/2+1/2*i*pi); sin(a/2-1/2*i*pi);
cos(a/2+1/2*i*pi); cos(a/2-1/2*i*pi);
csc(a/2+1/2*i*pi); csc(a/2-1/2*i*pi);
sec(a/2+1/2*i*pi); sec(a/2-1/2*i*pi);
tan(a/2+1/2*i*pi); tan(a/2-1/2*i*pi);
cot(a/2+1/2*i*pi); cot(a/2-1/2*i*pi);

sinh(a/2+1/2*pi); sinh(a/2-1/2*pi);
cosh(a/2+1/2*pi); cosh(a/2-1/2*pi);
csch(a/2+1/2*pi); csch(a/2-1/2*pi);
sech(a/2+1/2*pi); sech(a/2-1/2*pi);
tanh(a/2+1/2*pi); tanh(a/2-1/2*pi);
coth(a/2+1/2*pi); coth(a/2-1/2*pi);

% missing rule for asec added
{asec(-x), acot(-x)};
{acos(sqrt 3/2), acos(-sqrt 3/2)};
{asec(2/sqrt 3), asec(-2/sqrt 3)};

% conditions on pi shifts weakened
{sin(x/y+3pi), sin(k*pi+pi), sin(pi*(x+360)/180), sin(x+22pi/7), sin(1/pi+pi)};

% rules now work with rational on
on rational;
{sin(pi/2), cos(pi/2), sin(pi/12), cos(pi/12)};
{sin(x+pi/2), cos(x+pi/2)};
{acos(sqrt 3/2), acos(-sqrt 3/2)};
{asec(2/sqrt 3), asec(-2/sqrt 3)};
off rational;

% shifts for sec and csc
{csc(a+7pi), sec(a+8pi), csc(a+8pi/7), sec(a+8pi/7)};

% shifts now into range -pi/2 .. +pi/2
{sin(a+13pi/7),  tan(a+13pi/7),  cot(a-13pi/7), sec(a-13pi/7)};

% consistent treatment of cot and tan & equal rights for sec and csc
{sin(a+3pi/2), cos(a+3pi/2), tan(a+3pi/2), cot(a+3pi/2), csc(a+3pi/2), sec(a+3pi/2)};
{sin(a+5pi/2), cos(a+5pi/2), tan(a+5pi/2), cot(a+5pi/2), csc(a+5pi/2), sec(a+5pi/2)};


% rules work with complex on 
{sin(a+50*pi+2i), cos(a+(50*pi-3i)/7), sin(a+(50+2i)*pi), cos(a+(50-3i)*pi/7)};
on complex;
{sin(a+50*pi+2i), cos(a+(50*pi-3i)/7), sin(a+(50+2i)*pi), cos(a+(50-3i)*pi/7)};
on rational;
{sin(a+50*pi+2i), cos(a+(50*pi-3i)/7), sin(a+(50+2i)*pi), cos(a+(50-3i)*pi/7)};
off complex, rational;

% new rules for atan2
{atan2(1,0), atan2(-1,0), atan2(0, 1), atan2(0, -1)};
{atan2(1,1), atan2(1,-1), atan2(-1, 1), atan2(-1, -1)};
atan2(y^2, -x^2);

% so re/impart of log useful 
realvalued x,y;
{repart log(x+i*y), impart log(x+i*y)};
{repart log(x^2+i*y^2), impart log(x^2+i*y^2)};
{repart log(-1), impart log(-1)};
{repart log(i), impart log i, impart log(-i)};
{repart log(1+i), impart log(1+i), repart log(-1-i), impart log(-1-i)};

% rules for arbint shifts corrected & generalised
{exp(z+4i*arbint(1)*pi), exp(z+3i*arbint(1)*pi)};

sin(z+3*arbint(1)*pi); 
 % no longer crashes
sin(z-3*arbint(1)*pi);

% better conditions on pi shifts
sin(1/pi+pi);
off mcd;
sin(1/pi+pi);
on mcd;

sin(pi^2+pi);
cos(pi^2+pi);
csc(pi^2+pi);
sec(pi^2+pi);
tan(pi^2+pi);
cot(pi^2+pi);

sin(2i*pi+pi);
cos(2i*pi+pi);
csc(2i*pi+pi);
sec(2i*pi+pi);
tan(2i*pi+pi);
cot(2i*pi+pi);

sinh(2i*pi+pi);
cosh(2i*pi+pi);
csch(2i*pi+pi);
sech(2i*pi+pi);
tanh(2i*pi+pi);
coth(2i*pi+pi);

on complex;
sin(2i*pi+pi);
cos(2i*pi+pi);
csc(2i*pi+pi);
sec(2i*pi+pi);
tan(2i*pi+pi);
cot(2i*pi+pi);
sinh(2i*pi+pi);
cosh(2i*pi+pi);
csch(2i*pi+pi);
sech(2i*pi+pi);
tanh(2i*pi+pi);
coth(2i*pi+pi);
off complex;

sin(3/5*pi);
cos(3/5*pi);
csc(3/5*pi);
sec(3/5*pi);
tan(3/5*pi);
cot(3/5*pi);

sin(-5/7*pi);
cos(-5/7*pi);
csc(-5/7*pi);
sec(-5/7*pi);
tan(-5/7*pi);
cot(-5/7*pi);

sinh(3/5*i*pi);
cosh(3/5*i*pi);
csch(3/5*i*pi);
sech(3/5*i*pi);
tanh(3/5*i*pi);
coth(3/5*i*pi);

sinh(-5/7*i*pi);
cosh(-5/7*i*pi);
csch(-5/7*i*pi);
sech(-5/7*i*pi);
tanh(-5/7*i*pi);
coth(-5/7*i*pi);

end;

