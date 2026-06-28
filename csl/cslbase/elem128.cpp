//@@@@@@@@@@@@@@@@@
// (1) check principle value, notably acot() on complex args.
// (2) remaining inverse functions for FLOAT160 and COMPLEX160
// (3) fma for soft float128/160
// (4) atan2 ought to be clever wrt signed zeros! Ie
//     atan2(+-0, +-0) => -pi, 0 or pi depending on the signs.
// (5) FLOAT128 functions to return a NaN if arguments out of range.


// elem128.cpp                                  Copyright (C) 2026 Codemist

// $Id: elem128.cpp 7327 2026-03-07 17:06:01Z arthurcnorman $


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


#ifdef TEST
#include "float128.h"
#else
#include "headers.h"
#endif

// Here are the scenarios I support:
//  USE_LONG_DOUBLE     long double conforms to 128-bit IEEE, so std::sin.
//  USE_QUADMATH        __float128 is a suitable type, and functions sinq etc
//  USE_CLANG_FLOAT128  __float128, together with sinf128 but no complex fns
//  USE_CXX23_FLOAT128  std::float128_t for arithmetic but no library provided
//  USE_SOFT_FLOAT128   must do everything myself.
// and in general one of those symbols should be defined. If none are then I
// default to USE_SOFT_FLOAT128

// I will set up the following symbols to guard the code I include:
//   NEED_FLOAT160         I implement my own working precision.
//   NEED_FLOAT128         Implement 128-bit floats and complex.
//   NEED_REAL_MATHLIB     sin, cos etc on FLOAT128.
//   NEED_COMPLEX_MATHLIB  sin, cos etc on COMPLEX128.

// Within this file I have FLOAT128 and COMPLEX128 with basic arithmetic.
// If I have USE_LONG_DOUBLE I can delegate both real and complex cases
// to std::sin() etc.
// If I have USE_QUADMATH I can delegate to sinq() etc.
// If I have USE_CLANG_FLOAT128 I delegate to sinf128()
// For USE_CXX23_FLOAT128 and USE_SORT_FLOAT128 I have to implement things
// for myself.

// If I have a C++ simple array the following macro tells me how
// many items are stored in it.

#define lengthOf(v) (sizeof(v)/sizeof(v[0]))

#ifdef USE_LONG_DOUBLE

#define delegate128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base((long double)x); }

#define delegate128deg(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)todegrees(base((long double)x)); }

#define delegatedeg128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base(toradians((long double)x)); }

#define delegate128recip(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)(1.0L/(base((long double)x))); }

#define delegaterecip128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base(1.0L/(long double)x); }

long double todegrees(long double x)
{   return 57.29577951308232087679815481410517033241L*x;
}
 
int powermod360(int a, int n)
{   int r = 1;
    while (n != 0)
    {   if (n%2 != 0) r = (r * a)%360;
        a = (a * a)%360;
        n = n/2;
    }
    return r;
}

long double toradians(long double a)
{   if (a < 0.0L) return -toradians(-a);
    if (a < 180.0L) 
        return 0.01745329251994329576923690768488612713443L*a;
    int x;
    long double b = std::frexp(a, &x);
// Any floating point number that is at least 2^113 (and hence where its
// exponent as recovered by frexp is at least 114) denotes an integer.
    if (x >= 114)
    {   b = std::ldexp(b, 113);
        uint128_t ii = (uint128_t)b;
        ii = (ii%360 + powermod360(2, x-113))%360;
        a = (long double)ii;
        if (a > 180.0) a = a - 180.0; 
        return 0.01745329251994329576923690768488612713443L*a;
    }
// Here a is small enough that I can take its integer part as uint128_t.
    uint128_t ii = (uint128_t)a;
    ii = 360*(ii/360);           // make it a multiple of 360
    a = a - (long double)ii;
    if (a > 180.0L) a = a - 180.0L; 
    return 0.01745329251994329576923690768488612713443L*a;
}

FLOAT128 acot(FLOAT128 x)
{   if ((long double)x < 0.0)
        return (FLOAT128)(3.14159265358979323846264338327950288419717L -
                          std::atan(-1.0L/(long double)x));
    else return (FLOAT128)std::atan(1.0L/(long double)x);
}

delegate128(acos, std::acos)
delegate128deg(acosd, std::acos)
delegate128(acosh, std::acosh)
delegate128deg(acotd, acot)
delegaterecip128(acoth, std::atanh)
delegaterecip128(acsc, std::asin)
delegate128deg(acscd, acsc)
delegaterecip128(acsch, std::asinh)
delegaterecip128(asec, std::acos)
delegate128deg(asecd, asec)
delegaterecip128(asech, std::acosh)
delegate128(asin, std::asin)
delegate128deg(asind, asin) 
delegate128(asinh, std::asinh)
delegate128(atan, std::atan)
delegate128deg(atand, atan)
delegate128(atanh, std::atanh)
delegate128(cbrt, std::cbrt)
delegate128(cos, std::cos)
delegatedeg128(cosd, cos)
delegate128(cosh, std::cosh)
delegate128recip(cot, std::tan)
delegatedeg128(cotd, cot)
delegate128recip(coth, std::tanh)
delegate128recip(csc, std::sin)
delegatedeg128(cscd, csc)
delegate128recip(csch, std::sinh)
delegate128(exp, std::exp)
delegate128(expm1, std::expm1)
delegate128(ln, std::log)
delegate128(log, std::log)
delegate128(log10, std::log10)
delegate128(log1p, std::log1p)
delegate128(log2, std::log2);
delegate128recip(sec, std::cos)
delegatedeg128(secd, sec)
delegate128recip(sech, std::cosh)
delegate128(sin, std::sin)
delegatedeg128(sind, sin)
delegate128(sinh, std::sinh)
delegate128(sqrt, std::sqrt)
delegate128recip(rsqrt, sqrt)
delegate128(tan, std::tan);
delegatedeg128(tand, tan)
delegate128(tanh, std::tanh)

#define delegatebinary128(fn, base) \
FLOAT128 fn(FLOAT128 x, FLOAT128 y) \
{ return (FLOAT128)base((long double)x, (long double)y); }

#define delegatebinary128deg(fn, base) \
FLOAT128 fn(FLOAT128 x, FLOAT128 y)    \
{ return (FLOAT128)todegrees(base((long double)x, (long double)y)); }

// atan2() returns a value on the range -pi to +pi
// If x and y are both zero it has defined values in the C++ standard,
// but right now I have not get those supported.

FLOAT128 atan2(FLOAT128 y, FLOAT128 x)
{   if (!signbit(x))
    {   if (!signbit(y))
        {   return atan(y/x);
        }
        else
        {   return -atan(-y/x);
        }
    }
    else
    {   if (!signbit(y))
        {   return LF_C(3.14159265358979323846264338327950288419717) -
                   atan(-y/x);
        }
        else
        {   return -LF_C(3.14159265358979323846264338327950288419717) +
                   atan(y/x);
        }
    }
}

delegatebinary128deg(atan2d, atan2)
delegatebinary128(expt,      std::pow)
delegatebinary128(hypot,     std::hypot)


// frexp, ldexp, modf, exp2, ilogb, logb, scalbn, erf. erfc, tgamma, lgamma,
// ceil, floor, fmod, trunc, round, lround, rint, lrint, bearbyint, remainder,
// remquo, copysign, nextafter, nexttoward, fdim, fmax, fmin, abs, mfa,

#undef delegate128
#undef delegate128deg
#undef delegatedeg128
#undef delegate128recip
#undef delegaterecip128

#endif // USE_LONG_DOUBLE

#ifdef USE_QUADMATH

#define delegate128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base((__float128)x); }

#define delegate128deg(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)todegrees(base((__float128)x)); }

#define delegatedeg128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base(toradians((__float128)x)); }

#define delegate128recip(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)(1.0Q/(base((__float128)x))); }

#define delegaterecip128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base(1.0Q/(__float128)x); }

__float128 todegrees(__float128 x)
{   return 57.29577951308232087679815481410517033241Q*x;
}
 
int powermod360(int a, int n)
{   int r = 1;
    while (n != 0)
    {   if (n%2 != 0) r = (r * a)%360;
        a = (a * a)%360;
        n = n/2;
    }
    return r;
}

__float128 toradians(__float128 a)
{   if (a < 0.0Q) return -toradians(-a);
    if (a < 180.0Q) 
        return 0.01745329251994329576923690768488612713443Q*a;
    int x;
    __float128 b = frexpq(a, &x);
// Any floating point number that is at least 2^113 (and hence where its
// exponent as recovered by frexp is at least 114) denotes an integer.
    if (x >= 114)
    {   b = ldexpq(b, 113);
        uint128_t ii = (uint128_t)b;
        ii = (ii%360 + powermod360(2, x-113))%360;
        a = (__float128)ii;
        if (a > 180.0Q) a = a - 180.0Q; 
        return 0.01745329251994329576923690768488612713443Q*a;
    }
// Here a is small enough that I can take its integer part as uint128_t.
    uint128_t ii = (uint128_t)a;
    ii = 360*(ii/360);           // make it a multiple of 360
    a = a - (__float128)ii;
    if (a > 180.0Q) a = a - 180.0Q; 
    return 0.01745329251994329576923690768488612713443Q*a;
}
 
FLOAT128 acot(FLOAT128 x)
{   if (x < LF_C(0.0))
        return LF_C(3.14159265358979323846264338327950288419717) -
               (FLOAT128)atanq((__float128)(-LF_C(1.0)/x));
    else return (FLOAT128)atanq((__float128)(LF_C(1.0)/x));
}

delegate128(acos, acosq)
delegate128deg(acosd, acosq)
delegate128(acosh, acoshq)
delegate128deg(acotd, acot)
delegaterecip128(acoth, atanhq)
delegaterecip128(acsc, asinq)
delegate128deg(acscd, acsc)
delegaterecip128(acsch, asinhq)
delegaterecip128(asec, acosq)
delegate128deg(asecd, asec)
delegaterecip128(asech, acoshq)
delegate128(asin, asinq)
delegate128deg(asind, asin) 
delegate128(asinh, asinhq)
delegate128(atan, atanq)
delegate128deg(atand, atan)
delegate128(atanh, atanhq)
delegate128(cbrt, cbrtq)
delegate128(cos, cosq)
delegatedeg128(cosd, cos)
delegate128(cosh, coshq)
delegate128recip(cot, tanq)
delegatedeg128(cotd, cot)
delegate128recip(coth, tanhq)
delegate128recip(csc, sinq)
delegatedeg128(cscd, csc)
delegate128recip(csch, sinhq)
delegate128(exp, expq)
delegate128(expm1, expm1q)
delegate128(ln, logq)
delegate128(log, logq)
delegate128(log10, log10q)
delegate128(log1p, log1pq)
delegate128(log2, log2q);
delegate128recip(sec, cosq)
delegatedeg128(secd, sec)
delegate128recip(sech, coshq)
delegate128(sin, sinq);
delegatedeg128(sind, sin)
delegate128(sinh, sinhq)
delegate128(sqrt, sqrtq)
delegate128recip(rsqrt, sqrt)
delegate128(tan, tanq);
delegatedeg128(tand, tan)
delegate128(tanh, tanhq)

#define delegatebinary128(fn, base) \
FLOAT128 fn(FLOAT128 x, FLOAT128 y) \
{ return (FLOAT128)base((__float128)x, (__float128)y); }

#define delegatebinary128deg(fn, base) \
FLOAT128 fn(FLOAT128 x, FLOAT128 y)    \
{ return (FLOAT128)todegrees(base((__float128)x, (__float128)y)); }

delegatebinary128(atan2,     atan2q)
delegatebinary128deg(atan2d, atan2q)
delegatebinary128(expt,      powq)
delegatebinary128(hypot,     hypotq)

// frexp, ldexp, modf, exp2, ilogb, logb, scalbn, erf. erfc, tgamma, lgamma,
// ceil, floor, fmod, trunc, round, lround, rint, lrint, bearbyint, remainder,
// remquo, copysign, nextafter, nexttoward, fdim, fmax, fmin, abs, mfa,

#undef delegate128
#undef delegate128deg
#undef delegatedeg128
#undef delegate128recip
#undef delegaterecip128

#endif // USE_QUADMATH

#ifdef USE_CLANG_FLOAT128

#define delegate128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base((__float128)x); }

#define delegate128deg(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)todegrees(base((__float128)x)); }

#define delegatedeg128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base(toradians((__float128)x)); }

#define delegate128recip(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)(1.0Q/(base((__float128)x))); }

#define delegaterecip128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base(1.0Q/(__float128)x); }

__float128 todegrees(__float128 x)
{   return 57.29577951308232087679815481410517033241Q*x;
}
 
int powermod360(int a, int n)
{   int r = 1;
    while (n != 0)
    {   if (n%2 != 0) r = (r * a)%360;
        a = (a * a)%360;
        n = n/2;
    }
    return r;
}

__float128 toradians(__float128 a)
{   if (a < 0.0Q) return -toradians(-a);
    if (a < 180.0Q) 
        return 0.01745329251994329576923690768488612713443Q*a;
    int x;
    __float128 b = frexpf128(a, &x);
// Any floating point number that is at least 2^113 (and hence where its
// exponent as recovered by frexp is at least 114) denotes an integer.
    if (x >= 114)
    {   b = ldexpf128(b, 113);
        uint128_t ii = (uint128_t)b;
        ii = (ii%360 + powermod360(2, x-113))%360;
        a = (__float128)ii;
        if (a > 180.0Q) a = a - 180.0Q; 
        return 0.01745329251994329576923690768488612713443Q*a;
    }
// Here a is small enough that I can take its integer part as uint128_t.
    uint128_t ii = (uint128_t)a;
    ii = 360*(ii/360);           // make it a multiple of 360
    a = a - (__float128)ii;
    if (a > 180.0Q) a = a - 180.0Q; 
    return 0.01745329251994329576923690768488612713443Q*a;
}
 
FLOAT128 acot(FLOAT128 x)
{   if (x < LF_C(0.0))
        return LF_C(3.14159265358979323846264338327950288419717) -
               (FLOAT128)atanf128((__float128)(-LF_C(1.0)/x));
    else return (FLOAT128)atanf128((__float128)(LF_C(1.0)/x));
}

delegate128(acos, acosf128)
delegate128deg(acosd, acosf128)
delegate128(acosh, acoshf128)
delegate128deg(acotd, acot)
delegaterecip128(acoth, atanhf128)
delegaterecip128(acsc, asinf128)
delegate128deg(acscd, acsc)
delegaterecip128(acsch, asinhf128)
delegaterecip128(asec, acosf128)
delegate128deg(asecd, asec)
delegaterecip128(asech, acoshf128)
delegate128(asin, asinf128)
delegate128deg(asind, asin) 
delegate128(asinh, asinhf128)
delegate128(atan, atanf128)
delegate128deg(atand, atan)
delegate128(atanh, atanhf128)
delegate128(cbrt, cbrtf128)
delegate128(cos, cosf128)
delegatedeg128(cosd, cos)
delegate128(cosh, coshf128)
delegate128recip(cot, tanf128)
delegatedeg128(cotd, cot)
delegate128recip(coth, tanhf128)
delegate128recip(csc, sinf128)
delegatedeg128(cscd, csc)
delegate128recip(csch, sinhf128)
delegate128(exp, expf128)
delegate128(expm1, expm1f128)
delegate128(ln, logf128)
delegate128(log, logf128)
delegate128(log10, log10f128)
delegate128(log1p, log1pf128)
delegate128(log2, log2f128);
delegate128recip(sec, cosf128)
delegatedeg128(secd, sec)
delegate128recip(sech, coshf128)
delegate128(sin, sinf128);
delegatedeg128(sind, sin)
delegate128(sinh, sinhf128)
delegate128(sqrt, sqrtf128)
delegate128recip(rsqrt, sqrt)
delegate128(tan, tanf128);
delegatedeg128(tand, tan)
delegate128(tanh, tanhf128)

#define delegatebinary128(fn, base) \
FLOAT128 fn(FLOAT128 x, FLOAT128 y) \
{ return (FLOAT128)base((__float128)x, (__float128)y); }

#define delegatebinary128deg(fn, base) \
FLOAT128 fn(FLOAT128 x, FLOAT128 y)    \
{ return (FLOAT128)todegrees(base((__float128)x, (__float128)y)); }

delegatebinary128(atan2,     atan2f128)
delegatebinary128deg(atan2d, atan2f128)
delegatebinary128(expt,      powf128)
delegatebinary128(hypot,     hypotf128)

// frexp, ldexp, modf, exp2, ilogb, logb, scalbn, erf. erfc, tgamma, lgamma,
// ceil, floor, fmod, trunc, round, lround, rint, lrint, bearbyint, remainder,
// remquo, copysign, nextafter, nexttoward, fdim, fmax, fmin, abs, mfa,

#undef delegate128
#undef delegate128deg
#undef delegatedeg128
#undef delegate128recip
#undef delegaterecip128

#endif // USE_CLANG_FLOAT128

#if defined USE_CLANG_FLOAT128 || defined USE_CXX23_FLOAT128 || defined USE_SOFT_FLOAT128

FLOAT160 sumSeries(FLOAT160* v, int n, FLOAT160 x)
{   FLOAT160 r = v[n-1];
    long double rr = (long double)r;
    for (int i=n-2; i>=0; i--)
    {   r = x*r + v[i];
// In a while I will change the above to
//      r = r.fma(x, v[i];
// which may slightly reduce errors. 
        rr = ((long double)x)*rr + (long double)v[i];
        long double mine = (long double) r;
        if (std::abs((rr - mine)/rr) > 0.0001) abort();
    }
    return r;
}

// For this one I can be a lot more clever about reducing modulo 360.

constexpr FLOAT160 f160toradians(FLOAT160 x)
{   return x*0.0174532925199432957692369076848861271344287_Q;
}

constexpr FLOAT160 f160todegrees(FLOAT160 x)
{   return x*57.2957795130823208767981548141051703324055_Q;
}

FLOAT160 cbrt(FLOAT160 z)
{   FLOAT160 r;
    if (z >= 0.0_Q)
        r = (FLOAT160)std::pow((long double)z, 1.0L/3.0L);
    else r = -(FLOAT160)std::pow(-(long double)z, 1.0L/3.0L);
    FLOAT160 zz = z*z;
    r = z/(3.0_Q*zz) + (2.0_Q/3.0_Q)*z;
    return z/(3.0_Q*zz) + (2.0_Q/3.0_Q)*z;
}

// For the evaluation of sin(x) and cos(x) the hard part is range
// reduction. If |x| is large then one wants to subtract an integer multiple
// of pi/2 from it to bring it to the fundamental range -pi/4 to pi/4,
// tracking whether what is then wanted is a sine or cosine or the negative
// of one of those.
// If the reduced value is close to zero that subtraction could introduce
// severe cancellation errors. 
//
// K C Ng (Argument reduction for huge arguments: Good to the Last Bit, 1992)
// provides an explanation of a strategy.
//
// Here I will have numbers with 128 bit mantissas, and I will only
// concern myself with the exponent range as for IEEE 128-bit floats, ie
// up 16384.
//
// Any bit-pattern denoting a very large floating point number stands
// for an integer made up of 128-bits [the mantissa] and a large number
// of trailing zeros. If that is multiplied by the value 1/(2 pi) the
// fractional part gives the input reduced modulo 2 pi - albeit scaled
// to lie in the range 0 to 1, or with a little extra care -0.5 to 0.5.
// Ng's observation is that the bits that are required come from
// multiplying the 128-bit mantissa by a limited number of bits from
// somewhere within the full value for 1/(2 pi). The first few bits of the
// fraction will tell me which quadrant I am in, and the following ones
// give the fraction of pi/4 that I want to work with.
//
// So how many bits of the fraction are needed? In an extreme case the
// input floating point value may be very close in value to an integer
// multiple of pi/4, so to obtain 128 significant bits of that fraction
// can need many more bits.
// The extreme case in the range I am considering is
//   211178687508491476026207099112361930892 * 2^13323
//         = N*pi/2 + 6.714...e-43
// where N is a fairly ridiculously large integer (over 4000 decimal
// digits). This case exhibits 140 bits of cancellation, so to get 128
// significant figures in the residue one must evaluate the fraction
// to around 268 bits. I will be doing all the arithmetic in terms of
// 64-bit digits and so it is convenient to end up with 320 bits (i.e. 5
// words) in my value of the fractional part of X/(2*pi) - and with that
// amount in hand I will ignore any though of carries up that would arise
// if I calculated the exact product for all lower digits.
//
// I will need somewhat over 16384 bits of the reciprocal of pi, in
// particular enough to allow for the above cancellation issue. So a few
// more than 256 - here I provide 272 which is slight overkill.
//
// To multiply by M*2^x I will represent that as (M*2^remainder(x, 64)) *
// 2^(x/64), so I will stretch the 128-bit mantissa across 3 64-bit digits.
// To get 320 bits of the fraction I will use 5 words from the reciprocal
// of pi.

// a = u*v

static void mul(uint64_t* a,
                uint64_t* u, size_t lenu,
                uint64_t* v, size_t lenv)
{   //@std::cout << "mul 0x" << std::hex << std::setfill('0');
    //@for (size_t i=lenu; i!=0; i--)
    //@    std::cout << std::setprecision(16) << std::setw(16) << u[i-1] << "_";
    //@std::cout << "\nby 0x";
    //@for (size_t i=lenv; i!=0; i--)
    //@    std::cout << std::setw(16) << v[i-1] << "_";
    //@std::cout << "\n";
    for (size_t i = 0; i<lenu+lenv; i++)
        a[i] = 0;
    for (size_t i=0; i<lenu; i++)
    for (size_t j=0; j<lenv; j++)
    {   size_t k = i+j;
        uint128_t w = u[i]*(uint128_t)v[j];
        uint64_t lo = (uint64_t)w;
        uint64_t hi = (uint64_t)(w>>64);
        a[k] = a[k] + lo;
        if (a[k] < lo) hi++;
        k++;
        a[k] = a[k] + hi;
        if (a[k] < hi)
        {   while (++k < lenu+lenv)
            {    if (++a[k] != 0) break;
            }
        }
    }
    //@std::cout << "=> 0x";
    //@for (size_t i=lenu+lenv; i!=0; i--)
    //@    std::cout << std::setw(16) << a[i] << "_";
    //@std::cout << "\n";
}

// I used Reduce to generate this table using code that was in essence:
//   on rounded; precision 6000; w := 2/pi;
//   for i := ... do << w := w*2^64; prinhex (i = fix w); w := w-i >>;6
// save that I arranged to output the digits with the least significant
// ones first. Note it is 2/pi not 1/(2 pi) because that makes it
// a normalised number in the spirit of floating point - ie its most
// significant bit is a 1.

static uint64_t twoOverPi[] =
{ 0xbf0bc23522747ea2,0xf862e73bf28f39b5,0x3a9d4013d0cc1be5,0x8e1633b53bb1881d,
  0x393d8ea523aa3306,0xa94fd8ae01e661b4,0x251e7f3ed8974ebb,0x47f7a994c3aad392,
  0x7e8a31bb365895b7,0x6052dd34f8563aeb,0x47270babc3a734ba,0xa74b38fc4ceab2bb,
  0x89b295f364a8f1ae,0x4d59018071e0e13f,0x34007700d255f4fc,0x825c326b5b2746ed,
  0x6ded727a8d39a9b8,0x36169f3ac4a1a283,0xb5d6df8261dd9602,0x4d7e6f5119a5abf9,
  0x561408f1212a9db5,0x7e32b90f8ef5a7e7,0xca984e638270237c,0xce68b4ed09209f44,
  0x6919949a9529a828,0xdc51a463dd27dde1,0xa365b1933d0b7cbd,0x268a67f7bf920d2b,
  0x7bdbe5c23ac4eaf4,0x2688893c78e4c4a8,0x2a1a2c8012bf4390,0x94792c8761107b4c,
  0xc5476243853b8621,0xd3cfc50fae5adb86,0x8a59c52bfa94c5c1,0xfb49e956ffca0f1c,
  0x39e6e389d49ee540,0x086e59862a218347,0xf65523882b55ba41,0x5ea4677b7aacbaa2,
  0x42eb67df9dfe5fd4,0x9f405547dc3a74e1,0x214a827b21cf98dc,0x974c8836d1f9b392,
  0x0569f0b265a7887f,0x51b133990ed7a948,0x3826829be7caa40d,0xad38dc9367aae855,
  0x56ae79e536228922,0xc0549efa864ffc06,0x2c21d7f359987ad9,0xdddd1c2da118af46,
  0xc68351103ed84871,0x17c99b5861bc57e1,0xdd9b8e67ef3392b8,0xeebc34cc5de8605e,
  0xb5f4f5cbfc2dbc34,0x26ee523f0f117f11,0xb8701a649569605a,0x552ad6c6c096190b,
  0x538c994ecc2254dc,0x6a4afbd81c2f84b4,0x2138c8d91b0afc81,0xefc9352e61392f44,
  0x84d4e9a9b4fcd1ee,0xf4e16d3b8e2c86e2,0x3ecc5f114a0bfdfb,0xb920d6aa5e6b9c2a,
  0x576f89562ce3ce99,0xb40ecccf2d891234,0x36c59456a8d8b5a8,0x97c427a831c36ef1,
  0xd913d9ecb9ba8bfc,0xbefdfdef4556367e,0x667e162901767a9f,0x742c150d0c188194,
  0x24ba74607de58ad8,0xc9b55100b70db2e2,0xc6a9cff7df7329ba,0x9d6ecd7b723e6a11,
  0x0893745d7cb2ad6b,0xffe26a6ec6fdb0c1,0x35916fc5e0088dd7,0xfd29f3d6e7ca7c22,
  0x0e423e1c87c461e9,0xc6926e5d2eaced44,0x18465f7555f5bdd2,0x6913daf03c3aba46,
  0xc397a4d45877c5e3,0x647cd8649b31bed9,0x4ec8cad641f3e8de,0x7bdc06cc45e0fa29,
  0x72953b06a33540c0,0xb24855510efb1ec3,0x6b0701acb08cd0c0,0xdec9f560bf11654d,
  0x800120cc86dd71b6,0x5f57a4b13f149538,0xc7f48d4d0da63a20,0x4fbcf82d985ad795,
  0x4f6a68a82a4a5ac4,0x897bfef3059ebfb9,0x872afddab6256b34,0x640b148d4196debe,
  0x0027f0147f8607e1,0xca5c6a0817552e55,0xc1db9bbd17ab81a2,0xf9b4cbda11d0be7d,
  0x20d3a2b30a5d2f42,0x2d408da0cd4f99a5,0x698f77ff2780030c,0x08d4b1ea21f716e4,
  0xc3b21d3632a1a4b7,0x6e13e4305da92e85,0x50b7d51ec4f1335f,0xe0566b0152993755,
  0x1262845cb9496170,0x05a0dd5a476f21d2,0xfd6cbfa200a4e46c,0x6125ce70c9b8cb30,
  0x8416df30432dc735,0x3967955bbf3148d7,0xbd4dafe7b36e6d8f,0x2833676186182aea,
  0x156e85ff87fd073e,0x76e4fca90670803e,0xfafedb89fdbe896c,0x2a12162db7dcfde5,
  0x07da0eaa76a1597b,0xb6b42d297e804ba7,0x9aaf009353ad0457,0xc790b6db2a3a25a3,
  0xddbc5c3f6dded01f,0xf480c62ff0ac9aec,0xadc3da4886a05df7,0xd12df1b1c1998c77,
  0xba66aacfcf761d02,0xebef584a9bb7dac4,0x8953a6c6e26e6f00,0x76f923048b7b7217,
  0xc1d20f3f0bcd785b,0x331aaaf0a8654fa5,0xe9424ea4be13b523,0xb33d8f1b5709cd36,
  0x040622fa1de4d9a4,0x3080abf68c6615cb,0xf96af3be75df9328,0x29bf56573aff47b9,
  0x664d64b705ed3065,0x15dfa1ae00dafb0c,0x6837dbfcaba1ae31,0xde6319ef8c76528b,
  0xa9e69492ab6842dd,0xc6a5ca4ecd37a736,0x5bc3d8c492f54bad,0x316d07b43915200c,
  0x03f6f0098c402b99,0x9c7a2d9756c0833f,0xedaf12265c4dc26d,0x0eaa3a51c2a31dae,
  0x768364333b091a94,0x22dbaa140a2f2689,0xd2277549f6b6ebbb,0xb989c7bd401004f2,
  0x185915a562bbcb61,0x6c4bffdb0f903876,0x921110d8e80faf80,0x3715a0805c93805a,
  0xdde7b7173bdf082b,0xde41319d39928c70,0x3fa3fd94438c860d,0x663de06483dd9797,
  0x27fc00a871ea49c2,0xa4049407777030f3,0x9089d98850722cbe,0xacccc65414ad6ae2,
  0x6b49ba271d296996,0xb4c576ea17f9877d,0x9d072750045ddb3b,0x090b69f52ad56614,
  0x5bd4714e6e5445c1,0x10d86d324832754c,0x8985295255c06437,0xb25f3edd035d407f,
  0x3398207e4bf56863,0x91b45153d1f20acf,0x6eef169fa6948ef6,0x24d6bda67df77248,
  0xee2c90aa4702e774,0x30010c0d68084b58,0x25318d3974f71c05,0x5d8db8159f09e5bc,
  0x486ca46742727132,0x365f5f0efdbbb49a,0xe6e29731996bed88,0x4189dff49794e884,
  0x96cb314a1679e279,0x550c90a7721fe76b,0x2ec292472f327b6d,0x9c12887b20ab9fb5,
  0x71c1b3092ef3450b,0xb328f8c79405933e,0xf53e1380f1ecc3e7,0xbe00cc941eeece70,
  0xd4e5492910d5fdfc,0x91b24df31700ad43,0x4612c459c444c5c8,0xc277c9121426049b,
  0x36d9cad2a8288d61,0x818d67c12645ca55,0x6f63a62dcbbff4ef,0x78738a5a8cafbdd7,
  0x775c83c2a3883c61,0x0ab499d3f2a6067f,0x425faece616aa428,0x4a48d36710d8ddaa,
  0xf57fb0adf2e91e43,0x6212830148835b8e,0x1df35be01834132e,0x08cb7de050c017a7,
  0x4d58e232cac616e3,0x9bde2822d2e88628,0x5dd7de16de3b5892,0xcdc4ef09366cd43f,
  0x652289e83260bfe6,0x9947fbacd87f7eb7,0xff319f6a1e666157,0x1f001b0af1dfce19,
  0x24778ad623545ab9,0xd9d63b3884a7cb23,0xb07ae715175649c0,0x64abd770f87c6357,
  0x1810a3fc764d2a9d,0xa7b4d55537f63ed7,0x9b0062337cd2b497,0x467d862d71e39ac6,
  0xc4ad414d2c5d000c,0x15c614b59d19c3c2,0xfa6ed5772d30433b,0x87f121907c7c246a,
  0x9f3a1f35caf27f1d,0xc33d26ef6b1e5ef8,0x32c2de4f98327dbb,0xa5ff07053f7e33e8,
  0xddaf44d15719053e,0x8359c4768b961ca6,0x19c367cddce8092a,0x60e27bc08c6b47c4,
  0x06061556ca73a8c9,0x8dffd8804d732731,0x6599855f14a06840,0xa9e391615ee61b08,
  0xf0cfbc209af4361d,0x56033046fc7b6bab,0x6bfb5fb11f8d5d08,0x3d0739f78a5292ea,
  0x7527bac7ebe5f17b,0x4f463f669e5fea2d,0x6d367ecf27cb09b7,0xef2f118b5a0a6d1f,
  0x1ff897ffde05980f,0x9c845f8bbdf9283b,0x3991d639835339f4,0xe99c7026b45f7e41,
  0xe88235f52ebb4484,0xfe1deb1cb129a73e,0x06492eea09d1921c,0xb7246e3a424dd2e0,
  0xfe5163abdebbc561,0xdb6295993c439041,0xfc2757d1f534ddc0,0xa2f9836e4e441529,
  0x0000000000000000
};

static size_t lengthTwoOverPi = lengthOf(twoOverPi) - 1;

FLOAT160 trigreduce(FLOAT160 a, int& octant)
{   //@std::cout << "trigreduce(" << a << ")\n";
    if (a < 0.0_Q)
    {   a = -a;
        octant = 4;
// If the argument is negative I can take its absolute value and
// pretend it is a few octants on. Eg this is using the identity
// sin(-x) = sin(pi+x).
    }
    else octant = 0;
// If I am now in the range 0 to pi/4 I will just multiply by 4/pi so that
// that range is mapped onto 0 to 1. This is to be consistent with  what I
// do in the general case which is to return a value in the range 0 to 1
// standing for an offset within an octant together with an integer value
// explaining which octant is involved.
//     The constants here are "pi/4" and "2/pi".
    if (a <= 0.785398163397448309615660845819875721049292_Q)
        return 0.636619772367581343075535053490057448137839_Q * a;
// Now a >= pi/4 = 0.785... and that means that its floating point
// representation has an exponent that is at least 1. 
    uint64_t mm[3];
// Fetch the mantissa into a 192=bit field represened as three 64-bit ints.
    mm[2] = 0;
    mm[1] = (uint64_t)(a.mantissa()>>64);
    mm[0] = (uint64_t)a.mantissa();   
// Shift the mantissa in such a way that the residual exponant is a multiple
// of 64.
    int32_t x = a.exponent();
    //@std::cout << "a.x = " << a.exponent() << "\n";;
    int shift = x%64;
    x = x/64;
    if (shift != 0)
    {   mm[2] =                  (mm[1]>>(64-shift));
        mm[1] = (mm[1]<<shift) | (mm[0]>>(64-shift));
        mm[0] = (mm[0]<<shift);
    }
// Now multiply the mantissa by a bunch of digits from 2/pi.
    uint64_t prod[8];
    //@std::cout << "word x = " << x << "\n";
    mul(&prod[0], &mm[0], 3, &twoOverPi[lengthTwoOverPi-4-x], 5); 
    //@std::cout << std::hex << "\n" << std::setprecision(16)
    //@          << std::setfill('0') << std::setw(16) << prod[7]
    //@          << "\n"              << std::setw(16) << prod[6]  // octant
    //@          << "\n"              << std::setw(16) << prod[5]  // HI
    //@          << "\n"              << std::setw(16) << prod[4]  // LO
    //@          << "\n"              << std::setw(16) << prod[3]  // 
    //@          << "\n"              << std::setw(16) << prod[2]  // normalize
    //@          << "\n"              << std::setw(16) << prod[1]  //
    //@          << "\n"              << std::setw(16) << prod[0]  //
    //@          << std::dec << "\n";
    octant = 2*(prod[6] & 3);
    if ((prod[5]>>63) != 0)    // over 0.5
    {   octant++;
        uint64_t carry = 1;
        for (int i=0; i<=5; i++)
        {   prod[i] = carry + ~prod[i];
            carry = prod[i] == 0;
        }
    }
    //@std::cout << "frac = "
    //@          << (double)prod[5] / pow(2.0, 64) << "\n";
    FLOAT160 frac;
    frac.setsignbit(false);
// Well I need to handle leading zeros in the fraction....
    x = 0;
    while (prod[5] == 0 && x > -6*64)
    {   x -= 64;
        prod[5] = prod[4];
        prod[4] = prod[3];
        prod[3] = prod[2];
        prod[2] = prod[1];
        prod[1] = prod[0];
        prod[0] = 0;
    }
    shift = nlz(prod[5]);
    if (shift != 0)
    {   x -= shift;
        prod[5] = (prod[5]<<shift) | (prod[4]>>(64-shift));
        prod[4] = (prod[4]<<shift) | (prod[3]>>(64-shift));
        prod[3] = (prod[3]<<shift) | (prod[2]>>(64-shift));
        prod[2] = (prod[2]<<shift) | (prod[1]>>(64-shift));
        prod[1] = (prod[1]<<shift) | (prod[0]>>(64-shift));
        prod[0] = (prod[0]<<shift);
    }
// Now round it
    if (topbit64(prod[3]))
    if (++prod[4] == 0)
    {   if (++prod[5] == 0)
        {   prod[5] = topbit64();
            x++;
        }
    }
    frac.setmantissa((((uint128_t)prod[5])<<64) | prod[4]);
    frac.setexponent((frac.mantissa()==0) ? INT32_MIN : x);
    return frac;
}

// I have rational approximations for sin and cos across the range 0 to pi/4,
// but they are set up so that the range has been mapped to 0 to 1. This
// is because this change makes the argument reduction for potentially large
// arguments easier.

static FLOAT160 sin_p[] =   // for sin(pi*x/2)/x
{   1.570796326794896619231321691639751442098_Q,
   -0.001604044972399019644604488374991688767469_Q,
   -0.5937705959278475993379420768987748027781_Q,
    0.0005975753737488269809779780140320128727079_Q,
    0.05909625289400322796692758887881726829641_Q,
   -0.0000570474175532128901082952611095107150944_Q,
   -0.002381071959856202773551262656729113029431_Q,
    0.00000210706185893510229166568249295322065413_Q,
    0.00004509482558425328651129207826065802125741_Q,
   -0.00000003339973756999806539302029717504126154493_Q,
   -0.0000004057544785125929984018632150523632818622_Q,
    0.0000000001958321341618331499034371786495152562818_Q,
    0.000000001424140541705665404045847673940588645516_Q
};

static FLOAT160 sin_q[] =
{   1.000000000000000000000000000000000000000000_Q,
   -0.001021166745196027184479621615101577643576_Q,
    0.03322741509390714884691671032880190238699_Q,
   -0.00003950969336791632186448189442954709812605_Q,
    0.0005521682452664599571461029291696025224081_Q,
   -0.0000007574509770297829331502079477168923602926_Q,
    0.000005973445011674676914378868940424990106617_Q,
   -0.000000009195771025289025525337647651255869011957_Q,
    0.00000004527782404273010144195659992861646655353_Q,
   -0.00000000007262923445983475595620521032838668336912_Q,
    0.0000000002337701589079679880433739095325480628091_Q,
   -3.086732541116121324964291827577198166891e-13_Q,
    6.628423714613619127944341254096016077932e-13_Q
};

static FLOAT160 cos_p[] =
{   1.000000000000000000000000000000000000000_Q,
   -0.001079323149209389316670187745774472098182_Q,
   -1.196899589949123697664065560647514464822_Q,
    0.001284394855475493723758524833711039516854_Q,
    0.2089515993986136236737884964621315834127_Q,
   -0.0002166360097550516451607250336196631736833_Q,
   -0.0123630281210950712166115376273381739882_Q,
    0.00001181503433244860786732248106071244773204_Q,
    0.0003146052048983107377243841531501573509477_Q,
   -0.0000002526202600026095427135691328418048583901_Q,
   -0.000003602030406756103040172042222437872680703_Q,
    0.000000001889416501334054577060555742682831132203_Q,
    0.00000001549711359047789813144207311713088778854_Q
};

static FLOAT160 cos_q[] =
{   1.0000000000000000000000000000000000000000_Q,
   -0.001079323149209389316670187745774472127694_Q,
    0.03680096018704612969024581433700443243661_Q,
   -0.00004716670747883318826896415593024366480618_Q,
    0.0006834563258637035065956787936394320214179_Q,
   -0.000001034230593644737902789934716043122435223_Q,
    0.000008351626535934446222304627613186041579489_Q,
   -0.00000001457880540189841070690822529903563636939_Q,
    0.0000000724313924494431782746164415863441970191_Q,
   -0.0000000001361738737441661706109657426808996418938_Q,
    0.000000000434752823134271505129397823633432325808_Q,
   -7.002452489015871653247583039940347629568e-13_Q,
    1.462450713406493390104119121427303450061e-12_Q
};

FLOAT160 sin(FLOAT160 x)
{   int octant;
    x = trigreduce(x, octant);
    switch (octant)
    {
    default:
    case 0:
    case 3:
        return x*sumSeries(sin_p, lengthOf(sin_p), x) /
                 sumSeries(sin_q, lengthOf(sin_q), x);
    case 1:
    case 2:
        return sumSeries(cos_p, lengthOf(cos_p), x) /
               sumSeries(cos_q, lengthOf(cos_q), x);
    case 4:
    case 7:
        return -x*sumSeries(sin_p, lengthOf(sin_p), x) /
                 sumSeries(sin_q, lengthOf(sin_q), x);
    case 5:
    case 6:
        return -sumSeries(cos_p, lengthOf(cos_p), x) /
               sumSeries(cos_q, lengthOf(cos_q), x);
    }
}

FLOAT160 sind(FLOAT160 x)
{   return sin(f160toradians(x));
}

FLOAT160 cos(FLOAT160 x)
{   int octant;
    x = trigreduce(x, octant);
    switch (octant)
    {
    default:
    case 0:
    case 7:
        return sumSeries(cos_p, lengthOf(cos_p), x) /
               sumSeries(cos_q, lengthOf(cos_q), x);
    case 1:
    case 6:
        return x*sumSeries(sin_p, lengthOf(sin_p), x) /
                 sumSeries(sin_q, lengthOf(sin_q), x);
    case 2:
    case 5:
        return -x*sumSeries(sin_p, lengthOf(sin_p), x) /
                  sumSeries(sin_q, lengthOf(sin_q), x);
    case 3:
    case 4:
        return -sumSeries(cos_p, lengthOf(cos_p), x) /
                sumSeries(cos_q, lengthOf(cos_q), x);
    }
}

FLOAT160 cosd(FLOAT160 x)
{   return cos(f160toradians(x));
}

void sincos(FLOAT160 x, FLOAT160& s, FLOAT160& c)
{   int octant;
    x = trigreduce(x, octant);
    switch (octant)
    {
    case 0:
        s = x*sumSeries(sin_p, lengthOf(sin_p), x) /
              sumSeries(sin_q, lengthOf(sin_q), x);
        c = sumSeries(cos_p, lengthOf(cos_p), x) /
            sumSeries(cos_q, lengthOf(cos_q), x);
        return;
    case 1:
        s = sumSeries(cos_p, lengthOf(cos_p), x) /
            sumSeries(cos_q, lengthOf(cos_q), x);
        c = x*sumSeries(sin_p, lengthOf(sin_p), x) /
              sumSeries(sin_q, lengthOf(sin_q), x);
        return;
    case 2:
        s = sumSeries(cos_p, lengthOf(cos_p), x) /
            sumSeries(cos_q, lengthOf(cos_q), x);
        c = -x*sumSeries(sin_p, lengthOf(sin_p), x) /
               sumSeries(sin_q, lengthOf(sin_q), x);
        return;
    case 3:
        s = x*sumSeries(sin_p, lengthOf(sin_p), x) /
              sumSeries(sin_q, lengthOf(sin_q), x);
        c = -sumSeries(cos_p, lengthOf(cos_p), x) /
             sumSeries(cos_q, lengthOf(cos_q), x);
        return;
    case 4:
        s = -x*sumSeries(sin_p, lengthOf(sin_p), x) /
               sumSeries(sin_q, lengthOf(sin_q), x);
        c = -sumSeries(cos_p, lengthOf(cos_p), x) /
             sumSeries(cos_q, lengthOf(cos_q), x);
        return;
    case 5:
        s = -sumSeries(cos_p, lengthOf(cos_p), x) /
             sumSeries(cos_q, lengthOf(cos_q), x);
        c = -x*sumSeries(sin_p, lengthOf(sin_p), x) /
               sumSeries(sin_q, lengthOf(sin_q), x);
        return;
    case 6:
        s = -sumSeries(cos_p, lengthOf(cos_p), x) /
             sumSeries(cos_q, lengthOf(cos_q), x);
        c = x*sumSeries(sin_p, lengthOf(sin_p), x) /
              sumSeries(sin_q, lengthOf(sin_q), x);
        return;
    case 7:
        s = -x*sumSeries(sin_p, lengthOf(sin_p), x) /
               sumSeries(sin_q, lengthOf(sin_q), x);
        c = sumSeries(cos_p, lengthOf(cos_p), x) /
            sumSeries(cos_q, lengthOf(cos_q), x);
        return;
    }
}

FLOAT160 cot(FLOAT160 x)
{   FLOAT160 s, c;
    sincos(x, s, c);
    return c/s;
}

FLOAT160 cotd(FLOAT160 x)
{   FLOAT160 s, c;
    sincos(f160toradians(x), s, c);
    return c/s;
}

FLOAT160 csc(FLOAT160 x)
{   return 1.0_Q/sin(x);
}

FLOAT160 cscd(FLOAT160 x)
{   return 1.0_Q/sind(x);
}

// range reduction and then calculation for exp(x):
//    exp(x) = e^x = 2^(x/ln(2))
//    2^y splits y into integer and fractional parts. Integer part
//    just goes into exponent field of result, so now I just have
//    the case of 2^z with 0 <= z < 1 and value in range 1 to 2.
//    I will calculate (2^z-1)/z across the range 0-0.125 and have a table
//    of powers of 2^0.125 - that lets me get away with a slightly more
//    compact rational approximation. I will do all this in my FLOAT160
//    working precision and on that basis expect the FLOAT128 values to
//    be good.

// Sorting out how the code for exp() and expm1() overlap is something
// I will look at later on.

static FLOAT160 exp_octable[] =
{   0.0000000000000000000000000000000000000000_Q, 
    0.0905077326652576592070106557607079789927_Q, 
    0.1892071150027210667174999705604759152930_Q, 
    0.2968395546510096659337541177924511598353_Q, 
    0.4142135623730950488016887242096980785697_Q, 
    0.5422108254079408236122918620907348413068_Q, 
    0.6817928305074290860622509524664297900801_Q, 
    0.8340080864093424634870831895882888560773_Q,
    1.0000000000000000000000000000000000000000_Q
};
static FLOAT160 exp_p[] =
{   0.6931471805599453094172321214581765680737_Q,
    0.1638507241802161879389976745605377662491e-1_Q,
    0.1111080513090245096193942334836019166919e-1_Q,
    0.2523197609677775852992903049759603961266e-3_Q,
    0.3433396202068948357530012521638104972217e-4_Q,
    0.6612834363624882887964646325949905929453e-6_Q,
    0.2162348403714450924016156321391250853526e-7_Q,
    0.2101714773055805609781638612022184199853e-9_Q
};
static FLOAT160 exp_q[] =
{   1.0000000000000000000000000000000000000000_Q,
   -0.3229349275578863288553224655571563828594_Q,
    0.4787471841347592523962107176185849066378e-1_Q,
   -0.4244943201766206566801133343076899398152e-2_Q,
    0.2445545235228146961725729359119685196133e-3_Q,
   -0.9217046766308393356369722130194373556687e-5_Q,
    0.2121412313725233798992249177928269652172e-6_Q,
   -0.2322861545473693173223914979006893638227e-8_Q
};


FLOAT160 exp(FLOAT160 v)
{   // Multiply by 1/log(2)
    FLOAT160 w = v*1.4426950408889634073599246810018921374266_Q;
    if (w > 20000_Q)     // overflowed.
    {   FLOAT160 r(1);
        r.setexponent(20000);  // out of range for FLOAT128
        return r;
    }
    else if (w < -20000_Q) return FLOAT160(0); // underflowed.
    int64_t ipart = (uint64_t)w;
    if (w.signbit()) ipart = -ipart-1;
    w = w - (FLOAT160)ipart;       // w is now in the range 0 <= w <= 1 and
                                   // I have potential equality at each end
                                   // because of negative inputs.
    int oct = (w.exponent() <= -3) ? 0 : w.mantissa()>>(128-w.exponent()-3);
    w = w - (FLOAT160)oct/8.0_Q;
// Now w should be in the range 0 to 0.125.
// x*p(x)/q(x) gives what is intended to be a minimax rational
// approximation to 2^x-1 on the range 0 to 0.125. The values
// here were computed using the Reduce algebra system and the
// operator "multipoint_pade".
    FLOAT160 pp = w*sumSeries(exp_p, lengthOf(exp_p), w);
    FLOAT160 qq = sumSeries(exp_q, lengthOf(exp_q), w);
    FLOAT160 r = 1.0_Q + pp/qq;
// I have a table of (2^(k/8) - 1) for k in the range 0 to 8.
    r.setexponent(r.exponent() + ipart);
    return r * (1.0_Q+exp_octable[oct]);
}

FLOAT160 expm1(FLOAT160 v)
{   FLOAT160 w = v*1.4426950408889634073599246810018921374266_Q;
    if (w > 20000_Q)     // overflowed.
    {   FLOAT160 r(1);
        r.setexponent(20000);  // out of range for FLOAT128
        return r;
    }
    else if (w < -20000_Q) return FLOAT160(0); // underflowed.
    int64_t ipart = (uint64_t)w;
    if (w.signbit()) ipart = -ipart-1;
    w = w - (FLOAT160)ipart;
    int oct = (w.exponent() <= -3) ? 0 : w.mantissa()>>(128-w.exponent()-3);
    w = w - (FLOAT160)oct/8.0_Q;
    FLOAT160 pp = w*sumSeries(exp_p, lengthOf(exp_p), w);
    FLOAT160 qq = sumSeries(exp_q, lengthOf(exp_q), w);
// To here has been just the same as for full exp(). Now the result
// I need is is 2^ipart*(1+pp/qq)*(1+octable[oct]) - 1. If ipart != 0 there
// is little point in trying to be clever.
    if (ipart != 0)
    {   FLOAT160 r = 1.0_Q + pp/qq;
        r.setexponent(r.exponent() + ipart);
        return r * (1.0_Q+exp_octable[oct]);
    }
// But now I can use (1 + pp/qq + octable[oct] + pp/qq*octable[oct] - 1)
// and the "1" values cancel...
    FLOAT160 r = pp/qq;
    return r + exp_octable[oct] + r*exp_octable[oct];
}

// log() deserves special treatment near 1. See log1p().

//    log  log(2^n*x) = n log 2 + log x
//         then let y be an approximation to log x using std::log then write
//           x = exp(y) * (1 + w)
//         where now |w| may be < 10^-16. Then use log(w) = x - w^2/2
//         and the next term w^3/3 can be ignored.


FLOAT160 log(FLOAT160 v)
{   int xpart = v.exponent() - 1;
    v.setexponent(1);
// v is now in the range [1.0 .. 2.0). The case of it having started as
// zero is not considered!
    FLOAT160 addin = (FLOAT160)xpart *
                     0.6931471805599453094172321214581765680755_Q; 
// Get an approximation using regular double precision.
    FLOAT160 approx = (FLOAT160)std::log((double)v);
    FLOAT160 w = exp(-approx);
    FLOAT160 delta = v*w - 1.0_Q;
    FLOAT160 r = delta*(1.0_Q - 0.5_Q*delta);
    return (approx + r) + addin; 
}

FLOAT160 ln(FLOAT160 x)
{   return log(x);
}

FLOAT160 log10(FLOAT160 v)
{   return 0.434294481903251827651128918916605082294397_Q*log(v);
}

FLOAT160 log1p(FLOAT160 v)
{
// When |v| < 0.01 I would lose 7 or more trailing bits by adding
// it to 1. For lerger arguments I will still lose something (up to
// 7 bits) but for use from FLOAT128 the additional accuracy of my working
// precision means that is not a serious worry.
    if (v > 0.01_Q || v < - 0.01_Q) return log(1.0_Q + v);
// For small arguments I can use a minimax rational approximation.
    static FLOAT160 p[] =
    {   1.00000000000000000000000000000000000000000_Q,
        3.23335119208669009811950615647341921457860_Q,
        4.06671433035756562556475789834062201148364_Q,
        2.50218351827631076951595174285870181038385_Q,
        0.774379517233343735844117748547634310403064_Q,
        0.110073815423914934447863530639771712476732_Q,
        0.00535932633220079986583115090873941229555183_Q,
        0.0000194261077189025142142800262725012158715025_Q
    };
    static FLOAT160 q[] =
    {   1.00000000000000000000000000000000000000000_Q,
        3.73335119208669009811950615647341921457862_Q,
        5.60005659306757734129117764324399828543959_Q,
        4.30776141744786940745503851232289454405615_Q,
        1.79491249295642518367112099607943697533334_Q,
        0.391620165935727372830637704088991522399652_Q,
        0.0391623365536801345400276535769796942919873_Q,
        0.00124325974963227898938817681241416168985459_Q
    };
    FLOAT160 pp = sumSeries(p, lengthOf(p), v);
    FLOAT160 qq = sumSeries(q, lengthOf(q), v);
    return v*(pp/qq);
}

FLOAT160 log2(FLOAT160 v)
{   int32_t x;
    FLOAT160 w = v.frexp(x);
    return (FLOAT160)x + 1.44269504088896340735992468100189213742665_Q*log(w);
}

// The formula used here will lose accuracy because log() compresses the
// whole range of 128-bit floats into around the range +/- 11356. But here
// as measured against FLOAT128 I have 15 bits of accuracy in hand and that
// is at least pretty close to being able to overcome this challenge when
// I am only really concerned with use on FLOAT128s.
 
FLOAT160 expt(FLOAT160 x, FLOAT160 y)
{   return exp(y * log(x));
}

FLOAT160 sec(FLOAT160 x)
{   return 1.0_Q/cos(x);
}

FLOAT160 secd(FLOAT160 x)
{   return 1.0_Q/cosd(x);
}

FLOAT160 sinh(FLOAT160 v)
{   bool sign = v.signbit();
    v.setsignbit(false);
    if (v < 0.693147180559945309417232121458176568075500134_Q)
    {   if (v == 0.0_Q) return v;
        FLOAT160 a = expm1(v);
        v.setsignbit(true);
        FLOAT160 b = expm1(v);  // a and b have opposite signs.
        v = a - b;
        v.setexponent(v.exponent()-1);
        v.setsignbit(sign);
        return v;
    }
    v = exp(v);
    v = v - 1.0_Q/v; // These differ in magnitude enough that there is no
                     // embarassing cancellation.
    v.setexponent(v.exponent()-1);
    v.setsignbit(sign);
    return v;
}

FLOAT160 csch(FLOAT160 x)
{   return 1.0_Q/sinh(x);
}

FLOAT160 cosh(FLOAT160 v)
{   v = exp(v);
    v = v + (1.0_Q/v);
    v.setexponent(v.exponent()-1);
    return v;
}

FLOAT160 sech(FLOAT160 x)
{   return 1.0_Q/cosh(x);
}

void sinhcosh(FLOAT160 v, FLOAT160& s, FLOAT160& c)
{   if (v.mantissa() == 0)
    {   s = v;
        c = 1.0_Q;
        return;
    }
    bool sign = v.signbit();
    v.setsignbit(false);
    if (v < 0.693147180559945309417232121458176568075500134_Q)
    {   s = sinh(v);
        c = cosh(v);
        s.setsignbit(sign);
        return;
    }
    v.setsignbit(sign);
    v = exp(v);
    FLOAT160 r = 1.0_Q/v;
    s = v - r;
    s.setexponent(s.exponent()-1);
    c = v + r;
    c.setexponent(c.exponent()-1);
}

FLOAT160 coth(FLOAT160 x)
{   FLOAT160 s, c;
    sinhcosh(x, s, c);
    return c/s;
}

FLOAT160 sqrt(FLOAT160 x)
{   if (x < 0.0_Q) return NAN160();
    else if (x == 0.0_Q) return x;
    FLOAT160 r = (FLOAT160)std::sqrt((long double)x);
// If long double is an 80-bit type then the first approximation
// should be OK to 64-bits and the next to pretty well 128 which is
// good for FLOAT160 and thoroughly good enough for when this
// is a working precision calculation aimes at a FLOAT128 result.
// If long double is no better than double (and Windows may expect that)
// then an extra iteration is needed.
    if (longdouble64)
        r = 0.5_Q*(r + x/r);
    return 0.5_Q*(r + x/r);
}

FLOAT160 rsqrt(FLOAT160 x)
{   if (x < 0.0_Q) return NAN160();
    else if (x == 0.0_Q) return INF160();
     FLOAT160 r = 1.0_Q/(FLOAT160)std::sqrt((long double)x);
    if (longdouble64)
        r = 0.5_Q*r*(3.0_Q - x*r*r);
    return 0.5_Q*r*(3.0_Q - x*r*r);
}

// The usual main delicacy with hypot is that there can be overflow or
// underflow in intermediate results. Here the inputs are expected to
// have come from a FLOAT128 world where exponents are 15 bits, and here
// I have 32-bits, so this is not an issue.

FLOAT160 hypot(FLOAT160 x, FLOAT160 y)
{   return sqrt(x*x + y*y);
}

FLOAT160 tan(FLOAT160 x)
{   FLOAT160 s, c;
    sincos(x, s, c);
    return s/c;
}

FLOAT160 tand(FLOAT160 x)
{   FLOAT160 s, c;
    sincos(f160toradians(x), s, c);
    return s/c;
}

FLOAT160 tanh(FLOAT160 x)
{   FLOAT160 s, c;
    sinhcosh(x, s, c);
    return s/c;
}

FLOAT160 acos(FLOAT160 z)
{   if (z > 1.0_Q || z < -1.0_Q) return NAN160();
    FLOAT160 w = (FLOAT160)std::acos((long double)z);
    FLOAT160 s, c;
    sincos(w, s, c);
    w = w + (c - z)/s;
    if (longdouble64)
    {   sincos(w, s, c);
        w = w + (c - z)/s;
    }
    return w;
}

FLOAT160 acosd(FLOAT160 z)
{   if (z > 1.0_Q || z < -1.0_Q) return NAN160();
    return f160todegrees(acos(z));
}

FLOAT160 acosh(FLOAT160 z)
{   FLOAT160 w = (FLOAT160)std::acosh((long double)z);
    FLOAT160 s, c;
    sinhcosh(w, s, c);
    w = w + (c - z)/s;
    if (longdouble64)
    {   sinhcosh(w, s, c);
        w = w + (c - z)/s;
    }
    return w;
}

FLOAT160 acoth(FLOAT160 z)
{   return (FLOAT160)std::atanh(1.0/(long double)z);
}

// For y = asin(x)
//    y := asin(x)                      done using long double
//    let f(y) = sin(y) - x
//        f'(y) = cos(y)
//    y := y - (sin(y) - x)/cos(y)      Newton to improve

FLOAT160 asin(FLOAT160 z)
{   if (z > 1.0_Q || z < -1.0_Q) return NAN160();
    FLOAT160 w = (FLOAT160)std::asin((long double)z);
    FLOAT160 s, c;
    sincos(w, s, c);
    w = w + (z - s)/c;
    if (longdouble64)
    {   sincos(w, s, c);
        w = w + (z - s)/c;
    }
    return w;
}

FLOAT160 asind(FLOAT160 z)
{   if (z > 1.0_Q || z < -1.0_Q) return NAN160();
    return f160todegrees(asin(z));
}

FLOAT160 asinh(FLOAT160 z)
{   FLOAT160 w = (FLOAT160)std::asinh((long double)z);
    FLOAT160 s, c;
    sinhcosh(w, s, c);
    w = w + (s - z)/c;
    if (longdouble64)
    {   sinhcosh(w, s, c);
        w = w + (s - z)/c;
    }
    return w;
}

FLOAT160 atan(FLOAT160 z)
{   FLOAT160 r = (FLOAT160)std::atan((long double)z);
    FLOAT160 t = tan(r);
    r = r - (t - z)/(1.0_Q - t*t);
    if (longdouble64)
    {   t = tan(r);
        r = r - (t - z)/(1.0_Q - t*t);
    }
    return r;
}

FLOAT160 atanh(FLOAT160 z)
{   if (z > 1.0_Q || z < -1.0_Q) return NAN160();
    FLOAT160 r = (FLOAT160)std::atanh((long double)z);
    FLOAT160 t = tan(r);
    r = r - (t - z)/(1.0_Q + t*t);
    if (longdouble64)
    {   t = tan(r);
        r = r - (t - z)/(1.0_Q + t*t);
    }
    return r;
}

// atan2() returns a value on the range -pi to +pi

FLOAT160 atan2(FLOAT160 y, FLOAT160 x)
{   if (x >= 0.0_Q)
    {   if (y >= 0.0_Q)
        {   return atan(y/x);
        }
        else
        {   return -atan(-y/x);
        }
    }
    else
    {   if (y >= 0.0_Q)
        {   return 3.14159265358979323846264338327950288419717_Q -
                   atan(-y/x);
        }
        else
        {   return -3.14159265358979323846264338327950288419717_Q +
                   atan(y/x);
        }
    }
}

FLOAT160 atan2d(FLOAT160 y, FLOAT160 x)
{   return f160todegrees(atan2(y, x));
}

FLOAT160 atand(FLOAT160 x)
{   return f160todegrees(atan(x));
}

FLOAT160 acot(FLOAT160 z)
{   if (z < 0.0_Q) return 3.14159265358979323846264338327950288419717_Q -
                          atan(1.0_Q/z);
    return atan(1.0_Q/z);
}

FLOAT160 acotd(FLOAT160 z)
{   return f160todegrees(acot(z));
}

FLOAT160 acsc(FLOAT160 z)
{   if (z < 1.0_Q && z > -1.0_Q) return NAN160();
    return asin(1.0_Q/z);
}

FLOAT160 acscd(FLOAT160 z)
{   if (z < 1.0_Q && z > -1.0_Q) return NAN160();
    return f160todegrees(asin(1.0_Q/z));
}

FLOAT160 acsch(FLOAT160 z)
{   return asinh(1.0_Q/z);
}

FLOAT160 asec(FLOAT160 z)
{   if (z < 1.0_Q && z > -1.0_Q) return NAN160();
    return acos(1.0_Q/z);
}

FLOAT160 asecd(FLOAT160 z)
{   return f160todegrees(acos(1.0_Q/z));
}

FLOAT160 asech(FLOAT160 z)
{   if (z > 1.0_Q) return NAN160();
    return acosh(1.0_Q/z);
}

#endif // USE_CLANG_FLOAT128 || USE_CXX23_FLOAT128 || USE_SOFT_FLOAT128

#if defined USE_CXX23_FLOAT128 || defined USE_SOFT_FLOAT128

#define delegate128(fn, base) \
FLOAT128 fn(FLOAT128 x) { return (FLOAT128)base((FLOAT160)x); }

delegate128(acos, acos)
delegate128(acosd, acosd)
delegate128(acosh, acosh)
delegate128(acot, acot)
delegate128(acotd, acotd)
delegate128(acoth, acoth)
delegate128(acsc, acsc)
delegate128(acscd, acsc)
delegate128(acsch, acsch)
delegate128(asec, asec)
delegate128(asecd, asecd)
delegate128(asech, asech)
delegate128(asin, asin)
delegate128(asind, asind) 
delegate128(asinh, asinh)
delegate128(atan, atan)
delegate128(atand, atand)
delegate128(atanh, atanh)
delegate128(cbrt, cbrt)
delegate128(cos, cos)
delegate128(cosd, cosd)
delegate128(cosh, cosh)
delegate128(cot, cot)
delegate128(cotd, cotd)
delegate128(coth, coth)
delegate128(csc, csc)
delegate128(cscd, cscd)
delegate128(csch, csch)
delegate128(exp, exp)
delegate128(expm1, expm1)
delegate128(ln, log)
delegate128(log, log)
delegate128(log10, log10)
delegate128(log1p, log1p)
delegate128(log2, log2);
delegate128(sec, sec)
delegate128(secd, secd)
delegate128(sech, sech)
delegate128(sin, sin)
delegate128(sind, sind)
delegate128(sinh, sinh)
delegate128(sqrt, sqrt)
delegate128(rsqrt, rsqrt)
delegate128(tan, tan);
delegate128(tand, tand)
delegate128(tanh, tanh)

#define delegatebinary128(fn, base) \
FLOAT128 fn(FLOAT128 x, FLOAT128 y) \
{ return (FLOAT128)base((FLOAT160)x, (FLOAT160)y); }

delegatebinary128(atan2,  atan2)
delegatebinary128(atan2d, atan2d)
delegatebinary128(expt,   expt)
delegatebinary128(hypot,  hypot)

// frexp, ldexp, modf, exp2, ilogb, logb, scalbn, erf. erfc, tgamma, lgamma,
// ceil, floor, fmod, trunc, round, lround, rint, lrint, bearbyint, remainder,
// remquo, copysign, nextafter, nexttoward, fdim, fmax, fmin, abs, mfa,

#undef delegate128
#undef delegatebinary128

#endif // defined USE_CXX23_FLOAT128 || defined USE_SOFT_FLOAT128

// I should now have FLOAT128 available on every possible platform. So
// now I need to do somehing similar with complex-valued functions.
// If USE_LONG_DOUBLE is set then std::sin() etc will do the trick.
// If USE_QUADMATH is set then csinq() and friends should be available.
// In all the other cases I need to build a complex library based on
// the real-valued functions I have.

#ifdef NEED_COMPLEX_MATHLIB

// There are places where I want to use std::complex<long double> to
// evaluate some elementary function. The "respectable" case is where I
// use that to obtain a good first approximation to the full precision
// result I need. For instance in sqrt(COMPLEX160) I start by using
// sqrt(std::complex<long double>) and then using Newton Raphson to
// boost precision.
// In places where I have not got round to implementing my own COMPLEX160
// code I fall back to use of long double so that at least the code
// compiles and does something in every case. 

std::complex<long double> tocomplexlongdouble(COMPLEX160 z)
{   return std::complex<long double>((long double)z.real(),
                                     (long double)z.imag());
}

std::complex<long double> tocomplexlongdouble(FLOAT160 z)
{   return std::complex<long double>((long double)z, 0.0L);
}

COMPLEX160 fromcomplexlongdouble(std::complex<long double> z)
{   return COMPLEX160((FLOAT160)z.real(), (FLOAT160)z.imag());
}

// I could implement this better!

COMPLEX160 recip(COMPLEX160 z)
{   return COMPLEX160(1.0_Q, 0.0_Q)/z;
}

// Get both sine and cosine of the same argument.
// This could be done in ways that are cheaper than doing the
// two calculations separately, but for a first version I will
// take the lazy route.

#if false && defined USE_CLANG_FLOAT128

void sincos(FLOAT160 x, FLOAT160& s, FLOAT160& c)
{   s = sin(x);
    c = cos(x);
}

void sinhcosh(FLOAT160 x, FLOAT160& s, FLOAT160& c)
{   s = sinh(x);
    c = cosh(x);
}

#endif // USE_CLANG_FLOAT128

COMPLEX160 cos(COMPLEX160 z)
{   FLOAT160 s, c, sh, ch;
    sincos(z.real(), s, c);
    sinhcosh(z.imag(), sh, ch);
    return COMPLEX160(c*ch, -s*sh);
}

COMPLEX160 cosh(COMPLEX160 z)
{   FLOAT160 s, c, sh, ch;
    sincos(z.imag(), s, c);
    sinhcosh(z.real(), sh, ch);
    return COMPLEX160(c*ch, -s*sh);
}

COMPLEX160 sin(COMPLEX160 z)
{   FLOAT160 s, c, sh, ch;
    sincos(z.real(), s, c);
    sinhcosh(z.imag(), sh, ch);
    return COMPLEX160(s*ch, c*sh);
}

COMPLEX160 sinh(COMPLEX160 z)
{   FLOAT160 s, c, sh, ch;
    sincos(z.imag(), s, c);
    sinhcosh(z.real(), sh, ch);
    return COMPLEX160(c*sh, s*ch);
}

void sincos(COMPLEX160 x, COMPLEX160& s, COMPLEX160& c)
{   s = sin(x);
    c = cos(x);
}

void sinhcosh(COMPLEX160 x, COMPLEX160& s, COMPLEX160& c)
{   s = sinh(x);
    c = cosh(x);
}

COMPLEX160 exp(COMPLEX160 z)
{   FLOAT160 e, s, c;
    e = exp(z.real());
    sincos(z.imag(), s, c);
    return COMPLEX160(e*c, e*s);
}

COMPLEX160 expm1(COMPLEX160 z)
{   FLOAT160 e, s, c;
    if (z.real().abs() < 0.005_Q &&
        z.imag().abs() < 0.005_Q)
    {
// Here I want to compute just
//     -z^2/2 + z^4/24 - ... +z^12/12!
// and for the range I have here that will give me (cos z-1) correct to
// over 40 decimal places.
        COMPLEX160 z2 = z*z;
        COMPLEX160 z4 = z2*z2;
        COMPLEX160 z6 = z2*z4;
        COMPLEX160 z8 = z4*z4;
        COMPLEX160 z10 = z6*z4;
        COMPLEX160 z12 = z6*z6;
        COMPLEX160 cm1 =    // explcit brackets stress order of combination!
            ((((z12/479001600.0_Q -
                z10/3628800.0_Q) +
               z8/40320.0_Q) -
              z6/720.0_Q) +
             z4/24.0_Q) -
            z2/2.0_Q;
        e = expm1(z.real());
        sincos(z.imag(), s, c);
        return COMPLEX160(e*c, (1.0_Q+e)*s) + cm1;
    }
    e = expm1(z.real());
    sincos(z.imag(), s, c);
// The problem with using the generic version here is that for small real
// part of x it means that (cos(y)-1) must be computed accurately
// for small y. I think I could cross over |x|<0.005 which would mean that
// the result could be calculated as 1.005-1.0 when the simple formula
// was used, losing 7 or 8 bits. Well as against FLOAT128 I have 15 bits
// in hand so that would feel safe. Then the small case could be done
// with a simple taylor series or odre around 17 or 18, and since cos
// has an even series that would be 9 terms. At present I believe that
// a minimax approximation would not do any better.
    return COMPLEX160(e*c + (c-1.0_Q), (1.0_Q+e)*s);
}

COMPLEX160 cbrt(COMPLEX160 z)
{   COMPLEX160 r = fromcomplexlongdouble(
        std::pow(tocomplexlongdouble(z),
                 tocomplexlongdouble((FLOAT160)(1.0_Q/3.0_Q))));
    COMPLEX160 zz = z*z;
    r = z/(3.0_Q*zz) + (2.0_Q/3.0_Q)*z;
    return z/(3.0_Q*zz) + (2.0_Q/3.0_Q)*z;
}

COMPLEX160 sqrt(COMPLEX160 z)
{   COMPLEX160 r = fromcomplexlongdouble(std::sqrt(tocomplexlongdouble(z)));
// I now have a fairly plausible approxmation to my result. Long double
// will be based on at least 52-bit precision (and that case is the
// most plausible one that will leave me needing the code here, so I
// will work on that basis.
    r = 0.5_Q*(r + z/r);     // maybe 104 bits OK
    return 0.5_Q*(r + z/r);  // over 200 bits would be OK!
}

COMPLEX160 rsqrt(COMPLEX160 z)
{   COMPLEX160 r = fromcomplexlongdouble(
        std::sqrt(1.0L/tocomplexlongdouble(z)));
    r = 0.5_Q*r*(3.0_Q - z*r*r);
    return 0.5_Q*r*(3.0_Q - z*r*r);
}

// The functions here may end up being implemented based on the fact that
// they are inverses of things that are easier to compute. So I use long
// double and the standard function library and then use two steps of
// Newton Raphson to bring the result up to full precision.

COMPLEX160 acos(COMPLEX160 z)
{   COMPLEX160 r = fromcomplexlongdouble(
        std::acos(tocomplexlongdouble(z)));
    r = r + (cos(r) - z)/sin(r);
    return r + (cos(r) - z)/sin(r);
}
COMPLEX160 acosh(COMPLEX160 z)
{ return fromcomplexlongdouble(
    std::acosh(tocomplexlongdouble(z)));  }

COMPLEX160 asin(COMPLEX160 z)
{ return fromcomplexlongdouble(std::asin(tocomplexlongdouble(z)));   }

COMPLEX160 asinh(COMPLEX160 z)
{ return fromcomplexlongdouble(std::asinh(tocomplexlongdouble(z)));  }

COMPLEX160 atan(COMPLEX160 z)
{ return fromcomplexlongdouble(std::atan(tocomplexlongdouble(z)));   }

COMPLEX160 atanh(COMPLEX160 z)
{ return fromcomplexlongdouble(std::atanh(tocomplexlongdouble(z)));  }

COMPLEX160 ln(COMPLEX160 z)
{   FLOAT160 x = z.real();
    FLOAT160 y = z.imag();
    FLOAT160 r = x*x + y*y;
    return COMPLEX160(0.5_Q*ln(r), atan2(y, x));
}

COMPLEX160 log1p(COMPLEX160 z)
{   FLOAT160 x = z.real();
    FLOAT160 y = z.imag();
    FLOAT160 r = x*x + 2.0_Q*x + y*y;
    return COMPLEX160(0.5_Q*log1p(r), atan2(y, 1.0_Q+x));
}

COMPLEX160 log(COMPLEX160 z)
{   return ln(z);
}

COMPLEX160 log10(COMPLEX160 z)   // multiply by 1/log 10;
{   return ln(z)*0.434294481903251827651128918916605082294397_Q;
}

COMPLEX160 log2(COMPLEX160 z)    // multiply by 1/log 2
{   return ln(z)*1.44269504088896340735992468100189213742665_Q;
}

COMPLEX160 sec(COMPLEX160 z)
{   return recip(cos(z));
}

COMPLEX160 sech(COMPLEX160 z)
{   return recip(cosh(z));
}

COMPLEX160 tan(COMPLEX160 z)
{   COMPLEX160 s, c;
    sincos(z, s, c);
    return s/c;
}

COMPLEX160 tanh(COMPLEX160 z)
{   COMPLEX160 s, c;
    sinhcosh(z, s, c);
    return s/c;
}

// Review princial value issue here...

COMPLEX160 acot(COMPLEX160 z)
{   return atan(recip(z));
}

COMPLEX160 acoth(COMPLEX160 z)
{   return atanh(recip(z));
}

COMPLEX160 acsc(COMPLEX160 z)
{   return asin(recip(z));
}

COMPLEX160 acsch(COMPLEX160 z)
{   return asinh(recip(z));
}

COMPLEX160 asec(COMPLEX160 z)
{   return acos(recip(z));
}

COMPLEX160 asech(COMPLEX160 z)
{   return acosh(recip(z));
}

COMPLEX160 cot(COMPLEX160 z)
{   return recip(tan(z));
}

COMPLEX160 coth(COMPLEX160 z)
{   return recip(tanh(z));
}

COMPLEX160 csc(COMPLEX160 z)
{   return recip(sin(z));
}

COMPLEX160 csch(COMPLEX160 z)
{   return recip(sinh(z));
}

// Implementing x^y as exp(y log(x)) tends to lose accuracy - but here I am
// using a working precision that has 15 more bits than the COMPLEX128 which
// is what gets delivered to the end-users, and for at least a large
// fraction of interesting cases that will be sufficient to yield good
// results.

COMPLEX160 expt(COMPLEX160 x, COMPLEX160 y)
{   return exp(y*log(x));
}

// Note that in general I only let COMPLEX160 perform arithmetic between
// two values both of which are complex. However I do have an overload
// for COMPLEX160*FLOAT160 to support the code here.

COMPLEX160 expt(COMPLEX160 x, FLOAT160 y)
{   return exp(log(x)*y);
}

// I do not really think this is meaningful and I am liable to remove
// it in a while.

COMPLEX160 hypot(COMPLEX160 x, COMPLEX160 y)
{   return sqrt(x*x + y*y);
}

#endif // NEED_COMPLEX_MATHLIB

// Now delegate elementary functions on COMPLEX128 either to system-provided
// ones or to my own versions that use COMPLEX160.

#ifdef USE_LONG_DOUBLE

#define delegateC128(fn, base)                         \
COMPLEX128 fn(COMPLEX128 z)                            \
{   std::cout << #base << " " << z << "\n";            \
    std::complex<long double> v(                       \
        (long double)z.real(), (long double)z.imag()); \
    v = base(v);                                       \
    std::cout << "=> " << v << "\n";                   \
    return COMPLEX128(v.real(), v.imag());             \
}


delegateC128(acos,   std::acos)
delegateC128(acosh,  std::acosh)
delegateC128(asin,   std::asin)
delegateC128(asinh,  std::asinh)
delegateC128(atan,   std::atan)
delegateC128(atanh,  std::atanh)
delegateC128(cos,    std::cos)
delegateC128(cosh,   std::cosh)
delegateC128(exp,    std::exp)
delegateC128(ln,     std::log)
delegateC128(log,    std::log)
delegateC128(log10,  std::log10)
delegateC128(sin,    std::sin)
delegateC128(sinh,   std::sinh)
delegateC128(sqrt,   std::sqrt)
delegateC128(tan,    std::tan);
delegateC128(tanh,   std::tanh)

#define delegatebinaryC128(fn, base)                         \
COMPLEX128 fn(COMPLEX128 y, COMPLEX128 z)                            \
{   std::complex<long double> u(                       \
        (long double)y.real(), (long double)y.imag()); \
    std::complex<long double> v(                       \
        (long double)z.real(), (long double)z.imag()); \
    v = base(u, v);                                       \
    return COMPLEX128(v.real(), v.imag());             \
}

delegatebinaryC128(expt,  std::pow)

// The following are not directly supported in C++ for complex arguments.

std::complex<long double> cbrt(std::complex<long double> z)
{   return std::pow(z, 1.0L/3.0L);
}

std::complex<long double> expm1(std::complex<long double> z)
{   return std::exp(z) - 1.0L;
}

std::complex<long double> log1p(std::complex<long double> z)
{   return std::log(z + 1.0L);
}

std::complex<long double> log2(std::complex<long double> z)
{   return std::log(z) * 1.44269504088896340735992468100189213742665L;
}

delegateC128(cbrt,        cbrt)
delegateC128(expm1,       expm1)
delegateC128(log1p,       log1p)
delegateC128(log2,        log2)

// frexp, ldexp, modf, exp2, ilogb, logb, scalbn, erf. erfc, tgamma, lgamma,
// ceil, floor, fmod, trunc, round, lround, rint, lrint, bearbyint, remainder,
// remquo, copysign, nextafter, nexttoward, fdim, fmax, fmin, abs, mfa,

#undef delegateC128

#endif // USE_LONG_DOUBLE

#ifdef USE_QUADMATH

#define delegateC128(fn, base)                             \
COMPLEX128 fn(COMPLEX128 z)                                \
{   __complex128 v =                                       \
        {((__float128)z.real()), ((__float128)z.imag())};  \
    v = base(v);                                           \
    return COMPLEX128(crealq(v), cimagq(v));               \
}

delegateC128(acos,   cacosq)
delegateC128(acosh,  cacoshq)
delegateC128(asin,   casinq)
delegateC128(asinh,  casinhq)
delegateC128(atan,   catanq)
delegateC128(atanh,  catanhq)
delegateC128(cos,    ccosq)
delegateC128(cosh,   ccoshq)
delegateC128(exp,    cexpq)
delegateC128(ln,     clogq)
delegateC128(log,    clogq)
delegateC128(log10,  clog10q)
delegateC128(sin,    csinq)
delegateC128(sinh,   csinhq)
delegateC128(sqrt,   csqrtq)
delegateC128(tan,    ctanq);
delegateC128(tanh,   ctanhq)

#define delegatebinaryC128(fn, base)                  \
COMPLEX128 fn(COMPLEX128 y, COMPLEX128 z)             \
{   __complex128 u = {                                \
        (__float128)y.real(), (__float128)y.imag()};  \
    __complex128 v = {                                \
        (__float128)z.real(), (__float128)z.imag()};  \
    v = base(u, v);                                   \
    return COMPLEX128(crealq(v), cimagq(v));          \
}

delegatebinaryC128(expt, cpowq)

// The following are not directly supported in C++ for complex arguments.

__complex128 cbrt(__complex128 z)
{   return cpowq(z, 1.0Q/3.0Q);
}

__complex128 expm1(__complex128 z)
{   return cexpq(z) - 1.0Q;
}

__complex128 log1p(__complex128 z)
{   return clogq(z + 1.0Q);
}

__complex128 log2(__complex128 z)
{   return clogq(z) * 1.44269504088896340735992468100189213742665Q;
}

// I am not fussing about underflow or overflow here since this is
// really not a very sensible function when used on complex  values.

__complex128 hypot(__complex128 x,
                   __complex128 y)
{   return csqrtq(x*x + y*y);
}

delegateC128(cbrt,        cbrt)
delegateC128(expm1,       expm1)
delegateC128(log1p,       log1p)
delegateC128(log2,        log2)

// frexp, ldexp, modf, exp2, ilogb, logb, scalbn, erf. erfc, tgamma, lgamma,
// ceil, floor, fmod, trunc, round, lround, rint, lrint, bearbyint, remainder,
// remquo, copysign, nextafter, nexttoward, fdim, fmax, fmin, abs, mfa,

#undef delegateC128

#endif // USE_QUADMATH

#if defined USE_CLANG_FLOAT128 || defined USE_CXX23_FLOAT128 || defined USE_SOFT_FLOAT128

#define delegateC128(fn, base)                                 \
COMPLEX128 fn(COMPLEX128 z)                                    \
{   COMPLEX160 v((FLOAT160)z.real(), (FLOAT160)z.imag());      \
    v = base(v);                                               \
    return COMPLEX128((FLOAT128)v.real(), (FLOAT128)v.imag()); \
}

delegateC128(acos,   acos)
delegateC128(acosh,  acosh)
delegateC128(asin,   asin)
delegateC128(asinh,  asinh)
delegateC128(atan,   atan)
delegateC128(atanh,  atanh)
delegateC128(cos,    cos)
delegateC128(cosh,   cosh)
delegateC128(exp,    exp)
delegateC128(ln,     log)
delegateC128(log,    log)
delegateC128(log10,  log10)
delegateC128(sin,    sin)
delegateC128(sinh,   sinh)
delegateC128(sqrt,   sqrt)
delegateC128(tan,    tan);
delegateC128(tanh,   tanh)

delegateC128(cbrt,        cbrt)
delegateC128(expm1,       expm1)
delegateC128(log1p,       log1p)
delegateC128(log2,        log2)

#define delegatebinaryC128(fn, base)                           \
COMPLEX128 fn(COMPLEX128 y, COMPLEX128 z)                      \
{   COMPLEX160 u((FLOAT160)y.real(), (FLOAT160)y.imag());      \
    COMPLEX160 v((FLOAT160)z.real(), (FLOAT160)z.imag());      \
    v = base(u, v);                                            \
    return COMPLEX128((FLOAT128)v.real(), (FLOAT128)v.imag()); \
}

delegatebinaryC128(expt,  expt)

// frexp, ldexp, modf, exp2, ilogb, logb, scalbn, erf. erfc, tgamma, lgamma,
// ceil, floor, fmod, trunc, round, lround, rint, lrint, bearbyint, remainder,
// remquo, copysign, nextafter, nexttoward, fdim, fmax, fmin, abs, mfa,

#endif // USE_CLANG_FLOAT128 || USE_CXX23_FLOAT128 || USE_SOFT_FLOAT128

// The next bunch of functions are always merely derived

COMPLEX128 recip(COMPLEX128 z)
{   return COMPLEX128(LF_C(1.0), LF_C(0.0))/z;
}

// Review principal values here...

COMPLEX128 acot(COMPLEX128 z)
{   return atan(recip(z));
}

COMPLEX128 acoth(COMPLEX128 z)
{   return atanh(recip(z));
}

COMPLEX128 acsc(COMPLEX128 z)
{   return asin(recip(z));
}

COMPLEX128 acsch(COMPLEX128 z)
{   return asinh(recip(z));
}

COMPLEX128 asec(COMPLEX128 z)
{   return acos(recip(z));
}

COMPLEX128 asech(COMPLEX128 z)
{   return acosh(recip(z));
}

COMPLEX128 cot(COMPLEX128 z)
{   return recip(tan(z));
}

COMPLEX128 coth(COMPLEX128 z)
{   return recip(tanh(z));
}

COMPLEX128 csc(COMPLEX128 z)
{   return recip(sin(z));
}

COMPLEX128 csch(COMPLEX128 z)
{   return sinh(z);
}

COMPLEX128 sec(COMPLEX128 z)
{   return recip(cos(z));
}

COMPLEX128 sech(COMPLEX128 z)
{   return recip(cosh(z));
}

COMPLEX128 rsqrt(COMPLEX128 z)
{   return recip(sqrt(z));
}

#undef delegateC128
#undef delegatebinaryC128

// end of elem128.cpp
