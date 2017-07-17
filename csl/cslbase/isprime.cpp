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

// This is free-standing code.
// It provides a function "bool isprime(uint64_t n)" that tests if n
// is a prime number.

// See https://sourceforge.net/projects/isprime64/ for the programs used
// to create the various tables used here.


#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Since this file exists to define just a single external function I will
// write its declaration here rather than having a trivial header file
// to declare it.

extern bool isprime(uint64_t n);

///////////////////////////////////////////////////////////////////////////


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
//
// Note that I have three tables covering different ranges of inputs.
////////////////////////////////////////////////////////////////////////////

static const uint64_t hash32_multiplier  = UINT64_C(0x8a567b9f2727be4c),
                      hash32_multiplier1 = UINT64_C(0xf36a97a8291379c4);

static uint16_t witness32[208] =
{   4756,  4099, 14017,  4688,  1257,   134,  8773,  8027, 21348,  1198, 
   45041,  6576,  6231,  4117,  3626,  7230,  6535,  8173,  5790,  8544, 
   17855,  2464, 29443,   585,  3363,   337,  9820, 13854,  1938,  7603, 
    1648,  1594,  1329,  9831, 41997,  7080,  1082,   604,  3300,   136, 
    9684,  9341,  5745, 10047,  5053, 50655,  9976,  9331,  3955, 65043, 
    1442, 29683, 18239, 12819, 10606,  4493, 21183, 10425, 13314,  1270, 
   42246,  7663, 25626,  4711,  5762,  1091,  9232,  6299,   536, 15162, 
    1394, 14538,  4070,  1209,  6532,  1216,   244,   284,   182,  4870, 
   45076, 29570,  4426, 62446, 13131, 17177,  4038, 20067,  4838, 13419, 
     607,  4035,  3245,  1039,   152,  2526,  4033,  2945, 61385, 17110, 
    9064,   302,  5541,  2725, 33058,  7782,  3649,  2585,   347,  2112, 
    1111,  2222,  8470, 12089,  2148, 14272,  9378, 15782,  2137, 39825, 
   24543,  9836,  4330,  1053,  5319, 17121,  3995, 11879,  1038, 15327, 
    1725,  5854,  7864,  2733, 34344, 15106,  5449,  4400, 13495,   278, 
    1529,    95,   916,   419, 11969,  1884, 27404, 12835,  3227,  5848, 
   10781, 25357, 31475,  4912, 21772,  6350, 33100,  2244,  8530,  4866, 
   22761,  4544,   632,  2040,  3988,   617,   717, 23615, 11565,  2717, 
     915, 11348, 21533, 23740,  1433,  4410,  6065,  6182, 12412,  5743, 
    2703,  2979,   816, 13070,  4909,  6186,  4741, 14548, 26191,  4737, 
   14883,  1633, 14140, 19368,  5363, 36685, 25228, 21839,  3590,  7686, 
   10636,   193,   592,  2976, 18895, 27296, 20698,  8241
};

////////////////////////////////////////////////////////////////////////////

static const uint64_t hash44_multiplier  = UINT64_C(0x38caf47d856d4a84),
                      hash44_multiplier1 = UINT64_C(0x641a6962e0118ce3);

static uint16_t witness44[346] =
{   5585,  6401, 10442,  5250, 12914,  5319,  6710,  2013,  2814,  2118, 
   10126,  2403, 10014,   183, 17807, 23191,  6573, 13765,  4558,  6006, 
    2578,   301,  1035,  1397,   677,  9833,  3503,  2399,  1131,   742, 
    9114,   215, 13517,  1084, 62114,   429,   206,  1605, 16825,  5431, 
    1123, 64530, 27899,  2169,  8835,  2221,  1237, 32950, 17558, 24034, 
   12269,   157,  8778, 54414,  2899,  4674,  3939, 13665,   431,  8067, 
    3431, 15419,  1173, 13239,   693,  8822, 14250,  1585,   425,  2359, 
   25463,  1678,  6147,  4922, 30133,  3751,   634,  8315,  3591,  9337, 
    6043, 46861,  5382, 48303,  9353, 10205,   154, 17061, 21035,   375, 
    6439,  1314,   754,   154,  2319,  1526,  6231,  4925,  4301, 15906, 
   24561,  1641,  2313,  5633,  7823,  6199,  1026,  4058,  3779,  5569, 
   37943,  5995, 59379, 24635, 56142, 13383,   379, 21833, 10686,  4482, 
   48927,  4130,  7879,  2251, 45027,  6883, 14951, 25387,  1609, 14627, 
    7018,  2535,  6149,   403,  3561, 13738, 61514, 30919,  5057, 46698, 
   29746,   787,  7551,  8990,  5325,  1271,  5226,  9295, 18031,  2403, 
     435, 27335,  2015,  5057,  5410,  3591, 15701, 26327,   629,  5315, 
    3894,  1007,  2059, 11164, 57007,  6038,   503,  4386, 45943,  2041, 
     774,  8326,  1270, 28738,   179, 19297, 15222,  5711, 23433, 44871, 
    1150,   167, 50947,   215,  5091,  9594,  2513,   370,  6691,  1207, 
   17574, 20817,  4730, 16425,  1698,  3511, 52554,  3101,  4686,    15, 
    9067, 19738,  8317,   454,   247,  1655,  1565, 13635,  2629,  5355, 
   11603, 59841,   434, 29773,  1113,  5977,   543, 15699,   334,  3321, 
    1994, 15142, 12917,  2799,  1625, 51983,  1739, 14878,  7543,   373, 
     389,  1531,  4885,  6965,  3947,  6242,  1609,  1229,  6698,  7091, 
   20027, 10698,  1173,  5987,  1685,   730, 13896, 18759,  3213,  2937, 
   18829,  2399,  6653,  1703,   483,   735,  1475, 24462, 13123,  1023, 
     386,  3398, 31649, 10653,  9714, 12655, 12973,  7531,   693, 11381, 
   12233, 19790, 22333, 39110, 10907, 47237,  9452, 28410,  4006,  2477, 
   57554,  7763,     3,  8771,  2630,  3234,  3415, 38627, 10655,  3645, 
     777,  1394,   806, 12165,  1883, 20897, 23343,    15,  6341,  2006, 
     421,  6282, 26905,   607,  2822, 26647,   505,  2477, 42570,  1963, 
    2906, 10438,   825,   238, 22153,  8903,   469,  8698,  4962,  1119, 
   12673,  4931, 18242,  1583,  1791,  2666,  4839,   465, 25591, 21758, 
   37786, 19239,  6099, 22775,  6198, 32911,  1754,  1173,   775,   765, 
     526,  1034,  4038,  3702,  8623,  1393
};

////////////////////////////////////////////////////////////////////////////

static const uint64_t hash52_multiplier  = UINT64_C(0x16e52999af624d0f),
                      hash52_multiplier1 = UINT64_C(0x013baabcb446ec3a);

static uint16_t witness52[296] =
{  30873,  8027, 15305,  2033, 11922,  8779, 41631,  1661,    43,  1959, 
   32295, 19615,   963, 10601,  3013,   255,   213,  4723,  1542, 19570, 
    4491,  1953,   541,  1137,  2406, 17499, 10457,  2173, 13618, 12434, 
   11463, 18729,  3535, 14725, 21322, 15417,   654,  4298,  1582,   574, 
   43685,  3247,  1065,  7635,  4497, 28185,  4983,  1221,  2365,  3427, 
    2441,   518,  1437,  6081,  1339,    51,    65,  1759,  9402, 13903, 
   10591,  3977,   105,  1163,  4925,  1679,  6929, 10197,  2987,  1543, 
     157,  2693,    23,  3385, 10309,  3149,  4495,  4534,  4447,  3498, 
    6614, 11059,  5361,  8059,  2585, 13547, 25919,  9313,    47,   397, 
   13082,  5021, 12553,  2687,  3089,  4914,   319, 47686, 33067,  1526, 
    3451,  9002,  1265, 10641,  2307,  2118,   643, 13046,  6506,  1025, 
   32795, 20378,  1187,   434, 30342,  5815, 14033,  1447,   115, 44619, 
    1871,  3622,  6177, 24807, 56301, 22775,  1115,  3385,   394,   797, 
     106,  1893,  2863,  2151,  8093,  5045,  8898,  3655, 10791,    57, 
    2369,  2193,  7481,   181,   219, 10823,  1043,  1605, 11495,  5058, 
     893, 11342,  8010,   297, 19123, 51933,  1394,  6747,  2778,   287, 
    4041,  4337, 19831,  1071,   833,  2758, 28594,   829,   145,   223, 
   12113,   335, 10463, 12631,  2081, 17730,  1821,  6614,  8294,  2894, 
    1294,  1263,  8955,   518,  9083, 29993,  7577,  4842,  7581, 56085, 
    9081,  5059,  4243, 14079, 18141,  3810,  5515,  1329,  7917,   277, 
    1545, 24202, 22409,  1391,  1978,  2242,  4006,  5074,   227,  6043, 
    4707, 45947,   913,  7279,   829, 17525,   706, 24653,   622,  1602, 
    3993,  4878,  1863,  5065,  4079,  2978,  1786,  1925,  1869,  1026, 
    3051,  4861,   153,   934,  5274,  5433, 24335,   787,  6147,  1697, 
    4155,  9399,   127,  6126,  2186,  5891,  1667, 17023,  4386, 41458, 
   11633, 17002, 22234,   819, 28733,  6878,   106, 54767, 12970,  1339, 
     758,  5891,  6323,  4381,  4173,  2663,   178, 22566,  7542, 35271, 
     621,   966,   290,  4475,   479,  6133,  1559,  5903,  1277, 13269, 
    3337,  3821, 10746,  4953, 27797,  5919,  5183,  3755, 25051, 13987, 
   18039,  4919,  5105, 28917,  8823,   254
};

////////////////////////////////////////////////////////////////////////////
// End of copied (ie machine-generated) material.
////////////////////////////////////////////////////////////////////////////

#define number32_of_buckets (sizeof(witness32)/sizeof(witness32[0]))
#define number44_of_buckets (sizeof(witness44)/sizeof(witness44[0]))
#define number52_of_buckets (sizeof(witness52)/sizeof(witness52[0]))

// Now code that implements Miller-Rabin.

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

// To make the treatment of 32-bit inputs faster I have a second copy
// of the above code, but here restricted to 32-bit inputs.

static inline uint32_t exptmod32(uint32_t x, uint32_t n, uint32_t p)
{   uint32_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = (uint32_t)(((uint64_t)x*y)%p);
        x = (uint32_t)(((uint64_t)x*x)%p);
        n = n / 2;
    }
    return (uint32_t)(((uint64_t)x*y)%p);
}

static inline bool miller_rabin_isprime32(uint32_t a, uint32_t n)
{   uint32_t d = n-1;
    int s = 0;
    while ((d % 2) == 0)  // Find largest power of 2 dividing n-1
    {   d = d/2;
        ++s;
    }
    uint32_t x = exptmod32(a, d, n);
    if (x == 1 || x == n-1) return true;
    while (s > 1)
    {   x = (uint32_t)(((uint64_t)x*x)%n);
        if (x == 1) return false;
        else if (x == n-1) return true;
        --s;
    }
    return false;
}

static inline int32_t hash32_function(uint32_t p)
{   return (uint32_t)
        ((hash32_multiplier*(uint64_t)p)>>32) % number32_of_buckets;
}

static inline int32_t hash44_function(uint64_t p)
{   return (uint32_t)
        (((hash44_multiplier*p)>>32) ^
         ((hash44_multiplier1*(p>>32))>>32)) % number44_of_buckets;
}

static inline int32_t hash52_function(uint64_t p)
{   return (uint32_t)
        (((hash52_multiplier*p)>>32) ^
         ((hash52_multiplier1*(p>>32))>>32)) % number52_of_buckets;
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

static const bool trace_primep = false;

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
// The cut-off at 500 is entirely arbitrary, but tabulating more than 500
// lines of sequence would start to get clumsy. The trace_primep flag is
// only intended to be set when you are debugging and then only when looking
// at small inputs.
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
// test using a carefully selected base. Furthermore the Miller Rabin test
// is coded so it can only handle values up to 32 bits, which means that
// the intermediate result of modular multiplication fits into 64-bits.
    if (n < TWO32)
        return miller_rabin_isprime32(
            witness32[hash32_function((uint32_t)n)], (uint32_t)n);
// For larger numbers I will test using base 2 and then some more work.
    if (!miller_rabin_isprime(2, n)) return false;
    if (n < TWO44)
        return miller_rabin_isprime(witness44[hash44_function(n)], n);
    else if (n < TWO52)
        return (miller_rabin_isprime(extrabase, n) &&
                miller_rabin_isprime(witness52[hash52_function(n)], n)) ;
    else return lucas_test(n);
}

// end of isprime.cpp
