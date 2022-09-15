// isprime.h                                  Copyright (C) A C Norman 2022

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

///////////////////////////////////////////////////////////////////////////


// Given a, b and c as 64-bit unnsigned values with c!=0, compute (a*b)%c.
// The issue here is that the intermediate product a*b can use up to
// 128-bits.
// The division/remainder method used here is the one from Warren's book
// "Hacker's Delight" which in turn derives it by specialising and further
// optimising the scheme from Knuth's Art of Computer Programming volume 2.
//
// I need an auxilliary function to find the yop bit in a word.

constexpr inline int constexpr_nlz(uint64_t x)
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


constexpr inline uint64_t constexpr_mulmod64(uint64_t a, uint64_t b, uint64_t c)
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
// I must always initialise every variable that I declare in a constexpr
// function.
    int s = constexpr_nlz(c);        // Shift amount for norm. 0 <= s <= 63.
    c = c << s;                      // Normalize divisor.
    uint64_t vn1 = c >> 32;          // Break divisor up into
    uint64_t vn0 = c & 0xFFFFFFFFU;  // two 32-bit digits.
    uint64_t un32=0;
    if (s == 0) un32 = u1;
    else un32 = (u1 << s) | (u0 >> (64 - s));
    uint64_t un10 = u0 << s;           // Shift dividend left.
    uint64_t un1 = un10 >> 32;         // Break right half of
    uint64_t un0 = un10 & 0xFFFFFFFFU; // dividend into two digits.
    uint64_t q1 = un32/vn1;            // Compute the first
    uint64_t rhat = un32 - q1*vn1;     // quotient digit, q1.
    while (true)
    {   if (q1 >= base || q1*vn0 > base*rhat + un1)
        {   q1 = q1 - 1;
            rhat = rhat + vn1;
            if (rhat < base) continue;
        }
        break;
    }
    uint64_t un21 = un32*base + un1 - q1*c;  // Multiply and subtract.
    uint64_t q0 = un21/vn1;            // Compute the second
    rhat = un21 - q0*vn1;     // quotient digit, q0.
    while (true)
    {   if (q0 >= base || q0*vn0 > base*rhat + un0)
        {   q0 = q0 - 1;
            rhat = rhat + vn1;
            if (rhat < base) continue;
        }
        break;
    }
    return (un21*base + un0 - q0*c) >> s;     // return the remainder.
}

// Now code that implements Miller-Rabin.

// Compute x^n mod p

constexpr inline uint64_t constexpr_exptmod(uint64_t x, uint64_t n, uint64_t p)
{   uint64_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = constexpr_mulmod64(x, y, p);
        x = constexpr_mulmod64(x, x, p);
        n = n / 2;
    }
    return constexpr_mulmod64(x, y, p);
}

// Use Miller-Rabin with base a to check whether n is a (pseudo-)prime. The
// way this is used here should ensure that it is in fact 100% reliable in
// identifying primes. If this was used in a probabilistic context then this
// function would be called repeatedly with random first arguments. In my
// use if is called with selected first arguments so as to avoid
// strong pseudo-primes for all inputs up to 2^64

constexpr inline bool constexpr_miller_rabin_isprime(uint64_t a, uint64_t n)
{   uint64_t d = n-1;
    int s = 0;
    while ((d % 2) == 0)  // Find largest power of 2 dividing n-1
    {   d = d/2;
        ++s;
    }
    uint64_t x = constexpr_exptmod(a, d, n);
    if (x == 1 || x == n-1) return true;
    while (s > 1)
    {   x = constexpr_mulmod64(x, x, n);
        if (x == 1) return false;
        else if (x == n-1) return true;
        --s;
    }
    return false;
}

constexpr inline bool constexpr_isprime(uint64_t n)
{   if (n <= 1000)
    {   for (int k=2; k*k<=n; k++)
        {   if (n%k == 0) return false;
        }
        return true;
    }
// Note I must not use a witness that is equal to the value that I am
// testing, so I have checked small numbers the traditional way first.
    else if (!constexpr_miller_rabin_isprime(2, n)) return false;
#if 0
    else if (!constexpr_miller_rabin_isprime(3, n)) return false;
    else if (!constexpr_miller_rabin_isprime(5, n)) return false;
    else if (!constexpr_miller_rabin_isprime(7, n)) return false;
    else if (!constexpr_miller_rabin_isprime(11, n)) return false;
    else if (!constexpr_miller_rabin_isprime(13, n)) return false;
    else if (!constexpr_miller_rabin_isprime(17, n)) return false;
    else if (!constexpr_miller_rabin_isprime(19, n)) return false;
    else if (!constexpr_miller_rabin_isprime(23, n)) return false;
    else if (!constexpr_miller_rabin_isprime(29, n)) return false;
    else if (!constexpr_miller_rabin_isprime(31, n)) return false;
    else if (!constexpr_miller_rabin_isprime(37, n)) return false;
#endif
    else return true;
}

constexpr inline auto goodPrime(int n)
{   uint64_t p = (static_cast<uint64_t>(1)<<n) - 1;
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
// than I could ever use:
//     ... 281474976710597, 562949953421231, 1125899906842597.
// Of course I am aware that the first couple of entries are not
// useful. I include them because they are what emerges from the
// code that sets the table up.

constexpr inline uint64_t goodPrimes[] =
{   goodPrime( 0), goodPrime( 1), goodPrime( 2), goodPrime( 3),
    goodPrime( 4), goodPrime( 5), goodPrime( 6), goodPrime( 7),
    goodPrime( 8), goodPrime( 9), goodPrime(10), goodPrime(11),
    goodPrime(12), goodPrime(13), goodPrime(14), goodPrime(15),
    goodPrime(16), goodPrime(17), goodPrime(18), goodPrime(19),
    goodPrime(20), goodPrime(21), goodPrime(22), goodPrime(23),
    goodPrime(24), goodPrime(25), goodPrime(26), goodPrime(27),
    goodPrime(28), goodPrime(29), goodPrime(30), goodPrime(31)
#ifndef __clang__
// g++ copes with plenty of compile-time comoutation without fuss, but
// clang (on the Mac at least) has an embedded limit on the number of steps
// it is prepared to use in compile-time (meta) computation, and that
// causes big pain here! I have tried finding a compiler option that
// overrides its limit but so far without success.
    ,
    goodPrime(32), goodPrime(33), goodPrime(34), goodPrime(35),
    goodPrime(36), goodPrime(37), goodPrime(38), goodPrime(39),
    goodPrime(40), goodPrime(41), goodPrime(42), goodPrime(43),
    goodPrime(44), goodPrime(45), goodPrime(46), goodPrime(47),
    goodPrime(48), goodPrime(49), goodPrime(50)
#endif
};

constexpr inline unsigned int goodPrimesCount =
    sizeof(goodPrimes)/sizeof(goodPrimes[0]);

#ifdef __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too. So I am expecting that this
// will be the version is use almost all the time, and on several key
// platforms it ought to compile into a single instruction!

inline int inline_nlz(uint64_t x)
{   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
}

#else // __GNUC__

// This fallback is at least properly portable.

inline int inline_nlz(uint64_t x)
{   return constexpr_nlz(x);
}

#endif // __GNUC__

inline int primeIndex(uint64_t x)
{   return 64 - constexpr_nlz(x);
}

// These two functions ought only to be called with one of my
// "good" primes as an argument.

inline uint64_t previousGoodPrime(uint64_t p)
{   return p == goodPrimes[0] ? p : goodPrimes[primeIndex(p)-1];
}

inline uint64_t nextGoodPrime(uint64_t p)
{   return p == goodPrimes[goodPrimesCount-1] ? p :
                           goodPrimes[primeIndex(p)+1];
}

// end of isprime.h
