/* machine.h                       Copyright (C) 1990-2008 Codemist Ltd */

/*
 * This was ONCE a place where all system-specific options were detected
 * and mapped onto tidy macros that could guide subsequent compilation. Now
 * all that is handled in "config.h", which is manufactured on a per-target
 * basis by a configure-script created by autoconf.
 *
 * Now it us used for just a few tests based on what comes out of
 * config.h to set up really major further bits of configuration, where
 * the characteristic of what is done here is that it will vary from
 * target to target and it is truly pervasive in consequences.
 */



/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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

/* Signature: 149d8609 01-Jul-2009 */


#ifndef header_machine_h
#define header_machine_h 1


/*
 * I will decode information that config.h has given me and define a simple
 * symbol SOCKETS if I can use sockets...
 * 
 */
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#ifndef EMBEDDED
#define SOCKETS                  1
#endif
#endif


#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif


#ifdef WIN32
#  ifdef WIN64
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

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

/*
 * #ifdef __APPLE__
 *
 * Apple and MacOS provide a special challenge for me. It is possible to
 * compile code with a command such as
 *    gcc -arch ppc -archppc64 -archi386 ...
 * and by so doing create a two or three-way fat binary. This situation is
 * excellent, HOWEVER it causes real trouble for autoconf in any cases
 * where the results could be system-sensitive! A case where this is
 * unambiguously true relates to the size of data. So I put in some
 * old-fashioned manual treatment that will, I hope, override any values
 * found by autoconf in the relevent areas.
 *
 * Well ACTUALLY I hope and believe that Apple provides <stdint.h> and
 * so the macros set up where will never get inspected!
 *
 * Well these days they seem to have stdint.h in the kit, and so I will
 * comment this out!
 *
 *
 * #undef SIZEOF_SHORT_INT
 * #undef SIZEOF_INT
 * #undef SIZEOF_LONG
 * #undef SIZEOF_LONG_LONG
 * #undef SIZEOF_VOID_P
 * 
 * #if defined __x86_64__ || defined __ppc64__
 * #define SIZEOF_SHORT_INT  2
 * #define SIZEOF_INT        4
 * #define SIZEOF_LONG       4
 * #define SIZEOF_LONG_LONG  8
 * #define SIZEOF_VOID_P     8
 * #elif defined __i386__ ||  defined __ppc__
 * #undef SIZEOF_SHORT_INT   2
 * #undef SIZEOF_INT         4
 * #undef SIZEOF_LONG        4
 * #undef SIZEOF_LONG_LONG   8
 * #undef SIZEOF_VOID_P      4
 * #else
 * #error "Unknown architecture on a machine that says it is __APPLE__"
 * #endif
 *
 * #endif  __APPLE__
 */

/*
 * Now it appears that some systems provide types with names like
 * u_int32_t where I count uint32_t as more standard. I will adapt
 * around that here. As C compilers become more standardised this
 * will become increasingly irrelevant.
 */

#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif

#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif

#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif

/*
 * Finally if those abstract widths have not been provided I will fall
 * back on information worked out at configure-time. Note that that could
 * be delicate in the context of cross-compilation and other odd cases.
 */

#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif

#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif

#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif

#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif

#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif

#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif

#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif

#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif

#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif

#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif

#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif

#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif

/*
 * With luck that will have regularised the situation with regard to
 * integer types!
 */

#endif /* header_machine_h */

/* end machine.h */

