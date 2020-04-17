% Heat equation: Nijenhuis bracket of the recursion operator
% 2017-10-22
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x}$
dep_var:={u}$
odd_var:={q}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="h_nb1_state.red"$
resname:="h_nb1_res.red"$

% Initialization of the differential equation.
principal_der:={u_t}$
de:={u_2x}$
principal_odd:={q_t}$
de_odd:={q_2x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
  {principal_der,de,principal_odd,de_odd})$

% Saving cde state in a file
save_cde_state(statename)$

% Defining the linearization
mk_superfun(rh_sf,1,1);
rh_sf(1) := t*q_x + (1/2)*x*q;

% Computing the Nijenhuis bracket
nijenhuis_bracket(rh_sf,rh_sf,res_biv);

off nat$
off echo$
out <<resname>>$
write res_biv(1):=res_biv(1);
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

