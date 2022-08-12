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

const char* which;

uint64_t crudeHash(LispObject a)
{   if (is_cons(a))
        return 12345u + 169*(crudeHash(car(a)) + 169*crudeHash(cdr(a)));
    else if (is_fixnum(a)) return 11213u*a;
    else if (is_vector(a))
    {   uint64_t r = 19937u;
        size_t len=cells_in_vector(a);
        for (size_t i=0; i<len; i++)
            r = 21701*r + crudeHash(elt(a, i));
        return r;
    }
    else
    {   zprintf("!!!crudeHash(%16.16x) %s\n", a, which);
        displayAllPages("crudeHash messup");
        my_abort("bad value in crudeHash");
    }
}

uint64_t crudeHash(LispObject a, const char* w)
{   which = w;
    return crudeHash(a);
}

LispObject runtest(int n, int payload)
{
    if ((Crand()&255) < 2)
    {   Lgc(nil, fixnum_of_int(1));
        zprintf("consFringe = %a at end of GC\n", consFringe);
        zprintf("consLimit = %a at end of GC\n\n\n", consLimit);
        zprintf("vecFringe = %a at end of GC\n", vecFringe);
        zprintf("vecLimit = %a at end of GC\n\n\n", vecLimit);
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

size_t randSize()
{   uintptr_t r = Crand();
    r = doubleword_align_up(r);
    return 16384/CELL - 128 + (r & 0xff);
}

void gcTestCode()
{   std::printf("\n: Conservative code - run a simple test of the GC\n\n");
    set_up_signal_handlers();
#ifndef OLD
// I will take the view that the following are things that can happen:
// (1) set workbase[1] to a new cons
// (2) set workbase[2] to a new cons
// (3) set ambiguous[1] to a new cons
// (4) set ambiguous[2] to a new cons
// (5) set workbase[1] to a new vector
// (6) set workbase[2] to a new vector
// (7) set ambiguous[1] to a new vector
// (8) set ambiguous[2] to a new vector
// (9) garbage collect
// Note that each of 1-8 can discard the items previously stored there.

    workbase[1] = fixnum_of_int(Crand()&0xffff);
    workbase[2] = fixnum_of_int(Crand()&0xffff);
    ambiguous[1] = fixnum_of_int(Crand()&0xffff);
    ambiguous[2] = fixnum_of_int(Crand()&0xffff);
    for (int i=0; i<24; i++)
    {   switch (Crand()%10)
        {
        default:
        case 0:
            workbase[1] = cons(fixnum_of_int(Crand()&0xffff), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&set workbase 1 = %a\n", workbase[1]);
            break;
        case 1:
            workbase[2] = cons(fixnum_of_int(Crand()&0xffff), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&set workbase 2 = %a\n", workbase[2]);
            break;
        case 2:
            ambiguous[1] = cons(fixnum_of_int(Crand()&0xffff), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&set ambiguous 1 = %a\n", ambiguous[1]);
            break;
        case 3:
            ambiguous[2] = cons(fixnum_of_int(Crand()&0xffff), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&set ambiguous 2 = %a\n", ambiguous[2]);
            break;
        case 5:
            workbase[1] = get_basic_vector_init(randSize(), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&setvec workbase 1 = %a\n", workbase[1]);
            break;
        case 6:
            workbase[2] = get_basic_vector_init(randSize(), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&setvec workbase 2 = %a\n", workbase[2]);
            break;
        case 7:
            ambiguous[1] = get_basic_vector_init(randSize(), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&setvec ambiguous 1 = %a\n", ambiguous[1]);
            break;
        case 8:
            ambiguous[2] = get_basic_vector_init(randSize(), fixnum_of_int(Crand()&0xffff));
            zprintf("&&&setvec ambiguous 2 = %a\n", ambiguous[2]);
            break;
        case 9:
            std::cout << "&&&provoke reclaim\n";
            displayAllPages("memory before GC");
            uint64_t h0 = crudeHash(workbase[1], "w1") +
                          crudeHash(workbase[2], "w2") +
                          crudeHash(ambiguous[1], "a1") +
                          crudeHash(ambiguous[2], "a2");
            Lgc(nil, fixnum_of_int(Crand()&0xffff));
            uint64_t h1 = crudeHash(workbase[1], "w1") +
                          crudeHash(workbase[2], "w2") +
                          crudeHash(ambiguous[1], "a1") +
                          crudeHash(ambiguous[2], "a2");
            displayAllPages("memory after after GC");
            std::cout << "&&&end reclaim\n";
            my_assert(h1 == h0, "corrupted by GC");
            break;
        }
    }
    zprintf("&&&do one final GC\n");
    Lgc(nil, fixnum_of_int(0x999999));

#if 0
// This is going to let me control everything. I use workbase[] for
// precise pointers and ambiguous[] for uncertain ones and thus control
// exactly what ius alive and what is dead.
    setpname(nil, make_string("NIL"));
    workbase[1] = cons(fixnum_of_int(0x2222), fixnum_of_int(0x3333));
    workbase[2] = cons(workbase[1], nil);
    ambiguous[1] = workbase[2];
//  a->((2222 . 3333))    pname[nil] = "NIL"
    Lgc(nil, fixnum_of_int(0x111111));
//  (x) pinned in page 0, x:(2222 . 3333) and "NIL" in page 1
    Lgc(nil, fixnum_of_int(0x111111));
//  (x) pinned in page 0, x:(2222 . 3333) and "NIL" in a separate
//      chunk but also in page 0
    workbase[1] = workbase[2] = nil;
// Now try with only the ambiguous pointer saving things
    Lgc(nil, fixnum_of_int(0x111111));
    Lgc(nil, fixnum_of_int(0x111111));
    Lgc(nil, fixnum_of_int(0x111111));
    workbase[1] = ambiguous[1];
    ambiguous[1] = 0;
    Lgc(nil, fixnum_of_int(0x111111));
#endif
    
    

#else // OLD
// now the OLD code
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

    zprintf("Run the test\n");
    for (int i=1; i<10; i++)
    {   simple_print(runtest(1+Crand()%15, i));
        zprintf("\nGC test %d over\n", i);
    }
#endif
#endif // OLD
    std::printf("About to terminate\n");
    term_close();
    fflush(stdout);
    fflush(stderr);
#ifdef HAVE_QUICK_EXIT
    std::quick_exit(0);
#else // HAVE_QUICK_EXIT
    std::exit(0);
#endif // HAVE_QUICK_EXIT
}

// end of testcode.cpp
