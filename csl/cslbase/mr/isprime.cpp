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

static const uint64_t hash_multiplier = UINT64_C(0x391fac27820c50f3);

static uint16_t witness[220] =
{   24097, 23740,  2458, 23679,  5745, 32040,  6421, 12726, 18572,   335,
     8926,    29,   668,  3049, 16476, 22796,  2374, 26247, 29725,  8439,
     1897,   462, 13423, 21697,  8853, 57113, 51184, 10185, 20913, 27187,
      811,  2320,   670, 18044,  6695,  2849,  4433, 16574, 23929,  4901,
     1293, 38851, 23664, 20739, 18737, 11675,   276, 16436,  3287,  7848,
    17843,  1074,   738,  6313,  6674,  4560, 32923,  2873, 63817, 11844,
    14775,  2284,  2899,   487,  1198, 26161, 18465,  3640,  3318, 23542,
    44992,  5813, 14934, 20269,  4146, 26686, 28655, 12868, 11866,   198,
    12937, 13014,  3982,  9433,  7187, 24936,   306,  9631, 16950,  5816,
     1921,  4237,  9014,  3994,  4806, 10319,  7695,   219,   471,  2227,
    12635, 27138, 23664, 27545, 15519,  9518, 33316,  1240, 15372, 15568,
    12986, 19375,  3678,  6571, 15142, 25835, 14676,  1477,  8819, 43564,
     1138,  7126, 46458, 14793,  4475,  4576,  8901,  9976, 14099, 11413,
     1094, 14639, 10567, 15823,  1257,  9557, 15416,  5609,  2943,  3226,
    52813,  4179,  3277, 33705, 13876,   629,  5727, 15431,  1273,  2618,
      569, 10762,  1492,  3223,  1497, 17271, 12862, 15003,  2891,   531,
     7609, 25999, 38545, 30385,  6789, 36657, 12057,  2416,  5228,  1337,
    45667, 50408,  6397, 22013, 13481,  9633, 27613,  1059,  7291, 17207,
     2546, 25228, 28912, 17043,  1647, 10917,  3541, 20813,  4974, 13639,
    50875,  4891,  7856,  4410, 22045, 43824,  4067,  7830, 36932, 13118,
     7144, 21646,  3641,  7261, 57926, 11020,   159,  2458, 13783,  1861,
      747, 28294, 37358, 31378,  8268,  7245, 34590, 29322,  1271, 14500
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
// The next line checks for divisibility by 2, 3 and 7.
    if ((UINT64_C(0x000001df5d75d7dd) & (UINT64_C(1)<<(n%42U))) != 0)
        return (n==2) || (n==3) || (n==7);
// ... and this one copes with 5 and 11.
    if ((UINT64_C(0x0004310a42508c21) & (UINT64_C(1)<<(n%55U))) != 0)
        return (n==5) || (n==11);
// If there are no factors of 2,3,5,7 or 11 then any number left (apart from
// the special case 1) up to 13*13 must be a prime.
    if (n < 169) return (n!=1);
// Now I use hashing and my table to select a witness that will cause
// Miller-Rabin to deliver a fully reliable result.
    return miller_rabin_isprime(witness[hash_function(n)], n);
}

// end of isprime.c

