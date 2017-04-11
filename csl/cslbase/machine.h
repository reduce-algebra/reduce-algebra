// machine.h                               Copyright (C) 1990-2017 Codemist

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
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

// WIth really old versions of C++ you may not be able to write
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
// helps for printf etc) and always wrire large-value literals in the
// way that ancient systems and C required.

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif

extern "C"
{
// At present softfloat.h needs inclusion in C mode not C++ mode.
// This must be included before tags.h, but after __STDC_CONSTANT_MACROS
// has been defined.

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

#include <stdint.h>
#include <inttypes.h>

// C++ does not guarantee that intptr_t is provided, so I patch around
// that if necessary.

#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 4)
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif

#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 8)
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif

#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 4)
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif

#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 8)
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif

// Tidy up re possible 128-bit arithemetic support.

#if defined HAVE___INT128 && !defined HAVE_INT128_T
typedef __int128 int128_t;
#define HAVE_INT128_T
#endif

#if defined HAVE_UNSIGNED___INT128 && !defined HAVE_UINT128_T
typedef unsigned __int128 uint128_t;
#define HAVE_UINT128_T
#endif



// With luck that will have regularised the situation with regard to
// integer types!

#endif // header_machine_h

// end machine.h
