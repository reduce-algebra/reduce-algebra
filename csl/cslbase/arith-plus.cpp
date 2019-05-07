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

using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
using number_dispatcher::Flt;
using number_dispatcher::LFlt;

class Plus
{
public:
// fixnum + fixnum
    static inline LispObject op(intptr_t a, intptr_t b)
    {   return arithlib::Plus::op(a, b);
    }
// bignum + fixnum
    static inline LispObject op(uint64_t *a, intptr_t b)
    {   return arithlib::Plus::op(a, b);
    }
// rational + fixnum
    static inline LispObject op(Rat a, intptr_t b)
    {   abort("plus not coded yet");
    }
// complex + fixnum
    static inline LispObject op(Cpx a, intptr_t b)
    {   abort("plus not coded yet");
    }
// short float + fixnum
    static inline LispObject op(SFlt a, intptr_t b)
    {   abort("plus not coded yet");
    }
// single float + fixnum
    static inline LispObject op(Flt a, intptr_t b)
    {   abort("plus not coded yet");
    }
// double float + fixnum
    static inline LispObject op(double a, intptr_t b)
    {   return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
    }
// long float + fixnum
    static inline LispObject op(LFlt a, intptr_t b)
    {   abort("plus not coded yet");
    }
//............................................
// fixnum + bignum
    static inline LispObject op(intptr_t a, uint64_t *b)
    {   return op(b, a);
    }
// bignum + bignum
    static inline LispObject op(uint64_t *a, uint64_t *b)
    {   return arithlib::Plus::op(a, b);
    }
// rational + bignum
    static inline LispObject op(Rat a, uint64_t *b)
    {   abort("plus not coded yet");
    }
// complex + bignum
    static inline LispObject op(Cpx a, uint64_t *b)
    {   abort("plus not coded yet");
    }
// short float + bignum
    static inline LispObject op(SFlt a, uint64_t *b)
    {   abort("plus not coded yet");
    }
// single float + bignum
    static inline LispObject op(Flt a, uint64_t *b)
    {   abort("plus not coded yet");
    }
// double float + bignum
    static inline LispObject op(double a, uint64_t *b)
    {   return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
    }
// long float + bignum
    static inline LispObject op(LFlt a, uint64_t *b)
    {   abort("plus not coded yet");
    }

//............................................
// fixnum + rational
    static inline LispObject op(intptr_t a, Rat b)
    {   return op(b, a);
    }
// bignum + rational
    static inline LispObject op(uint64_t *a, Rat b)
    {   return op(b, a);
    }
// rational + rational
    static inline LispObject op(Rat a, Rat b)
    {   abort("plus not coded yet");
    }
// complex + rational
    static inline LispObject op(Cpx a, Rat b)
    {   abort("plus not coded yet");
    }
// short float + rational
    static inline LispObject op(SFlt a, Rat b)
    {   abort("plus not coded yet");
    }
// single float + rational
    static inline LispObject op(Flt a, Rat b)
    {   abort("plus not coded yet");
    }
// double float + rational
    static inline LispObject op(double a, Rat b)
    {   abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
    }
// long float + rational
    static inline LispObject op(LFlt a, Rat b)
    {   abort("plus not coded yet");
    }
//............................................
// fixnum + complex
    static inline LispObject op(intptr_t a, Cpx b)
    {   return op(b, a);
    }
// bignum + complex
    static inline LispObject op(uint64_t *a, Cpx b)
    {   return op(b, a);
    }
// rational + complex
    static inline LispObject op(Rat a, Cpx b)
    {   return op(b, a);
    }
// complex + complex
    static inline LispObject op(Cpx a, Cpx b)
    {   abort("plus not coded yet");
    }
// short float + complex
    static inline LispObject op(SFlt a, Cpx b)
    {   abort("plus not coded yet");
    }
// single float + complex
    static inline LispObject op(Flt a, Cpx b)
    {   abort("plus not coded yet");
    }
// double float + complex
    static inline LispObject op(double a, Cpx b)
    {   abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
    }
// long float + complex
    static inline LispObject op(LFlt a, Cpx b)
    {   abort("plus not coded yet");
    }
//............................................
// fixnum + short float
    static inline LispObject op(intptr_t a, SFlt b)
    {   return op(b, a);
    }
// bignum + short float
    static inline LispObject op(uint64_t *a, SFlt b)
    {   return op(b, a);
    }
// rational + short float
    static inline LispObject op(Rat a, SFlt b)
    {   return op(b, a);
    }
// complex + short float
    static inline LispObject op(Cpx a, SFlt b)
    {   return op(b, a);
    }
// short float + short float
    static inline LispObject op(SFlt a, SFlt b)
    {   abort("plus not coded yet");
    }
// single float + short float
    static inline LispObject op(Flt a, SFlt b)
    {   abort("plus not coded yet");
    }
// double float + short float
    static inline LispObject op(double a, SFlt b)
    {   abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
    }
// long float + short float
    static inline LispObject op(LFlt a, SFlt b)
    {   abort("plus not coded yet");
    }
//............................................
// fixnum + single float
    static inline LispObject op(intptr_t a, Flt b)
    {   return op(b, a);
    }
// bignum + single float
    static inline LispObject op(uint64_t *a, Flt b)
    {   return op(b, a);
    }
// rational + single float
    static inline LispObject op(Rat a, Flt b)
    {   return op(b, a);
    }
// complex + single float
    static inline LispObject op(Cpx a, Flt b)
    {   return op(b, a);
    }
// short float + single float
    static inline LispObject op(SFlt a, Flt b)
    {   return op(b, a);
    }
// single float + single float
    static inline LispObject op(Flt a, Flt b)
    {   abort("plus not coded yet");
    }
// double float + single float
    static inline LispObject op(double a, Flt b)
    {   abort("plus not coded yet");
//      return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
    }
// long float + single float
    static inline LispObject op(LFlt a, Flt b)
    {   abort("plus not coded yet");
    }

//............................................
// fixnum + double float
    static inline LispObject op(intptr_t a, double b)
    {   return op(b, a);
    }
// bignum + double float
    static inline LispObject op(uint64_t *a, double b)
    {   return op(b, a);
    }
// rational + double float
    static inline LispObject op(Rat a, double b)
    {   return op(b, a);
    }
// complex + double float
    static inline LispObject op(Cpx a, double b)
    {   return op(b, a);
    }
// short float + double float
    static inline LispObject op(SFlt a, double b)
    {   return op(b, a);
    }
// single float + double float
    static inline LispObject op(Flt a, double b)
    {   return op(b, a);
    }
// double float + double float
    static inline LispObject op(double a, double b)
    {   return make_boxfloat(a + arithlib::Double::op(b), TYPE_DOUBLE_FLOAT);
    }
// long float + double float
    static inline LispObject op(LFlt a, double b)
    {   abort("plus not coded yet");
    }
//............................................
// fixnum + long float
    static inline LispObject op(intptr_t a, LFlt b)
    {   return op(b, a);
    }
// bignum + long float
    static inline LispObject op(uint64_t *a, LFlt b)
    {   return op(b, a);
    }
// rational + long float
    static inline LispObject op(Rat a, LFlt b)
    {   return op(b, a);
    }
// complex + long float
    static inline LispObject op(Cpx a, LFlt b)
    {   return op(b, a);
    }
// short float + long float
    static inline LispObject op(SFlt a, LFlt b)
    {   return op(b, a);
    }
// single float + long float
    static inline LispObject op(Flt a, LFlt b)
    {   return op(b, a);
    }
// double float + long float
    static inline LispObject op(double a, LFlt b)
    {   return op(b, a);
    }
// long float + long float
    static inline LispObject op(LFlt a, LFlt b)
    {   abort("plus not coded yet");
    }

};

LispObject newplus(LispObject a, LispObject b)
{   return number_dispatcher::binary<LispObject,Plus>("plus", a, b);
}

// end of arith-plus.cpp

#endif // ARITHLIB
