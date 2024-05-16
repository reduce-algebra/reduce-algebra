// Code to suggest value for KARASTART etc            A C Norman, 2020-2024


/**************************************************************************
 * Copyright (C) 2024, Codemist.                         A C Norman       *
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

size_t start, start_parallel;

// This program is intended to help select good values for the above
// parameters in arithlib.hpp.
// When performing a multiplication on a pair of N digit numbers (where each
// digit is 64 bits) the code uses classical long multiplication for
// small N. From N=KARASTART upwards it uses Karatsuba. At what will typically
// be a much higher length it will start to use a pair of worker threads to
// get the 3 multiplications that come from a top-level decomposition done in
// parallel.

// I will start by picking a value for KARASTART. While doing tkat I will
// set KBIG to 999 so that multiple threads are never used.

// For a range of input sizes I will try values of KARASTART in the range
// 15 - 30 and report which one gives the fastest time. The products I
// will form will be from 15*15 up to 100*100. The choice of a starting point
// 15 is because my code handles small integer products specially and
// it requires (KARASTART+1)/2 > 7 so I can miss out just a few tests.

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
// error is detected.
    size_t klimit;
    uint64_t seed;
    if (argc > 1) seed = atoi(argv[1]);
    else seed = mersenne_twister() & 0xffff;
    cout << "seed = " << seed << "\n";

    chrono::high_resolution_clock::time_point clk, clk2;
    chrono::duration<double, micro> elapsed;
    chrono::nanoseconds timing;

    uint64_t a[1000], b[1000], c[2000];

    for (size_t i=0; i<1000; i++)
    {   a[i] = mersenne_twister();
        b[i] = mersenne_twister();
    }

    size_t overallBest = 999;
    for (size_t N = 15; N<=24; N++)
    {
#ifdef DEBUG
        size_t ntries = 200/N;
#else
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
            reseed(seed);
// I will run the multiplication a couple of times before I start
// timing in case that pre-loads a cache...
            clk = chrono::high_resolution_clock::now();
            for (size_t i=1; i<=ntries; i++)
            {   size_t lenc;
                arithlib_implementation::bigmultiply(a, N, b, N, c, lenc);
// The next line is intended to defeat any super-clever optimisation that
// omits most of the work.
                q += c[0] + c[lenc-1];
            }
            clk2 = chrono::high_resolution_clock::now();
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
            cout << "Test on " << N << " digit numbers says best start <= " << bestStart << "\n";
        else cout << "Test on " << N << " digit numbers says best start >= " << bestStart << "\n";
        overallBest = std::min(bestStart, overallBest);
    }

    cout << "\nPropose start = " << overallBest << "\n\n";
    cout << "About to exit" << "\n";
    return 0;
}

// end of karatune.cpp
