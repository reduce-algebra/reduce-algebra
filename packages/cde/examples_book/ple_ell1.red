% Plebanski equation: conservation laws on the cotangent covering
%    for non-local variables.
% 2015-10-10
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y,z}$
dep_var:={u}$
odd_var:={p}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="ple_ell1_state.red"$
resname:="ple_ell1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

% Saving cde state in a file
save_cde_state(statename)$

f_ple:={u_xz +u_ty - u_tx**2 + u_2t*u_2x}$

% Linearization
ell_function(f_ple,lple);

% computing the adjoint
adjoint_cdiffop(lple,lple_star);

off nat$
off echo$
out <<resname>>;
write "lple_sf(1):=",lple_sf(1);
write "lple_star_sf(1):=",lple_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$


;end;
