% Dispersionless Boussinesq equation: three local Hamiltonian operators
% 2015-10-09
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u,v}$
odd_var:={p,q}$
deg_indep_var:={-1,-2}$
deg_dep_var:={2,1}$
deg_odd_var:={1,2}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="bou_lho1_state.red"$
resname:="bou_lho1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t,v_t}$
% right-hand side of the differential equation
de:={u_x*v+u*v_x+sig*v_3x,u_x+v*v_x}$

% same constructions for odd coordinates;
principal_odd:={p_t,q_t}$
de_odd:={v*p_x+q_x,u*p_x+sig*p_3x+v*q_x}$

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
l_grad_var:=der_deg_ordering(0,all_parametric_der)$
l_grad_odd:={1} . der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
gradmon:=graded_mon(1,10,l_grad_var)$
gradmon:={1} . gradmon$
% list of graded monomials which are linear in odd variables
% and have total degree from 1 to 6
linodd:=mkalllinodd(gradmon,l_grad_odd,1,6)$
% Ansatz for local Hamiltonian operators
phi1:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$
phi2:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% equation for shadows of nonlocal symmetries in \ell^*-covering

mk_cdiffop(lbou2,1,{2},2);
for all phi let lbou2(1,1,phi)=td(phi,t) - v*td(phi,x) - v_x*phi;
for all phi let lbou2(1,2,phi)= - u_x*phi - u*td(phi,x) - sig*td(phi,x,3);
for all phi let lbou2(2,1,phi)= - td(phi,x);
for all phi let lbou2(2,2,phi)=td(phi,t) - v*td(phi,x) - v_x*phi;

equ 1:=lbou2(1,1,phi1) + lbou2(1,2,phi2);

equ 2:=lbou2(2,1,phi1) + lbou2(2,2,phi2);

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=2;

off coefficient_check;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,2);

tel2:=splitvars_opequ(equ,3,tel,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

off nat$
off echo$
out <<resname>>;
phi1:=phi1;
phi2:=phi2;
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: