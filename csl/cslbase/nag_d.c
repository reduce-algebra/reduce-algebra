/*
 * This code was contributed to CSL by NAG Ltd.
 */

/* Signature: 5830b865 24-May-2008 */


/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 **************************************************************************

Lisp_Object MS_CDECL Ld01ajf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
              Lw, Liw;
  double a, b, epsabs, epsrel, result, abserr, *w;
  int32_t  ifail, lw, *iw, liw;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01AJF) (double __stdcall (*fst) (double *),
	  double *, double *, double *, double *, double *, double *,
	  double *, int32_t *, int32_t *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PD01AJF d01ajf_proc;
#else
  extern void __stdcall D01AJF(double __stdcall (*fst) (double *), double *,
	  double *, double *, double *, double *, double *, double *,
	  int32_t *, int32_t *, int32_t *, int32_t *);
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
  iw = (int32_t *)malloc(liw*sizeof(int));

  /* Call NAG routine */
  push4(La,Lb,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01ajf_proc = (PD01AJF) GetProcAddress (hLib, "_D01AJF@48"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01ajf_proc) (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w,
	      &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01AJF (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w, &lw, iw,
	  &liw, &ifail);
#endif
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Lb,La);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
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
  Lifail = int2ccl(ifail);
  pop4(Liw,Lw,Labserr,Lresult);
  errexit();

  free (w);
  free (iw);

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}

Lisp_Object MS_CDECL Ld01akf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
              Lw, Liw;
  double a, b, epsabs, epsrel, result, abserr, *w;
  int32_t  ifail, lw, *iw, liw;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01AKF) (double __stdcall (*fst) (double *),
	  double *, double *, double *, double *, double *, double *,
	  double *, int32_t *, int32_t *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PD01AKF d01akf_proc;
#else
  extern void __stdcall D01AKF(double __stdcall (*fst) (double *), double *,
	  double *, double *, double *, double *, double *, double *,
	  int32_t *, int32_t *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,7,"Ld01akf");
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
  iw = (int32_t *)malloc(liw*sizeof(int));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01akf_proc = (PD01AKF) GetProcAddress (hLib, "_D01AKF@48"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01akf_proc) (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w,
	      &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01AKF (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w, &lw, iw,
	  &liw, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
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
  Lifail = int2ccl(ifail);
  pop4(Liw,Lw,Labserr,Lresult);
  errexit();

  free (w);
  free (iw);

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}

#if 1
Lisp_Object MS_CDECL Ld01alf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
              Lw, Liw, Lnpts, Lpoints;
  double a, b, epsabs, epsrel, result, abserr, *w, *points;
  int32_t  ifail, lw, *iw, liw, npts;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01ALF) (double __stdcall (*fst) (double *),
	  double *, double *, int32_t *, double *, double *, double *,
	  double *, double *, double *, int32_t *, int32_t *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PD01ALF d01alf_proc;
#else
  extern void __stdcall D01ALF(double __stdcall (*fst) (double *), double *,
	  double *, int32_t *, double *, double *, double *, double *,
	  double *, double *, int32_t *, int32_t *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,9,"Ld01alf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Lnpts = va_arg(args, Lisp_Object);
  Lpoints = va_arg(args, Lisp_Object);
  Lepsabs = va_arg(args, Lisp_Object);
  Lepsrel = va_arg(args, Lisp_Object);
  Llw = va_arg(args, Lisp_Object);
  Lliw = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  a = float_of_number(La);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  b = float_of_number(Lb);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  npts = thirty_two_bits(Lnpts);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  /* ndim = (length_of_header(vechdr(Lpoints)) - 4)/4; */
  points = (double *)malloc(npts*sizeof(double));
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  mkFortranVectorDouble(points, Lpoints, npts);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  epsabs = float_of_number(Lepsabs);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  epsrel = float_of_number(Lepsrel);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  lw = thirty_two_bits(Llw);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  liw = thirty_two_bits(Lliw);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();
  push5(La,Lb,Lnpts,Lpoints,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lpoints,Lnpts,Lb,La);
  errexit();

  /* Setup workspace arrays etc. */
  w = (double *)malloc(lw*sizeof(double));
  iw = (int32_t *)malloc(liw*sizeof(int));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01alf_proc = (PD01ALF) GetProcAddress (hLib, "_D01ALF@56"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01alf_proc) (&asp1, &a, &b, &npts, points, &epsabs, &epsrel,
	      &result, &abserr, w, &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01ALF (&asp1, &a, &b, &npts, points, &epsabs, &epsrel, &result, &abserr,
	  w, &lw, iw, &liw, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
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
  Lifail = int2ccl(ifail);
  pop4(Liw,Lw,Labserr,Lresult);
  errexit();

  free (points);
  free (w);
  free (iw);

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
Lisp_Object MS_CDECL Ld01alf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01amf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr, Lw, Liw,
              Lbound, Linf;
  double epsabs, epsrel, result, abserr, *w, bound;
  int32_t  ifail, lw, *iw, liw, inf;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01AMF) (double __stdcall (*fst) (double *),
	  double *, int32_t *, double *, double *, double *, double *,
	  double *, int32_t *, int32_t *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PD01AMF d01amf_proc;
#else
  extern void __stdcall D01AMF(double __stdcall (*fst) (double *), double *,
	  int32_t *, double *, double *, double *, double *, double *, int32_t *,
	  int32_t *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,7,"Ld01amf");
  va_start(args,nargs);
  Lbound = va_arg(args, Lisp_Object);
  Linf = va_arg(args, Lisp_Object);
  Lepsabs = va_arg(args, Lisp_Object);
  Lepsrel = va_arg(args, Lisp_Object);
  Llw = va_arg(args, Lisp_Object);
  Lliw = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  bound = float_of_number(Lbound);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);
  errexit();
  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  inf = thirty_two_bits(Linf);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);
  errexit();
  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  epsabs = float_of_number(Lepsabs);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);
  errexit();
  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  epsrel = float_of_number(Lepsrel);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);
  errexit();
  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  lw = thirty_two_bits(Llw);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);
  errexit();
  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  liw = thirty_two_bits(Lliw);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);
  errexit();
  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);
  errexit();

  /* Setup workspace arrays etc. */
  w = (double *)malloc(lw*sizeof(double));
  iw = (int32_t *)malloc(liw*sizeof(int));

  push4(Lbound,Linf,Lepsabs,Lepsrel);
  push3(Llw,Lliw,Lifail);

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01amf_proc = (PD01AMF) GetProcAddress (hLib, "_D01AMF@48"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01amf_proc) (&asp1, &bound, &inf, &epsabs, &epsrel, &result,
	      &abserr, w, &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01AMF (&asp1, &bound, &inf, &epsabs, &epsrel, &result, &abserr, w, &lw,
	  iw, &liw, &ifail);
#endif
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop3(Lepsabs,Linf,Lbound);

  /* Translate return values to CCL */
  /* Copy result */
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
  Lifail = int2ccl(ifail);
  pop4(Liw,Lw,Labserr,Lresult);
  errexit();

  free (w);
  free (iw);

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
Lisp_Object MS_CDECL Ld01amf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01anf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
              Lw, Liw, Lomega, Lkey;
  double a, b, epsabs, epsrel, result, abserr, *w, omega;
  int32_t  ifail, lw, *iw, liw, key;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01ANF) (double __stdcall (*fst) (double *),
	  double *, double *, double *, int32_t *, double *, double *,
	  double *, double *, double *, int32_t *, int32_t *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PD01ANF d01anf_proc;
#else
  extern void __stdcall D01ANF(double __stdcall (*fst) (double *), double *,
	  double *, double *, int32_t *, double *, double *, double *,
	  double *, double *, int32_t *, int32_t *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,9,"Ld01anf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Lomega = va_arg(args, Lisp_Object);
  Lkey = va_arg(args, Lisp_Object);
  Lepsabs = va_arg(args, Lisp_Object);
  Lepsrel = va_arg(args, Lisp_Object);
  Llw = va_arg(args, Lisp_Object);
  Lliw = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  a = float_of_number(La);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  b = float_of_number(Lb);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  omega = float_of_number(Lomega);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  key = thirty_two_bits(Lkey);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  epsabs = float_of_number(Lepsabs);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  epsrel = float_of_number(Lepsrel);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  lw = thirty_two_bits(Llw);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  liw = thirty_two_bits(Lliw);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();
  push5(La,Lb,Lomega,Lkey,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop4(Lkey,Lomega,Lb,La);
  errexit();

  /* Setup workspace arrays etc. */
  w = (double *)malloc(lw*sizeof(double));
  iw = (int32_t *)malloc(liw*sizeof(int));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01anf_proc = (PD01ANF) GetProcAddress (hLib, "_D01ANF@56"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01anf_proc) (&asp1, &a, &b, &omega, &key, &epsabs, &epsrel, &result,
	      &abserr, w, &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01ANF (&asp1, &a, &b, &omega, &key, &epsabs, &epsrel, &result, &abserr, w,
	  &lw, iw, &liw, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
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
  Lifail = int2ccl(ifail);
  pop4(Liw,Lw,Labserr,Lresult);
  errexit();

  free (w);
  free (iw);

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
Lisp_Object MS_CDECL Ld01anf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01apf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
              Lw, Liw, Lalfa, Lbeta, Lkey;
  double a, b, epsabs, epsrel, result, abserr, *w, alfa, beta;
  int32_t  ifail, lw, *iw, liw, key;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01APF) (double __stdcall (*fst) (double *),
	  double *, double *, double *, double *, int32_t *, double *,
	  double *, double *, double *, double *, int32_t *, int32_t *, int32_t *,
	  int32_t *);
  HINSTANCE hLib;
  PD01APF d01apf_proc;
#else
  extern void __stdcall D01APF(double __stdcall (*fst) (double *), double *,
	  double *, double *, double *, int32_t *, double *, double *,
	  double *, double *, double *, int32_t *, int32_t *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,10,"Ld01apf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Lalfa = va_arg(args, Lisp_Object);
  Lbeta = va_arg(args, Lisp_Object);
  Lkey = va_arg(args, Lisp_Object);
  Lepsabs = va_arg(args, Lisp_Object);
  Lepsrel = va_arg(args, Lisp_Object);
  Llw = va_arg(args, Lisp_Object);
  Lliw = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  a = float_of_number(La);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  b = float_of_number(Lb);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  alfa = float_of_number(Lalfa);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  beta = float_of_number(Lbeta);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  key = thirty_two_bits(Lkey);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  epsabs = float_of_number(Lepsabs);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  epsrel = float_of_number(Lepsrel);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  lw = thirty_two_bits(Llw);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  liw = thirty_two_bits(Lliw);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();
  push5(La,Lb,Lalfa,Lbeta,Lkey);
  push5(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
  pop5(Lkey,Lbeta,Lalfa,Lb,La);
  errexit();

  /* Setup workspace arrays etc. */
  w = (double *)malloc(lw*sizeof(double));
  iw = (int32_t *)malloc(liw*sizeof(int));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01apf_proc = (PD01APF) GetProcAddress (hLib, "_D01APF@60"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01apf_proc) (&asp1, &a, &b, &alfa, &beta, &key, &epsabs, &epsrel,
	      &result, &abserr, w, &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01APF (&asp1, &a, &b, &alfa, &beta, &key, &epsabs, &epsrel, &result,
	  &abserr, w, &lw, iw, &liw, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
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
  Lifail = int2ccl(ifail);
  pop4(Liw,Lw,Labserr,Lresult);
  errexit();

  free (w);
  free (iw);

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
Lisp_Object MS_CDECL Ld01apf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01aqf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
              Lw, Liw, Lc;
  double a, b, epsabs, epsrel, result, abserr, *w, c;
  int32_t  ifail, lw, *iw, liw;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01AQF) (double __stdcall (*fst) (double *),
	  double *, double *, double *, double *, double *, double *,
	  double *, double *, int32_t *, int32_t *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PD01AQF d01aqf_proc;
#else
  extern void __stdcall D01AQF(double __stdcall (*fst) (double *), double *,
	  double *, double *, double *, double *, double *, double *,
	  double *, int32_t *, int32_t *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,8,"Ld01aqf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Lc = va_arg(args, Lisp_Object);
  Lepsabs = va_arg(args, Lisp_Object);
  Lepsrel = va_arg(args, Lisp_Object);
  Llw = va_arg(args, Lisp_Object);
  Lliw = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  a = float_of_number(La);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  b = float_of_number(Lb);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  c = float_of_number(Lc);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  epsabs = float_of_number(Lepsabs);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  epsrel = float_of_number(Lepsrel);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  lw = thirty_two_bits(Llw);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  liw = thirty_two_bits(Lliw);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();
  push4(La,Lb,Lc,Lepsabs);
  push4(Lepsrel,Llw,Lliw,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lliw,Llw,Lepsrel);
  pop4(Lepsabs,Lc,Lb,La);
  errexit();

  /* Setup workspace arrays etc. */
  w = (double *)malloc(lw*sizeof(double));
  iw = (int32_t *)malloc(liw*sizeof(int));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01aqf_proc = (PD01AQF) GetProcAddress (hLib, "_D01AQF@52"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01aqf_proc) (&asp1, &a, &b, &c, &epsabs, &epsrel, &result, &abserr,
	      w, &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01AQF (&asp1, &a, &b, &c, &epsabs, &epsrel, &result, &abserr, w, &lw, iw,
	  &liw, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
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
  Lifail = int2ccl(ifail);
  pop4(Liw,Lw,Labserr,Lresult);
  errexit();

  free (w);
  free (iw);

  return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
Lisp_Object MS_CDECL Ld01aqf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01asf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lepsabs, Llw, Lliw, Lifail, Lresult, Labserr, Liw, Lomega,
	  Lkey, Llimlst, Llst, Lerlst, Lrslst, Lierlst;
  double a, epsabs, result, abserr, *w, omega, *erlst, *rslst;
  int32_t  ifail, lw, *iw, liw, key, limlst, lst, *ierlst;
  extern double __stdcall asp1(double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01ASF) (double __stdcall (*fst) (double *),
	  double *, double *, int32_t *, double *, double *, double *, int32_t *,
	  int32_t *, double *, double *, int32_t *, double *, int32_t *, int32_t *,
	  int32_t *, int32_t *);
  HINSTANCE hLib;
  PD01ASF d01asf_proc;
#else
  extern void __stdcall D01ASF(double __stdcall (*fst) (double *), double *,
	  double *, int32_t *, double *, double *, double *, int32_t *, int32_t *,
	  double *, double *, int32_t *, double *, int32_t *, int32_t *, int32_t *,
	  int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,8,"Ld01asf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lomega = va_arg(args, Lisp_Object);
  Lkey = va_arg(args, Lisp_Object);
  Lepsabs = va_arg(args, Lisp_Object);
  Llimlst = va_arg(args, Lisp_Object);
  Llw = va_arg(args, Lisp_Object);
  Lliw = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  a = float_of_number(La);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  omega = float_of_number(Lomega);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  key = thirty_two_bits(Lkey);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  epsabs = float_of_number(Lepsabs);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  limlst = thirty_two_bits(Llw);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  lw = thirty_two_bits(Llw);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  liw = thirty_two_bits(Lliw);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();
  push4(La,Lomega,Lkey,Lepsabs);
  push4(Llimlst,Llw,Lliw,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lliw,Llw,Llimlst);
  pop4(Lepsabs,Lkey,Lomega,La);
  errexit();

  /* Setup workspace arrays etc. */
  erlst = (double *)malloc(limlst*sizeof(double));
  rslst = (double *)malloc(limlst*sizeof(double));
  ierlst = (int32_t *)malloc(limlst*sizeof(int));
  w = (double *)malloc(lw*sizeof(double));
  iw = (int32_t *)malloc(liw*sizeof(int));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01asf_proc = (PD01ASF) GetProcAddress (hLib, "_D01ASF@68"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01asf_proc) (&asp1, &a, &omega, &key, &epsabs, &result, &abserr,
	      &limlst, &lst, erlst, rslst, ierlst, w, &lw, iw, &liw, &ifail);
    }
  }

  currlib = hLib;
#else
  D01ASF (&asp1, &a, &omega, &key, &epsabs, &result, &abserr, &limlst, &lst,
	  erlst, rslst, ierlst, w, &lw, iw, &liw, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lierlst = mkIntVector(ierlst,limlst,1);
  push(Lierlst);
  Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
  pop(Lierlst);
  errexit();
  push2(Lierlst,Lresult);
  Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
  pop2(Lresult,Lierlst);
  errexit();
  push3(Lierlst,Lresult,Labserr);
  Lerlst = mkFloatVector(erlst,limlst,1);
  pop3(Labserr,Lresult,Lierlst);
  errexit();
  push4(Lierlst,Lresult,Labserr,Lerlst);
  Lifail = int2ccl(ifail);
  pop4(Lerlst,Labserr,Lresult,Lierlst);
  errexit();
  push5(Lierlst,Lresult,Labserr,Lerlst,Lifail);
  Liw = mkIntVector(iw,liw,1);
  pop5(Lifail,Lerlst,Labserr,Lresult,Lierlst);
  errexit();
  push3(Lierlst,Lresult,Labserr);
  push3(Lerlst,Lifail,Liw);
  Llst = int2ccl(lst);
  pop3(Liw,Lifail,Lerlst);
  pop3(Labserr,Lresult,Lierlst);
  errexit();
  push4(Lierlst,Lresult,Labserr,Lerlst);
  push3(Lifail,Liw,Llst);
  Lrslst = mkFloatVector(rslst,limlst,1);
  pop4(Llst,Liw,Lifail,Lerlst);
  pop3(Labserr,Lresult,Lierlst);
  errexit();

  free (erlst);
  free (rslst);
  free (ierlst);
  free (w);
  free (iw);

  return Llist(nil,8,Lierlst,Lresult,Labserr,Lerlst,Lifail,Liw,Llst,Lrslst);
}
#else
Lisp_Object MS_CDECL Ld01asf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01bbf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Litype, Ln, Lgtype, Lifail, Lweight, Labscis;
  double a, b, *weight, *abscis;
  int32_t  ifail, itype, n, gtype;

#ifdef LOADLIB
  typedef void (__stdcall *PAD01BB) (double *, double *, int32_t *, int32_t *,
	  double *, double *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PAD01BB ad01bb_proc;
#else
  extern void __stdcall AD01BB(double *, double *, int32_t *, int32_t *,
	  double *, double *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,6,"Ld01bbf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Litype = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lgtype = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push3(La,Lb,Litype);
  push3(Ln,Lgtype,Lifail);
  a = float_of_number(La);
  pop3(Lifail,Lgtype,Ln);
  pop3(Litype,Lb,La);
  errexit();
  push3(La,Lb,Litype);
  push3(Ln,Lgtype,Lifail);
  b = float_of_number(Lb);
  pop3(Lifail,Lgtype,Ln);
  pop3(Litype,Lb,La);
  errexit();
  push3(La,Lb,Litype);
  push3(Ln,Lgtype,Lifail);
  itype = thirty_two_bits(Litype);
  pop3(Lifail,Lgtype,Ln);
  pop3(Litype,Lb,La);
  errexit();
  push3(La,Lb,Litype);
  push3(Ln,Lgtype,Lifail);
  n = thirty_two_bits(Ln);
  pop3(Lifail,Lgtype,Ln);
  pop3(Litype,Lb,La);
  errexit();
  push3(La,Lb,Litype);
  push3(Ln,Lgtype,Lifail);
  gtype = thirty_two_bits(Lgtype);
  pop3(Lifail,Lgtype,Ln);
  pop3(Litype,Lb,La);
  errexit();
  push3(La,Lb,Litype);
  push3(Ln,Lgtype,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop3(Lifail,Lgtype,Ln);
  pop3(Litype,Lb,La);
  errexit();
  push3(La,Lb,Litype);
  push3(Ln,Lgtype,Lifail);

  /* Setup workspace arrays etc. */  /* return value arrays in this case */
  weight = (double *)malloc(n*sizeof(double));
  abscis = (double *)malloc(n*sizeof(double));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   /* FIXME - DLL name? */
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (ad01bb_proc = (PAD01BB) GetProcAddress (hLib, "_AD01BB@32"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*ad01bb_proc) (&a, &b, &itype, &n, weight, abscis, &gtype, &ifail);
    }
  }

  currlib = hLib;
#else
  AD01BB (&a, &b, &itype, &n, weight, abscis, &gtype, &ifail);
#endif
  pop3(Lifail,Lgtype,Ln);
  pop3(Litype,Lb,La);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lweight = mkFloatVector(weight,n,1);
  push(Lweight);
  Labscis = mkFloatVector(abscis,n,1);
  pop(Lweight);
  errexit();
  push2(Lweight,Labscis);
  Lifail = int2ccl(ifail);
  pop2(Labscis,Lweight);
  errexit();

  free (weight);
  free (abscis);

  return Llist(nil,3,Lweight,Labscis,Lifail);
}
#else
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01fcf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lndim, Leps, Lminpts, Lmaxpts, Lifail, Lfinval, Lacc,
              Llenwrk;
  double *a, *b, eps, finval, acc, *wrkstr;
  int32_t  ifail, ndim, minpts, maxpts, lenwrk;
  extern double __stdcall asp4(int32_t *, double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01FCF) (int32_t *, double *, double *, int32_t *,
	  int32_t *, double __stdcall (*functn) (int32_t *, double *), double *,
	  double *, int32_t *, double *, double *, int32_t *);
  HINSTANCE hLib;
  PD01FCF d01fcf_proc;
#else
  extern void __stdcall D01FCF(int32_t *, double *, double *, int32_t *, int32_t *,
	  double __stdcall (*functn) (int32_t *, double *), double *, double *,
	  int32_t *, double *, double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,8,"Ld01fcf");
  va_start(args,nargs);
  Lndim = va_arg(args, Lisp_Object);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Lmaxpts = va_arg(args, Lisp_Object);
  Leps = va_arg(args, Lisp_Object);
  Llenwrk = va_arg(args, Lisp_Object);
  Lminpts = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  ndim = thirty_two_bits(Lndim);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();
  a = (double *) malloc (ndim * sizeof(double));
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  mkFortranVectorDouble(a, La, ndim);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();
  b = (double *) malloc (ndim * sizeof(double));
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  mkFortranVectorDouble(b, Lb, ndim);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  maxpts = thirty_two_bits(Lmaxpts);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  eps = float_of_number(Leps);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  lenwrk = thirty_two_bits(Llenwrk);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  minpts = thirty_two_bits(Lminpts);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();
  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();

  /* Setup workspace arrays etc. */
  wrkstr = (double *)malloc(lenwrk*sizeof(double));

  push4(Lndim,La,Lb,Lmaxpts);
  push4(Leps,Llenwrk,Lminpts,Lifail);
  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01fcf_proc = (PD01FCF) GetProcAddress (hLib, "_D01FCF@48"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01fcf_proc) (&ndim, a, b, &minpts, &maxpts, &asp4, &eps, &acc,
	      &lenwrk, wrkstr, &finval, &ifail);
    }
  }

  currlib = hLib;
#else
  D01FCF (&ndim, a, b, &minpts, &maxpts, &asp4, &eps, &acc, &lenwrk, wrkstr,
	  &finval, &ifail);
#endif
  pop4(Lifail,Lminpts,Llenwrk,Leps);
  pop4(Lmaxpts,Lb,La,Lndim);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lfinval = make_boxfloat(finval,TYPE_DOUBLE_FLOAT);
  push(Lfinval);
  Lminpts = int2ccl(minpts);
  pop(Lfinval);
  errexit();
  push2(Lfinval,Lminpts);
  Lifail = int2ccl(ifail);
  pop2(Lminpts,Lfinval);
  errexit();
  push3(Lfinval,Lminpts,Lifail);
  Lacc = make_boxfloat(acc,TYPE_DOUBLE_FLOAT);
  pop3(Lifail,Lminpts,Lfinval);
  errexit();

  free (a);
  free (b);
  free (wrkstr);

  return Llist(nil,4,Lfinval,Lminpts,Lifail,Lacc);
}
#else
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01gaf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lx, Ly, Ln, Lans, Ler, Lifail;
  double *x, *y, ans, er;
  int32_t ifail, n;

#ifdef LOADLIB
  typedef void (__stdcall *PD01GAF) (double *, double *, int32_t *, double *,
	  double *, int32_t *);
  HINSTANCE hLib;
  PD01GAF d01gaf_proc;
#else
  extern void __stdcall D01GAF(double *, double *, int32_t *, double *,
	  double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,4,"Ld01gaf");
  va_start(args,nargs);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lx,Ly,Ln,Lifail);
  n = thirty_two_bits(Ln);
  pop4(Lifail,Ln,Ly,Lx);
  errexit();
  x = (double *) malloc (n * sizeof(double));
  push4(Lx,Ly,Ln,Lifail);
  mkFortranVectorDouble(x, Lx, n);
  pop4(Lifail,Ln,Ly,Lx);
  errexit();
  y = (double *) malloc (n * sizeof(double));
  push4(Lx,Ly,Ln,Lifail);
  mkFortranVectorDouble(y, Ly, n);
  pop4(Lifail,Ln,Ly,Lx);
  errexit();
  push4(Lx,Ly,Ln,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Ln,Ly,Lx);
  errexit();

  push4(Lx,Ly,Ln,Lifail);
  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01gaf_proc = (PD01GAF) GetProcAddress (hLib, "_D01GAF@24"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01gaf_proc) (x, y, &n, &ans, &er, &ifail);
    }
  }

  currlib = hLib;
#else
  D01GAF (x, y, &n, &ans, &er, &ifail);
#endif
  pop4(Lifail,Ln,Ly,Lx);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lans = make_boxfloat(ans,TYPE_DOUBLE_FLOAT);
  push(Lans);
  Ler = make_boxfloat(er,TYPE_DOUBLE_FLOAT);
  pop(Lans);
  errexit();
  push2(Lans,Ler);
  Lifail = int2ccl(ifail);
  pop2(Ler,Lans);
  errexit();

  free (x);
  free (y);

  return Llist(nil,3,Lans,Ler,Lifail);
}
#else
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ld01gbf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lb, Lndim, Leps, Lmincls, Lmaxcls, Lifail, Lfinval, Lacc,
              Llenwrk, Lwrkstr;
  double *a, *b, eps, finval, acc, *wrkstr;
  int32_t  ifail, ndim, mincls, maxcls, lenwrk;
  extern double __stdcall asp4(int32_t *, double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD01GBF) (int32_t *, double *, double *, int32_t *,
	  int32_t *, double __stdcall (*functn) (int32_t *, double *), double *,
	  double *, int32_t *, double *, double *, int32_t *);
  HINSTANCE hLib;
  PD01GBF d01gbf_proc;
#else
  extern void __stdcall D01GBF(int32_t *, double *, double *, int32_t *, int32_t *,
	  double __stdcall (*functn) (int32_t *, double *), double *, double *,
	  int32_t *, double *, double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,9,"Ld01gbf");
  va_start(args,nargs);
  Lndim = va_arg(args, Lisp_Object);
  La = va_arg(args, Lisp_Object);
  Lb = va_arg(args, Lisp_Object);
  Lmaxcls = va_arg(args, Lisp_Object);
  Leps = va_arg(args, Lisp_Object);
  Llenwrk = va_arg(args, Lisp_Object);
  Lmincls = va_arg(args, Lisp_Object);
  Lwrkstr = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  ndim = thirty_two_bits(Lndim);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  a = (double *) malloc (ndim * sizeof(double));
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  mkFortranVectorDouble(a, La, ndim);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  b = (double *) malloc (ndim * sizeof(double));
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  mkFortranVectorDouble(b, Lb, ndim);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  maxcls = thirty_two_bits(Lmaxcls);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  eps = float_of_number(Leps);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  lenwrk = thirty_two_bits(Llenwrk);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  mincls = thirty_two_bits(Lmincls);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  wrkstr = (double *) malloc (lenwrk * sizeof(double));
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  mkFortranVectorDouble(wrkstr, Lwrkstr, lenwrk);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();
  push5(Lndim,La,Lb,Lmaxcls,Leps);
  push4(Llenwrk,Lmincls,Lwrkstr,Lifail);

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d01gbf_proc = (PD01GBF) GetProcAddress (hLib, "_D01GBF@48"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d01gbf_proc) (&ndim, a, b, &mincls, &maxcls, &asp4, &eps, &acc,
	      &lenwrk, wrkstr, &finval, &ifail);
    }
  }

  currlib = hLib;
#else
  D01GBF (&ndim, a, b, &mincls, &maxcls, &asp4, &eps, &acc, &lenwrk, wrkstr,
	  &finval, &ifail);
#endif
  pop5(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
  pop4(Lmaxcls,Lb,La,Lndim);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lfinval = make_boxfloat(finval,TYPE_DOUBLE_FLOAT);
  push(Lfinval);
  Lmincls = int2ccl(mincls);
  pop(Lfinval);
  errexit();
  push2(Lfinval,Lmincls);
  Lifail = int2ccl(ifail);
  pop2(Lmincls,Lfinval);
  errexit();
  push3(Lfinval,Lmincls,Lifail);
  Lwrkstr = mkFloatVector(wrkstr,lenwrk,1);
  pop3(Lifail,Lmincls,Lfinval);  
  push4(Lfinval,Lmincls,Lifail,Lwrkstr);
  Lacc = make_boxfloat(acc,TYPE_DOUBLE_FLOAT);
  pop4(Lwrkstr,Lifail,Lmincls,Lfinval);
  errexit();

  free (a);
  free (b);
  free (wrkstr);

  return Llist(nil,5,Lfinval,Lmincls,Lifail,Lwrkstr,Lacc);
}
#else
{
  return Llist(nil, 0);
}
#endif

Lisp_Object MS_CDECL Ld02bbf(Lisp_Object nil, int nargs, ...)
#if 0
{
  va_list args;
  Lisp_Object Lx, Lxend, Lm, Ln, Ly, Ltol, Lirelab, Lresult, Lifail;
  double x, xend, *y, tol, *w, *result;
  int32_t  ifail, m, n, irelab;
  extern void __stdcall asp7(double *, double *, double *);
  extern void __stdcall asp8(double *, double *);

#ifdef LOADLIB
  typedef void (__stdcall *PXD02BB) (double *, double *, int32_t *, int32_t *,
	  double *, double *, int32_t *, double *,
	  void __stdcall (*fcn) (double *, double *, double *),
	  void __stdcall (*out) (double *, double *), double *, int32_t *);
  HINSTANCE hLib;
  PXD02BB xd02bb_proc;
#else
  extern void __stdcall XD02BB(double *, double *, int32_t *, int32_t *,
	  double *, double *, int32_t *, double *,
	  void __stdcall (*fcn) (double *, double *, double *),
	  void __stdcall (*out) (double *, double *), double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,8,"Ld02bbf");
  va_start(args,nargs);
  Lxend = va_arg(args, Lisp_Object);
  Lm = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lirelab = va_arg(args, Lisp_Object);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Ltol = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  xend = float_of_number(Lxend);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  m = thirty_two_bits(Lm);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  n = thirty_two_bits(Ln);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  irelab = thirty_two_bits(Lirelab);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  x = float_of_number(Lx);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();
  y = (double *) malloc (n * sizeof(double));
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  mkFortranVectorDouble(y, Ly, n);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  tol = float_of_number(Ltol);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Lirelab);
  push4(Lx,Ly,Ltol,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lirelab,Ln,Lm,Lxend);
  errexit();

  /* Setup workspace arrays etc. */
  w = (double *)malloc(n*7*sizeof(double));
  result = (double *)malloc(m*n*sizeof(double));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   /* FIXME - DLL name? */
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (xd02bb_proc = (PXD02BB) GetProcAddress (hLib, "_XD02BB@48"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*xd02bb_proc) (&x, &xend, &m, &n, y, &tol, &irelab, result, &asp7,
	      &asp8, w, &ifail);
    }
  }

  currlib = hLib;
#else
  XD02BB (&x, &xend, &m, &n, y, &tol, &irelab, result, &asp7, &asp8, w,
	  &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
  push(Lx);
  Ly = mkFloatVector(y,n,1);
  pop(Lx);
  errexit();
  push2(Lx,Ly);
  Lresult = mkFloatVector(result,m,n);	/* FIXME: correct array ordering? */
  pop2(Ly,Lx);
  errexit();
  push3(Lx,Ly,Lresult);
  Lifail = int2ccl(ifail);
  pop3(Lresult,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lresult,Lifail);
  Ltol = make_boxfloat(tol,TYPE_DOUBLE_FLOAT);
  pop4(Lifail,Lresult,Ly,Lx);
  errexit();
  
  free (y);
  free (w);
  free (result);

  return Llist(nil,5,Lx,Ly,Lresult,Lifail,Ltol);
}
#else
{
  return Llist(nil, 0);
}
#endif

Lisp_Object MS_CDECL Ld02bhf(Lisp_Object nil, int nargs, ...)
#if 0
{
  va_list args;
  Lisp_Object Lx, Lxend, Ln, Ly, Ltol, Lirelab, Lhmax, Lifail;
  double x, xend, *y, tol, *w, hmax;
  int32_t  ifail, n, irelab;
  extern void __stdcall asp7(double *, double *, double *);
  extern double __stdcall asp9(double *, double *);

#ifdef LOADLIB
  typedef void (__stdcall *PD02BHF) (double *, double *, int32_t *, int32_t *,
	  double *, double *, int32_t *, double *,
	  void __stdcall (*fcn) (double *, double *, double *),
	  double __stdcall (*g) (double *, double *), double *, int32_t *);
  HINSTANCE hLib;
  PD02BHF d02bhf_proc;
#else
  extern void __stdcall D02BHF(double *, double *, int32_t *, int32_t *,
	  double *, double *, int32_t *, double *,
	  void __stdcall (*fcn) (double *, double *, double *),
	  double __stdcall (*g) (double *, double *), double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,8,"Ld02bhf");
  va_start(args,nargs);
  Lxend = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lirelab = va_arg(args, Lisp_Object);
  Lhmax = va_arg(args, Lisp_Object);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Ltol = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  xend = float_of_number(Lxend);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  n = thirty_two_bits(Ln);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  irelab = thirty_two_bits(Lirelab);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  hmax = float_of_number(Lhmax);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  x = float_of_number(Lx);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  y = (double *) malloc (n * sizeof(double));
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  mkFortranVectorDouble(y, Ly, n);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  tol = float_of_number(Ltol);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Ltol,Ly,Lx);
  pop4(Lhmax,Lirelab,Ln,Lxend);
  errexit();
  push4(Lxend,Ln,Lirelab,Lhmax);
  push4(Lx,Ly,Ltol,Lifail);

  /* Setup workspace arrays etc. */
  w = (double *)malloc(n*7*sizeof(double));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (d02bhf_proc = (PD02BHF) GetProcAddress (hLib, "_D02BHF@44"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*d02bhf_proc) (&x, &xend, &n, y, &tol, &irelab, &hmax, &asp7, &asp9,
	      w, &ifail);
    }
  }

  currlib = hLib;
#else
  D02BHF (&x, &xend, &n, y, &tol, &irelab, &hmax, &asp7, &asp9, w, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
  push(Lx);
  Ly = mkFloatVector(y,n,1);
  pop(Lx);
  errexit();
  push2(Lx,Ly);
  Lifail = int2ccl(ifail);
  pop2(Ly,Lx);
  errexit();
  push3(Lx,Ly,Lifail);
  Ltol = make_boxfloat(tol,TYPE_DOUBLE_FLOAT);
  pop3(Lifail,Ly,Lx);
  errexit();
  
  free (y);
  free (w);

  return Llist(nil,4,Lx,Ly,Lifail,Ltol);
}
#else
{
  return Llist(nil, 0);
}
#endif

Lisp_Object MS_CDECL Ld02cjf(Lisp_Object nil, int nargs, ...)
#if 0
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lx, Lxend, Lm, Ln, Ly, Ltol, Lrelabs, Lresult, Lifail;
  double x, xend, *y, tol, *w, *result;
  int32_t  ifail, m, n;
  fstring1 relabs;
  char srelabs[2];
  extern void __stdcall asp7(double *, double *, double *);
  extern void __stdcall asp8(double *, double *);
  extern double __stdcall asp9(double *, double *);

#ifdef LOADLIB
  typedef void (__stdcall *PXD02CJ) (double *, double *, int32_t *, int32_t *,
	  double *, void __stdcall (*fcn) (double *, double *, double *),
	  double *, fstring1, double *,
	  void __stdcall (*out) (double *, double *),
	  double __stdcall (*g) (double *, double *), double *, int32_t *);
  HINSTANCE hLib;
  PXD02CJ xd02cj_proc;
#else
  extern void __stdcall XD02CJ(double *, double *, int32_t *, int32_t *,
	  double *, void __stdcall (*fcn) (double *, double *, double *),
	  double *, fstring1, double *,
	  void __stdcall (*out) (double *, double *),
	  double __stdcall (*g) (double *, double *), double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,8,"Ld02cjf");
  va_start(args,nargs);
  Lxend = va_arg(args, Lisp_Object);
  Lm = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Ltol = va_arg(args, Lisp_Object);
  Lrelabs = va_arg(args, Lisp_Object);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
  xend = float_of_number(Lxend);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
  m = thirty_two_bits(Lm);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
  n = thirty_two_bits(Ln);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
  tol = float_of_number(Ltol);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
//  strncpy (srelabs, &celt(Lrelabs,0), 1);
  srelabs[0] = celt(Lrelabs,0);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();
  srelabs[1] = '\0';
  relabs.str = srelabs;
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
  x = float_of_number(Lx);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();
  y = (double *) malloc (n * sizeof(double));
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
  mkFortranVectorDouble(y, Ly, n);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();
  push4(Lxend,Lm,Ln,Ltol);
  push4(Lrelabs,Lx,Ly,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Ly,Lx,Lrelabs);
  pop4(Ltol,Ln,Lm,Lxend);
  errexit();

  relabs.len = 1;
  
  /* Setup workspace arrays etc. */
  w = (double *)malloc((28+21*n)*sizeof(double));
  result = (double *)malloc(m*n*sizeof(double));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   /* FIXME - DLL name? */
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (xd02cj_proc = (PXD02CJ) GetProcAddress (hLib, "_XD02CJ@56"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*xd02cj_proc) (&x, &xend, &m, &n, y, &asp7, &tol, relabs, result,
	      &asp8, &asp9, w, &ifail);
    }
  }

  currlib = hLib;
#else
  XD02CJ (&x, &xend, &m, &n, y, &asp7, &tol, relabs, result, &asp8, &asp9, w,
	  &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
  push(Lx);
  Ly = mkFloatVector(y,n,1);
  pop(Lx);
  errexit();
  push2(Lx,Ly);
  Lresult = mkFloatVector(result,m,n);	/* FIXME: correct array ordering? */
  pop2(Ly,Lx);
  errexit();
  push3(Lx,Ly,Lresult);
  Lifail = int2ccl(ifail);
  pop3(Lresult,Ly,Lx);
  errexit();
  
  free (y);
  free (w);
  free (result);

  return Llist(nil,4,Lx,Ly,Lresult,Lifail);
}
#else
{
  return Llist(nil, 0);
}
#endif

Lisp_Object MS_CDECL Ld02ejf(Lisp_Object nil, int nargs, ...)
#if 0
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lx, Lxend, Lm, Ln, Ly, Ltol, Lrelabs, Lresult, Lifail, Liw;
  double x, xend, *y, tol, *w, *result;
  int32_t  ifail, m, n, iw;
  fstring1 relabs;
  char srelabs[2];
  extern void __stdcall asp7(double *, double *, double *);
  extern void __stdcall asp8(double *, double *);
  extern double __stdcall asp9(double *, double *);
  extern void __stdcall asp31(double *, double *, double *);

#ifdef LOADLIB
  typedef void (__stdcall *PXD02EJ) (double *, double *, int32_t *, int32_t *,
	  double *, void __stdcall (*fcn) (double *, double *, double *),
	  void __stdcall (*pederv) (double *, double *, double *), double *,
	  fstring1, void __stdcall (*out) (double *, double *),
	  double __stdcall (*g) (double *, double *), double *, int32_t *,
	  double *, int32_t *);
	  
  HINSTANCE hLib;
  PXD02EJ xd02ej_proc;
#else
  extern void __stdcall XD02EJ(double *, double *, int32_t *, int32_t *,
	  double *, void __stdcall (*fcn) (double *, double *, double *),
	  void __stdcall (*pederv) (double *, double *, double *), double *,
	  fstring1, void __stdcall (*out) (double *, double *),
	  double __stdcall (*g) (double *, double *), double *, int32_t *,
	  double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,9,"Ld02ejf");
  va_start(args,nargs);
  Lxend = va_arg(args, Lisp_Object);
  Lm = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lrelabs = va_arg(args, Lisp_Object);
  Liw = va_arg(args, Lisp_Object);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Ltol = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  xend = float_of_number(Lxend);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  m = thirty_two_bits(Lm);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  n = thirty_two_bits(Ln);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
//  strncpy (srelabs, &celt(Lrelabs,0), 1);
  srelabs[0] = celt(Lrelabs,0);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  srelabs[1] = '\0';
  relabs.str = srelabs;
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  iw = thirty_two_bits(Liw);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  x = float_of_number(Lx);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  y = (double *) malloc (n * sizeof(double));
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  mkFortranVectorDouble(y, Ly, n);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  tol = float_of_number(Ltol);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Ltol,Ly,Lx,Liw);
  pop4(Lrelabs,Ln,Lm,Lxend);
  errexit();
  push5(Lxend,Lm,Ln,Lrelabs,Liw);
  push4(Lx,Ly,Ltol,Lifail);

  relabs.len = 1;
  
  /* Setup workspace arrays etc. */
  w = (double *)malloc(iw*sizeof(double));
  result = (double *)malloc(m*n*sizeof(double));

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   /* FIXME - DLL name? */
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (xd02ej_proc = (PXD02EJ) GetProcAddress (hLib, "_XD02EJ@64"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*xd02ej_proc) (&x, &xend, &m, &n, y, &asp7, &asp31, &tol, relabs,
	      &asp8, &asp9, w, &iw, result, &ifail);
    }
  }

  currlib = hLib;
#else
  XD02EJ (&x, &xend, &m, &n, y, &asp7, &asp31, &tol, relabs, &asp8, &asp9, w,
	  &iw, result, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
  push(Lx);
  Ly = mkFloatVector(y,n,1);
  pop(Lx);
  errexit();
  push2(Lx,Ly);
  Lresult = mkFloatVector(result,m,n);	/* FIXME: correct array ordering? */
  pop2(Ly,Lx);
  errexit();
  push3(Lx,Ly,Lresult);
  Lifail = int2ccl(ifail);
  pop3(Lresult,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lresult,Lifail);
  Ltol = make_boxfloat(tol,TYPE_DOUBLE_FLOAT);
  pop4(Lifail,Lresult,Ly,Lx);
  errexit();
  
  free (y);
  free (w);
  free (result);

  return Llist(nil,5,Lx,Ly,Lresult,Lifail,Ltol);
}
#else
{
  return Llist(nil, 0);
}
#endif

	/* ******************* GOT TO HERE ********************* */

Lisp_Object MS_CDECL Ld02gaf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}

Lisp_Object MS_CDECL Ld02gbf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}

Lisp_Object MS_CDECL Ld02kef(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}

Lisp_Object MS_CDECL Ld02raf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}

Lisp_Object MS_CDECL Ld03edf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}

Lisp_Object MS_CDECL Ld03eef(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}

Lisp_Object MS_CDECL Ld03faf(Lisp_Object nil, int nargs, ...)
{
  return Llist(nil, 0);
}
