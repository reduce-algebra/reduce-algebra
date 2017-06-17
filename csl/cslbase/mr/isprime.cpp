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

static const uint64_t hash_multiplier = UINT64_C(0x8bd03fd5cb49666b);

static uint16_t witness[216] =
{   17490,  5756,  7143, 10476, 13223,  5143, 54949, 46324, 11327, 21776, 
       14, 11348,  1837, 11945, 17130,   814, 24668, 27778, 29292, 12320, 
    27999, 24665,   217,  2136,   370, 15513, 11577, 11464,  9734,  5117, 
     4796, 11231,  1760,  9541, 13930,  1807, 10976, 11212, 46077, 10885, 
    13981,   148,   415,  4031, 26689,  9236,  2257, 14300,   183,  6148, 
    31088,  7970,  6283,   556,  2674,  6442,  3501, 17049, 20938, 44337, 
     7812,  4627, 21294,  6768,  5134, 40093,  4662,   774, 12178, 10453, 
    16975, 20017,  3405, 32346, 11745,   294, 14936, 20713,  3371, 13471, 
     3728,  4090, 40339, 57759, 22007,  1115, 24211, 10564, 13850, 11754, 
     2278,  5745, 16753, 51913, 13076,  1160,  2581, 13858, 13147,  1072, 
    44224,  5022,  1417, 19493, 39737,  6276,  6792,  4207,  6345, 40285, 
    23786, 51941,  4542,  3302,  9249,  6428, 35246,  4981,  9628,  9231, 
    23685, 15481,  2335, 34333, 27605, 11926,  6602,  6167,  2161,  6073, 
    10601,  4248, 46263,  2678,  6247,  8332,  5569,  4439, 50964,  2326, 
    17596,  1511, 43893, 11640,  2691, 40811,  4676, 32329,  3214, 18961, 
     9118,  3713, 41097,  4067,  9690,  8901,  3074,    67,  3153,   985, 
    33378,  8698, 16533, 41199, 47465, 47912, 21939, 21286,   652, 21348, 
    12998,  3723,  1294,  8768,  7897, 60772,  9880, 25647,  5644,  1481, 
    16626,  1608, 16379, 25558,   176,  5553, 17031,  9330,  6323,  2764, 
     5798,  4108,  6234, 51499, 19125,  1845, 22910,  9111,  5817, 55318, 
     2221,  7784, 13964, 46759,  3442, 14692,  6748,  6657,  7293,  1576, 
      330, 27166,  1625, 10388, 16052,  6421
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

