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

#include <complex>

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
{   int64_t aa = a.intval();
    switch (aa)
    {
    case 0:
        return fixnum_of_int(0);
    case -1:
        if (Oddp::op(b)) return fixnum_of_int(-1);
        // drop through;
    case 1:
        return fixnum_of_int(1);
    default:
        if (arithlib_lowlevel::Minusp::op(b)) return fixnum_of_int(0); 
        aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
    }
}

// bignum ** bignum
LispObject Expt::op(uint64_t *a, uint64_t *b)
{   if (arithlib_lowlevel::Minusp::op(b)) return fixnum_of_int(0);
    aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// rational ** bignum
LispObject Expt::op(Rat a, uint64_t *b)
{   return make_ratio(Expt::op(a.numerator(), b),
                      Expt::op(a.denominator(), b));
}

// complex ** bignum
LispObject Expt::op(Cpx a, uint64_t *b)
{
// I suppose that huge powers of (0+0i), (1+0i), (0+1i), (-1+0i), (0+-1i)
// can give sane results!
    if (Zerop::op(a.real_part()) &&
        Zerop::op(a.imag_part()))
    {   if (Minusp::op(b))
            aerror1("bad argument for expt",
                    (LispObject)(TAG_NUMBERS+(char *)b-8));
        else return a.value();  // (0+0i)^N
    }
    if (Onep::op(a.real_part()) &&
        Zerop::op(a.imag_part())) return a.value();
    if (Zerop::op(a.real_part()) &&
        Onep::op(a.imag_part()))
    {   switch (b[0] & 3)
        {
        case 0: return make_complex(a.imag_part(), a.real_part());
        case 1: return make_complex(a.real_part(), a.imag_part());
        case 2: return make_complex(Minus::op(a.imag_part()), a.real_part());
        case 3: return make_complex(a.real_part(), Minus::op(a.imag_part()));
        }
    }
    if (MinusOnep::op(a.real_part()) &&
        Zerop::op(a.imag_part()))
    {   if (Evenp::op(b)) return make_complex(Minus::op(a.real_part()), a.imag_part());
        else return a.value();
    }
    if (Zerop::op(a.real_part()) &&
        MinusOnep::op(a.imag_part()))
    {   switch (b[0] & 3)
        {
        case 0: return make_complex(Minus::op(a.imag_part()), a.real_part());
        case 1: return make_complex(a.real_part(), a.imag_part());
        case 2: return make_complex(a.imag_part(), a.real_part());
        case 3: return make_complex(a.real_part(), Minus::op(a.imag_part()));
        }
    }
    aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// short float ** bignum
LispObject Expt::op(SFlt a, uint64_t *b)
{   aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// single float ** bignum
LispObject Expt::op(Flt a, uint64_t *b)
{   aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// double float ** bignum
LispObject Expt::op(double a, uint64_t *b)
{   aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// long float ** bignum
LispObject Expt::op(LFlt a, uint64_t *b)
{   aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
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
#pragma message ("bignum ** fractional power needs attention")
LispObject Expt::op(uint64_t *a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// rational ** rational
LispObject Expt::op(Rat a, Rat b)
{   return make_boxfloat(std::pow(RawFloat::op(a), RawFloat::op(b)));
}

// complex ** rational
LispObject Expt::op(Cpx a, Rat b)
{   std::complex<double> aa(RawFloat::op(a.real_part()),
                            RawFloat::op(a.imag_part()));
    std::complex<double> bb(RawFloat::op(b), 0.0);
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
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
LispObject Expt::op(LFlt a, Rat b)
{   return Expt::op(a, LFlt(Float128::op(b)));
}

// fixnum ** complex
LispObject Expt::op(Fixnum a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
}

// bignum ** complex
LispObject Expt::op(uint64_t *a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
}

// rational ** complex
LispObject Expt::op(Rat a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
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
    {   float128_t ax = RawFloat128::op(a.real_part());
        float128_t ay = RawFloat128::op(a.imag_part());
        float128_t bx = RawFloat128::op(b.real_part());
        float128_t by = RawFloat128::op(b.imag_part());
        float128_t rx, ry;
        rx = i64_to_f128(1);
        ry = i64_to_f128(0);
#pragma message ("Should support complex with long-float components")
        return make_complex(make_boxfloat128(rx), make_boxfloat128(ry));
    }
    std::complex<double> aa(RawFloat::op(a.real_part()),
                            RawFloat::op(a.imag_part()));
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
}

// short float ** complex
LispObject Expt::op(SFlt a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
}

// single float ** complex
LispObject Expt::op(Flt a, Cpx b)
{   std::complex<double> aa(RawFloat::op(a), 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
}

// double float ** complex
LispObject Expt::op(double a, Cpx b)
{   std::complex<double> aa(a, 0.0);
    std::complex<double> bb(RawFloat::op(b.real_part()),
                            RawFloat::op(b.imag_part()));
    aa = std::pow(aa, bb);
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
}

// long float ** complex
LispObject Expt::op(LFlt a, Cpx b)
{   return Expt::op(make_complex(a.value(),
                                 make_boxfloat128(i64_to_f128(0))),
                    b);
}

// fixnum ** short float
LispObject Expt::op(Fixnum a, SFlt b)
{   double aa = RawFloat::op(a),
           bb = RawFloat::op(b);
    return make_boxfloat(std::pow(aa, bb));
}

// bignum ** short float
LispObject Expt::op(uint64_t *a, SFlt b)
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
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
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
LispObject Expt::op(LFlt a, SFlt b)
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
LispObject Expt::op(uint64_t *a, Flt b)
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
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
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
LispObject Expt::op(LFlt a, Flt b)
{   return Expt::op(a, LFlt(Float128::op(b)));
}

// fixnum ** double float
LispObject Expt::op(Fixnum a, double b)
{   double aa = RawFloat::op(a),
           bb = b;
    return make_boxfloat(std::pow(aa, bb));
}

// bignum ** double float
LispObject Expt::op(uint64_t *a, double b)
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
    return make_complex(make_boxfloat(aa.real()), make_boxfloat(aa.imag()));
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
LispObject Expt::op(LFlt a, double b)
{   return Expt::op(a, LFlt(Float128::op(b)));
}

// fixnum ** long float
LispObject Expt::op(Fixnum a, LFlt b)
{   return Expt::op(LFlt(Float128::op(a)), b);
}

// bignum ** long float
LispObject Expt::op(uint64_t *a, LFlt b)
{   return Expt::op(LFlt(Float128::op(a)), b);
}

// rational ** long float
LispObject Expt::op(Rat a, LFlt b)
{   return Expt::op(LFlt(Float128::op(a)), b);
}

// complex ** long float
LispObject Expt::op(Cpx a, LFlt b)
{   return Expt::op(a,
                    make_complex(b.value(),
                                 make_boxfloat128(i64_to_f128(0))));
}

// short float ** long float
LispObject Expt::op(SFlt a, LFlt b)
{   return Expt::op(LFlt(Float128::op(a)), b);
}

// single float ** long float
LispObject Expt::op(Flt a, LFlt b)
{   return Expt::op(LFlt(Float128::op(a)), b);
}

// double float ** long float
LispObject Expt::op(double a, LFlt b)
{   return Expt::op(LFlt(Float128::op(a)), b);
}

// long float ** long float

// return f128_exp(f128_mul(b.floatval(), f128_log(a.floatval())))

LispObject Expt::op(LFlt a, LFlt b)
{   abort("not done yet");
//  return f128_exp(f128_mul(b.floatval(), f128_log(a.floatval())))
#pragma message ("exponentiation involving float128_t not available yet")
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
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Quotient::op(b, g)),
                      Quotient::op(a.denominator(), g));
}

// complex / bignum
LispObject Quotient::op(Cpx a, uint64_t *b)
{   return make_complex(Quotient::op(a.real_part(), b),
                        Quotient::op(a.imag_part(), b));
}

// short float / bignum
LispObject Quotient::op(SFlt a, uint64_t *b)
{   int ax;
    int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Quotient::op(Flt a, uint64_t *b)
{   int ax;
    int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Quotient::op(double a, uint64_t *b)
{   int ax;
    int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Quotient::op(LFlt a, uint64_t *b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// fixnum / rational
LispObject Quotient::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Quotient::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Quotient::op(uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Quotient::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Quotient::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = Quotient::op(a.numerator(), g1);
    LispObject nb = Quotient::op(b.denominator(), g2);
    LispObject da = Quotient::op(a.denominator(), g2);
    LispObject db = Quotient::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Quotient::op(Cpx a, Rat b)
{   return make_complex(Quotient::op(a.real_part(), b),
                        Quotient::op(a.imag_part(), b));
}

// short float / rational
LispObject Quotient::op(SFlt a, Rat b)
{   int ax;
    int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Quotient::op(Flt a, Rat b)
{   int ax;
    int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Quotient::op(double a, Rat b)
{   int ax;
    int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Quotient::op(LFlt a, Rat b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// fixnum / complex
LispObject Quotient::op(Fixnum a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// bignum / complex
LispObject Quotient::op(uint64_t *a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// rational / complex
LispObject Quotient::op(Rat a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// complex / complex
LispObject Quotient::op(Cpx a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// short float / complex
LispObject Quotient::op(SFlt a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// single float / complex
LispObject Quotient::op(Flt a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// double float / complex
LispObject Quotient::op(double a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// long float / complex
LispObject Quotient::op(LFlt a, Cpx b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// fixnum / short float
LispObject Quotient::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Quotient::op(uint64_t *a, SFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// rational / short float
LispObject Quotient::op(Rat a, SFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// complex / short float
LispObject Quotient::op(Cpx a, SFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// short float / short float
LispObject Quotient::op(SFlt a, SFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// single float / short float
LispObject Quotient::op(Flt a, SFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// double float / short float
LispObject Quotient::op(double a, SFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// long float / short float
LispObject Quotient::op(LFlt a, SFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// fixnum / single float
LispObject Quotient::op(Fixnum a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// bignum / single float
LispObject Quotient::op(uint64_t *a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// rational / single float
LispObject Quotient::op(Rat a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// complex / single float
LispObject Quotient::op(Cpx a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// short float / single float
LispObject Quotient::op(SFlt a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// single float / single float
LispObject Quotient::op(Flt a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// double float / single float
LispObject Quotient::op(double a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// long float / single float
LispObject Quotient::op(LFlt a, Flt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// fixnum / double float
LispObject Quotient::op(Fixnum a, double b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// bignum / double float
LispObject Quotient::op(uint64_t *a, double b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// rational / double float
LispObject Quotient::op(Rat a, double b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// complex / double float
LispObject Quotient::op(Cpx a, double b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// short float / double float
LispObject Quotient::op(SFlt a, double b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// single float / double float
LispObject Quotient::op(Flt a, double b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// double float / double float
LispObject Quotient::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Quotient::op(LFlt a, double b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// fixnum / long float
LispObject Quotient::op(Fixnum a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// bignum / long float
LispObject Quotient::op(uint64_t *a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// rational / long float
LispObject Quotient::op(Rat a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// complex / long float
LispObject Quotient::op(Cpx a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// short float / long float
LispObject Quotient::op(SFlt a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// single float / long float
LispObject Quotient::op(Flt a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// double float / long float
LispObject Quotient::op(double a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
}

// long float / long float
LispObject Quotient::op(LFlt a, LFlt b)
{   abort("not done yet");
#pragma message ("incomplete code")
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
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % fixnum
LispObject Remainder::op(Cpx a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % fixnum
LispObject Remainder::op(SFlt a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % fixnum
LispObject Remainder::op(Flt a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % fixnum
LispObject Remainder::op(double a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % fixnum
LispObject Remainder::op(LFlt a, Fixnum b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
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
{   return fixnum_of_int(0);
}

// complex % bignum
LispObject Remainder::op(Cpx a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % bignum
LispObject Remainder::op(SFlt a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % bignum
LispObject Remainder::op(Flt a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % bignum
LispObject Remainder::op(double a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % bignum
LispObject Remainder::op(LFlt a, uint64_t *b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % rational
LispObject Remainder::op(Fixnum a, Rat b)
{   return fixnum_of_int(0);
}

// bignum % rational
LispObject Remainder::op(uint64_t *a, Rat b)
{   return fixnum_of_int(0);
}

// rational % rational
LispObject Remainder::op(Rat a, Rat b)
{   return fixnum_of_int(0);
}

// complex % rational
LispObject Remainder::op(Cpx a, Rat b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % rational
LispObject Remainder::op(SFlt a, Rat b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % rational
LispObject Remainder::op(Flt a, Rat b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % rational
LispObject Remainder::op(double a, Rat b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % rational
LispObject Remainder::op(LFlt a, Rat b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % complex
LispObject Remainder::op(Fixnum a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % complex
LispObject Remainder::op(uint64_t *a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % complex
LispObject Remainder::op(Rat a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % complex
LispObject Remainder::op(Cpx a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % complex
LispObject Remainder::op(SFlt a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % complex
LispObject Remainder::op(Flt a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % complex
LispObject Remainder::op(double a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % complex
LispObject Remainder::op(LFlt a, Cpx b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % short float
LispObject Remainder::op(Fixnum a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % short float
LispObject Remainder::op(uint64_t *a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % short float
LispObject Remainder::op(Rat a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % short float
LispObject Remainder::op(Cpx a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % short float
LispObject Remainder::op(SFlt a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % short float
LispObject Remainder::op(Flt a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % short float
LispObject Remainder::op(double a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % short float
LispObject Remainder::op(LFlt a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % single float
LispObject Remainder::op(Fixnum a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % single float
LispObject Remainder::op(uint64_t *a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % single float
LispObject Remainder::op(Rat a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % single float
LispObject Remainder::op(Cpx a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % single float
LispObject Remainder::op(SFlt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % single float
LispObject Remainder::op(Flt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % single float
LispObject Remainder::op(double a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % single float
LispObject Remainder::op(LFlt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % double float
LispObject Remainder::op(Fixnum a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % double float
LispObject Remainder::op(uint64_t *a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % double float
LispObject Remainder::op(Rat a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % double float
LispObject Remainder::op(Cpx a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % double float
LispObject Remainder::op(SFlt a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % double float
LispObject Remainder::op(Flt a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % double float
LispObject Remainder::op(double a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % double float
LispObject Remainder::op(LFlt a, double b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % long float
LispObject Remainder::op(Fixnum a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % long float
LispObject Remainder::op(uint64_t *a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % long float
LispObject Remainder::op(Rat a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % long float
LispObject Remainder::op(Cpx a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % long float
LispObject Remainder::op(SFlt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % long float
LispObject Remainder::op(Flt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % long float
LispObject Remainder::op(double a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % long float
LispObject Remainder::op(LFlt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    return Difference::op(a, Times::op(q, b));
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
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide short float
LispObject Divide::op(LFlt a, SFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide single float
LispObject Divide::op(Fixnum a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide single float
LispObject Divide::op(uint64_t *a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide single float
LispObject Divide::op(Rat a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide single float
LispObject Divide::op(Cpx a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide single float
LispObject Divide::op(SFlt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide single float
LispObject Divide::op(Flt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide single float
LispObject Divide::op(double a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide single float
LispObject Divide::op(LFlt a, Flt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide double float
LispObject Divide::op(Fixnum a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide double float
LispObject Divide::op(uint64_t *a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide double float
LispObject Divide::op(Rat a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide double float
LispObject Divide::op(Cpx a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide double float
LispObject Divide::op(SFlt a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide double float
LispObject Divide::op(Flt a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide double float
LispObject Divide::op(double a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide double float
LispObject Divide::op(LFlt a, double b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide long float
LispObject Divide::op(Fixnum a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide long float
LispObject Divide::op(uint64_t *a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide long float
LispObject Divide::op(Rat a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide long float
LispObject Divide::op(Cpx a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide long float
LispObject Divide::op(SFlt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide long float
LispObject Divide::op(Flt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide long float
LispObject Divide::op(double a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide long float
LispObject Divide::op(LFlt a, LFlt b)
{   LispObject q = Quotient::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
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
