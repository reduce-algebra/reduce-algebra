// Code to suggest value for KARASTART etc            A C Norman, 2020-2025


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

// $Id$


#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cassert>
#include <cstdint>

#define KARASTART     start
#define KARABIG       start_parallel

using namespace CSL_LISP;

size_t start, start_parallel;

// This program is intended to help select good values for the above
// parameters in arithlib.hpp.
// When performing a multiplication on a pair of N digit numbers (where each
// digit is 64 bits) the code uses classical long multiplication for
// small N. From N=KARASTART upwards it uses Karatsuba. At what will typically
// be a much higher length it will start to use a pair of worker threads to
// get the 3 multiplications that come from a top-level decomposition done in
// parallel.

// I will start by picking a value for KARASTART. While doing that I will
// set KARABIG to 999 so that multiple threads are never used.

// For a range of input sizes I will try values of KARASTART and in each
// case try with or without Karatsuba activated. When I find several in a
// row all declare Karatsuba faster I will view that is having found a
// proper transition point.

#include "arithlib.hpp"

using namespace arithlib;
using namespace arithlib_implementation;
using namespace std;

volatile uint64_t q = 0;

int main(int argc, char *argv[])
{
// If I invoke this without command line arguments it will run with
// a decent randomized sequence. If I give it a command line argument
// that is an integer it will use that to see its random number generator
// and so it will behave deterministically. This is really useful if an
// error is detected. The randomization provides some point for running this
// code multiple times - even though the exact nature of the numbers
// being multiplied is not expected to impact costs.
    size_t klimit;
    uint64_t seed;
    if (argc > 1) seed = atoi(argv[1]);
    else seed = mersenne_twister() & 0xffff;
    cout << "seed = " << seed << "\n";

    chrono::steady_clock::time_point clk, clk2;
    chrono::duration<double, micro> elapsed;
    chrono::nanoseconds timing;

    uint64_t a[1000], b[1000], c[2000];

    for (size_t i=0; i<1000; i++)
    {   a[i] = mersenne_twister();
        b[i] = mersenne_twister();
    }

    size_t overallBest = 999;
    int farEnough = 0;
    cout << "\n*** Check when Karatsuba beats classical\n\n";
    for (size_t N = 15; farEnough<5 && N<=40; N++)
    {
#ifdef DEBUG
        size_t ntries = 200/N;
#else
// The number of tries set here is intended to be large enough that
// timing measurements are liable to be reasonably reliable but small
// enough that running this code does not take stupidly too long.
        size_t ntries = 150000000/N;
#endif
        cout << "\n" << N  << " words\n";
        double bestSoFar = 1.0e6;
        size_t bestStart = 0;
        start_parallel = 999;
        for (start=N; start<=N+1 ; start++)
        {   cout <<   "start = " << setw(3) << start
                 << "  start_parallel = " << setw(3) << start_parallel
                 << "     ";
            clk = chrono::steady_clock::now();
            for (size_t i=1; i<=ntries; i++)
            {   size_t lenc;
                arithlib_implementation::bigmultiply(a, N, b, N, c, lenc);
// The next line is intended to defeat any super-clever optimisation that
// omits most of the work. Because q is volatile it will have to be
// executed and that means that both the top and the bottom digits of the
// product will have had to be computed.
                q += c[0] + c[lenc-1];
            }
            clk2 = chrono::steady_clock::now();
            elapsed = clk2 - clk;
            timing =
                chrono::duration_cast<chrono::nanoseconds>(elapsed);
            double tt = timing.count()/1.0e9;
            cout << setprecision(3) << tt << " sec\n";
            if (tt < bestSoFar)
            {   bestSoFar = tt;
                bestStart = start;
            }
        }
        if (bestStart == N)
        {   cout << "Test on " << N << " digit numbers faster using Karatsuba\n";
            farEnough++;
        }
        else
        {   cout << "Test on " << N << " digit numbers faster using classical multiplication\n";
            farEnough = 0;
            overallBest = N+1;
        }
        overallBest = std::min(bestStart, overallBest);
    }

    cout << "\nPropose KARASTART = " << overallBest << "\n\n";
    start = overallBest;

    size_t overallBestParallel = 999;
    farEnough = 0;
    cout << "\n*** Check when parallel Karatsuba beats sequential\n\n";
    for (size_t N = 50; farEnough<5 && N<=400; N+=3)
    {
#ifdef DEBUG
        size_t ntries = 200/N;
#else
        size_t ntries = 75000000/N;
#endif
        cout << "\n" << N  << " words\n";
        double bestSoFar = 1.0e6;
        size_t bestStart = 0;
        for (start_parallel=N; start_parallel<=N+1 ; start_parallel++)
        {   cout <<   "start = " << setw(3) << start
                 << "  start_parallel = " << setw(3) << start_parallel
                 << "     ";
            clk = chrono::steady_clock::now();
            for (size_t i=1; i<=ntries; i++)
            {   size_t lenc;
                arithlib_implementation::bigmultiply(a, N, b, N, c, lenc);
// The next line is intended to defeat any super-clever optimisation that
// omits most of the work.
                q += c[0] + c[lenc-1];
            }
            clk2 = chrono::steady_clock::now();
            elapsed = clk2 - clk;
            timing =
                chrono::duration_cast<chrono::nanoseconds>(elapsed);
            double tt = timing.count()/1.0e9;
            cout << setprecision(3) << tt << " sec\n";
            if (tt < bestSoFar)
            {   bestSoFar = tt;
                bestStart = start_parallel;
            }
        }
        if (bestStart == N)
        {   cout << "Test on " << N << " digit numbers faster with threads\n";
            farEnough++;
        }
        else
        {   cout << "Test on " << N << " digit numbers faster WITHOUT threads\n";
            farEnough = 0;
            overallBestParallel = N+1;
        }
        overallBestParallel = std::min(bestStart, overallBestParallel);
    }

    cout << "\nPropose KARASTART = " << overallBest << "\n";
    cout << "\nPropose KARABIG = " << overallBestParallel << "\n\n";
#if defined WIN32
    cout << "Windows (x86_64-w64-mingw32-g++)\n";
#elif defined __CYGWIN__
    cout << "Cygwin (g++)\n";
#elif defined __APPLE__ && defined __arm64__
    cout << "Macintosh m1 (macbook air)\n";
#elif defined __ARM_ARCH_8A
    cout << "Raspberry Pi 5 (64-bit Raspberry Pi OS)\n";
#elif defined __ARM_ARCH
    cout << "Raspberry Pi 5 (32-bit Raspberry Pi OS)\n";
#else
    cout << "General Linux etc\n";
#endif

    return 0;
}

// end of karatune.cpp
