% Potential Khokhlov-Zabolotskaya equation: local conservation laws
% 2015-11-13

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
dep_var:={v,w}$
deg_indep_var:={-3,-1,-2}$
deg_dep_var:={1,3}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="pkz_lcl1_state.red"$
resname:="pkz_lcl1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={v_y,w_y}$
% right-hand side of the differential equation
de:={w,v_tx - v_x*v_2x}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,{})$

% Saving cde state in a file
% save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% we assume that conserved currents have the form
% cl = ct dxdy + cx dtdy + cy dtdx
% in order to have a homogeneous c.l. w.r.t. grading
% there must hold: [cx]=[ct]+2=[cy]+1.

% List of variables ordered by gradings
top_degree:=10$
even_vars:=for i:=0:3 join selectvars(0,i,dep_var,all_parametric_der)$
l_grad_mon:=der_deg_ordering(0,even_vars)$
% List of graded monomials of scale degree <= top_degree
gradmon:=graded_mon(1,top_degree,l_grad_mon)$
gradmon:={1} . gradmon$

% List of scale degrees of the components of the conservation laws
deg_ct:=2$
deg_cx:=deg_ct+2$
deg_cy:=deg_ct+1$
% algebraic degree of the independent variables
deg_ind:=3$

% Creates monomials of scale degree equal to the third argument with:
% - monomials of independent variables of algebraic degree less than
% or equal to the first argument;
% - graded monomials in the list gradmon, which is ordered by scale degree.

grmont:=mkallgradmon_evenind(deg_ind,gradmon,deg_ct)$
grmonx:=mkallgradmon_evenind(deg_ind,gradmon,deg_cx)$
grmony:=mkallgradmon_evenind(deg_ind,gradmon,deg_cy)$

% Ansatz:
ct_list:=for each el in grmont collect (c(ctel:=ctel+1)*el)$
cx_list:=for each el in grmonx collect (c(ctel:=ctel+1)*el)$
cy_list:=for each el in grmony collect (c(ctel:=ctel+1)*el)$

ct_t_list:=for each el in ct_list collect td(el,t)$
cx_x_list:=for each el in cx_list collect td(el,x)$
cy_y_list:=for each el in cy_list collect td(el,y)$

ct:=(part(ct_list,0):=plus)$
cx:=(part(cx_list,0):=plus)$
cy:=(part(cy_list,0):=plus)$

ct_t:=(part(ct_t_list,0):=plus)$
cx_x:=(part(cx_x_list,0):=plus)$
cy_y:=(part(cy_y_list,0):=plus)$

equ 1:=ct_t-cx_x+cy_y$

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

% Beginning of removal of trivial c.l. from the solution
operator cc$
cctel:=0$

% ansatz for tcl, the grading must be compatible with
% tcl = tct dt + tcx dx + tcy dy
% and dbar(tcl) = (ddx(tcy)-ddy(tcx)) dxdy +
%                 (ddt(tcy)-ddy(tct)) dtdy +
%                 (ddt(tcx)-ddx(tct)) dtdx
%               = ct dxdy + cx dtdy + cy dtdx
deg_tcx:=deg_ct-2$
deg_tcy:=deg_tcx+1$
deg_tct:=deg_ct$
deg_tind:=deg_ind+1$

grmon_tcx:=mkallgradmon_evenind(deg_tind,gradmon,deg_tcx)$
grmon_tcy:=mkallgradmon_evenind(deg_tind,gradmon,deg_tcy)$
grmon_tct:=mkallgradmon_evenind(deg_tind,gradmon,deg_tct)$

tcx_list:=for each el in grmon_tcx collect (cc(cctel:=cctel+1)*el)$
tcy_list:=for each el in grmon_tcy collect (cc(cctel:=cctel+1)*el)$
tct_list:=for each el in grmon_tct collect (cc(cctel:=cctel+1)*el)$

tcx:=(part(tcx_list,0):=plus)$
tcy:=(part(tcy_list,0):=plus)$
tct:=(part(tct_list,0):=plus)$

clear equ$
operator equ$

equ 1:=(td(tcy,x)-td(tcx,y)) - ct$
equ 2:=(td(tcy,t)-td(tct,y)) - cx$
equ 3:=(td(tcx,t)-td(tct,x)) - cy$

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=3$

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{cc,cctel,0},{f,0,0})$

% Run the splitting procedures
% in order to obtain algebraic equations on coefficients
% of each monomial.

tel:=splitvars_opequ(equ,1,3,vars);

put_equations_used tel$

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=4:tel do integrate_equation i$

ctnontriv:=equ 1$
cxnontriv:=equ 2$
cynontriv:=equ 3$

off nat$
off echo$
out <<resname>>$
write "% Conservation laws (after removal of trivial ones)";
write ctnontriv:=ctnontriv;
write cxnontriv:=cxnontriv;
write cynontriv:=cynontriv;

write ";end;";
shut <<resname>>$
on echo$
on nat$


;end;

Local Variables:
mode:reduce
End:
