// generic.cpp                                  Copyright (C) 2026 Codemist

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

// This is for any extra out-of-line code I need as part of the scheme
// that dispatches on and handles numbers of many sorts.

#include "headers.h"

namespace CSL_LISP
{
using namespace arithlib_implementation;


LispObject gPlus::RR(LispObject p1, LispObject q1,
                     LispObject p2, LispObject q2)
{
// p1/q1 + p2/q2 will have denominator (q1*q2)/g where g = gcd(q1,q2) and
// numerator (p1*(q2/g) - p2*(q1/g) but reduced to lowest terms.
    LispObject g = G<gGcdn>(q1, q2);
    LispObject q1a = G<gQuotient>(q1, g);
    LispObject q2a = G<gQuotient>(q2, g);
    LispObject p = G<gDifference>(G<gTimes>(p1, q2a), G<gTimes>(p2, q1a));
    LispObject q = G<gTimes>(q1, q2a);
    g = G<gGcdn>(p, q);
    return make_ratio(G<gQuotient>(p, g), G<gQuotient>(q, g));
}

LispObject gDifference::RR(LispObject p1, LispObject q1,
                           LispObject p2, LispObject q2)
{
// p1/q1 + p2/q2 will have denominator (q1*q2)/g where g = gcd(q1,q2) and
// numerator (p1*(q2/g) + p2*(q1/g) but reduced to lowest terms.
    LispObject g = G<gGcdn>(q1, q2);
    LispObject q1a = G<gQuotient>(q1, g);
    LispObject q2a = G<gQuotient>(q2, g);
    LispObject p = G<gPlus>(G<gTimes>(p1, q2a), G<gTimes>(p2, q1a));
    LispObject q = G<gTimes>(q1, q2a);
    g = G<gGcdn>(p, q);
    return make_ratio(G<gQuotient>(p, g), G<gQuotient>(q, g));
}


LispObject gTimes::RR(LispObject p1, LispObject q1,
                      LispObject p2, LispObject q2)
{
// (p1/q1) * (p2/q2) => ((p1/g1)*(p2/g2)) / ((q1/g2)*(q2/g1))
// where g1=gcd(p1,q2) and g2=gcd(p2,q1)
    LispObject g1 = G<gGcdn>(p1, q2);
    LispObject g2 = G<gGcdn>(p2, q1);
    LispObject p = G<gTimes>(G<gQuotient>(p1, g1),
                             G<gQuotient>(p2, g2));
    LispObject q = G<gTimes>(G<gQuotient>(q1, g2),
                             G<gQuotient>(q2, g1));
    return make_ratio(p, q);
}

LispObject gExpt::RR(LispObject p1, LispObject q1,
                     LispObject p2, LispObject q2)
{   pending();
}

LispObject gExpt::CC(LispObject r1, LispObject i1,
                     LispObject r2, LispObject i2)
{   pending();
}

LispObject gQuotient::RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2)
{   if (G<gMinusp>(p2))
        return gTimes::RR(p1, q1, G<gMinus>(q2), G<gMinus>(p2));
    else return gTimes::RR(p1, q1, q2, p2);
}

LispObject gQuotient::CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2)
{
// (a+ib)/(c+id) can be calculated by multiplying numerator and
// denominator by (c-id) to get
//    ((a+ib)*(c-id)) / (c^2+d^2)
// Note that as for complex multiplication the numerator should be
// calculated using fused-multiply-add in floating point cases. Also
// if c or d are rather extreme values c^2+d^2 or the numerator may
// underfow or overflow prematurely, so a proper implementation
// will scale values early on.
// Also the code that dispatches will tend to pass values with
// zero imaginary part, so I deal with that specially here.
    if (G<gZerop>(i2))
        return make_complex(G<gQuotient>(r1, r2), G<gQuotient>(i1, r2));
    LispObject p = gTimes::CC(r1, i1, r2, G<gMinus>(i2));
    LispObject q = G<gPlus>(G<gTimes>(r1, r2), G<gTimes>(i1, i2));
    return make_complex(G<gQuotient>(real_part(p), q),
                        G<gQuotient>(imag_part(p), q));
}

LispObject gDivide::RR(LispObject p1, LispObject q1,
                       LispObject p2, LispObject q2)
{   if (G<gMinusp>(p2))
        return cons(gTimes::RR(p1, q1, G<gMinus>(q2), G<gMinus>(p2)),
                    fixnum_of_int(0));
    else return cons(gTimes::RR(p1, q1, q2, p2),
                     fixnum_of_int(0));
}

LispObject gDivide::CC(LispObject r1, LispObject i1,
                       LispObject r2, LispObject i2)
{   if (G<gZerop>(i2))
        return cons(make_complex(G<gQuotient>(r1, r2), G<gQuotient>(i1, r2)),
                    fixnum_of_int(0));
    LispObject p = gTimes::CC(r1, i1, r2, G<gMinus>(i2));
    LispObject q = G<gPlus>(G<gTimes>(r1, r2), G<gTimes>(i1, i2));
    return cons(make_complex(G<gQuotient>(real_part(p), q),
                        G<gQuotient>(imag_part(p), q)),
                fixnum_of_int(0));
}

LispObject gCLQuotient::RR(LispObject p1, LispObject q1,
                           LispObject p2, LispObject q2)
{   if (G<gMinusp>(p2))
        return gTimes::RR(p1, q1, G<gMinus>(q2), G<gMinus>(p2));
    else return gTimes::RR(p1, q1, q2, p2);
}

LispObject gCLQuotient::CC(LispObject r1, LispObject i1,
                           LispObject r2, LispObject i2)
{
    if (G<gZerop>(i2))
        return make_complex(G<gQuotient>(r1, r2), G<gQuotient>(i1, r2));
    LispObject p = gTimes::CC(r1, i1, r2, G<gMinus>(i2));
    LispObject q = G<gPlus>(G<gTimes>(r1, r2), G<gTimes>(i1, i2));
    return make_complex(G<gQuotient>(real_part(p), q),
                        G<gQuotient>(imag_part(p), q));
}

LispObject gRemainder::RR(LispObject p1, LispObject q1,
                                 LispObject p2, LispObject q2)
{   return fixnum_of_int(0);
}

LispObject gRemainder::CC(LispObject r1, LispObject i1,
                                 LispObject r2, LispObject i2)
{   return fixnum_of_int(0);
}

LispObject gCeiling::RR(LispObject p1, LispObject q1,
                        LispObject p2, LispObject q2)
{   pending();
}

LispObject gCeiling::CC(LispObject r1, LispObject i1,
                        LispObject r2, LispObject i2)
{   pending();
}

LispObject gFceiling::RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2)
{   pending();
}

LispObject gFceiling::CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2)
{   pending();
}

LispObject gFfloor::RR(LispObject p1, LispObject q1,
                                 LispObject p2, LispObject q2)
{   pending();
}

LispObject gFfloor::CC(LispObject r1, LispObject i1,
                       LispObject r2, LispObject i2)
{   pending();
}

LispObject gFloor::RR(LispObject p1, LispObject q1,
                      LispObject p2, LispObject q2)
{   pending();
}

LispObject gFloor::CC(LispObject r1, LispObject i1,
                      LispObject r2, LispObject i2)
{   pending();
}

LispObject gFtruncate::RR(LispObject p1, LispObject q1,
                          LispObject p2, LispObject q2)
{   pending();
}

LispObject gFtruncate::CC(LispObject r1, LispObject i1,
                          LispObject r2, LispObject i2)
{   pending();
}

LispObject gTruncate::RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2)
{   pending();
}

LispObject gTruncate::CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2)
{   pending();
}

} // end of namespace


// end of generic.cpp
