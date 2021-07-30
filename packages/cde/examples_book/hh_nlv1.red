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
odd_var:={w1,w2}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="hh_nlv1_state.red"$
resname:="hh_nlv1_res.red"$

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

% Same construction for odd coordinates
principal_odd:={w1_t,w2_t}$
de_odd:={rhs(first cotan_covering_eq),rhs(second cotan_covering_eq)
  };

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
% cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
%save_cde_state(statename)$

cnt:=0;
unk_cf:={};
nc:=length(dep_var);

even_vars:=for i:=0:3 join selectvars(0,i,dep_var,all_parametric_der)$
odd_vars:=for i:=0:3 join selectvars(1,i,odd_var,all_parametric_odd);
ansatz:=for each el in odd_vars sum
  <<
    unk_cf:=mkid(cf_,cnt:=cnt+1) . unk_cf;
    mkid(cf_,cnt)*el
  >>;
for each el in unk_cf do for each ell in even_vars do depend el,ell;

% Ansatz for conservation laws: we require them to be of the form
% cp dp \wedge dy \wedge dz + ct dt \wedge dy \wedge dz

cp:=w1$

% td(w1,t) - td(w2_p - q_z*w2_y+q_y*w2_z,p);

ct:=ansatz$

total_eq:=td(cp,t) - td(ct,p)$
system_eq:=splitext_list({total_eq})$

load_package crack;
crack_results:=crack(system_eq,{},unk_cf,
   cde_difflist(all_parametric_der,even_vars));

off nat$
off echo$
out <<resname>>;
crack_results:=crack_results;
write ";end;";
shut <<resname>>;
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: