% KP equation: tangent covering
% 2015-10-09
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u}$
odd_var:={q}$
deg_indep_var:={-3,-1,-2}$
deg_dep_var:={2}$
deg_odd_var:={1}$
total_order:=12$
% names for output of the state of cde and results of computations
statename:="kp_sympl1_state.red"$
resname:="kp_sympl1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_2y}$
% right-hand side of the differential equation
de:={u_tx-u_x**2-u*u_2x-(1/12)*u_4x}$

% same constructions for odd coordinates
principal_odd:={q_2y}$
de_odd:={
( - 12*q*u_2x - 12*q_2x*u - q_4x + 12*q_tx - 24*q_x*u_x)/12
}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$


;end;

