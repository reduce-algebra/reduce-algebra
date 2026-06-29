// float128.h                                   Copyright (C) 2026 Codemist

#ifndef header_float128_h
#define header_float128_h 1

// $Id: float128.h 7327 2026-03-07 17:06:01Z arthurcnorman $


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


// STATUS:                                                    21 June 2026.
// When built either on an x86_64 using g++ where the quadmath library
// is available, or on aarch64 Linux where "long double" is a 128-bit type
// this should now support all the elementary functions I want both on real
// and on complex arguments.
// As of mid 2026 it seems that the Macintosh does not provide a 128-bit
// floating point type via Xcode and clang. (I see some suggestion that
// a version of g++ via homebrew may have quadmath.h present, but that is
// not a very comfortable path forward). Also the current Xcode does
// not provide <stdfloat> and this the C++23 options... so I need to do
// EVERYTHING in software there!
// Windows/x86_64 is OK with quadmath. Windows/aarch64 awaits a build
// environment that I am happy using and that is stable! But the fallback
// to using software for everything means I can cope come what may.
//
// The potential build options that now work well in at least some cases
// but need finshing off are:
//   Use of the C++23 std::float128_t type which provides arithmetic but
//       does not come with a math library.
//   Compilation using clang where there is a type __float128 and
//       support for real but not complex elementary functions.
//   Configurations where all 128-bit floating point needs to be
//       implemented in software.
// These cases should get sorted out in order to have a fully portable
// rounded setup. The only one that at present is liable to be called
// for is use of clang on Windows on ARM where in some cases it may be
// that long double is just a 64-bit type. At the moment I am not yet
// supporting build there (for a range opf other reasons) so this is not
// urgent.

// OVERVIEW:
// This introduces types FLOAT_128 and COMPLEX_128. A literal for FLOAT_128
// should be presented as for instance LF_C(1.23245e67). The usual range
// of elementary functions should work on FLOAT_128 and COMPLEX_128 and the
// names used are sin, cos, exp, log and so on. Utility functions such
// as frexp and ldexp and tests for NaN and infinity values exist.
// Output via "std::cout <<" is possible but the level of control over
// the print format is limited. Input using "std::cin >>" has not been
// implemented.
//
   
#if defined USE_LONG_DOUBLE
// On the Macintosh and sometimes when compiling for Windows the type
// "long double" is too narrow. In some of those cases if you try to
// run this with USE_LONG_DOUBLE set it will necessarily fail.
 
static_assert(((long double)1.0 + 1.0e-34) != 1.0,
              "long double is not a 128-bit IEEE float");
#endif

#include <cstdint>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <complex>

#include "int128.h"  // for int128_t and uint128_t
#include "bitmaps.h" // for nlz()

// I will defined classes FLOAT_128 and COMPLEX_128 and provide
// a range of elementary functions over them. Since my class differs
// from all built in types the functions can have the simple names
// sin. cos, exp, log etc.

// Here are the scenarios I support:
//  USE_LONG_DOUBLE     long double conforms to 128-bit IEEE, so std::sin.
//  USE_QUADMATH        __float128 is a suitable type, and functions sinq etc
//  USE_CLANG_FLOAT128  __float128, together with sinf128 but no complex fns
//  USE_CXX23_FLOAT128  std::float128_t for arithmetic but no library provided
//  USE_SOFT_FLOAT128   must do everything myself.
// and in general one of those symbols should be defined. If none are then I
// default to USE_SOFT_FLOAT128

// The first two of these cover important practical situations:
//    Linux on ARM can use USE_LONG_DOUBLE.
//    MacOS on ARM can use USE_LONG_DOUBLE.
//    Linux on Intel with g++ can use USE_QUADMATH.
//    MacOS on Intel is uncertain since the default compiler is clang.
//        but that platform is in the process of falling out of support!
//    Windows on Intel using the Mingw version of gcc is OK with USE_QUADMATH.
//    Windows on Intel using Cygwin ditto.
//    Windows on ARM is pending at the momemnt (June 2026).

// The main oddity is when one wished to use clang (which is very reasonable
// and may be the default with some operating systems).

// So the USE_CLANG_FLOAT128 option is desirable even though I will probably
// noty use it a lot. The USE_CXX_FLOAT23 is present with a view to being
// future-proof, but it will really start to make sense when std::sin etc
// all have overfloads for std::float128_t. USE_SOFT_FLOAT128 is there as
// an ultimate fallback!
//
// USE_CLANG_FLOAT128 has an issue that clang does not provide a complex
// library (at present?), so to fill that gap I need me own high precision
// set of complex floating point elementary functions.

#if !defined USE_LONG_DOUBLE && \
    !defined USE_QUADMATH && \
    !defined USE_CLANG_FLOAT128 && \
    !defined USE_CXX23_FLOAT128 && \
    !defined USE_SOFT_FLOAT128
#define USE_SOFT_FLOAT128 1
#endif

#if defined __has_include
#  if __has_include(<bit>)
#    include <bit>
#  endif
#endif

#ifdef __cpp_lib_bit_cast
using std::bit_cast;
#else

#ifndef CSL_BITCAST

// This version will not be constexpr and that is a nuisance. And the
// code here does not do any validity checks on its usage!

template<class S, class T>
S bit_cast(const T& src)
{   S r;
    std::memcpy(&r, &src, sizeof(r));
    return r;
}

#define CSL_BITCAST 1

#endif // CSL_BITCAST
#endif // __cpp_lib_bit_cast

using std::int32_t;
using std::uint32_t;
using std::int64_t;
using std::uint64_t;

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


// These booleans inform me if the type "long double" is an IEEE
// 128-bit float, or if it is at least an Intel-style 80-bit one.
// And failing that it is liable to be just ths same as plain double,
// ie 53-bits of mantissa.

inline constexpr bool longdouble128 = LDBL_MANT_DIG == 113;
inline constexpr bool longdouble80  = LDBL_MANT_DIG == 64;
inline constexpr bool longdouble64  = LDBL_MANT_DIG == 53;

#if defined USE_LONG_DOUBLE

using FLOAT128REP = long double;
#define LF_C(x) ((FLOAT_128)(x ## L))
// Everything provided by standard C++ libraries.

#elif defined USE_QUADMATH

#include <quadmath.h>
// Everything provided by "-quadmath" library
using FLOAT128REP = __float128;
#define LF_C(x) ((FLOAT_128)(x ## Q))

#elif defined USE_CLANG_FLOAT128

#include <cfloat>
// Real elementary functions provided as sinf128 etc, but complex ones needed
using FLOAT128REP = __float128;
#define LF_C(x) ((FLOAT_128)(x ## Q))
#define LLF_C(x) ((FLOAT160)(x ## _Q)
#define NEED_FLOAT160 1
#define NEED_COMPLEX_MATHLIB 1

#elif defined USE_CXX23_FLOAT128

#include <stdfloat>
// Basic arithmetic on std::float128_t present, but all libraries needed here.
using FLOAT128REP = std::float128_t;
#define LF_C(x) ((FLOAT_128)(x ## F128)) 
#define LLF_C(x) ((FLOAT160)(x ## _Q))
#define NEED_FLOAT160 1
#define NEED_REAL_MATHLIB
#define NEED_COMPLEX_MATHLIB 1

#else

// Everything must be done in software.
using FLOAT128REP = uint128_t;
#define LF_C(x) ((FLOAT_128)(x ## _Q))
#define LLF_C(x) ((FLOAT160)(x ## _Q))
#define NEED_FLOAT128 1
#define NEED_FLOAT160 1
#define NEED_REAL_MATHLIB
#define NEED_COMPLEX_MATHLIB 1

#endif // selection of representation for FLPAT128 etc.

// NOTE that at least __float128 as used with quadmath.h, and plausibly
// various other things that FLOAT128REP expands into can need 16 byte
// alignment.

class alignas(16) FLOAT_128
{
private:
    FLOAT128REP v;
public:
// Constuctors
    FLOAT_128();
// I am only providing constructors based on the known-width integer types.
    FLOAT_128(int32_t);
    FLOAT_128(int64_t);
    FLOAT_128(int128_t);
    FLOAT_128(uint32_t);
    FLOAT_128(uint64_t);
    FLOAT_128(uint128_t);
    FLOAT_128(double);
    FLOAT_128(long double);
    FLOAT_128(FLOAT_128 const&);
#if defined USE_QUADMATH || \
    defined USE_CLANG_FLOAT128 || \
    defined USE_CXX23_FLOAT128
// In these cases FLOAT128REP is a floating point type that is not double
// or long double, but it is set up by LF_C(...).
    FLOAT_128(FLOAT128REP a) : v(a)
    {
    }
#endif
// Accessing the representation
// In the next two constructors the "float" and "int" arguments are to
// tag these as accessing the representation not any abstraction. The
// constructors should be called with 0.0f or 0 as their second argument,
// and the value used is ignored.
    FLOAT_128(FLOAT128REP, float);            // construct from a FLOAT128REP
    FLOAT128REP rep() const;
    FLOAT_128(uint128_t x, [[maybe_unused]]int y)  // Inject a bit pattern
    {   v = bit_cast<FLOAT128REP>(x);
    }
    FLOAT_128(uint32_t x, [[maybe_unused]]void* y) // the top 32 bits
    {   v = bit_cast<FLOAT128REP>(((uint128_t)x)<<96);
    }
    FLOAT_128(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4)
    {   uint128_t w = (uint128_t)a1;
        w = (w<<32) | a2;
        w = (w<<32) | a3;
        w = (w<<32) | a4;
        v = bit_cast<FLOAT128REP>(w);
    }
    void getbits(uint64_t& x, uint64_t& y) const // As bit-pattern
    {   uint128_t w = bit_cast<uint128_t>(v);
        x = (uint64_t)(w>>64);
        y = (uint64_t)w;
    }
    uint128_t getbits() const                    // ditto
    {   return bit_cast<uint128_t>(v);
    }
#if defined USE_QUADMATH || \
    defined USE_CLANG_FLOAT128 || \
    defined USE_CXX23_FLOAT128
// In these cases FLOAT128REP is a floating point type that is not double
// or long double, but converting to it using a cast feels nicer than
// needing to call rep().
    operator FLOAT128REP()
    {   return v;
    }
#endif
    uint128_t mantissa() const;
// Useful tests etc
    bool isinf() const;
    bool isnan() const;
    bool isfinite() const;
    bool isnormal() const;
    bool signbit() const;
    bool iszero() const;
// I will have some more specialist tests that I use internally
    bool isinfornan() const;
    FLOAT_128 ldexp(int x) const;
    FLOAT_128 frexp(int& x) const;
    FLOAT_128 abs() const;
    FLOAT_128 maxabs(FLOAT_128) const;
// Casts
    operator int32_t() const;
    operator int64_t() const;
    operator int128_t() const;
    operator uint32_t() const;
    operator uint64_t() const;
    operator uint128_t() const;
    operator double() const;
    operator long double() const;
// Operators
    FLOAT_128 operator+() const;
    FLOAT_128 operator-() const;
    FLOAT_128 operator+(FLOAT_128) const;
    FLOAT_128 operator-(FLOAT_128) const;
    FLOAT_128 operator*(FLOAT_128) const;
    FLOAT_128 operator/(FLOAT_128) const;
    FLOAT_128 fma(FLOAT_128, FLOAT_128) const;
// Comparisons
    bool operator==(FLOAT_128 const&) const;
    bool operator!=(FLOAT_128 const&) const;
    bool operator>(FLOAT_128 const&) const;
    bool operator<(FLOAT_128 const&) const;
    bool operator>=(FLOAT_128 const&) const;
    bool operator<=(FLOAT_128 const&) const;

    friend std::ostream& operator<<(std::ostream& o, FLOAT_128 const& d);
    friend class NAN128;
    friend class PLUSINF128;
    friend class MINUSINF128;
    friend class ZERO128;
    friend class MINUSZERO128;
};

class NAN128 : public FLOAT_128
{
public:
    NAN128();
};

class PLUSINF128 : public FLOAT_128
{
public:
    PLUSINF128();
};

class MINUSINF128 : public FLOAT_128
{
public:
    MINUSINF128();
};

class ZERO128 : public FLOAT_128
{
public:
    ZERO128();
};

class MINUSZERO128 : public FLOAT_128
{
public:
    MINUSZERO128();
};

class COMPLEX_128
{
private:
    FLOAT_128 rr;
    FLOAT_128 ii;
public:
// Constuctors
    COMPLEX_128();
// I am only providing constructors based on the known-width integer types.
    COMPLEX_128(int32_t);
    COMPLEX_128(int64_t);
    COMPLEX_128(int128_t);
    COMPLEX_128(uint32_t);
    COMPLEX_128(uint64_t);
    COMPLEX_128(uint128_t);
    COMPLEX_128(double);
    COMPLEX_128(long double);
    COMPLEX_128(FLOAT_128);
    COMPLEX_128(FLOAT_128, FLOAT_128);
    COMPLEX_128(COMPLEX_128 const&);
// Useful functions
// Casts
    operator int32_t() const;
    operator int64_t() const;
    operator int128_t() const;
    operator uint32_t() const;
    operator uint64_t() const;
    operator uint128_t() const;
    operator double() const;
    operator long double() const;
    operator FLOAT_128() const;
// operators
    COMPLEX_128 operator+() const;
    COMPLEX_128 operator-() const;
    COMPLEX_128 operator+(COMPLEX_128) const;
    COMPLEX_128 operator-(COMPLEX_128) const;
    COMPLEX_128 operator*(COMPLEX_128) const;
    COMPLEX_128 operator/(COMPLEX_128) const;
// comparisons
    bool operator==(COMPLEX_128 const&) const;
    bool operator!=(COMPLEX_128 const&) const;
// specials for complex values
    FLOAT_128 real() const;
    FLOAT_128 imag() const;
    FLOAT_128 arg() const;
    FLOAT_128 abs() const;
    FLOAT_128 norm() const;
    COMPLEX_128 conj() const;

    static COMPLEX_128 NaN()
    {   return COMPLEX_128(NAN128(), NAN128());
    }

    friend std::ostream& operator<<(std::ostream& o, COMPLEX_128 const& d);
};


// Internal to the reading and printing code I do some work to 192 bits...
// The code is here in the header file for its use when the user-defined
// syntax "_Q" is used for the input of FLOAT160 literals.


// add a digit somewhere into the middle of a vector, propagating carries.

// I use this when multiplying two 3-digit numbers, and there can never
// be a carry beyond the 6 digits that the result can have.

inline void addin192(uint64_t n, uint64_t* c, int k)
{   while (n != 0)
    {   c[k] = c[k] + n;
        n = (c[k] < n) ? 1 : 0;
        k++;
    } 
}

// {hi, mid, lo, x} = {hi1, mid1, lo1, x1) * {hi2, mid2, lo2, x2};

inline constexpr void multiply192(
    uint64_t hi1, uint64_t mid1, uint64_t lo1, int32_t x1,
    uint64_t hi2, uint64_t mid2, uint64_t lo2, int32_t x2,
    uint64_t& hi, uint64_t& mid, uint64_t& lo, int32_t& x)
{   if (x1 == INT32_MIN ||
        x2 == INT32_MIN)
    {   hi = mid = lo = 0;  // Special case if either input is zero
        x = INT32_MIN;
        return;
    }
    uint64_t a[3] = {lo1, mid1, hi1};
    uint64_t b[3] = {lo2, mid2, hi2};
    uint64_t c[6] = {0,0,0,0,0,0};
    for (int i=0; i<3; i++)
    {   for (int j=0; j<3; j++)
        {   int k = i+j;
            uint128_t w = ((uint128_t)a[i])*b[j];
            addin192((uint64_t)w, c, k);
            addin192((uint64_t)(w>>64), c, k+1);   
        }
    }
    hi = c[5];
    mid = c[4];
    lo = c[3];
// The raw product could have its top bit clear. If that is so then
// shift left by 1 to normalise.
    if ((hi>>63) == 0)
    {   hi = (hi<<1) | (mid>>63);
        mid = (mid<<1) | (lo>>63);
        lo = (lo<<1) | (c[2]>>63);
        c[2] = (c[2]<<2);
        x1--;
    }
    if ((c[2]>>63) != 0)   // round up if necessary.
        if (++lo == 0)
            if (++mid == 0) hi++;
    x = x1 + x2;
}

// breakfunction is a function that does not do anything! It exists so I can
// put calls of it in while I am debugging and then set breakpoints on
// it. That is sometimes easier than finding the exact point where I
// want the break or breaks every time I start the debugger.

inline constexpr void breakfunction()
{
} 

inline constexpr void power(
    uint64_t& hi, uint64_t& mid, uint64_t& lo, int32_t& x, int n)
{   uint64_t whi = hi, wmid=mid, wlo=lo;
    int32_t wx = x;
    hi = UINT64_C(0x8000000000000000);
    mid = 0;
    lo = 0;
    x = 1;
    while (n != 0)
    {   if (n%2 != 0) multiply192(hi, mid, lo, x,
                                  whi, wmid, wlo, wx,
                                  hi, mid, lo, x); 
         multiply192(whi, wmid, wlo, wx,
                     whi, wmid, wlo, wx,
                     whi, wmid, wlo, wx);
         n = n/2;
    } 
}

inline constexpr void power10(
    uint64_t& hi, uint64_t& mid, uint64_t& lo, int32_t& x, int n)
{   if (n == 0)
    {   hi=UINT64_C(0x8000000000000000);
        mid = lo = 0;
        x = 1;
        return;
    }
    else if (n > 0)
    {   hi=UINT64_C(0xa000000000000000);
        mid = lo = 0;
        x = 4;
    }
    else
    {   n = -n;
        hi = UINT64_C(0xcccccccccccccccc);
        mid = UINT64_C(0xcccccccccccccccc);
        lo = UINT64_C(0xcccccccccccccccd);
        x = -3;
    }
    power(hi, mid, lo, x, n);
}

// Add the integer n

inline constexpr void add192(
    uint64_t n,
    uint64_t& hi, uint64_t& mid, uint64_t& lo, int32_t& x)
{   if (n==0) return;     // add zero to anything does not change it
    uint64_t nhi=0, nmid=0, nlo=0;
    uint32_t nx=0;
    int shift = nlz(n);
    nhi = n << shift;
    nmid = 0;
    nlo = 0;
    nx = 64 - shift;
// Now n is in 192-bit notation.
    if (x == INT32_MIN) x = nx;
// Now I need to shift {nhi,nmid,nlo} right by x-nx places to align it.
    shift = x - nx;
    while (shift >= 64)
    {   nlo = nmid;
        nmid = nhi;
        nhi = 0;
        shift = shift - 64;
    }
    if (shift != 0)
    {   nlo = (nlo>>shift) | (nmid<<(64-shift));
        nmid = (nmid>>shift) | (nhi<<(64-shift));
        nhi = (nhi>>shift);
    }
    bool carry = false;
// Now I can do the addition.
    lo = lo + nlo;
    if (lo < nlo)
    {   mid++;
        if (mid == 0)
        {   hi++;
            if (hi == 0) carry = true;
        }
    }
    mid = mid + nmid;
    if (mid < nmid)
    {   hi++;
        if (hi == 0) carry = true;
    }
    hi = hi + nhi;
    if (hi < nhi) carry = true;
    if (carry)
    {   lo = (lo>>1) | (mid<<63);
        mid = (mid>>1) | (hi<<63);
        hi = (hi>>1) | UINT64_C(0x8000000000000000);
        x++;
    }
}

// Only valid if the integer part is less than 2^64.

inline constexpr uint64_t intpart192(uint64_t hi, int32_t x)
{   if (x<=0) return 0;
    else return hi>>(64-x);
}

// getting the fractional part is much more work that getting the
// integer part because in cases such as 3.0000001 when the integer is
// removed it becomes necessary to re-normalize the residue.

inline constexpr void fracpart192(
    uint64_t& hi, uint64_t& mid, uint64_t& lo, int32_t& x)
{
// When I call this I have just got the value to be such that its integer
// part fitted in uint64_t, and so I know that 0<x<64. Well that is apart
// from a case where (hi:mid:lo) has become zero, so let me filter that
// case out first!
// Also if the integer part was zero what I have is already correct.
    if (x<=0 || (hi==0 && mid==0 && lo==0)) return;
// Shift the bits up to discard an integer part.
    hi = (hi<<x) | (mid>>(64-x));
    mid = (mid<<x) | (lo>>(64-x));
    lo = (lo<<x);
    x = 0;
// There are various cases where the fractional part ends up zero
// or very very tiny.
    if (hi==0 && mid==0 && lo==0)
    {   x = INT32_MIN;   // Input had been exactly an integer.
        return;
    }
// Now I need to normalize.
    if (hi==0 && mid==0)
    {   hi = lo;
        lo = 0;
        x = -128;
    }    
    else if (hi == 0)
    {   hi = mid;
        mid = lo;
        lo = 0;
        x = -64;
    }
// Now hi will be non-zero
    int shift = nlz(hi);
    if (shift != 0)
    {   hi = (hi<<shift) | (mid>>(64-shift));
        mid = (mid<<shift) | (lo>>(64-shift));
        lo = (lo<<shift);
        x -= shift;
    }
}

// The next few compares absolute values of a pair of 192-bit values.

inline constexpr bool gt192(
    uint64_t hi1, uint64_t mid1, uint64_t lo1, int32_t x1,
    uint64_t hi2, uint64_t mid2, uint64_t lo2, int32_t x2)
{   if (x1 > x2) return true;
    if (x1 < x2) return false;
    if (hi1 > hi2) return true;
    if (hi1 < hi2) return false;
    if (mid1 > mid2) return true;
    if (mid1 < mid2) return false;
    if (lo1 > lo2) return true;
    if (lo1 < lo2) return false;
    return false;
}

inline constexpr bool ge192(
    uint64_t hi1, uint64_t mid1, uint64_t lo1, int32_t x1,
    uint64_t hi2, uint64_t mid2, uint64_t lo2, int32_t x2)
{   if (x1 > x2) return true;
    if (x1 < x2) return false;
    if (hi1 > hi2) return true;
    if (hi1 < hi2) return false;
    if (mid1 > mid2) return true;
    if (mid1 < mid2) return false;
    if (lo1 > lo2) return true;
    if (lo1 < lo2) return false;
    return true;
}

inline constexpr bool lt192(
    uint64_t hi1, uint64_t mid1, uint64_t lo1, int32_t x1,
    uint64_t hi2, uint64_t mid2, uint64_t lo2, int32_t x2)
{   return !ge192(hi1, mid1, lo1, x1, hi2, mid2, lo2, x2);
}

inline constexpr bool le192(
    uint64_t hi1, uint64_t mid1, uint64_t lo1, int32_t x1,
    uint64_t hi2, uint64_t mid2, uint64_t lo2, int32_t x2)
{   return !gt192(hi1, mid1, lo1, x1, hi2, mid2, lo2, x2);
}

#ifdef NEED_FLOAT160

// This provides working precision with a 128-bit mantissa. If I have
// to implement 128-bit floats in software I often delegate to this for the
// actual arithmetic. For input/output conversions and for the elementary
// functions this is how I keep accuracy high.

// The representation used here thinks of the top bit of the mantissa
// as having weight "1", so that the mantissa denotes a value in the
// range [1,2) with a non-offset binary exponent. Thus the value
// {false, 0x8000_0000_0000_0000_0000_0000_0000_0000, 0} represents
// 1.0.

class FLOAT160
{
private:
    bool sign;
    int32_t x;
    uint128_t m;
public:
// Constuctors
    constexpr FLOAT160();
    constexpr FLOAT160(int64_t n):sign(),x(),m()
    {   if (n == 0)
        {   m = 0;
            x = INT32_MIN;
            sign = false;
            return;
        }
        m = (int128_t)n;
        if (n >= 0) sign = false;
        else m = -m, sign = true;
        int shift = nlz(m);
        m = m << shift;
        x = 128 - shift;
    }
    constexpr FLOAT160(int32_t x) : FLOAT160((int64_t)x)
    {
    }
    constexpr FLOAT160(int128_t);
    constexpr FLOAT160(uint32_t);
    constexpr FLOAT160(uint64_t);
    constexpr FLOAT160(uint128_t);
    constexpr FLOAT160(double);
    constexpr FLOAT160(long double);
    FLOAT160(FLOAT_128 const&);
    constexpr FLOAT160(FLOAT160 const& v):sign(),x(),m()
    {   sign = v.sign;
        x = v.x;
        m = v.m;
    }
// Accessing the representation
    constexpr FLOAT160(bool, int32_t, uint128_t);
    constexpr bool signbit() const;
    constexpr int32_t exponent() const;
    constexpr void mantissa(uint64_t&, uint64_t&) const;
    constexpr uint128_t mantissa() const
    {   return m;
    }
    constexpr bool iszero() const;
    constexpr void setsignbit(bool);
    constexpr void setexponent(int32_t xx)
    {   x = xx;
    }
    constexpr void setmantissa(uint64_t, uint64_t);
    constexpr void setmantissa(uint128_t mm)
    {   m = mm;
    }
// Useful operations
    FLOAT160 ldexp(int32_t x) const;
    FLOAT160 frexp(int32_t& x) const;
// Casts
    constexpr operator int32_t() const;
    constexpr operator int64_t() const;
    constexpr operator int128_t() const;
    constexpr operator uint32_t() const;
    constexpr operator uint64_t() const;
    constexpr operator uint128_t() const;
    constexpr operator double() const;
    constexpr operator long double() const;
    operator FLOAT_128() const;
// Operators
    constexpr FLOAT160 operator=(FLOAT160 const&);
    constexpr FLOAT160 operator=(FLOAT160&&);
    FLOAT160 operator+=(FLOAT160 const&);
    FLOAT160 operator-=(FLOAT160 const&);
    FLOAT160 operator*=(FLOAT160 const&);
//  fma(a, b) == this*a + b but with only one rounding operation.
    FLOAT160 fma(FLOAT160&, FLOAT160&);
    FLOAT160 operator/=(FLOAT160 const&);
    constexpr FLOAT160 operator+() const;
    constexpr FLOAT160 operator-() const;
    constexpr FLOAT160 operator+(FLOAT160 const&) const;
    constexpr FLOAT160 operator-(FLOAT160 const&) const;
    constexpr FLOAT160 operator*(FLOAT160 const&) const;
    constexpr FLOAT160 operator/(FLOAT160 const&) const;
    constexpr FLOAT160 abs() const;
    constexpr FLOAT160 maxabs(FLOAT160) const;
// Comparisons
    constexpr bool operator==(FLOAT160 const&) const;
    constexpr bool operator!=(FLOAT160 const&) const;
    constexpr bool operator>(FLOAT160 const&) const;
    constexpr bool operator<(FLOAT160 const&) const;
    constexpr bool operator>=(FLOAT160 const&) const;
    constexpr bool operator<=(FLOAT160 const&) const;

    friend std::ostream& operator<<(std::ostream& o, FLOAT160 const& d);
// f160tof128rep() returns a value as a uint128_t that is the bit-pattern
// required for an IEEE-style 128 bit floating point value.
    uint128_t f160tof128rep() const;
    friend class NAN160;
    friend class INF160;
};

class NAN160 : public FLOAT160
{
public:
    NAN160();
};

class INF160 : public FLOAT160
{
public:
    INF160();
};


class COMPLEX160
{
private:
    FLOAT160 rr;
    FLOAT160 ii;
public:
// Constuctors
    COMPLEX160();
// I am only providing constructors based on the known-width integer types.
    COMPLEX160(int32_t);
    COMPLEX160(int64_t);
    COMPLEX160(int128_t);
    COMPLEX160(uint32_t);
    COMPLEX160(uint64_t);
    COMPLEX160(uint128_t);
    COMPLEX160(double);
    COMPLEX160(long double);
    COMPLEX160(FLOAT_128);
    COMPLEX160(FLOAT_128, FLOAT_128);
    COMPLEX160(COMPLEX_128 const&);
    COMPLEX160(FLOAT160);
    COMPLEX160(FLOAT160, FLOAT160);
    COMPLEX160(COMPLEX160 const&);
// Useful tests etc
// Casts
    operator int32_t() const;
    operator int64_t() const;
    operator int128_t() const;
    operator uint32_t() const;
    operator uint64_t() const;
    operator uint128_t() const;
    operator double() const;
    operator long double() const;
    operator FLOAT_128() const;
    operator FLOAT160() const;
    operator COMPLEX_128() const;
// Operators
    COMPLEX160 operator+() const;
    COMPLEX160 operator-() const;
    COMPLEX160 operator+(COMPLEX160) const;
    COMPLEX160 operator-(COMPLEX160) const;
    COMPLEX160 operator*(FLOAT160) const;
    COMPLEX160 operator*(COMPLEX160) const;
    COMPLEX160 operator/(COMPLEX160) const;
// Comparisons
    bool operator==(COMPLEX160 const&) const;
    bool operator!=(COMPLEX160 const&) const;
// Specials for complex values
    FLOAT160 real() const;
    FLOAT160 imag() const;
    FLOAT160 arg() const;
    FLOAT160 abs() const;
    FLOAT160 norm() const;
    COMPLEX160 conj() const;
    friend std::ostream& operator<<(std::ostream& o, COMPLEX160 const& d);
};

// The handling of the user-defined literals such as 1.2e3_Q and
// 0xabcdP22_Q are here in the header file so that the literals
// can be handled at compile-time.


// If I read the numbers in using 192-bits of precision I can be
// confident that the 128-bit version will be accurate. So I can
// work in a fairly naive way.

constexpr inline FLOAT160 string_to_float160(const char* s)
{   FLOAT160 r(0);
// If the literal starts with "0x" or "0X" it is in hex notation.
    if (*s == '0' && (s[1] == 'x' || s[1] == 'X'))
    {   s += 2;
        r.setexponent(0);
        r.setmantissa(0);
        int i = 32;
// For hex input the digits are put in from the most significant part
// of the mantissa downwards. The result is that if there are only a few
// digits given the value is effectively padded with zeros, while if
// there are more than 32 the excess ones are just discarded. The exponent
// is zero by default. Unless the value is given as zero its top bit
// will be forced to be a 1 so that it is properly normalised. Note that
// leading zeros are skipped.
// Thus:
//   0x0008_Q           gives 0.5
//   0x4_Q              is treated as if it has been 0xC_Q which is 0.75
//   0x9999..99999_Q    [with as many "9s" as you want where I have put
//                       the "..."] is 0.6, but it does not round the final
//                       stored "9" to an "a".
//   0x1234_5678_9abc_Q  illustrates underscores that may help legibility.
// For hex input I am taking the view that the user should not write
// more than 32 digits and then expect the excess ones to be used to
// round the main result. So
//     0x1111_1111_1111_1111_1111_1111_1111_11111_ffff_Q
// will still have a "1" in its least significant position.
        while (*s == '0') s++;
        for (;;)
        {   if (*s == '_') s++;  // One can put underscores as spacing.
            int c = *s;
            if ('0' <= c && c <= '9') s++, c = c - '0';
            else if ('a' <= c && c <= 'f') s++, c = 10 + c - 'a'; 
            else if ('A' <= c && c <= 'F') s++, c = 10 + c - 'A';
            else break;
            i--;
            if (i >= 0) r.setmantissa(r.mantissa() | ((uint128_t)c)<<(4*i));
        }
        if (r.mantissa() == 0)
        {   r.setexponent(INT32_MIN);
            return r;
        }
        r.setmantissa(r.mantissa() | ((uint128_t)1)<<127); 
        if (*s == 'p' || *s == 'P')
        {   r.setexponent(atoi(s+1));
        }
        return r;
    }
// Now for decimal input.
    uint64_t hi=0, mid=0, lo=0;
    int32_t x = INT32_MIN;
    while (*s == '0') s++;
    int count = 0;
    int dx = 0;
    while ('0' <= *s && *s <= '9')
    {   multiply192(UINT64_C(0xa000000000000000), 0, 0, 4,
                    hi, mid, lo, x,
                    hi, mid, lo, x);
        add192(*s++ - '0', hi, mid, lo, x);
        count++;
    }
    if (*s == '.')
    {   s++;
        while ('0' <= *s && *s <= '9')
        {   if (count < 42)   // I ignore digits beyond this limit.
            {   multiply192(UINT64_C(0xa000000000000000), 0, 0, 4,
                            hi, mid, lo, x,
                            hi, mid, lo, x);
                add192(*s - '0', hi, mid, lo, x);
                dx--;
                count++;
            }
            s++;
        }
    }
    if (*s == 'e') dx += std::atoi(s+1);
    uint64_t hi1=0, mid1=0, lo1=0;
    int32_t x1=0;
    power10(hi1, mid1, lo1, x1, dx);
    multiply192(hi1, mid1, lo1, x1, hi, mid, lo, x, hi, mid, lo, x);
    uint128_t m = (((uint128_t)hi)<<64) | mid;
// Round.
    if ((lo == (UINT64_C(1)<<63) && (m&1)!=0) ||
        (lo > (UINT64_C(1)<<63)))
    {   m++;
        if (m == 0)
        {   m = ((uint128_t)1)<<127;
            x++;
        }
    }
    r.setmantissa(m);
    r.setexponent(x);
    return r;
}

inline constexpr FLOAT160 operator ""_Q(const char* s)
{   return string_to_float160(s);
}

// I now include definitions of some things that get used by elem128.cpp
// where otherwise I get warnings about inline functions used but not
// defined.

// Here p={hi,lo} and q are values each with their top bit set. I
// want to set quot=p/q and rem=p%q. But note that it can be that
// hi>=q in which case the quotient would have 129 bits - so I return
// the top one as a boolean result.

// The version here works bit by bit which is unduly slow. I could
// do a lot better using something like
//    uint128_t q1 = hi / ((q>>64)+1);
// to get a slight underestimate for the top 64-bits of the quotient!
// But that optimisation can come later when I have things working
// correctly!

constexpr bool divide128(uint128_t hi, uint128_t lo, uint128_t q,
                         uint128_t& quot, uint128_t rem)
{   quot = rem = 0;
    bool bit128 = (hi>=q);
    if (bit128) hi -= q;
    quot = 0;
// I want to replace this with a version that uses division of
// 128-bit values by 64-bit ones rather than working one bit at a time.
    for (int i=0; i<128; i++)
    {   if ((hi>>127) != 0)
        {   quot = (quot<<1) | 1;
            hi = (hi<<1 | lo>>127) - q;
            lo = lo << 1;
        }
        else
        {   hi = (hi<<1 | lo>>127);
            lo = lo << 1;
            quot = quot << 1;
            if (hi >= q)
            {   hi -= q;
                quot |= 1;
            }
        }
    }
    rem = hi;
    return bit128;
}

constexpr FLOAT160::operator long double() const
{
#ifdef __cpp_lib_constexpr_cmath
    long double r = std::ldexp((long double)m, x-128);
#else
    long double r = (long double)m;
    if (x-128 > 0) for (int i=0; i<x-128; i++) r = 2.0L*r;
    else for (int i=0; i<128-x; i++) r = 0.5L*r;
#endif
    return sign ? -r : r;
}

constexpr FLOAT160 FLOAT160::operator+(FLOAT160 const& b) const
{   if (iszero())
    {   if (b.iszero())     // Ha ha (-0.0) + (-0.0) should return (-0.0).
        {   if (signbit())  // other combinations of zeros give +0.0.
            {   if (b.signbit()) return *this;
                else return b;
            }
            else return *this;
        }
        else return b;
    }
    else if (b.iszero()) return *this;
    long double xx = (long double)*this;
    long double yy = (long double)b;
    long double rr = xx+yy;
    FLOAT160 a = *this;
// Ensure that |a| >= |b|. This is useful when I come to aligning the two
// values and also for subtraction.
    FLOAT160 bb = b;
    if (x < bb.x ||
        (x == bb.x && m < bb.m))
    {   FLOAT160 w = a;
        a = bb;
        bb = w;
    }
    bool subtract = false;
    bool negate = false;
// Now look at the signs.
    if (a.sign)
    {   negate = true;
        if (!bb.sign) subtract = true;
    }
    else if (bb.sign) subtract = true;
// I can now shift bb right by ax-bx bits. I keep whatever is shifted
// out in guard.
    uint128_t guard = 0;
    int shift = a.x - bb.x;
    if (shift > 128) bb.m = 0;
    else if (shift == 128)
    {   guard = bb.m;
        bb.m = 0;
    }
    else if (shift != 0)
    {   guard = bb.m << (128-shift);
        bb.m = bb.m >> shift;
    }
// Now bb has been shifted so is aligned with a and I can either add or
// subtract.
    if (!subtract)
    {   a.m = a.m + bb.m;
        if (a.m < bb.m) // overflowed
        {   guard = (guard>>1) | (a.m<<127);
            a.m = topbit128() | (a.m>>1);
            a.x++;
        }
    }
    else
    {   a.m = a.m - bb.m;
// If the two values started off equal then guard will be zero so if I
// subtract I will have a.m==0 and guard==0. In other cases I can need to
// shift left so I end up with a normalized value. I can only ever need to
// shift by up to 127 bits.
        int shift = nlz(a.m);
        if (shift != 0)
        {   a.m = (a.m<<shift) | (guard>>(128-shift));
            guard = guard<<shift;
            a.x -= shift;
        }        }
// I now want to round.
    if (guard > topbit128() ||
        (guard == topbit128() && (a.m&1) != 0))
    {   a.m++;
        if (a.m == 0)
        {   a.m = topbit128();
            a.x++;
        }
    }
    if (negate) a.sign = true;
    long double mine = (long double)a;
    if (std::abs((mine-rr)/rr) > 0.001L) breakfunction();
    return a;
}

constexpr FLOAT160 FLOAT160::operator*(FLOAT160 const& rhs) const
{   long double xx = (long double)*this;
    long double yy = (long double)rhs;
    long double rr = xx*yy;
    FLOAT160 r;
    r.sign = sign != rhs.sign;
    if (m == 0 || rhs.m == 0)
    {   r.m = 0;
        r.x = INT32_MIN;
        return r;
    }
    r.x = x + rhs.x;
    uint128_t ahi = m >> 64;
    uint128_t alo = m - (ahi<<64);
    uint128_t bhi = rhs.m >> 64;
    uint128_t blo = rhs.m - (bhi<<64);
    uint128_t hi = ahi * bhi;
    uint128_t mid1 = ahi * blo;
    uint128_t mid2 = alo * bhi;
    uint128_t lo = alo * blo;
    hi = hi + (mid1>>64) + (mid2>>64);
    mid1 = mid1 << 64;
    mid2 = mid2 << 64;
    lo = lo + mid1;
    if (lo < mid1) hi++;
    lo = lo + mid2;
    if (lo < mid2) hi++;
// Now (hi,lo) should be a full 256-bit product of the mantissas.
    if (!topbit128(hi))
    {   hi = (hi<<1) | (lo>>127);
        lo = lo << 1;
        r.x--;
    }
// Even if I round up here that can not cause the high part of the
// result to overflow.
    if (lo > topbit128() ||
        (lo == topbit128() && (hi&1) != 0)) hi++;
    r.m = hi;
    long double mine = (long double)r;
    if (std::abs((mine-rr)/rr) > 0.001L) breakfunction();
    return r;
}

constexpr FLOAT160 FLOAT160::operator/(FLOAT160 const& rhs) const
{   long double xx = (long double)*this;
    long double yy = (long double)rhs;
    long double rr = xx/yy;
    FLOAT160 r;
    bool negative = sign != rhs.sign;
    if (m == 0)
    {   r.m = 0;
        r.x = INT32_MIN;
        r.sign = sign != rhs.sign;
        return r;
    }
    if (rhs.m == 0)
    {   r.m = 0;
        r.x = INT32_MAX;
        r.sign = negative;
        return r;
    }    
    uint128_t am = m, bm = rhs.m;
    int32_t ax = x, bx = rhs.x;
    r.sign = negative;
    r.x = ax - bx;
// Now I want r.m = (a.m<<128)/b.m with minor adjustment depending on where
// the top bit falls.
    uint128_t remainder = 0;
    bool top = divide128(am, 0, bm, r.m, remainder);
    if (top)
    {   remainder = (r.m<<127) | (remainder>>1);
        r.m = topbit128() | (r.m>>1);
        r.x++;
    }
    if (remainder > bm/2 ||
        (remainder == bm/2 && (r.m&1) != 0)) r.m++;
    long double mine = (long double)r;
    if (std::abs((mine-rr)/rr) > 0.001L) breakfunction();
    return r;
}

constexpr bool FLOAT160::operator==(const FLOAT160& a) const
{   return sign==a.sign && x==a.x && m==a.m;
}

constexpr bool FLOAT160::operator!=(const FLOAT160& a) const
{   return sign!=a.sign || x!=a.x || m!=a.m;
}

constexpr bool FLOAT160::operator>(const FLOAT160& a) const
{   if (sign!=a.sign) return a.sign;
    if (x!=a.x) return x > a.x;
    return m > a.m;
}

constexpr bool FLOAT160::operator>=(const FLOAT160& a) const
{   if (sign!=a.sign) return a.sign;
    if (x!=a.x) return x > a.x;
    return m >= a.m;
}

constexpr bool FLOAT160::operator<(const FLOAT160& a) const
{   if (sign!=a.sign) return sign;
    if (x!=a.x) return x < a.x;
    return m < a.m;
}

constexpr bool FLOAT160::operator<=(const FLOAT160& a) const
{   if (sign!=a.sign) return sign;
    if (x!=a.x) return x < a.x;
    return m <= a.m;
}

constexpr FLOAT160 FLOAT160::operator-(FLOAT160 const& rhs) const
{   return operator+(-rhs);
}

constexpr FLOAT160 FLOAT160::operator-() const
{   FLOAT160 r;
    r.sign = !sign;
    r.x = x;
    r.m = m;
    return r;
}

constexpr FLOAT160 FLOAT160::abs() const
{   return FLOAT160(false, x, m);
}

constexpr bool FLOAT160::iszero() const
{   return m == 0;
}

constexpr FLOAT160::FLOAT160():sign(),x(),m()
{   m = 0;
    x = INT32_MIN;
    sign = false;
}

// Build a FLOAT160 by specifying exponent and mantissa.

constexpr FLOAT160::FLOAT160(bool ss, int32_t xx, uint128_t mm):
                             sign(ss),x(xx),m(mm)
{
}

constexpr FLOAT160::FLOAT160(long double f):sign(),x(),m()
{   sign = std::signbit(f); // So that signed zeros transfer properly.
    if (f == 0.0L)
    {   m = 0;
        x = INT32_MIN;
        return;
    }
    if (sign) f = -f;
    int xx = 0;
// Until C++23 frexp and ldexp are not constexpr, so until then I use
// code that should be portable but which may be slow.
#ifdef __cpp_lib_constexpr_cmath
// I will separate mantissa and exponent.
    long double f1 = std::frexp(f, &xx);
// Now if I multiply the mantissa by 2^64 its integer part should be the
// top 64 bits.
    long double f2 = std::ldexp(f1, 64);
    uint64_t hi = (uint64_t)f2;
// Subtract that integer part off and again multiply by 2^64 and then
// I get the next 64 bits. If long double is not terribly long this
// will consist mostly of zero bits. But the scheme used here should apply
// regardless of how narrow or how wide long double is.
    long double f3 = std::ldexp(f2 - (long double)hi, 64);
#else
    xx = 0;
    long double f1 = f;
    while (f1 >= 1.0L)
    {   f1 = 0.5L*f1;
        xx++;
    }
    while (f1 < 0.5L)
    {   f1 = 2.0L*f1;
        xx--;
    }
    for (int i=0; i<64; i++) f1 = 2.0L*f1;
    uint64_t hi = (uint64_t)f1;
    long double f3 = f1 - (long double)hi;
    for (int i=0; i<64; i++) f3 = 2.0L*f3;
#endif
    uint64_t lo = (uint64_t)f3;
// The versions of long double that might be in use have 53, 64 and 113
// mantissa bits (including the hidden bit). So in all these cases
// the 128-bit value {hi,lo} will have captured them all, and the
// way I have done things means that what used to be a hidden bit is
// now explicitly represented.
    m = ((uint128_t)hi)<<64 | lo;
// is not yet normalised, but we should have f = m*2^(xx-128);
    x = xx;
    int shift = nlz(m);
    m = m << shift;
    x = x - shift;
}

constexpr FLOAT160::FLOAT160(double x):FLOAT160((long double)x)
{
}

constexpr bool FLOAT160::signbit() const
{   return sign;
}

constexpr void FLOAT160::setsignbit(bool ss)
{   sign = ss;
}

constexpr FLOAT160 FLOAT160::operator=(FLOAT160 const& rhs)
{   m = rhs.m;
    x = rhs.x;
    sign = rhs.sign;
    return *this;
}

constexpr FLOAT160 FLOAT160::operator=(FLOAT160&& rhs)
{   m = rhs.m;
    x = rhs.x;
    sign = rhs.sign;
    return *this;
}

constexpr int32_t FLOAT160::exponent() const
{   return x;
}

// Note that the casts to unsigned integers ignore the sign of the
// floating point value. Well in such cases the value is outside the
// range of the integer type so such usage would give "undefined behaviour"
// so I do not worry too much. But I may rely on my own behaviour here
// in later parts of this code.

constexpr FLOAT160::operator uint64_t() const
{   if (x <= 0) return 0;
    else return (uint64_t)(m>>(128-x));
}

constexpr FLOAT160::operator double() const
{
#ifdef  __cpp_lib_constexpr_cmath
    double r = std::ldexp((double)m, x-128);
#else
    double r = (double)m;
    if (x-128 > 0) for (int i=0; i<x-128; i++) r = 2.0L*r;
    else for (int i=0; i<128-x; i++) r = 0.5L*r;
#endif
    return sign ? -r : r;
}

#endif // NEED_FLOAT160

inline FLOAT_128 ldexp(FLOAT_128 v, int x)
{   return v.ldexp(x);
}

inline FLOAT_128 frexp(FLOAT_128 v, int* x)
{   return v.frexp(*x);
}

inline bool isinf(FLOAT_128 v)
{   return v.isinf();
}

inline bool isfinite(FLOAT_128 v)
{   return v.isfinite();
}

inline bool isnan(FLOAT_128 v)
{   return v.isinf();
}

inline bool isnormal(FLOAT_128 v)
{   return v.isnormal();
}

inline bool signbit(FLOAT_128 v)
{   return v.signbit();
}

inline bool iszero(FLOAT_128 v)
{   return v.iszero();
}

// I need to declare all the FLOAT_128 and COMPLEX_128 elementary functions
// so that people who #include this header will know about them. I declare
// versions that work on double and std::complex<double> too because that
// will be relevant for functions that are not part of the C++ standard but
// are ones I provide. Eg the trig functions that work in degrees rather
// than radians.


// Here I declare complex variants of a number of things that will not
// actually be needed. Notably the trig functions that work in degrees
// rather than radians. I view this as fairly harmless.

#define external_declaration(name)                               \
  extern double name(double);                                    \
  extern std::complex<double> name(const std::complex<double>&); \
  extern FLOAT_128 name(FLOAT_128);                                \
  extern COMPLEX_128 name(COMPLEX_128);

#define external_declaration_2(name)                       \
  extern double name(double, double);                      \
  extern std::complex<double> name(std::complex<double>&,  \
                                   std::complex<double>&); \
  extern FLOAT_128 name(FLOAT_128,FLOAT_128);                 \
  extern COMPLEX_128 name(COMPLEX_128,COMPLEX_128);

external_declaration(acos)                   
external_declaration(acosd)               
external_declaration(acosh)                  
external_declaration(acot)              
external_declaration(acotd)               
external_declaration(acoth)             
external_declaration(acsc)              
external_declaration(acscd)               
external_declaration(acsch)             
external_declaration(asec)              
external_declaration(asecd)               
external_declaration(asech)             
external_declaration(asin)                   
external_declaration(asind)               
external_declaration(asinh)                  
external_declaration(atan)                   
external_declaration(atand)               
external_declaration(atanh)                  
external_declaration(cbrt)                   
external_declaration(cos)                    
external_declaration(cosd)                
external_declaration(cosh)                   
external_declaration(cot)               
external_declaration(cotd)                
external_declaration(coth)              
external_declaration(csc)               
external_declaration(cscd)                
external_declaration(csch)              
external_declaration(exp)                    
external_declaration(expm1)                  
external_declaration(ln)                     
external_declaration(log)                    
external_declaration(log10)                  
external_declaration(log1p)                  
external_declaration(log2)                   
external_declaration(sec)               
external_declaration(secd)                
external_declaration(sech)              
external_declaration(sin)                    
external_declaration(sind)                
external_declaration(sinh)                   
external_declaration(sqrt)                   
external_declaration(rsqrt)             
external_declaration(tan)                    
external_declaration(tand)                
external_declaration(tanh)                   

external_declaration_2(atan2)            
external_declaration_2(atan2d)        
external_declaration_2(expt)             
external_declaration_2(hypot)            

#endif // header__float128_h

// end of float128.h

