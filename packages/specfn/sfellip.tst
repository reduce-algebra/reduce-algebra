out "sfellip.rlg";

load_package specfn;

% test of facilities sfellip.red and sfellipi.red
% Author: Alan Barnes   (Alan.Barnes45678@gmail.com) July 2019

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

% Nome
nome(0.4);
nome(0.99);

shut "sfellip.rlg";

;end;

