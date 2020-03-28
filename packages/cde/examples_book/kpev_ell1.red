% KP equation in evolutionary form: linearization and adjoint
% 2015-10-09
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u,v}$
odd_var:={p,q}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="kpev_ell1_state.red"$
resname:="kpev_ell1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

% Saving cde state in a file
save_cde_state(statename)$

% The KP equation

% left-hand side of the differential equation
f_kpev:={u_y - v_x,v_y - (u_t - u*u_x - (1/12)*u_3x)};

% Linearization
ell_function(f_kpev,lkpev);

% computing the adjoint
adjoint_cdiffop(lkpev,lkpev_star);

off nat$
off echo$
out <<resname>>;
write "lkpev_sf(1):=",lkpev_sf(1);
write "lkpev_sf(2):=",lkpev_sf(2);
write "lkpev_star_sf(1):=",lkpev_star_sf(1);
write "lkpev_star_sf(2):=",lkpev_star_sf(2);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

