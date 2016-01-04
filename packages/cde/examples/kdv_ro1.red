% KdV equation: recursion operator
% 2015-10-10
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
odd_var:={q,r}$
deg_indep_var:={-1,-3}$
deg_dep_var:={2}$
deg_odd_var:={2,1}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_ro1_state.red"$
resname:="kdv_ro1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% same construction for odd coordinates
principal_odd:={q_t,r_x,r_t}$
de_odd:={u_x*q+u*q_x+q_3x,q,u*q+q_2x}$

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
graadlijst_odd:=der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
graadmon:=for i:=1:10 collect mkvarlist1(i,i)$
graadmon:={1} . graadmon$
graadlijst_odd:={1} . graadlijst_odd$
% list of graded monomials which are linear in odd variables
% and have total degree from 1 to 6
linodd:=mkalllinodd(graadmon,graadlijst_odd,1,6)$
% Ansatz for recursion operators
sym:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% This is the equation \tilde\ell_K(sym)=0, where K=0 is KdV equation,
% \tilde\ell stands for lnearization lifted on the cotangent covering
% and sym is the generating function. From now on all equations
% are arranged in a single vector whose name is `equ'.

equ 1:=td(sym,t)-u*td(sym,x)-u_x*sym-td(sym,x,3)$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=1;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars in order to obtain equations on
% coefficients of each monomial.

tel:=splitext_opequ(equ,1,1);

tel2:=splitvars_opequ(equ,2,tel,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write sym:=sym;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

