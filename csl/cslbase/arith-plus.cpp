// arith-plus.cpp                          Copyright (C) 2022-2026 Codemist

#ifdef ARITHLIB

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

// $Id$

#include "arith-headers.h"

namespace CSL_LISP
{

// Each generic arithmetic operation will involve a class styled rather
// along the lines of this one. It will use mechanisms from the header
// file dispatch.h to go from tagged LispObjects to the data for each
// combination of operand types, and will then use code from arithlib.cpp
// to implement the big-number operations involved.

// Ugh 64 overloads! Well because addition is commutative I can make
// a number of them merely delegate to the version with arguments the other
// way round. The cases are
// 1.    Fixnum           28 or 60 bits with a low tag
// 2.    Bignum           notionally unlimited
// 3.    Rational         numerator & denominator are integers
// 4.    Complex          real and imag parts almost any type
// 5.    Short float      28 bits
// 6.    Single float     32 bits
// 7.    Double float     64 bits
// 8.    Long float       128 bits


// fixnum + fixnum
// Note that this can not just go "a+b" in any totally simple way
// because it must cope gracefully with any overflow in native arithmetic
// and in such cases return a bignum result.

// LispObject Plus::op(Fixnum a, Fixnum b)
// {   return arithlib_lowlevel::Plus::op(int_of_fixnum(a), int_of_fixnum(b));
// }

// bignum + fixnum
// LispObject Plus::op(uint64_t *a, Fixnum b)
// {   return arithlib_lowlevel::Plus::op(a, int_of_fixnum(b));
// }

// rational + fixnum
LispObject Plus::op(Rat a, Fixnum b)
{   return make_ratio(Binary(Plus, a.numerator(),
                               Binary(Times, a.denominator(), b)),
                      a.denominator());
}

// complex + fixnum
LispObject Plus::op(Cpx a, Fixnum b)
{   return make_complex(Binary(Plus, a.real_part(), b), a.imag_part());
}

// short float + fixnum
LispObject Plus::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() + static_cast<double>(int_of_fixnum(b)));
}

// single float + fixnum
LispObject Plus::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() + static_cast<double>(int_of_fixnum(b)));
}

// double float + fixnum
LispObject Plus::op(double a, Fixnum b)
{   return make_boxfloat(a + static_cast<double>(int_of_fixnum(b)));
}

// long float + fixnum
LispObject Plus::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a + (FLOAT_128)(int64_t)int_of_fixnum(b));
}

// fixnum + bignum
// LispObject Plus::op(Fixnum a, uint64_t *b)
// {   return Plus::op(b, a);
// }

// bignum + bignum
// LispObject Plus::op(uint64_t *a, uint64_t *b)
// {   return arithlib_lowlevel::Plus::op(a, b);
// }

// rational + bignum
LispObject Plus::op(Rat a, uint64_t *b)
{   return make_ratio(Binary(Plus, a.numerator(),
                               Binary(Times, a.denominator(), bignum_value(b))),
                      a.denominator());
}

// complex + bignum
LispObject Plus::op(Cpx a, uint64_t *b)
{   return make_complex(Binary(Plus, a.real_part(), bignum_value(b)), a.imag_part());
}

// short float + bignum
LispObject Plus::op(SFlt a, uint64_t *b)
{   return pack_short_float(a.floatval() + arithlib_lowlevel::Double::op(b));
}

// single float + bignum
LispObject Plus::op(Flt a, uint64_t *b)
{   return pack_single_float(a.floatval() + arithlib_lowlevel::Double::op(b));
}

// double float + bignum
LispObject Plus::op(double a, uint64_t *b)
{   return make_boxfloat(a + arithlib_lowlevel::Double::op(b));
}

// long float + bignum
LispObject Plus::op(FLOAT_128 a, uint64_t *b)
{   return make_boxfloat128(a + arithlib_lowlevel::Float128::op(b));
}

// fixnum + rational
LispObject Plus::op(Fixnum a, Rat b)
{   return Plus::op(b, a);
}

// bignum + rational
LispObject Plus::op(uint64_t *a, Rat b)
{   return Plus::op(b, a);
}

// rational + rational
LispObject Plus::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    LispObject g = IBinary(Gcdn, q1, q2);
    LispObject w;
    LispObject num = Binary(Plus,
                         Binary(Times, p1, w = Binary(Quotient, q2, g)),
                         Binary(Times, p2, Binary(Quotient, q1, g)));
    LispObject den = Binary(Times, w, q1);
    g = IBinary(Gcdn, num, den);
    return make_ratio(Binary(Quotient, num, g),
                      Binary(Quotient, den, g));
}

// complex + rational
LispObject Plus::op(Cpx a, Rat b)
{   return make_complex(Binary(Plus, a.real_part(), b.value()), a.imag_part());
}

// short float + rational
LispObject Plus::op(SFlt a, Rat b)
{   return pack_short_float(a.floatval() + RawFloat::op(b));
}

// single float + rational
LispObject Plus::op(Flt a, Rat b)
{   return pack_single_float(a.floatval() + RawFloat::op(b));
}

// double float + rational
LispObject Plus::op(double a, Rat b)
{   return make_boxfloat(a + RawFloat::op(b));
}

// long float + rational
LispObject Plus::op(FLOAT_128 a, Rat b)
{   return make_boxfloat128(a + Float128::op(b));
}

// fixnum + complex
LispObject Plus::op(Fixnum a, Cpx b)
{   return Plus::op(b, a);
}

// bignum + complex
LispObject Plus::op(uint64_t *a, Cpx b)
{   return Plus::op(b, a);
}

// rational + complex
LispObject Plus::op(Rat a, Cpx b)
{   return Plus::op(b, a);
}

// complex + complex
LispObject Plus::op(Cpx a, Cpx b)
{   return make_complex(Binary(Plus, a.real_part(), b.real_part()),
                        Binary(Plus, a.imag_part(), b.imag_part()));
}

// short float + complex
LispObject Plus::op(SFlt a, Cpx b)
{   return make_complex(Binary(Plus, a.value(), b.real_part()), b.imag_part());
}

// single float + complex
LispObject Plus::op(Flt a, Cpx b)
{   return make_complex(Binary(Plus, a.value(), b.real_part()), b.imag_part());
}

// double float + complex
LispObject Plus::op(double a, Cpx b)
{   return make_complex(Binary(Plus, make_boxfloat(a), b.real_part()), b.imag_part());
}

// long float + complex
LispObject Plus::op(FLOAT_128 a, Cpx b)
{   return make_complex(Binary(Plus, make_boxfloat128(a), b.real_part()), b.imag_part());
}

// fixnum + short float
LispObject Plus::op(Fixnum a, SFlt b)
{   return Plus::op(b, a);
}

// bignum + short float
LispObject Plus::op(uint64_t *a, SFlt b)
{   return Plus::op(b, a);
}

// rational + short float
LispObject Plus::op(Rat a, SFlt b)
{   return Plus::op(b, a);
}

// complex + short float
LispObject Plus::op(Cpx a, SFlt b)
{   return Plus::op(b, a);
}

// short float + short float
LispObject Plus::op(SFlt a, SFlt b)
{   return pack_short_float(a.floatval() + b.floatval());
}

// single float + short float
LispObject Plus::op(Flt a, SFlt b)
{   return pack_single_float(a.floatval() + b.floatval());
}

// double float + short float
LispObject Plus::op(double a, SFlt b)
{   return make_boxfloat(a + b.floatval());
}

// long float + short float
LispObject Plus::op(FLOAT_128 a, SFlt b)
{   return make_boxfloat128(a + Float128::op(b));
}

// fixnum + single float
LispObject Plus::op(Fixnum a, Flt b)
{   return Plus::op(b, a);
}

// bignum + single float
LispObject Plus::op(uint64_t *a, Flt b)
{   return Plus::op(b, a);
}

// rational + single float
LispObject Plus::op(Rat a, Flt b)
{   return Plus::op(b, a);
}

// complex + single float
LispObject Plus::op(Cpx a, Flt b)
{   return Plus::op(b, a);
}

// short float + single float
LispObject Plus::op(SFlt a, Flt b)
{   return Plus::op(b, a);
}

// single float + single float
LispObject Plus::op(Flt a, Flt b)
{   return pack_single_float(a.floatval() + b.floatval());
}

// double float + single float
LispObject Plus::op(double a, Flt b)
{   return make_boxfloat(a + b.floatval());
}

// long float + single float
LispObject Plus::op(FLOAT_128 a, Flt b)
{   return make_boxfloat128(a + Float128::op(b));
}

// fixnum + double float
LispObject Plus::op(Fixnum a, double b)
{   return Plus::op(b, a);
}

// bignum + double float
LispObject Plus::op(uint64_t *a, double b)
{   return Plus::op(b, a);
}

// rational + double float
LispObject Plus::op(Rat a, double b)
{   return Plus::op(b, a);
}

// complex + double float
LispObject Plus::op(Cpx a, double b)
{   return Plus::op(b, a);
}

// short float + double float
LispObject Plus::op(SFlt a, double b)
{   return Plus::op(b, a);
}

// single float + double float
LispObject Plus::op(Flt a, double b)
{   return Plus::op(b, a);
}

// double float + double float
LispObject Plus::op(double a, double b)
{   return make_boxfloat(a + b);
}

// long float + double float
LispObject Plus::op(FLOAT_128 a, double b)
{   return make_boxfloat128(a + Float128::op(b));
}

// fixnum + long float
LispObject Plus::op(Fixnum a, FLOAT_128 b)
{   return Plus::op(b, a);
}

// bignum + long float
LispObject Plus::op(uint64_t *a, FLOAT_128 b)
{   return Plus::op(b, a);
}

// rational + long float
LispObject Plus::op(Rat a, FLOAT_128 b)
{   return Plus::op(b, a);
}

// complex + long float
LispObject Plus::op(Cpx a, FLOAT_128 b)
{   return Plus::op(b, a);
}

// short float + long float
LispObject Plus::op(SFlt a, FLOAT_128 b)
{   return Plus::op(b, a);
}

// single float + long float
LispObject Plus::op(Flt a, FLOAT_128 b)
{   return Plus::op(b, a);
}

// double float + long float
LispObject Plus::op(double a, FLOAT_128 b)
{   return Plus::op(b, a);
}

// long float + long float
LispObject Plus::op(FLOAT_128 a, FLOAT_128 b)
{   return make_boxfloat128(a + b);
}

// I will also put difference() in this file, since the logic is very
// similar indeed to that for plus()

// fixnum - fixnum
// LispObject Difference::op(Fixnum a, Fixnum b)
// {   return arithlib_lowlevel::Difference::op(int_of_fixnum(a), int_of_fixnum(b));
// }

// bignum - fixnum
// LispObject Difference::op(uint64_t *a, Fixnum b)
// {   return arithlib_lowlevel::Difference::op(a, int_of_fixnum(b));
// }

// rational - fixnum
LispObject Difference::op(Rat a, Fixnum b)
{   return make_ratio(Binary(Difference, a.numerator(),
                                     Binary(Times, a.denominator(), b)),
                      a.denominator());
}

// complex - fixnum
LispObject Difference::op(Cpx a, Fixnum b)
{   return make_complex(Binary(Difference, a.real_part(), b),
                        a.imag_part());
}

// short float - fixnum
LispObject Difference::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() - static_cast<double>(int_of_fixnum(b)));
}

// single float - fixnum
LispObject Difference::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() - static_cast<double>(int_of_fixnum(b)));
}

// double float - fixnum
LispObject Difference::op(double a, Fixnum b)
{   return make_boxfloat(a - static_cast<double>(int_of_fixnum(b)));
}

// long float - fixnum
LispObject Difference::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a - (FLOAT_128)(int64_t)int_of_fixnum(b));
}

// fixnum - bignum
// LispObject Difference::op(Fixnum a, uint64_t *b)
// {   return arithlib_lowlevel::Difference::op(int_of_fixnum(a), b);
// }

// bignum - bignum
// LispObject Difference::op(uint64_t *a, uint64_t *b)
// {   return arithlib_lowlevel::Difference::op(a, b);
// }

// rational - bignum
LispObject Difference::op(Rat a, uint64_t *b)
{   return make_ratio(Binary(Difference, a.numerator(),
                                     Binary(Times, a.denominator(), bignum_value(b))),
                      a.denominator());
}

// complex - bignum
LispObject Difference::op(Cpx a, uint64_t *b)
{   return make_complex(Binary(Difference, a.real_part(), bignum_value(b)),
                        a.imag_part());
}

// short float - bignum
LispObject Difference::op(SFlt a, uint64_t *b)
{   return pack_short_float(a.floatval() -
                            arithlib_lowlevel::Double::op(b));
}

// single float - bignum
LispObject Difference::op(Flt a, uint64_t *b)
{   return pack_single_float(a.floatval() -
                             arithlib_lowlevel::Double::op(b));
}

// double float - bignum
LispObject Difference::op(double a, uint64_t *b)
{   return make_boxfloat(a - arithlib_lowlevel::Double::op(b));
}

// long float - bignum
LispObject Difference::op(FLOAT_128 a, uint64_t *b)
{   return make_boxfloat128(a - arithlib_lowlevel::Float128::op(b));
}

// fixnum - rational
LispObject Difference::op(Fixnum a, Rat b)
{   return make_ratio(Binary(Difference, Binary(Times, b.denominator(), a),
                                     b.numerator()),
                      b.denominator());
}

// bignum - rational
LispObject Difference::op(uint64_t *a, Rat b)
{   return make_ratio(Binary(Difference, Binary(Times, b.denominator(), bignum_value(a)),
                                     b.numerator()),
                      b.denominator());
}

// rational - rational
LispObject Difference::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    LispObject g = IBinary(Gcdn, q1, q2);
    LispObject w;
    LispObject num = Binary(Difference,
                         Binary(Times, p1, w = Binary(Quotient, q2, g)),
                         Binary(Times, p2, Binary(Quotient, q1, g)));
    LispObject den = Binary(Times, w, q1);
    g = IBinary(Gcdn, num, den);
    return make_ratio(Binary(Quotient, num, g),
                      Binary(Quotient, den, g));
}

// complex - rational
LispObject Difference::op(Cpx a, Rat b)
{   return make_complex(Binary(Difference, a.real_part(), b.value()),
                        a.imag_part());
}

// short float - rational
LispObject Difference::op(SFlt a, Rat b)
{   return pack_short_float(a.floatval() - RawFloat::op(b));
}

// single float - rational
LispObject Difference::op(Flt a, Rat b)
{   return pack_single_float(a.floatval() - RawFloat::op(b));
}

// double float - rational
LispObject Difference::op(double a, Rat b)
{   return make_boxfloat(a - RawFloat::op(b));
}

// long float - rational
LispObject Difference::op(FLOAT_128 a, Rat b)
{   return make_boxfloat128(a - Float128::op(b));
}

// fixnum - complex
LispObject Difference::op(Fixnum a, Cpx b)
{   return make_complex(Binary(Difference, a, b.real_part()),
                        Unary(Minus, b.imag_part()));
}

// bignum - complex
LispObject Difference::op(uint64_t *a, Cpx b)
{   return make_complex(Binary(Difference, bignum_value(a), b.real_part()),
                        Unary(Minus, b.imag_part()));
}

// rational - complex
LispObject Difference::op(Rat a, Cpx b)
{   return make_complex(Binary(Difference, a.value(), b.real_part()),
                        Unary(Minus, b.imag_part()));
}

// complex - complex
LispObject Difference::op(Cpx a, Cpx b)
{   return make_complex(Binary(Difference, a.real_part(), b.real_part()),
                        Binary(Difference, a.imag_part(), b.imag_part()));
}

// short float - complex
LispObject Difference::op(SFlt a, Cpx b)
{   return make_complex(Binary(Difference, a.value(), b.real_part()),
                        Unary(Minus, b.imag_part()));
}

// single float - complex
LispObject Difference::op(Flt a, Cpx b)
{   return make_complex(Binary(Difference, a.value(), b.real_part()),
                        Unary(Minus, b.imag_part()));
}

// double float - complex
LispObject Difference::op(double a, Cpx b)
{   return make_complex(Binary(Difference, make_boxfloat(a), b.real_part()),
                        Unary(Minus, b.imag_part()));
}

// long float - complex
LispObject Difference::op(FLOAT_128 a, Cpx b)
{   return make_complex(Binary(Difference, make_boxfloat128(a), b.real_part()),
                        Unary(Minus, b.imag_part()));
}

// fixnum - short float
LispObject Difference::op(Fixnum a, SFlt b)
{   return pack_short_float(static_cast<double>(int_of_fixnum(a)) - b.floatval());
}

// bignum - short float
LispObject Difference::op(uint64_t *a, SFlt b)
{   return pack_single_float(RawFloat::op(a) - b.floatval());
}

// rational - short float
LispObject Difference::op(Rat a, SFlt b)
{   return pack_single_float(RawFloat::op(a) - b.floatval());
}

// complex - short float
LispObject Difference::op(Cpx a, SFlt b)
{   return make_complex(Binary(Difference, a.real_part(), b.value()),
                        a.imag_part());
}

// short float - short float
LispObject Difference::op(SFlt a, SFlt b)
{   return pack_short_float(a.floatval() - b.floatval());
}

// single float - short float
LispObject Difference::op(Flt a, SFlt b)
{   return pack_single_float(a.floatval() - b.floatval());
}

// double float - short float
LispObject Difference::op(double a, SFlt b)
{   return make_boxfloat(a - b.floatval());
}

// long float - short float
LispObject Difference::op(FLOAT_128 a, SFlt b)
{   return make_boxfloat128(a - Float128::op(b));
}

// fixnum - single float
LispObject Difference::op(Fixnum a, Flt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) - b.floatval());
}

// bignum - single float
LispObject Difference::op(uint64_t *a, Flt b)
{   return pack_single_float(RawFloat::op(a) - b.floatval());
}

// rational - single float
LispObject Difference::op(Rat a, Flt b)
{   return pack_single_float(RawFloat::op(a) - b.floatval());
}

// complex - single float
LispObject Difference::op(Cpx a, Flt b)
{   return make_complex(Binary(Difference, a.real_part(), b.value()),
                        a.imag_part());
}

// short float - single float
LispObject Difference::op(SFlt a, Flt b)
{   return pack_single_float(a.floatval() - b.floatval());
}

// single float - single float
LispObject Difference::op(Flt a, Flt b)
{   return pack_single_float(a.floatval() - b.floatval());
}

// double float - single float
LispObject Difference::op(double a, Flt b)
{   return make_boxfloat(a - b.floatval());
}

// long float - single float
LispObject Difference::op(FLOAT_128 a, Flt b)
{   return make_boxfloat128(a - Float128::op(b));
}

// fixnum - double float@
LispObject Difference::op(Fixnum a, double b)
{   return make_boxfloat(static_cast<double>(int_of_fixnum(a)) - b);
}

// bignum - double float
LispObject Difference::op(uint64_t *a, double b)
{   return make_boxfloat(RawFloat::op(a) - b);
}

// rational - double float
LispObject Difference::op(Rat a, double b)
{   return make_boxfloat(RawFloat::op(a) - b);
}

// complex - double float
LispObject Difference::op(Cpx a, double b)
{   return make_complex(Binary(Difference, a.real_part(), make_boxfloat(b)),
                        a.imag_part());
}

// short float - double float
LispObject Difference::op(SFlt a, double b)
{   return make_boxfloat(a.floatval() - b);
}

// single float - double float
LispObject Difference::op(Flt a, double b)
{   return make_boxfloat(a.floatval() - b);
}

// double float - double float
LispObject Difference::op(double a, double b)
{   return make_boxfloat(a - b);
}

// long float - double float
LispObject Difference::op(FLOAT_128 a, double b)
{   return make_boxfloat128(a - Float128::op(b));
}

// fixnum - long float
LispObject Difference::op(Fixnum a, FLOAT_128 b)
{   return make_boxfloat128((FLOAT_128)(int64_t)int_of_fixnum(a) - b);
}

// bignum - long float
LispObject Difference::op(uint64_t *a, FLOAT_128 b)
{   return make_boxfloat128(Float128::op(a) - b);
}

// rational - long float
LispObject Difference::op(Rat a, FLOAT_128 b)
{   return make_boxfloat128(Float128::op(a) - b);
}

// complex - long float
LispObject Difference::op(Cpx a, FLOAT_128 b)
{   return make_complex(Binary(Difference, a.real_part(), make_boxfloat128(b)),
                        a.imag_part());
}

// short float - long float
LispObject Difference::op(SFlt a, FLOAT_128 b)
{   return make_boxfloat128(Float128::op(a) - b);
}

// single float - long float
LispObject Difference::op(Flt a, FLOAT_128 b)
{   return make_boxfloat128(Float128::op(a) - b);
}

// double float - long float
LispObject Difference::op(double a, FLOAT_128 b)
{   return make_boxfloat128(Float128::op(a) - b);
}

// long float - long float
LispObject Difference::op(FLOAT_128 a, FLOAT_128 b)
{   return make_boxfloat128(a - b);
}

// add1

LispObject Add1::op(Fixnum a)
{   return arithlib_lowlevel::Add1::op(int_of_fixnum(a));
}

LispObject Add1::op(uint64_t *a)
{   return arithlib_lowlevel::Add1::op(a);
}

LispObject Add1::op(Rat a)
{   return make_ratio(Binary(Plus, a.numerator(), a.denominator()), a.denominator());
}

LispObject Add1::op(Cpx a)
{   return make_complex(Unary(Add1, a.real_part()),
                        a.imag_part());
}

LispObject Add1::op(SFlt a)
{   return pack_short_float(a.floatval() + 1.0);
}

LispObject Add1::op(Flt a)
{   return pack_single_float(a.floatval() + 1.0);
}

LispObject Add1::op(double a)
{   return make_boxfloat(a + 1.0);
}

LispObject Add1::op(FLOAT_128 a)
{   return make_boxfloat128(LF_C(1.0) + a);
}

// sub1

LispObject Sub1::op(Fixnum a)
{   return arithlib_lowlevel::Sub1::op(int_of_fixnum(a));
}

LispObject Sub1::op(uint64_t *a)
{   return arithlib_lowlevel::Sub1::op(a);
}

LispObject Sub1::op(Rat a)
{   return make_ratio(Binary(Difference, a.numerator(), a.denominator()), a.denominator());
}

LispObject Sub1::op(Cpx a)
{   return make_complex(Unary(Sub1, a.real_part()), a.imag_part());
}

LispObject Sub1::op(SFlt a)
{   return pack_short_float(a.floatval() - 1.0);
}

LispObject Sub1::op(Flt a)
{   return pack_single_float(a.floatval() - 1.0);
}

LispObject Sub1::op(double a)
{   return make_boxfloat(a - 1.0);
}

LispObject Sub1::op(FLOAT_128 a)
{   return make_boxfloat128(LF_C(-1.0) + a);
}

// minus

LispObject Minus::op(Fixnum a)
{   return arithlib_lowlevel::Minus::op(int_of_fixnum(a));
}

LispObject Minus::op(uint64_t *a)
{   return arithlib_lowlevel::Minus::op(a);
}

LispObject Minus::op(Rat a)
{   return make_ratio(Unary(Minus, a.numerator()), a.denominator());
}

LispObject Minus::op(Cpx a)
{   return make_complex(Unary(Minus, a.real_part()),
                        Unary(Minus, a.imag_part()));
}

LispObject Minus::op(SFlt a)
{   return pack_short_float(-a.floatval());
}

LispObject Minus::op(Flt a)
{   return pack_single_float(-a.floatval());
}

LispObject Minus::op(double a)
{   return make_boxfloat(-a);
}

LispObject Minus::op(FLOAT_128 a)
{   return make_boxfloat128(-a);
}

// xdifference is provided just for the support of the CASE operator. It
// subtracts its arguments but returns NIL if either argument is not
// an small integer or if the result overflows. Small is 28-bits in this
// context at present, which is maybe strange!

LispObject Nxdifference(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    int32_t r;
    if (!is_fixnum(a) || !is_fixnum(b)) return nil;
    r = int_of_fixnum(a) - int_of_fixnum(b);
    if (r < -0x08000000 || r > 0x07ffffff) return nil;
    return fixnum_of_int(r);
}

LispObject Nplus(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nplus(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nplus(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Plus, a1, a2);
}

LispObject Nplus(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return Binary(Plus, Binary(Plus, a1, a2), a3);
}

LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Binary(Plus, Binary(Plus, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Binary(Plus, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Ndifference(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Difference, a1, a2);
}

LispObject Nadd1(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Add1, a1);
}

LispObject Nsub1(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Sub1, a1);
}

LispObject Nminus(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Minus, a1);
}

LispObject Nabs(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Abs, a1);
}

// The following functions, with name like IPLUS, ITIMES etc are relatives
// of the generic versions but they only support fixnum inputs. On a 32-bit
// machine that is values that fit in 28 bits, while on a 64-bit machine
// 60 bits are supported. Overflow is not checked for and although the
// consequence is probably that values wrap around within the range of fixnums
// that will not be guaranteed.

LispObject Niplus(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Niplus(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Niplus(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Plus, a1, a2);
}

LispObject Niplus(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return Binary(Plus, Binary(Plus, a1, a2), a3);
}

LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Binary(Plus, Binary(Plus, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Binary(Plus, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nidifference(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Difference, a1, a2);
}

LispObject Niadd1(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Add1, a1);
}

LispObject Nisub1(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Sub1, a1);
}

} // end of namespace

#endif // ARITHLIB

// end of arith-plus.cpp
