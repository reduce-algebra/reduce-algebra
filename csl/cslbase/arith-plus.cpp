#ifdef ARITHLIB
// arith-plus.cpp                               Copyright (C) 2019 Codemist

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

// ====== addition =====

// Each generic arithmetic operation will involve a class styled rather
// along the lines of this one. It will use mechanisms from the header
// file dispatch.h to go from tagged LispObjects to the data for each
// combination of operand types, and will then use code from arithlib.hpp
// to implement the big-number operations involved.

// Ugh 64 overloads! Well because addition is commutative I can make
// a number of them merely delegate to the version with arguments the other
// way round.

// Well I will make it even worse and include LispObject in the overloads
// and that makes it 81 little functions!

using number_dispatcher::Fixnum;
// uint64_t *
using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
// double
using number_dispatcher::Flt;
using number_dispatcher::LFlt;

// The main generic addition function is
//       LispObject Plus.op(LispObject, LispObject);

LispObject Plus::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Plus>("plus", a, b);
}


LispObject Plus::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}


LispObject Plus::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}


LispObject Plus::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}

LispObject Plus::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Plus>("plus", a, b);
}

// fixnum + fixnum
// Note that this can not just go "a+b" in any totally simple way
// because it must cope gracefully with any overflow in native arithmetic
// and in such cases return a bignum result.

inline LispObject Plus::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Plus::op(a.intval(), b.intval());
}
// bignum + fixnum
LispObject Plus::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Plus::op(a, b.intval());
}
// rational + fixnum
LispObject Plus::op(Rat a, Fixnum b)
{   return make_ratio(Plus::op(a.numerator(),
                               Times::op(a.denominator(), b)),
                      a.denominator());
}
// complex + fixnum
LispObject Plus::op(Cpx a, Fixnum b)
{   return make_complex(Plus::op(a.real_part(), b), a.imag_part());
}
// short float + fixnum
LispObject Plus::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() + (double)b.intval());
}
// single float + fixnum
LispObject Plus::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() + (double)b.intval());
}
// double float + fixnum
LispObject Plus::op(double a, Fixnum b)
{   return make_boxfloat(a + (double)b.intval(), TYPE_DOUBLE_FLOAT);
}
// long float + fixnum
LispObject Plus::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_add(a.floatval(), i64_to_f128(b.intval())));
}
//............................................
// fixnum + bignum
LispObject Plus::op(Fixnum a, uint64_t *b)
{   return Plus::op(b, a);
}
// bignum + bignum
LispObject Plus::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Plus::op(a, b);
}
// rational + bignum
LispObject Plus::op(Rat a, uint64_t *b)
{   return make_ratio(Plus::op(a.numerator(),
                               Times::op(a.denominator(), b)),
                      a.denominator());
}
// complex + bignum
LispObject Plus::op(Cpx a, uint64_t *b)
{   return make_complex(Plus::op(a.real_part(), b), a.imag_part());
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
{   return make_boxfloat(a + arithlib_lowlevel::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + bignum
LispObject Plus::op(LFlt a, uint64_t *b)
{   return make_boxfloat128(f128_add(a.floatval(), arithlib_lowlevel::Float128::op(b)));
}

//............................................
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
    LispObject g = Gcdn::op(q1, q2);
    LispObject w;
    LispObject num = Plus::op(
        Times::op(p1, w = Quotient::op(q2, g)),
        Times::op(p2, Quotient::op(q1, g)));
    LispObject den = Times::op(w, q1);
    g = Gcdn::op(num, den);
    return make_ratio(Quotient::op(num, g),
                      Quotient::op(den, g));
}
// complex + rational
LispObject Plus::op(Cpx a, Rat b)
{   return make_complex(Plus::op(a.real_part(), b), a.imag_part());
}
// short float + rational
LispObject Plus::op(SFlt a, Rat b)
{   return pack_short_float(a.floatval() + Float::op(b));
}
// single float + rational
LispObject Plus::op(Flt a, Rat b)
{   return pack_single_float(a.floatval() + Float::op(b));
}
// double float + rational
LispObject Plus::op(double a, Rat b)
{   return make_boxfloat(a + Float::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + rational
LispObject Plus::op(LFlt a, Rat b)
{   return make_boxfloat128(f128_add(a.floatval(), Float128::op(b)));
}
//............................................
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
{   return make_complex(Plus::op(a.real_part(), b.real_part()),
                        Plus::op(a.imag_part(), b.imag_part()));
}
// short float + complex
LispObject Plus::op(SFlt a, Cpx b)
{   return make_complex(Plus::op(a, b.real_part()), b.imag_part());
}
// single float + complex
LispObject Plus::op(Flt a, Cpx b)
{   return make_complex(Plus::op(a, b.real_part()), b.imag_part());
}
// double float + complex
LispObject Plus::op(double a, Cpx b)
{   return make_complex(Plus::op(a, b.real_part()), b.imag_part());
}
// long float + complex
LispObject Plus::op(LFlt a, Cpx b)
{   return make_complex(Plus::op(a, b.real_part()), b.imag_part());
}
//............................................
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
{   return make_boxfloat(a + b.floatval(), TYPE_DOUBLE_FLOAT);
}
// long float + short float
LispObject Plus::op(LFlt a, SFlt b)
{   return make_boxfloat128(f128_add(a.floatval(), Float128::op(b)));
}
//............................................
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
{   return make_boxfloat(a + b.floatval(), TYPE_DOUBLE_FLOAT);
}
// long float + single float
LispObject Plus::op(LFlt a, Flt b)
{   return make_boxfloat128(f128_add(a.floatval(), Float128::op(b)));
}

//............................................
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
{   return make_boxfloat(a + b, TYPE_DOUBLE_FLOAT);
}
// long float + double float
LispObject Plus::op(LFlt a, double b)
{   return make_boxfloat128(f128_add(a.floatval(), Float128::op(b)));
}
//............................................
// fixnum + long float
LispObject Plus::op(Fixnum a, LFlt b)
{   return Plus::op(b, a);
}
// bignum + long float
LispObject Plus::op(uint64_t *a, LFlt b)
{   return Plus::op(b, a);
}
// rational + long float
LispObject Plus::op(Rat a, LFlt b)
{   return Plus::op(b, a);
}
// complex + long float
LispObject Plus::op(Cpx a, LFlt b)
{   return Plus::op(b, a);
}
// short float + long float
LispObject Plus::op(SFlt a, LFlt b)
{   return Plus::op(b, a);
}
// single float + long float
LispObject Plus::op(Flt a, LFlt b)
{   return Plus::op(b, a);
}
// double float + long float
LispObject Plus::op(double a, LFlt b)
{   return Plus::op(b, a);
}
// long float + long float
LispObject Plus::op(LFlt a, LFlt b)
{   return make_boxfloat128(f128_add(a.floatval(), b.floatval()));
}


// I will also put difference() in this file, since the logic is very
// similar indeed to that for plus()

LispObject Difference::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Difference>("difference", a, b);
}

// -------------------------------------------------------------------------

LispObject Difference::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

LispObject Difference::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Difference>("difference", a, b);
}

// fixnum - fixnum
inline LispObject Difference::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Difference::op(a.intval(), b.intval());
}
// bignum - fixnum
LispObject Difference::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Difference::op(a, b.intval());
}
// rational - fixnum
LispObject Difference::op(Rat a, Fixnum b)
{   return make_ratio(Difference::op(a.numerator(),
                                     Times::op(a.denominator(), b)),
                      a.denominator());
}
// complex - fixnum
LispObject Difference::op(Cpx a, Fixnum b)
{   return make_complex(Difference::op(a.real_part(), b), a.imag_part());
}
// short float - fixnum
LispObject Difference::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() - (double)b.intval());
}
// single float - fixnum
LispObject Difference::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() - (double)b.intval());
}
// double float - fixnum
LispObject Difference::op(double a, Fixnum b)
{   return make_boxfloat(a - (double)b.intval(), TYPE_DOUBLE_FLOAT);
}
// long float - fixnum
LispObject Difference::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_sub(a.floatval(), i64_to_f128(b.intval())));
}
//............................................
// fixnum - bignum
LispObject Difference::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::Difference::op(b, a.intval());
}
// bignum - bignum
LispObject Difference::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Difference::op(a, b);
}
// rational - bignum
LispObject Difference::op(Rat a, uint64_t *b)
{   return make_ratio(Difference::op(a.numerator(),
                                     Times::op(a.denominator(), b)),
                      a.denominator());
}
// complex - bignum
LispObject Difference::op(Cpx a, uint64_t *b)
{   return make_complex(Difference::op(a.real_part(), b), a.imag_part());
}
// short float - bignum
LispObject Difference::op(SFlt a, uint64_t *b)
{   return pack_short_float(a.floatval() - arithlib_lowlevel::Double::op(b));
}
// single float - bignum
LispObject Difference::op(Flt a, uint64_t *b)
{   return pack_single_float(a.floatval() - arithlib_lowlevel::Double::op(b));
}
// double float - bignum
LispObject Difference::op(double a, uint64_t *b)
{   return make_boxfloat(a - arithlib_lowlevel::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float - bignum
LispObject Difference::op(LFlt a, uint64_t *b)
{   return make_boxfloat128(f128_sub(a.floatval(), arithlib_lowlevel::Float128::op(b)));
}

//............................................
// fixnum - rational
LispObject Difference::op(Fixnum a, Rat b)
{   return make_ratio(Difference::op(Times::op(b.denominator(), a),
                                     b.numerator()),
                      b.denominator());
}
// bignum - rational
LispObject Difference::op(uint64_t *a, Rat b)
{   return make_ratio(Difference::op(Times::op(b.denominator(), a),
                                     b.numerator()),
                      b.denominator());
}
// rational - rational
LispObject Difference::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    LispObject g = Gcdn::op(q1, q2);
    LispObject w;
    LispObject num = Difference::op(
        Times::op(p1, w = Quotient::op(q2, g)),
        Times::op(p2, Quotient::op(q1, g)));
    LispObject den = Times::op(w, q1);
    g = Gcdn::op(num, den);
    return make_ratio(Quotient::op(num, g),
                      Quotient::op(den, g));
}
// complex - rational
LispObject Difference::op(Cpx a, Rat b)
{   return make_complex(Difference::op(a.real_part(), b), a.imag_part());
}
// short float - rational
LispObject Difference::op(SFlt a, Rat b)
{   return pack_short_float(a.floatval() - Float::op(b));
}
// single float - rational
LispObject Difference::op(Flt a, Rat b)
{   return pack_single_float(a.floatval() - Float::op(b));
}
// double float - rational
LispObject Difference::op(double a, Rat b)
{   return make_boxfloat(a - Float::op(b), TYPE_DOUBLE_FLOAT);
}
// long float - rational
LispObject Difference::op(LFlt a, Rat b)
{   return make_boxfloat128(f128_sub(a.floatval(), Float128::op(b)));
}
//............................................
// fixnum - complex
LispObject Difference::op(Fixnum a, Cpx b)
{   return make_complex(Difference::op(a, b.real_part()),
                        Minus::op(b.imag_part()));
}
// bignum - complex
LispObject Difference::op(uint64_t *a, Cpx b)
{   return make_complex(Difference::op(a, b.real_part()),
                        Minus::op(b.imag_part()));
}
// rational - complex
LispObject Difference::op(Rat a, Cpx b)
{   return make_complex(Difference::op(a, b.real_part()),
                        Minus::op(b.imag_part()));
}
// complex - complex
LispObject Difference::op(Cpx a, Cpx b)
{   return make_complex(Difference::op(a.real_part(), b.real_part()),
                        Difference::op(a.imag_part(), b.imag_part()));
}
// short float - complex
LispObject Difference::op(SFlt a, Cpx b)
{   return make_complex(Difference::op(a, b.real_part()),
                        Minus::op(b.imag_part()));
}
// single float - complex
LispObject Difference::op(Flt a, Cpx b)
{   return make_complex(Difference::op(a, b.real_part()),
                        Minus::op(b.imag_part()));
}
// double float - complex
LispObject Difference::op(double a, Cpx b)
{   return make_complex(Difference::op(a, b.real_part()),
                        Minus::op(b.imag_part()));
}
// long float - complex
LispObject Difference::op(LFlt a, Cpx b)
{   return make_complex(Difference::op(a, b.real_part()),
                        Minus::op(b.imag_part()));
}
//............................................
// fixnum - short float
LispObject Difference::op(Fixnum a, SFlt b)
{   return pack_short_float((double)a.intval() - b.floatval());
}
// bignum - short float
LispObject Difference::op(uint64_t *a, SFlt b)
{   return pack_single_float(Float::op(a) - b.floatval());
}
// rational - short float
LispObject Difference::op(Rat a, SFlt b)
{   return pack_single_float(Float::op(a) - b.floatval());
}
// complex - short float
LispObject Difference::op(Cpx a, SFlt b)
{   return make_complex(a.real_part(), Difference::op(a.imag_part(), b));
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
{   return make_boxfloat(a - b.floatval(), TYPE_DOUBLE_FLOAT);
}
// long float - short float
LispObject Difference::op(LFlt a, SFlt b)
{   return make_boxfloat128(f128_sub(a.floatval(), Float128::op(b)));
}
//............................................
// fixnum - single float
LispObject Difference::op(Fixnum a, Flt b)
{   return pack_single_float((double)a.intval() - b.floatval());
}
// bignum - single float
LispObject Difference::op(uint64_t *a, Flt b)
{   return pack_single_float(Float::op(a) - b.floatval());
}
// rational - single float
LispObject Difference::op(Rat a, Flt b)
{   return pack_single_float(Float::op(a) - b.floatval());
}
// complex - single float
LispObject Difference::op(Cpx a, Flt b)
{   return make_complex(Difference::op(a.real_part(), b), a.imag_part());
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
{   return make_boxfloat(a - b.floatval(), TYPE_DOUBLE_FLOAT);
}
// long float - single float
LispObject Difference::op(LFlt a, Flt b)
{   return make_boxfloat128(f128_sub(a.floatval(), Float128::op(b)));
}

//............................................
// fixnum - double float@
LispObject Difference::op(Fixnum a, double b)
{   return make_boxfloat((double)a.intval() - b, TYPE_DOUBLE_FLOAT);
}
// bignum - double float
LispObject Difference::op(uint64_t *a, double b)
{   return make_boxfloat(Float::op(a) - b, TYPE_DOUBLE_FLOAT);
}
// rational - double float
LispObject Difference::op(Rat a, double b)
{   return make_boxfloat(Float::op(a) - b, TYPE_DOUBLE_FLOAT);
}
// complex - double float
LispObject Difference::op(Cpx a, double b)
{   return make_complex(Difference::op(a.real_part(), b), a.imag_part());
}
// short float - double float
LispObject Difference::op(SFlt a, double b)
{   return make_boxfloat(a.floatval() - b, TYPE_DOUBLE_FLOAT);
}
// single float - double float
LispObject Difference::op(Flt a, double b)
{   return make_boxfloat(a.floatval() - b, TYPE_DOUBLE_FLOAT);
}
// double float - double float
LispObject Difference::op(double a, double b)
{   return make_boxfloat(a - b, TYPE_DOUBLE_FLOAT);
}
// long float - double float
LispObject Difference::op(LFlt a, double b)
{   return make_boxfloat128(f128_sub(a.floatval(), Float128::op(b)));
}
//............................................
// fixnum - long float
LispObject Difference::op(Fixnum a, LFlt b)
{   return make_boxfloat128(f128_sub(Float128::op(a), b.floatval()));
}
// bignum - long float
LispObject Difference::op(uint64_t *a, LFlt b)
{   return make_boxfloat128(f128_sub(Float128::op(a), b.floatval()));
}
// rational - long float
LispObject Difference::op(Rat a, LFlt b)
{   return make_boxfloat128(f128_sub(Float128::op(a), b.floatval()));
}
// complex - long float
LispObject Difference::op(Cpx a, LFlt b)
{   return make_complex(Difference::op(a.real_part(), b), a.imag_part());
}
// short float - long float
LispObject Difference::op(SFlt a, LFlt b)
{   return make_boxfloat128(f128_sub(Float128::op(a), b.floatval()));
}
// single float - long float
LispObject Difference::op(Flt a, LFlt b)
{   return make_boxfloat128(f128_sub(Float128::op(a), b.floatval()));
}
// double float - long float
LispObject Difference::op(double a, LFlt b)
{   return make_boxfloat128(f128_sub(Float128::op(a), b.floatval()));
}
// long float - long float
LispObject Difference::op(LFlt a, LFlt b)
{   return make_boxfloat128(f128_sub(a.floatval(), b.floatval()));
}

// minus

LispObject Minus::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Minus>("minus", a);
}


LispObject Minus::op(Fixnum a)
{   return nil; //(double)a.intval();
}


LispObject Minus::op(uint64_t *a)
{   return arithlib_lowlevel::Minus::op(a);
}

LispObject Minus::op(Rat a)
{   return nil; //Minus::op(a.numerator()) / Minus::op(a.denominator());
}

LispObject Minus::op(Cpx a)
{   aerror1("bad argument for float", a.value());
}

LispObject Minus::op(SFlt a)
{   return nil;// a.floatval();
}

LispObject Minus::op(Flt a)
{   return nil; //a.floatval();
}

LispObject Minus::op(double a)
{   return nil;
}

LispObject Minus::op(LFlt a)
{   float64_t f = f128_to_f64(a.floatval());
// Ha ha - the jolly activity here is a response to the Strict Aliasing Rules
// that (I believe) allow me to feel safe if I move things treating it as
// byte data.
    double d;
    memcpy(&d, &f, sizeof(double));
    return nil;
}


// end of arith-plus.cpp

#endif // ARITHLIB
