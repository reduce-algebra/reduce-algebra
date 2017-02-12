//  arith01.cpp                           Copyright (C) 1990-2017 Codemist

//
// Arithmetic functions.
//        Addition of generic numbers
//        and in particular a lot of bignum support.
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
    {   trace_printf("%s: number with no digits (%.8x)\n", s, numhdr(a));
        prin_to_trace(b), trace_printf("\n");
        prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
        Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        aerror1("validate-number", a);
#endif
    }
    if (la == 0)
    {   if (SIXTY_FOUR_BIT)
        {   trace_printf("One word bignum invalid on 64-bit platform\n");
            prin_to_trace(a), trace_printf("\n");
            prin_to_trace(b), trace_printf("\n");
            prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
            Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
            aerror1("validate-number", a);
#endif
        }
        else
        {   msd = bignum_digits(a)[0];
            if (valid_as_fixnum(msd))
            {   trace_printf("%s: %.8x should be fixnum\n", s, msd);
                prin_to_trace(b), trace_printf("\n");
                prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
                Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
                aerror1("validate-number", a);
#endif
            }
            if (signed_overflow(msd))
            {   trace_printf("%s: %.8x should be two-word\n", s, msd);
                prin_to_trace(b), trace_printf("\n");
                prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
                Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
                aerror1("validate-number", a);
#endif
            }
            return a;
        }
    }
    if (SIXTY_FOUR_BIT && la == 1)
    {   int64_t v = ASL64(bignum_digits64(a, 1), 31) | bignum_digits(a)[0];
        if (valid_as_fixnum(v))
        {   trace_printf("%s: %#" PRIx64 " should be fixnum\n", s, v);
            prin_to_trace(b), trace_printf("\n");
            prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
            Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
            aerror1("validate-number", a);
#endif
        }
    }
    msd = bignum_digits(a)[la];
    if (signed_overflow(msd))
    {   trace_printf("%s: %.8x should be longer\n", s, msd);
        prin_to_trace(b), trace_printf("\n");
        prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
        Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        aerror1("validate-number", a);
#endif
    }
    if (msd == 0 && ((nsd = bignum_digits(a)[la-1]) & 0x40000000) == 0)
    {   trace_printf("%s: 0: %.8x should be shorter\n", s, nsd);
        prin_to_trace(b), trace_printf("\n");
        prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
        Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        aerror1("validate-number", a);
#endif
    }
    else if (msd == -1 && ((nsd = bignum_digits(a)[la-1]) & 0x40000000) != 0)
    {   trace_printf("%s: -1: %.8x should be shorter\n", s, nsd);
        prin_to_trace(b), trace_printf("\n");
        prin_to_trace(c), trace_printf("\n");
#ifdef VALIDATE_STOPS
        Lstop(nil, fixnum_of_int(1)); // System error, so stop.
#else
        aerror1("validate-number", a);
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
        return make_two_word_bignum((int32_t)ASR(n, 31),
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

#ifdef HAVE_INT128_T

LispObject make_lisp_integer128_fn(int128_t r)
{
// The result will be a bignum using 2, 3 or 4 digits.
    if (r < (int128_t)INT64_C(0x2000000000000000) &&
        r >= (int128_t)-INT64_C(0x2000000000000000))
        return make_two_word_bignum((int32_t)ASR(r, 31),
                                    (uint32_t)(r & 0x7fffffff));
// I will split off the high and low 62-bit chunks...
    uint64_t lo = (uint64_t)(r & INT64_C(0x3fffffffffffffffU));
    int64_t hi = (int64_t)ASR(r, 62);
    if (hi < INT64_C(0x40000000) &&
        hi >= -INT64_C(0x40000000))
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

#endif // HAVE_INT128_T

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
    bignum_digits(big_fake2)[1] = (int32_t)ASR(n, 31);
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
{   LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4);
// This happens to be the (alphabetically by file-name) first place where
// I am removing an "errexit()" test, so let me attach some commentary.
// If anything goes wrong within the getvector() above (or indeed some things
// could go right but potentially go a Lisp go, return-from, throw, quit
// restart etc!) either a longjmp or a throw will cause me to exit abruptly
// from the call to getvector. because I am not doing any setjmp or catch here
// the rest of this function will be abandoned and control will go back to
// or through whoever called me. When that happens things that might have
// been pushed onto the stack can be left with in a way that is no longer
// useful. But any CATCH block will arrange to reset the stack pointer
// properly and so recovers from that. The overall effect is that the code
// I have *HERE* just does not need to worry about exceptional exits, and
// so it is way tidier than it used to be.
// Some places where I do mind will pick up the strain.
    bignum_digits(w)[0] = n;
    if (SIXTY_FOUR_BIT) bignum_digits(w)[1] = 0;  // padding
    return w;
}

LispObject make_two_word_bignum(int32_t a1, uint32_t a0)
//
// This make a 2-word bignum from the 2-word value (a1,a0), where it
// must have been arranged already that a1 and a0 are correctly
// normalized to put in the two words as indicated.
//
{   LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+8);
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    if (!SIXTY_FOUR_BIT) bignum_digits(w)[2] = 0;
    return w;
}

LispObject make_three_word_bignum(int32_t a2, uint32_t a1, uint32_t a0)
//
// This make a 3-word bignum from the 3-word value (a2,a1,a0), where it
// must have been arranged already that the values are correctly
// normalized.
//
{   LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+12);
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    bignum_digits(w)[2] = a2;
    if (SIXTY_FOUR_BIT) bignum_digits(w)[3] = 0;
    return w;
}

LispObject make_four_word_bignum(int32_t a3, uint32_t a2,
                                 uint32_t a1, uint32_t a0)
//
// This make a 4-word bignum from the 4-word value (a3,a2,a1,a0), where it
// must have been arranged already that the values are correctly
// normalized.
//
{   LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+16);
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    bignum_digits(w)[2] = a2;
    bignum_digits(w)[3] = a3;
    if (!SIXTY_FOUR_BIT) bignum_digits(w)[4] = 0;
    return w;
}

LispObject make_sfloat(double d)
//
// Turn a regular floating point value into a Lisp "short float", which
// is an immediate object obtained by using the bottom 4 bits of a 32-bit
// word as tag, and the rest as just whatever would stand for a regular
// single precision value.  In doing the conversion here I ignore
// rounding etc - short floats are to save heap turn-over, but will
// not give robust numeric results.
//
{
#ifndef SHORT_FLOAT
// SFLOAT is (perhaps temporarily?) not supported in the experimental branch.
// This can be reinstated soon...
    return fixnum_of_int(0);
#else
    Float_union w;
    w.f = (float)d;
    if (trap_floating_overflow &&
        floating_edge_case(w.f))
    {   floating_clear_flags();
        aerror("exception with short float");
    }
    return (w.i & ~(int32_t)0xf) + XTAG_SFLOAT;
#endif
}

LispObject make_boxfloat(double a, int32_t type)
//
// Make a boxed float (single, double according to the type specifier)
// if type==0 this makes a short float.
// 128-bit floats must be made using make_boxfloat128.
//
{   LispObject r;
    switch (type)
    {   case 0:
        {
#ifndef SHORT_FLOAT
            return fixnum_of_int(0);
#else
            Float_union aa;
            aa.f = (float)a;
            if (trap_floating_overflow &&
                floating_edge_case(aa.f))
            {   floating_clear_flags();
                aerror("exception with short float");
            }
            return (aa.i & ~(intptr_t)0xf) + XTAG_SFLOAT;
#endif
        }
        case TYPE_SINGLE_FLOAT:
            r = getvector(TAG_BOXFLOAT, TYPE_SINGLE_FLOAT, sizeof(Single_Float));
            single_float_val(r) = (float)a;
            if (trap_floating_overflow &&
                floating_edge_case(single_float_val(r)))
            {   floating_clear_flags();
                aerror("exception with single float");
            }
            return r;
        default: // TYPE_DOUBLE_FLOAT I hope
            r = getvector(TAG_BOXFLOAT, TYPE_DOUBLE_FLOAT, SIZEOF_DOUBLE_FLOAT);
            if (!SIXTY_FOUR_BIT) double_float_pad(r) = 0;
            double_float_val(r) = a;
            if (trap_floating_overflow &&
                floating_edge_case(double_float_val(r)))
            {   floating_clear_flags();
                aerror("exception with double float");
            }
            return r;
    }
}

LispObject make_boxfloat128(float128_t a)
{   LispObject r;
    r = getvector(TAG_BOXFLOAT, TYPE_LONG_FLOAT, SIZEOF_LONG_FLOAT);
    if (!SIXTY_FOUR_BIT) long_float_pad(r) = 0;
    long_float_val(r) = a;
    if (trap_floating_overflow &&
        floating_edge_case128(&long_float_val(r)))
        aerror("exception with long float");
    return r;
}

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
    int x = 31*(int)n;
    int32_t msd = (int32_t)bignum_digits(v)[n];
// NB signed conversion on next line
    double r = (double)msd;
// If I have a one-word bignum then there is no messing around needed and the
// number will be converted to floating point without any rounding.
    if (n != 0)
    {   if (n == 1)
        {   r = TWO_31*r + (double)bignum_digits(v)[--n];
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
                r = TWO_31*r + (double)bignum_digits(v)[--n];
                x -= 31;
// Now I need to combine in lower order bits
                lo = bignum_digits(v)[--n];
                while (n > 0)
                {   if (bignum_digits(v)[--n] != 0) lo |= 1;
                }
// The bottom bit of lo will be well below the bits that contribute
// directly to the result, but by ORing in 1 there if any lower word is
// non-zero I will force rounding up in some cases where it is needed.
                r = TWO_31*r + (double)lo;
                x -= 31;
            }
            else
            {
// Here the top digit is reasonably large, so I will combine it with the
// top 15 bits from the second highest digit. That will give me a value
// using between 31 and 46 bits. This can be computed without rounding.
                int32_t mid = bignum_digits(v)[--n];
                r = 32768.0*r + (double)(mid >> 16);
                x -= 15;
                lo = bignum_digits(v)[--n];
                mid = ((mid & 0xffff) << 15) | (lo >> 16);
                if ((lo & 0xffff) != 0) mid |= 1;
                while (n > 0)
                {   if (bignum_digits(v)[--n] != 0) mid |= 1;
                }
                r = TWO_31*r + (double)mid;
                x -= 31;
            }
        }
    }
    *xp = x;
    return r;
}

#ifdef LITTLEENDIAN
static float128_t f128_TWO_31 = {{0, INT64_C(0x401e000000000000)}};
#else
statuc float128_t f128_TWO_31 = {{INT64_C(0x401e000000000000), 0}};
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
    int x = 31*(int)n;
    int32_t msd = (int32_t)bignum_digits(v)[n];
// NB signed conversion on next line
    float128_t r, w1, w2;
    i32_to_f128M(msd, &r);
    switch (n)
    {
        default:        // for very big numbers combine in 5 digits
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

double float_of_number(LispObject a)
//
// Return a (double precision) floating point value for the given Lisp
// number, or 0.0 in case of trouble.  This is often called in circumstances
// where I already know the type of its argument and so its type-dispatch
// is unnecessary - in doing so I am trading off performance against
// code repetition. Be aware that for long floats I will need to do something
// different!
//
{   if (is_fixnum(a)) return (double)int_of_fixnum(a);
#ifdef SHORT_FLOAT
    else if (is_sfloat(a))
    {   Float_union w;
        w.i = a - XTAG_SFLOAT;
        return (double)w.f;
    }
#endif
    else if (is_bfloat(a))
    {   int32_t h = type_of_header(flthdr(a));
        switch (h)
        {   case TYPE_SINGLE_FLOAT:
                return (double)single_float_val(a);
            case TYPE_DOUBLE_FLOAT:
                return double_float_val(a);
            case TYPE_LONG_FLOAT:
                {   float128_t w = long_float_val(a);
                    union { float64_t sf; double f; } f;
                    f.sf = f128M_to_f64(&w);
                    return f.f;
                }
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
                return ldexp(r1, x1);
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
                return ldexp(r1, x1 - x2);
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
#ifdef SHORT_FLOAT
    else if (is_sfloat(a))
    {   Float_union w;
        w.i = a - XTAG_SFLOAT;
        f32_to_f128M(w.f32, &r);
        return r;
    }
#endif
    else if (is_bfloat(a))
    {   int32_t h = type_of_header(flthdr(a));
        switch (h)
        {   case TYPE_SINGLE_FLOAT:
                r32 = float32_t_val(a);
                f32_to_f128M(r32, &r);
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

int32_t thirty_two_bits(LispObject a)
//
// return a 32 bit integer value for the Lisp integer (fixnum or bignum)
// passed down - ignore any higher order bits and return 0 if the arg was
// floating, rational etc or not a number at all.  Only really wanted where
// links between C-specific code (that might really want 32-bit values)
// and Lisp are being coded.
//
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            return (int32_t)int_of_fixnum(a);
        case TAG_NUMBERS:
            if (is_bignum(a))
            {   size_t len = bignum_length(a);
//
// Note that I keep 31 bits per word and use a 2s complement representation.
// thus if I have a one-word bignum I just want its contents but in all
// other cases I need just one bit from the next word up.
// The left shift by 31-bits is OK because it is on an unsigned value.
                if (len == CELL+4) return bignum_digits(a)[0]; // One word bignum
                return bignum_digits(a)[0] | (bignum_digits(a)[1] << 31);
            }
        // else drop through
        case TAG_BOXFLOAT:
        default:
//
// return 0 for all non-fixnums
//
            return 0;
    }
}

int64_t sixty_four_bits(LispObject a)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            return (int64_t)int_of_fixnum(a);
        case TAG_NUMBERS:
            if (is_bignum(a))
            {   int len = bignum_length(a);
                switch (len)
                {   case CELL+4:
// One word bignum. Do a double cast to stress how sign extension is needed.
                        return (int64_t)(int32_t)bignum_digits(a)[0];
                    case CELL+8:
                        return bignum_digits(a)[0] |
                               ASL64(bignum_digits64(a, 1), 31);
                    default:
                        return bignum_digits(a)[0] |
                               ((uint64_t)bignum_digits(a)[1] << 31) |
                               ASL64(bignum_digits64(a, 2), 62);
                }
            }
        // else drop through
        case TAG_BOXFLOAT:
        default:
//
// return 0 for all non-fixnums
//
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
    stackcheck2(0, r, i);
    push2(r, i);
    v = getvector(TAG_NUMBERS, TYPE_COMPLEX_NUM, sizeof(Complex_Number));
//
// The vector r has uninitialized contents here - dodgy.  If the call
// to getvector succeeded then I fill it in, otherwise I will not
// refer to it again, and I think that unreferenced vectors containing junk
// are OK.
//
    pop2(i, r);
    real_part(v) = r;
    imag_part(v) = i;
    return v;
}

LispObject make_ratio(LispObject p, LispObject q)
//
// By the time this is called (p/q) must be in its lowest terms, q>0
//
{   LispObject v;
    if (q == fixnum_of_int(1)) return p;
    stackcheck2(0, p, q);
    push2(p, q);
    v = getvector(TAG_NUMBERS, TYPE_RATNUM, sizeof(Rational_Number));
    pop2(q, p);
    numerator(v) = p;
    denominator(v) = q;
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

static LispObject plusis(LispObject a, LispObject b)
{
#ifndef SHORT_FLOAT
    return fixnum_of_int(0);
#else
    Float_union bb;
    bb.i = b - XTAG_SFLOAT;
    bb.f = (float)((double)int_of_fixnum(a) + bb.f);
    return (bb.i & ~(int32_t)0xf) + XTAG_SFLOAT;
#endif
}

//
// Bignums are represented as vectors where the most significant 32-bit
// digit is treated as signed, and the remaining ones are unsigned.
//

static LispObject plusib(LispObject a, LispObject b)
//
// Add a fixnum to a bignum, returning a result as a fixnum or bignum
// depending on its size.  This seems much nastier than one would have
// hoped. Well all in all a LOT of the arithmetic ends up being way messier
// that an idealist would have expected. This is perhaps related to there
// being potential transition cases when input or output values are around
// 27, 30, 59, 61, 92, ... bits wide.
//
{   size_t len = bignum_length(b)-CELL, i;
    intptr_t s1 = int_of_fixnum(a); // BEWARE - may be bigger than a digit.
    LispObject c;
    len = len/4;         // This is always 4 because even on a 64-bit
                         // machine where CELL=8 I use 4-byte B-digits
// If you are on a 64-bit machine it should NEVER be possible to end up
// with a 1-word bignum, because the relevant range always fits within
// a fixnum. The test on SIXTY_FOUR_BIT here should end up letting a reasonably
// clever compiler omit the code that covers this case.
    if (!SIXTY_FOUR_BIT && len == 1)
    {   int32_t s;
//
// Partly because it will be a common case and partly because it has
// various special cases I have special purpose code to cope with
// adding a fixnum to a one-word bignum. This only happens if we are
// on a 32-bit machine and hence the fixnum is at worst 28-bits wide.
//
        s = (int32_t)bignum_digits(b)[0] + (int32_t)s1;
// top_bit_set looks at 32-bit values...
        if (signed_overflow(s))  // needs to turn into two-word bignum
        {   if (s < 0) return make_two_word_bignum(-1, clear_top_bit(s));
            else return make_two_word_bignum(0, s);
        }
        if (valid_as_fixnum(s)) return fixnum_of_int(s);
        // here the result is a one-word bignum
        else return make_one_word_bignum(s);
    }
//
// Now, after all the silly cases have been handled, I have a calculation
// which seems set to give a multi-word result. On a 64-bit machine one can
// have (say) a positive two-word bignum and add a negative fixnum
// yielding a fixnum result. On a 32-bit machine that behaviour is not
// possible - the smallest value result will still be at least a 1-word
// bignum.
//
// So let me write out the 2-word case longhand in the 64-bit case...
    if (len == 2)
    {   int64_t s = (ASL64(bignum_digits64(b,1),31) | bignum_digits(b)[0]) +
                    (int64_t)s1;
// a 2-word bignum has at worst 62 bits and a fixnum 28 or 60, so their
// sum can not overflow a 64-bit word.
        return make_lisp_integer64(s);
    }
// b now has at least 3 digits.
    push(b);
    c = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*len);
    pop(b);
// Add in the lowest bit by hand
    int32_t d0 = bignum_digits(b)[0] + clear_top_bit(s1);
    bignum_digits(c)[0] = clear_top_bit(d0);
    s1 = s1>>31;
    if (top_bit_set(d0)) s1 = s1 + 1;
// Now s1 is at most 29 bits... I can treat it as a carry from the
// previous digit. Note that it may be either positive or negative
    for (i=1; i<len-1; i++)
    {   int32_t s = bignum_digits(b)[i] + (s1 & 0x7fffffff);
        s1 = s1 >> 31; // Note that s1 was signed so this is -1, 0 or 1
        bignum_digits(c)[i] = s & 0x7fffffff;
        s1 += top_bit(s);
    }
    s1 = s1 + (int32_t)bignum_digits(b)[i];
    if (!signed_overflow(s1))         // did it overflow?
    {
//
// Here the most significant digit did not produce an overflow, but maybe
// what we actually had was some cancellation and the MSD is now zero
// or -1, so that the number should shrink...
//
        if ((s1 == 0 && (bignum_digits(c)[i-1] & 0x40000000) == 0) ||
            (s1 == -1 && (bignum_digits(c)[i-1] & 0x40000000) != 0))
        {   // shrink the number
            numhdr(c) -= pack_hdrlength(1L);
            if (s1 == -1) bignum_digits(c)[i-1] |= 0x80000000;
//
// Now sometimes the shrinkage will leave a padding word, sometimes it
// will really allow me to save space. As a jolly joke with a 64-bit
// system I need padding if there have been an odd number of (32-bit)
// words of bignum data while with a 32-bit system the header word is
// 32-bits wide and I need padding if there are ar even number of additional
// data words.
//
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
// scheme I believe there will never be any linear scanning of active
// heap apart from the code that dumps out profile counts - and I may be able
// to rework those so that they identify the symbols that contain counts in
// some other way. So once I have reworked "mapstore" I can drop the
// messing around here that fills in little gaps left over when big numbers
// shrink. That will feel good.
//
            *(Header *)&bignum_digits(c)[i] = make_bighdr(2L);
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
        numhdr(c) += pack_hdrlength(1L);
        return c;
    }
    push(c);
    b = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4+4*len);
    pop(c);
    for (i=0; i<len-1; i++)
        bignum_digits(b)[i] = bignum_digits(c)[i];
//
// I move the top digit across by hand since if the number is negative
// I must lose its top bit
//
    bignum_digits(b)[i++] = clear_top_bit(s1);
// Now the one-word extension to the number
    bignum_digits(b)[i++] = top_bit_set(s1) ? -1 : 0;
//
// Finally because I know that I expanded into a new doubleword I should
// tidy up the second word of the newly allocated pair. I know I added two
// extra words because if I was just filling in the second of two existing
// words I did not do not do the fresh getvector() here...
//
    bignum_digits(b)[i] = 0;
    return b;
}

static LispObject plusir(LispObject a, LispObject b)
//
// fixnum and ratio, but also valid for bignum and ratio.
// Note that if the inputs were in lowest terms there is no need for
// and GCD calculations here.
//
{   push(b);
    a = times2(a, denominator(b));
    a = plus2(a, numerator(stack[0]));
    pop(b);
    return make_ratio(a, denominator(b));
}

static LispObject plusic(LispObject a, LispObject b)
//
// real of any sort plus complex.
//
{   push(b);
    a = plus2(a, real_part(b));
    pop(b);
//
// make_complex() takes responsibility for mapping #C(n 0) onto n
//
    return make_complex(a, imag_part(b));
}

static LispObject plusif(LispObject a, LispObject b)
//
// Fixnum plus boxed-float.
//
{   double d = (double)int_of_fixnum(a) + float_of_number(b);
// The test here is redundant because make_boxfloat would also check for
// infinity and NaN. However I test here because in the common case of
// double floats (ie the default) it lets the diagnostic tell me that I
// was doing PLUS rather than any other operation.
    if (trap_floating_overflow &&
        floating_edge_case(d))
    {   floating_clear_flags();
        aerror("floating point plus");
    }
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

#define plussi(a, b) plusis(b, a)

#define plussb(a, b) plusbs(b, a)

#define plussr(a, b) plusrs(b, a)

#define plussc(a, b) plusic(a, b)

static LispObject plussf(LispObject a, LispObject b)
//
// This can be used for any rational value plus a boxed-float. plusif()
// is separated just for (minor) efficiency reasons.
//
{   double d = float_of_number(a) + float_of_number(b);
    if (trap_floating_overflow &&
        floating_edge_case(d))
    {   floating_clear_flags();
        aerror("floating point plus");
    }
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

#define plusbi(a, b) plusib(b, a)

static LispObject plusbs(LispObject a, LispObject b)
{   double d = float_of_number(a) + float_of_number(b);
    return make_sfloat(d);
}

LispObject lengthen_by_one_bit(LispObject a, int32_t msd)
//
// (a) is a bignum, and arithmetic on it has (just) caused overflow
// in its top word - I just need to stick on another word. (msd) is the
// current top word, and its sign will be used to decide on the value
// that must be appended.
//
{   int32_t len = bignum_length(a);
//
// Sometimes I need to allocate a new vector and copy data across into it
//
    if ((len & 4) == 0)
    {   LispObject b;
        int32_t i;
        push(a);
        b = getvector(TAG_NUMBERS, TYPE_BIGNUM, len+4);
        pop(a);
        len = (len-CELL)/4;
        for (i=0; i<len; i++)
            bignum_digits(b)[i] = clear_top_bit(bignum_digits(a)[i]);
        bignum_digits(b)[len] = top_bit_set(msd) ? -1 : 0;
        bignum_digits(b)[len+1] = 0;
        return b;
    }
    else
//
// .. whereas sometimes I have a spare word already available.
//
    {   numhdr(a) += pack_hdrlength(1L);
        len = (len-CELL)/4;
        bignum_digits(a)[len-1] = clear_top_bit(bignum_digits(a)[len-1]);
        bignum_digits(a)[len] = top_bit_set(msd) ? -1 : 0;
        return a;
    }
}

static LispObject plusbb(LispObject a, LispObject b)
//
// add two bignums.
//
{   int32_t la = bignum_length(a),
            lb = bignum_length(b),
            i, s, carry;
    LispObject c;
    if (la < lb)    // maybe swap order of args
    {   LispObject t = a;
        int32_t t1;
        a = b; b = t;
        t1 = la; la = lb; lb = t1;
    }
//
// now (a) is AT LEAST as long as b.  I have special case code for
// when both args are single-word bignums, since I expect that to be
// an especially common case on 32-bit machines.
//
    if (!SIXTY_FOUR_BIT && la == CELL+4) // and hence b also has only 1 digit
    {   int32_t vc = bignum_digits(a)[0] + bignum_digits(b)[0];
// Because the digits are only 31-bits wide I do not get overflow when I add
// them in a 32-bit integer.
        return make_lisp_integer32(vc);
    }
    if (la == CELL+8)
    {   int64_t va = ASL64(bignum_digits64(a, 1), 31) | bignum_digits(a)[0];
        int64_t vb = (!SIXTY_FOUR_BIT && lb == CELL+4) ?
                     bignum_digits64(b, 0) :
                     ASL64(bignum_digits64(b, 1), 31) | bignum_digits(b)[0];
        return make_lisp_integer64(va + vb);
    }
// Now at least one operand uses 3 words... I will do a general bignum add
// which may sometimes be overkill, but ought to be safe.
    push2(a, b);
    c = getvector(TAG_NUMBERS, TYPE_BIGNUM, la);
    pop2(b, a);
    la = (la-CELL)/4 - 1;
    lb = (lb-CELL)/4 - 1;
    carry = 0;
//
// Add all but the top digit of b
//
    for (i=0; i<lb; i++)
    {   carry = bignum_digits(a)[i] + bignum_digits(b)[i] + top_bit(carry);
        bignum_digits(c)[i] = clear_top_bit(carry);
    }
    if (la == lb) s = bignum_digits(b)[i];
    else
//
// If a is strictly longer than b I sign extend b here and add in as many
// copies of 0 or -1 as needbe to get up to the length of a.
//
    {   s = bignum_digits(b)[i];
        carry =  bignum_digits(a)[i] + clear_top_bit(s) + top_bit(carry);
        bignum_digits(c)[i] = clear_top_bit(carry);
        if (s < 0) s = -1; else s = 0;
        for (i++; i<la; i++)
        {   carry = bignum_digits(a)[i] + clear_top_bit(s) + top_bit(carry);
            bignum_digits(c)[i] = clear_top_bit(carry);
        }
    }
//
// the most significant digit is added using signed arithmetic so that I
// can tell if it overflowed.
//
    carry = bignum_digits(a)[i] + s + top_bit(carry);
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
        {   int32_t j = i-1;
            while ((msd = bignum_digits(c)[j]) == 0 && j > 0) j--;
            if (SIXTY_FOUR_BIT && j == 1)
            {   int64_t s = ASL64(bignum_digits64(c,1), 31) |
                            bignum_digits(c)[0];
                if (valid_as_fixnum(s)) return fixnum_of_int(s);
            }
            else if (j == 0)
            {   int32_t s = bignum_digits(c)[0];
                if (valid_as_fixnum(s)) return fixnum_of_int(s);
            }
//
// ... but I may need a zero word on the front if the next word down
// has its top bit set... (top of 31 bits, that is)
//
            if ((msd & 0x40000000) != 0)
            {   j++;
                if (i == j) return c;
            }
//
// If I am shrinking by one word and had an even length to start with
// I do not have to mess about so much.
//
            if ((SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) != 0)) ||
                (!SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) == 0)))
            {   numhdr(c) -= pack_hdrlength(1L);
                return c;
            }
            numhdr(c) -= pack_hdrlength(i - j);
            if (SIXTY_FOUR_BIT)
            {   i = (i+2) & ~1;
                j = (j+2) & ~1;     // Round up to odd index
            }
            else
            {   i = (i+1) | 1;
                j = (j+1) | 1;     // Round up to odd index
            }
//
// I forge a header word to allow the garbage collector to skip over
// (and in due course reclaim) the space that turned out not to be needed.
//
            if (i != j) *(Header *)&bignum_digits(c)[j] = make_bighdr(i - j);
            return c;
        }
//
// Now do all the same sorts of things but this time for negative numbers.
//
        else if (carry == -1)
        {   int32_t j = i-1;
            msd = carry;    // in case j = 0
            while ((msd = bignum_digits(c)[j]) == 0x7fffffff && j > 0) j--;
            if (SIXTY_FOUR_BIT && j == 1)
            {   int64_t s = ASL64(bignum_digits64(c,1) |
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
                numhdr(c) -= pack_hdrlength(1);
                return c;
            }
            numhdr(c) -= pack_hdrlength(i - j);
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
            if (i != j) *(Header *)&bignum_digits(c)[j] = make_bighdr(i - j);
            return c;
        }
        return c;
    }
    else
    {   bignum_digits(c)[i] = carry;
        return lengthen_by_one_bit(c, carry);
    }
}

#define plusbr(a, b) plusir(a, b)

#define plusbc(a, b) plusic(a, b)

#define plusbf(a, b) plussf(a, b)

#define plusri(a, b) plusir(b, a)

#define plusrs(a, b) plusbs(a, b)

#define plusrb(a, b) plusri(a, b)

static LispObject plusrr(LispObject a, LispObject b)
//
// Adding two ratios involves some effort to keep the result in
// lowest terms.
//
{   LispObject na = numerator(a), nb = numerator(b);
    LispObject da = denominator(a), db = denominator(b);
    LispObject w = nil;
    push5(na, nb, da, db, nil);
#define g   stack[0]
#define db  stack[-1]
#define da  stack[-2]
#define nb  stack[-3]
#define na  stack[-4]
    g = gcd(da, db);
//
// all the calls to quot2() in this procedure are expected - nay required -
// to give exact integer quotients.
//
    db = quot2(db, g);
    g = quot2(da, g);
    na = times2(na, db);
    nb = times2(nb, g);
    na = plus2(na, nb);
    da = times2(da, db);
    g = gcd(na, da);
    na = quot2(na, g);
    da = quot2(da, g);
    w = make_ratio(na, da);
    popv(5);
    return w;
#undef na
#undef nb
#undef da
#undef db
#undef g
}

#define plusrc(a, b) plusic(a, b)

#define plusrf(a, b) plussf(a, b)

#define plusci(a, b) plusic(b, a)

#define pluscs(a, b) plussc(b, a)

#define pluscb(a, b) plusbc(b, a)

#define pluscr(a, b) plusrc(b, a)

static LispObject pluscc(LispObject a, LispObject b)
//
// Add complex values.
//
{   LispObject c;
    push2(a, b);
    c = plus2(imag_part(a), imag_part(b));
    pop2(b, a);
    a = plus2(real_part(a), real_part(b));
    return make_complex(a, c);
}

#define pluscf(a, b) plusfc(b, a)

#define plusfi(a, b) plusif(b, a)

#define plusfs(a, b) plussf(b, a)

#define plusfb(a, b) plusbf(b, a)

#define plusfr(a, b) plusrf(b, a)

#define plusfc(a, b) plusic(a, b)

static LispObject plusff(LispObject a, LispObject b)
//
// Add two boxed floats - the type of the result must match the
// longer of the types of the arguments, hence the extra
// messing about.
//
{   int32_t ha = type_of_header(flthdr(a)), hb = type_of_header(flthdr(b));
    int32_t hc = ha;
// If EITHER argument is a long float I will need to do things differently,
// bacause I can not use machine-native arithmetic on float128_t.
    if (ha == TYPE_LONG_FLOAT || hb == TYPE_LONG_FLOAT)
    {   float128_t x, y, z;
        x = float128_of_number(a);
        y = float128_of_number(b);
        f128M_add(&x, &y, &z);
        if (trap_floating_overflow &&
            floating_edge_case128(&z))
            aerror("floating point plus");
        return make_boxfloat128(z);
    }
    else if (ha == TYPE_DOUBLE_FLOAT || hb == TYPE_DOUBLE_FLOAT)
        hc = TYPE_DOUBLE_FLOAT;
    else hc = TYPE_SINGLE_FLOAT;
    if (trap_floating_overflow &&
        floating_edge_case(a))
    {   floating_clear_flags();
        aerror("floating point plus");
    }
    return make_boxfloat(float_of_number(a) + float_of_number(b), hc);
}

//
// and now for the dispatch code...
//

LispObject plus2(LispObject a, LispObject b)
//
// I probably want to change the specification of plus2 so that the fixnum +
// fixnum case is always expected to be done before the main body of the code
// is entered.  Well maybe even if I do that it then costs very little to
// include the fixnum code here as well, so I will not delete it.
//
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum + fixnum arithmetic happens - the case I most want to
// make efficient. Note that even if this becomes a bignum it can only be a
// rather short one.
//
                {   intptr_t r = int_of_fixnum(a) + int_of_fixnum(b);
                    if (valid_as_fixnum(r)) return fixnum_of_int(r);
                    else return make_lisp_integer64(r);
                }
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return plusis(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return plusib(a, b);
                        case TYPE_RATNUM:
                            return plusir(a, b);
                        case TYPE_COMPLEX_NUM:
                            return plusic(a, b);
                        default:
                            aerror1("bad arg for plus", b);
                    }
                }
                case TAG_BOXFLOAT:
                    return plusif(a, b);
                default:
                    aerror1("bad arg for plus",  b);
            }
#ifdef SHORT_FLOAT
        case XTAG_SFLOAT:
            switch (b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return plussi(a, b);
                case XTAG_SFLOAT:
                {   Float_union aa, bb;
                    aa.i = a - XTAG_SFLOAT;
                    bb.i = b - XTAG_SFLOAT;
                    aa.f = (float)(aa.f + bb.f);
                    return (aa.i & ~(int32_t)0xf) + XTAG_SFLOAT;
                }
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return plussb(a, b);
                        case TYPE_RATNUM:
                            return plussr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return plussc(a, b);
                        default:
                            aerror1("bad arg for plus",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return plussf(a, b);
                default:
                    aerror1("bad arg for plus",  b);
            }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return plusbi(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return plusbs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return plusbb(a, b);
                                case TYPE_RATNUM:
                                    return plusbr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return plusbc(a, b);
                                default:
                                    aerror1("bad arg for plus",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return plusbf(a, b);
                        default:
                            aerror1("bad arg for plus",  b);
                    }
                case TYPE_RATNUM:
                    switch (b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return plusri(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return plusrs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return plusrb(a, b);
                                case TYPE_RATNUM:
                                    return plusrr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return plusrc(a, b);
                                default:
                                    aerror1("bad arg for plus",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return plusrf(a, b);
                        default:
                            aerror1("bad arg for plus",  b);
                    }
                case TYPE_COMPLEX_NUM:
                    switch (b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return plusci(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return pluscs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return pluscb(a, b);
                                case TYPE_RATNUM:
                                    return pluscr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return pluscc(a, b);
                                default:
                                    aerror1("bad arg for plus",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return pluscf(a, b);
                        default:
                            aerror1("bad arg for plus",  b);
                    }
                default:    aerror1("bad arg for plus",  a);
            }
        }
        case TAG_BOXFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return plusfi(a, b);
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return plusfs(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return plusfb(a, b);
                        case TYPE_RATNUM:
                            return plusfr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return plusfc(a, b);
                        default:
                            aerror1("bad arg for plus",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return plusff(a, b);
                default:
                    aerror1("bad arg for plus",  b);
            }
        default:
            aerror1("bad arg for plus",  a);
    }
}

LispObject difference2(LispObject a, LispObject b)
{   switch ((int)b & TAG_BITS)
    {   case TAG_FIXNUM:
            if (is_fixnum(a))
            {   intptr_t r = int_of_fixnum(a) - int_of_fixnum(b);
                if (valid_as_fixnum(r)) return fixnum_of_int(r);
                else return make_lisp_integer64(r);
            }
            else if (b != MOST_NEGATIVE_FIXNUM)
                return plus2(a, 2*TAG_FIXNUM-b);
            else
            {   push(a);
                b = make_lisp_integerptr(-MOST_NEGATIVE_FIXVAL);
                break;
            }
        case TAG_NUMBERS:
            push(a);
            if (type_of_header(numhdr(b)) == TYPE_BIGNUM) b = negateb(b);
            else b = negate(b);
            break;
        case TAG_BOXFLOAT:
        default:
            push(a);
            b = negate(b);
            break;
    }
    pop(a);
    return plus2(a, b);
}

LispObject add1(LispObject p)
//
// Increment a number.  Short cut when the number is a fixnum, otherwise
// just hand over to the general addition code.
//
{   if (is_fixnum(p))
    {   if (p == MOST_POSITIVE_FIXNUM) // ONLY possible overflow case here
            return make_lisp_integerptr(1+MOST_POSITIVE_FIXVAL);
        else return (LispObject)(p + 0x10);
    }
    else return plus2(p, fixnum_of_int(1));
}

LispObject sub1(LispObject p)
//
// Decrement a number.  Short cut when the number is a fixnum, otherwise
// just hand over to the general addition code.
//
{   if (is_fixnum(p))
    {   if (p == MOST_NEGATIVE_FIXNUM)
            return make_lisp_integerptr(MOST_NEGATIVE_FIXVAL - 1);
        else return (LispObject)(p - 0x10);
    }
    else return plus2(p, fixnum_of_int(-1));
}

// end of arith01.cpp
