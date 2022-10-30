// arith-random.cpp                        Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

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

// $Id$

// This is "random" in two senses! It contains some oddments of stray
// functions, but also the ones that return random and pseudo-random
// numbers.


#include "headers.h"

LispObject N_make_power_of_two(size_t n)
//
// Create the number 2^n where n is positive.  Used to make the
// denominator float of a rational representation of a float.  Some fun
// to cope with various small cases before I get to the general call
// to make_n_word_bignum.
//
{   if (n < 64) return make_lisp_unsigned64((uint64_t)1 << n);
    else return Nleftshift(nil, fixnum_of_int(1), fixnum_of_int(n));
}

LispObject N_make_fix_or_big2(int32_t a1, uint32_t a2)
{   return make_lisp_integer64(((int64_t)a1 << 31) | a2);
}

// N_double_to_binary returns an integer exponent and sets m such that the
// original float is equal to m*2^x. It returns special values for x in the
// case of infinities and NaNs.

int N_double_to_binary(double d, int64_t& m)
{   if (std::isnan(d))
    {   m = 0;
        return INT_MIN;
    }
    else if (std::isinf(d))
    {   m = (d < 0.0) ? -1 : 1;
        return INT_MAX;
    }
    else if (d == 0.0)
    {   m = 0;   // I lose information about +0.0 vs -0.0 here
        return 0;
    }
    int x;
    d = std::frexp(d, &x);
// now d is in the range +/-[0/5, 1) and the input had value d*2^x
    m = static_cast<int64_t>(d*4503599627370496.0); // 2.0^52
    return x - 52;
}

#ifdef HAVE_SOFTFLOAT
// This does much the same for 128-bit floats.

int N_float128_to_binary(const float128_t *d, int64_t& mhi, uint64_t& mlo)
{   uint64_t hi = d->v[HIPART];
    uint64_t lo = d->v[LOPART];
    int x = static_cast<int>(hi >> 48) & 0x7fff;
    uint64_t fhi = hi & UINT64_C(0x0000ffffffffffff);
    if (x != 0) fhi |= UINT64_C(0x0001000000000000);
    if ((int64_t)hi < 0)  // Now negate the mantissa
    {   fhi = ~fhi;
        lo = ~lo;
        if (lo == UINT64_C(0xffffffffffffffff))
        {   lo = 0;
            fhi++;
        }
        else lo++;
    }
    mhi = fhi;
    mlo = lo;
    if (x == 0x7fff) return fhi==0 && lo == 0 ? INT_MAX : INT_MIN;
    return x - 0x3fff - 112;
}
#endif // HAVE_SOFTFLOAT

// The following can be used in lisp_fix and in comparisons between
// floats and bignums. It return three 31-bit digits that would be the top
// 3 words of representation in terms of 31-bit digits, together with
// the number of such digits that would be used. That is all because in
// an older version of CSL my bignums used 31-bit digits. For many
// purposes the split here is still useful.

intptr_t N_double_to_3_digits(double d, int32_t& a2, uint32_t& a1, uint32_t& a0)
{   int64_t m;
    int x = N_double_to_binary(d, m);
    a0 = (uint32_t)m & 0x7fffffffU;
    a1 = (uint32_t)((uint64_t)m >> 31) & 0x7fffffff;
    a2 = (int32_t)ASR(m, 62);   // In fact value should be either 0 or -1
    // because m is only a 53 bit + sign value.
    if (x == 0x7ff) return INTPTR_MAX;
// Now I need to adjust in effect so that the exponent is treated as
// a multiple of 31.
    int q = x/31, r = x%31;
    if (r < 0)
    {   q--;
        r += 31;
    }
// I now shift the 3-digit value left by r bits. It will not overflow.
    if (r != 0)
    {   a2 = ((uint32_t)a2<<r) | a1>>(31-r);
        a1 = ((a1<<r) & 0x7fffffffU) | a0>>(31-r);
        a0 = (a0<<r) & 0x7fffffffU;
    }
// At this stage it is possible that a2 is 0 or -1 and a1 does not
// intrude into its most significant place, in which case the bignum
// could have afforded to use one fewer digits.
    if ((a2 == 0 && (a1 & 0x40000000U) == 0) ||
        (a2 == -1 && (a1 & 0x40000000U) != 0))
    {   a2 = a1 | ((a1 & 0x40000000U)<<1);
        a1 = a0;
        a0 = 0;
        q--;
// Further to the above, a number that was originally sub-normalized can
// still suffer in the same manner. So I will do the same again!
        if ((a2 == 0 && (a1 & 0x40000000U) == 0) ||
            (a2 == -1 && (a1 & 0x40000000U) != 0))
        {   a2 = a1 | ((a1 & 0x40000000U)<<1);
            a1 = a0;
            a0 = 0;
            q--;
        }
    }
    return q;
}

#ifdef HAVE_SOFTFLOAT

intptr_t N_float128_to_5_digits(float128_t *d,
             int32_t& a4, uint32_t& a3, uint32_t& a2,
             uint32_t& a1, uint32_t& a0)
{   int64_t mhi;
    uint64_t mlo;
    int x = N_float128_to_binary(d, mhi, mlo);
    a0 = (uint32_t)mlo & 0x7fffffffU;
    a1 = (uint32_t)((uint64_t)mlo >> 31) & 0x7fffffff;
    a2 = (((uint32_t)mhi << 2) & 0x7fffffff) | (uint32_t)(mlo>>62);
    a3 = (uint32_t)(mhi>>29);
    a4 = (int32_t)ASR(mhi, 60);   // again either 0 or -1
    if (x == 0x7fff) return INTPTR_MAX;
    int q = x/31, r = x%31;
    if (r < 0)
    {   q--;
        r += 31;
    }
    if (a4 == 0 && a3 == 0 && a2 == 0 && a1 == 0 && a0 == 0) return q;
    if (r != 0)
    {   a4 = (int32_t)(((uint32_t)a4<<r) | a3>>(31-r));
        a3 = ((a3<<r) & 0x7fffffffU) | a2>>(31-r);
        a2 = ((a2<<r) & 0x7fffffffU) | a1>>(31-r);
        a1 = ((a1<<r) & 0x7fffffffU) | a0>>(31-r);
        a0 = (a0<<r) & 0x7fffffffU;
    }
    while ((a4 == 0 && (a3 & 0x40000000U) == 0) ||
           (a4 == -1 && (a3 & 0x40000000U) != 0))
    {   a4 = a3 | ((a3 & 0x40000000U)<<1);
        a3 = a2;
        a2 = a1;
        a1 = a0;
        a0 = 0;
        q--;
    }
    return q;
}

#endif // HAVE_SOFTFLOAT

LispObject N_rationalf(double d)
{
// If the value of the double is >= 2^52 then it must be an exact integer.
// In that case N_rationalf will just return the integer value using fix,
// and in this case it is immaterial what rounding mode I indicate there
// since no rounding should apply!
#define FP_INT_LIMIT ((double)((int64_t)1<<52))
    if (d <= -static_cast<double>(FP_INT_LIMIT) ||
        d >= static_cast<double>(FP_INT_LIMIT))
        return lisp_fix(make_boxfloat(d, WANT_DOUBLE_FLOAT), FIX_ROUND);
// Now the magnitude if d is modest, so it is safe to cast it to
// an int64_t. When I cast the result back to a float there will not be
// any need for rounding, so I can detect cases where the floating point
// input has a value that is exactly an integer.
    int64_t i = (int64_t)d;
    if (d == static_cast<double>(i)) return make_lisp_integer64(i);
// Now the value is smallish but is known not be to an integer. It may
// be that it is VERY small.
    bool negative = false;
    if (d < 0.0)
    {   d = -d;
        negative = true;
    }
    int32_t a2;
    uint32_t a1, a0;
    intptr_t x = 31*N_double_to_3_digits(d, a2, a1, a0);
// The representation extracted above is carefully aligned at a 32-bit
// boundary. I want to shift it right so that the least significant bit is
// a 1. I do the shifting in stages - by 31, by 6 and by 1 bit movements.
    while (a0 == 0)
    {   a0 = a1;
        a1 = a2;
        a2 = 0;
        x += 31;
    }
    while ((a0 & 0x3f) == 0)
    {   a0 = (a0 >> 6) | ((a1 & 0x3f) << 25);
        a1 = (a1 >> 6) | ((a2 & 0x3f) << 25);
        a2 = (uint32_t)a2 >> 6;
        x += 6;
    }
// Because d started as a floating point value it can involve at most 53 bits,
// and hence when I am within 6 bits of being normalised I have at worst
// 59 bits. But the bottom two words of the integer representation use
// 62 bits, so by now I must have a2 == 0
    assert(a2 == 0);
    while ((a0 & 1) == 0)
    {   a0 = (a0 >> 1) | ((a1 & 1) << 30);
        a1 = (a1 >> 1);
        x += 1;
    }
// Now the numerator will be just (d1,d0): re-attach the sign.
    if (negative)
    {   if (a0 == 0) a1 = -a1;
        else
        {   a0 = clear_top_bit(-a0);
            a1 = ~a1;
        }
    }
// x should still be strictly negative because the number was not an
// integer.
    assert(x < 0);
    LispObject w = N_make_fix_or_big2(a1, a0);
    THREADID;
    Save save(THREADARG w);
    LispObject den = N_make_power_of_two(-x);
    save.restore(w);
    return make_ratio(w, den);
}

// The intent here is to take a single precision floating point value and
// mask off its low 4 bits. The code here is a fine example of the sort
// of thing that runs up against strict aliasing rules. Here I believe that
// the use of memcpy ought to sort that out!

double N_truncate20(double d)
{   Float_union aa, bb;
    aa.f = d;
    std::memcpy(&bb, &aa, sizeof(bb));
    bb.i &= ~0xf;
    std::memcpy(&aa, &bb, sizeof(aa));
    return aa.f;
}

LispObject N_rationalizef(double dd, int bits)
//
// This is expected to give a 'nice' rational approximation to the
// floating point value d, specifically one where the size of the
// numerator and denominator are only just sufficient to capture the
// precision that the floating point representation provides.
//
{   double d;
    if (dd == 0.0) return fixnum_of_int(0);
    else if (dd < 0.0) d = -dd;
    else d = dd;
// Now d is the absolute value of the float that I need to deal with.
// If the absolute value of the input is large just convert it to an
// integer.
    if (d >= static_cast<double>((uint64_t)1<<bits))
        return lisp_fix(make_boxfloat(dd, WANT_DOUBLE_FLOAT), FIX_ROUND);
// If the value is small first convert it to a rational number p/q, then
// find the integer value r of q/p and return (1/r).
    if (d <= 1.0/static_cast<double>((uint64_t)1<<bits))
    {   LispObject r = N_rationalf(dd);
        r = lisp_ifix(denominator(r), numerator(r), FIX_ROUND);
        return make_ratio(fixnum_of_int(1), r);
    }
// Here I have a case where the result will be a non-trivial fraction. Because
// the true value is in the range 2^-K to 2^K with only K bits of precision
// both numerator and denominator will ens up with no more than (about?) K
// bits, and so they fit very happily in 64-bit integers.
    uint64_t p, q;
    uint64_t a;
    uint64_t u0, u1;
    uint64_t v0, v1;
    if (d >= 1.0)
    {
// if the input was at least 1.0 but under 2^53 I can multiply it by a
// power of 2 until it is between 2^52 and 2^53 and that should give me
// an exact integer which is within the range of int64_t. That then just
// needs a denominator that is the power of 2 that I scaled by. I will use
// 2^53 here even if I am working with single or short floats as input.
        int x;
        volatile double d1 = std::frexp(d, &x);
        p = (uint64_t)(d1*static_cast<double>((uint64_t)1<<53));
// The above conversion to an integer does little beyond keep the low 52
// bits of the floating point value and force bit 53 to be set!
        q = (uint64_t)1<<(53-x);
// The fraction (p/q) will now be an exact representation of the floating
// point input.
        a = p / q;       // partial quotient, which is at least 1.
        u0 = 1; u1 = a;  // the two "previous" approximations will be
        a = p % q;       // u0/v0 and u1/v1
        p = q;
        q = a;
        v0 = 0; v1 = 1;  // now u1/v1 is my initial approximation, and
        // it will be just the integer floor(d).
    }
    else
    {
// Now the input d is less than 1.0, so the first step of the continued
// fraction algorithm would use a partial quotient of zero, and just take
// the reciprocal of my value for d.
        int x;
        double d1 = std::frexp(d, &x);
        p = (uint64_t)(d1*static_cast<double>((uint64_t)1<<53));
// The next 3 lines express what I want to achieve, but because the exponent
// x is negative the initial value of the denominator q for the exact
// representation of d can be up to about 106 bits and in particular it
// will not fit in the type uint64_t.
//#     __int128 qq = (__int128)1<<(53-x);
//#     a = qq / p;
//#     q = qq % p;
// I can get a good approximation to the partial quotient (a) using
// floating point, but rounding when I calculate the reciprocal may mean
// it is not quite exact, or even quite in the integer range I had in mind.
        double d2 = 1.0/d;
        a = (uint64_t)d2;
// Given a quotient I can compute a remainder as q = 1<<(53-x) - a*p.
//      int128_t w1 = int128(1)<<(53-x);
//      int128_t w2 = (uint128_t)a*(uint128_t)p;
// but if the quotient (a) was correct then the remainder will be less
// than p, and p is known to be a 53-bit integer. Even if the computed
// quotient was a little bit out the value of q that I get here will not
// be far outside the range 0<=q<p, but it could err in either direction.
// But whatever else its value will fit within a 64-bit (signed) integer.
// I do the arithmetic as unsigned because I am deliberately expecting
// to truncate bits above the low 64.
        uint64_t w1 = 0;
        if (53-x < 64) w1 = (uint64_t)1<<(53-x);
        q = w1 - a*p;
// Now the value of a that I had computed in floating point might have
// been just slightly different from the exact value. This can now be
// observed by checking the remainder, so I will correct if necessary.
// I think I should probably only ever be out by +1 or -1 but I will write
// a loop "to be safe".
        while ((int64_t)q < 0)
        {   q = q + p;
            a--;
        }
        while (q >= p)
        {   q = q - p;
            a++;
        }
        u0 = 0; u1 = 1;
        v0 = 1; v1 = a;
    }
// I have now done the very first step towards generating a fractional
// representation of the input, and (u1/v1) is the best guess I have so
// far. The simple presentation of generating approximations always
// starts with (0/1) and then (1/0), but I do not want to have to test
// (1/0) to see if it is good, since my move to (floor(d)/1) for larger
// inputs.
// The next loop is the key one that derives a rational approximation to
// the original floating point value. In the situation here the ratios
// being worked with should not lead to NaNs, infinities or sub-normalised
// numbers...
    while (bits==53 ? d != static_cast<double>(u1)/static_cast<double>
           (v1) :
           bits==24 ? d != static_cast<float>(static_cast<double>
                   (u1)/static_cast<double>(v1)) :
           d != N_truncate20(static_cast<double>(u1)/static_cast<double>(v1)))
    {   a = p/q;
        uint64_t u2 = u0 + a*u1;
        uint64_t v2 = v0 + a*v1;
        p = q;   q = p%q;
        u0 = u1; u1 = u2;
        v0 = v1; v1 = v2;
    }
    LispObject p1;
    if (dd < 0.0) p1 = make_lisp_integer64(-(int64_t)u1);
    else p1 = make_lisp_integer64(u1);
    if (v1 == 1) return p1;
    THREADID;
    Save save(THREADARG p1);
    LispObject q1 = make_lisp_integer64(v1);
    save.restore(p1);
    return make_ratio(p1, q1);
}

#ifdef HAVE_SOFTFLOAT
// The following constants are 2^112 and -2^112 and their reciprocals, which
// are used in N_rationalf128 because any 128-bit floating point value that
// is that large is necessarily an exact integer.
//
// FP128_SMALL_LIMIT is 2^-113 and is used in N_rationalizef128.

#ifdef LITTLEENDIAN

static float128_t FP128_INT_LIMIT = {{0, INT64_C(0x406f000000000000)}};
static float128_t FP128_MINUS_INT_LIMIT = {{0, INT64_C(0xc06f000000000000)}};
static float128_t FP128_SMALL_LIMIT = {{0, INT64_C(0x3f8e000000000000)}};

#else

static float128_t FP128_INT_LIMIT = {{INT64_C(0x406f000000000000), 0}};
static float128_t FP128_MINUS_INT_LIMIT = {{INT64_C(0xc06f000000000000), 0}};
static float128_t FP128_LARGE_LIMIT = {{INT64_C(0x4070000000000000), 0}};
static float128_t FP128_SMALL_LIMIT = {{INT64_C(0x3f8e000000000000), 0}};

#endif

LispObject N_rationalf128(float128_t *d)
{
// If the value of the double is > 2^112 then it must be an exact integer.
// In that case N_rationalf will just return the integer value using fix,
// and in this case it is immaterial what rounding mode I indicate there
// since no rounding should apply!
    if (f128M_le(d, &FP128_MINUS_INT_LIMIT) ||
        f128M_le(&FP128_INT_LIMIT, d))
        return lisp_fix(make_boxfloat128(*d), FIX_ROUND);
// Now the magnitude if d at most 2^112. I want to check whether it is
// exactly an integer or not. Well that is not as easy as it was in the
// 64-bit case so I will go straight to the general method... Well I will
// filter out the case of zero first.
    if (f128M_zero(d)) return fixnum_of_int(0);
    bool negative = false;
    float128_t dd = *d;
    if (f128M_negative(d))
    {   f128M_negate(&dd);
        negative = true;
    }
// Remember that |d| < 2^112. That means it will use at most 4 digits
// of bignum. Well the calculations I do here split it into 5 digits,
// but by the time I end only the low 4 should be relevant.
    int32_t a4;
    uint32_t a3, a2, a1, a0;
    intptr_t x = 31*N_float128_to_5_digits(&dd, a4, a3, a2, a1, a0);
    while (a0 == 0 && x <= -31)
    {   a0 = a1;
        a1 = a2;
        a2 = a3;
        a3 = a4;
        a4 = 0;
        x += 31;
    }
    while ((a0 & 0x3f) == 0 && x <= -6)
    {   a0 = (a0 >> 6) | ((a1 & 0x3f) << 25);
        a1 = (a1 >> 6) | ((a2 & 0x3f) << 25);
        a2 = (a2 >> 6) | ((a3 & 0x3f) << 25);
        a3 = (a3 >> 6) | ((a4 & 0x3f) << 25);
        a4 = (uint32_t)a4 >> 6;
        x += 6;
    }
    while ((a0 & 1) == 0 && x <= -1)
    {   a0 = (a0 >> 1) | ((a1 & 1) << 30);
        a1 = (a1 >> 1) | ((a2 & 1) << 30);
        a2 = (a2 >> 1) | ((a3 & 1) << 30);
        a3 = (a3 >> 1) | ((a4 & 1) << 30);
        a4 = ((uint32_t)a4 >> 1);
        x += 1;
    }
    assert(a4 == 0);
    LispObject w;
    if (negative)
    {   uint32_t carry = 1;
        a0 = ~a0 + carry;
        carry = a0 >> 31;
        a0 &= 0x7fffffffU;
        a1 = ~a1 + carry;
        carry = a1 >> 31;
        a1 &= 0x7fffffffU;
        a2 = ~a2 + carry;
        carry = a2 >> 31;
        a2 &= 0x7fffffffU;
        a3 = ~a3 + carry;    // leave sign bit set in a3.
    }
    int len = 4;
// Allow for the fact that the number may not need fully 4 digits.
    if ((a3 == 0 && ((a2 & 0x40000000) == 0)) ||
        (a3 == 0xffffffff && ((a2 & 0x40000000) != 0)))
    {   len = 3;
        if (a3 == 0xffffffff) a2 |= 0x80000000U;
        if ((a2 == 0 && ((a1 & 0x40000000) == 0)) ||
            (a2 == 0xffffffff && ((a1 & 0x40000000) != 0)))
        {   len = 2;
            if (a2 == 0xffffffff) a1 |= 0x80000000U;
        }
    }
    switch (len)
    {   // case 4:
        default:
            w = make_four_word_bignum(a3, a2, a1, a0);
            break;
        case 3:
            w = make_three_word_bignum(a2, a1, a0);
            break;
        case 2:
            int64_t n = ((int64_t)a1 << 31) + a0;
            if (negative) n = -n;
            w = make_lisp_integer64(n);
            break;
    }
    if (x == 0) return w;
    THREADID;
    Save save(THREADARG w);
    LispObject den = N_make_power_of_two(-x);
    save.restore(w);
    return make_ratio(w, den);
}

// This is expected to adjust the ratio returned to support 113 bits
// of precision.
// I have taken the code from N_rationalize (as above) and removed the
// comments to make it shorter, and then the task is just to re-work
// it to cope with 128-bit wide values rather than 64-bit wide ones!

//-- static void N_uint128_prinhex(const char *msg, uint128_t a)
//-- {   printf("%s%.8x %.8x %.8x %.8x\n", msg,
//--         (uint32_t)(a >> 96), (uint32_t)(a >> 64),
//--         (uint32_t)(a >> 32), (uint32_t)a);
//-- }

// Now I need to be able to convert between float128_t and uint128_t with
// "fix" and "float" operations. I will only concern myself with positive
// numbers, and my expected use will be that I only attempt to fix
// values that will fit within 113 bits (ie well within 128), and
// I will only float values that are in around the same range.

uint128_t N_uint128_fix(float128_t *a)
{   if (f128M_eq(a, &f128_0)) return 0;
// I am not going to do anything clever with NaN or infinity here - they
// are just not permitted and would lead to chaos.
    float128_t aa;
    int x;
    f128M_frexp(a, &aa, &x);
// Now I take the 113 bits of mantissa (including an implicit bit) and
// shuffle to be in the form of the uint128_t integer.
    uint64_t hi = (aa.v[HIPART] & UINT64_C(0x0000ffffffffffff)) |
                  UINT64_C(0x0001000000000000);
    uint128_t w = aa.v[LOPART] | (uint128(hi)<<64);
// Now I may need to shift b by an amount determined by x.
    x = x - 113;
    if (x > 0) w = w<<x;
    else if (x < 0) w = w>>(-x);
    return w;
}

void N_uint128_float(uint128_t a, float128_t *b)
{   if (a == 0)
    {   *b = f128_0;
        return;
    }
    int x = 113;
// Now I want to normalize the integer so that the bit at position
// 00010000:00000000:00000000:00000000 is set, ie the one that will be
// the "hidden bit".
//
// Here what I want is a "find most significant bit" operation.
    while (a >= (uint128_t(1)<<113))
    {   a = a>>1;
        x++;
    }
    while (a < (uint128_t(1)<<(96-24+1)))
    {   a = a<<24;
        x = x - 24;
    }
    while (a < (uint128_t(1)<<(96-5+1)))
    {   a = a<<5;
        x = x - 5;
    }
    while (a < (uint128_t(1)<<112))
    {   a = a<<1;
        x--;
    }
    uint64_t ahi = (uint64_t)(a>>64) & UINT64_C(0x0000ffffffffffff);
    ahi = ahi | ((uint64_t)(x + 0x3ffe)<<48);
    b->v[HIPART] = ahi;
    b->v[LOPART] = (uint64_t)a;
}

LispObject N_rationalizef128(float128_t *dd)
{   float128_t d;
    if (f128M_zero(dd)) return fixnum_of_int(0);
    d = *dd;
    if (f128M_negative(&d)) f128M_negate(&d);
// Maybe the float is in fact exactly an integer.
    if (f128M_le(&FP128_INT_LIMIT, &d))
        return lisp_fix(make_boxfloat128(*dd), FIX_ROUND);
// I am slightly more conservative as to when I decide that the
// result I return will be just the reciprocal of an integer.
    if (f128M_le(&d, &FP128_SMALL_LIMIT))
    {   LispObject r = N_rationalf128(dd);
        r = lisp_ifix(denominator(r), numerator(r), FIX_ROUND);
        return make_ratio(fixnum_of_int(1), r);
    }
    uint128_t p, q;
    uint128_t a;
    uint128_t u0, u1;
    uint128_t v0, v1;
    if (f128M_le(&f128_1, &d))
    {   int x;
        float128_t d1;
        f128M_frexp(&d, &d1, &x);
        f128M_ldexp(&d1, 113);
        p = N_uint128_fix(&d1);
        q = uint128_t(1) << (113-x);
        u1 = p/q;
        a = p%q;
        u0 = 1;
        p = q;
        q = a;
        v0 = 0;
        v1 = 1;
    }
    else
    {   int x;
        float128_t d1, d2;
        f128M_frexp(&d, &d1, &x);
        f128M_ldexp(&d1, 113);
        p = N_uint128_fix(&d1);
        f128M_div(&f128_1, &d, &d2);
        a = N_uint128_fix(&d2);
        uint128_t w1;
        if (113-x < 128) w1 = uint128_t(1) << (113-x);
        else w1 = 0;
        q = w1 - a*p;
        while ((q >> 127) != 0)  // i.e. "negative"
        {   q += p;
            a -= 1;
        }
        while (p <= q)
        {   q -= p;
            a += 1;
        }
        u0 = 0;
        u1 = 1;
        v0 = 1;
        v1 = a;
    }
    float128_t du1, dv1, q2;
    while (N_uint128_float(u1, &du1),
           N_uint128_float(v1, &dv1),
           f128M_div(&du1, &dv1, &q2),
           !f128M_eq(&d, &q2))
    {   uint128_t a1;
        if (q == 0)
        {   std::printf("\n+++ Trouble in N_rationalizef128. q = 0\n");
            break;
        }
        a1 = p/q;
        uint128_t u2 = a1*u1 + u0;
        uint128_t v2 = a1*v1 + v0;
        p = q;   q = p%q;
        u0 = u1; u1 = u2;
        v0 = v1; v1 = v2;
    }
    LispObject p1;
    if (f128M_negative(dd)) p1 = make_lisp_integer128(-u1);
    else p1 = make_lisp_unsigned128(u1);
    if (v1 == 1) return p1;
    THREADID;
    Save save(THREADARG p1);
    LispObject q1 = make_lisp_unsigned128(v1);
    save.restore(p1);
    return make_ratio(p1, q1);
}

#endif // HAVE_SOFTFLOAT

LispObject N_rational(LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case TAG_FIXNUM:
            return a;
        case XTAG_SFLOAT:
            return N_rationalf(value_of_immediate_float(a));
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_RATNUM:
                    return a;
                default:
                    return aerror1("bad arg for rational", a);
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
#ifdef HAVE_SOFTFLOAT
            if (flthdr(a) == LONG_FLOAT_HEADER)
                return N_rationalf128(reinterpret_cast<float128_t *>(long_float_addr(
                                        a)));
            else
#endif // HAVE_SOFTFLOAT
                return N_rationalf(float_of_number(a));
        default:
            return aerror1("bad arg for rational", a);
    }
}

LispObject N_rationalize(LispObject a)
{   switch (a & XTAG_BITS)
    {   case TAG_FIXNUM:
            return a;
        case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return N_rationalizef(value_of_immediate_float(a), 24);
            else return N_rationalizef(value_of_immediate_float(a), 20);
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_RATNUM:
                    return a;
                default:
                    return aerror1("bad arg for rationalize", a);
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
        switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return N_rationalizef(single_float_val(a), 24);
                case DOUBLE_FLOAT_HEADER:
                    return N_rationalizef(double_float_val(a), 53);
#ifdef HAVE_SOFTFLOAT
                case LONG_FLOAT_HEADER:
                    return N_rationalizef128(reinterpret_cast<float128_t *>(long_float_addr(
                                               a)));
#endif // HAVE_SOFTFLOAT
            }
        default:
            return aerror1("bad arg for rationalize", a);
    }
}

LispObject Nrational(LispObject env, LispObject a)
{   return onevalue(N_rational(a));
}

LispObject Nmanexp(LispObject env, LispObject a)
{   int x;
    double f;
// At present I do not support 128-bit floats here @@@
    if (!is_float(a))  return aerror1("arg is not a floating-point number", a);
    f = float_of_number(a);
    f = std::frexp(f, &x);
    return onevalue(cons(make_boxfloat(f, WANT_DOUBLE_FLOAT),
                         fixnum_of_int(x)));
}

LispObject Nrationalize(LispObject env, LispObject a)
{   return onevalue(N_rationalize(a));
}

LispObject Nrandom(LispObject env, LispObject a, LispObject bb)
{
#ifdef COMMON
// Common Lisp expects an optional second arg to be used for the random
// state - at present I do not support that, but it will not be too hard
// when I get around to it...
#endif // COMMON
    if (is_fixnum(a))
         return arithlib_lowlevel::uniform_upto(a);
    if (is_numbers(a) && is_new_bignum(a))
        return arithlib_lowlevel::uniform_upto(a);
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        if (h == LONG_FLOAT_HEADER)
        {   aerror1("random can not cope with long floats yet", a);
        }
        double d = float_of_number(a), v;
// The calculation here turns 62 bits of integer data into a floating
// point number in the range 0.0 (inclusive) to 1.0 (exclusive).  Well,
// to be more precise, rounding the value to the machine's floating point
// format may round it up to be exactly 1.0, so I discard and cases where
// that happens (once in several blue moons...).  If I wrote code that
// knew exactly how many bits my floating point format had I could avoid
// the need for that extra test, but it does not seem very painful to me
// and I prefer the more portable code.
        do
        {   uint64_t r = arithlib::mersenne_twister();
            v = static_cast<double>(r);
            v /= 16384.0; // 2^16  I divide by 2^16 four times because
            v /= 16384.0; // 2^16  I think that the literal for 2^64 is
            v /= 16384.0; // 2^16  too big to be obvious or memorable and
            v /= 16384.0; // 2^16  in the hope that a compiler will optimise!
            v *= d;       // scale up to correct range
        } 
        while (v == d);   // loop on unusual case where FP value rounds up
        a = make_boxfloat(v, floatWant(h));
        return onevalue(a);
    }
    if (is_sfloat(a))
    {   Float_union d;
        Float_union v;
// What I do here violates strict aliasing rules! I ought to use some
// memcpy to be properly legal.
        d.f = value_of_immediate_float(a);
        do
        {   uint64_t r = arithlib::mersenne_twister();
            float r1 = static_cast<float>(r&0xffffffff)/16384.0/16384.0;
            v.f = r1*d.f;
        }
        while ((v.i & ~0xf) == (d.i & ~0xf));
        d.f = v.f;
        return onevalue(pack_immediate_float(v.f, a));
    }
    return aerror1("random-number", a);
}

LispObject Nrandom(LispObject env, LispObject a)
{   return Nrandom(env, a, nil);
}

LispObject Nnext_random(LispObject)
// Returns a random positive fixnum.  27 bits in this Lisp! At present this
// returns 27 bits whether on a 32 or 64-bit machine...
{   uint64_t r = arithlib::mersenne_twister();
    return onevalue(fixnum_of_int(r & 0x07ffffff));
}

LispObject Nmake_random_state(LispObject env, LispObject a, LispObject b)
{   uint64_t seed = 0;
    if (!is_fixnum(a)) seed = int_of_fixnum(a); 
    arithlib_lowlevel::reseed(seed);
    return onevalue(nil);
}

LispObject Nmake_random_state(LispObject env, LispObject a)
{   return Nmake_random_state(env, a, nil);
}

LispObject Npack_md5_result(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
{   uint64_t high = v0 | (static_cast<uint64_t>(v1)<<32);
    uint64_t low = v2 | (static_cast<uint64_t>(v3)<<32);
    return arithlib_lowlevel::int128_to_bignum(high, low);
}

// The function md5() can be given a number or a string as an argument,
// and it uses the md5 message digest algorithm to reduce it to a
// numeric value in the range 0 to 2^128.
// Well actually I will also allow an arbitrary expression, which I
// will often treat as if it has to be printed... Note that these days
// md5 is not considered secure, and sha1 that followed it is also not
// considered secure, so anybody worried by security needs at least sha2!

LispObject Nmd5(LispObject env, LispObject a)
{   unsigned char md[16];
    uint32_t v0, v1, v2, v3;
    size_t len, i;
// I want the checksums that are computed to be the same whether I am on
// a big or little-endian machine, so when I process integers I will
// check map them onto byte-sequences that adapt for that.
    if (is_fixnum(a))
    {   md[0] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[1] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[2] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[3] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[4] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[5] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[6] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[7] = a & 0xff;
        CSL_MD5_Init();
        CSL_MD5_Update(md, 8);
    }
    else if (is_numbers(a) && is_bignum_header(numhdr(a)))
    {   len = length_of_header(numhdr(a));
        CSL_MD5_Init();
#ifdef __cpp_lib_endian // C++20 feature. Needs #include <bit>.
        bool littleEndian = std::endian::native == std::endian::little;
#else // __cpp_lib_endian
        uint32_t w1 = 0x12345678;
        char w2[4];
        std::memcpy(w2, &w1, 4);
        bool littleEndian = w2[0] == 0x78;
#endif // __cpp_lib_endian
        if (littleEndian)
            CSL_MD5_Update(
                reinterpret_cast<const unsigned char*>(&bignum_digits(a)[0]),
                len-CELL);
        else for (i=0; i<(len-CELL)/4; i++)
        {   std::memcpy(md, &bignum_digits(a)[i], 4);
            int b = md[0]; md[0] = md[3]; md[3] = b;
            b = md[1]; md[1] = md[2]; md[2] = b;
            CSL_MD5_Update(md, 4);
        }
    }
    else if (is_numbers(a) && is_new_bignum_header(numhdr(a)))
    {   len = length_of_header(numhdr(a));
        CSL_MD5_Init();
#ifdef __cpp_lib_endian
        bool littleEndian = std::endian::native == std::endian::little;
#else // __cpp_lib_endian
        uint32_t w1 = 0x12345678;
        char w2[4];
        std::memcpy(w2, &w1, 4);
        bool littleEndian = w2[0] == 0x78;
#endif // __cpp_lib_endian
        if (littleEndian)
            CSL_MD5_Update(
                reinterpret_cast<const unsigned char*>(a - TAG_NUMBERS + CELL),
                len-CELL);
        else for (i=CELL; i<len; i+=8)
        {   std::memcpy(md,
                reinterpret_cast<const unsigned char*>(a - TAG_NUMBERS + i), 8);
            int b = md[0]; md[0] = md[7]; md[7] = b;
            b = md[1]; md[1] = md[6]; md[6] = b;
            b = md[2]; md[2] = md[5]; md[5] = b;
            b = md[3]; md[3] = md[4]; md[4] = b;
            CSL_MD5_Update(md, 4);
        }
    }
    else if (is_vector(a) && is_string(a))
    {   len = length_of_byteheader(vechdr(a));
        CSL_MD5_Init();
        CSL_MD5_Update((const unsigned char *)"\"", 1);
        CSL_MD5_Update(bit_cast<unsigned char *>(a + CELL - TAG_VECTOR),
                       len-CELL);
    }
    else checksum(a);
    CSL_MD5_Final(md);
// md5 produces a digest that is 128 bits. I wish to pack that as an
// integer. Well I will start by collecting 4 32-bit chunks...
//    for (i=0; i<16; i++) printf("%x ", md[i] & 0xff);
//   printf("\n");
    v0 = md[0] + (md[1]<<8) + (md[2]<<16) + (md[3]<<24);
    v1 = md[4] + (md[5]<<8) + (md[6]<<16) + (md[7]<<24);
    v2 = md[8] + (md[9]<<8) + (md[10]<<16) + (md[11]<<24);
    v3 = md[12] + (md[13]<<8) + (md[14]<<16) + (md[15]<<24);
    return onevalue(Npack_md5_result(v0, v1, v2, v3));
}

// For testing the MD5 code... processes a string "raw".

LispObject Nmd5string(LispObject env, LispObject a)
{   unsigned char md[16];
    if (is_vector(a) && is_string(a))
    {   size_t len = length_of_byteheader(vechdr(a));
        CSL_MD5_Init();
        CSL_MD5_Update(bit_cast<unsigned char *>(a + CELL -
                       TAG_VECTOR), len-CELL);
    }
    else return onevalue(nil);
    CSL_MD5_Final(md);
    for (int i=0; i<16; i++) std::printf("%x ", md[i]);
    std::printf("\n");
    return onevalue(Npack_md5_result(md[0], md[1], md[2], md[3]));
}

// md60 is a function that uses MD5 but then returns just about 60 bits
// of number not 128. It is for use when the full 128 bits of checksum
// would be clumsy overkill.
//
// Note that this version really does compute md5 and then just return the
// low 59 bits. A previous implementation that I had went to some trouble
// to ensure that the value returned was always represented as a bignum,
// and specifically that the top 32 bits of that value were never all zero.
// I now forget my exact reasoning for doing that, and it was clearly a
// rather odd thing to do! On a 64-bit machine a 59-bit value will always
// be a fixnum, and this is why (despite the function name!) I only keep
// 59 bits.

LispObject Nmd60(LispObject env, LispObject a)
{   unsigned char md[16];
    uint32_t v0, v1;
    size_t len, i;
// I want the checksums that are computed to be the same whether I am on
// a big or little-endian machine, so when I process integers I will
// check map them onto byte-sequences that adapt for that.
    if (is_fixnum(a))
    {   md[0] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[1] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[2] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[3] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[4] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[5] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[6] = a & 0xff;
        a = static_cast<uint64_t>(a) >> 8; md[7] = a & 0xff;
        CSL_MD5_Init();
        CSL_MD5_Update(md, 8);
    }
    else if (is_numbers(a) && is_bignum_header(numhdr(a)))
    {   len = length_of_header(numhdr(a));
        CSL_MD5_Init();
#ifdef __cpp_lib_endian // C++20 feature. Needs #include <bit>.
        bool littleEndian = std::endian::native == std::endian::little;
#else // __cpp_lib_endian
        uint32_t w1 = 0x12345678;
        char w2[4];
        std::memcpy(w2, &w1, 4);
        bool littleEndian = w2[0] == 0x78;
#endif // __cpp_lib_endian
        if (littleEndian)
            CSL_MD5_Update(
                reinterpret_cast<const unsigned char*>(&bignum_digits(a)[0]),
                len-CELL);
        else for (i=0; i<(len-CELL)/4; i++)
        {   std::memcpy(md, &bignum_digits(a)[i], 4);
            int b = md[0]; md[0] = md[3]; md[3] = b;
            b = md[1]; md[1] = md[2]; md[2] = b;
            CSL_MD5_Update(md, 4);
        }
    }
    else if (is_numbers(a) && is_new_bignum_header(numhdr(a)))
    {   len = length_of_header(numhdr(a));
        CSL_MD5_Init();
#ifdef __cpp_lib_endian
        bool littleEndian = std::endian::native == std::endian::little;
#else // __cpp_lib_endian
        uint32_t w1 = 0x12345678;
        char w2[4];
        std::memcpy(w2, &w1, 4);
        bool littleEndian = w2[0] == 0x78;
#endif // __cpp_lib_endian
        if (littleEndian)
            CSL_MD5_Update(
                reinterpret_cast<const unsigned char*>(a - TAG_NUMBERS + CELL),
                len-CELL);
        else for (i=CELL; i<len; i+=8)
        {   std::memcpy(md,
                reinterpret_cast<const unsigned char*>(a - TAG_NUMBERS + i), 8);
            int b = md[0]; md[0] = md[7]; md[7] = b;
            b = md[1]; md[1] = md[6]; md[6] = b;
            b = md[2]; md[2] = md[5]; md[5] = b;
            b = md[3]; md[3] = md[4]; md[4] = b;
            CSL_MD5_Update(md, 4);
        }
    }
    else if (is_vector(a) && is_string(a))
    {   len = length_of_byteheader(vechdr(a));
        CSL_MD5_Init();
        CSL_MD5_Update((const unsigned char *)"\"", 1);
        CSL_MD5_Update(bit_cast<unsigned char *>(a + CELL -
                       TAG_VECTOR), len-CELL);
    }
    else checksum(a);
    CSL_MD5_Final(md);
    v0 = md[0] + (md[1]<<8) + (md[2]<<16) + (md[3]<<24);
    v1 = md[4] + (md[5]<<8) + (md[6]<<16) + (md[7]<<24);
    uint64_t v = (uint64_t)v1<<32 | v0;
// I discard 4 bits to allow for fixnum tag bits and one more so that the
// number does not extend into the fixnum's sign bit.
// So maybe this in fact only keeps 59 bits.
    return onevalue(make_lisp_unsigned64(v >> 5));
}

LispObject Nvalidate_number(LispObject env, LispObject a)
{   return aerror1("validate-number not available or needed here", a);
}

LispObject Nvalidate_number(LispObject env, LispObject a, LispObject b)
{   return aerror2("validate-number not available or needed here", a, b);
}

#endif // ARITHLIB

// end of arith-random.cpp
