/* Correctly rounded reciprocal square root for long-double values.

Copyright (c) 2024-2025 Alexei Sibidanov and Paul Zimmermann

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

/* References:
   [1] Note on the Veltkamp/Dekker Algorithms with Directed Roundings,
       Paul Zimmermann, https://inria.hal.science/hal-04480440, February 2024.
*/

#define TRACE 0x8.000000000000001p-5L

#include <stdint.h>
#include <math.h> // for sqrtl
#include <errno.h>

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

// anonymous structs, see https://port70.net/~nsz/c/c11/n1570.html#6.7.2.1p19
typedef union {
  long double f;
  struct __attribute__((__packed__))
  {uint64_t m; uint32_t e:16; uint32_t empty:16;};
} b96u96_u;

typedef int64_t i64;
typedef uint64_t u64;
typedef unsigned __int128 u128;
typedef __int128 i128;
typedef union {double f;uint64_t u;} b64u64_u;

long double cr_rsqrtl (long double x){
  b96u96_u v = {.f = x};
  int e = v.e & 0x7fff;
  // check NaN, Inf, 0 and normalize subnormals
  if (__builtin_expect (v.e >= 0x7fff || v.e == 0, 0)){
    // case x subnormal or NaN or Inf
    if (e == 0) { // subnormal case
      if(!v.m) { // x = 0
#ifdef CORE_MATH_SUPPORT_ERRNO
	errno = ERANGE; // pole error
#endif
	return 1.0L / x;   // x=+0 and x=-0
      }
      else { // non-zero subnormal
	if(!v.e){ // positive subnormal
	  int cnt = __builtin_clzll (v.m);
	  v.m <<= cnt;
	  e -= cnt - 1;
	} else { // negative subnormal
#ifdef CORE_MATH_SUPPORT_ERRNO
	  errno = EDOM; // domain error
#endif
	  return 0.0L / 0.0L; // x<0: rsqrt(x)=NaN
	}
      }
    } else { // NaN or Inf
      if (v.e > 0x8000) return 0.0L / 0.0L; // x<0: rsqrt(x)=NaN
      if (e == 0x7fff && !(v.m<<1)) return +0L;         // x=Inf
      return x;                      // x=NaN
    }
  }
  // rsqrt(x) is exact iff x = 2^(2k)
  if (__builtin_expect (!(v.m<<1) && (e & 1), 0)){
    v.e = 16383 + (16383 - e) / 2;
    return v.f;
  }
  float op = 1.0f + 0x1p-25f, om = 1.0f - 0x1p-25f;
  long rn = op==om, ru = op>1.0f; // figure out a rounding mode
  rn <<= 25;
  // cubic approximation of 1/sqrt(x) in 64 regions in [1,2]
  static const unsigned T[][4] = {
    {0xffffffff, 0x3ffffde0, 0x17feab03, 0x9bb5b6e}, 
    {0xfe05ec45, 0x3e875b9f, 0x17152b51, 0x938bf8f}, 
    {0xfc176441, 0x3d1cefaa, 0x1637e8e1, 0x8bed008}, 
    {0xfa33f940, 0x3bbffca8, 0x156613a9, 0x84cdb43}, 
    {0xf85b4246, 0x3a6fd1bd, 0x149eec46, 0x7e24038}, 
    {0xf68cdbaf, 0x392bc98a, 0x13e1c268, 0x77e6ca6}, 
    {0xf4c866d6, 0x37f34948, 0x132df373, 0x720db8e}, 
    {0xf30d89c7, 0x36c5bff8, 0x1282e940, 0x6c913d0}, 
    {0xf15beef0, 0x35a2a59f, 0x11e01902, 0x676a6f9}, 
    {0xefb344dc, 0x34897aa0, 0x11450245, 0x6293031}, 
    {0xee133df5, 0x3379c719, 0x10b12e06, 0x5e05344}, 
    {0xec7b9047, 0x32731a52, 0x10242de6, 0x59bbbd0}, 
    {0xeaebf548, 0x31750a3c, 0xf9d9b6f, 0x55b1c7d}, 
    {0xe96429a7, 0x307f32f2, 0xf1d1769, 0x51e2e59}, 
    {0xe7e3ed19, 0x2f913653, 0xea24941, 0x4e4b037}, 
    {0xe66b022f, 0x2eaabb90, 0xe2cde82, 0x4ae6628}, 
    {0xe4f92e2e, 0x2dcb6eda, 0xdbc8a51, 0x47b1904}, 
    {0xe38e38e3, 0x2cf30104, 0xd510501, 0x44a95f6}, 
    {0xe229ec87, 0x2c212735, 0xcea0ba5, 0x41cae1a}, 
    {0xe0cc1597, 0x2b559aa1, 0xc875fb9, 0x3f13626}, 
    {0xdf7482b8, 0x2a901845, 0xc28c6c4, 0x3c80617}, 
    {0xde230497, 0x29d060a5, 0xbce0a0e, 0x3a0f8e9}, 
    {0xdcd76dd3, 0x29163796, 0xb76f656, 0x37bec57}, 
    {0xdb9192dc, 0x28616409, 0xb235b93, 0x358c09e}, 
    {0xda5149e1, 0x27b1afd5, 0xad30cb5, 0x3375847}, 
    {0xd9166ab7, 0x2706e78e, 0xa85df6d, 0x31797f9}, 
    {0xd7e0cec3, 0x2660da57, 0xa3babff, 0x2f96648}, 
    {0xd6b050e8, 0x25bf59be, 0x9f44d10, 0x2dcab92}, 
    {0xd584cd74, 0x25223993, 0x9af9f79, 0x2c151d9}, 
    {0xd45e220d, 0x24894fc8, 0x96d8227, 0x2a7449f}, 
    {0xd33c2da1, 0x23f47453, 0x92dd5f0, 0x28e70cc}, 
    {0xd21ed057, 0x2363810b, 0x8f07d75, 0x276c490}, 
    {0xd105eb80, 0x22d65192, 0x8b55d01, 0x2602f49}, 
    {0xcff1618b, 0x224cc339, 0x87c5a70, 0x24aa16f}, 
    {0xcee115f2, 0x21c6b4e6, 0x8455d12, 0x2360c7b}, 
    {0xcdd4ed36, 0x21440701, 0x8104d91, 0x22262d8}, 
    {0xcccccccd, 0x20c49b5c, 0x7dd15e1, 0x20f97cd}, 
    {0xcbc89b18, 0x20485520, 0x7aba124, 0x1fd9f71}, 
    {0xcac83f5c, 0x1fcf18bc, 0x77bdb9c, 0x1ec6e99}, 
    {0xc9cba1b4, 0x1f58cbd1, 0x74db295, 0x1dbfacc}, 
    {0xc8d2ab0a, 0x1ee55526, 0x7211458, 0x1cc3a34}, 
    {0xc7dd450e, 0x1e749c94, 0x6f5f018, 0x1bd2396}, 
    {0xc6eb5a2b, 0x1e068af9, 0x6cc35e7, 0x1aeae46}, 
    {0xc5fcd583, 0x1d9b0a2f, 0x6a3d6a7, 0x1a0d21a}, 
    {0xc511a2e6, 0x1d3204f7, 0x67cc3fd, 0x1938767}, 
    {0xc429aec8, 0x1ccb66f7, 0x656f047, 0x186c6f4}, 
    {0xc344e63f, 0x1c671ca6, 0x6324e90, 0x17a89f2}, 
    {0xc26336f8, 0x1c051346, 0x60ed285, 0x16ec9f9}, 
    {0xc1848f35, 0x1ba538db, 0x5ec706e, 0x16380fc}, 
    {0xc0a8ddc3, 0x1b477c1e, 0x5cb1d25, 0x158a948}, 
    {0xbfd011f8, 0x1aebcc78, 0x5aace0a, 0x14e3d7c}, 
    {0xbefa1bac, 0x1a9219f5, 0x58b7902, 0x1443881}, 
    {0xbe26eb32, 0x1a3a5542, 0x56d1469, 0x13a958b}, 
    {0xbd567158, 0x19e46fa2, 0x54f970e, 0x131500f}, 
    {0xbc889f5e, 0x19905ae5, 0x532f82f, 0x12863c3}, 
    {0xbbbd66f4, 0x193e0968, 0x5172f70, 0x11fcc96}, 
    {0xbaf4ba35, 0x18ed6e09, 0x4fc34d7, 0x11786b0}, 
    {0xba2e8ba3, 0x189e7c20, 0x4e200c4, 0x10f8e6e}, 
    {0xb96ace23, 0x18512782, 0x4c88bf1, 0x107e05b}, 
    {0xb8a974fa, 0x18056470, 0x4afcf6a, 0x1007932}, 
    {0xb7ea73ca, 0x17bb279b, 0x497c489, 0xf955db}, 
    {0xb72dbe8b, 0x1772661c, 0x48064f3, 0xf27362}, 
    {0xb673498f, 0x172b156e, 0x469aa93, 0xebcefe}, 
    {0xb5bb0976, 0x16e52b6d, 0x4538f98, 0xe56607}, 
  };
  
  u64 a = v.m;
  unsigned j=(a>>(64-7))&63, dj = (a>>(64-7-32));
  u64 sc = (e&1)?0x100000000ull:0xb504f335ull; // scale factors 1 and 1/sqrt(2)
  u64 c0 = T[j][0], c1 = T[j][1], c2 = T[j][2], c3 = T[j][3]; // polynomial coefficients
  // get an initial approximation r with ~30 bits precision
  u64 dj2 = dj*(u64)dj>>32, r = sc*((c0 - (dj*c1>>37)) + (dj2*(c2 - (dj*c3>>37))>>42))>>32, r2 = r*r;
  // Warning: if r2 has 64 bits, r2<<1 might overflow, thus cast to u128 before
  u128 H0 = ((u128)r2<<(1-(e&1)))*(u128)a; // a*r^2
  i64 h = H0>>35, hh = h>>33; //  h = a*r^2 - 1
  // one Newton iteration with x_next = x - x*(h/2 - 3/8*h^2) which provides ~90 bits
  u64 h2 = hh*hh, dh = 3*h2>>28;
  h -= dh;
  i128 Dr = (i128)h*-(i64)r;
  i64 dr = Dr>>35;
  v.e = 0x1fff + (0x7ffe - e) / 2;
  v.m = (r<<32) + (dr>>26);
  if(__builtin_expect((((dr^rn)+1)&((1<<26)-1))<3,0)){ // rounding test
    // a*r^2 has to fit into 3*64 = 192 bit since first ~60 bit are
    // known just use 128 bit of the tail to evaluate the correctly
    // rounded result
    r = v.m + ((dr>>25)&1); // initial estimation (round-to-nearest)
    if(r<(1ull<<62)) r = ~0ull; // if the estimation is in the next binade bring it back
    u128 Ra = r*(u128)a;
    u64 Rah = Ra>>64, Ral = Ra;
    u128 Hh = Rah*(u128)r;
    u128 Hl = Ral*(u128)r;
    Hh += Hl>>64;
    i64 h1 = Hh>>4;
    u64 h0 = Hh<<60|(u64)Hl>>4;
    i128 H = (u128)h1<<64|h0, dH = Ra>>3;
    u64 ddH = a>>3;
    // scan adding or subtracting 1 from r until the result is floor(1/sqrt(x))
    if(H<0){
      dH += ddH>>1;
      i128 pH;
      do {
	pH = H;
	H += dH;
	if(H>=0) break;
	r ++;
	dH += ddH;
      } while (1);
      H = pH;
      dH -= ddH>>1;
    } else {
      dH -= ddH>>1;
      do {
	H -= dH;
	r --;
	dH -= ddH;
	if(H<0) break;
      } while (1);
      dH += ddH>>1;
    }
    // now r = floor(1/sqrt(x))
    if(rn){ // round-to-nearest
      H += (dH>>1) + (ddH>>3);
      v.m = r + (H<0);
    } else { // directional modes
      v.m = r + ru;
    }
    if(__builtin_expect(!v.m, 0)){ // check that the result goes to the next binade
      v.m = 1ull<<63;
      v.e ++;
    }
    return v.f;
  }
  v.m += (!!(dr&rn))|ru;
  return v.f;
}
