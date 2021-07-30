% KdV equation: cosymmetries
% 2015-12-01
% Raffaele Vitolo
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

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u}$
odd_var:={}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_csy1_state.red"$
resname:="kdv_csy1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,{},{}})$

% Saving cde state in a file
save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% This is the equation ell^*_K(csy)=0, where K=0 is KdV equation
% `ell^*' stands for the formal adjoint of linearization
% and csy is the generating function.

mk_cdiffop(ellstar_k,1,{1},1);
for all csy let ellstar_k(csy) = td(csy,t) - u*td(csy,x) - td(csy,x,3);

% We require that psi depend on dependent variables only.
for each el in dep_var do depend psi,el;

split_vars:=
  for i:=1:total_order join selectvars(0,i,dep_var,all_parametric_der);

% Here we write results of the computation in a file.
system_eq:=ellstar_k(psi)$
unk:={psi};

load_package crack;
crack_results:=crack(system_eq,{},unk,
   split_vars);

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write crack_results:=crack_results;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;
