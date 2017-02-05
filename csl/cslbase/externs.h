// externs.h                               Copyright (C) Codemist 1989-2017

//
//   Main batch of extern declarations.
//
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

#ifndef header_externs_h
#define header_externs_h 1

// Note that the Windows version exports a number of symbols, as listed
// in a ".def" file. In order for there to be a match between the symbol
// names in the object files and the names in the .def file it is vital
// that all those things be declared with C linkage and hence un-mangled
// names. Perhaps I need some strategy that lets me gain the extra security
// of C++ linkage for everything else... but that is for the future.

#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif

//
// I have a bunch of macros that I use for desparation-mode debugging,
// and in particular when I have bugs that wriggle back into their lairs
// when I try running under "gdb" or whatever. These print dull messages
// to stderr. The "do..while" idiom is to keep C syntax safe with regard to
// semicolons.
//

#define D do { \
          const char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)

#define DS(s) do { \
          const char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)

#define DX(s) do { \
          const char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)

extern void **pages,
       **heap_pages, **vheap_pages,
       **native_pages;

extern void **new_heap_pages, **new_vheap_pages,
       **new_native_pages;

extern void *allocate_page(const char *why);

#ifdef CONSERVATIVE

#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_NATIVE 3

typedef struct page_map_t
{   void *start;
    void *end;
    int type;
} page_map_t;

#endif

extern int32_t pages_count,
       heap_pages_count, vheap_pages_count,
       native_pages_count;

extern int32_t new_heap_pages_count, new_vheap_pages_count,
       new_native_pages_count;

extern int32_t native_pages_changed;
extern int32_t native_fringe;

extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize;  // measured in units of one CSL page
extern LispObject *stack;
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;

extern bool restartp;

extern char *big_chunk_start, *big_chunk_end;

#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif

extern LispObject multiplication_buffer;

#define push(a)         { *++stack = (a); }
// push2 etc are just like push, but grouped together
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }

#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)

#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7

extern volatile char stack_contents_temp;

#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack("@" __FILE__,__LINE__)) \
   {   show_stack(); aerror("stack overflow"); }
#else
#define if_check_stack \
   {   const char *_p_ = (char *)&_p_; \
       if (_p_ < C_stack_limit) aerror("stack overflow"); \
   }
#endif

extern int32_t software_ticks, countdown;

//
// Extra debugging help...
//

#ifdef DEBUG

extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);

#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)

#define debug_assert(x) \
  if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }

#else

#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)

#define debug_assert(x)

#endif

//
// The next bit is JUST used under Linux for tracking stubborn bugs where
// I want to check where I am executing code.
//
extern volatile int blipflag;
extern int64_t blipcount, startblip;

#if defined __linux__ && defined DEBUG
#define HANDLE_BLIP                                                       \
    if (blipflag)                                                         \
    {   blipflag = 0;                                                     \
        if (startblip >= 0 && ++blipcount > startblip)                    \
        {   fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__);  \
            fflush(stderr);                                               \
        }                                                                 \
    }
#else
#define HANDLE_BLIP
#endif

#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
    }

#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
    }

#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
    }

#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
    }

#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
    }

extern LispObject nil;

#define first_nil_offset         50     // GC collector marks from here up

//
// A vector of 50 words is used by the interpreter when preparing args
// for functions and when handling multiple values.
//

#define work_0_offset           250

// Garbage collector marks up to but not including last_nil_offset
#define last_nil_offset         301

//
// NIL_SEGMENT_SIZE must be over-large by enough to allow for
// space lost while rounding nil up to be a multiple of 8. Also in the
// Common Lisp case I need to give myself a spare word BEFORE the place
// where nil points.
//
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(LispObject) + 32)

//
// I give myself a margin of SPARE bytes at the end of a page so that I can
// always CONS that amount (even without a garbage collection check) and not
// corrupt anything.  The main use for this is that sometimes I need to
// convert a set of multiple values or of arguments from values on the
// (C-) stack or wherever va_arg() can find them into a list structure, and
// to avoid horrible potential problems with a garbage collection spotting]
// an exception (notably a ^C interrupt), running arbitrary code in an
// exception ghandler and then continuing, I need to cons those things up
// without any possible GC.  The function cons_no_gc does that, and
// I should then call cons_gc_test() afterwards to regularise the situation.
// 512 bytes here leaves room for 64 conses, and I support at most 50
// (multiple-) values so I hope this is safe.
//

#define SPARE                   512

//
// I want my table of addresses here to be 8-byte aligned on 64-bit
// machines...
//

//
//            !COMMON  COMMON
//   32-bit    nil       nil
//   64-bit    nil+4     nil
//

#ifdef COMMON
#define BASE ((LispObject *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((LispObject *)(nil+4)): ((LispObject *)nil))
#endif

extern intptr_t byteflip;

extern LispObject * volatile stacklimit;

extern LispObject fringe;
extern LispObject volatile heaplimit;

extern LispObject volatile vheaplimit;
extern LispObject vfringe;

extern intptr_t nwork;

extern unsigned int exit_count;
extern uintptr_t gensym_ser;
extern intptr_t print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;

extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table;
extern LispObject progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject big_divisor, big_dividend, big_quotient;
extern LispObject big_fake1, big_fake2;
extern LispObject active_stream, current_module;
extern LispObject native_defs, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject native_code, native_symbol, traceprint_symbol;
extern LispObject load_source_symbol, load_selected_source_symbol;
extern LispObject bytecoded_symbol, nativecoded_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time;

extern LispObject keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol;
extern LispObject expand_def_symbol, allow_key_key;

extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;

extern LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol;
extern LispObject not_symbol, reader_workspace, named_character;
extern LispObject read_float_format, short_float, single_float, double_float;
extern LispObject long_float, bit_symbol, pathname_symbol, print_array_sym;
extern LispObject read_base, initial_element;

#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern LispObject om_closeConn(LispObject nil, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject nil, LispObject ldev);
extern LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern LispObject om_putAtp(LispObject nil, LispObject ldev);
extern LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_putAttr(LispObject nil, LispObject ldev);
extern LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_putBind(LispObject nil, LispObject ldev);
extern LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern LispObject om_putBVar(LispObject nil, LispObject ldev);
extern LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_putError(LispObject nil, LispObject ldev);
extern LispObject om_putEndError(LispObject nil, LispObject ldev);
extern LispObject om_putObject(LispObject nil, LispObject ldev);
extern LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern LispObject om_getApp(LispObject nil, LispObject ldev);
extern LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern LispObject om_getAtp(LispObject nil, LispObject ldev);
extern LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_getAttr(LispObject nil, LispObject ldev);
extern LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_getBind(LispObject nil, LispObject ldev);
extern LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern LispObject om_getBVar(LispObject nil, LispObject ldev);
extern LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_getError(LispObject nil, LispObject ldev);
extern LispObject om_getEndError(LispObject nil, LispObject ldev);
extern LispObject om_getObject(LispObject nil, LispObject ldev);
extern LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern LispObject om_getInt(LispObject nil, LispObject ldev);
extern LispObject om_getFloat(LispObject nil, LispObject ldev);
extern LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern LispObject om_getVar(LispObject nil, LispObject ldev);
extern LispObject om_getString(LispObject nil, LispObject ldev);
extern LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern LispObject om_getType(LispObject nil, LispObject ldev);

extern LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);

extern LispObject om_read(LispObject nil, LispObject dev);
extern LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject nil, int nargs, ...);
extern LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif

extern LispObject workbase[51];

extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;

#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]

extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);

#define LOG2_VECTOR_CHUNK_WORDS 17
#define VECTOR_CHUNK_WORDS  ((size_t)(1<<LOG2_VECTOR_CHUNK_WORDS)) // 0x20000
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_WORDS+1];

#define eq_hash_table_list     BASE[50] // In heap image
#define equal_hash_table_list  BASE[51] // In heap image
#define current_package_offset 52

extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern LispObject eq_hash_tables, equal_hash_tables;
extern uint32_t hash_equal(LispObject key);
extern uint32_t hash_for_checking(LispObject key, int depth);

//
// The following are used to help <escape> processing.
//
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;

//
// There is no reason to preserve this across restarts etc so making it a
// simple C variable makes it easier for me to initialise it early.
//
extern intptr_t exit_reason;

extern int procstackp;

#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif

extern bool garbage_collection_permitted;

#define MAX_INPUT_FILES         40  // limit on command-line length
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20

extern const char *files_to_read[MAX_INPUT_FILES],
       *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
       *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern bool fasl_output_file;
extern size_t output_directory;

extern LispObject *repeat_heap;
extern size_t repeat_count;

#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif

extern FILE *binary_write_file;

extern size_t boffop;
extern void packcharacter(int c);
extern void packbyte(int c);
#define boffo_char(i) ucelt(boffo, i)

extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();

#ifdef SOCKETS
extern bool sockets_ready;
extern void flush_socket();
#endif

extern void report_file(const char *s);

extern bool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;

extern size_t number_of_input_files,
       number_of_symbols_to_define,
       number_of_fasl_paths;
extern int init_flags;

extern int native_code_tag;

extern const char *standard_directory;

extern int gc_number;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;

#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4

#define Lispify_predicate(p)  ((p) ? lisp_true : nil)

//
// variables used by the IO system.
//

extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];

//
// If there is no more than 100 bytes of data then I will deem
// file compression frivolous.  The compression code assumes that
// it has at least 2 bytes to work on, so do NOT cut this limit down to zero.
// Indeed more than that the limit must be greater than the length of
// the initial header record (112 bytes).
//

#define CODESIZE                0x1000

typedef struct _entry_point0
{   no_args *p;
    const char *s;
} entry_point0;

typedef struct _entry_point1
{   one_args *p;
    const char *s;
} entry_point1;

typedef struct _entry_point2
{   two_args *p;
    const char *s;
} entry_point2;

typedef struct _entry_point3
{   three_args *p;
    const char *s;
} entry_point3;

typedef struct _entry_point4
{   four_args *p;
    const char *s;
} entry_point4;

typedef struct _entry_pointn
{   n_args *p;
    const char *s;
} entry_pointn;

extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4 entries_table4[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_tableio[];

extern void set_up_entry_lookup();
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);

extern int doubled_execution;

extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
       *config_header[], *csl_headers[];

extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject nil, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern int load_dynamic(const char *objname, const char *modname,
                        LispObject name, LispObject fns);
extern "C" LispObject Linstate_c_code(LispObject nil,
                                  LispObject name, LispObject fns);

extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);

#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);

extern void Iinit();
extern void IreInit();
extern void Ilist();
extern bool open_output(const char *s, size_t len);

#define IMAGE_CODE  ((size_t)(-1000))
#define HELP_CODE   ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))

#define IOPEN_OUT       0
#define IOPEN_IN        1

extern bool Iopen(const char *name, size_t len, int dirn, char *expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char *expanded_name, size_t hard, int sixtyfour);
extern bool Iwriterootp(char *expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep(const char *name, size_t len, char *datestamp,
                     size_t *size, char *expanded_name);
extern char *trim_module_name(char *name, size_t *lenp);
extern bool Icopy(const char *name, size_t len);
extern bool Idelete(const char *name, size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int  Igetc();
extern bool Iread(void *buff, size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void *buff, size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int  Zgetc();
extern bool Zread(void *buff, size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void *buff, size_t size);
extern long int Ioutsize();
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);

extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);

extern void ensure_screen();
extern int window_heading;
extern void my_abort();
extern "C" NORETURN void my_exit(int n);
extern void *my_malloc(size_t n);

extern clock_t base_time;
extern double *clock_stack;
extern void push_clock();
extern double pop_clock();
extern double consolidated_time[10], gc_time;
extern bool volatile already_in_gc, tick_on_gc_exit;
extern bool volatile interrupt_pending, tick_pending;
extern int deal_with_tick();
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
// Handlers registered using signal() are expected to have C linkage, and
// may not necessarily be supported otherwise. There are severe restrictions
// on what may be done within one, but if our system adhers to Posix it is
// legal to use longjmp.
extern "C" void low_level_signal_handler(int code);
extern "C" void sigint_handler(int code);
extern "C" int async_interrupt(int a);

extern "C" void record_get(LispObject tag, bool found);

//
// Functions used internally - not to be installed in Lisp function
// cells, but some of these may end up getting called using special
// non-standard conventions when the Lisp compiler has been at work.
//

// Note that some things here are declared to use C rather than C++ linkage.
// These are things that will be exported for use by other applications that
// might arrange to build CSL/Reduce as a DLL and hook into it from outside.
// See impex.def for the list of names where this can happen.

extern int         primep(int32_t);
extern void        set_up_functions(int restartp);
extern void        get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(unsigned char *code, LispObject lit,
                                       LispObject *entry_stack);
extern bool     complex_stringp(LispObject a);
extern LispObject  copy_string(LispObject a, size_t n);
extern void        freshline_trace();
extern void        freshline_debug();
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void       convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t   Crand();
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(LispObject a);
extern "C" bool eql_fn(LispObject a, LispObject b);
extern "C" bool cl_equal_fn(LispObject a, LispObject b);
extern "C" bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
                               const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs,
                        LispObject env, LispObject fname);
extern LispObject apply_lambda(LispObject def, int nargs,
                               LispObject env, LispObject name);
extern void        deallocate_pages();
extern void        drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern "C" LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern uint32_t  hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" bool        geq2(LispObject a, LispObject b);
extern "C" bool        greaterp2(LispObject a, LispObject b);
extern "C" bool        lesseq2(LispObject a, LispObject b);
extern "C" bool        lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
                            LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
                        LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, int32_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
                              one_args *f1, two_args *f2, n_args *fn);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern "C" LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern "C" LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern FILE        *open_file(char *filename, const char *original_name,
                              size_t n, const char *dirn, FILE *old_file);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern void        preserve(const char *msg, size_t len);
extern void        preserve_native_code();
extern void        relocate_native_function(unsigned char *bps);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t &len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prinhex_to_trace(const char *msg, LispObject value);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void        print_bignum(LispObject u, bool blankp, int nobreak);
extern void        print_bighexoctbin(LispObject u,
                                      int radix, int width, bool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
                          LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject quotrem2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void        read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
                          int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(const char *why, int line, const char *file);
extern int check_env(LispObject env);
#endif
extern bool do_not_kill_native_code;
extern void        set_fns(LispObject sym, one_args *f1,
                           two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern void        set_up_variables(int restart_flag);
extern void        warm_setup();
extern void        write_everything();
extern LispObject  simplify_string(LispObject s);
extern bool        stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t     thirty_two_bits(LispObject a);
extern int64_t     sixty_four_bits(LispObject a);

extern uint64_t crc64(uint64_t crc, const void *buf, size_t size);
// I now use the zlib version of crc32 so do not need a declaration here.
// extern uint32_t crc32(uint32_t crc, const void *buf, size_t size);

#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) // nothing
#endif

//
// The next few provide support for multiple values. In the past I had
// these as #define macros, which had a hidden trap if one wrote
// (say) "return onevalue(something_complicated);" and evaluation of the
// complicated thing could set the multiple values variable. Here using
// inline procedures the variable exit_count should always be set right
// at the end, as required.
//
static inline LispObject onevalue(LispObject r)
{   exit_count = 1;
    return r;
}
static inline LispObject nvalues(LispObject r, int n)
{   exit_count = n;
    return r;
}

//
// The function "equal" seems to be pretty critical (certainly for Standard
// Lisp mode and Reduce). So I write out the top-level part of it in-line
// and only call the (messy) function in cases where it might be worth-while.
// For Common Lisp I will presumably look at eql and cl_equal as well.
// The test here says:
//   If a and b are EQ then they are EQUAL,
//   else if a and b have different types they are not EQUAL
//   else if a has type fixnum, odds, sfloat, symbol
//            then they are not EQUAL (those types need to be EQ to be EQUAL)
//   otherwise call equal_fn(a, b) to decide the issue.
//
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      need_more_than_eq(a) &&                      \
      equal_fn(a, b)))

#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      need_more_than_eq(a) &&                      \
      cl_equal_fn(a, b)))

#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      need_more_than_eq(a) &&                      \
      eql_fn(a, b)))

//
// Helpers for the bignum arithmetic code...
//

extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                        uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);

#define argcheck(var, n, msg) if ((var)!=(n)) aerror(msg);

extern n_args      *no_arg_functions[];
extern no_args     *new_no_arg_functions[];
extern one_args    *one_arg_functions[];
extern two_args    *two_arg_functions[];
extern four_args   *four_arg_functions[];
extern n_args      *three_arg_functions[];
extern void        *useful_functions[];
extern char        *address_of_var(int n);

typedef struct setup_type
{   const char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;

typedef struct setup_type_1
{   const char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;

extern setup_type const
    arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
    arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
    eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
    lisphash_setup[], newhash_setup[], print_setup[], read_setup[],
    restart_setup[], mpi_setup[];

extern setup_type const
    u01_setup[], u02_setup[], u03_setup[], u04_setup[],
    u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
    u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
    u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
    u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
    u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
    u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
    u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
    u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
    u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
    u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
    u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
    u60_setup[];

extern setup_type const *setup_tables[];

#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif

#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif

extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
                           LispObject env, int compilerp);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);

//
// The variables here are always extern - they never survive in an image
// file.
//
extern LispObject resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;

//
// Flags used to toggle the protection or otherwise of symbols, and
// whether to warn about attempts to redefine them.
//
extern bool symbol_protect_flag, warn_about_protected_symbols;

#ifdef HASH_STATISTICS
extern uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2, Nhputtmp;
extern uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
#endif

#endif // header_externs_h

// end of externs.h
