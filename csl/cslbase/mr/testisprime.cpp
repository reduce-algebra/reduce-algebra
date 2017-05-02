// testisprime.cpp                            Copyright (C) A C Norman 2017

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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


// This code is to test the "isprime" function. It uses a sieve method to
// build a table marking all odd primes. It then checks every integer from
// 0 to 0xffffffff by calling isprime() and verifying that the result is
// in agreement with the bitmap.

// On my home pc it runs for between 6 and 7 minutes.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __STDC_CONSTANT_MACROS 1
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#include "isprime.cpp"

int main(int argc, char *argv[])
{
    printf("Table size = %d, multiplier = %#.16" PRIx64 "\n",
        sizeof(witness)/sizeof(witness[0]), hash_multiplier);
    fflush(stdout);
// Set up a table of primes.
    clock_t c0 = clock();
    char *primes = (char *)malloc(UINT64_C(0x80000000));
    if (primes == NULL)
    {   printf("Unable to allocate space\n");
        exit(1);
    }
// Sieve method. Note that I only use a flag for each odd number. I assume
// I am on a computer with plenty of memory, and so I use a full byte for
// every (odd) integer. That means I allocate a table that is 2Gbytes in
// size.
    printf("Set up a table of primes\n");
    fflush(stdout);
    for (uint64_t i=0; i<UINT64_C(0x80000000); i++) primes[i] = 1; // provisionally prime
    primes[0] = 0;
    {   uint64_t p = 1;
        while (p*p < UINT64_C(0x100000000))
        {   while (primes[p/2] == 0) p+=2; // find next prime
            uint64_t np = (3*p-1)/2;
            while (np < UINT64_C(0x80000000))
            {   primes[np] = 0;
                np += p;
            }
            p += 2;
        }
    }
    clock_t c1 = clock();
    printf("Primes table set up in %.2f seconds\n",
        (double)(c1-c0)/CLOCKS_PER_SEC);
    fflush(stdout);
// I will display a message every 0x10000000 (ie 16 such messages in all)
// so that the user gets some indication that progress is being made.
    uint64_t trigger = 0x10000000;
    int p;
// Very small numbers are special cases, so check them individually.
    if (isprime(p=0)  ||
        isprime(p=1)  ||
        !isprime(p=2))
    {   printf("incorrect result on small number %d\n", p);
        exit(1);
    }
    for (uint64_t i=3; i<UINT64_C(0x100000000); i++)
    {   if (i >= trigger)
        {   printf("tested up to %" PRIx64 "\n", i);
            fflush(stdout);
            trigger += 0x10000000;
        }
        if (isprime(i))
        {   if ((i%2)==0 || !primes[(i-1)/2])
            {   printf("Incorrect result, %u reported as prime\n",
                       (unsigned)i);
                exit(1);
            }
        }
        else
        {   if ((i%2)!=0 && primes[(i-1)/2])
            {   printf("Incorrect result, %u reported as composite\n",
                       (unsigned)i);
                exit(1);
            }
        }
    }
    clock_t c2 = clock();
    double s;
    printf("Testing the isprime function took %.2f seconds\n",
        s = (double)(c2-c1)/CLOCKS_PER_SEC);
    printf("That is %d ns per call\n",
        (int)(10.0e9*s/UINT64_C(0x100000000)));
    printf("Everything seems to be OK\n");
    return 0;
}

// end of testisprime.cpp
