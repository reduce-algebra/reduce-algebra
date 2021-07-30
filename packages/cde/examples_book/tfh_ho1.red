% Three-field hierarchy: local Hamiltonian operator
% 2017-10-10

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
dep_var:={u,v,w}$
odd_var:={p,q,r}$
deg_indep_var:={-1,-1,-1}$
deg_dep_var:={1,1,1}$
deg_odd_var:={1,1,1}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="tfh_ho1_state.red"$
resname:="tfh_ho1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_t,v_t,w_t}$
% right-hand side of the differential equation
de:={ u_y + 2*v_x,u*v_x + 2*w_x,u_x*w + u*w_x}$

% same constructions for odd coordinates;
principal_odd:={p_t,q_t,r_t}$
de_odd:={
p_y - q*v_x + r_x*w,
2*p_x + q*u_x + q_x*u,
2*q_x + r_x*u}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;
nc:=length(dep_var);

% List of variables ordered by gradings
l_grad_mon:=der_deg_ordering(0,all_parametric_der)$
l_grad_odd:={1} . der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
gradmon:=graded_mon(1,5,l_grad_mon)$
gradmon:={1} . gradmon$
% list of graded monomials which are linear in odd variables
% and have total degree from 1 to 8
linodd:=mkalllinodd(gradmon,l_grad_odd,1,3)$
% Ansatz for local Hamiltonian operators
operator phi;
for i:=1:nc do phi(i):=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% equation for shadows of nonlocal symmetries in \ell^*-covering
mk_superfun(ltfh_sf,1,3);
ltfh_sf(1):=p_t - p_y - 2*q_x$
ltfh_sf(2):= - p*v_x + q_t - q_x*u - 2*r_x$
ltfh_sf(3):= - p*w_x - p_x*w - r*u_x + r_t - r_x*u$
conv_superfun2cdiff(ltfh_sf,ltfh);

for i:=1:nc do
equ(i):=for j:=1:nc sum ltfh(i,j,phi(j));

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=3;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,3);

tel2:=splitvars_opequ(equ,4,tel,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

off nat$
off echo$
out <<resname>>;
write "operator phi;";
phi(1):=phi(1);
phi(2):=phi(2);
phi(3):=phi(3);
write ";end;";
shut <<resname>>;
on echo$
on nat$

% Generate a superfunction with the Hamiltonian operator
mk_superfun(ham1_sf,1,3);
for i:=1:nc do
  ham1_sf(i):=df(phi(i),c(15));
conv_superfun2cdiff(ham1_sf,ham1);
adjoint_cdiffop(ham1,ham1_star);
for i:=1:nc do if ham1_star_sf(i) + ham1_sf(i) neq 0 then
  write "Non self-adjoint operator";

% Conversion into bivector
conv_genfun2biv(ham1_sf,biv1);

% Computes the Schouten bracket followed by the Euler operator
% to check if the expression is a total divergence;
% returns the list of even and odd variational derivatives.
iszero_schouten_bracket(biv1,biv1,thr11);

;end;

Local Variables:
mode:reduce
End: