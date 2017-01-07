% KdV equation: local Hamiltonian operators, verification of skew-adjointness
% and computation of Schouten bracket
% 2015-10-08
% Raffaele Vitolo

%% on comp, echo, backtrace;
load_package cde;
%% in "cde_add";
%% algebraic;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
odd_var:={p}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_lho3_state.red"$
resname:="kdv_lho3_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% same construction for odd coordinates
principal_odd:={p_t}$
de_odd:={u*p_x+p_3x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$
% Saving cde state in a file
save_cde_state(statename)$

% Define the two Hamiltonian operators for KdV
mk_cdiffop(ham1,1,{1},1);
for all psi1 let ham1(1,1,psi1)=td(psi1,x);
mk_cdiffop(ham2,1,{1},1);
for all psi2 let ham2(1,1,psi2)=(1/3)*u_x*psi2 + td(psi2,x,3)
 + (2/3)*u*td(psi2,x);
% Note: one could equivalently load the operators as superfunctions
% and convert them to operators.

% Convert the two Hamiltonian operators to superfunctions:
conv_cdiff2superfun(ham1,sym1);
conv_cdiff2superfun(ham2,sym2);

% Computes the adjoint and verify skew-adjointness:
adjoint_cdiffop(ham1,ham1_star);
adjoint_cdiffop(ham2,ham2_star);
ham1_star_sf(1)+sym1(1);
ham2_star_sf(1)+sym2(1);

% The last two commands must return 0.

% Defines the previously computed Hamiltonian operators,
% the user may check that they are the same as sym1(1) and sym2(1)
sym1_odd := {p_x};
sym2_odd := {(1/3)*p*u_x + p_3x + (2/3)*p_x*u};

% Converts the two operators to bivectors
conv_genfun2biv(sym1,biv1);
conv_genfun2biv(sym2,biv2);

% Computes the Schouten bracket of the operators;
iszero_schouten_bracket(biv1,biv1,sb11);
iszero_schouten_bracket(biv1,biv2,sb12);
iszero_schouten_bracket(biv2,biv2,sb22);

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write sb11(1):=sb11(1);
write sb12(1):=sb12(1);
write sb22(1):=sb22(1);
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

