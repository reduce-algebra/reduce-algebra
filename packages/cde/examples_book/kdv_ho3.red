% KdV equation: local Hamiltonian operators, verification of skew-adjointness
% and computation of Schouten bracket
% 2015-10-08

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
statename:="kdv_ho3_state.red"$
resname:="kdv_ho3_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% same construction for odd coordinates
principal_odd:={p_t}$
de_odd:={u*p_x+p_3x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$
% Saving cde state in a file
save_cde_state(statename)$

% Define the two Hamiltonian operators for KdV
mk_cdiffop(ham1,1,{1},1);
for all psi1 let ham1(1,1,psi1)=td(psi1,x);
mk_cdiffop(ham2,1,{1},1);
for all psi2 let ham2(1,1,psi2)=(1/3)*u_x*psi2 + td(psi2,x,3)
 + (2/3)*u*td(psi2,x);
% Note: one could equivalently load the operators as superfunctions
% and convert them to operators.

% Convert the two Hamiltonian operators to superfunctions:
conv_cdiff2superfun(ham1,sym1);
conv_cdiff2superfun(ham2,sym2);

% Computes the adjoint and verify skew-adjointness:
adjoint_cdiffop(ham1,ham1_star);
adjoint_cdiffop(ham2,ham2_star);
ham1_star_sf(1)+sym1(1);
ham2_star_sf(1)+sym2(1);

% The last two commands must return 0.

% Defines the previously computed Hamiltonian operators,
% the user may check that they are the same as sym1(1) and sym2(1)
sym1_odd := {p_x};
sym2_odd := {(1/3)*p*u_x + p_3x + (2/3)*p_x*u};

% Converts the two operators to bivectors
conv_genfun2biv(sym1,biv1);
conv_genfun2biv(sym2,biv2);

% Check the expressions of the bivectors
biv1(1);
biv2(1);

% Computes variational derivatives
pvar_df(0,biv1(1),u);
pvar_df(1,biv1(1),p);
pvar_df(0,biv2(1),u);
pvar_df(1,biv2(1),p);

% Computes the Schouten bracket of the operators;
schouten_bracket(biv1,biv1,thr11);
thr11(1);
schouten_bracket(biv1,biv2,thr12);
thr12(1);
schouten_bracket(biv2,biv2,thr22);
thr22(1);

% Check if the above third nonzero bracket expression is
% zero in cohomology, i.e., is a total divergence
euler_df(thr22(1));

% Computes the Schouten bracket followed by the Euler operator
% to check if the expression is a total divergence;
% returns the list of even and odd variational derivatives.
iszero_schouten_bracket(biv1,biv1,thr11b);
iszero_schouten_bracket(biv1,biv2,thr12b);
iszero_schouten_bracket(biv2,biv2,thr22b);

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write "thr11:=",thr11;
write "thr12:=",thr12;
write "thr22:=",thr22;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

