
comment An error reported by Andrey Ignatenko:
        the derivative for acoth had the wrong sign.
        Check;

df(acoth(x),x);

comment 
 Test derivative of both sides of f(f^(-1)(x)) = x with respect to x,
 where f and f^(-1)) is a trigonometric or hyberbolic function and
 its inverse correspondingly.  Should return:
 {1,1,1,1,1,1,1,1,1,1,1,1};

operator f, fi$
rlst := {
   {f(~x)=>sin(x), fi(~x)=>asin(x)},
   {f(~x)=>cos(x), fi(~x)=>acos(x)},
   {f(~x)=>tan(x), fi(~x)=>atan(x)},
   {f(~x)=>cot(x), fi(~x)=>acot(x)},
   {f(~x)=>sinh(x), fi(~x)=>asinh(x)},
   {f(~x)=>cosh(x), fi(~x)=>acosh(x)},
   {f(~x)=>tanh(x), fi(~x)=>atanh(x)},
   {f(~x)=>coth(x), fi(~x)=>acoth(x)},
   {f(~x)=>sind(x), fi(~x)=>asind(x)},
   {f(~x)=>cosd(x), fi(~x)=>acosd(x)},
   {f(~x)=>tand(x), fi(~x)=>atand(x)},
   {f(~x)=>cotd(x), fi(~x)=>acotd(x)}
   }$
for each r in rlst collect sub(y=fi(x),df(f(y),y)*df(fi(x),x)) where r;
clear f, fi, rlst;

;end;
