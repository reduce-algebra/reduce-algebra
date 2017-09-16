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

#include "machine.h"
#include "int128_t.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "syscsl.h"

namespace mersenne_twister
{
// The Mersenne-twister code defines functions with names and signatures
// that exactly match various standard library routines, so I will wrap
// both declarations and implementation in a namespace that keeps things
// separated. Also the header file defined __STDC_LIMIT_MACROS and that can
// lead to redefinition messages unless I mess about a bit. I had thought
// of including this header before any of mine to avoid that trouble, but
// then it includes <stdint.h> and <inttypes.h> with __STDC_LIMIT_MACROS
// defined nicely, but not __STDC_FORMAT_MACROS. This is all a bit frustrating
// in that those silly macros are just set here for backwards compatibility
// and with modern C++ compilers they should be irrelevant!
  #undef __STDC_LIMIT_MACROS
  #include "mersenne-twister.h"
  #undef __STDC_LIMIT_MACROS
  #define __STDC_LIMIT_MACROS 1
}

#include "arith.h"
#include "entries.h"
#include "proc.h"
#include "stream.h"
#include "cslread.h"
#include "inthash.h"
#include "lispthrow.h"
#include "version.h"

#if HAVE_LIBWX
#include "wxfwin.h"
#else
#include "fwin.h"
#endif

#ifdef HAVE_CRLIBM
// crlibm aims to produce correctly rounded results in all cases.
// The functions from it selected here are the ones that round to
// nearest. I think I will now ALWAYS use it.

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

namespace FX {
}

using namespace FX;

#endif // header_headers_h

// end of headers.h
