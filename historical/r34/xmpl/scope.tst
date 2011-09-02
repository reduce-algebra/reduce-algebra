% Test SCOPE Package.

% NOTE:  The SCOPE, GHORNER, GSTRUCTR and GENTRAN packages must be loaded
% to run these tests.

on priall$
optimize z:=a^2*b^2+10*a^2*m^6+a^2*m^2+2*a*b*m^4+2*b^2*m^6+b^2*m^2
           iname s;
off priall$
on primat,acinfo$
optimize
     ghorner <<z:=a^2*b^2+10*a^2*m^6+a^2*m^2+2*a*b*m^4+2*b^2*m^6+b^2*m^2>>
     vorder m
     iname s;
operator a$
k:=j:=1$
u:=c*x+d$
v:=sin(u)$
optimize {a(k,j):=v*(v^2*cos(u)^2+u),
          a(k,j)::=:v*(v^2*cos(u)^2+u)} iname s;
off exp$
optimize {a(k,j):=v*(v^2*cos(u)^2+u),
          a(k,j)::=:v*(v^2*cos(u)^2+u)} iname s;
off primat,acinfo,period$
on fort$
optimize z:=(6*a+18*b+9*c+3*d+6*e+18*f+6*g+5*h+5*k+3)^13 iname s;
optimize {x:=3*a*p,y:=3*a*q,z:=6*a*r+2*b*p,u:=6*a*d+2*b*q,
v:=9*a*c+4*b*d,w:=4*b} iname s;
off fort$
clear a$
matrix a(2,2)$
a(1,1):=x+y+z$
a(1,2):=x*y$
a(2,1):=(x+y)*x*y$
a(2,2):=(x+2*y+3)^3-x$
on acinfo$
optimize gstructr<<a;
                   aa:=(x+y)^2;b:=(x+y)*(y+z);c:=(x+2*y)*(y+z)*(z+x)^2>>
name v iname s;
clear a$
off fort;
on priall$
optimize z:=:for j:=2:6 sum a^(1/j) iname s;
off acinfo,priall$
on optdecs$
optlang!*:='fortran$
optimize {x(i+1,i-1):=a(i+1,i-1)+b(i),y(i-1):=a(i-1,i+1)-b(i)} iname s
         declare <<x(4),a(4,4),y(5):real;b(5):integer>>;
optlang!*:='c$
optimize {x(i+1,i-1):=a(i+1,i-1)+b(i),y(i-1):=a(i-1,i+1)-b(i)} iname s
         declare <<x(4),a(4,4),y(5):real;b(5):integer>>;
optlang!*:= 'pascal$
optimize {x(i+1,i-1):=a(i+1,i-1)+b(i),y(i-1):=a(i-1,i+1)-b(i)} iname s
         declare <<x(4),a(4,4),y(5):real;b(5):integer>>;
optlang!*:='ratfor$
optimize {x(i+1,i-1):=a(i+1,i-1)+b(i),y(i-1):=a(i-1,i+1)-b(i)} iname s
         declare <<x(4),a(4,4),y(5):real;b(5):integer>>;

end;
