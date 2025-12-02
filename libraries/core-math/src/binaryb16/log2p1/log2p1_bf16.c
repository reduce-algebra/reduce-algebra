/* Correctly-rounded biased base-2 logarithm function for bfloat16 value.

Copyright (c) 2025 Paul Zimmermann

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

#include <stdint.h>
#include <errno.h>
#include <math.h> // only used during performance tests

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {__bf16 f; uint16_t u;} b16u16_u;
typedef union {float f; uint32_t u;} b32u32_u;

/* For 0 <= i1 < 2^8, T1[i1] approximates log2(x1), where the 16-bit
   encoding of x1 is i1*2^7 (i1 encodes the exponent of x1).
   Table copied from log2_bf16.c. */
static const float T1[] = {
 0, -0x1.f8p+6, -0x1.f4p+6, -0x1.fp+6, -0x1.ecp+6, -0x1.e8p+6, -0x1.e4p+6,
 -0x1.ep+6, -0x1.dcp+6, -0x1.d8p+6, -0x1.d4p+6, -0x1.dp+6, -0x1.ccp+6,
 -0x1.c8p+6, -0x1.c4p+6, -0x1.cp+6, -0x1.bcp+6, -0x1.b8p+6, -0x1.b4p+6,
 -0x1.bp+6, -0x1.acp+6, -0x1.a8p+6, -0x1.a4p+6, -0x1.ap+6, -0x1.9cp+6,
 -0x1.98p+6, -0x1.94p+6, -0x1.9p+6, -0x1.8cp+6, -0x1.88p+6, -0x1.84p+6,
 -0x1.8p+6, -0x1.7cp+6, -0x1.78p+6, -0x1.74p+6, -0x1.7p+6, -0x1.6cp+6,
 -0x1.68p+6, -0x1.64p+6, -0x1.6p+6, -0x1.5cp+6, -0x1.58p+6, -0x1.54p+6,
 -0x1.5p+6, -0x1.4cp+6, -0x1.48p+6, -0x1.44p+6, -0x1.4p+6, -0x1.3cp+6,
 -0x1.38p+6, -0x1.34p+6, -0x1.3p+6, -0x1.2cp+6, -0x1.28p+6, -0x1.24p+6,
 -0x1.2p+6, -0x1.1cp+6, -0x1.18p+6, -0x1.14p+6, -0x1.1p+6, -0x1.0cp+6,
 -0x1.08p+6, -0x1.04p+6, -0x1p+6, -0x1.f8p+5, -0x1.fp+5, -0x1.e8p+5,
 -0x1.ep+5, -0x1.d8p+5, -0x1.dp+5, -0x1.c8p+5, -0x1.cp+5, -0x1.b8p+5,
 -0x1.bp+5, -0x1.a8p+5, -0x1.ap+5, -0x1.98p+5, -0x1.9p+5, -0x1.88p+5,
 -0x1.8p+5, -0x1.78p+5, -0x1.7p+5, -0x1.68p+5, -0x1.6p+5, -0x1.58p+5,
 -0x1.5p+5, -0x1.48p+5, -0x1.4p+5, -0x1.38p+5, -0x1.3p+5, -0x1.28p+5,
 -0x1.2p+5, -0x1.18p+5, -0x1.1p+5, -0x1.08p+5, -0x1p+5, -0x1.fp+4, -0x1.ep+4,
 -0x1.dp+4, -0x1.cp+4, -0x1.bp+4, -0x1.ap+4, -0x1.9p+4, -0x1.8p+4, -0x1.7p+4,
 -0x1.6p+4, -0x1.5p+4, -0x1.4p+4, -0x1.3p+4, -0x1.2p+4, -0x1.1p+4, -0x1p+4,
 -0x1.ep+3, -0x1.cp+3, -0x1.ap+3, -0x1.8p+3, -0x1.6p+3, -0x1.4p+3, -0x1.2p+3,
 -0x1p+3, -0x1.cp+2, -0x1.8p+2, -0x1.4p+2, -0x1p+2, -0x1.8p+1, -0x1p+1,
 -0x1p+0, 0x0p+0, 0x1p+0, 0x1p+1, 0x1.8p+1, 0x1p+2, 0x1.4p+2, 0x1.8p+2,
 0x1.cp+2, 0x1p+3, 0x1.2p+3, 0x1.4p+3, 0x1.6p+3, 0x1.8p+3, 0x1.ap+3, 0x1.cp+3,
 0x1.ep+3, 0x1p+4, 0x1.1p+4, 0x1.2p+4, 0x1.3p+4, 0x1.4p+4, 0x1.5p+4, 0x1.6p+4,
 0x1.7p+4, 0x1.8p+4, 0x1.9p+4, 0x1.ap+4, 0x1.bp+4, 0x1.cp+4, 0x1.dp+4,
 0x1.ep+4, 0x1.fp+4, 0x1p+5, 0x1.08p+5, 0x1.1p+5, 0x1.18p+5, 0x1.2p+5,
 0x1.28p+5, 0x1.3p+5, 0x1.38p+5, 0x1.4p+5, 0x1.48p+5, 0x1.5p+5, 0x1.58p+5,
 0x1.6p+5, 0x1.68p+5, 0x1.7p+5, 0x1.78p+5, 0x1.8p+5, 0x1.88p+5, 0x1.9p+5,
 0x1.98p+5, 0x1.ap+5, 0x1.a8p+5, 0x1.bp+5, 0x1.b8p+5, 0x1.cp+5, 0x1.c8p+5,
 0x1.dp+5, 0x1.d8p+5, 0x1.ep+5, 0x1.e8p+5, 0x1.fp+5, 0x1.f8p+5, 0x1p+6,
 0x1.04p+6, 0x1.08p+6, 0x1.0cp+6, 0x1.1p+6, 0x1.14p+6, 0x1.18p+6, 0x1.1cp+6,
 0x1.2p+6, 0x1.24p+6, 0x1.28p+6, 0x1.2cp+6, 0x1.3p+6, 0x1.34p+6, 0x1.38p+6,
 0x1.3cp+6, 0x1.4p+6, 0x1.44p+6, 0x1.48p+6, 0x1.4cp+6, 0x1.5p+6, 0x1.54p+6,
 0x1.58p+6, 0x1.5cp+6, 0x1.6p+6, 0x1.64p+6, 0x1.68p+6, 0x1.6cp+6, 0x1.7p+6,
 0x1.74p+6, 0x1.78p+6, 0x1.7cp+6, 0x1.8p+6, 0x1.84p+6, 0x1.88p+6, 0x1.8cp+6,
 0x1.9p+6, 0x1.94p+6, 0x1.98p+6, 0x1.9cp+6, 0x1.ap+6, 0x1.a4p+6, 0x1.a8p+6,
 0x1.acp+6, 0x1.bp+6, 0x1.b4p+6, 0x1.b8p+6, 0x1.bcp+6, 0x1.cp+6, 0x1.c4p+6,
 0x1.c8p+6, 0x1.ccp+6, 0x1.dp+6, 0x1.d4p+6, 0x1.d8p+6, 0x1.dcp+6, 0x1.ep+6,
 0x1.e4p+6, 0x1.e8p+6, 0x1.ecp+6, 0x1.fp+6, 0x1.f4p+6, 0x1.f8p+6, 0x1.fcp+6,
 0,
};

/* For 0 <= i2 < 2^7, T2[i2] approximates log2(x2), where 1 <= x2 < 2
   and i2 matches the 7 lower bits of the 16-bit encoding of x2.
   Table copied from log2_bf16.c, with T2[0] modified to avoid
   failures with exact powers of 2 and rounding upwards. */
static const float T2[] = {
 0x1p-126, 0x1.6fe50cp-7, 0x1.6e7968p-6, 0x1.11cd1ep-5, 0x1.6bad38p-5,
 0x1.c4dfacp-5, 0x1.0eb38ap-4, 0x1.3aa2fep-4, 0x1.663f7p-4, 0x1.918a16p-4,
 0x1.bc8424p-4, 0x1.e72ec2p-4, 0x1.08c588p-3, 0x1.1dcd1ap-3, 0x1.32ae9ep-3,
 0x1.476aap-3, 0x1.5c01a4p-3, 0x1.70742ep-3, 0x1.84c2bep-3, 0x1.98eddp-3,
 0x1.acf5e2p-3, 0x1.c0db6cp-3, 0x1.d49ee4p-3, 0x1.e840bep-3, 0x1.fbc16cp-3,
 0x1.0790aep-2, 0x1.11307ep-2, 0x1.1ac05cp-2, 0x1.24407ap-2, 0x1.2db11p-2,
 0x1.37124cp-2, 0x1.406464p-2, 0x1.49a784p-2, 0x1.52dbep-2, 0x1.5c01a4p-2,
 0x1.6518fep-2, 0x1.6e221cp-2, 0x1.771d2cp-2, 0x1.800a56p-2, 0x1.88e9c8p-2,
 0x1.91bba8p-2, 0x1.9a8024p-2, 0x1.a3376p-2, 0x1.abe188p-2, 0x1.b47ecp-2,
 0x1.bd0f2ep-2, 0x1.c592fap-2, 0x1.ce0a4ap-2, 0x1.d6753ep-2, 0x1.ded3fep-2,
 0x1.e726aap-2, 0x1.ef6d68p-2, 0x1.f7a856p-2, 0x1.ffd79ap-2, 0x1.03fda8p-1,
 0x1.0809dp-1, 0x1.0c105p-1, 0x1.10113cp-1, 0x1.140cap-1, 0x1.18028cp-1,
 0x1.1bf312p-1, 0x1.1fde3ep-1, 0x1.23c41ep-1, 0x1.27a4cp-1, 0x1.2b8034p-1,
 0x1.2f5688p-1, 0x1.3327c6p-1, 0x1.36f4p-1, 0x1.3abb4p-1, 0x1.3e7d94p-1,
 0x1.423b08p-1, 0x1.45f3aap-1, 0x1.49a784p-1, 0x1.4d56a6p-1, 0x1.510118p-1,
 0x1.54a6e8p-1, 0x1.584822p-1, 0x1.5be4dp-1, 0x1.5f7dp-1, 0x1.6310b8p-1,
 0x1.66a008p-1, 0x1.6a2afap-1, 0x1.6db196p-1, 0x1.7133eap-1, 0x1.74b1fep-1,
 0x1.782bdcp-1, 0x1.7ba19p-1, 0x1.7f1322p-1, 0x1.82809ep-1, 0x1.85ea0cp-1,
 0x1.894f74p-1, 0x1.8cb0e4p-1, 0x1.900e62p-1, 0x1.9367f6p-1, 0x1.96bdaep-1,
 0x1.9a0f8ep-1, 0x1.9d5dap-1, 0x1.a0a7eep-1, 0x1.a3ee8p-1, 0x1.a7315ep-1,
 0x1.aa709p-1, 0x1.adac1ep-1, 0x1.b0e412p-1, 0x1.b41874p-1, 0x1.b74948p-1,
 0x1.ba769cp-1, 0x1.bda072p-1, 0x1.c0c6d4p-1, 0x1.c3e9cap-1, 0x1.c7095ap-1,
 0x1.ca258ep-1, 0x1.cd3e6ap-1, 0x1.d053f6p-1, 0x1.d3663cp-1, 0x1.d6753ep-1,
 0x1.d98106p-1, 0x1.dc899ap-1, 0x1.df8f02p-1, 0x1.e29142p-1, 0x1.e59064p-1,
 0x1.e88c6cp-1, 0x1.eb856p-1, 0x1.ee7b48p-1, 0x1.f16e28p-1, 0x1.f45e08p-1,
 0x1.f74afp-1, 0x1.fa34e2p-1, 0x1.fd1be4p-1,
};

/* For 0 <= i <= 20, R0[i] stores i-8.
   Table generated by table0() from log2p1.sage. */
static const float R0[] = {
-0x1p+3,-0x1.cp+2,-0x1.8p+2,-0x1.4p+2,-0x1p+2,-0x1.8p+1,-0x1p+1,-0x1p+0,
-0x0p+3,0x1p+0,0x1p+1,0x1.8p+1,0x1p+2,0x1.4p+2,0x1.8p+2,0x1.cp+2,0x1p+3,
0x1.2p+3,0x1.4p+3,0x1.6p+3,0x1.8p+3,
};

/* For 0 <= i < 64, R[i] stores {r,logr} where r approximates 1/x[i]
   with x[i] = 1 + i/64 and logr approximates -log2(r).
   Table generated by table1() from log2p1.sage. */
static const float R[][2] = {
 {0x1.fcp-1,0x1.72c7bap-7}, {0x1.f44p-1,0x1.126328p-5},
 {0x1.eccp-1,0x1.c4eb36p-5}, {0x1.e58p-1,0x1.3a0cf6p-4},
 {0x1.de6p-1,0x1.916a5ap-4}, {0x1.d78p-1,0x1.e6f50cp-4},
 {0x1.d0cp-1,0x1.1e153cp-3}, {0x1.ca4p-1,0x1.47b2c2p-3},
 {0x1.c4p-1,0x1.704604p-3}, {0x1.bdep-1,0x1.9895dp-3},
 {0x1.b7ep-1,0x1.c09d64p-3}, {0x1.b2p-1,0x1.e857d4p-3},
 {0x1.ac6p-1,0x1.0771aap-2}, {0x1.a6ep-1,0x1.1a88d2p-2},
 {0x1.a16p-1,0x1.2ddff4p-2}, {0x1.9c2p-1,0x1.409348p-2},
 {0x1.97p-1,0x1.530fdp-2}, {0x1.92p-1,0x1.6552b4p-2},
 {0x1.8d4p-1,0x1.76e206p-2}, {0x1.886p-1,0x1.891fe2p-2},
 {0x1.83cp-1,0x1.9aa436p-2}, {0x1.7f4p-1,0x1.abe2f8p-2},
 {0x1.7aep-1,0x1.bcd916p-2}, {0x1.768p-1,0x1.ce01a2p-2},
 {0x1.724p-1,0x1.dede16p-2}, {0x1.6e2p-1,0x1.ef6b3ep-2},
 {0x1.6a2p-1,0x1.ffa5d4p-2}, {0x1.662p-1,0x1.080748p-1},
 {0x1.624p-1,0x1.101082p-1}, {0x1.5e8p-1,0x1.17eceap-1},
 {0x1.5acp-1,0x1.1fdef6p-1}, {0x1.572p-1,0x1.27a23ap-1},
 {0x1.53ap-1,0x1.2f34fep-1}, {0x1.502p-1,0x1.36dbd6p-1},
 {0x1.4cap-1,0x1.3e973p-1}, {0x1.496p-1,0x1.45d7e4p-1},
 {0x1.46p-1,0x1.4d738p-1}, {0x1.42ep-1,0x1.5490e8p-1},
 {0x1.3fcp-1,0x1.5bc008p-1}, {0x1.3cap-1,0x1.630136p-1},
 {0x1.39ap-1,0x1.6a097p-1}, {0x1.36ap-1,0x1.7122f6p-1},
 {0x1.33ap-1,0x1.784e2p-1}, {0x1.30ep-1,0x1.7ef026p-1},
 {0x1.2ep-1,0x1.85efdp-1}, {0x1.2b4p-1,0x1.8cb19cp-1},
 {0x1.288p-1,0x1.93836p-1}, {0x1.25ep-1,0x1.9a14f6p-1},
 {0x1.234p-1,0x1.a0b5a2p-1}, {0x1.20cp-1,0x1.a713cap-1},
 {0x1.1e2p-1,0x1.add2b8p-1}, {0x1.1bcp-1,0x1.b3faep-1},
 {0x1.194p-1,0x1.ba845p-1}, {0x1.16ep-1,0x1.c0c7eap-1},
 {0x1.148p-1,0x1.c7193ap-1}, {0x1.124p-1,0x1.cd2248p-1},
 {0x1.0fep-1,0x1.d38efep-1}, {0x1.0dcp-1,0x1.d95accp-1},
 {0x1.0b8p-1,0x1.df8aaep-1}, {0x1.096p-1,0x1.e56edap-1},
 {0x1.074p-1,0x1.eb5f26p-1}, {0x1.052p-1,0x1.f15bc4p-1},
 {0x1.03p-1,0x1.f764e8p-1}, {0x1.01p-1,0x1.fd1ec8p-1},
};

#define INVLOG2 0x1.715476p+0f
#define ONE_THIRD 0x1.555556p-2f

// approximates log2(1+x) for x tiny
// using the Taylor expansion x/log(2) - x^2/2/log(2)
static inline float log2p1_tiny (float x) {
  float t = x * INVLOG2;
  return __builtin_fmaf (t, -0.5f * x, t);
}

__bf16 cr_log2p1_bf16 (__bf16 x){
  b32u32_u v = {.f = x};
  uint32_t u = v.u, au = u & 0x7fffffff;

  static const b16u16_u nan = {.u = 0x7fc0}; // qNaN
  static const b16u16_u inf = {.u = 0x7f80}; // +Inf
  static const b16u16_u minus_inf = {.u = 0xff80}; // -Inf

  if (u >= 0xbf800000u) { // x <= -1
#ifdef CORE_MATH_SUPPORT_ERRNO
    // for x=-1, we have errno=ERANGE (overflow to -Inf)
    errno = (u == 0xbf800000u) ? ERANGE : EDOM;
#endif
    // x + nan.f raises invalid if x = -sNaN
    return (u == 0xbf800000u) ? minus_inf.f : x + nan.f;
  }

  if ((u >> 23) == 0xff) return inf.f + x; // NaN or Inf

  /* For x >= 0x1.6cp+12, log2p1(x) rounds to the same value as log2(x),
     except when x is a power of two, cf check_large() in log2p1.sage.
     For x a power of two, we have i2=0, and we slightly increased T2[0]
     so that we get the correct rounding also with rounding upwards. */
  if (au >= 0x45b60000u) { // |x| >= 0x1.6cp+12
    uint16_t i1 = u >> 23;
    uint16_t i2 = (u >> 16) & 0x7f;
    return T1[i1] + T2[i2];
  }

  /* for |x| <= 0x1.84p-7, the following code gives the correct rounding,
     cf check_tiny() in log2p1.sage */
  if (au <= 0x3ba00000u) { // |x| <= 0x1.84p-7
    if (au == 0) return x; // x = 0
#ifdef CORE_MATH_SUPPORT_ERRNO
    // we have underflow for |x| < 0x1.64p-127
    if (au < 0x590000u)
      errno = ERANGE; // underflow
#endif
    return log2p1_tiny (v.f);
  }

  // exceptional values
  switch (u >> 16)
  {
  case 0x437f: return 8.0f; // x = 255
  case 0x42fe: return 7.0f; // x = 127
  case 0x427c: return 6.0f; // x = 63
  case 0x41f8: return 5.0f; // x = 31
  case 0x4170: return 4.0f; // x = 15
  case 0x40e0: return 3.0f; // x = 7
  case 0x4040: return 2.0f; // x = 3
  case 0x3f80: return 1.0f; // x = 1
  case 0xbf00: return -1.0f; // x = -1/2
  case 0xbf40: return -2.0f; // x = -3/4
  case 0xbf60: return -3.0f; // x = -7/8
  case 0xbf70: return -4.0f; // x = -15/16
  case 0xbf78: return -5.0f; // x = -31/32
  case 0xbf7c: return -6.0f; // x = -63/64
  case 0xbf7e: return -7.0f; // x = -127/128
  case 0xbf7f: return -8.0f; // x = -255/256
  case 0x3c73: return 0x1.5c0024p-6f; // x = 0x1.e6p-7
  }

  // now 0x1.86p-7 <= |x| <= 0x1.6ap+12
  v.f += 1.0f; // exact
  int i = v.u >> 23; // 119 <= i <= 139
  v.u = (v.u & 0x7fffffu) | 0x3f800000u; // reduce v in [1,2)
  // log2(1+x) = R0[i-119] + log2(v.f) where 1 <= v.f < 2
  int j = (v.u >> 17) & 0x3f; // upper 6 bits of the fractional part of v.f
  float z = __builtin_fmaf (R[j][0], v.f, -1.0f); // exact
  // r*(1+x) = 1 + z thus log2(1+x) = -log2(r) + log2(1+z)
  return R0[i-119] + (R[j][1] + log2p1_tiny (z));
}

// dummy function since GNU libc does not provide it
__bf16 log2p1_bf16 (__bf16 x) {
  return (__bf16) log2p1f ((float) x);
}
