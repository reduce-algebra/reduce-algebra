/* Performance of bivariate functions.

Copyright (c) 2022 Stéphane Glondu, Inria.

This file is part of the CORE-MATH project
(https://core-math.gitlabpages.inria.fr/).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#define _XOPEN_SOURCE 500   /* for ftruncate */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fenv.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

#include "random_under_test.h"

typedef TYPE_UNDER_TEST function_type_under_test (TYPE_UNDER_TEST, TYPE_UNDER_TEST);

function_type_under_test cr_function_under_test;
function_type_under_test function_under_test;

#define SAMPLE_SIZE (2 * sizeof(TYPE_UNDER_TEST))
#if defined(CORE_MATH_F128) && defined(__x86_64__) && !defined(__clang__)
#define CALL_LATENCY(accu,i)			\
  {						\
    __m128i in, ox, oy, m = {1, 0};		\
    asm("":"=x"(in):"0"(accu));			\
    asm("":"=x"(ox):"0"(randoms[2*i+0]));	\
    asm("":"=x"(oy):"0"(randoms[2*i+1]));	\
    in = _mm_and_si128 (in, m);			\
    ox = _mm_or_si128 (ox, in);			\
    oy = _mm_or_si128 (oy, in);			\
    __float128 x,y;				\
    asm("":"=x"(x),"=x"(y):"0"(ox),"1"(oy));	\
    accu = p_function_under_test(x, y);		\
  }
#else
#define CALL_LATENCY(accu,i) \
  accu = p_function_under_test(randoms[2 * i] + 0 * accu, randoms[2 * i + 1])
#endif
#define CALL_THROUGHPUT(i) (p_function_under_test(randoms[2 * i], randoms[2 * i + 1]))

#include "perf_common.h"
