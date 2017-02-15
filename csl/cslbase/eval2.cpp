// eval2.cpp                               Copyright (C) 1989-2017 Codemist

//
// Interpreter (part 2).  apply & some special forms
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


static LispObject apply_lots(int nargs, n_args *f, LispObject def)
//
// Cases with 8 or more args are lifted out here into a subroutine
// to make APPLY a bit shorter and because these cases should be
// uncommon & not worth optimising much.  The code that Microsoft C 6.00A
// produced for this was utterly DREADFUL - maybe other C compilers will
// make a mess of it too.  Anyway I hope it will not be called very often.
// Also I have plans that will deal with functions with many arguments in
// a micer way so this MESS will be able to go away.
//
{   switch(nargs)
    {   case 9:
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
//
// If more than 25 args are going to be passed I will arrange that the
// final ones are built into a list - as if the 25th arg was specified
// as a "&rest" one.  Why?  Because passing VERY large numbers of arguments
// in C is not a good idea - ANSI C compilers are only obliged to support
// up to 31 args, and one some machines this limit seems to really matter.
// But Common Lisp can need more args than that.  I will ignore the fact that
// what I do here is slow.  I will HOPE that calls with 25 or more args
// are very uncommon.
//
        {   int n = nargs;
            LispObject w, *tsp = stack;
#if (ARG_CUT_OFF != 25)
            if (ARG_CUT_OFF != 25)
            {   fprintf(stderr, "\n+++ ARG_CUT_OFF incorrectly configured\n");
                my_exit(EXIT_FAILURE);
            }
#endif
            w = ncons(tsp[-1]);
            tsp[-1] = w;
            while (n > ARG_CUT_OFF)
            {   w = cons(tsp[-2], tsp[-1]);
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
//
// The unpacking here must match "apply_lots" as above.  For up to
// (and including) ARG_CUT_OFF (=25) args things are passed normally.
// beyond that the first ARG_CUT_OFF-1 args are passed normally, and the
// rest are in a list as a final actual arg.  Note that this list will
// have at least two elements.
//
{   int i;
    if (nargs <= ARG_CUT_OFF)
    {   for (i = 0; i<nargs; i++)
        {   LispObject w = va_arg(a, LispObject);
            push(w);
        }
    }
    else
    {   LispObject x;
        for (i = 0; i<(ARG_CUT_OFF-1); i++)
        {   LispObject w = va_arg(a, LispObject);
            push(w);
        }
        x = va_arg(a, LispObject);
//
// Internal consistency should ensure that the list passed here is long
// enough for the following unpacking operation.  But if (as a result of
// internal system muddles it is not maybe the fact that qcar(nil) =
// qcdr(nil) = nil will tend to reduce the damage?
//
        for (; i<nargs; i++)
        {   push(qcar(x));
            x = qcdr(x);
        }
    }
    va_end(a);
}

void push_args_1(va_list a, int nargs)
//
// This is very much like push_args(), but is for the (rather small number
// of) cases where the first argument to a function must NOT be pushed on the
// stack.  See, for instance, "funcall" as an example.
//
{   int i;
    if (nargs <= ARG_CUT_OFF)
    {   for (i = 1; i<nargs; i++)
        {   LispObject w = va_arg(a, LispObject);
            push(w);
        }
    }
    else
    {   LispObject x;
        for (i = 1; i<(ARG_CUT_OFF-1); i++)
        {   LispObject w = va_arg(a, LispObject);
            push(w);
        }
        x = va_arg(a, LispObject);
        for (; i<nargs; i++)
        {   push(qcar(x));
            x = qcdr(x);
        }
    }
    va_end(a);
}


// My plan in a while is to change CSL so that functions of 0, 1, 2 and 3
// arguments are called directly via dedicated function cells. For 4 and
// up args I will pass args 1-3 naturally and the rest as a list, rather as
// if the call had been
//     (fff 1 2 3 (list 4 5 6 7 ...))
// Such a scheme supports having no (serious) limit on the number of arguments
// but does not need va_arg messing around so much. And in particular it
// gets rid of apply_lots() which really is very ugly.

LispObject apply(LispObject fn, int nargs, LispObject env, LispObject from)
//
// There are (nargs) arguments on the Lisp stack, and apply() must use them
// then pop them off.  They were pushed in the order push(arg1); push(arg2),
// and so on, and the stack grows upwards.
// from is a symbol that names the function that called me...
//
{   LispObject def;
    for (;;)
    {   if (symbolp(fn))
        {   debug_assert(1);
            debug_record_symbol(fn);
// Heer I am calling a function named by the symbol "fn" and all the arguments
// have been prepared and are on the stack.
            bool tracing = (qheader(fn) & SYM_TRACED) != 0;
            if (tracing)
            {   push2(fn, from);
                freshline_trace();
                trace_printf("Calling ");
                loop_print_trace(stack[-1]);
                trace_printf(" from ");
                loop_print_trace(stack[0]);
                popv(1);
                trace_printf("\n");
                for (int i=1; i<=nargs; i++)
                {   trace_printf("Arg%d: ", i);
                    loop_print_trace(stack[i-nargs-1]);
                    trace_printf("\n");
                }
                pop(fn);
            }
            def = fn; // this is passed as arg1 to the called code
//
// apply will find arguments on the stack and is responsible for
// popping them before it exits.
//
            {
//
// Because there are nargs values pushed on the (upwards growing) stack,
// &stack[1-nargs] points at the first value pushed, i.e. arg-1.  At one stage
// I had a machine-specific bit of code (called "ncall") to do the following,
// arguing that maybe in assembly code it would be possible to do much better
// than the really ugly switch statement shown now.  My belief now (especially
// given that ncall was used in just one place - here) is that the switch will
// cost no more than the procedure call did, and that in-line code will help
// speed up the common and critical cases of 0, 1, 2 and 3 args.  Also apply
// is otherwise a reasonably short function, so if this switch is needed
// anywhere here is not too bad.
//
                push(fn);
                switch (nargs)
                {
//
// The Standard Lisp Report (Marti et al, Utah UUCS-78-101) only
// requires support for 15 args.  Common Lisp requires at least 50.
// I deal with up to 8 args in-line here (I expect more than that to be
// amazingly uncommon) so that this function is kept under contol.
// Calls with more than 8 args go over to apply_lots, and within that
// function calls with over 25 args have an even more clumsy treatment.
//
                    case 0:
                        def = (*qfnn(fn))(def, 0);
                        break;
                    case 1:
                        def = (*qfn1(fn))(def, stack[-1]);
                        break;
                    case 2:
                        def = (*qfn2(fn))(def, stack[-2], stack[-1]);
                        break;
                    case 3:
                        def = (*qfnn(fn))(def, 3, stack[-3], stack[-2], stack[-1]);
                        break;
                    case 4:
                        def = (*qfnn(fn))(def, 4, stack[-4], stack[-3], stack[-2],
                                          stack[-1]);
                        break;
                    case 5:
                        def = (*qfnn(fn))(def, 5, stack[-5], stack[-4], stack[-3],
                                          stack[-2], stack[-1]);
                        break;
                    case 6:
                        def = (*qfnn(fn))(def, 6, stack[-6], stack[-5], stack[-4],
                                          stack[-3], stack[-2], stack[-1]);
                        break;
                    case 7:
                        def = (*qfnn(fn))(def, 7, stack[-7], stack[-6], stack[-5],
                                          stack[-4], stack[-3], stack[-2], stack[-1]);
                        break;
                    case 8:
                        def = (*qfnn(fn))(def, 8, stack[-8], stack[-7], stack[-6],
                                          stack[-5], stack[-4], stack[-3], stack[-2],
                                          stack[-1]);
                        break;
                    default:
                        def = apply_lots(nargs, qfnn(fn), def);
                        break;
                }
                debug_assert(1);
//
// here I have to pop the stack by hand - note that popv does not
// corrupt exit_count, which tells me how many results were being handed
// back.
//
                pop(fn);
                popv(nargs);
                if (tracing)
                {   push(def);
// In due course I will need to worry about multiple values here
                    freshline_trace();
                    loop_print_trace(fn);
                    trace_printf(" => ");
                    loop_print_trace(stack[0]);
                    trace_printf("\n");
                    pop(def);
                }
                return def;
            }
        }
        else if (!is_cons(fn))
        {   char message[64];
            popv(nargs);
            push(fn);
            char name_of_caller[32];
            from = qpname(from);
            size_t len = length_of_byteheader(vechdr(from)) - CELL;
            if (len >= sizeof(name_of_caller)) len = sizeof(name_of_caller)-1;
            memcpy(name_of_caller, &celt(from, 0), len);
            name_of_caller[len] = 0;
            sprintf(message, "Bad function called from %s: ",
                    name_of_caller);
            aerror1(message, fn);
        }
// apply_lambda() will pop the args from the stack when it is done
        if ((def = qcar(fn)) == lambda)
            return apply_lambda(qcdr(fn), nargs, env, fn);
//
// A bytecoded funarg is stored as (cfunarg <actual fn> <env>) and any call
// to it behaves as if the actual function was called with the environment
// passed as a forced-in first argument.
//
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
                return apply_lambda(qcdr(def), nargs, qcar(def), fn);
        }
        break;
    }
//
// Other cases are all errors.
//
    popv(nargs);
    char message[64];
    char name_of_caller[32];
    from = qpname(from);
    size_t len = length_of_byteheader(vechdr(from)) - CELL;
    if (len >= sizeof(name_of_caller)) len = sizeof(name_of_caller)-1;
    memcpy(name_of_caller, &celt(from, 0), len);
    name_of_caller[len] = 0;
    sprintf(message, "Bad function called from %s: ",
            name_of_caller);
    aerror1(message, fn);
}

//
// Now for implementation of all the special forms...
//

// activity.

static LispObject and_fn(LispObject args, LispObject env)
// also needs to be a macro for Common Lisp
{   stackcheck2(0, args, env);
    STACK_SANITY;
    if (!consp(args)) return onevalue(lisp_true);
    for (;;)
    {   LispObject v = qcar(args);
        args = qcdr(args);
        if (!consp(args)) return eval(v, env);
        push2(args, env);
        v = eval(v, env);
        pop2(env, args);
        if (v == nil) return onevalue(nil);
    }
}

// This is not used at present, but may be wanted sometime so I will
// leave it here for now...
//
//Lisp_Object append(Lisp_Object a, Lisp_Object b)
//{
//  if (!consp(a)) return b;
//  else
//  {   stackcheck2(0, a, b);
//      push(a);
//      b = append(qcdr(a), b);
//      pop(a);
//      return cons(qcar(a), b);
//  }
//}
//

static LispObject block_fn(LispObject args, LispObject env)
{   LispObject p;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push3(qcar(args),          // my_tag
          qcdr(args),          // args
          env);
#define env    stack[0]
#define args   stack[-1]
#define my_tag stack[-2]
//
// I need to augment the (lexical) environment with the name of my
// tag in such a way that return-from can throw out to exactly the
// correct matching level.  This is done by pushing (0 . tag) onto
// the environment - the 0 marks this as a block name.
//
    my_tag = cons(fixnum_of_int(0), my_tag);
    env = cons(my_tag, env);
    p = nil;
    while (consp(args))
    {   p = qcar(args);
        try
        {   START_TRY_BLOCK;
            p = eval(p, env);
        }
        catch (LispReturnFrom e)
        {   qcar(my_tag) = fixnum_of_int(2); // Invalidate
            if (exit_tag == my_tag)
            {   popv(3);
                return nvalues(exit_value, exit_count);
            }
            else throw;
        }
        catch (LispError e)
        {   int _reason = exit_reason;
            err_printf("\nEvaluating: ");
            loop_print_error(qcar(args));
            exit_reason = _reason;
            throw;
        }
        args = qcdr(args);
    }
    popv(3);
    return p;
#undef env
#undef args
#undef my_tag
}

static LispObject catch_fn(LispObject args, LispObject env)
{   LispObject tag, v;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    tag = qcar(args);
    tag = eval(tag, env);
    tag = catch_tags = cons(tag, catch_tags);
    pop2(env, args);
    push(tag);
    try
    {   START_SETJMP_BLOCK;
        v = progn_fn(qcdr(args), env);
    }
    catch (LispThrow e)
    {   pop(tag);
        catch_tags = qcdr(tag);
        qcar(tag) = tag;
        qcdr(tag) = nil;        // Invalidate the catch frame
        if (exit_tag == tag) return nvalues(exit_value, exit_count);
        else throw;
    }
    catch (LispException e)
    {   pop(tag);
        catch_tags = qcdr(tag);
        qcar(tag) = tag;
        qcdr(tag) = nil;        // Invalidate the catch frame
        throw;
    }
    pop(tag);
    catch_tags = qcdr(tag);
    qcar(tag) = tag;
    qcdr(tag) = nil;            // Invalidate the catch frame
    return v;
}

// let_fn_1 is used for various things that bind variables - and in CSL
// that will most commonly be PROG. In PROG there needs to be a TAGBODY
// to cope with GO as well.

#define BODY_LET            0
#define BODY_COMPILER_LET   1
#define BODY_PROG           2

#define local_decs stack[0]
#define specenv    stack[-1]
#define env1       stack[-2]
#define p          stack[-3]
#define q          stack[-4]
#define env        stack[-5]
#define body       stack[-6]
#define bvl        stack[-7]
#define Return(v)  { popv(8); return (v); }

class unbinder_t
{   LispObject *save;
public:
    unbinder_t()
    {   save = stack;
    }
    ~unbinder_t()
    {   stack = save;
        for (LispObject p1 = specenv; p1 != nil; p1 = qcdr(p1))
        {   LispObject w = qcar(p1);
            qvalue(qcar(w)) = qcdr(w);
        }
    }
};

LispObject let_fn_1(LispObject bvlx, LispObject bodyx,
                    LispObject envx, int compilerp)
//
// This will have to look for (declare (special ...)).
// compiler-let forces all of its bindings to be locally special. In
// CSL mode I do not support local declarations, which simplifies and
// speeds things up here. Well to be more precise, I support DECLARE in
// the Compiler, but in the interpreter in non-Common mode every variable
// is SPECIAL.
//
{   stackcheck3(0, bvlx, bodyx, envx);
    push3(bvlx, bodyx, envx);
    push5(nil, nil, envx, nil, nil);
//
// Find local declarations - it is necessary to macro-expand
// items in the body to see if they turn into declarations.
//
    for (;;)
    {   if (!consp(body)) break;
        p = macroexpand(qcar(body), env);
        body = qcdr(body);
        if (!consp(p))
        {   if (stringp(p) && consp(body)) continue;
            body = cons(p, body);
            break;
        }
        if (qcar(p) != declare_symbol)
        {   body = cons(p, body);
            break;
        }
        for (p = qcdr(p); consp(p); p = qcdr(p))
        {   q = qcar(p);
            if (!consp(q) || qcar(q) != special_symbol) continue;
            // here q says (special ...)
            for (q=qcdr(q); consp(q); q = qcdr(q))
                local_decs = cons(qcar(q), local_decs);
        }
    }

    for (; consp(bvl); bvl=qcdr(bvl))
    {   LispObject z;
        q = qcar(bvl);
        if (consp(q))
        {   z = qcdr(q);
            q = qcar(q);
            if (consp(z)) z = qcar(z); else z = nil;
        }
        else z = nil;
        if (!is_symbol(q) || q==nil || q==lisp_true)
        {   LispObject qq = q;
            error(1, err_bad_bvl, qq);
        }
        else
        {   Header h = qheader(q);
            if (z != nil) z = eval(z, env);
            z = cons(q, z);
            if (compilerp == BODY_COMPILER_LET)
            {   specenv = cons(z, specenv);
                q = acons(q, work_symbol, env1);
                env1 = q; // Locally special
            }
            else if (h & SYM_GLOBAL_VAR) aerror1("Attempt to bind", q);
            else if (h & SYM_SPECIAL_VAR) specenv = cons(z, specenv);
            else
            {   LispObject w;
                for (w = local_decs; w!=nil; w = qcdr(w))
                {   if (q != qcar(w)) continue;
                    qcar(w) = fixnum_of_int(0);
// The next few calls to cons() maybe lose w, but that is OK!
                    specenv = cons(z, specenv);
                    q = acons(q, work_symbol, env1);
                    env1 = q;
                    goto bound;
                }
                env1 = cons(z, env1);
            bound:  ;
            }
        }
    }

    while (local_decs!=nil)         // Pervasive special declarations
    {   LispObject q1 = qcar(local_decs);
        local_decs=qcdr(local_decs);
        if (!is_symbol(q1)) continue;
        q1 = acons(q1, work_symbol, env1);
        env1 = q1;
    }
// I treat the case where there are no new (special) bindings specially
// because in that case I can tail-call to the next stage of evaluation, and
// that saves stack.
    if (specenv == nil)
    {   LispObject bodyx = body, env1x = env1;
//
// See expansion of Return() for an explanation of why body and env1 have
// been moved into new local variables before the call..
//
        if (compilerp == BODY_PROG)
        {   Return(tagbody_fn(bodyx, env1x));
        }
        else
        {   Return(progn_fn(bodyx, env1x));
        }
    }
//
// I instate the special bindings after all values to bind have been
// collected. But this is where I will need to arrange to ensure that
// when for ANY reason at all the code here is unwound that the fluid
// bindings concerned get restored.
    for (p = specenv; p != nil; p = qcdr(p))
    {   LispObject w = qcar(p), v = qcar(w), z = qcdr(w);
        LispObject old = qvalue(v);
        qvalue(v) = z;
        qcdr(w) = old;
    }
// The above has instated bindings. Subject to not getting asynchronous
// interruptions once I start to bind any I bind all.
    {   unbinder_t raii;
        if (compilerp == BODY_PROG)
            body = (tagbody_fn(body, env1));
        else body = (progn_fn(body, env1));
    }
    bodyx = body;
    Return(bodyx);
#undef local_decs
#undef specenv
#undef env1
#undef p
#undef q
#undef env
#undef body
#undef bvl
#undef Return
}

static LispObject compiler_let_fn(LispObject args, LispObject env)
{   if (!consp(args)) return onevalue(nil);
    STACK_SANITY;
    return let_fn_1(qcar(args), qcdr(args), env, BODY_COMPILER_LET);
}

static LispObject cond_fn(LispObject args, LispObject env)
{   stackcheck2(0, args, env);
    STACK_SANITY;
    while (consp(args))
    {   LispObject p = qcar(args);
        if (consp(p))
        {   LispObject p1;
            push2(args, env);
            p1 = qcar(p);
            p1 = eval(p1, env);
            pop2(env, args);
            if (p1 != nil)
            {   args = qcdr(qcar(args));
// Here I support the case "(cond (predicate) ...)" with no consequents
// as returning the non-nil value of the predicate.
                if (!consp(args)) return onevalue(p1);
                else return progn_fn(args, env);
            }
        }
        args = qcdr(args);
    }
    return onevalue(nil);
}

LispObject declare_fn(LispObject, LispObject)
//
// declarations can only properly occur at the heads of various
// special forms, and so may NOT be evaluated in an ordinary manner.
// Thus I am entitled (just about) to make this a no-op.  It would
// probably be better to arrange that (declare ...) never got evaluated
// and then I could raise an error if this bit of code got activated.
// Indeed (declare ...) probably does not ever get evaluated - still
// a no-op here seems the safest bet. And in CSL mode this allows one to
// have left DECLAREs in there for the benefit of the compiler.
//
{   return onevalue(nil);
}


#define flagged_lose(v) \
    ((fv = qfastgets(v)) != nil && elt(fv, 1) != SPID_NOPROP)

static LispObject defun_fn(LispObject args, LispObject)
{
//
// defun is eventually expected (required!) to be a macro rather than (maybe
// as well as?) a special form.  For bootstrap purposes it seems useful to
// build it in as a special form.  Also this special form is quite good enough
// in CSL mode
//
    LispObject fname;
    STACK_SANITY;
    if (consp(args))
    {   fname = qcar(args);
        args = qcdr(args);
        if (is_symbol(fname))
        {   LispObject fv;
            if (qheader(fname) & SYM_SPECIAL_FORM)
                error(1, err_redef_special, fname);
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
                set_fns(fname, undefined1, undefined2, undefinedn);
                qenv(fname) = fname;
            }
//
// qfn() can contain 'interpreted' for a function defined wrt the null
// environment, or 'funarged' for one with an environment - in the latter
// case the definition (in qenv()) is a pair (<def> . <env>)
//
            qenv(fname) = args;         // Sort of notional lambda present
            set_fns(fname, interpreted1, interpreted2, interpretedn);
            if (qvalue(comp_symbol) != nil &&
                qfn1(compiler_symbol) != undefined1)
            {   push(fname);
                args = ncons(fname);
                (qfn1(compiler_symbol))(compiler_symbol, args);
                pop(fname);
            }
            return onevalue(fname);
        }
    }
    aerror("defun");
}

static LispObject defmacro_fn(LispObject args, LispObject)
{
//
// defmacro is eventually expected (required!) to be a macro rather than (maybe
// as well as?) a special form.  For bootstrap purposes it seems useful to
// build it in as a special form.
//
    LispObject fname;
    STACK_SANITY;
    if (consp(args))
    {   fname = qcar(args);
        args = qcdr(args);
        if (!consp(args)) aerror("Badly formatted use of defmacro");
        LispObject bvl = qcar(args);
// Here if bvl is a list such as (u) I will expand it to be (u &optional g).
        if (consp(bvl) && qcdr(bvl) == nil)
            args = cons(list3(qcar(bvl), opt_key, Lgensym(nil, 0)),
                        qcdr(args)); 
        if (is_symbol(fname))
        {   if ((qheader(fname) & (SYM_C_DEF | SYM_CODEPTR)) ==
                (SYM_C_DEF | SYM_CODEPTR)) return onevalue(fname);
            qheader(fname) |= SYM_MACRO;
//
// Note that a name can have a definition as a macro and as a special form,
// and in that case the qfn() cell gives the special form and the qenv()
// cell the macro definition.  Otherwise at present I put 'undefined'
// in the qfn() cell, but in due course I will want something else as better
// protection against compiled code improperly attempting to call a macro.
// Note also that if the symbol was a special form before I do not want
// to clear the C_DEF flag, since the special form must be re-instated when
// I reload the system.
//
            if ((qheader(fname) & SYM_SPECIAL_FORM) == 0)
            {   qheader(fname) &= ~SYM_C_DEF;
                if (qfn1(fname) != undefined1 &&
                    qvalue(redef_msg) != nil)
                {   debug_printf("\n+++ ");
                    loop_print_debug(fname);
                    debug_printf(" redefined as a macro\n");
                }
                set_fns(fname, undefined1, undefined2, undefinedn);
            }
            qenv(fname) = args;         // Sort of notional lambda present
            if (qvalue(comp_symbol) != nil &&
                qfn1(compiler_symbol) != undefined1)
            {   LispObject t1, t2;
                push(fname);
                if (!(consp(args) &&
                      consp(qcdr(args)) &&
                      qcdr(qcdr(args)) == nil &&
                      (t1 = qcar(args),
                       t2 = qcdr(qcar(qcdr(args))),
                       equal(t1, t2))))
                {   fname = stack[0];
                    args = ncons(fname);
                    (qfn1(compiler_symbol))(compiler_symbol, args);
                }
                pop(fname);
            }
            return onevalue(fname);
        }
    }
    aerror("defmacro");
}

static LispObject eval_when_fn(LispObject args, LispObject env)
//
// When interpreted, eval-when just looks for the situation EVAL.
//
{   LispObject situations;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    situations = qcar(args);
    args = qcdr(args);
    while (consp(situations))
    {   if (qcar(situations) == eval_symbol) return progn_fn(args, env);
        situations = qcdr(situations);
    }
    return onevalue(nil);
}

static LispObject flet_fn(LispObject args, LispObject env)
{   LispObject my_env, d;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    my_env = env;
    d = qcar(args);     // The bunch of definitions
    args = qcdr(args);
    while (consp(d))
    {   LispObject w = qcar(d);
        if (consp(w) && consp(qcdr(w)))
        {   LispObject w1;
            push4(args, d, env, w);
            w1 = list2star(funarg, my_env, qcdr(w));
            pop(w);
            w1 = cons(w1, qcar(w));
            pop(env);
            env = cons(w1, env);
            pop2(d, args);
        }
        d = qcdr(d);
    }
//
// Treat body as (let nil ...) to get (declare ...) recognized.
//
    return let_fn_1(nil, args, env, BODY_LET);
}

LispObject function_fn(LispObject args, LispObject env)
{
//
// For most things this behaves just like (quote xxx), but
// (function (lambda (x) y)) gets converted to
// (funarg env (x) y).
//
    STACK_SANITY;
    if (consp(args) && qcdr(args) == nil)
    {   args = qcar(args);
        if (consp(args) && qcar(args) == lambda)
            args = list2star(funarg, env, qcdr(args));
        return onevalue(args);
    }
    aerror("function");
}


static LispObject go_fn(LispObject args, LispObject env)
{   LispObject p, tag;
    STACK_SANITY;
    if (!consp(args)) aerror("go");
    else tag = qcar(args);
    for(p=env; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p), z;
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(1) &&
            (z = qcar(qcdr(w)), eql(z, tag)))
        {   exit_tag = w;
            exit_reason = UNWIND_GO;
            throw LispGo();  // only exit_tag matters here.
        }
    }
    error(1, err_go_tag, tag);
}

static LispObject if_fn(LispObject args, LispObject env)
{   LispObject p=nil, tr=nil, fs=nil;
    STACK_SANITY;
    if (!consp(args)) aerror("if");
    p = qcar(args);
    args = qcdr(args);
    if (!consp(args)) aerror("if");
    tr = qcar(args);
    args = qcdr(args);
    if (!consp(args)) fs = nil;
    else
    {   fs = qcar(args);
        args = qcdr(args);
        if (args != nil) aerror("if");
    }
    stackcheck4(0, p, env, tr, fs);
    push3(fs, tr, env);
    p = eval(p, env);
    pop3(env, tr, fs);
    if (p == nil)
        return eval(fs, env);      // tail call on result
    else return eval(tr, env);      // ... passing back values
}

static LispObject labels_fn(LispObject args, LispObject env)
{   LispObject my_env, d;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    my_env = env;
    d = qcar(args);     // The bunch of definitions
    while (consp(d))
    {   LispObject w = qcar(d);
        if (consp(w) && consp(qcdr(w)))
        {   LispObject w1;
            push4(args, d, env, w);
            w1 = list2star(funarg, nil, qcdr(w));
            pop(w);
            w1 = cons(w1, qcar(w));
            pop(env);
            env = cons(w1, env);
            pop2(d, args);
        }
        d = qcdr(d);
    }
//
// Now patch up the environments stored with the local defs so as to
// permit mutual recursion between them all.
//
    for (d=env; d!=my_env; d=qcdr(d))
        qcar(qcdr(qcar(qcar(d)))) = env;
    return let_fn_1(nil, qcdr(args), env, BODY_LET);
}

static LispObject let_fn(LispObject args, LispObject env)
{   if (!consp(args)) return onevalue(nil);
    STACK_SANITY;
    return let_fn_1(qcar(args), qcdr(args), env, BODY_LET);
}

static LispObject letstar_fn(LispObject args, LispObject env)
//
// This will have to look for (declare (special ...)), unless
// I am in CSL mode.
//
{   if (!consp(args)) return onevalue(nil);
    STACK_SANITY;
    stackcheck2(0, args, env);
    push3(qcar(args), qcdr(args), env);
    push5(nil, nil,                // p, q
          env, nil, nil);          // env1, specenv, local_decs
#define local_decs stack[0]
#define specenv    stack[-1]
#define env1       stack[-2]
#define p          stack[-3]
#define q          stack[-4]
#define env        stack[-5]
#define body       stack[-6]
#define bvl        stack[-7]
#define Return(v)  { popv(8); return (v); }
    for (;;)
    {   if (!consp(body)) break;
        p = macroexpand(qcar(body), env);
        body = qcdr(body);
        if (!consp(p))
        {   if (stringp(p) && consp(body)) continue;
            body = cons(p, body);
            break;
        }
        if (qcar(p) != declare_symbol)
        {   body = cons(p, body);
            break;
        }
        for (p = qcdr(p); consp(p); p = qcdr(p))
        {   q = qcar(p);
            if (!consp(q) || qcar(q) != special_symbol) continue;
            // here q says (special ...)
            for (q=qcdr(q); consp(q); q = qcdr(q))
                local_decs = cons(qcar(q), local_decs);
        }
    }
// Now I will start doing some binding...
    try
    {   START_SETJMP_BLOCK;
        for (; consp(bvl); bvl=qcdr(bvl))
        {   LispObject z;
            q = qcar(bvl);
            if (consp(q))
            {   z = qcdr(q);
                q = qcar(q);
                if (consp(z)) z = qcar(z); else z = nil;
            }
            else z = nil;
            if (!is_symbol(q) || q==nil || q==lisp_true)
            {   error(1, err_bad_bvl, q);
            }
            else
            {
                Header h = qheader(q);
                if (z != nil)
                z = eval(z, env);
                if (h & SYM_GLOBAL_VAR)
                    aerror1("attempt to bind", q);
                if (h & SYM_SPECIAL_VAR)
                {   p = z;
                    z = acons(q, qvalue(q), specenv);
                    specenv = z;
                    qvalue(q) = p;
                }
                else
                {   for (p = local_decs; p!=nil; p = qcdr(p))
                    {   LispObject w;
                        if (q != qcar(p)) continue;
                        qcar(p) = fixnum_of_int(0);
                        w = acons(q, qvalue(q), specenv);
                        specenv = w;
                        w = acons(q, work_symbol, env);
                        env = w;
                        qvalue(q) = z;
                        goto bound;
                    }
                    q = acons(q, z, env);
                    env = q;
                bound:  ;
                }
            }
        }
        while (local_decs!=nil)         // Pervasive special declarations
        {   q = qcar(local_decs);
            local_decs=qcdr(local_decs);
            if (!is_symbol(q)) continue;
            q = acons(q, work_symbol, env);
            env = q;
        }
        body = progn_fn(body, env);
        for (bvl = specenv; bvl != nil; bvl = qcdr(bvl))
        {   LispObject w = qcar(bvl), v = qcar(w), z = qcdr(w);
            qvalue(v) = z;
        }
        {   LispObject bodyx = body;
            Return(bodyx);
        }
    }
    catch (LispException e)
    {   for (bvl = specenv; bvl != nil; bvl = qcdr(bvl))
        {   LispObject w = qcar(bvl), v = qcar(w), z = qcdr(w);
            qvalue(v) = z;
        }
        popv(8);
        throw;
    }
#undef local_decs
#undef specenv
#undef env1
#undef p
#undef q
#undef env
#undef body
#undef bvl
#undef Return
}

static LispObject bad_specialfn2(LispObject env, LispObject a, LispObject b)
{   aerror1("bad special function", env);
}

setup_type const eval2_setup[] =
{   {"and",                     and_fn, bad_specialfn2, BAD_SPECIALN},
    {"catch",                   catch_fn, bad_specialfn2, BAD_SPECIALN},
    {"cond",                    cond_fn, bad_specialfn2, BAD_SPECIALN},
    {"eval-when",               eval_when_fn, bad_specialfn2, BAD_SPECIALN},
    {"function",                function_fn, bad_specialfn2, BAD_SPECIALN},
    {"go",                      go_fn, bad_specialfn2, BAD_SPECIALN},
    {"if",                      if_fn, bad_specialfn2, BAD_SPECIALN},
    {"let*",                    letstar_fn, bad_specialfn2, BAD_SPECIALN},
// DE and DM are used as low level primitives in the Common Lisp bootstrap
    {"de",                      defun_fn, bad_specialfn2, BAD_SPECIALN},
    {"dm",                      defmacro_fn, bad_specialfn2, BAD_SPECIALN},
    {"declare",                 declare_fn, bad_specialfn2, BAD_SPECIALN},
    {"compiler-let",            compiler_let_fn, bad_specialfn2, BAD_SPECIALN},
    {"flet",                    flet_fn, bad_specialfn2, BAD_SPECIALN},
    {"labels",                  labels_fn, bad_specialfn2, BAD_SPECIALN},
// For the purposes of Reduce there is a problem with the names LET anb BLOCK
// because they are used in the system, and having them as Lisp-level special
// forms would clash. I provide implementations but with names prefixed by
// "~". This is perhaps an issue that ough to get resolved some time.
//  {"block",                   block_fn, bad_specialfn2, BAD_SPECIALN},
//  {"let",                     let_fn, bad_specialfn2, BAD_SPECIALN},
    {"~block",                  block_fn, bad_specialfn2, BAD_SPECIALN},
    {"~let",                    let_fn, bad_specialfn2, BAD_SPECIALN},
    {NULL,                      0, 0, 0}
};

// end of eval2.cpp
