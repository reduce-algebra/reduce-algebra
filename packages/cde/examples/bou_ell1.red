% Dispersionless Boussinesq equation: linearization and adjoint
% 2014-12-22
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u,v}$
odd_var:={p,q}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="bou_ell1_state.red"$
resname:="bou_ell1_res.red"$

% There is no differential equation - we work on free jets.

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$
% Saving cde state in a file
save_cde_state(statename)$

% The function that defines the Boussinesq equation
f_bou:={u_t - (u_x*v + u*v_x + sig*v_3x),v_t - (u_x + v*v_x)}$

% Linearization
ell_function(f_bou,lbou);

% Check that lbou_sf is the superfunction of the linearization
% by introducing the linearization and converting it to a superfunction

mk_cdiffop(lbou2,1,{2},2);
for all phi let lbou2(1,1,phi)=td(phi,t) - v*td(phi,x) - v_x*phi;
for all phi let lbou2(1,2,phi)= - u_x*phi - u*td(phi,x) - sig*td(phi,x,3);
for all phi let lbou2(2,1,phi)= - td(phi,x);
for all phi let lbou2(2,2,phi)=td(phi,t) - v*td(phi,x) - v_x*phi;

conv_cdiff2superfun(lbou2,lbou2_sf);

% Check that lbou1 and lbou2 are the same by means of
% the corresponding superfunctions

for i:=1:length(dep_var) do
  if lbou2_sf(i) - lbou_sf(i) neq 0 then write "Error!";

% computing the adjoint
adjoint_cdiffop(lbou,lbou_star);
% please check that lbou_star_sf is the generating function
% of the adjoint linearization as above.

off nat$
off echo$
out <<resname>>;
write "lbou_sf(1):=",lbou_sf(1);
write "lbou_sf(2):=",lbou_sf(2);
write "lbou_star_sf(1):=",lbou_star_sf(1);
write "lbou_star_sf(2):=",lbou_star_sf(2);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: