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



#include "headers.h"


static void show(const char *s, float128_t *p)
{
    printf("Displaying %16s: ", s);
    f128M_print_E(0, 33, p);
    printf("\n");
}

static void show256(float256_t *p)
{
    float256_t q, r;
    q = *p;
    printf("%.16" PRIx64 " %.16" PRIx64 "\n", q.hi.v[1], q.hi.v[0]);
    q.lo = f128_0;
    q.hi.v[0] = 0;
    q.hi.v[1] ^= 0x8000000000000000;
    f256M_add(p, &q, &r);
    printf("%.16" PRIx64 " %.16" PRIx64 "\n", r.hi.v[1], r.hi.v[0]);
} 

float256_t f256_1;

int main(int argc, char *argv[])
{
    float128_t a, b, c, d, e, f, g, w1, w2;
#ifdef LITTLEENDIAN
    printf("Testing using a little-endian version\n");
#else
    printf("Testing using a big-endian version\n");
#endif
    printf("alignof(float128_t) = %u\n", (unsigned int)alignof(float128_t));

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
    ui64_to_f128M(10000000000000000, &g);
    printf("%.16" PRIx64 "/%.16" PRIx64 "\n",
        ((int64_t *)&g)[1], ((int64_t *)&g)[0]);
    show("10^16", &g);

    float256_t dd,ee,ff;
// Now verify the value I am using for the 256-bit version of 0.1
    i64_to_f128M(51, &a);
    i64_to_f128M(512, &b);
    f128M_div(&a, &b, &c); // 0.099609375
    f128M_sub(&f256_r10.hi, &c, &dd.hi);
    dd.lo = f256_r10.lo;
    f256_1.hi = f128_1;
    f256_1.lo = f128_0;
    f256M_mul(&f256_1, &dd, &ee);
    show("1/10.hi - 51/512", &ee.hi);
    show("1/10.lo - 51/512", &ee.lo);

    f256M_mul(&f256_r10, &f256_r10, &ee);
    show("1/100.hi - 51/512", &ee.hi);
    show("1/100.lo - 51/512", &ee.lo);

    dd = f256_r10;              // 0.1
    show("1/10.hi", &dd.hi);
    show("1/10.lo", &dd.lo);
    ee.hi = d; ee.lo = f128_0;  // 10.0
    f256M_mul(&dd, &ee, &ff);
    show("(1/10)*10.hi", &ff.hi);
    show("(1/10)*10.lo", &ff.lo);
  
    ui32_to_f128M(0x80000000u, &a);
    show("2^32", &a);
    show256(&f256_r10);
    return 0;
}

// end of softfloatdemo.cpp
