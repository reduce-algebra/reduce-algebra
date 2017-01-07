% KP equation: local Hamiltonian operators
% 2015-10-09
% Raffaele Vitolo

on comp, echo, backtrace;
load_package cde;
in "cde_add.red";
algebraic;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u}$
odd_var:={p}$
deg_indep_var:={-3,-2,-1}$
deg_dep_var:={2}$
deg_odd_var:={1}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="kp_lho1_state.red"$
resname:="kp_lho1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_2y}$
% right-hand side of the differential equation
de:={u_tx-u_x**2-u*u_2x-(1/12)*u_4x}$

% same constructions for odd coordinates
principal_odd:={p_2y}$
de_odd:={p_tx-u*p_2x-(1/12)*p_4x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% List of variables ordered by gradings
graadlijst:=der_deg_ordering(0,all_parametric_der)$
graadlijst_odd:={1} . der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
graadmon:=for i:=1:10 collect mkvarlist1(i,i)$
graadmon:={1} . graadmon$
% list of graded monomials which are linear in odd variables
% and have total degree from 1 to 5
linodd:=mkalllinodd(graadmon,graadlijst_odd,1,5)$
% Ansatz for local Hamiltonian operators
phi:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% Equation for shadows of symmetries in the cotangent covering

equ 1:=td(phi,y,2) - td(phi,x,t) + 2*u_x*td(phi,x)
 + u_2x*phi + u*td(phi,x,2) + (1/12)*td(phi,x,4)$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=1$

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0})$

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,1);

tel2:=splitvars_opequ(equ,2,tel,vars);

put_equations_used tel2$

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i$

off nat$
off echo$
out <<resname>>$
phi:=phi;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

