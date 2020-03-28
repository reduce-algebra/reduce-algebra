% Husain Heavenly equation (\epsilon=+1): recursion operator for cosymmetries
% 2017-10-13
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,p,y,z}$
dep_var:={v,q}$
odd_var:={w1,w2}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="hh_ell1_state.red"$
resname:="hh_ell1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={v_t,q_t}$
% right-hand side of the differential equation
de:={q,
  q_z*v_py - q_y*v_pz - v_2p
}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

f_hh:=for i:=1:2 collect part(principal_der,i) - part(de,i);

% Linearization
ell_function(f_hh,lhh);

% computing the adjoint
adjoint_cdiffop(lhh,lhh_star);

off nat$
off echo$
linelength(50);
out <<resname>>;
write "lhh_sf(1):=",lhh_sf(1);
write "lhh_sf(2):=",lhh_sf(2);
write "lhh_star_sf(1):=",lhh_star_sf(1);
write "lhh_star_sf(2):=",lhh_star_sf(2);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

