// restart.cpp                             Copyright (C) 1989-2022 Codemist

//
// Code needed to start off Lisp when no initial heap image is available,
// or to re-instate links between heap and C-coded core if there IS a
// heap loaded.  This code is run in a state that is in effect (in-package
// "lisp").
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

#ifdef WIN32
#include <windows.h>
#else
#ifndef EMBEDDED
#include <dlfcn.h>
#endif
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <sys/stat.h>
#include <sys/types.h>

#include "md5.h"

extern int showmathInitialised;

#ifndef S_IRUSR
#ifdef __S_IRUSR
#define S_IRUSR __S_IRUSR
#endif
#endif

#ifndef S_IWUSR
#ifdef __S_IWUSR
#define S_IWUSR __S_IWUSR
#endif
#endif

#ifndef S_IXUSR
#ifdef __S_IXUSR
#define S_IXUSR __S_IXUSR
#endif
#endif

DEFINE_THREAD_LOCAL(uintptr_t, genuineThreadId);

LispObject nil;
#ifdef NO_THREADS
LispObject* stack;
uintptr_t   stackBase;
uintptr_t   stackFringe;
uintptr_t   stackLimit = 0;
uintptr_t   C_stackBase;
uintptr_t   C_stackFringe;
uintptr_t   C_stackLimit;
#else // NO_THREADS
LispObject* stacks[maxThreads];
uintptr_t   stackBases[maxThreads];
uintptr_t   stackFringes[maxThreads];
uintptr_t   stackLimits[maxThreads];
uintptr_t   C_stackBases[maxThreads];
Bintptr_t   C_stackFringes[maxThreads];
uintptr_t   C_stackLimits[maxThreads];
#endif // NO_THREADS

LispObject* nilsegment;
LispObject* stacksegment;
int32_t stack_segsize = 1;

char* exit_charvec = nullptr;
intptr_t exit_reason;

intptr_t nwork;
unsigned int exit_count;
uint64_t gensym_ser;
intptr_t print_precision, miscflags;
intptr_t current_modulus, fastget_size, package_bits, modulus_is_large;
LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
LispObject quote_symbol, function_symbol, comma_symbol, comma_at_symbol;
LispObject cons_symbol, eval_symbol, apply_symbol, work_symbol, evalhook;
LispObject list_symbol, liststar_symbol, eq_symbol, eql_symbol;
LispObject cl_equal_symbol, equal_symbol, equalp_symbol;
LispObject go_symbol, cond_symbol, char_0_symbol;
LispObject applyhook, macroexpand_hook, append_symbol, exit_tag;
LispObject exit_value, catch_tags, keyword_package, current_package;
LispObject startfn, all_packages, package_symbol, internal_symbol;
LispObject gcknt_symbol, external_symbol, inherited_symbol;
LispObject gensym_base, string_char_sym, boffo;
LispObject key_key, allow_other_keys, aux_key;
LispObject err_table, format_symbol, progn_symbol, expand_def_symbol;
LispObject allow_key_key, declare_symbol, special_symbol, large_modulus;
LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol, echo_symbol;
LispObject codevec, litvec, supervisor, B_reg;
LispObject savedef_symbol, savedefs_symbol, lose_symbol, comp_symbol;
LispObject compiler_symbol, faslvec, tracedfn, lisp_terminal_io;
LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
LispObject prompt_thing, faslgensyms, prinl_symbol, emsg_star, redef_msg;
LispObject current_function, expr_symbol, fexpr_symbol, macro_symbol;
LispObject big_divisor, big_dividend, big_quotient, big_fake1, big_fake2;
LispObject active_stream, current_module, autoload_symbol, features_symbol;
LispObject lisp_package, sys_hash_table, rehash_vec1, rehash_vec2;
LispObject help_index, cfunarg, lex_words, get_counts, fastget_names;
LispObject input_libraries, output_library, current_file, break_function;
LispObject standard_output, standard_input, debug_io, error_output;
LispObject query_io, terminal_io, trace_output, fasl_stream, startup_symbol;
LispObject mv_call_symbol, traceprint_symbol, load_source_symbol;
LispObject load_selected_source_symbol, bytecoded_symbol, funcall_symbol;
LispObject gchook, resources, callstack, procstack, procmem, trap_time;
LispObject used_space, avail_space, eof_symbol, call_stack;
LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol, not_symbol;
LispObject reader_workspace, named_character, read_float_format, short_float;
LispObject single_float, double_float, long_float, bit_symbol;
LispObject pathname_symbol, print_array_sym, read_base;
LispObject initial_element, builtin0_symbol, builtin1_symbol;
LispObject builtin2_symbol, builtin3_symbol, builtin4_symbol;

LispObject workbase[51];

LispObject user_base_0, user_base_1, user_base_2, user_base_3, user_base_4;
LispObject user_base_5, user_base_6, user_base_7, user_base_8, user_base_9;

LispObject eq_hash_tables;

char program_name[64] = {0};

// The tables here are slightly oddly formatted. Every other entry is
// nullptr (reserved for other uses...) and each string has a single character
// stuck on its front that is also used as a marker elsewhere...

char** loadable_packages = nullptr;
char** switches = nullptr;

bool trap_floating_overflow = false;

int procstackp;

entry_point0 entries_table0[] =
{   {0,                                 "illegal"},
    {undefined_0,                       "undefined_0"},
    {autoload_0,                        "autoload_0"},
    {interpreted_0,                     "interpreted_0"},
    {funarged_0,                        "funarged_0"},
    {bytecoded_0,                       "bytecoded_0"},
    {byteopt_0,                         "byteopt_0"},
    {hardopt_0,                         "hardopt_0"},
    {byteoptrest_0,                     "byteoptrest_0"},
    {hardoptrest_0,                     "hardoptrest_0"},
    {G0W1,                              "G0W1"},
    {G0W2,                              "G0W2"},
    {G0W3,                              "G0W3"},
    {G0W4up,                            "G0W4up"},
    {G0Wother,                          "G0Wother"},
    {f0_as_0,                           "0->0"},
    {nullptr,                           "dummy"}
};

#define entry_table_size0 ((int)(sizeof(entries_table0)/sizeof(entries_table0[0])))

entry_point1 entries_table1[] =
{
// All values that can go in the function cells of symbols to stand for
// special interpreter activity are kept here. In most cases where there
// is an entrypoint there is a corresponding one that behaves just the
// same except that it has tracing enabled.
    {0,                                 "illegal"},
// A few special forms that are set up manually so slip through the normal
// scheme...
    {quote_fn,                          "quote"},
    {progn_fn,                          "progn"},
    {declare_fn,                        "declare"},
    {function_fn,                       "function"},
    {undefined_1,                       "undefined_1"},
    {autoload_1,                        "autoload_1"},
    {interpreted_1,                     "interpreted_1"},
    {funarged_1,                        "funarged_1"},
    {bytecoded_1,                       "bytecoded_1"},
    {byteopt_1,                         "byteopt_1"},
    {hardopt_1,                         "hardopt_1"},
    {byteoptrest_1,                     "byteoptrest_1"},
    {hardoptrest_1,                     "hardoptrest_1"},
    {G1W0,                              "G1W0"},
    {G1W2,                              "G1W2"},
    {G1W3,                              "G1W3"},
    {G1W4up,                            "G1W4up"},
    {G1Wother,                          "G1Wother"},
// The batch here relate to function re-work that discards unwanted
// extra arguments.
    {f1_as_0,                           "1->0"},
    {f1_as_1,                           "1->1"},
    {nullptr,                           "dummy"}
};

#define entry_table_size1 ((int)(sizeof(entries_table1)/sizeof(entries_table1[0])))

entry_point2 entries_table2[] =
{   {0,                                 "illegal"},
// A few special forms that are set up manually so slip through the normal
// scheme...
    {(two_args*)quote_fn,               "quote"},
    {(two_args*)progn_fn,               "progn"},
    {(two_args*)declare_fn,             "declare"},
    {(two_args*)function_fn,            "function"},
    {undefined_2,                       "undefined_2"},
    {G2W0,                              "G2W0"},
    {G2W1,                              "G2W1"},
    {G2W3,                              "G2W3"},
    {G2W4up,                            "G2W4up"},
    {G2Wother,                          "G2Wother"},
    {autoload_2,                        "autoload_2"},
    {interpreted_2,                     "interpreted_2"},
    {funarged_2,                        "funarged_2"},
    {bytecoded_2,                       "bytecoded_2"},
    {byteopt_2,                         "byteopt_2"},
    {hardopt_2,                         "hardopt_2"},
    {byteoptrest_2,                     "byteoptrest_2"},
    {hardoptrest_2,                     "hardoptrest_2"},
// The batch here relate to function re-work that discards unwanted
// extra arguments.
    {f2_as_0,                           "2->0"},
    {f2_as_1,                           "2->1"},
    {f2_as_2,                           "2->2"},
    {nullptr,                           "dummy"}
};

#define entry_table_size2 ((int)(sizeof(entries_table2)/sizeof(entries_table2[0])))

entry_point3 entries_table3[] =
{   {0,                                 "illegal"},
    {undefined_3,                       "undefined_3"},
    {autoload_3,                        "autoload_3"},
    {interpreted_3,                     "interpreted_3"},
    {funarged_3,                        "funarged_3"},
    {bytecoded_3,                       "bytecoded_3"},
    {byteopt_3,                         "byteopt_3"},
    {hardopt_3,                         "hardopt_3"},
    {byteoptrest_3,                     "byteoptrest_3"},
    {hardoptrest_3,                     "hardoptrest_3"},
    {G3W0,                              "G3W0"},
    {G3W1,                              "G3W1"},
    {G3W2,                              "G3W2"},
    {G3W4up,                            "G3W4up"},
    {G3Wother,                          "G3Wother"},
    {f3_as_0,                           "3->0"},
    {f3_as_1,                           "3->1"},
    {f3_as_2,                           "3->2"},
    {f3_as_3,                           "3->3"},
    {nullptr,                           "dummy"}
};

#define entry_table_size3 ((int)(sizeof(entries_table3)/sizeof(entries_table3[0])))

entry_point4up entries_table4up[] =
{   {0,                                 "illegal"},
    {undefined_4up,                     "undefined_4up"},
    {autoload_4up,                      "autoload_4up"},
    {interpreted_4up,                   "interpreted_4up"},
    {funarged_4up,                      "funarged_4up"},
    {bytecoded_4up,                     "bytecoded_4up"},
    {byteopt_4up,                       "byteopt_4up"},
    {hardopt_4up,                       "hardopt_4up"},
    {byteoptrest_4up,                   "byteoptrest_4up"},
    {hardoptrest_4up,                   "hardoptrest_4up"},
    {G4W0,                              "G4W0"},
    {G4W1,                              "G4W1"},
    {G4W2,                              "G4W2"},
    {G4W3,                              "G4W3"},
    {G4Wother,                          "G4Wother"},
    {nullptr,                           "dummy"}
};

#define entry_table_size4up ((int)(sizeof(entries_table4up)/sizeof(entries_table4up[0])))

entry_point1 entries_tableio[] =
{   {0,                                 "illegal"},
    {(one_arg* )char_from_illegal,      "char_from_illegal"},
    {(one_arg* )char_to_illegal,        "char_to_illegal"},
    {(one_arg* )read_action_illegal,    "read_action_illegal"},
    {(one_arg* )write_action_illegal,   "write_action_illegal"},
    {(one_arg* )char_from_terminal,     "char_from_terminal"},
    {(one_arg* )char_to_terminal,       "char_to_terminal"},
    {(one_arg* )read_action_terminal,   "read_action_terminal"},
    {(one_arg* )write_action_terminal,  "write_action_terminal"},
    {(one_arg* )char_from_file,         "char_from_file"},
    {(one_arg* )char_to_file,           "char_to_file"},
    {(one_arg* )read_action_file,       "read_action_file"},
    {(one_arg* )read_action_output_file,"read_action_output_file"},
    {(one_arg* )write_action_file,      "write_action_file"},
    {(one_arg* )binary_outchar,         "binary_outchar"},
    {(one_arg* )char_from_list,         "char_from_list"},
    {(one_arg* )char_to_list,           "char_to_list"},
    {(one_arg* )code_to_list,           "code_to_list"},
    {(one_arg* )read_action_list,       "read_action_list"},
    {(one_arg* )write_action_list,      "write_action_list"},
    {(one_arg* )count_character,        "count_character"},
    {(one_arg* )char_to_pipeout,        "char_to_pipeout"},
    {(one_arg* )write_action_pipe,      "write_action_pipe"},
    {(one_arg* )char_from_synonym,      "char_from_synonym"},
    {(one_arg* )char_to_synonym,        "char_to_synonym"},
    {(one_arg* )read_action_synonym,    "read_action_synonym"},
    {(one_arg* )write_action_synonym,   "write_action_synonym"},
    {(one_arg* )char_from_concatenated, "char_from_concatenated"},
    {(one_arg* )char_to_broadcast,      "char_to_broadcast"},
    {(one_arg* )read_action_concatenated,"read_action_concatenated"},
    {(one_arg* )write_action_broadcast, "write_action_broadcast"},
    {(one_arg* )char_from_echo,         "char_from_echo"},
    {nullptr,                           "dummy"}
};

#define entry_table_sizeio ((int)(sizeof(entries_tableio)/sizeof(entries_tableio[0])))

static LispObject Lreclaim_trap(LispObject env, LispObject a)
{   int64_t previous = reclaim_trap_count;
    if (!is_fixnum(a)) return aerror1("reclaim-trap", a);
    reclaim_trap_count = int_of_fixnum(a);
    term_printf("+++ Reclaim trap set at %d, previous = %d\n",
                reclaim_trap_count, previous);
    return onevalue(fixnum_of_int(previous));
}

static LispObject Lreclaim_stack_limit(LispObject env, LispObject a)
{   intptr_t previous = reclaim_stack_limit;
    if (!is_fixnum(a)) return aerror1("reclaim-stack-limit", a);
    reclaim_stack_limit = int_of_fixnum(a);
    term_printf("+++ Reclaim stack limit set at %d, previous = %d\n",
                reclaim_stack_limit, previous);
    return onevalue(fixnum_of_int(previous));
}

static const char* find_checksum(const char* name, size_t len,
                                 const setup_type* p)
{   const char* n;
    while (p->name != nullptr) p++;
    n = reinterpret_cast<const char*>(p->zero);
    if (std::strlen(n) == len && std::memcmp(name, n, len) == 0)
        return reinterpret_cast<const char*>(p->one);
    else return nullptr;
}

setup_type const* setup_tables[] =
{   u01_setup, u02_setup, u03_setup, u04_setup,
    u05_setup, u06_setup, u07_setup, u08_setup, u09_setup,
    u10_setup, u11_setup, u12_setup, u13_setup, u14_setup,
    u15_setup, u16_setup, u17_setup, u18_setup, u19_setup,
    u20_setup, u21_setup, u22_setup, u23_setup, u24_setup,
    u25_setup, u26_setup, u27_setup, u28_setup, u29_setup,
    u30_setup, u31_setup, u32_setup, u33_setup, u34_setup,
    u35_setup, u36_setup, u37_setup, u38_setup, u39_setup,
    u40_setup, u41_setup, u42_setup, u43_setup, u44_setup,
    u45_setup, u46_setup, u47_setup, u48_setup, u49_setup,
    u50_setup, u51_setup, u52_setup, u53_setup, u54_setup,
    u55_setup, u56_setup, u57_setup, u58_setup, u59_setup,
    u60_setup,
// I also include the kernel setup tables, but I put a nullptr in this
// table so it is easy to see where they start.
    nullptr,
    arith06_setup, arith08_setup, arith10_setup, arith12_setup,
    arith13_setup, char_setup, eval1_setup, eval2_setup, eval3_setup,
    funcs1_setup, funcs2_setup, funcs3_setup, lisphash_setup,
    print_setup, read_setup, restart_setup, mpi_setup,
#ifdef ARITHLIB
    arith_setup,
#endif
    nullptr
};

// If C code is to be instated (via c!:install calls in u01.lsp etc) there
// needs to be a verification that the file u01.c and the file u01.lsp (etc)
// are in step. So once for each such file this does the check. It should
// only happen when the system is being built and ought not to be a big
// performance issue.

static LispObject Lcheck_c_code(LispObject env, LispObject name,
                                LispObject lc1, LispObject lc2, LispObject a4up)
{   int32_t c1=-1, c2=-1, c3=-1;
    long int x1=-2, x2=-2, x3=-2;
    int32_t len;
    const char* p;
    const char* sname;
    size_t i;
    LispObject lc3 = arg4("check-c-code", a4up);
// This is called as when the system is about to install some links between
// Lisp and code that has been compiled into C++. It is given 4 arguments:
//   (check-c-code name-of-module-of-C++-code
//       c1 c2 c3)     % 3 parts of a checksum
// It looks at the setup tables for all the modules it is aware of. For
// each such the final entry will be of the form
//    {nullptr, "module-name", "checksum info", ...}
// and it sees if the information from there matches what it is looking for.
    if (!is_vector(name) ||
        !is_string_header(vechdr(name)) ||
        !is_fixnum(lc1) ||
        !is_fixnum(lc2) ||
        !is_fixnum(lc3)) return aerror1("check-c-code", name);
    c1 = int_of_fixnum(lc1);
    c2 = int_of_fixnum(lc2);
    c3 = int_of_fixnum(lc3);
    sname = reinterpret_cast<const char*>(&celt(name, 0));
    len = length_of_byteheader(vechdr(name)) - CELL;

    p = nullptr;
    for (i=0; setup_tables[i]!=nullptr; i++)
    {   if ((p = find_checksum(sname, len,
                               setup_tables[i])) != nullptr) break;
    }
    if (p == nullptr) return aerror1("check-c-code", name);

    if (std::sscanf(p, "%ld %ld %ld", &x1, &x2, &x3) != 3)
        return aerror1("check-c-code", name);
    if (c1 == x1 && c2 == x2 && c3 == x3) return onevalue(nil);
    err_printf("\n+++++ C code and environment files not compatible\n");
    err_printf("please check, re-compile and try again\n");
    err_printf("versions from %.*s.c %lx %lx %lx\n", len, sname, x1, x2,
               x3);
    err_printf("version passed here %lx %lx %lx\n", c1, c2, c3);
    return aerror1("check-c-code", name);
}

setup_type const restart_setup[] =
// things that are in modules that do not define enough Lisp entrypoints
// to be worth giving separate entry-tables.
{   DEF_0("~load-spid",         Lload_spid),
    DEF_1("~is-spid",           Lis_spid),
    DEF_1("~spid-to-nil",       Lspid_to_nil),
    DEF_1("~mv-list",           Lmv_list),
    DEF_4up("check-c-code",     Lcheck_c_code),
    DEF_1("modulep",            Lmodule_exists),
    DEF_1("start-module",       Lstart_module),
    DEF_2("write-module",       Lwrite_module),
    DEF_1("copy-module",        Lcopy_module),
    DEF_1("delete-module",      Ldelete_module),
    DEF_1("load-module",        Lload_module),
    {"load-source",             Lload_source0, Lload_source, G2Wother, G3Wother, G4Wother},
    {"load-selected-source",    Lload_selected_source0, Lload_selected_source, G2Wother, G3Wother, G4Wother},
    DEF_0("list-modules",       Llist_modules),
    DEF_1("writable-libraryp",  Lwritable_libraryp),
    {"library-members",         Llibrary_members0, Llibrary_members, G2Wother, G3Wother, G4Wother},
    DEF_1("startup-banner",     Lbanner),
    DEF_2("set-help-file",      Lset_help_file),
    {"mapstore",                Lmapstore0, Lmapstore, G2Wother, G3Wother, G4Wother},
    DEF_1("verbos",             Lverbos),
    {"gc",                      Lgc, Lgc, G2Wother, G3Wother, G4Wother},
    {"reclaim",                 Lgc, Lgc, G2Wother, G3Wother, G4Wother},
    DEF_1("reclaim-trap",       Lreclaim_trap),
    DEF_1("reclaim-stack-limit",Lreclaim_stack_limit),
    {"resource-limit",          G0Wother, G1Wother, Lresource_limit_2, Lresource_limit_3, Lresource_limit_4up},
    {"errorset",                G0Wother, Lerrorset_1, Lerrorset_2, Lerrorset_3, G4Wother},
#ifdef CONSERVATIVE
    {"gctest",                  Lgctest_0, Lgctest_1, Lgctest_2, G3Wother, G4Wother},
#endif
    {nullptr,                   nullptr, nullptr, nullptr, nullptr, nullptr}
};


static void create_symbols(setup_type const s[], int restart_flag)
{   size_t i;
    for (i=0; s[i].name != nullptr; i++)
        make_symbol(s[i].name, restart_flag,
                    s[i].zero,  s[i].one, s[i].two, s[i].three, s[i].fourup);
}

static int32_t defined_symbols;

static void count_symbols(setup_type const s[])
{   size_t i;
    for (i=0; s[i].name != nullptr; i++) defined_symbols++;
}

static LispObject make_undefined_fluid(const char* name)
{   LispObject v = make_undefined_symbol(name);
    setheader(v, qheader(v) | SYM_SPECIAL_VAR);
    return v;
}

static LispObject make_undefined_global(const char* name)
{   LispObject v = make_undefined_symbol(name);
    setheader(v, qheader(v) | SYM_GLOBAL_VAR);
    return v;
}

LispObject make_constant(const char* name, LispObject value)
{   LispObject w = make_undefined_global(name);
    setvalue(w, value);
    return w;
}

LispObject make_variable(const char* name, LispObject value)
{   LispObject w = make_undefined_fluid(name);
    setvalue(w, value);
    return w;
}

static void cold_setup()
{   miscflags = 3;
    setplist(nil, nil);
    setfastgets(nil, nil);
    setenv(nil, nil);        // points to self in undefined case
    qfn0(nil) = undefined_0;
    qfn1(nil) = undefined_1;
    qfn2(nil) = undefined_2;
    qfn3(nil) = undefined_3;
    qfn4up(nil) = undefined_4up;
    setheader(nil, TAG_HDR_IMMED+TYPE_SYMBOL+SYM_GLOBAL_VAR);
    setvalue(nil, nil);
    qcountLow(nil) = 256;
    qcountHigh(nil) = 0;
// When I am debugging CSL I can validate the heap, for instance whenever
// I allocate vector. I am about to need to call make_string to create a
// record of the name "nil", and during that call the pname field of nil
// had better be valid - so I fill it in with a nil.
    setpname(nil, nil);
// Similarly the package field for nil needs a (temporary) safe value.
    setpackage(nil, nil);
    exit_reason = UNWIND_NULL;
// eq_hash_tables is not an ordinary list-base, si I need to clear it
// individually.
    eq_hash_tables = nil;
    for (LispObject** p=list_bases; *p!=nullptr; p++) **p = nil;
    eq_hash_tables = nil;
// The package I am using at present will always be a package object
// stored in the value cell of "current-package". But that symbol does not
// quite exist yet - so as a temporary provision I use the value cell of NIL.
// This has in fact been done as part of the general initialization of
// list-bases, but I repeat it here for extra clarity.
    current_package = nil;
// The code here is generally coded on the supposition that there will NEVER
// be a garbage collection here, so all issues of error recovery related
// tests can be omitted. That makes this code much cleaner! It means that
// during a cold start that there is enough space (well for a COLD start that
// hardly likely to be an issue!) and in a warm start that none of the
// calls that make strings or symbols etc here trigger a genuine garbage
// collection - that can probably be assured by ensuring that on restart there
// is at least a little bit of space in hand.
//
// Well garbage collection even at this early stage should now be valid when
// the conservative GC is active.
#ifdef CONSERVATIVE
    if (gcTest)
    {   gcTestCode();   // if "--gc-test" was on command line.
        std::exit(0);
    }
#endif // CONSERVATIVE
#ifdef DEBUG
    cout << "Create pname of NIL\n";
#endif
#ifdef COMMON
    setpname(nil, make_string("NIL"));
#else
    setpname(nil, make_string("nil"));
#endif
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
// The size chosen here is only an initial size - the hash table in a package
// can grow later on if needbe - but I ought to ensure that the initial
// size is big enough for the built-in symbols that Lisp creates in
// this restart code.  The size must be a power of 2. I want the object
// table to have the same number of entries regardless of whether I am on
// a 32 or 64-bit machine to make cross-loading of images possible.
    packint_(static_cast<LispObject>(CP)) =
        get_basic_vector_init(CELL*(1+INIT_OBVECI_SIZE), fixnum_of_int(0));
    packflags_(static_cast<LispObject>(CP)) = fixnum_of_int(++package_bits);
#ifdef COMMON
// Common Lisp also has "external" symbols to allow for...
    packnint_(static_cast<LispObject>(CP)) = fixnum_of_int(0);
    packext_(static_cast<LispObject>(CP)) =
        get_basic_vector_init(CELL*(1+INIT_OBVECX_SIZE), fixnum_of_int(0));
    packnext_(static_cast<LispObject>(CP)) = fixnum_of_int(1);
    {   size_t i = (size_t)(hash_lisp_string(qpname(nil)) &
                            (INIT_OBVECX_SIZE - 1));
        elt(packext_(static_cast<LispObject>(CP)), i) = nil;
    }
#else
    packnint_(static_cast<LispObject>(CP)) = fixnum_of_int(1);
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
    fastget_size = 63;
    package_bits = 0;
    modulus_is_large = 0;
    unset_var = nil;
// there had better not be a need for garbage collection here...
// ... or elsewhere in setup, since the world is not yet put together.
// Ditto interrupts.
#define boffo_size 256
    boffo = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+boffo_size);
    std::memset(reinterpret_cast<void*>(
        reinterpret_cast<char*>(boffo) + (CELL - TAG_VECTOR)),
        '@', boffo_size);
// The next line has hidden depths.  When it is obeyed during cold start
// the C variable *package* has the value nil (because I will not have
// got as far as creating the Lisp-style variable for it to refer to), hence
// make_symbol looks in the value cell of nil to find the package to intern
// wrt. Once this has been done I can put nil back how it ought to have been,
// and then I can create the Lisp symbol !*package!*" and put everything in a
// respectable state!
    symbol_sequence = 257;
    current_package          = make_undefined_fluid("*package*");
    lisp_package             = qpackage(nil);
    setvalue(current_package,  lisp_package);
    setvalue(nil,              nil);          // Whew!
    setpackage(nil,            lisp_package);
    setpackage(current_package,lisp_package);

    B_reg = nil;                             // safe for GC
    unset_var                =
        make_undefined_global("~indefinite-value~");
    setvalue(unset_var,        unset_var);
// I have not set up NIL, !*PACKAGE!* and !~INDEFINITE!-VALUE!~ with
// sequence number 256, 257 and 258. So now I set up 256 character symbols
// such that they each get the correct sequence number.
    symbol_sequence = 0;
    for (int i=0; i<256; i++)
    {   int len;
        if (i <= 0x7f)
        {   boffo_char(0) = i;
            boffo_char(1) = 0;
            len = 1;
        }
        else
        {   boffo_char(0) = 0xc0 | (i >> 6);    // utf-8
            boffo_char(1) = 0x80 | (i & 0x3f);
            boffo_char(2) = 0;
            len = 2;
        }
        LispObject v = iintern(boffo, len, CP, 0);
        if (i == 0) char_0_symbol = v;
    }
// It is at least imaginable that I should remove ~indefinite-value~ from the
// object list, but I view it as really improbable that anybody will have
// an accidental conflict with the name and for debugging it MAY be handy
// to be able to access it?
//@@@@@@@@@@@@@@@@@@@    Lunintern(nil, unset_var);
    symbol_sequence = 259;
// Now in some minor sense the world is in a self-consistent state
    lisp_true           = make_undefined_global("t");
    setvalue(lisp_true,   lisp_true);
    savedef_symbol      = make_undefined_symbol("*savedef");
    savedefs_symbol     = make_undefined_symbol("*savedefs");
    lose_symbol         = make_undefined_symbol("lose");
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

    rehash_vec1 = get_basic_vector_init(CELL*(1+REHASHVEC_SIZE), nil);
    rehash_vec2 = get_basic_vector_init(CELL*(1+REHASHVEC_SIZE), nil);
    sys_hash_table = Lmkhash_1(nil, fixnum_of_int(2));    // EQUAL
    get_counts = Lmkhash_1(nil, fixnum_of_int(0));        // EQ
// I make the vector that can hold the names used for "fast" get tags big
// enough for the largest possible number.
    fastget_names = get_basic_vector_init((MAX_FASTGET_SIZE+2)*CELL,
                                          SPID_NOPROP);
// The next bit is a horrid fudge, used in read.c (function orderp) to
// support REDUCE. It ensures that the flag 'noncom is subject to an
// optimisation for flag/flagp that allows it to be tested for using a
// simple bit-test.  This MUST use entry zero (coded as 1 here!).
// Also I insist that 'lose be the second fastget thing!
    {   LispObject nc = make_undefined_symbol("noncom");
        setheader(nc, qheader(nc) | (1L << SYM_FASTGET_SHIFT));
        elt(fastget_names, 0) = nc;
        nc = make_undefined_symbol("lose");
        setheader(nc, qheader(nc) | (2L << SYM_FASTGET_SHIFT));
        elt(fastget_names, 1) = nc;
    }
// I create the stream objects just once at cold-start time, but every time I
// restart I will fill in their components in the standard way again.
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
}

LispObject set_up_functions(int restart_flag)
{
// All symbols that have a pointer to C code in their function cell must
// be set up whether we are in a warm OR a cold start state, because the
// actual addresses associated with C entrypoints will vary from version
// to version of the binary of the system.
    size_t i;
#ifdef COMMON
// In Common Lisp mode it could be that the user had something other than the
// LISP package active when the image was saved. But I want all the symbols
// that I create or restore here to be in the LISP (or sometimes keyword)
// package. So I temporarily reset the package here...
    LispObject saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    function_symbol          = make_symbol("function", restart_flag,
                                           bad_specialfn_0, function_fn, bad_specialfn_2, bad_specialfn_3,
                                           bad_specialfn_4up);
    setheader(function_symbol,
              qheader(function_symbol) | SYM_SPECIAL_FORM);
    quote_symbol             = make_symbol("quote", restart_flag,
                                           bad_specialfn_0, quote_fn, bad_specialfn_2, bad_specialfn_3,
                                           bad_specialfn_4up);
    setheader(quote_symbol, qheader(quote_symbol) | SYM_SPECIAL_FORM);
    go_symbol                = make_symbol("go", restart_flag,
                                           bad_specialfn_0, go_fn, bad_specialfn_2, bad_specialfn_3,
                                           bad_specialfn_4up);
    setheader(go_symbol, qheader(go_symbol) | SYM_SPECIAL_FORM);
    cond_symbol              = make_symbol("cond", restart_flag,
                                           bad_specialfn_0, cond_fn, bad_specialfn_2, bad_specialfn_3,
                                           bad_specialfn_4up);
    setheader(cond_symbol, qheader(cond_symbol) | SYM_SPECIAL_FORM);
    progn_symbol             = make_symbol("progn", restart_flag,
                                           bad_specialfn_0, progn_fn, bad_specialfn_2, bad_specialfn_3,
                                           bad_specialfn_4up);
    setheader(progn_symbol, qheader(progn_symbol) | SYM_SPECIAL_FORM);
    declare_symbol           = make_symbol("declare", restart_flag,
                                           bad_specialfn_0, declare_fn, bad_specialfn_2, bad_specialfn_3,
                                           bad_specialfn_4up);
    setheader(declare_symbol, qheader(declare_symbol) | SYM_SPECIAL_FORM);
    special_symbol           = make_undefined_symbol("special");
    large_modulus            = fixnum_of_int(1);
    cons_symbol              = make_symbol("cons", restart_flag, G0W1,
                                           G1W2, Lcons, G3W2, G4W2);
    list_symbol              = make_symbol("list", restart_flag, Lnilfn,
                                           Lncons, Llist_2, Llist_3, Llist_4up);
    liststar_symbol          = make_symbol("list*", restart_flag,
                                           G0Wother, Lidentity, Lcons, Llist_2star, Lliststar_4up);
    eq_symbol                = make_undefined_symbol("eq");
    eql_symbol               = make_undefined_symbol("eql");
    cl_equal_symbol          = make_undefined_symbol("cl-equal");
    equal_symbol             = make_undefined_symbol("equal");
    equalp_symbol            = make_undefined_symbol("equalp");
    eval_symbol              = make_symbol("eval", restart_flag, G0W1,
                                           Leval, G2W1, G3W1, G4W1);
    apply_symbol             = make_symbol("apply", restart_flag,
                                           G0Wother, Lapply_1, Lapply_2, Lapply_3, Lapply_4up);
    load_source_symbol       = make_symbol("load-source", restart_flag,
                                           Lload_source0, Lload_source, G2Wother, G3Wother, G4Wother);
    builtin0_symbol          = make_undefined_symbol("s:builtin0");
    builtin1_symbol          = make_undefined_symbol("s:builtin1");
    builtin2_symbol          = make_undefined_symbol("s:builtin2");
    builtin3_symbol          = make_undefined_symbol("s:builtin3");
    builtin4_symbol          = make_undefined_symbol("s:builtin4");
    load_selected_source_symbol =
        make_symbol("load-selected-source",
                    restart_flag, Lload_selected_source0,
                    Lload_selected_source, G2Wother, G3Wother,
                    G4Wother);
// The main bunch of symbols can be handed using a table that
// gives names and values.
    for (i=0; eval2_setup[i].name != nullptr; i++)
    {   LispObject v = make_symbol(eval2_setup[i].name,
                                   restart_flag,
                                   eval2_setup[i].zero,
                                   eval2_setup[i].one,
                                   eval2_setup[i].two,
                                   eval2_setup[i].three,
                                   eval2_setup[i].fourup);
        setheader(v, qheader(v) | SYM_SPECIAL_FORM);
    }
    for (i=0; eval3_setup[i].name != nullptr; i++)
    {   LispObject v = make_symbol(eval3_setup[i].name,
                                   restart_flag,
                                   eval3_setup[i].zero,
                                   eval3_setup[i].one,
                                   eval3_setup[i].two,
                                   eval3_setup[1].three,
                                   eval3_setup[i].fourup);
        setheader(v, qheader(v) | SYM_SPECIAL_FORM);
    }
    create_symbols(arith06_setup, restart_flag);
    create_symbols(arith08_setup, restart_flag);
    create_symbols(arith10_setup, restart_flag);
    create_symbols(arith12_setup, restart_flag);
    create_symbols(arith13_setup, restart_flag);
    create_symbols(char_setup, restart_flag);
    create_symbols(eval1_setup, restart_flag);
    create_symbols(funcs1_setup, restart_flag);
    create_symbols(funcs2_setup, restart_flag);
    create_symbols(funcs3_setup, restart_flag);
    create_symbols(lisphash_setup, restart_flag);
    create_symbols(print_setup, restart_flag);
    create_symbols(read_setup, restart_flag);
    create_symbols(restart_setup, restart_flag);
    create_symbols(mpi_setup, restart_flag);
#ifdef ARITHLIB
    create_symbols(arith_setup, restart_flag);
#endif
// Although almost everything is mapped into upper case in a Common Lisp
// world, I will preserve the case of symbols defined in u01 to u60.
    for (i=0; setup_tables[i]!=nullptr; i++)
        create_symbols(setup_tables[i], restart_flag | 2);

#ifdef NAG
    create_symbols(asp_setup, restart_flag);
    create_symbols(nag_setup, restart_flag);
    create_symbols(socket_setup, restart_flag);
    create_symbols(xdr_setup, restart_flag);
    create_symbols(grep_setup, restart_flag);
    create_symbols(axfns_setup, restart_flag);
    create_symbols(gr_setup, restart_flag);
#endif

#ifdef OPENMATH
    create_symbols(om_setup, restart_flag);
    create_symbols(om_parse_setup, restart_flag);
#endif

#ifdef COMMON
    CP = saved_package;
#endif
    return nil;
}

static int alpha1(const void* a, const void* b)
{   return std::strcmp(1+*(const char**)a, 1+*(const char**)b);
}

// This sets up:
//   lispsystem!*
//   The standard input and output streams
//   information about the command line arguments in lispargs!*
//   floating point limit constants (which ought in fact to be the
//       same on all platforms if I am using IEEE arithmetic...)
//   input!-libraries and output!-library

LispObject set_up_variables(int restart_flag)
{   LispObject w, w1;
    size_t i;
// There are a number of system variables that are not saved in
// image files and so that have to be set up manually in every case.
#ifdef COMMON
    LispObject saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    charvec = get_basic_vector_init(257*CELL, nil);
    for (int i=0; i<256; i++)
    {   char buffer[4];
// There is a special fudge in make_symbol so that "\00" gets treated
// as a string of length 1.
        if (i <= 0x7f)
        {   buffer[0] = i;
            buffer[1] = 0;
        }
        else
        {   buffer[0] = 0xc0 | (i>>6);
            buffer[1] = 0x80 | (i & 0x3f);
            buffer[2] = 0;
        }
        basic_elt(charvec, i) = make_undefined_symbol(buffer);
    }
    faslvec = nil;
    faslgensyms = nil;
    multiplication_buffer = nil;
// big_fake1 and big_fake2 represent a witty issue - when a bignum is
// serilized and it uses only one or two words its value gets written
// as a 64-bit numeric value. When it is re-loaded that value is packed
// as a number - either a fixnum or a bignum as relevant. So the FAKE
// nature of big_fake1 and big_fake2 will lead to the ser8ialization process
// reloading fixnums when using a 64-bit machine. Thus defeating the whole
// point of them!
    big_fake1 = make_one_word_bignum(0);
    big_fake2 = make_two_word_bignum(0, 0);
// It makes sense to reset big_divisor and big_dividend on reloading a heap
// image so that any very large allocation from the previous run is discarded.
    big_divisor = make_four_word_bignum(0, 0, 0, 0);
    big_dividend = make_four_word_bignum(0, 0, 0, 0);
    big_quotient = make_four_word_bignum(0, 0, 0, 0);
    setvalue(macroexpand_hook,
        funcall_symbol =
            make_symbol("funcall", restart_flag, G0Wother, Lfuncall_1,
                        Lfuncall_2, Lfuncall_3, Lfuncall_4up));
    input_libraries = make_undefined_symbol("input-libraries");
    setheader(input_libraries,
              qheader(input_libraries) | SYM_SPECIAL_VAR);
    setvalue(input_libraries, nil);
    for (i=fasl_files.size(); i!=0; i--)
        if (fasl_files[i-1].inUse)
            setvalue(input_libraries,
                     cons(SPID_LIBRARY + (((int32_t)(i-1))<<20),
                          qvalue(input_libraries)));
    output_library = make_undefined_symbol("output-library");
    setvalue(output_library, (output_directory & 0x80000000u) != 0 ? nil :
             SPID_LIBRARY + (((int32_t)(output_directory&0x3ff))<<20));
// The Lisp variable lispsystem* gets set here. (in Common mode it is
// the variable *features*)
// Its value is a list.
//       csl                      says I am a CSL Lisp
//       (executable . "string")  name of current executable (if available)
//       (shortname . "string")   executable wuithout path or extension
//       pipes                    do I support open-pipe?
//       parallel                 "parallel" function supported
//       (revision . number)      eg 4020. The most recent subversion checkin.
//       (name . "string")        eg "MSDOS/386"
//       (opsys . id)             unix/msdos/riscos/win32/finder/riscos/...
//       id                       unix/msdos etc again...
//       help                     help mechanism provided within Lisp
//       debug                    Lisp built with debug options
//       embedded                 if built using the EMBEDDED option
//       (c-code . number)        u01.c through u60.c define n functions
//       sixty-four               64-bit address version
//       texmacs                  "--texmacs" option on command line
//       parallel                 the "parallel" experimental function exists
//
// In Common mode the tags on the *features* list are generally in the
// keyword package. Otherwise they are just regular symbols. This makes it
// slightly hard to use code that tests this list in a generic environment!

    /*!!! csl
     */

    /*!! lispsys [03] \section{Items that can appear in {\ttfamily lispsystem!*}} \label{lispsys}
     *
     * There is a global variable called {\ttfamily lispsystem!*} whose value is
     * reset in the process of CSL starting up. An effect of this is that if the
     * user changes its value those changes do not survice a preserving and
     * re-loading a heap image: this is deliberate since the heap image may be
     * re-loaded on a different instance of CSL possibly on a quite different
     * computer of with a different configuration. The value of {\ttfamily
     * lispsystem!*} is a list of items, where each item is either an atomic tag
     * of a pair whose first component is a key. In general it would be unwise
     * to rely on exactly what information is present without review of the code
     * that sets it up. The information may be of interest to anybody but some tags
     * and keys are reflections of experiments rather than fully stable facilities.
     * \begin{description}
     */

    /*! lispsys [~~~~~~~~] \end{description} % end of lispsystem* section [restart.c]
     */

    {
#ifdef COMMON
        LispObject n = features_symbol;
        char opsys[32];
        char* p1 = opsys,* p2 = OPSYS;
        int ii;
        while ((*p1++ = std::toupper(*p2++)) != 0);
        *p1 = 0;
        /*! lispsys [opsys] \item [{\itshape operating system identity}] \index{{\ttfamily operating system identity}}
         * The name of the current operating system is put on the list. Exactly what
         * form is not explicitly defined!
         */
        w = cons(make_keyword(opsys), nil);
#if defined WIN64 || defined __WIN64__ || defined WIN32
        w = cons(make_keyword("WIN32"), w);
#endif
#if defined WIN64 || defined __WIN64__
        w = cons(make_keyword("WIN64"), w);
#endif
#if defined MACINTOSH
        w = cons(make_keyword("MAC"), w);
        w = cons(make_keyword("UNIX"), w);
#else
#if defined UNIX
        if (std::strcmp(opsys, "UNIX") != 0 &&
            std::strcmp(opsys, "unix") != 0)
            w = cons(make_keyword("UNIX"), w);
#endif
#endif
        /*! lispsys [win32] \item[{\ttfamily win32}, {\ttfamily win64}] \index{{\ttfamily win32}, {\ttfamily win64}}
         * Any windows system puts {\ttfamily win32} in {\ttfamily lispsystem!*}.
         * If 64-bit windows is is use then {\ttfamily win64} is also included
         */
#else
        LispObject n = make_undefined_symbol("lispsystem*");
        /*! lispsys [c-code] \item[{\ttfamily (c!-code . count)}] \index{{\ttfamily (c"!-code . count)}}
         * This will be present if code has been optimised into C through the source
         * files u01.c to u60.c, and in that case the value tells you how many functions
         * have been optimised in this manner.
         *
         */

        /*! lispsys [common-lisp] \item[{\ttfamily  common!-lisp}] \index{{\ttfamily  common"!-lisp}}
         * For a project some while ago a limited Common Lisp compatibility mode was
         * being developed, and this tag indicated that it was active. In that case all
         * entries are in upper case and the variable is called {\ttfamily *FEATURES*}
         * rather than {\ttfamily lispsystem!*}. But note that this Lisp has never even
         * aspired to be a full Common Lisp, since its author considers Common Lisp to
         * have been a sad mistake that must bear significant responsibility for the
         * fact that interest in Lisp has faded dramatically since its introduction.
         *
         */
        /*! lispsys [csl] \item[{\ttfamily csl}] \index{{\ttfamily csl}}
         * A simple tag intended to indicate that this Lisp system is CSL and not any
         * other. This can of course only work properly if all other Lisp systems
         * agree not to set this tag! In the context of Reduce I note that the PSL
         * Lisp system sets a tag {\ttfamily psl} on {\ttfamily lispsystem!*} and
         * the realistic use of this is to discriminate between CSL and PSL hosted
         * copies of Reduce.
         */

        /*! lispsys [debug] \item[{\ttfamily debug}] \index{{\ttfamily debug}}
         * If CSL was compiled with debugging options this is present, and one can imagine
         * various bits of code being more cautious or more verbose if it is detected.
         */

        /*! lispsys [executable] \item[{\ttfamily  (executable . name)}] \index{{\ttfamily  (executable . name)}}
         * The value is the fully rooted name of the executable file that was launched.
         */

        /*! lispsys [fox] \item[{\ttfamily fox}] \index{{\ttfamily fox}}
         * Used to be present if the FOX GUI toolkit was detected and incorporated as
         * part of CSL, but now probably never used!
         */

        /*! lispsys [name] \item[{\ttfamily  (name . name)}] \index{{\ttfamily  (name . name)}}
         * Some indication of the platform. For instance on one system I use it
         * is {\ttfamily linux-gnu:x86\_64} and on anther it is just {\ttfamily win32}.
         */

        /*! lispsys [opsys] \item[{\ttfamily  (opsys . operating-system)}] \index{{\ttfamily  (opsys . operating-system)}}
         * Some crude indication of the host operating system.
         */

        /*! lispsys [pipes] \item[{\ttfamily pipes}] \index{{\ttfamily pipes}}
         * In the earlier days of CSL there were computers where pipes were not
         * supported, so this tag notes when they are present and hance the facility
         * to create sub-tasks through them can be used.
         */

        /*! lispsys [record_get] \item[{\ttfamily  record\_get}] \index{{\ttfamily  record\_get}}
         * An an extension to the CSL profiling scheme it it possible to compile
         * a special version that tracks and counts each use of property-list access
         * functions. This can be useful because there are ways to give special
         * treatment to a small number of flags and a small number of properties. The
         * special-case flage end up stored as a bitmap in the symbol-header so avoid
         * need for property-list searching. But of course recording this extra
         * information slows things down. This tag notes when the slow version is
         * in use. It might be used to trigger a display of statistics at the end of
         * a calculation.
         */

        /*! lispsys [reduce] \item[{\ttfamily reduce}] \index{{\ttfamily reduce}}
         * This is intended to report if the initial heap image is for Reduce rather than
         * merely for Lisp.
         */

        /*! lispsys [shortname] \item[{\ttfamily  (shortname . name)}] \index{{\ttfamily  (shortname . name)}}
         * Gives the short name of the current executable, without its full path.
         */

        /*! lispsys [showmath] \item[{\ttfamily showmath}] \index{{\ttfamily showmath}}
         * If the ``showmath'' capability has been compiled into CSL this will be present
         * so that Lisp code can know it is reasonable to try to use it.
         */

        /*! lispsys [showmath1] \item[{\ttfamily showmath1}] \index{{\ttfamily showmath1}}
         * This marks the fact that this version of CSL will support the output
         * style where flat simple text preceeds TeX output, with a U+0003 (end of text)
         * marker to separate.
         */

        /*! lispsys [sixty-four] \item[{\ttfamily  sixty!-four}] \index{{\ttfamily  sixty"!-four}}
         * Present if the Lisp was compiled for a 64-bit computer.
         */

        /*! lispsys [termed] \item[{\ttfamily termed}] \index{{\ttfamily termed}}
         * Present if a cursor-addressable console was detected.
         */

        /*! lispsys [texmacs] \item[{\ttfamily texmacs}] \index{{\ttfamily texmacs}}
         * Present if the system was launched with the {\ttfamily --texmacs} flag.
         * The intent is that this should only be done when it has been launched with
         * texmacs as a front-end.
         */

        /*! lispsys [revision] \item[{\ttfamily  (revision . ver)}] \index{{\ttfamily  (revision . ver)}}
         * The CSL subversion revision number.
         */


        /*! lispsys [windowed] \item[{\ttfamily windowed}] \index{{\ttfamily windowed}}
         * Present if CSL is running in its own window rather than in console mode.
         */

        w = cons(make_keyword(OPSYS), nil);
#if defined WIN64 || defined __WIN64__ || defined WIN32
// In the WIN64 case I will ALSO tell the user than I am "win32". This is
// a curious thing to do maybe, but is because historically win32 may have
// been used as a "windows" test, and win64 is in general terms a
// compatible extension so all win32 options ought still to be available.
        w = cons(make_keyword("win32"), w);
#endif
#if defined WIN64 || defined __WIN64__
        w = cons(make_keyword("win64"), w);
#endif
        setheader(n, qheader(n) | SYM_SPECIAL_VAR);
#endif
        defined_symbols = 0;
        for (i=0;
             setup_tables[i]!=nullptr;
             i++) count_symbols(setup_tables[i]);
#ifdef COMMON
// A gratuitous misery here is the need to make words
// upper case.
        w = acons(make_keyword("OPSYS"),
                  make_undefined_symbol(OPSYS), w);
        w = acons(make_keyword("C-CODE"),
                  fixnum_of_int(defined_symbols), w);
        w = acons(make_keyword("PLATFORM"),
                  make_undefined_symbol(BUILTFOR), w);
        if (SIXTY_FOUR_BIT) w = cons(make_keyword("SIXTY-FOUR"), w);
        w = cons(make_keyword("PIPES"), w);
#if defined HAVE_UNISTD_H && \
    defined HAVE_SYS_TYPES_H && \
    defined HAVE_SYS_STAT_H && \
    defined HAVE_SYS_WAIT_H && \
    defined HAVE_SIGNAL_H && \
    defined HAVE_SYS_SHM_H && \
    defined HAVE_SYS_IPC_H && \
    defined HAVE_FORK && \
    defined HAVE_WAIT && \
    defined HAVE_WAITPID && \
    defined HAVE_SHMGET && \
    defined HAVE_SHMAT && \
    defined HAVE_SHMDT && \
    defined HAVE_SHMCTL
        w = cons(make_keyword("PARALLEL", w);
#endif
#ifdef DEBUG
        w = cons(make_keyword("DEBUG"), w);
#endif
#ifndef NO_BYTECOUNT
        w = cons(make_keyword("BYTECOUNTS"), w);
#endif
#ifdef EXPERIMENT
        w = cons(make_keyword("EXPERIMENT"), w);
#endif
        w = cons(make_keyword("RECORD_GET"), w);
        w = acons(make_keyword("EXECUTABLE"),
                  make_string(fullProgramName), w);
        w = acons(make_keyword("NAME"), make_string(IMPNAME), w);
        w = acons(make_keyword("REVISION"), fixnum_of_int(REVISION), w);
        w = cons(make_keyword("CCL"), w);
        w = cons(make_keyword("COMMON-LISP"), w);

#else // !COMMON

        w = acons(make_keyword("opsys"),
                  make_undefined_symbol(OPSYS), w);
        w = acons(make_keyword("c-code"),
                  fixnum_of_int(defined_symbols), w);
        w = acons(make_keyword("platform"),
                  make_undefined_symbol(BUILTFOR), w);
        if (texmacs_mode)
            w = cons(make_keyword("texmacs"), w);
        if (SIXTY_FOUR_BIT) w = cons(make_keyword("sixty-four"), w);
        w = cons(make_keyword("pipes"), w);
#if defined HAVE_CRLIBM
        w = cons(make_keyword("crlibm"), w);
#endif
#if defined HAVE_UNISTD_H && \
    defined HAVE_SYS_TYPES_H && \
    defined HAVE_SYS_STAT_H && \
    defined HAVE_SYS_WAIT_H && \
    defined HAVE_SIGNAL_H && \
    defined HAVE_SYS_SHM_H && \
    defined HAVE_SYS_IPC_H && \
    defined HAVE_FORK && \
    defined HAVE_WAIT && \
    defined HAVE_WAITPID && \
    defined HAVE_SHMGET && \
    defined HAVE_SHMAT && \
    defined HAVE_SHMDT && \
    defined HAVE_SHMCTL
        w = cons(make_keyword("parallel"), w);
#endif
#ifdef DEBUG
        w = cons(make_keyword("debug"), w);
#endif
#ifndef NO_BYTECOUNT
        w = cons(make_keyword("bytecounts"), w);
#endif
#ifdef EXPERIMENT
        w = cons(make_keyword("experiment"), w);
#endif
#ifdef CONSERVATIVE
        w = cons(make_keyword("conservative"), w);
#endif
#ifdef EMBEDDED
        w = cons(make_keyword("embedded"), w);
#endif
#ifdef NO_THROW
        w = cons(make_keyword("no-throw"), w);
#endif
#ifdef CONSERVATIVE
        w = cons(make_keyword("conservative"), w);
#endif
        if (fwin_windowmode() & FWIN_WITH_TERMED)
            w = cons(make_keyword("termed"), w);
#ifdef HAVE_LIBFOX
        if (fwin_windowmode() & FWIN_IN_WINDOW)
        {   w = cons(make_keyword("windowed"), w);
            w = cons(make_keyword("fox"), w);
// It could be the case that SHOWMATH is compiled in but the necessary
// fonts were not located. Or if they were there but "--" has been used to
// redirect standard output to a file.
            if (showmathInitialised &&
                alternative_stdout == nullptr)
            {   w = cons(make_keyword("showmath"), w);
                w = cons(make_keyword("showmath1"), w);
            }
        }
#endif
#ifdef HAVE_LIBWX
        if (fwin_windowmode() & FWIN_IN_WINDOW)
        {   w = cons(make_keyword("windowed"), w);
            w = cons(make_keyword("wx"), w);
// It could be the case that SHOWMATH is compiled in but the necessary
// fonts were not located. Or if they were there but "--" has been used to
// redirect standard output to a file.
            if (showmathInitialised &&
                alternative_stdout == nullptr)
            {   w = cons(make_keyword("showmath"), w);
                w = cons(make_keyword("showmath1"), w);
            }
        }
#endif
#ifdef RECORD_GET
        w = cons(make_keyword("record_get"), w);
#endif
        w = acons(make_keyword("executable"),
                  make_string(fullProgramName), w);
        w = acons(make_keyword("shortname"),
                  make_string(programName), w);
        if (!restartp) w = cons(make_keyword("cold-start"), w);
        w = acons(make_keyword("name"), make_string(IMPNAME), w);
        w = acons(make_keyword("revision"), fixnum_of_int(REVISION), w);
        w = cons(make_keyword("csl"), w);
// Ha Ha a trick here - if a symbol ADDSQ is defined I view this image
// as being one for REDUCE and push that information onto lispsystem*,
// and I also reset the "about box" information (if using fwin).
        w1 = make_undefined_symbol("addsq");
        if (qfn1(w1) != undefined_1)
        {   w = cons(make_keyword("reduce"), w);
            w1 = qvalue(make_undefined_symbol("version*"));
            if (is_vector(w1) &&
                is_string_header(vechdr(w1)))
            {   int n = length_of_byteheader(vechdr(w1))-CELL;
                std::sprintf(about_box_title, "About %.*s",
                             (n > 31-static_cast<int>(std::strlen("About ")) ?
                              31-static_cast<int>(std::strlen("About ")) : n),
                             reinterpret_cast<const char *>(&celt(w1, 0)));
                std::sprintf(about_box_description, "%.*s",
                             (n > 31 ? 31 : n),
                             reinterpret_cast<const char *>(&celt(w1, 0)));
// The provision here is that if variables called "author!*" and
// "author2!*" exist with strings as values then those values will
// appear in the "about box". See a commentary in the file fwin.c about
// possibly non-obvious constraints on what text you may properly place
// in these strings.
                w1 = qvalue(make_undefined_symbol("author1*"));
                if (is_vector(w1) &&
                    is_string_header(vechdr(w1)))
                {   n = length_of_byteheader(vechdr(w1))-CELL;
                    std::sprintf(about_box_rights_1, "%.*s",
                                 n > 31 ? 31 : n, reinterpret_cast<const char *>(&celt(w1, 0)));
                }
                else std::strcpy(about_box_rights_1, "A C Hearn/RAND");
                w1 = qvalue(make_undefined_symbol("author2*"));
                if (is_vector(w1) &&
                    is_string_header(vechdr(w1)))
                {   n = length_of_byteheader(vechdr(w1))-CELL;
                    std::sprintf(about_box_rights_2, "%.*s",
                                 n > 31 ? 31 : n,
                                 reinterpret_cast<const char *>(&celt(w1, 0)));
                }
                else std::strcpy(about_box_rights_2, "Codemist    ");
            }
            else
            {   std::strcpy(about_box_title, "About REDUCE");
                std::strcpy(about_box_description, "REDUCE");
                std::strcpy(about_box_rights_1, "A C Hearn/RAND");
                std::strcpy(about_box_rights_2, "Codemist");
            }
        }
        setheader(n, qheader(n) | SYM_SPECIAL_VAR);
        setvalue(n, w);
#endif // COMMON
    }
// lispargs* and full-lispargs!* give access to command line args used at
// launch. lispargs!* just contains anything beyond the keyword "--args"
// while full-lispargs contains everything.
    {   LispObject aa = nil, faa = nil;
        LispObject n = make_undefined_symbol("lispargs*");
        int i, seen_args_keyword=0;
        for (i=0; i<csl_argc; i++)
        {   LispObject s = make_string(csl_argv[i]);
            faa = cons(s, faa);
            if (seen_args_keyword) aa = cons(s, aa);
            if (std::strcmp(csl_argv[i], "--args") == 0) seen_args_keyword = 1;
        }
        aa = Lreverse(nil, aa);
        faa = Lreverse(nil, faa);
        setheader(n, qheader(n) | SYM_SPECIAL_VAR);
        setvalue(n, aa);
        n = make_undefined_fluid("full-lispargs*");
        setvalue(n, faa);
    }
// Floating point characteristics are taken from <cfloat> where it is
// supposed that the C compiler involved has got the values correct.
// I do this every time the system is loaded rather than just when an
// image is cold-created. This is because an image file may have been created
// on a system differing from the one on which it is used. Maybe in fact
// IEEE arithmetic is ALMOST universal and I am being too cautious here?
    make_constant("short-float-epsilon",
                  pack_short_float(16.0*FLT_EPSILON));
    make_constant("single-float-epsilon",
                  pack_single_float(FLT_EPSILON));
    make_constant("double-float-epsilon",
                  make_boxfloat(DBL_EPSILON, TYPE_DOUBLE_FLOAT));
// Now that LONG FLOAT is 128-bits all the literals set up here are
// liable to be incorrect!
    make_constant("long-float-epsilon",
                  make_boxfloat(DBL_EPSILON, TYPE_LONG_FLOAT));
// I assume that I have a radix 2 representation, and float-negative-epsilon
// is just half float-epsilon. Correct me if I am wrong...
    make_constant("short-float-negative-epsilon",
                  pack_short_float(16.0*FLT_EPSILON/2.0));
    make_constant("single-float-negative-epsilon",
                  pack_single_float(FLT_EPSILON/2.0));
    make_constant("double-float-negative-epsilon",
                  make_boxfloat(DBL_EPSILON/2.0, TYPE_DOUBLE_FLOAT));
// For now "long" = "double"
    make_constant("long-float-negative-epsilon",
                  make_boxfloat(DBL_EPSILON/2.0, TYPE_LONG_FLOAT));
// I hope that the C header file gets extremal values correct. Note that
// because pack_short_float() truncates (rather than rounding) it should give
// correct values for most-positive-short-float etc
    make_constant("most-positive-short-float",
                  pack_short_float(FLT_MAX));
    make_constant("most-positive-single-float",
                  pack_single_float(FLT_MAX));
    make_constant("most-positive-double-float",
                  make_boxfloat(DBL_MAX, TYPE_DOUBLE_FLOAT));
    make_constant("most-positive-long-float",
                  make_boxfloat(DBL_MAX, TYPE_LONG_FLOAT));
// Here I assume that the floating point representation is sign-and-magnitude
// and hence symmetric about zero.
    make_constant("most-negative-short-float",
                  pack_short_float(-FLT_MAX));
    make_constant("most-negative-single-float",
                  pack_single_float(-FLT_MAX));
    make_constant("most-negative-double-float",
                  make_boxfloat(-DBL_MAX, TYPE_DOUBLE_FLOAT));
    make_constant("most-negative-long-float",
                  make_boxfloat(-DBL_MAX, TYPE_LONG_FLOAT));
// The "least-xxx" set of values did not consider the case of denormalised
// numbers too carefully in ClTl-1, so in ClTl-2 there are elaborations. I
// believe that a proper C header file <cfloat> will make the macros that
// I use here refer to NORMALISED values, so the numeric results I use
// here will not be quite proper (ie there are smaller floats that are
// un-normalised). But I will ignore that worry just for now.
    make_constant("least-positive-short-float",
                  pack_short_float(FLT_MIN));
    make_constant("least-positive-single-float",
                  pack_single_float(FLT_MIN));
    make_constant("least-positive-double-float",
                  make_boxfloat(DBL_MIN, TYPE_DOUBLE_FLOAT));
    make_constant("least-positive-long-float",
                  make_boxfloat(DBL_MIN, TYPE_LONG_FLOAT));
    make_constant("least-negative-short-float",
                  pack_short_float(-FLT_MIN));
    make_constant("least-negative-single-float",
                  pack_single_float(-FLT_MIN));
    make_constant("least-negative-double-float",
                  make_boxfloat(-DBL_MIN, TYPE_DOUBLE_FLOAT));
    make_constant("least-negative-long-float",
                  make_boxfloat(-DBL_MIN, TYPE_LONG_FLOAT));
// The bunch here are intended to be NORMALISED numbers, while the unqualified
// ones above may not be.
    make_constant("least-positive-normalized-short-float",
                  pack_short_float(FLT_MIN));
    make_constant("least-positive-normalized-single-float",
                  pack_single_float(FLT_MIN));
    make_constant("least-positive-normalized-double-float",
                  make_boxfloat(DBL_MIN, TYPE_DOUBLE_FLOAT));
    make_constant("least-positive-normalized-long-float",
                  make_boxfloat(DBL_MIN, TYPE_LONG_FLOAT));
    make_constant("least-negative-normalized-short-float",
                  pack_short_float(-FLT_MIN));
    make_constant("least-negative-normalized-single-float",
                  pack_single_float(-FLT_MIN));
    make_constant("least-negative-normalized-double-float",
                  make_boxfloat(-DBL_MIN, TYPE_DOUBLE_FLOAT));
    make_constant("least-negative-normalized-long-float",
                  make_boxfloat(-DBL_MIN, TYPE_LONG_FLOAT));
    make_constant("internal-time-units-per-second",
                  fixnum_of_int(1000));

    terminal_io = make_undefined_fluid("*terminal-io*");
    standard_input = make_undefined_fluid("*standard-input*");
    standard_output = make_undefined_fluid("*standard-output*");
    error_output = make_undefined_fluid("*error-output*");
    trace_output = make_undefined_fluid("*trace-output*");
    debug_io = make_undefined_fluid("*debug-io*");
    query_io = make_undefined_fluid("*query-io*");

    stream_type(lisp_work_stream) = make_undefined_symbol("work-stream");

    {   LispObject f = lisp_terminal_io;
        stream_type(f) = make_undefined_symbol("terminal-stream");
        set_stream_read_fn(f, char_from_terminal);
        set_stream_read_other(f, read_action_terminal);
        set_stream_write_fn(f, char_to_terminal);
        set_stream_write_other(f, write_action_terminal);
        setvalue(terminal_io, f);
        f = lisp_standard_input;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
// If I do not have COMMON defined I will take a slight short cut here and
// make reading from *standard-input* read directly from the terminal. For
// full Common Lisp compatibility I think *standard-input* is required to
// be a synonym stream that will dynamically look at the value of the variable
// *terminal-io* every time it does anything. Ugh, since people who assign to
// or re-bind *terminal-io* seem to me to be asking for terrible trouble!
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
        setvalue(standard_input, f);

        f = lisp_standard_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        setvalue(standard_output, f);

        f = lisp_error_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        setvalue(error_output, f);

        f = lisp_trace_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        setvalue(trace_output, f);

        f = lisp_debug_io;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        setvalue(debug_io, f);

        f = lisp_query_io;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        setvalue(query_io, f);
    }

#if defined HAVE_LIBFOX || defined HAVE_LIBWX
    {   LispObject stream = make_undefined_fluid("*math-output*");
        LispObject f = make_stream_handle();
        stream_type(f) = make_undefined_symbol("math-output");
        set_stream_write_fn(f, char_to_math);
        set_stream_write_other(f, write_action_math);
        setvalue(stream, f);
        stream = make_undefined_fluid("*spool-output*");
        f = make_stream_handle();
        stream_type(f) = make_undefined_symbol("spool-output");
        set_stream_write_fn(f, char_to_spool);
        set_stream_write_other(f, write_action_spool);
        setvalue(stream, f);
    }
#endif

// I can now predefine symbols in two ways:
//     -D name=val
//     --D name=val
// The first of these matches old behaviour and the value assigned to name
// is always a string. The second can turn it into a symbol, number etc.
    for (auto ss : symbolsToDefine)
    {   bool undef = !ss.flag;
        const char* s = ss.key.c_str();
        if (undef)
        {   LispObject n = make_undefined_symbol(s);
            setvalue(n, unset_var);
        }
        else
        {   LispObject n = make_undefined_symbol(s);
            THREADID;
            Save save(THREADARG n);
            s = ss.data.c_str();
// If you go "--D xxx" then treat it as "--D xxx=t".
            LispObject v;
            if (std::strlen(s) == 0) v = lisp_true;
            else
            {   v = make_string(s);
                v = Lexplodec(nil, v);
                v = Lcompress(nil, v);
// The above will first make the value in -Dname=value into a string,
// then explode it into a list, and compress back - the effect is as if the
// original value had been passed through the regular Lisp READ function,
// so symbols, numbers and even s-expressions can be parsed.  If the
// parsing fails I (silently) treat the value as just NIL.
            }
            save.restore(n);
            setheader(n, qheader(n) | SYM_SPECIAL_VAR);
            setvalue(n, v);
        }
    }
    for (auto ss : stringsToDefine)
    {   bool undef = !ss.flag;
        const char* s = ss.key.c_str();
        if (undef)
        {   LispObject n = make_undefined_symbol(s);
            setvalue(n, unset_var);
        }
        else
        {   LispObject n = make_undefined_symbol(s);
            THREADID;
            Save save(THREADARG n);
            s = ss.data.c_str();
            LispObject v;
            if (std::strlen(s) == 0) v = lisp_true;
            else v = make_string(s);
            save.restore(n);
            setheader(n, qheader(n) | SYM_SPECIAL_VAR);
            setvalue(n, v);
        }
    }
    for (auto ss : stringsToEvaluate)
    {   const char* s = ss.c_str();
        THREADID;
        TRY
            LispObject v = make_string(s);
            errexit();
            v = Lexplodec(nil, v);
            errexit();
            v = Lcompress(nil, v);
            errexit();
            THREADID;
            Save save(THREADARG v);
            Lprin(nil, v);
            save.restore(v);
            errexit();
            v = Leval(nil, v);
            errexit();
            Save save1(THREADARG v);
            term_printf(" => ");
            errexit();
            save1.restore(v);
            Lprint(nil, v);
// A failure in an expression set to be evaluated here is fatal.
        CATCH(LispException)
            ensure_screen();
            my_exit();
        END_CATCH
    }
// Now if I have the FWIN windowed system I look in the Lisp variables
//    loadable-packages!*
//    switches!*
// (both expected to be lists of symbols) and copy info into a couple of
// C vectors, whence it can go to the window manager and be used to create
// suitable menus. I might get in a mess if I try to set and reset menus
// multiple times, and so to avoid possible confusion I do this step
// JUST ONCE. This may be limiting (in particular it means that menus get
// set at the very start of a run ONLY) but should only be visible to those
// who call restart!-csl.
    if (loadable_packages == nullptr && switches==nullptr)
    {   LispObject w1 = qvalue(make_undefined_symbol("loadable-packages*"));
        LispObject w2;
        int n;
        char* v;
        n = 0;
        for (w2=w1; consp(w2); w2=cdr(w2)) n++; // How many?
        n = 2*n;
        loadable_packages = new (std::nothrow) char* [n+1];
        if (loadable_packages != nullptr)
        {   n = 0;
            for (w2=w1; consp(w2); w2=cdr(w2))
            {   LispObject w3 = car(w2);
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    !is_string_header(vechdr(w3))) break;
                n1 = length_of_byteheader(vechdr(w3))-CELL;
                v = new (std::nothrow) char[n1+2];
                if (v == nullptr) break;
                v[0] = ' ';
                std::memcpy(v+1, &celt(w3, 0), n1);
                v[n1+1] = 0;
                loadable_packages[n++] = v;
                loadable_packages[n++] = nullptr;
            }
            std::qsort(loadable_packages, n/2, 2*sizeof(char*), alpha1);
            loadable_packages[n] = nullptr;   // nullptr-terminate the list
        }
        w1 = qvalue(make_undefined_symbol("switches*"));
        n = 0;
        for (w2=w1; consp(w2); w2=cdr(w2)) n++; // How many?
        n = (n+1)*sizeof(char*);
        n = 2*n;
        switches = new (std::nothrow) char* [n+1];
        if (switches != nullptr)
        {   n = 0;
            for (w2=w1; consp(w2); w2=cdr(w2))
            {   LispObject w3 = car(w2), w4;
                char sname[64];
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    !is_string_header(vechdr(w3))) break;
                n1 = length_of_byteheader(vechdr(w3))-CELL;
                if (n1 > 60) break;
                std::sprintf(sname, "*%.*s", n1,
                             reinterpret_cast<const char*>(&celt(w3, 0)));
                w4 = make_undefined_symbol(sname);
                v = new (std::nothrow) char[n1+2];
                if (v == nullptr) break;
// The first character records the current state of the switch. With FWIN
// I have entries that say "x" for "I am not at present active" which copes
// with switches that will become relevant only when a package of code is
// loaded. I will scan from time to time to update my information - I guess
// that I can put in a hook that triggers review after any module has been
// loaded. See the function review_switch_settings() the follows...
                if (qvalue(w4) == nil) v[0] = 'n';
                else if (qvalue(w4) == unset_var) v[0] = 'x';
                else v[0] = 'y';
                std::memcpy(v+1, &celt(w3, 0), n1);
                v[n1+1] = 0;
                switches[n++] = v;
                switches[n++] = nullptr;
            }
            std::qsort(switches, n/2, 2*sizeof(char*), alpha1);
            switches[n] = nullptr;
        }
    }

#ifdef COMMON
    CP = saved_package;
#endif
    return nil;
}

#ifndef COMMON
// This alse reviews the list of loaded packages...

void review_switch_settings()
{   LispObject sw = qvalue(make_undefined_symbol("switches*"));
    while (consp(sw))
    {   LispObject s = car(sw);
        char sname[64];
        int n1;
        char* v;
        char** p;
        LispObject starsw;
        sw = cdr(sw);
        if (is_symbol(s)) s = qpname(s);
        if (!is_vector(s) || !is_string_header(vechdr(s))) continue;
        n1 = length_of_byteheader(vechdr(s))-CELL;
        if (n1 > 60) continue;
        std::sprintf(sname, "*%.*s", n1,
                     reinterpret_cast<const char*>(&celt(s, 0)));
        for (p=switches; *p!=nullptr; p+=2)
        {   if (std::strcmp(1+*p, &sname[1]) == 0) break;
        }
        if ((v=*p) == nullptr) continue;
        starsw = make_undefined_symbol(sname);
        if (qvalue(starsw) == nil) switch(*v)
            {   case 'y':  *v = 0x3f&'N'; break;
                case 'n':                 break;
                case 'x':  *v = 'N';      break;
            }
        else if (qvalue(starsw) == unset_var) switch(*v)
            {   case 'y':  *v = 'X';      break;
                case 'n':  *v = 'X';      break;
                case 'x':                 break;
            }
        else switch(*v)
            {   case 'y':                 break;
                case 'n':  *v = 0x3f&'Y'; break;
                case 'x':  *v = 'Y';      break;
            }
    }
    sw = qvalue(make_undefined_symbol("loaded-packages*"));
    while (consp(sw))
    {   LispObject s = car(sw);
        char sname[64];
        int n1;
        char* v;
        char** p;
        sw = cdr(sw);
        if (is_symbol(s)) s = qpname(s);
        if (!is_vector(s) || !is_string_header(s)) continue;
        n1 = length_of_byteheader(vechdr(s))-CELL;
        if (n1 > 60) continue;
        std::sprintf(sname, "%.*s", n1,
                     reinterpret_cast<const char *>(&celt(s, 0)));
        for (p=loadable_packages; *p!=nullptr; p+=2)
        {   if (std::strcmp(1+*p, sname) == 0) break;
        }
        if ((v=*p) == nullptr) continue;
        if (*v == ' ') *v = 'X';  // X here says "update the info"
    }
    fwin_refresh_switches(switches, loadable_packages);
}

#endif

bool CSL_MD5_busy;

// Used to ensure that an image file matches up with the C code compiled
// into the main executable. The linear search here for the place the
// checksum lives is a bit crummy. But the total cost is linear in the
// number of things that have been compiled into C.

static void get_checksum(const setup_type* p)
{   while (p->name!=nullptr) p++;
    if (p->one != nullptr && p->two != nullptr)
    {   const unsigned char* w = reinterpret_cast<const unsigned char*>
                                 (p->two);
        CSL_MD5_Update(w, std::strlen(reinterpret_cast<const char*>(w)));
    }
}

void get_user_files_checksum(unsigned char* b)
{   size_t i;
    CSL_MD5_Init();
    for (i=0; setup_tables[i]!=nullptr; i++)
        get_checksum(setup_tables[i]);
    CSL_MD5_Final(b);
}

#ifdef __ARM__
// June 2016: on the Raspberry pi this code gets messed up by -O2 and -O3.
// This may well be my fault, but for now I will hold the fort by sticking in
// a pragma to downgrade the optimization (with a "z") level... Ugh. Every so
// often I should revisit this and see if I can understand what aspect of the
// code causes pain, or whether the Raspberry Pi version of g++ has moved on!
#pragma GCC optimize ("1")
#endif

void setup(int restart_flag, double store_size)
{
// restart_flag is a set of options passed as a bitmap:
//    1       Do a warm start, ie re-load a heap image.
//            The alternative is a cold start that should only
//            be called for as part of a system bootstrap process.
//    2       Grab memory for CSL to use.
//            The alternative is to assume that memory has already been
//            allocated, and to re-use what there is.
//    4, 8, ...   not used yet!
    int32_t i;
    if ((restart_flag & 2) != 0) init_heap_segments(store_size);
    garbage_collection_permitted = false;
    THREADID;
    stack = reinterpret_cast<LispObject*>(stackBase);
    *stack = nil;
    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;
    for (size_t j=0; j<=LOG2_VECTOR_CHUNK_BYTES; j++)
        free_vectors[j] = 0;

    if ((restart_flag & 1) != 0)
    {   char junkbuf[120];
        char filename[LONGEST_LEGAL_FILENAME];
        std::memset(junkbuf, 0, sizeof(junkbuf));
        std::memset(filename, 0, sizeof(filename));
        if (IopenRoot(filename, 0, 0))
        {   term_printf("\n+++ Image file \"%s\" can not be read\n",
                        filename);
            my_exit();
        }
// The initial record at the start of an image file is not compressed...
        Iread(junkbuf, 112);
        if (init_flags & INIT_VERBOSE)
        {   term_printf("Created: %.25s\n", &junkbuf[64]);
            // Time dump was taken
        }
        unsigned char chk[16];
        get_user_files_checksum(chk);
        for (i=0; i<16; i++)
        {   if (chk[i] != (junkbuf[90+i] & 0xff))
            {   term_printf(
                    "\n+++ Image file belongs with a different version\n");
                term_printf(
                    "    of the executable file (incompatible code\n");
                term_printf(
                    "    has been optimised into C and incorporated)\n");
                term_printf(
                    "    Unable to use this image file, so stopping\n");
                term_printf(
                    "    File is: %s\n", filename);
                my_exit();
            }
        }
// To make things more responsive for the user I will display a
// banner rather early (before reading the bulk of the image file).
// The banner that I will display is one provided to be by PRESERVE.
        {   char b[64];
            if (IopenRoot(filename, BANNER_CODE, 0)) b[0] = 0;
            else
            {   for (i=0; i<64; i++) b[i] = static_cast<char>(Igetc());
// The banner will not be subject to compression technology because it will
// normally be too short to benefit.
                IcloseInput();
            }
// A banner set via startup-banner takes precedence over one from preserve.
// But as a very special hack I detect if --texmacs was on the command
// line and in that case I stay quiet...
            if (!texmacs_mode)
            {   if (b[0] != 0)
                {   term_printf("%s\n", b);
                    ensure_screen();
                }
                else if (junkbuf[0] != 0)
                {   term_printf("%s\n", junkbuf);
                    ensure_screen();
                }
            }
        }
    }
    else for (LispObject** p = list_bases; *p!=nullptr; p++) **p = nil;

    stackLimit = ~static_cast<uintptr_t>(0xff) &
                 reinterpret_cast<uintptr_t>(
                     &stack[stack_segsize*CSL_PAGE_SIZE/CELL-200]);
    // allow some slop at end

#ifndef CONSERVATIVE
    void* p = vheap_pages[vheap_pages_count++] =
                  allocate_page("vheap warm setup");
    vfringe = reinterpret_cast<LispObject>(
                  8 + reinterpret_cast<char*>(doubleword_align_up(
                              reinterpret_cast<intptr_t>(p))));
    vheaplimit = static_cast<LispObject>(vfringe + (CSL_PAGE_SIZE - 16));
    p = heap_pages[heap_pages_count++] = allocate_page("heap warm setup");
    lheaplimit = (intptr_t)p;
    lfringe = static_cast<LispObject>(lheaplimit + CSL_PAGE_SIZE);
    lheaplimit = static_cast<LispObject>(lheaplimit + SPARE);
#endif // !CONSERVATIVE

    if ((restart_flag & 1) != 0) warm_setup();
    else cold_setup();

    if (init_flags & INIT_QUIET) Lverbos(nil, fixnum_of_int(1));
    if (init_flags & INIT_VERBOSE) Lverbos(nil, fixnum_of_int(3));
#ifndef CONSERVATIVE
// Here I grab more memory (if I am allowed to) until the proportion of the
// heap active at the end of garbage collection is less than 1/2.  If the
// attempt to grab more memory fails I clear the bit in init_flags that
// allows me to try to expand, so I will not waste time again.
// The aim of keeping the heap less than half full is an heuristic and
// could be adjusted on the basis of experience with this code.
    if ((init_flags & INIT_EXPANDABLE) != 0)
    {   int32_t more = heap_pages_count + vheap_pages_count;
        more = 3*more - pages_count;
        while (more-- > 0)
        {   void* page = reinterpret_cast<void*>(
                new (std::nothrow) char[CSL_PAGE_SIZE]);
            if (page == nullptr)
            {   init_flags &= ~INIT_EXPANDABLE;
                break;
            }
            else pages[pages_count++] = page;
        }
    }
#endif
    {   int32_t w = 0;
// The total store allocated is that used plus that free, including the
// page set aside for the Lisp stack.
        if (init_flags & INIT_VERBOSE)
        {   size_t m =
                (static_cast<size_t>(CSL_PAGE_SIZE/1024))*(pages_count+w+1);
            if (m >= 10240*1024)
                term_printf("Memory allocation: %lu Gbytes\n",
                    static_cast<unsigned long>(m/1024/1024));
            else if (m >= 10240)
                term_printf("Memory allocation: %lu Mbytes\n",
                    static_cast<unsigned long>(m/1024));
            else term_printf("Memory allocation: %lu Kbytes\n",
                static_cast<unsigned long>(m));
        }
    }
    if (init_flags & INIT_VERBOSE)
    {   unsigned int n = number_of_processors();
        if (n > 1)
            term_printf("There are %u processors available\n", n);
    }
    garbage_collection_permitted = true;
    return;
}

LispObject multiplication_buffer;

// Here is a table of all the list-bases that CSL marks from, and that
// must have their values captured in checkpoint files.

LispObject* list_bases[] =
{   &active_stream,         &allow_key_key,     &allow_other_keys,
    &all_packages,          &and_symbol,        &append_symbol,
    &applyhook,             &apply_symbol,      &autoload_symbol,
    &aux_key,               &avail_space,       &big_dividend,
    &big_divisor,           &big_fake1,         &big_fake2,
    &big_quotient,          &bit_symbol,        &boffo,
    &break_function,        &B_reg,             &builtin0_symbol,
    &builtin1_symbol,       &builtin2_symbol,   &builtin3_symbol,
    &builtin4_symbol,       &bytecoded_symbol,  &call_stack,
    &callstack,             &catch_tags,        &cfunarg,
    &char_0_symbol,         &charvec,           &cl_equal_symbol,
    &codevec,               &comma_at_symbol,   &comma_symbol,
    &compiler_symbol,       &comp_symbol,       &cond_symbol,
    &cons_symbol,           &current_file,      &current_function,
    &current_module,        &current_package,   &debug_io,
    &declare_symbol,        &double_float,      &echo_symbol,
    &emsg_star,             &eof_symbol,        &eql_symbol,
    &eq_symbol,             &equalp_symbol,     &equal_symbol,
    &error_output,          &err_table,         &evalhook,
    &eval_symbol,           &exit_tag,          &exit_value,
    &expand_def_symbol,     &expr_symbol,       &external_symbol,
    &faslgensyms,           &fasl_stream,       &faslvec,
    &fastget_names,         &features_symbol,   &fexpr_symbol,
    &format_symbol,         &funarg,            &funcall_symbol,
    &function_symbol,       &gchook,            &gcknt_symbol,
    &gensym_base,           &get_counts,        &go_symbol,
    &help_index,            &inherited_symbol,  &initial_element,
    &input_libraries,       &internal_symbol,   &key_key,
    &keyword_package,       &lambda,            &large_modulus,
    &lex_words,             &lisp_debug_io,     &lisp_error_output,
    &lisp_package,          &lisp_query_io,     &lisp_standard_input,
    &lisp_standard_output,  &lisp_terminal_io,  &lisp_trace_output,
    &lisp_true,             &lisp_work_stream,  &liststar_symbol,
    &list_symbol,           &litvec,            &load_selected_source_symbol,
    &load_source_symbol,    &long_float,        &lose_symbol,
    &lower_symbol,          &macroexpand_hook,  &macro_symbol,
    &multiplication_buffer, &mv_call_symbol,    &named_character,
    &nicknames_symbol,      &not_symbol,        &opt_key,
    &or_symbol,             &output_library,    &package_symbol,
    &pathname_symbol,       &prinl_symbol,      &print_array_sym,
    &procmem,               &procstack,         &progn_symbol,
    &prompt_thing,          &query_io,          &quote_symbol,
    &raise_symbol,          &read_base,         &reader_workspace,
    &read_float_format,     &redef_msg,         &rehash_vec1,
    &rehash_vec2,           &resources,         &rest_key,
    &savedefs_symbol,       &savedef_symbol,    &short_float,
    &single_float,          &special_symbol,    &standard_input,
    &standard_output,       &startfn,           &startup_symbol,
    &string_char_sym,       &supervisor,        &sys_hash_table,
    &terminal_io,           &tracedfn,          &trace_output,
    &traceprint_symbol,     &trap_time,         &unset_var,
    &used_space,            &use_symbol,        &work_symbol,

    &user_base_0,  &user_base_1,  &user_base_2,  &user_base_3,  &user_base_4,
    &user_base_5,  &user_base_6,  &user_base_7,  &user_base_8,  &user_base_9,

    &workbase[ 0], &workbase[ 1], &workbase[ 2], &workbase[ 3], &workbase[ 4],
    &workbase[ 5], &workbase[ 6], &workbase[ 7], &workbase[ 8], &workbase[ 9],
    &workbase[10], &workbase[11], &workbase[12], &workbase[13], &workbase[14],
    &workbase[15], &workbase[16], &workbase[17], &workbase[18], &workbase[19],
    &workbase[20], &workbase[21], &workbase[22], &workbase[23], &workbase[24],
    &workbase[25], &workbase[26], &workbase[27], &workbase[28], &workbase[29],
    &workbase[30], &workbase[31], &workbase[32], &workbase[33], &workbase[34],
    &workbase[35], &workbase[36], &workbase[37], &workbase[38], &workbase[39],
    &workbase[40], &workbase[41], &workbase[42], &workbase[43], &workbase[44],
    &workbase[45], &workbase[46], &workbase[47], &workbase[48], &workbase[49],
    &workbase[50],
    nullptr              // Used to mark the end of the table.
};

// For debugging it is sometimes nice to be able to identify the names
// associated with list-base offsets.

const char* list_names[] =
{   "active_stream",         "allow_key_key",     "allow_other_keys",
    "all_packages",          "and_symbol",        "append_symbol",
    "applyhook",             "apply_symbol",      "autoload_symbol",
    "aux_key",               "avail_space",       "big_dividend",
    "big_divisor",           "big_fake1",         "big_fake2",
    "big_quotient",          "bit_symbol",        "boffo",
    "break_function",        "B_reg",             "builtin0_symbol",
    "builtin1_symbol",       "builtin2_symbol",   "builtin3_symbol",
    "builtin4_symbol",       "bytecoded_symbol",  "call_stack",
    "callstack",             "catch_tags",        "cfunarg",
    "char_0_symbol",         "charvec",           "cl_equal_symbol",
    "codevec",               "comma_at_symbol",   "comma_symbol",
    "compiler_symbol",       "comp_symbol",       "cond_symbol",
    "cons_symbol",           "current_file",      "current_function",
    "current_module",        "current_package",   "debug_io",
    "declare_symbol",        "double_float",      "echo_symbol",
    "emsg_star",             "eof_symbol",        "eql_symbol",
    "eq_symbol",             "equalp_symbol",     "equal_symbol",
    "error_output",          "err_table",         "evalhook",
    "eval_symbol",           "exit_tag",          "exit_value",
    "expand_def_symbol",     "expr_symbol",       "external_symbol",
    "faslgensyms",           "fasl_stream",       "faslvec",
    "fastget_names",         "features_symbol",   "fexpr_symbol",
    "format_symbol",         "funarg",            "funcall_symbol",
    "function_symbol",       "gchook",            "gcknt_symbol",
    "gensym_base",           "get_counts",        "go_symbol",
    "help_index",            "inherited_symbol",  "initial_element",
    "input_libraries",       "internal_symbol",   "key_key",
    "keyword_package",       "lambda",            "large_modulus",
    "lex_words",             "lisp_debug_io",     "lisp_error_output",
    "lisp_package",          "lisp_query_io",     "lisp_standard_input",
    "lisp_standard_output",  "lisp_terminal_io",  "lisp_trace_output",
    "lisp_true",             "lisp_work_stream",  "liststar_symbol",
    "list_symbol",           "litvec",            "load_selected_source_symbol",
    "load_source_symbol",    "long_float",        "lose_symbol",
    "lower_symbol",          "macroexpand_hook",  "macro_symbol",
    "multiplication_buffer", "mv_call_symbol",    "named_character",
    "nicknames_symbol",      "not_symbol",        "opt_key",
    "or_symbol",             "output_library",    "package_symbol",
    "pathname_symbol",       "prinl_symbol",      "print_array_sym",
    "procmem",               "procstack",         "progn_symbol",
    "prompt_thing",          "query_io",          "quote_symbol",
    "raise_symbol",          "read_base",         "reader_workspace",
    "read_float_format",     "redef_msg",         "rehash_vec1",
    "rehash_vec2",           "resources",         "rest_key",
    "savedefs_symbol",       "savedef_symbol",    "short_float",
    "single_float",          "special_symbol",    "standard_input",
    "standard_output",       "startfn",           "startup_symbol",
    "string_char_sym",       "supervisor",        "sys_hash_table",
    "terminal_io",           "tracedfn",          "trace_output",
    "traceprint_symbol",     "trap_time",         "unset_var",
    "used_space",            "use_symbol",        "work_symbol",

    "user_base_0",  "user_base_1",  "user_base_2",  "user_base_3",  "user_base_4",
    "user_base_5",  "user_base_6",  "user_base_7",  "user_base_8",  "user_base_9",

    "workbase[ 0]", "workbase[ 1]", "workbase[ 2]", "workbase[ 3]", "workbase[ 4]",
    "workbase[ 5]", "workbase[ 6]", "workbase[ 7]", "workbase[ 8]", "workbase[ 9]",
    "workbase[10]", "workbase[11]", "workbase[12]", "workbase[13]", "workbase[14]",
    "workbase[15]", "workbase[16]", "workbase[17]", "workbase[18]", "workbase[19]",
    "workbase[20]", "workbase[21]", "workbase[22]", "workbase[23]", "workbase[24]",
    "workbase[25]", "workbase[26]", "workbase[27]", "workbase[28]", "workbase[29]",
    "workbase[30]", "workbase[31]", "workbase[32]", "workbase[33]", "workbase[34]",
    "workbase[35]", "workbase[36]", "workbase[37]", "workbase[38]", "workbase[39]",
    "workbase[40]", "workbase[41]", "workbase[42]", "workbase[43]", "workbase[44]",
    "workbase[45]", "workbase[46]", "workbase[47]", "workbase[48]", "workbase[49]",
    "workbase[50]",
    nullptr              // Used to mark the end of the table.
};



// June 2015: I am now going to try MD5 code from Alexander Peslyak
// (Solar Designer). The code is public domain and all I do here is provide
// wrappers so it appears to the bulk of CSL just as the previous version had.
// The main motivation for this is that I must have corrupted the Eric
// Younger code at some stage since it returned incorrect results for input
// strings whose length was 55 mod 64. This showed up when comparing behaviour
// with a Java-coded equivalent. I expect I could track down just what I had
// wrong, but moving to the alternative public domain implementation seemed
// both a good way to verify that the existing code I had was wrong and to end
// up with something clean and tidy for the future.

// Please note that these days MD5 is not considered cryptographically secure,
// and the implementation here will not be robust against side-attacks etc.
// The proper uses here are as a checksum fur use when chance rather than
// malice is the opponent.
//
// The Checksums here are used in two areas in CSL:
// (1) There is a user-visible checksum function that can be applied to
//     arbitrary Lisp objects. It is for whatever use anybody might like to
//     make of it.
// (2) There is a scheme that ensures that Lisp that has been translated
//     into C++ and put in u01.cpp .. u60.cpp is only activated when a
//     Lisp function with the same checksum is to be used.

#include "md5.cpp"

MD5_CTX context;

void CSL_MD5_Init()
{   CSL_MD5_busy = true;
    MD5_Init(&context);
}

void CSL_MD5_Update(const unsigned char *data, size_t len)
{   MD5_Update(&context, data, len);
}

void CSL_MD5_Final(unsigned char *md)
{   MD5_Final(md, &context);
    CSL_MD5_busy = false;
}

#if defined CONSERVATIVE
#include "testcode.cpp" // Temporary for debugging
#endif

// end of restart.cpp
