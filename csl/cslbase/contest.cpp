// contest.cpp                             Copyright (C) 1989-2021 Codemist

// Test harness for new storage allocation...

// This file is compiled along with newallocate.cpp and newcslgc.cpp
// and it will then just let me exercise the new storage allocation
// stuff without the extra weight of the rest of CSL.


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

// $Id$


//#define  INCLUDE_ERROR_STRING_TABLE 1
#include "headers.h"
//#undef   INCLUDE_ERROR_STRING_TABLE

#ifndef WIN32
#include <sys/wait.h>
#endif

#ifdef HAVE_UNISTD_H
#include <sys/unistd.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif



void cslstart(int argc, const char *argv[], character_writer *wout)
{   double store_size = 64.0*1024.0;
// By having 64 Mbytes of memory in all I will end up with a nominal 8 pages
// for my heap - one will be used as a stack region so there will be 7
// managed by garbage collection.
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    C_stacklimit = 0;
    max_store_size = 0.0;
    initHeapSegments(store_size);
// Now I need to ensure that all list-bases have valid (if not useful)
// values.
    setvalue(nil, nil);
    setenv(nil, nil);
    setplist(nil, nil);
    setfastgets(nil, nil);
    setpname(nil, nil);
    setpackage(nil, nil);
    for (auto p = list_bases; *p!=nullptr; p++)
        **p = nil;   
}

atomic<uintptr_t> event_flag(0);

static int col;

void crudeprin(LispObject a)
{   if (col > 70)
    {   printf("\n");
        col = 0;
    }
    if (a == nil) col += printf("nil");
    else if (is_fixnum(a))
        col += printf("%" PRId64, static_cast<int64_t>(int_of_fixnum(a)));
    else if (is_cons(a))
    {   col += printf("(");
        crudeprin(car(a));
        if (col > 70)
        {   printf("\n");
            col = 0;
        }
        col += printf(" . ");
        crudeprin(cdr(a));
        if (col > 70)
        {   printf("\n");
            col = 0;
        }
        col += printf(")");
    }
    else col += printf("?%" PRIx64, static_cast<int64_t>(a));
}

void crudeprint(LispObject a)
{   crudeprin(a);
    cout << endl;
    col = 0;
}

extern LispObject treetest(int k, int size=1000);

static void cslaction()
{   volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    printf("in cslaction\n");
    crudeprint(treetest(200000, 3));
}

int cslfinish(character_writer *w)
{   volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    drop_heap_segments();
    return 0;
}


int main(int argc, const char *argv[])
{   volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
// The next line sets threadId (in fact it should always be to zero since
// at this stage this is the firts and only thread that exists!) and using
// RAII arranges to release that identifier on exit. It is part of the
// protocol that will allow other threads to get created and run later on.
    threadMap = -1;
    activeThreads = 0;
    ThreadStartup userThreads;
    cslstart(argc, argv, nullptr);
    cslaction();
    return 0;
}

double max_store_size = 1024*1024*1024;  // 1G.
uintptr_t C_stacklimit;
LispObject nil;

LispObject aerror1(const char *s, LispObject a)
{   my_abort();
    return 0;
}

void trace_printf(const char *fmt, ...)
{   va_list a;
    va_start(a, fmt);
    vprintf(fmt, a);
    va_end(a);
}

int64_t sixty_four_bits(LispObject a)
{   my_abort();
    return 0;
}

void fatal_error(int code, ...)
{   my_abort();
}

int init_flags;

LispObject *stackBase;
DEFINE_THREAD_LOCAL(LispObject *, stack);

LispObject *repeat_heap = nullptr;
size_t repeat_heap_size = 0, repeat_count = 0;

LispObject multiplication_buffer;
intptr_t nwork;
unsigned int exit_count;
uint64_t gensym_ser;
intptr_t print_precision, miscflags;
intptr_t current_modulus, fastget_size, package_bits,
         modulus_is_large;
LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
LispObject quote_symbol, function_symbol, comma_symbol,
           comma_at_symbol;
LispObject cons_symbol, eval_symbol, apply_symbol, work_symbol,
           evalhook;
LispObject list_symbol, liststar_symbol, eq_symbol, eql_symbol;
LispObject cl_equal_symbol, equal_symbol, equalp_symbol;
LispObject go_symbol, cond_symbol;
LispObject applyhook, macroexpand_hook, append_symbol, exit_tag;
LispObject exit_value, catch_tags, keyword_package, current_package;
LispObject startfn, all_packages, package_symbol, internal_symbol;
LispObject gcknt_symbol, external_symbol, inherited_symbol;
LispObject gensym_base, string_char_sym, boffo;
LispObject key_key, allow_other_keys, aux_key;
LispObject err_table, format_symbol, progn_symbol, expand_def_symbol;
LispObject allow_key_key, declare_symbol, special_symbol,
           large_modulus;
LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol,
           echo_symbol;
LispObject codevec, litvec, supervisor, B_reg, savedef, comp_symbol;
LispObject compiler_symbol, faslvec, tracedfn, lisp_terminal_io;
LispObject lisp_standard_output, lisp_standard_input,
           lisp_error_output;
LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
LispObject prompt_thing, faslgensyms, prinl_symbol, emsg_star,
           redef_msg;
LispObject current_function, expr_symbol, fexpr_symbol, macro_symbol;
LispObject big_divisor, big_dividend, big_quotient, big_fake1,
           big_fake2;
LispObject active_stream, current_module;
LispObject autoload_symbol, features_symbol, lisp_package;
LispObject sys_hash_table, sxhash_hash_table;
LispObject help_index, cfunarg, lex_words, get_counts, fastget_names;
LispObject input_libraries, output_library, current_file,
           break_function;
LispObject standard_output, standard_input, debug_io;
LispObject error_output, query_io, terminal_io, trace_output,
           fasl_stream;
LispObject startup_symbol, mv_call_symbol, traceprint_symbol,
           load_source_symbol;
LispObject load_selected_source_symbol, bytecoded_symbol,
           funcall_symbol;
LispObject gchook, resources, callstack, procstack, procmem,
           trap_time;
LispObject used_space, avail_space, eof_symbol, call_stack;
LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol,
           not_symbol;
LispObject reader_workspace, named_character, read_float_format,
           short_float;
LispObject single_float, double_float, long_float, bit_symbol,
           pathname_symbol;
LispObject print_array_sym, read_base, initial_element;
LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
LispObject builtin3_symbol, builtin4_symbol;

LispObject workbase[51];

LispObject user_base_0, user_base_1, user_base_2, user_base_3,
           user_base_4;
LispObject user_base_5, user_base_6, user_base_7, user_base_8,
           user_base_9;

LispObject eq_hash_tables;


LispObject *list_bases[] =
{   &current_package,
    &B_reg,
    &codevec,
    &litvec,
    &exit_tag,
    &exit_value,
    &catch_tags,
    &lisp_package,
    &boffo,
    &charvec,
    &sys_hash_table,
    &sxhash_hash_table,
    &help_index,
    &gensym_base,
    &err_table,
    &supervisor,
    &startfn,
    &faslvec,
    &tracedfn,
    &prompt_thing,
    &faslgensyms,
    &current_function,
    &active_stream,
    &current_module,
    &autoload_symbol,
    &big_divisor,
    &big_dividend,
    &big_quotient,
    &big_fake1,
    &big_fake2,
    &append_symbol,
    &applyhook,
    &cfunarg,
    &comma_at_symbol,
    &comma_symbol,
    &compiler_symbol,
    &comp_symbol,
    &cons_symbol,
    &list_symbol,
    &liststar_symbol,
    &eq_symbol,
    &eql_symbol,
    &cl_equal_symbol,
    &equal_symbol,
    &equalp_symbol,
    &go_symbol,
    &cond_symbol,
    &echo_symbol,
    &emsg_star,
    &evalhook,
    &eval_symbol,
    &expr_symbol,
    &features_symbol,
    &fexpr_symbol,
    &funarg,
    &function_symbol,
    &lambda,
    &lisp_true,
    &lower_symbol,
    &macroexpand_hook,
    &macro_symbol,
    &opt_key,
    &prinl_symbol,
    &progn_symbol,
    &quote_symbol,
    &raise_symbol,
    &redef_msg,
    &rest_key,
    &savedef,
    &string_char_sym,
    &unset_var,
    &work_symbol,
    &lex_words,
    &get_counts,
    &fastget_names,
    &input_libraries,
    &output_library,
    &current_file,
    &break_function,
    &lisp_work_stream,
    &lisp_standard_output,
    &lisp_standard_input,
    &lisp_debug_io,
    &lisp_error_output,
    &lisp_query_io,
    &lisp_terminal_io,
    &lisp_trace_output,
    &standard_output,
    &standard_input,
    &debug_io,
    &error_output,
    &query_io,
    &terminal_io,
    &trace_output,
    &fasl_stream,
    &mv_call_symbol,
    &startup_symbol,
    &traceprint_symbol,
    &load_source_symbol,
    &load_selected_source_symbol,
    &bytecoded_symbol,
    &funcall_symbol,
    &gchook,
    &resources,
    &callstack,
    &procstack,
    &procmem,
    &multiplication_buffer,
    &trap_time,
    &gcknt_symbol,
    &apply_symbol,
    &keyword_package,
    &all_packages,
    &package_symbol,
    &internal_symbol,
    &external_symbol,
    &inherited_symbol,
    &key_key,
    &allow_other_keys,
    &aux_key,
    &format_symbol,
    &expand_def_symbol,
    &allow_key_key,
    &declare_symbol,
    &special_symbol,
    &large_modulus,
    &used_space,
    &avail_space,
    &eof_symbol,
    &call_stack,
    &nicknames_symbol,
    &use_symbol,
    &and_symbol,
    &or_symbol,
    &not_symbol,
    &reader_workspace,
    &named_character,
    &read_float_format,
    &short_float,
    &single_float,
    &double_float,
    &long_float,
    &bit_symbol,
    &pathname_symbol,
    &print_array_sym,
    &read_base,
    &initial_element,
    &builtin0_symbol,
    &builtin1_symbol,
    &builtin2_symbol,
    &builtin3_symbol,
    &builtin4_symbol,
    &user_base_0,
    &user_base_1,
    &user_base_2,
    &user_base_3,
    &user_base_4,
    &user_base_5,
    &user_base_6,
    &user_base_7,
    &user_base_8,
    &user_base_9,
    &workbase[0],
    &workbase[1],
    &workbase[2],   // a.k.a mv_2
    &workbase[3],
    &workbase[4],
    &workbase[5],
    &workbase[6],
    &workbase[7],
    &workbase[8],
    &workbase[9],
    &workbase[10],
    &workbase[11],
    &workbase[12],
    &workbase[13],
    &workbase[14],
    &workbase[15],
    &workbase[16],
    &workbase[17],
    &workbase[18],
    &workbase[19],
    &workbase[20],
    &workbase[21],
    &workbase[22],
    &workbase[23],
    &workbase[24],
    &workbase[25],
    &workbase[26],
    &workbase[27],
    &workbase[28],
    &workbase[29],
    &workbase[30],
    &workbase[31],
    &workbase[32],
    &workbase[33],
    &workbase[34],
    &workbase[35],
    &workbase[36],
    &workbase[37],
    &workbase[38],
    &workbase[39],
    &workbase[40],
    &workbase[41],
    &workbase[42],
    &workbase[43],
    &workbase[44],
    &workbase[45],
    &workbase[46],
    &workbase[47],
    &workbase[48],
    &workbase[49],
    &workbase[50],
    nullptr              // Used to mark the end of the table.
};

// Create a tree with integer leaves in the range start..end (inclusive).

LispObject create(int start, int end)
{   if (start == end) return fixnum_of_int(start);
    int half = (start + end)/2;
    return cons(create(start, half),
                create(half+1, end));
}

static int n;

// Perform a pre-order search of the given tree checking if the
// nodes are in sequence starting with the value start and ending with end.

LispObject saved;

void verify(LispObject p)
{   if (is_fixnum(p))
    {   if (int_of_fixnum(p) != n)
        {   cout << endl << "Found " << int_of_fixnum(p)
                 << " but expected " << n << endl;
            crudeprint(saved);
            dump_gets();
            my_abort();
        }
        n++;
        return;
    }
    else if (!is_cons(p))
    {   cout << endl << "neither integer nor cons! " << std::hex << p << endl;
        crudeprint(saved);
        dump_gets();
        my_abort();
    }
    verify(car(p));
    verify(cdr(p));
}

void verify(LispObject p, int start, int end)
{   n = start;
    saved = p;
    verify(p);
    if (n != end+1)
    {   cout << endl << "At end got " << n << " but expected " << end+1 << endl;
        crudeprint(saved);
        dump_gets();
        my_abort();
    }
}

LispObject treetest(int k, int size)
{   LispObject a = nil, b = nil;
    for (int i=0; i<k; i++)
    {   a = create(1, size);
        b = create(1, size);
        verify(a, 1, size);
        verify(b, 1, size);
    }
    return a;
}

// End of contest.cpp
