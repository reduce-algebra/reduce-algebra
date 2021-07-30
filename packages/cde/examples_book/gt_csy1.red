% Gibbons-Tsarev equation: cosymmetries
% 2017-08-13

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
indep_var:={x,y}$
dep_var:={u}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="gt_csy1_state.red"$
resname:="gt_csy1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_2y}$
% right-hand side of the differential equation
de:={ - u_x*u_xy + u_y*u_2x - 1}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Saving cde state in a file
% save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% We look for polynomial conservation laws with respect to
% independent variables, dependent variables, and their first-order derivatives.
% The form is cy dx + cx dy

% List of variables
top_degree:=3$
even_vars:=for i:=0:1 join selectvars(0,i,dep_var,all_parametric_der)$
all_vars:=append(indep_var,even_vars)$

% Generate all monomials of degree <=2
list_mon:=1 . mkallmon(top_degree,all_vars)$

% Generate the monomials of the ansatz
psi_list:=for each el in list_mon collect (c(ctel:=ctel+1)*el)$
psi:=(part(psi_list,0):=plus)$
psi_x_list:=for each el in psi_list collect td(el,x)$
psi_y_list:=for each el in psi_list collect td(el,y)$
psi_x:=(part(psi_x_list,0):=plus)$
psi_y:=(part(psi_y_list,0):=plus)$

% The equation

equ 1:=td(psi_y,y) + u_x*td(psi_y,x) - u_y*td(psi_x,x)
  - 2*u_xy*psi_x + 2*u_2x*psi_y$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=1;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the splitting procedure
% in order to obtain algebraic equations on coefficiens
% of each monomial.

tel:=splitvars_opequ(equ,1,1,vars);

put_equations_used tel;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=2:tel do integrate_equation i;

off nat$
off echo$
out <<resname>>$
write "% Cosymmetries of the GT equation:";
write psi:=psi;

write ";end;";
shut <<resname>>$
on echo$
on nat$


;end;

Local Variables:
mode:reduce
End:
