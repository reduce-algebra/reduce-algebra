#ifdef ARITHLIB
// arith-times.cpp                         Copyright (C) 1990-2019 Codemist

// $Id: version.h 4783 2018-09-25 20:26:06Z arthurcnorman $


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

// Times, Quotient, Remainder, Divide

#include "headers.h"

#include "softfloat.h"
#define softfloat_h 1

#include "arithlib.hpp"
#include "dispatch.h"

using number_dispatcher::Fixnum;
// uint64_t *
using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
// double
using number_dispatcher::Flt;
using number_dispatcher::LFlt;

//@@@
//@@@ At present this is basically the code for Plus, edited so that the
//@@@ names used are Times. Every function here will thus need review!
//@@@ However as a place-holder this is still useful.
//@@@


// The main generic addition function is
//       LispObject Times.op(LispObject, LispObject);

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
inline LispObject Times::op(Fixnum a, Fixnum b)
{   return arithlib::Times::op(a.intval(), b.intval());
}
// bignum * fixnum
LispObject Times::op(uint64_t *a, Fixnum b)
{   return arithlib::Times::op(a, b.intval());
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
{   if (b.intval() == 0) return a.v;
    return make_complex(Times::op(a.real_part(), b), a.imag_part());
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
{   return make_boxfloat(a * (double)b.intval(), TYPE_DOUBLE_FLOAT);
}
// long float * fixnum
LispObject Times::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_add(a.floatval(), i64_to_f128(b.intval())));
}
//............................................
// fixnum * bignum
LispObject Times::op(Fixnum a, uint64_t *b)
{   return Times::op(b, a);
}
// bignum * bignum
LispObject Times::op(uint64_t *a, uint64_t *b)
{   return arithlib::Times::op(a, b);
}
// rational * bignum
LispObject Times::op(Rat a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// complex * bignum
LispObject Times::op(Cpx a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * bignum
LispObject Times::op(SFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * bignum
LispObject Times::op(Flt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * bignum
LispObject Times::op(double a, uint64_t *b)
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * bignum
LispObject Times::op(LFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
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
{   return (LispObject)0; abort("times not coded yet");
}
// complex * rational
LispObject Times::op(Cpx a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * rational
LispObject Times::op(SFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * rational
LispObject Times::op(Flt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * rational
LispObject Times::op(double a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * rational
LispObject Times::op(LFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
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
{   return (LispObject)0; abort("times not coded yet");
}
// short float * complex
LispObject Times::op(SFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * complex
LispObject Times::op(Flt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * complex
LispObject Times::op(double a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * complex
LispObject Times::op(LFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
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
{   return (LispObject)0; abort("times not coded yet");
}
// single float * short float
LispObject Times::op(Flt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * short float
LispObject Times::op(double a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * short float
LispObject Times::op(LFlt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
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
{   return (LispObject)0; abort("times not coded yet");
}
// double float * single float
LispObject Times::op(double a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * single float
LispObject Times::op(LFlt a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
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
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * double float
LispObject Times::op(LFlt a, double b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
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
{   return (LispObject)0; abort("times not coded yet");
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

// fixnum * fixnum
inline LispObject Quotient::op(Fixnum a, Fixnum b)
{   return arithlib::Quotient::op(a.intval(), b.intval());
}
// bignum * fixnum
LispObject Quotient::op(uint64_t *a, Fixnum b)
{   return arithlib::Quotient::op(a, b.intval());
}
// rational * fixnum
LispObject Quotient::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Quotient::op(a.numerator(),
                               Quotient::op(a.denominator(), b)),
                      a.denominator());
}
// complex * fixnum
LispObject Quotient::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Quotient::op(a.real_part(), b), a.imag_part());
}
// short float * fixnum
LispObject Quotient::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() * (double)b.value());
}
// single float * fixnum
LispObject Quotient::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() * (double)b.intval());
}
// double float * fixnum
LispObject Quotient::op(double a, Fixnum b)
{   return make_boxfloat(a * (double)b.intval(), TYPE_DOUBLE_FLOAT);
}
// long float * fixnum
LispObject Quotient::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_add(a.floatval(), i64_to_f128(b.intval())));
}
//............................................
// fixnum * bignum
LispObject Quotient::op(Fixnum a, uint64_t *b)
{   return Quotient::op(b, a);
}
// bignum * bignum
LispObject Quotient::op(uint64_t *a, uint64_t *b)
{   return arithlib::Quotient::op(a, b);
}
// rational * bignum
LispObject Quotient::op(Rat a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// complex * bignum
LispObject Quotient::op(Cpx a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * bignum
LispObject Quotient::op(SFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * bignum
LispObject Quotient::op(Flt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * bignum
LispObject Quotient::op(double a, uint64_t *b)
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * bignum
LispObject Quotient::op(LFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
// fixnum * rational
LispObject Quotient::op(Fixnum a, Rat b)
{   return Quotient::op(b, a);
}
// bignum * rational
LispObject Quotient::op(uint64_t *a, Rat b)
{   return Quotient::op(b, a);
}
// rational * rational
LispObject Quotient::op(Rat a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// complex * rational
LispObject Quotient::op(Cpx a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * rational
LispObject Quotient::op(SFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * rational
LispObject Quotient::op(Flt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * rational
LispObject Quotient::op(double a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * rational
LispObject Quotient::op(LFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * complex
LispObject Quotient::op(Fixnum a, Cpx b)
{   return Quotient::op(b, a);
}
// bignum * complex
LispObject Quotient::op(uint64_t *a, Cpx b)
{   return Quotient::op(b, a);
}
// rational * complex
LispObject Quotient::op(Rat a, Cpx b)
{   return Quotient::op(b, a);
}
// complex * complex
LispObject Quotient::op(Cpx a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * complex
LispObject Quotient::op(SFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * complex
LispObject Quotient::op(Flt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * complex
LispObject Quotient::op(double a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * complex
LispObject Quotient::op(LFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * short float
LispObject Quotient::op(Fixnum a, SFlt b)
{   return Quotient::op(b, a);
}
// bignum * short float
LispObject Quotient::op(uint64_t *a, SFlt b)
{   return Quotient::op(b, a);
}
// rational * short float
LispObject Quotient::op(Rat a, SFlt b)
{   return Quotient::op(b, a);
}
// complex * short float
LispObject Quotient::op(Cpx a, SFlt b)
{   return Quotient::op(b, a);
}
// short float * short float
LispObject Quotient::op(SFlt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * short float
LispObject Quotient::op(Flt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * short float
LispObject Quotient::op(double a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * short float
LispObject Quotient::op(LFlt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * single float
LispObject Quotient::op(Fixnum a, Flt b)
{   return Quotient::op(b, a);
}
// bignum * single float
LispObject Quotient::op(uint64_t *a, Flt b)
{   return Quotient::op(b, a);
}
// rational * single float
LispObject Quotient::op(Rat a, Flt b)
{   return Quotient::op(b, a);
}
// complex * single float
LispObject Quotient::op(Cpx a, Flt b)
{   return Quotient::op(b, a);
}
// short float * single float
LispObject Quotient::op(SFlt a, Flt b)
{   return Quotient::op(b, a);
}
// single float * single float
LispObject Quotient::op(Flt a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * single float
LispObject Quotient::op(double a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * single float
LispObject Quotient::op(LFlt a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
// fixnum * double float
LispObject Quotient::op(Fixnum a, double b)
{   return Quotient::op(b, a);
}
// bignum * double float
LispObject Quotient::op(uint64_t *a, double b)
{   return Quotient::op(b, a);
}
// rational * double float
LispObject Quotient::op(Rat a, double b)
{   return Quotient::op(b, a);
}
// complex * double float
LispObject Quotient::op(Cpx a, double b)
{   return Quotient::op(b, a);
}
// short float * double float
LispObject Quotient::op(SFlt a, double b)
{   return Quotient::op(b, a);
}
// single float * double float
LispObject Quotient::op(Flt a, double b)
{   return Quotient::op(b, a);
}
// double float * double float
LispObject Quotient::op(double a, double b)
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * double float
LispObject Quotient::op(LFlt a, double b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * long float
LispObject Quotient::op(Fixnum a, LFlt b)
{   return Quotient::op(b, a);
}
// bignum * long float
LispObject Quotient::op(uint64_t *a, LFlt b)
{   return Quotient::op(b, a);
}
// rational * long float
LispObject Quotient::op(Rat a, LFlt b)
{   return Quotient::op(b, a);
}
// complex * long float
LispObject Quotient::op(Cpx a, LFlt b)
{   return Quotient::op(b, a);
}
// short float * long float
LispObject Quotient::op(SFlt a, LFlt b)
{   return Quotient::op(b, a);
}
// single float * long float
LispObject Quotient::op(Flt a, LFlt b)
{   return Quotient::op(b, a);
}
// double float * long float
LispObject Quotient::op(double a, LFlt b)
{   return Quotient::op(b, a);
}
// long float * long float
LispObject Quotient::op(LFlt a, LFlt b)
{   return (LispObject)0; abort("times not coded yet");
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

// fixnum * fixnum
inline LispObject Remainder::op(Fixnum a, Fixnum b)
{   return arithlib::Remainder::op(a.intval(), b.intval());
}
// bignum * fixnum
LispObject Remainder::op(uint64_t *a, Fixnum b)
{   return arithlib::Remainder::op(a, b.intval());
}
// rational * fixnum
LispObject Remainder::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Remainder::op(a.numerator(),
                               Remainder::op(a.denominator(), b)),
                      a.denominator());
}
// complex * fixnum
LispObject Remainder::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Remainder::op(a.real_part(), b), a.imag_part());
}
// short float * fixnum
LispObject Remainder::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() * (double)b.value());
}
// single float * fixnum
LispObject Remainder::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() * (double)b.intval());
}
// double float * fixnum
LispObject Remainder::op(double a, Fixnum b)
{   return make_boxfloat(a * (double)b.intval(), TYPE_DOUBLE_FLOAT);
}
// long float * fixnum
LispObject Remainder::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_add(a.floatval(), i64_to_f128(b.intval())));
}
//............................................
// fixnum * bignum
LispObject Remainder::op(Fixnum a, uint64_t *b)
{   return Remainder::op(b, a);
}
// bignum * bignum
LispObject Remainder::op(uint64_t *a, uint64_t *b)
{   return arithlib::Remainder::op(a, b);
}
// rational * bignum
LispObject Remainder::op(Rat a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// complex * bignum
LispObject Remainder::op(Cpx a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * bignum
LispObject Remainder::op(SFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * bignum
LispObject Remainder::op(Flt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * bignum
LispObject Remainder::op(double a, uint64_t *b)
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * bignum
LispObject Remainder::op(LFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
// fixnum * rational
LispObject Remainder::op(Fixnum a, Rat b)
{   return Remainder::op(b, a);
}
// bignum * rational
LispObject Remainder::op(uint64_t *a, Rat b)
{   return Remainder::op(b, a);
}
// rational * rational
LispObject Remainder::op(Rat a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// complex * rational
LispObject Remainder::op(Cpx a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * rational
LispObject Remainder::op(SFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * rational
LispObject Remainder::op(Flt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * rational
LispObject Remainder::op(double a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * rational
LispObject Remainder::op(LFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * complex
LispObject Remainder::op(Fixnum a, Cpx b)
{   return Remainder::op(b, a);
}
// bignum * complex
LispObject Remainder::op(uint64_t *a, Cpx b)
{   return Remainder::op(b, a);
}
// rational * complex
LispObject Remainder::op(Rat a, Cpx b)
{   return Remainder::op(b, a);
}
// complex * complex
LispObject Remainder::op(Cpx a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * complex
LispObject Remainder::op(SFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * complex
LispObject Remainder::op(Flt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * complex
LispObject Remainder::op(double a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * complex
LispObject Remainder::op(LFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * short float
LispObject Remainder::op(Fixnum a, SFlt b)
{   return Remainder::op(b, a);
}
// bignum * short float
LispObject Remainder::op(uint64_t *a, SFlt b)
{   return Remainder::op(b, a);
}
// rational * short float
LispObject Remainder::op(Rat a, SFlt b)
{   return Remainder::op(b, a);
}
// complex * short float
LispObject Remainder::op(Cpx a, SFlt b)
{   return Remainder::op(b, a);
}
// short float * short float
LispObject Remainder::op(SFlt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * short float
LispObject Remainder::op(Flt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * short float
LispObject Remainder::op(double a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * short float
LispObject Remainder::op(LFlt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * single float
LispObject Remainder::op(Fixnum a, Flt b)
{   return Remainder::op(b, a);
}
// bignum * single float
LispObject Remainder::op(uint64_t *a, Flt b)
{   return Remainder::op(b, a);
}
// rational * single float
LispObject Remainder::op(Rat a, Flt b)
{   return Remainder::op(b, a);
}
// complex * single float
LispObject Remainder::op(Cpx a, Flt b)
{   return Remainder::op(b, a);
}
// short float * single float
LispObject Remainder::op(SFlt a, Flt b)
{   return Remainder::op(b, a);
}
// single float * single float
LispObject Remainder::op(Flt a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * single float
LispObject Remainder::op(double a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * single float
LispObject Remainder::op(LFlt a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
// fixnum * double float
LispObject Remainder::op(Fixnum a, double b)
{   return Remainder::op(b, a);
}
// bignum * double float
LispObject Remainder::op(uint64_t *a, double b)
{   return Remainder::op(b, a);
}
// rational * double float
LispObject Remainder::op(Rat a, double b)
{   return Remainder::op(b, a);
}
// complex * double float
LispObject Remainder::op(Cpx a, double b)
{   return Remainder::op(b, a);
}
// short float * double float
LispObject Remainder::op(SFlt a, double b)
{   return Remainder::op(b, a);
}
// single float * double float
LispObject Remainder::op(Flt a, double b)
{   return Remainder::op(b, a);
}
// double float * double float
LispObject Remainder::op(double a, double b)
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * double float
LispObject Remainder::op(LFlt a, double b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * long float
LispObject Remainder::op(Fixnum a, LFlt b)
{   return Remainder::op(b, a);
}
// bignum * long float
LispObject Remainder::op(uint64_t *a, LFlt b)
{   return Remainder::op(b, a);
}
// rational * long float
LispObject Remainder::op(Rat a, LFlt b)
{   return Remainder::op(b, a);
}
// complex * long float
LispObject Remainder::op(Cpx a, LFlt b)
{   return Remainder::op(b, a);
}
// short float * long float
LispObject Remainder::op(SFlt a, LFlt b)
{   return Remainder::op(b, a);
}
// single float * long float
LispObject Remainder::op(Flt a, LFlt b)
{   return Remainder::op(b, a);
}
// double float * long float
LispObject Remainder::op(double a, LFlt b)
{   return Remainder::op(b, a);
}
// long float * long float
LispObject Remainder::op(LFlt a, LFlt b)
{   return (LispObject)0; abort("times not coded yet");
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

// fixnum * fixnum
inline LispObject Divide::op(Fixnum a, Fixnum b)
{   return arithlib::Divide::op(a.intval(), b.intval());
}
// bignum * fixnum
LispObject Divide::op(uint64_t *a, Fixnum b)
{   return arithlib::Divide::op(a, b.intval());
}
// rational * fixnum
LispObject Divide::op(Rat a, Fixnum b)
{   if (b.intval() == 0) return a.value();
    return make_ratio(Divide::op(a.numerator(),
                               Divide::op(a.denominator(), b)),
                      a.denominator());
}
// complex * fixnum
LispObject Divide::op(Cpx a, Fixnum b)
{   if (b.intval() == 0) return a.v;
    return make_complex(Divide::op(a.real_part(), b), a.imag_part());
}
// short float * fixnum
LispObject Divide::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() * (double)b.value());
}
// single float * fixnum
LispObject Divide::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() * (double)b.intval());
}
// double float * fixnum
LispObject Divide::op(double a, Fixnum b)
{   return make_boxfloat(a * (double)b.intval(), TYPE_DOUBLE_FLOAT);
}
// long float * fixnum
LispObject Divide::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_add(a.floatval(), i64_to_f128(b.intval())));
}
//............................................
// fixnum * bignum
LispObject Divide::op(Fixnum a, uint64_t *b)
{   return Divide::op(b, a);
}
// bignum * bignum
LispObject Divide::op(uint64_t *a, uint64_t *b)
{   return arithlib::Divide::op(a, b);
}
// rational * bignum
LispObject Divide::op(Rat a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// complex * bignum
LispObject Divide::op(Cpx a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * bignum
LispObject Divide::op(SFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * bignum
LispObject Divide::op(Flt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * bignum
LispObject Divide::op(double a, uint64_t *b)
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * bignum
LispObject Divide::op(LFlt a, uint64_t *b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
// fixnum * rational
LispObject Divide::op(Fixnum a, Rat b)
{   return Divide::op(b, a);
}
// bignum * rational
LispObject Divide::op(uint64_t *a, Rat b)
{   return Divide::op(b, a);
}
// rational * rational
LispObject Divide::op(Rat a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// complex * rational
LispObject Divide::op(Cpx a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * rational
LispObject Divide::op(SFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * rational
LispObject Divide::op(Flt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * rational
LispObject Divide::op(double a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * rational
LispObject Divide::op(LFlt a, Rat b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * complex
LispObject Divide::op(Fixnum a, Cpx b)
{   return Divide::op(b, a);
}
// bignum * complex
LispObject Divide::op(uint64_t *a, Cpx b)
{   return Divide::op(b, a);
}
// rational * complex
LispObject Divide::op(Rat a, Cpx b)
{   return Divide::op(b, a);
}
// complex * complex
LispObject Divide::op(Cpx a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// short float * complex
LispObject Divide::op(SFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * complex
LispObject Divide::op(Flt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * complex
LispObject Divide::op(double a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * complex
LispObject Divide::op(LFlt a, Cpx b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * short float
LispObject Divide::op(Fixnum a, SFlt b)
{   return Divide::op(b, a);
}
// bignum * short float
LispObject Divide::op(uint64_t *a, SFlt b)
{   return Divide::op(b, a);
}
// rational * short float
LispObject Divide::op(Rat a, SFlt b)
{   return Divide::op(b, a);
}
// complex * short float
LispObject Divide::op(Cpx a, SFlt b)
{   return Divide::op(b, a);
}
// short float * short float
LispObject Divide::op(SFlt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
// single float * short float
LispObject Divide::op(Flt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * short float
LispObject Divide::op(double a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * short float
LispObject Divide::op(LFlt a, SFlt b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * single float
LispObject Divide::op(Fixnum a, Flt b)
{   return Divide::op(b, a);
}
// bignum * single float
LispObject Divide::op(uint64_t *a, Flt b)
{   return Divide::op(b, a);
}
// rational * single float
LispObject Divide::op(Rat a, Flt b)
{   return Divide::op(b, a);
}
// complex * single float
LispObject Divide::op(Cpx a, Flt b)
{   return Divide::op(b, a);
}
// short float * single float
LispObject Divide::op(SFlt a, Flt b)
{   return Divide::op(b, a);
}
// single float * single float
LispObject Divide::op(Flt a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
}
// double float * single float
LispObject Divide::op(double a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
//      return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * single float
LispObject Divide::op(LFlt a, Flt b)
{   return (LispObject)0; abort("times not coded yet");
}

//............................................
// fixnum * double float
LispObject Divide::op(Fixnum a, double b)
{   return Divide::op(b, a);
}
// bignum * double float
LispObject Divide::op(uint64_t *a, double b)
{   return Divide::op(b, a);
}
// rational * double float
LispObject Divide::op(Rat a, double b)
{   return Divide::op(b, a);
}
// complex * double float
LispObject Divide::op(Cpx a, double b)
{   return Divide::op(b, a);
}
// short float * double float
LispObject Divide::op(SFlt a, double b)
{   return Divide::op(b, a);
}
// single float * double float
LispObject Divide::op(Flt a, double b)
{   return Divide::op(b, a);
}
// double float * double float
LispObject Divide::op(double a, double b)
{   return make_boxfloat(a * arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float * double float
LispObject Divide::op(LFlt a, double b)
{   return (LispObject)0; abort("times not coded yet");
}
//............................................
// fixnum * long float
LispObject Divide::op(Fixnum a, LFlt b)
{   return Divide::op(b, a);
}
// bignum * long float
LispObject Divide::op(uint64_t *a, LFlt b)
{   return Divide::op(b, a);
}
// rational * long float
LispObject Divide::op(Rat a, LFlt b)
{   return Divide::op(b, a);
}
// complex * long float
LispObject Divide::op(Cpx a, LFlt b)
{   return Divide::op(b, a);
}
// short float * long float
LispObject Divide::op(SFlt a, LFlt b)
{   return Divide::op(b, a);
}
// single float * long float
LispObject Divide::op(Flt a, LFlt b)
{   return Divide::op(b, a);
}
// double float * long float
LispObject Divide::op(double a, LFlt b)
{   return Divide::op(b, a);
}
// long float * long float
LispObject Divide::op(LFlt a, LFlt b)
{   return (LispObject)0; abort("times not coded yet");
}

// end of arith-times.cpp

#endif // ARITHLIB
