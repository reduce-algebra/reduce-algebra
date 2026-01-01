// isprime.h                                  Copyright (C) A C Norman 2025

/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

#ifndef header_isprime
#define header_isprime

// It provides a function "bool constexpr_isprime(uint64_t n)" that tests
// if n is a prime number and that can be used at compile-time.

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

namespace CSL_LISP
{

///////////////////////////////////////////////////////////////////////////


// I need an auxiliary function to find the top bit in a word.

constexpr inline int constexpr_nlz(uint32_t x)
{   int n = 0;
    if (x <= 0x0000FFFFU)
    {   n = n + 16;
        x = x << 16;
    }
    if (x <= 0x00FFFFFFU)
    {   n = n + 8;
        x = x << 8;
    }
    if (x <= 0x0FFFFFFFU)
    {   n = n + 4;
        x = x << 4;
    }
    if (x <= 0x3FFFFFFFU)
    {   n = n + 2;
        x = x << 2;
    }
    if (x <= 0x7FFFFFFFU)
    {   n = n + 1;
    }
    return n;
}

// Code that implements Miller-Rabin.

// Compute x^n mod p

constexpr inline uint32_t constexpr_exptmod(uint32_t x, uint32_t n, uint32_t p)
{   uint64_t xx = x, y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = (xx * y) % p;
        xx = (xx * xx) % p;
        n = n / 2;
    }
    return (xx * y) % p;
}

constexpr inline bool constexpr_isprime(uint64_t n)
{   if (n <= 7) return true; // All udd numbers up to 7 are prime!
    if (n%3 == 0) return false;
// Here 3 is an adequate witness!!!! Well actually just a simple
// Fermat test suffices and it is slightly simpler so I use it.
// This is because the I am only checking a few numbers that are all
// just a bit below powers of 3 and it turns out that none of the ones
// I come across are pseudoprimes to base 3. Far less Carmichael numbers.
    return (constexpr_exptmod(3, n-1, n) == 1);
}

constexpr inline auto goodPrime(int n)
{   uint32_t p = (1UL<<n) - 1;
    while (!constexpr_isprime(p)) p -= 2;
    return p;
}

// Here is a table whose entries are all primes selected as the
// largest prime less than powers of 3. They can be useful as the sizes
// for hash tables. I then provide functions that, given one of the
// primes from here, returns the previous or next. Those functions are
// intended to help when hash tables need to shrink or grow.
// The table starts off with:
// 0, 1, 3, 7, 13, 31, 61, 127, 251, 509, 1021, 2039, 4093, ...
// and continues up to values that are in fact ridiculously larger
// than I could ever use, ie up to almost 2^31 which would support
// billions of symbols and the table size plus the size of those
// symbols would stretch many 2025 computers.

#ifdef DEFINE_GOODPRIMES

constexpr inline uint64_t goodPrimes[32] =
{   goodPrime( 0), goodPrime( 1), goodPrime( 2), goodPrime( 3),
    goodPrime( 4), goodPrime( 5), goodPrime( 6), goodPrime( 7),
    goodPrime( 8), goodPrime( 9), goodPrime(10), goodPrime(11),
    goodPrime(12), goodPrime(13), goodPrime(14), goodPrime(15),
    goodPrime(16), goodPrime(17), goodPrime(18), goodPrime(19),
    goodPrime(20), goodPrime(21), goodPrime(22), goodPrime(23),
    goodPrime(24), goodPrime(25), goodPrime(26), goodPrime(27),
    goodPrime(28), goodPrime(29), goodPrime(30), goodPrime(31)
};

#else // DEFINE_GOODPRIMES
extern uint64_t goodPrimes[32];
#endif // DEFINE_GOODPRIMES

constexpr inline unsigned int goodPrimesCount =
    sizeof(goodPrimes)/sizeof(goodPrimes[0]);

inline int primeIndex(uint32_t x)
{   return 32 - constexpr_nlz(x);
}

// These two functions ought only to be called with one of my
// "good" primes as an argument. Because these are just under a power of
// 2 I can identify which one I have by counting the leading zeros in its
// representation. 

inline uint64_t previousGoodPrime(uint64_t p)
{   return p == goodPrimes[0] ? p : goodPrimes[primeIndex(p)-1];
}

inline uint64_t nextGoodPrime(uint64_t p)
{   return p == goodPrimes[goodPrimesCount-1] ? p :
                           goodPrimes[primeIndex(p)+1];
}

} // end namespace

#endif // header_isprime

// end of isprime.h
