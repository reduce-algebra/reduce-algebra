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

// $Id: fns1.cpp 4980 2019-05-06 12:08:42Z arthurcnorman $


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

static LispObject Nadd1(LispObject env, LispObject a1)
{   return onevalue(Plus::op(a1, fixnum_of_int(1)));
}

#if 0
Nplus,                   Nplus,                   Nplus,                   Nplus,                   Nplus,
Nadd1,                   Nadd1,                   Nadd1,                   Nadd1,                   Nadd1,
Nsub1,                   Nsub1,                   Nsub1,                   Nsub1,                   Nsub1,
Ndifference,             Ndifference,             Ndifference,             Ndifference,             Ndifference,
Ntimes,                  Ntimes,                  Ntimes,                  Ntimes,                  Ntimes,
Nquotient,               Nquotient,               Nquotient,               Nquotient,               Nquotient,
Nremainder,              Nremainder,              Nremainder,              Nremainder,              Nremainder,
Ndivide,                 Ndivide,                 Ndivide,                 Ndivide,                 Ndivide,
Nexpt,                   Nexpt,                   Nexpt,                   Nexpt,                   Nexpt,
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
Ngcdn,                   Ngcdn,                   Ngcdn,                   Ngcdn,                   Ngcdn,
Nlcmn,                   Nlcmn,                   Nlcmn,                   Nlcmn,                   Nlcmn,
Nmodular_plus,           Nmodular_plus,           Nmodular_plus,           Nmodular_plus,           Nmodular_plus,
Nmodular_difference,     Nmodular_difference,     Nmodular_difference,     Nmodular_difference,     Nmodular_difference,
Nmodular_times,          Nmodular_times,          Nmodular_times,          Nmodular_times,          Nmodular_times,
Nmodular_quotient,       Nmodular_quotient,       Nmodular_quotient,       Nmodular_quotient,       Nmodular_quotient,
Nminus,                  Nminus,                  Nminus,                  Nminus,                  Nminus,
Nminusp,                 Nminusp,                 Nminusp,                 Nminusp,                 Nminusp,
Nreciprocal,             Nreciprocal,             Nreciprocal,             Nreciprocal,             Nreciprocal,
Nzerop,                  Nzerop,                  Nzerop,                  Nzerop,                  Nzerop,
Nonep,                   Nonep,                   Nonep,                   Nonep,                   Nonep,
Noddp,                   Noddp,                   Noddp,                   Noddp,                   Noddp,
Nevenp,                  Nevenp,                  Nevenp,                  Nevenp,                  Nevenp,
Nbitnot,                 Nbitnot,                 Nbitnot,                 Nbitnot,                 Nbitnot,
Nset_Modulus,            Nset_Modulus,            Nset_Modulus,            Nset_Modulus,            Nset_Modulus,
Nmodular_number,         Nmodular_number,         Nmodular_number,         Nmodular_number,         Nmodular_number,
Nmodular_minus,          Nmodular_minus,          Nmodular_minus,          Nmodular_minus,          Nmodular_minus,
Nfloat,                  Nfloat,                  Nfloat,                  Nfloat,                  Nfloat,
Nfloat128,               Nfloat128,               Nfloat128,               Nfloat128,               Nfloat128,
Nfix,                    Nfix,                    Nfix,                    Nfix,                    Nfix,
Nfloor,                  Nfloor,                  Nfloor,                  Nfloor,                  Nfloor,
Nceiling,                Nceiling,                Nceiling,                Nceiling,                Nceiling,
Nfrexp,                  Nfrexp,                  Nfrexp,                  Nfrexp,                  Nfrexp,
Nldexp,                  Nldexp,                  Nldexp,                  Nldexp,                  Nldexp,
#endif

setup_type const arith_setup[] =
{
    {"newplus",              Nplus,              Nplus,              Nplus,              Nplus,              Nplus},
    {"newadd1",              G0W1,               Nadd1,              G2W1,               G3W1,               G4W1},
#if 0
    {"newdifference",        Ndifference,        Ndifference,        Ndifference,        Ndifference,        Ndifference},
    {"newtimes",             Ntimes,             Ntimes,             Ntimes,             Ntimes,             Ntimes},
    {"newquotient",          Nquotient,          Nquotient,          Nquotient,          Nquotient,          Nquotient},
    {"newremainder",         Nremainder,         Nremainder,         Nremainder,         Nremainder,         Nremainder},
    {"newdivide",            Ndivide,            Ndivide,            Ndivide,            Ndivide,            Ndivide},
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
    {"newgcdn",              Ngcdn,              Ngcdn,              Ngcdn,              Ngcdn,              Ngcdn},
    {"newlcmn",              Nlcmn,              Nlcmn,              Nlcmn,              Nlcmn,              Nlcmn},
    {"newmodular-plus",      Nmodular_plus,      Nmodular_plus,      Nmodular_plus,      Nmodular_plus,      Nmodular_plus},
    {"newmodular-difference",Nmodular_difference,Nmodular_difference,Nmodular_difference,Nmodular_difference,Nmodular_difference},
    {"newmodular-times",     Nmodular_times,     Nmodular_times,     Nmodular_times,     Nmodular_times,     Nmodular_times},
    {"newmodular-quotient",  Nmodular_quotient,  Nmodular_quotient,  Nmodular_quotient,  Nmodular_quotient,  Nmodular_quotient},
    {"newminus",             Nminus,             Nminus,             Nminus,             Nminus,             Nminus},
    {"newminusp",            Nminusp,            Nminusp,            Nminusp,            Nminusp,            Nminusp},
    {"newreciprocal",        Nreciprocal,        Nreciprocal,        Nreciprocal,        Nreciprocal,        Nreciprocal},
    {"newsub1",              Nsub1,              Nsub1,              Nsub1,              Nsub1,              Nsub1},
    {"newzerop",             Nzerop,             Nzerop,             Nzerop,             Nzerop,             Nzerop},
    {"newonep",              Nonep,              Nonep,              Nonep,              Nonep,              Nonep},
    {"newoddp",              Noddp,              Noddp,              Noddp,              Noddp,              Noddp},
    {"newevenp",             Nevenp,             Nevenp,             Nevenp,             Nevenp,             Nevenp},
    {"newbitnot",            Nbitnot,            Nbitnot,            Nbitnot,            Nbitnot,            Nbitnot},
    {"newset-modulus",       Nset_Modulus,       Nset_Modulus,       Nset_Modulus,       Nset_Modulus,       Nset_Modulus},
    {"newmodular-number",    Nmodular_number,    Nmodular_number,    Nmodular_number,    Nmodular_number,    Nmodular_number},
    {"newmodular-minus",     Nmodular_minus,     Nmodular_minus,     Nmodular_minus,     Nmodular_minus,     Nmodular_minus},
    {"newfloat",             Nfloat,             Nfloat,             Nfloat,             Nfloat,             Nfloat},
    {"newfloat128",          Nfloat128,          Nfloat128,          Nfloat128,          Nfloat128,          Nfloat128},
    {"newfix",               Nfix,               Nfix,               Nfix,               Nfix,               Nfix},
    {"newfloor",             Nfloor,             Nfloor,             Nfloor,             Nfloor,             Nfloor},
    {"newceiling",           Nceiling,           Nceiling,           Nceiling,           Nceiling,           Nceiling},
    {"newfrexp",             Nfrexp,             Nfrexp,             Nfrexp,             Nfrexp,             Nfrexp},
    {"newldexp",             Nldexp,             Nldexp,             Nldexp,             Nldexp,             Nldexp},
#endif
    {NULL,                   0, 0, 0, 0, 0}
};

// end of arith-setup.cpp

#endif // ARITHLIB

