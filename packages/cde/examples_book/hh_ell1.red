% Husain Heavenly equation (\epsilon=+1): recursion operator for cosymmetries
% 2017-10-13

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
indep_var:={t,p,y,z}$
dep_var:={v,q}$
odd_var:={w1,w2}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="hh_ell1_state.red"$
resname:="hh_ell1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={v_t,q_t}$
% right-hand side of the differential equation
de:={q,
  q_z*v_py - q_y*v_pz - v_2p
}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

f_hh:=for i:=1:2 collect part(principal_der,i) - part(de,i);

% Linearization
ell_function(f_hh,lhh);

% computing the adjoint
adjoint_cdiffop(lhh,lhh_star);

off nat$
off echo$
linelength(50);
out <<resname>>;
write "lhh_sf(1):=",lhh_sf(1);
write "lhh_sf(2):=",lhh_sf(2);
write "lhh_star_sf(1):=",lhh_star_sf(1);
write "lhh_star_sf(2):=",lhh_star_sf(2);
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

