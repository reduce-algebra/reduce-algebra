// ffttune.cpp                                    Copyright 2025 A C Norman

// $Id: ffttune.cpp 7191 2025-10-09 11:50:48Z arthurcnorman $

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

#define FFT_THRESHOLD 1000000

#include "arithlib.cpp"

using namespace std;
using namespace CSL_LISP;
using namespace acnutil;
using namespace arithlib;
using namespace arithlib_lowlevel;
using namespace arithlib_implementation;

// The mess here is actually rather over the top. But it seeds the random
// number generator with 128 bits from rge random_device() and also uses
// a clock that should be reporting nanoseconds since the year 1970 (this
// being protection against the hideous possibility that the C++ standard
// permits of random_device actually being deterministic.
std::random_device randomDevice;
auto timeNow =
    std::chrono::time_point_cast<std::chrono::nanoseconds>(
        std::chrono::system_clock::now());
std::uint64_t ticksNow = timeNow.time_since_epoch().count(); 
std::seed_seq seed{randomDevice(),
                   randomDevice(),
                   randomDevice(),
                   randomDevice(),
                   static_cast<uint32_t>(ticksNow>>32),
                   static_cast<uint32_t>(ticksNow)};
std::mt19937_64 twister(seed);

#include <iostream>

bool first = false;

void timetest(size_t N, int ntrials)
{
    stkvector<Digit> a(N);
    stkvector<Digit> b(N);
    stkvector<Digit> c(2*N+1);
    stkvector<Digit> cslow(2*N+1);

// I use random data as my input.
    for (size_t i=0; i<N; i++)
    {   a[i] = twister();
        b[i] = twister();
        c[i] = c[i+N] = 0;
        cslow[i] = cslow[i+N] = 0;
    }

    if (N >= 16) BigMultiplication::biggerMul(a, N, b, N, cslow);
    auto tt0 = microseconds();
#ifndef QUICK_TEST
    for (int trial=0; trial<ntrials; trial++)
    {   if (N >= 16) BigMultiplication::biggerMul(a, N, b, N, cslow);
    }
#endif
    auto tt1 = microseconds();
    BigMultiplication::fftmul(a, N, b, N, c);
    auto tt2 = microseconds();
#ifndef QUICK_TEST
    for (int trial=0; trial<ntrials; trial++)
    {   BigMultiplication::fftmul(a, N, b, N, c);
    }
#endif
    auto tt3 = microseconds();

    auto tslow = tt1-tt0,
         tfast = tt3-tt2;
    std::cout << std::setw(7) << N;
    std::cout << std::setw(12) << tslow
         << " (" << ((double)tslow/(N*log(N))) << ")";
    std::cout << std::setw(12) << tfast
         << " (" << ((double)tfast/(N*log(N))) << ")";
    if (tslow != 0) std::cout << "  ratio = " << (tfast/(double)tslow);
    if (!first && tfast < tslow)
    {   first = true;
        std::cout << " ******";
    }
    std::cout << "\n";

    if (N < 16) return; // because reference result not calculated.
// Check that previous and new methods gave the same result.
    for (int i=0; i<2*N; i--)
    {   if (c[i] != cslow[i])
        {   std::cout << "\n**FAIL** at " << i << "\n";
            prinvec("a   ", a, N, 1);
            prinvec("b   ", b, N, 1);
            prinvec("FFT ", c, 2*N, 1);
            prinvec("slow", cslow, 2*N, 1);
            abort();
        }
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Test starting" << std::endl;
#if defined __LINUX__ && __x86_64__
// I make the report here because I am investigating whether use of
// SSE or AVX could speed things up.
    __builtin_cpu_init();
    if (__builtin_cpu_supports("sse4.2")) std::cout << "Has SSE 4.2\n";
    else
    {   std::cout << "No SSE 4.2\n";
        return 1;
    }
    if (__builtin_cpu_supports("avx")) std::cout << "Has AVX\n";
    else
    {   std::cout << "No AVX\n";
        return 1;
    }
#endif // __LINUX__ && __x86_64

    size_t N = -1;
    if (argc > 1) N = atoi(argv[1]);

    int ntrials = 10;
    if (argc > 2) ntrials = atoi(argv[1]);

    std::cout << "  digits       old  (tt/NlogN)     new (tt/NlogN)\n";
    std::cout << std::fixed << std::setprecision(2);
    if (N != (size_t)(-1)) timetest(N, ntrials);
    else
    {   for (N=1; N<270000; N=2*N)
        {   timetest(N, ntrials);
            if (N>1) timetest((3*N)/2, ntrials);
        }
    }
    return 0;
}

// end of ffttune.cpp
