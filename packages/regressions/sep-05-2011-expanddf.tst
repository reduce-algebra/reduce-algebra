depend r,x;

depend {u}, a, b, {a, b}, v;

df(u,v);

on expanddf;

df(u,v);

operator f;

df(f(a),v);

df(f(u),v);

let x^3=u;

operator f;

let f(r)^3=u;

df(x,u);

df (f(r),u);

df(f(r,r^2),x);

df(f(r,cos y),x);

df(f(r,cos(x)),x);

df(f(r,cos y),x);

depend cos(y),x;

df(f(r,cos y),x);

depend y,x;

df(f(r,cos y),x);

df(cos y,x);

nodepend y,x;

df(cos y,x);

off expanddf;

df(f(r),r,x);

on expanddf;

df(f(r),r,x);

operator g;

off expanddf;

depend g(v),A1;

df(df(int(g(v),v),A1),v);

on expanddf;

df(df(int(g(v),v),A1),v);

end;
