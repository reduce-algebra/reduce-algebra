% Plebanski equation: conservation laws on the cotangent covering
%    for non-local variables.
% 2015-10-10
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y,z}$
dep_var:={u}$
odd_var:={p,r}$
deg_indep_var:={-1,-1,-4,-4}$
deg_dep_var:={1}$
deg_odd_var:={1,4}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="ple_nlcl1_state.red"$
resname:="ple_nlcl1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_xz}$
% right-hand side of the differential equation
de:={-u_ty+u_tx**2-u_2t*u_2x}$

% We add conservation laws as new nonlocal odd variables;
principal_odd:={p_xz,r_x,r_t}$
% rhs of the equations that define the nonlocal variable
rt:= - p_z - u_2t*p_x + u_tx*p_t$
rx:= p_y + u_2x*p_t - u_tx*p_x$
de_odd:={-p_ty+2*u_tx*p_tx-u_2x*p_2t-u_2t*p_2x,rx,rt}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

td(r,t,x) - td(r,x,t);

;end;


Local Variables:
mode:reduce
End:
