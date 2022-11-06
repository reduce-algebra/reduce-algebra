// arith-float128.cpp                      Copyright (C) 2022-2022 Codemist

// $Id$


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

#ifdef SOFTFLOAT

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


// Just for now I provide horrid placeholders for all the 128-bit float
// elementary functions by conveting back to ordinary double floats and
// calculating the result there. This is MUCH less accurate than would be
// proper, and can fail when the input is outside the range of double.
// I use std::memmove() to avoid strict aliasing undefinedness.
// All of this should be reworked in the long term - with the replacement
// code using the QuadFloat wrapper class around all the float128_t
// values so that coding style can look natural with literals written
// with a _Q suffix.

float128_t sin(float128_t x)
{   Double_union d;
    d.f64 = f128_to_f64(x);
    std::memmove(&d.f, &d.f64, sizeof(double));
    d.f = std::sin(d.f);
    std::memmove(&d.f64, &d.f, sizeof(double));
    return f64_to_f128(d.f64);
}

float128_t cos(float128_t x)
{   Double_union d;
    d.f64 = f128_to_f64(x);
    std::memmove(&d.f, &d.f64, sizeof(double));
    d.f = std::cos(d.f);
    std::memmove(&d.f64, &d.f, sizeof(double));
    return f64_to_f128(d.f64);
}

float128_t exp(float128_t x)
{   Double_union d;
    d.f64 = f128_to_f64(x);
    std::memmove(&d.f, &d.f64, sizeof(double));
    d.f = std::exp(d.f);
    std::memmove(&d.f64, &d.f, sizeof(double));
    return f64_to_f128(d.f64);
}

float128_t log(float128_t x)
{   Double_union d;
    d.f64 = f128_to_f64(x);
    std::memmove(&d.f, &d.f64, sizeof(double));
    d.f = std::log(d.f);
    std::memmove(&d.f64, &d.f, sizeof(double));
    return f64_to_f128(d.f64);
}

float128_t atan2(float128_t y, float128_t x)
{   Double_union d;
    d.f64 = f128_to_f64(x);
    std::memmove(&d.f, &d.f64, sizeof(double));
    d.f = std::atan(d.f);
    std::memmove(&d.f64, &d.f, sizeof(double));
    return f64_to_f128(d.f64);
}

float128_t abs2(float128_t x, float128_t y)
{   QuadFloat a(x);
    QuadFloat b(y);
// In naive terms what I want is sqrt(x*2 + y*2). If either x or y
// is very big squaring could overflow, so I need to svale.
    if (a > 1.0e2000_Q || a < -1.0e2000_Q ||
        b > 1.0e2000_Q || b < -1.0e2000_Q)
    {   QuadFloat scale = 0x2000'000000000000'0000000000000000_QX;
        a /= scale;
        b /= scale;
        QuadFloat r = a*a + b*b;
        return f128_mul(f128_sqrt(r.v), scale.v);
    }
// If both x and y are tiny I also need to scale to avoid premature
// underflow.
    if (a > 1.0e-2000_Q && a < -1.0e-2000_Q &&
        b > 1.0e-2000_Q && b < -1.0e-2000_Q)
    {   QuadFloat scale = 0x2000'000000000000'0000000000000000_QX;
        a *= scale;
        b *= scale;
        QuadFloat r = a*a + b*b;
        return f128_div(f128_sqrt(r.v), scale.v);
    }
    QuadFloat r = a*a + b*b;
    return f128_sqrt(r.v);
}

float128_t sqrt(float128_t x)
{   return f128_sqrt(x);
}

#endif // SOFTFLOAT

// end of arith-float.cpp
