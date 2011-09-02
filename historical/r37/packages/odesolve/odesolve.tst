% Tests and demonstrations for the odesolve package

% First some tests of the testdf module
algebraic procedure showode();
 <<write "order is ", odeorder, " and degree is ", odedegree;
   write "linearity is ", odelinearity," and highestderiv is ",
         highestderiv>>;

depend y,x$
ode1 := df(y,x);
sortoutode(ode1, y, x)$
showode()$
sortoutode(ode1**2,y,x)$
showode() $
sortoutode(e**ode1,y,x) $
showode() $
sortoutode(df(y,x)*df(y,x,2),y,x) $
showode() $
nodepend y,x $
depend z,w $
sortoutode(df(z,w,2)+3*z*df(z,w)+e**z,z,w) $
showode() $
nodepend z,w $

% ******************************************
% Next some tests for first-order differential equations
depend y,x $
% Just to test tracing
on trode $

% First-order quadrature case
ode := df(y,x) - x**2 - e**x;
odesolve(ode, y, x);

% A first-order linear equation, with an initial condition
ode:=df(y,x) + y * sin x/cos x - 1/cos x;
ans:=odesolve(ode,y,x);
% Note that arbconst is declared as an operator
% The initial condition is y = 1 at x = 0 so we do...
arbconst(!!arbconst)
   := sub(y=1,x=0,rhs first solve(ans,arbconst(!!arbconst)));
ans;
clear arbconst(!!arbconst) $

% A simple separable case
ans := odesolve(df(y,x) - y**2,y,x);
% We can improve this by
solve(ans,y);
nodepend y,x $

% A separable case, in different variables, with an initial condition
depend z,w $
ode:= (1-z**2)*w*df(z,w)+(1+w**2)*z;
% Assign the answer so we can input the condition (z = 2 at w = 1/2)
ans:=odesolve(ode,z,w);
% To tidy up the answer we will get for the constant we use
for all x let log(x)+log(1/x)=0 $
arbconst(!!arbconst) := sub(z=2,w=1/2,
                            rhs first solve(ans,arbconst(!!arbconst)));
ans;
clear arbconst(!!arbconst) $
nodepend z,w $

% Now a homogeneous one
depend y,x $
ode:=df(y,x) - (x-y)/(x+y);
% To make this look decent...
for all x,w let e**((log x)/w)=x**(1/w),
                (sqrt w)*(sqrt x)=sqrt(w*x) $
ans := odesolve(ode,y,x);

% Reducible to homogeneous 
% Note this is the previous example with origin shifted
ode:=df(y,x) - (x-y-3)/(x+y-1);
ans := odesolve(ode,y,x);

% and the special case of reducible to homogeneous
ode:=df(y,x)-(2*x+3*y+1)/(4*x+6*y+1);
ans := odesolve(ode,y,x);

% To tidy up the next one we need
for all x,w let e**(log x + w) = x*e**w,
                e**(w*log x)=x**w $

% a Bernoulli equation
ode:=x*(1-x**2)*df(y,x) + (2*x**2 -1)*y - x**3*y**3;
odesolve(ode,y,x);

% and finally, in this set, an exact case
ode:=(2*x**3 - 6*x*y + 6*x*y**2) + (-3*x**2 + 6*x**2*y - y**3)*df(y,x);
odesolve(ode,y,x);

% ******************************************
% Now for higher-order linear equations with constant coefficients

% First, examples without driving terms
% A simple one to start
ode:=6*df(y,x,2)+df(y,x)-2*y;
odesolve(ode,y,x);

% An example with repeated and complex roots
ode:=df(y,x,4)+2*df(y,x,2)+y;
odesolve(ode,y,x);

% A simple right-hand-side using the above example;
% It will need the substitution
for all w let (sin w)**2 + (cos w)** 2 = 1 $
ode:=ode-exp(x);
odesolve(ode,y,x);

ode:=df(y,x,2)+4*df(y,x)+4*y-x*exp(x);
ans:=odesolve(ode,y,x);
% At x=1 let y=0 and df(y,x)=1
ans2 := solve({first ans, 1 = df(rhs first ans, x)}, 
	       {arbconst(!!arbconst-1),arbconst(!!arbconst)});
arbconst(!!arbconst -1) := sub(x=1,y=0,rhs first first ans2);
arbconst(!!arbconst) := sub(x=1,y=0,rhs second first ans2);
ans;
clear arbconst(!!arbconst),arbconst(!!arbconst-1), ans, ans2 $

% For simultaneous equations you can use the machine e.g. as follows

depend z,x $
ode1:=df(y,x,2)+5*y-4*z+36*cos(7*x);
ode2:=y+df(z,x,2)-99*cos(7*x);
ode:=df(ode1,x,2)+4*ode2;
y := rhs first odesolve(ode,y,x);
z := rhs first solve(ode1,z);
clear ode1, ode2, ode, y,z $
nodepend z,x $

% A "homogeneous" n-th order (Euler) equation
ode := x*df(y,x,2) + df(y, x) + y/x + (log x)**3;
odesolve(ode, y, x);

% Not yet working
% ode :=6*df(y,x,2)+df(y,x)-2*y + tan x;
% odesolve(ode, y,x);

% To reset the system
!!arbconst := 0 $
clear ode $
off trode$
nodepend y,x $
end $
