% Tests of the root finding package.

% Author: Stanley L. Kameny (stan%valley.uucp@rand.org)

comment  This test file works only with Reduce version 3.5 and later
  and contains examples all of which are solved by roots mod 1.94.
  Answers are rounded to the value given by rootacc (default = 6)
  unless higher accuracy is needed to separate roots.  Format may differ 
  from that given here, but root order and values should agree exactly.
  (Although the function ROOTS may obtain the roots in a diffferent 
  order, they are sorted into a standard order in mod 1.94.)
         In the following, problems 20) and 82) are time consuming and
  have been commented out to speed up the test.
         The hard examples 111) through 115) almost double the test time
  but are necessary to test some logical paths.
         A new "hardest" example has been added as example 116).  It is
  commented out, since it is time consuming, but it is solved by roots
  mod 1.94.  The time needed to run the three commented-out examples is
  almost exactly equal to the time for the rest of the test.  Users of
  fast computers can uncomment the lines marked with %**%.  The three
  examples by themselves are contained in the test file rootsxtr.tst.

         When answers are produced which require precision increase for
  printing out or input of roots, roots functions cause precision
  increase to occur.  If the precision is already higher than the 
  default value, a message is printed out warning of the the precision 
  normally needed for input of those values.$

roots x;   % To load roots package.

write "This is Roots Package test ", symbolic roots!-mod$


% Simple root finding.

showtime;

% 1) multiple real and imaginary roots plus two real roots.
zz:= (x-3)**2*(100x**2+113)**2*(1000000x-10000111)*(x-1); roots zz;
%{x=1.06301*i,x=1.06301*i,x=-1.06301*i,x=-1.06301*i,
%x=3.0,x=3.0,x=1,x=10.0001} (rootacc caused rounding to 6 places)

% Accuracy is increased whenever necessary to separate distinct roots.

% 2) accuracy increase to 7 required for two roots.
zz:=(x**2+1)*(x-2)*(1000000x-2000001); roots zz;
%{x=i,x= -i,x=2.0,x=2.000001}

% 3) accuracy increase to 8 required.
zz:= (x-3)*(10000000x-30000001); roots zz;
%{x=3.0,x=3.0000001}

% 4) accuracy increase required here to separate repeated root from
% simple root.
zz := (x-3)*(1000000x-3000001)*(x-3)*(1000000x-3241234); roots zz;
%{x=3.0,x=3.0,x=3.000001,x=3.24123}

% other simple examples

% 5) five real roots with widely different spacing.
zz:= (x-1)*(10x-11)*(x-1000)*(x-1001)*(x-100000); roots zz;
%{x=1,x=1.1,x=1000.0,x=1001.0,x=1.0E+5}

% 6) a cluster of 5 roots in complex plane in vicinity of x=1.
zz:= (x-1)*(10000x**2-20000x+10001)*(10000x**2-20000x+9999); roots zz;
%{x=0.99,x=1,x=1 + 0.01*i,x=1 - 0.01*i,x=1.01}

% 7) four closely spaced real roots.
zz := (x-1)*(100x-101)*(100x-102)*(100x-103); roots zz;
%{x=1,x=1.01,x=1.02,x=1.03}

% 8) five closely spaced roots, 3 real + 1 complex pair.
zz := (x-1)*(100x-101)*(100x-102)*(100x**2-200x+101); roots zz;
%{x=1,x=1 + 0.1*i,x=1 - 0.1*i,x=1.01,x=1.02}

% 9) symmetric cluster of 5 roots, 3 real + 1 complex pair.
zz := (x-2)*(10000x**2-40000x+40001)*(10000x**2-40000x+39999); roots zz;
%{x=1.99,x=2.0,x=2.0 + 0.01*i,x=2.0 - 0.01*i,x=2.01}

% 10) closely spaced real and complex pair.
ss:= (x-2)*(100000000x**2-400000000x+400000001); roots ss;
%{x=2.0,x=2.0 + 0.0001*i,x=2.0 - 0.0001*i}

% 11) Zero roots and multiple roots cause no problem.
% Multiple roots are shown when the switch multiroot is on
%(normally on.)
zz:= x*(x-1)**2*(x-4)**3*(x**2+1); roots zz;
%{x=0,x=4.0,x=4.0,x=4.0,x=1,x=1,x=i,x= - i}

% 12) nearestroot will find a single root "near" a value, real or
% complex.
nearestroot(zz,2i);
%{x=i}

% More difficult examples.

% Three examples in which root scaling is needed in the complex
% iteration process.

% 13) nine roots, 3 real and 3 complex pairs.
zz:= x**9-45x-2; roots zz;
%{x= - 1.60371,x=-1.13237 + 1.13805*i,x=-1.13237 - 1.13805*i,
% x= - 0.0444444,x=0.00555357 + 1.60944*i,x=0.00555357 - 1.60944*i,
% x=1.14348 + 1.13804*i,x=1.14348 - 1.13804*i,x=1.61483}


comment  In the next two examples, there are complex roots with
  extremely  small real parts (new capability in Mod 1.91.);

% 14) nine roots, 1 real and 4 complex pairs.
zz:= x**9-9999x**2-0.01; roots zz;
%{x=-3.3584 + 1.61732*i,x=-3.3584 - 1.61732*i,
% x=-0.829456 + 3.63408*i,x=-0.829456 - 3.63408*i,
% x=5.0025E-29 + 0.00100005*i,x=5.0025E-29 - 0.00100005*i,
% x=2.32408 + 2.91431*i,x=2.32408 - 2.91431*i,x=3.72754}

comment  Rootacc 7 produces 7 place accuracy.  Answers will print in
  bigfloat format if floating point print >6 digits is not implemented.;

% 15) nine roots, 1 real and 4 complex pairs.
rootacc 7; zz:= x**9-500x**2-0.001; roots zz;
%{x=-2.189157 + 1.054242*i,x=-2.189157 - 1.054242*i,
% x=-0.5406772 + 2.368861*i,x=-0.5406772 - 2.368861*i,
% x=1.6E-26 + 0.001414214*i,x=1.6E-26 - 0.001414214*i,
% x=1.514944 + 1.899679*i,x=1.514944 - 1.899679*i,x=2.429781}

% the famous Wilkinson "ill-conditioned" polynomial and its family.

% 16) W(6) four real roots plus one complex pair.
zz:= 10000*(for j:=1:6 product(x+j))+27x**5; roots zz;
%{x= - 6.143833,x=-4.452438 + 0.02123455*i,x=-4.452438 - 0.02123455*i,
% x= - 2.950367,x= - 2.003647,x= - 0.9999775}

% 17) W(8) 4 real roots plus 2 complex pairs.
zz:= 1000*(for j:=1:8 product(x+j))+2x**7; roots zz;
%{x= - 8.437546,x=-6.494828 + 1.015417*i,x=-6.494828 - 1.015417*i,
% x=-4.295858 + 0.2815097*i,x=-4.295858 - 0.2815097*i,
% x= - 2.982725,x= - 2.000356,x= - 0.9999996}

% 18) W(10) 6 real roots plus 2 complex pairs.
zz:=1000*(for j:= 1:10 product (x+j))+x**9; roots zz;
%{x= - 10.80988,x=-8.70405 + 1.691061*i,x=-8.70405 - 1.691061*i,
% x=-6.046279 + 1.134321*i,x=-6.046279 - 1.134321*i,x= - 4.616444,
% x= - 4.075943,x= - 2.998063,x= - 2.000013,x= - 1}

% 19) W(12) 6 real roots plus 3 complex pairs.
zz:= 10000*(for j:=1:12 product(x+j))+4x**11; roots zz;
%{x= - 13.1895,x=-11.02192 + 2.23956*i,x=-11.02192 - 2.23956*i,
% x=-7.953917 + 1.948001*i,x=-7.953917 - 1.948001*i,
% x=-5.985629 + 0.8094247*i,x=-5.985629 - 0.8094247*i,
% x= - 4.880956,x= - 4.007117,x= - 2.999902,x= - 2.0,x= - 1}

% 20) W(20) 10 real roots plus 5 complex pairs. (The original problem)
% This example is commented out, since it takes significant time without
% being particularly difficult or checking out new paths:
%**%  zz:= x**19+10**7*for j:=1:20 product (x+j); roots zz;
%{x= - 20.78881,x=-19.45964 + 1.874357*i,x=-19.45964 - 1.874357*i,
% x=-16.72504 + 2.731577*i,x=-16.72504 - 2.731577*i,
% x=-14.01105 + 2.449466*i,x=-14.01105 - 2.449466*i,
% x=-11.82101 + 1.598621*i,x=-11.82101 - 1.598621*i,
% x=-10.12155 + 0.6012977*i,x=-10.12155 - 0.6012977*i,
% x= - 8.928803,x= - 8.006075,x= - 6.999746,x= - 6.000006,
% x= - 5.0,x= - 4.0,x= - 3.0,x= - 2.0,x= - 1}

rootacc 6;
% 21)  Finding one of a cluster of 8 roots.
zz:= (10**16*(x-1)**8-1); nearestroot(zz,2);
%{x=1.01}

% 22)  Six real roots spaced 0.01 apart.
c := 100; zz:= (x-1)*for i:=1:5 product (c*x-(c+i)); roots zz;
%{x=1,x=1.01,x=1.02,x=1.03,x=1.04,x=1.05}

% 23)  Six real roots spaced 0.001 apart.
c := 1000; zz:= (x-1)*for i:=1:5 product (c*x-(c+i)); roots zz;
%{x=1,x=1.001,x=1.002,x=1.003,x=1.004,x=1.005}

% 24)  Five real roots spaced 0.0001 apart.
c := 10000; zz:= (x-1)*for i:=1:4 product (c*x-(c+i)); roots zz;
%{x=1,x=1.0001,x=1.0002,x=1.0003,x=1.0004}

% 25)  A cluster of 9 roots, 5 real, 2 complex pairs; spacing 0.1.
zz:= (x-1)*(10**8*(x-1)**8-1); roots zz;
%{x=0.9,x=0.929289 + 0.0707107*i,x=0.929289 - 0.0707107*i,
% x=1,x=1 + 0.1*i,x=1 - 0.1*i,
% x=1.07071 + 0.0707107*i,x=1.07071 - 0.0707107*i,x=1.1}

% 26)  Same, but with spacing 0.01.
zz:= (x-1)*(10**16*(x-1)**8-1); roots zz;
%{x=0.99,x=0.992929 + 0.00707107*i,x=0.992929 - 0.00707107*i,
% x=1,x=1 + 0.01*i,x=1 - 0.01*i,
% x=1.00707 + 0.00707107*i,x=1.00707 - 0.00707107*i,x=1.01}

% 27)  Spacing reduced to 0.001.
zz:= (x-1)*(10**24*(x-1)**8-1); roots zz;
%{x=0.999,x=0.999293 + 0.000707107*i,x=0.999293 - 0.000707107*i,
% x=1,x=1 + 0.001*i,x=1 - 0.001*i,
% x=1.00071 + 0.000707107*i,x=1.00071 - 0.000707107*i,x=1.001}

% 28)  Eight roots divided into two clusters.
zz:= (10**8*(x-1)**4-1)*(10**8*(x+1)**4-1); roots zz;
%{x= - 0.99,x=0.99, x=-1 - 0.01*i,x=1 + 0.01*i,
% x=-1 + 0.01*i,x=1 - 0.01*i,x= - 1.01,x=1.01}

% 29)  A cluster of 8 roots in a different configuration.
zz:= (10**8*(x-1)**4-1)*(10**8*(100x-102)**4-1); roots zz;
%{x=0.99,x=1 + 0.01*i,x=1 - 0.01*i,x=1.01,
% x=1.0199,x=1.02 + 0.0001*i,x=1.02 - 0.0001*i,x=1.0201}

% 30)  A cluster of 8 complex roots.
zz:= ((10x-1)**4+1)*((10x+1)**4+1); roots zz;
%{x=-0.0292893 - 0.0707107*i,x=0.0292893 + 0.0707107*i,
% x=-0.0292893 + 0.0707107*i,x=0.0292893 - 0.0707107*i,
% x=-0.170711 - 0.0707107*i,x=0.170711 + 0.0707107*i,
% x=-0.170711 + 0.0707107*i,x=0.170711 - 0.0707107*i}

comment  In these examples, accuracy increase is required to separate a
  repeated root from a simple root.;

% 31)  Using allroots;
zz:= (x-4)*(x-3)**2*(1000000x-3000001); roots zz;
%{x=3.0,x=3.0,x=3.000001,x=4.0}

% 32)  Using realroots;
realroots zz;
%{x=3.0,x=3.0,x=3.000001,x=4.0}

comment  Tests of new capabilities in mod 1.87 for handling complex
  polynomials and polynomials with very small imaginary parts or very
  small real roots. A few real examples are shown, just to demonstrate
  that these still work.;

% 33) A trivial complex case (but degrees 1 and 2 are special cases);
zz:= x-i; roots zz;
%{x=i}

% 34) Real case.
zz:= y-7; roots zz;
%{y=7.0}

% 35) Roots with small imaginary parts (new capability);
zz := 10**16*(x**2-2x+1)+1; roots zz;
%{x=1 + 0.00000001*i,x=1 - 0.00000001*i}

% 36) One real, one complex root.
zz:=(x-9)*(x-5i-7); roots zz;
%{x=9.0,x=7.0 + 5.0*i}

% 37) Three real roots.
zz:= (x-1)*(x-2)*(x-3); roots zz;
%{x=1,x=2.0,x=3.0}

% 38) 2 real + 1 imaginary root.
zz:=(x**2-8)*(x-5i); roots zz;
%{x= - 2.82843,x=2.82843,x=5.0*i}

% 39) 2 complex roots.
zz:= (x-1-2i)*(x+2+3i); roots zz;
%{x=-2.0 - 3.0*i,x=1 + 2.0*i}

% 40) 2 irrational complex roots.
zz:= x**2+(3+2i)*x+7i; roots zz;
%{x=-3.14936 + 0.21259*i,x=0.149358 - 2.21259*i}

% 41) 2 complex roots of very different magnitudes with small imaginary
% parts.
zz:= x**2+(1000000000+12i)*x-1000000000; roots zz;
%{x=-1.0E+9 - 12.0*i,x=1 - 0.000000012*i}

% 42) Multiple real and complex roots cause no difficulty, provided
% that input is given in integer or rational form, (or if in decimal
% fraction format, with switch rounded off  or adjprec on and
% coefficients input explicitly,) so that polynomial is stored exactly.
zz :=(x**2-2i*x+5)**3*(x-2i)*(x-11/10)**2; roots zz;
%{x=-1.44949*i, x=-1.44949*i, x=-1.44949*i,
% x=3.44949*i, x=3.44949*i, x=3.44949*i, x=1.1, x=1.1, x=2.0*i}

% 42a) would have failed in roots Mod 1.93 and previously (bug)
realroots zz;
%{x=1.1,x=1.1}

% 43) 2 real, 2 complex roots.
zz:= (x**2-4)*(x**2+3i*x+5i); roots zz;
%{x= - 2.0,x=2.0,x=-1.2714 + 0.466333*i,x=1.2714 - 3.46633*i}

% 44) 4 complex roots.
zz:= x**4+(0.000001i)*x-16; roots zz;
%{x=-2.0 - 0.0000000625*i,x=-2.0*i,x=2.0*i,x=2.0 - 0.0000000625*i}

% 45) 2 real, 2 complex roots.
zz:= (x**2-4)*(x**2+2i*x+8); roots zz;
%{x= - 2.0,x=2.0,x=-4.0*i,x=2.0*i}

% 46) Using realroots to find only real roots.
realroots zz;
%{x= - 2.0,x=2.0}

% 47) Same example, applying nearestroot to find a single root.
zz:= (x**2-4)*(x**2+2i*x+8); nearestroot(zz,1);
%{x=2.0}

% 48) Same example, but focusing on imaginary point.
nearestroot(zz,i);
%{x=2.0*i}

% 49) The seed parameter can be complex also.
nearestroot(zz,1+i);
%{x=2.0*i}

% 50) One more nearestroot example.  Nearest root to real point may be
% complex.
zz:= (x**2-4)*(x**2-i); roots zz;
%{x= - 2.0,x=2.0,x=-0.707107 - 0.707107*i,x=0.707107 + 0.707107*i}

nearestroot (zz,1);
%{X=0.707107 + 0.707107*i}

% 51) 1 real root plus 5 complex roots.
zz:=(x**3-3i*x**2-5x+9)*(x**3-8); roots zz;
%{x=-1 + 1.73205*i,x=-1 - 1.73205*i,x=2.0,
% x=-2.41613 + 1.19385*i,x=0.981383 - 0.646597*i,x=1.43475 + 2.45274*i}

nearestroot(zz,1);
%{x=0.981383 - 0.646597*i}

% 52) roots can be computed to any accuracy desired, eg.  (note that the
% imaginary part of the second root is truncated because of its size,
% and that the imaginary part of a complex root is never polished away,
% even if it is smaller than the accuracy would require.)
zz := x**3+10**(-20)*i*x**2+8; rootacc 12; roots zz; rootacc 6;
%{x=-2.0 - 3.33333333333E-21*i,x=1 - 1.73205080757*i,
% x=1 + 1.73205080757*i}

% 53) Precision of 12 required to find small imaginary root,
% but standard accuracy can be used.
zz := x**2+123456789i*x+1; roots zz;
%{x=-1.23457E+8*i,x=0.0000000081*i}

% 54) Small real root is found with root 10*18 times larger(new).
zz := (x+1)*(x**2+123456789*x+1); roots zz;
%{x= - 1.23457E+8,x= - 1,x= - 0.0000000081}

% 55) 2 complex, 3 real irrational roots.
ss := (45*x**2+(-10i+12)*x-10i)*(x**3-5x**2+1); roots ss;
%{x= - 0.429174,x=0.469832,x=4.95934,
% x=-0.448056 - 0.19486*i,x=0.18139 + 0.417083*i}

% 56) Complex polynomial with floating coefficients.
zz := x**2+1.2i*x+2.3i+6.7; roots zz;
%{x=-0.427317 + 2.09121*i,x=0.427317 - 3.29121*i}

% 56a) multiple roots will be found if coefficients read in exactly.
% Exact read-in will occur unless dmode is rounded or complex-rounded.
zz := x**3 + (1.09 - 2.4*i)*x**2 + (-1.44 - 2.616*i)*x + -1.5696;
roots zz;
%{x=1.2*i,x=1.2*i,x= - 1.09}

% 57) Realroots, isolater and rlrootno accept 1, 2 or 3 arguments: (new)
zz:= for j:=-1:3 product (x-j); rlrootno zz;
% 5

realroots zz;
%{x=0,x= -1,x=1,x=2.0,x=3.0}

rlrootno(zz,positive); %positive selects positive, excluding 0.
% 3

rlrootno(zz,negative); %negative selects negative, excluding 0.
% 1

realroots(zz,positive);
%{x=1,x=2.0,x=3.0}

rlrootno(zz,-1.5,2); %the format with 3 arguments selects a range.
% 4

realroots(zz,-1.5,2); %the range is inclusive, except that:
%{x=0,x= - 1,x=1,x=2.0}

% A specific limit b may be excluded by using   exclude b.  Also, the
% limits infinity and -infinity can be specified.

realroots(zz,exclude 0,infinity);
% equivalent to realroots(zz,positive).
%{x=1,x=2.0,x=3.0}

rlrootno(zz,-infinity,exclude 0); % equivalent to rlrootno(zz,negative).
% 1

rlrootno(zz,-infinity,0);
% 2

rlrootno(zz,infinity,-infinity);
%equivalent to rlrootno zz; (order of limits does not matter.)
% 5

realroots(zz,1,infinity); % finds all real roots >= 1.
%{x=1,x=2.0,x=3.0}

realroots(zz,1,positive); % finds all real roots > 1.
%{x=2.0,x=3.0}

% 57a) Bug corrected in mod 1.94.  (handling of rational limits)
zz := (x-1/3)*(x-1/5)*(x-1/7)*(x-1/11);
realroots(zz,1/11,exclude(1/3));
%{x=0.0909091,x=0.142857,x=0.2}

realroots(zz,exclude(1/11),1/3);
%{x=0.142857,x=0.2,x=0.333333}

% New capabilities added in mod 1.88.

% 58) 3 complex roots, with two separated by very small real difference.
zz :=(x+i)*(x+10**8i)*(x+10**8i+1); roots zz;
%{x=-1 - 1.0E+8*i,x=-1.0E+8*i,x= - i}

% 59) Real polynomial with two complex roots separated by very small
% imaginary part.
zz:= (10**14x+123456789000000+i)*(10**14x+123456789000000-i); roots zz;
%{x=-1.23457 + 1.0E-14*i,x=-1.23457 - 1.0E-14*i}

% 60) Real polynomial with two roots extremely close together.
zz:= (x+2)*(10**10x+12345678901)*(10**10x+12345678900); roots zz;
%{x= - 2.0,x= - 1.2345678901,x= - 1.23456789}

% 61) Real polynomial with multiple root extremely close to simple root.
zz:= (x-12345678/10000000)*(x-12345679/10000000)**2; roots zz;
%{x=1.2345679,x=1.2345679,x=1.2345678}

% 62) Similar problem using realroots.
zz:=(x-2**30/10**8)**2*(x-(2**30+1)/10**8); realroots zz;
%{x=10.73741824,x=10.73741824,x=10.73741825}

% 63) Three complex roots with small real separation between two.
zz:= (x-i)*(x-1-10**8i)*(x-2-10**8i); roots zz;
%{x=i,x=1 + 1.0E+8*i,x=2.0 + 1.0E+8*i}

% 64) Use of nearestroot to isolate one of the close roots.
nearestroot(zz,10**8i+99/100);
%{x=1 + 1.0E+8*i}

% 65) Slightly more complicated example with close complex roots.
zz:= (x-i)*(10**8x-1234-10**12i)*(10**8x-1233-10**12i); roots zz;
%{x=i,x=0.00001233 + 10000.0*i,x=0.00001234 + 10000.0*i}

% 66) Four closely spaced real roots with varying spacings.
zz:= (x-1+1/10**7)*(x-1+1/10**8)*(x-1)*(x-1-1/10**7); roots zz;
%{x=0.9999999,x=0.99999999,x=1,x=1.0000001}

% 67) Complex pair plus two close real roots.
zz:= (x**2+1)*(x-12345678/10000000)*(x-12345679/10000000); roots zz;
%{x=i,x= - i,x=1.2345678,x=1.2345679}

% 68) Same problem using realroots to find only real roots.
realroots zz;
%{x=1.2345678,x=1.2345679}

% The switch ratroot causes output to be given in rational form.
% 69) Two complex roots with output in rational form.
on ratroot,complex; zz:=x**2-(5i+1)*x+1; sss:= roots zz; 

%           346859 - 1863580*i     482657 + 2593180*i
%sss := {x=--------------------,x=--------------------}
%                10000000                500000

% With roots in rational form, mkpoly can be used to reconstruct a
% polynomial.
zz1 := mkpoly sss;

%                      2
%zz1 := 5000000000000*x  - (4999999500000 + 25000010000000*i)*x
%
%        + 5000012308763 - 2110440*i

% Finding the roots of the new polynomial zz1.
rr:= roots zz1; 

%          346859 - 1863580*i     482657 + 2593180*i
%rr := {x=--------------------,x=--------------------}
%               10000000                500000

% The roots are stable to the extent that rr=ss, although zz1 and
% zz may differ.

zz1 - zz;

%               2
%4999999999999*x  - (4999999499999 + 25000009999995*i)*x
%
% + 5000012308762 - 2110440*i

% 70) Same type of problem in which roots are found exactly.
zz:=(x-10**8+i)*(x-10**8-i)*(x-10**8+3i/2)*(x-i); rr := roots zz;

%          4                    3                      2
%zz := (2*x  - (600000000 - i)*x  + 60000000000000005*x
%
%        - (2000000000000000800000000 + 29999999999999999*i)*x
%
%        + (30000000000000003 + 2000000000000000200000000*i))/2

%rr := {x=100000000 + i,x=100000000 - i,x=i,
%
%          200000000 - 3*i
%       x=-----------------}
%                 2

% Reconstructing a polynomial from the roots.
ss := mkpoly rr;

%         4                    3                      2
%ss := 2*x  - (600000000 - i)*x  + 60000000000000005*x
%
%       - (2000000000000000800000000 + 29999999999999999*i)*x
%
%       + (30000000000000003 + 2000000000000000200000000*i)

% In this case, the same polynomial is obtained.
ss - num zz;
% 0

% 71) Finding one of the complex roots using nearestroot.
nearestroot(zz,10**8-2i); 

%    200000000 - 3*I
%{x=-----------------}
%           2

% Finding the other complex root using nearestroot.
nearestroot(zz,10**8+2i);
%{x=100000000 + I}

% 72) A realroots problem which requires accuracy increase to avoid
% confusion of two roots.
zz:=(x+1)*(10000000x-19999999)*(1000000x-2000001)*(x-2);
realroots zz; 

%          19999999         2000001
% {x=-1,x=----------,x=2,x=---------}
%          10000000         1000000

% 73) Without the accuracy increase, this example would produce the
% obviously incorrect answer 2.
realroots(zz,3/2,exclude 2); 

%     19999999
% {x=----------}
%     10000000

% Rlrootno also gives the correct answer in this case.
rlrootno(zz,3/2,exclude 2);
% 1

% 74) Roots works equally well in this problem.
rr := roots zz;
%                 19999999        2000001
%rr := {x= - 1,x=----------,x=2,x=---------}
%                 10000000        1000000

% 75) The function getroot is convenient for obtaining the value of a
% root.
rr1 := getroot(1,rr);

%         19999999
% rr1 := ----------
%         10000000

% 76) For example, the value can be used as an argument to nearestroot.
nearestroot(zz,rr1); 

%     19999999
% {x=----------}
%     10000000


comment  New capabilities added to Mod 1.90 for avoiding floating point
  exceptions and exceeding iteration limits.;

% 77) This and the next example would previously have aborted because
%of exceeding iteration limits:
off ratroot; zz := x**16 - 900x**15 -2; roots zz;
%{x= - 0.665423,x=-0.607902 + 0.270641*i,x=-0.607902 - 0.270641*i,
% x=-0.44528 + 0.494497*i, x=-0.44528 - 0.494497*i,
% x=-0.205664 + 0.632867*i,x=-0.205664 - 0.632867*i,
% x=0.069527 + 0.661817*i,x=0.069527 - 0.661817*i,
% x=0.332711 + 0.57633*i,x=0.332711 - 0.57633*i,
% x=0.538375 + 0.391176*i,x=0.538375 - 0.391176*i,
% x=0.650944 + 0.138369*i,x=0.650944 - 0.138369*i,x=900.0}

% 78) a still harder example.
zz := x**30 - 900x**29 - 2; roots zz;
%{x= - 0.810021,x=-0.791085 + 0.174125*i,x=-0.791085 - 0.174125*i,
% x=-0.735162 + 0.340111*i,x=-0.735162 - 0.340111*i,
% x=-0.644866 + 0.490195*i,x=-0.644866 - 0.490195*i,
% x=-0.524417 + 0.617362*i,x=-0.524417 - 0.617362*i,
% x=-0.379447 + 0.715665*i,x=-0.379447 - 0.715665*i,
% x=-0.216732 + 0.780507*i,x=-0.216732 - 0.780507*i,
% x=-0.04388 + 0.808856*i,x=-0.04388 - 0.808856*i,
% x=0.131027 + 0.799383*i,x=0.131027 - 0.799383*i,
% x=0.299811 + 0.752532*i,x=0.299811 - 0.752532*i,
% x=0.454578 + 0.67049*i,x=0.454578 - 0.67049*i,
% x=0.588091 + 0.557094*i,x=0.588091 - 0.557094*i,
% x=0.694106 + 0.417645*i,x=0.694106 - 0.417645*i,
% x=0.767663 + 0.258664*i,x=0.767663 - 0.258664*i,
% x=0.805322 + 0.0875868*i,x=0.805322 - 0.0875868*i,x=900.0}

% 79) this deceptively simple example previously caused floating point
% overflows on some systems:
aa := x**6 - 4*x**3 + 2; realroots aa;
%{x=0.836719,x=1.50579}

% 80) a harder problem, which would have failed on almost all systems:
rr := x**16 - 90000x**15 - x**2 -2; realroots rr;
%{x= - 0.493299,x=90000.0}

% 81) this example would have failed because of floating point
% exceptions on almost all computer systems.
rr := x**30 - 9*10**10*x**29 - 2;  realroots rr;
%{x= - 0.429188,x=9.0E+10}

% 82) a test of allroot on this example.
% This example is commented out because it takes significant time
% without breaking new ground.
%**% roots  rr;
%{x= - 0.429188,
% x=-0.419154 + 0.092263*i,x=-0.419154 - 0.092263*i,
% x=-0.389521 + 0.180211*i,x=-0.389521 - 0.180211*i,
% x=-0.341674 + 0.259734*i,x=-0.341674 - 0.259734*i,
% x=-0.277851 + 0.327111*i,x=-0.277851 - 0.327111*i,
% x=-0.201035 + 0.379193*i,x=-0.201035 - 0.379193*i,
% x=-0.11482 + 0.413544*i,x=-0.11482 - 0.413544*i,
% x=-0.0232358 + 0.428559*i,x=-0.0232358 - 0.428559*i,
% x=0.0694349 + 0.423534*i,x=0.0694349 - 0.423534*i,
% x=0.158859 + 0.398706*i,x=0.158859 - 0.398706*i,
% x=0.240855 + 0.355234*i,x=0.240855 - 0.355234*i,
% x=0.311589 + 0.295153*i,x=0.311589 - 0.295153*i,
% x=0.367753 + 0.22127*i,x=0.367753 - 0.22127*i,
% x=0.406722 + 0.13704*i,x=0.406722 - 0.13704*i,
% x=0.426672 + 0.0464034*i,x=0.426672 - 0.0464034*i,x=9.0E+10}

% 83) test of starting point for iteration: no convergence if good
% real starting point is not found.
zz := x**30 -9*10**12x**29 -2; firstroot zz;
%{x= - 0.36617}

% 84) a case in which there are no real roots and good imaginary
% starting point must be used or roots cannot be found.
zz:= 9x**16 - x**5 +1; roots zz;
%{x=-0.866594 + 0.193562*i,x=-0.866594 - 0.193562*i,
% x=-0.697397 + 0.473355*i,x=-0.697397 - 0.473355*i,
% x=-0.510014 + 0.716449*i,x=-0.510014 - 0.716449*i,
% x=-0.161318 + 0.87905*i,x=-0.161318 - 0.87905*i,
% x=0.182294 + 0.828368*i,x=0.182294 - 0.828368*i,
% x=0.459373 + 0.737443*i,x=0.459373 - 0.737443*i,
% x=0.748039 + 0.494348*i,x=0.748039 - 0.494348*i,
% x=0.845617 + 0.142879*i,x=0.845617 - 0.142879*i}

% 85) five complex roots.
zz := x**5 - x**3 + i; roots zz;
%{x=-1.16695 - 0.217853*i,x=-0.664702 + 0.636663*i,x=-0.83762*i,
% x=0.664702 + 0.636663*i,x=1.16695 - 0.217853*i}

% Additional capabilities in Mod 1.91.

% 86) handling of polynomial with huge or infinitesimal coefficients.
precision reset;
on rounded; precision reset;
% so that the system will start this example in floating point.  Rounded
% is on so that the polynomial won't fill the page!
zz:= 1.0e-500x**3+x**2+x;
roots zz; off rounded; % rounded not normally needed for roots.
%{x=0,x= - 1.0E+500,x= - 1}
off roundbf;

comment  Switch roundbf will have been turned on in the last example in
  most computer systems.  This will inhibit the use of hardware floating
  point unless roundbf is turned off.

  Polynomials which make use of powergcd substitution and cascaded
  solutions.

  Uncomplicated cases.;

switch powergcd; % introduced here to verify that same answers are
% obtained with and without employing powergcd strategy.  Roots are
% found faster for applicable cases when !*powergcd=t (default state.)

% 87) powergcd done at the top level.
zz := x**12-5x**9+1; roots zz;
%{x=-0.783212 + 0.276071*i,x=0.152522 - 0.816316*i,
% x=0.63069 + 0.540246*i,x=-0.783212 - 0.276071*i,
% x=0.152522 + 0.816316*i,x=0.63069 - 0.540246*i,
% x=-0.424222 + 0.734774*i,x=-0.424222 - 0.734774*i,x=0.848444,
% x=-0.85453 + 1.48009*i,x=-0.85453 - 1.48009*i,x=1.70906}

off powergcd; roots zz; on powergcd;
%{x=-0.85453 + 1.48009*i,x=-0.85453 - 1.48009*i,
% x=-0.783212 + 0.276071*i,x=-0.783212 - 0.276071*i,
% x=-0.424222 + 0.734774*i,x=-0.424222 - 0.734774*i,
% x=0.152522 + 0.816316*i,x=0.152522 - 0.816316*i,
% x=0.63069 + 0.540246*i,x=0.63069 - 0.540246*i,x=0.848444,x=1.70906}

% 88) powergcd done after square free factoring.
zz := (x-1)**2*zz; roots zz;
%{x=1,x=1,
% x=-0.783212 + 0.276071*i,x=0.152522 - 0.816316*i,
% x=0.63069 + 0.540246*i,x=-0.783212 - 0.276071*i,
% x=0.152522 + 0.816316*i,x=0.63069 - 0.540246*i,
% x=-0.424222 + 0.734774*i,x=-0.424222 - 0.734774*i,x=0.848444,
% x=-0.85453 + 1.48009*i,x=-0.85453 - 1.48009*i,x=1.70906}

off powergcd; roots zz; on powergcd;
%{x=1,x=1,
% x=-0.85453 + 1.48009*i,x=-0.85453 - 1.48009*i,
% x=-0.783212 + 0.276071*i,x=-0.783212 - 0.276071*i,
% x=-0.424222 + 0.734774*i,x=-0.424222 - 0.734774*i,
% x=0.152522 + 0.816316*i,x=0.152522 - 0.816316*i,
% x=0.63069 + 0.540246*i,x=0.63069 - 0.540246*i,
% x=0.848444,x=1.70906}

% 89) powergcd done after separation into real and complex polynomial.
zz := x**5-i*x**4+x**3-i*x**2+x-i; roots zz;
%{x=-0.5 - 0.866025*i,x=0.5 + 0.866025*i,
% x=-0.5 + 0.866025*i,x=0.5 - 0.866025*i,x=i}

off powergcd; roots zz; on powergcd;
%{x=-0.5 + 0.866025*i,x=-0.5 - 0.866025*i,
% x=0.5 + 0.866025*i,x=0.5 - 0.866025*i,x=i}

% Cases where root separation requires accuracy and/or precision
% increase.  In some examples we get excess accuracy, but it is hard
% avoid this and still get all roots separated.

% 90) accuracy increase required to separate close roots;
let x=y**2;
zz:= (x-3)*(100000000x-300000001); roots zz;
%{y= - 1.732050808,y=1.732050808,y= - 1.73205081,y=1.73205081}

off powergcd; roots zz;  on powergcd;
%{y= - 1.73205081,y= - 1.732050808,y=1.732050808,y=1.73205081}

% 91) roots to be separated are on different square free factors.
zz:= (x-3)**2*(10000000x-30000001); roots zz;
%{y= - 1.73205081,y= - 1.73205081,y=1.73205081,y=1.73205081,
% y= - 1.73205084,y=1.73205084}

off powergcd; roots zz;  on powergcd;
%{y= - 1.73205081,y= - 1.73205081,y=1.73205081,y=1.73205081,
% y= - 1.73205084,y=1.73205084}

% 91a) A new capability for nearestroot:
nearestroot(zz,1.800000000001); % should find the root to 13 places.
%{y=1.732050836436}

% 92) roots must be separated in the complex polynomial factor only.
zz :=(y+1)*(x+10**8i)*(x+10**8i+1); roots zz;
%{y= - 1,
% y=-7071.067777 + 7071.067847*i,y=7071.067777 - 7071.067847*i,
% y=-7071.067812 + 7071.067812*i,y=7071.067812 - 7071.067812*i}

% 93)
zz := (x-2)**2*(1000000x-2000001)*(y-1); roots zz;
%{y= - 1.4142136,y= - 1.4142136,y=1.4142136,y=1.4142136,
% y= - 1.4142139,y=1,y=1.4142139}

% 94)
zz := (x-2)*(10000000x-20000001); roots zz;
%{y= - 1.41421356 ,y=1.41421356 ,y= - 1.4142136,y=1.4142136}

% 95)
zz := (x-3)*(10000000x-30000001); roots zz;
%{y= - 1.73205081 ,y=1.73205081 ,y= - 1.73205084 ,y=1.73205084}

% 96)
zz := (x-9)**2*(1000000x-9000001); roots zz;
%{y= - 3.0,y= - 3.0,y=3.0,y=3.0,y= - 3.00000017,y=3.00000017}

% 97)
zz := (x-3)**2*(1000000x-3000001); roots zz;
%{y= - 1.7320508,y= - 1.7320508,y=1.7320508,y=1.7320508,
% y= - 1.7320511,y=1.7320511}

% 98) the accuracy of the root sqrt 5 depends upon another close root.
% Although one of the factors is given in decimal notation, it is not
% necessary to turn rounded on.
rootacc 10; % using rootacc to specify the minumum desired accuracy.
zz := (y^2-5)*(y-2.2360679775);
% in this case, adding one place to the root near sqrt 5 causes a
% required increase of 4 places in accuracy of the root at sqrt 5.
roots zz;
%{y= - 2.236067977,y=2.2360679774998,y=2.2360679775}

realroots zz; % should get the same answer from realroots.
%{y= - 2.2360679775,y=2.2360679774998,y=2.2360679775}


% 99) The same thing also happens when the root near sqrt 5 is on a
% different square-free factor.
zz := (y^2-5)^2*(y-2.2360679775);
roots zz;
%{y= - 2.236067977,y= - 2.236067977,y=2.2360679774998,
% y=2.2360679774998,y=2.2360679775}

realroots zz; % realroots handles this case also.
%{y= - 2.236067977,y= - 2.236067977,y=2.2360679774998,y=2.2360679774998,
% y=2.2360679775}

% 100)
rootacc 6;
zz := (y-i)*(x-2)*(1000000x-2000001); roots zz;
%{y= - 1.4142136,y=1.4142136,y= - 1.4142139,y=1.4142139,y=i}

% 101) this example requires accuracy 15.
zz:= (y-2)*(100000000000000y-200000000000001);
roots zz;
%{y=2.0,y=2.00000000000001}

% 102) still higher precision needed.
zz:= (y-2)*(10000000000000000000y-20000000000000000001); roots zz;
%{y=2.0,y=2.0000000000000000001}

% 103) increase in precision required for substituted polynomial.
zz:= (x-2)*(10000000000x-20000000001); roots zz;
%{y= - 1.41421356237,y=1.41421356237,y= - 1.41421356241,y=1.41421356241}

% 104) still higher precision required for substituted polynomial.
zz:= (x-2)*(100000000000000x-200000000000001); roots zz;
%{y= - 1.414213562373095,y=1.414213562373095,
% y= - 1.414213562373099,y=1.414213562373099}

% 105) accuracy must be increased to separate root of complex factor
% from root of real factor.
zz:=(9y-10)*(y-2)*(9y-10-9i/100000000); roots zz;
%{y=1.111111111,y=2.0,y=1.111111111 + 0.00000001*i}

% 106) realroots does the same accuracy increase for real root based
% upon the presence of a close complex root in the same polynomial.
% The reason for this might not be obvious unless roots is called.
realroots zz;
%{y=1.111111111,y=2.0}

% 107) realroots now uses powergcd logic whenever it is applicable.
zz := (x-1)*(x-2)*(x-3);  realroots zz;
%{y= - 1,y=1,y= - 1.41421,y=1.41421,y= - 1.73205,y=1.73205}

realroots(zz,exclude 1,2);
%{y=1.41421,y=1.73205}

% 108) root of degree 1 polynomial factor must be evaluated at
% precision 18 and accuracy 10 in order to separate it from a root of
% another real factor.
clear x; zz:=(9x-10)**2*(9x-10-9/100000000)*(x-2); roots zz;
%{x=1.111111111,x=1.111111111,x=1.111111121,x=2.0}

nearestroot(zz,1);
%{x=1.111111111}

nearestroot(zz,1.5);
%{x=1.111111121}

nearestroot(zz,1.65);
%{x=2.0}

% 108a) new cability in mod 1.94.
realroots zz;
%{x=1.111111111,x=1.111111111,x=1.111111121,x=2.0}

% 109) in this example, precision >=40 is used and two roots need to be
% found to accuracy 16 and two to accuracy 14.
zz := (9x-10)*(7x-8)*(9x-10-9/10**12)*(7x-8-7/10**14); roots zz;
%{x=1.1111111111111,x=1.1111111111121,
% x=1.142857142857143,x=1.142857142857153}

% 110) very small real or imaginary parts of roots require high
% precision or exact computations, or they will be lost or incorrectly
% found.
zz := 1000000*r**18 + 250000000000*r**4 - 1000000*r**2 + 1; roots zz;
%{r=2.42978*i,r=-2.42978*i,
% r=-1.05424 - 2.18916*i,r=1.05424 + 2.18916*i,
% r=-1.05424 + 2.18916*i,r=1.05424 - 2.18916*i,
% r=-0.00141421 - 1.6E-26*i,r=0.00141421 + 1.6E-26*i,
% r=-0.00141421 + 1.6E-26*i,r=0.00141421 - 1.6E-26*i,
% r=-1.89968 - 1.51494*i,r=1.89968 + 1.51494*i,
% r=-1.89968 + 1.51494*i,r=1.89968 - 1.51494*i,
% r=-2.36886 - 0.540677*i,r=2.36886 + 0.540677*i,
% r=-2.36886 + 0.540677*i,r=2.36886 - 0.540677*i}


comment  These five examples are very difficult root finding problems
  for automatic root finding (not employing problem-specific
  procedures.) They require extremely high precision and high accuracy
  to separate almost multiple roots (multiplicity broken by a small high
  order perturbation.)  The examples are roughly in ascending order of
  difficulty.;

% 111) Two simple complex roots with extremely small real separation.
c := 10^-6;
zz:=(x-3c^2)^2+i*c*x^7; roots zz;
%{x=-15.0732 + 4.89759*i,x=-9.31577 - 12.8221*i,x=-1.2E-12 + 15.8489*i,
% x=2.99999999999999999999999999999997E-12
%    + 3.3068111527572904325663335008527E-44*i,
% x=3.00000000000000000000000000000003E-12
%    - 3.30681115275729043256633350085321E-44*i,
% x=9.31577 - 12.8221*i,x=15.0732 + 4.89759*i}

% 112) Four simple complex roots in two close sets.
c := 10^-4;
zz:=(x^2-3c^2)^2+i*c^2*x^9; roots zz;
%{x=-37.8622 + 12.3022*i,x=-23.4002 - 32.2075*i,
% x=-0.00017320508075689 - 2.41778234660324E-18*i,
% x=-0.000173205080756885 + 2.4177823466027E-18*i,
% x=39.8107*i,
% x=0.000173205080756885 + 2.4177823466027E-18*i,
% x=0.00017320508075689 - 2.41778234660324E-18*i,
% x=23.4002 - 32.2075*i,x=37.8622 + 12.3022*i}

% 113) Same example, but with higher minimum root accuracy specified.
rootacc 20;
roots zz;
%{x=-37.862241873586290526 + 12.302188128448775345*i,
% x=-23.400152368145827118 - 32.207546656274351069*i,
% x=-0.00017320508075689014714 - 2.417782346603239319E-18*i,
% x=-0.00017320508075688531157 + 2.417782346602699319E-18*i,
% x=39.810717055651151449*i,
% x=0.00017320508075688531157 + 2.417782346602699319E-18*i,
% x=0.00017320508075689014714 - 2.417782346603239319E-18*i,
% x=23.400152368145827118 - 32.207546656274351069*i,
% x=37.862241873586290526 + 12.302188128448775345*i}

precision reset;
% This resets precision and rootacc to nominal.

% 114) Two extremely close real roots plus a complex pair with extremely
% small imaginary part.
c := 10^6;
zz:=(c^2*x^2-3)^2+c^2*x^9; roots zz;
%{x= - 251.189,x=-77.6216 + 238.895*i,x=-77.6216 - 238.895*i,
% x= - 0.000001732050807568877293531,
% x= - 0.000001732050807568877293524,
% x=0.00000173205 + 3.41926E-27*i,x=0.00000173205 - 3.41926E-27*i,
% x=203.216 + 147.645*i,x=203.216 - 147.645*i}

% 114a) this example is a critical test for realroots as well.
realroots zz;
%{x= - 251.189,x= - 0.000001732050807568877293531,
% x= - 0.000001732050807568877293524}

% 115) Four simple complex roots in two extremely close sets.
c := 10^6;
zz:=(c^2*x^2-3)^2+i*c^2*x^9; roots zz;
%{x=-238.895 + 77.6216*i,x=-147.645 - 203.216*i,
% x=-0.00000173205080756887729353 - 2.417782346602969319022E-27*i,
% x=-0.000001732050807568877293525 + 2.417782346602969318968E-27*i,
% x=251.189*i,
% x=0.000001732050807568877293525 + 2.417782346602969318968E-27*i,
% x=0.00000173205080756887729353 - 2.417782346602969319022E-27*i,
% x=147.645 - 203.216*i,x=238.895 + 77.6216*i}


% 116) A new "hardest example" type.  This polynomial has two sets of
% extremely close real roots and two sets of extremely close conjugate
% complex roots, both large and small, with the maximum accuracy and
% precision required for the largest roots.  Three restarts are
% required, at progressively higher precision, to find all roots.
 % (to run this example, uncomment the following two lines.)
%**% zz1:= (10^12x^2-sqrt 2)^2+x^7$ zz2:= (10^12x^2+sqrt 2)^2+x^7$
%**% zzzz := zz1*zz2$ roots zzzz;
%{x= - 1.00000000000000000000000000009E+8,
% x= - 9.99999999999999999999999999906E+7,
% x= - 0.0000011892071150027210667183,
% x= - 0.0000011892071150027210667167,
% x=-5.4525386633262882960501E-28 + 0.000001189207115002721066718*i,
% x=-5.4525386633262882960501E-28 - 0.000001189207115002721066718*i,
% x=5.4525386633262882960201E-28 + 0.000001189207115002721066717*i,
% x=5.4525386633262882960201E-28 - 0.000001189207115002721066717*i,
% x=0.00000118921 + 7.71105E-28*i,
% x=0.00000118921 - 7.71105E-28*i,
% x=4.99999999999999999999999999953E+7
%    + 8.66025403784438646763723170835E+7*i,
% x=4.99999999999999999999999999953E+7
%    - 8.66025403784438646763723170835E+7*i,
% x=5.00000000000000000000000000047E+7
%    + 8.66025403784438646763723170671E+7*i,
% x=5.00000000000000000000000000047E+7
%    - 8.66025403784438646763723170671E+7*i}

% Realroots strategy on this example is different, but determining the
% necessary precision and accuracy is tricky.
%**% realroots zzzz;
%{x= - 1.00000000000000000000000000009E+8,
% x= - 9.9999999999999999999999999991E+7,
% x= - 0.0000011892071150027210667183,
% x= - 0.0000011892071150027210667167}

showtime;

end;
