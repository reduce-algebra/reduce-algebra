/* Correctly-rounded power function for binary32 values.

Copyright (c) 2022-2025 Alexei Sibidanov and Paul Zimmermann

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
#include <fenv.h> // for fegetround, FE_TONEAREST, FE_UPWARD
#ifdef __x86_64__
#include <x86intrin.h>
#define FLAG_T uint32_t
#else
#define FLAG_T fexcept_t
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;

/* __builtin_roundeven was introduced in gcc 10:
   https://gcc.gnu.org/gcc-10/changes.html,
   and in clang 17 */
#if ((defined(__GNUC__) && __GNUC__ >= 10) || (defined(__clang__) && __clang_major__ >= 17)) && (defined(__aarch64__) || defined(__x86_64__) || defined(__i386__))
# define roundeven_finite(x) __builtin_roundeven (x)
#else
/* round x to nearest integer, breaking ties to even */
static double
roundeven_finite (double x)
{
  double ix;
# if (defined(__GNUC__) || defined(__clang__)) && (defined(__AVX__) || defined(__SSE4_1__) || (__ARM_ARCH >= 8))
#  if defined __AVX__
   __asm__("vroundsd $0x8,%1,%1,%0":"=x"(ix):"x"(x));
#  elif __ARM_ARCH >= 8
   __asm__ ("frintn %d0, %d1":"=w"(ix):"w"(x));
#  else /* __SSE4_1__ */
   __asm__("roundsd $0x8,%1,%0":"=x"(ix):"x"(x));
#  endif
# else
  ix = __builtin_round (x); /* nearest, away from 0 */
  if (__builtin_fabs (ix - x) == 0.5)
  {
    /* if ix is odd, we should return ix-1 if x>0, and ix+1 if x<0 */
    union { double f; uint64_t n; } u, v;
    u.f = ix;
    v.f = ix - __builtin_copysign (1.0, x);
    if (__builtin_ctz (v.n) > __builtin_ctz (u.n))
      ix = v.f;
  }
# endif
  return ix;
}
#endif

// This code emulates the _mm_getcsr SSE intrinsic by reading the FPCR register.
// fegetexceptflag accesses the FPSR register, which seems to be much slower
// than accessing FPCR, so it should be avoided if possible.
// Adapted from sse2neon: https://github.com/DLTcollab/sse2neon
#if defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
#if defined(_MSC_VER)
#include <arm64intr.h>
#endif

typedef struct
{
  uint16_t res0;
  uint8_t  res1  : 6;
  uint8_t  bit22 : 1;
  uint8_t  bit23 : 1;
  uint8_t  bit24 : 1;
  uint8_t  res2  : 7;
  uint32_t res3;
} fpcr_bitfield;

inline static unsigned int _mm_getcsr(void)
{
  union
  {
    fpcr_bitfield field;
    uint64_t value;
  } r;

#if defined(_MSC_VER) && !defined(__clang__)
  r.value = _ReadStatusReg(ARM64_FPCR);
#else
  __asm__ __volatile__("mrs %0, FPCR" : "=r"(r.value));
#endif
  static const unsigned int lut[2][2] = {{0x0000, 0x2000}, {0x4000, 0x6000}};
  return lut[r.field.bit22][r.field.bit23];
}
#endif  // defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)

static inline int is_signalingf(float x) {
  b32u32_u u = {.f = x};
  /* To keep the following comparison simple, toggle the quiet/signaling bit,
   so that it is set for sNaNs.  This is inverse to IEEE 754-2008 (as well as
   common practice for IEEE 754-1985).  */
  u.u ^= 0x00400000;
  /* We have to compare for greater (instead of greater or equal), because x's
     significand being all-zero designates infinity not NaN.  */
  return (u.u & 0x7fffffff) > 0x7fc00000;
}

#ifdef CORE_MATH_SUPPORT_ERRNO
// assume x is not NaN
static inline int is_inf (float x) {
  b32u32_u u = {.f = x};
  return (u.u << 1) >= 0xff000000ull;
}
#endif

static inline double muldd(double xh, double xl, double ch, double cl, double *l){
  double ahlh = ch*xl, alhh = cl*xh, ahhh = ch*xh, ahhl = __builtin_fma(ch, xh, -ahhh);
  ahhl += alhh + ahlh;
  ch = ahhh + ahhl;
  *l = (ahhh - ch) + ahhl;
  return ch;
}

static inline double mulddd(double xh, double xl, double ch, double *l){
  double ahlh = ch*xl, ahhh = ch*xh, ahhl = __builtin_fma(ch, xh, -ahhh);
  ahhl += ahlh;
  ch = ahhh + ahhl;
  *l = (ahhh - ch) + ahhl;
  return ch;
}

static __attribute__((noinline)) double polydd(double xh, double xl, int n, const double c[][2], double *l){
  int i = n-1;
  double ch = c[i][0], cl = c[i][1];
  while(--i>=0){
    ch = muldd(xh,xl,ch,cl,&cl);
    double th = ch + c[i][0], tl = (c[i][0] - th) + ch;
    ch = th;
    cl += tl + c[i][1];
  }
  *l = cl;
  return ch;
}

static float as_powf_accurate2(float, float, int, FLAG_T);

static inline int isint(float y0){
  b32u32_u wy = {.f = y0};
  int ey = ((wy.u>>23) & 0xff) - 127, s = ey + 9;
  if(ey>=0){
    if(s>=32) return 1;
    return !(wy.u<<s);
  }
  if(!(wy.u<<1)) return 1;
  return 0;
}

static inline int isodd(float y0){
  b32u32_u wy = {.f = y0};
  int ey = ((wy.u>>23) & 0xff) - 127, s = ey + 9, odd = 0;
  if(ey>=0){
    if(s<32 && !(wy.u<<s)) odd = (wy.u>>(32-s))&1;
    if(s==32) odd = wy.u&1;
  }
  return odd;
}

static FLAG_T
get_flag (void)
{
  /* Warning: on __aarch64__ (for example cfarm103), FE_UPWARD=0x400000
     instead of 0x800. */
#if defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)
  return _mm_getcsr ();
#else
  fexcept_t flag;
  fegetexceptflag (&flag, FE_INEXACT);
  return flag;
#endif
}

static void
set_flag (FLAG_T flag)
{
#if defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)
  _mm_setcsr (flag);
#else
  fesetexceptflag (&flag, FE_INEXACT);
#endif
}

// return non-zero if x^y is exact (and exactly representable as a float)
static int
is_exact (float x, float y)
{
  /* All cases such that x^y might be exact are:
     (a) |x| = 1
     (b) y integer, 0 <= y <= 15
         (where 15 is the largest integer k such that 3^k fits in 24 bits)
     (c) y<0: x=1 or (x=2^e and |y|=n*2^-k with 2^k dividing e)
     (d) y>0: y=n*2^f with -4 <= f <= -1 and 1 <= n <= 15
     In cases (b)-(d), the low 16 bits of the encoding of y are zero,
     thus we use that for an early exit test.
     (For case (c), x=0x1p+1 and y=-0x1.2ap+7, only 16 low bits of the
     encoding of y are zero.) */

  b32u32_u v = {.f = x}, w = {.f = y};
  if (__builtin_expect ((v.u << 1) != 0x7f000000 && // |x| <> 1
                        (w.u << (32 - 16)) != 0, 1))
    return 0;

  if (__builtin_expect ((v.u << 1) == 0x7f000000, 0)) // |x| = 1
    return 1;

  // xmax[y] for 1<=y<=15 is the largest odd m such that m^y fits in 24 bits
  static const uint32_t xmax[] = { 0, 0xffffff, 4095, 255, 63, 27, 15, 9,
                                   7, 5, 5, 3, 3, 3, 3, 3};
  if (y >= 0 && isint (y)) {
    /* let x = m*2^e with m an odd integer, x^y is exact when
       - y = 0 or y = 1
       - m = 1 or -1 and -149 <= e*y < 128
       - if |x| is not a power of 2, 2 <= y <= 15 and
         m^y should fit in 24 bits
    */
    uint32_t m = v.u & 0x7fffff; // low 23 bits of significand
    int32_t e = ((v.u << 1) >> 24) - 0x96;
    if (e >= -149)
      m |= 0x800000;
    else // subnormal numbers
      e++;
    int t = __builtin_ctz (m);
    m = m >> t;
    e += t;
    /* For normal numbers, we have x = m*2^e. */
    if (y == 0 || y == 1)
      return 1;
    if (m == 1)
      return -149 <= y * e && y * e < 128;
    // now for y < 0 or 15 < y it cannot be exact
    if (y < 0 || 15 < y)
      return 0;
    // now 2 <= y <= 15
    int y_int = (int) y;
    if (m > xmax[y_int])
      return 0;
    // |x^y| = m^y * 2^(e*y)
    uint64_t my = m * m;
    for (int i = 2; i < y_int; i++)
      my = my * m;
    // my = m^y
    t = 32 - __builtin_clz (m);
    // 2^(t-1) <= m^y < 2^t thus 2^(e*y + t - 1) <= |x^y| < 2^(e*y + t)
    int32_t ez = e * y_int + t;
    if (ez <= -149 || 128 < ez)
      return 0;
    // since m is odd, x^y is an odd multiple of 2^(e*y)
    return e * y_int >= -149;
  }

  uint32_t n = w.u & 0x7fffff;
  int32_t f = ((w.u << 1) >> 24) - 0x96;
  if (f >= -149)
    n |= 0x800000;
  else // subnormal numbers
    f++;
  int t = __builtin_ctz (n);
  n = n >> t;
  f += t;
  // |y| = n*2^f with n odd

  uint32_t m = v.u & 0x7fffff;
  int32_t e = ((v.u << 1) >> 24) - 0x96;
  if (e >= -149)
    m |= 0x800000;
  else // subnormal numbers
    e++;
  t = __builtin_ctz (m);
  m = m >> t;
  e += t;
  // |x| = m*2^e with m odd

  /* if y < 0, the only cases where x^y might be exact are:
   * if y = -n*2^f with f >= 0
   * if y = -n*2^f with f < 0, if x = 2^e with 2^(-f) dividing e
   */
  if (y < 0)
  {
    int32_t ez;
    if (m != 1) return 0;
    // now x = 2^e
    if (f >= 0)
      ez = ((e >= 0) ? -(e << f) : (-e << f)) * n;
    else {
      // y = -n*2^f thus k = -f
      // now e <> 0
      t = __builtin_ctz (e);
      if (-f > t) return 0; // 2^k does not divide e
      ez = (-e >> (-f)) * n;
    }
    return -149 <= ez && ez < 128;
  }

  /* now y > 0, y is not a integer, y = n*2^f with n odd and f < 0.
     Since x^(n*2^f) = (x^(2^f))^n, and n is odd, necessarily
     x is an exact (2^k)th power with k=-f.
     This implies x is a square. Since x = m*2^e with m odd,
     necessarily m is a square, and e is even. */
  while (f++) {
    // try to extract a square from m*2^e
    if (e&1) return 0;
    e = e / 2;
    float dm = (float) m;
    float s = __builtin_roundf (__builtin_sqrtf (dm));
    if (s * s != dm)
      return 0;
    /* The above call of sqrtf() might set the inexact flag, but in case
       it happens, m is not a square, thus x^y cannot be exact. */
    m = (uint32_t) s;
  }

  // Now |x^y| = (m*2^e)^n with m, n odd integers
  // now for 15 < n it cannot be exact, unless m=1
  if (m > 1)
  {
    if (15 < n)
      return 0;
    // now n <= 15
    if (m > xmax[n])
      return 0;
  }
  // |x^y| = m^n * 2^(e*n) with m odd
  uint32_t my = m, n0 = n;
  while (n0-- > 1)
    my = my * m;
  // |x^y| = my * 2^(e*n)
  t = 32 - __builtin_clz (my); // number of significant bits of m^n
  /* x^y is an odd multiple of 2^(e*n) thus we should have e*n >= -149,
     we also have 2^(t-1) <= m^n thus 2^(e*n+t-1) <= |x^y| < 2^(e*n+t)
     and we need e*n+t <= 128 */
  return -149 <= e * (int) n && e * (int) n + t <= 128;
}

float cr_powf(float x0, float y0){
  volatile FLAG_T flag = get_flag ();
  static const double ix[] = {
    0x1p+0, 0x1.f07c1f07cp-1, 0x1.e1e1e1e1ep-1, 0x1.d41d41d42p-1,
    0x1.c71c71c72p-1, 0x1.bacf914c2p-1, 0x1.af286bca2p-1, 0x1.a41a41a42p-1,
    0x1.99999999ap-1, 0x1.8f9c18f9cp-1, 0x1.861861862p-1, 0x1.7d05f417dp-1,
    0x1.745d1745dp-1, 0x1.6c16c16c1p-1, 0x1.642c8590bp-1, 0x1.5c9882b93p-1,
    0x1.555555555p-1, 0x1.4e5e0a72fp-1, 0x1.47ae147aep-1, 0x1.414141414p-1,
    0x1.3b13b13b1p-1, 0x1.3521cfb2bp-1, 0x1.2f684bda1p-1, 0x1.29e4129e4p-1,
    0x1.249249249p-1, 0x1.1f7047dc1p-1, 0x1.1a7b9611ap-1, 0x1.15b1e5f75p-1,
    0x1.111111111p-1, 0x1.0c9714fbdp-1, 0x1.084210842p-1, 0x1.041041041p-1, 0x1p-1
  };
  
  static const double lix[][2] = {
    {0x0p+0, 0x0p+0}, {-0x1.6cp-5, 0x1.4b229b87f3f89p-15},
    {-0x1.66p-4, -0x1.fb7d654235799p-15}, {-0x1.08p-3, -0x1.8b119b2c9c87bp-12},
    {-0x1.5cp-3, -0x1.a39fa6533294dp-19}, {-0x1.acp-3, -0x1.ebc5b663dd4b8p-12},
    {-0x1.fcp-3, 0x1.f4a37fe0fa46fp-14}, {-0x1.24p-2, -0x1.01eac33103e6bp-12},
    {-0x1.4ap-2, 0x1.61ed0d15725ep-12}, {-0x1.6ep-2, -0x1.10e6ceb499ba9p-13},
    {-0x1.92p-2, 0x1.115db8ada837dp-12}, {-0x1.b4p-2, -0x1.fafdce266d7aep-12},
    {-0x1.d6p-2, -0x1.d4f80cd19906fp-12}, {-0x1.f8p-2, 0x1.5ea5ccd0a7396p-12},
    {0x1.e8p-2, -0x1.0500d67fe62ebp-13}, {0x1.c8p-2, 0x1.9dc2d41aa4626p-14},
    {0x1.a8p-2, 0x1.ff2e2ff321344p-11}, {0x1.8ap-2, 0x1.130157f4c3a3ep-11},
    {0x1.6cp-2, 0x1.61ed0cad929ccp-11}, {0x1.5p-2, -0x1.2089a632d7949p-11},
    {0x1.32p-2, 0x1.7fdc6dfb2d21ap-11}, {0x1.16p-2, 0x1.380a6c36088f3p-11},
    {0x1.f6p-3, -0x1.3ab7dc7ba81acp-18}, {0x1.cp-3, -0x1.cc2c0061ef1a2p-14},
    {0x1.8ap-3, 0x1.130157c97bbep-12}, {0x1.56p-3, 0x1.ee14ff34c4128p-14},
    {0x1.22p-3, 0x1.b5b854c4fde69p-12}, {0x1.ep-4, 0x1.635d1df7cb0b5p-13},
    {0x1.7ep-4, -0x1.3f6d2636c101ep-13}, {0x1.1cp-4, -0x1.33567f1b193a4p-14},
    {0x1.78p-5, -0x1.8d66c5313a71dp-14}, {0x1.74p-6, 0x1.f7430ee200ep-17}, {0x0p+0, 0x0p+0}
  };
  double x = x0, y = y0;
  b64u64_u tx = {.f = x}, ty = {.f = y};
  if(__builtin_expect (tx.u<<1 == (uint64_t)0x3ff<<53, 0)){ // |x|=1
    if(tx.u>>63){ // x=-1
      if((ty.u<<1) > (uint64_t)0x7ff<<53) return y0 + y0; // y=nan
      if(isint(y0)) return (isodd(y0)) ? x0 : -x0;
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      return (x - x) / (x - x);  // NaN /  (-1)^y for non-integer y, should raise 'Invalid operation' exception.
    }
    return is_signalingf (y0) ? x0 + y0 : x0; // 1^y = 1 except for y = sNaN
  }
  if(__builtin_expect (ty.u<<1 == 0, 0))
    return is_signalingf (x0) ? x0 + y0 : 1.0f; // x^0 = 1 except for x = sNaN
  if(__builtin_expect ((ty.u<<1) >= (uint64_t)0x7ff<<53, 0)){ // y=Inf/NaN
    // the case |x|=1 was already checked above
    if((tx.u<<1) > (uint64_t)0x7ff<<53) return x0 + y0; // x=NaN
    if((ty.u<<1) == (uint64_t)0x7ff<<53){
      if(((tx.u<<1) < ((uint64_t)0x3ff<<53)) ^ (ty.u>>63)){
	return 0;
      } else {
	return 1.0f/0.0f;
      }
    }
    return x0 + y0;
  }
  if(__builtin_expect (tx.u >= (uint64_t)0x7ff<<52, 0)){ // x is Inf, NaN or less than 0
    if((tx.u<<1) == (uint64_t)0x7ff<<53){ // x is +Inf or -Inf
      if(!isodd(y0)) x0 = __builtin_fabsf(x0);
      if(ty.u>>63)return 1/x0; else return x0;
    }
    if((tx.u<<1) > (uint64_t)0x7ff<<53) return x0 + x0; // x is NaN
    if(__builtin_expect(tx.u > (uint64_t)0x7ff<<52, 0)) // x <= 0
      if(!isint(y0) && x != 0) {
#ifdef CORE_MATH_SUPPORT_ERRNO
        errno = EDOM;
#endif
	return (x - x) / (x - x);  // NaN, should raise 'Invalid operation' exception.
      }
  }
  if(__builtin_expect (!(tx.u<<1), 0)){ // x=+0 or -0
    if(ty.u>>63){ // y < 0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      if(isodd(y0)) {
	return 1.0f/__builtin_copysignf(0.0f,x0);
      }  else {
	return 1.0f/0.0f;
      }
    } else { // y > 0
      if(isodd(y0))
	return __builtin_copysignf(1.0f,x0)*0.0f;
      else
	return 0.0f;
    }
  }
  uint64_t m = tx.u & ~(uint64_t)0>>12;
  int e = ((tx.u>>52)&0x7ff) - 0x3ff;
  int j = (m + ((int64_t)1<<(52-6)))>>(52-5), k = j>13;
  e += k;
  b64u64_u xd = {.u = m | (uint64_t)0x3ff<<52};
  double z = __builtin_fma(xd.f, ix[j], -1.0);
  static const double c[] =
    {0x1.71547652b82fep+0, -0x1.71547652b82fep-1, 0x1.ec709dc3a2d0bp-2, -0x1.71547652bc4a9p-2,
     0x1.2776c441b72ep-2, -0x1.ec709bdf453ecp-3, 0x1.a6406efd4b877p-3, -0x1.717d824a520f7p-3};
  double z2 = z*z, z4 = z2*z2;
  double c6 = c[6] + z*c[7];
  double c4 = c[4] + z*c[5];
  double c2 = c[2] + z*c[3];
  double c0 = c[0] + z*c[1];
  c0 += z2*c2;
  c4 += z2*c6;
  c0 += z4*c4;
  double l = z*c0 - lix[j][1];
  y *= 16;
  double zt = (e - lix[j][0])*y;
  z = l*y + zt;
  if(__builtin_expect(z>2048, 0)){
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE; // overflow
#endif
    if(isodd(y0))
      return __builtin_copysignf(0x1p127f, x0)*0x1p127f;
    else {
      return 0x1p127f*0x1p127f;
    }
  }
  if(__builtin_expect(z<-2400, 0)){
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE; // underflow
#endif
    if(isodd(y0))
      return __builtin_copysignf(0x1p-126f, x0)*0x1p-126f;
    else
      return 0x1p-126f*0x1p-126f;
  }
  if(__builtin_fabs(z)<0x1p-26) return 1.0 + z;
  double ia = __builtin_floor(z), h = __builtin_fma(l, y, zt - ia);
  static const double ce[] =
    {0x1.62e42fefa398bp-5, 0x1.ebfbdff84555ap-11, 0x1.c6b08d4ad86d3p-17,
     0x1.3b2ad1b1716a2p-23, 0x1.5d7472718ce9dp-30, 0x1.4a1d7f457ac56p-37};
  static const double tb[] =
    {0x1p+0, 0x1.0b5586cf9890fp+0, 0x1.172b83c7d517bp+0, 0x1.2387a6e756238p+0,
     0x1.306fe0a31b715p+0, 0x1.3dea64c123422p+0, 0x1.4bfdad5362a27p+0, 0x1.5ab07dd485429p+0,
     0x1.6a09e667f3bcdp+0, 0x1.7a11473eb0187p+0, 0x1.8ace5422aa0dbp+0, 0x1.9c49182a3f09p+0,
     0x1.ae89f995ad3adp+0, 0x1.c199bdd85529cp+0, 0x1.d5818dcfba487p+0, 0x1.ea4afa2a490dap+0};
  int64_t il = ia, jl = il&0xf, el = il - jl;
  el >>= 4;
  double s = tb[jl];
  b64u64_u su = {.u = (el + (uint64_t)0x3ff)<<52};
  s *= su.f;
  double h2 = h*h;
  c0 = ce[0] + h*ce[1];
  c2 = ce[2] + h*ce[3];
  c4 = ce[4] + h*ce[5];
  c0 += h2*(c2 + h2*c4);
  double w = s*h;
  b64u64_u rr = {.f = s + w*c0};
  // with off=467, fails for x,y=0x1.fd12b4p-1,-0x1.d0b058p+13 and RNDZ
  uint64_t off = 468;
  if(((rr.u+off)&0xfffffff) <= 2*off)
    return as_powf_accurate2 (x0, y0, is_exact (x0, y0), flag);
  int et = ((ty.u>>52)&0x7ff) - 0x3ff;
  uint64_t kk = (et >= -11) ? ty.u<<(11+et) : ty.u>>(-11-et);
  if(!(kk<<1)&&kk) rr.f = __builtin_copysign(rr.f,x);
  float res = rr.f;
#ifdef CORE_MATH_SUPPORT_ERRNO
  /* It is not enough to check if res is infinite, since for rounding towards
     zero, we have overflow for x^y >= 2^128, but res = MAX_FLT.
     It is also not enough to check if rr >= 2^128, since for rounding upwards,
     we have overflow for MAX_DBL < rr < 2^128. */
  // For RNDN, we have underflow when |x^y| < 2^-126*(1-2^-25)
  // FOR RNDZ/RNDD, we have underflow when |x^y| < 2^-126
  // For RNDU, we have underflow when |x^y| < 2^-126*(1-2^-24)
  double thres = (fegetround () == FE_TONEAREST) ? 0x1.ffffffp-127
    : (fegetround () == FE_UPWARD) ? 0x1.fffffep-127
    : 0x1p-126;
  if (is_inf (res) || __builtin_fabs (rr.f) >= 0x1p128 ||
      __builtin_fabs (rr.f) < thres) {
    errno = ERANGE; // overflow or underflow
  }
#endif
  return res;
}

// when is_exact is non-zero, flag is the original inexact flag
static float as_powf_accurate2(float x0, float y0, int is_exact, FLAG_T flag){
  static const double o[] = {1, 2};
  static const double ch[][2] =
    {{0x1.71547652b82fep+1, 0x1.777d0ffda2b89p-55}, {0x1.ec709dc3a03fdp-1, 0x1.d27f04ff73b3ap-55},
     {0x1.2776c50ef9bfep-1, 0x1.e4b514251d0ecp-55}, {0x1.a61762a7aded9p-2, 0x1.de632dc7f6998p-57},
     {0x1.484b13d7c02aep-2, 0x1.a320ec342ddb3p-56}, {0x1.0c9a84993fd48p-2, -0x1.e6425ce9a74a4p-57},
     {0x1.c68f568d8beafp-3, -0x1.03a175487feabp-57}, {0x1.89f3b14657dfbp-3, 0x1.f04a3acf0bcf7p-57},
     {0x1.5b9ad2f2d12ap-3, -0x1.68fdff6815a6fp-58}, {0x1.3702165b88acbp-3, 0x1.45b052ace6c8ep-60},
     {0x1.1998f60f2f005p-3, -0x1.79a94f62fb524p-57}, {0x1.f9bc428e30809p-4, -0x1.51f063387e47p-59},
     {0x1.1ac0ab871296ap-3, 0x1.2ba6a2e1a625bp-57}
    };
  static const double ce[][2] =
    {{0x1p+0, 0x1.f7d70599926c4p-98}, {0x1.62e42fefa39efp-1, 0x1.abc9e3b39856bp-56},
     {0x1.ebfbdff82c58fp-3, -0x1.5e43a540c283dp-57}, {0x1.c6b08d704a0cp-5, -0x1.d3316277451e6p-59},
     {0x1.3b2ab6fba4e77p-7, 0x1.4e66003ba7f85p-62}, {0x1.5d87fe78a6731p-10, 0x1.07183d46a9697p-66},
     {0x1.430912f86c787p-13, 0x1.bc81afca4c93p-67}, {0x1.ffcbfc588b0c7p-17, -0x1.e63f6f0116f4cp-71},
     {0x1.62c0223a5c826p-20, -0x1.30542d98ea4a5p-74}, {0x1.b5253d395e7c6p-24, -0x1.9285a132ce05ep-80},
     {0x1.e4cf5158b7b01p-28, -0x1.9ac1facae1b88p-83}, {0x1.e8cac7351a7a8p-32, -0x1.4fb82adebd76bp-91},
     {0x1.c3bd65182746dp-36, 0x1.84ad0689d30ep-91}, {0x1.8161931d765c3p-40, -0x1.254c6535279cep-95},
     {0x1.314943a26c9e2p-44, -0x1.f4f2fdc14fb82p-98}, {0x1.c36e53b459602p-49, 0x1.f0d06a5a63c41p-103},
     {0x1.397637b3876a4p-53, -0x1.5632c551ae458p-107}, {0x1.98fbfefdddb51p-58, -0x1.fd134923d52b4p-115}};
  double x = x0, y = y0;
  b64u64_u t = {.f = x};
  int e = ((t.u>>52)&0x7ff) - 0x3ff;
  t.u &= ~(uint64_t)0>>12;
  int k = t.u > 0x6a09e667f3bcdull;
  e += k;
  t.u |= (int64_t)0x3ff<<52;
  x = t.f;
  double xm = x-o[k], xp = x+o[k], zh = xm/xp, zl = __builtin_fma(zh,-xp,xm)/xp;
  double z2l, z2h = muldd(zh, zl, zh, zl, &z2l);
  z2h = polydd(z2h,z2l, 13, ch, &z2l);
  zh = muldd(zh,zl, z2h,z2l, &zl);
  zh = mulddd(zh,zl, y, &zl);
  double ey = e*y, eh = ey + zh, el = ((ey - eh) + zh) + zl, ee = roundeven_finite(eh);
  eh -= ee;
  eh = polydd(eh, el, 18, ce, &el);
  b64u64_u r = {.u = ((uint64_t)0x3ff+(int64_t)ee)<<52};
  b32u32_u ty = {.f = y0};
  int et = ((ty.u>>23)&0xff) - 0x7f;
  uint32_t kk = (8+et>=0) ? ty.u<<(8+et) : ty.u>>(-8-et);
  uint32_t isint = !(kk<<1|et>>31) || et>=23;
  b64u64_u ll = {.f = el}, lh = {.f = eh};
  if(((ll.u>>(6*4-1))&((1<<29)-1)) == ((1<<29)-1)){
    if(eh<1){
      if(el>=0x1p-54){
	el -= 0x1p-53;
	eh += 0x1p-53;
      } else if(el<=-0x1p-54){
	el += 0x1p-53;
	eh -= 0x1p-53;
      }
    } else {
      if(el>=0x1p-53){
	el -= 0x1p-52;
	eh += 0x1p-52;
      }else if(el<=-0x1p-53){
	el += 0x1p-52;
	eh -= 0x1p-52;
      }
    }
  } else if(((ll.u>>(6*4-1))&((1<<29)-1)) == 0 ){
    if(el>0){
      if(eh<1){
	if(el>=0x1p-53){
	  el -= 0x1p-53;
	  eh += 0x1p-53;
	}
      } else {
	if(el>=0x1p-52){
	  el -= 0x1p-52;
	  eh += 0x1p-52;
	}
      }
    } else {
      if(eh<1){
	if(el<=-0x1p-53){
	  el += 0x1p-53;
	  eh -= 0x1p-53;
	}
      } else {
	if(el<=-0x1p-52){
	  el += 0x1p-52;
	  eh -= 0x1p-52;
	}
      }
    }
  }
  ll.f = el;
  lh.f = eh;
  if((lh.u&0xfffffff) == 0){
    if(__builtin_fabs(ll.f)>0x1p-91){
      if(el<0){
	lh.u--;
	eh = lh.f;
      } else {
	lh.u++;
	eh = lh.f;
      }
    }
  }
  
  eh *= r.f;
  el *= r.f;
  if(isint && kk){
    eh = __builtin_copysign(eh, x0);
  }
  float res = eh;
  if (is_exact)
    set_flag (flag);
#ifdef CORE_MATH_SUPPORT_ERRNO
  if ((__builtin_fabsf (res) < 0x1p-126f && !is_exact) ||
      __builtin_fabs (eh) >= 0x1p128)
    errno = ERANGE;
#endif
  return res;
}
