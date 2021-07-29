% KdV equation: local symplectic operators,
% computation of the variational differential
% 2016-01-05

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
odd_var:={q}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kn_sympl1_state.red"$
resname:="kn_sympl1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u_3x - (3/2)*((u_2x**2)/u_x)}$

% same construction for odd coordinates
principal_odd:={q_t}$
de_odd:={q_3x + (3/2)*((u_2x**2)/(u_x**2))*q_x - 3*(u_2x/u_x)*q_2x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$
% Saving cde state in a file
save_cde_state(statename)$

% The adjoint linearization
mk_superfun(lkn_star_sf,1,1);
lkn_star_sf(1):=(6*q*u_2x**3 - 12*q*u_2x*u_3x*u_x + 6*q*u_4x*u_x**2 + 6*q_2x*
u_2x*u_x**2 + 2*q_3x*u_x**3 - 2*q_t*u_x**3 - 9*q_x*u_2x**2*u_x + 12*q_x*u_3x*u_x
  **2)/(2*u_x**3)$
conv_superfun2cdiff(lkn_star_sf,lkn_star);

% Define the candidate symplectic operator
mk_superfun(symp,1,1);
symp(1):=(1/(u_x**2))*q_x - (u_2x/(u_x**3))*q;

% Check that symp is a shadow of symmetry on the cotangent covering
lkn_star(1,1,symp(1));

% Computes the adjoint and verify skew-adjointness:
conv_superfun2cdiff(symp,symp_op);
adjoint_cdiffop(symp_op,symp_op_star);
% We recall that the above command creates two superfunctions,
% symp_op_sf that is equal to symp in our case and
% symp_op_star_sf which corresponds to the adjoint operator symp_op_star
symp_op_star_sf(1) + symp(1);

% The last two commands must return 0.

% Converts the symplectic operator to a variational form
conv_genfun2vform(symp,vform_symp);

% Compute the Cartan differential
cartan_df(vform_symp,dc_vform_symp);

dc_vform_symp(1);

% Computes the variational derivatives of the operator;
variational_df(vform_symp,vform_res);

vform_res(1);

;end;

