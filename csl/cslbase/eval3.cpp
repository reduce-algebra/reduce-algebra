// eval3.cpp                               Copyright (C) 1991-2017 Codemist

//
// Interpreter (part 3).
// Implementations of special forms (interpreted versions).
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


#include "headers.h"


#define BODY_LET            0
#define BODY_COMPILER_LET   1
#define BODY_PROG           2

static LispObject macrolet_fn(LispObject args, LispObject env)
{   LispObject d;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    d = qcar(args);     // The bunch of definitions
    while (consp(d))
    {   LispObject w = qcar(d);     // w = (name bvl ...)
        if (consp(w) && consp(qcdr(w)))
        {
//
// Here I need to call (expand-definer <form> nil) to map
// macro specifications with all the possible magic options into ones
// which just take 2 args, a form and an environment.
//
            push2(args, env);
            w = cons(expand_def_symbol, w);
            w = Lfuncall_3(nil, expand_def_symbol, w, nil);
//
// I expect expand-definer to return either
//     (~~defmacro name bvl ...)
// OR  (progn XXX (~~defmacro name bvl ...))
//     where XXX is exactly one form.
//
            if (qcar(w) == progn_symbol)
                w = qcar(qcdr(qcdr(w)));
            w = qcdr(w);
            w = cons(qcdr(w), qcar(w));
            pop2(env, args);
            env = cons(w, env);
        }
        d = qcdr(d);
    }
    return let_fn_1(nil, qcdr(args), env, BODY_LET);
}

static LispObject mv_prog1_fn(LispObject args, LispObject env)
{   LispObject r, rl;
    STACK_SANITY;
    int nargs, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    rl = nil;
    nargs = exit_count;
    push(r);
//
// I could use the Lisp stack to save things here, but I hope that this
// function is not used much and performance will not matter.
//
    for (i=nargs; i>=2; i--)
        rl = cons_no_gc((&mv_2)[i-2], rl);
    rl = cons_gc_test(rl);
    push(rl);
    while (is_cons(args = qcdr(args)) && args!=nil)
    {   LispObject w;
        push2(args, env);
        w = qcar(args);
        eval(w, env);
        pop2(env, args);
    }
    pop(rl);
    for (i = 2; i<=nargs; i++)
    {   (&mv_2)[i-2] = qcar(rl);
        rl = qcdr(rl);
    }
    pop(r);
    return nvalues(r, nargs);
}

static LispObject or_fn(LispObject args, LispObject env)
// also needs to be a macro for Common Lisp
{   if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    STACK_SANITY;
    for (;;)
    {   LispObject v = qcar(args);
        args = qcdr(args);
        if (!consp(args)) return eval(v, env);
        push2(args, env);
        v = eval(v, env);
        pop2(env, args);
        if (v != nil) return onevalue(v);
    }
}

// Note that (BLOCK ...) also catches LispReturnFrom exceptions, and that
// Common Lisp really thinks of PROG as a combination of LET, BLOCK and
// TAGBODY.

static LispObject prog_fn(LispObject args, LispObject env)
{   if (!consp(args) || !consp(qcdr(args))) return onevalue(nil);
    stackcheck2(0, args, env);
    STACK_SANITY;
    push3(nil, args, env);
#define env    stack[0]
#define args   stack[-1]
#define my_tag stack[-2]
//
// I need to augment the (lexical) environment with a null block
// tag so that (return ..) will work as required. See block_fn for
// further elaboration since (block ..) is the main way of introducing
// new block tags.
//
    my_tag = cons(fixnum_of_int(0), nil);
    env = cons(my_tag, env);
    try
    {   START_TRY_BLOCK;
        let_fn_1(qcar(args), qcdr(args), env, BODY_PROG);
    }
    catch (LispReturnFrom e)
    {   qcar(my_tag) = fixnum_of_int(2);    // Invalidate
        if (exit_tag == my_tag)
        {   popv(3);
            return exit_value;  // exit_count already OK here
        }
// It could be that the RETURN(-FROM) is heading to be handled by some
// enclosing block.
        else throw;
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_FNAME)
        {   err_printf("\nEvaluating: "); // A bit of backtrace on errors
            loop_print_error(args);
        }
        popv(3);
        exit_reason = _reason;
        throw;
    }
    popv(3);  // I get here if using let_fn_1 to process the body of the
              // PROG just returned without doing a (RETURN ...).
    return onevalue(nil);
#undef env
#undef args
#undef my_tag
}

LispObject progn_fn(LispObject args, LispObject env)
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    f = nil;
    for (;;)
    {   f = qcar(args);
        args = qcdr(args);
        if (!consp(args)) break;
        push3(args, env, f);
        on_backtrace(
            (void)eval(f, env),
            // Action for backtrace here...
            pop3(f, env, args);
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            });
        pop3(f, env, args);
    }
    return eval(f, env);    // tail call on last item in the progn
}

static LispObject prog1_fn(LispObject args, LispObject env)
//
// prog1 and prog2 will be implemented as macros for Common Lisp,
// and are here implemented as special forms too in the expectation
// that that will be good for performance.
//
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil); // (prog1) -> nil
    stackcheck2(0, args, env);
    push2(args, env);
    f = qcar(args);
    f = eval(f, env);              // first arg
    pop2(env, args);
    push(f);
    for (;;)
    {   args = qcdr(args);
        if (!consp(args)) break;
        push2(args, env);
        {   LispObject w = qcar(args);
            (void)eval(w, env);
        }
        pop2(env, args);
    }
    pop(f);
    return onevalue(f);     // always hands back just 1 value
}

static LispObject prog2_fn(LispObject args, LispObject env)
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil); // (prog2) -> nil
    stackcheck2(0, args, env);
    push2(args, env);
    args = qcar(args);
    (void)eval(args, env);                    // discard first arg
    pop2(env, args);
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil); // (prog2 x) -> nil
    push2(args, env);
    f = qcar(args);
    f = eval(f, env);                       // second arg
    pop2(env, args);
    push(f);
    for (;;)
    {   args = qcdr(args);
        if (!consp(args)) break;
        push2(args, env);
        args = qcar(args);
        (void)eval(args, env);
        pop2(env, args);
    }
    pop(f);
    return onevalue(f);     // always hands back just 1 value
}

#define specenv stack[0]
#define vals    stack[-1]
#define syms    stack[-2]
#define env     stack[-3]
#define args    stack[-4]

class RAIIunbind_progv_specials
{   LispObject *save;
public:
    RAIIunbind_progv_specials()
    {   save = stack;
    }
    ~RAIIunbind_progv_specials()
    {   stack = save;
        while (specenv != nil)
        {   LispObject p = qcar(specenv);
            qvalue(qcar(p)) = qcdr(p);
            specenv = qcdr(specenv);
        }
        popv(4);
    }
};

static LispObject progv_fn(LispObject args_x, LispObject env_x)
{   LispObject syms_x, vals_x, specenv_x, w;
    STACK_SANITY;
    if (!consp(args_x)) return onevalue(nil);
    stackcheck2(0, args_x, env_x);
    syms_x = vals_x = specenv_x = nil;
    syms_x = qcar(args_x);
    args_x = qcdr(args_x);
    push5(args_x, env_x, syms_x, vals_x, specenv_x);

    syms = eval(syms, env);
    if (!consp(args))
    {   popv(5);
        return nil;
    }
    w = qcar(args);
    args = qcdr(args);
    vals = eval(w, env);
    if (!consp(args))
    {   popv(5);
        return nil;
    }
    while (consp(syms))
    {   LispObject v = qcar(syms);
        LispObject w1;
        if (consp(vals))
        {   w = qcar(vals);
            vals = qcdr(vals);
        }
        else w = unset_var;
        syms = qcdr(syms);
        if (!is_symbol(v) || v==nil || v==lisp_true) continue;
        w1 = cons(v, qvalue(v));
//
// If I were to take the error exit here then some variables would have
// been set to their new values and some not. That would be a mess!
//
        qvalue(v) = w;
        specenv = cons(w1, specenv);
    }
    {   RAIIunbind_progv_specials unbind_progv_variables;
        args = progn_fn(args, env);
    }
    pop(w);
#undef specenv
#undef vals
#undef syms
#undef env
#undef args
    return w;
}

LispObject quote_fn(LispObject args, LispObject)
{   if (consp(args) && qcdr(args) == nil) return onevalue(qcar(args));
    aerror("quote");
}

static LispObject return_fn(LispObject args, LispObject env)
{
//
// First check that the block name (nil in this case) is lexically available
//
    STACK_SANITY;
    LispObject p;
    stackcheck2(0, args, env);
    for(p=env; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p);
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(0) && qcdr(w) == nil)
        {   p = w;
            goto tag_found;
        }
    }
    error(1, err_block_tag, nil);
tag_found:
    if (consp(args))
    {   push(p);
        p = qcar(args);
        env = eval(p, env);
        pop(p);
        exit_value = env;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    throw LispReturnFrom();
}

static LispObject return_from_fn(LispObject args, LispObject env)
{   LispObject p, tag;
    stackcheck2(0, args, env);
    STACK_SANITY;
    if (!consp(args)) tag = nil;
    else
    {   tag = qcar(args);
        args = qcdr(args);
    }
    for(p=env; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p);
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(0) && qcdr(w) == tag)
        {   p = w;
            goto tag_found;
        }
    }
    error(1, err_block_tag, tag);
tag_found:
    if (consp(args))
    {   push(p);
        p = qcar(args);
        env = eval(p, env);
        pop(p);
        exit_value = env;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    throw LispReturnFrom();
}

static LispObject setq_fn(LispObject args, LispObject env)
{   LispObject var, val = nil;
    STACK_SANITY;
    stackcheck2(0, args, env);
    while (consp(args))
    {   var = qcar(args);
        if (!is_symbol(var) || var == nil || var == lisp_true ||
            (qheader(var) & SYM_KEYWORD_VAR) == SYM_KEYWORD_VAR)
            aerror1("setq (bad variable)", var);
        args = qcdr(args);
        if (consp(args))
        {   push3(args, env, var);
            val = qcar(args);
            val = eval(val, env);
            pop3(var, env, args);
            args = qcdr(args);
        }
        else val = nil;
        if ((qheader(current_function) & SYM_TRACESET) != 0)
        {   push4(args, env, var, val);
            freshline_trace();
            loop_print_trace(current_function);
            trace_printf(":  ");
            loop_print_trace(stack[-1]);
            trace_printf(" := ");
            loop_print_trace(stack[0]);
            trace_printf("\n");
            pop4(val, var, env, args);
        }
        if ((qheader(var) & SYM_KEYWORD_VAR) == SYM_SPECIAL_VAR ||
            (qheader(var) & SYM_KEYWORD_VAR) == SYM_GLOBAL_VAR)
            qvalue(var) = val;
        else
        {   LispObject p = env, w;   // Here it seems to be a local variable,
                                     // or it could be locally FLUID.
            for (;;)
            {   if (!consp(p))
                {   qheader(var) |= SYM_SPECIAL_VAR;
#ifdef SOME_TIME_LATER
// If I display this message - which could be viewed as a proper error report -
// it leds to multiple failures in the Reduce regressions where scripting
// assumes that assignment to a variable is valid without any declaration.
                    push3(args, env, var);
                    debug_printf("\n+++++ "); loop_print_debug(var);
                    debug_printf(" proclaimed SPECIAL by SETQ\n");
                    pop3(var, env, args);
#endif
                    qvalue(var) = val;
                    break;
                }
                w = qcar(p);
                if (qcar(w) == var)
                {   if (qcdr(w) == work_symbol) qvalue(var) = val;
                    else qcdr(w) = val;
                    break;
                }
                p = qcdr(p);
            }
        }
    }
    return onevalue(val);
}

// tagbody does the bit of PROG that covers labels.

LispObject tagbody_fn(LispObject args, LispObject env)
{   LispObject f, p, my_env;
//
// Bind the labels that occur in this block.  Note that I invalidate
// these bindings if I ever exit from this block, so that nobody
// even thinks that they can use (go xx) to get back in.
//
    stackcheck2(0, args, env);
    STACK_SANITY;
    push2(env, args);
    for (p=args; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p);
        if (!consp(w))
        {   LispObject w1;
            push2(p, env);
            w1 = cons(fixnum_of_int(1), p);
            pop(env);
            env = cons(w1, env);
            pop(p);
        }
    }
// That has put my new version of env with bindings of the form
//    (1 . <location in the tagbody>)
// for each label present. In other words it goes
//    env = ( ... (1 labelname <continuation>) ... )
// where bindings for variable in the environment would have a symbol
// so the integer 1 here distinguishes these as label bindings.
    pop(args);
//
// (go xx) sets exit_tag to xx, which is then noticed next time tagbody
// is about to do anything.
//
    for (p=args; consp(p); p = qcdr(p))
    {   f = qcar(p);
        if (!is_cons(f)) continue; // Do not evaluate labels
        push3(p, env, f);
        try
        {   START_TRY_BLOCK;
            (void)eval(f, env);
        }
        catch (LispGo e)
        {   int _reason = exit_reason;
            pop3(f, env, p);
            my_env = stack[0];
// I need to do this search. Well in the code that implemented GO I checked
// that the destination label was bound as a label. That was so that I could
// give a decent diagnostic if it was not. The scan here is to see if it is
// a label in THIS level of a tagbody... and if not I will hand it upwards.
            for (p=env; p!=my_env; p=qcdr(p)) // scan label bindings
            {   LispObject w = qcar(p);
                if (w != exit_tag) continue;
// Now I have found the label I needed to jump to. Hoorah.
                p = qcdr(w);
                break;
            }
            if (p != my_env) continue; // take the GOTO
// If I drop out of the loop that means that the target label was
// not present in this block. Tidy up the label bindings to be very
// certain nobody can re-use them.
            while (env != my_env)
            {   qcar(qcar(env)) = fixnum_of_int(2);
                env = qcdr(env);
            }
// Because this is a sort of error I will display a message. It was for
// the benefit of this code that I had stacked f, the expression that
// contained the (GO ..) statement. 
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            }
// Re-throw the LispGo exception to try again at some outer level.
            exit_reason = _reason;
            throw;
        }
        catch (LispError e)
        {   int _reason = exit_reason;
            pop3(f, env, p);
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            }
// Re-throw some other exception that counted as an error.
            exit_reason = _reason;
            throw;
        }
        pop3(f, env, p);
    }
// This is where I drop off the end of the tagbody, so I tidy up and
// return nil.
    pop(my_env);
    while (env != my_env)
    {   qcar(qcar(env)) = fixnum_of_int(2);
        env = qcdr(env);
    }
    return onevalue(nil);
}

static LispObject the_fn(LispObject args, LispObject env)
//
// in effect an identity function for the present
//
{   if (!consp(args)) return onevalue(nil);
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil);
    args = qcar(args);
    return eval(args, env);
}

//
// In Common Lisp mode THROW has to be a special form because of the
// case where the information being thrown involves multiple values. For
// Standard Lisp I can perfectly well provide a simple function.
//

static LispObject throw_fn(LispObject args, LispObject env)
{   LispObject tag, p;
    STACK_SANITY;
    if (!consp(args)) aerror("throw");
    stackcheck2(0, args, env);
    tag = qcar(args);
    args = qcdr(args);
    push2(args, env);
    tag = eval(tag, env);
    pop2(env, args);
    for (p = catch_tags; p!=nil; p=qcdr(p))
        if (tag == qcar(p)) goto tag_found;
    aerror("throw: tag not found");
tag_found:
    if (consp(args))
    {   push(p);
        tag = qcar(args);
        tag = eval(tag, env);
        pop(p);
        exit_value = tag;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    throw LispThrow();
}

void Lthrow_one_value(LispObject env, LispObject tag, LispObject val)
{   LispObject p;
    STACK_SANITY;
    for (p = catch_tags; p!=nil; p=qcdr(p))
        if (tag == qcar(p)) goto tag_found;
    aerror("throw: tag not found");
tag_found:
    exit_value = val;
    exit_count = 1;
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    throw LispThrow();
}

LispObject Lthrow_nil(LispObject env, LispObject tag)
{   Lthrow_one_value(nil, tag, nil);
}

static LispObject unless_fn(LispObject args, LispObject env)
{   LispObject w;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    w = qcar(args);
    w = eval(w, env);
    pop2(env, args);
    if (w != nil) return onevalue(nil);
    else return progn_fn(qcdr(args), env);
}

static LispObject unwind_protect_fn(LispObject args, LispObject env)
{   LispObject r = nil, rl = nil;
    STACK_SANITY;
    int nargs = 0, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    try
    {   START_TRY_BLOCK;
        r = eval(r, env);
    }
    catch (LispException e)
    {   pop2(env, args);
        LispObject xt, xv;
        int xc, xr;
//
// Here I am in the process of exiting because of a throw, return-from,
// go or error.  I need to save all the internal stuff that tells me
// what is going on so I can restore it after the clean-up forms have been
// processed.  The values involved are:
//  (a) exit_tag       marks use of go, return-from or throw
//  (b) exit_value     first result value (throw, return-from)
//  (c) exit_count     number of values (throw, return-from)
//  (d) mv2,...        as indicated by exit_count
//  (e) exit_reason    what it says.
//
        xt = qvalue(trap_time);
        qvalue(trap_time) = nil; // No timeouts in recovery code
        push(xt);
        xv = exit_value;
        xt = exit_tag;
        xc = exit_count;
        xr = exit_reason;
        push2(xv, xt);
        for (i=xc; i>=2; i--)
            rl = cons_no_gc((&mv_2)[i-2], rl);
        rl = cons_gc_test(rl);
        push(rl);
        while (is_cons(args = qcdr(args)) && args!=nil)
        {   LispObject w = qcar(args);
            push2(args, env);
            (void)eval(w, env);
            pop2(env, args);
        }
        pop3(rl, xt, xv);
        for (i = 2; i<=xc; i++)
        {   (&mv_2)[i-2] = qcar(rl);
            rl = qcdr(rl);
        }
        exit_value = xv;
        exit_tag   = xt;
        exit_count = xc;
        exit_reason = xr;
        pop(xt);
        qvalue(trap_time) = xt;
        throw;                   // reinstate the exception
    }
    pop2(env, args);
//
// Now code (just like multiple-value-prog1) that evaluates the
// cleanup forms in the case that the protected form exits normally.
//
    nargs = exit_count;
    push2(args, env);
    for (i=nargs; i>=2; i--)
        rl = cons_no_gc((&mv_2)[i-2], rl);
    rl = cons_gc_test(rl);
    push(rl);
#define env  stack[-1]
#define args stack[-2]
    while (is_cons(args = qcdr(args)) && args!=nil)
    {   LispObject w = qcar(args);
        (void)eval(w, env);
    }
#undef env
#undef args
    pop(rl);
    popv(2);
    for (i = 2; i<=nargs; i++)
    {   (&mv_2)[i-2] = qcar(rl);
        rl = qcdr(rl);
    }
    return nvalues(r, nargs);
}

//
// Errorset is not defined as part of COMMON Lisp but I want it in
// any Lisp system that I use notwithstanding that.
//

const volatile char *errorset_msg;
static volatile char signal_msg[32];

static volatile char *int2str(volatile char *s, int n)
{   unsigned int n1;
// Even though I really only expect this to be called with small positive
// arguments I will code it so it should support ANY integer value, including
// the most negative one.
    if (n >= 0) n1 = (unsigned int)n;
    {   *s++ = '-';
        n1 = -(unsigned int)n;
    }
    if (n1 >= 10)
    {   s = int2str(s, n1/10);
        n1 = n1 % 10;
    }
    *s++ = '0' + n1;
    return s;
}

void low_level_signal_handler(int code)
{
// Observe, if you will, that in the case of a SIGSEGV this function does
// not use a significant amount of stack end ends up just doing a
// longjmp. I avoid use of other library functions so I can feel
// at least partially safe.
// Well access to the buffer signal_msg and variable errorset_msg will count
// as thread-unsafe and so are probably invalid!
// The official rules are that all I can do really safely in a signal handler
// is set a flag, and possibly exit the entire program. A plausible rationale
// for that is that the exception might have arisen while I was deep in
// operating system code not in my own user-mode code, and internal data
// may not be in a consistent state. The rules specifically say that
// longjmp is NOT safe, in part because when you continue you are liable to
// resume calling system facilities. But I just want to get any chance I can
// to report trouble and so will try it knowing it may not always work - if
// it does well enough that I manage to display a useful diagnostic even
// just sometimes I have won.
//
// Also the full rules for longjmp out of a signal handler seem very very
// restrictive. But I only trap SIGSEGV, SIGBUS and SIGILL and really I view
// all of those as indicating system failure and if I can survive well enough
// to gather some diagnostics I should be happy. So this being thoroughly
// un-guaranteed is perhaps not a total disaster.
//
    if (miscflags & HEADLINE_FLAG)
    {   switch (code)
        {   default:
                {   volatile char *p = signal_msg;
                    const char *m1 = "Signal (code=";
                    while (*m1) *p++ = *m1++;
                    p = int2str(p, code);
                    *p++ = ')';
                    *p = 0;
                }
                errorset_msg = signal_msg;
                break;
#ifdef SIGFPE
            case SIGFPE:
                errorset_msg = "Arithmetic exception";
                break;
#endif
#ifdef SIGSEGV
            case SIGSEGV:
                errorset_msg = "Memory access violation";
                break;
#endif
#ifdef SIGBUS
            case SIGBUS:
                errorset_msg = "Bus error";
                break;
#endif
#ifdef SIGILL
            case SIGILL:
                errorset_msg = "Illegal instruction";
                break;
#endif
        }
    }
// I am NOT ALLOWED TO USE THROW to exit from a signal handler in C++. I
// can at best try use of longjmp, and that is not really legal
// This has the malign consequence that destructors
// associated with stack frames passed through will not be activated. And
// I use destructors in a RAII style to tidy up bindings at times, so I
// hope I never do a really long longjmp, because that would bypass things!
    longjmp(*global_jb, 1);
}

void unwind_stack(LispObject *entry_stack, bool findcatch)
{   LispObject *sp = stack;
    while (sp != entry_stack)
    {   LispObject bv, w;
        size_t n;
        w = *sp--;
        if (findcatch && w == SPID_CATCH) break;
        if (w == (LispObject)SPID_FBIND)
        {
//
// Here I have found some fluid binding that need to be unwound. The code
// here is similar to that for FREERSTR.
//
            bv = *sp--;
            n = length_of_header(vechdr(bv));
            while (n>CELL)
            {   LispObject v = *(LispObject *)(
                                   (intptr_t)bv + n - (CELL + TAG_VECTOR));
                n -= CELL;
                qvalue(v) = *sp--;
            }
        }
        else if (w == (LispObject)SPID_PVBIND)
        {   bv = *sp--;
            while (bv != nil)
            {   LispObject w = qcar(bv);
                qvalue(qcar(w)) = qcdr(w);
                bv = qcdr(bv);
            }
        }
    }
//
// If "findcatch" is true this code must actually update the stack pointer -
// otherwise it must not. Ugly! The only use with findcatch set true is
// from the bytecode interpreter (bytes1.c)
//
    if (findcatch) stack = sp;
}

bool force_backtrace = false;

// The "volatile" qualifications here are to try to improve the chances of
// setjmp/longjmp behaving the way I want.

static LispObject errorset3(volatile LispObject env,
                            volatile LispObject form,
                            volatile LispObject fg1,
                            volatile LispObject fg2)
{   LispObject r;
    STACK_SANITY;
    volatile uint32_t flags = miscflags;
//
// See also (ENABLE-BACKTRACE level) and (ENABLE-ERROSET min max)
//
// (ERRORSET form message traceback)
// evaluates the form. If evaluation succeeds it hands back a list of
// length 1 containing the value. If it fails it returns an atom.
// If message=nil and traceback=nil then no diagnostics should appear.
// if message is set then the a 1-line explanation of any error is
// displayed. If traceback is set then in addition to that a backtrace
// is produced. I believe there is no merit in generating a traceback
// without the initial message, so (errorset form nil t) will be treated
// as if it had been (errorset form t t).
//
// CSL has four "levels" of diagnostic:
//    0            none at all
//    1            displays an inital message but nothing more
//    2            initial message + trace of functions that are active
//    3            as above but also shows args to functions.
//
// The "message" and "traceback" args to errorset select a level for
// use within the evaluation that is being controlled...
//    message traceback    resulting level
//       nil    any            0
//       0-3    any            0-3
//       t      nil            1
//       t      t              3
//       t      0              1
//       t      1-3            1-3
// any value other then nil and 0-3 counts as t above.
//
// The level established this way is then limited to be in the range
// set by (enable-errorset min max) where the default min and max are
// (obviously) 0 and 3. The limits set by enable-errorset are global.
// A facility previously called "always_noisy" is now achieved as
// by (enable-errorset 3 3).
//
// Finally within the evaluation of the form that erroset processes it is
// possible to call (enable-backtrace level) where level is 0-3 (or nil
// for 0, t for 3) and that sets the diagnostic level independent of the
// errorset. A level set by enable-backtrace typically just lasts until
// you exit from the surrounding errorset, because that resets the level
// to its prior value.
//

    {   int n;
        if (fg1 == nil) n = 0;
        else if (fg1 == fixnum_of_int(0) ||
                 fg1 == fixnum_of_int(1) ||
                 fg1 == fixnum_of_int(2) ||
                 fg1 == fixnum_of_int(3)) n = int_of_fixnum(fg1);
        else // now depend on fg2
            if (fg2 == nil || fg1 == fixnum_of_int(0)) n = 1;
            else if (fg1 == fixnum_of_int(1) ||
                     fg1 == fixnum_of_int(2) ||
                     fg1 == fixnum_of_int(3)) n = int_of_fixnum(fg1);
            else n = 3;
        if (n < errorset_min) n = errorset_min;
        if (n > errorset_max) n = errorset_max;
        if (force_backtrace) n = 3;
        miscflags &= ~BACKTRACE_MSG_BITS;
        switch (n)
        {   case 0: break;
            case 1: miscflags |= HEADLINE_FLAG;
                break;
            case 2: miscflags |= (HEADLINE_FLAG | FNAME_FLAG);
                break;
            default: // case 3:
                miscflags |= BACKTRACE_MSG_BITS;
                break;
        }
    }

    stackcheck2(2, form, env);
    errorset_msg = NULL;
    try
    {   START_TRY_BLOCK;
        r = eval(form, nil);
    }
    catch (LispError e)
    {
// I am not going to catch exceptions such as the ones that restart the
// system - only ones that couunt as "errors".
        miscflags = (flags & BACKTRACE_MSG_BITS) |
                    (miscflags & ~BACKTRACE_MSG_BITS);
//
// Now if within this errorset somebody had gone (enable-errorset min max)
// I must reset flags on the way out...
//
        switch (errorset_min)
        {   case 0: break;
            case 1: miscflags |= HEADLINE_FLAG;
                break;
            case 2: miscflags |= (HEADLINE_FLAG | FNAME_FLAG);
                break;
            default: // case 3:
                miscflags |= BACKTRACE_MSG_BITS;
                break;
        }
        switch (errorset_max)
        {   case 0: miscflags &= ~BACKTRACE_MSG_BITS;
                break;
            case 1: miscflags &= ~(FNAME_FLAG | ARGS_FLAG);
                break;
            case 2: miscflags &= ~ARGS_FLAG;
            default:break;
        }
        if (consp(exit_value)) exit_value = nil;
        return onevalue(exit_value);
    }
// Now the normal exit case...
    miscflags = (flags & BACKTRACE_MSG_BITS) |
                (miscflags & ~BACKTRACE_MSG_BITS);
    switch (errorset_min)
    {   case 0: break;
        case 1: miscflags |= HEADLINE_FLAG;
            break;
        case 2: miscflags |= (HEADLINE_FLAG | FNAME_FLAG);
            break;
        default: // case 3:
            miscflags |= BACKTRACE_MSG_BITS;
            break;
    }
    switch (errorset_max)
    {   case 0: miscflags &= ~BACKTRACE_MSG_BITS;
            break;
        case 1: miscflags &= ~(FNAME_FLAG | ARGS_FLAG);
            break;
        case 2: miscflags &= ~ARGS_FLAG;
        default:break;
    }
    r = ncons(r);
    return onevalue(r);
}

LispObject Lerrorset_3(LispObject env, LispObject form, LispObject fg1, LispObject fg2)
//
// This is not a special form, but is put into the code here because,
// like unwind-protect, it has to re-gain control after an evaluation
// error.
//
{   STACK_SANITY;
    return errorset3(env, form, fg1, fg2);
}

LispObject Lerrorset_1(LispObject env, LispObject form)
{   return errorset3(env, form, nil, nil);
}


LispObject Lerrorset_2(LispObject env, LispObject form, LispObject ffg1)
{   return errorset3(env, form, ffg1, nil);
}

// (resource!-limit form time space io errors C_stack Lisp_stack)
//   Evaluate the given form and if it succeeds return a
//   list whose first item is its value. If it fails in the ordinary manner
//   then its failure (error/throw/restart etc) gets passed back through
//   here in a transparent manner. But if it runs out of resources this
//   function catches that fact and returns an atomic value.
//   Resource limits are not precise, and are specified by the
//   subsequent arguments here:
//      time:  an integer giving a time allowance in seconds
//      space: an integer giving a measure of memory that may be used,
//             expressed in units of "megaconses". This may only be
//             checked for at garbage collection and so small values
//             will often be substantially overshot. This is space
//             allocated - the fact that memory gets recycled does not
//             get it discounted.
//      io:    an integer limiting the number of kilobytes of IO that may
//             be performed.
//      errors:an integer limiting the number of times traditional
//             Lisp errors can occur. Note that if errorset is used
//             you could have very many errors raised.
//      C_stack:in integer limiting (in Kbytes) the max depth of C
//             stack that may be used. The cut-off may be imprecise.
//      Lisp_stack: an integer limiting (in Kbytes) the max depth of
//             the Lisp stack that may be used.
//   In each case specifying a negative limit means that that limit does
//   not apply. But at least one limit must be specified.
//   If calls to resource!-limit are nested the inner ones can only
//   reduce the resources available to their form.
//
//
// Note that code within CSL can call the C function resource_exceeded() to
// note that resources have expired.
//

int64_t time_base = 0,   space_base = 0,   io_base = 0,   errors_base = 0;
int64_t time_now = 0,    space_now = 0,    io_now = 0,    errors_now = 0;
int64_t time_limit = -1, space_limit = -1, io_limit = -1, errors_limit = 0;
int64_t Cstack_base = 0,   Lispstack_base = 0;
int64_t Cstack_now = 0,    Lispstack_now = 0;
int64_t Cstack_limit = -1, Lispstack_limit = -1;

class RAIIresource_variables
{   int64_t save_time_base,
            save_space_base,
            save_io_base,
            save_errors_base,
            save_time_limit,
            save_space_limit,
            save_io_limit,
            save_errors_limit;
    LispObject *save_stack;
 public:
    RAIIresource_variables()
    {   save_time_base    = time_base;
        save_space_base   = space_base;
        save_io_base      = io_base;
        save_errors_base  = errors_base;
        save_time_limit   = time_limit;
        save_space_limit  = space_limit;
        save_io_limit     = io_limit;
        save_errors_limit = errors_limit;
        save_stack        = stack;
     }
    ~RAIIresource_variables()
    {   time_base    = save_time_base;
        space_base   = save_space_base;
        io_base      = save_io_base;
        errors_base  = save_errors_base;
        time_limit   = save_time_limit;
        space_limit  = save_space_limit;
        io_limit     = save_io_limit;
        errors_limit = save_errors_limit;
        stack        = save_stack;
    }
};

static LispObject resource_limit7(LispObject env,
                                  LispObject form,
                                  LispObject ltime,
                                  LispObject lspace,
                                  LispObject lio,
                                  LispObject lerrors,
                                  LispObject Csk,
                                  LispObject Lsk)
{
//
// This is being extended to make it possible to limit the C and Lisp stack
// usage. At present the controls for that are not in place!
//
    STACK_SANITY;
    LispObject r;
    int64_t lltime, llspace, llio, llerrors;
    RAIIresource_variables RAIIresource_variables_object;
    int64_t r0=0, r1=0, r2=0, r3=0;
    errorset_msg = NULL;
//
// Here I need to do something that actually sets up the limits!
// I only allow limits that are up to 31-bits...
//
    lltime = thirty_two_bits(ltime); // .. or zero if not an integer
    llspace = thirty_two_bits(lspace);
    llio = thirty_two_bits(lio);
    llerrors = thirty_two_bits(lerrors);
//
// I can get thrown back here in four important ways:
// (1) The calculation succeeds.
// (2) It fails with a regular Lisp error.
// (3) It fails because it raises a C-level signal.
// (4) It fails by raising a resource-exhausted complaint.
//
    try
    {   START_SETJMP_BLOCK;
        time_base   = time_now;
        space_base  = space_now;
        io_base     = io_now;
        errors_base = errors_now;
        if (lltime >= 0)
        {   int w;
//
// I make 2 seconds the smallest I can specify as a timeout because with
// my clock resolution at 1 sec if I specified "1" I could do so just a
// smidgin before the clock time and end up with no slack at all.
//
            if (lltime == 0 || lltime == 1) lltime = 2;
            w = time_base + lltime;
            if (time_limit >= 0 && time_limit < w) w = time_limit;
            time_limit = w;
        }
        if (llspace >= 0)
        {   int w;
//
// I make 2 megaconses the smallest request here for much the same
// reason I put a lower limit on time. Actually if go further and make
// 4 megaconses my limit...
//
            if (llspace >= 0 && llspace < 4) llspace = 4;
//
// Ok, the USER specified things in megaconses, but internally I will
// count in "CSL pages". The standard CSL page size is 4Mbytes, ie 0.5 or
// 0.25 megaconses so I multiply by 2 or 4 here (for 32 or 64-bit systems).
//
            llspace *= (2*sizeof(LispObject)*1024*1024)/PAGE_POWER_OF_TWO;
            w = space_base + llspace;
            if (space_limit >= 0 && space_limit < w) w = space_limit;
            space_limit = w;
        }
        if (llio >= 0)
        {   int w;
            if (llio == 0 || llio == 1) llio = 2;
            w = io_base + llio;
            if (io_limit >= 0 && io_limit < w) w = io_limit;
            io_limit = w;
        }
        if (llerrors >= 0)
        {   int w;
            w = errors_base + llerrors;
            if (errors_limit >= 0 && errors_limit < w) w = errors_limit;
            errors_limit = w;
        }
        r = eval(form, nil);
        r0 = time_now - time_base;
        r1 = (space_now - space_base)/
             ((2*sizeof(LispObject)*1024*1024)/PAGE_POWER_OF_TWO);
        r2 = io_now - io_base;
        r3 = errors_now - errors_base;
    }
    catch (LispResource e)
    {   form = list4(fixnum_of_int(r0),
                     fixnum_of_int(r1),
                     fixnum_of_int(r2),
                     fixnum_of_int(r3));
        qvalue(resources) = form;
// Here I had a resource limit trap
        return onevalue(nil);
    }
//
// I would like the result to show what resources had been used, but for now
// I just use ncons to wrap the resuult up.
//
    r = ncons(r);
    push(r);
    form = list4(fixnum_of_int(r0),
                 fixnum_of_int(r1),
                 fixnum_of_int(r2),
                 fixnum_of_int(r3));
    pop(r);
    qvalue(resources) = form;
    return onevalue(r);
}

LispObject Lresource_limit_4up(LispObject env, LispObject form, LispObject ltime,
    LispObject lspace, LispObject a4up)
{   LispObject lio, lerrors, Csk, Lsk;
    STACK_SANITY;
    if (!is_fixnum(ltime)) ltime = fixnum_of_int(-1);
    if (!is_fixnum(lspace)) lspace = fixnum_of_int(-1);
    lio = lerrors = Csk = Lsk = fixnum_of_int(-1);
    if (a4up != nil)
    {   lio = qcar(a4up);
        a4up = qcdr(a4up);
        if (a4up != nil)
        {   lerrors = qcar(a4up);
            a4up = qcdr(a4up);
            if (a4up != nil)
            {   Csk = qcar(a4up);
                a4up = qcdr(a4up);
                if (a4up != nil)
                {   Lsk = qcar(a4up);
                }
            }
        }
    }
    return resource_limit7(env, form, ltime, lspace, lio, lerrors, Csk, Lsk);
}


LispObject Lresource_limit_2(LispObject env, LispObject form, LispObject ltime)
{   return resource_limit7(env, form, ltime,
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1));
}

LispObject Lresource_limit_3(LispObject env, LispObject form, LispObject ltime, LispObject lspace)
{   return resource_limit7(env, form, ltime, lspace,
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1));
}


static LispObject when_fn(LispObject args, LispObject env)
{   LispObject w;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    w = qcar(args);
    w = eval(w, env);
    pop2(env, args);
    if (w == nil) return onevalue(nil);
    else return progn_fn(qcdr(args), env);
}

void bad_specialfn_0(LispObject env)
{   aerror1("bad special function", env);
}

void bad_specialfn_2(LispObject env, LispObject a, LispObject b)
{   aerror1("bad special function", env);
}

void bad_specialfn_3(LispObject env, LispObject a, LispObject b, LispObject c)
{   aerror1("bad special function", env);
}

void bad_specialfn_4up(LispObject env, LispObject a, LispObject b,
                LispObject c, LispObject d)
{   aerror1("bad special function", env);
}

setup_type const eval3_setup[] =
{   {"or",                      BAD_SPECIAL_0, or_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"prog",                    BAD_SPECIAL_0, prog_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"prog1",                   BAD_SPECIAL_0, prog1_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"prog2",                   BAD_SPECIAL_0, prog2_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"progn",                   BAD_SPECIAL_0, progn_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"quote",                   BAD_SPECIAL_0, quote_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"return",                  BAD_SPECIAL_0, return_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"setq",                    BAD_SPECIAL_0, setq_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"tagbody",                 BAD_SPECIAL_0, tagbody_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"unless",                  BAD_SPECIAL_0, unless_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"unwind-protect",          BAD_SPECIAL_0, unwind_protect_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"when",                    BAD_SPECIAL_0, when_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"macrolet",                BAD_SPECIAL_0, macrolet_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"multiple-value-call",     BAD_SPECIAL_0, mv_call_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"multiple-value-prog1",    BAD_SPECIAL_0, mv_prog1_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"progv",                   BAD_SPECIAL_0, progv_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"return-from",             BAD_SPECIAL_0, return_from_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"the",                     BAD_SPECIAL_0, the_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {"throw",                   BAD_SPECIAL_0, throw_fn, BAD_SPECIAL_2, BAD_SPECIAL_3, BAD_SPECIAL_4up},
    {NULL,                      0, 0, 0, 0, 0}
};

// end of eval3.cpp
