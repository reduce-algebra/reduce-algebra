/*  arith13.c                         Copyright (C) 2015-2015 Codemist Ltd */

/*
 * Complex elementary functions using the C99 support for same, but with
 * a rather ugly interface.
 *
 * These are provided via ugly names like native-csin because I will want
 * to have my own implementations as the main ones to be used - mainly so
 * that I can ensure that I deliver identical results on all platforms,
 * and also so that I can leverage the perfect accuracy of crlibm when
 * possible. So these are intended to be used just so that the results from
 * the native C library here can be compared against output from my own
 * code as part of the testing.
 */


/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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


/* $Id: arith13.c 2277 2014-01-06 10:33:50Z arthurcnorman $ */


#include "headers.h"

#ifdef HAVE_COMPLEX

#include <complex.h>


static Lisp_Object Lcarg(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    double r = carg(c);
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcabs(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    double r = cabs(c);
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcexp(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cexp(c);
    double rr = creal(r);
    double ri = cimag(r);
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lclog(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = clog(c);
    double rr = creal(r);
    double ri = cimag(r);
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcsqrt(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csqrt(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcsin(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csin(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lccos(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ccos(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lctan(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ctan(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lccsc(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function ccsc");
}

static Lisp_Object Lcsec(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function csec");
}

static Lisp_Object Lccot(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function ccot");
}

static Lisp_Object Lcasin(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = casin(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcacos(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cacos(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcatan(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = catan(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcacsc(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function cacsc");
}

static Lisp_Object Lcasec(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function casec");
}

static Lisp_Object Lcacot(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function cacot");
}

static Lisp_Object Lcsinh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csinh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lccosh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ccosh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lctanh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ctanh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lccsch(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function ccsch");
}

static Lisp_Object Lcsech(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function csech");
}

static Lisp_Object Lccoth(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function ccoth");
}

static Lisp_Object Lcasinh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = casinh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcacosh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cacosh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcatanh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = catanh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    errexit();
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcacsch(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function cacsch");
}

static Lisp_Object Lcasech(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function casech");
}

static Lisp_Object Lcacoth(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("pending function cacoth");
}



#else /* HAVE_COMPLEX */

static Lisp_Object Lcarg(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function carg");
}

static Lisp_Object Lcabs(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cabs");
}

static Lisp_Object Lcexp(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cexp");
}

static Lisp_Object Lclog(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function clog");
}

static Lisp_Object Lcsqrt(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function csqrt");
}

static Lisp_Object Lcsin(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function csin");
}

static Lisp_Object Lccos(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ccos");
}

static Lisp_Object Lctan(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ctan");
}

static Lisp_Object Lccsc(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ccsc");
}

static Lisp_Object Lcsec(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function csec");
}

static Lisp_Object Lccot(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ccot");
}

static Lisp_Object Lcasin(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function casin");
}

static Lisp_Object Lcacos(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cacos");
}

static Lisp_Object Lcatan(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function catan");
}

static Lisp_Object Lcacsc(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cacsc");
}

static Lisp_Object Lcasec(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function casec");
}

static Lisp_Object Lcacot(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cacot");
}

static Lisp_Object Lcsinh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function csinh");
}

static Lisp_Object Lccosh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ccosh");
}

static Lisp_Object Lctanh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ctanh");
}

static Lisp_Object Lccsch(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ccsch");
}

static Lisp_Object Lcsech(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function csech");
}

static Lisp_Object Lccoth(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function ccoth");
}

static Lisp_Object Lcasinh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function casinh");
}

static Lisp_Object Lcacosh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cacosh");
}

static Lisp_Object Lcatanh(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function catanh");
}

static Lisp_Object Lcacsch(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cacsch");
}

static Lisp_Object Lcasech(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function casech");
}

static Lisp_Object Lcacoth(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return aerror("unimplemented function cacoth");
}

#endif /* HAVE_COMPLEX */


setup_type const arith13_setup[] =
{
    {"native-carg",             too_few_2, Lcarg, wrong_no_2},
    {"native-cabs",             too_few_2, Lcabs, wrong_no_2},
    {"native-cexp",             too_few_2, Lcexp, wrong_no_2},
    {"native-clog",             too_few_2, Lclog, wrong_no_2},
    {"native-csqrt",            too_few_2, Lcsqrt, wrong_no_2},
    {"native-csin",             too_few_2, Lcsin, wrong_no_2},
    {"native-ccos",             too_few_2, Lccos, wrong_no_2},
    {"native-ctan",             too_few_2, Lctan, wrong_no_2},
    {"native-ccsc",             too_few_2, Lccsc, wrong_no_2},
    {"native-csec",             too_few_2, Lcsec, wrong_no_2},
    {"native-ccot",             too_few_2, Lccot, wrong_no_2},
    {"native-casin",            too_few_2, Lcasin, wrong_no_2},
    {"native-cacos",            too_few_2, Lcacos, wrong_no_2},
    {"native-catan",            too_few_2, Lcatan, wrong_no_2},
    {"native-cacsc",            too_few_2, Lcacsc, wrong_no_2},
    {"native-casec",            too_few_2, Lcasec, wrong_no_2},
    {"native-cacot",            too_few_2, Lcacot, wrong_no_2},
    {"native-csinh",            too_few_2, Lcsinh, wrong_no_2},
    {"native-ccosh",            too_few_2, Lccosh, wrong_no_2},
    {"native-ctanh",            too_few_2, Lctanh, wrong_no_2},
    {"native-ccsch",            too_few_2, Lccsch, wrong_no_2},
    {"native-csech",            too_few_2, Lcsech, wrong_no_2},
    {"native-ccoth",            too_few_2, Lccoth, wrong_no_2},
    {"native-casinh",           too_few_2, Lcasinh, wrong_no_2},
    {"native-cacosh",           too_few_2, Lcacosh, wrong_no_2},
    {"native-catanh",           too_few_2, Lcatanh, wrong_no_2},
    {"native-cacsch",           too_few_2, Lcacsch, wrong_no_2},
    {"native-casech",           too_few_2, Lcasech, wrong_no_2},
    {"native-cacoth",           too_few_2, Lcacoth, wrong_no_2},
    {NULL,                      0, 0, 0}
};

/* end of arith13.c */
