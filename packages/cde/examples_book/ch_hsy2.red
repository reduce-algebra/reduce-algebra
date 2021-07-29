% Camassa-Holm equation: higher symmetries
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
dep_var:={u,s1,s2}$
odd_var:={q}$
deg_indep_var:={-2,-1}$
deg_dep_var:={1,2,3}$
deg_odd_var:={1}$
total_order:=8$

% Nonlocal variables

s1x:=alpha*u - u_2x$
s1t:=u*u_2x + (1/2)*(u_x**2 - 3*alpha*(u**2))$

s2x:=alpha*(u**2) - u*u_2x$
s2t:= - 2*alpha*(u**3) + 2*(u**2)*u_2x + u*u_tx - u_t*u_x$


principal_der:={u_3x,s1_x,s1_t,s2_x,s2_t}$
de:={(alpha*(u_t + 3*u*u_x) - u_t2x - 2*u_x*u_2x)/u,
  s1x,s1t,s2x,s2t}$

% names for output of the state of cde and results of computations
statename:="ch_sym2_state.red"$
resname:="ch_sym2_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
  {principal_der,de,{},{}})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,{})$

% Saving cde state in a file
save_cde_state(statename)$

% Defining the superfunction corresponding with linearization operator
mk_superfun(lch_sf,1,1);
lch_sf(1):=( - alpha*q*u_t + alpha*q_t*u + 3*alpha*q_x*u**2 + 2*q*u_2x*u_x + q*
u_t2x - 2*q_2x*u*u_x - q_3x*u**2 - q_t2x*u - 2*q_x*u*u_2x)/u$
conv_superfun2cdiff(lch_sf,lch);

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% List of lists of variables ordered by gradings
l_grad_mon:=der_deg_ordering(0,all_parametric_der)$
l_grad_mon:=part(l_grad_mon,2):=alpha . part(l_grad_mon,2)$
% List of lists of graded monomials of scale degree <= 8
gradmon:=graded_mon(1,15,l_grad_mon)$
gradmon:={1} . gradmon$

% Creates monomials of scale degree equal to the third argument with:
% - monomials of independent variables of algebraic degree less than
% or equal to the first argument;
% - graded monomials in the list graadmon, which is ordered by scale degree.

grmont:=mkallgradmon_evenind(1,gradmon,6)$

% we assume a generating function of degree <= 8
sym:=(for each el in grmont sum (c(ctel:=ctel+1)*el))$

pause;

% The equation of symmetries
equ 1:=num lch(1,1,sym)$

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

% Run the procedure splitvars in order to obtain equations on coefficiens
% of each monomial.

tel:=splitvars_opequ(equ,1,1,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=2:tel do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write sym:=sym;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;
