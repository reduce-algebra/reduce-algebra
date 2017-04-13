// arith04.cpp                             Copyright (C) 1991-2017 Codemist

//
// Arithmetic functions.
//    <, rationalize
//
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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


LispObject make_n_word_bignum(int32_t a2, uint32_t a1, uint32_t a0, size_t n)
//
// This make a bignum with n words of data and digits a1, a2, a3 and
// then n zeros.  Will only be called with n>=0 and a1, a2, a3 already
// correctly structured to make a valid bignum. NOTE that the number n
// as passed is the number of zero words to be inserted before the 3
// words at the end!
//
{   size_t i;
    LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*n+12);
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
    LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*n+16);
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
    LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*n+20);
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
    else return make_n_word_bignum(((int32_t)1) << (n % 31), 0, 0, (n/31)-2);
}

static inline LispObject make_fix_or_big2(int32_t a1, uint32_t a2)
{   return make_lisp_integer64(((int64_t)a1 << 31) | a2);
}

LispObject rationalf(double d)
{
// If the value of the double is >= 2^52 then it must be an exact integer.
// In that case rationalf will just return the integer value using fix,
// and in this case it is immaterial what rounding mode I indicate there
// since no rounding should apply!
#define FP_INT_LIMIT ((double)((int64_t)1<<52))
    if (d <= -(double)FP_INT_LIMIT || d >= (double)FP_INT_LIMIT)
        return lisp_fix(make_boxfloat(d, TYPE_DOUBLE_FLOAT), FIX_ROUND);
// Now the magnitude if d is modest, so it is safe to cast it to
// an int64_t. When I cast the result back to a float there will not be
// any need for rounding, so I can detect cases where the floating point
// input has a value that is exactly an integer.
    int64_t i = (int64_t)d;
    if (d == (double)i) return make_lisp_integer64(i);
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
    push(w);
    LispObject den = make_power_of_two(-x);
    pop(w);
    return make_ratio(w, den);
}

// The intent here is to take a single precision floating point value and
// mask off its low 4 bits. The code here is a fine example of the sort
// of thing that runs up against strict aliasing rules. Here I believe that
// the use of memcpy ought to sort that out!

double truncate20(double d)
{   Float_union aa, bb;
    aa.f = d;
    memcpy(&bb, &aa, sizeof(bb));
    bb.i &= ~0xf;
    memcpy(&aa, &bb, sizeof(aa));
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
    else if (dd < 0.0) d = -dd; else d = dd;
// Now d is the absolute value of the float that I need to deal with.
// If the absolute value of the input is large just convert it to an
// integer.
    if (d >= (double)((uint64_t)1<<bits))
        return lisp_fix(make_boxfloat(dd, TYPE_DOUBLE_FLOAT), FIX_ROUND);
// If the value is small first convert it to a rational number p/q, then
// find the integer value r of q/p and return (1/r).
    if (d <= 1.0/(double)((uint64_t)1<<bits))
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
        volatile double d1 = frexp(d, &x);
        p = (uint64_t)(d1*(double)((uint64_t)1<<53));
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
        double d1 = frexp(d, &x);
        p = (uint64_t)(d1*(double)((uint64_t)1<<53));
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
//      __int128_t w1 = (__int128_t)1<<(53-x);
//      __int128_t w2 = (__int128_t)a*(__int128_t)p;
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
    while (bits==53 ? d != (double)u1/(double)v1 :
           bits==24 ? d != (float)((double)u1/(double)v1) :
           d != truncate20((double)u1/(double)v1))
    {   a = p/q;
        uint64_t u2 = u0 + a*u1;
        uint64_t v2 = v0 + a*v1;
        a = p % q;
        p = q;   q = a;
        u0 = u1; u1 = u2;
        v0 = v1; v1 = v2;
    }
    if (dd < 0.0) u1 = -u1;
    LispObject p1 = make_lisp_integer64(u1);
    if (v1 == 1) return p1;
    push(p1);
    LispObject q1 = make_lisp_integer64(v1);
    pop(p1);
    return make_ratio(p1, q1);
}

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
    push(w);
    LispObject den = make_power_of_two(-x);
    pop(w);
    return make_ratio(w, den);
}

// This is expected to adjust the ratio returned to support 113 bits
// of precision.
// I have taken the code from rationalize (as above) and removed the
// comments to make it shorter, and then the task is just to re-work
// it to cope with 128-bit wide values rather than 64-bit wide ones!

// First I need a little library to support 124-bit unsigned integers,
// I am not going to worry about performance at all here! Well I could
// have just delegated all this to the existing general bignum code, but
// that would have meant I needed to worry more about garbage collection
// and it would have carried a rather large amount of overhead in dispatch
// as between all the different arithmetic types. Given then I know I
// am working with a fixed (albeit mildly long) precision I end up with
// the mess I have here!
//
// Once I have debugged the version that uses nothin beyond uint64_t I
// will consider an alternative version that uses a 128-bit integer type
// that is provided by the platform. But given that I will want to support
// systems where that will not be available I need to get the portable
// version working first.


#if defined HAVE_UINT128_T && defined EXPERIMENT

// This is to remind me of future plans!

typedef struct __u124_t
{   uint128_t n;
} u124_t;

u124_t u124_1 = {1};

void u124_prinhex(const char *msg, u124_t *a)
{   printf("%s%.8x %.8x %.8x %.8x\n", msg,
        (uint32_t)(a->n >> 96), (uint32_t)(a->n >> 64),
        (uint32_t)(a->n >> 32), (uint32_t)a->n);
}

LispObject make_lisp_integer124(u124_t *a)
{   return make_lisp_integer128(a->n);
}

void u124_zero(u124_t *a)
{   a->n = 0;
}

// Set a to the value 2^n (n positive and in range).

void u124_two_to_n(u124_t *a, int n)
{   a->n = (uint128_t)1 << n;
}

// Test for zero.

bool u124_zerop(u124_t *a)
{   return a->n == 0;
}

bool u124_onep(u124_t *a)
{   return a->n == 1;
}

// The numbers are unsigned, but I will describe them as "negative"
// if the top bit is set.

bool u124_minusp(u124_t *a)
{   return (int128_t)(a->n) < 0;
}

// Comparisons.

bool u124_lessp(u124_t *a, u124_t *b)
{   return a->n < b->n;
}

bool u124_leq(u124_t *a, u124_t *b)
{   return a->n <= b->n;
}

// "Negating" does it work modulo 2^124.

void u124_negate(u124_t *a, u124_t *b)
{   b->n = -a->n;
}

// Addition and subtraction.

void u124_add(u124_t *a, u124_t *b, u124_t *c)
{   c->n = a->n + b->n;
}

void u124_sub(u124_t *a, u124_t *b, u124_t *c)
{   c->n = a->n - b->n;
}

// Multiplication only keep the low 124 bits of the product. Well 128
// bits here!

void u124_mul(u124_t *a, u124_t *b, u124_t *c)
{   c->n = a->n * b->n;
}

void u124_leftshift(u124_t *a)
{   a->n = a->n << 1;
}

void u124_rightshift(u124_t *a)
{   a->n = a->n >> 1;
}

// To perform variable shifts I take a path that was quickest and easiest
// for me to code. I shift successivly in units of 31, 6 and 1. With more
// care I could do everythin in close to a single sequence of (variable)
// shifts. but I do not view this as liable to be worth the coding effort,
// even though that would not be vary great..

void u124_leftshiftn(u124_t *a, int n)
{   a->n = a->n << n;
}

void u124_rightshiftn(u124_t *a, int n)
{   a->n = a->n >> n;
}

// Division (and remainder).

void u124_divrem(u124_t *a, u124_t *b, u124_t *q, u124_t *r)
{   q->n = a->n / b->n;
    r->n = a->n % b->n;
}

// Now I need to be able to convert between float128_t and u124_t with
// "fix" and "float" operations. I will only concern myself with positive
// numbers, and my expected use will be that I only attempt to fix
// values that will fit within 113 bits (ie well within 128), and
// I will only float values that are in around the same range.

void u124_fix(float128_t *a, u124_t *b)
{   if (f128M_eq(a, &f128_0))
    {   b->n = 0;
        return;
    }
// I am not going to do anything clever with NaN or infinity here - they
// are just not permitted and would lead to chaos.
    float128_t aa;
    int x;
    f128M_frexp(a, &aa, &x);
// Now I take the 113 bits of mantissa (including an implicit bit) and
// shuffle to be in the form of the u124_t multiple precision integer.
    uint64_t hi = (aa.v[HIPART] & UINT64_C(0x0000ffffffffffff)) |
                  UINT64_C(0x0001000000000000);
    uint128_t w = aa.v[LOPART] | ((uint128_t)hi<<64);
// Now I may need to shift b by an amount determined by x.
    x = x - 113;
    if (x > 0) w = w<<x;
    else if (x < 0) w = w>>(-x);
    b->n = w;
}

void u124_float(u124_t *a, float128_t *b)
{   uint128_t aa = a->n;
    if (aa == 0)
    {   *b = f128_0;
        return;
    }
    int x = 113;
// Now I want to normalize the integer so that the bit at position
// 00010000:00000000:00000000:00000000 is set, ie the one that will be
// the "hidden bit".
    while (aa >= ((uint128_t)1<<113))
    {   aa = aa>>1;
        x++;
    }
    while (aa < ((uint128_t)1<<(96-24+1)))
    {   aa = aa<<24;
        x = x - 24;
    }
    while (aa < ((uint128_t)1<<(96-5+1)))
    {   aa = aa<<5;
        x = x - 5;
    }
    while (aa < ((uint128_t)1<<112))
    {   aa = aa<<1;
        x--;
    }
    uint64_t ahi = (uint64_t)(aa>>64) & UINT64_C(0x0000ffffffffffff);
    ahi = ahi | ((uint64_t)(x + 0x3ffe)<<48);
    b->v[HIPART] = ahi;
    b->v[LOPART] = (uint64_t)aa; 
}

#else // HAVE_UINT128_T

typedef struct __u124_t
{   uint32_t d[4];
} u124_t;

u124_t u124_1 = {{1, 0, 0, 0}};

// For debugging purposes I will arrange to be able to print values in
// hex notation.

void u124_prinhex(const char *msg, u124_t *a)
{   uint32_t d0 = a->d[0], d1 = a->d[1], d2 = a->d[2], d3 = a->d[3];
// Now adjust for the fact that I only have 31 bits stored in each digit
    d0 |= (d1<<31);
    d1 = (d1>>1) | (d2<<30);
    d2 = (d2>>2) | (d3<<29);
    d3 = (d3>>3);
    printf("%s%.8x %.8x %.8x %.8x\n", msg, d3, d2, d1, d0);
}

// For conversion to a bignum the fact that my number is represented in
// 31-bit digits is really convenient. But I need to cope with
// signed values and work out how many digits are actually required, so this
// is still going to be astonishingly ugly!

LispObject make_lisp_integer124(u124_t *a)
{   uint32_t *d = a->d;
// I think it will be nicer to handle the positive and negative cases
// as separate ones.
    if ((d[3] & 0x40000000) == 0) // i.e. the positive case
    {   if (d[3] != 0 || (d[2] & 0x40000000) != 0)
            return make_four_word_bignum(d[3], d[2], d[1], d[0]);
        if (d[2] != 0 || (d[1] & 0x40000000) != 0)
            return make_three_word_bignum(d[2], d[1], d[0]);
        return make_lisp_integer64(((int64_t)d[1]<<31) | d[0]);
    }
// Now I have the negative case. Note that the top bit of each 32-bit
// word is zero, and I will need to change that when I pack up the value.
    if (d[3] != 0x7fffffff || (d[2] & 0x40000000) == 0)
        return make_four_word_bignum(d[3] | 0x80000000, d[2], d[1], d[0]);
    if (d[2] != 0x7fffffff || (d[1] & 0x40000000) == 0)
        return make_three_word_bignum(d[2] | 0x80000000, d[1], d[0]);
    int64_t r = (int32_t)(d[1] | 0x80000000);
    return make_lisp_integer64((r<<31) | d[0]);
}

void u124_zero(u124_t *a)
{   a->d[0] = a->d[1] = a->d[2] = a->d[3] = 0;
}

// Set a to the value 2^n (n positive and in range).

void u124_two_to_n(u124_t *a, int n)
{   a->d[0] = a->d[1] = a->d[2] = a->d[3] = 0;
    a->d[n/31] = 1<<(n%31);
}

// Test for zero.

bool u124_zerop(u124_t *a)
{   return a->d[0] == 0 &&
           a->d[1] == 0 &&
           a->d[2] == 0 &&
           a->d[3] == 0;
}

bool u124_onep(u124_t *a)
{   return a->d[0] == 1 &&
           a->d[1] == 0 &&
           a->d[2] == 0 &&
           a->d[3] == 0;
}

// The numbers are unsigned, but I will describe them as "negative"
// if the top bit is set.

bool u124_minusp(u124_t *a)
{   return ((a->d[3] & 0x40000000) != 0);
}

// Comparisons.

bool u124_lessp(u124_t *a, u124_t *b)
{   return a->d[3] < b->d[3] ||
           (a->d[3] == b->d[3] &&
            (a->d[2] < b->d[2] ||
             (a->d[2] == b->d[2] &&
              (a->d[1] < b->d[1] ||
               (a->d[1] == b->d[1] &&
                (a->d[0] < b->d[0]))))));
}

bool u124_leq(u124_t *a, u124_t *b)
{   return a->d[3] < b->d[3] ||
           (a->d[3] == b->d[3] &&
            (a->d[2] < b->d[2] ||
             (a->d[2] == b->d[2] &&
              (a->d[1] < b->d[1] ||
               (a->d[1] == b->d[1] &&
                (a->d[0] <= b->d[0]))))));
}

// "Negating" does it work modulo 2^124.

void u124_negate(u124_t *a, u124_t *b)
{   uint32_t c = -a->d[0];
    b->d[0] = c & 0x7fffffff;
    c = ~a->d[1] + (c>>31);
    b->d[1] = c & 0x7fffffff;
    c = ~a->d[2] + (c>>31);
    b->d[2] = c & 0x7fffffff;
    c = ~a->d[3] + (c>>31);
    b->d[3] = c & 0x7fffffff;
}

// Addition and subtraction.

void u124_add(u124_t *a, u124_t *b, u124_t *c)
{   uint32_t w = a->d[0] + b->d[0];
    c->d[0] = w & 0x7fffffff;
    w = (w >> 31) + a->d[1] + b->d[1];
    c->d[1] = w & 0x7fffffff;
    w = (w >> 31) + a->d[2] + b->d[2];
    c->d[2] = w & 0x7fffffff;
    w = (w >> 31) + a->d[3] + b->d[3];
    c->d[3] = w & 0x7fffffff;
}

void u124_sub(u124_t *a, u124_t *b, u124_t *c)
{   uint32_t w = a->d[0] - b->d[0];
    c->d[0] = w & 0x7fffffff;
    w = (w >> 31) + a->d[1] - b->d[1];
    c->d[1] = w & 0x7fffffff;
    w = (w >> 31) + a->d[2] - b->d[2];
    c->d[2] = w & 0x7fffffff;
    w = (w >> 31) + a->d[3] - b->d[3];
    c->d[3] = w & 0x7fffffff;
}

// Multiplication only keep the low 124 bits of the product.

void u124_mul(u124_t *a, u124_t *b, u124_t *c)
{   for (int i=0; i<4; i++) c->d[i] = 0;
    for (int i=0; i<4; i++)
    {   int k;
        for (int j=0; (k=i+j)<4; j++)
        {   uint64_t w = a->d[i]*b->d[j];
            while (k < 4)
            {   w = w + c->d[k];
                c->d[k] = w & 0x7fffffff;
                w = w >> 31;
                k++;
            }
        }
    }
}

void u124_leftshift(u124_t *a)
{   a->d[3] = (a->d[3]<<1) | (a->d[2]>>30);
    a->d[2] = ((a->d[2]<<1) & 0x7fffffff) | (a->d[1]>>30);
    a->d[1] = ((a->d[1]<<1) & 0x7fffffff) | (a->d[0]>>30);
    a->d[0] = (a->d[0]<<1) & 0x7fffffff;
}

void u124_rightshift(u124_t *a)
{   a->d[0] = (a->d[0]>>1) | (((a->d[1]) & 1U) << 30);
    a->d[1] = (a->d[1]>>1) | (((a->d[2]) & 1U) << 30);
    a->d[2] = (a->d[2]>>1) | (((a->d[3]) & 1U) << 30);
    a->d[3] = (a->d[3]>>1);
}

// To perform variable shifts I take a path that was quickest and easiest
// for me to code. I shift successivly in units of 31, 6 and 1. With more
// care I could do everythin in close to a single sequence of (variable)
// shifts. but I do not view this as liable to be worth the coding effort,
// even though that would not be vary great..

void u124_leftshiftn(u124_t *a, int n)
{   while (n >= 31)
    {   a->d[3] = a->d[2];
        a->d[3] = a->d[1];
        a->d[1] = a->d[0];
        a->d[0] = 0;
        n = n - 31;
    }
    while (n >= 6)
    {   a->d[3] = (a->d[3]<<6) | ((a->d[2]>>25) & 0x3f);
        a->d[2] = (a->d[2]<<6) | ((a->d[1]>>25) & 0x3f);
        a->d[1] = (a->d[1]<<6) | ((a->d[0]>>25) & 0x3f);
        a->d[0] = (a->d[0]<<6);
        n = n - 6;
    }
    for (int i=0; i<n; i++)
        u124_leftshift(a);
}

void u124_rightshiftn(u124_t *a, int n)
{   while (n >= 31)
    {   a->d[0] = a->d[1];
        a->d[1] = a->d[2];
        a->d[2] = a->d[3];
        a->d[3] = 0;
        n = n - 31;
    }
    while (n >= 6)
    {   a->d[0] = (a->d[0]>>6) | ((a->d[1]<<25) & 0x7fffffff);
        a->d[1] = (a->d[1]>>6) | ((a->d[2]<<25) & 0x7fffffff);
        a->d[2] = (a->d[2]>>6) | ((a->d[3]<<25) & 0x7fffffff);
        a->d[3] = (a->d[3]>>6);
        n = n - 6;
    }
    for (int i=0; i<n; i++)
        u124_rightshift(a);
}

// Division (and remainder) are done bit by bit, which is seriously
// inefficient but is straightforward to code. If I needed more speed I
// could follow the treaditional long division route and after a bit
// of normalization ger 31 bits at a time not 1. Or in the case that
// the platform supported a 128-bit integer type I could use that and
// so this directly!

void u124_divrem(u124_t *a, u124_t *b, u124_t *q, u124_t *r)
{   u124_t ww = *b;
    int n = 0;
    while (u124_leq(&ww, a))
    {   u124_leftshift(&ww);
        n++;
    }
    q->d[0] = q->d[1] = q->d[2] = q->d[3] = 0;
    *r = *a;
    while (n > 0)
    {   u124_rightshift(&ww);
        n--;
        u124_leftshift(q);
        if (u124_leq(&ww, r))
        {   u124_sub(r, &ww, r);
            q->d[0] |= 1;
        }
    }
}

// Now I need to be able to convert between float128_t and u124_t with
// "fix" and "float" operations. I will only concern myself with positive
// numbers, and my expected use will be that I only attempt to fix
// values that will fit within 113 bits (ie well within 124), and
// I will only float values that are in around the same range.

void u124_fix(float128_t *a, u124_t *b)
{   if (f128M_eq(a, &f128_0))
    {   b->d[0] = b->d[1] = b->d[2] = b->d[3] = 0;
        return;
    }
// I am not going to do anything clever with NaN or infinity here - they
// are just not permitted and would lead to chaos.
    float128_t aa;
    int x;
    f128M_frexp(a, &aa, &x);
// Now I take the 113 bits of mantissa (including an implicit bit) and
// shuffle to be in the form of the u124_t multiple precision integer.
    b->d[0] = aa.v[LOPART] & 0x7fffffff;
    b->d[1] = (aa.v[LOPART] >> 31) & 0x7fffffff;
    b->d[2] = ((aa.v[LOPART] >> 62) & 0x3) |
              ((aa.v[HIPART] << 2) & 0x7ffffffc);
// Remember to OR in the hidden bit on the next line.
    b->d[3] = ((aa.v[HIPART] >> 29) & 0x0007ffff) | 0x00080000;
// Now I may need to shift b by an amount determined by x.
    x = x - 113;
    if (x > 0) u124_leftshiftn(b, x);
    else if (x < 0) u124_rightshiftn(b, -x); 
}

void u124_float(u124_t *a, float128_t *b)
{   if (u124_zerop(a))
    {   *b = f128_0;
        return;
    }
// Turn the u124_t object into a pair of 64-bit integers, which will make
// packing to look like a float easier.
    uint64_t alo = (uint64_t)a->d[0] |
                   ((uint64_t)a->d[1]<<31) |
                   ((uint64_t)a->d[2]<<62),
             ahi = ((uint64_t)a->d[2]>>2) |
                   ((uint64_t)a->d[3]<<29);
    int x = 113;
// Now I want to normalize the integer so that the bit at position
// 00010000:00000000:00000000:00000000 is set, ie the one that will be
// the "hidden bit". This could involve either shifting left or right, but
// I expect the right shift case to be uncommon so I will do it rather
// crudely.
    if ((ahi & UINT64_C(0xfffe000000000000)) != 0)
    {   while ((ahi & UINT64_C(0xfffe000000000000)) != 0)
        {   alo = (alo>>1) | (ahi<<63);
            ahi = ahi>>1;
            x++;
        }
    }
    else
    {   while ((ahi & UINT64_C(0xfffffffffe000000)) == 0)
        {   ahi = (ahi<<24) | (alo>>40);
            alo = alo<<24;
            x = x - 24;
        }
        while ((ahi & UINT64_C(0x0001000000000000)) == 0)
        {   ahi = (ahi<<1) | (alo>>63);
            alo = alo<<1;
            x--;
        }
    }
    ahi = ahi & UINT64_C(0x0000ffffffffffff);
    ahi = ahi | ((uint64_t)(x + 0x3ffe)<<48);
    b->v[HIPART] = ahi;
    b->v[LOPART] = alo;
}

// end of implementation of 124-bit integers using reasonably
// portable C++.
#endif // HAVE_UINT128_T

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
    u124_t p, q;
    u124_t a;
    u124_t u0, u1;
    u124_t v0, v1;
    if (f128M_le(&f128_1, &d))
    {   int x;
        float128_t d1;
        f128M_frexp(&d, &d1, &x);
        f128M_ldexp(&d1, 113);
        u124_fix(&d1, &p);
        u124_two_to_n(&q, 113-x);
        u124_divrem(&p, &q, &u1, &a);
        u124_two_to_n(&u0, 0);
        p = q;
        q = a;
        u124_zero(&v0);
        u124_two_to_n(&v1, 0);
    }
    else
    {   int x;
        float128_t d1, d2;
        f128M_frexp(&d, &d1, &x);
        f128M_ldexp(&d1, 113);
        u124_fix(&d1, &p);
        f128M_div(&f128_1, &d, &d2);
        u124_fix(&d2, &a);
        u124_t w1, w2;
        if (113-x < 128) u124_two_to_n(&w1, 113-x);
        else u124_zero(&w1);
        u124_mul(&a, &p, &w2);
        u124_sub(&w1, &w2, &q);
        while (u124_minusp(&q))
        {   u124_add(&q, &p, &q);
            u124_sub(&a, &u124_1, &a);
        }
        while (u124_leq(&p, &q))
        {   u124_sub(&q, &p, &q);
            u124_add(&a, &u124_1, &a);
        }
        u124_zero(&u0);
        u124_two_to_n(&u1, 0);
        u124_two_to_n(&v0, 0);
        v1 = a;
    }
    float128_t du1, dv1, q2;
    while (u124_float(&u1, &du1),
           u124_float(&v1, &dv1),
           f128M_div(&du1, &dv1, &q2),
           !f128M_eq(&d, &q2))
    {   u124_t a1, a2;
        if (u124_zerop(&q))
        {   printf("\n+++ Trouble in rationalizef128. q = 0\n");
            break;
        }
        u124_divrem(&p, &q, &a1, &a2);
        u124_t u2;
        u124_mul(&a1, &u1, &u2);
        u124_add(&u2, &u0, &u2);
        u124_t v2;
        u124_mul(&a1, &v1, &v2);
        u124_add(&v2, &v0, &v2);
        p = q;   q = a2;
        u0 = u1; u1 = u2;
        v0 = v1; v1 = v2;
    }
    if (f128M_negative(dd)) u124_negate(&u1, &u1);
    LispObject p1 = make_lisp_integer124(&u1);
    if (u124_onep(&v1)) return p1;
    push(p1);
    LispObject q1 = make_lisp_integer124(&v1);
    pop(p1);
    return make_ratio(p1, q1);
}


LispObject rational(LispObject a)
{   switch ((int)a & XTAG_BITS)
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
                    aerror1("bad arg for rational", a);
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            if (type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
                return rationalf128(long_float_addr(a));
            else return rationalf(float_of_number(a));
        default:
            aerror1("bad arg for rational", a);
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
                    aerror1("bad arg for rationalize", a);
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    return rationalizef(single_float_val(a), 24);
                case TYPE_DOUBLE_FLOAT:
                    return rationalizef(double_float_val(a), 53);
                case TYPE_LONG_FLOAT:
                    return rationalizef128(long_float_addr(a));
            }
        default:
            aerror1("bad arg for rationalize", a);
    }
}

//
// Arithmetic comparison: lessp
//

static bool lessp_i_i(LispObject a1, LispObject a2);
static bool lessp_i_b(LispObject a1, LispObject a2);
static bool lessp_i_r(LispObject a1, LispObject a2);
static bool lessp_i_c(LispObject a1, LispObject a2);
static bool lessp_i_s(LispObject a1, LispObject a2);
static bool lessp_i_f(LispObject a1, LispObject a2);
static bool lessp_i_d(LispObject a1, LispObject a2);
static bool lessp_i_l(LispObject a1, LispObject a2);

static bool lessp_b_i(LispObject a1, LispObject a2);
static bool lessp_b_b(LispObject a1, LispObject a2);
static bool lessp_b_r(LispObject a1, LispObject a2);
static bool lessp_b_c(LispObject a1, LispObject a2);
static bool lessp_b_s(LispObject a1, LispObject a2);
static bool lessp_b_f(LispObject a1, LispObject a2);
static bool lessp_b_d(LispObject a1, LispObject a2);
static bool lessp_b_l(LispObject a1, LispObject a2);

static bool lessp_r_i(LispObject a1, LispObject a2);
static bool lessp_r_b(LispObject a1, LispObject a2);
static bool lessp_r_r(LispObject a1, LispObject a2);
static bool lessp_r_c(LispObject a1, LispObject a2);
static bool lessp_r_s(LispObject a1, LispObject a2);
static bool lessp_r_f(LispObject a1, LispObject a2);
static bool lessp_r_d(LispObject a1, LispObject a2);
static bool lessp_r_l(LispObject a1, LispObject a2);

static bool lessp_c_i(LispObject a1, LispObject a2);
static bool lessp_c_b(LispObject a1, LispObject a2);
static bool lessp_c_r(LispObject a1, LispObject a2);
static bool lessp_c_c(LispObject a1, LispObject a2);
static bool lessp_c_s(LispObject a1, LispObject a2);
static bool lessp_c_f(LispObject a1, LispObject a2);
static bool lessp_c_d(LispObject a1, LispObject a2);
static bool lessp_c_l(LispObject a1, LispObject a2);

static bool lessp_s_i(LispObject a1, LispObject a2);
static bool lessp_s_b(LispObject a1, LispObject a2);
static bool lessp_s_r(LispObject a1, LispObject a2);
static bool lessp_s_c(LispObject a1, LispObject a2);
static bool lessp_s_s(LispObject a1, LispObject a2);
static bool lessp_s_f(LispObject a1, LispObject a2);
static bool lessp_s_d(LispObject a1, LispObject a2);
static bool lessp_s_l(LispObject a1, LispObject a2);

static bool lessp_f_i(LispObject a1, LispObject a2);
static bool lessp_f_b(LispObject a1, LispObject a2);
static bool lessp_f_r(LispObject a1, LispObject a2);
static bool lessp_f_c(LispObject a1, LispObject a2);
static bool lessp_f_s(LispObject a1, LispObject a2);
static bool lessp_f_f(LispObject a1, LispObject a2);
static bool lessp_f_d(LispObject a1, LispObject a2);
static bool lessp_f_l(LispObject a1, LispObject a2);

static bool lessp_d_i(LispObject a1, LispObject a2);
static bool lessp_d_b(LispObject a1, LispObject a2);
static bool lessp_d_r(LispObject a1, LispObject a2);
static bool lessp_d_c(LispObject a1, LispObject a2);
static bool lessp_d_s(LispObject a1, LispObject a2);
static bool lessp_d_f(LispObject a1, LispObject a2);
static bool lessp_d_d(LispObject a1, LispObject a2);
static bool lessp_d_l(LispObject a1, LispObject a2);

static bool lessp_l_i(LispObject a1, LispObject a2);
static bool lessp_l_b(LispObject a1, LispObject a2);
static bool lessp_l_r(LispObject a1, LispObject a2);
static bool lessp_l_c(LispObject a1, LispObject a2);
static bool lessp_l_s(LispObject a1, LispObject a2);
static bool lessp_l_f(LispObject a1, LispObject a2);
static bool lessp_l_d(LispObject a1, LispObject a2);
static bool lessp_l_l(LispObject a1, LispObject a2);

static inline bool lessp_i_i(LispObject a, LispObject b)
{   return (intptr_t)a < (intptr_t)b;
}

static inline bool lessp_i_s(LispObject a, LispObject b)
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
        return (double)int_of_fixnum(a) < value_of_immediate_float(b);
    return lessp_i64d(int_of_fixnum(a), value_of_immediate_float(b));
}

static inline bool lessp_i_b(LispObject, LispObject b)
//
// a fixnum and a bignum can never be equal, and the magnitude of
// the bignum must be at least as great as that of the fixnum, hence
// to do a comparison I just need to look at sign of the bignum.
//
{   size_t len = bignum_length(b);
    int32_t msd = bignum_digits(b)[(len-CELL-4)/4];
    return (msd >= 0);
}

static inline bool lessp_i_r(LispObject a, LispObject b)
{   push(numerator(b));  // compute a < p/q  as a*q < p
    a = times2(a, denominator(b));
    pop(b);
    return lessp2(a, b);  // lessp2 is NOT an inline function!
}

static inline bool lessp_i_f(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return (double)int_of_fixnum(a) < single_float_val(b);
    return lessp_i64d(int_of_fixnum(a), single_float_val(b));
}

static inline bool lessp_i_d(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return (double)int_of_fixnum(a) < double_float_val(b);
    return lessp_i64d(int_of_fixnum(a), double_float_val(b));
}

static inline bool lessp_i_l(LispObject a, LispObject b)
{   float128_t aa;
    i64_to_f128M((int64_t)int_of_fixnum(a), &aa);
    return f128M_lt(&aa, long_float_addr(b));
}

static inline bool lessp_f_i(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return single_float_val(a) < (double)int_of_fixnum(b);
    return lessp_di64(single_float_val(a), int_of_fixnum(b));
}

static inline bool lessp_d_i(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return double_float_val(a) < (double)int_of_fixnum(b);
    return lessp_di64(double_float_val(a), int_of_fixnum(b));
}

static inline bool lessp_l_i(LispObject a, LispObject b)
{   float128_t bb;
    i64_to_f128M((int64_t)int_of_fixnum(b), &bb);
    return f128M_lt(long_float_addr(a), &bb);
}

static inline bool lessp_rawd_b(double a, LispObject b)
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
    if ((double)MOST_NEGATIVE_FIXVAL <= a &&
        a < -(double)MOST_NEGATIVE_FIXVAL) return (bn >= 0);
//
// If b is a one-word bignum I can convert it to floating point
// with no loss of accuracy at all.
//
    if (n == 0) return a < (double)bn;
//
// For two-digit bignums I first check if the float is so big that I can
// tell that it dominates the bignum, and if not I subtract the top digit
// of the bignum from both sides... in the critical case where the two
// values are almost the same that subtraction will not lead to loss of
// accuracy (at least provided that my floating point was implemented
// with a guard bit..)
//
    if (n == 1)
    {   if (a >= (double)INT64_C(0x4000000000000000)) return false;
        else if (a < -(double)INT64_C(0x4000000000000000)) return true;
        a -= TWO_31*(int32_t)bn;
        return a < (double)bignum_digits(b)[0];
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

static inline bool greaterp_rawd_b(double a, LispObject b)
// logic here is much as for the lessp test. By leavinbg the commentary
// out of this version you can get a clearer idea of how much code is
// involved.
{   size_t n = (bignum_length(b)-CELL-4)/4;
    int32_t bn = (int32_t)bignum_digits(b)[n];
    if ((double)MOST_NEGATIVE_FIXVAL <= a &&
        a < -(double)MOST_NEGATIVE_FIXVAL) return (bn < 0);
    if (n == 0) return a > (double)bn;
    if (n == 1)
    {   if (a >= (double)INT64_C(0x4000000000000000)) return true;
        else if (a < -(double)INT64_C(0x4000000000000000)) return false;
        a -= TWO_31*(int32_t)bn;
        return a > (double)bignum_digits(b)[0];
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

static inline bool lessp_b_rawd(LispObject a, double b)
{   return greaterp_rawd_b(b, a);
}

static inline bool lessp_rawl_b(float128_t *a, LispObject b)
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
    {
    case 1: // Only happens on 32-bit systems
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
    aerror("comparison between log float and large bignum - not implemented yet");
}


static inline bool lessp_b_rawl(LispObject a, float128_t *b)
{
    size_t n = (length_of_header(numhdr(a))-CELL)/4;
    float128_t aa, w0, w1;
    int32_t k;
    switch (n)
    {
    case 1: // Only happens on 32-bit systems
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
    aerror("comparison between log float and large bignum - not implemented yet");
}

static inline bool lessp_rawl_r(float128_t *a, LispObject b)
{   aerror("comparison between long float and raion not coded yet");
}

static inline bool lessp_r_rawl(LispObject a, float128_t *b)
{   aerror("comparison between long float and raion not coded yet");
}

static inline bool lessp_s_s(LispObject a, LispObject b)
{   return value_of_immediate_float(a) < value_of_immediate_float(b);
}

static inline bool lessp_s_f(LispObject a, LispObject b)
{   return value_of_immediate_float(a) < single_float_val(b);
}

static inline bool lessp_s_d(LispObject a, LispObject b)
{   return value_of_immediate_float(a) < double_float_val(b);
}

static inline bool lessp_f_f(LispObject a, LispObject b)
{   return single_float_val(a) < single_float_val(b);
}

static inline bool lessp_f_d(LispObject a, LispObject b)
{   return single_float_val(a) < double_float_val(b);
}

static inline bool lessp_d_d(LispObject a, LispObject b)
{   return double_float_val(a) < double_float_val(b);
}

static inline bool lessp_f_s(LispObject a, LispObject b)
{   return single_float_val(a) < value_of_immediate_float(b);
}

static inline bool lessp_d_s(LispObject a, LispObject b)
{   return double_float_val(a) < value_of_immediate_float(b);
}

static inline bool lessp_d_f(LispObject a, LispObject b)
{   return double_float_val(a) < single_float_val(b);
}

static inline bool lessp_b_f(LispObject a, LispObject b)
{   return lessp_b_rawd(a, single_float_val(b));
}

static inline bool lessp_b_d(LispObject a, LispObject b)
{   return lessp_b_rawd(a, double_float_val(b));
}

static inline bool lessp_d_b(LispObject a, LispObject b)
{   return lessp_rawd_b(double_float_val(a), b);
}

static inline bool lessp_b_l(LispObject a, LispObject b)
{   return lessp_b_rawl(a, long_float_addr(b));
}

static inline bool lessp_r_r(LispObject a, LispObject b)
{   LispObject c;
    push2(a, b);
    c = times2(numerator(a), denominator(b));
    pop2(b, a);
    push(c);
    b = times2(numerator(b), denominator(a));
    pop(c);
    return lessp2(c, b);
}

static inline bool lessp_rawd_r(double a, LispObject b)
// Compare float with ratio... painfully expensive.
{   LispObject a1 = rationalf(a);
    return lessp2(a1, b);
}

static inline bool lessp_r_rawd(LispObject a, double b)
{   LispObject b1 = rationalf(b);
    return lessp2(a, b1);
}

static inline bool lessp_d_r(LispObject a, LispObject b)
{   return lessp_rawd_r(double_float_val(a), b);
}

static inline bool lessp_r_d(LispObject a, LispObject b)
{   return lessp_r_rawd(a, double_float_val(b));
}

static inline bool lessp_s_i(LispObject a, LispObject b)
{   if (!SIXTY_FOUR_BIT)
        return value_of_immediate_float(a) < (double)int_of_fixnum(b);
// Again beware fixnums that are over 2^53 and can not be converted to a
// double precision float losslessly.
    return lessp_di64(value_of_immediate_float(a), int_of_fixnum(b));
}

static inline bool lessp_s_b(LispObject a, LispObject b)
{   return lessp_rawd_b(value_of_immediate_float(a), b);
}

static inline bool lessp_s_r(LispObject a, LispObject b)
{   return lessp_rawd_r(value_of_immediate_float(a), b);
}

static inline bool lessp_b_i(LispObject a, LispObject)
{   size_t len = bignum_length(a);
    int32_t msd = bignum_digits(a)[(len-CELL-4)/4];
    return (msd < 0);
}

static inline bool lessp_b_s(LispObject a, LispObject b)
{   return lessp_b_rawd(a, value_of_immediate_float(b));
}

static inline bool lessp_b_b(LispObject a, LispObject b)
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

static inline bool lessp_b_r(LispObject a, LispObject b)
{   return lessp_i_r(a, b);
}

static inline bool lessp_r_i(LispObject a, LispObject b)
{   push(numerator(a));
    b = times2(b, denominator(a));
    pop(a);
    return lessp2(a, b);
}

static inline bool lessp_r_s(LispObject a, LispObject b)
{   return lessp_r_rawd(a, value_of_immediate_float(b));
}

static inline bool lessp_r_b(LispObject a, LispObject b)
{   return lessp_r_i(a, b);
}


static inline bool lessp_r_f(LispObject a, LispObject b)
{   return lessp_r_rawd(a, single_float_val(b));
}

static inline bool lessp_f_b(LispObject a, LispObject b)
{   return lessp_rawd_b(single_float_val(a), b);
}

static inline bool lessp_f_r(LispObject a, LispObject b)
{   return lessp_rawd_r(single_float_val(a), b);
}

static inline bool lessp_c_i(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_c_b(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_c_r(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_c_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_c_s(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_c_f(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_c_d(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_c_l(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_i_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_b_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_r_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_s_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_f_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_d_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_l_c(LispObject a, LispObject b)
{   aerror2("ordered comparison on complex values", a, b);
}

static inline bool lessp_l_b(LispObject a, LispObject b)
{   return lessp_rawl_b(long_float_addr(a), b);
}

static inline bool lessp_l_r(LispObject a, LispObject b)
{   return lessp_rawl_r(long_float_addr(a), b);
}

static inline bool lessp_l_s(LispObject a, LispObject b)
{   Double_union d;
    d.f = value_of_immediate_float(b);
    float128_t bb;
    f64_to_f128M(d.f64, &bb);
    return f128M_lt(long_float_addr(a), &bb);
}

static inline bool lessp_l_f(LispObject a, LispObject b)
{   Double_union d;
    d.f = single_float_val(b);
    float128_t bb;
    f64_to_f128M(d.f64, &bb);
    return f128M_lt(long_float_addr(a), &bb);
}

static inline bool lessp_l_d(LispObject a, LispObject b)
{   Double_union d;
    d.f = double_float_val(b);
    float128_t bb;
    f64_to_f128M(d.f64, &bb);
    return f128M_lt(long_float_addr(a), &bb);
}

static inline bool lessp_l_l(LispObject a, LispObject b)
{   return f128M_lt(long_float_addr(a), long_float_addr(b));
}

static inline bool lessp_r_l(LispObject a, LispObject b)
{   return lessp_r_rawl(a, long_float_addr(b));
}

static inline bool lessp_s_l(LispObject a, LispObject b)
{   Double_union d;
    d.f = value_of_immediate_float(a);
    float128_t aa;
    f64_to_f128M(d.f64, &aa);
    return f128M_lt(&aa, long_float_addr(b));
}

static inline bool lessp_f_l(LispObject a, LispObject b)
{   Double_union d;
    d.f = single_float_val(a);
    float128_t aa;
    f64_to_f128M(d.f64, &aa);
    return f128M_lt(&aa, long_float_addr(b));
}

static inline bool lessp_d_l(LispObject a, LispObject b)
{   Double_union d;
    d.f = double_float_val(a);
    float128_t aa;
    f64_to_f128M(d.f64, &aa);
    return f128M_lt(&aa, long_float_addr(b));
}

// Now I have given all the helper type-specific rules - do the
// big dispatch.

arith_dispatch_2(static inline, bool, lessp)

bool greaterp2(LispObject a, LispObject b)
{   return lessp(b, a);
}

bool lessp2(LispObject a, LispObject b)
{   return lessp(a, b);
}

static inline bool geq_i_i(LispObject a1, LispObject a2)
{   return (intptr_t)a1 >= (intptr_t)a2;
}

// A bignum can not be equal to a fixnum, so I>=B is the same as B<I
static inline bool geq_i_b(LispObject a1, LispObject a2)
{   return lessp_b_i(a2, a1);
}

static inline bool geq_i_r(LispObject a1, LispObject a2)
{   return !lessp_i_r(a1, a2);
}

static inline bool geq_i_c(LispObject a1, LispObject a2)
{   return !lessp_i_c(a1, a2);
}

static inline bool geq_i_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_i_s(a1, a2);
}

static inline bool geq_i_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_i_f(a1, a2);
}

static inline bool geq_i_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_i_d(a1, a2);
}

static inline bool geq_i_l(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_i_l(a1, a2);
}

static inline bool geq_b_i(LispObject a1, LispObject a2)
{   return lessp_i_b(a2, a1);
}

static inline bool geq_b_b(LispObject a1, LispObject a2)
{   return !lessp_b_b(a1, a2);
}

static inline bool geq_b_r(LispObject a1, LispObject a2)
{   return !lessp_b_r(a1, a2);
}

static inline bool geq_b_c(LispObject a1, LispObject a2)
{   return !lessp_b_c(a1, a2);
}

static inline bool geq_b_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_b_s(a1, a2);
}

static inline bool geq_b_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_b_f(a1, a2);
}

static inline bool geq_b_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_b_d(a1, a2);
}

static inline bool geq_b_l(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_b_l(a1, a2);
}

static inline bool geq_r_i(LispObject a1, LispObject a2)
{   return !lessp_r_i(a1, a2);
}

static inline bool geq_r_b(LispObject a1, LispObject a2)
{   return !lessp_r_b(a1, a2);
}

static inline bool geq_r_r(LispObject a1, LispObject a2)
{   return !lessp_r_r(a1, a2);
}

static inline bool geq_r_c(LispObject a1, LispObject a2)
{   return !lessp_r_c(a1, a2);
}

static inline bool geq_r_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_r_s(a1, a2);
}

static inline bool geq_r_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_r_f(a1, a2);
}

static inline bool geq_r_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_r_d(a1, a2);
}

static inline bool geq_r_l(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_r_l(a1, a2);
}

static inline bool geq_c_i(LispObject a1, LispObject a2)
{   return !lessp_c_i(a1, a2);
}

static inline bool geq_c_b(LispObject a1, LispObject a2)
{   return !lessp_c_b(a1, a2);
}

static inline bool geq_c_r(LispObject a1, LispObject a2)
{   return !lessp_c_r(a1, a2);
}

static inline bool geq_c_c(LispObject a1, LispObject a2)
{   return !lessp_c_c(a1, a2);
}

static inline bool geq_c_s(LispObject a1, LispObject a2)
{   double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_c_s(a1, a2);
}

static inline bool geq_c_f(LispObject a1, LispObject a2)
{   double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_c_f(a1, a2);
}

static inline bool geq_c_d(LispObject a1, LispObject a2)
{   double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_c_d(a1, a2);
}

static inline bool geq_c_l(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_c_l(a1, a2);
}

static inline bool geq_s_i(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_i(a1, a2);
}

static inline bool geq_s_b(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_b(a1, a2);
}

static inline bool geq_s_r(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_r(a1, a2);
}

static inline bool geq_s_c(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    return !lessp_s_c(a1, a2);
}

static inline bool geq_s_s(LispObject a1, LispObject a2)
{   return value_of_immediate_float(a1) >= value_of_immediate_float(a2);
}

static inline bool geq_s_f(LispObject a1, LispObject a2)
{   return value_of_immediate_float(a1) >= single_float_val(a2);
}

static inline bool geq_s_d(LispObject a1, LispObject a2)
{   return value_of_immediate_float(a1) >= double_float_val(a2);
}

static inline bool geq_s_l(LispObject a1, LispObject a2)
{   double a1d = value_of_immediate_float(a1);
    if (a1d != a1d) return false;
    if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_s_l(a1, a2);
}

static inline bool geq_f_i(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_i(a1, a2);
}

static inline bool geq_f_b(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_b(a1, a2);
}

static inline bool geq_f_r(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_r(a1, a2);
}

static inline bool geq_f_c(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_f_c(a1, a2);
}

static inline bool geq_f_s(LispObject a1, LispObject a2)
{   return single_float_val(a1) >= value_of_immediate_float(a2);
}

static inline bool geq_f_f(LispObject a1, LispObject a2)
{   return single_float_val(a1) >= single_float_val(a2);
}

static inline bool geq_f_d(LispObject a1, LispObject a2)
{   return single_float_val(a1) >= double_float_val(a2);
}

static inline bool geq_f_l(LispObject a1, LispObject a2)
{   double a1d = single_float_val(a1);
    if (a1d != a1d) return false;
    if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_f_l(a1, a2);
}

static inline bool geq_d_i(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_i(a1, a2);
}

static inline bool geq_d_b(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_b(a1, a2);
}

static inline bool geq_d_r(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_r(a1, a2);
}

static inline bool geq_d_c(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    return !lessp_d_c(a1, a2);
}

static inline bool geq_d_s(LispObject a1, LispObject a2)
{   return double_float_val(a1) >= value_of_immediate_float(a2);
}

static inline bool geq_d_f(LispObject a1, LispObject a2)
{   return double_float_val(a1) >= single_float_val(a2);
}

static inline bool geq_d_d(LispObject a1, LispObject a2)
{   return double_float_val(a1) >= double_float_val(a2);
}

static inline bool geq_d_l(LispObject a1, LispObject a2)
{   double a1d = double_float_val(a1);
    if (a1d != a1d) return false;
    if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_d_l(a1, a2);
}

static inline bool geq_l_i(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    return !lessp_l_i(a1, a2);
}

static inline bool geq_l_b(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    return !lessp_l_b(a1, a2);
}

static inline bool geq_l_r(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    return !lessp_l_r(a1, a2);
}

static inline bool geq_l_c(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    return !lessp_l_c(a1, a2);
}

static inline bool geq_l_s(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    double a2d = value_of_immediate_float(a2);
    if (a2d != a2d) return false;
    return !lessp_l_s(a1, a2);
}

static inline bool geq_l_f(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    double a2d = single_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_l_f(a1, a2);
}

static inline bool geq_l_d(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    double a2d = double_float_val(a2);
    if (a2d != a2d) return false;
    return !lessp_l_d(a1, a2);
}

static inline bool geq_l_l(LispObject a1, LispObject a2)
{   if (f128M_nan(long_float_addr(a1))) return false;
    if (f128M_nan(long_float_addr(a2))) return false;
    return !lessp_l_l(a1, a2);
}

arith_dispatch_2(static inline, bool, geq)

bool lesseq2(LispObject a, LispObject b)
{   return geq(b, a);
}

bool geq2(LispObject a, LispObject b)
{   return geq(a, b);
}

// end of arith04.cpp
