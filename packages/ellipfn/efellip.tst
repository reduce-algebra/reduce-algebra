out "efellip.rlg";

load_package ellipfn;

% test of facilities efjacobi.red and efellint.red
% Author: Alan Barnes   (Alan.Barnes45678@gmail.com) July 2019
% Modified August 2019. Tests of theta functions moved to sftheta.tst -- 2021
% Renamed (was sfellip.tst) and moved to a new package ellipfn, December 2021
% by Alan Barnes

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

% inverse Jacobi functions
v := arcsn(0.5,0.7);
jacobisn(v,0.7);
w := arcns(2.0,0.7);
w-v;

arcds(100.0, 0.4);
arccs(100.0, 0.4);

w:=arccn(-0.3,0.8);
jacobicn(w,0.8);

w:=arccs(-0.4,0.8);
w:=arcsc(-2.5,0.8);

% Nome and related utilities
on complex;
a:=nome(0.4);
nome2mod(a);
nome(0.99);

elliptick(0.4);
nome2!K(a);
elliptick!'(0.4);
nome2!K!'(a);

shut "sfellip.rlg";

;end;

