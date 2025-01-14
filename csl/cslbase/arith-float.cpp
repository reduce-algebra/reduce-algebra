// arith-float.cpp                         Copyright (C) 2022-2025 Codemist

#ifdef ARITHLIB

// $Id$


/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

#include "arith-headers.h"

// I first provide some helper functions for directed rouding in
// floating point division. Well C++ provides "fesetround()" to establish
// a (global) rounding mode, but that needs to be enabled using
// "#pragma STDC FENV_ACCESS ON" and there is no guarantee of what
// options will actually be supported (if any!). So despite the fact
// that what I provide here will be slow, I am going to go for portability
// over performance. The functions here divide pairs of floating point
// values with Truncate, Floor and Ceiling semantics. And I have versions
// suitable for use with each of the four floating point precisions I
// can ever use. I either say "ugh" or possibly "wheee - what fun" depending
// on whether I have anything more important to do!
// I am supposing that a RoundToNearest mode is what simple use of "/"
// provides so I do not need to do anything special for that here.

// For these I will want code that increments or decrements a floating
// point value when I need to round up or down.

// For short and single floats I pass values around as doubles. The
// relevant floating point representations are:
//   short    20 bit mantissa 8 bit exponent
//   single   24 bit mantissa 8 bit exponent
//   double   53 bit mantissa 11 bit exponent
//   long    113 bit mantissa 15 bit exponent 

double truncate_to_short(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa &= 0xfffffffe00000000LLU;
    return bit_cast<double>(aa);
}

double truncate_to_single(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa &= 0xffffffffe0000000LLU;
    return bit_cast<double>(aa);
}

double short_increment(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa += 0x0000000200000000LLU;
    return bit_cast<double>(aa);
}

double single_increment(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa += 0x0000000020000000LLU;
    return bit_cast<double>(aa);
}

double double_increment(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa += 1;
    return bit_cast<double>(aa);
}

float128_t long_increment(float128_t a)
{   float128_t aa;
    aa.v[HIPART] = a.v[HIPART];
    if ((aa.v[LOPART] = a.v[LOPART]+1) == 0)
         aa.v[HIPART]++;
    return aa;
}

double short_decrement(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa -= 0x0000000200000000LLU;
    return bit_cast<double>(aa);
}

double single_decrement(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa -= 0x0000000020000000LLU;
    return bit_cast<double>(aa);
}

double double_decrement(double a)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa -= 1;
    return bit_cast<double>(aa);
}

float128_t long_decrement(float128_t a)
{   float128_t aa;
    aa.v[HIPART] = a.v[HIPART];
    if (a.v[LOPART] == 0) aa.v[HIPART]--;
    aa.v[LOPART] = a.v[LOPART]-1;
    return aa;
}

double short_truncate(double a, double b)
{
// The code here supposed that the inputs are both short floats that
// have been widened to doubles, so they only have 20 bits of (active)
// mantissa.
    double q = truncate_to_short(a/b);
    double aa = q*b;         // will be computed accurately.
    if (aa == a) return q;   // no rounding involved.
    if (aa > a)
    {   if ((a>0.0) == (b>0.0)) q = short_decrement(q);
    }
    else if ((a>=0.0) != (b>0.0)) q = short_increment(q);
    return q;
}

double short_floor(double a, double b)
{   double q = truncate_to_short(a/b);
// 20+20 < 53
    double aa = q*b;         // will be computed accurately.
    if (aa == a) return q;   // no rounding involved.
    if (aa > a)
    {   if ((a>0.0) == (b>0.0)) q = short_decrement(q);
    }
    else if ((a>=0.0) != (b>0.0)) q = short_increment(q);
    return q;
}

double short_ceiling(double a, double b)
{   double q = truncate_to_short(a/b);
// 20+20 < 53
    double aa = q*b;         // will be computed accurately.
    if (aa == a) return q;   // no rounding involved.
    if (aa > a)
    {   if ((a>0.0) == (b>0.0)) q = short_decrement(q);
    }
    else if ((a>=0.0) != (b>0.0)) q = short_increment(q);
    return q;
}

double single_truncate(double a, double b)
{   double q = truncate_to_single(a/b);
// 24+24<53 
    double aa = q*b;         // will be computed accurately.
    if (aa == a) return q;   // no rounding involved.
    if (aa > a)
    {   if ((a>0.0) == (b>0.0)) q = single_decrement(q);
    }
    else if ((a>=0.0) != (b>0.0)) q = single_increment(q);
    return q;
}

double single_floor(double a, double b)
{   double q = truncate_to_single(a/b);
// 24+24<53 
    double aa = q*b;         // will be computed accurately.
    if (aa == a) return q;   // no rounding involved.
    if (aa > a) q = single_decrement(q);
    return q;
}

double single_ceiling(double a, double b)
{   double q = truncate_to_single(a/b);
// 24+24<53 
    double aa = q*b;         // will be computed accurately.
    if (aa == a) return q;   // no rounding involved.
    if (aa < a) q = single_increment(q);
    return q;
}

// This splits a double precision value that has 53-bits of mantissa
// as a = h + l where the lowPart can be either +ve or -ve.
// I am then going to want to do this to two input numbers and then
// evaluate h1*h2 + h1*l2 + l1*h2 + l1*l2 and I will want each of
// those multiplications to be performed exactly. So what will be
// needed is for each of h amd l to have just 26 bits with that achieved
// by having h rounded to nearest. Let me consider just for a moment the
// case when the rounding is at exactly the half way point so one might
// agonise about whether to round up or down. Well in that case the low
// part will be just exactly 0.5ulp relative to the high part so it does
// not use up all its bits.

double split_double_in_two(double a, double &lowPart)
{   uint64_t aa = bit_cast<uint64_t>(a);
    aa += 0x0000000008000000LLU;
    aa &= 0xfffffffff7000000LLU;
    double highPart = bit_cast<double>(aa);
    lowPart = a - highPart;
    return highPart;
}

double double_truncate(double a, double b)
{   double q = a/b;      // properly rounded so within 0.5ulp of accurate
// I now want to compute a double precision value for q*b
    double bhi, blo, qhi, qlo;
    bhi = split_double_in_two(b, blo);
    qhi = split_double_in_two(q, qlo);
    double ahi = bhi*qhi;
    double amid1 = bhi*qlo;
    double amid2 = blo*qhi;
    double alo = blo*qlo;
// Well I will want to subtract a from all of those and by the
// way things are constructed its value is almost exactly the
// same as ahi!
    ahi -= a;
    ahi += amid1;  // Am I doing enough here?
    ahi += amid2;
    ahi += alo;
// Now the sign of ahi will tell me if q was high, exact or low/
    if (ahi == 0.0) return q;
    else if (ahi > 0.0)
    {   if (q > 0.0) return double_decrement(q);
    }
    else if (q < 0.0) return double_increment(q);
    else return q;
}

double double_floor(double a, double b)
{   double q = a/b;      // properly rounded so within 0.5ulp of accurate
// I now want to compute a double precision value for q*b
    double bhi, blo, qhi, qlo;
    bhi = split_double_in_two(b, blo);
    qhi = split_double_in_two(q, qlo);
    double ahi = bhi*qhi;
    double amid1 = bhi*qlo;
    double amid2 = blo*qhi;
    double alo = blo*qlo;
// Well I will want to subtract a from all of those and by the
// way things are constructed its value is almost exactly the
// same as ahi!
    ahi -= a;
    ahi += amid1;  // Am I doing enough here?
    ahi += amid2;
    ahi += alo;
// Now the sign of ahi will tell me if q was high, exact or low/
    if (ahi == 0.0) return q;
    else if (ahi > 0.0) return double_decrement(q);
    else return q;
}

double double_ceiling(double a, double b)
{   double q = a/b;      // properly rounded so within 0.5ulp of accurate
// I now want to compute a double precision value for q*b
    double bhi, blo, qhi, qlo;
    bhi = split_double_in_two(b, blo);
    qhi = split_double_in_two(q, qlo);
    double ahi = bhi*qhi;
    double amid1 = bhi*qlo;
    double amid2 = blo*qhi;
    double alo = blo*qlo;
// Well I will want to subtract a from all of those and by the
// way things are constructed its value is almost exactly the
// same as ahi!
    ahi -= a;
    ahi += amid1;  // Am I doing enough here?
    ahi += amid2;
    ahi += alo;
// Now the sign of ahi will tell me if q was high, exact or low/
    if (ahi == 0.0) return q;
    else if (ahi < 0.0) return double_increment(q);
    else return q;
}

float128_t split_long_in_two(float128_t a, float128_t &lowPart)
{   float128_t aa = a;
    if ((aa.v[LOPART] += 0x0080000000000000LLU) < a.v[LOPART])
        aa.v[HIPART]++;
    aa.v[LOPART] &= 0xff00000000000000LLU;
    lowPart = f128_sub(a, aa);
    return aa;
}

float128_t long_truncate(float128_t a, float128_t b)
{
// I should be able to in effect copy the code from the double precision
// version and use it here. I will do that later on! @@@@@@@@@@@@
    return f128_div(a, b);
}

float128_t long_floor(float128_t a, float128_t b)
{
    return f128_div(a, b);
}

float128_t long_ceiling(float128_t a, float128_t b)
{
    return f128_div(a, b);
}


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

// One can not just turn the numerator and denominator into floats and
// divide because each could be outside the range of floating point even
// though the quotient was a reasonable value. So if I start with a ratio
// (p/q) I multiply either p pr q by a suitable power of 2 (by shifting
// left, so it is fairly cheap) so that the integer quotient (p div q)
// is a 24-bit number, ie the bit 0x01000000 is set. Note that I expect
// that ratios are always non-zero! The shift amount provides an exponent
// I will merge in later, and the remainder in the division lets me
// know if I should round up or down.

LispObject Float::op(Rat a)
{   LispObject p = a.numerator(),
               q = a.denominator();
    bool neg = Minusp::op(p);
    if (neg) p = Minus::op(p);
    size_t lp = IntegerLength::op(p),
           lq = IntegerLength::op(q);
    uint64_t ptop = Top64Bits::op(p),
             qtop = Top64Bits::op(q);
    int shift = lp - lq - 24;
    if (ptop < qtop) shift--;
// Now I am *almost* certain how to shift to get a 24-bit integer, but
// just occasionally I will be off by 1 and need to adjust.
    zprintf("Float::op %d %.16x %.16x\n", shift, ptop, qtop);
    return aerror("float of rat not coded yet");
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
// The implementation here relies on the result if Float::op(a) being
// a double float. Well at present this is BAD because a fixnum may be up
// to 2^59-1 and at that level conversion to a double involves some
// rounding. The later conversion to a short float may then round again,
// and the combined effect may be that rounding is not quite right!

// @@@@

LispObject Float::op(Fixnum a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// bignum FLOAT short float
// Ditto here @@@@

LispObject Float::op(uint64_t *a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// rational FLOAT short float
// This is a case where the ratio needs careful conversion to
// a short float. @@@@
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
// This is OK because the single float turns into a double without that
// introducing any corruption at all.

LispObject Float::op(Flt a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// double float FLOAT short float
LispObject Float::op(double a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// long float FLOAT short float
// Rounding again needs to be done in a single step. @@@@
LispObject Float::op(LFlt a, SFlt b)
{   return pack_short_float(double_float_val(Float::op(a)));
}

// fixnum FLOAT single float
// Rounding again needs to be done in a single step. @@@@
LispObject Float::op(Fixnum a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// bignum FLOAT single float
// Rounding again needs to be done in a single step. @@@@
LispObject Float::op(uint64_t *a, Flt b)
{   return pack_single_float(double_float_val(Float::op(a)));
}

// rational FLOAT single float
// Rounding again needs to be done in a single step. @@@@
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
// Rounding again needs to be done in a single step. @@@@
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
{   return make_boxfloat128(Float128::op(a));
}

// bignum FLOAT long float
LispObject Float::op(uint64_t *a, LFlt b)
{   return make_boxfloat128(Float128::op(a));
}

// rational FLOAT long float
LispObject Float::op(Rat a, LFlt b)
{   return make_boxfloat128(Float128::op(a));
}

// complex FLOAT long float
LispObject Float::op(Cpx a, LFlt b)
{   return make_boxfloat128(Float128::op(a));
}

// short float FLOAT long float
LispObject Float::op(SFlt a, LFlt b)
{   return make_boxfloat128(Float128::op(a));
}

// single float FLOAT long float
LispObject Float::op(Flt a, LFlt b)
{   return make_boxfloat128(Float128::op(a));
}

// double float FLOAT long float
LispObject Float::op(double a, LFlt b)
{   return make_boxfloat128(Float128::op(a));
}

// long float FLOAT long float
LispObject Float::op(LFlt a, LFlt b)
{   return make_boxfloat128(a.floatval());
}

float RawFloat32::op(LispObject a)
{   return number_dispatcher::unary<double,RawFloat32>("float32", a);
}

float RawFloat32::op(Fixnum a)
{   return arithlib_lowlevel::Float::op(a.intval());
}

float RawFloat32::op(uint64_t *a)
{   return arithlib_lowlevel::Float::op(a);
}

float RawFloat32::op(Rat a)
{   int64_t px, qx;
// The code here avoids problems with overflow but if I am worried about
// perfect rounding in every case I may need to do more.
    double p =
       number_dispatcher::unary<double,Frexp>("frexp", a.numerator(), px);
    double q =
       number_dispatcher::unary<double,Frexp>("frexp", a.denominator(), qx);
    return (float)std::ldexp(p/q, px-qx);
}

float RawFloat32::op(Cpx a)
{   aerror1("bad argument for float32", a.value());
    return 0.0;
}

float RawFloat32::op(SFlt a)
{   return a.floatval();
}

float RawFloat32::op(Flt a)
{   return a.floatval();
}

float RawFloat32::op(double a)
{   return a;
}

float RawFloat32::op(LFlt a)
{   float32_t f = f128_to_f32(a.floatval());
    return bit_cast<float>(f.v);
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
// The code here avoids problems with overflow but if I am worried about
// perfect rounding in every case I may need to do more.
    double p =
       number_dispatcher::unary<double,Frexp>("frexp", a.numerator(), px);
    double q =
       number_dispatcher::unary<double,Frexp>("frexp", a.denominator(), qx);
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

float128_t Float128::op(LispObject a)
{   //return
    //    number_dispatcher::unary<float128_t,Float128>("float128", a);
    return i64_to_f128(0);
}

float128_t Float128::op(Fixnum a)
{   return i64_to_f128(a.intval());
}

float128_t Float128::op(uint64_t *a)
{   return arithlib_lowlevel::Float128::op(a);
}

float128_t Float128::op(Rat a)
{   int64_t px=0, qx=0;
    float128_t p = Frexp128::op(a.numerator(), px);
    float128_t q = Frexp128::op(a.denominator(), qx);
// Again perfect rounding might mean I really need a bit more work.
    float128_t d = f128_div(p, q);
    f128_ldexp(&d, px-qx);
    return d;
}

float128_t Float128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
    return i64_to_f128(0);
}

float128_t Float128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t Float128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t Float128::op(double a)
{   double d = a;
    float64_t dd;
    std::memcpy(&dd, &d, sizeof(double));
    return f64_to_f128(dd);
}

float128_t Float128::op(LFlt a)
{   return a.floatval();
}

LispObject Fix::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Fix>("fix", a);
}

LispObject Fix::op(Fixnum a)
{   return a.value();
}

LispObject Fix::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>
                                   (a) - 8 + TAG_NUMBERS);
}

LispObject Fix::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Fix::op(Cpx a)
{   return aerror1("bad argument for fix", a.value());
}

LispObject Fix::op(SFlt a)
{   return arithlib_lowlevel::truncDoubleToInt(a.floatval());
}

LispObject Fix::op(Flt a)
{   return arithlib_lowlevel::truncDoubleToInt(a.floatval());
}

LispObject Fix::op(double a)
{   return arithlib_lowlevel::truncDoubleToInt(a);
}

LispObject Fix::op(LFlt a)
{   return arithlib_lowlevel::truncFloat128ToInt(a.floatval());
}

LispObject Truncate::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Truncate>("truncate", a);
}

LispObject Truncate::op(Fixnum a)
{   return a.value();
}

LispObject Truncate::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Truncate::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Truncate::op(Cpx a)
{   return aerror1("bad argument for trunc", a.value());
}

LispObject Truncate::op(SFlt a)
{   return arithlib_lowlevel::truncDoubleToInt(a.floatval());
}

LispObject Truncate::op(Flt a)
{   return arithlib_lowlevel::truncDoubleToInt(a.floatval());
}

LispObject Truncate::op(double a)
{   return arithlib_lowlevel::truncDoubleToInt(a);
}

LispObject Truncate::op(LFlt a)
{   return arithlib_lowlevel::truncFloat128ToInt(a.floatval());
}

LispObject Floor::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Floor>("floor", a);
}

LispObject Floor::op(Fixnum a)
{   return a.value();
}

LispObject Floor::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
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
{   return arithlib_lowlevel::floorDoubleToInt(a.floatval());
}

LispObject Floor::op(Flt a)
{   return arithlib_lowlevel::floorDoubleToInt(a.floatval());
}

LispObject Floor::op(double a)
{   return arithlib_lowlevel::floorDoubleToInt(a);
}

LispObject Floor::op(LFlt a)
{   return arithlib_lowlevel::floorFloat128ToInt(a.floatval());
}

LispObject Ceiling::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ceiling>("ceiling", a);
}

LispObject Ceiling::op(Fixnum a)
{   return a.value();
}

LispObject Ceiling::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>
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
{   return arithlib_lowlevel::ceilingDoubleToInt(a.floatval());
}

LispObject Ceiling::op(Flt a)
{   return arithlib_lowlevel::ceilingDoubleToInt(a.floatval());
}

LispObject Ceiling::op(double a)
{   return arithlib_lowlevel::ceilingDoubleToInt(a);
}

LispObject Ceiling::op(LFlt a)
{   return arithlib_lowlevel::ceilingFloat128ToInt(a.floatval());
}

LispObject Ftruncate::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ftruncate>("floor", a);
}

LispObject Ftruncate::op(Fixnum a)
{   return a.value();
}

LispObject Ftruncate::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>
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
{   return arithlib_lowlevel::truncDoubleToInt(a.floatval());
}

LispObject Ftruncate::op(Flt a)
{   return arithlib_lowlevel::truncDoubleToInt(a.floatval());
}

LispObject Ftruncate::op(double a)
{   return arithlib_lowlevel::truncDoubleToInt(a);
}

LispObject Ftruncate::op(LFlt a)
{   return arithlib_lowlevel::truncFloat128ToInt(a.floatval());
}

LispObject Ffloor::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Ffloor>("floor", a);
}

LispObject Ffloor::op(Fixnum a)
{   return a.value();
}

LispObject Ffloor::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Ffloor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Ffloor(Rat)")
}

LispObject Ffloor::op(Cpx a)
{   return aerror1("bad argument for floor", a.value());
}

LispObject Ffloor::op(SFlt a)
{   return arithlib_lowlevel::floorDoubleToInt(a.floatval());
}

LispObject Ffloor::op(Flt a)
{   return arithlib_lowlevel::floorDoubleToInt(a.floatval());
}

LispObject Ffloor::op(double a)
{   return arithlib_lowlevel::floorDoubleToInt(a);
}

LispObject Ffloor::op(LFlt a)
{   return arithlib_lowlevel::floorFloat128ToInt(a.floatval());
}

LispObject Fceiling::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Fceiling>("ceiling", a);
}

LispObject Fceiling::op(Fixnum a)
{   return a.value();
}

LispObject Fceiling::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Fceiling::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
#pragma message ("Fceiling(Rat)")
}

LispObject Fceiling::op(Cpx a)
{   return aerror1("bad argument for ceiling", a.value());
}

LispObject Fceiling::op(SFlt a)
{   return arithlib_lowlevel::ceilingDoubleToInt(a.floatval());
}

LispObject Fceiling::op(Flt a)
{   return arithlib_lowlevel::ceilingDoubleToInt(a.floatval());
}

LispObject Fceiling::op(double a)
{   return arithlib_lowlevel::ceilingDoubleToInt(a);
}

LispObject Fceiling::op(LFlt a)
{   return arithlib_lowlevel::ceilingFloat128ToInt(a.floatval());
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
    f128_frexp(d, &d, &x1);
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
{   int64_t xp=0;
    float128_t p = Frexp128::op(a.numerator(), xp);
    int64_t xq=0;
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

LispObject Frexp128::op(LFlt a)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0);
}

float128_t Frexp128::op(LispObject a, int64_t &xx)
{   //return number_dispatcher::unary<float128_t,Frexp128>("frexp128",
    //        a, xx);
    return i64_to_f128(0);
}

float128_t frexp_finalize(float128_t d, int x, int64_t &xx)
{   int x1;
    f128_frexp(d, &d, &x1);
    xx = x + x1;
    return d;
}

float128_t Frexp128::op(Fixnum a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

float128_t Frexp128::op(uint64_t *a, int64_t &xx)
{   int64_t x = 0;
    float128_t d = arithlib_lowlevel::Frexp128::op(a, x);
    return frexp_finalize(d, x, xx);
}

float128_t Frexp128::op(Rat a, int64_t &xx)
{   int64_t xp = 0;
    float128_t p = Frexp128::op(a.numerator(), xp);
    int64_t xq = 0;
    float128_t q = Frexp128::op(a.denominator(), xq);
    return frexp_finalize(f128_div(p, q), xp-xq, xx);
}

float128_t Frexp128::op(Cpx a, int64_t &xx)
{   aerror1("bad argument for frexp", a.value());
    return i64_to_f128(0);
}

float128_t Frexp128::op(SFlt a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

float128_t Frexp128::op(Flt a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

float128_t Frexp128::op(double a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

float128_t Frexp128::op(LFlt a, int64_t &xx)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0, xx);
}

LispObject Ldexp::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Ldexp>("ldexp", a,
            b);
}

LispObject Ldexp::op(Fixnum a, Fixnum b)
{   double d = std::ldexp(static_cast<double>(a.intval()), b.intval());
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
    f128_ldexp(&f, b.intval());
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
{   if (Minusp::op(b)) return make_boxfloat(a == a ? 0.0 : 0.0/0.0,
                                            WANT_DOUBLE_FLOAT);
    double d = std::ldexp(a, 100000000);
    return make_boxfloat(d);
}

// I am not dealing with a NaN in the float128 case at present.

LispObject Ldexp::op(LFlt a, uint64_t *b)
{   if (Minusp::op(b)) return make_boxfloat128(i64_to_f128(0));
    float128_t f = a.floatval();
    f128_ldexp(&f, 100000000);
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
{   return aerror1("bad argument for isqrt", make_boxfloat128(a.value()));
}

LispObject Nfp_infinite(LispObject env, LispObject a)
{   SingleValued fn;
    switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (std::fpclassify(value_of_immediate_float(a)) == FP_INFINITE)
                return lisp_true;
            return nil;
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128_infinitep(*reinterpret_cast<float128_t *>(&long_float_val(
                                           a))))
                        return lisp_true;
                    return nil;
#endif // HAVE_SOFTFLOAT
                case SINGLE_FLOAT_HEADER:
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_INFINITE)
                        return lisp_true;
                    return nil;
            }
        default:
            break;
    }
    return nil;
}


LispObject Nfp_nan(LispObject env, LispObject a)
{   SingleValued fn;
    switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (std::fpclassify(value_of_immediate_float(a)) == FP_NAN)
                return lisp_true;
            return nil;
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    if (std::fpclassify(single_float_val(a)) == FP_NAN)
                        return lisp_true;
                    return nil;
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128_nanp(*reinterpret_cast<float128_t *>(&long_float_val(a))))
                        return lisp_true;
                    return nil;
#endif // HAVE_SOFTFLOAT
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_NAN)
                        return lisp_true;
                    return nil;
            }
        default:
            break;
    }
    return nil;
}

LispObject Nfp_finite(LispObject env, LispObject a)
{   SingleValued fn;
    switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (std::isfinite(value_of_immediate_float(a)))
                return lisp_true;
            return nil;
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128_finite(*reinterpret_cast<float128_t *>(&long_float_val(a))))
                        return lisp_true;
                    return nil;
#endif // HAVE_SOFTFLOAT
                case SINGLE_FLOAT_HEADER:
                    if (std::isfinite(single_float_val(a)))
                        return lisp_true;
                    return nil;
                case DOUBLE_FLOAT_HEADER:
                    if (std::isfinite(double_float_val(a)))
                        return lisp_true;
                    return nil;
            }
        default:
            break;
    }
    return nil;
}

LispObject Nfp_subnorm(LispObject env, LispObject a)
{   SingleValued fn;
    switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
        {   if (std::fpclassify(value_of_immediate_float(a)) == FP_SUBNORMAL)
                return  lisp_true;
            else return nil;
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    if (std::fpclassify(single_float_val(a)) == FP_SUBNORMAL)
                        return  lisp_true;
                    else return nil;
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    if (f128_subnorm(*reinterpret_cast<float128_t *>(&long_float_val(a))))
                        return lisp_true;
                    return nil;
#endif // HAVE_SOFTFLOAT
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_SUBNORMAL)
                        return  lisp_true;
                    else return nil;
            }
        default:
            break;
    }
    return nil;
}

// This will return T if its argument has its sign bit set. Note that this
// NOT the same a test (x < 0) because this function returns T for -0.0.

// C++ is expected to have std::signbit, so I will always use it. Without
// it I will not cope properly with signed zeros.

#define HAVE_SIGNBIT 1

LispObject Nfp_signbit(LispObject env, LispObject a)
{   SingleValued fn;
    switch (static_cast<int>(a) & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if ((intptr_t)a < 0) return lisp_true;
            else return nil;
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return std::signbit(single_float_val(a)) ? lisp_true : nil;
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    return f128_negative(
                        *reinterpret_cast<float128_t *> (&long_float_val(a))) ?
                        lisp_true : nil;
#endif // HAVE_SOFTFLOAT
                case DOUBLE_FLOAT_HEADER:
                    return std::signbit(double_float_val(a)) ? lisp_true : nil;
            }
        default:
            break;
    }
    return nil;
}


// The functions such as float-digits, float-precision, float-radix are
// coded here assuming that IEEE-style arithmetic is being used. If this is
// not so then all the code in this file needs review.  Furthermore I will
// be lazy about NaNs and denormalised numbers for now and come back to
// worry about them later on if I am really forced to.

LispObject Nfloat_digits(LispObject env, LispObject a)
{   SingleValued fn;
    int tag = static_cast<int>(a) & XTAG_BITS;
    switch (tag)
    {   case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return fixnum_of_int(24);
            else return fixnum_of_int(20);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return fixnum_of_int(24);
                case DOUBLE_FLOAT_HEADER:
                    return fixnum_of_int(53);
                case LONG_FLOAT_HEADER:
                    return fixnum_of_int(113);
            }
        default:
            return aerror("float-digits");
    }
}

LispObject Nfloat_precision(LispObject env, LispObject a)
{   SingleValued fn;
    int tag = static_cast<int>(a) & XTAG_BITS;
    double d = float_of_number(a);
    if (d == 0.0) return fixnum_of_int(0);
    switch (tag)
    {   case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return fixnum_of_int(24);
            else return fixnum_of_int(20);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return fixnum_of_int(24);
                case DOUBLE_FLOAT_HEADER:
                    return fixnum_of_int(53);
                case LONG_FLOAT_HEADER:
                    return fixnum_of_int(113);
            }
        default:
            return aerror("float-precision");
    }
}

// In CSL all floats use the same radix (2) and so the function to
// find the radix does not need to look at its argument.

LispObject Nfloat_radix(LispObject env, LispObject a2)
{   SingleValued fn;
    return fixnum_of_int(FLT_RADIX);
}

LispObject Nfloat_sign2(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(b) &&
        flthdr(b) == LONG_FLOAT_HEADER)
    {   float128_t d = float128_of_number(b);
// If a is another long float then float_of_number may overflow, but
// here I am only interested in its sign, and -infinity is still negative.
        if (float_of_number(a) < 0.0) f128_negate(&d);
        return make_boxfloat128(d);
    }
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(b);
// Worry a bit about -0.0 here
    if (float_of_number(a) < 0.0) d = -d;
    if (is_sfloat(b)) return pack_immediate_float(d, b);
    else if (!is_bfloat(b)) return aerror1("bad arg for float-sign",  b);
// make_boxfloat may detect infinity or NaN.
    else return make_boxfloat(d, floatWant(flthdr(b)));
}

LispObject Nfloat_sign1(LispObject env, LispObject a)
{   SingleValued fn;
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(1) &&
        flthdr(a) == LONG_FLOAT_HEADER)
    {   float128_t d = float128_of_number(a);
        float128_t r = f128_1;
        if (f128_negative(d)) f128_negate(&r);
        return make_boxfloat128(r);
    }
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
// worry a bit about -0.0 here
    if (d < 0.0) d = -1.0;
    else d = 1.0;
    if (is_sfloat(a)) return pack_immediate_float(d, a);
    else if (!is_bfloat(a)) return aerror1("bad arg for float-sign",  a);
    else return make_boxfloat(d, floatWant(flthdr(a)));
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
{   SingleValued fn;
    int n = 0;
    double w;
    unsigned char *p;
    if (!is_vector(code)) return aerror("fp-evaluate");
    while (consp(args))
    {   fp_args[n++] = float_of_number(car(args));
        if (n >= 32) return aerror("too many args in fp-evaluate");
        args = cdr(args);
    }
    n = 0;
    p = reinterpret_cast<unsigned char *>(&ucelt(code, 0));
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
                return args;
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
{   SingleValued fn;
    bool o = trap_floating_overflow;
    trap_floating_overflow = (a != nil);
    return Lispify_predicate(o);
}

LispObject Nround(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    if (!is_number(a) || !is_number(b)) return aerror1("round", a);
    return Nlisp_ifix(a, b, FIX_ROUND);
}

#ifdef HAVE_SOFTFLOAT

// long float version of the following function. Commentary is in the
// double precision version.

static LispObject Nlisp_fix_sub128(LispObject a, int roundmode)
{   float128_t *d = reinterpret_cast<float128_t *>(long_float_addr(a));
    if (f128_nanp(*d)) return aerror("NaN in fix");
    if (f128_infinitep(*d)) return aerror("infinity in fix");
    int x = f128_exponent(*d);
// Here I will limit the range where I convert to directly to a
// 64-bit integer. I make this a slightly lower limit than I applied
// when converting 64-bit floats because here the float128_t could be
// really really close to the integer limit and so might overflow on
// rounding the conversion.
    if (x < 62)
    {   int64_t n = f128M_to_i64(d, roundmode, false);
// Here the softfloat library does rounding for me. Hoorah!
        return make_lisp_integer64(n);
    }
// Now I know that the result will be at least a 62-bit integer.
    float128_t d2;
    f128_frexp(*d, &d2, &x);
    uint64_t hi, lo;
    f128_mantissa(d2, hi, lo);
    int128_t ii = (static_cast<uint128_t>(hi | 0x1000000000000ULL)<<64) | lo;
    if (f128_negative(*d)) ii = -ii;
    x -= 113;
// Now the result needs to be shifted left by x bits. Well if x<0 it needs to
// shift right and in that case I need to think about rounding modes.
    if (x < 0)      // consider rounding. 
    {   uint128_t frac = ii << (128+x);
        const uint128_t topBit = static_cast<uint128_t>(1)<<127;
        ii = ii >> x;
        switch (roundmode)
        {   default:
            case FIX_TRUNCATE:
// I am still in sign and magnitude mode so the right shift serves to truncate.
                        break;
            case FIX_ROUND:
                        if (frac > topBit ||
                            (frac == topBit && (ii&1) != 0)) ii++;
                        break;
            case FIX_FLOOR:
                        if (frac != 0 && f128_negative(*d)) ii++;
                        break;
            case FIX_CEILING:
                        if (frac != 0 && !f128_negative(*d)) ii++;
                        break;
        }
        if (f128_negative(*d)) ii = -ii;
        return make_lisp_integer128(ii);
    }
    return LeftShift::op(make_lisp_integer128(ii), fixnum_of_int(x));
}

#endif // HAVE_SOFTFLOAT

// This converts from a double to a Lisp integer, which will
// quite often have to be a bignum.  No overflow is permitted - the
// result can always be accurate, save that infinities and NaNs must
// be rejected.

static LispObject Nlisp_fix_sub(LispObject a, int roundmode)
{
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Nlisp_fix_sub128(a, roundmode);
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
    if (std::isnan(d)) return aerror("NaN in fix");
    if (std::isinf(d)) return aerror("infinity in fix");
// I will take a cheaper path if d is such that I can cast it to a 64-bit
// integer without that causing (integer) overflow.
    if (d >= static_cast<double>(INT64_MIN) &&
        d < -static_cast<double>(INT64_MIN))
    {   int64_t n = static_cast<int64_t>(d);
// Here the absolute value of d was strictly smaller than 2^63 and it
// was truncated towards zero in the conversion to an integer, so n
// is a value that would fit in a 64-bit integer. Fixing the rounding mode
// can only possibly change its value by +1 or -1, and that means that the
// only imaginable possibility for overflow is if it starts of as
// 0x7fffffffffffffff and has to be rounded up. But because doubles only have
// 53 bits of mantissa any that are close to the ends of the range of 64-bit
// integers will convert exactly to integers without any need for rounding.
        double f;   // For the fraction part that is left over...
        switch (roundmode)
        {   default:
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
// Now I know that the result will be at least a 63-bit integer, and is
// going to end up as a bignum. I am going to favour simplicity and
// code clarity over performance here! In these cases there is no
// rounding in the conversion and so no need to consider rounding modes.
    int x;
    double d1 = frexp(d, &x);
// now d is in the range +- [0.5,1) and pne wpi;d need to multiply by
// 2^x to recover the original value;
    double d2 = std::ldexp(d1, 55);   x -= 55;
// Now d3 is in the range +- [2^54, 2^55) and so can be converted to
// a 64-bit integer without any rounding. And x is the amount this
// needs to be shifted left to yield the final result...
    return LeftShift::op(make_lisp_integer64(static_cast<int64_t>(d2)),
                         fixnum_of_int(x));
}

// This converts from a ratio to a Lisp integer.  It has to apply
// rounding in the desired direction.

LispObject Nlisp_fix_ratio(LispObject a, int roundmode)
{   LispObject p = numerator(a), q = denominator(a), q1, r1, w;
    q1 = Quotient::op(p, q);
    errexit();
    r1 = Remainder::op(p, q);
    errexit();
// The quotient is now in q1 and the remainder in r1. The original fraction
// is still (p/q).
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
// Here r1 is the eventual remainder. If it is less then -q/2 or greater
// then q/2 I will need to adjust things. And if it is equal in either of
// those edge cases I need to think even harder!
            w = Times::op(r1, fixnum_of_int(2));
            errexit();
            if (Minusp::op(w)) w = Minus::op(w);
            errexit();
            if (Greaterp::op(w, q) ||
                (Eqn::op(w, q) && Oddp::op(q1)))
            {   if (Minusp::op(r1))
                {   r1 = Plus::op(r1, q);
                    errexit();
                    q1 = Sub1::op(q1);
                }
                else
                {   r1 = Difference::op(r1, q);
                    errexit();
                    q1 = Add1::op(q1);
                }
                errexit();
            }
            break;
        case FIX_FLOOR:
            if (Minusp::op(r1))
            {   r1 = Plus::op(r1, q);
                errexit();
                q1 = Sub1::op(q1);
                errexit();
            }
            break;
        case FIX_CEILING:
            if (Plusp::op(r1))
            {   r1 = Difference::op(r1, q);
                errexit();
                q1 = Add1::op(q1);
                errexit();
            }
            break;
    }
    mv_2 = r1;
    return nvalues(q1, 2);
}

// This fixes a value a and returns (a - fix(a)) as a second result. This is
// only ever called with a floating point argument.

LispObject Nlisp_fix(LispObject a, int roundmode)
{
    LispObject r = Nlisp_fix_sub(a, roundmode);
    errexit();
    a = Difference::op(a, r);
    errexit();
    mv_2 = a;
    return nvalues(r, 2);
}

// ifix is for the 2-arg variants of floor, truncate, round etc. For
// floating point values a and b it computes fix(a/b) and the residue
// returned as a second value is b times the residue in that fix operation.

LispObject Nlisp_ifix(LispObject a, LispObject b, int roundmode)
{
    LispObject r2, negb;
    if (is_float(a) || is_float(b))
    {   a = Quotient::op(a, b);
        errexit();
// If either argument was floating point then the quotient will be.
        LispObject r = Nlisp_fix(a, roundmode);
        mv_2 = Times::op(mv_2, b);
        errexit();
        return nvalues(r, 2);
    }
    LispObject q = Quotient::op(a, b);
    errexit();
    LispObject r = Remainder::op(a, b);
    errexit();
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
// I will apply a round-to-nearest, with round-to-even to break ties.
            negb = Minus::op(b);
            {   r2 = Times::op(r, fixnum_of_int(2));
                errexit();
            }
            if (Lessp::op(b, r2) ||
                (Eqn::op(b, r2) && Oddp::op(q))) goto increase_q;
            if (Lessp::op(r2, negb) ||
                (Eqn::op(r2, negb) && Oddp::op(q))) goto decrease_q;
            break;
        case FIX_FLOOR:
            if (!Minusp::op(r)) break;
        decrease_q:
            r = Plus::op(r, b);
            errexit();
            q = Sub1::op(q);
            errexit();
            break;
        case FIX_CEILING:
            if (!Plusp::op(r)) break;
        increase_q:
            r = Difference::op(r, b);
            errexit();
            q = Add1::op(q);
            errexit();
            break;
    }
    mv_2 = r;
    return nvalues(q, 2);
}

LispObject Nround(LispObject env, LispObject a)
{   SingleValued fn;
    if (!is_number(a)) return aerror1("round", a);
    if (is_numbers(a) && is_ratio(a)) return Nlisp_fix_ratio(a, FIX_ROUND);
    if (is_float(a)) return Nlisp_fix(a, FIX_ROUND);
    mv_2 = fixnum_of_int(0);
    return nvalues(a, 2);
}

LispObject Nfround(LispObject env, LispObject a1)
{   SingleValued fn;
    return aerror("fround");
}

LispObject Nfround(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return aerror("fround");
}

#ifdef HAVE_SOFTFLOAT

LispObject Nscale_float128(LispObject a, intptr_t x)
{   float128_t d = long_float_val(a);
    if (f128_nanp(d)) return a;
    if (x >= 0x40000) x = 0x40000;
    else if (x <= -0x40000) x = -0x40000;
    if (f128_subnorm(d))
    {   f128M_mul(&d, &f128_N1, &d);
        x -= 4096;
    }
    x += f128_exponent(d);
    if (x >= 0x7fff)         // result will be infinite
        f128_make_infinite(&d);
    else if (x <= 0)         // result underflows
    {   if (x < -113) f128_make_zero(&d);
        else
        {   f128_set_exponent(&d, x+4096);
// If there is a risk I need to generate a subnormal result do it this way.
            f128M_div(&d, &f128_N1, &d);
        }
    }
    else f128_set_exponent(&d, x);
    return make_boxfloat128(d);
}

#endif // HAVE_SOFTFLOAT

LispObject Nscale_float(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    if (!is_fixnum(b)) return aerror("scale-float");
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
    if (is_sfloat(a)) return pack_immediate_float(d, a);
    else if (!is_bfloat(a)) return aerror1("bad arg for scale-float",  a);
    else return make_boxfloat(d, floatWant(flthdr(a)));
}

LispObject Nfloat(LispObject env, LispObject a1)
{   SingleValued fn;
    return Float::op(a1);
}

LispObject Nfloat(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Float::op(a1, a2);
}

LispObject Nfix(LispObject env, LispObject a1)
{   SingleValued fn;
    return Fix::op(a1);
}

LispObject Ntruncate(LispObject env, LispObject a1)
{   SingleValued fn;
    return Truncate::op(a1);
}

LispObject Nfloor(LispObject env, LispObject a1)
{   SingleValued fn;
    return Floor::op(a1);
}

LispObject Nceiling(LispObject env, LispObject a1)
{   SingleValued fn;
    return Ceiling::op(a1);
}

LispObject Nftruncate(LispObject env, LispObject a1)
{   SingleValued fn;
    return Ftruncate::op(a1);
}

LispObject Nffloor(LispObject env, LispObject a1)
{   SingleValued fn;
    return Ffloor::op(a1);
}

LispObject Nfceiling(LispObject env, LispObject a1)
{   SingleValued fn;
    return Fceiling::op(a1);
}

LispObject Ntruncate(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Truncate::op(a1, a2);
}

LispObject Nfloor(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Floor::op(a1, a2);
}

LispObject Nceiling(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Ceiling::op(a1, a2);
}

LispObject Nftruncate(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Ftruncate::op(a1, a2);
}

LispObject Nffloor(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Ffloor::op(a1, a2);
}

LispObject Nfceiling(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Fceiling::op(a1,  a2);
}

LispObject Nfloat128(LispObject env, LispObject a1)
{   SingleValued fn;
    return make_boxfloat128(Float128::op(a1));
}

LispObject Nfrexp(LispObject env, LispObject a1)
{   SingleValued fn;
    return Frexp::op(a1);
}

LispObject Nldexp(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Ldexp::op(a1, a2);
}

LispObject Nmodf(LispObject env, LispObject a1)
{   SingleValued fn;
    float fi, ff;
    double di, df;
    float128_t li, lf;
    switch (a1 & XTAG_BITS)
    {   default:
            return cons(a1, make_boxfloat(0.0));
        case XTAG_SFLOAT:   // float28 or perhaps float32
            ff = std::modf(value_of_immediate_float(a1), &fi);
            if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0))
                return cons(pack_single_float(fi), pack_single_float(ff));
            else return cons(pack_short_float(fi), pack_short_float(ff));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a1))
        {       default:
                    return aerror("badly formatted float data");
                case SINGLE_FLOAT_HEADER:
                    ff = std::modf(single_float_val(a1), &fi);
                    return cons(pack_single_float(fi), pack_single_float(ff));
                case DOUBLE_FLOAT_HEADER:
                    df = std::modf(double_float_val(a1), &di);
                    return cons(make_boxfloat(di), make_boxfloat(df));
                case LONG_FLOAT_HEADER:
                    lf = arithlib_lowlevel::modf(long_float_val(a1), li);
                    return cons(make_boxfloat128(li), make_boxfloat128(lf));
            }
    }
}

#ifdef HAVE_SOFTFLOAT

LispObject Ndecode_long_float(LispObject a)
{   float128_t d = long_float_val(a);
    if (f128_infinitep(d) || f128_nanp(d))
    {   if (trap_floating_overflow) return aerror("decode-float");
        else return nil; // infinity or NaN
    }
    bool neg = false;
    int x = 0;
    if (f128_negative(d)) f128_negate(&d), neg = true;
    if (f128M_eq(&d, &f128_0)) x = 0;
    else
    {   if (f128_subnorm(d))
        {   f128M_mul(&d, &f128_N1, &d);
            x -= 4096;
        }
        x += f128_exponent(d) - 0x3fff;
        f128_set_exponent(&d, 0x3fff);
    }
    LispObject sign = make_boxfloat128(f128_1);
    if (neg) f128_negate(reinterpret_cast<float128_t *>(long_float_addr(sign)));
    {   a = make_boxfloat128(d);
        errexit();
    }
#ifdef COMMON
// Until and unless Standard Lisp supports multiple values this has to
// return a list in standard lisp mode.
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
#else
    return list3(sign, fixnum_of_int(x), a);
#endif
}
#endif // HAVE_SOFTFLOAT

LispObject Ndecode_float(LispObject env, LispObject a)
{   SingleValued fn;
    double d, neg = 1.0;
    int x;
    LispObject sign;
    if (!is_float(a)) return aerror("decode-float");
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Ndecode_long_float(a);
#endif // HAVE_SOFTFLOAT
    d = float_of_number(a);
    if (floating_edge_case(d))
    {   if (trap_floating_overflow) return aerror("decode-float");
        else return nil; // infinity or NaN
    }
// Ha ha ha - I detect -0.0 here.
    if (d < 0.0 || (d == 0.0 && 1.0/d < 0)) d = -d, neg = -1.0;
    if (d == 0.0) x = 0;
    else d = std::frexp(d, &x);
    if (is_sfloat(a)) sign = pack_immediate_float(neg, a);
    else sign = make_boxfloat(neg, floatWant(flthdr(a)));
    {   if (is_sfloat(a)) a = pack_immediate_float(d, a);
        else a = make_boxfloat(d, floatWant(flthdr(a)));
        errexit();
    }
#ifdef COMMON
// Until and unless Standard Lisp supports multiple values this has to
// return a list in standard lisp mode.
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
#else
    return list3(sign, fixnum_of_int(x), a);
#endif
}

#ifdef HAVE_SOFTFLOAT

LispObject Ninteger_decode_long_float(LispObject a)
{   float128_t d = long_float_val(a);
    if (f128_infinitep(d) || f128_nanp(d))
    {   if (trap_floating_overflow) return aerror("integer-decode-float");
        else return nil; // infinity or NaN
    }
    if (f128M_eq(&d, &f128_0))
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(f128_negative(d) ? -1 : 1);
        nvalues(fixnum_of_int(0), 3);
    }
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(f128_negative(d) ? -1 : 1));
#endif
    bool neg = false;
    if (f128_negative(d))
    {   f128_negate(&d);
        neg = true;
    }
    uint64_t hi, lo;
    f128_mantissa(d, hi, lo);
    int x = f128_exponent(d);
    a = make_lisp_integer128((static_cast<int128_t>(hi)<<64) | lo);
#ifdef COMMON
    {   mv_2 = fixnum_of_int(x);
        mv_3 = neg ? fixnum_of_int(-1) : fixnum_of_int(1);
        return nvalues(a, 3);
    }
#else
    return list3(a, fixnum_of_int(x),
                 neg ? fixnum_of_int(-1) : fixnum_of_int(1));
#endif // COMMON
}

#endif // HAVE_SOFTFLOAT

LispObject Ninteger_decode_float(LispObject env, LispObject a)
{   SingleValued fn;
    double d;
    if (!is_float(a)) return aerror("integer-decode-float");
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Ninteger_decode_long_float(a);
#endif // HAVE_SOFTFLOAT
    d = float_of_number(a);
    if (floating_edge_case(d))
    {   if (trap_floating_overflow) return aerror("integer-decode-float");
        else return nil; // infinity or NaN
    }
    if (d == 0.0)
    {
#ifdef COMMON
        mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(1.0/d < 0.0 ? -1 : 1);
        return nvalues(fixnum_of_int(0), 3);
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(1.0/d < 0.0 ? -1 : 1));
#endif
    }
    bool neg = 0;
    if (d < 0.0)
    {   d = -d;
        neg = true;
    }
    int x;
    d = frexp(d, &x);
    a = make_lisp_integer64(static_cast<int64_t>(
        d*16384.0*16384.0*16384.9*32.0));
    x -= 63;
#ifdef COMMON
    mv_2 = fixnum_of_int(x);
    mv_3 = neg ? fixnum_of_int(-1) : fixnum_of_int(1);
    return nvalues(a, 3);
#else
    return list3(a, fixnum_of_int(x),
                 neg ? fixnum_of_int(-1) : fixnum_of_int(1));
#endif
}

#endif // ARITHLIB

// end of arith-float.cpp
