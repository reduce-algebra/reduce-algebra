/*  fns2.c                          Copyright (C) 1989-2008 Codemist Ltd */

/*
 * Basic functions part 2.
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 5db20543 17-Dec-2008 */

#include "headers.h"


#ifdef COMMON
#include "clsyms.h"
#endif

#ifdef SOCKETS
#include "sockhdr.h"
#endif

Lisp_Object getcodevector(int type, int32_t size)
{
/*
 * type is the code (e.g. TYPE_BPS) that gets packed, together with
 * the size, into a header word.
 * size is measured in bytes and must allow space for the header word.
 * This obtains space in the BPS area
 */
    Lisp_Object nil = C_nil;
#ifdef CHECK_FOR_CORRUPT_HEAP
    validate_all();
#endif
    for (;;)
    {   int32_t alloc_size = (int32_t)doubleword_align_up(size);
        char *cf = (char *)codefringe, *cl = (char *)codelimit;
        int32_t free = cf - cl;
        char *r;
        if (alloc_size > free)
        {   char msg[40];
            sprintf(msg, "codevector %ld", (long)size);
            reclaim(nil, msg, GC_BPS, alloc_size);
            errexit();
            continue;
        }
        r = cf - alloc_size;
        codefringe = (Lisp_Object)r;
        *((Header *)r) = type + (size << 10) + TAG_ODDS;
/*
 * codelimit is always 8 bytes above the base of the code-page. The
 * address I need to return for a code-vector points (in a packed way)
 * to the first byte of actual byte data, ie CELL bytes above the start
 * of the data-structure. Oh joy!
 */
        return TAG_BPS +
           (((int32_t)((r + CELL) - (cl - 8)) & (PAGE_POWER_OF_TWO-4)) << 6) +
           (((int32_t)(bps_pages_count-1))<<(PAGE_BITS+6)); /* Wow! Obscure!! */
    }
}

Lisp_Object Lget_bps(Lisp_Object nil, Lisp_Object n)
{
    int32_t n1;
    if (!is_fixnum(n) || (int32_t)n<0) return aerror1("get-bps", n);
    n1 = int_of_fixnum(n);
    n = getcodevector(TYPE_BPS, n1+CELL);
    errexit();
    return onevalue(n);
}

/*/*
 * WARNING. This code is intended to allocate space into which I will post
 * executable code. Under a really old-fashioned "spirit of C" even though
 * grabbing space with malloc and re-using it this way was officially not
 * guaranteed one could typically expect to get away with it. Well apart
 * on Harvard-architecture machines where code and data addresses are quite
 * distinct. But more recently - I have become aware of it hitting wide
 * distribution in Fedora Core in late 2003 - security concerns have prompted
 * some major vendors to move to a model where malloc space is explicitly
 * locked down as non-executable. In such cases, which may become increasingly
 * common, it will be VITAL to adjust what lies behind this to perform
 * system calls to arrange that pages that will be used for native code are
 * tagged as executable. Maybe it is just as well that at present this is
 * an experimental extension to CSL and is not ready for general use anyway!
 */

Lisp_Object get_native_code_vector(int32_t size)
{
/*
 * Create some space for native code and return a handle that identifies
 * its start point. size is measured in bytes.
 */
    Lisp_Object nil = C_nil;
    if (size <= 0) size = 8;
    for (;;)
    {   int32_t alloc_size = (intptr_t)doubleword_align_up(size);
        intptr_t cf = native_fringe;
        intptr_t free = CSL_PAGE_SIZE - cf - 0x100; /* 256 bytes to be safe */
/*
 * When I start up a cold CSL I will have native_fringe set to zero and
 * native_pages_count also zero, indicating that there is none of this stuff
 * active.
 */
        if (native_fringe == 0 || alloc_size > free)
        {   char msg[40];
            sprintf(msg, "native code %ld", (long)size);
            reclaim(nil, msg, GC_NATIVE, alloc_size);
            errexit();
            continue;
        }
        free = (intptr_t)native_pages[native_pages_count-1];
        free = doubleword_align_up(free);
/*
 * I put the number of bytes in this block as the first word of the chunk
 * of memory, and arrange that there is a zero in what would be the first
 * word of unused space. Provided the user does not clobber bytes 0 to 4
 * or the block this is enough to allow restart code to scan through all
 * native code segments.
 */
        car32(free+native_fringe) = alloc_size;
        car32(free+native_fringe+alloc_size) = 0;
        native_fringe += alloc_size;
        native_pages_changed = 1;
        return Lcons(nil,
                     fixnum_of_int(native_pages_count-1),
                     fixnum_of_int(cf));
    }
}

Lisp_Object Lget_native(Lisp_Object nil, Lisp_Object n)
{
    int32_t n1;
    if (!is_fixnum(n) || (int32_t)n<0) return aerror1("get-native", n);
    n1 = int_of_fixnum(n);
    n = get_native_code_vector(n1);
    errexit();
    return onevalue(n);
}

int do_not_kill_native_code = 0;

void set_fns(Lisp_Object a, one_args *f1, two_args *f2, n_args *fn)
{
    Lisp_Object nil = C_nil;
    Lisp_Object w1, w2, w3 = nil;
/*
 * If I redefine a function for any reason (except to set trace options
 * on a bytecoded definition) I will discard any native-coded definitions
 * by splicing them out of the record. I provide a global variable to
 * defeat this behaviour (ugh).
 */
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

static CSLbool interpreter_entry(Lisp_Object a)
/*
 * If a function will be handled by the interpreter, including the case
 * of it being undefined, then the fn1() cell will tell me so.
 */
{
    return (
        qfn1(a) == interpreted1 ||
        qfn1(a) == traceinterpreted1 ||
        qfn1(a) == double_interpreted1 ||
        qfn1(a) == funarged1 ||
        qfn1(a) == tracefunarged1 ||
        qfn1(a) == double_funarged1 ||
        qfn1(a) == undefined1);
}

#endif

static char *show_fn1(one_args *p)
{
    int i;
    for (i=0; entries_table1[i].s!=NULL; i++)
        if (entries_table1[i].p == p) return entries_table1[i].s;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static char *show_fn2(two_args *p)
{
    int i;
    for (i=0; entries_table2[i].s!=NULL; i++)
        if (entries_table2[i].p == p) return entries_table2[i].s;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static char *show_fnn(n_args *p)
{
    int i;
    for (i=0; entries_tablen[i].s!=NULL; i++)
        if (entries_tablen[i].p == p) return entries_tablen[i].s;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

Lisp_Object Lsymbol_fn_cell(Lisp_Object nil, Lisp_Object a)
/*
 * For debugging...
 */
{
    char *s1, *s2, *sn;
    if (!symbolp(a)) return onevalue(nil);
    s1 = show_fn1(qfn1(a));
    s2 = show_fn2(qfn2(a));
    sn = show_fnn(qfnn(a));
    trace_printf("%s %s %s\n", s1, s2, sn);
    return onevalue(nil);
}

Lisp_Object Lsymbol_argcount(Lisp_Object nil, Lisp_Object a)
/*
 * For debugging and JIT compiler use. Only valid if the function involved
 * is byte-coded. For simple functions taking a fixed number of args the
 * result is an integer. Otherwise it is a list of 3 items
 *   (fewest-legal-args most-args-before-&rest flags)
 * where the flags has a 1 bit if missing &optional args are to be left
 * for the bytecoded stuff to unpick, otherwise they should be mapped to nil
 * somewhere. The 2 bit is present if a &rest argument is present.
 */
{
    one_args *f1;
    two_args *f2;
    n_args *fn;
    int low, high, hardrest;
    Lisp_Object r;
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
    low = b[0];          /* smallest number of valid args                */
    high = low + b[1];   /* largest number before &rest is accounted for */
    hardrest = 0;
/*
 * byteopt - optional arguments, with default of NIL
 */
    if (f1 == byteopt1 ||
        f1 == tracebyteopt1) hardrest = 0;
/*
 * hardopt - optional arguments but default is passed as a SPID so that
 * the user can follow up and apply cleverer default processing
 */
    else if (f1 == hardopt1 ||
        f1 == tracehardopt1) hardrest = 1;
/*
 * byteoptrest - anything with a &rest argument on the end.
 */
    else if (f1 == byteoptrest1 ||
        f1 == tracebyteoptrest1) hardrest = 1;
/*
 * hardoptrest - some &optional args with non-nil default value, plus &rest
 */
    else if (f1 == hardoptrest1 ||
        f1 == tracehardoptrest1) hardrest = 3;
    else return onevalue(nil);
    r = list3(fixnum_of_int(low),
              fixnum_of_int(high), fixnum_of_int(hardrest));
    errexit();
    return onevalue(r);
}

Lisp_Object Lsymbol_argcode(Lisp_Object nil, Lisp_Object a)
/*
 * This hands back a single integer that encodes what must be in the
 * three function cells for anything byte-coded.
 * Or nil if the argument did not name a bytecoded function.
 */
{
#define BYTE_ARGMASK 0x007    /* 0, 1, 2, 3 or 4. 4 means "4 or more" */
#define BYTE_OPT     0x008    /* &optional present */
#define BYTE_HARDOPT 0x010    /* "hard" case of &optional */
#define BYTE_REST    0x020    /* &rest present */
#define BYTE_TRACED  0x040
#define BYTE_DOUBLED 0x080
#define BYTE_CALLAS  0x100    /* link to some other function */
/*
 * I can not see any way much better than a grim sequence of explicit
 * tests to achieve what I want here.
 */
    one_args *f1;
    two_args *f2;
    n_args *fn;
    Lisp_Object r;
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
/*
 * I observe that I do not support double-execute for &optional and &rest
 * functions. I do not mind that too much!
 */
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
/* The next two intrude on the BYTE_OPT bit-position... */
    else if (f1 == f1_as_0) val = BYTE_CALLAS + 8;
    else if (f1 == f1_as_1) val = BYTE_CALLAS + 9;
    else return onevalue(nil);
    return onevalue(fixnum_of_int(val));
}

/*
 * The job of this function is to put back information as retrieved by
 * symbol-argcode. It is used in part of the support for native compilation
 * via C code... Note that it doe snot interact with any JIT stuff since the
 * two compilation strategies are complementary and I do not expect that I
 * will every use both at once.
 */

Lisp_Object Lsymbol_restore_fns(Lisp_Object nil, Lisp_Object name)
{
    int r;
    Lisp_Object n, env;
/*
 * This expects a property that has value <argcode> . <env>
 */
    if (!is_symbol(name)) return onevalue(nil);
    n = get(name, bytecoded_symbol);
    if (!consp(n)) return onevalue(nil);
    env = qcdr(n);
    n = qcar(n);
    if (!is_fixnum(n)) return onevalue(nil);
/*
 * When I first implemented this I thought I might remove the bytecode
 * definition from the property list. However I *hope* that soon I will be
 * re-instating the native defintion, which would lead to a need to put this
 * stuff back. So I think I will just leave it here and avoid the sweat
 * of re-instating it during system restart. This may lead to heap images
 * being a little larger but I propose not to fuss about that and further
 * I hope that structures will be shared and mean that any overhead is
 * small.
 *
 *  Lremprop(nil, name, bytecoded_symbol);
 */
    r = int_of_fixnum(n);
    switch (r)
    {
case 1:
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

Lisp_Object Lsymbol_env(Lisp_Object nil, Lisp_Object a)
/*
 * Not Common Lisp - read the 'environment' cell associated with a
 * symbol.  This cell is deemed empty unless the symbol-function is
 * compiled code.  For use mainly for debugging.
 */
{
    if (!symbolp(a)) return onevalue(nil);
#ifdef HIDE_USELESS_SYMBOL_ENVIRONMENTS
    else if ((qheader(a) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0 ||
        interpreter_entry(a)) return onevalue(nil);
#endif
    return onevalue(qenv(a));
}

Lisp_Object Lsymbol_set_env(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_symbol(a)) return aerror1("symbol-set-env", a);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    qenv(a) = b;
    return onevalue(b);
}

Lisp_Object Lsymbol_fastgets(Lisp_Object nil, Lisp_Object a)
{
    if (!symbolp(a)) return onevalue(nil);
    return onevalue(qfastgets(a));
}

/*
 * (protect 'name t) arranges that the function indicated (which is
 * expected to have been defined in the C kernel) can not be redefined.
 * (protect 'name nil) restores the usual state of affairs.
 */

Lisp_Object Lsymbol_protect(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Header h;
    if (!is_symbol(a)) return onevalue(nil);
    h = qheader(a);
    if (b == nil) qheader(a) = h & ~(SYM_CODEPTR | SYM_C_DEF);
    else qheader(a) = h | SYM_CODEPTR | SYM_C_DEF;
    h &= (SYM_CODEPTR | SYM_C_DEF);
    return onevalue(Lispify_predicate(h == (SYM_CODEPTR | SYM_C_DEF)));
}

/*
 * (symbol-make-fastget 'xxx nil)   returns current information, nil if no
 *                                  fastget usage set.
 * (symbol-make-fastget 'xxx n)     sets it to n (0 <= n < 63)
 * (symbol-make-fastget 'xxx -1)    sets the option off
 * (symbol-make-fastget n)          specify fast-get range (n <= 63)
 */

Lisp_Object Lsymbol_make_fastget1(Lisp_Object nil, Lisp_Object a)
{
    int32_t n, n1 = fastget_size;
    CSL_IGNORE(nil);
    if (!is_fixnum(a) ||
        (n = int_of_fixnum(a)) < 0 ||
        (n > MAX_FASTGET_SIZE)) return aerror1("symbol-make-fastget", a);
    term_printf("+++ Fastget size was %d, now %d\n", n1, n);
    fastget_size = n;
    return onevalue(fixnum_of_int(n1));
}

Lisp_Object Lsymbol_make_fastget(Lisp_Object nil, Lisp_Object a, Lisp_Object n)
{
    int32_t n1, p, q;
    Header h;
    if (!symbolp(a)) return onevalue(nil);
    h = qheader(a);
    p = header_fastget(h);
    if (is_fixnum(n))
    {   n1 = int_of_fixnum(n);
        if (n1 < -1 || n1 >= fastget_size)
            return aerror1("symbol-make-fastget", n);
        trace_printf("+++ Use fastget slot %d for ", n1);
        loop_print_trace(a);
        errexit();
        trace_printf("\n");
        if (p != 0) elt(fastget_names, p-1) = SPID_NOPROP;
        q = (n1 + 1) & 0x3f;
        h = (h & ~SYM_FASTGET_MASK) | (q << SYM_FASTGET_SHIFT);
        qheader(a) = h;
        if (q != 0) elt(fastget_names, q-1) = a;
    }
    if (p == 0) return onevalue(nil);
    else return onevalue(fixnum_of_int(p - 1));
}

static Lisp_Object deleqip(Lisp_Object a, Lisp_Object l)
/*
 * This deletes the item a (tested for using EQ) from the list l,
 * assuming that the list is nil-terminated and that the item a
 * occurs at most once. It overwrites the list l in the process.
 */
{
    Lisp_Object nil = C_nil, w, r;
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

void lose_C_def(Lisp_Object a)
{
/*
 * None of the code here can cause garbage collection.
 */
#ifdef COMMON
    Lisp_Object nil = C_nil;
    Lisp_Object b = get(a, unset_var, nil), c;
#else
    nil_as_base
    Lisp_Object b = get(a, unset_var), c;
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

/*
 * (symbol-set-native fn args bpsbase offset env)
 * where bpsbase is as handed back by (make-native nnn) and offset is
 * the offset in this block to enter at.
 * If args has the actual arg count in its bottom byte. Usually the
 * rest of it will be zero, and then one function cell is set to point to the
 * given entrypoint and the other two are set to point at error handlers.
 * If any bits in args beyond that are set then this call only changes the
 * directly specified function cell, and the others are left in whatever state
 * they were. If several of the fuction cells are to be filled in (eg to cope
 * with &optional or &rest arguments) then a simple call with args<256 must
 * be made first, followed by the calls (args>=256) that fill in the other
 * two cells.
 * The first time that symbol-set-native is called on a function that
 * function MUST have a byte coded definition, and this definition is
 * picked up and stored away, so that if (preserve) is called the bytecoded
 * definition will be available for use on systems with different
 * architectures. To make things tolerably consistent with that any operation
 * that installs a new bytecoded (or for that matter other) definition
 * will clear away any native-compiled versions of the function. 
 *
 * The native code that is installed will be expected to have relocation
 * records starting at the start of bpsbase, and these will be activated,
 * filling in references from the bps to other executable parts of Lisp.
 * Passing bad arguments to this function provide a quick and easy way to
 * cayse UTTER havoc. Therefore I disable its use in server applications.
 */

Lisp_Object MS_CDECL Lsymbol_set_native(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object fn, args, bpsbase, offset, env, w1, w2, w3;
    int32_t pagenumber, t_p, arginfo;
    intptr_t address, page, bps;
#ifdef SOCKETS
/*
 * Security measure - deny symbol-set-native to remote users
 */
    if (socket_server != 0) return aerror("symbol-set-native");
#endif
    argcheck(nargs, 5, "symbol-set-native");
    va_start(a, nargs);
    fn = va_arg(a, Lisp_Object);
    args = va_arg(a, Lisp_Object);
    bpsbase = va_arg(a, Lisp_Object);
    offset = va_arg(a, Lisp_Object);
    env = va_arg(a, Lisp_Object);
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
    if (address<8 || address>=CSL_PAGE_SIZE)
       return aerror1("symbol-set-native", offset);
    page = (intptr_t)native_pages[pagenumber];
    page = doubleword_align_up(page);
    bps = page + bps;
    relocate_native_function((unsigned char *)bps);
/*
 * Here I need to push the info I have just collected onto
 * the native_code list since otherwise things will not be re-loaded in
 * from a checkpoint image. Also if the function is at present byte-coded
 * I need to record that info about it in native_code.
 */
    w1 = native_code;
    w2 = nil;
    while (w1!=nil)
    {   w2 = qcar(w1);
        if (qcar(w2) == fn) break;
        w1 = qcdr(w1);
    }
    if (w1 == nil)
    {
/*
 * Here the function has not been seen as native code ever before, so it has
 * not been entered into the list. Do something about that...
 */
       push2(env, fn);
       args = Lsymbol_argcount(nil, fn);
       errexitn(2);
       if (args == nil)
           return aerror1("No bytecode definition found for", fn);
/*
 * Now I have to reverse the information that symbol_argcount gave me
 * to get the single numeric code as wanted by symbol_set_definition.
 * Oh what a mess.
 */
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
    w2 = qcdr(w2);  /* {nargs,(type . offset . env),...} */
/*
 * If I was defining this function in the simple way I should clear any
 * previous version (for this machine architecture) from the record.
 * Just at present this does not release the memory, but at some stage
 * in the future I may arrange to compact away old code when I do a
 * preserve operation (say).
 */
    if (nargs <= 0xff)
    {   w1 = w3 = w2;
        for (w1=qcdr(w2); w1!=nil; w1=qcdr(w1))
        {   w3 = qcar(w1);
            if (qcar(w3) == fixnum_of_int(native_code_tag)) break;
            w3 = w1;
        }
        if (w1 != nil) qcdr(w3) = qcdr(w1);
    }
/*
 * w2 is still the entry for this function in the native code list. It
 * needs to have an entry of type 0 (ie for bytecoded) and so the next
 * thing to do is to check that such an entry exists and if not to create
 * it.
 */
    w1 = w2;
    while ((w1 = qcdr(w1)) != nil)
    {   w3 = qcar(w1);
        if (qcar(w3) == fixnum_of_int(0)) break;
        w1 = qcdr(w1);
    }
    if (w1 == nil)
    {
/*
 * This is where there was no bytecode entry on the native code list
 * for this function, so I had better create one for it. Note that only
 * one such entry will ever be stored so it does not matter much where on
 * the list it goes. I suspect that the list ought always to be empty
 * in this case anyway.
 */
        push3(fn, env, w2);
        w1 = list2star(fixnum_of_int(0), fixnum_of_int(0), qenv(fn));
        errexitn(3);
        w2 = stack[0];
        w1 = cons(w1, qcdr(w2));
        errexitn(3);
        pop3(w2, env, fn);
        qcdr(w2) = w1;
    }
/*
 * Now the list of native code associated with this function certainly holds
 * a byte-coded definition (and for sanity that had better be consistent
 * with the native code I am installing now, but that is not something
 * that can be checked at this level). Put in an entry referring to the
 * current gubbins.
 */
    push3(w2, fn, env);
/*
 * now I pack the code type, arg category and offset into the
 * single fixnum that that information has to end up in.
 */
    t_p = (native_code_tag << 20);
    if ((nargs & 0xffffff00) != 0)
    {
        switch (nargs & 0xff)
        {
    case 1: t_p |= (1<<18); break;
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
    while ((w3 = qcdr(w2)) != nil) w2 = w3;  /* Tag onto the END */
    qcdr(w2) = w1;
    qheader(fn) &= ~SYM_TRACED;
    address = page + address;
/*
 * The code here must do just about the equivalent to that in restart.c
 */
    switch (nargs & 0xff)
    {
case 0:  ifnn(fn) = address;
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

static CSLbool restore_fn_cell(Lisp_Object a, char *name,
                            int32_t len, setup_type const s[])
{
    int i;
    for (i=0; s[i].name != NULL; i++)
    {   if (strlen(s[i].name) == (size_t)len &&
            memcmp(name, s[i].name, len) == 0) break;
    }
    if (s[i].name == NULL) return NO;
    set_fns(a, s[i].one, s[i].two, s[i].n);
    return YES;
}

static Lisp_Object Lrestore_c_code(Lisp_Object nil, Lisp_Object a)
{
    char *name;
    int32_t len;
    Lisp_Object pn;
    if (!symbolp(a)) return aerror1("restore-c-code", a);
    push(a);
    pn = get_pname(a);
    pop(a);
    errexit();
    name = (char *)&celt(pn, 0);
    len = length_of_header(vechdr(pn)) - 4;
    if (restore_fn_cell(a, name, len, u01_setup) ||
        restore_fn_cell(a, name, len, u02_setup) ||
        restore_fn_cell(a, name, len, u03_setup) ||
        restore_fn_cell(a, name, len, u04_setup) ||
        restore_fn_cell(a, name, len, u05_setup) ||
        restore_fn_cell(a, name, len, u06_setup) ||
        restore_fn_cell(a, name, len, u07_setup) ||
        restore_fn_cell(a, name, len, u08_setup) ||
        restore_fn_cell(a, name, len, u09_setup) ||
        restore_fn_cell(a, name, len, u10_setup) ||
        restore_fn_cell(a, name, len, u11_setup) ||
        restore_fn_cell(a, name, len, u12_setup))
    {   Lisp_Object env;
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
    else return onevalue(nil);
}

Lisp_Object Lsymbol_set_definition(Lisp_Object nil,
                                   Lisp_Object a, Lisp_Object b)
/*
 * The odd case here is where the second argument represents a freshly
 * created bit of compiled code. In which case the structure is
 *   (nargs . codevec . envvec)
 * where nargs is an integer indicating the number of arguments, codevec
 * is a vector of bytecodes, and envvec is something to go in the
 * environment cell of the symbol.
 * Here the low 8 bits of nargs indicate the number of required arguments.
 * The next 8 bits give the number of optional arguments, and the next
 * two bits are flags. Of these, the first is set if any of the optional
 * arguments has an initform or supplied-p associate, and the other
 * indicates that a "&rest" argument is required.
 * Bits beyond that (if non-zero) indicate that the function definition
 * is of the form (defun f1 (a b c) (f2 a b)) and the number coded is the
 * length of the function body.
 * Standard Lisp does not need &optional or &rest arguments, but it turned
 * out to be pretty easy to make the bytecode compiler support them.
 */
{
    if (!is_symbol(a) ||
/*
 * Something flagged with the CODEPTR bit is a gensym manufactured to
 * stand for a compiled-code object. It should NOT be reset!
 */
        (qheader(a) & (SYM_SPECIAL_FORM | SYM_CODEPTR)) != 0)
    {   if (qheader(a) & SYM_C_DEF) return onevalue(nil);
        return aerror1("symbol-set-definition", a);
    }
    qheader(a) &= ~SYM_TRACED;
    set_fns(a, undefined1, undefined2, undefinedn); /* Tidy up first */
    qenv(a) = a;
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    if (b == nil) return onevalue(b); /* set defn to nil to undefine */
    else if (symbolp(b))
    {
/*
 * One could imagine a view that the second arg to symbol-set-definition
 * had to be a codepointer object. I will be kind (?) and permit the NAME
 * of a function too.  However for the second arg to be a macro or a
 * special form would still be a calamity.
 *      if ((qheader(b) & SYM_CODEPTR) == 0)
 *          return aerror1("symbol-set-definition", b);
 */
        if ((qheader(b) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0)
            return aerror1("symbol-set-definition", b);
        qheader(a) = qheader(a) & ~SYM_MACRO;
        {   set_fns(a, qfn1(b), qfn2(b), qfnn(b));
            qenv(a) = qenv(b);
/*
 * In order that checkpoint files can be made there is some very
 * ugly fooling around here for functions that are defined in the C coded
 * kernel.  Sorry.
 */
            if ((qheader(b) & SYM_C_DEF) != 0)
            {
#ifdef COMMON
                Lisp_Object c = get(b, unset_var, nil);
#else
                Lisp_Object c = get(b, unset_var);
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
    {   int32_t nargs = (int)int_of_fixnum(qcar(b)), nopts, flagbits, ntail;
        nopts = nargs >> 8;
        flagbits = nopts >> 8;
        ntail = flagbits >> 2;
        nargs &= 0xff;
        nopts &= 0xff;
        flagbits &= 3;
        if (ntail != 0)
        {   switch (100*nargs + ntail-1)
            {
        case 300: set_fns(a, wrong_no_na, wrong_no_nb, f3_as_0); break;
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
            {
        default:
        case 0:  /* easy case optional arguments */
                set_fns(a, byteopt1, byteopt2, byteoptn); break;
        case 1:  /* optional args, but non-nil default, or supplied-p extra */
                set_fns(a, hardopt1, hardopt2, hardoptn); break;
        case 2:  /* easy opt args, but also a &rest arg */
                set_fns(a, byteoptrest1, byteoptrest2, byteoptrestn); break;
        case 3:  /* complicated &options and &rest */
                set_fns(a, hardoptrest1, hardoptrest2, hardoptrestn); break;
            }
            else switch (flagbits)
            {
        default:
        case 0:  /* easy case optional arguments */
                set_fns(a, tracebyteopt1, tracebyteopt2, tracebyteoptn); break;
        case 1:  /* optional args, but non-nil default, or supplied-p extra */
                set_fns(a, tracehardopt1, tracehardopt2, tracehardoptn); break;
        case 2:  /* easy opt args, but also a &rest arg */
                set_fns(a, tracebyteoptrest1, tracebyteoptrest2, tracebyteoptrestn); break;
        case 3:  /* complicated &options and &rest */
                set_fns(a, tracehardoptrest1, tracehardoptrest2, tracehardoptrestn); break;
            }
        }
        else
        {   if (nargs > 4) nargs = 4;
            if ((qheader(a) & SYM_TRACED) != 0) nargs += 5;
            qheader(a) = qheader(a) & ~SYM_MACRO;
            switch (nargs)
            {
        case 0:   set_fns(a, wrong_no_0a, wrong_no_0b, bytecoded0);
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
    {   Lisp_Object bvl = qcar(qcdr(b));
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
    {   Lisp_Object bvl = qcar(qcdr(b));
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

Lisp_Object Lgetd(Lisp_Object nil, Lisp_Object a)
{
    Header h;
    Lisp_Object type;
    CSL_IGNORE(nil);
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

Lisp_Object Lremd(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object res;
    CSL_IGNORE(nil);
    if (!is_symbol(a) ||
        (qheader(a) & SYM_SPECIAL_FORM) != 0)
        return aerror1("remd", a);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    res = Lgetd(nil, a);
    errexit();
    if (res == nil) return onevalue(nil); /* no definition to remove */
/*
 * I treat an explicit use of remd as a redefinition, and ensure that
 * restarting a preserved image will not put the definition back.
 */
    qheader(a) = qheader(a) & ~SYM_MACRO;
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    set_fns(a, undefined1, undefined2, undefinedn);
    qenv(a) = a;
    return onevalue(res);
}

/*
 * For set-autoload the first argument must be a symbol that will name
 * a function, the second arg is either an atom or a list of atoms, each
 * of which specified a module to be loaded if the names function is
 * called.  Loading the modules is expected to instate a definition for the
 * function involved.  This function is arranged so it does NOT do anything
 * if the function being set for autoloading is already defined. This is
 * on the supposition that the existing definition is in fact the desired
 * one, say because the relevant module happens to have been loaded already.
 * An explicit use of remd first can be used to ensure that no previous
 * definition is present and thus that a real autoload stub will be instated,
 * if that is what you really want.
 */

Lisp_Object Lset_autoload(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object res;
    CSL_IGNORE(nil);
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
/*
 * I treat an explicit use of set-autoload as a redefinition, and ensure that
 * restarting a preserved image will not put the definition back.  Note that
 * I will not allow autoloadable macros...
 */
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

static Lisp_Object traced1_function(Lisp_Object env, Lisp_Object a)
{
    Lisp_Object name, nil = C_nil;
    Lisp_Object r = nil;
/*
 * Worry about errors & garbage collection in following calls to print fns
 * This MUST be fixed sometime fairly soon... but then it could only bite
 * people using the trace facility, and their code is already dead!
 */
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

static Lisp_Object traced2_function(Lisp_Object env,
                                    Lisp_Object a, Lisp_Object b)
{
    Lisp_Object name, nil = C_nil;
    Lisp_Object r = nil;
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

static Lisp_Object MS_CDECL tracedn_function(Lisp_Object env, int nargs, ...)
{
    Lisp_Object name, nil = C_nil;
    Lisp_Object r = nil;
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
    {
default:
/*
 * Calls with 1 or 2 args can never arise, since those cases have been
 * split off for separate treatment.
 */
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
/*
 * Because the above is a horrid mess I will only support traced
 * calls with at most 15 args (more than I expect most people to
 * try). And this only applies to thigs that are NOT bytecoded -
 * I can trace bytecoded things with more args I believe, so users are not
 * utterly lost I hope.
 */
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
/*
 * This take the entrypoint of a function and tries to identify it
 * by scanning the tables used by the bytecode interpreter.  If the
 * function is found a record is returned indicating how many args
 * it takes, and what its index is in the relevant table.  The code
 * <NOT_FOUND,NOT_FOUND> is returned to indicate failure if the function
 * is not found.
 */
{
    int32_t index;
    for (index=0; zero_arg_functions[index]!=NULL; index++)
        if (fn == zero_arg_functions[index]) return pack_funtable(0, index);
    for (index=0; one_arg_functions[index]!=NULL; index++)
        if (f1 == one_arg_functions[index]) return pack_funtable(1, index);
    for (index=0; two_arg_functions[index]!=NULL; index++)
        if (f2 == two_arg_functions[index]) return pack_funtable(2, index);
    for (index=0; three_arg_functions[index]!=NULL; index++)
        if (fn == three_arg_functions[index]) return pack_funtable(3, index);
    return pack_funtable(NOT_FOUND, NOT_FOUND);
}

Lisp_Object Ltrace_all(Lisp_Object nil, Lisp_Object a)
{
#ifdef DEBUG
    if (a == nil) trace_all = 0;
    else trace_all = 1;
    return onevalue(nil);
#else
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    return aerror("trace-all only supported in DEBUG version");
#endif
}

Lisp_Object Ltrace(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   Lisp_Object s = qcar(w);
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
/*
 * I permit the tracing of just one function from the kernel, and achieve
 * this by installing a wrapper function in place of the real definition.
 * Indeed this is just like Lisp-level embedding, except that I can get at the
 * entrypoint table used by the bytecode interpreter and so trap calls made
 * via there, and I can use that table to tell me how many arguments the
 * traced function needed.
 */
            if (displaced1 == NULL)
            {   int nargs = funtable_nargs(table_entry);
/*
 * Remember what function was being traced, so that it can eventually be
 * invoked, and its name printed.
 */
                displaced1 = f1;
                displaced2 = f2;
                displacedn = fn;
                tracedfn = s;
/*
 * This makes calls via the regular interpreter see the traced version...
 */
                set_fns(s, traced1_function, traced2_function,
                           tracedn_function);
                table_entry = find_built_in_function(f1, f2, fn);
                nargs = funtable_nargs(table_entry);
                table_entry = funtable_index(table_entry);
                if (nargs != NOT_FOUND)
                {
/*
 * .. and now I make calls via short-form bytecodes do likewise.
 */
                    switch (nargs)
                    {
                default:
                case 0: zero_arg_functions[funtable_index(table_entry)] =
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

Lisp_Object Luntrace(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w = a;
    CSL_IGNORE(nil);
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   Lisp_Object s = qcar(w);
        w = qcdr(w);
        if (symbolp(s))
        {   one_args *f1 = qfn1(s);
            two_args *f2 = qfn2(s);
            n_args *fn = qfnn(s);
            if (f1 == traceinterpreted1)
            {   set_fns(a, interpreted1, interpreted2, interpretedn);
                qenv(s) = qcdr(qenv(s));
            }
            else if (f1 == tracefunarged1)
            {   set_fns(s, funarged1, funarged2, funargedn);
                qenv(s) = qcdr(qenv(s));
            }
            if (f1 == tracebytecoded1) ifn1(s) = (intptr_t)bytecoded1;
            if (f2 == tracebytecoded2) ifn2(s) = (intptr_t)bytecoded2;
            if (fn == tracebytecoded0) ifnn(s) = (intptr_t)bytecoded0;
            if (fn == tracebytecoded3) ifnn(s) = (intptr_t)bytecoded3;
            if (fn == tracebytecodedn) ifnn(s) = (intptr_t)bytecodedn;
            if (f1 == tracebyteopt1) ifn1(s) = (intptr_t)byteopt1;
            if (f2 == tracebyteopt2) ifn2(s) = (intptr_t)byteopt2;
            if (fn == tracebyteoptn) ifnn(s) = (intptr_t)byteoptn;
            if (f1 == tracebyteoptrest1) ifn1(s) = (intptr_t)byteoptrest1;
            if (f2 == tracebyteoptrest2) ifn2(s) = (intptr_t)byteoptrest2;
            if (fn == tracebyteoptrestn) ifnn(s) = (intptr_t)byteoptrestn;
            if (f1 == tracehardopt1) ifn1(s) = (intptr_t)hardopt1;
            if (f2 == tracehardopt2) ifn2(s) = (intptr_t)hardopt2;
            if (fn == tracehardoptn) ifnn(s) = (intptr_t)hardoptn;
            if (f1 == tracehardoptrest1) ifn1(s) = (intptr_t)hardoptrest1;
            if (f2 == tracehardoptrest2) ifn2(s) = (intptr_t)hardoptrest2;
            if (fn == tracehardoptrestn) ifnn(s) = (intptr_t)hardoptrestn;
            if (f1 == traced1_function)
            {   int nargs = funtable_nargs(table_entry);
                set_fns(s, displaced1, displaced2, displacedn);
                if (nargs != NOT_FOUND)
                    switch (nargs)
                    {
                default:
                case 0: zero_arg_functions[funtable_index(table_entry)] =
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

Lisp_Object Ldouble(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   Lisp_Object s = qcar(w);
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

Lisp_Object Lundouble(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w = a;
    CSL_IGNORE(nil);
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   Lisp_Object s = qcar(w);
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

/*
 * This is at present EXPERIMENTAL and INCOMPLETE so do not try it
 * unless you are involved in debugging the code involved. It will NOT
 * work for general code!
 */

Lisp_Object Ljit(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object w = a;
    if (symbolp(a))
    {   a = ncons(a);
        errexit();
        w = a;
    }
    while (consp(w))
    {   Lisp_Object s = qcar(w);
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

#endif /* JIT */

Lisp_Object Lmacro_function(Lisp_Object nil, Lisp_Object a)
{
    if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & SYM_MACRO) == 0) return onevalue(nil);
/* If the MACRO bit is set in the header I know there is a definition */
    else return onevalue(cons(lambda, qenv(a)));
}


Lisp_Object get_pname(Lisp_Object a)
{
    Lisp_Object name = qpname(a);
#ifndef COMMON
/*
 * When a gensym is first created its pname field points at a string that
 * will form the base of its name, and a magic bit is set in its header.
 * If at some stage it is necessary to inspect the print name (mainly in
 * order to print the symbol) it becomes necessary to create a new string
 * and insert a serial number.  Doing things this way means that the serial
 * numbers that users see will tend to be smaller, and space for per-gensym
 * strings does not get allocated unless really needed.  The down side is
 * that every time I want to grab the pname of anything I have to check for
 * this case and admit the possibility of garbage collection or even
 * failure.
 */
    if (qheader(a) & SYM_UNPRINTED_GENSYM)
    {   uintptr_t len;
        Lisp_Object nil = C_nil;
        char genname[64];
        len = length_of_header(vechdr(name)) - CELL;
        if (len > 60) len = 60;     /* Unpublished truncation of the string */
        sprintf(genname, "%.*s%lu", (int)len,
                (char *)name + (CELL - TAG_VECTOR), (long)gensym_ser++);
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

Lisp_Object Lsymbol_name(Lisp_Object nil, Lisp_Object a)
{
    if (!symbolp(a)) return aerror1("symbol-name", a);
    a = get_pname(a);
    errexit();
    return onevalue(a);
}

#ifdef COMMON

Lisp_Object Lsymbol_package(Lisp_Object nil, Lisp_Object a)
{
    if (!symbolp(a)) return aerror1("symbol-package", a);
    a = qpackage(a);
    return onevalue(a);
}

#endif

static Lisp_Object Lrestart_csl2(Lisp_Object nil,
                                 Lisp_Object a, Lisp_Object b)
/*
 * If the argument is given as nil then this is a cold-start, and when
 * I begin again it would be a VERY good idea to do a (load!-module 'compat)
 * rather promptly (otherwise some Lisp functions will not work at all).
 * I do not automate that because this function is intended for use in
 * delicate system rebuilding contexts and I want the user to have ultimate
 * control.  (restart!-csl t) reloads a heap-image in the normal way.
 * (restart!-csl 'xx) where xx is neither nil nor t starts by reloading a
 * heap image, but then it looks for a function with the same name as xx
 * (since a heap image is reloaded it is NOT easy (possible?) to keep the
 * symbol) and calls it as a function. Finally the case
 * (restart!-csl '(module fn)) restart the system, then calls load-module
 * on the named module and finally calls the given restart function.
 * This last option can be useful since otherwise the function to be called
 * in (restart!-csl 'xx) would need to be in the base image as re-loaded.
 * The second argument is passed through (vis serialisation as a string
 * of characters) and remade as a Lisp object to be passed to the restart
 * function as an argument.
 */
{
    int n;
    char *v;
#ifdef SOCKETS
/*
 * Security measure - deny restart-csl to remote users
 */
    if (socket_server != 0) return aerror("restart-csl");
#endif
    ensure_screen();
    n = 0;
    v = NULL;
/*
 * A comment seems in order here. The case b==SPID_NOARG should only
 * arise if I came from Lrestart_csl: it indicates that there was
 * no second argument provided.
 */
    if (b != SPID_NOARG)
    {   Lisp_Object b1;
        push(a);
        b1 = b = Lexploden(nil, b);
        pop(a);
        errexit();
        while (b1 != nil)
        {   n++;            /* number of chars of arg */
            b1 = qcdr(b1);
        }
        v = (char *)malloc(n+1);
        if (v == NULL) return aerror("space exhausted in restart-csl");
        n = 0;
        while (b != nil)
        {   v[n++] = (char)int_of_fixnum(qcar(b));
            b = qcdr(b);
        }
        v[n] = 0;
    }
    term_printf("\nThe system is about to do a restart...\n");
/* Almost all unpicking of the argument is done back in csl.c */
    exit_value = a;
    exit_tag = fixnum_of_int(2);   /* Flag to say "restart" */
    exit_reason = UNWIND_RESTART;
    exit_charvec = v;
    flip_exception();
    return nil;
}

static Lisp_Object Lrestart_csl(Lisp_Object nil, Lisp_Object a)
{
    return Lrestart_csl2(nil, a, SPID_NOARG);
}

static Lisp_Object Lpreserve(Lisp_Object nil,
                             Lisp_Object startup, Lisp_Object banner)
/*
 * (preserve <startup-fn>) saves a Lisp image in a standard place
 * and arranges that when restarted the saved image will call the specified
 * startup function.  In the process of doing all this it unwinds down to
 * the top level of Lisp. If a startup function is not given then the
 * previously active one is used.  If nil is specified then the previously
 * active startup function is retained.  If banner is non-nil (well really
 * I want a string) is is a message of up to 40 characters to display
 * when the system restart.
 */
{
    char filename[LONGEST_LEGAL_FILENAME];
    CSLbool failed;
#ifdef SOCKETS
/*
 * Security measure - deny preserve to remote users
 */
    if (socket_server != 0) return aerror("preserve");
#endif
    if (startup != nil) supervisor = startup;
    failed = Iwriterootp(filename);  /* Can I open image file for writing? */
    term_printf("\nThe system will be preserved on file \"%s\"\n", filename);
    if (failed) return aerror("preserve");
    ensure_screen();
    exit_count = 0;
    nil = C_nil;
    exit_value = banner;
    exit_tag = fixnum_of_int(1);   /* Flag to say "preserve" */
    exit_reason = UNWIND_RESTART;
    flip_exception();
    return nil;
}

static Lisp_Object MS_CDECL Lpreserve_0(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "preserve");
    return Lpreserve(nil, nil, nil);
}

static Lisp_Object Lpreserve_1(Lisp_Object nil, Lisp_Object startup)
{
    return Lpreserve(nil, startup, nil);
}


/*
 * This is an experimental addition - a version of PRESERVE that allows
 * CSL to continue executing after it has written out an image file.
 */

static Lisp_Object Lcheckpoint(Lisp_Object nil,
                              Lisp_Object startup, Lisp_Object banner)
{
    char filename[LONGEST_LEGAL_FILENAME];
    CSLbool failed = 0;
    char *msg = "";
#ifdef SOCKETS
/*
 * Security measure - deny checkpoint to remote users
 */
    if (socket_server != 0) return aerror("checkpoint");
#endif
    ensure_screen();
    if (startup != nil) supervisor = startup;
    failed = Iwriterootp(filename);  /* Can I open image file for writing? */
    term_printf("\nThe system will be preserved on file \"%s\"\n", filename);
    if (failed) return aerror("checkpoint");
    if (is_vector(banner) &&
        type_of_header(vechdr(banner)) == TYPE_STRING)
        msg = &celt(banner, 0);
/*
 * Note, with some degree of nervousness, that things on the C stack will
 * be updated by the garbage collection that happens during the processing
 * of the call to preserve(), but they will be neither adjusted into
 * relative addresses nor unadjusted (and hence restored) by in the
 * image-writing. But the image writing will not actually move any data
 * around so all is still OK, I hope!
 */
    push5(codevec, litvec, catch_tags, faslvec, faslgensyms);
    preserve(msg);
    nil = C_nil;
    if (exception_pending()) failed = 1, flip_exception();
    adjust_all();
    pop5(faslgensyms, faslvec, catch_tags, litvec, codevec);
    eq_hash_tables = eq_hash_table_list;
    equal_hash_tables = equal_hash_table_list;
    eq_hash_table_list = equal_hash_table_list = nil;
    {   Lisp_Object qq;
        for (qq = eq_hash_tables; qq!=nil; qq=qcdr(qq))
            rehash_this_table(qcar(qq));
        for (qq = equal_hash_tables; qq!=nil; qq=qcdr(qq))
            rehash_this_table(qcar(qq));
    }
    set_up_functions(YES);
    if (failed) return aerror("checkpoint");
    return onevalue(nil);
}

static Lisp_Object MS_CDECL Lcheckpoint_0(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "checkpoint");
    return Lcheckpoint(nil, nil, nil);
}

static Lisp_Object Lcheckpoint_1(Lisp_Object nil, Lisp_Object startup)
{
    return Lcheckpoint(nil, startup, nil);
}

/*
 * Drop out to the next enclosing code that limits resources, as if there had
 * been an overflow.
 */

static Lisp_Object MS_CDECL Lresource_exceeded(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "resource-exceeded");
    return resource_exceeded();
}
#ifdef COMMON
static CSLbool eql_numbers(Lisp_Object a, Lisp_Object b)
/*
 * This is only called from eql, and then only when a and b are both tagged
 * as ratios or complex numbers.
 */
{
    Lisp_Object p, q;
    p = *(Lisp_Object *)(a + (CELL - TAG_NUMBERS));
    q = *(Lisp_Object *)(b + (CELL - TAG_NUMBERS));
    if (!eql(p, q)) return NO;
    p = *(Lisp_Object *)(a + (2*CELL - TAG_NUMBERS));
    q = *(Lisp_Object *)(b + (2*CELL - TAG_NUMBERS));
    return eql(p, q);
}
#endif

CSLbool eql_fn(Lisp_Object a, Lisp_Object b)
/*
 * This seems incredible - all the messing about that is needed to
 * check that numeric values compare properly.  Ugh.
 */
{
/*
 * (these tests done before eql_fn is called).
 *  if (a == b) return YES;
 *  if ((((int32_t)a ^ (int32_t)b) & TAG_BITS) != 0) return NO;
 *
 * Actually in Common Lisp mode where I have short floats as immediate data
 * I have further pain here with (eql 0.0 -0.0).
 */
#ifdef COMMON
    if ((a == TAG_SFLOAT && b == (TAG_SFLOAT|0x80000000)) ||
        (a == (TAG_SFLOAT|0x80000000) && b == TAG_SFLOAT)) return YES;
#endif
    if (!is_number(a) || is_immed_or_cons(a)) return NO;
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        if (h != flthdr(b)) return NO;
#ifdef COMMON
        if (type_of_header(h) == TYPE_SINGLE_FLOAT)
            return (single_float_val(a) == single_float_val(b));
        else
#endif
/*
 * For the moment I view all non-single floats as double floats. Extra
 * stuff will be needed here if I ever implement long floats as 3-word
 * objects.
 */
        return (double_float_val(a) == double_float_val(b));
    }
    else    /* ratio, complex or bignum */
    {   Header h = numhdr(a);
        if (h != numhdr(b)) return NO;
        if (type_of_header(h) == TYPE_BIGNUM)
        {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
            while (hh > (intptr_t)(CELL - TAG_NUMBERS))
            {   hh -= 4;
                if (*(uint32_t *)((char *)a + hh) !=
                    *(uint32_t *)((char *)b + hh))
                    return NO;
            }
            return YES;
        }
#ifdef COMMON
        else return eql_numbers(a, b);
#else
        else return NO;
#endif
    }
}

static CSLbool cl_vec_equal(Lisp_Object a, Lisp_Object b)
/*
 * here a and b are known to be vectors or arrays.  This should compare
 * them following the Common Lisp recipe, where strings or bitvectors
 * (simple or complex) have their contents compared, while all other types of
 * vector or array are tested using EQ.
 */
{
    Header ha = vechdr(a), hb = vechdr(b);
    intptr_t offa = 0, offb = 0;
    int ta = type_of_header(ha), tb = type_of_header(hb);
    intptr_t la = length_of_header(ha), lb = length_of_header(hb);
#ifdef COMMON
    if (header_of_bitvector(ha)) ta = TYPE_BITVEC1;
    if (header_of_bitvector(hb)) tb = TYPE_BITVEC1;
#endif
    switch (ta)
    {
/*
case TYPE_ARRAY:
/* My moan here is that, as noted above, I ought to process even
 * non-simple strings and bit-vectors by comparing contents, but as a
 * matter of idleness I have not yet got around to that. In fact if I get
 * arrays to compare here I will pretend that they are not strings or
 * bit-vectors and compare using EQ...
 */
case TYPE_STRING:
        switch (tb)
        {
/* /*
    case TYPE_ARRAY:
*/
    case TYPE_STRING:
            goto compare_strings;
    default:return NO;
        }
#ifdef COMMON
case TYPE_BITVEC1:
        switch (tb)
        {
/* /*
    case TYPE_ARRAY:
*/
    case TYPE_BITVEC1:
            goto compare_bits;
    default:return NO;
        }
#endif
default: return (a == b);
    }
compare_strings:
    if (la != lb) return NO;
    while (la > 0)
    {   la--;
        if (*((char *)a + la + offa - TAG_VECTOR) !=
            *((char *)b + la + offb - TAG_VECTOR)) return NO;
    }
    return YES;
#ifdef COMMON
compare_bits:
    if (la != lb) return NO;
    while (la > 0)
    {   la--;
        if (*((char *)a + la + offa - TAG_VECTOR) !=
            *((char *)b + la + offb - TAG_VECTOR)) return NO;
    }
    return YES;
#endif
}

CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b)
/*
 * a and b are not EQ at this stage.. I guarantee to have checked that
 * before entering this general purpose code.
 */
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(nil);
/*
 * The for loop at the top here is so that cl_equal can iterate along the
 * length of linear lists.
 */
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__))
    {   err_printf("Stack too deep in cl_equal\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {
        int32_t ta = (int32_t)a & TAG_BITS;
        if (ta == TAG_CONS
#ifdef COMMON
            && a != nil
#endif
            )
        {   if (!consp(b)
#ifdef COMMON
                || b == nil
#endif
                ) return NO;
            else
            {   Lisp_Object ca = qcar(a), cb = qcar(b);
                if (ca == cb)
                {   a = qcdr(a);
                    b = qcdr(b);
                    if (a == b) return YES;
                    continue;
                }
/*
 * And here, because cl_equal() seems to be a very important low-level
 * primitive, I unwind one level of the recursion that would arise
 * with nested lists.
 */
                for (;;)
                {
                    int32_t tca = (int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS
#ifdef COMMON
                        && ca != nil
#endif
                        )
                    {   if (!consp(cb)
#ifdef COMMON
                            || cb == nil
#endif
                            ) return NO;
                        else
                        {   Lisp_Object cca = qcar(ca), ccb = qcar(cb);
                            if (cca == ccb)
                            {   ca = qcdr(ca);
                                cb = qcdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
/*
 * Do a real recursion when I get down to args like
 * ((x ...) ...) ((y ...) ...)
 */
                            if (!cl_equal(cca, ccb)) return NO;
                            ca = qcdr(ca);
                            cb = qcdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (tca <= TAG_SYMBOL ||
                             ((int32_t)cb & TAG_BITS) != tca) return NO;
                    else switch (tca)
                    {
                case TAG_NUMBERS:
                        {   Header h = numhdr(ca);
                            if (h != numhdr(cb)) return NO;
                            if (type_of_header(h) == TYPE_BIGNUM)
                            {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                                while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                                {   hh -= 4;
                                    if (*(uint32_t *)((char *)ca + hh) !=
                                        *(uint32_t *)((char *)cb + hh))
                                        return NO;
                                }
                                break;
                            }
#ifdef COMMON
                            else if (!eql_numbers(ca, cb)) return NO;
                            else break;
#else
                            else return NO;
#endif
                        }
                case TAG_VECTOR:
                        if (!cl_vec_equal(ca, cb)) return NO;
                        break;
                default:
                case TAG_BOXFLOAT:
                        {   Header h = flthdr(ca);
                            if (h != flthdr(cb)) return NO;
#ifdef COMMON
                            if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                            {
                                if (single_float_val(ca) !=
                                    single_float_val(cb)) return NO;
                                else break;
                            }
                            else
#endif
                            {
                                if (double_float_val(ca) !=
                                     double_float_val(cb)) return NO;
                                else break;
                            }
                        }
                    }
                    break;  /* out of the for (;;) loop */
                }
                a = qcdr(a);
                b = qcdr(b);
                if (a == b) return YES;
                continue;
            }
        }
        else if (ta <= TAG_SYMBOL ||
                 ((int32_t)b & TAG_BITS) != ta) return NO;
/*
 * OK - now a and b both have the same type and neither are immediate data
 * conses or symbols. That leaves vectors (including strings) and boxed
 * numbers.
 */
        else switch (ta)
        {
    case TAG_NUMBERS:
            {   Header h = numhdr(a);
                if (h != numhdr(b)) return NO;
                if (type_of_header(h) == TYPE_BIGNUM)
                {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                    while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                    {   hh -= 4;
                        if (*(uint32_t *)((char *)a + hh) !=
                            *(uint32_t *)((char *)b + hh))
                            return NO;
                    }
                    return YES;
                }
#ifdef COMMON
                else return eql_numbers(a, b);

#else
                else return NO;
#endif
            }
    case TAG_VECTOR:
            return cl_vec_equal(a, b);
    default:
    case TAG_BOXFLOAT:
            {   Header h = flthdr(a);
                if (h != flthdr(b)) return NO;
#ifdef COMMON
                if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                {
                    if (single_float_val(a) != single_float_val(b))
                        return NO;
                    else return YES;
                }
                else
#endif
/*
 * For the moment I view all non-single floats as double floats. Extra
 * stuff will be needed here if I ever implement long floats as 3-word
 * objects.
 */
                {
                    if (double_float_val(a) != double_float_val(b))
                        return NO;
                    else return YES;
                }
            }
        }
    }
}

static CSLbool vec_equal(Lisp_Object a, Lisp_Object b);

#ifdef TRACED_EQUAL
#define LOG_SIZE 10000
typedef struct equal_record
{
    char file[24];
    int line;
    int depth;
    int count;
} equal_record;

static equal_record equal_counts[LOG_SIZE];

static void record_equal(char *file, int line, int depth)
{
    int hash = 169*line + depth;
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
{
    int i;
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

CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                     char *file, int line, int depth)
/*
 * a and b are not EQ at this stage.. I guarantee to have checked that
 * before entering this general purpose code.
 */
{
    Lisp_Object nil = C_nil;
    record_equal(file, line, depth);
#undef equal_fn
#define equal_fn(a, b) traced_equal_fn(a, b, file, line, depth+1)
#else
CSLbool equal_fn(Lisp_Object a, Lisp_Object b)
/*
 * a and b are not EQ at this stage.. I guarantee to have checked that
 * before entering this general purpose code. I will also have checked that
 * the types of the two args agree, and that they are not both immediate
 * date.
 */
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(nil);
#endif
/*
 * The for loop at the top here is so that equal can iterate along the
 * length of linear lists.
 */
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__))
    {   err_printf("Stack too deep in equal\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {
        int32_t ta = (int32_t)a & TAG_BITS;
        if (ta == TAG_CONS
#ifdef COMMON
            && a != nil
#endif
            )
        {   if (!consp(b)
#ifdef COMMON
                || b == nil
#endif
                ) return NO;
            else
            {   Lisp_Object ca = qcar(a), cb = qcar(b);
                if (ca == cb)
                {   a = qcdr(a);
                    b = qcdr(b);
                    if (a == b) return YES;
                    continue;
                }
/*
 * And here, because equal() seems to be a very important low-level
 * primitive, I unwind one level of the recursion that would arise
 * with nested lists.
 */
                for (;;)
                {
                    int32_t tca = (int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS
#ifdef COMMON
                        && ca != nil
#endif
                        )
                    {   if (!consp(cb)
#ifdef COMMON
                            || cb == nil
#endif
                            ) return NO;
                        else
                        {   Lisp_Object cca = qcar(ca), ccb = qcar(cb);
                            if (cca == ccb)
                            {   ca = qcdr(ca);
                                cb = qcdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
/*
 * Do a real recursion when I get down to args like
 * ((x ...) ...) ((y ...) ...)
 */
                            if (!equal(cca, ccb)) return NO;
                            ca = qcdr(ca);
                            cb = qcdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (tca <= TAG_SYMBOL ||
                             ((int32_t)cb & TAG_BITS) != tca) return NO;
                    else switch (tca)
                    {
                case TAG_NUMBERS:
                        {   Header h = numhdr(ca);
                            if (h != numhdr(cb)) return NO;
                            if (type_of_header(h) == TYPE_BIGNUM)
                            {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                                while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                                {   hh -= 4;
                                    if (*(uint32_t *)((char *)ca + hh) !=
                                        *(uint32_t *)((char *)cb + hh))
                                        return NO;
                                }
                                break;
                            }
#ifdef COMMON
                            else if (!eql_numbers(ca, cb)) return NO;
                            else break;
#else
                            else return NO;
#endif
                        }
                case TAG_VECTOR:
                        if (!vec_equal(ca, cb)) return NO;
                        break;
                default:
                case TAG_BOXFLOAT:
                        {   Header h = flthdr(ca);
                            if (h != flthdr(cb)) return NO;
#ifdef COMMON
                            if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                            {
                                if (single_float_val(ca) !=
                                    single_float_val(cb)) return NO;
                                else break;
                            }
                            else
#endif
                            {
                                if (double_float_val(ca) !=
                                    double_float_val(cb)) return NO;
                                else break;
                            }
                        }
                    }
                    break;  /* out of the for (;;) loop */
                }
                a = qcdr(a);
                b = qcdr(b);
                if (a == b) return YES;
                continue;
            }
        }
        else if (ta <= TAG_SYMBOL ||
                 ((int32_t)b & TAG_BITS) != ta) return NO;
        else switch (ta)
        {
    case TAG_NUMBERS:
            {   Header h = numhdr(a);
                if (h != numhdr(b)) return NO;
                if (type_of_header(h) == TYPE_BIGNUM)
                {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                    while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                    {   hh -= 4;
                        if (*(uint32_t *)((char *)a + hh) !=
                            *(uint32_t *)((char *)b + hh))
                            return NO;
                    }
                    return YES;
                }
#ifdef COMMON
                else return eql_numbers(a, b);

#else
                else return NO;
#endif
            }
    case TAG_VECTOR:
            return vec_equal(a, b);
    default:
    case TAG_BOXFLOAT:
            {   Header h = flthdr(a);
                if (h != flthdr(b)) return NO;
#ifdef COMMON
                if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                {
                    if (single_float_val(a) != single_float_val(b))
                        return NO;
                    else return YES;
                }
                else
#endif
/*
 * For the moment I view all non-single floats as double floats. Extra
 * stuff will be needed here if I ever implement long floats as 3-word
 * objects.
 */
                {
                    if (double_float_val(a) != double_float_val(b))
                        return NO;
                    else return YES;
                }
            }
        }
    }
}

#ifdef TRACED_EQUAL
#undef equal_fn
#define equal_fn(a, b) traced_equal(a, b, __FILE__, __LINE__, 0)
#endif

static CSLbool vec_equal(Lisp_Object a, Lisp_Object b)
/*
 * Here a and b are known to be vectors. Compare using recursive calls to
 * EQUAL on all components.
 */
{
    Header ha = vechdr(a), hb = vechdr(b);
    int32_t l;
    if (ha != hb) return NO;
    l = (int32_t)doubleword_align_up(length_of_header(ha));
    if (vector_holds_binary(ha))
    {   while ((l -= 4) != 0)
            if (*((uint32_t *)((char *)a + l - TAG_VECTOR)) !=
                *((uint32_t *)((char *)b + l - TAG_VECTOR))) return NO;
        return YES;
    }
    else
    {   if (is_mixed_header(ha))
        {   while (l > 16)
            {   uint32_t ea = *((uint32_t *)((char *)a + l - TAG_VECTOR - 4)),
                           eb = *((uint32_t *)((char *)b + l - TAG_VECTOR - 4));
                if (ea != eb) return NO;
                l -= 4;
            }
        }
        while ((l -= CELL) != 0)
        {   Lisp_Object ea = *((Lisp_Object *)((char *)a + l - TAG_VECTOR)),
                        eb = *((Lisp_Object *)((char *)b + l - TAG_VECTOR));
            if (ea == eb) continue;
            if (!equal(ea, eb)) return NO;
        }
        return YES;
    }
}

CSLbool equalp(Lisp_Object a, Lisp_Object b)
/*
 * a and b are not EQ at this stage.. I guarantee to have checked that
 * before entering this general purpose code.
 */
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(nil);
/*
 * The for loop at the top here is so that equalp can iterate along the
 * length of linear lists.
 */
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__))
    {   err_printf("Stack too deep in equalp\n");
        my_exit(EXIT_FAILURE);
    }
#endif
    for (;;)
    {
        int32_t ta = (int32_t)a & TAG_BITS;
        if (ta == TAG_CONS
#ifdef COMMON
            && a != nil
#endif
            )
        {   if (!consp(b)
#ifdef COMMON
                || b == nil
#endif
                ) return NO;
            else
            {   Lisp_Object ca = qcar(a), cb = qcar(b);
                if (ca == cb)
                {   a = qcdr(a);
                    b = qcdr(b);
                    if (a == b) return YES;
                    continue;
                }
/*
 * And here, because equalp() seems to be a very important low-level
 * primitive, I unwind one level of the recursion that would arise
 * with nested lists.
 */
                for (;;)
                {
                    int32_t tca = (int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS
#ifdef COMMON
                        && ca != nil
#endif
                        )
                    {   if (!consp(cb)
#ifdef COMMON
                            || cb == nil
#endif
                            ) return NO;
                        else
                        {   Lisp_Object cca = qcar(ca), ccb = qcar(cb);
                            if (cca == ccb)
                            {   ca = qcdr(ca);
                                cb = qcdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
/*
 * Do a real recursion when I get down to args like
 * ((x ...) ...) ((y ...) ...)
 */
                            if (!equalp(cca, ccb)) return NO;
                            ca = qcdr(ca);
                            cb = qcdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (tca <= TAG_SYMBOL ||
                             ((int32_t)cb & TAG_BITS) != tca) return NO;
                    else switch (tca)
                    {
                case TAG_NUMBERS:
                        {   Header h = numhdr(ca);
                            if (h != numhdr(cb)) return NO;
                            if (type_of_header(h) == TYPE_BIGNUM)
                            {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                                while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                                {   hh -= 4;
                                    if (*(uint32_t *)((char *)ca + hh) !=
                                        *(uint32_t *)((char *)cb + hh))
                                        return NO;
                                }
                                break;
                            }
#ifdef COMMON
                            else if (!eql_numbers(ca, cb)) return NO;
                            else break;
#else
                            else return NO;
#endif
                        }
                case TAG_VECTOR:
/* /* At present vec_equal() is not right here */
                        if (!vec_equal(ca, cb)) return NO;
                        break;
                default:
                case TAG_BOXFLOAT:
                        {   Header h = flthdr(ca);
                            if (h != flthdr(cb)) return NO;
#ifdef COMMON
                            if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                            {
                                if (single_float_val(ca) !=
                                    single_float_val(cb)) return NO;
                                else break;
                            }
                            else
#endif
                            {
                                if (double_float_val(ca) !=
                                    double_float_val(cb)) return NO;
                                else break;
                            }
                        }
                    }
                    break;  /* out of the for (;;) loop */
                }
                a = qcdr(a);
                b = qcdr(b);
                if (a == b) return YES;
                continue;
            }
        }
        else if (ta <= TAG_SYMBOL ||
                 ((int32_t)b & TAG_BITS) != ta) return NO;
/* What is left is vectors, strings and boxed numbers */
        else switch (ta)
        {
    case TAG_NUMBERS:
            {   Header h = numhdr(a);
                if (h != numhdr(b)) return NO;
                if (type_of_header(h) == TYPE_BIGNUM)
                {   intptr_t hh = (intptr_t)length_of_header(h) - TAG_NUMBERS;
                    while (hh > (intptr_t)(CELL - TAG_NUMBERS))
                    {   hh -= 4;
                        if (*(uint32_t *)((char *)a + hh) !=
                            *(uint32_t *)((char *)b + hh))
                            return NO;
                    }
                    return YES;
                }
#ifdef COMMON
                else return eql_numbers(a, b);

#else
                else return NO;
#endif
            }
    case TAG_VECTOR:
/* /* wrong for Common Lisp */
            return vec_equal(a, b);
    default:
    case TAG_BOXFLOAT:
            {   Header h = flthdr(a);
                if (h != flthdr(b)) return NO;
#ifdef COMMON
                if (type_of_header(h) == TYPE_SINGLE_FLOAT)
                {
                    if (single_float_val(a) != single_float_val(b))
                        return NO;
                    else return YES;
                }
                else
#endif
/*
 * For the moment I view all non-single floats as double floats. Extra
 * stuff will be needed here if I ever implement long floats as 3-word
 * objects.
 */
                {
                    if (double_float_val(a) != double_float_val(b))
                        return NO;
                    else return YES;
                }
            }
        }
    }
}

Lisp_Object Leq(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return onevalue(Lispify_predicate(a == b));
}

Lisp_Object Leql(Lisp_Object nil,
                        Lisp_Object a, Lisp_Object b)
{
    return onevalue(Lispify_predicate(eql(a, b)));
}

Lisp_Object Leqcar(Lisp_Object nil,
                          Lisp_Object a, Lisp_Object b)
{
    if (!consp(a)) return onevalue(nil);
    a = qcar(a);
#ifdef COMMON
    return onevalue(Lispify_predicate(eql(a, b)));
#else
    return onevalue(Lispify_predicate(a == b));
#endif
}

Lisp_Object Lequalcar(Lisp_Object nil,
                          Lisp_Object a, Lisp_Object b)
{
    if (!consp(a)) return onevalue(nil);
    a = qcar(a);
    if (a == b) return lisp_true;
    else return onevalue(Lispify_predicate(equal(a, b)));
}

Lisp_Object Lcl_equal(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(cl_equal(a, b)));
}

Lisp_Object Lequal(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(equal(a, b)));
}

Lisp_Object Lequalp(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(equalp(a, b)));
}

Lisp_Object Lneq(Lisp_Object nil,
                        Lisp_Object a, Lisp_Object b)
{
    CSLbool r;
#ifdef COMMON
    r = cl_equal(a, b);
#else
    r = equal(a, b);
#endif
    return onevalue(Lispify_predicate(!r));
}

Lisp_Object Lnull(Lisp_Object nil, Lisp_Object a)
{
    return onevalue(Lispify_predicate(a == nil));
}

Lisp_Object Lendp(Lisp_Object nil, Lisp_Object a)
{
    if (a == nil) return onevalue(lisp_true);
    else if (is_cons(a)) return onevalue(nil);
    else return error(1, err_bad_endp, a);
}

Lisp_Object Lnreverse(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object b = nil;
#ifdef COMMON
    if (is_vector(a))
    {   int32_t n = Llength(nil, a) - 0x10;
        int32_t i = TAG_FIXNUM;
        while (n > i)
        {   Lisp_Object w = Laref2(nil, a, i);
            Laset(nil, 3, a, i, Laref2(nil, a, n));
            Laset(nil, 3, a, n, w);
            i += 0x10;
            n -= 0x10;
        }
        return onevalue(a);
    }
#endif
    while (consp(a))
    {   Lisp_Object c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return onevalue(b);
}

Lisp_Object Lnreverse2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    while (consp(a))
    {   Lisp_Object c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return onevalue(b);
}

#ifdef COMMON

/*
 * nreverse0 is like nreverse except that if its input is atomic it gets
 * returned intact rather than being converted to nil.
 */

Lisp_Object Lnreverse0(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object b = nil;
    if (!consp(a)) return onevalue(a);
    b = a;
    a = qcdr(a);
    qcdr(b) = nil;
    while (consp(a))
    {   Lisp_Object c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return onevalue(b);
}

#endif

Lisp_Object Lreverse(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object r;
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

Lisp_Object Lassoc(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
#ifdef TRACED_EQUAL
    Lisp_Object save_b = b;
    int pos = 0;
#endif
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   Lisp_Object c = qcar(b);
            if (consp(c) && a == qcar(c)) return onevalue(c);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
    while (consp(b))
    {   Lisp_Object c = qcar(b);
        if (consp(c))
        {   Lisp_Object cc = qcar(c);
#ifdef COMMON
            if (cl_equal(a, cc)) return onevalue(c);
#else
            if (equal(a, cc))
            {
#ifdef TRACED_EQUAL
/*
 * In silly cases the length might not be a fixnum!
 */
    trace_printf("Assoc YES %3d %3d ", pos, int_of_fixnum(Llength(nil,save_b)));
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
/* beware stuplidly lonng lists... */
    trace_printf("Assoc NO  %3d %3d ", pos, int_of_fixnum(Llength(nil,save_b)));
    prin_to_stdout(a); trace_printf("\n");
#endif
    return onevalue(nil);
}

Lisp_Object Latsoc(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
#ifdef COMMON
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   Lisp_Object c = qcar(b);
            if (consp(c) && a == qcar(c)) return onevalue(c);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
#endif
    while (consp(b))
    {   Lisp_Object c = qcar(b);
/*
 * eql() can neither fail nor call the garbage collector, so I do
 * not need to stack things here.
 */
#ifdef COMMON
        if (consp(c) && eql(a, qcar(c))) return onevalue(c);
#else
        if (consp(c) && a == qcar(c)) return onevalue(c);
#endif
        b = qcdr(b);
    }
    return onevalue(nil);
}

Lisp_Object Lmember(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == qcar(b)) return onevalue(b);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
    while (consp(b))
    {   Lisp_Object cb = qcar(b);
#ifdef COMMON
        if (cl_equal(a, cb)) return onevalue(b);
#else
        if (equal(a, cb)) return onevalue(b);
#endif
        b = qcdr(b);
    }
    return onevalue(nil);
}

Lisp_Object Lmemq(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
#ifdef COMMON
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == qcar(b)) return onevalue(b);
            b = qcdr(b);
        }
        return onevalue(nil);
    }
#endif
    while (consp(b))
/*
 * Note that eql() can never fail, and so checking for errors
 * and stacking a and b across the call to it is not necessary.
 */
    {
#ifdef COMMON
        if (eql(a, qcar(b))) return onevalue(b);
#else
        if (a == qcar(b)) return onevalue(b);
#endif
        b = qcdr(b);
    }
    return onevalue(nil);
}

static CSLbool smemq(Lisp_Object a, Lisp_Object b)
{
/*
 * /* This is a bit worrying - it can use C recursion to arbitrary
 * depth without any checking for overflow, and hence it can ESCAPE
 * if (e.g.) given cyclic structures.  Some alteration is needed.  As
 * things stand the code can never give wrong answers via GC rearrangement -
 * the problem is closer to being that it can never call the GC.
 */
#ifdef COMMON
    Lisp_Object nil = C_nil;
#else
    nil_as_base
#endif
    while (consp(b))
    {   Lisp_Object w = qcar(b);
        if (w == quote_symbol) return NO;
        else if (smemq(a, w)) return YES;
        else b = qcdr(b);
    }
    return (a == b);
}

Lisp_Object Lsmemq(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSLbool r;
    r = smemq(a, b);
    errexit();
    return onevalue(Lispify_predicate(r));
}

/*
 *  (defun contained (x y)
 *     (cond ((atom y) (equal x y))
 *           ((equal x y) 't)
 *           ('t (or (contained x (car y)) (contained x (cdr y))))))
 */

static CSLbool containedeq(Lisp_Object nil, Lisp_Object x, Lisp_Object y)
{
    while (consp(y))
    {   if (containedeq(nil, x, qcar(y))) return YES;
        y = qcdr(y);
    }
    return (x == y);
}

static CSLbool containedequal(Lisp_Object nil, Lisp_Object x, Lisp_Object y)
{
    while (consp(y))
    {   if (equal(x, y)) return YES;
        if (containedequal(nil, x, qcar(y))) return YES;
        y = qcdr(y);
    }
    return equal(x, y);
}

static Lisp_Object Lcontained(Lisp_Object nil, Lisp_Object x, Lisp_Object y)
{
    CSLbool r;
    if (is_symbol(x) || is_fixnum(x)) r = containedeq(nil, x, y);
    else r = containedequal(nil, x, y);
    errexit();
    return onevalue(Lispify_predicate(r));
}

Lisp_Object Llast(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object b;
    CSL_IGNORE(nil);
    if (!consp(a)) return aerror1("last", a);
    while (b = qcdr(a), consp(b)) a = b;
    return onevalue(qcar(a));
}

Lisp_Object Llastpair(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object b;
    CSL_IGNORE(nil);
    if (!consp(a)) return onevalue(a); /* aerror1("lastpair", a); */
    while (b = qcdr(a), consp(b)) a = b;
    return onevalue(a);
}

Lisp_Object Llength(Lisp_Object nil, Lisp_Object a)
{
/*
 * The use of 64-bit computers generates a real jolly here. In CSL at
 * present FIXNUMs are 28 bits, so the largest positive fixnum is around
 * 131,000,000. If I count lengths in fixnums as I did in my initial
 * version here and I look at a list longer than that (which of necessity
 * uses around 2G of memory on a 64 bit machine) I get an overflow and a
 * silly answer. I might JUST be able to get the same overflow on a 32-bit
 * system using just a bit over 1G of memory.
 *
 * If I do the counts in 32-bit "unsigned int" arithmetic then the
 * world is safe until I have filled 64G with cons cells. Right now that
 * feels safe... but having been bitten here once I will arrange to go
 * distinctly beyond that just to be certain - or at least to put off the
 * issue for long enough that I can be confident that it will not matter.
 */
    if (a == nil) return onevalue(fixnum_of_int(0));
    if (is_cons(a))
    {   uint32_t n, nhigh;
/*
 * Possibly I should do something to trap cyclic lists.. But doing so
 * would tend to be extra cost so unless it becomes a vital issue because
 * of some bug I will not worry.
 */
        n = 1;
        nhigh = 0;
/*
 * I have unrolled the loop here 4 times since I expect length to be
 * tolerably heavily used.  Look at the assembly code generated for
 * this to see if it was useful or counterproductive!
 */
        for (;;)
        {   a = qcdr(a);
            if (!consp(a)) break;
            a = qcdr(a);
            if (!consp(a)) { n += 1; break; }
            a = qcdr(a);
            if (!consp(a)) { n += 2; break; }
            a = qcdr(a);
            if (!consp(a)) { n += 3; break; }
            n += 4;
            if ((n & 0x80000000) != 0) { n = 0; nhigh++; }
        }
        if (nhigh != 0) return make_two_word_bignum(nhigh, n);
        else if ((n & fix_mask) != 0) return make_one_word_bignum(n);
        else return fixnum_of_int(n);
    }
#ifndef COMMON
    return onevalue(fixnum_of_int(0));  /* aerror("length");??? */
#else
/*
 * Common Lisp expects length to find the length of vectors
 * as well as lists. I believe that because of my "page size" limit no
 * bector can have more than 2^27 entries. The first possible dodgy case
 * would be a bit-vector, and one of those that was 16Mbytes long would
 * hit the limit... while at the time of writing this I use 4 Mbyte pages
 * even on 64-bit machines.
 */
    else if (!is_vector(a)) return aerror1("length", a);
    else
    {   Header h = vechdr(a);
        int32_t n = length_of_header(h) - CELL;
        if (type_of_header(h) == TYPE_ARRAY)
        {   Lisp_Object dims = elt(a, 1);
            Lisp_Object fillp = elt(a, 5);
            if (consp(dims) && !consp(qcdr(dims))) dims = qcar(dims);
            else return aerror1("length", a);  /* Not one-dimensional */
            if (is_fixnum(fillp)) dims = fillp;
            return onevalue(dims);
        }
        if (header_of_bitvector(h))
        {   n = (n - 1)*8;
/* Dodgy constant on next line - critically dependent on tag codes used! */
            n += ((h & 0x380) >> 7) + 1;
        }
        else if (type_of_header(h) != TYPE_STRING) n = n/CELL;
        return onevalue(fixnum_of_int(n));
    }
#endif
}

#ifdef COMMON

Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    int i;
    Lisp_Object r;
    if (nargs == 0) return onevalue(nil);
    va_start(a, nargs);
    push_args(a, nargs);
/*
 * The actual args have been passed a C args - I can not afford to
 * risk garbage collection until they have all been moved somewhere safe,
 * and here that safe place is the Lisp stack.  I have to delay checking for
 * overflow on same until all args have been pushed.
 */
    stackcheck0(nargs);
    nil = C_nil;
    r = nil;
/*
 * rearrange order of items on the stack...
 * The idea is that I will then reverse-copy the args in the order a1,
 * a2 , ... to make a result list.  But I want to pop the stack as soon as
 * I can, so I need arg1 on the TOP of the stack.
 */
    for (i = 0; 2*i+1<nargs; i++)
    {   Lisp_Object temp = stack[-i];
        stack[-i] = stack[i+1-nargs];
        stack[i+1-nargs] = temp;
    }
    for (i = 0; i<nargs; i++)
    {   Lisp_Object w;
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

Lisp_Object Lappend_1(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    return onevalue(a);
}

#endif /* COMMON */

Lisp_Object Lappend(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object r = nil;
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

Lisp_Object Ldelete(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object r;
    push2(a, b);
    r = nil;
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   Lisp_Object q = qcar(b);
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
        {   Lisp_Object q = qcar(b);
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
    {   Lisp_Object w = qcdr(r);
        qcdr(r) = b;
        b = r;
        r = w;
    }
    return onevalue(b);
}


Lisp_Object Ldeleq(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object r;
    push2(a, b);
    r = nil;
    while (consp(b))
    {   Lisp_Object q = qcar(b);
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
    {   Lisp_Object w = qcdr(r);
        qcdr(r) = b;
        b = r;
        r = w;
    }
    return onevalue(b);
}

Lisp_Object Lnconc(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object c;
    CSL_IGNORE(nil);
    if (!consp(a)) return onevalue(b);
    c = a;
    for (;;)
    {   Lisp_Object next = qcdr(c);
        if (!consp(next))
        {   qcdr(c) = b;
            return onevalue(a);
        }
        else c = next;
    }
}

/* #ifndef COMMON */

static Lisp_Object Lsubstq(Lisp_Object a, Lisp_Object b, Lisp_Object c)
{
    Lisp_Object w, nil = C_nil;
    if (c == b) return onevalue(a);
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__)) return aerror("substq");
#endif
    stackcheck3(0, a, b, c);
    push3(a, b, c);
    if (c == b)
    {   popv(2);
        pop(a);
        errexit();
        return onevalue(a);
    }
    if (!consp(stack[0])) { pop(c); popv(2); return c; }
    w = Lsubstq(stack[-2], stack[-1], qcar(stack[0]));
    errexitn(3);
    pop2(c, b);
    a = stack[0];
    stack[0] = w;
    w = Lsubstq(a, b, qcdr(c));
    pop(a);
    errexit();
    a = cons(a, w);
    errexit();
    return onevalue(a);
}

Lisp_Object MS_CDECL Lsubst(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object w, a, b, c;
    va_list aa;
    argcheck(nargs, 3, "subst");
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__)) return aerror("subst");
#endif
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    c = va_arg(aa, Lisp_Object);
    va_end(aa);
    if (c == b) return onevalue(a);
    if (is_symbol(b) || is_fixnum(b)) return Lsubstq(a, b, c);
    stackcheck3(0, a, b, c);
    push3(a, b, c);
#ifdef COMMON
    if (cl_equal(c, b))
#else
    if (equal(c, b))
#endif
    {   popv(2);
        pop(a);
        errexit();
        return onevalue(a);
    }
    if (!consp(stack[0])) { pop(c); popv(2); return c; }
    w = Lsubst(nil, 3, stack[-2], stack[-1], qcar(stack[0]));
    errexitn(3);
    pop2(c, b);
    a = stack[0];
    stack[0] = w;
    w = Lsubst(nil, 3, a, b, qcdr(c));
    pop(a);
    errexit();
    a = cons(a, w);
    errexit();
    return onevalue(a);
}

/* #endif */

Lisp_Object Lsublis(Lisp_Object nil, Lisp_Object al, Lisp_Object x)
{
    stackcheck2(0, al, x);
    errexit();
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__)) return aerror("sublis");
#endif
    push5(al, x, al, nil, nil);
#define carx stack[0]
#define cdrx stack[-1]
#define w    stack[-2]
#define x    stack[-3]
#define al   stack[-4]
    for (;;)
    {   if (!consp(w))
        {   if (!consp(x))
            {   Lisp_Object temp = x;
                popv(5);
                return temp;
            }
            carx = Lsublis(nil, al, qcar(x));
            errexitn(5);
            cdrx = Lsublis(nil, al, qcdr(x));
            errexitn(5);
            if (carx == qcar(x) && cdrx == qcdr(x))
            {   Lisp_Object temp = x;
                popv(5);
                return temp;
            }
            else
            {   Lisp_Object a1 = carx, a2 = cdrx;
                popv(5);
                return cons(a1, a2);
            }
        }
        {   Lisp_Object temp = qcar(w);
            if (consp(temp))
            {   Lisp_Object v = qcar(temp);
#ifdef COMMON
                if (cl_equal(v, x))
#else
                if (equal(v, x))
#endif
                {   temp = qcdr(temp);
                    popv(5);
                    return temp;
                }
            }
        }
        w = qcdr(w);
    }
}
#undef carx
#undef cdrx
#undef w
#undef x
#undef al

Lisp_Object Lsubla(Lisp_Object nil, Lisp_Object al, Lisp_Object x)
/*
 * as sublis, but uses eq test rather than equal
 */
{
    stackcheck2(0, al, x);
    errexit();
#ifdef CHECK_STACK
    if (check_stack(__FILE__,__LINE__)) return aerror("subla");
#endif
    push5(al, x, al, nil, nil);
#define carx stack[0]
#define cdrx stack[-1]
#define w    stack[-2]
#define x    stack[-3]
#define al   stack[-4]
    for (;;)
    {   if (!consp(w))
        {   if (!consp(x))
            {   Lisp_Object temp = x;
                popv(5);
                return temp;
            }
            carx = Lsubla(nil, al, qcar(x));
            errexitn(5);
            cdrx = Lsubla(nil, al, qcdr(x));
            errexitn(5);
            if (carx == qcar(x) && cdrx == qcdr(x))
            {   Lisp_Object temp = x;
                popv(5);
                return temp;
            }
            else
            {   Lisp_Object a1 = carx, a2 = cdrx;
                popv(5);
                return cons(a1, a2);
            }
        }
        {   Lisp_Object temp = qcar(w);
            if (consp(temp))
            {   Lisp_Object v = qcar(temp);
                if (v == x) { temp = qcdr(temp); popv(5); return temp; }
            }
        }
        w = qcdr(w);
    }
}
#undef carx
#undef cdrx
#undef w
#undef x
#undef al

setup_type const funcs2_setup[] =
{
    {"assoc",                   too_few_2, Lassoc, wrong_no_2},
/*
 * assoc** is expected to remain as the Standard Lisp version even if in
 * a Common Lisp world I redefine assoc to be someting messier. xassoc was
 * an earlier name I used for the same purpose, and is being withdrawn.
 */
    {"assoc**",                 too_few_2, Lassoc, wrong_no_2},
    {"xassoc",                  too_few_2, Lassoc, wrong_no_2},
    {"atsoc",                   too_few_2, Latsoc, wrong_no_2},
    {"member",                  too_few_2, Lmember, wrong_no_2},
    {"member**",                too_few_2, Lmember, wrong_no_2},
    {"memq",                    too_few_2, Lmemq, wrong_no_2},
    {"contained",               too_few_2, Lcontained, wrong_no_2},
    {"restart-csl",             Lrestart_csl, Lrestart_csl2, wrong_no_1},
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
    {"make-native",             Lget_native, too_many_1, wrong_no_1},
    {"symbol-env",              Lsymbol_env, too_many_1, wrong_no_1},
    {"symbol-make-fastget",     Lsymbol_make_fastget1, Lsymbol_make_fastget, wrong_no_2},
    {"symbol-fastgets",         Lsymbol_fastgets, too_many_1, wrong_no_1},
    {"symbol-fn-cell",          Lsymbol_fn_cell, too_many_1, wrong_no_1},
    {"symbol-argcode",          Lsymbol_argcount, too_many_1, wrong_no_1},
    {"symbol-restore-fns",      Lsymbol_restore_fns, too_many_1, wrong_no_1},
    {"symbol-argcount",         Lsymbol_argcount, too_many_1, wrong_no_1},
    {"symbol-set-env",          too_few_2, Lsymbol_set_env, wrong_no_2},
    {"symbol-set-native",       wrong_no_na, wrong_no_nb, Lsymbol_set_native},
    {"symbol-set-definition",   too_few_2, Lsymbol_set_definition, wrong_no_2},
    {"restore-c-code",          Lrestore_c_code, too_many_1, wrong_no_1},
    {"set-autoload",            too_few_2, Lset_autoload, wrong_no_2},
    {"remd",                    Lremd, too_many_1, wrong_no_1},
    {"trace",                   Ltrace, too_many_1, wrong_no_1},
#ifdef JIT
    {"jit",                     Ljit, too_many_1, wrong_no_1},
#endif
    {"untrace",                 Luntrace, too_many_1, wrong_no_1},
    {"trace-all",               Ltrace_all, too_many_1, wrong_no_1},
    {"double-execute",          Ldouble, too_many_1, wrong_no_1},
    {"undouble-execute",        Lundouble, too_many_1, wrong_no_1},
    {"macro-function",          Lmacro_function, too_many_1, wrong_no_1},
    {"symbol-name",             Lsymbol_name, too_many_1, wrong_no_1},
    {"plist",                   Lplist, too_many_1, wrong_no_1},
    {"delete",                  too_few_2, Ldelete, wrong_no_2},
    {"deleq",                   too_few_2, Ldeleq, wrong_no_2},
    {"preserve",                Lpreserve_1, Lpreserve, Lpreserve_0},
    {"checkpoint",              Lcheckpoint_1, Lcheckpoint, Lcheckpoint_0},
    {"mkvect",                  Lmkvect, too_many_1, wrong_no_1},
    {"nconc",                   too_few_2, Lnconc, wrong_no_2},
    {"neq",                     too_few_2, Lneq, wrong_no_2},
    {"not",                     Lnull, too_many_1, wrong_no_1},
    {"null",                    Lnull, too_many_1, wrong_no_1},
    {"resource-exceeded",       wrong_no_0a, wrong_no_0b, Lresource_exceeded},
    {"reverse",                 Lreverse, too_many_1, wrong_no_1},
    {"reversip",                Lnreverse, Lnreverse2, wrong_no_1},
/* I make the name nreverse generally available as well as reversip */
    {"nreverse",                Lnreverse, Lnreverse2, wrong_no_1},
    {"smemq",                   too_few_2, Lsmemq, wrong_no_2},
    {"subla",                   too_few_2, Lsubla, wrong_no_2},
    {"sublis",                  too_few_2, Lsublis, wrong_no_2},
    {"subst",                   wrong_no_3a, wrong_no_3b, Lsubst},
    {"symbol-protect",          too_few_2, Lsymbol_protect, wrong_no_2},
#ifdef COMMON
    {"symbol-package",          Lsymbol_package, too_many_1, wrong_no_1},
    {"symbol-plist",            Lplist, too_many_1, wrong_no_1},
    {"append",                  Lappend_1, Lappend, Lappend_n},
/*
 * In Common Lisp mode I make EQUAL do what Common Lisp says it should, but
 * also have EQUALS that is much the same but which also descends vectors.
 */
    {"equal",                   too_few_2, Lcl_equal, wrong_no_2},
    {"equals",                  too_few_2, Lequal, wrong_no_2},
    {"nreverse0",               Lnreverse0, too_many_1, wrong_no_1},
#else
    {"append",                  too_few_2, Lappend, wrong_no_2},
/* In Standard Lisp mode EQUAL descends vectors (but does not case fold) */
/* I provide cl-equal to do what Common Lisp does.                       */
    {"cl-equal",                too_few_2, Lcl_equal, wrong_no_2},
    {"equal",                   too_few_2, Lequal, wrong_no_2},
    {"member",                  too_few_2, Lmember, wrong_no_2},
#endif
    {NULL,                      0, 0, 0}
};

/* end of fns2.c */
