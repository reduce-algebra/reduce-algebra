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

size_t randSize()
{   uintptr_t r = Crand();
#if 0
    r = doubleword_align_up(r);
    return 16384/CELL - 128 + (r & 0xff);
#else
    return doubleword_align_up(CELL+ r%40);
#endif
}

void random_fill(LispObject v)
{   size_t n = cells_in_vector(v);
    for (size_t i=0; i<n; i++)
        elt(v, i) = fixnum_of_int(Crand() % 1000);
}

void gcTestCode()
{   std::printf("\n: Conservative code - run a simple test of the GC\n\n");
    int gcCount = 0;
    set_up_signal_handlers();
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
    for (int i=0; i<60; i++)
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
            random_fill(workbase[1]);
            zprintf("&&&setvec workbase 1 = %a\n", workbase[1]);
            break;
        case 6:
            workbase[2] = get_basic_vector_init(randSize(), fixnum_of_int(Crand()&0xffff));
            random_fill(workbase[2]);
            zprintf("&&&setvec workbase 2 = %a\n", workbase[2]);
            break;
        case 7:
            ambiguous[1] = get_basic_vector_init(randSize(), fixnum_of_int(Crand()&0xffff));
            random_fill(ambiguous[1]);
            zprintf("&&&setvec ambiguous 1 = %a\n", ambiguous[1]);
            break;
        case 8:
            ambiguous[2] = get_basic_vector_init(randSize(), fixnum_of_int(Crand()&0xffff));
            random_fill(ambiguous[2]);
            zprintf("&&&setvec ambiguous 2 = %a\n", ambiguous[2]);
            break;
        case 9:
            std::cout << "&&&provoke reclaim\n";
            displayAllPages("memory before GC");
            uint64_t w1 = crudeHash(workbase[1], "w1");
            uint64_t w2 = crudeHash(workbase[2], "w2");
            uint64_t a1 = crudeHash(ambiguous[1], "a1");
            uint64_t a2 = crudeHash(ambiguous[2], "a2");
            zprintf("w1=%a w2=%a a1=%a a2=%a\n", workbase[1], workbase[2],
                                                 ambiguous[1], ambiguous[2]);
            zprintf("w1="); simple_print(workbase[1]);
            zprintf("w2="); simple_print(workbase[2]);
            zprintf("a1="); simple_print(ambiguous[1]);
            zprintf("a2="); simple_print(ambiguous[2]);
            displayAllPages("memory before after GC");
            Lgc(nil, fixnum_of_int(Crand()&0xffff));
            uint64_t w1a = crudeHash(workbase[1], "w1");
            uint64_t w2a = crudeHash(workbase[2], "w2");
            uint64_t a1a = crudeHash(ambiguous[1], "a1");
            uint64_t a2a = crudeHash(ambiguous[2], "a2");
            zprintf("w1=%a w2=%a a1=%a a2=%a\n", workbase[1], workbase[2],
                                                 ambiguous[1], ambiguous[2]);
            zprintf("w1="); simple_print(workbase[1]);
            zprintf("w2="); simple_print(workbase[2]);
            zprintf("a1="); simple_print(ambiguous[1]);
            zprintf("a2="); simple_print(ambiguous[2]);
            displayAllPages("memory after after GC");
            std::cout << "&&&end reclaim\n";
            if (w1!=w1a || w2!=w2a || a1!=a1a || a2!=a2a)
            {   zprintf("%x %x   %x %x   %x %x   %x %x\n",
                        w1, w1a,  w2, w2a, a1, a1a, a2, a2a);
                my_abort("corrupted by GC");
            }
//          if (++gcCount == 1) i = 10000;
            break;
        }
    }
    zprintf("&&&do one final GC\n");
    Lgc(nil, fixnum_of_int(0x999999));
    std::printf("\n\n*** About to terminate happily ***\n\n");
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
