% out "ellipfn.rlg";

% load_package ellipfn;

% test of facilities  of elliptic functions package
% Author: Alan Barnes   (Alan.Barnes45678@gmail.com) July 2019
% Modified August 2019. Tests of theta functions moved to sftheta.tst -- 2021
% Renamed (was sfellip.tst) and moved to a new package ellipfn, December 2021
% by Alan Barnes
% Renamed ellipfn.tst and incorporated test from eftheta.tst and efweier.tst
% by Alan Barnes  January 2022

% periodic properties and quarter period shifts

jacobisn(u+2*elliptick(k),k);
jacobisn(u+2*i*elliptick!'(k),k);
jacobisn(u+elliptick(k),k);
jacobisn(u+i*elliptick!'(k),k);

jacobizeta(u+2*elliptick(k),k);
jacobie(u+14*elliptick(k),k);

% derivatives and consistency checks

df(jacobicn(u,k),u);
df(jacobisn(u,k)^2+jacobicn(u,k)^2,u);

df(jacobidn(u,k),k);
df(k^2*jacobisn(u,k)^2+jacobidn(u,k)^2,k);
% vanishes by Pythagorean identity for dn and cn

df(jacobie(u,k),u);
df(jacobie(u,k),k);

df(elliptick(k),k);
df(elliptice(k),k);

% check a well-known identity
df(elliptice(k)*elliptick!'(k)+elliptice!'(k)*elliptick(k)-elliptick(k)*elliptick!'(k),k);

df(jacobizeta(u,k),u);
df(elliptice(u,k),u);
df(elliptice(u,k),k);

% quasi-periodicity
elliptice(u+pi/2,k);
ellipticf(u-5*pi/2,k);
elliptice(u+11*pi/3,k);

% inverse Jacobian elliptic functions: special cases and derivatives

arcsn(x,0);
arcdn(x,1);
arcsn(-x,k);
arccn(-x,k);
arccs(-x,k);
arcds(-x,k);
arcsd(-x,k);
df(arccn(x,k),x);
df(arcdc(x,k),x);

jacobidn(arcdn(x^2,k),k);

% theta functions tests from former sftheta.tst
% added January 2022

% periodicity, quasi-periodicity and zeroes
elliptictheta1(z+6*pi, tau);
elliptictheta1(z+7*pi, tau);
elliptictheta2(z+7*pi/2, tau);
elliptictheta2(z+9*pi/2, tau);
elliptictheta4(z+9*pi, tau);
elliptictheta4(z+9*pi/2, tau);

elliptictheta1(6*pi+7*pi*tau, tau);
s1:=elliptictheta1(z+5*pi/2+3*pi*tau, tau);
elliptictheta2(6*pi+7*pi*tau, tau);
elliptictheta2(7/2*pi+7*pi*tau, tau);

elliptictheta4(6*pi+7/2*pi*tau, tau);
s2:=elliptictheta4(z+6*pi+7/2*pi*tau, tau);
elliptictheta3(z+6*pi+7/2*pi*tau, tau);
elliptictheta3(7*pi/2+3/2*pi*tau, tau);

elliptictheta1(-z,tau);
elliptictheta3(-z,tau);
elliptictheta3(z,tau+1);
elliptictheta1(z,tau-1);
elliptictheta2(z,-1/tau);

% tests of weierstrassian elliptic functions from
% former file sfweier.tst added by AB January 2022

% periodicity, quasi-periodicity, zeroes etc.
weierstrass(u+2v+4w,v,w);
a1:=weierstrass(u-2v-6w,v,w);
a2:=weierstrass(u+2v+3w,v,w);
a3:=weierstrass(u+5v+4w,v,w);
a4:=weierstrass(u+3v+5w,v,w);
weierstrass(2v+3w,v,w);
weierstrass(5v+2w,v,w);
weierstrass(3v+5w,v,w);

weierstrass(-2u^3,v,w);
m :=6;
weierstrass(m*u,m*v,m*w);

weierstrassZeta(u+2v+4w,v,w);
b1:=weierstrassZeta(u-2v-6w,v,w);
b2:=weierstrassZeta(u+2v+3w,v,w);
b3:=weierstrassZeta(u+5v+4w,v,w);
b4:=weierstrassZeta(u+3v+5w,v,w);
weierstrassZeta(2v+3w,v,w);
weierstrassZeta(5v+4w,v,w);
weierstrassZeta(3v+5w,v,w);

weierstrassZeta(-u+2w+4v,v,w);
m:= -5;
weierstrassZeta(m*u,m*v,m*w);


weierstrass_sigma(u+2v,v,w);
weierstrass_sigma(u-2w,v,w);
weierstrass_sigma(u+2v+2w,v,w);
c1:=weierstrass_sigma(u-2v-6w,v,w);
c2:=weierstrass_sigma(u+2v+3w,v,w);
c3:=weierstrass_sigma(u+5v+4w,v,w);
c4:=weierstrass_sigma(u+3v+5w,v,w);
weierstrass_sigma(2v+4w,v,w);
weierstrass_sigma(-2v-4w,v,w);
weierstrass_sigma(2v+w,v,w);
weierstrass_sigma(v+4w,v,w);
weierstrass_sigma(3v+w,v,w);

weierstrass_sigma(-u+2v+4w,v,w);

weierstrass_sigma1(u+2v,v,w);
weierstrass_sigma1(u-2w,v,w);
weierstrass_sigma1(u+2v+2w,v,w);
d1:=weierstrass_sigma1(u-2v-6w,v,w);
d2:=weierstrass_sigma1(u+2v+3w,v,w);
d3:=weierstrass_sigma1(u+5v+4w,v,w);
d4:=weierstrass_sigma1(u+3v+5w,v,w);
weierstrass_sigma1(2v+4w,v,w);
weierstrass_sigma1(-2v-4w,v,w);
weierstrass_sigma1(2v+w,v,w);
weierstrass_sigma1(v+4w,v,w);
weierstrass_sigma1(3v+w,v,w);
weierstrass_sigma1(-u+2v+4w,v,w);

weierstrass_sigma2(u+2v,v,w);
weierstrass_sigma2(u-2w,v,w);
weierstrass_sigma2(u+2v+2w,v,w);
f1:=weierstrass_sigma2(u-2v-6w,v,w);
f2:=weierstrass_sigma2(u+2v+3w,v,w);
f3:=weierstrass_sigma2(u+5v+4w,v,w);
f4:=weierstrass_sigma2(u+3v+5w,v,w);
weierstrass_sigma2(2v+4w,v,w);
weierstrass_sigma2(-2v-4w,v,w);
weierstrass_sigma2(2v+w,v,w);
weierstrass_sigma2(v+4w,v,w);
weierstrass_sigma2(3v+w,v,w);
weierstrass_sigma2(-u+2v+4w,v,w);

weierstrass_sigma3(u+2v,v,w);
weierstrass_sigma3(u-2w,v,w);
weierstrass_sigma3(u+2v+2w,v,w);
g1:=weierstrass_sigma3(u-2v-6w,v,w);
g2:=weierstrass_sigma3(u+2v+3w,v,w);
g3:=weierstrass_sigma3(u+5v+4w,v,w);
g4:=weierstrass_sigma3(u+3v+5w,v,w);
weierstrass_sigma3(2v+4w,v,w);
weierstrass_sigma3(-2v-4w,v,w);
weierstrass_sigma3(2v+w,v,w);
weierstrass_sigma3(v+4w,v,w);
weierstrass_sigma3(3v+w,v,w);
weierstrass_sigma3(-u+2v+4w,v,w);

df(weierstrass1(u, v, w), u);
weierstrass1(2*u, v, w);
weierstrass1(i*u, v, w);

on complex;
m :=6i;
weierstrass_sigma(m*u,m*v,m*w);

m :=-6i;
weierstrass_sigma1(m*u,m*v,m*w);

m :=6+i;
weierstrass_sigma2(m*u,m*v,m*w);

m :=-(6+i);
weierstrass_sigma3(m*u,m*v,m*w);

% numerical evaluations
on rounded, complex;

% complete elliptic integrals of 1st kind

K := elliptick(0.4);
K!' := elliptick!'(0.4);

% complete elliptic integrals of 2nd kind
EE := elliptice(0.4);
EE!' := elliptice!'(0.4);

% some of these used to fail or give erroneous results
elliptick(1.4);
elliptice(1.4);
elliptick(2+i);
elliptice(2+i);

% some incomplete elliptic integrals
elliptice(pi/4, 1/2);
elliptice(pi/4, 3);
elliptice(pi/2+i,1/2);
elliptice(i/2,i);

% Jacobi Zeta function
u := 0.6;
Z:= jacobizeta(u, 0.4);
E2 := jacobie(u, 0.4);

% checks
EE - jacobie(K, 0.4);

EE * K!' + EE!' * K - K * K!' - pi/2;

Z - E2 + EE*u/K;

% Jacobi functions
m := 0.8;

s := jacobisn(u,m);
c :=  jacobicn(u,m);
d :=  jacobidn(u,m);
s^2+c^2;
d^2+m^2*s^2;

u := 1/2+i/3;
s := jacobisn(u,m);
c :=  jacobicn(u,m);
d :=  jacobidn(u,m);
s^2+c^2;
d^2+m^2*s^2;

% Some of these used to fail or give erroneous results
% modulus > 1
m:=3;
s := jacobisn(u,m);
c :=  jacobicn(u,m);
d :=  jacobidn(u,m);
s^2+c^2;
d^2+m^2*s^2;

%Complex modulus
m:=3+i;
s := jacobisn(u,m);
c :=  jacobicn(u,m);
d :=  jacobidn(u,m);
s^2+c^2;
d^2+m^2*s^2;

% should be purely imaginary
jacobisn(0.5i,2);

% should be real
jacobisn(1.5,2i);

% inverse Jacobi functions
v := arcsn(0.5,0.7);
jacobisn(v,0.7);
w := arcns(2.0,0.7);
w-v;

w:=arccn(-0.3,0.8);
jacobicn(w,0.8);

w:=arccs(-0.4,0.8);
v:=arcsc(-2.5,0.8);
w-v-2*elliptick(0.8);

w:=arcdn(3,0.8);
jacobidn(w,0.8);

w:=arcsn(0.5,0.8+i);
jacobisn(w,0.8+i);

w:=arccn(-0.3,0.8+i);
jacobicn(w,0.8+i);

w:=arcdn(0.3+i,0.8+i);
jacobidn(w,0.8+i);


% Nome and related utilities
a:=nome(0.4);
nome2mod(a);
b:=nome(0.99);
nome2mod(b);

elliptick(0.4);
nome2!K(a);
elliptick!'(0.4);
nome2!K!'(a);

% theta functions
% numerical evaluation and consistency checks

tau := -i*log(0.1)/pi;
elliptictheta1(pi/6,tau);
elliptictheta2(pi/4,tau);
elliptictheta3(pi/3,tau);
elliptictheta4(pi/2,tau);

a := elliptictheta3(0,tau);
b := elliptictheta2(0,tau);
c := elliptictheta4(0,tau);
a^4-b^4-c^4;

tau := -i*log(0.8)/pi;
elliptictheta1(pi/6,tau);
elliptictheta2(pi/4,tau);
elliptictheta3(pi/3,tau);
elliptictheta4(pi/2,tau);

a := elliptictheta3(0,tau);
b := elliptictheta2(0,tau);
c := elliptictheta4(0,tau);
a^4-b^4-c^4;

z := 0.5;
w:=z+5*pi/2+3*pi*tau;
elliptictheta1(w,tau);
s1;

w:= z+6*pi+7/2*pi*tau;
elliptictheta4(w,tau);
s2;

w:=pi/6;

e1:=elliptictheta1(w,tau);
e2:=elliptictheta2(w,tau);
e3:=elliptictheta3(w,tau);
e4:=elliptictheta4(w,tau);

e1^4+e3^4-e2^4-e4^4;

a:=atan(4/3)/pi -i/pi*log 0.75;
elliptictheta1(i*pi/6,a);
elliptictheta1(i*pi/6,a-1);
elliptictheta2((2+i)*pi/4,a);
elliptictheta2((2+i)*pi/4,a-1);
elliptictheta3(i*pi/3,a);
elliptictheta3(i*pi/3,a-1);
elliptictheta4(i*pi/3,a);

d := elliptictheta3(0,a);
b := elliptictheta2(0,a);
c := elliptictheta4(0,a);
d^4-b^4-c^4;

% theta derivatives

theta1d(z,1,tau);
theta2d(z,2,tau);
theta3d(z,3,tau);
theta4d(z,2,tau);

td1:= theta1d(0,1,tau);
td3:= theta1d(0,3,tau);
t2 := elliptictheta2(0,tau);
t3 := elliptictheta3(0,tau);
t4 := elliptictheta4(0,tau);

td1-t2*t3*t4;

t2dd := theta2d(0,2,tau);
t3dd := theta3d(0,2,tau);
t4dd := theta4d(0,2,tau);


td3/td1-(t2dd/t2+t3dd/t3+t4dd/t4);

% weierstrassian elliptic functions and lattice functions
% numerical evaluations  -- should agree with Lawden's tables 

weierstrass(0.1, 1, 0.4i);
9*weierstrass(0.3, 3, 1.2i);
weierstrass(0.5+0.3i, 1, 0.3i);
16*weierstrass(2.0+1.2i, 4, 1.2i);
weierstrass(1,1,(1+1.4i)/2);
weierstrass(1.2, 1.2, 0.8i)-lattice_e1(1.2, 0.8i);
weierstrass(0.8i, 1.2, 0.8i)-lattice_e3(1.2, 0.8i);
weierstrass(1.2+0.8i, 1.2, 0.8i)-lattice_e2(1.2, 0.8i);

weierstrassZeta(0.2, 1, 1.6i);
3*weierstrassZeta(0.6, 3, 4.8i);
weierstrassZeta(1.9, 1, 0.6i);
4*weierstrassZeta(7.6, 4, 2.4i);
weierstrassZeta(1, 1, 1.6i)-eta1(1,1.6i);
weierstrassZeta(1.6i, 1, 1.6i)-eta3(1,1.6i);
weierstrassZeta(1+1.6i, 1, 1.6i)+eta2(1,1.6i);

weierstrass_sigma(0.2, 1, 1.6i);
weierstrass_sigma(0.6, 3, 4.8i)/3;
weierstrass_sigma(1.9, 1, 0.6i);
weierstrass_sigma(7.6, 4, 2.4i)/4;
weierstrass_sigma(2, 1, 1.6i);
weierstrass_sigma(3.2i, 1, 1.6i);
weierstrass_sigma(2+3.2i, 1, 1.6i);

weierstrass_sigma1(0.2, 1, 1.6i);
weierstrass_sigma1(0.6, 3, 4.8i);
weierstrass_sigma1(1.9, 1, 0.6i);
weierstrass_sigma1(7.6, 4, 2.4i);
-weierstrass_sigma1(2, 1, 1.6i)/exp(2*eta1(1,1.6i));
weierstrass_sigma1(3.2i, 1, 1.6i)/exp(2*eta3(1,1.6i)*1.6i);
weierstrass_sigma1(1, 1, 1.6i);

weierstrass_sigma2(0.2, 1, 1.6i);
weierstrass_sigma2(0.6, 3, 4.8i);
weierstrass_sigma2(1.9, 1, 0.6i);
weierstrass_sigma2(7.6, 4, 2.4i);
weierstrass_sigma2(2, 1, 1.6i)/exp(2*eta1(1,1.6i));
weierstrass_sigma2(3.2i, 1, 1.6i)/exp(2*eta3(1,1.6i)*1.6i);
weierstrass_sigma2(1+1.6i, 1, 1.6i);

weierstrass_sigma3(0.2, 1, 1.6i);
weierstrass_sigma3(0.6, 3, 4.8i);
weierstrass_sigma3(1.9, 1, 0.6i);
weierstrass_sigma3(7.6, 4, 2.4i);
weierstrass_sigma3(2, 1, 1.6i)/exp(2*eta1(1,1.6i));
-weierstrass_sigma3(3.2i, 1, 1.6i)/exp(2*eta3(1,1.6i)*1.6i);
weierstrass_sigma3(1.6i, 1, 1.6i);

u:=1; v:=2; w:= 0.5i;
weierstrass(u-2v-6w,v,w)-a1;
weierstrass(u+2v+3w,v,w)-a2;
weierstrass(u+5v+4w,v,w)-a3;
weierstrass(u+3v+5w,v,w)-a4;

weierstrassZeta(u-2v-6w,v,w)-b1;
weierstrassZeta(u+2v+3w,v,w)-b2;
weierstrassZeta(u+5v+4w,v,w)-b3;
weierstrassZeta(u+3v+5w,v,w)-b4;

weierstrass_sigma(u-2v-6w,v,w)-c1;
weierstrass_sigma(u+2v+3w,v,w)-c2;
weierstrass_sigma(u+5v+4w,v,w)-c3;
weierstrass_sigma(u+3v+5w,v,w)-c4;

weierstrass_sigma1(u-2v-6w,v,w)-d1;
weierstrass_sigma1(u+2v+3w,v,w)-d2;
weierstrass_sigma1(u+5v+4w,v,w)-d3;
weierstrass_sigma1(u+3v+5w,v,w)-d4;

weierstrass_sigma2(u-2v-6w,v,w)-f1;
weierstrass_sigma2(u+2v+3w,v,w)-f2;
weierstrass_sigma2(u+5v+4w,v,w)-f3;
weierstrass_sigma2(u+3v+5w,v,w)-f4;

weierstrass_sigma3(u-2v-6w,v,w)-g1;
weierstrass_sigma3(u+2v+3w,v,w)-g2;
weierstrass_sigma3(u+5v+4w,v,w)-g3;
weierstrass_sigma3(u+3v+5w,v,w)-g4;

l := lattice_generators(4,1);
lattice_invariants(first l, second l);

l := lattice_generators(2+i, 3+i);
lattice_invariants(first l, second l);

weierstrass1(0.5, 3, 0);      % special case (g3=0)
weierstrasszeta1(0.5, 0, 3);  % special case (g2=0)
weierstrass1(0.5, 4, 1);  % real lattice roots
weierstrass1(0.5, 4, -1); % ditto -- same discriminant
weierstrasszeta1(0.5, 1, 2);  % one real & 2 complex-conjugate roots
weierstrasszeta1(0.5, 1, -2); % ditto -- same discriminant
weierstrass1(0.5, 4*(2+i)^2, (2+i)^3);  % complex lattice roots (collinear)
weierstrass1(0.5, 2+i, 2+i);            % complex lattice roots (general)

lattice_roots(2+i, 1+3i);
quasi_period_factors(2+i, 1+3i);

;end;

