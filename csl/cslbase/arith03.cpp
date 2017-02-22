//  arith03.cpp                           Copyright (C) 1990-2017 Codemist

//
// Arithmetic functions.
//    quotient.
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
// Division
//

uint32_t Idivide(uint32_t *qp, uint32_t a, uint32_t b, uint32_t c)
//
//         *qp = (a,b) / c,  return the remainder
//
// The double-length value (a,b) is given as a 62-bit positive number.  Its
// low order 31 bits are in b, and the 0x80000000 bit of b is zero.  The
// high order part (in a) is also represented with the 0x80000000 bit zero.
// The divisor c is a positive value that is at most 0x7fffffff, and the
// procedure will only be called when the correct quotient is in the
// (inclusive) range 0 to 0x7fffffff.  The above constraints can be thought
// of in two ways: (a) Idivide used a 31-bit word and is working on
// unsigned values.  The 31-bit quantities happen to be being passed around
// in 32 bit registers, but the top bit of those registers will never be used
// and will contain zero, or (b) the range of values used is such that
// a 64 by 32-bit division can be performed, and by constraining the range
// of values this 64 by 32-bit division only has to handle positive numbers,
// but depending on the hardware of your computer you are entitled to use
// either signed or unsigned arithmetic.
//
{   uint64_t p = ((uint64_t)a << 31) | (uint64_t)b;
    if (qp != NULL) *qp = (uint32_t)(p / (uint64_t)c);
    return (uint32_t)(p % (uint64_t)c);
}

static LispObject quotis(LispObject a, LispObject b)
{
    mv_2 = fixnum_of_int(0);
#ifndef SHORT_FLOAT
    return fixnum_of_int(0);
#else
    Float_union bb;
    bb.i = b - XTAG_SFLOAT;
    if (bb.f == 0.0) aerror2("bad arg for quotient", a, b);
    bb.f = (float) ((float)int_of_fixnum(a) / bb.f);
    return (bb.i & ~(int32_t)0xf) + XTAG_SFLOAT;
#endif
}

static LispObject quotib(LispObject a, LispObject b)
{
//
// a fixnum divided by a bignum always gives 0, regardless of signs etc.,
// save in the one case of (-#x8000000)/(#x8000000) which must yield -1
// (an an analagous case in the 64-bit world...)
//
// The use of "magic numbers" here is without doubt ugly and is really not
// the way to have clear maintainable code. Apologies but in the short term
// I do not have a nicer solution to offer.
    if (a == MOST_NEGATIVE_FIXNUM &&
        ((SIXTY_FOUR_BIT && bignum_length(b) == CELL+8 &&
          bignum_digits(b)[0] == 0 &&
          bignum_digits(b)[1] == 0x10000000) ||
         (!SIXTY_FOUR_BIT && bignum_length(b) == CELL+4 &&
          bignum_digits(b)[0] == 0x08000000)))
    {   mv_2 = fixnum_of_int(0);
        return fixnum_of_int(-1);
    }
    else
    {   mv_2 = a;
        return fixnum_of_int(0);
    }
}

static LispObject CLquotib(LispObject a, LispObject b)
{   LispObject g;
    bool w;
    push2(a, b);
    w = minusp(b);
    g = gcd(stack[0], stack[-1]);
    if (w) g = negate(g);
    a = stack[-1];
    push(g);
    a = quot2(a, g);
    pop2(g, b);
    stack[0] = a;
    b = quot2(b, g);
    pop(a);
    return make_ratio(a, b);
}

// Remember that in Common Lisp there is a rendancy for QUOTIENT to
// return rational numbers...

static LispObject CLquotbi(LispObject a, LispObject b)
{   return CLquotib(a, b);
}

static LispObject CLquotbb(LispObject a, LispObject b)
{   return CLquotib(a, b);
}

static LispObject quotir(LispObject a, LispObject b)
{   LispObject w;
    mv_2 = fixnum_of_int(0);
    if (a == fixnum_of_int(0)) return a;
    push3(b, a, nil);
#define g   stack[0]
#define a   stack[-1]
#define b   stack[-2]
    g = gcd(a, numerator(b));
//
// the gcd() function guarantees to hand back a positive result.
//
    a = quot2(a, g);
    w = minusp(numerator(b));
    if (w) g = negate(g);
    g = quot2(numerator(b), g);     // denominator of result will be +ve
    a = times2(a, denominator(b));
    w = make_ratio(a, g);
    popv(3);
    return w;
#undef a
#undef b
#undef g
}

static LispObject quotic(LispObject a, LispObject b)
//
// Used for all cases of xxx/<p+iq>.  This is coded in a fairly naive
// way, multiplying both numerator and denominator of what will end up
// as the result by the complex conjugate of b.  If floating point
// arithmetic is used this can lead to grossly premature overflow.  For
// the moment I will ignore that miserable fact
//
{   LispObject u, v;
    mv_2 = fixnum_of_int(0);
    push2(a, b);
#define b stack[0]
#define a stack[-1]
//
//   a / (p + iq) is computed as follows:
//     (a * (p - iq)) / (p^2 + q^2)
//
    u = negate(imag_part(b));
    u = make_complex(real_part(b), u);
    a = times2(a, u);
    u = real_part(b);
    u = times2(u, u);
    v = imag_part(b);
    b = u;
    u = times2(v, v);
    u = plus2(u, b);
    v = a;
    popv(2);
    return quot2(v, u);
#undef a
#undef b
}

static LispObject quotif(LispObject a, LispObject b)
{   double d = float_of_number(b);
    mv_2 = fixnum_of_int(0);
    if (d == 0.0) aerror2("bad arg for quotient", a, b);
    d = (double)int_of_fixnum(a) / d;
    if (trap_floating_overflow &&
        floating_edge_case(d))
    {   floating_clear_flags();
        aerror("floating point quotient");
    }
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

static LispObject quotsi(LispObject a, LispObject b)
{
    mv_2 = fixnum_of_int(0);
#ifndef SHORT_FLOAT
    return fixnum_of_int(0);
#else
    Float_union aa;
    if (b == fixnum_of_int(0)) aerror2("bad arg for quotient", a, b);
    aa.i = a - XTAG_SFLOAT;
    aa.f = (float) (aa.f / (float)int_of_fixnum(b));
    return (aa.i & ~(int32_t)0xf) + XTAG_SFLOAT;
#endif
}

static LispObject quotsb(LispObject a, LispObject b)
{   double d = float_of_number(b);
    mv_2 = fixnum_of_int(0);
    if (d == 0.0) aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / d;
    return make_short_float(d);
}

#define quotsr(a, b) quotsb(a, b)

#define quotsc(a, b) quotic(a, b)

static LispObject quotsf(LispObject a, LispObject b)
{   double d = float_of_number(b);
    mv_2 = fixnum_of_int(0);
    if (d == 0.0) aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / d;
    if (trap_floating_overflow &&
        floating_edge_case(d))
    {   floating_clear_flags();
        aerror("floating point quotient");
    }
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

LispObject quotbn(LispObject a, int32_t n)
//
// Divide a bignum by an integer, where the integer is (by now)
// a natural C int32_t but limited to 31 not 32 bits active.  I.e.
// this can be used when dividing by a small fixnum or by dividing by
// a one-word bignum.  I will not call this with n=-1, which would
// be the one case where it could cause the quotient to be bigger
// than the dividend.  I also filter out the special easy case n=1
// before I get here. Leaves nwork set to the remainder.
// NOTE NOTE NOTE that on a 64-bit system this is not good enough
// for dividing by a general fixnum.
//
{   int sign;
    size_t lena = (bignum_length(a)-CELL)/4-1, i, lenc, lenx;
    uint32_t carry;
    if (!SIXTY_FOUR_BIT && lena == 0)   // one-word bignum as numerator
    {   int32_t p = (int32_t)bignum_digits(a)[0];
        nwork = p % n;
//
// C does not define what happens on non-exact division involving
// negative quantities, so I adjust things here so that the remainder
// has the sign that I want and the division I do is exact.
//
        if (p < 0)
        {   if (nwork > 0) nwork -= n;
        }
        else if (nwork < 0) nwork += n;
// Remainder should be correct (with correct sign) by now, regardless of
// what C had done.
        p = (p - nwork) / n;
        return make_lisp_integer32(p);
    }
    else if (lena == 1)   // two-word bignum as numerator
    {   int64_t a0 = bignum_digits64(a, 1)<<31 | bignum_digits(a)[0];
        int64_t p = a0 / n;
        nwork = a0 % n;
        if (nwork != 0 &&
            (nwork ^ a0) < 0) 
        {  if (p < 0)
           {   p++;
               nwork -= n;
           }
           else
           {   p--;
               nwork += n;
           }
        }
        return make_lisp_integer64(p);
    }
// That has dealt with the special cases - now the input is a bignum
// with at least 3 digits and the quotient will certainly be a bignum if
// you are on a 32-bit machine. On a 64-bit system the extreme case will
// be 1:00000000:0000000 (ie 2^62) divided by (-2^30) = -2^32 which is
// a fixnum, so I will need to be ready to truncate in that case. Well
// I would rather not allocate memory that I am then going to abandon, so I
// will write out the 3-word/1-word case here specially.
    if (SIXTY_FOUR_BIT && lena == 2)
    {   int32_t a2 = bignum_digits(a)[2];
        int32_t a1 = bignum_digits(a)[1];
        int32_t a0 = bignum_digits(a)[0];
        int64_t hi = (int64_t)a2<<31 | a1;
        int64_t q1 = hi/n;
        int64_t lo = (hi%n)<<31 | a0;
        int64_t q0 = lo/n;
        int32_t r0 = (int32_t)(lo%n);
// Now fix the sign of the remainder...
        if (r0 != 0 &&
            (r0 ^ a2) < 0) 
        {  if (q1 < 0)
           {   q0++;
               r0 -= n;
           }
           else
           {   q0--;
               r0 += n;
           }
        }
        nwork = r0;   // Remainder should now be OK
        q1 += q0>>31;
        q0 &= 0x7fffffff;
// Now the quotient is in (q1,q0) where q1 may be up to 61 bits, or could
// be fairly small. I need to see if the full result can be a fixnum.
        if (signed29_in_64(q1)) return fixnum_of_int(q1<<31 | q0);
        if (signed31_in_64(q1))
            return make_two_word_bignum((int32_t)q1, (uint32_t)q0);
        return make_three_word_bignum((int32_t)(q1>>31),
            (uint32_t)(q1&0x7fffffff), (uint32_t)q0);
    }
// Start by allocating a workspace copy of the dividend.  negateb will
// leave a a bignum, although it may change its length.
// I am (reasonably) happy to allocate new space here for to work in
// because it will be used as the result that I hand back.
    if ((int32_t)bignum_digits(a)[lena] < 0) a = negateb(a), sign = 3;
    else a = copyb(a), sign = 0;
    if (n < 0)
    {   sign ^= 1;
        n = -n;
    }
//
// Now both a and n have been made positive, and their original signs
// have been recorded so that I can tidy up at the end.  The 1 bit in sign
// tells me what sign the quotient will have, the 2 bit gives the sign
// for the remainder.
//
    lena = (bignum_length(a)-CELL)/4;
    carry = 0;
    for (i=lena; i>0; i--)
        Ddivide(carry, bignum_digits(a)[i-1], carry, bignum_digits(a)[i-1], n);
    if ((sign & 2) != 0) nwork = -(int32_t)carry;
    else nwork = carry;
    lena--;
    while (bignum_digits(a)[lena] == 0) lena--;
    if ((bignum_digits(a)[lena] & 0x40000000) != 0) lena++;
    if ((sign & 1) != 0)            // quotient will be negative
    {   carry = 0xffffffffU;
        for (i=0; i<lena; i++)
        {   carry = ADD32(clear_top_bit(~bignum_digits(a)[i]), top_bit(carry));
            bignum_digits(a)[i] = clear_top_bit(carry);
        }
        carry = ADD32(~bignum_digits(a)[i], top_bit(carry));
        if (carry == 0xffffffffU && (bignum_digits(a)[i-1] & 0x40000000) != 0)
        {   bignum_digits(a)[lena] = 0;
            lena--;
            bignum_digits(a)[i-1] |= 0x80000000U;
        }
        else bignum_digits(a)[i] = carry;
    }
// I need to free up some space here, I guess
    lenx = (bignum_length(a)-CELL)/4;
    if (SIXTY_FOUR_BIT)
    {   lenx = (lenx + 1) & ~1;
        lenc = (lena + 2) & ~1;
    }
    else
    {   lenx |= 1;  // round up to allow for allocation in doublewords
        lenc = (lena+1) | 1;
    }
    if (lenc != lenx) // space to discard?
        *(Header *)&bignum_digits(a)[lenc] = make_bighdr(lenx-lenc);
    numhdr(a) = make_bighdr(lena+1+CELL/4);
    return a;
}

LispObject quotbn1(LispObject a, int32_t n)
//
// Divide a bignum by an integer, where the integer is (by now)
// a natural C int32_t but limited to 31 not 32 bits active.  I.e.
// this can be used when dividing by a fixnum or by dividing by
// a one-word bignum.  I will not call this with n=-1, which would
// be the one case where it could cause the quotient to be bigger
// than the dividend.  Leaves nwork set to the remainder.
// This version is JUST the same as quotbn() except that it does not
// hand back a useful quotient - it is intended for use when only
// the remainder is wanted. For consistency I leave that where quotbn() did.
// The motivation for this is that I can avoid needing to allocate memory
// for the quotient...
{   int sign;
    int32_t lena = (bignum_length(a)-CELL)/4-1, i;
    uint32_t carry;
    if (!SIXTY_FOUR_BIT && lena == 0)      // one-word bignum as numerator
    {   int32_t p = (int32_t)bignum_digits(a)[0];
        nwork = p % n;
//
// C does not define what happens on non-exact division involving
// negative quantities, so I adjust things here so that the remainder
// has the sign that I want and the division I do is exact.
//
        if (p < 0)
        {   if (nwork > 0) nwork -= n;
        }
        else if (nwork < 0) nwork += n;
// Remainder should be correct (with correct sign) by now, regardless
        return nil;
    }
    else if (lena == 1)
    {   int64_t p = bignum_digits64(a, 1)<<31 | bignum_digits(a)[0];
        nwork = p % n;
        if (p < 0)
        {   if (nwork > 0) nwork -= n;
        }
        else if (nwork < 0) nwork += n;
        return nil;
    }
//
// That has dealt with the special cases - now the input is a bignum
// with at least 3 digits and the quotient will certainly be a bignum.
// Start by allocating a workspace copy of the dividend.  negateb will
// leave a a bignum, although it may change its length.
//
//
// Also note that I could fold the negateb() in with the division, and
// thereby save allocating a big hunk of extra memory.
//
// The code here is something of a cop-out in that it allocates memory for
// a copy of a even though it really does not need to. Maybe I should revisit
// it sometime.
    if ((int32_t)bignum_digits(a)[lena] < 0) a = negateb(a), sign = 3;
    else a = copyb(a), sign = 0;
    if (n < 0)
    {   sign ^= 1;
        n = -n;
    }
//
// Now both a and n have been made positive, and their original signs
// have been recorded so that I can tidy up at the end.  The 1 bit in sign
// tells me what sign the quotient will have, the 2 bit gives the sign
// for the remainder.
//
    lena = (bignum_length(a)-CELL)/4;
    carry = 0;
    for (i=lena-1; i>=0; i--)
        Ddivide(carry, bignum_digits(a)[i], carry, bignum_digits(a)[i], n);
    if ((sign & 2) != 0) carry = -(int32_t)carry;
// Beware and force carry to be treated as a signed value here!
    nwork = (int32_t)carry;          // leave remainder available to caller
    return nil;
}

static LispObject quotbi(LispObject a, LispObject b)
{
//
// dividing by 1 or -1 seems worth optimising.
//
    mv_2 = fixnum_of_int(0);
    if (b == fixnum_of_int(1)) return a;
    else if (b == fixnum_of_int(-1)) return negateb(a);
    else if (b == fixnum_of_int(0))
        aerror2("bad arg for quotient", a, b);
// Beware: quotbn can only take a 31-bit second argument...
    intptr_t n = int_of_fixnum(b);
// Check if b fits within 31-bits of signed integer...
    if (!SIXTY_FOUR_BIT ||
        signed31_in_ptr(n)) return quotbn(a, (int32_t)n);
// I should only get here on a 64-bit machine! I fake up a 2-word bignum
// for the value. On a 64-bit system that is NOT a standardly valid bignum,
// but it will allow me to call quotbb.
#ifdef HAVE_INT128_T
// Here I  cope with any case of a bignum with up to 4 digits divided
// by a 60-bit fixnum by converting things to the very wide type int128_t
// and just doing the division there. This may be faster than using long
// division!
    size_t lena = (bignum_length(a)-CELL-4)/4;
    int128_t p;
    switch (lena)
    {   case 0: // should never arise but put code in for frivolity!
            p = bignum_digits64(a, 0);
            break;
        case 1:
            p = bignum_digits64(a, 1)<<31 | bignum_digits(a)[0];
            break;
        case 2:
            p = bignum_digits64(a, 2)<<31 | bignum_digits(a)[1];
            p = ((uint128_t)p << 31) | bignum_digits(a)[0];
            break;
        case 3:        
            p = bignum_digits64(a, 3)<<31 | bignum_digits(a)[2];
            p = ((uint128_t)p << 31) | bignum_digits(a)[1];
            p = ((uint128_t)p << 31) | bignum_digits(a)[0];
            break;
    default:
        return quotbb(a, make_fake_bignum(n), QUOTBB_QUOTIENT_NEEDED);
    }
    p = p / int_of_fixnum(b);
// Now I need to re-pack the quotient, which could be anything up to a 3-digit
// bignum.
    return make_lisp_integer128(p);
#else
    return quotbb(a, make_fake_bignum(n), QUOTBB_QUOTIENT_NEEDED);
#endif
}

static LispObject quotrembi(LispObject a, LispObject b)
{
//
// dividing by 1 or -1 seems worth optimising.
//
    mv_2 = fixnum_of_int(0);
    if (b == fixnum_of_int(1)) return a;
    else if (b == fixnum_of_int(-1)) return negateb(a);
    else if (b == fixnum_of_int(0))
        aerror2("bad arg for quotient", a, b);
// Beware: quotbn can only take a 31-bit second argument...
    intptr_t n = int_of_fixnum(b);
// Check if b fits within 31-bits of signed integer...
    if (!SIXTY_FOUR_BIT ||
        signed31_in_ptr(n))
    {   LispObject q = quotbn(a, (int32_t)n);
        mv_2 = fixnum_of_int(nwork);
        return q;
    }
// I should only get here on a 64-bit machine! I fake up a 2-word bignum
// for the value. On a 64-bit system that is NOT a standardly valid bignum,
// but it will allow me to call quotbb.
#ifdef HAVE_INT128_T
    size_t lena = (bignum_length(a)-CELL-4)/4;
    int128_t p;
    switch (lena)
    {   case 0: // should never arise but put code in for frivolity!
            p = bignum_digits64(a, 0);
            break;
        case 1:
            p = bignum_digits64(a, 1)<<31 | bignum_digits(a)[0];
            break;
        case 2:
            p = bignum_digits64(a, 2)<<31 | bignum_digits(a)[1];
            p = ((uint128_t)p << 31) | bignum_digits(a)[0];
            break;
        case 3:        
            p = bignum_digits64(a, 3)<<31 | bignum_digits(a)[2];
            p = ((uint128_t)p << 31) | bignum_digits(a)[1];
            p = ((uint128_t)p << 31) | bignum_digits(a)[0];
            break;
    default:
        return quotbb(a, make_fake_bignum(n),
                      QUOTBB_QUOTIENT_NEEDED | QUOTBB_REMAINDER_NEEDED);
    }
// Because b is a fixnum the remainder must be.
    mv_2 = fixnum_of_int((int64_t)(p % int_of_fixnum(b)));
    p = p / int_of_fixnum(b);
    return make_lisp_integer128(p);
#else
    return quotbb(a, make_fake_bignum(n),
                  QUOTBB_QUOTIENT_NEEDED | QUOTBB_REMAINDER_NEEDED);
#endif
}

#define quotbs(a, b) quotsb(a, b)

// show() and show1() are not actually called by live code but where used in
// trace code currently commented out. I will leave them here just for now.

static void show(const char *msg, LispObject a, size_t lena)
{   trace_printf("%s", msg);
    if (is_fixnum(a)) trace_printf("#FIX% " PRIx64, int_of_fixnum(a));
    else
    {   size_t i = lena;
        for (;;)
        {   trace_printf(" %.8x", bignum_digits(a)[i]);
            if (i == 0) break;
            i--;
        }
    }
    trace_printf("\n");
}

static void show1(const char *msg, uint32_t atop, LispObject a, size_t lena)
{   trace_printf("%s %.8x : ", msg, atop);
    size_t i = lena;
    for (;;)
    {   trace_printf(" %.8x", bignum_digits(a)[i]);
        if (i == 0) break;
        i--;
    }
    trace_printf("\n");
}

//
// It is probably way over the top to make all the sub-functions for
// division "inline", but at least while I am writing it doing so will
// help discipline me into using procedural abstraction and not writing
// too much out longhand... And many of these are short enough anyway that
// the burden of inline expansion will not be huge, and maybe the most
// common use-cases will be when the big numbers are not very big and so
// procedure call overhead may be noticable.
//

// If |a| < |b| then a/b is zero. I judge the sizes by looking at how
// many digits are used in the bignum representations. There is a jolly
// extra level of though needed here in my case because of the 2s complement
// representation of numbers. If either a or b is of the form -2^(31*n-1)
// then it will be stored using a digit less than is needed for +2^(31*n-1).
// All other numbers retain the same number of big-digits when their absolute
// value is taken. So the test on the number of digits of the signed values
// here risks misleading if a or b are of that form. Well the only problem
// would be if the test succeeded unexpectedly and I returned zero. That
// might arise for the case a = -2^k and b = +2^k. From that state consider
// small chnges. If |a| increases even by 1 then lena increases and the
// special case exit is not activated. If |a| decreases then the quotient
// will legitimately be zero. If |b| increases then the true quotient ends up
// as zero, while if |b| decreases then lenb decreases and the special
// exit is not activated. Any other case where |lena|==|lenb| will have the
// lengths of a and b unchanged by negation so there can be no risk. So it
// seems that I have just a single edge case to test for!

static inline LispObject short_numerator(LispObject a, size_t lena,
                                         LispObject b, size_t lenb)
{   mv_2 = a;
// I can only have trouble if the representation of a is just one
// digit shorter than that of b and a starts off [-2^30,...] while
// b starts off [0,2^30,...].
    if (lena != lenb-1 ||
        (int32_t)bignum_digits(a)[lena] != -0x40000000 ||
        (int32_t)bignum_digits(b)[lenb] != 0 ||
        bignum_digits(b)[lenb-1] != 0x40000000U) return fixnum_of_int(0);
// Furthermore all further digits of both a and b must be zero for the
// odd case to apply.
    for (size_t i=0; i<lena; i++)
        if (bignum_digits(a)[i] != 0x00000000U ||
            bignum_digits(b)[i] != 0x00000000U) return fixnum_of_int(0);
// Here we go - return (-1) remainder zero.
    mv_2 = fixnum_of_int(0);
    return fixnum_of_int(-1);
}

static inline size_t copy_unsigned(LispObject r, LispObject a, size_t lena)
{   if (bignum_digits(a)[lena] == 0) lena--;
    for (size_t i=0; i<=lena; i++)
       bignum_digits(r)[i] = bignum_digits(a)[i];
    return lena;
}

// The following should only ever be used for negating numbers that
// start off negative, so the result should always be positive.

static inline size_t copy_negated(LispObject r, LispObject a, size_t lena)
{   uint32_t carry = 1;
//  show("input to copy_negated ", a, lena);
//  trace_printf("with lena = %d\n", (int)lena);
    for (size_t i=0; i<lena; i++) // all except the top digit
    {   uint32_t d = (bignum_digits(a)[i] ^ 0x7fffffff) + carry;
        bignum_digits(r)[i] = d & 0x7fffffff;
        carry = d >> 31;
    }
    if ((bignum_digits(r)[lena] = ~bignum_digits(a)[lena] + carry) == 0)
        lena--;
//  show("result of copy_negated ", r, lena);
//  trace_printf("with lena = %d\n", (int)lena);
    return lena;
}

#define SIGN_QUOTIENT_NEGATIVE   1
#define SIGN_REMAINDER_NEGATIVE  2

static inline int make_positive_and_copy(LispObject &a, size_t &lena,
                                         LispObject &b, size_t &lenb)
{
// Before I do anything else I will ensure that there is space available
// in the working variables... And I will leave myself a few bytes in hand.
    while (bignum_length(a)+16 >= bignum_length(big_dividend))
    {   size_t newlen = 2*bignum_length(big_dividend);
        push2(a, b);
//      trace_printf("newlen = %d\n", (int)newlen);
        LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, newlen);
        pop2(b, a);
        big_dividend = w;
    }
    while (bignum_length(b)+16 >= bignum_length(big_divisor))
    {   size_t newlen = 2*bignum_length(big_divisor);
        push2(a, b);
//      trace_printf("newlen = %d\n", (int)newlen);
        LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, newlen);
        pop2(b, a);
        big_divisor = w;
    }
    while (bignum_length(a)-bignum_length(b)+16 >= bignum_length(big_quotient))
    {   size_t newlen = 2*bignum_length(big_quotient);
        push2(a, b);
//      trace_printf("newlen = %d\n", (int)newlen);
        LispObject w = getvector(TAG_NUMBERS, TYPE_BIGNUM, newlen);
        pop2(b, a);
        big_quotient = w;
    }
    int sign = 0;
// While copying |a| into big_dividend and |b| into big_divisor I know that
// the results will be positive, so I discard any leading zero digits that
// might normally end up on the front of the numbers.
    if ((int32_t)bignum_digits(a)[lena] < 0)
    {   lena = copy_negated(big_dividend, a, lena);
        sign = SIGN_QUOTIENT_NEGATIVE | SIGN_REMAINDER_NEGATIVE;
    }
    else lena = copy_unsigned(big_dividend, a, lena);
    if ((int32_t)bignum_digits(b)[lenb] < 0)
    {   lenb = copy_negated(big_divisor, b, lenb);
        sign ^= SIGN_QUOTIENT_NEGATIVE;
    }
    else lenb = copy_unsigned(big_divisor, b, lenb);
    a = big_dividend;
    b = big_divisor;
//  trace_printf("operands made positive, lengths %d %d\n", (int)lena, (int)lenb);
//  show("a: ", a, lena);
//  show("b: ", b, lenb);
    return sign;
}

// This multiplies a by scale (in place) and returns any digit that
// carries out from the top. The value of scale is exected to be at
// most 0x40000000U and each digit in a is at most 0x7fffffffU, so the
// carry digit returned is at worst 0x3fffffffU.

static inline uint32_t timesbn(LispObject a, size_t len, uint32_t scale)
{   uint32_t carry = 0;
    for (size_t i=0; i<=len; i++)
    {   uint64_t d = (uint64_t)bignum_digits(a)[i] * (uint64_t)scale + carry;
        bignum_digits(a)[i] = (uint32_t)d & 0x7fffffff;
        carry = (uint32_t)(d >> 31);
    }
    return carry;   
}

static inline int32_t multiply_and_subtract(LispObject a, size_t lena,
                                            uint32_t q0,
                                            LispObject b, size_t lenb)
{   int32_t carry = 0;
    for (size_t i=0; i<=lenb; i++)
    {   int64_t d = (int64_t)bignum_digits(a)[lena-lenb+i] -
                    (int64_t)bignum_digits(b)[i]*(int64_t)q0 +
                    (int64_t)carry;
//      trace_printf("%.8x - %.8x * %.8x + %.8x = %" PRIx64 "\n",
//          bignum_digits(a)[lena-lenb+i],
//          bignum_digits(b)[i],
//          q0,
//          carry,
//          d);
        bignum_digits(a)[lena-lenb+i] = (uint32_t)d & 0x7fffffff;
        carry = (int32_t)(d >> 31);
//      trace_printf("digit for a = %.8x\n", bignum_digits(a)[lena-lenb+i]);
//      trace_printf("new carry = %.8x\n", (int)carry);
    }
//  trace_printf("return %.8x\n", carry);
    return carry;   
}

static inline int32_t add_back_correction(LispObject a, size_t lena,
                                          LispObject b, size_t lenb)
{    uint32_t carry = 0;
     for (size_t i=0; i<=lenb; i++)
     {   uint32_t d = bignum_digits(a)[lena-lenb+i] +
                      bignum_digits(b)[i] +
                      carry;
         bignum_digits(a)[lena-lenb+i] = d & 0x7fffffff;
         carry = d >> 31;
     }
     return carry;   
}

static inline uint32_t next_quotient_digit(uint32_t atop,
                                           LispObject a, size_t &lena,
                                           LispObject b, size_t lenb)
{   uint64_t p0 = (uint64_t)atop<<31 | bignum_digits(a)[lena];
    uint32_t q0 =  p0 / (uint64_t)bignum_digits(b)[lenb];
    uint32_t r0 =  p0 % (uint64_t)bignum_digits(b)[lenb];
// At this stage q0 may be correct or it may be an over-estimate by 1 or 2,
// but never any worse than that.
//
// The test on the next line should detect all case where q0 was in error
// by 2 and most when it was in error by 1. 
//
    if (q0 == 0x80000000U ||
        (uint64_t)q0*(uint64_t)bignum_digits(b)[lenb-1] >
        ((uint64_t)r0<<31 | bignum_digits(a)[lena-1]))
        q0--;
//  trace_printf("Leading quotient digit = %d = %#x\n", q0, q0);
//
// Now I want to go "a = a - b*q0*2^(31*(lena-lenb));" so that a
// is set to an accurate remainder after using q0 as (part of) the
// quotient. This may carry an overshoot into atop and if so I will need
// to reduce q0 again and compensate.
//
    atop += multiply_and_subtract(a, lena, q0, b, lenb);
//  show1("sets a to ", atop, a, lena);
    if ((int32_t)atop < 0)
    {   q0--;
        atop = add_back_correction(a, lena, b, lenb);
// When I add back b I ought to get a carry...
        assert(atop == 1);
    }
    lena--;  // a is now one digit shorter.
    return q0;
}

// a is a scaled positive value that , when divided by the scale factor
// will be less than the original divisor.

static inline size_t unscale(LispObject a, size_t lena, uint32_t scale)
{   uint32_t atop = 0;
    size_t i = lena;
    for (;;)
    {   uint64_t d = (uint64_t)atop<<31 | bignum_digits(a)[i];
        bignum_digits(a)[i] = (uint32_t)(d / scale);
        atop = (uint32_t)(d % scale);
        if (i == 0) break;
        i--;
    }
    while (lena != 0 && bignum_digits(a)[lena] == 0) lena--;
// Deal with the CSL oddity that the top digit of a bignum is treated as
// a signed 31-bit value, and so I sometimes need a leading zero ahead of it.
    if ((bignum_digits(a)[lena] & 0x40000000) != 0)
    {   lena++;
        bignum_digits(a)[lena] = 0;
    }
    return lena;
}

// Adjust the quotient format so it will be OK for my awkward internal
// representation.

static inline size_t fix_up_bignum_length(LispObject q, size_t lenq)
{
    if ((bignum_digits(q)[lenq] & 0x40000000U) != 0)
    {   lenq++;
        bignum_digits(q)[lenq] = 0;
    }
    else while (lenq != 0 &&
        bignum_digits(q)[lenq] == 0 &&
        (bignum_digits(q)[lenq-1] & 0x40000000U) == 0) lenq--;
    return lenq;
}

// For this one the input starts off positive and so it will end up negative.
// That could lead to it being able to get away with just one fewer digit.

static inline size_t negate_in_place(LispObject a, size_t lena)
{   uint32_t carry = 1;
    for (size_t i=0; i<lena; i++)
    {   uint32_t d = (bignum_digits(a)[i] ^ 0x7fffffff) + carry;
        bignum_digits(a)[i] = d & 0x7fffffff;
        carry = d >> 31; 
//      trace_printf("negate in place: %.8x %.8x\n", bignum_digits(a)[i], carry);
    }
// I treat the top digit specially since it is thought of as a signed value.
    int32_t d = ~bignum_digits(a)[lena] + carry;
//  trace_printf("top digits = %.8x\n", d);
    if (d == -1 &&
        lena != 0 &&
        (bignum_digits(a)[lena-1] & 0x40000000U) != 0)
    {   lena--;   // Shorten the number.
//  trace_printf("shorten and force top bit of previous\n");
        bignum_digits(a)[lena] |= 0x80000000;
    }
    else bignum_digits(a)[lena] = d;
    return lena;
}

static inline LispObject pack_up_result(LispObject a, size_t lena)
{
//  show("pack_up_result ", a, lena);
    if (lena == 0 &&
        (SIXTY_FOUR_BIT || valid_as_fixnum((int32_t)bignum_digits(a)[0])))
        return fixnum_of_int((int32_t)bignum_digits(a)[0]);
    else if (SIXTY_FOUR_BIT && lena == 1)
    {   int64_t r = bignum_digits64(a, 1)<<31 | bignum_digits(a)[0];
        if (valid_as_fixnum(r)) return fixnum_of_int(r);
    }
    LispObject r = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*lena+4);
//  trace_printf("lena = %d  r = %p\n", (int)lena, (void *)r);
    size_t i;
    for (i=0; i<=lena; i++)
        bignum_digits(r)[i] = bignum_digits(a)[i];
    if ((SIXTY_FOUR_BIT && (i & 1) != 0) ||
        (!SIXTY_FOUR_BIT && (i & 1) == 0)) bignum_digits(a)[i] = 0;
    return r;    
}

// I need to make copies of both numerator and denominator here because
// both get scaled. To avoid turning over more memory than I have to
// I will use fixed workspace held in big_divisor and big_dividend. These
// start off as 4-digit bignums, but I will reallocate/expand them here
// as need-be.  Right at the end of the calculation I will need to
// transcribe from big_dividend into a fresh new bignum that is returned as
// the remainder from this division. In these two workspace numbers I
// will only use the number of low digits relevant in the current calculation,
// and space beyond that may contain arbitrary garbage. This scheme has a
// consequence that if somewhere in a calculation the user does operations
// on really seriously long bignums then these workspace values get
// expanded and then remain large. Hmmm by expectation is that any space waste
// that arises will be small in the context of everything else.

LispObject quotbb(LispObject a, LispObject b, int need)
{   size_t lena = (bignum_length(a)-CELL-4)/4,
           lenb = (bignum_length(b)-CELL-4)/4;
// On 32-bit machines I may have a denominator that still fits in 31-bits.
// In that case I can optimise. The case lenb==0 ought not to arise on a
// 64-bit machine... And to avoid ending up with a division by a 1-word
// value it turns out that I MUST detect and filter out cases where the
// divisor is "really only 31-bits" but it has an extension word stuck on the
// front at thus stage. The reason for all this is that the main LONG division
// code assumes that the denominator b has at least two digits in it, and
// if it is erroneously allowed to run on a 1-digit number it accesses a
// "digit -1" which does not exist. In reality in that case it treats
// the header word of the bignum as if it has been part of the numeric data.
    if (!SIXTY_FOUR_BIT && (lenb == 0 ||
        (lenb == 1 && (bignum_digits(b)[1]==0 ||
                       (int32_t)bignum_digits(b)[1]==-1))))
    {   int32_t nn = (int32_t)bignum_digits(b)[0];
        if (lenb != 0 && (int32_t)bignum_digits(b)[1]==-1)
            nn = (int32_t)((uint32_t)nn | 0x80000000U);
        LispObject q = quotbn(a, nn);
        if ((need & QUOTBB_REMAINDER_NEEDED) != 0)
        {   push(q);
            a = make_lisp_integer32(nwork);
            pop(q);
            mv_2 = a;
        }
        return q;
    }
// If a has fewer digits than b then the quotient will be zero and I should
// report that without further messing around. However there is enough
// delicacy here that I lift processing into a separate procedure!
    if (lena < lenb) return short_numerator(a, lena, b, lenb);
// I copy the absolute values of a and b to places where it will be
// OK to overwrite them, taking their absolute values as I go. I record
// whether the eventual quotient and/or remainder will need to be negated
// at the end. This leaves the two inputs as rows of unsigned 31-bit digits
// with a[alen] and b[blen] both non-zero.
    mv_2 = a;
    int sign = make_positive_and_copy(a, lena, b, lenb);
// Tidying up the numbers may reveal a zero-quotient case if on input
// a and b use the same number of digits but a is of the form
// [0, 0x4xxxxxxx] while b is [nnnn, mmmm] and so within make_positive_and_copy
// the leading zero on a is removed.
    if (lena < lenb) return fixnum_of_int(0);
// By now a and b both have strictly positive leading digits.
    size_t lenq = lena-lenb; // potential length of quotient.
// I will multiply a and b by a scale factor that gets the top digit of "b"
// reasonably large. The value stored in "a" can become one digit longer,
// but there is space to store that.
//
// The scale factor used here is as per Knuth II edition II. Edition III
// proposed 0x7fffffffU/bignum_digits(b)[lenb] and if you look at just the
// leading digit of b alone that seems OK, but I am concerned that when you
// take lower digits of b into account that multiplying b by it can overflow.
    uint32_t scale = 0x80000000U / (bignum_digits(b)[lenb] + 1);
// When I scale the dividend expands into an extra digit but the scale
// factor has been chosen so that the divisor does not. So beware that
// a now has digits running from 0 to lena+1.
    bignum_digits(a)[lena+1] = timesbn(a, lena, scale);
    uint32_t btop = timesbn(b, lenb, scale);
    (void)btop; // To try to get rid of warning on unused variable btop.
    assert(btop == 0);
    size_t m = lenq;
    for (;;)
    {   uint32_t q = next_quotient_digit(
            bignum_digits(a)[lena+1], a, lena,
            b, lenb);
        bignum_digits(big_quotient)[m] = q;
        if (m == 0) break;
        m--;
    }
// Unscale and correct the signs.
    if ((need && QUOTBB_REMAINDER_NEEDED) != 0)
    {   lena = unscale(a, lena+1, scale);
        if (sign & SIGN_REMAINDER_NEGATIVE)
            lena = negate_in_place(a, lena);
    }
    if ((need & QUOTBB_QUOTIENT_NEEDED) != 0)
// Ensure that the quotient has a prefix zero digit if needbe.
    {   lenq = fix_up_bignum_length(big_quotient, lenq);
        if (sign & SIGN_QUOTIENT_NEGATIVE)
            lenq = negate_in_place(big_quotient, lenq);
    }
    if ((need && QUOTBB_REMAINDER_NEEDED) != 0)
// Now I need to pack the results so that they are suitable for use
// elsewhere in the system. 
    {   a = pack_up_result(a, lena);
        mv_2 = a;
    }
    if ((need & QUOTBB_QUOTIENT_NEEDED) != 0)
        return pack_up_result(big_quotient, lenq);
    else return nil;
}

#define quotbr(a, b) quotir(a, b)

#define quotbc(a, b) quotic(a, b)

#define quotbf(a, b) quotsf(a, b)

static LispObject quotri(LispObject a, LispObject b)
{   LispObject w;
    mv_2 = fixnum_of_int(0);
    if (b == fixnum_of_int(1)) return a;
    else if (b == fixnum_of_int(0))
        aerror2("bad arg for quotient", a, b);
    push3(a, b, nil);
#define g   stack[0]
#define b   stack[-1]
#define a   stack[-2]
    g = gcd(b, numerator(a));
    w = minusp(b);
    if (w) g = negate(g);      // ensure denominator is +ve
    b = quot2(b, g);
    g = quot2(numerator(a), g);
    a = times2(b, denominator(a));
    w = make_ratio(g, a);
    popv(3);
    return w;
#undef a
#undef b
#undef g
}

#define quotrs(a, b) quotsb(a, b)

#define quotrb(a, b) quotib(a, b)

static LispObject quotrr(LispObject a, LispObject b)
{   LispObject w;
    mv_2 = fixnum_of_int(0);
    push5(numerator(a), denominator(a),
          denominator(b), numerator(b), // NB switched order
          nil);
#define g   stack[0]
#define db  stack[-1]
#define nb  stack[-2]
#define da  stack[-3]
#define na  stack[-4]
    g = gcd(na, db);
    w = minusp(db);
    if (w) g = negate(g);
    na = quot2(na, g);
    db = quot2(db, g);
    g = gcd(nb, da);
    nb = quot2(nb, g);
    da = quot2(da, g);
    na = times2(na, nb);
    da = times2(da, db);
    w = make_ratio(na, da);
    popv(5);
    return w;
#undef g
#undef db
#undef nb
#undef da
#undef na
}

#define quotrc(a, b) quotic(a, b)

#define quotrf(a, b) quotsf(a, b)

static LispObject quotci(LispObject a, LispObject b)
{   LispObject r = real_part(a), i = imag_part(a);
    mv_2 = fixnum_of_int(0);
    if (b == fixnum_of_int(0)) aerror2("bad arg for quotient", a, b);
    push2(b, r);
    i = quot2(i, b);
    pop2(r, b);
    push(i);
    r = quot2(r, b);
    pop(i);
    return make_complex(r, i);
}

#define quotcs(a, b) quotci(a, b)

#define quotcb(a, b) quotci(a, b)

#define quotcr(a, b) quotci(a, b)

#define quotcc(a, b) quotic(a, b)

#define quotcf(a, b) quotci(a, b)

static LispObject quotfi(LispObject a, LispObject b)
{   double d;
    mv_2 = fixnum_of_int(0);
    if (b == fixnum_of_int(0)) aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / (double)int_of_fixnum(b);
    if (trap_floating_overflow &&
        floating_edge_case(d))
    {   floating_clear_flags();
        aerror("floating point quotient");
    }
    return make_boxfloat(d, type_of_header(flthdr(a)));
}

static LispObject quotfs(LispObject a, LispObject b)
{   double d = float_of_number(b);
    mv_2 = fixnum_of_int(0);
    if (d == 0.0) aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / d;
    if (trap_floating_overflow &&
        floating_edge_case(d))
    {   floating_clear_flags();
        aerror("floating point quotient");
    }
    return make_boxfloat(d, type_of_header(flthdr(a)));
}

#define quotfb(a, b) quotfs(a, b)

#define quotfr(a, b) quotfs(a, b)

#define quotfc(a, b) quotic(a, b)

static LispObject quotff(LispObject a, LispObject b)
{   int32_t ha = type_of_header(flthdr(a)), hb = type_of_header(flthdr(b));
    int32_t hc;
    mv_2 = fixnum_of_int(0);
// If EITHER argument is a long float I will need to do things differently,
// bacause I can not use machine-native arithmetic on float128_t.
    if (ha == TYPE_LONG_FLOAT || hb == TYPE_LONG_FLOAT)
    {   float128_t x, y, z;
        x = float128_of_number(a);
        y = float128_of_number(b);
        f128M_div(&x, &y, &z);
        if (trap_floating_overflow &&
            floating_edge_case128(&z))
            aerror("floating point quotient");
        return make_boxfloat128(z);
    }
    else if (ha == TYPE_DOUBLE_FLOAT || hb == TYPE_DOUBLE_FLOAT)
        hc = TYPE_DOUBLE_FLOAT;
    else hc = TYPE_SINGLE_FLOAT;
    double d;
    if ((d = float_of_number(b)) == 0.0)
        aerror2("bad arg for quotient", a, b);
    if (trap_floating_overflow &&
        floating_edge_case(d))
    {   floating_clear_flags();
        aerror("floating point quotient");
    }
    else return make_boxfloat(float_of_number(a) / d, hc);
}

LispObject quot2(LispObject a, LispObject b)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum / fixnum arithmetic happens - the case I most want to
// make efficient.
//
                    if (b == fixnum_of_int(0))
                        aerror2("bad arg for quotient", a, b);
                    else
                    {   intptr_t r, aa, bb;
                        aa = int_of_fixnum(a);
                        bb = int_of_fixnum(b);
// calculate remainder and force its sign to be correct
                        r = aa % bb;
                        if (aa < 0)
                        {   if (r > 0) r -= bb;
                        }
                        else if (r < 0) r += bb;
// then the division can be an exact one, as here
                        r = (aa - r)/bb;
//
// the only case where dividing one fixnum by another can lead to
// a bignum result is (-0x08000000/(-1)) which JUST overflows.
//
                        if (!SIXTY_FOUR_BIT && r == 0x08000000)
                            return make_one_word_bignum(r);
                        if (SIXTY_FOUR_BIT && r == INT64_C(0x0800000000000000))
                            return make_lisp_integer64(r);
                        else return fixnum_of_int(r);
                    }
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return quotis(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotib(a, b);
                        case TYPE_RATNUM:
                            return quotir(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotic(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotif(a, b);
                default:
                    aerror1("bad arg for quotient",  b);
            }
#ifdef SHORT_FLOAT
        case XTAG_SFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return quotsi(a, b);
                case XTAG_SFLOAT:
                {   Float_union aa, bb;
                    aa.i = a - XTAG_SFLOAT;
                    bb.i = b - XTAG_SFLOAT;
                    aa.f = (float) (aa.f / bb.f);
                    return (aa.i & ~(int32_t)0xf) + XTAG_SFLOAT;
                }
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotsb(a, b);
                        case TYPE_RATNUM:
                            return quotsr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotsc(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotsf(a, b);
                default:
                    aerror1("bad arg for quotient",  b);
            }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotbi(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotbs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotbb(a, b, QUOTBB_QUOTIENT_NEEDED);
                                case TYPE_RATNUM:
                                    return quotbr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotbc(a, b);
                                default:
                                    aerror1("bad arg for quotient",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotbf(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                case TYPE_RATNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotri(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotrs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotrb(a, b);
                                case TYPE_RATNUM:
                                    return quotrr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotrc(a, b);
                                default:
                                    aerror1("bad arg for quotient",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotrf(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                case TYPE_COMPLEX_NUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotci(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotcs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotcb(a, b);
                                case TYPE_RATNUM:
                                    return quotcr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotcc(a, b);
                                default:
                                    aerror1("bad arg for quotient",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotcf(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                default:    aerror1("bad arg for quotient",  a);
            }
        }
        case TAG_BOXFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return quotfi(a, b);
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return quotfs(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotfb(a, b);
                        case TYPE_RATNUM:
                            return quotfr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotfc(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotff(a, b);
                default:
                    aerror1("bad arg for quotient",  b);
            }
        default:
            aerror1("bad arg for quotient",  a);
    }
}

LispObject quotrem2(LispObject a, LispObject b)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum / fixnum arithmetic happens - the case I most want to
// make efficient.
//
                    if (b == fixnum_of_int(0))
                        aerror2("bad arg for divide", a, b);
                    else
                    {   intptr_t r, aa, bb;
                        aa = int_of_fixnum(a);
                        bb = int_of_fixnum(b);
// calculate remainder and force its sign to be correct
                        r = aa % bb;
                        if (aa < 0)
                        {   if (r > 0) r -= bb;
                        }
                        else if (r < 0) r += bb;
                        mv_2 = fixnum_of_int(r);
// then the division can be an exact one, as here
                        r = (aa - r)/bb;
//
// the only case where dividing one fixnum by another can lead to
// a bignum result is (-0x08000000/(-1)) which JUST overflows.
//
                        if (r == -MOST_NEGATIVE_FIXVAL)
                            return make_lisp_integerptr(r);
                        else return fixnum_of_int(r);
                    }
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return quotis(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotib(a, b);
                        case TYPE_RATNUM:
                            return quotir(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotic(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotif(a, b);
                default:
                    aerror1("bad arg for quotient",  b);
            }
#ifdef SHORT_FLOAT
        case XTAG_SFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return quotsi(a, b);
                case XTAG_SFLOAT:
                {   Float_union aa, bb;
                    aa.i = a - XTAG_SFLOAT;
                    bb.i = b - XTAG_SFLOAT;
                    aa.f = (float) (aa.f / bb.f);
                    return (aa.i & ~(int32_t)0xf) + XTAG_SFLOAT;
                }
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotsb(a, b);
                        case TYPE_RATNUM:
                            return quotsr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotsc(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotsf(a, b);
                default:
                    aerror1("bad arg for quotient",  b);
            }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotrembi(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotbs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotbb(a, b,
                                        QUOTBB_QUOTIENT_NEEDED |
                                        QUOTBB_REMAINDER_NEEDED);
                                case TYPE_RATNUM:
                                    return quotbr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotbc(a, b);
                                default:
                                    aerror1("bad arg for quotient",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotbf(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                case TYPE_RATNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotri(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotrs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotrb(a, b);
                                case TYPE_RATNUM:
                                    return quotrr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotrc(a, b);
                                default:
                                    aerror1("bad arg for quotient",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotrf(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                case TYPE_COMPLEX_NUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotci(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotcs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotcb(a, b);
                                case TYPE_RATNUM:
                                    return quotcr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotcc(a, b);
                                default:
                                    aerror1("bad arg for quotient",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotcf(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                default:    aerror1("bad arg for quotient",  a);
            }
        }
        case TAG_BOXFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return quotfi(a, b);
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return quotfs(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotfb(a, b);
                        case TYPE_RATNUM:
                            return quotfr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotfc(a, b);
                        default:
                            aerror1("bad arg for quotient",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotff(a, b);
                default:
                    aerror1("bad arg for quotient",  b);
            }
        default:
            aerror1("bad arg for quotient",  a);
    }
}

//
// The above version of quot2 is as required for the Standard Lisp QUOTIENT
// function, and it is called from various internal places in CSL/CCL, eg
// from within the code for TRUNCATE. Next I have something that will be very
// similar in behaviour, but which turns quotients of integers into
// rational numbers when that is necessary.
//

/***** Not reconstructed yet!!
 * ie this would need testing and review before being used in anger.
 */

LispObject CLquot2(LispObject a, LispObject b)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum / fixnum arithmetic happens - the case I most want to
// make efficient.
//
                    if (b == fixnum_of_int(0))
                        aerror2("bad arg for /", a, b);
                    else
                    {   intptr_t r, aa, bb, w;
                        aa = int_of_fixnum(a);
                        bb = int_of_fixnum(b);
                        if (bb < 0) aa = -aa, bb = -bb;
                        r = aa % bb;
                        if (r == 0)   // Exact division case
                        {   r = aa/bb;
//
// the only case where dividing one fixnum by another can lead to
// a bignum result is (-0x08000000/(-1)) which JUST overflows.
//
                            if (!SIXTY_FOUR_BIT && r == 0x08000000)
                                return make_one_word_bignum(r);
                            else if (SIXTY_FOUR_BIT &&
                                r == INT64_C(0x0800000000000000))
                                return make_lisp_integer64(r);
                            else return fixnum_of_int(r);
                        }
                        w = bb;
                        if (r < 0) r = -r;
                        while (r != 0)
                        {   int32_t w1 = w % r;
                            w = r;
                            r = w1;
                        }
                        aa = aa / w;
                        bb = bb / w;
                        return make_ratio(fixnum_of_int(aa), fixnum_of_int(bb));
                    }
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return quotis(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return CLquotib(a, b);
                        case TYPE_RATNUM:
                            return quotir(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotic(a, b);
                        default:
                            aerror1("bad arg for /",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotif(a, b);
                default:
                    aerror1("bad arg for /",  b);
            }
#ifdef SHORT_FLOAT
        case XTAG_SFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return quotsi(a, b);
                case XTAG_SFLOAT:
                {   Float_union aa, bb;
                    aa.i = a - XTAG_SFLOAT;
                    bb.i = b - XTAG_SFLOAT;
                    aa.f = (float) (aa.f / bb.f);
                    return (aa.i & ~(int32_t)0xf) + XTAG_SFLOAT;
                }
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotsb(a, b);
                        case TYPE_RATNUM:
                            return quotsr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotsc(a, b);
                        default:
                            aerror1("bad arg for /",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotsf(a, b);
                default:
                    aerror1("bad arg for /",  b);
            }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return CLquotbi(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotbs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return CLquotbb(a, b);
                                case TYPE_RATNUM:
                                    return quotbr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotbc(a, b);
                                default:
                                    aerror1("bad arg for /",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotbf(a, b);
                        default:
                            aerror1("bad arg for /",  b);
                    }
                case TYPE_RATNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotri(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotrs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotrb(a, b);
                                case TYPE_RATNUM:
                                    return quotrr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotrc(a, b);
                                default:
                                    aerror1("bad arg for /",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotrf(a, b);
                        default:
                            aerror1("bad arg for /",  b);
                    }
                case TYPE_COMPLEX_NUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return quotci(a, b);
#ifdef SHORT_FLOAT
                        case XTAG_SFLOAT:
                            return quotcs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return quotcb(a, b);
                                case TYPE_RATNUM:
                                    return quotcr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return quotcc(a, b);
                                default:
                                    aerror1("bad arg for /",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return quotcf(a, b);
                        default:
                            aerror1("bad arg for /",  b);
                    }
                default:    aerror1("bad arg for /",  a);
            }
        }
        case TAG_BOXFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return quotfi(a, b);
#ifdef SHORT_FLOAT
                case XTAG_SFLOAT:
                    return quotfs(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return quotfb(a, b);
                        case TYPE_RATNUM:
                            return quotfr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return quotfc(a, b);
                        default:
                            aerror1("bad arg for /",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return quotff(a, b);
                default:
                    aerror1("bad arg for /",  b);
            }
        default:
            aerror1("bad arg for /",  a);
    }
}

// end of arith03.cpp
