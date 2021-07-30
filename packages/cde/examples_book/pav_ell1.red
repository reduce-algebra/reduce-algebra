% Pavlov equation: linearization and adjoint
% 2016-01-14

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
indep_var:={t,x,y}$
dep_var:={u,v}$
odd_var:={p,q}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="pav_ell1_state.red"$
resname:="pav_ell1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

% Saving cde state in a file
save_cde_state(statename)$

% The KP equation

% left-hand side of the differential equation
f_pav:={u_2y - (u_tx + u_y*u_2x - u_x*u_xy),
 v_2y - (v_tx + u_y*v_2x - u_x*v_xy + 2*(u_xy*v_x - u_2x*v_y))}$

% Linearization
ell_function(f_pav,lpav);

% computing the adjoint
adjoint_cdiffop(lpav,lpav_star);

off nat$
off echo$
out <<resname>>;
write "lpav_sf(1):=",lpav_sf(1);
write "lpav_sf(2):=",lpav_sf(2);
write "lpav_star_sf(1):=",lpav_star_sf(1);
write "lpav_star_sf(2):=",lpav_star_sf(2);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

