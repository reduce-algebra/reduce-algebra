% KdV equation: local Hamiltonian operators
% 2015-10-08
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation
indep_var:={x,t}$
dep_var:={u}$
odd_var:={p}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_lho2_state.red"$
resname:="kdv_lho2_res.red"$

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

% Variables for constructing the ansatz
even_vars:=for i:=0:3 join selectvars(0,i,dep_var,all_parametric_der)$
odd_vars:=for i:=0:3 join selectvars(1,i,odd_var,all_parametric_odd)$

% Generate the ansatz
ctemp:=0$
ansatz:=for each el in odd_vars sum mkid(s,ctemp:=ctemp+1)*el$

% List of unknown coefficients in the ansatz
unk:=for i:=1:ctemp collect mkid(s,i)$
for each ell in unk do
 for each el in even_vars do depend ell,el$

% This is the equation \tilde\ell_K(sym)=0, where K=0 is KdV equation,
% \tilde\ell stands for lnearization lifted on the cotangent covering
% and sym is the generating function. From now on all equations
% are arranged in a single vector whose name is `equ'.

operator ell_f$
for all sym let ell_f(sym)=
   td(sym,t) - u*td(sym,x) - u_x*sym - td(sym,x,3)$

total_eq:=ell_f(ansatz)$
system_eq:=splitext_list({total_eq})$

load_package crack;
crack_results:=crack(system_eq,{},unk,
   cde_difflist(all_parametric_der,even_vars));

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write ansatz_odd:=replace_extodd(ansatz);
write crack_results:=crack_results;
write ";end;";
shut <<resname>>$
on echo$
on nat$


;end;

