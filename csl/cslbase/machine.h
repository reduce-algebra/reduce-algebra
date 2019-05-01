// machine.h                               Copyright (C) 1990-2019 Codemist

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
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG 1
#endif
#endif

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
#endif

//
// I will check a number of things before I try to use sigaltstack()
//
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif

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
#else
#define INLINE_VAR static
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
#endif

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif

// At some stage I might wish to move to "#include <cstdio>" etc however
// that would put things in the std: namespace, and the killer for me is
// that with g++ I can then not find putc_unlocked and getc_unlocked. Well
// I bet that I can if I try a bit harder...

#ifdef WIN32
// The aim here is to avoid use of the Microsoft versions of printf and
// friends and (hence) allow g++ to parse and check format strings reliably.
#define __USE_MINGW_ANSI_STDIO 1
#endif

#ifdef WIN32

#include <winsock.h>
#include <windows.h>

#else // WIN32

#define unix_posix 1        // Assume all non-windows systems are Unix!
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
#endif

#endif //WIN32

// I should possibly migrate to use of <iostream> rather than <stdio.h>,
// but doing so will involve changes across rather a latge swathe of the
// code! But I will make the iostream stuff available...
#include <iostream>
// I might also migrate from using <stdio.h> to using <cstdio> and face up to
// any namespace issues that are caused that way... But not today.
#include <stdio.h>
// Similarly I should probably go either "#include <cstdlib>" or just
// "#include <stdlib>" and in general migrate to be "more C++ than C"
// with regard to all libraries. Maybe the main issue there will be that
// I will need to fuss about namespaces at least a bit. That could be sensible
// anyway!
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <exception>
#include <errno.h>
#include <assert.h>

// As of May 2018 I will rely in C++11 for random number and thread support...

#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

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

#include <ffi.h>

#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL

extern "C"
{
// At present softfloat.h needs inclusion in C mode not C++ mode.
// This must be included before tags.h.

#include "softfloat.h"
}


//
// I will decode information that config.h has given me and define a simple
// symbol SOCKETS if I can use sockets...
//
//
#if !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#endif

#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif

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

// In this case I can make it simpler for the compiler! Something that is
// "implementation defined" is much safer to use than anything that is
// "undefined" in that the optimiser has to preserve whetever semantics the
// implementation settled on!

inline int32_t ASR(int32_t a, int n)
{   if (n<0 || n>=8*(int)sizeof(int32_t)) n=0;
    return a >> n;
}

inline int64_t ASR(int64_t a, int n)
{   if (n<0 || n>=8*(int)sizeof(int64_t)) n=0;
    return a >> n;
}

#else // SIGNED_SHIFTS_ARE_ARITHMETIC

inline int32_t ASR(int32_t a, int n)
{   if (n<0 || n>=8*(int)sizeof(int32_t)) n=0;
    uint32_t r = ((uint32_t)a) >> n;
    uint32_t signbit = ((uint32_t)a) >> (8*sizeof(uint32_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(uint32_t) - n);
    return (int32_t)r;
}

inline int64_t ASR(int64_t a, int n)
{   if (n<0 || n>=8*(int)sizeof(int64_t)) n=0;
    uint64_t r = ((uint64_t)a) >> n;
    uint64_t signbit = ((uint64_t)a) >> (8*sizeof(uint64_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(uint64_t) - n);
    return (int64_t)r;
}

#endif // SIGNED_SHIFTS_ARE_ARITHMETIC


// The behaviour of left shifts on negative (signed) values seems to be
// labelled as undefined in C/C++, so any time I am going to do a left shift
// I need to work in an unsigned type. Rather than messing with templates
// again I will have versions for each possible width that I might use.

inline int32_t ASL(int32_t a, int n)
{   if (n < 0 || n>=8*(int)sizeof(uint32_t)) n = 0;
    return (int32_t)(((uint32_t)a) << n);
}

inline int64_t ASL(int64_t a, int n)
{   if (n < 0 || n>=8*(int)sizeof(uint64_t)) n = 0;
    return (int64_t)(((uint64_t)a) << n);
}

inline uint64_t ASL(uint64_t a, int n)
{   if (n < 0 || n>=8*(int)sizeof(uint64_t)) n = 0;
    return a << n;
}

// Tidy up re possible 128-bit arithemetic support.

#ifdef HAVE_UINT128_T
#define HAVE_NATIVE_UINT128 1
#elif defined HAVE_UNSIGNED___INT128
typedef unsigned __int128 uint128_t;
#define HAVE_NATIVE_UINT128
#else
#include "uint128_t.h"  // For software emulation. Needs C++-11
#endif

#ifdef HAVE_INT128_T
#define HAVE_NATIVE_INT128 1
#elif defined HAVE___INT128
typedef __int128 int128_t;
#define HAVE_NATIVE_INT128
#elif defined HAVE_UINT128_T || defined HAVE_UNSIGNED___INT128
#error Seem to have unsigned 128-bit type but not a signed one!
#endif

// With luck that will have regularised the situation with regard to
// integer types!

#ifdef MAXALING4

// In the horrid case where malloc might return a fairly unaligned block
// of memory I will allocate a block that is 32-bytes larger than will be
// required. If I round that address up to be a multiple of 16 I can then
// guarantee to leave 16 bytes that are both free and aligned at a 16 byte
// boundary. I put a "void *" value in there (it will very probably not use
// up all the space, but I do not mind) pointing at the original start of
// the block.

inline void *aligned_malloc(size_t n)
{   void *p = (void *)malloc(n + 32);
    if (p == NULL) return p;
    void *r = (void *)((((uintptr_t)p + 15) & -(uint64_t)16) + 16);
    (void *)((uintptr_t)r - 16) = p;
    return r;
}

// To free something I need to retrieve the pointer to the genuine block
// start and hand that to free().

inline void aligned_free(void *p)
{   if (p == NULL) return;
    free(*(void *)((uintptr_t)p - 16));
}
#else // MAXALING4

// IN the hugely more common case where malloc does align things to at least
// 8 byte boundaries I can use malloc() and free() directly.

inline void *aligned_malloc(size_t n)
{   return (void *)malloc(n);
}

inline void aligned_free(void *p)
{   free(p);
}

#endif // MAXALING4

#endif // header_machine_h

// end machine.h
