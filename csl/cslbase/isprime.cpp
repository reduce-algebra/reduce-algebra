// isprime.cpp                           Copyright (C) A C Norman 2020-2022

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

// This is free-standing code.
// It provides a function "bool isprime(uint64_t n)" that tests if n
// is a prime number.

// See https://sourceforge.net/projects/isprime64/ for the programs used
// to create the various tables used here.


#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif

#include <cstdio>
#include <cstdint>
#include <cinttypes>

#ifndef __has_cpp_attribute
#define __has_cpp_attribute(name) 0
#endif // C++17 support

#if __has_cpp_attribute(maybe_unused)
// C++17 introduced [[maybe_unused]] to avoid warnings about unused variables
// and functions. Earlier versions of gcc and clang supported [[gnu::unused]]
// as a non-standard annotation with similar effect.
#define UNUSED_NAME [[maybe_unused]]
#elif defined __GNUC__
#define UNUSED_NAME [[gnu::unused]]
#else
// In any other case I just omit any annotation and if I get warnings about
// unused things then so be it.
#define UNUSED_NAME
#endif

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
    if (x <= 0x00000000FFFFFFFFU)
    {   n = n +32;
        x = x <<32;
    }
    if (x <= 0x0000FFFFFFFFFFFFU)
    {   n = n +16;
        x = x <<16;
    }
    if (x <= 0x00FFFFFFFFFFFFFFU)
    {   n = n + 8;
        x = x << 8;
    }
    if (x <= 0x0FFFFFFFFFFFFFFFU)
    {   n = n + 4;
        x = x << 4;
    }
    if (x <= 0x3FFFFFFFFFFFFFFFU)
    {   n = n + 2;
        x = x << 2;
    }
    if (x <= 0x7FFFFFFFFFFFFFFFU)
    {   n = n + 1;
    }
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
// there will be some eventually, with one estimate suggesting that the
// smallest may be above 10^10000.
//
// Note that I have three tables covering different ranges of inputs.
////////////////////////////////////////////////////////////////////////////

static const uint64_t hash32_multiplier  = UINT64_C(0x6f1ec8475ebe63cc);
UNUSED_NAME static const uint64_t
                      hash32_multiplier1 = UINT64_C(0x9b814cb804ce0bfe);

static std::uint16_t witness32[195] =
{   45413, 15318,  5566,  9894,  4093,  2426, 55517,  6987, 60065, 35349,
    14914, 25548,   241,  6538, 17249, 26225,  3768,  4276, 38551, 20617,
    18732,  3630,   599,  2364, 11690, 47189, 37347, 54919, 14461, 39832,
    24975, 62470, 45662, 22648,   651, 14052,  9172,  1238, 27109,  7897,
    31236, 14429, 12647, 13749, 15222,  8375,  2357, 36357,  3606,  3864,
    2383,  4272,  4629, 13100,  3945, 16010, 45695, 36072, 10557, 26589,
    29800, 15950, 10069,  2436,  4230,  3587,  2369,  3208,   843,  4426,
    62447, 14769, 56756, 32422,  6044, 15024, 20529,  3162, 10418,  3122,
    30659, 58608,  7152,  9966,  4340, 40179,   312, 12580, 62062,  7808,
    26287, 63583,   739,  4859, 34729,   748, 35862,  6142, 63793, 11875,
    44977, 16468,  9070, 25518, 17831,  9756,  8368,   956,  5079,  4347,
    13525, 21305, 22515, 17121,  2248, 60691, 14335, 22343,  2073,  1080,
    5475, 56183, 15275,  1563, 23412, 18837,  4056, 64371,  3950, 34221,
    5316, 14776,  9367,  6548,  6845, 47912, 16547,  7873, 64416,  2524,
    5736, 24519,   937,  7460,  5803, 11744,  8975, 23875,  1043,  9073,
    10387, 20851,  3503, 28770, 12260,  9338,  2707, 20006, 25957, 20942,
    2234,  7592,  7461, 25765,  3627,  2994,   151, 12829,  6019, 14130,
    3736, 22994,  7271, 50551,  4775,  8438,   408, 10272, 55347,  3881,
    11844, 52884, 11733, 31908,   224,  9411, 18917,  1961,  3094, 33594,
    13477,  5301, 47785,  4655,  6465
};

////////////////////////////////////////////////////////////////////////////

static const uint64_t hash44_multiplier  = UINT64_C(0x7549c298f9834e52),
                      hash44_multiplier1 = UINT64_C(0x955be7f2d22d28a2);

static std::uint16_t witness44[335] =
{   25490,  4297, 10653, 29662, 40495,  3011, 24362, 61027,   715,  3506,
    17551, 32135,  2822,   737, 13905,  1637,  8841, 37050, 12327, 11209,
    29, 19513, 15513,  1731,  1603,   582,  1655,   299,  2711,  4641,
    2259, 14233, 16474,   379, 20781, 31147, 19653,  1811, 16446,  1767,
    4645,  1943,  3741, 12637,  2231, 49207,  6322,  6713,  1515,  9290,
    3453, 12850, 20523, 18361,   358,  9058, 12473, 15085, 15645,  9411,
    5502,  6205,  6318,  7617,  2246,  2987,  4002,  3405,  4643,   247,
    40399, 16171,  2969, 18779,  2461,   678, 10214,  7286, 33019,  6133,
    37288,  5814,  2207,  6302,    33, 48847,  3862,  4618, 22739,  2695,
    1343,  1274,   811,  4490,  2586,  4933, 32498, 34875, 16027, 16414,
    2562, 15663,   589, 13665,  2273,  1423, 14575, 12081,  2771,  2366,
    15927, 10838,  8485, 13623,  4479,  2606,  7489, 10733, 11059,   710,
    30109,   910,  7851,  9098,  7886,  3875,  6081,  4235, 19887,   913,
    18193, 38701, 12261,  1215, 10369,  5758, 28855, 53514, 19342,  1146,
    15779,  6662,  2665, 59634,  7075,  1105, 32029,  9138, 18801, 18246,
    661,  1335,  9742, 50417, 53055,  5581,  2142,  8377,  7598, 17879,
    4833,  3103,  1570,  2530,  2002, 12230,  2635,   118,   799,  1626,
    974,  1701,   394,  6925,  2925, 16070, 14613,  9135,  5197, 26370,
    27118,  1755, 53687,  1111,   468,  3602,  1438,  4365, 18211, 17249,
    21385, 63037,  3105,  2665, 55265,  1443,   874,  1870,  7646,  5141,
    4917,   323,  4055,  2715,  4379, 13890,  5109,  9725,  1203,   209,
    10698,   517, 27069,  3414,  6285, 15935, 15203,   423,   531,  5607,
    27567,   785, 23266,  7979, 21617, 24001,  9623,   866, 29915,  6899,
    8851, 40886,   103, 27601, 14885,  1561,  8511, 45313,  5346, 26462,
    975,   806,  3283,   535, 20839,   946,   569, 63349, 16063,  3681,
    4154,  3730,  3605, 11794,  1947,   886, 17695,  9166,  9741, 18482,
    593,  1413,  2775,  5470, 28541,  7427,  3891,  5197,  5130, 16423,
    5479,  5985,  2070, 33119,  7347,  3710,  2335, 35789,  1421,  3035,
    2415,  3682,  9170, 13431,  8426,  2221,  4793,  3202, 26298, 10314,
    3743,   769,  9643,   985,  6650, 13133,  8509,  1830,  2079,   391,
    4835,  8822,  1887,  4722,  2815,  3529,   191, 16799, 20057,   305,
    4934,  4231,   198, 52811,   643,  3277, 12353,  2599,  1469,  9299,
    34361, 33505,  6237, 22902,  3489, 14627,  4855,  4826,  1622,  3990,
    19577,  4218, 13015, 40754,  1513
};

////////////////////////////////////////////////////////////////////////////

static const uint64_t hash52_multiplier  = UINT64_C(0x222156ef26884dc1),
                      hash52_multiplier1 = UINT64_C(0x8cd52a331c96952f);

static uint16_t witness52[284] =
{   26379, 47775, 17083,  2425, 33806,  3946, 12979, 18862,  3529, 11502,
    22435, 16230,  1915, 21314,   365, 48603,  8143,  2893, 17057, 32861,
    3503,  7915, 11757,  3082, 11461,  5321,  3307,   149,  4130,    29,
    9030,  9966,  9817,   427,   585, 16331,   457, 19890, 15951, 11731,
    459, 29026,  3351, 33749,  1425, 35957,  5178, 12078,  9946,  9229,
    4621,  1883,  6015, 22567,   342, 16499,  2186,  5734,   862, 59618,
    1239, 21214,   615, 11161, 40743, 41787,   637,  1047, 20629, 53283,
    1979,   323,   615,  1513,  3627,  5739,  6290,  7042,  2630,  9410,
    8181,  1823,  6401,  2174, 10169,  8466,  6741,   979,   915,  6046,
    6090,  6046, 12127, 37303,  2758, 19525,  5717,   426,  6935,  2502,
    47083,   111, 21281, 14002, 11247,  1101,  2849, 11654,  3355,  9002,
    12345, 28821, 10786, 27663,   137,  3877, 10798, 23923, 18411,  1686,
    666, 15086,  2186, 31758,  1394, 32467, 12646, 12969,   538, 16754,
    3049,  2717, 46858,  1378, 16121,  5499,   663,  3006, 12174, 13505,
    1039, 10275, 19763,  4129,  1894, 15803,  3035, 37358, 32070, 25318,
    6549, 27201,  2993, 10818,  2367, 13883, 45914,   945,  8641, 19435,
    2709, 12727,   161,  6649,  1737,  3917, 24139, 12370, 10559,  3838,
    8007,  6199,  1659, 28333,  8291,  3079, 23439, 13581,   978, 16010,
    6802,     7, 17749,   947, 14837,  2849,  6797, 10855,  4477,   910,
    7974,  2937, 61419,  9290, 21137,   330,  7390,   267,  1181, 12893,
    577,  3250,  1031, 19353,  1317, 21006, 10001,  2485, 47935,  5153,
    8329, 59487,  1299,   321, 39347,  4303,  4321,  1030, 29395, 12098,
    2817,   247,  9321, 54810,  1979,  2837,  7599, 31778, 24066, 29302,
    329, 18890, 10918, 11982,  4687,  5097, 40687,  4102, 34009,   821,
    7931,  2689,  5378,  6554, 24923,  2429, 33627,  9881,  3809,  5545,
    29531,  4757,  4645,  2670,  2262,  9397,  2797,  2595, 22817,  5057,
    4823,  7465, 23585,  1573, 23447,  1005,    77,  1546, 58829,  3107,
    291,   754,   897,  1783,   246,    13,  2691,  5363,  2962,  8165,
    6903,  3287, 13631, 18523
};

////////////////////////////////////////////////////////////////////////////

#ifdef ONE_TABLE

// The data within this #ifdef is just for fun. It shows the smallest
// single table I found. It can be used with a single hash function based
// on the two indicated multipliers and then covers the whole range from
// 4097 to 2^52. But note that when I use separate tables for each range
// the total space I use for the tables is 202+344+292=838 rather than
// the 870 needed for this single table. And when I have separate tables
// it becomes easy to produce a spin-off version of the code that only
// goes as far as 2^32 but that is especially compact.

static const uint64_t hash_multiplier  = UINT64_C(0x0162f7db9c161952),
                      hash_multiplier1 = UINT64_C(0x447f94b0903d127c);

static std::uint16_t witness[870] =
{   2551,   733,  8644,  2643, 11442,   325,  2272,   617,  5018, 25017,
    9686,  6881, 11086,  9274,  9533,   551,   325,   932,  2225,  3204,
    1343,  1262,   483,  2193,   804,  9649,  2490,   633,  1321,  4357,
    5567, 19670, 24316, 17124, 28036, 18930, 14928, 31005, 26779,  2256,
    1570,  8618,  2089, 11946, 27672,  3557,  4159,   642,  4069,  8029,
    18715, 38220,  2614,  7085, 39902,  1426,    11,  4438, 12359,  7810,
    2737,  2606, 18636,  6058,  1982,   788,  3107,   592,  3519,  1322,
    739,   594, 12879,   770,  1609,  2057,  4376,   249,  1980,  1337,
    6878,    99,   224,  8193,  6167,  2531,  1809,  2539, 14963,   818,
    13630, 10580,  3545,  1106, 22909,  3748, 30497,  4541,  2296,   565,
    5216,   901,  2237,  5395,  2861,  7977, 12435,  3227,  7975, 10341,
    5644, 40505,  7521,  9536,  4920,  4257,  8805,  5141,  2235,   952,
    4871,  5642,  2353,  8767,  1792,  1127,   881,   281,  2903, 14747,
    6361,  6096, 13000,   231,   309,   964,  9621,  6263, 13869,  1743,
    37399, 19357, 43167,   647,  2220, 11038,  4461,  3353,  8648, 11301,
    1397,  2499, 13256,  9726, 14444,  4276,  1187, 45245,  2783,  2056,
    2446,  7766,  8484,  3619,  8932,   303,   172,  1854,  5433,  5191,
    2013, 29388,  4350,  4695,  5514,  6554,  2774, 17474,  1641,   501,
    1438, 21634,  1333,  1759,    99,  1914,  6206,   819,  3838,  5117,
    522,   530, 16137,  4092,   698,  4544,  2618,  4907,   515,  3450,
    4184,  1619,  1956, 15146,  1417, 19929,  6442, 10245, 12733, 22571,
    10719,  2035, 19805,   987,  1411,   869,  9383,  4323,   103,  2027,
    36199,  1853,  5634,  5555,   573,  6551,  2453,   542, 17647,  5053,
    6929,   983,  1746,  3687,   327,   985,   869,  1094, 18574,  6732,
    1439,  5789,  1107,  2258,   262, 10653, 10213,  6331,  5426,  4254,
    95, 34871,  3349,   873, 14033, 13236,  2696,  1818,  2638, 21578,
    948,   619,   591,  6792,  1774,  3879, 31771,  1289,  1537,  1401,
    15358,  4429,    43,  7676,   291, 17977,  2026,  3033, 13277,  1204,
    9172, 39818,  1595,   906, 12452, 63488,  1619,   208,   838,  2145,
    1799,   409,  1329,  8609, 13535, 16173, 16526,  5578,  2284, 21521,
    2263,  1420,   130,  2772,  2841,   950,  8143, 13324,  1525, 48791,
    692,   419,   657, 11855,  2746,  4576,  1641, 18293,  6392,  4381,
    1691,  1463,  5600,   678,   559,  1204,  9467,  1455, 13255, 17173,
    6684,  7694,  2343,  3493,  3460,  1253,  4728,  6593,  1179,  5710,
    552, 21348,  2791,  1171,  1890,  4248,  3023,  6506,  2348, 19769,
    3529,  6025, 28240,  1607,  3113,   658,  1188,   179,  9671,   439,
    719, 15735, 16409,  1450,   769,   259,  8319, 10485,   952, 37668,
    995,   382, 13979,  4318,  2493,  1594,  2824,  6386, 28454,  1231,
    6097,  2477,  4420,  1203,   905, 10397,  1241,  9179,  1213,  3611,
    549, 19876,  7066,  1370,  2177, 13185,  8070,  3018,  1335,  3521,
    3290, 10198,  1672, 12108,   258, 23126,  2045,  6066,   377,  1460,
    15632,  4044, 19733,  4456,  6182, 14881, 10663, 10303,   738,  2801,
    29842, 20792,  7182,  1870,  2490,  2463,   211,  2222,   346,    71,
    849,   898,    44,  1477,  9571, 17824,  7937,  3730,   983,  1503,
    45313, 12887, 13075,  3811, 41653, 38611,  2248, 10435, 31416,  1932,
    2112,  3682,  6363, 27054, 36086,  4181,  2828,   787,  2425,  2993,
    1928, 20600,  9374,  3611, 14962,  3958,    53,  7133,  6932,  1308,
    5866,  1592, 12238, 17471,  1771,  2339, 14739,  4941,   406,   858,
    3102,  9656,  2561,  8156,  4443, 10099,  1341,  8584,  1179,  2073,
    4113,  1338,  1035,  1108,  8074,   117,  7344,  3455,  8530,  5825,
    73,  6611,   263,  2463,  3567,  7558,  2077,   982,  5770,  1221,
    1034,  2720, 14910,  2078,  1248, 22009,  4010,  1935,  6644,  2416,
    5788,  9742,   165, 13579, 18329,   202,  7176, 36216,   185,  4081,
    1405,  4123,   227,  1511, 10608,  1032,  3469, 19645, 13178, 11859,
    5195,   801, 14078, 16623,  1597, 13154, 17821,  4621,    58, 30247,
    1782,  1451,  6530,  3246,  2997,  2314,  1204,  8526, 24145,  2164,
    3032,   655, 10403,   888,   167,  9102, 13300,  2011,  9598,  2307,
    21761,  3446,  7325,   730,  3939,   489, 45037,  1216, 65496, 15946,
    1473, 11542, 19958, 13853, 28434, 19016,   414, 10434, 10126,  6734,
    1721,   561,  6726,  8467,  1841,   803,  1503,   528,   469,  5830,
    19182,  1046, 31865,  1247, 20419, 19545,   258,  3909, 34900,  1171,
    657, 21899,  2188,   333,  1630,  1562,  2834,  1302, 11153,   859,
    23688,  5150, 11612,  1253,  3171, 10221,   253,   631,  5368,   206,
    7427,   287, 56217,  2099, 11383,   405, 12182,  1159, 45931,  5983,
    651,   122,  1018,   414,  9027,   499,  6115,  6458,  1263,  4789,
    10383,  1587,  2617,  6443,  8188,  9281,  1404, 46214,  4070,  9691,
    1255,  2129, 19795,  1848,  1313,  7711,   589,  6139,  5524,  6100,
    1426,   858, 13984,  8922,   852,   852,  1542,  8150,  3169,  4788,
    1870,  6389, 10805,  7456,  1736,  4767,  4518,   943, 16398, 11008,
    1154,  3067, 12363,   260,  8173,   326, 30735, 10281,  9151,  3938,
    1677,  6988,  9337,  5440,  2233, 17823, 13523, 17389,  4141,  4340,
    6081, 13955,  1237,  1446,  6173, 32693,  5179,  9690,   926, 13567,
    6334,   678,  1905,  1952, 21325, 10425,  4952,  1438,   122,  6393,
    7193,   438,  3294,  2066,  1585,  1013,   424,  4127,   436,   239,
    1657,  3237,  7484, 14379,   597,   185, 17638,  7389, 35118,  3330,
    1635,  2716, 30437,  3207,  3222, 28191, 33467,   461,  7669,  1069,
    2854,  3046,  1443,   422,   843, 47986,   934,  1241,  4976, 12477,
    2308,   209,  1179,  6773,  3883,   417,   759,  6043,  4651, 27877,
    8939,  4934,   588,  9502,  4885,  1602,  3945, 26039, 23395,  4992,
    9796,  1023,  1573,  4597,  2033,  1614,  2995,   851, 17766,   198,
    2866,   893,    51,  1686,  1332,  1153,  5361,  1867, 25096, 10479,
    1193,  1585,  3790,   636,  5763,   247,  1040,  6166,  2207, 32164,
    248,  1227,  5031,  2269, 12983,   469,   706,  1864,  7945,    86,
    1921,  1330, 10861,  9564,  5089,  1971,   839,  1308,  8368, 29949,
    35421,   531,  7403,  5047,   204, 16780,  9341,   191,  6908,  1076,
    4620,  2580, 18539,  2941, 14852,   927,   794,  2032,  2056,  4546,
    15310,   182,  4305, 19098,  7473,   223,   681,  1341,  2697,  9334
};

#endif // ONE_TABLE

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
    if ((n & 0x00000000FFFFFFFFU) == 0)
    {   w = w +32;
        n = n >>32;
    }
    if ((n & 0x000000000000FFFFU) == 0)
    {   w = w +16;
        n = n >>16;
    }
    if ((n & 0x00000000000000FFU) == 0)
    {   w = w + 8;
        n = n >> 8;
    }
    if ((n & 0x000000000000000FU) == 0)
    {   w = w + 4;
        n = n >> 4;
    }
    if ((n & 0x0000000000000003U) == 0)
    {   w = w + 2;
        n = n >> 2;
    }
    if ((n & 0x0000000000000001U) == 0)
    {   w = w + 1;
    }
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
{   int64_t d;
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
           (d != 21 || !is_perfect_square(c)))
    {   if (d > 0) d = -d - 2;
        else d = -d + 2;
    }
    if (trace_primep)
        std::printf("Test %" D " using D=%" D ", j=%d\n",
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
    if (trace_primep)  std::printf("will use P=1, Q=%" P "\n", q);
// Another cheap test for easy cases that could detect c being composite, and
// where c > 2^24 and d having been found by checking in an arithmetic
// progression means I can not have q prime and q = c.
    if (gcdn(c, q) != 1) return false;
    k = c + 1;
    if (k == 0) return
            false; // Overflow, but 0xffffffffffffffff is composite.
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
                std::printf("%" D ":  "
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
        std::printf("k=%" P " uses %d bits and has %d trailing zeros\n",
                    k, l+1, ll);
// I will first do the part of the Lucas sequence up to where it will have
// used up all the nonzero bits in the representation of k. kk will track how
// far I have gone, and is only needed for trace output but tracking it is
// cheap.
    kk = 1;
    if (trace_primep)
        std::printf("1:     [1, 1]\n"); // Always the start-line!
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
            std::printf("%" P ": [%" P ", %" P "] q^k=%" P "\n",
                        kk, u, v, qk);
        if (trace_primep)
            std::printf("(A) l=%d ll=%d k=%" P " logbit=%s\n",
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
                std::printf("%" P ": [%" P ", %" P "] q^k=%" P "\n",
                            kk, u, v, qk);
        }
    }
// From now on I will only do doubling operations, and they are of the form
//      u = u*v;
// so if u is zero now I can be certain that it will be at the end, and the
// Regular (as distinct from Strong) Lucas test will be passed.
    if (u == 0)
    {   if (trace_primep) std::printf("u=0 so value is probably prime\n");
        return true; // Probably prime!
    }
// Now all the rest of the Lucas sequence is done using just the "doubling"
// process. But I am no longer interested in u.
    if (trace_primep)
    {   std::printf("After final non-doubling step u = %" P "\n", u);
        std::printf("Will just do doubling steps from now on...\n");
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
            std::printf("%" P ": [?, %" P "] qk=%" P "\n",
                        kk, v, qk);
        if (trace_primep)
            std::printf("(B) l=%d ll=%d k=%" P " logbit=%s\n",
                        l, ll, k, logbitp(l, k) ? "t" : "nil");
    }
    if (trace_primep)
        std::printf("exit loop with l = %d and v = %" P "\n", l, v);
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
    for (uint64_t i=3;; i+=2)
    {   int f;
        for (f=3; f*f<=i; f+=2)
            if (i%f == 0) break;
        if (f*f > i) continue; // i is a prime;
        if (lucas_test(i))
        {   std::printf("%" P "\n", i);
            if (++npseudos > 20) break;
        }
    }
    std::printf("testing complete\n");
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
