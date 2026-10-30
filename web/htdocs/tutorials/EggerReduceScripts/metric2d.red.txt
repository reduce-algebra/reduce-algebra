% Calculations concerning the special metric of Dieter Egger
% Small and capital letters are treated as being equivalent

% Dimension of space-time
n:=2;

% turn off extra echoes
off echo;

% smaller exponents first
on revpri;

% Coordinates
OPERATOR X$
X(0):=t$
X(1):=lambda0$

% lambda0 depends on t
DEPEND lambda0,t$

% Rules
trig1:={sin(~x)^2=>(1-cos(x)^2)}$
let trig1$

% Procedures
procedure kovab(aa,bb); begin
FOR I:=0:n-1 DO FOR J:=0:n-1 DO aa(I,J):=DF(bb(I),X(J))+FOR M:=0:n-1 SUM CHRIST(I,J,M)*bb(M)$
end;

procedure showMatrix(mm); begin
MATRIX hh(n,n)$
FOR I:=0:n-1 DO FOR J:=0:n-1 DO hh(I+1,J+1):=mm(I,J)$
write hh;
end;

procedure showVector(vv); begin
MATRIX hh(n,1)$
FOR I:=0:n-1 DO hh(I+1,1):=vv(I)$
write hh;
end;

% Vectors (1-dim arrays start with index 0)
ARRAY U(n), V(n), LV(n), B(n), LB(n), BG(n)$

% Arrays (2-dim arrays start with indices (0,0))
ARRAY G(n,n), GINV(n,n), CHRIST(n,n,n), RIEM(n,n,n,n), RICCI(n,n), EINST(n,n)$
ARRAY UKV(n,n)$

% Calculations
% optionally set maximum radius to 1
% a0:=1$
% or leave it open
a:=a0*sqrt(1-t^2)$

% Place
u(0):=a0*asin(t)$
u(1):=a*lambda0$

% Metric (cellar indices, covariant, default is zero)
G(0,0):=a0^2/(1-t^2)$
G(1,1):=a0^2*(1-t^2)$

% Inverse Metric (roof indices, contravariant)
MATRIX MG(n,n), MGINV(n,n)$
FOR I:=0:n-1 DO FOR J:=0:n-1 DO MG(I+1,J+1):=G(I,J)$
MGINV:=1/MG$
FOR I:=0:n-1 DO FOR J:=0:n-1 DO GINV(I,J):=MGINV(I+1,J+1)$

% show metric
write "g = ",mg;
write "ginv = ",mginv;
write "g*ginv = ",mg*mginv;

% Christoffel symbols
for k:=0:n-1 do for l:=0:n-1 do for m:=0:n-1 do CHRIST(k,l,m):=for i:=0:n-1 sum GINV(k,i)/2 * (DF(G(m,i),X(l)) + DF(G(l,i),X(m)) - DF(G(m,l),X(i)));
  
% curvature tensor
for m:=0:n-1 do for i:=0:n-1 do for k:=0:n-1 do for p:=0:n-1 do RIEM(m,i,k,p) :=DF(CHRIST(m,i,k),X(p)) - DF(CHRIST(m,i,p),X(k)) + FOR r:=0:n-1 SUM CHRIST(r,i,k)*CHRIST(m,r,p) - CHRIST(r,i,p)*CHRIST(m,r,k)$
 
% Ricci tensor
FOR I:=0:n-1 DO FOR J:=0:n-1 DO RICCI(I,J):=FOR M:=0:n-1 SUM RIEM(M,I,J,M)$
write "ricci = "; showMatrix(ricci);

% curvature scalar
R:=FOR I:=0:n-1 SUM FOR J:=0:n-1 SUM GINV(I,J)*RICCI(I,J)$
write "curvature scalar r = ",r;

% Einstein tensor
FOR I:=0:n-1 DO FOR J:=0:n-1 DO EINST(I,J):=RICCI(I,J)-R/2*G(I,J)$
write "einstein = "; showMatrix(einst);

% show place
write "place u = "; showVector(u);

% covariant derivative of place u
kovab(ukv,u)$
write "cov. deriv. of u = "; showMatrix(ukv);

% classical velocity
for k:=0:n-1 do v(k):=df(U(k),X(0))$
write "v = du/dt = "; showVector(v);

% local velocity with respect to (x0,x1)
for k:=0:n-1 do LV(k):=V(k)/V(0)$
write "lv = dx1/dx0 = "; showVector(lv);

% max. velocity
Array vmax(n)$
svmax:=a0/sqrt(1-t^2)$
for i:=0:n-1 do vmax(i):=svmax$
svmaxq:=svmax*svmax$
write "max. velocity = ",svmax;

% equation of motion
for k:=0:n-1 do BG(k):=-for m:=0:n-1 sum for n:=0:n-1 sum CHRIST(k,m,n)* vmax(m)*vmax(n)$
write "equation of motion = "; showVector(bg);

% local acceleration wrt (x0,x1)
for k:=0:n-1 do LB(k) :=1/V(0)*df(lv(k),x(0))$
write "la = dlv/dx0 * 1/v0 = "; showVector(lb);

%--------------------------------------------------------------
% write results to file
OUT "metric2d_results.txt";
off echo;
off nat;

% Metric
write "metric = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",I,",",J,") = ", G(I,J)$

% Inverse Metric
WRITE "inverse metric = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",I,",",J,") = ", GINV(I,J)$

% Christoffel symbols
write "christoffel symbols = ";
FOR K:=0:n-1 DO FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",K,",",I,",",J,") = ", CHRIST(K,I,J)$

% curvature tensor
write "curvature tensor = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO FOR K:=0:n-1 DO FOR L:=0:n-1 DO WRITE "(",I,",",J,",",K,",",L,") = ", RIEM(I,J,K,L)$
  
% Ricci tensor
write "ricci tensor = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",I,",",J,") = ", RICCI(I,J)$

% curvature scalar
write "curvature scalar = ",R$

% Einstein tensor
write "einstein tensor = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",I,",",J,") = ",EINST(I,J)$

% place U
write "place u = ";
FOR I:=0:n-1 DO WRITE "(",I,") = ", U(I)$

% covariant derivative of U
write "covariant derivative of u = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",I,",",J,") = ",Ukv(I,J)$

% velocity V
write "velocity v = ";
FOR I:=0:n-1 DO WRITE "(",I,") = ", V(I)$

% local velocity wrt (x0,x1)
write "local velocity wrt (x0,x1) = ";
FOR I:=0:n-1 DO WRITE "(",I,") = ", LV(I)$

% acceleration
write "acceleration = ";
FOR I:=0:n-1 DO WRITE "(",I,") = ", B(I)$

% local acceleration wrt (x0,x1)
write "local acceleration wrt (x0,x1) = ";
FOR I:=0:n-1 DO WRITE "(",I,") = ", LB(I)$

% equation of motion
write "equation of motion = ";
FOR I:=0:n-1 DO WRITE "(",I,") = ", BG(I)$

% equation of motion 
on factor;
write "equation of motion = ";
FOR I:=0:n-1 DO WRITE "(",I,")  =", BG(I)$
off factor;

SHUT "metric2d_results.txt";

off revpri;
on nat;

END;

