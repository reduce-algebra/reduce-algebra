% Krichever-Novikov equation: linearization and adjoint
% 2016-01-05
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
odd_var:={q}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kn_ell1_state.red"$
resname:="kn_ell1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$
% Saving cde state in a file
save_cde_state(statename)$

% the differential equation
f_kn:={u_t - (u_3x - (3/2)*((u_2x**2)/u_x))}$

% Linearization
ell_function(f_kn,lkn);

% computing the adjoint
adjoint_cdiffop(lkn,lkn_star);

off nat$
off echo$
out <<resname>>;
write "lkn_sf(1):=",lkn_sf(1);
write "lkn_star_sf(1):=",lkn_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$


;end;

