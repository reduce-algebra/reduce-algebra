/* Correctly-rounded Euclidean distance function (hypot) for binary16 value.

Copyright (c) 2025 Maxence Ponsardin.

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
#include <fenv.h> // for FE_TONEAREST, ...
#include <math.h> // only used during performance tests

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {_Float16 f; uint16_t u;} b16u16_u;
typedef union {double f; uint64_t u;} b64u64_u;

_Float16 cr_hypotf16(_Float16 x, _Float16 y){
  b64u64_u tx = {.f = x};
  b64u64_u ty = {.f = y};
  double ret = sqrt(tx.f * tx.f + ty.f * ty.f);
#ifdef CORE_MATH_SUPPORT_ERRNO
  int rnd = fegetround();
  if (rnd == FE_TONEAREST) { // rounding mode is rndn
    if (ret < 0x1.ffep-15 && (double) (_Float16) ret != ret) // underflow and inex
      errno = ERANGE;
    if (ret >= 0x1.ffep+15)
      errno = ERANGE;
  }
  if (rnd == FE_TOWARDZERO || rnd == FE_DOWNWARD) { // rounding mode is rndz/rndd
    if (ret < 0x1p-14 && (double) (_Float16) ret != ret) // underflow and inex
      errno = ERANGE;
    if (ret > 0x1p+16)
      errno = ERANGE;
  }
  if (rnd == FE_UPWARD) { // rounding mode is rndu
    if (ret < 0x1.ffcp-15 && (double) (_Float16) ret != ret) // underflow and inex
      errno = ERANGE;
    if (ret > 0x1.ffcp+15)
      errno = ERANGE;
  }
#endif
  return ret; 
}

// dummy function since GNU libc does not provide it
_Float16 hypotf16 (_Float16 x, _Float16 y) {
	return (_Float16) hypotf ((float) x, (float) y);
}
