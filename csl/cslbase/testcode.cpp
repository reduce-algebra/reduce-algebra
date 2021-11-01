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


void gcTestCode()
{   std::printf("\n: Conservative code - run a simple test of the GC\n\n");
    setvalue(nil, get_basic_vector_init(sizeof(Package), nil));
    setpackage(nil, static_cast<LispObject>(qvalue(nil)));

    packhdr_(static_cast<LispObject>(CP)) = TYPE_STRUCTURE + (packhdr_
                                            (static_cast<LispObject>(CP)) & ~header_mask);
    packint_(static_cast<LispObject>(CP)) = get_basic_vector_init(CELL*
                                            (1+2048), fixnum_of_int(0));
    packflags_(static_cast<LispObject>(CP)) = fixnum_of_int(++package_bits);

    packnint_(static_cast<LispObject>(CP)) = fixnum_of_int(
                1); // Allow for nil
// Place NIL into the table.
    {   size_t i = (size_t)(hash_lisp_string(qpname(nil)) &
                            (INIT_OBVECI_SIZE - 1));
        elt(packint_(static_cast<LispObject>(CP)), i) = nil;
    }
    gensym_ser = 1;
    print_precision = 6; // I maybe prefer 15 but use 6 to agree with PSL
    current_modulus = 1;
// a fastget entry of 0 means no fastget stuff present, and so in the 6-bit
// field I have the values 1-63 are available.
//
    fastget_size = 63;
    package_bits = 0;
    unset_var = nil;
//
// there had better not be a need for garbage collection here...
// ... or elsewhere in setup, since the world is not yet put together.
// Ditto interrupts.
//
#define boffo_size 256
    boffo = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+boffo_size);
    std::memset(reinterpret_cast<void *>(reinterpret_cast<char *>
                                         (boffo) + (CELL - TAG_VECTOR)), '@', boffo_size);
//
// The next line has hidden depths.  When it is obeyed during cold start
// the C variable *package* has the value nil, hence make_symbol
// looks in the value cell of nil to find the package to intern wrt. Once
// this has been done I can put nil back how it ought to have been!
//
    current_package          = make_undefined_fluid("*package*");
    lisp_package             = qpackage(nil);
    setvalue(current_package,  lisp_package);
    setvalue(nil,              nil);          // Whew!
    my_assert(qvalue(nil) == nil);
    setpackage(nil,            lisp_package);
    setpackage(current_package,lisp_package);
    my_assert(qvalue(nil) == nil);


    unset_var                =
        make_undefined_global("~indefinite-value~");
    setvalue(unset_var,        unset_var);
    lisp_true           = make_undefined_global("t");
    setvalue(lisp_true,   lisp_true);
#define make_keyword(name) make_undefined_symbol(name)
    gensym_base         = make_string("G");
    raise_symbol        = make_undefined_fluid("*raise");
    lower_symbol        = make_undefined_fluid("*lower");
    echo_symbol         = make_undefined_fluid("*echo");
    macroexpand_hook    = make_undefined_fluid("*macroexpand");
    input_libraries     = make_undefined_fluid("input-libraries");
    output_library      = make_undefined_fluid("output-library");
    current_function    = // system-startup
        startup_symbol      = make_undefined_symbol("system-startup");

    sys_hash_table = Lmkhash_1(nil, fixnum_of_int(2));    // EQUAL
//@ sxhash_hash_table = Lmkhash_1(nil, fixnum_of_int(0)); // EQ
    get_counts = Lmkhash_1(nil, fixnum_of_int(0));        // EQ
    fastget_names = get_basic_vector_init((MAX_FASTGET_SIZE+2)*CELL,
                                          SPID_NOPROP);
    lisp_work_stream = make_stream_handle();
    lisp_terminal_io = make_stream_handle();
    lisp_standard_output = make_stream_handle();
    lisp_standard_input = make_stream_handle();
    lisp_error_output = make_stream_handle();
    lisp_trace_output = make_stream_handle();
    lisp_debug_io = make_stream_handle();
    lisp_query_io = make_stream_handle();
    my_assert(qvalue(nil) == nil);
    set_up_functions(0);
    set_up_variables(0);


    Lgc(nil);
    cout << "\nFirst GC over\n";
    Lgc(nil);
    cout << "\nSecond GC over\n";
    Lgc(nil);
    cout << "\nThird GC over\n";
// Probably broken now!
}

// end of testcode.cpp
