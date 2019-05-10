#ifdef ARITHLIB
// arith-plus.cpp                          Copyright (C) 1990-2019 Codemist

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

#include "headers.h"

#include "softfloat.h"
#define softfloat_h 1

#include "arithlib.hpp"
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
inline LispObject Plus::op(Fixnum a, Fixnum b)
{   return arithlib::Plus::op(a.intvalue(), b.intvalue());
}
// bignum + fixnum
LispObject Plus::op(uint64_t *a, Fixnum b)
{   return arithlib::Plus::op(a, b.intvalue());
}
// rational + fixnum
LispObject Plus::op(Rat a, Fixnum b)
{   if (b.intvalue() == 0) return a.value();
    return make_ratio(Plus::op(a.numerator(),
                               Times::op(a.denominator(), b)),
                      a.denominator());
}
// complex + fixnum
LispObject Plus::op(Cpx a, Fixnum b)
{   if (b.intvalue() == 0) return a.v;
    return make_complex(Plus::op(a.real_part(), b), a.imag_part());
}
// short float + fixnum
LispObject Plus::op(SFlt a, Fixnum b)
{   return pack_short_float(a.floatval() + (double)b.value());
}
// single float + fixnum
LispObject Plus::op(Flt a, Fixnum b)
{   return pack_single_float(a.floatval() + (double)b.intvalue());
}
// double float + fixnum
LispObject Plus::op(double a, Fixnum b)
{   return make_boxfloat(a + (double)b.intvalue(), TYPE_DOUBLE_FLOAT);
}
// long float + fixnum
LispObject Plus::op(LFlt a, Fixnum b)
{   return make_boxfloat128(f128_add(a.floatval(), i64_to_f128(b.intvalue())));
}
//............................................
// fixnum + bignum
LispObject Plus::op(Fixnum a, uint64_t *b)
{   return Plus::op(b, a);
}
// bignum + bignum
LispObject Plus::op(uint64_t *a, uint64_t *b)
{   return arithlib::Plus::op(a, b);
}
// rational + bignum
LispObject Plus::op(Rat a, uint64_t *b)
{   return (LispObject)0; abort("plus not coded yet");
}
// complex + bignum
LispObject Plus::op(Cpx a, uint64_t *b)
{   return (LispObject)0; abort("plus not coded yet");
}
// short float + bignum
LispObject Plus::op(SFlt a, uint64_t *b)
{   return (LispObject)0; abort("plus not coded yet");
}
// single float + bignum
LispObject Plus::op(Flt a, uint64_t *b)
{   return (LispObject)0; abort("plus not coded yet");
}
// double float + bignum
LispObject Plus::op(double a, uint64_t *b)
{   return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + bignum
LispObject Plus::op(LFlt a, uint64_t *b)
{   return (LispObject)0; abort("plus not coded yet");
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
{   return (LispObject)0; abort("plus not coded yet");
}
// complex + rational
LispObject Plus::op(Cpx a, Rat b)
{   return (LispObject)0; abort("plus not coded yet");
}
// short float + rational
LispObject Plus::op(SFlt a, Rat b)
{   return (LispObject)0; abort("plus not coded yet");
}
// single float + rational
LispObject Plus::op(Flt a, Rat b)
{   return (LispObject)0; abort("plus not coded yet");
}
// double float + rational
LispObject Plus::op(double a, Rat b)
{   return (LispObject)0; abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + rational
LispObject Plus::op(LFlt a, Rat b)
{   return (LispObject)0; abort("plus not coded yet");
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
{   return (LispObject)0; abort("plus not coded yet");
}
// short float + complex
LispObject Plus::op(SFlt a, Cpx b)
{   return (LispObject)0; abort("plus not coded yet");
}
// single float + complex
LispObject Plus::op(Flt a, Cpx b)
{   return (LispObject)0; abort("plus not coded yet");
}
// double float + complex
LispObject Plus::op(double a, Cpx b)
{   return (LispObject)0; abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + complex
LispObject Plus::op(LFlt a, Cpx b)
{   return (LispObject)0; abort("plus not coded yet");
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
{   return (LispObject)0; abort("plus not coded yet");
}
// single float + short float
LispObject Plus::op(Flt a, SFlt b)
{   return (LispObject)0; abort("plus not coded yet");
}
// double float + short float
LispObject Plus::op(double a, SFlt b)
{   return (LispObject)0; abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + short float
LispObject Plus::op(LFlt a, SFlt b)
{   return (LispObject)0; abort("plus not coded yet");
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
{   return (LispObject)0; abort("plus not coded yet");
}
// double float + single float
LispObject Plus::op(double a, Flt b)
{   return (LispObject)0; abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + single float
LispObject Plus::op(LFlt a, Flt b)
{   return (LispObject)0; abort("plus not coded yet");
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
{   return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
}
// long float + double float
LispObject Plus::op(LFlt a, double b)
{   return (LispObject)0; abort("plus not coded yet");
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
{   return (LispObject)0; abort("plus not coded yet");
}

// end of arith-plus.cpp

#endif // ARITHLIB
