/* Check correctness of univariate quadruple-precision function on provided inputs

Copyright (c) 2025 Alexei Sibidanov <sibid@uvic.ca>.

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

#ifndef __APPLE__
#define _POSIX_C_SOURCE 200809L  /* for getline */
#endif /* !__APPLE */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fenv.h>
#include <getopt.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>
#include <quadmath.h>
#include <mpfr.h>

#include "function_under_test.h"

typedef unsigned __int128 u128;
typedef union {__float128 f; u128 a; uint64_t b[2];} b128u128_u;

__float128 cr_function_under_test(__float128);
__float128 ref_function_under_test(__float128);
int ref_fesetround(int);
void ref_init(void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd;
FILE *instream;

int transform(__float128, __float128*);
int nextarg(__float128*);
static void test();

int64_t parselong(const char *str){
  char *endptr;
  errno = 0;    /* To distinguish success/failure after call */
  int64_t val = strtoll(str, &endptr, 0);
  /* Check for various possible errors. */
  if (errno != 0) {
    perror("strtol");
    exit(EXIT_FAILURE);
  }
  if (endptr == str) {
    fprintf(stderr, "No digits were found\n");
    exit(EXIT_FAILURE);
  }
  return val;
}

int failures = 0;
int maxfailures = 10;

int main(int argc, char *argv[]){
  static struct option opts[] = {
    { "rndn",       no_argument, 0, 'n'},
    { "rndz",       no_argument, 0, 'z'},
    { "rndu",       no_argument, 0, 'u'},
    { "rndd",       no_argument, 0, 'd'},
    { "help",       no_argument, 0, 'h'},
    {  "rnd", required_argument, 0, 'r'},
    {"input", required_argument, 0, 'i'},
    { "maxf", required_argument, 0, 'm'},
    {      0,                 0, 0,  0 }
  };
  instream = stdin;
  const char *fname = NULL;
  while (1) {
    int ind = 0, c = getopt_long(argc, argv, "nudzhr:i:x:m:", opts, &ind);
    if (c == -1) break;
    switch (c) {
    case 'n': rnd = 0; break;
    case 'z': rnd = 1; break;
    case 'u': rnd = 2; break;
    case 'd': rnd = 3; break;
    case 'm': maxfailures = parselong(optarg); break;
    case 'r':
      rnd = parselong(optarg);
      if(rnd<0||rnd>3) {
	fprintf(stderr, "Rounding mode %d is outside of the range [0,3].\n",rnd);
	exit(EXIT_FAILURE);
      }
      break;
    case 'i':
      fname = optarg;
      break;
    case 'h': /* print a help message (to be written) */  break;
    }
  }

  if(fname){
    instream = fopen(fname, "r");
    if (instream == NULL) {
      fprintf(stderr, "Cannot open file %s for reading.\n",fname);
      exit(EXIT_FAILURE);
    }
  }

  test();

  fclose(instream);

  exit(EXIT_SUCCESS);
}

static inline u128 asuint128(__float128 f){
  b128u128_u u = {.f = f};
  return u.a;
}

/* define our own is_nan function to avoid depending from math.h */
static inline int is_nan(__float128 x){
  u128 u = asuint128(x) & ~((u128)1<<127);
  return u > (u128)0x7fff<<112;
}

static inline int is_equal(__float128 x, __float128 y){
  if(is_nan(x)) return is_nan(y);
  if(is_nan(y)) return is_nan(x);
  return asuint128(x) == asuint128(y);
}

#ifdef CORE_MATH_SUPPORT_ERRNO
static int is_inf (__float128 x)
{
  b128u128_u v = {.f = x};
  return ((v.a<<1)>>113) == 0x7fff && (v.a<<16) == 0;
}
#endif

/* We have to write some special code to print errors since:
   (1) the printf hook for quadmath is not installed everywhere,
       thus printf ("%Qa", ...) does not work everywhere
   (2) quadmath_snprintf can only print a single quad,
       but quadmath_snprintf (..., "x=%Qa", x) does not work
*/
static void
error (char *err, __float128 x, __float128 y)
{
  char buf[256];
  int n;
  n = snprintf (buf, sizeof buf, "%s", err);
  n += snprintf (buf + n, sizeof buf - n, " for x=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", x);
  n += snprintf (buf + n, sizeof buf - n, " (y=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", y);
  n += snprintf (buf + n, sizeof buf - n, ")");
  printf ("%s\n", buf);
}

static void
error2 (__float128 x, __float128 y, __float128 z)
{
  char buf[256];
  int n;
  n = snprintf (buf, sizeof buf, "FAIL x=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", x);
  n += snprintf (buf + n, sizeof buf - n, " ref=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", y);
  n += snprintf (buf + n, sizeof buf - n, " z=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", z);
  printf ("%s\n", buf);
}

static void check_one (__float128 x)
{
    b128u128_u zr, zt;
    mpfr_flags_clear (MPFR_FLAGS_INEXACT | MPFR_FLAGS_UNDERFLOW | MPFR_FLAGS_OVERFLOW);
    zr.f = ref_function_under_test(x);
#if defined(CORE_MATH_CHECK_INEXACT) || defined(CORE_MATH_SUPPORT_ERRNO)
    mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
    feclearexcept (FE_INEXACT | FE_UNDERFLOW | FE_OVERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = 0;
#endif
    zt.f = cr_function_under_test(x);
    if (!is_equal (zr.f, zt.f)) {
      if(++failures<maxfailures){
        error2 (x, zr.f, zt.f);
#ifndef DO_NOT_ABORT
        exit (1);
#endif
      }
    }

  // Check for spurious/missing underflow exception
  if (fetestexcept (FE_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    error ("Spurious underflow exception", x, zr.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }
  if (!fetestexcept (FE_UNDERFLOW) && mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    error ("Missing underflow exception", x, zr.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }

  // Check for spurious/missing overflow exception
  if (fetestexcept (FE_OVERFLOW) && !mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    error ("Spurious overflow exception", x, zr.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }
  if (!fetestexcept (FE_OVERFLOW) && mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    error ("Missing overflow exception", x, zr.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }

#ifdef CORE_MATH_CHECK_INEXACT
  int inex2 = fetestexcept (FE_INEXACT);
  if ((inex1 == 0) && (inex2 != 0))
  {
    error ("Spurious inexact exception", x, zr.f);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    error ("Missing inexact exception", x, zr.f);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
#endif

  // check errno
#ifdef CORE_MATH_SUPPORT_ERRNO
  // If x is a normal number and y is NaN, we should have errno = EDOM.
  int expected_edom = !is_nan (x) && is_nan (zr.f);
  if (expected_edom && errno != EDOM)
    {
      error ("Missing errno=EDOM", x, zr.f);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }
    if (!expected_edom && errno == EDOM)
    {
      error ("Spurious errno=EDOM", x, zr.f);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }

    /* If x is a normal number and a pole error (y exact infinity) or an
       overflow/underflow occurs, we should have errno = ERANGE. */
    int expected_erange = !is_nan (x) && !is_inf (x) &&
      ((is_inf (zr.f) && inex1 == 0) ||
       mpfr_flags_test (MPFR_FLAGS_OVERFLOW) ||
       mpfr_flags_test (MPFR_FLAGS_UNDERFLOW));
    if (expected_erange && errno != ERANGE)
    {
      error ("Missing errno=ERANGE", x, zr.f);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }
    if (!expected_erange && errno == ERANGE)
    {
      error ("Spurious errno=ERANGE", x, zr.f);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }
#endif

  // check underflow flag is not reset
  feraiseexcept (FE_UNDERFLOW);
  zt.f = cr_function_under_test (x);
  if (!fetestexcept (FE_UNDERFLOW)){
    error ("Underflow exception was reset", x, zt.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }

  // check divbyzero flag is not reset
  feraiseexcept (FE_DIVBYZERO);
  zt.f = cr_function_under_test (x);
  if (!fetestexcept (FE_DIVBYZERO)){
    error ("Underflow exception was reset", x, zt.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }

  // check inexact flag is not reset
  feraiseexcept (FE_INEXACT);
  zt.f = cr_function_under_test (x);
  if (!fetestexcept (FE_INEXACT)){
    error ("Underflow exception was reset", x, zt.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }

  // check invalid flag is not reset
  feraiseexcept (FE_INVALID);
  zt.f = cr_function_under_test (x);
  if (!fetestexcept (FE_INVALID)){
    error ("Underflow exception was reset", x, zt.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }

  // check overflow flag is not reset
  feraiseexcept (FE_OVERFLOW);
  zt.f = cr_function_under_test (x);
  if (!fetestexcept (FE_OVERFLOW)){
    error ("Underflow exception was reset", x, zt.f);
#ifdef DO_NOT_ABORT
    return;
#else
    exit(1);
#endif
  }
}

static void check (__float128 x) {
  check_one (x);
#ifdef WORST_SYMMETRIC
  check_one (-x);
#endif
}

static void test(){
  int count = 0;
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  __float128 x;
  while (nextarg(&x)) {
    check (x);
    ++count;
  }
  printf("%d tests passed, %d failure(s)\n", count, failures);
}

int transform(__float128 x, __float128 *out){
  static int first = 1;
  static b128u128_u px = {.f = __builtin_nanf128("")};
  static int64_t k;
  b128u128_u s = {.f = x};
  if (first || px.a != s.a) {
    first = 0;
    px.f = x;
    k = -1;
  }
  if(++k<2){
    s.b[1] ^= k<<63;
    *out = s.f;
    return 1;
  } else {
    return 0;
  }
}

int fillbuf(char **buf, size_t *nbuf){
  // fill the buffer
  ssize_t nget;
  while ((nget = getline(buf, nbuf, instream)) != -1) {
    char *pos = *buf, *ncom = strchr(pos, '#');
    if (ncom==pos) continue;
    if (ncom) memset(ncom, 0, *nbuf - (ncom - pos));
     // check that buffer is not empty
    int nonempty = 0;
    for (size_t i = 0, imax = strlen(pos); i<imax; i++) if (!isspace(pos[i])) { nonempty = 1; break;}
    if (nonempty) break;
  }
  if(nget == -1) {
    free(*buf);
    return 0;
  }
  return 1;
}

int nextarg(__float128 *x){
  static int first = 1;
  static __float128 arg = __builtin_nanf128("");
  if( !first ){
    if (transform(arg, x)) return 1;
  } else {
    first = 0;
  }
  static char *buf = NULL, *pos;
  static size_t nbuf = 0;
  do {
    if(buf==NULL || !*pos){
      int stat = fillbuf(&buf, &nbuf);
      if(stat==0) return 0;
      pos = buf;
    }
    while(*pos){
      char *pos1;
      errno = 0;
      arg = strtoflt128(pos, &pos1);
      if (errno == ERANGE) {transform(arg, x); return 1;} // just zero or infinity
      if (pos1 == pos) {pos++; continue;}
      pos = pos1;
      transform(arg, x); return 1;
    }
  } while(1);
}
