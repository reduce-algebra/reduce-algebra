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


static LispObject Lcarg(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    double r = carg(c);
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    return onevalue(a);
}

static LispObject Lcabs(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    double r = cabs(c);
    a = make_boxfloat(r, TYPE_DOUBLE_FLOAT);
    return onevalue(a);
}

static LispObject Lcexp(LispObject env, LispObject a, LispObject b)
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

static LispObject Lclog(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcsqrt(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcsin(LispObject env, LispObject a, LispObject b)
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

static LispObject Lccos(LispObject env, LispObject a, LispObject b)
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

static LispObject Lctan(LispObject env, LispObject a, LispObject b)
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

static LispObject Lccsc(LispObject env, LispObject a, LispObject b)
{   aerror("pending function ccsc");
}

static LispObject Lcsec(LispObject env, LispObject a, LispObject b)
{   aerror("pending function csec");
}

static LispObject Lccot(LispObject env, LispObject a, LispObject b)
{   aerror("pending function ccot");
}

static LispObject Lcasin(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcacos(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcatan(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcacsc(LispObject env, LispObject a, LispObject b)
{   aerror("pending function cacsc");
}

static LispObject Lcasec(LispObject env, LispObject a, LispObject b)
{   aerror("pending function casec");
}

static LispObject Lcacot(LispObject env, LispObject a, LispObject b)
{   aerror("pending function cacot");
}

static LispObject Lcsinh(LispObject env, LispObject a, LispObject b)
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

static LispObject Lccosh(LispObject env, LispObject a, LispObject b)
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

static LispObject Lctanh(LispObject env, LispObject a, LispObject b)
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

static LispObject Lccsch(LispObject env, LispObject a, LispObject b)
{   aerror("pending function ccsch");
}

static LispObject Lcsech(LispObject env, LispObject a, LispObject b)
{   aerror("pending function csech");
}

static LispObject Lccoth(LispObject env, LispObject a, LispObject b)
{   aerror("pending function ccoth");
}

static LispObject Lcasinh(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcacosh(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcatanh(LispObject env, LispObject a, LispObject b)
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

static LispObject Lcacsch(LispObject env, LispObject a, LispObject b)
{   aerror("pending function cacsch");
}

static LispObject Lcasech(LispObject env, LispObject a, LispObject b)
{   aerror("pending function casech");
}

static LispObject Lcacoth(LispObject env, LispObject a, LispObject b)
{   aerror("pending function cacoth");
}



#else // HAVE_COMPLEX

static LispObject Lcarg(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function carg");
}

static LispObject Lcabs(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cabs");
}

static LispObject Lcexp(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cexp");
}

static LispObject Lclog(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function clog");
}

static LispObject Lcsqrt(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function csqrt");
}

static LispObject Lcsin(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function csin");
}

static LispObject Lccos(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ccos");
}

static LispObject Lctan(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ctan");
}

static LispObject Lccsc(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ccsc");
}

static LispObject Lcsec(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function csec");
}

static LispObject Lccot(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ccot");
}

static LispObject Lcasin(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function casin");
}

static LispObject Lcacos(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cacos");
}

static LispObject Lcatan(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function catan");
}

static LispObject Lcacsc(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cacsc");
}

static LispObject Lcasec(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function casec");
}

static LispObject Lcacot(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cacot");
}

static LispObject Lcsinh(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function csinh");
}

static LispObject Lccosh(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ccosh");
}

static LispObject Lctanh(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ctanh");
}

static LispObject Lccsch(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ccsch");
}

static LispObject Lcsech(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function csech");
}

static LispObject Lccoth(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function ccoth");
}

static LispObject Lcasinh(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function casinh");
}

static LispObject Lcacosh(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cacosh");
}

static LispObject Lcatanh(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function catanh");
}

static LispObject Lcacsch(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cacsch");
}

static LispObject Lcasech(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function casech");
}

static LispObject Lcacoth(LispObject env, LispObject a, LispObject b)
{   aerror("unimplemented function cacoth");
}

#endif // HAVE_COMPLEX


setup_type const arith13_setup[] =
{   {"native-carg",             G0W2, G1W2, Lcarg, G3W2, G4W2},
    {"native-cabs",             G0W2, G1W2, Lcabs, G3W2, G4W2},
    {"native-cexp",             G0W2, G1W2, Lcexp, G3W2, G4W2},
    {"native-clog",             G0W2, G1W2, Lclog, G3W2, G4W2},
    {"native-csqrt",            G0W2, G1W2, Lcsqrt, G3W2, G4W2},
    {"native-csin",             G0W2, G1W2, Lcsin, G3W2, G4W2},
    {"native-ccos",             G0W2, G1W2, Lccos, G3W2, G4W2},
    {"native-ctan",             G0W2, G1W2, Lctan, G3W2, G4W2},
    {"native-ccsc",             G0W2, G1W2, Lccsc, G3W2, G4W2},
    {"native-csec",             G0W2, G1W2, Lcsec, G3W2, G4W2},
    {"native-ccot",             G0W2, G1W2, Lccot, G3W2, G4W2},
    {"native-casin",            G0W2, G1W2, Lcasin, G3W2, G4W2},
    {"native-cacos",            G0W2, G1W2, Lcacos, G3W2, G4W2},
    {"native-catan",            G0W2, G1W2, Lcatan, G3W2, G4W2},
    {"native-cacsc",            G0W2, G1W2, Lcacsc, G3W2, G4W2},
    {"native-casec",            G0W2, G1W2, Lcasec, G3W2, G4W2},
    {"native-cacot",            G0W2, G1W2, Lcacot, G3W2, G4W2},
    {"native-csinh",            G0W2, G1W2, Lcsinh, G3W2, G4W2},
    {"native-ccosh",            G0W2, G1W2, Lccosh, G3W2, G4W2},
    {"native-ctanh",            G0W2, G1W2, Lctanh, G3W2, G4W2},
    {"native-ccsch",            G0W2, G1W2, Lccsch, G3W2, G4W2},
    {"native-csech",            G0W2, G1W2, Lcsech, G3W2, G4W2},
    {"native-ccoth",            G0W2, G1W2, Lccoth, G3W2, G4W2},
    {"native-casinh",           G0W2, G1W2, Lcasinh, G3W2, G4W2},
    {"native-cacosh",           G0W2, G1W2, Lcacosh, G3W2, G4W2},
    {"native-catanh",           G0W2, G1W2, Lcatanh, G3W2, G4W2},
    {"native-cacsch",           G0W2, G1W2, Lcacsch, G3W2, G4W2},
    {"native-casech",           G0W2, G1W2, Lcasech, G3W2, G4W2},
    {"native-cacoth",           G0W2, G1W2, Lcacoth, G3W2, G4W2},
    {NULL,                      0, 0, 0}
};

// end of arith13.cpp
