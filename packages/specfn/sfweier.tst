load specfn;

out "sfweier.rlg";

% test of sfweier.red
% Author: Alan Barnes   (Alan.Barnes45678@gmail.com) February 2021

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


sigma(u+2v,v,w);
sigma(u-2w,v,w);
sigma(u+2v+2w,v,w);
c1:=sigma(u-2v-6w,v,w);
c2:=sigma(u+2v+3w,v,w);
c3:=sigma(u+5v+4w,v,w);
c4:=sigma(u+3v+5w,v,w);
sigma(2v+4w,v,w);
sigma(-2v-4w,v,w);
sigma(2v+w,v,w);
sigma(v+4w,v,w);
sigma(3v+w,v,w);

sigma(-u+2v+4w,v,w);

sigma1(u+2v,v,w);
sigma1(u-2w,v,w);
sigma1(u+2v+2w,v,w);
d1:=sigma1(u-2v-6w,v,w);
d2:=sigma1(u+2v+3w,v,w);
d3:=sigma1(u+5v+4w,v,w);
d4:=sigma1(u+3v+5w,v,w);
sigma1(2v+4w,v,w);
sigma1(-2v-4w,v,w);
sigma1(2v+w,v,w);
sigma1(v+4w,v,w);
sigma1(3v+w,v,w);
sigma1(-u+2v+4w,v,w);

sigma2(u+2v,v,w);
sigma2(u-2w,v,w);
sigma2(u+2v+2w,v,w);
f1:=sigma2(u-2v-6w,v,w);
f2:=sigma2(u+2v+3w,v,w);
f3:=sigma2(u+5v+4w,v,w);
f4:=sigma2(u+3v+5w,v,w);
sigma2(2v+4w,v,w);
sigma2(-2v-4w,v,w);
sigma2(2v+w,v,w);
sigma2(v+4w,v,w);
sigma2(3v+w,v,w);
sigma2(-u+2v+4w,v,w);

sigma3(u+2v,v,w);
sigma3(u-2w,v,w);
sigma3(u+2v+2w,v,w);
g1:=sigma3(u-2v-6w,v,w);
g2:=sigma3(u+2v+3w,v,w);
g3:=sigma3(u+5v+4w,v,w);
g4:=sigma3(u+3v+5w,v,w);
sigma3(2v+4w,v,w);
sigma3(-2v-4w,v,w);
sigma3(2v+w,v,w);
sigma3(v+4w,v,w);
sigma3(3v+w,v,w);
sigma3(-u+2v+4w,v,w);

on complex;
m :=6i;
sigma(m*u,m*v,m*w);

m :=-6i;
sigma1(m*u,m*v,m*w);

m :=6+i;
sigma2(m*u,m*v,m*w);

m :=-(6+i);
sigma3(m*u,m*v,m*w);

% numerical evaluations  -- should agree with Lawden's tables 
on rounded;

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

sigma(0.2, 1, 1.6i);
sigma(0.6, 3, 4.8i)/3;
sigma(1.9, 1, 0.6i);
sigma(7.6, 4, 2.4i)/4;
sigma(2, 1, 1.6i);
sigma(3.2i, 1, 1.6i);
sigma(2+3.2i, 1, 1.6i);

sigma1(0.2, 1, 1.6i);
sigma1(0.6, 3, 4.8i);
sigma1(1.9, 1, 0.6i);
sigma1(7.6, 4, 2.4i);
-sigma1(2, 1, 1.6i)/exp(2*eta1(1,1.6i));
sigma1(3.2i, 1, 1.6i)/exp(2*eta3(1,1.6i)*1.6i);
sigma1(1, 1, 1.6i);

sigma2(0.2, 1, 1.6i);
sigma2(0.6, 3, 4.8i);
sigma2(1.9, 1, 0.6i);
sigma2(7.6, 4, 2.4i);
sigma2(2, 1, 1.6i)/exp(2*eta1(1,1.6i));
sigma2(3.2i, 1, 1.6i)/exp(2*eta3(1,1.6i)*1.6i);
sigma2(1+1.6i, 1, 1.6i);

sigma3(0.2, 1, 1.6i);
sigma3(0.6, 3, 4.8i);
sigma3(1.9, 1, 0.6i);
sigma3(7.6, 4, 2.4i);
sigma3(2, 1, 1.6i)/exp(2*eta1(1,1.6i));
-sigma3(3.2i, 1, 1.6i)/exp(2*eta3(1,1.6i)*1.6i);
sigma3(1.6i, 1, 1.6i);

u:=1; v:=2; w:= 0.5i;
weierstrass(u-2v-6w,v,w)-a1;
weierstrass(u+2v+3w,v,w)-a2;
weierstrass(u+5v+4w,v,w)-a3;
weierstrass(u+3v+5w,v,w)-a4;

weierstrassZeta(u-2v-6w,v,w)-b1;
weierstrassZeta(u+2v+3w,v,w)-b2;
weierstrassZeta(u+5v+4w,v,w)-b3;
weierstrassZeta(u+3v+5w,v,w)-b4;

sigma(u-2v-6w,v,w)-c1;
sigma(u+2v+3w,v,w)-c2;
sigma(u+5v+4w,v,w)-c3;
sigma(u+3v+5w,v,w)-c4;

sigma1(u-2v-6w,v,w)-d1;
sigma1(u+2v+3w,v,w)-d2;
sigma1(u+5v+4w,v,w)-d3;
sigma1(u+3v+5w,v,w)-d4;

sigma2(u-2v-6w,v,w)-f1;
sigma2(u+2v+3w,v,w)-f2;
sigma2(u+5v+4w,v,w)-f3;
sigma2(u+3v+5w,v,w)-f4;

sigma3(u-2v-6w,v,w)-g1;
sigma3(u+2v+3w,v,w)-g2;
sigma3(u+5v+4w,v,w)-g3;
sigma3(u+3v+5w,v,w)-g4;

shut "sfweier.rlg";
;end;


