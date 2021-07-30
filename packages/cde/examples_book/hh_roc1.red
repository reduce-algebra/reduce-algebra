% Husain Heavenly equation, evolutionary form:
% recursion operator for cosymmetries
% 2017-10-13

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
indep_var:={t,p,y,z}$
dep_var:={v,q}$
odd_var:={w1,w2,r1}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="hh_roc1_state.red"$
resname:="hh_roc1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={v_t,q_t}$
% right-hand side of the differential equation
de:={q,
  q_z*v_py - q_y*v_pz - v_2p
}$

% Loading the adjoint linearization as a vector function of odd variables
ctc_hh:={
q_py*w2_z - q_pz*w2_y + q_y*w2_pz 
- q_z*w2_py - w1_t + w2_2p,
v_py*w2_z - v_pz*w2_y - w1 - w2_t
}$

cotan_covering_eq:=first solve({part(ctc_hh,1),part(ctc_hh,2)},{w1_t,w2_t})$

% The nonlocal variable
r1p:=w1$
r1t:=w2_p - q_z*w2_y+q_y*w2_z$

% Same construction for odd coordinates
principal_odd:={w1_t,w2_t,r1_p,r1_t}$
de_odd:={rhs(first cotan_covering_eq),rhs(second cotan_covering_eq),
  r1p,r1t
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
odd_vars:=for i:=0:2 join selectvars(1,i,odd_var,all_parametric_odd)$
ansatz_mon:=
  for each el in odd_vars join
    for each ell in all_vars collect ell*el$

% Ansatz for shadows of cosymmetries on the cotangent covering
operator phi;
phi(1):=(for each el in ansatz_mon sum (c(ctel:=ctel+1)*el))$
phi(2):=(for each el in ansatz_mon sum (c(ctel:=ctel+1)*el))$

% Loading the adjoint linearization operator
mk_superfun(lhh_star_sf,1,2);
lhh_star_sf(1):=q_py*w2_z - q_pz*w2_y + q_y*w2_pz 
- q_z*w2_py - w1_t + w2_2p;
lhh_star_sf(2):=v_py*w2_z - v_pz*w2_y - w1 - w2_t;

conv_superfun2cdiff(lhh_star_sf,lhh_star);

% The equations for shadows of cosymmetries on the cotangent covering
for i:=1:nc do
  equ(i):=num(for j:=1:nc sum lhh_star(i,j,phi(j)));

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

;end;

Local Variables:
mode:reduce
End: