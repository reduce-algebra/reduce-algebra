% Plebanski equation: non-local Hamiltonian operators
% We introduce non-local variables for the nonlocal Hamiltonian operator
% from the paper by Neyzi, Nutku, Sheftel (2005).
%
% 2015-10-10
% Raffaele Vitolo

% on comp, echo, backtrace;
load_package cde;
% in "cde_add.red";
% algebraic;

% load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y,z}$
dep_var:={u}$
odd_var:={p,r}$
deg_indep_var:={-1,-1,-4,-4}$
deg_dep_var:={1}$
deg_odd_var:={1,4}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="ple_nlho1_state.red"$
resname:="ple_nlho1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_xz}$
% right-hand side of the differential equation
de:={-u_ty+u_tx**2-u_2t*u_2x}$

% rhs of the equations that define the nonlocal variable
rt:= - p_z - u_2t*p_x + u_tx*p_t$
rx:= p_y + u_2x*p_t - u_tx*p_x$

% same constructions for odd coordinates.
% Note that we add conservation laws as new nonlocal odd variables;
% so we first introduce the component of the conservation law:
principal_odd:={
p_xz,
r_x,r_t
}$
%
de_odd:={-p_ty+2*u_tx*p_tx-u_2x*p_2t-u_2t*p_2x,
rx,rt
}$

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

% This is the ansatz for the nonlocal Hamiltonian operator.
% Ansatz-generating functions:
l_grad_var:=der_deg_ordering(0,all_parametric_der)$
l_grad_odd:={1} . der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
gradmon:=graded_mon(1,10,l_grad_var)$
gradmon:={1} . gradmon$
linodd:=mkalllinodd(gradmon,l_grad_odd,1,4)$

phi:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% This is the equation ell_Ple(sym)=0, where Ple=0 is
% the Plebanski equation
equ 1:=td(phi,x,z)+td(phi,t,y)-2*u_tx*td(phi,t,x)
+u_2x*td(phi,t,2)+u_2t*td(phi,x,2)$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=1;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,1);

tel2:=splitvars_opequ(equ,2,tel,vars);

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equation!

for i:=tel+1:tel2 do integrate_equation i;

off echo;
off nat;
out <<resname>>;
phi:=phi;
shut <<resname>>;
on nat;
on echo;

;end;


