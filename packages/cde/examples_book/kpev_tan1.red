% KP equation: tangent covering
% 2015-10-09
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u,v}$
odd_var:={p,q}$
deg_indep_var:={-3,-1,-2}$
deg_dep_var:={2,3}$
deg_odd_var:={1,2}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="kpev_ho1_state.red"$
resname:="kpev_ho1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_y,v_y}$
% right-hand side of the differential equation
de:={v_x,u_t - u*u_x - (1/12)*u_3x}$

% same constructions for odd coordinates
principal_odd:={p_y,q_y}$
de_odd:={q_x,( - 12*p*u_x - p_3x + 12*p_t - 12*p_x*u)/12}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

;end;

