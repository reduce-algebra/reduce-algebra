a:=sin(x);
b:=cos(x);
c:=a+b;
d:=c^2;
% derivative
df(d, x);
% manual derivative
2*(a+b)*(df(a,x)+df(b,x));
end;
