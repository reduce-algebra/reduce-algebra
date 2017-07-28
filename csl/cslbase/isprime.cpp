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

static const uint64_t hash32_multiplier  = UINT64_C(0xece3ce6412e5c07d),
                      hash32_multiplier1 = UINT64_C(0x45bc548c2b93e486);

static uint16_t witness32[200] =
{    455, 28250,   948, 38008, 26536, 36381,  4053, 28067,  4030,  6187, 
   34855, 21015,  9393,   420, 17393,  2296,  1846, 59324,   540,  1169, 
    1543,  9705, 19256, 16604, 25419,  6211,  2976, 26959,  1264,   403, 
    2434,  2112, 36169, 26500, 28008,  2922,  3785,  3387,  3743, 13583, 
   34490, 43914, 14689, 21045,  4561,  8356, 14387, 42257,   686, 18277, 
    3737, 11376,   459,   553,  2377,  7113,  6948, 33386,  5322,  1224, 
   17369,  1731, 48329, 14546,  5025,  8244, 60250, 24474,  2244, 23448, 
    1258, 49561, 25312, 14003,  2522,  4052,  1430,  9135, 47292, 27426, 
   13022, 42079, 27628, 17170,  1732,  2905,  3390, 11633,  5982, 26128, 
    9168,  2585, 30875,  3398,  7802,  2959,   751, 16112, 18406, 25548, 
    1591, 16637, 25217,  3876,  9013,  5627,  7876,   965,  6117, 11409, 
   21337,  8428, 13011,   840,   368,  7802, 26541,  1341,  1091,  6501, 
   27366,  4134,  8543,  4705, 32924, 11403,  3555, 23733,  2647,  8922, 
    5250, 21503, 21321,  2637, 10990,  5634,  2616, 59173, 16737,  6562, 
    6205,  2697, 18405,  4336, 14570,  4589,  1664, 20910, 12179,  3034, 
   28188,  6619,  3646,  9466, 27511,  8396,   603, 13108,   579, 11863, 
   27845, 32597,  3702,  2349,  3744,  6086, 18184,  6970,  6344,  1062, 
   30144,  6113,  3128,  2893, 16570,  5325,  4930, 13370, 53011, 41493, 
     443, 10790,  2360,  1464, 27211, 26739, 63484,  3945,  2540,  5624, 
    9859,  3573,  7910,  8260, 22410,  6142,  2435, 20213,  8582, 16388
};

////////////////////////////////////////////////////////////////////////////

static const uint64_t hash44_multiplier  = UINT64_C(0xc10911c844225361),
                      hash44_multiplier1 = UINT64_C(0x8365d91a966b9aaf);

static uint16_t witness44[340] =
{   1433, 11686,  2531, 21122,  1310,  1101,  4273, 14563,  7215,  3603, 
   13986, 38605,  3007, 11923,  1737, 53879,   678,  6798,   178, 21327, 
   65354,  1147, 12535,   423, 24159,  7131,  2926, 11586, 10975,  5719, 
     862, 60265,  7751, 22247,  5433,   474,  3938, 12374,   525, 24617, 
    6917, 14173,    97, 13162,  2749,   979, 14717,  2990,  7677, 35349, 
    9942,  6953,  7981,  4771, 20169,  6278,   659, 17343,  7919,  8318, 
    3081,  5143, 23739, 10021,  1274,  9719,  1925, 12955,  5373, 19690, 
    1363,  8887,  4582, 10993,  4739,   175,  5993,   701,  1709,  9186, 
   10011,  6009, 32687,  8742, 15187,  1491,  2381,  5643, 14599,  2203, 
    2587, 11150, 16935,  1315,  9590,   683, 13105,   849, 20414,  2119, 
     759, 12522,  1491, 57347,  2475, 16257,  1505,  8063, 23053, 47238, 
     801,  8605,  7379,  1003,  2669, 26381,  5015,   211, 49749, 13074, 
    7033, 11754,  8073, 18431,  1414,  1579,  9559,    77,  1226, 13329, 
   10686,  5725, 44342, 47917,   738, 19151,  8518,  3582,    83,     7, 
    6726,  8231, 27793, 36043,  4123,  5494,  6829,  3065, 30469, 15958, 
    1053,  2765,   949,  2577, 43251,   317,  1019, 15829, 16817, 10847, 
     998, 52759, 32321, 42190,  2534, 16115,  5090,  5105, 22166, 63618, 
    5338,   589,  3510,  7925,  8222,   637,  5247,  2363,   742,   825, 
     269,  9381,  2729,  4603,  3107,  2638, 18434,  3883,  3453, 13402, 
   53403, 21975, 26911, 12318,  5818,   821, 13999,  1098, 60565,  6917, 
    2722,  7129, 17431, 64115, 22015, 20681,  3970,  1086, 28273,   613, 
   28555, 20555, 13194,  6455,   271,  3185, 26949,  3326, 63274,  2925, 
   10381, 16277,   253,   105,  4017,  9858,  6274, 11317, 36905,  1115, 
    5515,  6013,  4445,  8263,  7477,  1955,  1325,   380,  8422,  2631, 
   13806, 54915, 22422, 11214, 16683, 62142,  9731,  1427,  1007, 24854, 
    1929,  4377,  8346,   322,  1274,    43, 14318, 12621,  1562, 42722, 
    1093, 60805,  7887, 16123,  3122,  9175,  5727, 45647,  2294,  1811, 
   52938, 14950,  4229, 20547,  9842, 21303,  6374,  2946, 14487,  1557, 
     329,  2861,   714, 14154, 12454,  7531,  9867,   234,   583, 23358, 
    5423,  5534,  2961,   191,  5598,  5207,   943,  5506,  6650, 42223, 
     542,  1753, 26033, 34065, 13253,  1357, 15702, 11803, 41621,  4469, 
   50089, 17511,  7707, 14042, 25675,  1053, 33170,  1366,  5194,   347, 
   26625, 55874,  1641,  2455,   791,  4401,  4949, 12290, 16371,  1914, 
      15, 29991,  4106,  7355,  3294, 15198,  4817, 27519,  3182,  1554
};

////////////////////////////////////////////////////////////////////////////

static const uint64_t hash52_multiplier  = UINT64_C(0x8defc1cef5c5b972),
                      hash52_multiplier1 = UINT64_C(0x648a316d7c6c4643);

static uint16_t witness52[290] =
{   4905,   502,  1806, 26346,  6961,  1505,  4054,   209, 13979,  1989, 
   14659,  8741, 13774,   253,  5143,  8513,  9105, 13257,  9593,  3123, 
   18421,   778,   237,  3569,  8434, 15709,   645,  2561,  4073,  3579, 
   28121, 13274,  4799, 35203,  7726,  6087, 19335,  4149, 62794,   301, 
   48891, 13346,  1831, 14515, 35822,  4130,  2501, 15157, 14842,   313, 
    2966, 20073,  2650,  3338,  1086,  2591,  1547,  5151,  4270,  1147, 
    2427,  5257, 15643,  2522,  2417,  2622, 27526, 17137, 16935,  8870, 
   12950,  2678,   805,   823, 16273, 37707, 24730,  1397,  6306,   453, 
    7409, 13591, 12103,   145,  1066, 32297,  4537, 56911,  6417,   539, 
    1630,  9247, 12057,  1005,  1727,  9646,  1013,  4310,  5379, 29783, 
   12115, 16822, 42709,  1645, 35853, 16557,  8347,  1183,  1469, 32701, 
     173,  2011, 11063,  1155, 13507,  5130,  1691,  4453,   372,  6686, 
    1711, 56509,  7243,  1482,  3706, 30186,   189, 18878, 34761,  7050, 
    6563, 60219, 62282,  3189,  7691,  1745, 10583,  3926, 11510,   431, 
   25569,  7197,  1189, 24333, 38855,  1025,   118,  7913, 10569, 20841, 
   19562,   891,  2235, 16759, 12593,  7161,  5101,  4747, 14746,   645, 
    3501, 36878,   667,  9045,  3478, 28611,  1195, 16815,  4638,  7197, 
     558,  7950,  6606,   219, 19829,   711,  8099,  6386,   662, 15031, 
    3013,  6190, 16189,   219,  2919, 13143, 16540,  1999,   551, 17587, 
    3523,   515,  1702,  7198,  6837,   390, 15354,  1909,  3314,  1774, 
    3067,  8295,  3977,  1507,  2099,  2715, 26307,  3190,  2385,   210, 
    7893,  1482, 11963,  4294, 46545, 25667,  4495, 13801, 24187, 47222, 
   49875, 20981,   906,  9227, 26550, 57791,  1862,   839,  4383,   691, 
   15874,  1035,  3813,  6311,  4467, 21729,   701,  5693, 19455,  2447, 
   16897,  9442,  7583, 13249,   117,  2939,  5163, 46997,  2173,  7865, 
     374, 14177,  1262,  4693,  8257, 58613,  1005,  6678,  2877, 15086, 
   19805,  1471,  3899,  2673, 22157, 19523,  8071, 42958,  1037,  4499, 
    2235,   117,  3379,  1599,  4441,   482, 55279,   557, 47494,  5487, 
   31809,  1907,  9651,  6501, 28363,   991,  9277,   437,  5905,   347
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

static uint16_t witness[870] =
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
