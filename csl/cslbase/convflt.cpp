// conflt.cpp                                     Copyright A C Norman 2026


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

// $Id$

#include "arithlib.h"
#include <climits>

namespace arithlib_implementation
{

// When doubles and FLOAT_128 values where available are to be
// compared against a bignum to get proper results the double should
// (at least in effect) be converted to a bignum. If one does the comparison
// by converting both inputs to floating point (which may feel easier) there
// are multiple problems. First the bignum might have a value outside
// the range of floats, so you get overflow. Then it might differ from
// a float in a bit position several hundred betlow its most significant
// one, and converting to a float would lose that information.

// doubleToBits() turns a floating point value into an integer plus
// an exponent. It sets mantissa*2^exponent = d. This function will not
// give sensible output if passed an infinity or a NaN and so they should be
// filtered out before it is called.

inline void doubleToBits(double d, SignedDigit &mantissa, int &exponent)
{   if (d == 0.0)
    {   mantissa = 0;
        exponent = 0;
        return;
    }
    int x;
    d = std::frexp(d, &x);
// now |d| is in the range [0.5,1) -- note closed at the 0.5 end and open
// at the other. And x is the power of 2 that the original input was scaled
// by to achieve this.
    d = d*9007199254740992.0; // 2^53;
// The conversion to an integer here will always be exact.
    mantissa = static_cast<SignedDigit>(d);
    exponent = x - 53;
}

// For FLOAT_128 the mantissa needs to be returned as a 128-bit integer, and
// I do that as a pair of 64-bit integers here. Infinities and NaNs would
// lead to nonsense output. Subnormal numbers are got wrong at present!

void longfloatToBits(FLOAT_128 d,
                     SignedDigit &mhi, Digit &mlo,
                     int &exponent)
{   if (isnan(d) || d == LF_C(0.0))
    {   mhi = mlo = 0;
        exponent = 0;
        return;
    }
    else if (isinf(d))
    {   if (d < LF_C(0.0)) mhi = mlo = -1;
        else mhi = mlo = 0;
        exponent = INT_MAX;
        return;
    }
// With FLOAT_128 the easier way to go is to access the bit-patterns.
    uint64_t HIPART, LOPART;
    d.getbits(HIPART, LOPART);
    exponent = (HIPART >> 48) & 0x7fff;
    if (exponent == 0) // subnormal number
    {   d = d * f128_N1;
        exponent -= 4096;
    }
    exponent -= 0x3ffe;
    mhi = (HIPART & 0xffffffffffff) | 0x0001000000000000;
    mlo = LOPART;
    if ((HIPART>>63) != 0)
    {   mlo = -mlo;
        if (mlo == 0) mhi = -mhi;
        else mhi = ~mhi;
    }
    exponent -= 113;
}

inline void doubleTo_virtualBignum(double d,
                                   SignedDigit& top, Digit& next,
                                   std::size_t& len,
                                   RoundingMode mode)
{   if (d == 0.0)
    {   top = next = 0;
        len = 1;
        return;
    }
// NaN leads to a returned value with zero length. Having a zero length
// for a bignum is invalid, so this marks the situation well.
    else if (std::isnan(d))
    {   top = next = 0;
        len = 0;
        return;
    }
// Infinties turn into values with maximum length and a top digit that
// captures the sign of the input.
    if (std::isinf(d))
    {   top = d < 0.0 ? -1 : 1;
        next = 0;
        len = SIZE_MAX;
        return;
    }
// If the (absolute) value is less than 2^53 I will need to consider
// rounding, but the result would not need multiple bignum digits and I
// can work with it here using simple 64-bit integers. But I will
// need to consider rounding modes since there could be a significant
// fractional part.
    if (d >= -2.0/DBL_EPSILON && d <= 2.0/DBL_EPSILON)
    {   int64_t i = static_cast<int64_t>(d);           // can leave a fraction
        double fracpart = d - static_cast<double>(i);  // will be exact
        if (fracpart != 0.0)
        {   switch (mode)
            {   case ROUND:
                    if (fracpart > 0.5 ||
                        (fracpart == 0.5 && (i&1) != 0)) i++;
                    else if (fracpart < -0.5 ||
                        (fracpart == -0.5 && (i&1) != 0)) i--;
                    break;
                case TRUNC:  // already truncated
                    break;
                case FLOOR:
                    if (d < 0.0) i--;
                    break;
                case CEILING:
                    if (d > 0.0) i++;
                    break;
            }
        }
        top = i;
        next = 0;
        len = 1;
        return;
    }
// From here down I do not need to worry about zero, infinity or NaNs,
// and there will be no rounding!
    SignedDigit mantissa;
    int exponent;
    doubleToBits(d, mantissa, exponent);
// Now I know intpart(d) = mantissa*2^exponent and mantissa is an integer.
    Digit lowbit = mantissa & -static_cast<Digit>(mantissa);
    int lz = 63 - nlz(lowbit); // low zero bits
    mantissa = mantissa >> lz;
    exponent += lz;
// Now mantissa has its least significant bit a "1".
    next = static_cast<Digit>(mantissa);
    top = d<0.0 && mantissa!=0 ? -1 : 0;
    if (exponent < 0)
    {   top = 0;
        len = 1;
    }
    else
    {   len = 2 + exponent/64;
        exponent = exponent%64;
// Now shift left by exponent, which is less than 64 here.
        shiftleft(top, next, exponent);
// In some cases this has still left all the bits I care about in next,
// with top not needed, so in such cases I will shrink by a word.
        if (shrinkable(top, next))
        {   top = next;
            next = 0;
            len--;
        }
        if (len <= 0)       // small enough that fixed part is zero.
        {   top = next = 0;
            len = 1;
        }
    }
}
inline void longfloatTo_virtualBignum(FLOAT_128 d,
                                     SignedDigit& top,
                                     Digit& mid,
                                     Digit& next,
                                     std::size_t& len,
                                     RoundingMode mode)
{   using namespace CSL_LISP;
    if (d == LF_C(0.0))
    {   top = mid = next = 0;
        len = 1;
        return;
    }
    else if (isnan(d))
    {   top = mid = next = 0;
        len = 0;
        return;
    }
    else if (isinf(d))
    {   if (d < LF_C(0.0)) top = mid = next = -1;
        else top = mid = next = 0;
        len = SIZE_MAX;
        return;
    }
    bool sign = d < LF_C(0.0);
    SignedDigit mhi;
    Digit mlo;
    int exponent;
    longfloatToBits(d, mhi, mlo, exponent);
// Here (mhi,mlo) is a 113-bit integer that must be multiplied by
// 2^exponent to yield the input value.
    uint128_t mantissa = (static_cast<uint128_t>(mhi)<<64) | mlo;
    if (exponent < 0)   // There is a fractional part to consider  
    {
// The number might have been well 
        uint128_t fracpart = exponent  < -113 ? static_cast<uint128_t>(1)
                                              : mantissa << (113+exponent);
        switch (mode)
        {   case ROUND:
                if (fracpart > 0x8000000000000000ULL ||
                    (fracpart == 0x8000000000000000 &&
                     (mantissa&1) != 0)) mantissa++;
                break;
            case TRUNC:  // the effect of modf is this already.
                break;
            case FLOOR:
                if (fracpart != 0 && d < LF_C(0.0)) mantissa++;
                break;
            case CEILING:
                if (fracpart != 0 && d >= LF_C(0.0)) mantissa++;
                break;
        }
        if (sign) mantissa = -mantissa;
        top = static_cast<int64_t>(mantissa>>64);
        mid = static_cast<uint64_t>(mantissa);
        next = 0;
        len = 2;
        if (shrinkable(top, next))
        {   top = next;
            next = 0;
            len--;
        }        
        return;
    }
    int lz;
    if (mlo != 0)
    {   Digit lowbit = mlo & (-mlo);
        lz = 63 - nlz(lowbit); // low zero bits
    }
    else
    {   Digit lowbit = mhi & (-static_cast<Digit>(mhi));
        lz = 64 + 63 - CSL_LISP::nlz(lowbit); // low zero bits
    }
    shiftright(mhi, mlo, lz);
    exponent += lz;
// Now I need to shift things left so that the number of trailing zeros
// to the right of my value is a multiple of 64. That may cause the
// mantissa to spread into parts of 3 words: (top, mid, next).
    next = mlo;
    mid = mhi;
    top = mhi<0 ? -1 : 0;
    if (exponent < 0)
    {   top = 0;
        len = 1;
    }
    else
    {   len = 3 + exponent/64;
        exponent = exponent%64;
        shiftleft(top, mid, next, exponent);
// In some cases this has still left all the bits I care about in next.
        if (shrinkable(top, mid))
        {   top = mid;
            mid = next;
            next = 0;
            len--;
        }
        if (shrinkable(top, mid))
        {   top = mid;
            mid = next;
            next = 0;
            len--;
        }
    }
}

inline std::intptr_t doubleToInt(double d, RoundingMode mode)
{
// I return 0 if the input is a NaN or either +infinity or -infinity.
// This is somewhat arbitrary, but right now I am not minded to raise an
// exception.
    if (!std::isfinite(d) || d==0.0) return intToHandle(0);
    SignedDigit top;
    Digit next;
    std::size_t len;
    doubleTo_virtualBignum(d, top, next, len, mode);
    std::uint64_t* r = reserve(len);
    if (len == 1) r[0] = top;
    else
    {   for (std::size_t i=0; i<len-2; i++) r[i] = 0;
        r[len-1] = top;
        r[len-2] = next;
    }
    return confirmSize(r, len, len);
}

inline std::intptr_t longfloatToInt(FLOAT_128 d, RoundingMode mode)
{   if (d == LF_C(0.0) ||
        isinf(d) ||
        isnan(d)) return intToHandle(0);
    SignedDigit top;
    Digit mid, next;
    std::size_t len;
    longfloatTo_virtualBignum(d, top, mid, next, len, mode);
    std::uint64_t* r = reserve(len);
    if (len == 1) r[0] = top;
    else if (len == 2)
    {   r[1] = top;
        r[0] = mid;
    }
    else
    {   for (std::size_t i=0; i<len-3; i++) r[i] = 0;
        r[len-1] = top;
        r[len-2] = mid;
        r[len-3] = next;
    }
    return confirmSize(r, len, len);
}

inline float castTo_float(double d)
{
// If the argument is a NaN then return a NaN of type float.
    if (std::isnan(d)) return std::nanf("");
// In C++ a narrowing cast here where the result would be out of range gives
// undefined behaviour, so I need to filter that case first. I am going
// to allow double values that are up to FLT_MAX*(1+2^(-24)) to round
// down to FLT_MAX - beyond that lies overflow reported as HUGE_VALF which
// on all modern systems will be an IEEE infinity.
    double limit = static_cast<double>(FLT_MAX) +
                   static_cast<double>(FLT_MAX) /
                   static_cast<double>(0x1000000);
    if (d >= limit) return HUGE_VALF;
    else if (d <= -limit) return -HUGE_VALF;
    else if (d >= static_cast<double>(FLT_MAX)) return FLT_MAX;
    else if (d <= static_cast<double>(FLT_MIN)) return FLT_MIN;
// Now I am not going to get any overflow - whew.
    float r1 = static_cast<float>(d);
// If the conversion was exact I do not have anything more to do!
    if (static_cast<double>(r1) == d) return r1;
    double err1 = static_cast<double>(r1) - d;
    float r2;
    double err2;
// Now I am going to find the next consecutive floating point value (in
// the correct direction) so that r1 and r2 are two values with d between
// them.
    if (err1 > 0.0)
    {   r2 = std::nextafterf(r1, FLT_MIN);
        err2 = d - static_cast<double>(r2);
    }
    else
    {   r2 = std::nextafterf(r1, FLT_MAX);
        err2 = static_cast<double>(r2) - d;
        err1 = -err1;
    }
    if (err1 < err2) return r1;
    else if (err2 < err1) return r2;
// Here I am at a half-way point. Hah - can add my error to a candidate
// result and the rounding there will then follow the "rounding style" that
// is in force - which I jolly well expect to be IEEE!
    return (r1 < r2 ? r1 : r2) + static_cast<float>(err1);
}
inline float Float::op(SignedDigit a)
{
// if |a| < 2^52 I can convert to a double exactly
    if (a > -0x10000000000000 && a < 0x10000000000000)
        return castTo_float(static_cast<double>(a));
    SignedDigit hi  = a & 0xfffffc0000000000;   // 22 bits
    SignedDigit mid = a & 0x000003fffff00000;   // 22 bits
    SignedDigit lo  = a & 0x00000000000fffff;   // 20 bits
    if (hi == 0 || hi == 0xfffffc000000000)
        return castTo_float(static_cast<double>(hi) +
                             static_cast<double>(mid) + static_cast<double>(lo));
// This next line will move a ">0.5ulp" case so that it is visible
// within just the high 44 bits.  This is because the whole number can
// only be a 0.5ulp case if all the bits below the top 24 are zero, and
// for that to happen certainly the low 20 bits must all be zero...
    if (lo != 0) mid |= 1;
    return castTo_float(static_cast<double>(hi) +
                         static_cast<double>(mid));
}

inline float Float::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Float::op(static_cast<SignedDigit>(a[0]));
// Now I need to do something similar to that done for the int64_t case
// but written larger. Specifically I want to split my input number into
// its top 24 bits and then all the rest. I will take separate paths
// for the positive and negative cases.
    Digit top24;
    int lz;
    bool sign = false;
    Digit top, next;
    bool carried = true;
    for (std::size_t i=0; i<lena-2; i++)
    {   if (a[i] != 0)
        {   carried = false;
            break;
        }
    }
// Grap the top 128 bits of the number as {top,next}.
    top = a[lena-1];
    next = a[lena-2];    // lena >= 2 here
// Take its absolute value.
    if (negative(top))
    {   sign = true;
        top = ~top;
        next = ~next;
        if (carried)
        {   next++;
            if (next == 0) top++;
        }
    }
    if (!carried) next |= 1;
// Now I need to do something very much like the code for the int64_t case.
    if (top == 0) lz = CSL_LISP::nlz(next) + 64;
    else lz = CSL_LISP::nlz(top);
//
//  uint64_t top24 = {top,next} >> (128-24-lz);
    int sh = 128-24-lz;
// Note that sh can never be zero here.
    if (sh < 64) top24 = (next >> sh) | (top << (64-sh));
    else top24 = top >> (sh-64);
//
//  {top,next} = {top,next} << lz+24; // keep only the fraction bits
    sh = lz+24;
    if (sh < 64)
    {   top = (top << sh) | (next >> (64-sh));
        next = next << sh;
    }
    else
    {   top = next << (sh - 64);
        next = 0;
    }
//
//  if ({top,next} > 0x80000000000000000000000000000000U) top24++;
//  else if ({top,next} == 0x80000000000000000000000000000000U)
//      top24 += (top24 & 1);
    if (top > 0x8000000000000000U) top24++;
    else if (top == 0x8000000000000000U)
    {   if (next != 0) top24++;
        else top24 += (top24&1);
    }
    double d = static_cast<float>(top24);
    if (sign) d = -d;
    return ldexpf(d, static_cast<int>(128-24-lz+64*(lena-2)));
}

inline double Frexp::op(SignedDigit a, SignedDigit& x)
{
// The bad news here is that I am not confident that C++ will guarantee
// to round large integer values in any particular way when it converts
// them to floating point. So I will take careful action so that the
// conversions that I do are ones that will be exact, and I will perform
// rounding in IEEE style myself.
// First I will see if the value is small enough that I can work directly.
    const SignedDigit range = 1LL<<53;
    if (a >= -range && a <= range) return static_cast<double>(a);
// I will now drop down to a sign and magnitude representation
    bool sign = a < 0;
    Digit top53 = sign ? -static_cast<Digit>(a) : a;
// Because top53 >= 2^53 the number of leading zeros in its representation is
// at most 10. Ha ha. That guaranteed that the shift below will not overflow
// and is why I chose my range as I did.
    int lz = CSL_LISP::nlz(top53);
    Digit low = top53 << (lz+53);
    top53 = top53 >> (64-53-lz);
    if (low > 0x8000000000000000U) top53++;
    else if (low == 0x8000000000000000U) top53 += (top53 &
                1); // round to even
// The next line should never introduce any rounding at all.
    double d = static_cast<double>(top53);
    if (sign) d = -d;
    x =64-53-lz;
    return d;
}

inline double Double::op(SignedDigit a)
{
// One would obviously like to go "return (double)a;" however C++ says
//  "If the value being converted is in the range of values that can
//   be represented but the value cannot be represented exactly, it is
//   an implementation-defined choice of either the next lower or higher
//   representable value."
// and I feel I should guarantee to round in IEEE style. I can do that
// by splitting the integer into two parts. Each of the two casts can deliver
// a double precision result without need for rounding
    SignedDigit hi = a & 0xffffffff00000000;
    SignedDigit lo = a & 0x00000000ffffffff;
    double d = static_cast<double>(lo);
    return d + static_cast<double>(hi);
}

inline double Frexp::op(std::uint64_t* a, SignedDigit& x)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Frexp::op(static_cast<SignedDigit>(a[0]), x);
// Now I need to do something similar to that done for the int64_t case
// but written larger. Specifically I want to split my input number into
// its top 53 bits and then all the rest. I will take separate paths
// for the positive and negative cases.
    Digit top53;
    int lz;
    bool sign = false;
    Digit top, next;
    bool carried = true;
    for (std::size_t i=0; i<lena-2; i++)
    {   if (a[i] != 0)
        {   carried = false;
            break;
        }
    }
// Grap the top 128 bits of the number as {top,next}.
    top = a[lena-1];
    next = a[lena-2];    // lena >= 2 here
// Take its absolute value.
    if (negative(top))
    {   sign = true;
        top = ~top;
        next = ~next;
        if (carried)
        {   next++;
            if (next == 0) top++;
        }
    }
    if (!carried) next |= 1;
// Now I need to do something very much like the code for the int64_t case.
    if (top == 0) lz = CSL_LISP::nlz(next) + 64;
    else lz = CSL_LISP::nlz(top);
//
//  uint64_t top53 = {top,next} >> (128-53-lz);
    int sh = 128-53-lz;
// Note that sh can never be zero here.
    if (sh < 64) top53 = (next >> sh) | (top << (64-sh));
    else top53 = top >> (sh-64);
//
//  {top,next} = {top,next} << lz+53; // keep only the fraction bits
    sh = lz+53;
    if (sh < 64)
    {   top = (top << sh) | (next >> (64-sh));
        next = next << sh;
    }
    else
    {   top = next << (sh - 64);
        next = 0;
    }
//
//  if ({top,next} > 0x80000000000000000000000000000000U) top53++;
//  else if ({top,next} == 0x80000000000000000000000000000000U)
//      top53 += (top53 & 1);
    if (top > 0x8000000000000000U) top53++;
    else if (top == 0x8000000000000000U)
    {   if (next != 0) top53++;
        else top53 += (top53&1);
    }
    double d = static_cast<double>(top53);
    if (sign) d = -d;
    x = 128-53-lz+64*(lena-2);
    return d;
}

inline double Double::op(std::uint64_t* a)
{   SignedDigit x = 0;
    double d = Frexp::op(a, x);
    if (x > 10000) x = 10000;
    return std::ldexp(d, static_cast<int>(x));
}

inline FLOAT_128 Float128::op(SignedDigit a)
{   return (FLOAT_128)a;
}

inline FLOAT_128 Frexp128::op(SignedDigit a, SignedDigit& x)
{   using namespace CSL_LISP;
    FLOAT_128 d = (FLOAT_128)a;
    int x1;
    d = frexp(d, x1);
    x = x1;
    return d;
}

inline FLOAT_128 Frexp128::op(std::uint64_t* a, SignedDigit& x)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Float128::op(static_cast<SignedDigit>(a[0]));
    Digit top113, top113a;
    int lz;
    bool sign = false;
    Digit top, next1, next2;
    bool carried = true;
    for (std::size_t i=0; i<lena-3; i++)
    {   if (a[i] != 0)
        {   carried = false;
            break;
        }
    }
// Grap the top 192 bits of the number as {top,next}.
    top = a[lena-1];
    next1 = a[lena-2];
    next2 = lena==2 ? 0 : a[lena-3];
// Take its absolute value.
    if (negative(top))
    {   sign = true;
        top = ~top;
        next1 = ~next1;
        next2 = ~next2;
        if (carried)
        {   next2++;
            if (next2 == 0)
            {   next1++;
                if (next1 == 0) top++;
            }
        }
    }
    if (!carried) next2 |= 1;
// I now have {top,next1,next2} the top 192 bits of my integer. top may be
// zero, but if it is then next1 will have its top bit set, and so within
// these bits I certainly have the 113 that I need to obtain an accurate
// floating point value.
    if (top == 0) lz = CSL_LISP::nlz(next1) + 64;
    else lz = CSL_LISP::nlz(top);
//
//  uint64_t {top113,top112a} = {top,next1,next2} >> (128-113-lz);
    int sh = 192-113-lz;
// Note that sh can never be zero here.
    if (sh < 64)
    {   top113 = (next1 >> sh) | (top << (64-sh));
        top113a = (next2 >> sh) | (next1 << (64-sh));
    }
    else
    {   top113 = top >> (sh-64);
        top113a = (next1 >> (sh-64)) | (top << (128-sh));
    }
//
//  {top,next} = {top,next} << lz+113; // keep only the fraction bits
    sh = lz+113;
    if (sh < 64)
    {   top = (top << sh) | (next1 >> (64-sh));
        next1 = (next1 << sh) | (next2 >> (64-sh));
        next2 = next2 << sh;
    }
    else
    {   top = next1 << (sh - 64);
        next1 = (next1 << (sh-64)) | (next2 >> (129-sh));
        next2 = 0;
    }
//
//  if ({top,next1,next2} > 0x80000000000000000000000000000000U) top113++;
//  else if ({top,next1, next2} == 0x80000000000000000000000000000000U)
//      top113 += (top113 & 1);
    if (top > 0x8000000000000000U)
    {   top113a++;
        if (top113a == 0) top113++;
    }
    else if (top == 0x8000000000000000U)
    {   if (next1 != 0 || (next1==0 && next2!=0))
        {   top113a++;
            if (top113a == 0) top113++;
        }
        else top113 += addWithCarry(top113a, top113a&1, top113a);
    }
//  FLOAT_128 d = i64_to_f128({top113, top113a});
    FLOAT_128 d = (FLOAT_128)top113;
    FLOAT_128 two32 = (FLOAT_128)(uint64_t)0x100000000;
    d = two32 * two32 * d + (FLOAT_128)top113a;
    if (sign) d = - d;
    x = 192-113-lz+64*(lena-2);
    return d;
}

inline FLOAT_128 Float128::op(std::uint64_t* a)
{   using namespace CSL_LISP;
    SignedDigit x = 0;
    FLOAT_128 d = Frexp128::op(a, x);
    if (x > 100000) x = 100000;
    return ldexp(d, static_cast<int>(x));
}

}; // end of namespace

// end of convflt.cpp
