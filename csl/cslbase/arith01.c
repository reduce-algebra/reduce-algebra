/*  arith01.c                         Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Arithmetic functions.
 *        Addition of generic numbers
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




/* Signature: 2e5bbc52 24-May-2008 */


#include "headers.h"


/*
 * I start off with a collection of utility functions that create
 * Lisp structures to represent various sorts of numbers
 * and which extract values from same.
 * The typedefs that explain the layout of these structures are in "tags.h"
 */

Lisp_Object make_one_word_bignum(int32_t n)
/*
 * n is an integer - create a bignum representation of it.  This is
 * done when n is outside the range 0xf8000000 to 0x07ffffff.
 */
{   Lisp_Object w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4);
    Lisp_Object nil;
    errexit();
    bignum_digits(w)[0] = n;
    if (SIXTY_FOUR_BIT) bignum_digits(w)[1] = 0;  /* padding */
    return w;
}

Lisp_Object make_two_word_bignum(int32_t a1, uint32_t a0)
/*
 * This make a 2-word bignum from the 2-word value (a1,a0), where it
 * must have been arranged already that a1 and a0 are correctly
 * normalized to put in the two words as indicated.
 */
{
    Lisp_Object w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+8);
    Lisp_Object nil;
    errexit();
    bignum_digits(w)[0] = a0;
    bignum_digits(w)[1] = a1;
    if (!SIXTY_FOUR_BIT) bignum_digits(w)[2] = 0;
    return w;
}

#ifdef COMMON
Lisp_Object make_sfloat(double d)
/*
 * Turn a regular floating point value into a Lisp "short float", which
 * is an immediate object obtained by using the bottom 4 bits of a 32-bit
 * word as tag, and the rest as just whatever would stand for a regular
 * single precision value.  In doing the conversion here I ignore
 * rounding etc - short floats are to save heap turn-over, but will
 * not give robust numeric results.
 */
{
    Float_union w;
    w.f = (float)d;
    return (w.i & ~(int32_t)0xf) + TAG_SFLOAT;
}
#endif

Lisp_Object make_boxfloat(double a, int32_t type)
/*
 * Make a boxed float (single, double or long according to the type specifier)
 * if type==0 this makes a short float
 */
{
    Lisp_Object r, nil;
#ifndef COMMON
    CSL_IGNORE(type);
#endif
#ifdef COMMON
    switch (type)
    {
case 0:
        {   Float_union aa;
            aa.f = (float)a;
            return (aa.i & ~(intptr_t)0xf) + TAG_SFLOAT;
        }
case TYPE_SINGLE_FLOAT:
        r = getvector(TAG_BOXFLOAT, TYPE_SINGLE_FLOAT, sizeof(Single_Float));
        errexit();
        single_float_val(r) = (float)a;
        return r;
default: /* TYPE_DOUBLE_FLOAT I hope */
#endif
        r = getvector(TAG_BOXFLOAT, TYPE_DOUBLE_FLOAT, SIZEOF_DOUBLE_FLOAT);
        errexit();
        double_float_val(r) = a;
        return r;
#ifdef COMMON
case TYPE_LONG_FLOAT:
        r = getvector(TAG_BOXFLOAT, TYPE_LONG_FLOAT, SIZEOF_LONG_FLOAT);
        errexit();
        long_float_val(r) = a;
        return r;
    }
#endif
}

static double bignum_to_float(Lisp_Object v, int32_t h, int *xp)
/*
 * Convert a Lisp bignum to get a floating point value.  This uses at most the
 * top 3 digits of the bignum's representation since that is enough to achieve
 * full double precision accuracy.
 * This can not overflow, because it leaves an exponent-adjustment value
 * in *xp. You need ldexp(r, *xp) afterwards.
 */
{
    int32_t n = (h-CELL-4)/4;  /* Last index into the data */
    int x = 31*(int)n;
    int32_t msd = (int32_t)bignum_digits(v)[n];
/* NB signed conversion on next line */
    double r = (double)msd;
    switch (n)
    {
default:        /* for very big numbers combine in 3 digits */
        r = TWO_31*r + (double)bignum_digits(v)[--n];
        x -= 31;
        /* drop through */
case 1: r = TWO_31*r + (double)bignum_digits(v)[--n];
        x -= 31;
        /* drop through */
case 0: break;  /* do no more */
    }
    *xp = x;
    return r;
}

double float_of_number(Lisp_Object a)
/*
 * Return a (double precision) floating point value for the given Lisp
 * number, or 0.0 in case of trouble.  This is often called in circumstances
 * where I already know the type of its argument and so its type-dispatch
 * is unnecessary - in doing so I am trading off performance against
 * code repetition.
 */
{
    if (is_fixnum(a)) return (double)int_of_fixnum(a);
#ifdef COMMON
    else if (is_sfloat(a))
    {   Float_union w;
        w.i = a - TAG_SFLOAT;
        return (double)w.f;
    }
#endif
    else if (is_bfloat(a))
    {   int32_t h = type_of_header(flthdr(a));
        switch (h)
        {
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            return (double)single_float_val(a);
#endif
    case TYPE_DOUBLE_FLOAT:
            return double_float_val(a);
#ifdef COMMON
    case TYPE_LONG_FLOAT:
            return (double)long_float_val(a);
#endif
    default:
            return 0.0;
        }
    }
    else
    {   Header h = numhdr(a);
        int x1;
        double r1;
        switch (type_of_header(h))
        {
    case TYPE_BIGNUM:
            r1 = bignum_to_float(a, length_of_header(h), &x1);
            return ldexp(r1, x1);
#ifdef COMMON
    case TYPE_RATNUM:
            {   int x2;
                Lisp_Object na = numerator(a);
                a = denominator(a);
                if (is_fixnum(na)) r1 = float_of_number(na), x1 = 0;
                else r1 = bignum_to_float(na,
                              length_of_header(numhdr(na)), &x1);
                if (is_fixnum(a)) r1 = r1 / float_of_number(a), x2 = 0;
                else r1 = r1 / bignum_to_float(a,
                                   length_of_header(numhdr(a)), &x2);
/* Floating point overflow can only arise in this ldexp() */
                return ldexp(r1, x1 - x2);
            }
#endif
    default:
/*
 * If the value was non-numeric or a complex number I hand back 0.0,
 * and since I am supposed to have checked the object type already
 * this OUGHT not to arrive - bit raising an exception seems over-keen.
 */
            return 0.0;
        }
    }
}

int32_t thirty_two_bits(Lisp_Object a)
/*
 * return a 32 bit integer value for the Lisp integer (fixnum or bignum)
 * passed down - ignore any higher order bits and return 0 if the arg was
 * floating, rational etc or not a number at all.  Only really wanted where
 * links between C-specific code (that might really want 32-bit values)
 * and Lisp are being coded.
 */
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        return int_of_fixnum(a);
case TAG_NUMBERS:
        if (is_bignum(a))
        {   int len = bignum_length(a);
/*
 * Note that I keep 31 bits per word and use a 2s complement representation.
 * thus if I have a one-word bignum I just want its contents but in all
 * other cases I need just one bit from the next word up.
 */
            if (len == 8) return bignum_digits(a)[0]; /* One word bignum */
            return bignum_digits(a)[0] | (bignum_digits(a)[1] << 31);
        }
        /* else drop through */
case TAG_BOXFLOAT:
default:
/*
 * return 0 for all non-fixnums
 */
        return 0;
    }
}

#ifdef HAVE_INT64_T

int64_t sixty_four_bits(Lisp_Object a)
{
    return (int64_t)thirty_two_bits(a); /* Inadequate really! */
}

#endif

#ifdef COMMON
Lisp_Object make_complex(Lisp_Object r, Lisp_Object i)
{
    Lisp_Object v, nil = C_nil;
/*
 * Here r and i are expected to be either both rational (which in this
 * context includes the case of integer values) or both of the same
 * floating point type.  It is assumed that this has already been
 * arranged by here.
 */
    if (i == fixnum_of_int(0)) return r;
    stackcheck2(0, r, i);
    push2(r, i);
    v = getvector(TAG_NUMBERS, TYPE_COMPLEX_NUM, sizeof(Complex_Number));
/*
 * The vector r has uninitialized contents here - dodgy.  If the call
 * to getvector succeeded then I fill it in, otherwise I will not
 * refer to it again, and I think that unreferenced vectors containing junk
 * are OK.
 */
    pop2(i, r);
    errexit();
    real_part(v) = r;
    imag_part(v) = i;
    return v;
}

Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q)
/*
 * By the time this is called (p/q) must be in its lowest terms, q>0
 */
{
    Lisp_Object v, nil = C_nil;
    if (q == fixnum_of_int(1)) return p;
    stackcheck2(0, p, q);
    push2(p, q);
    v = getvector(TAG_NUMBERS, TYPE_RATNUM, sizeof(Rational_Number));
    pop2(q, p);
    errexit();
    numerator(v) = p;
    denominator(v) = q;
    return v;
}

#endif

/*
 * The next bit of code seems pretty dreadful, but I think that is just
 * what generic arithmetic is all about.  The code for plus2 is written
 * as a dispatch function into over 30 separate possible type-specific
 * versions of the code.  In a very few simple (and performance-critical)
 * cases the code is written in-line in plus2 - in particular arithmetic
 * on fixnums is done that way.  Similarly for other cases.
 * I Use one-character suffices to remind me about types:
 *          i       fixnum
 *          b       bignum
 *          r       ratio
 *          s       short float
 *          f       boxed float (single/double/long)
 *          c       complex
 *
 * Throughout this code I am going to IGNORE floating point exceptions,
 * at least for a first attempt.  Decent detection of and recovery after
 * floating point overflow seems an extra unpleasant distraction!  Note
 * that C allows me to trap the SIGFPE exception, but returning from
 * the exception handler gives undefined behaviour - one is expected
 * to longjmp out, which means accepting the cost of using setjmp.
 *
 * It would perhaps be reasonable to write the dispatch code as a big
 * macro so that the versions for plus, times etc could all be kept
 * in step - I have not done that (a) because the macro would have been
 * bigger than I like macros to be (b) it would have involved token-
 * splicing (or VERY many parameters) to generate the names of the
 * separate type-specific procedures and (c) doing it by hand allows me
 * total flexibility about coding various cases in-line.
 */

#ifdef COMMON

static Lisp_Object plusis(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    bb.f = (float)((float)int_of_fixnum(a) + bb.f);
    return (bb.i & ~(int32_t)0xf) + TAG_SFLOAT;
}
#endif

/*
 * Bignums are represented as vectors where the most significant 32-bit
 * digit is treated as signed, and the remaining ones are unsigned.
 */

static Lisp_Object plusib(Lisp_Object a, Lisp_Object b)
/*
 * Add a fixnum to a bignum, returning a result as a fixnum or bignum
 * depending on its size.  This seems much nastier than one would have
 * hoped.
 */
{
    int32_t len = bignum_length(b)-CELL, i, sign = int_of_fixnum(a), s;
    Lisp_Object c, nil;
    len = len/4;         /* This is always 4 because even on a 64-bit */
                         /* machine where CELL=8 I use 4-byte B-digits */
    if (len == 1)
    {   int32_t t;
/*
 * Partly because it will be a common case and partly because it has
 * various special cases I have special purpose code to cope with
 * adding a fixnum to a one-word bignum.
 */
        s = (int32_t)bignum_digits(b)[0] + sign;
        t = s + s;
        if (top_bit_set(s ^ t))  /* needs to turn into two-word bignum */
        {   if (s < 0) return make_two_word_bignum(-1, clear_top_bit(s));
            else return make_two_word_bignum(0, s);
        }
        t = s & fix_mask;    /* Will it fit as a fixnum? */
        if (t == 0 || t == fix_mask) return fixnum_of_int(s);
        /* here the result is a one-word bignum */
        return make_one_word_bignum(s);
    }
/*
 * Now, after all the silly cases have been handled, I have a calculation
 * which seems set to give a multi-word result.  The result here can at
 * least never shrink to a fixnum since subtracting a fixnum can at
 * most shrink the length of a number by one word.  I omit the stack-
 * check here in the hope that code here never nests enough for trouble.
 */
    push(b);
    c = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*len);
    pop(b);
    errexit();
    s = bignum_digits(b)[0] + clear_top_bit(sign);
    bignum_digits(c)[0] = clear_top_bit(s);
    if (sign >= 0) sign = 0; else sign = 0x7fffffff; /* extend the sign */

    len--;
    for (i=1; i<len; i++)
    {   s = bignum_digits(b)[i] + sign + top_bit(s);
        bignum_digits(c)[i] = clear_top_bit(s);
    }
    /* Now just the most significant digit remains to be processed  */
    if (sign != 0) sign = -1;
    {   s = bignum_digits(b)[i] + sign + top_bit(s);
        if (!signed_overflow(s))         /* did it overflow? */
        {
/*
 * Here the most significant digit did not produce an overflow, but maybe
 * what we actually had was some cancellation and the MSD is now zero
 * or -1, so that the number should shrink...
 */
            if ((s == 0 && (bignum_digits(c)[i-1] & 0x40000000) == 0) ||
                (s == -1 && (bignum_digits(c)[i-1] & 0x40000000) != 0))
            {   /* shrink the number */
                numhdr(c) -= pack_hdrlength(1L);
                if (s == -1) bignum_digits(c)[i-1] |= ~0x7fffffff;
/*
 * Now sometimes the shrinkage will leave a padding word, sometimes it
 * will really allow me to save space. As a jolly joke with a 64-bit
 * system I need padding if there have been an odd number of (32-bit)
 * words of bignum data while with a 32-bit system the header word is
 * 32-bits wide and I need padding if there are ar even number of additional
 * data words.
 */
                if ((SIXTY_FOUR_BIT && ((i & 1) != 0)) ||
                    (!SIXTY_FOUR_BIT && ((i & 1) == 0)))
                {   bignum_digits(c)[i] = 0;   /* leave the unused word tidy */
                    return c;
                }
/*
 * Having shrunk the number I am leaving a doubleword of unallocated space
 * in the heap.  Dump a header word into it to make it look like an
 * 8-byte bignum since that will allow the garbage collector to handle it.
 * It I left it containing arbitrary junk I could wreck myself. The
 * make_bighdr(2L) makes a header for a number that fills 2 32-bit words
 * in all.
 */
                *(Header *)&bignum_digits(c)[i] = make_bighdr(2L);
                return c;
            }
            bignum_digits(c)[i] = s;  /* length unchanged */
            return c;
        }
/*
 * Here the result is one word longer than the input-bignum.
 * Once again SOMTIMES this will not involve allocating more store,
 * but just encroaching into the previously unused word that was padding
 * things out to a multiple of 8 bytes.
 */
        if ((SIXTY_FOUR_BIT && ((i & 1) == 0)) ||
            (!SIXTY_FOUR_BIT && ((i & 1) == 1)))
        {   bignum_digits(c)[i++] = clear_top_bit(s);
            bignum_digits(c)[i] = top_bit_set(s) ? -1 : 0;
            numhdr(c) += pack_hdrlength(1L);
            return c;
        }
        push(c);
/*
 * NB on the next line there is a +8. One +4 is because I had gone len--
 * somewhere earlier. The other +4 is to increase the length of the number
 * by one word.
 */
        b = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+8+4*len);
        pop(c);
        errexit();
        for (i=0; i<len; i++)
            bignum_digits(b)[i] = bignum_digits(c)[i];
/*
 * I move the top digit across by hand since if the number is negative
 * I must lost its top bit
 */
        bignum_digits(b)[i++] = clear_top_bit(s);
/* Now the one-word extension to the number */
        bignum_digits(b)[i++] = top_bit_set(s) ? -1 : 0;
/*
 * Finally because I know that I expanded into a new doubleword I should
 * tidy up the second word of the newly allocated pair.
 */
        bignum_digits(b)[i] = 0;
        return b;
    }
}

#ifdef COMMON
static Lisp_Object plusir(Lisp_Object a, Lisp_Object b)
/*
 * fixnum and ratio, but also valid for bignum and ratio.
 * Note that if the inputs were in lowest terms there is no need for
 * and GCD calculations here.
 */
{
    Lisp_Object nil;
    push(b);
    a = times2(a, denominator(b));
    nil = C_nil;
    if (!exception_pending()) a = plus2(a, numerator(stack[0]));
    pop(b);
    errexit();
    return make_ratio(a, denominator(b));
}

static Lisp_Object plusic(Lisp_Object a, Lisp_Object b)
/*
 * real of any sort plus complex.
 */
{
    Lisp_Object nil;
    push(b);
    a = plus2(a, real_part(b));
    pop(b);
    errexit();
/*
 * make_complex() takes responsibility for mapping #C(n 0) onto n
 */
    return make_complex(a, imag_part(b));
}
#endif

static Lisp_Object plusif(Lisp_Object a, Lisp_Object b)
/*
 * Fixnum plus boxed-float.
 */
{
    double d = (double)int_of_fixnum(a) + float_of_number(b);
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

#ifdef COMMON
#define plussi(a, b) plusis(b, a)

#define plussb(a, b) plusbs(b, a)

#define plussr(a, b) plusrs(b, a)

#define plussc(a, b) plusic(a, b)

#endif

static Lisp_Object plussf(Lisp_Object a, Lisp_Object b)
/*
 * This can be used for any rational value plus a boxed-float. plusif()
 * is separated just for (minor) efficiency reasons.
 */
{
    double d = float_of_number(a) + float_of_number(b);
    return make_boxfloat(d, type_of_header(flthdr(b)));
}

#define plusbi(a, b) plusib(b, a)

#ifdef COMMON

static Lisp_Object plusbs(Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(a) + float_of_number(b);
    return make_sfloat(d);
}

#endif

Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd)
/*
 * (a) is a bignum, and arithmetic on it has (just) caused overflow
 * in its top word - I just need to stick on another word. (msd) is the
 * current top word, and its sign will be used to decide on the value
 * that must be appended.
 */
{
    int32_t len = bignum_length(a);
/*
 * Sometimes I need to allocate a new vector and copy data across into it
 */
    if ((len & 4) == 0)
    {   Lisp_Object b, nil;
        int32_t i;
        push(a);
        b = getvector(TAG_NUMBERS, TYPE_BIGNUM, len+4);
        pop(a);
        errexit();
        len = (len-CELL)/4;
        for (i=0; i<len; i++)
            bignum_digits(b)[i] = clear_top_bit(bignum_digits(a)[i]);
        bignum_digits(b)[len] = top_bit_set(msd) ? -1 : 0;
        bignum_digits(b)[len+1] = 0;
        return b;
    }
    else
/*
 * .. whereas sometimes I have a spare word already available.
 */
    {   numhdr(a) += pack_hdrlength(1L);
        len = (len-CELL)/4;
        bignum_digits(a)[len-1] = clear_top_bit(bignum_digits(a)[len-1]);
        bignum_digits(a)[len] = top_bit_set(msd) ? -1 : 0;
        return a;
    }
}

static Lisp_Object plusbb(Lisp_Object a, Lisp_Object b)
/*
 * add two bignums.
 */
{
    int32_t la = bignum_length(a),
          lb = bignum_length(b),
          i, s, carry;
    Lisp_Object c, nil;
    if (la < lb)    /* maybe swap order of args */
    {   Lisp_Object t = a;
        int32_t t1;
        a = b; b = t;
        t1 = la; la = lb; lb = t1;
    }
/*
 * now (a) is AT LEAST as long as b.  I have special case code for
 * when both args are single-word bignums, since I expect that to be
 * an especially common case.
 */
    if (la == CELL+4)    /* and hence b also has only 1 digit */
    {   int32_t va = bignum_digits(a)[0],
              vb = bignum_digits(b)[0],
              vc = va + vb;
        if (signed_overflow(vc)) /* we have a 2-word bignum result */
        {   Lisp_Object w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+8);
            errexit();
            bignum_digits(w)[0] = clear_top_bit(vc);
            bignum_digits(w)[1] = top_bit_set(vc) ? -1 : 0;
            if (!SIXTY_FOUR_BIT) bignum_digits(w)[2] = 0;
            return w;
        }
/*
 * here the result fits into one word - maybe it will squash down into
 * a fixnum?
 */
        else
        {   vb = vc & fix_mask;
            if (vb == 0 || vb == fix_mask) return fixnum_of_int(vc);
            else return make_one_word_bignum(vc);
        }
    }
    push2(a, b);
    c = getvector(TAG_NUMBERS, TYPE_BIGNUM, la);
    pop2(b, a);
    errexit();
    la = (la-CELL)/4 - 1;
    lb = (lb-CELL)/4 - 1;
    carry = 0;
/*
 * Add all but the top digit of b
 */
    for (i=0; i<lb; i++)
    {   carry = bignum_digits(a)[i] + bignum_digits(b)[i] + top_bit(carry);
        bignum_digits(c)[i] = clear_top_bit(carry);
    }
    if (la == lb) s = bignum_digits(b)[i];
    else
/*
 * If a is strictly longer than b I sign extend b here and add in as many
 * copies of 0 or -1 as needbe to get up to the length of a.
 */
    {   s = bignum_digits(b)[i];
        carry =  bignum_digits(a)[i] + clear_top_bit(s) + top_bit(carry);
        bignum_digits(c)[i] = clear_top_bit(carry);
        if (s < 0) s = -1; else s = 0;
        for (i++; i<la; i++)
        {   carry = bignum_digits(a)[i] + clear_top_bit(s) + top_bit(carry);
            bignum_digits(c)[i] = clear_top_bit(carry);
        }
    }
/*
 * the most significant digit is added using signed arithmetic so that I
 * can tell if it overflowed.
 */
    carry = bignum_digits(a)[i] + s + top_bit(carry);
    if (!signed_overflow(carry))
    {
/*
 * Here the number has not expanded - but it may be shrinking, and it can
 * shrink by any number of words, all the way down to a fixnum maybe.  Note
 * that I started with at least a 2-word bignum here.
 */
        int32_t msd;
        bignum_digits(c)[i] = carry;
        if (carry == 0)
        {   int32_t j = i-1;
            while ((msd = bignum_digits(c)[j]) == 0 && j > 0) j--;
/*
 * ... but I may need a zero word on the front if the next word down
 * has its top bit set... (top of 31 bits, that is)
 */
            if ((msd & 0x40000000) != 0)
            {   j++;
                if (i == j) return c;
            }
            if (j == 0)
            {   int32_t s = bignum_digits(c)[0];
                if ((s & fix_mask) == 0) return fixnum_of_int(s);
            }
/*
 * If I am shrinking by one word and had an even length to start with
 * I do not have to mess about so much.
 */
            if ((SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) != 0)) ||
                (!SIXTY_FOUR_BIT && (j == i-1) && ((i & 1) == 0)))
            {   numhdr(c) -= pack_hdrlength(1L);
                return c;
            }
            numhdr(c) -= pack_hdrlength(i - j);
            if (SIXTY_FOUR_BIT)
            {   i = (i+2) & ~1;
                j = (j+2) & ~1;     /* Round up to odd index */
            }
            else
            {   i = (i+1) | 1;
                j = (j+1) | 1;     /* Round up to odd index */
            }
/*
 * I forge a header word to allow the garbage collector to skip over
 * (and in due course reclaim) the space that turned out not to be needed.
 */
            bignum_digits(c)[j] = make_bighdr(i - j);
            return c;
        }
/*
 * Now do all the same sorts of things but this time for negative numbers.
 */
        else if (carry == -1)
        {   int32_t j = i-1;
            msd = carry;    /* in case j = 0 */
            while ((msd = bignum_digits(c)[j]) == 0x7fffffff && j > 0) j--;
            if ((msd & 0x40000000) == 0)
            {   j++;
                if (i == j) return c;
            }
            if (j == 0)
            {   int32_t s = bignum_digits(c)[0] | ~0x7fffffff;
                if ((s & fix_mask) == fix_mask) return fixnum_of_int(s);
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
                j = (j+2) & ~1;     /* Round up to odd index */
            }
            else
            {   i = (i+1) | 1;
                j = (j+1) | 1;     /* Round up to odd index */
            }
            bignum_digits(c)[j] = make_bighdr(i - j);
            return c;
        }
        return c;
    }
    else
    {   bignum_digits(c)[i] = carry;
        return lengthen_by_one_bit(c, carry);
    }
}

#ifdef COMMON
#define plusbr(a, b) plusir(a, b)

#define plusbc(a, b) plusic(a, b)
#endif

#define plusbf(a, b) plussf(a, b)

#ifdef COMMON
#define plusri(a, b) plusir(b, a)

#define plusrs(a, b) plusbs(a, b)

#define plusrb(a, b) plusri(a, b)

static Lisp_Object plusrr(Lisp_Object a, Lisp_Object b)
/*
 * Adding two ratios involves some effort to keep the result in
 * lowest terms.
 */
{
    Lisp_Object nil = C_nil;
    Lisp_Object na = numerator(a), nb = numerator(b);
    Lisp_Object da = denominator(a), db = denominator(b);
    Lisp_Object w = nil;
    push5(na, nb, da, db, nil);
#define g   stack[0]
#define db  stack[-1]
#define da  stack[-2]
#define nb  stack[-3]
#define na  stack[-4]
    g = gcd(da, db);
    nil = C_nil;
    if (exception_pending()) goto fail;
/*
 * all the calls to quot2() in this procedure are expected - nay required -
 * to give exact integer quotients.
 */
    db = quot2(db, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    g = quot2(da, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    na = times2(na, db);
    nil = C_nil;
    if (exception_pending()) goto fail;
    nb = times2(nb, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    na = plus2(na, nb);
    nil = C_nil;
    if (exception_pending()) goto fail;
    da = times2(da, db);
    nil = C_nil;
    if (exception_pending()) goto fail;
    g = gcd(na, da);
    nil = C_nil;
    if (exception_pending()) goto fail;
    na = quot2(na, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    da = quot2(da, g);
    nil = C_nil;
    if (exception_pending()) goto fail;
    w = make_ratio(na, da);
/*
 * All the goto statements and the label seem a fair way of expressing
 * the common action that has to be taken if an error or interrupt is
 * detected during any of the intermediate steps here.  Anyone who
 * objects can change it if they really want...
 */
fail:
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

static Lisp_Object pluscc(Lisp_Object a, Lisp_Object b)
/*
 * Add complex values.
 */
{
    Lisp_Object c, nil;
    push2(a, b);
    c = plus2(imag_part(a), imag_part(b));
    pop2(b, a);
    errexit();
    a = plus2(real_part(a), real_part(b));
    errexit();
    return make_complex(a, c);
}

#define pluscf(a, b) plusfc(b, a)
#endif

#define plusfi(a, b) plusif(b, a)

#ifdef COMMON
#define plusfs(a, b) plussf(b, a)
#endif

#define plusfb(a, b) plusbf(b, a)

#ifdef COMMON
#define plusfr(a, b) plusrf(b, a)

#define plusfc(a, b) plusic(a, b)
#endif

static Lisp_Object plusff(Lisp_Object a, Lisp_Object b)
/*
 * Add two boxed floats - the type of the result must match the
 * longer of the types of the arguments, hence the extra
 * messing about.
 */
{
#ifdef COMMON
    int32_t ha = type_of_header(flthdr(a)), hb = type_of_header(flthdr(b));
#endif
    double d;
/*
 * This is written as a declaration followed by a separate assignment to
 * d because I hit a compiler bug on a VAX once otherwise.
 */
    d = float_of_number(a) + float_of_number(b);
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
 * and now for the dispatch code...
 */

/*
 * The following verifies that a number is properly formatted - a
 * fixnum if small enough or a decently normalised bignum.  For use when
 * there is suspicion of a bug wrt such matters. Call is
 *   validate_number("msg", numberToCheck, nX, nY)
 * where nX and nY must be numbers and are shown in any
 * diagnostic.
 */

void validate_number(char *s, Lisp_Object a, Lisp_Object b, Lisp_Object c)
{
    int32_t la, w, msd;
    if (!is_numbers(a)) return;
    la = (length_of_header(numhdr(a))-CELL-4)/4;
    if (la < 0)
        {   trace_printf("%s: number with no digits (%.8x)\n", s, numhdr(a));
            if (is_number(b)) prin_to_trace(b), trace_printf("\n");
            if (is_number(c)) prin_to_trace(c), trace_printf("\n");
            my_exit(EXIT_FAILURE);
        }
    if (la == 0)
    {   msd = bignum_digits(a)[0];
        w = msd & fix_mask;
        if (w == 0 || w == fix_mask)
        {   trace_printf("%s: %.8x should be fixnum\n", s, msd);
            if (is_number(b)) prin_to_trace(b), trace_printf("\n");
            if (is_number(c)) prin_to_trace(c), trace_printf("\n");
            my_exit(EXIT_FAILURE);
        }
        if (signed_overflow(msd))
        {   trace_printf("%s: %.8x should be two-word\n", s, msd);
            if (is_number(b)) prin_to_trace(b), trace_printf("\n");
            if (is_number(c)) prin_to_trace(c), trace_printf("\n");
            my_exit(EXIT_FAILURE);
        }
        return;
    }
    msd = bignum_digits(a)[la];
    if (signed_overflow(msd))
    {   trace_printf("%s: %.8x should be longer\n", s, msd);
        if (is_number(b)) prin_to_trace(b), trace_printf("\n");
        if (is_number(c)) prin_to_trace(c), trace_printf("\n");
        my_exit(EXIT_FAILURE);
    }
    if (msd == 0 && ((msd = bignum_digits(a)[la-1]) & 0x40000000) == 0)
    {   trace_printf("%s: 0: %.8x should be shorter\n", s, msd);
        if (is_number(b)) prin_to_trace(b), trace_printf("\n");
        if (is_number(c)) prin_to_trace(c), trace_printf("\n");
        my_exit(EXIT_FAILURE);
    }
    if (msd == -1 && ((msd = bignum_digits(a)[la-1]) & 0x40000000) != 0)
    {   trace_printf("%s: -1: %.8x should be shorter\n", s, msd);
        if (is_number(b)) prin_to_trace(b), trace_printf("\n");
        if (is_number(c)) prin_to_trace(c), trace_printf("\n");
        my_exit(EXIT_FAILURE);
    }
}


Lisp_Object plus2(Lisp_Object a, Lisp_Object b)
/*
 * I probably want to change the specification of plus2 so that the fixnum +
 * fixnum case is always expected to be done before the main body of the code
 * is entered.  Well maybe even if I do that it then costs very little to
 * include the fixnum code here as well, so I will not delete it.
 */
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
/*
 * This is where fixnum + fixnum arithmetic happens - the case I most want to
 * make efficient.
 */
            {   int32_t r = int_of_fixnum(a) + int_of_fixnum(b);
                int32_t t = r & fix_mask;
                if (t == 0 || t == fix_mask) return fixnum_of_int(r);
                else return make_one_word_bignum(r);
            }
#ifdef COMMON
    case TAG_SFLOAT:
            return plusis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return plusib(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return plusir(a, b);
        case TYPE_COMPLEX_NUM:
                return plusic(a, b);
#endif
        default:
                return aerror1("bad arg for plus", b);
                }
            }
    case TAG_BOXFLOAT:
            return plusif(a, b);
    default:
            return aerror1("bad arg for plus",  b);
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch (b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return plussi(a, b);
    case TAG_SFLOAT:
            {   Float_union aa, bb;
                aa.i = a - TAG_SFLOAT;
                bb.i = b - TAG_SFLOAT;
                aa.f = (float)(aa.f + bb.f);
                return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
            }
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return plussb(a, b);
        case TYPE_RATNUM:
                return plussr(a, b);
        case TYPE_COMPLEX_NUM:
                return plussc(a, b);
        default:
                return aerror1("bad arg for plus",  b);
                }
            }
    case TAG_BOXFLOAT:
            return plussf(a, b);
    default:
            return aerror1("bad arg for plus",  b);
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
                    return plusbi(a, b);
#ifdef COMMON
            case TAG_SFLOAT:
                    return plusbs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return plusbb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return plusbr(a, b);
                case TYPE_COMPLEX_NUM:
                        return plusbc(a, b);
#endif
                default:
                        return aerror1("bad arg for plus",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return plusbf(a, b);
            default:
                    return aerror1("bad arg for plus",  b);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch (b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return plusri(a, b);
            case TAG_SFLOAT:
                    return plusrs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return plusrb(a, b);
                case TYPE_RATNUM:
                        return plusrr(a, b);
                case TYPE_COMPLEX_NUM:
                        return plusrc(a, b);
                default:
                        return aerror1("bad arg for plus",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return plusrf(a, b);
            default:
                    return aerror1("bad arg for plus",  b);
                }
    case TYPE_COMPLEX_NUM:
                switch (b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return plusci(a, b);
            case TAG_SFLOAT:
                    return pluscs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return pluscb(a, b);
                case TYPE_RATNUM:
                        return pluscr(a, b);
                case TYPE_COMPLEX_NUM:
                        return pluscc(a, b);
                default:
                        return aerror1("bad arg for plus",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return pluscf(a, b);
            default:
                    return aerror1("bad arg for plus",  b);
                }
#endif
    default:    return aerror1("bad arg for plus",  a);
            }
        }
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return plusfi(a, b);
#ifdef COMMON
    case TAG_SFLOAT:
            return plusfs(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return plusfb(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return plusfr(a, b);
        case TYPE_COMPLEX_NUM:
                return plusfc(a, b);
#endif
        default:
                return aerror1("bad arg for plus",  b);
                }
            }
    case TAG_BOXFLOAT:
            return plusff(a, b);
    default:
            return aerror1("bad arg for plus",  b);
        }
default:
        return aerror1("bad arg for plus",  a);
    }
}

Lisp_Object difference2(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil;
    switch ((int)b & TAG_BITS)
    {
case TAG_FIXNUM:
        if (is_fixnum(a))
        {
            int32_t r = int_of_fixnum(a) - int_of_fixnum(b);
            int32_t t = r & fix_mask;
            if (t == 0 || t == fix_mask) return fixnum_of_int(r);
            else return make_one_word_bignum(r);
        }
        else if (b != ~0x7ffffffe) return plus2(a, 2*TAG_FIXNUM-b);
        else
        {   push(a);
            b = make_one_word_bignum(-int_of_fixnum(b));
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
    errexit();
    return plus2(a, b);
}

Lisp_Object add1(Lisp_Object p)
/*
 * Increment a number.  Short cut when the number is a fixnum, otherwise
 * just hand over to the general addition code.
 */
{
    if (is_fixnum(p))
    {   if (p == 0x7ffffff1)     /* The ONLY possible overflow case here  */
            return make_one_word_bignum(0x08000000);
        else return (Lisp_Object)(p + 0x10);
    }
    else return plus2(p, fixnum_of_int(1));
}

Lisp_Object sub1(Lisp_Object p)
/*
 * Decrement a number.  Short cut when the number is a fixnum, otherwise
 * just hand over to the general addition code.
 */
{
    if (is_fixnum(p))
    {   if (p == ~0x7ffffffe)     /* The ONLY possible overflow case here  */
            return make_one_word_bignum(int_of_fixnum(p) - 1);
        else return (Lisp_Object)(p - 0x10);
    }
    else return plus2(p, fixnum_of_int(-1));
}

/* end of arith01.c */
