%Problem: Calculate the PDE's for the isovector of the heat equation.
%--------
%         (c.f. B.K. Harrison, f.B. Estabrook, "Geometric Approach...",
%          J. Math. Phys. 12, 653, 1971);

%The heat equation @   psi = @  psi is equivalent to the set of exterior
%                   xx        t

%equations (with u=@ psi, y=@ psi):
%                   T        x


pform psi=0,u=0,x=0,y=0,t=0,a=1,da=2,b=2;

a:=d psi - u*d t - y*d x;

da:=- d u^d t - d y^d x;

b:=u*d x^d t - d y^d t;


%Now calculate the PDE's for the isovector;

tvector v;

pform vpsi=0,vt=0,vu=0,vx=0,vy=0;
fdomain vpsi=vpsi(psi,t,u,x,y),vt=vt(psi,t,u,x,y),vu=vu(psi,t,u,x,y),
                               vx=vx(psi,t,u,x,y),vy=vy(psi,t,u,x,y);

v:=vpsi*@ psi + vt*@ t + vu*@ u + vx*@ x + vy*@ y;


factor d;
on rat;

i1:=v |_ a - l*a;

pform o=1;

o:=ot*d t + ox*d x + ou*d u + oy*d y;

fdomain f=f(psi,t,u,x,y);

i11:=v _|d a - l*a + d f;

let vx=-@(f,y),vt=-@(f,u),vu=@(f,t)+u*@(f,psi),vy=@(f,x)+y*@(f,psi),
    vpsi=f-u*@(f,u)-y*@(f,y);

factor ^;

i2:=v |_ b - xi*b - o^a + zet*da;

let ou=0,oy=@(f,u,psi),ox=-u*@(f,u,psi),
    ot=@(f,x,psi)+u*@(f,y,psi)+y*@(f,psi,psi);

i2;

let zet=-@(f,u,x)-@(f,u,y)*u-@(f,u,psi)*y;

i2;

let xi=-@(f,t,u)-u*@(f,u,psi)+@(f,x,y)+u*@(f,y,y)+y*@(f,y,psi)+@(f,psi);

i2;

let @(f,u,u)=0;

i2;      % These PDE's have to be solved;


clear a,da,b,v,i1,i11,o,i2,xi,t;
remfdomain f;
clear @(f,u,u);


%Problem:
%--------
%Calculate the integrability conditions for the system of PDE's:
%(c.f. B.F. Schutz, "Geometrical Methods of Mathematical Physics"
%Cambridge University Press, 1984, p. 156)


% @ z /@ x + a1*z  + b1*z  = c1
%    1           1       2

% @ z /@ y + a2*z  + b2*z  = c2
%    1           1       2

% @ z /@ x + f1*z  + g1*z  = h1
%    2           1       2

% @ z /@ y + f2*z  + g2*z  = h2
%    2           1       2      ;


pform w(k)=1,integ(k)=4,z(k)=0,x=0,y=0,a=1,b=1,c=1,f=1,g=1,h=1,
      a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,f1=0,f2=0,g1=0,g2=0,h1=0,h2=0;

fdomain  a1=a1(x,y),a2=a2(x,y),b1=b1(x,y),b2=b2(x,y),
         c1=c1(x,y),c2=c2(x,y),f1=f1(x,y),f2=f2(x,y),
         g1=g1(x,y),g2=g2(x,y),h1=h1(x,y),h2=h2(x,y);


a:=a1*d x+a2*d y$
b:=b1*d x+b2*d y$
c:=c1*d x+c2*d y$
f:=f1*d x+f2*d y$
g:=g1*d x+g2*d y$
h:=h1*d x+h2*d y$

%The equivalent exterior system:;
factor d;
w(1) := d z(-1) + z(-1)*a + z(-2)*b - c;
w(2) := d z(-2) + z(-1)*f + z(-2)*g - h;
indexrange 1,2;
factor z;
%The integrability conditions:;

integ(k) := d w(k) ^ w(1) ^ w(2);

clear a,b,c,f,g,h,w(k),integ(k);

%Problem:
%--------
%Calculate the PDE's for the generators of the d-theta symmetries of
%the Lagrangian system of the planar Kepler problem.
%c.f. W.Sarlet, F.Cantrijn, Siam Review 23, 467, 1981;
%Verify that time translation is a d-theta symmetry and calculate the
%corresponding integral;

pform t=0,q(k)=0,v(k)=0,lam(k)=0,tau=0,xi(k)=0,et(k)=0,theta=1,f=0,
      l=0,glq(k)=0,glv(k)=0,glt=0;

tvector gam,y;

indexrange 1,2;

fdomain tau=tau(t,q(k),v(k)),xi=xi(t,q(k),v(k)),f=f(t,q(k),v(k));

l:=1/2*(v(1)**2+v(2)**2)+m/r$      %The Lagrangian;

pform r=0;
fdomain r=r(q(k));
let @(r,q 1)=q(1)/r,@(r,q 2)=q(2)/r,q(1)**2+q(2)**2=r**2;

lam(k):=-m*q(k)/r;                                %The force;

gam:=@ t + v(k)*@(q(k)) + lam(k)*@(v(k))$

et(k) := gam _| d xi(k) - v(k)*gam _| d tau$

y  :=tau*@ t + xi(k)*@(q(k)) + et(k)*@(v(k))$     %Symmetry generator;

theta := l*d t + @(l,v(k))*(d q(k) - v(k)*d t)$

factor @;

s := y |_ theta - d f$

glq(k):=@(q k) _|s;
glv(k):=@(v k) _|s;
glt:=@(t) _|s;

%Translation in time must generate a symmetry;
xi(k) := 0;
tau := 1;

glq k;
glv k;
glt;

%The corresponding integral is of course the energy;
integ := - y _| theta;


clear l,lam k,gam,et k,y,theta,s,glq k,glv k,glt,t,q k,v k,tau,xi k;
remfdomain r,f;

%Problem:
%--------
%Calculate the "gradient" and "Laplacian" of a function and the "curl"
%and "divergence" of a one-form in elliptic coordinates;


coframe e u=sqrt(cosh(v)**2-sin(u)**2)*d u,
        e v=sqrt(cosh(v)**2-sin(u)**2)*d v,
       e ph=cos u*sinh v*d ph;

pform f=0;

fdomain f=f(u,v,ph);

factor e,^;
on rat,gcd;
order cosh v, sin u;
%The gradient:;
d f;

factor @;
%The Laplacian:;
# d # d f;

%Another way of calculating the Laplacian:
-#vardf(1/2*d f^#d f,f);

remfac @;

%Now calculate the "curl" and the "divergence" of a one-form;

pform w=1,a(k)=0;

fdomain a=a(u,v,ph);

w:=a(-k)*e k;
%The curl:;
x := # d w;

factor @;
%The divergence;
y := # d # w;


remfac @;
clear x,y,w,u,v,ph,e k,a k;
remfdomain a,f;


%Problem:
%--------
%Calculate in a spherical coordinate system the Navier Stokes equations;

coframe e r=d r,e th=r*d th,e ph=r*sin th*d ph;
frame x;

fdomain v=v(t,r,th,ph),p=p(r,th,ph);

pform v(k)=0,p=0,w=1;

%We first calculate the convective derivative;

w := v(-k)*e(k)$

factor e; on rat;

cdv := @(w,t) + (v(k)*x(-k)) |_ w - 1/2*d(v(k)*v(-k));

%next we calculate the viscous terms;

visc := nu*(d#d# w - #d#d w) + nus*d#d# w;

%finally we add the pressure term and print the components of the
%whole equation;

pform nasteq=1,nast(k)=0;

nasteq := cdv - visc + 1/rho*d p$

factor @;

nast(-k) := x(-k) _| nasteq;

remfac @,e;

clear v k,x k,nast k,cdv,visc,p,w,nasteq;
remfdomain p,v;


%Problem:
%--------
%Calculate from the Lagrangian of a vibrating rod the equation of
% motion and show that the invariance under time translation leads
% to a conserved current;

pform y=0,x=0,t=0,q=0,j=0,lagr=2;

fdomain y=y(x,t),q=q(x),j=j(x);

factor ^;

lagr:=1/2*(rho*q*@(y,t)**2-e*j*@(y,x,x)**2)*d x^d t;

vardf(lagr,y);

%The Lagrangian does not explicitly depend on time; therefore the
%vector field @ t generates a symmetry. The conserved current is

pform c=1;
factor d;

c := noether(lagr,y,@ t);

%The exterior derivative of this must be zero or a multiple of the
%equation of motion (weak conservation law) to be a conserved current;

remfac d;

d c;

%i.e. it is a multiple of the equation of motion;

clear lagr,c;


%Problem:
%--------
%Show that the metric structure given by Eguchi and Hanson induces a
%self-dual curvature.
%c.f. T. Eguchi, P.B. Gilkey, A.J. Hanson, "Gravitation, Gauge Theories
% and Differential Geometry", Physics Reports 66, 213, 1980;

for all x let cos(x)**2=1-sin(x)**2;

pform f=0,g=0;
fdomain f=f(r), g=g(r);

coframe   o(r) =f*d r,
      o(theta) =(r/2)*(sin(psi)*d theta-sin(theta)*cos(psi)*d phi),
        o(phi) =(r/2)*(-cos(psi)*d theta-sin(theta)*sin(psi)*d phi),
        o(psi) =(r/2)*g*(d psi+cos(theta)*d phi);

frame e;


pform gamma1(a,b)=1,curv2(a,b)=2;
antisymmetric gamma1,curv2;

factor o;

gamma1(-a,-b):=-(1/2)*( e(-a) _|(e(-c) _|(d o(-b)))
                       -e(-b) _|(e(-a) _|(d o(-c)))
                       +e(-c) _|(e(-b) _|(d o(-a))) )*o(c)$


curv2(-a,b):=d gamma1(-a,b) + gamma1(-c,b)^gamma1(-a,c)$

factor ^;

curv2(a,b):= curv2(a,b)$

let f=1/g;
let g=sqrt(1-(a/r)**4);
pform chck(k,l)=2;
antisymmetric chck;
%The following has to be zero for a self-dual curvature;

chck(k,l):=1/2*eps(k,l,m,n)*curv2(-m,-n)+curv2(k,l);

clear gamma1(a,b),curv2(a,b),f,g,chck(a,b),o(k),e(k);
remfdomain f,g;

%Problem:
%--------
%Calculate for a given coframe and given torsion the Riemannian part and
%the torsion induced part of the connection. Calculate the curvature.

%For a more elaborate example see E.Schruefer, F.W. Hehl, J.D. McCrea,
%"Application of the REDUCE package EXCALC to the Poincare gauge field
%theory of gravity", to be submited to GRG Journal;

pform ff=0, gg=0;

fdomain ff=ff(r), gg=gg(r);

coframe o(4)=d u+2*b0*cos(theta)*d phi,
        o(1)=ff*(d u+2*b0*cos(theta)*d phi)+ d r,
        o(2)=gg*d theta,
        o(3)=gg*sin(theta)*d phi
 with metric g=-o(4)*o(1)-o(4)*o(1)+o(2)*o(2)+o(3)*o(3);

frame e;

pform tor(a)=2,gwt(a)=2,gam(a,b)=1,
      u1=0,u3=0,u5=0;

antisymmetric gam;

fdomain u1=u1(r),u3=u3(r),u5=u5(r);

tor(4):=0$

tor(1):=-u5*o(4)^o(1)-2*u3*o(2)^o(3)$

tor(2):=u1*o(4)^o(2)+u3*o(4)^o(3)$

tor(3):=u1*o(4)^o(3)-u3*o(4)^o(2)$

gwt(-a):=d o(-a)-tor(-a)$

%The following is the combined connection;
%The Riemannian part could have equally well been calculated by the
%RIEMANNCONX statement;

gam(-a,-b):=(1/2)*( e(-b) _|(e(-c) _|gwt(-a))
                   +e(-c) _|(e(-a) _|gwt(-b))
                   -e(-a) _|(e(-b) _|gwt(-c)) )*o(c);

pform curv(a,b)=2;
antisymmetric curv;
factor ^;

curv(-a,b):=d gam(-a,b) + gam(-c,b)^gam(-a,c);



showtime;
end;
