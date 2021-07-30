% WDVV equation in 1 component: local symplectic operator
% See Kersten, Krasilshchik, Verbovetsky, Vitolo.
% 2016-01-06

% Author: R Vitolo.

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

indep_var:={x,y}$
dep_var:={u}$
odd_var:={q}$
total_order:=10$
resname:="wdvv_ell1_res.red"$
statename:="wdvv_ell1_state.red"$

% We work on free jets.

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

save_cde_state(statename)$

% the differential equation
f_wdvv:={u_3y - u_2xy**2 + u_3x*u_x2y}$

% Linearization
ell_function(f_wdvv,lwdvv);

% computing the adjoint
adjoint_cdiffop(lwdvv,lwdvv_star);
% please check that lbou_star_sf is the generating function
% of the adjoint linearization as above.

off nat$
off echo$
out <<resname>>;
write "lwdvv_sf(1):=",lwdvv_sf(1);
write "lwdvv_star_sf(1):=",lwdvv_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;
