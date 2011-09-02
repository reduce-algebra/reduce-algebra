/* file nag.c */

/* Signature: 0506e9a8 27-Jan-1997 */


#include <stdarg.h>
#include <sys/types.h>
#include <string.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "entries.h"
#include "arith.h"

#ifdef TESTNAG

#ifdef LOADLIB	/* load DLLs when necessary */

#undef IGNORE		/* avoid conflicting macro definitions */
#include <windows.h>		/* is this OK here? */

#else	/* load DLLs when program is first run */

/* Temporary fix to take account of different naming conventions */
#if defined(__alpha)
#define D01AJF d01ajf_
#define SXXEAF sxxeaf_
#elif 1	/* DLL from FPSNT / Win32 version */			/* FIXME */
/* leave D01AJF etc as it is (DLL exports _D01AJF@48) */
#else 
#define D01AJF d01ajf
#define SXXEAF sxxeaf
#endif

#endif	/* LOADLIB */

#ifdef LOADLIB
HINSTANCE prevlib = NULL, currlib = NULL;
void free_prevlib ();
#endif

typedef struct
{
  char *str;
  int32 len;	/* or unsigned? */
} fstring1;


/*
   This checks a 32 bit integer's value and returns it as either a fixnum
   or a bignum.
*/
#define int2ccl(i)\
  (i > -268435455 && i < 268435456) ? fixnum_of_int(i) : make_one_word_bignum(i)


extern void mkFortranVectorDouble(double *loc, Lisp_Object v, int32 dim);

#include "nag_d.c"	/* D chapter routines */
#include "nag_s.c"	/* S chapter routines */


/*
 * Turn a vector of ints into a Lisp vector of vectors, corresponding to
 * the AXIOM representation of a Matrix(Integer).
 */
Lisp_Object mkIntVector(int32 v[], int32 nrows, int32 ncols)
{
  Lisp_Object nil=C_nil;
  Lisp_Object new, new_row;
  int32 i,j;

  new = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*nrows+4);
  errexit();
  /* vectors must pad to an even number of words */
  if ((nrows & 1) == 0) elt(new,nrows) = nil;
  for (i=0;i<nrows;++i) {
    new_row = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*ncols+4);
    errexit();
    /* vectors must pad to an even number of words */
    if ((ncols & 1) == 0) elt(new_row,ncols) = nil;
    for (j=0;j<ncols;++j) elt(new_row,j) = int2ccl(v[i*ncols+j]);
    elt(new,i) = new_row;
  }

  return onevalue(new);
}

/* 
 * Turn a vector of doubles into a Lisp vector of vectors, corresponding to
 * the AXIOM representation of a Matrix(DoubleFloat).
 */
Lisp_Object mkFloatVector(double v[], int32 nrows, int32 ncols)
{
  Lisp_Object nil=C_nil;
  Lisp_Object new, new_row, Lflt;
  int32 i, j;

  new = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*nrows+4);
  errexit();
  /* vectors must pad to an even number of words */
  if ((nrows & 1) == 0) elt(new,nrows) = nil;
  for (i=0;i<nrows;++i) {
    push(new);
    new_row = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*ncols+4);
    pop(new);
    errexit();
    /* vectors must pad to an even number of words */
    if ((ncols & 1) == 0) elt(new_row,ncols) = nil;
    for (j=0;j<ncols;++j) {
      push2(new, new_row);
      Lflt = make_boxfloat(v[i*ncols+j],TYPE_DOUBLE_FLOAT);
      pop2(new_row, new);
      errexit();
      elt(new_row,j) = Lflt;
    }
    elt(new,i) = new_row;
  }

  return onevalue(new);
}

typedef struct complex{
  double re;
  double im;
} complex;

/* 
 * Turn a vector of complexes into a Lisp vector of vectors, corresponding to
 * the AXIOM representation of a Matrix(Complex DoubleFloat).
 */
Lisp_Object mkComplexVector(complex v[], int32 nrows, int32 ncols)
{
  Lisp_Object nil=C_nil;
  Lisp_Object new, new_row, Lflt1, Lflt2;
  complex z;
  int32 i, j;

  new = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*nrows+4);
  errexit();
  /* vectors must pad to an even number of words */
  if ((nrows & 1) == 0) elt(new,nrows) = nil;
  for (i=0;i<nrows;++i) {
    push(new);
    new_row = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*ncols+4);
    pop(new);
    errexit();
    /* vectors must pad to an even number of words */
    if ((ncols & 1) == 0) elt(new,ncols) = nil;
    for (j=0;j<ncols;++j) {
      push2(new, new_row);
      z = v[i*ncols+j];
      Lflt1 = make_boxfloat(z.re,TYPE_DOUBLE_FLOAT);
      Lflt2 = make_boxfloat(z.im,TYPE_DOUBLE_FLOAT);
      pop2(new_row, new);
      errexit();
      elt(new_row,j) = Lcons(nil,Lflt1,Lflt2);
    }
    elt(new,i) = new_row;
  }

  return onevalue(new);
}

#if 0
Lisp_Object MS_CDECL Ls01eaf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lzr, Lzi, Lifail;
  double z[2], result[2];
  int32 ifail;
  /*
   * Returning DOUBLE COMPLEX objects via the function name is not portable
   * so we use a dummy subroutine as glue.
   */
#ifdef LOADLIB
  typedef void (__stdcall *PSXXEAF) (double *, double *, int*);
  HINSTANCE hLib;
  PSXXEAF sxxeaf_proc;
#else
#if 0
  extern void SXXEAF();
#else
  extern void __stdcall SXXEAF (double *, double *, int32 *);
#endif
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,3,"Ls01eaf");
  va_start(args,nargs);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push3(Lzr,Lzi,Lifail);
  z[0] = float_of_number(Lzr);
  pop3(Lifail,Lzi,Lzr);
  errexit();
  push3(Lzr,Lzi,Lifail);
  z[1] = float_of_number(Lzi);
  pop3(Lifail,Lzi,Lzr);
  errexit();
  push3(Lzr,Lzi,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop3(Lifail,Lzi,Lzr);
  errexit();

  /* Call NAG routine */
#ifdef LOADLIB
  if ( (hLib = LoadLibrary ("sxxeafdl")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    result[0] = 999.999;				/* FIXME */
    result[1] = 999.999;
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (sxxeaf_proc = (PSXXEAF) GetProcAddress (hLib, "_SXXEAF@12"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      result[0] = 999.999;					/* FIXME */
      result[1] = 999.999;
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*sxxeaf_proc) (z, result, &ifail);
    }
    if ( FreeLibrary (hLib) == FALSE )
    {
      /* couldn't free library -- possible error handling here */
      ifail += 1000;
    }
  }
#else
  SXXEAF(z,result,&ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lzr = make_boxfloat(result[0],TYPE_DOUBLE_FLOAT);
  push(Lzr);
  Lzi = make_boxfloat(result[1],TYPE_DOUBLE_FLOAT);
  pop(Lzr);
  errexit();
  push2(Lzr,Lzi);
  Lifail = int2ccl(ifail);
  pop2(Lzi,Lzr);
  errexit();
  
  return Llist(nil,3,Lzr,Lzi,Lifail);
}

Lisp_Object Ls13aaf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32 ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS13AAF) (double *, int*);
  HINSTANCE hLib;
  PS13AAF s13aaf_proc;
#else
  extern double __stdcall S13AAF (double *, int32 *);
#endif

  /* Translate arguments into C objects */
  push2(Lx,Lifail);
  x = float_of_number(Lx);
  pop2(Lifail,Lx);
  errexit();
  push2(Lx,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop2(Lifail,Lx);
  errexit();

  /* Call NAG routine */
#ifdef LOADLIB
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    y = 999.999;				/* FIXME */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s13aaf_proc = (PS13AAF) GetProcAddress (hLib, "_S13AAF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      y = 999.999;					/* FIXME */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s13aaf_proc) (&x, &ifail);
    }
    if ( FreeLibrary (hLib) == FALSE )
    {
      /* couldn't free library -- possible error handling here */
      ifail += 1000;
    }
  }
#else
  y = S13AAF(&x,&ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
  push(Ly);
  Lifail = int2ccl(ifail);
  pop(Ly);
  errexit();
  
  return Llist(nil,2,Ly,Lifail);
}
#endif	/* s01eaf & s13aaf */

#if 0
Lisp_Object MS_CDECL Ld01ajf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
              Lw, Liw;
  double a, b, epsabs, epsrel, result, abserr, *w;
  int32  ifail, lw, *iw, liw;
#if 0
  extern double asp1();
#else
  extern double __stdcall asp1(double *);
#endif
#ifdef LOADLIB
  typedef void (__stdcall *PD01AJF) (double __stdcall (*fst) (double *),
	  double *, double *, double *, double *, double *, double *,
	  double *, int *, int *, int *, int *);
  HINSTANCE hLib;
  PD01AJF d01ajf_proc;
#else
#if 0
  extern void D01AJF();
#else
  extern void __stdcall D01AJF(double __stdcall (*fst) (double *), double *, double *, double *,
          double *, double *, double *, double *, int *, int *, int *,
          int *);
#endif
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,7,"Ld01ajf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Lepsabs = va_arg(args, Lisp_Object);
  Lepsrel = va_arg(args, Lisp_Object);
  Llw = va_arg(args, Lisp_Object);
  Lliw = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  a = float_of_number(La);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  b = float_of_number(Lb);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  epsabs = float_of_number(Lepsabs);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  epsrel = float_of_number(Lepsrel);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  lw = thirty_two_bits(Llw);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  liw = thirty_two_bits(Lliw);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();

  /* Setup workspace arrays etc. */
  w = (double *)malloc(lw*sizeof(double));
  iw = (int *)malloc(liw*sizeof(int));

  /* Call NAG routine */
#ifdef LOADLIB
  if ( (hLib = LoadLibrary ("d01ajfdl")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    result = 999.999;					/* FIXME */
    ifail = -999;
  }
  else
  {
    if ( (d01ajf_proc = (PD01AJF) GetProcAddress (hLib, "_D01AJF@48")) == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      result = 999.999;						/* FIXME */
      ifail = -998;
    }
    else
    {
      (*d01ajf_proc) (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w, &lw,
	      iw, &liw, &ifail);
    }
    if ( FreeLibrary (hLib) == FALSE )
    {
      /* couldn't free library -- possible error handling here */
      ifail += 1000;
    }
  }
#else
  D01AJF(&asp1,&a,&b,&epsabs,&epsrel,&result,&abserr,w, &lw, iw, &liw, &ifail);
#endif

  /* Translate return values to CCL */
  Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
  push(Lresult);
  Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
  pop(Lresult);
  errexit();
  push2(Lresult,Labserr);
  Lw = mkFloatVector(w,lw,1);
  pop2(Labserr,Lresult);
  errexit();
  push3(Lresult,Labserr,Lw);
  Liw = mkIntVector(iw,liw,1);
  pop3(Lw,Labserr,Lresult);
  errexit();
  push4(Lresult,Labserr,Lw,Liw);
  Lifail = fixnum_of_int(ifail);
  pop4(Liw,Lw,Labserr,Lresult);

/*
  Lw = mkFloatVector(w,lw,1);
  pop2(Labserr,Lresult);
  errexit();
  push3(Lresult,Labserr,Lw);
  Lifail = fixnum_of_int(ifail);
  pop3(Lw,Labserr,Lresult);
*/
  errexit();

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
//  return Llist(nil,4,Lresult,Labserr,Liw,Lifail);
}
#endif	/* Ld01ajf */

Lisp_Object MS_CDECL Lbug(Lisp_Object nil, int nargs, ...)
{
  double *f;
  int i;

  f = (double *)malloc(100*sizeof(double));
  for ( i = 0; i < 100; i++ )
    *(f + i) = (double) i;

  return mkFloatVector(f,100,1);
}


#ifdef LOADLIB
void free_prevlib ()
{
  if ( prevlib != NULL )
    if ( FreeLibrary (prevlib) )
    {
      /* couldn't free library -- possible error handling here */
    }
  prevlib = currlib;
}
#endif

#else

Lisp_Object nag_error1(Lisp_Object nil, Lisp_Object arg)
{
  return aerror0("This version of the NAG Link is not available on this platform");
}

Lisp_Object nag_error2(Lisp_Object nil, Lisp_Object arg1, Lisp_Object arg2)
{
  return aerror0("This version of the NAG Link is not available on this platform");
}

Lisp_Object MS_CDECL nag_error0(Lisp_Object nil, int nargs, ...)
{
  return aerror0("This version of the NAG Link is not available on this platform");
}

#endif

setup_type const nag_setup[] =
{
#ifdef TESTNAG
    {"d01ajf",	wrong_no_na,	wrong_no_nb,	Ld01ajf},
    {"d01akf",	wrong_no_na,	wrong_no_nb,	Ld01akf},
    {"d01alf",	wrong_no_na,	wrong_no_nb,	Ld01alf},
    {"d01amf",	wrong_no_na,	wrong_no_nb,	Ld01amf},
    {"d01anf",	wrong_no_na,	wrong_no_nb,	Ld01anf},
    {"d01apf",	wrong_no_na,	wrong_no_nb,	Ld01apf},
    {"d01aqf",	wrong_no_na,	wrong_no_nb,	Ld01aqf},
    {"d01asf",	wrong_no_na,	wrong_no_nb,	Ld01asf},
    {"d01bbf",	wrong_no_na,	wrong_no_nb,	Ld01bbf},
    {"d01fcf",	wrong_no_na,	wrong_no_nb,	Ld01fcf},
    {"d01gaf",	wrong_no_na,	wrong_no_nb,	Ld01gaf},
    {"d01gbf",	wrong_no_na,	wrong_no_nb,	Ld01gbf},
    {"d02bbf",	wrong_no_na,	wrong_no_nb,	Ld02bbf},
    {"d02bhf",	wrong_no_na,	wrong_no_nb,	Ld02bhf},
    {"d02cjf",	wrong_no_na,	wrong_no_nb,	Ld02cjf},
    {"d02ejf",	wrong_no_na,	wrong_no_nb,	Ld02ejf},
    {"d02gaf",	wrong_no_na,	wrong_no_nb,	Ld02gaf},
    {"d02gbf",	wrong_no_na,	wrong_no_nb,	Ld02gbf},
    {"d02kef",	wrong_no_na,	wrong_no_nb,	Ld02kef},
    {"d02raf",	wrong_no_na,	wrong_no_nb,	Ld02raf},
    {"d03edf",	wrong_no_na,	wrong_no_nb,	Ld03edf},
    {"d03eef",	wrong_no_na,	wrong_no_nb,	Ld03eef},
    {"d03faf",	wrong_no_na,	wrong_no_nb,	Ld03faf},
    {"s01eaf",	wrong_no_na,	wrong_no_nb,	Ls01eaf},
    {"s13aaf",	too_few_2,	Ls13aaf,	wrong_no_2},
    {"s13acf",	too_few_2,	Ls13acf,	wrong_no_2},
    {"s13adf",	too_few_2,	Ls13adf,	wrong_no_2},
    {"s14aaf",	too_few_2,	Ls14aaf,	wrong_no_2},
    {"s14abf",	too_few_2,	Ls14abf,	wrong_no_2},
    {"s14baf",	wrong_no_na,	wrong_no_nb,	Ls14baf},
    {"s15adf",	too_few_2,	Ls15adf,	wrong_no_2},
    {"s15aef",	too_few_2,	Ls15aef,	wrong_no_2},
    {"s17acf",	too_few_2,	Ls17acf,	wrong_no_2},
    {"s17adf",	too_few_2,	Ls17adf,	wrong_no_2},
    {"s17aef",	too_few_2,	Ls17aef,	wrong_no_2},
    {"s17aff",	too_few_2,	Ls17aff,	wrong_no_2},
    {"s17agf",	too_few_2,	Ls17agf,	wrong_no_2},
    {"s17ahf",	too_few_2,	Ls17ahf,	wrong_no_2},
    {"s17ajf",	too_few_2,	Ls17ajf,	wrong_no_2},
    {"s17akf",	too_few_2,	Ls17akf,	wrong_no_2},
    {"s17dcf",	wrong_no_na,	wrong_no_nb,	Ls17dcf},
    {"s17def",	wrong_no_na,	wrong_no_nb,	Ls17def},
    {"s17dgf",	wrong_no_na,	wrong_no_nb,	Ls17dgf},
    {"s17dhf",	wrong_no_na,	wrong_no_nb,	Ls17dhf},
    {"s17dlf",	wrong_no_na,	wrong_no_nb,	Ls17dlf},
    {"s18acf",	too_few_2,	Ls18acf,	wrong_no_2},
    {"s18adf",	too_few_2,	Ls18adf,	wrong_no_2},
    {"s18aef",	too_few_2,	Ls18aef,	wrong_no_2},
    {"s18aff",	too_few_2,	Ls18aff,	wrong_no_2},
    {"s18dcf",	wrong_no_na,	wrong_no_nb,	Ls18dcf},
    {"s18def",	wrong_no_na,	wrong_no_nb,	Ls18def},
    {"s19aaf",	too_few_2,	Ls19aaf,	wrong_no_2},
    {"s19abf",	too_few_2,	Ls19abf,	wrong_no_2},
    {"s19acf",	too_few_2,	Ls19acf,	wrong_no_2},
    {"s19adf",	too_few_2,	Ls19adf,	wrong_no_2},
    {"s20acf",	too_few_2,	Ls20acf,	wrong_no_2},
    {"s20adf",	too_few_2,	Ls20adf,	wrong_no_2},
    {"s21baf",	wrong_no_na,	wrong_no_nb,	Ls21baf},
    {"s21bbf",	wrong_no_na,	wrong_no_nb,	Ls21bbf},
    {"s21bcf",	wrong_no_na,	wrong_no_nb,	Ls21bcf},
    {"s21bdf",	wrong_no_na,	wrong_no_nb,	Ls21bdf},
#else
    {"d01ajf",	nag_error1,	nag_error2,	nag_error0},
    {"d01akf",	nag_error1,	nag_error2,	nag_error0},
    {"d01alf",	nag_error1,	nag_error2,	nag_error0},
    {"d01amf",	nag_error1,	nag_error2,	nag_error0},
    {"d01anf",	nag_error1,	nag_error2,	nag_error0},
    {"d01apf",	nag_error1,	nag_error2,	nag_error0},
    {"d01aqf",	nag_error1,	nag_error2,	nag_error0},
    {"d01asf",	nag_error1,	nag_error2,	nag_error0},
    {"d01bbf",	nag_error1,	nag_error2,	nag_error0},
    {"d01fcf",	nag_error1,	nag_error2,	nag_error0},
    {"d01gaf",	nag_error1,	nag_error2,	nag_error0},
    {"d01gbf",	nag_error1,	nag_error2,	nag_error0},
    {"d02bbf",	nag_error1,	nag_error2,	nag_error0},
    {"d02bhf",	nag_error1,	nag_error2,	nag_error0},
    {"d02cjf",	nag_error1,	nag_error2,	nag_error0},
    {"d02ejf",	nag_error1,	nag_error2,	nag_error0},
    {"d02gaf",	nag_error1,	nag_error2,	nag_error0},
    {"d02gbf",	nag_error1,	nag_error2,	nag_error0},
    {"d02kef",	nag_error1,	nag_error2,	nag_error0},
    {"d02raf",	nag_error1,	nag_error2,	nag_error0},
    {"d03edf",	nag_error1,	nag_error2,	nag_error0},
    {"d03eef",	nag_error1,	nag_error2,	nag_error0},
    {"d03faf",	nag_error1,	nag_error2,	nag_error0},
    {"s01eaf",	nag_error1,	nag_error2,	nag_error0},
    {"s13aaf",	nag_error1,	nag_error2,	nag_error0},
    {"s13acf",	nag_error1,	nag_error2,	nag_error0},
    {"s13adf",	nag_error1,	nag_error2,	nag_error0},
    {"s14aaf",	nag_error1,	nag_error2,	nag_error0},
    {"s14abf",	nag_error1,	nag_error2,	nag_error0},
    {"s14baf",	nag_error1,	nag_error2,	nag_error0},
    {"s15adf",	nag_error1,	nag_error2,	nag_error0},
    {"s15aef",	nag_error1,	nag_error2,	nag_error0},
    {"s17acf",	nag_error1,	nag_error2,	nag_error0},
    {"s17adf",	nag_error1,	nag_error2,	nag_error0},
    {"s17aef",	nag_error1,	nag_error2,	nag_error0},
    {"s17aff",	nag_error1,	nag_error2,	nag_error0},
    {"s17agf",	nag_error1,	nag_error2,	nag_error0},
    {"s17ahf",	nag_error1,	nag_error2,	nag_error0},
    {"s17ajf",	nag_error1,	nag_error2,	nag_error0},
    {"s17akf",	nag_error1,	nag_error2,	nag_error0},
    {"s17dcf",	nag_error1,	nag_error2,	nag_error0},
    {"s17def",	nag_error1,	nag_error2,	nag_error0},
    {"s17dgf",	nag_error1,	nag_error2,	nag_error0},
    {"s17dhf",	nag_error1,	nag_error2,	nag_error0},
    {"s17dlf",	nag_error1,	nag_error2,	nag_error0},
    {"s18acf",	nag_error1,	nag_error2,	nag_error0},
    {"s18adf",	nag_error1,	nag_error2,	nag_error0},
    {"s18aef",	nag_error1,	nag_error2,	nag_error0},
    {"s18aff",	nag_error1,	nag_error2,	nag_error0},
    {"s18dcf",	nag_error1,	nag_error2,	nag_error0},
    {"s18def",	nag_error1,	nag_error2,	nag_error0},
    {"s19aaf",	nag_error1,	nag_error2,	nag_error0},
    {"s19abf",	nag_error1,	nag_error2,	nag_error0},
    {"s19acf",	nag_error1,	nag_error2,	nag_error0},
    {"s19adf",	nag_error1,	nag_error2,	nag_error0},
    {"s20acf",	nag_error1,	nag_error2,	nag_error0},
    {"s20adf",	nag_error1,	nag_error2,	nag_error0},
    {"s21baf",	nag_error1,	nag_error2,	nag_error0},
    {"s21bbf",	nag_error1,	nag_error2,	nag_error0},
    {"s21bcf",	nag_error1,	nag_error2,	nag_error0},
    {"s21bdf",	nag_error1,	nag_error2,	nag_error0},
#endif
    {NULL,	0,		0,		0}
};

/* end of nag.c */
