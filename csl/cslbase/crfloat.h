// crfloat.h                               Copyright (C) 1990-2026 Codemist

#ifndef header_crfloat_h
#define header_crfloat_h 1

// $Id$


/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

// "crlibm" is a portable library of floating point elementary functions
// guaranteed to round properly. Using it when I can is good not just
// for the accuracy but because that gets results bit for bit identical
// across platforms and so regression testing becomes easier.
// crlibm development work ceased some while ago and there is a successor
// "CORE-MATH" that carries the objective forward - but that does not
// offer an easy to pick up stand-alone version. Its objective is much
// more to get its technology merged into major and widely used maths
// libraries. So for instnce the GNU version of libc has adopted some
// of their functions and the AMD libm uses at least a few. As of 2026
// their web-site asserts that CMU Common Lisp is in the process if migrating
// to use them. If all C/C++ libraries were perfect it would not be
// necessary for me to do this here!

#ifdef HAVE_CRLIBM

// crlibm aims to produce correctly rounded results in all cases.
// The functions from it selected here are the ones that round to
// nearest (as distinct from trunc, floor or ceiling versuions). The
// code I use here only covers double precision. I am taking the view
// that I do not care very much about single precision, and crlibm
// does not support 128-bit floats and CORE-MATH only has a bit of
// support at that precision.


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


#endif // header_crfloat_h

// end of crfloat.h
