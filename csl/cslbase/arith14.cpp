//  arith14.cpp                                Copyright (C) 2016 Codemist

//
// Support for 128-bit floats
//

/**************************************************************************
 * Copyright (C) 2016, Codemist Ltd.                     A C Norman       *
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

// $Id: arith01.cpp 3480 2016-02-25 18:10:02Z arthurcnorman $

#include "headers.h"

// It is convenient to have a number of constants available. The
// values I have here are 0, 1, 10, 0.1, 10^17, 10^18 and 2^4096
// all as 128-bit numbers, and 1, 10 and 0.1 as 256-bit ones.

#ifdef LITTLEENDIAN

float128_t f128_0      = {0, 0x0000000000000000},
           f128_1      = {0, 0x3fff000000000000},
           f128_10_17  = {0, 0x40376345785d8a00},
           f128_10_18  = {0, 0x403abc16d674ec80},
           f128_N1     = {0, 0x4fff000000000000}; // 2^4096

float256_t f256_1      = {{0,0}, {0, 0x3fff000000000000}},         //@
           f256_10     = {{0,0}, {0, 0x4002400000000000}},
           f256_r10    = {{0x3333333333333333, 0x3f8a333333333333},
                          {0x9999999999999999, 0x3ffb999999999999}};
#else

float128_t f128_0      = {0x0000000000000000, 0},
           f128_1      = {0x3fff000000000000, 0},
           f128_10_17  = {0x40376345785d8a00, 0},
           f128_10_18  = {0x403abc16d674ec80, 0},
           f128_N1     = {0x4fff000000000000, 0};

float256_t f256_1      = {{0x3fff000000000000, 0}, {0,0}},         //@
           f256_10     = {{0x4002400000000000, 0}, {0,0}},
           f256_r10    = {{0x3ffb999999999999, 0x9999999999999999},
                          {0x3f8a333333333333, 0x3333333333333333}};
#endif



bool f128M_zero(const float128_t *p)
{
#ifdef LITTLEENDIAN
    return ((p->v[1] & 0x7fffffffffffffff) == 0) &&
            (p->v[0] == 0);
#else
    return ((p->v[0] & 0x7fffffffffffffff) == 0) &&
            (p->v[1] == 0);
#endif
}

bool f128M_infinite(const float128_t *p)
{
#ifdef LITTLEENDIAN
    return (((p->v[1] >> 48) & 0x7fff) == 0x7fff) &&
            ((p->v[1] & 0xffffffffffff) == 0) &&
            (p->v[0] == 0);
#else
    return (((p->v[0] >> 48) & 0x7fff) == 0x7fff) &&
            ((p->v[0] & 0xffffffffffff) == 0) &&
            (p->v[1] == 0);
#endif
}

// Here I do not count 0.0 (or -0.0) as sub-normal.

bool f128M_subnorm(const float128_t *p)
{
#ifdef LITTLEENDIAN
    return (((p->v[1] >> 48) & 0x7fff) == 0) &&
            (((p->v[1] & 0xffffffffffff) != 0) ||
             (p->v[0] != 0));
#else
    return (((p->v[0] >> 48) & 0x7fff) == 0) &&
            (((p->v[0] & 0xffffffffffff) != 0) ||
             (p->v[1] != 0));
#endif
}

bool f128M_nan(const float128_t *p)
{
#ifdef LITTLEENDIAN
    return (((p->v[1] >> 48) & 0x7fff) == 0x7fff) &&
            (((p->v[1] & 0xffffffffffff) != 0) ||
             (p->v[0] != 0));
#else
    return (((p->v[0] >> 48) & 0x7fff) == 0x7fff) &&
            (((p->v[0] & 0xffffffffffff) != 0) ||
             (p->v[1] != 0));
#endif
}

bool f128M_negative(const float128_t *x)
{
    if (f128M_nan(x)) return false;
#ifdef LITTLEENDIAN
    return ((int64_t)x->v[1]) < 0;
#else
    return ((int64_t)x->v[0]) < 0;
#endif
}

int f128M_exponent(const float128_t *p)
{
#ifdef LITTLEENDIAN
    return ((p->v[1] >> 48) & 0x7fff) - 0x3fff;
#else
    return ((p->v[0] >> 48) & 0x7fff) - 0x3fff;
#endif
}

void f128M_set_exponent(float128_t *p, int n)
{
#ifdef LITTLEENDIAN
    p->v[1] = (p->v[1] & 0x8000ffffffffffff) | (((uint64_t)n + 0x3fff) << 48);
#else
    p->v[0] = (p->v[0] & 0x8000ffffffffffff) | (((uint64_t)n + 0x3fff) << 48);
#endif
}

void f128M_ldexp(float128_t *p, int x)
{
    if (f128M_zero(p) ||
        f128M_infinite(p) ||
        f128M_nan(p)) return;  // special cases!
#ifdef LITTLEENDIAN
    int i = 1;
#else
    int i = 0;
#endif
    x = ((p->v[i] >> 48) & 0x7fff) + x;
// In case of overflow leave an infinity of the right sign.
    if (x >= 0x7fff)
    {   p->v[i] |= 0x7fff000000000000;
        p->v[i] &= 0xffff000000000000;
        p->v[1-i] = 0;
    }
    if (x < -114) // Without doubt underflowing to zero
    {   p->v[i] &= 0x7fffffffffffffff; // preserve sign of input
        p->v[1-i] = 0;
        return;
    }
// In the case that ldexp underflows I have to be especially careful
// because of the joys of sub-normalised numbers and gradual underflow.
// I deal with this by first forcing the exponent to be one that will
// not lead to a sub-norm and then using a multiply to scale it down.
    if (x <= 0)
    {   p->v[i] = (p->v[i] & 0x8000ffffffffffff) | ((uint64_t)(x+4096) << 48);
        float128_t w1;
        f128M_div(p, &f128_N1, &w1);
        *p = w1;
    }
    else p->v[i] = (p->v[i] & 0x8000ffffffffffff) | ((uint64_t)x << 48);
}

void f128M_negate(float128_t *x)
{
#ifdef LITTLEENDIAN
    x->v[1] ^= 0x8000000000000000;
#else
    x->v[0] ^= 0x8000000000000000;
#endif
}

// I will want working precision even higher than 128-bits. I will
// arrange that using pairs of 128-bit floats such that the value
// I am representing is their sum. The code I have here will not be
// robust against issues of denormailised numbers, infinities or
// NaNs, and so its use needs to take care to avoid such cases.
//
// I am following the scheme from T J Dekker, Numer Math 18 224-242 (1971).


// f256M_add adds two long numbers. As noted avove you should keep the
// arguments well away from cases where the result might underflow or
// overflow. The result should end up with almost 224 bits of precision,
// but it does not pretend to get rounding utterly correct.

void f256M_add(const float256_t *x, const float256_t *y, float256_t *z)
{
    float128_t r, s, w1, w2, w3;
// r = x->hi + y->hi
    f128M_add(&x->hi, &y->hi, &r);
// compute abs(x->hi) and abs(y->hi)
    w1 = x->hi;
    if (f128M_negative(&x->hi)) f128M_negate(&w1);
    w2 = y->hi;
    if (f128M_negative(&y->hi)) f128M_negate(&w2);
    if (f128M_lt(&w2, &w1))  // abs(y) < abs(x)
    {   // s = x->hi - r + y->hi + y->lo + x->lo;
        f128M_sub(&x->hi, &r, &w1);
        f128M_add(&w1, &y->hi, &w2);
        f128M_add(&w2, &y->lo, &w3);
        f128M_add(&w3, &x->lo, &s);
    }
    else
    {   // s = y->hi - r + x->hi + x->lo + y->lo
        f128M_sub(&y->hi, &r, &w1);
        f128M_add(&w1, &x->hi, &w2);
        f128M_add(&w2, &x->lo, &w3);
        f128M_add(&w3, &y->lo, &s);
    }
    f128M_add(&r, &s, &z->hi);
    f128M_sub(&r, &z->hi, &w1);
    f128M_add(&w1, &s, &z->lo);
}

void f128M_split(const float128_t *x, float128_t *yhi, float128_t *ylo)
{
    *yhi = *x;
// I clear 57 bits at the low end of yhi. This leaves 56 bits (maximum) in
// the mantissa, and if you multiply two values each of which have just 56
// bits the result as a float128 should be exact.
#ifdef LITTLEENDIAN
    yhi->v[0] &= ~0x1ffffffffffffff;
#else
    yhi->v[1] &= ~0x1ffffffffffffff;
#endif
    f128M_sub(x, yhi, ylo);
}

// f128M_mul2 multiplies two 128-bit floats and yields a result that
// is almost correct to the full precision of a 256-bit float.

static void f128M_mul2(const float128_t *x, const float128_t *y, float256_t *z)
{
    float128_t xhi, xlo, yhi, ylo, p, q, w1, w2;
    f128M_split(x, &xhi, &xlo);
    f128M_split(y, &yhi, &ylo);
// p is a fully accurate product of the top halves of x and y
    f128M_mul(&xhi, &yhi, &p);
// q will be xhi*ylo+xlo*yhi
    f128M_mul(&xhi, &ylo, &w1);
    f128M_mul(&xlo, &yhi, &w2);
    f128M_add(&w1, &w2, &q);
// The top half of the result is p+q
    f128M_add(&p, &q, &z->hi);
// The bottom half is p - zhi + q + (xlo*ylo)
    f128M_sub(&p, &z->hi, &w1);
    f128M_add(&w1, &q, &w2);
    f128M_mul(&xlo, &ylo, &w1);
    f128M_add(&w2, &w1, &z->lo);
}

// f256M_mul multiplies two 256-bit values to get a 256-bit result.

void f256M_mul(const float256_t *x, const float256_t *y, float256_t *z)
{
    float256_t c;
    float128_t w1, w2, w3;
// mul2 generates a double-precision product of the high parts.
    f128M_mul2(&x->hi, &y->hi, &c);
// c.lo = x->hi*y->lo + x->lo*y->hi + c.lo
    f128M_mul(&x->hi, &y->lo,  &w1);
    f128M_mul(&x->lo,  &y->hi, &w2);
    f128M_add(&w1, &w2, &w3);
    f128M_add(&w3, &c.lo, &w1);
    c.lo = w1;
// z->hi = c.hi + c.lo
    f128M_add(&c.hi, &c.lo, &z->hi);
// z->lo = c.hi - z->hi + c.lo
    f128M_sub(&c.hi, &z->hi, &w1);
    f128M_add(&w1, &c.lo, &z->lo);
}

// y := x^n where n is a positive integer.

static void f256M_pow(const float256_t *x, unsigned int n, float256_t *y)
{
    if (n == 0)
    {   y->hi = f128_1;
        y->lo = f128_0;
        return;
    }
    else if (n == 1)
    {   *y = *x;
        return;
    }
    float256_t w1, w2;
    f256M_mul(x, x, &w1);
    f256M_pow(&w1, n/2, &w2);
    if ((n % 2) == 0) *y = w2;
    else f256M_mul(&w2, x, y);
}

// This is code to print a float128_t value. That may require 34 decimal
// digits. Note that it uses 256-bit floats for internal working so that
// it stands a chance of avoiding loss of accuracy.


// This converts a number from foating point to character representation.
// The reult is true if the original number was nagative, and *pdecexp gets
// the decimal exponent. The buffer s is filled with 34 digits (or one of the
// strings "inf" or "nan" plus a terminating nul.In a printed representation
// these digits need displaying as [-]d.dddddddddExxx

bool f128M_sprint(char *s, float128_t *p, int *pdecexp)
{
//  printf("raw data: %.16" PRIx64 " %.16" PRIx64 "\n", p->v[0], p->v[1]);
// I deal with a number of special cases first. +0.0 and -0.0 ...
    if (f128M_eq(p, &f128_0))
    {   for (int i=0; i<34; i++) *s++ = '0';
        *s++ = 0;
        *pdecexp = 0;
        return f128M_negative(p);
    }
// +inf and -inf
    if (f128M_infinite(p))
    {   *s++ = 'i';
        *s++ = 'n';
        *s++ = 'f';
        *s++ = 0;
        *pdecexp = 0;
        return f128M_negative(p);
;
    }
// NaNs. I do not distinguish between signalling and non-signalling ones.
    int exponent = f128M_exponent(p);
    if (exponent == 0x4000) // A NaN, because I have already handled infinity
    {   *s++ = 'n';
        *s++ = 'a';
        *s++ = 'n';
        *s++ = 0;
        *pdecexp = 0;
        return false;
    }
// For sub-normal numbers the exponent is stored as a magic value. To find
// out what it REALLY is I will multiply the number by 2^4096. Because I know
// it is tiny that will not overflow, but it will put it back in the range of
// proper normalised numbers. So I can look at its exponent in a normal
// via that adjusted version. Multiplying by an exact power of two should
// never lose information or trigger rounding.
    if (exponent == -0x3fff) // a sub-normal number
    {   float128_t w3;
        f128M_mul(p, &f128_N1, &w3); // multiply by 2^4096
        exponent = f128M_exponent(&w3) - 0x1000;
    }
// Now remove the sign bit, and while doing I will expand this to be a 256
// bit float because I am liable to need to scale it.
    float256_t w1, w2;
    w1.hi = *p;
    w1.lo = f128_0;
    bool result = false;
    if (f128M_negative(&w1.hi))
    {   result = true;
        f128M_negate(&w1.hi);
    }
// Now the decimal exponent will be around exponent*log_{10}(2)
   double d_decexp = 0.301029995663981195*(double)exponent;
// Now I want to multiply the value I have by 10^(-decexp)
//  printf("d_decexp = %.3f\n", d_decexp);
    int decexp = 0;
    if (d_decexp >= 18.0)
    {   float256_t w3;
// multiply by a power of 0.1
        f256M_pow(&f256_r10, decexp = (int)(d_decexp-17.0), &w3);
        f256M_mul(&w1, &w3, &w2);
    }
    else if (d_decexp < 17.0)
    {   float256_t w3;
// multiply by a power of 10.0
        f256M_pow(&f256_10, decexp = (int)(18.0-d_decexp), &w3);
        decexp = -decexp;
        f256M_mul(&w1, &w3, &w2);
    }
    else w2 = w1;
// Now I rather expect that w2 is not that far from 1.0e17. Further the
// above scaling will have performed at most around 30 multiplications
// so can not have wrecked accuracy TOO much. I will do the final adjustment
// simply. If I scale the the range [1.0e17, 10.0e18) then I think that the
// tests are reasonably easy to perform provided I believe that the
// high part of a float256_t is rounded properly.
//  printf("near 1.0: %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//          w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
// While hi<1.0e17 or (hi==1.0e17 && lo<0.0) ...
    while (f128M_lt(&w2.hi, &f128_10_17) ||
           (f128M_eq(&w2.hi, &f128_10_17) &&
            f128M_lt(&w2.lo, &f128_0)))
    {   float256_t w3;
        f256M_mul(&w2, &f256_10, &w3);
        w2 = w3;
//      printf("times 10: %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//              w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
        decexp--;
    }
// while hi>=10.0e18 or (hi==10.0e18 && lo>0.0) ...
    while (!f128M_lt(&w2.hi, &f128_10_18) ||
           (f128M_eq(&w2.hi, &f128_10_18) &&
            !f128M_lt(&w2.lo, &f128_0)))
    {   float256_t w3;
        f256M_mul(&w2, &f256_r10, &w3);
        w2 = w3;
//      printf("div 10: %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//              w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
        decexp++;
    }
// Now w2 should be neatly in the range 1.0e17 to 9.99999999999...e17. I will
// consolidate all of it into the 128-bit top half.
//  printf("[1,10): %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//          w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
    float128_t v;
    f128M_add(&w2.hi, &w2.lo, &v);
//  printf("[1.0e17,1.0e18) as single: %.16" PRIx64 " %.16" PRIx64 "\n", v.v[0], v.v[1]);
    uint64_t d = f128M_to_ui64_r_minMag(&v, false);
    s += sprintf(s, "%.17" PRIu64, d);
    float128_t w3, w4;
    i64_to_f128M(-d, &w3);
    f128M_add(&v, &w3, &w4);
//  printf("sub digit: %.16" PRIx64 " %.16" PRIx64 "\n", w4.v[0], w4.v[1]);
    f128M_mul(&w4, &f128_10_17, &v);
    d = f128M_to_ui64_r_minMag(&v, false);
    s += sprintf(s, "%.17" PRIu64, d);
    *pdecexp = decexp + 17;
    return result;
}

void f128M_print(float128_t *p)
{   char s[36];
    int decexp;
    bool neg = f128M_sprint(s, p, &decexp);
    if (!isdigit(s[0])) printf("%s%s\n", neg ? "-" : "", s);
    else printf("%s%c.%sQ%d\n", neg ? "-" : "", s[0], &s[1], decexp);
}

// This rounds the number in the buffer to have ndigits after where the
// decimal point will be. 
// When I round it is possible to generate an overflow. Consider the case of
// 9.9996 rounded to 3 figures after the point. It should end up as
// 10.000, except that what I want to do is shift that along so it comes
// out as "1.000" with the exponent incremented. Roudning to 0 digits will
// leave just the integer part, while rounding to 33 (or more) places
// should not change anything because there are no digits beyond there.

static bool round_at(char *s, int ndigits)
{
    if (ndigits < 0 || ndigits >= 33) return false;
// If the digits just beyond where I am is < '5' I will truncate down.
    if (s[ndigits+1] < '5') return false;
// If the digits beyond where I am are "50000...0" and I the digit I would
// change on rounding up is even then I will round down.
    if (s[ndigits+1] == '5' && (s[ndigits]%2 == 0))
    {   int p = ndigits+2;
        while (p < 34 && s[p] == '0') p++;
        if (p >= 34) return false;
    }
// Here I need to round up.
    int p = ndigits;
    while (p >= 0)
    {   if (s[p] != '9')
        {   s[p]++;
            return false;
        }
        s[p--] = '0';  // need to carry.
    }
// If I haev dropped out of the loop it means that I have rounded an
// initial '9' up.
    s[0] = '1';        // the remaining relevant digits will all be '0' here.
    return true;
}

static void pad_by(int n, int filler='#')
{
    while (n-- > 0) putchar(filler);
}

// Print using "e" format

void f128M_print_E(int width, int prec, float128_t *p)
{   char s[36];
    int decexp;
    bool sign = f128M_sprint(s, p, &decexp);
    if (prec < 1) prec = 1;
    if (sign) width--;
    if (!isdigit(s[0]))
    {   pad_by(width-strlen(s));
        if (sign) putchar('-');
        fputs(s, stdout);
    }
    else
    {   char ebuf[8];
        if (round_at(s, prec)) decexp++;
// I format the exponent so I can see how many characters that uses.
        width -= sprintf(ebuf, "e%02d", decexp);
        pad_by(width - prec - 1);
        if (prec >= 34)
        {   printf("%c.%.33s", s[0], &s[1]);
            pad_by(prec-33, '0');
            fputs(ebuf, stdout);
        }
        else printf("%c.%.*s%s", s[0], prec-1, &s[1], ebuf);
    }
}

// This will be for "F" format. At present it is merely a copy of the "E"
// format code!

void f128M_print_F(int width, int prec, float128_t *p)
{   char s[36];
    int decexp;
    bool sign = f128M_sprint(s, p, &decexp);
    if (prec < 1) prec = 1;
    if (sign) width--;
    if (!isdigit(s[0]))
    {   pad_by(width-strlen(s));
        if (sign) putchar('-');
        fputs(s, stdout);
    }
    else
    {   char ebuf[8];
        if (round_at(s, prec)) decexp++;
// I format the exponent so I can see how many characters that uses.
        width -= sprintf(ebuf, "e%02d", decexp);
        pad_by(width - prec - 1);
        if (prec >= 34)
        {   printf("%c.%.33s", s[0], &s[1]);
            pad_by(prec-33, '0');
            fputs(ebuf, stdout);
        }
        else printf("%c.%.*s%s", s[0], prec-1, &s[1], ebuf);
    }
}

// Finally for "G" format.

void f128M_print_G(int width, int prec, float128_t *p)
{   char s[36];
    int decexp;
    bool sign = f128M_sprint(s, p, &decexp);
    if (prec < 1) prec = 1;
    if (sign) width--;
    if (!isdigit(s[0]))
    {   pad_by(width-strlen(s));
        if (sign) putchar('-');
        fputs(s, stdout);
    }
    else
    {   char ebuf[8];
        if (round_at(s, prec)) decexp++;
// I format the exponent so I can see how many characters that uses.
        width -= sprintf(ebuf, "e%02d", decexp);
        pad_by(width - prec - 1);
        if (prec >= 34)
        {   printf("%c.%.33s", s[0], &s[1]);
            pad_by(prec-33, '0');
            fputs(ebuf, stdout);
        }
        else printf("%c.%.*s%s", s[0], prec-1, &s[1], ebuf);
    }
}


// end of arith14.cpp
