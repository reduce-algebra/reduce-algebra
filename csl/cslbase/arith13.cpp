// arith13.cpp                             Copyright (C) 2016-2017 Codemist    

//
// Complex elementary functions using the C99 support for same, but with
// a rather ugly interface.
//
// These are provided via ugly names like native-csin because I will want
// to have my own implementations as the main ones to be used - mainly so
// that I can ensure that I deliver identical results on all platforms,
// and also so that I can leverage the perfect accuracy of crlibm when
// possible. So these are intended to be used just so that the results from
// the native C library here can be compared against output from my own
// code as part of the testing.
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
 *************************************************************************/


// $Id$


#include "headers.h"

#ifdef HAVE_COMPLEX

#include <complex.h>


static LispObject Lcarg(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    double r = carg(c);
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    return onevalue(a);
}

static LispObject Lcabs(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    double r = cabs(c);
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    return onevalue(a);
}

static LispObject Lcexp(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cexp(c);
    double rr = creal(r);
    double ri = cimag(r);
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lclog(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = clog(c);
    double rr = creal(r);
    double ri = cimag(r);
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcsqrt(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csqrt(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcsin(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csin(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccos(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ccos(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lctan(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ctan(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccsc(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function ccsc");
}

static LispObject Lcsec(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function csec");
}

static LispObject Lccot(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function ccot");
}

static LispObject Lcasin(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = casin(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacos(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cacos(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcatan(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = catan(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacsc(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function cacsc");
}

static LispObject Lcasec(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function casec");
}

static LispObject Lcacot(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function cacot");
}

static LispObject Lcsinh(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csinh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccosh(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ccosh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lctanh(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ctanh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccsch(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function ccsch");
}

static LispObject Lcsech(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function csech");
}

static LispObject Lccoth(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function ccoth");
}

static LispObject Lcasinh(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = casinh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacosh(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cacosh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcatanh(LispObject nil, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = catanh(c);
    double rr = creal(r);
    double ri = cimag(r);
    printf("A %.8f %.8f\r\n", float_of_number(a), float_of_number(b));
    printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    push(a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    pop(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacsch(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function cacsch");
}

static LispObject Lcasech(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function casech");
}

static LispObject Lcacoth(LispObject nil, LispObject a, LispObject b)
{   aerror("pending function cacoth");
}



#else // HAVE_COMPLEX

static LispObject Lcarg(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function carg");
}

static LispObject Lcabs(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cabs");
}

static LispObject Lcexp(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cexp");
}

static LispObject Lclog(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function clog");
}

static LispObject Lcsqrt(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function csqrt");
}

static LispObject Lcsin(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function csin");
}

static LispObject Lccos(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ccos");
}

static LispObject Lctan(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ctan");
}

static LispObject Lccsc(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ccsc");
}

static LispObject Lcsec(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function csec");
}

static LispObject Lccot(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ccot");
}

static LispObject Lcasin(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function casin");
}

static LispObject Lcacos(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cacos");
}

static LispObject Lcatan(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function catan");
}

static LispObject Lcacsc(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cacsc");
}

static LispObject Lcasec(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function casec");
}

static LispObject Lcacot(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cacot");
}

static LispObject Lcsinh(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function csinh");
}

static LispObject Lccosh(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ccosh");
}

static LispObject Lctanh(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ctanh");
}

static LispObject Lccsch(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ccsch");
}

static LispObject Lcsech(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function csech");
}

static LispObject Lccoth(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function ccoth");
}

static LispObject Lcasinh(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function casinh");
}

static LispObject Lcacosh(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cacosh");
}

static LispObject Lcatanh(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function catanh");
}

static LispObject Lcacsch(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cacsch");
}

static LispObject Lcasech(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function casech");
}

static LispObject Lcacoth(LispObject nil, LispObject a, LispObject b)
{   aerror("unimplemented function cacoth");
}

#endif // HAVE_COMPLEX


setup_type const arith13_setup[] =
{   {"native-carg",             TOO_FEW_2, Lcarg, WRONG_NO_2},
    {"native-cabs",             TOO_FEW_2, Lcabs, WRONG_NO_2},
    {"native-cexp",             TOO_FEW_2, Lcexp, WRONG_NO_2},
    {"native-clog",             TOO_FEW_2, Lclog, WRONG_NO_2},
    {"native-csqrt",            TOO_FEW_2, Lcsqrt, WRONG_NO_2},
    {"native-csin",             TOO_FEW_2, Lcsin, WRONG_NO_2},
    {"native-ccos",             TOO_FEW_2, Lccos, WRONG_NO_2},
    {"native-ctan",             TOO_FEW_2, Lctan, WRONG_NO_2},
    {"native-ccsc",             TOO_FEW_2, Lccsc, WRONG_NO_2},
    {"native-csec",             TOO_FEW_2, Lcsec, WRONG_NO_2},
    {"native-ccot",             TOO_FEW_2, Lccot, WRONG_NO_2},
    {"native-casin",            TOO_FEW_2, Lcasin, WRONG_NO_2},
    {"native-cacos",            TOO_FEW_2, Lcacos, WRONG_NO_2},
    {"native-catan",            TOO_FEW_2, Lcatan, WRONG_NO_2},
    {"native-cacsc",            TOO_FEW_2, Lcacsc, WRONG_NO_2},
    {"native-casec",            TOO_FEW_2, Lcasec, WRONG_NO_2},
    {"native-cacot",            TOO_FEW_2, Lcacot, WRONG_NO_2},
    {"native-csinh",            TOO_FEW_2, Lcsinh, WRONG_NO_2},
    {"native-ccosh",            TOO_FEW_2, Lccosh, WRONG_NO_2},
    {"native-ctanh",            TOO_FEW_2, Lctanh, WRONG_NO_2},
    {"native-ccsch",            TOO_FEW_2, Lccsch, WRONG_NO_2},
    {"native-csech",            TOO_FEW_2, Lcsech, WRONG_NO_2},
    {"native-ccoth",            TOO_FEW_2, Lccoth, WRONG_NO_2},
    {"native-casinh",           TOO_FEW_2, Lcasinh, WRONG_NO_2},
    {"native-cacosh",           TOO_FEW_2, Lcacosh, WRONG_NO_2},
    {"native-catanh",           TOO_FEW_2, Lcatanh, WRONG_NO_2},
    {"native-cacsch",           TOO_FEW_2, Lcacsch, WRONG_NO_2},
    {"native-casech",           TOO_FEW_2, Lcasech, WRONG_NO_2},
    {"native-cacoth",           TOO_FEW_2, Lcacoth, WRONG_NO_2},
    {NULL,                      0, 0, 0}
};

// end of arith13.cpp
