% KP equation: local Hamiltonian operators
% 2015-10-09

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
dep_var:={u,v}$
odd_var:={p,q}$
deg_indep_var:={-3,-1,-2}$
deg_dep_var:={2,3}$
deg_odd_var:={2,1}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="kpev_ho1_state.red"$
resname:="kpev_ho1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_y,v_y}$
% right-hand side of the differential equation
de:={v_x,u_t - u*u_x - (1/12)*u_3x}$

% same constructions for odd coordinates
principal_odd:={p_y,q_y}$
de_odd:={( - q_3x + 12*q_t - 12*q_x*u)/12,p_x}$

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

% List of variables ordered by gradings
l_grad_mon:=der_deg_ordering(0,all_parametric_der)$
l_grad_odd:={1} . der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
gradmon:=graded_mon(1,10,l_grad_mon)$
gradmon:={1} . gradmon$
% list of graded monomials which are linear in odd variables
% and have total degree from 1 to 5
linodd:=mkalllinodd(gradmon,l_grad_odd,1,5)$
% Ansatz for local Hamiltonian operators
psi1:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$
psi2:=(for each el in linodd sum (c(ctel:=ctel+1)*el))$

% Equation for shadows of symmetries in the cotangent covering
mk_superfun(lkpev_sf,1,2);
lkpev_sf(1):=p_y - q_x$
lkpev_sf(2):=(12*p*u_x + p_3x - 12*p_t + 12*p_x*u + 12*q_y)/12$
conv_superfun2cdiff(lkpev_sf,lkpev)$

equ 1:=lkpev(1,1,psi1) + lkpev(1,2,psi2)$
equ 2:=lkpev(2,1,psi1) + lkpev(2,2,psi2)$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=2$

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0})$

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,2);

tel2:=splitvars_opequ(equ,3,tel,vars);

put_equations_used tel2$

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i$

off nat$
off echo$
out <<resname>>$
psi1:=psi1;
psi2:=psi2;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

