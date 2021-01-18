// arith-modular.cpp                       Copyright (C) 2020-2021 Codemist

#ifdef ARITHLIB

// $Id$


/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

#include "headers.h"
#include "dispatch.h"

using number_dispatcher::Fixnum;
// uint64_t *
using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
// double
using number_dispatcher::Flt;
using number_dispatcher::LFlt;

LispObject ModularPlus::op(LispObject a, LispObject b)
{   return
        number_dispatcher::ibinary<LispObject,ModularPlus>("modular-plus", a,
                b);
}

LispObject ModularPlus::op(LispObject a, Fixnum b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularPlus>("modular-plus", a,
                b);
}

LispObject ModularPlus::op(LispObject a, uint64_t *b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularPlus>("modular-plus", a,
                b);
}

LispObject ModularPlus::op(Fixnum a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularPlus>("modular-plus", a,
                b);
}

LispObject ModularPlus::op(uint64_t *a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularPlus>("modular-plus", a,
                b);
}

// fixnum + fixnum
LispObject ModularPlus::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularPlus::op(a.intval(), b.intval());
}
// bignum + fixnum
LispObject ModularPlus::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularPlus::op(a, b.intval());
}
// fixnum + bignum
LispObject ModularPlus::op(Fixnum a, uint64_t *b)
{   return ModularPlus::op(b, a);
}
// bignum + bignum
LispObject ModularPlus::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularPlus::op(a, b);
}

LispObject ModularTimes::op(LispObject a, LispObject b)
{   return
        number_dispatcher::ibinary<LispObject,ModularTimes>("modular-times",
                a, b);
}

LispObject ModularTimes::op(LispObject a, Fixnum b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularTimes>("modular-times",
                a, b);
}

LispObject ModularTimes::op(LispObject a, uint64_t *b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularTimes>("modular-times",
                a, b);
}

LispObject ModularTimes::op(Fixnum a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularTimes>("modular-times",
                a, b);
}

LispObject ModularTimes::op(uint64_t *a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularTimes>("modular-times",
                a, b);
}

// fixnum * fixnum
LispObject ModularTimes::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularTimes::op(a.intval(),
            b.intval());
}
// bignum * fixnum
LispObject ModularTimes::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularTimes::op(a, b.intval());
}
// fixnum * bignum
LispObject ModularTimes::op(Fixnum a, uint64_t *b)
{   return ModularTimes::op(b, a);
}
// bignum * bignum
LispObject ModularTimes::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularTimes::op(a, b);
}

LispObject ModularDifference::op(LispObject a, LispObject b)
{   return
        number_dispatcher::ibinary<LispObject,ModularDifference>("modular-difference",
                a, b);
}

LispObject ModularDifference::op(LispObject a, Fixnum b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularDifference>("modular-difference",
                a, b);
}

LispObject ModularDifference::op(LispObject a, uint64_t *b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularDifference>("modular-difference",
                a, b);
}

LispObject ModularDifference::op(Fixnum a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularDifference>("modular-difference",
                a, b);
}

LispObject ModularDifference::op(uint64_t *a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularDifference>("modular-difference",
                a, b);
}

// fixnum - fixnum
LispObject ModularDifference::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularDifference::op(a.intval(),
            b.intval());
}
// bignum - fixnum
LispObject ModularDifference::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularDifference::op(a, b.intval());
}
// fixnum - bignum
LispObject ModularDifference::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::ModularDifference::op(a.intval(), b);
}
// bignum - bignum
LispObject ModularDifference::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularDifference::op(a, b);
}

LispObject ModularQuotient::op(LispObject a, LispObject b)
{   return
        number_dispatcher::ibinary<LispObject,ModularQuotient>("modular-quotient",
                a, b);
}

LispObject ModularQuotient::op(LispObject a, Fixnum b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularQuotient>("modular-quotient",
                a, b);
}

LispObject ModularQuotient::op(LispObject a, uint64_t *b)
{   return
        number_dispatcher::ibinaryR<LispObject,ModularQuotient>("modular-quotient",
                a, b);
}

LispObject ModularQuotient::op(Fixnum a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularQuotient>("modular-quotient",
                a, b);
}

LispObject ModularQuotient::op(uint64_t *a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,ModularQuotient>("modular-quotient",
                a, b);
}

// fixnum / fixnum
LispObject ModularQuotient::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularQuotient::op(a.intval(),
            b.intval());
}
// bignum / fixnum
LispObject ModularQuotient::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularQuotient::op(a, b.intval());
}
// fixnum / bignum
LispObject ModularQuotient::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::ModularQuotient::op(a.intval(), b);
}
// bignum / bignum
LispObject ModularQuotient::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularQuotient::op(a, b);
}

LispObject ModularExpt::op(LispObject a, LispObject b)
{   return
        number_dispatcher::ibinary<LispObject,ModularExpt>("modular-expt", a,
                b);
}

// fixnum ** n
LispObject ModularExpt::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularExpt::op(a.intval(), b.intval());
}
// bignum ** n
LispObject ModularExpt::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularExpt::op(a, b.intval());
}

// fixnum ** n
LispObject ModularExpt::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::ModularExpt::op(a.intval(), b);
}
// bignum ** n
LispObject ModularExpt::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularExpt::op(a, b);
}

LispObject ModularReciprocal::op(LispObject a)
{   return
        number_dispatcher::iunary<LispObject,ModularReciprocal>("modular-reciprocal",
                a);
}

// -fixnum
LispObject ModularReciprocal::op(Fixnum a)
{   return arithlib_lowlevel::ModularReciprocal::op(a.intval());
}
// -bignum
LispObject ModularReciprocal::op(uint64_t *a)
{   return arithlib_lowlevel::ModularReciprocal::op(a);
}

LispObject ModularMinus::op(LispObject a)
{   return
        number_dispatcher::iunary<LispObject,ModularMinus>("modular-minus",
                a);
}

// -fixnum
LispObject ModularMinus::op(Fixnum a)
{   return arithlib_lowlevel::ModularMinus::op(a.intval());
}
// -bignum
LispObject ModularMinus::op(uint64_t *a)
{   return arithlib_lowlevel::ModularMinus::op(a);
}

LispObject SetModulus::op(LispObject a)
{   return
        number_dispatcher::iunary<LispObject,SetModulus>("set-modulus", a);
}

// -fixnum
LispObject SetModulus::op(Fixnum a)
{   return arithlib_lowlevel::SetModulus::op(a.intval());
}
// -bignum
LispObject SetModulus::op(uint64_t *a)
{   return arithlib_lowlevel::SetModulus::op(a);
}

LispObject ModularNumber::op(LispObject a)
{   return
        number_dispatcher::iunary<LispObject,ModularNumber>("modular-number",
                a);
}

// -fixnum
LispObject ModularNumber::op(Fixnum a)
{   return arithlib_lowlevel::ModularNumber::op(a.intval());
}
// -bignum
LispObject ModularNumber::op(uint64_t *a)
{   return arithlib_lowlevel::ModularNumber::op(a);
}

#endif // ARITHLIB

// end of arith-modular.cpp

