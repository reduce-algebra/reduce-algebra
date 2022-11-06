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


// The initial version of this file defines many "Inline" functions. When
// I get things feeling really rather more stafe I intend to move most
// of the definitions into a new file float128_t.cpp, leaving just
// declarations here. At present it is rather stupid!
  
#ifndef header_float128_t
#define header_float128_t

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
// format.

// Note that input is FRAGILE. For instance the hex input must have
// 32 hex digits (the separator "'" may be used to help make the format
// clearer) and they must be proper hex digits. For decimal style input
// the format should be used with caution and overflow, underflow and the
// like avoided. This is intended for my use within just this project
// rather than being robust code proper for general use.

// This builds on top of the softfloat library from John R Hauser, a copy
// of which can be found elsewhere within the CSL/Reduce source tree.

extern "C" {
#include "softfloat.h"
}

inline int  f128_exponent(const float128_t p);
inline void f128_set_exponent(float128_t *p, int n);
extern void f128_ldexp(float128_t *p, int n);
extern void f128_frexp(float128_t p, float128_t *r, int *x);
inline bool f128_infinitep(const float128_t p);
inline bool f128_finite(const float128_t p);
inline bool f128_nanp(const float128_t x);
inline bool f128_subnorm(const float128_t x);
inline bool f128_negative(const float128_t x);
inline void f128_negate(float128_t *x);
extern void f128_split(const float128_t *x, float128_t *yhi, float128_t *ylo);

#ifdef LITTLEENDIAN
#define HIPART 1
#define LOPART 0
#else
#define HIPART 0
#define LOPART 1
#endif

extern float128_t
    f128_0,      // 0.0L0
    f128_half,   // 0.5L0
    f128_mhalf,  // -0.5L0
    f128_1,      // 1.0L0
    f128_10,     // 10.0L0
    f128_10_17,  // 1.0L17
    f128_10_18,  // 1.0L18
    f128_r10,    // 0.1L0
    f128_scale,  // 2.0^58+1.0
    f128_N1;     // 2.0L0^4096

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

inline void f128_negate(float128_t *x)
{   x->v[HIPART] ^= UINT64_C(0x8000000000000000);
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

extern float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;

// These print 128-bit floats in the various standard styles, returning the
// number of characters used. The "sprint" versions put their result in
// a buffer, while "print" goes to stdout.

extern int f128_sprint_E(char *s, int width, int precision,
                         float128_t p);
extern int f128_sprint_F(char *s, int width, int precision,
                         float128_t p);
extern int f128_sprint_G(char *s, int width, int precision,
                         float128_t p);
extern int f128_print_E(int width, int precision, float128_t p);
extern int f128_print_F(int width, int precision, float128_t p);
extern int f128_print_G(int width, int precision, float128_t p);

extern float128_t atof128(const char *s);

// By making the code that generated a QuadFloat from a string of
// characters "constexpr" I can (with luck) move all costs associated
// with use of QuadFloat literals to compile-time.

inline constexpr float128_t ato128(const char* s)
{
// I will collect the mantissa in a 5-word array, storing just
// 32 bits in each word. That is 160 bits and is going to give me
// 48 guard bits while I calculate the floating point representation.
// With that many guard bits I will hope not to have too much pain with
// overall accuracy of conversion once the result is packed in 128 bits.
    uint64_t m[5];
    float128_t r;
    for (int i=0; i<5; i++) m[i] = 0;
    int x = 0;    // decimal exponent
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
        unsigned int carry = c - '0';
        for (int i=0; i<5; i++)
        {   uint64_t d = 10*m[i] + carry;
            carry = d>>32;
            m[i] = d & 0xffffffffU;
        }
        if (dotSeen) x--;
        c = *s++;
        if (c == '.')
        {   c = *s++;
            dotSeen = true;
        }
    }
    int xx = 0;    // explicitly specified decimal exponent
    if (c == 'e')
    {   c = *s++;
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
    if (isZero)
    {   r.v[0] = r.v[1] = 0;
        return r;
    }
    int bx = 160;     // binary exponent
// Now normalise the value - first get the top word non-zero.
    while (m[4] == 0)
    {   m[4] = m[3];
        m[3] = m[2];
        m[2] = m[1];
        m[1] = m[0];
        m[0] = 0;
        bx -= 32;
    }
// Now shift within the words to get the top bit non-zero.
    uint64_t topWord = m[4]; // this is nonzero
    int shift = 0;
    while ((topWord & 0x80000000U) == 0)
    {   topWord = topWord<<1;
        shift++;
    }
    bx -= shift;
    uint64_t carry = 0;
    for (int i=0; i<5; i++)
    {   uint64_t w = (m[i]<<shift) + carry;
        m[i] = w & 0xffffffffU;
        carry = w >> 32;
    }
// I need to multiply by 10^x (or if x is negative I divide).
    while (x > 0)
    {   uint64_t carry = 0;
        for (int i=0; i<5; i++)
        {   uint64_t w = 10*m[i] + carry;
            m[i] = w & 0xffffffffU;
            carry = w >> 32;
        }
        while (carry != 0)
        {   uint64_t bit = carry & 1;
            for (int i=4; i>=0; i--)
            {   uint64_t w = m[i];
                m[i] = (w>>1) | (bit<<31);
                bit = w & 1;
            }
            carry >>= 1;
            bx++;
        }
        x--;
    }
// Similarly for division I am not bothering to round the quotient.
    while (x < 0)
    {   uint64_t carry = 0;
        for (int i=4; i>=0; i--)
        {   uint64_t w = m[i] + (carry<<32);
            m[i] = w/10;
            carry = w%10;
        }
        carry = (carry<<32)/10;
        while ((m[4]&0x80000000U) == 0)
        {   uint64_t bit = carry>>31;
            carry = carry<<1;
            for (int i=0; i<5; i++)
            {   uint64_t w = m[i];
                m[i] = (w<<1) + bit;
                bit = w >> 31;
            }   
            bx--;
        }
        x++;
    }
#ifdef LITTLEENDIAN
    const int low = 0, high = 1;
#else // LITTLEENDIAN
    const int low = 1, high = 0;
#endif // LITTLEENDIAN
    bx += 0x3ffe;
// At this stage I have an extra-precision value which I should
// round to the nearest proper result.
    if (((m[1] & 0x7fff) > 0x4000) ||
        (((m[1] & 0x7fff) == 0x4000) && ((m[1] & 0x8000) != 0)))
    {   m[1] += 0x8000;
        if (m[1] >= 0x100000000u)
        {   m[1] &= 0xffffffffu;
            m[2] += 1;
            if (m[2] >= 0x100000000u)
            {   m[2] &= 0xffffffffu;
                m[3] += 1;
                if (m[3] >= 0x100000000u)
                {   m[3] &= 0xffffffffu;
                    m[4] += 1;
                    if (m[4] >= 0x100000000u)
                    {   bx++;
                        m[0] = (m[0]>>1) + ((m[1]&1)<<31);
                        m[1] = (m[1]>>1) + ((m[2]&1)<<31);
                        m[2] = (m[2]>>1) + ((m[3]&1)<<31);
                        m[3] = (m[3]>>1) + ((m[4]&1)<<31);
                        m[4] = m[4]>>1;
                    }
                }
            }
        }
    }
    r.v[high] = r.v[low] = 0;
    if (sign) r.v[high] |= 0x80000000;
    r.v[high] |= ((static_cast<uint64_t>(bx) & 0x7fffU) << 48);
    r.v[high] |= ((m[4] & 0x7fffffff) << 17) | (m[3] >> 15);
    r.v[low] = (m[3] << 49) | (m[2] << 17) | (m[1] >> 15);
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

    constexpr QuadFloat()                   // default constructor
    {   v.v[0] = v.v[1] = 0;
    }
    constexpr QuadFloat(float128_t n)       // import from a float128_t
    {   v = n;
    }
    constexpr QuadFloat(const char* s)      // value as from a text string
    {   v = ato128(s);
    }
    constexpr QuadFloat(const QuadFloat& rhs)
    {   v = rhs.v;
    }
    QuadFloat(int n)
    {   v = i32_to_f128(n);
    }
    QuadFloat(int64_t n)
    {   v = i64_to_f128(n);
    }
    QuadFloat(float64_t n)
    {   v = f64_to_f128(n);
    }
    QuadFloat(double d)
    {   float64_t n;
        std::memcpy(reinterpret_cast<char*>(&n),
                    reinterpret_cast<char*>(&d),
                    sizeof(double));
        v = f64_to_f128(n);
    }

    constexpr QuadFloat(QuadFloat&& rhs)
    {   v = rhs.v;
    }

    friend std::ostream& operator<<(std::ostream& o, const QuadFloat& d)
    {   std::ios_base::fmtflags save = o.flags();
        return o << std::hex
                 << std::setw(16) << std::setfill('0') << d.v.v[1] << "'"
                 << std::setw(16) << std::setfill('0') << d.v.v[0]
                 << std::setiosflags(save);
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

    QuadFloat operator-() const;

    QuadFloat operator+(const QuadFloat& rhs) const;
    QuadFloat operator-(const QuadFloat& rhs) const;
    QuadFloat operator*(const QuadFloat& rhs) const;
    QuadFloat operator/(const QuadFloat& rhs) const;

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

inline QuadFloat QuadFloat::operator-() const
{   float128_t zero = {0,0};
    return QuadFloat(f128_sub(zero, v));
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
{   uint64_t high, low, w = 0;
    s += 2; // skip over the "0x" prefix.
    int c = *s++, d;
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
    float128_t r;    
#ifdef LITTLEENDIAN
    r.v[0] = low;
    r.v[1] = high;
#else // LITTLEENDIAN
    r.v[0] = high;
    r.v[1] = low;
#endif // LITTLEENDIAN
    return QuadFloat(r);
}

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


extern float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;


#ifdef LITTLEENDIAN
#define fpOrder(a, b) {INT64_C(a), INT64_C(b)}
#define fp256Order(a, b) {a, b}
#else // LITTLEENDIAN
#define fpOrder(a, b) {INT64_C(b), INT64_C(a)}
#define fp256Order(a, b) {b, a}
#endif // LITTLEENDIAN

extern float256_t
  f256_5, //      = fp256Order(fpOrder(0,0), fpOrder(0, 0x4001400000000000)),
  f256_10, //     = fp256Order(fpOrder(0,0), fpOrder(0, 0x4002400000000000)),
  f256_r5, //     = fp256Order(fpOrder(0x999999999999999a, 0xbf8a999999999999),
           //                  fpOrder(0x999999999999999a, 0x3ffc999999999999)),
  f256_r10, //    = fp256Order(fpOrder(0x999999999999999a, 0xbf89999999999999),
            //                 fpOrder(0x999999999999999a, 0x3ffb999999999999)),
  f256_10_16; //  = fp256Order(fpOrder(0,0), fpOrder(0, 0x40341c37937e0800));

// I will want working precision even higher than 128-bits. I will
// arrange that using pairs of 128-bit floats such that the value
// I am representing is their sum. The code I have here will not be
// robust against issues of denormailised numbers, infinities or
// NaNs, and so its use needs to take care to avoid such cases.
//
// I am following the scheme from T J Dekker, Numer Math 18 224-242 (1971).

extern float256_t ato256(const char* s);

class OctFloat
{
public:
// Many people would believe I should make the data field here
// private rather than public, and provide an access function in
// case of need.

    float256_t v;

    constexpr OctFloat()                   // default constructor
    {   v.hi = v.lo = f128_0;
    }
    constexpr OctFloat(float128_t n)       // import from a float128_t
    {   v.hi = n;
        v.lo = f128_0;
    }
    constexpr OctFloat(float256_t n)       // import from a float256_t
    {   v.hi = n.hi;
        v.lo = n.lo;
    }
    constexpr OctFloat(const char* s)      // value as from a text string
    {   v = ato256(s);
    }
    constexpr OctFloat(const QuadFloat hi, const QuadFloat lo)
    {   v.hi = hi.v;
        v.lo = lo.v;
    }
    constexpr OctFloat(const OctFloat& rhs)
    {   v = rhs.v;
    }
    OctFloat(int n)
    {   v.hi = i32_to_f128(n);
        v.lo = f128_0;
    }
    OctFloat(int64_t n)
    {   v.hi = i64_to_f128(n);
        v.lo = f128_0;
    }
    OctFloat(float64_t n)
    {   v.hi = f64_to_f128(n);
        v.lo = f128_0;
    }
    OctFloat(double d)
    {   float64_t n;
        std::memcpy(reinterpret_cast<char*>(&n),
                    reinterpret_cast<char*>(&d),
                    sizeof(double));
        v.hi = f64_to_f128(n);
        v.lo = f128_0;
    }

    constexpr OctFloat(OctFloat&& rhs)
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

    constexpr bool sign();
    constexpr int exponent();
    constexpr OctFloat set_exponent(int64_t n);
    constexpr OctFloat mantissa();
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
// fact that QuadDoubles can be read in competently.


inline OctFloat oct_10(10);

inline OctFloat operator ""_QQ (const char* s)
{   return OctFloat(ato256(s));
}

inline float256_t ato256(const char* s)
{   bool sign = false;
    if (*s == '-')
    {   sign = true;
        s++;
        if (*s == '\'') s++;
    }
    bool dotSeen = false;
    int x = 0;
    OctFloat r(0);
    int c;
    while (std::isdigit(c = *s))
    {   r = oct_10*r + OctFloat(c - '0');
        s++;
        if (*s == '\'') s++;
        if (dotSeen) x--;
        else if (*s == '.')
        {   dotSeen = true;
            s++;
            if (*s == '\'') s++;
        }
    }
    if (*s == 'e' || *s == 'E')
    {   s++;
        if (*s == '\'') s++;
        bool xsign = false;
        if (*s == '-')
        {   xsign = true;
            s++;
            if (*s == '\'') s++;
        }
        int xx = 0;
        while (std::isdigit(c = *s))
        {   xx = 10*xx + c - '0';
            s++;
            if (*s == '\'') s++;
        }
        if (xsign) xx = -xx;
        x += xx;
    }
    if (x != 0)
    {   bool xsign = x < 0;
        if (xsign) x = -x;
        float256_t scale;
        f256M_pow(&oct_10.v, x, &scale);
        if (xsign) r = r / OctFloat(scale);
        else r = r * OctFloat(r);
    }
    if (sign) r = -r;
    return r.v;
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
        {   int c = *s++, d;
            if ((d = hexFromChar(c)) < 0)
            {   s--;
                break;
            }
            if (*s == '\'') s++;
            w = 16*w + d;
        }
        data[i] = w;
    }
    float256_t r;
#ifdef LITTLEENDIAN
    const int low = 0, high = 1;
#else // LITTLEENDIAN
    const int low = 1, high = 0;
#endif // LITTLEENDIAN
    r.hi.v[high] = data[0];
    r.hi.v[low] = data[1];
    r.lo.v[high] = data[2];
    r.lo.v[low] = data[3];
    return OctFloat(r); // Only fills in the "hi" component.
}

#endif // header_float128_t

// end of float128_t.h
