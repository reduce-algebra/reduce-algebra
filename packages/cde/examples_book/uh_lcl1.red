% Universal Hierarchy equation: local conservation laws
% 2017-08-13
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="uh_lcl1_state.red"$
resname:="uh_lcl1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_2y}$
% right-hand side of the differential equation
de:={u_t*u_xy - u_y*u_tx}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% We look for conserved currents of the type
% cl = cx dtdy + cy dtdx

% List of variables in the ansatz
even_vars:=for i:=0:1 join selectvars(0,i,dep_var,all_parametric_der)$
% Dependence of the unknown functions
unk:={cx,cy};
for each el in even_vars do
<<
  depend(cx,el);
  depend(cy,el)
>>;

total_eq:={td(cx,y) - td(cy,x)}$
split_vars:=
  for i:=2:total_order join selectvars(0,i,dep_var,all_parametric_der);
load_package crack;
crack_results:=crack(total_eq,{},unk,split_vars);

off nat$
off echo$
out <<resname>>$
write "% Conservation laws of the Universal Hierarchy equation";
write "crack_results:=",crack_results;

write ";end;";
shut <<resname>>$
on echo$
on nat$

% Removal of trivial c.l. from the solution
let second first crack_results;
% Ansatz for tcl, the grading must be compatible with
% tcl = tct dt
% and dbar(tcl) = - tct_y dtdy - tct_x dtdx
%               = cx dtdy + cy dtdx
unk:={tct};
for each el in even_vars do depend(tct,el);
for each el in indep_var do depend(tct,el);

total_eq:={ - td(tct,y) - df(cx,c_17), - td(tct,x) - df(cy,c_17)}$
crack_results_triv:=crack(total_eq,{},unk,split_vars);

;end;

Local Variables:
mode:reduce
End:
