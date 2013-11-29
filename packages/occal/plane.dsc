NAME
plane

TITLE
Abort Landing in the Presence of Windshear

CONSTANTS
tf := 40
hR := 1000
rho := 0.2203e-2
S := 0.1560e4
g := 3.2172e1
m := 4662.44
A0 := 0.4456e5
A1 := -0.2398e2
A2 := 0.1442e-1
alphamax := 0.300
umax := 0.052
delta := 0.0349
beta0 := 0.3825
beta0dot := 0.2
x0 := 0
h0 := 600
V0 := 239.7
alpha0 := 0.128
gamma0 :=  -0.0393
gammaf := 0.1297

DYNAMIC_VARIABLES
x
h
V
gammma
alpha

CONTROL_VARIABLES
u

ABBREVIATIONS
T => betta(tt) * (A0 + A1 * V + A2 * V^2);
D => (1/2) * Cd(alpha) * rho * S * V^2;
Cd(alpha) => B0 + B1 * alpha + B2 * alpha^2;
L => (1/2) * Cl * rho * S * V^2;
Wx => k * A(x);
Wh => k * (h/hstar) * B(x);

TIME_VARIABLE
tt

DIFFERENTIAL_EQUATIONS
DOT(x) := V*cos(gammma) + Wx;
DOT(h) := V*sin(gammma) + Wh;
DOT(V) := (T/m) * cos(alpha + delta) - D/m - g * sin(gammma);
DOT(gammma) := (T/(m*V)) * sin(alpha + delta) + L/(m*V) - (1/V) * g * cos(gammma);
DOT(alpha) := u;

FUNCTIONAL
(hR - h)^6;

END_POINT_IS_FREE

BOUNDARIES
0;
tf;

BOUNDARY_CONDITIONS
x(0) - x0;
V(0) - V0;
h(0) - h0;
gammma(0)-gamma0;
alpha(0) - alpha0;
gammma(tf) - gammaf;

RESTRICTIONS
abs(u) <= umax;
alpha <= alphamax;
