comment

This is a demonstration of the working of elementary functions available
in the Reduce system.  It is not intended as an accuracy test.  Other 
functions become available if certain library packages are loaded.

                            -------

Integer functions that work in all domain modes, independent of switch
NUMVAL, so long as their arguments evaluate to real numbers.

Functions of one argument:
FIX, SGN, ROUND, CEILING, FLOOR

(The following functions are available only in symbolic mode, so they
 are not tested here: ISQRT, ICBRT, ILOG2, IROOTN);

fix a;  % will be evaluated only if a evaluates to a real number.

a := 27/4;

fix a;

fix 12.345;

sgn (-15/2);

round 12.5;

ceiling 12.5;

floor 12.5;

% isqrt 12.5;

% icbrt 12.5;

% ilog2 130.7;

% irootn(72,4);

% irootn(72,3/2); % this will not evaluate.


comment   Functions which require arguments which evaluate to integers:

Function of one argument:  FACTORIAL

Fumction of two arguments:  PERM, CHOOSE;$

factorial 10;

perm(5,10);  % permutations of 5 out of 10.

choose(5,10);  % choose 5 out of 10;


comment

These functions are evaluated in dmodes ROUNDED and COMPLEX-ROUNDED
(ON ROUNDED,COMPLEX) so long as their arguments and values evaluate
to real numbers and NUMVAL (normally ON) is ON.

Variable treated as function of no arguments:  E, PI.

Functions of one argument:
EXP, LOG, LN, LOG10, NORM, ARG, SQRT,
RAD2DEG, RAD2DMS, DEG2RAD, DEG2DMS, DMS2DEG, DMS2RAD,
SIN, ASIN, COS, ACOS, TAN, ATAN, COT, ACOT, SEC, ASEC, CSC, ACSC,
SINH, ASINH, COSH, ACOSH, TANH, ATANH, COTH, ACOTH, SECH, ASECH,
CSCH, ACSCH.

Functions of two arguments:
EXPT, LOGB, HYPOT, ATAN2.

Function evaluation is carried out to the precision specified in the
latest PRECISION statement.

(The following functions are available only in symbolic mode, so they
 are not tested here:
  SIND, ASIND, COSD, ACOSD, TAND, ATAND, COTD, ACOTD, SECD, ASECD,
  CSCD, ACSCD, ATAN2D, CBRT);

on rounded; precision 6;

a := exp 3;

log a;

ln a;

log10 1000;

norm (-12.345);  % for real x, this is equivalent to ABS x.

arg (-12.345);  % for real x, this -> if x<0 then pi else 0.0.

sqrt 3;

ws**2;

deg2rad 30;

rad2deg ws;

a := deg2dms 12.345; % a will be a list.

dms2deg ws;

dms2rad a;

rad2deg ws;

asin 0.5;

sin ws;

acos 0.5;

cos ws;

atan 0.5;

tan ws;

acot 0.5;

cot ws;

asec 3;

sec ws;

acsc 3;

csc ws;

asinh 0.5;

sinh ws;

acosh 2;

cosh ws;

atanh 0.5;

tanh ws;

acoth 2;

coth ws;

sech 1;

asech ws;

csch 1;

acsch ws;

expt(2,1.234);

logb(ws,2);

hypot(3,4);

a := -3*pi/4; % any  -pi<a<=pi should work.

atan2(sin a,cos a);

ws - a;  % should be 0.

precision 20;  % functions will be computed to 20 places.

sin 1.5;

asin ws;

precision 50;  % fuctions computed to 50 places.

sin 1.5;

asin ws;

precision 6;

comment   If argument or value are complex, functions are not computed
when dmode is ROUNDED; $

sin(1+i);  % complex argument.

asin 2;  % value would be complex.

on complex;  %now complex arguments and complex results will be handled.

comment   Complex functions of one argument:
EXP, LOG, NORM, ARG, SQRT,
SIN, ASIN, COS, ACOS, TAN, ATAN, COT, ACOT, SEC, ASEC, CSC, ACSC,
SINH, ASINH, COSH. ACOSH, TANH, ATANH, COTH, ACOTH, SECH, ASECH,
CSCH, ACSCH.
(The following functions are available only in symbolic mode, so they
 are not tested here:
  SIND, ASIND, COSD, ACOSD, TAND, ATAND, COTD, ACOTD, SECD, ASECD,
  CSCD, ACSCD.)

Complex function of two variables:  EXPT, LOGB, ATAN2;

e**(pi*i); % should be -1 (except for computational error.)

log(1+i);

exp ws;

norm(5*exp(2i));

arg(5*exp(2i));

sqrt(1+i);

ws**2;

asin 2;

sin ws;

acos 2;

cos ws;

atan(1+i);

tan ws;

acot(1+i);

cot ws;

asec 0.1;

sec ws;

acsc 0.1;

csc ws;

sinh(1+i);

asinh ws;

cosh(1+i);

acosh ws;

atanh 2;

tanh ws;

acoth 0.3;

coth ws;

asech(1-i);

sech ws;

acsch(1-i);

csch ws;

expt(1+i,1-i);

logb(ws,1+i);

a := 1+i; % any a such that - pi < repart a <= pi should work.

atan2(sin a,cos a);

ws - a; % should be 0;

end;


