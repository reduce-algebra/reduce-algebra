/*  arith02.c                         Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Arithmetic functions.
 *        Multiplication of generic numbers
 *        and in particular a lot of bignum support.
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




/* Signature: 791ef456 24-May-2008 */

#include "headers.h"


/*
 * Now for multiplication
 */

/*
 * I provide symbols IMULTIPLY and IDIVIDE which can be asserted if the
 * corresponding routines have been provided elsewhere (e.g. in machine
 * code for extra speed)
 */

#ifndef IMULTIPLY

#ifdef HAVE_UINT64_T
/*
 * If I have 64-bit unsigneds available this function in not in fact needed
 * since a macro in arith.h arranges that the multiplication is done
 * in-line.  However this version is left here in the source code as
 * convenient documentation of what the function needs to do.
 */
 
uint32_t Imultiply(uint32_t *rlow, uint32_t a, uint32_t b, uint32_t c)
/*
 *          (result, *rlow) = a*b + c     as 62-bit product
 *
 *          rlow may well be the same as one of a, b or c so the
 *          assignment to *rlow must not be done until the calculation is
 *          complete.  Inputs a and b are 31-bit values (i.e. they have
 *          their top bit zero and are to be treated as positive value.
 *          c may use all 32 bits, but again is treated as unsigned.
 *          The result is computed and the low 31 bits placed in rlow,
 *          (the top bit of rlow will end up zero) and the top part
 *          of the result is returned.
 */
{
/* NB the value r could be int64_t or uint64_t - it does not matter */
    uint64_t r = (uint64_t)a*(uint64_t)b + (uint64_t)c;
    *rlow = (uint32_t)(r & 0x7fffffff);
    return (uint32_t)(r >> 31);
}


#else

uint32_t Imultiply(uint32_t *rlow, uint32_t a, uint32_t b, uint32_t c)
/*
 *          (result, *rlow) = a*b + c     as 62-bit product
 *
 * The code given here forms the produce by doing three single-precision
 * (16*16->32) multiplies and using shifts etc to glue the partial results
 * together.  This is slightly faster than the above (maybe simpler?) code
 * on at least some machines.
 */
{
    uint32_t ah, bh;
    uint32_t w0, w1, w2;
    ah = a >> 16;
/*
 * On some machines I know that multi-bit shifts are especially painful,
 * while on others it is nasty to access the literal value needed as a
 * mask here.  Hence I make some show of providing an alternative.
 */
    a &= 0xffff;
    bh = b >> 16;
    b &= 0xffff;
/*
 * At present I can not see any way of issuing any of these multiplies
 * any earlier, or of doing useful work between the times that I launch
 * them, or even delaying before I use their results.  This will be rather
 * sad on machines where multiplication could overlap with other operations.
 */
    w2 = ah*bh;
    w1 = (a + ah)*(b + bh);
    w0 = a*b;
/*
 * The largest exact result that can be computed by the next line (given
 * that a and b start off just 31 bit) is 0xfffd0002
 */
    w1 = (w1 - w2) - w0;  /* == (a*bh + b*ah) */
/*
 * I split into 30 bits in the lower word and 32 in the upper, so I have
 * 2 bits available for temporary carry effects in the lower part.
 */
    w2 = (w2 << 2) + (w1 >> 14) + (w0 >> 30) + (c >> 30);
    w1 &= 0x3fff;
    w0 = (c & 0x3fffffff) + (w0 & 0x3fffffffU) + (w1 << 16);
    w0 += ((w2 & 1) << 30);
    w2 = (w2 >> 1) + (w0 >> 31);
    *rlow = w0 & 0x7fffffffU;
    return w2;
}

#endif
#endif /* IMULTIPLY */

static Lisp_Object timesii(Lisp_Object a, Lisp_Object b)
/*
 * multiplying two fixnums together is much messier than adding them,
 * mainly because the result can easily be a two-word bignum
 */
{
    uint32_t aa = (uint32_t)int_of_fixnum(a),
             bb = (uint32_t)int_of_fixnum(b);
    uint32_t temp, low, high;
/*
 * Multiplication by 0 or by 1 is just possibly common enough to be worth
 * filtering out the following special cases.  Avoidance of the tedious
 * checks for overflow may make this useful even if Imultiply is very fast.
 */
    if (aa <= 1)
    {   if (aa == 0) return fixnum_of_int(0);
        else return b;
    }
    else if (bb <= 1)
    {   if (bb == 0) return fixnum_of_int(0);
        else return a;
    }
/*
 * I dump the low part of the product in temp then copy to a variable low
 * because temp has to have its address taken and so is not a candidate for
 * living in a register.
 */
    Dmultiply(high, temp, clear_top_bit(aa), clear_top_bit(bb), 0);
/*
 * The result handed back here has only 31 bits active in its low part.
 */
    low = temp;
/*
 * The next two lines convert the unsigned product produced by Imultiply
 * into a signed product.
 */
    if ((int32_t)aa < 0) high -= bb;
    if ((int32_t)bb < 0) high -= aa;
    if ((high & 0x40000000) == 0) high = clear_top_bit(high);
    else high = set_top_bit(high);
    if (high == 0 && (low & 0x40000000) == 0)
    {   /* one word positive result */
        if (low <= 0x07ffffff) return fixnum_of_int(low);
        else return make_one_word_bignum(low);
    }
    else if (high == -1 && (low & 0x40000000) != 0)
    {   /* one word negative result */
        low = set_top_bit(low);
        if ((low & fix_mask) == fix_mask) return fixnum_of_int(low);
        else return make_one_word_bignum(low);
    }
    else return make_two_word_bignum(high, low);
}

#ifdef COMMON
static Lisp_Object timesis(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    bb.f = (float) ((float)int_of_fixnum(a) * bb.f);
    return (bb.i & ~(int32_t)0xf) + TAG_SFLOAT;
}
#endif

/*
 * This code has existed since around 1990, but in January 2008 a bug
 * surfaced relating to cases such as (-2)*(2^61-1) where the top digit of the
 * bignum is close to overflowing and so needing an additional word.
 * The ability of bugs to persist in code that is notionally simple is
 * something to remind oneself about constantly!
 */

static Lisp_Object timesib(Lisp_Object a, Lisp_Object b)
{
    int32_t aa = int_of_fixnum(a), lenb, i;
    uint32_t carry, ms_dig, w;
    Lisp_Object c, nil;
/*
 * I will split off the (easy) cases of the fixnum being -1, 0 or 1.
 */
    if (aa == 0) return fixnum_of_int(0);
    else if (aa == 1) return b;
    else if (aa == -1) return negateb(b);
    lenb = bignum_length(b);
    push(b);
    c = getvector(TAG_NUMBERS, TYPE_BIGNUM, lenb);
    pop(b);
    errexit();
    lenb = (lenb-CELL)/4;
    if (aa < 0)
    {   aa = -aa;
        carry = 0xffffffffU;
        for (i=0; i<lenb-1; i++)
        {   carry = clear_top_bit(~bignum_digits(b)[i]) + top_bit(carry);
            bignum_digits(c)[i] = clear_top_bit(carry);
        }
/*
 * I do the most significant digit separately.
 */
        carry = ~bignum_digits(b)[i] + top_bit(carry);
/*
 * there is a special case needed here - if b started off as a number
 * like 0xc0000000,0,0,0 then negating it would call for extension of
 * the bignum c (this is the usual assymetry in the range of twos-
 * complement numbers).  But if I detect that case specially I can
 * observe that the ONLY case where negation overflows is where the
 * negated value is exactly a power of 2 such .. an easy thing to
 * multiply a by!  Furthermore the power of two involved is known to
 * be 30 mod 31.
 */
        if (carry == 0x40000000)
        {   bignum_digits(c)[i] = (aa & 1) << 30;
            aa = aa >> 1;
            goto extend_by_one_word;
        }
        if ((carry & 0x40000000) != 0) carry = set_top_bit(carry);
        bignum_digits(c)[i] = carry;
    }
    else
    {   for (i=0; i<lenb; i++) bignum_digits(c)[i] = bignum_digits(b)[i];
    }
/*
 * Now c is a copy of b (negated if necessary) and I just want to
 * multiply it by the positive value a.  This is the heart of the
 * procedure.  Re-write Imultiply in assembly code if you want it
 * to go faster.  See the top of this file for a portable sample
 * implementation of Imultiply, which gives back a result as a pair
 * of 31-bit values. But note that if the computer has been marked as
 * supporting a 64-bit integer data-type then Imultiply macro-expands
 * into code that uses 64-bit intermediate values and so that should
 * go quote fast enough without assembly code.
 */
    carry = 0;
/*
 * here aa is > 0, and a fortiori the 0x80000000 bit of aa is clear,
 * so I do not have to worry about the difference between 31 and 32
 * bit values for aa.
 */
    for (i=0; i<lenb-1; i++)
        Dmultiply(carry, bignum_digits(c)[i], bignum_digits(c)[i],
                          (uint32_t)aa, carry);
    ms_dig = bignum_digits(c)[i];
    Dmultiply(carry, w, clear_top_bit(ms_dig), (uint32_t)aa, carry);
/*
 * After forming the product to (lenb) digits I need to see if there
 * is any overflow. Calculate what the next digit would be, sign
 * extending into the 0x80000000 bit as necessary.
 */
    if ((carry & 0x40000000) != 0) carry = set_top_bit(carry);
    if (((int32_t)ms_dig) < 0) carry -= aa;
    aa = (int32_t)carry;
    if (aa == -1 && (w & 0x40000000) != 0)
    {   bignum_digits(c)[i] = set_top_bit(w);
        return c;
    }
    bignum_digits(c)[i] = w;
    if (aa == 0 && (w & 0x40000000) == 0) return c;
/*
 * drop through to extend the number by a word - note that because I
 * am multiplying by a fixnum it is only possible to have to expand by
 * just one word.
 */
extend_by_one_word:
    if ((SIXTY_FOUR_BIT && ((lenb & 1) != 0)) ||
       (!SIXTY_FOUR_BIT && ((lenb & 1) == 0)))
/*
 * Here there was a padder word that I can expand into.
 */
    {   bignum_digits(c)[lenb] = aa;
        numhdr(c) += pack_hdrlength(1);
        return c;
    }
/*
 * Need to allocate more space to grow into. I need to grow by just 4 bytes.
 */
    push(c);
    a = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4+4*lenb);
    pop(c);
    errexit();
    for (i=0; i<lenb; i++)
        bignum_digits(a)[i] = bignum_digits(c)[i];
    bignum_digits(a)[i] = aa;
    bignum_digits(a)[i+1] = 0;  /* the padder word */
    return a;
}

#ifdef COMMON
static Lisp_Object timesir(Lisp_Object a, Lisp_Object b)
/*
 * multiply integer (fixnum or bignum) by ratio.
 */
{
    Lisp_Object nil = C_nil;
    Lisp_Object w = nil;
    if (a == fixnum_of_int(0)) return a;
    else if (a == fixnum_of_int(1)) return b;
    push3(b, a, nil);
#define g   stack[0]
#define a   stack[-1]
#define b   stack[-2]
    g = gcd(a, denominator(b));
    nil = C_nil;
    if (exception_pending()) goto fail;
    a = quot2(a, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    g = quot2(denominator(b), g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    a = times2(a, numerator(b));
    nil = C_nil;
    if (exception_pending()) goto fail;
/*
 * make_ratio tidies things up if the denominator was exactly 1
 */
    w = make_ratio(a, g);
fail:
    popv(3);
    return w;
#undef a
#undef b
#undef g
}

static Lisp_Object timesic(Lisp_Object a, Lisp_Object b)
/*
 * multiply an arbitrary non-complex number by a complex one
 */
{
    Lisp_Object nil;
    Lisp_Object r = real_part(b), i = imag_part(b);
    push2(a, r);
    i = times2(a, i);
    pop2(r, a);
    errexit();
    push(i);
    r = times2(a, r);
    pop(i);
    errexit();
    return make_complex(r, i);
}
#endif

static Lisp_Object timesif(Lisp_Object a, Lisp_Object b)
{
    double d = (double)int_of_fixnum(a) * float_of_number(b);
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

#ifdef COMMON
#define timessi(a, b) timesis(b, a)

static Lisp_Object timessb(Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(a) * float_of_number(b);
    return make_sfloat(d);
}

#define timessr(a, b) timessb(a, b)

#define timessc(a, b) timesic(a, b)
#endif

static Lisp_Object timessf(Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(a) * float_of_number(b);
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

#define timesbi(a, b) timesib(b, a)

#ifdef COMMON
#define timesbs(a, b) timessb(b, a)
#endif

/*
 * Now for bignum multiplication - made more than comfortably complicated
 * by a desire to make it go fast for very big numbers.
 */

#ifndef KARATSUBA_CUTOFF
/*
 * I have conducted some experiments on one machine to find out what the
 * best cut-off value here is.  The exact value chosen is not very
 * critical, and the fancy techniques do not pay off until numbers get
 * a lot bigger than this length (which is expressed in units of 31-bit
 * words, i.e. about 10 decimals).  Anyone who wants may recompile with
 * alternative values to try to get the system fine-tuned for their
 * own computer - but I do not expect it to be possible to achieve much
 * by so doing.
 */
#define KARATSUBA_CUTOFF 12
#endif


static void long_times(uint32_t *c, uint32_t *a, uint32_t *b,
                       uint32_t *d, int32_t lena, int32_t lenb, int32_t lenc);

static void long_times1(uint32_t *c, uint32_t *a, uint32_t *b,
                        uint32_t *d, int32_t lena, int32_t lenb, int32_t lenc)
/*
 * Here both a and b are big, with lena <= lenb.  Split each into two chunks
 * of size (lenc/4), say (a1,a2) and (b1,b2), and compute each of
 *          a1*b1
 *          a2*b2
 *          (a1+a2)*(b1+b2)
 * where in the last case a1+a2 and b1+b2 can be computed keeping their
 * carry bits as k1 and k2 (so that a1+a2 and b1+b2 are restricted to
 * size lenb). The chunks can then be combined with a few additions and
 * subtractions to form the product that is really wanted.  If in fact a
 * was shorter than lenc/4 (so that after a is split up the top half is
 * all zero) I do things in a more straightforward way.  I require that on
 * entry to this code lenc<4 < lenb <= lenc/2.
 */
{
    int32_t h = lenc/4;   /* lenc must have been made even enough... */
    int32_t lena1 = lena - h;
    int32_t lenb1 = lenb - h;
    uint32_t carrya, carryb;
    int32_t i;
/*
 * if the top half of a would be all zero I go through a separate path,
 * doing just two subsidiary multiplications.
 */
    if (lena1 <= 0)
    {   long_times(c+h, a, b+h, d, lena, lenb-h, 2*h);
        for (i=0; i<h; i++) c[3*h+i] = 0;
        long_times(d, a, b, c, lena, h, 2*h);
        for (i=0; i<h; i++) c[i] = d[i];
        carrya = 0;
        for (;i<2*h; i++)
        {   uint32_t w = c[i] + d[i] + carrya;
            c[i] = clear_top_bit(w);
            carrya = w >> 31;
        }
        for (;carrya!=0;i++)
        {   uint32_t w = c[i] + 1;
            c[i] = clear_top_bit(w);
            carrya = w >> 31;
        }
        return;
    }
/*
 * form (a1+a2) and (b1+b2).
 */
    carrya = 0;
    for (i=0; i<h; i++)
    {   uint32_t w = a[i] + carrya;
        if (i < lena1) w += a[h+i];
        d[i] = clear_top_bit(w);
        carrya = w >> 31;
    }
    carryb = 0;
    for (i=0; i<h; i++)
    {   uint32_t w = b[i] + carryb;
        if (i < lenb1) w += b[h+i];
        d[h+i] = clear_top_bit(w);
        carryb = w >> 31;
    }
    long_times(c+h, d, d+h, c, h, h, 2*h);
/*
 * Adjust to allow for the cases of a1+a2 or b1+b2 overflowing
 * by a single bit.
 */
    c[3*h] = carrya & carryb;
    if (carrya != 0)
    {   carrya = 0;
        for (i=0; i<h; i++)
        {   uint32_t w = c[2*h+i] + d[h+i] + carrya;
            c[2*h+i] = clear_top_bit(w);
            carrya = w >> 31;
        }
    }
    if (carryb != 0)
    {   carryb = 0;
        for (i=0; i<h; i++)
        {   uint32_t w = c[2*h+i] + d[i] + carryb;
            c[2*h+i] = clear_top_bit(w);
            carryb = w >> 31;
        }
    }
    c[3*h] += carrya + carryb;
    for (i=1; i<h; i++) c[3*h+i] = 0;
/*
 * Now (a1+a2)*(b1+b2) should have been computed totally properly
 */
    for (i=0; i<h; i++) d[h+i] = 0;
/*
 * multiply out a1*b1, where note that a1 and b1 may be less long
 * than h, but not by much.
 */
    long_times(d, a+h, b+h, c, lena-h, lenb-h, 2*h);
    carrya = 0;
    for (i=0; i<2*h; i++)
    {   uint32_t w = c[2*h+i] + d[i] + carrya;
        c[2*h+i] = clear_top_bit(w);
        carrya = w >> 31;
    }
    carrya = 0;
    for (i=0; i<2*h; i++)
    {   uint32_t w = c[h+i] - d[i] - carrya;
        c[h+i] = clear_top_bit(w);
        carrya = w >> 31;
    }
    for (; carrya!=0 && i<3*h; i++)
    {   uint32_t w = c[h+i] - 1;
        c[h+i] = clear_top_bit(w);
        carrya = w >> 31;
    }
/*
 * multiply out a2*b2
 */
    long_times(d, a, b, c, h, h, 2*h);
    for (i=0; i<h; i++) c[i] = d[i];
    carrya = 0;
    for (; i<2*h; i++)
    {   uint32_t w = c[i] + d[i] + carrya;
        c[i] = clear_top_bit(w);
        carrya = w >> 31;
    }
    for (; carrya!=0 && i<4*h; i++)
    {   uint32_t w = c[i] + 1;
        c[i] = clear_top_bit(w);
        carrya = w >> 31;
    }
    carrya = 0;
    for (i=0; i<2*h; i++)
    {   uint32_t w = c[h+i] - d[i] - carrya;
        c[h+i] = clear_top_bit(w);
        carrya = w >> 31;
    }
    for (; carrya!=0 && i<3*h; i++)
    {   uint32_t w = c[h+i] - 1;
        c[h+i] = clear_top_bit(w);
        carrya = w >> 31;
    }
/*
 * The product is now complete
 */
}

static void long_times2(uint32_t *c, uint32_t *a, uint32_t *b,
                        int32_t lena, int32_t lenb, int32_t lenc)
/*
 * This case is standard old fashioned long multiplication.  Dump the
 * result into c.
 */
{
    int32_t i;
    for (i=0; i<lenc; i++) c[i] = 0;
    for (i=0; i<lena; i++)
    {   uint32_t carry = 0, da = a[i];
        int32_t j;
/*
 * When I multiply by (for instance) a high power of 2 there will
 * be plenty of zero digits in the number being worked with, and
 * so the test da!=0 will save something useful.
 */
        if (da != 0)
        {   for (j=0; j<lenb; j++)
            {   int32_t k = i + j;
                Dmultiply(carry, c[k], da, b[j],
/* NB the addition here is OK and fits into a 32-bit unsigned result */
                                  carry + c[k]);
            }
            c[i+j] = carry;
        }
    }
}

static void long_times(uint32_t *c, uint32_t *a, uint32_t *b,
                       uint32_t *d, int32_t lena, int32_t lenb, int32_t lenc)
/*
 * This decides if a multiplication is big enough to benefit from
 * decomposition a la Karatsuba.
 * In recursive entries through here out of long_times1() the numbers a
 * and b may have shrunk in ways that mean I need to reconsider the
 * precision to which I am working.  This must leave c filled out all
 * the way to lenc, with padding 0s if necessary.
 */
{
    if (lenb < lena)
    {   uint32_t *t1;
        int32_t t2;
        t1 = a; a = b; b = t1;
        t2 = lena; lena = lenb; lenb = t2;
    }
    if (4*lenb <= lenc) /* In this case I should shrink lenc a bit.. */
    {   int32_t newlenc = (lenb+1)/2;
        int k = 0;
        while (newlenc > KARATSUBA_CUTOFF)
        {   newlenc = (newlenc + 1)/2;
            k++;
        }
        while (k != 0)
        {   newlenc = 2*newlenc;
            k--;
        }
        newlenc = 4*newlenc;
        while (lenc > newlenc) c[--lenc] = 0;
    }
    if (lena > KARATSUBA_CUTOFF) long_times1(c, a, b, d, lena, lenb, lenc);
    else long_times2(c, a, b, lena, lenb, lenc);
}

static Lisp_Object timesbb(Lisp_Object a, Lisp_Object b)
/*
 * a and b are both guaranteed to be bignums when I call this
 * procedure.
 */
{
    int sign = 1;
    Lisp_Object c, d, nil;
    int32_t lena, lenb, lenc, i;
    lena = (bignum_length(a) - CELL)/4;
    lenb = (bignum_length(b) - CELL)/4;
    if (lena == 1 && lenb == 1)
/*
 * I am going to deem multiplication of two one-word bignums worthy of
 * a special case, since it is probably fairly common and it will be cheap
 * enough that avoiding overheads might matter.  I still need to split
 * off the signs, because Imultiply can only deal with 31-bit unsigned values.
 * One-word bignums each have value at least 2^27 (or else they would have
 * been represented as fixnums) so the result here will always be a two-word
 * bignum.
 */
    {   int32_t va = (int32_t)bignum_digits(a)[0],
              vb = (int32_t)bignum_digits(b)[0], vc;
        uint32_t vclow;
        if (va < 0)
        {   if (vb < 0) Dmultiply(vc, vclow, -va, -vb, 0);
            else
            {   Dmultiply(vc, vclow, -va, vb, 0);
                if (vclow == 0) vc = -vc;
                else
                {   vclow = clear_top_bit(-(int32_t)vclow);
                    vc = ~vc;
                }
            }
        }
        else if (vb < 0)
        {   Dmultiply(vc, vclow, va, -vb, 0);
            if (vclow == 0) vc = -vc;
            else
            {   vclow = clear_top_bit(-(int32_t)vclow);
                vc = ~vc;
            }
        }
        else Dmultiply(vc, vclow, va, vb, 0);
        return make_two_word_bignum(vc, vclow);
    }
/*
 * I take the absolute values of the two input values a and b,
 * recording what the eventual sign for the product will need to be.
 */
    if (((int32_t)bignum_digits(a)[lena-1]) < 0)
    {   sign = -sign;
        push(b);
/*
 * Negating a negative bignum can sometimes mean that it will
 * have to get longer (because of the twos complement assymmetry),
 * but can never cause it to shrink,  In particular it can never lead
 * to demotion to a fixnum, so after this call to negateb it is still
 * OK to assume that a is a bignum.
 */
        a = negateb(a);
        pop(b);
        errexit();
        lena = (bignum_length(a) - CELL)/4;
    }
    if (((int32_t)bignum_digits(b)[lenb-1]) < 0)
    {   sign = -sign;
        push(a);
        /* see above comments about negateb */
        b = negateb(b);
        pop(a);
        errexit();
        lenb = (bignum_length(b) - CELL)/4;
    }
    if (lenb < lena)    /* Commute so that b is at least as long as a */
    {   c = a;
        a = b;
        b = c;
        lenc = lena;
        lena = lenb;
        lenb = lenc;
    }
    push2(a, b);
/*
 * For very big numbers I have two special actions called for here.  First
 * I must round up the size of the result vector to have a big enough power
 * of two as a factor so that (recursive) splitting in two does not cause
 * trouble later.  Then I have to allocate some workspace, the size of that
 * being related to the size of the numbers being handled.
 */
    if (lena > KARATSUBA_CUTOFF)
    {
        int k = 0;
/*
 * I pad lenc up to have a suitably large power of 2 as a factor so
 * that splitting numbers in half works neatly for me.
 */
        lenc = (lenb+1)/2;  /* rounded up half-length of longer number */
        while (lenc > KARATSUBA_CUTOFF)
        {   lenc = (lenc + 1)/2;
            k++;
        }
        while (k != 0)
        {   lenc = 2*lenc;
            k--;
        }
        lenc = 2*lenc;
        c = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+8*lenc);
        errexitn(2);
/*
 * The next line seems pretty shameless, but it may reduce the amount of
 * garbage collection I do.  When the workspace vector needed is short enough
 * (at present up to 256 bytes) I use the character assembly buffer (boffo)
 * as my workspace, relying on an expectation that bignumber multiplication
 * can never be triggered from places within the reader where that buffer is
 * in use for its normal purpose.  I forge tag bits to make boffo look like
 * a number here, but can never trigger garbage collection in a way that
 * might inspect same, so that too is safe at present.
 */
        if ((4*lenc+CELL) <= (intptr_t)length_of_header(vechdr(boffo)))
            d = (Lisp_Object)((char *)boffo + TAG_NUMBERS - TAG_VECTOR);
        else
        {   push(c);
            d = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*lenc);
            pop(c);
        }
        lenc = 2*lenc;
    }
    else
    {
/*
 * In cases where I will use classical long multiplication there is no
 * need to waste space with extra padding or with the workspace vector d.
 */
        lenc = lena + lenb;
        c = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*lenc);
        d = c;     /* set d to avoid dataflow anomaly */
    }
    pop2(b, a);
    errexit();
    {   uint32_t *da = &bignum_digits(a)[0],
                   *db = &bignum_digits(b)[0],
                   *dc = &bignum_digits(c)[0],
                   *dd = &bignum_digits(d)[0];
        long_times(dc, da, db, dd, lena, lenb, lenc);
    }
/*
 * Here the absolute value of the product has been computed properly.
 * The result can easily have a zero top digit, which will need trimming
 * off.  If at least one of the input values was a number which had to
 * be represented with a zero leading digit (e.g. 0x40000000) then the
 * product can have two leading zero digits here.  Similarly for negative
 * results.  Also padding (to allow splitting numbers into two) can have
 * resulted in extra padding up at the top.  lenc gives the size of vector
 * that was allocated, lena+lenb is a much better guess of how much data
 * is active in it.
 */
    errexit();
    {   int32_t newlenc = lena + lenb;
/*
 * I tidy up by putting a zero in any padding word above the top of the
 * active data, and by inserting a header in space that gets trimmed off
 * in such a way that the garbage collector will not get upset.  This
 * all just roughly trims the numbers - fine adjustment follows.
 */
        if ((SIXTY_FOUR_BIT && ((newlenc & 1) != 0)) ||
           (!SIXTY_FOUR_BIT && ((newlenc & 1) == 0)))
        {   bignum_digits(c)[newlenc] = 0;
            if (lenc != newlenc)    /* i.e. I padded out somewhat */
            {
                *(Header *)&bignum_digits(c)[newlenc+1] =
                    make_bighdr(lenc-newlenc-1);
                lenc = newlenc;
                numhdr(c) = make_bighdr(lenc+CELL/4);
            }
        }
        else if (lenc != newlenc)    /* i.e. I padded out somewhat */
        {
            *(Header *)&bignum_digits(c)[newlenc] =
                make_bighdr(lenc-newlenc);
            lenc = newlenc;
            numhdr(c) = make_bighdr(lenc+CELL/4);
        }
    }
/*
 * Now I am safe against the garbage collector, and the number c has as
 * its length just lena+lenb, even if it had been padded out earlier.
 */
    if (sign < 0)
    {   uint32_t carry = 0xffffffffU;
        for (i=0; i<lenc-1; i++)
        {   carry = clear_top_bit(~bignum_digits(c)[i]) + top_bit(carry);
            bignum_digits(c)[i] = clear_top_bit(carry);
        }
        carry = ~bignum_digits(c)[i] + top_bit(carry);
        if (carry != -1)
        {   bignum_digits(c)[i] = carry;
            return c;   /* no truncation needed */
        }
        carry = bignum_digits(c)[i-1];
        if ((carry & 0x40000000) == 0)
        {   bignum_digits(c)[i] = 0xffffffffU;
            return c;   /* no truncation becase of previous digit */
        }
/*
 * I need to argue that lenc was at least 2, so bignum_digits(c)[i-2]
 * could at worst access the header word of the bignum - but it can never
 * do that because if it were doing so then the bignum product would
 * be about to have a value zero or thereabouts.  One-word bignums are not
 * allowed to have leading zero digits.
 */
        if (carry == 0x7fffffff &&
            (bignum_digits(c)[i-2] & 0x40000000) != 0) /* chop 2 */
        {   bignum_digits(c)[i-2] |= ~0x7fffffff;
/*
 * I common up the code to chop off two words from the number at label "chop2"
 */
            goto chop2;
        }
        bignum_digits(c)[i-1] |= ~0x7fffffff;
        /* Drop through to truncate by 1 and sometimes that is easy */
    }
    else
    {   uint32_t w = bignum_digits(c)[lenc-1];
        if (w != 0) return c; /* no truncation */
        w = bignum_digits(c)[lenc-2];
        if ((w & 0x40000000) != 0) return c;
        if (w == 0 &&
            (bignum_digits(c)[lenc-3] & 0x40000000) == 0) goto chop2;
        /* truncate one word */
    }
/*
 * here the data in the bignum is all correct (even in the most significant
 * digit) but I need to shrink the number by one word.  Because of all the
 * doubleword alignment that is used here this can sometimes be done very
 * easily, and other times it involves forging a short bit of dummy data
 * to fill in a gap that gets left in the heap.
 */
    numhdr(c) -= pack_hdrlength(1);
    if ((SIXTY_FOUR_BIT && ((lenc & 1) == 0)) ||
        (!SIXTY_FOUR_BIT && ((lenc & 1) != 0)))
        bignum_digits(c)[lenc-1] = 0; /* tidy up */
    else bignum_digits(c)[lenc-1] = make_bighdr(2);
    return c;
chop2:
/*
 * Trim two words from the number c
 */
    numhdr(c) -= pack_hdrlength(2);
    lenc -= 2;
    bignum_digits(c)[lenc] = 0;
    if (SIXTY_FOUR_BIT) lenc = (lenc + 1) & ~1;
    else lenc |= 1;
    *(Header *)&bignum_digits(c)[lenc] = make_bighdr(2);
    return c;
}

#ifdef COMMON
#define timesbr(a, b) timesir(a, b)

#define timesbc(a, b) timesic(a, b)
#endif

#define timesbf(a, b) timessf(a, b)

#ifdef COMMON
#define timesri(a, b) timesir(b, a)

#define timesrs(a, b) timessr(b, a)

#define timesrb(a, b) timesbr(b, a)

static Lisp_Object timesrr(Lisp_Object a, Lisp_Object b)
/*
 * multiply a pair of rational numbers
 */
{
    Lisp_Object nil = C_nil;
    Lisp_Object w = nil;
    push5(numerator(a), denominator(a),
          numerator(b), denominator(b), nil);
#define g   stack[0]
#define db  stack[-1]
#define nb  stack[-2]
#define da  stack[-3]
#define na  stack[-4]
    g = gcd(na, db);
    nil = C_nil;
    if (exception_pending()) goto fail;
    na = quot2(na, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    db = quot2(db, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    g = gcd(nb, da);
    nil = C_nil;
    if (exception_pending()) goto fail;
    nb = quot2(nb, g);
    nil = C_nil;
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
fail:
    popv(5);
    return w;
#undef g
#undef db
#undef nb
#undef da
#undef na
}

#define timesrc(a, b) timesic(a, b)

#define timesrf(a, b) timessf(a, b)

#define timesci(a, b) timesic(b, a)

#define timescs(a, b) timessc(b, a)

#define timescb(a, b) timesbc(b, a)

#define timescr(a, b) timesrc(b, a)

static Lisp_Object timescc(Lisp_Object a, Lisp_Object b)
/*
 * multiply a pair of complex values
 */
{
    Lisp_Object nil = C_nil;
    Lisp_Object w = nil;
    push4(real_part(a), imag_part(a),
          real_part(b), imag_part(b));
    push2(nil, nil);
#define u   stack[0]
#define v   stack[-1]
#define ib  stack[-2]
#define rb  stack[-3]
#define ia  stack[-4]
#define ra  stack[-5]
    u = times2(ra, rb);
    nil = C_nil;
    if (exception_pending()) goto fail;
    v = times2(ia, ib);
    nil = C_nil;
    if (exception_pending()) goto fail;
    v = negate(v);
    nil = C_nil;
    if (exception_pending()) goto fail;
    u = plus2(u, v);                    /* real part of result */
    nil = C_nil;
    if (exception_pending()) goto fail;
    v = times2(ra, ib);
    nil = C_nil;
    if (exception_pending()) goto fail;
    ib = times2(rb, ia);
    nil = C_nil;
    if (exception_pending()) goto fail;
    v = plus2(v, ib);                   /* imaginary part */
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = make_complex(u, v);
fail:
    popv(6);
    return w;
#undef u
#undef v
#undef ib
#undef rb
#undef ia
#undef ra
}

#define timescf(a, b) timesci(a, b)
#endif

#define timesfi(a, b) timesif(b, a)

#ifdef COMMON
#define timesfs(a, b) timessf(b, a)
#endif

#define timesfb(a, b) timesbf(b, a)

#ifdef COMMON
#define timesfr(a, b) timesrf(b, a)

#define timesfc(a, b) timescf(b, a)
#endif

static Lisp_Object timesff(Lisp_Object a, Lisp_Object b)
/*
 * multiply boxed floats - see commentary on plusff()
 */
{
#ifdef COMMON
    int32_t ha = type_of_header(flthdr(a)), hb = type_of_header(flthdr(b));
#endif
    double d = float_of_number(a) * float_of_number(b);
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

/*
 * ... and now for the dispatch code that copes with general
 * multiplication.
 */

#ifdef TEST_BIGNUM

/*
 * If I have suspicions about the behaviour of the ariithmetic code I can
 * do some degree of extra testing. Eg I can compute the same value twice
 * (once inefficiently) and compare results.
 */

extern Lisp_Object genuine_times2(Lisp_Object a, Lisp_Object b);


Lisp_Object times2(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object ab1, aa, bb, nil = C_nil;
    push2(a, b);
    ab1 = plus2(a, b);               /* a + b */
    errexitn(2);
    ab1 = genuine_times2(ab1, ab1);  /* a^2 + 2*a*b + b^2 */
    errexitn(2);
    pop2(b, a);
    push3(a, b, ab1);
    aa = genuine_times2(a, a);       /* a^2 */
    errexitn(3);
    pop3(ab1, b, a);
    push4(a, b, aa, ab1);
    bb = genuine_times2(b, b);       /* b^2 */
    errexitn(4);
    pop(ab1);
    ab1 = difference2(ab1, bb);      /* now a^2 + 2*a*b */
    errexitn(3);
    pop(aa);
    ab1 = difference2(ab1, aa);      /* 2*a*b */
    errexitn(2);
    ab1 = quot2(ab1, fixnum_of_int(2));
    errexitn(2);
    pop2(b, a);
    push3(ab1, a, b);
    aa = genuine_times2(a, b);
    pop3(b, a, ab1);
    errexit();
    if (!numeq2(aa, ab1))
    {   err_printf("multiply messed up\n");
        err_printf("a = "); prin_to_error(a);
        err_printf("\nb = "); prin_to_error(b);
        err_printf("\n((a+b)^-a^-b^)/2) = "); prin_to_error(ab1);
        err_printf("\na*b = "); prin_to_error(aa);
        err_printf("\n\n"); 
        return aerror("bad times");
    }
    return aa;
}

#define times2(a,b) genuine_times2(a,b)
#endif

Lisp_Object times2(Lisp_Object a, Lisp_Object b)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return timesii(a, b);
#ifdef COMMON
    case TAG_SFLOAT:
            return timesis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return timesib(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return timesir(a, b);
        case TYPE_COMPLEX_NUM:
                return timesic(a, b);
#endif
        default:
                return aerror1("bad arg for times",  b);
                }
            }
    case TAG_BOXFLOAT:
            return timesif(a, b);
    default:
            return aerror1("bad arg for times",  b);
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch (b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return timessi(a, b);
    case TAG_SFLOAT:
            {   Float_union aa, bb; /* timesss() coded in-line */
                aa.i = a - TAG_SFLOAT;
                bb.i = b - TAG_SFLOAT;
                aa.f = (float) (aa.f * bb.f);
                return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
            }
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return timessb(a, b);
        case TYPE_RATNUM:
                return timessr(a, b);
        case TYPE_COMPLEX_NUM:
                return timessc(a, b);
        default:
                return aerror1("bad arg for times",  b);
                }
            }
    case TAG_BOXFLOAT:
            return timessf(a, b);
    default:
            return aerror1("bad arg for times",  b);
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
                    return timesbi(a, b);
#ifdef COMMON
            case TAG_SFLOAT:
                    return timesbs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return timesbb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return timesbr(a, b);
                case TYPE_COMPLEX_NUM:
                        return timesbc(a, b);
#endif
                default:
                        return aerror1("bad arg for times",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return timesbf(a, b);
            default:
                    return aerror1("bad arg for times",  b);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch (b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return timesri(a, b);
            case TAG_SFLOAT:
                    return timesrs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return timesrb(a, b);
                case TYPE_RATNUM:
                        return timesrr(a, b);
                case TYPE_COMPLEX_NUM:
                        return timesrc(a, b);
                default:
                        return aerror1("bad arg for times",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return timesrf(a, b);
            default:
                    return aerror1("bad arg for times",  b);
                }
    case TYPE_COMPLEX_NUM:
                switch (b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return timesci(a, b);
            case TAG_SFLOAT:
                    return timescs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return timescb(a, b);
                case TYPE_RATNUM:
                        return timescr(a, b);
                case TYPE_COMPLEX_NUM:
                        return timescc(a, b);
                default:
                        return aerror1("bad arg for times",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return timescf(a, b);
            default:
                    return aerror1("bad arg for times",  b);
                }
#endif
    default:    return aerror1("bad arg for times",  a);
            }
        }
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return timesfi(a, b);
#ifdef COMMON
    case TAG_SFLOAT:
            return timesfs(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return timesfb(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return timesfr(a, b);
        case TYPE_COMPLEX_NUM:
                return timesfc(a, b);
#endif
        default:
                return aerror1("bad arg for times",  b);
                }
            }
    case TAG_BOXFLOAT:
            return timesff(a, b);
    default:
            return aerror1("bad arg for times",  b);
        }
default:
        return aerror1("bad arg for times",  a);
    }
}

/* end of arith02.c */
