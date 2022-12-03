// arith-quad.cpp                         Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

// $Id: arith-quad.cpp 6450 2022-12-01 14:58:05Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

// I will start off with placeholders here that yield the correct types
// but only compure results to double precision accuracy - ie 53-bits.
// Eventually maybe I will work through and replace all these with
// proper 128-bit floating point versions, maybe adopting the Cephes maths
// library code (which is released under the MIT licence). A challenge
// there is that their code is written (very reasonably) using "long double"
// as the name for the 128-bit floating type, but across all platforms
// "long double" is sometimes not supported and is sometimes an 80-bit
// type - all of which is why I use software floating point and a raw
// type float128_t that has to be used via explicit function calls and
// then a type QuadFloat that is slightly nicer to use. And for me
// 128-bit floating point literals need to be written with a "_Q" suffix.
// So I will have some straightforward but mildly time-consuming adaptation
// to do!

float128_t qatan2(float128_t a, float128_t b)
{   QuadFloat aa(a), bb(b);
    return QuadFloat(std::atan2(static_cast<double>(aa),
                                static_cast<double>(bb))).v;
}

float128_t qatan2d(float128_t a, float128_t b)
{   return f128_NaN;
}

float128_t qexpt(float128_t a, float128_t b)
{   return f128_NaN;
}

float128_t qacos(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::acos(static_cast<double>(aa))).v;
}

float128_t qacosd(float128_t a)
{   return f128_NaN;
}

float128_t qacosh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::acosh(static_cast<double>(aa))).v;
}

float128_t qacot(float128_t a)
{   return f128_NaN;
}

float128_t qacotd(float128_t a)
{   return f128_NaN;
}

float128_t qacoth(float128_t a)
{   return f128_NaN;
}

float128_t qacsc(float128_t a)
{   return f128_NaN;
}

float128_t qacscd(float128_t a)
{   return f128_NaN;
}

float128_t qacsch(float128_t a)
{   return f128_NaN;
}

float128_t qasec(float128_t a)
{   return f128_NaN;
}

float128_t qasecd(float128_t a)
{   return f128_NaN;
}

float128_t qasech(float128_t a)
{   return f128_NaN;
}

float128_t qasin(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::asin(static_cast<double>(aa))).v;
}

float128_t qasind(float128_t a)
{   return f128_NaN;
}
 
float128_t qasinh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::asinh(static_cast<double>(aa))).v;
}

float128_t qatan(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::atan(static_cast<double>(aa))).v;
}

float128_t qatand(float128_t a)
{   return f128_NaN;
}

float128_t qatanh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::atanh(static_cast<double>(aa))).v;
}

float128_t qcbrt(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::cbrt(static_cast<double>(aa))).v;
}
  
float128_t qcos(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::cos(static_cast<double>(aa))).v;
}

float128_t qcosd(float128_t a)
{   return f128_NaN;
}
  
float128_t qcosh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::cosh(static_cast<double>(aa))).v;
}

float128_t qcot(float128_t a)
{   return f128_NaN;
}

float128_t qcotd(float128_t a)
{   return f128_NaN;
}

float128_t qcoth(float128_t a)
{   return f128_NaN;
}

float128_t qcsc(float128_t a)
{   return f128_NaN;
}

float128_t qcscd(float128_t a)
{   return f128_NaN;
}

float128_t qcsch(float128_t a)
{   return f128_NaN;
}
  
float128_t qexp(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::exp(static_cast<double>(aa))).v;
}

float128_t qhypot(float128_t x, float128_t y)
{   QuadFloat a(x);
    QuadFloat b(y);
    QuadFloat scale = 1.0_Q;
    QuadFloat r = a*a + b*b;
// If the above calculation overflows or underflows I will repeat
// it but on scaled inputs.
    if (r.isinf())
    {   scale = 1.0e4000_Q;
        a /= scale;
        b /= scale;
        r = a*a + b*b;
    }
    if (r.issubnorm())
    {   scale = 1.0e-4000_Q;
        a /= scale;
        b /= scale;
        r = a*a + b*b;
    }
    return f128_mul(scale.v, qsqrt(r.v));
}

float128_t qln(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::log(static_cast<double>(aa))).v;
}
    
float128_t qlog(float128_t a, float128_t b)
{   return f128_NaN;
}

float128_t qlog10(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::log10(static_cast<double>(aa))).v;
}

float128_t qsec(float128_t a)
{   return f128_NaN;
}

float128_t qsecd(float128_t a)
{   return f128_NaN;
}

float128_t qsech(float128_t a)
{   return f128_NaN;
}
  
float128_t qsin(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::sin(static_cast<double>(aa))).v;
}

float128_t qsind(float128_t a)
{   return f128_NaN;
}
  
float128_t qsinh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::sinh(static_cast<double>(aa))).v;
}

float128_t qsqrt(float128_t a)
{   return f128_sqrt(a);
}

float128_t qtan(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::tan(static_cast<double>(aa))).v;
}

float128_t qtand(float128_t a)
{   return f128_NaN;
}

float128_t qtanh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::tanh(static_cast<double>(aa))).v;
}

float128_t qlog2(float128_t a)
{   return f128_NaN;
}

#endif // ARITHLIB

// end of arith-quad.cpp
