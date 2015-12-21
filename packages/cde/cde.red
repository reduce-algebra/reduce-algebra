module cde; % CDIFF package main file

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

% % *****************************************************************
% Author and maintainer: Raffaele Vitolo
% Dipartimento di Matematica, Universita' del Salento (Lecce, Italy)
% email: raffaele.vitolo@unisalento.it
% web: http://poincare.unisalento.it/vitolo

%
% Version and Date:  2.0, October 2015.
%
% ===============================================================

%
% write "This is CDE, a REDUCE package for calculus on differential equations";
% write "version 2.0, October 2015";
% write "by Raffaele Vitolo";

%
%-----------------------------------------------------------------------------%
% Initialization
%-----------------------------------------------------------------------------%
%
% List of global variables
% NOTATION: identifiers which end with !* are symbolic mode lists,
% for internal use only.
% Identifiers with names both ending with !* and without are lists
% which are the same and are usable in both modes, provided that the lists
% that are declared in one mode are shared in order to make them accessible
% under the other mode.
global '(indep_var dep_var odd_var total_order
 principal_der de principal_odd de_odd
 deg_indep_var deg_dep_var deg_odd_var % end of input variables
 indep_var!* dep_var!* odd_var!* principal_der!* de!* principal_odd!* de_odd!*
 deg_indep_var!* deg_dep_var!* deg_odd_var!*
    % end of internal version of input variables
 id_tot_der!*
 n_indep_var all_mind_table!* all_der_mind!* all_odd_mind!*
 all_der_id!* all_odd_id!*
 all_der_id all_odd_id
 n_all_ext
 i2m_jetspace!* i2m_jetspace_odd!* i2o_jetspace!* i2o_jetspace_odd!*
    % end of jetspace variables
 all_principal_der!* all_parametric_der!*
 all_principal_der all_parametric_der
 all_principal_odd!* all_parametric_odd!*
 all_principal_odd all_parametric_odd
 n_all_principal_ext n_all_parametric_ext
   tot_der!*
     letop
    % end of parametric and principal variables
 primary_diffcon_der_tot!* primary_diffcon_odd_tot!*
 primary_diffcon_der!* primary_diffcon_odd!* diffcon_der!*
 diffcon_odd!* diffcon_comp_der!* diffcon_comp_odd!* diffcon_comp_ext!*
 diffcon_param_der!* diffcon_param_ext!*
 repprincparam_der repprincparam_ext repprincparam_odd
     );

% shared variables
share all_der_id,all_odd_id,all_parametric_der,all_principal_der,
  all_parametric_odd,all_principal_odd,repprincparam_der,repprincparam_odd;

% List of switches and their default values

switch checkord;
% checkord: enables commands which check if any computation
% with total derivatives produces expression which depend on 'letop'.
% Default: t
!*checkord:=t;

switch expand_td;
% expand_td: if nil does not expand the procedure td, mapping it to simpiden
% and transforming it into an operator. Default: t
!*expand_td:=t;

load_package cdiff;

create!-package('(cde cde_tools cde_jetspace cde_parametric
                  cde_totalder cde_diffcon cde_varcalc cde_cdiff
                  cde_cdcalc cde_ansatz cde_init), nil);

endmodule;

end;
