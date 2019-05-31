// arith-setup.cpp                              Copyright (C) 2019 Codemist    

#ifdef ARITHLIB

//
// Setup for the new set of arithmetic operations
//
// BEWARE: The code that implements all thse operators expects to be run in
// the context of a conservative GC, and so while it will be possible to test
// things in a while the use for anything serious has to wait until CSL has
// made that transition.
//

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


#include "headers.h"
#include "dispatch.h"


static LispObject Nplus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nplus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nplus(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Plus::op(a1, a2));
}

static LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Plus::op(Plus::op(a1, a2), a3));
}

static LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Plus::op(Plus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Plus::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Ntimes(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Ntimes(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Ntimes(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Times::op(a1, a2));
}

static LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onevalue(Times::op(Times::op(a1, a2), a3));
}

static LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus)
{   LispObject w = Times::op(Times::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Times::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nexpt(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Expt::op(a1, a2));
}

static LispObject Ngcdn(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Ngcdn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Gcdn::op(a1, a2));
}

static LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Gcdn::op(Gcdn::op(a1, a2), a3));
}

static LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Gcdn::op(Gcdn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Gcdn::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlcmn(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nlcmn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Lcmn::op(a1, a2));
}

static LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Lcmn::op(Lcmn::op(a1, a2), a3));
}

static LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Lcmn::op(Lcmn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Lcmn::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Ndifference(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Difference::op(a1, a2));
}


static LispObject Nquotient(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Quotient::op(a1, a2));
}


static LispObject Nremainder(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Remainder::op(a1, a2));
}


static LispObject Ndivide(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Divide::op(a1, a2));
}

static LispObject Nadd1(LispObject env, LispObject a1)
{   return onevalue(Plus::op(a1, fixnum_of_int(1)));
}

static LispObject Nsub1(LispObject env, LispObject a1)
{   return onevalue(Difference::op(a1, fixnum_of_int(1)));
}

static LispObject Nonep(LispObject env, LispObject a1)
{   return onevalue(Onep::op(a1));
}

static LispObject Nevenp(LispObject env, LispObject a1)
{   return onevalue(Evenp::op(a1));
}

static LispObject Noddp(LispObject env, LispObject a1)
{   return onevalue(Oddp::op(a1));
}

static LispObject Nzerop(LispObject env, LispObject a1)
{   return onevalue(Zerop::op(a1));
}

static LispObject Nminusp(LispObject env, LispObject a1)
{   return onevalue(Minusp::op(a1));
}

static LispObject Nminus(LispObject env, LispObject a1)
{   return onevalue(Minus::op(a1));
}

static LispObject Nreciprocal(LispObject env, LispObject a1)
{   return onevalue(Reciprocal::op(a1));
}

static LispObject Nsquare(LispObject env, LispObject a1)
{   return onevalue(Square::op(a1));
}

static LispObject Nfloat(LispObject env, LispObject a1)
{   return onevalue(Float::op(a1));
}

static LispObject Nfix(LispObject env, LispObject a1)
{   return onevalue(Fix::op(a1));
}

static LispObject Nfloor(LispObject env, LispObject a1)
{   return onevalue(Floor::op(a1));
}

static LispObject Nceiling(LispObject env, LispObject a1)
{   return onevalue(Ceiling::op(a1));
}

static LispObject Nfloat128(LispObject env, LispObject a1)
{   return onevalue(make_boxfloat128(Float128::op(a1)));
}

static LispObject Nfrexp(LispObject env, LispObject a1)
{   return onevalue(Frexp::op(a1));
}

static LispObject Nldexp(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Ldexp::op(a1, a2));
}

LispObject onebool(bool b)
{   return onevalue(b ? lisp_true : nil);
}

static LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Greaterp::op(a1, a2));
}

static LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2,
                                            LispObject a3)
{   return onebool(Greaterp::op(a1, a2) && Greaterp::op(a2, a3));
}

static LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2,
                                            LispObject a3, LispObject a4plus)
{   if (!Greaterp::op(a1, a2)) return onevalue(nil);
    if (!Greaterp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Greaterp::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Ngeq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Geq::op(a1, a2));
}

static LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3)
{   return onebool(Geq::op(a1, a2) && Geq::op(a2, a3));
}

static LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus)
{   if (!Geq::op(a1, a2)) return onevalue(nil);
    if (!Geq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Geq::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nlessp(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Lessp::op(a1, a2));
}

static LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onebool(Lessp::op(a1, a2) && Lessp::op(a2, a3));
}

static LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus)
{   if (!Lessp::op(a1, a2)) return onevalue(nil);
    if (!Lessp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Lessp::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nleq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Leq::op(a1, a2));
}

static LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3)
{   return onebool(Leq::op(a1, a2) && Leq::op(a2, a3));
}

static LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus)
{   if (!Leq::op(a1, a2)) return onevalue(nil);
    if (!Leq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Leq::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Eqn::op(a1, a2));
}

static LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onebool(Eqn::op(a1, a2) && Eqn::op(a2, a3));
}

static LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus)
{   if (!Eqn::op(a1, a2)) return onevalue(nil);
    if (!Eqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Eqn::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nneqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Neqn::op(a1, a2));
}

static LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onebool(Neqn::op(a1, a2) && Neqn::op(a2, a3) &&
                   Neqn::op(a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all aee distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

static LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   if (!Neqn::op(a1, a2)) return onevalue(nil);
    if (!Neqn::op(a2, a3)) return onevalue(nil);
    if (!Neqn::op(a1, a3)) return onevalue(nil);
    for (LispObject w=a4plus; is_cons(w); w=qcdr(w))
    {   LispObject a = qcar(w);
        if (!Neqn::op(a1, a)) return onevalue(nil); 
        if (!Neqn::op(a2, a)) return onevalue(nil); 
        if (!Neqn::op(a3, a)) return onevalue(nil);
    }
    a2 = a3;
    for (;is_cons(a4plus); a4plus=qcdr(a4plus))
    {   LispObject a = qcar(a4plus);
        for (LispObject  w = qcdr(a4plus); is_cons(w); w = qcdr(w))
        {   if (!Neqn::op(a, qcar(w))) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Nlogand(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nlogand(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogand(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logand::op(a1, a2));
}

static LispObject Nlogand(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logand::op(Logand::op(a1, a2), a3));
}

static LispObject Nlogand(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlogor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nlogor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logor::op(a1, a2));
}

static LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logor::op(Logor::op(a1, a2), a3));
}

static LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlogxor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nlogxor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logxor::op(a1, a2));
}

static LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logxor::op(Logxor::op(a1, a2), a3));
}

static LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlogeqv(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nlogeqv(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logeqv::op(a1, a2));
}

static LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logeqv::op(Logeqv::op(a1, a2), a3));
}

static LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlognot(LispObject env, LispObject a1)
{   return onevalue(Lognot::op(a1));
}

static LispObject Nleftshift(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(LeftShift::op(a1, a2));
}

static LispObject Nrightshift(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(RightShift::op(a1, a2));
}

static LispObject Nmodular_plus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nmodular_plus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(ModularPlus::op(a1, a2));
}

static LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                                                LispObject a3)
{   return onevalue(ModularPlus::op(ModularPlus::op(a1, a2), a3));
}

static LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                                                LispObject a3, LispObject a4plus)
{   LispObject w = ModularPlus::op(ModularPlus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularPlus::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nmodular_times(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nmodular_times(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(ModularTimes::op(a1, a2));
}

static LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2,
                                                 LispObject a3)
{   return onevalue(ModularTimes::op(ModularTimes::op(a1, a2), a3));
}

static LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2,
                                                 LispObject a3, LispObject a4plus)
{   LispObject w = ModularTimes::op(ModularTimes::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularTimes::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nmodular_expt(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(ModularExpt::op(a1, a2));
}

static LispObject Nmodular_difference(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(ModularDifference::op(a1, a2));
}

static LispObject Nmodular_quotient(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(ModularQuotient::op(a1, a2));
}

static LispObject Nmodular_reciprocal(LispObject env, LispObject a1)
{   return onevalue(ModularReciprocal::op(a1));
}

static LispObject Nmodular_minus(LispObject env, LispObject a1)
{   return onevalue(ModularMinus::op(a1));
}

static LispObject Nset_modulus(LispObject env, LispObject a1)
{   return onevalue(SetModulus::op(a1));
}

static LispObject Nmodular_number(LispObject env, LispObject a1)
{   return onevalue(ModularNumber::op(a1));
}

// The following functions, with name like IPLUS, ITIMES etc are relatives
// of the generic versions but they only support fixnum inputs. On a 32-bit
// machine that is values that fit in 28 bits, while on a 64-bit machine
// 60 bits are supported. Overflow is not checked for and although the
// consequence is probably that values wrap around within the range of fixnums
// that will not be guaranteed.

static LispObject Niplus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Niplus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Niplus(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Plus::op(a1, a2));
}

static LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Plus::op(Plus::op(a1, a2), a3));
}

static LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Plus::op(Plus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Plus::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nitimes(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nitimes(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nitimes(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Times::op(a1, a2));
}

static LispObject Nitimes(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onevalue(Times::op(Times::op(a1, a2), a3));
}

static LispObject Nitimes(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus)
{   LispObject w = Times::op(Times::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Times::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Niexpt(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Expt::op(a1, a2));
}

static LispObject Nigcdn(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nigcdn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Gcdn::op(a1, a2));
}

static LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Gcdn::op(Gcdn::op(a1, a2), a3));
}

static LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Gcdn::op(Gcdn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Gcdn::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilcmn(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nilcmn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Lcmn::op(a1, a2));
}

static LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Lcmn::op(Lcmn::op(a1, a2), a3));
}

static LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Lcmn::op(Lcmn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Lcmn::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nidifference(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Difference::op(a1, a2));
}


static LispObject Niquotient(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Quotient::op(a1, a2));
}


static LispObject Niremainder(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Remainder::op(a1, a2));
}


static LispObject Nidivide(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Divide::op(a1, a2));
}

static LispObject Niadd1(LispObject env, LispObject a1)
{   return onevalue(Plus::op(a1, fixnum_of_int(1)));
}

static LispObject Nisub1(LispObject env, LispObject a1)
{   return onevalue(Difference::op(a1, fixnum_of_int(1)));
}

static LispObject Nionep(LispObject env, LispObject a1)
{   return onevalue(Onep::op(a1));
}

static LispObject Nievenp(LispObject env, LispObject a1)
{   return onevalue(Evenp::op(a1));
}

static LispObject Nioddp(LispObject env, LispObject a1)
{   return onevalue(Oddp::op(a1));
}

static LispObject Nizerop(LispObject env, LispObject a1)
{   return onevalue(Zerop::op(a1));
}

static LispObject Niminusp(LispObject env, LispObject a1)
{   return onevalue(Minusp::op(a1));
}

static LispObject Niminus(LispObject env, LispObject a1)
{   return onevalue(Minus::op(a1));
}

static LispObject Nireciprocal(LispObject env, LispObject a1)
{   return onevalue(Reciprocal::op(a1));
}

static LispObject Nisquare(LispObject env, LispObject a1)
{   return onevalue(Square::op(a1));
}

static LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Greaterp::op(a1, a2));
}

static LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2,
                                            LispObject a3)
{   return onebool(Greaterp::op(a1, a2) && Greaterp::op(a2, a3));
}

static LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2,
                                            LispObject a3, LispObject a4plus)
{   if (!Greaterp::op(a1, a2)) return onevalue(nil);
    if (!Greaterp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Greaterp::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nigeq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Geq::op(a1, a2));
}

static LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3)
{   return onebool(Geq::op(a1, a2) && Geq::op(a2, a3));
}

static LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus)
{   if (!Geq::op(a1, a2)) return onevalue(nil);
    if (!Geq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Geq::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nilessp(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Lessp::op(a1, a2));
}

static LispObject Nilessp(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onebool(Lessp::op(a1, a2) && Lessp::op(a2, a3));
}

static LispObject Nilessp(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus)
{   if (!Lessp::op(a1, a2)) return onevalue(nil);
    if (!Lessp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Lessp::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nileq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Leq::op(a1, a2));
}

static LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3)
{   return onebool(Leq::op(a1, a2) && Leq::op(a2, a3));
}

static LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus)
{   if (!Leq::op(a1, a2)) return onevalue(nil);
    if (!Leq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Leq::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Eqn::op(a1, a2));
}

static LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onebool(Eqn::op(a1, a2) && Eqn::op(a2, a3));
}

static LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus)
{   if (!Eqn::op(a1, a2)) return onevalue(nil);
    if (!Eqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Eqn::op(a2, a3 = qcar(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = qcdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nineqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Neqn::op(a1, a2));
}

static LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   return onebool(Neqn::op(a1, a2) && Neqn::op(a2, a3) &&
                   Neqn::op(a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all aee distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

static LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   if (!Neqn::op(a1, a2)) return onevalue(nil);
    if (!Neqn::op(a2, a3)) return onevalue(nil);
    if (!Neqn::op(a1, a3)) return onevalue(nil);
    for (LispObject w=a4plus; is_cons(w); w=qcdr(w))
    {   LispObject a = qcar(w);
        if (!Neqn::op(a1, a)) return onevalue(nil); 
        if (!Neqn::op(a2, a)) return onevalue(nil); 
        if (!Neqn::op(a3, a)) return onevalue(nil);
    }
    a2 = a3;
    for (;is_cons(a4plus); a4plus=qcdr(a4plus))
    {   LispObject a = qcar(a4plus);
        for (LispObject  w = qcdr(a4plus); is_cons(w); w = qcdr(w))
        {   if (!Neqn::op(a, qcar(w))) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Nilogand(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nilogand(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogand(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logand::op(a1, a2));
}

static LispObject Nilogand(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logand::op(Logand::op(a1, a2), a3));
}

static LispObject Nilogand(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilogor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nilogor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logor::op(a1, a2));
}

static LispObject Nilogor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logor::op(Logor::op(a1, a2), a3));
}

static LispObject Nilogor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilogxor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nilogxor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logxor::op(a1, a2));
}

static LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logxor::op(Logxor::op(a1, a2), a3));
}

static LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilogeqv(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nilogeqv(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logeqv::op(a1, a2));
}

static LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3)
{   return onevalue(Logeqv::op(Logeqv::op(a1, a2), a3));
}

static LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus)
{   LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, qcar(a4plus));
        a4plus = qcdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilognot(LispObject env, LispObject a1)
{   return onevalue(Lognot::op(a1));
}

static LispObject Nileftshift(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(LeftShift::op(a1, a2));
}

static LispObject Nirightshift(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(RightShift::op(a1, a2));
}



setup_type const arith_setup[] =
{
    {"newplus",              Nplus,              Nplus,              Nplus,              Nplus,              Nplus},
    {"newadd1",              G0W1,               Nadd1,              G2W1,               G3W1,               G4W1},
    {"newdifference",        G0W2,               G1W2,               Ndifference,        G3W2,               G4W2},
    {"newtimes",             Ntimes,             Ntimes,             Ntimes,             Ntimes,             Ntimes},
    {"newquotient",          G0W2,               G1W2,               Nquotient,          G3W2,               G4W2},
    {"newremainder",         G0W2,               G1W2,               Nremainder,         G3W2,               G4W2},
    {"newdivide",            G0W2,               G1W2,               Ndivide,            G3W2,               G4W2},
    {"newgcdn",              Ngcdn,              Ngcdn,              Ngcdn,              Ngcdn,              Ngcdn},
    {"newlcmn",              Nlcmn,              Nlcmn,              Nlcmn,              Nlcmn,              Nlcmn},
    {"newminus",             G0W1,               Nminus,             G2W1,               G3W1,               G4W1},
    {"newminusp",            G0W1,               Nminusp,            G2W1,               G3W1,               G4W1},
    {"newreciprocal",        G0W1,               Nreciprocal,        G2W1,               G3W1,               G4W1},
    {"newsquare",            G0W1,               Nsquare,            G2W1,               G3W1,               G4W1},
    {"newsub1",              G0W1,               Nsub1,              G2W1,               G3W1,               G4W1},
    {"newzerop",             G0W1,               Nzerop,             G2W1,               G3W1,               G4W1},
    {"newonep",              G0W1,               Nonep,              G2W1,               G3W1,               G4W1},
    {"newoddp",              G0W1,               Noddp,              G2W1,               G3W1,               G4W1},
    {"newevenp",             G0W1,               Nevenp,             G2W1,               G3W1,               G4W1},
    {"newfloat",             G0W1,               Nfloat,             G2W1,               G3W1,               G4W1},
    {"newfloat128",          G0W1,               Nfloat128,          G2W1,               G3W1,               G4W1},
    {"newfix",               G0W1,               Nfix,               G2W1,               G3W1,               G4W1},
    {"newfloor",             G0W1,               Nfloor,             G2W1,               G3W1,               G4W1},
    {"newceiling",           G0W1,               Nceiling,           G2W1,               G3W1,               G4W1},
    {"newfrexp",             G0W1,               Nfrexp,             G2W1,               G3W1,               G4W1},
    {"newldexp",             G0W1,               G1W2,               Nldexp,             G3W2,               G4W1},
    {"newexpt",              G0W2,               G1W2,               Nexpt,              G3W2,               G4W2},
// Neqn is a name that gives trouble. In one part of the code here it is
// "N" followed by "eqn", and denotes the function that will perform equality
// tests on numbers. In another it is "Neqn", otherwise "neqn" but capitalized
// and it is the name of a class that implements "neqn". So I tag "_a" on
// the end of one of these to resolve the clash.
    {"neweqn",               G0W2,               G1W2,               Neqn_a,             Neqn_a,             Neqn_a},
    {"newneqn",              G0W2,               G1W2,               Nneqn,              Nneqn,              Nneqn},
    {"newgreaterp",          G0W2,               G1W2,               Ngreaterp,          Ngreaterp,          Ngreaterp},
    {"newgeq",               G0W2,               G1W2,               Ngeq,               Ngeq,               Ngeq},
    {"newlessp",             G0W2,               G1W2,               Nlessp,             Nlessp,             Nlessp},
    {"newleq",               G0W2,               G1W2,               Nleq,               Nleq,               Nleq},
    {"newlogand",            Nlogand,            Nlogand,            Nlogand,            Nlogand,            Nlogand},
    {"newlogor",             Nlogor,             Nlogor,             Nlogor,             Nlogor,             Nlogor},
    {"newlogxor",            Nlogxor,            Nlogxor,            Nlogxor,            Nlogxor,            Nlogxor},
    {"newlogeqv",            Nlogeqv,            Nlogeqv,            Nlogeqv,            Nlogeqv,            Nlogeqv},
    {"newlognot",            G0W1,               Nlognot,            G2W1,               G3W1,               G4W1},
    {"newlshift",            G0W2,               G1W2,               Nleftshift,         G3W1,               G4W1},
    {"newrshift",            G0W2,               G1W2,               Nrightshift,        G3W1,               G4W1},
    {"newmodular-plus",      Nmodular_plus,      Nmodular_plus,      Nmodular_plus,      Nmodular_plus,      Nmodular_plus},
    {"newmodular-difference",G0W2,               G1W2,               Nmodular_difference,G3W2,               G4W2},
    {"newmodular-times",     Nmodular_times,     Nmodular_times,     Nmodular_times,     Nmodular_times,     Nmodular_times},
    {"newmodular-quotient",  G0W2,               G1W2,               Nmodular_quotient,  G3W2,               G4W2},
    {"newmodular-expt",      G0W2,               G1W2,               Nmodular_expt,      G3W2,               G4W2},
    {"newset-modulus",       G0W1,               Nset_modulus,       G2W1,               G3W1,               G4W1},
    {"newset-small-modulus", G0W1,               Nset_modulus,       G2W1,               G3W1,               G4W1},
    {"newmodular-number",    G0W1,               Nmodular_number,    G2W1,               G3W1,               G4W1},
    {"newmodular-minus",     G0W1,               Nmodular_minus,     G2W1,               G3W1,               G4W1},
    {"newmodular-reciprocal",G0W1,               Nmodular_reciprocal,G2W1,               G3W1,               G4W1},
    {"newiplus",             Niplus,             Niplus,             Niplus,             Niplus,             Niplus},
    {"newiadd1",             G0W1,               Niadd1,             G2W1,               G3W1,               G4W1},
    {"newidifference",       G0W2,               G1W2,               Nidifference,       G3W2,               G4W2},
    {"newitimes",            Nitimes,            Nitimes,            Nitimes,            Nitimes,            Nitimes},
    {"newiquotient",         G0W2,               G1W2,               Niquotient,         G3W2,               G4W2},
    {"newiremainder",        G0W2,               G1W2,               Niremainder,        G3W2,               G4W2},
    {"newidivide",           G0W2,               G1W2,               Nidivide,           G3W2,               G4W2},
    {"newigcdn",             Nigcdn,             Nigcdn,             Nigcdn,             Nigcdn,             Nigcdn},
    {"newilcmn",             Nilcmn,             Nilcmn,             Nilcmn,             Nilcmn,             Nilcmn},
    {"newiminus",            G0W1,               Niminus,            G2W1,               G3W1,               G4W1},
    {"newiminusp",           G0W1,               Niminusp,           G2W1,               G3W1,               G4W1},
    {"newireciprocal",       G0W1,               Nireciprocal,       G2W1,               G3W1,               G4W1},
    {"newisquare",           G0W1,               Nisquare,           G2W1,               G3W1,               G4W1},
    {"newisub1",             G0W1,               Nisub1,             G2W1,               G3W1,               G4W1},
    {"newizerop",            G0W1,               Nizerop,            G2W1,               G3W1,               G4W1},
    {"newionep",             G0W1,               Nionep,             G2W1,               G3W1,               G4W1},
    {"newioddp",             G0W1,               Nioddp,             G2W1,               G3W1,               G4W1},
    {"newievenp",            G0W1,               Nievenp,            G2W1,               G3W1,               G4W1},
    {"newiexpt",             G0W2,               G1W2,               Niexpt,             G3W2,               G4W2},
    {"newieqn",              G0W2,               G1W2,               Nieqn_a,            Nieqn_a,            Nieqn_a},
    {"newineqn",             G0W2,               G1W2,               Nineqn,             Nineqn,             Nineqn},
    {"newigreaterp",         G0W2,               G1W2,               Nigreaterp,         Nigreaterp,         Nigreaterp},
    {"newigeq",              G0W2,               G1W2,               Nigeq,              Nigeq,              Nigeq},
    {"newilessp",            G0W2,               G1W2,               Nilessp,            Nilessp,            Nilessp},
    {"newileq",              G0W2,               G1W2,               Nileq,              Nileq,              Nileq},
    {"newilogand",           Nilogand,           Nilogand,           Nilogand,           Nilogand,           Nilogand},
    {"newilogor",            Nilogor,            Nilogor,            Nilogor,            Nilogor,            Nilogor},
    {"newilogxor",           Nilogxor,           Nilogxor,           Nilogxor,           Nilogxor,           Nilogxor},
    {"newilogeqv",           Nilogeqv,           Nilogeqv,           Nilogeqv,           Nilogeqv,           Nilogeqv},
    {"newilognot",           G0W1,               Nilognot,           G2W1,               G3W1,               G4W1},
    {"newilshift",           G0W2,               G1W2,               Nileftshift,        G3W1,               G4W1},
    {"newirshift",           G0W2,               G1W2,               Nirightshift,       G3W1,               G4W1},
    {NULL,                   0, 0, 0, 0, 0}
};

#endif // ARITHLIB

// end of arith-setup.cpp
