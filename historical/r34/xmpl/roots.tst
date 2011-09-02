% Tests of the root finding package.

% Author: Stanley L. Kameny (stan%valley.uucp@rand.org)

% Answers are rounded to the value given by rootacc (default = 6) unless
% higher accuracy is needed to separate roots.  Root order and format
% may differ from that given here, but values should agree.
% In the following, problems  20), 78) and 82) are time consuming and
% been commented out to speed up the test.

roots x;   % To load roots package.

write "This is Roots Package test ", symbolic roots!-mod$

% Simple root finding.

showtime;

% 1) multiple real and imaginary roots plus two real roots.
zz:= (x-3)**2*(100x**2+113)**2*(1000000x-10000111)*(x-1); roots zz;
%{X=1.06301*I,X=1.06301*I,X=-1.06301*I,X=-1.06301*I,
%X=3.0,X=3.0,X=1,X=10.0001} (rootacc caused rounding to 6 places)

% Accuracy is increased whenever necessary to separate distinct roots.

% 2) accuracy increase to 7 required for two roots.
zz:=(x**2+1)*(x-2)*(1000000x-2000001); roots zz;
%{X=2.0,X=I,X= - I,X=2.000001}

% 3) accuracy increase to 8 required.
zz:= (x-3)*(10000000x-30000001); roots zz;
%{X=3.0,X=3.0000001}

% 4) accuracy increase required here to separate repeated root from
% simple root.
zz := (x-3)*(1000000x-3000001)*(x-3)*(1000000x-3241234); roots zz;
%{X=3.0,X=3.0,X=3.000001,X=3.24123}

% other simple examples

% 5) five real roots with widely different spacing.
zz:= (x-1)*(10x-11)*(x-1000)*(x-1001)*(x-100000); roots zz;
%{X=1,X=1.1,X=1000.0,X=1001.0,X=100000.0}

% 6) a cluster of 5 roots in complex plane in vicinity of x=1.
zz:= (x-1)*(10000x**2-20000x+10001)*(10000x**2-20000x+9999); roots zz;
%{X=1,X=1.01,X=0.99,X=1 + 0.01*I,X=1 - 0.01*I}

% 7) four closely spaced real roots.
zz := (x-1)*(100x-101)*(100x-102)*(100x-103); roots zz;
%{X=1.02,X=1.01,X=1,X=1.03}

% 8) five closely spaced roots, 3 real + 1 complex pair.
zz := (x-1)*(100x-101)*(100x-102)*(100x**2-200x+101); roots zz;
%{X=1.01,X=1,X=1.02,X=1 + 0.1*I,X=1 - 0.1*I}

% 9) symmetric cluster of 5 roots, 3 real + 1 complex pair.
zz := (x-2)*(10000x**2-40000x+40001)*(10000x**2-40000x+39999); roots zz;
%{X=2.0,X=2.01,X=1.99,X=2.0 + 0.01*I,X=2.0 - 0.01*I}

% 10) closely spaced real and complex pair.
ss:= (x-2)*(100000000x**2-400000000x+400000001); roots ss;
%{X=2.0,X=2.0 + 0.0001*I,X=2.0 - 0.0001*I}

% 11) Zero roots and multiple roots cause no problem.
% Multiple roots are shown when the switch multiroot is on
%(normally on.)
zz:= x*(x-1)**2*(x-4)**3*(x**2+1); roots zz;
%{X=0,X=4.0,X=4.0,X=4.0,X=1,X=1,X=I,X= - I}

% 12) nearestroot will find a single root "near" a value, real or
% complex.
nearestroot(zz,2i);
%{X=I}

% More difficult examples.

% Three examples in which root scaling is needed in the complex
% iteration process.

% 13) nine roots, 3 real and 3 complex pairs.
zz:= x**9-45x-2; roots zz;
%{X= - 0.0444444,X=1.61483,
% X=0.00555 + 1.60944*I,X=0.00555 - 1.60944*I,
% X= - 1.60371,
% X=1.14348 + 1.13804*I,X=1.14348 - 1.13804*I,
% X=-1.13237 + 1.13805*I,X=-1.13237 - 1.13805*I}


% In the next two examples, there are complex roots with extremely
% small real parts (new capability in Mod 1.91.)

% 14) nine roots, 1 real and 4 complex pairs.
zz:= x**9-9999x**2-0.01; roots zz;
%{X=5.0E-29 + 0.00100005*I,X=5.0E-29 - 0.00100005*I,
%X=3.72754,
%X=-0.829456 + 3.63408*I, X=-0.829456 + 3.63408*I,
%X=-3.3584 + 1.61732*I, X=-3.3584 - 1.61732*I,
%X=2.32408 + 2.91431*I, X=2.32408 - 2.91431*I}

% rootacc 7 produces 7 place accuracy; answers will print in bigfloat
% format if floating point print >6 digits is not implemented.

% 15) nine roots, 1 real and 4 complex pairs.
rootacc 7; zz:= x**9-500x**2-0.001; roots zz;
%{X=1.6E-26 + 0.001414214*I,X=1.6E-26 - 0.001414214*I,
% X=-0.540677 + 2.368861*I, X=-0.540677 - 2.368861*I,
% X=-2.189157 + 1.054242*I, X=-2.189157 - 1.054242*I,
% X=1.514944 + 1.899679*I, X=1.514944 - 1.899679*I}

% the famous Wilkinson "ill-conditioned" polynomial and its family.

% 16) W(6) four real roots plus one complex pair.
zz:= 10000*(for j:=1:6 product(x+j))+27x**5; roots zz;
%{X= - 2.950367,X=-4.452438 + 0.021235*I,X=-4.452438 - 0.021235*I,
% X= - 0.9999775,X= - 2.003647,X= - 6.143833}

% 17) W(8) 4 real roots plus 2 complex pairs.
zz:= 1000*(for j:=1:8 product(x+j))+2x**7; roots zz;
%{X=-4.295858 + 0.28151*I,X=-4.295858 - 0.28151*I,
% X= - 2.982725,
% X=-6.494828 + 1.015417*I,X=-6.494828 - 1.015417*I,
% X= - 0.9999996,X= - 2.000356,X= - 8.437546}

% 18) W(10) 6 real roots plus 2 complex pairs.
zz:=1000*(for j:= 1:10 product (x+j))+x**9; roots zz;
%{X= - 4.616444,X=-6.046279 + 1.134321*I,X=-6.046279 - 1.134321*I,
% X= - 4.075943,X= - 2.998063,
% X=-8.70405 + 1.691061*I,X=-8.70405 - 1.691061*I,
% X= -1,X= - 2.000013,X= - 10.80988}

% 19) W(12) 6 real roots plus 3 complex pairs.
zz:= 10000*(for j:=1:12 product(x+j))+4x**11; roots zz;
%{X=-5.985629 + 0.809425*I,X=-5.985629 - 0.809425*I,
% X= - 4.880956,X= - 4.007117,
% X=-7.953917 + 1.948001*I,X=-7.953917 - 1.948001*I,
% X= -1,X=-11.02192 + 2.23956*I,X=-11.02192 - 2.23956*I,
% X= - 2.0,X= - 2.999902,X= - 13.1895}

% 20) W(20) 10 real roots plus 5 complex pairs. (The original problem)
% This example is commented out, since it takes significant time:
%  zz:= x**19+10**7*for j:=1:20 product (x+j); roots zz;
%{X=-10.12155 + 0.6013*I,X=-10.12155 - 0.6013*I,
% X= - 8.928803,
% X=-11.82101 + 1.59862*I,X=-11.82101 - 1.59862*I,
% X= - 8.006075,X= - 6.999746,
% X=-14.01105 + 2.44947*I,X=-14.01105 - 2.44947*I,
% X=-1,X= - 6.000006,
% X=-19.45964 + 1.87436*I,X=-19.45964 - 1.87436*I,
% X= - 2.0,X= - 5.0,
% X=-16.72504 + 2.73158*I,X=-16.72504 - 2.73158*I,
% X= - 3.0,X= - 4.0,X= - 20.78881}

rootacc 6;
% 21)  Finding one of a cluster of 8 roots.
zz:= (10**16*(x-1)**8-1); nearestroot(zz,2);
%{X=1.01}

% 22)  Six real roots spaced 0.01 apart.
c := 100; zz:= (x-1)*for i:=1:5 product (c*x-(c+i)); roots zz;
%{X=1.03,X=1.02,X=1.04,X=1.0,X=1.01,X=1.05}

% 23)  Six real roots spaced 0.001 apart.
c := 1000; zz:= (x-1)*for i:=1:5 product (c*x-(c+i)); roots zz;
%{X=1.003,X=1.002,X=1.004,X=1,X=1.001,X=1.005}

% 24)  Five real roots spaced 0.0001 apart.
c := 10000; zz:= (x-1)*for i:=1:4 product (c*x-(c+i)); roots zz;
%{X=1.0002,X=1.0003,X=1,X=1.0001,X=1.0004}

% 25)  A cluster of 9 roots, 5 real, 2 complex pairs; spacing 0.1.
zz:= (x-1)*(10**8*(x-1)**8-1); roots zz;
%{X=1,X=1.1,X=1 + 0.1*I,X=1 - 0.1*I,X=0.9,
% X=0.929289 + 0.070711*I,X=0.929289 - 0.070711*I,
% X=1.07071 + 0.07071*I,X=1.07071 - 0.07071*I}

% 26)  Same, but with spacing 0.01.
zz:= (x-1)*(10**16*(x-1)**8-1); roots zz;
%{X=1,X=1.01,X=1 + 0.01*I,X=1 - 0.01*I,X=0.99,
% X=0.992929 + 0.007071*I,X=0.992929 - 0.007071*I,
% X=1.00707 + 0.00707*I,X=1.00707 - 0.00707*I}

% 27)  Spacing reduced to 0.001.
zz:= (x-1)*(10**24*(x-1)**8-1); roots zz;
%{X=1,X=1.001,X=1 + 0.001*I,X=1 - 0.001*I,X=0.999,
% X=0.999293 + 0.000707*I,X=0.999293 - 0.000707*I,
% X=1.00071 + 0.000707*I,X=1.00071 - 0.000707*I}

% 28)  Eight roots divided into two clusters.
zz:= (10**8*(x-1)**4-1)*(10**8*(x+1)**4-1); roots zz;
%{X=1.01,X= - 1.01,X=1 + 0.01*I,X=-1 - 0.01*I,
% X=-1 + 0.01*I,X=1 - 0.01*I,X=0.99,X= - 0.99}

% 29)  A cluster of 8 roots in a different configuration.
zz:= (10**8*(x-1)**4-1)*(10**8*(100x-102)**4-1); roots zz;
%{X=1.01, X=1.0199, X=1.02 + 0.0001*I, X=1.02 - 0.0001*I,
% X=1 + 0.01*I, X=1 - 0.01*I, X=0.99, X=1.0201}

% 30)  A cluster of 8 complex roots.
zz:= ((10x-1)**4+1)*((10x+1)**4+1); roots zz;
%{X=0.0292893 + 0.0707107*I,X=-0.0292893 - 0.0707107*I,
% X=-0.0292893 + 0.0707107*I,X=0.0292893 - 0.0707107*I,
% X=0.170711 + 0.070711*I,X=-0.170711 - 0.070711*I,
% X=-0.170711 + 0.070711*I,X=0.170711 - 0.070711*I}

% In these examples, accuracy increase is required to separate a
% repeated root from a simple root.

% 31)  Using allroots;
zz:= (x-4)*(x-3)**2*(1000000x-3000001); roots zz;
%{X=3.0,X=3.0,X=3.000001,X=4.0}

% 32)  Using realroots;
realroots zz;
%{X=3.0,X=3.0,X=3.000001,X=4.0}

comment  Tests of new capabilities in mod 1.87 for handling complex
  polynomials and polynomials with very small imaginary parts or very
  small real roots. A few real examples are shown, just to demonstrate
  that these still work;

% 33) A trivial complex case (but degrees 1 and 2 are special cases);
zz:= x-i; roots zz;
%{X=I}

% 34) Real case.
zz:= y-7; roots zz;
%{Y=7.0}

% 35) Roots with small imaginary parts (new capability);
zz := 10**16*(x**2-2x+1)+1; roots zz;
%{X=1 + 0.00000001*I,X=1 - 0.00000001*I}

% 36) One real, one complex root.
zz:=(x-9)*(x-5i-7); roots zz;
%{X=9.0,X=7.0 + 5.0*I}

% 37) Three real roots.
zz:= (x-1)*(x-2)*(x-3); roots zz;
%{X=2.0,X=1,X=3.0}

% 38) 2 real + 1 imaginary root.
zz:=(x**2-8)*(x-5i); roots zz;
%{X=2.82843,X= - 2.82843,X=5.0*I}

% 39) 2 complex roots.
zz:= (x-1-2i)*(x+2+3i); roots zz;
%{X=1 + 2.0*I,X=-2.0 - 3.0*I}

% 40) 2 irrational complex roots.
zz:= x**2+(3+2i)*x+7i; roots zz;
%{X=0.14936 - 2.21259*I,X=-3.14936 + 0.21259*I}

% 41) 2 complex roots of very different magnitudes with small imaginary
%   parts.
zz:= x**2+(1000000000+12i)*x-1000000000; roots zz;
%{X=1 - 0.000000012*I,X=-1.0E+9 - 12.0*I}

% 42) Multiple real and complex roots cause no difficulty, provided
% that input is given in integer or rational form and mode is complex.
zz :=(x**2-2i*x+5)**3*(x-2i)*(x-11/10)**2; roots zz;
%{X=-1.44949*I, X=-1.44949*I, X=-1.44949*I,
% X=3.44949*I, X=3.44949*I, X=3.44949*I, X=1.1, X=1.1, X=2.0*I}

% 43) 2 real, 2 complex roots.
zz:= (x**2-4)*(x**2+3i*x+5i); roots zz;
%{X=2.0,X= - 2.0,X=-1.2714 + 0.466333*I,X=1.2714 - 3.46633*I}

% 44) 4 complex roots.
zz:= x**4+(0.000001i)*x-16; roots zz;
%{X=2.0 - 0.0000000625*I,X=-2.0*I,X=-2.0 - 0.0000000625*I,X=2.0*I}

% 45) 2 real, 2 complex roots.
zz:= (x**2-4)*(x**2+2i*x+8); roots zz;
%{X=2.0,X= - 2.0,X=2.0*I,X=-4.0*I}

% 46) Using realroots to find only real roots.
realroots zz;
%{X= - 2.0,X=2.0}

% 47) Same example, applying nearestroot to find a single root.
zz:= (x**2-4)*(x**2+2i*x+8); nearestroot(zz,1);
%{X=2.0}

% 48) Same example, but focusing on imaginary point.
nearestroot(zz,i);
%{X=2.0*I}

% 49) The seed parameter can be complex also.
nearestroot(zz,1+i);
%{X=2.0*I}

% 50) One more nearestroot example.  Nearest root to real point may be
%complex.
zz:= (x**2-4)*(x**2-i); roots zz;
%{X=2.0,X= - 2.0,X=0.707107 + 0.707107*I,X=-0.707107 - 0.707107*I}

nearestroot (zz,1);
%{X=0.707107 + 0.707107*I}

% 51) 1 real root plus 5 complex roots.
zz:=(x**3-3i*x**2-5x+9)*(x**3-8); roots zz;
%{X=2.0, X=-1 + 1.73205*I, X=-1 - 1.73205*I,
% X=0.981383 - 0.646597*I, X=-2.41613 + 1.19385*I,
% X=1.43475 + 2.45274*I}

nearestroot(zz,1);
%{X=0.981383 - 0.646597*I}

% 52) roots can be computed to any accuracy desired, eg.  (note that the
% imaginary part of the second root is truncated because of its size,
% and that the imaginary part of a complex root is never polished away,
% even if it is smaller than the accuracy would require.)
zz := x**3+10**(-20)*i*x**2+8; rootacc 12; roots zz; rootacc 0;
%{X=1 - 1.73205080757*I,X=1 + 1.73205080757*I,
% X=-2.0 - 3.33333E-21*I}

% 53) Precision increase to 12 required to find small imaginary root,
% but standard accuracy can be used.
zz := x**2+123456789i*x+1; roots zz;
%{X=0.0000000081*I,X=-123457000.0*I}

% 54) Small real root is found with root 10*18 times larger(new).
zz := (x+1)*(x**2+123456789*x+1); roots zz;
%{X= - 0.0000000081,X= - 1.0,X= - 123457000.0}

% 55) 2 complex, 3 real irrational roots.
ss := (45*x**2+(-10i+12)*x-10i)*(x**3-5x**2+1); roots ss;
%{X=0.469832,X= - 0.429174,X=4.95934,X=0.18139 + 0.417083*I,
% X=-0.448056 - 0.19486*I}

% 56) Complex polynomial with floating coefficients.
zz := x**2+1.2i*x+2.3i+6.7; roots zz;
%{X=-0.42732 + 2.09121*I,X=0.42732 - 3.29121*I}

% multiple roots will be found if coefficients read in exactly.
ZZ := X**3 + (1.09 - 2.4*I)*X**2 + (-1.44 - 2.616*I)*X + -1.5696;
roots zz;
%{X=1.2*I,X=1.2*I,X= - 1.09}

% 57) Realroots, isolater and rlrootno accept 1, 2 or 3 arguments: (new)
zz:= for j:=-1:3 product (x-j); rlrootno zz;
% 5

realroots zz;
%{X=0,X= -1,X=1,X=2.0,X=3.0}

rlrootno(zz,positive); %positive selects positive, excluding 0.
% 3

rlrootno(zz,negative); %negative selects negative, excluding 0.
% 1

realroots(zz,positive);
%{X=1,X=2.0,X=3.0}

rlrootno(zz,-1.5,2); %the format with 3 arguments selects a range.
% 4

realroots(zz,-1.5,2); %the range is inclusive, except that:
%{X=0,X=-1,X=1,X=2.0}

% A specific limit b may be excluded by using   exclude b.  Also, the
% limits infinity and -infinity can be specified.

realroots(zz,exclude 0,infinity);
% equivalent to realroots(zz,positive).
%{X=1,X=2.0,X=3.0}

rlrootno(zz,-infinity,exclude 0); % equivalent to rlrootno(zz,negative).
% 1

rlrootno(zz,-infinity,0);
% 2

rlrootno(zz,infinity,-infinity);
%equivalent to rlrootno zz; (order of limits does not matter.)
% 5

realroots(zz,1,infinity); % finds all real roots >= 1.
%{X=1,X=2.0,X=3.0}

realroots(zz,1,positive); % finds all real roots > 1.
%{X=2.0,X=3.0}

% New capabilities added in mod 1.88.

% 58) 3 complex roots, with two separated by very small real difference.
zz :=(x+i)*(x+10**8i)*(x+10**8i+1); roots zz;
%{X= - I,X=-1.0E+8*I,X=-1 - 1.0E+8*I}

% 59) Real polynomial with two complex roots separated by very small
% imaginary part.
zz:= (10**14x+123456789000000+i)*(10**14x+123456789000000-i); roots zz;
%{X=-1.23457 + 1.0E-14*I,X=-1.23457 - 1.0E-14*I}

% 60) Real polynomial with two roots extremely close together.
zz:= (x+2)*(10**10x+12345678901)*(10**10x+12345678900); roots zz;
%{X= - 1.2345678901,X= - 1.23456789,X= - 2.0}

% 61) Real polynomial with multiple root extremely close to simple root.
zz:= (x-12345678/10000000)*(x-12345679/10000000)**2; roots zz;
%{X=1.2345679,X=1.2345679,X=1.2345678}

% 62) Similar problem using realroots.
zz:=(x-2**30/10**8)**2*(x-(2**30+1)/10**8); realroots zz;
%{X=10.73741824,X=10.73741824,X=10.73741825}

% 63) Three complex roots with small real separation between two.
zz:= (x-i)*(x-1-10**8i)*(x-2-10**8i); roots zz;
%{X=I,X=1 + 1.0E+8*I,X=2.0 + 1.0E+8*I}

% 64) Use of nearestroot to isolate one of the close roots.
nearestroot(zz,10**8i+99/100);
% {X=1 + 1.0E+8*I}

% 65) Slightly more complicated example with close complex roots.
zz:= (x-i)*(10**8x-1234-10**12i)*(10**8x-1233-10**12i); roots zz;
%{X=I,X=0.00001233 + 10000.0*I,X=0.00001234 + 10000.0*I}

% 66) Four closely spaced real roots with varying spacings.
zz:= (x-1+1/10**7)*(x-1+1/10**8)*(x-1)*(x-1-1/10**7); roots zz;
%{X=1,X=0.9999999,X=0.99999999,X=1.0000001}

% 67) Complex pair plus two close real roots.
zz:= (x**2+1)*(x-12345678/10000000)*(x-12345679/10000000); roots zz;
%{X=1.2345678,X=1.2345679,X=I,X= - I}

% 68) Same problem using realroots to find only real roots.
realroots zz;
%{X=1.2345678,X=1.2345679}

% The switch ratroot causes output to be given in rational form.
% 69) Two complex roots with output in rational form.
on ratroot,complex; zz:=x**2-(5i+1)*x+1; sss:= roots zz;

%           17343 - 93179*I     96531 + 518636*I
%SSS := {X=-----------------,X=------------------}
%               500000               100000

% With roots in rational form, mkpoly can be used to reconstruct a
% polynomial.
zz1 := mkpoly sss;

%                    2
%ZZ1 := 50000000000*X  - (49999800000 + 250000100000*I)*X + (
%
%          50000120977 + 42099*I)

% Finding the roots of the new polynomial zz1.
rr:= roots zz1;

%          17343 - 93179*I     96531 + 518636*I
%RR := {X=-----------------,X=------------------}
%              500000               100000

% The roots are stable to the extent that rr=ss, although zz1 and
% zz may differ.

zz1 - zz;

%             2
%49999999999*X  - (49999799999 + 250000099995*I)*X + (50000120976 +
%
%   42099*I)

% 70) Same type of problem in which roots are found exactly.
zz:=(x-10**8+i)*(x-10**8-i)*(x-10**8+3i/2)*(x-i); rr := roots zz;

%          4                    3                      2
%ZZ := (2*X  - (600000000 - I)*X  + 60000000000000005*X  - (
%
%          2000000000000000800000000 + 29999999999999999*I)*X + (
%
%          30000000000000003 + 2000000000000000200000000*I))/2

%RR := {X=100000000 + I,X=100000000 - I,X=I,X=
%
%        200000000 - 3*I
%       -----------------}
%               2

% Reconstructing a polynomial from the roots.
ss := mkpoly rr;

%         4                    3                      2
%SS := 2*X  - (600000000 - I)*X  + 60000000000000005*X  - (
%
%         2000000000000000800000000 + 29999999999999999*I)*X + (
%
%         30000000000000003 + 2000000000000000200000000*I)

% In this case, the same polynomial is obtained.
ss - num zz;
% 0

% 71) Finding one of the complex roots using nearestroot.
nearestroot(zz,10**8-2i);

%    200000000 - 3*I
%{X=-----------------}
%           2

% Finding the other complex root using nearestroot.
nearestroot(zz,10**8+2i);
%{X=100000000 + I}

% 72) A realroots problem which requires accuracy increase to avoid
% confusion of two roots.
zz:=(x+1)*(10000000x-19999999)*(1000000x-2000001)*(x-2); realroots zz;

%          19999999         2000001
% {X=-1,X=----------,X=2,X=---------}
%          10000000         1000000

% 73) Without the accuracy increase, this example would produce the
% obviously incorrect answer 2.
realroots(zz,3/2,exclude 2);

%     19999999
% {X=----------}
%     10000000

% Rlrootno also gives the correct answer in this case.
rlrootno(zz,3/2,exclude 2);
% 1

% 74) Roots works equally well in this problem.
rr := roots zz;

%           19999999              2000001
% RR := {X=----------,X=-1,X=2,X=---------}
%           10000000              1000000

% 75) The function getroot is convenient for obtaining the value of a
% root.
rr1 := getroot(1,rr);

%         19999999
% RR1 := ----------
%         10000000

% 76) For example, the value can be used as an argument to nearestroot.
nearestroot(zz,rr1);

%     19999999
% {X=----------}
%     10000000


comment  New capabilities added to Mod 1.90 for avoiding floating point
exceptions and exceeding iteration limits;

% 77) This and the next example would previously have aborted because
%of exceeding iteration limits:
off ratroot; zz := x**16 - 900x**15 -2; roots zz;
%{X= - 0.665423,X=0.069527 + 0.661817*I,X=0.069527 - 0.661817*I,
% X=0.650944 + 0.138369*I,X=0.650944 - 0.138369*I,
% X=-0.205664 + 0.632867*I,X=-0.205664 - 0.632867*I,
% X=-0.607902 + 0.270641*I,X=-0.607902 - 0.270641*I,
% X=0.332711 + 0.57633*I,X=0.332711 - 0.57633*I,
% X=0.538375 + 0.391176*I,X=0.538375 - 0.391176*I,
% X=-0.44528 + 0.494497*I,X=-0.44528 - 0.494497*I,X=900.0}

% 78) a still harder example.
% This example is commented out, since it takes significant time:
% z := x**30 - 900x**29 - 2; roots zz;
%{X= - 0.810021,
% X=-0.04388 + 0.808856*I,X=-0.04388 - 0.808856*I,
% X=0.805322 + 0.087587*I,X=0.805322 - 0.087587*I,
% X=0.131027 + 0.799383*I,X=0.131027 - 0.799383*I,
% X=-0.791085 + 0.174125*I,X=-0.791085 - 0.174125*I,
% X=-0.216732 + 0.780507*I,X=-0.216732 - 0.780507*I,
% X=0.767663 + 0.258664*I,X=0.767663 - 0.258664*I,
% X=0.299811 + 0.752532*I,X=0.299811 - 0.752532*I,
% X=-0.735162 + 0.340111*I,X=-0.735162 - 0.340111*I,
% X=-0.379447 + 0.715665*I,X=-0.379447 - 0.715665*I,
% X=0.694106 + 0.417645*I,X=0.694106 - 0.417645*I,
% X=-0.524417 + 0.617362*I,X=-0.524417 - 0.617362*I,
% X=0.454578 + 0.67049*I,X=0.454578 - 0.67049*I,
% X=-0.644866 + 0.490195*I,X=-0.644866 - 0.490195*I,
% X=0.588091 + 0.557094*I,X=0.588091 - 0.557094*I,X=900.0}

% 79) this deceptively simple example previously caused floating point
% overflows on some systems:
aa := x**6 - 4*x**3 + 2; realroots aa;
%{X=0.836719,X=1.50579}

% 80) a harder problem, which would have failed on almost all systems:
rr := x**16 - 90000x**15 - x**2 -2; realroots rr;
%{X= - 0.493299,X=90000.0}

% 81) this example would have failed because of floating point
% exceptions on almost all computer systems.
rr := X**30 - 9*10**10*X**29 - 2;  realroots rr;
%{X= - 0.429188,X=9.0E+10}

% 82) a test of allroot on this example.
% This example is commented out, since it takes significant time:
% roots  rr;
%{X= - 0.429188,
% X=-0.023236 + 0.428559*I,X=-0.023236 - 0.428559*I,
% X=0.426672 + 0.046403*I,X=0.426672 - 0.046403*I,
% X=0.069435 + 0.423534*I,X=0.069435 - 0.423534*I,
% X=-0.419154 + 0.092263*I,X=-0.419154 - 0.092263*I,
% X=-0.11482 + 0.413544*I,X=-0.11482 - 0.413544*I,
% X=0.406722 + 0.13704*I,X=0.406722 - 0.13704*I,
% X=0.158859 + 0.398706*I,X=0.158859 - 0.398706*I,
% X=-0.389521 + 0.180211*I,X=-0.389521 - 0.180211*I,
% X=-0.201035 + 0.379193*I,X=-0.201035 - 0.379193*I,
% X=0.367753 + 0.22127*I,X=0.367753 - 0.22127*I,
% X=-0.277851 + 0.327111*I,X=-0.277851 - 0.327111*I,
% X=0.240855 + 0.355234*I,X=0.240855 - 0.355234*I,
% X=-0.341674 + 0.259734*I,X=-0.341674 - 0.259734*I,
% X=0.311589 + 0.295153*I,X=0.311589 - 0.295153*I,X=9.0E+10}

% 83) test of starting point for iteration: no convergence if good
% real starting point is not found.
zz := x**30 -9*10**12x**29 -2; firstroot zz;
%{X= - 0.36617}

% 84) a case in which there are no real roots and good imaginary
% starting point must be used or roots cannot be found.
zz:= 9x**16 - x**5 +1; roots zz;
%{X=0.182294 + 0.828368*I,X=0.182294 - 0.828368*I,
% X=-0.697397 + 0.473355*I,X=-0.697397 - 0.473355*I,
% X=0.845617 + 0.142879*I,X=0.845617 - 0.142879*I,
% X=-0.161318 + 0.87905*I,X=-0.161318 - 0.87905*I,
% X=-0.866594 + 0.193562*I,X=-0.866594 - 0.193562*I,
% X=0.459373 + 0.737443*I,X=0.459373 - 0.737443*I,
% X=0.748039 + 0.494348*I,X=0.748039 - 0.494348*I,
% X=-0.510014 + 0.716449*I,X=-0.510014 - 0.716449*I}

% 85) five complex roots.
zz := x**5 - x**3 + i; roots zz;
%{X=-0.83762*I,X=-0.664702 + 0.636663*I,X=0.664702 + 0.636663*I,
% X=1.16695 - 0.21785*I,X=-1.16695 - 0.21785*I}

% Additional capabilities in Mod 1.91.

% 86) handling of polynomial with huge or infinitesimal coefficients.
on rounded;
zz:= 1.0e-500x**3+x**2+x; roots zz; off rounded;
%{X=0,X=-1,X= - 1.0E+500}

% switch roundbf will have been turned on in the last example in most
% computer systems.  This will inhibit the use of hardware floating
% point unless roundbf is turned off.
% polynomials which make use of powergcd substitution and cascaded
% solutions.

% Uncomplicated cases.

switch powergcd; % introduced here to verify that same answers are
% obtained with and without employing powergcd strategy.  Roots are
% found faster for applicable cases when !*powergcd=t (default state.)

% 87) powergcd done at the top level.
zz := x**12-5x**9+1; roots zz;
%{X=0.848444,X=-0.424222 + 0.734774*I,X=-0.424222 - 0.734774*I,
% X=0.152522 - 0.816316*I,
% X=-0.783212 + 0.276071*I,X=0.63069 + 0.540246*I,
% X=0.152522 + 0.816316*I,
% X=-0.783212 - 0.276071*I,X=0.63069 - 0.540246*I,
% X=1.70906,X=-0.85453 + 1.48009*I,X=-0.85453 - 1.48009*I}

off powergcd; roots zz; on powergcd;
%{X=0.848444,X=-0.424222 + 0.734774*I,X=-0.424222 - 0.734774*I,
% X=1.70906,X=-0.783212 + 0.276071*I,X=-0.783212 - 0.276071*I,
% X=0.152522 + 0.816316*I,X=0.152522 - 0.816316*I,
% X=0.63069 + 0.540246*I,X=0.63069 - 0.540246*I,
% X=-0.85453 + 1.48009*I,X=-0.85453 - 1.48009*I}

% 88) powergcd done after square free factoring.
zz := (x-1)**2*zz; roots zz;
%{X=1,X=1,
% X=0.848444,X=-0.424222 + 0.734774*I,X=-0.424222 - 0.734774*I,
% X=0.152522 - 0.816316*I,X=-0.783212 + 0.276071*I,
% X=0.63069 + 0.540246*I,
% X=0.152522 + 0.816316*I,X=-0.783212 - 0.276071*I,
% X=0.63069 - 0.540246*I,
% X=1.70906,X=-0.85453 + 1.48009*I,X=-0.85453 - 1.48009*I}

off powergcd; roots zz; on powergcd;
%{X=1,X=1,
% X=0.848444,X=-0.424222 + 0.734774*I,X=-0.424222 - 0.734774*I,
% X=1.70906,X=-0.783212 + 0.276071*I,X=-0.783212 - 0.276071*I,
% X=0.152522 + 0.816316*I,X=0.152522 - 0.816316*I,
% X=0.63069 + 0.540246*I,X=0.63069 - 0.540246*I,
% X=-0.85453 + 1.48009*I,X=-0.85453 - 1.48009*I}

% 89) powergcd done after separation into real and complex polynomial.
zz := x**5-i*x**4+x**3-i*x**2+x-i; roots zz;
%{X=0.5 + 0.866025*I,X=-0.5 - 0.866025*I,
% X=-0.5 + 0.866025*I,X=0.5 - 0.866025*I,X=I}

off powergcd; roots zz; on powergcd;
%{X=-0.5 + 0.866025*I,X=-0.5 - 0.866025*I,
% X=0.5 + 0.866025*I,X=0.5 - 0.866025*I,X=I}

% Cases where root separation requires accuracy and/or precision
% increase.  In some examples we get excess accuracy, but it is hard
% avoid this and still get all roots separated.

% 90) accuracy increase required to separate close roots;
let x=y**2;
zz:= (x-3)*(100000000x-300000001); roots zz;
%{Y=1.732050808,Y= - 1.732050808,Y=1.73205081,Y= - 1.73205081}

off powergcd; roots zz; on powergcd;
%{Y=1.732050808,Y= - 1.732050808,Y= - 1.73205081,Y=1.73205081}

% 91) roots to be separated are on different square free factors.
zz:= (x-3)**2*(10000000x-30000001); roots zz;
%{Y=1.73205081 ,Y=1.73205081 ,Y= - 1.73205081 ,Y= - 1.73205081 ,
% Y=1.73205084 ,Y= - 1.73205084}

off powergcd; roots zz; on powergcd;
%{Y=1.73205081 ,Y=1.73205081 ,Y= - 1.73205081,Y= - 1.73205081,
% Y=1.73205084 ,Y= - 1.73205084}

% 92) roots must be separated in the complex polynomial factor only.
zz :=(y+1)*(x+10**8i)*(x+10**8i+1); roots zz;
%{Y=-1,
% Y=-7071.067812 + 7071.067812*I,Y=7071.067812 - 7071.067812*I,
% Y=-7071.067777 + 7071.067847*I,Y=7071.067777 - 7071.067847*I}

% 93)
zz := (x-2)**2*(1000000x-2000001)*(y-1); roots zz;
%{Y=1.4142136,Y=1.4142136,Y= - 1.4142136,Y= - 1.4142136,
% Y=1,Y=1.4142139,Y= - 1.4142139}

% 94)
zz := (x-2)*(10000000x-20000001); roots zz;
%{Y=1.41421356 ,Y= - 1.41421356 ,Y=1.4142136,Y= - 1.4142136}

% 95)
zz := (x-3)*(10000000x-30000001); roots zz;
%{Y=1.73205081 ,Y= - 1.73205081 ,Y=1.73205084 ,Y= - 1.73205084}

% 96)
zz := (x-9)**2*(1000000x-9000001); roots zz;
%{Y=3.0,Y=3.0,Y= - 3.0,Y= - 3.0,Y=3.00000017,Y= - 3.00000017}

% 97)
zz := (x-3)**2*(1000000x-3000001); roots zz;
%{Y=1.7320508,Y=1.7320508,Y= - 1.7320508,Y= - 1.7320508,
% Y=1.7320511,Y= - 1.7320511}

% 98) the accuracy of the root -sqrt 3 depends upon another close root.
on rounded;
zz := (x-3)*(y+1.732058); roots zz;
%{Y= - 1.732051,Y=1.73205,Y= - 1.732058}

zz := (x-3)*(y+1.732051); roots zz;
%{Y= - 1.73205081,Y=1.73205,Y= - 1.732051}

zz := (x-3)*(y+1.73205081); roots zz;
%{Y= - 1.732050808,Y=1.73205,Y= - 1.73205081}

% 99) minimum accuracy specified using rootacc.
rootacc 10; roots zz;
%{Y= - 1.732050808,Y=1.732050808,Y= - 1.73205081}

% 100)
off rounded; rootacc 6;
zz := (y-i)*(x-2)*(1000000x-2000001); roots zz;
%{Y=1.4142136,Y= - 1.4142136,Y=1.4142139,Y= - 1.4142139,Y=I}

% 101) this example requires accuracy 15.
zz:= (y-2)*(100000000000000y-200000000000001); roots zz;
%{Y=2.0,Y=2.00000000000001}

% 102) still higher precision needed.
zz:= (y-2)*(10000000000000000000y-20000000000000000001); roots zz;
%{Y=2.000 00000 00000 00000 1,Y=2.0}

% 103) increase in precision required for substituted polynomial.
zz:= (x-2)*(10000000000x-20000000001); roots zz;
%{Y=1.41421356241,Y= - 1.41421356241,Y=1.41421356237,
% Y= - 1.41421356237}

% 104) still higher precision required for substituted polynomial.
zz:= (x-2)*(100000000000000x-200000000000001); roots zz;
%{Y=1.414 21356 23730 99,Y= - 1.414 21356 23730 99,
% Y=1.414 21356 23730 95,Y= - 1.414 21356 23730 95}

% 105) accuracy must be increased to separate root of complex factor
% from root of real factor.
zz:=(9y-10)*(y-2)*(9y-10-9i/100000000); roots zz;
%{Y=1.111111111,Y=2.0,Y=1.111111111 + 0.00000001*I}

% 106) realroots does the same accuracy increase for real root based
% upon the presence of a close complex root in the same polynomial.
% The reason for this might not be obvious unless roots is called.
realroots zz;
%{Y=1.111111111,Y=2.0}

% 107) realroots now uses powergcd logic whenever it is applicable.
zz := (x-1)*(x-2)*(x-3);  realroots zz;
%{Y=-1,Y=1,Y= - 1.41421,Y=1.41421,Y= - 1.73205,Y=1.73205}

realroots(zz,exclude 1,2);
%{Y=1.41421,Y=1.73205}

% 108) root of degree 1 polynomial factor must be evaluated at
% precision 18 and accuracy 10 in order to separate it from a root of
% another real factor.
clear x; zz:=(9x-10)**2*(9x-10-9/100000000)*(x-2); roots zz;
%{X=1.111111111,X=1.111111111,X=1.111111121,X=2.0}

nearestroot(zz,1);
%{X=1.111111111}

nearestroot(zz,1.5);
%{X=1.111111121}

nearestroot(zz,1.65);
%{X=2.0}

% 109) in this example, precision >=40 is used and two roots need to be
% found to accuracy 16 and two to accuracy 14.
zz := (9x-10)*(7x-8)*(9x-10-9/10**12)*(7x-8-7/10**14);
roots zz;
%{X=1.1111111111121,X=1.142 85714 28571 43,
% X=1.1111111111111,X=1.142 85714 28571 53}

% 110) very small real or imaginary parts of roots require high
% precision or exact computations, or they will be lost or incorrectly
% found.
zz := 1000000*R**18   + 250000000000*R**4  - 1000000*R**2  + 1;
roots zz;
%{R=0.00141421 + 1.6E-26*I,R=-0.00141421 - 1.6E-26*I,
% R=0.00141421 - 1.6E-26*I,R=-0.00141421 + 1.6E-26*I,
% R=2.36886 + 0.54068*I,R=-2.36886 - 0.54068*I,
% R=-2.36886 + 0.54068*I,R=2.36886 - 0.54068*I,
% R=1.05424 + 2.18916*I,R=-1.05424 - 2.18916*I,
% R=-1.05424 + 2.18916*I,R=1.05424 - 2.18916*I,
% R=2.42978*I,R=-2.42978*I,
% R=1.89968 + 1.51494*I,R=-1.89968 - 1.51494*I,
% R=-1.89968 + 1.51494*I,R=1.89968 - 1.51494*I}

showtime;

end;


