% KdV equation: linearization and its adjoint
% 2015-10-05
% Raffaele Vitolo

% Loading the interface to cdiff packages; used to generate all
% (even and odd) derivative coordinates,
% (even and odd) principal and parametric derivatives,
% and the restriction of total derivatives to the (even and odd) equation.
% Of course mostly odd part refers to tangent or cotangent covering.
in "cde.red"$

algebraic;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
odd_var:={p}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_ell1_state.red"$
resname:="kdv_ell1_res.red"$

% There is no differential equation - we work on free jets.

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$
% Saving cde state in a file
save_cde_state(statename)$

% The function that defines the KdV equation
f_kdv:={u_t - (u*u_x + u_3x)}$

% Compute the linearization, check that ell_kdv is the same as lkdv.
ell_function(f_kdv,ell_kdv);

% computing the adjoint
adjoint_cdiffop(ell_kdv,ellstar_kdv);

% The adjoint linearization in odd variables - for comparison
% - p_t + (u*p_x+p_3x)$

% For comparison check with the adjoint linearization:
mk_cdiffop(lskdv,1,{1},1);
for all phi let lskdv(1,1,phi) = - p_t + (u*p_x+p_3x);
conv_cdiff2superfun(lskdv,lskdv_sf);

% Check that lkdv and ell_kdv are the same.
lskdv_sf(1) - ellstar_kdv_sf(1);

;end;

off nat$
off echo$
out <<resname>>$
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

