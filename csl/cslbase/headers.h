// headers.h                               Copyright (C) 2005-2017 Codemist

#ifndef header_headers_h
#define header_headers_h 1

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

//
// #include the majority of the header files needed by CSL code.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef DEBUG
#define NDEBUG 1
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

// At some stage I might wish to move to "#include <cstdio>" etc however
// that would put things in the std: namespace, and the killer for me is
// that with g++ I can then not find putc_unlocked and getc_unlocked.

// The following need to be defined so that the useful C macros in
// stdint.h get defined. They reflect an ugly gulf between C and C++.
// Well this is a gulf that USED to exist and these should not longer be
// required - but sometimes I may try building an somewhat ancient platforms
// so I use them... if you have an up to date C++ compiler an integer
// literal written with very many digits will be treated as of some suitably
// wide type. But if I go back to somewhat ancient verisions I NEED to write
// UINT64_C(0x1234567812345678) to get what I need. Also if you have a new
// enough C++ compiler you should get limits without needing to ask for them
// this way...

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif

#ifdef WIN32
// The aim here is to avoid use of the Microsoft versions of printf and
// friends and (hence) allow g++ to parse and check format strings reliably.
#define __USE_MINGW_ANSI_STDIO 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <exception>

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#else
// I am also going to rely on correctness including on the 64-bit mingw
// compilers where at one stage I had to do special things here to work
// around a temporary issue that related to their use of the Microsoft
// C libraries rather than the GNU ones.
#error inttypes.h is now required for building CSL
#endif

#include <limits.h>

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "syscsl.h"
#include "arith.h"
#include "entries.h"
#include "proc.h"
#include "stream.h"
#include "cslread.h"
#include "inthash.h"
#include "lispthrow.h"

#if HAVE_LIBWX
#include "wxfwin.h"
#else
#include "fwin.h"
#endif

#ifdef HAVE_CRLIBM
//
// crlibm aims to produce correctly rounded results in all cases.
// The functions from it selected here are the ones that round to
// nearest. I think I will now ALWAYS use it.
//

#include "crlibm.h"

#undef sin
#undef cos
#undef tan
#undef sinh
#undef cosh
#undef asin
#undef acos
#undef atan
#undef exp
#undef exp2
#undef log
#undef log2
#undef log10
#undef pow

#define sin        sin_rn
#define cos        cos_rn
#define tan        tan_rn
#define sinh       sinh_rn
#define cosh       cosh_rn
#define asin       asin_rn
#define acos       acos_rn
#define atan       atan_rn
#define exp        exp_rn
#define exp2       exp2_rn
#define log        log_rn
#define log2       log2_rn
#define log10      log10_rn
#define pow        pow_rn

#endif // HAVE_CRLIBM

#endif // this header included already

// end of headers.h
