// machine.h                               Copyright (C) 1990-2021 Codemist

//
// This was ONCE a place where all system-specific options were detected
// and mapped onto tidy macros that could guide subsequent compilation. Now
// all that is handled in "config.h", which is manufactured on a per-target
// basis by a configure-script created by autoconf.
//
// Now it us used for just a few tests based on what comes out of
// config.h to set up really major further bits of configuration, where
// the characteristic of what is done here is that it will vary from
// target to target and it is truly pervasive in consequences.
//


/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

// $Id$


#ifndef header_machine_h
#define header_machine_h 1

// To keep my C++ just a bit more compact I will put in some "using"
// statements here so that especially commonly used things can avoid needing
// explicit "std::" prefixes. The things I "use" here are ones that should
// be standard from the headers I have included and should not be names
// where there is any proper chance for conflict. Note that I need some
// header files scanned before the "using" statement.

#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <atomic>
#include <string>

#ifndef __has_cpp_attribute
#define __has_cpp_attribute(name) 0
#endif // fake C++17 support

#ifndef __has_include
#define __has_include(name) 0
#endif // fake C++17 support


#if !defined HAVE_FILESYSTEM &&  \
     __has_include(<filesystem>)
#define HAS_FILESYSTEM 1
#endif // HAVE_FILESYSTEM now defined if "#include <filesystem>" reasonable.

#ifdef HAVE_FILESYSTEM
#include <filesystem>
#endif // HAVE_FILESYSTEM

// Now I can test __cpp_lib_filesystem to see if std::filesystem is
// actually available. If I use it I may need to link -lstdc++fs in gcc
// or -lc++fs in clang!

#if !defined LIKELY && !defined UNLIKELY

#ifdef __has_cpp_attribute_likely
#define LIKELY [[likely]]
#else // __has_cpp_attribute_likely
#define LIKELY
#endif // __has_cpp_attribute_likely

#ifdef __has_cpp_attribute_unlikely
#define UNLIKELY [[unlikely]]
#else // __has_cpp_attribute_unlikely
#define UNLIKELY
#endif // __has_cpp_attribute_unlikely

#endif // LIKELY, UNLIKELY

using std::cout;      // Make C++ output as in "cout << "string" << endl;" a
using std::endl;      // lot nicer to write.

using std::int32_t;   // Fixed-width and architecture-specific width integers
using std::int64_t;   // that are really heavily used.
using std::intptr_t;
using std::uint32_t;
using std::uint64_t;
// The header "int128_h.h" ensures that int128_t and uint128_t are
// available without needing any package prefix.
using std::uintptr_t;
using std::size_t;

using std::string;    // This to encourage me to use "string" rather than
                      // "char *".

using std::atomic;    // If I am going to be multi-threaded then very many
                      // things need to be atomic and writing std::atomic<>
                      // every time is a burden.

#if !defined DEBUG && !defined NDEBUG
#define NDEBUG 1
#endif // DEBUG || NDEBUG

//
// If the header "complex.h" is available, the type "complex double" is
// accepted and the function "csqrt" is present I will assume I can use the
// standard C99 complex number support facilities. Aha SOME C++ systems
// support this, but others use a template class, and I will adapt my code
// to use that some time.
//

#if defined HAVE_COMPLEX_H && \
    defined HAVE_COMPLEX_DOUBLE && \
    defined HAVE_CSQRT
#define HAVE_COMPLEX 1
#endif // Complex number support

//
// I will check a number of things before I try to use sigaltstack()
//
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H && \
    defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP && \
    defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif // sigaltstack availability

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

#ifdef __cpp_inline_variables
// For versions of C++ up to C++17 I will put constant values in header
// files using something along the line of "static const int VAR = VAL;".
// This should give the compiler a chance to replace the name with its value
// throughout the compilation unit, and if the compiler is clever enough it
// will avoid leaving a word of memory with the value stored if all uses
// have been dealt with more directly. However it will tend to lead to a
// lot of "static variable defined but not used" warnings.
// From C++17 onwards (and C++ mandates the __cpp_inline_variables macro to
// indicate if the feature is in place) I will use
// "inline const int VAR = VAL;" and now if memory is allocated for the
// variable it will only be allocated once, and I hope that compilers will
// not feel entitled to moan about cases where there are no references.
//
#define INLINE_VAR inline
#else // inline variables
#define INLINE_VAR UNUSED_NAME static
#endif // inline variables

#if defined(__clang__) || defined (__GNUC__)
# define NO_SANITIZE_ADDRESS __attribute__((no_sanitize_address))
#else
# define NO_SANITIZE_ADDRESS
#endif

// With really old versions of C++ you may not be able to write
// large literal integers without some decoration. So e.g.
// 0x7fffffffffffffff might count as an overflow. In those old days you
// could either add a suffix (typically L or LL, but different platforms
// might not agree about how wide L made things) or use the C macros
// such as INT64_C().
//
// A bit later C++ compilers started interpreting long strings of digits
// as items with integer type wide enough to represent them. And then
// INT64_C and friends only got defined if you had defined a symbol
// __STDC_CONSTANT_MACROS before including <stdint.h>.
//
// Yet later the stance seems to have softened and INT64_C etc get
// defined by <stdint.h> regardless, so use is not required but is
// permitted. To cope with all these situations I will define the
// magic symbols __STDC_CONSTANT_MACROS and __STDC_FORMAT_MACROS (which
// helps for printf etc) and always write large-value literals in the
// way that ancient systems and C required.

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif // define INT32_C etc

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif // define numeric limits

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif // define PRId32 etc

#include "winsupport.h"

#ifndef WIN32
#define unix_posix 1        // Assume all non-windows systems are Unix-like!
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>
#define WSAGetLastError()   errno  // retrieve error code
#define WSACleanup()               // tidy up at end of day
#define closesocket(a)      close(a)
#define SOCKET              int
#define SOCKET_ERROR        (-1)
#ifndef INADDR_NONE
#  define INADDR_NONE       0xffffffff
#endif // INADDR_NONE

#endif //WIN32

// I now include eg <cstdio> rather than <stdio.h>. The consequence is that
// all the names that are declared are certain to be present in the std::
// namespace. They MIGHT be present in the global namespace too, but there is
// no guarantee of that.

// The consequence is that I ought to go "using std::fopen;" and things like
// that wherever I use a C library function, or as an alternative write the
// calls as std::fopen(...) instead of just fopen(...). At present it is not
// clear how I can police my adherence to this requirement!

#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cctype>
#include <cwctype>
#include <ctime>
#include <cstdarg>
#include <csignal>
#include <cerrno>

// Now the C++ facilities that I use...

#include <iomanip>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif // SYS_TIME_H

// In a manner that I view as bad, at least the Macintosh copy of libffi
// installed via macports in August 2017 defined a bunch of autoconf-related
// macros, potentially in conflict with my own set of values that autoconf
// sets up for me. So here I do a load of #undef steps to avoid trouble, and
// I then must not try using those macros at all.

#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL

#ifndef WITHOUT_FFI
#include <ffi.h>
#endif // WITHOUT_FFI

#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL

#ifndef EMBEDDED
extern "C"
{
// At present softfloat.h needs inclusion in C mode not C++ mode.
// This must be included before tags.h.

#include "softfloat.h"
}
#endif // EMBEDDED

// I want to have types uint128_t and int128_t and this header file
// can arrange that for me.

#include "int128_t.h"

//
// I will decode information that config.h has given me and define a simple
// symbol SOCKETS if I can use sockets...
//
//
#if !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif // sockets available
#endif // !EMBEDDED

#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else // 64-bit?
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif // 64-bit?
#else // WIN32
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else // Give up on identity of platform
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif // system and implementation identity

// The C and C++ refuse to define the behaviour of right shifts
// on signed types. The underlying reason may relate to the possibility that
// numbers might be stored in sign-and-magnitude notation or some other
// scheme other than the 2s complement that is in practice universal these
// days. I provide support here that will guarantee to do right shifts
// in arithmetic mode - and hope that modern compilers will map them
// onto the single machine instruction that is generally what I want.

// Shifts by more than the word-length are invalid, and I should not perform
// any, but the code may indicate some guarded by SIXTY_FOUR_BIT, so
// I will fudge things here! In MANY cases the extra tests here will be
// ones where the compiler can remove them because the shift amount is
// manifest. If that is not the case they are still cheap and ensure that
// my code behaves in a defined manner (even if that could be wrong!).

#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
// Right shifts on (negative) signed values have implementation defined
// (rather than undefined) semantics in C++, and so on platforms
// where in fact you get right shifting of a 2s complement representation
// with the sign bit preserved I can just use "a>>n" and the only special
// care I need to take is if the shift amount is out of range.

inline int32_t ASR(int32_t a, int n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(int32_t))) n=0;
    return a >> n;
}

inline int64_t ASR(int64_t a, int n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(int64_t))) n=0;
    return a >> n;
}

inline int128_t ASR(int128_t a, int n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(int128_t))) n=0;
    return a >> n;
}

#else // SIGNED_SHIFTS_ARE_ARITHMETIC

// It could be that a>>n does something "odd" for negative a, for instance
// not preserving the sign bit. I perform the main part of the shift in
// unsigned mode and put in the extra copies of it manually. I do not expect
// this code to be activated on any ordinary computer!

inline int32_t ASR(int32_t a, int n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(int32_t))) n=0;
    uint32_t r = (static_cast<uint32_t>(a)) >> n;
    uint32_t signbit = (static_cast<uint32_t>(a)) >>
                                 (8*sizeof(uint32_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(uint32_t) - n));
    return static_cast<int32_t>(r);
}

inline int64_t ASR(int64_t a, int n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(int64_t))) n=0;
    uint64_t r = (static_cast<uint64_t>(a)) >> n;
    uint64_t signbit = (static_cast<uint64_t>(a)) >>
                                 (8*sizeof(uint64_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(uint64_t) - n));
    return static_cast<int64_t>(r);
}

inline int128_t ASR(int128_t a, int n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(int128_t))) n=0;
    uint128_t r = (static_cast<uint128_t>(a)) >> n;
    uint64_t signbit = (static_cast<uint128_t>(a)) >>
                                 (8*sizeof(uint128_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(uint128_t) - n));
    return static_cast<int128_t>(r);
}

#endif // SIGNED_SHIFTS_ARE_ARITHMETIC


// The behaviour of left shifts on negative (signed) values seems to be
// labelled as undefined in C/C++, so any time I am going to do a left shift
// I need to work in an unsigned type. Rather than messing with templates
// again I will have versions for each possible width that I might use.

inline int32_t ASL(int32_t a, int n)
{   if (n < 0 || n>=8*static_cast<int>(sizeof(uint32_t))) n = 0;
    return static_cast<int32_t>((static_cast<uint32_t>(a)) << n);
}

inline int64_t ASL(int64_t a, int n)
{   if (n < 0 || n>=8*static_cast<int>(sizeof(uint64_t))) n = 0;
    return static_cast<int64_t>((static_cast<uint64_t>(a)) << n);
}

inline uint64_t ASL(uint64_t a, int n)
{   if (n < 0 || n>=8*static_cast<int>(sizeof(uint64_t))) n = 0;
    return a << n;
}

// It is useful to have some integer constants that I KNOW are 64-bit
// wide or that I KNOW are the width of pointers - these are for instance
// for us in code of that shape (x & (1U<<n)) where I need the "1" to be at
// least as wide as x and it would be excessive for it to be wider.

INLINE_VAR const uintptr_t uptr_1 = static_cast<uintptr_t>(1);
INLINE_VAR const uint64_t u64_1 = static_cast<uint64_t>(1);

#endif // header_machine_h

// end machine.h
