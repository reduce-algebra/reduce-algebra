// fftutils.cpp                                   Copyright 2025 A C Norman

// $Id$

/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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


#include <cstdint>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <bit>
#include <utility>
#include <algorithm>
#include <vector>
#include <thread>

// This makes 128-bit integers available using either g++ or clang++.
// It is not standard-compliant and even with those compilers it may
// not be available on all computers.

#include "int128_t.h"

// I want to be able to find the number of leading zeros in an integer.
// In bitmaps.h I set up a function "nlz()" for this that maps onto
// intrinsics where it can. Well actually what I want is the position of the
// top 1 bit in a number so I can round up to a power of 2.

#include "bitmaps.h"

// C++20 introduces "consteval" which is like "constexpr" save that it
// INSISTS that evaluation happens at compile time. I will use it it
// it is available.

#ifdef __cpp_consteval
#define CONSTEVAL consteval
#else
#define CONSTEVAL constexpr
#endif

namespace fftutils
{

using Digit = std::uint64_t;
using SignedDigit = std::int64_t;

#ifdef DEBUG
using DigitPtr = vecpointer<Digit>;
using ConstDigitPtr = vecpointer<const Digit>;
#else // DEBUG
using DigitPtr = Digit*;
using ConstDigitPtr = const Digit*;
#endif // DEBUG


using Digit32 = std::uint32_t;
using SignedDigit32 = std::int32_t;

#ifdef DEBUG
using DigitPtr32 = vecpointer<Digit32>;
using ConstDigitPtr32 = vecpointer<const Digit32>;
#else // DEBUG
using DigitPtr32 = Digit32*;
using ConstDigitPtr32 = const Digit32*;
#endif // DEBUG

// A utility to round up to the next size that is either 2^n or 3*2^(n-2)

inline size_t roundUp23(size_t N)
{
#ifdef __cpp_lib_int_pow2
    size_t r = std::bit_ceil(N);
#else
    size_t r = 1LLU<<(64-nlz((uint64_t)(N-1)));
#endif
    size_t r1 = 3*(r/4);
    return N<=r1 ? r1 : r;
}

inline char* hex128(uint128_t a)
{   static char str[40];
    for (int i=31; i>=0; i--)
    {   str[i] = "0123456789abcdef"[a&0xf];
        a >>= 4;
    }
    str[32] = 0;
    return str;
}

inline char* dec128(uint128_t a)
{   static char str[44];
    char temp[44];
    size_t i=0, j=0;
    while (a != 0)
    {   temp[i++] = "0123456789"[a%10];
        a /= 10;
    }
    do  str[j++] = temp[--i]; while (i != 0);
    str[j] = 0;
    return str;
}

// For debugging it is nice to be able print out vectors... but the integers
// in the vectors are so large that trace output becomes unduly bulky. For
// some level of checking it will be OK if I just display the low 4 digits.

#ifdef SYMMETRIC

inline int64_t Sig(uint64_t a, uint64_t P)
{
    return a>(P/2) ? a-P : a;
}

#else

inline uint64_t Sig(uint64_t a, uint64_t P)
{   return a;
}

#endif

inline void prinvec(const char* s, const uint64_t* v, size_t n, uint64_t P)
{   std::cout << s;
    for (size_t i=0; i<n; i++)
        std::cout << " " << Sig(v[i], P);
    std::cout << "\n";
}

inline void prinvec(const char* s, uint64_t w, const uint64_t* v, size_t n, uint64_t P)
{   std::cout << s << " " << w << ":";
    for (size_t i=0; i<n; i++)
        std::cout << " " << Sig(v[i], P);
    std::cout << "\n";
}

inline void prinvec(const char* s, const uint64_t* v, size_t n)
{   std::cout << s;
    for (size_t i=0; i<n; i++)
        std::cout << " " << v[i];
    std::cout << "\n";
}

inline void prinvec(const char* s, uint64_t w, const uint64_t* v, size_t n)
{   std::cout << s << " " << w << ":";
    for (size_t i=0; i<n; i++)
        std::cout << " " << v[i];
    std::cout << "\n";
}

#ifdef SYMMETRIC

inline int32_t Sig(uint32_t a, uint32_t P)
{   return a>(P/2) ? a-P : a;
}

#else

inline uint32_t Sig(uint32_t a, uint32_t P)
{   return a;
}

#endif

inline void prinvec(const char* s, const uint32_t* v, uint32_t n, uint32_t P)
{   std::cout << s;
    for (uint32_t i=0; i<n; i++)
        std::cout << " " << Sig(v[i], P);
    std::cout << "\n";
}

inline void prinvec(const char* s, uint32_t w,
                    const uint32_t* v, uint32_t n, uint32_t P)
{   std::cout << s << " " << w << ":";
    for (uint32_t i=0; i<n; i++)
        std::cout << " " << Sig(v[i], P);
    std::cout << "\n";
}

inline void prinvec(const char* s, const uint32_t* v, uint32_t n)
{   std::cout << s;
    for (uint32_t i=0; i<n; i++)
        std::cout << " " << v[i];
    std::cout << "\n";
}

inline void prinvec(const char* s, uint32_t w,
                    const uint32_t* v, uint32_t n)
{   std::cout << s << " " << w << ":";
    for (uint32_t i=0; i<n; i++)
        std::cout << " " << v[i];
    std::cout << "\n";
}

//*************************************************************************
//*************************************************************************
// In this file I have code that gets eveluated at compile-time. It is
// is a separate file from the code that actually performs Fourier transforms
// for two reasons: first it is bulky enough that I do not want it to
// distract from the main code. Secondly in arithlib.hpp the main FFT
// code ends up as class member-functions and what I do here must be
// compiled as top-level code.
//
// The first part find five suitable primes and sets up roots of unity
// modulo each of them.
//*************************************************************************
//*************************************************************************

// The product of my 5 primes is about 0x272cf66*2^128. If you have
// a convolution of a pair of vectors of 64-bit integers each of length N
// then the largest integer in the output can be around N*2^128. So here
// the limit I have on N means that a value computed modulo the product
// of my five primes allows the true4 result to be extracted.

// All the FFT work will now be done modulo my primes, so the key
// modular product step (u*v)%P just involves a 64-bit intermediate
// result. The final Chinese Remainder step has to deliver a value with
// over 150 bits so involves some multi-precision work.

// Because the FFT work is time critical I use template expansion to
// express separate variants for each prime, since I expect that to allow
// modern C++ compilers to generate specialised code for the remainder
// operations. Tor that to be possible I set up a pile of compile-time
// executed code that selects primes and yields associated constants. This
// has the beneficial (I hope) side effect of avoiding the inclusion of
// a bunch of "magic numbers" in the code.

// Form (a+b) % N where all three inputs are 64-bit unsigned integers
// and a and b are both less than N. Annd then for (a-b) % N.

// I have both 64 and 32-bit basic modular arithmetic here in because
// although the main FFT will use just 32-but the Chinese Remainder
// support code may need more.

inline constexpr uint64_t plusmod(uint64_t a, uint64_t b, uint64_t N)
{   //assert(a < N);
    //assert(b < N);
    uint64_t c = a + b;
    if (c >= N) c -= N;
    return c;
}

template <uint64_t P>
inline constexpr uint64_t plusmod(uint64_t a, uint64_t b)
{   //assert(a < P);
    //assert(b < P);
    uint64_t c = a + b;
    if (c >= P) c -= P;
    return c;
}

inline constexpr uint32_t plusmod(uint32_t a, uint32_t b, uint32_t N)
{   //assert(a < N);
    //assert(b < N);
    uint32_t c = a + b;
    if (c >= N) c -= N;
    return c;
}

template <uint32_t P>
inline constexpr uint32_t plusmod(uint32_t a, uint32_t b)
{   //assert(a < P);
    //assert(b < P);
    uint32_t c = a + b;
    if (c >= P) c -= P;
    return c;
}

inline constexpr uint64_t differencemod(uint64_t a, uint64_t b, uint64_t N)
{   //assert(a < N);
    //assert(b < N);
    uint64_t c = a + N - b;
    if (c >= N) c -= N;
    return c;
}

template <uint64_t P>
inline constexpr uint64_t differencemod(uint64_t a, uint64_t b)
{   //assert(a < P);
    //assert(b < P);
    uint64_t c = a + P - b;
    if (c >= P) c -= P;
    return c;
}

inline constexpr uint32_t differencemod(uint32_t a, uint32_t b, uint32_t N)
{   //assert(a < N);
    //assert(b < N);
    uint64_t c = a + N - b;
    if (c >= N) c -= N;
    return c;
}

template <uint32_t P>
inline constexpr uint32_t differencemod(uint32_t a, uint32_t b)
{   //assert(a < P);
    //assert(b < P);
    uint64_t c = a + P - b;
    if (c >= P) c -= P;
    return c;
}

// Form (a*b) % N where all three inputs are 64-bit unsigned integers
// and a and b are both less than N.

inline constexpr uint64_t timesmod(uint64_t a, uint64_t b, uint64_t N)
{   //assert(a < N);
    //assert(b < N);
    return (uint64_t)(((uint128_t)a * b) % N);
}

template <uint64_t P>
inline constexpr uint64_t timesmod(uint64_t a, uint64_t b)
{   //assert(a < P);
    //assert(b < P);
    return (uint64_t)(((uint128_t)a * b) % P);
}

// Form (a*b) % N where all three inputs are 32-bit unsigned integers
// and a and b are both less than N.

inline constexpr uint32_t timesmod(uint32_t a, uint32_t b, uint32_t N)
{   //assert(a < N);
    //assert(b < N);
    return (uint32_t)(((uint64_t)a * b) % N);
}

template <uint32_t P>
inline constexpr uint32_t timesmod(uint32_t a, uint32_t b)
{   //assert(a < P);
    //assert(b < P);
    return (uint32_t)(((uint64_t)a * b) % P);
}

inline constexpr uint64_t times64(uint32_t a, uint32_t b)
{    return a*(uint64_t)b;
}

/// Compute x^n mod N where all values are 64 bits.

inline constexpr uint64_t exptmod(uint64_t x, uint64_t n, uint64_t N)
{   if (n == 0) return 1;
    uint64_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = timesmod(x, y, N);
        x = timesmod(x, x, N);
        n = n / 2;
    }
    return timesmod(x, y, N);
}

inline constexpr uint32_t exptmod(uint32_t x, uint32_t n, uint32_t N)
{   if (n == 0) return 1;
    uint32_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = timesmod(x, y, N);
        x = timesmod(x, x, N);
        n = n / 2;
    }
    return timesmod(x, y, N);
}

// Find the reciprocal of a mod N.

template <uint64_t P>
inline constexpr uint64_t recipmod(uint64_t a)
{   int64_t y = 0, x = 1;
    uint64_t m = P;
    while (a > 1)
    {   uint64_t q = a / m;
        uint64_t t = m; m = a - q*m; a = t;
        int64_t t1 = y; y = x - q*y; x = t1;
    }
    if (x < 0) x += P;
    return x;
}

template <uint32_t P>
inline constexpr uint32_t recipmod(uint32_t a)
{   int32_t y = 0, x = 1;
    uint32_t m = P;
    while (a > 1)
    {   uint32_t q = a / m;
        uint32_t t = m; m = a - q*m; a = t;
        int32_t t1 = y; y = x - q*y; x = t1;
    }
    if (x < 0) x += P;
    return x;
}

// Use Miller-Rabin with base a to see if it can show that N is
// composite. I am happy to leave this as 64-bit code since it is only
// execured at compile time so any excess there has no impact on eventual
// runtime cost.

inline CONSTEVAL bool miller_rabin_probably_prime(uint64_t a, uint64_t N)
{   uint64_t d = N-1;
    int s = 0;
    while ((d % 2) == 0)  // Find largest power of 2 dividing n-1
    {   d = d/2;
        ++s;
    }
    uint64_t x = exptmod(a, d, N);
    if (x == 1 || x == N-1) return true;
    while (s > 1)
    {   x = timesmod(x, x, N);
        if (x == 1) return false;
        else if (x == N-1) return true;
        --s;
    }
    return false;
}

// For numbers up to 2^64 use of the following 12 bases will filter
// out all composite numbers so this is a fully reliable check for
// primality in that range. Again I will now only be checking values up
// to 2^31 so the support for 64-bit values is not really necessary!

inline CONSTEVAL bool isprime64(uint64_t N)
{   const uint64_t witnesses[] =
        {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (auto a:witnesses)
       if (!miller_rabin_probably_prime(a, N)) return false;
    return true;   
}

// I will be prepared to perform FFTs on vecvtors whose length is a power
// or two or three times a power of two. This restriction is based on my
// investigation of the costs of performing the transform as balanced againt
// the need to pad vectors up to a size I will cope with. So suppose N
// is a vectore length of that form. To do the FFT using modular arithmetic
// I will want a prime P of the form k*N+1 because in that case I will be
// able to find a suitable primitive Nth root of unity.

// In the FFT code I have some lines of the form
//    A = u+v;
// to be processed mod P, and I can render that as
//    A = u+v; if (A>=P) A-=P;
// provided P<0x80000000. 
// There are also lines such as
//    A = u-v-w1*w2+x1*x2
// and with P as above I can render this as
//    A = (u-v-w1*w1+x1*x2+P^2)%P
// and because all inputs are in the range 0..P-1 the bracket will end
// up positive and I do just one remaindering operation. I expect that to
// be a good thing to do even though processing u and v involves widening
// them from 32 to 64-bits and adding in P^2 is an extra addition.

// There are two things that limit the size of the largest number I can
// handle. I want to have a single primitive root associated with each prime,
// and foe that the primes must each be one greater than a multiple of the
// LCM of all possible lengths. And then the power of 2 that is a factor of
// that LCM sets a limit on the length of vectors. This limit means that
// I will not be able to handle numbers with over about 2^31.5 bits (remember
// each of those 3*2^24 digits is 64 bits) and that is almost 10^0 decimal
// digits.

// The second thing that limits the largest numbers that can be handles is
// the use of just 5 prime moduli. If the convolution of two N digit
// numbers is formed accurately some of the values may be the result of
// adding N products of pairs. So the modular work and reconstruction here
// bust be able to handle 128+log(N) bits. Happily here it turns out that
// the product of the five primes I end up with will be just over 0x28f3d31
// times 2^128, giving 25 bits there. This is remarkably close to the first
// limit I had! And in any of my uses I will not approach either.

inline constexpr uint32_t LCMlengths = 0x06000000U;

// Here I will be able to cope with vectors of length up to 3*2^24. A
// vector just longer than that would round up in size to 2^26 which does
// not divide into my LCM nicely. So I should view that as the limit to
// vector length. The value is 50_331_648 and that is a count of 64-bit words
// so it represents 3_221_225_472 bits. That is 969_685_489 decimal digits
// so just short of a billion decimal digits. To cope with more I would
// want to move to use of 64-bit primes for my modular arithmetic.


inline CONSTEVAL uint64_t findP(uint64_t start)
{   uint64_t p = LCMlengths*(start/LCMlengths) + 1;
    while (!isprime64(p)) p -= LCMlengths;
    return p;
}

// I need primes each of which is 1 larger than a multiple of LCMlengths.
// I start with Q1 the first such prime such that 2*Q1^2-Q1 will fit in
// a 64-bit integer. Of course each prime does not fully fill the 32-bits
// so the actual width of a value reconstructed modulo their product will
// be log2(Q1*Q2*Q3*Q4*Q5) = 153.36. That is to say 128+25 bits. A result
// of this is that such a reconstruction can cope with convolutions involving
// vectors of length up to 2^25. Well look harder at this. If I have a pair
// of numbers such that their product will use at most 1.5*2^25 digits
// then the sum of the (non-zero) lengths in the two numbers will be
// at most that. The convolution with largest values in it will be one
// where the two inputs are the same length and then the middle term of
// it will be the sum of 1.5*2^24 64-bit numbers. That will not overflow
// the 153 bits I can cope with here. So the constraint on the biggest
// multiplications I can perform is JUST 1.5*2^25. I think I am both
// astonished and rather pleased that two constraints end up so close
// to setting consistent limits.


inline constexpr uint32_t Q1 = findP(0x80000000U);  // 0x7e000001
inline constexpr uint32_t Q2 = findP(Q1-2);         // 0x78000001
inline constexpr uint32_t Q3 = findP(Q2-2);         // 0x6c000001
inline constexpr uint32_t Q4 = findP(Q3-2);         // 0x66000001
inline constexpr uint32_t Q5 = findP(Q4-2);         // 0x42000001

// For reason I do not understand gdb has trouble displaying Q1 etc
// and seems to show floating point values. I hope these versions will
// help me debug more easily.
inline uint32_t QQ1 = Q1;
inline uint32_t QQ2 = Q2;
inline uint32_t QQ3 = Q3;
inline uint32_t QQ4 = Q4;
inline uint32_t QQ5 = Q5;

// For each prime I want a value (omega1,omega2,...) that is a primitive
// LCMlength root of unity modulo that prime.

template <uint64_t P>
inline CONSTEVAL uint64_t rootofunity()
{   for (uint64_t k=2;;k++)
    {   if (exptmod(k, (P-1), P) != 1) continue; // redundant: P prime
// The next 2 lines verify that no lower power of k will be 1. Ie that
// 1, k, k^2, ... k^LCMlengths is a full length cycle of distinct values.
        if (exptmod(k, (P-1)/2, P) == 1) continue;
        if (exptmod(k, (P-1)/3, P) == 1) continue;
// The result will be such that whem raised to the power LCMlengths it
// yields 1. This means that for any length L that is a factor of LCMlengths
// then this value r raised to the power (LCMlengths/L) will be a primitive
// Lth root of unity, as required for a length-L fft.
        return exptmod(k, (P-1)/LCMlengths, P);
    }
}

inline constexpr uint32_t omega1 = rootofunity<Q1>();   // 0x0f6abdd4
inline constexpr uint32_t omega2 = rootofunity<Q2>();   // 0x54c52df8
inline constexpr uint32_t omega3 = rootofunity<Q3>();   // 0x58232605
inline constexpr uint32_t omega4 = rootofunity<Q4>();   // 0x0cb719df
inline constexpr uint32_t omega5 = rootofunity<Q5>();   // 0x1476e7a6

//*************************************************************************
//*************************************************************************
// Next comes support for Chinese Remainder code. This involves using
// and extended GCD algorithm first on (Q1,Q2) and (Q3,Q4) to get results
// modulo P1=Q1*Q2 ands P2=Q3*Q4. Then I merge them to get a result
// modulo P1*P2 (=Q1*Q2*Q3*Q4) and finally deal with Q5 - which for some
// level of tidiness I call P3 too.
//*************************************************************************
//*************************************************************************

inline constexpr uint64_t P1 = Q1*(uint64_t)Q2;
inline constexpr uint64_t P2 = Q3*(uint64_t)Q4;
inline constexpr uint32_t P3 = (uint32_t)Q5;

// Given a and b I want to find x and y such that
//     a*x - b*y = 1  (x_negated=false)
//    -a*x + b*y = 1  (x_negated=true)
// The reasoning here is that the standard version sets up
//     a*x + b*y = 1
// but one of x and y will be negative (both a and b will be positive -
// in my usage they will be two prime numbers). But when I come to handle
// the output having signed values is confusing - especially if I have
// multi-precision ones, so going for a sort of sign and magnitude
// representation feels cleanest. 

struct XGCD64
{   int64_t x = 1, y = 0;
    bool x_negated = false;
    CONSTEVAL XGCD64(int64_t a, int64_t b)
    {   int64_t u=1, v=0;
        while (b!=0)
        {   int64_t q=a/b;
            int64_t temp=a-q*b; a=b; b=temp;
            temp=y-u*q;         y=u; u=temp;
            temp=x-v*q;         x=v; v=temp;
        }
        if (x < 0)
        {   x = -x;
            x_negated = true;
        }
        else y = -y;
    }
};

// These first two are used to find results mod P1 and P2, and then
// the third helps with P1*P2 - otherwise Q1*Q2*Q3*Q4.

inline constexpr XGCD64 Q1_Q2(Q1, Q2);
inline constexpr XGCD64 Q3_Q4(Q3, Q4);

inline constexpr XGCD64 P1_P2(P1, P2);

// now suppose X = a mod P1 and b mod P2 then
//    x = a*P2*P1_P2.x - b*P1*P1_P2.y  [uniquely mod P1*P2]
// or (as in the previous case) with the subtraction done the
// other way round.

struct XGCD128
{   int128_t x = 1, y = 0;
    bool x_negated = false;
    CONSTEVAL XGCD128(int128_t a, int128_t b)
    {   int128_t u=1, v=0;
        while (b!=0)
        {   int128_t q=a/b;
            int128_t temp=a-q*b; a=b; b=temp;
            temp=y-u*q;        y=u; u=temp;
            temp=x-v*q;        x=v; v=temp;
        }
        if (x < 0)
        {   x = -x;
            x_negated = true;
        }
        else y = -y;
    }
};

inline constexpr uint128_t P1xP2 = (uint128_t)P1*P2;
inline constexpr XGCD128 P1_P2_P3(P1xP2, P3);

inline uint64_t Hi(uint128_t n)
{   return n>>64;
}

inline uint64_t Lo(uint128_t n)
{   return n;
}

// I observe that in the two cases I am using here neither ends up
// with x negated. However the code above shows awareness that that
// situation could arise.

// Now a bit of code that finds given
//    X = a1 mod P1,   a2 mod P2,   a3 mod P3
// and retuns its value split into 3 64-bit digits {hi,mid,lo}

// I need to be able to multiply a 64 bit value by a 128-bit one. This
// is basically "short multiplication" because I view the 128 bit
// number as two 64-bit digits.

inline constexpr void times_64_128(uint64_t a, uint128_t b,
                                   uint64_t& hi, uint64_t& mid, uint64_t& lo)
{   uint64_t bhi = static_cast<uint64_t>(b>>64);
    uint64_t blo = static_cast<uint64_t>(b);
    uint128_t w1 = a*(uint128_t)blo;
    lo = static_cast<uint64_t>(w1);
    uint128_t w2 = a*(uint128_t)bhi + (w1>>64);
    mid = static_cast<uint64_t>(w2);
    hi = static_cast<uint64_t>(w2>>64);
}

// I will need a value of P1*P2*P3 expressed radix 2^64, ie as 3 digits.

struct P1xP2xP3_t
{
    uint64_t hi = 0;
    uint64_t mid = 0;
    uint64_t lo = 0;
    CONSTEVAL P1xP2xP3_t()
    {   times_64_128(P1, P2*(uint128_t)P3, hi, mid, lo);
    }
};

inline constexpr P1xP2xP3_t P1xP2xP3;

// I want (a*b)%P1xP2 where all the values are 128-bit integers.
// I had experimented with code to do this on 64-bit inputs but found
// that relying on simple code using g++ or clang++ 128-bit integers
// made better sense, But here I do not have the luxury of letting the
// compiler take the strain! Well that means my previous work was not
// totally in vain.

template <uint128_t P>
inline CONSTEVAL int leadingzeros()
{   for (int i=0; i<128; i++)
        if ((P>>(127-i)) == 1) return i;
    return 128;
}

// I want 2^M/P such that it fills all of a 128-bit word.
// Because the plan is that this only gets used at compile-time I will
// not try very hard re performance. Also I will not worry about
// overflow or division by zero.

template <uint128_t P>
inline CONSTEVAL uint128_t inverse()
{   uint128_t phi=static_cast<uint128_t>(1)<<(128-leadingzeros<P>()), plo=0;
    uint128_t q = P;    
    uint128_t r = 0;
    for (int i=0; i<128; i++)
    {   r <<= 1;
        if (phi >= q)
        {   phi -= q;
            r |= 1;
        }
        phi = (phi<<1) | (plo>>127);
        plo <<= 1;
    }
    return r;
}

inline constexpr uint128_t invP1xP2 = inverse<P1xP2>();

// Multiply a pair of 128-bit values to get a 256 bit result.

inline void times_128(uint128_t a, uint128_t b,
                      uint128_t& chi, uint128_t& clo)
{
    uint64_t ahi = a>>64, alo = a;
    uint64_t bhi = b>>64, blo = b;
    uint128_t hh = ahi*(uint128_t)bhi;
    uint128_t hl = ahi*(uint128_t)blo;
    uint128_t lh = alo*(uint128_t)bhi;
    uint128_t ll = alo*(uint128_t)blo;
    chi = hh + (hl>>64) + (lh>>64);
    hl <<= 64;
    lh <<= 64;
    clo = ll + hl;
    if (clo < hl) chi++;
    clo = clo + lh;
    if (clo < lh) chi++;
}

// This is to get the high 128 bits of the product of two 128 bit
// numbers. Well I will not fuss about carries that would have
// come from adding in the low halves of the cross products so
// the value I get may be low by 1 or 2. In context I will not worry
// about this.

inline constexpr uint128_t times_hi_128(uint128_t a, uint128_t b)
{   uint64_t ahi = a>>64, alo = a;
    uint64_t bhi = b>>64, blo = b;
    uint128_t hi = ahi*(uint128_t)bhi;
    uint128_t mid1 = (ahi*(uint128_t)blo)>>64;
    uint128_t mid2 = (bhi*(uint128_t)alo)>>64;
    return hi + mid1 + mid2;
} 

// Form (a*b) mod P=P1*P2  where a and b are both 128-bit values -
// taking advantage of the fact that the value of P is known and has
// a couple of high zero bits.

template <uint128_t P>
inline constexpr uint128_t timesmod(uint128_t a, uint128_t b)
{   uint128_t phi=0, plo=0;
    times_128(a, b, phi, plo);
// Here a and b each have (at least) leadingzeros<P>() leading zeros and so
// their product has at least 2*leadingzeros<P>(). So if I shift the 256-bit
// version of the product right by 128-2*leadingzeros<P>() I should get a
// value that fits into 128 bits and that has as much accuracy as I can. 
    uint128_t ptop = (phi<<(2*leadingzeros<P>())) |
                     (plo>>(128-2*leadingzeros<P>()));
    uint128_t quot = times_hi_128(ptop, invP1xP2);
// I now want to set rem = a*b - quot*P1xP2
// Well quot needs shifting to allow for that fact that invP1xP2 had
// been shifted up to get extra precision.
    quot >>= (leadingzeros<P>()-1);
    uint128_t qhi=0, qlo=0;
    times_128(quot, P1xP2, qhi, qlo);
    phi -= qhi;
    uint128_t r = plo - qlo;
    if (r > plo) phi--;
//  assert(phi == 0);
// I very much expect that after this {phi,plo} will be my remainder
// and since that is < 2^128 only plo matters.
    if (r > P1xP2) r -= P1xP2;
    return r;
}

//*************************************************************************
//*************************************************************************
// I have now set up some useful constants, so I can give the code
// that actually performs the interpolation.
//*************************************************************************
//*************************************************************************

// Suppose I have two comprime values P1 and P2 and I know that
//    A = a1 mod P1
//    A = a2 mod P2  and I want to find A [modulo P1*P2]
// I start by finding x and y such that
//    x*P1 + y*P2 = 1  [be aware that one of x,y will be +ve and one -ve]   
// Easily note
//    x*P1 = 1 mod P2
//    y*P2 = 1 mod P1
// and based on that we have that
//    A = a2*x*P1 + a1*y*P2  mod P1*P2
// satisfies the constraints. Now I want to avoid triple length arithmetic
// so I can write this as
//    A = (a2*x % P2)*P1 ++ (a1*y % P1)*P2
// where "++" will in fact be a subtraction (one way round or the
// other) and if it was about to give a negative result one most add
// P1*P2 to bring the final result into range.

// The version of the code I have here sets three constraints.
// It works by first generating a value based on the first two and
// that will be unique modulo P1*P2. It then does the same process
// (but now having to use larger numbers) to merge in the the effect
// of P3. The result will be returned as three 64-bit digits.

inline uint32_t modulo(uint64_t hi, uint64_t mid, uint64_t lo, uint32_t P)
{   uint32_t r = ((((uint128_t)hi)<<64) + mid)%P;
    r = ((((uint128_t)r)<<64) + lo)%P;
    return r;
}

// This reconstructs modulo P1 and P2 (each of which are 64 bits wide) and
// P3 which is only 32-bits wide. This gives a result that fits within
// 64+64+32 bits (ie 160 bits). 

inline void chinese_remainder(Digit a1, Digit a2, Digit32 a3,
                              uint64_t& hi, uint64_t& mid, uint64_t& lo)
{
    //assert(a3 < Q3);
// First find a1a2 which will be a1 mod P1 and a2 mod P2
    uint128_t a1a2A = ((a2*(uint128_t)P1_P2.x)%P2)*P1;
    uint128_t a1a2B = ((a1*(uint128_t)P1_P2.y)%P1)*P2;
    uint128_t a1a2;
    if constexpr (P1_P2.x_negated)
        a1a2 = a1a2B >= a1a2A ? a1a2B - a1a2A
                              : a1a2B + (uint128_t)P1xP2 - a1a2A;
    else
        a1a2 = a1a2A >= a1a2B ? a1a2A - a1a2B
                              : a1a2A + (uint128_t)P1xP2 - a1a2B;
// here a1a2 should be a1 mod P1 (== Q1*Q2) and a2 mod P2 (== Q3*Q4)
    //assert(a1a2%P1 == a1);
    //assert(a1a2%P2 == a2);
//
// Now the next step is logically the same but looks messier
// because I need to go to 192 bits. Well more pedantically around 150
// would suffice, but that still means I will use three 64-bit digits.
//
// The logic is
//    p = ((a3*P1_P2_P3.x)%P3)        * (P1*P2); a3 & p1_p2_p3.x both 64 bits
//    q = ((a1a2*P1_P2_P3.y)%(P1*P2)) * P3;   a1a2 & p1_p2_p3.y both 128 bits
//    (p - q) % (P1*P2*P3);     [ or potentially q-p ]
// and note here that which of p and q is larger is a separate matter
// from which way the subtraction goes, but that each of p and q are in
// the range 0 .. P1*P2*P3-1.
    Digit temp = a3*(Digit)P1_P2_P3.x; // will not overflow inputs are 32-bit
    Digit phi, pmid, plo;
    times_64_128(temp%P3, P1xP2, phi, pmid, plo);
// Now for the messier one: I need (a1a2*P1_P2_P3.y) % (P1*P2)
// and all three values involved are 128-bits wide.
    uint128_t q1 = timesmod<P1xP2>(a1a2, P1_P2_P3.y);
    Digit qhi, qmid, qlo;
    times_64_128(P3, q1, qhi, qmid, qlo);
// Now I need to return p-q  mod P1xP2xP3. Note that both p and q are
// less than P1xP2xP3 so the only correction I can need would be if the
// naive subtraction leaves a negative value.
// The x_negated flag is a constant!
    if constexpr (P1_P2_P3.x_negated)   
    {   hi = qhi-phi;
        mid = qmid-pmid;
        lo = qlo-plo;
        if (mid > qmid) hi--;
        if (lo > qlo)
        {   if (mid-- == 0) hi--;
        }
    }
    else
    {   hi = phi-qhi;
        mid = pmid-qmid;
        lo = plo-qlo;
        if (mid > pmid) hi--;
        if (lo > plo)
        {   if (mid-- == 0) hi--;
        }
    }
// This could have left a negative result - if it did I must add in P1*P2*P3
    if ((hi>>63) != 0)
    {   hi = hi + P1xP2xP3.hi;
        mid = mid + P1xP2xP3.mid;
        lo = lo + P1xP2xP3.lo;
        if (mid < P1xP2xP3.mid) hi++;
        if (lo < P1xP2xP3.lo)
        {   if (++mid == 0) hi++;
        }
    }
}

// Here I have 32-bit values a, b, q1, q2, x and y and I require
//   R = a mod q1
//   R = b mod q2
//   x*q1 - y*q2 = 1 or -x*q1 + y*q2 = 1 depending on x_negated.
// Return the 64-bit value of R

template <Digit32 q1, Digit32 q2, Digit32 x, Digit32 y, bool x_negated>
inline Digit chinese_remainder_32(Digit32 a, Digit32 b)
{   //assert(a < q1);
    //assert(b < q2);
// First find a1a2 which will be a1 mod q1 and a2 mod q2
    Digit RA = ((b*(Digit)x)%q2)*q1;
    Digit RB = ((a*(Digit)y)%q1)*q2;
    Digit P = q1*(Digit)q2;
    Digit r;

// 4 lines just for debugging
    if constexpr (x_negated) r = RB >= RA ? RB - RA : RB + P - RA;
    else r = RA >= RB ? RA - RB : RA + P - RB;
    //assert(r%q1 == a);
    //assert(r%q2 == b);

    if constexpr (x_negated) return RB >= RA ? RB - RA : RB + P - RA;
    else return RA >= RB ? RA - RB : RA + P - RB;
}

inline void chinese_remainder(Digit32 a1, Digit32 a2,
                              Digit32 a3, Digit32 a4, Digit32 a5,
                              uint64_t& hi, uint64_t& mid, uint64_t& lo)
{   //assert(a1 < Q1);
    //assert(a2 < Q2);
    //assert(a3 < Q3);
    //assert(a4 < Q4);
    //assert(a5 < Q5);
    uint64_t b1 = chinese_remainder_32<
                  Q1,Q2,Q1_Q2.x,Q1_Q2.y,Q1_Q2.x_negated>(a1, a2),
             b2 = chinese_remainder_32<
                  Q3,Q4,Q3_Q4.x,Q3_Q4.y,Q3_Q4.x_negated>(a3, a4);
    //assert(a1 == b1%Q1);
    //assert(a2 == b1%Q2);
    //assert(a3 == b2%Q3);
    //assert(a4 == b2%Q4);
    chinese_remainder(b1, b2, a5, hi, mid, lo);
}

#ifdef TESTUTILS

extern "C"
{

int main()
{
     std::cout << std::hex;
     std::cout << Q1 << "  " << omega1 << "  " << (2*Q1*(uint64_t)Q1) << "\n";
     std::cout << Q2 << "  " << omega2 << "  " << (2*Q2*(uint64_t)Q2) << "\n";
     std::cout << Q3 << "  " << omega3 << "  " << (2*Q3*(uint64_t)Q3) << "\n";
     std::cout << Q4 << "  " << omega4 << "  " << (2*Q4*(uint64_t)Q4) << "\n";
     std::cout << Q5 << "  " << omega5 << "  " << (2*Q5*(uint64_t)Q5) << "\n";

     uint64_t hi, mid, lo;
     chinese_remainder(7,7,7,7,7, hi,mid,lo);
     std:: cout << hi << " " << mid << " " << lo << "\n";

     std::cout << "finishing\n";
     return 0;
}

}

#endif // TESTUTILS

} // end of namespace

// end of fftutils.cpp
