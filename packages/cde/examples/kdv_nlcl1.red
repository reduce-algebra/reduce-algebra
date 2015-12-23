% KdV equation: non-local conservation laws on the cotangent covering
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
odd_var:={p}$
deg_indep_var:={-1,-3}$
deg_dep_var:={2}$
deg_odd_var:={1}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_nlcl1_state.red"$
resname:="kdv_nlcl1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% same constructions for odd coordinates
principal_odd:={p_t}$
de_odd:={u*p_x+p_3x}$

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
% and have total degree 6 and 8 respectively
linodd6:=mkalllinodd(graadmon,graadlijst_odd,6,6)$
linodd8:=mkalllinodd(graadmon,graadlijst_odd,8,8)$

% We would like to find three conservation laws
% on the cotangent covering of the KdV equation
% which depend linearly on the covering variables;
% we assume that they are of the form cnx dx + cnt dt.
% They are produced by symmetries of the initial equation.
% In the case of 2 independent variables and 1 dependent variable,
% one could prove that one component of such conservation laws
% can always be written as sym*p_x0t0 as follows:

c1x:=(t*u_x+1)*p$ % degree 1
c2x:=u_x*p$ % degree 4
c3x:=(u*u_x+u_3x)*p$ % degree 6

% The second component must be found by solving an equation.

c1t:=f1*p+f2*p_x+f3*p_2x$
c2t:=(for each el in linodd6 sum (c(ctel:=ctel+1)*el))$ % degree 6
c3t:=(for each el in linodd8 sum (c(ctel:=ctel+1)*el))$ % degree 8

% for the first conservation law solutions are found by hand
% due to the presence of `t' in the generator.

f3:=t*u_x+1$
f2:=-td(f3,x)$
f1:=u*f3+td(f3,x,2)$

% The first equation below is already solved `by hand'.

equ 1:=td(c1t,x)-td(c1x,t);
equ 2:=td(c2t,x)-td(c2x,t);
equ 3:=td(c3t,x)-td(c3x,t);

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=3;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,3);

tel2:=splitvars_opequ(equ,4,tel,vars);

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

off echo$
off nat$
out <<resname>>$
c1x:=c1x;
c1t:=c1t;
c2x:=c2x;
c2t:=c2t;
c3x:=c3x;
c3t:=c3t;
shut <<resname>>$
on nat$
on echo$

;end;

