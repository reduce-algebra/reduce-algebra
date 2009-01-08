/*  eval2.c                          Copyright (C) 1989-2008 Codemist Ltd */

/*
 * Interpreter (part 2).  apply & some special forms
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



/* Signature: 040d07a6 24-May-2008 */

#include "headers.h"



static Lisp_Object apply_lots(int nargs, n_args *f, Lisp_Object def)
/*
 * Cases with 8 or more args are lifted out here into a subroutine
 * to make APPLY a bit shorter and because these cases should be
 * uncommon & not worth optimising much.  The code that Microsoft C 6.00A
 * produced for this was utterly DREADFUL - maybe other C compilers will
 * make a mess of it too.  Anyway I hope it will not be called very often.
 */
{
    switch(nargs)
    {
case 9:
        return (*f)(def, 9,   stack[-9],  stack[-8],  stack[-7],
                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                  stack[-2],  stack[-1]);
case 10:
        return (*f)(def, 10,  stack[-10], stack[-9],  stack[-8],
                  stack[-7],  stack[-6],  stack[-5],  stack[-4],
                  stack[-3],  stack[-2],  stack[-1]);
case 11:
        return (*f)(def, 11,  stack[-11], stack[-10],
                  stack[-9],  stack[-8],  stack[-7],  stack[-6],
                  stack[-5],  stack[-4],  stack[-3],  stack[-2],
                  stack[-1]);
case 12:
        return (*f)(def, 12,  stack[-12], stack[-11],
                  stack[-10], stack[-9],  stack[-8],  stack[-7],
                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                  stack[-2],  stack[-1]);
case 13:
        return (*f)(def, 13,  stack[-13], stack[-12],
                  stack[-11], stack[-10], stack[-9],  stack[-8],
                  stack[-7],  stack[-6],  stack[-5],  stack[-4],
                  stack[-3],  stack[-2],  stack[-1]);
case 14:
        return (*f)(def, 14,  stack[-14], stack[-13],
                  stack[-12], stack[-11], stack[-10], stack[-9],
                  stack[-8],  stack[-7],  stack[-6],  stack[-5],
                  stack[-4],  stack[-3],  stack[-2],  stack[-1]);
case 15:
        return (*f)(def, 15,  stack[-15], stack[-14],
                  stack[-13], stack[-12], stack[-11], stack[-10],
                  stack[-9],  stack[-8],  stack[-7],  stack[-6],
                  stack[-5],  stack[-4],  stack[-3],  stack[-2],
                  stack[-1]);
case 16:
        return (*f)(def, 16,  stack[-16], stack[-15],
                  stack[-14], stack[-13], stack[-12], stack[-11],
                  stack[-10], stack[-9],  stack[-8],  stack[-7],
                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                  stack[-2],  stack[-1]);
case 17:
        return (*f)(def, 17,  stack[-17], stack[-16],
                  stack[-15], stack[-14], stack[-13], stack[-12],
                  stack[-11], stack[-10], stack[-9],  stack[-8],
                  stack[-7],  stack[-6],  stack[-5],  stack[-4],
                  stack[-3],  stack[-2],  stack[-1]);
case 18:
        return (*f)(def, 18,  stack[-18], stack[-17],
                  stack[-16], stack[-15], stack[-14], stack[-13],
                  stack[-12], stack[-11], stack[-10], stack[-9],
                  stack[-8],  stack[-7],  stack[-6],  stack[-5],
                  stack[-4],  stack[-3],  stack[-2],  stack[-1]);
case 19:
        return (*f)(def, 19,  stack[-19], stack[-18],
                  stack[-17], stack[-16], stack[-15], stack[-14],
                  stack[-13], stack[-12], stack[-11], stack[-10],
                  stack[-9],  stack[-8],  stack[-7],  stack[-6],
                  stack[-5],  stack[-4],  stack[-3],  stack[-2],
                  stack[-1]);
case 20:
        return (*f)(def, 20,  stack[-20], stack[-19],
                  stack[-18], stack[-17], stack[-16], stack[-15],
                  stack[-14], stack[-13], stack[-12], stack[-11],
                  stack[-10], stack[-9],  stack[-8],  stack[-7],
                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                  stack[-2],  stack[-1]);
case 21:
        return (*f)(def, 21,  stack[-21], stack[-20],
                  stack[-19], stack[-18], stack[-17], stack[-16],
                  stack[-15], stack[-14], stack[-13], stack[-12],
                  stack[-11], stack[-10], stack[-9],  stack[-8],
                  stack[-7],  stack[-6],  stack[-5],  stack[-4],
                  stack[-3],  stack[-2],  stack[-1]);
case 22:
        return (*f)(def, 22,  stack[-22], stack[-21],
                  stack[-20], stack[-19], stack[-18], stack[-17],
                  stack[-16], stack[-15], stack[-14], stack[-13],
                  stack[-12], stack[-11], stack[-10], stack[-9],
                  stack[-8],  stack[-7],  stack[-6],  stack[-5],
                  stack[-4],  stack[-3],  stack[-2],  stack[-1]);
case 23:
        return (*f)(def, 23,  stack[-23], stack[-22],
                  stack[-21], stack[-20], stack[-19], stack[-18],
                  stack[-17], stack[-16], stack[-15], stack[-14],
                  stack[-13], stack[-12], stack[-11], stack[-10],
                  stack[-9],  stack[-8],  stack[-7],  stack[-6],
                  stack[-5],  stack[-4],  stack[-3],  stack[-2],
                  stack[-1]);
case 24:
        return (*f)(def, 24,  stack[-24], stack[-23],
                  stack[-22], stack[-21], stack[-20], stack[-19],
                  stack[-18], stack[-17], stack[-16], stack[-15],
                  stack[-14], stack[-13], stack[-12], stack[-11],
                  stack[-10], stack[-9],  stack[-8],  stack[-7],
                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                  stack[-2],  stack[-1]);
case 25:
        return (*f)(def, 25,  stack[-25], stack[-24], stack[-23],
                  stack[-22], stack[-21], stack[-20], stack[-19],
                  stack[-18], stack[-17], stack[-16], stack[-15],
                  stack[-14], stack[-13], stack[-12], stack[-11],
                  stack[-10], stack[-9],  stack[-8],  stack[-7],
                  stack[-6],  stack[-5],  stack[-4],  stack[-3],
                  stack[-2],  stack[-1]);
default:
/*
 * If more than 25 args are going to be passed I will arrange that the
 * final ones are built into a list - as if the 25th arg was specified
 * as a "&rest" one.  Why?  Because passing VERY large numbers of arguments
 * in C is not a good idea - ANSI C compilers are only obliged to support
 * up to 31 args, and one some machines this limit seems to really matter.
 * But Common Lisp can need more args than that.  I will ignore the fact that
 * what I do here is slow.  I will HOPE that calls with 25 or more args
 * are very uncommon.
 */
        {   int n = nargs;
            Lisp_Object w, *tsp = stack, nil = C_nil;
#if (ARG_CUT_OFF != 25)
            if (ARG_CUT_OFF != 25)
            {   fprintf(stderr, "\n+++ ARG_CUT_OFF incorrectly configured\n");
                my_exit(EXIT_FAILURE);
            }
#endif
            w = ncons(tsp[-1]);
            errexit();
            tsp[-1] = w;
            while (n > ARG_CUT_OFF)
            {   w = cons(tsp[-2], tsp[-1]);
                errexit();
                tsp[-2] = w;
                tsp[-1] = tsp[0];
                tsp--;
                n--;
            }
            return (*f)(def, nargs,   tsp[-25], tsp[-24], tsp[-23],
                      tsp[-22], tsp[-21], tsp[-20], tsp[-19],
                      tsp[-18], tsp[-17], tsp[-16], tsp[-15],
                      tsp[-14], tsp[-13], tsp[-12], tsp[-11],
                      tsp[-10], tsp[-9],  tsp[-8],  tsp[-7],
                      tsp[-6],  tsp[-5],  tsp[-4],  tsp[-3],
                      tsp[-2],  tsp[-1]);
        }
    }
}

void push_args(va_list a, int nargs)
/*
 * The unpacking here must match "apply_lots" as above.  For up to
 * (and including) ARG_CUT_OFF (=25) args things are passed normally.
 * beyond that the first ARG_CUT_OFF-1 args are passed normally, and the
 * rest are in a list as a final actual arg.  Note that this list will
 * have at least two elements.
 */
{
    int i;
    if (nargs <= ARG_CUT_OFF)
    {   for (i = 0; i<nargs; i++)
        {   Lisp_Object w = va_arg(a, Lisp_Object);
            push(w);
        }
    }
    else
    {   Lisp_Object x;
        for (i = 0; i<(ARG_CUT_OFF-1); i++)
        {   Lisp_Object w = va_arg(a, Lisp_Object);
            push(w);
        }
        x = va_arg(a, Lisp_Object);
/*
 * Internal consistency should ensure that the list passed here is long
 * enough for the following unpacking operation.  But if (as a result of
 * internal system muddles it is not maybe the fact that qcar(nil) =
 * qcdr(nil) = nil will tend to reduce the damage?
 */
        for (; i<nargs; i++)
        {   push(qcar(x));
            x = qcdr(x);
        }
    }
    va_end(a);
}

void push_args_1(va_list a, int nargs)
/*
 * This is very much like push_args(), but is for the (rather small number
 * of) cases where the first argument to a function must NOT be pushed on the
 * stack.  See, for instance, "funcall" as an example.
 */
{
    int i;
    if (nargs <= ARG_CUT_OFF)
    {   for (i = 1; i<nargs; i++)
        {   Lisp_Object w = va_arg(a, Lisp_Object);
            push(w);
        }
    }
    else
    {   Lisp_Object x;
        for (i = 1; i<(ARG_CUT_OFF-1); i++)
        {   Lisp_Object w = va_arg(a, Lisp_Object);
            push(w);
        }
        x = va_arg(a, Lisp_Object);
        for (; i<nargs; i++)
        {   push(qcar(x));
            x = qcdr(x);
        }
    }
    va_end(a);
}


Lisp_Object apply(Lisp_Object fn, int nargs, Lisp_Object env, Lisp_Object name)
/*
 * There are (nargs) arguments on the Lisp stack, and apply() must use them
 * then pop them off.  They were pushed in the order push(arg1); push(arg2),
 * and so on, and the stack grows upwards.
 * If I return with an error I will hand back the value name rather than the
 * junk value normally used in such cases.
 */
{
    Lisp_Object def, nil = C_nil;
    for (;;)
    {   if (symbolp(fn))
        {
            def = qenv(fn); /* this is passed as arg1 to the called code */
/*
 * apply_lambda() will find arguments on the stack and is responsible for
 * popping them before it exits.
 */
            {
/*
 * Because there are nargs values pushed on the (upwards growing) stack,
 * &stack[1-nargs] points at the first value pushed, i.e. arg-1.  At one stage
 * I had a machine-specific bit of code (called "ncall") to do the following,
 * arguing that maybe in assembly code it would be possible to do much better
 * than the really ugly switch statement shown now.  My belief now (especially
 * given that ncall was used in just one place - here) is that the switch will
 * cost no more than the procedure call did, and that in-line code will help
 * speed up the common and critical cases of 0, 1, 2 and 3 args.  Also apply
 * is otherwise a reasonably short function, so if this switch is needed
 * anywhere here is not too bad.
 */
                push(name);
                switch (nargs)
                {
/*
 * The Standard Lisp Report (Marti et al, Utah UUCS-78-101) only
 * requires support for 15 args.  Common Lisp requires at least 50.
 * I deal with up to 8 args in-line here (I expect more than that to be
 * amazingly uncommon) so that this function is kept under contol.
 * Calls with more than 8 args go over to apply_lots, and within that
 * function calls with over 25 args have an even more clumsy treatment.
 */
            case 0:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfnn(fn))(def, 0);
                    break;
            case 1:
#ifdef DEBUG
                    if (qfn1(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfn1(fn))(def, stack[-1]);
                    break;
            case 2:
#ifdef DEBUG
                    if (qfn2(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfn2(fn))(def, stack[-2], stack[-1]);
                    break;
            case 3:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfnn(fn))(def, 3, stack[-3], stack[-2], stack[-1]);
                    break;
            case 4:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfnn(fn))(def, 4, stack[-4], stack[-3], stack[-2],
                                   stack[-1]);
                    break;
            case 5:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfnn(fn))(def, 5, stack[-5], stack[-4], stack[-3],
                                   stack[-2], stack[-1]);
                    break;
            case 6:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfnn(fn))(def, 6, stack[-6], stack[-5], stack[-4],
                                   stack[-3], stack[-2], stack[-1]);
                    break;
            case 7:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfnn(fn))(def, 7, stack[-7], stack[-6], stack[-5],
                                   stack[-4], stack[-3], stack[-2], stack[-1]);
                    break;
            case 8:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = (*qfnn(fn))(def, 8, stack[-8], stack[-7], stack[-6],
                                   stack[-5], stack[-4], stack[-3], stack[-2],
                                   stack[-1]);
                    break;
            default:
#ifdef DEBUG
                    if (qfnn(fn) == NULL)
                    {   term_printf("Illegal APPLY\n");
                        my_exit(EXIT_FAILURE);
                    }
#endif
                    def = apply_lots(nargs, qfnn(fn), def);
                    break;
                }
/*
 * here I have to pop the stack by hand - note that popv does not
 * corrupt exit_count, which tells me how many results were being handed
 * back.
 */
                pop(name);
                popv(nargs);
                nil = C_nil;
                if (exception_pending()) return name;
                else return def;
            }
        }
        else if (!is_cons(fn))
        {   popv(nargs);
            push(name);
            error(1, err_bad_fn, fn);
            pop(name);
            return name;
        }
/* apply_lambda() will pop the args from the stack when it is done */
        if ((def = qcar(fn)) == lambda)
            return apply_lambda(qcdr(fn), nargs, env, name);
/*
 * A bytecoded funarg is stored as (cfunarg <actual fn> <env>) and any call
 * to it behaves as if the actual function was called with the environment
 * passed as a forced-in first argument.
 */

        else if (def == cfunarg)
        {   int i;
            push(nil);
            def = qcdr(fn);
            fn = qcar(def);
            for (i=0; i<nargs; i++) stack[-i] = stack[-i-1];
            stack[-nargs] = qcdr(def);
            nargs++;
            continue;
        }
        else if (def == funarg)
        {   def = qcdr(fn);
            if (consp(def))
                return apply_lambda(qcdr(def), nargs, qcar(def), name);
        }
        break;
    }
/*
 * Other cases are all errors.
 */
    popv(nargs);
    push(name);
    error(1, err_bad_apply, fn);
    pop(name);
    return name;
}

/*
 * Now for implementation of all the special forms...
 */

static Lisp_Object and_fn(Lisp_Object args, Lisp_Object env)
/* also needs to be a macro for Common Lisp */
{
    Lisp_Object nil = C_nil;
    stackcheck2(0, args, env);
    if (!consp(args)) return onevalue(lisp_true);
    for (;;)
    {   Lisp_Object v = qcar(args);
        args = qcdr(args);
        if (!consp(args)) return eval(v, env);
        push2(args, env);
        v = eval(v, env);
        pop2(env, args);
        errexit();
        if (v == nil) return onevalue(nil);
    }
}

/*
 * This is not used at present, but may be wanted sometime so I will
 * leave it here for now...
 *
Lisp_Object append(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil = C_nil;
    if (!consp(a)) return b;
    else
    {   stackcheck2(0, a, b);
        push(a);
        b = append(qcdr(a), b);
        pop(a);
        errexit();
        return cons(qcar(a), b);
    }
}
*/

static Lisp_Object block_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object p, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push3(qcar(args),          /* my_tag                               */
          qcdr(args),          /* args                                 */
          env);
#define env    stack[0]
#define args   stack[-1]
#define my_tag stack[-2]
/*
 * I need to augment the (lexical) environment with the name of my
 * tag in such a way that return-from can throw out to exactly the
 * correct matching level.  This is done by pushing (0 . tag) onto
 * the environment - the 0 marks this as a block name.
 */
    my_tag = cons(fixnum_of_int(0), my_tag);
    errexitn(3);
    env = cons(my_tag, env);
    errexitn(3);
    p = nil;
    while (consp(args))
    {   p = qcar(args);
        p = eval(p, env);
/*
 * one of the sorts of exit that may be activated by marking nil is
 * a return_from.  Here I need to check to see if that is what
 * is going on.
 */
    nil = C_nil;
    if (exception_pending())
        {   flip_exception(); /* Temp restore it */
            qcar(my_tag) = fixnum_of_int(2); /* Invalidate */
            if (exit_reason == UNWIND_RETURN && exit_tag == my_tag)
            {   exit_reason = UNWIND_NULL; /* not strictly needed - but tidy */
                popv(3);
                return nvalues(exit_value, exit_count);
            }
            if ((exit_reason & UNWIND_ERROR) != 0)
            {   err_printf("\nEvaluating: ");
                loop_print_error(qcar(args));
                ignore_exception();
            }
            flip_exception(); /* re-instate exit condition */
            popv(3);
            return nil;
        }
        args = qcdr(args);
    }
    popv(3);
    return p;
#undef env
#undef args
#undef my_tag
}

static Lisp_Object catch_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object tag, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    tag = qcar(args);
    tag = eval(tag, env);
    errexit();
    tag = catch_tags = cons(tag, catch_tags);
    pop2(env, args);
    errexit();
    push(tag);
    {
        Lisp_Object v = progn_fn(qcdr(args), env);
        pop(tag);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            catch_tags = qcdr(tag);
            qcar(tag) = tag;
            qcdr(tag) = nil;        /* Invalidate the catch frame */
            if (exit_reason == UNWIND_THROW && exit_tag == tag)
            {   exit_reason = UNWIND_NULL;
                return nvalues(exit_value, exit_count);
            }
            flip_exception();
            return nil;
        }
        catch_tags = qcdr(tag);
        qcar(tag) = tag;
        qcdr(tag) = nil;        /* Invalidate the catch frame */
        return v;
    }
}

#define BODY_LET            0
#define BODY_COMPILER_LET   1
#define BODY_PROG           2

Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                     Lisp_Object env, int compilerp)
/*
 * This will have to look for (declare (special ...)).
 * compiler-let forces all of its bindings to be locally special. In
 * CSL mode I do not support local declarations, which simplifies and
 * speeds things up here.
 */
{
    Lisp_Object nil = C_nil;
    stackcheck3(0, bvl, body, env);
    push3(bvl, body, env);
    nil = C_nil;
    push5(nil, nil, env, nil, nil);
#ifdef COMMON
/*
 * I lose the name (for security) but leave the junk stack location
 * (because doing otherwise seems unduly complicated.
 */
#define local_decs stack[0]
#endif
#define specenv    stack[-1]
#define env1       stack[-2]
#define p          stack[-3]
#define q          stack[-4]
#define env        stack[-5]
#define body       stack[-6]
#define bvl        stack[-7]
#define Return(v)  { popv(8); return (v); }
#ifdef COMMON
/*
 * Find local declarations - it is necessary to macro-expand
 * items in the body to see if they turn into declarations.
 */
    for (;;)
    {   if (exception_pending() || !consp(body)) break;
        p = macroexpand(qcar(body), env);
        errexitn(8);
        body = qcdr(body);
        if (!consp(p))
        {   if (stringp(p) && consp(body)) continue;
            body = cons(p, body);
            nil = C_nil;
            break;
        }
        if (qcar(p) != declare_symbol)
        {   body = cons(p, body);
            nil = C_nil;
            break;
        }
        for (p = qcdr(p); consp(p); p = qcdr(p))
        {   q = qcar(p);
            if (!consp(q) || qcar(q) != special_symbol) continue;
            /* here q says (special ...) */
            for (q=qcdr(q); consp(q); q = qcdr(q))
            {   local_decs = cons(qcar(q), local_decs);
                nil = C_nil;
                if (exception_pending()) break;
            }
            if (exception_pending()) break;
        }
    }
    if (exception_pending()) Return(nil);
#endif

    for (; consp(bvl); bvl=qcdr(bvl))
    {   Lisp_Object z;
        q = qcar(bvl);
        if (consp(q))
        {   z = qcdr(q);
            q = qcar(q);
            if (consp(z)) z = qcar(z); else z = nil;
        }
        else z = nil;
        if (!is_symbol(q))
        {   Lisp_Object qq = q;
            Return(error(1, err_bad_bvl, qq));
        }
        else
        {
#ifdef COMMON
            Header h = qheader(q);
#endif
            if (z != nil)
            {   z = eval(z, env);
                errexitn(8);
            }
            z = cons(q, z);
            errexitn(8);
#ifdef COMMON
            if (compilerp == BODY_COMPILER_LET)
            {   specenv = cons(z, specenv);
                errexitn(8);
                q = acons(q, work_symbol, env1);
                errexitn(8);
                env1 = q; /* Locally special */
            }
            else
#endif
#ifndef COMMON
            specenv = cons(z, specenv);
#else
            if (h & SYM_SPECIAL_VAR) specenv = cons(z, specenv);
            else
            {
                Lisp_Object w;
                for (w = local_decs; w!=nil; w = qcdr(w))
                {   if (q != qcar(w)) continue;
                    qcar(w) = fixnum_of_int(0);
/* The next few calls to cons() maybe lose w, but that is OK! */
                    specenv = cons(z, specenv);
                    errexitn(8);
                    q = acons(q, work_symbol, env1);
                    errexitn(8);
                    env1 = q;
                    goto bound;
                }
                env1 = cons(z, env1);
        bound:  ;
            }
#endif
            errexitn(8);
        }
    }

#ifdef COMMON
    while (local_decs!=nil)         /* Pervasive special declarations */
    {   Lisp_Object q1 = qcar(local_decs);
        local_decs=qcdr(local_decs);
        if (!is_symbol(q1)) continue;
        q1 = acons(q1, work_symbol, env1);
        errexitn(8);
        env1 = q1;
    }
#endif

    if (specenv == nil)
    {   Lisp_Object bodyx = body, env1x = env1;
/*
 * See expansion of Return() for an explanation of why body and env1 have
 * been moved into new local variables before the call..
 */
        if (compilerp == BODY_PROG)
        {   Return(tagbody_fn(bodyx, env1x));
        }
        else
        {   Return(progn_fn(bodyx, env1x));
        }
    }
/*
 * I instate the special bindings after all values to bind have been collected
 */
    for (p = specenv; p != nil; p = qcdr(p))
    {   Lisp_Object w = qcar(p), v = qcar(w), z = qcdr(w);
        Lisp_Object old = qvalue(v);
        qvalue(v) = z;
        qcdr(w) = old;
    }

    {
        if (compilerp == BODY_PROG)
             body = tagbody_fn(body, env1);
        else body = progn_fn(body, env1);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            for (p = specenv; p != nil; p = qcdr(p))
            {   Lisp_Object w = qcar(p), v = qcar(w), z = qcdr(w);
                qvalue(v) = z;
            }
            flip_exception();
            Return(nil);
        }
        else
        {   for (p = specenv; p != nil; p = qcdr(p))
            {   Lisp_Object w = qcar(p), v = qcar(w), z = qcdr(w);
                qvalue(v) = z;
            }
            {   Lisp_Object bodyx = body;
                Return(bodyx);
            }
        }
    }
#ifdef COMMON
#undef local_decs
#endif
#undef specenv
#undef env1
#undef p
#undef q
#undef env
#undef body
#undef bvl
#undef Return
}

#ifdef COMMON

static Lisp_Object compiler_let_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    return let_fn_1(qcar(args), qcdr(args), env, BODY_COMPILER_LET);
}

#endif

static Lisp_Object cond_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    stackcheck2(0, args, env);
    while (consp(args))
    {
        Lisp_Object p = qcar(args);
        if (consp(p))
        {   Lisp_Object p1;
            push2(args, env);
            p1 = qcar(p);
            p1 = eval(p1, env);
            pop2(env, args);
            errexit();
            if (p1 != nil)
            {   args = qcdr(qcar(args));
/* Here I support the case "(cond (predicate) ...)" with no consequents */
                if (!consp(args)) return onevalue(p1);
                else return progn_fn(args, env);
            }
        }
        args = qcdr(args);
    }
    return onevalue(nil);
}

#ifdef COMMON

Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env)
/*
 * declarations can only properly occur at the heads of various
 * special forms, and so may NOT be evaluated in an ordinary manner.
 * Thus I am entitled (just about) to make this a no-op.  It would
 * probably be better to arrange that (declare ...) never got evaluated
 * and then I could raise an error if this bit of code got activated.
 * Indeed (declare ...) probably does not ever get evaluated - still
 * a no-op here seems the safest bet.
 */
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(env);
    CSL_IGNORE(args);
    return onevalue(nil);
}

#endif

#define flagged_lose(v) \
    ((fv = qfastgets(v)) != nil && elt(fv, 1) != SPID_NOPROP)

static Lisp_Object defun_fn(Lisp_Object args, Lisp_Object env)
{
/*
 * defun is eventually expected (required!) to be a macro rather than (maybe
 * as well as?) a special form.  For bootstrap purposes it seems useful to
 * build it in as a special form.  Also this special form is quite good enough
 * in CSL mode
 */
    Lisp_Object fname, nil = C_nil;
    CSL_IGNORE(env);
    if (consp(args))
    {   fname = qcar(args);
        args = qcdr(args);
        if (is_symbol(fname))
        {   Lisp_Object fv;
            if (qheader(fname) & SYM_SPECIAL_FORM)
                return error(1, err_redef_special, fname);
            if ((qheader(fname) & (SYM_C_DEF | SYM_CODEPTR)) ==
                (SYM_C_DEF | SYM_CODEPTR)) return onevalue(fname);
            if (flagged_lose(fname))
            {   debug_printf("\n+++ ");
                loop_print_debug(fname);
                debug_printf(" not defined because of LOSE flag\n");
                return onevalue(nil);
            }
            qheader(fname) = qheader(fname) & ~SYM_MACRO;
            if ((qheader(fname) & SYM_C_DEF) != 0) lose_C_def(fname);
            if (qfn1(fname) != undefined1)
            {   if (qvalue(redef_msg) != nil)
                {   debug_printf("\n+++ ");
                    loop_print_debug(fname);
                    debug_printf(" redefined\n");
                }
                errexit();
                set_fns(fname, undefined1, undefined2, undefinedn);
                qenv(fname) = fname;
            }
/*
 * qfn() can contain 'interpreted' for a function defined wrt the null
 * environment, or 'funarged' for one with an environment - in the latter
 * case the definition (in qenv()) is a pair (<def> . <env>)
 */
            qenv(fname) = args;         /* Sort of notional lambda present */
            set_fns(fname, interpreted1, interpreted2, interpretedn);
            if (qvalue(comp_symbol) != nil &&
                qfn1(compiler_symbol) != undefined1)
            {   push(fname);
                args = ncons(fname);
                nil = C_nil;
                if (!exception_pending())
                    (qfn1(compiler_symbol))(qenv(compiler_symbol), args);
                pop(fname);
            }
            return onevalue(fname);
        }
    }
    return aerror("defun");
}

static Lisp_Object defmacro_fn(Lisp_Object args, Lisp_Object env)
{
/*
 * defmacro is eventually expected (required!) to be a macro rather than (maybe
 * as well as?) a special form.  For bootstrap purposes it seems useful to
 * build it in as a special form.
 */
    Lisp_Object fname, nil = C_nil;
    CSL_IGNORE(env);
    if (consp(args))
    {   fname = qcar(args);
        args = qcdr(args);
        if (is_symbol(fname))
        {
            if ((qheader(fname) & (SYM_C_DEF | SYM_CODEPTR)) ==
                (SYM_C_DEF | SYM_CODEPTR)) return onevalue(fname);
            qheader(fname) |= SYM_MACRO;
/*
 * Note that a name can have a definition as a macro and as a special form,
 * and in that case the qfn() cell gives the special form and the qenv()
 * cell the macro definition.  Otherwise at present I put 'undefined'
 * in the qfn() cell, but in due course I will want something else as better
 * protection against compiled code improperly attempting to call a macro.
 * Note also that if the symbol was a special form before I do not want
 * to clear the C_DEF flag, since the special form must be re-instated when
 * I reload the system.
 */
            if ((qheader(fname) & SYM_SPECIAL_FORM) == 0)
            {   qheader(fname) &= ~SYM_C_DEF;
                if (qfn1(fname) != undefined1 &&
                    qvalue(redef_msg) != nil)
                {   debug_printf("\n+++ ");
                    loop_print_debug(fname);
                    debug_printf(" redefined as a macro\n");
                    errexit();
                }
                set_fns(fname, undefined1, undefined2, undefinedn);
            }
            qenv(fname) = args;         /* Sort of notional lambda present */
            if (qvalue(comp_symbol) != nil &&
                qfn1(compiler_symbol) != undefined1)
            {   Lisp_Object t1, t2;
                push(fname);
                if (!(consp(args) &&
                      consp(qcdr(args)) &&
                      qcdr(qcdr(args)) == nil &&
                      (t1 = qcar(args),
                       t2 = qcdr(qcar(qcdr(args))),
                       equal(t1, t2))))
                {   errexitn(1);
                    fname = stack[0];
                    args = ncons(fname);
                    nil = C_nil;
                    if (!exception_pending())
                        (qfn1(compiler_symbol))(qenv(compiler_symbol), args);
                }
                pop(fname);
                errexit();
            }
            return onevalue(fname);
        }
    }
    return aerror("defmacro");
}

static Lisp_Object eval_when_fn(Lisp_Object args, Lisp_Object env)
/*
 * When interpreted, eval-when just looks for the situation EVAL.
 */
{
    Lisp_Object situations, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    situations = qcar(args);
    args = qcdr(args);
    while (consp(situations))
    {   if (qcar(situations) == eval_symbol) return progn_fn(args, env);
        situations = qcdr(situations);
    }
    return onevalue(nil);
}

#ifdef COMMON

static Lisp_Object flet_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object my_env, d, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    my_env = env;
    d = qcar(args);     /* The bunch of definitions */
    args = qcdr(args);
    nil = C_nil;
    while (consp(d))
    {   Lisp_Object w = qcar(d);
        if (consp(w) && consp(qcdr(w)))
        {   Lisp_Object w1;
            push4(args, d, env, w);
            w1 = list2star(funarg, my_env, qcdr(w));
            pop(w);
            nil = C_nil;
            if (!exception_pending()) w1 = cons(w1, qcar(w));
            pop(env);
            nil = C_nil;
            if (!exception_pending()) env = cons(w1, env);
            pop2(d, args);
            errexit();
        }
        d = qcdr(d);
    }
/*
 * Treat body as (let nil ...) to get (declare ...) recognized.
 */
    return let_fn_1(nil, args, env, BODY_LET);
}

#endif

Lisp_Object function_fn(Lisp_Object args, Lisp_Object env)
{
/*
 * For most things this behaves just like (quote xxx), but
 * (function (lambda (x) y)) gets converted to
 * (funarg env (x) y).
 */
    Lisp_Object nil = C_nil;
    if (consp(args) && qcdr(args) == nil)
    {   args = qcar(args);
        if (consp(args) && qcar(args) == lambda)
            args = list2star(funarg, env, qcdr(args));
        return onevalue(args);
    }
    return aerror("function");
}


static Lisp_Object go_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object p, tag, nil = C_nil;
    CSL_IGNORE(env);
    if (!consp(args)) return aerror("go");
    else tag = qcar(args);
    for(p=env; consp(p); p=qcdr(p))
    {   Lisp_Object w = qcar(p), z;
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(1) &&
            (z = qcar(qcdr(w)), eql(z, tag)))
        {   p = w;
            goto tag_found;
        }
    }
    return error(1, err_go_tag, tag);
tag_found:
    exit_tag = p;
    exit_count = 0;
    exit_reason = UNWIND_GO;
    flip_exception(); /* Exceptional exit active */
    return nil;
}

static Lisp_Object if_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object p=nil, tr=nil, fs=nil;
    if (!consp(args)) return aerror("if");
    p = qcar(args);
    args = qcdr(args);
    if (!consp(args)) return aerror("if");
    tr = qcar(args);
    args = qcdr(args);
    if (!consp(args)) fs = nil;
    else
    {   fs = qcar(args);
        args = qcdr(args);
        if (args != nil) return aerror("if");
    }
    stackcheck4(0, p, env, tr, fs);
    push3(fs, tr, env);
    p = eval(p, env);
    pop3(env, tr, fs);
    errexit();
    if (p == nil)
         return eval(fs, env);      /* tail call on result     */
    else return eval(tr, env);      /* ... passing back values */
}

#ifdef COMMON

static Lisp_Object labels_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object my_env, d, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    my_env = env;
    d = qcar(args);     /* The bunch of definitions */
    while (consp(d))
    {   Lisp_Object w = qcar(d);
        if (consp(w) && consp(qcdr(w)))
        {   Lisp_Object w1;
            push4(args, d, env, w);
            w1 = list2star(funarg, nil, qcdr(w));
            pop(w);
            nil = C_nil;
            if (!exception_pending()) w1 = cons(w1, qcar(w));
            pop(env);
            nil = C_nil;
            if (!exception_pending()) env = cons(w1, env);
            pop2(d, args);
            errexit();
        }
        d = qcdr(d);
    }
/*
 * Now patch up the environments stored with the local defs so as to
 * permit mutual recursion between them all.
 */
    for (d=env; d!=my_env; d=qcdr(d))
        qcar(qcdr(qcar(qcar(d)))) = env;
    return let_fn_1(nil, qcdr(args), env, BODY_LET);
}

#endif

static Lisp_Object let_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    return let_fn_1(qcar(args), qcdr(args), env, BODY_LET);
}

static Lisp_Object letstar_fn(Lisp_Object args, Lisp_Object env)
/*
 * This will have to look for (declare (special ...)), unless
 * I am in CSL mode.
 */
{
    Lisp_Object nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push3(qcar(args), qcdr(args), env);
    nil = C_nil;
    push5(nil, nil,                /* p, q                      */
          env, nil, nil);          /* env1, specenv, local_decs */
#ifdef COMMON
#define local_decs stack[0]
#endif
#define specenv    stack[-1]
#define env1       stack[-2]
#define p          stack[-3]
#define q          stack[-4]
#define env        stack[-5]
#define body       stack[-6]
#define bvl        stack[-7]
#define Return(v)  { popv(8); return (v); }
#ifdef COMMON
    for (;;)
    {   if (exception_pending() || !consp(body)) break;
        p = macroexpand(qcar(body), env);
        errexitn(8);
        body = qcdr(body);
        if (!consp(p))
        {   if (stringp(p) && consp(body)) continue;
            body = cons(p, body);
            nil = C_nil;
            break;
        }
        if (qcar(p) != declare_symbol)
        {   body = cons(p, body);
            nil = C_nil;
            break;
        }
        for (p = qcdr(p); consp(p); p = qcdr(p))
        {   q = qcar(p);
            if (!consp(q) || qcar(q) != special_symbol) continue;
            /* here q says (special ...) */
            for (q=qcdr(q); consp(q); q = qcdr(q))
            {   local_decs = cons(qcar(q), local_decs);
                nil = C_nil;
                if (exception_pending()) break;
            }
            if (exception_pending()) break;
        }
    }
    if (exception_pending()) Return(nil);
#endif
    for (; consp(bvl); bvl=qcdr(bvl))
    {   Lisp_Object z;
        q = qcar(bvl);
        if (consp(q))
        {   z = qcdr(q);
            q = qcar(q);
            if (consp(z)) z = qcar(z); else z = nil;
        }
        else z = nil;
        if (!is_symbol(q))
        {   error(1, err_bad_bvl, q);
            goto unwind_special_bindings;
        }
        else
        {
#ifdef COMMON
            Header h = qheader(q);
#endif
            if (z != nil)
            {   z = eval(z, env);
                nil = C_nil;
                if (exception_pending()) goto unwind_special_bindings;
            }
#ifndef COMMON
            p = z;
            z = acons(q, qvalue(q), specenv);
            nil = C_nil;
            if (!exception_pending()) specenv = z;
            qvalue(q) = p;
#else
            if (h & SYM_SPECIAL_VAR)
            {
                p = z;
                z = acons(q, qvalue(q), specenv);
                nil = C_nil;
                if (!exception_pending()) specenv = z;
                qvalue(q) = p;
            }
            else
            {
                for (p = local_decs; p!=nil; p = qcdr(p))
                {   Lisp_Object w;
                    if (q != qcar(p)) continue;
                    qcar(p) = fixnum_of_int(0);
                    w = acons(q, qvalue(q), specenv);
                    nil = C_nil;
                    if (exception_pending()) goto unwind_special_bindings;
                    specenv = w;
                    w = acons(q, work_symbol, env);
                    nil = C_nil;
                    if (exception_pending()) goto unwind_special_bindings;
                    env = w;
                    qvalue(q) = z;
                    goto bound;
                }
                q = acons(q, z, env);
                nil = C_nil;
                if (exception_pending()) goto unwind_special_bindings;
                env = q;
        bound:  ;
            }
#endif
            nil = C_nil;
            if (exception_pending()) goto unwind_special_bindings;
        }
    }
#ifdef COMMON
    while (local_decs!=nil)         /* Pervasive special declarations */
    {   q = qcar(local_decs);
        local_decs=qcdr(local_decs);
        if (!is_symbol(q)) continue;
        q = acons(q, work_symbol, env);
        nil = C_nil;
        if (!exception_pending()) env = q;
        else goto unwind_special_bindings;
    }
#endif
    if (specenv == nil)
    {   Lisp_Object bodyx = body, envx = env;
        Return(progn_fn(bodyx, envx));  /* beware Return macro! */
    }
    {
        body = progn_fn(body, env);
        nil = C_nil;
        if (exception_pending()) goto unwind_special_bindings;
        for (bvl = specenv; bvl != nil; bvl = qcdr(bvl))
        {   Lisp_Object w = qcar(bvl), v = qcar(w), z = qcdr(w);
            qvalue(v) = z;
        }
        {   Lisp_Object bodyx = body;
            Return(bodyx);
        }
    }
unwind_special_bindings:
    flip_exception();
    for (bvl = specenv; bvl != nil; bvl = qcdr(bvl))
    {   Lisp_Object w = qcar(bvl), v = qcar(w), z = qcdr(w);
        qvalue(v) = z;
    }
    flip_exception();
    popv(8);
    return nil;
#ifdef COMMON
#undef local_decs
#endif
#undef specenv
#undef env1
#undef p
#undef q
#undef env
#undef body
#undef bvl
#undef Return
}

setup_type const eval2_setup[] =
/*
 * A jolly curiosity - "function" and "declare" are ALSO set up in
 * restart.c (because handles are needed on the symbols).  I leave
 * the redundant initialisation here too since I find it clearer that
 * way.
 */
{
    {"and",                     and_fn, bad_special2, bad_specialn},
    {"catch",                   catch_fn, bad_special2, bad_specialn},
    {"cond",                    cond_fn, bad_special2, bad_specialn},
/*
 * I am not over-enthusiastic about supporting eval-when in CSL, but
 * something of that sort seems needed by some bits of code that I have
 * come across...
 */
    {"eval-when",               eval_when_fn, bad_special2, bad_specialn},
    {"function",                function_fn, bad_special2, bad_specialn},
    {"go",                      go_fn, bad_special2, bad_specialn},
    {"if",                      if_fn, bad_special2, bad_specialn},
    {"let*",                    letstar_fn, bad_special2, bad_specialn},
/* DE and DM are used as low level primitives in the Common Lisp bootstrap */
    {"de",                      defun_fn, bad_special2, bad_specialn},
    {"dm",                      defmacro_fn, bad_special2, bad_specialn},
#ifdef COMMON
    {"block",                   block_fn, bad_special2, bad_specialn},
    {"compiler-let",            compiler_let_fn, bad_special2, bad_specialn},
    {"declare",                 declare_fn, bad_special2, bad_specialn},
    {"flet",                    flet_fn, bad_special2, bad_specialn},
    {"labels",                  labels_fn, bad_special2, bad_specialn},
    {"let",                     let_fn, bad_special2, bad_specialn},
#else
    {"~block",                  block_fn, bad_special2, bad_specialn},
    {"~let",                    let_fn, bad_special2, bad_specialn},
#endif
    {NULL,                      0, 0, 0}};

/* end of eval2.c */
