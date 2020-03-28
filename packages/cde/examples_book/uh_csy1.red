% Universal Hierarchy equation: cosymmetries
% 2017-08-20
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="uh_csy1_state.red"$
resname:="uh_csy1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_2y}$
% right-hand side of the differential equation
de:={u_t*u_xy - u_y*u_tx}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Saving cde state in a file
% save_cde_state(statename)$

% We define the operator `ellstar_uh', which is
% the adjoint linearization operator:
mk_cdiffop(ellstar_uh,1,{1},1);
for all psi let
  ellstar_uh(1,1,psi) = td(psi,y,2) - u_t*td(psi,x,y) + u_y*td(psi,x,t)
    - 2*u_tx*td(psi,y) + 2*u_xy*td(psi,t);

% Define an ansatz for psi: we want a function of u and its first derivatives,
% with an additional dependency on t,x,y
ansatz_vars:=for i:=0:1 join selectvars(0,i,dep_var,all_parametric_der)$
for each el in ansatz_vars do depend psi,el;
depend psi,t,x,y;
split_vars:=cde_difflist(all_parametric_der,ansatz_vars)$

unk:={psi}$

% This is the equation ellstar_uh(psi)=0, where uh=0 is UH equation
lin_eq:={ellstar_uh(1,1,psi)}$

system_eq:=splitvars_list(lin_eq,split_vars)$
load_package crack;
crack_sol:=crack(system_eq,{},unk,{});

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write crack_sol:=crack_sol;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End:
