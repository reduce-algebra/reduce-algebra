% Test of Complex Number mode in REDUCE.

on complex;

(31+i)/74;

ws/(b+1);  % this now comes out right!

w:=(x+3*i)**2;

on gcd;

(x**3-7*x**2+x-7)/(x**2+(3+i)*x+3*i);

off gcd;

sqrt(x**4+14*i*x**3-51*x**2-14*i*x+1);

on rounded;

(3.25 + 8.5i) + (6.75 - 8.5i);

(3.25 + 8.5i) - (6.0 - 9.5i);

(1.0 + 10.0*i)*(-6.5 + 2.5*i);

(1.2 - 3.4*i)*(-5.6 + 7.8*i);

(19.8 + 28.4*i)/(-5.6 + 7.8*i);

e;

pi;

17*i**2;

(-7.0 + 24.0*i)**(1/2);

sqrt(-7.0 + 24.0*i);

sqrt(-10.12 - 8.16*i);

sin(0.0 + 0.0*i);

sin(1.0 + 0.0*i);

sin(1.0 + 1.0*i);

cos(0.0 + 0.0*i);

cos(1.0 - 0.0*i);

cos(1.0 + 1.0*i);

tan(0.0 + 0.0*i);

tan(1.0 + 0.0*i);

tan(1.0 + 1.0*i);

asin(1.0 + 1.0*i);

acos(1.0 + 1.0*i);

atan(1.0 + 1.0*i);

log(1.0 + 1.0*i);

asin 2;

sin ws;

acos 2;

cos ws;

atan(1+i);

tan ws;

log(2+i);

exp ws;

e**(i*pi);

e**i;

z := sqrt i;

z**2;

off rounded;

% on rationalize;  % no longer needed, since it doesn't affect complex.

s:= 1.1+2.3i;

s/4;  % this would have had a common factor of 4.

x:= a+1.1+2.3i;

y:= b+1.2+1.3i;

z:= x/y;

z/4;  % this would have had a common polynomial factor b^2 + ...

z*7/4;

s/(c^2+c+1);  % this would have had a common factor of c^2+c+1

clear x;

zz:= x^2+(1.1+2.3i)*x+1.2+1.3i;

ss:=1.23456789x^2+1.3579i*x+5.6789;

% off rationalize;  % not needed now.

z:= x+1.1+2.3i;

on rationalize;

z;               % same as previous answer.

off rationalize;

1.23456789x^2+2.3456i*x+7.89;

on factor;

x**2+1;

x**4-1;

x**4+(i+2)*x**3+(2*i+5)*x**2+(2*i+6)*x+6;

(2*i+3)*x**4+(3*i-2)*x**3-2*(i+1)*x**2+i*x-1;

% Multivariate examples:

x**2+y**2;

off factor;

factorize(x**2+1);

end;

