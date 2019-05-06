// headers.h                               Copyright (C) 2005-2019 Codemist

#ifndef header_headers_h
#define header_headers_h 1

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

//
// #include the majority of the header files needed by CSL code.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

// On a temporary basis the "experiment" I am working on is a conservative
// garbage collector. I want some of the conditionalization to be on the
// symbol CONSERVATIVE so I arrange to force that to be defined in relevant
// situations.

#if defined EXPERIMENT && !defined CONSERVATIVE
#define CONSERVATIVE 1
#endif

// There will be an hierarchy of degrees of generality in support for
// user interfaces. If EMBEDDED is defined then there will be no attempt
// at any input handling beyond simple use of getchar(). At the other
// extreme if no special symbols are defined I will link in with the FOX
// GUI toolkit (or potentially in the future some other!) so that there
// is a chance of supporting popping up a window. To get an intermediate
// configuration define WITHOUT_GUI which avoids linking in the GUI toolkit
// but attempts to use cursor-movement options on the terminal to support
// some colouring, local editing, input history etc.
// Here I arrange that if EMBEDDED has been defined I force WITHOUT_GUI to
// be used so that EMBEDDED itself just has to disable to management
// of input editing and output colouring.

#if defined EMBEDDED && !defined WITHOUT_GUI
#define WITHOUT_GUI 1
#endif

// Also force REDUCE_PROMPTS to be undefined in the EMBEDDED case. This is
// done here just to make things a bit more bullet-proof against people trying
// a build with mixed up sets of symbols predefined.
#ifdef EMBEDDED
#undef REDUCE_PROMPTS
#endif

// In places in the code I might start thinking I need to write
//   #ifndef WITHOUT_GUI
// and the double-negative there is ugly and does not aid comprehension, so
// while I will have WITHOUT_GUI as the symbol established on the outside
// I will set up WITH_GUI here to be in a complementary state.

// First explicitly undefine the symbol just to make sure.
#undef WITH_GUI

#ifndef WITHOUT_GUI
#define WITH_GUI 1
#endif // !WITHOUT_GUI

#include "machine.h"

#if HAVE_LIBWX
#include "wxfwin.h"
#else
#include "fwin.h"
#endif

#include "termed.h"

#ifdef HAVE_CRLIBM
// crlibm aims to produce correctly rounded results in all cases.
// The functions from it selected here are the ones that round to
// nearest. I think I will now ALWAYS use it.

#include "crlibm.h"

inline double CSLsin(double x)
{   return sin_rn(x);
}
inline double CSLcos(double x)
{   return cos_rn(x);
}
inline double CSLtan(double x)
{   return tan_rn(x);
}
inline double CSLsinh(double x)
{   return sinh_rn(x);
}
inline double CSLcosh(double x)
{   return cosh_rn(x);
}
inline double CSLasin(double x)
{   return asin_rn(x);
}
inline double CSLacos(double x)
{   return acos_rn(x);
}
inline double CSLatan(double x)
{   return atan_rn(x);
}
inline double CSLexp(double x)
{   return exp_rn(x);
}
inline double CSLexp2(double x)
{   return exp2_rn(x);
}
inline double CSLlog(double x)
{   return log_rn(x);
}
inline double CSLlog2(double x)
{   return log2_rn(x);
}
inline double CSLlog10(double x)
{   return log10_rn(x);
}
inline double CSLpow(double x, double y)
{   return pow_rn(x, y);
}

#else // HAVE_CRLIBM

#include <cmath>

using std::sin;
using std::cos;
using std::tan;
using std::sinh;
using std::cosh;
using std::asin;
using std::acos;
using std::atan;
using std::exp;
using std::exp2;
using std::log;
using std::log2;
using std::log10;
using std::pow;

inline double CSLsin(double x)
{   return sin(x);
}
inline double CSLcos(double x)
{   return cos(x);
}
inline double CSLtan(double x)
{   return tan(x);
}
inline double CSLsinh(double x)
{   return sinh(x);
}
inline double CSLcosh(double x)
{   return cosh(x);
}
inline double CSLasin(double x)
{   return asin(x);
}
inline double CSLacos(double x)
{   return acos(x);
}
inline double CSLatan(double x)
{   return atan(x);
}
inline double CSLexp(double x)
{   return exp(x);
}
inline double CSLexp2(double x)
{   return exp2(x);
}
inline double CSLlog(double x)
{   return log(x);
}
inline double CSLlog2(double x)
{   return log2(x);
}
inline double CSLlog10(double x)
{   return log10(x);
}
inline double CSLpow(double x, double y)
{   return pow(x, x);
}

#endif // HAVE_CRLIBM

#include "int128_t.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "allocate.h"
#include "syscsl.h"
#include "arith.h"
#include "entries.h"
#include "proc.h"
#include "stream.h"
#include "cslread.h"
#include "inthash.h"
#include "lispthrow.h"
#include "version.h"

namespace FX {
}

using namespace FX;

#endif // header_headers_h

// end of headers.h
