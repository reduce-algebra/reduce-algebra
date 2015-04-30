
int(e^(-(x-mu)^2/(2*sigma^2)),x,-infinity,infinity);

y := e^(-(x-mu)^2/(2*sigma^2));

z := df(y,x)/x;

limit(z,x,infinity);

on complex;

limit(z,x,infinity);

end;
