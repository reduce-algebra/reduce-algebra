/* Performance of sincos-like functions.

Copyright (c) 2022-2024 Stéphane Glondu and Paul Zimmermann, Inria.

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

typedef void function_type_under_test (TYPE_UNDER_TEST, TYPE_UNDER_TEST*, TYPE_UNDER_TEST*);

function_type_under_test cr_function_under_test;
function_type_under_test function_under_test;

#define SAMPLE_SIZE (sizeof(TYPE_UNDER_TEST))
#define CALL_LATENCY(accu,i) do {                           \
  TYPE_UNDER_TEST x, y;                                     \
  p_function_under_test(randoms[i] + 0 * accu, &x, &y);     \
  accu = x;                                                 \
  } while (0)

#define CALL_THROUGHPUT(i) do {                 \
  TYPE_UNDER_TEST x, y;                         \
  p_function_under_test(randoms[i], &x, &y); \
  } while (0)

#include "perf_common.h"
