// headers.h                               Copyright (C) 2005-2025 Codemist

#ifndef header_headers_h
#define header_headers_h 1

/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

#if (defined EMBEDDED || defined ENABLE_WEBGUI)  && !defined WITHOUT_GUI
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

#include "log.h"
#include "machine.h"

// The next two are for platform-specific optimisations.
#include "threadloc.h"
#include "mymutex.h"

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
{   return std::sin(x);
}
inline double CSLcos(double x)
{   return std::cos(x);
}
inline double CSLtan(double x)
{   return std::tan(x);
}
inline double CSLsinh(double x)
{   return std::sinh(x);
}
inline double CSLcosh(double x)
{   return std::cosh(x);
}
inline double CSLasin(double x)
{   return std::asin(x);
}
inline double CSLacos(double x)
{   return std::acos(x);
}
inline double CSLatan(double x)
{   return std::atan(x);
}
inline double CSLexp(double x)
{   return std::exp(x);
}
inline double CSLexp2(double x)
{   return std::exp2(x);
}
inline double CSLlog(double x)
{   return std::log(x);
}
inline double CSLlog2(double x)
{   return std::log2(x);
}
inline double CSLlog10(double x)
{   return std::log10(x);
}
inline double CSLpow(double x, double y)
{   return std::pow(x, y);
}

#endif // HAVE_CRLIBM

#include "bitmaps.h"
#include "tags.h"

#include "cslerror.h"
#include "externs.h"
#include "lispthrow.h"
#include "newallocate.h"
#include "syscsl.h"
#include "entries.h"
#include "arith.h"
#include "proc.h"
#include "stream.h"
#include "isprime.h"
#include "cslread.h"
#include "inthash.h"
// #include "version.h"   // included by just the files that use it
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif // __EMSCRIPTEN__

#ifdef ARITHLIB
#include "arith-defs.h"
#endif // ARITHLIB

namespace CSL_LISP
{

#ifdef ARITHLIB
// Here we hava another oddity! The JIT must call different things for
// various basic arithmetic operations depending on whether ARITHLIB is
// active or not. But I want to be able to initialize the table of
// entyrypoints ina  tiday way, so this fragment sets up names that
// refer to either old or new functions so I can initialise from them.

typedef bool boolFn2(LispObject, LispObject);
typedef LispObject lispFn2(LispObject, LispObject);
typedef std::intptr_t makebigFn(arithlib_implementation::SignedDigit);

inline const boolFn2& JITlessp2Val = Lessp::op;
inline const boolFn2& JITleq2Val = Leq::op;
inline const lispFn2& JITplus2Val = Plus::op;
inline const lispFn2& JITdifference2Val = Difference::op;
inline const lispFn2& JITtimes2Val = Times::op;
inline const lispFn2& JITquotient2Val = Quotient::op;
inline const lispFn2& JITremainderVal = Remainder::op;
inline const makebigFn& JITint_from_ptrVal =
                      arithlib_implementation::intToBignum;

#else // ARITHLIB

inline const auto& JITlessp2Val = lessp2;
inline const auto& JITleq2Val = lesseq2;
inline const auto& JITplus2Val = plus2;
inline const auto& JITdifference2Val = difference2;
inline const auto& JITtimes2Val = times2;
inline const auto& JITquotient2Val = quot2;
inline const auto& JITremainderVal = Cremainder;
inline const auto& JITint_from_ptrVal = make_lisp_integerptr;

#endif // ARITHLIB

inline LispObject do_tailcall()
{   int nargs = JITerrflag;
    JITerrflag = 0;
    LispObject tocall = JITarg0;
printf("\n@@@ do_tailcall argcount=%d dest=%p\n", nargs, (void*)tocall);
    switch (nargs)
    {
    case 0:
        return qfn0(tocall)(qenv(tocall));
    case 1:
        return qfn1(tocall)(qenv(tocall), JITarg1);
    case 2:
        return qfn2(tocall)(qenv(tocall), JITarg1,JITarg2);
    case 3:
        return qfn3(tocall)(qenv(tocall), JITarg1,JITarg2,JITarg3);
    default:
        return qfn4up(tocall)(qenv(tocall), JITarg1,JITarg2,JITarg3,JITarg4);
    }
}

// Now that I have all functions declared I can set up an instance of
// the NilBlock and initialize all elements.

#define FF(a,b,c) c,
inline struct NilBlock myNilBlock =
{
    NIL_BLOCK_CONTENTS
};
#undef FF

// Finally it would be good to have names visible in global scope
// that give me access to each of the fields.

#define FF(a,b,c) \
inline a& b = myNilBlock.I##b;
NIL_BLOCK_CONTENTS
#undef FF

inline const LispObject nil =
    reinterpret_cast<LispObject>(&myNilBlock.Inil_symbol) + TAG_SYMBOL;
inline LispObject* workbase = &myNilBlock.workbaseVec[0];

} // end namespace

namespace FX
{
}

using namespace FX;

#endif // header_headers_h

// end of headers.h
