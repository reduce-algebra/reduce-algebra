// float128.cpp                                 Copyright (C) 2026 Codemist

// $Id: float128.cpp 7327 2026-03-07 17:06:01Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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


#ifdef TEST
#include "float128.h"
#else
#include "headers.h"
#endif

// Here are the scenarios I support:
//  USE_LONG_DOUBLE     long double conforms to 128-bit IEEE, so std::sin.
//  USE_QUADMATH        __float128 is a suitable type, and functions sinq etc
//  USE_CLANG_FLOAT128  __float128, together with sinf128 but no complex fns
//  USE_CXX23_FLOAT128  std::float128_t for arithmetic but no library provided
//  USE_SOFT_FLOAT128   must do everything myself.
// and in general one of those symbols should be defined. If none are then I
// default to USE_SOFT_FLOAT128


// Sometimes I will have a 128-bit floating point datatype provided by the
// along with all the elementary functions I need. In other cases the
// datatype and basic arithmetic operations are in place but T will need
// my own elementary function library. And in the most extreme case
// I will have to implement floating point in software.
//
// I will set up the following symbols to guard the code I include:
//   NEED_FLOAT160         I implement my own working precision.
//   NEED_FLOAT128         Implement 128-bit floats and complex.
//   NEED_REAL_MATHLIB     sin, cos etc on FLOAT128.
//   NEED_COMPLEX_MATHLIB  sin, cos etc on COMPLEX_128.

// Tu support CSL I provide 64-bit float functions that are
// not offered by the C++ standard.

// NOTE (ha ha ha) that for inverse trig functions the expected principle
// values will be as follows:
//
//    asin
//    atan     -pi/2 to pi/2
//    acsc
//
//    acos
//    acot     0 to pi
//    asec
//
//    atan2    0 to 2*pi
//
// and so the derivations as between these can involve adjustments to allow
// for that.

double acot(double x)
{   if (x < 0.0) return M_PI - std::atan(-1.0/x);
    else return std::atan(1.0/x);
}

double acoth(double x) { return std::atanh(1.0/x); }
double acsc(double x)  { return std::asin(1.0/x); }
double acsch(double x) { return std::asinh(1.0/x); }
double asec(double x)  { return std::acos(1.0/x); }
double asech(double x) { return std::acosh(1.0/x); }
double cbrt(double x)
{   if (x < 0) return -std::pow(-x, 1.0/3.0);
    else return std::pow(x, 1.0/3.0);
}
double cot(double x)   { return 1.0/std::tan(x); }
double coth(double x)  { return 1.0/std::tanh(x); }
double csc(double x)   { return 1.0/std::sin(x); }
double csch(double x)  { return 1.0/std::sinh(x); }
double sec(double x)   { return 1.0/std::cos(x); }
double sech(double x)  { return 1.0/std::cosh(x); }
double rsqrt(double x) { return 1.0/std::sqrt(x); }
double ln(double x)    { return log(x); }

double to_degrees(double x) { return 180.0*x/M_PI; }
// For large values of x I could do a lot better with the next one!
double to_radians(double x) { return M_PI*x/180.0; }

double acosd(double x) { return to_degrees(std::acos(x)); }
double acotd(double x) { return to_degrees(acot(x)); }
double acscd(double x) { return to_degrees(acsc(x)); }
double asecd(double x) { return to_degrees(asec(x)); }
double asind(double x) { return to_degrees(std::asin(x)); }
double atand(double x) { return to_degrees(std::atan(x)); }

double cosd(double x) { return std::cos(to_radians(x)); }
double cotd(double x) { return cot(to_radians(x)); }
double cscd(double x) { return csc(to_radians(x)); }
double secd(double x) { return sec(to_radians(x)); }
double sind(double x) { return std::sin(to_radians(x)); }
double tand(double x) { return std::tan(to_radians(x)); }

std::complex<double> acot(const std::complex<double>& x)
{    return std::tan(1.0/x);
}
std::complex<double> acoth(const std::complex<double>& x)
{    return std::tanh(1.0/x);
}
std::complex<double> acsc(const std::complex<double>& x)
{    return std::sin(1.0/x);
}
std::complex<double> acsch(const std::complex<double>& x)
{    return std::sinh(1.0/x);
}
std::complex<double> asec(const std::complex<double>& x)
{    return std::cos(1.0/x);
}
std::complex<double> asech(const std::complex<double>& x)
{    return std::cosh(1.0/x);
}
std::complex<double> cbrt(const std::complex<double>& x)
{    return std::pow(x, 1.0/3.0);
}
std::complex<double> cot(const std::complex<double>& x)
{    return 1.0/std::tan(x);
}
std::complex<double> coth(const std::complex<double>& x)
{    return 1.0/std::tanh(x);
}
std::complex<double> csc(const std::complex<double>& x)
{    return 1.0/std::sin(x);
}
std::complex<double> csch(const std::complex<double>& x)
{    return 1.0/std::sinh(x);
}
std::complex<double> sec(const std::complex<double>& x)
{    return 1.0/std::cos(x);
}
std::complex<double> sech(const std::complex<double>& x)
{    return 1.0/std::cosh(x);
}
std::complex<double> rsqrt(const std::complex<double>& x)
{    return 1.0/std::sqrt(x);
}
std::complex<double> expm1(const std::complex<double>& x)
{    return std::exp(x) - 1.0;
}

std::complex<double> ln(const std::complex<double>& x)
{    return std::log(x);
}

std::complex<double> log10(const std::complex<double>& x)
{    return std::log(x)*0.43429448190325182765;
}

#ifndef NEED_FLOAT128

// Here the system provides a me with 128-bit floats and at least basic
// arithmetic operations on them. I just wrap this all up within FLOAT128.

// Constructors

FLOAT_128::FLOAT_128()
{
}

NAN128::NAN128()
{   v = LF_C(0.0)/LF_C(0.0);
}

PLUSINF128::PLUSINF128()
{   v = LF_C(1.0)/LF_C(0.0);
}

MINUSINF128::MINUSINF128()
{   v = -LF_C(1.0)/LF_C(0.0);
}

ZERO128::ZERO128()
{   v = LF_C(0.0);
}

MINUSZERO128::MINUSZERO128()
{   v = -LF_C(0.0);
}

FLOAT_128::FLOAT_128(int32_t w)
{   v = w;
}

FLOAT_128::FLOAT_128(int64_t w)
{   v = w;
}

FLOAT_128::FLOAT_128(int128_t w)
{   v = w;
}

FLOAT_128::FLOAT_128(uint32_t w)
{   v = w;
}

FLOAT_128::FLOAT_128(uint64_t w)
{   v = w;
}

FLOAT_128::FLOAT_128(uint128_t w)
{   v = w;
}

FLOAT_128::FLOAT_128(double w)
{   v = w;
}

FLOAT_128::FLOAT_128(long double w)
{   v = w;
}

FLOAT_128::FLOAT_128(FLOAT_128 const& w)
{   v = w.v;
}

// The extra argument is just there to flags that this is injecting
// representation-level data into the FLOAT_128.

FLOAT_128::FLOAT_128(FLOAT128REP w, [[maybe_unused]] float unused)
{   v = w;
}

FLOAT128REP FLOAT_128::rep() const
{   return v;
}

uint128_t FLOAT_128::mantissa() const
{   uint128_t w = bit_cast<uint128_t>(v);
    return (bit_cast<uint128_t>(w)<<16)>>16;
}

// Useful tests etc

bool FLOAT_128::isinf() const
{   uint128_t w = bit_cast<uint128_t>(v);
    return (w<<1) == ((uint128_t)0x7fff << 113);
}

bool FLOAT_128::isnan() const
{   uint128_t w = bit_cast<uint128_t>(v);
    return ((w<<1)>>113) == 0x7fff &&
           (w<<16) != 0;
}

bool FLOAT_128::isinfornan() const
{   uint128_t w = bit_cast<uint128_t>(v);
    return ((w<<1)>>113) == 0x7fff;
}

bool FLOAT_128::isfinite() const
{   uint128_t w = bit_cast<uint128_t>(v);
    return ((w<<1)>>113) != 0x7fff;
}

bool FLOAT_128::signbit() const
{   return (bit_cast<uint128_t>(v)>>127) != 0;
}

FLOAT_128 FLOAT_128::abs() const
{   return FLOAT_128((bit_cast<uint128_t>(v)<<1)>>1, 0);
}

FLOAT_128 FLOAT_128::maxabs(FLOAT_128 v) const
{   if (abs() >= v.abs()) return *this;
    else return v;
}

bool FLOAT_128::isnormal() const
{   uint128_t b = bit_cast<uint128_t>(v);
    if ((b<<1) == 0) return true;   // +0.0 or -0.0
    else if (((b>>112) & 0x7fff) == 0) return false;
    else return true;               // exponent field nonzero.
}

bool FLOAT_128::iszero() const
{   return (bit_cast<uint128_t>(v)<<1) == 0;
}

// Casts

FLOAT_128::operator int32_t() const
{   return (int32_t)v;
}

FLOAT_128::operator int64_t() const
{   return (int64_t)v;
}

FLOAT_128::operator int128_t() const
{   return (int128_t)v;
}

FLOAT_128::operator uint32_t() const
{   return (uint32_t)v;
}

FLOAT_128::operator uint64_t() const
{   return (uint64_t)v;
}

FLOAT_128::operator uint128_t() const
{   return (uint128_t)v;
}

FLOAT_128::operator double() const
{   return (double)v;
}

FLOAT_128::operator long double() const
{   return (long double)v;
}

// Operators

FLOAT_128 FLOAT_128::operator+() const
{   return FLOAT_128(v, 0.0f);
}

FLOAT_128 FLOAT_128::operator-() const
{   return FLOAT_128(-v, 0.0f);
}

FLOAT_128 FLOAT_128::operator+(FLOAT_128 w) const
{   return FLOAT_128(v + w.v, 0.0f);
}

FLOAT_128 FLOAT_128::operator-(FLOAT_128 w) const
{   return FLOAT_128(v - w.v, 0.0f);
}

FLOAT_128 FLOAT_128::operator*(FLOAT_128 w) const
{   return FLOAT_128(v * w.v, 0.0f);
}

FLOAT_128 FLOAT_128::operator/(FLOAT_128 w) const
{   return FLOAT_128(v / w.v, 0.0f);
}

FLOAT_128 FLOAT_128::fma(FLOAT_128 b, FLOAT_128 c) const
{
#if defined USE_LONG_DOUBLE
    return FLOAT_128(std::fma(v, b.v, c.v));
#elif defined USE_QUADMATH
    return FLOAT_128(fmaq(v, b.v, c.v));
#elif defined USE_CLANG_FLOAT128
    return FLOAT_128(fmaf128(v, b.v, c.v));
#else
    FLOAT160 aa = (FLOAT160)*this;
    FLOAT160 bb = (FLOAT160)b;
    FLOAT160 cc = (FLOAT160)c;
    return (FLOAT_128)aa.fma(bb, cc);
#endif
}

// Comparisons

bool FLOAT_128::operator==(FLOAT_128 const& w) const
{   return (v == w.v);
}

bool FLOAT_128::operator!=(FLOAT_128 const& w) const
{   return (v != w.v);
}

bool FLOAT_128::operator>(FLOAT_128 const& w) const
{   return (v > w.v);
}

bool FLOAT_128::operator<(FLOAT_128 const& w) const
{   return (v < w.v);
}

bool FLOAT_128::operator>=(FLOAT_128 const& w) const
{   return (v >= w.v);
}

bool FLOAT_128::operator<=(FLOAT_128 const& w) const
{   return (v <= w.v);
}

#endif // !NEED_FLOAT128

// ldexp()  and frexp() seem to need to be done in software if the
// C++23 "std::float128_t" type is available as well as if everything
// needs to be done in software, and when there are system-provided
// versions the names vary.

FLOAT_128 FLOAT_128::ldexp(int x) const
{
#if defined USE_LONG_DOUBLE
    return FLOAT_128(std::ldexp(v, x), 1.0f);
#elif defined USE_QUADMATH
    return FLOAT_128(ldexpq(v, x), 1.0f);
#elif defined USE_CLANG_FLOAT128
    return FLOAT_128(ldexpf128(v, x), 1.0f);
#else
// In the case of C++23 std::float128_t and also if I am doing things
// all in software I will do this by playing with the binary representation.
// There are several horrid cases here:
//     input is not a denormalised number, in which case exponent information
//         is determined by the position of the top bit in the mantissa field.
//     ldexp leads to overflow (including cases where the input is infinite).
//     ldexp leads to underflow.
    uint128_t b = bit_cast<uint128_t>(v);
// If the input is +0.0 or -0.0 return it.
    if ((b<<1) == 0) return *this;
    int xx = (b>>112) & 0x7fff;
// If the input is an infinity or a NaN return it.
    if (xx == 0x7fff) return *this;
// If the input is denormalised then normalise it leaving xx the
// true exponent - which may be outside the proper range for going
// back into a FLOAT_128.
    uint128_t mm = (b<<16)>>16;
    if (xx == 0)
    {   int shift = nlz(mm)-15;
// The shift value is what would bring the top bit of the mantissa to
// where the hidden bit would lie. I want to shift it to there and then
// discard the high 16 bits of the word so that the hidden bit is indeed
// hidden.
        xx = xx - shift;
        mm = (mm << (shift+16)) >> 16;
    }
    xx = xx + x;
// Now check for overflow...
    if (xx >= 0x7fff) return PLUSINF128();
    if (xx <= 0)
    {
// Underflow, with the result either a denorm or zero.
        if (xx < -112) mm = (mm | (((uint128_t)1)<<112)) >> (-xx);
        else mm = 0;
        xx = 0;
    }
    uint64_t hi = (uint64_t)((b>>127)<<63) |
        (((uint64_t)xx)<<48) |
        (uint64_t)(mm>>64);
    return FLOAT_128(((uint128_t)hi)<<64 | (uint64_t)mm, 0);
#endif
}

FLOAT_128 FLOAT_128::frexp(int& x) const
{
#if defined USE_LONG_DOUBLE
    return FLOAT_128(std::frexp(v, &x), 1.0f);
#elif defined USE_QUADMATH
    return FLOAT_128(frexpq(v, &x), 1.0f);
#elif defined USE_CLANG_FLOAT128
    return FLOAT_128(frexpf128(v, &x), 1.0f);
#else
    uint128_t b = bit_cast<uint128_t>(v);
    if (b == 0)
    {   x = 0;
        return *this;         // 0.0
    }
    int xx = (int)((b>>112) & 0x7fff);
    if (xx == 0x7fff)
    {   x = 0;
        return *this;         // infinities and NaNs
    }
    if (xx == 0)
    {   int shift = 1+nlz(b<<16);
        xx = xx - shift;
        b = ((b>>127)<<127) |
            (((b<<(shift+16)))>>16) |
            (((uint128_t)0x3fff)<<112);
    }
    else b = (b | (((uint128_t)0x3fff)<<112)) & ~(((uint128_t)1)<<126);
    x = xx - 0x3fff;
    return FLOAT_128(b, true);
#endif
}

void f128tof160(FLOAT_128 const& v,
                bool& sign, int32_t& exponent, uint128_t& mantissa)
{   uint128_t b = bit_cast<uint128_t>(v.rep());
    sign = (b>>127) != 0;
    int32_t x = (int32_t)((b<<1)>>113);
// I should never have an infinity or a NaN here - I should have filtered
// and such cases out before trying to convert to FLOAT160. However I can
// have denormalised values.
    b = ((b<<16)>>16);               // get rid of sign and exponent fields.
    if (x != 0)
    {   b = b | ((uint128_t)1)<<112; // reinstate hidden bit
        x = x - 0x3fff;
    }
    else if (b == 0) x = INT32_MIN;  // a zero
    else
    {   int shift = nlz(b);          // renormalise denorm.
        b = b << shift;
        x = x - 0x3fff - shift + 15;
    }
    exponent = x+1;
    mantissa = b << 15;              // re-align to top bit of mantissa.
}

#ifdef NEED_FLOAT160

// Implement FLOAT160 - a "working precision" that has 128-bits of
// mantissa, 32-bits of exponent and that does not handle infinties,
// NaNs even though it can return some of those...

NAN160::NAN160()
{   sign = false;
    x = INT32_MAX;
    m = 1;
}

INF160::INF160()
{   sign = false;
    x = INT32_MAX;
    m = 0;
}   



// Arithmetic operations on FLOAT160 will not be pedantic about how I
// round at the least significant bit. I will not support any directed
// rounding schemes and will not guarantee to follow IEEE-style rules
// that round-to-even in the 0.5ULP case. But I will do what I feel I
// can when it is not too burdensome. This is intended to be used as
// working precision with 15 more bits of mantissa than FLOAT_128 (15 not 16
// because I represent the top bit of the mantissa explicitly rather than
// as a hidden bit) and the hope is that that is enough to make work on
// 128-bit floats as accurate as I need.

constexpr FLOAT160::FLOAT160(uint64_t n):sign(),x(),m()
{   sign = false;
    m = n;
    if (n == 0)
    {   x = INT32_MIN;
        return;
    }
    int shift = nlz(m);
    m = m << shift;
    x = 128 - shift;
}

constexpr FLOAT160::FLOAT160(uint32_t x) : FLOAT160((uint64_t)x)
{
}

constexpr FLOAT160::FLOAT160(uint128_t n):sign(),x(),m()
{   if (n == 0)
    {   m = 0;
        x = INT32_MIN;
        sign = false;
        return;
    }
    m = n;
    sign = false;
    int shift = nlz(m);
    m = m << shift;
    x = 128 - shift;
}

constexpr FLOAT160::FLOAT160(int128_t n):sign(),x(),m()
{   if (n < 0)
    {   n = -(uint128_t)n;
        sign = true;
    }
    else sign = false;
    if (n == 0)
    {   m = 0;
        x = INT32_MIN;
        sign = false;
        return;
    }
    m = n;
    sign = false;
    int shift = nlz(m);
    m = m << shift;
    x = 128 - shift;
}

// Here there is a bit of a mess! "long double" might be any of 64, 80
// or 128 bits and I will need to do different things in each case! Well
// I have a scheme here that leaves the code uniform.

// Well I will believe I know the exact format of a double, and so I
// could probably do this exploiting that.

FLOAT160::FLOAT160(FLOAT_128 const& v) : sign(false),x(0),m(0)
{   f128tof160(v, sign, x, m);
}

// Accessors

constexpr FLOAT160 FLOAT160::maxabs(FLOAT160 v) const
{   if (abs() >= v.abs()) return *this;
    else return v;
}

constexpr void FLOAT160::mantissa(uint64_t& hi, uint64_t& lo) const
{   hi = (uint64_t)(m>>64);
    lo = (uint64_t)m;
}

FLOAT160 FLOAT160::ldexp(int32_t x) const
{   if (mantissa() == 0) return *this;
    else return FLOAT160(signbit(), exponent()+x, mantissa());
}

FLOAT160 FLOAT160::frexp(int& x) const
{   if (mantissa() == 0)
    {   x = 0;
        return *this;
    }
    x = exponent();
    return FLOAT160(signbit(), 0, mantissa());
}

constexpr void FLOAT160::setmantissa(uint64_t hi, uint64_t lo)
{   m = (((uint128_t)hi)<<64) | lo;
}

constexpr FLOAT160::operator uint128_t() const
{   if (x <= 0) return 0;
    else return m>>(128-x);
}

constexpr FLOAT160::operator int64_t() const
{   if (x <= 0) return 0;
    uint64_t r = (uint64_t)(m>>(128-x));
    if (sign) r = -r;
    return (int64_t)r;
}

// This converts to the bit-pattern that will be for a 128-bit float,
// handling infinities and denormalised values and rounding properly.

uint128_t FLOAT160::f160tof128rep() const
{
// I will first handle some special values that have to convert into
// infinities or NaNs
    if (x == INT32_MAX)
    {   if (m == 0)
        {   if (sign) return MINUSINF128();
            else return PLUSINF128();
        }
        else return NAN128();
    }
    uint128_t r = 0;
    if (m == 0) return r;
    int32_t xx = x + 0x3ffe;
    if (xx <= 0)
    {   if (xx >= -111)
        {   r |= m>>(16-xx);
// @@@ I need to round here I guess.
        }
        return r; // denorm or underflow
    }
    if (xx >= 0x7fff)
        return r | (((uint128_t)0x7fff)<<112); // infinity
    r = (m<<1)>>16;              // Mantissa with top bit hidden
    uint128_t guard = m<<(128-15);
    if (guard > topbit128() ||
        (guard == topbit128() && (r&1)!=0)) r++;
// Note that incrementing r could overflow out of the 112-bit mantissa
// field, but since I add in the exponent when this happens the (non-
// hidden) mantissa ends up as zero and the exponent increases. Including
// possibly to yield an infinity!
    if (sign) r |= topbit128();
    r += ((uint128_t)xx) << 112;
    return r;
}

FLOAT160::operator FLOAT_128() const
{   FLOAT_128 r(f160tof128rep(), 0);
    return r;
}

FLOAT160 FLOAT160::fma(FLOAT160& b, FLOAT160& c)
{   std::cout << "160-bit fms called\n";
    std::abort(); // @@@
}

FLOAT160 FLOAT160::operator+=(FLOAT160 const& rhs)
{   FLOAT160 r = *this + rhs;
    sign = r.sign;
    x = r.x;
    m = r.m;
    return *this;
}

FLOAT160 FLOAT160::operator-=(FLOAT160 const& rhs)
{   FLOAT160 r = *this - rhs;
    sign = r.sign;
    x = r.x;
    m = r.m;
    return *this;
}

FLOAT160 FLOAT160::operator*=(FLOAT160 const& rhs)
{   FLOAT160 r = *this * rhs;
    sign = r.sign;
    x = r.x;
    m = r.m;
    return *this;
}

FLOAT160 FLOAT160::operator/=(FLOAT160 const& rhs)
{   FLOAT160 r = *this / rhs;
    sign = r.sign;
    x = r.x;
    m = r.m;
    return *this;
}

#endif // NEED_FLOAT160

extern int f160_sprint_G(char* r, int width, int precision,
                         bool sign, int32_t exponent, uint128_t mantissa);

std::ostream& showfloat160(std::ostream& o,
                           bool sign, int32_t exponent, uint128_t mantissa,
                           int width, int precision)
{   bool hex = (o.flags() & std::ios::hex) != 0;
    if (hex)
    {   uint128_t v = mantissa;
        uint64_t hi = v >> 64;
        uint64_t lo = (uint64_t)v;
        int32_t x = v==0 ? 0 : exponent;
        int pad = width - 36;
        if (sign) pad--;
        int xx = x;
        while (xx >= 10)
        {   pad--;
            xx = xx/10;
        }
        for (int i=0; i<pad; i++) o << " ";
        return o << (sign ? "-0X" : "0X")
                 << std::setfill('0') << std::setw(16) << hi
                 << "_"               << std::setw(16) << lo
                 << std::dec << "P" << x << std::hex;
    }
    else
    {   char buffer[128];
        f160_sprint_G(buffer, width, precision,
                      sign, exponent, mantissa);
        return o << buffer;
    }
}

std::ostream& operator<<(std::ostream& o, FLOAT_128 const& d)
{   if (d.isnan()) return o << "NaN";
    else if (d.isinf())
    {   if (d.signbit()) return o << "-inf";
        else return o << "inf";
    }
    else
    {   bool sign;
        int32_t exponent;
        uint128_t mantissa;
        f128tof160(d, sign, exponent, mantissa);
        return showfloat160(o, sign, exponent, mantissa,
                            o.width(), o.precision());
    }
}

std::ostream& operator<<(std::ostream& o, COMPLEX_128 const& d)
{   o << d.real() << " + " << d.imag() << "*i";
    return o;
}

#ifdef NEED_FLOAT160

std::ostream& operator<<(std::ostream& o, FLOAT160 const& d)
{   return showfloat160(o,
                        d.signbit(), d.exponent(), d.mantissa(),
                        o.width(), o.precision());
}

std::ostream& operator<<(std::ostream& o, COMPLEX160 const& d)
{   o << d.real() << " + " << d.imag() << "*i";
    return o;
}

#endif

// Now printing of high precision floats. This first function turns a
// FLOAT160 into an array of characters together with a decimal exponent
// that must be attached. It does not do anything about formatting.

bool f160_to_string(char* s,
                    bool sign, int32_t exponent, uint128_t mantissa,
                    int& decexp)
{   if (mantissa == 0)
    {   std::strcpy(s, "0");
        decexp = 0;
        return sign;
    }
    int32_t x = exponent;
    uint128_t m = mantissa;
// Now I only have positive nonzero numbers to cope with.
    uint64_t hi, mid, lo;
    hi = (uint64_t)(m>>64);
    mid = (uint64_t)m;
    lo = 0;
// I want to scale the input until it is the range
// [10^17, 10^18). I start by estimating the number of decimal digits
// present by multiplying the binary exponent by log10(2) - well I use
// a good rational approximation to that.
    uint64_t hi1, mid1, lo1;
    int32_t x1;
    int32_t dx = (12655*x + 21019)/42039;
    power10(hi1, mid1, lo1, x1, 17 - dx);
    multiply192(hi, mid, lo, x, hi1, mid1, lo1, x1, hi, mid, lo, x);
// I now expect the value to be close to where I need it to be, so I
// adjust by multiplying or dividing by 10.
    while (ge192(hi, mid, lo, x,    // compare with 10^18
           UINT64_C(0xde0b6b3a76400000), 0, 0, 60))
    {   multiply192(hi, mid, lo, x,
                    UINT64_C(0xcccccccccccccccc),
                    UINT64_C(0xcccccccccccccccc),
                    UINT64_C(0xcccccccccccccccd), -3,
                    hi, mid, lo, x);
        dx++;
    }
    while (lt192(hi, mid, lo, x,    // compare with 10^17
           UINT64_C(0xb1a2bc2ec5000000), 0, 0, 57))
    {   multiply192(hi, mid, lo, x,
                    UINT64_C(0xa000000000000000), 0, 0, 4,
                    hi, mid, lo, x);
        dx--;
    }
// If I now take the integer part of my scaled number I get exactly 18
// digits to put in my result.
    s += snprintf(s, 24, "%" PRIu64, intpart192(hi, x));
    fracpart192(hi, mid, lo, x);
// Now I can grab the next 12 digits.
    multiply192(hi, mid, lo, x,
                UINT64_C(0xe8d4a51000000000), 0, 0, 40,
                hi, mid, lo, x);
    s += snprintf(s, 20, "%012" PRIu64, intpart192(hi, x));
    fracpart192(hi, mid, lo, x);
// And a final 12 digits, making 18+12+12 = 42 in all.
    multiply192(hi, mid, lo, x,
                UINT64_C(0xe8d4a51000000000), 0, 0, 40,
                hi, mid, lo, x);
    s += snprintf(s, 20, "%012" PRIu64, intpart192(hi, x));
// I generate exactly 42 digits, while 39 should be enough to
// capture all the information pre4sent in my 128-bit mantissa.
    decexp = dx;
    return sign;
}

// f160_to_string decodes the number so that it is always in the form
// nnnnn with 42 digits (unless the value is zero!). It returns the sign
// and placing the (decimal) exponent in decexp.

#ifdef NEED_FLOAT160

// f160_print prints all 42 digits as generated by f160_to_string.

void f160_print(FLOAT160 p)
{   char s[128];
    int decexp;
    bool neg = f160_to_string(s,
                              p.signbit(), p.exponent(), p.mantissa(),
                              decexp);
    if (!std::isdigit(s[0])) std::printf("%s%s\n", neg ? "-" : "", s);
    else std::printf("%s%c.%sL%d\n", neg ? "-" : "", s[0], &s[1], decexp);
}

#endif

// This rounds the number in a buffer to have ndigits in all.
// When I round it is possible to generate an overflow. Consider the case of
// 9.9996 rounded to 4 figures. It should end up as
// 10.000, except that what I want to do is shift that along so it comes
// out as "1.000" with the exponent incremented. Rounding to 1 digits will
// leave just the integer part.

bool round_at(char* s, int ndigits)
{
// The raw string s will have 42 digits so if I ask to keep all of them
// I just leave things alone. If I round to 41 or fewer then there will be
// a digit beyond where I round.
    if (ndigits < 0 || ndigits >= 42) return false;
// If the digits just beyond where I am is < '5' I will truncate down.
    if (s[ndigits] < '5')
    {    s[ndigits] = 0;
         return false;
    }
// If the digits beyond where I am are "50000...0" and I the digit I would
// change on rounding up is even then I will round down.
    if (s[ndigits] == '5' && (ndigits == 0 || s[ndigits-1]%2 == 0))
    {   s[ndigits] = 0;
        int p = ndigits+1;
        while (p < 42 && s[p] == '0') p++;
        if (p >= 42) return false;
    }
    s[ndigits] = 0;
// Here I need to round up.
    int p = ndigits-1;
    while (p >= 0)
    {   if (s[p] != '9')
        {   s[p]++;
            return false;
        }
        s[p--] = '0';  // need to carry.
    }
// If I have dropped out of the loop it means that I have rounded an
// initial '9' up.
    s[0] = '1';        // most of the remaining relevant digits are '0' here.
    s[ndigits] = '0';
    s[ndigits+1] = 0;
    return true;
}

// This is used to put in blanks to fill to the specified width.

char* pad_by(char* r, int n)
{   while (n-- > 0) *r++ = ' ';
    *r = 0;
    return r;
}

// This is used to insert a string of '0' chararacters.

char* pad_by_zero(char* r, int n)
{   while (n-- > 0) *r++ = '0';
    *r = 0;
    return r;
}

// Print using "E " format

int f160_sprint_E(char* r, int width, int prec, char* s, bool sign, int decexp)
{   char* original_r = r;
// I limit the requested precision to 39 - anything higher is unnecessary!
// A precision less than 1 can not make sense.
    if (prec < 1) prec = 1;
    else if (prec > 39) prec = 39;
    if (sign) width--;
    if (!std::isdigit(s[0]))
    {   r = pad_by(r, width-std::strlen(s));
        if (sign) *r++ = '-';
        std::strcpy(r, s);
        return (r - original_r) + std::strlen(r);
    }
    else
    {   char ebuf[12];
        if (round_at(s, prec)) decexp++;
// I format the exponent so I can see how many characters that uses.
        width -= std::snprintf(ebuf, sizeof(ebuf), "L%d", decexp);
        r = pad_by(r, width - prec - 1);
        if (sign) *r++ = '-';
        if (prec >= 36)
        {   r += std::snprintf(r, 40, "%c.%.35s", s[0], &s[1]);
            r = pad_by_zero(r, prec-36);
            std::strcpy(r, ebuf);
            r += std::strlen(r);
        }
        else r += std::snprintf(r, 40, "%c.%.*s%s", s[0], prec-2, &s[1], ebuf);
    }
    return r - original_r;
}

int f160_print_E(int width, int prec,
                 bool sign, int32_t exponent, uint128_t mantissa)
{   char buffer[128], s[128];
    int r = 0;
    while (width > 63)
    {   std::putchar(' ');
        r++;
        width--;
    }
    if (prec > 39) prec = 39;
    int decexp;
    bool neg = f160_to_string(s, sign, exponent, mantissa, decexp);
    r += f160_sprint_E(buffer, width, prec, s, neg, decexp);
    std::fputs(buffer, stdout);
    return r;
}

int f128_print_E(int width, int prec, FLOAT_128 p)
{   bool sign;
    int32_t exponent;
    uint128_t mantissa;
    f128tof160(p, sign, exponent, mantissa);
    return f160_print_E(width, prec, sign, exponent, mantissa);
}

// This will be for "F" format.

int f160_sprint_F(char* r, int width, int prec, char* s, bool sign, int decexp)
{   char* original_r = r;
    if (prec < 0) prec = 0;
    else if (prec > 39) prec = 39;
    if (sign) width--;
// Infinities and NaNs are displayed with scant regard to the requested
// precision, but they do honour the width request.
    if (!std::isdigit(s[0]))
    {   r = pad_by(r, width-std::strlen(s));
        if (sign) *r++ = '-';
        std::strcpy(r, s);
        return (r - original_r) + std::strlen(r);
    }
// The "F" print format is basically abominable in that it can lead to
// absurdly long output. There are three bad cases
// (1)    %9999.2F           generates a silly number of leading blanks
// (2)    %.2F in 1.23e1234  has to display >1K chars before the "."
// (3)    %.9999F            has to generate many chars after the "."
// I will take the view that for sprint the first of these is something that
// the user has done and they know how big a buffer to provide - so I view
// it as not terribly much of a problem.
// But be aware that if 1.0e1000 is printed in F format it will have a very
// large number of characters before the decimal point and writing those
// into a buffer will be problematic. So by and large F format is a BAD thing,
// while E and G format are safe.
    if (round_at(s, decexp+prec)) decexp++;
    if (decexp >= 40)
    {
// Here I deal with the integer part if it is bigger than 10^40 so you
// get all possible valid bits of the floaying point values then some
// zeros, then a "." and then nume number of zeros that your precision
// indicated. This can really easily overflow a buffer!
        if (sign) *r++ = '-';
        r += std::snprintf(r, 41, "%.40s", s);
        r = pad_by_zero(r, decexp-39);
        *r++ = '.';
        r = pad_by_zero(r, prec);
    }
    else if (decexp >= 0)
    {
// Here there is an integer part to split off.
        int fdig = 39-decexp;
        if (fdig > prec) fdig = prec;
        if (sign) *r++ = '-';
        r += std::snprintf(r, 48, "%.*s.%.*s",
                          decexp+1, s, fdig, &s[decexp+1]);
        r = pad_by_zero(r, prec-fdig);
    }
    else if (prec+decexp+1 <= 39)
    {
// Now there is no integer part but the floating point representation is
// such that it has significant digits of its fraction all the way to
// the specified precision.
        if (sign) *r++ = '-';
        r += std::snprintf(r, 4, "0.");
        int pp = -decexp-1;
        if (pp > prec) pp = prec;
        r = pad_by_zero(r, pp);
        if (prec+decexp+1 > 0)
            r += std::snprintf(r, 48, "%.*s", prec+decexp+1, s);
    }
    else
    {
// Finally we have a case where the precision is such that
// there need to be zeros places after all the meaningful digits of the
// fraction.
        if (sign) *r++ = '-';
        r += std::snprintf(r, 4, "0.");
        r = pad_by_zero(r, -decexp-1);
        r += std::snprintf(r, 40, "%.39s", s);
        r = pad_by_zero(r, prec+decexp-38);
    }
    return r - original_r;
}

int f160_print_F(int width, int prec,
                 bool sign, int32_t exponent, uint128_t mantissa)
{   char buffer[128], s[128];
    int r = 0;
    while (width > 63)
    {   std::putchar(' ');
        r++;
        width--;
    }
    int decexp;
    bool neg = f160_to_string(s, sign, exponent, mantissa, decexp);
    r += f160_sprint_F(buffer, width, prec, s, neg, decexp);
    std::fputs(buffer, stdout);
    return r;
}

int f128_print_F(int width, int prec, FLOAT_128 p)
{   bool sign;
    int32_t exponent;
    uint128_t mantissa;
    f128tof160(p, sign, exponent, mantissa);
    return f160_print_F(width, prec, sign, exponent, mantissa);
}

// Finally for "G" format.

int f160_sprint_G(char* r, int width, int precision,
                  bool sign, int32_t exponent, uint128_t mantissa)
{   char s[128];
    int decexp;
// This implementation does the conversion twice, which is clumsy.  It also
// makes its choice as between use of E and F format before rounding. This
// letter could hurt when printing 9.99999e3 in precision 3. Here the
// exponent and precision are both 3 so F format will be used, asking for
// no digits beyond the decimal point. This asks the F printer to print
// as 999.[999] and I expect it will round this to 1000. which ought to
// have been rendered as 1.e03.
    bool neg = f160_to_string(s, sign, exponent, mantissa, decexp);
    if (precision < 1) precision = 1;
    else if (precision > 39) precision = 39;
    if (decexp < -4 || decexp > precision)
        return f160_sprint_E(r, width, precision, s, neg, decexp);
    else return f160_sprint_F(r, width, precision-decexp, s, neg, decexp);
}

int f128_sprint_G(char* r, int width, int precision, FLOAT_128 p)
{   bool sign;
    int32_t exponent;
    uint128_t mantissa;
    f128tof160(p, sign, exponent, mantissa);
    return f160_sprint_G(r, width, precision, sign, exponent, mantissa);
}

int f160_print_G(int width, int precision,
                 bool sign, int32_t exponent, uint128_t mantissa)
{   char buffer[128];
    int r = 0;
    while (width > 63)
    {   std::putchar(' ');
        r++;
        width--;
    }
    r += f160_sprint_G(buffer, width, precision, sign, exponent, mantissa);
    std::fputs(buffer, stdout);
    return r;
}

int f128_print_G(int width, int precision, FLOAT_128 p)
{   bool sign;
    int32_t exponent;
    uint128_t mantissa;
    f128tof160(p, sign, exponent, mantissa);
    return f160_print_G(width, precision, sign, exponent, mantissa);
}

#ifdef NEED_FLOAT128

// Here I will sometimes use FLOAT160 working precision to implement
// FLOAT_128 operations. In this case I know that the data field in the
// onject is of type uint128_t.

// Constructors

FLOAT_128::FLOAT_128()
{
}

// I convert from integer to FLOAT_128 via FLOAT160 since that will deal
// with infinities nicely... and avoids me needing to duplicate code.
// The important part of this is not the FLOAT160 width but that the
// caset from there to mere FLOAT_128 is useful.

FLOAT_128::FLOAT_128(int32_t w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(int64_t w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(int128_t w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(uint32_t w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(uint64_t w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(uint128_t w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(double w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(long double w)
{   v = ((FLOAT_128)FLOAT160(w)).v;
}

FLOAT_128::FLOAT_128(FLOAT_128 const& w)
{   v = w.v;
}

//FLOAT_128::FLOAT_128(uint64_t hi, uint64_t lo)
//{   v = (((uint128_t)hi)<<64) | lo;
//}

// The extra argument is just there to flags that this is injecting
// representation-level data into the FLOAT_128.

//FLOAT_128::FLOAT_128(uint128_t rep, [[maybe_unused]] int unused)
//{   v = bit_cast<FLOAT128REP>(rep);
//}

FLOAT_128::FLOAT_128(FLOAT128REP rep, [[maybe_unused]] float unused)
{   v = rep;
}

FLOAT128REP FLOAT_128::rep() const
{   return v;
}

uint128_t FLOAT_128::mantissa() const
{   return (bit_cast<uint128_t>(v)<<16)>>16;
}

// Useful tests etc

bool FLOAT_128::isinf() const
{   return (v<<1) == ((uint128_t)0xfffe)<<112;
}

bool FLOAT_128::isfinite() const
{   return ((v<<1)>>113) != 0x7fff;
}

bool FLOAT_128::isnan() const
{   return ((v>>112) & 0x7fff) == 0x7fff &&
           (v<<16) != 0;
}

bool FLOAT_128::isinfornan() const
{   return ((v>>112) & 0x7fff) == 0x7fff;
}

bool FLOAT_128::signbit() const
{   return (v>>127) != 0;
}

bool FLOAT_128::isnormal() const
{   if ((v<<1) == 0) return true;   // +0.0 or -0.0
    else if (((v>>112) & 0x7fff) == 0) return false;
    else return true;               // exponent field nonzero.
}

bool FLOAT_128::iszero() const
{   return (v<<1) == 0;
}

FLOAT_128 FLOAT_128::abs() const
{   return FLOAT_128((v<<1)>>1, 0);
}

FLOAT_128 FLOAT_128::maxabs(FLOAT_128 x) const
{   if ((v>>1) >= (x.v>>1)) return *this;
    else return x;
}


// Casts

// Casting any sort of float to a variety of int will give undefined
// bahaviour if the value used overflows. What I do is I convert to
// a 128-bit result and truncate. Infinities and NaNs probably lead
// to a zero value being returned.

FLOAT_128::operator int32_t() const
{   return (int32_t)operator int128_t();
}

FLOAT_128::operator int64_t() const
{   return (int64_t)operator int128_t();
}

FLOAT_128::operator int128_t() const
{   uint128_t r = operator uint128_t();
    if ((v>>127) != 0) return -r;
    else return r;
}

FLOAT_128::operator uint32_t() const
{   return (uint32_t)operator uint128_t();
}

FLOAT_128::operator uint64_t() const
{   return (uint64_t)operator uint128_t();
}

FLOAT_128::operator uint128_t() const
{   int x = (v<<1)>>113;            // the exponent field
    if (x <= 0) return 0;           // value is < 1.0
// Set up the mantissa, putting back the hidden bit.
    uint128_t m = ((v<<16)>>16) | (((uint128_t)1)<<112);
// If the number is too big then return zero.
    int128_t r = x>113 ? 0 : (m>>(113-x));
    if ((v>>127) != 0) return -r;
    else return r;
}

FLOAT_128::operator double() const
{   if (v == 0) return 0.0;
    int x = (v<<1)>>113;
    if (x == 0x7fff) // infinity or NaN
    {   if ((v<<16) != 0) return 0.0/0.0;
        if ((v>>127) == 0) return 1.0/0.0;
        else return (-1.0)/0.0;
    }
    int128_t i = ((v<<16)>>16) | ((uint128_t)1)<<112;
    double m = (double)i;
    if ((v>>127) != 0) i = -i;
    return std::ldexp(m, x-0x3fff-113);
}

FLOAT_128::operator long double() const
{   if (v == 0) return 0.0L;
    int x = (v<<1)>>113;
    if (x == 0x7fff) // infinity or NaN
    {   if ((v<<16) != 0) return 0.0L/0.0L;
        if ((v>>127) == 0) return 1.0L/0.0L;
        else return (-1.0L)/0.0L;
    }
    int128_t i = ((v<<16)>>16) | ((uint128_t)1)<<112;
    long double m = (long double)i;
    if ((v>>127) != 0) i = -i;
    return std::ldexp(m, x-0x3fff-113);
}

// Operators

FLOAT_128 FLOAT_128::operator+() const
{   return FLOAT_128(v, 0.0f);
}

// Note that negating a NaN here flips the sign bit but the result is
// still a NaN.
FLOAT_128 FLOAT_128::operator-() const
{   return FLOAT_128(v ^ ((uint128_t)1)<<127, 0.0f);
}

// For most of the operations on FLOAT_128 I need to start by handling
// infinities an NaNs (and sometimes zeros). But beyond that I delegate
// to FLOAT160. The handling of the special cases feels pretty painful!

FLOAT_128 FLOAT_128::operator+(FLOAT_128 w) const
{   if (isinfornan())
    {   if (w.isinfornan())
        {
// If either input is a NaN then return a NaN.
            if (mantissa() != 0) return *this;
            else if (w.mantissa() != 0) return w;
// If both inputs are infinities and their signs match then return
// that infinity, otherwise a NaN.
            else if (signbit() == w.signbit()) return *this;
            else return NAN128();
        }
// An infinity or a NaN plus something finite remains unchanged.
        return *this;
    }
    else if (w.isinfornan()) return w;
    else return (FLOAT_128)((FLOAT160)*this + (FLOAT160)w);
}

FLOAT_128 FLOAT_128::operator-(FLOAT_128 w) const
{   return operator+(- w);
}

FLOAT_128 FLOAT_128::operator*(FLOAT_128 w) const
{   if (isinfornan())
    {   if (mantissa() != 0) return *this;    // a NaN
        if (w.isinfornan())
        {   if (w.mantissa() != 0) return w;  // a NaN
            if (signbit() == w.signbit()) return PLUSINF128();
            else return MINUSINF128();
        }
        if (w.isnan()) return w;
        if (w.iszero() == 0) return NAN128();  // inf*0.0
        if (signbit() == w.signbit())     // inf*finite
            return PLUSINF128();
        else return MINUSINF128();
    }
    else if (w.isinfornan())
    {   if (iszero()) return NAN128();    // 0.0*(inf or NaN)
        if (w.isnan()) return w;
        if(signbit() == w.signbit()) return PLUSINF128();
        return MINUSINF128();
    }
    else return (FLOAT_128)((FLOAT160)*this * (FLOAT160)w);
}

FLOAT_128 FLOAT_128::fma(FLOAT_128 b, FLOAT_128 c) const
{   FLOAT160 aa = (FLOAT160)*this;
    FLOAT160 bb = (FLOAT160)b;
    FLOAT160 cc = (FLOAT160)b;
    return (FLOAT_128)aa.fma(bb, cc);
}

FLOAT_128 FLOAT_128::operator/(FLOAT_128 w) const
{   if (isinfornan())
    {   if (w.isinfornan()) return NAN128(); // infornan/infornan
        else if (signbit() == w.signbit()) return PLUSINF128();
        else return MINUSINF128();
    }
    else if (w.isinfornan())
    {   if (w.isnan()) return w;               // x/NaN
// Now normailsed numbe/infinity
        if (signbit() == w.signbit()) return ZERO128();
        else return MINUSZERO128();
    }
    else if (w.iszero())
    {   if (signbit() == w.signbit()) return PLUSINF128();
        else return MINUSINF128();
    }
    else return (FLOAT_128)((FLOAT160)*this / (FLOAT160)w);
}

// Comparisons

bool FLOAT_128::operator==(FLOAT_128 const& w) const
{   if (isnan() || w.isnan()) return false;
    return (v == w.v);
}

bool FLOAT_128::operator!=(FLOAT_128 const& w) const
{   if (isnan() || w.isnan()) return false;
    return (v != w.v);
}

bool FLOAT_128::operator>(FLOAT_128 const& w) const
{   if (isnan() || w.isnan()) return false;
    return (v > w.v);
}

bool FLOAT_128::operator<(FLOAT_128 const& w) const
{   if (isnan() || w.isnan()) return false;
    return (v < w.v);
}

bool FLOAT_128::operator>=(FLOAT_128 const& w) const
{   if (isnan() || w.isnan()) return false;
    return (v >= w.v);
}

bool FLOAT_128::operator<=(FLOAT_128 const& w) const
{   if (isnan() || w.isnan()) return false;
    return (v <= w.v);
}

NAN128::NAN128()
{   v = ((uint128_t)UINT64_C(0x7fff800000000000))<<64;
}

PLUSINF128::PLUSINF128()
{   v = ((uint128_t)UINT64_C(0x7fff000000000000))<<64;
}

MINUSINF128::MINUSINF128()
{   v = ((uint128_t)UINT64_C(0xffff000000000000))<<64;
}

ZERO128::ZERO128()
{   v = ((uint128_t)UINT64_C(0x0000000000000000))<<64;
}

MINUSZERO128::MINUSZERO128()
{   v = ((uint128_t)UINT64_C(0x8000000000000000))<<64;
}

#endif // !NEED_FLOAT128

void debug(uint64_t hi, uint64_t mid, uint64_t lo, uint32_t x,
              const char* msg = "")
{   std::cout << msg << "0x" << std::hex
              << std::setw(16) << (uint64_t)hi
              << std::setw(16) << (uint64_t)mid
              << std::setw(16) << (uint64_t)lo
              << std::dec << "P" << x << "\r\n";
}

#ifdef NEED_FLOAT160

void debugbin(FLOAT160 v)
{   auto n = std::cout.precision();
    auto ff = std::cout.fill();
    auto fg = std::cout.flags();
    std::cout << std::hex << std::setprecision(16) << std::setfill('0');
    if (v.signbit()) std::cout <<  " -";
    else std::cout << " +";
    std::cout << std::setw(16) << (uint64_t)(v.mantissa()>>64) << ":"
              << std::setw(16) << (uint64_t)v.mantissa()
              << std::dec << "P" << v.exponent() << "\r\n";
    std::cout.precision(n);
    std::cout.fill(ff);
    std::cout.flags(fg);
}

void debug(FLOAT160 v, const char* msg="") // Show low-precision approximation...
{   auto n = std::cout.precision();
    long double d = std::ldexp((long double)v.mantissa(), v.exponent()-128);
    if (v.signbit()) d = -d;
    std::cout << std::setprecision(19) << msg << d;
    debugbin(v);
    std::cout.precision(n);
}

#endif


COMPLEX_128::COMPLEX_128()
{   rr = LF_C(0.0);
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(int32_t n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(int64_t n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(int128_t n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(uint32_t n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(uint64_t n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(uint128_t n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(double n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(long double n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(FLOAT_128 n)
{   rr = n;
    ii = LF_C(0.0);
}

COMPLEX_128::COMPLEX_128(FLOAT_128 r, FLOAT_128 i)
{   rr = r;
    ii = i;
}

COMPLEX_128::COMPLEX_128(COMPLEX_128 const& z)
{   rr = z.rr;
    ii = z.ii;
}

// Casts
// Hmmm - here if I cast a complex value to a scalar one I will just return
// the rr part.

COMPLEX_128::operator int32_t() const
{   return (int32_t)rr;
}

COMPLEX_128::operator int64_t() const
{   return (int64_t)rr;
}

COMPLEX_128::operator int128_t() const
{   return (int128_t)rr;
}

COMPLEX_128::operator uint32_t() const
{   return (uint32_t)rr;
}

COMPLEX_128::operator uint64_t() const
{   return (uint64_t)rr;
}

COMPLEX_128::operator uint128_t() const
{   return (uint128_t)rr;
}

COMPLEX_128::operator double() const
{   return (double)rr;
}

COMPLEX_128::operator long double() const
{   return (long double)rr;
}

COMPLEX_128::operator FLOAT_128() const
{   return rr;
}

// operators

COMPLEX_128 COMPLEX_128::operator+() const
{   return *this;
}

COMPLEX_128 COMPLEX_128::operator-() const
 {   return COMPLEX_128(-rr, -ii);
}

COMPLEX_128 COMPLEX_128::operator+(COMPLEX_128 a) const
{   return COMPLEX_128(rr + a.rr, ii + a.ii);
}

COMPLEX_128 COMPLEX_128::operator-(COMPLEX_128 a) const
{   return COMPLEX_128(rr - a.rr, ii - a.ii);
}

// (a + i b) * (c + i d) = (a c - b d) + i (a d + b c)
//
// The above is horrid for two reasons.
// (1) a*c and other intermediate products may overflow even when
//     the final result is in range.
// (2) The additions and subtractions (note that a, b, c and d may each be
//     either positive or negative) can lead to severe leading-digit
//     cancellation and thus inaccurate results.
//
// The first issue has to be handled using scaling. The second
// via the use of fused-multiply-add.

// Consider a*b + c*d
// Use the sequence
//    abhi = a*b;               // rounded in normal way
//    ablo = fma(a, b, -abhi);  // gets low part of exact product
//    res = fma(c, d, abhi);    // if a*b + c*d has cancellation
//                              // it happens here.
//    res = res + ablo;         // final accurate value.
// To achieve subtraction just negate c (or d) to start with.

COMPLEX_128 COMPLEX_128::operator*(COMPLEX_128 x) const
{   FLOAT_128 a = rr;
    FLOAT_128 b = ii;
    FLOAT_128 c = x.rr;
    FLOAT_128 d = x.ii;
// Here I want scales such that I do not get premature overflow
// or underflow;
    FLOAT_128 scale1 = a.maxabs(b);
    FLOAT_128 scale2 = c.maxabs(d);
    a = a/scale1;
    b = b/scale1;
    c = c/scale2;
    d = d/scale2;
// The real part of the result is based on a*c - b*d;
    FLOAT_128 realpart = c*d;
    FLOAT_128 err = c.fma(-d, realpart);
    realpart = a.fma(b, -realpart) + err;
// The imaginary part is based on a*d + b*c;
    FLOAT_128 imagpart = -b*c;
    err = b.fma(c, imagpart);
    imagpart = a.fma(d, imagpart) + err;
    FLOAT_128 q = scale1*scale2;
    return COMPLEX_128(q*realpart, q*imagpart);
}

COMPLEX_128 COMPLEX_128::operator/(COMPLEX_128 a) const
{   FLOAT_128 q = LF_C(1.0)/(a.rr*a.rr + a.ii*a.ii);
    COMPLEX_128 w = operator*(a.conj());
    return COMPLEX_128(q*w.real(), q*w.imag());
}

// comparisons

bool COMPLEX_128::operator==(COMPLEX_128 const& a) const
{   return rr == a.rr && ii == a.ii;
}

bool COMPLEX_128::operator!=(COMPLEX_128 const& a) const
{   return rr != a.rr || ii != a.ii;
}

// specials for complex values
FLOAT_128 COMPLEX_128::real() const
{   return rr;
}

FLOAT_128 COMPLEX_128::imag() const
{   return ii;
}

FLOAT_128 COMPLEX_128::arg() const
{   abort(); // atan2(ii, rr);
}

FLOAT_128 COMPLEX_128::abs() const
{   abort(); // hypot(rr, ii);
}

// If this is going to overflow it just will.

FLOAT_128 COMPLEX_128::norm() const
{   return rr*rr + ii*ii;
}

COMPLEX_128 COMPLEX_128::conj() const
{   return COMPLEX_128(rr, -ii);
}

#ifdef NEED_FLOAT160

COMPLEX160::COMPLEX160()
{   rr = 0.0_Q;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(int32_t n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(int64_t n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(int128_t n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(uint32_t n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(uint64_t n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(uint128_t n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(double n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(long double n)
{   rr = (FLOAT160)n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(FLOAT160 n)
{   rr = n;
    ii = 0.0_Q;
}

COMPLEX160::COMPLEX160(FLOAT_128 rrr, FLOAT_128 iii)
{   rr = (FLOAT160)rrr;
    ii = (FLOAT160)iii;
}

COMPLEX160::COMPLEX160(FLOAT160 rrr, FLOAT160 iii)
{   rr = rrr;
    ii = iii;
}

COMPLEX160::COMPLEX160(COMPLEX160 const& z)
{   rr = z.rr;
    ii = z.ii;
}

// Casts

COMPLEX160::operator int32_t() const
{   return (int32_t)rr;
}

COMPLEX160::operator int64_t() const
{   return (int64_t)rr;
}

COMPLEX160::operator int128_t() const
{   return (int128_t)rr;
}

COMPLEX160::operator uint32_t() const
{   return (uint32_t)rr;
}

COMPLEX160::operator uint64_t() const
{   return (uint64_t)rr;
}

COMPLEX160::operator uint128_t() const
{   return (uint128_t)rr;
}

COMPLEX160::operator double() const
{   return (double)rr;
}

COMPLEX160::operator long double() const
{   return (long double)rr;
}

COMPLEX160::operator FLOAT160() const
{   return rr;
}

// operators

COMPLEX160 COMPLEX160::operator+() const
{   return *this;
}

COMPLEX160 COMPLEX160::operator-() const
{   return COMPLEX160(-rr, ii);
}

COMPLEX160 COMPLEX160::operator+(COMPLEX160 a) const
{   return COMPLEX160(rr + a.rr, ii + a.ii);
}

COMPLEX160 COMPLEX160::operator-(COMPLEX160 a) const
{   return COMPLEX160(rr - a.rr, ii - a.ii);
}

// Because FLOAT160 has an extended range of exponents I do not need
// to worry about overflow here.

COMPLEX160 COMPLEX160::operator*(FLOAT160 a) const
{   return COMPLEX160(rr*a, ii*a);
}

COMPLEX160 COMPLEX160::operator*(COMPLEX160 a) const
{   return COMPLEX160(rr*a.rr - ii*a.ii, rr*a.ii + ii*a.rr);
}

COMPLEX160 COMPLEX160::operator/(COMPLEX160 a) const
{   FLOAT160 q = a.rr*a.rr + a.ii*a.ii;
    return COMPLEX160((rr*a.rr * ii*a.ii)/q, (rr*a.ii - ii*a.rr)/q);

}

// comparisons
bool COMPLEX160::operator==(COMPLEX160 const& a) const
{   return rr==a.rr && ii==a.ii;
}

bool COMPLEX160::operator!=(COMPLEX160 const& a) const
{   return rr!=a.rr || ii!=a.ii;
}

// specials for complex values
FLOAT160 COMPLEX160::real() const
{   return rr;
}

FLOAT160 COMPLEX160::imag() const
{   return ii;
}

FLOAT160 COMPLEX160::arg() const
{   abort();
}

FLOAT160 COMPLEX160::abs() const
{   abort();
}

FLOAT160 COMPLEX160::norm() const
{   return rr*rr + ii*ii;
}

COMPLEX160 COMPLEX160::conj() const
{   return COMPLEX160(rr, -ii);
}

#endif // NEED_FLOAT160


#ifdef TEST

// This test code is temporary and will vary depending on what I am checking!

// On Intel I will view QUADMATH as reference, while on ARM I will use
// long double for that.


// For testing the elementary functions I start with a view that any of
// the schemes I have for FLOAT_128 should end up with bitwise identical
// representations. On Intel I then have the quadmath library that I can
// use as a reference set of functions, while on ARM I can expect that
// "long double" will always support everything. So where either of those
// can be used I will set things up so I can compare the results from my
// own code against those. The situation where that fails is when I am
// compiling with clang and using the __float128 type that it provides,
// and I am on an Intel machine. Then quadmath will not be available but
// long double will use an 80-bit representation not a 129-bit one.

// The macro "tester(fn)" sets up a definitiion of test##fn that takes
// a FLOAT_128 argument.

#if !defined USE_CLANG_FLOAT128 || defined __aarch64__

#ifdef __aarch64__

// On a Macintosh where long double is no better than double the error
// reports from here will only pick up gross badness.

#define tester(fn)                                                         \
void test##fn(FLOAT_128 v)                                                  \
{   FLOAT_128 r1 = fn(v);                                                   \
    long double vv = (long double)v;                                       \
    long double r2 = std::fn(vv);                                          \
    long double err = (long double)r1 - r2;                                \
    std::cout << #fn << ": "                                               \
              << std::setprecision(36) << r1                               \
              << "\n     " << r2 << " "                                    \
              << "\nRelative error = "                                     \
              << std::setprecision(6) << (err/r2) << "\n\n";               \
}

#else

#include <quadmath.h>

static char buffer[40];

int hexdigit(int n)
{   if (n < 10) return '0' + n;
    else return 'a' + (n - 10);
}

char* hexstring(void* p)
{   unsigned char* q = (unsigned char*)p;
    char* r = &buffer[0];
    for (int i=0; i<16; i++)
    {   int w = *q++;
        *r++ = hexdigit(w & 0xf);
        *r++ = hexdigit((w>>4) & 0xf);
    }
    *r = 0;
    return &buffer[0];
}


#define tester(fn)                                                           \
void test##fn(FLOAT_128 v)                                                    \
{   FLOAT_128 r1 = fn(v);                                                     \
    __float128 vv;                                                           \
    std::memcpy(&vv, &v, 16);                                                \
    __float128 r2 = fn##q(vv);                                               \
    __float128 err;                                                          \
    std::memcpy(&err, &r1, 16);                                              \
    err = err - r2;                                                          \
    std::cout << #fn << ": "                                                 \
              << std::setprecision(36) << r1                                 \
              << "\n     " << hexstring(&r1)                                 \
              << "\n     " << hexstring(&r2)                                 \
              << "\nRelative error = "                                       \
              << std::setprecision(6) << ((double)(err/r2)) << "\n\n";       \
}

#endif // aarch64 vs Intel

tester(exp);
tester(expm1);
tester(log);
tester(log1p);
tester(log10);
tester(log2);
tester(sqrt);
tester(cbrt)

tester(sin);
tester(cos);
tester(asin);
tester(acos);
tester(atan);
tester(sinh);
tester(cosh);
tester(asinh);
tester(acosh);
tester(atanh);

#endif // USE_CLANG_FLOAT128

int main()
{   std::cout << "start\n";

#ifndef USE_CLANG_FLOAT128

//? testexp(LF_C(1.0));
//? testexp(LF_C(17.0));
//? testexp(LF_C(98.0));
//? testexp(-LF_C(33.0));

//? testlog(LF_C(1.5));
//? testlog(LF_C(7653.0));
//? testlog(LF_C(0.0001111));
//? testlog(LF_C(1.00001));

    testsin(LF_C(3.5));
//@ testsin(LF_C(1.5));
//? testsin(LF_C(7653.0));
//? testsin(LF_C(0.0001111));
//? testsin(LF_C(1.00001));

#endif // USE_CLANG_FLOAT128

    FLOAT_128 one = LF_C(1.0);

//? std::cout << std::setprecision(33) << exp(one) << "\n";
//? std::cout << exp(COMPLEX_128(LF_C(5.0), LF_C(5.0))) << "\n";

    return 0;
}

#endif // TEST

// end of float128.cpp
