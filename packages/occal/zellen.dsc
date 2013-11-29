COMMENT
           Zellenwachstum des Immunsystems

NAME
zellen

TITLE
   Zellenwachstum

PARAMETERS
b
d
myp
myl
gama
k
L0
As

FUNCTIONAL
1;

DYNAMIC_VARIABLES
A
L
P

CONTROL_VARIABLES
u

BOUNDARIES
0;
ts;

TIME_VARIABLE
t

DIFFERENTIAL_EQUATIONS
A        k * L * (1 - L/c) + k * gama * P;
L        (b * u - d * (1 - u) - myl) * L * (1 - L/c);
P        d * (1 - u) * L * (1 - L/c) - myp * P;

BOUNDARY_CONDITIONS
A(0);
L(0) - L0;
P(0);
A(ts) -As;

RESTRICTIONS
L * (1 - L/c) > 0;
L < c;
c - l > 0;
c>0;
A > 0;
L > 0;
P > 0;
d > 0;
k > 0;
gama > 1;
B>0;
b >= myl;
myp > 0;
myl > 0;
c>0;