% KdV equation: local Hamiltonian operators - crack approach
% 2015-10-08

% Author: Raffaele Vitolo

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Id: $


load_package cde;

% Initialization of the jet environment of the differential equation
indep_var:={x,t}$
dep_var:={u}$
odd_var:={p}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_ho2_state.red"$
resname:="kdv_ho2_res.red"$

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

mk_cdiffop(lkdv,1,{1},1);
for all phi let lkdv(1,1,phi) = td(phi,t) - phi*u_x - u*td(phi,x) - td(phi,x,3);

total_eq:=lkdv(1,1,ansatz);

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

