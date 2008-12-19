/* This code wad contributed to CSL by NAG Ltd */

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
 *************************************************************************/



/* Signature: 4753a1e7 24-May-2008 */


#if 1
Lisp_Object MS_CDECL Ls01eaf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lzr, Lzi, Lifail, Lwr, Lwi;
  double z[2], w[2];
  int32_t ifail;

  /*
   * Returning DOUBLE COMPLEX objects via the function name is not portable
   * so we use a dummy subroutine as glue.
   */

#ifdef LOADLIB
  typedef void (__stdcall *PSXXEAF) (double *, double *, int32_t *);
  HINSTANCE hLib;
  PSXXEAF sxxeaf_proc;
#else
  extern void __stdcall SXXEAF (double *, double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfasj")) == NULL )	/* FIXME (jackets) */
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (sxxeaf_proc = (PSXXEAF) GetProcAddress (hLib, "_SXXEAF@12"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*sxxeaf_proc) (z, w, &ifail);
    }
  }

  currlib = hLib;
#else
  SXXEAF(z,w,&ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lwr = make_boxfloat(w[0],TYPE_DOUBLE_FLOAT);
  push(Lwr);
  Lwi = make_boxfloat(w[1],TYPE_DOUBLE_FLOAT);
  pop(Lwr);
  errexit();
  push2(Lwr,Lwi);
  Lifail = int2ccl(ifail);
  pop2(Lwi,Lwr);
  errexit();
  
  return Llist(nil,3,Lwr,Lwi,Lifail);
}

Lisp_Object MS_CDECL Ls13aaf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS13AAF) (double *, int32_t *);
  HINSTANCE hLib;
  PS13AAF s13aaf_proc;
#else
  extern double __stdcall S13AAF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s13aaf_proc = (PS13AAF) GetProcAddress (hLib, "_S13AAF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s13aaf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
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
#endif

Lisp_Object MS_CDECL Ls13acf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS13ACF) (double *, int32_t *);
  HINSTANCE hLib;
  PS13ACF s13acf_proc;
#else
  extern double __stdcall S13ACF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s13acf_proc = (PS13ACF) GetProcAddress (hLib, "_S13ACF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s13acf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S13ACF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls13adf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS13ADF) (double *, int32_t *);
  HINSTANCE hLib;
  PS13ADF s13adf_proc;
#else
  extern double __stdcall S13ADF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s13adf_proc = (PS13ADF) GetProcAddress (hLib, "_S13ADF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s13adf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S13ADF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls14aaf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS14AAF) (double *, int32_t *);
  HINSTANCE hLib;
  PS14AAF s14aaf_proc;
#else
  extern double __stdcall S14AAF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s14aaf_proc = (PS14AAF) GetProcAddress (hLib, "_S14AAF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s14aaf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S14AAF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls14abf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS14ABF) (double *, int32_t *);
  HINSTANCE hLib;
  PS14ABF s14abf_proc;
#else
  extern double __stdcall S14ABF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s14abf_proc = (PS14ABF) GetProcAddress (hLib, "_S14ABF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s14abf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S14ABF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls14baf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object La, Lx, Ltol, Lp, Lq, Lifail;
  double a, x, tol, p, q;
  int32_t ifail;

#ifdef LOADLIB
  typedef void (__stdcall *PS14BAF) (double *, double *, double *, double *,
	  double *, int32_t *);
  HINSTANCE hLib;
  PS14BAF s14baf_proc;
#else
  extern void __stdcall S14BAF (double *, double *, double *, double *,
	  double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,4,"Ls14baf");
  va_start(args,nargs);
  La = va_arg(args, Lisp_Object);
  Lx = va_arg(args, Lisp_Object);
  Ltol = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(La,Lx,Ltol,Lifail);
  a = float_of_number(La);
  pop4(Lifail,Ltol,Lx,La);
  errexit();
  push4(La,Lx,Ltol,Lifail);
  x = float_of_number(Lx);
  pop4(Lifail,Ltol,Lx,La);
  errexit();
  push4(La,Lx,Ltol,Lifail);
  tol = float_of_number(Ltol);
  pop4(Lifail,Ltol,Lx,La);
  errexit();
  push4(La,Lx,Ltol,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Ltol,Lx,La);
  errexit();

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s14baf_proc = (PS14BAF) GetProcAddress (hLib, "_S14BAF@24"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s14baf_proc) (&a, &x, &tol, &p, &q, &ifail);
    }
  }

  currlib = hLib;
#else
  S14BAF (&a, &x, &tol, &p, &q, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lp = make_boxfloat(p,TYPE_DOUBLE_FLOAT);
  push(Lp);
  Lq = make_boxfloat(q,TYPE_DOUBLE_FLOAT);
  pop(Lp);
  errexit();
  push2(Lp,Lq);
  Lifail = int2ccl(ifail);
  pop2(Lq,Lp);
  errexit();
  
  return Llist(nil,3,Lp,Lq,Lifail);
}

Lisp_Object MS_CDECL Ls15adf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS15ADF) (double *, int32_t *);
  HINSTANCE hLib;
  PS15ADF s15adf_proc;
#else
  extern double __stdcall S15ADF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s15adf_proc = (PS15ADF) GetProcAddress (hLib, "_S15ADF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s15adf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S15ADF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls15aef(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS15AEF) (double *, int32_t *);
  HINSTANCE hLib;
  PS15AEF s15aef_proc;
#else
  extern double __stdcall S15AEF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s15aef_proc = (PS15AEF) GetProcAddress (hLib, "_S15AEF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s15aef_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S15AEF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17acf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17ACF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17ACF s17acf_proc;
#else
  extern double __stdcall S17ACF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17acf_proc = (PS17ACF) GetProcAddress (hLib, "_S17ACF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17acf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17ACF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17adf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17ADF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17ADF s17adf_proc;
#else
  extern double __stdcall S17ADF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17adf_proc = (PS17ADF) GetProcAddress (hLib, "_S17ADF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17adf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17ADF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17aef(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17AEF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17AEF s17aef_proc;
#else
  extern double __stdcall S17AEF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17aef_proc = (PS17AEF) GetProcAddress (hLib, "_S17AEF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17aef_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17AEF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17aff(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17AFF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17AFF s17aff_proc;
#else
  extern double __stdcall S17AFF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17aff_proc = (PS17AFF) GetProcAddress (hLib, "_S17AFF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17aff_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17AFF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17agf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17AGF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17AGF s17agf_proc;
#else
  extern double __stdcall S17AGF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17agf_proc = (PS17AGF) GetProcAddress (hLib, "_S17AGF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17agf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17AGF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17ahf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17AHF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17AHF s17ahf_proc;
#else
  extern double __stdcall S17AHF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17ahf_proc = (PS17AHF) GetProcAddress (hLib, "_S17AHF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17ahf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17AHF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17ajf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17AJF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17AJF s17ajf_proc;
#else
  extern double __stdcall S17AJF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17ajf_proc = (PS17AJF) GetProcAddress (hLib, "_S17AJF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17ajf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17AJF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls17akf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS17AKF) (double *, int32_t *);
  HINSTANCE hLib;
  PS17AKF s17akf_proc;
#else
  extern double __stdcall S17AKF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17akf_proc = (PS17AKF) GetProcAddress (hLib, "_S17AKF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s17akf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S17AKF(&x,&ifail);
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

#if 1
Lisp_Object MS_CDECL Ls17dcf(Lisp_Object nil, int nargs, ...)
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
  fstring1 scale;
  double z[2], *cy, *cwrk, fnu;
  int32_t n, nz, ifail;
  char sscale[2];

#ifdef LOADLIB
  typedef void (__stdcall *PS17DCF) (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, double *, int32_t *);
  HINSTANCE hLib;
  PS17DCF s17dcf_proc;
#else
  extern void __stdcall S17DCF (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,6,"Ls17dcf");
  va_start(args,nargs);
  Lfnu = va_arg(args, Lisp_Object);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lscale = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  fnu = float_of_number(Lfnu);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[0] = float_of_number(Lzr);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[1] = float_of_number(Lzi);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  n = thirty_two_bits(Ln);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
  sscale[0] = celt(Lscale,0);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  sscale[1] = '\0';
  scale.str = sscale;
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);

  scale.len = 1;

  /* Setup workspace arrays etc. */
  cy = (double *)malloc(n*2*sizeof(double));	/* "complex" array */
  cwrk = (double *)malloc(n*2*sizeof(double));	/* "complex" array */

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17dcf_proc = (PS17DCF) GetProcAddress (hLib, "_S17DCF@36"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s17dcf_proc) (&fnu, z, &n, scale, cy, &nz, cwrk, &ifail);
    }
  }

  currlib = hLib;
#else
  S17DCF(&fnu, z, &n, scale, cy, &nz, cwrk, &ifail);
#endif
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lcy = mkComplexVector(cy,n,1);
  push(Lcy);
  Lifail = int2ccl(ifail);
  pop(Lcy);
  errexit();
  push2(Lcy,Lifail);
  Lnz = int2ccl(nz);
  pop2(Lifail,Lcy);
  errexit();

  free (cy);
  free (cwrk);
  
  return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ls17def(Lisp_Object nil, int nargs, ...)
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
  fstring1 scale;
  double z[2], *cy, fnu;
  int32_t n, nz, ifail;
  char sscale[2];

#ifdef LOADLIB
  typedef void (__stdcall *PS17DEF) (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PS17DEF s17def_proc;
#else
  extern void __stdcall S17DEF (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,6,"Ls17def");
  va_start(args,nargs);
  Lfnu = va_arg(args, Lisp_Object);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lscale = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  fnu = float_of_number(Lfnu);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[0] = float_of_number(Lzr);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[1] = float_of_number(Lzi);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  n = thirty_two_bits(Ln);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
  sscale[0] = celt(Lscale,0);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  sscale[1] = '\0';
  scale.str = sscale;
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);

  scale.len = 1;

  /* Setup workspace arrays etc. */
  cy = (double *)malloc(n*2*sizeof(double));	/* "complex" array */

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17def_proc = (PS17DEF) GetProcAddress (hLib, "_S17DEF@32"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s17def_proc) (&fnu, z, &n, scale, cy, &nz, &ifail);
    }
  }

  currlib = hLib;
#else
  S17DEF(&fnu, z, &n, scale, cy, &nz, &ifail);
#endif
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lcy = mkComplexVector(cy,n,1);
  push(Lcy);
  Lifail = int2ccl(ifail);
  pop(Lcy);
  errexit();
  push2(Lcy,Lifail);
  Lnz = int2ccl(nz);
  pop2(Lifail,Lcy);
  errexit();

  free (cy);
  
  return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{
  return Llist(nil, 0);
}
#endif

Lisp_Object MS_CDECL Ls17dgf(Lisp_Object nil, int nargs, ...)
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lderiv, Lzr, Lzi, Lscale, Lifail, Lair, Laii, Lnz;
  fstring1 deriv, scale;
  double z[2], ai[2];
  int32_t nz, ifail;
  char sderiv[2], sscale[2];

#ifdef LOADLIB
  typedef void (__stdcall *PS17DGF) (fstring1, double *, fstring1, double *,
	  int32_t *, int32_t *);
  HINSTANCE hLib;
  PS17DGF s17dgf_proc;
#else
  extern void __stdcall S17DGF (fstring1, double *, fstring1, double *,
	  int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,5,"Ls17dgf");
  va_start(args,nargs);
  Lderiv = va_arg(args, Lisp_Object);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Lscale = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sderiv, &celt(Lderiv,0), 1);
  sderiv[0] = celt(Lderiv,0);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  sderiv[1] = '\0';
  deriv.str = sderiv;
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
  z[0] = float_of_number(Lzr);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
  z[1] = float_of_number(Lzi);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
  sscale[0] = celt(Lscale,0);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  sscale[1] = '\0';
  scale.str = sscale;
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();

  deriv.len = 1;
  scale.len = 1;

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17dgf_proc = (PS17DGF) GetProcAddress (hLib, "_S17DGF@32"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s17dgf_proc) (deriv, z, scale, ai, &nz, &ifail);
    }
  }

  currlib = hLib;
#else
  S17DGF(deriv, z, scale, ai, &nz, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lair = make_boxfloat(ai[0],TYPE_DOUBLE_FLOAT);
  push(Lair);
  Laii = make_boxfloat(ai[1],TYPE_DOUBLE_FLOAT);
  pop(Lair);
  errexit();
  push2(Lair,Laii);
  Lifail = int2ccl(ifail);
  pop2(Laii,Lair);
  errexit();
  push3(Lair,Laii,Lifail);
  Lnz = int2ccl(nz);
  pop3(Lifail,Laii,Lair);
  errexit();
  
  return Llist(nil,4,Lair,Laii,Lifail,Lnz);
}

Lisp_Object MS_CDECL Ls17dhf(Lisp_Object nil, int nargs, ...)
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lderiv, Lzr, Lzi, Lscale, Lifail, Lbir, Lbii;
  fstring1 deriv, scale;
  double z[2], bi[2];
  int32_t ifail;
  char sderiv[2], sscale[2];

#ifdef LOADLIB
  typedef void (__stdcall *PS17DHF) (fstring1, double *, fstring1, double *,
	  int32_t *);
  HINSTANCE hLib;
  PS17DHF s17dhf_proc;
#else
  extern void __stdcall S17DHF (fstring1, double *, fstring1, double *,
	  int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,5,"Ls17dhf");
  va_start(args,nargs);
  Lderiv = va_arg(args, Lisp_Object);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Lscale = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sderiv, &celt(Lderiv,0), 1);
  sderiv[0] = celt(Lderiv,0);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  sderiv[1] = '\0';
  deriv.str = sderiv;
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
  z[0] = float_of_number(Lzr);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
  z[1] = float_of_number(Lzi);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
  sscale[0] = celt(Lscale,0);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();
  sscale[1] = '\0';
  scale.str = sscale;
  push5(Lderiv,Lzr,Lzi,Lscale,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Lscale,Lzi,Lzr,Lderiv);
  errexit();

  deriv.len = 1;
  scale.len = 1;
  
  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17dhf_proc = (PS17DHF) GetProcAddress (hLib, "_S17DHF@28"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s17dhf_proc) (deriv, z, scale, bi, &ifail);
    }
  }

  currlib = hLib;
#else
  S17DHF(deriv, z, scale, bi, &ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lbir = make_boxfloat(bi[0],TYPE_DOUBLE_FLOAT);
  push(Lbir);
  Lbii = make_boxfloat(bi[1],TYPE_DOUBLE_FLOAT);
  pop(Lbir);
  errexit();
  push2(Lbir,Lbii);
  Lifail = int2ccl(ifail);
  pop2(Lbii,Lbir);
  errexit();
  
  return Llist(nil,3,Lbir,Lbii,Lifail);
}

#if 1
Lisp_Object MS_CDECL Ls17dlf(Lisp_Object nil, int nargs, ...)
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy, Lm;
  fstring1 scale;
  double z[2], *cy, fnu;
  int32_t n, nz, ifail, m;
  char sscale[2];

#ifdef LOADLIB
  typedef void (__stdcall *PS17DLF) (int32_t *, double *, double *, int32_t *,
	  fstring1, double *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PS17DLF s17dlf_proc;
#else
  extern void __stdcall S17DLF (int32_t *, double *, double *, int32_t *,
	  fstring1, double *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,7,"Ls17dlf");
  va_start(args,nargs);
  Lm = va_arg(args, Lisp_Object);
  Lfnu = va_arg(args, Lisp_Object);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lscale = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  m = thirty_two_bits(Lm);
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  fnu = float_of_number(Lfnu);
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[0] = float_of_number(Lzr);
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[1] = float_of_number(Lzi);
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  n = thirty_two_bits(Ln);
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
  sscale[0] = celt(Lscale,0);
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();
  sscale[1] = '\0';
  scale.str = sscale;
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();
  push4(Lm,Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);

  scale.len = 1;

  /* Setup workspace arrays etc. */
  cy = (double *)malloc(n*2*sizeof(double));	/* "complex" array */

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s17dlf_proc = (PS17DLF) GetProcAddress (hLib, "_S17DLF@36"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s17dlf_proc) (&m, &fnu, z, &n, scale, cy, &nz, &ifail);
    }
  }

  currlib = hLib;
#else
  S17DLF(&m, &fnu, z, &n, scale, cy, &nz, &ifail);
#endif
  pop4(Lifail,Lscale,Ln,Lzi);
  pop3(Lzr,Lfnu,Lm);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lcy = mkComplexVector(cy,n,1);
  push(Lcy);
  Lifail = int2ccl(ifail);
  pop(Lcy);
  errexit();
  push2(Lcy,Lifail);
  Lnz = int2ccl(nz);
  pop2(Lifail,Lcy);
  errexit();

  free (cy);
  
  return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{
  return Llist(nil, 0);
}
#endif

Lisp_Object MS_CDECL Ls18acf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS18ACF) (double *, int32_t *);
  HINSTANCE hLib;
  PS18ACF s18acf_proc;
#else
  extern double __stdcall S18ACF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s18acf_proc = (PS18ACF) GetProcAddress (hLib, "_S18ACF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s18acf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S18ACF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls18adf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS18ADF) (double *, int32_t *);
  HINSTANCE hLib;
  PS18ADF s18adf_proc;
#else
  extern double __stdcall S18ADF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s18adf_proc = (PS18ADF) GetProcAddress (hLib, "_S18ADF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s18adf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S18ADF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls18aef(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS18AEF) (double *, int32_t *);
  HINSTANCE hLib;
  PS18AEF s18aef_proc;
#else
  extern double __stdcall S18AEF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s18aef_proc = (PS18AEF) GetProcAddress (hLib, "_S18AEF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s18aef_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S18AEF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls18aff(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS18AFF) (double *, int32_t *);
  HINSTANCE hLib;
  PS18AFF s18aff_proc;
#else
  extern double __stdcall S18AFF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s18aff_proc = (PS18AFF) GetProcAddress (hLib, "_S18AFF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s18aff_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S18AFF(&x,&ifail);
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

#if 1
Lisp_Object MS_CDECL Ls18dcf(Lisp_Object nil, int nargs, ...)
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
  fstring1 scale;
  double z[2], *cy, fnu;
  int32_t n, nz, ifail;
  char sscale[2];

#ifdef LOADLIB
  typedef void (__stdcall *PS18DCF) (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PS18DCF s18dcf_proc;
#else
  extern void __stdcall S18DCF (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,6,"Ls18dcf");
  va_start(args,nargs);
  Lfnu = va_arg(args, Lisp_Object);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lscale = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  fnu = float_of_number(Lfnu);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[0] = float_of_number(Lzr);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[1] = float_of_number(Lzi);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  n = thirty_two_bits(Ln);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
  sscale[0] = celt(Lscale,0);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  sscale[1] = '\0';
  scale.str = sscale;
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);

  scale.len = 1;

  /* Setup workspace arrays etc. */
  cy = (double *)malloc(n*2*sizeof(double));	/* "complex" array */

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s18dcf_proc = (PS18DCF) GetProcAddress (hLib, "_S18DCF@32"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s18dcf_proc) (&fnu, z, &n, scale, cy, &nz, &ifail);
    }
  }

  currlib = hLib;
#else
  S18DCF(&fnu, z, &n, scale, cy, &nz, &ifail);
#endif
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lcy = mkComplexVector(cy,n,1);
  push(Lcy);
  Lifail = int2ccl(ifail);
  pop(Lcy);
  errexit();
  push2(Lcy,Lifail);
  Lnz = int2ccl(nz);
  pop2(Lifail,Lcy);
  errexit();

  free (cy);
  
  return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{
  return Llist(nil, 0);
}
#endif

#if 1
Lisp_Object MS_CDECL Ls18def(Lisp_Object nil, int nargs, ...)
{							/* FIXME: strings */
  va_list args;
  Lisp_Object Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
  fstring1 scale;
  double z[2], *cy, fnu;
  int32_t n, nz, ifail;
  char sscale[2];

#ifdef LOADLIB
  typedef void (__stdcall *PS18DEF) (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, int32_t *);
  HINSTANCE hLib;
  PS18DEF s18def_proc;
#else
  extern void __stdcall S18DEF (double *, double *, int32_t *, fstring1,
	  double *, int32_t *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,6,"Ls18def");
  va_start(args,nargs);
  Lfnu = va_arg(args, Lisp_Object);
  Lzr = va_arg(args, Lisp_Object);
  Lzi = va_arg(args, Lisp_Object);
  Ln = va_arg(args, Lisp_Object);
  Lscale = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  fnu = float_of_number(Lfnu);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[0] = float_of_number(Lzr);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  z[1] = float_of_number(Lzi);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  n = thirty_two_bits(Ln);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
  sscale[0] = celt(Lscale,0);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  sscale[1] = '\0';
  scale.str = sscale;
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();
  push3(Lfnu,Lzr,Lzi);
  push3(Ln,Lscale,Lifail);

  scale.len = 1;

  /* Setup workspace arrays etc. */
  cy = (double *)malloc(n*2*sizeof(double));	/* "complex" array */

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s18def_proc = (PS18DEF) GetProcAddress (hLib, "_S18DEF@32"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      (*s18def_proc) (&fnu, z, &n, scale, cy, &nz, &ifail);
    }
  }

  currlib = hLib;
#else
  S18DEF(&fnu, z, &n, scale, cy, &nz, &ifail);
#endif
  pop3(Lifail,Lscale,Ln);
  pop3(Lzi,Lzr,Lfnu);
  errexit();

  /* Translate return values to CCL */
  /* Copy result */
  Lcy = mkComplexVector(cy,n,1);
  push(Lcy);
  Lifail = int2ccl(ifail);
  pop(Lcy);
  errexit();
  push2(Lcy,Lifail);
  Lnz = int2ccl(nz);
  pop2(Lifail,Lcy);
  errexit();

  free (cy);
  
  return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{
  return Llist(nil, 0);
}
#endif

Lisp_Object MS_CDECL Ls19aaf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS19AAF) (double *, int32_t *);
  HINSTANCE hLib;
  PS19AAF s19aaf_proc;
#else
  extern double __stdcall S19AAF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s19aaf_proc = (PS19AAF) GetProcAddress (hLib, "_S19AAF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s19aaf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S19AAF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls19abf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS19ABF) (double *, int32_t *);
  HINSTANCE hLib;
  PS19ABF s19abf_proc;
#else
  extern double __stdcall S19ABF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s19abf_proc = (PS19ABF) GetProcAddress (hLib, "_S19ABF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s19abf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S19ABF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls19acf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS19ACF) (double *, int32_t *);
  HINSTANCE hLib;
  PS19ACF s19acf_proc;
#else
  extern double __stdcall S19ACF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s19acf_proc = (PS19ACF) GetProcAddress (hLib, "_S19ACF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s19acf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S19ACF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls19adf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS19ADF) (double *, int32_t *);
  HINSTANCE hLib;
  PS19ADF s19adf_proc;
#else
  extern double __stdcall S19ADF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s19adf_proc = (PS19ADF) GetProcAddress (hLib, "_S19ADF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s19adf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S19ADF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls20acf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS20ACF) (double *, int32_t *);
  HINSTANCE hLib;
  PS20ACF s20acf_proc;
#else
  extern double __stdcall S20ACF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s20acf_proc = (PS20ACF) GetProcAddress (hLib, "_S20ACF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s20acf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S20ACF(&x,&ifail);
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

Lisp_Object MS_CDECL Ls20adf(Lisp_Object nil, Lisp_Object Lx, Lisp_Object Lifail)
{
  Lisp_Object Ly;
  double x, y;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS20ADF) (double *, int32_t *);
  HINSTANCE hLib;
  PS20ADF s20adf_proc;
#else
  extern double __stdcall S20ADF (double *, int32_t *);
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
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s20adf_proc = (PS20ADF) GetProcAddress (hLib, "_S20ADF@8"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      y = (*s20adf_proc) (&x, &ifail);
    }
  }

  currlib = hLib;
#else
  y = S20ADF(&x,&ifail);
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


Lisp_Object MS_CDECL Ls21baf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lx, Ly, Lifail, Lrc;
  double x, y, rc;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS21BAF) (double *, double *, int32_t *);
  HINSTANCE hLib;
  PS21BAF s21baf_proc;
#else
  extern double __stdcall S21BAF (double *, double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,3,"Ls21baf");
  va_start(args,nargs);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push3(Lx,Ly,Lifail);
  x = float_of_number(Lx);
  pop3(Lifail,Ly,Lx);
  errexit();
  push3(Lx,Ly,Lifail);
  y = float_of_number(Ly);
  pop3(Lifail,Ly,Lx);
  errexit();
  push3(Lx,Ly,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop3(Lifail,Ly,Lx);
  errexit();

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s21baf_proc = (PS21BAF) GetProcAddress (hLib, "_S21BAF@12"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      rc = (*s21baf_proc) (&x, &y, &ifail);
    }
  }

  currlib = hLib;
#else
  rc = S21BAF(&x,&y,&ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lrc = make_boxfloat(rc,TYPE_DOUBLE_FLOAT);
  push(Lrc);
  Lifail = int2ccl(ifail);
  pop(Lrc);
  errexit();
  
  return Llist(nil,2,Lrc,Lifail);
}

Lisp_Object MS_CDECL Ls21bbf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lx, Ly, Lz, Lifail, Lrf;
  double x, y, z, rf;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS21BBF) (double *, double *, double *, int32_t *);
  HINSTANCE hLib;
  PS21BBF s21bbf_proc;
#else
  extern double __stdcall S21BBF (double *, double *, double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,4,"Ls21bbf");
  va_start(args,nargs);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Lz = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lx,Ly,Lz,Lifail);
  x = float_of_number(Lx);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lz,Lifail);
  y = float_of_number(Ly);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lz,Lifail);
  z = float_of_number(Lz);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lz,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s21bbf_proc = (PS21BBF) GetProcAddress (hLib, "_S21BBF@16"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      rf = (*s21bbf_proc) (&x, &y, &z, &ifail);
    }
  }

  currlib = hLib;
#else
  rf = S21BBF(&x,&y,&z,&ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lrf = make_boxfloat(rf,TYPE_DOUBLE_FLOAT);
  push(Lrf);
  Lifail = int2ccl(ifail);
  pop(Lrf);
  errexit();
  
  return Llist(nil,2,Lrf,Lifail);
}

Lisp_Object MS_CDECL Ls21bcf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lx, Ly, Lz, Lifail, Lrd;
  double x, y, z, rd;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS21BCF) (double *, double *, double *, int32_t *);
  HINSTANCE hLib;
  PS21BCF s21bcf_proc;
#else
  extern double __stdcall S21BCF (double *, double *, double *, int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,4,"Ls21bcf");
  va_start(args,nargs);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Lz = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push4(Lx,Ly,Lz,Lifail);
  x = float_of_number(Lx);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lz,Lifail);
  y = float_of_number(Ly);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lz,Lifail);
  z = float_of_number(Lz);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();
  push4(Lx,Ly,Lz,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop4(Lifail,Lz,Ly,Lx);
  errexit();

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s21bcf_proc = (PS21BCF) GetProcAddress (hLib, "_S21BCF@16"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      rd = (*s21bcf_proc) (&x, &y, &z, &ifail);
    }
  }

  currlib = hLib;
#else
  rd = S21BCF(&x,&y,&z,&ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lrd = make_boxfloat(rd,TYPE_DOUBLE_FLOAT);
  push(Lrd);
  Lifail = int2ccl(ifail);
  pop(Lrd);
  errexit();
  
  return Llist(nil,2,Lrd,Lifail);
}

Lisp_Object MS_CDECL Ls21bdf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object Lx, Ly, Lz, Lr, Lifail, Lrj;
  double x, y, z, r, rj;
  int32_t ifail;

#ifdef LOADLIB
  typedef double (__stdcall *PS21BDF) (double *, double *, double *, double *,
	  int32_t *);
  HINSTANCE hLib;
  PS21BDF s21bdf_proc;
#else
  extern double __stdcall S21BDF (double *, double *, double *, double *,
	  int32_t *);
#endif

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,5,"Ls21bdf");
  va_start(args,nargs);
  Lx = va_arg(args, Lisp_Object);
  Ly = va_arg(args, Lisp_Object);
  Lz = va_arg(args, Lisp_Object);
  Lr = va_arg(args, Lisp_Object);
  Lifail = va_arg(args, Lisp_Object);
  va_end(args);

  /* Translate arguments into C objects */
  push5(Lx,Ly,Lz,Lr,Lifail);
  x = float_of_number(Lx);
  pop5(Lifail,Lr,Lz,Ly,Lx);
  errexit();
  push5(Lx,Ly,Lz,Lr,Lifail);
  y = float_of_number(Ly);
  pop5(Lifail,Lr,Lz,Ly,Lx);
  errexit();
  push5(Lx,Ly,Lz,Lr,Lifail);
  z = float_of_number(Lz);
  pop5(Lifail,Lr,Lz,Ly,Lx);
  errexit();
  push5(Lx,Ly,Lz,Lr,Lifail);
  r = float_of_number(Lr);
  pop5(Lifail,Lr,Lz,Ly,Lx);
  errexit();
  push5(Lx,Ly,Lz,Lr,Lifail);
  ifail = thirty_two_bits(Lifail);
  pop5(Lifail,Lr,Lz,Ly,Lx);
  errexit();

  /* Call NAG routine */
#ifdef LOADLIB
  free_prevlib ();
  
  if ( (hLib = LoadLibrary ("nagfas")) == NULL )
  {
    /* couldn't find DLL -- error handling here */
    ifail = -999;
  }
  else	/* OK so far */
  {
    if ( (s21bdf_proc = (PS21BDF) GetProcAddress (hLib, "_S21BDF@20"))
	    == NULL )
    {
      /* couldn't find function within DLL -- error handling here */
      ifail = -998;
    }
    else	/* have found function in DLL */
    {
      rj = (*s21bdf_proc) (&x, &y, &z, &r, &ifail);
    }
  }

  currlib = hLib;
#else
  rj = S21BDF(&x,&y,&z,&r,&ifail);
#endif

  /* Translate return values to CCL */
  /* Copy result */
  Lrj = make_boxfloat(rj,TYPE_DOUBLE_FLOAT);
  push(Lrj);
  Lifail = int2ccl(ifail);
  pop(Lrj);
  errexit();
  
  return Llist(nil,2,Lrj,Lifail);
}
