%
%  More Tests for REDUCE Special Functions Package
%
%  Winfried Neun, ZIB Berlin, February 1993
%

load_package specfn;

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     1. Binomial Coefficients and Stirling numbers
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Binomial (2,1/2);

on rounded;
Binomial (2.1,2);
off rounded;

Binomial (n,2);

1/Binomial (49,6); % for those who play Lotto in Germany.

Stirling1(10,5);

Stirling2(10,5);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     2. Bernoulli Polynomials
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

BernoulliP (4,x);

BernoulliP (4,1/2);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     4. Laguerre Polynomials
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

LaguerreP(3,x);

LaguerreP(2,1,x);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     5. Legendre and Jacobi Polynomials
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

LegendreP (2,x);

LegendreP (3,x);

LegendreP (6,3,x);

JacobiP (2,1,3/4,x);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     6. Chebychev Polynomials
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

ChebyshevT(2,x);

ChebyshevT(3,x);

ChebyshevU(2,x);

ChebyshevU(3,x);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     7. Hermite Polynomials
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

HermiteP (2,x);

HermiteP (3,x);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     8. Gegenbauer Polynomials
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

GegenbauerP(2,5,x);

GegenbauerP(3,2,x);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%     9. Some well-known Infinite Sums
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

off exp;

sum(1/m^4,m,1,infinity);

sum((-1)^m/m^4,m,1,infinity);

sum(1/(2*m-1)^4,m,1,infinity);

sum((-1)^m/(2*m-1)^3,m,1,infinity);

on exp;

sum((-1)^m/(2*m-1)^2,m,1,infinity);


% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%    10. Euler Numbers and Polynomials
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Euler(6);

EulerP(4,x);

EulerP(4,1/2); 

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%    11. Integral Functions
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

on rounded;

Shi(3.4);

Si(3.4);

Chi(3.4);

Ci(3.4);

Ei(Pi);

erfc(2.0);

Fresnel_C(3.1);

Fresnel_S(3.1);

off rounded;

df(Si(z),z);
 
limit(Si(x),x,infinity);

limit(Fresnel_S(x),x,infinity);

s_i(x);

defint(cos(t)/t,t,X,INFINITY);

% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
%    12. Misc Functions
% =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


defint(log(t)/(1-t),t,1,x);

on rounded;

dilog(3.1);

off rounded;
end;



