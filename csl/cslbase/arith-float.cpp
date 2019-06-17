// arith-float.cpp                              Copyright (C) 2019 Codemist

#ifdef ARITHLIB

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

LispObject Float::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Float>("float", a);
}

// A mere cast to double here would not guarantee the rounding mode in
// cases that the integer was longer than 52 bits.
LispObject Float::op(Fixnum a)
{   return make_boxfloat(arithlib_lowlevel::Double::op(a.intval()));
}

// In this next one note thar arithlib has a class Float that converts
// to a C++ float and a separate one called Double that converts to a
// C++ double and hence is what I need here!
LispObject Float::op(uint64_t *a)
{   return make_boxfloat(arithlib_lowlevel::Double::op(a));
}

#pragma message ("conversion from ratio to float not done yet")
LispObject Float::op(Rat a)
{   aerror("float of rat not coded yet");
//    return Float::op(a.numerator()) / Float::op(a.denominator());
}

LispObject Float::op(Cpx a)
{   aerror1("bad argument for float", a.value());
}

LispObject Float::op(SFlt a)
{   return make_boxfloat(a.floatval());
}

LispObject Float::op(Flt a)
{   return make_boxfloat(a.floatval());
}

LispObject Float::op(double a)
{   return make_boxfloat(a);
}

LispObject Float::op(LFlt a)
{   float64_t f = f128_to_f64(a.floatval());
// Ha ha - the jolly activity here is a response to the Strict Aliasing Rules
// that (I believe) allow me to feel safe if I move things treating it as
// byte data.
    double d;
    memcpy(&d, &f, sizeof(double));
    return make_boxfloat(d);
}

LispObject Float128::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Float128>("float128", a);
}

LispObject Float128::op(Fixnum a)
{   return make_boxfloat128(i64_to_f128(a.intval()));
}

LispObject Float128::op(uint64_t *a)
{   return make_boxfloat128(arithlib_lowlevel::Float128::op(a));
}

LispObject Float128::op(Rat a)
{   aerror("floating a rat not implemented yet");
//return f128_div(Float128::op(a.numerator()), Float128::op(a.denominator()));
}

LispObject Float128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
}

LispObject Float128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(double a)
{   double d = a;
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(LFlt a)
{   return a.value();
}

// In Common Lisp the 1-argument version of FLOAT converts to a
// single precisoin float and if the second argument of the 2-argument
// version is unhelpful it does the same. I view that as old fashioned
// and ridiculous and make double the default. If at any stage strict
// Common Lisp compatibility was required and it was essential to continue
// to support short and single floats the changes here might be extensive
// but would not be difficulty. Except that when I convert to a short or
// single float I often do so by first creating a (double) float and then
// narrowing. If the conversion to the double round up (say) in such a way
// then the subsequent narrowing operation then only rounds up because of
// the exact value generated then overall the rounding up was incorrect.
// This case is not common but it is straightforward to construct an
// example. Since few people (any people?) will use the narrower CSL floats
// and even fewer will then worry about that level of correctness I propose
// to ignore the issue. There will in fact be plenty of other places where
// floating point support fails strict challenges to be as perfect as one
// might imagine - both in terms of correct vs incorrect rounding and in
// instances where premature overflow can arise.              ACN June 2019

LispObject Float::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a, b);
}

// fixnum FLOAT fixnum

LispObject Float::op(Fixnum a, Fixnum b)
{   return Float::op(a);
}

// bignum FLOAT fixnum
LispObject Float::op(uint64_t *a, Fixnum b)
{   return Float::op(a);
}

// rational FLOAT fixnum
LispObject Float::op(Rat a, Fixnum b)
{   return Float::op(a);
}

// complex FLOAT fixnum
LispObject Float::op(Cpx a, Fixnum b)
{   return Float::op(a);
}

// short float FLOAT fixnum
LispObject Float::op(SFlt a, Fixnum b)
{   return Float::op(a);
}

// single float FLOAT fixnum
LispObject Float::op(Flt a, Fixnum b)
{   return Float::op(a);
}

// double float FLOAT fixnum
LispObject Float::op(double a, Fixnum b)
{   return Float::op(a);
}

// long float FLOAT fixnum
LispObject Float::op(LFlt a, Fixnum b)
{   return Float::op(a);
}

// fixnum FLOAT bignum
LispObject Float::op(Fixnum a, uint64_t *b)
{   return Float::op(a);
}

// bignum FLOAT bignum
LispObject Float::op(uint64_t *a, uint64_t *b)
{   return Float::op(a);
}

// rational FLOAT bignum
LispObject Float::op(Rat a, uint64_t *b)
{   return Float::op(a);
}

// complex FLOAT bignum
LispObject Float::op(Cpx a, uint64_t *b)
{   return Float::op(a);
}

// short float FLOAT bignum
LispObject Float::op(SFlt a, uint64_t *b)
{   return Float::op(a);
}

// single float FLOAT bignum
LispObject Float::op(Flt a, uint64_t *b)
{   return Float::op(a);
}

// double float FLOAT bignum
LispObject Float::op(double a, uint64_t *b)
{   return Float::op(a);
}

// long float FLOAT bignum
LispObject Float::op(LFlt a, uint64_t *b)
{   return Float::op(a);
}

// fixnum FLOAT rational
LispObject Float::op(Fixnum a, Rat b)
{   return Float::op(a);
}

// bignum FLOAT rational
LispObject Float::op(uint64_t *a, Rat b)
{   return Float::op(a);
}

// rational FLOAT rational
LispObject Float::op(Rat a, Rat b)
{   return Float::op(a);
}

// complex FLOAT rational
LispObject Float::op(Cpx a, Rat b)
{   return Float::op(a);
}

// short float FLOAT rational
LispObject Float::op(SFlt a, Rat b)
{   return Float::op(a);
}

// single float FLOAT rational
LispObject Float::op(Flt a, Rat b)
{   return Float::op(a);
}

// double float FLOAT rational
LispObject Float::op(double a, Rat b)
{   return Float::op(a);
}

// long float FLOAT rational
LispObject Float::op(LFlt a, Rat b)
{   return Float::op(a);
}

// fixnum FLOAT complex
LispObject Float::op(Fixnum a, Cpx b)
{   return Float::op(a);
}

// bignum FLOAT complex
LispObject Float::op(uint64_t *a, Cpx b)
{   return Float::op(a);
}

// rational FLOAT complex
LispObject Float::op(Rat a, Cpx b)
{   return Float::op(a);
}

// complex FLOAT complex
LispObject Float::op(Cpx a, Cpx b)
{   return Float::op(a);
}

// short float FLOAT complex
LispObject Float::op(SFlt a, Cpx b)
{   return Float::op(a);
}

// single float FLOAT complex
LispObject Float::op(Flt a, Cpx b)
{   return Float::op(a);
}

// double float FLOAT complex
LispObject Float::op(double a, Cpx b)
{   return Float::op(a);
}

// long float FLOAT complex
LispObject Float::op(LFlt a, Cpx b)
{   return Float::op(a);
}

// fixnum FLOAT short float
// The implementation gere relies on the result if Float::op(a) being
// a double float.
LispObject Float::op(Fixnum a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// bignum FLOAT short float
LispObject Float::op(uint64_t *a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// rational FLOAT short float
LispObject Float::op(Rat a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// complex FLOAT short float
LispObject Float::op(Cpx a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// short float FLOAT short float
LispObject Float::op(SFlt a, SFlt b)
{   return a.value();
}

// single float FLOAT short float
LispObject Float::op(Flt a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// double float FLOAT short float
LispObject Float::op(double a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// long float FLOAT short float
LispObject Float::op(LFlt a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// fixnum FLOAT single float
LispObject Float::op(Fixnum a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// bignum FLOAT single float
LispObject Float::op(uint64_t *a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// rational FLOAT single float
LispObject Float::op(Rat a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// complex FLOAT single float
LispObject Float::op(Cpx a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// short float FLOAT single float
LispObject Float::op(SFlt a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// single float FLOAT single float
LispObject Float::op(Flt a, Flt b)
{   return a.value();
}

// double float FLOAT single float
LispObject Float::op(double a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// long float FLOAT single float
LispObject Float::op(LFlt a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// fixnum FLOAT double float
LispObject Float::op(Fixnum a, double b)
{   return Float::op(a);
}

// bignum FLOAT double float
LispObject Float::op(uint64_t *a, double b)
{   return Float::op(a);
}

// rational FLOAT double float
LispObject Float::op(Rat a, double b)
{   return Float::op(a);
}

// complex FLOAT double float
LispObject Float::op(Cpx a, double b)
{   return Float::op(a);
}

// short float FLOAT double float
LispObject Float::op(SFlt a, double b)
{   return Float::op(a);
}

// single float FLOAT double float
LispObject Float::op(Flt a, double b)
{   return Float::op(a);
}

// double float FLOAT double float
LispObject Float::op(double a, double b)
{   return make_boxfloat(a);
}

// long float FLOAT double float
LispObject Float::op(LFlt a, double b)
{   return Float::op(a);
}

// fixnum FLOAT long float
LispObject Float::op(Fixnum a, LFlt b)
{   return Float128::op(a);
}

// bignum FLOAT long float
LispObject Float::op(uint64_t *a, LFlt b)
{   return Float128::op(a);
}

// rational FLOAT long float
LispObject Float::op(Rat a, LFlt b)
{   return Float128::op(a);
}

// complex FLOAT long float
LispObject Float::op(Cpx a, LFlt b)
{   return Float128::op(a);
}

// short float FLOAT long float
LispObject Float::op(SFlt a, LFlt b)
{   return Float128::op(a);
}

// single float FLOAT long float
LispObject Float::op(Flt a, LFlt b)
{   return Float128::op(a);
}

// double float FLOAT long float
LispObject Float::op(double a, LFlt b)
{   return Float128::op(a);
}

// long float FLOAT long float
LispObject Float::op(LFlt a, LFlt b)
{   return make_boxfloat128(a.floatval());
}

double RawFloat::op(LispObject a)
{   return number_dispatcher::unary<double,RawFloat>("float", a);
}

double RawFloat::op(Fixnum a)
{   return arithlib_lowlevel::Double::op(a.intval());
}

double RawFloat::op(uint64_t *a)
{   return arithlib_lowlevel::Double::op(a);
}

double RawFloat::op(Rat a)
{   int64_t px, qx;
    double p = number_dispatcher::unary<double,Frexp>("frexp", a.numerator(), px);
    double q = number_dispatcher::unary<double,Frexp>("frexp", a.denominator(), qx);
    return std::ldexp(p/q, px-qx);
}

double RawFloat::op(Cpx a)
{   aerror1("bad argument for float", a.value());
}

double RawFloat::op(SFlt a)
{   return a.floatval();
}

double RawFloat::op(Flt a)
{   return a.floatval();
}

double RawFloat::op(double a)
{   return a;
}

double RawFloat::op(LFlt a)
{   float64_t f = f128_to_f64(a.floatval());
// Ha ha - the jolly activity here is a response to the Strict Aliasing Rules
// that (I believe) allow me to feel safe if I move things treating it as
// byte data.
    double d;
    memcpy(&d, &f, sizeof(double));
    return d;
}

float128_t RawFloat128::op(LispObject a)
{   return number_dispatcher::unary<float128_t,RawFloat128>("float128", a);
}

float128_t RawFloat128::op(Fixnum a)
{   return i64_to_f128(a.intval());
}

float128_t RawFloat128::op(uint64_t *a)
{   return arithlib_lowlevel::Float128::op(a);
}

float128_t RawFloat128::op(Rat a)
{   int64_t px, qx;
    float128_t p = Frexp128::op(a.numerator(), px);
    float128_t q = Frexp128::op(a.denominator(), qx);
    float128_t d = f128_div(p, q);
    f128M_ldexp(&d, px-qx);
    return d;
}

float128_t RawFloat128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
}

float128_t RawFloat128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(double a)
{   double d = a;
    float64_t dd;
    memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(LFlt a)
{   return a.floatval();
}

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
{   return arithlib_lowlevel::trunc_double_to_int(a.floatval());
}

LispObject Fix::op(Flt a)
{   return arithlib_lowlevel::trunc_double_to_int(a.floatval());
}

LispObject Fix::op(double a)
{   return arithlib_lowlevel::trunc_double_to_int(a);
}

LispObject Fix::op(LFlt a)
{   return arithlib_lowlevel::trunc_float128_to_int(a.floatval());
}

LispObject Truncate::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Truncate>("floor", a);
}

LispObject Truncate::op(Fixnum a)
{   return a.value();
}

LispObject Truncate::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Truncate::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Truncate(Rat)")
}

LispObject Truncate::op(Cpx a)
{   aerror1("bad argument for trunc", a.value());
}

LispObject Truncate::op(SFlt a)
{   return arithlib_lowlevel::trunc_double_to_int(a.floatval());
}

LispObject Truncate::op(Flt a)
{   return arithlib_lowlevel::trunc_double_to_int(a.floatval());
}

LispObject Truncate::op(double a)
{   return arithlib_lowlevel::trunc_double_to_int(a);
}

LispObject Truncate::op(LFlt a)
{   return arithlib_lowlevel::trunc_float128_to_int(a.floatval());
}

LispObject Floor::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Floor>("floor", a);
}

LispObject Floor::op(Fixnum a)
{   return a.value();
}

LispObject Floor::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Floor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Floor(Rat)")
}

LispObject Floor::op(Cpx a)
{   aerror1("bad argument for floor", a.value());
}

LispObject Floor::op(SFlt a)
{   return arithlib_lowlevel::floor_double_to_int(a.floatval());
}

LispObject Floor::op(Flt a)
{   return arithlib_lowlevel::floor_double_to_int(a.floatval());
}

LispObject Floor::op(double a)
{   return arithlib_lowlevel::floor_double_to_int(a);
}

LispObject Floor::op(LFlt a)
{   return arithlib_lowlevel::floor_float128_to_int(a.floatval());
}

LispObject Ceiling::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ceiling>("ceiling", a);
}

LispObject Ceiling::op(Fixnum a)
{   return a.value();
}

LispObject Ceiling::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Ceiling::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ceiling(Rat)")
}

LispObject Ceiling::op(Cpx a)
{   aerror1("bad argument for ceiling", a.value());
}

LispObject Ceiling::op(SFlt a)
{   return arithlib_lowlevel::ceiling_double_to_int(a.floatval());
}

LispObject Ceiling::op(Flt a)
{   return arithlib_lowlevel::ceiling_double_to_int(a.floatval());
}

LispObject Ceiling::op(double a)
{   return arithlib_lowlevel::ceiling_double_to_int(a);
}

LispObject Ceiling::op(LFlt a)
{   return arithlib_lowlevel::ceiling_float128_to_int(a.floatval());
}

LispObject Ftruncate::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ftruncate>("floor", a);
}

LispObject Ftruncate::op(Fixnum a)
{   return a.value();
}

LispObject Ftruncate::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Ftruncate::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ftruncate(Rat)")
}

LispObject Ftruncate::op(Cpx a)
{   aerror1("bad argument for trunc", a.value());
}

LispObject Ftruncate::op(SFlt a)
{   return arithlib_lowlevel::trunc_double_to_int(a.floatval());
}

LispObject Ftruncate::op(Flt a)
{   return arithlib_lowlevel::trunc_double_to_int(a.floatval());
}

LispObject Ftruncate::op(double a)
{   return arithlib_lowlevel::trunc_double_to_int(a);
}

LispObject Ftruncate::op(LFlt a)
{   return arithlib_lowlevel::trunc_float128_to_int(a.floatval());
}

LispObject Ffloor::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ffloor>("floor", a);
}

LispObject Ffloor::op(Fixnum a)
{   return a.value();
}

LispObject Ffloor::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Ffloor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ffloor(Rat)")
}

LispObject Ffloor::op(Cpx a)
{   aerror1("bad argument for floor", a.value());
}

LispObject Ffloor::op(SFlt a)
{   return arithlib_lowlevel::floor_double_to_int(a.floatval());
}

LispObject Ffloor::op(Flt a)
{   return arithlib_lowlevel::floor_double_to_int(a.floatval());
}

LispObject Ffloor::op(double a)
{   return arithlib_lowlevel::floor_double_to_int(a);
}

LispObject Ffloor::op(LFlt a)
{   return arithlib_lowlevel::floor_float128_to_int(a.floatval());
}

LispObject Fceiling::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Fceiling>("ceiling", a);
}

LispObject Fceiling::op(Fixnum a)
{   return a.value();
}

LispObject Fceiling::op(uint64_t *a)
{   return (LispObject)((char *)a - 8 + TAG_NUMBERS);
}

LispObject Fceiling::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Fceiling(Rat)")
}

LispObject Fceiling::op(Cpx a)
{   aerror1("bad argument for ceiling", a.value());
}

LispObject Fceiling::op(SFlt a)
{   return arithlib_lowlevel::ceiling_double_to_int(a.floatval());
}

LispObject Fceiling::op(Flt a)
{   return arithlib_lowlevel::ceiling_double_to_int(a.floatval());
}

LispObject Fceiling::op(double a)
{   return arithlib_lowlevel::ceiling_double_to_int(a);
}

LispObject Fceiling::op(LFlt a)
{   return arithlib_lowlevel::ceiling_float128_to_int(a.floatval());
}

// (frexp nn) => (double-float . fixnum)

LispObject Frexp::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Frexp>("frexp", a);
}

LispObject frexp_finalize(double d, int x)
{   int x1;
    d = std::frexp(d, &x1);
    return cons(fixnum_of_int(x + x1), make_boxfloat(d));
}

LispObject Frexp::op(Fixnum a)
{   return frexp_finalize((double)a.intval(), 0);
}

LispObject Frexp::op(uint64_t *a)
{   int64_t x;
    double d = arithlib_lowlevel::Frexp::op(a, x);
    return frexp_finalize(d, x);
}

LispObject Frexp::op(Rat a)
{   int64_t xp;
    double p = Frexp::op(a.numerator(), xp);
    int64_t xq;
    double q = Frexp::op(a.denominator(), xq);
    return frexp_finalize(p/q, xp-xq);
}

LispObject Frexp::op(Cpx a)
{   aerror1("bad argument for frexp", a.value());
}

LispObject Frexp::op(SFlt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp::op(Flt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp::op(double a)
{   return frexp_finalize(a, 0);
}

LispObject Frexp::op(LFlt a)
{   return frexp_finalize(Float::op(a), 0);
}

double frexp_finalize(double d, int x, int64_t &xx)
{   int x1;
    d = std::frexp(d, &x1);
    xx = x + x1;
    return d;
}

double Frexp::op(LispObject a, int64_t &xx)
{   return number_dispatcher::unary<double,Frexp>("frexp", a, xx);
}

double Frexp::op(Fixnum a, int64_t &xx)
{   return frexp_finalize((double)a.intval(), 0, xx);
}

double Frexp::op(uint64_t *a, int64_t &xx)
{   int64_t x;
    double d = arithlib_lowlevel::Frexp::op(a, x);
    return frexp_finalize(d, x, xx);
}

double Frexp::op(Rat a, int64_t &xx)
{   int64_t xp;
    double p = Frexp::op(a.numerator(), xp);
    int64_t xq;
    double q = Frexp::op(a.denominator(), xq);
    return frexp_finalize(p/q, xp-xq, xx);
}

double Frexp::op(Cpx a, int64_t &xx)
{   aerror1("bad argument for frexp", a.value());
}

double Frexp::op(SFlt a, int64_t &xx)
{   return frexp_finalize((double)a.floatval(), 0, xx);
}

double Frexp::op(Flt a, int64_t &xx)
{   return frexp_finalize((double)a.floatval(), 0, xx);
}

double Frexp::op(double a, int64_t &xx)
{   return frexp_finalize((double)a, 0, xx);
}

double Frexp::op(LFlt a, int64_t &xx)
{   return frexp_finalize(Float::op(a), 0, xx);
}

LispObject frexp_finalize(float128_t d, int x)
{   int x1;
    f128M_frexp(&d, &d, &x1);
    return cons(fixnum_of_int(x+x1), make_boxfloat128(d));
}

LispObject Frexp128::op(Fixnum a)
{   return frexp_finalize((double)a.intval(), 0);
}

LispObject Frexp128::op(uint64_t *a)
{   int64_t x;
    float128_t d = arithlib_lowlevel::Frexp128::op(a, x);
    return frexp_finalize(d, x);
}

LispObject Frexp128::op(Rat a)
{   int64_t xp;
    float128_t p = Frexp128::op(a.numerator(), xp);
    int64_t xq;
    float128_t q = Frexp128::op(a.denominator(), xq);
    return frexp_finalize(f128_div(p, q), xp-xq);
}

LispObject Frexp128::op(Cpx a)
{   aerror1("bad argument for frexp", a.value());
}

LispObject Frexp128::op(SFlt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp128::op(Flt a)
{   return frexp_finalize(a.floatval(), 0);
}

LispObject Frexp128::op(double a)
{   return frexp_finalize(a, 0);
}

LispObject Frexp128::op(LFlt a)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0);
}

float128_t Frexp128::op(LispObject a, int64_t &xx)
{   return number_dispatcher::unary<float128_t,Frexp128>("frexp128", a, xx);
}

float128_t frexp_finalize(float128_t d, int x, int64_t &xx)
{   int x1;
    f128M_frexp(&d, &d, &x1);
    xx = x + x1;
    return d;
}

float128_t Frexp128::op(Fixnum a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(uint64_t *a, int64_t &xx)
{   int64_t x;
    float128_t d = arithlib_lowlevel::Frexp128::op(a, x);
    return frexp_finalize(d, x, xx);
}

float128_t Frexp128::op(Rat a, int64_t &xx)
{   int64_t xp;
    float128_t p = Frexp128::op(a.numerator(), xp);
    int64_t xq;
    float128_t q = Frexp128::op(a.denominator(), xq);
    return frexp_finalize(f128_div(p, q), xp-xq, xx);
}

float128_t Frexp128::op(Cpx a, int64_t &xx)
{   aerror1("bad argument for frexp", a.value());
}

float128_t Frexp128::op(SFlt a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(Flt a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(double a, int64_t &xx)
{   return frexp_finalize(RawFloat128::op(a), 0, xx);
}

float128_t Frexp128::op(LFlt a, int64_t &xx)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0, xx);
}

LispObject Ldexp::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Ldexp>("ldexp", a, b);
}

LispObject Ldexp::op(Fixnum a, Fixnum b)
{   double d = std::ldexp((double)a.intval(), b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(uint64_t *a, Fixnum b)
{   double d = std::ldexp(Float::op(a), b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(Rat a, Fixnum b)
{   double d = std::ldexp(Float::op(a), b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(Cpx a, Fixnum b)
{   aerror1("bad argument for ldexp", a.value());
}

LispObject Ldexp::op(SFlt a, Fixnum b)
{   double d = std::ldexp(a.floatval(), b.intval());
    return pack_short_float(d);
}

LispObject Ldexp::op(Flt a, Fixnum b)
{   double d = std::ldexp(a.floatval(), b.intval());
    return pack_single_float(d);
}

LispObject Ldexp::op(double a, Fixnum b)
{   double d = std::ldexp(a, b.intval());
    return make_boxfloat(d);
}

LispObject Ldexp::op(LFlt a, Fixnum b)
{   float128_t f = a.floatval();
    f128M_ldexp(&f, b.intval());
    return make_boxfloat128(f);
}

// If the exponent imposed by ldexp is a bignum I map to zero if it is
// negative and I force in an exponent of 10000000 otherwise, expecting
// that to leave 0.0 as 0.0 but turn everything else into an infinity.

LispObject Ldexp::op(Fixnum a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(0.0);
    double d = std::ldexp((double)a.intval(), 100000000);
    return make_boxfloat(d);
}

LispObject Ldexp::op(uint64_t *a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(0.0);
    double d = std::ldexp(Float::op(a), 100000000);
    return make_boxfloat(d);
}

LispObject Ldexp::op(Rat a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(0.0);
    double d = std::ldexp(Float::op(a), 100000000);
    return make_boxfloat(d);
}

LispObject Ldexp::op(Cpx a, uint64_t *b)
{   aerror1("bad argument for ldexp", a.value());
}

LispObject Ldexp::op(SFlt a, uint64_t *b)
{   if (Minusp::op(b)) return pack_short_float(
        a.floatval() == a.floatval() ? 0.0 : 0.0/0.0);
    double d = std::ldexp(a.floatval(), 100000000);
    return pack_short_float(d);
}

LispObject Ldexp::op(Flt a, uint64_t *b)
{   if (Minusp::op(b)) return pack_single_float(
        a.floatval() == a.floatval() ? 0.0 : 0.0/0.0);
    double d = std::ldexp(a.floatval(), 100000000);
    return pack_single_float(d);
}

LispObject Ldexp::op(double a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat(
        a == a ? 0.0 : 0.0/0.0,
        TYPE_DOUBLE_FLOAT);
    double d = std::ldexp(a, 100000000);
    return make_boxfloat(d);
}

// I am not dealing with a NaN in the float128 case at present.

LispObject Ldexp::op(LFlt a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat128(i64_to_f128(0));
    float128_t f = a.floatval();
    f128M_ldexp(&f, 100000000);
    return make_boxfloat128(f);
}

LispObject Sqrt::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Sqrt>("sqrt", a);
}

LispObject Sqrt::op(Fixnum a)
{   return make_boxfloat(std::sqrt((double)a.intval()));
}

LispObject Sqrt::op(uint64_t *a)
{   return make_boxfloat(std::sqrt(RawFloat::op(a)));
}

LispObject Sqrt::op(Rat a)
{   int64_t px, qx;
    double p = Frexp::op(a.numerator(), px);
    double q = Frexp::op(a.denominator(), qx);
    if (px%2 != 0)
    {   p *= 2.0;
        px--;
    }
    if (qx%2 != 0)
    {   q *= 2.0;
        qx--;
    }
    return make_boxfloat(std::ldexp(std::sqrt(p/q), (p-q)/2));
}

LispObject Sqrt::op(Cpx a)
{   aerror1("complex sqrt not coded yet", a.value());
}

LispObject Sqrt::op(SFlt a)
{   return make_boxfloat(std::sqrt(Float::op(a)));
}

LispObject Sqrt::op(Flt a)
{  return make_boxfloat(std::sqrt(Float::op(a)));
}

LispObject Sqrt::op(double a)
{   return make_boxfloat(std::sqrt(a));
}

LispObject Sqrt::op(LFlt a)
{   return make_boxfloat128(f128_sqrt(a.floatval()));
}

LispObject Isqrt::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Isqrt>("isqrt", a);
}

LispObject Isqrt::op(Fixnum a)
{   return arithlib_lowlevel::Isqrt::op(a.intval());
}

LispObject Isqrt::op(uint64_t *a)
{   return arithlib_lowlevel::Isqrt::op(a);
}

LispObject Isqrt::op(Rat a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(Cpx a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(SFlt a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(Flt a)
{   aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(double a)
{   aerror1("bad argument for isqrt", make_boxfloat(a));
}

LispObject Isqrt::op(LFlt a)
{   aerror1("bad argument for isqrt", a.value());
}

#endif // ARITHLIB

// end of arith-float.cpp
