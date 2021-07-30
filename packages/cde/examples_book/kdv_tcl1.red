% KdV equation: conservation laws on the tangent covering
% 2017-10-01

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
deg_indep_var:={-1,-3}$
deg_dep_var:={2}$
deg_odd_var:={1}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="kdv_tcl1_state.red"$
resname:="kdv_tcl1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this also means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_t}$
% right-hand side of the differential equation
de:={u*u_x+u_3x}$

% same constructions for odd coordinates
principal_odd:={q_t}$
de_odd:={q*u_x + u*q_x + q_3x}$

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
l_grad_even:=der_deg_ordering(0,all_parametric_der)$
l_grad_odd:={1} . der_deg_ordering(1,all_parametric_odd)$
% List of graded monomials of scale degree <= 10
gradmon:=graded_mon(1,10,l_grad_even)$
gradmon:={1} . gradmon$
% list of graded monomials which are linear in odd variables
% and have total degree 3 and 5 respectively
linodd3:=mkalllinodd(gradmon,l_grad_odd,3,3)$
linodd5:=mkalllinodd(gradmon,l_grad_odd,5,5)$

% We would like to find two conservation laws
% on the tangent covering of the KdV equation
% which depend linearly on the covering variables;
% we assume that they are of the form cnx dx + cnt dt.
% They are produced by symmetries of the initial equation.
% In the case of 2 independent variables and 1 dependent variable,
% one could prove that one component of such conservation laws
% can always be written as sym*q as follows:

c1x:=q$ % degree 1
c2x:=u*q$ % degree 3

% The second component must be found by solving an equation.

c1t:=(for each el in linodd3 sum (c(ctel:=ctel+1)*el))$ % degree 3
c2t:=(for each el in linodd5 sum (c(ctel:=ctel+1)*el))$ % degree 5

% The first equation below is already solved `by hand'.

equ 1:=td(c1t,x)-td(c1x,t);
equ 2:=td(c2t,x)-td(c2x,t);

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=2;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,2);

tel2:=splitvars_opequ(equ,3,tel,vars);

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

off echo$
off nat$
out <<resname>>$
c1x:=c1x;
c1t:=c1t;
c2x:=c2x;
c2t:=c2t;
shut <<resname>>$
on nat$
on echo$

;end;

