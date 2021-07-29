% Camassa-Holm equation: symplectic operator
% 2016-01-13

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
odd_var:={q,o1,o2}$
deg_indep_var:={-2,-1}$
deg_dep_var:={1}$
deg_odd_var:={1,2,3}$
total_order:=8$
principal_der:={u_3x}$
de:={(alpha*(u_t + 3*u*u_x) - u_t2x - 2*u_x*u_2x)/u}$

% The nonlocal odd variables
o1x:=alpha*q$
o1t:=(u_2x - 3*u*alpha)*q + u_x*q_x +u*q_2x +q_tx$

o2x:=(alpha*u - u_2x)*q$
o2t:=((u_2x - 3*u*alpha)*u + u*u_2x)*q + (u_x*u - u*u_x)*q_x
  +u**2*q_2x - u_x*q_t +u*q_tx$

principal_odd:={q_3x,o1_x,o1_t,o2_x,o2_t}$
de_odd:={( - alpha*q*u_t + alpha*q_t*u + 3*alpha*q_x*u**2 + 2*q*u_2x*u_x
  + q*u_t2x - 2*q_2x*u*u_x - q_t2x*u - 2*q_x*u*u_2x)/u**2,
  o1x,o1t,o2x,o2t}$

% names for output of the state of cde and results of computations
statename:="ch_sympl1_state.red"$
resname:="ch_sympl1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
  {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

% Defining the superfunction corresponding with adjoint linearization operator
mk_superfun(lch_star_sf,1,1);
lch_star_sf(1):= - alpha*q_t - 3*alpha*q_x*u + q_2x*u_x + q_3x*u + q_t2x + q_x*
u_2x$
conv_superfun2cdiff(lch_star_sf,lch_star);

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% List of variables ordered by gradings
l_grad_mon:=der_deg_ordering(0,all_parametric_der)$
l_grad_odd:=der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
gradmon:=graded_mon(1,10,l_grad_mon)$
gradmon:=part(gradmon,2):=alpha . part(gradmon,2)$
gradmon:={1} . gradmon$

l_grad_odd:={1} . l_grad_odd$
% list of graded monomials which are linear in odd variables
% and have total degree from 1 to 6
linodd:=mkalllinodd(gradmon,l_grad_odd,1,6)$
% Ansatz for recursion operators

phi:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% Equation for shadows of cosymmetries on the tangent covering
equ 1:=num lch_star(1,1,phi)$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=1;

% We need to solve irrespectively of the values of alpha
off coefficient_check;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars in order to obtain equations on
% coefficients of each monomial.

tel:=splitext_opequ(equ,1,1);

tel2:=splitvars_opequ(equ,2,tel,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write phi:=phi;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;
