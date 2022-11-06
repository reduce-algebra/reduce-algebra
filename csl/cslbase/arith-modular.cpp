// arith-modular.cpp                       Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

// $Id$


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

#include "headers.h"

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

//LispObject ModularExpt::op(LispObject a, LispObject b)
//{   return
//        number_dispatcher::ibinary<LispObject,ModularExpt>("modular-expt", a,
//                b);
//}
//
//// fixnum ** n
//LispObject ModularExpt::op(Fixnum a, Fixnum b)
//{   return arithlib_lowlevel::ModularExpt::op(a.intval(), b.intval());
//}
//// bignum ** n
//LispObject ModularExpt::op(uint64_t *a, Fixnum b)
//{   return arithlib_lowlevel::ModularExpt::op(a, b.intval());
//}
//
//// fixnum ** n
//LispObject ModularExpt::op(Fixnum a, uint64_t *b)
//{   return arithlib_lowlevel::ModularExpt::op(a.intval(), b);
//}
//// bignum ** n
//LispObject ModularExpt::op(uint64_t *a, uint64_t *b)
//{   return arithlib_lowlevel::ModularExpt::op(a, b);
//}

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

LispObject SafeModularReciprocal::op(LispObject a)
{   return
        number_dispatcher::iunary<LispObject,SafeModularReciprocal>("modular-reciprocal",
                a);
}

// -fixnum
LispObject SafeModularReciprocal::op(Fixnum a)
{   return arithlib_lowlevel::SafeModularReciprocal::op(a.intval());
}
// -bignum
LispObject SafeModularReciprocal::op(uint64_t *a)
{   return arithlib_lowlevel::SafeModularReciprocal::op(a);
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

LispObject Nmodular_plus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Nmodular_plus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nmodular_plus(LispObject env, LispObject a1,
                                LispObject a2)
{   return onevalue(ModularPlus::op(a1, a2));
}

LispObject Nmodular_plus(LispObject env, LispObject a1,
                                LispObject a2,
                                LispObject a3)
{   return onevalue(ModularPlus::op(ModularPlus::op(a1, a2), a3));
}

LispObject Nmodular_plus(LispObject env, LispObject a1,
                                LispObject a2,
                                LispObject a3, LispObject a4plus)
{   LispObject w = ModularPlus::op(ModularPlus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularPlus::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nmodular_times(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

LispObject Nmodular_times(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2)
{   return onevalue(ModularTimes::op(a1, a2));
}

LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2,
                                 LispObject a3)
{   return onevalue(ModularTimes::op(ModularTimes::op(a1, a2), a3));
}

LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   LispObject w = ModularTimes::op(ModularTimes::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularTimes::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nmodular_expt(LispObject env, LispObject a, LispObject n)
{   if (!is_fixnum(a) && !is_new_bignum(a))
        return aerror1("bad argument to modular-expt", a);
    if (!is_fixnum(n) && !is_new_bignum(n) && !Minusp::op(n))
        return aerror1("bad argument to modular-expt", n);
    if (n == fixnum_of_int(0)) return fixnum_of_int(1);
    else if (n == fixnum_of_int(1)) return a;        // a simple special case.
    size_t len = int_of_fixnum(IntegerLength::op(n));
    uint64_t i;
    uint64_t* nn;
// I do a deep dive into arithlib.hpp to exploit data respresentation.
// This code should probably migrate to be within arithlib.
    if (arithlib_implementation::stored_as_fixnum(n))
    {   i = arithlib_implementation::int_of_handle(n);
        nn = &i;
    }
    else nn = arithlib_implementation::vector_of_handle(n);
    LispObject r = fixnum_of_int(1);
    for (size_t k=0; k<len-1; k++)
    {   int bit = (nn[k/64]>>(k%64)) & 1;
        if (bit != 0) r = ModularTimes::op(r, a);
        a = ModularTimes::op(a, a);
    }
    return onevalue(ModularTimes::op(r, a));
}

LispObject Nmodular_difference(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(ModularDifference::op(a1, a2));
}

LispObject Nmodular_quotient(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(ModularQuotient::op(a1, a2));
}

LispObject Nmodular_reciprocal(LispObject env, LispObject a1)
{   return onevalue(ModularReciprocal::op(a1));
}

LispObject Nsafe_modular_reciprocal(LispObject env, LispObject a1)
{   return onevalue(SafeModularReciprocal::op(a1));
}

LispObject Nmodular_minus(LispObject env, LispObject a1)
{   return onevalue(ModularMinus::op(a1));
}

LispObject Nset_modulus(LispObject env, LispObject a1)
{   return onevalue(SetModulus::op(a1));
}

LispObject Nmodular_number(LispObject env, LispObject a1)
{   return onevalue(ModularNumber::op(a1));
}

#endif // ARITHLIB

// end of arith-modular.cpp

