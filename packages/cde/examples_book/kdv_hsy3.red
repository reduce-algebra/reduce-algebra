% KdV equation: higher symmetries; here we compute shadows of symmetries.
% 2015-12-09

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
dep_var:={u,w}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_hsy3_state.red"$
resname:="kdv_hsy3_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t,w_t,w_x}$
% right-hand side of the differential equation
de:={u*u_x+u_3x,u**2/2 + u_2x,u}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Saving cde state in a file
save_cde_state(statename)$

% This is the equation ell_K(sym)=0, where K=0 is KdV equation
% `ell' stands for linearization and sym is the generating function.
% From now on all equations are arranged in a single vector
% whose name is `equ'.

mk_cdiffop(ell_kdv,1,{1},1);
for all sym let ell_kdv(1,1,sym) = td(sym,t)-u*td(sym,x)-u_x*sym-td(sym,x,3);

% Define an ansatz for sym
ansatz_vars:=for i:=0:5 join selectvars(0,i,dep_var,all_parametric_der)$
for each el in ansatz_vars do depend sym,el;
for each el in indep_var do depend sym,el;
split_vars:=cde_difflist(all_parametric_der,ansatz_vars)$

unk:={sym}$
lin_eq:={ell_kdv(1,1,sym)}$
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
