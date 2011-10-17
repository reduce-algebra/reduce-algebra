/*  eval3.c                          Copyright (C) 1991-96 Codemist Ltd */

/*
 * Interpreter (part 3).
 * Implementations of special forms (interpreted versions).
 *
 */

/* Signature: 0c8cf0ed 07-Mar-2000 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#ifdef __WATCOMC__
#include <float.h>
#endif

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "arith.h"
#include "entries.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif

#ifndef COMMON

static Lisp_Object plus_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object r;
    if (!consp(args)) return fixnum_of_int(0); /* (plus) => 0 */
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    errexit();
    args = qcdr(args);
    while (consp(args))
    {   Lisp_Object w;
        push3(env, args, r);
        w = qcar(args);
        w = eval(w, env);
        pop(r);
        errexitn(2);
        if (is_fixnum(r) && is_fixnum(w))
        {   int32 c = int_of_fixnum(r) + int_of_fixnum(w);
            int32 w1 = c & fix_mask;
            if (w1 == 0 || w1 == fix_mask) r = fixnum_of_int(c);
            else r = plus2(r, w);
        }
        else r = plus2(r, w);
        errexitn(2);
        pop2(args, env);
        args = qcdr(args);
    }
    return onevalue(r);   
}

static Lisp_Object times_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object r;
    if (!consp(args)) return fixnum_of_int(1); /* (times) => 1 */
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    errexit();
    args = qcdr(args);
    while (consp(args))
    {   Lisp_Object w;
        push3(env, args, r);
        w = qcar(args);
        w = eval(w, env);
        pop(r);
        errexitn(2);
        r = times2(r, w);
        pop2(args, env);
        errexit();
        args = qcdr(args);
    }
    return onevalue(r);   
}

static Lisp_Object list_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object w1, w2, w3, r = nil;
/*
 * I am going to write out the cases of list with 0, 1, 2 or 3
 * args specially here, since I expect them to be the more common ones
 * and I am generally jumpy about performance.  It seems a bit nasty
 * to get to an interpreted call to list anyway.
 */
    if (!consp(args)) return onevalue(nil); /* (list) */
    w1 = qcar(args); args = qcdr(args);
    if (!consp(args))                       /* (list w1) */
    {   w1 = eval(w1, env);
        errexit();
        w1 = ncons(w1);
        errexit();
        return onevalue(w1);
    }
    w2 = qcar(args); args = qcdr(args);
    if (!consp(args))                       /* (list w1 w2) */
    {   push2(env, w2);
        w1 = eval(w1, env);
        errexitn(2);
        w2 = stack[0];
        stack[0] = w1;
        w2 = eval(w2, stack[-1]);
        errexitn(2);
        w1 = list2(stack[0], w2);
        popv(2);
        errexit();
        return onevalue(w1);
    }
    w3 = qcar(args); args = qcdr(args);
    if (!is_cons(args))                     /* (list w1 w2 w3) */
    {   push3(env, w2, w3);
        w1 = eval(w1, env);
        errexitn(3);
        w2 = stack[-1];
        stack[-1] = w1;
        w2 = eval(w2, stack[-2]);
        errexitn(3);
        w3 = stack[0];
        stack[0] = w2;
        w3 = eval(w3, stack[-2]);
        errexitn(3);
        w3 = ncons(w3);
        errexitn(3);
        w1 = list2star(stack[-1], stack[0], w3);
        popv(3);
        errexit();
        return onevalue(w1);
    }
    push4(args, env, w1, w2);
    w3 = eval(w3, env);
    errexitn(4);
    push(w3);
    w2 = eval(stack[-1], stack[-3]);
    errexitn(5);
    stack[-1] = w2;
    w1 = eval(stack[-2], stack[-3]);
    errexitn(5);
    r = ncons(w1);
    errexitn(5);
    pop2(w3, w2);
    r = list2star(w3, w2, r);
    errexitn(3);
    pop3(w1, env, args);
    while (consp(args))
    {   Lisp_Object w;
        push3(env, args, r);
        w = qcar(args);
        w = eval(w, env);
        pop(r);
        errexitn(2);
        r = cons(w, r);
        pop2(args, env);
        errexit();
        args = qcdr(args);
    }
    return onevalue(nreverse(r));   
}

static Lisp_Object liststar_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object r = nil;
    if (!consp(args)) return aerror("list*");
    do
    {   Lisp_Object w;
        push3(env, args, r);
        w = qcar(args);
        w = eval(w, env);
        pop(r);
        errexitn(2);
        r = cons(w, r);
        pop2(args, env);
        errexit();
        args = qcdr(args);
    } while (consp(args));
    args = qcar(r);
    r = qcdr(r);
    while (r != nil)
    {   Lisp_Object c = r;
        r = qcdr(r);
        qcdr(c) = args;
        args = c;
    }
    return onevalue(args);
}

#endif

#define BODY_LET            0
#define BODY_COMPILER_LET   1
#define BODY_PROG           2

#ifdef COMMON

static Lisp_Object macrolet_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object d, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    d = qcar(args);     /* The bunch of definitions */
    while (consp(d))
    {   Lisp_Object w = qcar(d);    /* w = (name bvl ...) */
        if (consp(w) && consp(qcdr(w)))
        {
/*
 * Here I need to call (expand-definer <form> nil) to map
 * macro specifications with all the possible magic options into ones
 * which just take 2 args, a form and an environment.
 */
            push2(args, env);
            w = cons(expand_def_symbol, w);
            errexitn(2);
            w = Lfuncalln(nil, 3, expand_def_symbol, w, nil);
            errexitn(2);
/*
 * I expect expand-definer to return either
 *     (~~defmacro name bvl ...)
 * OR  (progn XXX (~~defmacro name bvl ...))
 *     where XXX is exactly one form.
 */
            if (qcar(w) == progn_symbol)
                w = qcar(qcdr(qcdr(w)));
            w = qcdr(w);
            w = cons(qcdr(w), qcar(w));
            errexitn(2);
            pop2(env, args);
            env = cons(w, env);
            errexit();
        }
        d = qcdr(d);
    }
    return let_fn_1(nil, qcdr(args), env, BODY_LET);
}

#endif

#ifdef COMMON

static Lisp_Object mv_prog1_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object r, rl, nil = C_nil;
    int nargs, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    errexit();
    rl = nil;
    nargs = exit_count;
    push(r);
/*
 * I could use the Lisp stack to save things here, but I hope that this
 * function is not used much and performance will not matter.
 */
    for (i=nargs; i>=2; i--)
        rl = cons_no_gc((&mv_2)[i-2], rl);
    rl = cons_gc_test(rl);
    errexitn(1);
    push(rl);
    while (is_cons(args = qcdr(args)) && args!=nil)
    {   Lisp_Object w;
        push2(args, env);
        w = qcar(args);
        eval(w, env);
        pop2(env, args);
        errexitn(2);
    }
    pop(rl);
    for (i = 2; i<=nargs; i++)
    {   (&mv_2)[i-2] = qcar(rl);
        rl = qcdr(rl);
    }
    pop(r);
    return nvalues(r, nargs);
}

#endif

static Lisp_Object or_fn(Lisp_Object args, Lisp_Object env)
/* also needs to be a macro for Common Lisp */
{
    Lisp_Object nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    for (;;)
    {   Lisp_Object v = qcar(args);
        args = qcdr(args);
        if (!consp(args)) return eval(v, env);
        push2(args, env);
        v = eval(v, env);
        pop2(env, args);
        errexit();
        if (v != nil) return onevalue(v);
    }
}

static Lisp_Object prog_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object p, nil = C_nil;
    if (!consp(args) || !consp(qcdr(args))) return onevalue(nil);
    stackcheck2(0, args, env);
    push3(nil, args, env);
#define env    stack[0]
#define args   stack[-1]
#define my_tag stack[-2]
/*
 * I need to augment the (lexical) environment with a null block
 * tag so that (return ..) will work as required. See block_fn for
 * further elaboration since (block ..) is the main way of introducing
 * new block tags.
 */
    my_tag = cons(fixnum_of_int(0), nil);
    errexitn(3);
    env = cons(my_tag, env);
    errexitn(3);
    p = let_fn_1(qcar(args), qcdr(args), env, BODY_PROG);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception(); /* Temp restore it */
        qcar(my_tag) = fixnum_of_int(2);    /* Invalidate */
        if (exit_reason == UNWIND_RETURN && exit_tag == my_tag)
        {   exit_reason = UNWIND_NULL;  /* not strictly needed - but tidy */
            popv(3);
            return exit_value;  /* exit_count already OK here */
        }
        if ((exit_reason & UNWIND_ERROR) != 0)
        {   err_printf("\nEvaluating: ");
            loop_print_error(args);
        }
        flip_exception(); /* re-instate exit condition */
        popv(3);
        return nil;
    }
    popv(3);
    return onevalue(nil);
#undef env
#undef args
#undef my_tag
}

#ifdef COMMON
/*-- 
 *-- At one time I though I might implement PROG* in the kernel here, but
 *-- now it seems at least as reasonable to implement it is a Lisp-coded
 *-- macro that expands to BLOCK, LET* and TAGBODY, thus meaning that the
 *-- code that was supposed to be provided here is pretty-well irrelevant.
 *--
 *-- static Lisp_Object progstar_fn(Lisp_Object args, Lisp_Object env)
 *-- /*
 *--  * /* At present this is WRONG in that it is just a copy of prog_fn,
 *--  * so it awaits re-work to make the bindings happen in serial rather
 *--  * than parallel..
 *--  *  /
 *-- {
 *--     Lisp_Object p, nil = C_nil;
 *--     if (!consp(args) || !consp(qcdr(args))) return onevalue(nil);
 *--     stackcheck2(0, args, env);
 *--     push3(nil, args, env);
 *-- #define env    stack[0]
 *-- #define args   stack[-1]
 *-- #define my_tag stack[-2]
 *-- /*
 *--  * I need to augment the (lexical) environment with a null block
 *--  * tag so that (return ..) will work as required. See block_fn for
 *--  * further elaboration since (block ..) is the main way of introducing
 *--  * new block tags.
 *--  * /
 *--     my_tag = cons(fixnum_of_int(0), nil);
 *--     errexitn(3);
 *--     env = cons(my_tag, env);
 *--     errexitn(3);
 *--     p = let_fn_1(qcar(args), qcdr(args), env, BODY_PROG);
 *--     nil = C_nil;
 *--     if (exception_pending())
 *--     {   flip_exception(); /* Temp restore it * /
 *--         qcar(my_tag) = fixnum_of_int(2); /* Invalidate * /
 *--         if (exit_reason == UNWIND_RETURN && exit_tag == my_tag)
 *--         {   exit_reason = UNWIND_NULL;    /* not strictly needed - but tidy * /
 *--             popv(3);
 *--             return exit_value;
 *--         }
 *--         if ((exit_reason & UNWIND_ERROR) != 0)
 *--         {   err_printf("\nEvaluating: ");
 *--             loop_print_error(qcar(args));
 *--         }
 *--         flip_exception(); /* re-instate exit condition * /
 *--         popv(3);
 *--         return nil;
 *--     }
 *--     popv(3);
 *--     return onevalue(nil);
 *-- #undef env
 *-- #undef args
 *-- #undef my_tag
 *-- }
 *--
 */

#endif

Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object f, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    f = nil;
    for (;;)
    {   f = qcar(args);
        args = qcdr(args);
        if (!consp(args)) break;
        push3(args, env, f);
        voideval(f, env);
        pop3(f, env, args);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            if ((exit_reason & UNWIND_ERROR) != 0)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            }
            flip_exception();
            return nil;   /* premature exit */
        }
    }
    return eval(f, env);    /* tail call on last item in the progn */
}

static Lisp_Object prog1_fn(Lisp_Object args, Lisp_Object env)
/*
 * prog1 and prog2 will be implemented as macros for Common Lisp,
 * and are here implemented as special forms too in the expectation
 * that that will be good for performance.
 */
{
    Lisp_Object f, nil = C_nil;
    if (!consp(args)) return onevalue(nil); /* (prog1) -> nil */
    stackcheck2(0, args, env);
    push2(args, env);
    f = qcar(args);
    f = eval(f, env);              /* first arg */
    pop2(env, args);
    push(f);
    errexit();
    for (;;)
    {   args = qcdr(args);
        if (!consp(args)) break;
        push2(args, env);
        {   Lisp_Object w = qcar(args);
            voideval(w, env);
        }
        pop2(env, args);
        errexitn(1);
    }
    pop(f);
    return onevalue(f);     /* always hands back just 1 value */
}

static Lisp_Object prog2_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object f, nil = C_nil;
    if (!consp(args)) return onevalue(nil); /* (prog2) -> nil */
    stackcheck2(0, args, env);
    push2(args, env);
    args = qcar(args);
    voideval(args, env);                    /* discard first arg */
    pop2(env, args);
    errexit();
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil); /* (prog2 x) -> nil */
    push2(args, env);
    f = qcar(args);
    f = eval(f, env);                       /* second arg */
    pop2(env, args);
    push(f);
    errexit();
    for (;;)
    {   args = qcdr(args);
        if (!consp(args)) break;
        push2(args, env);
        args = qcar(args);
        voideval(args, env);
        pop2(env, args);
        errexitn(1);
    }
    pop(f);
    return onevalue(f);     /* always hands back just 1 value */
}

#ifdef COMMON

static Lisp_Object progv_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object syms, vals, specenv, nil = C_nil, w;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    syms = vals = specenv = nil;
    syms = qcar(args);
    args = qcdr(args);
    push5(args, env, syms, vals, specenv);
#define specenv stack[0]
#define vals    stack[-1]
#define syms    stack[-2]
#define env     stack[-3]
#define args    stack[-4]
    syms = eval(syms, env);
    nil = C_nil;
    if (exception_pending() || !consp(args)) { popv(5); return nil; }
    w = qcar(args);
    args = qcdr(args);
    vals = eval(w, env);
    nil = C_nil;
    if (exception_pending() || !consp(args)) { popv(5); return nil; }
    while (consp(syms))
    {   Lisp_Object v = qcar(syms);
        Lisp_Object w1;
        if (consp(vals))
        {   w = qcar(vals);
            vals = qcdr(vals);
        }
        else w = unset_var;
        syms = qcdr(syms);
        if (!is_symbol(v)) continue;
        w1 = cons(v, qvalue(v));
/*
 * If I were to take the error exit here then some variables would have
 * been set to their new values and some not. That would be a mess!
 */
        errexitn(5);
        qvalue(v) = w;
        specenv = cons(w1, specenv);
        errexitn(5);
    }
    args = progn_fn(args, env);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        while (specenv != nil)
        {   Lisp_Object p = qcar(specenv);
            qvalue(qcar(p)) = qcdr(p);
            specenv = qcdr(specenv);
        }
        flip_exception();
        popv(5);
        return nil;
    }
    while (specenv != nil)
    {   Lisp_Object p = qcar(specenv);
        qvalue(qcar(p)) = qcdr(p);
        specenv = qcdr(specenv);
    }
    popv(4);
#undef specenv
#undef vals
#undef syms
#undef env
#undef args
    pop(vals);
    return vals;
}

#endif

Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(env);
    if (consp(args) && qcdr(args) == nil) return onevalue(qcar(args));
    return aerror("quote");
}

static Lisp_Object return_fn(Lisp_Object args, Lisp_Object env)
{
/*
 * First check that the block name (nil in this case) is lexically available
 */
    Lisp_Object p, nil = C_nil;
    stackcheck2(0, args, env);
    for(p=env; consp(p); p=qcdr(p))
    {   Lisp_Object w = qcar(p);
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(0) && qcdr(w) == nil)
        {   p = w;
            goto tag_found;
        }
    }
    return error(1, err_block_tag, nil);
tag_found:
    if (consp(args))
    {
        push(p);
        p = qcar(args);
        env = eval(p, env);
        pop(p);
        errexit();
        exit_value = env;
#ifndef COMMON
        exit_count = 1;
#else
        /* exit_count was left set by the call to eval */
#endif
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    flip_exception();
    return nil;
}

#ifdef COMMON

static Lisp_Object return_from_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object p, tag, nil = C_nil;
    stackcheck2(0, args, env);
    if (!consp(args)) tag = nil;
    else
    {   tag = qcar(args);
        args = qcdr(args);
    }
    for(p=env; consp(p); p=qcdr(p))
    {   Lisp_Object w = qcar(p);
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(0) && qcdr(w) == tag)
        {   p = w;
            goto tag_found;
        }
    }
    return error(1, err_block_tag, tag);
tag_found:
    if (consp(args))
    {
        push(p);
        p = qcar(args);
        env = eval(p, env);
        pop(p);
        errexit();
        exit_value = env;
#ifndef COMMON
        exit_count = 1;
#else
        /* exit_count left set by eval */
#endif
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    flip_exception();
    return nil;
}

#endif

static Lisp_Object setq_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object var, val = nil;
    stackcheck2(0, args, env);
    while (consp(args))
    {   var = qcar(args);
        if (!is_symbol(var) || var == nil || var == lisp_true)
            return aerror("setq (bad variable)");
        args = qcdr(args);
        if (consp(args))
        {   push3(args, env, var);
            val = qcar(args);
            val = eval(val, env);
            pop3(var, env, args);
            errexit();
            args = qcdr(args);
        }
        else val = nil;
#ifndef COMMON
        qvalue(var) = val;
#else
        if (qheader(var) & SYM_SPECIAL_VAR) qvalue(var) = val;
        else
        {   Lisp_Object p = env, w;
            for (;;)
            {   if (!consp(p))
                {
#ifndef COMMON
                    qheader(var) |= SYM_SPECIAL_VAR;
                    push3(args, env, var);
                    debug_printf("\n+++++ "); loop_print_debug(var);
                    debug_printf(" proclaimed SPECIAL by SETQ\n");
                    pop3(var, env, args);
                    errexit();
#endif
                    qvalue(var) = val;
                    break;
                }
                w = qcar(p);
                if (qcar(w) == var)
                {
                    if (qcdr(w) == work_symbol) qvalue(var) = val;
                    else qcdr(w) = val;
                    break;
                }
                p = qcdr(p);
            }
        }
#endif
    }
    return onevalue(val);
}

static Lisp_Object noisy_setq_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object var, val = nil;
    stackcheck2(0, args, env);
    while (consp(args))
    {   var = qcar(args);
        if (!is_symbol(var) || var == nil || var == lisp_true)
            return aerror("setq (bad variable)");
        args = qcdr(args);
        if (consp(args))
        {   push3(args, env, var);
            val = qcar(args);
            val = eval(val, env);
            pop3(var, env, args);
            errexit();
            args = qcdr(args);
        }
        else val = nil;
        push4(var, env, args, val);
        loop_print_trace(var);
        errexitn(4);
        trace_printf(" := ");
        loop_print_trace(stack[0]);
        errexitn(4);
        trace_printf("\n");
        pop4(val, args, env, var);
#ifndef COMMON
        qvalue(var) = val;
#else
        if (qheader(var) & SYM_SPECIAL_VAR) qvalue(var) = val;
        else
        {   Lisp_Object p = env, w;
            for (;;)
            {   if (!consp(p))
                {
#ifndef COMMON
                    qheader(var) |= SYM_SPECIAL_VAR;
                    push3(args, env, var);
                    debug_printf("\n+++++ "); loop_print_debug(var);
                    debug_printf(" proclaimed SPECIAL by SETQ\n");
                    pop3(var, env, args);
                    errexit();
#endif
                    qvalue(var) = val;
                    break;
                }
                w = qcar(p);
                if (qcar(w) == var)
                {
                    if (qcdr(w) == work_symbol) qvalue(var) = val;
                    else qcdr(w) = val;
                    break;
                }
                p = qcdr(p);
            }
        }
#endif
    }
    return onevalue(val);
}

Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object f, p, my_env, nil = C_nil;
/*
 * Bind the labels that occur in this block.  Note that I invalidate
 * these bindings if I ever exit from this block, so that nobody
 * even thinks that they can use (go xx) to get back in.
 */
    stackcheck2(0, args, env);
    f = nil;
    push2(env, args);
    for (p=args; consp(p); p=qcdr(p))
    {   Lisp_Object w = qcar(p);
        if (!consp(w))
        {   Lisp_Object w1;
            push3(f, p, env);
            w1 = cons(fixnum_of_int(1), p);
            pop(env);
            nil = C_nil;
            if (!exception_pending()) env = cons(w1, env);
            pop2(p, f);
            errexitn(2);
        }
    }
    pop(args);
/*
 * (go xx) sets exit_tag to xx, which is then noticed next time tagbody
 * is about to do anything.
 */
    for (p=args;;p = qcdr(p))
    {   nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            pop(my_env);
            if (exit_reason != UNWIND_GO)
            {
                while (env != my_env)
                {   qcar(qcar(env)) = fixnum_of_int(2);
                    env = qcdr(env);
                }
                if ((exit_reason & UNWIND_ERROR) != 0)
                {   err_printf("\nEvaluating: ");
                    loop_print_error(f);
                    ignore_exception();
                }
                flip_exception();
                return nil; /* re-instate exit condition */
            }
            else
            {   for (p=env;;p=qcdr(p))
/*
 * If the target of (go xx) is not found then tagbody returns without
 * clearing exit_tag, thus giving an enclosing tagbody a chance to notice
 * the problem and look for the label.
 */
                {   if (p == my_env) /* Not to a tag in this tagbody */
                    {   while (env != my_env)
                        {   qcar(qcar(env)) = fixnum_of_int(2);
                            env = qcdr(env);
                        }
                        if ((exit_reason & UNWIND_ERROR) != 0)
                        {   err_printf("\nEvaluating: ");
                            loop_print_error(f);
                            ignore_exception();
                        }
                        flip_exception();
                        return nil;
                    }
                    if (exit_tag == qcar(p))
                    {   p = qcdr(qcdr(exit_tag));
                        exit_tag = nil;
                        exit_reason = UNWIND_NULL;
                        push(my_env);
                        break;              /* Success! */
                    }
                }
            }
        }
        if (!consp(p))
        {   pop(my_env);
            while (env != my_env)
            {   qcar(qcar(env)) = fixnum_of_int(2);
                env = qcdr(env);
            }
            return onevalue(nil);
        }
        if (is_cons(f = qcar(p)) && f!=nil)
        {   push3(p, env, f);
            voideval(f, env);
            pop3(f, env, p);
        }
    }
}

#ifdef COMMON

static Lisp_Object the_fn(Lisp_Object args, Lisp_Object env)
/*
 * in effect an identity function for the present
 */
{
    Lisp_Object nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil);
    args = qcar(args);
    return eval(args, env);
}

#endif

static Lisp_Object throw_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object tag, p, nil = C_nil;
    if (!consp(args)) return aerror("throw");
    stackcheck2(0, args, env);
    tag = qcar(args);
    args = qcdr(args);
    push2(args, env);
    tag = eval(tag, env);
    pop2(env, args);
    errexit();
    for (p = catch_tags; p!=nil; p=qcdr(p))
        if (tag == qcar(p)) goto tag_found;
    return aerror("throw: tag not found");
tag_found:
    if (consp(args))
    {
        push(p);
        tag = qcar(args);
        tag = eval(tag, env);
        pop(p);
        errexit();
        exit_value = tag;
#ifndef COMMON
        exit_count = 1;
#else
        /* exit_count left set by eval */
#endif
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    flip_exception();
    return nil;
}

static Lisp_Object unless_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object w, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    w = qcar(args);
    w = eval(w, env);
    pop2(env, args);
    errexit();
    if (w != nil) return onevalue(nil);
    else return progn_fn(qcdr(args), env);
}

static Lisp_Object unwind_protect_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object nil = C_nil;
    Lisp_Object r = nil ,rl = nil;
    int nargs = 0, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    nil = C_nil;
    if (exception_pending())
    {   Lisp_Object xt, xv;
        int xc, xr;
/*
 * Here I am in the process of exiting because of a throw, return-from,
 * go or error.  I need to save all the internal stuff that tells me
 * what is going on so I can restore it after the clean-up forms have been
 * processed.  The values involved are:
 *  (a) exit_tag       marks use of go, return-from or throw
 *  (b) exit_value     first result value (throw, return-from)
 *  (c) exit_count     number of values (throw, return-from)
 *  (d) mv2,...        as indicated by exit_count
 *  (e) exit_reason    what it says.
 */
        flip_exception();
        xv = exit_value;
        xt = exit_tag;
        xc = exit_count;
        xr = exit_reason;
        push2(xv, xt);
        for (i=xc; i>=2; i--)
            rl = cons_no_gc((&mv_2)[i-2], rl);
        rl = cons_gc_test(rl);
        errexitn(2);
        push(rl);
        while (is_cons(args = qcdr(args)) && args!=nil)
        {   Lisp_Object w = qcar(args);
            push2(args, env);
            voideval(w, env);
            pop2(env, args);
            errexitn(3);
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
        flip_exception();
        return nil;
    }
/*
 * Now code (just like multiple-value-prog1) that evaluates the
 * cleanup forms in the case that the protected form exits normally.
 */
#ifndef COMMON
    nargs = 1;  /* Just one value returned */
#else
    nargs = exit_count;
#endif
    push2(args, env);
    for (i=nargs; i>=2; i--)
        rl = cons_no_gc((&mv_2)[i-2], rl);
    rl = cons_gc_test(rl);
    errexitn(2);
    push(rl);
#define env  stack[-1]
#define args stack[-2]
    while (is_cons(args = qcdr(args)) && args!=nil)
    {   Lisp_Object w = qcar(args);
        voideval(w, env);
        errexitn(3);
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

/*
 * Errorset is not defined as part of COMMON Lisp but I want it in
 * any Lisp system that I use notwithstanding that.
 */

#ifndef __cplusplus
jmp_buf *errorset_buffer;
#endif
char *errorset_msg;
static char signal_msg[32];

#ifdef __WATCOMC__
void low_level_signal_handler(int code)
#else
void MS_CDECL low_level_signal_handler(int code)
#endif
{
    Lisp_Object nil;
#ifdef __WATCOMC__
    _fpreset();
#endif
    ignore_exception();
    if (miscflags & HEADLINE_FLAG)
    switch (code)
    {
default:
        sprintf(signal_msg, "Signal (code=%d)", code);
        errorset_msg = signal_msg;
        break;
case SIGFPE:
        errorset_msg = "Floating point exception";
        break;
case SIGSEGV:
        errorset_msg = "Memory access violation";
        break;
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
#ifdef __cplusplus
    throw "low_level_signal_handler";
#else
    longjmp(*errorset_buffer, 1);
#endif
}

void unwind_stack(Lisp_Object *entry_stack, CSLbool findcatch)
{
    Lisp_Object *sp = stack;
    while (sp != entry_stack)
    {   Lisp_Object bv, w;
        int32 n;
        w = *sp--;
        if (findcatch && w == SPID_CATCH) break;
        if (w == (Lisp_Object)SPID_FBIND)
        {
/*
 * Here I have found some fluid binding that need to be unwound. The code
 * here is similar to that for FREERSTR.
 */
            bv = *sp--;
            n = length_of_header(vechdr(bv));
            while (n>4)
            {   Lisp_Object v = *(Lisp_Object *)(
                   (int32)bv + n - (4 + TAG_VECTOR));
                n -= 4;
                qvalue(v) = *sp--;
            }
        }
        else if (w == (Lisp_Object)SPID_PVBIND)
        {   bv = *sp--;
            while (bv != C_nil)
            {   Lisp_Object w = qcar(bv);
                qvalue(qcar(w)) = qcdr(w);
                bv = qcdr(bv);
            }
        }
    }
/*
 * If "findcatch" is true this code must actually update the stack pointer -
 * otherwise it must not. Ugly! The only use with findcatch set true is
 * from the bytecode interpreter (bytes1.c)
 */
    if (findcatch) stack = sp;
}


Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...)
/*
 * This is not a special form, but is put into the code here because,
 * like unwind-protect, it has to re-gain control after an evaluation
 * error.
 */
{
    Lisp_Object r, nil = C_nil, form, fg1, fg2;
    va_list a;
    Lisp_Object *save;
    unsigned32 flags = miscflags;
#ifndef __cplusplus
    jmp_buf this_level, *saved_buffer = errorset_buffer;
#endif
    if (nargs < 1 || nargs > 3) return aerror("errorset");
    va_start(a, nargs);
    form = va_arg(a, Lisp_Object);
    fg1 = fg2 = lisp_true;
    if (nargs >= 2)
    {   fg1 = fg2 = va_arg(a, Lisp_Object);
        if (nargs >= 3) fg2 = va_arg(a, Lisp_Object);
    }
    va_end(a);
    miscflags &= ~(HEADLINE_FLAG | MESSAGES_FLAG);
    if (fg1 != nil) miscflags |= HEADLINE_FLAG;
    if (fg2 != nil) miscflags |= MESSAGES_FLAG;
    push2(codevec, litvec);
    save = stack;
    stackcheck2(2, form, env);
    errorset_msg = NULL;
#ifdef __cplusplus
    try
#else
    if (!setjmp(this_level))
#endif
    {
#ifndef __cplusplus
        errorset_buffer = &this_level;
#endif
        r = eval(form, env);
#ifndef __cplusplus
        errorset_buffer = saved_buffer;
#endif
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            pop2(litvec, codevec);
            miscflags = (flags & ~GC_MSG_BITS) | (miscflags & GC_MSG_BITS);
            switch (exit_reason)
            {
        case UNWIND_RESTART:
                flip_exception();
                return nil; /* Not catchable */
        default:break;
            }
            if (consp(exit_value)) exit_value = nil;
            return onevalue(exit_value);
        }
        pop2(litvec, codevec);
        miscflags = (flags & ~GC_MSG_BITS) | (miscflags & GC_MSG_BITS);
        r = ncons(r);
        errexit();
        return onevalue(r);
    }
#ifdef __cplusplus
    catch (char *)
#else
    else
#endif
    {   if (errorset_msg != NULL)
        {   term_printf("\n%s detected\n", errorset_msg);
            errorset_msg = NULL;
        }
/*
 * Worry about restoration of fluids bound before the exception
 * forced unwinding.  All pretty dreadful, I think.  If I leave fluid
 * unbind information interleaved on the stack I could cope with it
 * here I think... but I have not done so yet.
 */
        unwind_stack(save, NO);
        stack = save;
        nil = C_nil;
        pop2(litvec, codevec);
#ifndef __cplusplus
        errorset_buffer = saved_buffer;
#endif
        signal(SIGFPE, low_level_signal_handler);
#ifdef __WATCOMC__
        _control87(_EM_OVERFLOW | _EM_INVALID | _EM_DENORMAL |
                   _EM_ZERODIVIDE | _EM_INEXACT | _EM_UNDERFLOW,
                   _MCW_EM);
#endif
        if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#ifdef SIGBUS
        if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
        if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
        return onevalue(nil);
    }
}

Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form)
{
    return Lerrorsetn(nil, 3, form, nil, nil);
}


Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1)
{
    return Lerrorsetn(nil, 3, form, ffg1, nil);
}


static Lisp_Object when_fn(Lisp_Object args, Lisp_Object env)
{
    Lisp_Object w, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    w = qcar(args);
    w = eval(w, env);
    pop2(env, args);
    errexit();
    if (w == nil) return onevalue(nil);
    else return progn_fn(qcdr(args), env);
}

setup_type const eval3_setup[] =
{
    {"or",                      or_fn, bad_special2, bad_specialn},
    {"prog",                    prog_fn, bad_special2, bad_specialn},
    {"prog1",                   prog1_fn, bad_special2, bad_specialn},
    {"prog2",                   prog2_fn, bad_special2, bad_specialn},
/*  {"progn",                   progn_fn, bad_special2, bad_specialn}, */
/*  {"quote",                   quote_fn, bad_special2, bad_specialn}, */
    {"return",                  return_fn, bad_special2, bad_specialn},
    {"setq",                    setq_fn, bad_special2, bad_specialn},
    {"noisy-setq",              noisy_setq_fn, bad_special2, bad_specialn},
    {"tagbody",                 tagbody_fn, bad_special2, bad_specialn},
    {"throw",                   throw_fn, bad_special2, bad_specialn},
    {"unless",                  unless_fn, bad_special2, bad_specialn},
    {"unwind-protect",          unwind_protect_fn, bad_special2, bad_specialn},
    {"when",                    when_fn, bad_special2, bad_specialn},
#ifdef COMMON
    {"macrolet",                macrolet_fn, bad_special2, bad_specialn},
    {"multiple-value-call",     mv_call_fn, bad_special2, bad_specialn},
    {"multiple-value-prog1",    mv_prog1_fn, bad_special2, bad_specialn},
/*--{"prog*",                   progstar_fn, bad_special2, bad_specialn}, */
    {"progv",                   progv_fn, bad_special2, bad_specialn},
    {"return-from",             return_from_fn, bad_special2, bad_specialn},
    {"the",                     the_fn, bad_special2, bad_specialn},
#else
    {"list",                    list_fn, bad_special2, bad_specialn},
    {"list*",                   liststar_fn, bad_special2, bad_specialn},
    {"plus",                    plus_fn, bad_special2, bad_specialn},
    {"times",                   times_fn, bad_special2, bad_specialn},
#endif
    {NULL,                      0, 0, 0}};

/* end of eval3.c */
