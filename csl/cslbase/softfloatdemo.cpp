/*
 * softfloatdemo.cpp
 */


// Thie file is a demonstration of the "SoftFloat-3a" package that I am
// now incorporating. I may well change it to include some sensible
// test code in the future, but for now it serves two purposes. The first
// is just to confirm that the softfloat library can be compiled and linked.
// The second is that it is a place where I can develop code that builds on
// same - such as read and print primitives.
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

/* $Id: softfloatdemo.cpp 3297 2015-12-14 20:30:04Z arthurcnorman $ */


// I am now using the SoftFloat-3a library by John R Hauser. This is
// a small demonstration and test of how it is used.

// [NOTE to self: I need to check this on a machine which is not LITTLEENDIAN
//  since the order of bytes of words in the data structues will differ there.]


#include <stdio.h>

#define __STDC_FORMAT_MACROS 1
#include <stdint.h>
#include <inttypes.h>

extern "C"
{
#include "softfloat.h"
}

static int f128M_exponent(const float128_t *p)
{
#ifdef LITTLEENDIAN
    return ((p->v[0] >> 48) & 0x7fff) - 0x3fff;
#else
    return ((p->v[1] >> 48) & 0x7fff) - 0x3fff;
#endif
}

static void f128M_set_exponent(float128_t *p, int n)
{
#ifdef LITTLEENDIAN
    p->v[0] = (p->v[0] & 0x8000ffffffffffff) | (((uint64_t)n + 0x3fff) << 48);
#else
    p->v[1] = (p->v[1] & 0x8000ffffffffffff) | (((uint64_t)n + 0x3fff) << 48);
#endif
}

static bool f128M_infinite(const float128_t *p)
{
#ifdef LITTLEENDIAN
    return (((p->v[0] >> 48) & 0x7fff) == 0x7fff) &&
            ((p->v[0] & 0xffffffffffff) == 0) &&
            (p->v[1] == 0);
#else
    return (((p->v[1] >> 48) & 0x7fff) == 0x7fff) &&
            ((p->v[1] & 0xffffffffffff) == 0) &&
            (p->v[0] == 0);
#endif
}

static bool f128M_negative(const float128_t *x)
{
#ifdef LITTLEENDIAN
    return ((int64_t)x->v[0]) < 0;
#else
    return ((int64_t)x->v[1]) < 0;
#endif
}

static void f128M_negate(float128_t *x)
{
#ifdef LITTLEENDIAN
    x->v[0] ^= 0x8000000000000000;
#else
    x->v[1] ^= 0x8000000000000000;
#endif
}

// I will want working precision even higher than 128-bits. I will
// arrange that using pairs of 128-bit floats such that the value
// I am representing is their sum. The code I have here will not be
// robust against issues of denormailised numbers, infinities or
// NaNs, and so its use needs to take care to avoid such cases.
//
// I am following the scheme from T J Dekker, Numer Math 18 224-242 (1971).


// Because I have no special reason to care about the layout in memory of
// my 256-bit floating point representation I will use the same structure
// definition for ir regardless of the endianness of the machine I am on.

typedef struct _float256_t
{
    float128_t hi;
    float128_t lo;
} float256_t;

// It is convenient to have a number of consiants available. The
// values I have here are 0, 1, 10, 0.1 and 2^4096 all as 128-bit
// numbers, and 10 and 0.1 as 256-bit ones.

#ifdef LITTLEENDIAN

float128_t f128_0      = {0x0000000000000000, 0},
           f128_1      = {0x3fff000000000000, 0},
           f128_10     = {0x4002400000000000, 0},
           f128_10_17  = {0x40376345785d8a00, 0},
           f128_10_18  = {0x403abc16d674ec80, 0},
           f128_r10    = {0x3ffb999999999999, 0x999999999999999a},
           f128_N1     = {0x4fff000000000000, 0}; // 2^4096

float256_t f256_1      = {{0x3fff000000000000, 0}, {0,0}},
           f256_10     = {{0x4002400000000000, 0}, {0,0}},
           f256_r10    = {{0x3ffb999999999999, 0x9999999999999999},
                          {0x3f8a333333333333, 0x3333333333333333}};
#else

float128_t f128_0      = {0, 0x0000000000000000},
           f128_1      = {0, 0x3fff000000000000},
           f128_10     = {0, 0x4002400000000000},
           f128_10_17  = {0, 0x40376345785d8a00},
           f128_10_18  = {0, 0x403abc16d674ec80},
           f128_r10    = {0x999999999999999a, 0x3ffb999999999999},
           f128_N1     = {0, 0x4fff000000000000};

float256_t f256_10     = {{0, 0x4002400000000000}, {0,0}},
           f256_r10    = {{0x9999999999999999, 0x3ffb999999999999},
                          {0x3333333333333333, 0x3f8a333333333333}};
#endif

// f256M_add adds two long numbers. As noted avove you should keep the
// arguments well away from cases where the result might underflow or
// overflow. The result should end up with almost 224 bits of precision,
// but it does not pretend to get rounding utterly correct.

static void f256M_add(const float256_t *x, const float256_t *y, float256_t *z)
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

static void f128M_split(const float128_t *x, float128_t *yhi, float128_t *ylo)
{
    *yhi = *x;
// I clear 57 bits at the low end of yhi. This leaves 56 bits (maximum) in
// the mantissa, and if you multiply two values each of which have just 56
// bits the result as a float128 should be exact.
#ifdef LITTLEENDIAN
    yhi->v[1] &= ~0x1ffffffffffffff;
#else
    yhi->v[0] &= ~0x1ffffffffffffff;
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

static void f256M_mul(const float256_t *x, const float256_t *y, float256_t *z)
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

static void print(float128_t *p)
{
    printf("raw data: %.16" PRIx64 " %.16" PRIx64 "\n", p->v[0], p->v[1]);
// I deal with a number of special cases first. +0.0 and -0.0 ...
    if (f128M_eq(p, &f128_0))
    {   if (f128M_negative(p)) printf("-");
        printf("0.0\n");
        return;
    }
// +inf and -inf
    if (f128M_infinite(p))
    {   if (f128M_negative(p)) printf("-");
        printf("inf\n");
        return;
    }
// NaNs. I do not distinguish between signalling and non-signalling ones.
    int exponent = f128M_exponent(p);
    if (exponent == 0x4000) // A NaN, because I have already handled infinity
    {   printf("NaN\n");
        return;
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
    if (f128M_negative(&w1.hi))
    {   printf("-");
        f128M_negate(&w1.hi);
    }
// Now the decimal exponent will be around exponent*log_{10}(2)
   int decexp = (int)(0.3010300*(double)exponent);
// Now I want to multiply the value I have by 10^(-decexp)
//  printf("decexp = %d\n", decexp);
    if (decexp > 0)
    {   float256_t w3;
        f256M_pow(&f256_r10, decexp, &w3);
        f256M_mul(&w1, &w3, &w2);
    }
    else if (decexp < 0)
    {   float256_t w3;
        f256M_pow(&f256_10, -decexp, &w3);
        f256M_mul(&w1, &w3, &w2);
    }
    else w2 = w1;
// Now I rather expect that w2 is not that far from 1.0. Further the
// above scaling will have performed at most around 30 multiplications
// so can not have wrecked accuracy TOO much. I will do the final adjustment
// simply. If I scale the the range [1.0, 10.0) then I think that the
// tests are reasonably easy to perform provided I believe that the
// high part of a float256_t is rounded properly.
//  printf("near 1.0: %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//          w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
// While hi<1.0 or (hi==1.0 && lo<0.0) ...
    while (f128M_lt(&w2.hi, &f128_1) ||
           (f128M_eq(&w2.hi, &f128_1) &&
            f128M_lt(&w2.lo, &f128_0)))
    {   float256_t w3;
        f256M_mul(&w2, &f256_10, &w3);
        w2 = w3;
//      printf("times 10: %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//              w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
        decexp--;
    }
// while hi>=10.0 or (hi==10.0 && lo>0.0) ...
    while (!f128M_lt(&w2.hi, &f128_10) ||
           (f128M_eq(&w2.hi, &f128_10) &&
            !f128M_lt(&w2.lo, &f128_0)))
    {   float256_t w3;
        f256M_mul(&w2, &f256_r10, &w3);
        w2 = w3;
//      printf("div 10: %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//              w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
        decexp++;
    }
// Now w2 should be neatly in the range 1 to 9.99999999999... I will
// consolidate all of it into the 128-bit top half.
//  printf("[1,10): %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 " %.16" PRIx64 "\n",
//          w2.hi.v[0], w2.hi.v[1], w2.lo.v[0], w2.lo.v[1]);
    float128_t v;
    f128M_add(&w2.hi, &w2.lo, &v);
//  printf("[1,10) as single: %.16" PRIx64 " %.16" PRIx64 "\n", v.v[0], v.v[1]);
// Now I extract decimal digits. I could collect many at a time , but
// for simplicity and because to start with I just want something that
// works (and I am not really worried about performance) I will extract
// just one at a time. The recipe used is to iterate
//       d = fix v;
//       v = 10 * (v - d);
// I would do way better here if I had initially normalised the
// number to be in the range [10^17, 10^18). I could then fix it to
// a 63-bit integer, and the conversion would then involve just 2 steps,
// with no rounding required. I may change to that scheme soon! But this
// one was easier to start with.
    for (int k=0; k<34; k++)
    {  uint_fast32_t d = f128M_to_ui32_r_minMag(&v, false);
       putchar('0' + d);
       if (k == 0) putchar('.');
       float128_t w3, w4;
       i32_to_f128M(-d, &w3);
       f128M_add(&v, &w3, &w4);
//     printf("sub digit: %.16" PRIx64 " %.16" PRIx64 "\n", w4.v[0], w4.v[1]);
       f128M_mul(&w4, &f128_10, &v);
//     printf("next: %.16" PRIx64 " %.16" PRIx64 "\n", v.v[0], v.v[1]);
    }
    if (decexp != 0) printf("Q%d", decexp);
    printf("\n");  

}

static void show(const char *s, float128_t *p)
{
    printf("Displaying %s\n", s);
    print(p);
}

int main(int argc, char *argv[])
{
    float128_t a, b, c, d, e, f,g,h,w1, w2;

    ui32_to_f128M(0, &f128_0);

    ui32_to_f128M(1, &a);
    ui32_to_f128M(7, &b);
    f128M_div(&a, &b, &c);
    ui64_to_f128M(10, &d);
    ui64_to_f128M(100000000000000000, &f);
    ui64_to_f128M(1000000000000000000, &g);
    f128M_div(&a, &d, &e);
    show("1", &a);
    show("7", &b);
    show("10", &d);
    show("1/7", &c);
    show("1/10", &e);
    f128M_split(&c, &w1, &w2);
    show("hi", &w1);
    show("lo", &w2);
    show("10^17", &f);
    show("10^18", &g);

    float256_t dd,ee,ff;
// Now verify the value I am using for the 256-bit version of 0.1
    i64_to_f128M(51, &a);
    i64_to_f128M(512, &b);
    f128M_div(&a, &b, &c); // 0.099609375
    f128M_sub(&f256_r10.hi, &c, &dd.hi);
    dd.lo = f256_r10.lo;
    f256M_mul(&f256_1, &dd, &ee);
    show("1/10.hi - 51/512", &ee.hi);
    show("1/10.lo - 51/512", &ee.lo);

    dd = f256_r10;              // 0.1
    show("1/10.hi", &dd.hi);
    show("1/10.lo", &dd.lo);
    ee.hi = d; ee.lo = f128_0;  // 10.0
    f256M_mul(&dd, &ee, &ff);
    show("(1/10)*10.hi", &ff.hi);
    show("(1/10)*10.lo", &ff.lo);
  
    return 0;
}

// end of softfloatdemo.cpp
