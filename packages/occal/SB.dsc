NAME
Reentry

TITLE
Stoer-Bulirsch, Kap. 7 

CONSTANTS
R = 209
beta = 4.26
rho0 := 2.704e-3
g := 0.32172e-3

DYNAMIC_VARIABLES
v
gama
xi

CONTROL_VARIABLES
u

ABBREVIATIONS
rho(~h) = rho0 * exp(- beta * h);
c_W (u) :=  1.174 - 0.9 * cos(u);
c_A (u) := 0.6 * sin(u);
S := 53200 * m;
h := xi * R;

TIME_VARIABLE
tt

DIFFERENTIAL_EQUATIONS
DOT(v) := -S*rho(h)*v^2*c_W(u)/(2*m)
          - g * sin(gama) / (1 + xi)^2;
DOT(gama) := S*rho(h)*v*c_A(u)/(2*m)
              + v*cos(gama) / (R * (1 + xi))
              - g*cos(gama)/(v * (1 + xi)^2);
xi       v * sin (gama) / R;

FUNCTIONAL
10*v^3*sqrt(rho(h));

END_POINT_IS_FREE

BOUNDARIES
0;
TIME_T;

BOUNDARY_CONDITIONS
v(0) - 0.36;
gama(0) + 8.1*pi/180;
xi(0)-4/R;
v(TIME_T) - 0.27;
gama(TIME_T);
xi(TIME_T) -2.5/R;

RESTRICTIONS
v > 0;

