// ftmod.cpp                                      Copyright 2025 A C Norman

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



// This is code that I am working on and that is not yet either complete
// or debugged, but when sorted I expect to merge it in with "arithlib".
// It is for multiplying (large) numbers using the following scheme:
//
// To form a*b let N be length(A)+length(B) rounded up. For many presentations
// of FFT multiplication one rounds up to a power of 2. Here I go up to the
// next integer that is a power of 2 possibly multiplied by 3,9, 27 or 81
// and 5, 25, 125. With those options the passing required is limited to
// about 10% rather than a factor of 2, and my hope is that that will
// balance out the extra complication of the FFT on a slightly more
// composite length. But the code also provides other padding options so
// that I will be able to compare.
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
// In arithlib I already do the three subsidiary multiplications involved
// in (the top level decomposition of) Karatsuba in separate threads so that
// they are performed in parallel. In due course I intend to do the same
// here with the three modular FFT-based multiplications.

// I have three multiplication schemes here while I test. One is simple
// classical O(N^2) and that can provide a baseline for comparing both
// results and timings. The next uses Fourier Transforms over the prime
// fields but computes them using simple multiplication by matrix with
// elements omega^(i*j). That provides no speed advantage but will show
// the values that should emerge from transforms - and that version
// appears to work (thereby validating both the structure of the code and
// details of the modular arithmetic).
// The final one is the "fast" version which should run in time proportional
// to NlogN. FFT experts have developed a large range of optimizations that
// I have not implemented so my FFT is not going to be the very fastest
// possible - there is liable to be scope for rework there at a later
// stage.

// As of 20/08/2025 the code now passes some tests that compare the
// output from simple multiplication with that using FFT, and timimgs
// show that for the versions of each I have here that the break-even
// point for FFT is about multiplying a pair of 1000 digit (well that is
// 64-bit digits, so that is around 20000 decimals). I find that reasonably
// in line with my expectations. 

// When this goes into arithlib it will collect the proper BSD license
// statement - but that is how I view its status right now. This is
// checked in to sourceforge because I think there is enough working code
// in it to be of interest and because I want a secure copy somewhere. And
// to encourage me to keep going oon it and on arithlib.
//
// This is going to need tidying up, more testing and then consolidating
// into arithlib. But it may still be of interest to some as a freestanding
// illustration of the technology. 
//
//            Arthur Norman



#include <cstdint>
#include <iostream>
#include <iomanip>
#include <bit>

// For testing I will want...
#include <cmath>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <atomic>
#include <cassert>

using namespace std;    // If I am keen I will remove this at some stage
                        // and put explicit "std::" prefixes where needed.


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
#define CONST consteval
#else
#define CONST constexpr
#endif

// I find the extreme generality of the C++ <chrono> scheme rather
// heavy - so here I wrap it up to give me a simple function that
// reports microseconds used since this program was started. The
// length of the lines here with multiple instances of "::" illustrates
// what is involved!

auto basetime = std::chrono::high_resolution_clock::now();

uint64_t microseconds()
{   auto tt = std::chrono::high_resolution_clock::now() - basetime;
    return std::chrono::duration_cast<std::chrono::microseconds>(tt).count();
}

// C++ does not (as a ammer of its standard) support sending 128-bit
// integers to an output stream. So here I have a little function that
// ts to convert from such an integer to a string so I can print it.

char* hex(uint128 a)
{   static char str[40];
    for (int i=31; i>=0; i--)
    {   str[i] = "0123456789abcdef"[a&0xf];
        a >>= 4;
    }
    str[32] = 0;
    return str;
}

char* dec(uint128 a)
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

// for debugging it is nice to be able print out vectors...

void prinvec(const char* s, uint64_t* v, int n)
{   cout << s;
    if (n > 10) n = 10; // to limit printout!
    for (size_t i=0; i<n; i++)
        cout << " " << v[i];
    cout << "\n";
}

void prinvec(const char* s, uint64_t w, uint64_t* v, int n)
{   cout << s << " " << w << ":";
    if (n > 10) n = 10; // to limit printout!
    for (size_t i=0; i<n; i++)
        cout << " " << v[i];
    cout << "\n";
}

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
// For the product I intend to go
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

// So first I will have a pile of compile-time-executed code that selects
// primes and yields associated constants.

// Form (a+b) % N where all three inputs are 64-bit unsigned integers
// and a and b are both less than N. Annd then for (a-b) % N.

constexpr uint64_t plusmod(uint64_t a, uint64_t b, uint64_t N)
{   uint64_t c = a + b;
    return c >= N ? c-N : c;
}

constexpr uint64_t differencemod(uint64_t a, uint64_t b, uint64_t N)
{   if (a >= b) return a-b;
    else return (a+N)-b;
}

// Form (a*b) % N where all three inputs are 64-bit unsigned integers
// and a and b are both less than N.

constexpr uint64_t timesmod(uint64_t a, uint64_t b, uint64_t N)
{   return (uint64_t)(((uint128)a * b) % N);
}

// Compute x^n mod N where all values are 64 bits.

constexpr uint64_t exptmod(uint64_t x, uint64_t n, uint64_t N)
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

constexpr uint64_t recipmod(uint64_t a, uint64_t N)
{   int64_t y = 0, x = 1;
    uint64_t m = N;
    while (a > 1)
    {   uint64_t q = a / m;
        uint64_t t = m; m = a - q*m; a = t;
        int64_t t1 = y; y = x - q*y; x = t1;
    }
    if (x < 0) x += N;
    return x;
}

// Use Miller-Rabin with base a to see if it can show that N is
// composite. 

CONST bool miller_rabin_probably_prime(uint64_t a, uint64_t N)
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

CONST bool isprime(uint64_t N)
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

constexpr uint64_t LCMlengths = (3*3*3*3*5*5*5LU) << 44;

CONST uint64_t findP(uint64_t start)
{   uint64_t p = LCMlengths*(start/LCMlengths) + 1;
    while (!isprime(p)) p -= LCMlengths;
    return p;
}

// I start with P1 the first prime below 2^63, then P2 and P3 are the
// next viable ones down from there. Note that P3 is just 1 greater
// than 2^44*3^4*5^3. 
// The primes here are uniquely defined by the constraints
// I have shown above - and so I could write their values out as
// simple literals. But by using constexpr compile-time calculation I
// "show my working" and protect against typos.

constexpr uint64_t P1 = findP(1LU<<63);   // 0x6a4af00000000001
constexpr uint64_t P2 = findP(P1-2);      // 0x2022900000000001
constexpr uint64_t P3 = findP(P2-2);      // 0x0278d00000000001

// For each prime I want a value (omega1,...) that is a primitive
// LCMlength root of unity.

CONST uint64_t rootofunity(uint64_t P)
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

constexpr uint64_t omega1 = rootofunity(P1);   // 0x546e6cc8bf755453
constexpr uint64_t omega2 = rootofunity(P2);   // 0x168f08f8e7
constexpr uint64_t omega3 = rootofunity(P3);   // 0xe

template <uint64_t P, uint64_t omega>
void slow_ft(uint64_t* a, size_t N)
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
            w = plusmod(w, timesmod(a[j], exptmod(root, i*j, P), P), P);
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
    delete [] temp;
}

template <uint64_t P, uint64_t omega>
void inverse_slow_ft(uint64_t*a, size_t N)
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
            w = plusmod(w, timesmod(a[j], exptmod(root, i*j, P), P), P);
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
    delete [] temp;
}

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
    CONST XGCD64(int64_t a, int64_t b)
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

constexpr XGCD64 P1_P2(P1, P2);

// now suppose X = a mod P1 and b mod P2 then
//    x = a*P2*P1_P2.x - b*P1*P1_P2.y  [uniquely mod P1*P2]
// or (as in the previous case) with the subtraction done the
// other way round.

struct XGCD128
{   int128 x = 1, y = 0;
    bool x_negated = false;
    CONST XGCD128(int128 a, int128 b)
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

constexpr uint128 P1xP2 = (uint128)P1*P2;

constexpr XGCD128 P1_P2_P3(P1xP2, P3);

// I observe that in the two cases I am using here neither ends up
// with x negated.

// Now a bit of code that finds given
//    X = a1 mod P1,   a2 mod P2,   a3 mod P3
// and retuns its value split into 3 64-bit digits {hi,mid,lo}

// I need to be able to multiply a 64 bit value by a 128-bit one. This
// is basically "short multiplication" because I view the 128 bit
// number as two 64-bit digits.

constexpr void times_64_128(uint64_t a, uint128 b,
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
    CONST P1xP2xP3_t()
    {   times_64_128(P1, (uint128)P2*P3, hi, mid, lo);
    }
};

constexpr P1xP2xP3_t P1xP2xP3;

// I want (a*b)%P1xP2 where all the values are 128-bit integers.
// I had experimented with code to do this on 64-bit inputs but found
// that relying on simple code using g++ or clang++ 128-bit integers
// made better sense, But here I do not have the luxury of letting the
// compiler take the strain! Well that means my previous work was not
// totally in vain.

template <uint128 P>
CONST int leadingzeros()
{   for (int i=0; i<128; i++)
        if ((P>>(127-i)) == 1) return i;
    return 128;
}

// I want 2^M/P such that it fills all of a 128-bit word.
// Because the plan is that this only gets used at compile-time I will
// not try very hard re performance. Also I will not worry about
// overflow or division by zero.

template <uint128 P>
CONST uint128 inverse()
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

constexpr uint128 invP1xP2 = inverse<P1xP2>();

// Multiply a pair of 128-bit values to get a 256 bit result.

void times_128(uint128 a, uint128 b, uint128& chi, uint128& clo)
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

constexpr uint128 times_hi_128(uint128 a, uint128 b)
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
constexpr uint128 timesmod(uint128 a, uint128 b)
{    uint128 phi, plo;
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
     assert(phi == 0);
// I very much expect that after this {phi,plo} will be my remainder
// and since that is < 2^128 only plo matters.
     if (r > P1xP2) r -= P1xP2;
     return r;
}

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

void chinese_remainder(uint64_t a1, uint64_t a2, uint64_t a3,
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


// Test if N is a suitable size for the restricted FFT that I will
// be using. I will allow it to have factors of up to 3^4*5^3 in
// addition to any power of 2 it likes.

bool valid(size_t N)
{   if (N%5 == 0)
    {   N /= 5;
        if (N%5 == 0)
        {   N /= 5;
            if (N%5 == 0) N /= 5;
        }
    }
    if (N%3 == 0)
    {   N /= 3;
        if (N%3 == 0)
        {   N /= 3;
            if (N%3 == 0)
            {   N /= 3;
                if (N%3 == 0) N /= 3;
            }
        }
    }
    return (N = (N & (-N)));
}

// For validation I will code up classical O(N^2) multiplication so I
// can try random cases and compare fast and slow versions for both
// results and timings.

void slowmul(uint64_t* a, size_t lena,
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

 // Fourier Transforms done in NlogN steps

uint64_t w(int k, size_t N, uint64_t* roots, size_t stride)
{   return roots[(k%N)*stride];
}

// A "fast" Fourier Transform. This will apply to vectors whose length has
// factors 2, 3 and 5 but nothing more. For the 3 and 5 cases it
// does a decimation with recursive code. For powers of 2 it is
// a traditional iterative power-of-two scheme. There will be a range
// of ways that this could be speeded up - there have been very many
// careful studies of just how to improve FFT code. What I have here
// tends to emphasise simplicity.

// It needs some helper functions

// What I have here is a matrix transposition algorithm applied to
// and (N/m)*m matrix. Performing the rearrangement in-place
// and with O(1) space use is a well understood problem. The
// cost is going to be linear. There are cleverer schemes than the
// one I use here both in terms of workspace needed and in making the
// rearrangement cache friendly, but I will use this fairly simple
// scheme for now.

// Note that transpose() would become basically trivial if I was
// willing to use enough extra workspace. 

// The values in my array will be numbers modulo some prime P, and P
// will be such that it does not use its top bit. That lets me
// use that bit as a flag or marker!

constexpr uint64_t topbit = ((uint64_t)1)<<63;

// Transpose a matrix of size (n/m)*m. The intend here is to map eg
//    a1 b2 c3 d4     => abcd 1234
// or aA1 bB2 cC3 dD4 => abcd ABCD 1234

// The array a has total length N. shuffle it in ways that
// use m blocks each of size N/m.

void transpose(uint64_t* a, size_t N, size_t m)
{
// k will scan for an item in a[] that has not yet been moved.
    for (size_t k=1; k<N-1;)
    {   uint64_t saved = a[k];
        size_t start = k, next = k, prev = k;
// Here I have a cycle to traverse.
        while ((next = (m*next) % (N-1)) != start)
        {   a[prev] = a[next] | topbit;
            prev = next;
        }
        a[prev] = saved | topbit;
        while (k<N-1 && (a[k]&topbit)!=0) k++;
    }
// I reset the top bit of every word at the end of this.
    for (size_t i=0; i<N; i++)
        a[i] &= ~topbit;
}

// In what follows P is the prime I am working modulo and
// baseomega = 1^(1/LCMlengths) is a primitive root of unity such
// that if I want to make a Fourier Transform on a vector of length M
// then the "omega" that I use can be baseomega^(LCMlengths/M).

template <uint64_t P, uint64_t baseomage>
extern void fast_ft(uint64_t* x, size_t N, uint64_t* roots, size_t stride);

template <size_t M, uint64_t P, uint64_t baseomega>
void decimate(uint64_t* x, size_t N, uint64_t* roots, size_t stride)
{   size_t K = N/M;
// Shuffle data (in place) so that the values I will need to
// recurse on are in neat blocks of consecutive locations.
    transpose(x, N, M);
// Perform transforms on M blocks each of size N/M
    for (size_t i=0; i<N; i+=K)
        fast_ft<P,baseomega>(x+i, K, roots, M*stride);
// Now do some N/M "butterflies" each of which works on M values
// that fall with stride N/M within the array.
    for (size_t i=0; i<K; i++)
    {   uint64_t temp[M];
        for (size_t j=0; j<M; j++)
        {   temp[j] = 0;
            for (int k=0; k<M; k++)
                temp[j] =
                    plusmod(temp[j],
                            timesmod(x[i+k*K],
                                     w(k*(i+j*K), N, roots, stride),
                                     P),
                            P);
        }
        for (size_t j=0; j<M; j++)
            x[i+j*K] = temp[j];
    }
}

#ifdef SIMPLEST_BIT_REVERSE

// I can do better than this! But starting with a really simple version
// until all is tested makes sense. So view this as for a reference that
// explains what is wanted and a version I can compare the more elaborate
// one against.

size_t bitreverse(size_t i, size_t N)
{   size_t r=0;
    while (N != 1)
    {   r = (r<<1) | (i & 1);
        i = i>>1;
        N = N>>1;
    }
    return r;
}

#else // SIMPLEST_BIT_REVERSE

// My more complicated version involves counting zero bits at one
// end or the other of a word and having a table that shows how the
// numbers from 0 to 255 reverse. So there is really a lot more code
// here than I might really like!

#ifdef _cpp_lib_bitops

// C++20 provides functions for counting zeros. Unlike the GNU intrinsics
// they have defined behaviour when presented with a zero word.

inline int nlz(uint64_t x)
{   return countl_zero(x);
}

inline int ntz(uint64_t x)
{   return countr_zero(x);
}

#elif defined __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too.

inline int nlz(uint64_t x)
{   return x==0 ? 64 : __builtin_clzll(x);
}

inline int ntz(uint64_t x)
{   return x==0 ? 64 : __builtin_ctzll(x);
}

#else // __GNUC__

inline int nlz(uint64_t x)
{   constexpr static struct nlztable_t
    {
    public:
        int8_t tt[67] = {0};
        constexpr nlztable_t()
        {   uint64_t w = -1;
            int i = 0;
            while (w != 0)
            {   tt[w%67] = i;
                w = w>>1;
                i++;
            {
        }
    } nlztable;
    x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    x |= x>>32;
// Now x is a number with all bits up as far as its highest one set, and I
// have achieved that without performing any tests.
    return nlztable.tt[(x & -x) % 67];
}

inline int ntz(uint64_t x)
{
// I count the number of trailing zeros by first ensuring that x has only
// its bottom bit set (by ANDing it with its negative) and then I can
// use a 67 entry table. I fill in the values in that table using a bit
// of compile-time code so as to avoid use of "magic numbers" that could
// hide errors.
    constexpr static struct ntztable_t
    {
    public:
        int8_t tt[67] = {0};
        constexpr ntztable_t()
        {   for (int i=0; i<64; i++)
            {   uint64_t w = ((uint64_t)1)<<i;
                tt[w%67] = i;
            }
        }
    } ntztable;
    return ntztable.tt[(x & -x) % 67];
}

#endif // various versions of ntz()

// N is a power of 2. i<N. Reverse the bits if i. This version works
// for N up to 2^32 and uses a table for reversal within a byte and
// so handles cases from 1-8, 9-16, 17-24 and 25-32 bits separately.

size_t bitreverse(size_t i, size_t N)
{   constexpr static struct byterevtab_t
    {
    public:
        uint8_t tt[256] = {0};
// This sets up (at compile time) a table showing how to bit reverse
// numbers in the range 0-255.
        constexpr byterevtab_t()
        {   for (int i=0; i<256; i++)
            {   int w = i, r = 0;
                for (int j=0; j<8; j++)
                {   r = (r<<1) | (w&1);
                    w = w>>1;
                }
                tt[i] = r;
            }
        }
    } byterevtab;
    int zerobits = ntz(N);
    if (zerobits <= 8)
        return byterevtab.tt[i] >> (8-zerobits);
    else if (zerobits <= 16)
    {   int rev16 = (byterevtab.tt[i&0xff]<<8) | byterevtab.tt[i>>8];
        return rev16 >> (16-zerobits);
    }
    else if (zerobits <= 24)
    {   int rev24 = (byterevtab.tt[i&0xff]<<16) |
                    (byterevtab.tt[(i>>8)&0xff]<<8);
                    byterevtab.tt[i>>16];
        return rev24 >> (24-zerobits);
    }
    else if (zerobits <= 32)
    {   int rev24 = (byterevtab.tt[i&0xff]<<24) |
                    (byterevtab.tt[(i>>8)&0xff]<<16);
                    (byterevtab.tt[(i>>16)&0xff]<<8);
                    byterevtab.tt[i>>24];
        return rev24 >> (32-zerobits);
    }
// I will only support vector lengths that would fit in a 32-bit
// unsigned integer.
    else return 0;
}

#endif // SIMPLEST_BIT_REVERSE

template <uint64_t P, uint64_t baseomega>
void fast_ft(uint64_t* x, size_t N, uint64_t* roots, size_t stride)
{   if (N%5 == 0) decimate<5,P,baseomega>(x, N, roots, stride);
    else if (N%3 == 0) decimate<3,P,baseomega>(x, N, roots, stride);
    else if (N == 1) return;
    else if (N == 2)
    {   uint64_t p = x[0], q = x[1];
        x[0] = plusmod(p, q, P);
        x[1] = differencemod(p, q, P);
    }
    else if (N == 4)
    {   uint64_t p = x[0], q = x[1], r = x[2], s = x[3];
        uint64_t a = plusmod(p, r, P);
        uint64_t b = differencemod(p, r, P);
        uint64_t c = plusmod(q, s, P);
        uint64_t d = differencemod(q, s, P);
        x[0] = plusmod(a, c, P);
        x[1] = plusmod(b, timesmod(roots[stride], d, P), P);
        x[2] = differencemod(a, c, P);
        x[3] = differencemod(b, timesmod(roots[stride], d, P), P);
    }
// Here I demand that the array size is a power of 2.
    else if ((N&(-N)) == N)
    {
// Permute the input vector using a bit-reverse scheme.
        for (size_t i=0; i<N; i++)                 // N
        {   size_t buddy = bitreverse(i,N);
            if (buddy > i) swap(x[i], x[buddy]);
        }
// Now the transform turns into a "simple" nest of loops, which to my
// mind are best copied from where somebody else has got them working!
        for (size_t m=2; m<=N; m=2*m)              // log(N)
        {   uint64_t ww = roots[stride*N/m];
            for (size_t k=0; k<N; k+=m)            // N/m
            {   uint64_t w = 1;
                for (size_t j = 0; j<m/2; j++)     // m/2
                {   uint64_t t = timesmod(w, x[k+j+m/2], P);
                    uint64_t u = x[k+j];
                    x[k+j] = plusmod(u, t, P);
                    x[k+j+m/2] = differencemod(u, t, P);
                    w = timesmod(w, ww, P);
                }
            }
        }
    }
    else
    {   cout << "\nInvalid vector length " << N << "\n";
        abort();
    }
}

// The user-call to fft() starts by allocating a temporary array and
// filling it with powers of the Nth root of unity that is relevant.
// This means that the main code can just look up those values rather than
// needing to re-compute them. The final argument to fft() is a "stride"
// to be applied in this table.

template <uint64_t P, uint64_t baseomega>
void fast_ft(uint64_t* x, size_t N)
{   uint64_t* roots = new uint64_t[N];
    uint64_t ww = exptmod(baseomega, LCMlengths/N, P);
    uint64_t R = 1;
    roots[0] = R;
    for (size_t i=1; i<N; i++)                   // N
        roots[i] = (R = timesmod(ww, R, P));
//    cout << "N=" << N << " baseomega=" << baseomega << " ww = " << ww << "\n";
//    for (size_t i=0; i<N; i++)
//        cout << i << ": " << roots[i] << "\n";
    fast_ft<P,baseomega>(x, N, roots, 1);
    delete[] roots;
}

template <uint64_t P, uint64_t baseomega>
void inverse_fast_ft(uint64_t* x, size_t N)
{   uint64_t* roots = new uint64_t[N];
    uint64_t ww = exptmod(baseomega, LCMlengths-LCMlengths/N, P);
    uint64_t R = 1;
    roots[0] = R;
    for (size_t i=1; i<N; i++)
        roots[i] = (R = timesmod(ww, R, P));
//    cout << "N=" << N << " baseomega=" << baseomega << " ww = " << ww << "\n";
//    for (size_t i=0; i<N; i++)
//        cout << i << ": " << roots[i] << "\n";
    fast_ft<P,baseomega>(x, N, roots, 1);
    delete[] roots;
}

void fastmul(uint64_t* a, size_t lena,
             uint64_t* b, size_t lenb,
             uint64_t* c)
{   size_t N = lena+lenb;
// I offer several options for how the length is rounded up for use with
// FFTs
#if FANCY_LENGTHS
// Here I round up to a size that passes the "valid" test. That sees if the
// only factors of N other than 2 are up to 4 threes and up to 3 fives.
// Using this the amount of padding is kept pretty low.
// This looks pretty inefficient, but its cost is just proportional
// to the number of digits I am working with and the rounding up that
// it does is typically by a small factor - compared with the N*log(N)
// work involving a great deal of modular arithmetic I think tha the cost
// here is not liable to be a big issue.
// A worry about this is that the code (at least as I have it at present)
// that handles FFT on lengths that are not powers of 2 may be slower than
// the purs power of 2 case - especially for fairly short vectors.
    while (!valid(N)) N++;
#elif ONLY_POWERS_OF_TWO
// Here is the FFT traditional scheme or rounding up to the next power
// of two, potentially wasting both space and work when some sizes get
// almost doubled.
    N = static_cast<uint64_t>(1)<<(64-nlz(N-1);
#else
// Now try rounding up so that apart from powers of two there can be a single
// factor of 3. So possible sizes go 2, 3, 4, 6, 8, 12, 16, ... and the
// expansion is at worst by a factor of 1.5 and some informal argument
// suggests that on average it might be around 20%. This might be good value
// because the padding is not too bad and it only needs a single level of
// my (perhaps clumsy) code that decimates by a factor of 3.
    size_t temp1 = static_cast<uint64_t>(1)<<(64-nlz(N-1));
    size_t temp2 = 3*temp1/4;
    N = N<=temp2 ? temp2 : temp1;
#endif
    uint64_t* workspace = new uint64_t[9*N];
    uint64_t* a1 = workspace;
    uint64_t* a2 = workspace+N;
    uint64_t* a3 = workspace+2*N;
    uint64_t* b1 = workspace+3*N;
    uint64_t* b2 = workspace+4*N;
    uint64_t* b3 = workspace+5*N;
    uint64_t* c1 = workspace+6*N;
    uint64_t* c2 = workspace+7*N;
    uint64_t* c3 = workspace+8*N;
// First collect images of a and b modulo each of P1, P2 and P3 and pad
// each out to length N with zeros.
    size_t i;
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
// Take fourier transforms (mod P and in-place) of the inputs.
    slow_ft<P1,omega1>(a1, N);
    slow_ft<P1,omega1>(b1, N);

    slow_ft<P2,omega2>(a2, N);
    slow_ft<P2,omega2>(b2, N);

    slow_ft<P3,omega3>(a3, N);
    slow_ft<P3,omega3>(b3, N);
// Pointwise multiplication 
    for (size_t i=0; i<N; i++)
    {   c1[i] = timesmod(a1[i], b1[i], P1);
        c2[i] = timesmod(a2[i], b2[i], P2);
        c3[i] = timesmod(a3[i], b3[i], P3);
    }
    inverse_slow_ft<P1,omega1>(c1, N);
    inverse_slow_ft<P2,omega2>(c2, N);
    inverse_slow_ft<P3,omega3>(c3, N);

// There is a stray factor of N around here...
    uint64_t R1 = recipmod(N, P1);
    uint64_t R2 = recipmod(N, P2);
    uint64_t R3 = recipmod(N, P3);

    for (size_t i=0; i<N; i++)
    {   c1[i] = timesmod(c1[i], R1, P1);
        c2[i] = timesmod(c2[i], R2, P2);
        c3[i] = timesmod(c3[i], R3, P3);
    }

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

void fastermul(uint64_t* a, size_t lena,
               uint64_t* b, size_t lenb,
               uint64_t* c)
{   size_t N = lena+lenb;
// I offer several options for how the length is rounded up for use with
// FFTs
#if FANCY_LENGTHS
// Here I round up to a size that passes the "valid" test. That sees if the
// only factors of N other than 2 are up to 4 threes and up to 3 fives.
// Using this the amount of padding is kept pretty low.
// This looks pretty inefficient, but its cost is just proportional
// to the number of digits I am working with and the rounding up that
// it does is typically by a small factor - compared with the N*log(N)
// work involving a great deal of modular arithmetic I think tha the cost
// here is not liable to be a big issue.
// A worry about this is that the code (at least as I have it at present)
// that handles FFT on lengths that are not powers of 2 may be slower than
// the purs power of 2 case - especially for fairly short vectors.
    while (!valid(N)) N++;
#elif ONLY_POWERS_OF_TWO
// Here is the FFT traditional scheme or rounding up to the next power
// of two, potentially wasting both space and work when some sizes get
// almost doubled.
    N = static_cast<uint64_t>(1)<<(64-nlz(N-1);
#else
// Now try rounding up so that apart from powers of two there can be a single
// factor of 3. So possible sizes go 2, 3, 4, 6, 8, 12, 16, ... and the
// expansion is at worst by a factor of 1.5 and some informal argument
// suggests that on average it might be around 20%. This might be good value
// because the padding is not too bad and it only needs a single level of
// my (perhaps clumsy) code that decimates by a factor of 3.
    size_t temp1 = static_cast<uint64_t>(1)<<(64-nlz(N-1));
    size_t temp2 = 3*temp1/4;
    N = N<=temp2 ? temp2 : temp1;
#endif
    uint64_t* workspace = new uint64_t[9*N];
    uint64_t* a1 = workspace;
    uint64_t* a2 = workspace+N;
    uint64_t* a3 = workspace+2*N;
    uint64_t* b1 = workspace+3*N;
    uint64_t* b2 = workspace+4*N;
    uint64_t* b3 = workspace+5*N;
    uint64_t* c1 = workspace+6*N;
    uint64_t* c2 = workspace+7*N;
    uint64_t* c3 = workspace+8*N;
// First collect images of a and b modulu each of P1, P2 and P3 and pad
// each out to length N with zeros.
    size_t i;
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
// Take fourier transforms (mod P and in-place) of the inputs.
    fast_ft<P1,omega1>(a1, N);
    fast_ft<P1,omega1>(b1, N);

    fast_ft<P2,omega2>(a2, N);
    fast_ft<P2,omega2>(b2, N);

    fast_ft<P3,omega3>(a3, N);
    fast_ft<P3,omega3>(b3, N);
// Pointwise multiplication 
    for (size_t i=0; i<N; i++)
    {   c1[i] = timesmod(a1[i], b1[i], P1);
        c2[i] = timesmod(a2[i], b2[i], P2);
        c3[i] = timesmod(a3[i], b3[i], P3);
    }
    inverse_fast_ft<P1,omega1>(c1, N);
    inverse_fast_ft<P2,omega2>(c2, N);
    inverse_fast_ft<P3,omega3>(c3, N);

// There is a stray factor of N around here...
    uint64_t R1 = recipmod(N, P1);
    uint64_t R2 = recipmod(N, P2);
    uint64_t R3 = recipmod(N, P3);

    for (size_t i=0; i<N; i++)
    {   c1[i] = timesmod(c1[i], R1, P1);
        c2[i] = timesmod(c2[i], R2, P2);
        c3[i] = timesmod(c3[i], R3, P3);
    }

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

// This is very much over the top! It works to seed the random number
// system with a value unpredictable from run to run based on a
// range of data that is liable to change. It is like this because
// basic_randomness() could in fact be deterministic on some platforms.. 

seed_seq* get_random_seed()
{   uint64_t threadid =
        static_cast<uint64_t>(hash<thread::id>()(this_thread::get_id()));
    random_device basic_randomness;
    uint64_t seed_component_1 = static_cast<uint64_t>(basic_randomness());
    uint64_t seed_component_2 = static_cast<uint64_t>(basic_randomness());
    uint64_t seed_component_3 = static_cast<uint64_t>(basic_randomness());
    uint64_t time_now = static_cast<uint64_t>(time(nullptr));
    uint64_t chrono_now =
        static_cast<uint64_t>(
            chrono::high_resolution_clock::now().
                time_since_epoch().count());
    uint64_t addr = static_cast<uint64_t>(
        reinterpret_cast<uintptr_t>(&seed_component_1));
    static seed_seq random_seed
    {   threadid,
        seed_component_1,
        seed_component_2,
        seed_component_3,
        time_now,
        chrono_now,
        addr
    };
   return &random_seed;
}

mt19937_64 twister(*get_random_seed());

#include <iostream>

void timetest(size_t N, int ntrials)
{   uint64_t* a = new uint64_t[N];
    uint64_t* b = new uint64_t[N];
    uint64_t* c = new uint64_t[2*N];
    uint64_t* cslow = new uint64_t[2*N];

    for (size_t i=0; i<N; i++)
    {   a[i] = twister();
        b[i] = twister();
        c[i] = c[i+N] = 0;
        cslow[i] = cslow[i+N] = 0;
    }

    uint64_t tt0 = microseconds();
    for (int trial=0; trial<ntrials; trial++)
    {   slowmul(a, N, b, N, cslow);
    }
    uint64_t tt1 = microseconds();
    for (int trial=0; trial<ntrials; trial++)
    {   fastermul(a, N, b, N, c);
    }
    uint64_t tt2 = microseconds();

    uint64_t t;
    cout << setw(6) << N
         << setw(12) << (t = tt1-tt0)
         << " (" << (double)t/(N*N) << ")"
         << setw(12) << (t = tt2-tt1)
         << " (" << (double)t/(N*log(N)) << ")"
         << "\n";

// Check that classical and fast methods gave the same result.
    for (int i=2*N-1; i>=0; i--)
    {   if (c[i] != cslow[i])
        {   cout << "\n**FAIL** at " << i << "\n";
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

    int ntrials = 100;
    if (argc > 2) ntrials = atoi(argv[1]);

    cout << " digits       slow (tt/N*N)      fast (tt/NlogN)\n";

    cout << fixed << setprecision(2);
    if (N != -1) timetest(N, ntrials);
    else
    {   for (N=2; N<=8192; N=2*N)
        {   timetest(N, ntrials);
            timetest(3*N/2, ntrials);
        }
    }
    return 0;
}

// end of fftmod.cpp


#ifdef REVCOUNT

// This is code to count in a 32-bit integer but in a bit-reversed order
// It is here because in due course I will want to merge it in with the
// above. But just for now it is a bit of freestanding technology.

#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;


// At the start of some versions of FFT code I need to count from
// 0 to some power of 2 and use a bit-reversed version of the index.
// The code here is to support that in a 32-bit word and almost always
// getting the next count in its reversed for involved just one
// table-lookup and a few shifts.
//
// To use this to count up to 2^N use revstep()>>(32-N).

uint32_t i = 0;      // These need to be encapsulated so the code here
uint32_t revi = 0;   // is merely an explanation of the process.

uint32_t revstep()
{   constexpr static struct byterevtab_t
    {
    public:
        uint8_t tt[256] = {0};
// This sets up (at compile time) a table showing how to bit reverse
// numbers in the range 0-255.
        constexpr byterevtab_t()
        {   for (int i=0; i<256; i++)
            {   int w = i, r = 0;
                for (int j=0; j<8; j++)
                {   r = (r<<1) | (w&1);
                    w = w>>1;
                }
                tt[i] = r;
            }
        }
    } byterevtab;
// Everything down to here has happened at compile time and so does not
// contribute to run-time costs.
    if ((i & 0xff) != 0)
        return revi = (revi&0xffffff) | (byterevtab.tt[i++ & 0xff]<<24);
// What follows happens only one time in 256 ..
    i++; // does not change higher bits of i.
    revi = (revi&0xffff) | (byterevtab.tt[(i >> 8) & 0xff] << 16);
    if ((i & 0xff00) != 0) return revi;
// .. one time in 65536 ..
    revi = (revi&0xff) | (byterevtab.tt[(i >> 16) & 0xff] << 8);
    if ((i & 0xff0000) != 0) return revi;
// one time in 16777216!
    revi = byterevtab.tt[(i >> 24) & 0xff];
    return revi;
}

// To test the above I provide a simple bit-reverse function

uint64_t bitreverse(uint64_t i, uint64_t N)
{   uint64_t r=0;
    while (N != 1)
    {   r = (r<<1) | (i & 1);
        i = i>>1;
        N = N>>1;
    }
    return r;
}

int main(int argc, char* argv[])
{
    for (uint64_t j=0; j<0x100000000; j++)
    {   uint32_t r1 = bitreverse(j, 0x100000000);
        uint32_t r2 = revstep();
        if (r1 != r2)
        {   std::cout << hex << j << ": ref=" << r1 << " step=" << r2 << "\n";
            std::abort();
        }
    }
    std::cout << "OK\n";
}

#endif REVCOUNT