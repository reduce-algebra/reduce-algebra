// arith-logops.cpp                             Copyright (C) 2019 Codemist

#ifdef ARITHLIB

// $Id$


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

// Logand, Logor etc. Also Shifts.

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


LispObject Logand::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logand>("logand", a, b);
}
LispObject Logand::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logand>("logand", a, b);
}
LispObject Logand::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logand>("logand", a, b);
}
LispObject Logand::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logand>("logand", a, b);
}

LispObject Logand::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logand>("logand", a, b);
}
// fixnum & fixnum
LispObject Logand::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logand::op(a.intval(), b.intval());
}
// bignum & fixnum
LispObject Logand::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logand::op(a, b.intval());
}
// fixnum & bignum
LispObject Logand::op(Fixnum a, std::uint64_t *b)
{   return Logand::op(b, a);
}
// bignum & bignum
LispObject Logand::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Logand::op(a, b);
}

LispObject Logor::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logor>("logor", a, b);
}
LispObject Logor::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logor>("logor", a, b);
}
LispObject Logor::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logor>("logor", a, b);
}
LispObject Logor::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logor>("logor", a, b);
}

LispObject Logor::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logor>("logor", a, b);
}
// fixnum | fixnum
LispObject Logor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logor::op(a.intval(), b.intval());
}
// bignum | fixnum
LispObject Logor::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logor::op(a, b.intval());
}
// fixnum | bignum
LispObject Logor::op(Fixnum a, std::uint64_t *b)
{   return Logor::op(b, a);
}
// bignum | bignum
LispObject Logor::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Logor::op(a, b);
}

LispObject Logxor::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logxor>("logxor", a, b);
}
LispObject Logxor::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logxor>("logxor", a, b);
}
LispObject Logxor::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logxor>("logxor", a, b);
}
LispObject Logxor::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logxor>("logxor", a, b);
}

LispObject Logxor::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logxor>("logxor", a, b);
}
// fixnum ^ fixnum
LispObject Logxor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logxor::op(a.intval(), b.intval());
}
// bignum ^ fixnum
LispObject Logxor::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logxor::op(a, b.intval());
}
// fixnum ^ bignum
LispObject Logxor::op(Fixnum a, std::uint64_t *b)
{   return Logxor::op(b, a);
}
// bignum ^ bignum
LispObject Logxor::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Logxor::op(a, b);
}

LispObject Logeqv::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logeqv>("logeqv", a, b);
}
LispObject Logeqv::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logeqv>("logeqv", a, b);
}
LispObject Logeqv::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logeqv>("logeqv", a, b);
}
LispObject Logeqv::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logeqv>("logeqv", a, b);
}

LispObject Logeqv::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logeqv>("logeqv", a, b);
}
// fixnum  eqv  fixnum
LispObject Logeqv::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logeqv::op(a.intval(), b.intval());
}
// bignum  eqv  fixnum
LispObject Logeqv::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logeqv::op(a, b.intval());
}
// fixnum  eqv  bignum
LispObject Logeqv::op(Fixnum a, std::uint64_t *b)
{   return Logeqv::op(b, a);
}
// bignum  eqv  bignum
LispObject Logeqv::op(std::uint64_t *a, std::uint64_t *b)
{   return arithlib_lowlevel::Logeqv::op(a, b);
}
LispObject Lognot::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Lognot>("lognot", a);
}
LispObject Lognot::op(Fixnum a)
{   return arithlib_lowlevel::Lognot::op(a.intval());
}
LispObject Lognot::op(std::uint64_t *a)
{   return arithlib_lowlevel::Lognot::op(a);
}

LispObject Logcount::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Logcount>("logcount", a);
}
LispObject Logcount::op(Fixnum a)
{   return arithlib_lowlevel::Logcount::op(a.intval());
}
LispObject Logcount::op(std::uint64_t *a)
{   return arithlib_lowlevel::Logcount::op(a);
}

LispObject LeftShift::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,LeftShift>("lshift", a, b);
}
LispObject LeftShift::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,LeftShift>("lshift", a, b);
}
LispObject LeftShift::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,LeftShift>("lshift", a, b);
}
LispObject LeftShift::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,LeftShift>("lshift", a, b);
}

LispObject LeftShift::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,LeftShift>("lshift", a, b);
}
// fixnum << fixnum
LispObject LeftShift::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::LeftShift::op(a.intval(), b.intval());
}
// bignum << fixnum
LispObject LeftShift::op(std::uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::LeftShift::op(a, b.intval());
}
LispObject bignum_value(std::uint64_t *a)
{   return number_dispatcher::bignum_value(a);
}
// fixnum << bignum
LispObject LeftShift::op(Fixnum a, std::uint64_t *b)
{   if (Minusp::op(b))
    {   if (Minusp::op(a)) return fixnum_of_int(-1);
        else return fixnum_of_int(0);
    }
    else if (Zerop::op(a)) return fixnum_of_int(0);
    else aerror1("left shift by value that is too large", bignum_value(b));
}
// bignum << bignum
LispObject LeftShift::op(std::uint64_t *a, std::uint64_t *b)
{   if (Minusp::op(b))
    {   if (Minusp::op(a)) return fixnum_of_int(-1);
        else return fixnum_of_int(0);
    }
    else aerror1("left shift by value that is too large", bignum_value(b));

}

LispObject RightShift::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,RightShift>("rshift", a, b);
}
LispObject RightShift::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,RightShift>("rshift", a, b);
}
LispObject RightShift::op(LispObject a, std::uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,RightShift>("rshift", a, b);
}
LispObject RightShift::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,RightShift>("rshift", a, b);
}

LispObject RightShift::op(std::uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,RightShift>("rshift", a, b);
}
// fixnum >> fixnum
LispObject RightShift::op(Fixnum a, Fixnum b)
{   if (Minusp::op(b))
        return arithlib_lowlevel::LeftShift::op(a.intval(), -b.intval());
    else return arithlib_lowlevel::RightShift::op(a.intval(), b.intval());
}
// bignum >> fixnum
LispObject RightShift::op(std::uint64_t *a, Fixnum b)
{   if (Minusp::op(b))
        return arithlib_lowlevel::LeftShift::op(a, -b.intval());
    else return arithlib_lowlevel::RightShift::op(a, b.intval());

}
// fixnum >> bignum
LispObject RightShift::op(Fixnum a, std::uint64_t *b)
{   if (Minusp::op(b))
    {   if (Zerop::op(a)) return fixnum_of_int(0);
        else aerror1("right shift by value that is too negative",
                     bignum_value(b));
    }
    else if (Minusp::op(a)) return fixnum_of_int(-1);
    else return fixnum_of_int(0);
}
// bignum >> bignum
LispObject RightShift::op(std::uint64_t *a, std::uint64_t *b)
{   if (Minusp::op(b))
        aerror1("right shift by value that is too negative", bignum_value(b));
    else if (Minusp::op(a)) return fixnum_of_int(-1);
    else return fixnum_of_int(0);
}

#endif // ARITHLIB

// end of arith-logops.cpp
