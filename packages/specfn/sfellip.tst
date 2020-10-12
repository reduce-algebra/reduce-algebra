out "sfellip.rlg";

load_package specfn;

% test of facilities sfellip.red and sfellipi.red
% Author: Alan Barnes   (Alan.Barnes45678@gmail.com) July 2019
% Modified August 2019

% periodic properties and quarter period shifts

jacobisn(u+2*elliptick(k),k);
jacobisn(u+2*i*elliptick!'(k),k);
jacobisn(u+elliptick(k),k);
jacobisn(u+i*elliptick!'(k),k);

jacobizeta(u+2*elliptick(k),k);
elliptice(u+14*elliptick(k),k);

% derivatives and consistency checks

df(jacobicn(u,k),u);
df(jacobisn(u,k)^2+jacobicn(u,k)^2,u);

df(jacobidn(u,k),k);
df(k^2*jacobisn(u,k)^2+jacobidn(u,k)^2,k);
% vanishes by Pythagorean identity for dn and cn

df(elliptice(u,k),u);
df(elliptice(u,k),k);

df(elliptick(k),k);
df(elliptice(k),k);

% check a well-known identity
df(elliptice(k)*elliptick!'(k)+elliptice!'(k)*elliptick(k)-elliptick(k)*elliptick!'(k),k);

df(jacobizeta(u,k),u);
df(ellipticd(u,k),u);
df(ellipticd(u,k),k);

% quasi-periodicity
ellipticd(u+pi/2,k);
ellipticf(u-5*pi/2,k);
ellipticd(u+11*pi/3,k);

% theta functions
% periodicity, quasi-periodicity and zeroes
elliptictheta1(z+6*pi, q);
elliptictheta1(z+7*pi, q);
elliptictheta2(z+7*pi/2, q);
elliptictheta2(z+9*pi/2, q);
elliptictheta4(z+9*pi, q);
elliptictheta4(z+9*pi/2, q);

elliptictheta1(6*pi+7*i*log q, q);
elliptictheta1(z+5*pi/2+3*i*log q, q);
elliptictheta2(6*pi+7*i*log q, q);
elliptictheta2(7/2*pi+7*i*log q, q);

elliptictheta4(6*pi+7/2*i*log q, q);
elliptictheta4(z+6*pi+7/2*i*log q, q);
elliptictheta4(z+6*pi+7*i*log q, q);
elliptictheta3(7*pi/2+3/2*i*log q, q);
elliptictheta3(z+7*pi/2+3/2*i*log q, q);

elliptictheta1(-z,q);
elliptictheta3(-z,q);
elliptictheta3(z,-q);
realvalued q;
elliptictheta1(z,-q);
elliptictheta2(z,-1/4);

% numerical evaluation and consistency checks
on rounded;

% complete elliptic integrals of 1st kind
K := elliptick(0.4);
K!' := elliptick!'(0.4);

% complete elliptic integrals of 2nd kind
EE := elliptice(0.4);
EE!' := elliptice!'(0.4);

% Jacobi Zeta function
u := 0.6;
Z:= jacobizeta(u, 0.4);
E2 := elliptice(u, 0.4);

% checks
EE - elliptice(K, 0.4);

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

% Nome and related utilities
a:=nome(0.4);
nome2mod(a);
nome(0.99);

elliptick(0.4);
nome2!K(a);
elliptick!'(0.4);
nome2!K!'(a);

% theta functions
elliptictheta1(pi/6,0.6);
elliptictheta2(pi/4,0.6);
elliptictheta3(pi/3,0.6);
elliptictheta4(pi/2,0.6);

elliptictheta1(pi/6,0.9);
elliptictheta2(pi/4,0.9);
elliptictheta3(pi/3,0.9);
elliptictheta4(pi/2,0.9);

a := elliptictheta3(0,0.5);
b := elliptictheta2(0,0.5);
c := elliptictheta4(0,0.5);
a^4-b^4-c^4;

shut "sfellip.rlg";

;end;

