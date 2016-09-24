//  eval3.cpp                         Copyright (C) 1991-2015 Codemist    

//
// Interpreter (part 3).
// Implementations of special forms (interpreted versions).
//
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


#if 0

static LispObject plus_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r;
    if (!consp(args)) return fixnum_of_int(0); // (plus) => 0
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    errexit();
    args = qcdr(args);
    while (consp(args))
    {   LispObject w;
        push3(env, args, r);
        w = qcar(args);
        w = eval(w, env);
        pop(r);
        errexitn(2);
        if (is_fixnum(r) && is_fixnum(w))
        {   int32_t c = int_of_fixnum(r) + int_of_fixnum(w);
            int32_t w1 = c & fix_mask;
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

static LispObject noisy_plus_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r;
    if (!consp(args)) return fixnum_of_int(0); // (plus) => 0
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = noisy_eval(r, env);
    pop2(env, args);
    errexit();
    args = qcdr(args);
    while (consp(args))
    {   LispObject w;
        push3(env, args, r);
        w = qcar(args);
        w = noisy_eval(w, env);
        pop(r);
        errexitn(2);
        if (is_fixnum(r) && is_fixnum(w))
        {   int32_t c = int_of_fixnum(r) + int_of_fixnum(w);
            int32_t w1 = c & fix_mask;
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

static LispObject times_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r;
    if (!consp(args)) return fixnum_of_int(1); // (times) => 1
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    errexit();
    args = qcdr(args);
    while (consp(args))
    {   LispObject w;
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

static LispObject noisy_times_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r;
    if (!consp(args)) return fixnum_of_int(1); // (times) => 1
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = noisy_eval(r, env);
    pop2(env, args);
    errexit();
    args = qcdr(args);
    while (consp(args))
    {   LispObject w;
        push3(env, args, r);
        w = qcar(args);
        w = noisy_eval(w, env);
        pop(r);
        errexitn(2);
        r = times2(r, w);
        pop2(args, env);
        errexit();
        args = qcdr(args);
    }
    return onevalue(r);
}

#endif

#ifndef COMMON

static LispObject list_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject w1, w2, w3, r = nil;
//
// I am going to write out the cases of list with 0, 1, 2 or 3
// args specially here, since I expect them to be the more common ones
// and I am generally jumpy about performance.  It seems a bit nasty
// to get to an interpreted call to list anyway.
//
    if (!consp(args)) return onevalue(nil); // (list)
    w1 = qcar(args); args = qcdr(args);
    if (!consp(args))                       // (list w1)
    {   w1 = eval(w1, env);
        errexit();
        w1 = ncons(w1);
        errexit();
        return onevalue(w1);
    }
    w2 = qcar(args); args = qcdr(args);
    if (!consp(args))                       // (list w1 w2)
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
    if (!is_cons(args))                     // (list w1 w2 w3)
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
    push4(args, env, w2, w3);
    w1 = eval(w1, env);
    errexitn(4);
    push(w1);
    w2 = eval(stack[-2], stack[-3]);
    errexitn(5);
    stack[-2] = w2;
    w3 = eval(stack[-1], stack[-3]);
    errexitn(5);
    stack[-1] = w3;
    pop(w1);
    r = ncons(w1);
    errexitn(4);
    pop2(w3, w2);
    r = list2star(w3, w2, r);
    errexitn(4);
    pop2(env, args);
    while (consp(args))
    {   LispObject w;
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

static LispObject noisy_list_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject w1, w2, w3, r = nil;
//
// I am going to write out the cases of list with 0, 1, 2 or 3
// args specially here, since I expect them to be the more common ones
// and I am generally jumpy about performance.  It seems a bit nasty
// to get to an interpreted call to list anyway.
//
    if (!consp(args)) return onevalue(nil); // (list)
    w1 = qcar(args); args = qcdr(args);
    if (!consp(args))                       // (list w1)
    {   w1 = noisy_eval(w1, env);
        errexit();
        w1 = ncons(w1);
        errexit();
        return onevalue(w1);
    }
    w2 = qcar(args); args = qcdr(args);
    if (!consp(args))                       // (list w1 w2)
    {   push2(env, w2);
        w1 = noisy_eval(w1, env);
        errexitn(2);
        w2 = stack[0];
        stack[0] = w1;
        w2 = noisy_eval(w2, stack[-1]);
        errexitn(2);
        w1 = list2(stack[0], w2);
        popv(2);
        errexit();
        return onevalue(w1);
    }
    w3 = qcar(args); args = qcdr(args);
    if (!is_cons(args))                     // (list w1 w2 w3)
    {   push3(env, w2, w3);
        w1 = noisy_eval(w1, env);
        errexitn(3);
        w2 = stack[-1];
        stack[-1] = w1;
        w2 = noisy_eval(w2, stack[-2]);
        errexitn(3);
        w3 = stack[0];
        stack[0] = w2;
        w3 = noisy_eval(w3, stack[-2]);
        errexitn(3);
        w3 = ncons(w3);
        errexitn(3);
        w1 = list2star(stack[-1], stack[0], w3);
        popv(3);
        errexit();
        return onevalue(w1);
    }
    push4(args, env, w2, w3);
    w1 = noisy_eval(w1, env);
    errexitn(4);
    push(w1);
    w2 = noisy_eval(stack[-2], stack[-3]);
    errexitn(5);
    stack[-2] = w2;
    w3 = noisy_eval(stack[-1], stack[-3]);
    errexitn(5);
    stack[-1] = w3;
    pop(w1);
    r = ncons(w1);
    errexitn(4);
    pop2(w3, w2);
    r = list2star(w3, w2, r);
    errexitn(4);
    pop2(env, args);
    while (consp(args))
    {   LispObject w;
        push3(env, args, r);
        w = qcar(args);
        w = noisy_eval(w, env);
        pop(r);
        errexitn(2);
        r = cons(w, r);
        pop2(args, env);
        errexit();
        args = qcdr(args);
    }
    return onevalue(nreverse(r));
}

static LispObject liststar_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r = nil;
    if (!consp(args)) return aerror("list*");
    do
    {   LispObject w;
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
    while (consp(args));
    args = qcar(r);
    r = qcdr(r);
    while (r != nil)
    {   LispObject c = r;
        r = qcdr(r);
        qcdr(c) = args;
        args = c;
    }
    return onevalue(args);
}

static LispObject noisy_liststar_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r = nil;
    if (!consp(args)) return aerror("list*");
    do
    {   LispObject w;
        push3(env, args, r);
        w = qcar(args);
        w = noisy_eval(w, env);
        pop(r);
        errexitn(2);
        r = cons(w, r);
        pop2(args, env);
        errexit();
        args = qcdr(args);
    }
    while (consp(args));
    args = qcar(r);
    r = qcdr(r);
    while (r != nil)
    {   LispObject c = r;
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

static LispObject macrolet_fn(LispObject args, LispObject env)
{   LispObject d, nil = C_nil;
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
            errexitn(2);
            w = Lfuncalln(nil, 3, expand_def_symbol, w, nil);
            errexitn(2);
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
            errexitn(2);
            pop2(env, args);
            env = cons(w, env);
            errexit();
        }
        d = qcdr(d);
    }
    return let_fn_1(nil, qcdr(args), env, BODY_LET, 0);
}

static LispObject noisy_macrolet_fn(LispObject args, LispObject env)
{   LispObject d, nil = C_nil;
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
            errexitn(2);
            w = Lfuncalln(nil, 3, expand_def_symbol, w, nil);
            errexitn(2);
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
            errexitn(2);
            pop2(env, args);
            env = cons(w, env);
            errexit();
        }
        d = qcdr(d);
    }
    return let_fn_1(nil, qcdr(args), env, BODY_LET, 1);
}

#endif

#ifdef COMMON

static LispObject mv_prog1_fn(LispObject args, LispObject env)
{   LispObject r, rl, nil = C_nil;
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
//
// I could use the Lisp stack to save things here, but I hope that this
// function is not used much and performance will not matter.
//
    for (i=nargs; i>=2; i--)
        rl = cons_no_gc((&mv_2)[i-2], rl);
    rl = cons_gc_test(rl);
    errexitn(1);
    push(rl);
    while (is_cons(args = qcdr(args)) && args!=nil)
    {   LispObject w;
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

static LispObject noisy_mv_prog1_fn(LispObject args, LispObject env)
{   LispObject r, rl, nil = C_nil;
    int nargs, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = noisy_eval(r, env);
    pop2(env, args);
    errexit();
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
    errexitn(1);
    push(rl);
    while (is_cons(args = qcdr(args)) && args!=nil)
    {   LispObject w;
        push2(args, env);
        w = qcar(args);
        noisy_eval(w, env);
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

static LispObject or_fn(LispObject args, LispObject env)
// also needs to be a macro for Common Lisp
{   LispObject nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    for (;;)
    {   LispObject v = qcar(args);
        args = qcdr(args);
        if (!consp(args)) return eval(v, env);
        push2(args, env);
        v = eval(v, env);
        pop2(env, args);
        errexit();
        if (v != nil) return onevalue(v);
    }
}

static LispObject noisy_or_fn(LispObject args, LispObject env)
// also needs to be a macro for Common Lisp
{   LispObject nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    for (;;)
    {   LispObject v = qcar(args);
        args = qcdr(args);
        if (!consp(args)) return noisy_eval(v, env);
        push2(args, env);
        v = noisy_eval(v, env);
        pop2(env, args);
        errexit();
        if (v != nil) return onevalue(v);
    }
}

static LispObject prog_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    if (!consp(args) || !consp(qcdr(args))) return onevalue(nil);
    stackcheck2(0, args, env);
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
    errexitn(3);
    env = cons(my_tag, env);
    errexitn(3);
    let_fn_1(qcar(args), qcdr(args), env, BODY_PROG, 0);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception(); // Temp restore it
        qcar(my_tag) = fixnum_of_int(2);    // Invalidate
        if (exit_reason == UNWIND_RETURN && exit_tag == my_tag)
        {   exit_reason = UNWIND_NULL;  // not strictly needed - but tidy
            popv(3);
            return exit_value;  // exit_count already OK here
        }
        if (SHOW_FNAME)
        {   err_printf("\nEvaluating: ");
            loop_print_error(args);
        }
        flip_exception(); // re-instate exit condition
        popv(3);
        return nil;
    }
    popv(3);
    return onevalue(nil);
#undef env
#undef args
#undef my_tag
}

static LispObject noisy_prog_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    if (!consp(args) || !consp(qcdr(args))) return onevalue(nil);
    stackcheck2(0, args, env);
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
    errexitn(3);
    env = cons(my_tag, env);
    errexitn(3);
    let_fn_1(qcar(args), qcdr(args), env, BODY_PROG, 1);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception(); // Temp restore it
        qcar(my_tag) = fixnum_of_int(2);    // Invalidate
        if (exit_reason == UNWIND_RETURN && exit_tag == my_tag)
        {   exit_reason = UNWIND_NULL;  // not strictly needed - but tidy
            popv(3);
            return exit_value;  // exit_count already OK here
        }
        if (SHOW_FNAME)
        {   err_printf("\nEvaluating: ");
            loop_print_error(args);
        }
        flip_exception(); // re-instate exit condition
        popv(3);
        return nil;
    }
    popv(3);
    return onevalue(nil);
#undef env
#undef args
#undef my_tag
}

LispObject progn_fn(LispObject args, LispObject env)
{   LispObject f, nil = C_nil;
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
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            }
            flip_exception();
            return nil;   // premature exit
        }
    }
    return eval(f, env);    // tail call on last item in the progn
}

LispObject noisy_progn_fn(LispObject args, LispObject env)
{   LispObject f, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    f = nil;
    for (;;)
    {   f = qcar(args);
        args = qcdr(args);
        if (!consp(args)) break;
        push3(args, env, f);
        noisy_voideval(f, env);
        pop3(f, env, args);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            }
            flip_exception();
            return nil;   // premature exit
        }
    }
    return noisy_eval(f, env);    // tail call on last item in the progn
}

static LispObject prog1_fn(LispObject args, LispObject env)
//
// prog1 and prog2 will be implemented as macros for Common Lisp,
// and are here implemented as special forms too in the expectation
// that that will be good for performance.
//
{   LispObject f, nil = C_nil;
    if (!consp(args)) return onevalue(nil); // (prog1) -> nil
    stackcheck2(0, args, env);
    push2(args, env);
    f = qcar(args);
    f = eval(f, env);              // first arg
    pop2(env, args);
    push(f);
    errexit();
    for (;;)
    {   args = qcdr(args);
        if (!consp(args)) break;
        push2(args, env);
        {   LispObject w = qcar(args);
            voideval(w, env);
        }
        pop2(env, args);
        errexitn(1);
    }
    pop(f);
    return onevalue(f);     // always hands back just 1 value
}

static LispObject noisy_prog1_fn(LispObject args, LispObject env)
//
// prog1 and prog2 will be implemented as macros for Common Lisp,
// and are here implemented as special forms too in the expectation
// that that will be good for performance.
//
{   LispObject f, nil = C_nil;
    if (!consp(args)) return onevalue(nil); // (prog1) -> nil
    stackcheck2(0, args, env);
    push2(args, env);
    f = qcar(args);
    f = noisy_eval(f, env);              // first arg
    pop2(env, args);
    push(f);
    errexit();
    for (;;)
    {   args = qcdr(args);
        if (!consp(args)) break;
        push2(args, env);
        {   LispObject w = qcar(args);
            noisy_voideval(w, env);
        }
        pop2(env, args);
        errexitn(1);
    }
    pop(f);
    return onevalue(f);     // always hands back just 1 value
}

static LispObject prog2_fn(LispObject args, LispObject env)
{   LispObject f, nil = C_nil;
    if (!consp(args)) return onevalue(nil); // (prog2) -> nil
    stackcheck2(0, args, env);
    push2(args, env);
    args = qcar(args);
    voideval(args, env);                    // discard first arg
    pop2(env, args);
    errexit();
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil); // (prog2 x) -> nil
    push2(args, env);
    f = qcar(args);
    f = eval(f, env);                       // second arg
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
    return onevalue(f);     // always hands back just 1 value
}

static LispObject noisy_prog2_fn(LispObject args, LispObject env)
{   LispObject f, nil = C_nil;
    if (!consp(args)) return onevalue(nil); // (prog2) -> nil
    stackcheck2(0, args, env);
    push2(args, env);
    args = qcar(args);
    noisy_voideval(args, env);                    // discard first arg
    pop2(env, args);
    errexit();
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil); // (prog2 x) -> nil
    push2(args, env);
    f = qcar(args);
    f = noisy_eval(f, env);                       // second arg
    pop2(env, args);
    push(f);
    errexit();
    for (;;)
    {   args = qcdr(args);
        if (!consp(args)) break;
        push2(args, env);
        args = qcar(args);
        noisy_voideval(args, env);
        pop2(env, args);
        errexitn(1);
    }
    pop(f);
    return onevalue(f);     // always hands back just 1 value
}

#ifdef COMMON

static LispObject progv_fn(LispObject args, LispObject env)
{   LispObject syms, vals, specenv, nil = C_nil, w;
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
    if (exception_pending() || !consp(args))
    {   popv(5);
        return nil;
    }
    w = qcar(args);
    args = qcdr(args);
    vals = eval(w, env);
    nil = C_nil;
    if (exception_pending() || !consp(args))
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
        {   LispObject p = qcar(specenv);
            qvalue(qcar(p)) = qcdr(p);
            specenv = qcdr(specenv);
        }
        flip_exception();
        popv(5);
        return nil;
    }
    while (specenv != nil)
    {   LispObject p = qcar(specenv);
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

static LispObject noisy_progv_fn(LispObject args, LispObject env)
{   LispObject syms, vals, specenv, nil = C_nil, w;
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
    if (exception_pending() || !consp(args))
    {   popv(5);
        return nil;
    }
    w = qcar(args);
    args = qcdr(args);
    vals = noisy_eval(w, env);
    nil = C_nil;
    if (exception_pending() || !consp(args))
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
        errexitn(5);
        qvalue(v) = w;
        specenv = cons(w1, specenv);
        errexitn(5);
    }
    args = noisy_progn_fn(args, env);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        while (specenv != nil)
        {   LispObject p = qcar(specenv);
            qvalue(qcar(p)) = qcdr(p);
            specenv = qcdr(specenv);
        }
        flip_exception();
        popv(5);
        return nil;
    }
    while (specenv != nil)
    {   LispObject p = qcar(specenv);
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

LispObject quote_fn(LispObject args, LispObject)
{   LispObject nil = C_nil;
    if (consp(args) && qcdr(args) == nil) return onevalue(qcar(args));
    return aerror("quote");
}

static LispObject return_fn(LispObject args, LispObject env)
{
//
// First check that the block name (nil in this case) is lexically available
//
    LispObject p, nil = C_nil;
    stackcheck2(0, args, env);
    for(p=env; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p);
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(0) && qcdr(w) == nil)
        {   p = w;
            goto tag_found;
        }
    }
    return error(1, err_block_tag, nil);
tag_found:
    if (consp(args))
    {   push(p);
        p = qcar(args);
        env = eval(p, env);
        pop(p);
        errexit();
        exit_value = env;
#ifndef COMMON
        exit_count = 1;
#else
        // exit_count was left set by the call to eval
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

static LispObject noisy_return_fn(LispObject args, LispObject env)
{
//
// First check that the block name (nil in this case) is lexically available
//
    LispObject p, nil = C_nil;
    stackcheck2(0, args, env);
    for(p=env; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p);
        if (!consp(w)) continue;
        if (qcar(w) == fixnum_of_int(0) && qcdr(w) == nil)
        {   p = w;
            goto tag_found;
        }
    }
    return error(1, err_block_tag, nil);
tag_found:
    if (consp(args))
    {   push(p);
        p = qcar(args);
        env = noisy_eval(p, env);
        pop(p);
        errexit();
        exit_value = env;
#ifndef COMMON
        exit_count = 1;
#else
        // exit_count was left set by the call to eval
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

static LispObject return_from_fn(LispObject args, LispObject env)
{   LispObject p, tag, nil = C_nil;
    stackcheck2(0, args, env);
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
    return error(1, err_block_tag, tag);
tag_found:
    if (consp(args))
    {   push(p);
        p = qcar(args);
        env = eval(p, env);
        pop(p);
        errexit();
        exit_value = env;
#ifndef COMMON
        exit_count = 1;
#else
        // exit_count left set by eval
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

static LispObject noisy_return_from_fn(LispObject args, LispObject env)
{   LispObject p, tag, nil = C_nil;
    stackcheck2(0, args, env);
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
    return error(1, err_block_tag, tag);
tag_found:
    if (consp(args))
    {   push(p);
        p = qcar(args);
        env = noisy_eval(p, env);
        pop(p);
        errexit();
        exit_value = env;
#ifndef COMMON
        exit_count = 1;
#else
        // exit_count left set by eval
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

static LispObject setq_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject var, val = nil;
    stackcheck2(0, args, env);
    while (consp(args))
    {   var = qcar(args);
        if (!is_symbol(var) || var == nil || var == lisp_true)
            return aerror1("setq (bad variable)", var);
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
        {   LispObject p = env, w;
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
                {   if (qcdr(w) == work_symbol) qvalue(var) = val;
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

static LispObject noisy_setq_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject var, val = nil;
    stackcheck2(0, args, env);
    while (consp(args))
    {   var = qcar(args);
        if (!is_symbol(var) || var == nil || var == lisp_true)
            return aerror1("setq (bad variable)", var);
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
        freshline_trace();
        trace_printf("+++ [traceset]: ");
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
        {   LispObject p = env, w;
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
                {   if (qcdr(w) == work_symbol) qvalue(var) = val;
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

LispObject tagbody_fn(LispObject args, LispObject env)
{   LispObject f, p, my_env, nil = C_nil;
//
// Bind the labels that occur in this block.  Note that I invalidate
// these bindings if I ever exit from this block, so that nobody
// even thinks that they can use (go xx) to get back in.
//
    stackcheck2(0, args, env);
    f = nil;
    push2(env, args);
    for (p=args; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p);
        if (!consp(w))
        {   LispObject w1;
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
//
// (go xx) sets exit_tag to xx, which is then noticed next time tagbody
// is about to do anything.
//
    for (p=args;; p = qcdr(p))
    {   nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            pop(my_env);
            if (exit_reason != UNWIND_GO)
            {   while (env != my_env)
                {   qcar(qcar(env)) = fixnum_of_int(2);
                    env = qcdr(env);
                }
                if (SHOW_FNAME)
                {   err_printf("\nEvaluating: ");
                    loop_print_error(f);
                    ignore_exception();
                }
                flip_exception();
                return nil; // re-instate exit condition
            }
            else
            {   for (p=env;; p=qcdr(p))
//
// If the target of (go xx) is not found then tagbody returns without
// clearing exit_tag, thus giving an enclosing tagbody a chance to notice
// the problem and look for the label.
//
                {   if (p == my_env) // Not to a tag in this tagbody
                    {   while (env != my_env)
                        {   qcar(qcar(env)) = fixnum_of_int(2);
                            env = qcdr(env);
                        }
                        if (SHOW_FNAME)
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
                        break;              // Success!
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

LispObject noisy_tagbody_fn(LispObject args, LispObject env)
{   LispObject f, p, my_env, nil = C_nil;
//
// Bind the labels that occur in this block.  Note that I invalidate
// these bindings if I ever exit from this block, so that nobody
// even thinks that they can use (go xx) to get back in.
//
    stackcheck2(0, args, env);
    f = nil;
    push2(env, args);
    for (p=args; consp(p); p=qcdr(p))
    {   LispObject w = qcar(p);
        if (!consp(w))
        {   LispObject w1;
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
//
// (go xx) sets exit_tag to xx, which is then noticed next time tagbody
// is about to do anything.
//
    for (p=args;; p = qcdr(p))
    {   nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            pop(my_env);
            if (exit_reason != UNWIND_GO)
            {   while (env != my_env)
                {   qcar(qcar(env)) = fixnum_of_int(2);
                    env = qcdr(env);
                }
                if (SHOW_FNAME)
                {   err_printf("\nEvaluating: ");
                    loop_print_error(f);
                    ignore_exception();
                }
                flip_exception();
                return nil; // re-instate exit condition
            }
            else
            {   for (p=env;; p=qcdr(p))
//
// If the target of (go xx) is not found then tagbody returns without
// clearing exit_tag, thus giving an enclosing tagbody a chance to notice
// the problem and look for the label.
//
                {   if (p == my_env) // Not to a tag in this tagbody
                    {   while (env != my_env)
                        {   qcar(qcar(env)) = fixnum_of_int(2);
                            env = qcdr(env);
                        }
                        if (SHOW_FNAME)
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
                        break;              // Success!
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
            noisy_voideval(f, env);
            pop3(f, env, p);
        }
    }
}

#ifdef COMMON

static LispObject the_fn(LispObject args, LispObject env)
//
// in effect an identity function for the present
//
{   LispObject nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil);
    args = qcar(args);
    return eval(args, env);
}

static LispObject noisy_the_fn(LispObject args, LispObject env)
//
// in effect an identity function for the present
//
{   LispObject nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    args = qcdr(args);
    if (!consp(args)) return onevalue(nil);
    args = qcar(args);
    return noisy_eval(args, env);
}

//
// In Common Lisp mode THROW has to be a special form because of the
// case where the information being thrown involves multiple values. For
// Standard Lisp I can perfectly well provide a simple function.
//

static LispObject throw_fn(LispObject args, LispObject env)
{   LispObject tag, p, nil = C_nil;
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
    {   push(p);
        tag = qcar(args);
        tag = eval(tag, env);
        pop(p);
        errexit();
        exit_value = tag;
#ifndef COMMON
        exit_count = 1;
#else
        // exit_count left set by eval
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

static LispObject noisy_throw_fn(LispObject args, LispObject env)
{   LispObject tag, p, nil = C_nil;
    if (!consp(args)) return aerror("throw");
    stackcheck2(0, args, env);
    tag = qcar(args);
    args = qcdr(args);
    push2(args, env);
    tag = noisy_eval(tag, env);
    pop2(env, args);
    errexit();
    for (p = catch_tags; p!=nil; p=qcdr(p))
        if (tag == qcar(p)) goto tag_found;
    return aerror("throw: tag not found");
tag_found:
    if (consp(args))
    {   push(p);
        tag = qcar(args);
        tag = noisy_eval(tag, env);
        pop(p);
        errexit();
        exit_value = tag;
#ifndef COMMON
        exit_count = 1;
#else
        // exit_count left set by eval
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

#endif

LispObject Lthrow_one_value(LispObject nil, LispObject tag, LispObject val)
{   LispObject p;
    for (p = catch_tags; p!=nil; p=qcdr(p))
        if (tag == qcar(p)) goto tag_found;
    return aerror("throw: tag not found");
tag_found:
    exit_value = val;
#ifndef COMMON
    exit_count = 1;
#endif
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    flip_exception();
    return nil;
}

LispObject Lthrow_nil(LispObject nil, LispObject tag)
{   return Lthrow_one_value(nil, tag, nil);
}

static LispObject unless_fn(LispObject args, LispObject env)
{   LispObject w, nil = C_nil;
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

static LispObject noisy_unless_fn(LispObject args, LispObject env)
{   LispObject w, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    w = qcar(args);
    w = noisy_eval(w, env);
    pop2(env, args);
    errexit();
    if (w != nil) return onevalue(nil);
    else return noisy_progn_fn(qcdr(args), env);
}

static LispObject unwind_protect_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r = nil, rl = nil;
    int nargs = 0, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = eval(r, env);
    pop2(env, args);
    nil = C_nil;
    if (exception_pending())
    {   LispObject xt, xv;
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
        flip_exception();
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
        errexitn(3);   // Running out of space in recovery code3 is sad
        push(rl);
        while (is_cons(args = qcdr(args)) && args!=nil)
        {   LispObject w = qcar(args);
            push2(args, env);
            voideval(w, env);
            pop2(env, args);
            errexitn(4);
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
        flip_exception();
        return nil;
    }
//
// Now code (just like multiple-value-prog1) that evaluates the
// cleanup forms in the case that the protected form exits normally.
//
#ifndef COMMON
    nargs = 1;  // Just one value returned
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
    {   LispObject w = qcar(args);
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

static LispObject noisy_unwind_protect_fn(LispObject args, LispObject env)
{   LispObject nil = C_nil;
    LispObject r = nil, rl = nil;
    int nargs = 0, i;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    r = qcar(args);
    r = noisy_eval(r, env);
    pop2(env, args);
    nil = C_nil;
    if (exception_pending())
    {   LispObject xt, xv;
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
        flip_exception();
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
        errexitn(3);   // Running out of space in recovery code3 is sad
        push(rl);
        while (is_cons(args = qcdr(args)) && args!=nil)
        {   LispObject w = qcar(args);
            push2(args, env);
            noisy_voideval(w, env);
            pop2(env, args);
            errexitn(4);
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
        flip_exception();
        return nil;
    }
//
// Now code (just like multiple-value-prog1) that evaluates the
// cleanup forms in the case that the protected form exits normally.
//
#ifndef COMMON
    nargs = 1;  // Just one value returned
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
    {   LispObject w = qcar(args);
        noisy_voideval(w, env);
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

//
// Errorset is not defined as part of COMMON Lisp but I want it in
// any Lisp system that I use notwithstanding that.
//

const char *errorset_msg;
static char signal_msg[32];

void low_level_signal_handler(int code)
{
//
// Observe, if you will, that in the case of a SIGSEGV this function does
// not use a significant amount of stack end ends up just doing a
// throw. Well the biggest stack use could be via sprintf if I had
// an unknown signal code - it may be worth re-working that as in-line code
// to be extra cautious.
//
    LispObject nil;
    ignore_exception();
    if (miscflags & HEADLINE_FLAG)
        switch (code)
    {       default:
                sprintf(signal_msg, "Signal (code=%d)", code);
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
    throw "low_level_signal_handler";
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
            while (bv != C_nil)
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

static LispObject errorset3(volatile LispObject env,
                            volatile LispObject form,
                            volatile LispObject fg1,
                            volatile LispObject fg2)
{   volatile LispObject nil = C_nil, r;
    volatile uint32_t flags = miscflags;
    LispObject * volatile save;

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

    push2(codevec, litvec);
    save = stack;
    stackcheck2(2, form, env);
    errorset_msg = NULL;
    try
    {
        r = eval(form, env);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            pop2(litvec, codevec);
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
            switch (exit_reason)
            {   case UNWIND_RESTART:
                case UNWIND_RESOURCE:
                case UNWIND_THROW:
                    flip_exception();
                    return nil; // Not catchable
                default:break;
            }
            if (consp(exit_value)) exit_value = nil;
            return onevalue(exit_value);
        }
        pop2(litvec, codevec);
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
        errexit();
        return onevalue(r);
    }
    catch (const char *)
    {
//
// Note that this is where a throw might suddenly get me back to. The
// values of any local variables that are not marked as "volatile" could
// be uncertain here! So I hope I have tagged the right things as
// volatile. Maybe with C++ that is no longer an issue.
//
        nil = C_nil;
        if (errorset_msg != NULL)
        {   term_printf("\n%s detected\n", errorset_msg);
            errorset_msg = NULL;
        }
//
// Worry about restoration of fluids bound before the exception
// forced unwinding.  All pretty dreadful, I think.
//
        unwind_stack(save, false);
//
// I also suspect I should restore miscflags from flags...
//
        stack = save;
        nil = C_nil;
        pop2(litvec, codevec);
#ifndef UNDER_CE
        signal(SIGFPE, low_level_signal_handler);
#ifdef USE_SIGALTSTACK
// SIGSEGV will be handled on the alternative stack
        {   struct sigaction sa;
            sa.sa_handler = low_level_signal_handler;
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = SA_ONSTACK | SA_RESETHAND;
            if (segvtrap) sigaction(SIGSEGV, &sa, NULL);
        }
#else
        if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#endif
#ifdef SIGBUS
        if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
        if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
#endif
        errors_now++;
        if (errors_limit >= 0 && errors_now > errors_limit)
            return resource_exceeded();
        return onevalue(nil);
    }
}

LispObject Lerrorsetn(LispObject env, int nargs, ...)
//
// This is not a special form, but is put into the code here because,
// like unwind-protect, it has to re-gain control after an evaluation
// error.
//
{   LispObject form, fg1, fg2;
    va_list a;
    if (nargs < 1 || nargs > 3) return aerror("errorset");
    va_start(a, nargs);
    form = va_arg(a, LispObject);
    fg1 = fg2 = lisp_true;
    if (nargs >= 2)
    {   fg1 = fg2 = va_arg(a, LispObject);
        if (nargs >= 3) fg2 = va_arg(a, LispObject);
    }
    va_end(a);
    return errorset3(env, form, fg1, fg2);
}

LispObject Lerrorset1(LispObject nil, LispObject form)
{   return errorset3(nil, form, nil, nil);
}


LispObject Lerrorset2(LispObject nil, LispObject form, LispObject ffg1)
{   return errorset3(nil, form, ffg1, nil);
}

//
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

static LispObject resource_limit7(volatile LispObject env,
                                  volatile LispObject form,
                                  volatile LispObject ltime,
                                  volatile LispObject lspace,
                                  volatile LispObject lio,
                                  volatile LispObject lerrors,
                                  volatile LispObject Csk,
                                  volatile LispObject Lsk)
{
//
// This is being extended to make it possible to limit the C and Lisp stack
// usage. At present the controls for that are not in place!
//
    volatile LispObject nil = C_nil, r;
    volatile int64_t lltime, llspace, llio, llerrors;
    volatile int64_t save_time_base   = time_base,
                     save_space_base  = space_base,
                     save_io_base     = io_base,
                     save_errors_base = errors_base;
    volatile int64_t save_time_limit  = time_limit,
                     save_space_limit = space_limit,
                     save_io_limit    = io_limit,
                     save_errors_limit= errors_limit;
    volatile int64_t r0=0, r1=0, r2=0, r3=0;
    LispObject * volatile save;
    push2(codevec, litvec);
    save = stack;
    stackcheck2(2, form, env);
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
    {   time_base   = time_now;
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
        r = eval(form, env);
        r0 = time_now - time_base;
        r1 = (space_now - space_base)/
             ((2*sizeof(LispObject)*1024*1024)/PAGE_POWER_OF_TWO);
        r2 = io_now - io_base;
        r3 = errors_now - errors_base;
//
// Restore limits. This is OK if the inner call gets here via a regular
// return, but I may need to worry about exceptions too.
//
        time_base  = save_time_base;  space_base   = save_space_base;
        io_base    = save_io_base;    errors_base  = save_errors_base;
        time_limit = save_time_limit; space_limit  = save_space_limit;
        io_limit   = save_io_limit;   errors_limit = save_errors_limit;
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            pop2(litvec, codevec);
//
// I suspect I want to process restart!-csl here and prevent that from being
// able to circumvent resource limits.
//
            if (exit_reason != UNWIND_RESOURCE)
            {   flip_exception();
                return nil;
            }
            form = list4(fixnum_of_int(r0),
                         fixnum_of_int(r1),
                         fixnum_of_int(r2),
                         fixnum_of_int(r3));
            errexit();
            form = list4(fixnum_of_int(r0),
                         fixnum_of_int(r1),
                         fixnum_of_int(r2),
                         fixnum_of_int(r3));
            errexit();
            qvalue(resources) = form;
// Here I had a resource limit trap
            return onevalue(nil);
        }
        pop2(litvec, codevec);
//
// I would like the result to show what resources had been used, but for now
// I just use ncons to wrap the resuult up.
//
        r = ncons(r);
        errexit();
        push(r);
        form = list4(fixnum_of_int(r0),
                     fixnum_of_int(r1),
                     fixnum_of_int(r2),
                     fixnum_of_int(r3));
        pop(r);
        errexit();
        qvalue(resources) = form;
        return onevalue(r);
    }
    catch (const char *)
    {   nil = C_nil;
        time_base  = save_time_base;  space_base   = save_space_base;
        io_base    = save_io_base;    errors_base  = save_errors_base;
        time_limit = save_time_limit; space_limit  = save_space_limit;
        io_limit   = save_io_limit;   errors_limit = save_errors_limit;
        if (errorset_msg != NULL)
        {   term_printf("\n%s detected\n", errorset_msg);
            errorset_msg = NULL;
        }
//
// Worry about restoration of fluids bound before the exception
// forced unwinding.  All pretty dreadful, I think.
//
        unwind_stack(save, false);
        stack = save;
        nil = C_nil;
        pop2(litvec, codevec);
#ifndef UNDER_CE
        signal(SIGFPE, low_level_signal_handler);
#ifdef USE_SIGALTSTACK
// SIGSEGV will be handled on the alternative stack
        {   struct sigaction sa;
            sa.sa_handler = low_level_signal_handler;
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = SA_ONSTACK | SA_RESETHAND;
            if (segvtrap) sigaction(SIGSEGV, &sa, NULL);
        }
#else
        if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#endif
#ifdef SIGBUS
        if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
        if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
#endif
        {   LispObject r = list4(fixnum_of_int(r0),
                                 fixnum_of_int(r1),
                                 fixnum_of_int(r2),
                                 fixnum_of_int(r3));
            errexit();
            qvalue(resources) = r;
        }
        return aerror("signal caught");
    }
}

LispObject Lresource_limitn(LispObject env, int nargs, ...)
{   LispObject form, ltime, lspace, lio, lerrors, Csk, Lsk;
    va_list a;
    if (nargs < 2 || nargs > 7) return aerror("resource_limit");
    va_start(a, nargs);
    form = va_arg(a, LispObject);
    ltime = lspace = lio = lerrors = Csk = Lsk = fixnum_of_int(-1);
    if (nargs >= 2)
    {   ltime = va_arg(a, LispObject);
        if (nargs >= 3)
        {   lspace = va_arg(a, LispObject);
            if (nargs >= 4)
            {   lio = va_arg(a, LispObject);
                if (nargs >= 5)
                {   lerrors = va_arg(a, LispObject);
                    if (nargs >= 6)
                    {   Csk = va_arg(a, LispObject);
                        if (nargs >= 7)
                        {   Lsk = va_arg(a, LispObject);
                        }
                    }
                }
            }
        }
    }
    va_end(a);
    return resource_limit7(env, form, ltime, lspace, lio, lerrors, Csk, Lsk);
}


LispObject Lresource_limit2(LispObject nil, LispObject form, LispObject ltime)
{   return resource_limit7(nil, form, ltime,
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1));
}


static LispObject when_fn(LispObject args, LispObject env)
{   LispObject w, nil = C_nil;
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

static LispObject noisy_when_fn(LispObject args, LispObject env)
{   LispObject w, nil = C_nil;
    if (!consp(args)) return onevalue(nil);
    stackcheck2(0, args, env);
    push2(args, env);
    w = qcar(args);
    w = noisy_eval(w, env);
    pop2(env, args);
    errexit();
    if (w == nil) return onevalue(nil);
    else return noisy_progn_fn(qcdr(args), env);
}

setup_type const eval3_setup[] =
{   {"or",                      or_fn, (two_args *)noisy_or_fn, bad_specialn},
    {"prog",                    prog_fn, (two_args *)noisy_prog_fn, bad_specialn},
    {"prog1",                   prog1_fn, (two_args *)noisy_prog1_fn, bad_specialn},
    {"prog2",                   prog2_fn, (two_args *)noisy_prog2_fn, bad_specialn},
//
// progn and quote are initialised in restart.cpp so do not need
// to me included here - I put them in as comments as a reminder.
//  {"progn",                   progn_fn, (two_args *)noisy_progn_fn, bad_specialn},
//  {"quote",                   quote_fn, (two_args *)quote_fn, bad_specialn},
//
    {"return",                  return_fn, (two_args *)noisy_return_fn, bad_specialn},
    {"setq",                    setq_fn, (two_args *)noisy_setq_fn, bad_specialn},
    {"noisy-setq",              noisy_setq_fn, (two_args *)noisy_setq_fn, bad_specialn},
    {"tagbody",                 tagbody_fn, (two_args *)noisy_tagbody_fn, bad_specialn},
    {"unless",                  unless_fn, (two_args *)noisy_unless_fn, bad_specialn},
    {"unwind-protect",          unwind_protect_fn, (two_args *)noisy_unwind_protect_fn, bad_specialn},
    {"when",                    when_fn, (two_args *)noisy_when_fn, bad_specialn},
#ifdef COMMON
    {"macrolet",                macrolet_fn, (two_args *)noisy_macrolet_fn, bad_specialn},
    {"multiple-value-call",     mv_call_fn, (two_args *)noisy_multiple_value_call_fn, bad_specialn},
    {"multiple-value-prog1",    mv_prog1_fn, (two_args *)noisy_multiple_value_prog1_fn, bad_specialn},
    {"progv",                   progv_fn, (two_args *)noisy_progv_fn, bad_specialn},
    {"return-from",             return_from_fn, (two_args *)noisy_return_from_fn, bad_specialn},
    {"the",                     the_fn, (two_args *)noisy_the_fn, bad_specialn},
    {"throw",                   throw_fn, (two_args *)noisy_throw_fn, bad_specialn},
#else
    {"list",                    list_fn, (two_args *)noisy_list_fn, bad_specialn},
    {"list*",                   liststar_fn, (two_args *)noisy_liststar_fn, bad_specialn},
//  {"plus",                    plus_fn, (two_args *)noisy_plus_fn, bad_specialn},
//  {"times",                   times_fn, (two_args *)noisy_times_fn, bad_specialn},
#endif
    {NULL,                      0, 0, 0}
};

// end of eval3.cpp
