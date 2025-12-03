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

double rand_arg(double s, unsigned int *seed){
  int64_t r0,r1;
  r0 = rand_r (seed) | (int64_t) rand_r (seed) << 31;
  r1 = rand_r (seed) | (int64_t) rand_r (seed) << 31;
  b64u64_u o = {.u = (((r0^((uint64_t)r1<<32))&(~(0x7ffull<<52)))|(0x3ffull<<52))};
  double r = o.f-copysign(1,o.f);
  return r*s;
}

double rand_arg2(unsigned int *seed){
  int64_t r0,r1;
  b64u64_u o;
  do {
    r0 = rand_r (seed) | (int64_t) rand_r (seed) << 31;
    r1 = rand_r (seed) | (int64_t) rand_r (seed) << 31;
    o.u = r0^((uint64_t)r1<<32);
  } while((o.u<<1)>=(0x7ffull<<53));
  return o.f;
}

static void check (double x){
  b64u64_u yr = {.f = rfun(x)}, yt = {.f = tfun(x)};
  if (yr.u != yt.u) {
    printf("test_fun and ref_fun differ for x=%a\n", x);
    printf("test_fun gives %a\n", yt.f);
    printf(" ref_fun gives %a\n", yr.f);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
}

static void check_random(unsigned int seed, double a, double b, int64_t ntests){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  if (verbose)
    printf("seed = %d\n",seed);
  int fail = 0, maxfail = 10;
  double s = (b - a)*0.5, m = (a+b)*0.5;
  int64_t count = 0;
  while(1){
    int64_t i = 0, n = 10*1000;
    for(;i<n;i++){
      double x = m + rand_arg(s, &seed);
      check(x);
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

static void call_random(unsigned int seed, int64_t n, double a, double b){
  fesetround(rnd1[rnd]);
  double s = (b - a)*0.5, m = (a+b)*0.5;
  for(int64_t j=0;j<n;j++){
    double x = m + rand_arg(s, &seed);
    tfun(x);
  }
}

double fasttwosum(double a, double b, double *e){
  double t = a + b;
  *e = (a-t)+b;
  return t;
}

// get a double-double linear approximation of acosh(x)
static void
dd_acosh_p (double *c0h, double *c0l, double *c1h, double *c1l, double x){
  mpfr_t t;
  mpfr_init2 (t, 107);

  mpfr_set_d (t, x, MPFR_RNDN);
  mpfr_acosh (t, t, MPFR_RNDN);
  *c0h = mpfr_get_d (t, MPFR_RNDN);
  mpfr_sub_d (t, t, *c0h, MPFR_RNDN);
  *c0l = mpfr_get_d (t, MPFR_RNDN);
#if 1
  mpfr_set_d (t, x, MPFR_RNDN);
  mpfr_sqr (t, t, MPFR_RNDN);
  mpfr_sub_d (t, t, 1.0, MPFR_RNDN);
  mpfr_rec_sqrt(t, t, MPFR_RNDN);
  *c1h = mpfr_get_d (t, MPFR_RNDN);
  mpfr_sub_d (t, t, *c1h, MPFR_RNDN);
  *c1l = mpfr_get_d (t, MPFR_RNDN);
#else
  double exm1, xm1 = fasttwosum(x,-1.0, &exm1);
  double exp1, xp1 = fasttwosum(x, 1.0, &exp1);
  double x2m1 = xm1*xp1, ex2m1 = exm1*xp1 + exp1*xm1 + fma(xm1,xp1, -x2m1);
  double sx2m1 = sqrt(x2m1), d = 1.0 / sx2m1, esx2m1 = (ex2m1 - fma(sx2m1, sx2m1, -x2m1))*0.5*d;
  double ed = (fma(d,-sx2m1, 1.0) - (esx2m1*d)*(1.0-(esx2m1*d)))*d;
  *c1h = d;
  *c1l = ed;
#endif

  mpfr_clear (t);
}

static void scan_consecutive(int64_t n, double x){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  int64_t count = 0, reportstride = 1000l*1000l*1000l, nreport = reportstride;
  while (n) {
    /* acosh(x+h) ~= (c0h+c0l) + (c1h+c1l)*h + c2*h^2 + c3*h^3 + c4*h^4 local Taylor expansion*/
    double c0h, c0l, c1h, c1l;
    dd_acosh_p (&c0h, &c0l, &c1h, &c1l, x);
    double t2 = c1h*c1h, t3 = t2*c1h, t4 = t2*t2;
    double c2 = t3*x*-0.5;
    double c3 = t2*t3*(2*x*x+1)/6;
    double c4 = t4*t3*x*(2*x*x+3)*-0.125;

    int e; frexp (x, &e);
    /* 2^(e-1) <= |x| < 2^e thus ulp(x) = 2^(e-53) */
    double h = ldexp(1.0, e - 53);

    // c4*(jmax*h)^4 < 0x1p-100*c0 -- fourth order term is less then 0x1p-100 of the function value
    int64_t jmax = 0x1p-25*sqrt(sqrt(fabs(c0h/c4)))/h;
    if (jmax > n) jmax = n; // cap to n
    double nbnd = ldexp(1.0,e);//next binade boundary
    if (h*jmax + x > nbnd){ // do not cross the binade boundary with ulp unchanged
      jmax = (nbnd - x)/h;
    }
    const int64_t ks = 256;
    double fe, ref[ks];
    for(int64_t j=0;j<jmax;){
      double xl = j*h, fl, fh = fasttwosum(c0h, c1h*xl, &fl);
      fl += (((c4*xl + c3)*xl + c2)*xl + c1l)*xl + c0l;
      fh = fasttwosum(fh, fl, &fl);
      double d1l = ((((((4*j + 6)*j + 4)*j + 1)*(c4*h) + c3*((j + 1)*3*j + 1))*h + c2*(2*j+1))*h + c1l)*h, d1h = c1h*h;
      double d2 = 2*((c4*h*((6*j + 12)*j + 7) + c3*(3*j + 3))*h + c2)*h*h;
      int kmax = ks;
      if(jmax-j<ks) kmax = jmax-j;
      for(int k=0;k<kmax;k++){ // fill first an array of almost correctly rounded results
	ref[k] = fh + fl;
	fh = fasttwosum(fh, d1h, &fe); fl += fe + d1l;
	d1l += d2;
      }
      j += kmax;
#if 0
      // control of accuracy -- with current options and x=0x1.08p0 the accuracy is ~0x1p-94
      double p0h, p0l, p1h, p1l;
      dd_acosh_p (&p0h, &p0l, &p1h, &p1l, x + h*j);
      printf("%ld %a\n", j, (fh-p0h)+(fl-p0l));
#else
      for(int k=0;k<kmax;k++){
	if (__builtin_expect(tfun(x) != ref[k],0)) // expensive test
	  check(x);
	x += h;
      }
#endif
    }
    n -= jmax;
    if( (count += jmax) > nreport){
      nreport += reportstride;
      printf("n_tested = %ld x_current = %a\n", count, x);
    }
  }
}

static void check_val(double x){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  check(x);
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000UL /* total number of tests */
#endif

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

static void check_random_p(unsigned int seed, int64_t ntests){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  if (verbose)
    printf("seed = %d\n",seed);
  int fail = 0, maxfail = 10;
  int64_t count = 0;
  while(1){
    int64_t i = 0, n = 10*1000;
    for(;i<n;i++){
      double x = rand_arg2(&seed);
      check(x);
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

static void check_random_all_p (int seed){
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
  int thread = 1, seed = getpid (), darts = 0, conseq = 0, p = 0;
  double x = __builtin_nan(""), a = 1, b = 2;
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
