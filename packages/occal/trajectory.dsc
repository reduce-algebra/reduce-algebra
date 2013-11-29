NAME
Trajectory

TITLE
Trajectory, by H. Oberle

CONSTANTS

PARAMETERS
r0
rf
v0
gamma0
mf



DYNAMIC_VARIABLES
r
phi
v
gama
m

CONTROL_VARIABLES
delta
epsilon
alpha

ABBREVIATIONS
T => Tmax(r,v) * delta;
D => 1/2 * S0 * rho(r) * v^2 * C_D(r,v,alpha);
L => 1/2 * S0 * rho(r) * v^2 * C_L(r,v,alpha);
C_D(r,v,alpha) => C_D0(r,v,alpha) + C_D1(r,v,alpha) * alpha^2;
C_L(r,v,alpha) => C_L1(r,v) * alpha;

TIME_VARIABLE
tt

DIFFERENTIAL_EQUATIONS
DOT(r) = v * sin(gama);
DOT(phi) = v/r * cos(gama);
DOT(v) = 1/m * (T * cos(epsilon) - D) - sin(gama)/r^2;
DOT(gama) = 1/(m*v) * (T * sin(epsilon) + L) + (v/r - 1/(v*r^2)) * cos(gama);
DOT(m) = - sigma(r,v) * T;

FUNCTIONAL
- (1/m * (T * cos(epsilon) - D) - sin(gama)/r^2);

END_POINT_IS_FREE

BOUNDARIES
0;
tf;

BOUNDARY_CONDITIONS
r(0) - r0;
r(tf) - rf;
phi(0);
v(0) - v0;
gama(0) - gamma0;
gama(tf);
m(0) - 1;
m(tf) - mf;
lamb_v(tf) + 1;

RESTRICTIONS
delta >= 0;
delta <= 1;
Tmax(r,v) >= 0;

