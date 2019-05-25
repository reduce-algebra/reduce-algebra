// arith-float.cpp                              Copyright (C) 2019 Codemist

// $Id$


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

#include "headers.h"
#include "dispatch.h"

using number_dispatcher::Fixnum;
// uint64_t *
using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
// double
using number_dispatcher::Flt;
using number_dispatcher::LFlt;

//========================================================================

double Float::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Float>("float", a);
}


double Float::op(Fixnum a)
{   return (double)a.intval();
}


double Float::op(uint64_t *a)
{   return arithlib_lowlevel::Float::op(a);
}

double Float::op(Rat a)
{   return Float::op(a.numerator()) / Float::op(a.denominator());
}

double Float::op(Cpx a)
{   aerror1("bad argument for float", a.value());
}

double Float::op(SFlt a)
{   return a.floatval();
}

double Float::op(Flt a)
{   return a.floatval();
}

double Float::op(double a)
{   return a;
}

double Float::op(LFlt a)
{   float64_t f = f128_to_f64(a.floatval());
// Ha ha - the jolly activity here is a response to the Strict Aliasing Rules
// that (I believe) allow me to feel safe if I move things treating it as
// byte data.
    double d;
    memcpy(&d, &f, sizeof(double));
    return d;
}

//========================================================================


float128_t Float128::op(LispObject a)
{   return number_dispatcher::unary<float128_t,Float128>("float128", a);
}


float128_t Float128::op(Fixnum a)
{   return i64_to_f128(a.intval());
}


float128_t Float128::op(uint64_t *a)
{   return arithlib_lowlevel::Float128::op(a);
}

float128_t Float128::op(Rat a)
{   return f128_div(Float128::op(a.numerator()), Float128::op(a.denominator()));
}

float128_t Float128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
}

float128_t Float128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t Float128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t Float128::op(double a)
{   double d = a;
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t Float128::op(LFlt a)
{   return a.floatval();
}

//========================================================================


LispObject Fix::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Fix>("fix", a);
}


LispObject Fix::op(Fixnum a)
{   return a.value();
}


LispObject Fix::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Fix::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Fix::op(Cpx a)
{   aerror1("bad argument for fix", a.value());
}

LispObject Fix::op(SFlt a)
{   return arithlib_lowlevel::double_to_bignum(a.floatval());
}

LispObject Fix::op(Flt a)
{   return arithlib_lowlevel::double_to_bignum(a.floatval());
}

LispObject Fix::op(double a)
{   return arithlib_lowlevel::double_to_bignum(a);
}

LispObject Fix::op(LFlt a)
{   return arithlib_lowlevel::float128_to_bignum(a.floatval());
}

//========================================================================

LispObject Floor::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Floor>("floor", a);
}


LispObject Floor::op(Fixnum a)
{   return a.value();
}


LispObject Floor::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Floor::op(Rat a)   // @@@
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Floor::op(Cpx a)
{   aerror1("bad argument for floor", a.value());
}

LispObject Floor::op(SFlt a)
{   return arithlib_lowlevel::double_to_floor(a.floatval());
}

LispObject Floor::op(Flt a)
{   return arithlib_lowlevel::double_to_floor(a.floatval());
}

LispObject Floor::op(double a)
{   return arithlib_lowlevel::double_to_floor(a);
}

LispObject Floor::op(LFlt a)
{   return arithlib_lowlevel::float128_to_floor(a.floatval());
}

//========================================================================

LispObject Ceiling::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ceiling>("ceiling", a);
}


LispObject Ceiling::op(Fixnum a)
{   return a.value();
}


LispObject Ceiling::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Ceiling::op(Rat a)   // @@@
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Ceiling::op(Cpx a)
{   aerror1("bad argument for ceiling", a.value());
}

LispObject Ceiling::op(SFlt a)
{   return arithlib_lowlevel::double_to_ceiling(a.floatval());
}

LispObject Ceiling::op(Flt a)
{   return arithlib_lowlevel::double_to_ceiling(a.floatval());
}

LispObject Ceiling::op(double a)
{   return arithlib_lowlevel::double_to_ceiling(a);
}

LispObject Ceiling::op(LFlt a)
{   return arithlib_lowlevel::float128_to_ceiling(a.floatval());
}

//========================================================================

LispObject Frexp::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Frexp>("frexp", a);
}


LispObject Frexp::op(Fixnum a)
{   aerror1("bad argument to frexp", a.value());
}


LispObject Frexp::op(uint64_t *a)
{   aerror1("bad argument to frexp", (LispObject)((char *)a - 8 + TAG_NUMBERS));
}

LispObject Frexp::op(Rat a)
{   aerror1("bad argument for frexp", a.value());
}

LispObject Frexp::op(Cpx a)
{   aerror1("bad argument for frexp", a.value());
}

LispObject Frexp::op(SFlt a)
{   int x;
    double d = std::frexp(a.floatval(), &x);
    return cons(pack_short_float(d), fixnum_of_int(x));
}

LispObject Frexp::op(Flt a)
{   int x;
    double d = std::frexp(a.floatval(), &x);
    return cons(pack_single_float(d), fixnum_of_int(x));
}

LispObject Frexp::op(double a)
{   int x;
    double d = std::frexp(a, &x);
    return cons(make_boxfloat(d, TYPE_DOUBLE_FLOAT), fixnum_of_int(x));
}

LispObject Frexp::op(LFlt a)
{   int x;
    float128_t d = a.floatval();
    f128M_frexp(&d, &d, &x);
    return cons(make_boxfloat128(d), fixnum_of_int(x));
}

//========================================================================

LispObject Ldexp::op(LispObject a, LispObject b)
{   return number_dispatcher::shiftlike<LispObject,Ldexp>("ldexp", a, b);
}


LispObject Ldexp::op(Fixnum a, int b)
{   double d = std::ldexp((double)a.intval(), b);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}


LispObject Ldexp::op(uint64_t *a, int b)
{   double d = std::ldexp(Float::op(a), b);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

LispObject Ldexp::op(Rat a, int b)
{   double d = std::ldexp(Float::op(a), b);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

LispObject Ldexp::op(Cpx a, int b)
{   aerror1("bad argument for ldexp", a.value());
}

LispObject Ldexp::op(SFlt a, int b)
{   double d = std::ldexp(a.floatval(), b);
    return pack_short_float(d);
}

LispObject Ldexp::op(Flt a, int b)
{   double d = std::ldexp(a.floatval(), b);
    return pack_single_float(d);
}

LispObject Ldexp::op(double a, int b)
{   double d = std::ldexp(a, b);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

LispObject Ldexp::op(LFlt a, int b)
{   float128_t f = a.floatval();
    f128M_ldexp(&f, b);
    return make_boxfloat128(f);
}


// end of arith-float.cpp

