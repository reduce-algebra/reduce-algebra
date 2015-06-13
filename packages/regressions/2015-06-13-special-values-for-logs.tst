
log(e);
log(1);
log10(10);
log10(1);

on rounded;
log(e);
log(1);
log10(10);
log10(1);

on complex;
log(e);
log(1);
log10(10);
log10(1);

off complex,rounded;

logb(1,x);
logb(1,y);
logb(1,x^2/y);
logb(x/y,x/y);
logb(y,e);
logb(x*y,10);

log(e^(x^2));
logb(e^(x^2),e);
log10(10^x);
logb(10^x,10);

logb(a**x,a);
logb((a^2)^(x^2),a^2);

log(1/3);
log(-1/3);
log(1/-3);
log((-1)/(-3));

array a(3);
a(1) := 1/3;
log(a(1));


end;
