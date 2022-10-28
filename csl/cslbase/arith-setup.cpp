// arith-setup.cpp                         Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

//
// Setup for the new set of arithmetic operations
//

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

LispObject onebool(bool b)
{   return onevalue(b ? lisp_true : nil);
}

LispObject Nplus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Nplus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nplus(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Plus::op(a1, a2));
}

LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onevalue(Plus::op(Plus::op(a1, a2), a3));
}

LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   LispObject w = Plus::op(Plus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Plus::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Ntimes(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

LispObject Ntimes(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Ntimes(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Times::op(a1, a2));
}

LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Times::op(Times::op(a1, a2), a3));
}

LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Times::op(Times::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Times::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

//LispObject Nexpt(LispObject env, LispObject a1, LispObject a2)
//{   return onevalue(Expt::op(a1, a2));
//}

LispObject Ngcdn(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Ngcdn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Gcdn::op(a1, a2));
}

LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onevalue(Gcdn::op(Gcdn::op(a1, a2), a3));
}

LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   LispObject w = Gcdn::op(Gcdn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Gcdn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nlcmn(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

LispObject Nlcmn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Lcmn::op(a1, a2));
}

LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onevalue(Lcmn::op(Lcmn::op(a1, a2), a3));
}

LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   LispObject w = Lcmn::op(Lcmn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Lcmn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Ndifference(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(Difference::op(a1, a2));
}

LispObject Nquotient(LispObject env, LispObject a1,
                            LispObject a2)
{   return onevalue(Quotient::op(a1, a2));
}

LispObject NCLQuotient(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(CLQuotient::op(a1, a2));
}

LispObject Nremainder(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(Remainder::op(a1, a2));
}

LispObject Nmod(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(Mod::op(a1, a2));
}

LispObject Ndivide(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Divide::op(a1, a2));
}

LispObject Nadd1(LispObject env, LispObject a1)
{   return onevalue(Plus::op(a1, fixnum_of_int(1)));
}

LispObject Nsub1(LispObject env, LispObject a1)
{   return onevalue(Difference::op(a1, fixnum_of_int(1)));
}

// Some of the predicates here are "generous" when given an argument
// which is not a number, so for instance (onep 'rhubarb) returns nil.
// Ditto zerop, plusp and minusp.

LispObject Nonep(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && Onep::op(a1));
}

LispObject Nevenp(LispObject env, LispObject a1)
{   return onebool(Evenp::op(a1));
}

LispObject Noddp(LispObject env, LispObject a1)
{   return onebool(Oddp::op(a1));
}

LispObject Nzerop(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && Zerop::op(a1));
}

LispObject Nminusp(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && Minusp::op(a1));
}

LispObject Nplusp(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && Plusp::op(a1));
}

LispObject Nminus(LispObject env, LispObject a1)
{   return onevalue(Minus::op(a1));
}

LispObject Nabs(LispObject env, LispObject a1)
{   return onevalue(Abs::op(a1));
}

LispObject Nreciprocal(LispObject env, LispObject a1)
{   return onevalue(Reciprocal::op(a1));
}

//LispObject Nsqrt(LispObject env, LispObject a1)
//{   return onevalue(Sqrt::op(a1));
//}

LispObject Nisqrt(LispObject env, LispObject a1)
{   return onevalue(Isqrt::op(a1));
}

LispObject Nsquare(LispObject env, LispObject a1)
{   return onevalue(Square::op(a1));
}

LispObject Nfloat(LispObject env, LispObject a1)
{   return onevalue(Float::op(a1));
}

LispObject Nfloat(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Float::op(a1, a2));
}

LispObject Nfix(LispObject env, LispObject a1)
{   return onevalue(Fix::op(a1));
}

LispObject Ntruncate(LispObject env, LispObject a1)
{   return onevalue(Truncate::op(a1));
}

LispObject Nfloor(LispObject env, LispObject a1)
{   return onevalue(Floor::op(a1));
}

LispObject Nceiling(LispObject env, LispObject a1)
{   return onevalue(Ceiling::op(a1));
}

LispObject Nftruncate(LispObject env, LispObject a1)
{   return onevalue(Ftruncate::op(a1));
}

LispObject Nffloor(LispObject env, LispObject a1)
{   return onevalue(Ffloor::op(a1));
}

LispObject Nfceiling(LispObject env, LispObject a1)
{   return onevalue(Fceiling::op(a1));
}

LispObject Ntruncate(LispObject env, LispObject a1,
                            LispObject a2)
{   return onevalue(Truncate::op(a1, a2));
}

LispObject Nfloor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Floor::op(a1, a2));
}

LispObject Nceiling(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Ceiling::op(a1, a2));
}

LispObject Nftruncate(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(Ftruncate::op(a1, a2));
}

LispObject Nffloor(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Ffloor::op(a1, a2));
}

LispObject Nfceiling(LispObject env, LispObject a1,
                            LispObject a2)
{   return onevalue(Fceiling::op(a1,  a2));
}

LispObject Nfloat128(LispObject env, LispObject a1)
{   return onevalue(Float128::op(a1));
}

LispObject Nfrexp(LispObject env, LispObject a1)
{   return onevalue(Frexp::op(a1));
}

LispObject Nldexp(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Ldexp::op(a1, a2));
}

LispObject Ngreaterp(LispObject env, LispObject a1,
                            LispObject a2)
{   return onebool(Greaterp::op(a1, a2));
}

LispObject Ngreaterp(LispObject env, LispObject a1,
                            LispObject a2,
                            LispObject a3)
{   return onebool(Greaterp::op(a1, a2) && Greaterp::op(a2, a3));
}

LispObject Ngreaterp(LispObject env, LispObject a1,
                            LispObject a2,
                            LispObject a3, LispObject a4plus)
{   if (!Greaterp::op(a1, a2)) return onevalue(nil);
    if (!Greaterp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Greaterp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Ngeq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Geq::op(a1, a2));
}

LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3)
{   return onebool(Geq::op(a1, a2) && Geq::op(a2, a3));
}

LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3, LispObject a4plus)
{   if (!Geq::op(a1, a2)) return onevalue(nil);
    if (!Geq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Geq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nlessp(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Lessp::op(a1, a2));
}

LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(Lessp::op(a1, a2) && Lessp::op(a2, a3));
}

LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!Lessp::op(a1, a2)) return onevalue(nil);
    if (!Lessp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Lessp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nleq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Leq::op(a1, a2));
}

LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3)
{   return onebool(Leq::op(a1, a2) && Leq::op(a2, a3));
}

LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3, LispObject a4plus)
{   if (!Leq::op(a1, a2)) return onevalue(nil);
    if (!Leq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Leq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Eqn::op(a1, a2));
}

LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(Eqn::op(a1, a2) && Eqn::op(a2, a3));
}

LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!Eqn::op(a1, a2)) return onevalue(nil);
    if (!Eqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Eqn::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(CLEqn::op(a1, a2));
}

LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(CLEqn::op(a1, a2) && CLEqn::op(a2, a3));
}

LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!CLEqn::op(a1, a2)) return onevalue(nil);
    if (!CLEqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (CLEqn::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nneqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Neqn::op(a1, a2));
}

LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onebool(Neqn::op(a1, a2) && Neqn::op(a2, a3) &&
                   Neqn::op(a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all aee distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   if (!Neqn::op(a1, a2)) return onevalue(nil);
    if (!Neqn::op(a2, a3)) return onevalue(nil);
    if (!Neqn::op(a1, a3)) return onevalue(nil);
    for (LispObject w=a4plus; is_cons(w); w=cdr(w))
    {   LispObject a = car(w);
        if (!Neqn::op(a1, a)) return onevalue(nil);
        if (!Neqn::op(a2, a)) return onevalue(nil);
        if (!Neqn::op(a3, a)) return onevalue(nil);
    }
    a2 = a3;
    for (; is_cons(a4plus); a4plus=cdr(a4plus))
    {   LispObject a = car(a4plus);
        for (LispObject  w = cdr(a4plus); is_cons(w); w = cdr(w))
        {   if (!Neqn::op(a, car(w))) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

LispObject Nmax(LispObject env)
{   return aerror("max called witout arguments");
}

LispObject Nmax(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nmax(LispObject env, LispObject a1, LispObject a2)
{   if (Lessp::op(a1, a2)) return onevalue(a2);
    return onevalue(a1);
}

LispObject Nmax(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3)
{   if (Lessp::op(a1, a2)) a1 = a2;
    if (Lessp::op(a1, a3)) a1 = a3;
    return onevalue(a1);
}

LispObject Nmax(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4plus)
{   if (Lessp::op(a1, a2)) a1 = a2;
    if (Lessp::op(a1, a3)) a1 = a3;
    while (is_cons(a4plus))
    {   LispObject w = car(a4plus);
        if (Lessp::op(a1, w)) a1 = w;
        a4plus = cdr(a4plus);
    }
    return onevalue(a1);
}

LispObject Nmin(LispObject env)
{   return aerror("min called witout arguments");
}

LispObject Nmin(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nmin(LispObject env, LispObject a1, LispObject a2)
{   if (Greaterp::op(a1, a2)) return onevalue(a2);
    return onevalue(a1);
}

LispObject Nmin(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3)
{   if (Greaterp::op(a1, a2)) a1 = a2;
    if (Greaterp::op(a1, a3)) a1 = a3;
    return onevalue(a1);
}

LispObject Nmin(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4plus)
{   if (Greaterp::op(a1, a2)) a1 = a2;
    if (Greaterp::op(a1, a3)) a1 = a3;
    while (is_cons(a4plus))
    {   LispObject w = car(a4plus);
        if (Greaterp::op(a1, w)) a1 = w;
        a4plus = cdr(a4plus);
    }
    return onevalue(a1);
}

LispObject Nlogand(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

LispObject Nlogand(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nlogand(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logand::op(a1, a2));
}

LispObject Nlogand(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logand::op(Logand::op(a1, a2), a3));
}

LispObject Nlogand(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nlogor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Nlogor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logor::op(a1, a2));
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Logor::op(Logor::op(a1, a2), a3));
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nlogxor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Nlogxor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logxor::op(a1, a2));
}

LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logxor::op(Logxor::op(a1, a2), a3));
}

LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nlogeqv(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

LispObject Nlogeqv(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logeqv::op(a1, a2));
}

LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logeqv::op(Logeqv::op(a1, a2), a3));
}

LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nlognot(LispObject env, LispObject a1)
{   return onevalue(Lognot::op(a1));
}

LispObject Nlsd(LispObject env, LispObject a1)
{   return onevalue(LowBit::op(a1));
}

LispObject Nmsd(LispObject env, LispObject a1)
{   return onevalue(IntegerLength::op(a1));
}

LispObject Nlogcount(LispObject env, LispObject a1)
{   return onevalue(Logcount::op(a1));
}

LispObject Nleftshift(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(LeftShift::op(a1, a2));
}

// The following divides by a power of 2 when shifting right so is not
// a natural arithmetic shift on negative numbers.

LispObject Nash1(LispObject env, LispObject a1, LispObject a2)
{   bool neg = Minusp::op(a1);
    if (neg) a1 = Minus::op(a1);
    a1 = LeftShift::op(a1, a2);
    if (neg) a1 = Minus::op(a1);
    return onevalue(a1);
}

LispObject Nrightshift(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(RightShift::op(a1, a2));
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

LispObject Nmodular_expt(LispObject env, LispObject a1,
                                LispObject a2)
{   return onevalue(ModularExpt::op(a1, a2));
}

LispObject Nmodular_difference(LispObject env, LispObject a1,
                                      LispObject a2)
{   return onevalue(ModularDifference::op(a1, a2));
}

LispObject Nmodular_quotient(LispObject env, LispObject a1,
                                    LispObject a2)
{   return onevalue(ModularQuotient::op(a1, a2));
}

LispObject Nmodular_reciprocal(LispObject env, LispObject a1)
{   return onevalue(ModularReciprocal::op(a1));
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

// The following functions, with name like IPLUS, ITIMES etc are relatives
// of the generic versions but they only support fixnum inputs. On a 32-bit
// machine that is values that fit in 28 bits, while on a 64-bit machine
// 60 bits are supported. Overflow is not checked for and although the
// consequence is probably that values wrap around within the range of fixnums
// that will not be guaranteed.

LispObject Niplus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Niplus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Niplus(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Plus::op(a1, a2));
}

LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Plus::op(Plus::op(a1, a2), a3));
}

LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Plus::op(Plus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Plus::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nitimes(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

LispObject Nitimes(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nitimes(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Times::op(a1, a2));
}

LispObject Nitimes(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Times::op(Times::op(a1, a2), a3));
}

LispObject Nitimes(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Times::op(Times::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Times::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Niexpt(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Expt::op(a1, a2));
}

LispObject Nigcdn(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Nigcdn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Gcdn::op(a1, a2));
}

LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Gcdn::op(Gcdn::op(a1, a2), a3));
}

LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Gcdn::op(Gcdn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Gcdn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nilcmn(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

LispObject Nilcmn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Lcmn::op(a1, a2));
}

LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Lcmn::op(Lcmn::op(a1, a2), a3));
}

LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Lcmn::op(Lcmn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Lcmn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nidifference(LispObject env, LispObject a1,
                               LispObject a2)
{   return onevalue(Difference::op(a1, a2));
}

LispObject Niquotient(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(Quotient::op(a1, a2));
}

LispObject Nimod(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(Mod::op(a1, a2));
}

LispObject Nidivide(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Divide::op(a1, a2));
}

LispObject Niadd1(LispObject env, LispObject a1)
{   return onevalue(Plus::op(a1, fixnum_of_int(1)));
}

LispObject Nisub1(LispObject env, LispObject a1)
{   return onevalue(Difference::op(a1, fixnum_of_int(1)));
}

LispObject Nionep(LispObject env, LispObject a1)
{   return onebool(Onep::op(a1));
}

LispObject Nievenp(LispObject env, LispObject a1)
{   return onebool(Evenp::op(a1));
}

LispObject Nioddp(LispObject env, LispObject a1)
{   return onebool(Oddp::op(a1));
}

LispObject Nizerop(LispObject env, LispObject a1)
{   return onebool(Zerop::op(a1));
}

LispObject Niminusp(LispObject env, LispObject a1)
{   return onebool(Minusp::op(a1));
}

LispObject Niminus(LispObject env, LispObject a1)
{   return onevalue(Minus::op(a1));
}

LispObject Niabs(LispObject env, LispObject a1)
{   return onevalue(Abs::op(a1));
}

LispObject Nireciprocal(LispObject env, LispObject a1)
{   return onevalue(Reciprocal::op(a1));
}

LispObject Nisquare(LispObject env, LispObject a1)
{   return onevalue(Square::op(a1));
}

LispObject Nigreaterp(LispObject env, LispObject a1,
                             LispObject a2)
{   return onebool(Greaterp::op(a1, a2));
}

LispObject Nigreaterp(LispObject env, LispObject a1,
                             LispObject a2,
                             LispObject a3)
{   return onebool(Greaterp::op(a1, a2) && Greaterp::op(a2, a3));
}

LispObject Nigreaterp(LispObject env, LispObject a1,
                             LispObject a2,
                             LispObject a3, LispObject a4plus)
{   if (!Greaterp::op(a1, a2)) return onevalue(nil);
    if (!Greaterp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Greaterp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nigeq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Geq::op(a1, a2));
}

LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onebool(Geq::op(a1, a2) && Geq::op(a2, a3));
}

LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   if (!Geq::op(a1, a2)) return onevalue(nil);
    if (!Geq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Geq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nilessp(LispObject env, LispObject a1,
                          LispObject a2)
{   return onebool(Lessp::op(a1, a2));
}

LispObject Nilessp(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onebool(Lessp::op(a1, a2) && Lessp::op(a2, a3));
}

LispObject Nilessp(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   if (!Lessp::op(a1, a2)) return onevalue(nil);
    if (!Lessp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Lessp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nileq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Leq::op(a1, a2));
}

LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onebool(Leq::op(a1, a2) && Leq::op(a2, a3));
}

LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   if (!Leq::op(a1, a2)) return onevalue(nil);
    if (!Leq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Leq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nieqn_a(LispObject env, LispObject a1,
                          LispObject a2)
{   return onebool(Eqn::op(a1, a2));
}

LispObject Nieqn_a(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onebool(Eqn::op(a1, a2) && Eqn::op(a2, a3));
}

LispObject Nieqn_a(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   if (!Eqn::op(a1, a2)) return onevalue(nil);
    if (!Eqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Eqn::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

LispObject Nineqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Neqn::op(a1, a2));
}

LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(Neqn::op(a1, a2) && Neqn::op(a2, a3) &&
                   Neqn::op(a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all aee distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!Neqn::op(a1, a2)) return onevalue(nil);
    if (!Neqn::op(a2, a3)) return onevalue(nil);
    if (!Neqn::op(a1, a3)) return onevalue(nil);
    for (LispObject w=a4plus; is_cons(w); w=cdr(w))
    {   LispObject a = car(w);
        if (!Neqn::op(a1, a)) return onevalue(nil);
        if (!Neqn::op(a2, a)) return onevalue(nil);
        if (!Neqn::op(a3, a)) return onevalue(nil);
    }
    a2 = a3;
    for (; is_cons(a4plus); a4plus=cdr(a4plus))
    {   LispObject a = car(a4plus);
        for (LispObject  w = cdr(a4plus); is_cons(w); w = cdr(w))
        {   if (!Neqn::op(a, car(w))) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

LispObject Nilogand(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

LispObject Nilogand(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Logand::op(a1, a2));
}

LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   return onevalue(Logand::op(Logand::op(a1, a2), a3));
}

LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nilogor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Nilogor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logor::op(a1, a2));
}

LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logor::op(Logor::op(a1, a2), a3));
}

LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nilogxor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Nilogxor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Logxor::op(a1, a2));
}

LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   return onevalue(Logxor::op(Logxor::op(a1, a2), a3));
}

LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nilogeqv(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

LispObject Nilogeqv(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Logeqv::op(a1, a2));
}

LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   return onevalue(Logeqv::op(Logeqv::op(a1, a2), a3));
}

LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

LispObject Nilognot(LispObject env, LispObject a1)
{   return onevalue(Lognot::op(a1));
}

LispObject Nileftshift(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(LeftShift::op(a1, a2));
}

LispObject Nirightshift(LispObject env, LispObject a1,
                               LispObject a2)
{   return onevalue(RightShift::op(a1, a2));
}

LispObject Nmodf(LispObject env, LispObject a1)
{   float fi, ff;
    double di, df;
    float128_t li, lf;
    switch (a1 & XTAG_BITS)
{       default:
            return cons(a1, make_boxfloat(0.0));
        case XTAG_SFLOAT:   // float28 or perhaps float32
            ff = std::modf(value_of_immediate_float(a1), &fi);
            if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0))
                return cons(pack_single_float(fi), pack_single_float(ff));
            else return cons(pack_short_float(fi), pack_short_float(ff));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a1))
        {       default:
                    return aerror("badly formatted float data");
                case SINGLE_FLOAT_HEADER:
                    ff = std::modf(single_float_val(a1), &fi);
                    return cons(pack_single_float(fi), pack_single_float(ff));
                case DOUBLE_FLOAT_HEADER:
                    df = std::modf(double_float_val(a1), &di);
                    return cons(make_boxfloat(di), make_boxfloat(df));
                case LONG_FLOAT_HEADER:
                    lf = arithlib_lowlevel::modf(long_float_val(a1), li);
                    return cons(make_boxfloat128(li), make_boxfloat128(lf));
            }
    }
}

LispObject Nrealpart(LispObject env, LispObject a)
{   if (!is_number(a)) return aerror1("realpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(real_part(a));
    else return onevalue(a);
}

LispObject Nimagpart(LispObject env, LispObject a)
{   if (!is_number(a)) return aerror1("imagpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(imag_part(a));
// /* the 0.0 returned here ought to be the same type as a has
    else return onevalue(fixnum_of_int(0));
}

LispObject Nnumerator(LispObject env, LispObject a)
{   if (!is_number(a)) return aerror1("numerator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(numerator(a));
    else return onevalue(a);
}

LispObject Ndenominator(LispObject env, LispObject a)
{   if (!is_number(a)) return aerror1("denominator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(denominator(a));
    else return onevalue(fixnum_of_int(1));
}

LispObject Ncomplex_1(LispObject env, LispObject a)
{
// /* Need to make zero of same type as a
    a = make_complex(a, fixnum_of_int(0));
    return onevalue(a);
}

LispObject Ncomplex_2(LispObject env, LispObject a, LispObject b)
{
// /* Need to coerce a and b to the same type here...
    a = make_complex(a, b);
    return onevalue(a);
}

LispObject Nconjugate(LispObject env, LispObject a)
{   if (!is_number(a)) return aerror1("conjugate", a);
    if (is_numbers(a) && is_complex(a))
    {   LispObject r = real_part(a),
                   i = imag_part(a);
        {   THREADID;
            Save save(THREADARG r);
            i = Minus::op(i);
            errexit();
            save.restore(r);
        }
        a = make_complex(r, i);
        return onevalue(a);
    }
    else return onevalue(a);
}

#ifdef HAVE_SOFTFLOAT
LispObject Ndecode_long_float(LispObject a)
{   float128_t d = long_float_val(a);
    if (f128M_infinite(&d) || f128M_nan(&d))
    {   if (trap_floating_overflow) return aerror("decode-float");
        else return onevalue(nil); // infinity or NaN
    }
    bool neg = false;
    int x = 0;
    if (f128M_negative(&d)) f128M_negate(&d), neg = true;
    if (f128M_eq(&d, &f128_0)) x = 0;
    else
    {   if (f128M_subnorm(&d))
        {   f128M_mul(&d, &f128_N1, &d);
            x -= 4096;
        }
        x += f128M_exponent(&d) - 0x3fff;
        f128M_set_exponent(&d, 0x3fff);
    }
    LispObject sign = make_boxfloat128(f128_1);
    if (neg) f128M_negate(reinterpret_cast<float128_t *>(long_float_addr(
                                  sign)));
    {   THREADID;
        Save save(THREADARG sign);
        a = make_boxfloat128(d);
        errexit();
        save.restore(sign);
    }
#ifdef COMMON
// Until and unless Standard Lisp supports multiple values this has to
// return a list in standard lisp mode.
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
#else
    return list3(sign, fixnum_of_int(x), a);
#endif
}
#endif // HAVE_SOFTFLOAT

LispObject Ndecode_float(LispObject env, LispObject a)
{   double d, neg = 1.0;
    int x;
    LispObject sign;
    if (!is_float(a)) return aerror("decode-float");
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return Ndecode_long_float(a);
#endif // HAVE_SOFTFLOAT
    d = float_of_number(a);
    if (floating_edge_case(d))
    {   if (trap_floating_overflow) return aerror("decode-float");
        else return onevalue(nil); // infinity or NaN
    }
// Ha ha ha - I detect -0.0 here.
    if (d < 0.0 || (d == 0.0 && 1.0/d < 0)) d = -d, neg = -1.0;
    if (d == 0.0) x = 0;
    else d = std::frexp(d, &x);
    if (is_sfloat(a)) sign = pack_immediate_float(neg, a);
    else sign = make_boxfloat(neg, floatWant(flthdr(a)));
    {   THREADID;
        Save save(THREADARG sign);
        if (is_sfloat(a)) a = pack_immediate_float(d, a);
        else a = make_boxfloat(d, floatWant(flthdr(a)));
        errexit();
        save.restore(sign);
    }
#ifdef COMMON
// Until and unless Standard Lisp supports multiple values this has to
// return a list in standard lisp mode.
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
#else
    return list3(sign, fixnum_of_int(x), a);
#endif
}

#ifdef HAVE_SOFTFLOAT
LispObject Ninteger_decode_long_float(LispObject a)
{   float128_t d = long_float_val(a);
    if (f128M_infinite(&d) || f128M_nan(&d))
    {   if (trap_floating_overflow) return aerror("integer-decode-float");
        else return onevalue(nil); // infinity or NaN
    }
    if (f128M_eq(&d, &f128_0))
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(f128M_negative(&d) ? -1 : 1);
        nvalues(fixnum_of_int(0), 3);
    }
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(f128M_negative(&d) ? -1 : 1));
#endif
    bool neg = false;
    if (f128M_negative(&d))
    {   f128M_negate(&d);
        neg = true;
    }
    int32_t d4;
    uint32_t d3, d2, d1, d0;
    intptr_t x = 31*float128_to_5_digits(&d, d4, d3, d2, d1, d0);
    a = make_n5_word_bignum(d4, d3, d2, d1, d0, 0);
#ifdef COMMON
    {   mv_2 = fixnum_of_int(x);
        mv_3 = neg ? fixnum_of_int(-1) : fixnum_of_int(1);
        return nvalues(a, 3);
    }
#else
    return list3(a, fixnum_of_int(x),
                 neg ? fixnum_of_int(-1) : fixnum_of_int(1));
#endif
}
#endif // HAVE_SOFTFLOAT


LispObject Ninteger_decode_float(LispObject env, LispObject a)
{   double d;
    if (!is_float(a)) return aerror("integer-decode-float");
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && flthdr(a) == LONG_FLOAT_HEADER)
        return integer_decode_long_float(a);
#endif // HAVE_SOFTFLOAT
    d = float_of_number(a);
    if (floating_edge_case(d))
    {   if (trap_floating_overflow) return aerror("integer-decode-float");
        else return onevalue(nil); // infinity or NaN
    }
    if (d == 0.0)
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(1.0/d < 0.0 ? -1 : 1);
        nvalues(fixnum_of_int(0), 3);
    }
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(1.0/d < 0.0 ? -1 : 1));
#endif
    bool neg = 0;
    if (d < 0.0)
    {   d = -d;
        neg = true;
    }
    int32_t d2;
    uint32_t d1, d0;
    intptr_t x = 31*double_to_3_digits(d, d2, d1, d0);
    a = make_three_word_bignum(d2, d1, d0);
#ifdef COMMON
    {   mv_2 = fixnum_of_int(x);
        mv_3 = neg ? fixnum_of_int(-1) : fixnum_of_int(1);
        return nvalues(a, 3);
    }
#else
    return list3(a, fixnum_of_int(x),
                 neg ? fixnum_of_int(-1) : fixnum_of_int(1));
#endif
}

setup_type const arith_setup[] =
{   DEF_1("modf",         Nmodf),
    {"plus",              Nplus, Nplus, Nplus, Nplus, Nplus},
    {"plus2",             Nplus, Nplus, Nplus, Nplus, Nplus},
    {"+",                 Nplus, Nplus, Nplus, Nplus, Nplus},
    DEF_1("add1",         Nadd1),
    DEF_1("1+",           Nadd1),
    DEF_2("difference",   Ndifference),
    DEF_2("xdifference",  Nxdifference),
    {"-",                 G0Wother, Nminus, Ndifference, G3Wother, G4Wother},
    {"times",             Ntimes, Ntimes, Ntimes, Ntimes, Ntimes},
    {"times2",            Ntimes, Ntimes, Ntimes, Ntimes, Ntimes},
    {"*",                 Ntimes, Ntimes, Ntimes, Ntimes, Ntimes},
    DEF_2("quotient",     Nquotient),
    DEF_2("//",           Nquotient),
    DEF_2("/",            NCLQuotient),
    DEF_2("remainder",    Nremainder),
    DEF_2("rem",          Nremainder),
    DEF_2("mod",          Nmod),
    DEF_2("divide",       Ndivide),
    {"gcd",               Ngcdn, Ngcdn, Ngcdn, Ngcdn, Ngcdn},
    {"gcdn",              Ngcdn, Ngcdn, Ngcdn, Ngcdn, Ngcdn},
    {"lcmn",              Nlcmn, Nlcmn, Nlcmn, Nlcmn, Nlcmn},
    DEF_1("minus",        Nminus),
    DEF_1("minusp",       Nminusp),
    DEF_1("plusp",        Nplusp),
    DEF_1("abs",          Nabs),
    DEF_1("reciprocal",   Nreciprocal),
    DEF_1("square",       Nsquare),
    DEF_1("sqrt",         Nsqrt),
    DEF_1("isqrt",        Nisqrt),
    DEF_1("sub1",         Nsub1),
    DEF_1("1-",           Nsub1),
    DEF_1("zerop",        Nzerop),
    DEF_1("onep",         Nonep),
    DEF_1("oddp",         Noddp),
    DEF_1("evenp",        Nevenp),
    {"float",             G0Wother, Nfloat, Nfloat, G3Wother, G4Wother},
    DEF_1("float128",     Nfloat128),
    DEF_1("fix",          Nfix),
    {"truncate",          G0Wother, Ntruncate, Ntruncate, G3Wother, G4Wother},
    {"floor",             G0Wother, Nfloor, Nfloor, G3Wother, G4Wother},
    {"ceiling",           G0Wother, Nceiling, Nceiling, G3Wother, G4Wother},
    {"ftruncate",         G0Wother, Nftruncate, Nftruncate, G3Wother, G4Wother},
    {"ffloor",            G0Wother, Nffloor, Nffloor, G3Wother, G4Wother},
    {"fceiling",          G0Wother, Nfceiling, Nfceiling, G3Wother, G4Wother},
    DEF_1("frexp",        Nfrexp),
    DEF_2("ldexp",        Nldexp),
    DEF_2("expt",         Nexpt),
    {"max",               Nmax, Nmax, Nmax, Nmax, Nmax},
    {"max2",              Nmax, Nmax, Nmax, Nmax, Nmax},
    {"imax",              Nmax, Nmax, Nmax, Nmax, Nmax},
    {"min",               Nmin, Nmin, Nmin, Nmin, Nmin},
    {"min2",              Nmin, Nmin, Nmin, Nmin, Nmin},
    {"imin",              Nmin, Nmin, Nmin, Nmin, Nmin},
// Neqn is a name that gives trouble. In one part of the code here it is
// "N" followed by "eqn", and denotes the function that will perform equality
// tests on numbers. In another it is "Neqn", otherwise "neqn" but capitalized
// and it is the name of a class that implements "neqn". So I tag "_a" on
// the end of one of these to resolve the clash.
    {"eqn",               G0Wother, G1Wother, Neqn_a, Neqn_a, Neqn_a},
    {"=",                 G0Wother, G1Wother, NCLEqn, NCLEqn, NCLEqn},
    {"neqn",              G0Wother, G1Wother, Nneqn, Nneqn, Nneqn},
    {"/=",                G0Wother, G1Wother, Nneqn, Nneqn, Nneqn},
    {"greaterp",          G0Wother, G1Wother, Ngreaterp, Ngreaterp, Ngreaterp},
    {">",                 G0Wother, G1Wother, Ngreaterp, Ngreaterp, Ngreaterp},
    {"geq",               G0Wother, G1Wother, Ngeq, Ngeq, Ngeq},
    {">=",                G0Wother, G1Wother, Ngeq, Ngeq, Ngeq},
    {"lessp",             G0Wother, G1Wother, Nlessp, Nlessp, Nlessp},
    {"<",                 G0Wother, G1Wother, Nlessp, Nlessp, Nlessp},
    {"leq",               G0Wother, G1Wother, Nleq, Nleq, Nleq},
    {"<=",                G0Wother, G1Wother, Nleq, Nleq, Nleq},
    {"logand",            Nlogand, Nlogand, Nlogand, Nlogand, Nlogand},
    {"logor",             Nlogor, Nlogor, Nlogor, Nlogor, Nlogor},
    {"logior",            Nlogor, Nlogor, Nlogor, Nlogor, Nlogor},
    {"logxor",            Nlogxor, Nlogxor, Nlogxor, Nlogxor, Nlogxor},
    {"logeqv",            Nlogeqv, Nlogeqv, Nlogeqv, Nlogeqv, Nlogeqv},
    {"land",              Nlogand, Nlogand, Nlogand, Nlogand, Nlogand},
    {"lor",               Nlogor, Nlogor, Nlogor, Nlogor, Nlogor},
    {"lxor",              Nlogxor, Nlogxor, Nlogxor, Nlogxor, Nlogxor},
    {"leqv",              Nlogeqv, Nlogeqv, Nlogeqv, Nlogeqv, Nlogeqv},
    DEF_1("lognot",       Nlognot),
    DEF_1("lnot",         Nlognot),
    DEF_1("lsd",          Nlsd),
    DEF_1("msd",          Nmsd),
    DEF_1("integer-length", Nmsd),
    DEF_1("logcount",     Nlogcount),
    DEF_2("lshift",       Nleftshift),
    DEF_2("ash",          Nleftshift),
    DEF_2("ashift",       Nash1),
    DEF_2("ash1",         Nash1),
    DEF_2("rshift",       Nrightshift),
    {"modular-plus",      Nmodular_plus, Nmodular_plus, Nmodular_plus, Nmodular_plus, Nmodular_plus},
    DEF_2("modular-difference", Nmodular_difference),
    {"modular-times",     Nmodular_times, Nmodular_times, Nmodular_times, Nmodular_times, Nmodular_times},
    DEF_2("modular-quotient",   Nmodular_quotient),
    DEF_2("modular-expt", Nmodular_expt),
    DEF_1("set-modulus",  Nset_modulus),
    DEF_1("set-small-modulus",  Nset_modulus),
    DEF_1("modular-number",     Nmodular_number),
    DEF_1("modular-minus",      Nmodular_minus),
    DEF_1("modular-reciprocal", Nmodular_reciprocal),
    {"iplus",             Niplus, Niplus, Niplus, Niplus, Niplus},
    {"iplus2",            Niplus, Niplus, Niplus, Niplus, Niplus},
    DEF_1("iadd1",        Niadd1),
    DEF_2("idifference",  Nidifference),
    {"itimes",            Nitimes, Nitimes, Nitimes, Nitimes, Nitimes},
    {"itimes2",           Nitimes, Nitimes, Nitimes, Nitimes, Nitimes},
    DEF_2("iquotient",    Niquotient),
    DEF_2("iremainder",   Nremainder),
    DEF_2("irem",         Nremainder),
    DEF_2("imod",         Nmod),
    DEF_2("idivide",      Nidivide),
    {"igcdn",             Nigcdn, Nigcdn, Nigcdn, Nigcdn, Nigcdn},
    {"ilcmn",             Nilcmn, Nilcmn, Nilcmn, Nilcmn, Nilcmn},
    DEF_1("iminus",       Niminus),
    DEF_1("iminusp",      Niminusp),
    DEF_1("iabs",         Niabs),
    DEF_1("ireciprocal",  Nireciprocal),
    DEF_1("isquare",      Nisquare),
    DEF_1("isub1",        Nisub1),
    DEF_1("izerop",       Nizerop),
    DEF_1("ionep",        Nionep),
    DEF_1("ioddp",        Nioddp),
    DEF_1("ievenp",       Nievenp),
    DEF_2("iexpt",        Niexpt),
    {"ieqn",              G0Wother, G1Wother, Nieqn_a, Nieqn_a, Nieqn_a},
    {"ineqn",             G0Wother, G1Wother, Nineqn, Nineqn, Nineqn},
    {"igreaterp",         G0Wother, G1Wother, Nigreaterp, Nigreaterp, Nigreaterp},
    {"igeq",              G0Wother, G1Wother, Nigeq, Nigeq, Nigeq},
    {"ilessp",            G0Wother, G1Wother, Nilessp, Nilessp, Nilessp},
    {"ileq",              G0Wother, G1Wother, Nileq, Nileq, Nileq},
    {"ilogand",           Nilogand, Nilogand, Nilogand, Nilogand, Nilogand},
    {"ilogor",            Nilogor, Nilogor, Nilogor, Nilogor, Nilogor},
    {"ilogxor",           Nilogxor, Nilogxor, Nilogxor, Nilogxor, Nilogxor},
    {"ilogeqv",           Nilogeqv, Nilogeqv, Nilogeqv, Nilogeqv, Nilogeqv},
    {"iland",             Nilogand, Nilogand, Nilogand, Nilogand, Nilogand},
    {"ilor",              Nilogor, Nilogor, Nilogor, Nilogor, Nilogor},
    {"ilxor",             Nilogxor, Nilogxor, Nilogxor, Nilogxor, Nilogxor},
    {"ileqv",             Nilogeqv, Nilogeqv, Nilogeqv, Nilogeqv, Nilogeqv},
    DEF_1("ilognot",      Nilognot),
    DEF_1("ilnot",        Nilognot),
    DEF_1("ilogcount",    Nlogcount),
    DEF_2("ilshift",      Nileftshift),
    DEF_2("irshift",      Nirightshift),
    DEF_2("ileftshift",   Nileftshift),
    DEF_2("irightshift",  Nirightshift),
    DEF_1("abs",          Nabsval),
    DEF_1("acos",         Nacos),
    DEF_1("acosd",        Nacosd),
    DEF_1("acosh",        Nacosh),
    DEF_1("acot",         Nacot),
    DEF_1("acotd",        Nacotd),
    DEF_1("acoth",        Nacoth),
    DEF_1("acsc",         Nacsc),
    DEF_1("acscd",        Nacscd),
    DEF_1("acsch",        Nacsch),
    DEF_1("asec",         Nasec),
    DEF_1("asecd",        Nasecd),
    DEF_1("asech",        Nasech),
    DEF_1("asin",         Nasin),
    DEF_1("asind",        Nasind),
    DEF_1("asinh",        Nasinh),
    DEF_1("atand",        Natand),
    DEF_2("atan2",        Natan2),
    DEF_2("atan2d",       Natan2d),
    DEF_1("atanh",        Natanh),
    DEF_1("cbrt",         Ncbrt),
    DEF_1("cos",          Ncos),
    DEF_1("cosd",         Ncosd),
    DEF_1("cosh",         Ncosh),
    DEF_1("cot",          Ncot),
     DEF_1("cotd",         Ncotd),
    DEF_1("coth",         Ncoth),
    DEF_1("csc",          Ncsc),
    DEF_1("cscd",         Ncscd),
    DEF_1("csch",         Ncsch),
    DEF_1("exp",          Nexp),
    DEF_2("expt",         Nexpt),
    DEF_2("hypot",        Nhypot),
    DEF_1("ln",           Nln),
    {"log",               G0Wother, Nln, Nlog_2, G3Wother, G4Wother},
    DEF_1("log2",         Nlog2),
    DEF_1("log10",        Nlog10),
    DEF_1("sec",          Nsec),
    DEF_1("secd",         Nsecd),
    DEF_1("sech",         Nsech),
    DEF_1("sin",          Nsin),
    DEF_1("sind",         Nsind),
    DEF_1("sinh",         Nsinh),
    DEF_1("sqrt",         Nsqrt),
    DEF_1("tan",          Ntan),
    DEF_1("tand",         Ntand),
    DEF_1("tanh",         Ntanh),
    DEF_1("cis",          Ncis),
//  DEF_1("isqrt",        Nisqrt),
    DEF_1("phase",        Nphase),
    DEF_1("signum",       Nsignum),
    {"atan",              G0Wother, Natan, Natan_2, G3Wother, G4Wother},
    DEF_2("logb",         Nlog_2),
    DEF_2("native-carg",  Ncarg),
    DEF_2("native-cabs",  Ncabs),
    DEF_2("native-cexp",  Ncexp),
    DEF_2("native-clog",  Nclog),
    DEF_2("native-csqrt", Ncsqrt),
    DEF_2("native-csin",  Ncsin),
    DEF_2("native-ccos",  Nccos),
    DEF_2("native-ctan",  Nctan),
    DEF_2("native-ccsc",  Nccsc),
    DEF_2("native-csec",  Ncsec),
    DEF_2("native-ccot",  Nccot),
    DEF_2("native-casin", Ncasin),
    DEF_2("native-cacos", Ncacos),
    DEF_2("native-catan", Ncatan),
    DEF_2("native-cacsc", Ncacsc),
    DEF_2("native-casec", Ncasec),
    DEF_2("native-cacot", Ncacot),
    DEF_2("native-csinh", Ncsinh),
    DEF_2("native-ccosh", Nccosh),
    DEF_2("native-ctanh", Nctanh),
    DEF_2("native-ccsch", Nccsch),
    DEF_2("native-csech", Ncsech),
    DEF_2("native-ccoth", Nccoth),
    DEF_2("native-casinh",Ncasinh),
    DEF_2("native-cacosh",Ncacosh),
    DEF_2("native-catanh",Ncatanh),
    DEF_2("native-cacsch",Ncacsch),
    DEF_2("native-casech",Ncasech),
    DEF_2("native-cacoth",Ncacoth),
    DEF_1("numerator",    Nnumerator),
    DEF_1("denominator",  Ndenominator),
    DEF_1("realpart",     Nrealpart),
    DEF_1("imagpart",     Nimagpart),
    DEF_1("decode-float", Ndecode_float),
    DEF_1("integer-decode-float", Ninteger_decode_float),

    DEF_1("fp-infinite", Nfp_infinite),
    DEF_1("float-infinity-p", Nfp_infinite),
    DEF_1("fp-nan", Nfp_nan),
    DEF_1("fp-finite", Nfp_finite),
    DEF_1("fp-subnorm", Nfp_subnorm),
    DEF_1("float-denormalized-p", Nfp_subnorm),
    DEF_1("fp-signbit", Nfp_signbit),
    DEF_1("float-sign", Nfp_signbit),
    DEF_1("float-digits", Nfloat_digits),
    DEF_1("float-precision", Nfloat_precision),
    DEF_1("float-radix", Nfloat_radix),
    {"float_sign", G0Wother, Nfloat_sign1, Nfloat_sign2, G3Wother, G4Wother},

    DEF_1("rational", Nrational),
    DEF_1("manexp", Nmanexp),
    DEF_1("rationalize", Nrationalize),
    {"random", G0Wother, Nrandom_1, Nrandom_2, G3Wother, G4Wother}, 
    DEF_0("next-random-number", Nnext_random),
    DEF_0("random-fixnum", Nnext_random),
    {"make-random-state", G0Wother, Nmake_random_state1, Nmake_random_state, G3Wother, G4Wother},
    DEF_1("md5", Nmd5),
    DEF_1("md5string", Nmd5string),
    DEF_1("md60", Nmd60),
    DEF_2("inorm", Ninorm),
    DEF_3("boole", Nboole),
    DEF_2("byte", Nbyte),
    DEF_1("byte-position", Nbyte_position),
    DEF_1("byte-size", Nbyte_size),
    {"complex", G0Wother, Ncomplex_1, Ncomplex_2, G3Wother, G4Wother}, 
    DEF_1("conjugate", Nconjugate),

    {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}
};

#endif // ARITHLIB

// end of arith-setup.cpp
