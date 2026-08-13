// arith-times.cpp                         Copyright (C) 2022-2026 Codemist

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


// Times, Quotient, Remainder, Divide etc

//
// As with much of the generic arithmetic code there is real ugliness
// dealing with all combinations of argument types. The types in play are
//  LispObject, small integer, large integer, ratio, short, single, double
// and long floats, complex. That is 9 cases for a unary operator and 81
// for a binary one. In quite a few of the cases the code needed for
// a range of the combinations is the same and one might have hoped that
// most of them could be dealt with by a single copy of that code as the
// body of a template. However there are also rather a lot of cases where
// different type-specific code is called for and I have not sorted out
// a good way to exploit templates. Thus the code here is rather unpleasantly
// repetitive!

#include "headers.h"
#include <complex>

namespace CSL_LISP
{

// fixnum * fixnum
// LispObject Times::op(Fixnum a, Fixnum b)
// {   return arithlib_lowlevel::Times::op(int_of_fixnum(a), int_of_fixnum(b));
// }

// bignum * fixnum
// LispObject Times::op(std::uint64_t* a, Fixnum b)
// {   return arithlib_lowlevel::Times::op(a, int_of_fixnum(b));
// }

// rational * fixnum
LispObject Times::op(Rat a, Fixnum b)
{   if (b == fixnum_of_int(0)) return b;
    else if (b == fixnum_of_int(1)) return a.value();
    return make_ratio(Binary(Times,
                             a.numerator(),
                             Binary(Times, a.denominator(), b)),
                      a.denominator());
}

// complex * fixnum
LispObject Times::op(Cpx a, Fixnum b)
{   return make_complex(Binary(Times, a.real_part(), b),
                        Binary(Times, a.imag_part(), b));
}

// short float * fixnum
LispObject Times::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() *
                            static_cast<double>(int_of_fixnum(b)));
}

// single float * fixnum
LispObject Times::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() *
                             static_cast<double>(int_of_fixnum(b)));
}

// double float * fixnum
LispObject Times::op(double a, Fixnum b)
{   return make_boxfloat(a * static_cast<double>(int_of_fixnum(b)));
}

// long float * fixnum
LispObject Times::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a * (FLOAT_128)int_of_fixnum(b));
}

// fixnum * bignum
// LispObject Times::op(Fixnum a, std::uint64_t* b)
// {   return Times::op(b, a);
// }

// bignum * bignum
// LispObject Times::op(std::uint64_t* a, std::uint64_t* b)
// {   return arithlib_lowlevel::Times::op(a, b);
// }

// rational * bignum
LispObject Times::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    LispObject cofactor = Binary(Quotient, bignum_value(b), g);
    return make_ratio(Binary(Times, a.numerator(), cofactor),
                      Binary(Quotient,a.denominator(), g));
}

// complex * bignum
LispObject Times::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Times, a.real_part(), bignum_value(b)),
                        Binary(Times, a.imag_part(), bignum_value(b)));
}

// short float * bignum
LispObject Times::op(SFlt a, std::uint64_t* b)
{   return pack_short_float(a.floatval() * RawFloat::op(b));
}

// single float * bignum
LispObject Times::op(Flt a, std::uint64_t* b)
{   return pack_single_float(a.floatval() * RawFloat::op(b));
}

// double float * bignum
LispObject Times::op(double a, std::uint64_t* b)
{   return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}

// long float * bignum
LispObject Times::op(FLOAT_128 a, std::uint64_t* b)
{   return make_boxfloat128(a * Float128::op(b));
}

// fixnum * rational
LispObject Times::op(Fixnum a, Rat b)
{   return Times::op(b, a);
}

// bignum * rational
LispObject Times::op(std::uint64_t* a, Rat b)
{   return Times::op(b, a);
}

// rational * rational
LispObject Times::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.denominator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.numerator());
    LispObject na = Binary(Quotient,a.numerator(), g1);
    LispObject nb = Binary(Quotient,b.numerator(), g2);
    LispObject da = Binary(Quotient,a.denominator(), g2);
    LispObject db = Binary(Quotient,b.denominator(), g1);
    return make_ratio(Binary(Times, na, nb), Binary(Times, da, db));
}

// complex * rational
LispObject Times::op(Cpx a, Rat b)
{   return make_complex(Binary(Times, a.real_part(), b.value()),
                        Binary(Times, a.imag_part(), b.value()));
}

// short float * rational
// The key mess here is that I do not want to trigger exponent overflow
// early, but the numerator and denominators of the rational could be
// really huge.
LispObject Times::op(SFlt a, Rat b)
{   std::int64_t xb;
    double d = Frexp::op(b, xb); // A special version for internal use!
    int x;
    d *= std::frexp(a.floatval(), &x);
    x += xb;
    d = std::ldexp(d, x);
    return pack_short_float(d);
}

// single float * rational
LispObject Times::op(Flt a, Rat b)
{   std::int64_t xb;
    double d = Frexp::op(b, xb);
    int x;
    d *= std::frexp(a.floatval(), &x);
    x += xb;
    d = std::ldexp(d, x);
    return pack_single_float(d);
}

// double float * rational
LispObject Times::op(double a, Rat b)
{   std::int64_t xb;
    double d = Frexp::op(b, xb);
    int x;
    d *= std::frexp(a, &x);
    x += xb;
    d = std::ldexp(d, x);
    return make_boxfloat(d);
}

// long float * rational
LispObject Times::op(FLOAT_128 a, Rat b)
{   std::int64_t xb;
    FLOAT_128 d = Frexp128::op(b, xb);
    int32_t x;
    FLOAT_128 d1 = a;
    d1 = frexp(d1, x);
    x += xb;
    d = d * d1;
    return ldexp(d, x);
}

// fixnum * complex
LispObject Times::op(Fixnum a, Cpx b)
{   return Times::op(b, a);
}

// bignum * complex
LispObject Times::op(std::uint64_t* a, Cpx b)
{   return Times::op(b, a);
}

// rational * complex
LispObject Times::op(Rat a, Cpx b)
{   return Times::op(b, a);
}

// complex * complex
LispObject Times::op(Cpx a, Cpx b)
{   return make_complex(
               Binary(Difference, Binary(Times, a.real_part(), b.real_part()),
                              Binary(Times, a.imag_part(), b.imag_part())),
               Binary(Plus, Binary(Times, a.real_part(), b.imag_part()),
                            Binary(Times, a.imag_part(), b.real_part())));
}

// short float * complex
LispObject Times::op(SFlt a, Cpx b)
{   return make_complex(Binary(Times, b.real_part(), a.value()),
                        Binary(Times, b.imag_part(), a.value()));
}

// single float * complex
LispObject Times::op(Flt a, Cpx b)
{   return make_complex(Binary(Times, b.real_part(), a.value()),
                        Binary(Times, b.imag_part(), a.value()));
}

// double float * complex
LispObject Times::op(double a, Cpx b)
{   return make_complex(Binary(Times, b.real_part(), make_boxfloat(a)),
                        Binary(Times, b.imag_part(), make_boxfloat(a)));
}

// long float * complex
LispObject Times::op(FLOAT_128 a, Cpx b)
{   return make_complex(Binary(Times, b.real_part(), make_boxfloat128(a)),
                        Binary(Times, b.imag_part(), make_boxfloat128(a)));
}

// fixnum * short float
LispObject Times::op(Fixnum a, SFlt b)
{   return Times::op(b, a);
}

// bignum * short float
LispObject Times::op(std::uint64_t* a, SFlt b)
{   return Times::op(b, a);
}

// rational * short float
LispObject Times::op(Rat a, SFlt b)
{   return Times::op(b, a);
}

// complex * short float
LispObject Times::op(Cpx a, SFlt b)
{   return Times::op(b, a);
}

// short float * short float
LispObject Times::op(SFlt a, SFlt b)
{   return pack_short_float(a.floatval() * b.floatval());
}

// single float * short float
LispObject Times::op(Flt a, SFlt b)
{   return pack_single_float(a.floatval() * b.floatval());
}

// double float * short float
LispObject Times::op(double a, SFlt b)
{   return make_boxfloat(a * b.floatval());
}

// long float * short float
LispObject Times::op(FLOAT_128 a, SFlt b)
{   return make_boxfloat128(a * Float128::op(b));
}

// fixnum * single float
LispObject Times::op(Fixnum a, Flt b)
{   return Times::op(b, a);
}

// bignum * single float
LispObject Times::op(std::uint64_t* a, Flt b)
{   return Times::op(b, a);
}

// rational * single float
LispObject Times::op(Rat a, Flt b)
{   return Times::op(b, a);
}

// complex * single float
LispObject Times::op(Cpx a, Flt b)
{   return Times::op(b, a);
}

// short float * single float
LispObject Times::op(SFlt a, Flt b)
{   return Times::op(b, a);
}

// single float * single float
LispObject Times::op(Flt a, Flt b)
{   return pack_short_float(a.floatval() * b.floatval());
}

// double float * single float
LispObject Times::op(double a, Flt b)
{   return make_boxfloat(a * b.floatval());
}

// long float * single float
LispObject Times::op(FLOAT_128 a, Flt b)
{   return make_boxfloat128(a * Float128::op(b));
}

// fixnum * double float
LispObject Times::op(Fixnum a, double b)
{   return Times::op(b, a);
}

// bignum * double float
LispObject Times::op(std::uint64_t* a, double b)
{   return Times::op(b, a);
}

// rational * double float
LispObject Times::op(Rat a, double b)
{   return Times::op(b, a);
}

// complex * double float
LispObject Times::op(Cpx a, double b)
{   return Times::op(b, a);
}

// short float * double float
LispObject Times::op(SFlt a, double b)
{   return Times::op(b, a);
}

// single float * double float
LispObject Times::op(Flt a, double b)
{   return Times::op(b, a);
}

// double float * double float
LispObject Times::op(double a, double b)
{   return make_boxfloat(a * b);
}

// long float * double float
LispObject Times::op(FLOAT_128 a, double b)
{   return make_boxfloat128(a * Float128::op(b));
}

// fixnum * long float
LispObject Times::op(Fixnum a, FLOAT_128 b)
{   return Times::op(b, a);
}

// bignum * long float
LispObject Times::op(std::uint64_t* a, FLOAT_128 b)
{   return Times::op(b, a);
}

// rational * long float
LispObject Times::op(Rat a, FLOAT_128 b)
{   return Times::op(b, a);
}

// complex * long float
LispObject Times::op(Cpx a, FLOAT_128 b)
{   return Times::op(b, a);
}

// short float * long float
LispObject Times::op(SFlt a, FLOAT_128 b)
{   return Times::op(b, a);
}

// single float * long float
LispObject Times::op(Flt a, FLOAT_128 b)
{   return Times::op(b, a);
}

// double float * long float
LispObject Times::op(double a, FLOAT_128 b)
{   return Times::op(b, a);
}

// long float * long float
LispObject Times::op(FLOAT_128 a, FLOAT_128 b)
{   return make_boxfloat128(a * b);
}

// fixnum * fixnum
LispObject ClassicalTimes::op(Fixnum a, Fixnum b)
{   return Times::op(a, b);
}

// bignum * fixnum
LispObject ClassicalTimes::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::ClassicalTimes::op(a, int_of_fixnum(b));
}

// rational * fixnum
LispObject ClassicalTimes::op(Rat a, Fixnum b)
{   return Times::op(a, b);
}

// complex * fixnum
LispObject ClassicalTimes::op(Cpx a, Fixnum b)
{   return Times::op(a, b);
}

// short float * fixnum
LispObject ClassicalTimes::op(SFlt a, Fixnum b)
{   return Times::op(a, b);
}

// single float * fixnum
LispObject ClassicalTimes::op(Flt a, Fixnum b)
{   return Times::op(a, b);
}

// double float * fixnum
LispObject ClassicalTimes::op(double a, Fixnum b)
{   return Times::op(a, b);
}

// long float * fixnum
LispObject ClassicalTimes::op(FLOAT_128 a, Fixnum b)
{   return Times::op(a, b);
}

// fixnum * bignum
LispObject ClassicalTimes::op(Fixnum a, std::uint64_t* b)
{   return ClassicalTimes::op(b, a);
}

// bignum * bignum
LispObject ClassicalTimes::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::ClassicalTimes::op(a, b);
}

// rational * bignum
LispObject ClassicalTimes::op(Rat a, std::uint64_t* b)
{   return Times::op(a, b);
}

// complex * bignum
LispObject ClassicalTimes::op(Cpx a, std::uint64_t* b)
{   return Times::op(a, b);
}

// short float * bignum
LispObject ClassicalTimes::op(SFlt a, std::uint64_t* b)
{   return Times::op(a, b);
}

// single float * bignum
LispObject ClassicalTimes::op(Flt a, std::uint64_t* b)
{   return Times::op(a, b);
}

// double float * bignum
LispObject ClassicalTimes::op(double a, std::uint64_t* b)
{   return Times::op(a, b);
}

// long float * bignum
LispObject ClassicalTimes::op(FLOAT_128 a, std::uint64_t* b)
{   return Times::op(a, b);
}

// fixnum * rational
LispObject ClassicalTimes::op(Fixnum a, Rat b)
{   return Times::op(a, b);
}

// bignum * rational
LispObject ClassicalTimes::op(std::uint64_t* a, Rat b)
{   return Times::op(a, b);
}

// rational * rational
LispObject ClassicalTimes::op(Rat a, Rat b)
{   return Times::op(a, b);
}

// complex * rational
LispObject ClassicalTimes::op(Cpx a, Rat b)
{   return Times::op(a, b);
}

LispObject ClassicalTimes::op(SFlt a, Rat b)
{   return Times::op(a, b);
}

// single float * rational
LispObject ClassicalTimes::op(Flt a, Rat b)
{   return Times::op(a, b);
}

// double float * rational
LispObject ClassicalTimes::op(double a, Rat b)
{   return Times::op(a, b);
}

// long float * rational
LispObject ClassicalTimes::op(FLOAT_128 a, Rat b)
{   return Times::op(a, b);
}

// fixnum * complex
LispObject ClassicalTimes::op(Fixnum a, Cpx b)
{   return Times::op(a, b);
}

// bignum * complex
LispObject ClassicalTimes::op(std::uint64_t* a, Cpx b)
{   return Times::op(a, b);
}

// rational * complex
LispObject ClassicalTimes::op(Rat a, Cpx b)
{   return Times::op(a, b);
}

// complex * complex
LispObject ClassicalTimes::op(Cpx a, Cpx b)
{   return Times::op(a, b);
}

// short float * complex
LispObject ClassicalTimes::op(SFlt a, Cpx b)
{   return Times::op(a, b);
}

// single float * complex
LispObject ClassicalTimes::op(Flt a, Cpx b)
{   return Times::op(a, b);
}

// double float * complex
LispObject ClassicalTimes::op(double a, Cpx b)
{   return Times::op(a, b);
}

// long float * complex
LispObject ClassicalTimes::op(FLOAT_128 a, Cpx b)
{   return Times::op(a, b);
}

// fixnum * short float
LispObject ClassicalTimes::op(Fixnum a, SFlt b)
{   return Times::op(a, b);
}

// bignum * short float
LispObject ClassicalTimes::op(std::uint64_t* a, SFlt b)
{   return Times::op(a, b);
}

// rational * short float
LispObject ClassicalTimes::op(Rat a, SFlt b)
{   return Times::op(a, b);
}

// complex * short float
LispObject ClassicalTimes::op(Cpx a, SFlt b)
{   return Times::op(a, b);
}

// short float * short float
LispObject ClassicalTimes::op(SFlt a, SFlt b)
{   return Times::op(a, b);
}

// single float * short float
LispObject ClassicalTimes::op(Flt a, SFlt b)
{   return Times::op(a, b);
}

// double float * short float
LispObject ClassicalTimes::op(double a, SFlt b)
{   return Times::op(a, b);
}

// long float * short float
LispObject ClassicalTimes::op(FLOAT_128 a, SFlt b)
{   return Times::op(a, b);
}

// fixnum * single float
LispObject ClassicalTimes::op(Fixnum a, Flt b)
{   return Times::op(a, b);
}

// bignum * single float
LispObject ClassicalTimes::op(std::uint64_t* a, Flt b)
{   return Times::op(a, b);
}

// rational * single float
LispObject ClassicalTimes::op(Rat a, Flt b)
{   return Times::op(a, b);
}

// complex * single float
LispObject ClassicalTimes::op(Cpx a, Flt b)
{   return Times::op(a, b);
}

// short float * single float
LispObject ClassicalTimes::op(SFlt a, Flt b)
{   return Times::op(a, b);
}

// single float * single float
LispObject ClassicalTimes::op(Flt a, Flt b)
{   return Times::op(a, b);
}

// double float * single float
LispObject ClassicalTimes::op(double a, Flt b)
{   return Times::op(a, b);
}

// long float * single float
LispObject ClassicalTimes::op(FLOAT_128 a, Flt b)
{   return Times::op(a, b);
}

// fixnum * double float
LispObject ClassicalTimes::op(Fixnum a, double b)
{   return Times::op(a, b);
}

// bignum * double float
LispObject ClassicalTimes::op(std::uint64_t* a, double b)
{   return Times::op(a, b);
}

// rational * double float
LispObject ClassicalTimes::op(Rat a, double b)
{   return Times::op(a, b);
}

// complex * double float
LispObject ClassicalTimes::op(Cpx a, double b)
{   return Times::op(a, b);
}

// short float * double float
LispObject ClassicalTimes::op(SFlt a, double b)
{   return Times::op(a, b);
}

// single float * double float
LispObject ClassicalTimes::op(Flt a, double b)
{   return Times::op(a, b);
}

// double float * double float
LispObject ClassicalTimes::op(double a, double b)
{   return Times::op(a, b);
}

// long float * double float
LispObject ClassicalTimes::op(FLOAT_128 a, double b)
{   return Times::op(a, b);
}

// fixnum * long float
LispObject ClassicalTimes::op(Fixnum a, FLOAT_128 b)
{   return Times::op(a, b);
}

// bignum * long float
LispObject ClassicalTimes::op(std::uint64_t* a, FLOAT_128 b)
{   return Times::op(a, b);
}

// rational * long float
LispObject ClassicalTimes::op(Rat a, FLOAT_128 b)
{   return Times::op(a, b);
}

// complex * long float
LispObject ClassicalTimes::op(Cpx a, FLOAT_128 b)
{   return Times::op(a, b);
}

// short float * long float
LispObject ClassicalTimes::op(SFlt a, FLOAT_128 b)
{   return Times::op(a, b);
}

// single float * long float
LispObject ClassicalTimes::op(Flt a, FLOAT_128 b)
{   return Times::op(a, b);
}

// double float * long float
LispObject ClassicalTimes::op(double a, FLOAT_128 b)
{   return Times::op(a, b);
}

// long float * long float
LispObject ClassicalTimes::op(FLOAT_128 a, FLOAT_128 b)
{   return Times::op(a, b);
}

// fixnum ** fixnum
LispObject Expt::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Pow::op(int_of_fixnum(a),
                                      static_cast<std::int64_t>(int_of_fixnum(b)));
}

// bignum ** fixnum
LispObject Expt::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Pow::op(a,
                                      static_cast<std::int64_t>(int_of_fixnum(b)));
}

LispObject generic_expt(LispObject a, std::int64_t n)
{   if (n == 0) return fixnum_of_int(1);
    else if (n == 1) return a;
    else if (n < 0) return generic_expt(Unary(Reciprocal, a), -n);
    else
    {   LispObject aa = generic_expt(a, n/2);
        aa = Unary(Square, aa);
        if ((n & 1) != 0) aa = Binary(Times, aa, a);
        return aa;
    }
}

// rational ** fixnum
LispObject Expt::op(Rat a, Fixnum b)
{   std::int64_t n = int_of_fixnum(b);
    if (n == 0) return fixnum_of_int(1);
    else if (n == 1) return a.value();
    else return generic_expt(a.value(), n);
}

LispObject match_type(LispObject in, int value)
{   switch (in & XTAG_BITS)
    {   case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(in))
            {   case SINGLE_FLOAT_HEADER:
                    return pack_single_float(static_cast<double>(value));
                case DOUBLE_FLOAT_HEADER:
                    return make_boxfloat(static_cast<double>(value));
                case LONG_FLOAT_HEADER:
                    return make_boxfloat128((FLOAT_128)(value));
                default:
                    return aerror1("Invalid component in complex number", in);
            }
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            switch (type_of_header(numhdr(in)))
            {   case TYPE_NEW_BIGNUM:
                    return fixnum_of_int(value);
                case TYPE_RATNUM:
                    return make_ratio(fixnum_of_int(value), fixnum_of_int(1));
                case TYPE_COMPLEX_NUM:
                default:
                    return aerror1("Invalid component in complex number", in);
            }
        default:
        case TAG_FIXNUM:
            return fixnum_of_int(value);
        case XTAG_SFLOAT:
            if ((in & XTAG_FLOAT32) != 0)
                return pack_single_float(static_cast<double>(value));
            else return pack_short_float(static_cast<double>(value));
    }
}

LispObject Expt::op(Cpx a, Fixnum b)
{   std::int64_t n = int_of_fixnum(b);
// A complex number ought to have both components the same type, but that
// could be integer, rational or one of the various sorts of float. If I
// raise it to the power zero I want a result that has value 1 + 0i but both
// the "1" and the "0" should match the input in type.
    if (n == 0) return make_complex(match_type(a.real_part(), 1),
                                        match_type(a.imag_part(), 0));
    else if (n == 1) return a.value();
    if (n < 0)
    {   n = -n;
        a = Reciprocal::op(a);
    }
    return generic_expt(a.value(), n);
}

// short float ** fixnum
LispObject Expt::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() * static_cast<double>(int_of_fixnum(b)));
}

// single float ** fixnum
LispObject Expt::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() * static_cast<double>(int_of_fixnum(b)));
}

// double float ** fixnum
LispObject Expt::op(double a, Fixnum b)
{   return make_boxfloat(a * static_cast<double>(int_of_fixnum(b)));
}

// long float ** fixnum

LispObject Expt::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(expt(a, (int128_t)b));
}

// fixnum ** bignum
LispObject Expt::op(Fixnum a, std::uint64_t* b)
{   std::int64_t aa = int_of_fixnum(a);
    switch (aa)
    {   case 0:
            return fixnum_of_int(0);
        case -1:
            if (Oddp::op(b)) return fixnum_of_int(-1);
        // drop through;
        case 1:
            return fixnum_of_int(1);
        default:
            if (arithlib_lowlevel::Minusp::op(b)) return fixnum_of_int(0);
            return aerror1("bad argument for expt",
                reinterpret_cast<LispObject>(
                    TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
    }
}

// bignum ** bignum
LispObject Expt::op(std::uint64_t* a, std::uint64_t* b)
{   if (arithlib_lowlevel::Minusp::op(b)) return fixnum_of_int(0);
    return aerror1("bad argument for expt",
        reinterpret_cast<LispObject>(
            TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
}

// rational ** bignum
LispObject Expt::op(Rat a, std::uint64_t* b)
{   return make_ratio(Binary(Expt, a.numerator(), bignum_value(b)),
                      Binary(Expt, a.denominator(), bignum_value(b)));
}

// complex ** bignum
LispObject Expt::op(Cpx a, std::uint64_t* b)
{
// I suppose that huge powers of (0+0i), (1+0i), (0+1i), (-1+0i), (0+-1i)
// can give sane results!
    if (BoolUnary(Zerop, a.real_part()) &&
        BoolUnary(Zerop, a.imag_part()))
    {   if (Minusp::op(b))
            return aerror1("bad argument for expt",
                reinterpret_cast<LispObject>(
                    TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
        else return a.value();  // (0+0i)^N
    }
    if (BoolUnary(Onep, a.real_part()) &&
        BoolUnary(Zerop, a.imag_part())) return a.value();
    if (BoolUnary(Zerop, a.real_part()) &&
        BoolUnary(Onep, a.imag_part()))
    {   switch (b[0] & 3)
        {   case 0: return make_complex(a.imag_part(), a.real_part());
            case 1: return make_complex(a.real_part(), a.imag_part());
            case 2: return make_complex(Unary(Minus, a.imag_part()),
                                        a.real_part());
            case 3: return make_complex(a.real_part(),
                                        Unary(Minus, a.imag_part()));
        }
    }
    if (BoolUnary(MinusOnep, a.real_part()) &&
        BoolUnary(Zerop, a.imag_part()))
    {   if (Evenp::op(b)) return make_complex(Unary(Minus, a.real_part()),
                                              a.imag_part());
        else return a.value();
    }
    if (BoolUnary(Zerop, a.real_part()) &&
        BoolUnary(MinusOnep, a.imag_part()))
    {   switch (b[0] & 3)
        {   case 0: return make_complex(Unary(Minus, a.imag_part()),
                                        a.real_part());
            case 1: return make_complex(a.real_part(), a.imag_part());
            case 2: return make_complex(a.imag_part(), a.real_part());
            case 3: return make_complex(a.real_part(),
                                        Unary(Minus, a.imag_part()));
        }
    }
    return aerror1("bad argument for expt",
        reinterpret_cast<LispObject>(
            TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
}

// short float ** bignum
LispObject Expt::op(SFlt a, std::uint64_t* b)
{   return aerror1("bad argument for expt",
        reinterpret_cast<LispObject>(
            TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
}

// single float ** bignum
LispObject Expt::op(Flt a, std::uint64_t* b)
{   return aerror1("bad argument for expt",
        reinterpret_cast<LispObject>(
            TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
}

// double float ** bignum
LispObject Expt::op(double a, std::uint64_t* b)
{   return aerror1("bad argument for expt",
        reinterpret_cast<LispObject>(
            TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
}

// long float ** bignum
LispObject Expt::op(FLOAT_128 a, std::uint64_t* b)
{   return aerror1("bad argument for expt",
        reinterpret_cast<LispObject>(
            TAG_NUMBERS+reinterpret_cast<char *>(b)-8));
}

// fixnum ** rational
LispObject Expt::op(Fixnum a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// bignum ** rational
//
// The code here could suffer from premature overflow in the case of an
// input bignum that was outside the range of floating point values and
// a second argument with value < 1. The same issue will arise in cases
// of a bignum raised to a floating point value. I could deal with that
// by using Frexp to split the bignum into a mantissa and exponent form.
// I could then compute 2.0**(n*exponent) and finally combine. But that is
// not for today. I will however leave a message to myself in to tend to
// remind me to come back to it!
//
LispObject Expt::op(std::uint64_t* a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// rational ** rational
// Should eg (9/16)^(1/2) remain rational rather that ending up as a float?
LispObject Expt::op(Rat a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// complex ** rational
LispObject Expt::op(Cpx a, Rat b)
{   std::complex<double> aa(RawFloat::op(a.real_part()),
                            RawFloat::op(a.imag_part()));
    std::complex<double> bb(RawFloat::op(b), 0.0);
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// short float ** rational
LispObject Expt::op(SFlt a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// single float ** rational
LispObject Expt::op(Flt a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// double float ** rational
LispObject Expt::op(double a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// long float ** rational
LispObject Expt::op(FLOAT_128 a, Rat b)
{   return Expt::op(a, FLOAT_128(Float128::op(b)));
}

// fixnum ** complex
LispObject Expt::op(Fixnum a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// bignum ** complex
LispObject Expt::op(std::uint64_t* a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// rational ** complex
LispObject Expt::op(Rat a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// complex ** complex
//
// If any component of either complex input is a 128-bit float then
// I should handle that and return a complex value built of two
// 128-bit floats. For now I just fold down to 64-bits.
//
//    a**b = exp(b*log(a))
// if a = r*exp(i*theta) then log(a) = log(r) + theta
// Where a = x + iy => r = sqrt(x^2+y^2) and theta=atan(y/x);
// and exp(x + iy) = exp(x)*(cos y + i*sin x)
//
// So to implement all this I need the following functions on 128-bit
// (real) floats:
//    exp, log, sqrt, atan, sin, cos.
// Ha ha. Those can go in arith_float128.cpp at some stage but the
// basic techniques can be:
//   exp(x) == exp(intpart(x)) * exp(fracpart(x))
//     first bit done by raising e to an integer power. Second
//     part via power series exp(x) = 1 + x + x^2/2! + x^3/3! + ...
//                                    + x^31/31!
//     which is about what is needed to get accuracy.
//   sin and cos: range reduction to 0..pi/4 then power series ending in
//     the x^29/29! term.
//   sqrt: Newton Raphson . This is cheap!
//   atan: range reduction using atan(1/x) = pi/2 - atan x
//                               atan x = atan c + atan((x-c)/(1+x*c))
//     where the first rule ensures x<=1 and by having a modest table
//     the second could leave x <= 1/10. Then the series
//     atan x = x - x^3/3 + x^5/5 ... x^33/33
//   log: start with frexp that leaves a range 1-2 to cope with. Use
//     log x = log c + log(x/c) for some tabulated values of c and log c
//     to reduce range to 1..1.1 and then use
//     log(1+x) = x - x/2 + ... x^33/33
// Use of the raw Taylor Series will not be as efficient as I could achieve
// with some minimax approximations, and the simplistic use of the formulae
// will leave some inaccuracies, but basically I do not care that much. If I
// get this much working I will be amazed!

LispObject Expt::op(Cpx a, Cpx b)
{   if (is_long_float(a.real_part()) ||
        is_long_float(a.imag_part()) ||
        is_long_float(b.real_part()) ||
        is_long_float(b.imag_part()))
    {   FLOAT_128 ax = Unary(Float128, a.real_part());
        FLOAT_128 ay = Unary(Float128, a.imag_part());
        FLOAT_128 bx = Unary(Float128, b.real_part());
        FLOAT_128 by = Unary(Float128, b.imag_part());
        FLOAT_128 rx, ry;
        COMPLEX_128 aa(ax, ay);
        COMPLEX_128 bb(bx, by);
        COMPLEX_128 c = expt(aa, bb);
        rx = c.real();
        ry = c.imag();
        return make_complex(make_boxfloat128(rx), make_boxfloat128(ry));
    }
    std::complex<double> aa(RawFloat::op(a.real_part()),
                            RawFloat::op(a.imag_part()));
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// short float ** complex
LispObject Expt::op(SFlt a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// single float ** complex
LispObject Expt::op(Flt a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// double float ** complex
LispObject Expt::op(double a, Cpx b)
{   std::complex<double> aa(a, 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// long float ** complex
LispObject Expt::op(FLOAT_128 a, Cpx b)
{   return Expt::op(Cpx(make_complex(make_boxfloat128(a),
                                     make_boxfloat128(LF_C(0.0)))),
                    b);
}

// fixnum ** short float
LispObject Expt::op(Fixnum a, SFlt b)
{   double aa = RawFloat::op(a),
               bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// bignum ** short float
LispObject Expt::op(std::uint64_t* a, SFlt b)
{   double aa = RawFloat::op(a),
               bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// rational ** short float
LispObject Expt::op(Rat a, SFlt b)
{   double aa = RawFloat::op(a),
               bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// complex ** short float
LispObject Expt::op(Cpx a, SFlt b)
{   std::complex<double> aa(RawFloat::op(a.real_part()),
                            RawFloat::op(a.imag_part()));
    std::complex<double> bb(RawFloat::op(b), 0.0);
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// short float ** short float
LispObject Expt::op(SFlt a, SFlt b)
{   double aa = RawFloat::op(a),
               bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// single float ** short float
LispObject Expt::op(Flt a, SFlt b)
{   double aa = RawFloat::op(a),
               bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// double float ** short float
LispObject Expt::op(double a, SFlt b)
{   double aa = RawFloat::op(a),
               bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// long float ** short float
LispObject Expt::op(FLOAT_128 a, SFlt b)
{   double aa = RawFloat::op(a),
           bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// fixnum ** single float
LispObject Expt::op(Fixnum a, Flt b)
{   double aa = RawFloat::op(a),
           bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// bignum ** single float
LispObject Expt::op(std::uint64_t* a, Flt b)
{   double aa = RawFloat::op(a),
           bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// rational ** single float
LispObject Expt::op(Rat a, Flt b)
{   double aa = RawFloat::op(a),
           bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// complex ** single float
LispObject Expt::op(Cpx a, Flt b)
{   std::complex<double> aa(RawFloat::op(a.real_part()),
                            RawFloat::op(a.imag_part()));
    std::complex<double> bb(RawFloat::op(b), 0.0);
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// short float ** single float
LispObject Expt::op(SFlt a, Flt b)
{   double aa = RawFloat::op(a),
               bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// single float ** single float
LispObject Expt::op(Flt a, Flt b)
{   double aa = RawFloat::op(a),
           bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// double float ** single float
LispObject Expt::op(double a, Flt b)
{   double aa = a,
           bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// long float ** single float
LispObject Expt::op(FLOAT_128 a, Flt b)
{   return Expt::op(a, FLOAT_128(Float128::op(b)));
}

// fixnum ** double float
LispObject Expt::op(Fixnum a, double b)
{   double aa = RawFloat::op(a),
           bb = b;
    return make_boxfloat(std::pow(aa, bb));
}

// bignum ** double float
LispObject Expt::op(std::uint64_t* a, double b)
{   double aa = RawFloat::op(a),
           bb = b;
    return make_boxfloat(std::pow(aa, bb));
}

// rational ** double float
LispObject Expt::op(Rat a, double b)
{   double aa = RawFloat::op(a),
           bb = b;
    return make_boxfloat(std::pow(aa, bb));
}

// complex ** double float
LispObject Expt::op(Cpx a, double b)
{   std::complex<double> aa(RawFloat::op(a.real_part()),
                            RawFloat::op(a.imag_part()));
    std::complex<double> bb(b, 0.0);
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()),
                        make_boxfloat(aa.imag()));
}

// short float ** double float
LispObject Expt::op(SFlt a, double b)
{   double aa = RawFloat::op(a),
           bb = b;
    return make_boxfloat(std::pow(aa, bb));
}

// single float ** double float
LispObject Expt::op(Flt a, double b)
{   double aa = RawFloat::op(a),
           bb = b;
    return make_boxfloat(std::pow(aa, bb));
}

// double float ** double float
LispObject Expt::op(double a, double b)
{   double aa = a,
           bb = b;
    return make_boxfloat(std::pow(aa, bb));
}

// long float ** double float
LispObject Expt::op(FLOAT_128 a, double b)
{   return Expt::op(a, FLOAT_128(Float128::op(b)));
}

// fixnum ** long float
LispObject Expt::op(Fixnum a, FLOAT_128 b)
{   return Expt::op(FLOAT_128(Float128::op(a)), b);
}

// bignum ** long float
LispObject Expt::op(std::uint64_t* a, FLOAT_128 b)
{   return Expt::op(FLOAT_128(Float128::op(a)), b);
}

// rational ** long float
LispObject Expt::op(Rat a, FLOAT_128 b)
{   return Expt::op(FLOAT_128(Float128::op(a)), b);
}

// complex ** long float
LispObject Expt::op(Cpx a, FLOAT_128 b)
{   return Expt::op(a, Cpx(make_complex(make_boxfloat128(b),
                                        make_boxfloat128(LF_C(0.0)))));
}

// short float ** long float
LispObject Expt::op(SFlt a, FLOAT_128 b)
{   return Expt::op(FLOAT_128(Float128::op(a)), b);
}

// single float ** long float
LispObject Expt::op(Flt a, FLOAT_128 b)
{   return Expt::op(FLOAT_128(Float128::op(a)), b);
}

// double float ** long float
LispObject Expt::op(double a, FLOAT_128 b)
{   return Expt::op(FLOAT_128(Float128::op(a)), b);
}

// long float ** long float


LispObject Expt::op(FLOAT_128 a, FLOAT_128 b)
{   return make_boxfloat128(expt(a, b));
}

// fixnum / fixnum
LispObject Quotient::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(int_of_fixnum(a), int_of_fixnum(b));
}

// bignum / fixnum
LispObject Quotient::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, int_of_fixnum(b));
}

// rational / fixnum
LispObject Quotient::op(Rat a, Fixnum b)
{   if (b == 1) return a.value();
    return make_ratio(Binary(Quotient,
                             a.numerator(),
                             b),
                      a.denominator());
}

// complex / fixnum
LispObject Quotient::op(Cpx a, Fixnum b)
{   if (b == 1) return a.v;
    return make_complex(Binary(Quotient, a.real_part(), b),
                        Binary(Quotient, a.imag_part(), b));
}

// short float / fixnum
LispObject Quotient::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() /
                            static_cast<double>(int_of_fixnum(b)));
}

// single float / fixnum
LispObject Quotient::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() /
                             static_cast<double>(int_of_fixnum(b)));
}

// double float / fixnum
LispObject Quotient::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float / fixnum
LispObject Quotient::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum / bignum
LispObject Quotient::op(Fixnum a, std::uint64_t* b)
{
// There is one special case where this is not zero. That is when
// a = -K and b is K where the first is representable as a fixnum and
// the second has to be a bignum... all because of twos complement
// assymetry of range.
    if (arithlib_implementation::numberSize(b) == 1 &&
        a == -static_cast<int64_t>(b[0]))
        return fixnum_of_int(-1);
    return fixnum_of_int(0);
}

// bignum / bignum
LispObject Quotient::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Quotient::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(),
                             Binary(Quotient, bignum_value(b), g)),
                     Binary(Quotient, a.denominator(), g));
}

// complex / bignum
LispObject Quotient::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Quotient, a.real_part(), bignum_value(b)),
                        Binary(Quotient, a.imag_part(), bignum_value(b)));
}

// short float / bignum
LispObject Quotient::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Quotient::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Quotient::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Quotient::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Quotient::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(Quotient, a, g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Quotient::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(Quotient, bignum_value(a), g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Quotient::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(Quotient,a.numerator(), g1);
    LispObject nb = Binary(Quotient,b.denominator(), g2);
    LispObject da = Binary(Quotient,a.denominator(), g2);
    LispObject db = Binary(Quotient,b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Quotient::op(Cpx a, Rat b)
{   return make_complex(Binary(Quotient,a.real_part(), b.value()),
                        Binary(Quotient,a.imag_part(), b.value()));
}

// short float / rational
LispObject Quotient::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Quotient::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Quotient::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Quotient::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Quotient::op(Fixnum a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a, conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// bignum / complex
LispObject Quotient::op(std::uint64_t* a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, bignum_value(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// rational / complex
LispObject Quotient::op(Rat a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// complex / complex
LispObject Quotient::op(Cpx a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// short float / complex
LispObject Quotient::op(SFlt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// single float / complex
LispObject Quotient::op(Flt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// double float / complex
LispObject Quotient::op(double a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, make_boxfloat(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// long float / complex
LispObject Quotient::op(FLOAT_128 a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, make_boxfloat128(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Quotient, num, den);
}

// fixnum / short float
LispObject Quotient::op(Fixnum a, SFlt b)
{   return pack_short_float(static_cast<double>(int_of_fixnum(a)) /
                            b.floatval());
}

// bignum / short float
LispObject Quotient::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_short_float(aa);
}

// rational / short float
LispObject Quotient::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_short_float(aa);
}
// complex / short float
LispObject Quotient::op(Cpx a, SFlt b)
{   return make_complex(
        Binary(Quotient,a.real_part(), b.value()),
        Binary(Quotient,a.imag_part(), b.value()));
}

// short float / short float
LispObject Quotient::op(SFlt a, SFlt b)
{   return pack_short_float(a.floatval() / b.floatval());
}

// single float / short float
LispObject Quotient::op(Flt a, SFlt b)
{   return pack_single_float(a.floatval() / b.floatval());
}

// double float / short float
LispObject Quotient::op(double a, SFlt b)
{   return make_boxfloat(a / b.floatval());
}

// long float / short float
LispObject Quotient::op(FLOAT_128 a, SFlt b)
{   return make_boxfloat128(a / Float128::op(b));
}

// fixnum / single float
LispObject Quotient::op(Fixnum a, Flt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) /
                             b.floatval());
}

// bignum / single float
LispObject Quotient::op(std::uint64_t* a, Flt b)
{   std::int64_t ax;
    int bx;
    double aa = Frexp::op(a, ax);
    double bb = std::frexp(b.floatval(), &bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// rational / single float
LispObject Quotient::op(Rat a, Flt b)
{   std::int64_t ax;
    int bx;
    double aa = Frexp::op(a, ax);
    double bb = std::frexp(b.floatval(), &bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// complex / single float
LispObject Quotient::op(Cpx a, Flt b)
{   return make_complex(
        Binary(Quotient,a.real_part(), b.value()),
        Binary(Quotient,a.imag_part(), b.value()));
}

// short float / single float
LispObject Quotient::op(SFlt a, Flt b)
{   return pack_single_float(a.floatval() / b.floatval());
}

// single float / single float
LispObject Quotient::op(Flt a, Flt b)
{   return pack_single_float(a.floatval() / b.floatval());
}

// double float / single float
LispObject Quotient::op(double a, Flt b)
{   return make_boxfloat(a / b.floatval());
}

// long float / single float
LispObject Quotient::op(FLOAT_128 a, Flt b)
{   return make_boxfloat128(a / Float128::op(b));
}

// fixnum / double float
LispObject Quotient::op(Fixnum a, double b)
{   return make_boxfloat(static_cast<double>(int_of_fixnum(a)) / b);
}

// bignum / double float
LispObject Quotient::op(std::uint64_t* a, double b)
{   std::int64_t ax;
    int bx;
    double aa = Frexp::op(a, ax);
    double bb = std::frexp(b, &bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// rational / double float
LispObject Quotient::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Quotient::op(Cpx a, double b)
{   return make_complex(
        Binary(Quotient,a.real_part(), b),
        Binary(Quotient,a.imag_part(), b));
}

// short float / double float
LispObject Quotient::op(SFlt a, double b)
{   return make_boxfloat(a.floatval() / b);
}

// single float / double float
LispObject Quotient::op(Flt a, double b)
{   return make_boxfloat(a.floatval() / b);
}

// double float / double float
LispObject Quotient::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Quotient::op(FLOAT_128 a, double b)
{   return make_boxfloat128(a / Float128::op(b));
}

// fixnum / long float
LispObject Quotient::op(Fixnum a, FLOAT_128 b)
{   return Quotient::op(FLOAT_128(Float128::op(a)), b);
}

// bignum / long float
LispObject Quotient::op(std::uint64_t* a, FLOAT_128 b)
{   return Quotient::op(FLOAT_128(Float128::op(a)), b);
// Imperfect wrt premature overflow if a is huge
}

// rational / long float
LispObject Quotient::op(Rat a, FLOAT_128 b)
{   return Quotient::op(FLOAT_128(Float128::op(a)), b);
}

// complex / long float
LispObject Quotient::op(Cpx a, FLOAT_128 b)
{   return make_complex(
        Binary(Quotient,a.real_part(), b),
        Binary(Quotient,a.imag_part(), b));
}

// short float / long float
LispObject Quotient::op(SFlt a, FLOAT_128 b)
{   return Quotient::op(FLOAT_128(Float128::op(a)), b);
}

// single float / long float
LispObject Quotient::op(Flt a, FLOAT_128 b)
{   return Quotient::op(FLOAT_128(Float128::op(a)), b);
}

// double float / long float
LispObject Quotient::op(double a, FLOAT_128 b)
{   return Quotient::op(FLOAT_128(Float128::op(a)), b);
}

// long float / long float
LispObject Quotient::op(FLOAT_128 a, FLOAT_128 b)
{   return make_boxfloat128(a / b);
}

// (quotient 22 7) => 3 and (!/!/ 22 7) => 3
// (/ 22 7) => 22/7 (a rational number)

// fixnum CL/ fixnum
LispObject CLQuotient::op(Fixnum a, Fixnum b)
{   std::int64_t aa = int_of_fixnum(a),
                 bb = int_of_fixnum(b),
                 u, v, g;
    u = aa >= 0 ? aa : -aa;
    v = bb >= 0 ? bb : -bb;
    if (v > u) { g = u; u = v; v = g; }
    else g = v;
    for (;;)
    {   v = u%v;
        if (v == 0) break;
        u = g;
        g = v;
    }
    aa /= g;
    bb /= g;
    if (bb < 0)
    {   aa = -aa;
        bb = -bb;
    }
    return make_ratio(make_lisp_integer64(aa), make_lisp_integer64(bb));
}

// bignum CL/ fixnum
LispObject CLQuotient::op(std::uint64_t* a, Fixnum b)
{   LispObject g = Gcdn::op(a, b);
    LispObject p = Binary(Quotient, bignum_value(a), g);
    LispObject q = Binary(Quotient, b, g);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational CL/ fixnum
LispObject CLQuotient::op(Rat a, Fixnum b)
{   if (b == fixnum_of_int(1)) return a.value();
    arithlib_abort("not coded yet");
}

// complex CL/ fixnum
LispObject CLQuotient::op(Cpx a, Fixnum b)
{   if (b == fixnum_of_int(1)) return a.v;
    return make_complex(Binary(CLQuotient, a.real_part(), b),
                        Binary(CLQuotient, a.imag_part(), b));
}

// short float CL/ fixnum
LispObject CLQuotient::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() /
                            static_cast<double>(int_of_fixnum(b)));
}

// single float CL/ fixnum
LispObject CLQuotient::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() /
                             static_cast<double>(int_of_fixnum(b)));
}

// double float CL/ fixnum
LispObject CLQuotient::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float CL/ fixnum
LispObject CLQuotient::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum CL/ bignum
LispObject CLQuotient::op(Fixnum a, std::uint64_t* b)
{   LispObject g = Gcdn::op(a, b);
    LispObject p = Binary(Quotient, a, g);
    LispObject q = Binary(Quotient, bignum_value(b), g);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum CL/ bignum
LispObject CLQuotient::op(std::uint64_t* a, std::uint64_t* b)
{   LispObject g = Gcdn::op(a, b);
    LispObject p = Binary(Quotient, bignum_value(a), g);
    LispObject q = Binary(Quotient, bignum_value(b), g);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational CL/ bignum
LispObject CLQuotient::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(),
                                    Binary(CLQuotient, bignum_value(b), g)),
                      Binary(CLQuotient, a.denominator(), g));
}

// complex CL/ bignum
LispObject CLQuotient::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(CLQuotient, a.real_part(), bignum_value(b)),
                        Binary(CLQuotient, a.imag_part(), bignum_value(b)));
}

// short float CL/ bignum
LispObject CLQuotient::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float CL/ bignum
LispObject CLQuotient::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float CL/ bignum
LispObject CLQuotient::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float CL/ bignum
LispObject CLQuotient::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum CL/ rational
LispObject CLQuotient::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(CLQuotient, a, g),
                                 b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum CL/ rational
LispObject CLQuotient::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(CLQuotient, bignum_value(a), g),
                                 b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational CL/ rational
LispObject CLQuotient::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(CLQuotient,a.numerator(), g1);
    LispObject nb = Binary(CLQuotient,b.denominator(), g2);
    LispObject da = Binary(CLQuotient,a.denominator(), g2);
    LispObject db = Binary(CLQuotient,b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex CL/ rational
LispObject CLQuotient::op(Cpx a, Rat b)
{   return make_complex(Binary(CLQuotient, a.real_part(), b.value()),
                        Binary(CLQuotient, a.imag_part(), b.value()));
}

// short float CL/ rational
LispObject CLQuotient::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float CL/ rational
LispObject CLQuotient::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float CL/ rational
LispObject CLQuotient::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float CL/ rational
LispObject CLQuotient::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum CL/ complex
LispObject CLQuotient::op(Fixnum a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a, conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// bignum CL/ complex
LispObject CLQuotient::op(std::uint64_t* a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, bignum_value(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// rational CL/ complex
LispObject CLQuotient::op(Rat a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// complex CL/ complex
LispObject CLQuotient::op(Cpx a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// short float CL/ complex
LispObject CLQuotient::op(SFlt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// single float CL/ complex
LispObject CLQuotient::op(Flt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// double float CL/ complex
LispObject CLQuotient::op(double a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a, conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// long float CL/ complex
LispObject CLQuotient::op(FLOAT_128 a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, make_boxfloat128(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(CLQuotient, num, den);
}

// fixnum CL/ short float
LispObject CLQuotient::op(Fixnum a, SFlt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) /
                             b.floatval());
}

// bignum CL/ short float
LispObject CLQuotient::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational CL/ short float
LispObject CLQuotient::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex CL/ short float
LispObject CLQuotient::op(Cpx a, SFlt b)
{   return make_complex(Binary(CLQuotient,a.real_part(), b.value()),
                        Binary(CLQuotient,a.imag_part(), b.value()));
}

// short float CL/ short float
LispObject CLQuotient::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float CL/ short float
LispObject CLQuotient::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float CL/ short float
LispObject CLQuotient::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float CL/ short float
LispObject CLQuotient::op(FLOAT_128 a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum CL/ single float
LispObject CLQuotient::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum CL/ single float
LispObject CLQuotient::op(std::uint64_t* a, Flt b)
{   arithlib_abort("not done yet");
}

// rational CL/ single float
LispObject CLQuotient::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex CL/ single float
LispObject CLQuotient::op(Cpx a, Flt b)
{   return make_complex(
        Binary(CLQuotient,a.real_part(), b.value()),
        Binary(CLQuotient,a.imag_part(), b.value()));
}

// short float CL/ single float
LispObject CLQuotient::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float CL/ single float
LispObject CLQuotient::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float CL/ single float
LispObject CLQuotient::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float CL/ single float
LispObject CLQuotient::op(FLOAT_128 a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum CL/ double float
LispObject CLQuotient::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum CL/ double float
LispObject CLQuotient::op(std::uint64_t* a, double b)
{   arithlib_abort("not done yet");
}

// rational CL/ double float
LispObject CLQuotient::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex CL/ double float
LispObject CLQuotient::op(Cpx a, double b)
{   return make_complex(
        Binary(CLQuotient, a.real_part(), make_boxfloat(b)),
        Binary(CLQuotient, a.imag_part(), make_boxfloat(b)));
}

// short float CL/ double float
LispObject CLQuotient::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float CL/ double float
LispObject CLQuotient::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float CL/ double float
LispObject CLQuotient::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float CL/ double float
LispObject CLQuotient::op(FLOAT_128 a, double b)
{   arithlib_abort("not done yet");
}

// fixnum CL/ long float
LispObject CLQuotient::op(Fixnum a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// bignum CL/ long float
LispObject CLQuotient::op(std::uint64_t* a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// rational CL/ long float
LispObject CLQuotient::op(Rat a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// complex CL/ long float
LispObject CLQuotient::op(Cpx a, FLOAT_128 b)
{   return make_complex(
        Binary(CLQuotient,a.real_part(), b),
        Binary(CLQuotient,a.imag_part(), b));
}

// short float CL/ long float
LispObject CLQuotient::op(SFlt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// single float CL/ long float
LispObject CLQuotient::op(Flt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// double float CL/ long float
LispObject CLQuotient::op(double a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// long float CL/ long float
LispObject CLQuotient::op(FLOAT_128 a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// fixnum remainder fixnum
LispObject Remainder::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Remainder::op(int_of_fixnum(a), int_of_fixnum(b));
}

// bignum remainder fixnum
LispObject Remainder::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Remainder::op(a, int_of_fixnum(b));
}

// rational remainder fixnum
LispObject Remainder::op(Rat a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b));
}

// complex % fixnum
LispObject Remainder::op(Cpx a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b));
}

// short float % fixnum
LispObject Remainder::op(SFlt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b));
}

// single float % fixnum
LispObject Remainder::op(Flt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(),
                              Binary(Times, q, b));
}

// double float % fixnum
LispObject Remainder::op(double a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a), Binary(Times, q, b));
}

// long float % fixnum
LispObject Remainder::op(FLOAT_128 a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat128(a), Binary(Times, q, b));
}

// fixnum % bignum
LispObject Remainder::op(Fixnum a, std::uint64_t* b)
{   if (arithlib_implementation::numberSize(b) == 1 &&
        int_of_fixnum(a) == -static_cast<int64_t>(b[0]))
        return fixnum_of_int(0);
    return a;
}

// bignum % bignum
LispObject Remainder::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Remainder::op(a, b);
}

// rational % bignum
LispObject Remainder::op(Rat a, std::uint64_t* b)
{   return fixnum_of_int(0);
}

// complex % bignum
LispObject Remainder::op(Cpx a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, bignum_value(b)));
}

// short float % bignum
LispObject Remainder::op(SFlt a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(),
                              Binary(Times, q, bignum_value(b)));
}

// single float % bignum
LispObject Remainder::op(Flt a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(),
                  Binary(Times, q, bignum_value(b)));
}

// double float % bignum
LispObject Remainder::op(double a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a),
                              Binary(Times, q, bignum_value(b)));
}

// long float % bignum
LispObject Remainder::op(FLOAT_128 a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat128(a),
                              Binary(Times, q, bignum_value(b)));
}

// fixnum % rational
LispObject Remainder::op(Fixnum a, Rat b)
{   return fixnum_of_int(0);
}

// bignum % rational
LispObject Remainder::op(std::uint64_t* a, Rat b)
{   return fixnum_of_int(0);
}

// rational % rational
LispObject Remainder::op(Rat a, Rat b)
{   return fixnum_of_int(0);
}

// complex % rational
LispObject Remainder::op(Cpx a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// short float % rational
LispObject Remainder::op(SFlt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// single float % rational
LispObject Remainder::op(Flt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// double float % rational
LispObject Remainder::op(double a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a), Binary(Times, q, b.value()));
}

// long float % rational
LispObject Remainder::op(FLOAT_128 a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat128(a), Binary(Times, q, b.value()));
}

// fixnum % complex
LispObject Remainder::op(Fixnum a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a, Binary(Times, q, b.value()));
}

// bignum % complex
LispObject Remainder::op(std::uint64_t* a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, bignum_value(a), Binary(Times, q, b.value()));
}

// rational % complex
LispObject Remainder::op(Rat a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// complex % complex
LispObject Remainder::op(Cpx a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// short float % complex
LispObject Remainder::op(SFlt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// single float % complex
LispObject Remainder::op(Flt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// double float % complex
LispObject Remainder::op(double a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a), Binary(Times, q, b.value()));
}

// long float % complex
LispObject Remainder::op(FLOAT_128 a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat128(a), Binary(Times, q, b.value()));
}

// fixnum % short float
LispObject Remainder::op(Fixnum a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a, Binary(Times, q, b.value()));
}

// bignum % short float
LispObject Remainder::op(std::uint64_t* a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, bignum_value(a), Binary(Times, q, b.value()));
}

// rational % short float
LispObject Remainder::op(Rat a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// complex % short float
LispObject Remainder::op(Cpx a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(),
                              Binary(Times, q, b.value()));
}

// short float % short float
LispObject Remainder::op(SFlt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// single float % short float
LispObject Remainder::op(Flt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// double float % short float
LispObject Remainder::op(double a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a), Binary(Times, q, b.value()));
}

// long float % short float
LispObject Remainder::op(FLOAT_128 a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat128(a), Binary(Times, q, b.value()));
}

// fixnum % single float
LispObject Remainder::op(Fixnum a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a, Binary(Times, q, b.value()));
}

// bignum % single float
LispObject Remainder::op(std::uint64_t* a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, bignum_value(a), Binary(Times, q, b.value()));
}

// rational % single float
LispObject Remainder::op(Rat a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// complex % single float
LispObject Remainder::op(Cpx a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// short float % single float
LispObject Remainder::op(SFlt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// single float % single float
LispObject Remainder::op(Flt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, b.value()));
}

// double float % single float
LispObject Remainder::op(double a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a), Binary(Times, q, b.value()));
}

// long float % single float
LispObject Remainder::op(FLOAT_128 a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat128(a), Binary(Times, q, b.value()));
}

// fixnum % double float
LispObject Remainder::op(Fixnum a, double b)
{   LispObject q = Quotient::op(a, b);
    return Binary(Difference, a, Binary(Times, q, make_boxfloat(b)));
}

// bignum % double float
LispObject Remainder::op(std::uint64_t* a, double b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, bignum_value(a), Binary(Times, q, make_boxfloat(b)));
}

// rational % double float
LispObject Remainder::op(Rat a, double b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat(b)));
}

// complex % double float
LispObject Remainder::op(Cpx a, double b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat(b)));
}

// short float % double float
LispObject Remainder::op(SFlt a, double b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat(b)));
}

// single float % double float
LispObject Remainder::op(Flt a, double b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat(b)));
}

// double float % double float
LispObject Remainder::op(double a, double b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a), Binary(Times, q, make_boxfloat(b)));
}

// long float % double float
LispObject Remainder::op(FLOAT_128 a, double b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a, Binary(Times, q, b));
}

// fixnum % long float
LispObject Remainder::op(Fixnum a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a, Binary(Times, q, make_boxfloat128(b)));
}

// bignum % long float
LispObject Remainder::op(std::uint64_t* a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, bignum_value(a), Binary(Times, q, make_boxfloat128(b)));
}

// rational % long float
LispObject Remainder::op(Rat a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat128(b)));
}

// complex % long float
LispObject Remainder::op(Cpx a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat128(b)));
}

// short float % long float
LispObject Remainder::op(SFlt a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat128(b)));
}

// single float % long float
LispObject Remainder::op(Flt a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, a.value(), Binary(Times, q, make_boxfloat128(b)));
}

// double float % long float
LispObject Remainder::op(double a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat(a), Binary(Times, q, make_boxfloat128(b)));
}

// long float % long float
LispObject Remainder::op(FLOAT_128 a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    return Binary(Difference, make_boxfloat128(a), Binary(Times, q, make_boxfloat128(b)));
}

// fixnum mod fixnum
LispObject Mod::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Mod::op(int_of_fixnum(a), int_of_fixnum(b));
}

// bignum mod fixnum
LispObject Mod::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Mod::op(a, int_of_fixnum(b));
}

// fixnum % bignum
LispObject Mod::op(Fixnum a, std::uint64_t* b)
{
// One misery here is that one can have -2^k as a fixnum but 2^k having
// to be a bignum, and in that case the result must be zero.
    int64_t aa = int_of_fixnum(a);
    if (aa == 0 ||
        (aa == -0x0800000000000000LL &&
         b[0] == 0x0800000000000000LLU)) return fixnum_of_int(0);
    size_t len = arithlib_implementation::numberSize(b);
    bool a_neg = aa<0;
    bool b_neg = static_cast<int64_t>(b[len-1])<0;
    if (a_neg == b_neg) return a;
    else return Binary(Plus, a, bignum_value(b));
}

// bignum % bignum
LispObject Mod::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Mod::op(a, b);
}

// fixnum divide fixnum
LispObject Divide::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Divide::op(int_of_fixnum(a), int_of_fixnum(b));
}

// bignum divide fixnum
LispObject Divide::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Divide::op(a, int_of_fixnum(b));
}

// rational divide fixnum
LispObject Divide::op(Rat a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b, q));
    return cons(q, r);
}

// complex divide fixnum
LispObject Divide::op(Cpx a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, q, b));
    return cons(q, r);
}

// short float divide fixnum
LispObject Divide::op(SFlt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b, q));
    return cons(q, r);
}

// single float divide fixnum
LispObject Divide::op(Flt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b, q));
    return cons(q, r);
}

// double float divide fixnum
LispObject Divide::op(double a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a), Binary(Times, b, q));
    return cons(q, r);
}

// long float divide fixnum
LispObject Divide::op(FLOAT_128 a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a),
                                      Binary(Times, b, q));
    return cons(q, r);
}

// fixnum divide bignum
LispObject Divide::op(Fixnum a, std::uint64_t* b)
{   if (arithlib_implementation::numberSize(b) == 1 &&
        a == -static_cast<int64_t>(b[0]))
        return cons(fixnum_of_int(-1), fixnum_of_int(0));
    return arithlib_lowlevel::Divide::op(int_of_fixnum(a), b);
}

// bignum divide bignum
LispObject Divide::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Divide::op(a, b);
}

// rational divide bignum
LispObject Divide::op(Rat a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, bignum_value(b), q));
    return cons(q, r);
}

// complex divide bignum
LispObject Divide::op(Cpx a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, bignum_value(b), q));
    return cons(q, r);
}

// short float divide bignum
LispObject Divide::op(SFlt a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, bignum_value(b), q));
    return cons(q, r);
}

// single float divide bignum
LispObject Divide::op(Flt a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, bignum_value(b), q));
    return cons(q, r);
}

// double float divide bignum
LispObject Divide::op(double a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a), Binary(Times, bignum_value(b), q));
    return cons(q, r);
}

// long float divide bignum
LispObject Divide::op(FLOAT_128 a, std::uint64_t* b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a), Binary(Times, bignum_value(b), q));
    return cons(q, r);
}

// fixnum divide rational
LispObject Divide::op(Fixnum a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a,
                                      Binary(Times, b.value(), q));
    return cons(q, r);
}

// bignum divide rational
LispObject Divide::op(std::uint64_t* a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, bignum_value(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// rational divide rational
LispObject Divide::op(Rat a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// complex divide rational
LispObject Divide::op(Cpx a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// short float divide rational
LispObject Divide::op(SFlt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// single float divide rational
LispObject Divide::op(Flt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// double float divide rational
LispObject Divide::op(double a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// long float divide rational
LispObject Divide::op(FLOAT_128 a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// fixnum divide complex
LispObject Divide::op(Fixnum a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a, Binary(Times, b.value(), q));
    return cons(q, r);
}

// bignum divide complex
LispObject Divide::op(std::uint64_t* a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, bignum_value(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// rational divide complex
LispObject Divide::op(Rat a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// complex divide complex
LispObject Divide::op(Cpx a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// short float divide complex
LispObject Divide::op(SFlt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// single float divide complex
LispObject Divide::op(Flt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// double float divide complex
LispObject Divide::op(double a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// long float divide complex
LispObject Divide::op(FLOAT_128 a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// fixnum divide short float
LispObject Divide::op(Fixnum a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a, Binary(Times, b.value(), q));
    return cons(q, r);
}

// bignum divide short float
LispObject Divide::op(std::uint64_t* a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, bignum_value(a),
                                      Binary(Times, b.value(), q));
    return cons(q, r);
}

// rational divide short float
LispObject Divide::op(Rat a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// complex divide short float
LispObject Divide::op(Cpx a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// short float divide short float
LispObject Divide::op(SFlt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// single float divide short float
LispObject Divide::op(Flt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// double float divide short float
LispObject Divide::op(double a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a),
                                      Binary(Times, b.value(), q));
    return cons(q, r);
}

// long float divide short float
LispObject Divide::op(FLOAT_128 a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// fixnum divide single float
LispObject Divide::op(Fixnum a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a, Binary(Times, b.value(), q));
    return cons(q, r);
}

// bignum divide single float
LispObject Divide::op(std::uint64_t* a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, bignum_value(a),
                                      Binary(Times, b.value(), q));
    return cons(q, r);
}

// rational divide single float
LispObject Divide::op(Rat a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// complex divide single float
LispObject Divide::op(Cpx a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// short float divide single float
LispObject Divide::op(SFlt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// single float divide single float
LispObject Divide::op(Flt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, b.value(), q));
    return cons(q, r);
}

// double float divide single float
LispObject Divide::op(double a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// long float divide single float
LispObject Divide::op(FLOAT_128 a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a), Binary(Times, b.value(), q));
    return cons(q, r);
}

// fixnum divide double float
LispObject Divide::op(Fixnum a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Binary(Difference, a, Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// bignum divide double float
LispObject Divide::op(std::uint64_t* a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, bignum_value(a), Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// rational divide double float
LispObject Divide::op(Rat a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// complex divide double float
LispObject Divide::op(Cpx a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// short float divide double float
LispObject Divide::op(SFlt a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// single float divide double float
LispObject Divide::op(Flt a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// double float divide double float
LispObject Divide::op(double a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a), Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// long float divide double float
LispObject Divide::op(FLOAT_128 a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a), Binary(Times, make_boxfloat(b), q));
    return cons(q, r);
}

// fixnum divide long float
LispObject Divide::op(Fixnum a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a, Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

// bignum divide long float
LispObject Divide::op(std::uint64_t* a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, bignum_value(a), Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

// rational divide long float
LispObject Divide::op(Rat a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

// complex divide long float
LispObject Divide::op(Cpx a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

// short float divide long float
LispObject Divide::op(SFlt a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

// single float divide long float
LispObject Divide::op(Flt a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, a.value(), Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

// double float divide long float
LispObject Divide::op(double a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat(a), Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

// long float divide long float
LispObject Divide::op(FLOAT_128 a, FLOAT_128 b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Binary(Difference, make_boxfloat128(a), Binary(Times, make_boxfloat128(b), q));
    return cons(q, r);
}

LispObject Square::op(Fixnum a)
{   return arithlib_lowlevel::Square::op(int_of_fixnum(a));
}

LispObject Square::op( std::uint64_t* a)
{   return arithlib_lowlevel::Square::op( a);
}

LispObject Square::op( Rat a)
{   LispObject p = a.numerator(), q = a.denominator();
    return make_ratio(Unary(Square, p), Unary(Square, q));
}

LispObject Square::op( Cpx a)
{   // (x + iy)^2 = x^2 - y^2 + 2*i*x*y
    LispObject x = a.real_part(), y = a.imag_part();
    LispObject vx = Binary(Difference, Unary(Square, x), Unary(Square, y));
    LispObject vy = Binary(Times, fixnum_of_int(2), Binary(Times, x, y));
    return make_complex(vx, vy);
}

LispObject Square::op( SFlt a)
{   return pack_short_float(a.floatval()*a.floatval());
}

LispObject Square::op( Flt a)
{   return pack_single_float(a.floatval()*a.floatval());
}

LispObject Square::op( double a)
{   return make_boxfloat(a*a);
}

LispObject Square::op( FLOAT_128 a)
{   return make_boxfloat128(a * a);
}

LispObject Reciprocal::op(Fixnum a)
{   switch (int_of_fixnum(a))
    {   case 0:  return aerror1("bad argument for reciprocal", a);
        case 1:  return fixnum_of_int(1);
        case -1: return fixnum_of_int(-1);
        default: return fixnum_of_int(0);
    }
}

LispObject Reciprocal::op(std::uint64_t* a)
{   return int_of_fixnum(0);
}

LispObject Reciprocal::op(Rat a)
{   LispObject p = a.numerator(), q = a.denominator();
    if (Zerop::op(a)) return aerror1("bad argument for reciprocal", a.value());
    else if (BoolUnary(Minusp, p))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(q, p);
}

LispObject Reciprocal::op(Cpx a)
{   // 1/(x + iy) = (x - iy)/(x^2+y^2)
    LispObject x = a.real_part(), y = a.imag_part();
    LispObject d = Binary(Plus, Unary(Square, x), Unary(Square, y));
    if (BoolUnary(Zerop, d)) return aerror1("bad argument for reciprocal", a.value());
// If the complex value has both components integers I will upgrade
// them to floating point.
    bool promote = false;
    switch (d & XTAG_BITS)
    {   case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            switch (type_of_header(numhdr(d)))
            {   case TYPE_NEW_BIGNUM:
                    promote = true;
                    break;
                default:
                    break;
            }
            break;
        case TAG_FIXNUM:
            promote = true;
            break;
        default:
            break;
    }
    if (promote)
    {   x = Unary(Float, x);
        y = Unary(Float, y);
        d = Unary(Float, d);
    }
    return make_complex(Binary(Quotient,x, d), Binary(Quotient,y, d));
}

LispObject Reciprocal::op(SFlt a)
{   return pack_short_float(1.0 / a.floatval());
}

LispObject Reciprocal::op(Flt a)
{   return pack_single_float(1.0 / a.floatval());
}

LispObject Reciprocal::op(double a)
{   return make_boxfloat(1.0 / a);
}

LispObject Reciprocal::op(FLOAT_128 a)
{   return make_boxfloat128(LF_C(1.0) / a);
}

// There are now definitions for Truncate, Floor and Ceiling which
// perform division with directed rounding. In general I have not
// implemented these so even when they divide they will often not
// round properly. I will need to come back and work over them later.

// fixnum truncate fixnum
LispObject Truncate::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(int_of_fixnum(a), int_of_fixnum(b));
}

// bignum truncate fixnum
LispObject Truncate::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, int_of_fixnum(b));
}

// rational truncate fixnum
LispObject Truncate::op(Rat a, Fixnum b)
{   if (b == int_of_fixnum(0)) return a.value();
    return make_ratio(Binary(Truncate, a.numerator(),
                             Binary(Truncate, a.denominator(), b)),
                      a.denominator());
}

// complex truncate fixnum
LispObject Truncate::op(Cpx a, Fixnum b)
{   if (b == fixnum_of_int(0)) return a.v;
    return make_complex(Binary(Truncate, a.real_part(), b), a.imag_part());
}

// short float truncate fixnum
LispObject Truncate::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() /
                            static_cast<double>(int_of_fixnum(b)));
}

// single float truncate fixnum
LispObject Truncate::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() /
                             static_cast<double>(int_of_fixnum(b)));
}

// double float truncate fixnum
LispObject Truncate::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float truncate fixnum
LispObject Truncate::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum truncate bignum
LispObject Truncate::op(Fixnum a, std::uint64_t* b)
{   if (arithlib_implementation::numberSize(b) == 1 &&
        int_of_fixnum(a) == -static_cast<int64_t>(b[0]))
        return fixnum_of_int(-1);
    return fixnum_of_int(0);
}

// bignum truncate bignum
LispObject Truncate::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational truncate bignum
LispObject Truncate::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(), Binary(Truncate, bignum_value(b), g)),
                      Binary(Truncate, a.denominator(), g));
}

// complex truncate bignum
LispObject Truncate::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Truncate, a.real_part(), bignum_value(b)),
                        Binary(Truncate, a.imag_part(), bignum_value(b)));
}

// short float truncate bignum
LispObject Truncate::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float truncate bignum
LispObject Truncate::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float truncate bignum
LispObject Truncate::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float truncate bignum
LispObject Truncate::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum truncate rational
LispObject Truncate::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(Truncate, a, g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum truncate rational
LispObject Truncate::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(Truncate, bignum_value(a), g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational truncate rational
LispObject Truncate::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(Truncate, a.numerator(), g1);
    LispObject nb = Binary(Truncate, b.denominator(), g2);
    LispObject da = Binary(Truncate, a.denominator(), g2);
    LispObject db = Binary(Truncate, b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex truncate rational
LispObject Truncate::op(Cpx a, Rat b)
{   return make_complex(Binary(Truncate, a.real_part(), b.value()),
                        Binary(Truncate, a.imag_part(), b.value()));
}

// short float truncate rational
LispObject Truncate::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float truncate rational
LispObject Truncate::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float truncate rational
LispObject Truncate::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float truncate rational
LispObject Truncate::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum truncate complex
LispObject Truncate::op(Fixnum a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a, conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// bignum truncate complex
LispObject Truncate::op(std::uint64_t* a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, bignum_value(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// rational truncate complex
LispObject Truncate::op(Rat a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// complex truncate complex
LispObject Truncate::op(Cpx a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// short float truncate complex
LispObject Truncate::op(SFlt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// single float truncate complex
LispObject Truncate::op(Flt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// double float truncate complex
LispObject Truncate::op(double a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a, conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// long float truncate complex
LispObject Truncate::op(FLOAT_128 a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, make_boxfloat128(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Truncate, num, den);
}

// fixnum truncate short float
LispObject Truncate::op(Fixnum a, SFlt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) / b.floatval());
}

// bignum truncate short float
LispObject Truncate::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational truncate short float
LispObject Truncate::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex truncate short float
LispObject Truncate::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float truncate short float
LispObject Truncate::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float truncate short float
LispObject Truncate::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float truncate short float
LispObject Truncate::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float truncate short float
LispObject Truncate::op(FLOAT_128 a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum truncate single float
LispObject Truncate::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum truncate single float
LispObject Truncate::op(std::uint64_t* a, Flt b)
{   arithlib_abort("not done yet");
}

// rational truncate single float
LispObject Truncate::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex truncate single float
LispObject Truncate::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float truncate single float
LispObject Truncate::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float truncate single float
LispObject Truncate::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float truncate single float
LispObject Truncate::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float truncate single float
LispObject Truncate::op(FLOAT_128 a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum truncate double float
LispObject Truncate::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum truncate double float
LispObject Truncate::op(std::uint64_t* a, double b)
{   arithlib_abort("not done yet");
}

// rational truncate double float
LispObject Truncate::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex truncate double float
LispObject Truncate::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float truncate double float
LispObject Truncate::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float truncate double float
LispObject Truncate::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float truncate double float
LispObject Truncate::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float truncate double float
LispObject Truncate::op(FLOAT_128 a, double b)
{   arithlib_abort("not done yet");
}

// fixnum truncate long float
LispObject Truncate::op(Fixnum a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// bignum truncate long float
LispObject Truncate::op(std::uint64_t* a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// rational truncate long float
LispObject Truncate::op(Rat a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// complex truncate long float
LispObject Truncate::op(Cpx a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// short float truncate long float
LispObject Truncate::op(SFlt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// single float truncate long float
LispObject Truncate::op(Flt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// double float truncate long float
LispObject Truncate::op(double a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// long float truncate long float
LispObject Truncate::op(FLOAT_128 a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// fixnum ceiling fixnum
LispObject Ceiling::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// bignum ceiling fixnum
LispObject Ceiling::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational ceiling fixnum
LispObject Ceiling::op(Rat a, Fixnum b)
{   if (b == 0) return a.value();
    return make_ratio(Binary(Ceiling, a.numerator(),
                                  Binary(Ceiling, a.denominator(), b)),
                      a.denominator());
}

// complex ceiling fixnum
LispObject Ceiling::op(Cpx a, Fixnum b)
{   if (b == 0) return a.v;
    return make_complex(Binary(Ceiling, a.real_part(), b), a.imag_part());
}

// short float ceiling fixnum
LispObject Ceiling::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// single float ceiling fixnum
LispObject Ceiling::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// double float ceiling fixnum
LispObject Ceiling::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float ceiling fixnum
LispObject Ceiling::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum ceiling bignum
LispObject Ceiling::op(Fixnum a, std::uint64_t* b)
{   if (arithlib_implementation::numberSize(b) == 1 &&
        int_of_fixnum(a) == -static_cast<int64_t>(b[0]))
        return fixnum_of_int(-1);
    return fixnum_of_int(0);
}

// bignum ceiling bignum
LispObject Ceiling::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational ceiling bignum
LispObject Ceiling::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(), Binary(Ceiling, bignum_value(b), g)),
                      Binary(Ceiling, a.denominator(), g));
}

// complex ceiling bignum
LispObject Ceiling::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Ceiling, a.real_part(), bignum_value(b)),
                        Binary(Ceiling, a.imag_part(), bignum_value(b)));
}

// short float ceiling bignum
LispObject Ceiling::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float ceiling bignum
LispObject Ceiling::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float ceiling bignum
LispObject Ceiling::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float ceiling bignum
LispObject Ceiling::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum ceiling rational
LispObject Ceiling::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(Ceiling, a, g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum ceiling rational
LispObject Ceiling::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(Ceiling, bignum_value(a), g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational ceiling rational
LispObject Ceiling::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(Ceiling, a.numerator(), g1);
    LispObject nb = Binary(Ceiling, b.denominator(), g2);
    LispObject da = Binary(Ceiling, a.denominator(), g2);
    LispObject db = Binary(Ceiling, b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex ceiling rational
LispObject Ceiling::op(Cpx a, Rat b)
{   return make_complex(Binary(Ceiling, a.real_part(), b.value()),
                        Binary(Ceiling, a.imag_part(), b.value()));
}

// short float ceiling rational
LispObject Ceiling::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float ceiling rational
LispObject Ceiling::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float ceiling rational
LispObject Ceiling::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float ceiling rational
LispObject Ceiling::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum ceiling complex
LispObject Ceiling::op(Fixnum a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a, conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// bignum ceiling complex
LispObject Ceiling::op(std::uint64_t* a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, bignum_value(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// rational ceiling complex
LispObject Ceiling::op(Rat a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// complex ceiling complex
LispObject Ceiling::op(Cpx a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// short float ceiling complex
LispObject Ceiling::op(SFlt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// single float ceiling complex
LispObject Ceiling::op(Flt a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a.value(), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// double float ceiling complex
LispObject Ceiling::op(double a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, a, conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// long float ceiling complex
LispObject Ceiling::op(FLOAT_128 a, Cpx b)
{   LispObject conj = make_complex(b.real_part(), Unary(Minus, b.imag_part()));
    LispObject num = Binary(Times, make_boxfloat128(a), conj);
    LispObject den =
        Binary(Plus, Unary(Square, b.real_part()), Unary(Square, b.imag_part()));
    return Binary(Ceiling, num, den);
}

// fixnum ceiling short float
LispObject Ceiling::op(Fixnum a, SFlt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) / b.floatval());
}

// bignum ceiling short float
LispObject Ceiling::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational ceiling short float
LispObject Ceiling::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex ceiling short float
LispObject Ceiling::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float ceiling short float
LispObject Ceiling::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float ceiling short float
LispObject Ceiling::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float ceiling short float
LispObject Ceiling::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float ceiling short float
LispObject Ceiling::op(FLOAT_128 a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum ceiling single float
LispObject Ceiling::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum ceiling single float
LispObject Ceiling::op(std::uint64_t* a, Flt b)
{   arithlib_abort("not done yet");
}

// rational ceiling single float
LispObject Ceiling::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex ceiling single float
LispObject Ceiling::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float ceiling single float
LispObject Ceiling::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float ceiling single float
LispObject Ceiling::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float ceiling single float
LispObject Ceiling::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float ceiling single float
LispObject Ceiling::op(FLOAT_128 a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum ceiling double float
LispObject Ceiling::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum ceiling double float
LispObject Ceiling::op(std::uint64_t* a, double b)
{   arithlib_abort("not done yet");
}

// rational ceiling double float
LispObject Ceiling::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex ceiling double float
LispObject Ceiling::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float ceiling double float
LispObject Ceiling::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float ceiling double float
LispObject Ceiling::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float ceiling double float
LispObject Ceiling::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float ceiling double float
LispObject Ceiling::op(FLOAT_128 a, double b)
{   arithlib_abort("not done yet");
}

// fixnum ceiling long float
LispObject Ceiling::op(Fixnum a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// bignum ceiling long float
LispObject Ceiling::op(std::uint64_t* a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// rational ceiling long float
LispObject Ceiling::op(Rat a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// complex ceiling long float
LispObject Ceiling::op(Cpx a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// short float ceiling long float
LispObject Ceiling::op(SFlt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// single float ceiling long float
LispObject Ceiling::op(Flt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// double float ceiling long float
LispObject Ceiling::op(double a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// long float ceiling long float
LispObject Ceiling::op(FLOAT_128 a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// fixnum floor fixnum
LispObject Floor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// bignum floor fixnum
LispObject Floor::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational floor fixnum
LispObject Floor::op(Rat a, Fixnum b)
{   if (b == 0) return a.value();
    return make_ratio(Binary(Floor, a.numerator(),
                                    Binary(Floor, a.denominator(), b)),
                      a.denominator());
}

// complex floor fixnum
LispObject Floor::op(Cpx a, Fixnum b)
{   if (b == fixnum_of_int(0)) return a.v;
    return make_complex(Binary(Floor, a.real_part(), b), a.imag_part());
}

// short float floor fixnum
LispObject Floor::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// single float floor fixnum
LispObject Floor::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// double float floor fixnum
LispObject Floor::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float floor fixnum
LispObject Floor::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum floor bignum
LispObject Floor::op(Fixnum a, std::uint64_t* b)
{   if (arithlib_implementation::numberSize(b) == 1 &&
        int_of_fixnum(a) == -static_cast<int64_t>(b[0]))
        return fixnum_of_int(-1);
    return fixnum_of_int(0);
}

// bignum floor bignum
LispObject Floor::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational floor bignum
LispObject Floor::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(), Binary(Floor, bignum_value(b), g)),
                      Binary(Floor, a.denominator(), g));
}

// complex floor bignum
LispObject Floor::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Floor, a.real_part(), bignum_value(b)),
                        Binary(Floor, a.imag_part(), bignum_value(b)));
}

// short float floor bignum
LispObject Floor::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float floor bignum
LispObject Floor::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float floor bignum
LispObject Floor::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float floor bignum
LispObject Floor::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum floor rational
LispObject Floor::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(Floor, a, g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum floor rational
LispObject Floor::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(Floor, bignum_value(a), g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational floor rational
LispObject Floor::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(Floor, a.numerator(), g1);
    LispObject nb = Binary(Floor, b.denominator(), g2);
    LispObject da = Binary(Floor, a.denominator(), g2);
    LispObject db = Binary(Floor, b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex floor rational
LispObject Floor::op(Cpx a, Rat b)
{   return make_complex(Binary(Floor, a.real_part(), b.value()),
                        Binary(Floor, a.imag_part(), b.value()));
}

// short float floor rational
LispObject Floor::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float floor rational
LispObject Floor::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float floor rational
LispObject Floor::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float floor rational
LispObject Floor::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum floor complex
LispObject Floor::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
}

// bignum floor complex
LispObject Floor::op(std::uint64_t* a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational floor complex
LispObject Floor::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex floor complex
LispObject Floor::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float floor complex
LispObject Floor::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float floor complex
LispObject Floor::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float floor complex
LispObject Floor::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float floor complex
LispObject Floor::op(FLOAT_128 a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum floor short float
LispObject Floor::op(Fixnum a, SFlt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) / b.floatval());
}

// bignum floor short float
LispObject Floor::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational floor short float
LispObject Floor::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex floor short float
LispObject Floor::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float floor short float
LispObject Floor::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float floor short float
LispObject Floor::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float floor short float
LispObject Floor::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float floor short float
LispObject Floor::op(FLOAT_128 a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum floor single float
LispObject Floor::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum floor single float
LispObject Floor::op(std::uint64_t* a, Flt b)
{   arithlib_abort("not done yet");
}

// rational floor single float
LispObject Floor::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex floor single float
LispObject Floor::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float floor single float
LispObject Floor::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float floor single float
LispObject Floor::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float floor single float
LispObject Floor::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float floor single float
LispObject Floor::op(FLOAT_128 a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum floor double float
LispObject Floor::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum floor double float
LispObject Floor::op(std::uint64_t* a, double b)
{   arithlib_abort("not done yet");
}

// rational floor double float
LispObject Floor::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex floor double float
LispObject Floor::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float floor double float
LispObject Floor::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float floor double float
LispObject Floor::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float floor double float
LispObject Floor::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float floor double float
LispObject Floor::op(FLOAT_128 a, double b)
{   arithlib_abort("not done yet");
}

// fixnum floor long float
LispObject Floor::op(Fixnum a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// bignum floor long float
LispObject Floor::op(std::uint64_t* a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// rational floor long float
LispObject Floor::op(Rat a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// complex floor long float
LispObject Floor::op(Cpx a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// short float floor long float
LispObject Floor::op(SFlt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// single float floor long float
LispObject Floor::op(Flt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// double float floor long float
LispObject Floor::op(double a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// long float floor long float
LispObject Floor::op(FLOAT_128 a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// fixnum ftruncate fixnum
LispObject Ftruncate::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// bignum ftruncate fixnum
LispObject Ftruncate::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational ftruncate fixnum
LispObject Ftruncate::op(Rat a, Fixnum b)
{   if (b == 0) return a.value();
    return make_ratio(Binary(Quotient,a.numerator(),
                                      Binary(Ftruncate, a.denominator(), b)),
                      a.denominator());
}

// complex ftruncate fixnum
LispObject Ftruncate::op(Cpx a, Fixnum b)
{   if (b == 0) return a.v;
    return make_complex(Binary(Ftruncate, a.real_part(), b),
                        a.imag_part());
}

// short float ftruncate fixnum
LispObject Ftruncate::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// single float ftruncate fixnum
LispObject Ftruncate::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// double float ftruncate fixnum
LispObject Ftruncate::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float ftruncate fixnum
LispObject Ftruncate::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum ftruncate bignum
LispObject Ftruncate::op(Fixnum a, std::uint64_t* b)
{   return fixnum_of_int(0);
}

// bignum ftruncate bignum
LispObject Ftruncate::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational ftruncate bignum
LispObject Ftruncate::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(), Binary(Ftruncate, bignum_value(b), g)),
                      Binary(Ftruncate, a.denominator(), g));
}

// complex ftruncate bignum
LispObject Ftruncate::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Ftruncate, a.real_part(), bignum_value(b)),
                        Binary(Ftruncate, a.imag_part(), bignum_value(b)));
}

// short float ftruncate bignum
LispObject Ftruncate::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float ftruncate bignum
LispObject Ftruncate::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float ftruncate bignum
LispObject Ftruncate::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float ftruncate bignum
LispObject Ftruncate::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum ftruncate rational
LispObject Ftruncate::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(Ftruncate, a, g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum ftruncate rational
LispObject Ftruncate::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(Ftruncate, bignum_value(a), g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational ftruncate rational
LispObject Ftruncate::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(Ftruncate, a.numerator(), g1);
    LispObject nb = Binary(Ftruncate, b.denominator(), g2);
    LispObject da = Binary(Ftruncate, a.denominator(), g2);
    LispObject db = Binary(Ftruncate, b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex ftruncate rational
LispObject Ftruncate::op(Cpx a, Rat b)
{   return make_complex(Binary(Ftruncate, a.real_part(), b.value()),
                        Binary(Ftruncate, a.imag_part(), b.value()));
}

// short float ftruncate rational
LispObject Ftruncate::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float ftruncate rational
LispObject Ftruncate::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float ftruncate rational
LispObject Ftruncate::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float ftruncate rational
LispObject Ftruncate::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum ftruncate complex
LispObject Ftruncate::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
}

// bignum ftruncate complex
LispObject Ftruncate::op(std::uint64_t* a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational ftruncate complex
LispObject Ftruncate::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex ftruncate complex
LispObject Ftruncate::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float ftruncate complex
LispObject Ftruncate::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float ftruncate complex
LispObject Ftruncate::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float ftruncate complex
LispObject Ftruncate::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float ftruncate complex
LispObject Ftruncate::op(FLOAT_128 a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum ftruncate short float
LispObject Ftruncate::op(Fixnum a, SFlt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) / b.floatval());
}

// bignum ftruncate short float
LispObject Ftruncate::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational ftruncate short float
LispObject Ftruncate::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex ftruncate short float
LispObject Ftruncate::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float ftruncate short float
LispObject Ftruncate::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float ftruncate short float
LispObject Ftruncate::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float ftruncate short float
LispObject Ftruncate::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float ftruncate short float
LispObject Ftruncate::op(FLOAT_128 a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum ftruncate single float
LispObject Ftruncate::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum ftruncate single float
LispObject Ftruncate::op(std::uint64_t* a, Flt b)
{   arithlib_abort("not done yet");
}

// rational ftruncate single float
LispObject Ftruncate::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex ftruncate single float
LispObject Ftruncate::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float ftruncate single float
LispObject Ftruncate::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float ftruncate single float
LispObject Ftruncate::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float ftruncate single float
LispObject Ftruncate::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float ftruncate single float
LispObject Ftruncate::op(FLOAT_128 a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum ftruncate double float
LispObject Ftruncate::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum ftruncate double float
LispObject Ftruncate::op(std::uint64_t* a, double b)
{   arithlib_abort("not done yet");
}

// rational ftruncate double float
LispObject Ftruncate::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex ftruncate double float
LispObject Ftruncate::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float ftruncate double float
LispObject Ftruncate::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float ftruncate double float
LispObject Ftruncate::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float ftruncate double float
LispObject Ftruncate::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float ftruncate double float
LispObject Ftruncate::op(FLOAT_128 a, double b)
{   arithlib_abort("not done yet");
}

// fixnum ftruncate long float
LispObject Ftruncate::op(Fixnum a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// bignum ftruncate long float
LispObject Ftruncate::op(std::uint64_t* a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// rational ftruncate long float
LispObject Ftruncate::op(Rat a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// complex ftruncate long float
LispObject Ftruncate::op(Cpx a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// short float ftruncate long float
LispObject Ftruncate::op(SFlt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// single float ftruncate long float
LispObject Ftruncate::op(Flt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// double float ftruncate long float
LispObject Ftruncate::op(double a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// long float ftruncate long float
LispObject Ftruncate::op(FLOAT_128 a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// fixnum fceiling fixnum
LispObject Fceiling::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// bignum fceiling fixnum
LispObject Fceiling::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational fceiling fixnum
LispObject Fceiling::op(Rat a, Fixnum b)
{   if (b == 0) return a.value();
    return make_ratio(Binary(Fceiling, a.numerator(),
                                   Binary(Fceiling, a.denominator(), b)),
                      a.denominator());
}

// complex fceiling fixnum
LispObject Fceiling::op(Cpx a, Fixnum b)
{   if (b == 0) return a.v;
    return make_complex(Binary(Fceiling, a.real_part(), b),
                        a.imag_part());
}

// short float fceiling fixnum
LispObject Fceiling::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// single float fceiling fixnum
LispObject Fceiling::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// double float fceiling fixnum
LispObject Fceiling::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float fceiling fixnum
LispObject Fceiling::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum fceiling bignum
LispObject Fceiling::op(Fixnum a, std::uint64_t* b)
{   return fixnum_of_int(0);
}

// bignum fceiling bignum
LispObject Fceiling::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational fceiling bignum
LispObject Fceiling::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(), Binary(Fceiling, bignum_value(b), g)),
                      Binary(Fceiling, a.denominator(), g));
}

// complex ceiling bignum
LispObject Fceiling::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Fceiling, a.real_part(), bignum_value(b)),
                        Binary(Fceiling, a.imag_part(), bignum_value(b)));
}

// short float / bignum
LispObject Fceiling::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Fceiling::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Fceiling::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Fceiling::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Fceiling::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(Fceiling, a, g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Fceiling::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(Fceiling, bignum_value(a), g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Fceiling::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(Fceiling, a.numerator(), g1);
    LispObject nb = Binary(Fceiling, b.denominator(), g2);
    LispObject da = Binary(Fceiling, a.denominator(), g2);
    LispObject db = Binary(Fceiling, b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Fceiling::op(Cpx a, Rat b)
{   return make_complex(Binary(Fceiling, a.real_part(), b.value()),
                        Binary(Fceiling, a.imag_part(), b.value()));
}

// short float / rational
LispObject Fceiling::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Fceiling::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Fceiling::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Fceiling::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Fceiling::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
}

// bignum fceiling complex
LispObject Fceiling::op(std::uint64_t* a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational fceiling complex
LispObject Fceiling::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex fceiling complex
LispObject Fceiling::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float fceiling complex
LispObject Fceiling::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float fceiling complex
LispObject Fceiling::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float fceiling complex
LispObject Fceiling::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float fceiling complex
LispObject Fceiling::op(FLOAT_128 a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum fceiling short float
LispObject Fceiling::op(Fixnum a, SFlt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) / b.floatval());
}

// bignum fceiling short float
LispObject Fceiling::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational fceiling short float
LispObject Fceiling::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex fceiling short float
LispObject Fceiling::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float fceiling short float
LispObject Fceiling::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float fceiling short float
LispObject Fceiling::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float fceiling short float
LispObject Fceiling::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float fceiling short float
LispObject Fceiling::op(FLOAT_128 a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum fceiling single float
LispObject Fceiling::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum fceiling single float
LispObject Fceiling::op(std::uint64_t* a, Flt b)
{   arithlib_abort("not done yet");
}

// rational fceiling single float
LispObject Fceiling::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex fceiling single float
LispObject Fceiling::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float fceiling single float
LispObject Fceiling::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float fceiling single float
LispObject Fceiling::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float fceiling single float
LispObject Fceiling::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float fceiling single float
LispObject Fceiling::op(FLOAT_128 a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum fceiling double float
LispObject Fceiling::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum fceiling double float
LispObject Fceiling::op(std::uint64_t* a, double b)
{   arithlib_abort("not done yet");
}

// rational fceiling double float
LispObject Fceiling::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex fceiling double float
LispObject Fceiling::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float fceiling double float
LispObject Fceiling::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float fceiling double float
LispObject Fceiling::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float fceiling double float
LispObject Fceiling::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float fceiling double float
LispObject Fceiling::op(FLOAT_128 a, double b)
{   arithlib_abort("not done yet");
}

// fixnum fceiling long float
LispObject Fceiling::op(Fixnum a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// bignum fceiling long float
LispObject Fceiling::op(std::uint64_t* a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// rational fceiling long float
LispObject Fceiling::op(Rat a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// complex fceiling long float
LispObject Fceiling::op(Cpx a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// short float fceiling long float
LispObject Fceiling::op(SFlt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// single float fceiling long float
LispObject Fceiling::op(Flt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// double float fceiling long float
LispObject Fceiling::op(double a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// long float fceiling long float
LispObject Fceiling::op(FLOAT_128 a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// fixnum ffloor fixnum
LispObject Ffloor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// bignum ffloor fixnum
LispObject Ffloor::op(std::uint64_t* a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational ffloor fixnum
LispObject Ffloor::op(Rat a, Fixnum b)
{   if (b == 0) return a.value();
    return make_ratio(Binary(Ffloor, a.numerator(),
                                 Binary(Ffloor, a.denominator(), b)),
                      a.denominator());
}

// complex ffloor fixnum
LispObject Ffloor::op(Cpx a, Fixnum b)
{   if (b == 0) return a.v;
    return make_complex(Binary(Ffloor, a.real_part(), b), a.imag_part());
}

// short float ffloor fixnum
LispObject Ffloor::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// single float ffloor fixnum
LispObject Ffloor::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / static_cast<double>(int_of_fixnum(b)));
}

// double float ffloor fixnum
LispObject Ffloor::op(double a, Fixnum b)
{   return make_boxfloat(a / static_cast<double>(int_of_fixnum(b)));
}

// long float ffloor fixnum
LispObject Ffloor::op(FLOAT_128 a, Fixnum b)
{   return make_boxfloat128(a / (FLOAT_128)int_of_fixnum(b));
}

// fixnum ffloor bignum
LispObject Ffloor::op(Fixnum a, std::uint64_t* b)
{   return fixnum_of_int(0);
}

// bignum ffloor bignum
LispObject Ffloor::op(std::uint64_t* a, std::uint64_t* b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational ffloor bignum
LispObject Ffloor::op(Rat a, std::uint64_t* b)
{   LispObject g = IBinary(Gcdn, a.denominator(), bignum_value(b));
    return make_ratio(Binary(Times, a.numerator(),
                                    Binary(Ffloor, bignum_value(b), g)),
                      Binary(Ffloor, a.denominator(), g));
}

// complex ffloor bignum
LispObject Ffloor::op(Cpx a, std::uint64_t* b)
{   return make_complex(Binary(Ffloor, a.real_part(), bignum_value(b)),
                        Binary(Ffloor, a.imag_part(), bignum_value(b)));
}

// short float ffloor bignum
LispObject Ffloor::op(SFlt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float ffloor bignum
LispObject Ffloor::op(Flt a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float ffloor bignum
LispObject Ffloor::op(double a, std::uint64_t* b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float ffloor bignum
LispObject Ffloor::op(FLOAT_128 a, std::uint64_t* b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum ffloor rational
LispObject Ffloor::op(Fixnum a, Rat b)
{   LispObject g = IBinary(Gcdn, a, b.numerator());
    LispObject p = Binary(Times, Binary(Ffloor, a, g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// bignum ffloor rational
LispObject Ffloor::op(std::uint64_t* a, Rat b)
{   LispObject g = IBinary(Gcdn, bignum_value(a), b.numerator());
    LispObject p = Binary(Times, Binary(Ffloor, bignum_value(a), g), b.denominator());
    LispObject q = b.numerator();
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// rational ffloor rational
LispObject Ffloor::op(Rat a, Rat b)
{   LispObject g1 = IBinary(Gcdn, a.numerator(), b.numerator());
    LispObject g2 = IBinary(Gcdn, a.denominator(), b.denominator());
    LispObject na = Binary(Ffloor, a.numerator(), g1);
    LispObject nb = Binary(Ffloor, b.denominator(), g2);
    LispObject da = Binary(Ffloor, a.denominator(), g2);
    LispObject db = Binary(Ffloor, b.numerator(), g1);
    LispObject p = Binary(Times, na, nb);
    LispObject q = Binary(Times, da, db);
    if (BoolUnary(Minusp, q))
    {   p = Unary(Minus, p);
        q = Unary(Minus, q);
    }
    return make_ratio(p, q);
}

// complex ffloor rational
LispObject Ffloor::op(Cpx a, Rat b)
{   return make_complex(Binary(Ffloor, a.real_part(), b.value()),
                        Binary(Ffloor, a.imag_part(), b.value()));
}

// short float ffloor rational
LispObject Ffloor::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float ffloor rational
LispObject Ffloor::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float ffloor rational
LispObject Ffloor::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float ffloor rational
LispObject Ffloor::op(FLOAT_128 a, Rat b)
{   std::int64_t xx;
    FLOAT_128 bb = Frexp128::op(b, xx);
    FLOAT_128 d = a / bb;
    d = ldexp(d, -xx);
    return make_boxfloat128(d);
}

// fixnum ffloor complex
LispObject Ffloor::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
}

// bignum ffloor complex
LispObject Ffloor::op(std::uint64_t* a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational ffloor complex
LispObject Ffloor::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex ffloor complex
LispObject Ffloor::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float ffloor complex
LispObject Ffloor::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float ffloor complex
LispObject Ffloor::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float ffloor complex
LispObject Ffloor::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float ffloor complex
LispObject Ffloor::op(FLOAT_128 a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum ffloor short float
LispObject Ffloor::op(Fixnum a, SFlt b)
{   return pack_single_float(static_cast<double>(int_of_fixnum(a)) / b.floatval());
}

// bignum ffloor short float
LispObject Ffloor::op(std::uint64_t* a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational ffloor short float
LispObject Ffloor::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex ffloor short float
LispObject Ffloor::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float ffloor short float
LispObject Ffloor::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float ffloor short float
LispObject Ffloor::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float ffloor short float
LispObject Ffloor::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float ffloor short float
LispObject Ffloor::op(FLOAT_128 a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum ffloor single float
LispObject Ffloor::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum ffloor single float
LispObject Ffloor::op(std::uint64_t* a, Flt b)
{   arithlib_abort("not done yet");
}

// rational ffloor single float
LispObject Ffloor::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex ffloor single float
LispObject Ffloor::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float ffloor single float
LispObject Ffloor::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float ffloor single float
LispObject Ffloor::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float ffloor single float
LispObject Ffloor::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float ffloor single float
LispObject Ffloor::op(FLOAT_128 a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum ffloor double float
LispObject Ffloor::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum ffloor double float
LispObject Ffloor::op(std::uint64_t* a, double b)
{   arithlib_abort("not done yet");
}

// rational ffloor double float
LispObject Ffloor::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex ffloor double float
LispObject Ffloor::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float ffloor double float
LispObject Ffloor::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float ffloor double float
LispObject Ffloor::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float ffloor double float
LispObject Ffloor::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float ffloor double float
LispObject Ffloor::op(FLOAT_128 a, double b)
{   arithlib_abort("not done yet");
}

// fixnum ffloor long float
LispObject Ffloor::op(Fixnum a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// bignum ffloor long float
LispObject Ffloor::op(std::uint64_t* a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// rational ffloor long float
LispObject Ffloor::op(Rat a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// complex ffloor long float
LispObject Ffloor::op(Cpx a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// short float ffloor long float
LispObject Ffloor::op(SFlt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// single float ffloor long float
LispObject Ffloor::op(Flt a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// double float ffloor long float
LispObject Ffloor::op(double a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}

// long float ffloor long float
LispObject Ffloor::op(FLOAT_128 a, FLOAT_128 b)
{   arithlib_abort("not done yet");
}


LispObject Ntimes(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(1);
}

LispObject Ntimes(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Ntimes(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Times, a1, a2);
}

LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   SingleValued fn;
    return Binary(Times, Binary(Times, a1, a2), a3);
}

LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Binary(Times, Binary(Times, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Binary(Times, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

//LispObject Nexpt(LispObject env, LispObject a1, LispObject a2)
//{   SingleValued fn;
//    return Binary(Expt, a1, a2);
//}

LispObject Ngcdn(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Ngcdn(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

#define CHECK_TIMES 1

LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
#ifdef CHECK_TIMES
    LispObject r = IBinary(Gcdn, a1, a2);
    LispObject a = a1;
    LispObject b = a2;
    if (BoolUnary(Minusp, a)) a = Unary(Minus, a);
    if (BoolUnary(Minusp, b)) b = Unary(Minus, b);
    while (b != fixnum_of_int(0))
    {   LispObject c = Binary(Remainder, a, b);
        a = b;
        b = c;
    }
    if (a != r && !equal_fn(a, r))
        aerror2("gcd failure", cons(a1, a2), cons(r, a));
    return r;
#else // CHECK_TIMES
    return IBinary(Gcdn, a1, a2);
#endif // CHECK_TIMES
}

LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Gcdn, IBinary(Gcdn, a1, a2), a3);
}

LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Gcdn, IBinary(Gcdn, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Gcdn, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nlcmn(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(1);
}

LispObject Nlcmn(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(Lcmn, a1, a2);
}

LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Lcmn, IBinary(Lcmn, a1, a2), a3);
}

LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Lcmn, IBinary(Lcmn, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Lcmn, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nquotient(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
#ifdef CHECK_TIMES
// For quotients and remainders I will use divide() here and I will put the
// testing there.
    return car(Ndivide(env, a1, a2));
#else // CHECK_TIMES
    return Binary(Quotient, a1, a2);
#endif // CHECK_TIMES
}

LispObject NCLQuotient(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(CLQuotient, a1, a2);
}

LispObject Nremainder(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
#ifdef CHECK_TIMES
    return cdr(Ndivide(env, a1, a2));
#else // CHECK_TIMES
    return Binary(Remainder, a1, a2);
#endif // CHECK_TIMES
}

LispObject Nmod(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(Mod, a1, a2);
}

LispObject Ndivide(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
#ifdef CHECK_TIMES
    if ((is_fixnum(a1) || is_new_bignum(a1)) &&
        (is_fixnum(a2) || is_new_bignum(a2)))
    {   LispObject w = Binary(Divide, a1, a2);
        LispObject quo = car(w);
        LispObject rem = cdr(w);
// quotient & remainder will be correct if a1 = a2*quo + rem and
// also rem is between 0 and sign(a1)*|a2|
        LispObject xa1 = Binary(Plus, Binary(Times, a2, quo), rem);
        LispObject xa1a = Binary(Plus, Binary(ClassicalTimes, a2, quo), rem);
        if (xa1 != xa1a && !equal_fn(xa1, xa1a))
            aerror2("multiplication failure", cons(a2, quo), cons(xa1, xa1a));
        if (a1 != xa1 && !equal_fn(a1, xa1))
            aerror2("quotient failure", cons(a1, a2), w);
        if (rem == fixnum_of_int(0)) return w; // zero remainder OK
        if (BoolUnary(Minusp, a1))
        {   if (BoolUnary(Minusp, a2))
            {   // a1 and a2 must both negative. remainder must satisfy
                // a2 < remainder < 0
                if (BoolBinary(Lessp, a2, rem) &&
                    BoolUnary(Minusp, rem)) return w;
            }
            else
            {   // a1 negative, a2 positive. Want -a2 < remainder < 0
                if (BoolBinary(Lessp, Unary(Minus, a2), rem) &&
                    BoolUnary(Minusp, rem)) return w;
            }
        }
        else if (BoolUnary(Minusp, a2))
        {   // a1 positive, a2 negative. 0 <= remainder < -a2
            if (BoolUnary(Plusp, rem) &&
                BoolBinary(Lessp, rem, Unary(Minus, a2))) return w;
        }
        else
        {   // both a1 and a2 positive. 0 <= remainder < a2
            if (BoolUnary(Plusp, rem) &&
                BoolBinary(Lessp, rem, a2)) return w;
        }
        aerror2("quotient failure", cons(a1, a2), w);
    }
#endif // CHECK_TIMES
    return Binary(Divide, a1, a2);
}

LispObject Nreciprocal(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Reciprocal, a1);
}

LispObject Nsquare(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Square, a1);
}

LispObject Nitimes(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(1);
}

LispObject Nitimes(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

// The idea is that itimes should be used on just fixnums and should
// only ne used when there will be no overflow.

LispObject Nitimes(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Times, a1, a2);
}

LispObject Nitimes(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return Binary(Times, Binary(Times, a1, a2), a3);
}

LispObject Nitimes(LispObject env, LispObject a1, LispObject a2,
                   LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Binary(Times, Binary(Times, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Binary(Times, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Niexpt(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Nexpt(env, a1, a2);
}

LispObject Nigcdn(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nigcdn(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(Gcdn, a1, a2);
}

LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Gcdn, IBinary(Gcdn, a1, a2), a3);
}

LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Gcdn, IBinary(Gcdn, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Gcdn, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nilcmn(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(1);
}

LispObject Nilcmn(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(Lcmn, a1, a2);
}

LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Lcmn, IBinary(Lcmn, a1, a2), a3);
}

LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Lcmn, IBinary(Lcmn, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Lcmn, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Niquotient(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Quotient, a1, a2);
}

LispObject Nimod(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(Mod, a1, a2);
}

LispObject Nidivide(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Binary(Divide, a1, a2);
}

LispObject Nireciprocal(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Reciprocal, a1);
}

LispObject Nisquare(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Square, a1);
}

} // end of namespace

#endif // ARITHLIB

// end of arith-times.cpp
