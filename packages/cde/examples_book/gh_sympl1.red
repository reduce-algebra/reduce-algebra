% General Heavenly equation, evolutionary form: local symplectic operator
% 2017-10-11

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
indep_var:={t,x,y,z}$
dep_var:={u,v}$
odd_var:={p,q}$
total_order:=5$
% names for output of the state of cde and results of computations
statename:="gh_sympl1_state.red"$
resname:="gh_sympl1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_t,v_t}$
% right-hand side of the differential equation
de:={v,
  (1/u_yz)*(u_2x*u_yz - u_xy*u_xz + v_y*v_z + b*(v_y*u_xz - v_z*u_xy))
}$

% Loading the linearization as a vector function of odd variables
tc_gh:={p_t - q,
(b*p_xy*u_yz*v_z - b*p_xz*u_yz*v_y - b*
p_yz*u_xy*v_z + b*p_yz*u_xz*v_y - b*q_y*u_xz*u_yz 
+ b*q_z*u_xy*u_yz - p_2x*u_yz**2 + p_xy*u_xz*u_yz 
+ p_xz*u_xy*u_yz - p_yz*u_xy*u_xz + p_yz*v_y*v_z +
 q_t*u_yz**2 - q_y*u_yz*v_z - q_z*u_yz*v_y)/u_yz**
2
}$

tan_covering_eq:=first solve({part(tc_gh,1),part(tc_gh,2)},{p_t,q_t})$

% Same construction for odd coordinates
principal_odd:={p_t,q_t}$
de_odd:={rhs(first tan_covering_eq),rhs(second tan_covering_eq)
  };

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Saving cde state in a file
%save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;
nc:=length(dep_var);

% List of variables ordered by gradings
even_vars:=for i:=0:2 join selectvars(0,i,dep_var,all_parametric_der)$
all_vars:=1 . even_vars$
odd_vars:=for i:=0:1 join selectvars(1,i,odd_var,all_parametric_odd)$
ansatz_mon:=
  for each el in odd_vars join
    for each ell in even_vars join {ell*el,b*ell*el}$

% Ansatz for shadows of cosymmetries on the tangent covering
operator phi;
phi(1):=(for each el in ansatz_mon sum (c(ctel:=ctel+1)*el))$
phi(2):=(for each el in ansatz_mon sum (c(ctel:=ctel+1)*el))$

% Loading the adjoint linearization operator
mk_superfun(lgh_star_sf,1,2);
lgh_star_sf(1):=(2*b*q*u_2y2z*u_xy*u_yz*v_z - 2*b*
q*u_2y2z*u_xz*u_yz*v_y - 2*b*q*u_2yz*u_x2z*u_yz*
v_y - 6*b*q*u_2yz*u_xy*u_y2z*v_z + 2*b*q*u_2yz*
u_xy*u_yz*v_2z + 4*b*q*u_2yz*u_xyz*u_yz*v_z + 6*b*
q*u_2yz*u_xz*u_y2z*v_y - 2*b*q*u_2yz*u_xz*u_yz*
v_yz - b*q*u_2yz*u_yz**2*v_xz + 2*b*q*u_x2y*u_y2z*
u_yz*v_z - b*q*u_x2y*u_yz**2*v_2z - 2*b*q*u_x2yz*
u_yz**2*v_z + b*q*u_x2z*u_yz**2*v_2y + 2*b*q*u_xy*
u_y2z*u_yz*v_yz - b*q*u_xy*u_yz**2*v_y2z + 2*b*q*
u_xy2z*u_yz**2*v_y - 4*b*q*u_xyz*u_y2z*u_yz*v_y - 
2*b*q*u_xz*u_y2z*u_yz*v_2y + b*q*u_xz*u_yz**2*
v_2yz + b*q*u_y2z*u_yz**2*v_xy - b*q_x*u_2yz*u_yz
**2*v_z + b*q_x*u_y2z*u_yz**2*v_y + b*q_xy*u_yz**3
*v_z - b*q_xz*u_yz**3*v_y + b*q_y*u_x2z*u_yz**2*
v_y + 2*b*q_y*u_xy*u_y2z*u_yz*v_z - b*q_y*u_xy*
u_yz**2*v_2z - 2*b*q_y*u_xyz*u_yz**2*v_z - 2*b*q_y
*u_xz*u_y2z*u_yz*v_y + b*q_y*u_xz*u_yz**2*v_yz + b
*q_y*u_yz**3*v_xz - b*q_yz*u_xy*u_yz**2*v_z + b*
q_yz*u_xz*u_yz**2*v_y + 2*b*q_z*u_2yz*u_xy*u_yz*
v_z - 2*b*q_z*u_2yz*u_xz*u_yz*v_y - b*q_z*u_x2y*
u_yz**2*v_z - b*q_z*u_xy*u_yz**2*v_yz + 2*b*q_z*
u_xyz*u_yz**2*v_y + b*q_z*u_xz*u_yz**2*v_2y - b*
q_z*u_yz**3*v_xy - p_t*u_yz**4 - q*u_2xy*u_y2z*
u_yz**2 + 2*q*u_2xyz*u_yz**3 - q*u_2xz*u_2yz*u_yz
**2 + 2*q*u_2y2z*u_xy*u_xz*u_yz - 2*q*u_2y2z*u_yz*
v_y*v_z + 2*q*u_2yz*u_x2z*u_xy*u_yz - 6*q*u_2yz*
u_xy*u_xz*u_y2z + 4*q*u_2yz*u_xyz*u_xz*u_yz + 6*q*
u_2yz*u_y2z*v_y*v_z - 2*q*u_2yz*u_yz*v_2z*v_y - 2*
q*u_2yz*u_yz*v_yz*v_z - q*u_x2y*u_x2z*u_yz**2 + 2*
q*u_x2y*u_xz*u_y2z*u_yz - 2*q*u_x2yz*u_xz*u_yz**2 
- 2*q*u_xy*u_xy2z*u_yz**2 + 4*q*u_xy*u_xyz*u_y2z*
u_yz - 3*q*u_xyz**2*u_yz**2 - 2*q*u_y2z*u_yz*v_2y*
v_z - 2*q*u_y2z*u_yz*v_y*v_yz + q*u_yz**2*v_2y*
v_2z + q*u_yz**2*v_2yz*v_z + q*u_yz**2*v_y*v_y2z +
 q*u_yz**2*v_yz**2 - q_2x*u_yz**4 - q_x*u_2yz*u_xz
*u_yz**2 - q_x*u_xy*u_y2z*u_yz**2 + 2*q_x*u_xyz*
u_yz**3 + q_xy*u_xz*u_yz**3 + q_xz*u_xy*u_yz**3 + 
q_y*u_2xz*u_yz**3 - q_y*u_x2z*u_xy*u_yz**2 + 2*q_y
*u_xy*u_xz*u_y2z*u_yz - 2*q_y*u_xyz*u_xz*u_yz**2 -
 2*q_y*u_y2z*u_yz*v_y*v_z + q_y*u_yz**2*v_2z*v_y +
 q_y*u_yz**2*v_yz*v_z - q_yz*u_xy*u_xz*u_yz**2 + 
q_yz*u_yz**2*v_y*v_z + q_z*u_2xy*u_yz**3 + 2*q_z*
u_2yz*u_xy*u_xz*u_yz - 2*q_z*u_2yz*u_yz*v_y*v_z - 
q_z*u_x2y*u_xz*u_yz**2 - 2*q_z*u_xy*u_xyz*u_yz**2 
+ q_z*u_yz**2*v_2y*v_z + q_z*u_yz**2*v_y*v_yz)/
u_yz**4$

lgh_star_sf(2):=( - b*q*u_2yz*u_xz + b*q*u_xy*
u_y2z + b*q_y*u_xz*u_yz - b*q_z*u_xy*u_yz - p*u_yz
**2 - q*u_2yz*v_z - q*u_y2z*v_y + 2*q*u_yz*v_yz - 
q_t*u_yz**2 + q_y*u_yz*v_z + q_z*u_yz*v_y)/u_yz**2
  $

conv_superfun2cdiff(lgh_star_sf,lgh_star);

% The equations for shadows of cosymmetries on the tangent covering
for i:=1:nc do
  equ(i):=num(for j:=1:nc sum lgh_star(i,j,phi(j)));

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=2;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

off coefficient_check;
initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,2);

tel2:=splitvars_opequ(equ,3,tel,vars);

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
write ";end;";
shut <<resname>>;
on echo$
on nat$

mk_superfun(symp1_sf,1,2);
for i:=1:nc do
  symp1_sf(i):=df(phi(i),c(35));
conv_superfun2cdiff(symp1_sf,symp1);
adjoint_cdiffop(symp1,symp1_star);
for i:=1:nc do if symp1_star_sf(i) + symp1_sf(i) neq 0 then
  write "Non self-adjoint operator";

% Conversion into bivector
conv_genfun2vform(symp1_sf,vform1);

% Computes the Cartan differential followed by the Euler operator
% to check if the expression is a total divergence;
cartan_df(vform1,dc_vform1);
dc_vform1(1);
variational_df(vform1,vform_res);


;end;

Local Variables:
mode:reduce
End: