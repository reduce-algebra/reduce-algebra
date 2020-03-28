% Three-field hierarchy: local Hamiltonian operator
% 2017-10-10
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u,v,w}$
odd_var:={p,q,r}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="tfh_ell1_state.red"$
resname:="tfh_ell1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_t,v_t,w_t}$
% right-hand side of the differential equation
de:={ u_y + 2*v_x,u*v_x + 2*w_x,u_x*w + u*w_x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

% Saving cde state in a file
save_cde_state(statename)$

% The function that defines the equation
f_tfh:=for i:=1:3 collect part(principal_der,i) - part(de,i)$

% Linearization
ell_function(f_tfh,ltfh);

% computing the adjoint
adjoint_cdiffop(ltfh,ltfh_star);
% please check that lbou_star_sf is the generating function
% of the adjoint linearization as above.

off nat$
off echo$
out <<resname>>;
write "ltfh_sf(1):=",ltfh_sf(1);
write "ltfh_sf(2):=",ltfh_sf(2);
write "ltfh_sf(3):=",ltfh_sf(3);
write "ltfh_star_sf(1):=",ltfh_star_sf(1);
write "ltfh_star_sf(2):=",ltfh_star_sf(2);
write "ltfh_star_sf(3):=",ltfh_star_sf(3);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: