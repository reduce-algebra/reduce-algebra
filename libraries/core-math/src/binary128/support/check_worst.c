/* Check correctness of bivariate quadruple-precision function on provided inputs

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
#define _GNU_SOURCE
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

__float128 cr_function_under_test(__float128, __float128);
__float128 ref_function_under_test(__float128, __float128);
void ref_init(void);
int ref_fesetround(int);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd;
FILE *instream;

static int nextarg(__float128*,__float128*);
static void test();
static void check(__float128, __float128);

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
    int ind = 0, c = getopt_long(argc, argv, "nudzhr:i:x:m:s:", opts, &ind);
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
  return  (asuint128(x)<<1) > (u128)0x7fff<<113;
}

static inline int is_equal(__float128 x, __float128 y){
  if(is_nan(x)) return is_nan(y);
  if(is_nan(y)) return is_nan(x);
  return asuint128(x) == asuint128(y);
}

#ifdef CORE_MATH_SUPPORT_ERRNO
static int is_num(__float128 x){
  b128u128_u v = {.f = x};
  return (v.a<<1) < (u128)0x7fff<<113;
}
#endif

static inline void treatfailure(){
#ifndef DO_NOT_ABORT
  exit(1);
#endif
}

/* We have to write some special code to print errors since:
   (1) the printf hook for quadmath is not installed everywhere,
       thus printf ("%Qa", ...) does not work everywhere
   (2) quadmath_snprintf can only print a single quad,
       but quadmath_snprintf (..., "x=%Qa", x) does not work
*/
static void
error (char *err, __float128 x, __float128 y, __float128 z)
{
  char buf[256];
  int n;
  n = snprintf (buf, sizeof buf, "%s", err);
  n += snprintf (buf + n, sizeof buf - n, " for x=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", x);
  n += snprintf (buf + n, sizeof buf - n, " y=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", y);
  n += snprintf (buf + n, sizeof buf - n, " (z=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", z);
  n += snprintf (buf + n, sizeof buf - n, ")");
  printf ("%s\n", buf);
  treatfailure();
}

static void
error2 (__float128 x, __float128 y, __float128 r, __float128 z){
  char buf[256];
  int n;
  n = snprintf (buf, sizeof buf, "FAIL x=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", x);
  n += snprintf (buf + n, sizeof buf - n, " y=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", y);
  n += snprintf (buf + n, sizeof buf - n, " ref=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", r);
  n += snprintf (buf + n, sizeof buf - n, " z=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", z);
  printf ("%s\n", buf);
  treatfailure();
}

static void check_flag(int flag, __float128 x, __float128 y, __float128 z){
  char buf[256];
  const char *str;
  mpfr_flags_t mflag;
  switch(flag){
  case FE_UNDERFLOW: str = "underflow"; mflag = MPFR_FLAGS_UNDERFLOW; break;
  case FE_OVERFLOW: str = "overflow"; mflag = MPFR_FLAGS_OVERFLOW; break;
  case FE_INEXACT: str = "inexact"; mflag = MPFR_FLAGS_INEXACT; break;
  case FE_DIVBYZERO: str = "division by zero"; mflag = MPFR_FLAGS_DIVBY0; break;
  default: str = "unknown"; mflag = 0; break;
  }
  mflag = !!mpfr_flags_test(mflag);
  if(flag == FE_UNDERFLOW)
    mflag &= !!mpfr_flags_test(MPFR_FLAGS_INEXACT);
  flag = !!fetestexcept(flag);

  if (flag && !mflag){
    snprintf(buf, sizeof buf, "Spurious %s exception", str);
    error (buf, x, y, z);
  }
  if (!flag && mflag){
    snprintf(buf, sizeof buf, "Missing %s exception", str);
    error (buf, x, y, z);
  }
}

void check (__float128 x, __float128 y){
  __float128 zr, zt;

  mpfr_flags_clear (MPFR_FLAGS_ALL);
  zr = ref_function_under_test(x, y);

#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = 0;
#endif
  feclearexcept (FE_ALL_EXCEPT);
  zt = cr_function_under_test(x, y);

  if (!is_equal (zr, zt))
    if(++failures<maxfailures) error2(x, y, zr, zt);

  // Check for spurious/missing underflow exception
  check_flag(FE_UNDERFLOW, x, y, zt);
  // Check for spurious/missing overflow exception
  check_flag(FE_OVERFLOW, x, y, zt);
#ifdef CORE_MATH_CHECK_INEXACT
  // Check for spurious/missing inexact exception
  check_flag(FE_INEXACT, x, y, zt);
#endif

#ifdef CORE_MATH_SUPPORT_ERRNO
  /* If (x,y) are normal numbers and an overflow occurs, we should
     have errno = ERANGE. */
  int expected_erange = is_num (x) && is_num (y) && !!mpfr_flags_test(MPFR_FLAGS_OVERFLOW);
  if (expected_erange && errno != ERANGE)
    error ("Missing errno=ERANGE", x, y, zt);
  if (!expected_erange && errno == ERANGE)
    error ("Spurious errno=ERANGE", x, y, zt);
#endif

  // Check flags are not reset
  // check underflow flag is not reset
  feraiseexcept ( FE_UNDERFLOW);
  zt = cr_function_under_test (x, y);
  if (!fetestexcept (FE_UNDERFLOW)) {
    error ("Underflow exception was reset", x, y, zt);
  }

  // check divbyzero flag is not reset
  feraiseexcept (FE_DIVBYZERO);
  zt = cr_function_under_test (x, y);
  if (!fetestexcept (FE_DIVBYZERO)) {
    error ("Underflow exception was reset", x, y, zt);
  }

  // check inexact flag is not reset
  feraiseexcept ( FE_INEXACT);
  zt = cr_function_under_test (x, y);
  if (!fetestexcept (FE_INEXACT)) {
    error ("Inexact exception was reset", x, y, zt);
  }

  // check invalid flag is not reset
  feraiseexcept ( FE_INVALID);
  zt = cr_function_under_test (x, y);
  if (!fetestexcept (FE_INVALID)) {
    error ("Invalid exception was reset", x, y, zt);
  }

  // check overflow flag is not reset
  feraiseexcept ( FE_OVERFLOW);
  zt = cr_function_under_test (x, y);
  if (!fetestexcept (FE_OVERFLOW)) {
    error ("Overflow exception was reset", x, y, zt);
  }

}

void test(){
  int count = 0;
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  __float128 x,y;
  while (nextarg(&x,&y)) {
    check (x, y);
    ++count;
  }
  printf("%d tests passed, %d failure(s)\n", count, failures);
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

static __float128 mystrtoflt128(const char *p, char **pn){
  __float128 res = strtoflt128(p, pn);
  if (*pn > p) return res;
  char *pos = strcasestr(p, "nan");
  if (pos == NULL) return res;
  uint64_t nan = 0;
  if (pos - 1 >= p){
    if(strncasecmp(pos-1, "q", 1) == 0) nan = 1;
    if(strncasecmp(pos-1, "s", 1) == 0) nan = 0;
  }
  if (pos - 2 >= p){
    if(strncasecmp(pos-2, "+", 1) == 0) nan |= 0;
    if(strncasecmp(pos-2, "-", 1) == 0) nan |= 2;
  }
  *pn = pos + 3;
  b128u128_u u;
  u.b[1] = (nan&2)<<62|0x7fffull<<48|1ul<<((nan&1)+46);
  u.b[0] = 0;
  return u.f;
}

int nextarg(__float128 *x, __float128 *y){
  static char *buf = NULL, *pos;
  static size_t nbuf = 0;
  if(buf==NULL || !pos){
    int stat = fillbuf(&buf, &nbuf);
    if(stat==0) return 0;
    pos = buf;
  }
  char *pos1;

  *x = mystrtoflt128(pos, &pos1);
  if (pos1 == pos) return 0;
  pos = pos1;

  *y = mystrtoflt128(pos, &pos1);
  if (pos1 == pos) return 0;
  pos = NULL;
  return 1;
}
