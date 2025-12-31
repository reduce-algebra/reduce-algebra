// ffttest.cpp                                    Copyright 2025 A C Norman

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

#include <cmath>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <atomic>
#include <cassert>

#include "int128_t.h"
#include "acnutil.h"
using namespace acnutil;

using Digit = std::uint64_t;
using SignedDigit = std::int64_t;

#ifdef DEBUG
using DigitPtr = vecpointer<Digit>;
using ConstDigitPtr = vecpointer<const Digit>;
#else // DEBUG
using DigitPtr = Digit*;
using ConstDigitPtr = const Digit*;
#endif // DEBUG

#ifdef NEW
#include "fftmod1.cpp"
#else
#include "fftmod.cpp"
#endif

// C++20 introduces "consteval" which is like "constexpr" save that it
// INSISTS that evaluation happens at compile time. I will use it it
// it is available.

#ifdef __cpp_consteval
#define CONSTEVAL consteval
#else
#define CONSTEVAL constexpr
#endif

// There are people who believe that the next line can fail to provide
// really proper "random" sequences, but for now it suffices. There are
// two limitations. The first and most potentially devastating is that
// random_device() is allowed to be deterministic. I rather expect that
// will only happen on embedded systems and the like, but there is no
// way of knowing here. The second is that a single use of it only returns
// a tiny fraction of the entropy that a proper rendom sequence could
// benefit from. Specifically it returns just an "unsigned int" which will
// often be just 32 bits. Ah well.

std::mt19937_64 twister(std::random_device{}());

using Digit = std::uint64_t;
using SignedDigit = std::int64_t;

#ifdef DEBUG
using DigitPtr = vecpointer<Digit>;
using ConstDigitPtr = vecpointer<const Digit>;
#else // DEBUG
using DigitPtr = Digit*;
using ConstDigitPtr = const Digit*;
#endif // DEBUG

[[gnu::always_inline]]
inline Digit addWithCarry(Digit a1,
                          Digit a2,
                          Digit &r)
{   return static_cast<Digit>(__builtin_add_overflow(a1, a2, &r));
}

// Now the general version with a carry-in. Note that I require that this
// can cope with a carry-in that may be bigger than 1 and that thus the
// carry out can be 0, 1 or 2. So reallt this is an "add 3 values"
// function.

[[gnu::always_inline]]
inline Digit addWithCarry(Digit a1,
                          Digit a2,
                          Digit carry_in,
                          Digit &r)
{   Digit w;
    Digit c1 = addWithCarry(a1, carry_in, w);
    return c1 + addWithCarry(w, a2, r);
}

// subtractWithBorrow does
//     r = a1 - a2 - b_in;
// and returns 1 is there is a borrow out.

[[gnu::always_inline]]
inline Digit subtractWithBorrow(Digit a1,
                                Digit a2,
                                Digit &r)
{   return static_cast<Digit>(__builtin_sub_overflow(a1, a2, &r));
}

[[gnu::always_inline]]
inline Digit subtractWithBorrow(Digit a1,
                                Digit a2,
                                Digit borrow_in,
                                Digit &r)
{   Digit w;
    int b1 = subtractWithBorrow(a1, borrow_in, w);
    return b1 + subtractWithBorrow(w, a2, r);
}


// I want code that will multiply two 64-bit values and yield a 128-bit
// result. The result must be expressed as a pair of 64-bit integers.
// If I have a type "__int128", as will often be the case when using gcc,
// this is very easy to express. Otherwise I split the two inputs into
// 32-bit halves, do 4 multiplications and some additions to construct
// the result. My belief is that any platform that supports 128-bit
// integers will define __SIZEOF_int128_t__ (that is certainly the case
// with gcc on cygwin and 64-bit ARM and with clang on a Mac m1).
// If that is not defined I will suppose that I need to write the
// calculations out in terms of 64-bit arithmetic.


// At least for debugging I may wish to display 128-bit integers. Here I
// only do hex printing. I could do decimal and octal if I really wanted
// but just for debugging that does not seem vital. If some C++ compiler
// already supported printing of 128-bit ints this definition might clash
// and would need commenting out.

inline std::ostream & operator << (std::ostream &out, uint128_t a)
{   out << std::hex << std::setw(16) << std::setfill('0') <<
        static_cast<Digit>(a>>64)
        << " "
        << static_cast<Digit>(a) << std::dec << std::setfill(' ');
    return out;
}

inline uint128_t pack128(Digit hi, Digit lo)
{   return (static_cast<uint128_t>(hi)<<64) | lo;
}

[[gnu::always_inline]]
inline void multiply64(Digit a, Digit b,
                       Digit &hi, Digit &lo)
{   uint128_t r = static_cast<uint128_t>(a)*static_cast<uint128_t>(b);
    hi = static_cast<Digit>(r >> 64);
    lo = static_cast<Digit>(r);
}

// Now much the same but forming a*b+c. Note that this can not overflow
// the 128-bit result. Both hi and lo are only updated at the end
// of this, and so they are allowed to be the same as other arguments.

[[gnu::always_inline]]
inline void multiply64(Digit a, Digit b,
                       Digit c,
                       Digit &hi, Digit &lo)
{   uint128_t r = static_cast<uint128_t>(a)*static_cast<uint128_t>(b) +
                static_cast<uint128_t>(c);
    hi = static_cast<Digit>(r >> 64);
    lo = static_cast<Digit>(r);
}

[[gnu::always_inline]]
inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             SignedDigit &hi, Digit &lo)
{   int128_t r = static_cast<int128_t>(a)*static_cast<int128_t>(b);
    hi = static_cast<SignedDigit>(static_cast<uint128_t>(r) >> 64);
    lo = static_cast<Digit>(r);
}

[[gnu::always_inline]]
inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             Digit c,
                             SignedDigit &hi, Digit &lo)
{   uint128_t r = static_cast<uint128_t>(
                    static_cast<int128_t>(a)*static_cast<int128_t>(b))
                + static_cast<uint128_t>(c);
    hi = static_cast<SignedDigit>(r >> 64);
    lo = static_cast<Digit>(r);
}

// Here I have classical multiplication for the case N>=M and as
// used here M>7. This is written out as succession of 3 loops since
// that leads to each having simpler start and end conditions, and I
// hope that reduces overhead.

static void simpleMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{
// For this I will require N>=M
    Digit carry = 0, lo, hi = 0, hi1;
// The lowest Digit can be handled specially to get things going.
    multiply64(a[0], b[0], lo, result[0]);
    std::size_t k=1;
    for (; k<M; k++)
    {   std::size_t i;
// Here I want k<M<=N so certainly if i<k then i<N
//@@ The code shown with "//@@" here is the simple presentation of this
//@@ loop, but the actual code unrolls the loop so that two steps are
//@@ taken in each iteration (and potentially a final one is needed at
//@@ the end. This is done to reduce loop overhead. Possibly clever compilers
//@@ would do that for me anyway?
//@@    for (i=0; i<=k; i++)
//@@    {   multiply64(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        for (i=0; i<=k-1; i+=2)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<=k)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Now k>=M, I want i<=k to imply i<N so go as far as k<N
    for (; k<N; k++)
    {
//@@    for (std::size_t j=0; j<M; j++)
//@@    {
//@@ // Ha ha in this loop I iterate on j=k-i which makes the loop
//@@ // just a little nicer to express.
//@@        multiply64(a[k-j], b[j], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t j;
        for (j=0; j<M-1; j+=2)
        {   multiply64(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[k-j-1], b[j+1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (j<M)
        {   multiply64(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Finally k>=N so i<N will imply i<=k
    for (; k<N+M-1; k++)
    {
//@@    for (std::size_t i=k+1-M; i<N; i++)
//@@    {   multiply64(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t i;
        for (i=k+1-M; i<N-1; i+=2)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<N)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// The very final digit of the result drops out here.
    result[k] = lo;
}

size_t slowLimit = 8192;

void timetest(size_t N, int ntrials)
{   //std::cout << "Starting test with length " << N << "\n";
    uint64_t* a = new uint64_t[N];
    uint64_t* b = new uint64_t[N];
    uint64_t* c = new uint64_t[2*N+1];
    uint64_t* cslow = new uint64_t[2*N+1];

// I use random data as my input.
    for (size_t i=0; i<N; i++)
    {
#ifdef RANDOM
        a[i] = twister();
        b[i] = twister();
#else
        a[i] = i+1;
        b[i] = i+1;
#endif
        c[i] = c[i+N] = 0;
        cslow[i] = cslow[i+N] = 0;
    }

// I will not do the "slow" multiplcation for large values of N because
// it gets to take more time than it is worth.
    auto tt0 = microseconds();
    auto tt1 = tt0;
    if (N < 8192)
    {   for (int trial=0; trial<ntrials; trial++)
        {   simpleMul(a, N, b, N, cslow);
        }
        tt1 = microseconds();
    }
    auto tt2 = microseconds();
    for (int trial=0; trial<ntrials; trial++)
    {   fftmul<false>(a, N, b, N, c);
    }
    auto tt3 = microseconds();

    auto tslow = tt1-tt0,
         tfast = tt3-tt2;
    std::cout << std::setw(6) << N;
    if (tslow != 0)
    {   std::cout << std::setw(12) << tslow
             << " (" << (100.0*(double)tslow/(N*N)) << ")";
    }
    else std::cout << std::setw(19) << " ";
    std::cout << std::setw(12) << tfast
         << " (" << ((double)tfast/(N*log(N))) << ")";
    std::cout << "  " << tfast;
    if (tslow != 0) std::cout << "  ratio = " << (tfast/(double)tslow);
    std::cout << "\n";

// Check that classical and fast methods gave the same result.
    if (N < 8192)     // Only check cases where I had done the slow multiply.
        for (int i=2*N-1; i>=0; i--)
    {   if (c[i] != cslow[i])
        {   std::cout << "\n**FAIL** at " << i << "\n";
            prinvec("a", a, N);
            prinvec("b", b, N);
            prinvec("c    ", c, 2*N);
            prinvec("cslow", cslow, 2*N);
            abort();
        }
    }

    delete [] a;
    delete [] b;
    delete [] c;
    delete [] cslow;
}

inline bool valid(size_t N)
{   while (N%2 == 0) N /= 2;
    return N==1 || N==3;
}

int main(int argc, char* argv[])
{
    size_t N = -1;
    if (argc > 1) N = atoi(argv[1]);

    int ntrials = 1;
//    int ntrials = 50;
    if (argc > 2) ntrials = atoi(argv[1]);

    std::cout << " digits       slow (tt/N*N)      fast (tt/NlogN)\n";

    std::cout << std::fixed << std::setprecision(2);
    if (N != -1LU) timetest(N, ntrials);
    else
    {   for (N=8; N<2*slowLimit; N++)
            if (valid(N)) timetest(N, ntrials);
    }
    return 0;
}

// end of ffttest.cpp

