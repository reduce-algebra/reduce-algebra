operator f;

let f(~x) => exp(-x^2/2);

int(f(x-y),y);
df(ws,y);
int(f(x+y),y);
df(ws,y);

int(f^(b*x^2+c*x),x);
df(ws,x);
int(f^(1/b*x^2+c*x),x);
df(ws,x);
int(f^(1/b*x^2+c*x/d),x);
df(ws,x);
int(f^(c*x)/f^(b*x^2+d),x);
df(ws,x);
int(f^(c*x)/f^(x^2/b+d),x);
df(ws,x);
int(f^(c*x)/f^((b*x^2+d)/a),x);
df(ws,x);
int(a/f^(b*x^2+c*x+d),x);
df(ws,x);
int(g/f^((b*x^2+c*x+d)/a),x);
df(ws,x);

int(f^(c*x)/f^(x^2/b),x);
df(ws,x);

end;

