/* Correctly-rounded biased base-10 logarithm function for bfloat16 value.

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

/* For 0 <= i1 < 2^8, T1[i1] approximates log10(x1), where the 16-bit
   encoding of x1 is i1*2^7 (i1 encodes the exponent of x1).
   Table copied from log10_bf16.c. */
static const float T1[] = {
 0, -0x1.2f703p+5, -0x1.2d07aep+5, -0x1.2a9f2cp+5, -0x1.2836a8p+5,
 -0x1.25ce26p+5, -0x1.2365a4p+5, -0x1.20fd22p+5, -0x1.1e94ap+5,
 -0x1.1c2c1cp+5, -0x1.19c39ap+5, -0x1.175b18p+5, -0x1.14f296p+5,
 -0x1.128a14p+5, -0x1.10219p+5, -0x1.0db90ep+5, -0x1.0b508cp+5,
 -0x1.08e80ap+5, -0x1.067f88p+5, -0x1.041704p+5, -0x1.01ae82p+5, -0x1.fe8cp+4,
 -0x1.f9bafcp+4, -0x1.f4e9f6p+4, -0x1.f018f2p+4, -0x1.eb47ecp+4,
 -0x1.e676e8p+4, -0x1.e1a5e2p+4, -0x1.dcd4dep+4, -0x1.d803dap+4,
 -0x1.d332d4p+4, -0x1.ce61dp+4, -0x1.c990cap+4, -0x1.c4bfc6p+4,
 -0x1.bfeec2p+4, -0x1.bb1dbcp+4, -0x1.b64cb8p+4, -0x1.b17bb2p+4,
 -0x1.acaaaep+4, -0x1.a7d9a8p+4, -0x1.a308a4p+4, -0x1.9e37ap+4,
 -0x1.99669ap+4, -0x1.949596p+4, -0x1.8fc49p+4, -0x1.8af38cp+4,
 -0x1.862288p+4, -0x1.815182p+4, -0x1.7c807ep+4, -0x1.77af78p+4,
 -0x1.72de74p+4, -0x1.6e0d6ep+4, -0x1.693c6ap+4, -0x1.646b66p+4,
 -0x1.5f9a6p+4, -0x1.5ac95cp+4, -0x1.55f856p+4, -0x1.512752p+4,
 -0x1.4c564ep+4, -0x1.478548p+4, -0x1.42b444p+4, -0x1.3de33ep+4,
 -0x1.39123ap+4, -0x1.344136p+4, -0x1.2f703p+4, -0x1.2a9f2cp+4,
 -0x1.25ce26p+4, -0x1.20fd22p+4, -0x1.1c2c1cp+4, -0x1.175b18p+4,
 -0x1.128a14p+4, -0x1.0db90ep+4, -0x1.08e80ap+4, -0x1.041704p+4, -0x1.fe8cp+3,
 -0x1.f4e9f6p+3, -0x1.eb47ecp+3, -0x1.e1a5e2p+3, -0x1.d803dap+3,
 -0x1.ce61dp+3, -0x1.c4bfc6p+3, -0x1.bb1dbcp+3, -0x1.b17bb2p+3,
 -0x1.a7d9a8p+3, -0x1.9e37ap+3, -0x1.949596p+3, -0x1.8af38cp+3,
 -0x1.815182p+3, -0x1.77af78p+3, -0x1.6e0d6ep+3, -0x1.646b66p+3,
 -0x1.5ac95cp+3, -0x1.512752p+3, -0x1.478548p+3, -0x1.3de33ep+3,
 -0x1.344136p+3, -0x1.2a9f2cp+3, -0x1.20fd22p+3, -0x1.175b18p+3,
 -0x1.0db90ep+3, -0x1.041704p+3, -0x1.f4e9f6p+2, -0x1.e1a5e2p+2,
 -0x1.ce61dp+2, -0x1.bb1dbcp+2, -0x1.a7d9a8p+2, -0x1.949596p+2,
 -0x1.815182p+2, -0x1.6e0d6ep+2, -0x1.5ac95cp+2, -0x1.478548p+2,
 -0x1.344136p+2, -0x1.20fd22p+2, -0x1.0db90ep+2, -0x1.f4e9f6p+1,
 -0x1.ce61dp+1, -0x1.a7d9a8p+1, -0x1.815182p+1, -0x1.5ac95cp+1,
 -0x1.344136p+1, -0x1.0db90ep+1, -0x1.ce61dp+0, -0x1.815182p+0,
 -0x1.344136p+0, -0x1.ce61dp-1, -0x1.344136p-1, -0x1.344136p-2, 0x0p+0,
 0x1.344136p-2, 0x1.344136p-1, 0x1.ce61dp-1, 0x1.344136p+0, 0x1.815182p+0,
 0x1.ce61dp+0, 0x1.0db90ep+1, 0x1.344136p+1, 0x1.5ac95cp+1, 0x1.815182p+1,
 0x1.a7d9a8p+1, 0x1.ce61dp+1, 0x1.f4e9f6p+1, 0x1.0db90ep+2, 0x1.20fd22p+2,
 0x1.344136p+2, 0x1.478548p+2, 0x1.5ac95cp+2, 0x1.6e0d6ep+2, 0x1.815182p+2,
 0x1.949596p+2, 0x1.a7d9a8p+2, 0x1.bb1dbcp+2, 0x1.ce61dp+2, 0x1.e1a5e2p+2,
 0x1.f4e9f6p+2, 0x1.041704p+3, 0x1.0db90ep+3, 0x1.175b18p+3, 0x1.20fd22p+3,
 0x1.2a9f2cp+3, 0x1.344136p+3, 0x1.3de33ep+3, 0x1.478548p+3, 0x1.512752p+3,
 0x1.5ac95cp+3, 0x1.646b66p+3, 0x1.6e0d6ep+3, 0x1.77af78p+3, 0x1.815182p+3,
 0x1.8af38cp+3, 0x1.949596p+3, 0x1.9e37ap+3, 0x1.a7d9a8p+3, 0x1.b17bb2p+3,
 0x1.bb1dbcp+3, 0x1.c4bfc6p+3, 0x1.ce61dp+3, 0x1.d803dap+3, 0x1.e1a5e2p+3,
 0x1.eb47ecp+3, 0x1.f4e9f6p+3, 0x1.fe8cp+3, 0x1.041704p+4, 0x1.08e80ap+4,
 0x1.0db90ep+4, 0x1.128a14p+4, 0x1.175b18p+4, 0x1.1c2c1cp+4, 0x1.20fd22p+4,
 0x1.25ce26p+4, 0x1.2a9f2cp+4, 0x1.2f703p+4, 0x1.344136p+4, 0x1.39123ap+4,
 0x1.3de33ep+4, 0x1.42b444p+4, 0x1.478548p+4, 0x1.4c564ep+4, 0x1.512752p+4,
 0x1.55f856p+4, 0x1.5ac95cp+4, 0x1.5f9a6p+4, 0x1.646b66p+4, 0x1.693c6ap+4,
 0x1.6e0d6ep+4, 0x1.72de74p+4, 0x1.77af78p+4, 0x1.7c807ep+4, 0x1.815182p+4,
 0x1.862288p+4, 0x1.8af38cp+4, 0x1.8fc49p+4, 0x1.949596p+4, 0x1.99669ap+4,
 0x1.9e37ap+4, 0x1.a308a4p+4, 0x1.a7d9a8p+4, 0x1.acaaaep+4, 0x1.b17bb2p+4,
 0x1.b64cb8p+4, 0x1.bb1dbcp+4, 0x1.bfeec2p+4, 0x1.c4bfc6p+4, 0x1.c990cap+4,
 0x1.ce61dp+4, 0x1.d332d4p+4, 0x1.d803dap+4, 0x1.dcd4dep+4, 0x1.e1a5e2p+4,
 0x1.e676e8p+4, 0x1.eb47ecp+4, 0x1.f018f2p+4, 0x1.f4e9f6p+4, 0x1.f9bafcp+4,
 0x1.fe8cp+4, 0x1.01ae82p+5, 0x1.041704p+5, 0x1.067f88p+5, 0x1.08e80ap+5,
 0x1.0b508cp+5, 0x1.0db90ep+5, 0x1.10219p+5, 0x1.128a14p+5, 0x1.14f296p+5,
 0x1.175b18p+5, 0x1.19c39ap+5, 0x1.1c2c1cp+5, 0x1.1e94ap+5, 0x1.20fd22p+5,
 0x1.2365a4p+5, 0x1.25ce26p+5, 0x1.2836a8p+5, 0x1.2a9f2cp+5, 0x1.2d07aep+5,
 0x1.2f703p+5, 0x1.31d8b2p+5, 0,
};

/* For 0 <= i2 < 2^7, T2[i2] approximates log10(x2), where 1 <= x2 < 2
   and i2 matches the 7 lower bits of the 16-bit encoding of x2.
   Table copied from log10_bf16.c. */
static const float T2[] = {
 0x0p+0, 0x1.bafd48p-9, 0x1.b9476ap-8, 0x1.49b086p-7, 0x1.b5e908p-7,
 0x1.10a83ap-6, 0x1.45f4f6p-6, 0x1.7adc3ep-6, 0x1.af5f92p-6, 0x1.e3806ap-6,
 0x1.0ba01ap-5, 0x1.25502cp-5, 0x1.3ed11ap-5, 0x1.58238ep-5, 0x1.714834p-5,
 0x1.8a3faep-5, 0x1.a30a9ep-5, 0x1.bba9ap-5, 0x1.d41d52p-5, 0x1.ec6648p-5,
 0x1.02428cp-4, 0x1.0e3d2ap-4, 0x1.1a2344p-4, 0x1.25f522p-4, 0x1.31b306p-4,
 0x1.3d5d34p-4, 0x1.48f3eep-4, 0x1.547774p-4, 0x1.5fe804p-4, 0x1.6b45ep-4,
 0x1.76914p-4, 0x1.81ca64p-4, 0x1.8cf18p-4, 0x1.9806dap-4, 0x1.a30a9ep-4,
 0x1.adfd08p-4, 0x1.b8de4ep-4, 0x1.c3aea4p-4, 0x1.ce6e42p-4, 0x1.d91d58p-4,
 0x1.e3bc1ap-4, 0x1.ee4abap-4, 0x1.f8c968p-4, 0x1.019c2ap-3, 0x1.06cbd6p-3,
 0x1.0bf3dp-3, 0x1.11143p-3, 0x1.162d08p-3, 0x1.1b3e72p-3, 0x1.204882p-3,
 0x1.254b4ep-3, 0x1.2a46e8p-3, 0x1.2f3b6ap-3, 0x1.3428e2p-3, 0x1.390f68p-3,
 0x1.3def0ep-3, 0x1.42c7e8p-3, 0x1.479a08p-3, 0x1.4c658p-3, 0x1.512a64p-3,
 0x1.55e8c6p-3, 0x1.5aa0b4p-3, 0x1.5f5244p-3, 0x1.63fd86p-3, 0x1.68a288p-3,
 0x1.6d415ep-3, 0x1.71da18p-3, 0x1.766cc4p-3, 0x1.7af974p-3, 0x1.7f8036p-3,
 0x1.84011ap-3, 0x1.887c2ep-3, 0x1.8cf18p-3, 0x1.916128p-3, 0x1.95cb28p-3,
 0x1.9a2f96p-3, 0x1.9e8e7cp-3, 0x1.a2e7e8p-3, 0x1.a73beap-3, 0x1.ab8a9p-3,
 0x1.afd3e4p-3, 0x1.b417f4p-3, 0x1.b856dp-3, 0x1.bc908p-3, 0x1.c0c514p-3,
 0x1.c4f496p-3, 0x1.c91f14p-3, 0x1.cd4498p-3, 0x1.d1653p-3, 0x1.d580e6p-3,
 0x1.d997c8p-3, 0x1.dda9dep-3, 0x1.e1b734p-3, 0x1.e5bfd6p-3, 0x1.e9c3cep-3,
 0x1.edc328p-3, 0x1.f1bdeep-3, 0x1.f5b42ap-3, 0x1.f9a5e8p-3, 0x1.fd933p-3,
 0x1.00be06p-2, 0x1.02b044p-2, 0x1.04a054p-2, 0x1.068e4p-2, 0x1.087a08p-2,
 0x1.0a63b4p-2, 0x1.0c4b46p-2, 0x1.0e30c4p-2, 0x1.101432p-2, 0x1.11f594p-2,
 0x1.13d4fp-2, 0x1.15b24ap-2, 0x1.178da6p-2, 0x1.196706p-2, 0x1.1b3e72p-2,
 0x1.1d13ecp-2, 0x1.1ee778p-2, 0x1.20b91ap-2, 0x1.2288d8p-2, 0x1.2456b4p-2,
 0x1.2622bp-2, 0x1.27ecd4p-2, 0x1.29b52p-2, 0x1.2b7b9ep-2, 0x1.2d404cp-2,
 0x1.2f032cp-2, 0x1.30c448p-2, 0x1.32839ep-2,
};

/* For 0 <= i <= 20, R0[i] stores an approximation of -log10(2^(i-8)).
   Table generated by table0() from log10p1.sage. */
static const float R0[] = {
-0x1.344136p+1,-0x1.0db90ep+1,-0x1.ce61dp+0,-0x1.815182p+0,-0x1.344136p+0,
-0x1.ce61dp-1,-0x1.344136p-1,-0x1.344136p-2,-0x0p+3,0x1.344136p-2,
0x1.344136p-1,0x1.ce61dp-1,0x1.344136p+0,0x1.815182p+0,0x1.ce61dp+0,
0x1.0db90ep+1,0x1.344136p+1,0x1.5ac95cp+1,0x1.815182p+1,0x1.a7d9a8p+1,
0x1.ce61dp+1,
};

/* For 0 <= i < 64, R[i] stores {r,logr} where r approximates 1/x[i]
   with x[i] = 1 + i/64 and logr approximates -log10(r).
   Table generated by table1() from log10p1.sage, with some entries
   optimized to reduce exceptional cases. */
static const float R[][2] = {
 {0x1.fcp-1,0x1.be76bep-9}, {0x1.f44p-1,0x1.4a653p-7},
 {0x1.eccp-1,0x1.10af2cp-6}, {0x1.e58p-1,0x1.7a2796p-6},
 {0x1.de6p-1,0x1.e35a34p-6}, {0x1.d78p-1,0x1.252d6ep-5},
 {0x1.d0cp-1,0x1.587a6cp-5}, {0x1.ca4p-1,0x1.8a968ap-5},
 {0x1.c4p-1,0x1.bb720ap-5}, {0x1.bdep-1,0x1.ebfc52p-5},
 {0x1.b7ep-1,0x1.0e17dp-4}, {0x1.b2p-1,0x1.260308p-4},
 {0x1.ac6p-1,0x1.3d37dap-4}, {0x1.a6ep-1,0x1.543492p-4},
 {0x1.a16p-1,0x1.6b7e56p-4}, {0x1.9c2p-1,0x1.8202dap-4},
 {0x1.97p-1,0x1.984564p-4}, {0x1.92p-1,0x1.ae4286p-4},
 {0x1.8d4p-1,0x1.c3676cp-4}, {0x1.886p-1,0x1.d95e7ep-4},
 {0x1.83cp-1,0x1.ee7628p-4}, {0x1.7f4p-1,0x1.019d08p-3},
 {0x1.7aep-1,0x1.0bd33ep-3}, {0x1.768p-1,0x1.1627d2p-3},
 {0x1.724p-1,0x1.204e96p-3}, {0x1.6e2p-1,0x1.2a459cp-3},
 {0x1.6a2p-1,0x1.340aecp-3}, {0x1.662p-1,0x1.3dec04p-3},
 {0x1.624p-1,0x1.47992ap-3}, {0x1.5e8p-1,0x1.511056p-3},
 {0x1.5acp-1,0x1.5aa194p-3}, {0x1.572p-1,0x1.63fa7cp-3},
 {0x1.53ap-1,0x1.6d18fcp-3}, {0x1.502p-1,0x1.764facp-3},
 {0x1.4cap-1,0x1.7f9f0cp-3}, {0x1.496p-1,0x1.885abep-3},
 {0x1.46p-1,0x1.9183e6p-3}, {0x1.42ep-1,0x1.9a1518p-3},
 {0x1.3fcp-1,0x1.a2bb9ep-3}, {0x1.3cap-1,0x1.ab77e2p-3},
 {0x1.39ap-1,0x1.b3ef92p-3}, {0x1.36ap-1,0x1.bc7c16p-3},
 {0x1.33ap-1,0x1.c51dd8p-3}, {0x1.30ep-1,0x1.cd1a78p-3},
 {0x1.2ep-1,0x1.d587dap-3}, {0x1.2b4p-1,0x1.ddaabcp-3},
 {0x1.288p-1,0x1.e5e0d8p-3}, {0x1.25ep-1,0x1.edc9acp-3},
 {0x1.234p-1,0x1.f5c4acp-3}, {0x1.20cp-1,0x1.fd6f94p-3},
 {0x1.1e2p-1,0x1.02c78p-2}, {0x1.1bcp-1,0x1.067c72p-2},
 {0x1.194p-1,0x1.0a6bf4p-2}, {0x1.16ep-1,0x1.0e316ap-2},
 {0x1.148p-1,0x1.11ff22p-2}, {0x1.124p-1,0x1.15a15ap-2},
 {0x1.0fep-1,0x1.197f9p-2}, {0x1.0dcp-1,0x1.1cfce8p-2},
 {0x1.0b8p-1,0x1.20b6ap-2}, {0x1.096p-1,0x1.244282p-2},
 {0x1.074p-1,0x1.27d5ep-2}, {0x1.052p-1,0x1.2b708cp-2},
 {0x1.03p-1,0x1.2f12dp-2}, {0x1.01p-1,0x1.32855cp-2},
};

#define INVLOG10 0x1.bcb7b2p-2f
#define ONE_THIRD 0x1.555556p-2f

// approximates log10(1+x) for x tiny
// using the Taylor expansion x/log(10) - x^2/2/log(10)
static inline float log10p1_tiny (float x) {
  float t = x * INVLOG10;
  return __builtin_fmaf (t, -0.5f * x, t);
}

__bf16 cr_log10p1_bf16 (__bf16 x){
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

  /* for x >= 0x1.bep+12, log10p1(x) rounds to the same value as log10(x),
     cf check_large() in log10p1.sage */
  if (au >= 0x45df0000u) { // |x| >= 0x1.bep+12
    uint16_t i1 = u >> 23;
    uint16_t i2 = (u >> 16) & 0x7f;
    return T1[i1] + T2[i2];
  }

  /* for |x| <= 0x1.4p-8, the following code gives the correct rounding,
     cf check_tiny() in log10p1.sage */
  if (au <= 0x3ba00000u) { // |x| <= 0x1.4p-8
    if (au == 0) return x; // x = 0
    /* avoid a spurious underflow for |x| <= 0x1.84p-63,
       cf check_underflow() in log10p1.sage */
    if (au >= 0x20430000) return log10p1_tiny (v.f);
    // avoid a spurious underflow for |x|=0x1.26p-125 and rounding away
    float res;
    if (au == 0x1130000u)
      res = (au == u) ? 0x1.febaf6p-127f : -0x1.febaf6p-127f;
    else
      res = x * INVLOG10;
#ifdef CORE_MATH_SUPPORT_ERRNO
    // we have underflow for |x| < 0x1.26p-125, and for |x| = 0x1.26p-125
    // and not rounding away
    if (au < 0x1130000u || (au == 0x1130000u &&
                            __builtin_fmaf (x, 0x1p-25f, x) == x))
      errno = ERANGE; // underflow
#endif
    return res;
  }

  // exceptional values
  if (u == 0x41100000u) return 1.0f; // x = 9
  if (u == 0x42c60000u) return 2.0f; // x = 99

  // now 0x1.42p-8 <= |x| <= 0x1.bcp+12
  v.f += 1.0f;
  int i = v.u >> 23; // 119 <= i <= 139
  v.u = (v.u & 0x7fffffu) | 0x3f800000u;
  // log10(1+x) = R0[i-119] + log10(v.f) where 1 <= v.f < 2
  int j = (v.u >> 17) & 0x3f; // upper 6 bits of the fractional part of v.f
  float z = __builtin_fmaf (R[j][0], v.f, -1.0f); // exact
  // r*(1+x) = 1 + z thus log10(1+x) = -log10(r) + log10(1+z)
  return R0[i-119] + (R[j][1] + log10p1_tiny (z));
}

// dummy function since GNU libc does not provide it
__bf16 log10p1_bf16 (__bf16 x) {
  return (__bf16) log10p1f ((float) x);
}
