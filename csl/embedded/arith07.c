/*  arith07.c                         Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Arithmetic functions.  negation plus a load of Common Lisp things
 * for support of complex numbers.
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



/* Signature: 55b237df 24-May-2008 */

#include "headers.h"


Lisp_Object copyb(Lisp_Object a)
/*
 * copy a bignum.
 */
{
    Lisp_Object b, nil;
    int32_t len = bignum_length(a), i;
    push(a);
    b = getvector(TAG_NUMBERS, TYPE_BIGNUM, len);
    pop(a);
    errexit();
    len = (len-CELL)/4;
    for (i=0; i<len; i++)
        bignum_digits(b)[i] = bignum_digits(a)[i];
    return b;
}

Lisp_Object negateb(Lisp_Object a)
/*
 * Negate a bignum.  Note that negating the 1-word bignum
 * value of 0x08000000 will produce a fixnum as a result,
 * which might confuse the caller... in a similar way negating
 * the value -0x40000000 will need to promote from a one-word
 * bignum to a 2-word bignum.  How messy just for negation!
 */
{
    Lisp_Object b, nil;
    int32_t len = bignum_length(a), i, carry;
    if (len == CELL+4)   /* one-word bignum - do specially */
    {   len = -(int32_t)bignum_digits(a)[0];
        if (len == fix_mask) return fixnum_of_int(len);
        else if (len == 0x40000000) return make_two_word_bignum(0, len);
        else return make_one_word_bignum(len);
    }
    push(a);
    b = getvector(TAG_NUMBERS, TYPE_BIGNUM, len);
    pop(a);
    errexit();
    len = (len-CELL)/4-1;
    carry = -1;
    for (i=0; i<len; i++)
    {   carry = clear_top_bit(~bignum_digits(a)[i]) + top_bit(carry);
        bignum_digits(b)[i] = clear_top_bit(carry);
    }
/*
 * Handle the top digit separately since it is signed.
 */
    carry = ~bignum_digits(a)[i] + top_bit(carry);
    if (!signed_overflow(carry))
    {
/*
 * If the most significant word ends up as -1 then I just might
 * have 0x40000000 in the next word down and so I may need to shrink
 * the number.  Since I handled 1-word bignums specially I have at
 * least two words to deal with here.
 */
        if (carry == -1 && (bignum_digits(b)[i-1] & 0x40000000) != 0)
        {   bignum_digits(b)[i-1] |= ~0x7fffffff;
            numhdr(b) -= pack_hdrlength(1);
            if (SIXTY_FOUR_BIT)
            {   if ((i & 1) != 0) bignum_digits(b)[i] = 0;
                else bignum_digits(b)[i] = make_bighdr(2);
            }
            else
            {   if ((i & 1) == 0) bignum_digits(b)[i] = 0;
                else bignum_digits(b)[i] = make_bighdr(2);
            }
        }
        else bignum_digits(b)[i] = carry;   /* no shrinking needed */
        return b;
    }
/*
 * Here I have overflow: this can only happen when I negate a number
 * that started off with 0xc0000000 in the most significant digit,
 * and I have to pad a zero word onto the front.
 */
    bignum_digits(b)[i] = clear_top_bit(carry);
    return lengthen_by_one_bit(b, carry);
}

/*
 * generic negation
 */

Lisp_Object negate(Lisp_Object a)
{
#ifdef COMMON
    Lisp_Object nil;  /* needed for errexit() */
#endif
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        {   int32_t aa = -int_of_fixnum(a);
/*
 * negating the number -#x8000000 (which is a fixnum) yields a value
 * which just fails to be a fixnum.
 */
            if (aa != 0x08000000) return fixnum_of_int(aa);
            else return make_one_word_bignum(aa);
        }
#ifdef COMMON
case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            aa.f = (float) (-aa.f);
            return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                return negateb(a);
#ifdef COMMON
    case TYPE_RATNUM:
                {   Lisp_Object n = numerator(a),
                                d = denominator(a);
                    push(d);
                    n = negate(n);
                    pop(d);
                    errexit();
                    return make_ratio(n, d);
                }
    case TYPE_COMPLEX_NUM:
                {   Lisp_Object r = real_part(a),
                                i = imag_part(a);
                    push(i);
                    r = negate(r);
                    pop(i);
                    errexit();
                    push(r);
                    i = negate(i);
                    pop(r);
                    errexit();
                    return make_complex(r, i);
                }
#endif
    default:
                return aerror1("bad arg for minus",  a);
            }
        }
case TAG_BOXFLOAT:
        {   double d = float_of_number(a);
            return make_boxfloat(-d, type_of_header(flthdr(a)));
        }
default:
        return aerror1("bad arg for minus",  a);
    }
}


/*****************************************************************************/
/***              Transcendental functions etcetera.                       ***/
/*****************************************************************************/


/*
 * Much of the code here is extracted from the portable Fortran library
 * used by Codemist with its Fortran compiler.
 */

/*
 * The object of the following macro is to adjust the floating point
 * variables concerned so that the more significant one can be squared
 * with NO LOSS OF PRECISION. It is only used when there is no danger
 * of over- or under-flow.
 *
 * This code is NOT PORTABLE but can be modified for use elsewhere
 * It should, however, serve for IEEE and IBM FP formats.
 */

#define _fp_normalize(high, low)                                          \
    {   double temp;           /* access to representation     */         \
        temp = high;           /* take original number         */         \
        ((int32_t *)&temp)[current_fp_rep & FP_WORD_ORDER] = 0;             \
                               /* make low part of mantissa 0  */         \
        low += (high - temp);  /* add into low-order result    */         \
        high = temp;                                                      \
    }

#ifdef COMMON

double MS_CDECL Cabs(Complex z)
{
/*
 * Obtain the absolute value of a complex number - note that the main
 * agony here is in ensuring that neither overflow nor underflow can
 * wreck the calculation.  Given ideal arithmetic the sum could be carried
 * through as just sqrt(x^2 + y^2).
 */
    double x = z.real, y = z.imag;
    double scale;
    int n1, n2;
    if (x==0.0) return fabs(y);
    else if (y==0.0) return fabs(x);
    (void)frexp(x, &n1);
    (void)frexp(y, &n2);
/* The exact range of values returned by frexp does not matter here */
    if (n2>n1) n1 = n2;
/* n1 is now the exponent of the larger (in absolute value) of x, y      */
    scale = ldexp(1.0, n1);     /* can not be 0.0                        */
    x /= scale;
    y /= scale;
/* The above scaling operation introduces no rounding error (since the   */
/* scale factor is exactly a power of 2). It reduces the larger of x, y  */
/* to be somewhere near 1.0 so overflow in x*x+y*y is impossible. It is  */
/* still possible that one of x*x and y*y will underflow (but not both)  */
/* but this is harmless.                                                 */
    return scale * sqrt(x*x + y*y);
}

Complex MS_CDECL Ccos(Complex z)
{
    double x = z.real, y = z.imag;
/*
 * cos(x + iy) = cos(x)*cosh(y) - i sin(x)*sinh(y)
 * For smallish y this can be used directly.  For |y| > 50 I will
 * compute sinh and cosh as just +/- exp(|y|)/2
 */
    double s = sin(x), c = cos(x);
    double absy = fabs(y);
    if (absy <= 50.0)
    {   double sh = sinh(y), ch = cosh(y);
        z.real = c*ch;
        z.imag = - s*sh;
        return z;
    }
    else
    {
        double w;
        int n = _reduced_exp(absy, &w) - 1;
        z.real = ldexp(c*w, n);
        if (y < 0.0) z.imag = ldexp(s*w, n);
        else z.imag = ldexp(-s*w, n);
        return z;
    }
}

static double reduced_power(double a, int n)
{
/*
 * Compute (1 + a)^n - 1 avoiding undue roundoff error.
 * Assumes n >= 1 on entry and that a is small.
 */
    if (n == 1) return a;
    {   double d = reduced_power(a, n/2);
        d = (2.0 + d)*d;
        if (n & 1) d += (1.0 + d)*a;
        return d;
    }
}

/*
 * The following value is included for documentation purposes - it
 * give the largest args that can be given to exp() without leading to
 * overflow on IEEE-arithmetic machines.
 *   #define _exp_arg_limit 709.78271289338397
 * Note that in any case exp(50.0) will not overflow (it is only 5.2e21),
 * so it can be evaluated the simple direct way.
 */

int _reduced_exp(double x, double *r)
{
/*
 * (*r) = exp(x)/2^n;   return n;
 * where n will be selected so that *r gets set to a fairly small value
 * (precise range of r unimportant provided it will be WELL away from
 * chances of overflow, even when exp(x) would actually overflow). This
 * function may only be called with argument x that is positive and
 * large enough that n will end up satisfying n>=1.  The coding here
 * will ensure that if x>4.0, and in general the use of this function
 * will only be for x > 50.
 * For IBM hardware it would be good to be able to control the value
 * of n mod 4, maybe, to help counter wobbling precision.  This is not
 * done here.
 */
    int n;
    double f;
    n = (int)(x / 7.625 + 0.5);
/*
 * 7.625 = 61/8 and is expected to have an exact floating point
 * representation here, so f is computed without any rounding error.
 * (do I need something like the (x - 0.5) - 0.5 trick here?)
 */
    f = exp(x - 7.625*(double)n);
/*
 * the magic constant is ((exp(61/8) / 2048) - 1) and it arises because
 * 61/88 is a decent rational approximation to log(2), hence exp(61/8)
 * is almost 2^11.  Thus I compute exp(x) as
 *   2^(11*n) * (exp(61/8)/2^11)^n * exp(f)
 * The first factor is exact, the second is (1+e)^n where e is small and
 * n is an integer, so can be computer accurately, and the residue f at the
 * end is small enough not to give over-bad trouble.
 * The numeric constant given here was calculated with the REDUCE 3.3
 * bigfloat package.
 */
#define _e61q8     3.81086435594567676751e-4
    *r = reduced_power(_e61q8, n)*f + f;
#undef _e61q8
    return 11*n;
}

Complex MS_CDECL Cexp(Complex z)
{
    double x = z.real, y = z.imag;
/*
 * value is exp(x)*(cos(y) + i sin(y)) but have care with overflow
 * Here (and throughout the complex library) there is an opportunity
 * to save time by computing sin(y) and cos(y) together.  Since this
 * code is (to begin with) to sit on top of an arbitrary C library,
 * perhaps with hardware support for the calculation of real-valued
 * trig functions I am not going to try to realise this saving.
 */
    double s = sin(y), c = cos(y);
/*
 * if x > 50 I will use a cautious sceme which computes exp(x) with
 * its (binary) exponent separated. Note that 50.0 is chosen as a
 * number noticably smaller than _exp_arg_limit (exp(50) = 5.18e21),
 * but is not a critical very special number.
 */
    if (x <= 50.0)      /* includes x < 0.0, of course */
    {   double w = exp(x);
        z.real = w*c;
        z.imag = w*s;
        return z;
    }
    else
    {   double w;
        int n = _reduced_exp(x, &w);
        z.real = ldexp(w*c, n);
        z.imag = ldexp(w*s, n);
        return z;
    }
}

Complex MS_CDECL Cln(Complex z)
{
    double x = z.real, y = z.imag;
/*
 * if x and y are both very large then cabs(z) may be out of range
 * even though log or if is OK.  Thus it is necessary to perform an
 * elaborate scaled calculation here, and not just
 *               z.real = log(cabs(z));
 */
    double scale, r;
    int n1, n2;
    if (x==0.0) r = log(fabs(y));
    else if (y==0.0) r = log(fabs(x));
    else
    {
        (void)frexp(x, &n1);
        (void)frexp(y, &n2);
/* The exact range of values returned by frexp does not matter here */
        if (n2>n1) n1 = n2;
        scale = ldexp(1.0, n1);
        x /= scale;
        y /= scale;
        r = log(scale) + 0.5*log(x*x + y*y);
    }
    z.real = r;
/*
 * The C standard is not very explicit about the behaviour of atan2(0.0, -n)
 * while for Fortran it is necessary that this returns +pi not -pi.  Hence
 * with extreme caution I put a special test here.
 */
    if (y == 0.0)
        if (x < 0.0) z.imag = _pi;
        else z.imag = 0.0;
    else z.imag = atan2(y, x);
    return z;
}


/*
 * Complex raising to a power.  This seems to be pretty nasty
 * to get right, and the code includes extra high precision variants
 * on atan() and log().  Further refinements wrt efficiency may be
 * possible later on.
 * This code has been partially tested, and seems to be uniformly
 * better than using just a**b = exp(b*log(a)), but much more careful
 * study is needed before it can possibly be claimed that it is
 * right in the sense of not throwing away accuracy when it does not
 * have to.  I also need to make careful checks to verify that the
 * correct (principal) value is computed.
 */

/*
 * The next function is used after arithmetic has been done on extra-
 * precision numbers so that the relationship between high and low parts
 * is no longer known.  Re-instate it.
 */

#define _two_minus_25 2.98023223876953125e-8 /* 2^(-25) */

static double fp_add(double a, double b, double *lowres)
{
/* Result is the high part of a+b, with the low part assigned to *lowres */
    double absa, absb;
    if (a >= 0.0) absa = a; else absa = -a;
    if (b >= 0.0) absb = b; else absb = -b;
    if (absa < absb)
    {   double t = a; a = b; b = t;
    }
/* Now a is the larger (in absolute value) of the two numbers */
    if (absb > absa * _two_minus_25)
    {   double al = 0.0, bl = 0.0;
/*
 * If the exponent difference beweeen a and b is no more than 25 then
 * I can add the top part (20 or 24 bits) of a to the top part of b
 * without going beyond the 52 or 56 bits that a full mantissa can hold.
 */
        _fp_normalize(a, al);
        _fp_normalize(b, bl);
        a = a + b;              /* No rounding needed here */
        b = al + bl;
        if (a == 0.0)
        {   a = b;
            b = 0.0;
        }
    }
/*
 * The above step leaves b small wrt the value in a (unless a+b led
 * to substantial cancellation of leading digits), but leaves the high
 * part a with bits everywhere.  Force low part of a to zero.
 */
    {   double al = 0.0;
        _fp_normalize(a, al);
        b = b + al;
    }
    if (a >= 0.0) absa = a; else absa = -a;
    if (b >= 0.0) absb = b; else absb = -b;
    if (absb > absa * _two_minus_25)
/*
 * If on input a is close to -b, then a+b is close to zero.  In this
 * case the exponents of a abd b matched, and so earlier calculations
 * have all been done exactly.  Go around again to split residue into
 * high and low parts.
 */
    {   double al = 0.0, bl = 0.0;
        _fp_normalize(b, bl);
        a = a + b;
        _fp_normalize(a, al);
        b = bl + al;
    }
    *lowres = b;
    return a;
}

#undef _two_minus_25

static void extended_atan2(double b, double a, double *thetah, double *thetal)
{
    int octant;
    double rh, rl, thh, thl;
/*
 * First reduce the argument to the first octant (i.e. a, b both +ve,
 * and b <= a).
 */
    if (b < 0.0)
    {   octant = 4;
        a = -a;
        b = -b;
    }
    else octant = 0;
    if (a < 0.0)
    {   double t = a;
        octant += 2;
        a = b;
        b = -t;
    }
    if (b > a)
    {   double t = a;
        octant += 1;
        a = b;
        b = t;
    }

    {   static struct { double h; double l;} _atan[] = {
/*
 * The table here gives atan(n/16) in 1.5-precision for n=0..16
 * Note that all the magic numbers used in this file were calculated
 * using the REDUCE bigfloat package, and all the 'exact' parts have
 * a denominator of at worst 2^26 and so are expected to have lots
 * of trailing zero bits in their floating point representation.
 */
            { 0.0,                        0.0 },
            { 0.06241881847381591796875,  -0.84778585694947708870e-8 },
            { 0.124355018138885498046875, -2.35921240630155201508e-8 },
            { 0.185347974300384521484375, -2.43046897565983490387e-8 },
            { 0.2449786663055419921875,   -0.31786778380154175187e-8 },
            { 0.302884876728057861328125, -0.83530864557675689054e-8 },
            { 0.358770668506622314453125,  0.17639499059427950639e-8 },
            { 0.412410438060760498046875,  0.35366268088529162896e-8 },
            { 0.4636476039886474609375,    0.50121586552767562314e-8 },
            { 0.512389481067657470703125, -2.07569197640365239794e-8 },
            { 0.558599293231964111328125,  2.21115983246433832164e-8 },
            { 0.602287352085113525390625, -0.59501493437085023057e-8 },
            { 0.643501102924346923828125,  0.58689374629746842287e-8 },
            { 0.6823165416717529296875,    1.32029951485689299817e-8 },
            { 0.71882998943328857421875,   1.01883359311982641515e-8 },
            { 0.75315129756927490234375,  -1.66070805128190106297e-8 },
            { 0.785398185253143310546875, -2.18556950009312141541e-8 }
                                                              };
        int k = (int)(16.0*(b/a + 0.03125)); /* 0 to 16 */
        double kd = (double)k/16.0;
        double ah = a, al = 0.0,
               bh = b, bl = 0.0,
               ch, cl, q, q2;
        _fp_normalize(ah, al);
        _fp_normalize(bh, bl);
        ch = bh - ah*kd; cl = bl - al*kd;
        ah = ah + bh*kd; al = al + bl*kd;
        bh = ch; bl = cl;
/* Now |(a/b)| <= 1/32 */
        ah = fp_add(ah, al, &al);       /* Re-normalise */
        bh = fp_add(bh, bl, &bl);
/* Compute approximation to b/a */
        rh = (bh + bl)/(ah + al); rl = 0.0;
        _fp_normalize(rh, rl);
        bh -= ah*rh; bl -= al*rh;
        rl = (bh + bl)/(ah + al);   /* Quotient now formed */
/*
 * Now it is necessary to compute atan(q) to one-and-a-half precision.
 * Since |q| < 1/32 I will leave just q as the high order word of
 * the result and compute atan(q)-q as a single precision value. This
 * gives about 16 bits accuracy beyond regular single precision work.
 */
        q = rh + rl;
        q2 = q*q;
/* The expansion the follows could be done better using a minimax poly */
        rl -= q*q2*(0.33333333333333333333 -
                q2*(0.20000000000000000000 -
                q2*(0.14285714285714285714 -
                q2*(0.11111111111111111111 -
                q2* 0.09090909090909090909))));
/* OK - now (rh, rl) is atan(reduced b/a).  Need to add on atan(kd) */
        rh += _atan[k].h;
        rl += _atan[k].l;
    }
/*
 * The following constants give high precision versions of pi and pi/2,
 * and the high partwords (p2h and pih) have lots of low order zero bits
 * in their binary representation.  Expect (=require) that the arithmetic
 * that computes thh is done without introduced rounding error.
 */
#define _p2h    1.57079632580280303955078125
#define _p2l    9.92093579680540441639751e-10

#define _pih    3.14159265160560607910156250
#define _pil    1.984187159361080883279502e-9

    switch (octant)
    {
default:
case 0: thh = rh;          thl = rl;          break;
case 1: thh = _p2h - rh;   thl = _p2l - rl;   break;
case 2: thh = _p2h + rh;   thl = _p2l + rl;   break;
case 3: thh = _pih - rh;   thl = _pil - rl;   break;
case 4: thh = -_pih + rh;  thl = -_pil + rl;  break;
case 5: thh = -_p2h - rh;  thl = -_p2l - rl;  break;
case 6: thh = -_p2h + rh;  thl = -_p2l + rl;  break;
case 7: thh = -rh;         thl = -rl;         break;
    }

#undef _p2h
#undef _p2l
#undef _pih
#undef _pil

    *thetah = fp_add(thh, thl, thetal);
}

static void extended_log(int k, double a, double b,
                         double *logrh, double *logrl)
{
/*
 * If we had exact arithmetic this procedure could be:
 *      k*log(2) + 0.5*log(a^2 + b^2)
 */
    double al = 0.0, bl = 0.0, all = 0.0, bll = 0.0, c, ch, cl, cll;
    double w, q, qh, ql, rh, rl;
    int n;
/*
 * First (a^2 + b^2) is calculated, using extra precision.
 * Because any rounding at this stage can lead to bad errors in
 * the power that I eventually want to compute, I use 3-word
 * arithmetic here, and with the version of _fp_normalize given
 * above and IEEE or IBM370 arithmetic this part of the
 * computation is exact.
 */
    _fp_normalize(a, al); _fp_normalize(al, all);
    _fp_normalize(b, bl); _fp_normalize(bl, bll);
    ch = a*a + b*b;
    cl = 2.0*(a*al + b*bl);
    cll = (al*al + bl*bl) +
          all*(2.0*(a + al) + all) +
          bll*(2.0*(b + bl) + bll);
    _fp_normalize(ch, cl);
    _fp_normalize(cl, cll);
    c = ch + (cl + cll);        /* single precision approximation */
/*
 * At this stage the scaling of the input value will mean that we
 * have 0.25 <= c <= 2.0
 *
 * Now rewrite things as
 *      (2*k + n)*log(s) + 0.5*log((a^2 + b^2)/2^n))
 *           where s = sqrt(2)
 * and where the arg to the log is in sqrt(0.5), sqrt(2)
 */

#define _sqrt_half 0.70710678118654752440
#define _sqrt_two  1.41421356237309504880
    k = 2*k;
    while (c < _sqrt_half)
    {   k   -= 1;
        ch  *= 2.0;
        cl  *= 2.0;
        cll *= 2.0;
        c   *= 2.0;
    }
    while (c > _sqrt_two)
    {   k   += 1;
        ch  *= 0.5;
        cl  *= 0.5;
        cll *= 0.5;
        c   *= 0.5;
    }
#undef _sqrt_half
#undef _sqrt_two
    n = (int)(16.0/c + 0.5);
    w = (double)n / 16.0;
    ch *= w;
    cl *= w;
    cll *= w;           /* Now |c-1| < 0.04317 */
    ch = (ch - 0.5) - 0.5;
    ch = fp_add(ch, cl, &cl);
    cl = cl + cll;
/*
 * (ch, cl) is now the reduced argument ready for calculating log(1+c),
 * and now that the reduction is over I can drop back to the use of just
 * two doubleprecision values to represent c.
 */
    c = ch + cl;
    qh = c / (2.0 + c);
    ql = 0.0;
    _fp_normalize(qh, ql);
    ql = ((ch - qh*(2.0 + ch)) + cl - qh*cl) / (2.0 + c);
/* (qh, ql) is now c/(2.0 + c) */
    rh = qh;  /* 18 bits bigger than low part will end up */
    q = qh + ql;
    w = q*q;
    rl = ql + q*w*(0.33333333333333333333 +
                w*(0.20000000000000000000 +
                w*(0.14285714285714285714 +
                w*(0.11111111111111111111 +
                w*(0.09090909090909090909)))));
/*
 * (rh, rl) is now atan(c) correct to double precision plus about 18 bits.
 */

    {   double temp;
        static struct { double h; double l; } _log_table[] = {
/*
 * The following values are (in extra precision) -log(n/16)/2 for n
 * in the range 11 to 23 (i.e. roughly over sqrt(2)/2 to sqrt(2))
 */
            {  0.1873466968536376953125,    2.786706765149099245e-8 },
            {  0.1438410282135009765625,    0.801238948715710950e-8 },
            {  0.103819668292999267578125,  1.409612298322959552e-8 },
            {  0.066765725612640380859375, -2.930037906928620319e-8 },
            {  0.0322692394256591796875,    2.114312640614896196e-8 },
            {  0.0,                         0.0                     },
            { -0.0303122997283935546875,   -1.117982386660280307e-8 },
            { -0.0588915348052978515625,    1.697710612429310295e-8 },
            { -0.08592510223388671875,     -2.622944289242004947e-8 },
            { -0.111571788787841796875,     1.313073691899185245e-8 },
            { -0.135966837406158447265625, -2.033566243215020975e-8 },
            { -0.159226894378662109375,     2.881939480146987639e-8 },
            { -0.18145275115966796875,      0.431498374218108783e-8 }};

        rh = fp_add(rh, _log_table[n-11].h, &temp);
        rl = temp + _log_table[n-11].l + rl;
    }

#define _exact_part_logroot2    0.3465735912322998046875
#define _approx_part_logroot2   (-9.5232714997888393927e-10)
/* Multiply this by k and add it in */
    {   double temp, kd = (double)k;
        rh = fp_add(rh, kd*_exact_part_logroot2, &temp);
        rl = rl + temp + kd*_approx_part_logroot2;
    }
#undef _exact_part_logroot2
#undef _approx_part_logroot2

    *logrh = rh;
    *logrl = rl;
    return;
}


Complex MS_CDECL Cpow(Complex z1, Complex z2)
{
    double a = z1.real, b = z1.imag,
           c = z2.real, d = z2.imag;
    int k, m, n;
    double scale;
    double logrh, logrl, thetah, thetal;
    double r, i, rh, rl, ih, il, clow, dlow, q;
    double cw, sw, cost, sint;

    if (b == 0.0 && d == 0.0 && a >= 0.0)/* Simple case if both args are real */
    {   z1.real = pow(a, c);
        z1.imag = 0.0;
        return z1;
    }
/*
 * Start by scaling z1 by dividing out a power of 2 so that |z1| is
 * fairly close to 1
 */
    if (a == 0.0)
    {   if (b == 0.0) return z1;    /* 0.0**anything is really an error */
/* The exact values returned by frexp do not matter here */
        (void)frexp(b, &k);
    }
    else
    {   (void)frexp(a, &k);
        if (b != 0.0)
        {   int n;
            (void)frexp(b, &n);
            if (n > k) k = n;
        }
    }
    scale = ldexp(1.0, k);
    a /= scale;
    b /= scale;
/*
 * The idea next is to express z1 as r*exp(i theta), then z1**z2
 * is exp(z2*log(z1)) and the exponent simplifies to
 *             (c*log r - d*theta) + i(c theta + d log r).
 * Note r = scale*sqrt(a*a + b*b) now.
 * The argument for exp() must be computed to noticably more than
 * regular precision, since otherwise exp() greatly magnifies the
 * error in the real part (if it is large and positive) and range
 * reduction in the imaginary part can equally lead to accuracy
 * problems.  Neither c nor d can usefully be anywhere near the
 * extreme range of floating point values, so I will not even try
 * to scale them, thus I will end up happy(ish) if I can compute
 * atan2(b, a) and log(|z1|) in one-and-a-half precision form.
 * It would be best to compute theta in units of pi/4 rather than in
 * raidians, since then the case of z^n (integer n) with arg(z) an
 * exact multiple of pi/4 would work out better. However at present I
 * just hope that the 1.5-precision working is good enough.
 */
    extended_atan2(b, a, &thetah, &thetal);
    extended_log(k, a, b, &logrh, &logrl);

/* Normalise all numbers */
    clow = 0.0;
    dlow = 0.0;
    _fp_normalize(c, clow);
    _fp_normalize(d, dlow);

/*  (rh, rl) = c*logr - d*theta; */
    rh = c*logrh - d*thetah;  /* No rounding in this computation */
    rl = c*logrl + clow*(logrh + logrl) - d*thetal - dlow*(thetah + thetal);

/*  (ih, il) = c*theta + d*logr; */
    ih = c*thetah + d*logrh;  /* No rounding in this computation */
    il = c*thetal + clow*(thetah + thetal) + d*logrl + dlow*(logrh + logrl);

/*
 * Now it remains to take the exponential of the extended precision
 * value in ((rh, rl), (ih, il)).
 * Range reduce the real part by multiples of log(2), and the imaginary
 * part by multiples of pi/2.
 */

    rh = fp_add(rh, rl, &rl);   /* renormalise */
    r = rh + rl;                /* Approximate value */

#define _recip_log_2 1.4426950408889634074

    q = r * _recip_log_2;
    m = (q < 0.0) ? (int)(q - 0.5) : (int)(q + 0.5);
    q = (double)m;
#undef _recip_log_2
/*
 * log 2 = 11629080/2^24  - 0.000 00000 19046 54299 95776 78785
 * to reasonable accuracy.  It is vital that the exact part be
 * read in as a number with lots of low zero bits, so when it gets
 * multiplied by the integer q there is NO rounding needed.
 */

#define _exact_part_log2    0.693147182464599609375
#define _approx_part_log2 (-1.9046542999577678785418e-9)
    rh = rh - q*_exact_part_log2;
    rl = rl - q*_approx_part_log2;
#undef _exact_part_log2
#undef _approx_part_log2
    r = exp(rh + rl);        /* This should now be accurate enough */

    ih = fp_add(ih, il, &il);
    i = ih + il;        /* Approximate value */

#define _recip_pi_by_2 0.6366197723675813431

    q = i * _recip_pi_by_2;
    n = (q < 0.0) ? (int)(q - 0.5) : (int)(q + 0.5);
    q = (double)n;
/*
 * pi/2 = 105414357/2^26 + 0.000 00000 09920 93579 68054 04416 39751
 * to reasonable accuracy.  It is vital that the exact part be
 * read in as a number with lots of low zero bits, so when it gets
 * multiplied by the integer q there is NO rounding needed.
 */

#define _exact_part_pi2    1.57079632580280303955078125
#define _approx_part_pi2   9.92093579680540441639751e-10
    ih = ih - q*_exact_part_pi2;
    il = il - q*_approx_part_pi2;
#undef _recip_pi_by_2
#undef _exact_part_pi2
#undef _approx_part_pi2
    i = ih + il;            /* Now accurate enough */
/*
 * Having done super-careful range reduction I can call the regular
 * sin/cos routines here.  If sin/cos could both be computed together
 * that could speed things up a little bit, but by this stage they have
 * not much in common.
 */
    cw = cos(i);
    sw = sin(i);
    switch (n & 3)  /* quadrant control */
    {
default:
case 0: cost = cw;  sint = sw;  break;
case 1: cost = -sw; sint = cw;  break;
case 2: cost = -cw; sint = -sw; break;
case 3: cost = sw;  sint = -cw; break;
    }

/*
 * Now, at long last, I can assemble the results and return.
 */

    z1.real = ldexp(r*cost, m);
    z1.imag = ldexp(r*sint, m);
    return z1;
}

/*
 * End of complex-to-complex-power code.
 */

#endif

/* end of arith07.c */
