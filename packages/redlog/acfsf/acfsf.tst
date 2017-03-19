rlset acfsf;

sub(x=a, x=0 and a=0 and ex(x, x=y) and ex(a, x<>a));

rlsimpl(x^2+y^2+1<>0);

rlqe ex(x,x^2=y);

g := ex(x,x^3+a*x^2+b*x+c=0 and x^3+d*x^2+e*x+f=0);

rlvarl g;

h := rlqe g;

rlatnum h;

rlstruct h;

rltermml h;

rlqe rlall (h equiv resultant(x^3+a*x^2+b*x+c,x^3+d*x^2+e*x+f,x)=0);

end;
