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
    LispObject r = nil;
// I am expecting that the list (9 8 7 6 5 4 3 2 1) will be preserved
// with the head element and the next having an ambiguous references to
// them but the other cells ending up copied. So (9 . ) and (8 . ) will
// be pinned and (7 6 5 4 3 2 1) will be copied...
    for (int i=0; i<10; i++)
        r = cons(fixnum_of_int(i), r);

    setvalue(nil, get_basic_vector_init(sizeof(Package), nil));
#ifdef COMMON
    setpackage(nil, qvalue(nil));    // For sake of restart code
    all_packages = ncons(qvalue(nil));
#else
    setpackage(nil, static_cast<LispObject>(qvalue(nil)));
#endif

    packhdr_(static_cast<LispObject>(CP)) = TYPE_STRUCTURE + (packhdr_
                                            (static_cast<LispObject>(CP)) & ~header_mask);
#ifdef COMMON
    packname_(static_cast<LispObject>(CP)) = make_string("LISP");
#endif
//
// The size chosen here is only an initial size - the hash table in a package
// can grow later on if needbe - but I ought to ensure that the initial
// size is big enough for the built-in symbols that Lisp creates in
// this restart code.  The size must be a power of 2. I want the object
// table to have the same number of entries regardless of whether I am on
// a 32 or 64-bit machine to make cross-loading of images possible.
//
    packint_(static_cast<LispObject>(CP)) = get_basic_vector_init(CELL*
                                            (1+INIT_OBVECI_SIZE), fixnum_of_int(0));
    packflags_(static_cast<LispObject>(CP)) = fixnum_of_int(
                ++package_bits);

#ifdef COMMON
//
// Common Lisp also has "external" symbols to allow for...
//
    packnint_(static_cast<LispObject>(CP)) = fixnum_of_int(0);
    packext_(static_cast<LispObject>(CP)) = get_basic_vector_init(CELL*
                                            (1+INIT_OBVECX_SIZE), fixnum_of_int(0));
    packnext_(static_cast<LispObject>(CP)) = fixnum_of_int(
                1); // Allow for nil
    {   size_t i = (size_t)(hash_lisp_string(qpname(nil)) &
                            (INIT_OBVECX_SIZE - 1));
        elt(packext_(static_cast<LispObject>(CP)), i) = nil;
    }
#else
    packnint_(static_cast<LispObject>(CP)) = fixnum_of_int(
                1); // Allow for nil
// Place NIL into the table.
    {   size_t i = (size_t)(hash_lisp_string(qpname(nil)) &
                            (INIT_OBVECI_SIZE - 1));
        elt(packint_(static_cast<LispObject>(CP)), i) = nil;
    }
#endif
    gensym_ser = 1;
    print_precision = 6; // I maybe prefer 15 but use 6 to agree with PSL
    current_modulus = 1;
// a fastget entry of 0 means no fastget stuff present, and so in the 6-bit
// field I have the values 1-63 are available.
//
    fastget_size = 63;
    package_bits = 0;
    modulus_is_large = 0;
    unset_var = nil;
//
// there had better not be a need for garbage collection here...
// ... or elsewhere in setup, since the world is not yet put together.
// Ditto interrupts.
//
#define boffo_size 256
    boffo = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+boffo_size);
// @@@O K here
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
    setpackage(nil,            lisp_package);
    setpackage(current_package,lisp_package);
//@@@ OK here


    B_reg = nil;                             // safe for GC
    unset_var                =
        make_undefined_global("~indefinite-value~");
    setvalue(unset_var,        unset_var);
//@@@@@@@@@@@@@@@@@@@    Lunintern(nil, unset_var);
//
// Now in some minor sense the world is in a self-consistent state
//
    lisp_true           = make_undefined_global("t");
    setvalue(lisp_true,   lisp_true);
    savedef             = make_undefined_symbol("*savedef");
    comma_symbol        = make_undefined_symbol("~comma");
    comma_at_symbol     = make_undefined_symbol("~comma-at");
    lambda              = make_undefined_symbol("lambda");
    funarg              = make_undefined_symbol("funarg");
    cfunarg             = make_undefined_symbol("cfunarg");
    opt_key             = make_undefined_symbol("&optional");
    rest_key            = make_undefined_symbol("&rest");
    key_key             = make_undefined_symbol("&key");
    allow_other_keys    = make_undefined_symbol("&allow-other-keys");
    aux_key             = make_undefined_symbol("&aux");
    work_symbol         =
        make_undefined_symbol("~magic-internal-symbol~");
    Lunintern(nil, work_symbol);
    package_symbol      = make_undefined_symbol("package");
    packid_(static_cast<LispObject>(CP))         = package_symbol;

    macroexpand_hook    = make_undefined_fluid("*macroexpand-hook*");
    evalhook            = make_undefined_fluid("*evalhook*");
    setvalue(evalhook,    nil);
    applyhook           = make_undefined_fluid("*applyhook*");
    setvalue(applyhook,  nil);
#ifdef COMMON
    keyword_package     = make_undefined_fluid("*keyword-package*");
    setvalue(keyword_package, make_package(make_string("KEYWORD")));
    err_table           = make_undefined_global("*ERROR-MESSAGE*");
#else
    err_table           = make_undefined_global("*error-messages*");
#endif
    setvalue(err_table,   nil);
#ifdef COMMON
#define make_keyword(name) \
        Lintern_2(nil, make_string(name), qvalue(keyword_package))
    internal_symbol     = make_keyword("INTERNAL");
    external_symbol     = make_keyword("EXTERNAL");
    inherited_symbol    = make_keyword("INHERITED");
    allow_key_key       = make_keyword("ALLOW-OTHER-KEYS");
#else
#define make_keyword(name) make_undefined_symbol(name)
#endif
    gensym_base         = make_string("G");
    expand_def_symbol   = make_undefined_symbol("expand-definer");
    format_symbol       = make_undefined_symbol("format");
    string_char_sym     = make_undefined_symbol("string-char");
// The following bunch of symbols relate to Common Lisp features and are
// not necessarily fully used.
    nicknames_symbol    = make_undefined_symbol(":nicknames");
    use_symbol          = make_undefined_symbol(":use");
    and_symbol          = make_undefined_symbol("and");
    or_symbol           = make_undefined_symbol("or");
    not_symbol          = make_undefined_symbol("not");
    reader_workspace    = make_undefined_symbol("#:x");
// @@ OK here
    named_character     = make_undefined_symbol(":named-character");
    read_float_format   =
        make_undefined_symbol("*read-default-float-format*");
    short_float         = make_undefined_symbol("short-float");
    single_float        = make_undefined_symbol("single-float");
    double_float        = make_undefined_symbol("double-float");
    long_float          = make_undefined_symbol("long-float");
    bit_symbol          = make_undefined_symbol("bit");
    pathname_symbol     = make_undefined_symbol("pathname");
    print_array_sym     = make_undefined_symbol("*print-array*");
    read_base           = make_undefined_symbol("*read-base*");
    initial_element     = make_undefined_symbol(":initial-element");
    make_constant("most-positive-fixnum", MOST_POSITIVE_FIXNUM);
    make_constant("most-negative-fixnum", MOST_NEGATIVE_FIXNUM);
    make_constant("pi",
                  make_boxfloat(3.141592653589793238, TYPE_DOUBLE_FLOAT));
    append_symbol       = make_undefined_symbol("append");
    raise_symbol        = make_undefined_fluid("*raise");
    lower_symbol        = make_undefined_fluid("*lower");
    echo_symbol         = make_undefined_fluid("*echo");
    comp_symbol         = make_undefined_fluid("*comp");
    compiler_symbol     = make_undefined_symbol("compile");
    current_function    = // system-startup
        startup_symbol      = make_undefined_symbol("system-startup");
    mv_call_symbol      = make_symbol("multiple-value-call", 0,
                                      bad_specialfn_0, mv_call_fn, bad_specialfn_2, bad_specialfn_3,
                                      bad_specialfn_4up);
    autoload_symbol     = make_undefined_symbol("autoload");
    bytecoded_symbol    = make_undefined_symbol("bytecoded-definition");
    traceprint_symbol   = make_undefined_symbol("trace-print");
    load_source_symbol  = make_symbol("load-source", 0, Lload_source0,
                                      Lload_source, G2Wother, G3Wother, G4Wother);
    load_selected_source_symbol =
        make_symbol("load-selected-source", 0, Lload_selected_source0,
                    Lload_selected_source, G2Wother, G3Wother, G4Wother);
    prinl_symbol        = make_symbol("prinl", 0, G0W1, Lprin, G2W1, G3W1,
                                      G4W1);
    emsg_star           = make_undefined_global("emsg*");
    redef_msg           = make_undefined_fluid("*redefmsg");
    expr_symbol         = make_undefined_symbol("expr");
    fexpr_symbol        = make_undefined_symbol("fexpr");
    macro_symbol        = make_undefined_symbol("macro");
    break_function      = make_undefined_fluid("*break-loop*");
    gchook              = make_undefined_fluid("*gc-hook*");
    resources           = make_undefined_fluid("*resources*");
    used_space          = make_undefined_fluid("*used-space*");
    avail_space         = make_undefined_fluid("*avail-space*");
    gcknt_symbol        = make_variable("gcknt*", fixnum_of_int(0));
// Note that end-of-file is represented by an odd Unicode value (in UTF-8)
    eof_symbol          = make_undefined_symbol("\xf4\x8f\xbf\xbf");
    call_stack          = nil;
    trap_time           = make_undefined_symbol("trap-time*");
//  count_high          = make_undefined_symbol("count-high*");
    setvalue(break_function, nil);
    setvalue(gchook, nil);
    setvalue(trap_time, nil);
    setvalue(resources, nil);
    setvalue(used_space, fixnum_of_int(0));
    setvalue(avail_space, fixnum_of_int(0));
    {   LispObject common = make_undefined_fluid("common-lisp-mode");
#ifdef COMMON
        setvalue(common, lisp_true);
        setvalue(raise_symbol, lisp_true);
        setvalue(lower_symbol, nil);
#else
        setvalue(common, nil);
        setvalue(raise_symbol, nil);
        setvalue(lower_symbol, lisp_true);
#endif
    }
    setvalue(echo_symbol,      nil);
    setvalue(comp_symbol,      nil);
    setvalue(emsg_star,        nil);
    setvalue(redef_msg,        lisp_true);

    sys_hash_table = Lmkhash_1(nil, fixnum_of_int(2));    // EQUAL
    sxhash_hash_table = Lmkhash_1(nil, fixnum_of_int(0)); // EQ
    get_counts = Lmkhash_1(nil, fixnum_of_int(0));        // EQ
//
// I make the vector that can hold the names used for "fast" get tags big
// enough for the largest possible number.
//
    fastget_names = get_basic_vector_init((MAX_FASTGET_SIZE+2)*CELL,
                                          SPID_NOPROP);
//
// The next bit is a horrid fudge, used in read.c (function orderp) to
// support REDUCE. It ensures that the flag 'noncom is subject to an
// optimisation for flag/flagp that allows it to be tested for using a
// simple bit-test.  This MUST use entry zero (coded as 1 here!).
// Also I insist that 'lose be the second fastget thing!
//
    {   LispObject nc = make_undefined_symbol("noncom");
        setheader(nc, qheader(nc) | (1L << SYM_FASTGET_SHIFT));
        elt(fastget_names, 0) = nc;
        nc = make_undefined_symbol("lose");
        setheader(nc, qheader(nc) | (2L << SYM_FASTGET_SHIFT));
        elt(fastget_names, 1) = nc;
    }
//
// I create the stream objects just once at cold-start time, but every time I
// restart I will fill in their components in the standard way again.
//
    lisp_work_stream = make_stream_handle();
    lisp_terminal_io = make_stream_handle();
    lisp_standard_output = make_stream_handle();
    lisp_standard_input = make_stream_handle();
    lisp_error_output = make_stream_handle();
    lisp_trace_output = make_stream_handle();
    lisp_debug_io = make_stream_handle();
    lisp_query_io = make_stream_handle();
    set_up_functions(0);
    set_up_variables(0);
    procstack = nil;
    procmem = get_basic_vector_init(CELL*100, nil); // 0 to 99
    procstackp = 0;


/*##*/    Lgc0(nil);
/*##*/    simple_print(r);
/*##*/    std::printf("\n");
/*##*/    std::printf("Now exit ...\n");
/*##*/ //   Lstop0(nil);
}

// end of testcode.cpp
