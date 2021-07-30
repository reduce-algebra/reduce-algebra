% Pavlov equation: local higher symmetries
% 2016-01-14

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
deg_indep_var:={-5,-1,-3}$
deg_dep_var:={1,1}$
deg_odd_var:={0,0}$
total_order:=10$
principal_der:={u_2y,v_2y}$
de:={u_tx + u_y*u_2x - u_x*u_xy,
 v_tx + u_y*v_2x - u_x*v_xy + 2*(u_xy*v_x - u_2x*v_y)}$

% names for output of the state of cde and results of computations
statename:="pav_hsy1_state.red"$
resname:="pav_hsy1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{principal_der,de,{},{}})$
% Saving cde state in a file
save_cde_state(statename)$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Loading the linearization
mk_superfun(lpav_sf,1,2);
lpav_sf(1):= - p_2x*u_y + p_2y - p_tx + p_x*u_xy + p_xy*u_x - p_y*u_2x$
lpav_sf(2):=2*p_2x*v_y + p_x*v_xy - 2*p_xy*v_x - p_y*v_2x - q_2x*u_y + q_2y - 
q_tx - 2*q_x*u_xy + q_xy*u_x + 2*q_y*u_2x$
conv_superfun2cdiff(lpav_sf,lpav);

% Defining an ansatz for the two-component symmetry
phiu:=0;
% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% List of lists of variables ordered by gradings
l_grad_mon:=der_deg_ordering(0,all_parametric_der)$
% List of lists of graded monomials of scale degree <= 8
gradmon:=graded_mon(1,8,l_grad_mon)$
gradmon:={1} . gradmon$
ansatz:=for each el in gradmon join el$

% we assume a generating function with components of degree <= 8
phiv:=for each el in ansatz sum c(ctel:=ctel+1)*el$
unk:={phiu,phiv}$

% Define the equations
nc:=length(dep_var);
equ 1:=for j:=1:nc sum lpav(1,j,part(unk,j))$
equ 2:=for j:=1:nc sum lpav(2,j,part(unk,j))$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=2;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedure splitvars in order to obtain equations on coefficients
% of each monomial.

tel:=splitvars_opequ(equ,1,2,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=3:tel do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
phiu:=phiu;
phiv:=phiv;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

