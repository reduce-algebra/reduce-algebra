% Camassa-Holm equation: linearization and adjoint
% 2015-11-09
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x}$
dep_var:={u}$
odd_var:={p}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="ch_ell1_state.red"$
resname:="ch_ell1_res.red"$

% There is no differential equation - we work on free jets.

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$
% Saving cde state in a file
save_cde_state(statename)$

% The function that defines the Camassa-Holm equation
f_ch:={alpha*(u_t + 3*u*u_x) - u_t2x - 2*u_x*u_2x - u*u_3x}$

% Linearization
ell_function(f_ch,lch);

% computing the adjoint
adjoint_cdiffop(lch,lch_star);
% please check that lbou_star_sf is the generating function
% of the adjoint linearization as above.

off nat$
off echo$
out <<resname>>;
write "lch_sf(1):=",lch_sf(1);
write "lch_star_sf(1):=",lch_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: