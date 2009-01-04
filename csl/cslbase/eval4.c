/* eval4.c                           Copyright (C) 1991-2008, Codemist Ltd */

/*
 * Bytecode interpreter/main interpreter interfaces
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



/* Signature: 4eebc042 04-Jan-2009 */

#include "headers.h"



#ifdef DEBUG
int trace_all = 0;
#endif

#define name_from(def) elt(qcdr(def), 0)

Lisp_Object MS_CDECL bytecoded0(Lisp_Object def, int nargs, ...)
{
    Lisp_Object nil=C_nil;
    if (nargs != 0) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32_t)nargs));
    push2(litvec, codevec);
    stackcheck1(2, def);
/*
 * The "-2" a few lines down is discussed in the file bytes1.c. It is
 * part of the mechanism for allowing functions to have a few data bytes
 * at the start of the code-vector.
 */
#ifdef DEBUG
    if (trace_all)
    {   trace_all = 0;
        push(def);
        freshline_trace();
        trace_printf("Entering ");
        loop_print_trace(name_from(def));
        trace_printf(" (no args)");
        if (callstack != nil)
        {   trace_printf(" from ");
/*/*
 * The following line is not garbage-collector safe, and similarly for the
 * other places I print trace output involving callstack. But since it is
 * just for use when debugging I will be sloppy about that just for now!
 */
            loop_print_trace(qcar(callstack));
        }
        trace_printf("\n");
        trace_all = 1;
        nil = C_nil;
        if (exception_pending()) { popv(3); return nil; }
        pop(def);
    }
#endif
    def = bytestream_interpret(qcar(def)-2, qcdr(def), stack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return def;
}

Lisp_Object bytecoded1(Lisp_Object def, Lisp_Object a)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    push3(litvec, codevec, a);
    stackcheck1(3, def);
#ifdef DEBUG
    if (trace_all)
    {   trace_all = 0;
        push(def);
        freshline_trace();
        trace_printf("Entering ");
        loop_print_trace(name_from(def));
        if (callstack != nil)
        {   trace_printf(" from ");
            loop_print_trace(qcar(callstack));
        }
        trace_printf("\nArg1: ");
        loop_print_trace(stack[-1]);
        trace_printf("\n");
        trace_all = 1;
        nil = C_nil;
        if (exception_pending()) { popv(4); return nil; }
        pop(def);
    }
#endif
    r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-1);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
/*
 * If bytestream_interpret handed back a failure code then the VERY LAST
 * thing that it did was to move stack down, in effect losing the argument
 * that had been passed to the bytesteam code.  But nothing can touch the
 * stack between that action and here, so if I quickly increment the
 * stack pointer again I can find the argument again - or at least whetever
 * value the failed function left in that variable.  Yes this does look
 * a little delicate, but I do like seeing argument values in my backtraces,
 * and the software stack involved here it totally under my control.
 * NOTE however that if the function I am calling here does a tail call
 * to something that is not directly bytecoded then the stack can be
 * clobbered, and the results will be garbage in the backtrace.
 */
        stack++;
        pop3(a, codevec, litvec); 
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg1: ");
            loop_print_error(a); err_printf("\n");
            ignore_exception();
        }
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object bytecoded2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    push4(litvec, codevec, a, b);
    stackcheck1(4, def);
#ifdef DEBUG
    if (trace_all)
    {   trace_all = 0;
        push(def);
        freshline_trace();
        trace_printf("Entering ");
        loop_print_trace(name_from(def));
        if (callstack != nil)
        {   trace_printf(" from ");
            loop_print_trace(qcar(callstack));
        }
        trace_printf("\nArg1: ");
        loop_print_trace(stack[-2]);
        trace_printf("\n");
        trace_printf("Arg2: ");
        loop_print_trace(stack[-1]);
        trace_printf("\n");
        trace_all = 1;
        nil = C_nil;
        if (exception_pending()) { popv(5); return nil; }
        pop(def);
    }
#endif
    r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-2);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += 2;
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg 1: ");
            loop_print_error(stack[-1]); err_printf("\n");
            ignore_exception();
            err_printf("Arg 2: ");
            loop_print_error(stack[0]); err_printf("\n");
            ignore_exception();
        }
        popv(2); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL bytecoded3(Lisp_Object def, int nargs, ...)
{
    va_list aa;
    Lisp_Object r, a, b, c;
    Lisp_Object nil = C_nil;
    if (nargs != 3) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32_t)nargs));
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    c = va_arg(aa, Lisp_Object);
    va_end(aa);
    push5(litvec, codevec, a, b, c);
    stackcheck1(5, def);
#ifdef DEBUG
    if (trace_all)
    {   trace_all = 0;
        push(def);
        freshline_trace();
        trace_printf("Entering ");
        loop_print_trace(name_from(def));
        if (callstack != nil)
        {   trace_printf(" from ");
            loop_print_trace(qcar(callstack));
        }
        trace_printf("\nArg1: ");
        loop_print_trace(stack[-3]);
        trace_printf("\n");
        trace_printf("Arg2: ");
        loop_print_trace(stack[-2]);
        trace_printf("\n");
        trace_printf("Arg3: ");
        loop_print_trace(stack[-1]);
        trace_printf("\n");
        trace_all = 1;
        nil = C_nil;
        if (exception_pending()) { popv(6); return nil; }
        pop(def);
    }
#endif
    r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-3);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += 3;
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-2]); err_printf("\n");
            ignore_exception();
            err_printf("Arg2: ");
            loop_print_error(stack[-1]); err_printf("\n");
            ignore_exception();
            err_printf("Arg3: ");
            loop_print_error(stack[0]); err_printf("\n");
            ignore_exception();
        }
        popv(3); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL bytecodedn(Lisp_Object def, int nargs, ...)
{
/*
 * The messing about here is to get the (unknown number of) args
 * into a nice neat vector so that they can be indexed into. If I knew
 * that the args were in consecutive locations on the stack I could
 * probably save a copying operation.
 */
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i;
    Lisp_Object *stack_save = stack;
    va_list a;
    push2(litvec, codevec);
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    if (nargs != ((unsigned char *)data_of_bps(r))[0])
    {   popv(nargs+2);
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    r = bytestream_interpret(r-1, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
/*
 * Note that in this display if a function had over 50 args then the
 * final bunch of them will be bundled up in to a list (as if for &rest).
 */
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

/*
 * Now I have carbon copies of the above, but with some print statements
 * inserted.  These are installed when a function is marked for trace
 * output.
 */

Lisp_Object unpack_mv(Lisp_Object nil, Lisp_Object r)
{
    Lisp_Object *p = &mv_1;
    exit_count = 0;
    *p = nil;
    while (r != nil)
    {   *p++ = qcar(r);
        r = qcdr(r);
        exit_count++;
    }
    return mv_1;
}

Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object def, int nargs, ...)
{
    Lisp_Object r, nil=C_nil;
    if (nargs != 0) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32_t)nargs));
    push3(litvec, codevec, def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    trace_printf(" (no args)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
    trace_printf("\n");
    nil = C_nil;
    if (exception_pending()) { popv(3); return nil; }
    def = stack[0];
    r = bytestream_interpret(qcar(def)-2, qcdr(def), stack);
    nil = C_nil;
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#ifdef COMMON
    r = Lmv_list(nil, r);
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#endif
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    nil = C_nil;
    if (!exception_pending())
    {   trace_printf(" = ");
        loop_print_trace(r);
        trace_printf("\n");
    }
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop3(r, codevec, litvec);
#ifdef COMMON
    r = unpack_mv(nil, r);
#endif
    return r;
}

Lisp_Object tracebytecoded1(Lisp_Object def, Lisp_Object a)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    push4(litvec, codevec, def, a);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(2); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    trace_printf(" (1 arg)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
    trace_printf("\nArg1: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(2); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    stackcheck0(4);
    def = stack[-1];
    r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-1);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack++;
        pop(a); popv(1); pop2(codevec, litvec);
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg1: ");
            loop_print_error(a); err_printf("\n");
            ignore_exception();
        }
        flip_exception();
        return nil;
    }
#ifdef COMMON
    r = Lmv_list(nil, r);
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#endif
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop3(r, codevec, litvec);
#ifdef COMMON
    r = unpack_mv(nil, r);
#endif
    return r;
}

Lisp_Object tracebytecoded2(Lisp_Object def,
                        Lisp_Object a, Lisp_Object b)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    push5(litvec, codevec, def, a, b);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(3); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    trace_printf(" (2 args)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
    trace_printf("\nArg1: ");
    loop_print_trace(stack[-1]);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(3); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    trace_printf("\nArg2: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(3); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    stackcheck0(5);
    def = stack[-2];
    r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-2);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += 2;
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-1]); err_printf("\n");
            ignore_exception();
            err_printf("Arg2: ");
            loop_print_error(stack[0]); err_printf("\n");
            ignore_exception();
        }
        popv(3); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#ifdef COMMON
    r = Lmv_list(nil, r);
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#endif
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop3(r, codevec, litvec);
#ifdef COMMON
    r = unpack_mv(nil, r);
#endif
    return r;
}

Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object def, int nargs, ...)
{
    va_list aa;
    Lisp_Object r, a, b, c;
    Lisp_Object nil = C_nil;
    if (nargs != 3) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32_t)nargs));
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    c = va_arg(aa, Lisp_Object);
    va_end(aa);
    push2(litvec, codevec);
    push4(def, a, b, c);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(4); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    trace_printf(" (3 args)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
    trace_printf("\nArg1: ");
    loop_print_trace(stack[-2]);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(4); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    trace_printf("\nArg2: ");
    loop_print_trace(stack[-1]);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(4); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    trace_printf("\nArg3: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        popv(4); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    stackcheck0(6);
    def = stack[-3];
    r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-3);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += 3;
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-2]); err_printf("\n");
            ignore_exception();
            err_printf("Arg2: ");
            loop_print_error(stack[-1]); err_printf("\n");
            ignore_exception();
            err_printf("Arg3: ");
            loop_print_error(stack[0]); err_printf("\n");
            ignore_exception();
        }
        popv(4); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#ifdef COMMON
    r = Lmv_list(nil, r);
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#endif
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop3(r, codevec, litvec);
#ifdef COMMON
    r = unpack_mv(nil, r);
#endif
    return r;
}

Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object def, int nargs, ...)
{
/*
 * The messing about here is to get the (unknown number of) args
 * into a nice neat vector so that they can be indexed into. If I knew
 * that the args were in consecutive locations on the stack I could
 * probably save a copying operation.
 */
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i;
    Lisp_Object *stack_save = stack;
    va_list a;
    push3(litvec, codevec, def);
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" (%d args)", nargs);
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    def = stack[-nargs];
    r = qcar(def);
    if (nargs != ((unsigned char *)data_of_bps(r))[0])
    {   popv(nargs+3);
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    r = bytestream_interpret(r-1, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs+1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#ifdef COMMON
    r = Lmv_list(nil, r);
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#endif
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop3(r, codevec, litvec);
#ifdef COMMON
    r = unpack_mv(nil, r);
#endif
    return r;
}

int doubled_execution = 0;

Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object def, int nargs, ...)
{
    Lisp_Object nil=C_nil;
    if (nargs != 0) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32_t)nargs));
    push2(litvec, codevec);
    stackcheck1(2, def);
    if (!doubled_execution)
    {   push3(def, litvec, codevec);
        doubled_execution = 1;
        bytestream_interpret(qcar(def)-2, qcdr(def), stack);
        nil = C_nil;
        pop3(codevec, litvec, def);
        if (!exception_pending())
            def = bytestream_interpret(qcar(def)-2, qcdr(def), stack);
        doubled_execution = 0;
    }
    else def = bytestream_interpret(qcar(def)-2, qcdr(def), stack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return def;
}

Lisp_Object double_bytecoded1(Lisp_Object def, Lisp_Object a)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    push3(litvec, codevec, a);
    stackcheck1(3, def);
    if (!doubled_execution)
    {   push4(def, litvec, codevec, a);
        doubled_execution = 1;
        r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-1);
        nil = C_nil;
        pop3(codevec, litvec, def);
        if (!exception_pending())
            r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-1);
        doubled_execution = 0;
    }
    else r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-1);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack++;
        pop3(a, codevec, litvec); 
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg1: ");
            loop_print_error(a); err_printf("\n");
            ignore_exception();
        }
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object double_bytecoded2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    push4(litvec, codevec, a, b);
    stackcheck1(4, def);
    if (!doubled_execution)
    {   push5(def, litvec, codevec, a, b);
        doubled_execution = 1;
        r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-2);
        nil = C_nil;
        pop3(codevec, litvec, def);
        if (!exception_pending())
            r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-2);
        doubled_execution = 0;
    }
    else r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-2);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += 2;
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg 1: ");
            loop_print_error(stack[-1]); err_printf("\n");
            ignore_exception();
            err_printf("Arg 2: ");
            loop_print_error(stack[0]); err_printf("\n");
            ignore_exception();
        }
        popv(2); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object def, int nargs, ...)
{
    va_list aa;
    Lisp_Object r, a, b, c;
    Lisp_Object nil = C_nil;
    if (nargs != 3) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32_t)nargs));
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    c = va_arg(aa, Lisp_Object);
    va_end(aa);
    push5(litvec, codevec, a, b, c);
    stackcheck1(5, def);
    if (!doubled_execution)
    {   push6(def, litvec, codevec, a, b, c);
        doubled_execution = 1;
        r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-3);
        nil = C_nil;
        pop3(codevec, litvec, def);
        if (!exception_pending())
            r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-3);
        doubled_execution = 0;
    }
    else r = bytestream_interpret(qcar(def)-2, qcdr(def), stack-3);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += 3;
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-2]); err_printf("\n");
            ignore_exception();
            err_printf("Arg2: ");
            loop_print_error(stack[-1]); err_printf("\n");
            ignore_exception();
            err_printf("Arg3: ");
            loop_print_error(stack[0]); err_printf("\n");
            ignore_exception();
        }
        popv(3); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object def, int nargs, ...)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i;
    Lisp_Object *stack_save = stack;
    va_list a;
    push2(litvec, codevec);
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    if (nargs != ((unsigned char *)data_of_bps(r))[0])
    {   popv(nargs+2);
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    trace_printf("Function with > 3 args not doubled\n");
    r = bytestream_interpret(r-1, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}


/*
 * The code that follows is just used to support compiled code that
 * has &optional or &rest arguments.
 */

Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a)
{
    return byteoptn(def, 1, a);
}

Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return byteoptn(def, 2, a, b);
}

static Lisp_Object vbyteoptn(Lisp_Object def, int nargs,
                             va_list a, Lisp_Object dflt)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i, wantargs, wantopts;
    Lisp_Object *stack_save = stack;
    push2(litvec, codevec);
/*
 * Maybe I should raise an exception (continuable error) if too many args
 * are provided - for now I just silently ignore the excess.
 */
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs || nargs > wantargs+wantopts)
    {   popv(nargs); pop2(codevec, litvec)
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   /* Provide value for all optional args */
        nargs++;
    }
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    r = bytestream_interpret(r, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vbyteoptn(def, nargs, a, C_nil);
}

Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a)
{
    return hardoptn(def, 1, a);
}

Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return hardoptn(def, 2, a, b);
}

Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vbyteoptn(def, nargs, a, SPID_NOARG);
}

Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a)
{
    return byteoptrestn(def, 1, a);
}

Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return byteoptrestn(def, 2, a, b);
}

static Lisp_Object vbyterestn(Lisp_Object def, int nargs,
                              va_list a, Lisp_Object dflt)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i, wantargs, wantopts;
    Lisp_Object *stack_save = stack;
    push2(litvec, codevec);
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs)
    {   popv(nargs+2);
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   /* Provide value for all optional args */
        nargs++;
    }
    {   Lisp_Object rest = nil;
        while (nargs > wantargs+wantopts)
        {   Lisp_Object w = stack[0];
            stack[0] = def;
            rest = cons(w, rest);
            errexitn(nargs+2);
            pop(def);
            nargs--;
        }
        push(rest);
        nargs++;
    }
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    r = bytestream_interpret(r, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vbyterestn(def, nargs, a, C_nil);
}

Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a)
{
    return hardoptrestn(def, 1, a);
}

Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return hardoptrestn(def, 2, a, b);
}

Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vbyterestn(def, nargs, a, SPID_NOARG);
}

/*
 * Next the execution-doubling versions of the &opt/&rest interfaces
 */

Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a)
{
    return double_byteoptn(def, 1, a);
}

Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return double_byteoptn(def, 2, a, b);
}

static Lisp_Object double_vbyteoptn(Lisp_Object def, int nargs,
                             va_list a, Lisp_Object dflt)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i, wantargs, wantopts;
    Lisp_Object *stack_save = stack;
    push2(litvec, codevec);
/*
 * Maybe I should raise an exception (continuable error) if too many args
 * are provided - for now I just silently ignore th excess.
 */
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs || nargs > wantargs+wantopts)
    {   popv(nargs); pop2(codevec, litvec)
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   /* Provide value for all optional args */
        nargs++;
    }
    stackcheck1(stack-stack_save, def);
    trace_printf("Function with simple &opt arg not doubled\n");
    r = qcar(def);
    r = bytestream_interpret(r, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return double_vbyteoptn(def, nargs, a, C_nil);
}

Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a)
{
    return double_hardoptn(def, 1, a);
}

Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return double_hardoptn(def, 2, a, b);
}

Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return double_vbyteoptn(def, nargs, a, SPID_NOARG);
}

Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a)
{
    return double_byteoptrestn(def, 1, a);
}

Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return double_byteoptrestn(def, 2, a, b);
}

static Lisp_Object double_vbyterestn(Lisp_Object def, int nargs,
                              va_list a, Lisp_Object dflt)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i, wantargs, wantopts;
    Lisp_Object *stack_save = stack;
    push2(litvec, codevec);
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs)
    {   popv(nargs+2);
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   /* Provide value for all optional args */
        nargs++;
    }
    {   Lisp_Object rest = nil;
        while (nargs > wantargs+wantopts)
        {   Lisp_Object w = stack[0];
            stack[0] = def;
            rest = cons(w, rest);
            errexitn(nargs+2);
            pop(def);
            nargs--;
        }
        push(rest);
        nargs++;
    }
    stackcheck1(stack-stack_save, def);
    trace_printf("Function with simple &rest arg not doubled\n");
    r = qcar(def);
    r = bytestream_interpret(r, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop2(codevec, litvec);
    return r;
}

Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return double_vbyterestn(def, nargs, a, C_nil);
}

Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a)
{
    return double_hardoptrestn(def, 1, a);
}

Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return double_hardoptrestn(def, 2, a, b);
}

Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return double_vbyterestn(def, nargs, a, SPID_NOARG);
}

Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a)
{
    return tracebyteoptn(def, 1, a);
}

Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return tracebyteoptn(def, 2, a, b);
}

static Lisp_Object vtracebyteoptn(Lisp_Object def, int nargs,
                             va_list a, Lisp_Object dflt)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i, wantargs, wantopts;
    Lisp_Object *stack_save = stack;
    push3(litvec, codevec, def);
/*
 * Maybe I should raise an exception (continuable error) if too many args
 * are provided - for now I just silently ignore th excess.
 */
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs || nargs > wantargs+wantopts)
    {   popv(nargs+1); pop2(codevec, litvec)
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   /* Provide value for all optional args */
        nargs++;
    }
    stackcheck1(stack-stack_save, def);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" (%d args)", nargs);
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    def = stack[-nargs];
    r = qcar(def);
    r = bytestream_interpret(r, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs+1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#ifdef COMMON
    r = Lmv_list(nil, r);
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#endif
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    nil = C_nil;
    if (!exception_pending())
    {   trace_printf(" = ");
        loop_print_trace(r);
        trace_printf("\n");
    }
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop3(r, codevec, litvec);
#ifdef COMMON
    r = unpack_mv(nil, r);
#endif
    return r;
}

Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vtracebyteoptn(def, nargs, a, C_nil);
}

Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a)
{
    return tracehardoptn(def, 1, a);
}

Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return tracehardoptn(def, 2, a, b);
}

Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vtracebyteoptn(def, nargs, a, SPID_NOARG);
}

Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a)
{
    return tracebyteoptrestn(def, 1, a);
}

Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return tracebyteoptrestn(def, 2, a, b);
}

static Lisp_Object vtracebyterestn(Lisp_Object def, int nargs,
                              va_list a, Lisp_Object dflt)
{
    Lisp_Object r;
    Lisp_Object nil = C_nil;
    int i, wantargs, wantopts;
    Lisp_Object *stack_save = stack;
    push3(litvec, codevec, def);
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    stackcheck1(stack-stack_save, def);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs)
    {   popv(nargs+2);
        return error(2, err_wrong_no_args, name_from(def),
                        fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   /* Provide value for all optional args */
        nargs++;
    }
    {   Lisp_Object rest = nil;
        while (nargs > wantargs+wantopts)
        {   Lisp_Object w = stack[0];
            stack[0] = def;
            rest = cons(w, rest);
            errexitn(nargs+2);
            pop(def);
            nargs--;
        }
        push(rest);
        nargs++;
    }
    stackcheck1(stack-stack_save, def);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" (%d args)", nargs);
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    def = stack[-nargs];
    r = qcar(def);
    r = bytestream_interpret(r, qcdr(def), stack-nargs);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        stack += nargs;
        if ((exit_reason & UNWIND_ERROR) != 0)
        for (i=1; i<=nargs; i++)
        {   err_printf("Arg%d: ", i);
            loop_print_error(stack[i-nargs]); err_printf("\n");
            ignore_exception();
        }
        popv(nargs+1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#ifdef COMMON
    r = Lmv_list(nil, r);
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
#endif
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    nil = C_nil;
    if (!exception_pending())
    {   trace_printf(" = ");
        loop_print_trace(r);
        trace_printf("\n");
    }
    if (exception_pending()) 
    {   flip_exception();
        popv(1); pop2(codevec, litvec);
        flip_exception();
        return nil;
    }
    pop3(r, codevec, litvec);
#ifdef COMMON
    r = unpack_mv(nil, r);
#endif
    return r;
}

Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vtracebyterestn(def, nargs, a, C_nil);
}

Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a)
{
    return tracehardoptrestn(def, 1, a);
}

Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    return tracehardoptrestn(def, 2, a, b);
}

Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...)
{
    va_list a;
    va_start(a, nargs);
    return vtracebyterestn(def, nargs, a, SPID_NOARG);
}

static Lisp_Object Lis_spid(Lisp_Object nil, Lisp_Object a)
{   /* Used in compilation for optional args */
    return onevalue(Lispify_predicate(is_spid(a)));
}

static Lisp_Object Lspid_to_nil(Lisp_Object nil, Lisp_Object a)
{   /* Used in compilation for optional args */
    if (is_spid(a)) a = nil;
    return onevalue(a);
}

static Lisp_Object MS_CDECL Lload_spid(Lisp_Object nil, int nargs, ...)
{   /* Used in compilation of UNWIND-PROTECT */
    CSL_IGNORE(nil);
    CSL_IGNORE(nargs);
    return onevalue(SPID_PROTECT);
}

Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a)
/*
 * This does a (multiple-value-list A) on just one form.  It must be used
 * carefully so that the value-count information does not get lost between
 * the evaluation of A and calling this code.
 */
{
#ifdef COMMON
    Lisp_Object r, *save_stack = stack;
    int i, x = exit_count;
    stackcheck1(0, a);
    if (x > 0) push(a);
    for (i=2; i<=x; i++) push((&work_0)[i]);
    r = nil;
    for (i=0; i<x; i++)
    {   Lisp_Object w;
        pop(w);
        r = cons(w, r);
        nil = C_nil;
        if (exception_pending())
        {   stack = save_stack;
            return nil;
        }
    }
    return onevalue(r);
#else
    CSL_IGNORE(nil);
    return ncons(a);
#endif
}

/*
 * In these tables there are some functions that would need adjusting
 * for a Common Lisp compiler, since they take different numbers of
 * args in Common and Standard Lisp.
 * This means, to be specific:
 *
 *  Lgensym     Lread       Latan       Ltruncate   Lfloat
 *  Lintern     Lmacroexpand            Lmacroexpand_1
 *  Lrandom     Lunintern   Lappend     Leqn        Lgcd
 *  Lgeq        Lgreaterp   Llcm        Lleq        Llessp
 *  Lquotient
 *
 * In these cases (at least!) the Common Lisp version of the compiler will
 * need to avoid generating the call that uses this table.
 *
 * Some functions are missing from the list here because they seemed
 * critical enough to be awarded single-byte opcodes or because the
 * compiler always expands them away - car through cddddr are the main
 * cases, together with eq and equal.
 */


n_args *zero_arg_functions[] =
{
    Lbatchp,                /* 0 */
    Ldate,                  /* 1 */
    Leject,                 /* 2 */
    Lerror0,                /* 3 */
    Lgctime,                /* 4 */
    Lgensym,                /* 5 */
    Llposn,                 /* 6 */
    Lnext_random,           /* 7 */
    Lposn,                  /* 8 */
    Lread,                  /* 9 */
    Lreadch,                /* 10 */
    Lterpri,                /* 11 */
    Ltime,                  /* 12 */
    Ltyi,                   /* 13 */
    Lload_spid,             /* 14 */  /* ONLY used in compiled code */
    NULL
};

one_args *one_arg_functions[] =
{
    Labsval,                /* 0 */
    Ladd1,                  /* 1 */
    Latan,                  /* 2 */
    Lapply0,                /* 3 */
    Latom,                  /* 4 */
    Lboundp,                /* 5 */
    Lchar_code,             /* 6 */
    Lclose,                 /* 7 */
    Lcodep,                 /* 8 */
    Lcompress,              /* 9 */
    Lconstantp,             /* 10 */
    Ldigitp,                /* 11 */
    Lendp,                  /* 12 */
    Leval,                  /* 13 */
    Levenp,                 /* 14 */
    Levlis,                 /* 15 */
    Lexplode,               /* 16 */
    Lexplode2lc,            /* 17 */
    Lexplodec,              /* 18 */
    Lfixp,                  /* 19 */
    Lfloat,                 /* 20 */
    Lfloatp,                /* 21 */
    Lsymbol_specialp,       /* 22 */
    Lgc,                    /* 23 */
    Lgensym1,               /* 24 */
    Lgetenv,                /* 25 */
    Lsymbol_globalp,        /* 26 */
    Liadd1,                 /* 27 */
    Lsymbolp,               /* 28 */
    Liminus,                /* 29 */
    Liminusp,               /* 30 */
    Lindirect,              /* 31 */
    Lintegerp,              /* 32 */
    Lintern,                /* 33 */
    Lisub1,                 /* 34 */
    Llength,                /* 35 */
    Llengthc,               /* 36 */
    Llinelength,            /* 37 */
    Lalpha_char_p,          /* 38 */
    Lload_module,           /* 39 */
    Llognot,                /* 40 */
    Lmacroexpand,           /* 41 */
    Lmacroexpand_1,         /* 42 */
    Lmacro_function,        /* 43 */
    Lget_bps,               /* 44 */
    Lmake_global,           /* 45 */
    Lsmkvect,               /* 46 */
    Lmake_special,          /* 47 */
    Lminus,                 /* 48 */
    Lminusp,                /* 49 */
    Lmkvect,                /* 50 */
    Lmodular_minus,         /* 51 */
    Lmodular_number,        /* 52 */
    Lmodular_reciprocal,    /* 53 */
    Lnull,                  /* 54 */
    Loddp,                  /* 55 */
    Lonep,                  /* 56 */
    Lpagelength,            /* 57 */
    Lconsp,                 /* 58 */
    Lplist,                 /* 59 */
    Lplusp,                 /* 60 */
    Lprin,                  /* 61 */
    Lprinc,                 /* 62 */
    Lprint,                 /* 63 */
    Lprintc,                /* 64 */
    Lrandom,                /* 65 */
    Lrational,              /* 66 */
    Lrdf1,                  /* 67 */
    Lrds,                   /* 68 */
    Lremd,                  /* 69 */
    Lreverse,               /* 70 */
    Lnreverse,              /* 71 */
    Lwhitespace_char_p,     /* 72 */
    Lset_small_modulus,     /* 73 */
    Lxtab,                  /* 74 */
    Lspecial_char,          /* 75 */
    Lspecial_form_p,        /* 76 */
    Lspool,                 /* 77 */
    Lstop,                  /* 78 */
    Lstringp,               /* 79 */
    Lsub1,                  /* 80 */
    Lsymbol_env,            /* 81 */
    Lsymbol_function,       /* 82 */
    Lsymbol_name,           /* 83 */
    Lsymbol_value,          /* 84 */
    Lsystem,                /* 85 */
    Ltruncate,              /* 86 */
    Lttab,                  /* 87 */
    Ltyo,                   /* 88 */
    Lunintern,              /* 89 */
    Lunmake_global,         /* 90 */
    Lunmake_special,        /* 91 */
    Lupbv,                  /* 92 */
    Lsimple_vectorp,        /* 93 */
    Lverbos,                /* 94 */
    Lwrs,                   /* 95 */
    Lzerop,                 /* 96 */
    Lcar,                   /* 97 */
    Lcdr,                   /* 98 */
    Lcaar,                  /* 99 */
    Lcadr,                  /* 100 */
    Lcdar,                  /* 101 */
    Lcddr,                  /* 102 */
    Lcar,                   /* 103 */   /* Really QCAR (unchecked) */
    Lcdr,                   /* 104 */
    Lcaar,                  /* 105 */
    Lcadr,                  /* 106 */
    Lcdar,                  /* 107 */
    Lcddr,                  /* 108 */
    Lncons,                 /* 109 */
    Lnumberp,               /* 110 */
    Lis_spid,               /* 111 */  /* ONLY used in compiled code */
    Lspid_to_nil,           /* 112 */  /* ONLY used in compiled code */
    Lmv_list,               /* 113 */  /* ONLY used in compiled code */
    NULL
};

two_args *two_arg_functions[] =
{
    Lappend,                /* 0 */
    Lash,                   /* 1 */
    Lassoc,                 /* 2 */
    Latsoc,                 /* 3 */
    Ldeleq,                 /* 4 */
    Ldelete,                /* 5 */
    Ldivide,                /* 6 */
    Leqcar,                 /* 7 */
    Leql,                   /* 8 */
    Leqn,                   /* 9 */
    Lexpt,                  /* 10 */
    Lflag,                  /* 11 */
    Lflagpcar,              /* 12 */
    Lgcd,                   /* 13 */
    Lgeq,                   /* 14 */
    Lgetv,                  /* 15 */
    Lgreaterp,              /* 16 */
    Lidifference,           /* 17 */
    Ligreaterp,             /* 18 */
    Lilessp,                /* 19 */
    Limax,                  /* 20 */
    Limin,                  /* 21 */
    Liplus2,                /* 22 */
    Liquotient,             /* 23 */
    Liremainder,            /* 24 */
    Lirightshift,           /* 25 */
    Litimes2,               /* 26 */
    Llcm,                   /* 27 */
    Lleq,                   /* 28 */
    Llessp,                 /* 29 */
    Lmake_random_state,     /* 30 */
    Lmax2,                  /* 31 */
    Lmember,                /* 32 */
    Lmemq,                  /* 33 */
    Lmin2,                  /* 34 */
    Lmod,                   /* 35 */
    Lmodular_difference,    /* 36 */
    Lmodular_expt,          /* 37 */
    Lmodular_plus,          /* 38 */
    Lmodular_quotient,      /* 39 */
    Lmodular_times,         /* 40 */
    Lnconc,                 /* 41 */
    Lneq,                   /* 42 */
    Lorderp,                /* 43 */
    Lquotient,              /* 44 */
    Lrem,                   /* 45 */
    Lremflag,               /* 46 */
    Lremprop,               /* 47 */
    Lrplaca,                /* 48 */
    Lrplacd,                /* 49 */
    Lsgetv,                 /* 50 */
    Lset,                   /* 51 */
    Lsmemq,                 /* 52 */
    Lsubla,                 /* 53 */
    Lsublis,                /* 54 */
    Lsymbol_set_definition, /* 55 */
    Lsymbol_set_env,        /* 56 */
    Ltimes2,                /* 57 */
    Lxcons,                 /* 58 */
    Lequal,                 /* 59 */
    Leq,                    /* 60 */
    Lcons,                  /* 61 */
    Llist2,                 /* 62 */
    Lget,                   /* 63 */
    Lgetv,                  /* 64 */   /* QGETV */
    Lflagp,                 /* 65 */
    Lapply1,                /* 66 */
    Ldifference2,           /* 67 */
    Lplus2,                 /* 68 */
    Ltimes2,                /* 69 */
    Lequalcar,              /* 70 */
    Leq,                    /* 71 */   /* IEQUAL */
    Lnreverse2,             /* 72 */
    NULL
};

n_args *three_arg_functions[] =
{                         
    Lbpsputv,               /* 0 */
    Lerrorsetn,             /* 1 */
    Llist2star,             /* 2 */
    Llist3,                 /* 3 */
    Lputprop,               /* 4 */
    Lputv,                  /* 5 */
    Lsputv,                 /* 6 */
    Lsubst,                 /* 7 */
    Lapply2,                /* 8 */
    Lacons,                 /* 9 */
    NULL
};

/* end of eval4.c */

