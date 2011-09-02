/* externs.h                            Copyright (C) Codemist 1989-2002 */

/*
 *   Main batch of extern declarations.
 *
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */



/* Signature: 1241cdfd 10-Oct-2002 */

#ifndef header_externs_h
#define header_externs_h 1

#ifndef header_machine_h
#include "machine.h"
#endif

#ifndef header_tags_h
#include "tags.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_MPI
#include "mpi.h"
extern int32 mpi_rank,mpi_size;
#endif

#ifdef MEMORY_TRACE
#define my_pop() (memory_reference((int32)stack), (*stack--))
#else
#define my_pop() (*stack--)
#endif


extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;

#ifndef NO_COPYING_GC
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#endif

extern int32 pages_count,
             heap_pages_count, vheap_pages_count,
             bps_pages_count, native_pages_count;

#ifndef NO_COPYING_GC
extern int32 new_heap_pages_count, new_vheap_pages_count,
             new_bps_pages_count, new_native_pages_count;
#endif

extern int native_pages_changed;
extern int32 native_fringe;

extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32 stack_segsize;  /* measured in units of one CSL page */
extern DLLexport Lisp_Object *C_stack;
#define stack C_stack

#ifdef MEMORY_TRACE

#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); } while (0)
/* push2 etc are just like push, but grouped together */
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); \
                          *++stack = (c); \
                          memory_reference((intxx)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); \
                          *++stack = (c); \
                          memory_reference((intxx)stack); \
                          *++stack = (d); \
                          memory_reference((intxx)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intxx)stack); \
                          *++stack = (b); \
                          memory_reference((intxx)stack); \
                          *++stack = (c); \
                          memory_reference((intxx)stack); \
                          *++stack = (d); \
                          memory_reference((intxx)stack); \
                          *++stack = (e); \
                          memory_reference((intxx)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)

#define pop(a)          { memory_reference((intxx)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; memory_reference((intxx)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; memory_reference((intxx)stack); (c) = *stack--; \
                          memory_reference((intxx)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intxx)stack); (a) = *stack--; memory_reference((intxx)stack); (b) = *stack--; memory_reference((intxx)stack); (c) = *stack--; \
                          memory_reference((intxx)stack); (d) = *stack--; memory_reference((intxx)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n);

#else /* MEMORY_TRACE */

#define push(a)         { *++stack = (a); }
/* push2 etc are just like push, but grouped together */
#ifdef USE_AUTOINDEX
/*
 * Having inspected the code generated by one of the C compilers that
 * is frequently used with this Lisp it emerges that the multiple
 * push operations might sometimes be much better treated with
 * the increment parts explicitly consolidated into one. To leave
 * scope for fine-tuning to cmpiler and machine architecture the
 * USE_AUTOINDEX macro could be pre-defined and I suspect that on
 * VAX and ARM computers it may make good sense.
 */
#define push2(a,b)      { *++stack = (a); *++stack = (b); }
#define push3(a,b,c)    { *++stack = (a); *++stack = (b); *++stack = (c); }
#define push4(a,b,c,d)  { *++stack = (a); *++stack = (b); *++stack = (c); \
                          *++stack = (d); }
#define push5(a,b,c,d,e){ *++stack = (a); *++stack = (b); *++stack = (c); \
                          *++stack = (d); *++stack = (e); }
#define push6(a,b,c,d,e,f) {push3(a,b,c); push3(d,e,f)}

#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { (a) = *stack--; (b) = *stack--; }
#define pop3(a,b,c)     { (a) = *stack--; (b) = *stack--; (c) = *stack--; }
#define pop4(a,b,c,d)   { (a) = *stack--; (b) = *stack--; (c) = *stack--; \
                          (d) = *stack--; }
#define pop5(a,b,c,d,e) { (a) = *stack--; (b) = *stack--; (c) = *stack--; \
                          (d) = *stack--; (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n);
#else /* USE_AUTOINDEX */
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
#define popv(n)           stack -= (n);
#endif /* USE_AUTOINDEX */
#endif /* MEMORY_TRACE*/

#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }

#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7



#ifdef CHECK_STACK

#ifdef SOFTWARE_TICKS

extern DLLexport int32 countdown;
#ifdef INITIAL_SOFTWARE_TICKS
extern DLLexport int32 software_ticks;
#endif

#define stackcheck0(k)                                      \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck1(k, a1)                                  \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck2(k, a1, a2)                              \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck3(k, a1, a2, a3)                          \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck4(k, a1, a2, a3, a4)                      \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#else  /* SOFTWARE_TICKS */

#define stackcheck0(k)                                      \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if (stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck1(k, a1)                                  \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if (stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck2(k, a1, a2)                              \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if (stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck3(k, a1, a2, a3)                          \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if (stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck4(k, a1, a2, a3, a4)                      \
    if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow"); \
    if (stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#endif /* SOFTWARE_TICKS */

#else  /* CHECK_STACK */

#ifdef SOFTWARE_TICKS

extern DLLexport int32 countdown;
#ifdef INITIAL_SOFTWARE_TICKS
extern DLLexport int32 software_ticks;
#endif

#define stackcheck0(k)                                      \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck1(k, a1)                                  \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck2(k, a1, a2)                              \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck3(k, a1, a2, a3)                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck4(k, a1, a2, a3, a4)                      \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#else  /* SOFTWARE_TICKS */

#define stackcheck0(k)                                      \
    if (stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck1(k, a1)                                  \
    if (stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck2(k, a1, a2)                              \
    if (stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck3(k, a1, a2, a3)                          \
    if (stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#define stackcheck4(k, a1, a2, a3, a4)                      \
    if (stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }

#endif /* SOFTWARE_TICKS */
#endif /* CHECK_STACK */

/*
 * As well as being used to point directly to the major Lisp item NIL,
 * this register is used as a base for a table of other critically
 * important other Lisp values.  Offsets for at least some of these are
 * defined here.
 * I also need a proper C external variable holding the value of NIL since
 * when called from the C library (e.g. in a signal handler) the global
 * register variable will not be available!
 */

extern DLLexport Lisp_Object C_nil;

/*
 * In COMMON mode the symbol-head for NIL uses the first few offsets
 * from NIL here, so I start storing system variables at offset 12 so
 * that even if at some stage I expand the size of all identifiers from the
 * present state I will be safe.
 */

#define first_nil_offset         50     /* GC collector marks from here up */

/*
 * A vector of 50 words is used by the interpreter when preparing args
 * for functions and when handling multiple values.
 */

#define work_0_offset           200

/* Garbage collector marks up to but not including last_nil_offset */
#define last_nil_offset         251

/*
 * NIL_SEGMENT_SIZE must be over-large by enough to allow for
 * space lost while rounding nil up to be a multiple of 8. Also in the
 * Common Lisp case I need to give myself a spare word BEFORE the place
 * where C_nil points.
 */
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)

/*
 * I give myself a margin of SPARE bytes at the end of a page so that I can
 * always CONS that amount (even without a garbage collection check) and not
 * corrupt anything.  The main use for this is that sometimes I need to
 * convert a set of multiple values or of arguments from values on the
 * (C-) stack or wherever va_arg() can find them into a list structure, and
 * to avoid horrible potential problems with a garbage collection spotting]
 * an exception (notably a ^C interrupt), running arbitrary code in an
 * exception ghandler and then continuing, I need to cons those things up
 * without any possible GC.  The function cons_no_gc does that, and
 * I should then call cons_gc_test() afterwards to regularise the situation.
 * 512 bytes here leaves room for 64 conses, and I support at most 50
 * (multiple-) values so I hope this is safe.
 */

#define SPARE                   512

/*
 * I want my table of addresses here to be 8-byte aligned on 64-bit
 * machines...
 */
#ifdef ADDRESS_64
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE ((Lisp_Object *)(nil+4))
#endif
#else
#define BASE ((Lisp_Object *)nil)
#endif

#ifdef NILSEG_EXTERNS
/*
 * One some computers (ones with plenty of registers, and where the
 * main addressing mode is register-indexed, and where optimising
 * an compiler can keep variables in registers all the time, it will
 * be most efficient to put major system variables addressed as offsets
 * from NIL, where I expect to keep nil in a register variable pretty
 * well always.  On other machines (notable the Intel 80286) that policy
 * gives pretty disasterous code, and the use of direct simple external
 * variables will win.  In PRESERVE and RESTORE I will have to copy
 * all the separate external variables into a compact block for
 * transfer to and from files.  Actually on many (most?) machines the
 * choice of whether this option should be enabled or not will be pretty
 * marginal and should really be sorted out by building once with
 * NILSEG_EXTERNS and once without, and comparing the performance of the
 * two resulting systems.
 */

#define nil_as_base

extern unsigned32 byteflip;

extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;

extern Lisp_Object * volatile stacklimit;

extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;

extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;

extern int32 nwork;

extern int32 exit_reason;
extern DLLexport int32 exit_count;
extern unsigned32 gensym_ser, print_precision, miscflags;
extern int32 current_modulus, fastget_size, package_bits;

extern DLLexport Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern DLLexport Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern DLLexport Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern DLLexport Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern DLLexport Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern DLLexport Lisp_Object current_package, startfn;
extern DLLexport Lisp_Object gensym_base, string_char_sym, boffo;
extern DLLexport Lisp_Object err_table;
extern DLLexport Lisp_Object progn_symbol;
extern DLLexport Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern DLLexport Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern DLLexport Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern DLLexport Lisp_Object tracedfn, lisp_terminal_io;
extern DLLexport Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern DLLexport Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern DLLexport Lisp_Object prompt_thing, faslgensyms;
extern DLLexport Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern DLLexport Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern DLLexport Lisp_Object cl_symbols, active_stream, current_module;
extern DLLexport Lisp_Object features_symbol, lisp_package;
extern DLLexport Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern DLLexport Lisp_Object get_counts, fastget_names, input_libraries;
extern DLLexport Lisp_Object output_library, current_file, break_function;
extern DLLexport Lisp_Object standard_output, standard_input, debug_io;
extern DLLexport Lisp_Object error_output, query_io, terminal_io;
extern DLLexport Lisp_Object trace_output, fasl_stream;
extern DLLexport Lisp_Object native_code, native_symbol, traceprint_symbol;
extern DLLexport Lisp_Object loadsource_symbol;
extern DLLexport Lisp_Object hankaku_symbol;

#ifdef COMMON
extern DLLexport Lisp_Object keyword_package;
extern DLLexport Lisp_Object all_packages, package_symbol, internal_symbol;
extern DLLexport Lisp_Object external_symbol, inherited_symbol;
extern DLLexport Lisp_Object key_key, allow_other_keys, aux_key;
extern DLLexport Lisp_Object format_symbol;
extern DLLexport Lisp_Object expand_def_symbol, allow_key_key, declare_symbol;
extern DLLexport Lisp_Object special_symbol;
#endif

#ifdef OPENMATH
extern DLLexport Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern DLLexport Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern DLLexport Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern DLLexport Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern DLLexport Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern DLLexport Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern DLLexport Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern DLLexport Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern DLLexport Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern DLLexport Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern DLLexport Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern DLLexport Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern DLLexport Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern DLLexport Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern DLLexport Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern DLLexport Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern DLLexport Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern DLLexport Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern DLLexport Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);

extern DLLexport Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern DLLexport Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);

extern DLLexport Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern DLLexport Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern DLLexport Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern DLLexport Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern DLLexport Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern DLLexport Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif

extern Lisp_Object workbase[51];

extern DLLexport Lisp_Object user_base_0, user_base_1, user_base_2;
extern DLLexport Lisp_Object user_base_3, user_base_4, user_base_5;
extern DLLexport Lisp_Object user_base_6, user_base_7, user_base_8;
extern DLLexport Lisp_Object user_base_9;

#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]

#else /* NILSEG_EXTERNS */

#define nil_as_base  Lisp_Object nil = C_nil;

#define byteflip              (*(unsigned32 *)&BASE[12])
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
/*
 * On a machine where sizeof(void *)=8 and alignment matters I need to arrange for
 * stacklimit to be properly aligned. Also I MUST do the address calculation
 * in a way that does not get muddled by the "sizeof(void *)" issue. I
 * reserve nilseg offsets 15, 16 and 17 for this.
 */
#ifdef COMMON
#define stacklimit            (*(Lisp_Object * volatile *) \
                                  &BASE[16])
#else
#define stacklimit            (*(Lisp_Object * volatile *)&BASE[15])
#endif
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             (*(unsigned32 *)&BASE[22])

#define nwork                 (*(int32 *)&BASE[24])
#define exit_reason           (*(int32 *)&BASE[25])
#define exit_count            (*(int32 *)&BASE[26])
#define gensym_ser            (*(unsigned32 *)&BASE[27])
#define print_precision       (*(unsigned32 *)&BASE[28])
#define current_modulus       (*(int32 *)&BASE[29])
#define fastget_size          (*(int32 *)&BASE[30])
#define package_bits          (*(int32 *)&BASE[31])
/* offsets 32-49 spare at present */

/* Offset 50 used for EQ hash table list    */
/* Offset 51 used for EQUAL hash table list */
#define current_package       BASE[52]
/* current_package is treated specially by the garbage collector */

#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
/*
 * 75-89 spare for workspace-style locations
 */
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]

#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]

#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#endif


/*
 * The next are intended for use by people building custom versions
 * of CSL. They are always handled as if NILSEG_EXTERNS had been set,
 * even if it had not, since that gives the user direct access to them as
 * simple C variables. Note that they must ALWAYS be kept with proper
 * valid Lisp objects in them.
 */
/*  #define user_base_0       BASE[190] */
/*  #define user_base_1       BASE[191] */
/*  #define user_base_2       BASE[192] */
/*  #define user_base_3       BASE[193] */
/*  #define user_base_4       BASE[194] */
/*  #define user_base_5       BASE[195] */
/*  #define user_base_6       BASE[196] */
/*  #define user_base_7       BASE[197] */
/*  #define user_base_8       BASE[198] */
/*  #define user_base_9       BASE[199] */

extern DLLexport Lisp_Object user_base_0, user_base_1, user_base_2;
extern DLLexport Lisp_Object user_base_3, user_base_4, user_base_5;
extern DLLexport Lisp_Object user_base_6, user_base_7, user_base_8;
extern DLLexport Lisp_Object user_base_9;

#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]

#endif /*NILSEG_EXTERNS */

/* dummy_function_call is only used to patch around C compiler bugs! */
extern void MS_CDECL dummy_function_call(char *why, ...);

extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);

#define eq_hash_table_list     BASE[50] /* In heap image */
#define equal_hash_table_list  BASE[51] /* In heap image */
#define current_package_offset 52

extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;

/*
 * The following are used to help <escape> processing.
 */
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;

#ifdef DEBUG
extern int trace_all;
#endif

#define MAX_INPUT_FILES         40  /* limit on command-line length */
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20

extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;

#ifndef COMMON
#ifdef CWIN
extern char **loadable_packages;
extern char **switches;
#endif
#endif

#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif

extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];

extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;

extern int native_code_tag;

extern char *standard_directory;

extern CSLbool gc_method_is_copying;
extern int32 gc_number;

#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4

#define Lispify_predicate(p)  ((p) ? lisp_true : nil)

/*
 * variables used by the IO system.
 */

extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];

typedef struct Ihandle
{
    FILE *f;        /* File within which this sub-file lives */
    long int o;     /* Offset (as returned by ftell)         */
    long int n;     /* Number of bytes remaining unread here */
    unsigned32 chk; /* Checksum                              */
    int status;     /* Reading or Writing                    */
} Ihandle;

/*
 * If there is no more than 100 bytes of data then I will deem
 * file compression frivolous.  The compression code assumes that
 * it has at least 2 bytes to work on, so do NOT cut this limit down to zero.
 * Indeed more than that the limit must be greater than the length of
 * the initial header record (112 bytes).
 */

extern int32 compression_worth_while;
#define CODESIZE                0x1000

typedef struct entry_point
{
    void *p;
    char *s;
} entry_point;

#ifdef CJAVA
#define entry_table_size   132
#else
#define entry_table_size   127
#endif
extern entry_point entries_table[];

extern int doubled_execution;

#ifdef MEMORY_TRACE
extern intxx memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif

#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);

extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool Iopen(char *name, int len, CSLbool dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32 offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32 *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(void);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32 Iread(void *buff, int32 size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32 size);
extern long int Ioutsize(void);

/*
 * I will allow myself 192 bytes to store registration information.
 * In my initial implementation I will only use a fraction of that
 * but it seems safer to design the structure with extra room for potential
 * enhancements. I will keep a version code in the data so that I can update
 * my methods but still preserve upwards compatibility when I do that.
 */
#define REGISTRATION_SIZE     192
#define REGISTRATION_VERSION  "r1.0"
extern unsigned char registration_data[REGISTRATION_SIZE];
extern void MD5_Init(void);
extern void MD5_Update(unsigned char *data, int len);
extern void MD5_Final(unsigned char *md);
extern CSLbool MD5_busy;
extern unsigned char *MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
/*
 * crypt_init() seeds the encryption engine that I used, and then
 * crypt_get_block() gets a chunk of the sequence, which I can XOR with
 * text to mess it up.
 */
extern void crypt_init(char *key);
#define CRYPT_BLOCK 128
extern void crypt_get_block(unsigned char result[CRYPT_BLOCK]);
/*
 * crypt_active is -ve if none is in use, otherwise it is a key identifier
 * (to allow for possibly multiple keys). crypt_buffer & crypt_count are
 * things filled in by crypt_get_block(). The encryption stuff here is just
 * for protection of the software, and the code that does somewhat more
 * serious encryption to create the keys used with this stream cipher live
 * elsewhere. The crypto technology in CSL is only used on image files, ie
 * chunks of compiled code etc, and no provision has been made to use it
 * on user data-files. I can store up to CRYPT_KEYS different keys with
 * a CSL system and have different modules protected by different ones of
 * them.
 */
#define CRYPT_KEYS 10
extern char *crypt_keys[CRYPT_KEYS];
extern int crypt_active;
extern unsigned char *crypt_buffer;
extern int crypt_count;

extern void ensure_screen(void);
extern int window_heading;
#ifndef WINDOW_SYSTEM
#ifdef BUFFERED_STDOUT
extern clock_t last_flush;
#define ensure_screen() fflush(stdout)
#endif
#define start_up_window_manager(a) {}
#endif
extern void my_exit(int n);
extern void *my_malloc(size_t n);

extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending, polltick_pending;
extern DLLexport int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
extern jmp_buf *errorset_buffer;
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
#ifdef __WATCOMC__
extern void low_level_signal_handler(int code);
#else
extern void MS_CDECL low_level_signal_handler(int code);
#endif
extern void MS_CDECL sigint_handler(int code);
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#endif

#ifdef RECORD_GET
extern void record_get(Lisp_Object tag, CSLbool found);
#endif

/*
 * Functions used internally - not to be installed in Lisp function
 * cells, but some of these may end up getting called using special
 * non-standard conventions when the Lisp compiler has been at work.
 */

extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern DLLexport Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern DLLexport Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern DLLexport Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern DLLexport Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern unsigned32  Crand(void);
extern DLLexport Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(unsigned32 a, unsigned32 b);
extern void        discard(Lisp_Object a);
extern DLLexport CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern DLLexport CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern DLLexport CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern DLLexport CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern DLLexport CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern DLLexport Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern DLLexport Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern DLLexport Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern DLLexport Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern DLLexport Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int32 type, intxx length);
extern Lisp_Object getvector_init(intxx n, Lisp_Object v);
extern Lisp_Object getcodevector(int32 type, intxx size);
extern unsigned32  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern DLLexport CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern DLLexport CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern DLLexport CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern DLLexport CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern DLLexport Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern DLLexport Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern DLLexport Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern DLLexport Lisp_Object lognot(Lisp_Object a);
extern DLLexport Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32 n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(char *b);
extern Lisp_Object make_nstring(char *b, int32 n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern DLLexport void MS_CDECL  stdout_printf(char *fmt, ...);
extern DLLexport void MS_CDECL  term_printf(char *fmt, ...);
extern DLLexport void MS_CDECL  err_printf(char *fmt, ...);
extern DLLexport void MS_CDECL  debug_printf(char *fmt, ...);
extern DLLexport void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern DLLexport Lisp_Object ncons(Lisp_Object a);
extern DLLexport Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern DLLexport Lisp_Object negate(Lisp_Object a);
extern DLLexport Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern DLLexport Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32 *len);
extern DLLexport void prin_to_stdout(Lisp_Object u);
extern DLLexport void prin_to_terminal(Lisp_Object u);
extern DLLexport void prin_to_debug(Lisp_Object u);
extern DLLexport void prin_to_query(Lisp_Object u);
extern DLLexport void prin_to_trace(Lisp_Object u);
extern DLLexport void prin_to_error(Lisp_Object u);
extern DLLexport void loop_print_stdout(Lisp_Object o);
extern DLLexport void loop_print_terminal(Lisp_Object o);
extern DLLexport void loop_print_debug(Lisp_Object o);
extern DLLexport void loop_print_query(Lisp_Object o);
extern DLLexport void loop_print_trace(Lisp_Object o);
extern DLLexport void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern DLLexport Lisp_Object princ(Lisp_Object u);
extern DLLexport Lisp_Object print(Lisp_Object u);
extern DLLexport Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern DLLexport Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern DLLexport Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern DLLexport Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern DLLexport Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intxx size);
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern DLLexport Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32       thirty_two_bits(Lisp_Object a);
#ifdef ADDRESS_64
extern int64       sixty_four_bits(Lisp_Object a);
#endif

#ifdef DEMO_MODE
extern void give_up();
#endif
#ifdef DEMO_BUILD
extern int32 demo_key1, demo_key2;
#endif

/*
 * The next few provide support for multiple values.
 */
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif

#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
/*
 * I lift the top test from eval out to be in-line so that I can
 * (rather often) avoid the overhead of a procedure call when return from
 * it will be almost immediate.  The effect is that in CSL mode Ceval is
 * only ever called on a list.  NB the first arg to eval gets evaluated
 * several times here - maybe I will just hope that CSE optimisation picks
 * up this sort of repetition...
 */
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
/* voideval(a, b) is like (void)eval(a, b) */
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) /* Beware "else" after this */
#endif

/*
 * The function "equal" seems to be pretty critical (certainly for Standard
 * Lisp mode and Reduce). So I write out the top-level part of it in-line
 * and only call the (messy) function in cases where it might be worth-while.
 * For Common Lisp I will presumably look at eql and cl_equal as well.
 * The test here says:
 *   If a and b are EQ then they are EQUAL,
 *   else if a and b have different types they are not EQUAL
 *   else if a has type 1, 2, 3 or 4 (ie fixnum, odds, sfloat, symbol)
 *            then they are not EQUAL (those types need to be EQ to be EQUAL)
 *   otherwise call equal_fn(a, b) to decide the issue.
 */
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))

#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))

#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))

/*
 * Helpers for the bignum arithmetic code...
 */

#ifndef IMULTIPLY
extern unsigned32 Imultiply(unsigned32 *rlow, unsigned32 a,
                            unsigned32 b, unsigned32 c);
#endif
#ifndef IDIVIDE
extern unsigned32 Idivide(unsigned32 *qp, unsigned32 a,
                          unsigned32 b, unsigned32 c);
extern unsigned32 Idiv10_9(unsigned32 *qp, unsigned32 a, unsigned32 b);
#endif

/*
 * UNSAFE removes some checks - but it does noy seem to make much difference
 * so I rather strongly suggest that you do not enable it!
 */
#ifdef UNSAFE
# define argcheck(var, n, msg) (var) = (var);
#else
# define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
#endif

extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);

typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;

extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
extern setup_type const
       u01_setup[], u02_setup[], u03_setup[], u04_setup[],
       u05_setup[], u06_setup[], u07_setup[], u08_setup[],
       u09_setup[], u10_setup[], u11_setup[], u12_setup[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif

#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif

extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);

/* 
 * Flags used to toggle the protection or otherwise of symbols, and 
 * whether to warn about attempts to redefine them.
 */
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;

#ifdef __cplusplus
}
#endif

/*
 * Now declare entrypoints to machine-dependent code fragments...
 */

#include "sys.h"

#endif /* header_externs_h */

/* end of externs.h */
