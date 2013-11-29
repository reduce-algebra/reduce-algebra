COMMENT
               Turbo generator  Input file

NAME
turbo

TITLE
   T U R B O G E N E R A T O R  

CONSTANTS
x10 := 0.60295
x20 := 0.0
x30 := 1.87243
x40 := 0.79778
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

FUNCTIONAL
alpha * ((x1 - x1s)**2 + (x4 - x4s)**2) +
 alpha2 * x2**2 +
 alpha3 * (x3-x3s)**2 +
 beta1 * (u1 - u1s)**2 + beta2 * (u2 - u2s)**2;

DYNAMIC_VARIABLES
x1
x2
x3
x4

CONTROL_VARIABLES
u1
u2

BOUNDARIES
0;
ts;

TIME_VARIABLE
t

DIFFERENTIAL_EQUATIONS
x1       x2 * x4;
x2       1/M *
         (u1 - s4 * x1 * x4 - s5 * x1 * x3 - kappad * x2);
x3       u2 - A * x3 + c * x4;
x4       - x1 * x2;

BOUNDARY_CONDITIONS
x1(0) - x10;
x2(0) - x20;
x3(0) - x30;
x4(0) - x40;
lamb_x1(ts);
 lamb_x2(ts);
 lamb_x3(ts);
 lamb_x4(ts);
