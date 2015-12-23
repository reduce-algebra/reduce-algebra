% Burgers equation: higher symmetries (CRACK's approach)
% 2010-10-05
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
total_order:=10$
% names for output of the state of cde and results of computations
statename:="bur_hsy2_state.red"$
resname:="bur_hsy2_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u_2x+2*u*u_x}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$
% Saving cde state in a file
save_cde_state(statename)$

% This is the operator ell_B(sym), where B=0 is Burgers'equation,
% `ell' stands for linearization or Frechet derivative.

operator ell_b$
for all sym let ell_b(sym)=td(sym,t)-td(sym,x,2)-2*u*td(sym,x)-2*u_x*sym$

% This is the list of variables from which the unknown function `ansatz' depends
even_vars:=for i:=0:3 join selectvars(0,i,dep_var,all_parametric_der)$
for each el in even_vars do depend(ansatz,el)$
split_vars:=cde_difflist(all_parametric_der,even_vars)$

total_eq:=ell_b(ansatz)$
check_letop({total_eq})$

load_package crack;
crack_results:=crack(total_eq,{},{ansatz},split_vars);

% Here we write results of the computation in a file.

off echo$
off nat$
out <<resname>>;
write crack_results;
write ";end;";
shut <<resname>>;
on nat$
on echo$

;end;
