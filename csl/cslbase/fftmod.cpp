// fftmod.cpp                                     Copyright 2025 A C Norman

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


// The code here uses Fourier Transfroms, or perehaps more pedantically
// the Number Theoretical Transfrom, to multiply large integers. Those
// integers have 64-bit digits.
// Initial results suggest that it will match or improve on simple
// schoolbook long multiplication for results that are 256 digits long,
// It will be some way beyond that before it matches Karatsuba and Toom,
// but that threshold will be assessed later on. But there seems a chance
// that it will leave my version of Karatsuba that uses three threads
// at the top level with at best a rather narrow band of applicability.


// To form a*b let N be length(A)+length(B) rounded up. For many presentations
// of FFT multiplication one rounds up to a power of 2.
// I *may* at a later stage allow for multiples of 3 or 5 to be used
// in the size so as to reduce the amount of paddiing needed.
// I pad each of a and b to length N with zeros. I have three primes P1,
// P2 and P3 such that each fits in 64-bits and eachg is a multiple of
// every possible length that I will be using. This limits the length
// of inputs to around 2^44 digits which is a constraint that I am not
// especially worried about.
// If P is a prime I form the FFT of a and of b, do pairwise multiplication
// and an inverse FFT all mod P. The result will be an image of my product
// modulo P. Using the Chinese Remainder Theorem I can then re-create
// digits modulo P1*P2*P3. That is big enough for everything to be correct
// in Z. Because those reconstructions and 3 digits long I have some carry
// operations before I end up with what should be the true product in a
// natural form.
//
// I do the multiplication modulo three primes P1, P2 and P3 and I do those
// steps in parallel. That increases overhead for shortish numbers but
// really pays of for large enough ones.

// I have three multiplication schemes here while I test. One is simple
// classical O(N^2) and that can provide a baseline for comparing both
// results and timings. The next uses Fourier Transforms over the prime
// fields but computes them using simple multiplication by matrix with
// elements omega^(i*j). That provides no speed advantage but will show
// the values that should emerge from transforms - and that version
// appears to work (thereby validating both the structure of the code and
// details of the modular arithmetic).
// The final one is the "fast" version which should run in time proportional
// to N*logN.

// I might comments on some of the decisions embedded here and some
// alternatives that I have not followed up on.
// I might have used 32-bit primes so that (a*b)%P all worked directly in
// properly portable C++ with the product a 64-bit integer. But for a vector
// length N I need a prime of the form k*N+1 so I can find a primitive root/
// Suppose for a moment that I just use power of 2 lengths up to 2^L and I
// keep using 64-bit digits, then I will need 5 32-bit primes each of the
// for k*2^L+1 and that will restrict L unduly. If I use 32-bit digits by
// splitting my input ones into low and high halves I only need 3 such primes.
// But I still restrict L, and I would prefer a scheme that could extent to
// multiply numbers to unreasonably long lengths. Experiments suggest that
// I could have L up to 2^27 and have 5 primes, but no better than that.
//
//            Arthur Norman



#include <cstdint>
#include <iostream>
#include <iomanip>
#include <bit>
#include <utility>
#include <algorithm>
#include <vector>
#include <thread>

// The following will provide support for some parallel execution.
// It provides a call
//     runInThreads(vector<T>v, void (*fn)(T));
// that applies the given function to each item in the vector.

#include "cthread.cpp" 

// For testing I will want...
#include <cmath>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <atomic>
#include <cassert>


// This makes 128-bit integers available using either g++ or clang++.
// It is not standard-compliant and even with those compilers it may
// not be available on all computers.

#ifdef __GNUC__
using int128  = __int128;
using uint128 = unsigned __int128;
#endif

// C++20 introduces "consteval" which is like "constexpr" save that it
// INSISTS that evaluation happens at compile time. I will use it it
// it is available.

#ifdef __cpp_consteval
#define CONSTEVAL consteval
#else
#define CONSTEVAL constexpr
#endif

// I find the extreme generality of the C++ <chrono> scheme rather
// heavy - so here I wrap it up to give me a simple function that
// reports microseconds used since this program was started. The
// length of the lines here with multiple instances of "::" illustrates
// what is involved!

// high_resolution_clock may be an alias for system_clock and that may
// sometimes not be monotonic. I believe I observe that oddity under WSL2,
// so using steady_clock seems safer,

inline auto basetime = std::chrono::steady_clock::now();

inline auto microseconds()
{   auto tt = std::chrono::steady_clock::now() - basetime;
    return std::chrono::duration_cast<std::chrono::microseconds>(tt).count();
}

// C++ does not (as part of its standard) support sending 128-bit
// integers to an output stream. So here I have a little function that
// ts to convert from such an integer to a string so I can print it.

inline char* hex(uint128 a)
{   static char str[40];
    for (int i=31; i>=0; i--)
    {   str[i] = "0123456789abcdef"[a&0xf];
        a >>= 4;
    }
    str[32] = 0;
    return str;
}

inline char* dec(uint128 a)
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

inline int64_t Sig(uint64_t a, uint64_t P)
{   return a>(P/2) ? a-P : a;
}

inline void prinvec(const char* s, uint64_t* v, size_t n, uint64_t P)
{   std::cout << s;
    if (n > 10u) n = 10; // to limit printout!
    for (size_t i=0; i<n; i++)
        std::cout << " " << Sig(v[i], P)%10000;
    std::cout << "\n";
}

inline void prinvec(const char* s, uint64_t w, uint64_t* v, size_t n, uint64_t P)
{   std::cout << s << " " << w << ":";
    if (n > 10u) n = 10; // to limit printout!
    for (size_t i=0; i<n; i++)
        std::cout << " " << Sig(v[i], P)%10000;
    std::cout << "\n";
}

//*************************************************************************
//*************************************************************************
// I will first have some code that gets run at compile time and so does
// contribute tu runtime costs.
// The first part find three suitable primes and sets up roots of unity
// modulo each of them.
//*************************************************************************
//*************************************************************************

// In the future I may wish to decimate radix 3 or 5 as well as 2, and
// so I choose my primes so that that will be possible if I end up
// going there.
//
// Note that 3*3*3*3*5*5*5 = 10125. What I have here are three primes
// each less than 2^64 and each one greater than a multiple of
// 2^44*3^4*5*3. A consequence of this is that if I choose vector
// sizes that are of the form N=2^a*3^b*5^c with a<=44, b<=4 and c<=3
// then then there will always be a principle Nth root of unity modulo
// each of them. If I round every vector that I use up to a size that is
// of the form N as above the worst padding will involve growth by
// 12.5% and it is reasonable to expect "average" growth by just 4%.
// These numbers are to be compared against the style of FFT work that
// can need to (almost) double the size of vectors to get a power of 2
// as the working vector size.
// The effect is that I can take FFTs on vectors of length up to 2^44.
// That is of course a limit way larger than anything that is feasible
// in 2025.
// If I worked with numbers represented as 2^44 digits with each digit
// being 64-bits, the convolution that emerges as the product could have
// 2*64+44 bits which is 172 bits. Happily the product of the three primes
// is a number with 180 bits - ie slightly beyond that - so I can recover
// the correct value using the Chinese Reaminder Theorem and these
// three primes.
//
// There are then two bits of extended precision arithmetic needed:
// (1)    Form the product (u*v) mod P
// (2)    Chinese Remainder mod P1, P2 and P2 to get a 172 bit result
//        expressed in 64-bit segments.
//
// Pretty much the standard scheme for performing modular multiplication
// when the remaindering operation could be expensive but the modulus is
// a known value goes along the lines:
//       w = u*v     as a result of width 128. I note that the computers
//                   I am most interested in support forming a product
//                   in this form.
//       w' = top bits of w, such that it can be a full 64-bit value.
//            Since u and v are each only 63 bits their product is
//            at most 126 so the top 64 bits that I collect contain
//            more than half the information.
//       q = top half of w'*(2^M/P) where the power of 2 is chosen
//            to leave q using all the 64-bits of a register. I am going to
//            argue that q will be a really good approximation to w/P
//       r = w - q*P
//            If I am really lucky here I will be able to be confident that
//            the high part of this will all cancel out and so I only
//            compute its low 64-bits.
// If r is not the perfect remainder I expect it to be out by at most 1,
// and so if what I compute has r>=P I know I need to do a correction
// step - but that is a cheap test. The fact that I can set this up with
// a known set of shifts and of 2^126/P comes down to me being able to use
// a single set of primes for all vector-lengths, and that is why I make
// the primes each one greater than the LCM of all lengths I will support,
// with that being reasonable given the constraints I apply the the
// vector-length N.
//
// HOWEVER I find that with g++ and clang++ the code (u*v)%P gets compiled
// into something very much like the above when P is know, so for reduction
// modulo a 64-bit prime I do not need to write all this out! But later on
// I will want to perform a multiplication modulo a value that is 128-bits
// wide, and there I will need to code up a version of it.

// First I will have a pile of compile-time-executed code that selects
// primes and yields associated constants.

// Form (a+b) % N where all three inputs are 64-bit unsigned integers
// and a and b are both less than N. Annd then for (a-b) % N.

inline constexpr uint64_t plusmod(uint64_t a, uint64_t b, uint64_t N)
{   uint64_t c = a + b;
    return c >= N ? c-N : c;
}

template <uint64_t P>
inline constexpr uint64_t plusmod(uint64_t a, uint64_t b)
{   uint64_t c = a + b;
    return c >= P ? c-P : c;
}

inline constexpr uint64_t differencemod(uint64_t a, uint64_t b, uint64_t N)
{   if (a >= b) return a-b;
    else return (a+N)-b;
}

template <uint64_t P>
inline constexpr uint64_t differencemod(uint64_t a, uint64_t b)
{   if (a >= b) return a-b;
    else return (a+P)-b;
}

// Form (a*b) % N where all three inputs are 64-bit unsigned integers
// and a and b are both less than N.

inline constexpr uint64_t timesmod(uint64_t a, uint64_t b, uint64_t N)
{   return (uint64_t)(((uint128)a * b) % N);
}

template <uint64_t P>
inline constexpr uint64_t timesmod(uint64_t a, uint64_t b)
{   return (uint64_t)(((uint128)a * b) % P);
}

// Compute x^n mod N where all values are 64 bits.

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

// Use Miller-Rabin with base a to see if it can show that N is
// composite. 

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
// primality in that range.

inline CONSTEVAL bool isprime64(uint64_t N)
{   const uint64_t witnesses[] =
        {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (auto a:witnesses)
       if (!miller_rabin_probably_prime(a, N)) return false;
    return true;   
}

// Now for FFT purposes I will need primes that have a primitive
// Nth root, and here I am interested in that being the case when
// N is a factor of 2^44*3^4*5^3. For that to work out I just need
// a prime that is 1 greater than some multiple of that magic number.
// Here I search down from the value "start" by first rounding it to
// be a suitable value and then stepping down until I find a prime.
// The density of primes (in arithmetic progressions) tells me that
// I will not have a totally unreasonable search to perform.

inline constexpr uint64_t LCMlengths = (3*3*3*3*5*5*5LU) << 44;

inline CONSTEVAL uint64_t findP(uint64_t start)
{   uint64_t p = LCMlengths*(start/LCMlengths) + 1;
    while (!isprime64(p)) p -= LCMlengths;
    return p;
}

// I start with P1 the first prime below 2^63, then P2 and P3 are the
// next viable ones down from there. Note that P3 is just 1 greater
// than 2^44*3^4*5^3. 
// The primes here are uniquely defined by the constraints
// I have shown above - and so I could write their values out as
// simple literals. But by using constexpr compile-time calculation I
// "show my working" and protect against typos.

inline constexpr uint64_t P1 = findP(1LU<<63);   // 0x6a4af00000000001
inline constexpr uint64_t P2 = findP(P1-2);      // 0x2022900000000001
inline constexpr uint64_t P3 = findP(P2-2);      // 0x0278d00000000001

// For each prime I want a value (omega1,...) that is a primitive
// LCMlength root of unity.

template <uint64_t P>
inline CONSTEVAL uint64_t rootofunity()
{   for (uint64_t k=2;;k++)
    {   if (exptmod(k, P-1, P) != 1) continue; // should never happen!
// The next 3 lines verify that no lower power of k will be 1. Ie that
// 1, k, k^2, ... k^LCMlengths is a full length cycle of distinct values.
        if (exptmod(k, (P-1)/2, P) == 1) continue;
        if (exptmod(k, (P-1)/3, P) == 1) continue;
        if (exptmod(k, (P-1)/5, P) == 1) continue;
// The result will be such that whem raised to the power LCMlengths it
// yields 1. This means that for any length L that is a factor of LCMlengths
// then this value r raised to the power (LCMlengths/L) will be a primitive
// Lth root of unity, as required for a length-L fft.
        return exptmod(k, (P-1)/LCMlengths, P);
    }
}

inline constexpr uint64_t omega1 = rootofunity<P1>();   // 0x546e6cc8bf755453
inline constexpr uint64_t omega2 = rootofunity<P2>();   // 0x168f08f8e7
inline constexpr uint64_t omega3 = rootofunity<P3>();   // 0xe

//*************************************************************************
//*************************************************************************
// Next comes support for Chinese Remainder code. This involves using
// and extended GCD algorithm first on (P1,P2) and then on (P1*P2,P3)
// to find key constants needed when the final calculation is to be made.
//*************************************************************************
//*************************************************************************

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

inline constexpr XGCD64 P1_P2(P1, P2);

// now suppose X = a mod P1 and b mod P2 then
//    x = a*P2*P1_P2.x - b*P1*P1_P2.y  [uniquely mod P1*P2]
// or (as in the previous case) with the subtraction done the
// other way round.

struct XGCD128
{   int128 x = 1, y = 0;
    bool x_negated = false;
    CONSTEVAL XGCD128(int128 a, int128 b)
    {   int128 u=1, v=0;
        while (b!=0)
        {   int128 q=a/b;
            int128 temp=a-q*b; a=b; b=temp;
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

inline constexpr uint128 P1xP2 = (uint128)P1*P2;

inline constexpr XGCD128 P1_P2_P3(P1xP2, P3);

// I observe that in the two cases I am using here neither ends up
// with x negated. However the code above shows awareness that that
// situation could arise.

// Now a bit of code that finds given
//    X = a1 mod P1,   a2 mod P2,   a3 mod P3
// and retuns its value split into 3 64-bit digits {hi,mid,lo}

// I need to be able to multiply a 64 bit value by a 128-bit one. This
// is basically "short multiplication" because I view the 128 bit
// number as two 64-bit digits.

inline constexpr void times_64_128(uint64_t a, uint128 b,
                                   uint64_t& hi, uint64_t& mid, uint64_t& lo)
{   uint64_t bhi = static_cast<uint64_t>(b>>64);
    uint64_t blo = static_cast<uint64_t>(b);
    uint128 w1 = (uint128)a*blo;
    lo = static_cast<uint64_t>(w1);
    uint128 w2 = (uint128)a*bhi + (w1>>64);
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
    {   times_64_128(P1, (uint128)P2*P3, hi, mid, lo);
    }
};

inline constexpr P1xP2xP3_t P1xP2xP3;

// I want (a*b)%P1xP2 where all the values are 128-bit integers.
// I had experimented with code to do this on 64-bit inputs but found
// that relying on simple code using g++ or clang++ 128-bit integers
// made better sense, But here I do not have the luxury of letting the
// compiler take the strain! Well that means my previous work was not
// totally in vain.

template <uint128 P>
inline CONSTEVAL int leadingzeros()
{   for (int i=0; i<128; i++)
        if ((P>>(127-i)) == 1) return i;
    return 128;
}

// I want 2^M/P such that it fills all of a 128-bit word.
// Because the plan is that this only gets used at compile-time I will
// not try very hard re performance. Also I will not worry about
// overflow or division by zero.

template <uint128 P>
inline CONSTEVAL uint128 inverse()
{   uint128 phi=static_cast<uint128>(1)<<(128-leadingzeros<P>()), plo=0;
    uint128 q = P;    
    uint128 r = 0;
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

inline constexpr uint128 invP1xP2 = inverse<P1xP2>();

// Multiply a pair of 128-bit values to get a 256 bit result.

inline void times_128(uint128 a, uint128 b, uint128& chi, uint128& clo)
{
    uint64_t ahi = a>>64, alo = a;
    uint64_t bhi = b>>64, blo = b;
    uint128 hh = (uint128)ahi*bhi;
    uint128 hl = (uint128)ahi*blo;
    uint128 lh = (uint128)alo*bhi;
    uint128 ll = (uint128)alo*blo;
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

inline constexpr uint128 times_hi_128(uint128 a, uint128 b)
{   uint64_t ahi = a>>64, alo = a;
    uint64_t bhi = b>>64, blo = b;
    uint128 hi = (uint128)ahi*bhi;
    uint128 mid1 = ((uint128)ahi*blo)>>64;
    uint128 mid2 = ((uint128)bhi*alo)>>64;
    return hi + mid1 + mid2;
} 

// Form (a*b) mod P=P1*P2  where a and b are both 128-bit values -
// taking advantage of the fact that the value of P is known and has
// a couple of high zero bits.

template <uint128 P>
inline constexpr uint128 timesmod(uint128 a, uint128 b)
{   uint128 phi, plo;
    times_128(a, b, phi, plo);
// Here a and b each have (at least) leadingzeros<P>() leading zeros and so
// their product has at least 2*leadingzeros<P>(). So if I shift the 256-bit
// version of the product right by 128-2*leadingzeros<P>() I should get a
// value that fits into 128 bits and that has as much accuracy as I can. 
    uint128 ptop = phi<<(2*leadingzeros<P>()) |
                    (plo>>(128-2*leadingzeros<P>()));
    uint128 quot = times_hi_128(ptop, invP1xP2);
// I now want to set rem = a*b - quot*P1xP2
// Well quot needs shifting to allow for that fact that invP1xP2 had
// been shifted up to get extra precision.
    quot >>= (leadingzeros<P>()-1);
    uint128 qhi, qlo;
    times_128(quot, P1xP2, qhi, qlo);
    phi -= qhi;
    uint128 r = plo - qlo;
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

inline void chinese_remainder(uint64_t a1, uint64_t a2, uint64_t a3,
                              uint64_t& hi, uint64_t& mid, uint64_t& lo)
{
// First find a1a2 which will be a1 mod P1 and a2 mod P2
    uint128 a1a2A = (((uint128)a2*P1_P2.x)%P2)*P1;
    uint128 a1a2B = (((uint128)a1*P1_P2.y)%P1)*P2;
    uint128 a1a2;
// In fact I because I am using a fixed set of primes I happen to know
// that x_negated will NOT be set here, but I expect that a good compiler
// will understand that and the redundant code here will not hurt - and
// having it here makes what I write "more honest".
    if (P1_P2.x_negated)
        a1a2 = a1a2B >= a1a2A ? a1a2B - a1a2A
                              : a1a2B + (uint128)P1xP2 - a1a2A;
    else
        a1a2 = a1a2A >= a1a2B ? a1a2A - a1a2B
                              : a1a2A + (uint128)P1xP2 - a1a2B;
// Now the next step is logically the same but looks messier
// because I need to go to 192 bits. Well more pedantically around 170
// would suffice, but that still means I will yse three 64-bit digits.
//
// The logic is
//    p = ((a3*P1_P2_P3.x)%P3)        * (P1*P2); a3 & p1_p2_p3.x both 64 bits
//    q = ((a1a2*P1_P2_P3.y)%(P1*P2)) * P3;   a1a2 & p1_p2_p3.y both 128 bits
//    (p - q) % (P1*P2*P3);

    uint128 temp = a3*P1_P2_P3.x;   // will not overflow because .x is 64-bits
    uint64_t phi, pmid, plo;
    times_64_128(temp%P3, P1xP2, phi, pmid, plo);
// Now for the messier one: I need (a1a2*P1_P2_P3.y) % (P1*P2)
// and all three values involved are 128-bits wide.
    uint128 q1 = timesmod<P1xP2>(a1a2, P1_P2_P3.y);
    uint64_t qhi, qmid, qlo;
    times_64_128(P3, q1, qhi, qmid, qlo);
// Now I need to return p-q  mod P1xP2xP3. Note that both p and q are
// less than P1xP2xP3 so the only correction I can need would be if the
// naive subtraction leaves a negative value.
    hi = phi-qhi;
    mid = pmid-qmid;
    lo = plo-qlo;
    if (mid > pmid) hi--;
    if (lo > plo)
    {   if (mid-- == 0) hi--;
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

//*************************************************************************
//*************************************************************************
// Here is some code that does FFT and multiplication is naive and slow
// ways so I can use those as reference implementations to check the
// "fast" results.
//*************************************************************************
//*************************************************************************

// For validation I will code up classical O(N^2) multiplication so I
// can try random cases and compare fast and slow versions for both
// results and timings.

inline void slowmul(uint64_t* a, size_t lena,
                    uint64_t* b, size_t lenb,
                    uint64_t* c)
{   size_t N = lena+lenb;
    for (size_t i=0; i<N; i++)
        c[i] = 0;
    for (size_t i=0; i<lena; i++)
    {   for (size_t j=0; j<lenb; j++)
        {   uint128 w = (uint128)a[i]*b[j];
            size_t k = i+j;
            while (w != 0)
            {   uint64_t loww = w;
                w >>= 64;
                c[k] += loww;
                if (c[k] < loww) w++; // carry
                k++;
            }
        }
    }
}

// Fourier Transform done in N^2 steps, not used except possibly while
// debugging but still posisbly useful as documentation/reference.

template <uint64_t P, uint64_t omega>
inline void slow_ft(uint64_t* a, size_t N)
{   uint64_t root = exptmod(omega, LCMlengths/N, P);
// Here I have a really simple Fourier Transform (and its inverse)
// coded as simply multiplication of the input vector by a matrix
// whose elements are omega^(i*j). This has to put the transformed
// data in a new vector. This code would work for arbitrary length vectors
// not just powers of 2 so it may be a useful basis for checking when
// I code up more complicated versions.
    uint64_t* temp = new uint64_t[N];
    for (size_t i=0; i<N; i++)
    {   uint64_t w = 0;
        for (size_t j=0; j<N; j++)
            w = plusmod<P>(w, timesmod<P>(a[j], exptmod(root, i*j, P)));
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
    delete [] temp;
}

template <uint64_t P, uint64_t omega>
inline void inverse_slow_ft(uint64_t*a, size_t N)
{   uint64_t root = exptmod(omega, LCMlengths-LCMlengths/N, P);
// Here I have a really simple Fourier Transform (and its inverse)
// coded as simply multiplication of the input vector by a matrix
// whose elements are omega^(i*j). This has to put the transformed
// data in a new vector. This code would work for arbitrary length vectors
// not just powers of 2 so it may be a useful basis for checking other
// (faster) versions.
    uint64_t* temp = new uint64_t[N];
    for (size_t i=0; i<N; i++)
    {   uint64_t w = 0;
        for (size_t j=0; j<N; j++)
            w = plusmod<P>(w, timesmod<P>(a[j], exptmod(root, i*j, P)));
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
    delete [] temp;
}

//*************************************************************************
//*************************************************************************
// Now the Fast Fourier Transform code that us at the heart of all of this.
//*************************************************************************
//*************************************************************************


// Fourier Transforms done in NlogN steps

inline uint64_t w(int k, size_t N, uint64_t* roots)
{   return roots[k%N];
}

// A "fast" Fourier Transform.
//
// In what follows P is the prime I am working modulo and
// baseomega = 1^(1/LCMlengths) is a primitive root of unity such
// that if I want to make a Fourier Transform on a vector of length M
// then the "omega" that I use can be baseomega^(LCMlengths/M).

// Decimation in time.

template <uint64_t P>
inline void butterfly2A(uint64_t& a, uint64_t& b, uint64_t w)
{    uint64_t u = a;
     uint64_t v = timesmod<P>(b, w);
     a = plusmod<P>(u, v);
     b = differencemod<P>(u, v);
}

// A special version for when the root of unity is 1.
template <uint64_t P>
inline void butterfly2A(uint64_t& a, uint64_t& b)
{    uint64_t u = a;
     uint64_t v = b;
     a = plusmod<P>(u, v);
     b = differencemod<P>(u, v);
}

// Here the input vector should be in bit-reverse-counting order
// but the output appears in natural order.

template <uint64_t P>
inline void dit_ft(uint64_t* x, size_t N, uint64_t* roots)
{   for (size_t m=2; m<=N; m=2*m)
    {   for (size_t k=0; k<N; k+=m)
        {
// The first butterfly uses 1 as the power of omega, and so avoids
// a multiplication, so I do it as a separate stage.
            butterfly2A<P>(x[k], x[k+m/2]);
            size_t w = N/m;
            for (size_t j = 1; j<m/2; j++, w+=N/m)
            {   butterfly2A<P>(x[k+j], x[k+m/2+j], roots[w]);
            }
        }
    }
}

// Decimation in Frequency.

// This performs the steps from the above but in reverse
// and in such a manner that it provides an inverse transformation.

// The input vector is presented in natural order but the output
// is generated in bit-reverse-counting order.

template <uint64_t P>
inline void butterfly2B(uint64_t& a, uint64_t& b, uint64_t w)
{   uint64_t u = plusmod<P>(a, b);
    uint64_t v = timesmod<P>(differencemod<P>(a, b), w);
    a = u;
    b = v;
}

template <uint64_t P>
inline void butterfly2B(uint64_t& a, uint64_t& b)
{   uint64_t u = plusmod<P>(a, b);
    uint64_t v = differencemod<P>(a, b);
    a = u;
    b = v;
}

template <uint64_t P>
inline void dif_ft(uint64_t* x, size_t N, uint64_t* roots)
{   for (size_t m=N; m>=2; m=m/2)
    {   for (size_t k=0; k<N; k+=m)
        {   size_t w = N/2;
            for (size_t j = m/2-1; j>=1; j--)
            {   w += N/m;
                butterfly2B<P>(x[k+j], x[k+j+m/2], roots[w]);
            }
// Here the very last step would involve 1 as the power of omega, so I
// separate it off.
            butterfly2B<P>(x[k], x[k+m/2]);
        }
    }
}

//*************************************************************************
//*************************************************************************
// Fast multiplication will compute convolutions using FFT and then
// perform carry operations to leave a product in tidy form.
//*************************************************************************
//*************************************************************************

class FFTParams
{
public:
    int which;    // Index of the prime to be used.
    size_t N;     // Length of all vectors.
    uint64_t* a;  // First input vector .
    uint64_t* b;  // Second input vector.
    uint64_t* c;  // Result is places here.
    uint64_t* w;  // Table of powers of omega, the root of unity to be used.
    FFTParams()
    {   which = -1;
        a = b = c = w = nullptr;
        N = 0;
    }
    FFTParams(int xwhich, size_t xN, uint64_t* xa, uint64_t* xb,
                                     uint64_t* xc, uint64_t* xw)
    {   which = xwhich;
        N = xN;
        a = xa;
        b = xb;
        c = xc;
        w = xw;
    }
};

// For the threads that I use I have two challenges. First each thread
// needs different vectors to work on but my scheme only passed a single
// argument. So I make that argument a structure (FFTParams). And then
// for performance I want to have the prime used in each task passed
// as a template parameter. So I pass in information field called which and
// dispatch on that to code using each value for the template parameters.

template <uint64_t P, uint64_t omega>
inline void useOneModuleT(FFTParams d)
{   uint64_t R = 1, ww = exptmod(omega, LCMlengths/d.N, P);
    d.w[0] = R;
    for (size_t i=1; i<d.N; i++)
        d.w[i] = (R = timesmod<P>(ww, R));
    dif_ft<P>(d.a, d.N, d.w);
    dif_ft<P>(d.b, d.N, d.w);
// Pointwise multiplication
    for (size_t i=0; i<d.N; i++)
        d.c[i] = timesmod<P>(d.a[i], d.b[i]);
    dit_ft<P>(d.c, d.N, d.w);
// There is a stray factor of d.N that I must divide out...
    {   uint64_t R1 = recipmod<P>(d.N);
        for (size_t i=0; i<d.N; i++)
            d.c[i] = timesmod<P>(d.c[i], R1);
    }
}

inline void useOneModulus(FFTParams d)
{   switch (d.which)
    {
    case 1:
        useOneModuleT<P1,omega1>(d);
        break;
    case 2:
        useOneModuleT<P2,omega2>(d);
        break;
    case 3:
        useOneModuleT<P3,omega3>(d);
        break;
    }
}

inline void fftmul(uint64_t* a, size_t lena,
            uint64_t* b, size_t lenb,
            uint64_t* c)
{   size_t N = lena+lenb;
    while ((N & -N) != N) N++;
// Here I round up to a power of 2 in a rather simplistic way. The
// following line may suggest something better.
//      N = static_cast<uint64_t>(1)<<(64-nlz(N-1);
    uint64_t* workspace = new uint64_t[12*N];
    uint64_t* a1 = workspace;
    uint64_t* a2 = workspace+N;
    uint64_t* a3 = workspace+2*N;
    uint64_t* b1 = workspace+3*N;
    uint64_t* b2 = workspace+4*N;
    uint64_t* b3 = workspace+5*N;
    uint64_t* c1 = workspace+6*N;
    uint64_t* c2 = workspace+7*N;
    uint64_t* c3 = workspace+8*N;
    uint64_t* w1 = workspace+9*N;
    uint64_t* w2 = workspace+10*N;
    uint64_t* w3 = workspace+11*N;
// First collect images of a and b modulo each of P1, P2 and P3 and pad
// each out to length N with zeros.
    size_t i;
// The remaindering here might well not be needed because in effect it will
// happen as modular arithmetic on the vector is performed???
    for (i=0; i<lena; i++)
    {   a1[i] = a[i] % P1;
        a2[i] = a[i] % P2;
        a3[i] = a[i] % P3;
    }
    while (i < N)
    {   a1[i] = a2[i] = a3[i] = 0;
        i++;
    }
    for (i=0; i<lenb; i++)
    {   b1[i] = b[i] % P1;
        b2[i] = b[i] % P2;
        b3[i] = b[i] % P3;
    }
    while (i < N)
    {   b1[i] = b2[i] = b3[i] = 0;
        i++;
    }

// There are three little blocks of code here and they could be
// run in parallel. I would expect that doing so would speed the
// whole multiplication up be a factor of almost 3 once absolute costs
// were high enough that synchronization overheads ceased dominating.

    std::vector<FFTParams> subtasks =
    {   FFTParams(1, N, a1, b1, c1, w1),
        FFTParams(2, N, a2, b2, c2, w2),
        FFTParams(3, N, a3, b3, c3, w3)
    };
    runInThreads(subtasks, useOneModulus);


// Use the Chinese Remainder Theorem to turn the modular results back
// into a proper set of values for the convolution, and do some carrying
// operations to turn all that back into the final product.
    uint64_t carry=0, carry1=0, carry2;
// Each component on the convolution will be returned as 3 digits {hi,med,lo}
// So I need to combine these as in
//                        hi0 med0  lo0
//                   hi1 med1  lo1
//              hi2 med2  lo2
// ...
// but the "hi" values are in effect carried from adding up many partial
// products, and the final "hi" is certain to be zero.
    for (i=0; i<lena+lenb; i++)
    {   uint64_t hi, mid, lo;
        chinese_remainder(c1[i], c2[i], c3[i], hi, mid, lo);
        c[i] = lo+carry;
        carry1 += mid;
        carry2 = hi + (carry1<mid);
        if (c[i]<lo)
        {   if (++carry1 == 0) carry2++;
        }
        carry = carry1;
        carry1 = carry2;
    }
    c[i++] = carry;
    assert(carry1 == 0);
    delete [] workspace;
}

//=========================================================================
//=========================================================================
//=========================================================================
//=========================================================================

#ifdef TEST_FFT

// There are people who believe that the next line can fail to provide
// really proper "random" sequences, but for now it suffices.

std::mt19937_64 twister(std::random_device{}());

#include <iostream>

size_t slowLimit = 8192;

void timetest(size_t N, int ntrials)
{   uint64_t* a = new uint64_t[N];
    uint64_t* b = new uint64_t[N];
    uint64_t* c = new uint64_t[2*N];
    uint64_t* cslow = new uint64_t[2*N];

// I use random data as my input.
    for (size_t i=0; i<N; i++)
    {   a[i] = twister();
        b[i] = twister();
        c[i] = c[i+N] = 0;
        cslow[i] = cslow[i+N] = 0;
    }

// I will not do the "slow" multiplcation for large values of N because
// it gets to take more time than it is worth.
    auto tt0 = microseconds();
    auto tt1 = tt0;
    if (N < 8192)
    {   for (int trial=0; trial<ntrials; trial++)
        {   slowmul(a, N, b, N, cslow);
        }
        tt1 = microseconds();
    }
    auto tt2 = microseconds();
    for (int trial=0; trial<ntrials; trial++)
    {   fftmul(a, N, b, N, c);
    }
    auto tt3 = microseconds();

    auto tslow = tt1-tt0,
         tfast = tt3-tt2;
    std::cout << std::setw(6) << N;
    if (tslow != 0)
    {   std::cout << std::setw(12) << tslow
             << " (" << ((double)tslow/(N*N)) << ")";
    }
    else std::cout << std::setw(19) << " ";
    std::cout << std::setw(12) << tfast
         << " (" << ((double)tfast/(N*log(N))) << ")";
    if (tslow != 0) std::cout << "  ratio = " << (tfast/(double)tslow);
    std::cout << "\n";

// Check that classical and fast methods gave the same result.
    if (N < 8192)     // Only check cases where I had done the slow multiply.
        for (int i=2*N-1; i>=0; i--)
    {   if (c[i] != cslow[i])
        {   std::cout << "\n**FAIL** at " << i << "\n";
            abort();
        }
    }

    delete [] a;
    delete [] b;
    delete [] c;
    delete [] cslow;
}

int main(int argc, char* argv[])
{
    size_t N = -1;
    if (argc > 1) N = atoi(argv[1]);

    int ntrials = 50;
    if (argc > 2) ntrials = atoi(argv[1]);

    std::cout << " digits       slow (tt/N*N)      fast (tt/NlogN)\n";

    std::cout << std::fixed << std::setprecision(2);
    if (N != -1u) timetest(N, ntrials);
    else
    {   for (N=4; N<2*slowLimit; N=2*N)
        {   timetest(N, ntrials);
        }
    }
    return 0;
}

#endif // TEST_FFT

// end of fftmod.cpp
