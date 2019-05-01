//
// This code was contributed to CSL by NAG Ltd.
//


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

/* $Id$ */


LispObject Ld01ajf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,7,"Ld01ajf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Lepsrel = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    b = float_of_number(Lb);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    epsrel = float_of_number(Lepsrel);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);

    // Setup workspace arrays etc.
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    // Call NAG routine
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01ajf_proc = (PD01AJF) GetProcAddress (hLib, "_D01AJF@48"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01ajf_proc) (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w,
                            &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01AJF (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w, &lw, iw,
            &liw, &ifail);
#endif
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);

    // Translate return values to CCL
    // Copy result
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    push(Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult);
    push(Lresult,Labserr);
    Lw = mkFloatVector(w,lw,1);
    pop(Labserr,Lresult);
    push(Lresult,Labserr,Lw);
    Liw = mkIntVector(iw,liw,1);
    pop(Lw,Labserr,Lresult);
    push(Lresult,Labserr,Lw,Liw);
    Lifail = int2ccl(ifail);
    pop(Liw,Lw,Labserr,Lresult);

    free (w);
    free (iw);

    return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}

LispObject Ld01akf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,7,"Ld01akf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Lepsrel = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    b = float_of_number(Lb);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    epsrel = float_of_number(Lepsrel);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);
    push(La,Lb,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lb,La);

    // Setup workspace arrays etc.
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01akf_proc = (PD01AKF) GetProcAddress (hLib, "_D01AKF@48"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01akf_proc) (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w,
                            &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01AKF (&asp1, &a, &b, &epsabs, &epsrel, &result, &abserr, w, &lw, iw,
            &liw, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    push(Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult);
    push(Lresult,Labserr);
    Lw = mkFloatVector(w,lw,1);
    pop(Labserr,Lresult);
    push(Lresult,Labserr,Lw);
    Liw = mkIntVector(iw,liw,1);
    pop(Lw,Labserr,Lresult);
    push(Lresult,Labserr,Lw,Liw);
    Lifail = int2ccl(ifail);
    pop(Liw,Lw,Labserr,Lresult);

    free (w);
    free (iw);

    return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}

#if 1
LispObject Ld01alf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,9,"Ld01alf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lnpts = va_arg(args, LispObject);
    Lpoints = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Lepsrel = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    b = float_of_number(Lb);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    npts = thirty_two_bits(Lnpts);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    // ndim = (length_of_header(vechdr(Lpoints)) - 4)/4;
    points = (double *)malloc(npts*sizeof(double));
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    mkFortranVectorDouble(points, Lpoints, npts);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    epsrel = float_of_number(Lepsrel);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);
    push(La,Lb,Lnpts,Lpoints,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lpoints,Lnpts,Lb,La);

    // Setup workspace arrays etc.
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01alf_proc = (PD01ALF) GetProcAddress (hLib, "_D01ALF@56"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01alf_proc) (&asp1, &a, &b, &npts, points, &epsabs, &epsrel,
                            &result, &abserr, w, &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01ALF (&asp1, &a, &b, &npts, points, &epsabs, &epsrel, &result, &abserr,
            w, &lw, iw, &liw, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    push(Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult);
    push(Lresult,Labserr);
    Lw = mkFloatVector(w,lw,1);
    pop(Labserr,Lresult);
    push(Lresult,Labserr,Lw);
    Liw = mkIntVector(iw,liw,1);
    pop(Lw,Labserr,Lresult);
    push(Lresult,Labserr,Lw,Liw);
    Lifail = int2ccl(ifail);
    pop(Liw,Lw,Labserr,Lresult);

    free (points);
    free (w);
    free (iw);

    return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
LispObject Ld01alf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01amf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr, Lw, Liw,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,7,"Ld01amf");
    va_start(args,nargs);
    Lbound = va_arg(args, LispObject);
    Linf = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Lepsrel = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    bound = float_of_number(Lbound);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);
    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    inf = thirty_two_bits(Linf);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);
    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);
    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    epsrel = float_of_number(Lepsrel);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);
    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);
    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);
    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);

    // Setup workspace arrays etc.
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    push(Lbound,Linf,Lepsabs,Lepsrel);
    push(Llw,Lliw,Lifail);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01amf_proc = (PD01AMF) GetProcAddress (hLib, "_D01AMF@48"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01amf_proc) (&asp1, &bound, &inf, &epsabs, &epsrel, &result,
                            &abserr, w, &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01AMF (&asp1, &bound, &inf, &epsabs, &epsrel, &result, &abserr, w, &lw,
            iw, &liw, &ifail);
#endif
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Linf,Lbound);

    // Translate return values to CCL
    // Copy result
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    push(Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult);
    push(Lresult,Labserr);
    Lw = mkFloatVector(w,lw,1);
    pop(Labserr,Lresult);
    push(Lresult,Labserr,Lw);
    Liw = mkIntVector(iw,liw,1);
    pop(Lw,Labserr,Lresult);
    push(Lresult,Labserr,Lw,Liw);
    Lifail = int2ccl(ifail);
    pop(Liw,Lw,Labserr,Lresult);

    free (w);
    free (iw);

    return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
LispObject Ld01amf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01anf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,9,"Ld01anf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lomega = va_arg(args, LispObject);
    Lkey = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Lepsrel = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    b = float_of_number(Lb);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    omega = float_of_number(Lomega);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    key = thirty_two_bits(Lkey);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    epsrel = float_of_number(Lepsrel);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);
    push(La,Lb,Lomega,Lkey,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lomega,Lb,La);

    // Setup workspace arrays etc.
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01anf_proc = (PD01ANF) GetProcAddress (hLib, "_D01ANF@56"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01anf_proc) (&asp1, &a, &b, &omega, &key, &epsabs, &epsrel, &result,
                            &abserr, w, &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01ANF (&asp1, &a, &b, &omega, &key, &epsabs, &epsrel, &result, &abserr, w,
            &lw, iw, &liw, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    push(Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult);
    push(Lresult,Labserr);
    Lw = mkFloatVector(w,lw,1);
    pop(Labserr,Lresult);
    push(Lresult,Labserr,Lw);
    Liw = mkIntVector(iw,liw,1);
    pop(Lw,Labserr,Lresult);
    push(Lresult,Labserr,Lw,Liw);
    Lifail = int2ccl(ifail);
    pop(Liw,Lw,Labserr,Lresult);

    free (w);
    free (iw);

    return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
LispObject Ld01anf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01apf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,10,"Ld01apf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lalfa = va_arg(args, LispObject);
    Lbeta = va_arg(args, LispObject);
    Lkey = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Lepsrel = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    b = float_of_number(Lb);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    alfa = float_of_number(Lalfa);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    beta = float_of_number(Lbeta);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    key = thirty_two_bits(Lkey);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    epsrel = float_of_number(Lepsrel);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);
    push(La,Lb,Lalfa,Lbeta,Lkey);
    push(Lepsabs,Lepsrel,Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Lepsrel,Lepsabs);
    pop(Lkey,Lbeta,Lalfa,Lb,La);

    // Setup workspace arrays etc.
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01apf_proc = (PD01APF) GetProcAddress (hLib, "_D01APF@60"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01apf_proc) (&asp1, &a, &b, &alfa, &beta, &key, &epsabs, &epsrel,
                            &result, &abserr, w, &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01APF (&asp1, &a, &b, &alfa, &beta, &key, &epsabs, &epsrel, &result,
            &abserr, w, &lw, iw, &liw, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    push(Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult);
    push(Lresult,Labserr);
    Lw = mkFloatVector(w,lw,1);
    pop(Labserr,Lresult);
    push(Lresult,Labserr,Lw);
    Liw = mkIntVector(iw,liw,1);
    pop(Lw,Labserr,Lresult);
    push(Lresult,Labserr,Lw,Liw);
    Lifail = int2ccl(ifail);
    pop(Liw,Lw,Labserr,Lresult);

    free (w);
    free (iw);

    return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
LispObject Ld01apf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01aqf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lepsabs, Lepsrel, Llw, Lliw, Lifail, Lresult, Labserr,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,8,"Ld01aqf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lc = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Lepsrel = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    b = float_of_number(Lb);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    c = float_of_number(Lc);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    epsrel = float_of_number(Lepsrel);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);
    push(La,Lb,Lc,Lepsabs);
    push(Lepsrel,Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Lepsrel);
    pop(Lepsabs,Lc,Lb,La);

    // Setup workspace arrays etc.
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01aqf_proc = (PD01AQF) GetProcAddress (hLib, "_D01AQF@52"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01aqf_proc) (&asp1, &a, &b, &c, &epsabs, &epsrel, &result, &abserr,
                            w, &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01AQF (&asp1, &a, &b, &c, &epsabs, &epsrel, &result, &abserr, w, &lw, iw,
            &liw, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    push(Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult);
    push(Lresult,Labserr);
    Lw = mkFloatVector(w,lw,1);
    pop(Labserr,Lresult);
    push(Lresult,Labserr,Lw);
    Liw = mkIntVector(iw,liw,1);
    pop(Lw,Labserr,Lresult);
    push(Lresult,Labserr,Lw,Liw);
    Lifail = int2ccl(ifail);
    pop(Liw,Lw,Labserr,Lresult);

    free (w);
    free (iw);

    return Llist(nil,5,Lresult,Labserr,Lw,Liw,Lifail);
}
#else
LispObject Ld01aqf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01asf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lepsabs, Llw, Lliw, Lifail, Lresult, Labserr, Liw, Lomega,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,8,"Ld01asf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lomega = va_arg(args, LispObject);
    Lkey = va_arg(args, LispObject);
    Lepsabs = va_arg(args, LispObject);
    Llimlst = va_arg(args, LispObject);
    Llw = va_arg(args, LispObject);
    Lliw = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    omega = float_of_number(Lomega);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    key = thirty_two_bits(Lkey);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    epsabs = float_of_number(Lepsabs);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    limlst = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    lw = thirty_two_bits(Llw);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    liw = thirty_two_bits(Lliw);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);
    push(La,Lomega,Lkey,Lepsabs);
    push(Llimlst,Llw,Lliw,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lliw,Llw,Llimlst);
    pop(Lepsabs,Lkey,Lomega,La);

    // Setup workspace arrays etc.
    erlst = (double *)malloc(limlst*sizeof(double));
    rslst = (double *)malloc(limlst*sizeof(double));
    ierlst = (int32_t *)malloc(limlst*sizeof(int));
    w = (double *)malloc(lw*sizeof(double));
    iw = (int32_t *)malloc(liw*sizeof(int));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01asf_proc = (PD01ASF) GetProcAddress (hLib, "_D01ASF@68"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01asf_proc) (&asp1, &a, &omega, &key, &epsabs, &result, &abserr,
                            &limlst, &lst, erlst, rslst, ierlst, w, &lw, iw, &liw, &ifail);
        }
    }

    currlib = hLib;
#else
    D01ASF (&asp1, &a, &omega, &key, &epsabs, &result, &abserr, &limlst, &lst,
            erlst, rslst, ierlst, w, &lw, iw, &liw, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lierlst = mkIntVector(ierlst,limlst,1);
    push(Lierlst);
    Lresult = make_boxfloat(result,TYPE_DOUBLE_FLOAT);
    pop(Lierlst);
    push(Lierlst,Lresult);
    Labserr = make_boxfloat(abserr,TYPE_DOUBLE_FLOAT);
    pop(Lresult,Lierlst);
    push(Lierlst,Lresult,Labserr);
    Lerlst = mkFloatVector(erlst,limlst,1);
    pop(Labserr,Lresult,Lierlst);
    push(Lierlst,Lresult,Labserr,Lerlst);
    Lifail = int2ccl(ifail);
    pop(Lerlst,Labserr,Lresult,Lierlst);
    push(Lierlst,Lresult,Labserr,Lerlst,Lifail);
    Liw = mkIntVector(iw,liw,1);
    pop(Lifail,Lerlst,Labserr,Lresult,Lierlst);
    push(Lierlst,Lresult,Labserr);
    push(Lerlst,Lifail,Liw);
    Llst = int2ccl(lst);
    pop(Liw,Lifail,Lerlst);
    pop(Labserr,Lresult,Lierlst);
    push(Lierlst,Lresult,Labserr,Lerlst);
    push(Lifail,Liw,Llst);
    Lrslst = mkFloatVector(rslst,limlst,1);
    pop(Llst,Liw,Lifail,Lerlst);
    pop(Labserr,Lresult,Lierlst);

    free (erlst);
    free (rslst);
    free (ierlst);
    free (w);
    free (iw);

    return Llist(nil,8,Lierlst,Lresult,Labserr,Lerlst,Lifail,Liw,Llst,Lrslst);
}
#else
LispObject Ld01asf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01bbf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Litype, Ln, Lgtype, Lifail, Lweight, Labscis;
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,6,"Ld01bbf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Litype = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lgtype = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lb,Litype);
    push(Ln,Lgtype,Lifail);
    a = float_of_number(La);
    pop(Lifail,Lgtype,Ln);
    pop(Litype,Lb,La);
    push(La,Lb,Litype);
    push(Ln,Lgtype,Lifail);
    b = float_of_number(Lb);
    pop(Lifail,Lgtype,Ln);
    pop(Litype,Lb,La);
    push(La,Lb,Litype);
    push(Ln,Lgtype,Lifail);
    itype = thirty_two_bits(Litype);
    pop(Lifail,Lgtype,Ln);
    pop(Litype,Lb,La);
    push(La,Lb,Litype);
    push(Ln,Lgtype,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Lgtype,Ln);
    pop(Litype,Lb,La);
    push(La,Lb,Litype);
    push(Ln,Lgtype,Lifail);
    gtype = thirty_two_bits(Lgtype);
    pop(Lifail,Lgtype,Ln);
    pop(Litype,Lb,La);
    push(La,Lb,Litype);
    push(Ln,Lgtype,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lgtype,Ln);
    pop(Litype,Lb,La);
    push(La,Lb,Litype);
    push(Ln,Lgtype,Lifail);

    /* Setup workspace arrays etc. */  // return value arrays in this case
    weight = (double *)malloc(n*sizeof(double));
    abscis = (double *)malloc(n*sizeof(double));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   // FIXME - DLL name?
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (ad01bb_proc = (PAD01BB) GetProcAddress (hLib, "_AD01BB@32"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*ad01bb_proc) (&a, &b, &itype, &n, weight, abscis, &gtype, &ifail);
        }
    }

    currlib = hLib;
#else
    AD01BB (&a, &b, &itype, &n, weight, abscis, &gtype, &ifail);
#endif
    pop(Lifail,Lgtype,Ln);
    pop(Litype,Lb,La);

    // Translate return values to CCL
    // Copy result
    Lweight = mkFloatVector(weight,n,1);
    push(Lweight);
    Labscis = mkFloatVector(abscis,n,1);
    pop(Lweight);
    push(Lweight,Labscis);
    Lifail = int2ccl(ifail);
    pop(Labscis,Lweight);

    free (weight);
    free (abscis);

    return Llist(nil,3,Lweight,Labscis,Lifail);
}
#else
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01fcf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lndim, Leps, Lminpts, Lmaxpts, Lifail, Lfinval, Lacc,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,8,"Ld01fcf");
    va_start(args,nargs);
    Lndim = va_arg(args, LispObject);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lmaxpts = va_arg(args, LispObject);
    Leps = va_arg(args, LispObject);
    Llenwrk = va_arg(args, LispObject);
    Lminpts = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    ndim = thirty_two_bits(Lndim);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);
    a = (double *) malloc (ndim * sizeof(double));
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    mkFortranVectorDouble(a, La, ndim);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);
    b = (double *) malloc (ndim * sizeof(double));
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    mkFortranVectorDouble(b, Lb, ndim);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    maxpts = thirty_two_bits(Lmaxpts);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    eps = float_of_number(Leps);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    lenwrk = thirty_two_bits(Llenwrk);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    minpts = thirty_two_bits(Lminpts);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);

    // Setup workspace arrays etc.
    wrkstr = (double *)malloc(lenwrk*sizeof(double));

    push(Lndim,La,Lb,Lmaxpts);
    push(Leps,Llenwrk,Lminpts,Lifail);
    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01fcf_proc = (PD01FCF) GetProcAddress (hLib, "_D01FCF@48"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01fcf_proc) (&ndim, a, b, &minpts, &maxpts, &asp4, &eps, &acc,
                            &lenwrk, wrkstr, &finval, &ifail);
        }
    }

    currlib = hLib;
#else
    D01FCF (&ndim, a, b, &minpts, &maxpts, &asp4, &eps, &acc, &lenwrk, wrkstr,
            &finval, &ifail);
#endif
    pop(Lifail,Lminpts,Llenwrk,Leps);
    pop(Lmaxpts,Lb,La,Lndim);

    // Translate return values to CCL
    // Copy result
    Lfinval = make_boxfloat(finval,TYPE_DOUBLE_FLOAT);
    push(Lfinval);
    Lminpts = int2ccl(minpts);
    pop(Lfinval);
    push(Lfinval,Lminpts);
    Lifail = int2ccl(ifail);
    pop(Lminpts,Lfinval);
    push(Lfinval,Lminpts,Lifail);
    Lacc = make_boxfloat(acc,TYPE_DOUBLE_FLOAT);
    pop(Lifail,Lminpts,Lfinval);

    free (a);
    free (b);
    free (wrkstr);

    return Llist(nil,4,Lfinval,Lminpts,Lifail,Lacc);
}
#else
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01gaf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject Lx, Ly, Ln, Lans, Ler, Lifail;
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,4,"Ld01gaf");
    va_start(args,nargs);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lx,Ly,Ln,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Ln,Ly,Lx);
    x = (double *) malloc (n * sizeof(double));
    push(Lx,Ly,Ln,Lifail);
    mkFortranVectorDouble(x, Lx, n);
    pop(Lifail,Ln,Ly,Lx);
    y = (double *) malloc (n * sizeof(double));
    push(Lx,Ly,Ln,Lifail);
    mkFortranVectorDouble(y, Ly, n);
    pop(Lifail,Ln,Ly,Lx);
    push(Lx,Ly,Ln,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Ln,Ly,Lx);

    push(Lx,Ly,Ln,Lifail);
    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01gaf_proc = (PD01GAF) GetProcAddress (hLib, "_D01GAF@24"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01gaf_proc) (x, y, &n, &ans, &er, &ifail);
        }
    }

    currlib = hLib;
#else
    D01GAF (x, y, &n, &ans, &er, &ifail);
#endif
    pop(Lifail,Ln,Ly,Lx);

    // Translate return values to CCL
    // Copy result
    Lans = make_boxfloat(ans,TYPE_DOUBLE_FLOAT);
    push(Lans);
    Ler = make_boxfloat(er,TYPE_DOUBLE_FLOAT);
    pop(Lans);
    push(Lans,Ler);
    Lifail = int2ccl(ifail);
    pop(Ler,Lans);

    free (x);
    free (y);

    return Llist(nil,3,Lans,Ler,Lifail);
}
#else
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ld01gbf(LispObject env, int nargs, ...)
{   va_list args;
    LispObject La, Lb, Lndim, Leps, Lmincls, Lmaxcls, Lifail, Lfinval, Lacc,
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,9,"Ld01gbf");
    va_start(args,nargs);
    Lndim = va_arg(args, LispObject);
    La = va_arg(args, LispObject);
    Lb = va_arg(args, LispObject);
    Lmaxcls = va_arg(args, LispObject);
    Leps = va_arg(args, LispObject);
    Llenwrk = va_arg(args, LispObject);
    Lmincls = va_arg(args, LispObject);
    Lwrkstr = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    ndim = thirty_two_bits(Lndim);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    a = (double *) malloc (ndim * sizeof(double));
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    mkFortranVectorDouble(a, La, ndim);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    b = (double *) malloc (ndim * sizeof(double));
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    mkFortranVectorDouble(b, Lb, ndim);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    maxcls = thirty_two_bits(Lmaxcls);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    eps = float_of_number(Leps);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    lenwrk = thirty_two_bits(Llenwrk);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    mincls = thirty_two_bits(Lmincls);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    wrkstr = (double *) malloc (lenwrk * sizeof(double));
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    mkFortranVectorDouble(wrkstr, Lwrkstr, lenwrk);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);
    push(Lndim,La,Lb,Lmaxcls,Leps);
    push(Llenwrk,Lmincls,Lwrkstr,Lifail);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d01gbf_proc = (PD01GBF) GetProcAddress (hLib, "_D01GBF@48"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d01gbf_proc) (&ndim, a, b, &mincls, &maxcls, &asp4, &eps, &acc,
                            &lenwrk, wrkstr, &finval, &ifail);
        }
    }

    currlib = hLib;
#else
    D01GBF (&ndim, a, b, &mincls, &maxcls, &asp4, &eps, &acc, &lenwrk, wrkstr,
            &finval, &ifail);
#endif
    pop(Lifail,Lwrkstr,Lmincls,Llenwrk,Leps);
    pop(Lmaxcls,Lb,La,Lndim);

    // Translate return values to CCL
    // Copy result
    Lfinval = make_boxfloat(finval,TYPE_DOUBLE_FLOAT);
    push(Lfinval);
    Lmincls = int2ccl(mincls);
    pop(Lfinval);
    push(Lfinval,Lmincls);
    Lifail = int2ccl(ifail);
    pop(Lmincls,Lfinval);
    push(Lfinval,Lmincls,Lifail);
    Lwrkstr = mkFloatVector(wrkstr,lenwrk,1);
    pop(Lifail,Lmincls,Lfinval);
    push(Lfinval,Lmincls,Lifail,Lwrkstr);
    Lacc = make_boxfloat(acc,TYPE_DOUBLE_FLOAT);
    pop(Lwrkstr,Lifail,Lmincls,Lfinval);

    free (a);
    free (b);
    free (wrkstr);

    return Llist(nil,5,Lfinval,Lmincls,Lifail,Lwrkstr,Lacc);
}
#else
{   return Llist(nil, 0);
}
#endif

LispObject Ld02bbf(LispObject env, int nargs, ...)
#if 0
{   va_list args;
    LispObject Lx, Lxend, Lm, Ln, Ly, Ltol, Lirelab, Lresult, Lifail;
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,8,"Ld02bbf");
    va_start(args,nargs);
    Lxend = va_arg(args, LispObject);
    Lm = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lirelab = va_arg(args, LispObject);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Ltol = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    xend = float_of_number(Lxend);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    m = thirty_two_bits(Lm);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    irelab = thirty_two_bits(Lirelab);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);
    y = (double *) malloc (n * sizeof(double));
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    mkFortranVectorDouble(y, Ly, n);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    tol = float_of_number(Ltol);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lirelab);
    push(Lx,Ly,Ltol,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lirelab,Ln,Lm,Lxend);

    // Setup workspace arrays etc.
    w = (double *)malloc(n*7*sizeof(double));
    result = (double *)malloc(m*n*sizeof(double));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   // FIXME - DLL name?
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (xd02bb_proc = (PXD02BB) GetProcAddress (hLib, "_XD02BB@48"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*xd02bb_proc) (&x, &xend, &m, &n, y, &tol, &irelab, result, &asp7,
                            &asp8, w, &ifail);
        }
    }

    currlib = hLib;
#else
    XD02BB (&x, &xend, &m, &n, y, &tol, &irelab, result, &asp7, &asp8, w,
            &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
    push(Lx);
    Ly = mkFloatVector(y,n,1);
    pop(Lx);
    push(Lx,Ly);
    Lresult = mkFloatVector(result,m,n);  // FIXME: correct array ordering?
    pop(Ly,Lx);
    push(Lx,Ly,Lresult);
    Lifail = int2ccl(ifail);
    pop(Lresult,Ly,Lx);
    push(Lx,Ly,Lresult,Lifail);
    Ltol = make_boxfloat(tol,TYPE_DOUBLE_FLOAT);
    pop(Lifail,Lresult,Ly,Lx);

    free (y);
    free (w);
    free (result);

    return Llist(nil,5,Lx,Ly,Lresult,Lifail,Ltol);
}
#else
{   return Llist(nil, 0);
}
#endif

LispObject Ld02bhf(LispObject env, int nargs, ...)
#if 0
{   va_list args;
    LispObject Lx, Lxend, Ln, Ly, Ltol, Lirelab, Lhmax, Lifail;
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,8,"Ld02bhf");
    va_start(args,nargs);
    Lxend = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lirelab = va_arg(args, LispObject);
    Lhmax = va_arg(args, LispObject);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Ltol = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    xend = float_of_number(Lxend);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    irelab = thirty_two_bits(Lirelab);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    hmax = float_of_number(Lhmax);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    y = (double *) malloc (n * sizeof(double));
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    mkFortranVectorDouble(y, Ly, n);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    tol = float_of_number(Ltol);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Ltol,Ly,Lx);
    pop(Lhmax,Lirelab,Ln,Lxend);
    push(Lxend,Ln,Lirelab,Lhmax);
    push(Lx,Ly,Ltol,Lifail);

    // Setup workspace arrays etc.
    w = (double *)malloc(n*7*sizeof(double));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfad01")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (d02bhf_proc = (PD02BHF) GetProcAddress (hLib, "_D02BHF@44"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*d02bhf_proc) (&x, &xend, &n, y, &tol, &irelab, &hmax, &asp7, &asp9,
                            w, &ifail);
        }
    }

    currlib = hLib;
#else
    D02BHF (&x, &xend, &n, y, &tol, &irelab, &hmax, &asp7, &asp9, w, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
    push(Lx);
    Ly = mkFloatVector(y,n,1);
    pop(Lx);
    push(Lx,Ly);
    Lifail = int2ccl(ifail);
    pop(Ly,Lx);
    push(Lx,Ly,Lifail);
    Ltol = make_boxfloat(tol,TYPE_DOUBLE_FLOAT);
    pop(Lifail,Ly,Lx);

    free (y);
    free (w);

    return Llist(nil,4,Lx,Ly,Lifail,Ltol);
}
#else
{   return Llist(nil, 0);
}
#endif

LispObject Ld02cjf(LispObject env, int nargs, ...)
#if 0
{   // FIXME: strings
    va_list args;
    LispObject Lx, Lxend, Lm, Ln, Ly, Ltol, Lrelabs, Lresult, Lifail;
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,8,"Ld02cjf");
    va_start(args,nargs);
    Lxend = va_arg(args, LispObject);
    Lm = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Ltol = va_arg(args, LispObject);
    Lrelabs = va_arg(args, LispObject);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
    xend = float_of_number(Lxend);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
    m = thirty_two_bits(Lm);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
    tol = float_of_number(Ltol);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
//  strncpy (srelabs, &celt(Lrelabs,0), 1);
    srelabs[0] = celt(Lrelabs,0);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);
    srelabs[1] = '\0';
    relabs.str = srelabs;
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);
    y = (double *) malloc (n * sizeof(double));
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
    mkFortranVectorDouble(y, Ly, n);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Ltol);
    push(Lrelabs,Lx,Ly,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Ly,Lx,Lrelabs);
    pop(Ltol,Ln,Lm,Lxend);

    relabs.len = 1;

    // Setup workspace arrays etc.
    w = (double *)malloc((28+21*n)*sizeof(double));
    result = (double *)malloc(m*n*sizeof(double));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   // FIXME - DLL name?
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (xd02cj_proc = (PXD02CJ) GetProcAddress (hLib, "_XD02CJ@56"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*xd02cj_proc) (&x, &xend, &m, &n, y, &asp7, &tol, relabs, result,
                            &asp8, &asp9, w, &ifail);
        }
    }

    currlib = hLib;
#else
    XD02CJ (&x, &xend, &m, &n, y, &asp7, &tol, relabs, result, &asp8, &asp9, w,
            &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
    push(Lx);
    Ly = mkFloatVector(y,n,1);
    pop(Lx);
    push(Lx,Ly);
    Lresult = mkFloatVector(result,m,n);  // FIXME: correct array ordering?
    pop(Ly,Lx);
    push(Lx,Ly,Lresult);
    Lifail = int2ccl(ifail);
    pop(Lresult,Ly,Lx);

    free (y);
    free (w);
    free (result);

    return Llist(nil,4,Lx,Ly,Lresult,Lifail);
}
#else
{   return Llist(nil, 0);
}
#endif

LispObject Ld02ejf(LispObject env, int nargs, ...)
#if 0
{   // FIXME: strings
    va_list args;
    LispObject Lx, Lxend, Lm, Ln, Ly, Ltol, Lrelabs, Lresult, Lifail, Liw;
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

    // Set up arguments as Lisp Objects
    argcheck(nargs,9,"Ld02ejf");
    va_start(args,nargs);
    Lxend = va_arg(args, LispObject);
    Lm = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lrelabs = va_arg(args, LispObject);
    Liw = va_arg(args, LispObject);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Ltol = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    xend = float_of_number(Lxend);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    m = thirty_two_bits(Lm);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
//  strncpy (srelabs, &celt(Lrelabs,0), 1);
    srelabs[0] = celt(Lrelabs,0);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    srelabs[1] = '\0';
    relabs.str = srelabs;
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    iw = thirty_two_bits(Liw);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    y = (double *) malloc (n * sizeof(double));
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    mkFortranVectorDouble(y, Ly, n);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    tol = float_of_number(Ltol);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Ltol,Ly,Lx,Liw);
    pop(Lrelabs,Ln,Lm,Lxend);
    push(Lxend,Lm,Ln,Lrelabs,Liw);
    push(Lx,Ly,Ltol,Lifail);

    relabs.len = 1;

    // Setup workspace arrays etc.
    w = (double *)malloc(iw*sizeof(double));
    result = (double *)malloc(m*n*sizeof(double));

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfadj")) == NULL )   // FIXME - DLL name?
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (xd02ej_proc = (PXD02EJ) GetProcAddress (hLib, "_XD02EJ@64"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*xd02ej_proc) (&x, &xend, &m, &n, y, &asp7, &asp31, &tol, relabs,
                            &asp8, &asp9, w, &iw, result, &ifail);
        }
    }

    currlib = hLib;
#else
    XD02EJ (&x, &xend, &m, &n, y, &asp7, &asp31, &tol, relabs, &asp8, &asp9, w,
            &iw, result, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lx = make_boxfloat(x,TYPE_DOUBLE_FLOAT);
    push(Lx);
    Ly = mkFloatVector(y,n,1);
    pop(Lx);
    push(Lx,Ly);
    Lresult = mkFloatVector(result,m,n);  // FIXME: correct array ordering?
    pop(Ly,Lx);
    push(Lx,Ly,Lresult);
    Lifail = int2ccl(ifail);
    pop(Lresult,Ly,Lx);
    push(Lx,Ly,Lresult,Lifail);
    Ltol = make_boxfloat(tol,TYPE_DOUBLE_FLOAT);
    pop(Lifail,Lresult,Ly,Lx);

    free (y);
    free (w);
    free (result);

    return Llist(nil,5,Lx,Ly,Lresult,Lifail,Ltol);
}
#else
{   return Llist(nil, 0);
}
#endif

// ******************* GOT TO HERE *********************

LispObject Ld02gaf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}

LispObject Ld02gbf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}

LispObject Ld02kef(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}

LispObject Ld02raf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}

LispObject Ld03edf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}

LispObject Ld03eef(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}

LispObject Ld03faf(LispObject env, int nargs, ...)
{   return Llist(nil, 0);
}

// end of nsg_d.cpp
