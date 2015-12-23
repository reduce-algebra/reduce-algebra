% KdV equation: local conservation laws
% 2015-10-05
% Raffaele Vitolo

% Loading the interface to cdiff packages; used to generate all
% (even and odd) derivative coordinates,
% (even and odd) principal and parametric derivatives,
% and the restriction of total derivatives to the (even and odd) equation.
% Of course mostly odd part refers to tangent or cotangent covering.

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
deg_indep_var:={-1,-3}$
deg_dep_var:={2}$
deg_odd_var:={0}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_lcl1_state.red"$
resname:="kdv_lcl1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% List of lists of variables ordered by gradings
graadlijst:=der_deg_ordering(0,all_parametric_der)$
% List of lists of graded monomials of scale degree <= 5
graadmon:=for i:=1:5 collect mkvarlist1(i,i)$
graadmon:={1} . graadmon$
ansatz:=for each el in graadmon join el$

% we assume a conservation law of the form omega = fx dx+ ft dt
fx:=(for each el in ansatz sum (c(ctel:=ctel+1)*el))$
ft:=(for each el in ansatz sum (c(ctel:=ctel+1)*el))$

% This is the equation dbar(omega)=0, where `dbar' is the total exterior
% derivative. Note that the equation has to be fulfilled on the initial
% differential equation. From now on all equations
% are arranged in a single vector whose name is `equ'.

equ 1:=td(fx,t)-td(ft,x)$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=1;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedure splitvars in order to obtain equations on coefficiens
% of each monomial.

tel:=splitvars_opequ(equ,1,1,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=2:tel do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write fx:=fx;
write ft:=ft;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

