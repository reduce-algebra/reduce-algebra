/* Various special tests

Copyright (c) 2023-2025 Alexei Sibidanov and Paul Zimmermann

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

/* Usage: ./check_special -t -a -10 -b 10
          ./check_special -t -p
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
#include <mpfr.h>
#include "function_under_test.h"

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 200000000UL /* total number of tests */
#endif

double cr_function_under_test(double);
double ref_function_under_test(double);

int ref_fesetround(int);
void ref_init(void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd;
int verbose = 0;
unsigned long tested = 0;

static inline double tfun(double x){
  return cr_function_under_test(x);
}

static inline double rfun(double x){
  return ref_function_under_test(x);
}

typedef union {double f; uint64_t u;} b64u64_u;

static inline uint64_t
asuint64 (double x)
{
  b64u64_u u;
  u.f = x;
  return u.u;
}

static double
asfloat64 (uint64_t n)
{
  b64u64_u u;
  u.u = n;
  return u.f;
}

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
#pragma omp atomic update
  tested ++;
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

// put in h+l a double-double approximation of atanh(x)
static void
dd_atanh (double *h, double *l, double x)
{
  mpfr_t t;
  mpfr_init2 (t, 107);
  mpfr_set_d (t, x, MPFR_RNDN);
  mpfr_atanh (t, t, MPFR_RNDN);
  *h = mpfr_get_d (t, MPFR_RNDN);
  mpfr_sub_d (t, t, *h, MPFR_RNDN);
  *l = mpfr_get_d (t, MPFR_RNDN);
  mpfr_clear (t);
}

static void scan_consecutive(int64_t n, double x){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  if (n < 0) {
    n = -n;
    x = asfloat64 (asuint64 (x) - n);
  }
  int64_t n0 = n;
  while (n) {
    double h, l, d, dd;
    dd_atanh (&h, &l, x);
    d = 1.0 / (1.0 - x * x); // derivative of atanh(x)
    dd = fabs(2.0 * d * x / (1.0 - x * x)); // absolute value of 2nd derivative
    int e;
    frexp (x, &e);
    /* 2^(e-1) <= |x| < 2^e thus ulp(x) = 2^(e-53) */
    d = ldexp (d, e - 53); // multiply d by ulp(x)
    dd = ldexp (dd, 2 * (e - 53)); // multiply dd by ulp(x)^2
    /* we want j^2*dd < 2^-11 ulp(h) so that the 2nd-order term
       produces an error bounded by 2^-11 ulp(h), to that MPFR
       will be called with probability about 2^-11.
       Thus approximately j^2*dd < 2^-64 h,
       or j < 2^-32 sqrt(h/dd) */
    int64_t jmax = 0x1p-32 * sqrt (h / dd);
    if (jmax > n) jmax = n; // cap to n
    if (jmax == 0) jmax = 1; // avoid infinite loop
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
    for(int64_t j=0;j<jmax;j++){
      b64u64_u v = {.f = x};
      v.u += j;
      double t = tfun (v.f);
      // atanh(x+j*u) is approximated by h + l + j*d
      double w = h + __builtin_fma (j, d, l);
      if (t != w) // expensive test
        check(v.f);
    }
    n -= jmax;
    x += jmax * ldexp (1.0, e - 53);
  }
  printf ("checked %lu values, expensive checks %lu\n", n0, tested);
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
  // for atanh, p=1 makes little sense since the domain is (-1,1)
  int thread = 1, seed = getpid (), darts = 0, conseq = 0, p = 0;
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
