//  fns2.cpp                          Copyright (C) 1989-2016 Codemist    

//
// Basic functions part 2.
//

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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

#ifdef DEBUG_VALIDATE
static int validate_count = 0;
#endif

LispObject Lget_bps(LispObject nil, LispObject n)
{   if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("get-bps", n);
    intptr_t n1 = int_of_fixnum(n);
    n = getvector(TAG_VECTOR, TYPE_BPS_4, n1+CELL);
    errexit();
    return onevalue(n);
}

#ifdef REINSTATE_NATIVE_CODE_EXPERIMENT

///*
// WARNING. This code is intended to allocate space into which I will post
// executable code. Under a really old-fashioned "spirit of C" even though
// grabbing space with malloc and re-using it this way was officially not
// guaranteed one could typically expect to get away with it. Well apart
// on Harvard-architecture machines where code and data addresses are quite
// distinct. But more recently - I have become aware of it hitting wide
// distribution in Fedora Core in late 2003 - security concerns have prompted
// some major vendors to move to a model where malloc space is explicitly
// locked down as non-executable. In such cases, which may become increasingly
// common, it will be VITAL to adjust what lies behind this to perform
// system calls to arrange that pages that will be used for native code are
// tagged as executable. Maybe it is just as well that at present this is
// an experimental extension to CSL and is not ready for general use anyway!
//

LispObject get_native_code_vector(size_t size)
{
//
// Create some space for native code and return a handle that identifies
// its start point. size is measured in bytes.
//
    LispObject nil = C_nil;
    if (size == 0) size = 8;
    for (;;)
    {   size_t alloc_size = (size_t)doubleword_align_up(size);
        intptr_t cf = native_fringe;
        size_t free = CSL_PAGE_SIZE - cf - 0x100; // 256 bytes to be safe
//
// When I start up a cold CSL I will have native_fringe set to zero and
// native_pages_count also zero, indicating that there is none of this stuff
// active.
//
        if (native_fringe == 0 || alloc_size > free)
        {   char msg[40];
            sprintf(msg, "native code %ld", (long)size);
            reclaim(nil, msg, GC_NATIVE, alloc_size);
            errexit();
            continue;
        }
        free = (intptr_t)native_pages[native_pages_count-1];
        free = doubleword_align_up(free);
//
// I put the number of bytes in this block as the first word of the chunk
// of memory, and arrange that there is a zero in what would be the first
// word of unused space. Provided the user does not clobber bytes 0 to 4
// or the block this is enough to allow restart code to scan through all
// native code segments.
//
        car32(free+native_fringe) = alloc_size;
        car32(free+native_fringe+alloc_size) = 0;
        native_fringe += alloc_size;
        native_pages_changed = 1;
        return Lcons(nil,
                     fixnum_of_int(native_pages_count-1),
                     fixnum_of_int(cf));
    }
}

LispObject Lget_native(LispObject nil, LispObject n)
{   if (!is_fixnum(n) || (intptr_t)n<0) return aerror1("get-native", n);
    intptr_t n1 = int_of_fixnum(n);
    n = get_native_code_vector(n1);
    errexit();
    return onevalue(n);
}

bool do_not_kill_native_code = false;

#endif // REINSTATE_NATIVE_CODE_EXPERIMENT

// Soon this will need to take FIVE functions not THREE. Specifically ones
// that support 0, 1, 2, 3 and 4+ arguments.

void set_fns(LispObject a, one_args *f1, two_args *f2, n_args *fn)
{
#ifdef REINSTATE_NATIVE_CODE_EXPERIMENT
    LispObject nil = C_nil;
    LispObject w1, w2, w3 = nil;
//
// If I redefine a function for any reason (except to set trace options
// on a bytecoded definition) I will discard any native-coded definitions
// by splicing them out of the record. I provide a global variable to
// defeat this behaviour (ugh).
//
    if (!do_not_kill_native_code)
    {   for (w1 = native_code; w1!=nil; w1=qcdr(w1))
        {   w2 = qcar(w1);
            if (qcar(w2) == a) break;
            w3 = w1;
        }
        if (w1 != nil)
        {   w1 = qcdr(w1);
            if (w3 == nil) native_code = w1;
            else qcdr(w3) = w1;
        }
    }
#endif // REINSTATE_NATIVE_CODE_EXPERIMENT
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR))
    {   if (symbol_protect_flag)
        {   if (warn_about_protected_symbols)
            {   trace_printf("+++ WARNING: protected function ");
                prin_to_trace(a);
                trace_printf(" not redefined\n");
            }
            return;
        }
        else
        {   if (warn_about_protected_symbols)
            {   trace_printf("+++ WARNING: protected function ");
                prin_to_trace(a);
                trace_printf(" *has* been redefined\n");
            }
            Lsymbol_protect(C_nil, a, C_nil);
        }
    }
    ifn1(a) = (intptr_t)f1;
    ifn2(a) = (intptr_t)f2;
    ifnn(a) = (intptr_t)fn;
}

#ifdef HIDE_USELESS_SYMBOL_ENVIRONMENTS

static bool interpreter_entry(LispObject a)
//
// If a function will be handled by the interpreter, including the case
// of it being undefined, then the fn1() cell will tell me so.
//
{   return (
               qfn1(a) == interpreted1 ||
               qfn1(a) == traceinterpreted1 ||
               qfn1(a) == double_interpreted1 ||
               qfn1(a) == funarged1 ||
               qfn1(a) == tracefunarged1 ||
               qfn1(a) == double_funarged1 ||
               qfn1(a) == undefined1);
}

#endif

// Here again I will need to deal with 0 and 3-argument cases...

static const char *c_fn1(one_args *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].one == p) return s[i].name;
    return NULL;
}

static const char *c_fn2(two_args *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].two == p) return s[i].name;
    return NULL;
}

static const char *c_fnn(n_args *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].n == p) return s[i].name;
    return NULL;
}

static const char *show_fn1(one_args *p)
{   int i;
    const char *r;
    for (i=0; entries_table1[i].s!=NULL; i++)
        if (entries_table1[i].p == p) return entries_table1[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fn1(p, setup_tables[i])) != NULL) return r;
// There are more entries in setup_tables after the first NULL!
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fn1(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static const char *show_fn2(two_args *p)
{   int i;
    const char *r;
    for (i=0; entries_table2[i].s!=NULL; i++)
        if (entries_table2[i].p == p) return entries_table2[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fn2(p, setup_tables[i])) != NULL) return r;
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fn2(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static const char *show_fnn(n_args *p)
{   int i;
    const char *r;
    for (i=0; entries_tablen[i].s!=NULL; i++)
        if (entries_tablen[i].p == p) return entries_tablen[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fnn(p, setup_tables[i])) != NULL) return r;
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fnn(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

LispObject Lsymbol_fn_cell(LispObject nil, LispObject a)
//
// For debugging... This looks in the 3 (soon 5) function cells that any
// symbol has and attempts to display the name of the function there.
// There are enough tables for me to find the names of MANY things, but I
// do not guarantee everything.
//
{   const char *s1, *s2, *sn;
    if (!symbolp(a)) return onevalue(nil);
    s1 = show_fn1(qfn1(a));
    s2 = show_fn2(qfn2(a));
    sn = show_fnn(qfnn(a));
    trace_printf("%s %s %s\n", s1, s2, sn);
    return onevalue(nil);
}

// This should show the header of any symbol, any vector or
// any numeric value that has a header... It is JUST for debugging, and it
// prints information but does not return a useful value.

LispObject Lobject_header(LispObject nil, LispObject a)
{   if (is_symbol(a))
    {   Header h = qheader(a);
        trace_printf("Symbol: (%" PRIxPTR ") ", h);
        if ((h & SYM_SPECIAL_VAR) != 0) trace_printf(" fluid");
        if ((h & SYM_GLOBAL_VAR) != 0) trace_printf(" global");
        if ((h & SYM_SPECIAL_FORM) != 0) trace_printf(" special-form");
        if ((h & SYM_MACRO) != 0) trace_printf(" macro");
        if ((h & SYM_C_DEF) != 0) trace_printf(" C-def");
        if ((h & SYM_CODEPTR) != 0) trace_printf(" codeptr");
        if ((h & SYM_ANY_GENSYM) != 0) trace_printf(" any-gensym");
        if ((h & SYM_TRACED) != 0) trace_printf(" traced");
        if ((h & SYM_FASTGET_MASK) != 0) trace_printf(" fastget");
        trace_printf("\n");
    }
    else if (is_vector(a))
    {   Header h = vechdr(a);
        trace_printf("Symbol: (%" PRIxPTR ") ", h);
        trace_printf("Rounded up length in bytes units = %" PRIuPTR "\n",
                     length_of_header(h));
        if (!vector_holds_binary(h))
            trace_printf("Holds %" PRIuPTR " pointers\n",
                         length_of_header(h)/CELL);
        else if (is_bitvec_header(h))
            trace_printf("Bits %" PRIuPTR "\n", length_of_bitheader(h));
        else if (vector_i8(h))
            trace_printf("Bytes %" PRIuPTR "\n", length_of_byteheader(h));
        else if (vector_i16(h))
            trace_printf("Halfwords %" PRIuPTR "\n", length_of_hwordheader(h));
        else if (vector_i32(h))
            trace_printf("32-bit data " PRIuPTR "\n",
                length_of_header(h)/4);
        else if (vector_i64(h))
            trace_printf("64-bit data " PRIuPTR "\n",
                length_of_header(h)/8);
        else if (vector_i128(h))
            trace_printf("128-bit data " PRIuPTR "\n",
                length_of_header(h)/16);
        else if (vector_f32(h))
            trace_printf("32-bit floating point data " PRIuPTR "\n",
                length_of_header(h)/4);
        else if (vector_f64(h))
            trace_printf("64-bit floating point data " PRIuPTR "\n",
                length_of_header(h)/8);
        else if (vector_f128(h))
            trace_printf("128-bit floating point data " PRIuPTR "\n",
                length_of_header(h)/16);
        else trace_printf("Unknown vector type\n");
    }
// I will expand the following two cases if at some stage my debugging needs
// make that important.
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        trace_printf("Number: (%" PRIxPTR ") ", h);
        trace_printf("\n");
    }
    else if (is_bfloat(a))
    {   Header h = flthdr(a);
        trace_printf("Floating point: (%" PRIxPTR ") ", h);
        trace_printf("\n");
    }
    return onevalue(nil);
}

LispObject Lsymbol_argcount(LispObject nil, LispObject a)
//
// For debugging and JIT compiler use. Only valid if the function involved
// is byte-coded. For simple functions taking a fixed number of args the
// result is an integer. Otherwise it is a list of 3 items
//   (fewest-legal-args most-args-before-&rest flags)
// where the flags has a 1 bit if missing &optional args are to be left
// for the bytecoded stuff to unpick, otherwise they should be mapped to nil
// somewhere. The 2 bit is present if a &rest argument is present.
//
{   one_args *f1;
    two_args *f2;
    n_args *fn;
    int low, high, hardrest;
    LispObject r;
    unsigned char *b;
    if (!symbolp(a)) return onevalue(nil);
    f1 = qfn1(a);
    f2 = qfn2(a);
    fn = qfnn(a);
    r = qenv(a);
    if (!consp(r)) return onevalue(nil);
    r = qcar(r);
    if (!is_bps(r)) return onevalue(nil);
    b = (unsigned char *)data_of_bps(r);
    if (f1 == bytecoded1 ||
        f1 == tracebytecoded1 ||
        f1 == f1_as_0 ||
        f1 == f1_as_1 ||
#ifdef JIT
        f1 == jitcompileme1 ||
#endif
        f1 == double_bytecoded1) return onevalue(fixnum_of_int(1));
    if (f2 == bytecoded2 ||
        f2 == tracebytecoded2 ||
        f2 == f2_as_0 ||
        f2 == f2_as_1 ||
        f2 == f2_as_2 ||
#ifdef JIT
        f2 == jitcompileme2 ||
#endif
        f2 == double_bytecoded2) return onevalue(fixnum_of_int(2));
    if (fn == bytecoded0 ||
        fn == tracebytecoded0 ||
        fn == f0_as_0 ||
#ifdef JIT
        fn == jitcompileme0 ||
#endif
        fn == double_bytecoded0) return onevalue(fixnum_of_int(0));
    if (fn == bytecoded3 ||
        fn == tracebytecoded3 ||
        fn == f3_as_0 ||
        fn == f3_as_1 ||
        fn == f3_as_2 ||
        fn == f3_as_3 ||
#ifdef JIT
        fn == jitcompileme3 ||
#endif
        fn == double_bytecoded3) return onevalue(fixnum_of_int(3));
    if (fn == bytecodedn ||
        fn == tracebytecodedn ||
#ifdef JIT
        fn == jitcompilemen ||
#endif
        fn == double_bytecodedn) return onevalue(fixnum_of_int(b[0]));
    low = b[0];          // smallest number of valid args
    high = low + b[1];   // largest number before &rest is accounted for
    hardrest = 0;
//
// byteopt - optional arguments, with default of NIL
//
    if (f1 == byteopt1 ||
        f1 == tracebyteopt1) hardrest = 0;
//
// hardopt - optional arguments but default is passed as a SPID so that
// the user can follow up and apply cleverer default processing
//
    else if (f1 == hardopt1 ||
             f1 == tracehardopt1) hardrest = 1;
//
// byteoptrest - anything with a &rest argument on the end.
//
    else if (f1 == byteoptrest1 ||
             f1 == tracebyteoptrest1) hardrest = 1;
//
// hardoptrest - some &optional args with non-nil default value, plus &rest
//
    else if (f1 == hardoptrest1 ||
             f1 == tracehardoptrest1) hardrest = 3;
    else return onevalue(nil);
    r = list3(fixnum_of_int(low),
              fixnum_of_int(high), fixnum_of_int(hardrest));
    errexit();
    return onevalue(r);
}

LispObject Lsymbol_argcode(LispObject nil, LispObject a)
//
// This hands back a single integer that encodes what must be in the
// three function cells for anything byte-coded.
// Or nil if the argument did not name a bytecoded function.
//
{
#define BYTE_ARGMASK 0x007    // 0, 1, 2, 3 or 4. 4 means "4 or more"
#define BYTE_OPT     0x008    // &optional present
#define BYTE_HARDOPT 0x010    // "hard" case of &optional
#define BYTE_REST    0x020    // &rest present
#define BYTE_TRACED  0x040
#define BYTE_DOUBLED 0x080
#define BYTE_CALLAS  0x100    // link to some other function
//
// I can not see any way much better than a grim sequence of explicit
// tests to achieve what I want here.
//
    one_args *f1;
    two_args *f2;
    n_args *fn;
    LispObject r;
    int val;
    if (!symbolp(a)) return onevalue(nil);
    f1 = qfn1(a);
    f2 = qfn2(a);
    fn = qfnn(a);
    r = qenv(a);
    if (!consp(r)) return onevalue(nil);
    r = qcar(r);
    if (!is_bps(r)) return onevalue(nil);
    if (f1 == bytecoded1) val = 1;
#ifdef JIT
    else if (f1 == jitcompileme1) val = 1;
#endif
    else if (f1 == tracebytecoded1) val = 1 + BYTE_TRACED;
    else if (f1 == double_bytecoded1) val = 1 + BYTE_DOUBLED;
    else if (f2 == bytecoded2) val = 2;
#ifdef JIT
    else if (f2 == jitcompileme2) val = 2;
#endif
    else if (f2 == tracebytecoded2) val = 2 + BYTE_TRACED;
    else if (f2 == double_bytecoded2) val = 2 + BYTE_DOUBLED;
    else if (fn == bytecoded0) val = 0;
#ifdef JIT
    else if (fn == jitcompileme0) val = 0;
#endif
    else if (fn == tracebytecoded0) val = 0 + BYTE_TRACED;
    else if (fn == double_bytecoded0) val = 0 + BYTE_DOUBLED;
    else if (fn == bytecoded3) val = 3;
#ifdef JIT
    else if (fn == jitcompileme3) val = 3;
#endif
    else if (fn == tracebytecoded3) val = 3 + BYTE_TRACED;
    else if (fn == double_bytecoded3) val = 3 + BYTE_DOUBLED;
    else if (fn == bytecodedn) val = 4;
#ifdef JIT
    else if (fn == jitcompilemen) val = 4;
#endif
    else if (fn == tracebytecodedn) val = 4 + BYTE_TRACED;
    else if (fn == double_bytecodedn) val = 4 + BYTE_DOUBLED;
//
// I observe that I do not support double-execute for &optional and &rest
// functions. I do not mind that too much!
//
    else if (f1 == byteopt1) val = BYTE_OPT;
    else if (f1 == tracebyteopt1) val = BYTE_OPT + BYTE_TRACED;
    else if (f1 == hardopt1) val = BYTE_HARDOPT;
    else if (f1 == tracehardopt1) val = BYTE_HARDOPT + BYTE_TRACED;
    else if (f1 == byteoptrest1) val = BYTE_OPT + BYTE_REST;
    else if (f1 == tracebyteoptrest1) val = BYTE_OPT + BYTE_REST + BYTE_TRACED;
    else if (f1 == hardoptrest1) val = BYTE_HARDOPT + BYTE_REST;
    else if (f1 == tracehardoptrest1) val = BYTE_HARDOPT + BYTE_REST + BYTE_TRACED;
    else if (fn == f3_as_0) val = BYTE_CALLAS + 0;
    else if (fn == f3_as_1) val = BYTE_CALLAS + 1;
    else if (fn == f3_as_2) val = BYTE_CALLAS + 2;
    else if (fn == f3_as_3) val = BYTE_CALLAS + 3;
    else if (fn == f0_as_0) val = BYTE_CALLAS + 4;
    else if (f2 == f2_as_0) val = BYTE_CALLAS + 5;
    else if (f2 == f2_as_1) val = BYTE_CALLAS + 6;
    else if (f2 == f2_as_2) val = BYTE_CALLAS + 7;
// The next two intrude on the BYTE_OPT bit-position...
    else if (f1 == f1_as_0) val = BYTE_CALLAS + 8;
    else if (f1 == f1_as_1) val = BYTE_CALLAS + 9;
    else return onevalue(nil);
    return onevalue(fixnum_of_int(val));
}

//
// The job of this function is to put back information as retrieved by
// symbol-argcode. It is used in part of the support for native compilation
// via C code... Note that it does not interact with any JIT stuff since the
// two compilation strategies are complementary and I do not expect that I
// will every use both at once.
//

LispObject Lsymbol_restore_fns(LispObject nil, LispObject name)
{   int r;
    LispObject n, env;
//
// This expects a property that has value <argcode> . <env>
//
    if (!is_symbol(name)) return onevalue(nil);
    n = get(name, bytecoded_symbol);
    if (!consp(n)) return onevalue(nil);
    env = qcdr(n);
    n = qcar(n);
    if (!is_fixnum(n)) return onevalue(nil);
//
// When I first implemented this I thought I might remove the bytecode
// definition from the property list. However I *hope* that soon I will be
// re-instating the native defintion, which would lead to a need to put this
// stuff back. So I think I will just leave it here and avoid the sweat
// of re-instating it during system restart. This may lead to heap images
// being a little larger but I propose not to fuss about that and further
// I hope that structures will be shared and mean that any overhead is
// small.
//
//  Lremprop(nil, name, bytecoded_symbol);
//
    r = int_of_fixnum(n);
    switch (r)
    {   case 1:
            set_fns(name, bytecoded1, too_many_1, wrong_no_1);
            break;
        case 1 + BYTE_TRACED:
            set_fns(name, tracebytecoded1, too_many_1, wrong_no_1);
            break;
        case 1 + BYTE_DOUBLED:
            set_fns(name, double_bytecoded1, too_many_1, wrong_no_1);
            break;
        case 2:
            set_fns(name, too_few_2, bytecoded2, wrong_no_2);
            break;
        case 2 + BYTE_TRACED:
            set_fns(name, too_few_2, tracebytecoded2, wrong_no_2);
            break;
        case 2 + BYTE_DOUBLED:
            set_fns(name, too_few_2, double_bytecoded2, wrong_no_2);
            break;
        case 0:
            set_fns(name, wrong_no_0a, wrong_no_0b, bytecoded0);
            break;
        case 0 + BYTE_TRACED:
            set_fns(name, wrong_no_0a, wrong_no_0b, tracebytecoded0);
            break;
        case 0 + BYTE_DOUBLED:
            set_fns(name, wrong_no_0a, wrong_no_0b, double_bytecoded0);
            break;
        case 3:
            set_fns(name, wrong_no_3a, wrong_no_3b, bytecoded3);
            break;
        case 3 + BYTE_TRACED:
            set_fns(name, wrong_no_3a, wrong_no_3b, tracebytecoded3);
            break;
        case 3 + BYTE_DOUBLED:
            set_fns(name, wrong_no_3a, wrong_no_3b, double_bytecoded3);
            break;
        case 4:
            set_fns(name, wrong_no_na, wrong_no_nb, bytecodedn);
            break;
        case 4 + BYTE_TRACED:
            set_fns(name, wrong_no_na, wrong_no_nb, tracebytecodedn);
            break;
        case 4 + BYTE_DOUBLED:
            set_fns(name, wrong_no_na, wrong_no_nb, double_bytecodedn);
            break;
        case BYTE_OPT:
            set_fns(name, byteopt1, byteopt2, byteoptn);
            break;
        case BYTE_OPT + BYTE_TRACED:
            set_fns(name, tracebyteopt1, tracebyteopt2, tracebyteoptn);
            break;
        case BYTE_HARDOPT:
            set_fns(name, hardopt1, hardopt2, hardoptn);
            break;
        case BYTE_HARDOPT + BYTE_TRACED:
            set_fns(name, tracehardopt1, tracehardopt2, tracehardoptn);
            break;
        case BYTE_OPT + BYTE_REST:
            set_fns(name, byteoptrest1, byteoptrest2, byteoptrestn);
            break;
        case BYTE_OPT + BYTE_REST + BYTE_TRACED:
            set_fns(name, tracebyteoptrest1, tracebyteoptrest2, tracebyteoptrestn);
            break;
        case BYTE_HARDOPT + BYTE_REST:
            set_fns(name, hardoptrest1, hardoptrest2, hardoptrestn);
            break;
        case BYTE_HARDOPT + BYTE_REST + BYTE_TRACED:
            set_fns(name, tracehardoptrest1, tracehardoptrest2, tracehardoptrestn);
            break;
        case BYTE_CALLAS + 0:
            set_fns(name, wrong_no_na, wrong_no_nb,  f3_as_0);
            break;
        case BYTE_CALLAS + 1:
            set_fns(name, wrong_no_na, wrong_no_nb,  f3_as_1);
            break;
        case BYTE_CALLAS + 2:
            set_fns(name, wrong_no_na, wrong_no_nb,  f3_as_2);
            break;
        case BYTE_CALLAS + 3:
            set_fns(name, wrong_no_na, wrong_no_nb,  f3_as_3);
            break;
        case BYTE_CALLAS + 4:
            set_fns(name, wrong_no_na, wrong_no_nb,  f0_as_0);
            break;
        case BYTE_CALLAS + 5:
            set_fns(name, too_few_2,  f2_as_0, wrong_no_2);
            break;
        case BYTE_CALLAS + 6:
            set_fns(name, too_few_2,  f2_as_1, wrong_no_2);
            break;
        case BYTE_CALLAS + 7:
            set_fns(name, too_few_2,  f2_as_2, wrong_no_2);
            break;
        case BYTE_CALLAS + 8:
            set_fns(name, f1_as_0, too_many_1, wrong_no_1);
            break;
        case BYTE_CALLAS + 9:
            set_fns(name, f1_as_1, too_many_1, wrong_no_1);
            break;

        default:
            return onevalue(nil);
    }
    qenv(name) = env;
    return onevalue(lisp_true);
}

LispObject Lsymbol_env(LispObject nil, LispObject a)
//
// Not Common Lisp - read the 'environment' cell associated with a
// symbol.  This cell is deemed empty unless the symbol-function is
// compiled code.  For use mainly for debugging.
//
{   if (!symbolp(a)) return onevalue(nil);
#ifdef HIDE_USELESS_SYMBOL_ENVIRONMENTS
    else if ((qheader(a) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0 ||
             interpreter_entry(a)) return onevalue(nil);
#endif
    return onevalue(qenv(a));
}

LispObject Lsymbol_set_env(LispObject nil, LispObject a, LispObject b)
{   if (!is_symbol(a)) return aerror1("symbol-set-env", a);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    qenv(a) = b;
    return onevalue(b);
}

LispObject Lsymbol_fastgets(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    return onevalue(qfastgets(a));
}

//
// (protect 'name t) arranges that the function indicated (which is
// expected to have been defined in the C kernel) can not be redefined.
// (protect 'name nil) restores the usual state of affairs.
//

LispObject Lsymbol_protect(LispObject nil, LispObject a, LispObject b)
{   Header h;
    if (!is_symbol(a)) return onevalue(nil);
    h = qheader(a);
    if (b == nil) qheader(a) = h & ~(SYM_CODEPTR | SYM_C_DEF);
    else qheader(a) = h | SYM_CODEPTR | SYM_C_DEF;
    h &= (SYM_CODEPTR | SYM_C_DEF);
    return onevalue(Lispify_predicate(h == (SYM_CODEPTR | SYM_C_DEF)));
}

//
// (symbol-make-fastget 'xxx nil)   returns current information, nil if no
//                                  fastget usage set.
// (symbol-make-fastget 'xxx n)     sets it to n (0 <= n < 63)
// (symbol-make-fastget 'xxx -1)    sets the option off
//

LispObject Lsymbol_make_fastget1(LispObject nil, LispObject a)
{
//
// Originally I had thought I would let people change the fastget size here,
// but I think that is dangerous and unnecessary so I will not do so any
// more. Anybody who tries will get a cryptic message!
//
    term_printf("+++ symbol-make-fastget called with only 1 argument\n");
    return onevalue(nil);
}

LispObject Lsymbol_make_fastget(LispObject nil, LispObject a, LispObject n)
{   intptr_t n1, p, q;
    Header h;
    if (!symbolp(a)) return onevalue(nil);
    h = qheader(a);
    p = header_fastget(h);
    if (is_fixnum(n))
    {   n1 = int_of_fixnum(n);
        if (n1 < -1 || n1 >= fastget_size)
            return aerror1("symbol-make-fastget", n);
//
//      trace_printf("+++ Use fastget slot %d for ", n1);
//      loop_print_trace(a);
//      errexit();
//      trace_printf("\n");
//
        if (p != 0) elt(fastget_names, p-1) = SPID_NOPROP;
        q = (n1 + 1) & 0x3f;
        h = (h & ~SYM_FASTGET_MASK) | (q << SYM_FASTGET_SHIFT);
        qheader(a) = h;
        if (q != 0) elt(fastget_names, q-1) = a;
    }
    if (p == 0) return onevalue(nil);
    else return onevalue(fixnum_of_int(p - 1));
}

static LispObject deleqip(LispObject a, LispObject l)
//
// This deletes the item a (tested for using EQ) from the list l,
// assuming that the list is nil-terminated and that the item a
// occurs at most once. It overwrites the list l in the process.
//
{   LispObject nil = C_nil, w, r;
    if (l == nil) return nil;
    if (qcar(l) == a) return qcdr(l);
    r = l;
    while (w = l, (l = qcdr(l)) != nil)
    {   if (qcar(l) == a)
        {   qcdr(w) = qcdr(l);
            return r;
        }
    }
    return r;
}

void lose_C_def(LispObject a)
{
//
// None of the code here can cause garbage collection.
//
#ifdef COMMON
    LispObject nil = C_nil;
    LispObject b = get(a, unset_var, nil), c;
#else
    LispObject b = get(a, unset_var), c;
#endif
    Lremprop(C_nil, a, unset_var);
    qheader(a) &= ~SYM_C_DEF;
#ifdef COMMON
    c = get(b, work_symbol, nil);
#else
    c = get(b, work_symbol);
#endif
    c = deleqip(a, c);
    if (c == C_nil) Lremprop(C_nil, b, work_symbol);
    else putprop(b, work_symbol, c);
}

#ifdef REINSTATE_NATIVE_CODE_EXPERIMENT

//
// (symbol-set-native fn args bpsbase offset env)
// where bpsbase is as handed back by (make-native nnn) and offset is
// the offset in this block to enter at.
// If args has the actual arg count in its bottom byte. Usually the
// rest of it will be zero, and then one function cell is set to point to the
// given entrypoint and the other two are set to point at error handlers.
// If any bits in args beyond that are set then this call only changes the
// directly specified function cell, and the others are left in whatever state
// they were. If several of the fuction cells are to be filled in (eg to cope
// with &optional or &rest arguments) then a simple call with args<256 must
// be made first, followed by the calls (args>=256) that fill in the other
// two cells.
// The first time that symbol-set-native is called on a function that
// function MUST have a byte coded definition, and this definition is
// picked up and stored away, so that if (preserve) is called the bytecoded
// definition will be available for use on systems with different
// architectures. To make things tolerably consistent with that any operation
// that installs a new bytecoded (or for that matter other) definition
// will clear away any native-compiled versions of the function.
//
// The native code that is installed will be expected to have relocation
// records starting at the start of bpsbase, and these will be activated,
// filling in references from the bps to other executable parts of Lisp.
// Passing bad arguments to this function provide a quick and easy way to
// cayse UTTER havoc. Therefore I disable its use in server applications.
//

LispObject Lsymbol_set_native(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject fn, args, bpsbase, offset, env, w1, w2, w3;
    int32_t pagenumber, t_p, arginfo;
    intptr_t address, page, bps;
    argcheck(nargs, 5, "symbol-set-native");
    va_start(a, nargs);
    fn = va_arg(a, LispObject);
    args = va_arg(a, LispObject);
    bpsbase = va_arg(a, LispObject);
    offset = va_arg(a, LispObject);
    env = va_arg(a, LispObject);
    va_end(a);
    if (!is_symbol(fn) ||
        (qheader(fn) & (SYM_SPECIAL_FORM | SYM_CODEPTR)) != 0)
        return aerror1("symbol-set-native", fn);
    if (!is_fixnum(args)) return aerror1("symbol-set-native", args);
    if (!consp(bpsbase) ||
        !is_fixnum(qcar(bpsbase)) ||
        !is_fixnum(qcdr(bpsbase)))
        return aerror1("symbol-set-native", bpsbase);
    if (!is_fixnum(offset)) return aerror1("symbol-set-native", offset);
    nargs = int_of_fixnum(args);
    pagenumber = int_of_fixnum(qcar(bpsbase));
    if (pagenumber<0 || pagenumber>=native_pages_count)
        return aerror1("symbol-set-native", bpsbase);
    bps = int_of_fixnum(qcdr(bpsbase));
    address = bps+int_of_fixnum(offset);
    if (address<8 || address>=(intptr_t)CSL_PAGE_SIZE)
        return aerror1("symbol-set-native", offset);
    page = (intptr_t)native_pages[pagenumber];
    page = doubleword_align_up(page);
    bps = page + bps;
    relocate_native_function((unsigned char *)bps);
//
// Here I need to push the info I have just collected onto
// the native_code list since otherwise things will not be re-loaded in
// from a checkpoint image. Also if the function is at present byte-coded
// I need to record that info about it in native_code.
//
    w1 = native_code;
    w2 = nil;
    while (w1!=nil)
    {   w2 = qcar(w1);
        if (qcar(w2) == fn) break;
        w1 = qcdr(w1);
    }
    if (w1 == nil)
    {
//
// Here the function has not been seen as native code ever before, so it has
// not been entered into the list. Do something about that...
//
        push2(env, fn);
        args = Lsymbol_argcount(nil, fn);
        errexitn(2);
        if (args == nil)
            return aerror1("No bytecode definition found for", fn);
//
// Now I have to reverse the information that symbol_argcount gave me
// to get the single numeric code as wanted by symbol_set_definition.
// Oh what a mess.
//
        if (is_fixnum(args)) arginfo = int_of_fixnum(args);
        else
        {   arginfo = int_of_fixnum(qcar(args));
            args = qcdr(args);
            arginfo |= ((int_of_fixnum(qcar(args)) - arginfo) << 8);
            args = qcdr(args);
            arginfo |= int_of_fixnum(qcar(args)) << 16;
        }
        fn = stack[0];
        w2 = list2(fn, fixnum_of_int(arginfo));
        errexitn(2);
        w2 = cons(w2, native_code);
        errexitn(2);
        native_code = w2;
        w2 = qcar(w2);
        pop2(fn, env);
    }
    w2 = qcdr(w2);  // {nargs,(type . offset . env),...}
//
// If I was defining this function in the simple way I should clear any
// previous version (for this machine architecture) from the record.
// Just at present this does not release the memory, but at some stage
// in the future I may arrange to compact away old code when I do a
// preserve operation (say).
//
    if (nargs <= 0xff)
    {   w1 = w3 = w2;
        for (w1=qcdr(w2); w1!=nil; w1=qcdr(w1))
        {   w3 = qcar(w1);
            if (qcar(w3) == fixnum_of_int(native_code_tag)) break;
            w3 = w1;
        }
        if (w1 != nil) qcdr(w3) = qcdr(w1);
    }
//
// w2 is still the entry for this function in the native code list. It
// needs to have an entry of type 0 (ie for bytecoded) and so the next
// thing to do is to check that such an entry exists and if not to create
// it.
//
    w1 = w2;
    while ((w1 = qcdr(w1)) != nil)
    {   w3 = qcar(w1);
        if (qcar(w3) == fixnum_of_int(0)) break;
        w1 = qcdr(w1);
    }
    if (w1 == nil)
    {
//
// This is where there was no bytecode entry on the native code list
// for this function, so I had better create one for it. Note that only
// one such entry will ever be stored so it does not matter much where on
// the list it goes. I suspect that the list ought always to be empty
// in this case anyway.
//
        push3(fn, env, w2);
        w1 = list2star(fixnum_of_int(0), fixnum_of_int(0), qenv(fn));
        errexitn(3);
        w2 = stack[0];
        w1 = cons(w1, qcdr(w2));
        errexitn(3);
        pop3(w2, env, fn);
        qcdr(w2) = w1;
    }
//
// Now the list of native code associated with this function certainly holds
// a byte-coded definition (and for sanity that had better be consistent
// with the native code I am installing now, but that is not something
// that can be checked at this level). Put in an entry referring to the
// current gubbins.
//
    push3(w2, fn, env);
//
// now I pack the code type, arg category and offset into the
// single fixnum that that information has to end up in.
//
    t_p = (native_code_tag << 20);
    if ((nargs & 0xffffff00) != 0)
    {   switch (nargs & 0xff)
        {   case 1: t_p |= (1<<18); break;
            case 2: t_p |= (2<<18); break;
            default:t_p |= (3<<18); break;
        }
    }
    t_p |= (pagenumber & 0x3ffff);
    w1 = list2star(fixnum_of_int(t_p), fixnum_of_int(address), env);
    errexitn(3);
    w1 = ncons(w1);
    pop3(env, fn, w2);
    errexit();
    while ((w3 = qcdr(w2)) != nil) w2 = w3;  // Tag onto the END
    qcdr(w2) = w1;
    qheader(fn) &= ~SYM_TRACED;
    address = page + address;
//
// The code here must do just about the equivalent to that in restart.c
//
    switch (nargs & 0xff)
    {   case 0:  ifnn(fn) = address;
            if (nargs<=0xff)
                ifn1(fn) = (intptr_t)wrong_no_0a, ifn2(fn) = (intptr_t)wrong_no_0b;
            break;
        case 1:  ifn1(fn) = address;
            if (nargs<=0xff)
                ifn2(fn) = (intptr_t)too_many_1, ifnn(fn) = (intptr_t)wrong_no_1;
            break;
        case 2:  ifn2(fn) = address;
            if (nargs<=0xff)
                ifn1(fn) = (intptr_t)too_few_2, ifnn(fn) = (intptr_t)wrong_no_2;
            break;
        case 3:  ifnn(fn) = address;
            if (nargs<=0xff)
                ifn1(fn) = (intptr_t)wrong_no_3a, ifn2(fn) = (intptr_t)wrong_no_3b;
            break;
        default: ifnn(fn) = address;
            if (nargs<=0xff)
                ifn1(fn) = (intptr_t)wrong_no_na, ifn2(fn) = (intptr_t)wrong_no_nb;
            break;
    }
    qenv(fn) = env;
    return onevalue(fn);
}

#endif // REINSTATE_NATIVE_CODE_EXPERIMENT

static bool restore_fn_cell(LispObject a, char *name,
                               size_t len, setup_type const s[])
{   size_t i;
    for (i=0; s[i].name != NULL; i++)
    {   if (strlen(s[i].name) == (size_t)len &&
            memcmp(name, s[i].name, len) == 0) break;
    }
    if (s[i].name == NULL) return false;
    set_fns(a, s[i].one, s[i].two, s[i].n);
    return true;
}

//
// This gets called by the compiler if it is asked to compile something
// into a fasl file where that thing has a definition as C code. In such a
// case what it puts into the fasl file is a call to this to instate the
// version coded in C. If a LOT of stuff has been turning into C this could
// become a bottleneck - and in such a case I should make a table of C
// entrypoints as a hash table or something sorted for use with binary
// search!
//

static LispObject Lrestore_c_code(LispObject nil, LispObject a)
{   char *name;
    size_t len;
    size_t i;
    LispObject pn;
    if (!symbolp(a)) return aerror1("restore-c-code", a);
    push(a);
    pn = get_pname(a);
    pop(a);
    errexit();
    name = (char *)&celt(pn, 0);
    len = length_of_byteheader(vechdr(pn)) - CELL;
//
// This is a potential time-sink in that it does a linear scan of all the
// definitions in the tables that are in u01.c to u60.c.
//
    for (i=0; setup_tables[i]!=NULL; i++)
    {   if (restore_fn_cell(a, name, len, setup_tables[i]))
        {   LispObject env;
            push(a);
#ifdef COMMON
            env = get(a, funarg, nil);
#else
            env = get(a, funarg);
#endif
            pop(a);
            errexit();
            qenv(a) = env;
            return onevalue(a);
        }
    }
    return onevalue(nil);
}

LispObject Lsymbol_set_definition(LispObject nil,
                                  LispObject a, LispObject b)
//
// The odd case here is where the second argument represents a freshly
// created bit of compiled code. In which case the structure is
//   (nargs . codevec . envvec)
// where nargs is an integer indicating the number of arguments, codevec
// is a vector of bytecodes, and envvec is something to go in the
// environment cell of the symbol.
// Here the low 8 bits of nargs indicate the number of required arguments.
// The next 8 bits give the number of optional arguments, and the next
// two bits are flags. Of these, the first is set if any of the optional
// arguments has an initform or supplied-p associate, and the other
// indicates that a "&rest" argument is required.
// Bits beyond that (if non-zero) indicate that the function definition
// is of the form (defun f1 (a b c) (f2 a b)) and the number coded is the
// length of the function body.
// Standard Lisp does not need &optional or &rest arguments, but it turned
// out to be pretty easy to make the bytecode compiler support them.
//
{   if (!is_symbol(a) ||
//
// Something flagged with the CODEPTR bit is a gensym manufactured to
// stand for a compiled-code object. It should NOT be reset!
//
        (qheader(a) & (SYM_SPECIAL_FORM | SYM_CODEPTR)) != 0)
    {   if (qheader(a) & SYM_C_DEF) return onevalue(nil);
        return aerror1("symbol-set-definition", a);
    }
    qheader(a) &= ~SYM_TRACED;
    set_fns(a, undefined1, undefined2, undefinedn); // Tidy up first
    qenv(a) = a;
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    if (b == nil) return onevalue(b); // set defn to nil to undefine
    else if (symbolp(b))
    {
//
// One could imagine a view that the second arg to symbol-set-definition
// had to be a codepointer object. I will be kind (?) and permit the NAME
// of a function too.  However for the second arg to be a macro or a
// special form would still be a calamity.
//      if ((qheader(b) & SYM_CODEPTR) == 0)
//          return aerror1("symbol-set-definition", b);
//
        if ((qheader(b) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0)
            return aerror1("symbol-set-definition", b);
        qheader(a) = qheader(a) & ~SYM_MACRO;
        {   set_fns(a, qfn1(b), qfn2(b), qfnn(b));
            qenv(a) = qenv(b);
//
// In order that checkpoint files can be made there is some very
// ugly fooling around here for functions that are defined in the C coded
// kernel.  Sorry.
//
            if ((qheader(b) & SYM_C_DEF) != 0)
            {
#ifdef COMMON
                LispObject c = get(b, unset_var, nil);
#else
                LispObject c = get(b, unset_var);
#endif
                if (c == nil) c = b;
                push2(c, a);
                putprop(a, unset_var, c);
                errexitn(2);
                pop(a);
#ifdef COMMON
                a = cons(a, get(stack[0], work_symbol, nil));
#else
                a = cons(a, get(stack[0], work_symbol));
#endif
                errexitn(1);
                putprop(stack[0], work_symbol, a);
                pop(b);
                errexit();
            }
        }
    }
    else if (!consp(b)) return aerror1("symbol-set-definition", b);
    else if (is_fixnum(qcar(b)))
    {   int32_t nargs = (int32_t)int_of_fixnum(qcar(b)),
                nopts, flagbits, ntail;
        nopts = nargs >> 8;
        flagbits = nopts >> 8;
        ntail = flagbits >> 2;
        nargs &= 0xff;
        nopts &= 0xff;
        flagbits &= 3;
        if (ntail != 0)
        {   switch (100*nargs + ntail-1)
            {   case 300: set_fns(a, wrong_no_na, wrong_no_nb, f3_as_0); break;
                case 301: set_fns(a, wrong_no_na, wrong_no_nb, f3_as_1); break;
                case 302: set_fns(a, wrong_no_na, wrong_no_nb, f3_as_2); break;
                case 303: set_fns(a, wrong_no_na, wrong_no_nb, f3_as_3); break;
                case 200: set_fns(a, too_few_2, f2_as_0, wrong_no_2); break;
                case 201: set_fns(a, too_few_2, f2_as_1, wrong_no_2); break;
                case 202: set_fns(a, too_few_2, f2_as_2, wrong_no_2); break;
                case 100: set_fns(a, f1_as_0, too_many_1, wrong_no_1); break;
                case 101: set_fns(a, f1_as_1, too_many_1, wrong_no_1); break;
                case 000: set_fns(a, wrong_no_na, wrong_no_nb, f0_as_0); break;
            }
            b = qcdr(b);
        }
        else if (flagbits != 0 || nopts != 0)
        {   if ((qheader(a) & SYM_TRACED) == 0) switch(flagbits)
            {       default:
                    case 0:  // easy case optional arguments
                        set_fns(a, byteopt1, byteopt2, byteoptn); break;
                    case 1:  // optional args, but non-nil default, or supplied-p extra
                        set_fns(a, hardopt1, hardopt2, hardoptn); break;
                    case 2:  // easy opt args, but also a &rest arg
                        set_fns(a, byteoptrest1, byteoptrest2, byteoptrestn); break;
                    case 3:  // complicated &options and &rest
                        set_fns(a, hardoptrest1, hardoptrest2, hardoptrestn); break;
                }
            else switch (flagbits)
            {       default:
                    case 0:  // easy case optional arguments
                        set_fns(a, tracebyteopt1, tracebyteopt2, tracebyteoptn); break;
                    case 1:  // optional args, but non-nil default, or supplied-p extra
                        set_fns(a, tracehardopt1, tracehardopt2, tracehardoptn); break;
                    case 2:  // easy opt args, but also a &rest arg
                        set_fns(a, tracebyteoptrest1, tracebyteoptrest2, tracebyteoptrestn); break;
                    case 3:  // complicated &options and &rest
                        set_fns(a, tracehardoptrest1, tracehardoptrest2, tracehardoptrestn); break;
                }
        }
        else
        {   if (nargs > 4) nargs = 4;
            if ((qheader(a) & SYM_TRACED) != 0) nargs += 5;
            qheader(a) = qheader(a) & ~SYM_MACRO;
            switch (nargs)
            {   case 0:   set_fns(a, wrong_no_0a, wrong_no_0b, bytecoded0);
                    break;
                case 1:   set_fns(a, bytecoded1,  too_many_1,  wrong_no_1);
                    break;
                case 2:   set_fns(a, too_few_2,   bytecoded2,  wrong_no_2);
                    break;
                case 3:   set_fns(a, wrong_no_3a, wrong_no_3b, bytecoded3);
                    break;
                default:
                case 4:   set_fns(a, wrong_no_na, wrong_no_nb, bytecodedn);
                    break;

                case 5+0: set_fns(a, wrong_no_0a, wrong_no_0b, tracebytecoded0);
                    break;
                case 5+1: set_fns(a, tracebytecoded1, too_many_1,  wrong_no_1);
                    break;
                case 5+2: set_fns(a, too_few_2,   tracebytecoded2, wrong_no_2);
                    break;
                case 5+3: set_fns(a, wrong_no_3a, wrong_no_3b, tracebytecoded3);
                    break;
                case 5+4: set_fns(a, wrong_no_na, wrong_no_nb, tracebytecodedn);
                    break;
            }
        }
        qenv(a) = qcdr(b);
    }
    else if (qcar(b) == lambda)
    {   LispObject bvl = qcar(qcdr(b));
        int nargs = 0;
        while (consp(bvl)) nargs++, bvl = qcdr(bvl);
        qheader(a) = qheader(a) & ~SYM_MACRO;
        if ((qheader(a) & SYM_TRACED) != 0)
            set_fns(a, traceinterpreted1, traceinterpreted2, traceinterpretedn);
        else set_fns(a, interpreted1, interpreted2, interpretedn);
        qenv(a) = qcdr(b);
        if (qvalue(comp_symbol) != nil &&
            qfn1(compiler_symbol) != undefined1)
        {   push(a);
            a = ncons(a);
            errexitn(1);
            (qfn1(compiler_symbol))(qenv(compiler_symbol), a);
            pop(a);
            errexit();
        }
    }
    else if (qcar(b) == funarg)
    {   LispObject bvl = qcar(qcdr(b));
        int nargs = 0;
        while (consp(bvl)) nargs++, bvl = qcdr(bvl);
        qheader(a) = qheader(a) & ~SYM_MACRO;
        if ((qheader(a) & SYM_TRACED) != 0)
            set_fns(a, tracefunarged1, tracefunarged2, tracefunargedn);
        else set_fns(a, funarged1, funarged2, funargedn);
        qenv(a) = qcdr(b);
    }
    else return aerror1("symbol-set-definition", b);
    return onevalue(b);
}

LispObject Lgetd(LispObject nil, LispObject a)
{   Header h;
    LispObject type;
    if (a == nil) return onevalue(nil);
    else if (!is_symbol(a)) return onevalue(nil);
    h = qheader(a);
    if ((h & SYM_SPECIAL_FORM) != 0) type = fexpr_symbol;
    else if ((h & SYM_MACRO) != 0)
    {   a = cons(lambda, qenv(a));
        errexit();
        type = macro_symbol;
    }
    else
    {   a = Lsymbol_function(nil, a);
        errexit();
        if (a == nil) return onevalue(nil);
        type = expr_symbol;
    }
    a = cons(type, a);
    errexit();
    return onevalue(a);
}

LispObject Lremd(LispObject nil, LispObject a)
{   LispObject res;
    if (!is_symbol(a) ||
        (qheader(a) & SYM_SPECIAL_FORM) != 0)
        return aerror1("remd", a);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    res = Lgetd(nil, a);
    errexit();
    if (res == nil) return onevalue(nil); // no definition to remove
//
// I treat an explicit use of remd as a redefinition, and ensure that
// restarting a preserved image will not put the definition back.
//
    qheader(a) = qheader(a) & ~SYM_MACRO;
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    set_fns(a, undefined1, undefined2, undefinedn);
    qenv(a) = a;
    return onevalue(res);
}

//
// For set-autoload the first argument must be a symbol that will name
// a function, the second arg is either an atom or a list of atoms, each
// of which specified a module to be loaded if the names function is
// called.  Loading the modules is expected to instate a definition for the
// function involved.  This function is arranged so it does NOT do anything
// if the function being set for autoloading is already defined. This is
// on the supposition that the existing definition is in fact the desired
// one, say because the relevant module happens to have been loaded already.
// An explicit use of remd first can be used to ensure that no previous
// definition is present and thus that a real autoload stub will be instated,
// if that is what you really want.
//

LispObject Lset_autoload(LispObject nil, LispObject a, LispObject b)
{   LispObject res;
    if (!is_symbol(a) ||
        (qheader(a) & SYM_SPECIAL_FORM) != 0)
        return aerror1("set-autoload", a);
    if (!(qfn1(a) == undefined1 && qfn2(a) == undefined2 &&
          qfnn(a) == undefinedn)) return onevalue(nil);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    push2(a, b);
    if (consp(b)) res = cons(a, b);
    else res = list2(a, b);
    pop2(b, a);
    errexit();
//
// I treat an explicit use of set-autoload as a redefinition, and ensure that
// restarting a preserved image will not put the definition back.  Note that
// I will not allow autoloadable macros...
//
    qheader(a) = qheader(a) & ~SYM_MACRO;
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    set_fns(a, autoload1, autoload2, autoloadn);
    qenv(a) = res;
    return onevalue(res);
}

#define pack_funtable(a, n) ((((int32_t)(a)) << 16) | (n))
#define funtable_nargs(u)   ((u) >> 16)
#define funtable_index(u)   ((u) & 0xffffU)

static one_args *displaced1 = NULL;
static two_args *displaced2;
static n_args   *displacedn;
static uint32_t table_entry;

static LispObject traced1_function(LispObject env, LispObject a)
{   LispObject name, nil = C_nil;
    LispObject r = nil;
//
// Worry about errors & garbage collection in following calls to print fns
// This MUST be fixed sometime fairly soon... but then it could only bite
// people using the trace facility, and their code is already dead!
//
    freshline_trace();
    loop_print_trace(tracedfn);
    push(tracedfn);
    trace_printf(" called (1 arg)\narg1: ");
    loop_print_trace(a);
    trace_printf("\n");
    r = (*displaced1)(env, a);
    pop(name);
    errexit();
    push(r);
    freshline_trace();
    loop_print_trace(name);
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return onevalue(r);
}

static LispObject traced2_function(LispObject env,
                                   LispObject a, LispObject b)
{   LispObject name, nil = C_nil;
    LispObject r = nil;
    freshline_trace();
    loop_print_trace(tracedfn);
    push(tracedfn);
    trace_printf(" called (2 args)\narg1:");
    loop_print_trace(a);
    trace_printf("\narg2: ");
    loop_print_trace(b);
    trace_printf("\n");
    r = (*displaced2)(env, a, b);
    pop(name);
    errexit();
    push(r);
    freshline_trace();
    loop_print_trace(name);
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return onevalue(r);
}

static LispObject tracedn_function(LispObject env, int nargs, ...)
{   LispObject name, nil = C_nil;
    LispObject r = nil;
    int i;
    va_list a;
    push(tracedfn);
    va_start(a, nargs);
    push_args(a, nargs);
    freshline_trace();
    loop_print_trace(tracedfn);
    trace_printf(" called (%d args)\n", nargs);
    for (i=1; i<=nargs; i++)
    {   trace_printf("arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    if (nargs <= 15) switch (nargs)
    {       default:
//
// Calls with 1 or 2 args can never arise, since those cases have been
// split off for separate treatment.
//
                popv(nargs+1);
                return aerror("system error in trace mechanism");
            case 0:
                r = (*displacedn)(env, 0);
                break;
            case 3:
                r = (*displacedn)(env, 3,    stack[-2], stack[-1], stack[0]);
                break;
            case 4:
                r = (*displacedn)(env, 4,    stack[-3],  stack[-2],  stack[-1],
                                  stack[0]);
                break;
            case 5:
                r = (*displacedn)(env, 5,    stack[-4],  stack[-3],  stack[-2],
                                  stack[-1],  stack[0]);
                break;
            case 6:
                r = (*displacedn)(env, 6,    stack[-5],  stack[-4],  stack[-3],
                                  stack[-2],  stack[-1],  stack[0]);
                break;
            case 7:
                r = (*displacedn)(env, 7,    stack[-6],  stack[-5],  stack[-4],
                                  stack[-3],  stack[-2],  stack[-1],  stack[0]);
                break;
            case 8:
                r = (*displacedn)(env, 8,    stack[-7],  stack[-6],  stack[-5],
                                  stack[-4],  stack[-3],  stack[-2],  stack[-1],
                                  stack[0]);
                break;
            case 9:
                r = (*displacedn)(env, 9,    stack[-8],  stack[-7],  stack[-6],
                                  stack[-5],  stack[-4],  stack[-3],  stack[-2],
                                  stack[-1],  stack[0]);
                break;
            case 10:
                r = (*displacedn)(env, 10,   stack[-9], stack[-8],  stack[-7],
                                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                                  stack[-2],  stack[-1],  stack[0]);
                break;
            case 11:
                r = (*displacedn)(env, 11,   stack[-10], stack[-9],
                                  stack[-8],  stack[-7],  stack[-6],  stack[-5],
                                  stack[-4],  stack[-3],  stack[-2],  stack[-1],
                                  stack[0]);
                break;
            case 12:
                r = (*displacedn)(env, 12,   stack[-11], stack[-10],
                                  stack[-9], stack[-8],  stack[-7],  stack[-6],
                                  stack[-5],  stack[-4],  stack[-3],  stack[-2],
                                  stack[-1],  stack[0]);
                break;
            case 13:
                r = (*displacedn)(env, 13,   stack[-12], stack[-11],
                                  stack[-10], stack[-9], stack[-8],  stack[-7],
                                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                                  stack[-2],  stack[-1],  stack[0]);
                break;
            case 14:
                r = (*displacedn)(env, 14,   stack[-13], stack[-12],
                                  stack[-11], stack[-10], stack[-9], stack[-8],
                                  stack[-7],  stack[-6],  stack[-5],  stack[-4],
                                  stack[-3],  stack[-2],  stack[-1],  stack[0]);
                break;
            case 15:
                r = (*displacedn)(env, 15,   stack[-14], stack[-13],
                                  stack[-12], stack[-11], stack[-10], stack[-9],
                                  stack[-8],  stack[-7],  stack[-6],  stack[-5],
                                  stack[-4],  stack[-3],  stack[-2],  stack[-1],
                                  stack[0]);
                break;
        }
    else
    {   trace_printf("Too many arguments to trace a function\n");
//
// Because the above is a horrid mess I will only support traced
// calls with at most 15 args (more than I expect most people to
// try). And this only applies to thigs that are NOT bytecoded -
// I can trace bytecoded things with more args I believe, so users are not
// utterly lost I hope.
//
        return aerror("traced function with > 15 args: not supported");
    }
    popv(nargs);
    pop(name);
    errexit();
    push(r);
    freshline_trace();
    loop_print_trace(name);
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return onevalue(r);
}

#define NOT_FOUND 100

static uint32_t find_built_in_function(one_args *f1,
                                       two_args *f2,
                                       n_args *fn)
//
// This take the entrypoint of a function and tries to identify it
// by scanning the tables used by the bytecode interpreter.  If the
// function is found a record is returned indicating how many args
// it takes, and what its index is in the relevant table.  The code
// <NOT_FOUND,NOT_FOUND> is returned to indicate failure if the function
// is not found.
//
{   int32_t index;
    for (index=0; no_arg_functions[index]!=NULL; index++)
        if (fn == no_arg_functions[index]) return pack_funtable(0, index);
    for (index=0; one_arg_functions[index]!=NULL; index++)
        if (f1 == one_arg_functions[index]) return pack_funtable(1, index);
    for (index=0; two_arg_functions[index]!=NULL; index++)
        if (f2 == two_arg_functions[index]) return pack_funtable(2, index);
    for (index=0; three_arg_functions[index]!=NULL; index++)
        if (fn == three_arg_functions[index]) return pack_funtable(3, index);
    return pack_funtable(NOT_FOUND, NOT_FOUND);
}

LispObject Ltrace_all(LispObject, LispObject a)
{
#ifdef DEBUG
    LispObject nil = C_nil;
    if (a == nil) trace_all = 0;
    else trace_all = 1;
    return onevalue(nil);
#else
    (void)a;
    return aerror("trace-all only supported in DEBUG version");
#endif
}

LispObject Ltrace(LispObject nil, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   LispObject s = qcar(w);
        w = qcdr(w);
        if (symbolp(s))
        {   one_args *f1 = qfn1(s);
            two_args *f2 = qfn2(s);
            n_args *fn = qfnn(s);
            int fixenv = 0, done = 0;
            if (f1 == undefined1)
            {   freshline_debug();
                debug_printf("+++ ");
                loop_print_debug(s);
                debug_printf(" not yet defined\n");
                continue;
            }
            qheader(s) |= SYM_TRACED;
            if (f1 == interpreted1)
            {   set_fns(s, traceinterpreted1, traceinterpreted2, traceinterpretedn);
                fixenv = done = 1;
            }
            if (f1 == funarged1)
            {   set_fns(s, tracefunarged1, tracefunarged2, tracefunargedn);
                fixenv = done = 1;
            }
            if (fn == bytecoded0) ifnn(s) = (intptr_t)tracebytecoded0, done = 1;
            if (f1 == bytecoded1) ifn1(s) = (intptr_t)tracebytecoded1, done = 1;
            if (f2 == bytecoded2) ifn2(s) = (intptr_t)tracebytecoded2, done = 1;
            if (fn == bytecoded3) ifnn(s) = (intptr_t)tracebytecoded3, done = 1;
            if (fn == bytecodedn) ifnn(s) = (intptr_t)tracebytecodedn, done = 1;
            if (f1 == byteopt1) ifn1(s) = (intptr_t)tracebyteopt1, done = 1;
            if (f2 == byteopt2) ifn2(s) = (intptr_t)tracebyteopt2, done = 1;
            if (fn == byteoptn) ifnn(s) = (intptr_t)tracebyteoptn, done = 1;
            if (f1 == hardopt1) ifn1(s) = (intptr_t)tracehardopt1, done = 1;
            if (f2 == hardopt2) ifn2(s) = (intptr_t)tracehardopt2, done = 1;
            if (fn == hardoptn) ifnn(s) = (intptr_t)tracehardoptn, done = 1;
            if (f1 == byteoptrest1) ifn1(s) = (intptr_t)tracebyteoptrest1, done = 1;
            if (f2 == byteoptrest2) ifn2(s) = (intptr_t)tracebyteoptrest2, done = 1;
            if (fn == byteoptrestn) ifnn(s) = (intptr_t)tracebyteoptrestn, done = 1;
            if (f1 == hardoptrest1) ifn1(s) = (intptr_t)tracehardoptrest1, done = 1;
            if (f2 == hardoptrest2) ifn2(s) = (intptr_t)tracehardoptrest2, done = 1;
            if (fn == hardoptrestn) ifnn(s) = (intptr_t)tracehardoptrestn, done = 1;
            if (fixenv)
            {   push2(a, s);
                a = cons(s, qenv(s));
                errexitn(2);
                pop(s);
                qenv(s) = a;
                pop(a);
            }
            if (done) continue;
//
// I permit the tracing of just one function from the kernel, and achieve
// this by installing a wrapper function in place of the real definition.
// Indeed this is just like Lisp-level embedding, except that I can get at the
// entrypoint table used by the bytecode interpreter and so trap calls made
// via there, and I can use that table to tell me how many arguments the
// traced function needed.
//
            if (displaced1 == NULL)
            {   int nargs = funtable_nargs(table_entry);
//
// Remember what function was being traced, so that it can eventually be
// invoked, and its name printed.
//
                displaced1 = f1;
                displaced2 = f2;
                displacedn = fn;
                tracedfn = s;
//
// This makes calls via the regular interpreter see the traced version...
//
                set_fns(s, traced1_function, traced2_function,
                        tracedn_function);
                table_entry = find_built_in_function(f1, f2, fn);
                nargs = funtable_nargs(table_entry);
                table_entry = funtable_index(table_entry);
                if (nargs != NOT_FOUND)
                {
//
// .. and now I make calls via short-form bytecodes do likewise.
//
                    switch (nargs)
                {       default:
                        case 0: no_arg_functions[funtable_index(table_entry)] =
                                tracedn_function;
                            break;
                        case 1: one_arg_functions[funtable_index(table_entry)] =
                                traced1_function;
                            break;
                        case 2: two_arg_functions[funtable_index(table_entry)] =
                                traced2_function;
                            break;
                        case 3: three_arg_functions[funtable_index(table_entry)] =
                                tracedn_function;
                            break;
                    }
                }
            }
            continue;
        }
    }
    return onevalue(a);
}

//
// The following will undo traceset as well as trace.
//

LispObject Luntrace(LispObject nil, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   LispObject s = qcar(w);
        w = qcdr(w);
        if (symbolp(s))
        {   one_args *f1 = qfn1(s);
            two_args *f2 = qfn2(s);
            n_args *fn = qfnn(s);
            if (f1 == traceinterpreted1 || f1 == tracesetinterpreted1)
            {   set_fns(s, interpreted1, interpreted2, interpretedn);
                qenv(s) = qcdr(qenv(s));
            }
            else if (f1 == tracefunarged1 || f1 == tracesetfunarged1)
            {   set_fns(s, funarged1, funarged2, funargedn);
                qenv(s) = qcdr(qenv(s));
            }
            if (f1 == tracebytecoded1  || f1 == tracesetbytecoded1  ) ifn1(s) = (intptr_t)bytecoded1;
            if (f2 == tracebytecoded2  || f2 == tracesetbytecoded2  ) ifn2(s) = (intptr_t)bytecoded2;
            if (fn == tracebytecoded0  || fn == tracesetbytecoded0  ) ifnn(s) = (intptr_t)bytecoded0;
            if (fn == tracebytecoded3  || fn == tracesetbytecoded3  ) ifnn(s) = (intptr_t)bytecoded3;
            if (fn == tracebytecodedn  || fn == tracesetbytecodedn  ) ifnn(s) = (intptr_t)bytecodedn;
            if (f1 == tracebyteopt1    || f1 == tracesetbyteopt1    ) ifn1(s) = (intptr_t)byteopt1;
            if (f2 == tracebyteopt2    || f2 == tracesetbyteopt2    ) ifn2(s) = (intptr_t)byteopt2;
            if (fn == tracebyteoptn    || fn == tracesetbyteoptn    ) ifnn(s) = (intptr_t)byteoptn;
            if (f1 == tracebyteoptrest1|| f1 == tracesetbyteoptrest1) ifn1(s) = (intptr_t)byteoptrest1;
            if (f2 == tracebyteoptrest2|| f2 == tracesetbyteoptrest2) ifn2(s) = (intptr_t)byteoptrest2;
            if (fn == tracebyteoptrestn|| fn == tracesetbyteoptrestn) ifnn(s) = (intptr_t)byteoptrestn;
            if (f1 == tracehardopt1    || f1 == tracesethardopt1    ) ifn1(s) = (intptr_t)hardopt1;
            if (f2 == tracehardopt2    || f2 == tracesethardopt2    ) ifn2(s) = (intptr_t)hardopt2;
            if (fn == tracehardoptn    || fn == tracesethardoptn    ) ifnn(s) = (intptr_t)hardoptn;
            if (f1 == tracehardoptrest1|| f1 == tracesethardoptrest1) ifn1(s) = (intptr_t)hardoptrest1;
            if (f2 == tracehardoptrest2|| f2 == tracesethardoptrest2) ifn2(s) = (intptr_t)hardoptrest2;
            if (fn == tracehardoptrestn|| fn == tracesethardoptrestn) ifnn(s) = (intptr_t)hardoptrestn;
            if (f1 == traced1_function)
            {   int nargs = funtable_nargs(table_entry);
                set_fns(s, displaced1, displaced2, displacedn);
                if (nargs != NOT_FOUND)
                    switch (nargs)
                {       default:
                        case 0: no_arg_functions[funtable_index(table_entry)] =
                                displacedn;
                            break;
                        case 1: one_arg_functions[funtable_index(table_entry)] =
                                displaced1;
                            break;
                        case 2: two_arg_functions[funtable_index(table_entry)] =
                                displaced2;
                            break;
                        case 3: three_arg_functions[funtable_index(table_entry)] =
                                displacedn;
                            break;
                    }
                displaced1 = NULL;
                displaced2 = NULL;
                displacedn = NULL;
            }
            qheader(s) &= ~SYM_TRACED;
        }
    }
    return onevalue(a);
}

LispObject Ltraceset(LispObject nil, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   LispObject s = qcar(w);
        w = qcdr(w);
        if (symbolp(s))
        {   one_args *f1 = qfn1(s);
            two_args *f2 = qfn2(s);
            n_args *fn = qfnn(s);
            int fixenv = 0, done = 0;
            if (f1 == undefined1)
            {   freshline_debug();
                debug_printf("+++ ");
                loop_print_debug(s);
                debug_printf(" not yet defined\n");
                continue;
            }
            qheader(s) |= SYM_TRACED;
            if (f1 == interpreted1)
            {   set_fns(s, tracesetinterpreted1, tracesetinterpreted2, tracesetinterpretedn);
                fixenv = done = 1;
            }
            if (f1 == funarged1)
            {   set_fns(s, tracesetfunarged1, tracesetfunarged2, tracesetfunargedn);
                fixenv = done = 1;
            }
            if (fn == bytecoded0) ifnn(s) = (intptr_t)tracesetbytecoded0, done = 1;
            if (f1 == bytecoded1) ifn1(s) = (intptr_t)tracesetbytecoded1, done = 1;
            if (f2 == bytecoded2) ifn2(s) = (intptr_t)tracesetbytecoded2, done = 1;
            if (fn == bytecoded3) ifnn(s) = (intptr_t)tracesetbytecoded3, done = 1;
            if (fn == bytecodedn) ifnn(s) = (intptr_t)tracesetbytecodedn, done = 1;
            if (f1 == byteopt1) ifn1(s) = (intptr_t)tracesetbyteopt1, done = 1;
            if (f2 == byteopt2) ifn2(s) = (intptr_t)tracesetbyteopt2, done = 1;
            if (fn == byteoptn) ifnn(s) = (intptr_t)tracesetbyteoptn, done = 1;
            if (f1 == hardopt1) ifn1(s) = (intptr_t)tracesethardopt1, done = 1;
            if (f2 == hardopt2) ifn2(s) = (intptr_t)tracesethardopt2, done = 1;
            if (fn == hardoptn) ifnn(s) = (intptr_t)tracesethardoptn, done = 1;
            if (f1 == byteoptrest1) ifn1(s) = (intptr_t)tracesetbyteoptrest1, done = 1;
            if (f2 == byteoptrest2) ifn2(s) = (intptr_t)tracesetbyteoptrest2, done = 1;
            if (fn == byteoptrestn) ifnn(s) = (intptr_t)tracesetbyteoptrestn, done = 1;
            if (f1 == hardoptrest1) ifn1(s) = (intptr_t)tracesethardoptrest1, done = 1;
            if (f2 == hardoptrest2) ifn2(s) = (intptr_t)tracesethardoptrest2, done = 1;
            if (fn == hardoptrestn) ifnn(s) = (intptr_t)tracesethardoptrestn, done = 1;
            if (fixenv)
            {   push2(a, s);
                a = cons(s, qenv(s));
                errexitn(2);
                pop(s);
                qenv(s) = a;
                pop(a);
            }
            if (done) continue;
//
// I permit the tracing of just one function from the kernel, and achieve
// this by installing a wrapper function in place of the real definition.
// Indeed this is just like Lisp-level embedding, except that I can get at the
// entrypoint table used by the bytecode interpreter and so trap calls made
// via there, and I can use that table to tell me how many arguments the
// traced function needed.
//
            if (displaced1 == NULL)
            {   int nargs = funtable_nargs(table_entry);
//
// Remember what function was being traced, so that it can eventually be
// invoked, and its name printed.
//
                displaced1 = f1;
                displaced2 = f2;
                displacedn = fn;
                tracedfn = s;
//
// This makes calls via the regular interpreter see the traced version...
//
                set_fns(s, traced1_function, traced2_function,
                        tracedn_function);
                table_entry = find_built_in_function(f1, f2, fn);
                nargs = funtable_nargs(table_entry);
                table_entry = funtable_index(table_entry);
                if (nargs != NOT_FOUND)
                {
//
// .. and now I make calls via short-form bytecodes do likewise.
//
                    switch (nargs)
                {       default:
                        case 0: no_arg_functions[funtable_index(table_entry)] =
                                tracedn_function;
                            break;
                        case 1: one_arg_functions[funtable_index(table_entry)] =
                                traced1_function;
                            break;
                        case 2: two_arg_functions[funtable_index(table_entry)] =
                                traced2_function;
                            break;
                        case 3: three_arg_functions[funtable_index(table_entry)] =
                                tracedn_function;
                            break;
                    }
                }
            }
            continue;
        }
    }
    return onevalue(a);
}

LispObject Ldouble(LispObject nil, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   LispObject s = qcar(w);
        w = qcdr(w);
        if (symbolp(s))
        {   one_args *f1 = qfn1(s);
            two_args *f2 = qfn2(s);
            n_args *fn = qfnn(s);
            int fixenv = 0, done = 0;
            if (f1 == undefined1) continue;
            if (f1 == interpreted1)
            {   set_fns(s, double_interpreted1, double_interpreted2, double_interpretedn);
                fixenv = done = 1;
            }
            if (f1 == funarged1)
            {   set_fns(s, double_funarged1, double_funarged2, double_funargedn);
                fixenv = done = 1;
            }
            if (fn == bytecoded0) ifnn(s) = (intptr_t)double_bytecoded0, done = 1;
            if (f1 == bytecoded1) ifn1(s) = (intptr_t)double_bytecoded1, done = 1;
            if (f2 == bytecoded2) ifn2(s) = (intptr_t)double_bytecoded2, done = 1;
            if (fn == bytecoded3) ifnn(s) = (intptr_t)double_bytecoded3, done = 1;
            if (fn == bytecodedn) ifnn(s) = (intptr_t)double_bytecodedn, done = 1;
            if (f1 == byteopt1) ifn1(s) = (intptr_t)double_byteopt1, done = 1;
            if (f2 == byteopt2) ifn2(s) = (intptr_t)double_byteopt2, done = 1;
            if (fn == byteoptn) ifnn(s) = (intptr_t)double_byteoptn, done = 1;
            if (f1 == hardopt1) ifn1(s) = (intptr_t)double_hardopt1, done = 1;
            if (f2 == hardopt2) ifn2(s) = (intptr_t)double_hardopt2, done = 1;
            if (fn == hardoptn) ifnn(s) = (intptr_t)double_hardoptn, done = 1;
            if (f1 == byteoptrest1) ifn1(s) = (intptr_t)double_byteoptrest1, done = 1;
            if (f2 == byteoptrest2) ifn2(s) = (intptr_t)double_byteoptrest2, done = 1;
            if (fn == byteoptrestn) ifnn(s) = (intptr_t)double_byteoptrestn, done = 1;
            if (f1 == hardoptrest1) ifn1(s) = (intptr_t)double_hardoptrest1, done = 1;
            if (f2 == hardoptrest2) ifn2(s) = (intptr_t)double_hardoptrest2, done = 1;
            if (fn == hardoptrestn) ifnn(s) = (intptr_t)double_hardoptrestn, done = 1;
            if (fixenv)
            {   push2(a, s);
                a = cons(s, qenv(s));
                errexitn(2);
                pop(s);
                qenv(s) = a;
                pop(a);
            }
            if (done) continue;
            debug_printf("Unable to execution-double: "); loop_print_debug(s);
            trace_printf("\n");
            continue;
        }
    }
    return onevalue(a);
}

LispObject Lundouble(LispObject nil, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   LispObject s = qcar(w);
        w = qcdr(w);
        if (symbolp(s))
        {   one_args *f1 = qfn1(s);
            two_args *f2 = qfn2(s);
            n_args *fn = qfnn(s);
            if (f1 == double_interpreted1)
            {   set_fns(a, interpreted1, interpreted2, interpretedn);
                qenv(s) = qcdr(qenv(s));
            }
            else if (f1 == double_funarged1)
            {   set_fns(s, funarged1, funarged2, funargedn);
                qenv(s) = qcdr(qenv(s));
            }
            else if (f1 == double_bytecoded1) ifn1(s) = (intptr_t)bytecoded1;
            else if (f2 == double_bytecoded2) ifn2(s) = (intptr_t)bytecoded2;
            else if (fn == double_bytecoded0) ifnn(s) = (intptr_t)bytecoded0;
            else if (fn == double_bytecoded3) ifnn(s) = (intptr_t)bytecoded3;
            else if (fn == double_bytecodedn) ifnn(s) = (intptr_t)bytecodedn;
            else if (f1 == double_byteopt1) ifn1(s) = (intptr_t)byteopt1;
            else if (f2 == double_byteopt2) ifn2(s) = (intptr_t)byteopt2;
            else if (fn == double_byteoptn) ifnn(s) = (intptr_t)byteoptn;
            else if (f1 == double_byteoptrest1) ifn1(s) = (intptr_t)byteoptrest1;
            else if (f2 == double_byteoptrest2) ifn2(s) = (intptr_t)byteoptrest2;
            else if (fn == double_byteoptrestn) ifnn(s) = (intptr_t)byteoptrestn;
            else if (f1 == double_hardopt1) ifn1(s) = (intptr_t)hardopt1;
            else if (f2 == double_hardopt2) ifn2(s) = (intptr_t)hardopt2;
            else if (fn == double_hardoptn) ifnn(s) = (intptr_t)hardoptn;
            else if (f1 == double_hardoptrest1) ifn1(s) = (intptr_t)hardoptrest1;
            else if (f2 == double_hardoptrest2) ifn2(s) = (intptr_t)hardoptrest2;
            else if (fn == double_hardoptrestn) ifnn(s) = (intptr_t)hardoptrestn;
        }
    }
    return onevalue(a);
}

#ifdef JIT

//
// This is at present EXPERIMENTAL and INCOMPLETE so do not try it
// unless you are involved in debugging the code involved. It will NOT
// work for general code!
//

LispObject Ljit(LispObject, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   LispObject s = qcar(w);
        w = qcdr(w);
        if (symbolp(s))
        {   one_args *f1 = qfn1(s);
            two_args *f2 = qfn2(s);
            n_args *fn = qfnn(s);
            int done = 0;
            if (fn == bytecoded0) ifnn(s) = (intptr_t)jitcompileme0, done = 1;
            if (f1 == bytecoded1) ifn1(s) = (intptr_t)jitcompileme1, done = 1;
            if (f2 == bytecoded2) ifn2(s) = (intptr_t)jitcompileme2, done = 1;
            if (fn == bytecoded3) ifnn(s) = (intptr_t)jitcompileme3, done = 1;
            if (fn == bytecodedn) ifnn(s) = (intptr_t)jitcompilemen, done = 1;
            if (!done)
            {   freshline_debug();
                debug_printf("+++ ");
                loop_print_debug(s);
                debug_printf(" not a candidate for JIT\n");
            }
            continue;
        }
    }
    return onevalue(a);
}

#endif // JIT

LispObject Lmacro_function(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & SYM_MACRO) == 0) return onevalue(nil);
// If the MACRO bit is set in the header I know there is a definition
    else return onevalue(cons(lambda, qenv(a)));
}


LispObject get_pname(LispObject a)
{   LispObject name = qpname(a);
#ifndef COMMON
//
// When a gensym is first created its pname field points at a string that
// will form the base of its name, and a magic bit is set in its header.
// If at some stage it is necessary to inspect the print name (mainly in
// order to print the symbol) it becomes necessary to create a new string
// and insert a serial number.  Doing things this way means that the serial
// numbers that users see will tend to be smaller, and space for per-gensym
// strings does not get allocated unless really needed.  The down side is
// that every time I want to grab the pname of anything I have to check for
// this case and admit the possibility of garbage collection or even
// failure.
//
    if (qheader(a) & SYM_UNPRINTED_GENSYM)
    {   uintptr_t len;
        char *p;
        LispObject nil = C_nil;
        char genname[80];
        len = length_of_byteheader(vechdr(name)) - CELL;
        if (len > 60) len = 60;     // Unpublished truncation of the string
// I will make the first 10K names g0000 to g9999 with exactly 4 digits
// at the end. After that I will use
// g9999_999, g9999_999_999, g9999_999_999_999 with underscores separating
// off ech trailing group of 3 digits. THis scheme has two separate
// motivations. The first is that putting digits in blocks of 3 might
// make the names easier to read. The second is that this arrangement
// will let me look at the full name of a printed gensym and separate off
// the "numeric" suffix. The code I have here would allow for up to 10^13
// distinct gensyms, and after that it wraps round. Well on a 32-bit
// system it counts up to 2^32 and wraps there.
        sprintf(genname, "%.*s", (int)len, &celt(name, 0));
        p = genname+len;
        if (gensym_ser <= 9999) sprintf(p, "%.4d", (int)gensym_ser);
        else if (gensym_ser <= 9999999)
            sprintf(p, "%.4d_%.3d",
                (int)(gensym_ser/1000),
                (int)(gensym_ser%1000));
        else if (!SIXTY_FOUR_BIT || gensym_ser <= UINT64_C(99999999999))
            sprintf(p, "%.4d_%.3d_%.3d",
                (int)(gensym_ser/1000000),
                (int)((gensym_ser/1000)%1000),
                (int)(gensym_ser%1000));
        else
            sprintf(p, "%.4d_%.3d_%.3d_%.3d",
                (int)((gensym_ser/1000000000)%10000),
                (int)((gensym_ser/1000000)%1000),
                (int)((gensym_ser/1000)%1000),
                (int)(gensym_ser%1000));
        gensym_ser++;
        push(a);
        name = make_string(genname);
        pop(a);
        errexit();
        qpname(a) = name;
        qheader(a) &= ~SYM_UNPRINTED_GENSYM;
    }
#endif
    return name;
}

LispObject Lsymbol_name(LispObject nil, LispObject a)
{   if (!symbolp(a)) return aerror1("symbol-name", a);
    a = get_pname(a);
    errexit();
    return onevalue(a);
}

LispObject Lsymbol_package(LispObject nil, LispObject a)
{   if (!symbolp(a)) return aerror1("symbol-package", a);
    a = qpackage(a);
    return onevalue(a);
}

static LispObject Lrestart_lisp2(LispObject nil,
                                 LispObject a, LispObject b)
//
// If the argument is given as nil then this is a cold-start, and when
// I begin again it would be a VERY good idea to do a (load!-module 'compat)
// rather promptly (otherwise some Lisp functions will not work at all).
// I do not automate that because this function is intended for use in
// delicate system rebuilding contexts and I want the user to have ultimate
// control.  (restart!-lisp t) reloads a heap-image in the normal way.
// (restart!-lisp 'xx) where xx is neither nil nor t starts by reloading a
// heap image, but then it looks for a function with the same name as xx
// (since a heap image is reloaded it is NOT easy (possible?) to keep the
// symbol) and calls it as a function. Finally the case
// (restart!-lisp '(module xx)) reloads the heap image, calls load-module
// on the named module and finally calls the given restart function.
// This last option can be useful since otherwise the function to be called
// in (restart!-lisp 'xx) would need to be in the base image as re-loaded.
// There is no provision here to force a cold start followed by a reload
// of some particular module.
//
// The second argument (if provided) is passed through (via serialization
// as a string of characters) and remade as a Lisp object to be passed to
// the custom restart function as an argument. Thus in (restart!-lisp 'xx) the
// function xx should not take any arguments, while in the call
// (restart!-list 'xx 'argument) the function xx must accept one argument.
//
// The expectation is that when this function is called Lisp will be reading
// from its initial default input source, and that will be preserved across
// the restart. A log file and the standard output should also be safe,
// but no other files should be active when restart!-lisp is called.
//
{   int n;
    char *v;
    ensure_screen();
    n = 0;
    v = NULL;
//
// A comment seems in order here. The case b==SPID_NOARG should only
// arise if I came from Lrestart_lisp: it indicates that there was
// no second argument provided.
//
    if (b != SPID_NOARG)
    {   LispObject b1;
        push(a);
//
// I will need to pack the data into a character vector using utf-8
// encoding... exploden can hand back character codes up to 0x0010ffff.
//
        b1 = b = Lexploden(nil, b);
        pop(a);
        errexit();
        while (b1 != nil)
        {   int ch = int_of_fixnum(qcar(b1));
            n++;            // number of chars of arg
            if (ch > 0x7f) n++; // extra byte
            if (ch > 0x7ff) n++;
            if (ch > 0xffff) n++; // Now have enough bytes for utf8
            b1 = qcdr(b1);
        }
        v = (char *)malloc(n+1);
        if (v == NULL) return aerror("space exhausted in restart-csl");
        n = 0;
        while (b != nil)
        {   int ch = int_of_fixnum(qcar(b));
            if (ch <= 0x7f) v[n++] = ch;
            else if (ch < 0x7ff)
            {   v[n++] = 0xc0 | ((ch >> 6) & 0x1f);
                v[n++] = 0x80 | (ch & 0x3f);
            }
            else if (ch < 0xffff)
            {   v[n++] = 0xe0 | ((ch >> 12) & 0x0f);
                v[n++] = 0x80 | ((ch >> 6) & 0x3f);
                v[n++] = 0x80 | (ch & 0x3f);
            }
            else
            {   v[n++] = 0xf0 | ((ch >> 18) & 0x07);
                v[n++] = 0x80 | ((ch >> 12) & 0x3f);
                v[n++] = 0x80 | ((ch >> 6) & 0x3f);
                v[n++] = 0x80 | (ch & 0x3f);
            }
            b = qcdr(b);
        }
        v[n] = 0;
    }
    term_printf("\nThe system is about to do a restart...\n");
// Almost all unpicking of the argument is done back in csl.c
    exit_value = a;
    exit_tag = fixnum_of_int(2);   // Flag to say "restart"
    exit_reason = UNWIND_RESTART;
    exit_charvec = v;
    flip_exception();
    return nil;
}

static LispObject Lrestart_lisp(LispObject nil, LispObject a)
{   return Lrestart_lisp2(nil, a, SPID_NOARG);
}

static LispObject Lpreserve_03(LispObject nil, int nargs, ...)
{   LispObject startup = nil, banner = nil, resume = nil;
    char filename[LONGEST_LEGAL_FILENAME];
    bool failed;
    if (nargs!=0)
    {   va_list a;
        argcheck(nargs, 3, "preserve");
        va_start(a, nargs);
        startup = va_arg(a, LispObject);
        banner = va_arg(a, LispObject);
        resume = va_arg(a, LispObject);
        va_end(a);
    }
    memset(filename, 0, sizeof(filename));
    if (startup != nil) supervisor = startup;
    failed = Iwriterootp(filename);  // Can I open image file for writing?
    term_printf("\nThe system will be preserved on file \"%s\"\n", filename);
    if (failed) return aerror("preserve");
    ensure_screen();
    exit_count = 0;  // no value at all returned
    nil = C_nil;
    exit_value = banner;
    exit_tag = resume == nil ? fixnum_of_int(1) : // Flag to say "preserve"
               fixnum_of_int(3);                  // preserve and restart
    exit_reason = UNWIND_RESTART;
    flip_exception();
    return nil;
}

static LispObject Lpreserve_1(LispObject nil, LispObject startup)
{   return Lpreserve_03(nil, 3, startup, nil, nil);
}

static LispObject Lpreserve_2(LispObject nil,
                              LispObject startup, LispObject banner)
//
// (preserve <startup-fn>) saves a Lisp image in a standard place
// and arranges that when restarted the saved image will call the specified
// startup function.  In the process of doing all this it unwinds down to
// the top level of Lisp. If a startup function is not given then the
// previously active one is used.  If nil is specified then the previously
// active startup function is retained.  If banner is non-nil (well really
// I want a string) is is a message of up to 40 characters to display
// when the system restart.
//
{   return Lpreserve_03(nil, 3, startup, banner, nil);
}


#if 0
//
// This is an experimental addition - a version of PRESERVE that allows
// CSL to continue executing after it has written out an image file. I am
// now removing it because I have arranged that if PRESERVE is given a
// non-nil third argument it reloads the image that it creates rather than
// quitting lisp.
//

// ++++ With the new serialization-based scheme for preserve() this would
//      all become almost trivial to reinstate if I thought it was useful!


static LispObject Lcheckpoint(LispObject nil,
                              LispObject startup, LispObject banner)
{   char filename[LONGEST_LEGAL_FILENAME];
    bool failed = false;
    char *msg = "";
    int len = 0;
    memset(filename, 0, sizeof(filename));
    ensure_screen();
    if (startup != nil) supervisor = startup;
    failed = Iwriterootp(filename);  // Can I open image file for writing?
    term_printf("\nThe system will be preserved on file \"%s\"\n", filename);
    if (failed) return aerror("checkpoint");
    if (is_vector(banner) && is_string(banner))
    {   msg = &celt(banner, 0);
        len = length_of_byteheader(vechdr(banner)) - CELL;
    }
//
// Note, with some degree of nervousness, that things on the C stack will
// be updated by the garbage collection that happens during the processing
// of the call to preserve(), but they will be neither adjusted into
// relative addresses nor unadjusted (and hence restored) by in the
// image-writing. But the image writing will not actually move any data
// around so all is still OK, I hope!
//
    push3(catch_tags, faslvec, faslgensyms);
    preserve(msg, len);
    nil = C_nil;
    if (exception_pending()) failed = 1, flip_exception();
    adjust_all();
    pop3(faslgensyms, faslvec, catch_tags);
    eq_hash_tables = eq_hash_table_list;
    equal_hash_tables = equal_hash_table_list;
    eq_hash_table_list = equal_hash_table_list = nil;
    {   LispObject qq;
        for (qq = eq_hash_tables; qq!=nil; qq=qcdr(qq))
            rehash_this_table(qcar(qq));
        for (qq = equal_hash_tables; qq!=nil; qq=qcdr(qq))
            rehash_this_table(qcar(qq));
    }
    set_up_functions(true);
    if (failed) return aerror("checkpoint");
    return onevalue(nil);
}

static LispObject Lcheckpoint_0(LispObject nil, int nargs, ...)
{   argcheck(nargs, 0, "checkpoint");
    return Lcheckpoint(nil, nil, nil);
}

static LispObject Lcheckpoint_1(LispObject nil, LispObject startup)
{   return Lcheckpoint(nil, startup, nil);
}

#endif


//
// Drop out to the next enclosing code that limits resources, as if there had
// been an overflow.
//

static LispObject Lresource_exceeded(LispObject nil, int nargs, ...)
{   argcheck(nargs, 0, "resource-exceeded");
    return resource_exceeded();
}

static bool eql_numbers(LispObject a, LispObject b)
//
// This is only called from eql, and then only when a and b are both tagged
// as ratios or complex numbers.
//
{   LispObject p, q;
    p = *(LispObject *)(a + (CELL - TAG_NUMBERS));
    q = *(LispObject *)(b + (CELL - TAG_NUMBERS));
    if (!eql(p, q)) return false;
    p = *(LispObject *)(a + (2*CELL - TAG_NUMBERS));
    q = *(LispObject *)(b + (2*CELL - TAG_NUMBERS));
    return eql(p, q);
}

bool eql_fn(LispObject a, LispObject b)
//
// This seems incredible - all the messing about that is needed to
// check that numeric values compare properly.  Ugh.
//
{
//
// (these tests done before eql_fn is called).
//  if (a == b) return true;
//  if ((((intptr_t)a ^ (intptr_t)b) & TAG_BITS) != 0) return false;
//
// Actually in Common Lisp mode where I have short floats as immediate data
// I have further pain here with (eql 0.0s -0.0s), and (eql NaN NaN) might
// improperly return true because of the early EQ test. 
//
    if ((a == XTAG_SFLOAT && b == (XTAG_SFLOAT|(intptr_t)0x80000000U)) ||
        (a == (XTAG_SFLOAT|(intptr_t)0x80000000U) && b == XTAG_SFLOAT))
        return true;
    if (!is_number(a) || is_immed_or_cons(a)) return false;
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        if (h != flthdr(b)) return false;
        if (type_of_header(h) == TYPE_SINGLE_FLOAT)
            return (single_float_val(a) == single_float_val(b));
        else
//
// For the moment I view all non-single floats as double floats. Extra
// stuff will be needed here if I ever implement long floats as 3-word
// objects.
//
            return (double_float_val(a) == double_float_val(b));
    }
    else    // ratio, complex or bignum
    {   Header h = numhdr(a);
        if (h != numhdr(b)) return false;
        if (type_of_header(h) == TYPE_BIGNUM)
        {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
            while (hh > (intptr_t)(CELL - TAG_NUMBERS))
            {   hh -= 4;
                if (*(uint32_t *)((char *)a + hh) !=
                    *(uint32_t *)((char *)b + hh))
                    return false;
            }
            return true;
        }
        else return eql_numbers(a, b);
    }
}

#ifdef COMMON
#define eqcheck(a, b) eql(a, b)
#else
#define eqcheck(a, b) ((a) == (b))
#endif

static bool cl_vec_equal(LispObject a, LispObject b)
//
// here a and b are known to be vectors or arrays.  This should compare
// them following the Common Lisp recipe, where strings or bitvectors
// (simple or complex) have their contents compared, while all other types of
// vector or array are tested using EQ.
//
{   Header ha = vechdr(a), hb = vechdr(b);
    intptr_t offa = 0, offb = 0;
    int ta = type_of_header(ha), tb = type_of_header(hb);
    intptr_t la = length_of_header(ha), lb = length_of_header(hb);
    if (is_bitvec_header(ha)) ta = TYPE_BITVEC_1;
    if (is_bitvec_header(hb)) tb = TYPE_BITVEC_1;
    switch (ta)
    {
//
//case TYPE_ARRAY:
///  My moan here is that, as noted above, I ought to process even
// non-simple strings and bit-vectors by comparing contents, but as a
// matter of idleness I have not yet got around to that. In fact if I get
// arrays to compare here I will pretend that they are not strings or
// bit-vectors and compare using EQ...
//
        case TYPE_STRING_1:
        case TYPE_STRING_2:
        case TYPE_STRING_3:
        case TYPE_STRING_4:
            switch (tb)
            {
// /*
//  case TYPE_ARRAY:
//
                case TYPE_STRING_1:
                case TYPE_STRING_2:
                case TYPE_STRING_3:
                case TYPE_STRING_4:
                    goto compare_strings;
                default:return false;
            }
        case TYPE_BITVEC_1:
        case TYPE_BITVEC_2:
        case TYPE_BITVEC_3:
        case TYPE_BITVEC_4:
        case TYPE_BITVEC_5:
        case TYPE_BITVEC_6:
        case TYPE_BITVEC_7:
        case TYPE_BITVEC_8:
        case TYPE_BITVEC_9:
        case TYPE_BITVEC_10:
        case TYPE_BITVEC_11:
        case TYPE_BITVEC_12:
        case TYPE_BITVEC_13:
        case TYPE_BITVEC_14:
        case TYPE_BITVEC_15:
        case TYPE_BITVEC_16:
        case TYPE_BITVEC_17:
        case TYPE_BITVEC_18:
        case TYPE_BITVEC_19:
        case TYPE_BITVEC_20:
        case TYPE_BITVEC_21:
        case TYPE_BITVEC_22:
        case TYPE_BITVEC_23:
        case TYPE_BITVEC_24:
        case TYPE_BITVEC_25:
        case TYPE_BITVEC_26:
        case TYPE_BITVEC_27:
        case TYPE_BITVEC_28:
        case TYPE_BITVEC_29:
        case TYPE_BITVEC_30:
        case TYPE_BITVEC_31:
        case TYPE_BITVEC_32:
            switch (tb)
            {
// /*
//  case TYPE_ARRAY:
//
                case TYPE_BITVEC_1:
                case TYPE_BITVEC_2:
                case TYPE_BITVEC_3:
                case TYPE_BITVEC_4:
                case TYPE_BITVEC_5:
                case TYPE_BITVEC_6:
                case TYPE_BITVEC_7:
                case TYPE_BITVEC_8:
                case TYPE_BITVEC_9:
                case TYPE_BITVEC_10:
                case TYPE_BITVEC_11:
                case TYPE_BITVEC_12:
                case TYPE_BITVEC_13:
                case TYPE_BITVEC_14:
                case TYPE_BITVEC_15:
                case TYPE_BITVEC_16:
                case TYPE_BITVEC_17:
                case TYPE_BITVEC_18:
                case TYPE_BITVEC_19:
                case TYPE_BITVEC_20:
                case TYPE_BITVEC_21:
                case TYPE_BITVEC_22:
                case TYPE_BITVEC_23:
                case TYPE_BITVEC_24:
                case TYPE_BITVEC_25:
                case TYPE_BITVEC_26:
                case TYPE_BITVEC_27:
                case TYPE_BITVEC_28:
                case TYPE_BITVEC_29:
                case TYPE_BITVEC_30:
                case TYPE_BITVEC_31:
                case TYPE_BITVEC_32:
                    goto compare_bits;
                default:return false;
            }
        default: return (a == b);
    }
compare_strings:
    la = length_of_byteheader(ha);
    lb = length_of_byteheader(hb);
    if (la != lb) return false;
    while (la > 0)
    {   la--;
        if (*((char *)a + la + offa - TAG_VECTOR) !=
            *((char *)b + la + offb - TAG_VECTOR)) return false;
    }
    return true;
compare_bits:
    la = length_of_bitheader(ha);
    lb = length_of_bitheader(hb);
    if (la != lb) return false;
// I will insist that the bitvectors have zero bits in any unused space
// in their final byte. 
    la = (la + 7)/8;
    lb = (lb + 7)/8;
    while (la > 0)
    {   la--;
        if (*((char *)a + la + offa - TAG_VECTOR) !=
            *((char *)b + la + offb - TAG_VECTOR)) return false;
    }
    return true;
}

bool cl_equal_fn(LispObject a, LispObject b)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code.
//
{
#ifdef COMMON
    LispObject nil = C_nil;
#endif
//
// The for loop at the top here is so that cl_equal can iterate along the
// length of linear lists.
//
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("Stack too deep in cl_equal\n");
        return false;
    }
#endif
    for (;;)
    {   int32_t ta = (int32_t)a & TAG_BITS;
        if (ta == TAG_CONS
#ifdef COMMON
            && a != nil
#endif
           )
        {   if (!consp(b)
#ifdef COMMON
                || b == nil
#endif
               ) return false;
            else
            {   LispObject ca = qcar(a), cb = qcar(b);
                if (ca == cb)
                {   a = qcdr(a);
                    b = qcdr(b);
                    if (a == b) return true;
                    continue;
                }
//
// And here, because cl_equal() seems to be a very important low-level
// primitive, I unwind one level of the recursion that would arise
// with nested lists.
//
                for (;;)
                {   int32_t tca = (int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS
#ifdef COMMON
                        && ca != nil
#endif
                       )
                    {   if (!consp(cb)
#ifdef COMMON
                            || cb == nil
#endif
                           ) return false;
                        else
                        {   LispObject cca = qcar(ca), ccb = qcar(cb);
                            if (cca == ccb)
                            {   ca = qcdr(ca);
                                cb = qcdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
//
// Do a real recursion when I get down to args like
// ((x ...) ...) ((y ...) ...)
//
                            if (!cl_equal(cca, ccb)) return false;
                            ca = qcdr(ca);
                            cb = qcdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (is_immed_cons_sym(tca) ||
                             ((int32_t)cb & TAG_BITS) != tca) return false;
                    else switch (tca)
                        {   case TAG_NUMBERS:
                            {   Header h = numhdr(ca);
                                if (h != numhdr(cb)) return false;
                                if (type_of_header(h) == TYPE_BIGNUM)
                                {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                                    while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                                    {   hh -= 4;
                                        if (*(uint32_t *)((char *)ca + hh) !=
                                            *(uint32_t *)((char *)cb + hh))
                                            return false;
                                    }
                                    break;
                                }
                                else if (!eql_numbers(ca, cb)) return false;
                                else break;
                            }
                            case TAG_VECTOR:
                                if (!cl_vec_equal(ca, cb)) return false;
                                break;
                            default:
                            case TAG_BOXFLOAT:
                            {   Header h = flthdr(ca);
                                if (h != flthdr(cb)) return false;
                                if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                                {   if (single_float_val(ca) !=
                                        single_float_val(cb)) return false;
                                    else break;
                                }
                                else
                                {   if (double_float_val(ca) !=
                                        double_float_val(cb)) return false;
                                    else break;
                                }
                            }
                        }
                    break;  // out of the for (;;) loop
                }
                a = qcdr(a);
                b = qcdr(b);
                if (a == b) return true;
                continue;
            }
        }
        else if (is_immed_cons_sym(ta) ||
                 ((int32_t)b & TAG_BITS) != ta) return false;
//
// OK - now a and b both have the same type and neither are immediate data
// conses or symbols. That leaves vectors (including strings) and boxed
// numbers.
//
        else switch (ta)
            {   case TAG_NUMBERS:
                {   Header h = numhdr(a);
                    if (h != numhdr(b)) return false;
                    if (type_of_header(h) == TYPE_BIGNUM)
                    {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                        while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                        {   hh -= 4;
                            if (*(uint32_t *)((char *)a + hh) !=
                                *(uint32_t *)((char *)b + hh))
                                return false;
                        }
                        return true;
                    }
                    else return eql_numbers(a, b);
                }
                case TAG_VECTOR:
                    return cl_vec_equal(a, b);
                default:
                case TAG_BOXFLOAT:
                {   Header h = flthdr(a);
                    if (h != flthdr(b)) return false;
                    if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                    {   if (single_float_val(a) != single_float_val(b))
                            return false;
                        else return true;
                    }
                    else
//
// For the moment I view all non-single floats as double floats. Extra
// stuff will be needed here if I ever implement long floats as 3-word
// objects.
//
                    {   if (double_float_val(a) != double_float_val(b))
                            return false;
                        else return true;
                    }
                }
            }
    }
}

static bool vec_equal(LispObject a, LispObject b);

//
// Hmmm - EQUAL could be re-implemented to be non-recursive via pointer
// reversing and if that was done then there could not possibly be any
// concerns about stck overflow in it. Furthermore since EQUAL traverses
// the two input lists in lockstep and only dived into structures that
// are not EQ, and since a larger part of one list can not be EQUAL to
// a smaller part of the other it may be that the temporary rearrangement
// to one list can never confuse traversal of the other. I might want to
// think about recovery in the case that cyclic (and partially shared) lists
// are presented. Until I implement this I do not know what the performance
// would be as compared agsinst a regular recursive version.
//
// For performance I might wish to consider an implementation that
// defers pointer reversal via a small local stack of depth (say) three.
// Oh what a jolly and messy project it will be if I get round to implementing
// and measuring that!
//

#ifdef TRACED_EQUAL
#define LOG_SIZE 10000
typedef struct equal_record
{   char file[24];
    int line;
    int depth;
    int count;
} equal_record;

static equal_record equal_counts[LOG_SIZE];

static void record_equal(char *file, int line, int depth)
{   int hash = 169*line + depth;
    char *p = file;
    while (*p != 0) hash = 169*hash + (*p++ & 0xff);
    hash = ((169*hash) & 0x7fffffff) % LOG_SIZE;
    while (equal_counts[hash].count != 0)
    {   if (equal_counts[hash].line == line &&
            equal_counts[hash].depth == depth &&
            strncmp(equal_counts[hash].file, file, 24) == 0)
        {   equal_counts[hash].count++;
            return;
        }
        hash = (hash + 1) % LOG_SIZE;
    }
    strncpy(equal_counts[hash].file, file, 24);
    equal_counts[hash].line = line;
    equal_counts[hash].depth = depth;
    equal_counts[hash].count = 1;
    return;
}

void dump_equals()
{   int i;
    FILE *log = fopen("equal.log", "w");
    if (log == NULL) log = stdout;
    fprintf(log, "\nCalls to equal...\n");
    for (i=0; i<LOG_SIZE; i++)
        if (equal_counts[i].count != 0)
            fprintf(log, "%24.24s %5d %5d %10d\n",
                    equal_counts[i].file, equal_counts[i].line,
                    equal_counts[i].depth, equal_counts[i].count);
    fprintf(log, "end of counts\n");
    if (log != stdout) fclose(log);
}

bool traced_equal_fn(LispObject a, LispObject b,
                        char *file, int line, int depth)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code.
//
{   LispObject nil = C_nil;
    record_equal(file, line, depth);
#undef equal_fn
#define equal_fn(a, b) traced_equal_fn(a, b, file, line, depth+1)
#else
bool equal_fn(LispObject a, LispObject b)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code. I will also have checked that
// the types of the two args agree, and that they are not both immediate
// date.
//
{
#ifdef COMMON
    LispObject nil = C_nil;
#endif
#endif
//
// The for loop at the top here is so that equal can iterate along the
// length of linear lists. For MANY MANY cases in a Lisp world data
// structures will be long but not so terribly deep and so one hopes that
// stack requirements here will not be excessive. Hahaha - if I had a
// non-recursive version of the code too but it proved generally slower
// I could trigger a transfer into it at the stage that stck use became
// excessive...
//
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("Stack too deep in equal\n");
        return false;
    }
#endif
    for (;;)
    {   int32_t ta = (int32_t)a & TAG_BITS;
        if (ta == TAG_CONS
#ifdef COMMON
            && a != nil
#endif
           )
        {   if (!consp(b)
#ifdef COMMON
                || b == nil
#endif
               ) return false;
            else
            {   LispObject ca = qcar(a), cb = qcar(b);
                if (ca == cb)
                {   a = qcdr(a);
                    b = qcdr(b);
                    if (a == b) return true;
                    continue;
                }
//
// And here, because equal() seems to be a very important low-level
// primitive, I unwind one level of the recursion that would arise
// with nested lists.
//
                for (;;)
                {   int32_t tca = (int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS
#ifdef COMMON
                        && ca != nil
#endif
                       )
                    {   if (!consp(cb)
#ifdef COMMON
                            || cb == nil
#endif
                           ) return false;
                        else
                        {   LispObject cca = qcar(ca), ccb = qcar(cb);
                            if (cca == ccb)
                            {   ca = qcdr(ca);
                                cb = qcdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
//
// Do a real recursion when I get down to args like
// ((x ...) ...) ((y ...) ...)
//
                            if (!equal(cca, ccb)) return false;
                            ca = qcdr(ca);
                            cb = qcdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (is_immed_cons_sym(tca) ||
                             ((int32_t)cb & TAG_BITS) != tca) return false;
                    else switch (tca)
                        {   case TAG_NUMBERS:
                            {   Header h = numhdr(ca);
                                if (h != numhdr(cb)) return false;
                                if (type_of_header(h) == TYPE_BIGNUM)
                                {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                                    while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                                    {   hh -= 4;
                                        if (*(uint32_t *)((char *)ca + hh) !=
                                            *(uint32_t *)((char *)cb + hh))
                                            return false;
                                    }
                                    break;
                                }
                                else if (!eql_numbers(ca, cb)) return false;
                                else break;
                            }
                            case TAG_VECTOR:
                                if (!vec_equal(ca, cb)) return false;
                                break;
                            default:
                            case TAG_BOXFLOAT:
                            {   Header h = flthdr(ca);
                                if (h != flthdr(cb)) return false;
                                if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                                {   if (single_float_val(ca) !=
                                        single_float_val(cb)) return false;
                                    else break;
                                }
                                else
                                {   if (double_float_val(ca) !=
                                        double_float_val(cb)) return false;
                                    else break;
                                }
                            }
                        }
                    break;  // out of the for (;;) loop
                }
                a = qcdr(a);
                b = qcdr(b);
                if (a == b) return true;
                continue;
            }
        }
        else if (is_immed_cons_sym(ta) ||
                 ((int32_t)b & TAG_BITS) != ta) return false;
        else switch (ta)
            {   case TAG_NUMBERS:
                {   Header h = numhdr(a);
                    if (h != numhdr(b)) return false;
                    if (type_of_header(h) == TYPE_BIGNUM)
                    {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                        while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                        {   hh -= 4;
                            if (*(uint32_t *)((char *)a + hh) !=
                                *(uint32_t *)((char *)b + hh))
                                return false;
                        }
                        return true;
                    }
                    else return eql_numbers(a, b);
                }
                case TAG_VECTOR:
                    return vec_equal(a, b);
                default:
                case TAG_BOXFLOAT:
                {   Header h = flthdr(a);
                    if (h != flthdr(b)) return false;
                    if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                    {   if (single_float_val(a) != single_float_val(b))
                            return false;
                        else return true;
                    }
                    else
//
// For the moment I view all non-single floats as double floats. Extra
// stuff will be needed here if I ever implement long floats as 3-word
// objects.
//
                    {   if (double_float_val(a) != double_float_val(b))
                            return false;
                        else return true;
                    }
                }
            }
    }
}

#ifdef TRACED_EQUAL
#undef equal_fn
#define equal_fn(a, b) traced_equal(a, b, __FILE__, __LINE__, 0)
#endif

static bool vec_equal(LispObject a, LispObject b)
//
// Here a and b are known to be vectors. Compare using recursive calls to
// EQUAL on all components.
//
{   Header ha = vechdr(a), hb = vechdr(b);
    size_t l;
    if (ha != hb) return false;
//
// This used to check all the way up to the end of the final doubleword
// that the vector was padded to. This means that it was VITAL that any
// vector needed any final padding word put in a definite and good state.
// Checking only the words that matter is just marginally quicker and
// will fail less often if I do not pad properly!
//
    l = (size_t)word_align_up(length_of_header(ha));
    if (vector_holds_binary(ha))
    {   while ((l -= 4) != 0)
            if (*((uint32_t *)((char *)a + l - TAG_VECTOR)) !=
                *((uint32_t *)((char *)b + l - TAG_VECTOR))) return false;
        return true;
    }
    else
    {   if (is_mixed_header(ha))
        {   while (l > 16)
            {   uint32_t ea = *((uint32_t *)((char *)a + l - TAG_VECTOR - 4)),
                         eb = *((uint32_t *)((char *)b + l - TAG_VECTOR - 4));
                if (ea != eb) return false;
                l -= 4;
            }
        }
        while ((l -= CELL) != 0)
        {   LispObject ea = *((LispObject *)((char *)a + l - TAG_VECTOR)),
                       eb = *((LispObject *)((char *)b + l - TAG_VECTOR));
            if (ea == eb) continue;
            if (!equal(ea, eb)) return false;
        }
        return true;
    }
}

bool equalp(LispObject a, LispObject b)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code.
//
{
#ifdef COMMON
    LispObject nil = C_nil;
#endif
//
// The for loop at the top here is so that equalp can iterate along the
// length of linear lists.
//
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("Stack too deep in equalp\n");
        return false;
    }
#endif
    for (;;)
    {   int32_t ta = (int32_t)a & TAG_BITS;
        if (ta == TAG_CONS
#ifdef COMMON
            && a != nil
#endif
           )
        {   if (!consp(b)
#ifdef COMMON
                || b == nil
#endif
               ) return false;
            else
            {   LispObject ca = qcar(a), cb = qcar(b);
                if (ca == cb)
                {   a = qcdr(a);
                    b = qcdr(b);
                    if (a == b) return true;
                    continue;
                }
//
// And here, because equalp() seems to be a very important low-level
// primitive, I unwind one level of the recursion that would arise
// with nested lists.
//
                for (;;)
                {   int32_t tca = (int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS
#ifdef COMMON
                        && ca != nil
#endif
                       )
                    {   if (!consp(cb)
#ifdef COMMON
                            || cb == nil
#endif
                           ) return false;
                        else
                        {   LispObject cca = qcar(ca), ccb = qcar(cb);
                            if (cca == ccb)
                            {   ca = qcdr(ca);
                                cb = qcdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
//
// Do a real recursion when I get down to args like
// ((x ...) ...) ((y ...) ...)
//
                            if (!equalp(cca, ccb)) return false;
                            ca = qcdr(ca);
                            cb = qcdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (is_immed_cons_sym(tca) ||
                             ((int32_t)cb & TAG_BITS) != tca) return false;
                    else switch (tca)
                        {   case TAG_NUMBERS:
                            {   Header h = numhdr(ca);
                                if (h != numhdr(cb)) return false;
                                if (type_of_header(h) == TYPE_BIGNUM)
                                {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                                    while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                                    {   hh -= 4;
                                        if (*(uint32_t *)((char *)ca + hh) !=
                                            *(uint32_t *)((char *)cb + hh))
                                            return false;
                                    }
                                    break;
                                }
                                else if (!eql_numbers(ca, cb)) return false;
                                else break;
                            }
                            case TAG_VECTOR:
// /* At present vec_equal() is not right here
                                if (!vec_equal(ca, cb)) return false;
                                break;
                            default:
                            case TAG_BOXFLOAT:
                            {   Header h = flthdr(ca);
                                if (h != flthdr(cb)) return false;
                                if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                                {   if (single_float_val(ca) !=
                                        single_float_val(cb)) return false;
                                    else break;
                                }
                                else
                                {   if (double_float_val(ca) !=
                                        double_float_val(cb)) return false;
                                    else break;
                                }
                            }
                        }
                    break;  // out of the for (;;) loop
                }
                a = qcdr(a);
                b = qcdr(b);
                if (a == b) return true;
                continue;
            }
        }
        else if (is_immed_cons_sym(ta) ||
                 ((int32_t)b & TAG_BITS) != ta) return false;
// What is left is vectors, strings and boxed numbers
        else switch (ta)
            {   case TAG_NUMBERS:
                {   Header h = numhdr(a);
                    if (h != numhdr(b)) return false;
                    if (type_of_header(h) == TYPE_BIGNUM)
                    {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                        while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                        {   hh -= 4;
                            if (*(uint32_t *)((char *)a + hh) !=
                                *(uint32_t *)((char *)b + hh))
                                return false;
                        }
                        return true;
                    }
                    else return eql_numbers(a, b);
                }
                case TAG_VECTOR:
// /* wrong for Common Lisp
                    return vec_equal(a, b);
                default:
                case TAG_BOXFLOAT:
                {   Header h = flthdr(a);
                    if (h != flthdr(b)) return false;
                    if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                    {   if (single_float_val(a) != single_float_val(b))
                            return false;
                        else return true;
                    }
                    else
//
// For the moment I view all non-single floats as double floats. Extra
// stuff will be needed here if I ever implement long floats as 3-word
// objects.
//
                    {   if (double_float_val(a) != double_float_val(b))
                            return false;
                        else return true;
                    }
                }
            }
    }
}

LispObject Leq(LispObject nil, LispObject a, LispObject b)
{   return onevalue(Lispify_predicate(a == b));
}

LispObject Leql(LispObject nil,
                LispObject a, LispObject b)
{   return onevalue(Lispify_predicate(eql(a, b)));
}

LispObject Leqcar(LispObject nil,
                  LispObject a, LispObject b)
{   if (!consp(a)) return onevalue(nil);
    a = qcar(a);
    return onevalue(Lispify_predicate(eqcheck(a, b)));
}

LispObject Lequalcar(LispObject nil,
                     LispObject a, LispObject b)
{   if (!consp(a)) return onevalue(nil);
    a = qcar(a);
    if (a == b) return lisp_true;
    else return onevalue(Lispify_predicate(equal(a, b)));
}

LispObject Lcl_equal(LispObject nil, LispObject a, LispObject b)
{   if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(cl_equal(a, b)));
}

LispObject Lequal(LispObject nil, LispObject a, LispObject b)
{   if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(equal(a, b)));
}

LispObject Lequalp(LispObject nil, LispObject a, LispObject b)
{   if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(equalp(a, b)));
}

LispObject Lneq(LispObject nil,
                LispObject a, LispObject b)
{   bool r;
#ifdef COMMON
    r = cl_equal(a, b);
#else
//
// Note that "equal" here is a macro that expands to something that
// checks the EQ case in-line, so there is no merit in putting
//   if (a == b) return onevalue(nil);
// first.
//
    r = equal(a, b);
#endif
    return onevalue(Lispify_predicate(!r));
}

LispObject Lnull(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(a == nil));
}

LispObject Lendp(LispObject nil, LispObject a)
{   if (a == nil) return onevalue(lisp_true);
    else if (is_cons(a)) return onevalue(nil);
    else return error(1, err_bad_endp, a);
}

LispObject Lnreverse(LispObject nil, LispObject a)
{   LispObject b = nil;
#ifdef COMMON
    if (is_vector(a))
    {   intptr_t n = Llength(nil, a) - 0x10;
        intptr_t i = TAG_FIXNUM;
        while (n > i)
        {   LispObject w = Laref2(nil, a, i);
            Laset(nil, 3, a, i, Laref2(nil, a, n));
            Laset(nil, 3, a, n, w);
            i += 0x10;
            n -= 0x10;
        }
        return onevalue(a);
    }
#endif
    while (consp(a))
    {   LispObject c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return onevalue(b);
}

LispObject Lnreverse2(LispObject nil, LispObject a, LispObject b)
{   while (consp(a))
    {   LispObject c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return onevalue(b);
}

#ifdef COMMON

//
// nreverse0 is like nreverse except that if its input is atomic it gets
// returned intact rather than being converted to nil.
//

LispObject Lnreverse0(LispObject nil, LispObject a)
{   LispObject b = nil;
    if (!consp(a)) return onevalue(a);
    b = a;
    a = qcdr(a);
    qcdr(b) = nil;
    while (consp(a))
    {   LispObject c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return onevalue(b);
}

#endif

LispObject Lreverse(LispObject nil, LispObject a)
{   LispObject r;
    stackcheck1(0, a);
    nil = C_nil;
    r = nil;
    while (consp(a))
    {   push(a);
        r = cons(qcar(a), r);
        pop(a);
        errexit();
        a = qcdr(a);
    }
    return onevalue(r);
}

#ifdef DEBUG_ASSOC
static int64_t assoc_calls = 0, assoc_length = 0, assoc_max = 0; //@@
#endif

LispObject Lassoc(LispObject nil, LispObject a, LispObject b)
{
#ifdef TRACED_EQUAL
    LispObject save_b = b;
    int pos = 0;
#endif
#ifdef DEBUG_ASSOC
    int64_t this_assoc = 0;
    if ((assoc_calls % 1000) == 999)
        term_printf("Assoc %.3f av length %.1f max %.1f calls\n",
                    (double)assoc_length/(double)assoc_calls,
                    (double)assoc_max,
                    (double)assoc_calls);
    assoc_calls++;
#endif
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   LispObject c = qcar(b);
#ifdef DEBUG_ASSOC
            assoc_length++;
            if (assoc_length > 100*assoc_calls) return aerror("average search for assoc");
            if (++this_assoc > assoc_max) assoc_max = this_assoc;
//!!        if (assoc_max > 1000) return aerror("length for assoc");
#endif
            if (consp(c) && a == qcar(c)) return onevalue(c);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
    while (consp(b))
    {   LispObject c = qcar(b);
        if (consp(c))
        {   LispObject cc = qcar(c);
#ifdef DEBUG_ASSOC
            assoc_length++;
            if (++this_assoc > assoc_max) assoc_max = this_assoc;
//!!        if (assoc_max > 1000) return aerror("length for assoc");
#endif
#ifdef COMMON
            if (cl_equal(a, cc)) return onevalue(c);
#else
            if (equal(a, cc))
            {
#ifdef TRACED_EQUAL
//
// In silly cases the length might not be a fixnum!
//
                trace_printf("Assoc true %3d %3d ", pos, int_of_fixnum(Llength(nil,save_b)));
                prin_to_stdout(a); trace_printf("\n");
#endif
                return onevalue(c);
            }
#endif
        }
        b = qcdr(b);
#ifdef TRACED_EQUAL
        pos++;
#endif
    }
#ifdef TRACED_EQUAL
// beware stupidly long lists...
    trace_printf("Assoc false  %3d %3d ", pos, int_of_fixnum(Llength(nil,save_b)));
    prin_to_stdout(a); trace_printf("\n");
#endif
    return onevalue(nil);
}

LispObject Latsoc(LispObject nil, LispObject a, LispObject b)
{
#ifdef COMMON
//
// See comments under atsoc...
//
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   LispObject c = qcar(b);
            if (consp(c) && a == qcar(c)) return onevalue(c);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
#endif
    while (consp(b))
    {   LispObject c = qcar(b);
//
// As for memq I unroll the loop a little...
// eql() can neither fail nor call the garbage collector, so I do
// not need to stack things here.
//
        if (consp(c) && eqcheck(a, qcar(c))) return onevalue(c);
        b = qcdr(b);
        if (!consp(b)) return onevalue(nil);
        c = qcar(b);
        if (consp(c) && eqcheck(a, qcar(c))) return onevalue(c);
        b = qcdr(b);
        if (!consp(b)) return onevalue(nil);
        c = qcar(b);
        if (consp(c) && eqcheck(a, qcar(c))) return onevalue(c);
        b = qcdr(b);
        if (!consp(b)) return onevalue(nil);
        c = qcar(b);
        if (consp(c) && eqcheck(a, qcar(c))) return onevalue(c);
        b = qcdr(b);
    }
    return onevalue(nil);
}

LispObject Lmember(LispObject nil, LispObject a, LispObject b)
{   if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == qcar(b)) return onevalue(b);
            b = qcdr(b);
            if (!consp(b)) return onevalue(nil);
            if (a == qcar(b)) return onevalue(b);
            b = qcdr(b);
            if (!consp(b)) return onevalue(nil);
            if (a == qcar(b)) return onevalue(b);
            b = qcdr(b);
            if (!consp(b)) return onevalue(nil);
            if (a == qcar(b)) return onevalue(b);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
    while (consp(b))
    {   LispObject cb = qcar(b);
#ifdef COMMON
        if (cl_equal(a, cb)) return onevalue(b);
#else
        if (equal(a, cb)) return onevalue(b);
#endif
        b = qcdr(b);
    }
    return onevalue(nil);
}

LispObject Lmemq(LispObject nil, LispObject a, LispObject b)
{
#ifdef COMMON
//
// I think it is possible that the test I need here is more along the
// lines of "is it a number that is not a fixnum" since EQL only
// diverges from EQ in that case... However I will not adjust this right
// now since I am not at present too concerned about Common Lisp mode...
//
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == qcar(b)) return onevalue(b);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
#endif
    while (consp(b))
    {
//
// I have unrolled this loop a bit because I found that in one of the
// Reduce tests it was a serious hot-spot.
//
        if (eqcheck(a, qcar(b))) return onevalue(b);
        b = qcdr(b);
        if (!consp(b)) return onevalue(nil);
        if (eqcheck(a, qcar(b))) return onevalue(b);
        b = qcdr(b);
        if (!consp(b)) return onevalue(nil);
        if (eqcheck(a, qcar(b))) return onevalue(b);
        b = qcdr(b);
        if (!consp(b)) return onevalue(nil);
        if (eqcheck(a, qcar(b))) return onevalue(b);
        b = qcdr(b);
    }
    return onevalue(nil);
}

static bool smemq(LispObject a, LispObject b)
{
//
// /* This is a bit worrying - it can use C recursion to arbitrary
// depth without any checking for overflow, and hence it can ESCAPE
// if (e.g.) given cyclic structures.  Some alteration is needed.  As
// things stand the code can never give wrong answers via GC rearrangement -
// the problem is closer to being that it can never call the GC.
//
#ifdef COMMON
    LispObject nil = C_nil;
#endif
    while (consp(b))
    {   LispObject w = qcar(b);
        if (w == quote_symbol) return false;
        else if (smemq(a, w)) return true;
        else b = qcdr(b);
    }
    return (a == b);
}

LispObject Lsmemq(LispObject nil, LispObject a, LispObject b)
{   bool r;
    r = smemq(a, b);
    errexit();
    return onevalue(Lispify_predicate(r));
}

//
//  (defun contained (x y)
//     (cond ((atom y) (equal x y))
//           ((equal x y) 't)
//           ('t (or (contained x (car y)) (contained x (cdr y))))))
//

static bool containedeq(LispObject nil, LispObject x, LispObject y)
{   while (consp(y))
    {   if (containedeq(nil, x, qcar(y))) return true;
        y = qcdr(y);
    }
    return (x == y);
}

static bool containedequal(LispObject nil, LispObject x, LispObject y)
{   while (consp(y))
    {   if (equal(x, y)) return true;
        if (containedequal(nil, x, qcar(y))) return true;
        y = qcdr(y);
    }
    return equal(x, y);
}

static LispObject Lcontained(LispObject nil, LispObject x, LispObject y)
{   bool r;
    if (is_symbol(x) || is_fixnum(x)) r = containedeq(nil, x, y);
    else r = containedequal(nil, x, y);
    errexit();
    return onevalue(Lispify_predicate(r));
}

LispObject Llast(LispObject nil, LispObject a)
{   LispObject b;
#ifndef COMMON
    (void)nil;
#endif
    if (!consp(a)) return aerror1("last", a);
    while (b = qcdr(a), consp(b)) a = b;
    return onevalue(qcar(a));
}

LispObject Llastpair(LispObject nil, LispObject a)
{   LispObject b;
#ifndef COMMON
    (void)nil;
#endif
    if (!consp(a)) return onevalue(a); // aerror1("lastpair", a);
    while (b = qcdr(a), consp(b)) a = b;
    return onevalue(a);
}

LispObject Llength(LispObject nil, LispObject a)
{
    if (a == nil) return onevalue(fixnum_of_int(0));
    if (is_cons(a))
    {   size_t n = 1;
//
// Possibly I should do something to trap cyclic lists.. But doing so
// would tend to be extra cost so unless it becomes a vital issue because
// of some bug I will not worry.
//
// I have unrolled the loop here 4 times since I expect length to be
// tolerably heavily used. Look at the assembly code generated for
// this to see if it was useful or counterproductive!
//
        for (;;)
        {   a = qcdr(a);
            if (!consp(a)) break;
            a = qcdr(a);
            if (!consp(a))
            {   n += 1;
                break;
            }
            a = qcdr(a);
            if (!consp(a))
            {   n += 2;
                break;
            }
            a = qcdr(a);
            if (!consp(a))
            {   n += 3;
                break;
            }
            n += 4;
        }
        a = make_lisp_unsigned64(n);
        errexit();
        return onevalue(a);
    }
//
// Common Lisp expects length to find the length of vectors
// as well as lists. I might as well do that in Standard Lisp mode
// too. Otherwise length of atoms (except NIL) lead to zero.
//
    else if (is_vector(a))
    {   Header h = vechdr(a);
        size_t n = length_of_header(h) - CELL;
// If at any stage I move to a segmented representation for huge vectors I
// will need to re-work this!
        if (type_of_header(h) == TYPE_ARRAY)
        {   LispObject dims = elt(a, 1);
            LispObject fillp = elt(a, 5);
            if (consp(dims) && !consp(qcdr(dims))) dims = qcar(dims);
            else return aerror1("length", a);  // Not one-dimensional
            if (is_fixnum(fillp)) dims = fillp;
            return onevalue(dims);
        }
        if (is_bitvec_header(h)) n = length_of_bitheader(h) - 8*CELL;
        else if (is_string_header(h)) n = length_of_byteheader(h) - CELL;
        else n = (length_of_header(h) - CELL)/CELL;
        a = make_lisp_unsigned64(n);
        errexit();
        return onevalue(a);
    }
    else return onevalue(fixnum_of_int(0));
}

#ifdef COMMON

LispObject Lappend_n(LispObject nil, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs == 0) return onevalue(nil);
    va_start(a, nargs);
    push_args(a, nargs);
//
// The actual args have been passed a C args - I can not afford to
// risk garbage collection until they have all been moved somewhere safe,
// and here that safe place is the Lisp stack.  I have to delay checking for
// overflow on same until all args have been pushed.
//
    stackcheck0(nargs);
    nil = C_nil;
    r = nil;
//
// rearrange order of items on the stack...
// The idea is that I will then reverse-copy the args in the order a1,
// a2 , ... to make a result list.  But I want to pop the stack as soon as
// I can, so I need arg1 on the TOP of the stack.
//
    for (i = 0; 2*i+1<nargs; i++)
    {   LispObject temp = stack[-i];
        stack[-i] = stack[i+1-nargs];
        stack[i+1-nargs] = temp;
    }
    for (i = 0; i<nargs; i++)
    {   LispObject w;
        pop(w);
        while (consp(w))
        {   push(w);
            nil = C_nil;
            if (!exception_pending()) r = cons(qcar(w), r);
            pop(w);
            w = qcdr(w);
        }
    }
    nil = C_nil;
    if (exception_pending()) return C_nil;
    return onevalue(nreverse(r));
}

LispObject Lappend_1(LispObject, LispObject a)
{   return onevalue(a);
}

#endif // COMMON

LispObject Lappend(LispObject nil, LispObject a, LispObject b)
{   LispObject r = nil;
    push(b);
    stackcheck2(1, a, r);
    while (consp(a))
    {   push(a);
        r = cons(qcar(a), r);
        pop(a);
        errexitn(1);
        a = qcdr(a);
    }
    pop(b);
    while (r != nil)
    {   a = qcdr(r);
        qcdr(r) = b;
        b = r;
        r = a;
    }
    return onevalue(b);
}

LispObject Ldelete(LispObject nil, LispObject a, LispObject b)
{   LispObject r;
    push2(a, b);
    r = nil;
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   LispObject q = qcar(b);
            if (q == stack[-1])
            {   b = qcdr(b);
                break;
            }
            stack[0] = qcdr(b);
            r = cons(qcar(b), r);
            errexitn(2);
            b = stack[0];
        }
    }
    else
    {   while (consp(b))
        {   LispObject q = qcar(b);
#ifdef COMMON
            if (cl_equal(q, a))
#else
            if (equal(q, a))
#endif
            {   b = qcdr(b);
                break;
            }
            stack[0] = qcdr(b);
            r = cons(qcar(b), r);
            errexitn(2);
            b = stack[0];
            a = stack[-1];
        }
    }
    popv(2);
    while (r != nil)
    {   LispObject w = qcdr(r);
        qcdr(r) = b;
        b = r;
        r = w;
    }
    return onevalue(b);
}


LispObject Ldeleq(LispObject nil, LispObject a, LispObject b)
{   LispObject r;
    push2(a, b);
    r = nil;
    while (consp(b))
    {   LispObject q = qcar(b);
        if (q == stack[-1])
        {   b = qcdr(b);
            break;
        }
        stack[0] = qcdr(b);
        r = cons(qcar(b), r);
        errexitn(2);
        b = stack[0];
    }
    popv(2);
    while (r != nil)
    {   LispObject w = qcdr(r);
        qcdr(r) = b;
        b = r;
        r = w;
    }
    return onevalue(b);
}

LispObject Lnconc(LispObject nil, LispObject a, LispObject b)
{   LispObject c;
#ifndef COMMON
    (void)nil;
#endif
    if (!consp(a)) return onevalue(b);
    c = a;
    for (;;)
    {   LispObject next = qcdr(c);
        if (!consp(next))
        {   qcdr(c) = b;
            return onevalue(a);
        }
        else c = next;
    }
}

//
// All the comments that follow are the signature of me needing to think
// carefully while implementing a version of the code here that will
// not recurse in the CDR direction.
//
// subst(a, b, c)
//   if b = c then a
//   else if atom c then c
//   else subst(a, b, car c) . subst(a, b, cdr c);
//
// Now the logic of a version that iterates along the list...
//
//
//  orig                                      R             C
//   |                                        |             |
//   V                                        V             V
//  ---------    ---------    ---------     ---------     ---------
//  | X1|   +--->| X2|   +--->|X' | / |     |X' | : |     | Z |   +--->
//  =========    =========    =========     ======+==     =========
//                              ^                 |
//                              L-----------------J
//
//
//                    RX
//                     |
//                     V
//     ---------     ---------
//     | Y1| / |     | Y2| : |
//     ---------     ------+--
//       ^                 |
//       L-----------------J
//
//
// The original list C started at orig, and the cells X contain their original
// content there, while the result of substitution on them gives the values Y
// shown in the list accessed via RX.
//
// The reversed section of the original list from R back has values where
// substitution leaves them unaltered, so they are suitable for inclusion
// in the result. The reversed chains ends in cells marked "/" in the
// diagram - that can be any non-pair. I will use the fixnum zero. You might
// have expected me to use nil, but I will not because the nil variable is
// used at times to hold an error flag. The reversed chain at RX contains
// data that has needed to be copied, and so Y2 NEQ X2.
//
// The fragment of the original starting from C contains original data (Z) that
// has not yet been inspected.
//
// There is a procedure referred to here as "normalising"  that restores the
// pointers from R backwars to be forward pointers, and as it does so correspoding
// new items are placed on the RX list. It leaves R=nil.
//
//  orig                                          R:0       C
//   |                                                      |
//   V                                                      V
//  ---------    ---------    ---------     ---------     ---------
//  | X |   +--->| X |   +--->| X |   +---->| X |   +---->| Z |   +--->
//  =========    =========    =========     =========     =========
//
//                                                 RX
//                                                  |
//                                                  V
//     ---------     ---------      ---------     ---------
//     | Y | / |     | Y | : |      | Y | : |     | Y | : |
//     ---------     ------+--      ------+--     ------+--
//       ^            ^    |          ^   |             |
//       |            |    |          |   |             |
//       L------------+----J          L---+-------------J
//                    |                   |
//                    L-------------------J
//
// There is a futher procedure known here as "unwinding" that can be
// performed after normalisation. It takes a value in C and reverses
// pointers back from R (thereby restoring the original list). It then
// reverses the RX list onto the front to deliver a final result.
//
// The very initial situation is
//
//   C       RX:0  R:0
//   |
//   V
//  ---------
//  | X |   +--->
//  =========
//
//
// Each step first checks if C as a whole is to be replaced.
//     "if b = c then a"
// from the first line of the simple version. If so and if a!=c then
// you normalise, set c=a then unwind.
//
// If the above substitution occurs but a=c or if c is atomic
// just unwind.
//
// Now c is non-atomic. Recurse to process car(c). If this
// is unchanged then extent the reversed list ar R. This may need
// special care when the list is empty to start with.
//
// If the substitution on car c proceed something that differeed
// then normalise and push the new result onto rx.
//
//


//
// The above treatment is required for four functions
//     subst, substq
//     sublis, subla
//


static LispObject substq(LispObject a, LispObject b, LispObject c)
{   LispObject nil = C_nil, w;
    stackcheck3(0, a, b, c);
    push2(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push3(a, b, c);
#define c   stack[0]
#define b   stack[-1]
#define a   stack[-2]
#define r   stack[-3]
#define rx  stack[-4]
    for (;;)
    {   if (c == b)
        {   if (c == a) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = w;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   w = cons(qcar(r), rx);
                errexitn(5);
                rx = w;
                r = qcdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
        if (!consp(c)) break;
// Recurse in CAR direction
        w = substq(a, b, qcar(c));
// If the recursive call fails I need to unshare before exit - so I
// put in a hand-crafted test that arranges that.
        nil = C_nil;
        if (exception_pending())
        {   while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = c;
                c = r;
                r = w;
            }
            return nil;
        }
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        else if (w == qcar(c))
        {   w = qcdr(c);
            qcdr(c) = r;
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = qcar(r), v = rx;
                push(w);
                ww = cons(u, v);
                errexitn(6);
                pop(w);
                rx = ww;
                r = qcdr(r);
            }
            w = cons(w, rx);
            errexitn(5);
            rx = w;
            c = qcdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef b
#undef a
#undef r
#undef rx
    pop3(c, b, a);
    {   LispObject r, rx;
        pop2(r, rx);
        while (r != TAG_FIXNUM)
        {   w = qcdr(r);
            qcdr(r) = c;
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        if (exception_pending()) return nil;
        while (rx != TAG_FIXNUM)
        {   w = qcdr(rx);
            qcdr(rx) = c;
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}



LispObject subst(LispObject a, LispObject b, LispObject c)
{   LispObject nil = C_nil, w;
    stackcheck3(0, a, b, c);
    push2(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push3(a, b, c);
#define c   stack[0]
#define b   stack[-1]
#define a   stack[-2]
#define r   stack[-3]
#define rx  stack[-4]
    for (;;)
    {
#ifdef COMMON
        if (cl_equal(c, b))
#else
        if (equal(c, b))
#endif
        {
// if EQUAL said "yes" then it can not have failed.
            if (c == a) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = w;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   w = cons(qcar(r), rx);
                errexitn(5);
                rx = w;
                r = qcdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
// equal may fail with a stack overflow, and if it does it will return
// false (and set the exception marker). In that case I must recover and
// undo any damage I have done to input lists.
        nil = C_nil;
        if (exception_pending() || !consp(c)) break;
// Recurse in CAR direction
        w = subst(a, b, qcar(c));
// If the recursive call fails I need to unshare before exit - so I
// put in a hand-crafted test that arranges that.
        nil = C_nil;
        if (exception_pending())
        {   while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = c;
                c = r;
                r = w;
            }
            return nil;
        }
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        else if (w == qcar(c))
        {   w = qcdr(c);
            qcdr(c) = r;
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = qcar(r), v = rx;
                push(w);
                ww = cons(u, v);
                errexitn(6);
                pop(w);
                rx = ww;
                r = qcdr(r);
            }
            w = cons(w, rx);
            errexitn(5);
            rx = w;
            c = qcdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef b
#undef a
#undef r
#undef rx
    pop3(c, b, a);
    {   LispObject r, rx;
        pop2(r, rx);
        while (r != TAG_FIXNUM)
        {   w = qcdr(r);
            qcdr(r) = c;
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        if (exception_pending()) return nil;
        while (rx != TAG_FIXNUM)
        {   w = qcdr(rx);
            qcdr(rx) = c;
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}


LispObject subla(LispObject a, LispObject c)
{   LispObject nil = C_nil, w;
    stackcheck2(0, a, c);
    push2(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push2(a, c);
#define c   stack[0]
#define a   stack[-1]
#define r   stack[-2]
#define rx  stack[-3]
    for (;;)
    {   LispObject tt = a;
        bool found = false;
        while (consp(tt))
        {   LispObject tta = qcar(tt);
            if (consp(tta) && c == qcar(tta))
            {   tt = qcdr(tta);
                found = true;
                break;
            }
            tt = qcdr(tt);
        }
        if (found)
        {   if (c == tt) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = w;
            }
// The input data is now restored
            a = tt;
            r = cc;
            while (r != c)
            {   w = cons(qcar(r), rx);
                errexitn(4);
                rx = w;
                r = qcdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
        if (!consp(c)) break;
// Recurse in CAR direction
        w = subla(a, qcar(c));
// If the recursive call fails I need to unshare before exit - so I
// put in a hand-crafted test that arranges that.
        nil = C_nil;
        if (exception_pending())
        {   while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = c;
                c = r;
                r = w;
            }
            return nil;
        }
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        else if (w == qcar(c))
        {   w = qcdr(c);
            qcdr(c) = r;
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = qcar(r), v = rx;
                push(w);
                ww = cons(u, v);
                errexitn(5);
                pop(w);
                rx = ww;
                r = qcdr(r);
            }
            w = cons(w, rx);
            errexitn(4);
            rx = w;
            c = qcdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef a
#undef r
#undef rx
    pop2(c, a);
    {   LispObject r, rx;
        pop2(r, rx);
        while (r != TAG_FIXNUM)
        {   w = qcdr(r);
            qcdr(r) = c;
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        if (exception_pending()) return nil;
        while (rx != TAG_FIXNUM)
        {   w = qcdr(rx);
            qcdr(rx) = c;
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}


LispObject sublis(LispObject a, LispObject c)
{   LispObject nil = C_nil, w;
    stackcheck2(0, a, c);
    push2(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push2(a, c);
#define c   stack[0]
#define a   stack[-1]
#define r   stack[-2]
#define rx  stack[-3]
    for (;;)
    {   LispObject tt = a;
        bool found = false;
        while (consp(tt))
        {   LispObject tta = qcar(tt);
#ifdef COMMON
            if (consp(tta) && cl_equal(c, qcar(tta)))
#else
            if (consp(tta) && equal(c, qcar(tta)))
#endif
            {   tt = qcdr(tta);
                found = true;
                break;
            }
            nil = C_nil;
            if (exception_pending()) break;
            tt = qcdr(tt);
        }
        if (found)
        {
// if EQUAL had said "yes" then it can not have failed.
            if (c == tt) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = w;
            }
// The input data is now restored
            a = tt;
            r = cc;
            while (r != c)
            {   w = cons(qcar(r), rx);
                errexitn(4);
                rx = w;
                r = qcdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
// equal may fail with a stack overflow, and if it does it will return
// false (and set the exception marker). In that case I must recover and
// undo any damage I have done to input lists.
        nil = C_nil;
        if (exception_pending() || !consp(c)) break;
// Recurse in CAR direction
        w = sublis(a, qcar(c));
// If the recursive call fails I need to unshare before exit - so I
// put in a hand-crafted test that arranges that.
        nil = C_nil;
        if (exception_pending())
        {   while (r != TAG_FIXNUM)
            {   w = qcdr(r);
                qcdr(r) = c;
                c = r;
                r = w;
            }
            return nil;
        }
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        else if (w == qcar(c))
        {   w = qcdr(c);
            qcdr(c) = r;
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = qcdr(r);
                qcdr(r) = cc;
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = qcar(r), v = rx;
                push(w);
                ww = cons(u, v);
                errexitn(5);
                pop(w);
                rx = ww;
                r = qcdr(r);
            }
            w = cons(w, rx);
            errexitn(4);
            rx = w;
            c = qcdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef a
#undef r
#undef rx
    pop2(c, a);
    {   LispObject r, rx;
        pop2(r, rx);
        while (r != TAG_FIXNUM)
        {   w = qcdr(r);
            qcdr(r) = c;
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        if (exception_pending()) return nil;
        while (rx != TAG_FIXNUM)
        {   w = qcdr(rx);
            qcdr(rx) = c;
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}



LispObject Lsubstq(LispObject nil, int nargs, ...)
{   LispObject a, b, c;
    va_list aa;
    argcheck(nargs, 3, "substq");
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        return aerror("subst");
    }
#endif
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    return substq(a, b, c);
}

LispObject Lsubst(LispObject nil, int nargs, ...)
{   LispObject a, b, c;
    va_list aa;
    argcheck(nargs, 3, "subst");
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        return aerror("subst");
    }
#endif
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    if (c == b) return onevalue(a);
    else if (is_symbol(b) || is_fixnum(b)) return substq(a, b, c);
    else return subst(a, b, c);
}

LispObject Lsublis(LispObject nil, LispObject al, LispObject x)
{   stackcheck2(0, al, x);
    errexit();
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        return aerror("sublis");
    }
#endif
    if (!consp(al)) return onevalue(x);
    else return sublis(al, x);
}


LispObject Lsubla(LispObject nil, LispObject al, LispObject x)
//
// as sublis, but uses eq test rather than equal
//
{   stackcheck2(0, al, x);
    errexit();
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        return aerror("subla");
    }
#endif
    if (!consp(al)) return onevalue(x);
    else return subla(al, x);
}


setup_type const funcs2_setup[] =
{   {"assoc",                   too_few_2, Lassoc, wrong_no_2},
//
// assoc** is expected to remain as the Standard Lisp version even if in
// a Common Lisp world I redefine assoc to be something messier. xassoc was
// an earlier name I used for the same purpose, and is being withdrawn.
//
    {"assoc**",                 too_few_2, Lassoc, wrong_no_2},
    {"xassoc",                  too_few_2, Lassoc, wrong_no_2},
    {"atsoc",                   too_few_2, Latsoc, wrong_no_2},
    {"member",                  too_few_2, Lmember, wrong_no_2},
    {"member**",                too_few_2, Lmember, wrong_no_2},
    {"memq",                    too_few_2, Lmemq, wrong_no_2},
    {"contained",               too_few_2, Lcontained, wrong_no_2},
//
// I originally called this restart!-csl but I am now changing the name
// to be restart!-lisp to be a little less specific about exactly which
// implementation of Lisp is involved. IN the fullness of time I will
// remove the name restart!-csl...
//
    {"restart-lisp",            Lrestart_lisp, Lrestart_lisp2, wrong_no_1},
    {"restart-csl",             Lrestart_lisp, Lrestart_lisp2, wrong_no_1},
    {"eq",                      too_few_2, Leq, wrong_no_2},
    {"iequal",                  too_few_2, Leq, wrong_no_2},
    {"eqcar",                   too_few_2, Leqcar, wrong_no_2},
    {"equalcar",                too_few_2, Lequalcar, wrong_no_2},
    {"eql",                     too_few_2, Leql, wrong_no_2},
    {"equalp",                  too_few_2, Lequalp, wrong_no_2},
    {"endp",                    Lendp, too_many_1, wrong_no_1},
    {"getd",                    Lgetd, too_many_1, wrong_no_1},
    {"last",                    Llast, too_many_1, wrong_no_1},
    {"lastpair",                Llastpair, too_many_1, wrong_no_1},
    {"length",                  Llength, too_many_1, wrong_no_1},
    {"make-bps",                Lget_bps, too_many_1, wrong_no_1},
    {"symbol-env",              Lsymbol_env, too_many_1, wrong_no_1},
    {"symbol-make-fastget",     Lsymbol_make_fastget1, Lsymbol_make_fastget, wrong_no_2},
    {"symbol-fastgets",         Lsymbol_fastgets, too_many_1, wrong_no_1},
    {"object-header",           Lobject_header, too_many_1, wrong_no_1},
    {"symbol-fn-cell",          Lsymbol_fn_cell, too_many_1, wrong_no_1},
    {"symbol-argcode",          Lsymbol_argcount, too_many_1, wrong_no_1},
    {"symbol-restore-fns",      Lsymbol_restore_fns, too_many_1, wrong_no_1},
    {"symbol-argcount",         Lsymbol_argcount, too_many_1, wrong_no_1},
    {"symbol-set-env",          too_few_2, Lsymbol_set_env, wrong_no_2},
#ifdef REINSTATE_NATIVE_CODE_EXPERIMENT
    {"make-native",             Lget_native, too_many_1, wrong_no_1},
    {"symbol-set-native",       wrong_no_na, wrong_no_nb, Lsymbol_set_native},
#endif
    {"symbol-set-definition",   too_few_2, Lsymbol_set_definition, wrong_no_2},
    {"restore-c-code",          Lrestore_c_code, too_many_1, wrong_no_1},
    {"set-autoload",            too_few_2, Lset_autoload, wrong_no_2},
    {"remd",                    Lremd, too_many_1, wrong_no_1},
    {"trace",                   Ltrace, too_many_1, wrong_no_1},
    {"traceset",                Ltraceset, too_many_1, wrong_no_1},
#ifdef JIT
    {"jit",                     Ljit, too_many_1, wrong_no_1},
#endif
    {"untrace",                 Luntrace, too_many_1, wrong_no_1},
// Note that untraceset is exactly the same as untrace
    {"untraceset",              Luntrace, too_many_1, wrong_no_1},
    {"trace-all",               Ltrace_all, too_many_1, wrong_no_1},
    {"double-execute",          Ldouble, too_many_1, wrong_no_1},
    {"undouble-execute",        Lundouble, too_many_1, wrong_no_1},
    {"macro-function",          Lmacro_function, too_many_1, wrong_no_1},
    {"symbol-name",             Lsymbol_name, too_many_1, wrong_no_1},
    {"id2string",               Lsymbol_name, too_many_1, wrong_no_1},
    {"plist",                   Lplist, too_many_1, wrong_no_1},
    {"prop",                    Lplist, too_many_1, wrong_no_1},
    {"delete",                  too_few_2, Ldelete, wrong_no_2},
    {"deleq",                   too_few_2, Ldeleq, wrong_no_2},
    {"preserve",                Lpreserve_1, Lpreserve_2, Lpreserve_03},
    {"mkvect",                  Lmkvect, too_many_1, wrong_no_1},
    {"nconc",                   too_few_2, Lnconc, wrong_no_2},
    {"neq",                     too_few_2, Lneq, wrong_no_2},
    {"not",                     Lnull, too_many_1, wrong_no_1},
    {"null",                    Lnull, too_many_1, wrong_no_1},
    {"resource-exceeded",       wrong_no_0a, wrong_no_0b, Lresource_exceeded},
    {"reverse",                 Lreverse, too_many_1, wrong_no_1},
    {"reversip",                Lnreverse, Lnreverse2, wrong_no_1},
// I make the name nreverse generally available as well as reversip
    {"nreverse",                Lnreverse, Lnreverse2, wrong_no_1},
// also reversip2 for the 2-arg varient
    {"reversip2",               too_few_2, Lnreverse2, wrong_no_1},
    {"smemq",                   too_few_2, Lsmemq, wrong_no_2},
    {"subla",                   too_few_2, Lsubla, wrong_no_2},
    {"sublis",                  too_few_2, Lsublis, wrong_no_2},
    {"subst",                   wrong_no_3a, wrong_no_3b, Lsubst},
    {"substq",                  wrong_no_3a, wrong_no_3b, Lsubstq},
    {"symbol-protect",          too_few_2, Lsymbol_protect, wrong_no_2},
#ifdef COMMON
    {"symbol-plist",            Lplist, too_many_1, wrong_no_1},
    {"append",                  Lappend_1, Lappend, Lappend_n},
//
// In Common Lisp mode I make EQUAL do what Common Lisp says it should, but
// also have EQUALS that is much the same but which also descends vectors.
//
    {"equal",                   too_few_2, Lcl_equal, wrong_no_2},
    {"equals",                  too_few_2, Lequal, wrong_no_2},
    {"nreverse0",               Lnreverse0, too_many_1, wrong_no_1},
#else
    {"append",                  too_few_2, Lappend, wrong_no_2},
// In Standard Lisp mode EQUAL descends vectors (but does not case fold)
// I provide cl-equal to do what Common Lisp does.
    {"cl-equal",                too_few_2, Lcl_equal, wrong_no_2},
    {"equal",                   too_few_2, Lequal, wrong_no_2},
    {"member",                  too_few_2, Lmember, wrong_no_2},
#endif
    {"symbol-package",          Lsymbol_package, too_many_1, wrong_no_1},
    {"serialize",               Lserialize, too_many_1, wrong_no_1},
    {"full-serialize",          Lserialize1, too_many_1, wrong_no_1},
    {"unserialize",             wrong_no_0a, wrong_no_0b, Lunserialize},
    {NULL,                      0, 0, 0}
};

// end of fns2.cpp
