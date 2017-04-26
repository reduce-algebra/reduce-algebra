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

// The next section is pasted in from the output from hash4.c

static const uint64_t hash_multiplier = UINT64_C(0x868b01cd82a78e5f);

static uint16_t witness[225] =
{    3008, 49948, 12233,  7093, 21445,  6147, 15325,  3129,   771,  2096,
    18117,  6730, 16995,  7540,  2334, 23126,  1970,  5749,  3479,  7483,
    30586, 10811,  6697, 31219, 26128,  6443, 13750,  1134, 11739, 54532,
    27495, 16604,  4740, 20360, 25521, 64660, 22625,  4178,  7472, 31392,
     5062,  1065, 41070,  8828,  1070,  5487, 20346,  4877,   701,  3957,
    11745,  8527,  6505,  1063, 33187, 17507,   898,  9284,  8799, 10352,
    35076, 31159,  4154,  5744, 45476, 24208, 20475,  1387, 24960, 15656,
      819, 19405, 28585, 19771,  2935,  3851,  1894, 13684,   789,  4773,
    15648,  8910, 14241,   527, 28724,  1447,   713, 25916, 18772,  1098,
     4239,  4664, 24185, 12239, 42085,  2246, 10599,  4921,  7199, 38090,
    32014,  4425, 18294, 12131,  6095,   406,  4921, 10379, 44820, 21344,
    10267, 14960, 14269,  8689,  2903, 36047, 10749,   810,  3695, 31858,
    26793,  2941, 16636,  3743,  1909,  9434,   690, 53301,  7839, 15600,
     5695,  4700, 18672, 60846,  9164,  6614,  3398,   570,  1567,  7232,
      566,  6509, 17270, 10927, 11537,  2033, 25472, 30378,  3827,  1074,
      357, 26202,  4064,  3287,  1964,   679,  1573,  6957, 20907, 25658,
     1677, 27929, 58745, 14757, 54584,   539,   152,  4899,  6981, 17360,
     6450,  7204,  4099,  3853,  1839,   328, 14266,  1413, 21492,  3980,
    59251,  6530, 26818,  1505, 20926,  1593, 41688, 23148, 13297,  1431,
    12811,  4935,  1635, 38016,  7996, 40096, 18137, 14919,  3521, 32804,
      711,  6311,  6884, 10778,  1045,  4105, 25928, 41963,  3145,  2919,
     2354, 29087,  6895,  2199,  6515, 33793,   629,   603, 30873,  4937,
    20963,  2222, 20900,  6620, 37036
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
// This is the function that a user might call to test for primality.

bool isprime(uint32_t n)
{
// I will start by filtering out potential very small factors. This
// detects a significant fraction of composites cheaply, and is expected to
// be overall good for average efficiency.
    if ((n % 2) == 0) return n == 2;
    if ((n % 3) == 0) return n == 3;
    if ((n % 5) == 0) return n == 5;
    if ((n % 7) == 0) return n == 7;
// If there are no factors of 2,3,5 or 7 then any number left (apart from
// the special case 1) will be a prime.
    if (n < 121) return n != 1;
// Now I use hashing and my table to select a witness that will cause
// Miller-Rabin to deliver a fully reliable result.
    return miller_rabin_isprime(witness[hash_function(n)], n);
}

// end of isprime.c

