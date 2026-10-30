% Calculations concerning the special metric of Dieter Egger
% Small and capital letters are treated as being equivalent

% Dimension of space-time
n:=4;

% turn off extra echoes
off echo;

% smaller exponents first
on revpri;

% Coordinates
OPERATOR X$
X(0):=t$
X(1):=lambda0$
X(2):=lambda1$
X(3):=lambda2$

% Vectors (1-dim arrays start with index 0)
ARRAY U(n), V(n)$

% place (fixed to origin)
U(0):=a0*asin(t)$
U(1):=0$
U(2):=0$
U(3):=0$

% Rule
trig1:={sin(~x)^2=>(1-cos(x)^2)}$
let trig1$

% Procedure
procedure showMatrix(mm); begin
MATRIX hh(n,n)$
FOR I:=0:n-1 DO FOR J:=0:n-1 DO hh(I+1,J+1):=mm(I,J)$
write hh; end;

% Arrays (2-dim arrays start with indices (0,0))
ARRAY G(n,n), GINV(n,n), CHRIST(n,n,n), RIEM(n,n,n,n), RICCI(n,n), EINST(n,n)$
ARRAY EIT(n,n), ENI(n,n)$

% Metric (cellar indices)
G(0,0):=a0^2/(1-t^2)$
G(1,1):=a0^2*(1-t^2)$
G(2,2):=a0^2*(1-t^2)*cos(lambda0)^2$
G(3,3):=a0^2*(1-t^2)*cos(lambda0)^2*cos(lambda1)^2$

% Inverse Metric (roof indices)
MATRIX MG(n,n), MGINV(n,n)$
FOR I:=0:n-1 DO FOR J:=0:n-1 DO MG(I+1,J+1):=G(I,J)$
MGINV:=1/MG$
FOR I:=0:n-1 DO FOR J:=0:n-1 DO GINV(I,J):=MGINV(I+1,J+1)$

write "g = ",mg$
write "ginv = ",mginv$
write "g*ginv = ",mg*mginv$

% velocity
for i:=0:n-1 do v(i):=df(u(i),t)$

% max. velocity
Array vmax(n)$
svmax:=a0/sqrt(1-t^2)$
for i:=0:n-1 do vmax(i):=svmax$
svmaxq:=svmax*svmax$
write "max. velocity = ",svmax$

% energy impulse tensor (eit, roof indices)
for i:=0:n-1 do for j:=0:n-1 do eit(i,j):=v(i)*v(j)*(p/svmaxq + rho) - p * ginv(i,j)$  
write "eit roof = "$ showMatrix(eit)$

% energy impulse tensor (eni, cellar indices, including kappa)
for i:=0:n-1 do for j:=0:n-1 do eni(i,j) := - kappa * for k:=0:n-1 sum g(i,k)* for l:=0:n-1 sum g(j,l)*eit(k,l)$
write "eni = -kappa*(eit cellar) = "$ showMatrix(eni)$

% Christoffel symbols (Fliessbach)
for k:=0:n-1 do for l:=0:n-1 do for m:=0:n-1 do CHRIST(k,l,m):= for n:=0:n-1 sum GINV(k,n)/2 * (DF(G(m,n),X(l)) + DF(G(l,n),X(m)) - DF(G(m,l),X(n)))$
  
% curvature tensor (Fliessbach)
for m:=0:n-1 do for i:=0:n-1 do for k:=0:n-1 do for p:=0:n-1 do RIEM(m,i,k,p) :=  DF(CHRIST(m,i,k),X(p)) - DF(CHRIST(m,i,p),X(k)) + FOR r:=0:n-1 SUM CHRIST(r,i,k)*CHRIST(m,r,p) - CHRIST(r,i,p)*CHRIST(m,r,k)$
 
% Ricci tensor (Fliessbach)
FOR I:=0:n-1 DO FOR J:=0:n-1 DO RICCI(I,J):= FOR M:=0:n-1 SUM RIEM(M,I,M,J)$
write "ricci = "$ showMatrix(ricci)$

% curvature scalar
R:= FOR I:=0:n-1 SUM FOR J:=0:n-1 SUM GINV(I,J)*RICCI(I,J)$
write "curvature scalar r = ",r;

% Einstein tensor
FOR I:=0:n-1 DO FOR J:=0:n-1 DO EINST(I,J):=RICCI(I,J)-R/2*G(I,J)$
write "einstein = "$ showMatrix(einst)$

% solving field equations
write "solving field equations ...";
on factor;
erho:=solve(eni(0,0)=einst(0,0),rho)$
write "mass density = ", erho$

ep:=solve(eni(1,1)=einst(1,1),p)$
write "pressure = ", ep$
off factor;

ferho:=sub(ep,erho)$
write "final mass density = ", ferho$

%--------------------------------------------------------------
% write results to file
OUT "metric4d_results.txt";
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

% energy impulse tensor
write "energy impulse tensor eit (roof) = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",I,",",J,") = ",eit(I,J);

% energy impulse tensor
write "energy impulse tensor eni (with kappa, cellar) = ";
FOR I:=0:n-1 DO FOR J:=0:n-1 DO WRITE "(",I,",",J,") = ",eni(I,J);

% solving field equations
write "solving field equations ...";
on factor;
write "mass density = ", erho;
write "pressure = ", ep;
off factor;
write "final mass density = ", ferho;

SHUT "metric4d_results.txt";

off revpri;
on nat;

END;

