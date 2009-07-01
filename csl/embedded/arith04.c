/*  arith04.c                         Copyright (C) 1991-2008 Codemist Ltd */

/*
 * Arithmetic functions.
 *    <, rationalize
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



/* Signature: 3f3fa250 24-May-2008 */

#include "headers.h"


#ifndef COMMON
/*
 * In CSL mode I fudge make_ratio to be just cons, since it is ONLY
 * needed for (rational ...)
 */

#define make_ratio(a, b) cons(a, b)

#endif

Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2, uint32_t a3, int32_t n)
/*
 * This make a bignum with n words of data and digits a1, a2, a3 and
 * then n zeros.  Will only be called with n>=0 and a1, a2, a3 already
 * correctly structured to make a valid bignum.
 */
{
    int32_t i;
    Lisp_Object w = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+4*n), nil;
    errexit();
    for (i=0; i<n; i++) bignum_digits(w)[i] = 0;
    bignum_digits(w)[n] = a3;
    bignum_digits(w)[n+1] = a2;
    bignum_digits(w)[n+2] = a1;
    if ((n & 1) != 0) bignum_digits(w)[n+3] = 0;
    return w;
}

static Lisp_Object make_power_of_two(int32_t x)
/*
 * Create the number 2^x where x is positive.  Used to make the
 * denominator of a rational representation of a float.  Endless fun
 * to cope with various small cases before I get to the general call
 * to make_n_word_bignum.
 */
{
    if (x < 27) return fixnum_of_int(((int32_t)1) << x);
    else if (x < 30) return make_one_word_bignum(((int32_t)1) << x);
    else if (x == 30) return make_two_word_bignum(0, 0x40000000);
    else if (x < 61) return make_two_word_bignum(((int32_t)1) << (x-31), 0);
    else if ((x % 31) == 30)
         return make_n_word_bignum(0, 0x40000000, 0, (x/31)-2);
    else return make_n_word_bignum(((int32_t)1) << (x % 31), 0, 0, (x/31)-3);
}

static Lisp_Object make_fix_or_big2(int32_t a1, uint32_t a2)
{
    if ((a1==0 && (a2 & fix_mask)==0) ||
        (a1==-1 && (a2 & 0x78000000)==0x78000000))
        return fixnum_of_int(a2);
    else if (a1==0 && (a2 & 0x40000000)==0)
        return make_one_word_bignum(a2);
    else if (a1==-1 && (a2 & 0x40000000)!=0)
        return make_one_word_bignum(a2|~0x7fffffff);
    else return make_two_word_bignum(a1, a2);
}

Lisp_Object rationalf(double d)
{
    int x;
    CSLbool negative = NO;
    int32_t a0, a1;
    uint32_t a2;
    Lisp_Object nil;
    if (d == 0.0) return fixnum_of_int(0);
    if (d < 0.0) d = -d, negative = YES;
    d = frexp(d, &x);   /* 0.5 <= abs(d) < 1.0, x = the (binary) exponent */
/*
 * The next line is not logically needed, provided frexp() is implemented to
 * the relevant standard. However Zortech C release 3.0 used to get the output
 * range for frexp() marginally out and the following line works around the
 * resulting problem.  I leave the code in (always) since its cost
 * implications are minor and other libraries may suffer the same way, and it
 * will be easier not to have to track the bug down from cold again!
 */
    if (d == 1.0) d = 0.5, x++;
    d *= TWO_31;
    a1 = (int32_t)d;
    if (d < 0.0) a1--;
    d -= (double)a1;
    a2 = (uint32_t)(d * TWO_31);
/* Now I have the mantissa of the floating value packed into a1 and a2 */
    x -= 62;
    if (x < 0)
    {   Lisp_Object w;
/*
 * Here the value may have a denominator, or it may be that it will turn
 * out to be representable as an integer.
 */
        while ((a2 & 1) == 0 && x < 0)
        {   a2 = (a2 >> 1) | ((a1 & 1) << 30);
            a1 = a1 >> 1;
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
            if (a1 & 0x40000000) a1 |= ~0x7fffffff;
#endif
            x++;
            if (x == 0)
            {   if (negative)
                {   if (a2 == 0) a1 = -a1;
                    else
                    {   a2 = clear_top_bit(-(int32_t)a2);
                        a1 = ~a1;
                    }
                }
                return make_fix_or_big2(a1, a2);
            }
        }
        if (negative)
        {   if (a2 == 0) a1 = -a1;
            else
            {   a2 = clear_top_bit(-(int32_t)a2);
                a1 = ~a1;
            }
        }
        w = make_fix_or_big2(a1, a2);
        errexit();
        x = -x;
/*
 * Remember: in CSL mode make_ratio is just cons
 */
        if (x < 27) return make_ratio(w, fixnum_of_int(((int32_t)1) << x));
        else
        {   Lisp_Object d, nil;
            push(w);
            d = make_power_of_two(x);
            pop(w);
            errexit();
            return make_ratio(w, d);
        }
    }
    else
    {
/*
 * here the floating point value is quite large, and I need to create
 * a multi-word bignum for it.
 */
        int x1;
        if (negative)
        {   if (a2 == 0) a1 = -a1;
            else
            {   a2 = clear_top_bit(-(int32_t)a2);
                a1 = ~a1;
            }
        }
        if (a1 < 0)
        {   a0 = -1;
            a1 = clear_top_bit(a1);
        }
        else a0 = 0;
        x1 = x / 31;
        x = x % 31;
        a0 = (a0 << x) | (a1 >> (31-x));
        a1 = clear_top_bit(a1 << x) | (a2 >> (31-x));
        a2 = clear_top_bit(a2 << x);
        return make_n_word_bignum(a0, a1, a2, x1);
    }
}

#ifdef COMMON

static Lisp_Object rationalizef(double d)
/*
 * This is expected to give a 'nice' rational approximation to the
 * floating point value d.
 */
{
    double dd;
    Lisp_Object p, q, nil;
    if (d == 0.0) return fixnum_of_int(0);
    else if (d < 0.0) dd = -d; else dd = d;
    p = rationalf(dd);
    errexit();
    q = denominator(p);
    p = numerator(p);
/* /* No cleaning up done, yet. Need to start to produce continued
 * fraction for p/q and truncate it at some suitable point to get
 * a sensible approximation.  Since this is only needed in Common Lisp
 * mode, and seems a bit specialist even then I am not going to rush into
 * cobbling up the code (which I have done before and is basically OK,
 * save that the stopping criteria are pretty delicate).
 */
    if (d < 0.0)
    {   p = negate(p);
        errexit();
    }
    return make_ratio(p, q);
}

#endif

Lisp_Object rational(Lisp_Object a)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        return a;
#ifdef COMMON
case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            return rationalf((double)aa.f);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
#ifdef COMMON
    case TYPE_RATNUM:
#endif
                return a;
    default:
                return aerror1("bad arg for rational", a);
            }
        }
case TAG_BOXFLOAT:
        return rationalf(float_of_number(a));
default:
        return aerror1("bad arg for rational", a);
    }
}

#ifdef COMMON
Lisp_Object rationalize(Lisp_Object a)
{
    switch (a & TAG_BITS)
    {
case TAG_FIXNUM:
        return a;
#ifdef COMMON
case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            return rationalizef((double)aa.f);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
#ifdef COMMON
    case TYPE_RATNUM:
#endif
                return a;
    default:
                return aerror1("bad arg for rationalize", a);
            }
        }
case TAG_BOXFLOAT:
        return rationalizef(float_of_number(a));
default:
        return aerror1("bad arg for rationalize", a);
    }
}
#endif

/*
 * Arithmetic comparison: lessp
 */

#ifdef COMMON
static CSLbool lesspis(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
/*
 * Any fixnum can be converted to a float without introducing any
 * error at all...
 */
    return (double)int_of_fixnum(a) < (double)bb.f;
}
#endif

CSLbool lesspib(Lisp_Object a, Lisp_Object b)
/*
 * a fixnum and a bignum can never be equal, and the magnitude of
 * the bignum must be at least as great as that of the fixnum, hence
 * to do a comparison I just need to look at sign of the bignum.
 */
{
    int32_t len = bignum_length(b);
    int32_t msd = bignum_digits(b)[(len-CELL-4)/4];
    CSL_IGNORE(a);
    return (msd >= 0);
}

#ifdef COMMON
static CSLbool lesspir(Lisp_Object a, Lisp_Object b)
{
/*
 * compute a < p/q  as a*q < p
 */
    push(numerator(b));
    a = times2(a, denominator(b));
    pop(b);
    return lessp2(a, b);
}
#endif

#define lesspif(a, b) ((double)int_of_fixnum(a) < float_of_number(b))

CSLbool lesspdb(double a, Lisp_Object b)
/*
 * a is a floating point number and b a bignum.  Compare them.
 */
{
    int32_t n = (bignum_length(b)-CELL-4)/4;
    int32_t bn = (int32_t)bignum_digits(b)[n];
/*
 * The value represented by b can not be in the range that fixnums
 * cover, so if a is in that range I need only inspect the sign of b.
 */
    if ((double)(-0x08000000) <= a &&
        a <= (double)(0x7fffffff))
        return (bn >= 0);
/*
 * If b is a one-word bignum I can convert it to floating point
 * with no loss of accuracy at all.
 */
    if (n == 0) return a < (double)bn;
/*
 * For two-digit bignums I first check if the float is so big that I can
 * tell that it dominames the bignum, and if not I subtract the top digit
 * of the bignum from both sides... in the critical case where the two
 * values are almost the same that subtraction will not lead to loss of
 * accuracy (at least provided that my floating point was implemented
 * with a guard bit..)
 */
    if (n == 1)
    {   if (1.0e19 < a) return NO;
        else if (a < -1.0e19) return YES;
        a -= TWO_31*(int32_t)bn;
        return a < (double)bignum_digits(b)[0];
    }
/*
 * If the two operands differ in their signs then all is easy.
 */
    if (bn >= 0 && a < 0.0) return YES;
    if (bn < 0 && a >= 0.0) return NO;
/*
 * Now I have a 3 or more digit bignum, so here I will (in effect)
 * convert the float to a bignum and then perform the comparison.. that
 * does the best I can to avoid error.  I do not actually have to create
 * a datastructure for the bignum provided I can collect up the data that
 * would have to be stored in it.  See lisp_fix (arith8.c) for related code.
 */
    {   int32_t a0, a1, a2;
        int x, x1;
        a = frexp(a, &x); /* 0.5 <= abs(a) < 1.0, x = (binary) exponent */
        if (a == 1.0) a = 0.5, x++;    /* For Zortech */
        a *= TWO_31;
        a1 = (int32_t)a;                 /* 2^31 > |a| >= 2^30 */
        if (a < 0.0) a1--;             /* now maybe a1 is -2^31 */
        a -= (double)a1;
        a2 = (uint32_t)(a * TWO_31); /* This conversion should be exact */
        x -= 62;
/*
 * If the float is smaller in absolute value than the bignum life is easy
 */
        if (x < 0) return (bn >= 0);
        x1 = x/31 + 2;
        if (n != x1)
        {   if (n < x1) return a < 0.0;
            else return (bn >= 0);
        }
/*
 * Now the most jolly bit - the two numbers have the same sign and involve
 * the same number of digits.
 */
        if (a1 < 0)
        {   a0 = -1;
            a1 = clear_top_bit(a1);
        }
        else a0 = 0;
        x = x % 31;
        a0 = (a0 << x) | (a1 >> (31-x));
        a1 = clear_top_bit(a1 << x) | (a2 >> (31-x));
        a2 = clear_top_bit(a2 << x);
        if (a0 != bn) return a0 < bn;
        bn = bignum_digits(b)[n-1];
        if (a1 != bn) return a1 < bn;
        return a2 < (int32_t)bignum_digits(b)[n-2];
    }
}

CSLbool lesspbd(Lisp_Object b, double a)
/*
 * Code as for lesspdb, but use '>' test instead of '<'
 */
{
    int32_t n = (bignum_length(b)-CELL-4)/4;
    int32_t bn = (int32_t)bignum_digits(b)[n];
/*
 * The value represented by b can not be in the range that fixnums
 * cover, so if a is in that range I need only inspect the sign of b.
 */
    if ((double)(-0x08000000) <= a &&
        a <= (double)(0x7fffffff))
        return (bn < 0);
/*
 * If b is a one-word bignum I can convert it to floating point
 * with no loss of accuracy at all.
 */
    if (n == 0) return (double)bn < a;
/*
 * For two-digit bignums I first check if the float is so big that I can
 * tell that it dominates the bignum, and if not I subtract the top digit
 * of the bignum from both sides... in the critical case where the two
 * values are almost the same that subtraction will not lead to loss of
 * accuracy (at least provided that my floating point was implemented
 * with a guard bit..)
 */
    if (n == 1)
    {   if (1.0e19 < a) return YES;
        else if (a < -1.0e19) return NO;
        a -= TWO_31 * (double)bn;
        return (double)bignum_digits(b)[0] < a;
    }
/*
 * If the two operands differ in their signs then all is easy.
 */
    if (bn >= 0 && a < 0.0) return NO;
    if (bn < 0 && a >= 0.0) return YES;
/*
 * Now I have a 3 or more digit bignum, so here I will (in effect)
 * convert the float to a bignum and then perform the comparison.. that
 * does the best I can to avoid error.  I do not actually have to create
 * a datastructure for the bignum provided I can collect up the data that
 * would have to be stored in it.  See lisp_fix (arith8.c) for related code.
 */
    {   int32_t a0, a1, a2;
        int x, x1;
        a = frexp(a, &x); /* 0.5 <= abs(a) < 1.0, x = (binary) exponent */
        if (a == 1.0) a = 0.5, x++;
        a *= TWO_31;
        a1 = (int32_t)a;        /* 2^31 > |a| >= 2^30 */
        if (a < 0.0) a1--;   /* now maybe a1 is -2^31 */
        a -= (double)a1;
        a2 = (uint32_t)(a * TWO_31); /* This conversion should be exact */
        x -= 62;
/*
 * If the float is smaller in absolute value than the bignum life is easy
 */
        if (x < 0) return (bn < 0);
        x1 = x/31 + 2;
        if (n != x1)
        {   if (n < x1) return a >= 0.0;
            else return (bn < 0);
        }
/*
 * Now the most jolly bit - the two numbers have the same sign and involve
 * the same number of digits.
 */
        if (a1 < 0)
        {   a0 = -1;
            a1 = clear_top_bit(a1);
        }
        else a0 = 0;
        x = x % 31;
        a0 = (a0 << x) | (a1 >> (31-x));
        a1 = clear_top_bit(a1 << x) | (a2 >> (31-x));
        a2 = clear_top_bit(a2 << x);
        if (a0 != bn) return a0 > bn;
        bn = bignum_digits(b)[n-1];
        if (a1 != bn) return a1 > bn;
        return a2 > (int32_t)bignum_digits(b)[n-2];
    }
}

#ifdef COMMON

static CSLbool lessprr(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object c;
    push2(a, b);
    c = times2(numerator(a), denominator(b));
    pop2(b, a);
    push(c);
    b = times2(numerator(b), denominator(a));
    pop(c);
    return lessp2(c, b);
}

CSLbool lesspdr(double a, Lisp_Object b)
/*
 * Compare float with ratio... painfully expensive.
 */
{
    Lisp_Object a1 = rationalf(a), nil;
    errexit();
    return lessprr(a1, b);
}

CSLbool lessprd(Lisp_Object a, double b)
/*
 * Compare float with ratio.
 */
{
    Lisp_Object b1 = rationalf(b), nil;
    errexit();
    return lessprr(a, b1);
}

static CSLbool lesspsi(Lisp_Object a, Lisp_Object b)
{
    Float_union aa;
    aa.i = a - TAG_SFLOAT;
    return (double)aa.f < (double)int_of_fixnum(b);
}

static CSLbool lesspsb(Lisp_Object a, Lisp_Object b)
{
    Float_union aa;
    aa.i = a - TAG_SFLOAT;
    return lesspdb((double)aa.f, b);
}

static CSLbool lesspsr(Lisp_Object a, Lisp_Object b)
{
    Float_union aa;
    aa.i = a - TAG_SFLOAT;
    return lesspdr((double)aa.f, b);
}

static CSLbool lesspsf(Lisp_Object a, Lisp_Object b)
{
    Float_union aa;
    aa.i = a - TAG_SFLOAT;
    return (double)aa.f < float_of_number(b);
}
#endif

CSLbool lesspbi(Lisp_Object a, Lisp_Object b)
{
    int32_t len = bignum_length(a);
    int32_t msd = bignum_digits(a)[(len-CELL-4)/4];
    CSL_IGNORE(b);
    return (msd < 0);
}

#ifdef COMMON
static CSLbool lesspbs(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    return lesspbd(a, (double)bb.f);
}
#endif

static CSLbool lesspbb(Lisp_Object a, Lisp_Object b)
{
    int32_t lena = bignum_length(a),
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
    /* lenb == lena here */
    {   int32_t msa = bignum_digits(a)[lena],
              msb = bignum_digits(b)[lena];
        if (msa < msb) return YES;
        else if (msa > msb) return NO;
/*
 * Now the leading digits of the numbers agree, so in particular the numbers
 * have the same sign.
 */
        while (--lena >= 0)
        {   uint32_t da = bignum_digits(a)[lena],
                       db = bignum_digits(b)[lena];
            if (da == db) continue;
            return (da < db);
        }
        return NO;      /* numbers are the same */
    }
}

#define lesspbr(a, b) lesspir(a, b)

#define lesspbf(a, b) lesspbd(a, float_of_number(b))

#ifdef COMMON

static CSLbool lesspri(Lisp_Object a, Lisp_Object b)
{
    push(numerator(a));
    b = times2(b, denominator(a));
    pop(a);
    return lessp2(a, b);
}

static CSLbool lessprs(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    return lessprd(a, (double)bb.f);
}

#define lessprb(a, b) lesspri(a, b)

#define lessprf(a, b) lessprd(a, float_of_number(b))

#endif

#define lesspfi(a, b) (float_of_number(a) < (double)int_of_fixnum(b))

#ifdef COMMON
static CSLbool lesspfs(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    return float_of_number(a) < (double)bb.f;
}
#endif

#define lesspfb(a, b) lesspdb(float_of_number(a), b)

#define lesspfr(a, b) lesspfb(a, b)

#define lesspff(a, b) (float_of_number(a) < float_of_number(b))


CSLbool greaterp2(Lisp_Object a, Lisp_Object b)
{
    return lessp2(b, a);
}

CSLbool lessp2(Lisp_Object a, Lisp_Object b)
/*
 * Note that this type-dispatch does not permit complex numbers to
 * be compared - their presence will lead to an exception being raised.
 * This shortens the code (marginally).
 */
{
    Lisp_Object nil = C_nil;
    if (exception_pending()) return NO;
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
/* For fixnums the comparison happens directly */
            return ((int32_t)a < (int32_t)b);
#ifdef COMMON
    case TAG_SFLOAT:
            return lesspis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return lesspib(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return lesspir(a, b);
#endif
        default:
                return (CSLbool)aerror2("bad arg for lessp", a, b);
                }
            }
    case TAG_BOXFLOAT:
            return lesspif(a, b);
    default:
            return (CSLbool)aerror2("bad arg for lessp", a, b);
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch (b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return lesspsi(a, b);
    case TAG_SFLOAT:
            {   Float_union aa, bb;
                aa.i = a - TAG_SFLOAT;
                bb.i = b - TAG_SFLOAT;
                return (aa.f < bb.f);
            }
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return lesspsb(a, b);
        case TYPE_RATNUM:
                return lesspsr(a, b);
        default:
                return (CSLbool)aerror2("bad arg for lessp", a, b);
                }
            }
    case TAG_BOXFLOAT:
            return lesspsf(a, b);
    default:
            return (CSLbool)aerror2("bad arg for lessp", a, b);
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
                    return lesspbi(a, b);
#ifdef COMMON
            case TAG_SFLOAT:
                    return lesspbs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return lesspbb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return lesspbr(a, b);
#endif
                default:
                        return (CSLbool)aerror2("bad arg for lessp", a, b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return lesspbf(a, b);
            default:
                    return (CSLbool)aerror2("bad arg for lessp", a, b);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch (b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return lesspri(a, b);
            case TAG_SFLOAT:
                    return lessprs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return lessprb(a, b);
                case TYPE_RATNUM:
                        return lessprr(a, b);
                default:
                        return (CSLbool)aerror2("bad arg for lessp", a, b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return lessprf(a, b);
            default:
                    return (CSLbool)aerror2("bad arg for lessp", a, b);
                }
#endif
    default:    return (CSLbool)aerror2("bad arg for lessp", a, b);
            }
        }
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return lesspfi(a, b);
#ifdef COMMON
    case TAG_SFLOAT:
            return lesspfs(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return lesspfb(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return lesspfr(a, b);
#endif
        default:
                return (CSLbool)aerror2("bad arg for lessp", a, b);
                }
            }
    case TAG_BOXFLOAT:
            return lesspff(a, b);
    default:
            return (CSLbool)aerror2("bad arg for lessp", a, b);
        }
default:
        return (CSLbool)aerror2("bad arg for lessp", a, b);
    }
}

/* end of arith04.c */
