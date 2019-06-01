// arith-times.cpp                              Copyright (C) 2019 Codemist

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

// Times, Quotient, Remainder, Divide etc

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


LispObject Times::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Times>("times", a, b);
}

LispObject Times::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

LispObject Times::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

LispObject Times::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

LispObject Times::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

LispObject Times::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

LispObject Times::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

LispObject Times::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

LispObject Times::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Times>("times", a, b);
}

// fixnum * fixnum
LispObject Times::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Times::op(a.intval(), b.intval());
}
// bignum * fixnum
LispObject Times::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Times::op(a, b.intval());
}
// rational * fixnum
LispObject Times::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Times::op(a.numerator(),
                               Times::op(a.denominator(), b)),
                      a.denominator());
}
// complex * fixnum
LispObject Times::op(Cpx a, Fixnum b)
{   return make_complex(Times::op(a.real_part(), b),
                        Times::op(a.imag_part(), b));
}
// short float * fixnum
LispObject Times::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() * (double)b.value());
}
// single float * fixnum
LispObject Times::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() * (double)b.intval());
}
// double float * fixnum
LispObject Times::op(double a, Fixnum b)
{   return make_boxfloat(a * (double)b.intval());
}
// long float * fixnum
LispObject Times::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_mul(a.floatval(), i64_to_f128(b.intval())));
}
// fixnum * bignum
LispObject Times::op(Fixnum a, uint64_t *b)
{   return Times::op(b, a);
}
// bignum * bignum
LispObject Times::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Times::op(a, b);
}
// rational * bignum
LispObject Times::op(Rat a, uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    LispObject cofactor = Quotient::op(b, g);
    return make_ratio(Times::op(a.numerator(), cofactor),
                      Quotient::op(a.denominator(), g));
}
// complex * bignum
LispObject Times::op(Cpx a, uint64_t *b)
{   return make_complex(Times::op(a.real_part(), b),
                        Times::op(a.imag_part(), b));
}
// short float * bignum
LispObject Times::op(SFlt a, uint64_t *b)
{   return pack_short_float(a.floatval() * RawFloat::op(b));
}
// single float * bignum
LispObject Times::op(Flt a, uint64_t *b)
{   return pack_single_float(a.floatval() * RawFloat::op(b));
}
// double float * bignum
LispObject Times::op(double a, uint64_t *b)
{   return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float * bignum
LispObject Times::op(LFlt a, uint64_t *b)
{   return make_boxfloat128(f128_mul(a.floatval(), RawFloat128::op(b)));
}
// fixnum * rational
LispObject Times::op(Fixnum a, Rat b)
{   return Times::op(b, a);
}
// bignum * rational
LispObject Times::op(uint64_t *a, Rat b)
{   return Times::op(b, a);
}
// rational * rational
LispObject Times::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.denominator());
    LispObject g2 = Gcdn::op(a.denominator(), b.numerator());
    LispObject na = Quotient::op(a.numerator(), g1);
    LispObject nb = Quotient::op(b.numerator(), g2);
    LispObject da = Quotient::op(a.denominator(), g2);
    LispObject db = Quotient::op(b.denominator(), g1);
    return make_ratio(Times::op(na, nb), Times::op(da, db));
}
// complex * rational
LispObject Times::op(Cpx a, Rat b)
{   return make_complex(Times::op(a.real_part(), b),
                        Times::op(a.imag_part(), b));
}
// short float * rational
// The key mess here is that I do not want to trigger exponent overflow
// early, but the numerator and denominators of the rational could be
// really huge.
LispObject Times::op(SFlt a, Rat b)
{   int64_t xb;
    double d = Frexp::op(b, xb); // A special version for internal use!
    int x;
    d *= std::frexp(a.floatval(), &x);
    x += xb;
    d = std::ldexp(d, x);
    return pack_short_float(d);
}
// single float * rational
LispObject Times::op(Flt a, Rat b)
{   int64_t xb;
    double d = Frexp::op(b, xb);
    int x;
    d *= std::frexp(a.floatval(), &x);
    x += xb;
    d = std::ldexp(d, x);
    return pack_single_float(d);
}
// double float * rational
LispObject Times::op(double a, Rat b)
{   int64_t xb;
    double d = Frexp::op(b, xb);
    int x;
    d *= std::frexp(a, &x);
    x += xb;
    d = std::ldexp(d, x);
    return make_boxfloat(d);
}
// long float * rational
LispObject Times::op(LFlt a, Rat b)
{   int64_t xb;
    float128_t d = Frexp128::op(b, xb);
    int x;
    float128_t d1 = a.floatval();
    f128M_frexp(&d1, &d1, &x);
    x += xb;
    d = f128_mul(d, d1);
    f128M_ldexp(&d, x);
    return make_boxfloat128(d);
}
// fixnum * complex
LispObject Times::op(Fixnum a, Cpx b)
{   return Times::op(b, a);
}
// bignum * complex
LispObject Times::op(uint64_t *a, Cpx b)
{   return Times::op(b, a);
}
// rational * complex
LispObject Times::op(Rat a, Cpx b)
{   return Times::op(b, a);
}
// complex * complex
LispObject Times::op(Cpx a, Cpx b)
{   return make_complex(
        Difference::op(Times::op(a.real_part(), b.real_part()),
                       Times::op(a.imag_part(), b.imag_part())),
        Plus::op(Times::op(a.real_part(), b.imag_part()),
                 Times::op(a.imag_part(), b.real_part())));
}
// short float * complex
LispObject Times::op(SFlt a, Cpx b)
{   return make_complex(Times::op(b.real_part(), a),
                        Times::op(b.imag_part(), a));
}
// single float * complex
LispObject Times::op(Flt a, Cpx b)
{   return make_complex(Times::op(b.real_part(), a),
                        Times::op(b.imag_part(), a));
}
// double float * complex
LispObject Times::op(double a, Cpx b)
{   return make_complex(Times::op(b.real_part(), a),
                        Times::op(b.imag_part(), a));
}
// long float * complex
LispObject Times::op(LFlt a, Cpx b)
{   return make_complex(Times::op(b.real_part(), a),
                        Times::op(b.imag_part(), a));
}
// fixnum * short float
LispObject Times::op(Fixnum a, SFlt b)
{   return Times::op(b, a);
}
// bignum * short float
LispObject Times::op(uint64_t *a, SFlt b)
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
LispObject Times::op(LFlt a, SFlt b)
{   return make_boxfloat128(f128_mul(a.floatval(), RawFloat128::op(b)));
}
// fixnum * single float
LispObject Times::op(Fixnum a, Flt b)
{   return Times::op(b, a);
}
// bignum * single float
LispObject Times::op(uint64_t *a, Flt b)
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
{   return make_boxfloat(a, b.floatval());
}
// long float * single float
LispObject Times::op(LFlt a, Flt b)
{   return make_boxfloat128(f128_mul(a.floatval(), RawFloat128::op(b)));
}
// fixnum * double float
LispObject Times::op(Fixnum a, double b)
{   return Times::op(b, a);
}
// bignum * double float
LispObject Times::op(uint64_t *a, double b)
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
LispObject Times::op(LFlt a, double b)
{   return make_boxfloat128(f128_mul(a.floatval(), RawFloat128::op(b)));
}
// fixnum * long float
LispObject Times::op(Fixnum a, LFlt b)
{   return Times::op(b, a);
}
// bignum * long float
LispObject Times::op(uint64_t *a, LFlt b)
{   return Times::op(b, a);
}
// rational * long float
LispObject Times::op(Rat a, LFlt b)
{   return Times::op(b, a);
}
// complex * long float
LispObject Times::op(Cpx a, LFlt b)
{   return Times::op(b, a);
}
// short float * long float
LispObject Times::op(SFlt a, LFlt b)
{   return Times::op(b, a);
}
// single float * long float
LispObject Times::op(Flt a, LFlt b)
{   return Times::op(b, a);
}
// double float * long float
LispObject Times::op(double a, LFlt b)
{   return Times::op(b, a);
}
// long float * long float
LispObject Times::op(LFlt a, LFlt b)
{   return make_boxfloat128(f128_mul(a.floatval(), b.floatval()));
}

LispObject Expt::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

LispObject Expt::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Expt>("expt", a, b);
}

// fixnum ** fixnum
LispObject Expt::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Pow::op(a.intval(), b.intval());
}
// bignum ** fixnum
LispObject Expt::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Pow::op(a, b.intval());
}
template <typename T>
LispObject generic_expt(T a, int64_t n)
{   if (n == 1) return a.value();
    else
    {   LispObject aa = generic_expt(a, n/2);
        aa = Square::op(aa);
        if ((n & 1) != 0) aa = Times::op(aa, a);
        return aa;
    }
}

// rational ** fixnum
LispObject Expt::op(Rat a, Fixnum b)
{   int64_t n = b.intval();
    if (n == 0) return make_ratio(fixnum_of_int(1), fixnum_of_int(1));
    else if (n == 1) return a.value();
    else if (n < 0)
    {   n = -n;
        a = Reciprocal::op(a);
    }
    return generic_expt(a, n);
}

LispObject match_type(LispObject in, int value)
{   switch (in & XTAG_BITS)
    {
    case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
        switch (type_of_header(flthdr(in)))
        {
        case TYPE_SINGLE_FLOAT:
            return pack_single_float((double)value);
        case TYPE_DOUBLE_FLOAT:
            return make_boxfloat((double)value);
        case TYPE_LONG_FLOAT:
            return make_boxfloat128(i64_to_f128(value));
        default:
            aerror1("Invalid component in complex number", in);
        }
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(in)))
        {
        case TYPE_NEW_BIGNUM:
        case TYPE_BIGNUM:
            return fixnum_of_int(value);
        case TYPE_RATNUM:
            return make_ratio(fixnum_of_int(value), fixnum_of_int(1));
        case TYPE_COMPLEX_NUM:
        default:
            aerror1("Invalid component in complex number", in);
        }
    default:
    case TAG_FIXNUM:
        return fixnum_of_int(value);
    case XTAG_SFLOAT:
        if ((in & XTAG_FLOAT32) != 0)
            return pack_single_float((double)value);
        else return pack_short_float((double)value);
    }
}

LispObject Expt::op(Cpx a, Fixnum b)
{   int64_t n = b.intval();
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
    return generic_expt(a, n);
}

// short float ** fixnum
LispObject Expt::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() * (double)b.value());
}
// single float ** fixnum
LispObject Expt::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() * (double)b.intval());
}
// double float ** fixnum
LispObject Expt::op(double a, Fixnum b)
{   return make_boxfloat(a * (double)b.intval());
}
// long float ** fixnum
LispObject Expt::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_add(a.floatval(), i64_to_f128(b.intval())));
}
// fixnum ** bignum
LispObject Expt::op(Fixnum a, uint64_t *b)
{   abort("not done yet");
}
// bignum ** bignum
LispObject Expt::op(uint64_t *a, uint64_t *b)
{   if (arithlib_lowlevel::Minusp::op(b)) return fixnum_of_int(0);
    aerror("arguments to expt are too large");
}
// rational ** bignum
LispObject Expt::op(Rat a, uint64_t *b)
{   abort("times not coded yet");
}
// complex ** bignum
LispObject Expt::op(Cpx a, uint64_t *b)
{   abort("times not coded yet");
}
// short float ** bignum
LispObject Expt::op(SFlt a, uint64_t *b)
{   abort("times not coded yet");
}
// single float ** bignum
LispObject Expt::op(Flt a, uint64_t *b)
{   abort("times not coded yet");
}
// double float ** bignum
LispObject Expt::op(double a, uint64_t *b)
{   return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float ** bignum
LispObject Expt::op(LFlt a, uint64_t *b)
{   abort("times not coded yet");
}
// fixnum ** rational
LispObject Expt::op(Fixnum a, Rat b)
{   abort("not done yet");
}
// bignum ** rational
LispObject Expt::op(uint64_t *a, Rat b)
{   abort("not done yet");
}
// rational ** rational
LispObject Expt::op(Rat a, Rat b)
{   abort("times not coded yet");
}
// complex ** rational
LispObject Expt::op(Cpx a, Rat b)
{   abort("times not coded yet");
}
// short float ** rational
LispObject Expt::op(SFlt a, Rat b)
{   abort("times not coded yet");
}
// single float ** rational
LispObject Expt::op(Flt a, Rat b)
{   abort("times not coded yet");
}
// double float ** rational
LispObject Expt::op(double a, Rat b)
{   abort("times not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float ** rational
LispObject Expt::op(LFlt a, Rat b)
{   abort("times not coded yet");
}
// fixnum ** complex
LispObject Expt::op(Fixnum a, Cpx b)
{   abort("not done yet");
}
// bignum ** complex
LispObject Expt::op(uint64_t *a, Cpx b)
{   abort("not done yet");
}
// rational ** complex
LispObject Expt::op(Rat a, Cpx b)
{   abort("not done yet");
}
// complex ** complex
LispObject Expt::op(Cpx a, Cpx b)
{   abort("times not coded yet");
}
// short float ** complex
LispObject Expt::op(SFlt a, Cpx b)
{   abort("times not coded yet");
}
// single float ** complex
LispObject Expt::op(Flt a, Cpx b)
{   abort("times not coded yet");
}
// double float ** complex
LispObject Expt::op(double a, Cpx b)
{   abort("times not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float ** complex
LispObject Expt::op(LFlt a, Cpx b)
{   abort("times not coded yet");
}
// fixnum ** short float
LispObject Expt::op(Fixnum a, SFlt b)
{   abort("not done yet");
}
// bignum ** short float
LispObject Expt::op(uint64_t *a, SFlt b)
{   abort("not done yet");
}
// rational ** short float
LispObject Expt::op(Rat a, SFlt b)
{   abort("not done yet");
}
// complex ** short float
LispObject Expt::op(Cpx a, SFlt b)
{   abort("not done yet");
}
// short float ** short float
LispObject Expt::op(SFlt a, SFlt b)
{   abort("times not coded yet");
}
// single float ** short float
LispObject Expt::op(Flt a, SFlt b)
{   abort("times not coded yet");
}
// double float ** short float
LispObject Expt::op(double a, SFlt b)
{   abort("times not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float ** short float
LispObject Expt::op(LFlt a, SFlt b)
{   abort("times not coded yet");
}
// fixnum ** single float
LispObject Expt::op(Fixnum a, Flt b)
{   abort("not done yet");
}
// bignum ** single float
LispObject Expt::op(uint64_t *a, Flt b)
{   abort("not done yet");
}
// rational ** single float
LispObject Expt::op(Rat a, Flt b)
{   abort("not done yet");
}
// complex ** single float
LispObject Expt::op(Cpx a, Flt b)
{   abort("not done yet");
}
// short float ** single float
LispObject Expt::op(SFlt a, Flt b)
{   abort("not done yet");
}
// single float ** single float
LispObject Expt::op(Flt a, Flt b)
{   abort("times not coded yet");
}
// double float ** single float
LispObject Expt::op(double a, Flt b)
{   abort("times not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float ** single float
LispObject Expt::op(LFlt a, Flt b)
{   abort("times not coded yet");
}
// fixnum ** double float
LispObject Expt::op(Fixnum a, double b)
{   abort("not done yet");
}
// bignum ** double float
LispObject Expt::op(uint64_t *a, double b)
{   abort("not done yet");
}
// rational ** double float
LispObject Expt::op(Rat a, double b)
{   abort("not done yet");
}
// complex ** double float
LispObject Expt::op(Cpx a, double b)
{   abort("not done yet");
}
// short float ** double float
LispObject Expt::op(SFlt a, double b)
{   abort("not done yet");
}
// single float ** double float
LispObject Expt::op(Flt a, double b)
{   abort("not done yet");
}
// double float ** double float
LispObject Expt::op(double a, double b)
{   return make_boxfloat(pow(a, b));
}
// long float ** double float
LispObject Expt::op(LFlt a, double b)
{   abort("times not coded yet");
}
// fixnum ** long float
LispObject Expt::op(Fixnum a, LFlt b)
{   abort("not done yet");
}
// bignum ** long float
LispObject Expt::op(uint64_t *a, LFlt b)
{   abort("not done yet");
}
// rational ** long float
LispObject Expt::op(Rat a, LFlt b)
{   abort("not done yet");
}
// complex ** long float
LispObject Expt::op(Cpx a, LFlt b)
{   abort("not done yet");
}
// short float ** long float
LispObject Expt::op(SFlt a, LFlt b)
{   abort("not done yet");
}
// single float ** long float
LispObject Expt::op(Flt a, LFlt b)
{   abort("not done yet");
}
// double float ** long float
LispObject Expt::op(double a, LFlt b)
{   abort("not done yet");
}
// long float ** long float
LispObject Expt::op(LFlt a, LFlt b)
{   abort("times not coded yet");
}

LispObject Quotient::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Quotient>("quotient", a, b);
}

// fixnum / fixnum
LispObject Quotient::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a.intval(), b.intval());
}
// bignum / fixnum
LispObject Quotient::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}
// rational / fixnum
LispObject Quotient::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Quotient::op(a.numerator(),
                               Quotient::op(a.denominator(), b)),
                      a.denominator());
}
// complex / fixnum
LispObject Quotient::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Quotient::op(a.real_part(), b), a.imag_part());
}
// short float / fixnum
LispObject Quotient::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}
// single float / fixnum
LispObject Quotient::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}
// double float / fixnum
LispObject Quotient::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}
// long float / fixnum
LispObject Quotient::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}
// fixnum / bignum
LispObject Quotient::op(Fixnum a, uint64_t *b)
{   return fixnum_of_int(0);
}
// bignum / bignum
LispObject Quotient::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}
// rational / bignum
LispObject Quotient::op(Rat a, uint64_t *b)
{   abort("times not coded yet");
}
// complex / bignum
LispObject Quotient::op(Cpx a, uint64_t *b)
{   abort("times not coded yet");
}
// short float / bignum
LispObject Quotient::op(SFlt a, uint64_t *b)
{   abort("times not coded yet");
}
// single float / bignum
LispObject Quotient::op(Flt a, uint64_t *b)
{   abort("times not coded yet");
}
// double float / bignum
LispObject Quotient::op(double a, uint64_t *b)
{   return make_boxfloat(a / arithlib_lowlevel::Double::op(b));
}
// long float / bignum
LispObject Quotient::op(LFlt a, uint64_t *b)
{   abort("times not coded yet");
}
// fixnum / rational
LispObject Quotient::op(Fixnum a, Rat b)
{   abort("not coded yet");
}
// bignum / rational
LispObject Quotient::op(uint64_t *a, Rat b)
{   abort("not coded yet");
}
// rational / rational
LispObject Quotient::op(Rat a, Rat b)
{   abort("not coded yet");
}
// complex / rational
LispObject Quotient::op(Cpx a, Rat b)
{   abort("not coded yet");

}
// short float / rational
LispObject Quotient::op(SFlt a, Rat b)
{   abort("not coded yet");

}
// single float / rational
LispObject Quotient::op(Flt a, Rat b)
{   abort("not coded yet");

}
// double float / rational
LispObject Quotient::op(double a, Rat b)
{   abort("not coded yet");
//      return make_boxfloat(a / arithlib_lowlevel::Double::op(b));
}
// long float / rational
LispObject Quotient::op(LFlt a, Rat b)
{   abort("not coded yet");
}
// fixnum / complex
LispObject Quotient::op(Fixnum a, Cpx b)
{   abort("not coded yet");
}
// bignum / complex
LispObject Quotient::op(uint64_t *a, Cpx b)
{   abort("not coded yet");
}
// rational / complex
LispObject Quotient::op(Rat a, Cpx b)
{   abort("not coded yet");
}
// complex / complex
LispObject Quotient::op(Cpx a, Cpx b)
{   abort("not coded yet");
}
// short float / complex
LispObject Quotient::op(SFlt a, Cpx b)
{   abort("not coded yet");
}
// single float / complex
LispObject Quotient::op(Flt a, Cpx b)
{   abort("not coded yet");
}
// double float / complex
LispObject Quotient::op(double a, Cpx b)
{   abort("not coded yet");
}
// long float / complex
LispObject Quotient::op(LFlt a, Cpx b)
{   abort("not coded yet");
}
// fixnum / short float
LispObject Quotient::op(Fixnum a, SFlt b)
{   abort("not coded yet");
}
// bignum / short float
LispObject Quotient::op(uint64_t *a, SFlt b)
{   abort("not coded yet");
}
// rational / short float
LispObject Quotient::op(Rat a, SFlt b)
{   abort("not coded yet");
}
// complex / short float
LispObject Quotient::op(Cpx a, SFlt b)
{   abort("not coded yet");
}
// short float / short float
LispObject Quotient::op(SFlt a, SFlt b)
{   abort("not coded yet");
}
// single float / short float
LispObject Quotient::op(Flt a, SFlt b)
{   abort("not coded yet");
}
// double float / short float
LispObject Quotient::op(double a, SFlt b)
{   abort("not coded yet");
}
// long float / short float
LispObject Quotient::op(LFlt a, SFlt b)
{   abort("not coded yet");
}
// fixnum / single float
LispObject Quotient::op(Fixnum a, Flt b)
{   abort("not coded yet");
}
// bignum / single float
LispObject Quotient::op(uint64_t *a, Flt b)
{   abort("not coded yet");
}
// rational / single float
LispObject Quotient::op(Rat a, Flt b)
{   abort("not coded yet");
}
// complex / single float
LispObject Quotient::op(Cpx a, Flt b)
{   abort("not coded yet");
}
// short float / single float
LispObject Quotient::op(SFlt a, Flt b)
{   abort("not coded yet");
}
// single float / single float
LispObject Quotient::op(Flt a, Flt b)
{   abort("not coded yet");
}
// double float / single float
LispObject Quotient::op(double a, Flt b)
{   abort("not coded yet");
}
// long float / single float
LispObject Quotient::op(LFlt a, Flt b)
{   abort("not coded yet");
}
// fixnum / double float
LispObject Quotient::op(Fixnum a, double b)
{   abort("not coded yet");
}
// bignum / double float
LispObject Quotient::op(uint64_t *a, double b)
{   abort("not coded yet");
}
// rational / double float
LispObject Quotient::op(Rat a, double b)
{   abort("not coded yet");
}
// complex / double float
LispObject Quotient::op(Cpx a, double b)
{   abort("not coded yet");
}
// short float / double float
LispObject Quotient::op(SFlt a, double b)
{   abort("not coded yet");
}
// single float / double float
LispObject Quotient::op(Flt a, double b)
{   abort("not coded yet");
}
// double float / double float
LispObject Quotient::op(double a, double b)
{   return make_boxfloat(a / b);
}
// long float / double float
LispObject Quotient::op(LFlt a, double b)
{   abort("not coded yet");
}
// fixnum / long float
LispObject Quotient::op(Fixnum a, LFlt b)
{   abort("not coded yet");
}
// bignum / long float
LispObject Quotient::op(uint64_t *a, LFlt b)
{   abort("not coded yet");
}
// rational / long float
LispObject Quotient::op(Rat a, LFlt b)
{   abort("not coded yet");
}
// complex / long float
LispObject Quotient::op(Cpx a, LFlt b)
{   abort("not coded yet");
}
// short float / long float
LispObject Quotient::op(SFlt a, LFlt b)
{   abort("not coded yet");
}
// single float / long float
LispObject Quotient::op(Flt a, LFlt b)
{   abort("not coded yet");
}
// double float / long float
LispObject Quotient::op(double a, LFlt b)
{   abort("not coded yet");
}
// long float / long float
LispObject Quotient::op(LFlt a, LFlt b)
{   abort("times not coded yet");
}

LispObject Remainder::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Remainder>("remainder", a, b);
}

// fixnum remainder fixnum
LispObject Remainder::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Remainder::op(a.intval(), b.intval());
}
// bignum remainder fixnum
LispObject Remainder::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Remainder::op(a, b.intval());
}
// rational remainder fixnum
LispObject Remainder::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Remainder::op(a.numerator(),
                               Remainder::op(a.denominator(), b)),
                      a.denominator());
}
// complex % fixnum
LispObject Remainder::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Remainder::op(a.real_part(), b), a.imag_part());
}
// short float % fixnum
LispObject Remainder::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() * (double)b.value());
}
// single float % fixnum
LispObject Remainder::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() * (double)b.intval());
}
// double float % fixnum
LispObject Remainder::op(double a, Fixnum b)
{   return make_boxfloat(a * (double)b.intval());
}
// long float % fixnum
LispObject Remainder::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}
// fixnum % bignum
LispObject Remainder::op(Fixnum a, uint64_t *b)
{   return a.value();
}
// bignum % bignum
LispObject Remainder::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Remainder::op(a, b);
}
// rational % bignum
LispObject Remainder::op(Rat a, uint64_t *b)
{   abort("remainder not coded yet");
}
// complex % bignum
LispObject Remainder::op(Cpx a, uint64_t *b)
{   abort("remainder not coded yet");
}
// short float % bignum
LispObject Remainder::op(SFlt a, uint64_t *b)
{   abort("remainder not coded yet");
}
// single float % bignum
LispObject Remainder::op(Flt a, uint64_t *b)
{   abort("remainder not coded yet");
}
// double float % bignum
LispObject Remainder::op(double a, uint64_t *b)
{   return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float % bignum
LispObject Remainder::op(LFlt a, uint64_t *b)
{   abort("remainder not coded yet");
}
// fixnum % rational
LispObject Remainder::op(Fixnum a, Rat b)
{   abort("not done yet");
}
// bignum % rational
LispObject Remainder::op(uint64_t *a, Rat b)
{   abort("not done yet");
}
// rational % rational
LispObject Remainder::op(Rat a, Rat b)
{   abort("remainder not coded yet");
}
// complex % rational
LispObject Remainder::op(Cpx a, Rat b)
{   abort("remainder not coded yet");
}
// short float % rational
LispObject Remainder::op(SFlt a, Rat b)
{   abort("remainder not coded yet");
}
// single float % rational
LispObject Remainder::op(Flt a, Rat b)
{   abort("remainder not coded yet");
}
// double float % rational
LispObject Remainder::op(double a, Rat b)
{   abort("remainder not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float % rational
LispObject Remainder::op(LFlt a, Rat b)
{   abort("remainder not coded yet");
}
// fixnum % complex
LispObject Remainder::op(Fixnum a, Cpx b)
{   abort("not done yet");
}
// bignum % complex
LispObject Remainder::op(uint64_t *a, Cpx b)
{   abort("not done yet");
}
// rational % complex
LispObject Remainder::op(Rat a, Cpx b)
{   abort("not done yet");
}
// complex % complex
LispObject Remainder::op(Cpx a, Cpx b)
{   abort("remainder not coded yet");
}
// short float % complex
LispObject Remainder::op(SFlt a, Cpx b)
{   abort("remainder not coded yet");
}
// single float % complex
LispObject Remainder::op(Flt a, Cpx b)
{   abort("remainder not coded yet");
}
// double float % complex
LispObject Remainder::op(double a, Cpx b)
{   abort("remainder not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float % complex
LispObject Remainder::op(LFlt a, Cpx b)
{   abort("remainder not coded yet");
}
// fixnum % short float
LispObject Remainder::op(Fixnum a, SFlt b)
{   abort("not done yet");
}
// bignum % short float
LispObject Remainder::op(uint64_t *a, SFlt b)
{   abort("not done yet");
}
// rational % short float
LispObject Remainder::op(Rat a, SFlt b)
{   abort("not done yet");
}
// complex % short float
LispObject Remainder::op(Cpx a, SFlt b)
{   abort("not done yet");
}
// short float % short float
LispObject Remainder::op(SFlt a, SFlt b)
{   abort("remainder not coded yet");
}
// single float % short float
LispObject Remainder::op(Flt a, SFlt b)
{   abort("remainder not coded yet");
}
// double float % short float
LispObject Remainder::op(double a, SFlt b)
{   abort("remainder not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float % short float
LispObject Remainder::op(LFlt a, SFlt b)
{   abort("remainder not coded yet");
}
// fixnum % single float
LispObject Remainder::op(Fixnum a, Flt b)
{   abort("not done yet");
}
// bignum % single float
LispObject Remainder::op(uint64_t *a, Flt b)
{   abort("not done yet");
}
// rational % single float
LispObject Remainder::op(Rat a, Flt b)
{   abort("not done yet");
}
// complex % single float
LispObject Remainder::op(Cpx a, Flt b)
{   abort("not done yet");
}
// short float % single float
LispObject Remainder::op(SFlt a, Flt b)
{   abort("not done yet");
}
// single float % single float
LispObject Remainder::op(Flt a, Flt b)
{   abort("remainder not coded yet");
}
// double float % single float
LispObject Remainder::op(double a, Flt b)
{   abort("remainder not coded yet");
//      return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}
// long float % single float
LispObject Remainder::op(LFlt a, Flt b)
{   abort("remainder not coded yet");
}
// fixnum % double float
LispObject Remainder::op(Fixnum a, double b)
{   abort("not done yet");
}
// bignum % double float
LispObject Remainder::op(uint64_t *a, double b)
{   abort("not done yet");
}
// rational % double float
LispObject Remainder::op(Rat a, double b)
{   abort("not done yet");
}
// complex % double float
LispObject Remainder::op(Cpx a, double b)
{   abort("not done yet");
}
// short float % double float
LispObject Remainder::op(SFlt a, double b)
{   abort("not done yet");
}
// single float % double float
LispObject Remainder::op(Flt a, double b)
{   abort("not done yet");
}
// double float % double float
LispObject Remainder::op(double a, double b)
{   return make_boxfloat(std::remainder(a, b));
}
// long float % double float
LispObject Remainder::op(LFlt a, double b)
{   abort("remainder not coded yet");
}
// fixnum % long float
LispObject Remainder::op(Fixnum a, LFlt b)
{   abort("not done yet");
}
// bignum % long float
LispObject Remainder::op(uint64_t *a, LFlt b)
{   abort("not done yet");
}
// rational % long float
LispObject Remainder::op(Rat a, LFlt b)
{   abort("not done yet");
}
// complex % long float
LispObject Remainder::op(Cpx a, LFlt b)
{   abort("not done yet");
}
// short float % long float
LispObject Remainder::op(SFlt a, LFlt b)
{   abort("not done yet");
}
// single float % long float
LispObject Remainder::op(Flt a, LFlt b)
{   abort("not done yet");
}
// double float % long float
LispObject Remainder::op(double a, LFlt b)
{   abort("not done yet");
}
// long float % long float
LispObject Remainder::op(LFlt a, LFlt b)
{   abort("remainder not coded yet");
}

LispObject Divide::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Divide>("divide", a, b);
}

// fixnum divide fixnum
LispObject Divide::op(Fixnum a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// bignum divide fixnum
LispObject Divide::op(uint64_t *a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// rational divide fixnum
LispObject Divide::op(Rat a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// complex divide fixnum
LispObject Divide::op(Cpx a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// short float divide fixnum
LispObject Divide::op(SFlt a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// single float divide fixnum
LispObject Divide::op(Flt a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// double float divide fixnum
LispObject Divide::op(double a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// long float divide fixnum
LispObject Divide::op(LFlt a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// fixnum divide bignum
LispObject Divide::op(Fixnum a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// bignum divide bignum
LispObject Divide::op(uint64_t *a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// rational divide bignum
LispObject Divide::op(Rat a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// complex divide bignum
LispObject Divide::op(Cpx a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// short float divide bignum
LispObject Divide::op(SFlt a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// single float divide bignum
LispObject Divide::op(Flt a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// double float divide bignum
LispObject Divide::op(double a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// long float divide bignum
LispObject Divide::op(LFlt a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// fixnum divide rational
LispObject Divide::op(Fixnum a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// bignum divide rational
LispObject Divide::op(uint64_t *a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// rational divide rational
LispObject Divide::op(Rat a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// complex divide rational
LispObject Divide::op(Cpx a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// short float divide rational
LispObject Divide::op(SFlt a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// single float divide rational
LispObject Divide::op(Flt a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// double float divide rational
LispObject Divide::op(double a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// long float divide rational
LispObject Divide::op(LFlt a, Rat b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// fixnum divide complex
LispObject Divide::op(Fixnum a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// bignum divide complex
LispObject Divide::op(uint64_t *a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// rational divide complex
LispObject Divide::op(Rat a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// complex divide complex
LispObject Divide::op(Cpx a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// short float divide complex
LispObject Divide::op(SFlt a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// single float divide complex
LispObject Divide::op(Flt a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// double float divide complex
LispObject Divide::op(double a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// long float divide complex
LispObject Divide::op(LFlt a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// fixnum divide short float
LispObject Divide::op(Fixnum a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// bignum divide short float
LispObject Divide::op(uint64_t *a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// rational divide short float
LispObject Divide::op(Rat a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// complex divide short float
LispObject Divide::op(Cpx a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// short float divide short float
LispObject Divide::op(SFlt a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// single float divide short float
LispObject Divide::op(Flt a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}
// double float divide short float
LispObject Divide::op(double a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// long float divide short float
LispObject Divide::op(LFlt a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// fixnum divide single float
LispObject Divide::op(Fixnum a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// bignum divide single float
LispObject Divide::op(uint64_t *a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// rational divide single float
LispObject Divide::op(Rat a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// complex divide single float
LispObject Divide::op(Cpx a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// short float divide single float
LispObject Divide::op(SFlt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// single float divide single float
LispObject Divide::op(Flt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// double float divide single float
LispObject Divide::op(double a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// long float divide single float
LispObject Divide::op(LFlt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// fixnum divide double float
LispObject Divide::op(Fixnum a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// bignum divide double float
LispObject Divide::op(uint64_t *a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// rational divide double float
LispObject Divide::op(Rat a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// complex divide double float
LispObject Divide::op(Cpx a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// short float divide double float
LispObject Divide::op(SFlt a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// single float divide double float
LispObject Divide::op(Flt a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// double float divide double float
LispObject Divide::op(double a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// long float divide double float
LispObject Divide::op(LFlt a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// fixnum divide long float
LispObject Divide::op(Fixnum a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// bignum divide long float
LispObject Divide::op(uint64_t *a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// rational divide long float
LispObject Divide::op(Rat a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// complex divide long float
LispObject Divide::op(Cpx a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// short float divide long float
LispObject Divide::op(SFlt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// single float divide long float
LispObject Divide::op(Flt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// double float divide long float
LispObject Divide::op(double a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}
// long float divide long float
LispObject Divide::op(LFlt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Remainder::op(a, b);
    return cons(q, r);
}

LispObject Square::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Square>("square", a);
}

LispObject Square::op(Fixnum a)
{   return arithlib_lowlevel::Square::op(a.intval());
}

LispObject Square::op(uint64_t *a)
{   return arithlib_lowlevel::Square::op(a);
}

LispObject Square::op(Rat a)
{   LispObject p = a.numerator(), q = a.denominator();
    return make_ratio(Square::op(p), Square::op(q));
}

LispObject Square::op(Cpx a)
{   // (x + iy)^2 = x^2 - y^2 + 2*i*x*y
    LispObject x = a.real_part(), y = a.imag_part();
    LispObject vx = Difference::op(Square::op(x), Square::op(y));
    LispObject vy = Times::op(fixnum_of_int(2), Times::op(x, y));
    return make_complex(vx, vy);
}

LispObject Square::op(SFlt a)
{   return pack_short_float(a.floatval()*a.floatval());
}

LispObject Square::op(Flt a)
{   return pack_single_float(a.floatval()*a.floatval());
}

LispObject Square::op(double a)
{   return make_boxfloat(a*a);
}

LispObject Square::op(LFlt a)
{   return make_boxfloat128(f128_mul(a.floatval(), a.floatval()));
}

LispObject Reciprocal::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Reciprocal>("reciprocal", a);
}

LispObject Reciprocal::op(Fixnum a)
{   switch (a.intval())
    {   case 0:  aerror1("bad argument for reciprocal", a.value());
        case 1:  return int_of_fixnum(1);
        case -1: return int_of_fixnum(-1);
        default: return int_of_fixnum(0);
    }
}

LispObject Reciprocal::op(uint64_t *a)
{   return int_of_fixnum(0);
}

LispObject Reciprocal::op(Rat a)
{   LispObject p = a.numerator(), q = a.denominator();
    if (Zerop::op(p)) aerror1("bad argument for reciprocal", a.value());
    else if (Minusp::op(p))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(q, p);
}

LispObject Reciprocal::op(Cpx a)
{   // 1/(x + iy) = (x - iy)/(x^2+y^2)
    LispObject x = a.real_part(), y = a.imag_part();
    LispObject d = Plus::op(Square::op(x), Square::op(y));
    if (Zerop::op(d)) aerror1("bad argument for reciprocal", a.value());
// If the complex value has both components integers I will upgrade
// them to floating point.
    bool promote = false;
    switch (d & XTAG_BITS)
    {   case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            switch (type_of_header(numhdr(d)))
            {   case TYPE_NEW_BIGNUM:
                case TYPE_BIGNUM:
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
    {   x = Float::op(x);
        y = Float::op(y);
        d = Float::op(d);
    }
    return make_complex(Quotient::op(x, d), Quotient::op(y, d));
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

LispObject Reciprocal::op(LFlt a)
{   return make_boxfloat128(f128_div(i64_to_f128(1), a.floatval()));
}

#endif // ARITHLIB

// end of arith-times.cpp
