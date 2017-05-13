// isprime.c                                  Copyright (C) 2017 A C Norman

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

#include <stdint.h>

// The function mulmod(a, b, n) computes a*b mod n where a, b and n are
// all unsigned 32-bit integers. As coded here it does the multiplication
// and remainder steps using 64-bit arithmetic so as to avoid overflow.
// With a good compiler this is expected to generate code that would be
// hard to improve on. The function is "inline" to avoid call overhead
// while preserving a tidy abstract presentation.

static inline uint32_t mulmod(uint32_t a, uint32_t b, uint32_t n)
{   return (uint32_t)(((uint64_t)a*(uint64_t)b) % n);
}

// Compute x^n mod p

static inline uint32_t exptmod(uint32_t x, uint32_t n, uint32_t p)
{   uint32_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = mulmod(x, y, p);
        x = mulmod(x, x, p);
        n = n / 2;
    }
    return mulmod(x, y, p);
}

// Use Miller-Rabin with base a to check whether n is a (pseudo-)prime. The
// way this is used here should ensure that it is in fact 100% reliable in
// identifying primes. If this was used in a probabilistic context then this
// function would be called repeatedly with random first arguments. In my
// use if is called with carefully selected first arguments so as to avoid
// strong pseudo-primes.

static inline bool miller_rabin_isprime(uint32_t a, uint32_t n)
{   uint32_t d = n-1;
    int s = 0;
    while ((d % 2) == 0)  // Find largest power of 2 dividing n-1
    {   d = d/2;
        ++s;
    }
    uint32_t x = exptmod(a, d, n);
    if (x == 1 || x == n-1) return true;
    while (s > 1)
    {   x = mulmod(x, x, n);
        if (x == 1) return false;
        else if (x == n-1) return true;
        --s;
    }
    return false;
}

// The next section is pasted in from the output from hash.cpp

static const uint64_t hash_multiplier = UINT64_C(0x42d05aac70a4aa77);

static uint16_t witness[218] =
{   23034, 37043, 23021, 32936,  2779,  1864,  6534,  9421,  1184,   518, 
    21703, 29411,  1770,  5739, 11214,  1098,  6430, 40301,  7409, 23271, 
    16971,  3991, 51098,  9342, 53482, 25517, 17964,  5031, 19460,  5175, 
      408,  1272, 51835,  3325,  9815,  6553,  3296,  1893,  1436, 12495, 
     3070, 46986, 22714,   942,  3924,  2760,  3807,  6583, 25386, 14138, 
       68, 27644, 16145,  2212, 35000,  3337, 15557, 17369, 27754, 29918, 
      671, 11191, 29760,  5593,  5927, 23954, 50781, 10856, 13497, 18798, 
     9533,  7318, 12906,  2350,   741,  3503,  5968,  1069, 12756, 17218, 
    22506,  7582,  4267,  7166,  7305,  1778, 13845, 21032,   813, 10158, 
    18088, 17891,  5309,  1980,  3469, 20763, 13964,  1978, 54068,    42, 
    26722, 58162,  2586, 55464, 27468, 26907,  4154,  3166,   194, 16206, 
    41606, 11989, 17445, 15703, 17651, 15084, 21391,   511,  1453, 19874, 
    34803,  5236,  8468,  9473, 24706, 22849, 30529,  4251, 40743, 15783, 
     3047,  3101, 22919, 38383,  5404, 12464,  2033,  5881,  1457, 12484, 
    21196,   679, 12079,  7754, 25352,  8608, 12221,  2020,  5603, 27705, 
      926, 12542, 13402,  6305, 31325,  9371, 20026,   575, 65250, 17346, 
     2332,  6722, 16868, 11934, 12655, 10774,  2785, 50648,  4462, 21053, 
    24472, 26197,  2109, 11909, 36842,  2139, 18593, 25154, 26768,  3028, 
    10749, 12358, 41384,   522,  2898, 12627, 27189,  2856,  2409, 47975, 
    13454,  2828, 63383,  6415,  6584, 42795, 40662, 25209,  2945,  4430, 
    23242,   381, 15501,  3446, 17216,  1066, 39710, 56616, 61451, 48127, 
     1622, 20022, 61701, 20247,  7951,  1478, 19437, 26952
};

// end of copied material.

// My hash function maps a 32-bit unsigned integer onto an index into the
// above table such that the table will give a witness that allows for
// reliable prime-checking of the integer. The basic idea is that
//       hash(b) = (multiplier*p) % tablesize
// where the multiplication is computed modulo 2^64. This should be cheap to
// compute and I have 2^64 possible multipliers to choose between to find
// a scheme that distributes values well. The extra shift right discard the
// low bits of the product, which are liable to only depend on low bits of the
// input and the multiplier. It is not clear that I need it, but I introduced
// it at a time I was concerned about even table sizes and the effect that
/// has on hashing - and because it is really rather cheap.

static inline unsigned int hash_function(uint32_t p)
{   return (unsigned int)
        ((hash_multiplier*(uint64_t)p)>>31) %
        (sizeof(witness)/sizeof(witness[0]));
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

// This is the function that a user might call to test for primality.

bool isprime(uint32_t n)
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
// Now I use hashing and my table to select a witness that will cause
// Miller-Rabin to deliver a fully reliable result.
    return miller_rabin_isprime(witness[hash_function(n)], n);
}

// end of isprime.c

