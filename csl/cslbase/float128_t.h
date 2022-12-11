// float128_t.h                                Copyright Arthur Norman 2022

// $Id$

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


// *************************
// * * * W A R N I N G * * *
// *************************
//
// It is possible that on some platforms - especially 32-bit x86 ones -
// that floating point operations are compiled to use 80-bit extra
// precision for some intermediate working. That could potentially
// disrupt things for me. If necessary one can set compilation flags
// such as "-msse2" to avoid that. I believe that on 64-bit systems that
// double precision operations always round in the IEEE style and so
// will be safe.

  
#ifndef header_float128_t
#define header_float128_t

#ifdef HAVE_BITCAST
#include <bit>
using std::bit_cast;
#else // HAVE_BITCAST
// For most of CSL this is a redundant repeat of stuff from machine.h,
// however by including it here I make this header free-standing.
template <class To, class From>
std::enable_if_t<
    sizeof(To) == sizeof(From) &&
    std::is_trivially_copyable_v<From> &&
    std::is_trivially_copyable_v<To>,
    To>
bit_cast(const From& src) noexcept
{   static_assert(std::is_trivially_constructible_v<To>,
        "This implementation additionally requires "
        "destination type to be trivially constructible");
    To dst;
    std::memcpy(&dst, &src, sizeof(To));
    return dst;
}
#define HAVE_BITCAST 1
#endif // HAVE_BITCAST

#include <cstring>

// For any degree of sanity at all here I need to arrange that I can use
// 128-bit floats using the normal arithmetic operators even though they
// are liable to be implemented in software with ugly function calls
// as the "real" way of doing things. So here is a C++ wrapper with lots
// of operator overloading.


// With this I can write literals as for instance
//       123.456e78_Q                           normal decimal style.
// OR    0xDDDD'DDDDDDDDDDDD'DDDDDDDDDDDDDDDD_QX hexadecimal 128-bits.
// These generate objects of type QuadFloat and that type supports
// the basic arithmetic operations +-*/ and comparison operations such
// as ">" and ">=".
// It directed to and ostream via "<<" the data is displayed in hex
// format. Well I have a chance of using G format decimal printing so
// I should use that unless the "hex" flag is set.

// Note that hex input is FRAGILE. For instance the hex input must have
// 32 hex digits (the separator "'" may be used to help make the format
// clearer) and they must be proper hex digits.
// Decimal input is intended to yield an exactly correct value in particular
// when the input is a decimal rendering of an exactly representable value,
// however I have not put any effort into coping with sub-normal numbers.
// If the decimal provided has a value between two representable values
// I attempt to round to the nearest, rounding to even om ambiguity. This
// is done subject to me using a limited number of guard bits in the
// calculation.

// This builds on top of the softfloat library from John R Hauser, a copy
// of which can be found elsewhere within the CSL/Reduce source tree.

extern "C" {
#include "softfloat.h"
}

#ifdef LITTLEENDIAN
#define fpOrder(a, b)    {a, b}
#define fp256Order(a, b) {a, b}
#define HIPART 1
#define LOPART 0
#else // LITTLEENDIAN
#define fpOrder(a, b)    {b, a}
#define fp256Order(a, b) {b, a}
#define HIPART 0
#define LOPART 1
#endif // LITTLEENDIAN

inline int  f128_exponent(const float128_t p);
inline void f128_set_exponent(float128_t *p, int n);
extern void f128_ldexp(float128_t *p, int n);
extern void f128_frexp(float128_t p, float128_t *r, int *x);
extern float128_t f128_modf(float128_t p, float128_t& intpart);

inline bool f128_infinitep(const float128_t p);
inline bool f128_finite(const float128_t p);
inline bool f128_nanp(const float128_t x);
inline bool f128_subnorm(const float128_t x);
inline bool f128_negative(const float128_t x);
inline void f128_minus(float128_t *x);
inline void f128_negate(float128_t *x);
extern void f128_split(const float128_t *x, float128_t *yhi, float128_t *ylo);

// This file may be used more of less stand-alone so I will not rely on
// "earlier" CSL headers to define these...

#ifndef UNUSED_NAME
#if __has_cpp_attribute(maybe_unused)
// C++17 introduced [[maybe_unused]] to avoid warnings about unused variables
// and functions. Earlier versions of gcc and clang supported [[gnu::unused]]
// as a non-standard annotation with similar effect.
#define UNUSED_NAME [[maybe_unused]]
#elif defined __GNUC__
#define UNUSED_NAME [[gnu::unused]]
#else // [[maybe_unused]] or [[gnu::unused]] availability
// In any other case I just omit any annotation and if I get warnings about
// unused things then so be it.
#define UNUSED_NAME
#endif // annotation for unused things
#endif // UNUSED_NAME

#ifndef INLINE_VAR
#ifdef __cpp_inline_variables
#define INLINE_VAR inline
#else // inline variables
#define INLINE_VAR UNUSED_NAME static
#endif // inline variables
#endif // INLINE_VAR


extern float128_t f128_NaN;         // a NaN
extern float128_t f128_0;           // 0.0_Q . v;
extern float128_t f128_half;        // 0.5_Q . v;
extern float128_t f128_mhalf;       // (-0.5_Q) . v;
extern float128_t f128_1;           // 1.0_Q . v;
extern float128_t f128_10_16;       // 1.0e16_Q . v;
extern float128_t f128_10_17;       // 1.0e17_Q . v;
extern float128_t f128_10_18;       // 1.0e18_Q . v;
extern float128_t f128_10_19;       // 1.0e19_Q . v;
extern float128_t f128_scale;       // {fpOrder(0x0080000000000000ULL, 0x4038000000000000ULL)};
extern float128_t f128_N1;          // {fpOrder(0, 0x4fff000000000000ULL)}; // 2^4096

extern float128_t f128_epsilon;
extern float128_t f128_half_epsilon;
extern float128_t f128_max;
extern float128_t f128_negmax;
extern float128_t f128_min;
extern float128_t f128_negmin;
extern float128_t f128_normmin;
extern float128_t f128_negnormmin;

inline bool f128_zerop(const float128_t p)
{   return ((p.v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
           (p.v[LOPART] == 0);
}

inline bool f128_infinitep(const float128_t p)
{   return (((p.v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
           ((p.v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
           (p.v[LOPART] == 0);
}

inline bool f128_finite(const float128_t p)
{   return (((p.v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}

inline void f128_make_infinite(float128_t *p)
{   p->v[HIPART] |= UINT64_C(0x7fff000000000000);
    p->v[HIPART] &= UINT64_C(0xffff000000000000);
    p->v[LOPART] = 0;
}

inline void f128_make_zero(float128_t *p)
{   p->v[HIPART] &= UINT64_C(0x8000000000000000);
    p->v[LOPART] = 0;
}

// Here I do not count 0.0 (or -0.0) as sub-normal.

inline bool f128_subnorm(const float128_t p)
{   return (((p.v[HIPART] >> 48) & 0x7fff) == 0) &&
           (((p.v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
            (p.v[LOPART] != 0));
}

inline bool f128_nanp(const float128_t p)
{   return (((p.v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
           (((p.v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
            (p.v[LOPART] != 0));
}

inline bool f128_negative(const float128_t x)
{   if (f128_nanp(x)) return false;
    return (static_cast<int64_t>(x.v[HIPART])) < 0;
}

inline int f128_exponent(const float128_t p)
{   return ((p.v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}

inline void f128_set_exponent(float128_t *p, int n)
{   p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                   ((static_cast<uint64_t>(n) + 0x3fff) << 48);
}

inline void f128_mantissa(const float128_t p, uint64_t& hi, uint64_t& lo)
{   hi = p.v[HIPART] & 0x0000ffffffffffffULL;
    if ((p.v[HIPART] & 0x7fff000000000000ULL) != 0)
                 hi |= 0x0001000000000000ULL;  // hidden bit
    lo = p.v[LOPART];
}

inline void f128_negate(float128_t *x)
{   x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}

inline float128_t f128_minus(float128_t x)
{   x.v[HIPART] ^= UINT64_C(0x8000000000000000);
    return x;
}

inline bool floating_edge_case128(float128_t r)
{   return f128_infinitep(r) || f128_nanp(r);
}

extern int float128_to_binary(const float128_t d, int64_t &mhi, uint64_t &mlo);
extern intptr_t float128_to_5_digits(float128_t d,
                                     int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0);

struct float256_t
{
#ifdef LITTLEENDIAN
    float128_t lo;
    float128_t hi;
#else
    float128_t hi;
    float128_t lo;
#endif
};

inline void f128_to_f256M(const float128_t a, float256_t *b)
{   b->hi = a;
    b->lo = f128_0;
}

extern void f256M_add(
    const float256_t *x, const float256_t *y, float256_t *z);

extern void f256M_mul(
    const float256_t *x, const float256_t *y, float256_t *z);

extern void f256M_div(
    const float256_t *x, const float256_t *y, float256_t *z);

extern void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);

// These print 128-bit floats in the various standard styles, returning the
// number of characters used. The "sprint" versions put their result in
// a buffer, while "print" goes to stdout.

extern int f128_sprint_E(char *s, int width, int precision, float128_t p);
extern int f128_sprint_F(char *s, int width, int precision, float128_t p);
extern int f128_sprint_G(char *s, int width, int precision, float128_t p);

extern void f128_print(float128_t p);
extern int f128_print_E(int width, int precision, float128_t p);
extern int f128_print_F(int width, int precision, float128_t p);
extern int f128_print_G(int width, int precision, float128_t p);

// By making the code that generated a QuadFloat from a string of
// characters "constexpr" I can move all costs associated with use
// of QuadFloat literals to compile-time. At least with a sufficiently
// good compiler implementing sufficiently recent C++ features.

inline constexpr uint64_t f160_leftshift(uint64_t m[5], uint64_t carry, int bits=1)
{   for (int i=0; i<5; i++)
    {   uint64_t w = (m[i]<<bits) + carry;
        m[i] = w & 0xffffffffU;
        carry = w >> 32;
    }
    return carry;
}

inline constexpr uint64_t f160_rightshift(uint64_t m[5], uint64_t carry, int bits=1)
{   for (int i=4; i>=0; i--)
    {   uint64_t w = m[i];
        m[i] = (w>>bits) + (carry<<(32-bits));
        carry = w & ((1U<<bits) - 1);
    }
    return carry;
}

// I want constexpr versions of these functions here, and so even though
// I have them defined elsewhere I will provide versions in this file
// (and with slightly different names).

inline constexpr int f160_nlz(uint64_t x)
{   int n = 0;
    if (x <= 0x00000000FFFFFFFFU)
    {   n = n +32;
        x = x <<32;
    }
    if (x <= 0x0000FFFFFFFFFFFFU)
    {   n = n +16;
        x = x <<16;
    }
    if (x <= 0x00FFFFFFFFFFFFFFU)
    {   n = n + 8;
        x = x << 8;
    }
    if (x <= 0x0FFFFFFFFFFFFFFFU)
    {   n = n + 4;
        x = x << 4;
    }
    if (x <= 0x3FFFFFFFFFFFFFFFU)
    {   n = n + 2;
        x = x << 2;
    }
    if (x <= 0x7FFFFFFFFFFFFFFFU)
    {   n = n + 1;
    }
    return n;
}

inline constexpr int f160_z(unsigned int n)
{   if (n==0) return 64;
    uint64_t v=0;
    int r = -1;
    for (int k=0; k<64; k++)
    {   v = 1ULL<<k;
        if (v%67 == n) r = k;
    }
    return r;
};

constexpr static int8_t f160_ntzTable[67] =
{   f160_z( 0), f160_z( 1), f160_z( 2), f160_z( 3), f160_z( 4),
    f160_z( 5), f160_z( 6), f160_z( 7), f160_z( 8), f160_z( 9),
    f160_z(10), f160_z(11), f160_z(12), f160_z(13), f160_z(14),
    f160_z(15), f160_z(16), f160_z(17), f160_z(18), f160_z(19),
    f160_z(20), f160_z(21), f160_z(22), f160_z(23), f160_z(24),
    f160_z(25), f160_z(26), f160_z(27), f160_z(28), f160_z(29),
    f160_z(30), f160_z(31), f160_z(32), f160_z(33), f160_z(34),
    f160_z(35), f160_z(36), f160_z(37), f160_z(38), f160_z(39),
    f160_z(40), f160_z(41), f160_z(42), f160_z(43), f160_z(44),
    f160_z(45), f160_z(46), f160_z(47), f160_z(48), f160_z(49),
    f160_z(50), f160_z(51), f160_z(52), f160_z(53), f160_z(54),
    f160_z(55), f160_z(56), f160_z(57), f160_z(58), f160_z(59),
    f160_z(60), f160_z(61), f160_z(62), f160_z(63), f160_z(64),
    f160_z(65), f160_z(66)
};

inline constexpr int f160_ntz(uint64_t n)
{   return f160_ntzTable[(n & -n) % 67];
}
inline constexpr void f160_mul(uint64_t m[5], uint64_t n, int& bx)
{   uint64_t carry = 0;
    for (int i=0; i<5; i++)
    {   uint64_t w = n*m[i] + carry;
        m[i] = w & 0xffffffffU;
        carry = w >> 32;
    }
    if (carry != 0)
    {   int carryBits = 64 - f160_nlz(carry);
        f160_rightshift(m, carry, carryBits);
        bx += carryBits;
    }
}

inline constexpr void f160_div(uint64_t m[5], uint64_t n, int& bx)
{   uint64_t carry = 0;
    for (int i=4; i>=0; i--)
    {   uint64_t w = m[i] + (carry<<32);
        m[i] = w/n;
        carry = w%n;
    }
    carry = (carry<<32)/n;
    if (m[4] == 0)
    {   for (int i=3; i>=0; i--) m[i+1] = m[1];
        m[0] = carry;
        carry = 0;
    }
    int carryBits = f160_nlz(m[4]) - 32;
    f160_leftshift(m, carry>>(32-carryBits), carryBits);
    bx -= carryBits;
}

#ifdef LITTLEENDIAN
constexpr int f128_low = 0, f128_high = 1;
#else // LITTLEENDIAN
constexpr int f128_low = 1, f128_high = 0;
#endif // LITTLEENDIAN

inline constexpr float128_t atof128(const char* s)
{
// I will collect the mantissa in a 5-word array, storing just
// 32 bits in each word. That is 160 bits and is going to give me
// 48 guard bits while I calculate the floating point representation.
// With that many guard bits I will hope not to have too much pain with
// overall accuracy of conversion once the result is packed in 128 bits.
// Ha ha ha - if the user were to write a decimal with 48+ significant
// decimal digits (way more than are needed to get a QuadFloat accurate)
// then the 160-bit integer here could overflow and that would lead to
// a grossly incorrect result! So I will want to avoid collecting digits
// beyond say 47 - however I will need to count such skipped over digits
// in case the input is 50 digits followed by ".0".
    uint64_t m[5] = {0,0,0,0,0};
    float128_t r = {0,0};
    int x = 0;    // decimal exponent
    int digits = 0, skipped = 0;
    bool isZero = true, dotSeen = false, sign = false;
    int c = *s++;
    if (c == '-')
    {   sign = true;
        c = *s++;
    }
// Here I do repeated multiplication by 10 and just discard any bits that
// fall off to the right. This is rather crude! Two things that would be
// better would be (a) multiuplying by maybe 100000000 as much as possible
// to cope with larger exponents with fewer multiplications and (b) rounding
// after each multipication. 
    while (c>='0' && c<='9')
    {   if (c != '0') isZero = false;
        if (!isZero) digits++;
        if (digits < 47)
        {   unsigned int carry = c - '0';
            for (int i=0; i<5; i++)
            {   uint64_t d = 10*m[i] + carry;
                carry = d>>32;
                m[i] = d & 0xffffffffU;
            }
        }
        else skipped++;
        if (dotSeen) x--;
        c = *s++;
        if (c == '.')
        {   c = *s++;
            dotSeen = true;
        }
    }
// If the NNN.NNN part does not have any non-zero digits then
// whatever exponent might follow the result is going to be zero, so
// I will return it now. However in a spirit of enthusiasm I will
// allow the zero to be a signed one.
    if (isZero)
    {   r.v[f128_high] = r.v[f128_low] = 0;
        if (sign) r.v[f128_high] |= 0x8000000000000000LLU;
        return r;
    }
    int xx = skipped;    // explicitly specified decimal exponent
                         // I allow all sorts of silly characters!
    if (c == 'e' || c == 'E' || c == 'd' || c == 'D' ||
        c == 'l' || c == 'l' || c == 's' || c == 'S' ||
        c == 'f' || c == 'F')
    {   c = *s++;
        if (c == '+') c = *s++;
        bool xsign = false;
        if (c == '-')
        {   xsign = true;
            c = *s++;
        }
        while (c>='0' && c<='9')
        {   xx = 10*xx + c - '0';
            c = *s++;
        }
        if (xsign) xx = -xx;
    }
    x += xx;
    int bx = 160;     // binary exponent
// Now normalise the value - first get the top word non-zero.
    while (m[4] == 0)
    {   for (int i=3; i>=0; i--) m[i+1] = m[i];
        m[0] = 0;
        bx -= 32;
    }
// Now shift within the words to get the top bit non-zero.
    int carryBits = f160_nlz(m[4]) - 32;
    f160_leftshift(m, 0, carryBits);
    bx -= carryBits;

//    while ((m[4] & 0x80000000U) == 0)
//    {   f160_leftshift(m, 0);
//        bx--;
//    }

// Now I have in effect a 160-bit floating point value for an integer
// made from all the digits of the input.
// I need to multiply by 10^x (or if x is negative I divide). I do so
// in a naive manner - ie repeated multiplication or division by the
// constant 10. The largest 120-bit float is almost 10^5000 so in the
// worst case I may be performing almost 5000 multiplications here, and
// each can corrupt a low bit of the value. I feel that the result means
// I will not want to rely on say the bottom 16 bits of my result. Well to
// save a little time and also improve accuracy I scale in chunks of 10^9
// while I can, so actually the worst number of multiplications is just
// under 560 and maybe I will only lose 10 bits.
    while (x > 8)
    {   f160_mul(m, 1000000000, bx);
        x -= 9;
    }
    while (x > 0)
    {   f160_mul(m, 10, bx);
        x--;
    }
// Similarly for division I am not bothering to round the quotient.
    while (x < -8)
    {   f160_div(m, 1000000000, bx);
        x += 9;
    }
    while (x < 0)
    {   f160_div(m, 10, bx);
        x++;
    }
    bx += 0x3ffe;
// At this stage I have an extra-precision value which I should
// round to the nearest proper result.
    if ((m[1] & 0x7fff) >= 0x4000)
    {   uint64_t carry = 0x8000;
        for (int i=1; i<5; i++)
        {   uint64_t w = m[i] + carry;
            m[i] = w & 0xffffffffU;
            carry = w >> 32;
        }
        if (carry != 0)
        {   f160_rightshift(m, 1);
            bx++;
        }
    }
    for (int i=0; i<5; i++) m[i] &= 0xffffffffU;  // ensure clean!
    m[4] &= 0x7fffffffU;   // lose the hidden bit
    uint64_t hh = (m[4]<<32) | m[3];
    uint64_t ll = (m[2]<<32) | m[1];
// Shift the mantissa right 15 bits to put it where it needs to be.
    ll = (ll>>15) | (hh<<49);
    hh = hh>>15;
// Insert exponent
    if (bx >= 0x7fff)   // Overflow to infinity
    {   bx = 0x7fff;
        hh = ll = 0;
    }
    if (bx <= 0)
    {   hh |= 0x0001000000000000ULL; // restore bit that will not be hidden
        int sh = 1-bx;
        bx = 0;                      // to leave a subnormal number or zero.
        if (sh >= 128) hh = ll = 0;
        else
        {   if (sh >= 64)
            {   ll = hh;
                hh = 0;
                sh -= 64;
            }
            if (sh != 0)
            {   ll = (hh<<(64-sh)) | (ll >> sh);
                hh >>= sh;
            }
        }
    }
    hh |= static_cast<uint64_t>(bx & 0x7fffU)<<48;
    if (sign) hh |= 0x8000000000000000LLU;
    r.v[f128_high] = hh;
    r.v[f128_low] = ll;
    return r;
}

// I do not intend to support NaN, infinity values or sub-normalised
// values in code that uses QuadFloat. Well to be more precise, support
// for them is whatever follows from the underpinning float128_t type. 

class QuadFloat
{
public:
// Many people would believe I should make the data field here
// private rather than public, and provide an access function in
// case of need.

    float128_t v;

    constexpr QuadFloat():v()               // default constructor
    {   v = f128_0;
    }
    constexpr QuadFloat(float128_t n):v()   // import from a float128_t
    {   v = n;
    }
    constexpr QuadFloat(const char* s):v()  // value as from a text string
    {   v = atof128(s);
    }
    constexpr QuadFloat(const QuadFloat& rhs):v()
    {   v = rhs.v;
    }
    QuadFloat(int n):v()
    {   v = i32_to_f128(n);
    }
    QuadFloat(int64_t n):v()
    {   v = i64_to_f128(n);
    }
    QuadFloat(float64_t n):v()
    {   v = f64_to_f128(n);
    }
    QuadFloat(double d):v()
    {   float64_t n;
        std::memcpy(reinterpret_cast<char*>(&n),
                    reinterpret_cast<char*>(&d),
                    sizeof(double));
        v = f64_to_f128(n);
    }
    constexpr QuadFloat(QuadFloat&& rhs):v()
    {   v = rhs.v;
    }

    operator double()
    {   float64_t r = f128_to_f64(v);
// The following line is probably the most genuine use of bit_cast I have
// written anywhere!
        return bit_cast<double>(r.v);
    }

    operator int64_t()
    {   return f128_to_i64(v, softfloat_round_minMag, false);
    }

    friend std::ostream& operator<<(std::ostream& o, const QuadFloat& d)
    {   bool hex = (o.flags() & std::ios::hex) != 0;
        if (hex)
        {   return o << std::setw(16) << std::setfill('0') << d.v.v[1]
                 << "'" << std::setw(16) << std::setfill('0') << d.v.v[0];
        }
        else
        {   char buffer[64];
            f128_sprint_G(buffer, 0, 36, d.v);
            return o << buffer;
        }
    }

    constexpr QuadFloat operator=(const QuadFloat& rhs)
    {   v = rhs.v;
        return *this;
    }
    constexpr QuadFloat operator=(QuadFloat&& rhs)
    {   v = rhs.v;
        return *this;
    }

    bool operator==(const QuadFloat& rhs) const;
    bool operator!=(const QuadFloat& rhs) const;
    bool operator<(const QuadFloat& rhs) const;
    bool operator<=(const QuadFloat& rhs) const;
    bool operator>(const QuadFloat& rhs) const;
    bool operator>=(const QuadFloat& rhs) const;

    constexpr QuadFloat operator+() const;
    constexpr QuadFloat operator-() const;

    QuadFloat operator+(const QuadFloat& rhs) const;
    QuadFloat operator-(const QuadFloat& rhs) const;
    QuadFloat operator*(const QuadFloat& rhs) const;
    QuadFloat operator/(const QuadFloat& rhs) const;

    QuadFloat operator+=(const QuadFloat& rhs);
    QuadFloat operator-=(const QuadFloat& rhs);
    QuadFloat operator*=(const QuadFloat& rhs);
    QuadFloat operator/=(const QuadFloat& rhs);

    bool isinf()
    {   return f128_infinitep(v);
    }

    bool isfinite()
    {   return f128_finite(v);
    }

    bool isnan()
    {   return f128_nanp(v);
    }

    bool issubnorm()
    {   return f128_subnorm(v);
    }

    bool isnegative()
    {   return f128_negative(v);
    }

    constexpr bool sign();
    constexpr int exponent();
    constexpr QuadFloat set_exponent(int64_t n);
    constexpr QuadFloat mantissa();
};

inline bool QuadFloat::operator==(const QuadFloat& rhs) const
{   return f128_eq(v, rhs.v);
}

inline bool QuadFloat::operator!=(const QuadFloat& rhs) const
{   return !f128_eq(v, rhs.v);
}

inline bool QuadFloat::operator<(const QuadFloat& rhs) const
{   return f128_lt(v, rhs.v);
}

inline bool QuadFloat::operator<=(const QuadFloat& rhs) const
{   return f128_le(v, rhs.v);
}

inline bool QuadFloat::operator>(const QuadFloat& rhs) const
{   return f128_lt(rhs.v, v);
}

inline bool QuadFloat::operator>=(const QuadFloat& rhs) const
{   return f128_le(rhs.v, v);
}

constexpr inline QuadFloat QuadFloat::operator+() const
{   return *this;
}

constexpr inline QuadFloat QuadFloat::operator-() const
{   float128_t r{{0,0}};
    r.v[f128_high] = v.v[f128_high] ^ 0x8000000000000000ULL;
    r.v[f128_low] = v.v[f128_low];
    return QuadFloat(r);
}

inline QuadFloat QuadFloat::operator+(const QuadFloat& rhs) const
{   return QuadFloat(f128_add(v, rhs.v));
}

inline QuadFloat QuadFloat::operator-(const QuadFloat& rhs) const
{   return QuadFloat(f128_sub(v, rhs.v));
}

inline QuadFloat QuadFloat::operator*(const QuadFloat& rhs) const
{   return QuadFloat(f128_mul(v, rhs.v));
}

inline QuadFloat QuadFloat::operator/(const QuadFloat& rhs) const
{   return QuadFloat(f128_div(v, rhs.v));
}

inline QuadFloat QuadFloat::operator+=(const QuadFloat& rhs)
{   v = f128_add(v, rhs.v);
    return *this;
}

inline QuadFloat QuadFloat::operator-=(const QuadFloat& rhs)
{   v = f128_sub(v, rhs.v);
    return *this;
}

inline QuadFloat QuadFloat::operator*=(const QuadFloat& rhs)
{   v = f128_mul(v, rhs.v);
    return *this;
}

inline QuadFloat QuadFloat::operator/=(const QuadFloat& rhs)
{   v = f128_div(v, rhs.v);
    return *this;
}

inline constexpr bool QuadFloat::sign()
{
#ifdef LITTLEENDIAN
    uint64_t top = v.v[1];
#else // LITTLEENDIAN
    uint64_t top = v.v[0];
#endif // LITTLEENDIAN
    return (top & 0x8000000000000000U) != 0;
}

inline constexpr int QuadFloat::exponent()
{
#ifdef LITTLEENDIAN
    uint64_t top = v.v[1];
#else // LITTLEENDIAN
    uint64_t top = v.v[0];
#endif // LITTLEENDIAN
    return ((top>>48) & 0x7fff) - 0x3fff;
}

inline constexpr QuadFloat QuadFloat::set_exponent(int64_t n)
{   float128_t r = v;
#ifdef LITTLEENDIAN
    r.v[1] = (r.v[1] & 0x8000ffffffffffffU) | (((n + 0x3fff) & 0x7fff)<<48);
#else // LITTLEENDIAN
    r.v[0] = (r.v[0] & 0x8000ffffffffffffU) | (((n + 0x3fff) & 0x7fff)<<48);
#endif // LITTLEENDIAN
    return r;
}

inline constexpr QuadFloat QuadFloat::mantissa()
{   float128_t r = v;
#ifdef LITTLEENDIAN
    r.v[1] = (r.v[1] & 0x8000ffffffffffffU) | 0x3fff000000000000U;
#else // LITTLEENDIAN
    r.v[0] = (r.v[0] & 0x8000ffffffffffffU) | 0x3fff000000000000U;
#endif // LITTLEENDIAN
    return QuadFloat(r);
}

inline constexpr QuadFloat operator ""_Q (const char *s)
{   return QuadFloat(s);
}

#define HAVE_Q_LITERALS 1

inline constexpr unsigned hexFromChar(int c)
{   switch (c)
    {
    default:  return -1;
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'a': return 10;
    case 'b': return 11;
    case 'c': return 12;
    case 'd': return 13;
    case 'e': return 14;
    case 'f': return 15;
    case 'A': return 10;
    case 'B': return 11;
    case 'C': return 12;
    case 'D': return 13;
    case 'E': return 14;
    case 'F': return 15;
    }
}

inline constexpr QuadFloat operator ""_QX (const char* s)
{   uint64_t high=0, low=0, w = 0;
    s += 2; // skip over the "0x" prefix.
    int c = *s++, d=0;
    int n = 0;
    while ((d = hexFromChar(c)) >= 0)
    {   w = 16*w + d;
        c = *s++;
        if (c == '\'') c = *s++;
        if (++n == 16) break;
    }
    high = w;
    w = 0;
    n = 0;
    while ((d = hexFromChar(c)) >= 0)
    {   w = 16*w + d;
        c = *s++;
        if (c == '\'') c = *s++;
        if (++n == 16) break;
    }
    low = w;
    float128_t r = {{0,0}};    
#ifdef LITTLEENDIAN
    r.v[0] = low;
    r.v[1] = high;
#else // LITTLEENDIAN
    r.v[0] = high;
    r.v[1] = low;
#endif // LITTLEENDIAN
    return QuadFloat(r);
}

INLINE_VAR float128_t f128_NaN          = {fpOrder(0, 0x7fff800000000000LL)}; 
INLINE_VAR float128_t f128_0            = 0.0_Q . v;
INLINE_VAR float128_t f128_half         = 0.5_Q . v;
INLINE_VAR float128_t f128_mhalf        = (-0.5_Q) . v;
INLINE_VAR float128_t f128_1            = 1.0_Q . v;
INLINE_VAR float128_t f128_10_16        = 1.0e16_Q . v;
INLINE_VAR float128_t f128_10_17        = 1.0e17_Q . v;
INLINE_VAR float128_t f128_10_18        = 1.0e18_Q . v;
INLINE_VAR float128_t f128_10_19        = 1.0e19_Q . v;
INLINE_VAR float128_t f128_scale        = {fpOrder(0x0080000000000000ULL, 0x4038000000000000ULL)};
INLINE_VAR float128_t f128_N1           = {fpOrder(0, 0x4fff000000000000ULL)}; // 2^4096

INLINE_VAR float128_t f128_epsilon      = 1.925929944387235853055977942584927319e-34_Q . v;
INLINE_VAR float128_t f128_half_epsilon = 9.629649721936179265279889712924636593e-35_Q . v;
INLINE_VAR float128_t f128_max          = 1.18973149535723176508575932662800702e+4932_Q . v;
INLINE_VAR float128_t f128_negmax       = (-1.18973149535723176508575932662800702e+4932_Q) . v;
INLINE_VAR float128_t f128_min          = {fpOrder(1, 0)};
//                                        6.47517511943802511092443895822764655e-4966_Q . v;
INLINE_VAR float128_t f128_negmin       = {fpOrder(1, 0x8000000000000000ULL)};
//                                        (-6.47517511943802511092443895822764655e-4966_Q) . v;
INLINE_VAR float128_t f128_normmin      = 3.36210314311209350626267781732175260e-4932_Q . v; 
INLINE_VAR float128_t f128_negnormmin   = (-3.36210314311209350626267781732175260e-4932_Q) . v;

// Now some limited support for 256-bit floats, implemented as pairs
// of 128-bit numbers using the strategy sometimes known as double-double.
// But here it should be quad-quad.
// Infinities, NaNs and gradual underflow will NOT be well supported here
// so code that uses these numbers should take care!

extern void f256M_negate(const float256_t *x, float256_t *z);
extern void f256M_add(const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_mul(const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern void f256M_gt(const float256_t *x, float256_t *y);
extern void f256M_ge(const float256_t *x, float256_t *y);
extern void f256M_lt(const float256_t *x, float256_t *y);
extern void f256M_le(const float256_t *x, float256_t *y);

// I will want working precision even higher than 128-bits. I will
// arrange that using pairs of 128-bit floats such that the value
// I am representing is their sum. The code I have here will not be
// robust against issues of denormailised numbers, infinities or
// NaNs, and so its use needs to take care to avoid such cases.
//
// I am following the scheme from T J Dekker, Numer Math 18 224-242 (1971).

extern float256_t
  f256_5, //      = fp256Order(fpOrder(0,0), fpOrder(0, 0x4001400000000000ULL)),
  f256_10, //     = fp256Order(fpOrder(0,0), fpOrder(0, 0x4002400000000000ULL)),
  f256_r5, //     = fp256Order(fpOrder(0x00000000000000000ULL, 0x4001400000000000ULL),
           //                  fpOrder(0x00000000000000000ULL, 0x0000000000000000ULL)),
  f256_r10, //    = fp256Order(fpOrder(0x9999999999999999aULL, 0xbf8a999999999999ULL),
            //                 fpOrder(0x9999999999999999aULL, 0x3ffc999999999999ULL)),
  f256_10_16; //  = fp256Order(fpOrder(0,0), fpOrder(0, 0x40341c37937e0800ULL));

extern float256_t ato256(const char* s);

class OctFloat
{
public:
// Many people would believe I should make the data field here
// private rather than public, and provide an access function in
// case of need.

    float256_t v;

    constexpr OctFloat():v()               // default constructor
    {   v.hi = v.lo = f128_0;
    }
    constexpr OctFloat(float128_t n):v()   // import from a float128_t
    {   v.hi = n;
        v.lo = f128_0;
    }
    constexpr OctFloat(float256_t n):v()   // import from a float256_t
    {   v.hi = n.hi;
        v.lo = n.lo;
    }
    OctFloat(const char* s):v()            // value as from a text string
    {   v = ato256(s);
    }
    constexpr OctFloat(const QuadFloat hi):v()
    {   v.hi = hi.v;
        v.lo = f128_0;
    }
    constexpr OctFloat(const QuadFloat hi, const QuadFloat lo):v()
    {   v.hi = hi.v;
        v.lo = lo.v;
    }
    constexpr OctFloat(const OctFloat& rhs):v()
    {   v = rhs.v;
    }
    OctFloat(int n):v()
    {   v.hi = i32_to_f128(n);
        v.lo = f128_0;
    }
    OctFloat(int64_t n):v()
    {   v.hi = i64_to_f128(n);
        v.lo = f128_0;
    }
    OctFloat(float64_t n):v()
    {   v.hi = f64_to_f128(n);
        v.lo = f128_0;
    }
    OctFloat(double d):v()
    {   float64_t n;
        std::memcpy(reinterpret_cast<char*>(&n),
                    reinterpret_cast<char*>(&d),
                    sizeof(double));
        v.hi = f64_to_f128(n);
        v.lo = f128_0;
    }
    constexpr OctFloat(OctFloat&& rhs):v()
    {   v = rhs.v;
    }

    friend std::ostream& operator<<(std::ostream& o, const OctFloat& d)
    {   return o << QuadFloat(d.v.hi) << "_:_" << QuadFloat(d.v.lo);
    }

    constexpr OctFloat operator=(const OctFloat& rhs)
    {   v = rhs.v;
        return *this;
    }
    constexpr OctFloat operator=(OctFloat&& rhs)
    {   v = rhs.v;
        return *this;
    }

// Beware at present - these overloads only support operations with the
// OctFloat argument as the left operand! I could set up some templates
// etc to allow for things the other way round, but given that OctFloats
// are ONLY intended for internal use in support of bettter precision in
// some QuadFloat operations I am not going to add that extra complication.

    bool operator==(const OctFloat& rhs) const;
    bool operator!=(const OctFloat& rhs) const;
    bool operator<(const OctFloat& rhs) const;
    bool operator<=(const OctFloat& rhs) const;
    bool operator>(const OctFloat& rhs) const;
    bool operator>=(const OctFloat& rhs) const;

    OctFloat operator-() const;

    OctFloat operator+(const OctFloat& rhs) const;
    OctFloat operator-(const OctFloat& rhs) const;
    OctFloat operator*(const OctFloat& rhs) const;
    OctFloat operator/(const OctFloat& rhs) const;

};


// I will allow oct-float literals in the form 1.234e56_QQ but NOTE
// WELL that I will not expect all the bits in the value read to be
// fully accurate. The results will be best when the values are within
// reasonable reach of 1.0, and infinities, subnormal numbers etc may
// not be well supported. The values will have around 227 bits which
// gives a little over 68 decimals. The literals here will not be
// assembled at compile time and so it will probably be best to
// set up all constants using static initialization so that the
// conversion from decimal to binary is performed at program startup
// time. Another option will be to run a jiffy program once that
// sets up the constants that way and then renders the binary values
// in hex, since I will be able to provide a compile-time translation
// from hex-formatted input of the form 0xNNNN...NNN_QQX into the
// required data. For this there will be exactly 64 hex digits that
// will denote the bit pattern in a most-significant-digit-first layout.
// So the main thing that the parsing will need to do is to allow for
// byte ordering on the target machine.
//
// Well probably the best way to put OctFloat literal values in source code
// will be along the lines of OctFloat(1.23_Q, 4.56e-36_Q) leveraging the
// fact that QuadDoubles can be read in competently. Or to input then
// as hex values with an 0x prefix and _QQX suffix and exactly 64 hex
// digits between.


inline OctFloat oct_10(10);

inline OctFloat operator ""_QQ (const char* s)
{   return OctFloat(ato256(s));
}

// If the user specified other than exactly 64 hex digits with _QQX the
// result will be something that is as defined by this code but that
// ought not to be relied upon!

constexpr inline OctFloat operator ""_QQX (const char* s)
{   s += 2; // skip over the "0x" prefix.
    if (*s == '\'') s++;
    uint64_t data[4] = {0, 0, 0, 0};
    for (int i=0; i<4; i++)
    {   uint64_t w = 0;
        for (int j=0; j<16; j++)
        {   int c = *s++, d=0;
            if ((d = hexFromChar(c)) < 0)
            {   s--;
                break;
            }
            if (*s == '\'') s++;
            w = 16*w + d;
        }
        data[i] = w;
    }
    float256_t r = {{0, 0}, {0,0}};
#ifdef LITTLEENDIAN
    const int low = 0, high = 1;
#else // LITTLEENDIAN
    const int low = 1, high = 0;
#endif // LITTLEENDIAN
    r.hi.v[high] = data[0];
    r.hi.v[low] = data[1];
    r.lo.v[high] = data[2];
    r.lo.v[low] = data[3];
    return OctFloat(r);
}

#endif // header_float128_t

// end of float128_t.h
