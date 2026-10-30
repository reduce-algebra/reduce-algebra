% calculation of metric tensor (2-dim space-time)

off echo;
on revpri;
n:=2;

operator x$
x(0):=t; x(1):=lambda0;

% metric
array g(n,n)$

% rules
trig1:={sin(~x)^2=>(1-cos(x)^2)}$ let trig1$

% procedures
procedure scalprod(a,b); 
begin integer n;
n:=first(length(a))-1; 
result:=for i:=0:n-1 sum a(i)*b(i);
return result 
end;

procedure showmatrix(mm);
begin integer m,n;l:=length(mm);m:=first(l)-1;n:=second(l)-1;
matrix hhm(m,n);
for i:=0:m-1 do for j:=0:n-1 do hhm(i+1,j+1):=mm(i,j);
write hhm end;

procedure showvector(vv);
begin integer n;n:=first(length(vv))-1;
matrix hhv(n,1);
for i:=0:n-1 do hhv(i+1,1):=vv(i);
write hhv end;

array f(n+1), dfdt(n+1), dfdl(n+1)$

% current radius
a:=a0*sqrt(1-t^2);

% surface of hyper sphere in t and lambda

f(0):=a*cos(lambda0);
f(1):=a*sin(lambda0);
f(2):=a0*t;

for i:=0:n do dfdt(i):=df(f(i),x(0));
for i:=0:n do dfdl(i):=df(f(i),x(1));

g(0,0):=scalprod(dfdt,dfdt)$
g(0,1):=scalprod(dfdt,dfdl)$
g(1,0):=scalprod(dfdl,dfdt)$
g(1,1):=scalprod(dfdl,dfdl)$

write "f = "; showvector(f);
write "df/dt = "; showvector(dfdt);
write "df/dl = "; showvector(dfdl);
write "g = "; showmatrix(g);

off revpri;
on echo;
end;
