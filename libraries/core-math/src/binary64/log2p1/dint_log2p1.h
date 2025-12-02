/* Correctly-rounded power function for two binary64 values.

Copyright (c) 2022-2025 CERN.
Author: Tom Hubrecht

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

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, exp_dRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
  This file contains type definition and functions to manipulate the dint64_t
  data type used in the second iteration of Ziv's method. It is composed of two
  uint64_t values for the significand and the exponent is represented by a
  signed int64_t value.
*/

#ifndef DINT_H
#define DINT_H

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

/*
  Type and structure definitions
*/

#ifndef UINT128_T
#define UINT128_T

#if (defined(__clang__) && __clang_major__ >= 14) || (defined(__GNUC__) && __GNUC__ >= 14 && __BITINT_MAXWIDTH__ && __BITINT_MAXWIDTH__ >= 128)
typedef unsigned _BitInt(128) u128;
#else
typedef unsigned __int128 u128;
#endif

typedef union {
  u128 r;
  struct {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    uint64_t l, h;
#else
    uint64_t h, l;
#endif
  };
} uint128_t;

// Add two 128 bit integers and return 1 if an overflow occured
static inline int addu_128(uint128_t a, uint128_t b, uint128_t *r) {
  r->l = a.l + b.l;
  r->h = a.h + b.h + (r->l < a.l);

  // Return the overflow
  return r->h == a.h ? r->l < a.l : r->h < a.h;
}

// Subtract two 128 bit integers and return 1 if an underflow occured
static inline int subu_128(uint128_t a, uint128_t b, uint128_t *r) {
  uint128_t c = {.r = -b.r};
  r->l = a.l + c.l;
  r->h = a.h + c.h + (r->l < a.l);

  // Return the underflow
  return a.h != r->h ? r->h > a.h : r->l > a.l;
}

static inline int cmp(int64_t a, int64_t b) { return (a > b) - (a < b); }

static inline int cmpu(uint64_t a, uint64_t b) { return (a > b) - (a < b); }

#endif

typedef struct {
  uint64_t hi;
  uint64_t lo;
  int64_t ex;
  uint64_t sgn;
} dint64_t;

/*
  Constants
*/

static const dint64_t ONE = {
    .hi = 0x8000000000000000, .lo = 0x0, .ex = 0, .sgn = 0x0};

static const dint64_t M_ONE = {
    .hi = 0x8000000000000000, .lo = 0x0, .ex = 0, .sgn = 0x1};

/* the following is an approximation of log(2), with absolute error less
   than 2^-129.97: |(hi/2^63+lo/2^127)*2^-1 - log(2)| < 2^-129.97 */
static const dint64_t LOG2 = {
    .hi = 0xb17217f7d1cf79ab, .lo = 0xc9e3b39803f2f6af, .ex = -1, .sgn = 0x0};

/* the following is an approximation of 2^12/log(2), with absolute error less
   than 2^-118.63: |(hi/2^63+lo/2^127)*2^12 - 2^12/log(2)| < 2^-118.63 */
static const dint64_t LOG2_INV = {
    .hi = 0xb8aa3b295c17f0bb, .lo = 0xbe87fed0691d3e89, .ex = 12, .sgn = 0x0};

static const dint64_t ZERO = {.hi = 0x0, .lo = 0x0, .ex = 0, .sgn = 0x0};

/*
  Base functions
*/

// Copy a dint64_t value
static inline void cp_dint(dint64_t *r, const dint64_t *a) {
  r->ex = a->ex;
  r->hi = a->hi;
  r->lo = a->lo;
  r->sgn = a->sgn;
}

static inline signed char cmp_dint(const dint64_t *a, const dint64_t *b) {
  return cmp(a->ex, b->ex)    ? cmp(a->ex, b->ex)
         : cmpu(a->hi, b->hi) ? cmpu(a->hi, b->hi)
                              : cmpu(a->lo, b->lo);
}

// Add two dint64_t values
static inline void add_dint(dint64_t *r, const dint64_t *a, const dint64_t *b) {
  if (!(a->hi | a->lo)) {
    cp_dint(r, b);
    return;
  }

  if (!(b->hi | b->lo)) {
    cp_dint(r, a);
    return;
  }

  switch (cmp_dint(a, b)) {
  case 0:
    if (a->sgn ^ b->sgn) {
      cp_dint(r, &ZERO);
      return;
    }

    cp_dint(r, a);
    r->ex++;
    return;

  case -1:
    add_dint(r, b, a);
    return;
  }

  // From now on, |A| > |B|

  uint128_t A = {.h = a->hi, .l = a->lo};
  uint128_t B = {.h = b->hi, .l = b->lo};
  int64_t m_ex = a->ex;

  if (a->ex > b->ex) {
    int sh = a->ex - b->ex;
    // round to nearest
    if (sh <= 128)
      B.r += 0x1 & (B.r >> (sh - 1));
    if (sh < 128)
      B.r = B.r >> sh;
    else
      B.r = 0;
  }

  uint128_t C;
  unsigned char sgn = a->sgn;

  if (a->sgn ^ b->sgn) {
    // a and b have different signs C = A + (-B)
    subu_128(A, B, &C);
  } else {
    if (addu_128(A, B, &C)) {
      C.r += C.l & 0x1;
      C.r = ((u128)1 << 127) | (C.r >> 1);
      m_ex++;
    }
  }

  uint64_t ex =
      C.h ? __builtin_clzll(C.h) : 64 + (C.l ? __builtin_clzll(C.l) : a->ex);
  C.r = C.r << ex;

  r->sgn = sgn;
  r->hi = C.h;
  r->lo = C.l;
  r->ex = m_ex - ex;
}

// Multiply two dint64_t numbers, with 126 bits of accuracy
static inline void mul_dint(dint64_t *r, const dint64_t *a, const dint64_t *b) {
  uint128_t t = {.r = (u128)(a->hi) * (u128)(b->hi)};
  uint128_t m1 = {.r = (u128)(a->hi) * (u128)(b->lo)};
  uint128_t m2 = {.r = (u128)(a->lo) * (u128)(b->hi)};

  uint128_t m;
  // If we only garantee 127 bits of accuracy, we improve the simplicity of the
  // code uint64_t l = ((u128)(a->lo) * (u128)(b->lo)) >> 64; m.l += l; m.h +=
  // (m.l < l);
  t.h += addu_128(m1, m2, &m);
  t.r += m.h;

  // Ensure that r->hi starts with a 1
  uint64_t ex = !(t.h >> 63);
  if (ex)
    t.r = t.r << 1;

  t.r += (m.l >> 63);

  r->hi = t.h;
  r->lo = t.l;

  // Exponent and sign
  r->ex = a->ex + b->ex - ex + 1;
  r->sgn = a->sgn ^ b->sgn;
}

// Multiply an integer with a dint64_t variable
static inline void mul_dint_2(dint64_t *r, int64_t b, const dint64_t *a) {
  uint128_t t;

  if (!b) {
    cp_dint(r, &ZERO);
    return;
  }

  uint64_t c = b < 0 ? -b : b;
  r->sgn = b < 0 ? !a->sgn : a->sgn;

  t.r = (u128)(a->hi) * (u128)c;

  int m = t.h ? __builtin_clzll(t.h) : 64;
  t.r = (t.r << m);

  // Will pose issues if b is too large but for now we assume it never happens
  // TODO: FIXME
  uint128_t l = {.r = (u128)(a->lo) * (u128)c};
  l.r = (l.r << (m - 1)) >> 63;

  if (addu_128(l, t, &t)) {
    t.r += t.r & 0x1;
    t.r = ((u128)1 << 127) | (t.r >> 1);
    m--;
  }

  r->hi = t.h;
  r->lo = t.l;
  r->ex = a->ex + 64 - m;
}

typedef union {
  double f;
  uint64_t u;
} f64_u;

// Extract both the significand and exponent of a double
static inline void fast_extract(int64_t *e, uint64_t *m, double x) {
  f64_u _x = {.f = x};

  *e = (_x.u >> 52) & 0x7ff;
  *m = (_x.u & (~0ull >> 12)) + (*e ? (1ull << 52) : 0);
  *e = *e - 0x3ff;
}

// Convert a double to the corresponding dint64_t value
static inline void dint_fromd(dint64_t *a, double b) {
  fast_extract(&a->ex, &a->hi, b);

  uint32_t t = (a->hi) ? __builtin_clzll(a->hi) : 0;

  a->sgn = b < 0.0;
  a->hi = a->hi << t;
  a->ex = a->ex - (t > 11 ? t - 12 : 0);
  a->lo = 0;
}

#if 0
// Prints a dint64_t value for debugging purposes
static inline void print_dint(const dint64_t *a) {
  printf("{.hi=0x%"PRIx64", .lo=0x%"PRIx64", .ex=%"PRId64", .sgn=0x%"PRIx64"}\n", a->hi, a->lo, a->ex,
         a->sgn);
}
#endif

/* put in r an approximation of 1/a, assuming a is not zero */
static inline void inv_dint (dint64_t *r, double a)
{
  dint64_t q, A;
  // we convert 4/a and divide by 4 to avoid a spurious underflow
  dint_fromd (r, 4.0 / a); /* accurate to about 53 bits */
  r->ex -= 2;
  /* we use Newton's iteration: r -> r + r*(1-a*r) */
  dint_fromd (&A, -a);
  mul_dint (&q, &A, r);    /* -a*r */
  add_dint (&q, &ONE, &q); /* 1-a*r */
  mul_dint (&q, r, &q);    /* r*(1-a*r) */
  add_dint (r, r, &q);
}

/* put in r an approximation of b/a, assuming a is not zero */
static inline void div_dint (dint64_t *r, double b, double a)
{
  dint64_t B;
  inv_dint (r, a);
  dint_fromd (&B, b);
  mul_dint (r, r, &B);
}

#endif
