NAME
Robotarm

TITLE
Robot arm, by H. Oberle

CONSTANTS

PARAMETERS
xL

DYNAMIC_VARIABLES
alpha
theta
omega1
omega2

CONTROL_VARIABLES
U1
U2

ABBREVIATIONS
m1 := 1;
m2 := 1;
M := 1;
l1 := 1;
l2 := 1;
a2 := 0.5;
J1 := 1/3;
J2 := 1/3;
J3 := 0;
U1max := 1;
U2max := 1;
J11 := J1 + (m2 + M) * l1^2;
J12 := m2 * a2 * l1 + M * l1 * l2;
J22 := J2 + J3 + M * l2^2;
det := J11 * J22 - J12^2*cos(alpha)^2;
v1 := J12 * sin(alpha)* omega2^2 + U1 - U2;
v2 := - J12 * sin(alpha)* omega1^2 + U2;
xx(0) := l1 + l2 * cos(alpha(0));
yy(0) := l2 * sin(alpha(0));
xx(~w) => l1*cos(theta(w)) + l2*cos(theta(w)+alpha(w)) when w neq 0;
yy(~w) => l1*sin(theta(w)) + l2*sin(theta(w)+alpha(w)) when w neq 0;

TIME_VARIABLE
tt

DIFFERENTIAL_EQUATIONS
DOT(alpha) = omega2 - omega1;
DOT(theta) = omega1;
omega1       1/det*(-J22 * v1 + cos(alpha) * J12 * v2);
omega2       1/det*(-J11 * v2 + cos(alpha) * J12 * v1);

FUNCTIONAL
1;

END_POINT_IS_FREE

BOUNDARIES
0;
tf;

BOUNDARY_CONDITIONS
theta(0);
omega1(0);
omega2(0);
omega1(tf);
omega2(tf);
sqrt((xx(tf)-xx(0))^2 + (yy(tf) - yy(0))^2) - xL;

RESTRICTIONS
U1 <= U1max;
U2 <= U2max;
U1 >= - U1max;
U2 >= - U2max;
cos(alpha)**2 <= 1;
