// fftmod.cpp                                     Copyright 2025 A C Norman

// $Id$

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


// The code here uses Fourier Transfroms, or perehaps more pedantically
// the Number Theoretical Transfrom, to multiply large integers. Those
// integers have 64-bit digits.

// To form a*b let N be length(A)+length(B) rounded up. For many presentations
// of FFT multiplication one rounds up to a power of 2. However I will
// handle lengths that are either of the form 2^n or 3*2^n. This reduces
// the amount of padding that can be called for so that in the worst case
// vectors only expand to 1.5 times their original size rather than by a
// full factor of 2.
// I pad each of a and b to length N with zeros. I have five primes Q1-Q5,
// such that each fits in 31-bits and each is a multiple of
// every possible length that I will be using. This limits the length
// of inputs to around 2^19 digits which is a constraint that I am not
// especially worried about given that CSL has a limit at that level.
//
// When P is a prime I form the FFT of a and of b, do pairwise multiplication
// and an inverse FFT all mod P. The result will be an image of my product
// modulo P. Using the Chinese Remainder Theorem I can then re-create
// digits modulo the product of the Qi. That is big enough for everything
// to be correct in Z. Because those reconstructions are about 150 bits long
// I have some carry operations before I end up with what should be the true
// product in a natural form.
//
// I do the multiplication modulo my primes in parallel. That increases
// overhead for shortish numbers but really pays of for large enough ones.
// And I expect the cross over point to be broadly in line with where
// FFT-based methods become viable anyway.
//
// Hmmm could I use SIMD for the parallelism? One wants to run 5 tasks
// and parallel and the key challenge will be steps that go (u*v)%P where
// each of those values are 32-bits but the intermediate product is 64-bits
// wide.

// I implement three multiplication schemes here while I test. One is simple
// classical O(N^2) and that can provide a baseline for comparing both
// results and timings. The next uses Fourier Transforms over the prime
// fields but computes them using simple multiplication by matrix with
// elements omega^(i*j). That provides no speed advantage but will show
// the values that should emerge from transforms - and that version
// appears to work (thereby validating both the structure of the code and
// details of the modular arithmetic). Such a method will work with
// any size vector where I can provide a suitable root of unity, not just
// powers of 2 and 3.
// The final one is the "fast" version which should run in time proportional
// to N*logN.

// Well: the slow versions will only be included if you compile with
// "-DTESTFFT".

#ifndef ARITHLIB_VERSION
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
#include "lvector.base.h"

// For testing I will want...
#include <cmath>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <atomic>
#include <cassert>
#include "fftutils.cpp"
using namespace fftutils;
#endif // ARITHLIB_VERSION

//*************************************************************************
//*************************************************************************
// Here is some code that does FFT and multiplication is naive and slow
// ways so I can use those as reference implementations to check the
// "fast" results.
//*************************************************************************
//*************************************************************************


// For validation I will code up classical O(N^2) multiplication so I
// can try random cases and compare fast and slow versions for both
// results and timings. The classical multiplication I have in arithlin is
// distinctly faster than this, but has much longer code with loops
// unrolled etc.

static void slowmul(ConstDigitPtr a, size_t lena,
                    ConstDigitPtr b, size_t lenb,
                    DigitPtr c)
{   size_t N = lena+lenb;
    for (size_t i=0; i<N; i++)
        c[i] = 0;
    for (size_t i=0; i<lena; i++)
    {   for (size_t j=0; j<lenb; j++)
        {   uint128_t w = (uint128_t)a[i]*b[j];
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

#ifdef TESTFFT

// The Fourier transforms here will work on 32-bit values...

// Here I have a really simple Fourier Transform (and its inverse)
// coded as simply multiplication of the input vector by a matrix
// whose elements are omega^(i*j). This has to put the transformed
// data in a new vector. This code would work for arbitrary length vectors
// not just powers of 2 so it may be a useful basis for checking when
// I code up more complicated versions.

template <Digit32 P, Digit32 omega>
static void slow_ft(DigitPtr32 a, size_t N)
{   Digit32 root = exptmod(omega, (int32_t)(LCMlengths/N), P);
    stkvector<Digit32> temp(N);
    for (size_t i=0; i<N; i++)
    {   Digit32 w = 0;
        for (size_t j=0; j<N; j++)
            w = plusmod<P>(w, timesmod<P>(a[j], exptmod(root, (int32_t)((i*j)%N), P)));
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
}

// Inverse of the above. This is just the same code save it uses
// the reciprocal of the root of unity used in the first version.

template <Digit32 P, Digit32 omega>
static void inverse_slow_ft(DigitPtr32 a, size_t N)
{   Digit32 root = exptmod(omega, (int32_t)(LCMlengths-LCMlengths/N), P);
    stkvector<Digit32> temp(N);
    for (Digit32 i=0; i<N; i++)
    {   Digit32 w = 0;
        for (size_t j=0; j<N; j++)
            w = plusmod<P>(w, timesmod<P>(a[j], exptmod(root, (int32_t)((i*j)%N), P)));
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
}

#endif // TESTFFT

//*************************************************************************
//*************************************************************************
// Now the Fast Fourier Transform code that us at the heart of all of this.
//*************************************************************************
//*************************************************************************

#if defined __x86_64__ && defined __GNUC__
#pragma GCC push_options

#define DIF_FT generic_dif_ft
#define DIT_FT generic_dit_ft
#include "fftkernel.cpp"
#undef DIF_FT
#undef DIT_FT

#define DIF_FT sse4_dif_ft
#define DIT_FT sse4_dit_ft
#pragma GCC target ("sse4.2")
#include "fftkernel.cpp"
#undef DIF_FT
#undef DIT_FT

#define DIF_FT avx_dif_ft
#define DIT_FT avx_dit_ft
#pragma GCC target ("avx")
#include "fftkernel.cpp"
#undef DIF_FT
#undef DIT_FT

#pragma GCC pop_options

// Dispatch into the potentially SIMD-optimised version of the FFT code.

template <uint32_t P, uint32_t cube_root>
static void dif_ft(DigitPtr32 x, size_t N, DigitPtr32 omegas)
{   if (avx_available) avx_dif_ft<P,cube_root>(x, N, omegas);
    else if (sse4_available) sse4_dif_ft<P,cube_root>(x, N, omegas);
    else generic_dif_ft<P,cube_root>(x, N, omegas);
}

template <uint32_t P, uint32_t cube_root>
static void dit_ft(DigitPtr32 x, size_t N, DigitPtr32 omegas)
{   if (avx_available) avx_dit_ft<P,cube_root>(x, N, omegas);
    else if (sse4_available) sse4_dit_ft<P,cube_root>(x, N, omegas);
    else generic_dit_ft<P,cube_root>(x, N, omegas);
}

#else // Intel

// For all platforms other than x86_64 I just have a single version of the code.
// Perhaps the most important case will be ARM, where "neon" has provided 128-bit
// SIMD on all machines that are at all liabnle to be relevant.

#define DIF_FT dif_ft
#define DIT_FT dit_ft
#include "fftkernel.cpp"
#undef DIF_FT
#undef DIT_FT

#endif // Intel


#ifdef TESTFFT

// This supposes that you will be doing an FFT on a vector of length N,
// and that decimation will be by 3 and 2 as necessary. It adjusts
// an index n in a way that if N is a power of 2 it just bit-reverses it
// and if there us a factor of 3 that is handled that way that is necessary.
// It is coded so it would handle an arbitrary power of 3 even though that
// is more than is required here.

int32_t radix_reverse(uint32_t n, uint32_t N)
{   uint32_t r = 0;
    while (N != 1)
    {   if (N%2 == 0)
        {   r = 2*r + n%2;
            N /= 2;
            n /= 2;
        }
        else if (N%3 == 0)
        {   r = 3*r + n%3;
            N /= 3;
            n /= 3;
        }
        else abort();  // Bad length!
    }
    return r;
}

int32_t radix_reverse2(uint32_t n, uint32_t N)
{   uint32_t r = 0;
    while (N != 1)
    {   if (N%3 == 0)
        {   r = 3*r + n%3;
            N /= 3;
            n /= 3;
        }
        else if (N%2 == 0)
        {   r = 2*r + n%2;
            N /= 2;
            n /= 2;
        }
        else abort();  // Bad length!
    }
    return r;
}

// Reorder the entries in the vector a using radix_reverse()l.

void reverse_vec(DigitPtr32 a, uint32_t N)
{   stkvector<Digit> newer(N);
    for (uint32_t i=0; i<N; i++)
        newer[i] = a[radix_reverse2(i, N)];
    for (uint64_t i=0; i<N; i++)
        a[i] = newer[i];
}

// For debugging purposes I would like code that checks if one vector
// holds values that are a permutation of the ones in a second.

const size_t maxN = 512;
uint32_t shuffle[maxN];

void findperm(uint32_t* a, uint32_t* b, uint32_t N, uint32_t P)
{   for (uint32_t i=0; i<N; i++) shuffle[i] = 0x999999;
    for (uint32_t i=0; i<N; i++)
    {   for (uint32_t j=0; j<N; j++)
            if (a[i] == b[j]) shuffle[i] = j;
    }
}

// std::random_device does not provide as much randomness as one might
// ideally like - and it is not even guaranteed to deliver any. However
// its use should mean that successive tests runs here vary.

std::mt19937_64 twister(std::random_device{}());
[[gnu::used]] inline bool valid(size_t N)
{   while (N%2 == 0) N /= 2;
    return N==1 || N==3;
}

int main()
{   Digit32 afft[maxN], aref[maxN], asave[maxN],
            omegas[maxN], inv_omegas[maxN];


    for (size_t N=2; N<=maxN; N++) if (valid(N))
    {   std::cout << "\n\nStart on " << N << "\n";
        uint32_t y = exptmod(omega1, (int32_t)(LCMlengths/N), Q1);
        uint32_t z = 1;
        inv_omegas[0] = omegas[0] = 1;
        for (int i=1; i<N; i++)
        {   z = timesmod<Q1>(z, y);
            inv_omegas[N-i] = z;
            omegas[i] = z;
        }
        assert(timesmod<Q1>(z, y) == 1);

        for (int i=0; i<N; i++)
            asave[i] = aref[i] = afft[i] = twister()%Q1;

// here asave[], aref[] and afft[] are three copies of the input. aref[] and
// afft[] will become a referennce Fourier Transform and the output from
// my fast code (initially at least in scrambled order). asave[] will remain
// as the original input. In due course when I have the inverse transform
// implemented I compare whether a round trip return to those values.

        inverse_slow_ft<Q1,omega1>(aref, N);
        constexpr uint32_t cube_root1b = exptmod(omega1, 2*LCMlengths/3, Q1);
        dif_ft<Q1,cube_root1b>(afft, (uint32_t)N, inv_omegas);
        findperm(afft, aref, N, Q1);
        reverse_vec(afft, N);
        for (size_t i=0; i<N; i++)
        {   if (aref[i] == afft[i]) continue;
            std::cout << "Oops at " << i << " with N=" << N << "\n";
            std::exit(1);
        }
// This first check has compared the values computed using my "fast"
// "dif_ft()" code with ones prepared using a slow and simple matrix
// multiplication. This is intended to check that what I have is actually
// a fourier transform.
        std::cout << "OK on vector of length " << N << "\n";
// I will try the classical inverse to check things...
// Put back at start posn,
        for (int i=0; i<N; i++)
            afft[i] = asave[i];
// Repear dif_ft()
        dif_ft<Q1,cube_root1b>(afft, (uint32_t)N, inv_omegas);
// now do classical inverse...
        reverse_vec(afft, N);
        slow_ft<Q1,omega1>(afft, N);
        for (int i=0; i<N; i++)
        {   if (timesmod<Q1>((Digit32)N, asave[i]) != afft[i])
            {   std::cout << "After classical, oops at " << i << "\n";
                for (size_t j=0; j<N; j++)
                    afft[j] = timesmod<Q1>((Digit32)N, afft[j]);
                prinvec("Input        ", afft, N, Q1);
                prinvec("Expected     ", asave, N, Q1);
                std::exit(1);
            }
        }


// Now I will use "dit_ft()" to convert back and see if I get to where I
// started.
        for (size_t i=0; i<N; i++)
            afft[i] = asave[i];
// Repeat the dif_ft() step
        dif_ft<Q1,cube_root1b>(afft, (uint32_t)N, omegas);
        constexpr uint32_t cube_root1a = exptmod(omega1, LCMlengths/3, Q1);
        dit_ft<Q1,cube_root1a>(afft, (uint32_t)N, inv_omegas);
        std::cout << "Checking for N=" << N << "\n";
        for (int i=0; i<N; i++)
        {   if (timesmod<Q1>((Digit32)N, asave[i]) != afft[i])
            {   std::cout << "Oops at " << i << "\n";
                for (size_t j=0; j<N; j++)
                    asave[j] = timesmod<Q1>((Digit32)N, asave[j]);
                prinvec("Input        ", aref, N, Q1);
                prinvec("Expected     ", asave, N, Q1);
                prinvec("My result    ", afft, N, Q1);

                std::exit(1);
            }
        }

    }

    return 0;
}

#endif

// Fourier Transforms done in NlogN steps

//*************************************************************************
//*************************************************************************
// Fast multiplication will compute convolutions using FFT and then
// perform carry operations to leave a product in tidy form.
//*************************************************************************
//*************************************************************************

class FFTParams
{
public:
    int which;       // Index of the prime to be used.
    size_t N;        // Length of all vectors.
    ConstDigitPtr a;        // First input vector .
    ConstDigitPtr b;        // Second input vector.
    size_t lena;
    size_t lenb;
    DigitPtr32 ws;     // workspace and result.
    FFTParams()
    {   which = -1;
        a = b = nullptr;
        lena = lenb = 0;
        ws = nullptr;
        N = 0;
    }
    FFTParams(int which, size_t N,
              ConstDigitPtr a, ConstDigitPtr b,
              size_t lena, size_t lenb,
              DigitPtr32 ws)
    {   this->which = which;
        this->N = N;
        this->a = a;
        this->b = b;
        this->lena = lena;
        this->lenb = lenb;
        this->ws = ws;
    }
};

// For the threads that I use I have two challenges. First each thread
// needs different vectors to work on but my scheme only passed a single
// argument. So I make that argument a structure (FFTParams). And then
// for performance I want to have the prime used in each task passed
// as a template parameter. So I pass in information field called which and
// dispatch on that to code using each value for the template parameters.
// This is liable to lead to 5 copies of the FFT code getting created by
// template expansion with each of the 5 primes I use. 

template <Digit32 P, Digit32 omega>
static void useOneModulus1(FFTParams& d)
{   size_t N = d.N;
    DigitPtr32 a = d.ws;
    DigitPtr32 b = d.ws+N;
    DigitPtr32 omegas = d.ws+2*N;
    DigitPtr32 inv_omegas = d.ws+3*N;
    size_t i;
// The remaindering here reduced 64-bit digits in the input to 32- bit
// modular images.
    for (i=0; i<d.lena; i++) a[i] = d.a[i] % P;
    while (i < N) a[i++] = 0;
    for (i=0; i<d.lenb; i++)b[i] = d.b[i] % P;
    while (i < N) b[i++] = 0;
#ifdef PRINT
    prinvec("a32", a, N);
    prinvec("b32", b, N);
#endif
    Digit32 R = 1, ww = exptmod(omega, (int32_t)(LCMlengths/d.N), P);
    inv_omegas[0] = omegas[0] = 1;
    for (size_t i=1; i<N; i++)
        inv_omegas[d.N-i] = omegas[i] = (R = timesmod<P>(ww, R));
    constexpr Digit32 cube_root1 = exptmod(omega, LCMlengths/3, P);
    constexpr Digit32 cube_root2 = exptmod(omega, 2*LCMlengths/3, P);
    dif_ft<P, cube_root1>(a, N, omegas);
    dif_ft<P, cube_root1>(b, N, omegas);
// Pointwise multiplication
    for (size_t i=0; i<N; i++)
        a[i] = timesmod<P>(a[i], b[i]);
#ifdef PRINT
    prinvec("pairwise", a, N);
#endif
    dit_ft<P,cube_root2>(a, N, inv_omegas);
#ifdef PRINT
    prinvec("dit_ft", a, N);
#endif
// There is a stray factor of N that I must divide out... Well I
// only really need to do this as far as lena+lenb... 
    Digit32 R1 = recipmod<P>((Digit32)N);
    for (size_t i=0; i<N; i++)
        a[i] = timesmod<P>(a[i], R1);
#ifdef PRINT
    prinvec("r32", a, N);
#endif
}

static void useOneModulus(FFTParams d)
{   switch (d.which)
    {
    case 1:
        useOneModulus1<Q1,omega1>(d);
        break;
    case 2:
        useOneModulus1<Q2,omega2>(d);
        break;
    case 3:
        useOneModulus1<Q3,omega3>(d);
        break;
    case 4:
        useOneModulus1<Q4,omega4>(d);
        break;
    case 5:
        useOneModulus1<Q5,omega5>(d);
        break;
    }
}

template <bool parallel=true>
static void fftmul(ConstDigitPtr a, size_t lena,
                   ConstDigitPtr b, size_t lenb,
                   DigitPtr c)
{
    size_t N = roundUp23(lena+lenb);
// Grab all the workspace I need. It looks like a lot! But note that
// these are vectors of 32-bit numbers (modulo one of my primes) rather than
// 64-bits, so it is not quite as bad as it looks! I need all this because
// I will work on 5 modular images in parallel and each will need their own
// data and workspace.
    stkvector<Digit32> workspace(20*N);
    DigitPtr32 ws1 = workspace+0*N;
    DigitPtr32 ws2 = workspace+4*N;
    DigitPtr32 ws3 = workspace+8*N;
    DigitPtr32 ws4 = workspace+12*N;
    DigitPtr32 ws5 = workspace+16*N;
    std::vector<FFTParams> subtasks =
    {   FFTParams(1, N, a, b, lena, lenb, ws1),
        FFTParams(2, N, a, b, lena, lenb, ws2),
        FFTParams(3, N, a, b, lena, lenb, ws3),
        FFTParams(4, N, a, b, lena, lenb, ws4),
        FFTParams(5, N, a, b, lena, lenb, ws5)
    };
#ifdef PRINT
    prinvec("a", a, lena);
    prinvec("b", b, lenb);
#endif
    runInThreads<parallel>(subtasks, useOneModulus);
// The product mod Q1 is left on ws1 etc.

// Use the Chinese Remainder Theorem to turn the modular results back
// into a proper set of values for the convolution, and do some carrying
// operations to turn all that back into the final product.
    uint64_t carry=0, carry1=0, carry2;
// Each component on the convolution will be reconstructed as a value with
// up to 150 bits represented as 3 digits {hi,med,lo} so to form a proper
// final result I will need to combine these as in
//                        hi0 med0  lo0
//                   hi1 med1  lo1
//              hi2 med2  lo2
// ...
// but the "hi" values are in effect carried from adding up many partial
// products, and the final "hi" is certain to be zero. Note that I only
// need to do this for a number of places set by the original input numbers,
// not all the way out to the padded value N.
    size_t i;
    for (i=0; i<lena+lenb; i++)
    {   uint64_t hi, mid, lo;
#ifdef PRINT
        prinvec("ws1", ws1, N);
        prinvec("ws2", ws2, N);
        prinvec("ws3", ws3, N);
        prinvec("ws4", ws4, N);
        prinvec("ws5", ws5, N);
#endif
        chinese_remainder(ws1[i], ws2[i], ws3[i], ws4[i], ws5[i], hi, mid, lo);
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
    if (carry1 != 0)
        std::cout << "Bad carry = " << carry1 << "\n";;
}

// end of fftmod.cpp
