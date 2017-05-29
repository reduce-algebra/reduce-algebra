// isprime.cpp                                Copyright (C) 2017 A C Norman

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

static const uint64_t hash_multiplier = UINT64_C(0x57414e1483828f10);

static uint16_t witness[217] =
{   11357,  4067, 12485, 38163, 17202,  6958, 20701, 28093,  6779, 10085, 
     3581,  1324,  8856, 26620,   470,   749,  8148,  2707, 14683, 15646, 
     7293, 31232,  8880,  6765, 61671, 25374, 44051, 12171,  1443, 20280, 
    18700,   895, 26314,  5189,  7839,  4606,  1564,  2091, 20932,  4801, 
    19804, 55816,   287, 25816, 45850,  5533,  2363, 25864,  4618,  8782, 
      222, 14424,   452,  6934,  5411,  7428,  2822,   313, 43755, 10874, 
     6014,  4389,  2855,  3002,   354,  2873, 17577, 14597,  8555, 18105, 
      161, 19844, 44435, 35508,  2041,  1503,   478, 13142,  8368,  8924, 
    11926,  1656, 17247,  3895,  3110, 35508, 39701,  2738,  1949,  1093, 
    35074,  1612,  5220,  6537, 24605,  8437, 24586, 10525, 15637, 11252, 
     9671,  4426, 52404,  1119,  3062,  3491,  2516, 27688, 15599,  1897, 
     5936,  9808, 27917,  5310, 59006,  1597,  4305, 19142, 46234, 10874, 
    11116, 62850, 28063,  9156,  7124,  1356,  1794,  2307, 30429,  2471, 
    28526,  4807,  2429,  1202, 38548,  3023, 14720,  4471, 56738, 59815, 
    41006, 13713, 17565,  4178, 21773, 25692, 26380, 20156,  7378,  2597, 
     2873,  9525,  4000, 53741,   394, 20035, 56865,  1221, 10073, 24034, 
    36959, 13311,  2035,   132,  5201, 16555,  3511,  3243, 17391, 36515, 
     9668, 51259, 16648,  9995,  9428,  2410, 35296,  6420,  5162,  7475, 
     1317,  5587,   801, 40185,  2874,  6385, 44152,  8012, 10939,  6650, 
    12643,  6342,   295,  6060,  1450, 39172,  2723, 20092,  3551, 19137, 
     1614,  6073,   631,  8344, 23156,  3784,  4462,  6792,  3697,  3867, 
    28429, 55023, 10542,  2045, 10436, 42107, 18198
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

// end of isprime.cpp

