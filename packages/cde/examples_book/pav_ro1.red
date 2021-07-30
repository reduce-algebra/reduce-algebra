% Pavlov equation: recursion operator for symmetries
% 2017-10-06

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
odd_var:={q,r}$
total_order:=6;

% The even equation
principal_der:={u_2y}$
de:={u_tx + u_y*u_2x - u_x*u_xy}$

% The odd nonlocal variable
rx:=u_x*q_x + q_y - u_2x*q$
ry:=q_t + u_y*q_x - u_xy*q$

% The odd equation
principal_odd:={q_2y,r_x,r_y}$
de_odd:={q_2x*u_y  + q_tx - q_x*u_xy - q_xy*u_x + q_y*u_2x,rx,ry}$

% names for output of the state of cde and results of computations
statename:="pav_ro1_state.red"$
resname:="pav_ro1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
  {principal_der,de,principal_odd,de_odd})$

mk_superfun(lpav_sf,1,1);
lpav_sf(1):= - q_2x*u_y + q_2y - q_tx + q_x*u_xy + q_xy*u_x - q_y*u_2x$
conv_superfun2cdiff(lpav_sf,lpav);

lpav(1,1,r);

;end;

