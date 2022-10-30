// arith-float.cpp                         Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

// $Id$


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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
// One can not just turn the numerator and denominator into floats and
// divide because each could be outside the range of floating point even
// though the quotient was a reasonable value.

LispObject Float::op(Rat a)
{   return aerror("float of rat not coded yet");
//    return Float::op(a.numerator()) / Float::op(a.denominator());
}

LispObject Float::op(Cpx a)
{   return aerror1("bad argument for float", a.value());
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
    std::memcpy(&d, &f, sizeof(double));
    return make_boxfloat(d);
}

LispObject Float128::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Float128>("float128",
            a);
}

LispObject Float128::op(Fixnum a)
{   return make_boxfloat128(i64_to_f128(a.intval()));
}

LispObject Float128::op(uint64_t *a)
{   return make_boxfloat128(arithlib_lowlevel::Float128::op(a));
}

// As for shorter floats! 
LispObject Float128::op(Rat a)
{   return aerror("floating a rat not implemented yet");
//return f128_div(Float128::op(a.numerator()), Float128::op(a.denominator()));
}

LispObject Float128::op(Cpx a)
{   return aerror1("bad argument for float128", a.value());
}

LispObject Float128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(double a)
{   double d = a;
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return make_boxfloat128(f64_to_f128(dd));
}

LispObject Float128::op(LFlt a)
{   return a.value();
}

// In Common Lisp the 1-argument version of FLOAT converts to a
// single precision float and if the second argument of the 2-argument
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
// instances where premature overflow can arise.              ACN June 2020

LispObject Float::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
}

LispObject Float::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Float>("float", a,
            b);
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
    double p = number_dispatcher::unary<double,Frexp>("frexp",
               a.numerator(), px);
    double q = number_dispatcher::unary<double,Frexp>("frexp",
               a.denominator(), qx);
    return std::ldexp(p/q, px-qx);
}

double RawFloat::op(Cpx a)
{   aerror1("bad argument for float", a.value());
    return 0.0;
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
    std::memcpy(&d, &f, sizeof(double));
    return d;
}

float128_t RawFloat128::op(LispObject a)
{   //return
    //    number_dispatcher::unary<float128_t,RawFloat128>("float128", a);
    return i64_to_f128(0);
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
    return i64_to_f128(0);
}

float128_t RawFloat128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t RawFloat128::op(double a)
{   double d = a;
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
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
{   return bit_cast<LispObject>(bit_cast<char *>
                                   (a) - 8 + TAG_NUMBERS);
}

LispObject Fix::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Fix::op(Cpx a)
{   return aerror1("bad argument for fix", a.value());
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
{   return bit_cast<LispObject>(bit_cast<char *>
                                   (a) - 8 + TAG_NUMBERS);
}

LispObject Truncate::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Truncate(Rat)")
}

LispObject Truncate::op(Cpx a)
{   return aerror1("bad argument for trunc", a.value());
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
{   return bit_cast<LispObject>(bit_cast<char *>
                                   (a) - 8 + TAG_NUMBERS);
}

LispObject Floor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Floor(Rat)")
// Need tp round towards -infinity here.
}

LispObject Floor::op(Cpx a)
{   return aerror1("bad argument for floor", a.value());
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
{   return bit_cast<LispObject>(bit_cast<char *>
                                   (a) - 8 + TAG_NUMBERS);
}

LispObject Ceiling::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ceiling(Rat)")
// noot to truncate towards +infinity here
}

LispObject Ceiling::op(Cpx a)
{   return aerror1("bad argument for ceiling", a.value());
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
{   return bit_cast<LispObject>(bit_cast<char *>
                                   (a) - 8 + TAG_NUMBERS);
}

LispObject Ftruncate::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ftruncate(Rat)")
}

LispObject Ftruncate::op(Cpx a)
{   return aerror1("bad argument for trunc", a.value());
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
{   return bit_cast<LispObject>(bit_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Ffloor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ffloor(Rat)")
}

LispObject Ffloor::op(Cpx a)
{   return aerror1("bad argument for floor", a.value());
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
{   return bit_cast<LispObject>(bit_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Fceiling::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Fceiling(Rat)")
}

LispObject Fceiling::op(Cpx a)
{   return aerror1("bad argument for ceiling", a.value());
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
{   return frexp_finalize(static_cast<double>(a.intval()), 0);
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
{   return aerror1("bad argument for frexp", a.value());
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
{   return frexp_finalize(static_cast<double>(a.intval()), 0, xx);
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
    return 0.0;
}

double Frexp::op(SFlt a, int64_t &xx)
{   return frexp_finalize(static_cast<double>(a.floatval()), 0, xx);
}

double Frexp::op(Flt a, int64_t &xx)
{   return frexp_finalize(static_cast<double>(a.floatval()), 0, xx);
}

double Frexp::op(double a, int64_t &xx)
{   return frexp_finalize(static_cast<double>(a), 0, xx);
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
{   return frexp_finalize(static_cast<double>(a.intval()), 0);
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
{   return aerror1("bad argument for frexp", a.value());
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

LispObject Frexp128::op(LFlt
                        a)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0);
}

float128_t Frexp128::op(LispObject a, int64_t &xx)
{   //return number_dispatcher::unary<float128_t,Frexp128>("frexp128",
    //        a, xx);
    return i64_to_f128(0);
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
    return i64_to_f128(0);
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

float128_t Frexp128::op(LFlt a,
                        int64_t &xx)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0, xx);
}

LispObject Ldexp::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Ldexp>("ldexp", a,
            b);
}

LispObject Ldexp::op(Fixnum a, Fixnum b)
{   double d = std::ldexp(static_cast<double>(a.intval()),
                          b.intval());
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
{   return aerror1("bad argument for ldexp", a.value());
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
    double d = std::ldexp(static_cast<double>(a.intval()), 100000000);
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
{   return aerror1("bad argument for ldexp", a.value());
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
                                      WANT_DOUBLE_FLOAT);
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
{   return make_boxfloat(std::sqrt(static_cast<double>(a.intval())));
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
{   return aerror1("complex sqrt not coded yet", a.value());
}

LispObject Sqrt::op(SFlt a)
{   return make_boxfloat(std::sqrt(Float::op(a)));
}

LispObject Sqrt::op(Flt a)
{   return make_boxfloat(std::sqrt(Float::op(a)));
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
{   return aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(Cpx a)
{   return aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(SFlt a)
{   return aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(Flt a)
{   return aerror1("bad argument for isqrt", a.value());
}

LispObject Isqrt::op(double a)
{   return aerror1("bad argument for isqrt", make_boxfloat(a));
}

LispObject Isqrt::op(LFlt a)
{   return aerror1("bad argument for isqrt", a.value());
}

LispObject Nfp_infinite(LispObject env, LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (std::fpclassify(value_of_immediate_float(a)) == FP_INFINITE)
                return onevalue(lisp_true);
            return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128M_infinite(reinterpret_cast<float128_t *>(&long_float_val(
                                           a))))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
                case SINGLE_FLOAT_HEADER:
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_INFINITE)
                        return onevalue(lisp_true);
                    return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}


LispObject Nfp_nan(LispObject env, LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (std::fpclassify(value_of_immediate_float(a)) == FP_NAN)
                return onevalue(lisp_true);
            return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    if (std::fpclassify(single_float_val(a)) == FP_NAN)
                        return onevalue(lisp_true);
                    return onevalue(nil);
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128M_nan(reinterpret_cast<float128_t *>(&long_float_val(a))))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_NAN)
                        return onevalue(lisp_true);
                    return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

LispObject Nfp_finite(LispObject env, LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (std::isfinite(value_of_immediate_float(a)))
                return onevalue(lisp_true);
            return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128M_finite(reinterpret_cast<float128_t *>(&long_float_val(a))))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
                case SINGLE_FLOAT_HEADER:
                    if (std::isfinite(single_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
                case DOUBLE_FLOAT_HEADER:
                    if (std::isfinite(double_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

LispObject Nfp_subnorm(LispObject env, LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
        {   if (std::fpclassify(value_of_immediate_float(a)) == FP_SUBNORMAL)
                return  onevalue(lisp_true);
            else return onevalue(nil);
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    if (std::fpclassify(single_float_val(a)) == FP_SUBNORMAL)
                        return  onevalue(lisp_true);
                    else return onevalue(nil);
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128M_subnorm(reinterpret_cast<float128_t *>(&long_float_val(a))))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_SUBNORMAL)
                        return  onevalue(lisp_true);
                    else return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

// This will return T if its argument has its sign bit set. Note that this
// NOT the same a test (x < 0) because this function returns T for -0.0.

// C++ is expected to have std::signbit, so I will always use it. Without
// it I will not cope properly with signed zeros.

#define HAVE_SIGNBIT 1

LispObject Nfp_signbit(LispObject env, LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if ((intptr_t)a < 0) return onevalue(lisp_true);
            else return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return onevalue(std::signbit(single_float_val(a)) ? lisp_true : nil);
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    return onevalue(f128M_negative(reinterpret_cast<float128_t *>
                                                   (&long_float_val(a))) ?
                                    lisp_true : nil);
#endif // HAVE_SOFTFLOAT
                case DOUBLE_FLOAT_HEADER:
                    return onevalue(std::signbit(double_float_val(a)) ? lisp_true : nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}


// The functions such as float-digits, float-precision, float-radix are
// coded here assuming that IEEE-style arithmetic is being used. If this is
// not so then all the code in this file needs review.  Furthermore I will
// be lazy about NaNs and denormalised numbers for now and come back to
// worry about them later on if I am really forced to.

LispObject Nfloat_digits(LispObject env, LispObject a)
{   int tag = static_cast<int>(a) & XTAG_BITS;
    switch (tag)
    {   case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return onevalue(fixnum_of_int(24));
            else return onevalue(fixnum_of_int(20));
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return onevalue(fixnum_of_int(24));
                case DOUBLE_FLOAT_HEADER:
                    return onevalue(fixnum_of_int(53));
                case LONG_FLOAT_HEADER:
                    return onevalue(fixnum_of_int(113));
            }
        default:
            return aerror("float-digits");
    }
}

LispObject Nfloat_precision(LispObject env, LispObject a)
{   int tag = static_cast<int>(a) & XTAG_BITS;
    double d = float_of_number(a);
    if (d == 0.0) return onevalue(fixnum_of_int(0));
    switch (tag)
    {   case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return onevalue(fixnum_of_int(24));
            else return onevalue(fixnum_of_int(20));
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return onevalue(fixnum_of_int(24));
                case DOUBLE_FLOAT_HEADER:
                    return onevalue(fixnum_of_int(53));
                case LONG_FLOAT_HEADER:
                    return onevalue(fixnum_of_int(113));
            }
        default:
            return aerror("float-precision");
    }
}

// In CSL all floats use the same radix (2) and so the function to
// find the radix does not need to look at its argument.

LispObject Nfloat_radix(LispObject env, LispObject a2)
{   return onevalue(fixnum_of_int(FLT_RADIX));
}

LispObject Nfloat_sign2(LispObject env, LispObject a,
                               LispObject b)
{
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(b) &&
        flthdr(b) == LONG_FLOAT_HEADER)
    {   float128_t d = float128_of_number(b);
// If a is another long float then float_of_number may overflow, but
// here I am only interested in its sign, and -infinity is still negative.
        if (float_of_number(a) < 0.0) f128M_negate(&d);
        return onevalue(make_boxfloat128(d));
    }
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(b);
// Worry a bit about -0.0 here
    if (float_of_number(a) < 0.0) d = -d;
    if (is_sfloat(b)) return onevalue(pack_immediate_float(d, b));
    else if (!is_bfloat(b)) return aerror1("bad arg for float-sign",  b);
// make_boxfloat may detect infinity or NaN.
    else return onevalue(make_boxfloat(d, floatWant(flthdr(b))));
}

LispObject Nfloat_sign1(LispObject env, LispObject a)
{
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(1) &&
        flthdr(a) == LONG_FLOAT_HEADER)
    {   float128_t d = float128_of_number(a);
        float128_t r = f128_1;
        if (f128M_negative(&d)) f128M_negate(&r);
        return onevalue(make_boxfloat128(r));
    }
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
// worry a bit about -0.0 here
    if (d < 0.0) d = -1.0;
    else d = 1.0;
    if (is_sfloat(a)) return onevalue(pack_immediate_float(d, a));
    else if (!is_bfloat(a)) return aerror1("bad arg for float-sign",  a);
    else return onevalue(make_boxfloat(d, floatWant(flthdr(a))));
}

static double fp_args[32];
static double fp_stack[16];

// codes 0 to 31 just load up arguments
#define FP_RETURN        32
#define FP_PLUS          33
#define FP_DIFFERENCE    34
#define FP_TIMES         35
#define FP_QUOTIENT      36
#define FP_MINUS         37
#define FP_SQUARE        38
#define FP_CUBE          39
#define FP_SIN           40
#define FP_COS           41
#define FP_TAN           42
#define FP_EXP           43
#define FP_LOG           44
#define FP_SQRT          45

LispObject Nfp_eval(LispObject env, LispObject code, LispObject args)
// The object of this code is to support fast evaluation of numeric
// expressions.  The first argument is a vector of byte opcodes, while
// the second arg is a list of floating point values whose value will (or
// at least may) be used.  There are at most 32 values in this list.
{   int n = 0;
    double w;
    unsigned char *p;
    if (!is_vector(code)) return aerror("fp-evaluate");
    while (consp(args))
    {   fp_args[n++] = float_of_number(car(args));
        if (n >= 32) return aerror("too many args in fp-evaluate");
        args = cdr(args);
    }
    n = 0;
    p = bit_cast<unsigned char *>(&ucelt(code, 0));
    for (;;)
    {   int op = *p++;
// Opcodes 0 to 31 just load up the corresponding input value.
        if (op < 32)
        {   fp_stack[n++] = fp_args[op];
            if (n >= 16) return aerror("stack overflow in fp-evaluate");
            continue;
        }
        switch (op)
        {   default:
                return aerror("Bad op in fp-evaluate");
            case FP_RETURN:
                args = make_boxfloat(fp_stack[0], WANT_DOUBLE_FLOAT);
                return onevalue(args);
            case FP_PLUS:
                n--;
                fp_stack[n] += fp_stack[n-1];
                continue;
            case FP_DIFFERENCE:
                n--;
                fp_stack[n] -= fp_stack[n-1];
                continue;
            case FP_TIMES:
                n--;
                fp_stack[n] *= fp_stack[n-1];
                continue;
            case FP_QUOTIENT:
                n--;
                fp_stack[n] /= fp_stack[n-1];
                continue;
            case FP_MINUS:
                fp_stack[n] = -fp_stack[n];
                continue;
            case FP_SQUARE:
                fp_stack[n] *= fp_stack[n];
                continue;
            case FP_CUBE:
                w = fp_stack[n];
                w *= w;
                fp_stack[n] *= w;
                continue;
            case FP_SIN:
                fp_stack[n] = std::sin(fp_stack[n]);
                continue;
            case FP_COS:
                fp_stack[n] = std::cos(fp_stack[n]);
                continue;
            case FP_TAN:
                fp_stack[n] = std::tan(fp_stack[n]);
                continue;
            case FP_EXP:
                fp_stack[n] = std::exp(fp_stack[n]);
                continue;
            case FP_LOG:
                fp_stack[n] = std::log(fp_stack[n]);
                continue;
            case FP_SQRT:
                fp_stack[n] = std::sqrt(fp_stack[n]);
                continue;
        }
    }
}

LispObject Ntrap_floating_overflow(LispObject env, LispObject a)
{   bool o = trap_floating_overflow;
    trap_floating_overflow = (a != nil);
    return onevalue(Lispify_predicate(o));
}

LispObject Nround(LispObject env, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) return aerror1("round", a);
    return lisp_ifix(a, b, FIX_ROUND);
}

#ifdef HAVE_SOFTFLOAT
// long float version of the following function. Commentary is in the
// double precision version.

static LispObject Nlisp_fix_sub128(LispObject a, int roundmode)
{   float128_t *d = reinterpret_cast<float128_t *>(long_float_addr(
                        a));
    if (f128M_nan(d)) return aerror("NaN in fix");
    if (f128M_infinite(d)) return aerror("infinity in fix");
    int x = f128M_exponent(d);
// Here I will limit the range where I convert to an int64_t value because
// a long float could have a value of (say) INT64_MAX+0.75, and then the
// conversion would overflow and hence fail.
    if (x < 62)
    {   int64_t n = f128M_to_i64(d, roundmode, false);
// Here the softfloat library does rounding for me. Hoorah!
        return make_lisp_integer64(n);
    }
// Now I know that the result will be at least a 62-bit integer, which means
// it will be at least a 3-word bignum.
// I may sometimes still need to worry about rounding.
    int32_t d4;
    uint32_t d3, d2, d1, d0;
    intptr_t x1 = float128_to_5_digits(d, d4, d3, d2, d1, d0);
    switch (x1)
    {   case -2:
// The integer part is at present represented in 2s complement, so if I
// chop bits off its end that will decrease its value. Put another way, the
// raw value I have got is as for FLOOR.
            if (d1 != 0 || d0 != 0)
            {   switch (roundmode)
            {       default:
                    case FIX_TRUNCATE:
                        if (d4 < 0) goto inc2;
                        break;
                    case FIX_ROUND:
                        if (d1 > 0x40000000 ||
                            (d1 == 0x40000000 && d0 != 0)) goto inc2;
                        if (d1 == 0x40000000 && ((d2 & 1) != 0)) goto inc2;
                        break;
                    case FIX_FLOOR:
                        break;          // Nothing more to do
                    case FIX_CEILING:   // always need to increment here
                    inc2:
                        d2++;
                        if (d2 == 0x40000000)
                        {   d2 = 0;
                            d3++;
                            if (d3 == 0x40000000)
                            {   d3 = 0;
                                d4++;
                                if (d4 == 0x40000000) // need an extra word
                                    return make_four_word_bignum(0, d4, 0, 0);
                                else if (d4 == 0)
                                    return make_two_word_bignum(0xc0000000,0);
                            }
                        }
                        break;
                }
            }
            return make_three_word_bignum(d4, d3, d2);
        case -1:
            if (d0 != 0)
            {   switch (roundmode)
            {       default:
                    case FIX_TRUNCATE:
                        if (d4 < 0) goto inc1;
                        break;
                    case FIX_ROUND:
                        if (d0 > 0x40000000) goto inc1;
                        if (d0 == 0x40000000 && ((d1 & 1) != 0)) goto inc1;
                        break;
                    case FIX_FLOOR:
                        break;          // Nothing more to do
                    case FIX_CEILING:   // always need to increment here
                    inc1:
                        d1++;
                        if (d1 == 0x40000000)
                        {   d1 = 0;
                            d2++;
                            if (d2 == 0x40000000)
                                if (d2 == 0x40000000)
                                {   d2 = 0;
                                    d3++;
                                    if (d3 == 0x40000000)
                                    {   d3 = 0;
                                        d4++;
                                        if (d4 == 0x40000000) // need an extra word
                                            return make_n_word_bignum(0, d4, 0, 2);
                                        else if (d4 == 0)
                                            return make_three_word_bignum(0xc0000000, 0, 0);
                                    }
                                }
                        }
                        break;
                }
            }
            return make_four_word_bignum(d4, d3, d2, d1);
        default:
            return make_n5_word_bignum(d4, d3, d2, d1, d0, x1);
    }
}
#endif // HAVE_SOFTFLOAT

static LispObject Nlisp_fix_sub(LispObject a, int roundmode)
// This converts from a double to a Lisp integer, which will
// quite often have to be a bignum.  No overflow is permitted - the
// result can always be accurate.
{
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Nlisp_fix_sub128(a, roundmode);
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
    if (!(d == d)) return aerror("NaN in fix");
    if (1.0/d == 0.0) return aerror("infinity in fix");
// I will take a cheaper path if d is such that I can cast it to a 64-bit
// integer without that causing (integer) overflow.
    if (d >= static_cast<double>(INT64_MIN) &&
        d < -static_cast<double>(INT64_MIN))
    {   int64_t n = (int64_t)d;
// Here the absolute value of d was strictly smaller than 2^63 and it
// was truncated towards zero in the conversion to an integer, so n
// is a value that would fit in a 64-bit integer. Fixing the rounding mode
// can only possibly change its value by +1 or -1, and that means that the
// only imaginable possibility for overflow is if it starts of as
// 0x7fffffffffffffff and has to be rounded up. But because doubles only have
// 53 bits of mantissa any that are close to the ends of the range of 64-bit
// integers will convert exactly to integers without and need for rounding.
        double f;   // The fraction part that is left over...
        switch (roundmode)
    {       default:
            case FIX_TRUNCATE:  // The cast truncated so I am done.
                return make_lisp_integer64(n);
            case FIX_ROUND:
// In a more general situation you could worry that (double)n could introduce
// rounding for some values of n > 2^53. However in any such case n will have
// been derived from a float that had an exact integer value so there will
// not have been any rounding and will not need to be any on the return trip.
                f = d - static_cast<double>(n);
                if (f > 0.5) n = (uint64_t)n + 1;
                else if (f < -0.5) n--;
                else if (f == 0.5) n = ((uint64_t)n+1) & ~1;
                else if (f == -0.5) n = n & ~1;
// If the original value of n was MAX_INT64 and I rounded up then I
// could have overflowed here, so in the case where that could arise
// I treat the value as unsigned.
                if (d < 0.0) return make_lisp_integer64(n);
                else return make_lisp_unsigned64(n);
            case FIX_FLOOR:
                f = d - static_cast<double>(n);
                if (f < 0.0) n--;  // no overflow possible
                return make_lisp_integer64(n);
                break;
            case FIX_CEILING:
                f = d - static_cast<double>(n);
                if (f > 0.0) n = (uint64_t)n + 1;
                if (d < 0.0) return make_lisp_integer64(n);
                else return make_lisp_unsigned64(n);
        }
    }
// Now I know that the result will be at least a 63-bit integer, which means
// it will be at least a 3-word bignum. Life is even better than that. If
// the input as that large then since a double precision float only has 56
// bits for its mantissa I know now that I will not need to do any rounding,
// and so all the complication regarding the rounding mode does not apply.
    int32_t d2;
    uint32_t d1, d0;
    intptr_t x = double_to_3_digits(d, d2, d1, d0);
    return make_n_word_bignum(d2, d1, d0, x);
}

// This converts from a ratio to a Lisp integer.  It has to apply
// rounding in the desired direction.

static LispObject Nlisp_fix_ratio(LispObject a, int roundmode)
{   LispObject w, w1;
    THREADID;
    RealSave save(THREADARG numerator(a), denominator(a), nil);
    LispObject &p = save.val(1);
    LispObject &q = save.val(2);  // note that q will always be positive!
    LispObject &r = save.val(3);
    r = quot2(p, q);
    errexit();
    p = Cremainder(p, q);
    errexit();
// The quotient is now in r and the remainder in p. The original divisor
// is still in q.
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
// Here p is the eventual remainder. If it is less then -q/2 or greater
// then q/2 I will need to adjust things. And if it is equal in either of
// those edge cases I need to think even harder!
            w = times2(p, fixnum_of_int(2));
            errexit();
            {   Save save1(THREADARG w);
                w1 = negate(w);
                errexit();
                save.restore(w);
            }
            if (greaterp2(w, q) ||
                (numeq2(w, q) && Loddp(nil, r)!=nil))
            {   p = difference2(p, q);
                errexit();
                r = add1(r);
                errexit();
            }
            else if (greaterp2(w1, q) ||
                     (numeq2(w1, q) && Loddp(nil, r)!=nil))
            {   p = plus2(p, q);
                errexit();
                r = sub1(r);
                errexit();
            }
            break;
        case FIX_FLOOR:
            if (minusp(p))
            {   p = plus2(p, q);
                errexit();
                r = sub1(r);
                errexit();
            }
            break;
        case FIX_CEILING:
            if (plusp(p))
            {   p = difference2(p, q);
                errexit();
                r = add1(r);
                errexit();
            }
            break;
    }
    mv_2 = p;
    return nvalues(r, 2);
}

// This fixes a value a and returns (a - fix(a)) as a second result. This is
// only ever called with a floating point argument.

LispObject Nlisp_fix(LispObject a, int roundmode)
{   LispObject r;
    THREADID;
    Save save(THREADARG a);
    r = Nlisp_fix_sub(a, roundmode);
    errexit();
    save.restore(a);
    Save save1(THREADARG r);
    a = difference2(a, r);
    errexit();
    save1.restore(r);
    mv_2 = a;
    return nvalues(r, 2);
}

// ifix is for the 2-arg variants of floor, truncate, round etc. For
// floating point values a and b it computes fix(a/b) and the residue
// returned as a second value is b times the residue in that fix operation.

LispObject Nlisp_ifix(LispObject aa, LispObject bb, int roundmode)
{   LispObject r2, negb;
    THREADID;
    if (is_float(aa) || is_float(bb))
    {   Save save(THREADARG bb);
        aa = quot2(aa, bb);
        errexit();
// If either argument was floating point then the quotient will be.
        LispObject r = Nlisp_fix(aa, roundmode);
        save.restore(bb);
        Save save1(THREADARG r);
        mv_2 = times2(mv_2, bb);
        errexit();
        save1.restore(r);
        return nvalues(r, 2);
    }
    RealSave save(THREADARG aa, bb, nil, nil);
    LispObject &a = save.val(1);
    LispObject &b = save.val(2);
    LispObject &r = save.val(3);
    LispObject &q = save.val(4);
    q = quot2(a, b);
    errexit();
    r = Cremainder(a, b);
    errexit();
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
// I will apply a round-to-nearest, with round-to-even to break ties.
            negb = negate(b);
            {   Save save1(THREADARG negb);
                r2 = times2(r, fixnum_of_int(2));
                errexit();
                save1.restore(negb);
            }
            if (lessp2(b, r2) ||
                (numeq2(b, r2) && Loddp(nil, q)!=nil)) goto increase_q;
            if (lessp2(r2, negb) ||
                (numeq2(r2, negb) && Loddp(nil, q)!=nil)) goto decrease_q;
            break;
        case FIX_FLOOR:
            if (!minusp(r)) break;
        decrease_q:
            r = plus2(r, b);
            errexit();
            q = sub1(q);
            errexit();
            break;
        case FIX_CEILING:
            if (!plusp(r)) break;
        increase_q:
            r = difference2(r, b);
            errexit();
            q = add1(q);
            errexit();
            break;
    }
    mv_2 = r;
    return nvalues(q, 2);
}

LispObject Nround(LispObject env, LispObject a)
{   if (!is_number(a)) return aerror1("round", a);
    if (is_numbers(a) && is_ratio(a)) return Nlisp_fix_ratio(a, FIX_ROUND);
    if (is_float(a)) return Nlisp_fix(a, FIX_ROUND);
    mv_2 = fixnum_of_int(0);
    return nvalues(a, 2);
}

LispObject Nfround(LispObject env, LispObject a1)
{   return aerror("fround");
}

LispObject Nfround(LispObject env, LispObject a1, LispObject a2)
{   return aerror("fround");
}

#ifdef HAVE_SOFTFLOAT
LispObject Nscale_float128(LispObject a, intptr_t x)
{   float128_t d = long_float_val(a);
    if (f128M_nan(&d)) return a;
    if (x >= 0x40000) x = 0x40000;
    else if (x <= -0x40000) x = -0x40000;
    if (f128M_subnorm(&d))
    {   f128M_mul(&d, &f128_N1, &d);
        x -= 4096;
    }
    x += f128M_exponent(&d);
    if (x >= 0x7fff)         // result will be infinite
        f128M_make_infinite(&d);
    else if (x <= 0)         // result underflows
    {   if (x < -113) f128M_make_zero(&d);
        else
        {   f128M_set_exponent(&d, x+4096);
// If there is a risk I need to generate a subnormal result do it this way.
            f128M_div(&d, &f128_N1, &d);
        }
    }
    else f128M_set_exponent(&d, x);
    return make_boxfloat128(d);
}
#endif // HAVE_SOFTFLOAT

LispObject Nscale_float(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(b)) return aerror("scale-float");
    intptr_t x = int_of_fixnum(b);
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Nscale_float128(a, x);
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
    if (x >= 4096) x = 4096;
    else if (x <= -4096) x = -4096;
    d = std::ldexp(d, static_cast<int>(x));
// Overflows etc handled by make_boxfloat.
    if (is_sfloat(a)) return onevalue(pack_immediate_float(d, a));
    else if (!is_bfloat(a)) return aerror1("bad arg for scale-float",  a);
    else return onevalue(make_boxfloat(d, floatWant(flthdr(a))));
}

#endif // ARITHLIB

// end of arith-float.cpp
