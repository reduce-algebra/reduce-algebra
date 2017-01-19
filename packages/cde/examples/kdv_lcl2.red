% KdV equation: local conservation laws, search for non-trivial c.l.
% 2015-10-05
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
deg_indep_var:={-1,-3}$
deg_dep_var:={2}$
deg_odd_var:={0}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_lcl2_state.red"$
resname:="kdv_lcl2_res.red"$

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
operator c,cc,equ$
cctel:=0;

% List of variables ordered by gradings
l_grad_var:=der_deg_ordering(0,all_parametric_der)$
% List of graded monomials of scale degree <= 3
gradmon:=graded_mon(1,3,l_grad_var)$
gradmon:={1} . gradmon$
gradmon:=indep_var . gradmon$
ansatz:=for each el in gradmon join el$

% Loads the result of the computation in kdv_lcl1_res
ax := c(3)*u_x + c(2)*u + c(1)$
at := (2*c(8) + 2*c(3)*u*u_x + 2*c(3)*u_3x + c(2)*u**2 + 2*c(2)*
u_2x)/2$

% ansatz for a0, the grading must be compatible
% with the system ax-td(a0,x)=0, at-td(a0,t)=0

a0:=(for each el in ansatz sum (cc(cctel:=cctel+1)*el))$

% The equations below will yield the nontrivial part
% of the above conservation law.

equ 1:=ax-td(a0,x);
equ 2:=at-td(a0,t);

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=2;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{cc,cctel,0},{f,0,0});

% Run the procedure splitvars in order to obtain equations on coefficiens
% of each monomial.

tel:=splitvars_opequ(equ,1,2,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=3:tel do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write axnontriv:=ax-ddx(a0);
write atnontriv:=at-ddt(a0);
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

