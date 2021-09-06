off rlabout;

rlset acfsf;

g := ex(x,x^3+a*x^2+b*x+c=0 and x^3+d*x^2+e*x+f=0);

h := rlqe g;

rlqe rlall (h equiv resultant(x^3+a*x^2+b*x+c,x^3+d*x^2+e*x+f,x)=0);

end;
