// eval4.cpp                              Copyright (C) 1991-2017, Codemist    

//
// Bytecode interpreter/main interpreter interfaces
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


#define name_from(def) elt(qcdr(def), 0)

// Each of these entrypoints to the bytecode interpreter preserves litvec
// and codevec. Just about the only place these variable are set is within
// the bytecode interpreter.

LispObject bytecoded0(LispObject def, int nargs, ...)
{   if (nargs != 0) error(2, err_wrong_no_args, name_from(def),
                                     fixnum_of_int((int32_t)nargs));
    SAVE_CODEVEC;
    LispObject r;
// I can use START_TRY_BLOCK without "try" if there are not going to be any
// "catch" clauses at this level!
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack);
    }
    return r;
}

LispObject bytecoded1(LispObject def, LispObject a)
{   SAVE_CODEVEC;
    push2(def, a);
    LispObject r;
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-1);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
// START_TRY_BLOCK arranges to preserve the stack pointer and restore it so
// that when I get here it is just as it was at the start of "try".... But
// there is a delicacy! The argument(s) are pushed onto the stack on a
// callee-pops basis, so if I exited successfully they would have been
// discarded. But in the various exceptional exit cases this will probably not
// have happened! There may be some odd consequnces if the function I
// had been invoking did a tail-call and the exception was raised within that,
// since then the arguments for the original function are rather liable to
// have been lost.
        pop(a);
        if (SHOW_ARGS)
        {   err_printf("Arg1: ");
            loop_print_error(a);
            err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
// Note that a destructor set up by SAVE_CODEVEC gets activated here and
// that restores the stack pointer and also values of codevec and litvec.
    return r;
}

LispObject bytecoded2(LispObject def, LispObject a, LispObject b)
{   LispObject r;
    SAVE_CODEVEC;
    push3(def, a, b);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-2);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   err_printf("Arg 1: ");
            loop_print_error(stack[-1]); err_printf("\n");
            err_printf("Arg 2: ");
            loop_print_error(stack[0]); err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject bytecoded3(LispObject def, int nargs, ...)
{   va_list aa;
    LispObject r, a, b, c;
    if (nargs != 3) error(2, err_wrong_no_args, name_from(def),
                                     fixnum_of_int((int32_t)nargs));
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    SAVE_CODEVEC;
    push4(def, a, b, c);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-3);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-2]); err_printf("\n");
            err_printf("Arg2: ");
            loop_print_error(stack[-1]); err_printf("\n");
            err_printf("Arg3: ");
            loop_print_error(stack[0]); err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject bytecodedn(LispObject def, int nargs, ...)
{
//
// The messing about here is to get the (unknown number of) args
// into a nice neat vector so that they can be indexed into. If I knew
// that the args were in consecutive locations on the stack I could
// probably save a copying operation.
//
    LispObject r;
    int i;
    va_list a;
    SAVE_CODEVEC;
    push(def);
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    r = qcar(def);
    if (nargs != ((unsigned char *)data_of_bps(r))[0])
    {   popv(nargs+2);
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+1, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
//
// Note that in this display if a function had over 50 args then the
// final bunch of them will be bundled up in to a list (as if for &rest).
//
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

//
// Now I have carbon copies of the above, but with some print statements
// inserted.  These are installed when a function is marked for trace
// output.
//

LispObject unpack_mv(LispObject env, LispObject r)
{   LispObject *p = &mv_1;
    exit_count = 0;
    *p = nil;
    while (r != nil)
    {   *p++ = qcar(r);
        r = qcdr(r);
        exit_count++;
    }
    return mv_1;
}

LispObject tracebytecoded0(LispObject def, int nargs, ...)
{   LispObject r;
    if (nargs != 0) error(2, err_wrong_no_args, name_from(def),
                                     fixnum_of_int((int32_t)nargs));
    SAVE_CODEVEC;
    push(def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    trace_printf(" (no args)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
#ifndef NO_BYTECOUNT
    else if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = stack[0];
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack);
    }
// This, or possibly I could EITHER
//    (a) ensure that printing trace info never disrupts multiple value
//        information
// OR (b) stack all values, not just one of them.
    r = Lmv_list(nil, r);
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop3(r, codevec, litvec);
    return unpack_mv(nil, r);
}

LispObject tracebytecoded1(LispObject def, LispObject a)
{   LispObject r;
    SAVE_CODEVEC;
    push2(def, a);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    trace_printf(" (1 arg)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
#ifndef NO_BYTECOUNT
    else if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\nArg1: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    def = stack[-1];
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-1);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   err_printf("Arg1: ");
            pop(a);
            loop_print_error(a); err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
    r = Lmv_list(nil, r);
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return unpack_mv(nil, r);
}

LispObject tracebytecoded2(LispObject def,
                           LispObject a, LispObject b)
{   LispObject r;
    SAVE_CODEVEC;
    push3(def, a, b);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    trace_printf(" (2 args)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
#ifndef NO_BYTECOUNT
    else if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\nArg1: ");
    loop_print_trace(stack[-1]);
    trace_printf("\nArg2: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    def = stack[-2];
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-2);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-1]); err_printf("\n");
            err_printf("Arg2: ");
            loop_print_error(stack[0]); err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
    r = Lmv_list(nil, r);
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return unpack_mv(nil, r);
}

LispObject tracebytecodedn(LispObject def, int nargs, ...)
{
//
// The messing about here is to get the (unknown number of) args
// into a nice neat vector so that they can be indexed into. If I knew
// that the args were in consecutive locations on the stack I could
// probably save a copying operation.
//
    LispObject r;
    int i;
    va_list a;
    SAVE_CODEVEC;
    push(def);
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" (%d args)", nargs);
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
#ifndef NO_BYTECOUNT
    else if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    def = stack[-nargs];
    r = qcar(def);
    if (nargs != ((unsigned char *)data_of_bps(r))[0])
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+1, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    r = Lmv_list(nil, r);
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return unpack_mv(nil, r);
}

LispObject tracebytecoded3(LispObject def, int nargs, ...)
{   va_list aa;
    LispObject r, a, b, c;
    if (nargs != 3) error(2, err_wrong_no_args, name_from(def),
                                     fixnum_of_int((int32_t)nargs));
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    SAVE_CODEVEC;
    push4(def, a, b, c);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(name_from(def));
    trace_printf(" (3 args)");
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
#ifndef NO_BYTECOUNT
    else if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\nArg1: ");
    loop_print_trace(stack[-2]);
    trace_printf("\nArg2: ");
    loop_print_trace(stack[-1]);
    trace_printf("\nArg3: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    def = stack[-3];
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-3);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-2]); err_printf("\n");
            err_printf("Arg2: ");
            loop_print_error(stack[-1]); err_printf("\n");
            err_printf("Arg3: ");
            loop_print_error(stack[0]); err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
    r = Lmv_list(nil, r);
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return unpack_mv(nil, r);
}

//
// The code that follows is just used to support compiled code that
// has &optional or &rest arguments.
//

LispObject byteopt1(LispObject def, LispObject a)
{   return byteoptn(def, 1, a);
}

LispObject byteopt2(LispObject def, LispObject a, LispObject b)
{   return byteoptn(def, 2, a, b);
}

static LispObject vbyteoptn(LispObject def, int nargs,
                            va_list a, LispObject dflt)
{   LispObject r;
    int i, wantargs, wantopts;
    SAVE_CODEVEC;
//
// Maybe I should raise an exception (continuable error) if too many args
// are provided - for now I just silently ignore the excess.
//
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs || nargs > wantargs+wantopts)
    {   popv(nargs); pop2(codevec, litvec)
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   // Provide value for all optional args
        nargs++;
    }
    r = qcar(def);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+2, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject byteoptn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyteoptn(def, nargs, a, nil);
}

LispObject hardopt1(LispObject def, LispObject a)
{   return hardoptn(def, 1, a);
}

LispObject hardopt2(LispObject def, LispObject a, LispObject b)
{   return hardoptn(def, 2, a, b);
}

LispObject hardoptn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyteoptn(def, nargs, a, SPID_NOARG);
}

LispObject byteoptrest1(LispObject def, LispObject a)
{   return byteoptrestn(def, 1, a);
}

LispObject byteoptrest2(LispObject def, LispObject a, LispObject b)
{   return byteoptrestn(def, 2, a, b);
}

static LispObject vbyterestn(LispObject def, int nargs,
                             va_list a, LispObject dflt)
{   LispObject r;
    int i, wantargs, wantopts;
    SAVE_CODEVEC;
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs)
    {   popv(nargs+2);
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   // Provide value for all optional args
        nargs++;
    }
    {   LispObject rest = nil;
        while (nargs > wantargs+wantopts)
        {   LispObject w = stack[0];
            stack[0] = def;
            rest = cons(w, rest);
            pop(def);
            nargs--;
        }
        push(rest);
        nargs++;
    }
    r = qcar(def);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+2, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject byteoptrestn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyterestn(def, nargs, a, nil);
}

LispObject hardoptrest1(LispObject def, LispObject a)
{   return hardoptrestn(def, 1, a);
}

LispObject hardoptrest2(LispObject def, LispObject a, LispObject b)
{   return hardoptrestn(def, 2, a, b);
}

LispObject hardoptrestn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyterestn(def, nargs, a, SPID_NOARG);
}

LispObject tracebyteopt1(LispObject def, LispObject a)
{   return tracebyteoptn(def, 1, a);
}

LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b)
{   return tracebyteoptn(def, 2, a, b);
}

static LispObject vtracebyteoptn(LispObject def, int nargs,
                                 va_list a, LispObject dflt)
{   LispObject r;
    int i, wantargs, wantopts;
    SAVE_CODEVEC;
    push(def);
//
// Maybe I should raise an exception (continuable error) if too many args
// are provided - for now I just silently ignore th excess.
//
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs || nargs > wantargs+wantopts)
    {   popv(nargs+1); pop2(codevec, litvec)
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   // Provide value for all optional args
        nargs++;
    }
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" (%d args)", nargs);
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
#ifndef NO_BYTECOUNT
    else if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    def = stack[-nargs];
    r = qcar(def);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+2, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    r = Lmv_list(nil, r);
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return unpack_mv(nil, r);
}

LispObject tracebyteoptn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vtracebyteoptn(def, nargs, a, nil);
}

LispObject tracehardopt1(LispObject def, LispObject a)
{   return tracehardoptn(def, 1, a);
}

LispObject tracehardopt2(LispObject def, LispObject a, LispObject b)
{   return tracehardoptn(def, 2, a, b);
}

LispObject tracehardoptn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vtracebyteoptn(def, nargs, a, SPID_NOARG);
}

LispObject tracebyteoptrest1(LispObject def, LispObject a)
{   return tracebyteoptrestn(def, 1, a);
}

LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b)
{   return tracebyteoptrestn(def, 2, a, b);
}

static LispObject vtracebyterestn(LispObject def, int nargs,
                                  va_list a, LispObject dflt)
{   LispObject r;
    int i, wantargs, wantopts;
    SAVE_CODEVEC;
    push(def);
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs)
    {   popv(nargs+2);
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   // Provide value for all optional args
        nargs++;
    }
    {   LispObject rest = nil;
        while (nargs > wantargs+wantopts)
        {   LispObject w = stack[0];
            stack[0] = def;
            rest = cons(w, rest);
            pop(def);
            nargs--;
        }
        push(rest);
        nargs++;
    }
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" (%d args)", nargs);
    if (callstack != nil)
    {   trace_printf(" from ");
        loop_print_trace(qcar(callstack));
    }
#ifndef NO_BYTECOUNT
    else if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    def = stack[-nargs];
    r = qcar(def);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+2, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    r = Lmv_list(nil, r);
    pop(def);
    push(r);
    freshline_trace();
    loop_print_trace(name_from(def));
    trace_printf(" = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return unpack_mv(nil, r);
}

LispObject tracebyteoptrestn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vtracebyterestn(def, nargs, a, nil);
}

LispObject tracehardoptrest1(LispObject def, LispObject a)
{   return tracehardoptrestn(def, 1, a);
}

LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b)
{   return tracehardoptrestn(def, 2, a, b);
}

LispObject tracehardoptrestn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vtracebyterestn(def, nargs, a, SPID_NOARG);
}

LispObject Lis_spid(LispObject env, LispObject a)
{   // Used in compilation for optional args
    return onevalue(Lispify_predicate(is_spid(a)));
}

LispObject Lspid_to_nil(LispObject env, LispObject a)
{   // Used in compilation for optional args
    if (is_spid(a)) a = nil;
    return onevalue(a);
}

LispObject Lload_spid(LispObject, int, ...)
{   // Used in compilation of UNWIND-PROTECT
    return onevalue(SPID_PROTECT);
}

LispObject Lmv_list(LispObject env, LispObject a)
//
// This does a (multiple-value-list A) on just one form.  It must be used
// carefully so that the value-count information does not get lost between
// the evaluation of A and calling this code. For this to work the variable
// exit_count must have been set to 1 before the call that evaluated the
// argument! Ensuring that all the time may be tough and may mean that
// non-compiled code has to set exit_count rather often "just to be sure".
// It also makes the case of (apply #'mv!-list ...) seem slightly scary,
// because normally arguments only generate one value each. Hmmm maybe this
// would be best implemented as a special form.
// Haha (multiple-value-list V) may be implemented as
// (multiple-value-call #'list V) and multiple-value-call is a special form.
// so what I have here is in fact unsupportable!
//
{   LispObject r;
    int i, x = exit_count;
    if (x > 0) push(a);
    for (i=2; i<=x; i++) push((&work_0)[i]);
    r = nil;
    for (i=0; i<x; i++)
    {   LispObject w;
        pop(w);
        r = cons(w, r);
    }
    return onevalue(r);
}

//
// In these tables there are some functions that would need adjusting
// for a Common Lisp compiler, since they take different numbers of
// args in Common and Standard Lisp.
// This means, to be specific:
//
//  Lgensym     Lread       Latan       Ltruncate   Lfloat
//  Lintern     Lmacroexpand            Lmacroexpand_1
//  Lrandom     Lunintern   Lappend     Leqn        Lgcd
//  Lgeq        Lgreaterp   Llcm        Lleq        Llessp
//  Lquotient
//
// In these cases (at least!) the Common Lisp version of the compiler will
// need to avoid generating the call that uses this table.
//
// Some functions are missing from the list here because they seemed
// critical enough to be awarded single-byte opcodes or because the
// compiler always expands them away - car through cddddr are the main
// cases, together with eq and equal.
//


n_args *no_arg_functions[] =
{   Lbatchp,                // 0
    Ldate,                  // 1
    Leject,                 // 2
    Lerror0,                // 3
    Lgctime,                // 4
    Lgensym,                // 5
    Llposn,                 // 6
    Lnext_random,           // 7
    Lposn,                  // 8
    Lread,                  // 9
    Lreadch,                // 10
    Lterpri,                // 11
    Ltime,                  // 12
    Ltyi,                   // 13
    Lload_spid,             /* 14 */  // ONLY used in compiled code
    NULL
};

no_args *new_no_arg_functions[] =
{   NULL
};

one_args *one_arg_functions[] =
{   Labsval,                // 0
    Ladd1,                  // 1
    Latan,                  // 2
    Lapply0,                // 3
    Latom,                  // 4
    Lboundp,                // 5
    Lchar_code,             // 6
    Lclose,                 // 7
    Lcodep,                 // 8
    Lcompress,              // 9
    Lconstantp,             // 10
    Ldigitp,                // 11
    Lendp,                  // 12
    Leval,                  // 13
    Levenp,                 // 14
    Levlis,                 // 15
    Lexplode,               // 16
    Lexplode2lc,            // 17
    Lexplodec,              // 18
    Lfixp,                  // 19
    Lfloat,                 // 20
    Lfloatp,                // 21
    Lsymbol_specialp,       // 22
    Lgc,                    // 23
    Lgensym1,               // 24
    Lgetenv,                // 25
    Lsymbol_globalp,        // 26
    Liadd1,                 // 27
    Lsymbolp,               // 28
    Liminus,                // 29
    Liminusp,               // 30
    Lindirect,              // 31
    Lintegerp,              // 32
    Lintern,                // 33
    Lisub1,                 // 34
    Llength,                // 35
    Llengthc,               // 36
    Llinelength,            // 37
    Lalpha_char_p,          // 38
    Lload_module,           // 39
    Llognot,                // 40
    Lmacroexpand,           // 41
    Lmacroexpand_1,         // 42
    Lmacro_function,        // 43
    Lget_bps,               // 44
    Lmake_global,           // 45
    Lsmkvect,               // 46
    Lmake_special,          // 47
    Lminus,                 // 48
    Lminusp,                // 49
    Lmkvect,                // 50
    Lmodular_minus,         // 51
    Lmodular_number,        // 52
    Lmodular_reciprocal,    // 53
    Lnull,                  // 54
    Loddp,                  // 55
    Lonep,                  // 56
    Lpagelength,            // 57
    Lconsp,                 // 58
    Lplist,                 // 59
    Lplusp,                 // 60
    Lprin,                  // 61
    Lprinc,                 // 62
    Lprint,                 // 63
    Lprintc,                // 64
    Lrandom,                // 65
    Lrational,              // 66
    Lrdf1,                  // 67
    Lrds,                   // 68
    Lremd,                  // 69
    Lreverse,               // 70
    Lnreverse,              // 71
    Lwhitespace_char_p,     // 72
    Lset_small_modulus,     // 73
    Lxtab,                  // 74
    Lspecial_char,          // 75
    Lspecial_form_p,        // 76
    Lspool,                 // 77
    Lstop,                  // 78
    Lstringp,               // 79
    Lsub1,                  // 80
    Lsymbol_env,            // 81
    Lsymbol_function,       // 82
    Lsymbol_name,           // 83
    Lsymbol_value,          // 84
    Lsystem,                // 85
    Ltruncate,              // 86
    Lttab,                  // 87
    Ltyo,                   // 88
    Lunintern,              // 89
    Lunmake_global,         // 90
    Lunmake_special,        // 91
    Lupbv,                  // 92
    Lsimple_vectorp,        // 93
    Lverbos,                // 94
    Lwrs,                   // 95
    Lzerop,                 // 96
    Lcar,                   // 97
    Lcdr,                   // 98
    Lcaar,                  // 99
    Lcadr,                  // 100
    Lcdar,                  // 101
    Lcddr,                  // 102
    Lcar,                   /* 103 */   // Really QCAR (unchecked)
    Lcdr,                   // 104
    Lcaar,                  // 105
    Lcadr,                  // 106
    Lcdar,                  // 107
    Lcddr,                  // 108
    Lncons,                 // 109
    Lnumberp,               // 110
    Lis_spid,               /* 111 */  // ONLY used in compiled code
    Lspid_to_nil,           /* 112 */  // ONLY used in compiled code
    Lmv_list,               /* 113 */  // ONLY used in compiled code
    Lload_source,           // 114

// I also need a FEW special forms where their setup is done by hand in
// restart.cpp so there are not entries in the usual tables...
    quote_fn,               // 115
    progn_fn,               // 116
    progn_fn,               // 117
    declare_fn,             // 118
    function_fn,            // 119
    NULL
};

two_args *two_arg_functions[] =
{   Lappend,                // 0
    Lash,                   // 1
    Lassoc,                 // 2
    Latsoc,                 // 3
    Ldeleq,                 // 4
    Ldelete,                // 5
    Ldivide,                // 6
    Leqcar,                 // 7
    Leql,                   // 8
    Leqn,                   // 9
    Lexpt,                  // 10
    Lflag,                  // 11
    Lflagpcar,              // 12
    Lgcd,                   // 13
    Lgeq,                   // 14
    Lgetv,                  // 15
    Lgreaterp,              // 16
    Lidifference,           // 17
    Ligreaterp,             // 18
    Lilessp,                // 19
    Limax,                  // 20
    Limin,                  // 21
    Liplus2,                // 22
    Liquotient,             // 23
    Liremainder,            // 24
    Lirightshift,           // 25
    Litimes2,               // 26
    Llcm,                   // 27
    Lleq,                   // 28
    Llessp,                 // 29
    Lmake_random_state,     // 30
    Lmax2,                  // 31
    Lmember,                // 32
    Lmemq,                  // 33
    Lmin2,                  // 34
    Lmod,                   // 35
    Lmodular_difference,    // 36
    Lmodular_expt,          // 37
    Lmodular_plus,          // 38
    Lmodular_quotient,      // 39
    Lmodular_times,         // 40
    Lnconc,                 // 41
    Lneq,                   // 42
    Lorderp,                // 43
    Lquotient,              // 44
    Lrem,                   // 45
    Lremflag,               // 46
    Lremprop,               // 47
    Lrplaca,                // 48
    Lrplacd,                // 49
    Lsgetv,                 // 50
    Lset,                   // 51
    Lsmemq,                 // 52
    Lsubla,                 // 53
    Lsublis,                // 54
    Lsymbol_set_definition, // 55
    Lsymbol_set_env,        // 56
    Ltimes2,                // 57
    Lxcons,                 // 58
    Lequal,                 // 59
    Leq,                    // 60
    Lcons,                  // 61
    Llist2,                 // 62
    Lget,                   // 63
    Lgetv,                  /* 64 */   // QGETV
    Lflagp,                 // 65
    Lapply1,                // 66
    Ldifference2,           // 67
    Lplus2,                 // 68
    Ltimes2,                // 69
    Lequalcar,              // 70
    Leq,                    /* 71 */   // IEQUAL
    Lnreverse2,             // 72
    NULL
};

n_args *three_arg_functions[] =
{   Lbpsputv,               // 0
    Lerrorsetn,             // 1
    Llist2star,             // 2
    Llist3,                 // 3
    Lputprop,               // 4
    Lputv,                  // 5
    Lsputv,                 // 6
    Lsubst,                 // 7
    Lapply2,                // 8
    Lacons,                 // 9
    NULL
};

four_args *four_arg_functions[] =
{   NULL
};


// end of eval4.cpp
