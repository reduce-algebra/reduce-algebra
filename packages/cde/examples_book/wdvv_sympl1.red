% WDVV equation in 1 component: local symplectic operator
% See Kersten, Krasilshchik, Verbovetsky, Vitolo.
% 2016-01-06

% Author: R Vitoto

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
resname:="wdvv_symp1_res.red"$

% left-hand side of the differential equation
principal_der:={u_3y}$
% right-hand side of the differential equation
de:={u_2xy**2 - u_3x*u_x2y}$

% same constructions for odd coordinates
principal_odd:={q_3y}$
de_odd:={2*u_2xy*q_2xy - q_3x*u_x2y - u_3x*q_x2y}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$
% Saving cde state in a file
% save_cde_state(statename)$

% introducing the adjoint linearization
mk_superfun(lwdvv_star_sf,1,1);
lwdvv_star_sf(1):= - u_2x2y*q_2x + 2*u_2xy*q_2xy - u_3x*q_x2y + 2*u_3xy*q_xy - 
u_4x*q_2y - u_x2y*q_3x - q_3y$
conv_superfun2cdiff(lwdvv_star_sf,lwdvv_star);

% Checking that q_x is a symplectic operator
lwdvv_star(1,1,q_x);

;end;

Local Variables:
mode:reduce
End:
