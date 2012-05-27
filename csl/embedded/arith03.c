/*  arith03.c                         Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Arithmetic functions.
 *    quotient.
 *
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 13a28396 24-May-2008 */

#include "headers.h"


/*
 * Division
 */

#ifndef IDIVIDE
#ifdef HAVE_UINT64_T

uint32_t Idivide(uint32_t *qp, uint32_t a, uint32_t b, uint32_t c)
/*
 *         *qp = (a,b) / c,  return the remainder
 *
 * The double-length value (a,b) is given as a 62-bit positive number.  Its
 * low order 31 bits are in b, and the 0x80000000 bit of b is zero.  The
 * high order part (in a) is also represented with the 0x80000000 bit zero.
 * The divisor c is a positive value that is at most 0x7fffffff, and the
 * procedure will only be called when the correct quotient is in the
 * (inclusive) range 0 to 0x7fffffff.  The above constraints can be thought
 * of in two ways: (a) Idivide used a 31-bit word and is working on
 * unsigned values.  The 31-bit quantities happen to be being passed around
 * in 32 bit registers, but the top bit of those registers will never be used
 * and will contain zero, or (b) the range of values used is such that
 * a 64 by 32-bit division can be performed, and by constraining the range
 * of values this 64 by 32-bit division only has to handle positive numbers,
 * but depending on the hardware of your computer you are entitled to use
 * either signed or unsigned arithmetic.
 */
{
    uint64_t p = ((uint64_t)a << 31) | (uint64_t)b;
    *qp = (uint32_t)(p / (uint64_t)c);
    return (uint32_t)(p % (uint64_t)c);
}

#else

uint32_t Idivide(uint32_t *qp, uint32_t a, uint32_t b, uint32_t c)
/*
 *         *qp = (a,b) / c,  return the remainder
 *
 * The double-length value (a,b) is given as a 62-bit positive number.  Its
 * low order 31 bits are in b, and the 0x80000000 bit of b is zero.  The
 * high order part (in a) is also represented with the 0x80000000 bit zero.
 * The divisor c is a positive value that is at most 0x7fffffff, and the
 * procedure will only be called when the correct quotient is in the
 * (inclusive) range 0 to 0x7fffffff.  The above constraints can be thought
 * of in two ways: (a) Idivide used a 31-bit word and is working on
 * unsigned values.  The 31-bit quantities happen to be being passed around
 * in 32 bit registers, but the top bit of those registers will never be used
 * and will contain zero, or (b) the range of values used is such that
 * a 64 by 32-bit division can be performed, and by constraining the range
 * of values this 64 by 32-bit division only has to handle positive numbers,
 * but depending on the hardware of your computer you are entitled to use
 * either signed or unsigned arithmetic.
 */
{
    int i;
    uint32_t q = 0;
/*
 * I have a loop that needs to be executed 32 times, with just
 * slightly different behaviour the last time around.  Since it is
 * fairly short, I unwind it three-fold into a loop executed 10 times
 * plus a postlude.  I also do a test at the start that decides if the
 * quotient will be small (less than about 16 bits) an in that case
 * loop rather less often - my reasoning is that a plausible distribution
 * of quotients is exponential so the short route will be taken about
 * half of the time, and will save almost half of the work done here at the
 * cost of a not-too-expensive extra test to begin with.
 */
    if (a < (c >> 15))
    {   a = (a << 15) | (b >> 16);
        b = (b << 15) & 0x7fffffff;
        i = 5;
    }
    else i = 0;
    do
    {   q = q << 3;         /* accumulate quotient 3 bits at a time */
        if (a >= c)         /* bit 1 of 3... */
        {   a = a - c;
            q = q + 4;
        }
        a = a << 1;         /* shift (a,b) doubleword left 1 bit */
        b = b << 1;
        if (((int32_t)b) < 0) a = a + 1;
        if (a >= c)         /* bit 2 of 3... */
        {   a = a - c;
            q = q + 2;
        }
        a = a << 1;
        b = b << 1;
        if (((int32_t)b) < 0) a = a + 1;
        if (a >= c)         /* bit 3 of 3... */
        {   a = a - c;
            q = q + 1;
        }
        a = a << 1;
        b = b << 1;
        if (((int32_t)b) < 0) a = a + 1;
        i++;
   } while (i < 10);
    q = q << 2;             /* 2 more bits to be included */
    if (a >= c)
    {   a = a - c;
        q = q + 2;
    }
    a = a << 1;
    b = b << 1;
    if (((int32_t)b) < 0) a = a + 1;
    if (a >= c)             /* the final bit of the quotient */
    {   a = a - c;          /* leave remainder in a, b should be zero */
        q = q + 1;
    }
    *qp = q;
    return a;
}

#endif
#endif /* IDIVIDE */

#ifdef COMMON
static Lisp_Object quotis(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    if (bb.f == 0.0) return aerror2("bad arg for quotient", a, b);
    bb.f = (float) ((float)int_of_fixnum(a) / bb.f);
    return (bb.i & ~(int32_t)0xf) + TAG_SFLOAT;
}
#endif

static Lisp_Object quotib(Lisp_Object a, Lisp_Object b)
{
/*
 * a fixnum divided by a bignum always gives 0, regardless of signs etc.,
 * save in the one case of (-#x8000000)/(#x8000000) which must yield -1
 */
    if (int_of_fixnum(a) == fix_mask && bignum_length(b) == 8 &&
        bignum_digits(b)[0] == 0x08000000) return fixnum_of_int(-1);
    else return fixnum_of_int(0);
}

#ifdef COMMON
static Lisp_Object CLquotib(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object g, nil = C_nil;
    CSLbool w;
    push2(a, b);
    w = minusp(b);
    errexitn(2);
    g = gcd(stack[0], stack[-1]);
    errexitn(2);
    if (w)
    {   g = negate(g);
        errexitn(2);
    }
    a = stack[-1];
    push(g);
    a = quot2(a, g);
    errexitn(3);
    pop2(g, b);
    stack[0] = a;
    b = quot2(b, g);
    pop(a);
    errexit();
    return make_ratio(a, b);
}

static Lisp_Object CLquotbi(Lisp_Object a, Lisp_Object b)
{
    return CLquotib(a, b);
}

static Lisp_Object CLquotbb(Lisp_Object a, Lisp_Object b)
{
    return CLquotib(a, b);
}

static Lisp_Object quotir(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object w, nil;
    if (a == fixnum_of_int(0)) return a;
    push3(b, a, C_nil);
#define g   stack[0]
#define a   stack[-1]
#define b   stack[-2]
    g = gcd(a, numerator(b));
/*
 * the gcd() function guarantees to hand back a positive result.
 */
    nil = C_nil;
    if (exception_pending()) goto fail;
    a = quot2(a, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = minusp(numerator(b));
    nil = C_nil;
    if (exception_pending()) goto fail;
    if (w)
    {   g = negate(g);
        nil = C_nil;
        if (exception_pending()) goto fail;
    }
    g = quot2(numerator(b), g);     /* denominator of result will be +ve */
    nil = C_nil;
    if (exception_pending()) goto fail;
    a = times2(a, denominator(b));
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = make_ratio(a, g);
    popv(3);
    return w;
fail:
    popv(3);
    return nil;
#undef a
#undef b
#undef g
}

static Lisp_Object quotic(Lisp_Object a, Lisp_Object b)
/*
 * Used for all cases of xxx/<p+iq>.  This is coded in a fairly naive
 * way, multiplying both numerator and denominator of what will end up
 * as the result by the complex conjugate of b.  If floating point
 * arithmetic is used this can lead to grossly premature overflow.  For
 * the moment I will ignore that miserable fact
 */
{
    Lisp_Object u, v, nil;
    push2(a, b);
#define b stack[0]
#define a stack[-1]
/*
 *   a / (p + iq) is computed as follows:
 *     (a * (p - iq)) / (p^2 + q^2)
 */
    u = negate(imag_part(b));
    nil = C_nil;
    if (exception_pending()) goto fail;
    u = make_complex(real_part(b), u);
    nil = C_nil;
    if (exception_pending()) goto fail;
    a = times2(a, u);
    u = real_part(b);
    u = times2(u, u);
    nil = C_nil;
    if (exception_pending()) goto fail;
    v = imag_part(b);
    b = u;
    u = times2(v, v);
    nil = C_nil;
    if (exception_pending()) goto fail;
    u = plus2(u, b);
    nil = C_nil;
    if (exception_pending()) goto fail;
    v = a;
    popv(2);
    return quot2(v, u);
#undef a
#undef b
fail:
    popv(2);
    return nil;
}
#endif

static Lisp_Object quotif(Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(b);
    if (d == 0.0) return aerror2("bad arg for quotient", a, b);
    d = (double)int_of_fixnum(a) / d;
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

#ifdef COMMON
static Lisp_Object quotsi(Lisp_Object a, Lisp_Object b)
{
    Float_union aa;
    if (b == fixnum_of_int(0)) return aerror2("bad arg for quotient", a, b);
    aa.i = a - TAG_SFLOAT;
    aa.f = (float) (aa.f / (float)int_of_fixnum(b));
    return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
}

static Lisp_Object quotsb(Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(b);
    if (d == 0.0) return aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / d;
    return make_sfloat(d);
}

#define quotsr(a, b) quotsb(a, b)

#define quotsc(a, b) quotic(a, b)
#endif

static Lisp_Object quotsf(Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(b);
    if (d == 0.0) return aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / d;
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

Lisp_Object quotbn(Lisp_Object a, int32_t n)
/*
 * Divide a bignum by an integer, where the integer is (by now)
 * a natural C int32_t but limited to 31 not 32 bits active.  I.e.
 * this can be used when dividing by a fixnum or by dividing by
 * a one-word bignum.  I will not call this with n=-1, which would
 * be the one case where it could cause the quotient to be bigger
 * than the dividend.  Leaves nwork set to the remainder.
 */
{
    Lisp_Object nil;
    int sign;
    int32_t lena = (bignum_length(a)-CELL)/4-1, i, lenc, lenx;
    uint32_t carry;
    if (lena == 0)      /* one-word bignum as numerator */
    {   int32_t p = (int32_t)bignum_digits(a)[0], w;
        nil = C_nil;    /* So I can access nwork */
        nwork = p % n;
/*
 * C does not define what happens on non-exact division involving
 * negative quantities, so I adjust things here so that the remainder
 * has the sign that I want and the division I do is exact.
 */
        if (p < 0)
        {   if (nwork > 0) nwork -= n;
        }
        else if (nwork < 0) nwork += n;
/* Remainder should be correct (with correct sign) by now, regardless */
        p = (p - nwork) / n;
        w = p & fix_mask;
        if (w == 0 || w == fix_mask) return fixnum_of_int(p);
        else return make_one_word_bignum(p);
    }
    else if (lena == 1)
/*
 * I treat division of a 2-word bignum by a fixnum or 1-word bignum as
 * a special case since it can lead to a fixnum result - if the divisor is
 * just one word long and the dividend is 3 or more words I would
 * certainly have a bignum result.  Thus by separating off the code here
 * I (a) remove the need for test relating to big- to fixnum conversion
 * later on and (b) avoid allocating heap in this tolerably common case
 * when sometimes I will not need to.
 */
    {   uint32_t a0 = bignum_digits(a)[0];
        int32_t a1 = (int32_t)bignum_digits(a)[1];
        if (a1 < 0)
        {   sign = 3;
            if (a0 == 0) a1 = -a1;
            else
            {   a0 = clear_top_bit(-(int32_t)a0);
                a1 = ~a1;
            }
        }
        else sign = 0;
        if (n < 0) sign ^= 1, n = -n;
        if (a1 < n) /* result can be calculated in one word - good! */
        {   uint32_t q, r;
            Ddivide(r, q, (uint32_t)a1, a0, n);
            if ((sign & 2) != 0) r = -(int32_t)r;
            nil = C_nil;
            nwork = r;
            a0 = q;
            if (a0 == 0) return fixnum_of_int(0);
            if ((sign & 1) == 0)
            {   if ((a0 & fix_mask) == 0) return fixnum_of_int(a0);
                else if ((a0 & 0x40000000) == 0)
                        return make_one_word_bignum(a0);
                else return make_two_word_bignum(0, a0);
            }
            a0 = -(int32_t)a0;
            if ((a0 & fix_mask) == fix_mask) return fixnum_of_int(a0);
            else if ((a0 & 0xc0000000U) == 0xc0000000U)
                    return make_one_word_bignum(a0);
            else return make_two_word_bignum(-1, clear_top_bit(a0));
        }
/*
 * here the quotient will involve exactly two digits.
 */
        else
        {   uint32_t q1, q0, r;
            Ddivide(r, q1, 0, (uint32_t)a1, n);
            Ddivide(r, q0, r, a0, n);
            if ((sign & 2) != 0) r = -(int32_t)r;
            nil = C_nil;
            nwork = r;
            if ((sign & 1) != 0)
            {   if (q0 == 0) q1 = -(int32_t)q1;
                else
                {   q1 = ~q1;
                    q0 = clear_top_bit(-(int32_t)q0);
                }
            }
            if (q1 == 0 && (q0 & 0x40000000) == 0)
                return make_one_word_bignum(q0);
            return make_two_word_bignum(q1, q0);
        }
    }     
/*
 * That has dealt with the special cases - now the input is a bignum
 * with at least 3 digits and the quotient will certainly be a bignum.
 * Start by allocating a workspace copy of the dividend.  negateb will
 * leave a a bignum, although it may change its length.
 */
    if ((int32_t)bignum_digits(a)[lena] < 0) a = negateb(a), sign = 3;
    else a = copyb(a), sign = 0;
    errexit();
    if (n < 0)
    {   sign ^= 1;
        n = -n;
    }
/*
 * Now both a and n have been made positive, and their original signs
 * have been recorded so that I can tidy up at the end.  The 1 bit in sign
 * tells me what sign the quotient will have, the 2 bit gives the sign
 * for the remainder.
 */
    lena = (bignum_length(a)-CELL)/4;
    carry = 0;
    for (i=lena-1; i>=0; i--)
        Ddivide(carry, bignum_digits(a)[i], carry, bignum_digits(a)[i], n);
    if ((sign & 2) != 0) carry = -(int32_t)carry;
    nil = C_nil;
    nwork = carry;                  /* leave remainder available to caller */
    lena--;
    while (bignum_digits(a)[lena] == 0) lena--;
    if ((bignum_digits(a)[lena] & 0x40000000) != 0) lena++;
    if ((sign & 1) != 0)            /* quotient will be negative */
    {   carry = 0xffffffffU;
        for (i=0; i<lena; i++)
        {   carry = clear_top_bit(~bignum_digits(a)[i]) + top_bit(carry);
            bignum_digits(a)[i] = clear_top_bit(carry);
        }
        carry = ~bignum_digits(a)[i] + top_bit(carry);
        if (carry == -1 && (bignum_digits(a)[i-1] & 0x40000000) != 0)
        {   bignum_digits(a)[lena] = 0;
            lena--;
            bignum_digits(a)[i-1] |= ~0x7fffffff;
        }
        else bignum_digits(a)[i] = carry;
    }
/* I need to free up some space here, I guess */
    lenx = (bignum_length(a)-CELL)/4;
    if (SIXTY_FOUR_BIT)
    {   lenx = (lenx + 1) & ~1;
        lenc = (lena + 2) & ~1;
    }
    else
    {   lenx |= 1;  /* round up to allow for allocation in doublewords */
        lenc = (lena+1) | 1;
    }
    if (lenc != lenx) /* space to discard? */
        *(Header *)&bignum_digits(a)[lenc] = make_bighdr(lenx-lenc);
    numhdr(a) = make_bighdr(lena+1+CELL/4);
    return a;
}

Lisp_Object quotbn1(Lisp_Object a, int32_t n)
/*
 * Divide a bignum by an integer, where the integer is (by now)
 * a natural C int32_t but limited to 31 not 32 bits active.  I.e.
 * this can be used when dividing by a fixnum or by dividing by
 * a one-word bignum.  I will not call this with n=-1, which would
 * be the one case where it could cause the quotient to be bigger
 * than the dividend.  Leaves nwork set to the remainder.
 * This version is JUST the same as quotbn() except that it does not
 * hand back a useful quotient - it is intended for use when only
 * the remainder is wanted. For consistency I leave that where quotbn() did.
 */
{
    Lisp_Object nil;
    int sign;
    int32_t lena = (bignum_length(a)-CELL)/4-1, i;
    uint32_t carry;
    if (lena == 0)      /* one-word bignum as numerator */
    {   int32_t p = (int32_t)bignum_digits(a)[0];
        nil = C_nil;    /* So I can access nwork */
        nwork = p % n;
/*
 * C does not define what happens on non-exact division involving
 * negative quantities, so I adjust things here so that the remainder
 * has the sign that I want and the division I do is exact.
 */
        if (p < 0)
        {   if (nwork > 0) nwork -= n;
        }
        else if (nwork < 0) nwork += n;
/* Remainder should be correct (with correct sign) by now, regardless */
        else return nil;
    }
    else if (lena == 1)
/*
 * I treat division of a 2-word bignum by a fixnum or 1-word bignum as
 * a special case since it can lead to a fixnum result - if the divisor is
 * just one word long and the dividend is 3 or more words I would
 * certainly have a bignum result.  Thus by separating off the code here
 * I (a) remove the need for test relating to big- to fixnum conversion
 * later on and (b) avoid allocating heap in this tolerably common case
 * when sometimes I will not need to.
 */
    {   uint32_t a0 = bignum_digits(a)[0];
        int32_t a1 = (int32_t)bignum_digits(a)[1];
        if (a1 < 0)
        {   sign = 3;
            if (a0 == 0) a1 = -a1;
            else
            {   a0 = clear_top_bit(-(int32_t)a0);
                a1 = ~a1;
            }
        }
        else sign = 0;
        if (n < 0) sign ^= 1, n = -n;
        if (a1 < n) /* result can be calculated in one word - good! */
        {   uint32_t q, r;
            Ddivide(r, q, (uint32_t)a1, a0, n);
            if ((sign & 2) != 0) r = -(int32_t)r;
            nil = C_nil;
            nwork = r;
            return nil;
        }
/*
 * here the quotient will involve two digits.
 */
        else
        {   uint32_t q1, q0, r;
            Ddivide(r, q1, 0, (uint32_t)a1, n);
            Ddivide(r, q0, r, a0, n);
            if ((sign & 2) != 0) r = -(int32_t)r;
            nil = C_nil;
            nwork = r;
            return nil;
        }
    }     
/*
 * That has dealt with the special cases - now the input is a bignum
 * with at least 3 digits and the quotient will certainly be a bignum.
 * Start by allocating a workspace copy of the dividend.  negateb will
 * leave a a bignum, although it may change its length.
 */
/*
 * Also note that I could fold the negateb() in with the division, and
 * thereby save allocating a big hunk of extra memory.
 */
    if ((int32_t)bignum_digits(a)[lena] < 0) a = negateb(a), sign = 3;
    else a = copyb(a), sign = 0;
    errexit();
    if (n < 0)
    {   sign ^= 1;
        n = -n;
    }
/*
 * Now both a and n have been made positive, and their original signs
 * have been recorded so that I can tidy up at the end.  The 1 bit in sign
 * tells me what sign the quotient will have, the 2 bit gives the sign
 * for the remainder.
 */
    lena = (bignum_length(a)-CELL)/4;
    carry = 0;
    for (i=lena-1; i>=0; i--)
        Ddivide(carry, bignum_digits(a)[i], carry, bignum_digits(a)[i], n);
    if ((sign & 2) != 0) carry = -(int32_t)carry;
    nil = C_nil;
    nwork = carry;                  /* leave remainder available to caller */
    return nil;
}

static Lisp_Object quotbi(Lisp_Object a, Lisp_Object b)
{
/*
 * dividing by 1 or -1 seems worth optimising.
 */
    if (b == fixnum_of_int(1)) return a;
    else if (b == fixnum_of_int(-1)) return negateb(a);
    else if (b == fixnum_of_int(0))
        return aerror2("bad arg for quotient", a, b);
    else return quotbn(a, int_of_fixnum(b));
}

#ifdef COMMON
#define quotbs(a, b) quotsb(a, b)
#endif

Lisp_Object quotbb(Lisp_Object a, Lisp_Object b)
/*
 * Divide one bignum by another.   This can compute the
 * remainder at the same time as the quotient, and leaves same around
 * in mv_2.  If it is not needed then setting up the remainder is
 * a cost - but usually a modest one (in context), so I think that
 * the simplification is worth-while.
 */
{
    Lisp_Object nil, olda;
    int sign;
    int32_t lena, lenb, lenc, lenx, i;
    uint32_t carry, scale, v1;
    Lisp_Object q, r;
/*
 * If I am dividing by a one-word bignum I can go a bit faster...
 */
    lenb = (bignum_length(b)-CELL-4)/4;
    if (lenb == 0)
    {   q = quotbn(a, bignum_digits(b)[0]);
        errexit();
/*
 * Now lots of frivolity packing up the remainder...
 */
        r = (Lisp_Object)(nwork & fix_mask);
        if ((int32_t)r == 0 || (int32_t)r == fix_mask)
            mv_2 = fixnum_of_int(nwork);
        else
        {   push(q);
            a = make_one_word_bignum(nwork);
            pop(q);
            errexit();
            mv_2 = a;
        }
        return q;
    }
/*
 * Convert to sign and magnitude representation
 */
    push2(a, b);
    lena = (bignum_length(a)-CELL-4)/4;
    if ((int32_t)bignum_digits(a)[lena] < 0)
    {   a = negateb(a);
        sign = 3;
    }
    else
    {   a = copyb(a);
        sign = 0;
    }
    pop(b);
    errexit();
    lena = (bignum_length(a)-CELL-4)/4;

    push(a);
    if ((int32_t)bignum_digits(b)[lenb] < 0)
    {   b = negateb(b);
/*
 * I MUST NOT do    lenb = (bignum_length(b)-CELL-4)/4;     here because the
 * negateb may have failed and therefore handed back junk rather than
 * a bignum.  E.g. an interrupt provoked by the user or a store-jam might
 * lead to a failure report here. So I must defer re-finding the length until
 * I have checked for exceptions.
 */
        sign ^= 1;
    }
    else b = copyb(b);
    pop2(a, olda);  /* original a, with original sign */
    errexit();
    lenb = (bignum_length(b)-CELL-4)/4;
/*
 * Now that the numbers are unsigned it could be that I can drop
 * a leading zero that had previously been necessary.  That could reveal
 * that I have a one-word divisor after all...
 */
    if (bignum_digits(b)[lenb] == 0) lenb--;
    if (lenb == 0)
    {   a = quotbn(a, bignum_digits(b)[0]);
        errexit();
        if ((sign & 2) != 0) nwork = -nwork;
        if ((sign & 1) != 0) a = negate(a);
        errexit();
        r = (Lisp_Object)(nwork & fix_mask);
        if (r == 0 || (int32_t)r == fix_mask) mv_2 = fixnum_of_int(nwork);
        else
        {   push(a);
            if (signed_overflow(nwork))
            {   if ((int32_t)nwork < 0)
                    b = make_two_word_bignum(-1, clear_top_bit(nwork));
                else b = make_two_word_bignum(0, nwork);
            }
            else b = make_one_word_bignum(nwork);
            pop(a);
            errexit();
            mv_2 = b;
        }
        return a;
    }
/*
 * Now the divisor is at least two digits long.
 */
    if (bignum_digits(a)[lena] == 0) lena--;
/*
 * I will take a special case when the lengths of the two numbers
 * match since in that case the quotient will be only one digit long.
 * Also after I have filtered the lena<=lenb cases out, and have treated
 * one-word cases of b specially I will know that the numerator a has
 * at least two digits.
 */
    if (lena < lenb)
    {   mv_2 = olda;
        return fixnum_of_int(0);
    }
    else if (lenb == lena)
    {   uint32_t p0 = bignum_digits(a)[lena-1], p1 = bignum_digits(a)[lena],
                   q0 = bignum_digits(b)[lenb-1], q1 = bignum_digits(b)[lena],
                   r0, r1, q, w, carry1;
/*
 * If the dividend is smaller than the divisor I can return zero right now.
 */
        if (p1 < q1 || (p1 == q1 && p0 < q0))
        {   mv_2 = olda;
            return fixnum_of_int(0);
        }
/*
 * I scale the divisor so that it will have its top bit set (top wrt the
 * 31 bit field that is in use, that is), and scale the top two digits
 * of the dividend to match.  The resulting values can then be divided to get
 * a pretty good estimate for the true quotient.  Note that the division on
 * the next line is UNSIGNED arithmetic.
 */
        scale = 0x80000000U / ((uint32_t)1 + q1);
        Dmultiply(carry, w, q0, scale, 0);
        Dmultiply(q, w, q1, scale, carry);
        q = w;
        Dmultiply(carry, w, p0, scale, 0);
        Dmultiply(carry, w, p1, scale, carry);
        if (carry == q) q = 0x7fffffff;
        else
        {   Ddivide(q, w, carry, w, q);
            q = w;
        }
/*
 * q is now my estimated quotient, based on a quick look at high digits.
 */
        Dmultiply(carry, w, q0, q, 0);
        r0 = w;
        Dmultiply(carry, w, q1, q, carry);
        r1 = w;
        r0 = r0 - p0;
        if ((int32_t)r0 < 0)
        {   r0 = clear_top_bit(r0);
            r1 = r1 - p1 - 1;
        }
        else r1 = r1 - p1;
/* /*
 * the next line is a cop-out for now - if my estimated quotient
 * was close enough to the true value than the residual I get here
 * ought to be fairly small - if it is not I have bungled.  Over several years
 * of testa and use I have not seen the disaster message triggered, but the
 * code should stay in until I can write the paragraph of comment that
 * should go here explaing why all is well...
 */
        if (carry != 0 && (int32_t)r1 < 0 &&
            carry != 1 && r1 != ~0x7fffffff)
        {
            err_printf("\n+++!!!+++ carry needed (line %d of \"%s\")\n",
                       __LINE__, __FILE__);
            my_exit(EXIT_FAILURE);
        }
/*
 * That obtained the remainder from (p1,p0)/(q1,q0) - now adjust q until
 * the remainder has the sign I want it to have.
 */
/* /* I do not look at carry here - I have a nasty suspicion that I should.. */
        while ((int32_t)r1 > 0 ||
               (r1 == 0 && r0 != 0))
        {   q--;
            r0 = r0 - q0;
            if ((int32_t)r0 < 0)
            {   r0 = clear_top_bit(r0);
                r1 = r1 - q1 - 1;
            }
            else r1 = r1 - q1;
        }
/*
 * Now q is (p1,p0)/(q1,q0), which is an over-estimate for the true
 * quotient, but by at worst 1.  Compute a proper full-length remainder
 * now, using the original unscaled input numbers.
 */
        carry = 0;
        carry1 = 0xffffffffU;
        for (i=0; i<=lena; i++)
        {   Dmultiply(carry, w, bignum_digits(b)[i], q, carry);
            carry1 = bignum_digits(a)[i] + clear_top_bit(~w) + top_bit(carry1);
            bignum_digits(a)[i] = clear_top_bit(carry1);
        }
        if ((int32_t)carry1 >= 0) /* need to correct it! */
        {   q--;
            for (i=0; i<=lena; i++)
            {   carry1 = bignum_digits(a)[i] + bignum_digits(b)[i] +
                         top_bit(carry1);
                bignum_digits(a)[i] = clear_top_bit(carry1);
            }
        }
/*
 * Now the quotient is correct - but since I want to hand back a neat
 * remainder I have more to do - I must convert the value stored in a
 * into a legitimate result, and store it in mv_2.
 */
        while (lena > 0 && bignum_digits(a)[lena] == 0) lena--;
        if ((bignum_digits(a)[lena] & 0x40000000) != 0) lena++;
        if (lena == 0)  /* Maybe fixnum remainder? */
        {   int32_t rr = bignum_digits(a)[0];
            if (rr != 0 && (sign & 2) != 0)
            {   rr = -rr;
                if ((rr & fix_mask) == fix_mask)
                {   mv_2 = fixnum_of_int(rr);
                    goto return_q;
                }
            }
            else if ((rr & fix_mask) == 0)
            {   mv_2 = fixnum_of_int(rr);
                goto return_q;
            }
        }
        if ((sign & 2) != 0)
        {   carry = 0xffffffffU;
            for (i=0; i<lena; i++)
            {   carry = clear_top_bit(~bignum_digits(a)[i]) + top_bit(carry);
                bignum_digits(a)[i] = clear_top_bit(carry);
            }
            carry = ~bignum_digits(a)[i] + top_bit(carry);
            bignum_digits(a)[i] = carry;
/*
 * if my remainder is -2^(31*n-1) then I need to shrink lena here, which
 * seems like a messy case to have to consider.
 */
            if (carry == -1 && (bignum_digits(a)[i-1] & 0x40000000) != 0)
            {   bignum_digits(a)[lena] = 0;
                lena--;
                bignum_digits(a)[i-1] |= ~0x7fffffff;
            }
        }
/*
 * Now tidy up the space that I am about to discard, so that it will not
 * upset the garbage collector.
 */
        lenx = (bignum_length(a)-CELL)/4;
        if (SIXTY_FOUR_BIT)
        {   lenx = (lenx+1) & ~1;
            lenc = (lena+2) & ~1;
        }
        else
        {   lenx |= 1;  /* round up to allow for allocation in doublewords */
            lenc = (lena+1) | 1;
        }
        if (lenc != lenx) /* space to discard? */
            *(Header *)&bignum_digits(a)[lenc] = make_bighdr(lenx-lenc);
        numhdr(a) = make_bighdr(lena+1+CELL/4);
        mv_2 = a;
    return_q:
        if (q != 0 && (sign & 1) != 0)
        {   q = -(int32_t)q;
            if ((q & fix_mask) == fix_mask) return fixnum_of_int(q);
            if ((q & 0x40000000) == 0)
                return make_two_word_bignum(-1, clear_top_bit(q));
        }
        else if ((q & fix_mask) == 0) return fixnum_of_int(q);
        else if ((q & 0x40000000) != 0) return make_two_word_bignum(0, q);
        return make_one_word_bignum(q);
    }
/*
 * Now both a and b have been made positive, and their original signs
 * have been recorded so that I can tidy up at the end.  The 1 bit in sign
 * tells me what sign the quotient will have, the 2 bit gives the sign
 * for the remainder.  Both a and b have been copied so it will be OK to
 * overwrite them in the process of doing the division.  The length of
 * a is strictly greater than that of b, which itself is at least 2 digits,
 * so this is a real case of long division, although the quotient may still
 * end up small (but non-zero).
 */

/*
 * I find a scale factor to multiply a and b by so that the leading digit of
 * the divisor is fairly large.  Again note that the arithmetic is UNSIGNED.
 */
    scale = 0x80000000U / ((uint32_t)1 + (uint32_t)bignum_digits(b)[lenb]);

    carry = 0;
    for (i=0; i<=lenb; i++)
        Dmultiply(carry, bignum_digits(b)[i],
                         bignum_digits(b)[i], scale, carry);
    v1 = bignum_digits(b)[lenb];

    carry = 0;
    for (i=0; i<=lena; i++)
        Dmultiply(carry, bignum_digits(a)[i],
                         bignum_digits(a)[i], scale, carry);
/*
 * The scaled value of the numerator a may involve an extra digit
 * beyond those that I have space for in the vector.  Hold this digit
 * in the variable 'carry'.  Note that scaling the divisor did NOT cause
 * it to change length.
 */

    while (lena >= lenb)
    {   uint32_t w, h0, h1, v2, u2, carry1, carry2, qq, rr;
        if (carry == v1)
        {   qq = 0x7fffffff;
            rr = carry + bignum_digits(a)[lena];
        }
        else
        {   Ddivide(rr, w, carry, bignum_digits(a)[lena], v1);
            qq = w;
        }
        v2 = bignum_digits(b)[lenb-1];
        Dmultiply(h1, h0, v2, qq, 0);
        u2 = bignum_digits(a)[lena-1];
        if (h1 > rr ||
            (h1 == rr && h0 > u2))
        {   qq--;
            h0 -= v2;
            if ((int32_t)h0 < 0)
            {   h0 = clear_top_bit(h0);
                h1--;
            }
            rr += v1;
            if (h1 > rr ||
                (h1 == rr && h0 > u2)) qq--;
        }
/*
 * Now subtract off q*b from a, up as far as lena.
 */
        carry1 = 0;
        carry2 = 0xffffffffU;
        for (i=0; i<=lenb; i++)
        {   Dmultiply(carry1, w, bignum_digits(b)[i], qq, carry1);
            carry2 = bignum_digits(a)[lena-lenb+i] +
                     clear_top_bit(~w) + top_bit(carry2);
            bignum_digits(a)[lena-lenb+i] = clear_top_bit(carry2);
        }
        carry2 = carry + clear_top_bit(~carry1) + top_bit(carry2);
        if ((int32_t)carry2 >= 0) /* overshot.. */
        {   qq--;
            carry2 = 0;
            for (i=0; i<=lenb; i++)
            {   carry2 = bignum_digits(a)[lena-lenb+i] +
                         bignum_digits(b)[i] + top_bit(carry2);
                bignum_digits(a)[lena-lenb+i] = clear_top_bit(carry2);
            }
        }
        carry = bignum_digits(a)[lena];
        bignum_digits(a)[lena] = qq; /* good place to store the quotient */
        lena--;
    }

    lena = (bignum_length(a)-CELL-4)/4;

/*
 * Now the quotient is in the top digits of a, and the remainder is left
 * (scaled up) in the low bit (plus carry)
 */
    bignum_digits(b)[lenb] = carry/scale;
    carry = carry%scale;
    for (i=lenb-1; i>=0; i--)
        Ddivide(carry, bignum_digits(b)[i],
                       carry, bignum_digits(a)[i], scale);
    if (carry != 0)
    {   err_printf("+++!!!+++ Incorrect unscaling line %d file \"%s\" (%ld)\n",
                 __LINE__, __FILE__, (long)carry);
        my_exit(EXIT_FAILURE);
    }
    for (i=0; i<=lena-lenb; i++)
        bignum_digits(a)[i] = bignum_digits(a)[i+lenb];
    for (;i < lena; i++) bignum_digits(a)[i] = 0;
    lena = lena - lenb;
    while (bignum_digits(a)[lena] == 0) lena--;
/*
 * the above loop terminates properly since the quotient will be non-zero,
 * which in turn is because I was dividing p by q where p had strictly
 * more digits than q, and was hence strictly greater than q.
 */
    if ((bignum_digits(a)[lena] & 0x40000000) != 0) lena++;
    if ((sign & 1) != 0)            /* quotient will be negative */
    {   carry = 0xffffffffU;
        for (i=0; i<lena; i++)
        {   carry = clear_top_bit(~bignum_digits(a)[i]) + top_bit(carry);
            bignum_digits(a)[i] = clear_top_bit(carry);
        }
        carry = ~bignum_digits(a)[i] + top_bit(carry);
        if (carry == -1 && (bignum_digits(a)[i-1] & 0x40000000) != 0)
        {   bignum_digits(a)[lena] = 0;
            lena--;
            bignum_digits(a)[i-1] |= ~0x7fffffff;
        }
        else bignum_digits(a)[i] = carry;
    }
    lenx = (bignum_length(a)-CELL)/4;
    if (SIXTY_FOUR_BIT)
    {   lenx = (lenx+1) & ~1;  /* round up to allow for allocation in doublewords */
        lenc = (lena+2) & ~1;
    }
    else
    {   lenx |= 1;  /* round up to allow for allocation in doublewords */
        lenc = (lena+1) | 1;
    }
    if (lenc != lenx) /* space to discard? */
        *(Header *)&bignum_digits(a)[lenc] = make_bighdr(lenx-lenc);
    numhdr(a) = make_bighdr(lena+1+CELL/4);
    if (lena == 0)
    {   int32_t d = bignum_digits(a)[0];
        int32_t x = d & fix_mask;
        if (x == 0 || x == fix_mask) a = fixnum_of_int(d);
    }
/*
 * Here I need to tidy up the discarded space that could otherwise
 * kill the poor old garbage collector..
 */
    while (lenb >= 0 && bignum_digits(b)[lenb] == 0) lenb--;
    if (lenb < 0) mv_2 = fixnum_of_int(0); /* hah - zero remainder! */
    else
    {
        if ((bignum_digits(b)[lenb] & 0x40000000) != 0) lenb++;
        if ((sign & 2) != 0)    /* need to negate the remainder */
        {   carry = 0xffffffffU;
            for (i=0; i<lenb; i++)
            {   carry = clear_top_bit(~bignum_digits(b)[i]) + top_bit(carry);
                bignum_digits(b)[i] = clear_top_bit(carry);
            }
            carry = ~bignum_digits(b)[i] + top_bit(carry);
            if (carry == -1 && (bignum_digits(b)[i-1] & 0x40000000) != 0)
            {   bignum_digits(b)[lenb] = 0;
                lenb--;
                bignum_digits(b)[i-1] |= ~0x7fffffff;
            }
            else bignum_digits(b)[i] = carry;
        }
        lenx = (bignum_length(b)-CELL)/4;
        if (SIXTY_FOUR_BIT)
        {   lenx = (lenx+1) & ~1;  /* round up to allow for allocation in doublewords */
            lenc = (lenb+2) & ~1;
        }
        else
        {   lenx |= 1;  /* round up to allow for allocation in doublewords */
            lenc = (lenb+1) | 1;
        }
        if (lenc != lenx) /* space to discard? */
            *(Header *)&bignum_digits(b)[lenc] = make_bighdr(lenx-lenc);
        numhdr(b) = make_bighdr(lenb+1+CELL/4);
        mv_2 = b;
        if (lenb == 0)
        {   int32_t r1, rr;
            rr = bignum_digits(b)[0];
            r1 = rr & fix_mask;
            if (r1 == 0 || r1 == fix_mask) mv_2 = fixnum_of_int(rr);
        }
    }
    return a;
}

#ifdef COMMON
#define quotbr(a, b) quotir(a, b)

#define quotbc(a, b) quotic(a, b)
#endif

#define quotbf(a, b) quotsf(a, b)

#ifdef COMMON
static Lisp_Object quotri(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object w, nil;
    if (b == fixnum_of_int(1)) return a;
    else if (b == fixnum_of_int(0))
        return aerror2("bad arg for quotient", a, b);
    push3(a, b, C_nil);
#define g   stack[0]
#define b   stack[-1]
#define a   stack[-2]
    g = gcd(b, numerator(a));
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = minusp(b);
    nil = C_nil;
    if (exception_pending()) goto fail;
    if (w)
    {   g = negate(g);      /* ensure denominator is +ve */
        nil = C_nil;
        if (exception_pending()) goto fail;
    }
    b = quot2(b, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    g = quot2(numerator(a), g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    a = times2(b, denominator(a));
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = make_ratio(g, a);
    popv(3);
    return w;
fail:
    popv(3);
    return nil;
#undef a
#undef b
#undef g
}

#define quotrs(a, b) quotsb(a, b)

#define quotrb(a, b) quotib(a, b)

static Lisp_Object quotrr(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object w, nil;
    push5(numerator(a), denominator(a),
          denominator(b), numerator(b), /* NB switched order */
          C_nil);
#define g   stack[0]
#define db  stack[-1]
#define nb  stack[-2]
#define da  stack[-3]
#define na  stack[-4]
    g = gcd(na, db);
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = minusp(db);
    nil = C_nil;
    if (exception_pending()) goto fail;
    if (w)
    {   g = negate(g);
        nil = C_nil;
        if (exception_pending()) goto fail;
    }
    na = quot2(na, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    db = quot2(db, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    g = gcd(nb, da);
    if (exception_pending()) goto fail;
    nil = C_nil;
    nb = quot2(nb, g);
    if (exception_pending()) goto fail;
    da = quot2(da, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    na = times2(na, nb);
    nil = C_nil;
    if (exception_pending()) goto fail;
    da = times2(da, db);
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = make_ratio(na, da);
    popv(5);
    return w;
fail:
    popv(5);
    return nil;
#undef g
#undef db
#undef nb
#undef da
#undef na
}

#define quotrc(a, b) quotic(a, b)

#define quotrf(a, b) quotsf(a, b)

static Lisp_Object quotci(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object r = real_part(a), i = imag_part(a), nil;
    if (b == fixnum_of_int(0)) return aerror2("bad arg for quotient", a, b);
    push2(b, r);
    i = quot2(i, b);
    pop2(r, b);
    errexit();
    push(i);
    r = quot2(r, b);
    pop(i);
    errexit();
    return make_complex(r, i);
}

#define quotcs(a, b) quotci(a, b)

#define quotcb(a, b) quotci(a, b)

#define quotcr(a, b) quotci(a, b)

#define quotcc(a, b) quotic(a, b)

#define quotcf(a, b) quotci(a, b)
#endif

static Lisp_Object quotfi(Lisp_Object a, Lisp_Object b)
{
    double d;
    if (b == fixnum_of_int(0)) return aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / (double)int_of_fixnum(b);
    return make_boxfloat(d, type_of_header(flthdr(a)));
}

static Lisp_Object quotfs(Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(b);
    if (d == 0.0) return aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / d;
    return make_boxfloat(d, type_of_header(flthdr(a)));
}

#define quotfb(a, b) quotfs(a, b)

#ifdef COMMON
#define quotfr(a, b) quotfs(a, b)

#define quotfc(a, b) quotic(a, b)
#endif

static Lisp_Object quotff(Lisp_Object a, Lisp_Object b)
{
#ifdef COMMON
    int32_t ha = type_of_header(flthdr(a)), hb = type_of_header(flthdr(b));
#endif
    double d = float_of_number(b);
    if (d == 0.0) return aerror2("bad arg for quotient", a, b);
    d = float_of_number(a) / d;
#ifdef COMMON
    if (ha == TYPE_LONG_FLOAT || hb == TYPE_LONG_FLOAT)
        ha = TYPE_LONG_FLOAT;
    else if (ha == TYPE_DOUBLE_FLOAT || hb == TYPE_DOUBLE_FLOAT)
        ha = TYPE_DOUBLE_FLOAT;
    else ha = TYPE_SINGLE_FLOAT;
    return make_boxfloat(d, ha);
#else
    return make_boxfloat(d, TYPE_DOUBLE_FLOAT);
#endif
}

Lisp_Object quot2(Lisp_Object a, Lisp_Object b)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
/*
 * This is where fixnum / fixnum arithmetic happens - the case I most want to
 * make efficient.
 */
            if (b == fixnum_of_int(0))
                return aerror2("bad arg for quotient", a, b);
            else
            {   int32_t r, aa, bb;
                aa = int_of_fixnum(a);
                bb = int_of_fixnum(b);
/* calculate remainder and force its sign to be correct */
                r = aa % bb;
                if (aa < 0)
                {   if (r > 0) r -= bb;
                }
                else if (r < 0) r += bb;
/* then the division can be an exact one, as here */
                r = (aa - r)/bb;
/*
 * the only case where dividing one fixnum by another can lead to
 * a bignum result is (-0x08000000/(-1)) which JUST overflows.
 */
                if (r != 0x08000000) return fixnum_of_int(r);
                else return make_one_word_bignum(r);
            }
#ifdef COMMON
    case TAG_SFLOAT:
            return quotis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return quotib(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return quotir(a, b);
        case TYPE_COMPLEX_NUM:
                return quotic(a, b);
#endif
        default:
                return aerror1("bad arg for quotient",  b);
                }
            }
    case TAG_BOXFLOAT:
            return quotif(a, b);
    default:
            return aerror1("bad arg for quotient",  b);
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return quotsi(a, b);
    case TAG_SFLOAT:
            {   Float_union aa, bb;
                aa.i = a - TAG_SFLOAT;
                bb.i = b - TAG_SFLOAT;
                aa.f = (float) (aa.f / bb.f);
                return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
            }
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return quotsb(a, b);
        case TYPE_RATNUM:
                return quotsr(a, b);
        case TYPE_COMPLEX_NUM:
                return quotsc(a, b);
        default:
                return aerror1("bad arg for quotient",  b);
                }
            }
    case TAG_BOXFLOAT:
            return quotsf(a, b);
    default:
            return aerror1("bad arg for quotient",  b);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return quotbi(a, b);
#ifdef COMMON
            case TAG_SFLOAT:
                    return quotbs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return quotbb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return quotbr(a, b);
                case TYPE_COMPLEX_NUM:
                        return quotbc(a, b);
#endif
                default:
                        return aerror1("bad arg for quotient",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return quotbf(a, b);
            default:
                    return aerror1("bad arg for quotient",  b);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return quotri(a, b);
            case TAG_SFLOAT:
                    return quotrs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return quotrb(a, b);
                case TYPE_RATNUM:
                        return quotrr(a, b);
                case TYPE_COMPLEX_NUM:
                        return quotrc(a, b);
                default:
                        return aerror1("bad arg for quotient",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return quotrf(a, b);
            default:
                    return aerror1("bad arg for quotient",  b);
                }
    case TYPE_COMPLEX_NUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return quotci(a, b);
            case TAG_SFLOAT:
                    return quotcs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return quotcb(a, b);
                case TYPE_RATNUM:
                        return quotcr(a, b);
                case TYPE_COMPLEX_NUM:
                        return quotcc(a, b);
                default:
                        return aerror1("bad arg for quotient",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return quotcf(a, b);
            default:
                    return aerror1("bad arg for quotient",  b);
                }
#endif
    default:    return aerror1("bad arg for quotient",  a);
            }
        }
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return quotfi(a, b);
#ifdef COMMON
    case TAG_SFLOAT:
            return quotfs(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return quotfb(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return quotfr(a, b);
        case TYPE_COMPLEX_NUM:
                return quotfc(a, b);
#endif
        default:
                return aerror1("bad arg for quotient",  b);
                }
            }
    case TAG_BOXFLOAT:
            return quotff(a, b);
    default:
            return aerror1("bad arg for quotient",  b);
        }
default:
        return aerror1("bad arg for quotient",  a);
    }
}

#ifdef COMMON

/*
 * The above version of quot2 is as required for the Standard Lisp QUOTIENT
 * function, and it is called from various internal places in CSL/CCL, eg
 * from within the code for TRUNCATE. Next I have something that will be very
 * similar in behaviour, but which turns quotients of integers into
 * rational numbers when that is necessary.
 */

/***** Not reconstructed yet!! */

Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
/*
 * This is where fixnum / fixnum arithmetic happens - the case I most want to
 * make efficient.
 */
            if (b == fixnum_of_int(0))
                return aerror2("bad arg for /", a, b);
            else
            {   int32_t r, aa, bb, w;
                aa = int_of_fixnum(a);
                bb = int_of_fixnum(b);
                if (bb < 0) aa = -aa, bb = -bb;
                r = aa % bb;
                if (r == 0)   /* Exact division case */
                {   r = aa/bb;
/*
 * the only case where dividing one fixnum by another can lead to
 * a bignum result is (-0x08000000/(-1)) which JUST overflows.
 */
                    if (r != 0x08000000) return fixnum_of_int(r);
                    else return make_one_word_bignum(r);
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
#ifdef COMMON
    case TAG_SFLOAT:
            return quotis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return CLquotib(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return quotir(a, b);
        case TYPE_COMPLEX_NUM:
                return quotic(a, b);
#endif
        default:
                return aerror1("bad arg for /",  b);
                }
            }
    case TAG_BOXFLOAT:
            return quotif(a, b);
    default:
            return aerror1("bad arg for /",  b);
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return quotsi(a, b);
    case TAG_SFLOAT:
            {   Float_union aa, bb;
                aa.i = a - TAG_SFLOAT;
                bb.i = b - TAG_SFLOAT;
                aa.f = (float) (aa.f / bb.f);
                return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
            }
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return quotsb(a, b);
        case TYPE_RATNUM:
                return quotsr(a, b);
        case TYPE_COMPLEX_NUM:
                return quotsc(a, b);
        default:
                return aerror1("bad arg for /",  b);
                }
            }
    case TAG_BOXFLOAT:
            return quotsf(a, b);
    default:
            return aerror1("bad arg for /",  b);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return CLquotbi(a, b);
#ifdef COMMON
            case TAG_SFLOAT:
                    return quotbs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return CLquotbb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return quotbr(a, b);
                case TYPE_COMPLEX_NUM:
                        return quotbc(a, b);
#endif
                default:
                        return aerror1("bad arg for /",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return quotbf(a, b);
            default:
                    return aerror1("bad arg for /",  b);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return quotri(a, b);
            case TAG_SFLOAT:
                    return quotrs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return quotrb(a, b);
                case TYPE_RATNUM:
                        return quotrr(a, b);
                case TYPE_COMPLEX_NUM:
                        return quotrc(a, b);
                default:
                        return aerror1("bad arg for /",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return quotrf(a, b);
            default:
                    return aerror1("bad arg for /",  b);
                }
    case TYPE_COMPLEX_NUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return quotci(a, b);
            case TAG_SFLOAT:
                    return quotcs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return quotcb(a, b);
                case TYPE_RATNUM:
                        return quotcr(a, b);
                case TYPE_COMPLEX_NUM:
                        return quotcc(a, b);
                default:
                        return aerror1("bad arg for /",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return quotcf(a, b);
            default:
                    return aerror1("bad arg for /",  b);
                }
#endif
    default:    return aerror1("bad arg for /",  a);
            }
        }
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return quotfi(a, b);
#ifdef COMMON
    case TAG_SFLOAT:
            return quotfs(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return quotfb(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return quotfr(a, b);
        case TYPE_COMPLEX_NUM:
                return quotfc(a, b);
#endif
        default:
                return aerror1("bad arg for /",  b);
                }
            }
    case TAG_BOXFLOAT:
            return quotff(a, b);
    default:
            return aerror1("bad arg for /",  b);
        }
default:
        return aerror1("bad arg for /",  a);
    }
}

#endif

/* end of arith03.c */
