% General Heavenly equation: symplectic operators
% 2017-10-11

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
dep_var:={u,v}$
odd_var:={p,q}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="gh_ell1_state.red"$
resname:="gh_ell1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t,v_t}$
% right-hand side of the differential equation
de:={v,
  (1/u_yz)*(u_2x*u_yz - u_xy*u_xz + v_y*v_z + b*(v_y*u_xz - v_z*u_xy))
}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

f_gh:=for i:=1:2 collect part(principal_der,i) - part(de,i);

% Linearization
ell_function(f_gh,lgh);

% computing the adjoint
adjoint_cdiffop(lgh,lgh_star);

off nat$
off echo$
linelength(50);
out <<resname>>;
write "lgh_sf(1):=",lgh_sf(1);
write "lgh_sf(2):=",lgh_sf(2);
write "lgh_star_sf(1):=",lgh_star_sf(1);
write "lgh_star_sf(2):=",lgh_star_sf(2);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

