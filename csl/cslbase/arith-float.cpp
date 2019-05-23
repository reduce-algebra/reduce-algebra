// arith-float.cpp                              Copyright (C) 2019 Codemist

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
//@@@ names used are different. Every function here will thus need review!
//@@@ However as a place-holder this is still useful.
//@@@


double Float::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Float>("float", a);
}


double Float::op(Fixnum a)
{   return (double)a.intval();
}


double Float::op(uint64_t *a)
{   return arithlib_lowlevel::Float::op(a);
}

double Float::op(Rat a)
{   return Float::op(a.numerator()) / Float::op(a.denominator());
}

double Float::op(Cpx a)
{   aerror1("bad argument for float", a.value());
}

double Float::op(SFlt a)
{   return a.floatval();
}

double Float::op(Flt a)
{   return a.floatval();
}

double Float::op(double a)
{   return a;
}

double Float::op(LFlt a)
{   float64_t f = f128_to_f64(a.floatval());
// Ha ha - the jolly activity here is a response to the Strict Aliasing Rules
// that (I believe) allow me to feel safe if I move things treating it as
// byte data.
    double d;
    memcpy(&d, &f, sizeof(double));
    return d;
}



float128_t Float128::op(LispObject a)
{   return number_dispatcher::unary<float128_t,Float128>("float128", a);
}


float128_t Float128::op(Fixnum a)
{   return i64_to_f128(a.intval());
}


float128_t Float128::op(uint64_t *a)
{   return arithlib_lowlevel::Float128::op(a);
}

float128_t Float128::op(Rat a)
{   return f128_div(Float128::op(a.numerator()), Float128::op(a.denominator()));
}

float128_t Float128::op(Cpx a)
{   aerror1("bad argument for float128", a.value());
}

float128_t Float128::op(SFlt a)
{   double d = a.floatval();
    float64_t dd;
    return f64_to_f128(dd);
}

float128_t Float128::op(Flt a)
{   double d = a.floatval();
    float64_t dd;
    return f64_to_f128(dd);
}

float128_t Float128::op(double a)
{   double d = a;
    float64_t dd;
    return f64_to_f128(dd);
}

float128_t Float128::op(LFlt a)
{   return a.floatval();
}


// end of arith-float.cpp

