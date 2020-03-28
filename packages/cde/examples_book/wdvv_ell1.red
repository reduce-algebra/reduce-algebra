% WDVV equation in 1 component: local symplectic operator
% See Kersten, Krasilshchik, Verbovetsky, Vitolo.
% 2016-01-06

load_package cde;

indep_var:={x,y}$
dep_var:={u}$
odd_var:={q}$
total_order:=10$
resname:="wdvv_ell1_res.red"$
statename:="wdvv_ell1_state.red"$

% We work on free jets.

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

save_cde_state(statename)$

% the differential equation
f_wdvv:={u_3y - u_2xy**2 + u_3x*u_x2y}$

% Linearization
ell_function(f_wdvv,lwdvv);

% computing the adjoint
adjoint_cdiffop(lwdvv,lwdvv_star);
% please check that lbou_star_sf is the generating function
% of the adjoint linearization as above.

off nat$
off echo$
out <<resname>>;
write "lwdvv_sf(1):=",lwdvv_sf(1);
write "lwdvv_star_sf(1):=",lwdvv_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;
