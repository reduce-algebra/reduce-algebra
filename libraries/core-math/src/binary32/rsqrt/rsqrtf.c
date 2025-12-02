/* Correctly-rounded reciprocal square root of binary32 value.

Copyright (c) 2022-2023 Alexei Sibidanov.

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
#include <fenv.h> // for feraiseexcept, FE_INVALID

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;

float cr_rsqrtf(float x){
  double xd = x;
  b32u32_u ix = {.f = x};
  if(__builtin_expect(ix.u >= 0xff<<23 || ix.u==0, 0)){
    if(!(ix.u << 1))
    {
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      return 1.0f/x; // +/-0
    }
    if(ix.u >> 31){
      ix.u &= ~0u>>1;
      if(ix.u > 0xff<<23) return x + x; // nan
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      feraiseexcept (FE_INVALID);
      return __builtin_nanf("<0");
    }
    if(!(ix.u<<9)) return 0.0f;
    return x + x; // nan
  }
  unsigned m = ix.u<<8;
  if(__builtin_expect(ix.u == 0x2f7e2au || m == 0xbdf8a800u || m == 0x55b7bd00u, 0)){
    if(ix.u != 0x0055b7bdu){
      unsigned e = ix.u>>23, k = 1;
      if(ix.u == 0x2f7e2au) e = -1;
      if(m == 0x55b7bd00u) k = 0;
      static const b32u32_u tb[] = {{.u = 0x000c1740u}, {.u = 0x005222e0u}};
      b32u32_u r = tb[k], dr;
      e = (512 - e)/2 - 578;
      r.u |= e<<23;
      dr.u = (e-25)<<23;
      return r.f - dr.f;
    }
  }
  return (1.0/xd)*__builtin_sqrt(xd);
}

#ifdef __INTEL_CLANG_COMPILER
// rsqrt is called invsqrt with icx
extern float invsqrtf (float);
float rsqrtf(float x){
  return invsqrtf (x);
}
#endif
