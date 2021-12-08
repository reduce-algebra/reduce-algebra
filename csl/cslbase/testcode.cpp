// testcode.cpp                                 Copyright (C) 2021 Codemist

// This is code to exercise the draft conservative GC.

/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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
{   if (n == 0)
    {   Lgc(nil, lisp_true);
#if defined CONSERVATIVE && defined DEBUG
        cout << "Fringe = " << Addr(fringe) << " at end of GC\n";
        cout << "Limit = " << Addr(limit) << " at end of GC\n";
#endif
        return fixnum_of_int(payload);
    }
    return cons(ncons(fixnum_of_int(n)), runtest(n-1, payload));
}

#undef INIT_OBVECI_SIZE
#define INIT_OBVECI_SIZE 16

void gcTestCode()
{   std::printf("\n: Conservative code - run a simple test of the GC\n\n");
    set_up_signal_handlers();
    cout << "create package object\n";
    setvalue(nil, get_basic_vector_init(sizeof(Package), nil));
    setpackage(nil, static_cast<LispObject>(qvalue(nil)));

    packhdr_(static_cast<LispObject>(CP)) =
        TYPE_STRUCTURE+(packhdr_(static_cast<LispObject>(CP)) & ~header_mask);
    cout << "create package vector\n";
    packint_(static_cast<LispObject>(CP)) =
        get_basic_vector_init(CELL*(1+16), fixnum_of_int(0));
    packflags_(static_cast<LispObject>(CP)) =
        fixnum_of_int(++package_bits);

    packnint_(static_cast<LispObject>(CP)) =
        fixnum_of_int(1); // Allow for nil
// Place NIL into the table.
    {   size_t i = hash_lisp_string(qpname(nil)) & (INIT_OBVECI_SIZE - 1);
        cout << "Place NIL at offset " << i << "\n";
        elt(packint_(static_cast<LispObject>(CP)), i) = nil;
    }
    fastget_size = 63;
#undef boffo_size
#define boffo_size 32
    cout << "create boffo\n";
    boffo = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+boffo_size);
    std::memset(reinterpret_cast<void *>(reinterpret_cast<char *>
                                         (boffo) + (CELL - TAG_VECTOR)), '@', boffo_size);
//
// The next line has hidden depths.  When it is obeyed during cold start
// the C variable *package* has the value nil, hence make_symbol
// looks in the value cell of nil to find the package to intern wrt. Once
// this has been done I can put nil back how it ought to have been!
//
    cout << "create *package* symbol\n";
    current_package          = make_undefined_fluid("*package*");
    lisp_package             = qpackage(nil);
    setvalue(current_package,  lisp_package);
    setvalue(nil,              nil);          // Whew!
    setpackage(nil,            lisp_package);
    setpackage(current_package,lisp_package);

    cout << "create T symbol\n";
    lisp_true           = make_undefined_global("t");
    setvalue(lisp_true,   lisp_true);

    cout << "Now run the test\n";
    simple_print(runtest(1, 9999));
    cout << "\nFirst GC test over\n";
    simple_print(runtest(1, 6666));
    cout << "\nSecond GC test over\n";
// Probably broken now!
}

// end of testcode.cpp
