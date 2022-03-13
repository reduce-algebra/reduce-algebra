// testcode.cpp                                 Copyright (C) 2022 Codemist

// This is code to exercise the draft conservative GC.

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

// $Id: testcode.cpp 5763 2021-04-16 16:01:23Z arthurcnorman $

#include "headers.h"

LispObject runtest(int n, int payload)
{
    if ((Crand()&255) < 2)
    {   Lgc(nil, fixnum_of_int(1));
        zprintf("Fringe = %a at end of GC\n", fringe);
        zprintf("Limit = %a at end of GC\n\n\n", limit);
    }
    if (n < 2) return Lflag(nil, ncons(lisp_true), fixnum_of_int(0x33333));
// This version does not rely on ambiguous pointers to preserve anything.
    LispObject w = runtest(n-1, payload);
    RealSave s2(w);
    LispObject x = runtest(n-2, payload);
    s2.restore(w);
    return cons(w, x);
//  return cons(runtest(n-1, payload), runtest(n-2, payload));
}

#undef INIT_OBVECI_SIZE
#define INIT_OBVECI_SIZE 16

void gcTestCode()
{   std::printf("\n: Conservative code - run a simple test of the GC\n\n");
    set_up_signal_handlers();
    setpname(nil, make_string("*NIL*"));
#if 1
    lisp_true = get_symbol(false);
    setheader(lisp_true, TAG_HDR_IMMED+TYPE_SYMBOL);
    setvalue(lisp_true, lisp_true);
    setpname(lisp_true, make_string("*T*"));
    setplist(lisp_true, nil);
    setfastgets(lisp_true, nil);
    setpackage(lisp_true, nil);
    setenv(lisp_true, lisp_true);
    qfn0(lisp_true) = undefined_0;
    qfn1(lisp_true) = undefined_1;
    qfn2(lisp_true) = undefined_2;
    qfn3(lisp_true) = undefined_3;
    qfn4up(lisp_true) = undefined_4up;
    qcountLow(lisp_true) = 0;
    qcountHigh(lisp_true) = 0;

    int n = Crand() % 20;
    zprintf("n = %d\n", n);
    simple_print(runtest(n, fixnum_of_int(0x22222)));
    std::printf("Nearly done - just one more GC\n");
    Lgc(nil, fixnum_of_int(0x11111));
    std::printf("completed final GC\n");
#else
#if 0
    LispObject w;
//  setpname(nil, w = make_string("nil"));
    setpname(nil, w = cons(fixnum_of_int(1),
                           cons(fixnum_of_int(2), fixnum_of_int(3))));
#endif
    setvalue(nil,              nil);          // Whew!

    for (int i=0; i<1000; i++) Crand();
    zprintf("Run the test\n");
    for (int i=1; i<10; i++)
    {   simple_print(runtest(1+Crand()%15, i));
        zprintf("\nGC test %d over\n", i);
    }
#endif
    std::printf("About to terminate\n");
    term_close();
    fflush(stdout);
    fflush(stderr);
    std::quick_exit(0);
}

// end of testcode.cpp
