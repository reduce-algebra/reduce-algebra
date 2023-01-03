// Code to suggest value for KARSTSUBA_CUTOFF              A C Norman, 2020


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

unsigned long int klimit = 18;
#define KARATSUBA_CUTOFF klimit

#include "arithlib.hpp"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cassert>

#if defined __CYGWIN__ || defined __MINGW32__
// One thing I want to check is that declarations and definitions that I
// have made in my library do not clash with ones in <windows.h>. So
// even though I do not need anything from it I will include it here!

//#include <windows.h>
#endif

using namespace arithlib;

int main(int argc, char *argv[])
{
// If I invoke this without command line arguments it will run with
// a decent randomized sequence. If I give it a command line argument
// that is an integer it will use that to see its random number generator
// and so it will behave deterministically. This is really useful if an
// error is detected.

    std::uint64_t seed;
    if (argc > 1) seed = std::atoi(argv[1]);
    else seed = mersenne_twister() & 0xffff;
    std::cout << "seed = " << seed << std::endl;

    std::chrono::high_resolution_clock::time_point clk, clk2;
    std::chrono::duration<double, std::micro> elapsed;
    std::chrono::nanoseconds timing;

    for (std::size_t maxbits = 250; maxbits<=2500; maxbits+=250)
    {   std::size_t ntries = 250000;
        std::cout << "Test with maxbits = " << maxbits
           << ": " << ((maxbits+63)/64) << " words\n";
#define MAX_KARA_CUTOFF 35
        for (klimit = 2; klimit < MAX_KARA_CUTOFF; klimit++)
        {   reseed(seed);
            clk = std::chrono::high_resolution_clock::now();

            for (std::size_t i=1; i<=ntries; i++)
            {
#if 1
                Bignum a = uniform_positive_bignum(maxbits);
                Bignum b = uniform_positive_bignum(maxbits);
#else
                Bignum a = random_upto_bits_bignum(maxbits);
                Bignum b = random_upto_bits_bignum(maxbits);
#endif
                if (klimit == MAX_KARA_CUTOFF-1) klimit = 100000;
                if (klimit != MAX_KARA_CUTOFF-2)
                {   Bignum c = a * b;
                }
            }
            clk2 = std::chrono::high_resolution_clock::now();
            elapsed = clk2 - clk;
            timing =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
            std::cout << "Time for k=" << klimit << " ="
                      << (timing.count()/1.0e9) << " sec" << std::endl;
        }
    }

    std::cout << "About to exit" << std::endl;
    return 0;
}

// end of arithtest.cpp
