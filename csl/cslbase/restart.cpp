// restart.cpp                             Copyright (C) 1989-2017 Codemist

//
// Code needed to start off Lisp when no initial heap image is available,
// or to re-instate links between heap and C-coded core if there IS a
// heap loaded.  This code is run in a state that is in effect (in-package
// "lisp").
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

extern int load_count, load_limit;

//
// machineid.c is a dynamically-created file that contains
//  (a) Identification of the type of object file used by this system.
//      In many cases this is the ELF magic code for the machine.
//  (b) Information about the command used to compile C code.
//  (c) Header files relating to the Lisp-to-C compilation process.
//
#include "machineid.cpp"

LispObject nil;
LispObject *stackbase;
LispObject * volatile stacklimit;

LispObject *nilsegment;
LispObject *stacksegment;
int32_t stack_segsize = 1;

char *exit_charvec = NULL;
intptr_t exit_reason;

intptr_t byteflip;
LispObject fringe;
LispObject volatile heaplimit;
LispObject volatile vheaplimit;
LispObject vfringe;
intptr_t nwork;
unsigned int exit_count;
uint64_t gensym_ser;
intptr_t print_precision, miscflags;
intptr_t current_modulus, fastget_size, package_bits, modulus_is_large;
LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
LispObject quote_symbol, function_symbol, comma_symbol, comma_at_symbol;
LispObject cons_symbol, eval_symbol, apply_symbol, work_symbol, evalhook;
LispObject applyhook, macroexpand_hook, append_symbol, exit_tag;
LispObject exit_value, catch_tags, keyword_package, current_package;
LispObject startfn, all_packages, package_symbol, internal_symbol;
LispObject gcknt_symbol, external_symbol, inherited_symbol;
LispObject gensym_base, string_char_sym, boffo;
LispObject key_key, allow_other_keys, aux_key;
LispObject err_table, format_symbol, progn_symbol, expand_def_symbol;
LispObject allow_key_key, declare_symbol, special_symbol, large_modulus;
LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol, echo_symbol;
LispObject codevec, litvec, supervisor, B_reg, savedef, comp_symbol;
LispObject compiler_symbol, faslvec, tracedfn, lisp_terminal_io;
LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
LispObject prompt_thing, faslgensyms, prinl_symbol, emsg_star, redef_msg;
LispObject current_function, expr_symbol, fexpr_symbol, macro_symbol;
LispObject big_divisor, big_dividend, big_quotient, big_fake1, big_fake2;
LispObject active_stream, current_module;
LispObject autoload_symbol, features_symbol, lisp_package, sys_hash_table;
LispObject help_index, cfunarg, lex_words, get_counts, fastget_names;
LispObject input_libraries, output_library, current_file, break_function;
LispObject standard_output, standard_input, debug_io;
LispObject error_output, query_io, terminal_io, trace_output, fasl_stream;
LispObject startup_symbol, mv_call_symbol, traceprint_symbol, load_source_symbol;
LispObject load_selected_source_symbol, bytecoded_symbol, funcall_symbol;
LispObject gchook, resources, callstack, procstack, procmem, trap_time;
LispObject used_space, avail_space, eof_symbol, call_stack;
LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol, not_symbol;
LispObject reader_workspace, named_character, read_float_format, short_float;
LispObject single_float, double_float, long_float, bit_symbol, pathname_symbol;
LispObject print_array_sym, read_base, initial_element;
LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
LispObject builtin3_symbol, builtin4_symbol; 

LispObject workbase[51];

LispObject user_base_0, user_base_1, user_base_2, user_base_3, user_base_4;
LispObject user_base_5, user_base_6, user_base_7, user_base_8, user_base_9;

LispObject eq_hash_tables, equal_hash_tables;

//
// On an Intel 80x86 (because I am almost forced to) and on other machines
// (much more cheerfully, and for choice!) I will arrange my memory as
// a number of pages.  A general pool of these pages gets used
// to satisfy requests for heap and vector heap space.
//
// Since this code was first written it has become silly to even consider
// computers with 16-bit segmented addressing! It is still convenient to
// allocate memory in chunks, although that does set an upper limit to the
// size of any individual object: this may hurt if a user wants a big vector
// and it does constrain the range of big-numbers supported by the
// artithmetic.
//

void **pages,
     **heap_pages,
     **vheap_pages;
void **new_heap_pages,
     **new_vheap_pages;

#ifdef CONSERVATIVE

page_map_t *page_map;

#endif

int32_t pages_count,
        heap_pages_count,
        vheap_pages_count;
int32_t new_heap_pages_count,
        new_vheap_pages_count;

char program_name[64] = {0};

//
// The tables here are slightly oddly formatted. Every other entry is
// NULL (reserved for other uses...) and each string has a single character
// stuck on its front that is also used as a marker elsewhere...
//

char **loadable_packages = NULL, **switches = NULL;

bool trap_floating_overflow = true;

int procstackp;

entry_point0 entries_table0[] =
{
    {0,                                 "illegal"},
    {undefined0,                        "undefined0"},
    {NULL,                              "dummy"}
};

#define entry_table_size0 ((int)(sizeof(entries_table0)/sizeof(entries_table0[0])))

entry_point1 entries_table1[] =
{
//
// All values that can go in the function cells of symbols to stand for
// special interpreter activity are kept here. In most cases where there
// is an entrypoint there is a corresponding one that behaves just the
// same except that it has tracing enabled.
//
    {0,                                  "illegal"},
// A few special forms that are set up manually so slip through the normal
// scheme...
    {quote_fn,                           "quote"},
    {progn_fn,                           "progn"},
    {declare_fn,                         "declare"},
    {function_fn,                        "function"},
    {undefined1,                         "undefined1"},
    {autoload1,                          "autoload1"},
    {interpreted1,                       "interpreted1"},
    {funarged1,                          "funarged1"},
    {bytecoded1,                         "bytecoded1"},
    {byteopt1,                           "byteopt1"},
    {hardopt1,                           "hardopt1"},
    {byteoptrest1,                       "byteoptrest1"},
    {hardoptrest1,                       "hardoptrest1"},
    {TOO_FEW_2,                          "too_few_2"},
    {WRONG_NO_0A,                        "wrong_no_0a"},
    {WRONG_NO_3A,                        "wrong_no_3a"},
    {WRONG_NO_NA,                        "wrong_no_na"},

//
// The batch here relate to function re-work that discards unwanted
// extra arguments.
//
    {f1_as_0,                            "1->0"},
    {f1_as_1,                            "1->1"},
    {NULL,                               "dummy"}
};

#define entry_table_size1 ((int)(sizeof(entries_table1)/sizeof(entries_table1[0])))

entry_point2 entries_table2[] =
{   {0,                                  "illegal"},
// A few special forms that are set up manually so slip through the normal
// scheme...
    {(two_args *)quote_fn,               "quote"},
    {(two_args *)progn_fn,               "progn"},
    {(two_args *)declare_fn,             "declare"},
    {(two_args *)function_fn,            "function"},
    {undefined2,                         "undefined2"},
    {autoload2,                          "autoload2"},
    {interpreted2,                       "interpreted2"},
    {funarged2,                          "funarged2"},
    {bytecoded2,                         "bytecoded2"},
    {byteopt2,                           "byteopt2"},
    {hardopt2,                           "hardopt2"},
    {byteoptrest2,                       "byteoptrest2"},
    {hardoptrest2,                       "hardoptrest2"},
    {TOO_MANY_1,                         "too_many_1"},
    {WRONG_NO_0B,                        "wrong_no_0b"},
    {WRONG_NO_3B,                        "wrong_no_3b"},
    {WRONG_NO_NB,                        "wrong_no_nb"},
//
// The batch here relate to function re-work that discards unwanted
// extra arguments.
//
    {f2_as_0,                            "2->0"},
    {f2_as_1,                            "2->1"},
    {f2_as_2,                            "2->2"},
    {NULL,                               "dummy"}
};

#define entry_table_size2 ((int)(sizeof(entries_table2)/sizeof(entries_table2[0])))

entry_point3 entries_table3[] =
{
    {0,                                 "illegal"},
    {undefined3,                        "undefined3"},
    {NULL,                              "dummy"}
};

#define entry_table_size3 ((int)(sizeof(entries_table3)/sizeof(entries_table3[0])))

entry_point4 entries_table4[] =
{
    {0,                                 "illegal"},
    {undefined4,                        "undefined4"},
    {NULL,                              "dummy"}
};

#define entry_table_size4 ((int)(sizeof(entries_table4)/sizeof(entries_table4[0])))

entry_pointn entries_tablen[] =
{   {0,                                  "illegal"},
    {undefinedn,                         "undefinedn"},
    {autoloadn,                          "autoloadn"},
    {interpretedn,                       "interpretedn"},
    {funargedn,                          "funargedn"},
    {bytecoded0,                         "bytecoded0"},
    {bytecoded3,                         "bytecoded3"},
    {bytecodedn,                         "bytecodedn"},
    {byteoptn,                           "byteoptn"},
    {hardoptn,                           "hardoptn"},
    {byteoptrestn,                       "byteoptrestn"},
    {hardoptrestn,                       "hardoptrestn"},
    {WRONG_NO_1,                         "wrong_no_1"},
    {WRONG_NO_2,                         "wrong_no_2"},
//
// The batch here relate to function variants that discard unwanted
// extra arguments and call something else.
//
    {f0_as_0,                            "0->0"},
    {f3_as_0,                            "3->0"},
    {f3_as_1,                            "3->1"},
    {f3_as_2,                            "3->2"},
    {f3_as_3,                            "3->3"},
    {NULL,                               "dummy"}
};

#define entry_table_sizen ((int)(sizeof(entries_tablen)/sizeof(entries_tablen[0])))

entry_pointn entries_tableio[] =
{   {0,                                          "illegal"},
    {(n_args *)char_from_illegal,                "char_from_illegal"},
    {(n_args *)char_to_illegal,                  "char_to_illegal"},
    {(n_args *)read_action_illegal,              "read_action_illegal"},
    {(n_args *)write_action_illegal,             "write_action_illegal"},
    {(n_args *)char_from_terminal,               "char_from_terminal"},
    {(n_args *)char_to_terminal,                 "char_to_terminal"},
    {(n_args *)read_action_terminal,             "read_action_terminal"},
    {(n_args *)write_action_terminal,            "write_action_terminal"},
    {(n_args *)char_from_file,                   "char_from_file"},
    {(n_args *)char_to_file,                     "char_to_file"},
    {(n_args *)read_action_file,                 "read_action_file"},
    {(n_args *)read_action_output_file,          "read_action_output_file"},
    {(n_args *)write_action_file,                "write_action_file"},
    {(n_args *)binary_outchar,                   "binary_outchar"},
    {(n_args *)char_from_list,                   "char_from_list"},
    {(n_args *)char_to_list,                     "char_to_list"},
    {(n_args *)code_to_list,                     "code_to_list"},
    {(n_args *)read_action_list,                 "read_action_list"},
    {(n_args *)write_action_list,                "write_action_list"},
    {(n_args *)count_character,                  "count_character"},
    {(n_args *)char_to_pipeout,                  "char_to_pipeout"},
    {(n_args *)write_action_pipe,                "write_action_pipe"},
    {(n_args *)char_from_synonym,                "char_from_synonym"},
    {(n_args *)char_to_synonym,                  "char_to_synonym"},
    {(n_args *)read_action_synonym,              "read_action_synonym"},
    {(n_args *)write_action_synonym,             "write_action_synonym"},
    {(n_args *)char_from_concatenated,           "char_from_concatenated"},
    {(n_args *)char_to_broadcast,                "char_to_broadcast"},
    {(n_args *)read_action_concatenated,         "read_action_concatenated"},
    {(n_args *)write_action_broadcast,           "write_action_broadcast"},
    {(n_args *)char_from_echo,                   "char_from_echo"},
    {NULL,                                       "dummy"}
};

#define entry_table_sizeio ((int)(sizeof(entries_tableio)/sizeof(entries_tableio[0])))

void *allocate_page(const char *why)
{   if (pages_count == 0) fatal_error(err_no_store);
    return pages[--pages_count];
}

static char *global_handle;

void *my_malloc(size_t n)
{
//
// The idea here is INTENDED to provide a small amount of extra checking and
// robustness about use of malloc and free. It is very probable these days
// that I would do MUCH better to use a well-developed separate package
// to help me out here - eg I understand that "valgrind" is useful for
// detecting memory leaks...
//
    char *r = (char *)(*malloc_hook)(n+64);
    int32_t *p = (int32_t *)quadword_align_up(r);
//
//    | ... |   :   |    |    |    |    |    |    | to user |    |    |
//    r     p <-r->    n  55aa 1234 3456 1234 3456           8765 cba9
// where p is quadword aligned whatever r is.
//
//
    if (r == NULL) return NULL;
    n = quadword_align_up(n);
    inject_randomness((int)(intptr_t)r);
    if (!SIXTY_FOUR_BIT) p[1] = 0;
    *(void **)(p) = r;                 // base address for free()
    *(int64_t *)(&p[2]) = (int64_t)n;  // allow for 64-bit size
    p[4] = 0x12345678;            // Marker words for security
    p[5] = 0x3456789a;
    p[6] = 0x12345678;
    p[7] = 0x3456789a;
    r = (char *)&p[8];
    car32(r+n)   = 0x87654321;
    car32(r+n+4) = 0xcba98765;
    return (void *)r;
}

char *big_chunk_start, *big_chunk_end;

static void my_free(void *r)
{   int32_t *p, *q;
    size_t n;
    char *rr = (char *)r;
//
// I will not free it if the pointer is strictly inside the single big
// chunk that I grabbed at the start of the run.
//
    if (rr > big_chunk_start && rr <= big_chunk_end) return;
    p = (int32_t *)r - 8;
    n = (size_t)*(int64_t *)(&p[2]);
    if (p[4] != 0x12345678 ||
        p[5] != 0x3456789a)
    {   term_printf("Corruption at start of memory block %p: %.8x %.8x\n",
                    r, p[4], p[5]);
        ensure_screen();
        my_exit(0);
    }
    q = (int32_t *)((char *)r + n);
    if (q[0] != (int32_t)0x87654321 ||
        q[1] != (int32_t)0xcba98765)
    {   term_printf("Corruption at end of memory block %p: %.8x %.8x\n",
                    r, q[0], q[1]);
        ensure_screen();
        my_exit(0);
    }
    (*free_hook)((void *)((void **)p)[0]);
}

static void *my_malloc_1(size_t n)
//
// This is a pretty silly function - it gobbles up 24Kbytes of
// stack and then just calls malloc - it stuffs a pointer to the
// stack-chunk into a static variable so that compilers can not
// detect (I hope!) that the array remains unused.  The purpose of this
// is to make malloc fail if it is about to encroach on space that
// should be used for stack.  This is relevant on small systems where
// stack and heap grow towards one another and where one space has been
// grabbed by malloc it is unavailable for stack (even if it is FREEd).
// The number 24000 is pretty arbitrary - but if I have 24K bytes of stack
// I will be able to do at least something.
// Also this code verifies that the memory addresses returned have the
// correct most significant bit. I allocate just a bit more memory than
// is really needed to leave a one-word (or so) guard-band between
// allocated blocks. This is necessary on some releases of an SGI C
// compiler (library) where blocks of memory that are word but not
// doubleword aligned can be returned.
//
{   char gobble_stack[24000];
    char *r;
    intptr_t pun, pun1;
    global_handle = gobble_stack;
    r = (char *)my_malloc(n+16);
    pun = (intptr_t)r;
    pun1 = (intptr_t)(r + n);
//
// I will moan if the block of memory allocated spans zero.
// Note that if this does happen then something very funny is happening
// about 0 cast to a pointer (i.e. a NULL pointer) since NULL is supposed
// not to be valid as an address (?) but appears to be within the address
// range of the block of store just allocated.
//
    if ((intptr_t)(pun ^ pun1) < 0) fatal_error(err_mem_spans_zero);
//
// Now if I get a block with the "wrong" top bit I will just return NULL
// to suggest that no more memory was available - CSL can then proceed
// or fail as it sees fit.
//
//
// For dynamic address sign I should not test the address sign on the
// first call - instead I just remember what it was.  On subsequent calls
// I will check it.
//
    return (void *)r;
}

static void *my_malloc_2(size_t n)
//
// Rather like my_malloc_1(), but does NOT check the sign bit of the
// returned pointer. Provided as a place to put hooks to check memory
// allocation problems.
//
{   char gobble_stack[24000];
    char *r;
    global_handle = gobble_stack;
    r = (char *)my_malloc(n+16);
    return (void *)r;
}

static LispObject Lreclaim_trap(LispObject env, LispObject a)
{   int64_t previous = reclaim_trap_count;
    if (!is_fixnum(a)) aerror1("reclaim-trap", a);
    reclaim_trap_count = int_of_fixnum(a);
    term_printf("+++ Reclaim trap set at %d, previous = %d\n",
                reclaim_trap_count, previous);
    return onevalue(fixnum_of_int(previous));
}

static LispObject Lreclaim_stack_limit(LispObject env, LispObject a)
{   intptr_t previous = reclaim_stack_limit;
    if (!is_fixnum(a)) aerror1("reclaim-stack-limit", a);
    reclaim_stack_limit = int_of_fixnum(a);
    term_printf("+++ Reclaim stack limit set at %d, previous = %d\n",
                reclaim_stack_limit, previous);
    return onevalue(fixnum_of_int(previous));
}

static void init_heap_segments(double store_size)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double not
// an integer so that overflow is not an issue.
//
{   const char *memfile = "memory.use"; // For memory statistics etc
    pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
#ifdef CONSERVATIVE
    page_map = (page_map_t *)my_malloc_2(MAX_PAGES*sizeof(page_map_t));
#endif
    heap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    vheap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    new_heap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    new_vheap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    if (pages == NULL ||
#ifdef CONSERVATIVE
        page_map == NULL ||
#endif
        new_heap_pages == NULL ||
        new_vheap_pages == NULL ||
        heap_pages == NULL ||
        vheap_pages == NULL)
    {   fatal_error(err_no_store);
    }

    {   intptr_t free_space = SIXTY_FOUR_BIT ? 128000000 : 32000000;
        intptr_t request;
        request = (intptr_t)store_size;
// By doing this in intptr_t I should avoid overflow
        if (request != 0) free_space = 1024*request;
        free_space = free_space/(CSL_PAGE_SIZE+4);
        if (free_space > MAX_PAGES) free_space = MAX_PAGES;
        pages_count = heap_pages_count = vheap_pages_count = 0;
//
// I grab memory using a function called my_malloc_1(), which verifies that
// all addresses used in the heap have the same top bit.  The very first time
// it is called nilsegment will be NULL - that time it does less checking.
//
        nilsegment = NULL;
        {   size_t n = (size_t)(NIL_SEGMENT_SIZE+free_space*(CSL_PAGE_SIZE+16));
//
// I try to get the whole of the initial hunk of memory that I need in
// one gulp since that (maybe) gives me the best chance to obtain all
// the memory in just one half of my address space.
//
            char *pool = (char *)my_malloc_1(n);
//
// I get 8 bytes more than seems necessary because I will need to
// align my page frames up to a doubleword boundary, and that can
// potentially waste 7 bytes.
//
            if (pool != NULL)
            {   big_chunk_start = (char *)pool;
                big_chunk_end = big_chunk_start + (n-1);
                nilsegment = (LispObject *)pool;
                pool = pool + NIL_SEGMENT_SIZE;
#ifdef COMMON
// NB here that NIL is tagged as a CONS not as a symbol
                nil = doubleword_align_up(nilsegment) + TAG_CONS + 8;
#else
                nil = doubleword_align_up(nilsegment) + TAG_SYMBOL;
#endif
//
// If at the end of the run I am going to free some space I had better not
// free these pages. When I free the nilsegment they all get discarded at
// once. Observe here that the page that will be at the top of the list of
// pages will be the one with the higher address, and pages here will
// all be contiguous. So if I merely grab two pages from here I may
// view them as a single double-sized one. Since I will normally grab
// from the top of the pile it will be the second one that I grab that
// is the base of the double-page. This feels close to cheating!
//
                while (pages_count < free_space)
                {   void *page =
//
// Ha Ha - for some long while I had a buf whereby I missed out the cast
// to size_t here and as a result if you asked for over 4G of memory
// there was an integer overflow in the subscript calculation leading to
// reasonably obscure disaster.
//
                        (void *)&pool[pages_count*
                                      (size_t)(CSL_PAGE_SIZE+16)];
                    pages[pages_count++] = page;
                }
            }
        }
    }

//
// I allocate a stack segment first because I will use it as buffer space for
// decompressing the contents of an image file. It will come out of the
// initial contiguous block.
// If the user had asked for an oversize stack it has to be allocated
// independently here anyway.
//
    if (nilsegment != NULL && pages_count > 0)
    {   if (stack_segsize != 1)
        {   stacksegment =
                (LispObject *)my_malloc(stack_segsize*CSL_PAGE_SIZE + 16);
            if (stacksegment == NULL)
                fatal_error(err_no_store);
        }
        else stacksegment = (LispObject *)pages[--pages_count];
    }
    else
    {   printf("pages_count <= 0 = %d\n", pages_count);
        fatal_error(err_no_store);
    }
    CSL_MD5_Update((unsigned char *)memfile, 8);
//
// The stack does not need to be doubleword aligned, but it does need
// to be word aligned (otherwise certain back-pointers in the garbage
// collector give trouble), so I fix it up here.  Note that stacksegment
// remains pointing at the original base so that I can free() it later.
//
    stackbase = (LispObject *)doubleword_align_up((intptr_t)stacksegment);
}

static void abandon(void *p[], int32_t n)
{   while (n != 0)
    {   void *w = p[--n];
//
// The test here that avoids calling free on a NULL pointer is
// certainly not needed with an ANSI compliant library - but
// rumour has it that many Unix libraries are unkind in this
// respect, and the test is pretty cheap...
//
        if (w != NULL) my_free(w);
    }
}

void drop_heap_segments(void)
{   abandon(pages,           pages_count);
    abandon(heap_pages,      heap_pages_count);
    abandon(vheap_pages,     vheap_pages_count);
    my_free(stacksegment);
    my_free(nilsegment);
}

static char *find_checksum(const char *name, int32_t len, const setup_type *p)
{   char *n;
    while (p->name != NULL) p++;
    n = (char *)p->one;
    if (strlen(n) == (size_t)len && memcmp(name, n, len) == 0)
        return (char *)p->two;
    else return NULL;
}

setup_type const *setup_tables[] =
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
//
// I also include the kernel setup tables, but I put a NULL in this
// table so it is easy to see where they start.
//
    NULL,
    arith06_setup, arith08_setup, arith10_setup, arith12_setup,
    arith13_setup, char_setup, eval1_setup, eval2_setup, eval3_setup,
    funcs1_setup, funcs2_setup, funcs3_setup, lisphash_setup,
    newhash_setup, print_setup, read_setup, restart_setup, mpi_setup,
    NULL
};

//
// If C code is to be instated (via c!:install calls in u01.lsp etc) there
// needs to be a verification that the file u01.c and the file u01.lsp (etc)
// are in step. So once for each such file this does the check. It should
// only happen when the system is being built and ought not to be a big
// performance issue.
//

static LispObject Lcheck_c_code(LispObject env, int nargs, ...)
{   LispObject name, lc1, lc2, lc3;
    int32_t c1=-1, c2=-1, c3=-1;
    long int x1=-2, x2=-2, x3=-2;
    int32_t len;
    va_list a;
    char *p;
    const char *sname;
    size_t i;
    argcheck(nargs, 4, "check-c-code");
    va_start(a, nargs);
    name = va_arg(a, LispObject);
    lc1 = va_arg(a, LispObject);
    lc2 = va_arg(a, LispObject);
    lc3 = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(name) ||
        !is_string_header(vechdr(name)) ||
        !is_fixnum(lc1) ||
        !is_fixnum(lc2) ||
        !is_fixnum(lc3)) aerror1("check-c-code", name);
    c1 = int_of_fixnum(lc1);
    c2 = int_of_fixnum(lc2);
    c3 = int_of_fixnum(lc3);
    sname = &celt(name, 0);
    len = length_of_byteheader(vechdr(name)) - CELL;

    p = NULL;
    for (i=0; setup_tables[i]!=NULL; i++)
    {   if ((p = find_checksum(sname, len, setup_tables[i])) != NULL) break;
    }
    if (p == NULL) aerror1("check-c-code", name);

    if (sscanf(p, "%ld %ld %ld", &x1, &x2, &x3) != 3)
        aerror1("check-c-code", name);
    if (c1 == x1 && c2 == x2 && c3 == x3) return onevalue(nil);
    err_printf("\n+++++ C code and environment files not compatible\n");
    err_printf("please check, re-compile and try again\n");
    err_printf("versions from %.*s.c %lx %lx %lx\n", len, sname, x1, x2, x3);
    err_printf("version passed here %lx %lx %lx\n", c1, c2, c3);
    aerror1("check-c-code", name);
}

setup_type const restart_setup[] =
//
// things that are in modules that do not define enough Lisp entrypoints
// to be worth giving separate entry-tables.
//
{
    {"~load-spid",              WRONG_NO_NA, WRONG_NO_NB, Lload_spid},
    {"~is-spid",                Lis_spid, TOO_MANY_1, WRONG_NO_1},
    {"~spid-to-nil",            Lspid_to_nil, TOO_MANY_1, WRONG_NO_1},
    {"~mv-list",                Lmv_list, TOO_MANY_1, WRONG_NO_1},
    {"check-c-code",            WRONG_NO_NA, WRONG_NO_NB, Lcheck_c_code},
    {"modulep",                 Lmodule_exists, TOO_MANY_1, WRONG_NO_1},
    {"start-module",            Lstart_module, TOO_MANY_1, WRONG_NO_1},
    {"write-module",            TOO_FEW_2, Lwrite_module, WRONG_NO_2},
    {"copy-module",             Lcopy_module, TOO_MANY_1, WRONG_NO_1},
    {"delete-module",           Ldelete_module, TOO_MANY_1, WRONG_NO_1},
    {"load-module",             Lload_module, TOO_MANY_1, WRONG_NO_1},
    {"load-source",             Lload_source, TOO_MANY_1, Lload_source0},
    {"load-selected-source",    Lload_selected_source, TOO_MANY_1, Lload_selected_source0},
    {"list-modules",            WRONG_NO_NA, WRONG_NO_NB, Llist_modules},
    {"writable-libraryp",       Lwritable_libraryp, TOO_MANY_1, WRONG_NO_1},
    {"library-members",         Llibrary_members, TOO_MANY_1, Llibrary_members0},
    {"startup-banner",          Lbanner, TOO_MANY_1, WRONG_NO_1},
    {"set-help-file",           TOO_FEW_2, Lset_help_file, WRONG_NO_2},
    {"mapstore",                Lmapstore, TOO_MANY_1, Lmapstore0},
    {"verbos",                  Lverbos, TOO_MANY_1, WRONG_NO_1},
    {"gc",                      Lgc, TOO_MANY_1, Lgc0},
    {"reclaim",                 Lgc, TOO_MANY_1, Lgc0},
    {"reclaim-trap",            Lreclaim_trap, TOO_MANY_1, WRONG_NO_1},
    {"reclaim-stack-limit",     Lreclaim_stack_limit, TOO_MANY_1, WRONG_NO_1},
    {"resource-limit",          TOO_FEW_2, Lresource_limit2, Lresource_limitn},
    {"errorset",                Lerrorset1, Lerrorset2, Lerrorsetn},
    {NULL,                      0, 0, 0}
};


static void create_symbols(setup_type const s[], int restart_flag)
{   size_t i;
    for (i=0; s[i].name != NULL; i++)
        make_symbol(s[i].name, restart_flag, s[i].one, s[i].two, s[i].n);
}

static int32_t defined_symbols;

static void count_symbols(setup_type const s[])
{   size_t i;
    for (i=0; s[i].name != NULL; i++) defined_symbols++;
}

#ifndef EMBEDDED
static setup_type_1 *find_def_table(LispObject mod, LispObject checksum);
#endif

typedef struct dynamic_modules
{   char *name;
    setup_type_1 *entries;
} dynamic_modules;

static dynamic_modules *loaded_dynamic_modules = NULL;
static unsigned int loaded_dynamic_count = 0 , loaded_dynamic_size = 0;

//
// A real curiosity of my implementation is that find_dynamic_module
// takes a char * and a length. The "string" it is given need not be
// properly terminated with a "\0". The string data might be transient.
// in contrase, record_dynamic_module takes a normal-style C string (which
// of course is terminated with '\0', and it requires that the string
// data is non-transient. BEWARE if you try to use these at some stage in the
// future.
//
static setup_type_1 *find_dynamic_module(char *name, size_t len)
{   unsigned int hash = 0;
    size_t i;
    char *p = name;
    if (loaded_dynamic_size == 0) return NULL;
    for (i=0; i<len; i++) hash=169*hash+(*p++ & 0xff);
    hash %= loaded_dynamic_size;
    for (;;)
    {   if (loaded_dynamic_modules[hash].name == NULL) return NULL;
        if (strncmp(name, loaded_dynamic_modules[hash].name, len) == 0 &&
            strlen(loaded_dynamic_modules[hash].name) == len)
            return loaded_dynamic_modules[hash].entries;
        hash = (hash + 1) % loaded_dynamic_size;
    }
}

//
// The constant here must be a prime number.
//
#define INITIAL_DYNAMIC_MODULE_HASH_SIZE 1009

static void record_dynamic_module(char *name, setup_type_1 *entries)
{   unsigned int hash;
    char *p;
    loaded_dynamic_count++;
    if (3*loaded_dynamic_count >= 2*loaded_dynamic_size)
    {   dynamic_modules *newtable;
        uint32_t newsize; // so I can use isprime()
        size_t i;
        if (loaded_dynamic_size == 0)
            newsize = INITIAL_DYNAMIC_MODULE_HASH_SIZE;
        else
        {   newsize = 2*loaded_dynamic_size-1;
            while (!isprime(newsize)) newsize+=2;
        }
#ifdef TRACE_NATIVE
        trace_printf("Hash needs to grow from %d to %d\n", loaded_dynamic_size, newsize);
        ensure_screen();
#endif
        newtable = (dynamic_modules *)
                   malloc(newsize*sizeof(dynamic_modules));
        for (i=0; i<newsize; i++) newtable[i].name = NULL;
        for (i=0; i<loaded_dynamic_size; i++)
        {   if ((p = loaded_dynamic_modules[i].name) == NULL) continue;
            hash = 0;
            while (*p != 0) hash=169*hash+(*p++ & 0xff);
//
// I will leave the trace print here when I rehash so that I spot cases of
// rehashing in case to increase the chance of spotting associated bugs.
// I will also start with a small hash table so that repeated rehashing is
// provoked.
//
#ifdef TRACE_NATIVE
            trace_printf("Hash for %s is %x in REHASH\n", loaded_dynamic_modules[i].name, hash);
            ensure_screen();
#endif
            hash %= newsize;
            for (;;)
            {   if (newtable[hash].name == NULL)
                {   newtable[hash].name = loaded_dynamic_modules[i].name;
                    newtable[hash].entries = loaded_dynamic_modules[i].entries;
                    break;
                }
                hash = (hash + 1) % newsize;
            }
        }
        if (loaded_dynamic_size != 0) free(loaded_dynamic_modules);
        loaded_dynamic_modules = newtable;
        loaded_dynamic_size = newsize;
    }
    p = name;
    hash = 0;
    while (*p != 0) hash=169*hash+(*p++ & 0xff);
    hash %= loaded_dynamic_size;
    for (;;)
    {   if (loaded_dynamic_modules[hash].name == NULL)
        {   loaded_dynamic_modules[hash].name = name;
            loaded_dynamic_modules[hash].entries = entries;
            return;
        }
        if (strcmp(name, loaded_dynamic_modules[hash].name) == 0)
        {   loaded_dynamic_modules[hash].entries = entries;
            return;
        }
        hash = (hash + 1) % loaded_dynamic_size;
    }
}

static char dll_cache_directory[LONGEST_LEGAL_FILENAME] = {0};

static void find_dll_cache_directory()
{   unsigned char md[16];
    char userinfo[80], counts[8];
    int i;
#ifdef WIN32
    DWORD n;
#endif
    char *p;
    struct stat stbuf;
    int count;
    if (dll_cache_directory[0] != 0) return;
//
// This does its real work just once. But I may need to re-try
// if the first choice directory name does not work well.
//
    for (count=0; count<100; count++)
    {   CSL_MD5_Init();
        sprintf(counts, "%d:", count);
        CSL_MD5_Update((unsigned char *)counts, strlen(counts));
        CSL_MD5_Update((unsigned char *)fullProgramName,
                       strlen(fullProgramName));
#ifdef WIN32
        userinfo[0] = ';';
        n = sizeof(userinfo) - 1;
        if (!GetUserName(userinfo+1, &n)) strcpy(userinfo, ";UnknownUser;");
        else strcat(userinfo, ";");
        if (GetTempPath(LONGEST_LEGAL_FILENAME, dll_cache_directory) == 0)
            strcpy(dll_cache_directory, ".\\");
#else
        sprintf(userinfo, ";%d;", (int)geteuid());
        strcpy(dll_cache_directory, "/tmp/");
#endif
        CSL_MD5_Update((const unsigned char *)userinfo, strlen(userinfo));
        CSL_MD5_Update((const unsigned char *)linker_type, strlen(linker_type));
        CSL_MD5_Final(md);
#ifdef TRACE_NATIVE
        trace_printf("Base cache name on %s %s %s\n",
                     fullProgramName, userinfo, linker_type);
#endif
        p = dll_cache_directory + strlen(dll_cache_directory);
//
// The name of the directory that I invent will be the letters
// CSL followed by 25 characters (0-9, a-t) (ie 25*5-125 bits derived
// from an MD5 checksum).
//
        *p++ = 'C'; *p++ = 'S'; *p++ = 'L';
        for (i=0; i<25; i++)
        {   int j, w = 0;
            for (j=15; j>=0; j--)
            {   int w1 = (md[j] >> 5) | (w << 3);
                w = md[j] & 0x1f;
                md[j] = w1;
            }
            if (w < 10) *p++ = '0' + w;
            else *p++ = 'a' + w - 10;
        }
        *p = 0;
#ifdef TRACE_NATIVE
        trace_printf("DLL cache directory will be %s\n", dll_cache_directory);
#endif
//
// I should now verify that that directory exists and is readable and
// writable! If it is I am done. If not I will try to create it as
// a directory - if that works I can return. If that still does not help
// I will loop to try a second-choice name. If the "temporary directory"
// that I obtained did not exist this might loop I suppose, so anybody
// who sets the shell variable TEMP to something silly might get hurt? To
// avoid infinite pain I will just declare disaster if I do not succeed in
// a fair number of tries.
//
        if (stat(dll_cache_directory, &stbuf) == 0 &&
#ifdef S_IRUSR
            stbuf.st_mode & S_IRUSR &&
#endif
#ifdef S_IWUSR
            stbuf.st_mode & S_IWUSR &&
#endif
            (stbuf.st_mode & S_IFMT) == S_IFDIR) return;
        Cmkdir(dll_cache_directory);
        if (stat(dll_cache_directory, &stbuf) == 0 &&
#ifdef S_IRUSR
            stbuf.st_mode & S_IRUSR &&
#endif
#ifdef S_IWUSR
            stbuf.st_mode & S_IWUSR &&
#endif
            (stbuf.st_mode & S_IFMT) == S_IFDIR) return;
    }
//
// here 100 different attempts to find a suitable directory have all
// failed. I just give up!
//
    fatal_error(err_no_tempdir);
}

static char objname[LONGEST_LEGAL_FILENAME];

static void tidy_up_old_dlls(const char *name, int why, long int size)
{   const char *p = name, *q = objname;
//
// If the file I have found has a name rather like objname then I will delete
// it. So I will start to scanning past initial equal parts in the names.
//
    while ((*p)==(*q) && (*p)!=0)
    {   p++;
        q++;
    }
//
// Now if p is of the form (where nnn is numeric)
//    nnn-nnn-nnn.dll    or nnn-nnn-nnn.so
// it is an old DLL for the same module so it should go. I have
// some fairly grotty code here that is intended to detect this
// pattern. Well it is a bit messier than that - the first few chars of the
// checksum info may have matched...
//
    while (*p != 0 && isdigit((int)*p)) p++;
    if (*p == '-') p++;
    while (*p != 0 && isdigit((int)*p)) p++;
    if (*p == '-') p++;
    while (*p != 0 && isdigit((int)*p)) p++;
    if (strcmp(p, ".dll") != 0 &&
        strcmp(p, ".so") != 0) return;
#ifdef TRACE_NATIVE
    trace_printf("Deleting old DLL file %s\n", name);
#endif
    remove(name);
}

#ifndef EMBEDDED

static setup_type_1 *find_def_table(LispObject mod, LispObject checksum)
{   size_t len = 0, checklen = 0;
    const char *sname, *checkname;
    char modname[80], xmodname[LONGEST_LEGAL_FILENAME];
    char sname1[LONGEST_LEGAL_FILENAME];
    FILE *dest;
    int c;
    char setupname[80];
    char *p;
    setup_type_1 *dll;
    initfn *init;
#ifdef WIN32
    HMODULE a;
    UINT ww;
#else
    void *a;
#endif
    memset(modname, 0, sizeof(modname));
    memset(xmodname, 0, sizeof(xmodname));
    memset(sname1, 0, sizeof(sname1));
#ifdef TRACE_NATIVE
    trace_printf("find_def_table ");
    prin_to_trace(mod);
    trace_printf("\n");
    ensure_screen();
#endif

    sname = get_string_data(mod, "find_def_table", len);
    checkname = get_string_data(checksum, "find_def_table", checklen);
#ifdef TRACE_NATIVE
    trace_printf("Checksum given as \"%.*s\"\n", checklen, checkname);
#endif
    sprintf(sname1, "%.*s-%.*s", (int)len, sname, (int)checklen, checkname);
    p = sname1;
    while (*p!=0)
    {   if (*p == ' ') *p = '-';
        p++;
    }
    dll = find_dynamic_module(sname1, strlen(sname1));
    if (dll != NULL) return dll;
//
// I keep dynamically-loadable read code in the image where a module
// whose portable version is called foo.fasl might have a machine-specific
// variant foo.win32.fasl.
//
    sprintf(modname, "%.*s.%s", (int)len, sname, linker_type);

//
// Here I will do some more cache-style activity. I will hold a
// dirctory typically called /tmp/nnnnnn (where nnnnn is a checksum
// on fullProgramName and the linker type and the curren user)
// and put extracted DLL files there.
// If I find one present there I will use it. Otherwise I
// will extract it from the image file. This may give me trouble
// with regard to versioning, and so when I initially create or update
// a file in the image I should delete any cached version as outdated.
// (that last bit not done to start with)
//
    find_dll_cache_directory();

#ifdef TRACE_NATIVE
    trace_printf("Attempt to load module %s\n", modname);
#endif
//
// Now if dll_cache_directory/sname.[so/dll] exists I will use it.
// otherwise I will create it by copying from the image file.
// The name I use here will include checksum information. At some stage
// I should possibly try to delete any files in the cache that match in
// their root but disagree in the checksum portion, since they are liable
// to be old.
//
#ifdef WIN32
    sprintf(objname, "%s\\%s.dll", dll_cache_directory, sname1);
#else
    sprintf(objname, "%s/%s.so", dll_cache_directory, sname1);
#endif
#ifdef TRACE_NATIVE
    trace_printf("Invented name %s for temp location of module\n", objname);
#endif
    {   struct stat stbuf;
//
// Check if the module exists in the cache - if not try to create it...
// I count the DLL as unavailable if either stat fails (which may indicate
// that the file does not exist) or if it is not readable by its owner
// (who ought to be me!). Not if it is not readable it may not be writable
// either, and in that case the attempt here to create it will fail.
//
        if (stat(objname, &stbuf) != 0
#ifdef S_IRUSR
            || (stbuf.st_mode & S_IRUSR) == 0
#endif
           )
        {   if (Iopen(modname, strlen(modname), IOPEN_IN, xmodname))
            {   trace_printf("module not found\n");
                return NULL;
            }

#ifdef TRACE_NATIVE
            trace_printf("Will now copy %s to the DLL cache\n", modname);
#endif
//
// Here I can tidy up the cache directory. I want to DELETE any files in
// it whose names are somewhat similar to the one I am about to create.
// Just for now I will just print a message ratherthan actually do anything.
//
            set_hostcase(1);
            scan_files(dll_cache_directory, tidy_up_old_dlls);
//
// Here I can read and process the module...
//
            dest = fopen(objname, "wb");
            if (dest == NULL)              // failed to write to temp file
            {   IcloseInput();
                return NULL;
            }
// This uses Igets not Zgetc because it wants to access the raw compressed
// data so it can just copy it across. At least at present if I ever have
// DLLs nested within the image file I will put them there uncompressed.
            while ((c = Igetc()) != EOF)
                putc(c, dest);
            IcloseInput();
            if (fclose(dest) != 0)
            {   trace_printf("failed to write DLL to temp directory\n");
                return NULL;
            }
        }
    }
//
// Now I have copied the object file data to a "real" but temporary file.
//
    sprintf(modname, "%.*s", (int)len, sname);

#ifdef TRACE_NATIVE
    trace_printf("load_dynamic for find_def_table %s %s\n", objname, modname);
#endif
    sprintf(setupname, "%s_setup", modname);
    for (p=setupname; *p!=0; p++)
        if (*p=='-') *p='_';
#ifdef TRACE_NATIVE
    trace_printf("Look for \"%s\"\n", setupname);
#endif
#ifdef WIN32
//
// In various cases of failure Windows has a default behaviour of popping
// up a dialog box when a DLL can not be loaded. I do not want that, since
// I intend to recover graciously if the module can not be located or
// loaded.
//
    ww = SetErrorMode(SEM_FAILCRITICALERRORS);
#ifdef TRACE_NATIVE
    trace_printf("Loading DLL called %s for %s\n", objname, modname);
#endif
    a = LoadLibrary(objname);
    if (a == 0)
    {   DWORD err = GetLastError(), err1;
        LPTSTR errbuf = NULL;
//
// If I let Windows pop up its message box I still seem to get more info
// than FormatMessage presents me with... Specifically if the module I tried
// to load refused to because of a symbol that it needed to load, the
// pop up tells me the name of that symbol.
//
        err1 = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
                             FORMAT_MESSAGE_ALLOCATE_BUFFER |
                             FORMAT_MESSAGE_IGNORE_INSERTS,
                             NULL,
                             err,
                             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                             (LPTSTR)&errbuf,
                             0,
                             NULL);
        if (err1 == 0 || errbuf==NULL)
            trace_printf("FormatMessage on code %d failed with %d\n",
                         (int)err, (int)GetLastError());
        else
        {   trace_printf("%s", errbuf);
            LocalFree(errbuf);
        }
    }
    SetErrorMode(ww);
#ifdef TRACE_NATIVE
    trace_printf("Dynamic loading of test code\na = %p\n", (void *)a);
#endif
    if (a == 0) return 0;
    dll = (setup_type_1 *)GetProcAddress(a, setupname);
//
// The dynamic module that I create should always have a function called
// "init" that I must call to tell it where nil, stack and stacklimit are.
//
    init = (initfn *)GetProcAddress(a, "init");
#else // WIN32
    a = dlopen(objname, RTLD_NOW | RTLD_GLOBAL);
#ifdef TRACE_NATIVE
    trace_printf("a = %p\n", a);
#endif
    if (a == NULL)
    {   trace_printf("Err = <%s>\n", dlerror()); fflush(stdout);
        return 0;
    }
    dll = (setup_type_1 *)dlsym(a, setupname);
    init = (initfn *)dlsym(a, "init");
#endif // WIN32
#ifdef TRACE_NATIVE
    trace_printf("setup table is %p, init fn is %p\n", dll, init);
#endif
    if (dll == NULL || init == NULL)
    {
#ifdef WIN32
        FreeLibrary(a);
#endif
        return NULL;
    }
    (*init)(&nil, &stack, &stacklimit);
//
// Wheee - I have now loaded and initialised the module.
//
#ifdef TRACE_NATIVE
    {   setup_type_1 *b = dll;
        while (b->name != NULL)
        {   trace_printf("%s %p %p %p %u %u\n",
                         b->name, b->one, b->two, b->n, b->c1, b->c2);
            b++;
        }
        trace_printf("%s %s\n", (char *)(b->one), (char *)(b->two));
    }
#endif
//
//  remove(objname);
// At one stage I wanted to count the DLL files as temporary - but now I keep
// them all in a cache directory, so I really do NOT want to delete them
// here... If the user deletes them that will not be a problem - they will get
// re-created if necessary.
//

//
// Update the cache...
//
    p = (char *)malloc(strlen(sname1)+1);
    strcpy(p, sname1);
    p[len] = 0;
    record_dynamic_module(p, dll);
    return dll;
}

#endif // EMBEDDED

static void cold_setup()
{   LispObject w;
    void *p = allocate_page("vheap cold setup");
    vheap_pages[vheap_pages_count++] = p;
    vfringe = (LispObject)(8 + (char *)doubleword_align_up((intptr_t)p));
    vheaplimit = (LispObject)((char *)vfringe + (CSL_PAGE_SIZE - 16));

    p = heap_pages[heap_pages_count++] = allocate_page("heap cold setup");
    heaplimit = quadword_align_up((intptr_t)p);
    fringe = (LispObject)((char *)heaplimit + CSL_PAGE_SIZE);
    heaplimit = (LispObject)((char *)heaplimit + SPARE);

    miscflags = 3;
    qplist(nil) = nil;
    qfastgets(nil) = nil;
    qenv(nil) = nil;        // points to self in undefined case
    ifn1(nil) = (intptr_t)undefined1;
    ifn2(nil) = (intptr_t)undefined2;
    ifnn(nil) = (intptr_t)undefinedn;
    qheader(nil) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_GLOBAL_VAR;
    qvalue(nil) = nil;
//
// When I am debugging CSL I can validate the heap, for instance whenever
// I allocate vector. The call to make_string here does that, and so I MUST
// have a tidy world in place here.
//
    qpname(nil) = nil;
    for (LispObject **p=list_bases; *p!=NULL; p++) **p = nil;
    eq_hash_tables = equal_hash_tables = nil;
#ifdef COMMON
    qpackage(nil) = nil;
    qpname(nil) = make_string("NIL");
#else
    qpackage(nil) = nil;
    qpname(nil) = make_string("nil");
#endif
    qcount(nil) = 0;
    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;
    eq_hash_tables = equal_hash_tables = nil;

// The package I am using at present will always be a package object
// stored in the value cell of "current-package". But that symbol does not
// quite exist yet - so as a temporary provision I use the value cell of NIL.
    current_package = nil;
//
// The code here is generally coded on the supposition that there will NEVER
// be a garbage collection here, so all issues of error recovery related
// tests can be omitted. That makes this code much cleaner! It means that
// during a cold start that there is enough space (well for a COLD start that
// hardly likely to be an issue!) and in a warm start that none of the
// calls that make strings or symbols etc here trigger a genuine garbage
// collection - that can probably be assured by ensuring that on restart there
// is at least a little bit of space in hand.
//
    qvalue(nil) = getvector_init(sizeof(Package), nil);
#ifdef COMMON
    qpackage(nil) = qvalue(nil);    // For sake of restart code
    all_packages = ncons(qvalue(nil));
#else
    qpackage(nil) = qvalue(nil);
#endif

    packhdr_(CP) = TYPE_STRUCTURE + (packhdr_(CP) & ~header_mask);
#ifdef COMMON
    packname_(CP) = make_string("LISP");
#endif
//
// The size chosen here is only an initial size - the hash table in a package
// can grow later on if needbe - but I ought to ensure that the initial
// size is big enough for the built-in symbols that Lisp creates in
// this restart code.  The size must be a power of 2. I want the object
// table to have the same number of entries regardless of whether I am on
// a 32 or 64-bit machine to make cross-loading of images possible.
//
    packint_(CP) = getvector_init(CELL*(1+INIT_OBVECI_SIZE), fixnum_of_int(0));
    packvint_(CP) = fixnum_of_int(1);
    packflags_(CP) = fixnum_of_int(++package_bits);
#ifdef COMMON
//
// Common Lisp also has "external" symbols to allow for...
//
    packnint_(CP) = fixnum_of_int(0);
    packext_(CP) = getvector_init(CELL*(1+INIT_OBVECX_SIZE), fixnum_of_int(0));
    packvext_(CP) = fixnum_of_int(1);
    packnext_(CP) = fixnum_of_int(1); // Allow for nil
    {   size_t i = (int)(hash_lisp_string(qpname(nil)) &
                      (INIT_OBVECX_SIZE - 1));
        elt(packext_(CP), i) = nil;
    }
#else
    packnint_(CP) = fixnum_of_int(1); // Allow for nil
// Place NIL into the table.
    {   size_t i = (int)(hash_lisp_string(qpname(nil)) &
                      (INIT_OBVECI_SIZE - 1));
        elt(packint_(CP), i) = nil;
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
    boffo = getvector(TAG_VECTOR, TYPE_STRING_4, CELL+boffo_size);
    memset((void *)((char *)boffo + (CELL - TAG_VECTOR)), '@', boffo_size);
//
// The next line has hidden depths.  When it is obeyed during cold start
// the C variable *package* has the value nil, hence make_symbol
// looks in the value cell of nil to find the package to intern wrt. Once
// this has been done I can put nil back how it ought to have been!
//
    current_package          = make_undefined_symbol("*package*");
    qheader(current_package)|= SYM_SPECIAL_VAR;
    lisp_package = qvalue(current_package)  = qpackage(nil);
    qvalue(nil)              = nil;          // Whew!
    qpackage(nil) = qpackage(current_package) = lisp_package;

    B_reg = nil;                             // safe for GC
    unset_var                = make_undefined_symbol("~indefinite-value~");
    qheader(unset_var)      |= SYM_GLOBAL_VAR;
    qvalue(unset_var)        = unset_var;
    Lunintern(nil, unset_var);
//
// Now in some minor sense the world is in a self-consistent state
//
    lisp_true           = make_undefined_symbol("t");
    qheader(lisp_true) |= SYM_GLOBAL_VAR;
    qvalue(lisp_true)   = lisp_true;
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
    work_symbol         = make_undefined_symbol("~magic-internal-symbol~");
    Lunintern(nil, work_symbol);
    package_symbol      = make_undefined_symbol("package");
    packid_(CP)         = package_symbol;

    macroexpand_hook    = make_undefined_symbol("*macroexpand-hook*");
    qheader(macroexpand_hook) |= SYM_SPECIAL_VAR;
    evalhook            = make_undefined_symbol("*evalhook*");
    qheader(evalhook)  |= SYM_SPECIAL_VAR;
    qvalue(evalhook)    = nil;
    applyhook           = make_undefined_symbol("*applyhook*");
    qheader(applyhook) |= SYM_SPECIAL_VAR;
    qvalue(applyhook)   = nil;
#ifdef COMMON
    keyword_package     = make_undefined_symbol("*keyword-package*");
    qheader(keyword_package) |= SYM_GLOBAL_VAR;
    qvalue(keyword_package) = make_package(make_string("KEYWORD"));
    err_table           = make_undefined_symbol("*ERROR-MESSAGE*");
#else
    err_table           = make_undefined_symbol("*error-messages*");
#endif
    qheader(err_table) |= SYM_GLOBAL_VAR;
    qvalue(err_table)   = nil;
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
    read_float_format   = make_undefined_symbol("*read-default-float-format*");
    short_float         = make_undefined_symbol("short-float");
    single_float        = make_undefined_symbol("single-float");
    double_float        = make_undefined_symbol("double-float");
    long_float          = make_undefined_symbol("long-float");
    bit_symbol          = make_undefined_symbol("bit");
    pathname_symbol     = make_undefined_symbol("pathname");
    print_array_sym     = make_undefined_symbol("*print-array*");
    read_base           = make_undefined_symbol("*read-base*");
    initial_element     = make_undefined_symbol(":initial-element");

#define make_constant(name, value)       \
        w = make_undefined_symbol(name); \
        qheader(w) |= SYM_GLOBAL_VAR;   \
        qvalue(w) = value;
#define make_variable(name, value)       \
        w = make_undefined_symbol(name); \
        qheader(w) |= SYM_SPECIAL_VAR;   \
        qvalue(w) = value;
    make_constant("most-positive-fixnum", MOST_POSITIVE_FIXNUM);
    make_constant("most-negative-fixnum", MOST_NEGATIVE_FIXNUM);
    make_constant("pi",
                  make_boxfloat(3.141592653589793238, TYPE_DOUBLE_FLOAT));
    append_symbol       = make_undefined_symbol("append");
    raise_symbol        = make_undefined_symbol("*raise");
    lower_symbol        = make_undefined_symbol("*lower");
    echo_symbol         = make_undefined_symbol("*echo");
    comp_symbol         = make_undefined_symbol("*comp");
    compiler_symbol     = make_undefined_symbol("compile");
    current_function    = // system-startup
    startup_symbol      = make_undefined_symbol("system-startup");
    mv_call_symbol      = make_symbol("multiple-value-call", 0, mv_call_fn, NULL, BAD_SPECIALN);
    autoload_symbol     = make_undefined_symbol("autoload");
    bytecoded_symbol    = make_undefined_symbol("bytecoded-definition");
    traceprint_symbol   = make_undefined_symbol("trace-print");
    load_source_symbol  = make_symbol("load-source", 0, Lload_source, TOO_MANY_1, Lload_source0);
    load_selected_source_symbol =
                          make_symbol("load-selected-source", 0, Lload_selected_source, TOO_MANY_1, Lload_selected_source0);
    prinl_symbol        = make_symbol("prinl", 0, Lprin, TOO_MANY_1, WRONG_NO_1);
    emsg_star           = make_undefined_symbol("emsg*");
    redef_msg           = make_undefined_symbol("*redefmsg");
    expr_symbol         = make_undefined_symbol("expr");
    fexpr_symbol        = make_undefined_symbol("fexpr");
    macro_symbol        = make_undefined_symbol("macro");
    break_function      = make_undefined_symbol("*break-loop*");
    gchook              = make_undefined_symbol("*gc-hook*");
    resources           = make_undefined_symbol("*resources*");
    used_space          = make_undefined_symbol("*used-space*");
    avail_space         = make_undefined_symbol("*avail-space*");
    gcknt_symbol        = make_variable("gcknt*", fixnum_of_int(0));
// Note that end-of-file is represented by an odd Unicode value (in UTF-8)
    eof_symbol          = make_undefined_symbol("\xf4\x8f\xbf\xbf");
    call_stack          = nil;
    trap_time           = make_undefined_symbol("trap-time*");
//  count_high          = make_undefined_symbol("count-high*");
    qheader(lower_symbol) |= SYM_SPECIAL_VAR;
    qheader(echo_symbol)  |= SYM_SPECIAL_VAR;
    qheader(comp_symbol)  |= SYM_SPECIAL_VAR;
    qheader(emsg_star)    |= SYM_GLOBAL_VAR;
    qheader(redef_msg)    |= SYM_SPECIAL_VAR;
    qheader(break_function)    |= SYM_SPECIAL_VAR;
    qvalue(break_function)      = nil;
    qheader(gchook)       |= SYM_SPECIAL_VAR;
    qvalue(gchook)         = nil;
    qheader(trap_time)    |= SYM_SPECIAL_VAR;
    qvalue(trap_time)      = nil;
    qheader(resources)    |= SYM_SPECIAL_VAR;
    qvalue(resources)      = nil;
    qheader(used_space)   |= SYM_SPECIAL_VAR;
    qvalue(used_space)     = fixnum_of_int(0);
    qheader(avail_space)  |= SYM_SPECIAL_VAR;
    qvalue(avail_space)    = fixnum_of_int(0);
    {   LispObject common = make_undefined_symbol("common-lisp-mode");
        qheader(common)   |= SYM_SPECIAL_VAR;
#ifdef COMMON
        qvalue(common)        = lisp_true;
        qvalue(raise_symbol)  = lisp_true;
        qvalue(lower_symbol)  = nil;
#else
        qvalue(common)        = nil;
        qvalue(raise_symbol)  = nil;
        qvalue(lower_symbol)  = lisp_true;
#endif
    }
    qvalue(echo_symbol)    = nil;
    qvalue(comp_symbol)    = nil;
    qvalue(emsg_star)      = nil;
    qvalue(redef_msg)      = lisp_true;

    sys_hash_table = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(2), nil);
    get_counts = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(0), nil);
//
// I make the vector that can hold the names used for "fast" get tags big
// enough for the largest possible number.
//
    fastget_names = getvector_init((MAX_FASTGET_SIZE+2)*CELL, SPID_NOPROP);
//
// The next bit is a horrid fudge, used in read.c (function orderp) to
// support REDUCE. It ensures that the flag 'noncom is subject to an
// optimisation for flag/flagp that allows it to be tested for using a
// simple bit-test.  This MUST use entry zero (coded as 1 here!).
// Also I insist that 'lose be the second fastget thing!
//
    {   LispObject nc = make_undefined_symbol("noncom");
        qheader(nc) |= (1L << SYM_FASTGET_SHIFT);
        elt(fastget_names, 0) = nc;
        nc = make_undefined_symbol("lose");
        qheader(nc) |= (2L << SYM_FASTGET_SHIFT);
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
    inject_randomness((int)clock());
    set_up_functions(0);
    set_up_variables(0);
    procstack = nil;
    procmem = getvector_init(CELL*100, nil); // 0 to 99
    procstackp = 0;
}

void set_up_functions(int restart_flag)
{
//
// All symbols that have a pointer to C code in their function cell must
// be set up whether we are in a warm OR a cold start state, because the
// actual addresses associated with C entrypoints will vary from version
// to version of the binary of the system.
//
    size_t i;
#ifdef COMMON
//
// In Common Lisp mode it could be that the user had something other than the
// LISP package active when the image was saved. But I want all the symbols
// that I create or restore here to be in the LISP (or sometimes keyword)
// package. So I temporarily reset the package here...
//
    LispObject saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    function_symbol          = make_symbol("function", restart_flag, function_fn, (two_args *)function_fn, BAD_SPECIALN);
    qheader(function_symbol)|= SYM_SPECIAL_FORM;
    quote_symbol             = make_symbol("quote", restart_flag, quote_fn, (two_args *)quote_fn, BAD_SPECIALN);
    qheader(quote_symbol)   |= SYM_SPECIAL_FORM;
    progn_symbol             = make_symbol("progn", restart_flag, progn_fn, (two_args *)progn_fn, BAD_SPECIALN);
    qheader(progn_symbol)   |= SYM_SPECIAL_FORM;
    declare_symbol           = make_symbol("declare", restart_flag, declare_fn, (two_args *)declare_fn, BAD_SPECIALN);
    qheader(declare_symbol) |= SYM_SPECIAL_FORM;
    special_symbol           = make_undefined_symbol("special");
    large_modulus            = fixnum_of_int(1);
    cons_symbol              = make_symbol("cons", restart_flag, TOO_FEW_2, Lcons, WRONG_NO_2);
    eval_symbol              = make_symbol("eval", restart_flag, Leval, TOO_MANY_1, WRONG_NO_1);
    apply_symbol             = make_symbol("apply", restart_flag, Lapply_1, Lapply_2, Lapply_n);
    load_source_symbol       = make_symbol("load-source", restart_flag, Lload_source, TOO_MANY_1, Lload_source0);
    builtin0_symbol          = make_undefined_symbol("s:builtin0");
    builtin1_symbol          = make_undefined_symbol("s:builtin1");  
    builtin2_symbol          = make_undefined_symbol("s:builtin2");  
    builtin3_symbol          = make_undefined_symbol("s:builtin3");  
    builtin4_symbol          = make_undefined_symbol("s:builtin4");  
    load_selected_source_symbol =
                               make_symbol("load-selected-source",
                                   restart_flag, Lload_selected_source,
                                   TOO_MANY_1, Lload_selected_source0);
//
// The main bunch of symbols can be handed using a table that
// gives names and values.
//
    for (i=0; eval2_setup[i].name != NULL; i++)
        qheader(make_symbol(eval2_setup[i].name,
                            restart_flag,
                            eval2_setup[i].one,
                            eval2_setup[i].two,
                            eval2_setup[i].n)) |= SYM_SPECIAL_FORM;
    for (i=0; eval3_setup[i].name != NULL; i++)
        qheader(make_symbol(eval3_setup[i].name,
                            restart_flag,
                            eval3_setup[i].one,
                            eval3_setup[i].two,
                            eval3_setup[i].n)) |= SYM_SPECIAL_FORM;

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
    create_symbols(newhash_setup, restart_flag);
    create_symbols(print_setup, restart_flag);
    create_symbols(read_setup, restart_flag);
    create_symbols(restart_setup, restart_flag);
    create_symbols(mpi_setup, restart_flag);
//
// Although almost everything is mapped into upper case in a Common Lisp
// world, I will preserve the case of symbols defined in u01 to u60.
//
    for (i=0; setup_tables[i]!=NULL; i++)
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
}

static int alpha1(const void *a, const void *b)
{   return strcmp(1+*(const char **)a, 1+*(const char **)b);
}

// This sets up:
//   lispsystem!*
//   The standard input and output streams
//   information about the command line arguments in lispargs!*
//   floating point limit constants (which ought in fact to be the
//       same on all platforms if I am using IEEE arithmetic...)
//   input!-libraries and output!-library

void set_up_variables(int restart_flag)
{   LispObject w, w1;
    size_t i;
// There are a number of system variables that are not saved in
// image files and so that have to be set up manually in every case.
#ifdef COMMON
    LispObject saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    charvec = getvector_init(257*CELL, nil);
    faslvec = nil;
    faslgensyms = nil;
    multiplication_buffer = nil;
// big_fake1 and big_fake2 represent a witty issue - when a bignum is
// serilized and it uses only one or two words its value gets written
// as a 64-bit numeric value. When it is re-loaded that value is packed
// as a number - either a fixnum or a bignum as relevant. So the FAKE
// nature of big_fake1 and big_fake2 will lead to the ser8ialization process
// reloading fixnums if one is on a 64-bit machine. Thus defeating the whole
// point of them!
    big_fake1 = make_one_word_bignum(0);
    big_fake2 = make_two_word_bignum(0, 0);
// It makes sense to reset big_divisor and big_dividend on reloading a heap
// image so that any very large allocation from the previous run is discarded.
    big_divisor = make_four_word_bignum(0, 0, 0, 0);
    big_dividend = make_four_word_bignum(0, 0, 0, 0);
    big_quotient = make_four_word_bignum(0, 0, 0, 0);
    qvalue(macroexpand_hook) = funcall_symbol =
        make_symbol("funcall", restart_flag, Lfuncall1, Lfuncall2, Lfuncalln);
    input_libraries = make_undefined_symbol("input-libraries");
    qheader(input_libraries)  |= SYM_SPECIAL_VAR;
    qvalue(input_libraries) = nil;
    for (i=number_of_fasl_paths; i!=0; i--)
        qvalue(input_libraries) = cons(SPID_LIBRARY + (((int32_t)(i-1))<<20),
                                       qvalue(input_libraries));
    output_library = make_undefined_symbol("output-library");
    qvalue(output_library)  = (output_directory & 0x80000000u) != 0 ? nil :
                              SPID_LIBRARY + (((int32_t)output_directory)<<20);
//
// The Lisp variable lispsystem* gets set here. (in Common mode it is
// the variable *features*)
// Its value is a list.
//       csl                      says I am a CSL Lisp
//       (executable . "string")  name of current executable (if available)
//       (shortname . "string")   executable wuithout path or extension
//       pipes                    do I support open-pipe?
//       parallel                 "parallel" function supported
//       (version . "string")     eg "2.11"
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
//

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
        char *p1 = opsys, *p2 = OPSYS;
        int ii;
        while ((*p1++ = toupper(*p2++)) != 0);
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
        if (strcmp(opsys, "UNIX") != 0 &&
            strcmp(opsys, "unix") != 0)
            w = cons(make_keyword("UNIX"), w);
#endif
#endif
        /*! lispsys [win32] \item[{\ttfamily win32}, {\ttfamily win64}] \index{{\ttfamily win32}, {\ttfamily win64}}
         * Any windows system puts {\ttfamily win32} in {\ttfamily lispsystem!*}.
         * If 64-bit windows is is use then {\ttfamily win64} is also included
         */

        /*! lispsys [linker] \item[{\ttfamily (linker . type)}] \index{{\ttfamily (linker . type)}}
         * Intended for use in association with {\ttfamily compiler!-command}, the value
         * is {\ttfamily win32} on Windows, {\ttfamily x86\_64} on 64-bit Linux and
         * other things on other systems, as detected using the program {\ttfamily
         * objtype.c}.
         */

        w = acons(make_keyword("LINKER"),
                  make_undefined_symbol(linker_type), w);
        w1 = nil;
        for (ii=sizeof(compiler_command)/sizeof(compiler_command[0]);
             ii!=0;
             ii--)
            w1 = cons(make_undefined_symbol(compiler_command[ii-1]), w1);

        /*! lispsys [compiler-command] \item[{\ttfamily (compiler!-command . command)}] \index{{\ttfamily (compiler"!-command . command)}}
         * The value associated with this key is a string that was used to compile the
         * files of C code making up CSL. It should contain directives to set up
         * search paths and predefined symbols. It is intended to be used in an
         * experiment that generates C code synamically, uses a command based on this
         * string to compile it and then dynamically links the resulting code in with
         * the running system.
         */

        w = acons(make_keyword("COMPILER-COMMAND"), w1, w);
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

        /*! lispsys [version] \item[{\ttfamily  (version . ver)}] \index{{\ttfamily  (version . ver)}}
         * The CSL version number.
         */


        /*! lispsys [windowed] \item[{\ttfamily windowed}] \index{{\ttfamily windowed}}
         * Present if CSL is running in its own window rather than in console mode.
         */

        w = cons(make_keyword(OPSYS), nil);
        int ii;
#if defined WIN64 || defined __WIN64__ || defined WIN32
//
// In the WIN64 case I will ALSO tell the user than I am "win32". This is
// a curious thing to do maybe, but is because historically win32 may have
// been used as a "windows" test, and win64 is in general terms a
// compatible extension so all win32 options ought still to be available.
//
        w = cons(make_keyword("win32"), w);
#endif
#if defined WIN64 || defined __WIN64__
        w = cons(make_keyword("win64"), w);
#endif
        qheader(n) |= SYM_SPECIAL_VAR;
        w = acons(make_keyword("linker"),
                  make_undefined_symbol(linker_type), w);
        w1 = nil;
        for (ii=sizeof(compiler_command)/sizeof(compiler_command[0]);
             ii!=0;
             ii--)
            w1 = cons(make_undefined_symbol(compiler_command[ii-1]), w1);
        w = acons(make_keyword("compiler-command"), w1, w);
#endif
        defined_symbols = 0;
        for (i=0; setup_tables[i]!=NULL; i++) count_symbols(setup_tables[i]);
#ifdef COMMON
//
// A gratuitous misery here is the need to make words
// upper case.
//
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
#ifdef EXPERIMENT
                 w = cons(make_keyword("EXPERIMENT"), w);
#endif
                 w = cons(make_keyword("RECORD_GET"), w);
                 w = acons(make_keyword("EXECUTABLE"),
                           make_string(fullProgramName), w);
                 w = acons(make_keyword("NAME"), make_string(IMPNAME), w);
                 w = acons(make_keyword("VERSION"), make_string(VERSION), w);
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
#ifdef EXPERIMENT
        w = cons(make_keyword("experiment"), w);
#endif
#ifdef EMBEDDED
        w = cons(make_keyword("embedded"), w);
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
//
            if (showmathInitialised &&
                alternative_stdout == NULL)
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
//
            if (showmathInitialised &&
                alternative_stdout == NULL)
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
        w = acons(make_keyword("version"), make_string(VERSION), w);
        w = cons(make_keyword("csl"), w);
//
// Ha Ha a trick here - if a symbol ADDSQ is defined I view this image
// as being one for REDUCE and push that information onto lispsystem*,
// and I also reset the "about box" information (if using fwin).
//
        w1 = make_undefined_symbol("addsq");
        if (qfn1(w1) != undefined1)
        {   w = cons(make_keyword("reduce"), w);
            w1 = qvalue(make_undefined_symbol("version*"));
            if (is_vector(w1) &&
                is_string_header(vechdr(w1)))
            {
                int n = length_of_byteheader(vechdr(w1))-CELL;
                sprintf(about_box_title, "About %.*s",
                        (n > 31-(int)strlen("About ") ?
                         31-(int)strlen("About ") : n),
                        &celt(w1, 0));
                sprintf(about_box_description, "%.*s",
                        (n > 31 ? 31 : n),
                        &celt(w1, 0));
//
// The provision here is that if variables called "author!*" and
// "author2!*" exist with strings as values then those values will
// appear in the "about box". See a commentary in the file fwin.c about
// possibly non-obvious constraints on what text you may properly place
// in these strings.
//
                w1 = qvalue(make_undefined_symbol("author1*"));
                if (is_vector(w1) &&
                    is_string_header(vechdr(w1)))
                {   n = length_of_byteheader(vechdr(w1))-CELL;
                    sprintf(about_box_rights_1, "%.*s",
                            n > 31 ? 31 : n, &celt(w1, 0));
                }
                else strcpy(about_box_rights_1, "A C Hearn/RAND");
                w1 = qvalue(make_undefined_symbol("author2*"));
                if (is_vector(w1) &&
                    is_string_header(vechdr(w1)))
                {   n = length_of_byteheader(vechdr(w1))-CELL;
                    sprintf(about_box_rights_2, "%.*s",
                            n > 31 ? 31 : n, &celt(w1, 0));
                }
                else strcpy(about_box_rights_2, "Codemist    ");
            }
            else
            {   strcpy(about_box_title, "About REDUCE");
                strcpy(about_box_description, "REDUCE");
                strcpy(about_box_rights_1, "A C Hearn/RAND");
                strcpy(about_box_rights_2, "Codemist");
            }
        }
        qheader(n) |= SYM_SPECIAL_VAR;
        qvalue(n) = w;
#endif // COMMON
    }
//
// lispargs* and full-lispargs!* give access to command line args used at
// launch. lispargs!* just contains anything beyond the keyword "--args"
// while full-lispargs contains everything.
//
    {   LispObject aa = nil, faa = nil;
        LispObject n = make_undefined_symbol("lispargs*");
        int i, seen_args_keyword=0;
        for (i=0; i<csl_argc; i++)
        {   LispObject s = make_string(csl_argv[i]);
            faa = cons(s, faa);
            if (seen_args_keyword) aa = cons(s, aa);
            if (strcmp(csl_argv[i], "--args") == 0) seen_args_keyword = 1;
        }
        aa = Lreverse(nil, aa);
        faa = Lreverse(nil, faa);
        qheader(n) |= SYM_SPECIAL_VAR;
        qvalue(n) = aa;
        n = make_undefined_symbol("full-lispargs*");
        qheader(n) |= SYM_SPECIAL_VAR;
        qvalue(n) = faa;
    }
//
// Floating point characteristics are taken from <cfloat> where it is
// supposed that the C compiler involved has got the values correct.
// I do this every time the system is loaded rather than just when an
// image is cold-created. This is because an image file may have been created
// on a system differing from the one on which it is used. Maybe in fact
// IEEE arithmetic is ALMOST universal and I am being too cautious here?
//
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
//
// I assume that I have a radix 2 representation, and float-negative-epsilon
// is just half float-epsilon. Correct me if I am wrong...
//
    make_constant("short-float-negative-epsilon",
                  pack_short_float(16.0*FLT_EPSILON/2.0));
    make_constant("single-float-negative-epsilon",
                  pack_single_float(FLT_EPSILON/2.0));
    make_constant("double-float-negative-epsilon",
                  make_boxfloat(DBL_EPSILON/2.0, TYPE_DOUBLE_FLOAT));
// For now "long" = "double"
    make_constant("long-float-negative-epsilon",
                  make_boxfloat(DBL_EPSILON/2.0, TYPE_LONG_FLOAT));
//
// I hope that the C header file gets extremal values correct. Note that
// because pack_short_float() truncates (rather than rounding) it should give
// correct values for most-positive-short-float etc
//
    make_constant("most-positive-short-float",
                  pack_short_float(FLT_MAX));
    make_constant("most-positive-single-float",
                  pack_single_float(FLT_MAX));
    make_constant("most-positive-double-float",
                  make_boxfloat(DBL_MAX, TYPE_DOUBLE_FLOAT));
    make_constant("most-positive-long-float",
                  make_boxfloat(DBL_MAX, TYPE_LONG_FLOAT));
//
// Here I assume that the floating point representation is sign-and-magnitude
// and hence symmetric about zero.
//
    make_constant("most-negative-short-float",
                  pack_short_float(-FLT_MAX));
    make_constant("most-negative-single-float",
                  pack_single_float(-FLT_MAX));
    make_constant("most-negative-double-float",
                  make_boxfloat(-DBL_MAX, TYPE_DOUBLE_FLOAT));
    make_constant("most-negative-long-float",
                  make_boxfloat(-DBL_MAX, TYPE_LONG_FLOAT));
//
// The "least-xxx" set of values did not consider the case of denormalised
// numbers too carefully in ClTl-1, so in ClTl-2 there are elaborations. I
// believe that a proper C header file <cfloat> will make the macros that
// I use here refer to NORMALISED values, so the numeric results I use
// here will not be quite proper (ie there are smaller floats that are
// un-normalised). But I will ignore that worry just for now.
//
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
//
// The bunch here are intended to be NORMALISED numbers, while the unqualified
// ones above may not be.
//
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

    qheader(terminal_io = make_undefined_symbol("*terminal-io*"))
    |= SYM_SPECIAL_VAR;
    qheader(standard_input = make_undefined_symbol("*standard-input*"))
    |= SYM_SPECIAL_VAR;
    qheader(standard_output = make_undefined_symbol("*standard-output*"))
    |= SYM_SPECIAL_VAR;
    qheader(error_output = make_undefined_symbol("*error-output*"))
    |= SYM_SPECIAL_VAR;
    qheader(trace_output = make_undefined_symbol("*trace-output*"))
    |= SYM_SPECIAL_VAR;
    qheader(debug_io = make_undefined_symbol("*debug-io*"))
    |= SYM_SPECIAL_VAR;
    qheader(query_io = make_undefined_symbol("*query-io*"))
    |= SYM_SPECIAL_VAR;

    stream_type(lisp_work_stream) = make_undefined_symbol("work-stream");

    {   LispObject f = lisp_terminal_io;
        stream_type(f) = make_undefined_symbol("terminal-stream");
        set_stream_read_fn(f, char_from_terminal);
        set_stream_read_other(f, read_action_terminal);
        set_stream_write_fn(f, char_to_terminal);
        set_stream_write_other(f, write_action_terminal);
        qvalue(terminal_io) = f;
        f = lisp_standard_input;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
//
// If I do not have COMMON defined I will take a slight short cut here and
// make reading from *standard-input* read directly from the terminal. For
// full Common Lisp compatibility I think *standard-input* is required to
// be a synonym stream that will dynamically look at the value of the variable
// *terminal-io* every time it does anything. Ugh, since people who assign to
// or re-bind *terminal-io* seem to me to be asking for terrible trouble!
//
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
        qvalue(standard_input) = f;

        f = lisp_standard_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(standard_output) = f;

        f = lisp_error_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(error_output) = f;

        f = lisp_trace_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(trace_output) = f;

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
        qvalue(debug_io) = f;

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
        qvalue(query_io) = f;
    }

#if defined HAVE_LIBFOX || defined HAVE_LIBWX
    {   LispObject stream = make_undefined_symbol("*math-output*");
        LispObject f = make_stream_handle();
        qheader(stream) |= SYM_SPECIAL_VAR;
        stream_type(f) = make_undefined_symbol("math-output");
        set_stream_write_fn(f, char_to_math);
        set_stream_write_other(f, write_action_math);
        qvalue(stream) = f;
        stream = make_undefined_symbol("*spool-output*");
        qheader(stream) |= SYM_SPECIAL_VAR;
        f = make_stream_handle();
        stream_type(f) = make_undefined_symbol("spool-output");
        set_stream_write_fn(f, char_to_spool);
        set_stream_write_other(f, write_action_spool);
        qvalue(stream) = f;
    }
#endif

//
// I can not handle boffo overflow very well here, but I do really hope that
// symbols spelt out on the command line will always be fairly short.
//
    for (i=0; i<number_of_symbols_to_define; i++)
    {   bool undef = undefine_this_one[i];
        const char *s = symbols_to_define[i];
        if (undef)
        {   LispObject n = make_undefined_symbol(s);
            qvalue(n) = unset_var;
        }
        else
        {   char buffer[256];
            char *p = buffer;
            int c;
            LispObject n, v;
            while ((c = *s++) != 0 && c != '=') *p++ = (char)c;
            *p = 0;
            n = make_undefined_symbol(buffer);
            push(n);
            if (c == 0) v = lisp_true;
            else
            {
//
// I have been having a big difficulty here, caused by the inconsistent and
// awkward behaviours of various shells and "make" utilities. In a tidy
// and simple world I might like a command-line option -Dxx=yyy to allow
// arbitrary text for yyy terminating it at the next whitespace. Then yyy
// could be processed by the Lisp reader so that numbers, symbols, strings
// etc could be specified. However I find that things I often want to
// use involve characters such as "\" and ":" (as components of file-names
// on some machines), and sometimes "make" treats these as terminators, or
// wants to do something magic with "\".  If I put things within quote marks
// then sometimes the quotes get passed through to Lisp and sometimes not.
// This is all a BIG misery in a multi-platform situation!  As a fresh
// attempt to inject sanity I will always convert yyy to a Lisp string. If
// it is specified with leading and trailing '"' marks I will strip them. Thus
// both -Dxxx=yyy and -Dxxx="yyy" will leave the variable xxx set to the
// string "yyy". Then as a Lisp user I can parse the string if I need to
// interpret it as something else.
//
#ifndef PASS_PREDEFINES_THROUGH_READER
                if (*s == '"')   // Convert "yyy" to just yyy
                {   char s1[256];
                    strncpy(s1, s+1, sizeof(s1));
                    s1[sizeof(s1)-1] = 0; // force termination
                    p = s1;
                    while (*p != 0) p++;
                    if (*--p == '"') *p = 0;
                    v = make_string(s1);
                }
                else
#endif
                v = make_string(s);
#ifdef PASS_PREDEFINES_THROUGH_READER
                v = Lexplodec(nil, v);
                v = Lcompress(nil, v);
//
// The above will first make the value in -Dname=value into a string,
// then explode it into a list, and compress back - the effect is as if the
// original value had been passed through the regular Lisp READ function,
// so symbols, numbers and even s-expressions can be parsed.  If the
// parsing fails I (silently) treat the value as just NIL.
//
#endif
            }
            pop(n);
            qheader(n) |= SYM_SPECIAL_VAR;
            qvalue(n) = v;
        }
    }
//
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
//
    if (loadable_packages == NULL && switches==NULL)
    {   LispObject w1 = qvalue(make_undefined_symbol("loadable-packages*"));
        LispObject w2;
        int n;
        char *v;
        n = 0;
        for (w2=w1; consp(w2); w2=qcdr(w2)) n++; // How many?
        n = 2*n;
        loadable_packages = (char **)(*malloc_hook)((n+1)*sizeof(char *));
        if (loadable_packages != NULL)
        {   n = 0;
            for (w2=w1; consp(w2); w2=qcdr(w2))
            {   LispObject w3 = qcar(w2);
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    !is_string_header(vechdr(w3))) break;
                n1 = length_of_byteheader(vechdr(w3))-CELL;
                v = (char *)(*malloc_hook)(n1+2);
                if (v == NULL) break;
                v[0] = ' ';
                memcpy(v+1, &celt(w3, 0), n1);
                v[n1+1] = 0;
                loadable_packages[n++] = v;
                loadable_packages[n++] = NULL;
            }
            qsort(loadable_packages, n/2, 2*sizeof(char *), alpha1);
            loadable_packages[n] = NULL;   // NULL-terminate the list
        }
        w1 = qvalue(make_undefined_symbol("switches*"));
        n = 0;
        for (w2=w1; consp(w2); w2=qcdr(w2)) n++; // How many?
        n = (n+1)*sizeof(char *);
        n = 2*n;
        switches = (char **)(*malloc_hook)(n);
        if (switches != NULL)
        {   n = 0;
            for (w2=w1; consp(w2); w2=qcdr(w2))
            {   LispObject w3 = qcar(w2), w4;
                char sname[64];
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    !is_string_header(vechdr(w3))) break;
                n1 = length_of_byteheader(vechdr(w3))-CELL;
                if (n1 > 60) break;
                sprintf(sname, "*%.*s", n1, &celt(w3, 0));
                w4 = make_undefined_symbol(sname);
                v = (char *)(*malloc_hook)(n1+2);
                if (v == NULL) break;
//
// The first character records the current state of the switch. With FWIN
// I have entries that say "x" for "I am not at present active" which copes
// with switches that will become relevant only when a package of code is
// loaded. I will scan from time to time to update my information - I guess
// that I can put in a hook that triggers review after any module has been
// loaded. See the function review_switch_settings() the follows...
//
                if (qvalue(w4) == nil) v[0] = 'n';
                else if (qvalue(w4) == unset_var) v[0] = 'x';
                else v[0] = 'y';
                memcpy(v+1, &celt(w3, 0), n1);
                v[n1+1] = 0;
                switches[n++] = v;
                switches[n++] = NULL;
            }
            qsort(switches, n/2, 2*sizeof(char *), alpha1);
            switches[n] = NULL;
        }
    }

#ifdef COMMON
    CP = saved_package;
#endif
}

#ifndef COMMON

//
// This alse reviews the list of loaded packages...
//
void review_switch_settings()
{   LispObject sw = qvalue(make_undefined_symbol("switches*"));
    while (consp(sw))
    {   LispObject s = qcar(sw);
        char sname[64];
        int n1;
        char *v;
        char **p;
        LispObject starsw;
        sw = qcdr(sw);
        if (is_symbol(s)) s = qpname(s);
        if (!is_vector(s) || !is_string_header(vechdr(s))) continue;
        n1 = length_of_byteheader(vechdr(s))-CELL;
        if (n1 > 60) continue;
        sprintf(sname, "*%.*s", n1, &celt(s, 0));
        for (p=switches; *p!=NULL; p+=2)
        {   if (strcmp(1+*p, &sname[1]) == 0) break;
        }
        if ((v=*p) == NULL) continue;
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
    {   LispObject s = qcar(sw);
        char sname[64];
        int n1;
        char *v;
        char **p;
        sw = qcdr(sw);
        if (is_symbol(s)) s = qpname(s);
        if (!is_vector(s) || !is_string_header(s)) continue;
        n1 = length_of_byteheader(vechdr(s))-CELL;
        if (n1 > 60) continue;
        sprintf(sname, "%.*s", n1, &celt(s, 0));
        for (p=loadable_packages; *p!=NULL; p+=2)
        {   if (strcmp(1+*p, sname) == 0) break;
        }
        if ((v=*p) == NULL) continue;
        if (*v == ' ') *v = 'X';  // X here says "update the info"
    }
    fwin_refresh_switches(switches, loadable_packages);
}

#endif

bool CSL_MD5_busy;
unsigned char unpredictable[256];
static int n_unpredictable = 0;
static bool unpredictable_pending = 0;

void inject_randomness(int n)
{   unpredictable[n_unpredictable++] ^= (n % 255);
    if (n_unpredictable >= 256)
    {   n_unpredictable = 0;
        unpredictable_pending = true;
    }
    if (unpredictable_pending & !CSL_MD5_busy)
    {   CSL_MD5_Init();
        CSL_MD5_Update(unpredictable, sizeof(unpredictable));
        CSL_MD5_Final(unpredictable);
        unpredictable_pending = false;
    }
}

//
// Used to ensure that an image file matches up with the C code compiled
// into the main executable. The linear search here for the place the
// checksum lives is a bit crummy. But the total cost is linear in the
// number of things that have been compiled into C.
//
static void get_checksum(const setup_type *p)
{   while (p->name!=NULL) p++;
    if (p->one != NULL && p->two != NULL)
    {   unsigned char *w = (unsigned char *)p->two;
        CSL_MD5_Update(w, strlen((char *)w));
    }
}

void get_user_files_checksum(unsigned char *b)
{   size_t i;
    CSL_MD5_Init();
    for (i=0; setup_tables[i]!=NULL; i++)
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
//
// restart_flag is a set of options passed as a bitmap:
//    1       Do a warm start, ie re-load a heap image.
//            The alternative is a cold start that should only
//            be called for as part of a system bootstrap process.
//    2       Grab memory for CSL to use.
//            The alternative is to assume that memory has already been
//            allocated, and to re-use what there is.
//    4, 8, ...   not used yet!
//
    int32_t i;
    if ((restart_flag & 2) != 0) init_heap_segments(store_size);
    garbage_collection_permitted = false;
    stack = stackbase;
    stack[0] = nil;
    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;

    if ((restart_flag & 1) != 0)
    {   char junkbuf[120];
        char filename[LONGEST_LEGAL_FILENAME];
        memset(junkbuf, 0, sizeof(junkbuf));
        memset(filename, 0, sizeof(filename));
        if (IopenRoot(filename, 0, 0))
        {   term_printf("\n+++ Image file \"%s\" can not be read\n",
                        filename);
            my_exit(EXIT_FAILURE);
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
                my_exit(EXIT_FAILURE);
            }
        }
//
// To make things more responsive for the user I will display a
// banner rather early (before reading the bulk of the image file).
// The banner that I will display is one provided to be by PRESERVE.
//
        {   char b[64];
            if (IopenRoot(filename, BANNER_CODE, 0)) b[0] = 0;
            else
            {   for (i=0; i<64; i++) b[i] = (char)Igetc();
// The banner will not be subject to compression technology because it will
// normally be too short to benefit.
                IcloseInput();
            }
//
// A banner set via startup-banner takes precedence over one from preserve.
// But as a very special hack I detect if --texmacs was on the command
// line and in that case I stay quiet...
//
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
    else for (LispObject **p = list_bases; *p!=NULL; p++) **p = nil;

    savestacklimit = stacklimit = &stack[stack_segsize*CSL_PAGE_SIZE/4-200];
    // allow some slop at end
    if ((restart_flag & 1) != 0) warm_setup();
    else cold_setup();

    if (init_flags & INIT_QUIET) Lverbos(nil, fixnum_of_int(1));
    if (init_flags & INIT_VERBOSE) Lverbos(nil, fixnum_of_int(3));
//
// Here I grab more memory (if I am allowed to) until the proportion of the
// heap active at the end of garbage collection is less than 1/2.  If the
// attempt to grab more memory fails I clear the bit in init_flags that
// allows me to try to expand, so I will not waste time again.
// The aim of keeping the heap less than half full is an heuristic and
// could be adjusted on the basis of experience with this code.
//
    if (init_flags & INIT_EXPANDABLE)
    {   int32_t more = heap_pages_count + vheap_pages_count;
        more = 3 *more - pages_count;
        while (more-- > 0)
        {   void *page = (void *)my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
//
// CF the code in gc.c -- I can still use my_malloc_1 here, which makes this
// code just a tiny bit safer.
//
            if (page == NULL)
            {   init_flags &= ~INIT_EXPANDABLE;
                break;
            }
            else pages[pages_count++] = page;
        }
    }
    {   int32_t w = 0;
//
// The total store allocated is that used plus that free, including the
// page set aside for the Lisp stack. I had better report this in Kbytes
// which should then be sort of OK up to a total of 4000 Gbytes before the
// unsigned long overflows on me.
//
        if (init_flags & INIT_VERBOSE)
        {   unsigned long m =
                ((unsigned long)(CSL_PAGE_SIZE/1000))*(pages_count+w+1);
            if (m > 4000)
                term_printf("Memory allocation: %lu Mbytes\n", m/1000);
            else term_printf("Memory allocation: %lu Kbytes\n", m);
        }
    }
    if (init_flags & INIT_VERBOSE)
    {   int n = number_of_processors();
        if (n > 1)
            term_printf("There are %d processors available\n", n);
    }
    garbage_collection_permitted = true;
    return;
}

LispObject multiplication_buffer;

// Here is a table of all the list-bases that CSL marks from, and that
// must have their values captured in checkpoint files.

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
    NULL              // Used to mark the end of the table.
};

//
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
//
// Please note that these days MD5 is not considered cryptographically secure,
// and the implementation here will not be robust against side-attacks etc.
// The proper uses hare are as a checksum fur use when chance rather than
// malice is the opponent.
//

#include "md5.cpp"

MD5_CTX context;

void CSL_MD5_Init(void)
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

// end of restart.cpp
