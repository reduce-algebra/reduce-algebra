% Dispersionless Boussinesq equation: shadows of symmetries
% 2015-12-09

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
dep_var:={u,v,w,z1,z2,z3}$
odd_var:={p,q,r}$
deg_indep_var:={-1,-2}$
deg_dep_var:={3,4,2,1,2,3}$
deg_odd_var:={0,0,0}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="bou_sh1_state.red"$
resname:="bou_sh1_res.red"$

% The function that defines the Boussinesq equation
principal_der:={u_t,v_t,w_t,
  z1_x,z1_t,
  z2_x,z2_t,
  z3_x,z3_t
    }$
de:={w*w_x + v_x, - u*w_x - 3*w*u_x,u_x,
  w,u,
  u,v+(w**2/2),
  v+w**2,-u*w
  }$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{principal_der,de,{},{}})$
% Saving cde state in a file
save_cde_state(statename)$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Loading the linearization
mk_superfun(lbou_sf,1,3);
mk_superfun(lbou_star_sf,1,3);
in "bou_ell1_res.red"$
conv_superfun2cdiff(lbou_sf,lbou)$

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
phiu:=for each el in ansatz sum c(ctel:=ctel+1)*el$
phiv:=for each el in ansatz sum c(ctel:=ctel+1)*el$
phiw:=for each el in ansatz sum c(ctel:=ctel+1)*el$
unk:={phiu,phiv,phiw}$

% Define the equations
nc:=3;
equ 1:=for j:=1:nc sum lbou(1,j,part(unk,j))$
equ 2:=for j:=1:nc sum lbou(2,j,part(unk,j))$
equ 3:=for j:=1:nc sum lbou(3,j,part(unk,j))$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=3;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedure splitvars in order to obtain equations on coefficiens
% of each monomial.

tel:=splitvars_opequ(equ,1,3,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel;

% It is worth to write down the equations for the coefficients.

for i:=4:tel do write equ i;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=4:tel do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
phiu:=phiu;
phiv:=phiv;
phiw:=phiw;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: