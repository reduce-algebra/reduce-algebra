// arith01.cpp                             Copyright (C) 1990-2021 Codemist

//
// Arithmetic functions.
//        Addition of generic numbers
//        and in particular a lot of bignum support.
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

//
// The following verifies that a number is properly formatted - a
// fixnum if small enough or a decently normalised bignum.  For use when
// there is suspicion of a bug wrt such matters. Call is
//   validate_number("msg", numberToCheck, nX, nY)
// where nX and nY are values shown in any diagnostic.
//

// If I make validate-number stop absolutely that can be useful if I am
// running under a debugger, because I can put a break-point on Lstop
// and there I when I run normally I know I do not run on beyond trouble.
// But if I let it exit reporting an error I may get a Lisp-level backtrace...
// and that too can be helpful. So while I decide and to make temporary
// changes easier I will parameterize the code...

// #define VALIDATE_STOPS 1

LispObject validate_number(const char *s, LispObject a,
                           LispObject b, LispObject c)
{   int32_t la, msd, nsd;
// The only two bad things that I can think of are (a) for a number that
// should be a fixnum to be stored as a bignum and (b) for a bignum
// to have leading zero digits when it ought not to. So unless the
// argument here looks like a bignum there is nothing much to do.
    if (!is_numbers(a) || !is_bignum(a)) return a;
    la = (length_of_header(numhdr(a))-CELL-4)/4;
    if (la < 0)
    {   trace_printf("%s: number with no digits (%.16" PRIx16 ")\n",
                     s, (uint64_t)numhdr(a));
        prin_to_trace(b), trace_printf("\n");
        prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
        return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        return aerror1("validate-number", a);
#endif
    }
    if (la == 0)
    {   if (SIXTY_FOUR_BIT)
        {   trace_printf("One word bignum invalid on 64-bit platform\n");
            prin_to_trace(a), trace_printf("\n");
            prin_to_trace(b), trace_printf("\n");
            prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
            return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
            return aerror1("validate-number", a);
#endif
        }
        else
        {   msd = bignum_digits(a)[0];
            if (valid_as_fixnum(msd))
            {   trace_printf("%s: %.8x should be fixnum\n", s, msd);
                prin_to_trace(b), trace_printf("\n");
                prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
                return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
                return aerror1("validate-number", a);
#endif
            }
            if (signed_overflow(msd))
            {   trace_printf("%s: %.8x should be two-word\n", s, msd);
                prin_to_trace(b), trace_printf("\n");
                prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
                return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
                return aerror1("validate-number", a);
#endif
            }
            return a;
        }
    }
    if (SIXTY_FOUR_BIT && la == 1)
    {   int64_t v = ASL(bignum_digits64(a, 1), 31) | bignum_digits(a)[0];
        if (valid_as_fixnum(v))
        {   trace_printf("%s: %#" PRIx64 " should be fixnum\n", s, v);
            prin_to_trace(b), trace_printf("\n");
            prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
            return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
            return aerror1("validate-number", a);
#endif
        }
    }
    msd = bignum_digits(a)[la];
    if (signed_overflow(msd))
    {   trace_printf("%s: %.8x should be longer\n", s, msd);
        prin_to_trace(b), trace_printf("\n");
        prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
        return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        return aerror1("validate-number", a);
#endif
    }
    if (msd == 0 && ((nsd = bignum_digits(a)[la-1]) & 0x40000000) == 0)
    {   trace_printf("%s: 0: %.8x should be shorter\n", s, nsd);
        prin_to_trace(b); trace_printf("\n");
        prin_to_trace(c); trace_printf("\n");
#ifdef VALIDATE_STOPS
        return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        return aerror1("validate-number", a);
#endif
    }
    else if (msd == -1 &&
             ((nsd = bignum_digits(a)[la-1]) & 0x40000000) != 0)
    {   trace_printf("%s: -1: %.8x should be shorter\n", s, nsd);
        prin_to_trace(b); trace_printf("\n");
        prin_to_trace(c); trace_printf("\n");
#ifdef VALIDATE_STOPS
        return Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        return aerror1("validate-number", a);
#endif
    }
    return a; // OK
}



//
// I start off with a collection of utility functions that create
// Lisp structures to represent various sorts of numbers
// and which extract values from same.
// The typedefs that explain the layout of these structures are in "tags.h"
//

// The functions here are called via inline functions that are in arith.h and
// that check if all that is needed is fixnum_of_int, so here I know that
// I have to create a bignum.

LispObject make_lisp_integer32_fn(int32_t n)
{   if (!SIXTY_FOUR_BIT && (n < 0x40000000 && n >= -0x40000000))
        return make_one_word_bignum(n);
    return make_two_word_bignum((int32_t)ASR(n, 31),
                                (uint32_t)(n & 0x7fffffff));
}

LispObject make_lisp_integer64_fn(int64_t n)
{   if (!SIXTY_FOUR_BIT && (n < 0x40000000 && n >= -0x40000000))
        return make_one_word_bignum((int32_t)n);
// With a RECENT C++ compiler I would not need the INT64_C macro here,
// since the C++ standard would cause the large value to be treated as a
// wide integer automatically. However if I go back and use an old version
// of gcc this is required...
    if (n < INT64_C(0x2000000000000000) &&
        n >= -INT64_C(0x2000000000000000))
        return make_two_word_bignum((int32_t)ASR(n, 31),
                                    (uint32_t)(n & 0x7fffffff));
    return make_three_word_bignum(
               (int32_t)ASR(n, 62),
               (uint32_t)((n >> 31) & 0x7fffffff),
               (uint32_t)(n & 0x7fffffff));
}

LispObject make_lisp_unsigned64_fn(uint64_t n)
{   if (!SIXTY_FOUR_BIT && n < 0x40000000)
        return make_one_word_bignum((int32_t)n);
    if (n < UINT64_C(0x2000000000000000))
        return make_two_word_bignum((int32_t)(n >> 31),
                                    (uint32_t)(n & 0x7fffffff));
    return make_three_word_bignum(
               (int32_t)(n >> 62),
               (uint32_t)((n >> 31) & 0x7fffffff),
               (uint32_t)(n & 0x7fffffff));
}

LispObject make_lisp_integerptr_fn(intptr_t n)
{   if (!SIXTY_FOUR_BIT && (n < 0x40000000 && n >= -0x40000000))
        return make_one_word_bignum((int32_t)n);
    if (!SIXTY_FOUR_BIT ||
        (n < (intptr_t)INT64_C(0x2000000000000000) &&
         n >= -(intptr_t)INT64_C(0x2000000000000000)))
        return make_two_word_bignum((int32_t)ASR((int64_t)n, 31),
                                    (uint32_t)(n & 0x7fffffff));
// Noter that intptr_t may be a 32-bit type where trying to shift right be 62
// bits would be a mistake. So I cast to 64-bits to be safe.
    return make_three_word_bignum(
               (int32_t)ASR((int64_t)n, 62),
               (uint32_t)((n >> 31) & 0x7fffffff),
               (uint32_t)(n & 0x7fffffff));
}

LispObject make_lisp_unsignedptr_fn(uintptr_t n)
{   if (!SIXTY_FOUR_BIT && n < 0x40000000)
        return make_one_word_bignum((int32_t)n);
    if (!SIXTY_FOUR_BIT || n < (uintptr_t)UINT64_C(0x2000000000000000))
        return make_two_word_bignum((int32_t)(n >> 31),
                                    (uint32_t)(n & 0x7fffffff));
    return make_three_word_bignum(
               (int32_t)((uint64_t)n >> 62),
               (uint32_t)((n >> 31) & 0x7fffffff),
               (uint32_t)(n & 0x7fffffff));
}

LispObject make_lisp_integer128_fn(int128_t r)
{
// The result will be a bignum using 2, 3, 4 or 5 digits.
    if (r < int128_t(INT64_C(0x2000000000000000)) &&
        r >= -int128_t(INT64_C(0x2000000000000000)))
        return make_two_word_bignum((int32_t)ASR(static_cast<int64_t>(r), 31),
                                    (uint32_t)(r & 0x7fffffff));
// I will split off the high and low 62-bit chunks...
    uint64_t lo = (uint64_t)(r & UINT64_C(0x3fffffffffffffff));
    int64_t hi = static_cast<int64_t>(r >> 62);
    if (hi < INT64_C(0x40000000) &&
        hi >= -INT64_C(0x40000000))
        return make_three_word_bignum(
                   (int32_t)hi,
                   (uint32_t)((lo >> 31) & 0x7fffffff),
                   (uint32_t)(lo & 0x7fffffff));
    else if (hi < INT64_C(0x2000000000000000) &&
             hi >= -INT64_C(0x2000000000000000))
        return make_four_word_bignum(
                   (int32_t)ASR(hi, 31),
                   (uint32_t)(hi & 0x7fffffff),
                   (uint32_t)((lo >> 31) & 0x7fffffff),
                   (uint32_t)(lo & 0x7fffffff));
    else return make_five_word_bignum(
                        (int32_t)ASR(hi, 62),
                        (uint32_t)(ASR(hi, 31) & 0x7fffffff),
                        (uint32_t)(hi & 0x7fffffff),
                        (uint32_t)((lo >> 31) & 0x7fffffff),
                        (uint32_t)(lo & 0x7fffffff));
}

LispObject make_lisp_unsigned128_fn(uint128_t r)
{
// The result will be a bignum using 2, 3 or 4 digits.
    if (r < uint128_t(INT64_C(0x2000000000000000)))
        return make_two_word_bignum(
            (int32_t)ASR(static_cast<int64_t>(r), 31),
            (uint32_t)(static_cast<uint64_t>(r) & 0x7fffffff));
// I will split off the high and low 62-bit chunks...
    uint64_t lo = (uint64_t)(static_cast<uint64_t>(r) &
                             INT64_C(0x3fffffffffffffffU));
    int64_t hi = static_cast<uint64_t>(r >> 62); // Will be positive
    if (hi < INT64_C(0x40000000))
        return make_three_word_bignum(
                   (int32_t)hi,
                   (uint32_t)((lo >> 31) & 0x7fffffff),
                   (uint32_t)(lo & 0x7fffffff));
    else
        return make_four_word_bignum(
                   (int32_t)ASR(hi, 31),
                   (uint32_t)(hi & 0x7fffffff),
                   (uint32_t)((lo >> 31) & 0x7fffffff),
                   (uint32_t)(lo & 0x7fffffff));
}

// There are places within the arithmetic code where the simplest
// implementatiom for combining a bignum and a fixnum seemed to be to
// convert the fixnum into a bignum representation, even though that
// should never arise "in the wild". This function makes a 1 or 2 word
// bignum as necessary.

LispObject make_fake_bignum(intptr_t n)
{
// It could be made into a 1-word bignum if the value is up to 31-bits...
    if (!SIXTY_FOUR_BIT ||
        (-0x40000000 <= n &&
         n < 0x40000000))
    {   bignum_digits(big_fake1)[0] = n;
        if (SIXTY_FOUR_BIT) bignum_digits(big_fake1)[1] = 0;  // padding
        return big_fake1;
    }
// Otherwise it must be a 2-digit bignum. That could cope with 31+31=62 bit
// numbers and a fixnum can only be 60 bits, so I never need a 3-digit
// bignum.
    bignum_digits(big_fake2)[1] = (int32_t)ASR((int64_t)n, 31);
    bignum_digits(big_fake2)[0] = (uint32_t)(n & 0x7fffffff);
    if (!SIXTY_FOUR_BIT) bignum_digits(big_fake2)[2] = 0;     // padding
    return big_fake2;
}

LispObject make_one_word_bignum(int32_t n)
//
// n is an integer - create a bignum representation of it.  This is
// done when n is outside the range 0xf8000000 to 0x07ffffff, but
// inside the range 0xc0000000 to 0x3fffffff on a 32-bit machine. It
// should never be needed on a 64-bit system!
//
{   LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4);
    errexit();
    bignum_digits(w)[0] = n;
    return w;
}

LispObject make_two_word_bignum(int32_t a1, uint32_t a0)
//
// This make a 2-word bignum from the 2-word value (a1,a0), where it
// must have been arranged already that a1 and a0 are correctly
// normalized to put in the two words as indicated.
//
{   LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, CELL+8);
    errexit();
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    return w;
}

LispObject make_three_word_bignum(int32_t a2, uint32_t a1, uint32_t a0)
//
// This make a 3-word bignum from the 3-word value (a2,a1,a0), where it
// must have been arranged already that the values are correctly
// normalized.
//
{   LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, CELL+12);
    errexit();
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    bignum_digits(w)[2] = a2;
    return w;
}

LispObject make_four_word_bignum(int32_t a3, uint32_t a2,
                                 uint32_t a1, uint32_t a0)
//
// This make a 4-word bignum from the 4-word value (a3,a2,a1,a0), where it
// must have been arranged already that the values are correctly
// normalized.
//
{   LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, CELL+16);
    errexit();
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    bignum_digits(w)[2] = a2;
    bignum_digits(w)[3] = a3;
    return w;
}

LispObject make_five_word_bignum(int32_t a4, uint32_t a3, uint32_t a2,
                                 uint32_t a1, uint32_t a0)
//
// This make a 5-word bignum from the 5-word value (a4,a3,a2,a1,a0), where it
// must have been arranged already that the values are correctly
// normalized.
//
{   LispObject w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, CELL+20);
    errexit();
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    bignum_digits(w)[2] = a2;
    bignum_digits(w)[3] = a3;
    bignum_digits(w)[4] = a4;
    return w;
}

LispObject make_boxfloat(double a, int type)
// Make a boxed float (single, double according to the type specifier)
// if type==0 this makes a short float.
// 128-bit floats must be made using make_boxfloat128.
{   LispObject r;
    switch (type)
    {   case 0:
            return pack_short_float(a);
        case TYPE_SINGLE_FLOAT:
            return pack_single_float(a);
        default: // TYPE_DOUBLE_FLOAT I hope
            r = get_basic_vector(TAG_BOXFLOAT, TYPE_DOUBLE_FLOAT,
                                 SIZEOF_DOUBLE_FLOAT);
            errexit();
            if (!SIXTY_FOUR_BIT) double_float_pad(r) = 0;
            double_float_val(r) = a;
            if (trap_floating_overflow &&
                floating_edge_case(double_float_val(r)))
            {   floating_clear_flags();
                return aerror("exception with double float");
            }
            return r;
    }
}

#ifdef HAVE_SOFTFLOAT
LispObject make_boxfloat128(float128_t a)
{   LispObject r;
    r = get_basic_vector(TAG_BOXFLOAT, TYPE_LONG_FLOAT, SIZEOF_LONG_FLOAT);
    errexit();
    if (!SIXTY_FOUR_BIT) long_float_pad(r) = 0;
    long_float_val(r) = a;
    if (trap_floating_overflow &&
        floating_edge_case128(
            reinterpret_cast<float128_t *>(&long_float_val(r))))
        return aerror("exception with long float");
    return r;
}
#endif // HAVE_SOFTFLOAT

static double bignum_to_float(LispObject v, int32_t h, int *xp)
//
// Convert a Lisp bignum to get a floating point value.  This uses at most the
// top 3 digits of the bignum's representation since that is enough to achieve
// full double precision accuracy. Note that this is 3 words not 2 because
// the top word of the bignum might have only 1 bit in it, so the top 2 words
// of a bignum might only provide 1+31 bits of significance.
// This can not overflow, because it leaves an exponent-adjustment value
// in *xp. You need ldexp(r, *xp) afterwards, and THAT is where any overflow
// can arise.
//
// Well my remark about only needing to look at 3 words is wrong if I want
// a floating result that is always correctly rounded to even (as per IEEE).
// Suppose I had a floating point format with 12-bit (plus an implicit bit)
// mantissa, then consider an integer such as
//    0x122280000000x
//       ===
// where I have underlined the 12 bits that will appear explicitly in the
// floating point rendition. If x is zero then round-to-even will yield
// a floating point value [1]222, while if x is non-zero I will need to round
// up and deliver [1]223. There could be very very many zeros before the "x",
// bounded only by the limit on exponents.
{   int32_t n = (h-CELL-4)/4;  // Last index into the data
    int x = 31*static_cast<int>(n);
    int32_t msd = (int32_t)bignum_digits(v)[n];
// NB signed conversion on next line
    double r = static_cast<double>(msd);
// If I have a one-word bignum then there is no messing around needed and the
// number will be converted to floating point without any rounding.
    if (n != 0)
    {   if (n == 1)
        {   r = TWO_31*r + static_cast<double>(bignum_digits(v)[--n]);
// A two-word bignum may involve rounding, but each digit can be
// converted exactly and a correct result should emerge from the single
// addition that combines low and high parts.
            x -= 31;
        }
        else
        {   int32_t lo;
// Here I have a bignum with at least 3 digits. I will do different things
// based on whether there are less than or more then 16 bits in use in the
// most significant digit
            if (-0x10000 < msd && msd < 0x10000)
            {
// Here the top digit is reasonably small, so I can combine the top two
// digits to get a value that will be at worst 48-bits wide and hence
// will be converted to floating point without any rounding at all.
                r = TWO_31*r + static_cast<double>(bignum_digits(v)[--n]);
                x -= 31;
// Now I need to combine in lower order bits
                lo = bignum_digits(v)[--n];
                while (n > 0)
                {   if (bignum_digits(v)[--n] != 0) lo |= 1;
                }
// The bottom bit of lo will be well below the bits that contribute
// directly to the result, but by ORing in 1 there if any lower word is
// non-zero I will force rounding up in some cases where it is needed.
                r = TWO_31*r + static_cast<double>(lo);
                x -= 31;
            }
            else
            {
// Here the top digit is reasonably large, so I will combine it with the
// top 15 bits from the second highest digit. That will give me a value
// using between 31 and 46 bits. This can be computed without rounding.
                int32_t mid = bignum_digits(v)[--n];
                r = 32768.0*r + static_cast<double>(mid >> 16);
                x -= 15;
                lo = bignum_digits(v)[--n];
                mid = ((mid & 0xffff) << 15) | (lo >> 16);
                if ((lo & 0xffff) != 0) mid |= 1;
                while (n > 0)
                {   if (bignum_digits(v)[--n] != 0) mid |= 1;
                }
                r = TWO_31*r + static_cast<double>(mid);
                x -= 31;
            }
        }
    }
    *xp = x;
    return r;
}

#ifdef HAVE_SOFTFLOAT
#ifdef LITTLEENDIAN
static float128_t f128_TWO_31 = {{0, INT64_C(0x401e000000000000)}};
#else
static float128_t f128_TWO_31 = {{INT64_C(0x401e000000000000), 0}};
#endif

static float128_t bignum_to_float128(LispObject v, int32_t h, int *xp)
//
// Convert a Lisp bignum to get a 128-bit floating point value.
// This uses at most the top 5 digits of the bignum's representation
// since that is enough to achieve full accuracy.
// This can not overflow, because it leaves an exponent-adjustment value
// in *xp. You need "ldexp128(r, *xp)" afterwards.
//
// WELL actually just using the top 5 digits us not enough! Consider an
// integer whose mantissa has 0.5 in the last place, then a long string of
// zero bits and then MAYBE a final trailing 1 that could force rounding up
// rather than down...
{   int32_t n = (h-CELL-4)/4;  // Last index into the data
    int x = 31*static_cast<int>(n);
    int32_t msd = (int32_t)bignum_digits(v)[n];
// NB signed conversion on next line
    float128_t r, w1, w2;
    i32_to_f128M(msd, &r);
    switch (n)
{       default:        // for very big numbers combine in 5 digits
            ui32_to_f128M(bignum_digits(v)[--n], &w1);
            f128M_mul(&r, &f128_TWO_31, &w2);
            f128M_add(&w1, &w2, &r);
            x -= 31;
        // drop through
        case 3:
            ui32_to_f128M(bignum_digits(v)[--n], &w1);
            f128M_mul(&r, &f128_TWO_31, &w2);
            f128M_add(&w1, &w2, &r);
            x -= 31;
        // drop through
        case 2:
            ui32_to_f128M(bignum_digits(v)[--n], &w1);
            f128M_mul(&r, &f128_TWO_31, &w2);
            f128M_add(&w1, &w2, &r);
            x -= 31;
        // drop through
        case 1:
            ui32_to_f128M(bignum_digits(v)[--n], &w1);
            f128M_mul(&r, &f128_TWO_31, &w2);
            f128M_add(&w1, &w2, &r);
            x -= 31;
        // drop through
        case 0: break;  // do no more
    }
    *xp = x;
    return r;
}

#endif // HAVE_SOFTFLOAT

// Now two functions that will help me to turn floats into (potentially big)
// integers or rationals, or to compare floats with bignums.

// double_to_binary returns an integer exponent and sets m such that the
// original float is equal to m*2^x. It returns special values for x in the
// case of infinities and NaNs.

int double_to_binary(double d, int64_t &m)
#ifdef OLD_VERSION
{   Double_union u;
// What is done here is an improper use of the union type even if it is
// what old-fashioned C expected to be able to do. I could use std::frexp
// after checking for infinities and NaNs and be much more officially safe!
    u.f = d;
    int x = static_cast<int>(u.i64 >> 52) & 0x7ff;
    int64_t f = u.i64 & UINT64_C(0x000fffffffffffff);
    if (x != 0) f |= INT64_C(0x0010000000000000);
    if ((int64_t)u.i64 < 0) f = -f;
    m = f;
// for Infinity I will return INT_MAX and for a NaN INT_MIN as otherwise
// invalid exponent values.
    if (x == 0x7ff) return f==0 ? INT_MAX : INT_MIN;
    return x - 0x3ff - 52;
}
#else // OLD_VERSION
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
#endif // OLD_VERSION

#ifdef HAVE_SOFTFLOAT
// This does much the same for 128-bit floats.

int float128_to_binary(const float128_t *d, int64_t &mhi,
                       uint64_t &mlo)
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
// 3 words of a bignum representation of the value, and size_t value that
// indicates the total number of words that the bignum would need to use.
// If this value is 2 then the 3 word-sized digits are all that the
// bignum will use. If it is 1 then either you have a 2-word bignum or
// a fixnum, and if a0 is non-zero a remainder. If it is 0 then the
// integer value is all in a2 and you either need a fixnum or a 1-word
// bignum (on 32-bit machines) and a1, a0 mark a fractional part. Values
// less than zero correspond to fractional floating point values.
// If the argument is infinite or a NaN the result will be INTPTR_MAX.

intptr_t double_to_3_digits(double d, int32_t &a2, uint32_t &a1,
                            uint32_t &a0)
{   int64_t m;
    int x = double_to_binary(d, m);
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
intptr_t float128_to_5_digits(float128_t *d,
                              int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0)
{   int64_t mhi;
    uint64_t mlo;
    int x = float128_to_binary(d, mhi, mlo);
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

double float_of_number(LispObject a)
//
// Return a (double precision) floating point value for the given Lisp
// number, or 0.0 in case of trouble.  This is often called in circumstances
// where I already know the type of its argument and so its type-dispatch
// is unnecessary - in doing so I am trading off performance against
// code repetition. Be aware that for long floats I will need to do something
// different!
//
{   if (is_fixnum(a)) return static_cast<double>(int_of_fixnum(a));
    else if (is_sfloat(a))
        return value_of_immediate_float(a);
    else if (is_bfloat(a))
    {   int32_t h = type_of_header(flthdr(a));
        switch (h)
        {   case TYPE_SINGLE_FLOAT:
// On a 64-bit system one should NEVER encounter a boxed single precision
// float, and so to improve reliability I will raise an error if one is
// seen.
                if (SIXTY_FOUR_BIT)
                    return aerror("boxed single float on 64-bit system");
                return static_cast<double>(single_float_val(a));
            case TYPE_DOUBLE_FLOAT:
                return double_float_val(a);
#ifdef HAVE_SOFTFLOAT
            case TYPE_LONG_FLOAT:
            {   float128_t w = long_float_val(a);
                union
                {   float64_t sf;
                    double f;
                } f;
                f.sf = f128M_to_f64(&w);
                return f.f;
            }
#endif // HAVE_SOFTFLOAT
            default:
                return 0.0;
        }
    }
    else
    {   Header h = numhdr(a);
        int x1;
        double r1;
        switch (type_of_header(h))
        {   case TYPE_BIGNUM:
                r1 = bignum_to_float(a, length_of_header(h), &x1);
                return std::ldexp(r1, x1);
            case TYPE_RATNUM:
            {   int x2;
                LispObject na = numerator(a);
                a = denominator(a);
                if (is_fixnum(na)) r1 = float_of_number(na), x1 = 0;
                else r1 = bignum_to_float(na,
                              length_of_header(numhdr(na)), &x1);
                if (is_fixnum(a)) r1 = r1 / float_of_number(a), x2 = 0;
                else r1 = r1 / bignum_to_float(a,
                                   length_of_header(numhdr(a)), &x2);
// Floating point overflow can only arise in this ldexp()
                return std::ldexp(r1, x1 - x2);
            }
            default:
//
// If the value was non-numeric or a complex number I hand back 0.0,
// and since I am supposed to have checked the object type already
// this OUGHT not to arrive - bit raising an exception seems over-keen.
//
                return 0.0;
        }
    }
}

#ifdef HAVE_SOFTFLOAT
float128_t float128_of_number(LispObject a)
//
// Return a 128-bit floating point value for the given Lisp
// number, or 0.0 in case of trouble.
//
{   float128_t r;
    float64_t r64;
    float32_t r32;
    if (is_fixnum(a))
    {   i64_to_f128M((int64_t)int_of_fixnum(a), &r);
        return r;
    }
    else if (is_sfloat(a))
    {   Float_union w;
        if (SIXTY_FOUR_BIT) w.i = (int32_t)((uint64_t)a>>32);
        else w.i = a - XTAG_SFLOAT;
        f32_to_f128M(w.f32, &r);
        return r;
    }
    else if (is_bfloat(a))
    {   int32_t h = type_of_header(flthdr(a));
        switch (h)
        {   case TYPE_SINGLE_FLOAT:
                r32 = float32_t_val(a);
                f32_to_f128M(r32, &r);
                if (SIXTY_FOUR_BIT)
                    aerror("boxed single float on 64-bit system");
                return r;
            case TYPE_DOUBLE_FLOAT:
                r64 = float64_t_val(a);
                f64_to_f128M(r64, &r);
                return r;
            case TYPE_LONG_FLOAT:
                return float128_t_val(a);
            default:
                i32_to_f128M(0, &r);
                return r;
        }
    }
    else
    {   Header h = numhdr(a);
        int x1;
        float128_t r1, r2, w;
        switch (type_of_header(h))
        {   case TYPE_BIGNUM:
                r1 = bignum_to_float128(a, length_of_header(h), &x1);
                f128M_ldexp(&r1, x1);
                return r1;
            case TYPE_RATNUM:
            {   int x2;
                LispObject na = numerator(a);
                a = denominator(a);
                if (is_fixnum(na)) r1 = float128_of_number(na), x1 = 0;
                else r1 = bignum_to_float128(na,
                              length_of_header(numhdr(na)), &x1);
                if (is_fixnum(a)) r2 = float128_of_number(a), x2 = 0;
                else r2 = bignum_to_float128(a,
                              length_of_header(numhdr(a)), &x2);
                f128M_div(&r1, &r2, &w);
                f128M_ldexp(&w, x1 - x2);
                return w;
            }
            default:
//
// If the value was non-numeric or a complex number I hand back 0.0,
// and since I am supposed to have checked the object type already
// this OUGHT not to arrive - but raising an exception seems over-keen.
//
                i32_to_f128M(0, &r);
                return r;
        }
    }
}
#endif // HAVE_SOFTFLOAT

int32_t thirty_two_bits(LispObject a)
// return a 32 bit integer value for the Lisp integer (fixnum or bignum)
// passed down - return 0 if the arg was out of range, or floating,
// rational etc or not a number at all.  Only really wanted where
// links between C-specific code (that might really want 32-bit values)
// and Lisp are being coded.
{   int64_t r;
    switch (static_cast<int>(a) & XTAG_BITS)
    {   case TAG_FIXNUM:
            r = (int64_t)int_of_fixnum(a);
            if (r > INT32_MAX ||
                r < INT32_MIN) return 0;
            return (int32_t)r;
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
            if (is_bignum(a))
            {   size_t len = bignum_length(a);
// Note that I keep 31 bits per word and use a 2s complement representation.
// thus if I have a one-word bignum I just want its contents but in all
// other cases I need just one bit from the next word up.
// The left shift by 31-bits is OK because it is on an unsigned value.
                if (len == CELL+4) return bignum_digits(a)[0]; // One word.
                if (len == CELL+8)
                {   uint32_t d1 = bignum_digits(a)[1];
                    if (d1 == 0 || d1 == 0xffffffff)
                        return bignum_digits(a)[0] | (d1 << 31);
                }
            }
        // else drop through
        default:
// return 0 for all non-fixnums and for varius overflow cases
            return 0;
    }
}

uint32_t thirty_two_bits_unsigned(LispObject a)
// return a 32 bit unsigned integer value for the Lisp integer (fixnum
// or bignum) passed down - return 0 if the arg was out of range, or
// floating, rational etc or not a number at all.  Only really wanted where
// links between C-specific code (that might really want 32-bit values)
// and Lisp are being coded.
{   int64_t r;
    switch (static_cast<int>(a) & XTAG_BITS)
    {   case TAG_FIXNUM:
            r = (int64_t)int_of_fixnum(a);
            if (r > UINT32_MAX ||
                r < 0) return 0;
            return (int32_t)r;
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
            if (is_bignum(a))
            {   size_t len = bignum_length(a);
// Note that I keep 31 bits per word and use a 2s complement representation.
                if (len == CELL+4)
                {   int32_t w = (int32_t)bignum_digits(a)[0]; // One word.
                    if (w < 0) return 0;
                    else return w;
                }
                if (len == CELL+8)
                {   uint32_t d1 = bignum_digits(a)[1];
                    if (d1 == 0 || d1 == 1)
                        return bignum_digits(a)[0] | (d1 << 31);
                }
            }
        // else drop through
        default:
// return 0 for all non-fixnums and for varius overflow cases
            return 0;
    }
}

// This returns a 64-bit signed integer if the argument is in that range,
// or 0 for an invalid argument.

int64_t sixty_four_bits(LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case TAG_FIXNUM:
            return (int64_t)int_of_fixnum(a); // always in range
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
            if (is_bignum(a))
            {   int len = bignum_length(a);
                switch (len)
                {   case CELL+4:
// One word bignum. Do a double cast to stress how sign extension is needed.
                        return (int64_t)(int32_t)bignum_digits(a)[0];
                    case CELL+8:
// Here the bignum provides 62 bits as a 2s complement value
                        return bignum_digits(a)[0] |
                               ASL(bignum_digits64(a, 1), 31);
                    default:
                        int64_t d2 = bignum_digits64(a, 2);
                        if (d2==0 || d2==1 || d2==-1 || d2==-2)
                            return bignum_digits(a)[0] |
                                   ((uint64_t)bignum_digits(a)[1] << 31) |
                                   ASL(d2, 62);
                }
            }
        // else drop through
        default:
// return 0 for all non-fixnums
            return 0;
    }
}

uint64_t sixty_four_bits_unsigned(LispObject a)
{   switch (static_cast<int>(a) & XTAG_BITS)
    {   case TAG_FIXNUM:
            if (int_of_fixnum(a) < 0) return 0;
            return (uint64_t)int_of_fixnum(a);
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
            if (is_bignum(a))
            {   int len = bignum_length(a);
                switch (len)
                {   case CELL+4:
                        if ((int32_t)bignum_digits(a)[0] < 0) return 0;
                        return (uint64_t)bignum_digits(a)[0];
                    case CELL+8:
                        if ((int32_t)bignum_digits(a)[1] < 0) return 0;
                        return bignum_digits(a)[0] |
                               ASL(bignum_digits64(a, 1), 31);
                    default:
                        int64_t d2 = bignum_digits64(a, 2);
                        if (d2==0 || d2==1 || d2==2 || d2==3)
                            return bignum_digits(a)[0] |
                                   ((uint64_t)bignum_digits(a)[1] << 31) |
                                   ASL(d2, 62);
                }
            }
        // else drop through
        default:
// return 0 for all non-fixnums or for overflow
            return 0;
    }
}

LispObject make_complex(LispObject r, LispObject i)
{   LispObject v;
//
// Here r and i are expected to be either both rational (which in this
// context includes the case of integer values) or both of the same
// floating point type.  It is assumed that this has already been
// arranged by here.
//
    if (i == fixnum_of_int(0)) return r;
    stackcheck(r, i);
    {   Save save(r, i);
        v = get_basic_vector(TAG_NUMBERS, TYPE_COMPLEX_NUM,
                         sizeof(Complex_Number));
        errexit();
        save.restore(r, i);
// The vector r has uninitialized contents here - dodgy.  If the call
// to get_basic_vector succeeded then I fill it in, otherwise I will not
// refer to it again, and I think that unreferenced vectors containing junk
// are OK.
    }
    setreal_part(v, r);
    setimag_part(v, i);
    return v;
}

LispObject make_ratio(LispObject p, LispObject q)
// By the time this is called (p/q) must be in its lowest terms, q>0
// If q=1 then this just returns p, so the rational reverts to an integer.
{   LispObject v;
    if (q == fixnum_of_int(1)) return p;
    stackcheck(p, q);
    {   Save save(p, q);
        v = get_basic_vector(TAG_NUMBERS, TYPE_RATNUM,
                             sizeof(Rational_Number));
        errexit();
        save.restore(p, q);
    }
    setnumerator(v, p);
    setdenominator(v, q);
    return v;
}

//
// The next bit of code seems pretty dreadful, but I think that is just
// what generic arithmetic is all about.  The code for plus2 is written
// as a dispatch function into over 30 separate possible type-specific
// versions of the code.  In a very few simple (and performance-critical)
// cases the code is written in-line in plus2 - in particular arithmetic
// on fixnums is done that way.  Similarly for other cases.
// I Use one-character suffices to remind me about types:
//          i       fixnum
//          b       bignum
//          r       ratio
//          s       short float
//          f       boxed float (single/double/long)
//          c       complex
//
// Throughout this code I am going to IGNORE floating point exceptions,
// at least for a first attempt.  Decent detection of and recovery after
// floating point overflow seems an extra unpleasant distraction!  Note
// that I could trap the SIGFPE exception, but working out just how to
// continue is then horrid - and anyway these days most situations where a
// floating point calculation is problemematic tend to lead to a NaN not
// to an SIGFPE, so really this concern is probably now one rooted in
// ancient history!
//
// It would perhaps be reasonable to write the dispatch code as a big
// macro so that the versions for plus, times etc could all be kept
// in step - I have not done that (a) because the macro would have been
// bigger than I like macros to be (b) it would have involved token-
// splicing (or VERY many parameters) to generate the names of the
// separate type-specific procedures and (c) doing it by hand allows me
// total flexibility about coding various cases in-line. But at some stage
// perhaps C++ templates will take the strain in a neat manner?
//

inline LispObject plus_i_i(LispObject a1, LispObject a2);
inline LispObject plus_i_b(LispObject a1, LispObject a2);
inline LispObject plus_i_r(LispObject a1, LispObject a2);
inline LispObject plus_i_c(LispObject a1, LispObject a2);
inline LispObject plus_i_s(LispObject a1, LispObject a2);
inline LispObject plus_i_f(LispObject a1, LispObject a2);
inline LispObject plus_i_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject plus_i_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject plus_b_i(LispObject a1, LispObject a2);
inline LispObject plus_b_b(LispObject a1, LispObject a2);
inline LispObject plus_b_r(LispObject a1, LispObject a2);
inline LispObject plus_b_c(LispObject a1, LispObject a2);
inline LispObject plus_b_s(LispObject a1, LispObject a2);
inline LispObject plus_b_f(LispObject a1, LispObject a2);
inline LispObject plus_b_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject plus_b_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject plus_r_i(LispObject a1, LispObject a2);
inline LispObject plus_r_b(LispObject a1, LispObject a2);
inline LispObject plus_r_r(LispObject a1, LispObject a2);
inline LispObject plus_r_c(LispObject a1, LispObject a2);
inline LispObject plus_r_s(LispObject a1, LispObject a2);
inline LispObject plus_r_f(LispObject a1, LispObject a2);
inline LispObject plus_r_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject plus_r_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject plus_c_i(LispObject a1, LispObject a2);
inline LispObject plus_c_b(LispObject a1, LispObject a2);
inline LispObject plus_c_r(LispObject a1, LispObject a2);
inline LispObject plus_c_c(LispObject a1, LispObject a2);
inline LispObject plus_c_s(LispObject a1, LispObject a2);
inline LispObject plus_c_f(LispObject a1, LispObject a2);
inline LispObject plus_c_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject plus_c_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject plus_s_i(LispObject a1, LispObject a2);
inline LispObject plus_s_b(LispObject a1, LispObject a2);
inline LispObject plus_s_r(LispObject a1, LispObject a2);
inline LispObject plus_s_c(LispObject a1, LispObject a2);
inline LispObject plus_s_s(LispObject a1, LispObject a2);
inline LispObject plus_s_f(LispObject a1, LispObject a2);
inline LispObject plus_s_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject plus_s_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject plus_f_i(LispObject a1, LispObject a2);
inline LispObject plus_f_b(LispObject a1, LispObject a2);
inline LispObject plus_f_r(LispObject a1, LispObject a2);
inline LispObject plus_f_c(LispObject a1, LispObject a2);
inline LispObject plus_f_s(LispObject a1, LispObject a2);
inline LispObject plus_f_f(LispObject a1, LispObject a2);
inline LispObject plus_f_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject plus_f_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject plus_d_i(LispObject a1, LispObject a2);
inline LispObject plus_d_b(LispObject a1, LispObject a2);
inline LispObject plus_d_r(LispObject a1, LispObject a2);
inline LispObject plus_d_c(LispObject a1, LispObject a2);
inline LispObject plus_d_s(LispObject a1, LispObject a2);
inline LispObject plus_d_f(LispObject a1, LispObject a2);
inline LispObject plus_d_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject plus_d_l(LispObject a1, LispObject a2);

inline LispObject plus_l_i(LispObject a1, LispObject a2);
inline LispObject plus_l_b(LispObject a1, LispObject a2);
inline LispObject plus_l_r(LispObject a1, LispObject a2);
inline LispObject plus_l_c(LispObject a1, LispObject a2);
inline LispObject plus_l_s(LispObject a1, LispObject a2);
inline LispObject plus_l_f(LispObject a1, LispObject a2);
inline LispObject plus_l_d(LispObject a1, LispObject a2);
inline LispObject plus_l_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject difference_i_i(LispObject a1, LispObject a2);
inline LispObject difference_i_b(LispObject a1, LispObject a2);
inline LispObject difference_i_r(LispObject a1, LispObject a2);
inline LispObject difference_i_c(LispObject a1, LispObject a2);
inline LispObject difference_i_s(LispObject a1, LispObject a2);
inline LispObject difference_i_f(LispObject a1, LispObject a2);
inline LispObject difference_i_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject difference_i_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject difference_b_i(LispObject a1, LispObject a2);
inline LispObject difference_b_b(LispObject a1, LispObject a2);
inline LispObject difference_b_r(LispObject a1, LispObject a2);
inline LispObject difference_b_c(LispObject a1, LispObject a2);
inline LispObject difference_b_s(LispObject a1, LispObject a2);
inline LispObject difference_b_f(LispObject a1, LispObject a2);
inline LispObject difference_b_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject difference_b_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject difference_r_i(LispObject a1, LispObject a2);
inline LispObject difference_r_b(LispObject a1, LispObject a2);
inline LispObject difference_r_r(LispObject a1, LispObject a2);
inline LispObject difference_r_c(LispObject a1, LispObject a2);
inline LispObject difference_r_s(LispObject a1, LispObject a2);
inline LispObject difference_r_f(LispObject a1, LispObject a2);
inline LispObject difference_r_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject difference_r_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject difference_c_i(LispObject a1, LispObject a2);
inline LispObject difference_c_b(LispObject a1, LispObject a2);
inline LispObject difference_c_r(LispObject a1, LispObject a2);
inline LispObject difference_c_c(LispObject a1, LispObject a2);
inline LispObject difference_c_s(LispObject a1, LispObject a2);
inline LispObject difference_c_f(LispObject a1, LispObject a2);
inline LispObject difference_c_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject difference_c_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject difference_s_i(LispObject a1, LispObject a2);
inline LispObject difference_s_b(LispObject a1, LispObject a2);
inline LispObject difference_s_r(LispObject a1, LispObject a2);
inline LispObject difference_s_c(LispObject a1, LispObject a2);
inline LispObject difference_s_s(LispObject a1, LispObject a2);
inline LispObject difference_s_f(LispObject a1, LispObject a2);
inline LispObject difference_s_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject difference_s_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject difference_f_i(LispObject a1, LispObject a2);
inline LispObject difference_f_b(LispObject a1, LispObject a2);
inline LispObject difference_f_r(LispObject a1, LispObject a2);
inline LispObject difference_f_c(LispObject a1, LispObject a2);
inline LispObject difference_f_s(LispObject a1, LispObject a2);
inline LispObject difference_f_f(LispObject a1, LispObject a2);
inline LispObject difference_f_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject difference_f_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

inline LispObject difference_d_i(LispObject a1, LispObject a2);
inline LispObject difference_d_b(LispObject a1, LispObject a2);
inline LispObject difference_d_r(LispObject a1, LispObject a2);
inline LispObject difference_d_c(LispObject a1, LispObject a2);
inline LispObject difference_d_s(LispObject a1, LispObject a2);
inline LispObject difference_d_f(LispObject a1, LispObject a2);
inline LispObject difference_d_d(LispObject a1, LispObject a2);
#ifdef HAVE_SOFTFLOAT
inline LispObject difference_d_l(LispObject a1, LispObject a2);

inline LispObject difference_l_i(LispObject a1, LispObject a2);
inline LispObject difference_l_b(LispObject a1, LispObject a2);
inline LispObject difference_l_r(LispObject a1, LispObject a2);
inline LispObject difference_l_c(LispObject a1, LispObject a2);
inline LispObject difference_l_s(LispObject a1, LispObject a2);
inline LispObject difference_l_f(LispObject a1, LispObject a2);
inline LispObject difference_l_d(LispObject a1, LispObject a2);
inline LispObject difference_l_l(LispObject a1, LispObject a2);
#endif // HAVE_SOFTFLOAT

// I rather expect plus_i_i to be the case that arises most frequently.

inline LispObject plus_i_i(LispObject a1, LispObject a2)
{   return make_lisp_integer64(int_of_fixnum(a1) + int_of_fixnum(a2));
}

// Add a fixnum to a bignum, returning a result as a fixnum or bignum
// depending on its size.  This seems much nastier than one would have
// hoped. Well all in all a LOT of the arithmetic ends up being way messier
// that an idealist would have expected. This is perhaps related to there
// being potential boundary cases when input or output values are around
// 27, 30, 59, 61, 92, ... bits wide.

// Through much of this code I am going to be close to neurotic about
// casting to unsigned types before I do arithmetic. This is because
// integer overflow (eg a carry that goes into the sign bit and flips it)
// is deemed an undefined behaviour by C++, abd clever compilers may
// exploit this so that the compiled code assumes that overflow will
// never arise. So code such as
//     int32_t w = a + b;   // a and b are 31-bit values here
//     int carry = (w >> 31) & 1;
//     int32_t sum = w & 0x7fffffff;
// is not proper. If a and b start off positive and the initial addition
// would leave to a value over 0x7fffffff that is overflow so the
// consequences are undefined. That means that any value left in carry
// or sum are undefined, so a compiler could be entitled to simplify the
// generated code in any way it could think of to exploit that. A natural
// possibility would be to assume that carry was always going to be zero
// and the top bit of w was always zero so the mask operation could be
// omitted. If I use unsigned arithmetic I will be somewhat safer.

inline LispObject plus_i_b(LispObject a1, LispObject a2)
{   size_t len = (bignum_length(a2)-CELL)/4, i;
    intptr_t s1 = int_of_fixnum(a1);
// If you are on a 64-bit machine it should NEVER be possible to end up
// with a 1-word bignum, because the relevant range always fits within
// a fixnum. The test on SIXTY_FOUR_BIT here should end up letting a reasonably
// clever compiler omit the code that covers this case.
    if (!SIXTY_FOUR_BIT && len == 1)
        return make_lisp_integerptr((int32_t)bignum_digits(a2)[0] + s1);
// I write out the 2-word case longhand because in the 64-bit case
// it can yield a fixnum.
    if (len == 2)
    {   int64_t s = (ASL(bignum_digits64(a2,1),
                         31) | bignum_digits(a2)[0]) +
                    (int64_t)s1;
// a 2-word bignum has at worst 62 bits and a fixnum 28 or 60, so their
// sum can not overflow a 64-bit word.
        return make_lisp_integer64(s);
    }
// The bignum a2 now has at least 3 digits. I will view this as now a case
// where I do not need to optimise edge cases so carefully, and where the
// length (as a bignum) of the result is rather likely to match that of a2.
    LispObject c;
    {   Save save(a2);
        c = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*len);
        errexit();
        save.restore(a2);
    }
// Add in the lowest digit by hand because at this stage s1 can have
// more than 31 bits and so intrudes beyond there.
    uint32_t d0 = bignum_digits(a2)[0] + (uint32_t)clear_top_bit(s1);
    bignum_digits(c)[0] = clear_top_bit(d0);
    s1 = ASR((int64_t)s1, 31);
    if (top_bit_set(d0)) s1 = s1 + 1;
// Now s1 is at most 29 bits... I can treat it as a carry from the
// previous digit. Note that it may be either positive or negative
    for (i=1; i<len-1; i++)
    {   uint32_t s = bignum_digits(a2)[i] + (uint32_t)(s1 & 0x7fffffff);
        s1 = ASR((int64_t)s1,
                 31); // Note that s1 was signed so this is -1, 0 or 1
        bignum_digits(c)[i] = s & 0x7fffffff;
        s1 = s1 + top_bit(s);
    }
    s1 = (int32_t)ADD32(s1, bignum_digits(a2)[i]);
// A trap I fell into here is that ADD32 returns an unsigned result and when
// that expands to an uniptr_t on a 64-bit machine it gets zero bits stuck
// on the front. Then when I compare against -1 it says "no".
    if (!signed_overflow((int32_t)s1))         // did it overflow?
    {
// Here the most significant digit did not produce an overflow, but maybe
// what we actually had was some cancellation and the MSD is now zero
// or -1, so that the number should shrink...
        if ((s1 == 0 && (bignum_digits(c)[i-1] & 0x40000000) == 0) ||
            (s1 == -1 && (bignum_digits(c)[i-1] & 0x40000000) != 0))
        {   // shrink the number
            setnumhdr(c, numhdr(c) - pack_hdrlength(1L));
            if (s1 == -1) bignum_digits(c)[i-1] |= 0x80000000;
// Now sometimes the shrinkage will leave a padding word, sometimes it
// will really allow me to save space. As a jolly joke with a 64-bit
// system I need padding if there have been an odd number of (32-bit)
// words of bignum data while with a 32-bit system the header word is
// 32-bits wide and I need padding if there are ar even number of additional
// data words.
            if ((SIXTY_FOUR_BIT && ((i & 1) != 0)) ||
                (!SIXTY_FOUR_BIT && ((i & 1) == 0)))
            {   bignum_digits(c)[i] = 0;   // leave the unused word tidy
                return c;
            }
//
// Having shrunk the number I am leaving a doubleword of unallocated space
// in the heap.  Dump a header word into it to make it look like an
// 8-byte bignum since that will allow the garbage collector to handle it.
// It I left it containing arbitrary junk I could wreck myself. The
// make_bighdr(2L) makes a header for a number that fills 2 32-bit words
// in all.
// AHAHA. With the "Late 2016" model garbage collector and preserve/restart
// plus the "Early 2017" rework of mapstore() I believe there will never be
// any linear scanning of active heap, and so this (minor) extra cost could
// be avoided. I will leave it in here as a matter of being tidy as well as
// against the possibility that future GC re-works require it!
//
            *reinterpret_cast<Header *>(&bignum_digits(c)[i]) = make_bighdr(2L);
            return c;
        }
        bignum_digits(c)[i] = s1;  // length unchanged
        return c;
    }
//
// Here the result is one word longer than the input-bignum.
// Once again SOMTIMES this will not involve allocating more store,
// but just encroaching into the previously unused word that was padding
// things out to a multiple of 8 bytes.
//
    if ((SIXTY_FOUR_BIT && ((i & 1) == 0)) ||
        (!SIXTY_FOUR_BIT && ((i & 1) == 1)))
    {   bignum_digits(c)[i++] = clear_top_bit(s1);
        bignum_digits(c)[i] = top_bit_set(s1) ? -1 : 0;
        setnumhdr(c, numhdr(c) + pack_hdrlength(1L));
        return c;
    }
    {   Save save(c);
        a2 = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4+4*len);
        errexit();
        save.restore(c);
    }
    for (size_t i=0; i<len-1; i++)
        bignum_digits(a2)[i] = vbignum_digits(c)[i];
//
// I move the top digit across by hand since if the number is negative
// I must lose its top bit
//
    bignum_digits(a2)[i++] = clear_top_bit(s1);
// Now the one-word extension to the number
    bignum_digits(a2)[i++] = top_bit_set(s1) ? -1 : 0;
//
// Finally because I know that I expanded into a new doubleword I should
// tidy up the second word of the newly allocated pair. I know I added two
// extra words because if I was just filling in the second of two existing
// words I did not do not do the fresh get_basic_vector() here...
//
    bignum_digits(a2)[i] = 0;
    return a2;
}


// Add a fixnum to a ratio, but also valid for bignum and ratio.
// Note that if the inputs were in lowest terms there is no need for
// and GCD calculations here.

inline LispObject plus_i_r(LispObject a1, LispObject a2)
{   {   Save save(a2);
        a1 = times2(a1, denominator(a2));
        errexit();
        save.restore(a2);
        a1 = plus2(a1, numerator(a2));
        errexit();
        save.restore(a2);
    }
    return make_ratio(a1, denominator(a2));
}


// real value of any sort plus complex.

inline LispObject plus_i_c(LispObject a1, LispObject a2)
{   {   Save save(a2);
        a1 = plus2(a1, real_part(a2));
        errexit();
        save.restore(a2);
    }
// make_complex() takes responsibility for mapping #C(n 0) onto n
    return make_complex(a1, imag_part(a2));
}

inline LispObject plus_i_s(LispObject a1, LispObject a2)
{   double d = static_cast<double>(int_of_fixnum(a1)) +
               value_of_immediate_float(a2);
    return pack_immediate_float(d, a2);
}

inline LispObject plus_i_f(LispObject a1, LispObject a2)
{   double d = static_cast<double>(int_of_fixnum(a1)) +
               single_float_val(a2);
    return make_boxfloat(d, TYPE_SINGLE_FLOAT);
}

inline LispObject plus_i_d(LispObject a1, LispObject a2)
{   double d = static_cast<double>(int_of_fixnum(a1)) +
               double_float_val(a2);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject plus_i_l(LispObject a1, LispObject a2)
{   float128_t x, z;
    i64_to_f128M((int64_t)int_of_fixnum(a1), &x);
    f128M_add(&x, reinterpret_cast<float128_t *>(long_float_addr(a2)), &z);
    return make_boxfloat128(z);
}
#endif // HAVE_SOFTFLOAT

inline LispObject plus_b_i(LispObject a1, LispObject a2)
{   return plus_i_b(a2, a1);
}

// Add two bignums.

LispObject lengthen_by_one_bit(LispObject a, int32_t msd)
// (a) is a bignum, and arithmetic on it has (just) caused overflow
// in its top word - I just need to stick on another word. (msd) is the
// current top word, and its sign will be used to decide on the value
// that must be appended.
{   int32_t len = bignum_length(a);
// Sometimes I need to allocate a new vector and copy data across into it
    if ((len & 4) == 0)
    {   LispObject b;
        int32_t i;
        {   Save save(a);
            b = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, len+4);
            errexit();
            save.restore(a);
        }
        len = (len-CELL)/4;
        for (i=0; i<len; i++)
            bignum_digits(b)[i] = clear_top_bit(bignum_digits(a)[i]);
        bignum_digits(b)[len] = top_bit_set(msd) ? -1 : 0;
        bignum_digits(b)[len+1] = 0;
        return b;
    }
    else
// .. whereas sometimes I have a spare word already available.
    {   setnumhdr(a, numhdr(a) + pack_hdrlength(1L));
        len = (len-CELL)/4;
        bignum_digits(a)[len-1] = clear_top_bit(bignum_digits(a)[len-1]);
        bignum_digits(a)[len] = top_bit_set(msd) ? -1 : 0;
        return a;
    }
}

inline LispObject plus_b_b(LispObject a, LispObject b)
{   size_t la = (bignum_length(a)-CELL)/4,
           lb = (bignum_length(b)-CELL)/4;
    if (la < lb)    // maybe swap order of args
    {   LispObject t = a; a = b; b = t;
        size_t t1 = la; la = lb; lb = t1;
    }
// now (a) is AT LEAST as long as (b).  I have special case code for
// when both args are single-word bignums, since I expect that to be
// an especially common case on 32-bit machines. With a 1-word bignum
// there the digits are in the range -0x40000000 to +0x3fffffff and so adding
// two of them will not lead to signed arithmetic overflow!
    if (!SIXTY_FOUR_BIT && la == 1) // and hence b also has only 1 digit
        return make_lisp_integer32(
            static_cast<int32_t>(bignum_digits(a)[0]) +
            static_cast<int32_t>(bignum_digits(b)[0]));
// If the longer number is just 2 words I can convert both to int64_t.
    if (la == 2)
    {   int64_t va = ASL(bignum_digits64(a, 1), 31) | bignum_digits(a)[0];
        int64_t vb = (!SIXTY_FOUR_BIT && lb == 1) ?
                     bignum_digits64(b, 0) :
                     ASL(bignum_digits64(b, 1), 31) | bignum_digits(b)[0];
        return make_lisp_integer64(va + vb);
    }
// Now at least one operand uses 3 words... I will do a general bignum add
// which may sometimes be overkill, but ought to be safe.
    LispObject c;
    {   Save save(a, b);
        c = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, 4*la+CELL);
        errexit();
        save.restore(a, b);
    }
    uint32_t carry = 0;
// Add all but the top digit of b
    la--;
    lb--;
    size_t i;
    for (i=0; i<lb; i++)
    {   carry = bignum_digits(a)[i] + bignum_digits(b)[i] +
                (uint32_t)top_bit(carry);
        bignum_digits(c)[i] = clear_top_bit(carry);
    }
    int32_t s;
    if (la == lb) s = bignum_digits(b)[i];
    else
// If a is strictly longer than b I sign extend b here and add in as many
// copies of 0 or -1 as needbe to get up to the length of a.
// Note that the index "i" is left over from the previous loop...
    {   s = (int32_t)bignum_digits(b)[i];
        carry =  bignum_digits(a)[i] + (uint32_t)clear_top_bit(s) +
                 (uint32_t)top_bit(carry);
        bignum_digits(c)[i] = clear_top_bit(carry);
        if (s < 0) s = -1;
        else s = 0;
        for (i++; i<la; i++)
        {   carry = bignum_digits(a)[i] + (uint32_t)clear_top_bit(s) +
                    (uint32_t)top_bit(carry);
            bignum_digits(c)[i] = clear_top_bit(carry);
        }
    }
    carry = (int32_t)bignum_digits(a)[i] + (uint32_t)s +
            (uint32_t)top_bit(carry);
// I need to know if the top digit leads to 31-bit signed overflow.
    if (!signed_overflow(carry))
    {
//
// Here the number has not expanded - but it may be shrinking, and it can
// shrink by any number of words, all the way down to a fixnum maybe.  Note
// that I started with at least a 2-word bignum here.
//
        int32_t msd;
        bignum_digits(c)[i] = carry;
        if (carry == 0)
        {   size_t j = i-1;
            while ((msd = bignum_digits(c)[j]) == 0 && j > 0) j--;
            if (SIXTY_FOUR_BIT && j == 1)
            {   int64_t s = ASL(bignum_digits64(c,1), 31) |
                            bignum_digits(c)[0];
                if (valid_as_fixnum(s)) return fixnum_of_int(s);
            }
            else if (j == 0)
            {   int32_t s = bignum_digits(c)[0];
                if (valid_as_fixnum(s)) return fixnum_of_int(s);
            }
// ... but I may need a zero word on the front if the next word down
// has its top bit set... (top of 31 bits, that is)
            if ((msd & 0x40000000) != 0)
            {   j++;
                if (i == j) return c;
            }
// I am shrinking the vector. In some cases all I need to do is to
// fix up its header-word.
            if ((SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) != 0)) ||
                (!SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) == 0)))
            {   setnumhdr(c, numhdr(c) - pack_hdrlength(1L));
                return c;
            }
// A more complicated truncation case.
            setnumhdr(c, numhdr(c) - pack_hdrlength(i - j));
            if (SIXTY_FOUR_BIT)
            {   i = (i+2) & ~1;
                j = (j+2) & ~1;     // Round up to odd index
            }
            else
            {   i = (i+1) | 1;
                j = (j+1) | 1;     // Round up to odd index
            }
// I forge a header word to fill in the discarded space. This is no longer
// vital, but it still feels the tidy thing to do.
            if (i != j) *reinterpret_cast<Header *>(&bignum_digits(
                        c)[j]) = make_bighdr(i - j);
            return c;
        }
// Now do all the same sorts of things but this time for negative numbers.
        else if (carry == 0xffffffff)
        {   size_t j = i-1;
            msd = carry;    // in case j = 0
            while ((msd = bignum_digits(c)[j]) == 0x7fffffff && j > 0) j--;
            if (SIXTY_FOUR_BIT && j == 1)
            {   int64_t s = ASL(bignum_digits64(c,1) |
                                INT64_C(0xffffffff80000000), 31) |
                            bignum_digits(c)[0];
                if (valid_as_fixnum(s)) return fixnum_of_int(s);
            }
            else if (j == 0)
            {   int32_t s = bignum_digits(c)[0] | 0x80000000;
                if (valid_as_fixnum(s)) return fixnum_of_int(s);
            }
            if ((msd & 0x40000000) == 0)
            {   j++;
                if (i == j) return c;
            }
            if ((SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) != 0)) ||
                (!SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) == 0)))
            {   bignum_digits(c)[i] = 0;
                bignum_digits(c)[i-1] |= ~0x7fffffff;
                setnumhdr(c, numhdr(c) - pack_hdrlength(1));
                return c;
            }
            setnumhdr(c, numhdr(c) - pack_hdrlength(i - j));
            bignum_digits(c)[j+1] = 0;
            bignum_digits(c)[j] |= ~0x7fffffff;
            if (SIXTY_FOUR_BIT)
            {   i = (i+2) & ~1;
                j = (j+2) & ~1;     // Round up to odd index
            }
            else
            {   i = (i+1) | 1;
                j = (j+1) | 1;     // Round up to odd index
            }
            if (i != j) *reinterpret_cast<Header *>(&bignum_digits(
                        c)[j]) = make_bighdr(i - j);
            return c;
        }
        return c;
    }
    else
    {   bignum_digits(c)[i] = carry;
        return lengthen_by_one_bit(c, carry);
    }
}

inline LispObject plus_b_r(LispObject a1, LispObject a2)
{   return plus_i_r(a1, a2);
}

inline LispObject plus_b_c(LispObject a1, LispObject a2)
{   return plus_i_c(a1, a2);
}

inline LispObject plus_b_s(LispObject a1, LispObject a2)
{   double d = float_of_number(a1) + value_of_immediate_float(a2);
    return pack_immediate_float(d, a2);
}

inline LispObject plus_b_f(LispObject a1, LispObject a2)
{   double d = float_of_number(a1) + single_float_val(a2);
    return make_boxfloat(d, TYPE_SINGLE_FLOAT);
}

inline LispObject plus_b_d(LispObject a1, LispObject a2)
{   double d = float_of_number(a1) + double_float_val(a2);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject plus_b_l(LispObject a1, LispObject a2)
{   float128_t x, z;
    x = float128_of_number(a1);
    f128M_add(&x, reinterpret_cast<float128_t *>(long_float_addr(a2)), &z);
    return make_boxfloat128(z);
}
#endif // HAVE_SOFTFLOAT

inline LispObject plus_r_i(LispObject a1, LispObject a2)
{   return plus_i_r(a2, a1);
}

inline LispObject plus_r_b(LispObject a1, LispObject a2)
{   return plus_b_r(a2, a1);
}

// Adding two ratios involves some effort to keep the result in
// lowest terms.

inline LispObject plus_r_r(LispObject a1, LispObject a2)
{   RealSave save(numerator(a1), numerator(a2),
                  denominator(a1), denominator(a2), nil);
    LispObject &na = save.val(1);
    LispObject &nb = save.val(2);
    LispObject &da = save.val(3);
    LispObject &db = save.val(4);
    LispObject &g  = save.val(5);
    g = gcd(da, db);
// All the calls to quot2() in this procedure are expected - nay required -
// to give exact integer quotients.
    db = quot2(db, g);
    errexit();
    g = quot2(da, g);
    errexit();
    na = times2(na, db);
    errexit();
    nb = times2(nb, g);
    errexit();
    na = plus2(na, nb);
    errexit();
    da = times2(da, db);
    errexit();
    g = gcd(na, da);
    errexit();
    na = quot2(na, g);
    errexit();
    da = quot2(da, g);
    errexit();
    return make_ratio(na, da);
}

inline LispObject plus_r_c(LispObject a1, LispObject a2)
{   return plus_i_c(a1, a2);
}

inline LispObject plus_r_s(LispObject a1, LispObject a2)
{   return plus_b_s(a1, a2);
}

inline LispObject plus_r_f(LispObject a1, LispObject a2)
{   return plus_b_f(a1, a2);
}

inline LispObject plus_r_d(LispObject a1, LispObject a2)
{   return plus_b_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject plus_r_l(LispObject a1, LispObject a2)
{   return plus_b_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

// The code that performs arithmetic on complex values will tend to
// work by going (x + iy) + q => (x+q) + iy. It will then use generic
// arithmetic to from x+q, and this will repeat a dispatch on the type
// of q. If I was really worried about the last tiny fraction of performance
// I might unfold so that the type-information I have already collected
// was preserved, but that seems excessive at present.

inline LispObject plus_c_i(LispObject a1, LispObject a2)
{   return plus_i_c(a2, a1);
}

inline LispObject plus_c_b(LispObject a1, LispObject a2)
{   return plus_i_c(a2, a1);
}

inline LispObject plus_c_r(LispObject a1, LispObject a2)
{   return plus_i_c(a2, a1);
}

// Add complex values.

inline LispObject plus_c_c(LispObject a1, LispObject a2)
{   LispObject c;
    {   Save save(a1, a2);
        c = plus2(imag_part(a1), imag_part(a2));
        errexit();
        save.restore(a1, a2);
    }
    errexit();
    {   Save save(c);
        a1 = plus2(real_part(a1), real_part(a2));
        errexit();
        save.restore(c);
    }
    return make_complex(a1, c);
}

inline LispObject plus_c_s(LispObject a1, LispObject a2)
{   return plus_i_c(a2, a1);
}

inline LispObject plus_c_f(LispObject a1, LispObject a2)
{   return plus_i_c(a2, a1);
}

inline LispObject plus_c_d(LispObject a1, LispObject a2)
{   return plus_i_c(a2, a1);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject plus_c_l(LispObject a1, LispObject a2)
{   return plus_i_c(a2, a1);
}
#endif // HAVE_SOFTFLOAT

inline LispObject plus_s_i(LispObject a1, LispObject a2)
{   return plus_i_s(a2, a1);
}

inline LispObject plus_s_b(LispObject a1, LispObject a2)
{   return plus_b_s(a2, a1);
}

inline LispObject plus_s_r(LispObject a1, LispObject a2)
{   return plus_r_s(a2, a1);
}

inline LispObject plus_s_c(LispObject a1, LispObject a2)
{   return plus_c_s(a2, a1);
}

inline LispObject plus_s_s(LispObject a1, LispObject a2)
{   double d = value_of_immediate_float(a1) +
               value_of_immediate_float(a2);
    return pack_immediate_float(d, a1, a2);
}

inline LispObject plus_s_f(LispObject a1, LispObject a2)
{   double d = value_of_immediate_float(a1) + single_float_val(a2);
    return make_boxfloat(d, TYPE_SINGLE_FLOAT);
}

inline LispObject plus_s_d(LispObject a1, LispObject a2)
{   double d = value_of_immediate_float(a1) + single_float_val(a2);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject plus_s_l(LispObject a1, LispObject a2)
{   float128_t x, z;
    Double_union xf;
    xf.f = value_of_immediate_float(a1);
    f64_to_f128M(xf.f64, &x);
    f128M_add(&x, reinterpret_cast<float128_t *>(long_float_addr(a2)), &z);
    return make_boxfloat128(z);
}
#endif // HAVE_SOFTFLOAT

inline LispObject plus_f_i(LispObject a1, LispObject a2)
{   return plus_i_f(a2, a1);
}

inline LispObject plus_f_b(LispObject a1, LispObject a2)
{   return plus_b_f(a2, a1);
}

inline LispObject plus_f_r(LispObject a1, LispObject a2)
{   return plus_r_f(a2, a1);
}

inline LispObject plus_f_c(LispObject a1, LispObject a2)
{   return plus_c_f(a2, a1);
}

inline LispObject plus_f_s(LispObject a1, LispObject a2)
{   return plus_s_f(a2, a1);
}

inline LispObject plus_f_f(LispObject a1, LispObject a2)
{   return make_boxfloat(single_float_val(a1) + single_float_val(a2),
                         TYPE_SINGLE_FLOAT);
}

inline LispObject plus_f_d(LispObject a1, LispObject a2)
{   return make_boxfloat(single_float_val(a1) + double_float_val(a2),
                         TYPE_DOUBLE_FLOAT);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject plus_f_l(LispObject a1, LispObject a2)
{   float128_t x, z;
    Double_union xf;
    xf.f = single_float_val(a1);
    f64_to_f128M(xf.f64, &x);
    f128M_add(&x, reinterpret_cast<float128_t *>(long_float_addr(a2)),
              &z);
    return make_boxfloat128(z);
}
#endif // HAVE_SOFTFLOAT

inline LispObject plus_d_i(LispObject a1, LispObject a2)
{   return plus_i_d(a2, a1);
}

inline LispObject plus_d_b(LispObject a1, LispObject a2)
{   return plus_b_d(a2, a1);
}

inline LispObject plus_d_r(LispObject a1, LispObject a2)
{   return plus_r_d(a2, a1);
}

inline LispObject plus_d_c(LispObject a1, LispObject a2)
{   return plus_c_d(a2, a1);
}

inline LispObject plus_d_s(LispObject a1, LispObject a2)
{   return plus_s_d(a2, a1);
}

inline LispObject plus_d_f(LispObject a1, LispObject a2)
{   return plus_f_d(a2, a1);
}

inline LispObject plus_d_d(LispObject a1, LispObject a2)
{   return make_boxfloat(double_float_val(a1) + double_float_val(a2),
                         TYPE_DOUBLE_FLOAT);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject plus_d_l(LispObject a1, LispObject a2)
{   float128_t x, z;
    Double_union xf;
    xf.f = static_cast<double>(double_float_val(a1));
    f64_to_f128M(xf.f64, &x);
    f128M_add(&x, reinterpret_cast<float128_t *>(long_float_addr(a2)), &z);
    return make_boxfloat128(z);
}

inline LispObject plus_l_i(LispObject a1, LispObject a2)
{   return plus_i_l(a2, a1);
}

inline LispObject plus_l_b(LispObject a1, LispObject a2)
{   return plus_b_l(a2, a1);
}

inline LispObject plus_l_r(LispObject a1, LispObject a2)
{   return plus_r_l(a2, a1);
}

inline LispObject plus_l_c(LispObject a1, LispObject a2)
{   return plus_c_l(a2, a1);
}

inline LispObject plus_l_s(LispObject a1, LispObject a2)
{   return plus_s_l(a2, a1);
}

inline LispObject plus_l_f(LispObject a1, LispObject a2)
{   return plus_f_l(a2, a1);
}

inline LispObject plus_l_d(LispObject a1, LispObject a2)
{   return plus_d_l(a2, a1);
}

inline LispObject plus_l_l(LispObject a1, LispObject a2)
{   float128_t z;
    f128M_add(reinterpret_cast<float128_t *>(long_float_addr(a1)),
              reinterpret_cast<float128_t *>(long_float_addr(a2)), &z);
    return make_boxfloat128(z);
}
#endif // HAVE_SOFTFLOAT

arith_dispatch_2(inline, LispObject, plus)

LispObject plus2(LispObject a, LispObject b)
{
#ifdef DEBUG
    validate_number("Arg1 for plus", a, a, b);
    errexit();
    validate_number("Arg2 for plus", b, a, b);
    errexit();
    LispObject r = plus(a, b);
    errexit();
    validate_number("result for plus", r, a, b);
    errexit();
    return r;
#else
    return plus(a, b);
#endif
}

inline LispObject difference_i_i(LispObject a1, LispObject a2)
{   return make_lisp_integer64(int_of_fixnum(a1) - int_of_fixnum(a2));
}

inline LispObject difference_i_b(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_i(a1, a2);
}

inline LispObject difference_i_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_i_r(a1, a2);
}

inline LispObject difference_i_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_i_c(a1, a2);
}

inline LispObject difference_i_s(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_i_s(a1, a2);
}

inline LispObject difference_i_f(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_i_f(a1, a2);
}

inline LispObject difference_i_d(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_i_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject difference_i_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    errexit();
    return plus_i_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline LispObject difference_b_i(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_b(a1, a2);
}

inline LispObject difference_b_b(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    errexit();
    return plus_b(a1, a2);
}

inline LispObject difference_b_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_b_r(a1, a2);
}

inline LispObject difference_b_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_b_c(a1, a2);
}

inline LispObject difference_b_s(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_b_s(a1, a2);
}

inline LispObject difference_b_f(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_b_f(a1, a2);
}

inline LispObject difference_b_d(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_b_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject difference_b_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_b_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline LispObject difference_r_i(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = times2(a2, denominator(a1));
        errexit();
        save.restore(a1);
        a2 = difference2(numerator(a1), a2);
        errexit();
        save.restore(a1);
    }
    return make_ratio(a2, denominator(a1));
}

inline LispObject difference_r_b(LispObject a1, LispObject a2)
{   return difference_r_i(a1, a2);
}

inline LispObject difference_r_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_r_r(a1, a2);
}

inline LispObject difference_r_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_r_c(a1, a2);
}

inline LispObject difference_r_s(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_r_s(a1, a2);
}

inline LispObject difference_r_f(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_r_f(a1, a2);
}

inline LispObject difference_r_d(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_r_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject difference_r_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_r_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline LispObject difference_c_i(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = make_lisp_integer64(-int_of_fixnum(a2));
        errexit();
        save.restore(a1);
    }
    return plus_c_i(a1, a2);
}

inline LispObject difference_c_b(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negateb(a2);
        errexit();
        save.restore(a1);
    }
    return plus_c_b(a1, a2);
}

inline LispObject difference_c_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_c_r(a1, a2);
}

inline LispObject difference_c_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_c_c(a1, a2);
}

inline LispObject difference_c_s(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_c_s(a1, a2);
}

inline LispObject difference_c_f(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_c_f(a1, a2);
}

inline LispObject difference_c_d(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_c_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject difference_c_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_c_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline LispObject difference_s_i(LispObject a1, LispObject a2)
{   double d = value_of_immediate_float(a1) - static_cast<double>
               (int_of_fixnum(a2));
    return pack_immediate_float(d, a1);
}

inline LispObject difference_s_b(LispObject a1, LispObject a2)
{   int x;
    double a2d = bignum_to_float(a2, length_of_header(numhdr(a2)), &x);
    double d = value_of_immediate_float(a1) - std::ldexp(a2d, x);
    return pack_immediate_float(d, a1);
}

inline LispObject difference_s_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_s_r(a1, a2);
}

inline LispObject difference_s_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_s_c(a1, a2);
}

inline LispObject difference_s_s(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_s_s(a1, a2);
}

inline LispObject difference_s_f(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_s_f(a1, a2);
}

inline LispObject difference_s_d(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_s_d(a1, a2);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject difference_s_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_s_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline LispObject difference_f_i(LispObject a1, LispObject a2)
{   double d = single_float_val(a1) - static_cast<double>
               (int_of_fixnum(a2));
    return make_boxfloat(d, TYPE_SINGLE_FLOAT);
}

inline LispObject difference_f_b(LispObject a1, LispObject a2)
{   int x;
    double a2d = bignum_to_float(a2, length_of_header(numhdr(a2)), &x);
    double d = single_float_val(a1) - std::ldexp(a2d, x);
    return make_boxfloat(d, TYPE_SINGLE_FLOAT);
}

inline LispObject difference_f_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_f_r(a1, a2);
}

inline LispObject difference_f_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_f_c(a1, a2);
}

inline LispObject difference_f_s(LispObject a1, LispObject a2)
{   double d = single_float_val(a1) - value_of_immediate_float(a2);
    return make_boxfloat(d, TYPE_SINGLE_FLOAT);
}

inline LispObject difference_f_f(LispObject a1, LispObject a2)
{   double d = single_float_val(a1) - single_float_val(a2);
    return make_boxfloat(d, TYPE_SINGLE_FLOAT);
}

inline LispObject difference_f_d(LispObject a1, LispObject a2)
{   double d = single_float_val(a1) - single_float_val(a2);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject difference_f_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_f_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

inline LispObject difference_d_i(LispObject a1, LispObject a2)
{   double d = double_float_val(a1) - static_cast<double>
               (int_of_fixnum(a2));
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

inline LispObject difference_d_b(LispObject a1, LispObject a2)
{   int x;
    double a2d = bignum_to_float(a2, length_of_header(numhdr(a2)), &x);
    double d = double_float_val(a1) - std::ldexp(a2d, x);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

inline LispObject difference_d_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_d_r(a1, a2);
}

inline LispObject difference_d_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_d_c(a1, a2);
}

inline LispObject difference_d_s(LispObject a1, LispObject a2)
{   double d = double_float_val(a1) - value_of_immediate_float(a2);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

inline LispObject difference_d_f(LispObject a1, LispObject a2)
{   double d = double_float_val(a1) - single_float_val(a2);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

inline LispObject difference_d_d(LispObject a1, LispObject a2)
{   double d = double_float_val(a1) - double_float_val(a2);
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
}

#ifdef HAVE_SOFTFLOAT
inline LispObject difference_d_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_d_l(a1, a2);
}

inline LispObject difference_l_i(LispObject a1, LispObject a2)
{   float128_t x, z;
    i64_to_f128M((int64_t)int_of_fixnum(a2), &x);
    f128M_sub(reinterpret_cast<float128_t *>(long_float_addr(a1)), &x, &z);
    return make_boxfloat128(z);
}

inline LispObject difference_l_b(LispObject a1, LispObject a2)
{   float128_t x, z;
    x = float128_of_number(a2);
    f128M_sub(reinterpret_cast<float128_t *>(long_float_addr(a2)), &x, &z);
    return make_boxfloat128(z);
}

inline LispObject difference_l_r(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_l_r(a1, a2);
}

inline LispObject difference_l_c(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_l_c(a1, a2);
}

inline LispObject difference_l_s(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_l_s(a1, a2);
}

inline LispObject difference_l_f(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_l_f(a1, a2);
}

inline LispObject difference_l_d(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_l_d(a1, a2);
}

inline LispObject difference_l_l(LispObject a1, LispObject a2)
{   {   Save save(a1);
        a2 = negate(a2);
        errexit();
        save.restore(a1);
    }
    return plus_l_l(a1, a2);
}
#endif // HAVE_SOFTFLOAT

//
// and now for the dispatch code...
//

arith_dispatch_2(inline, LispObject, difference)

LispObject difference2(LispObject a, LispObject b)
{
#ifdef DEBUG
    validate_number("Arg1 for difference", a, a, b);
    errexit();
    validate_number("Arg2 for difference", b, a, b);
    errexit();
    LispObject r = difference(a, b);
    errexit();
    validate_number("result for difference", r, a, b);
    errexit();
    return r;
#else
    return difference(a, b);
#endif
}




// Increment a number.  Short cut when the number is a fixnum, otherwise
// just hand over to the general addition code.

LispObject add1(LispObject p)
{   if (is_fixnum(p))
    {   if (p == MOST_POSITIVE_FIXNUM) // ONLY possible overflow case here
            return make_lisp_integerptr(1+MOST_POSITIVE_FIXVAL);
        else return static_cast<LispObject>(p + 0x10);
    }
    else return plus2(p, fixnum_of_int(1));
}

// Decrement a number.  Short cut when the number is a fixnum, otherwise
// just hand over to the general addition code.

LispObject sub1(LispObject p)
{   if (is_fixnum(p))
    {   if (p == MOST_NEGATIVE_FIXNUM)
            return make_lisp_integerptr(MOST_NEGATIVE_FIXVAL - 1);
        else return static_cast<LispObject>(p - 0x10);
    }
    else return plus2(p, fixnum_of_int(-1));
}

// end of arith01.cpp
