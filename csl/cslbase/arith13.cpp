// arith13.cpp                             Copyright (C) 2016-2021 Codemist

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
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lclog(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = clog(c);
    double rr = creal(r);
    double ri = cimag(r);
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcsqrt(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csqrt(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcsin(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csin(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccos(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ccos(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lctan(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ctan(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccsc(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function ccsc");
}

static LispObject Lcsec(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function csec");
}

static LispObject Lccot(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function ccot");
}

static LispObject Lcasin(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = casin(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacos(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cacos(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcatan(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = catan(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacsc(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function cacsc");
}

static LispObject Lcasec(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function casec");
}

static LispObject Lcacot(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function cacot");
}

static LispObject Lcsinh(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = csinh(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccosh(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ccosh(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lctanh(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = ctanh(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lccsch(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function ccsch");
}

static LispObject Lcsech(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function csech");
}

static LispObject Lccoth(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function ccoth");
}

static LispObject Lcasinh(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = casinh(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacosh(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = cacosh(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcatanh(LispObject env, LispObject a, LispObject b)
{   complex double c = float_of_number(a) + I*float_of_number(b);
    complex double r = catanh(c);
    double rr = creal(r);
    double ri = cimag(r);
    std::printf("A %.8f %.8f\r\n", float_of_number(a),
                float_of_number(b));
    std::printf("B %.8f %.8f\r\n", creal(c), cimag(c));
    std::printf("C %.8f %.8f\r\n", creal(r), cimag(r));
    a = make_boxfloat(rr, TYPE_DOUBLE_FLOAT);
    errexit();
    THREADID;
    Save save(THREADARG a);
    b = make_boxfloat(ri, TYPE_DOUBLE_FLOAT);
    errexit();
    save.restore(a);
    a = cons(a, b);
    return onevalue(a);
}

static LispObject Lcacsch(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function cacsch");
}

static LispObject Lcasech(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function casech");
}

static LispObject Lcacoth(LispObject env, LispObject a, LispObject b)
{   return aerror("pending function cacoth");
}



#else // HAVE_COMPLEX

static LispObject Lcarg(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function carg");
}

static LispObject Lcabs(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cabs");
}

static LispObject Lcexp(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cexp");
}

static LispObject Lclog(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function clog");
}

static LispObject Lcsqrt(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function csqrt");
}

static LispObject Lcsin(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function csin");
}

static LispObject Lccos(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ccos");
}

static LispObject Lctan(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ctan");
}

static LispObject Lccsc(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ccsc");
}

static LispObject Lcsec(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function csec");
}

static LispObject Lccot(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ccot");
}

static LispObject Lcasin(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function casin");
}

static LispObject Lcacos(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cacos");
}

static LispObject Lcatan(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function catan");
}

static LispObject Lcacsc(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cacsc");
}

static LispObject Lcasec(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function casec");
}

static LispObject Lcacot(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cacot");
}

static LispObject Lcsinh(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function csinh");
}

static LispObject Lccosh(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ccosh");
}

static LispObject Lctanh(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ctanh");
}

static LispObject Lccsch(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ccsch");
}

static LispObject Lcsech(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function csech");
}

static LispObject Lccoth(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function ccoth");
}

static LispObject Lcasinh(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function casinh");
}

static LispObject Lcacosh(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cacosh");
}

static LispObject Lcatanh(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function catanh");
}

static LispObject Lcacsch(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cacsch");
}

static LispObject Lcasech(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function casech");
}

static LispObject Lcacoth(LispObject env, LispObject a, LispObject b)
{   return aerror("unimplemented function cacoth");
}

#endif // HAVE_COMPLEX


setup_type const arith13_setup[] =
{   DEF_2("native-carg",    Lcarg),
    DEF_2("native-cabs",    Lcabs),
    DEF_2("native-cexp",    Lcexp),
    DEF_2("native-clog",    Lclog),
    DEF_2("native-csqrt",   Lcsqrt),
    DEF_2("native-csin",    Lcsin),
    DEF_2("native-ccos",    Lccos),
    DEF_2("native-ctan",    Lctan),
    DEF_2("native-ccsc",    Lccsc),
    DEF_2("native-csec",    Lcsec),
    DEF_2("native-ccot",    Lccot),
    DEF_2("native-casin",   Lcasin),
    DEF_2("native-cacos",   Lcacos),
    DEF_2("native-catan",   Lcatan),
    DEF_2("native-cacsc",   Lcacsc),
    DEF_2("native-casec",   Lcasec),
    DEF_2("native-cacot",   Lcacot),
    DEF_2("native-csinh",   Lcsinh),
    DEF_2("native-ccosh",   Lccosh),
    DEF_2("native-ctanh",   Lctanh),
    DEF_2("native-ccsch",   Lccsch),
    DEF_2("native-csech",   Lcsech),
    DEF_2("native-ccoth",   Lccoth),
    DEF_2("native-casinh",  Lcasinh),
    DEF_2("native-cacosh",  Lcacosh),
    DEF_2("native-catanh",  Lcatanh),
    DEF_2("native-cacsch",  Lcacsch),
    DEF_2("native-casech",  Lcasech),
    DEF_2("native-cacoth",  Lcacoth),
    {nullptr,               nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of arith13.cpp
