// Code to suggest value for KARSTSUBA_EVEN_START etc A C Norman, 2020-2022


/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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

#define KARATSUBA_START_EVEN start_even
#define KARATSUBA_START_ODD  start_odd
#define PARAKARA_START       start_parallel

size_t start_even,     // = DEFAULT_KARATSUBA_START_EVEN,
       start_odd,      // = DEFAULT_KARATSUBA_START_ODD,
       start_parallel; // = DEFAULT_KARATSUBA_PARALLEL;

// This progran is intended to help select good values for the above
// three parameters in arithlib.hpp.
// When performing a multiplication on a pair of N digit numbers (where each
// digit is 64 bits) the code uses classical long multiplication for
// small N. If N is even then from N=KARATSUBA_START_EVEN upwards it
// uses Karatsuba. Similarly for N odd. At what will typically be a much
// higher length it will start to use a pair of worker threads to get the
// 3 multiplications that come from a top-level decomposition done in
// parallel.

// This runs tests for a range of integer sizes. For each size that it
// tries it uses a range of values for the thresholds. The idea is that
// it should consider threshold values critical for the number size under
// test.
// So for an size N I put in a constraint that will allow one level of
// decomposition and work down from there.
// As an example consider N=54.
// If I set limits over 27 then after a single decomposition things will
// go no futher. If I allow a split into 27+27 the next place I can
// block would be with a threshold over 14
//     START_EVEN   START_ODD  START_PARALLEL
//       999          999       999            no decomposition
//        28           28       999 or 54      54->27
//        15           14       999 or 54      54->27->14
//         8            8       999 or 54      54->27->14->7
// For each of those apart from the "no decompostion" case the top level
// decomposition may or may not be performed using threads.
//
// I will also have a default setting for the three thresholds where for
// amy particular N its behavior will match one of the ones suggested
// above. I will always run that test and annotate its timings with "<<<<<".
// If my defaults are good that line of measurement will show the shortest
// time (within normal measurement levels of uncertainty).

#include "arithlib.hpp"

using namespace arithlib;
using namespace arithlib_implementation;
using namespace std;

volatile uint64_t q = 0;

vector<uint64_t> special;

// Note that the various thresholds will all be (well) under 999 and so
// allowing 10-bit fields when packing them is safe.

bool sizeorder(uint64_t a, uint64_t b)
{   return ((a & 0x3ff) + ((a>>10) & 0x3ff) + ((a>>20) & 0x3ff)) <
           ((b & 0x3ff) + ((b>>10) & 0x3ff) + ((b>>20) & 0x3ff));
}

size_t pack(size_t even, size_t odd, size_t parallel)
{   return even + (odd<<10) + (parallel<<20); 
}

void fillInSpecials(size_t N)
{   special.clear();
    special.push_back(pack(999, 999, 999));
    special.push_back(pack(DEFAULT_KARATSUBA_START_EVEN,
                           DEFAULT_KARATSUBA_START_ODD,
                           DEFAULT_KARATSUBA_START_PARALLEL));
    size_t topN = N;
    while (N > 7)
    {   N = (N+1)/2;
        special.push_back(pack(N+1, N+1, 999));
// I will take the view that trying threads on less than 80 digits will
// be over-costly.
        if (topN >= 80) special.push_back(pack(N+1, N+1, topN));
    }
    sort(special.begin(), special.end(), sizeorder);
}

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

// For multiplication of two numbers each with N digits there can be
// various special values for the Karatsuba thresholds.
// If N is even then start_even being N vs any value bigger than that
// will impact the first level of decomposition. Similarly if N is
// odd then start_odd will.
// Then in addition to that all values that are special for (N+1)/2 will
// also apply.

    for (size_t N = 8; N<=250; N = (N<37 ? N+1 : N<100 ? N+7 : N+25))
    {   size_t ntries = 100000/N;
        size_t innerTries = 1000;
        cout << "\n" << N  << " words\n";
        fillInSpecials(N);
        for (auto packed:special)
        {   start_even = packed&0x3ff;
            start_odd = (packed>>10) & 0x3ff;
            start_parallel = (packed>>20) & 0x3ff;
            cout <<   "start_even = " << setw(3) << start_even
                 << "  start_odd = " << setw(3) << start_odd
                 << "  start_parallel = " << setw(3) << start_parallel
                 << "     ";
            reseed(seed);
// I will run the multiplication a couple of times before I start
// timing in case that pre-loads a cache...
            for (size_t i=1; i<=4; i++)
            {   uint64_t s1 = mersenne_twister(),
                         s2 = mersenne_twister();
                for (size_t i=0; i<N; i++)
                {   a[i] = s1;
                    s2 = s1 + s2;
                    s1 = a[i];
                }
                for (size_t i=0; i<N; i++)
                {   b[i] = s1;
                    s2 = s1 + s2;
                    s1 = b[i];
                }
                size_t lenc;
                arithlib_implementation::bigmultiply(a, N, b, N, c, lenc);
                q += c[0];
            }
            clk = chrono::high_resolution_clock::now();
            for (size_t i=1; i<=ntries; i++)
            {   uint64_t s1 = mersenne_twister(),
                         s2 = mersenne_twister();
                for (size_t i=0; i<N; i++)
                {   a[i] = s1;
                    s2 = s1 + s2;
                    s1 = a[i];
                }
                for (size_t i=0; i<N; i++)
                {   b[i] = s1;
                    s2 = s1 + s2;
                    s1 = b[i];
                }
                for (int kk=0; kk<innerTries; kk++)
                {   size_t lenc;
                    arithlib_implementation::bigmultiply(a, N, b, N, c, lenc);
                    q += c[0];
                }
            }
            clk2 = chrono::high_resolution_clock::now();
            elapsed = clk2 - clk;
            timing =
                chrono::duration_cast<chrono::nanoseconds>(elapsed);
            cout << setprecision(3) << (timing.count()/1.0e9) << " sec";
            if (packed == pack(DEFAULT_KARATSUBA_START_EVEN,
                               DEFAULT_KARATSUBA_START_ODD,
                               DEFAULT_KARATSUBA_START_PARALLEL))
                cout << "  <<<<\n";
            else cout << "\n";
        }
    }

    cout << "About to exit" << "\n";
    return 0;
}

// end of karatune.cpp
