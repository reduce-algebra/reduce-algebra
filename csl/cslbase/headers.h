/* headers.h                       Copyright (C) 2005-2008 Codemist Ltd */

#ifndef header_headers_h
#define header_headers_h 1



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

/* Signature: 19ae4f8f 24-May-2008 */

/*
 * #include the majority of the header files needed by CSL code.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>

#ifndef UNDER_CE
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
#include "stream.h"
#include "cslread.h"

#ifdef HAVE_FWIN
#include "fwin.h"
#endif

#if 0

/*
 * This hack relates to the mingw-w64 compiler. Up to around cvs revision
 * 352, dated around 17 April 2008, the C runtime had trouble calling the
 * Microsoft implementatons of setjmp and longjmp. The gcc intrinsics
 * mapped onto here have their own problems, but could hold the fort
 * for a while. I intend to remove this trace of history once the 64-bit
 * mingw has stabilised just a bit more.
 */

#if !defined MICROSOFT_C && defined WIN64
#undef setjmp
#undef longjmp
#define setjmp  __builtin_setjmp
#define longjmp __builtin_longjmp
#endif

#endif /* 0 */

#endif /* this header included already */

/* end of headers.h */

