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

LispObject Times::op(LispObject a, std::uint64_t *b)
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

LispObject Times::op(std::uint64_t *a, LispObject b)
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
LispObject Times::op(std::uint64_t *a, Fixnum b)
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
LispObject Times::op(Fixnum a, std::uint64_t *b)
{   return Times::op(b, a);
}

// bignum * bignum
LispObject Times::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Times::op(a, b);
}

// rational * bignum
LispObject Times::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    LispObject cofactor = Quotient::op(b, g);
    return make_ratio(Times::op(a.numerator(), cofactor),
                      Quotient::op(a.denominator(), g));
}

// complex * bignum
LispObject Times::op(Cpx a, std::uint64_t *b)
{   return make_complex(Times::op(a.real_part(), b),
                        Times::op(a.imag_part(), b));
}

// short float * bignum
LispObject Times::op(SFlt a, std::uint64_t *b)
{   return pack_short_float(a.floatval() * RawFloat::op(b));
}

// single float * bignum
LispObject Times::op(Flt a, std::uint64_t *b)
{   return pack_single_float(a.floatval() * RawFloat::op(b));
}

// double float * bignum
LispObject Times::op(double a, std::uint64_t *b)
{   return make_boxfloat(a * arithlib_lowlevel::Double::op(b));
}

// long float * bignum
LispObject Times::op(LFlt a, std::uint64_t *b)
{   return make_boxfloat128(f128_mul(a.floatval(), RawFloat128::op(b)));
}

// fixnum * rational
LispObject Times::op(Fixnum a, Rat b)
{   return Times::op(b, a);
}

// bignum * rational
LispObject Times::op(std::uint64_t *a, Rat b)
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
LispObject Times::op(LFlt a, Rat b)
{   std::int64_t xb;
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
LispObject Times::op(std::uint64_t *a, Cpx b)
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
LispObject Times::op(std::uint64_t *a, SFlt b)
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
LispObject Times::op(std::uint64_t *a, Flt b)
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
LispObject Times::op(std::uint64_t *a, double b)
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
LispObject Times::op(std::uint64_t *a, LFlt b)
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

LispObject Expt::op(LispObject a, std::uint64_t *b)
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

LispObject Expt::op(std::uint64_t *a, LispObject b)
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
{   return arithlib_lowlevel::Pow::op(a.intval(), (std::int64_t)b.intval());
}

// bignum ** fixnum
LispObject Expt::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Pow::op(a, (std::int64_t)b.intval());
}
template <typename T>
LispObject generic_expt(T a, std::int64_t n)
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
{   std::int64_t n = b.intval();
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
{   std::int64_t n = b.intval();
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
LispObject Expt::op(Fixnum a, std::uint64_t *b)
{   std::int64_t aa = a.intval();
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
LispObject Expt::op(std::uint64_t *a, std::uint64_t *b)
{   if (arithlib_lowlevel::Minusp::op(b)) return fixnum_of_int(0);
    aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// rational ** bignum
LispObject Expt::op(Rat a, std::uint64_t *b)
{   return make_ratio(Expt::op(a.numerator(), b),
                      Expt::op(a.denominator(), b));
}

// complex ** bignum
LispObject Expt::op(Cpx a, std::uint64_t *b)
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
LispObject Expt::op(SFlt a, std::uint64_t *b)
{   aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// single float ** bignum
LispObject Expt::op(Flt a, std::uint64_t *b)
{   aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// double float ** bignum
LispObject Expt::op(double a, std::uint64_t *b)
{   aerror1("bad argument for expt", (LispObject)(TAG_NUMBERS+(char *)b-8));
}

// long float ** bignum
LispObject Expt::op(LFlt a, std::uint64_t *b)
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
LispObject Expt::op(std::uint64_t *a, Rat b)
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
LispObject Expt::op(std::uint64_t *a, Cpx b)
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
#pragma message ("Should support expt complex with long-float components")
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
LispObject Expt::op(std::uint64_t *a, SFlt b)
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
LispObject Expt::op(std::uint64_t *a, Flt b)
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
LispObject Expt::op(std::uint64_t *a, double b)
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
LispObject Expt::op(std::uint64_t *a, LFlt b)
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
{   arithlib_abort("not done yet");
//  return f128_exp(f128_mul(b.floatval(), f128_log(a.floatval())))
#pragma message ("exponentiation involving float128_t not available yet")
}

LispObject Quotient::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Quotient>("quotient", a, b);
}

LispObject Quotient::op(LispObject a, std::uint64_t *b)
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

LispObject Quotient::op(std::uint64_t *a, LispObject b)
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
LispObject Quotient::op(std::uint64_t *a, Fixnum b)
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
LispObject Quotient::op(Fixnum a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// bignum / bignum
LispObject Quotient::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Quotient::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Quotient::op(b, g)),
                      Quotient::op(a.denominator(), g));
}

// complex / bignum
LispObject Quotient::op(Cpx a, std::uint64_t *b)
{   return make_complex(Quotient::op(a.real_part(), b),
                        Quotient::op(a.imag_part(), b));
}

// short float / bignum
LispObject Quotient::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Quotient::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Quotient::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Quotient::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
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
LispObject Quotient::op(std::uint64_t *a, Rat b)
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
LispObject Quotient::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Quotient::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("quotient involving complex incomplete code")
}

// bignum / complex
LispObject Quotient::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject Quotient::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject Quotient::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject Quotient::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject Quotient::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject Quotient::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject Quotient::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject Quotient::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Quotient::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject Quotient::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject Quotient::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
#pragma message ("quitient involving short float incomplete code")
}

// short float / short float
LispObject Quotient::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject Quotient::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject Quotient::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject Quotient::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject Quotient::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject Quotient::op(std::uint64_t *a, Flt b)
{   arithlib_abort("quotient involving single float not done yet");
}

// rational / single float
LispObject Quotient::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject Quotient::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject Quotient::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject Quotient::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject Quotient::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject Quotient::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject Quotient::op(Fixnum a, double b)
{   return make_boxfloat((double)a.intval() / b);
}

// bignum / double float
LispObject Quotient::op(std::uint64_t *a, double b)
{   std::int64_t ax;
    int bx;
    double aa = Frexp::op(a, ax);
    double bb = std::frexp(b, &bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// rational / double float
#pragma message ("quotient involving double float incomplete code")
LispObject Quotient::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Quotient::op(Cpx a, double b)
{   arithlib_abort("not done yet");
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
LispObject Quotient::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject Quotient::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
#pragma message ("quotient involving long float incomplete code")
}

// bignum / long float
LispObject Quotient::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject Quotient::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject Quotient::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject Quotient::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject Quotient::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject Quotient::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject Quotient::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// (quotient 22 7) => 3 and (!/!/ 22 7) => 3
// (/ 22 7) => 22/7

LispObject CLQuotient::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

LispObject CLQuotient::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,CLQuotient>("quotient", a, b);
}

// fixnum / fixnum
LispObject CLQuotient::op(Fixnum a, Fixnum b)
{   std::int64_t aa = a.intval(),
            bb = b.intval(),
// @@ This is WRONG at present!
            gg = arithlib_lowlevel::Gcd::op(aa, bb);
    aa = aa/gg;
    bb = bb/gg;
    if (bb < 0)
    {   aa = -aa;
        bb = -bb;
    }
// Messy cases arise with (/ ? MIN_FIXNUM) and (/ MIN_FIXNUM -?) because
// each of those can leave -MIN_FIXNUM as one of the components of the
// ratio, and that is a bignum not a fixnum.
    return make_ratio(make_lisp_integer64(aa), make_lisp_integer64(bb));
}

// bignum / fixnum
LispObject CLQuotient::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}

// rational / fixnum
LispObject CLQuotient::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    arithlib_abort("not coded yet");
}

// complex / fixnum
LispObject CLQuotient::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(CLQuotient::op(a.real_part(), b), a.imag_part());
}

// short float / fixnum
LispObject CLQuotient::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}

// single float / fixnum
LispObject CLQuotient::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}

// double float / fixnum
LispObject CLQuotient::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}

// long float / fixnum
LispObject CLQuotient::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}

// fixnum / bignum
LispObject CLQuotient::op(Fixnum a, std::uint64_t *b)
{   arithlib_abort("not coded yet");
}

// bignum / bignum
LispObject CLQuotient::op(std::uint64_t *a, std::uint64_t *b)
{   arithlib_abort("not coded yet");
}

// rational / bignum
LispObject CLQuotient::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), CLQuotient::op(b, g)),
                      CLQuotient::op(a.denominator(), g));
}

// complex / bignum
LispObject CLQuotient::op(Cpx a, std::uint64_t *b)
{   return make_complex(CLQuotient::op(a.real_part(), b),
                        CLQuotient::op(a.imag_part(), b));
}

// short float / bignum
LispObject CLQuotient::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject CLQuotient::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject CLQuotient::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject CLQuotient::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject CLQuotient::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(CLQuotient::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject CLQuotient::op(std::uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(CLQuotient::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject CLQuotient::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = CLQuotient::op(a.numerator(), g1);
    LispObject nb = CLQuotient::op(b.denominator(), g2);
    LispObject da = CLQuotient::op(a.denominator(), g2);
    LispObject db = CLQuotient::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject CLQuotient::op(Cpx a, Rat b)
{   return make_complex(CLQuotient::op(a.real_part(), b),
                        CLQuotient::op(a.imag_part(), b));
}

// short float / rational
LispObject CLQuotient::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject CLQuotient::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject CLQuotient::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject CLQuotient::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject CLQuotient::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("CL quotient incomplete code")
}

// bignum / complex
LispObject CLQuotient::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject CLQuotient::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject CLQuotient::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject CLQuotient::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject CLQuotient::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject CLQuotient::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject CLQuotient::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject CLQuotient::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject CLQuotient::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject CLQuotient::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject CLQuotient::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float / short float
LispObject CLQuotient::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject CLQuotient::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject CLQuotient::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject CLQuotient::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject CLQuotient::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject CLQuotient::op(std::uint64_t *a, Flt b)
{   arithlib_abort("not done yet");
}

// rational / single float
LispObject CLQuotient::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject CLQuotient::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject CLQuotient::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject CLQuotient::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject CLQuotient::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject CLQuotient::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject CLQuotient::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum / double float
LispObject CLQuotient::op(std::uint64_t *a, double b)
{   arithlib_abort("not done yet");
}

// rational / double float
LispObject CLQuotient::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject CLQuotient::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float / double float
LispObject CLQuotient::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float / double float
LispObject CLQuotient::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float / double float
LispObject CLQuotient::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject CLQuotient::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject CLQuotient::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
}

// bignum / long float
LispObject CLQuotient::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject CLQuotient::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject CLQuotient::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject CLQuotient::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject CLQuotient::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject CLQuotient::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject CLQuotient::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

LispObject Remainder::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Remainder>("remainder", a, b);
}

LispObject Remainder::op(LispObject a, std::uint64_t *b)
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

LispObject Remainder::op(std::uint64_t *a, LispObject b)
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
LispObject Remainder::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Remainder::op(a, b.intval());
}

// rational remainder fixnum
LispObject Remainder::op(Rat a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % fixnum
LispObject Remainder::op(Cpx a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % fixnum
LispObject Remainder::op(SFlt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % fixnum
LispObject Remainder::op(Flt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % fixnum
LispObject Remainder::op(double a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % fixnum
LispObject Remainder::op(LFlt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % bignum
LispObject Remainder::op(Fixnum a, std::uint64_t *b)
{   return a.value();
}

// bignum % bignum
LispObject Remainder::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Remainder::op(a, b);
}

// rational % bignum
LispObject Remainder::op(Rat a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// complex % bignum
LispObject Remainder::op(Cpx a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % bignum
LispObject Remainder::op(SFlt a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % bignum
LispObject Remainder::op(Flt a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % bignum
LispObject Remainder::op(double a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % bignum
LispObject Remainder::op(LFlt a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % rational
LispObject Remainder::op(Fixnum a, Rat b)
{   return fixnum_of_int(0);
}

// bignum % rational
LispObject Remainder::op(std::uint64_t *a, Rat b)
{   return fixnum_of_int(0);
}

// rational % rational
LispObject Remainder::op(Rat a, Rat b)
{   return fixnum_of_int(0);
}

// complex % rational
LispObject Remainder::op(Cpx a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % rational
LispObject Remainder::op(SFlt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % rational
LispObject Remainder::op(Flt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % rational
LispObject Remainder::op(double a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % rational
LispObject Remainder::op(LFlt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % complex
LispObject Remainder::op(Fixnum a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % complex
LispObject Remainder::op(std::uint64_t *a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % complex
LispObject Remainder::op(Rat a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % complex
LispObject Remainder::op(Cpx a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % complex
LispObject Remainder::op(SFlt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % complex
LispObject Remainder::op(Flt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % complex
LispObject Remainder::op(double a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % complex
LispObject Remainder::op(LFlt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % short float
LispObject Remainder::op(Fixnum a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % short float
LispObject Remainder::op(std::uint64_t *a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % short float
LispObject Remainder::op(Rat a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % short float
LispObject Remainder::op(Cpx a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % short float
LispObject Remainder::op(SFlt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % short float
LispObject Remainder::op(Flt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % short float
LispObject Remainder::op(double a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % short float
LispObject Remainder::op(LFlt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % single float
LispObject Remainder::op(Fixnum a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % single float
LispObject Remainder::op(std::uint64_t *a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % single float
LispObject Remainder::op(Rat a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % single float
LispObject Remainder::op(Cpx a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % single float
LispObject Remainder::op(SFlt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % single float
LispObject Remainder::op(Flt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % single float
LispObject Remainder::op(double a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % single float
LispObject Remainder::op(LFlt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % double float
LispObject Remainder::op(Fixnum a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % double float
LispObject Remainder::op(std::uint64_t *a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % double float
LispObject Remainder::op(Rat a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % double float
LispObject Remainder::op(Cpx a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % double float
LispObject Remainder::op(SFlt a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % double float
LispObject Remainder::op(Flt a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % double float
LispObject Remainder::op(double a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % double float
LispObject Remainder::op(LFlt a, double b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// fixnum % long float
LispObject Remainder::op(Fixnum a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// bignum % long float
LispObject Remainder::op(std::uint64_t *a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// rational % long float
LispObject Remainder::op(Rat a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// complex % long float
LispObject Remainder::op(Cpx a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// short float % long float
LispObject Remainder::op(SFlt a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// single float % long float
LispObject Remainder::op(Flt a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// double float % long float
LispObject Remainder::op(double a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

// long float % long float
LispObject Remainder::op(LFlt a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    return Difference::op(a, Times::op(q, b));
}

LispObject Divide::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Divide>("divide", a, b);
}

LispObject Divide::op(LispObject a, std::uint64_t *b)
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

LispObject Divide::op(std::uint64_t *a, LispObject b)
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
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide fixnum
LispObject Divide::op(std::uint64_t *a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide fixnum
LispObject Divide::op(Rat a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide fixnum
LispObject Divide::op(Cpx a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide fixnum
LispObject Divide::op(SFlt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide fixnum
LispObject Divide::op(Flt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide fixnum
LispObject Divide::op(double a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide fixnum
LispObject Divide::op(LFlt a, Fixnum b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide bignum
LispObject Divide::op(Fixnum a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide bignum
LispObject Divide::op(std::uint64_t *a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide bignum
LispObject Divide::op(Rat a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide bignum
LispObject Divide::op(Cpx a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide bignum
LispObject Divide::op(SFlt a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide bignum
LispObject Divide::op(Flt a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide bignum
LispObject Divide::op(double a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide bignum
LispObject Divide::op(LFlt a, std::uint64_t *b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide rational
LispObject Divide::op(Fixnum a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide rational
LispObject Divide::op(std::uint64_t *a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide rational
LispObject Divide::op(Rat a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide rational
LispObject Divide::op(Cpx a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide rational
LispObject Divide::op(SFlt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide rational
LispObject Divide::op(Flt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide rational
LispObject Divide::op(double a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide rational
LispObject Divide::op(LFlt a, Rat b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide complex
LispObject Divide::op(Fixnum a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide complex
LispObject Divide::op(std::uint64_t *a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide complex
LispObject Divide::op(Rat a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide complex
LispObject Divide::op(Cpx a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide complex
LispObject Divide::op(SFlt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide complex
LispObject Divide::op(Flt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide complex
LispObject Divide::op(double a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide complex
LispObject Divide::op(LFlt a, Cpx b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide short float
LispObject Divide::op(Fixnum a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide short float
LispObject Divide::op(std::uint64_t *a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide short float
LispObject Divide::op(Rat a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide short float
LispObject Divide::op(Cpx a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide short float
LispObject Divide::op(SFlt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide short float
LispObject Divide::op(Flt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide short float
LispObject Divide::op(double a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide short float
LispObject Divide::op(LFlt a, SFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide single float
LispObject Divide::op(Fixnum a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide single float
LispObject Divide::op(std::uint64_t *a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide single float
LispObject Divide::op(Rat a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide single float
LispObject Divide::op(Cpx a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide single float
LispObject Divide::op(SFlt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide single float
LispObject Divide::op(Flt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide single float
LispObject Divide::op(double a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide single float
LispObject Divide::op(LFlt a, Flt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide double float
LispObject Divide::op(Fixnum a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide double float
LispObject Divide::op(std::uint64_t *a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide double float
LispObject Divide::op(Rat a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide double float
LispObject Divide::op(Cpx a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide double float
LispObject Divide::op(SFlt a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide double float
LispObject Divide::op(Flt a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide double float
LispObject Divide::op(double a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide double float
LispObject Divide::op(LFlt a, double b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// fixnum divide long float
LispObject Divide::op(Fixnum a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// bignum divide long float
LispObject Divide::op(std::uint64_t *a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// rational divide long float
LispObject Divide::op(Rat a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// complex divide long float
LispObject Divide::op(Cpx a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// short float divide long float
LispObject Divide::op(SFlt a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// single float divide long float
LispObject Divide::op(Flt a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// double float divide long float
LispObject Divide::op(double a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

// long float divide long float
LispObject Divide::op(LFlt a, LFlt b)
{   LispObject q = Truncate::op(a, b);
    LispObject r = Difference::op(a, Times::op(b, q));
    return cons(q, r);
}

LispObject Square::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Square>("square", a);
}

LispObject Square::op(Fixnum a)
{   return arithlib_lowlevel::Square::op(a.intval());
}

LispObject Square::op(std::uint64_t *a)
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

LispObject Reciprocal::op(std::uint64_t *a)
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

// What follows will be just placeholders

LispObject Truncate::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

LispObject Truncate::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Truncate>("quotient", a, b);
}

// fixnum / fixnum
LispObject Truncate::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a.intval(), b.intval());
}

// bignum / fixnum
LispObject Truncate::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}

// rational / fixnum
LispObject Truncate::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Truncate::op(a.numerator(),
                               Truncate::op(a.denominator(), b)),
                      a.denominator());
}

// complex / fixnum
LispObject Truncate::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Truncate::op(a.real_part(), b), a.imag_part());
}

// short float / fixnum
LispObject Truncate::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}

// single float / fixnum
LispObject Truncate::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}

// double float / fixnum
LispObject Truncate::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}

// long float / fixnum
LispObject Truncate::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}

// fixnum / bignum
LispObject Truncate::op(Fixnum a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// bignum / bignum
LispObject Truncate::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Truncate::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Truncate::op(b, g)),
                      Truncate::op(a.denominator(), g));
}

// complex / bignum
LispObject Truncate::op(Cpx a, std::uint64_t *b)
{   return make_complex(Truncate::op(a.real_part(), b),
                        Truncate::op(a.imag_part(), b));
}

// short float / bignum
LispObject Truncate::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Truncate::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Truncate::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Truncate::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Truncate::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Truncate::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Truncate::op(std::uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Truncate::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Truncate::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = Truncate::op(a.numerator(), g1);
    LispObject nb = Truncate::op(b.denominator(), g2);
    LispObject da = Truncate::op(a.denominator(), g2);
    LispObject db = Truncate::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Truncate::op(Cpx a, Rat b)
{   return make_complex(Truncate::op(a.real_part(), b),
                        Truncate::op(a.imag_part(), b));
}

// short float / rational
LispObject Truncate::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Truncate::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Truncate::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Truncate::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Truncate::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("truncate incomplete code")
}

// bignum / complex
LispObject Truncate::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject Truncate::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject Truncate::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject Truncate::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject Truncate::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject Truncate::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject Truncate::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject Truncate::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Truncate::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject Truncate::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject Truncate::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float / short float
LispObject Truncate::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject Truncate::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject Truncate::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject Truncate::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject Truncate::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject Truncate::op(std::uint64_t *a, Flt b)
{   arithlib_abort("not done yet");
}

// rational / single float
LispObject Truncate::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject Truncate::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject Truncate::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject Truncate::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject Truncate::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject Truncate::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject Truncate::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum / double float
LispObject Truncate::op(std::uint64_t *a, double b)
{   arithlib_abort("not done yet");
}

// rational / double float
LispObject Truncate::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Truncate::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float / double float
LispObject Truncate::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float / double float
LispObject Truncate::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float / double float
LispObject Truncate::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Truncate::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject Truncate::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
}

// bignum / long float
LispObject Truncate::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject Truncate::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject Truncate::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject Truncate::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject Truncate::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject Truncate::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject Truncate::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

LispObject Ceiling::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

LispObject Ceiling::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ceiling>("quotient", a, b);
}

// fixnum / fixnum
LispObject Ceiling::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a.intval(), b.intval());
}

// bignum / fixnum
LispObject Ceiling::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}

// rational / fixnum
LispObject Ceiling::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Ceiling::op(a.numerator(),
                               Ceiling::op(a.denominator(), b)),
                      a.denominator());
}

// complex / fixnum
LispObject Ceiling::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Ceiling::op(a.real_part(), b), a.imag_part());
}

// short float / fixnum
LispObject Ceiling::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}

// single float / fixnum
LispObject Ceiling::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}

// double float / fixnum
LispObject Ceiling::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}

// long float / fixnum
LispObject Ceiling::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}

// fixnum / bignum
LispObject Ceiling::op(Fixnum a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// bignum / bignum
LispObject Ceiling::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Ceiling::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Ceiling::op(b, g)),
                      Ceiling::op(a.denominator(), g));
}

// complex / bignum
LispObject Ceiling::op(Cpx a, std::uint64_t *b)
{   return make_complex(Ceiling::op(a.real_part(), b),
                        Ceiling::op(a.imag_part(), b));
}

// short float / bignum
LispObject Ceiling::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Ceiling::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Ceiling::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Ceiling::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Ceiling::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Ceiling::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Ceiling::op(std::uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Ceiling::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Ceiling::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = Ceiling::op(a.numerator(), g1);
    LispObject nb = Ceiling::op(b.denominator(), g2);
    LispObject da = Ceiling::op(a.denominator(), g2);
    LispObject db = Ceiling::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Ceiling::op(Cpx a, Rat b)
{   return make_complex(Ceiling::op(a.real_part(), b),
                        Ceiling::op(a.imag_part(), b));
}

// short float / rational
LispObject Ceiling::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Ceiling::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Ceiling::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Ceiling::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Ceiling::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("2-arg ceiling incomplete code")
}

// bignum / complex
LispObject Ceiling::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject Ceiling::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject Ceiling::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject Ceiling::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject Ceiling::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject Ceiling::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject Ceiling::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject Ceiling::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Ceiling::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject Ceiling::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject Ceiling::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float / short float
LispObject Ceiling::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject Ceiling::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject Ceiling::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject Ceiling::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject Ceiling::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject Ceiling::op(std::uint64_t *a, Flt b)
{   arithlib_abort("not done yet");
}

// rational / single float
LispObject Ceiling::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject Ceiling::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject Ceiling::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject Ceiling::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject Ceiling::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject Ceiling::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject Ceiling::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum / double float
LispObject Ceiling::op(std::uint64_t *a, double b)
{   arithlib_abort("not done yet");
}

// rational / double float
LispObject Ceiling::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Ceiling::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float / double float
LispObject Ceiling::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float / double float
LispObject Ceiling::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float / double float
LispObject Ceiling::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Ceiling::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject Ceiling::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
}

// bignum / long float
LispObject Ceiling::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject Ceiling::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject Ceiling::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject Ceiling::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject Ceiling::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject Ceiling::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject Ceiling::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}


LispObject Floor::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

LispObject Floor::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Floor>("quotient", a, b);
}

// fixnum / fixnum
LispObject Floor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a.intval(), b.intval());
}

// bignum / fixnum
LispObject Floor::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}

// rational / fixnum
LispObject Floor::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Floor::op(a.numerator(),
                               Floor::op(a.denominator(), b)),
                      a.denominator());
}

// complex / fixnum
LispObject Floor::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Floor::op(a.real_part(), b), a.imag_part());
}

// short float / fixnum
LispObject Floor::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}

// single float / fixnum
LispObject Floor::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}

// double float / fixnum
LispObject Floor::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}

// long float / fixnum
LispObject Floor::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}

// fixnum / bignum
LispObject Floor::op(Fixnum a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// bignum / bignum
LispObject Floor::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Floor::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Floor::op(b, g)),
                      Floor::op(a.denominator(), g));
}

// complex / bignum
LispObject Floor::op(Cpx a, std::uint64_t *b)
{   return make_complex(Floor::op(a.real_part(), b),
                        Floor::op(a.imag_part(), b));
}

// short float / bignum
LispObject Floor::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Floor::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Floor::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Floor::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Floor::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Floor::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Floor::op(std::uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Floor::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Floor::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = Floor::op(a.numerator(), g1);
    LispObject nb = Floor::op(b.denominator(), g2);
    LispObject da = Floor::op(a.denominator(), g2);
    LispObject db = Floor::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Floor::op(Cpx a, Rat b)
{   return make_complex(Floor::op(a.real_part(), b),
                        Floor::op(a.imag_part(), b));
}

// short float / rational
LispObject Floor::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Floor::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Floor::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Floor::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Floor::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("2 arg floor incomplete code")
}

// bignum / complex
LispObject Floor::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject Floor::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject Floor::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject Floor::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject Floor::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject Floor::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject Floor::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject Floor::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Floor::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject Floor::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject Floor::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float / short float
LispObject Floor::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject Floor::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject Floor::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject Floor::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject Floor::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject Floor::op(std::uint64_t *a, Flt b)
{   arithlib_abort("not done yet");
}

// rational / single float
LispObject Floor::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject Floor::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject Floor::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject Floor::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject Floor::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject Floor::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject Floor::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum / double float
LispObject Floor::op(std::uint64_t *a, double b)
{   arithlib_abort("not done yet");
}

// rational / double float
LispObject Floor::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Floor::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float / double float
LispObject Floor::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float / double float
LispObject Floor::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float / double float
LispObject Floor::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Floor::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject Floor::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
}

// bignum / long float
LispObject Floor::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject Floor::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject Floor::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject Floor::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject Floor::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject Floor::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject Floor::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

LispObject Ftruncate::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

LispObject Ftruncate::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ftruncate>("quotient", a, b);
}

// fixnum / fixnum
LispObject Ftruncate::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a.intval(), b.intval());
}

// bignum / fixnum
LispObject Ftruncate::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}

// rational / fixnum
LispObject Ftruncate::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Quotient::op(a.numerator(),
                               Ftruncate::op(a.denominator(), b)),
                      a.denominator());
}

// complex / fixnum
LispObject Ftruncate::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Ftruncate::op(a.real_part(), b), a.imag_part());
}

// short float / fixnum
LispObject Ftruncate::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}

// single float / fixnum
LispObject Ftruncate::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}

// double float / fixnum
LispObject Ftruncate::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}

// long float / fixnum
LispObject Ftruncate::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}

// fixnum / bignum
LispObject Ftruncate::op(Fixnum a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// bignum / bignum
LispObject Ftruncate::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Ftruncate::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Ftruncate::op(b, g)),
                      Ftruncate::op(a.denominator(), g));
}

// complex / bignum
LispObject Ftruncate::op(Cpx a, std::uint64_t *b)
{   return make_complex(Ftruncate::op(a.real_part(), b),
                        Ftruncate::op(a.imag_part(), b));
}

// short float / bignum
LispObject Ftruncate::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Ftruncate::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Ftruncate::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Ftruncate::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Ftruncate::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Ftruncate::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Ftruncate::op(std::uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Ftruncate::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Ftruncate::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = Ftruncate::op(a.numerator(), g1);
    LispObject nb = Ftruncate::op(b.denominator(), g2);
    LispObject da = Ftruncate::op(a.denominator(), g2);
    LispObject db = Ftruncate::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Ftruncate::op(Cpx a, Rat b)
{   return make_complex(Ftruncate::op(a.real_part(), b),
                        Ftruncate::op(a.imag_part(), b));
}

// short float / rational
LispObject Ftruncate::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Ftruncate::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Ftruncate::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Ftruncate::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Ftruncate::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("2 arg ftruncate incomplete code")
}

// bignum / complex
LispObject Ftruncate::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject Ftruncate::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject Ftruncate::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject Ftruncate::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject Ftruncate::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject Ftruncate::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject Ftruncate::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject Ftruncate::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Ftruncate::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject Ftruncate::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject Ftruncate::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float / short float
LispObject Ftruncate::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject Ftruncate::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject Ftruncate::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject Ftruncate::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject Ftruncate::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject Ftruncate::op(std::uint64_t *a, Flt b)
{   arithlib_abort("not done yet");
}

// rational / single float
LispObject Ftruncate::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject Ftruncate::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject Ftruncate::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject Ftruncate::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject Ftruncate::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject Ftruncate::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject Ftruncate::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum / double float
LispObject Ftruncate::op(std::uint64_t *a, double b)
{   arithlib_abort("not done yet");
}

// rational / double float
LispObject Ftruncate::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Ftruncate::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float / double float
LispObject Ftruncate::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float / double float
LispObject Ftruncate::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float / double float
LispObject Ftruncate::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Ftruncate::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject Ftruncate::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
}

// bignum / long float
LispObject Ftruncate::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject Ftruncate::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject Ftruncate::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject Ftruncate::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject Ftruncate::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject Ftruncate::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject Ftruncate::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

LispObject Fceiling::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

LispObject Fceiling::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Fceiling>("quotient", a, b);
}

// fixnum / fixnum
LispObject Fceiling::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a.intval(), b.intval());
}

// bignum / fixnum
LispObject Fceiling::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}

// rational / fixnum
LispObject Fceiling::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Fceiling::op(a.numerator(),
                               Fceiling::op(a.denominator(), b)),
                      a.denominator());
}

// complex / fixnum
LispObject Fceiling::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Fceiling::op(a.real_part(), b), a.imag_part());
}

// short float / fixnum
LispObject Fceiling::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}

// single float / fixnum
LispObject Fceiling::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}

// double float / fixnum
LispObject Fceiling::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}

// long float / fixnum
LispObject Fceiling::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}

// fixnum / bignum
LispObject Fceiling::op(Fixnum a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// bignum / bignum
LispObject Fceiling::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Fceiling::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Fceiling::op(b, g)),
                      Fceiling::op(a.denominator(), g));
}

// complex / bignum
LispObject Fceiling::op(Cpx a, std::uint64_t *b)
{   return make_complex(Fceiling::op(a.real_part(), b),
                        Fceiling::op(a.imag_part(), b));
}

// short float / bignum
LispObject Fceiling::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Fceiling::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Fceiling::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Fceiling::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Fceiling::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Fceiling::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Fceiling::op(std::uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Fceiling::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Fceiling::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = Fceiling::op(a.numerator(), g1);
    LispObject nb = Fceiling::op(b.denominator(), g2);
    LispObject da = Fceiling::op(a.denominator(), g2);
    LispObject db = Fceiling::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Fceiling::op(Cpx a, Rat b)
{   return make_complex(Fceiling::op(a.real_part(), b),
                        Fceiling::op(a.imag_part(), b));
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
LispObject Fceiling::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Fceiling::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("2 arg fceiling incomplete code")
}

// bignum / complex
LispObject Fceiling::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject Fceiling::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject Fceiling::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject Fceiling::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject Fceiling::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject Fceiling::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject Fceiling::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject Fceiling::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Fceiling::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject Fceiling::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject Fceiling::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float / short float
LispObject Fceiling::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject Fceiling::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject Fceiling::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject Fceiling::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject Fceiling::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject Fceiling::op(std::uint64_t *a, Flt b)
{   arithlib_abort("not done yet");
}

// rational / single float
LispObject Fceiling::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject Fceiling::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject Fceiling::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject Fceiling::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject Fceiling::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject Fceiling::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject Fceiling::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum / double float
LispObject Fceiling::op(std::uint64_t *a, double b)
{   arithlib_abort("not done yet");
}

// rational / double float
LispObject Fceiling::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Fceiling::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float / double float
LispObject Fceiling::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float / double float
LispObject Fceiling::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float / double float
LispObject Fceiling::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Fceiling::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject Fceiling::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
}

// bignum / long float
LispObject Fceiling::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject Fceiling::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject Fceiling::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject Fceiling::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject Fceiling::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject Fceiling::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject Fceiling::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

LispObject Ffloor::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, double b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(double a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

LispObject Ffloor::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<LispObject,Ffloor>("quotient", a, b);
}

// fixnum / fixnum
LispObject Ffloor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a.intval(), b.intval());
}

// bignum / fixnum
LispObject Ffloor::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Quotient::op(a, b.intval());
}

// rational / fixnum
LispObject Ffloor::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Ffloor::op(a.numerator(),
                               Ffloor::op(a.denominator(), b)),
                      a.denominator());
}

// complex / fixnum
LispObject Ffloor::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Ffloor::op(a.real_part(), b), a.imag_part());
}

// short float / fixnum
LispObject Ffloor::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() / (double)b.value());
}

// single float / fixnum
LispObject Ffloor::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() / (double)b.intval());
}

// double float / fixnum
LispObject Ffloor::op(double a, Fixnum b)
{   return make_boxfloat(a / (double)b.intval());
}

// long float / fixnum
LispObject Ffloor::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_div(a.floatval(), i64_to_f128(b.intval())));
}

// fixnum / bignum
LispObject Ffloor::op(Fixnum a, std::uint64_t *b)
{   return fixnum_of_int(0);
}

// bignum / bignum
LispObject Ffloor::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Quotient::op(a, b);
}

// rational / bignum
LispObject Ffloor::op(Rat a, std::uint64_t *b)
{   LispObject g = Gcdn::op(a.denominator(), b);
    return make_ratio(Times::op(a.numerator(), Ffloor::op(b, g)),
                      Ffloor::op(a.denominator(), g));
}

// complex / bignum
LispObject Ffloor::op(Cpx a, std::uint64_t *b)
{   return make_complex(Ffloor::op(a.real_part(), b),
                        Ffloor::op(a.imag_part(), b));
}

// short float / bignum
LispObject Ffloor::op(SFlt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / bignum
LispObject Ffloor::op(Flt a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / bignum
LispObject Ffloor::op(double a, std::uint64_t *b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return make_boxfloat(std::ldexp(aa/bb, ax-bx));
}

// long float / bignum
LispObject Ffloor::op(LFlt a, std::uint64_t *b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / rational
LispObject Ffloor::op(Fixnum a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Ffloor::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// bignum / rational
LispObject Ffloor::op(std::uint64_t *a, Rat b)
{   LispObject g = Gcdn::op(a, b.numerator());
    LispObject p = Times::op(Ffloor::op(a, g), b.denominator());
    LispObject q = b.numerator();
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// rational / rational
LispObject Ffloor::op(Rat a, Rat b)
{   LispObject g1 = Gcdn::op(a.numerator(), b.numerator());
    LispObject g2 = Gcdn::op(a.denominator(), b.denominator());
    LispObject na = Ffloor::op(a.numerator(), g1);
    LispObject nb = Ffloor::op(b.denominator(), g2);
    LispObject da = Ffloor::op(a.denominator(), g2);
    LispObject db = Ffloor::op(b.numerator(), g1);
    LispObject p = Times::op(na, nb);
    LispObject q = Times::op(da, db);
    if (Minusp::op(q))
    {   p = Minus::op(p);
        q = Minus::op(q);
    }
    return make_ratio(p, q);
}

// complex / rational
LispObject Ffloor::op(Cpx a, Rat b)
{   return make_complex(Ffloor::op(a.real_part(), b),
                        Ffloor::op(a.imag_part(), b));
}

// short float / rational
LispObject Ffloor::op(SFlt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_short_float(std::ldexp(aa/bb, ax-bx));
}

// single float / rational
LispObject Ffloor::op(Flt a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a.floatval(), &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// double float / rational
LispObject Ffloor::op(double a, Rat b)
{   int ax;
    std::int64_t bx;
    double aa = std::frexp(a, &ax);
    double bb = Frexp::op(b, bx);
    return pack_single_float(std::ldexp(aa/bb, ax-bx));
}

// long float / rational
LispObject Ffloor::op(LFlt a, Rat b)
{   std::int64_t xx;
    float128_t bb = Frexp128::op(b, xx);
    float128_t d = f128_div(a.floatval(), bb);
    f128M_ldexp(&d, -xx);
    return make_boxfloat128(d);
}

// fixnum / complex
LispObject Ffloor::op(Fixnum a, Cpx b)
{   arithlib_abort("not done yet");
#pragma message ("2 arg ffloor incomplete code")
}

// bignum / complex
LispObject Ffloor::op(std::uint64_t *a, Cpx b)
{   arithlib_abort("not done yet");
}

// rational / complex
LispObject Ffloor::op(Rat a, Cpx b)
{   arithlib_abort("not done yet");
}

// complex / complex
LispObject Ffloor::op(Cpx a, Cpx b)
{   arithlib_abort("not done yet");
}

// short float / complex
LispObject Ffloor::op(SFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// single float / complex
LispObject Ffloor::op(Flt a, Cpx b)
{   arithlib_abort("not done yet");
}

// double float / complex
LispObject Ffloor::op(double a, Cpx b)
{   arithlib_abort("not done yet");
}

// long float / complex
LispObject Ffloor::op(LFlt a, Cpx b)
{   arithlib_abort("not done yet");
}

// fixnum / short float
LispObject Ffloor::op(Fixnum a, SFlt b)
{   return pack_single_float((double)a.intval() / b.floatval());
}

// bignum / short float
LispObject Ffloor::op(std::uint64_t *a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}

// rational / short float
LispObject Ffloor::op(Rat a, SFlt b)
{   std::int64_t x;
    double aa = Frexp::op(a, x);
    aa = aa/b.floatval();
    aa = std::ldexp(aa, -x);
    return pack_single_float(aa);
}
// complex / short float
LispObject Ffloor::op(Cpx a, SFlt b)
{   arithlib_abort("not done yet");
}

// short float / short float
LispObject Ffloor::op(SFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// single float / short float
LispObject Ffloor::op(Flt a, SFlt b)
{   arithlib_abort("not done yet");
}

// double float / short float
LispObject Ffloor::op(double a, SFlt b)
{   arithlib_abort("not done yet");
}

// long float / short float
LispObject Ffloor::op(LFlt a, SFlt b)
{   arithlib_abort("not done yet");
}

// fixnum / single float
LispObject Ffloor::op(Fixnum a, Flt b)
{   arithlib_abort("not done yet");
}

// bignum / single float
LispObject Ffloor::op(std::uint64_t *a, Flt b)
{   arithlib_abort("not done yet");
}

// rational / single float
LispObject Ffloor::op(Rat a, Flt b)
{   arithlib_abort("not done yet");
}

// complex / single float
LispObject Ffloor::op(Cpx a, Flt b)
{   arithlib_abort("not done yet");
}

// short float / single float
LispObject Ffloor::op(SFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// single float / single float
LispObject Ffloor::op(Flt a, Flt b)
{   arithlib_abort("not done yet");
}

// double float / single float
LispObject Ffloor::op(double a, Flt b)
{   arithlib_abort("not done yet");
}

// long float / single float
LispObject Ffloor::op(LFlt a, Flt b)
{   arithlib_abort("not done yet");
}

// fixnum / double float
LispObject Ffloor::op(Fixnum a, double b)
{   arithlib_abort("not done yet");
}

// bignum / double float
LispObject Ffloor::op(std::uint64_t *a, double b)
{   arithlib_abort("not done yet");
}

// rational / double float
LispObject Ffloor::op(Rat a, double b)
{   arithlib_abort("not done yet");
}

// complex / double float
LispObject Ffloor::op(Cpx a, double b)
{   arithlib_abort("not done yet");
}

// short float / double float
LispObject Ffloor::op(SFlt a, double b)
{   arithlib_abort("not done yet");
}

// single float / double float
LispObject Ffloor::op(Flt a, double b)
{   arithlib_abort("not done yet");
}

// double float / double float
LispObject Ffloor::op(double a, double b)
{   return make_boxfloat(a / b);
}

// long float / double float
LispObject Ffloor::op(LFlt a, double b)
{   arithlib_abort("not done yet");
}

// fixnum / long float
LispObject Ffloor::op(Fixnum a, LFlt b)
{   arithlib_abort("not done yet");
}

// bignum / long float
LispObject Ffloor::op(std::uint64_t *a, LFlt b)
{   arithlib_abort("not done yet");
}

// rational / long float
LispObject Ffloor::op(Rat a, LFlt b)
{   arithlib_abort("not done yet");
}

// complex / long float
LispObject Ffloor::op(Cpx a, LFlt b)
{   arithlib_abort("not done yet");
}

// short float / long float
LispObject Ffloor::op(SFlt a, LFlt b)
{   arithlib_abort("not done yet");
}

// single float / long float
LispObject Ffloor::op(Flt a, LFlt b)
{   arithlib_abort("not done yet");
}

// double float / long float
LispObject Ffloor::op(double a, LFlt b)
{   arithlib_abort("not done yet");
}

// long float / long float
LispObject Ffloor::op(LFlt a, LFlt b)
{   arithlib_abort("not done yet");
}


#endif // ARITHLIB

// end of arith-times.cpp
