/* headers.h                       Copyright (C) 2005-2010 Codemist Ltd */

#ifndef header_headers_h
#define header_headers_h 1



/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
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

/* $Id$ */

/*
 * #include the majority of the header files needed by CSL code.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/*
 * I will check a number of things before I try to use sigaltstack()
 */
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <time.h>
#include <stdarg.h>

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#else
/*
 * If <inttypes.h> is not available I will try some things that probably
 * work on the most common gcc systems but which may need more work on
 * other platforms.
 */
#if defined __x86_64 || (defined __SIZEOF_PTRDIFF_T__ && __SIZEOF_PTRDIFF_T__ == 8)
#define PRIdPTR "lld"
#define PRIuPTR "llu"
#define PRIxPTR "llx"
#else
#define PRIdPTR "d"
#define PRIuPTR "u"
#define PRIxPTR "x"
#endif
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef WIN64
/* The mingw64 build that I use seems to get messed up by inttypes.h */
#undef PRIdPTR
#undef PRIuPTR
#undef PRIxPTR
#define PRIdPTR "lld"
#define PRIuPTR "llu"
#define PRIxPTR "llx"
#endif

#ifndef UNDER_CE
/*
 * The test for UNDER_CE is a little odd here, but when I once compiled a
 * version of this to run under Windows CE on an Ipaq I could not have
 * signal handling there hence this. One mighht have expected me to say
 * #ifdef HAVE_SIGNAL_H but maybe the file existed in the world where I
 * cross-built for CE and that led to pain? I now forget.
 */
#include <signal.h>
#endif

#ifndef __cplusplus
#include <setjmp.h>
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

#ifdef HAVE_FWIN
#if HAVE_LIBWX
#include "wxfwin.h"
#else
#include "fwin.h"
#endif
#endif

#ifdef HAVE_CRLIBM
/*
 * crlibm aims to produce correctly rounded results in all cases.
 * The functions from it selected here are the ones that round to
 * nearest.
 */

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

#endif /* HAVE_CRLIBM */


#endif /* this header included already */

/* end of headers.h */

