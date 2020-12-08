// eval3.cpp                               Copyright (C) 1991-2020 Codemist

//
// Interpreter (part 3).
// Implementations of special forms (interpreted versions).
//
//

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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

// $Id: eval3.cpp 5428 2020-10-12 17:06:37Z arthurcnorman $


#include "headers.h"


#define BODY_LET            0
#define BODY_COMPILER_LET   1
#define BODY_PROG           2

static LispObject macrolet_fn(LispObject args, LispObject env)
{   LispObject d;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck(args, env);
    d = car(args);     // The bunch of definitions
    while (consp(d))
    {   LispObject w = car(d);     // w = (name bvl ...)
        if (consp(w) && consp(cdr(w)))
        {
//
// Here I need to call (expand-definer <form> nil) to map
// macro specifications with all the possible magic options into ones
// which just take 2 args, a form and an environment.
//
            push(args, env);
            w = cons(expand_def_symbol, w);
            w = Lfuncall_3(nil, expand_def_symbol, w, nil);
//
// I expect expand-definer to return either
//     (~~defmacro name bvl ...)
// OR  (progn XXX (~~defmacro name bvl ...))
//     where XXX is exactly one form.
//
            if (car(w) == progn_symbol)
                w = car(cdr(cdr(w)));
            w = cdr(w);
            w = cons(cdr(w), car(w));
            pop(env, args);
            env = cons(w, env);
        }
        d = cdr(d);
    }
    return let_fn_1(nil, cdr(args), env, BODY_LET);
}

static LispObject mv_prog1_fn(LispObject args, LispObject env)
{   LispObject r, rl;
    STACK_SANITY;
    int nargs, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck(args, env);
    push(args, env);
    r = car(args);
    r = eval(r, env);
    pop(env, args);
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
    while (is_cons(args = cdr(args)) && args!=nil)
    {   LispObject w;
        push(args, env);
        w = car(args);
        eval(w, env);
        pop(env, args);
    }
    pop(rl);
    for (i = 2; i<=nargs; i++)
    {   (&mv_2)[i-2] = car(rl);
        rl = cdr(rl);
    }
    pop(r);
    return nvalues(r, nargs);
}

static LispObject or_fn(LispObject args, LispObject env)
// also needs to be a macro for Common Lisp
{   if (!consp(args)) return onevalue(nil);
    stackcheck(args, env);
    STACK_SANITY;
    for (;;)
    {   LispObject v = car(args);
        args = cdr(args);
        if (!consp(args)) return eval(v, env);
        push(args, env);
        v = eval(v, env);
        pop(env, args);
        if (v != nil) return onevalue(v);
    }
}

// Note that (BLOCK ...) also catches LispReturnFrom exceptions, and that
// Common Lisp really thinks of PROG as a combination of LET, BLOCK and
// TAGBODY.

static LispObject prog_fn(LispObject iargs, LispObject ienv)
{   if (!consp(iargs) || !consp(cdr(iargs))) return onevalue(nil);
    stackcheck(iargs, ienv);
    LispObject t = nil;
    RealPush save(t, iargs, ienv);
    LispObject &env    = stack[0];
    LispObject &args   = stack[-1];
    LispObject &my_tag = stack[-2];
// I need to augment the (lexical) environment with a null block
// tag so that (return ..) will work as required. See block_fn for
// further elaboration since (block ..) is the main way of introducing
// new block tags.
    my_tag = cons(fixnum_of_int(0), nil);
    env = cons(my_tag, env);
    {   START_TRY_BLOCK;
        let_fn_1(car(args), cdr(args), env, BODY_PROG);
    }
    switch (exceptionFlag)
    {   case LispReturnFrom:
            setcar(my_tag, fixnum_of_int(2));    // Invalidate
            if (exit_tag == my_tag)
            {   exceptionFlag = LispNormal;
                return exit_value;  // exit_count already OK here
            }
// It could be that the RETURN(-FROM) is heading to be handled by some
// enclosing block.
            else return nil;
        case LispError:
        case LispSignal:
        case LispResource:
            {   int _reason = exit_reason;
                int save = exceptionFlag;
                exceptionFlag = LispNormal;
                if (SHOW_FNAME)
                {   err_printf("\nEvaluating: "); // A bit of backtrace on errors
                    loop_print_error(args);
                }
                exceptionFlag = save;
                exit_reason = _reason;
                return nil;
            }
    }
// I get here if using let_fn_1 to process the body of the
// PROG just returned without doing a (RETURN ...), or if I am being exited
// via a (thrown) return-from, go or restart request.
    return onevalue(nil);
}

LispObject progn_fn(LispObject args, LispObject env)
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck(args, env);
    f = nil;
    for (;;)
    {   f = car(args);
        args = cdr(args);
        if (!consp(args)) break;
        push(args, env, f);
        on_backtrace(
            static_cast<void>(eval(f, env)),
            // Action for backtrace here...
            pop(f, env, args);
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            },
            return nil);
        pop(f, env, args);
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
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    {   Push save(args, env);
        f = car(args);
        f = eval(f, env);              // first arg
    }
    if (exceptionPending()) return nil;
    {   Push save(f);
        for (;;)
        {   args = cdr(args);
            if (!consp(args)) break;
            Push save1(args, env);
            {   LispObject w = car(args);
                static_cast<void>(eval(w, env));
            }
            if (exceptionPending()) return nil;
        }
    }
    return onevalue(f);     // always hands back just 1 value
}

static LispObject prog2_fn(LispObject args, LispObject env)
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil); // (prog2) -> nil
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    {   Push save(args, env);
        args = car(args);
        static_cast<void>(eval(args, env));  // eval & discard first arg
    }
    if (exceptionPending()) return nil;
    args = cdr(args);
    if (!consp(args)) return onevalue(nil); // (prog2 x) -> nil
    {   Push save(args, env);
        f = car(args);
        f = eval(f, env);                       // second arg
    }
    {   Push save(f);
        for (;;)
        {   args = cdr(args);
            if (!consp(args)) break;
            {   Push save1(args, env);
                args = car(args);
                static_cast<void>(eval(args, env));
            }
        }
    }
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
        {   LispObject p = car(specenv);
            setvalue(car(p), cdr(p));
            specenv = cdr(specenv);
        }
        real_popv(4);
    }
};

static LispObject progv_fn(LispObject args_x, LispObject env_x)
{   LispObject syms_x, vals_x, specenv_x, w;
    STACK_SANITY;
    if (!consp(args_x)) return onevalue(nil);
    stackcheck(args_x, env_x);
    if (exceptionPending()) return nil;
    syms_x = vals_x = specenv_x = nil;
    syms_x = car(args_x);
    args_x = cdr(args_x);
    real_push(args_x, env_x, syms_x, vals_x, specenv_x);

    syms = eval(syms, env);
    if (exceptionPending()) { real_popv(5); return nil; }
    if (!consp(args))
    {   real_popv(5);
        return nil;
    }
    w = car(args);
    args = cdr(args);
    vals = eval(w, env);
    if (exceptionPending()) { real_popv(5); return nil; }
    if (!consp(args))
    {   real_popv(5);
        return nil;
    }
    while (consp(syms))
    {   LispObject v = car(syms);
        LispObject w1;
        if (consp(vals))
        {   w = car(vals);
            vals = cdr(vals);
        }
        else w = unset_var;
        syms = cdr(syms);
        if (!is_symbol(v) || v==nil || v==lisp_true) continue;
        w1 = cons(v, qvalue(v));
        if (exceptionPending()) { real_popv(5); return nil; }
// If I were to take the error exit here then some variables would have
// been set to their new values and some not. That would be a mess! So if the
// above CONS fails and triggers an exit things are bad. I may need to
// pre-allocate the space, but because PROGV is esoteric (and not used by
// Reduce) I am not going to go to the trouble YET.
        setvalue(v, w);
        specenv = cons(w1, specenv);
    }
    {   RAIIunbind_progv_specials unbind_progv_variables;
        args = progn_fn(args, env);
    }
    real_pop(w);
#undef specenv
#undef vals
#undef syms
#undef env
#undef args
    return w;
}

LispObject quote_fn(LispObject args, LispObject)
{   if (consp(args) && cdr(args) == nil) return onevalue(car(args));
    return aerror("quote");
}

static LispObject return_fn(LispObject args, LispObject env)
{
// First check that the block name (nil in this case) is lexically available
    STACK_SANITY;
    LispObject p;
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    for(p=env; consp(p); p=cdr(p))
    {   LispObject w = car(p);
        if (!consp(w)) continue;
        if (car(w) == fixnum_of_int(0) && cdr(w) == nil)
        {   p = w;
            goto tag_found;
        }
    }
    return error(1, err_block_tag, nil);
tag_found:
    if (consp(args))
    {   push(p);
        LispObject p1 = car(args);
        env = eval(p1, env);
        pop(p);
        if (exceptionPending()) return nil;
        exit_value = env;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    exceptionFlag = LispReturnFrom;
    return nil;
}

static LispObject return_from_fn(LispObject args, LispObject env)
{   LispObject p, tag;
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    STACK_SANITY;
    if (!consp(args)) tag = nil;
    else
    {   tag = car(args);
        args = cdr(args);
    }
    for(p=env; consp(p); p=cdr(p))
    {   LispObject w = car(p);
        if (!consp(w)) continue;
        if (car(w) == fixnum_of_int(0) && cdr(w) == tag)
        {   p = w;
            goto tag_found;
        }
    }
    return error(1, err_block_tag, tag);
tag_found:
    if (consp(args))
    {   push(p);
        LispObject p1 = car(args);
        env = eval(p1, env);
        pop(p);
        if (exceptionPending()) return nil;
        exit_value = env;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    exceptionFlag = LispReturnFrom;
    return nil;
}

static LispObject setq_fn(LispObject args, LispObject env)
{   LispObject var, val = nil;
    STACK_SANITY;
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    while (consp(args))
    {   var = car(args);
        if (!is_symbol(var) || var == nil || var == lisp_true ||
            (qheader(var) & SYM_KEYWORD_VAR) == SYM_KEYWORD_VAR)
        {   return aerror1("setq (bad variable)", var);
        }
        args = cdr(args);
        if (consp(args))
        {   {   Push save(args, env, var);
                val = car(args);
                val = eval(val, env);
            }
            if (exceptionPending()) return nil;
            args = cdr(args);
        }
        else val = nil;
        if ((qheader(current_function) & SYM_TRACESET) != 0)
        {   real_push(args, env, var, val);
            freshline_trace();
// I want loop_print_trace to avoid exiting with errors!
            loop_print_trace(current_function);
            trace_printf(":  ");
            loop_print_trace(stack[-1]);
            trace_printf(" := ");
            loop_print_trace(stack[0]);
            trace_printf("\n");
            real_pop(val, var, env, args);
        }
        if ((qheader(var) & SYM_KEYWORD_VAR) == SYM_SPECIAL_VAR ||
            (qheader(var) & SYM_KEYWORD_VAR) == SYM_GLOBAL_VAR)
            setvalue(var, val);
        else
        {   LispObject p = env, w;   // Here it seems to be a local variable,
            // or it could be locally FLUID.
            for (;;)
            {   if (!consp(p))
                {   setheader(var, qheader(var) | SYM_SPECIAL_VAR);
#ifdef SOME_TIME_LATER
// If I display this message - which could be viewed as a proper error report -
// it leds to multiple failures in the Reduce regressions where scripting
// assumes that assignment to a variable is valid without any declaration.
                    push(args, env, var);
                    debug_printf("\n+++++ "); loop_print_debug(var);
                    debug_printf(" proclaimed SPECIAL by SETQ\n");
                    pop(var, env, args);
#endif
                    setvalue(var, val);
                    break;
                }
                w = car(p);
                if (car(w) == var)
                {   if (cdr(w) == work_symbol) setvalue(var, val);
                    else write_barrier(cdraddr(w), val);
                    break;
                }
                p = cdr(p);
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
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    STACK_SANITY;
    real_push(env, args);
    for (p=args; consp(p); p=cdr(p))
    {   LispObject w = car(p);
        if (!consp(w))
        {   LispObject w1;
            push(p, env);
            w1 = cons(fixnum_of_int(1), p);
            pop(env);
            if (exceptionFlag == LispNormal)
                env = cons(w1, env);
            pop(p);
            if (exceptionPending()) return nil;
        }
    }
// That has put my new version of env with bindings of the form
//    (1 . <location in the tagbody>)
// for each label present. In other words it goes
//    env = ( ... (1 labelname <continuation>) ... )
// where bindings for variable in the environment would have a symbol
// so the integer 1 here distinguishes these as label bindings.
    real_pop(args);
//
// (go xx) sets exit_tag to xx, which is then noticed next time tagbody
// is about to do anything.
//
    for (p=args; consp(p); p = cdr(p))
    {   f = car(p);
        if (!is_cons(f)) continue; // Do not evaluate labels
        push(p, env, f);
        {   START_TRY_BLOCK;
            static_cast<void>(eval(f, env));
        }
        switch (exceptionFlag)
        {   case LispGo:
                {   int _reason = exit_reason;
                    exceptionFlag = LispNormal;
                    pop(f, env, p);
                    my_env = stack[0];
// I need to do this search. Well in the code that implemented GO I checked
// that the destination label was bound as a label. That was so that I could
// give a decent diagnostic if it was not. The scan here is to see if it is
// a label in THIS level of a tagbody... and if not I will hand it upwards.
                    for (p=env; p!=my_env; p=cdr(p)) // scan label bindings
                    {   LispObject w = car(p);
                        if (w != exit_tag) continue;
// Now I have found the label I needed to jump to. Hoorah.
                        p = cdr(w);
                        break;
                    }
                    if (p != my_env) continue; // take the GOTO
// If I drop out of the loop that means that the target label was
// not present in this block. Tidy up the label bindings to be very
// certain nobody can re-use them.
                    while (env != my_env)
                    {   setcar(car(env), fixnum_of_int(2));
                        env = cdr(env);
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
                    exceptionFlag = LispGo;
                    return nil;
                }
            case LispError:
            case LispSignal:
            case LispResource:
                {   int _reason = exit_reason;
                    int save = exceptionFlag;
                    exceptionFlag = LispNormal;
                    pop(f, env, p);
                    if (SHOW_FNAME)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(f);
                    }
// Re-throw some other exception that counted as an error.
                    exit_reason = _reason;
                    exceptionFlag = save;
                    return nil;
                }
        }
        pop(f, env, p);
    }
// This is where I drop off the end of the tagbody, so I tidy up and
// return nil.
    real_pop(my_env);
    while (env != my_env)
    {   setcar(car(env), fixnum_of_int(2));
        env = cdr(env);
    }
    return onevalue(nil);
}

static LispObject the_fn(LispObject args, LispObject env)
//
// in effect an identity function for the present
//
{   if (!consp(args)) return onevalue(nil);
    args = cdr(args);
    if (!consp(args)) return onevalue(nil);
    args = car(args);
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
    if (!consp(args)) return aerror("throw");
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    tag = car(args);
    args = cdr(args);
    push(args, env);
    tag = eval(tag, env);
    pop(env, args);
    if (exceptionPending()) return nil;
    for (p = catch_tags; p!=nil; p=cdr(p))
        if (tag == car(p)) goto tag_found;
    return aerror("throw: tag not found");
tag_found:
    if (consp(args))
    {   push(p);
        tag = car(args);
        tag = eval(tag, env);
        pop(p);
        if (exceptionPending()) return nil;
        exit_value = tag;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    exceptionFlag = LispThrow;
    return nil;
}

LispObject Lthrow_one_value(LispObject env, LispObject tag, LispObject val)
{   LispObject p;
    STACK_SANITY;
    for (p = catch_tags; p!=nil; p=cdr(p))
        if (tag == car(p)) goto tag_found;
    return aerror("throw: tag not found");
tag_found:
    exit_value = val;
    exit_count = 1;
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    exceptionFlag = LispThrow;
    return nil;
}

LispObject Lthrow_nil(LispObject env, LispObject tag)
{   return Lthrow_one_value(nil, tag, nil);
}

static LispObject unless_fn(LispObject args, LispObject env)
{   LispObject w;
    STACK_SANITY;
    if (!consp(args)) return onevalue(nil);
    stackcheck(args, env);
    if (exceptionPending()) return nil;
    push(args, env);
    w = car(args);
    w = eval(w, env);
    pop(env, args);
    if (exceptionPending()) return nil;
    if (w != nil) return onevalue(nil);
    else return progn_fn(cdr(args), env);
}

static LispObject unwind_protect_fn(LispObject args, LispObject env)
{   LispObject r = nil, rl = nil;
    STACK_SANITY;
    int nargs = 0, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck(args, env);
    push(args, env);
    r = car(args);
    {   START_TRY_BLOCK;
        r = eval(r, env);
    }
    if (exceptionPending())
    {   int save = exceptionFlag;
        exceptionFlag = LispNormal;
        pop(env, args);
        LispObject xt, xv;
        int xc, xr;
// Here I am in the process of exiting because of a throw, return-from,
// go or error.  I need to save all the internal stuff that tells me
// what is going on so I can restore it after the clean-up forms have been
// processed.  The values involved are:
//  (a) exit_tag       marks use of go, return-from or throw
//  (b) exit_value     first result value (throw, return-from)
//  (c) exit_count     number of values (throw, return-from)
//  (d) mv2,...        as indicated by exit_count
//  (e) exit_reason    what it says.
        xt = qvalue(trap_time);
        setvalue(trap_time, nil); // No timeouts in recovery code
        push(xt);
        xv = exit_value;
        xt = exit_tag;
        xc = exit_count;
        xr = exit_reason;
        push(xv, xt);
        for (i=xc; i>=2; i--)
            rl = cons_no_gc((&mv_2)[i-2], rl);
        rl = cons_gc_test(rl);
// I am going to take the view that if there is a failure during execution
// of the cleanup forms then full cleanup will not be complete, and this
// can include the case of "cons" failing right before anything else.
        if (exceptionPending()) return nil;
        push(rl);
// Now I will obey the cleanup 
        while (is_cons(args = cdr(args)) && args!=nil)
        {   LispObject w = car(args);
            push(args, env);
            static_cast<void>(eval(w, env));
            pop(env, args);
            if (exceptionPending()) return nil;
        }
        pop(rl, xt, xv);
        for (i = 2; i<=xc; i++)
        {   (&mv_2)[i-2] = car(rl);
            rl = cdr(rl);
        }
        exit_value = xv;
        exit_tag   = xt;
        exit_count = xc;
        exit_reason = xr;
        pop(xt);
        setvalue(trap_time, xt);
        exceptionFlag = save;
        return nil;                   // reinstate the exception
    }
    pop(env, args);
//
// Now code (just like multiple-value-prog1) that evaluates the
// cleanup forms in the case that the protected form exits normally.
//
    nargs = exit_count;
    real_push(args, env);
    for (i=nargs; i>=2; i--)
        rl = cons_no_gc((&mv_2)[i-2], rl);
    rl = cons_gc_test(rl);
    if (exceptionPending()) return nil;
    real_push(rl);
    LispObject &xenv = stack[-1];
    LispObject &xargs = stack[-2];
    while (is_cons(xargs = cdr(xargs)) && xargs!=nil)
    {   LispObject w = car(xargs);
        static_cast<void>(eval(w, xenv));
        if (exceptionPending()) return nil;
    }
    real_pop(rl);
    real_popv(2);
    for (i = 2; i<=nargs; i++)
    {   (&mv_2)[i-2] = car(rl);
        rl = cdr(rl);
    }
    return nvalues(r, nargs);
}

//
// Errorset is not defined as part of COMMON Lisp but I want it in
// any Lisp system that I use notwithstanding that.
//

const volatile char *errorset_msg;

void unwind_stack(LispObject *entry_stack, bool findcatch)
{   LispObject *sp = stack;
    while (sp != entry_stack)
    {   LispObject bv, w;
        size_t n;
        w = *sp--;
        if (findcatch && w == SPID_CATCH) break;
        if (w == static_cast<LispObject>(SPID_FBIND))
        {
//
// Here I have found some fluid binding that need to be unwound. The code
// here is similar to that for FREERSTR.
//
            bv = *sp--;
            n = length_of_header(vechdr(bv));
            while (n>CELL)
            {   LispObject v = *reinterpret_cast<LispObject *>(
                                   (intptr_t)bv + n - (CELL + TAG_VECTOR));
                n -= CELL;
                setvalue(v, *sp--);
            }
        }
        else if (w == static_cast<LispObject>(SPID_PVBIND))
        {   bv = *sp--;
            while (bv != nil)
            {   LispObject w = car(bv);
                setvalue(car(w), cdr(w));
                bv = cdr(bv);
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
// setjmp/longjmp behaving the way I want. Even with those qualifiers in
// place any use of it is utterlt uncertain!

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
    push(form, env);
    stackcheck();
    pop(env);
    pop(form);
    if (exceptionPending()) return nil;
    errorset_msg = nullptr;
    {   START_TRY_BLOCK;
        r = eval(form, nil);
    }
    if (errorState())
    {   exceptionFlag = LispNormal;
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
        if (stop_on_error) throw;
        if (consp(exit_value)) exit_value = nil;
        return onevalue(exit_value);
    }
    else if (exceptionPending()) return nil;
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

LispObject Lerrorset_3(LispObject env, LispObject form,
                       LispObject fg1, LispObject fg2)
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


LispObject Lerrorset_2(LispObject env, LispObject form,
                       LispObject ffg1)
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

int64_t time_base = 0,   space_base = 0,   io_base = 0,
        errors_base = 0;
int64_t time_now = 0,    space_now = 0,    io_now = 0,
        errors_now = 0;
int64_t time_limit = -1, space_limit = -1, io_limit = -1,
        errors_limit = 0;
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
// This is being extended to make it possible to limit the C and Lisp stack
// usage. At present the controls for that are not in place!
    STACK_SANITY;
    LispObject r;
    int64_t lltime, llspace, llio, llerrors;
    RAIIresource_variables RAIIresource_variables_object;
    int64_t r0=0, r1=0, r2=0, r3=0;
    errorset_msg = nullptr;
// Here I need to do something that actually sets up the limits!
// I only allow limits that are up to 31-bits...
    lltime = thirty_two_bits(ltime); // .. or zero if not an integer
    llspace = thirty_two_bits(lspace);
    llio = thirty_two_bits(lio);
    llerrors = thirty_two_bits(lerrors);
// I can get thrown back here in four important ways:
// (1) The calculation succeeds.
// (2) It fails with a regular Lisp error.
// (3) It fails because it raises a C-level signal.
// (4) It fails by raising a resource-exhausted complaint.
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
// All the above mess was just establishing the limits to be applied!
// So now I can do the work that has to be constrained.
        r = eval(form, nil);
        r0 = time_now - time_base;
        r1 = (space_now - space_base)/
             ((2*sizeof(LispObject)*1024*1024)/PAGE_POWER_OF_TWO);
        r2 = io_now - io_base;
        r3 = errors_now - errors_base;
    }
endOfTryBlock:
    if (exceptionFlag == LispResource)
    {   exceptionFlag = LispNormal;
        form = list4(fixnum_of_int(r0),
                     fixnum_of_int(r1),
                     fixnum_of_int(r2),
                     fixnum_of_int(r3));
        if (exceptionPending()) return nil;
        setvalue(resources, form);
// Here I had a resource limit trap
        return onevalue(nil);
    }
// The guarded code may have exited with some other exception!
    if (exceptionPending()) return nil; 
// I would like the result to show what resources had been used, but for now
// I just use ncons to wrap the resuult up.
    r = ncons(r);
    if (exceptionPending()) return nil; 
    push(r);
    form = list4(fixnum_of_int(r0),
                 fixnum_of_int(r1),
                 fixnum_of_int(r2),
                 fixnum_of_int(r3));
    pop(r);
    if (exceptionPending()) return nil; 
    setvalue(resources, form);
    return onevalue(r);
}

LispObject Lresource_limit_4up(LispObject env, LispObject form,
                               LispObject ltime,
                               LispObject lspace, LispObject a4up)
{   LispObject lio, lerrors, Csk, Lsk;
    STACK_SANITY;
    if (!is_fixnum(ltime)) ltime = fixnum_of_int(-1);
    if (!is_fixnum(lspace)) lspace = fixnum_of_int(-1);
    lio = lerrors = Csk = Lsk = fixnum_of_int(-1);
    if (a4up != nil)
    {   lio = car(a4up);
        a4up = cdr(a4up);
        if (a4up != nil)
        {   lerrors = car(a4up);
            a4up = cdr(a4up);
            if (a4up != nil)
            {   Csk = car(a4up);
                a4up = cdr(a4up);
                if (a4up != nil)
                {   Lsk = car(a4up);
                }
            }
        }
    }
    return resource_limit7(env, form, ltime, lspace, lio, lerrors, Csk,
                           Lsk);
}


LispObject Lresource_limit_2(LispObject env, LispObject form,
                             LispObject ltime)
{   return resource_limit7(env, form, ltime,
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1));
}

LispObject Lresource_limit_3(LispObject env, LispObject form,
                             LispObject ltime, LispObject lspace)
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
    stackcheck(args, env);
    push(args, env);
    w = car(args);
    w = eval(w, env);
    pop(env, args);
    if (w == nil || exceptionPending()) return onevalue(nil);
    else return progn_fn(cdr(args), env);
}

LispObject bad_specialfn_0(LispObject env)
{   return aerror1("bad special function", env);
}

LispObject bad_specialfn_2(LispObject env, LispObject a, LispObject b)
{   return aerror1("bad special function", env);
}

LispObject bad_specialfn_3(LispObject env, LispObject a, LispObject b,
                     LispObject c)
{   return aerror1("bad special function", env);
}

LispObject bad_specialfn_4up(LispObject env, LispObject a, LispObject b,
                       LispObject c, LispObject d)
{   return aerror1("bad special function", env);
}

setup_type const eval3_setup[] =
{   {"or",                      bad_specialfn_0, or_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"prog",                    bad_specialfn_0, prog_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"prog1",                   bad_specialfn_0, prog1_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"prog2",                   bad_specialfn_0, prog2_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"progn",                   bad_specialfn_0, progn_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"quote",                   bad_specialfn_0, quote_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"return",                  bad_specialfn_0, return_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"setq",                    bad_specialfn_0, setq_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"tagbody",                 bad_specialfn_0, tagbody_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"unless",                  bad_specialfn_0, unless_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"unwind-protect",          bad_specialfn_0, unwind_protect_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"when",                    bad_specialfn_0, when_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"macrolet",                bad_specialfn_0, macrolet_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"multiple-value-call",     bad_specialfn_0, mv_call_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"multiple-value-prog1",    bad_specialfn_0, mv_prog1_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"progv",                   bad_specialfn_0, progv_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"return-from",             bad_specialfn_0, return_from_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"the",                     bad_specialfn_0, the_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {"throw",                   bad_specialfn_0, throw_fn, bad_specialfn_2, bad_specialfn_3, bad_specialfn_4up},
    {nullptr,                   nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of eval3.cpp
