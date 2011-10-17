/* file asps.c */

/* Signature: 3637adcc 27-Jan-1997 */

#include <stdarg.h>
#include <sys/types.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "entries.h"
#include "arith.h"

#ifndef WINDOWS_NT
#define __stdcall
#endif

/*
 * The overall design for the asps mechanism relies on the following facts:
 *  1. No NAG routine uses the same type of ASP more than once.
 *  2. We have a hard-coded limit of 10 Asps in use at any one time (in
 *     theory we could make this 10 Asps per NAG routine by changing the
 *     storage strategy for the code/environment pairs).
 *  3. If NAG routines call one another, they do it via the top-level AXIOM
 *     interfaces (and so go through the setup/restore process.
 *
 *  The code and environment are the values obtained by applying car and cdr
 *  respectively to a spadclosure.  They are used in calling funcall in lisp
 *  as follows:
 *   (FUNCALL code arg1 arg2 ... argn environment)
 *
 *  When we call setup on an asp, we push the code part onto user_base_0 and
 *  the environment onto user_base_1 (which we treat as Lisp lists), and then
 *  store the index in user_base_0/user_base_1 into the appropriate variable
 *  (this is the index counting from the base).
 *
 *  When we call an asp we copy the appropriate code/environment portions onto
 *  users_base_2 and user_base_3, and pass them as arguments to Lfuncall and
 *  friends.
 *
 *  When we call restore on an asp we pop user_base_0/user_base_1 (this is
 *  dodgey in one sense, but we assume that we restore all the asps from a
 *  NAG call at the same time so the order in which we pop the user_bases is
 *  in fact immaterial).  Finally we restore the old asp_n_pointer value.
 *
 */

extern Lisp_Object user_base_0, user_base_1, user_base_2, user_base_3;

#define CODE_STACK user_base_0
#define ENVIRONMENT_STACK user_base_1
#define CODE user_base_2
#define ENVIRONMENT user_base_3

/* The number of asps on the stacks at present. */
int32 stack_depth=0;

/*
 * The current location of an asp's code/environment is stored on a stack, so
 * that we can nest calls which use asps.
 *
 */
typedef struct Asp_Loc {
  int32 loc;
  struct Asp_Loc *next;
} Asp_Loc;

Asp_Loc *asp1_index=NULL,*asp4_index=NULL,*asp6_index=NULL,*asp35_index=NULL;

#define location(asp) \
  (asp == NULL) ? aerror0("Asp calling mechanism corrupted"): asp -> loc;

Asp_Loc *push_asp_num(Asp_Loc *asp) {
  Asp_Loc *new;

  new = (Asp_Loc *)malloc(sizeof(Asp_Loc));
  new->next = asp;
  new->loc  = stack_depth;
  return(new);
}

#define pop_asp_num(asp) asp->next

void push_asp(Lisp_Object nil, Lisp_Object f_code, Lisp_Object f_env)
{
  Lisp_Object w;
  if (stack_depth == 0) {
    push(f_env);
    w = ncons(f_code);
    pop(f_env);
    errexitv();
    f_code = w;
    push(f_code);
    w = ncons(f_env);
    pop(f_code);
    errexitv();
    f_env = w;
    CODE_STACK = f_code;
    ENVIRONMENT_STACK = f_env;
  }
  else {
    push(f_env);
    w = Lcons(nil,f_code,CODE_STACK);
    pop(f_env);
    errexitv();
    f_code = w;
    push(f_code);
    w = Lcons(nil,f_env,ENVIRONMENT_STACK);
    pop(f_code);
    errexitv();
    f_env = w;
    CODE_STACK = f_code;
    ENVIRONMENT_STACK = f_env;
  }

  ++ stack_depth;
}

void pop_asp(Lisp_Object nil)
{
  CODE_STACK=qcdr(CODE_STACK);
  ENVIRONMENT_STACK=qcdr(ENVIRONMENT_STACK);
  -- stack_depth;
}

#define get_code(index) Lelt(C_nil,CODE_STACK,fixnum_of_int(stack_depth-index))
#define get_env(index) Lelt(C_nil,ENVIRONMENT_STACK,fixnum_of_int(stack_depth-index))

/*
 * This function restores the global variables which are used in calling asps
 * to their previous state.
 */
Lisp_Object asp_restore(Lisp_Object nil, int32 asp)
{ 
  pop_asp(nil);
  switch (int_of_fixnum(asp))
  {
    case 1:
      asp1_index = pop_asp_num(asp1_index);
      break;
    case 4:
      asp4_index = pop_asp_num(asp4_index);
      break;
    case 6:
      asp6_index = pop_asp_num(asp6_index);
      break;
    case 35:
      asp35_index = pop_asp_num(asp35_index);
      break;
    default:
      aerror1("asp_restore: Unknown asp type:",asp);
      break;
  }

  return onevalue(lisp_true);
}

/*
 * This function sets up the global variables which are needed in calling asps
 */
Lisp_Object MS_CDECL asp_set(Lisp_Object nil, int nargs, ...)
{ 
  int32 asp;
  va_list args;
  Lisp_Object aspnum, f_car, f_cdr;

  argcheck(nargs,3,"asp_set");
  va_start(args,nargs);
  aspnum = va_arg(args, Lisp_Object);
  f_car  = va_arg(args, Lisp_Object);
  f_cdr  = va_arg(args, Lisp_Object);
  va_end(args);

  asp = int_of_fixnum(aspnum);

  switch (asp)
  {
    case 1:
      push_asp(nil,f_car, f_cdr);
      errexit();
      asp1_index = push_asp_num(asp1_index);
      break;
    case 4:
      push_asp(nil,f_car, f_cdr);
      errexit();
      asp4_index = push_asp_num(asp4_index);
      break;
    case 6:
      push_asp(nil,f_car, f_cdr);
      errexit();
      asp6_index = push_asp_num(asp6_index);
      break;
    case 35:
      push_asp(nil,f_car, f_cdr);
      errexit();
      asp35_index = push_asp_num(asp35_index);
      break;
    default:
      aerror1("asp_set: Unknown asp type:",aspnum);
      break;
  }

  return onevalue(lisp_true);
}

/* Routines for converting between representations. */
Lisp_Object mkAXIOMVectorDF(double *v, int32 dim)
{
  Lisp_Object nil=C_nil;
  Lisp_Object new, Lflt;
  int32 i;

  new = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*dim+4);
  errexit();
  /* vectors must pad to an even number of words */
  if ((dim & 1) == 0) elt(new,dim) = nil;

  for (i=0;i<dim;++i) {
    push(new);
    Lflt = make_boxfloat(*(v+i),TYPE_DOUBLE_FLOAT);
    pop(new);
    errexit();
    elt(new,i) = Lflt;
  }

  return onevalue(new);
}

void mkFortranVectorDouble(double *loc, Lisp_Object v, int32 dim)
{
  int32 i;
  Lisp_Object nil=C_nil;

  for (i=0;i<dim;++i) {
    push(v);
    *(loc + i) = float_of_number(elt(v,i));
    pop(v);
  }
}

void mkFortran2DArrayDouble(double *loc, Lisp_Object v, int32 rows, int32 cols)
{
  int32 i,j;
  Lisp_Object nil=C_nil;

  for (i=0;i<rows;++i) 
    for (j=0;j<cols;++j) {
      push(v);
      *(loc + j*cols + i) = float_of_number(elt(v,i*cols+j));
      pop(v);
    }
}


/* Code for ASP1 */

double __stdcall asp1 (double *x)
{
  Lisp_Object arg = make_boxfloat(*x,TYPE_DOUBLE_FLOAT), result, code, env;
  Lisp_Object nil = C_nil;

  code = get_code(asp1_index->loc);
  env  = get_env(asp1_index->loc);
  result = Lfuncalln(C_nil,3,code,arg,env);
  errexit();

  if (exception_pending()) aerror0("Error in evaluating function (ASP1)");

  return float_of_number(result);
}

#ifdef TEST_ASPS
Lisp_Object test_asp1(Lisp_Object nil, Lisp_Object a)
{  
  double arg = float_of_number(a);
  arg=asp1(&arg);
  return make_boxfloat(arg,TYPE_DOUBLE_FLOAT);
}
#endif

/* Code for ASP4 */

double __stdcall asp4 (int32 *ndim, double *x)
{
  Lisp_Object arg, result, code, env;

  arg = mkAXIOMVectorDF(x,*ndim); 
  code = get_code(asp4_index->loc);
  env  = get_env(asp4_index->loc);

  result = Lfuncalln(C_nil,3,code,arg,env);

  return float_of_number(result);
}

#ifdef TEST_ASPS
Lisp_Object test_asp4(Lisp_Object nil, Lisp_Object v)
{
  double *x;
  int ndim;
  Lisp_Object result;

  ndim = (length_of_header(vechdr(v)) - 4)/4;
  x = (double *)malloc(ndim*sizeof(double));
  mkFortranVectorDouble(x,v,ndim);

  result = make_boxfloat(asp4(&ndim,x),TYPE_DOUBLE_FLOAT);
  free(x);
  return(result);
}
#endif

/* Code for ASP6 */

void __stdcall asp6 (int32 *n, double *x, double *fvec, int32 *iflag)
{
  Lisp_Object arg, code, env;

  arg = mkAXIOMVectorDF(x,*n); 

  code = get_code(asp6_index->loc);
  env  = get_env(asp6_index->loc);

  mkFortranVectorDouble(fvec,Lfuncalln(C_nil,3,code,arg,env),*n);
}

#ifdef TEST_ASPS
Lisp_Object test_asp6(Lisp_Object nil, Lisp_Object v)
{
  double *x, *fvec;
  int n,iflag;
  Lisp_Object result;

  n = (length_of_header(vechdr(v)) - 4)/4;
  x = (double *)malloc(n*sizeof(double));
  fvec = (double *)malloc(n*sizeof(double));

  mkFortranVectorDouble(x,v,n);

  asp6(&n,x,fvec,&iflag);
  result = mkAXIOMVectorDF(fvec,n);
  free(x);
  free(fvec);
  return(result);
}
#endif

/* Code for ASP35 */

void __stdcall asp35 (int32 *n, double *x, double *fvec, double *fjac,
                      int32 *ldfjac, int32 *iflag)
{
  Lisp_Object Lx, Liflag, Lresult, code, env;

  Lx = mkAXIOMVectorDF(x,*n);
  Liflag = fixnum_of_int(*iflag);

  code = get_code(asp35_index->loc);
  env  = get_env(asp35_index->loc);

  Lresult = Lfuncalln(C_nil,4,code,Lx,Liflag,env);

  if (*iflag == 1)
    mkFortranVectorDouble(fvec,Lresult,*n);
  else
    mkFortran2DArrayDouble(fjac,Lresult,*ldfjac,*n);
}

#ifdef TEST_ASPS
Lisp_Object test_asp35(Lisp_Object nil, Lisp_Object v, Lisp_Object flag)
{
  double *x, *fvec, *fjac;
  int n, ldfjac, iflag;
  Lisp_Object result;

  n = (length_of_header(vechdr(v)) - 4)/4;
  ldfjac=n;
  x = (double *)malloc(n*sizeof(double));
  mkFortranVectorDouble(x,v,n);
  fjac = (double *)malloc(n*ldfjac*sizeof(double));
  fvec = (double *)malloc(n*sizeof(double));
  iflag=int_of_fixnum(flag);

  asp35(&n,x,fvec,fjac,&ldfjac,&iflag);
  if (iflag == 1)
    result = mkAXIOMVectorDF(fvec,n);
  else
    result = mkAXIOMVectorDF(fjac,n*ldfjac);
  free(x);
  free(fjac);
  free(fvec);
  return(result);
}
#endif

#ifndef TEST_ASPS
Lisp_Object asp_error1(Lisp_Object nil, Lisp_Object a1)
{
  return aerror0("The Windows version of the NAG Link is not installed");
}

Lisp_Object asp_error2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2)
{
  return aerror0("The Windows version of the NAG Link is not installed");
}

Lisp_Object MS_CDECL asp_error0(Lisp_Object nil, int32 nargs, ...)
{
  return aerror0("The Windows version of the NAG Link is not installed");
}
#endif

setup_type const asp_setup[] =
{
    {"asp-setup",	wrong_no_na,	wrong_no_nb,	asp_set},
    {"asp-restore",	asp_restore,    too_many_1,     wrong_no_1},
#ifdef TEST_ASPS
    {"asp1",		test_asp1,	too_many_1,	wrong_no_1},
    {"asp4",		test_asp4,	too_many_1,	wrong_no_1},
    {"asp6",		test_asp6,	too_many_1,	wrong_no_1},
    {"asp35",		too_few_2,	test_asp35,	wrong_no_2},
#else
    {"asp1",		asp_error1,     asp_error2,     asp_error0},
    {"asp4",		asp_error1,     asp_error2,     asp_error0},
    {"asp6",		asp_error1,     asp_error2,     asp_error0},
    {"asp35",		asp_error1,     asp_error2,     asp_error0},
#endif
    {NULL,		0,		0,		0}
};

/* end of file asps.c */
