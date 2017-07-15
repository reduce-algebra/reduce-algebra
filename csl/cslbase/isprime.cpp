// isprime.cpp                                Copyright (C) A C Norman 2017

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

// I am not going to make this include general CSL header files because it
// is remarkably free-standing and might be useful elsewhere!
//
// It provides a function "bool isprime(uint64_t n)" that tests if n
// is a prime number.


#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Given a, b and c as 64-bit unnsigned values with c!=0, compute (a*b)%c.
// The issue here is that the intermediate product a*b can use up to
// 128-bits.
// The division/remainder method used here is the one from Warren's book
// "Hacker's Delight" which in turn derives it by specialising and further
// optimising the scheme from Knuth's Art of Computer Programming volume 2.

// On platforms where the C++ compiler supports an integer type of width
// 128 bits I just use than rather than the visible messing around with
// double precision work atop the 64-bit data-type.

#ifdef __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too.
//
// In my use here nlz should never be given a zero argument - that would
// correspond to trying to perform modular arithmetic with a zero modulus. 

static inline int nlz(uint64_t x)
{   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
}

#else // __GNUC__

static inline int nlz(uint64_t x)
{   int n = 0;
    if (x <= 0x00000000FFFFFFFFU) {n = n +32; x = x <<32;}
    if (x <= 0x0000FFFFFFFFFFFFU) {n = n +16; x = x <<16;}
    if (x <= 0x00FFFFFFFFFFFFFFU) {n = n + 8; x = x << 8;}
    if (x <= 0x0FFFFFFFFFFFFFFFU) {n = n + 4; x = x << 4;}
    if (x <= 0x3FFFFFFFFFFFFFFFU) {n = n + 2; x = x << 2;}
    if (x <= 0x7FFFFFFFFFFFFFFFU) {n = n + 1;}
    return n;
}

#endif // __GNUC__

// Form (a*b) % c where all three inputs are 64-bit unsigned integers
// and a and b are both less than c.

#ifdef __SIZEOF_INT128__

static inline uint64_t mulmod64(uint64_t a, uint64_t b, uint64_t c)
{   return (uint64_t)(((unsigned __int128)a * b) % c);
}

#else // __SIZEOF_INT128__

static uint64_t mulmod64(uint64_t a, uint64_t b, uint64_t c)
{   uint64_t a1 = a >> 32,           // top half
             a0 = a & 0xFFFFFFFFU;   // low half
    uint64_t b1 = b >> 32,           // top half
             b0 = b & 0xFFFFFFFFU;   // low half
    uint64_t u1 = a1*b1, u0 = a0*b0; // for the double length product
    uint64_t w = a0*b1;
    u1 += w >> 32;
    w <<= 32;
    u0 += w;
    if (u0 < w) u1++;
    w = a1*b0;
    u1 += w >> 32;
    w <<= 32;
    u0 += w;
    if (u0 < w) u1++;
// See the Hacker's Delight for commentary about what follows. The associated
// web-site explains usage rights:
// "You are free to use, copy, and distribute any of the code on this web
// site (www.hackersdelight.org) , whether modified by you or not. You need
// not give attribution. This includes the algorithms (some of which appear
// in Hacker's Delight), the Hacker's Assistant, and any code submitted by
// readers. Submitters implicitly agree to this." and then "The author has
// taken care in the preparation of this material, but makes no expressed
// or implied warranty of any kind and assumes no responsibility for errors
// or omissions. No liability is assumed for incidental or consequential
// damages in connection with or arising out of the use of the information
// or programs contained herein."
// I may not be obliged to give attribution, but I view it as polite to!
// Any error that have crept in in my adapaptation of the original code
// will be my fault, but you see in the BSD license at the top of this
// file that I disclaim any possible liability for consequent loss or damage.
    const uint64_t base = 0x100000000U; // Number base (32 bits).
    uint64_t un1, un0,        // Norm. dividend LSD's.
             vn1, vn0,        // Norm. divisor digits.
             q1, q0,          // Quotient digits.
             un32, un21, un10,// Dividend digit pairs.
             rhat;            // A remainder.
    int s = nlz(c);           // Shift amount for norm. 0 <= s <= 63.
    c = c << s;               // Normalize divisor.
    vn1 = c >> 32;            // Break divisor up into
    vn0 = c & 0xFFFFFFFFU;    // two 32-bit digits.
    if (s == 0) un32 = u1;
    else un32 = (u1 << s) | (u0 >> (64 - s));
    un10 = u0 << s;           // Shift dividend left.
    un1 = un10 >> 32;         // Break right half of
    un0 = un10 & 0xFFFFFFFFU; // dividend into two digits.
    q1 = un32/vn1;            // Compute the first
    rhat = un32 - q1*vn1;     // quotient digit, q1.
again1:
    if (q1 >= base || q1*vn0 > base*rhat + un1)
    {   q1 = q1 - 1;
        rhat = rhat + vn1;
        if (rhat < base) goto again1;
    }
    un21 = un32*base + un1 - q1*c;  // Multiply and subtract.
    q0 = un21/vn1;            // Compute the second
    rhat = un21 - q0*vn1;     // quotient digit, q0.
again2:
    if (q0 >= base || q0*vn0 > base*rhat + un0)
    {   q0 = q0 - 1;
        rhat = rhat + vn1;
        if (rhat < base) goto again2;
    }
    return (un21*base + un0 - q0*c) >> s;     // return the remainder.
}

#endif // __SIZEOF_INT128__

#define TWO32 ((uint64_t)1<<32)
#define TWO44 ((uint64_t)1<<44)
#define TWO52 ((uint64_t)1<<52)
#define extrabase 9375

////////////////////////////////////////////////////////////////////////////
// The following multiplers are used to define a hash function, and the
// table witness[] is accessed by the hash values so computed. The idea
// is that for small numbers n the value witness[hash(n)] will (on its own)
// be a reliable Miller-Rabin witness for checking primality. For
// slightly larger numbers that together with a test using base 2 will
// suffice, while for yet larger numbers I will test using 2, 9275 and
// witness[hash(n)]. Beyond the range where hat can be made reliable
// I will do a Miller-Rabin test using base 2 and a Lucas test as in
// BPSW. That has been verified as reliable up to 2^64 and is expected
// to be good for much larger numbers. At the time of writing there are
// KNOWN numbers that are BPSW pseudoprimes, although it is expected that
// there will be some eventually, withg one estimate suggesting that the
// smallest may be above 10^10000.
////////////////////////////////////////////////////////////////////////////

static const uint64_t hash_multiplier  = UINT64_C(0x6daaf0f718e92f62),
                      hash_multiplier1 = UINT64_C(0x73cc467437fea7eb);

static uint16_t witness[876] =
{    467,   619,  1401,  2531,   565,   541,   541,  5960,  4898,  2239, 
    7312,  5428,  5073, 12721,  2504,  2295,  3068,  1441,  1691, 13611, 
   16061,  1787,  9252, 13396,  5709, 11761,  1293,  4641,  5750,   599, 
     855,  4619, 11141,  8468,   407,   789,  3801,  1321,  7085,    59, 
    7627, 14817,   316,  1174,  2825,  3683, 10266,  1581,   260,  1059, 
     445,  7097, 11739,  5091,  7223, 22648,  1841,   163,  3453,   268, 
    3535,  8598,  1860,  4064,  3473,    46,   322,  2041,  2643,  4955, 
   16465,  1999,  3787,  3895,  6613,  3676, 18565,  1970,  1386, 30735, 
    5362,  1997,  1325,   481, 10302,   444,  6491,  1585, 37813,  4914, 
     928,   446,  4003,  8886,   797,   130,   123, 23956,  1766,  8652, 
    9138,  5023,   852, 14853,   887,  1138, 17292,   130,  1363, 37424, 
     365,  1116,  7993, 15427,  1480,  2054,   326, 22925,   388,  2372, 
    9461,  9998,    88,   524,  2841,    21,   317,  9906,  2046,  6257, 
    1394,  4405,  2911,  9662,  9931,  6646,  2797,  4670,  1434,  1168, 
    5432,   345, 27341,  2033,  1059,  2657,  4142, 31469,  1201, 12047, 
   17009, 13133,  3377,  2545,  1382,   462,  5735, 11823, 18473,  1674, 
    3407,   113,  2131,  5418,  2098,  2354,  3579,  1114,   498,  9594, 
    8497,   680,   367,  4843,  4642, 19958,  2684,   386,  3601, 27771, 
    6657, 55892,  2397,  3172,   520,  8964,  3933, 34396,  3633, 20054, 
    9638,  3373,    87, 13815,  8621, 18168,   891,   898,   950,  2285, 
    3357,  2331,  2103,  2023,  2199,  1126, 11891,  3882, 14557,  2175, 
    1769,  2555,   112,  3819, 13061, 61198,    47,  7813,  5138,  9668, 
   12033,  4166,   126,  3041,  3874,  1739, 40705, 15180,  6804,  1159, 
     644, 18227,  9891,   981,  3470, 10719,  6171,  1377,   777,  4752, 
     259,  1877,   856, 16501,  4270,  8210,  2524,  4460, 10577, 17073, 
     139,   874,  1057,   647,  8558,  7483,  2994, 51685,  5101,   655, 
    3618,  4253, 14018,  7638, 11568,   679,  2641,  2326,  1168,  2261, 
   12906,  1490, 17005, 14543, 48684, 40964,  1405,   362, 29960,   341, 
    6785,  5637, 34942,   388,   611,  4434, 36768,  3943,  3996,   877, 
    3904, 11061,    43, 17197,  1750, 19107,  2571,  4281,  4348,  7167, 
     145,  2959, 10865,  4364, 18307,  6260,   812, 42088, 24122,  2997, 
   11410,  7906, 12547, 55266,  7533,  4065,  3227,  8253,  1842,  2698, 
    3670, 14349, 11832, 22917,  2784,  7406,  7374,  9496,  2337,  1776, 
    2835,   851,  1621,  2396, 26093,   282,  2272,  9759, 10065,  6741, 
    1925,  8979,  1316,  1743,   987,  8991, 17069, 17566, 12001,  8585, 
    1119,  3780,   388,   611,  7755,  8263,  9084,   417,  8521,  5873, 
    1334, 13633, 16771,  3084,  7703, 11640,  9523, 16030,  7242, 12730, 
     430,   403,  1022,  2138,  1245,  7541,  9074,  3619,  5410, 17184, 
   10864,  7476,   899, 12236,  1526, 27916,  4787,  1605,   161,  2194, 
     166,  4538,    47, 55585,  7503,   228,  1719,  2571,  8404,   614, 
    5959,  4043,  3883, 18963,  3949,   563,  3444,  8422, 21004, 15518, 
    2783,  4873,   742,  1133,   159,  5050, 13774, 13260,   772,  3975, 
    5483,  6819, 10461,  1626,   513, 16788,   997,    93,    13,  5526, 
    1190, 10876,   127, 12287,  3009,  1956,  1733,   707,  2822,  8930, 
    6229,   177,  4639,  7602,  2172, 13167, 15486,  3127,  2254,   237, 
    2910, 35962,  9976, 15121,    14,  1564,   181,  6633,  7259,   730, 
   28071,  4793,  1318,  1908, 12440,   293,  2226,  5837,  8261,  3023, 
     847,  3018,  3156,  3431,   755,  5982, 12564,   958, 47391,   650, 
     971,   643, 10878,   834,  3436,   715,  7743,  1962,  4237,  4626, 
     334,     7,  2764,  2219,  1163,   475,  3056,  7699,  4410,  2305, 
     621,  2421,  7219,   106,  2807,   859,   129,  8252,  4390,  4303, 
    1768,    11,  6619,  1625,  7519,  4741, 19026,  2604,  1167,  6591, 
    4298, 14295, 16430,  5817,   347,  6443,  2342,     7, 32465,  2546, 
   10405,  5617,  5723,  5411,   336,   221,  7410,   943, 15827,  8698, 
   28475,  1133,  2146,  4078,  6195,  1985,   819,   102,   592, 47912, 
    4379,  1293, 31174,  2289,  2855,  4044,  1787,    13,  4024,   366, 
   13442, 11196,   398, 26368,   483,  7253, 17295,   253,  1691,  1907, 
      87,   974,  3581,  2564,  1087,   604,   717,  7660, 17579,  1631, 
    1006,  3990,  1823,   257,   290, 11893,  7425,  1216,   962,  9798, 
     229,   342, 34989,  3032,   347,  2253,  3076,  1269, 12125,  7502, 
    3495,   906,   326,   498,  5967, 13434,  1745,  1857,  2169, 43878, 
   10142,  5741,  5031,  1253,  8393,  2760, 14544,  3792,  1190,  3926, 
      78,  1386,  1168,  9376, 21956,   231,   660, 41315,   905,  6273, 
    7670,  4068,  5876,    97, 44368,  4596,   154,  3961,  1530, 19906, 
    1265,    86,  5301,  6268,   412, 17763,    65,   148,  6169,  1096, 
    2132,  1905, 19938,  1332,  4752,  1581,   123,  1136, 12142, 34820, 
    2934,  1218,  8242,   284,  4690,  1557,  1759,  1097,   963,  1397, 
    9405, 25670,  9005, 39237,   587,  3625,  1660,  1017,  6897,  1548, 
   26067,   741,  2142, 11374, 12468,  1650, 15580,    67,   624,  6778, 
    1324,   642,  1726,  2565,  1050, 36802,    95,  4393,  2199,  2924, 
    4334,  5001,   552, 12034,  1390,  4369,  4330,   134, 22958,   210, 
   21080, 16605,  7968,   856,  6455,  2769,  1190,   199,   445,  4423, 
    1953,   825,  3453,  3982, 17986,  5917,   580,  7109,  3166, 14047, 
    6856,  4705,  1291,   707,  2391,  1333,  1634, 19645,  1506,  1128, 
   31823,  4314,  1128,  1412, 28883,   358,  2027,  9543,  8962,   467, 
    1022,   501,  2035,   211,   573,   177,  2764,  4131,   175,   659, 
    1067,  5456,  5152,  1804,  6518,  9264,  1098, 20129,  4555, 44303, 
     700,  2035,  2238,  7941,  1302,  3637,  5480,  1088,   615, 17610, 
    2270, 12096,  3089,  2046,  1618,  6168,   531, 13055, 13644,  2109, 
    1843,   404,  1906,   559,  2323,   769,   574,  1464,    33,  4483, 
    1627, 16966, 15598,  6146,  3394,   723,  2597,  4323, 12886,   372, 
   11732, 15918,   203,  2773,  1514,  1015,  8506,  1337,  3442,  2012, 
    2035,   710, 21397,  3684,   152,  2139, 10728,  5102,   259,   510, 
   37327,  1247,   831,  8351,  1529,  7398, 61997,    41,   724,  1147, 
     371, 35587, 17090,   124, 12735, 50231,  4612,  6469,  1593,  1508, 
   13190, 10027,  5111, 14619,  7980,  1242,  1940,  8799,   924, 10164, 
    6596,  3213,  1441,  5635,  1289, 13233,  1419,   318,  3978, 45947, 
     807, 14718,  1780,   626,   775,   318
};

////////////////////////////////////////////////////////////////////////////
// End of copied (ie machine-generated) material.
////////////////////////////////////////////////////////////////////////////

#define number_of_buckets (sizeof(witness)/sizeof(witness[0]))

// Now code that implements Miller-Rabin. I will do this in a form that
// copes with 64-bit values even when I am only going to be using
// 32-bit ones.

// The function mulmod64(a, b, n) computes a*b mod n where a, b and n are
// all unsigned 64-bit integers.

// Compute x^n mod p

static inline uint64_t exptmod(uint64_t x, uint64_t n, uint64_t p)
{   uint64_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = mulmod64(x, y, p);
        x = mulmod64(x, x, p);
        n = n / 2;
    }
    return mulmod64(x, y, p);
}

// Use Miller-Rabin with base a to check whether n is a (pseudo-)prime. The
// way this is used here should ensure that it is in fact 100% reliable in
// identifying primes. If this was used in a probabilistic context then this
// function would be called repeatedly with random first arguments. In my
// use if is called with carefully selected first arguments so as to avoid
// strong pseudo-primes.

static inline bool miller_rabin_isprime(uint64_t a, uint64_t n)
{   uint64_t d = n-1;
    int s = 0;
    while ((d % 2) == 0)  // Find largest power of 2 dividing n-1
    {   d = d/2;
        ++s;
    }
    uint64_t x = exptmod(a, d, n);
    if (x == 1 || x == n-1) return true;
    while (s > 1)
    {   x = mulmod64(x, x, n);
        if (x == 1) return false;
        else if (x == n-1) return true;
        --s;
    }
    return false;
}

// Note that if the input is only 32-bits wide that the bit that
// multiplies by hash_multiplier1 does not actually contribute here!

static inline int32_t hash_function(uint64_t p)
{   return (uint32_t)
        (((hash_multiplier*p)>>32) ^
         ((hash_multiplier1*(p>>32))>>32)) % number_of_buckets;
}

// This bitmap lets me check numbers up to 4096 for primality especially
// fast.

static uint32_t oddprime_bitmap[] =
{   0x64b4cb6e, 0x816d129a, 0x864a4c32, 0x2196820d, 0x5a0434c9, 0xa4896120,
    0x29861144, 0x4a2882d1, 0x32424030, 0x08349921, 0x4225064b, 0x148a4884,
    0x6c304205, 0x0b40b408, 0x125108a0, 0x65048928, 0x804c3098, 0x80124496,
    0x41124221, 0xc02104c9, 0x00982d32, 0x08044900, 0x82689681, 0x220825b0,
    0x40a28948, 0x90042659, 0x30434006, 0x69009244, 0x08088210, 0x12410da4,
    0x2400c060, 0x086122d2, 0x821b0484, 0x0110d301, 0xc044a002, 0x14916022,
    0x04a6400c, 0x092094d2, 0x00522094, 0x4ca21008, 0x51018200, 0xa48b0810,
    0x44309a25, 0x034c1081, 0x80522502, 0x20844908, 0x18003250, 0x241140a2,
    0x01840128, 0x0a41a001, 0x36004512, 0x29260008, 0xc0618283, 0x10100480,
    0x4822006d, 0xc20c2658, 0x24894810, 0x45205820, 0x19002488, 0x10c02502,
    0x01140868, 0x802832ca, 0x264b0400, 0x60901300
};

static inline int jacobi_symbol_positive_args(uint64_t a, uint64_t b)
{   if (b%2 == 0) return 0;
    int j = 1;
    uint64_t r;
//  if (a < 0)    // I leave this in as a reminder re signed values of a.
//  {   a = -a;
//      if ((b & 3) == 3) j = -j;
//  }
    while (a != 0)
    {   while (a%2 == 0)
        {   a = a/2;
            if ((b & 7) == 3 ||
                (b & 7) == 5) j = -j;
        }
        r = a;
        a = b;
        b = r;
        if ((a & 3) == 3 && (b & 3) == 3) j = -j;
        a = a % b;
    }
    if (b == 1) return j;
    else return 0;
}

static int signed_jacobi_symbol(int64_t a, uint64_t b)
{   if (a >= 0) return jacobi_symbol_positive_args(a, b);
    int r = jacobi_symbol_positive_args(-a, b);
    if ((b & 3) == 3) r = -r;
    return r;
}

// This function must not be given 0 as an argument! It returns the
// length (in bits) needed to represent the argument in binary. So for
// instance
//    integer_length(1)   = 1
//    integer_length(2)   = 2
//    integer_length(4)   = 3
//    integer_length(8)   = 4

static inline int integer_length(uint64_t n)
{   return 64 - nlz(n);
}

// This function must not be given 0 as an argument! It returns the
// index of the least significant set bit in the argument, as in
// instance
//    lsd(1)   = 1
//    lsd(2)   = 2
//    lsd(4)   = 3
//    lsd(8)   = 4

static inline int lsd(uint64_t n)
{
#ifdef __GNUC__
    return __builtin_ctzll(n) + 1;
#else
    unsigned int w = 1;
    if ((n & 0x00000000FFFFFFFFU) == 0) { w = w +32; n = n >>32; }
    if ((n & 0x000000000000FFFFU) == 0) { w = w +16; n = n >>16; }
    if ((n & 0x00000000000000FFU) == 0) { w = w + 8; n = n >> 8; }
    if ((n & 0x000000000000000FU) == 0) { w = w + 4; n = n >> 4; }
    if ((n & 0x0000000000000003U) == 0) { w = w + 2; n = n >> 2; }
    if ((n & 0x0000000000000001U) == 0) { w = w + 1; }
    return w;

#endif
}

// logbitp counts the least significant bit of the number as bit 0.

static inline int logbitp(int pos, uint64_t a)
{   return (a & ((uint64_t)1<<pos)) != 0;
}

static inline uint64_t addmod64(uint64_t a, uint64_t b, uint64_t c)
{
// If a and b are both in the range [0..c-1] then (a+b)%c will be either
// a+b or a+b-c. There are two circumstances where I must go for the second
// of these. The first is where the calculation a+b overflows the uint64_t
// type. That case can be detected by the calculated sum being smaller than
// one of the operands. In that case the true value of a+b is at least 2^64,
// and i is smaller than that, so subtracting it to restore things is good.
// The second case is where a+b does not overflow, but ends up at least as
// large as c.
    uint64_t w = a + b;
    if (w < a || w >= c) w -= c;
    return w;
}

static inline uint64_t negatemod64(uint64_t a, uint64_t c)
{   if (a == 0) return a;
    else return c - a;
}

static bool is_perfect_square(uint64_t n)
{   if (n <= 1U) return true;
// I will find where the most significant bit of the input is... I can
// use a built-in function if I am using or fully compatible with g++,
// otherwise I code it for myself.
    unsigned int w = integer_length(n) - 1;
// Now I will generate an approximation to the square root of my
// input by shifting it right by half its length, but then applying
// a simple linear approximation that leaves my result exact on every other
// power of 2.
    uint64_t r = n >> (w/2);
    r = (r + ((uint64_t)2 << (w/2))) / 3;
// I do an initial Newton-Raphson step.
    r = (r + n/r)/2;
// This initial step will always leave me with an over-estimate for the
// square root, so I can iterate until the value stops decreasing.
    uint64_t r1 = (r + (n/r))/2;
// When I have done the second step I check if that decreased my
// approximation, and if it did I will do another.
    if (r1 < r) r1 = (r1 + (n/r1))/2;
// It turns out that with the initial approximation I used here and this many
// steps I will always have the exact square root at least for any input value
// that is a perfect square. I ran a trivial test program that tried the
// squares of every possible 32-bit value so I could be certain of that!
//
// If I now have a value that squares up to give the original value I must
// have started with a perfect square. Otherwise not.
    return (r1*r1 == n);
}

static uint64_t gcdn(uint64_t a, uint64_t b)
{   while (b != 0)
    {   uint64_t c = a % b;
        a = b;
        b = c;
    }
    return a;
}

// This  code for the Lucas test will only be invoked if small factors
// for c have been rules out. In particular c will certainly be odd. It
// returns true if c is a Lucas probable-prime.

static bool trace_primep = false;

static int64_t mmod(int64_t a, uint64_t c)
{   if (a >= 0) return a%c;
    a = a % (int64_t)c;
    if (a < 0) a += c;
    return a;
}

#define P PRIu64
#define D PRId64

static bool lucas_test(uint64_t c)
{
    int64_t d;
    int j;
    uint64_t k, kk, u, v, q, qk, tmp;
    int l, ll;
// Find a proper value for D such that jacobi(d,c)=-1. This is achieved
// by trying the sequence 5, -7, 9, -11, 13, -15, 17, -19, 21, -23,....
// until one works (note that 9 and 25 can not work because they are perfect
// squares, but they are included in the test sequence anyway. It is very much
// expected that almost always a suitable d will be found within the first
// couple of tries. If the input c had been a perfect square then there will
// never be a valid d, so if I am searching for longer than expected I will
// divert and check for that. At present the world believe that even for the
// biggest inputs one could envisage here that the value of d found will be
// small.
    d = 5;
    while ((j = signed_jacobi_symbol(d, c)) > 0 &&
           (d != 21 || ~is_perfect_square(c)))
    {   if (d > 0) d = -d - 2;
        else d = -d + 2;
    }
    if (trace_primep)
        printf("Test %" D " using D=%" D ", j=%d\n",
               c, d, j);
// j would be zero if d and c had a non-trivial gcd (and hence unless
// |d|=c and d is a prime c is certainly composite. Well in the big picture
// I will only be using this when c > 2^52 and for d to get that large would
// take more time than could possibly be feasible.
// j would be 1 if I exited because c was a perfect square, and again that
// means it is not prime. Well if c = |d| then c might still be a prime!
    if (j >= 0)
    {   if (d < 0) d = -d;
        if (c != (uint64_t)d) return false;
// Now I need to check if c is prime, but I very strongly expect it to be
// a really small value, so I will use crude code. Let me remind myself that
// it is an odd number.
        for (uint64_t f=3; f*f<=c; f+=2) // Test division by odd numbers...
           if (c%f == 0) return false;
        return true;
    }
// The sequence of values for d that are tried guarantee that the divison
// by 4 here is always exact. I will evaluate q modulo c.
    if (d < 1) q = (1-d)/4;
    else q = c - (d-1)/4;
    if (trace_primep)  printf("will use P=1, Q=%" P "\n", q);
// Another cheap test for easy cases that could detect c being composite, and
// where c > 2^24 and d having been found by checking in an arithmetic
// progression means I can not have q prime and q = c.
    if (gcdn(c, q) != 1) return false;
    k = c + 1;
    if (k == 0) return false; // Overflow, but 0xffffffffffffffff is composite.
// I now set up a Lucas sequence with initial values u_0=1, v_0=2, u_1=1, v_1=1
// and the general iteration u_{n} = u_{n-1} - q u_{n-2}. In terms of articles
// about Lucas sequences this is the special case where p=1.
    u = 1;
    v = 1;
// For small examples I can compute the Lucas sequence in a naive manner
// and display all the values. This is intended to be useful for comparison
// with the values calculated below using the more sophisticated method.
    if (trace_primep && c < 500)
    {   int64_t w, u0, u1, ut, v0, v1, vt;
        uint64_t nn[200];
        int nnp = 0;
        w = c + 1;
// I will tabulate the values of k that the doubling method will go via..
// Note that the arithmetic that I do here is using signed 64-bit values and
// those can easily overflow...
        while (w != 0)
        {   nn[nnp++] = w;
            if (w%2 == 0) w = w/2;
            else w = w-1;
        }
        u0 = 0; u1 = 1;
        v0 = 2; v1 = 1;
        for (uint64_t i = 1; i<=c+1; i++)
        {   ut = u1 - q*u0;
            vt = v1 - q*v0;
            u0 = u1; u1 = ut;
            v0 = v1; v1 = vt;
// I display k, u_k, v_k and then those two values modulo c, just in the
// cases that should arise in the cleverer doubling code.
            int j;
            for (j=0; j<nnp; j++)
                if (i == nn[j]) break;
            if (j >= nnp) continue;
            if (trace_primep)
                printf("%" D ":  "
                    "[%" D ", %" D "]  "
                    "%" D "   %" D "\n",
                    i, mmod(u0,c), mmod(v0,c), u0, v0);
        }
    }
// For subsequent arithmetic to work properly I must ensure that even if
// q starts off negative I have a version of it reduced to the range [0,c) to
// work with. Similarly d. The variable qk will hold q^k where k is an index
// into the Lucas sequence. 
    qk = q;   // Well for q I already did this.
    if (d < 0) d = c + d;
// I will iterate downwards over bits in a binary representation of (c+1).
// well to implement a Strong Lucas Test I need to iterate down until I
// have no more below bits set in k.
    l = integer_length(k) - 1;
    ll = lsd(k) - 1;
    if (trace_primep) 
        printf("k=%" P " uses %d bits and has %d trailing zeros\n",
            k, l+1, ll);
// I will first do the part of the Lucas sequence up to where it will have
// used up all the nonzero bits in the representation of k. kk will track how
// far I have gone, and is only needed for trace output but tracking it is
// cheap.
    kk = 1;
    if (trace_primep) printf("1:     [1, 1]\n"); // Always the start-line!
    while ((l = l-1) >= ll)
    {
// I can double a subscript in the Lucas sequence using:
//    u_{2k} := u_{k} v_{k}
//    v_{2k} := v_{k}^2 - 2 qk_{k}
//    qk_{2k}:= qk_{k} qk_{k}
// and happily I can do those updates sequentially.
        u = mulmod64(u, v, c);
        v = addmod64(mulmod64(v, v, c),
                     negatemod64(mulmod64(2, qk, c), c), c);
        kk = 2*kk;
        qk = mulmod64(qk, qk, c);
        if (trace_primep)
            printf("%" P ": [%" P ", %" P "] q^k=%" P "\n",
                kk, u, v, qk);
        if (trace_primep)
            printf("(A) l=%d ll=%d k=%" P " logbit=%s\n",
                l, ll, k, logbitp(l, k) ? "t" : "nil");
// Now I need to do a step whenever there is a "1" bit in the binary
// representation of k.
        if (logbitp(l, k))
        {
// The rule used here is:
//    u_{k+1} = (u_{k} + v_{k})/2
//    v_{k+1} = (d u_{k} + v_{k})/2
//    qk_{k+1}= q qk_{k}
// and again all the arithmetic is to be done modulo c. I need a temporary
// veriable when updating u and v since each depends on the other.
            tmp = addmod64(u, v, c);
            v = addmod64(mulmod64(d, u, c), v, c);
            u = tmp;
// Dividing by 2 when I have an even modulus is something I can write out
// in-line here rather easily, and I expect this to be nicer than using
// modular!-quotient or even that having computed a modular reciprocal of 2
// and doing a modular multiplication by it. But I need to be slightly
// careful to ensure that I avoid overflow.
            if ((u & 1) != 0) u = (u+1)/2 + (c-1)/2;
            else u = u/2;
            if ((v & 1) != 0) v = (v+1)/2 + (c-1)/2;
            else v = v/2;
            kk = kk + 1;
            qk = mulmod64(q, qk, c);
            if (trace_primep)
                printf("%" P ": [%" P ", %" P "] q^k=%" P "\n",
                    kk, u, v, qk);
        }
    }
// From now on I will only do doubling operations, and they are of the form
//      u = u*v;
// so if u is zero now I can be certain that it will be at the end, and the
// Regular (as distinct from Strong) Lucas test will be passed.
    if (u == 0)
    {   if (trace_primep) printf("u=0 so value is probably prime\n");
        return true; // Probably prime!
    }
// Now all the rest of the Lucas sequence is done using just the "doubling"
// process. But I am no longer interested in u.
    if (trace_primep)
    {   printf("After final non-doubling step u = %" P "\n", u);
        printf("Will just do doubling steps from now on...\n");
    }
    while (v != 0 && (l = l-1) >= 0)
    {
// I can again double a subscript in the Lucas sequence using:
//    v_{2k} := v_{k}^2 - 2 qk_{k}
//    qk_{2k}:= qk_{k} qk_{k}
        v = addmod64(mulmod64(v, v, c),
                     negatemod64(mulmod64(2, qk, c), c), c);
        kk = 2*kk;
        qk = mulmod64(qk, qk, c);
// I do not compute u here because at each stage I just multiply u by v. If
// I have a prime then this is a field multiplication and u can only end up zero
// if some v is zero.
        if (trace_primep)
            printf("%" P ": [??, %" P "] qk=%" P "\n",
                kk, v, qk);
        if (trace_primep)
            printf("(B) l=%d ll=%d k=%" P " logbit=%s\n",
                l, ll, k, logbitp(l, k) ? "t" : "nil");
    }
    if (trace_primep)
        printf("exit loop with l = %d and v = %" P "\n", l, v);
// If at this point v=0 then c is a Strong Lucas Probable-prime using the
// values p=1 and q as derived here.
    return (v == 0);
}

#if 0

// This little test program finds the first few Strong Lucas pseudoprimes
// by using my code (as above) and comparing results against a naive
// trial division test for odd numbers. It should display the sequence
// 5459, 5777, 10877, 16109, 18971, 22499, 24569, 25199, 40309, 58519,
// 75077, 97439, 100127, 113573, 115639, 130139, 155819, 158399, 161027,
// 162133, 176399, 176471, 189419, 192509, 197801, 224369, 230691,
// 231703, 243629, 253259, 268349, 288919, 313499, 324899
// which is A217255 in the on-line encyclopedia of integer sequences.
// I am taking a view that at least up until overflow could intervene
// that re-creating that sequence is a pretty good signature of correctness.


int main(int argc, char *argv[])
{   int npseudos = 0;
    for (uint64_t i=3;;i+=2)
    {   int f;
        for (f=3; f*f<=i; f+=2)
            if (i%f == 0) break;
        if (f*f > i) continue; // i is a prime;
        if (lucas_test(i))
        {   printf("%" P "\n", i);
            if (++npseudos > 20) break;
        }
    }
    printf("testing complete\n");
    return 0;
}

#endif

bool isprime(uint64_t n)
{
// I will start by filtering out potential very small factors. This
// detects a significant fraction of composites cheaply, and is expected to
// be overall good for average efficiency.
    if (n <= 4096)
    {   if (n%2 == 0) return n == 2;
        else return (oddprime_bitmap[n/64] & (1<<((n/2)&31))) != 0;
    }
// The next line checks for divisibility by 2, 3 and 7 ...
    if ((UINT64_C(0x000001df5d75d7dd) & (UINT64_C(1)<<(n%42))) != 0)
        return false;
// ... and this one copes with 5 and 11.
    if ((UINT64_C(0x0004310a42508c21) & (UINT64_C(1)<<(n%55))) != 0)
        return false;
    if (n%13 == 0 ||
// There factors checked for here are picked so that they include numbers
// that are most often factors of base 2 strong pseudoprimes. Between all of
// these this only spots factors of around 0.5% of the pseudoprimes up to
// 2^64.
        n%29 == 0 ||
        n%31 == 0 ||
        n%37 == 0 ||
        n%41 == 0 ||
        n%53 == 0 ||
        n%61 == 0 ||
        n%101 == 0 ||
        n%109 == 0 ||
        n%113 == 0 ||
        n%137 == 0 ||
        n%157 == 0 ||
        n%181 == 0) return false;
// Now if the value if a 32-bit integer I can use just one Miller Rabin
// test using a carefully selected base.
    if (n < TWO32)
        return miller_rabin_isprime(witness[hash_function(n)], n);
// For larger numbers I will test using base 2 and then some more work.
    if (!miller_rabin_isprime(2, n)) return false;
// For numbers over 2^52 I will do a Miller Rabin with base 2 and then
// a Lucas test. That is known safe up to 2^64 and believed safe to more
// like 10^10000. The Lucas test is expected to be as costly as around 3
// further rounds of Miller Rabin.
    if (n >= TWO52) return lucas_test(n);
    if (!miller_rabin_isprime(witness[hash_function(n)], n)) return false;
    if (n < TWO44) return true;
    return miller_rabin_isprime(extrabase, n);
}

// end of isprime.cpp
