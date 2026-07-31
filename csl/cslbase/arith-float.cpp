// arith-float.cpp                         Copyright (C) 2022-2026 Codemist

#ifdef ARITHLIB

// $Id$


/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

namespace CSL_LISP
{

using namespace arithlib_implementation;

// For short and single and double floats I pass values around as doubles.
// This is what C++ typically does! Long floats will be passed using
// FLOAT_128. The relevant floating point representations are:
//   short    20 bit mantissa 8 bit exponent
//   single   24 bit mantissa 8 bit exponent
//   double   53 bit mantissa 11 bit exponent
//   long    113 bit mantissa 15 bit exponent 

// I can move to the next-following or the previous floating point value
// in each representation by incrementing or decrementing the integer
// representation (taking care not to adjust an infinity or a NaN)

double short_next_float(double a)
{   if (!isfinite(a)) return a;
    return bit_cast<double>(bit_cast<uint64_t>(a) + 0x00000010'00000000);
}

double single_next_float(double a)
{   if (!isfinite(a)) return a;
    return bit_cast<double>(bit_cast<uint64_t>(a) + 0x00000001'00000000);
}

double double_next_float(double a)
{   if (!isfinite(a)) return a;
    return bit_cast<double>(bit_cast<uint64_t>(a) + 0x00000000'00000001);
}

FLOAT_128 long_next_float(FLOAT_128 a)
{   if (!isfinite(a)) return a;
    return FLOAT_128(a.getbits() + 1, i128());
}

double short_previous_float(double a)
{   if (!isfinite(a)) return a;
    return bit_cast<double>(bit_cast<uint64_t>(a) - 0x00000010'00000000);
}

double single_previous_float(double a)
{   if (!isfinite(a)) return a;
    return bit_cast<double>(bit_cast<uint64_t>(a) - 0x00000001'00000000);
}

double double_previous_float(double a)
{   if (!isfinite(a)) return a;
    return bit_cast<double>(bit_cast<uint64_t>(a) - 0x00000000'00000001);
}

FLOAT_128 long_previous_float(FLOAT_128 a)
{   if (!isfinite(a)) return a;
    return FLOAT_128(a.getbits() - 1, i128());
}

// Now I will need to handle round, truncate, floor and ceiling.
// Each of these functions compute a/b with the particular rounding mode
// and leave a remainder in f_remainder or lf_remainder.
// The remainder will be suitable for the same width of float as is
// indicated by the function name.

double f_remainder;
FLOAT_128 lf_remainder;

double short_round(double a, double b)
{   double q = round_to_short(a/b);
    f_remainder = round_to_short(fma(-q, b, a));
    return q; 
}

double single_round(double a, double b)
{   double q = round_to_single(a/b);
    f_remainder = round_to_single(fma(-q, b, a));
    return q; 
}

double double_round(double a, double b)
{   double q = a/b;
    f_remainder = fma(-q, b, a);
    return q; 
}

FLOAT_128 long_round(FLOAT_128 a, FLOAT_128 b)
{   FLOAT_128 q = a/b;
    lf_remainder = fma(-q, b, a);
    return q; 
}

double short_floor(double a, double b)
{   double q = round_to_short(a/b);
    f_remainder = round_to_short(fma(-q, b, a));
    if (f_remainder > 0.0)
    {   q = short_previous_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    return q; 
}

double single_floor(double a, double b)
{   double q = round_to_single(a/b);
    f_remainder = round_to_single(fma(-q, b, a));
    if (f_remainder > 0.0)
    {   q = single_previous_float(q);
        f_remainder = round_to_single(fma(-q, b, a));
    }
    return q; 
}

double double_floor(double a, double b)
{   double q = a/b;
    f_remainder = fma(-q, b, a);
    if (f_remainder > 0.0)
    {   q = double_previous_float(q);
        f_remainder = fma(-q, b, a);
    }
    return q; 
}

FLOAT_128 long_floor(FLOAT_128 a, FLOAT_128 b)
{   FLOAT_128 q = a/b;
    lf_remainder = fma(-q, b, a);
    if (lf_remainder > LF_C(0.0))
    {   q = long_previous_float(q);
        f_remainder = fma(-q, b, a);
    }
    return q; 
}

double short_ceiling(double a, double b)
{   double q = round_to_short(a/b);
    f_remainder = round_to_short(fma(-q, b, a));
    if (f_remainder < 0.0)
    {   q = short_next_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    return q; 
}

double single_ceiling(double a, double b)
{   double q = round_to_single(a/b);
    f_remainder = round_to_single(fma(-q, b, a));
    if (f_remainder < 0.0)
    {   q = single_next_float(q);
        f_remainder = round_to_single(fma(-q, b, a));
    }
    return q; 
}

double double_ceiling(double a, double b)
{   double q = a/b;
    f_remainder = fma(-q, b, a);
    if (f_remainder < 0.0)
    {   q = double_next_float(q);
        f_remainder = fma(-q, b, a);
    }
    return q; 
}

FLOAT_128 long_ceiling(FLOAT_128 a, FLOAT_128 b)
{   FLOAT_128 q = a/b;
    lf_remainder = fma(-q, b, a);
    if (lf_remainder < LF_C(0.0))
    {   q = long_next_float(q);
        f_remainder = fma(-q, b, a);
    }
    return q; 
}

double short_trunc(double a, double b)
{   double q = round_to_short(a/b);
    f_remainder = round_to_short(fma(-q, b, a));
    if (q < 0.0 && f_remainder < 0.0)
    {   q = short_next_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    else if (q > 0.0 && f_remainder > 0.0)
    {   q = short_previous_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    return q; 
}

double single_trunc(double a, double b)
{   double q = round_to_single(a/b);
    f_remainder = round_to_single(fma(-q, b, a));
    if (q < 0.0 && f_remainder < 0.0)
    {   q = single_next_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    else if (q > 0.0 && f_remainder > 0.0)
    {   q = single_previous_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    return q; 
}

double double_trunc(double a, double b)
{   double q = a/b;
    f_remainder = fma(-q, b, a);
    if (q < 0.0 && f_remainder < 0.0)
    {   q = double_next_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    else if (q > 0.0 && f_remainder > 0.0)
    {   q = double_previous_float(q);
        f_remainder = round_to_short(fma(-q, b, a));
    }
    return q; 
}

FLOAT_128 long_trunc(FLOAT_128 a, FLOAT_128 b)
{   FLOAT_128 q = a/b;
    lf_remainder = fma(-q, b, a);
    if (q < LF_C(0.0) && f_remainder < LF_C(0.0))
    {   q = long_next_float(q);
        lf_remainder = round_to_short(fma(-q, b, a));
    }
    else if (q > LF_C(0.0) && f_remainder > LF_C(0.0))
    {   q = long_previous_float(q);
        lf_remainder = round_to_short(fma(-q, b, a));
    }
    return q; 
}

LispObject Float::op(LispObject a)
{   return unary<LispObject,Float>("float", a);
}

// A mere cast to double here would not guarantee the floor-ing mode in
// cases that the integer was longer than 52 bits.

LispObject Float::op(Fixnum a)
{   return make_boxfloat(Double::op(a.intval()));
}

// In this next one note that arithlib has a class Float that converts
// to a C++ float and a separate one called Double that converts to a
// C++ double and hence is what I need here!

LispObject Float::op(uint64_t *a)
{   return make_boxfloat(Double::op(a));
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
{   double d = (double)a.floatval();
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
{   return binary<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Fixnum b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, uint64_t *b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Rat b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Cpx b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, SFlt b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, Flt b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, double b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(LispObject a, LFlt b)
{   return binaryR<LispObject,Float>("float", a, b);
}

LispObject Float::op(Fixnum a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(uint64_t *a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(Rat a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(Cpx a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(SFlt a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(Flt a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(double a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
}

LispObject Float::op(LFlt a, LispObject b)
{   return binaryL<LispObject,Float>("float", a, b);
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

// Note that here we go LFly => double => short_float so the rounding is
// done in two steps, which is not always correct.

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
{   return unary<double,RawFloat32>("float32", a);
}

float RawFloat32::op(Fixnum a)
{   return Float::op(a.intval());
}

float RawFloat32::op(uint64_t *a)
{   return Float::op(a);
}

float RawFloat32::op(Rat a)
{   int64_t px, qx;
// The code here avoids problems with overflow but if I am worried about
// perfect rounding. I may need to do more.
    double p =
       unary<double,Frexp>("frexp", a.numerator(), px);
    double q =
       unary<double,Frexp>("frexp", a.denominator(), qx);
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
{   return (float)a;
}

float RawFloat32::op(LFlt a)
{   return (float)a.floatval();
}

double RawFloat::op(LispObject a)
{   return unary<double,RawFloat>("float", a);
}

double RawFloat::op(Fixnum a)
{   return Double::op(a.intval());
}

double RawFloat::op(uint64_t *a)
{   return Double::op(a);
}

double RawFloat::op(Rat a)
{   int64_t px, qx;
// The code here avoids problems with overflow but if I am worried about
// perfect rounding.
    double p =
       unary<double,Frexp>("frexp", a.numerator(), px);
    double q =
       unary<double,Frexp>("frexp", a.denominator(), qx);
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
{   return (double)a.floatval();
}

FLOAT_128 Float128::op(LispObject a)
{   return unary<FLOAT_128,Float128>("float128", a);
}

FLOAT_128 Float128::op(Fixnum a)
{   return (FLOAT_128)(int128_t)a.intval();
}

FLOAT_128 Float128::op(uint64_t *a)
{   return arithlib_implementation::Float128::op(a);
}

FLOAT_128 Float128::op(Rat a)
{   int64_t px=0, qx=0;
    FLOAT_128 p = Frexp128::op(a.numerator(), px);
    FLOAT_128 q = Frexp128::op(a.denominator(), qx);
// Again perfect rounding might mean I really need a bit more work.
    FLOAT_128 d = p / q;
    return ldexp(d, px-qx);
}

FLOAT_128 Float128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
    return LF_C(0.0);
}

FLOAT_128 Float128::op(SFlt a)
{   double d = a.floatval();
    return (FLOAT_128)d;
}

FLOAT_128 Float128::op(Flt a)
{   double d = a.floatval();
    return (FLOAT_128)d;
}

FLOAT_128 Float128::op(double a)
{   return (FLOAT_128)a;
}

FLOAT_128 Float128::op(LFlt a)
{   return a.floatval();
}

LispObject Fix::op(LispObject a)
{   return unary<LispObject,Fix>("fix", a);
}

LispObject Fix::op(Fixnum a)
{   return a.value();
}

LispObject Fix::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(
               reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Fix::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Fix::op(Cpx a)
{   return aerror1("bad argument for fix", a.value());
}

LispObject Fix::op(SFlt a)
{   return truncDoubleToInt(a.floatval());
}

LispObject Fix::op(Flt a)
{   return truncDoubleToInt(a.floatval());
}

LispObject Fix::op(double a)
{   return truncDoubleToInt(a);
}

LispObject Fix::op(LFlt a)
{   return truncFloat128ToInt(a.floatval());
}

LispObject Truncate::op(LispObject a)
{   return unary<LispObject,Truncate>("truncate", a);
}

LispObject Truncate::op(Fixnum a)
{   return a.value();
}

LispObject Truncate::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(
               reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Truncate::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Truncate::op(Cpx a)
{   return aerror1("bad argument for trunc", a.value());
}

LispObject Truncate::op(SFlt a)
{   return truncDoubleToInt(a.floatval());
}

LispObject Truncate::op(Flt a)
{   return truncDoubleToInt(a.floatval());
}

LispObject Truncate::op(double a)
{   return truncDoubleToInt(a);
}

LispObject Truncate::op(LFlt a)
{   return truncFloat128ToInt(a.floatval());
}

LispObject Floor::op(LispObject a)
{   return unary<LispObject,Floor>("floor", a);
}

LispObject Floor::op(Fixnum a)
{   return a.value();
}

LispObject Floor::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(
        reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Floor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
// Need to round towards -infinity here.
}

LispObject Floor::op(Cpx a)
{   return aerror1("bad argument for floor", a.value());
}

LispObject Floor::op(SFlt a)
{   return floorDoubleToInt(a.floatval());
}

LispObject Floor::op(Flt a)
{   return floorDoubleToInt(a.floatval());
}

LispObject Floor::op(double a)
{   return floorDoubleToInt(a);
}

LispObject Floor::op(LFlt a)
{   return floorFloat128ToInt(a.floatval());
}

LispObject Ceiling::op(LispObject a)
{   return unary<LispObject,Ceiling>("ceiling", a);
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
// need to truncate towards +infinity here
}

LispObject Ceiling::op(Cpx a)
{   return aerror1("bad argument for ceiling", a.value());
}

LispObject Ceiling::op(SFlt a)
{   return ceilingDoubleToInt(a.floatval());
}

LispObject Ceiling::op(Flt a)
{   return ceilingDoubleToInt(a.floatval());
}

LispObject Ceiling::op(double a)
{   return ceilingDoubleToInt(a);
}

LispObject Ceiling::op(LFlt a)
{   return ceilingFloat128ToInt(a.floatval());
}

LispObject Ftruncate::op(LispObject a)
{   return unary<LispObject,Ftruncate>("floor", a);
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
}

LispObject Ftruncate::op(Cpx a)
{   return aerror1("bad argument for trunc", a.value());
}

LispObject Ftruncate::op(SFlt a)
{   return truncDoubleToInt(a.floatval());
}

LispObject Ftruncate::op(Flt a)
{   return truncDoubleToInt(a.floatval());
}

LispObject Ftruncate::op(double a)
{   return truncDoubleToInt(a);
}

LispObject Ftruncate::op(LFlt a)
{   return truncFloat128ToInt(a.floatval());
}

LispObject Ffloor::op(LispObject a)
{   return unary<LispObject,Ffloor>("floor", a);
}

LispObject Ffloor::op(Fixnum a)
{   return a.value();
}

LispObject Ffloor::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Ffloor::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Ffloor::op(Cpx a)
{   return aerror1("bad argument for floor", a.value());
}

LispObject Ffloor::op(SFlt a)
{   return floorDoubleToInt(a.floatval());
}

LispObject Ffloor::op(Flt a)
{   return floorDoubleToInt(a.floatval());
}

LispObject Ffloor::op(double a)
{   return floorDoubleToInt(a);
}

LispObject Ffloor::op(LFlt a)
{   return floorFloat128ToInt(a.floatval());
}

LispObject Fceiling::op(LispObject a)
{   return unary<LispObject,Fceiling>("ceiling", a);
}

LispObject Fceiling::op(Fixnum a)
{   return a.value();
}

LispObject Fceiling::op(uint64_t *a)
{   return reinterpret_cast<LispObject>(reinterpret_cast<char *>(a) - 8 + TAG_NUMBERS);
}

LispObject Fceiling::op(Rat a)
{   return Quotient::op(a.numerator(), a.denominator());
}

LispObject Fceiling::op(Cpx a)
{   return aerror1("bad argument for ceiling", a.value());
}

LispObject Fceiling::op(SFlt a)
{   return ceilingDoubleToInt(a.floatval());
}

LispObject Fceiling::op(Flt a)
{   return ceilingDoubleToInt(a.floatval());
}

LispObject Fceiling::op(double a)
{   return ceilingDoubleToInt(a);
}

LispObject Fceiling::op(LFlt a)
{   return ceilingFloat128ToInt(a.floatval());
}

// (frexp nn) => (double-float . fixnum)

LispObject Frexp::op(LispObject a)
{   return unary<LispObject,Frexp>("frexp", a);
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
    double d = Frexp::op(a, x);
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
{   return unary<double,Frexp>("frexp", a, xx);
}

double Frexp::op(Fixnum a, int64_t &xx)
{   return frexp_finalize(static_cast<double>(a.intval()), 0, xx);
}

double Frexp::op(uint64_t *a, int64_t &xx)
{   int64_t x;
    double d = arithlib_implementation::Frexp::op(a, x);
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

LispObject frexp_finalize(FLOAT_128 d, int x)
{   int x1;
    d = frexp(d, x1);
    return cons(fixnum_of_int(x+x1), make_boxfloat128(d));
}

LispObject Frexp128::op(Fixnum a)
{   return frexp_finalize(static_cast<double>(a.intval()), 0);
}

LispObject Frexp128::op(uint64_t *a)
{   int64_t x;
    FLOAT_128 d = Frexp128::op(a, x);
    return frexp_finalize(d, x);
}

LispObject Frexp128::op(Rat a)
{   int64_t xp=0;
    FLOAT_128 p = Frexp128::op(a.numerator(), xp);
    int64_t xq=0;
    FLOAT_128 q = Frexp128::op(a.denominator(), xq);
    return frexp_finalize(p / q, xp-xq);
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

FLOAT_128 Frexp128::op(LispObject a, int64_t &xx)
{   return unary<FLOAT_128,Frexp128>("frexp128", a, xx);
}

FLOAT_128 frexp_finalize(FLOAT_128 d, int x, int64_t &xx)
{   int x1;
    d = frexp(d, x1);
    xx = x + x1;
    return d;
}

FLOAT_128 Frexp128::op(Fixnum a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

FLOAT_128 Frexp128::op(uint64_t *a, int64_t &xx)
{   int64_t x = 0;
    FLOAT_128 d = arithlib_implementation::Frexp128::op(a, x);
    return frexp_finalize(d, x, xx);
}

FLOAT_128 Frexp128::op(Rat a, int64_t &xx)
{   int64_t xp = 0;
    FLOAT_128 p = Frexp128::op(a.numerator(), xp);
    int64_t xq = 0;
    FLOAT_128 q = Frexp128::op(a.denominator(), xq);
    return frexp_finalize(p / q, xp-xq, xx);
}

FLOAT_128 Frexp128::op(Cpx a, int64_t &xx)
{   aerror1("bad argument for frexp", a.value());
    return LF_C(0.0);
}

FLOAT_128 Frexp128::op(SFlt a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

FLOAT_128 Frexp128::op(Flt a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

FLOAT_128 Frexp128::op(double a, int64_t &xx)
{   return frexp_finalize(Float128::op(a), 0, xx);
}

FLOAT_128 Frexp128::op(LFlt a, int64_t &xx)  // maybe this should return just a double?
{   return frexp_finalize(a.floatval(), 0, xx);
}

LispObject Ldexp::op(LispObject a, LispObject b)
{   return ibinary<LispObject,Ldexp>("ldexp", a,
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
{   FLOAT_128 f = a.floatval();
    f = ldexp(f, b.intval());
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
{   FLOAT_128 f = a.floatval();
// if the exponent is to be set to a bignum then the result will be either
// zero or infinity. But with the original sign of a. Well except that
// ldexp(0.0, anything will be zero... and infinities and NaNs will not
// change.
    if (f == LF_C(0.0) ||
        isnan(f) ||
        isinf(f)) return make_boxfloat128(f);
    FLOAT_128 r =
        Minusp::op(b) ? LF_C(0.0) : PLUSINF128();
    if (f.signbit()) r = -r;
    return make_boxfloat128(r);
}

LispObject Sqrt::op(LispObject a)
{   return unary<LispObject,Sqrt>("sqrt", a);
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
{   return make_boxfloat128(sqrt(a.floatval()));
}

LispObject Isqrt::op(LispObject a)
{   return iunary<LispObject,Isqrt>("isqrt", a);
}

LispObject Isqrt::op(Fixnum a)
{   return Isqrt::op(a.intval());
}

LispObject Isqrt::op(uint64_t *a)
{   return arithlib_implementation::Isqrt::op(a);
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
            else return nil;
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {
                case LONG_FLOAT_HEADER:
                    if (isinf(long_float_val(a))) return lisp_true;
                    else return nil;
                case SINGLE_FLOAT_HEADER:
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_INFINITE)
                        return lisp_true;
                    else return nil;
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
                    else return nil;
                case LONG_FLOAT_HEADER:
                    if (isnan(long_float_val(a))) return lisp_true;
                    else return nil;
                case DOUBLE_FLOAT_HEADER:
                    if (std::fpclassify(double_float_val(a)) == FP_NAN)
                        return lisp_true;
                    else return nil;
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
                case LONG_FLOAT_HEADER:
                    if (isfinite(long_float_val(a)))
                        return lisp_true;
                    return nil;
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
                case LONG_FLOAT_HEADER:
                    if (!isnormal(long_float_val(a)))
                        return lisp_true;
                    return nil;
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
                case LONG_FLOAT_HEADER:
                    return signbit(long_float_val(a)) ? lisp_true : nil;
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
    if (is_bfloat(b) &&
        flthdr(b) == LONG_FLOAT_HEADER)
    {   FLOAT_128 d = float128_of_number(b);
// If a is another long float then float_of_number may overflow, but
// here I am only interested in its sign, and -infinity is still negative.
        if (float_of_number(a) < LF_C(0.0)) d = - d;
        return make_boxfloat128(d);
    }
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
    if (is_bfloat(1) &&
        flthdr(a) == LONG_FLOAT_HEADER)
    {   FLOAT_128 d = float128_of_number(a);
        FLOAT_128 r = LF_C(1.0);
        if (signbit(d)) r = -r;
        return make_boxfloat128(r);
    }
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


// long float version of the following function. Commentary is in the
// double precision version.

static LispObject Nlisp_fix_sub128(LispObject a, int roundmode)
{   FLOAT_128 d = long_float_val(a);
    if (isnan(d)) return aerror("NaN in fix");
    if (isinf(d)) return aerror("infinity in fix");
    int x;
    d = frexp(d, x);
// Here I will limit the range where I convert to directly to a
// 64-bit integer. I make this a slightly lower limit than I applied
// when converting 64-bit floats because here the FLOAT_128 could be
// really really close to the integer limit and so might overflow on
// rounding the conversion.
    if (x < 62)
    {   int64_t n = (int64_t)d;
// @@@ Must adjust using roundmode here
        return make_lisp_integer64(n);
    }
// Now I know that the result will be at least a 62-bit integer.
    FLOAT_128 d2;
    d2 = frexp(d, x);
    uint128_t m = d2.mantissa();
// Because this comes out of frexp it is a properly normalised value.
    int128_t ii = m | (((uint128_t)1)<<112); // Put back hidden bit.
    if (signbit(d)) ii = -ii;
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
                        if (frac != 0 && d < LF_C(0.0)) ii++;
                        break;
            case FIX_CEILING:
                        if (frac != 0 && d > LF_C(0.0)) ii++;
                        break;
        }
        if (d < LF_C(0.0)) ii = -ii;
        return make_lisp_integer128(ii);
    }
    return LeftShift::op(make_lisp_integer128(ii), fixnum_of_int(x));
}

// This converts from a double to a Lisp integer, which will
// quite often have to be a bignum.  No overflow is permitted - the
// result can always be accurate, save that infinities and NaNs must
// be rejected.

static LispObject Nlisp_fix_sub(LispObject a, int roundmode)
{   if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Nlisp_fix_sub128(a, roundmode);
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

LispObject Nscale_float128(LispObject a, intptr_t x)
{   FLOAT_128 d = long_float_val(a);
    if (isnan(d) || isinf(d)) return a;
    d = ldexp(d, (int)x);
    return make_boxfloat128(d);
}

LispObject Nscale_float(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    if (!is_fixnum(b)) return aerror("scale-float");
    intptr_t x = int_of_fixnum(b);
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Nscale_float128(a, x);
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
    FLOAT_128 li, lf;
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
                    lf = modf(long_float_val(a1), li);
                    return cons(make_boxfloat128(li), make_boxfloat128(lf));
            }
    }
}

LispObject Ndecode_long_float(LispObject a)
{   FLOAT_128 d = long_float_val(a);
    if (isinf(d) || isnan(d))
    {   if (trap_floating_overflow) return aerror("decode-float");
        else return nil; // infinity or NaN
    }
    bool neg = false;
    int x = 0;
    if (signbit(d)) d = -d, neg = true;
    if (d == LF_C(0.0)) x = 0;
    else
    {   if (!isnormal(d))
        {   d = d * arithlib_implementation::f128_N1;
            x -= 4096;
        }
        int x1;
        d = frexp(d, x1);
        x += x1;
    }
    LispObject sign = make_boxfloat128(neg ? LF_C(-1.0) : LF_C(1.0));
    a = make_boxfloat128(d);
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

LispObject Ndecode_float(LispObject env, LispObject a)
{   SingleValued fn;
    double d, neg = 1.0;
    int x;
    LispObject sign;
    if (!is_float(a)) return aerror("decode-float");
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Ndecode_long_float(a);
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

LispObject Ninteger_decode_long_float(LispObject a)
{   FLOAT_128 d = long_float_val(a);
    if (isinf(d) || isnan(d))
    {   if (trap_floating_overflow) return aerror("integer-decode-float");
        else return nil; // infinity or NaN
    }
    if (d == LF_C(0.0))
    {
#ifdef COMMON
        mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(signbit(d) ? -1 : 1);
        return nvalues(fixnum_of_int(0), 3);
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(signbit(d) ? -1 : 1));
    }
#endif
    bool neg = false;
    if (signbit(d))
    {   d = -d;
        neg = true;
    }
    int x;
    d = frexp(d, x);
    x = x - 113;
    if (d == LF_C(0.0)) x = 0;
    uint128_t ipart = (uint128_t)ldexp(d, 113);
    LispObject v1 = make_lisp_integer128(ipart);
    LispObject v2 = fixnum_of_int(x);
    LispObject v3 = fixnum_of_int(neg ? -1 : 1);    
#ifdef COMMON
    {   mv_2 = v2
        mv_3 = v3
        return nvalues(v1, 3);
    }
#else
    return list3(v1, v2, v3);
#endif // COMMON
}

LispObject Ninteger_decode_float(LispObject env, LispObject a)
{   SingleValued fn;
    double d;
    if (!is_float(a)) return aerror("integer-decode-float");
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Ninteger_decode_long_float(a);
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
    d = frexp(d, x);
    a = make_lisp_integer64((int64_t)std::ldexp(d, 63));
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

} // end of namespace

// end of arith-float.cpp

