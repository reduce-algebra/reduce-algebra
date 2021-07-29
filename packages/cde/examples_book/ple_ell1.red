% Plebanski equation: conservation laws on the cotangent covering
%    for non-local variables.
% 2015-10-10

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
indep_var:={t,x,y,z}$
dep_var:={u}$
odd_var:={p}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="ple_ell1_state.red"$
resname:="ple_ell1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

% Saving cde state in a file
save_cde_state(statename)$

f_ple:={u_xz +u_ty - u_tx**2 + u_2t*u_2x}$

% Linearization
ell_function(f_ple,lple);

% computing the adjoint
adjoint_cdiffop(lple,lple_star);

off nat$
off echo$
out <<resname>>;
write "lple_sf(1):=",lple_sf(1);
write "lple_star_sf(1):=",lple_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$


;end;
