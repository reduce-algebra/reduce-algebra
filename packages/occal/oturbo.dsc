COMMENT
               Turbo generator  Input file

NAME
oturbo

TITLE
   T U R B O G E N E R A T O R  

CONSTANTS
deltas := 0.647193730475
eta0 := 0.0
x30 := 1.87243
alpha := 2.5
alpha2 := 1.0
alpha3 := 0.1
beta1 := 1.0
beta2 := 1.0
M := 0.04225
x1s := 0.60295
x2s := 0.00
x3s := 1.87253
x4s := 0.79778
s4 :=0.0
s5:=0.0
c:=0.0
A:=0.17
u1s := 0.80
u2s := 0.73962
kappad := 0.02535

ABBREVIATIONS
x2 => eta;
x1 => sin(delta);
x4 => cos(delta);

FUNCTIONAL
alpha * ((x1 - x1s)**2 + (x4 - x4s)**2) +
 alpha2 * x2**2 +
 alpha3 * (x3-x3s)**2 +
 beta1 * (u1 - u1s)**2 + beta2 * (u2 - u2s)**2;

DYNAMIC_VARIABLES
delta
eta
x3

CONTROL_VARIABLES
u1
u2

BOUNDARIES
0;
ts;

TIME_VARIABLE
t

DIFFERENTIAL_EQUATIONS
delta    eta;
eta       1/M *
         (u1 - s4 * sin(delta) * cos(delta)
             - s5 * x3 * sin(delta) - kappad * eta);
x3       u2 - A * x3 + c * cos(delta);

BOUNDARY_CONDITIONS
delta(0) - deltas;
eta(0) - eta0;
x3(0) - x30;
lamb_delta(ts);
 lamb_eta(ts);
 lamb_x3(ts);
