#ifdef ARITHLIB

// arith-setup.cpp                              Copyright (C) 2019 Codemist    

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



#if 0
// Pending...
Nexpt,
Neqn,                    Neqn,                    Neqn,                    Neqn,                    Neqn,
Nneqn,                   Nneqn,                   Nneqn,                   Nneqn,                   Nneqn,
Ngreaterp,               Ngreaterp,               Ngreaterp,               Ngreaterp,               Ngreaterp,
Ngeq,                    Ngeq,                    Ngeq,                    Ngeq,                    Ngeq,
Nlessp,                  Nlessp,                  Nlessp,                  Nlessp,                  Nlessp,
Nleq,                    Nleq,                    Nleq,                    Nleq,                    Nleq,
Nlogand,                 Nlogand,                 Nlogand,                 Nlogand,                 Nlogand,
Nlogor,                  Nlogor,                  Nlogor,                  Nlogor,                  Nlogor,
Nlogxor,                 Nlogxor,                 Nlogxor,                 Nlogxor,                 Nlogxor,
Nlogeqv,                 Nlogeqv,                 Nlogeqv,                 Nlogeqv,                 Nlogeqv,
Nlshift,                 Nlshift,                 Nlshift,                 Nlshift,                 Nlshift,
Nrshift,                 Nrshift,                 Nrshift,                 Nrshift,                 Nrshift,
Nmodular_plus,           Nmodular_plus,           Nmodular_plus,           Nmodular_plus,           Nmodular_plus,
Nmodular_difference,     Nmodular_difference,     Nmodular_difference,     Nmodular_difference,     Nmodular_difference,
Nmodular_times,          Nmodular_times,          Nmodular_times,          Nmodular_times,          Nmodular_times,
Nmodular_quotient,       Nmodular_quotient,       Nmodular_quotient,       Nmodular_quotient,       Nmodular_quotient,
Nbitnot,                 Nbitnot,                 Nbitnot,                 Nbitnot,                 Nbitnot,
Nset_Modulus,            Nset_Modulus,            Nset_Modulus,            Nset_Modulus,            Nset_Modulus,
Nmodular_number,         Nmodular_number,         Nmodular_number,         Nmodular_number,         Nmodular_number,
Nmodular_minus,          Nmodular_minus,          Nmodular_minus,          Nmodular_minus,          Nmodular_minus,
#endif

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
    {"newldexp",             G0W1,               G1W2,               Nldexp,             G3W1,               G4W1},
#if 0
// These ones do not even have stubs by way of dummy implementation.
    {"newexpt",              Nexpt,              Nexpt,              Nexpt,              Nexpt,              Nexpt},
    {"neweqn",               Neqn,               Neqn,               Neqn,               Neqn,               Neqn},
    {"newneqn",              Nneqn,              Nneqn,              Nneqn,              Nneqn,              Nneqn},
    {"newgreaterp",          Ngreaterp,          Ngreaterp,          Ngreaterp,          Ngreaterp,          Ngreaterp},
    {"newgeq",               Ngeq,               Ngeq,               Ngeq,               Ngeq,               Ngeq},
    {"newlessp",             Nlessp,             Nlessp,             Nlessp,             Nlessp,             Nlessp},
    {"newleq",               Nleq,               Nleq,               Nleq,               Nleq,               Nleq},
    {"newlogand",            Nlogand,            Nlogand,            Nlogand,            Nlogand,            Nlogand},
    {"newlogor",             Nlogor,             Nlogor,             Nlogor,             Nlogor,             Nlogor},
    {"newlogxor",            Nlogxor,            Nlogxor,            Nlogxor,            Nlogxor,            Nlogxor},
    {"newlogeqv",            Nlogeqv,            Nlogeqv,            Nlogeqv,            Nlogeqv,            Nlogeqv},
    {"newlshift",            Nlshift,            Nlshift,            Nlshift,            Nlshift,            Nlshift},
    {"newrshift",            Nrshift,            Nrshift,            Nrshift,            Nrshift,            Nrshift},
    {"newmodular-plus",      Nmodular_plus,      Nmodular_plus,      Nmodular_plus,      Nmodular_plus,      Nmodular_plus},
    {"newmodular-difference",Nmodular_difference,Nmodular_difference,Nmodular_difference,Nmodular_difference,Nmodular_difference},
    {"newmodular-times",     Nmodular_times,     Nmodular_times,     Nmodular_times,     Nmodular_times,     Nmodular_times},
    {"newmodular-quotient",  Nmodular_quotient,  Nmodular_quotient,  Nmodular_quotient,  Nmodular_quotient,  Nmodular_quotient},
    {"newbitnot",            Nbitnot,            Nbitnot,            Nbitnot,            Nbitnot,            Nbitnot},
    {"newset-modulus",       Nset_Modulus,       Nset_Modulus,       Nset_Modulus,       Nset_Modulus,       Nset_Modulus},
    {"newmodular-number",    Nmodular_number,    Nmodular_number,    Nmodular_number,    Nmodular_number,    Nmodular_number},
    {"newmodular-minus",     Nmodular_minus,     Nmodular_minus,     Nmodular_minus,     Nmodular_minus,     Nmodular_minus},
#endif
    {NULL,                   0, 0, 0, 0, 0}
};

// end of arith-setup.cpp

#endif // ARITHLIB

