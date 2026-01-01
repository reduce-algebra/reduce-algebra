// Code to suggest value for KARASTART etc            A C Norman, 2020-2026


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
// parameters in arithlib.cpp.
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

#define FFT_THRESHOLD 1000000

#include "arithlib.h"

using namespace arithlib;
using namespace arithlib_implementation;
using namespace std;

volatile uint64_t q = 0;

double measure(size_t N, size_t limit)
{
    uint64_t a[8000], b[8000], c[16000];

    mt19937_64 twister(random_device{}());
    for (size_t i=0; i<8000; i++)
    {   a[i] = twister();
        b[i] = twister();
    }

    size_t lenc;

#ifdef DEBUG
    size_t ntries = 200/N;
    if (N==0) N = 1;
#else
    size_t ntries = 50000000/N;
#endif
    start_parallel = limit;
    auto clk = chrono::steady_clock::now();
    for (size_t i=1; i<=ntries; i++)
    {   size_t lenc;
        arithlib_implementation::bigmultiply(a, N, b, N, c, lenc);
        q += c[0] + c[lenc-1];
    }
    auto clk2 = chrono::steady_clock::now();
    auto elapsed = clk2 - clk;
    auto timing =
        chrono::duration_cast<chrono::nanoseconds>(elapsed);
    return timing.count()/1.0e9;
}

double speedratio(size_t N)
{   return measure(N, N)/measure(N, N+1);
}

int main(int argc, char *argv[])
{
    mt19937_64 twister(random_device{}());

    chrono::steady_clock::time_point clk, clk2;
    chrono::duration<double, micro> elapsed;
    chrono::nanoseconds timing;

    uint64_t a[8000], b[8000], c[16000];

    for (size_t i=0; i<8000; i++)
    {   a[i] = twister();
        b[i] = twister();
    }

    size_t overallBest = 999;
    int farEnough = 0;
#ifndef NOSMALL
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
#else
    KARASTART = overallBest = 16;
#endif // NOSMALL

    size_t overallBestParallel = 999;
    farEnough = 0;
    cout << "\n*** Check when parallel Karatsuba beats sequential\n\n";

    double r = speedratio(6000);
    cout << "Ratio at length 6000 = " << r << "\n";
    if (r >= 0.5)
    {   cout << "Concurrency support on this machine seems very poor\n";
        return 1;
    }

    size_t low, high;
    low = 32;
    int count = 0;
    while (speedratio(low) < 0.8 && count++ < 5) low = low/2;
    high = 2*low;
    while (speedratio(high) > 1.2 && count++ < 10) high = 2*high;
    if (count > 9)
    {   cout << "Unable to identify limits\n";
        return 1;
    }

    cout << low << " <= KARABIG <= " << high << "\n";

    size_t mid;
    while ((mid = (low+high)/2) != low)
    {   r = speedratio(mid);
        cout << "Size=" << mid << " speed ratio=" << r << "\n";
        if (r > 1.0) low = mid;
        else high = mid;
    }
    overallBestParallel = high;

    cout << "\nPropose KARASTART = " << overallBest << "\n";
    cout << "Propose KARABIG = " << overallBestParallel << "\n\n";

    for (size_t k=high-2; k<=high+2; k++)
    {   r = speedratio(k);
        cout << "Size=" << k << " speed ratio=" << r << "\n";
    }

    cout << "\nTested on ";
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
