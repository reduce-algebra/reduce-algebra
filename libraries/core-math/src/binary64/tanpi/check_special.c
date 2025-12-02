/* Various special tests

Copyright (c) 2023-2025 Alexei Sibidanov

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

/* Usage: ./check.sh --special -t -a -10 -b 10 tanpi
          ./check.sh --special -t -p tanpi
   -t   the test is done in parallel
   -a   first boundary
   -b   second boundary
   -p   generates random numbers in the whole binary64 range
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <fenv.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include "function_under_test.h"

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 100000000UL /* total number of tests */
#endif

double cr_function_under_test(double);
double ref_function_under_test(double);

int ref_fesetround(int);
void ref_init(void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd;
int verbose = 0;

static inline double tfun(double x){
  return cr_function_under_test(x);
}

static inline double rfun(double x){
  return ref_function_under_test(x);
}

typedef union {double f; uint64_t u;} b64u64_u;

double rand_arg(double s){
  int64_t r0,r1;
  r0 = rand () | (int64_t) rand () << 31;
  r1 = rand () | (int64_t) rand () << 31;
  b64u64_u o = {.u = (((r0^((uint64_t)r1<<32))&(~(0x7ffull<<52)))|(0x3ffull<<52))};
  double r = o.f-copysign(1,o.f);
  return r*s;
}

double rand_arg2(){
  int64_t r0,r1;
  b64u64_u o;
  do {
    r0 = rand () | (int64_t) rand () << 31;
    r1 = rand () | (int64_t) rand () << 31;
    o.u = r0^((uint64_t)r1<<32);
  } while((o.u<<1)>=(0x7ffull<<53));
  return o.f;
}

static int check (double x){
  b64u64_u yr = {.f = rfun(x)}, yt = {.f = tfun(x)};
  if (yr.u != yt.u) {
    printf("test_fun and ref_fun differ for x=%a\n", x);
    printf("test_fun gives %a\n", yt.f);
    printf(" ref_fun gives %a\n", yr.f);
    return -1;
  }
  return 0;
}

static void check_random(int seed, double a, double b, int64_t ntests){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  if (verbose)
    printf("seed = %d\n",seed);
  srand(seed);
  int fail = 0, maxfail = 10;
  double s = (b - a)*0.5, m = (a+b)*0.5;
  int64_t count = 0;
  while(1){
    int64_t i = 0, n = 10*1000;
    for(;i<n;i++){
      double x = m + rand_arg(s);
      if(check(x)) fail++;
      if(fail>=maxfail) break;
    }
    count += i;
    if (verbose)
      printf("failure(s) %d, total %"PRIx64"\n",fail,count);
    if(count>=ntests) break;
    if(fail>=maxfail) break;
  }
  if (verbose)
    printf("%d fails per %"PRIx64" calls or %.1e %%\n",
           fail, count, (double)fail/count*100);
}

static void call_random(int seed, int64_t n, double a, double b){
  fesetround(rnd1[rnd]);
  srand(seed);
  double s = (b - a)*0.5, m = (a+b)*0.5;
  for(int64_t j=0;j<n;j++){
    double x = m + rand_arg(s);
    tfun(x);
  }
}

static void scan_consecutive(int64_t n, double x){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  double dir = __builtin_inf();
  if(n<0) {
    dir = -dir;
    n = -n;
  }
  int64_t fail = 0;
  for(int64_t j=0;j<n;j++){
    if((fail += check(x)<0)>10) break;
    x = nextafter(x, dir);
  }
}

static void check_val(double x){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  check(x);
}

static void check_random_all(int seed, double a, double b){
  int nthreads = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
  nthreads = omp_get_num_threads();
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for(int i = 0; i < nthreads; i++)
    check_random(seed + i, a, b, CORE_MATH_TESTS / nthreads);
}

static void check_random_p(int seed, int64_t ntests){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  if (verbose)
    printf("seed = %d\n",seed);
  srand(seed);
  int fail = 0, maxfail = 10;
  int64_t count = 0;
  while(1){
    int64_t i = 0, n = 10*1000;
    for(;i<n;i++){
      double x = rand_arg2();
      if(check(x)) fail++;
      if(fail>=maxfail) break;
    }
    count += i;
    if (verbose)
      printf("failure(s) %d, total %"PRIx64"\n",fail,count);
    if(count>=ntests) break;
    if(fail>=maxfail) break;
  }
  if (verbose)
    printf("%d fails per %"PRIx64" calls or %.1e %%\n",
           fail, count, (double)fail/count*100);
}

static void check_random_all_p(int seed){
  int nthreads = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
  nthreads = omp_get_num_threads();
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for(int i = 0; i < nthreads; i++)
    check_random_p(seed + i, CORE_MATH_TESTS / nthreads);
}

int64_t parselong(const char *str){
  char *endptr;
  errno = 0;    /* To distinguish success/failure after call */
  int64_t val = strtoll(str, &endptr, 0);
  /* Check for various possible errors. */
  if(errno != 0) {
    perror("strtol");
    exit(EXIT_FAILURE);
  }
  if(endptr == str) {
    fprintf(stderr, "No digits were found\n");
    exit(EXIT_FAILURE);
  }
  return val;
}

int main(int argc, char *argv[]){
  static struct option opts[] = {
    { "rndn",        no_argument, 0, 'n'},
    { "rndz",        no_argument, 0, 'z'},
    { "rndu",        no_argument, 0, 'u'},
    { "rndd",        no_argument, 0, 'd'},
    { "help",        no_argument, 0, 'h'},
    {"verbose",      no_argument, 0, 'v'},
    {"thread",       no_argument, 0, 't'},
    {   "exp",       no_argument, 0, 'p'},
    { "seed",  required_argument, 0, 's'},
    {"darts",  required_argument, 0, 'D'},
    {"conseq", required_argument, 0, 'C'},
    {  "rnd",  required_argument, 0, 'r'},
    {"input",  required_argument, 0, 'i'},
    {      0,                  0, 0,  0 }
  };
  int thread = 1, seed = getpid (), darts = 0, conseq = 0, p = 1;
  double x = __builtin_nan(""), a = -1, b = 1;
  int64_t n = 10*1000;
  while(1) {
    int ind = 0, c = getopt_long(argc, argv, "nudzhvtps:D:C:r:i:x:a:b:", opts, &ind);
    if(c == -1) break;
    switch(c) {
    case 'a': a = strtod(optarg,NULL); break;
    case 'b': b = strtod(optarg,NULL); break;
    case 'n': rnd = 0; break;
    case 'z': rnd = 1; break;
    case 'u': rnd = 2; break;
    case 'd': rnd = 3; break;
    case 'v': verbose = 1; break;
    case 't': thread = 1; break;
    case 'p': p = 1; break;
    case 's': seed = parselong(optarg); break;
    case 'D': darts = 1; n = parselong(optarg); break;
    case 'C': conseq = 1; n = parselong(optarg); break;
    case 'r': rnd = parselong(optarg);
      if(rnd<0||rnd>3) {
        fprintf(stderr, "Rounding mode %d is outside of the range [0,3].\n",rnd);
        exit(EXIT_FAILURE);
      }
      break;
    case 'i':
      break;
    case 'h': /* print a help message (to be written) */  break;
    case 'x': x = strtod(optarg, NULL);
      break;
    default:
      break;
    }
  }

  if(x==x){
    check_val(x);
  } else {
    if(darts){
      call_random(seed, n, a, b);
    } else if(conseq){
      scan_consecutive(n, a);
    } else {
      if(p){
	if(thread)
	  check_random_all_p(seed);
	else
	  check_random_p(seed, CORE_MATH_TESTS);
      } else {
	if(thread)
	  check_random_all(seed, a, b);
	else
	  check_random(seed, a, b, CORE_MATH_TESTS);
      }
    }
  }
  return 0;
}
