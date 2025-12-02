/* Performance of univariate functions.

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
#ifdef __INTEL_CLANG_COMPILER
#include <mathimf.h>
#endif

#include "random_under_test.h"

typedef TYPE_UNDER_TEST function_type_under_test (TYPE_UNDER_TEST);

function_type_under_test cr_function_under_test;
function_type_under_test function_under_test;

#define SAMPLE_SIZE (sizeof(TYPE_UNDER_TEST))
// disable for now the code below which does not work for TYPE_UNDER_TEST=long double
#if defined(CORE_MATH_F128) && defined(__x86_64__) && !defined(__clang__)
#define CALL_LATENCY(accu,i)					\
  {								\
    __m128i in, out, m = {1, 0};				\
    asm("" : "=x" (in) :"0" (accu));				\
    asm("" : "=x" (out) :"0" (randoms[i]));			\
    in = _mm_and_si128 (in, m);					\
    out = _mm_or_si128 (out, in);				\
    asm("": "=x"(accu): "0"(out));				\
    accu = p_function_under_test(accu);				\
  }
#else
#define CALL_LATENCY(accu,i) \
  accu = p_function_under_test(randoms[i] + 0 * accu)
#endif
#define CALL_THROUGHPUT(i) (p_function_under_test(randoms[i]))

#include "perf_common.h"
