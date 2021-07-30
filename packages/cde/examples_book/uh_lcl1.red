% Universal Hierarchy equation: local conservation laws
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
indep_var:={t,x,y}$
dep_var:={u}$
total_order:=10$
% names for output of the state of cde and results of computations
statename:="uh_lcl1_state.red"$
resname:="uh_lcl1_res.red"$

% Initialization of the differential equation.

% left-hand side of the differential equation
principal_der:={u_2y}$
% right-hand side of the differential equation
de:={u_t*u_xy - u_y*u_tx}$

% Calling cde's main routine
cde({indep_var,dep_var,{},total_order},
   {principal_der,de,{},{}})$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% We look for conserved currents of the type
% cl = cx dtdy + cy dtdx

% List of variables in the ansatz
even_vars:=for i:=0:1 join selectvars(0,i,dep_var,all_parametric_der)$
% Dependence of the unknown functions
unk:={cx,cy};
for each el in even_vars do
<<
  depend(cx,el);
  depend(cy,el)
>>;

total_eq:={td(cx,y) - td(cy,x)}$
split_vars:=
  for i:=2:total_order join selectvars(0,i,dep_var,all_parametric_der);
load_package crack;
crack_results:=crack(total_eq,{},unk,split_vars);

off nat$
off echo$
out <<resname>>$
write "% Conservation laws of the Universal Hierarchy equation";
write "crack_results:=",crack_results;

write ";end;";
shut <<resname>>$
on echo$
on nat$

% Removal of trivial c.l. from the solution
let second first crack_results;
% Ansatz for tcl, the grading must be compatible with
% tcl = tct dt
% and dbar(tcl) = - tct_y dtdy - tct_x dtdx
%               = cx dtdy + cy dtdx
unk:={tct};
for each el in even_vars do depend(tct,el);
for each el in indep_var do depend(tct,el);

total_eq:={ - td(tct,y) - df(cx,c_17), - td(tct,x) - df(cy,c_17)}$
crack_results_triv:=crack(total_eq,{},unk,split_vars);

;end;

Local Variables:
mode:reduce
End:
