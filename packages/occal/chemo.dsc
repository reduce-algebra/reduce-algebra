COMMENT
               Chemo therapie generator  Input file

NAME
chemo

TITLE
   Chemotherapie

PARAMETERS
A1
B1
beta1
x10
A2
B2
beta2
x20

FUNCTIONAL
- (1 - alpha) * x1 + alpha * x2;

DYNAMIC_VARIABLES
x1
x2

CONTROL_VARIABLES
u

BOUNDARIES
0;
ts;

TIME_VARIABLE
t

DIFFERENTIAL_EQUATIONS
x1       x1 * (A1 - (A1 - B1) * u - beta1 * log(x1/x10));
x2       x2 * (A2 - (A2 - B2) * u - beta2 * log(x2/x20));

BOUNDARY_CONDITIONS
x1(0) - x10;
x2(0) - x20;
lamb_x1(ts) + (1 - alpha);
lamb_x2(ts) - alpha;

RESTRICTIONS
x1 >= 0;
x2 >= 0;
alpha > 0;
alpha < 1;
alpha - 1 < 0;
beta1 > beta2;