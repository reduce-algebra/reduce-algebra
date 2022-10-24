//  arith14.cpp                                 Copyright (C) 2022 Codemist

//
// Support for 128-bit floats using the SoftFloat-3a package - this
// provides some additional low level primitives that I want (eg tests for
// infinities and NaNs), and then implements conversion to and from
// character strings. To get the conversions accurate there is skeletal
// support for 256-bit "float128-float128" arithmetic.
//

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

#ifdef HAVE_SOFTFLOAT
// It is convenient to have a number of constants available. The
// values I have here are 0, 1/2, -1/2, 1, 10, 0.1, 10^17, 10^18 and 2^4096
// all as 128-bit numbers, and 1, 10 and 0.1 as 256-bit ones.

#ifdef LITTLEENDIAN
#define fpOrder(a, b) {INT64_C(a), INT64_C(b)}
#define fp256Order(a, b) {a, b}
#else // LITTLEENDIAN
#define fpOrder(a, b) {INT64_C(a), INT64_C(b)}
#define fp256Order(a, b) {b, a}
#endif // LITTLEENDIAN

float128_t
  f128_0            = {fpOrder(0, 0x0000000000000000)},
  f128_half         = {fpOrder(0, 0x3ffe000000000000)},
  f128_mhalf        = {fpOrder(0, 0xbffe000000000000)},
  f128_1            = {fpOrder(0, 0x3fff000000000000)},
  f128_10_16        = {fpOrder(0, 0x40341c37937e0800)},
  f128_10_17        = {fpOrder(0, 0x40376345785d8a00)},
  f128_10_18        = {fpOrder(0, 0x403abc16d674ec80)},
  f128_scale        = {fpOrder(0x0080000000000000, 0x4038000000000000)},
  f128_N1           = {fpOrder(0, 0x4fff000000000000)}, // 2^4096

// These values are not set up yet!!!!
  f128_epsilon      = {fpOrder(0, 0)},
  f128_half_epsilon = {fpOrder(0, 0)},
  f128_max          = {fpOrder(0, 0)},
  f128_negmax       = {fpOrder(0, 0)},
  f128_min          = {fpOrder(0, 0)},
  f128_negmin       = {fpOrder(0, 0)},
  f128_normmin      = {fpOrder(0, 0)},
  f128_negnormmin   = {fpOrder(0, 0)};


float256_t
  f256_5      = fp256Order(fpOrder(0,0), fpOrder(0, 0x4001400000000000)),
  f256_10     = fp256Order(fpOrder(0,0), fpOrder(0, 0x4002400000000000)),
  f256_r5     = fp256Order(fpOrder(0x999999999999999a, 0xbf8a999999999999),
                            fpOrder(0x999999999999999a, 0x3ffc999999999999)),
  f256_r10    = fp256Order(fpOrder(0x999999999999999a, 0xbf89999999999999),
                            fpOrder(0x999999999999999a, 0x3ffb999999999999)),
  f256_10_16  = fp256Order(fpOrder(0,0), fpOrder(0, 0x40341c37937e0800));

void f128M_ldexp(float128_t *p, int x)
{   if (f128M_zero(p) ||
        f128M_infinite(p) ||
        f128M_nan(p)) return;  // special cases!
    x = ((p->v[HIPART] >> 48) & 0x7fff) + x;
// In case of overflow leave an infinity of the right sign.
    if (x >= 0x7fff)
    {   p->v[HIPART] |= INT64_C(0x7fff000000000000);
        p->v[HIPART] &= INT64_C(0xffff000000000000);
        p->v[LOPART] = 0;
    }
    if (x < -114) // Without doubt underflowing to zero
    {   p->v[HIPART] &= INT64_C(
                            0x8000000000000000); // preserve sign of input
        p->v[LOPART] = 0;
        return;
    }
// In the case that ldexp underflows I have to be especially careful
// because of the joys of sub-normalised numbers and gradual underflow.
// I deal with this by first forcing the exponent to be one that will
// not lead to a sub-norm and then using a multiply to scale it down.
    if (x <= 0)
    {   p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                       ((uint64_t)(x+4096) << 48);
        float128_t w1;
        f128M_div(p, &f128_N1, &w1);
        *p = w1;
    }
    else p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                            ((uint64_t)x << 48);
}

void f128M_frexp(float128_t *p, float128_t *r, int *x)
{   if (f128M_zero(p) ||
        f128M_infinite(p) ||
        f128M_nan(p))
    {   *r = *p;
        *x = 0;
        return;
    }
    int px = ((p->v[HIPART] >> 48) & 0x7fff);
// If I had a sub-normalized number I will multiply if by 2^4096 before
// forcing its exponent. Doing that will have turned any non-zero sub-norm
// into a legitimate normalized number.
    if (px == 0)
    {   f128M_mul(p, &f128_N1, r);
        px = ((r->v[HIPART] >> 48) & 0x7fff) - 4096;
    }
    else *r = *p;
    r->v[HIPART] = (r->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                   ((uint64_t)0x3ffe << 48);
    *x = px - 0x3ffe;
}

// I will want working precision even higher than 128-bits. I will
// arrange that using pairs of 128-bit floats such that the value
// I am representing is their sum. The code I have here will not be
// robust against issues of denormailised numbers, infinities or
// NaNs, and so its use needs to take care to avoid such cases.
//
// I am following the scheme from T J Dekker, Numer Math 18 224-242 (1971).


// f256M_add adds two long numbers. As noted above you should keep the
// arguments well away from cases where the result might underflow or
// overflow. The result should end up with almost 224 bits of precision,
// but it does not pretend to get rounding utterly correct.

void f256M_add(const float256_t *x, const float256_t *y, float256_t *z)
{   float128_t r, s, w1, w2, w3;
// r = x->hi + y->hi
    f128M_add(&x->hi, &y->hi, &r);
// compute abs(x->hi) and abs(y->hi)
    w1 = x->hi;
    if (f128M_negative(&w1)) f128M_negate(&w1);
    w2 = y->hi;
    if (f128M_negative(&w2)) f128M_negate(&w2);
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

UNUSED_NAME static void f128X_print(const float128_t *v)
{   std::printf("%.16" PRIx64 " %.16" PRIx64, v->v[HIPART],
                v->v[LOPART]);
}

// This helper function splits a 113-bit float X into two parts H & L each
// of which only uses 56 bits such that H+L = X. You may worry that 56+56
// is only 112 not 113 - the extra bit is recovered because L can be
// negative! The object of this step is so that numbers such as H and L can
// then be multiplied without introducing any rounding at all.

void f128M_split(const float128_t *x, float128_t *yhi,
                 float128_t *ylo)
{   float128_t p, q;
    f128M_mul(x, &f128_scale, &p);  // 2^58+1
    f128M_sub(x, &p, &q);
    f128M_add(&q, &p, yhi);
    f128M_sub(x, yhi, ylo);
}

// f128M_mul2 multiplies two 128-bit floats and yields a result that
// is almost correct to the full precision of a 256-bit float.

static void f128M_mul2(const float128_t *x, const float128_t *y,
                       float256_t *z)
{   float128_t xhi, xlo, yhi, ylo, p, q, w1, w2;
    f128M_split(x, &xhi, &xlo);
    f128M_split(y, &yhi, &ylo);
// p will be a fully accurate product of the top halves of x and y
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

void f256M_mul(const float256_t *x, const float256_t *y,
               float256_t *z)
{   float256_t c;
    float128_t w1, w2, w3;
// mul2 generates a double-precision product of the high parts.
    f128M_mul2(&x->hi, &y->hi, &c);
// c.lo = x->lo*y->lo + x->hi*y->lo + x->lo*y->hi + c.lo
    f128M_mul(&x->lo, &y->lo, &w3);
    f128M_mul(&x->hi, &y->lo, &w2);
    f128M_add(&w2, &w3, &w1);
    f128M_mul(&x->lo, &y->hi, &w2);
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

void f256M_pow(const float256_t *x, unsigned int n, float256_t *y)
{   if (n == 0)
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


// This converts a number from floating point to character representation.
// The reult is true if the original number was negative, and *pdecexp gets
// the decimal exponent. The buffer s is filled with 34 digits (or one of the
// strings "inf" or "nan" plus a terminating nul. In a printed representation
// these digits need displaying as [-]d.dddddddddExxx

bool f128M_sprint(char *s, float128_t *p, int *pdecexp)
{
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
    }
// NaNs. I do not distinguish between signalling and non-signalling ones.
    int exponent = f128M_exponent(p);
    if (exponent ==
        0x4000) // A NaN, because I have already handled infinity
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
    double d_decexp = 0.301029995663981195*static_cast<double>(exponent);
// Now I want to multiply the value I have by 10^(-decexp)
//  printf("d_decexp = %.3f\n", d_decexp);
    int decexp = 0;
    if (d_decexp >= 18.0)
    {   float256_t w3;
// multiply by a power of 0.1. Note that the largest possible finite number
// is around 1.19e4932 and to scale that down to 10^17 or so involves
// multiplying by a number where which is about 10^17 times as big as
// the smallest normaised number. But in the double-double representation
// in use here that would mean that its low half could be sub-normal, and so
// I do the division as (n/5^K)/2^K where the scaling by a power of 2
// is certainly safe.
        f256M_pow(&f256_r5, decexp = static_cast<int>(d_decexp-17.0), &w3);
        f128M_ldexp(&w3.hi, -decexp);
        f128M_ldexp(&w3.lo, -decexp);
        f256M_mul(&w1, &w3, &w2);
    }
    else if (d_decexp < 17.0)
    {   float256_t w3;
// multiply by a power of 10.0. Well this could cause overflow issues
// if the number I am trying to print is really tiny. To avoid that instead
// of multiplying by 10^K I will multiply by 5^K (not risking anything at
// all bad) and then increment the exponent by K.
        f256M_pow(&f256_5, decexp = static_cast<int>(18.0-d_decexp), &w3);
        f128M_ldexp(&w3.hi, decexp);
        f128M_ldexp(&w3.lo, decexp);
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
//
// while hi<1.0e17 or (hi==1.0e17 && lo<0.0) ...
    while (f128M_lt(&w2.hi, &f128_10_17) ||
           (f128M_eq(&w2.hi, &f128_10_17) &&
            f128M_lt(&w2.lo, &f128_0)))
    {   float256_t w3;
        f256M_mul(&w2, &f256_10, &w3);
        w2 = w3;
        decexp--;
    }
// while hi>=10.0e18 or (hi==10.0e18 && lo>0.0) ...
    while (!f128M_lt(&w2.hi, &f128_10_18) ||
           (f128M_eq(&w2.hi, &f128_10_18) &&
            !f128M_lt(&w2.lo, &f128_0)))
    {   float256_t w3;
        f256M_mul(&w2, &f256_r10, &w3);
        w2 = w3;
        decexp++;
    }
// Now w2 should be neatly in the range 1.0e17 to 9.99999999999...e17. I will
// consolidate all of it into the 128-bit top half.
    float128_t v;
    f128M_add(&w2.hi, &w2.lo, &v);
    uint64_t d = f128M_to_ui64(&v, softfloat_round_min, false);
    s += std::sprintf(s, "%.17" PRIu64, d);
    float128_t w3, w4;
    i64_to_f128M(-d, &w3);
    f128M_add(&v, &w3, &w4);
    f128M_mul(&w4, &f128_10_17, &v);
    d = f128M_to_ui64(&v, softfloat_round_near_even, false);
    s += std::sprintf(s, "%.17" PRIu64, d);
    *pdecexp = decexp + 17;
    return result;
}

void f128M_print(float128_t *p)
{   char s[36];
    int decexp;
    bool neg = f128M_sprint(s, p, &decexp);
    if (!std::isdigit(s[0])) std::printf("%s%s\n", neg ? "-" : "", s);
    else std::printf("%s%c.%sL%d\n", neg ? "-" : "", s[0], &s[1], decexp);
}

// This rounds the number in the buffer to have ndigits in all.
// When I round it is possible to generate an overflow. Consider the case of
// 9.9996 rounded to 4 figures. It should end up as
// 10.000, except that what I want to do is shift that along so it comes
// out as "1.000" with the exponent incremented. Rounding to 1 digits will
// leave just the integer part, while rounding to 33 (or more) places
// should not change anything because there are no digits beyond there.
// Rounding to 0 digits should yield either "0" or "1".

static bool round_at(char *s, int ndigits)
{   if (ndigits < 0 || ndigits >= 34) return false;
// If the digits just beyond where I am is < '5' I will truncate down.
    if (s[ndigits] < '5') return false;
// If the digits beyond where I am are "50000...0" and I the digit I would
// change on rounding up is even then I will round down.
    if (s[ndigits] == '5' && (ndigits == 0 || s[ndigits-1]%2 == 0))
    {   int p = ndigits+1;
        while (p < 34 && s[p] == '0') p++;
        if (p >= 34) return false;
    }
// Here I need to round up.
    int p = ndigits-1;
    while (p >= 0)
    {   if (s[p] != '9')
        {   s[p]++;
            return false;
        }
        s[p--] = '0';  // need to carry.
    }
// If I have dropped out of the loop it means that I have rounded an
// initial '9' up.
    s[0] = '1';        // the remaining relevant digits will all be '0' here.
    return true;
}

// This is used to put in blanks to fill to the specified width.

static char *pad_by(char *r, int n)
{   while (n-- > 0) *r++ = ' ';
    *r = 0;
    return r;
}

// This is used to insert a string of '0' chararacters. If it woule be
// a very long string I abbreviate it using the notation "0000{NNN}0000"
// where the {NNN} stands for a sequence on NNN zeros. This can not be
// triggered within parts of the number that are significant. It happens
// with huge numbers in F format that may end up with integer parts such as
//                 XXXXX...XXXXX00000...00000.0
// with 34 digits (the most needed for full indication of a 128-bit float) in
// the string XX..XX but then very many zeros before the decimal point.
// It might also arise with F format if the user specified a HUGE precision
// and either leading or trailing zeros surround the digits that are
// actually significant, as in
//     0.00000...00000XXXXX...XXXXX00000...00000
// Observe that the smallest value that will appear as NNN will be 3, when
// "00000{4}00000" stands for 14 zeros in a row, so it just saves space:
// "00000000000000"
//

static char *pad_by_zero(char *r, int n)
{   if (n >= 14) r += std::sprintf(r, "00000{%d}00000", n-10);
    else while (n-- > 0) *r++ = '0';
    *r = 0;
    return r;
}

// Print using "e" format

int f128M_sprint_E(char *r, int width, int prec, float128_t *p)
{   char s[36], *original_r = r;
    int decexp;
    bool sign = f128M_sprint(s, p, &decexp);
// I limit the requested precision to 9999 so that the {NNNN} abbreviations
// only ever need 4 digits. A precision less than 1 can not make sense.
    if (prec < 1) prec = 1;
    else if (prec > 9999) prec = 9999;
    if (sign) width--;
    if (!std::isdigit(s[0]))
    {   r = pad_by(r, width-std::strlen(s));
        if (sign) *r++ = '-';
        std::strcpy(r, s);
        return (r - original_r) + std::strlen(r);
    }
    else
    {   char ebuf[8];
        if (round_at(s, prec+1)) decexp++;
// I format the exponent so I can see how many characters that uses.
        width -= std::sprintf(ebuf, "e%02d", decexp);
        r = pad_by(r, width - prec - 1);
        if (sign) *r++ = '-';
        if (prec >= 34)
        {   r += std::sprintf(r, "%c.%.33s", s[0], &s[1]);
            r = pad_by_zero(r, prec-33);
            std::strcpy(r, ebuf);
            r += std::strlen(r);
        }
        else r += std::sprintf(r, "%c.%.*s%s", s[0], prec-1, &s[1], ebuf);
    }
// The longest possible output here will be along the lines of
//  -1.123456789012345678901234567890123000{NNNN}000e-NNNN
// ie 54 chars plus the terminating '\0'. Well if width is greater
// then 54 this can be left-padded with blanks up to width.
    return r - original_r;
}

int f128M_print_E(int width, int prec, float128_t *p)
{   char buffer[64];
    int r = 0;
    while (width > 63)
    {   std::putchar(' ');
        r++;
        width--;
    }
// Oh dear - if prec is huge this may display something like
//      1.000...000E12
// with a HUGE number of zeros, swamping the buffer. Well that pain is
// avoided by having f128M_sprint arrange to insert {NNNN} in place of
// long strings of zeros...
    r += f128M_sprint_E(buffer, width, prec, p);
    std::fputs(buffer, stdout);
    return r;
}


// This will be for "F" format.

int f128M_sprint_F(char *r, int width, int prec, float128_t *p)
{   char s[36], *original_r = r;
    int decexp;
    bool sign = f128M_sprint(s, p, &decexp);
    if (prec < 0) prec = 0;
    else if (prec > 9999) prec = 9999;
    if (sign) width--;
// Infinities and NaNs are displayed with scant regard to the requested
// precision, but they do honour the width request.
    if (!std::isdigit(s[0]))
    {   r = pad_by(r, width-std::strlen(s));
        if (sign) *r++ = '-';
        std::strcpy(r, s);
        return (r - original_r) + std::strlen(r);
    }
// The "F" print format is basically abominable in that it can lead to
// absurdly long output. There are three bad cases
// (1)    %9999.2F           generates a silly number of leading blanks
// (2)    %.2F in 1.23e1234  has to display >1K chars before the "."
// (3)    %.9999F            has to generate many chars after the "."
// I will take the view that for sprint the first of these is something that
// the user has done and they know how big a buffer to provide - so I view
// it as not terribly much of a problem. For the other two I will introduce
// an abbreviation so that long strings of "0" characters can be mapped to
// appear as "000{1234}000" with the section with brackes denoting that
// man digits. I will then limit widths to be no greater than 9999 so I
// only need 4 digits. I will use this whenever there would otherwise have
// been a string of more than 12 '0' chars inserted.
// I think that makes the longest possible output something like
// -1234567890123456789012345678901234000{NNNN}000.000{NNNN}000
// or maybe
// -0.000{NNNN}0001234567890123456789012345678901234000{NNNN}000
// which I make 61 characters (plus the terminating '\0').
//
// I have a whole slew of different cases to consider here! These need
// to be separated in term of how the digits making up the significant
// part of the result fall relative to (a) the decimal point and (b) the
// right hand end of the desired result, and where strings of zeros need to
// be inserted. Eg some of the cases are in the patterns:
//     xxxxxxxx00000000.00000000
//                 xxxx.xx(xx)
//                 xxxx.xxxx00000000
//                    0.00000000xxxx(xxxx)
//                    0.00000000xxxxxxxx00000000
// where xxxxxxxx denote significant digits, (xxxx) digits that are to
// be truncated and 00000000 could be almost arbitrarily long sequences of
// zero characters dependent on the magnitude of the number being displayed
// and the number of sigits after the decimal point that F notation has
// asked for.
    if (round_at(s, decexp+prec+1)) decexp++;
    if (decexp >= 34)
    {   if (sign) *r++ = '-';
        r += std::sprintf(r, "%.34s", s);
        r = pad_by_zero(r, decexp-33);
        *r++ = '.';
        r = pad_by_zero(r, prec);
    }
    else if (decexp >= 0)
    {   int fdig = 33-decexp;
        if (fdig > prec) fdig = prec;
        if (sign) *r++ = '-';
        r += std::sprintf(r, "%.*s.%.*s",
                          decexp+1, s, fdig, &s[decexp+1]);
        r = pad_by_zero(r, prec-fdig);
    }
    else if (prec+decexp+1 <= 34)
    {   if (sign) *r++ = '-';
        r += std::sprintf(r, "0.");
        int pp = -decexp-1;
        if (pp > prec) pp = prec;
        r = pad_by_zero(r, pp);
        if (prec+decexp+1 > 0)
            r += std::sprintf(r, "%.*s", prec+decexp+1, s);
    }
    else
    {   if (sign) *r++ = '-';
        r += std::sprintf(r, "0.");
        r = pad_by_zero(r, -decexp-1);
        r += std::sprintf(r, "%.34s", s);
        r = pad_by_zero(r, prec+decexp-33);
    }
    return r - original_r;
}

int f128M_print_F(int width, int prec, float128_t *p)
{   char buffer[64];
    int r = 0;
    while (width > 63)
    {   std::putchar(' ');
        r++;
        width--;
    }
    r += f128M_sprint_F(buffer, width, prec, p);
    std::fputs(buffer, stdout);
    return r;
}


// Finally for "G" format.

int f128M_sprint_G(char *r, int width, int prec, float128_t *p)
{   char s[36];
    int decexp;
// This implementation does the conversion twice, which is clumsy.  It also
// makes its choice as between use of E and F format before rounding. This
// letter could hurt when printing 9.99999e3 in precision 3. Here the
// exponent and precision are both 3 so F format will be used, asking for
// no digits beyond the decimal point. This asks the F printer to print
// as 999.[999] and I expect it will round this to 1000. which ought to
// have been rendered as 1.e03.
    static_cast<void>(f128M_sprint(s, p, &decexp));
    if (prec < 1) prec = 1;
    else if (prec > 9999) prec = 9999;
    if (decexp < -4 || decexp > prec)
        return f128M_sprint_E(r, width, prec, p);
    else return f128M_sprint_F(r, width, prec-decexp, p);
}

int f128M_print_G(int width, int prec, float128_t *p)
{   char buffer[64];
    int r = 0;
    while (width > 63)
    {   std::putchar(' ');
        r++;
        width--;
    }
    r += f128M_sprint_G(buffer, width, prec, p);
    std::fputs(buffer, stdout);
    return r;
}

// I also want to be able to read float128_t values...

#ifdef UNUSED_IDFPLUS

static LispObject idfplus(LispObject a, LispObject b)
{   LispObject ai = car(a), ax = car(cdr(a)), asgn = car(cdr(cdr(a)));
    LispObject bi = car(b), bx = car(cdr(b)), bsgn = car(cdr(cdr(b)));
    if (ax < bx)
    {   bi = times2(bi, make_power_of_two(int_of_fixnum(
                                              bx) - int_of_fixnum(ax)));
        bx = ax;
    }
    if (bx < ax)
    {   ai = times2(ai, make_power_of_two(int_of_fixnum(
                                              ax) - int_of_fixnum(bx)));
        ax = bx;
    }
    if (asgn == fixnum_of_int(-1)) ai = negate(ai); // GC safe?
    if (bsgn == fixnum_of_int(-1)) bi = negate(bi);
    ai = plus2(ai, bi);
    if (minusp(ai))
    {   ai = negate(ai);
        asgn = fixnum_of_int(-1);
    }
    else asgn = fixnum_of_int(1);
    return list3(ai, ax, asgn);
}

#endif

float128_t atof128(const char *s)
{   int x = 0;
    bool sign = false, seen = false, dotseen = false;
    uint64_t z[3];
    int nz = 0, n = 0;
    z[0] = z[1] = z[2] = 0;
    if (*s == '+') s++;
    else if (*s == '-')
    {   sign = true;
        s++;
    }
// To start with I will collect 3 chunks each of 16 decimal digits.
    while (*s != 0)
    {   int c = *s++;
        if (c == '.')
        {   dotseen = true;
            continue;
        }
        if (!seen && c == '0')
        {   if (dotseen) x--;
            continue;
        }
        seen = true;
        if (!std::isdigit(c)) break; // probably exponent marker.
        if (nz < 3) z[nz] = 10*z[nz] + (c - '0');
        if (!dotseen) x++;
        if (++n == 16)
        {   nz++;
            n = 0;
        }
    }
    switch (nz)
    {   case 0: if (!dotseen) x += 16;
        case 1: if (!dotseen) x += 16;
        case 2:
            while (++n != 17)
            {   z[nz] *= 10;
                if (!dotseen) x++;
            }
        default:
            break;
    }
// Now my number is {z[0], z[1], z[2]} with in base 10^16, with x digits
// of that after the decimal point.
    s--; // move back to re-investigate the char that ended the mantissa
    switch (*s)
    {
// I allow all even slightly plausible exponent signifiers.
        case 's': case 'S':
        case 'f': case 'F':
        case 'e': case 'E':
        case 'd': case 'D':
        case 'l': case 'L':
            s++;
// atoi() would allow whitespace after the exponent signifier and before
// the exponent itself.
            x += std::atoi(s);
        default:
            break;
    }
// Where I am now is that I have z[0]:z[1] . z[2] where each digit is
// 16 decimals. The bit before the "." will be exactly representable as
// an integer in the 128-bit format.
    float128_t u, v, w;
    float256_t uu, vv, ww;
    ui64_to_f128M(z[0], &u);          // u = (float128_t)z[0];
    f128M_mul(&u, &f128_10_16, &v);   // v = u * 10^16;
    ui64_to_f128M(z[1], &u);          // u = (float128_t)z[1];
    f128M_add(&u, &v, &w);            // w = u + v;
    f128M_to_f256M(&w, &ww);          // expand to 256 bit
    ui64_to_f128M(z[2], &u);          // u = (float128_t)z[2];
    f128M_to_f256M(&u, &uu);
    f256M_mul(&ww, &f256_10_16, &vv); // v = w * 10^16;
    f256M_add(&uu, &vv,
              &ww);         // collect final integer in 256-bit form
    float256_t k, l;
// I now need to multiply by 10^(x-48). The 48 is because of the way I have
// collected a 48-bit integer. I will scale my multiplying by a power of
// 5 or (1/5) [which will not overflow or underflow in any reasonable case]
// then using ldexp to scale by the right power of 2 in a way that knows how
// to cope with inifinities and subnormal numbers.
// I branch the code because f256M_pow can only cope with positive exponents.
    if (x >= 48) f256M_pow(&f256_5, x-48, &k);
    else f256M_pow(&f256_r5, 48-x, &k);
    f256M_mul(&ww, &k, &l);
    f128M_ldexp(&l.hi, x-48);
    f128M_ldexp(&l.lo, x-48);
// Probably just l.hi is the correct result here, but just to be safe I will
// ad din l.lo...
    float128_t r;
    f128M_add(&l.hi, &l.lo, &r);
    if (sign) f128M_negate(&r);
    return r;
}
#endif // HAVE_SOFTFLOAT

// end of arith14.cpp
