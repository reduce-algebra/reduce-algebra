% Camassa-Holm equation: linearization and adjoint
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
indep_var:={t,x}$
dep_var:={u}$
odd_var:={p}$
total_order:=8$
principal_der:={u_3x}$
de:={(alpha*(u_t + 3*u*u_x) - u_t2x - 2*u_x*u_2x)/u}$
% names for output of the state of cde and results of computations
statename:="ch_ell2_state.red"$
resname:="ch_ell2_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{principal_der,de,{},{}})$
% Saving cde state in a file
save_cde_state(statename)$

% Defining superfunctions corresponding with linearization operator
% and its adjoint
mk_superfun(lch_sf,1,1);
mk_superfun(lch_star_sf,1,1);
in "ch_ell1_res.red";

lch_sf(1):=restrict_to_equation(lch_sf(1));
lch_star_sf(1):=restrict_to_equation(lch_star_sf(1));

conv_superfun2cdiff(lch_sf,lch);
conv_superfun2cdiff(lch_star_sf,lch_star);

off nat$
off echo$
out <<resname>>;
write "lch_sf(1):=",lch_sf(1);
write "lch_star_sf(1):=",lch_star_sf(1);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: