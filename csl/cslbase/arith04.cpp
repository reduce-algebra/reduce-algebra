// arith04.cpp                             Copyright (C) 1991-2021 Codemist

//
// Arithmetic functions.
//    <, rationalize
//
//

/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

#include "headers.h"


LispObject make_n_word_bignum(int32_t a2, uint32_t a1, uint32_t a0,
                              size_t n)
//
// This make a bignum with n words of data and digits a1, a2, a3 and
// then n zeros.  Will only be called with n>=0 and a1, a2, a3 already
// correctly structured to make a valid bignum. NOTE that the number n
// as passed is the number of zero words to be inserted before the 3
// words at the end!
//
{   size_t i;
    LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM,
                                    CELL+4*n+12);
    for (i=0; i<n; i++) bignum_digits(w)[i] = 0;
    bignum_digits(w)[n] = a0;
    bignum_digits(w)[n+1] = a1;
    bignum_digits(w)[n+2] = a2;
    if ((n & 1) != (SIXTY_FOUR_BIT ? 1 : 0)) bignum_digits(w)[n+3] = 0;
    return w;
}

// Now the same sort of idea but with yet more digits being passed.

LispObject make_n4_word_bignum(int32_t a3, uint32_t a2, uint32_t a1,
                               uint32_t a0, size_t n)
{   size_t i;
    LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM,
                                    CELL+4*n+16);
    for (i=0; i<n; i++) bignum_digits(w)[i] = 0;
    bignum_digits(w)[n] = a0;
    bignum_digits(w)[n+1] = a1;
    bignum_digits(w)[n+2] = a2;
    bignum_digits(w)[n+3] = a3;
    if ((n & 1) != (SIXTY_FOUR_BIT ? 0 : 1)) bignum_digits(w)[n+4] = 0;
    return w;
}

LispObject make_n5_word_bignum(int32_t a4, uint32_t a3, uint32_t a2,
                               uint32_t a1, uint32_t a0, size_t n)
{   size_t i;
    LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM,
                                    CELL+4*n+20);
    for (i=0; i<n; i++) bignum_digits(w)[i] = 0;
    bignum_digits(w)[n] = a0;
    bignum_digits(w)[n+1] = a1;
    bignum_digits(w)[n+2] = a2;
    bignum_digits(w)[n+3] = a3;
    bignum_digits(w)[n+4] = a4;
    if ((n & 1) != (SIXTY_FOUR_BIT ? 1 : 0)) bignum_digits(w)[n+5] = 0;
    return w;
}

LispObject make_power_of_two(size_t n)
//
// Create the number 2^n where n is positive.  Used to make the
// denominator of a rational representation of a float.  Some fun
// to cope with various small cases before I get to the general call
// to make_n_word_bignum.
//
{   if (n < 64) return make_lisp_unsigned64((uint64_t)1 << n);
    else if ((n % 31) == 30)
        return make_n_word_bignum(0, 0x40000000, 0, (n/31)-2);
    else return make_n_word_bignum(((int32_t)1) << (n % 31), 0, 0,
                                       (n/31)-2);
}

static LispObject make_fix_or_big2(int32_t a1, uint32_t a2)
{   return make_lisp_integer64(((int64_t)a1 << 31) | a2);
}

LispObject rationalf(double d)
{
// If the value of the double is >= 2^52 then it must be an exact integer.
// In that case rationalf will just return the integer value using fix,
// and in this case it is immaterial what rounding mode I indicate there
// since no rounding should apply!
#define FP_INT_LIMIT ((double)((int64_t)1<<52))
    if (d <= -static_cast<double>(FP_INT_LIMIT) ||
        d >= static_cast<double>(FP_INT_LIMIT))
        return lisp_fix(make_boxfloat(d, TYPE_DOUBLE_FLOAT), FIX_ROUND);
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
    intptr_t x = 31*double_to_3_digits(d, a2, a1, a0);
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
    LispObject w = make_fix_or_big2(a1, a0);
    THREADID;
    Save save(THREADARG w);
    LispObject den = make_power_of_two(-x);
    save.restore(w);
    return make_ratio(w, den);
}

// The intent here is to take a single precision floating point value and
// mask off its low 4 bits. The code here is a fine example of the sort
// of thing that runs up against strict aliasing rules. Here I believe that
// the use of memcpy ought to sort that out!

double truncate20(double d)
{   Float_union aa, bb;
    aa.f = d;
    std::memcpy(&bb, &aa, sizeof(bb));
    bb.i &= ~0xf;
    std::memcpy(&aa, &bb, sizeof(aa));
    return aa.f;
}

static LispObject rationalizef(double dd, int bits)
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
        return lisp_fix(make_boxfloat(dd, TYPE_DOUBLE_FLOAT), FIX_ROUND);
// If the value is small first convert it to a rational number p/q, then
// find the integer value r of q/p and return (1/r).
    if (d <= 1.0/static_cast<double>((uint64_t)1<<bits))
    {   LispObject r = rationalf(dd);
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
           d != truncate20(static_cast<double>(u1)/static_cast<double>(v1)))
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
// are used in rationalf128 because any 128-bit floating point value that
// is that large is necessarily an exact integer.
//
// FP128_SMALL_LIMIT is 2^-113 and is used in rationalizef128.

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

LispObject rationalf128(float128_t *d)
{
// If the value of the double is > 2^112 then it must be an exact integer.
// In that case rationalf will just return the integer value using fix,
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
    intptr_t x = 31*float128_to_5_digits(&dd, a4, a3, a2, a1, a0);
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
    LispObject den = make_power_of_two(-x);
    save.restore(w);
    return make_ratio(w, den);
}

// This is expected to adjust the ratio returned to support 113 bits
// of precision.
// I have taken the code from rationalize (as above) and removed the
// comments to make it shorter, and then the task is just to re-work
// it to cope with 128-bit wide values rather than 64-bit wide ones!

//-- static void uint128_prinhex(const char *msg, uint128_t a)
//-- {   printf("%s%.8x %.8x %.8x %.8x\n", msg,
//--         (uint32_t)(a >> 96), (uint32_t)(a >> 64),
//--         (uint32_t)(a >> 32), (uint32_t)a);
//-- }

// Now I need to be able to convert between float128_t and uint128_t with
// "fix" and "float" operations. I will only concern myself with positive
// numbers, and my expected use will be that I only attempt to fix
// values that will fit within 113 bits (ie well within 128), and
// I will only float values that are in around the same range.

uint128_t uint128_fix(float128_t *a)
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

void uint128_float(uint128_t a, float128_t *b)
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

static LispObject rationalizef128(float128_t *dd)
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
    {   LispObject r = rationalf128(dd);
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
        p = uint128_fix(&d1);
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
        p = uint128_fix(&d1);
        f128M_div(&f128_1, &d, &d2);
        a = uint128_fix(&d2);
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
    while (uint128_float(u1, &du1),
           uint128_float(v1, &dv1),
           f128M_div(&du1, &dv1, &q2),
           !f128M_eq(&d, &q2))
    {   uint128_t a1;
        if (q == 0)
        {   std::printf("\n+++ Trouble in rationalizef128. q = 0\n");
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

LispObject rational(LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case TAG_FIXNUM:
            return a;
        case XTAG_SFLOAT:
            return rationalf(value_of_immediate_float(a));
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
            if (type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
                return rationalf128(reinterpret_cast<float128_t *>(long_float_addr(
                                        a)));
            else
#endif // HAVE_SOFTFLOAT
                return rationalf(float_of_number(a));
        default:
            return aerror1("bad arg for rational", a);
    }
}

LispObject rationalize(LispObject a)
{   switch (a & XTAG_BITS)
    {   case TAG_FIXNUM:
            return a;
        case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return rationalizef(value_of_immediate_float(a), 24);
            else return rationalizef(value_of_immediate_float(a), 20);
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
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    return rationalizef(single_float_val(a), 24);
                case TYPE_DOUBLE_FLOAT:
                    return rationalizef(double_float_val(a), 53);
#ifdef HAVE_SOFTFLOAT
                case TYPE_LONG_FLOAT:
                    return rationalizef128(reinterpret_cast<float128_t *>(long_float_addr(
                                               a)));
#endif // HAVE_SOFTFLOAT
            }
        default:
            return aerror1("bad arg for rationalize", a);
    }
}

//
// Arithmetic comparison: lessp
//

inline bool lessp_i_i(LispObject a1, LispObject a2);
inline bool lessp_i_b(LispObject a1, LispObject a2);
inline bool lessp_i_r(LispObject a1, LispObject a2);
inline bool lessp_i_c(LispObject a1, LispObject a2);
inline bool lessp_i_s(LispObject a1, LispObject a2);
inline bool lessp_i_f(LispObject a1, LispObject a2);
inline bool lessp_i_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline bool lessp_i_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline bool lessp_b_i(LispObject a1, LispObject a2);
inline bool lessp_b_b(LispObject a1, LispObject a2);
inline bool lessp_b_r(LispObject a1, LispObject a2);
inline bool lessp_b_c(LispObject a1, LispObject a2);
inline bool lessp_b_s(LispObject a1, LispObject a2);
inline bool lessp_b_f(LispObject a1, LispObject a2);
inline bool lessp_b_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline bool lessp_b_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline bool lessp_r_i(LispObject a1, LispObject a2);
inline bool lessp_r_b(LispObject a1, LispObject a2);
inline bool lessp_r_r(LispObject a1, LispObject a2);
inline bool lessp_r_c(LispObject a1, LispObject a2);
inline bool lessp_r_s(LispObject a1, LispObject a2);
inline bool lessp_r_f(LispObject a1, LispObject a2);
inline bool lessp_r_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline bool lessp_r_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline bool lessp_c_i(LispObject a1, LispObject a2);
inline bool lessp_c_b(LispObject a1, LispObject a2);
inline bool lessp_c_r(LispObject a1, LispObject a2);
inline bool lessp_c_c(LispObject a1, LispObject a2);
inline bool lessp_c_s(LispObject a1, LispObject a2);
inline bool lessp_c_f(LispObject a1, LispObject a2);
inline bool lessp_c_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline bool lessp_c_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline bool lessp_s_i(LispObject a1, LispObject a2);
inline bool lessp_s_b(LispObject a1, LispObject a2);
inline bool lessp_s_r(LispObject a1, LispObject a2);
inline bool lessp_s_c(LispObject a1, LispObject a2);
inline bool lessp_s_s(LispObject a1, LispObject a2);
inline bool lessp_s_f(LispObject a1, LispObject a2);
inline bool lessp_s_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline bool lessp_s_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline bool lessp_f_i(LispObject a1, LispObject a2);
inline bool lessp_f_b(LispObject a1, LispObject a2);
inline bool lessp_f_r(LispObject a1, LispObject a2);
inline bool lessp_f_c(LispObject a1, LispObject a2);
inline bool lessp_f_s(LispObject a1, LispObject a2);
inline bool lessp_f_f(LispObject a1, LispObject a2);
inline bool lessp_f_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline bool lessp_f_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline bool lessp_d_i(LispObject a1, LispObject a2);
inline bool lessp_d_b(LispObject a1, LispObject a2);
inline bool lessp_d_r(LispObject a1, LispObject a2);
inline bool lessp_d_c(LispObject a1, LispObject a2);
inline bool lessp_d_s(LispObject a1, LispObject a2);
inline bool lessp_d_f(LispObject a1, LispObject a2);
inline bool lessp_d_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline bool lessp_d_l(LispObject a1, LispObject a2);

inline bool lessp_l_i(LispObject a1, LispObject a2);
inline bool lessp_l_b(LispObject a1, LispObject a2);
inline bool lessp_l_r(LispObject a1, LispObject a2);
inline bool lessp_l_c(LispObject a1, LispObject a2);
inline bool lessp_l_s(LispObject a1, LispObject a2);
inline bool lessp_l_f(LispObject a1, LispObject a2);
inline bool lessp_l_d(LispObject a1, LispObject a2);
inline bool lessp_l_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline bool lessp_i_i(LispObject a, LispObject b)
{   return (intptr_t)a < (intptr_t)b;
}

inline bool lessp_i_s(LispObject a, LispObject b)
{
// On a 32-bit machine any fixnum can be converted to a float without
// introducing any error at all... but now on a 64-bit system one can
// have a fixnum with value over 2^52 that gers rounded to create a
// double precision float. Consider say the value 2^59-1 which will end
// up as a double precision value that is exactly 2^59 and it may thus
// show as being equal to rather than less than the floating point input.
// This issue can arise for comparison against doubles as well as single
// and short floats.
    if (!SIXTY_FOUR_BIT)
        return static_cast<double>(int_of_fixnum(a)) <
               value_of_immediate_float(b);
    return lessp_i64d(int_of_fixnum(a), value_of_immediate_float(b));
}

inline bool lessp_i_b(LispObject, LispObject b)
//
// a fixnum and a bignum can never be equal, and the magnitude of
// the bignum must be at least as great as that of the fixnum, hence
// to do a comparison I just need to look at sign of the bignum.
//
{   size_t len = bignum_length(b);
    int32_t msd = bignum_digits(b)[(len-CELL-4)/4];
    return (msd >= 0);
}

inline bool lessp_i_r(LispObject a, LispObject b)
{   THREADID;
    Save save(THREADARG b);  // compute a < p/q  as a*q < p
    a = times2(a, denominator(b));
    save.restore(b);
    return lessp2(a, numerator(b));  // lessp2 is NOT an inline function!
}

inline bool lessp_i_f(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return static_cast<double>(int_of_fixnum(a)) < single_float_val(b);
    return lessp_i64d(int_of_fixnum(a), single_float_val(b));
}

inline bool lessp_i_d(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return static_cast<double>(int_of_fixnum(a)) < double_float_val(b);
    return lessp_i64d(int_of_fixnum(a), double_float_val(b));
}

#ifdef HAVE_SOFTFLOAT
inline bool lessp_i_l(LispObject a, LispObject b)
{   float128_t aa;
    i64_to_f128M((int64_t)int_of_fixnum(a), &aa);
    return f128M_lt(&aa, reinterpret_cast<float128_t *>(long_float_addr(
                        b)));
}
#endif // HAVE_SOFTFLOAT

inline bool lessp_f_i(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return single_float_val(a) < static_cast<double>(int_of_fixnum(b));
    return lessp_di64(single_float_val(a), int_of_fixnum(b));
}

inline bool lessp_d_i(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return double_float_val(a) < static_cast<double>(int_of_fixnum(b));
    return lessp_di64(double_float_val(a), int_of_fixnum(b));
}

#ifdef HAVE_SOFTFLOAT
inline bool lessp_l_i(LispObject a, LispObject b)
{   float128_t bb;
    i64_to_f128M((int64_t)int_of_fixnum(b), &bb);
    return f128M_lt(reinterpret_cast<float128_t *>(long_float_addr(a)),
                    &bb);
}
#endif // HAVE_SOFTFLOAT

inline bool lessp_rawd_b(double a, LispObject b)
// a is a floating point number and b a bignum.  Compare them.
{   size_t n = (bignum_length(b)-CELL-4)/4;
    int32_t bn = (int32_t)bignum_digits(b)[n];
// The value represented by b can not be in the range that fixnums
// cover, so if a is in that range I need only inspect the sign of b.
// However I need to note that the range of fixnums is differs based on
// whether I am on a 32 or 64 bit system!
//
// I test "< -MOST_NEGATIVE_FIXVAL" rather than "<= MOST_POSITIVE_FIXVAL"
// because the largest positive fixnum will not convert to a double in a
// loss-free manner on a 64-bit machine, while the most negative one will.
    if (static_cast<double>(MOST_NEGATIVE_FIXVAL) <= a &&
        a < -static_cast<double>(MOST_NEGATIVE_FIXVAL)) return (bn >= 0);
//
// If b is a one-word bignum I can convert it to floating point
// with no loss of accuracy at all.
//
    if (n == 0) return a < static_cast<double>(bn);
//
// For two-digit bignums I first check if the float is so big that I can
// tell that it dominates the bignum, and if not I subtract the top digit
// of the bignum from both sides... in the critical case where the two
// values are almost the same that subtraction will not lead to loss of
// accuracy (at least provided that my floating point was implemented
// with a guard bit..)
//
    if (n == 1)
    {   if (a >= static_cast<double>(INT64_C(0x4000000000000000))) return
                false;
        else if (a < -static_cast<double>(INT64_C(0x4000000000000000))) return
                true;
        a -= TWO_31*(int32_t)bn;
        return a < static_cast<double>(bignum_digits(b)[0]);
    }
//
// If the two operands differ in their signs then all is easy.
//
    if (bn >= 0 && a < 0.0) return true;
    if (bn < 0 && a >= 0.0) return false;
//
// Now I have a 3 or more digit bignum, so here I will (in effect)
// convert the float to a bignum and then perform the comparison.. that
// does the best I can to avoid error.  I do not actually have to create
// a datastructure for the bignum provided I can collect up the data that
// would have to be stored in it.  See lisp_fix (arith08.c) for related code.
//
    int32_t a2;
    uint32_t a1, a0;
    intptr_t x = double_to_3_digits(a, a2, a1, a0);
// If the float would turn into a bignum with either fewer or more digits
// than the value it is to be compared with the result is based on just the
// sign bit of whichever is larger.
    if (n != 2+(size_t)x)
    {   if (n < 2+(size_t)x) return (a < 0);
        else return (bn >= 0);
    }
// Now the two numbers are rather similar in magnitude. Compare the
// first 3 digits of the bignum forms.
    if (a2 < bn) return true;
    else if (a2 > bn) return false;
    else if (a1 < bignum_digits(b)[n-1]) return true;
    else if (a1 > bignum_digits(b)[n-1]) return false;
    else if (a0 < bignum_digits(b)[n-2]) return true;
    else if (a0 > bignum_digits(b)[n-2]) return false;
    for (size_t i=0; i<n-2; i++)
        if (bignum_digits(b)[i] != 0) return true;
    return false;
}

inline bool greaterp_rawd_b(double a, LispObject b)
// logic here is much as for the lessp test. By leavinbg the commentary
// out of this version you can get a clearer idea of how much code is
// involved.
{   size_t n = (bignum_length(b)-CELL-4)/4;
    int32_t bn = (int32_t)bignum_digits(b)[n];
    if (static_cast<double>(MOST_NEGATIVE_FIXVAL) <= a &&
        a < -static_cast<double>(MOST_NEGATIVE_FIXVAL)) return (bn < 0);
    if (n == 0) return a > static_cast<double>(bn);
    if (n == 1)
    {   if (a >= static_cast<double>(INT64_C(0x4000000000000000))) return
                true;
        else if (a < -static_cast<double>(INT64_C(0x4000000000000000))) return
                false;
        a -= TWO_31*(int32_t)bn;
        return a > static_cast<double>(bignum_digits(b)[0]);
    }
    if (bn >= 0 && a < 0.0) return false;
    if (bn < 0 && a >= 0.0) return true;
    int32_t a2;
    uint32_t a1, a0;
    intptr_t x = double_to_3_digits(a, a2, a1, a0);
    if (n != 2+(size_t)x)
    {   if (n < 2+(size_t)x) return (a > 0);
        else return (bn < 0);
    }
    if (a2 > bn) return true;
    else if (a2 < bn) return false;
    else if (a1 > bignum_digits(b)[n-1]) return true;
    else if (a1 < bignum_digits(b)[n-1]) return false;
    else if (a0 > bignum_digits(b)[n-2]) return true;
    else if (a0 < bignum_digits(b)[n-2]) return false;
// Any nonzero trailing digits in b only render its value larger and so
// if I have got here I already know that a is NOT strictly bigger than b.
    return false;
}

inline bool lessp_b_rawd(LispObject a, double b)
{   return greaterp_rawd_b(b, a);
}

#ifdef HAVE_SOFTFLOAT
inline bool lessp_rawl_b(float128_t *a, LispObject b)
{
// I am not going to worry too much about performance here - code
// simplicity will trump that. The strategy to be used will be as follows:
//    If b uses at no more than 113 bits then I can convert b to
//    a float128_t without any loss and then do the comparison.
// [I rather hope that will in fact be a common case.]
//    Looking at the exponent of the float128_t one can work out how it
//    would align againt the bignum. It then becomes easy to see if the
//    top bit of the mantissa aligns nicely againt the top word of the
//    bignum. It will only be necessary to check 4 words of the bignum.
// [Actually this does not look too bad either.]
    size_t n = (length_of_header(numhdr(b))-CELL)/4;
    float128_t bb, w0, w1;
    int32_t k;
    switch (n)
    {   case 1: // Only happens on 32-bit systems
            i32_to_f128M((int32_t)bignum_digits(b)[0], &bb);
            return f128M_lt(a, &bb);
        case 2:
            i64_to_f128M(bignum_digits64(b, 1)<<31 | bignum_digits(b)[0], &bb);
            return f128M_lt(a, &bb);
        case 3:
            i64_to_f128M(bignum_digits64(b, 2)<<31 | bignum_digits(b)[1], &w1);
#ifdef LITTLEENDIAN
            w1.v[1] += UINT64_C(31) << 48;
#else
            w1.v[0] += UINT64_C(31) << 48;
#endif
            ui32_to_f128M((int32_t)bignum_digits(b)[0], &w0);
            f128M_add(&w0, &w1, &bb);
            return f128M_lt(a, &bb);
        case 4:
            k = (int32_t)bignum_digits(b)[3];
            if (k > 0x80000 ||
                k < -0x80000) break;
// I am now confident that b will turn into a number that will convert to
// a 128-bit float without rounding.
            i64_to_f128M(bignum_digits64(b,3)<<31 | bignum_digits(b)[2], &w1);
#ifdef LITTLEENDIAN
            w1.v[1] += UINT64_C(62) << 48;  // multiply by 2^62
#else
            w1.v[0] += UINT64_C(62) << 48;
#endif
            ui64_to_f128M(bignum_digits64(b,1)<<31 | bignum_digits(b)[0], &w0);
            f128M_add(&w0, &w1, &bb);
            return f128M_lt(a, &bb);
        default:
            break;
    }
// Here the integer uses at least 113 bits to represent its absolute value.
    return aerror("comparison between long float and large bignum - not implemented yet");
}

inline bool lessp_b_rawl(LispObject a, float128_t *b)
{   size_t n = (length_of_header(numhdr(a))-CELL)/4;
    float128_t aa, w0, w1;
    int32_t k;
    switch (n)
    {   case 1: // Only happens on 32-bit systems
            i32_to_f128M((int32_t)bignum_digits(a)[0], &aa);
            return f128M_lt(&aa, b);
        case 2:
            i64_to_f128M(bignum_digits64(a, 1)<<31 | bignum_digits(a)[0], &aa);
            return f128M_lt(&aa, b);
        case 3:
            i64_to_f128M(bignum_digits64(a, 2)<<31 | bignum_digits(a)[1], &w1);
#ifdef LITTLEENDIAN
            w1.v[1] += UINT64_C(31) << 48;
#else
            w1.v[0] += UINT64_C(31) << 48;
#endif
            ui32_to_f128M((int32_t)bignum_digits(a)[0], &w0);
            f128M_add(&w0, &w1, &aa);
            return f128M_lt(&aa, b);
        case 4:
            k = (int32_t)bignum_digits(a)[3];
            if (k > 0x80000 ||
                k < -0x80000) break;
// I am now confident that a will turn into a number that will convert to
// a 128-bit float without rounding.
            i64_to_f128M(bignum_digits64(a,3)<<31 | bignum_digits(a)[2], &w1);
#ifdef LITTLEENDIAN
            w1.v[1] += UINT64_C(62) << 48;  // multiply by 2^62
#else
            w1.v[0] += UINT64_C(62) << 48;
#endif
            ui64_to_f128M(bignum_digits64(a,1)<<31 | bignum_digits(a)[0], &w0);
            f128M_add(&w0, &w1, &aa);
            return f128M_lt(&aa, b);
        default:
            break;
    }
// Here the integer uses at least 113 bits to represent its absolute value.
    return aerror("comparison between long float and large bignum - not implemented yet");
}

inline bool lessp_rawl_r(float128_t *a, LispObject b)
{   aerror("comparison between long float and raion not coded yet");
    return false;
}

inline bool lessp_r_rawl(LispObject a, float128_t *b)
{   aerror("comparison between long float and rational not coded yet");
    return false;
}

#endif // HAVE_SOFTFLOAT

inline bool lessp_s_s(LispObject a, LispObject b)
{   return value_of_immediate_float(a) < value_of_immediate_float(b);
}

inline bool lessp_s_f(LispObject a, LispObject b)
{   return value_of_immediate_float(a) < single_float_val(b);
}

inline bool lessp_s_d(LispObject a, LispObject b)
{   return value_of_immediate_float(a) < double_float_val(b);
}

inline bool lessp_f_f(LispObject a, LispObject b)
{   return single_float_val(a) < single_float_val(b);
}

inline bool lessp_f_d(LispObject a, LispObject b)
{   return single_float_val(a) < double_float_val(b);
}

inline bool lessp_d_d(LispObject a, LispObject b)
{   return double_float_val(a) < double_float_val(b);
}

inline bool lessp_f_s(LispObject a, LispObject b)
{   return single_float_val(a) < value_of_immediate_float(b);
}

inline bool lessp_d_s(LispObject a, LispObject b)
{   return double_float_val(a) < value_of_immediate_float(b);
}

inline bool lessp_d_f(LispObject a, LispObject b)
{   return double_float_val(a) < single_float_val(b);
}

inline bool lessp_b_f(LispObject a, LispObject b)
{   return lessp_b_rawd(a, single_float_val(b));
}

inline bool lessp_b_d(LispObject a, LispObject b)
{   return lessp_b_rawd(a, double_float_val(b));
}

inline bool lessp_d_b(LispObject a, LispObject b)
{   return lessp_rawd_b(double_float_val(a), b);
}

#ifdef HAVE_SOFTFLOAT
inline bool lessp_b_l(LispObject a, LispObject b)
{   return lessp_b_rawl(a,
                        reinterpret_cast<float128_t *>(long_float_addr(b)));
}
#endif // HAVE_SOFTFLOAT

inline bool lessp_r_r(LispObject a, LispObject b)
{   LispObject c;
    THREADID;
    Save save(THREADARG a, b);
    c = times2(numerator(a), denominator(b));
    save.restore(a, b);
    Save save1(THREADARG c);
    b = times2(numerator(b), denominator(a));
    save1.restore(c);
    return lessp2(c, b);
}

inline bool lessp_rawd_r(double a, LispObject b)
// Compare float with ratio... painfully expensive.
{   LispObject a1 = rationalf(a);
    return lessp2(a1, b);
}

inline bool lessp_r_rawd(LispObject a, double b)
{   LispObject b1 = rationalf(b);
    return lessp2(a, b1);
}

inline bool lessp_d_r(LispObject a, LispObject b)
{   return lessp_rawd_r(double_float_val(a), b);
}

inline bool lessp_r_d(LispObject a, LispObject b)
{   return lessp_r_rawd(a, double_float_val(b));
}

inline bool lessp_s_i(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return value_of_immediate_float(a) < static_cast<double>
               (int_of_fixnum(b));
// Again beware fixnums that are over 2^53 and can not be converted to a
// double precision float losslessly.
    return lessp_di64(value_of_immediate_float(a), int_of_fixnum(b));
}

inline bool lessp_s_b(LispObject a, LispObject b)
{   return lessp_rawd_b(value_of_immediate_float(a), b);
}

inline bool lessp_s_r(LispObject a, LispObject b)
{   return lessp_rawd_r(value_of_immediate_float(a), b);
}

inline bool lessp_b_i(LispObject a, LispObject)
{   size_t len = bignum_length(a);
    int32_t msd = bignum_digits(a)[(len-CELL-4)/4];
    return (msd < 0);
}

inline bool lessp_b_s(LispObject a, LispObject b)
{   return lessp_b_rawd(a, value_of_immediate_float(b));
}

inline bool lessp_b_b(LispObject a, LispObject b)
{   size_t lena = bignum_length(a),
               lenb = bignum_length(b);
    if (lena > lenb)
    {   int32_t msd = bignum_digits(a)[(lena-CELL-4)/4];
        return (msd < 0);
    }
    else if (lenb > lena)
    {   int32_t msd = bignum_digits(b)[(lenb-CELL-4)/4];
        return (msd >= 0);
    }
    lena = (lena-CELL-4)/4;
    // lenb == lena here
    {   int32_t msa = bignum_digits(a)[lena],
                    msb = bignum_digits(b)[lena];
        if (msa < msb) return true;
        else if (msa > msb) return false;
//
// Now the leading digits of the numbers agree, so in particular the numbers
// have the same sign.
//
        if (lena != 0) for (;;)
            {   lena--;
                uint32_t da = bignum_digits(a)[lena],
                         db = bignum_digits(b)[lena];
                if (da == db && lena != 0) continue;
                return (da < db);
            }
        return false;      // numbers are the same
    }
}

inline bool lessp_b_r(LispObject a, LispObject b)
{   return lessp_i_r(a, b);
}

inline bool lessp_r_i(LispObject a, LispObject b)
{   THREADID;
    Save save(THREADARG a);
    b = times2(b, denominator(a));
    save.restore(a);
    return lessp2(numerator(a), b);
}

inline bool lessp_r_s(LispObject a, LispObject b)
{   return lessp_r_rawd(a, value_of_immediate_float(b));
}

inline bool lessp_r_b(LispObject a, LispObject b)
{   return lessp_r_i(a, b);
}


inline bool lessp_r_f(LispObject a, LispObject b)
{   return lessp_r_rawd(a, single_float_val(b));
}

inline bool lessp_f_b(LispObject a, LispObject b)
{   return lessp_rawd_b(single_float_val(a), b);
}

inline bool lessp_f_r(LispObject a, LispObject b)
{   return lessp_rawd_r(single_float_val(a), b);
}

inline bool lessp_c_i(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_c_b(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_c_r(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_c_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_c_s(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_c_f(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_c_d(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_c_l(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_i_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_b_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_r_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_s_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_f_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_d_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

#ifdef HAVE_SOFTFLOAT
inline bool lessp_l_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
    return false;
}

inline bool lessp_l_b(LispObject a, LispObject b)
{   return lessp_rawl_b(reinterpret_cast<float128_t *>
                        (long_float_addr(a)), b);
}

inline bool lessp_l_r(LispObject a, LispObject b)
{   return lessp_rawl_r(reinterpret_cast<float128_t *>
                        (long_float_addr(a)), b);
}

inline bool lessp_l_s(LispObject a, LispObject b)
{   Double_union d;
    d.f = value_of_immediate_float(b);
    float128_t bb;
    f64_to_f128M(d.f64, &bb);
    return f128M_lt(reinterpret_cast<float128_t *>(long_float_addr(a)),
                    &bb);
}

inline bool lessp_l_f(LispObject a, LispObject b)
{   Double_union d;
    d.f = single_float_val(b);
    float128_t bb;
    f64_to_f128M(d.f64, &bb);
    return f128M_lt(reinterpret_cast<float128_t *>(long_float_addr(a)),
                    &bb);
}

inline bool lessp_l_d(LispObject a, LispObject b)
{   Double_union d;
    d.f = static_cast<double>(double_float_val(b));
    float128_t bb;
    f64_to_f128M(d.f64, &bb);
    return f128M_lt(reinterpret_cast<float128_t *>(long_float_addr(a)),
                    &bb);
}

inline bool lessp_l_l(LispObject a, LispObject b)
{   return f128M_lt(reinterpret_cast<float128_t *>(long_float_addr(
                        a)), reinterpret_cast<float128_t *>(long_float_addr(b)));
}

inline bool lessp_r_l(LispObject a, LispObject b)
{   return lessp_r_rawl(a,
                        reinterpret_cast<float128_t *>(long_float_addr(b)));
}

inline bool lessp_s_l(LispObject a, LispObject b)
{   Double_union d;
    d.f = value_of_immediate_float(a);
    float128_t aa;
    f64_to_f128M(d.f64, &aa);
    return f128M_lt(&aa, reinterpret_cast<float128_t *>(long_float_addr(
                        b)));
}

inline bool lessp_f_l(LispObject a, LispObject b)
{   Double_union d;
    d.f = single_float_val(a);
    float128_t aa;
    f64_to_f128M(d.f64, &aa);
    return f128M_lt(&aa, reinterpret_cast<float128_t *>(long_float_addr(
                        b)));
}

inline bool lessp_d_l(LispObject a, LispObject b)
{   Double_union d;
    d.f = static_cast<double>(double_float_val(a));
    float128_t aa;
    f64_to_f128M(d.f64, &aa);
    return f128M_lt(&aa, reinterpret_cast<float128_t *>(long_float_addr(
                        b)));
}
#endif // HAVE_SOFTFLOAT

// Now I have given all the helper type-specific rules - do the
// big dispatch.

arith_dispatch_2(inline, bool, lessp)

bool greaterp2(LispObject a, LispObject b)
{   return lessp(b, a);
}

bool lessp2(LispObject a, LispObject b)
{   return lessp(a, b);
}

inline bool geq_i_i(LispObject a1, LispObject a2)
{   return (intptr_t)a1 >= (intptr_t)a2;
}

// A bignum can not be equal to a fixnum, so I>=B is the same as B<I
inline bool geq_i_b(LispObject a1, LispObject a2)
{   return lessp_b_i(a2, a1);
}

inline bool geq_i_r(LispObject a1, LispObject a2)
{   return !lessp_i_r(a1, a2);
}

inline bool geq_i_c(LispObject a1, LispObject a2)
{   return !lessp_i_c(a1, a2);
}

inline bool geq_i_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_i_s(a1, a2);
}

inline bool geq_i_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_i_f(a1, a2);
}

inline bool geq_i_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_i_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline bool geq_i_l(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_i_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline bool geq_b_i(LispObject a1, LispObject a2)
{   return lessp_i_b(a2, a1);
}

inline bool geq_b_b(LispObject a1, LispObject a2)
{   return !lessp_b_b(a1, a2);
}

inline bool geq_b_r(LispObject a1, LispObject a2)
{   return !lessp_b_r(a1, a2);
}

inline bool geq_b_c(LispObject a1, LispObject a2)
{   return !lessp_b_c(a1, a2);
}

inline bool geq_b_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_b_s(a1, a2);
}

inline bool geq_b_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_b_f(a1, a2);
}

inline bool geq_b_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_b_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline bool geq_b_l(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_b_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline bool geq_r_i(LispObject a1, LispObject a2)
{   return !lessp_r_i(a1, a2);
}

inline bool geq_r_b(LispObject a1, LispObject a2)
{   return !lessp_r_b(a1, a2);
}

inline bool geq_r_r(LispObject a1, LispObject a2)
{   return !lessp_r_r(a1, a2);
}

inline bool geq_r_c(LispObject a1, LispObject a2)
{   return !lessp_r_c(a1, a2);
}

inline bool geq_r_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_r_s(a1, a2);
}

inline bool geq_r_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_r_f(a1, a2);
}

inline bool geq_r_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_r_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline bool geq_r_l(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_r_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline bool geq_c_i(LispObject a1, LispObject a2)
{   return !lessp_c_i(a1, a2);
}

inline bool geq_c_b(LispObject a1, LispObject a2)
{   return !lessp_c_b(a1, a2);
}

inline bool geq_c_r(LispObject a1, LispObject a2)
{   return !lessp_c_r(a1, a2);
}

inline bool geq_c_c(LispObject a1, LispObject a2)
{   return !lessp_c_c(a1, a2);
}

inline bool geq_c_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_c_s(a1, a2);
}

inline bool geq_c_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_c_f(a1, a2);
}

inline bool geq_c_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_c_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline bool geq_c_l(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_c_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline bool geq_s_i(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_i(a1, a2);
}

inline bool geq_s_b(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_b(a1, a2);
}

inline bool geq_s_r(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_r(a1, a2);
}

inline bool geq_s_c(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_c(a1, a2);
}

inline bool geq_s_s(LispObject a1, LispObject a2)
{   return value_of_immediate_float(a1) >= value_of_immediate_float(
               a2);
}

inline bool geq_s_f(LispObject a1, LispObject a2)
{   return value_of_immediate_float(a1) >= single_float_val(a2);
}

inline bool geq_s_d(LispObject a1, LispObject a2)
{   return value_of_immediate_float(a1) >= double_float_val(a2);
}

#ifdef HAVE_SOFTFLOAT
inline bool geq_s_l(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_s_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline bool geq_f_i(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_i(a1, a2);
}

inline bool geq_f_b(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_b(a1, a2);
}

inline bool geq_f_r(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_r(a1, a2);
}

inline bool geq_f_c(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_c(a1, a2);
}

inline bool geq_f_s(LispObject a1, LispObject a2)
{   return single_float_val(a1) >= value_of_immediate_float(a2);
}

inline bool geq_f_f(LispObject a1, LispObject a2)
{   return single_float_val(a1) >= single_float_val(a2);
}

inline bool geq_f_d(LispObject a1, LispObject a2)
{   return single_float_val(a1) >= double_float_val(a2);
}

#ifdef HAVE_SOFTFLOAT
inline bool geq_f_l(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_f_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline bool geq_d_i(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_i(a1, a2);
}

inline bool geq_d_b(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_b(a1, a2);
}

inline bool geq_d_r(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_r(a1, a2);
}

inline bool geq_d_c(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_c(a1, a2);
}

inline bool geq_d_s(LispObject a1, LispObject a2)
{   return double_float_val(a1) >= value_of_immediate_float(a2);
}

inline bool geq_d_f(LispObject a1, LispObject a2)
{   return double_float_val(a1) >= single_float_val(a2);
}

inline bool geq_d_d(LispObject a1, LispObject a2)
{   return double_float_val(a1) >= double_float_val(a2);
}

#ifdef HAVE_SOFTFLOAT
inline bool geq_d_l(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_d_l(a1, a2);
}

inline bool geq_l_i(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    return !lessp_l_i(a1, a2);
}

inline bool geq_l_b(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    return !lessp_l_b(a1, a2);
}

inline bool geq_l_r(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    return !lessp_l_r(a1, a2);
}

inline bool geq_l_c(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    return !lessp_l_c(a1, a2);
}

inline bool geq_l_s(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_l_s(a1, a2);
}

inline bool geq_l_f(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_l_f(a1, a2);
}

inline bool geq_l_d(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_l_d(a1, a2);
}

inline bool geq_l_l(LispObject a1, LispObject a2)
{   if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a1)))) return false;
    if (f128M_nan(reinterpret_cast<float128_t *>(long_float_addr(
                      a2)))) return false;
    return !lessp_l_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

arith_dispatch_2(inline, bool, geq)

bool lesseq2(LispObject a, LispObject b)
{   return geq(b, a);
}

bool geq2(LispObject a, LispObject b)
{   return geq(a, b);
}

// end of arith04.cpp
