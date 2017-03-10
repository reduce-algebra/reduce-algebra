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

static LispObject make_power_of_two(size_t n)
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

LispObject make_approx_ratio(LispObject p, LispObject q, int bits)
{
// Adjust p and q so that the length (in bits) of p + the length of q is
// just bigger than bits. Use a conversion to a continued fraction to
// achieve this. Bits will be 20, 24, 62 or 112.
// @@ Does not do anything yet @@
    return make_ratio(p, q);
}

static LispObject rationalizef(double d, int bits)
//
// This is expected to give a 'nice' rational approximation to the
// floating point value d, specifically one where the size of the
// numerator and denominator are only just sufficient to capture the
// precision that the floating point representation provides.
//
{   double dd;
    LispObject p, q;
    if (d == 0.0) return fixnum_of_int(0);
    else if (d < 0.0) dd = -d; else dd = d;
    p = rationalf(dd);
    q = denominator(p);
    p = numerator(p);
// /* No cleaning up done, yet. Need to start to produce continued
// fraction for p/q and truncate it at some suitable point to get
// a sensible approximation.  Since this is only needed in Common Lisp
// mode, and seems a bit specialist even then I am not going to rush into
// cobbling up the code (which I have done before and is basically OK,
// save that the stopping criteria are pretty delicate).
//
    if (d < 0.0) p = negate(p);
    return make_approx_ratio(p, q, bits);
}

// The following constants ars 2^112 and -2^112
static float128_t FP128_INT_LIMIT =
{
#ifdef LITTLEENDIAN
    {0, INT64_C(0x406f0000)}
#else
    {INT64_C(0x406f0000) , 0}
#endif
};
static float128_t FP128_MINUS_INT_LIMIT =
{
#ifdef LITTLEENDIAN
    {0, INT64_C(0xC06f0000)}
#else
    {INT64_C(0xC06f0000) , 0}
#endif
};

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

// This is expected to adjust the ration returned to support 112 bits
// of precision.

static LispObject rationalizef128(float128_t *d)
{   float128_t dd;
    LispObject p, q;
    if (f128M_zero(d)) return fixnum_of_int(0);
    dd = *d;
    if (f128M_negative(d)) f128M_negate(&dd);
    p = rationalf128(&dd);
    q = denominator(p);
    p = numerator(p);
    if (f128M_negative(d)) p = negate(p);
    return make_approx_ratio(p, q, 112);
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
                    return rationalizef(value_of_immediate_float(a), 24);
                case TYPE_DOUBLE_FLOAT:
                    return rationalizef(value_of_immediate_float(a), 52);
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

