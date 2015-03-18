% Interface between Reduce/CSL and the NLopt numerical optimization package
% http://ab-initio.mit.edu/wiki/index.php/NLopt.

module nlopt;

#if (memq 'csl lispsystem!*)

off lower;

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
   newDoubleArray!* setDoubleArray!* freeDoubleArray!*
   nlopt_get_algorithm!*        NLOPT_get_algorithm!*
   nlopt_algorithm_name!*
   nlopt_get_dimension!*        NLOPT_get_dimension!*
   nlopt_create!*               NLOPT_create!*
   nlopt_set_local_optimizer!*  NLOPT_set_local_optimizer!*
   nlopt_destroy!*              NLOPT_destroy!*
   nlopt_set_lower_bounds!*     NLOPT_set_lower_bounds!*
   nlopt_set_upper_bounds!*     NLOPT_set_upper_bounds!*
   nlopt_set_xtol_rel!*         NLOPT_set_xtol_rel!*
   nlopt_set_ftol_rel!*         NLOPT_set_ftol_rel!*
   nlopt_set_ftol_abs!*         NLOPT_set_ftol_abs!*
   nlopt_set_maxeval!*          NLOPT_set_maxeval!*
   nlopt_set_maxtime!*          NLOPT_set_maxtime!*
   nlopt_get_lower_bounds!*     NLOPT_get_lower_bound!*
   nlopt_get_upper_bounds!*     NLOPT_get_upper_bound!*
   nlopt_get_xtol_rel!*         NLOPT_get_xtol_rel!*
   nlopt_get_ftol_rel!*         NLOPT_get_ftol_rel!*
   nlopt_get_ftol_abs!*         NLOPT_get_ftol_abs!*
   nlopt_get_maxeval!*          NLOPT_get_maxeval!*
   nlopt_get_maxtime!*          NLOPT_get_maxtime!*
   nlopt_set_stopval!*          NLOPT_set_stopval!*
   nlopt_set_min_objective!*    NLOPT_set_min_objective!*
   nlopt_set_max_objective!*    NLOPT_set_max_objective!*
   nlopt_optimize!*             NLOPT_optimize!*
   get_result!*  free_result!*
   nlopt_add_equality_constraint!*        NLOPT_add_eq_constraint!*
   nlopt_add_equality_mconstraint!*       NLOPT_add_eq_mconstraint!*
   nlopt_add_inequality_constraint!*      NLOPT_add_ineq_constraint!*
   nlopt_add_inequality_mconstraint!*     NLOPT_add_ineq_mconstraint!*
   nlopt_remove_equality_constraints!*    NLOPT_remove_eq_constraints!*
   nlopt_remove_inequality_constraints!*  NLOPT_remove_ineq_constraints!*
   nlopt_set_initial_step!*     NLOPT_set_initial_step!*
   nlopt_set_initial_step1!*    NLOPT_set_initial_step1!*
   nlopt_get_initial_step!*     NLOPT_get_initial_step!*
   nlopt_set_population!*       NLOPT_set_population!*
   nlopt_srand!*                NLOPT_srand!*
);

#endif

endmodule;  % nlopt
end;