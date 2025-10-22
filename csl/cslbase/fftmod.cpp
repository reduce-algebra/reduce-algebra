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
#include "lvector.base.h"

// For testing I will want...
#include <cmath>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <atomic>
#include <cassert>

#ifndef ARITHLIB_VERSION
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
// results and timings.

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

// Fourier Transform done in N^2 steps, not used except possibly while
// debugging but still posisbly useful as documentation/reference.

template <uint64_t P, uint64_t omega>
static void slow_ft(DigitPtr a, size_t N)
{   uint64_t root = exptmod(omega, LCMlengths/N, P);
// Here I have a really simple Fourier Transform (and its inverse)
// coded as simply multiplication of the input vector by a matrix
// whose elements are omega^(i*j). This has to put the transformed
// data in a new vector. This code would work for arbitrary length vectors
// not just powers of 2 so it may be a useful basis for checking when
// I code up more complicated versions.
    stkvector<Digit> temp(N);
    for (size_t i=0; i<N; i++)
    {   uint64_t w = 0;
        for (size_t j=0; j<N; j++)
            w = plusmod<P>(w, timesmod<P>(a[j], exptmod(root, i*j, P)));
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
}

template <uint64_t P, uint64_t omega>
static void inverse_slow_ft(DigitPtr a, size_t N)
{   uint64_t root = exptmod(omega, LCMlengths-LCMlengths/N, P);
// Here I have a really simple Fourier Transform (and its inverse)
// coded as simply multiplication of the input vector by a matrix
// whose elements are omega^(i*j). This has to put the transformed
// data in a new vector. This code would work for arbitrary length vectors
// not just powers of 2 so it may be a useful basis for checking other
// (faster) versions.
    stkvector<Digit> temp(N);
    for (size_t i=0; i<N; i++)
    {   uint64_t w = 0;
        for (size_t j=0; j<N; j++)
            w = plusmod<P>(w, timesmod<P>(a[j], exptmod(root, i*j, P)));
        temp[i] = w;
    }
    for (size_t i=0; i<N; i++)
        a[i] = temp[i];
}

//*************************************************************************
//*************************************************************************
// Now the Fast Fourier Transform code that us at the heart of all of this.
//*************************************************************************
//*************************************************************************


// Fourier Transforms done in NlogN steps

// A "fast" Fourier Transform.
//
// In what follows P is the prime I am working modulo and
// baseomega = 1^(1/LCMlengths) is a primitive root of unity such
// that if I want to make a Fourier Transform on a vector of length M
// then the "omega" that I use can be baseomega^(LCMlengths/M).

// Decimation in time.

template <uint64_t P>
static void butterfly2A(uint64_t& a, uint64_t& b, uint64_t w)
{    uint64_t u = a;
     uint64_t v = timesmod<P>(b, w);
     a = plusmod<P>(u, v);
     b = differencemod<P>(u, v);
}

// A special version for when the root of unity is 1.
template <uint64_t P>
static void butterfly2A(uint64_t& a, uint64_t& b)
{    uint64_t u = a;
     uint64_t v = b;
     a = plusmod<P>(u, v);
     b = differencemod<P>(u, v);
}

// Here the input vector should be in bit-reverse-counting order
// but the output appears in natural order.

template <uint64_t P>
static void dit_ft(DigitPtr x, size_t N, DigitPtr roots)
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
static void butterfly2B(uint64_t& a, uint64_t& b, uint64_t w)
{   uint64_t u = plusmod<P>(a, b);
    uint64_t v = timesmod<P>(differencemod<P>(a, b), w);
    a = u;
    b = v;
}

template <uint64_t P>
static void butterfly2B(uint64_t& a, uint64_t& b)
{   uint64_t u = plusmod<P>(a, b);
    uint64_t v = differencemod<P>(a, b);
    a = u;
    b = v;
}

template <uint64_t P>
static void dif_ft(DigitPtr x, size_t N, DigitPtr roots)
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
    int which;        // Index of the prime to be used.
    size_t N;         // Length of all vectors.
// Note that at this level the inputs to the multiplication process
// get trashed. THis is OK because they are copies of the original input
// padded to length N.
    DigitPtr a;       // First input vector .
    DigitPtr b;       // Second input vector.
    DigitPtr c;       // Result is places here.
    DigitPtr w;       // Table of powers of omega, the root of unity to be used.
    FFTParams()
    {   which = -1;
        a = b = c = w = nullptr;
        N = 0;
    }
    FFTParams(int xwhich, size_t xN, DigitPtr xa, DigitPtr xb,
                                     DigitPtr xc, DigitPtr xw)
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
static void useOneModuleT(FFTParams d)
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

static void useOneModulus(FFTParams d)
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

static void fftmul(ConstDigitPtr a, size_t lena,
                   ConstDigitPtr b, size_t lenb,
                   DigitPtr c)
{   size_t N = lena+lenb;
    while ((N & -N) != N) N++;
// Here I round up to a power of 2 in a rather simplistic way. The
// following line may suggest something better.
//      N = static_cast<uint64_t>(1)<<(64-nlz(N-1);
    stkvector<Digit> workspace(12*N);
    DigitPtr a1 = workspace;
    DigitPtr a2 = workspace+N;
    DigitPtr a3 = workspace+2*N;
    DigitPtr b1 = workspace+3*N;
    DigitPtr b2 = workspace+4*N;
    DigitPtr b3 = workspace+5*N;
    DigitPtr c1 = workspace+6*N;
    DigitPtr c2 = workspace+7*N;
    DigitPtr c3 = workspace+8*N;
    DigitPtr w1 = workspace+9*N;
    DigitPtr w2 = workspace+10*N;
    DigitPtr w3 = workspace+11*N;
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
}

// end of fftmod.cpp
