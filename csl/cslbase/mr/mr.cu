// mr.cu                                      Copyright (C) A C Norman 2017

/*
 * "This software contains source code provided by NVIDIA Corporation."
 *
 * Specifically this code contains fragments from the CUDA Sample code
 * distributed by nVidia. They permit modification and re-distribution subject
 * to including the statement made at the top of this comments and preserving
 * nVidia Copyright statements, such as the following line:
 * "Copyright 1993-2015 NVIDIA Corporation.  All rights reserved."
 *
 * Apart from the above  constraints the code here is subject to a BSD
 * license, the terms of which follow:
 */


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

#define __STDC_CONSTANT_MACROS 1
#define __STDC_LIMIT_MACROS    1
#define __STDC_FORMAT_MACROS   1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <helper_functions.h>

__global__ void gpuCode(uint32_t n, char *out)
{
// n will be a composite.
    unsigned int bx = blockIdx.x;
    unsigned int by = blockIdx.y;
    unsigned int tx = threadIdx.x;
    unsigned int ty = threadIdx.y;
// Ignore calls that seem out of range.
    if (bx>=16 || by>=16 || tx>=16 || ty>=16) return;
    uint32_t a = ((bx*16 + by)*16 + tx)*16 + ty;
    uint32_t a0 = a;
// a is a base I might like to use to test it. I will set out[a] to 1
// if the Miller Rabin test suggests that n is prime, ie if n is a strong
// pseudoprime base a.
// When this is called n should not be a multiple of 2, 3, 5, 7 or 11, and so
// the next few (commented out) lines are not required.
//  if (n == 1) goto composite;            // 1 treated as composite
//  else if (n <= 3) goto prime;           // 2 and 3 are primes
//  else if ((n & 1) == 0) goto composite; // even numbers are all composite
// a == 1 and a == p-1 (and for small p values that are close to multiples of
// p) will always be bad, but it is easiest to let those cases through here.
    uint32_t d = n-1;
    int s = 0;
    while ((d & 1) == 0)
    {   d = d >> 1;
        s++;
    }
    uint32_t y = 1;
    while (d > 1)
    {   if ((d & 1) != 0) y = ((uint64_t)a * y) % n;
        a = ((uint64_t)a * a) % n;
        d = d >> 1;
    }
    uint32_t x = ((uint64_t)a * y) % n;
    if (x == 1 || x == n-1) goto prime;
    while (s > 1)
    {   x = ((uint64_t)x * x) % n;
        if (x == 1) goto composite;
        else if (x == n-1) goto prime;
        s--;
    }
// If I drop out of the loop then the input was compostite.
composite:
    out[a0] = 0;
    return;
prime:
    out[a0] = 1;
    return;
}

// I will report progress from time to time. More often at the start of the
// run.

static char *get_date()
{   time_t t0 = time(NULL);
    return asctime(localtime(&t0));
}

unsigned int records = 0;

void report_progress(uint32_t p)
{   if ((p < 0x00100000 && (p & 0x0000fffe) == 0) ||
        (p < 0x01000000 && (p & 0x000ffffe) == 0) ||
        (p < 0x10000000 && (p & 0x00fffffe) == 0) ||
        (                  (p & 0x0ffffffe) == 0))
    {   printf("Testing %.8x found %u at %s", p&(~1), records, get_date());
        fflush(stdout);
    }
}

static void dump_results(uint32_t p, char *out_data, FILE *out)
{   uint32_t fails = 0;
// Bases 0 and 1 are not useful at all. p-1 is also no use
    out_data[0] = out_data[1] = 0;
    for (int i=0; i<256*256; i++)
        if (out_data[i]) fails++;
    if (fails != 0)
    {   records++;
// For each composite number that is a pseudo-prime to at least one base I
// output a record that starts with 4 bytes for the composite uint32_t value.
        putc(p & 0xff, out);
        putc((p>>8) & 0xff, out);
        putc((p>>16) & 0xff, out);
        putc((p>>24) & 0xff, out);
// The 2 bytes for the number of bases (in the range 1..0xffff) that it is
// a pseudoprime for.
        putc(fails & 0xff, out);
        putc((fails>>8) & 0xff, out);
// Then a collection of 2 byte values that list those bases.
        for (int i=0; i<256*256; i+=8)
        {   if (out_data[i])
            {   putc(i & 0xff, out);
                putc((i>>8) & 0xff, out);
            }
        }
    }
}

int main(int argc, char *argv[])
{   FILE *out = fopen("mr.data", "wb");
    if (out == NULL)
    {   printf("Failed to open output file\n");
        exit(1);
    }
    setvbuf(out, NULL, _IOFBF, 4*1024*1024);
//
// I will use 256 Mbytes for a bitmap recording all the odd primes up to 2^32.
// It takes (only) a couple of minutes of CPU time to set this up.
//
    char *primes = (char *)malloc(0x80000000U/8);
    if (primes == NULL)
    {   printf("Unable to allocate space\n");
        exit(1);
    }
// Sieve method
    printf("Start prime sieve %s", get_date());
    fflush(stdout);
    for (uint64_t i=0; i<0x80000000U/8; i++) primes[i] = 0xff;
    primes[0] = 0xfe;
    {   uint64_t p = 1;
        while (p*p < UINT64_C(0x100000000))
        {   while ((primes[p/16] & (1<<((p/2)&7))) == 0) p+=2; // next prime.
            uint64_t np = (3*p-1)/2;
            while (np < 0x80000000U)   // strike out all multiple of it.
            {   primes[np/8] &= ~(1<<(np&7));
                np += p;
            }
            p += 2;
        }
    }
    printf("Map of odd primes created %s", get_date());
// Both for checking and foir use elsewhere I will dump out a brief bitmap
// table of primes that will let me identify primes up to 4096 very rapidly.
    printf("uint32_t oddprime_bitmap[] =");
    for (int i=0; i<4096/2/8/4; i++)
    {   if (i == 0) printf("\n{   ");
        else if (i % 6 == 0) printf(",\n    ");
        else printf(", ");
        uint32_t v = primes[4*i] | (primes[4*i+1]<<8) |
                     (primes[4*i+2]<<16) | (primes[4*i+3]<<24);
        printf("%#.8x", v);
    }
    printf("\n};\n");
    fflush(stdout);

    int devID = gpuGetMaxGflopsDeviceId();
    checkCudaErrors(cudaSetDevice(devID));

// While debugging I wanted to use printf on the device, and giving a
// large print buffer helped. For release code this is not needed.
//  cudaDeviceSetLimit(cudaLimitPrintfFifoSize, 200*1024*1024);

    char *out_data = (char *)malloc(256*256*sizeof(char));
    int out_ready = 0;
    uint32_t saved_p = 0;

    char *gpu_output;
    checkCudaErrors(cudaMalloc((void **)&gpu_output, 256*256*sizeof(char)));

    dim3 grid(16, 16);
    dim3 thread(16, 16);

    records = 0;
    for (uint32_t p=3; p!=0xffffffff; p+=2)
    {   report_progress(p);
        if (p%3 == 0) continue;
        if (p%5 == 0) continue;
        if (p%7 == 0) continue;
        if (p%11 == 0) continue;
// I am not going to test numbers that have a factor of 2,3,5,7 or 11 because
// I will check for those small factors elsewhere. I then just need to look
// at other composite numbers to see if they might be strong pseudoprimes.
        if ((primes[p/16] & (1<<((p/2)&7))) != 0) continue;
// Now p should be a composite number (with no factors less than 13).
//
// Start the GPU...
        gpuCode<<<grid, thread>>>(p, gpu_output);
// Now if a previous kernel task has given us some output write it to
// our output file. What I am doing here is overlapping the GPU analysing
// my next number with the CPU processing and writing out information about
// the one I analysed last time round.
        if (out_ready) dump_results(saved_p, out_data, out);
// When that is done I should wait for the current kernel to complete
// and recover the results that it delivers.
        getLastCudaError("Kernel execution failed");
        checkCudaErrors(cudaMemcpy(out_data,
                                   gpu_output,
                                   256*256*sizeof(char),
                                   cudaMemcpyDeviceToHost));
        saved_p = p;
        out_ready = 1;
    }
// The final chunk of output from the GPU has now been recovered but still
// needs sending to the output file.
    if (out_ready) dump_results(saved_p, out_data, out);

    fclose(out);
    free(out_data);
    checkCudaErrors(cudaFree(gpu_output));

    exit(EXIT_SUCCESS);
}

// end of mr.cu
