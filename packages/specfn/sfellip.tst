out "sfellip.rlg";

load_package specfn;

% test of facilities sfellip.red and sfellipi.red
% Author: Alan Barnes   (Alan.Barnes45678@gmail.com) July 2019
% Modified August 2019. Tests of theta functions moved to sftheta.tst -- 2021

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

% Nome and related utilities
a:=nome(0.4);
nome2mod(a);
nome(0.99);

elliptick(0.4);
nome2!K(a);
elliptick!'(0.4);
nome2!K!'(a);

shut "sfellip.rlg";

;end;

