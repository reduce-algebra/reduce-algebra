#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <assert.h>
#include <nlopt.h>
// The "procedural" interface to Reduce/CSL.
#include "C_call_CSL.h"


// activate by setting to 1 or 2
int DEBUG = 0;

// The optimization "object":
static nlopt_opt opt       = NULL;
// The result computed by NLOPT_optimize:
static double *result;
// The local optimization sub-algorithm/object, for algorithms that use it:
static nlopt_opt local_opt = NULL;

// Nlopt return codes, see nlopt_result in nlopt.h.  Used only in few
// places. nlopt_main.red does error checking at the Reduce level.
char *nlopt_result_mess(nlopt_result r) {
  char *s;
  switch (r) {
  case -1: s = "nlopt failure!";  break;
  case -2: s = "invalid arguments or unsupported constraints (perhaps for this algorithm)!";  break;
  case -3: s = "out of memory!";  break;
  case -4: s = "progress limited by roundoff";  break;
  case -5: s = "forced stop";  break;
  case 1:  s = "nlopt success";  break;
  case 2:  s = "stop value reached";  break;
  case 3:  s=  "f-tolerance reached";  break;
  case 4:  s = "x-tolerance reached";  break;
  case 5:  s = "max evaluations reached";  break;
  case 6:  s = "max time reached";  break;
  };
  return s;
}

#define ERRORCHECK(who,r) if (r != NLOPT_SUCCESS) \
    {fprintf(stderr, "*%s: %s\n", who, nlopt_result_mess(r));}


// =======================================================================
// Basics
// =======================================================================

void NLOPT_create(int32_t anum, int32_t n) {
  opt = nlopt_create(anum, n);
  if (opt == NULL)
    fprintf(stderr,"Couldn't create '%s'!\n",nlopt_algorithm_name(anum));
}

void NLOPT_destroy() {
  nlopt_destroy(opt);
}

int32_t NLOPT_get_algorithm() {
  // The only reason for this "NLOPT_" is to convert from nlopt_algorithm to int32_t"!
  // Isn't there a better way?
  int32_t a = nlopt_get_algorithm(opt);
  return a;
}

int32_t NLOPT_get_dimension() {
  // The only reason for this "NLOPT_" is to convert from "unsigned" to "int32_t"!
  int32_t d = nlopt_get_dimension(opt);
  return d;
}

// =======================================================================
// Setting upper and lower bounds (hyper-rectangle)
// =======================================================================

int32_t NLOPT_set_lower_bounds(const double *lb) {
  int32_t r = nlopt_set_lower_bounds(opt, lb);
  return r;
}
int32_t NLOPT_set_upper_bounds(const double *ub) {
  int32_t r = nlopt_set_upper_bounds(opt, ub);
  return r;
}

// acts like a Icon generator
double NLOPT_get_lower_bound(int32_t i, int32_t n) {
  static double *slb = NULL;
  if (i == 0) {
    // Contortion 1:
    slb = (double *) malloc(n*sizeof(double));
    int32_t r = nlopt_get_lower_bounds(opt, slb);
    ERRORCHECK("NLOPT_get_lower_bound",r);
  }
  // Contortion 2:
  double lbi = slb[i];
  if (i == n-1) free(slb);
  return lbi; 
}

// acts like a Icon generator
double NLOPT_get_upper_bound(int32_t i, int32_t n) {
  static double *sub = NULL;
  if (i == 0) {
    // Contortion 1:
    sub = (double *) malloc(n*sizeof(double));
    int32_t r = nlopt_get_upper_bounds(opt, sub);
    ERRORCHECK("NLOPT_get_upper_bound",r);
  }
  // Contortion 2:
  double ubi = sub[i];
  if (i == n-1) free(sub);
  return ubi; 
}

// =======================================================================
// Stopping criteria
// =======================================================================

int32_t NLOPT_set_xtol_rel(double t) {
  return nlopt_set_xtol_rel(opt, t);
}
int32_t NLOPT_set_ftol_rel(double t) {
  return nlopt_set_ftol_rel(opt, t);
}
int32_t NLOPT_set_ftol_abs(double t) {
  return nlopt_set_ftol_abs(opt, t);
}
int32_t NLOPT_set_maxeval(int32_t m) {
  return nlopt_set_maxeval(opt, m);
}
int32_t NLOPT_set_maxtime(double m) {
  return nlopt_set_maxtime(opt, m);
}
int32_t NLOPT_set_stopval(double v) {
  return nlopt_set_stopval(opt, v);
}

double NLOPT_get_xtol_rel() {
  return nlopt_get_xtol_rel(opt);
}
double NLOPT_get_ftol_rel() {
  return nlopt_get_ftol_rel(opt);
}
double NLOPT_get_ftol_abs() {
  return nlopt_get_ftol_abs(opt);
}
int32_t NLOPT_get_maxeval() {
  return nlopt_get_maxeval(opt);
}
double NLOPT_get_maxtime() {
  return nlopt_get_maxtime(opt);
}


// ===========================================================================
// Functions *internal* to the interface for dealing with arrays of doubles
// To understand what's going on see the comments in nlopt_set_lower_bounds()
// in nlopt_main.red.
// ===========================================================================
double *newDoubleArray(int32_t len) {
  double *a;
  a = (double *) malloc(len*sizeof(double));
  return a;
}
void setDoubleArray(double a[], int32_t i, double x) {
  a[i] = x;
}
void freeDoubleArray(double a[]) {
  free(a);
}
// This internal function turns a C array of doubles into a Lisp list and 
// leaves it at the top of the stack.  The "stack" is used by the "procedural"
// interface to Reduce, see file "C_call_CSL.h".
void C_darray_to_Lisp_list(int32_t n, const double x[]) {
  // Push the x[i] on the stack.
  for (int i = 0; i < n; i++) PROC_push_floating(x[i]);
  // Make a list out of the x[i]; it is left at the top of the stack.
  PROC_make_function_call("list", n);
  // Now having put 'list on the front, get rid of it.
  // (This perhaps shows that that ACN should really extend the procedural
  // interface to make this slightly nicer. But with luck this will suffice
  // for now.)
  PROC_lisp_eval();
}


// ================================================================
// Setting the optimization objective
// ================================================================
// This is the most complex and difficult part of the interface so far.


// This function is internal to the interface (static), and is of type nlopt_func.
// It is modelled after f77_func_wrap in api/f77api.c.  It is used as a wrapper
// for scalar functions, which can represent either the optimization objective,
// or a general equality or inequality constraint.
// The PROC_ code is borrowed from cuba_integrand in redcuba.c of the 'cuba' package.
static double red_func_wrap(unsigned n, const double *x, double *grad, void *f_data) {
  double z;
  char *fn = (char *) f_data;
  if (DEBUG > 1) {
    fprintf(stderr, "red_func_wrap: %s", fn);
    if (grad) fprintf(stderr, " [G]");
    fprintf(stderr, "\n");
  }
  // Convert the function name (string) to a symbol, push it on the stack, and
  // wrap it in a quote:
  PROC_push_symbol(fn);
  PROC_make_function_call("quote", 1);
  // Turn the array 'x' into a Lisp list and leave it at the top of the "stack".
  C_darray_to_Lisp_list(n,x);
  // Wrap it in a quote:
  PROC_make_function_call("quote", 1);
  // Evaluate a call to the Reduce algebraic function 'fn' that takes an n-list
  // of reals 'x', and delivers either a single real, f(x), or, if 'grad' is not
  // NULL, the flattened (n+1)-list of reals {f(x),grad(x)}.
  int32_t r = PROC_make_function_call("call_alg_fn_list2list", 2);
  PROC_lisp_eval();
  if (DEBUG > 1) {
    fprintf(stderr, "  %s(", fn);
    for (int i=0; i<n; i++) {
      fprintf(stderr, "%.4g", x[i]);
      if (i < n-1) fprintf(stderr, ",");
    }
  };
  if (grad) {
    // If 'grad' is not NULL, the Reduce function 'fn' is expected to return a
    // flattened list {f(x),grad(x)}, where grad(x) is an n-list which should
    // be assigned to 'grad'. (Also see the function red_mfunc_wrap.)
    PROC_handle y = PROC_get_value();
    z = PROC_floating_value(PROC_first(y));
    if (DEBUG > 1) {
      fprintf(stderr, ") = %.5g\n", z);
      fprintf(stderr, "  grad = {");
    };
    y = PROC_rest(y);
    for (int i = 0; i < n; i++) {
      grad[i] = PROC_floating_value(PROC_first(y));
      y = PROC_rest(y);
      if (DEBUG > 1) {
	fprintf(stderr, "%.4g", grad[i]);
	if (i < n-1) fprintf(stderr, ",");
      }
    }
    if (DEBUG > 1) fprintf(stderr, "}\n");
  }
  else {  // grad is NULL, result is just f(x)
    z = PROC_floating_value(PROC_get_value());
    if (DEBUG > 1) fprintf(stderr, ") = %.5g\n", z);
  }
  return z;
}



// Modelled after F77_nlo_set_min_objective in api/f77funcs_.h.
int32_t NLOPT_set_min_objective(char *fname) {
  // In the call to nlopt_set_min_objective:
  //   1. The wrapper red_func_wrap is the nlopt_func argument,
  //   2. The name of the Reduce function defining the objective is the *f_data argument,
  //   3. We can't just pass fname to to this argument, we need the string rfun on the heap!
  char *rfun = malloc(strlen(fname)*sizeof(char)+1);
  strcpy(rfun,fname);
  return nlopt_set_min_objective(opt, red_func_wrap, rfun);
}

int32_t NLOPT_set_max_objective(char *fname) {
  char *rfun = malloc(strlen(fname)*sizeof(char)+1);
  strcpy(rfun,fname);
  return nlopt_set_max_objective(opt, red_func_wrap, rfun);
}

int32_t NLOPT_optimize(double *x0, int32_t n) {
  double *x, f;
  x = (double *) malloc(n*sizeof(double));
  for (int j=0; j<n; j++) x[j] = x0[j];
  if (DEBUG) fprintf(stderr, "NLOPT_optimize:\n");
  int32_t r = nlopt_optimize(opt, x, &f);
  // assign results to the static 'result' array:
  result = (double *) malloc((n+1)*sizeof(double));
  result[0] = f;
  for (int j=0; j<n; j++) result[j+1] = x[j];
  free(x);
  if (DEBUG) {
    fprintf(stderr, "  f = %f\n", result[0]);
    fprintf(stderr, "  result =");
    for (int j=0; j<n; j++)
      fprintf(stderr, " %.5g", result[j+1]);
    fprintf(stderr, "\n");
  }
  return r;
}

double get_result(int32_t i) {
  return result[i];
}

void free_result() {
  free(result);
}


// ================================================================
// Setting the local optimization sub-algorithm
// ================================================================

int32_t NLOPT_set_local_optimizer(int32_t anum) {
  local_opt = nlopt_create(anum, nlopt_get_dimension(opt));
  return nlopt_set_local_optimizer(opt, local_opt);
}


// =============================================================================
// Defining scalar constraints
// =============================================================================

// Note: in the next two functions
// 1. The wrapper function red_func_wrap is the nlopt_func argument,
// 2. The name of the Reduce function defining the constraint is the *f_data argument,
// 3. We can't just pass c_fname to to this argument, we need the string cfun on the heap!

int32_t NLOPT_add_eq_constraint(char *c_fname, double tol) {
  char *cfun = malloc(strlen(c_fname)*sizeof(char)+1);
  assert(cfun != NULL);
  strcpy(cfun,c_fname);
  if (DEBUG) fprintf(stderr, "added '%s' equality constraint, %.3g\n", cfun, tol);
  return nlopt_add_equality_constraint(opt, red_func_wrap, cfun, tol);
}
int32_t NLOPT_add_ineq_constraint(char *c_fname, double tol) {
  char *cfun = malloc(strlen(c_fname)*sizeof(char)+1);
  assert(cfun != NULL);
  strcpy(cfun,c_fname);
  if (DEBUG) fprintf(stderr, "added '%s' inequality constraint, %.3g\n", cfun, tol);
  return nlopt_add_inequality_constraint(opt, red_func_wrap, cfun, tol);
}

// =============================================================================
// Defining vector-valued constraints
// =============================================================================

// This function is internal to the interface (static), and is of type nlopt_mfunc.
// It is modelled after f77_mfunc_wrap in api/f77api.c.  It is used as a wrapper for 
// functions that, given an n-vector 'x', return an m-vector in 'result'.
static void red_mfunc_wrap(unsigned m, double *result, unsigned n, const double *x, 
			   double *grad, void *f_data) {
  char *fn = (char *) f_data;
  if (DEBUG > 1) {
    fprintf(stderr, "red_mfunc_wrap: %s", fn);
    if (grad) fprintf(stderr, " [G]");
    fprintf(stderr, "\n");
  }
  // Convert the function name (string) to a symbol, push it on the stack, and
  // wrap it in a quote:
  PROC_push_symbol(fn);
  PROC_make_function_call("quote", 1);
  // Turn the array x into a Lisp list and leave it at the top of the "stack".
  C_darray_to_Lisp_list(n,x);
  // Wrap it in a quote:
  PROC_make_function_call("quote", 1);
  // Evaluate a call to the Reduce m-dimensional algebraic function fn: R^n -> R^m
  int32_t r = PROC_make_function_call("call_alg_fn_list2list", 2);
  PROC_lisp_eval();
  if (DEBUG > 1) {
    fprintf(stderr, "  %s(", fn);
    for (int i=0; i<n; i++) {
      fprintf(stderr, "%.4g", x[i]);
      if (i < n-1) fprintf(stderr, ",");
    }
    fprintf(stderr, ") = {");
  }
  // If 'grad' is NULL, the result is a an m-list, which we assign to the C
  // array 'result' element-by-element.  If 'grad' is non-NULL, then it points
  // to an array of length m*n, and the result of 'fn' also contains a list of
  // length m*n, the gradients of the constraint functions with respect to x,
  // and 'grad' should be set to this list.  It is assumed that ∂c_i/∂x_j is
  // stored in grad[i*n + j].  
  // Irrespective of 'grad', we first get the first m elements of the list and
  // assign them to 'result'.
  PROC_handle y = PROC_get_value();
  for (int i = 0; i < m; i++) {
    result[i] = PROC_floating_value(PROC_first(y));
    y = PROC_rest(y);
    if (DEBUG > 1) {
      fprintf(stderr, "%.4g", result[i]);
      if (i < m-1)  fprintf(stderr, ",");
    }
  }
  if (DEBUG > 1) fprintf(stderr, "}\n");
  if (grad) {  
    // Now handle the last m*n elements of what 'fn' has returned
    if (DEBUG > 1) fprintf(stderr, "  grad = {");
    for (int i = 0; i < m*n; i++) {
      grad[i] = PROC_floating_value(PROC_first(y));
      y = PROC_rest(y);
      if (DEBUG > 1) {
	fprintf(stderr, "%.4g", grad[i]);
	if (i < m*n-1) fprintf(stderr, ",");
      }
    }
    if (DEBUG > 1) fprintf(stderr, "}\n");
  }
}



// Note: look at the notes for the functions for scalar constraints
int32_t NLOPT_add_eq_mconstraint(char *c_fname, int32_t m, double *tol) {
  char *cfun = malloc(strlen(c_fname)*sizeof(char)+1);
  assert(cfun != NULL);
  strcpy(cfun,c_fname);
  if (DEBUG) fprintf(stderr, "added '%s' equality m-constraint\n", cfun);
  return nlopt_add_equality_mconstraint(opt, m, red_mfunc_wrap, cfun, tol);
}
int32_t NLOPT_add_ineq_mconstraint(char *c_fname, int32_t m, double *tol) {
  char *cfun = malloc(strlen(c_fname)*sizeof(char)+1);
  assert(cfun != NULL);
  strcpy(cfun,c_fname);
  if (DEBUG) fprintf(stderr, "added '%s' inequality m-constraint\n", cfun);
  return nlopt_add_inequality_mconstraint(opt, m, red_mfunc_wrap, cfun, tol);
}


// =============================================================================
// Removing constraints
// =============================================================================

int32_t NLOPT_remove_eq_constraints() {
  return nlopt_remove_equality_constraints(opt);
}
int32_t NLOPT_remove_ineq_constraints() {
  return nlopt_remove_inequality_constraints(opt);
}

// =============================================================================
// Step size for algorithms without derivatives
// =============================================================================

int32_t NLOPT_set_initial_step(const double *dx) {
  return nlopt_set_initial_step(opt, dx);
}
int32_t NLOPT_set_initial_step1(double dx) {
  return nlopt_set_initial_step1(opt, dx);
}

// ============================================================================
// Stochastic search algorithms
// ============================================================================

int32_t NLOPT_set_population(int p) {
  return nlopt_set_population(opt, (unsigned) p);
}

void NLOPT_srand(int64_t seed) {
  nlopt_srand((unsigned long) seed);
}
