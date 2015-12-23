% KdV equation: non-local Hamiltonian operators
% 2015-10-10
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
odd_var:={p,r1,r2,r3}$
deg_indep_var:={-1,-3}$
deg_dep_var:={2}$
deg_odd_var:={2,1,4,6}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="kdv_nlho1_state.red"$
resname:="kdv_nlho1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% same constructions for odd coordinates;
% here odd coordinates are augmented with
% components of local conservation laws on the cotangent covering;
% see the file kdv_nlcl1_res;
% note that the results in the above file must be converted to the p-form
% (identifier notation) using the function replace_extodd
principal_odd:={p_t,r1_x,r1_t,r2_x,r2_t,r3_x,r3_t}$
de_odd:={u*p_x+p_3x,
p*(t*u_x + 1),
p*t*u*u_x + p*t*u_3x + p*u + p_2x*t*u_x + p_2x - p_x*t*u_2x,
p*u_x,
p*u*u_x + p*u_3x + p_2x*u_x - p_x*u_2x,
p*(u*u_x + u_3x),
p*u**2*u_x + 2*p*u*u_3x + 3*p*u_2x*u_x + p*u_5x + p_2x*u*u_x + p_2x*
u_3x - p_x*u*u_2x - p_x*u_4x - p_x*u_x**2}$

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
% and have total degree 7
linodd:=mkalllinodd(graadmon,graadlijst_odd,7,7)$

% This is the ansatz for the nonlocal Hamiltonian operator.
% It comes from the gradings of local Hamiltonian operators
% when written in terms of p's.
phi:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% equation for shadows of nonlocal symmetries in \ell^*-covering
equ 1:=td(phi,t)-u*td(phi,x)-u_x*phi-td(phi,x,3);

% This is the list of variables, to be passed to the equation solver.
vars:=append(indep_var,all_parametric_der);

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

% Next command tells the solver the total number of equations obtained
% after running splitvars.
put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!
for i:=tel+1:tel2 do integrate_equation i;

off nat$
off echo$
out <<resname>>$
phi:=phi;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

