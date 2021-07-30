% Dispersionless Boussinesq equation: conservation laws
% 2015-11-09

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
dep_var:={u,v,w}$
odd_var:={p,q,r}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="bou_csy1_state.red"$
resname:="bou_csy1_res.red"$

% The function that defines the Boussinesq equation
principal_der:={u_t,v_t,w_t}$
de:={w*w_x + v_x, - u*w_x - 3*w*u_x,u_x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{principal_der,de,{},{}})$
% Saving cde state in a file
save_cde_state(statename)$

ncomp:=length(dep_var)$

mk_superfun(lbou_sf,1,3);
mk_superfun(lbou_star_sf,1,3);

% Loading the results from bou_ell1_res.red
lbou_sf(1):=p_t - q_x - r*w_x - r_x*w;
lbou_sf(2):=p*w_x + 3*p_x*w + q_t + 3*r*u_x + r_x*u;
lbou_sf(3):= - p_x + r_t;
lbou_star_sf(1):= - p_t - 2*q*w_x - 3*q_x*w + r_x;
lbou_star_sf(2):=p_x - q_t;
lbou_star_sf(3):=p_x*w + 2*q*u_x - q_x*u - r_t;

conv_superfun2cdiff(lbou_star_sf,lbou_star);

% Another possibility is to  directly load the operator as a
% C-Differential operator:
%% mk_cdiffop(lbou_star,1,{3},3);
%% for all psi let lbou_star(1,1,psi)= - td(psi,t);
%% for all psi let lbou_star(1,2,psi)= - 2*psi*w_x - 3*w*td(psi,x);
%% for all psi let lbou_star(1,3,psi)= td(psi,x);
%% for all psi let lbou_star(2,1,psi)= td(psi,x);
%% for all psi let lbou_star(2,2,psi)= - td(psi,t);
%% for all psi let lbou_star(2,3,psi)=0;
%% for all psi let lbou_star(3,1,psi)= w*td(psi,x);
%% for all psi let lbou_star(3,2,psi)= 2*u_x*psi - u*td(psi,x);
%% for all psi let lbou_star(3,3,psi)= - td(psi,t);

cldens_1:=w;
cldens_2:=u;
cldens_3:=v+w**2;

genfun_1:=for each el in dep_var collect pvar_df(0,cldens_1,el)$
genfun_2:=for each el in dep_var collect pvar_df(0,cldens_2,el)$
genfun_3:=for each el in dep_var collect pvar_df(0,cldens_3,el)$

res_1:=
for i:=1:ncomp collect
  for j:=1:ncomp sum lbou_star(i,j,part(genfun_1,j));

res_2:=
for i:=1:ncomp collect
  for j:=1:ncomp sum lbou_star(i,j,part(genfun_2,j));

res_3:=
for i:=1:ncomp collect
  for j:=1:ncomp sum lbou_star(i,j,part(genfun_3,j));


;end;

Local Variables:
mode:reduce
End: