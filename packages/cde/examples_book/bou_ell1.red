% Dispersionless Boussinesq equation: linearization and adjoint
% 2015-11-09

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
dep_var:={u,v,w}$
odd_var:={p,q,r}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="bou_ell1_state.red"$
resname:="bou_ell1_res.red"$

% There is no differential equation - we work on free jets.

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$
% Saving cde state in a file
save_cde_state(statename)$

% The function that defines the Boussinesq equation
f_bou:={u_t - w*w_x - v_x,v_t + u*w_x + 3*w*u_x,w_t - u_x}$

% Linearization
ell_function(f_bou,lbou);

% computing the adjoint
adjoint_cdiffop(lbou,lbou_star);
% please check that lbou_star_sf is the generating function
% of the adjoint linearization as above.

off nat$
off echo$
out <<resname>>;
write "lbou_sf(1):=",lbou_sf(1);
write "lbou_sf(2):=",lbou_sf(2);
write "lbou_sf(3):=",lbou_sf(3);
write "lbou_star_sf(1):=",lbou_star_sf(1);
write "lbou_star_sf(2):=",lbou_star_sf(2);
write "lbou_star_sf(3):=",lbou_star_sf(3);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: