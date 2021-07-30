% KdV equation: linearization and its adjoint
% 2015-10-05

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

