% Interface between Reduce/CSL and the NLopt numerical optimization package
% http://ab-initio.mit.edu/wiki/index.php/NLopt.

% Author: Kostas N. Oikonomou

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

module nlopt;

#if (memq 'csl lispsystem!*)

off lower;
% necessary, see globals below

create!-package('(nlopt nlopt_main alg_intf), nil);

exports nlopt_get_algorithm, nlopt_algorithm_name, nlopt_algorithms,
   nlopt_get_dimension,
   nlopt_create, nlopt_set_local_optimizer, nlopt_destroy, 
   nlopt_set_lower_bounds, nlopt_set_upper_bounds,
   nlopt_set_xtol_rel,
   nlopt_set_ftol_rel, nlopt_set_ftol_abs,
   nlopt_set_maxeval, nlopt_set_maxtime,
   nlopt_get_lower_bounds, nlopt_get_upper_bounds,
   nlopt_get_xtol_rel,
   nlopt_get_ftol_rel, nlopt_get_ftol_abs,
   nlopt_get_maxeval, nlopt_get_maxtime,
   nlopt_set_stopval,
   nlopt_set_min_objective, nlopt_set_max_objective,
   nlopt_optimize,
   nlopt_add_equality_constraint, nlopt_add_equality_mconstraint,
   nlopt_add_inequality_constraint, nlopt_add_inequality_mconstraint,
   nlopt_remove_equality_constraints, nlopt_remove_inequality_constraints;


% Everything starting with "NLOPT_" is a C wrapper for the corresponding C "nlopt_"
% found in nlopt.h
global '(
   librednlopt_loc!* librednlopt!*
   nlopt_algorithm_codes!* nlopt_algorithm_rev_codes!*
   newdoublearray!* setdoublearray!* freedoublearray!*
   nlopt_get_algorithm!*        nlopt_get_algorithm!*
   nlopt_algorithm_name!*
   nlopt_get_dimension!*        nlopt_get_dimension!*
   nlopt_create!*               nlopt_create!*
   nlopt_set_local_optimizer!*  nlopt_set_local_optimizer!*
   nlopt_destroy!*              nlopt_destroy!*
   nlopt_set_lower_bounds!*     nlopt_set_lower_bounds!*
   nlopt_set_upper_bounds!*     nlopt_set_upper_bounds!*
   nlopt_set_xtol_rel!*         nlopt_set_xtol_rel!*
   nlopt_set_ftol_rel!*         nlopt_set_ftol_rel!*
   nlopt_set_ftol_abs!*         nlopt_set_ftol_abs!*
   nlopt_set_maxeval!*          nlopt_set_maxeval!*
   nlopt_set_maxtime!*          nlopt_set_maxtime!*
   nlopt_get_lower_bounds!*     nlopt_get_lower_bound!*
   nlopt_get_upper_bounds!*     nlopt_get_upper_bound!*
   nlopt_get_xtol_rel!*         nlopt_get_xtol_rel!*
   nlopt_get_ftol_rel!*         nlopt_get_ftol_rel!*
   nlopt_get_ftol_abs!*         nlopt_get_ftol_abs!*
   nlopt_get_maxeval!*          nlopt_get_maxeval!*
   nlopt_get_maxtime!*          nlopt_get_maxtime!*
   nlopt_set_stopval!*          nlopt_set_stopval!*
   nlopt_set_min_objective!*    nlopt_set_min_objective!*
   nlopt_set_max_objective!*    nlopt_set_max_objective!*
   nlopt_optimize!*             nlopt_optimize!*
   get_result!*  free_result!*
   nlopt_add_equality_constraint!*        nlopt_add_eq_constraint!*
   nlopt_add_equality_mconstraint!*       nlopt_add_eq_mconstraint!*
   nlopt_add_inequality_constraint!*      nlopt_add_ineq_constraint!*
   nlopt_add_inequality_mconstraint!*     nlopt_add_ineq_mconstraint!*
   nlopt_remove_equality_constraints!*    nlopt_remove_eq_constraints!*
   nlopt_remove_inequality_constraints!*  nlopt_remove_ineq_constraints!*
   nlopt_set_initial_step!*     nlopt_set_initial_step!*
   nlopt_set_initial_step1!*    nlopt_set_initial_step1!*
   nlopt_get_initial_step!*     nlopt_get_initial_step!*
   nlopt_set_population!*       nlopt_set_population!*
   nlopt_srand!*                nlopt_srand!*
);

#endif

endmodule;  % nlopt

end;
