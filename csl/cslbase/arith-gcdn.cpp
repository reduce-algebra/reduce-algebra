// arith-gcdn.cpp                          Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

LispObject Gcdn::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Gcdn>("gcdn", a, b);
}

LispObject Gcdn::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Gcdn>("gcdn", a, b);
}

LispObject Gcdn::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Gcdn>("gcdn", a, b);
}

LispObject Gcdn::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Gcdn>("gcdn", a, b);
}

LispObject Gcdn::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Gcdn>("gcdn", a, b);
}

LispObject Gcdn::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Gcd::op(a.intval(), b.intval());
}
// bignum gcdn fixnum
LispObject Gcdn::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Gcd::op(a, b.intval());
}
// fixnum gcdn bignum
LispObject Gcdn::op(Fixnum a, uint64_t *b)
{   return Gcdn::op(b, a);
}
// bignum gcdn bignum
LispObject Gcdn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Gcd::op(a, b);
}

LispObject Lcmn::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Lcmn>("lcmn", a, b);
}

LispObject Lcmn::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Lcmn>("lcmn", a, b);
}

LispObject Lcmn::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Lcmn>("lcmn", a, b);
}

LispObject Lcmn::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Lcmn>("lcmn", a, b);
}

LispObject Lcmn::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Lcmn>("lcmn", a, b);
}

LispObject Lcmn::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Lcm::op(a.intval(), b.intval());
}
// bignum lcmn fixnum
LispObject Lcmn::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Lcm::op(a, b.intval());
}
// fixnum lcmn bignum
LispObject Lcmn::op(Fixnum a, uint64_t *b)
{   return Lcmn::op(b, a);
}
// bignum lcmn bignum
LispObject Lcmn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Lcm::op(a, b);
}

#endif //ARITHLIB

// end of arith-gcdn.cpp

