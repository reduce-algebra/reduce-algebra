/* ----------------------------------------------------------------------
   $Id$
   ----------------------------------------------------------------------
   (c) 2013 T. Sturm
   ----------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   
      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.
   
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include <stdio.h>
#include <stdlib.h>
#include <gurobi_c.h>
#include <inttypes.h>

#define VERBOSE 0

#define ERRORCHECK(error) if (error) {fprintf(stderr, "ERROR: %s\n", GRBgeterrormsg(env)); GRBwrite(model, "/tmp/error.lp"); exit(1);}

static GRBenv *env = NULL;
static GRBmodel *model = NULL;
static int NumVars = 0;
static int *ind = NULL;
static double *Val  = NULL;
static int ValIndex = 0;

void gurobi_newmodel(int32_t, int32_t);
void gurobi_addvars(int32_t, int32_t);
int32_t gurobi_numVars(void);
void gurobi_addconstr(char*, double*, double);
void gurobi_addconstrFast(char*, double);
void gurobi_delconstr1(void);
void gurobi_delconstr(int32_t);
void gurobi_updatemodel(void);
void gurobi_negconstr1(void);
void gurobi_negconstr(int32_t);
void gurobi_write(char*);
const char *gurobi_optimize(void);
double gurobi_getSol(int32_t);
void gurobi_freemodel(void);
double *gurobi_newDoubleArray(int32_t);
void gurobi_setDoubleArray(double*, int32_t, double);
void gurobi_freeDoubleArray(double*);
void gurobi_pushToVal(double);
int32_t *newInt32Array(int);
void gurobi_setInt32Array(int32_t*, int, int32_t);
void gurobi_freeInt32Array(int32_t*);
int32_t *gurobi_newInd(int);
#ifdef DEBUG
int gurobi_cfprintf(FILE*, const char*, ...);
#endif

void gurobi_newmodel(int32_t n, int32_t m) {
  int error;

  error = GRBloadenv(&env, NULL);
  ERRORCHECK(error || env == NULL);

  error = GRBnewmodel(env, &model, NULL, 0, NULL, NULL, NULL, NULL, NULL);
  ERRORCHECK(error);

  error = GRBsetintparam(GRBgetenv(model), "OutputFlag", 0);
  ERRORCHECK(error);

  gurobi_addvars(n, m);

#ifdef DEBUG
  gurobi_cfprintf(stderr, "env = %p, model = %p\n", env, model);
#endif
}

void gurobi_addvars(int32_t n, int32_t m) {
  double *lb;
  int i;
  int error;
  char *vtype;

  NumVars = n+m;

  ind = (int *)malloc((n+m) * sizeof(int));
  Val = (double *)malloc((n+m) * sizeof(double));
  ValIndex = 0;
  lb = (double *)malloc((n+m) * sizeof(double));
  vtype = (char *)malloc((n+m) * sizeof(char));

  for (i=0; i<n+m; i++) {
    ind[i] = i;
    lb[i] = - GRB_INFINITY;
    vtype[i] = (i<n) ? GRB_CONTINUOUS : GRB_INTEGER;
  }

  error = GRBaddvars(model, n+m, 0, NULL, NULL, NULL, NULL, lb, NULL, vtype, NULL);
  ERRORCHECK(error);

  error = GRBupdatemodel(model);
  ERRORCHECK(error);

#ifdef DEBUG
  gurobi_cfprintf(stderr, "successfully exiting gurobi_addvars, n = %d\n", n);
#endif
}

void gurobi_updatemodel(void) {
  int error;

  error = GRBupdatemodel(model);
  ERRORCHECK(error);
}

int32_t gurobi_numVars(void) {
  return NumVars;
}

void gurobi_addconstr(char rel[], double val[], double c) {
  int error;

  /* gurobi_cfprintf(stderr, "entering gurobi_addconstr: model = %p, NumVars = %d, rel = '%c', ind = %p, val=%p, c=%f\n", model, NumVars, rel[0], ind, val, c); */

#ifdef DEBUG
  gurobi_cfprintf(stderr, "ind = {%d, %d}, val = {%f, %f}\n", ind[0], ind[1], val[0], val[1]);
#endif
  error = GRBaddconstr(model, NumVars, ind, val, rel[0], c, NULL);
  ERRORCHECK(error);

#ifdef DEBUG
  gurobi_cfprintf(stderr, "successfully exiting gurobi_addconstr: model = %p, NumVars = %d, rel = '%c', ind = %p, val=%p, c=%f\n", model, NumVars, rel[0], ind, val, c);
#endif
}

void gurobi_addconstrFast(char rel[], double c) {
  int error;

  /* gurobi_cfprintf(stderr, "ind = {%d, %d}, val = {%f, %f}\n", ind[0], ind[1], val[0], val[1]);*/

  error = GRBaddconstr(model, NumVars, ind, Val, rel[0], c, NULL);
  ERRORCHECK(error);

  ValIndex = 0;

#ifdef DEBUG
  gurobi_cfprintf(stderr, "successfully exiting gurobi_addconstrFast: model = %p, NumVars = %d, rel = '%c', ind = %p, Val=%p, c=%f\n", model, NumVars, rel[0], ind, Val, c);
#endif
}

void gurobi_delconstr1(void) {
  /* for backward compatibility */
  gurobi_delconstr(0);
}

void gurobi_delconstr(int32_t n) {
  int error;
  int row[] = {(int)n};

  error = GRBdelconstrs(model, 1, row);
  ERRORCHECK(error);
}

void gurobi_negconstr1(void) {
  /* for backward compatibility */
  gurobi_negconstr(0);
}

void gurobi_negconstr(int32_t n) {
  
  int i;
  int error;
  double v;
  int cind[NumVars];

  for (i=0; i<NumVars; i++) {
    cind[i] = n;
    error = GRBgetcoeff (model, n, i, &v);
    ERRORCHECK(error);
    Val[i] = -v;
  }

  error = GRBchgcoeffs(model, NumVars, cind, ind, Val);
  if (error) {
    printf("NumVars = %d\n", NumVars);
    for (i=0; i<NumVars; i++) {
      printf("Val[%d]=%f ", i, Val[i]);
    }
    printf("\n");
    for (i=0; i<NumVars; i++) {
      printf("ind[%d]=%d ", i, ind[i]);
    }
    printf("\n");
  }
  ERRORCHECK(error);
}

void gurobi_write(char *fn) {
  int error;

  error = GRBwrite(model, fn);
  ERRORCHECK(error);
}

const char *gurobi_optimize(void) {
  int error;
  int optimstatus;

  error = GRBoptimize(model);
  ERRORCHECK(error);

  error = GRBgetintattr(model, GRB_INT_ATTR_STATUS, &optimstatus);
  ERRORCHECK(error);

  switch (optimstatus) {
  case GRB_OPTIMAL:
    return "optimal";
  case GRB_UNBOUNDED:
    return "unbounded";
  case GRB_INFEASIBLE:
    return "infeasible";
  default:
    return "error";
  }
}

double gurobi_getSol(int32_t i) {
  int error;
  double sol[1];
  
  error = GRBgetdblattrarray(model, GRB_DBL_ATTR_X, (int)i - 1, 1, sol);
  ERRORCHECK(error);

  return sol[0];
}

void gurobi_freemodel() {
  GRBfreemodel(model);
  GRBfreeenv(env);
  free(ind);
  free(Val);
  model = NULL;
  env = NULL;
  ind = NULL;
  NumVars = 0;
  ValIndex = 0;
}

double *gurobi_newDoubleArray(int32_t len) {
  double *a;

  a = (double *)malloc(len * sizeof(double));

#ifdef DEBUG
  gurobi_cfprintf(stderr, "created array a = %p of size %d\n", a, len);
#endif
  return a;
}

void gurobi_setDoubleArray(double a[], int32_t i, double x) {
#ifdef DEBUG
  gurobi_cfprintf(stderr, "setting a[%d] = %f, where a = %p\n", i, x, a);
#endif
  a[i] = x;
}

void gurobi_freeDoubleArray(double a[]) {
  free(a);
}

void gurobi_pushToVal(double x) {
  Val[ValIndex++] = x;
}

int32_t *gurobi_newInt32Array(int len) {
  return (int32_t *)malloc(len * sizeof(int32_t));
}

void gurobi_setInt32Array(int32_t a[], int i, int32_t x) {
  a[i] = x;
}

void gurobi_freeInt32Array(int32_t a[]) {
  free(a);
}

int32_t *gurobi_newInd(int len) {
  int32_t *a;
  int i;
  
  a = (int32_t *)malloc(len * sizeof(int32_t));
  for (i=0; i<len; i++)
    a[i] = i + 1;
  return a;
}

#ifdef DEBUG
int gurobi_cfprintf(FILE *file, const char *msg, ...) {
  int ecode=0;

  if (file && VERBOSE) {
    va_list ap;
  
    va_start(ap, msg);
    ecode = vfprintf(file, msg, ap);
    va_end(ap);
    fflush(file);
  }

  return ecode;
}
#endif
