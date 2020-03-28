% KP equation: linearization and adjoint
% 2015-10-09
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u}$
odd_var:={p}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="kp_ell1_state.red"$
resname:="kp_ell1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

% Saving cde state in a file
save_cde_state(statename)$

% The KP equation

% left-hand side of the differential equation
f_kp:={u_2y - (u_tx-u_x**2-u*u_2x-(1/12)*u_4x)}$

% Linearization
ell_function(f_kp,lkp);

% computing the adjoint
adjoint_cdiffop(lkp,lkp_star);

off nat$
off echo$
out <<resname>>;
write "lkp_sf(1):=",lkp_sf(1);
write "lkp_star_sf(1):=",lkp_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

