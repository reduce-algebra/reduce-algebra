// "int128_t.h":  128 bit integer types for C++
//                             Copyright Jason Lee, Arthur Norman 2013-2023

// $Id$
  
#ifndef __INT128_T__
#define __INT128_T__

/*
If you go "#include "int128_t.h" you should end up with two types -
uint128_t and int128_t for wide integers. If these are supported by
your C++ compiler directly (possibly with names like unsigned __int128
and __int128) then the native versions will be used. Otherwise classes
with the relevant names will be introduced with most arithmetic operators
overloaded to use them. You are expected to have the following two lines in
your "configure.ac" to check whether there are suitable built-in types, and
then of course if relevant "config.h" must be loaded before this header file.
        AC_CHECK_TYPES([__int128, unsigned __int128])
        AC_CHECK_TYPES([int128_t, uint128_t])

The INTENT is that when this header has been #included that the two types
int128_t and uint128_t should be available for use within the following code
almost as if they were part of the system in the way that std::int64_t etc
are available. I use this with the CSL and Reduce systems and the 128-bit
types suffice for that: I have NOT tested everything heavily beyond that so
there can be a range of possible faults. And some of the C++ coding may
be ugly or otherwise bad. The unsigned part is was originally by Jason Lee
and should be robust (apart from where I altered it) but the signed variant
and the way that the code tests for existing native 129-bit types is newer
and and improvements from any C++ expert would be most welcome.

I have also not worried very much about performance-tuning of the signed
code. The unsigned version had some care to avoid unnecessary work, but here
my stance is that a computer that does not support native 128-bit will be
slow at big arithmetic whatever I do, so hurtying it a bit mnore will not
upset me too much. A C++ expert may want to address that too!

I have a collection of uses of "typename enable_if<std::is_arithetic<..."
in here that is sufficient to resolve some ambiguities that arose in use
with CSL, but I have not put that in everywhere - just in enough places to
support my current usage. Others who pick this up might want to review
and extent that!

Copyright (c) 2013 - 2017 Jason Lee @ calccrypto at gmail.com
              2020 - 2023 Arthur Norman

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

With much help from Auston Sterling

Thanks to Stefan Deigmo?=ller for finding
a bug in operator*.

Thanks to Frano?=ois Dessenne for convincing me
to do a general rewrite of this class.


This code incorporated the Jason Lee code but has been re-worked by Arthur
Norman, 2020-, and now provides both signed and unsigned 128-bit types called
uint128_t and int128_t, and to arrange that it can always be loaded as a
header-only library that checks HAVE_INT128_T (etc) as set up using autoconf
to decide how it will support the required types.
*/


// Tidy up re possible 128-bit arithmetic support. The required types may
// already exist with names such as __int128 or int128_t. If neither of those
// is available I set up an emulation that uses 64-bit arithmetic as its
// base but provides a class that should behave like the 128-bit integer
// type that I really want.

// I want this to be a standalone header file that could be used outside
// CSL, and so I include the C++ header files that it used and I will refer
// to things as e.g. std::uint64_t even though through CSL I have a "using"
// directive to render the "std::" unnecessary.

#include <cinttypes>
#include <cstdint>
#include <string>

// Note that even if the C++ environment provides a type called "int128_t"
// it should not be in std::, and so I should expect to access it directly.

#if !defined HAVE_UINT128_T && defined HAVE_UNSIGNED___INT128
typedef unsigned __int128 uint128_t;
#define HAVE_UINT128_T 1
#endif // !defined HAVE_UINT128_T && defined HAVE_UNSIGNED___INT128

#if !defined HAVE_INT128_T && defined HAVE___INT128
typedef __int128 int128_t;
#define HAVE_INT128_T 1
#endif // !defined HAVE_INT128_T && defined HAVE___INT128

#if !defined HAVE_UINT128_T
class uint128_t;
#endif

#if !defined HAVE_INT128_T
class int128_t;
#endif

#ifdef HAVE_UINT128_T

// I provide getUPPER(), getLOWER() and PACK128() for conversions between
// unsigned 128-bit integers and pairs of unsigned 64-bit values.

namespace INT128
{

inline std::uint64_t getUPPER(uint128_t a)
{   return a >> 64;
}

inline std::uint64_t getLOWER(uint128_t a)
{   return static_cast<std::uint64_t>(a);
}

inline uint128_t PACK128(std::uint64_t high, std::uint64_t low)
{   return uint128_t(high)<<64 | low;
}

inline bool TOP_BIT(uint128_t a)
{   return (a >> 127) != 0;
}

inline uint128_t UNSIGNED_FLIP_TOP_BIT(uint128_t a)
{   return a ^ (uint128_t(1)<<127);
}

};

#else // HAVE_UINT128_T

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <utility>

class uint128_t
{
private:
    std::uint64_t UPPER, LOWER;

public:
    // Constructors
    uint128_t();
    uint128_t(const uint128_t & rhs);
    uint128_t(uint128_t && rhs);
    uint128_t(int128_t rhs);

    template <typename T>
    uint128_t(const T & rhs)
        : UPPER(0), LOWER(rhs)
    {   static_assert(std::is_integral <T>::value,
                      "Input argument type must be an integer.");
    }

    template <typename S, typename T> uint128_t(const S & upper_rhs,
            const T & lower_rhs)
        : UPPER(upper_rhs), LOWER(lower_rhs)
    {   static_assert(std::is_integral <S>::value &&
                      std::is_integral <T>::value
                      , "Input argument types must be integers.");
    }

    //  RHS input args only

    // Assignment Operator
    uint128_t operator=(const uint128_t & rhs);
    uint128_t operator=(uint128_t && rhs);
    uint128_t operator=(int128_t rhs);

    template <typename T> uint128_t operator=(const T & rhs)
    {   static_assert(std::is_integral <T>::value,
                      "Input argument type must be an integer.");
        UPPER = 0;
        LOWER = rhs;
        return *this;
    }

    // Typecast Operators
    operator bool() const;
    operator std::uint8_t() const;
    operator std::uint16_t() const;
    operator std::uint32_t() const;
    operator std::uint64_t() const;
    operator std::int64_t() const;
    operator int128_t() const;

    // Bitwise Operators
    uint128_t operator&(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
    operator&(const T & rhs) const
    {   return uint128_t(0, LOWER & static_cast<std::uint64_t>(rhs));
    }

    uint128_t & operator&=(const uint128_t & rhs);

    template <typename T> uint128_t & operator&=(const T & rhs)
    {   UPPER = 0;
        LOWER &= rhs;
        return *this;
    }

    uint128_t operator|(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
    operator|(const T & rhs) const
    {   return uint128_t(UPPER, LOWER | static_cast<std::uint64_t>(rhs));
    }

    uint128_t & operator|=(const uint128_t & rhs);

    template <typename T> uint128_t & operator|=(const T & rhs)
    {   LOWER |= static_cast<std::uint64_t>(rhs);
        return *this;
    }

    uint128_t operator^(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
    operator^(const T & rhs) const
    {   return uint128_t(UPPER, LOWER ^ static_cast<std::uint64_t>(rhs));
    }

    uint128_t & operator^=(const uint128_t & rhs);

    template <typename T> uint128_t & operator^=(const T & rhs)
    {   LOWER ^= static_cast<std::uint64_t>(rhs);
        return *this;
    }

    uint128_t operator~() const;

    // Bit Shift Operators
    uint128_t operator<<(const uint128_t & rhs) const;

    template <typename T> uint128_t operator<<(const T & rhs) const
    {   return *this << uint128_t(rhs);
    }

    uint128_t & operator<<=(const uint128_t & rhs);

    template <typename T> uint128_t & operator<<=(const T & rhs)
    {   *this = *this << uint128_t(rhs);
        return *this;
    }

    uint128_t operator>>(const uint128_t & rhs) const;

    template <typename T> uint128_t operator>>(const T & rhs) const
    {   return *this >> uint128_t(rhs);
    }

    uint128_t & operator>>=(const uint128_t & rhs);

    template <typename T> uint128_t & operator>>=(const T & rhs)
    {   *this = *this >> uint128_t(rhs);
        return *this;
    }

    // Logical Operators
    bool operator!() const;
    bool operator&&(const uint128_t & rhs) const;
    bool operator||(const uint128_t & rhs) const;

    template <typename T> bool operator&&(const T & rhs)
    {   return static_cast <bool> (*this && rhs);
    }

    template <typename T> bool operator||(const T & rhs)
    {   return static_cast <bool> (*this || rhs);
    }

    // Comparison Operators
    bool operator==(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator==(const T & rhs) const
    {   return (!UPPER && (LOWER == static_cast<std::uint64_t>(rhs)));
    }

    bool operator!=(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator!=(const T & rhs) const
    {   return (UPPER | (LOWER != static_cast<std::uint64_t>(rhs)));
    }

    bool operator>(const uint128_t & rhs) const;

    template <typename T> bool operator>(const T & rhs) const
    {   return (UPPER || (LOWER > static_cast<std::uint64_t>(rhs)));
    }

    bool operator<(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator<(const T & rhs) const
    {   return (!UPPER)?(LOWER < static_cast<std::uint64_t>(rhs)):false;
    }

    bool operator>=(const uint128_t & rhs) const;

    template <typename T> bool operator>=(const T & rhs) const
    {   return ((*this > rhs) | (*this == rhs));
    }

    bool operator<=(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator<=(const T & rhs) const
    {   return ((*this < rhs) | (*this == rhs));
    }

    // Arithmetic Operators
    uint128_t operator+(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
    operator+(const T & rhs) const
    {   return uint128_t(UPPER + ((LOWER + static_cast<std::uint64_t>(rhs)) <
                                  LOWER), LOWER + static_cast<std::uint64_t>(rhs));
    }

    uint128_t & operator+=(const uint128_t & rhs);

    template <typename T> uint128_t & operator+=(const T & rhs)
    {   UPPER = UPPER + ((LOWER + rhs) < LOWER);
        LOWER = LOWER + rhs;
        return *this;
    }

    uint128_t operator-(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
    operator-(const T & rhs) const
    {   return uint128_t(static_cast<std::uint64_t>(
                             UPPER - ((LOWER - rhs) > LOWER)),
                         static_cast<std::uint64_t>(LOWER - rhs));
    }

    uint128_t & operator-=(const uint128_t & rhs);

    template <typename T> uint128_t & operator-=(const T & rhs)
    {   *this = *this - rhs;
        return *this;
    }

    uint128_t operator*(const uint128_t & rhs) const;

    template <typename T> uint128_t operator*(const T & rhs) const
    {   return *this * uint128_t(rhs);
    }

    uint128_t & operator*=(const uint128_t & rhs);

    template <typename T> uint128_t & operator*=(const T & rhs)
    {   *this = *this * uint128_t(rhs);
        return *this;
    }

private:
    std::pair <uint128_t, uint128_t> divmod(const uint128_t & lhs,
                                            const uint128_t & rhs) const;

public:
    uint128_t operator/(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
    operator/(const T & rhs) const
    {   return *this / uint128_t(rhs);
    }

    uint128_t & operator/=(const uint128_t & rhs);

    template <typename T> uint128_t & operator/=(const T & rhs)
    {   *this = *this / uint128_t(rhs);
        return *this;
    }

    uint128_t operator%(const uint128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
    operator%(const T & rhs) const
    {   return *this - (rhs * (*this / rhs));
    }

    uint128_t & operator%=(const uint128_t & rhs);

    template <typename T> uint128_t & operator%=(const T & rhs)
    {   *this = *this % uint128_t(rhs);
        return *this;
    }

    // Increment Operator
    uint128_t & operator++();
    uint128_t operator++(int);

    // Decrement Operator
    uint128_t & operator--();
    uint128_t operator--(int);

    // Nothing done since promotion doesn't work here
    uint128_t operator+() const;

    // two's complement
    uint128_t operator-() const;

    // Get private values
    const std::uint64_t & upper() const
    {   return UPPER;
    }
    const std::uint64_t & lower() const
    {   return LOWER;
    }

    // Get bitsize of value
    std::uint8_t bits() const;

    // Get string representation of value
    std::string str(std::uint8_t base = 10,
                    const unsigned int & len = 0) const;
};

namespace INT128
{

inline std::uint64_t getUPPER(uint128_t a)
{   return a.upper();
}

inline std::uint64_t getLOWER(uint128_t a)
{   return a.lower();
}

inline uint128_t PACK128(std::uint64_t high, std::uint64_t low)
{   return uint128_t(high, low);
}

inline bool TOP_BIT(uint128_t a)
{   return (getUPPER(a) >> 63) != 0;
}

inline uint128_t UNSIGNED_FLIP_TOP_BIT(uint128_t a)
{   return uint128_t(getUPPER(a) ^ static_cast<std::uint64_t>(1)<<63,
                     getLOWER(a));
}

};

//== // Give uint128_t type traits
//== namespace std    // This is probably not a good idea
//== {
//== template <> struct is_arithmetic <uint128_t> : std::true_type {};
//== template <> struct is_integral   <uint128_t> : std::true_type {};
//== template <> struct is_unsigned   <uint128_t> : std::true_type {};
//== template <> struct is_signed     <uint128_t> : std::false_type {};
//== };

// lhs type T as first arguemnt
// If the output is not a bool, casts to type T

// Bitwise Operators
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
operator&(const T & lhs, const uint128_t & rhs)
{   return rhs & lhs;
}

template <typename T> T & operator&=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (rhs & lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
operator|(const T & lhs, const uint128_t & rhs)
{   return rhs | lhs;
}

template <typename T> T & operator|=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (rhs | lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
operator^(const T & lhs, const uint128_t & rhs)
{   return rhs ^ lhs;
}

template <typename T> T & operator^=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (rhs ^ lhs);
}

// Bitshift operators
uint128_t operator<<(const bool & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::uint8_t  & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::uint16_t & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::uint32_t & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::uint64_t & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::int8_t & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::int16_t  & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::int32_t & lhs, const uint128_t & rhs);
uint128_t operator<<(const std::int64_t & lhs, const uint128_t & rhs);

template <typename T> T & operator<<=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (uint128_t(lhs) << rhs);
}

uint128_t operator>>(const bool & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::uint8_t  & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::uint16_t & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::uint32_t & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::uint64_t & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::int8_t & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::int16_t & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::int32_t & lhs, const uint128_t & rhs);
uint128_t operator>>(const std::int64_t & lhs, const uint128_t & rhs);

template <typename T> T & operator>>=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (uint128_t(lhs) >> rhs);
}

// Comparison Operators
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator==(const T & lhs, const uint128_t & rhs)
{   return (!rhs.upper() &&
            (static_cast<std::uint64_t>(lhs) == rhs.lower()));
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator!=(const T & lhs, const uint128_t & rhs)
{   return (rhs.upper() ||
            (static_cast<std::uint64_t>(lhs) != rhs.lower()));
}

template <typename T> bool operator>(const T & lhs, const uint128_t & rhs)
{   return (!rhs.upper()) &&
           (static_cast<std::uint64_t>(lhs) > rhs.lower());
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator<(const T & lhs, const uint128_t & rhs)
{   if (rhs.upper())
    {   return true;
    }
    return (static_cast<std::uint64_t>(lhs) < rhs.lower());
}

template <typename T> bool operator>=(const T & lhs, const uint128_t & rhs)
{   if (rhs.upper())
    {   return false;
    }
    return (static_cast<std::uint64_t>(lhs) >= rhs.lower());
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator<=(const T & lhs, const uint128_t & rhs)
{   if (rhs.upper())
    {   return true;
    }
    return (static_cast<std::uint64_t>(lhs) <= rhs.lower());
}

// Arithmetic Operators
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
operator+(const T & lhs, const uint128_t & rhs)
{   return rhs + lhs;
}

template <typename T> T & operator+=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (rhs + lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
operator-(const T & lhs, const uint128_t & rhs)
{   return -(rhs - lhs);
}

template <typename T> T & operator-=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (-(rhs - lhs));
}

template <typename T> uint128_t operator*(const T & lhs, const uint128_t & rhs)
{   return rhs * lhs;
}

template <typename T> T & operator*=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (rhs * lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
operator/(const T & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) / rhs;
}

template <typename T> T & operator/=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (uint128_t(lhs) / rhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, uint128_t>::type
 operator%(const T & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) % rhs;
}

template <typename T> T & operator%=(T & lhs, const uint128_t & rhs)
{   return lhs = static_cast <T> (uint128_t(lhs) % rhs);
}

// IO Operator
std::ostream & operator<<(std::ostream & stream, const uint128_t & rhs);

// I do not go "#define UINT128_T" here because while I am setting up
// int128_t I want to know if the unsigned version is native or
// simulated. A key reason for that is that if both are native then
// casts between them will already exist, while if either is simulated
// I will need to define something.

inline uint128_t::uint128_t()
    : UPPER(0), LOWER(0)
{}

inline uint128_t::uint128_t(const uint128_t & rhs)
    : UPPER(rhs.UPPER), LOWER(rhs.LOWER)
{}

inline uint128_t::uint128_t(uint128_t && rhs)
    : UPPER(std::move(rhs.UPPER)), LOWER(std::move(rhs.LOWER))
{   if (this != &rhs)
    {   rhs.UPPER = 0;
        rhs.LOWER = 0;
    }
}

inline uint128_t uint128_t::operator=(const uint128_t & rhs)
{   UPPER = rhs.UPPER;
    LOWER = rhs.LOWER;
    return *this;
}

inline uint128_t uint128_t::operator=(uint128_t && rhs)
{   if (this != &rhs)
    {   UPPER = std::move(rhs.UPPER);
        LOWER = std::move(rhs.LOWER);
        rhs.UPPER = 0;
        rhs.LOWER = 0;
    }
    return *this;
}

inline uint128_t::operator bool() const
{   return (bool) (UPPER | LOWER);
}

inline uint128_t::operator std::uint8_t() const
{   return static_cast<std::uint8_t>(LOWER);
}

inline uint128_t::operator std::uint16_t() const
{   return static_cast<std::uint16_t>(LOWER);
}

inline uint128_t::operator std::uint32_t() const
{   return (std::uint32_t) LOWER;
}

inline uint128_t::operator std::uint64_t() const
{   return (std::uint64_t) LOWER;
}

inline uint128_t::operator std::int64_t() const
{   return (std::int64_t) LOWER;
}

inline uint128_t uint128_t::operator&(const uint128_t & rhs) const
{   return uint128_t(UPPER & rhs.UPPER, LOWER & rhs.LOWER);
}

inline uint128_t & uint128_t::operator&=(const uint128_t & rhs)
{   UPPER &= rhs.UPPER;
    LOWER &= rhs.LOWER;
    return *this;
}

inline uint128_t uint128_t::operator|(const uint128_t & rhs) const
{   return uint128_t(UPPER | rhs.UPPER, LOWER | rhs.LOWER);
}

inline uint128_t & uint128_t::operator|=(const uint128_t & rhs)
{   UPPER |= rhs.UPPER;
    LOWER |= rhs.LOWER;
    return *this;
}

inline uint128_t uint128_t::operator^(const uint128_t & rhs) const
{   return uint128_t(UPPER ^ rhs.UPPER, LOWER ^ rhs.LOWER);
}

inline uint128_t & uint128_t::operator^=(const uint128_t & rhs)
{   UPPER ^= rhs.UPPER;
    LOWER ^= rhs.LOWER;
    return *this;
}

inline uint128_t uint128_t::operator~() const
{   return uint128_t(~UPPER, ~LOWER);
}

inline uint128_t uint128_t::operator<<(const uint128_t & rhs) const
{   const std::uint64_t shift = rhs.LOWER;
    if (((bool) rhs.UPPER) || (shift >= 128))
    {   return uint128_t(0);
    }
    else if (shift == 64)
    {   return uint128_t(LOWER, 0);
    }
    else if (shift == 0)
    {   return *this;
    }
    else if (shift < 64)
    {   return uint128_t((UPPER << shift) + (LOWER >> (64 - shift)),
                         LOWER << shift);
    }
    else if ((128 > shift) && (shift > 64))
    {   return uint128_t(LOWER << (shift - 64), 0);
    }
    else
    {   return uint128_t(0);
    }
}

inline uint128_t & uint128_t::operator<<=(const uint128_t & rhs)
{   *this = *this << rhs;
    return *this;
}

inline uint128_t uint128_t::operator>>(const uint128_t & rhs) const
{   const std::uint64_t shift = rhs.LOWER;
    if (((bool) rhs.UPPER) || (shift >= 128))
    {   return uint128_t(0);
    }
    else if (shift == 64)
    {   return uint128_t(0, UPPER);
    }
    else if (shift == 0)
    {   return *this;
    }
    else if (shift < 64)
    {   return uint128_t(UPPER >> shift,
                         (UPPER << (64 - shift)) + (LOWER >> shift));
    }
    else if ((128 > shift) && (shift > 64))
    {   return uint128_t(0, (UPPER >> (shift - 64)));
    }
    else
    {   return uint128_t(0);
    }
}

inline uint128_t & uint128_t::operator>>=(const uint128_t & rhs)
{   *this = *this >> rhs;
    return *this;
}

inline bool uint128_t::operator!() const
{   return !(bool) (UPPER | LOWER);
}

inline bool uint128_t::operator&&(const uint128_t & rhs) const
{   return ((bool) *this && rhs);
}

inline bool uint128_t::operator||(const uint128_t & rhs) const
{   return ((bool) *this || rhs);
}

inline bool uint128_t::operator==(const uint128_t & rhs) const
{   return ((UPPER == rhs.UPPER) && (LOWER == rhs.LOWER));
}

inline bool uint128_t::operator!=(const uint128_t & rhs) const
{   return ((UPPER != rhs.UPPER) | (LOWER != rhs.LOWER));
}

inline bool uint128_t::operator>(const uint128_t & rhs) const
{   if (UPPER == rhs.UPPER)
    {   return (LOWER > rhs.LOWER);
    }
    return (UPPER > rhs.UPPER);
}

inline bool uint128_t::operator<(const uint128_t & rhs) const
{   if (UPPER == rhs.UPPER)
    {   return (LOWER < rhs.LOWER);
    }
    return (UPPER < rhs.UPPER);
}

inline bool uint128_t::operator>=(const uint128_t & rhs) const
{   return ((*this > rhs) | (*this == rhs));
}

inline bool uint128_t::operator<=(const uint128_t & rhs) const
{   return ((*this < rhs) | (*this == rhs));
}

inline uint128_t uint128_t::operator+(const uint128_t & rhs) const
{   return uint128_t(UPPER + rhs.UPPER + ((LOWER + rhs.LOWER) <
                                          LOWER), LOWER + rhs.LOWER);
}

inline uint128_t & uint128_t::operator+=(const uint128_t & rhs)
{   UPPER += rhs.UPPER + ((LOWER + rhs.LOWER) < LOWER);
    LOWER += rhs.LOWER;
    return *this;
}

inline uint128_t uint128_t::operator-(const uint128_t & rhs) const
{   return uint128_t(UPPER - rhs.UPPER - ((LOWER - rhs.LOWER) >
                                          LOWER), LOWER - rhs.LOWER);
}

inline uint128_t & uint128_t::operator-=(const uint128_t & rhs)
{   *this = *this - rhs;
    return *this;
}

inline uint128_t uint128_t::operator*(const uint128_t & rhs) const
{   // split values into 4 32-bit parts
    std::uint64_t top[4] = {UPPER >> 32, UPPER & 0xffffffff, LOWER >> 32, LOWER & 0xffffffff};
    std::uint64_t bottom[4] = {rhs.UPPER >> 32, rhs.UPPER & 0xffffffff, rhs.LOWER >> 32, rhs.LOWER & 0xffffffff};
    std::uint64_t products[4][4];

    // multiply each component of the values
    for(int y = 3; y > -1; y--)
    {   for(int x = 3; x > -1; x--)
        {   products[3 - x][y] = top[x] * bottom[y];
        }
    }

    // first row
    std::uint64_t fourth32 = (products[0][3] & 0xffffffff);
    std::uint64_t third32  = (products[0][2] & 0xffffffff) +
                             (products[0][3] >> 32);
    std::uint64_t second32 = (products[0][1] & 0xffffffff) +
                             (products[0][2] >> 32);
    std::uint64_t first32  = (products[0][0] & 0xffffffff) +
                             (products[0][1] >> 32);

    // second row
    third32  += (products[1][3] & 0xffffffff);
    second32 += (products[1][2] & 0xffffffff) + (products[1][3] >> 32);
    first32  += (products[1][1] & 0xffffffff) + (products[1][2] >> 32);

    // third row
    second32 += (products[2][3] & 0xffffffff);
    first32  += (products[2][2] & 0xffffffff) + (products[2][3] >> 32);

    // fourth row
    first32  += (products[3][3] & 0xffffffff);

    // move carry to next digit
    third32  += fourth32 >> 32;
    second32 += third32  >> 32;
    first32  += second32 >> 32;

    // remove carry from current digit
    fourth32 &= 0xffffffff;
    third32  &= 0xffffffff;
    second32 &= 0xffffffff;
    first32  &= 0xffffffff;

    // combine components
    return uint128_t((first32 << 32) | second32,
                     (third32 << 32) | fourth32);
}

inline uint128_t & uint128_t::operator*=(const uint128_t & rhs)
{   *this = *this * rhs;
    return *this;
}

inline std::pair <uint128_t, uint128_t> uint128_t::divmod(
    const uint128_t & lhs, const uint128_t & rhs) const
{   // Save some calculations /////////////////////
    if (rhs == uint128_t(0))
    {   throw std::domain_error("Error: division or modulus by 0");
    }
    else if (rhs == uint128_t(1))
    {   return std::pair <uint128_t, uint128_t> (lhs, uint128_t(0));
    }
    else if (lhs == rhs)
    {   return std::pair <uint128_t, uint128_t> (uint128_t(1), uint128_t(0));
    }
    else if ((lhs == uint128_t(0)) || (lhs < rhs))
    {   return std::pair <uint128_t, uint128_t> (uint128_t(0), lhs);
    }

    std::pair <uint128_t, uint128_t> qr (uint128_t(0), uint128_t(0));
    for(std::uint8_t x = lhs.bits(); x > 0; x--)
    {   qr.first  <<= uint128_t(1);
        qr.second <<= uint128_t(1);

        if ((lhs >> (x - 1U)) & 1)
        {   qr.second++;
        }

        if (qr.second >= rhs)
        {   qr.second -= rhs;
            qr.first++;
        }
    }
    return qr;
}

inline uint128_t uint128_t::operator/(const uint128_t & rhs) const
{   return divmod(*this, rhs).first;
}

inline uint128_t & uint128_t::operator/=(const uint128_t & rhs)
{   *this = *this / rhs;
    return *this;
}

inline uint128_t uint128_t::operator%(const uint128_t & rhs) const
{   return divmod(*this, rhs).second;
}

inline uint128_t & uint128_t::operator%=(const uint128_t & rhs)
{   *this = *this % rhs;
    return *this;
}

inline uint128_t & uint128_t::operator++()
{   static const uint128_t uint128_1(1);
    return *this += uint128_1;
}

inline uint128_t uint128_t::operator++(int)
{   uint128_t temp(*this);
    ++*this;
    return temp;
}

inline uint128_t & uint128_t::operator--()
{   static const uint128_t uint128_1(1);
    return *this -= uint128_1;
}

inline uint128_t uint128_t::operator--(int)
{   uint128_t temp(*this);
    --*this;
    return temp;
}

inline uint128_t uint128_t::operator+() const
{   return *this;
}

inline uint128_t uint128_t::operator-() const
{   static const uint128_t uint128_1(1);
    return ~*this + uint128_1;
}

inline std::uint8_t uint128_t::bits() const
{   std::uint8_t out = 0;
    if (UPPER)
    {   out = 64;
        std::uint64_t up = UPPER;
        while (up)
        {   up >>= 1;
            out++;
        }
    }
    else
    {   std::uint64_t low = LOWER;
        while (low)
        {   low >>= 1;
            out++;
        }
    }
    return out;
}

inline std::string uint128_t::str(std::uint8_t base,
                                  const unsigned int & len) const
{   if ((base < 2) || (base > 16))
    {   throw std::invalid_argument("Base must be in the range [2, 16]");
    }
    std::string out = "";
    if (!(*this))
    {   out = "0";
    }
    else
    {   std::pair <uint128_t, uint128_t> qr(*this, uint128_t(0));
        do
        {   qr = divmod(qr.first, base);
            out = "0123456789abcdef"[static_cast<std::uint8_t>(qr.second)] + out;
        }
        while (qr.first);
    }
    if (out.size() < len)
    {   out = std::string(len - out.size(), '0') + out;
    }
    return out;
}

inline uint128_t operator<<(const bool & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::uint8_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::uint16_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::uint32_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::uint64_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::int8_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::int16_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::int32_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator<<(const std::int64_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) << rhs;
}

inline uint128_t operator>>(const bool & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::uint8_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::uint16_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::uint32_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::uint64_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::int8_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::int16_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::int32_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline uint128_t operator>>(const std::int64_t & lhs, const uint128_t & rhs)
{   return uint128_t(lhs) >> rhs;
}

inline std::ostream & operator<<(std::ostream & stream, const uint128_t & rhs)
{   if (stream.flags() & stream.oct)
    {   stream << rhs.str(8);
    }
    else if (stream.flags() & stream.dec)
    {   stream << rhs.str(10);
    }
    else if (stream.flags() & stream.hex)
    {   stream << rhs.str(16);
    }
    return stream;
}

#endif // HAVE_UINT128_T

// Now I should certainly have a type uint128_t. It may be native or
// simulated, but it should exist, and it should provide getUPPER(),
// getLOWER() and PACK128() functions. I also have functions to test or
// flip the top bit if an uint128_t.


#ifdef HAVE_INT128_T

namespace INT128
{

inline std::uint64_t getLOWER(int128_t a)
{   return static_cast<std::uint64_t>(a);
}

inline std::int64_t getUPPER(int128_t a)
{   return static_cast<std::int64_t>((a - getLOWER(a)) /
               static_cast<int128_t>(1)<<64);
}

inline int128_t PACK128(int64_t high, std::uint64_t low)
{   return static_cast<int128_t>(high)<<64 | low;
}

inline uint128_t UNSIGNED(int128_t a)
{   return PACK128(static_cast<std::uint64_t>(a>>64),
                   static_cast<std::uint64_t>(a));
}

};

#else // HAVE_INT128_T

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <utility>

namespace INT128
{
inline uint128_t UNSIGNED(int128_t a);
};

class int128_t
{
private:
    std::int64_t UPPER;
    std::uint64_t LOWER;

public:
    // Constructors
    int128_t()
    {   UPPER = 0;
        LOWER = 0;
    }
    int128_t(const int128_t & rhs)
    {   UPPER = rhs.UPPER;
        LOWER = rhs.LOWER;
    }
    int128_t(int128_t && rhs)
    {   UPPER = rhs.UPPER;
        LOWER = rhs.LOWER;
    }
    int128_t(uint128_t v)
    {   UPPER = static_cast<std::int64_t>(INT128::getUPPER(v));
        LOWER = INT128::getLOWER(v);
    }

    int128_t(const bool &rhs)
    {   UPPER = 0;
        LOWER = rhs;
    }
    template <typename T> int128_t(const T & rhs)
        : UPPER(rhs < 0 ? -1 : 0), LOWER(rhs)
    {   static_assert(std::is_integral <T>::value,
                      "Input argument type must be an integer.");
    }
    template <typename S, typename T> int128_t(const S & upper_rhs,
                                               const T & lower_rhs)
        : UPPER(upper_rhs), LOWER(lower_rhs)
    {   static_assert(std::is_integral <S>::value &&
                      std::is_integral <T>::value
                      , "Input argument types must be integers.");
    }

    std::int64_t getUPPER()
    {   return UPPER;
    }

    std::uint64_t getLOWER()
    {   return LOWER;
    }

    static uint128_t FLIP_TOP_BIT(int128_t a)
    {   return INT128::UNSIGNED_FLIP_TOP_BIT(INT128::UNSIGNED(a));
    }

    //  RHS input args only

    // Assignment Operator
    int128_t operator=(const int128_t & rhs)
    {   UPPER = rhs.UPPER;
        LOWER = rhs.LOWER;
        return *this;
    }
    int128_t operator=(int128_t && rhs)
    {   UPPER = rhs.UPPER;
        LOWER = rhs.LOWER;
        return *this;
    }
    int128_t operator=(uint128_t rhs)
    {   UPPER = static_cast<std::int64_t>(INT128::getUPPER(rhs));
        LOWER = INT128::getLOWER(rhs);
        return *this;
    }

    template <typename T> int128_t operator=(const T & rhs)
    {   static_assert(std::is_integral <T>::value,
                      "Input argument type must be an integer.");
        UPPER = rhs < 0 ? -1 : 0;
        LOWER = rhs;
        return *this;
    }

    // Typecast Operators
    operator bool() const
    {   return (bool) (UPPER | LOWER);
    }
    
    operator std::int8_t() const
    {   return static_cast<std::int8_t>(LOWER);
    }

    operator std::int16_t() const
    {   return static_cast<std::int16_t>(LOWER);
    }

    operator std::int32_t() const
    {   return (std::int32_t) LOWER;
    }

    operator std::int64_t() const
    {   return (std::int64_t) LOWER;
    }

    operator std::uint8_t() const
    {   return static_cast<std::uint8_t>(LOWER);
    }

    operator std::uint16_t() const
    {   return static_cast<std::uint16_t>(LOWER);
    }

    operator std::uint32_t() const
    {   return (std::uint32_t) LOWER;
    }

    operator std::uint64_t() const
    {   return (std::uint64_t) LOWER;
    }

    operator uint128_t() const
    {   return INT128::PACK128(static_cast<std::uint64_t>(UPPER), LOWER);
    }

    // Bitwise Operators
    int128_t operator&(const int128_t & rhs) const
    {   return int128_t(UPPER&rhs.UPPER, LOWER&rhs.LOWER);
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    operator&(const T & rhs) const
    {   return int128_t(rhs >= 0 ? 0 : UPPER,
                        LOWER & static_cast<std::uint64_t>(rhs));
    }

    int128_t & operator&=(const int128_t & rhs)
    {   UPPER &= rhs.UPPER;
        LOWER &= rhs.LOWER;
        return *this;
    }

    template <typename T> int128_t & operator&=(const T & rhs)
    {   if (rhs >= 0) UPPER = 0;
        LOWER &= rhs;
        return *this;
    }

    int128_t operator|(const int128_t & rhs) const
    {   return int128_t(UPPER|rhs.UPPER, LOWER|rhs.LOWER);
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    operator|(const T & rhs) const
    {   return int128_t(rhs < 0 ? -1 : UPPER,
                        LOWER | static_cast<std::uint64_t>(rhs));
    }

    int128_t & operator|=(const int128_t & rhs)
    {   UPPER |= rhs.UPPER;
        LOWER |= rhs.LOWER;
        return *this;
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    & operator|=(const T & rhs)
    {   if (rhs < 0) UPPER = -1;
        LOWER |= static_cast<std::uint64_t>(rhs);
        return *this;
    }

    int128_t operator^(const int128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    operator^(const T & rhs) const
    {   return int128_t(rhs<0 ? ~UPPER : UPPER,
                        LOWER ^ static_cast<std::uint64_t>(rhs));
    }

    int128_t & operator^=(const int128_t & rhs);

    template <typename T> int128_t & operator^=(const T & rhs)
    {   if (rhs < 0) UPPER = ~UPPER;
        LOWER ^= static_cast<std::uint64_t>(rhs);
        return *this;
    }

    int128_t operator~() const
    {   return int128_t(~INT128::UNSIGNED(*this));
    }

    // Bit Shift Operators
    int128_t operator<<(const int128_t & rhs) const;

    template <typename T> int128_t operator<<(const T & rhs) const
    {   return *this << int128_t(rhs);
    }

    int128_t & operator<<=(const int128_t & rhs);

    template <typename T> int128_t & operator<<=(const T & rhs)
    {   *this = *this << int128_t(rhs);
        return *this;
    }

    int128_t operator>>(const int128_t & rhs) const
    {   bool sign = UPPER < 0;
        uint128_t r = INT128::UNSIGNED(*this) >> INT128::UNSIGNED(rhs);
        if (sign) r |= INT128::UNSIGNED(int128_t(-1)) << INT128::UNSIGNED(int128_t(128)-rhs);
        return int128_t(r);
    }

    template <typename T> int128_t operator>>(const T & rhs) const
    {   return *this >> int128_t(rhs);
    }

    int128_t & operator>>=(const int128_t & rhs)
    {   bool sign = UPPER < 0;
        uint128_t r = INT128::UNSIGNED(*this) >> INT128::UNSIGNED(rhs);
        if (sign) r |= INT128::UNSIGNED(int128_t(-1)) << INT128::UNSIGNED(int128_t(128)-rhs);
        UPPER=static_cast<std::int64_t>(INT128::getUPPER(r));
        LOWER=INT128::getLOWER(r);
        return *this;
    }

    template <typename T> int128_t & operator>>=(const T & rhs)
    {   *this = *this >> int128_t(rhs);
        return *this;
    }

    // Logical Operators
    bool operator!() const;
    bool operator&&(const int128_t & rhs) const;
    bool operator||(const int128_t & rhs) const;

    template <typename T> bool operator&&(const T & rhs)
    {   return static_cast <bool> (*this && rhs);
    }

    template <typename T> bool operator||(const T & rhs)
    {   return static_cast <bool> (*this || rhs);
    }

    // Comparison Operators
    bool operator==(const int128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator==(const T & rhs) const
    {   return (UPPER == (rhs>=0 ? 0 : -1) &&
               (LOWER == static_cast<std::uint64_t>(rhs)));
    }

    bool operator!=(const int128_t & rhs) const;

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator!=(const T & rhs) const
    {   return (UPPER != (rhs>0 ? 0 : -1) ||
               (LOWER != static_cast<std::uint64_t>(rhs)));
    }

    bool operator>(const int128_t & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) > int128_t::FLIP_TOP_BIT(rhs);
    }

    template <typename T> bool operator>(const T & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) > int128_t::FLIP_TOP_BIT(static_cast<std::uint64_t>(rhs));
    }

    bool operator<(const int128_t & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) < int128_t::FLIP_TOP_BIT(rhs);
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator<(const T & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) < int128_t::FLIP_TOP_BIT(static_cast<std::uint64_t>(rhs));
    }

    bool operator>=(const int128_t & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) >= int128_t::FLIP_TOP_BIT(rhs);
    }

    template <typename T> bool operator>=(const T & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) >= int128_t::FLIP_TOP_BIT(static_cast<std::uint64_t>(rhs));
    }

    bool operator<=(const int128_t & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) <= int128_t::FLIP_TOP_BIT(rhs);
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
    operator<=(const T & rhs) const
    {   return int128_t::FLIP_TOP_BIT(*this) <= int128_t::FLIP_TOP_BIT(static_cast<std::uint64_t>(rhs));
    }

    // Arithmetic Operators
    int128_t operator+(const int128_t & rhs) const
    {   return int128_t(INT128::UNSIGNED(*this) + INT128::UNSIGNED(rhs));
    }
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    operator+(const T & rhs) const
    {   return int128_t(INT128::UNSIGNED(*this) + INT128::UNSIGNED(rhs));
    }

    int128_t & operator+=(const int128_t & rhs)
    {   int128_t r = int128_t(INT128::UNSIGNED(*this) + INT128::UNSIGNED(rhs));
        UPPER = r.UPPER;
        LOWER = r.LOWER;
        return *this;
    }

    template <typename T> int128_t & operator+=(const T & rhs)
    {   int128_t r = int128_t(INT128::UNSIGNED(*this) + INT128::UNSIGNED(rhs));
        UPPER = r.UPPER;
        LOWER = r.LOWER;
        return *this;
    }

    int128_t operator-(const int128_t & rhs) const
    {   return int128_t(INT128::UNSIGNED(*this) - INT128::UNSIGNED(rhs));
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    operator=(const T & rhs)
    {   return *this = int128_t(rhs);
    }

    int128_t & operator-=(const int128_t & rhs)
    {   int128_t r = int128_t(INT128::UNSIGNED(*this) - INT128::UNSIGNED(rhs));
        UPPER = r.UPPER;
        LOWER = r.LOWER;
        return *this;
    }

    template <typename T> int128_t & operator-=(const T & rhs)
    {   int128_t r = int128_t(INT128::UNSIGNED(*this) - INT128::UNSIGNED(rhs));
        UPPER = r.UPPER;
        LOWER = r.LOWER;
        return *this;
    }

    int128_t operator*(const int128_t & rhs) const
    {   return int128_t(INT128::UNSIGNED(*this) * INT128::UNSIGNED(rhs));
    }

    template <typename T> int128_t operator*(const T & rhs) const
    {   return int128_t(INT128::UNSIGNED(*this) * INT128::UNSIGNED(rhs));
    }

    int128_t & operator*=(const int128_t & rhs)
    {   int128_t r = int128_t(INT128::UNSIGNED(*this) * INT128::UNSIGNED(rhs));
        UPPER = r.UPPER;
        LOWER = r.LOWER;
        return *this;
    }

    template <typename T> int128_t & operator*=(const T & rhs)
    {   int128_t r = int128_t(INT128::UNSIGNED(*this) * INT128::UNSIGNED(rhs));
        UPPER = r.UPPER;
        LOWER = r.LOWER;
        return *this;
    }

private:
    std::pair <int128_t, int128_t> divrem(const int128_t & a,
                                          const int128_t & b) const
    {   uint128_t ua = INT128::UNSIGNED(a), ub = INT128::UNSIGNED(b), uq;
        if (a.upper() < 0)
        {   if (b.upper() < 0) uq = (-ua)/(-ub);
            else uq = -((-ua)/ub);
        }
        else
        {   if (b.upper() < 0) uq = -(ua/(-ub));
            else uq = ua/ub;
        }
        int128_t q(uq);
        return std::pair<int128_t,int128_t>(q, a - q*b);
    }

public:
    int128_t operator/(const int128_t & rhs) const
    {   return  divrem(*this, rhs).first;
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    operator/(const T & rhs) const
    {   return *this / int128_t(rhs);
    }

    int128_t & operator/=(const int128_t & rhs);

    template <typename T> int128_t & operator/=(const T & rhs)
    {   *this = *this / int128_t(rhs);
        return *this;
    }

    int128_t operator%(const int128_t & rhs) const
    {   return divrem(*this, rhs).second;
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
    operator%(const T & rhs) const
    {   return  *this % int128_t(rhs);
    }

    int128_t & operator%=(const int128_t & rhs);

    template <typename T> int128_t & operator%=(const T & rhs)
    {   *this = *this % int128_t(rhs);
        return *this;
    }

    // Increment Operator
    int128_t & operator++();
    int128_t operator++(int);

    // Decrement Operator
    int128_t & operator--();
    int128_t operator--(int);

    // Nothing done since promotion doesn't work here
    int128_t operator+() const
    {   return *this;
    }

    // two's complement
    int128_t operator-() const;

    // Get private values
    const std::int64_t & upper() const
    {   return UPPER;
    }
    const std::uint64_t & lower() const
    {   return LOWER;
    }

    // Get bitsize of value
    std::uint8_t bits() const;

    // Get string representation of value
    std::string str(std::uint8_t base = 10,
                    unsigned int len = 0) const;
};

inline uint128_t INT128::UNSIGNED(int128_t a)
{   return INT128::PACK128(static_cast<std::uint64_t>(a.getUPPER()), a.getLOWER());
}

//== // Give int128_t type traits
//== namespace std    // This is probably not a good idea
//== {
//== template <> struct is_arithmetic <int128_t> : std::true_type {};
//== template <> struct is_integral   <int128_t> : std::true_type {};
//== template <> struct is_signed     <int128_t> : std::true_type {};
//== template <> struct is_unsigned   <int128_t> : std::false_type {};
//== };

// lhs type T as first arguemnt
// If the output is not a bool, casts to type T

// Bitwise Operators
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
operator&(const T & lhs, const int128_t & rhs)
{   return rhs & lhs;
}

template <typename T> T & operator&=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (rhs & lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
operator|(const T & lhs, const int128_t & rhs)
{   return rhs | lhs;
}

template <typename T> T & operator|=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (rhs | lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
operator^(const T & lhs, const int128_t & rhs)
{   return rhs ^ lhs;
}

template <typename T> T & operator^=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (rhs ^ lhs);
}

// Bitshift operators

//inline int128_t operator<<(const int128_t & lhs, const int128_t & rhs)
//{   return int128_t(int128_t::INT128::UNSIGNED(lhs) << INT128::UNSIGNED(rhs));
//}

inline int128_t operator<<(const bool & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::uint8_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::uint16_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::uint32_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::uint64_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::int8_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::int16_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::int32_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

inline int128_t operator<<(const std::int64_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) << rhs;
}

//inline int128_t operator>>(const int128_t & lhs, const int128_t & rhs)
//{   if (lhs >= 0) return int128_t((int128_t::INT128::UNSIGNED(lhs) >> INT128::UNSIGNED(rhs));
//    else return int128_t((int128_t::INT128::UNSIGNED(lhs) >> INT128::UNSIGNED(rhs)) |
//                         (INT128::UNSIGNED(int128_t(-1)) << (128-INT128::UNSIGNED(rhs))));
//}

inline int128_t operator>>(const bool & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::uint8_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::uint16_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::uint32_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::uint64_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::int8_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::int16_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::int32_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

inline int128_t operator>>(const std::int64_t & lhs, const int128_t & rhs)
{   return int128_t(lhs) >> rhs;
}

template <typename T> T & operator<<=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (int128_t(lhs) << rhs);
}

template <typename T> T & operator>>=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (int128_t(lhs) >> rhs);
}

// Comparison Operators
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator==(const T & lhs, const int128_t & rhs)
{   return (rhs.upper() == (lhs<0?-1:0) &&
            (static_cast<std::uint64_t>(lhs) == rhs.lower()));
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator!=(const T & lhs, const int128_t & rhs)
{   
    return (rhs.upper() != (lhs<0?-1:0) ||
            (static_cast<std::uint64_t>(lhs) != rhs.lower()));
}

template <typename T> bool operator>(const T & lhs, const int128_t & rhs)
{   return INT128::UNSIGNED_FLIP_TOP_BIT(int128_t(lhs)) > INT128::UNSIGNED_FLIP_TOP_BIT(rhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator<(const T & lhs, const int128_t & rhs)
{   return INT128::UNSIGNED_FLIP_TOP_BIT(int128_t(lhs)) < INT128::UNSIGNED_FLIP_TOP_BIT(rhs);
}

template <typename T> bool operator>=(const T & lhs,
                                      const int128_t & rhs)
{   return INT128::UNSIGNED_FLIP_TOP_BIT(int128_t(lhs)) >= INT128::UNSIGNED_FLIP_TOP_BIT(rhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
operator<=(const T & lhs, const int128_t & rhs)
{   return INT128::UNSIGNED_FLIP_TOP_BIT(int128_t(lhs)) <= INT128::UNSIGNED_FLIP_TOP_BIT(rhs);
}

// Arithmetic Operators
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
operator+(const T & lhs, const int128_t & rhs)
{   return rhs + lhs;
}

template <typename T> T & operator+=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (rhs + lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
operator-(const T & lhs, const int128_t & rhs)
{   return -(rhs - lhs);
}

template <typename T> T & operator-=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (-(rhs - lhs));
}

template <typename T> int128_t operator*(const T & lhs, const int128_t & rhs)
{   return rhs * lhs;
}

template <typename T> T & operator*=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (rhs * lhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
operator/(const T & lhs, const int128_t & rhs)
{   return int128_t(lhs) / rhs;
}

template <typename T> T & operator/=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (int128_t(lhs) / rhs);
}

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int128_t>::type
operator%(const T & lhs, const int128_t & rhs)
{   return int128_t(lhs) % rhs;
}

template <typename T> T & operator%=(T & lhs, const int128_t & rhs)
{   return lhs = static_cast <T> (int128_t(lhs) % rhs);
}

// IO Operator
std::ostream & operator<<(std::ostream & stream, const int128_t & rhs);


//inline bool greaterp128(const int128_t & a, const int128_t & b)
//{   uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
//    uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
//    return aa > bb;
//}

// The code here is because x<<n can have undefined value for signed types x,
// and I want one that just "does what I expect" even in cases where there
// is overflow. The situation with x>>n is even less satisfactory because
// when x is signed there is little guarantee about how its sign bit is
// handled. I want it to be replicated into the space vacated by the shift.

//inline int128_t ASL128(const int128_t & a, int n)
//{   if (n >= 128) return 0;
//    if (n < 64) return
//            int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
//                     a.lower()<<n);
//    else if (n == 64) return int128_t(a.lower(), 0);
//    else return int128_t(a.lower()<<(n-64), 0);
//}

//inline int128_t ASR128(const int128_t & a, int n)
//{   if (n >= 128) return int128_t(a < 0 ? -1 : 0);
//    if (n < 64) return int128_t(ASR(static_cast<std::int64_t>(a.upper()), n),
//                                    (a.upper()<<(64-n)) | (a.lower()>>n));
//    else if (n == 64) return int128_t(-static_cast<std::int64_t>(a.upper()<0),
//                                          a.upper());
//    else if (n < 64) return int128_t(ASR(static_cast<std::int64_t>(a.upper()), n),
//                                         (a.upper()<<(64-n)) | (a.lower()>>n));
//    else return int128_t(-static_cast<std::int64_t>(a.upper()<0),
//                             ASR((static_cast<std::int64_t>(a.upper())), n-64));
//}

namespace INT128
{

inline std::int64_t getUPPER(int128_t a)
{   return a.getUPPER();
}

inline std::uint64_t getLOWER(int128_t a)
{   return a.getLOWER();
}

inline int128_t PACK128(std::int64_t high, std::uint64_t low)
{   return int128_t(high, low);
}

};

inline std::string int128_t::str(std::uint8_t base,
                                 unsigned int len) const
{   std::string out = "";
    if (UPPER==0 && LOWER==0) out = "0";
    else
    {   uint128_t u = INT128::UNSIGNED(*this);
        if (base==10 && UPPER<0)
        {   u = -u;
            len--;
        }
        do
        {   int r = static_cast<std::uint64_t>(u % base);
            out = "0123456789abcdef"[r] + out;
            u = u / base;
        } while (u != 0);
    }
    if (out.size() < len) out = std::string(len - out.size(), '0') + out;
    if (base==10 && UPPER<0) out = "-" + out;
    return out; 
}

inline int128_t & int128_t::operator++()
{   static const int128_t int128_1(1);
    return *this += int128_1;
}

inline int128_t int128_t::operator++(int)
{   int128_t temp(*this);
    ++*this;
    return temp;
}

inline int128_t & int128_t::operator--()
{   static const int128_t int128_1(1);
    return *this -= int128_1;
}

inline int128_t int128_t::operator--(int)
{   int128_t temp(*this);
    --*this;
    return temp;
}

inline int128_t int128_t::operator-() const
{   static const int128_t int128_1(1);
    return ~*this + int128_1;
}

inline std::ostream & operator<<(std::ostream & stream, const int128_t & rhs)
{   if (stream.flags() & stream.oct)
    {   stream << rhs.str(8);
    }
    else if (stream.flags() & stream.dec)
    {   stream << rhs.str(10);
    }
    else if (stream.flags() & stream.hex)
    {   stream << rhs.str(16);
    }
    return stream;
}

#endif // HAVE_INT128_T

inline uint128_t uint128(int128_t v)
{   return INT128::PACK128(static_cast<std::uint64_t>(v>>64),
                   INT128::getLOWER(INT128::UNSIGNED(v)));
}

inline uint128_t uint128(std::uint64_t v)
{   return INT128::PACK128(static_cast<std::uint64_t>(0), v);
}

inline uint128_t uint128(int64_t v)
{   return INT128::PACK128(
        static_cast<std::uint64_t>(v<0 ? 0xffffffffffffffffU : 0U),
        v);
}

#ifdef HAVE_INT128_T
inline int128_t int128(int64_t v)
{   return static_cast<int128_t>(v);
}
#else // HAVE_INT128_T
inline int128_t int128(int64_t v)
{   return int128_t(static_cast<std::int64_t>(v<0 ? -1 : 0),
                    static_cast<std::uint64_t>(v));
}
#endif // HAVE_INT128_T

#ifndef HAVE_UINT128_T
inline uint128_t::operator int128_t() const
{   return INT128::PACK128(static_cast<std::int64_t>(UPPER), LOWER);
}
inline uint128_t::uint128_t(int128_t a)
{   UPPER = INT128::getUPPER(a);
    LOWER = INT128::getLOWER(a);
}

inline uint128_t uint128_t::operator=(int128_t rhs)
{   UPPER = static_cast<std::uint64_t>(INT128::getUPPER(rhs));
    LOWER = INT128::getLOWER(rhs);
    return *this;
}
#endif // HAVE_UINT128_T

// Once this header has been installed both HAVE_UINT128_T and
// HAVE_INT128_T will be defined.

#ifndef HAVE_UINT128_T
#define HAVE_UINT128_T 1
#endif

#ifndef HAVE_INT128_T
#define HAVE_INT128_T 1
#endif

#endif // __INT128_T__

// end of int128_t.h
