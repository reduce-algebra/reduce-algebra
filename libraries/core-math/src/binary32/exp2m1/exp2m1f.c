/* Correctly-rounded base-2 exponent function biased by 1 for binary32 value.

Copyright (c) 2022-2025 Alexei Sibidanov.

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

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;

float cr_exp2m1f(float x){
  static const float q[][2] = {{0x1.fffffep127f, 0x1.fffffep127f},
                               {0x1.fffffep127f, 0x1p+103f},
                               {-1.0f, 0x1p-26f}};
  b32u32_u t = {.f = x};
  double z = x;
  uint32_t ux = t.u, ax = ux&(~0u>>1);
  if(__builtin_expect(ux>=0xc1c80000u, 0)){ // x <= -25
    if(ax>(0xffu<<23)) return x + x; // nan
    // avoid spurious inexact exception for -Inf
    return (ux == 0xff800000) ? q[2][0] : q[2][0] + q[2][1];
  } else if(__builtin_expect(ax>=0x43000000u, 0)){  // x >= 128
    if(ax>(0xffu<<23)) return x + x; // nan
    // for x=128 and rounding downward or to zero, there is no overflow
    int special = x == 128.0f && (q[1][0] + q[1][1] == q[1][0]);
#ifdef CORE_MATH_SUPPORT_ERRNO
    if (!special)
      errno = ERANGE;
#endif
    // avoid spurious inexact exception for +Inf
    return (ux == 0x7f800000) ? x : q[special][0] + q[special][1];
  } else if (__builtin_expect(ax<0x3df95f1fu, 0)){ // |x| < 8.44e-2/log(2)
    double z2 = z*z, r;
    if (__builtin_expect(ax<0x3d67a4ccu, 0)){ // |x| < 3.92e-2/log(2)
      if (__builtin_expect(ax<0x3caa2feeu, 0)){ // |x| < 1.44e-2/log(2)
	if (__builtin_expect(ax<0x3bac1405u, 0)){ // |x| < 3.64e-3/log(2)
	  if (__builtin_expect(ax<0x3a358876u, 0)){ // |x| < 4.8e-4/log(2)
	    if (__builtin_expect(ax<0x37d32ef6u, 0)){ // |x| < 1.745e-5/log(2)
	      if (__builtin_expect(ax<0x331fdd82u, 0)){ // |x| < 2.58e-8/log(2)
		if (__builtin_expect(ax<0x2538aa3bu, 0)){ // |x| < 0x1.715476p-53
#ifdef CORE_MATH_SUPPORT_ERRNO
                  /* exp2m1(x) underflows:
                   * for |x| <= 0x1.715476p-126 for rounding toward zero
                   * for |x| <= 0x1.715474p-126 for rounding to nearest/away */
                    if (x != 0 && (__builtin_fabsf (x) <= 0x1.715474p-126f ||
                                   (__builtin_fabsf (x) == 0x1.715476p-126f &&
                                    __builtin_fabsf (x * 5.0f) <= 0x1.cda992p-124f)))
                      errno = ERANGE; // underflow
#endif
		  r = 0x1.62e42fefa39efp-1;
		} else {
		  r = 0x1.62e42fefa39fp-1 + z * 0x1.ebfbdff82c58fp-3;
		}
	      } else {
		if (__builtin_expect(ux == 0xb3d85005u, 0)) return -0x1.2bdf76p-24 - 0x1.8p-77;
		if (__builtin_expect(ux == 0x3338428du, 0)) return 0x1.fee08ap-26 + 0x1p-80;
		static const double c[] =
		  {0x1.62e42fefa39efp-1, 0x1.ebfbdff8548fdp-3, 0x1.c6b08d704a06dp-5};
		r = c[0] + z * (c[1] + z * c[2]);
	      }
	    } else {
	      if (__builtin_expect(ux == 0x388bca4fu, 0)) return 0x1.839702p-15 - 0x1.8p-68;
	      static const double c[] =
		{0x1.62e42fefa39efp-1, 0x1.ebfbdff82c58fp-3, 0x1.c6b08dc82b347p-5, 0x1.3b2ab6fbad172p-7};
	      r = (c[0] + z * c[1]) + z2 * (c[2] + z * c[3]);
	    }
	  } else {
	    static const double c[] =
	      {0x1.62e42fefa39efp-1, 0x1.ebfbdff82c068p-3, 0x1.c6b08d704a6dcp-5, 0x1.3b2ac262c3eedp-7,
	       0x1.5d87fe7af779ap-10};
	    r = (c[0] + z * c[1]) + z2 * (c[2] + z * (c[3] + z * c[4]));
	  }
	} else {
	  static const double c[] =
	    {0x1.62e42fefa39fp-1, 0x1.ebfbdff82c58dp-3, 0x1.c6b08d7011d13p-5, 0x1.3b2ab6fbd267dp-7,
	     0x1.5d88a81cea49ep-10, 0x1.430912ea9b963p-13};
	  r = (c[0] + z * c[1]) + z2 * ((c[2] + z * c[3]) + z2 * (c[4] + z * c[5]));
	}
      } else {
	static const double c[] =
	  {0x1.62e42fefa39efp-1, 0x1.ebfbdff82c639p-3, 0x1.c6b08d7049f1cp-5, 0x1.3b2ab6f5243bdp-7,
	   0x1.5d87fe80a9e6cp-10, 0x1.430d0b9257fa8p-13, 0x1.ffcbfc4cf0952p-17};
	r = (c[0] + z * c[1]) + z2 * ((c[2] + z * c[3]) + z2 * (c[4] + z * (c[5] + z * c[6])));
      }
    } else {
      static const double c[] =
	{0x1.62e42fefa39efp-1, 0x1.ebfbdff82c591p-3, 0x1.c6b08d704cf6bp-5, 0x1.3b2ab6fba00cep-7,
	 0x1.5d87fdfdaadb4p-10, 0x1.4309137333066p-13, 0x1.ffe5e90daf7ddp-17, 0x1.62c0220eed731p-20};
      r = ((c[0] + z * c[1]) + z2 * (c[2] + z * c[3])) + (z2*z2) * ((c[4] + z * c[5]) + z2 * (c[6] + z * c[7]));
    }
    r *= z;
    return r;
  } else {
    static const double c[] =
      {0x1.62e42fefa398bp-5, 0x1.ebfbdff84555ap-11, 0x1.c6b08d4ad86d3p-17,
       0x1.3b2ad1b1716a2p-23, 0x1.5d7472718ce9dp-30, 0x1.4a1d7f457ac56p-37};
    static const double tb[] =
      {0x1p+0, 0x1.0b5586cf9890fp+0, 0x1.172b83c7d517bp+0, 0x1.2387a6e756238p+0,
       0x1.306fe0a31b715p+0, 0x1.3dea64c123422p+0, 0x1.4bfdad5362a27p+0, 0x1.5ab07dd485429p+0,
       0x1.6a09e667f3bcdp+0, 0x1.7a11473eb0187p+0, 0x1.8ace5422aa0dap+0, 0x1.9c49182a3f09p+0,
       0x1.ae89f995ad3adp+0, 0x1.c199bdd85529cp+0, 0x1.d5818dcfba487p+0, 0x1.ea4afa2a490dap+0};
    double a = 16.0*z, ia = __builtin_floor(a), h = a - ia, h2 = h*h;
    int64_t i = ia, j = i&0xf, e = i - j;
    e >>= 4;
    double s = tb[j];
    b64u64_u su = {.u = (e + 0x3ffull)<<52};
    s *= su.f;
    double c0 = c[0] + h*c[1];
    double c2 = c[2] + h*c[3];
    double c4 = c[4] + h*c[5];
    c0 += h2*(c2 + h2*c4);
    double w = s*h;
    return (s-1.0) + w*c0;
  }
}
