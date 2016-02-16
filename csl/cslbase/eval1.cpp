//  eval1.cpp                         Copyright (C) 1989-2015 Codemist Ltd

//
// Interpreter (part 1).
//

/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

LispObject nreverse(LispObject a)
{   LispObject nil = C_nil;
    LispObject b = nil;
    while (consp(a))
    {   LispObject c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return b;
}

//
//  Environments are represented as association lists, and have to cope
// with several sorts of things.  The items in an environment can be
// in one of the following forms:
//
//  (a)       (symbol  .  value)      normal lexical variable binding
//  (b)       (symbol  .  ~magic~)    given symbol is (locally) special
//  (c)       (0  . tag)              (block tag ...) marker
//  (d)       (1  . (tag ...))        (tagbody ... tag ...) marker
//  (e)       (2  . <anything>)       case (c) or (d) but now invalidated
//  (f)       (def . symbol)          (flet ...) or (macrolet ...) binding,
//                                    where the def is non-atomic.
//
// Format for def in case (f)
//
//  (1)       (funarg env bvl ...)    flet and labels
//  (2)       (bvl ...)               macrolet
//                                    Note that 'funarg is not valid as a bvl
//                                    and indeed in this case bvl is a list
//

//
// In CSL mode flet, macrolet and local declarations are not supported.
//

LispObject Ceval(LispObject u, LispObject env)
{   LispObject nil = C_nil;
#ifdef COMMON
    int t;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__)) return aerror("deep stack in eval");
#endif
restart:
    t = (int)u & TAG_BITS;
//
// The first case considered is of symbols - lexical and special bindings
// have to be sorted out.
//
    if (t == TAG_SYMBOL)
    {   Header h = qheader(u);
        debug_record_symbol(u);
        if (h & SYM_SPECIAL_VAR)
        {   LispObject v = qvalue(u);
            if (v == unset_var) return error(1, err_unset_var, u);
            else return onevalue(v);
        }
        else
        {   while (env != nil)
            {   LispObject p = qcar(env);
                if (qcar(p) == u)
                {   LispObject v =qcdr(p);
//
// If a variable is lexically bound to the value work_symbol that means
// that the symbol has been (lexically) declared to be special, so its
// value cell should be inspected.
//
                    if (v == work_symbol)
                    {   v = qvalue(u);
                        if (v == unset_var) return error(1, err_unset_var, u);
                    }
                    return onevalue(v);
                }
                env = qcdr(env);
            }
            {   LispObject v = qvalue(u);
                if (v == unset_var) return error(1, err_unset_var, u);
                else return onevalue(v);
            }
        }
    }
//
// Things that are neither symbols nor lists evaluate to themselves,
// e.g. numbers and vectors.
//
    else if (t != TAG_CONS) return onevalue(u);
    else
#endif // COMMON
    {
//
// The final case is that of a list (fn ...), and one case that has to
// be checked is if fn is lexically bound.
//
        LispObject fn, args;
#ifdef COMMON
//
// The test for nil here is because although nil is a symbol the tagging
// structure tested here marks it as a list.
//
        if (u == nil) return onevalue(nil);
#endif
        stackcheck2(0, u, env);
        fn = qcar(u);
        args = qcdr(u);
#ifdef COMMON
//
// Local function bindings must be looked for first.
//
        {   LispObject p;
            for (p=env; p!=nil; p=qcdr(p))
            {   LispObject w = qcar(p);
//
// The form (<list> . sym) is used in an environment to indicate a local
// binding of a function, either as a regular function or as a macro
// (i.e. flet or macrolet).  The structure of the list distinguishes
// between these two cases.
//
                if (qcdr(w) == fn && is_cons(w = qcar(w)) && w!=nil)
                {   p = qcar(w);
                    if (p == funarg) // ordinary function
                    {   fn = w;      // (funarg ...) is OK to apply
                        goto ordinary_function;
                    }
//
// Here it is a local macro. Observe that the macroexpansion is done
// with respect to an empty environment.  Macros that are defined at the same
// time may seem to be mutually recursive but there is a sense in which they
// are not (as well as a sense in which they are) - self and cross references
// only happen AFTER an expansion and can not happen during one.
//
                    push2(u, env);
                    w = cons(lambda, w);
                    nil = C_nil;
                    if (!exception_pending())
                        p = Lfuncalln(nil, 4, qvalue(macroexpand_hook),
                                      w, u, nil);
                    pop2(env, u);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        if (SHOW_FNAME)
                        {   err_printf("\nMacroexpanding: ");
                            loop_print_error(u);
                            nil = C_nil;
                            if (exception_pending()) flip_exception();
                        }
                        flip_exception();
                        return nil;
                    }
                    u = p;
                    goto restart;
                }
            }
        }
#endif
        if (is_symbol(fn))
        {
//
// Special forms and macros are checked for next.  Special forms
// take precedence over macros.
//
            Header h = qheader(fn);
            debug_record_symbol(fn);
            if (h & SYM_SPECIAL_FORM)
            {
#ifdef DEBUG
                if (qfn1(fn) == NULL)
                {   term_printf("Illegal special form\n");
                    my_exit(EXIT_FAILURE);
                }
#endif
                return ((Special_Form *)qfn1(fn))(args, env);
            }
            else if (h & SYM_MACRO)
            {   push2(u, env);
//
// the environment passed to macroexpand should only be needed to cope
// with macrolet, I think.  Since I use just one datastructure for the
// whole environment I also pass along lexical bindings etc, but I hope that
// they will never be accessed.  I do not think that macrolet is important
// enough to call for complication and slow-down in the interpreter this
// way - but then I am not exactly what you would call a Common Lisp Fan!
//
                debug_record("About to expand a macro");
                fn = macroexpand(u, env);
                debug_record("macro expanded");
                pop2(env, u);
                nil = C_nil;
                if (exception_pending())
                {   flip_exception();
                    if (SHOW_FNAME)
                    {   err_printf("\nMacroexpanding: ");
                        loop_print_error(u);
                        nil = C_nil;
                        if (exception_pending()) flip_exception();
                    }
                    flip_exception();
                    return nil;
                }
                return eval(fn, env);
            }
        }
//
// Otherwise we have a regular function call.  I prepare the args and
// call APPLY.
//
#ifdef COMMON
    ordinary_function:
#endif
        {   int nargs = 0;
            LispObject *save_stack = stack;
//
// Args are built up on the stack here...
//
            while (consp(args))
            {   LispObject w;
                push3(fn, args, env);
                w = qcar(args);
                w = eval(w, env);
                pop3(env, args, fn);
//
// nil having its mark bit set indicates that a special sort of exit
// is in progress.  Multiple values can be ignored in this case.
//
                nil = C_nil;
                if (exception_pending())
                {   flip_exception();
                    stack = save_stack;
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(qcar(args));
                        nil = C_nil;
                        if (exception_pending()) flip_exception();
                    }
                    flip_exception();
                    return nil;
                }
                push(w);        // args build up on the Lisp stack
                nargs++;
                args = qcdr(args);
            }

//
// I pass the environment down to apply() because it will be used if the
// function was a simple lambda expression.  If the function is a symbol
// or a closure, env will be irrelevant.  The arguments are on the Lisp
// stack, and it is the responsibility of apply() to pop them.
//
#ifndef NO_BYTECOUNT
            name_of_caller = "eval";
#endif
            return apply(fn, nargs, env, fn, 0);
        }
    }
}

LispObject noisy_Ceval(LispObject u, LispObject env)
{   LispObject nil = C_nil;
#ifdef COMMON
    int t;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__)) return aerror("deep stack in eval");
#endif
restart:
    t = (int)u & TAG_BITS;
//
// The first case considered is of symbols - lexical and special bindings
// have to be sorted out.
//
    if (t == TAG_SYMBOL)
    {   Header h = qheader(u);
        if (h & SYM_SPECIAL_VAR)
        {   LispObject v = qvalue(u);
            if (v == unset_var) return error(1, err_unset_var, u);
            else return onevalue(v);
        }
        else
        {   while (env != nil)
            {   LispObject p = qcar(env);
                if (qcar(p) == u)
                {   LispObject v =qcdr(p);
//
// If a variable is lexically bound to the value work_symbol that means
// that the symbol has been (lexically) declared to be special, so its
// value cell should be inspected.
//
                    if (v == work_symbol)
                    {   v = qvalue(u);
                        if (v == unset_var) return error(1, err_unset_var, u);
                    }
                    return onevalue(v);
                }
                env = qcdr(env);
            }
            {   LispObject v = qvalue(u);
                if (v == unset_var) return error(1, err_unset_var, u);
                else return onevalue(v);
            }
        }
    }
//
// Things that are neither symbols nor lists evaluate to themselves,
// e.g. numbers and vectors.
//
    else if (t != TAG_CONS) return onevalue(u);
    else
#endif // COMMON
    {
//
// The final case is that of a list (fn ...), and one case that has to
// be checked is if fn is lexically bound.
//
        LispObject fn, args;
#ifdef COMMON
//
// The test for nil here is because although nil is a symbol the tagging
// structure tested here marks it as a list.
//
        if (u == nil) return onevalue(nil);
#endif
        stackcheck2(0, u, env);
        fn = qcar(u);
        args = qcdr(u);
#ifdef COMMON
//
// Local function bindings must be looked for first.
//
        {   LispObject p;
            for (p=env; p!=nil; p=qcdr(p))
            {   LispObject w = qcar(p);
//
// The form (<list> . sym) is used in an environment to indicate a local
// binding of a function, either as a regular function or as a macro
// (i.e. flet or macrolet).  The structure of the list distinguishes
// between these two cases.
//
                if (qcdr(w) == fn && is_cons(w = qcar(w)) && w!=nil)
                {   p = qcar(w);
                    if (p == funarg) // ordinary function
                    {   fn = w;      // (funarg ...) is OK to apply
                        goto ordinary_function;
                    }
//
// Here it is a local macro. Observe that the macroexpansion is done
// with respect to an empty environment.  Macros that are defined at the same
// time may seem to be mutually recursive but there is a sense in which they
// are not (as well as a sense in which they are) - self and cross references
// only happen AFTER an expansion and can not happen during one.
//
                    push2(u, env);
                    w = cons(lambda, w);
                    nil = C_nil;
                    if (!exception_pending())
                        p = Lfuncalln(nil, 4, qvalue(macroexpand_hook),
                                      w, u, nil);
                    pop2(env, u);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        if (SHOW_FNAME)
                        {   err_printf("\nMacroexpanding: ");
                            loop_print_error(u);
                            nil = C_nil;
                            if (exception_pending()) flip_exception();
                        }
                        flip_exception();
                        return nil;
                    }
                    u = p;
                    goto restart;
                }
            }
        }
#endif
        if (is_symbol(fn))
        {
//
// Special forms and macros are checked for next.  Special forms
// take precedence over macros.
//
            Header h = qheader(fn);
            if (h & SYM_SPECIAL_FORM)
            {
#ifdef DEBUG
                if (qfn1(fn) == NULL)
                {   term_printf("Illegal special form\n");
                    my_exit(EXIT_FAILURE);
                }
#endif
//
// The fact that I use the special form's handler function from the
// qfn2 cell arranges to pass down that fact that I am "noisy", ie dealing
// with tracesetq.
//
                return ((Special_Form *)qfn2(fn))(args, env);
            }
            else if (h & SYM_MACRO)
            {   push2(u, env);
//
// the environment passed to macroexpand should only be needed to cope
// with macrolet, I think.  Since I use just one datastructure for the
// whole environment I also pass along lexical bindings etc, but I hope that
// they will never be accessed.  I do not think that macrolet is important
// enough to call for complication and slow-down in the interpreter this
// way - but then I am not exactly what you would call a Common Lisp Fan!
//
                fn = macroexpand(u, env);
                pop2(env, u);
                nil = C_nil;
                if (exception_pending())
                {   flip_exception();
                    if (SHOW_FNAME)
                    {   err_printf("\nMacroexpanding: ");
                        loop_print_error(u);
                        nil = C_nil;
                        if (exception_pending()) flip_exception();
                    }
                    flip_exception();
                    return nil;
                }
                return noisy_eval(fn, env);
            }
        }
//
// Otherwise we have a regular function call.  I prepare the args and
// call APPLY.
//
#ifdef COMMON
    ordinary_function:
#endif
        {   int nargs = 0;
            LispObject *save_stack = stack;
//
// Args are built up on the stack here...
//
            while (consp(args))
            {   LispObject w;
                push3(fn, args, env);
                w = qcar(args);
                w = noisy_eval(w, env);
                pop3(env, args, fn);
//
// nil having its mark bit set indicates that a special sort of exit
// is in progress.  Multiple values can be ignored in this case.
//
                nil = C_nil;
                if (exception_pending())
                {   flip_exception();
                    stack = save_stack;
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(qcar(args));
                        nil = C_nil;
                        if (exception_pending()) flip_exception();
                    }
                    flip_exception();
                    return nil;
                }
                push(w);        // args build up on the Lisp stack
                nargs++;
                args = qcdr(args);
            }

//
// I pass the environment down to apply() because it will be used if the
// function was a simple lambda expression.  If the function is a symbol
// or a closure, env will be irrelevant.  The arguments are on the Lisp
// stack, and it is the responsibility of apply() to pop them. There may
// be a question here about traceset and
//   ((lambda (x) ... (setq ...) ...) ARG)
// where I think that the setq will not be traced. If I needed to deal
// with that I would need a noisy_apply such that tracesetq context was
// preserved into the application of visible lambda expressions.
//
#ifndef NO_BYTECOUNT
            name_of_caller = "eval";
#endif
            return apply(fn, nargs, env, fn, 1);
        }
    }
}

#ifdef COMMON
//
// Keyword arguments are not supported in CSL mode - but &optional
// and &rest and &aux will be (at least for now).  Removal of
// support for keywords will save a little space and an even smaller
// amount of time.
//

static bool check_no_unwanted_keys(LispObject restarg, LispObject ok_keys)
//
// verify that there were no unwanted keys in the actual arg list
//
{   LispObject nil = C_nil;
    bool odd_key_found = false;
    while (restarg!=nil)
    {   LispObject k = qcar(restarg);
        LispObject w;
        for (w=ok_keys; w!=nil; w=qcdr(w))
            if (k == qcar(w)) goto is_ok;
        odd_key_found = true;
    is_ok:
        restarg = qcdr(restarg);
        if (restarg==nil) return true;  // odd length list
        if (k == allow_key_key && qcar(restarg) != nil) return false; // OK
        restarg = qcdr(restarg);
    }
    return odd_key_found;
}

static bool check_keyargs_even(LispObject restarg)
//
// check that list is even length with alternate items symbols in
// the keyword package.
//
{   LispObject nil = C_nil;
    while (restarg!=nil)
    {   LispObject q = qcar(restarg);
        if (!is_symbol(q) || qpackage(q) != qvalue(keyword_package)) return true;
        restarg = qcdr(restarg);
        if (restarg==nil) return true;      // Odd length is wrong
        restarg = qcdr(restarg);
    }
    return false;                               // OK
}

static LispObject keywordify(LispObject v)
{
//
// arg is a non-nil symbol.  Should nil be permitted - I think not
// since there seems too much chance of confusion.
//
    LispObject nil, name = get_pname(v);
    errexit();
    return Lintern_2(nil, name, qvalue(keyword_package));
}

static LispObject key_lookup(LispObject keyname, LispObject args)
{   LispObject nil = C_nil;
    while (args!=nil)
    {   LispObject next = qcdr(args);
        if (next==nil) return nil;
        if (qcar(args) == keyname) return next;
        else args = qcdr(next);
    }
    return nil;
}

#endif

LispObject apply_lambda(LispObject def, int nargs,
                        LispObject env, LispObject name, int noisy)
//
// Here def is a lambda expression (sans the initial lambda) that is to
// be applied.  Much horrible messing about is needed so that I can cope
// with &optional and &rest args (including initialisers and supplied-p
// variables, also &key, &allow-other-keys and &aux).  Note the need to find
// any special declarations at the head of the body of the lambda-form.
// Must pop (nargs) items from the stack at exit.
//
{
//
// lambda-lists are parsed using a finite state engine with the
// following states, plus an exit state.
//
#define STATE_NULL     0        // at start and during regular args
#define STATE_OPT      1        // after &optional
#define STATE_OPT1     2        // after &optional + at least one var
#define STATE_REST     3        // immediately after &rest
#define STATE_REST1    4        // after &rest vv
#define STATE_KEY      5        // &key with no &rest
#define STATE_ALLOW    6        // &allow-other-keys
#define STATE_AUX      7        // &aux

    LispObject nil = C_nil;
    int opt_rest_state = STATE_NULL;
    LispObject *next_arg;
    int args_left = nargs;
    LispObject w;
    if (!consp(def))
    {   popv(nargs);
        return onevalue(nil);    // Should never happen
    }
    stackcheck3(0, def, env, name);
    w = qcar(def);
    next_arg = &stack[1-nargs];         // Points to arg1
    push4(w,                            // bvl
          qcdr(def),                    // body
          env, name);
//
// Here I need to macroexpand the first few items in body and
// look for declare/special items.  I will only bother with SPECIAL decls.
// Note that args have been pushed onto the stack first to avoid corruption
// while the interpreter performs macroexpansion.  This is the sort of place
// where I feel that Common Lisp has built in causes of inefficiency.
// Well oh well!!! The Common Lisp standardisation group thought so too,
// and have now indicated that DECLARE forms can not be hidden away as
// the result of macros, so some of this is unnecessary.
//
    push5(nil, nil,                  // local_decs, ok_keys
          nil, nil, nil);            // restarg, specenv, val1
    push5(nil, nil,                  // arg, v1
          nil, nil, nil);            // v, p, w
//
// On computers which have unsigned offsets in indexed memory reference
// instructions the negative indexes off the stack suggested here might
// be more expensive than I would like - maybe on such machines the stack
// pointer should be kept offset by 64 bytes (say).  Doing so in general
// would be to the disadvantage of machines with auto-index address modes
// that might be used when pushing/popping single items on the stack.
//
#define w           stack[0]
#define p           stack[-1]
#define v           stack[-2]
#define v1          stack[-3]
#define arg         stack[-4]
#define val1        stack[-5]
#define specenv     stack[-6]
#define restarg     stack[-7]
#ifdef COMMON
#define ok_keys     stack[-8]
#define local_decs  stack[-9]
#endif
#define name        stack[-10]
#define env         stack[-11]
#define body        stack[-12]
#define bvl         stack[-13]
#define arg1        stack[-14]
#define stack_used ((int)(nargs + 14))

#ifdef COMMON
    for (;;)
    {   if (!consp(body)) break;
        p = macroexpand(qcar(body), env);
        nil = C_nil;
        if (exception_pending())
        {   LispObject qname = name;
            popv(stack_used);
            return qname;
        }
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
        for (v = qcdr(v); consp(v); v = qcdr(v))
        {   v1 = qcar(v);
            if (!consp(v1) || qcar(v1) != special_symbol) continue;
            // here v1 says (special ...)
            for (v1=qcdr(v1); consp(v1); v1 = qcdr(v1))
            {   local_decs = cons(qcar(v1), local_decs);
                if (exception_pending()) break;
            }
        }
    }
    nil = C_nil;
    if (exception_pending())
    {   LispObject qname = name;
        popv(stack_used);
        return qname;
    }
#endif
//
// Parse the BVL
//
    for (p = bvl; consp(p); p=qcdr(p))
    {   v = qcar(p);
        v1 = nil;
        arg = nil;
        val1 = nil;
//
// I can break from this switch statement with v a variable to bind
// and arg the value to bind to it, also v1 (if not nil) is a second
// variable to be bound (a supplied-p value) and val1 the value to bind it to.
// If I see &rest or &key the remaining actual args get collected into
// restarg, which takes the place of arg in some respects.
//
        switch (opt_rest_state)
        {

            case STATE_NULL:
                if (v == opt_key)
                {   opt_rest_state = STATE_OPT;
                    continue;
                }

#define BAD1(msg)    { error(0, msg);    goto unwind_special_bindings; }
#define BAD2(msg, a) { error(1, msg, a); goto unwind_special_bindings; }

#define collect_rest_arg()                                  \
    while (args_left-- != 0)                                \
    {   if (!exception_pending())                           \
            restarg = cons(next_arg[args_left], restarg);   \
        nil = C_nil;                                        \
    }

                if (v == rest_key)
                {   collect_rest_arg();
                    if (exception_pending()) goto unwind_special_bindings;
                    opt_rest_state = STATE_REST;
                    continue;
                }
#ifdef COMMON
                if (v == key_key)
                {   collect_rest_arg();
                    if (exception_pending()) goto unwind_special_bindings;
                    if (check_keyargs_even(restarg)) BAD2(err_bad_keyargs, restarg);
                    opt_rest_state = STATE_KEY;
                    continue;
                }

                if (v == aux_key)
                {   if (args_left != 0) BAD1(err_excess_args);
                    opt_rest_state = STATE_AUX;
                    continue;
                }
                if (v == allow_other_keys) BAD2(err_bad_bvl, v);
#endif
                if (args_left == 0) BAD1(err_insufficient_args);
                arg = *next_arg++;
                args_left--;
                v1 = nil;       // no suppliedp mess here, I'm glad to say
                break;

            case STATE_OPT:
                if (v == opt_key
                    || v == rest_key
#ifdef COMMON
                    || v == key_key
                    || v == allow_other_keys
                    || v == aux_key
#endif
                   ) BAD2(err_bad_bvl, v);
//
// Here v may be a simple variable, or a list (var init suppliedp)
//
                opt_rest_state = STATE_OPT1;
            process_optional_parameter:
                if (args_left != 0)
                {   arg = *next_arg++;
                    args_left--;
                    val1 = lisp_true;
                }
                else
                {   arg = nil;
                    val1 = nil;
                }
                v1 = nil;
                if (!consp(v)) break;       // Simple case
                {   w = qcdr(v);
                    v = qcar(v);
                    if (!consp(w)) break;   // (var)
                    if (val1 == nil)        // use the init form
                    {   arg = qcar(w);
                        arg = eval(arg, env);
                        nil = C_nil;
                        if (exception_pending()) goto unwind_special_bindings;
                    }
                    w = qcdr(w);
                    if (consp(w)) v1 = qcar(w); // suppliedp name
                    break;
                }

            case STATE_OPT1:
                if (v == rest_key)
                {   collect_rest_arg();
                    if (exception_pending()) goto unwind_special_bindings;
                    opt_rest_state = STATE_REST;
                    continue;
                }
#ifdef COMMON
                if (v == key_key)
                {   collect_rest_arg();
                    if (exception_pending()) goto unwind_special_bindings;
                    if (check_keyargs_even(restarg)) BAD2(err_bad_keyargs, restarg);
                    opt_rest_state = STATE_KEY;
                    continue;
                }
                if (v == aux_key)
                {   if (args_left != 0) BAD1(err_excess_args);
                    opt_rest_state = STATE_AUX;
                    continue;
                }
#endif
                if (v == opt_key
#ifdef COMMON
                    || v == allow_other_keys
#endif
                   ) BAD2(err_bad_bvl, v);
                goto process_optional_parameter;

            case STATE_REST:
                if (v == opt_key
                    || v == rest_key
#ifdef COMMON
                    || v == key_key
                    || v == allow_other_keys
                    || v == aux_key
#endif
                   ) BAD2(err_bad_bvl, v);
                opt_rest_state = STATE_REST1;
                arg = restarg;
                break;

            case STATE_REST1:
#ifdef COMMON
                if (v == key_key)
                {   if (check_keyargs_even(restarg)) BAD2(err_bad_keyargs, restarg);
                    opt_rest_state = STATE_KEY;
                    continue;
                }
                if (v == aux_key)
                {   opt_rest_state = STATE_AUX;
                    continue;
                }
#endif
                BAD2(err_bad_bvl, rest_key);

#ifdef COMMON
            case STATE_KEY:
                if (v == allow_other_keys)
                {   opt_rest_state = STATE_ALLOW;
                    continue;
                }
                if (v == aux_key)
                {   if (check_no_unwanted_keys(restarg, ok_keys))
                        BAD2(err_bad_keyargs, restarg);
                    opt_rest_state = STATE_AUX;
                    continue;
                }
                if (v == opt_key || v == rest_key || v == key_key)
                    BAD2(err_bad_bvl, v);
            process_keyword_parameter:
//
// v needs to expand to ((:kv v) init svar) in effect here.
//
                {   LispObject keyname = nil;
                    w = nil;
                    if (!consp(v))
                    {   if (!is_symbol(v) || v==nil || v==lisp_true)
                            BAD2(err_bad_bvl, v);
                        keyname = keywordify(v);
                    }
                    else
                    {   w = qcdr(v);
                        v = qcar(v);
                        if (!consp(v))
                        {   if (!is_symbol(v) || v==nil || v==lisp_true)
                                BAD2(err_bad_bvl, v);
                            keyname = keywordify(v);
                            nil = C_nil;
                            if (exception_pending()) goto unwind_special_bindings;
                        }
                        else
                        {   keyname = qcar(v);
                            if (!is_symbol(keyname) || v==nil || v ==lisp_true)
                                BAD2(err_bad_bvl, v);
                            keyname = keywordify(keyname);
                            nil = C_nil;
                            if (exception_pending()) goto unwind_special_bindings;
                            v = qcdr(v);
                            if (consp(v)) v = qcar(v);
                            else BAD2(err_bad_bvl, v);
                        }
                    }
                    ok_keys = cons(keyname, ok_keys);
                    nil = C_nil;
                    if (exception_pending()) goto unwind_special_bindings;
                    arg = key_lookup(qcar(ok_keys), restarg);
                    if (arg == nil) val1 = nil;
                    else
                    {   arg = qcar(arg);
                        val1 = lisp_true;
                    }
                    v1 = nil;
                    if (!consp(w)) break;   // (var)
                    if (val1 == nil)        // use the init form
                    {   arg = qcar(w);
                        arg = eval(arg, env);
                        nil = C_nil;
                        if (exception_pending()) goto unwind_special_bindings;
                    }
                    w = qcdr(w);
                    if (consp(w)) v1 = qcar(w); // suppliedp name
                    break;
                }

            case STATE_ALLOW:
                if (v == aux_key)
                {   opt_rest_state = STATE_AUX;
                    continue;
                }
                if (v == opt_key || v == rest_key || v == key_key ||
                    v == allow_other_keys) BAD2(err_bad_bvl, v);
                goto process_keyword_parameter;

            case STATE_AUX:
                if (v == opt_key || v == rest_key ||
                    v == key_key || v == allow_other_keys ||
                    v == aux_key) BAD2(err_bad_bvl, v);
                if (consp(v))
                {   w = qcdr(v);
                    v = qcar(v);
                    if (consp(w))
                    {   arg = qcar(w);
                        arg = eval(arg, env);
                        nil = C_nil;
                        if (exception_pending()) goto unwind_special_bindings;
                    }
                }
                else arg = nil;
                v1 = nil;
                break;
#endif
        }
//
// This is where I get when I have one or two vars to bind.
//

#ifndef COMMON
//
// CSL mode does not have to mess about looking for local special bindings
// and so is MUCH shorter and neater. I always shallow bind
//
#define instate_binding(var, val, local_decs1, lab)                     \
        {   if (!is_symbol(var) || var==nil || var==lisp_true)       \
                BAD2(err_bad_bvl, var);                                 \
            w = acons(var, qvalue(var), specenv);                       \
            nil = C_nil;                                                \
            if (exception_pending()) goto unwind_special_bindings;      \
            specenv = w;                                                \
            qvalue(var) = val;                                          \
        }
#else
#define instate_binding(var, val, local_decs1, lab)                     \
        {   Header h;                                                   \
            if (!is_symbol(var) || var==nil || var==lisp_true)          \
                BAD2(err_bad_bvl, var);                                 \
            h = qheader(var);                                           \
            if ((h & SYM_SPECIAL_VAR) != 0)                             \
            {   w = acons(var, qvalue(var), specenv);                   \
                nil = C_nil;                                            \
                if (exception_pending()) goto unwind_special_bindings;  \
                specenv = w;                                            \
                qvalue(var) = val;                                      \
            }                                                           \
            else                                                        \
            {   for (w = local_decs1; w!=nil; w = qcdr(w))              \
                {   if (qcar(w) == var)                                 \
                    {   qcar(w) = fixnum_of_int(0);/* decl is used up */\
                        w = acons(var, work_symbol, env);               \
                        nil = C_nil;                                    \
                        if (exception_pending())                        \
                            goto unwind_special_bindings;               \
                        env = w;                                        \
                        w = acons(var, qvalue(var), specenv);           \
                        nil = C_nil;                                    \
                        if (exception_pending())                        \
                            goto unwind_special_bindings;               \
                        specenv = w;                                    \
                        qvalue(var) = val;                              \
                        goto lab;                                       \
                    }                                                   \
                }                                                       \
                w = acons(var, val, env);                               \
                nil = C_nil;                                            \
                if (exception_pending()) goto unwind_special_bindings;  \
                env = w;                                                \
        lab:    ;                                                       \
            }                                                           \
        }
#endif

#ifdef COMMON
//
// Must check about local special declarations here...
//
#endif
        instate_binding(v, arg, local_decs, label1);
        if (v1 != nil) instate_binding(v1, val1, local_decs, label2);

    }   // End of for loop that scans BVL

#ifdef COMMON
//
// As well as local special declarations that have applied to bindings here
// there can be some that apply just to variable references within the body.
//
    while (local_decs!=nil)
    {   LispObject q = qcar(local_decs);
        local_decs=qcdr(local_decs);
        if (!is_symbol(q)) continue;
        w = acons(q, work_symbol, env);
        nil = C_nil;
        if (exception_pending()) goto unwind_special_bindings;
        env = w;
    }
#endif

    switch (opt_rest_state)
    {   case STATE_NULL:
        case STATE_OPT1:        // Ensure there had not been too many args
            if (args_left != 0) BAD1(err_excess_args);
            break;

        case STATE_OPT:         // error if bvl finishes here
        case STATE_REST:
            BAD2(err_bad_bvl, opt_rest_state == STATE_OPT ? opt_key : rest_key);

#ifdef COMMON
        case STATE_KEY:         // ensure only valid keys were given
            if (check_no_unwanted_keys(restarg, ok_keys))
                BAD2(err_bad_keyargs, restarg);
            break;
#endif

        default:
//                             in the following cases all is known to be well
//case STATE_REST1:
//case STATE_ALLOW:
//case STATE_AUX:
//
            break;
    }

//
// Now all the argument bindings have been performed - it remains to
// process the body of the lambda-expression.
//
    if (specenv == nil)
    {   LispObject bodyx = body, envx = env;
        LispObject qname = name;
        popv(stack_used);
        push(qname);
        bodyx = noisy ? noisy_progn_fn(bodyx, envx) : progn_fn(bodyx, envx);
        pop(qname);
        nil = C_nil;
        if (exception_pending()) return qname;
        return bodyx;
    }
    {   exit_count = 1;
        body = noisy ? noisy_progn_fn(body, env) : progn_fn(body, env);
        nil = C_nil;
        if (exception_pending()) goto unwind_special_bindings;
        while (specenv != nil)
        {   LispObject bv = qcar(specenv);
            qvalue(qcar(bv)) = qcdr(bv);
            specenv = qcdr(specenv);
        }
        {   LispObject bodyx = body;
            popv(stack_used);
//
// note that exit_count has not been disturbed since I called progn_fn,
// so the number of values that will be returned remains correctly
// established.
//
            return bodyx;
        }
    }

unwind_special_bindings:
//
// I gete here ONLY if nil has its mark bit set, which means that (for
// one reason or another) I am having to unwind the stack, restoring
// special bindings as I go.
//
    nil = C_nil;
    flip_exception();
    while (specenv != nil)
    {   LispObject bv = qcar(specenv);
        qvalue(qcar(bv)) = qcdr(bv);
        specenv = qcdr(specenv);
    }
    flip_exception();
    {   LispObject qname = name;
        popv(stack_used);
        return qname;
    }
#undef w
#undef p
#undef v
#undef v1
#undef arg
#undef val1
#undef specenv
#undef restarg
#undef ok_keys
#undef local_decs
#undef name
#undef env
#undef body
#undef bvl
#undef stack_used
}

LispObject Leval(LispObject nil, LispObject a)
{   return eval(a, nil);     // Multiple values may be returned
}

LispObject Levlis(LispObject nil, LispObject a)
{   LispObject r;
    stackcheck1(0, a);
    r = nil;
    while (consp(a))
    {   push2(qcdr(a), r);
        a = qcar(a);
        a = eval(a, nil);
        errexitn(2);
        pop(r);
        r = cons(a, r);
        pop(a);
        errexit();
    }
    return onevalue(nreverse(r));
}

LispObject Lapply_n(LispObject nil, int nargs, ...)
{   va_list a;
    int i;
    LispObject *stack_save = stack, last, fn = nil;
    if (nargs == 0) return aerror("apply");
    else if (nargs > 1)
    {   va_start(a, nargs);
        fn = va_arg(a, LispObject);
        push_args_1(a, nargs);
        pop(last);
        i = nargs-2;
        while (consp(last))
        {   push(qcar(last));
            last = qcdr(last);
            i++;
        }
    }
    else i = 0;
    stackcheck1(stack-stack_save, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, i, nil, fn, 0);
}

LispObject Lapply_1(LispObject nil, LispObject fn)
{   return Lapply_n(nil, 1, fn);
}

LispObject Lapply_2(LispObject nil, LispObject fn, LispObject a1)
{   return Lapply_n(nil, 2, fn, a1);
}

LispObject Lapply0(LispObject nil, LispObject fn)
{
#ifndef DEBUG
// I avoid this optimisation if debugging...
    if (is_symbol(fn)) return (*qfnn(fn))(qenv(fn), 0);
#endif
    stackcheck1(0, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, 0, C_nil, fn, 0);
}

LispObject Lapply1(LispObject nil, LispObject fn, LispObject a)
{
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfn1(fn))(qenv(fn), a);
#endif
    push(a);
    stackcheck1(1, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, 1, C_nil, fn, 0);
}

LispObject Lapply2(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject fn, a, b;
    argcheck(nargs, 3, "apply2");
    va_start(aa, nargs);
    fn = va_arg(aa, LispObject);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    va_end(aa);
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfn2(fn))(qenv(fn), a, b);
#endif
    push2(a, b);
    stackcheck1(2, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, 2, C_nil, fn, 0);
}

LispObject Lapply3(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject fn, a, b, c;
    argcheck(nargs, 4, "apply3");
    va_start(aa, nargs);
    fn = va_arg(aa, LispObject);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfnn(fn))(qenv(fn), 3, a, b, c);
#endif
    push3(a, b, c);
    stackcheck1(3, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, 3, C_nil, fn, 0);
}

LispObject Lfuncall1(LispObject nil, LispObject fn)
{
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfnn(fn))(qenv(fn), 0);
#endif
    stackcheck1(0, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "funcall";
#endif
    return apply(fn, 0, nil, fn, 0);
}

LispObject Lfuncall2(LispObject nil, LispObject fn, LispObject a1)
{
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfn1(fn))(qenv(fn), a1);
#endif
    push(a1);
    stackcheck1(1, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "funcall";
#endif
    return apply(fn, 1, nil, fn, 0);
}

static LispObject Lfuncalln_sub(LispObject nil, int nargs, va_list a)
{   LispObject *stack_save = stack, fn;
    fn = va_arg(a, LispObject);
    push_args_1(a, nargs);
    stackcheck1(stack-stack_save, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "funcall";
#endif
    return apply(fn, nargs-1, nil, fn, 0);
}

LispObject Lfuncalln(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject fn, a1, a2, a3, a4;
    va_start(a, nargs);
    switch (nargs)
    {   case 0: return aerror("funcall");
        case 1: // cases 1 and 2 should go through Lfuncall1,2 not here
        case 2: return aerror("funcall wrong call");
        case 3: fn = va_arg(a, LispObject);
            a1 = va_arg(a, LispObject);
            a2 = va_arg(a, LispObject);
#ifndef DEBUG
            if (is_symbol(fn)) return (*qfn2(fn))(qenv(fn), a1, a2);
#endif
            push2(a1, a2);
#ifndef NO_BYTECOUNT
            name_of_caller = "funcall";
#endif
            return apply(fn, 2, nil, fn, 0);
        case 4: fn = va_arg(a, LispObject);
            a1 = va_arg(a, LispObject);
            a2 = va_arg(a, LispObject);
            a3 = va_arg(a, LispObject);
#ifndef DEBUG
            if (is_symbol(fn)) return (*qfnn(fn))(qenv(fn), 3, a1, a2, a3);
#endif
            push3(a1, a2, a3);
#ifndef NO_BYTECOUNT
            name_of_caller = "funcall";
#endif
            return apply(fn, 3, nil, fn, 0);
        case 5: fn = va_arg(a, LispObject);
            a1 = va_arg(a, LispObject);
            a2 = va_arg(a, LispObject);
            a3 = va_arg(a, LispObject);
            a4 = va_arg(a, LispObject);
#ifndef DEBUG
            if (is_symbol(fn)) return (*qfnn(fn))(qenv(fn), 4, a1, a2, a3, a4);
#endif
            push4(a1, a2, a3, a4);
#ifndef NO_BYTECOUNT
            name_of_caller = "funcall";
#endif
            return apply(fn, 4, nil, fn, 0);
        default:
            return Lfuncalln_sub(nil, nargs, a);
    }
}

#ifdef COMMON

LispObject Lvalues(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject *p = &mv_2, w;
    int i;
//
// Because multiple-values get passed back in static storage there is
// a fixed upper limit to how many I can handle - truncate here to allow
// for that.
//
    if (nargs > 50) nargs = 50;
    if (nargs == 0) return nvalues(nil, 0);
    va_start(a, nargs);
    push_args(a, nargs);
    for (i=1; i<nargs; i++)
    {   pop(w);
        p[nargs-i-1] = w;
    }
    pop(w);
    return nvalues(w, nargs);
}

LispObject Lvalues_2(LispObject nil, LispObject a, LispObject b)
{   return Lvalues(nil, 2, a, b);
}

LispObject Lvalues_1(LispObject nil, LispObject a)
{   return Lvalues(nil, 1, a);
}

LispObject mv_call_fn(LispObject args, LispObject env)
//
// here with the rest of the interpreter rather than in specforms.c
//
{   LispObject nil = C_nil;
    LispObject fn, *stack_save = stack;
    int i=0, j=0;
    if (!consp(args)) return nil;       // (multiple-value-call) => nil
    stackcheck2(0, args, env);
    push2(args, env);
    fn = qcar(args);
    fn = eval(fn, env);
    pop2(env, args);
    errexit();
    args = qcdr(args);
    while (consp(args))
    {   LispObject r1;
        push2(args, env);
        r1 = qcar(args);
        exit_count = 1;
        r1  = eval(r1, env);
        nil = C_nil;
        if (exception_pending())
        {   stack = stack_save;
            return nil;
        }
//
// It is critical here that push does not check for stack overflow and
// thus can not call the garbage collector, or otherwise lead to calculation
// that could possibly clobber the multiple results that I am working with
// here.
//
        pop2(env, args);
        push(r1);
        i++;
        for (j = 2; j<=exit_count; j++)
        {   push((&work_0)[j]);
            i++;
        }
        args = qcdr(args);
    }
    stackcheck2(stack-stack_save, fn, env);
#ifndef NO_BYTECOUNT
    name_of_caller = "mv-call";
#endif
    return apply(fn, i, env, fn, 0);
}

#endif

LispObject interpreted1(LispObject def, LispObject a1)
{   LispObject nil = C_nil;
    push(a1);
    stackcheck1(1, def);
    return apply_lambda(def, 1, nil, def, 0);
}

LispObject interpreted2(LispObject def, LispObject a1, LispObject a2)
{   LispObject nil = C_nil;
    push2(a1, a2);
    stackcheck1(2, def);
    return apply_lambda(def, 2, nil, def, 0);
}

LispObject interpretedn(LispObject def, int nargs, ...)
{
//
// The messing about here is to get the (unknown number of) args
// into a nice neat vector so that they can be indexed into. If I knew
// that the args were in consecutive locations on the stack I could
// probably save a copying operation.
//
    LispObject nil = C_nil;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    return apply_lambda(def, nargs, nil, def, 0);
}

LispObject funarged1(LispObject def, LispObject a1)
{   LispObject nil = C_nil;
    push(a1);
    stackcheck1(1, def);
    return apply_lambda(qcdr(def), 1, qcar(def), qcdr(def), 0);
}

LispObject funarged2(LispObject def, LispObject a1, LispObject a2)
{   LispObject nil = C_nil;
    push2(a1, a2);
    stackcheck1(2, def);
    return apply_lambda(qcdr(def), 2, qcar(def), qcdr(def), 0);
}

LispObject funargedn(LispObject def, int nargs, ...)
{   LispObject nil = C_nil;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    return apply_lambda(qcdr(def), nargs, qcar(def), qcdr(def), 0);
}

//
// Now some execution-doubling versions...
//

LispObject double_interpreted1(LispObject def, LispObject a1)
{   LispObject nil = C_nil;
    push(a1);
    stackcheck1(1, def);
    return apply_lambda(def, 1, nil, def, 0);
}

LispObject double_interpreted2(LispObject def, LispObject a1, LispObject a2)
{   LispObject nil = C_nil;
    push2(a1, a2);
    stackcheck1(2, def);
    return apply_lambda(def, 2, nil, def, 0);
}

LispObject double_interpretedn(LispObject def, int nargs, ...)
{
//
// The messing about here is to get the (unknown number of) args
// into a nice neat vector so that they can be indexed into. If I knew
// that the args were in consecutive locations on the stack I could
// probably save a copying operation.
//
    LispObject nil = C_nil;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    return apply_lambda(def, nargs, nil, def, 0);
}

LispObject double_funarged1(LispObject def, LispObject a1)
{   LispObject nil = C_nil;
    push(a1);
    stackcheck1(1, def);
    return apply_lambda(qcdr(def), 1, qcar(def), qcdr(def), 0);
}

LispObject double_funarged2(LispObject def, LispObject a1, LispObject a2)
{   LispObject nil = C_nil;
    push2(a1, a2);
    stackcheck1(2, def);
    return apply_lambda(qcdr(def), 2, qcar(def), qcdr(def), 0);
}

LispObject double_funargedn(LispObject def, int nargs, ...)
{   LispObject nil = C_nil;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    return apply_lambda(qcdr(def), nargs, qcar(def), qcdr(def), 0);
}

LispObject traceinterpreted1(LispObject def, LispObject a1)
//
// Like interpreted() but the definition has the fn name consed on the front
//
{   LispObject nil = C_nil, r;
    push(a1);
    stackcheck1(1, def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(qcar(def));
    trace_printf(" (1 arg)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\nArg1: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    r = apply_lambda(qcdr(def), 1, nil, def, 0);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject traceinterpreted2(LispObject def, LispObject a1, LispObject a2)
//
// Like interpreted() but the definition has the fn name consed on the front
//
{   LispObject nil = C_nil, r;
    int i;
    push2(a1, a2);
    stackcheck1(2, def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(qcar(def));
    trace_printf(" (2 args)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    for (i=1; i<=2; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-2]);
        trace_printf("\n");
    }
    r = apply_lambda(qcdr(def), 2, nil, def, 0);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject traceinterpretedn(LispObject def, int nargs, ...)
//
// Like interpreted() but the definition has the fn name consed on the front
//
{   int i;
    LispObject nil = C_nil, r;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(qcar(def));
    trace_printf(" (%d args)", nargs);
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    r = apply_lambda(qcdr(def), nargs, nil, def, 0);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracefunarged1(LispObject def, LispObject a1)
//
// Like funarged() but with some printing
//
{   LispObject nil = C_nil, r;
    push(a1);
    stackcheck1(1, def);
    freshline_trace();
    trace_printf("Entering funarg ");
    loop_print_trace(qcar(def));
    trace_printf(" (1 arg)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = qcdr(def);
    r = apply_lambda(qcdr(def), 1, qcar(def), qcdr(def), 0);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracefunarged2(LispObject def, LispObject a1, LispObject a2)
//
// Like funarged() but with some printing
//
{   LispObject nil = C_nil, r;
    push2(a1, a2);
    stackcheck1(2, def);
    freshline_trace();
    trace_printf("Entering funarg ");
    loop_print_trace(qcar(def));
    trace_printf(" (2 args)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = qcdr(def);
    r = apply_lambda(qcdr(def), 2, qcar(def), qcdr(def), 0);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracefunargedn(LispObject def, int nargs, ...)
//
// Like funarged() but with some printing
//
{   LispObject nil = C_nil, r;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    freshline_trace();
    trace_printf("Entering funarg ");
    loop_print_trace(qcar(def));
    trace_printf(" (%d args)", nargs);
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = qcdr(def);
    r = apply_lambda(qcdr(def), nargs, qcar(def), qcdr(def), 0);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracesetinterpreted1(LispObject def, LispObject a1)
//
// Like interpreted() but the definition has the fn name consed on the front
//
{   LispObject nil = C_nil, r;
    push(a1);
    stackcheck1(1, def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(qcar(def));
    trace_printf(" (1 arg)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\nArg1: ");
    loop_print_trace(stack[0]);
    trace_printf("\n");
    r = apply_lambda(qcdr(def), 1, nil, def, 1);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracesetinterpreted2(LispObject def, LispObject a1, LispObject a2)
//
// Like interpreted() but the definition has the fn name consed on the front
//
{   LispObject nil = C_nil, r;
    int i;
    push2(a1, a2);
    stackcheck1(2, def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(qcar(def));
    trace_printf(" (2 args)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    for (i=1; i<=2; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-2]);
        trace_printf("\n");
    }
    r = apply_lambda(qcdr(def), 2, nil, def, 1);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracesetinterpretedn(LispObject def, int nargs, ...)
//
// Like interpreted() but the definition has the fn name consed on the front
//
{   int i;
    LispObject nil = C_nil, r;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    freshline_trace();
    trace_printf("Entering ");
    loop_print_trace(qcar(def));
    trace_printf(" (%d args)", nargs);
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    for (i=1; i<=nargs; i++)
    {   trace_printf("Arg%d: ", i);
        loop_print_trace(stack[i-nargs]);
        trace_printf("\n");
    }
    r = apply_lambda(qcdr(def), nargs, nil, def, 1);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracesetfunarged1(LispObject def, LispObject a1)
//
// Like funarged() but with some printing
//
{   LispObject nil = C_nil, r;
    push(a1);
    stackcheck1(1, def);
    freshline_trace();
    trace_printf("Entering funarg ");
    loop_print_trace(qcar(def));
    trace_printf(" (1 arg)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = qcdr(def);
    r = apply_lambda(qcdr(def), 1, qcar(def), qcdr(def), 1);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracesetfunarged2(LispObject def, LispObject a1, LispObject a2)
//
// Like funarged() but with some printing
//
{   LispObject nil = C_nil, r;
    push2(a1, a2);
    stackcheck1(2, def);
    freshline_trace();
    trace_printf("Entering funarg ");
    loop_print_trace(qcar(def));
    trace_printf(" (2 args)");
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = qcdr(def);
    r = apply_lambda(qcdr(def), 2, qcar(def), qcdr(def), 1);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

LispObject tracesetfunargedn(LispObject def, int nargs, ...)
//
// Like funarged() but with some printing
//
{   LispObject nil = C_nil, r;
    LispObject *stack_save = stack;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    stackcheck1(stack-stack_save, def);
    freshline_trace();
    trace_printf("Entering funarg ");
    loop_print_trace(qcar(def));
    trace_printf(" (%d args)", nargs);
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = qcdr(def);
    r = apply_lambda(qcdr(def), nargs, qcar(def), qcdr(def), 1);
    errexit();
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

static LispObject macroexpand_1(LispObject form, LispObject env)
{   // The environment here seems only necessary for macrolet
    LispObject done;
    LispObject f, nil;
    nil = C_nil;
    stackcheck2(0, form, env);
    done = nil;
    if (consp(form))
    {   f = qcar(form);
#ifdef COMMON
//
// look for local macro definitions
//
        {   LispObject p;
            for (p=env; p!=nil; p=qcdr(p))
            {   LispObject w = qcar(p);
                if (qcdr(w) == f && is_cons(w = qcar(w)) && w!=nil)
                {   p = qcar(w);
                    if (p == funarg) // ordinary function
                    {   mv_2 = nil;
                        return nvalues(form, 2);
                    }
                    push2(form, done);
                    w = cons(lambda, w);
                    errexitn(1);
                    p = Lfuncalln(nil, 4, qvalue(macroexpand_hook),
                                  w, stack[-1], nil);
                    pop2(done, form);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        if (SHOW_FNAME)
                        {   err_printf("\nMacroexpanding: ");
                            loop_print_error(form);
                            nil = C_nil;
                            if (exception_pending()) flip_exception();
                        }
                        flip_exception();
                        return nil;
                    }
                    mv_2 = lisp_true;
                    return nvalues(p, 2);
                }
            }
        }
//
// If there is no local macro definition I need to look for a global one
//
#endif
        if (symbolp(f) && (qheader(f) & SYM_MACRO) != 0)
        {   done = qvalue(macroexpand_hook);
            if (done == unset_var)
                return error(1, err_macroex_hook, macroexpand_hook);
            push3(form, env, done);
            f = cons(lambda, qenv(f));
            pop3(done, env, form);
            nil = C_nil;
            if (!exception_pending())
            {
#ifndef COMMON
// CSL does not pass an environment down here, so does not demand &opt arg
                form = Lfuncalln(nil, 3, done, f, form);
#else
                form = Lfuncalln(nil, 4, done, f, form, env);
#endif
                nil = C_nil;
            }
            if (exception_pending()) return nil;
            done = lisp_true;
        }
    }
    mv_2 = done;
    return nvalues(form, 2);    // Multiple values handed back
}

LispObject macroexpand(LispObject form, LispObject env)
{   // The environment here seems only necessary for macrolet
    LispObject done, nil;
    nil = C_nil;
    stackcheck2(0, form, env);
    done = nil;
    for (;;)
    {   push2(env, done);
        form = macroexpand_1(form, env);
        pop2(done, env);
        errexit();
        if (mv_2 == nil) break;
        done = lisp_true;
    }
    mv_2 = done;
    return nvalues(form, 2);    // Multiple values handed back
}

LispObject Lmacroexpand(LispObject nil, LispObject a)
{   return macroexpand(a, nil);
}

#ifdef COMMON
LispObject Lmacroexpand_2(LispObject, LispObject a, LispObject b)
{   return macroexpand(a, b);
}
#endif

LispObject Lmacroexpand_1(LispObject nil, LispObject a)
{   return macroexpand_1(a, nil);
}

#ifdef COMMON
LispObject Lmacroexpand_1_2(LispObject, LispObject a, LispObject b)
{   return macroexpand_1(a, b);
}

#endif

//
// To make something autoloadable I should set the environment cell to
//    (name-of-self module-name-1 module-name-2 ...)
// and when invoked the function will do a load-module on each of the
// modules specified and then re-attempt to call.  Loading the
// modules is expected to establish a proper definition for the
// function involved.
//

LispObject autoload1(LispObject fname, LispObject a1)
{   LispObject nil = C_nil;
    push2(a1, qcar(fname));
    set_fns(qcar(fname), undefined1, undefined2, undefinedn);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        errexitn(3);
        pop(fname);
    }
    pop(fname);
#ifndef NO_BYTECOUNT
    name_of_caller = "autoload";
#endif
    return apply(fname, 1, nil, fname, 0);
}

LispObject autoload2(LispObject fname, LispObject a1, LispObject a2)
{   LispObject nil = C_nil;
    push3(a1, a2, qcar(fname));
    set_fns(qcar(fname), undefined1, undefined2, undefinedn);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        errexitn(4);
        pop(fname);
    }
    pop(fname);
#ifndef NO_BYTECOUNT
    name_of_caller = "autoload";
#endif
    return apply(fname, 2, nil, fname, 0);
}

LispObject autoloadn(LispObject fname, int nargs, ...)
{   LispObject nil = C_nil;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    push(qcar(fname));
    set_fns(qcar(fname), undefined1, undefined2, undefinedn);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        errexitn(nargs+2);
        pop(fname);
    }
    pop(fname);
#ifndef NO_BYTECOUNT
    name_of_caller = "autoload";
#endif
    return apply(fname, nargs, nil, fname, 0);
}

LispObject undefined1(LispObject fname, LispObject)
{
//
// It would be perfectly possible to grab and save the args here, and retry
// the function call after error has patched things up.  Again
// this entrypoint is for compiled code calling something that is undefined,
// and so no lexical environment is needed.
//
    return error(1, err_undefined_function_1, fname);
}

LispObject undefined2(LispObject fname, LispObject, LispObject)
{   return error(1, err_undefined_function_2, fname);
}

LispObject undefinedn(LispObject fname, int, ...)
{   return error(1, err_undefined_function_n, fname);
}

//
// The next few functions allow me to create variants on things! The
// entrypoint fX_as_Y goes in the function cell of a symbol, and the name
// of a function with Y arguments goes in is environment cell. The result will
// be a function that accepts X arguments and discards all but the first Y of
// them, then chains to the other function. The purpose is to support goo
// compilation of things like
//   (de funny_equal (a b c) (equal a b))
//

LispObject f0_as_0(LispObject env, int nargs, ...)
{   if (nargs != 0) return aerror1("wrong number of args (0->0)", env);
    debug_record_symbol(env);
    return (*qfnn(env))(qenv(env), 0);
}

LispObject f1_as_0(LispObject env, LispObject)
{   debug_record_symbol(env);
    return (*qfnn(env))(qenv(env), 0);
}

LispObject f2_as_0(LispObject env, LispObject, LispObject)
{   debug_record_symbol(env);
    return (*qfnn(env))(qenv(env), 0);
}

LispObject f3_as_0(LispObject env, int nargs, ...)
{   if (nargs != 3) return aerror1("wrong number of args (3->0)", env);
    debug_record_symbol(env);
    return (*qfnn(env))(qenv(env), 0);
}

LispObject f1_as_1(LispObject env, LispObject a)
{   debug_record_symbol(env);
    return (*qfn1(env))(qenv(env), a);
}

LispObject f2_as_1(LispObject env, LispObject a, LispObject)
{   debug_record_symbol(env);
    return (*qfn1(env))(qenv(env), a);
}

LispObject f3_as_1(LispObject env, int nargs, ...)
{   va_list a;
    LispObject a1;
    if (nargs != 3) return aerror1("wrong number of args (3->1)", env);
    va_start(a, nargs);
    a1 = va_arg(a, LispObject);
    va_end(a);
    debug_record_symbol(env);
    return (*qfn1(env))(qenv(env), a1);
}

LispObject f2_as_2(LispObject env, LispObject a, LispObject b)
{   debug_record_symbol(env);
    return (*qfn2(env))(qenv(env), a, b);
}

LispObject f3_as_2(LispObject env, int nargs, ...)
{   va_list a;
    LispObject a1, a2;
    if (nargs != 3) return aerror1("wrong number of args (3->2)", env);
    va_start(a, nargs);
    a1 = va_arg(a, LispObject);
    a2 = va_arg(a, LispObject);
    va_end(a);
    debug_record_symbol(env);
    return (*qfn2(env))(qenv(env), a1, a2);
}

LispObject f3_as_3(LispObject env, int nargs, ...)
{   va_list a;
    LispObject a1, a2, a3;
    if (nargs != 3) return aerror1("wrong number of args (3->3)", env);
    va_start(a, nargs);
    a1 = va_arg(a, LispObject);
    a2 = va_arg(a, LispObject);
    a3 = va_arg(a, LispObject);
    va_end(a);
    debug_record_symbol(env);
    return (*qfnn(env))(qenv(env), 3, a1, a2, a3);
}

//
// The next function is EXPERIMENTAL and is only available if there is
// a "fork" function available. It is probably only even partially useful
// if the operating system and libraries used implement that using a
// "copy on write" strategy. This is the case with Linux, and I believe it to
// be so in MacOSX. But Windows does not provide that sort of functionality
// comfortably, so this stuff will not be available there. Observe that I
// make fairly extreme use of the autoconf detection stuff to try to avoid
// trying this where it might not make sense!
//

//
// Expected behaviour
//   (parallel f a)
//      runs two tasks, one of which is f(a, nil), the other is f(a, t).
//      when the first of those tasks completes the other is killed.
//      The result is a pair (fg . val)
//      If fg > 0 it is 1 or 2 to indicate which of the two calls
//      "won". In that case the value is the result returned by the
//      call, but NOTE that it has been in effect through print/read, and
//      so gensym identity and structure sharing will have been lost.
//      If fg < 0 then the true result was computed, but its printed
//      representation was longer than around 2K characters. The absolute
//      value of fg again indicates which task won, but the value is now
//      a string consisting of the first segment of characters in a printed
//      representation of the result. If creating parallel processes
//      fails or if the first task to finish does so by failing then this
//      call will report an error.
//      While it may be legal to use nested instaces of parallel to get
//      extra concurrency the memory demands that will result could be
//      severe. The overhead associated with starting and finishing a
//      task may also be significant, and so this is only liable to make
//      sense on a multi-cpu system for sub-tasks that are fairly demanding.
//      Note that the longer running task will be cancelled and no output
//      from it will be available at all.
//      Tasks run this way should probably avoid all input and output
//      operations.
//
//      If the computer on which CSL has been built does not support "fork"
//      and the shared memory operations required here the parallel function
//      will just always report an error.
//
//      While this code is in development it may genatate a certain amount
//      of unwanted trace or logging information.
//

#if defined HAVE_UNISTD_H && \
    defined HAVE_SYS_TYPES_H && \
    defined HAVE_SYS_STAT_H && \
    defined HAVE_SYS_WAIT_H && \
    defined HAVE_SIGNAL_H && \
    defined HAVE_SYS_SHM_H && \
    defined HAVE_SYS_IPC_H && \
    defined HAVE_FORK && \
    defined HAVE_WAIT && \
    defined HAVE_WAITPID && \
    defined HAVE_SHMGET && \
    defined HAVE_SHMAT && \
    defined HAVE_SHMDT && \
    defined HAVE_SHMCTL

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>

#define PARSIZE 65536

static void write_result(LispObject nil, LispObject r, char *shared)
{
//
// This converts an arbitrary result into a string so I can pass it back.
//
    int32_t i, len, ok = 1;
//
// Cyclic and re-entrant structures could lead to failure here, and
// uninterned symbols (eg gensyms) will not be coped with very well. But
// SIMPLE data types should all be safe.
//
    r = Lexplode(nil, r);
    if (exception_pending())
    {   strcpy(shared, "Failed");
        exit(2);
    }
    r = Llist_to_string(nil, r);
    if (exception_pending())
    {   strcpy(shared, "Failed");
        exit(3);
    }
    len = length_of_byteheader(vechdr(r)) - CELL;
//
// If the displayed form ou the output was too long I just truncate it
// at present. A more agressive attitude would be to count that as a form
// of failure. As an intermediate step I use the first character in my
// buffer as an "overflow flag" and leave a blank in it if all is well.
//
    if (len > PARSIZE-2)
    {   len=PARSIZE-2;
        ok = 0;
    }
    shared[0] = ok ? ' ' : '#';
    for (i=0; i<len; i++) shared[i+1] = celt(r, i);
    shared[len+1] = 0;
}

LispObject Lparallel(LispObject nil, LispObject a, LispObject b)
{   pid_t pid1, pid2, pidx, pidy;
//
// Create an identifier for a private shared segment of memory of size
// 2*PARSIZE. This will be used for passing a result from the sub-task
// to the main one. Give up if such a segment can not be allocated.
//
    int status, segid = shmget(IPC_PRIVATE, (size_t)(2*PARSIZE),
                               IPC_CREAT | S_IRUSR | S_IWUSR);
    char *shared, *w;
    int overflow;
    LispObject r;
    if (segid == -1) return aerror("Unable to allocate a shared segment");
//
// Attach to the shared segment to obtain a memory address via which it can be
// accessed. Again raise an error if this fails.
//
    shared = (char *)shmat(segid, NULL, 0);
    if (shared == (char *)(-1))
        return aerror("Unable to attach to shared segment");
//
// the shared segment is set up to contain null strings in the two places
// where it might be used to hold return values.
//
    shared[0] = shared[PARSIZE] = 0;
//
// Split off a clone of the current process that can be used to do the
// first evaluation. If this succeeds call a(b, nil) in it. Note that
// processes created via "fork" inherit shared memory segments from their
// parent.
//
    pid1 = fork();
    if (pid1 < 0)     // Task not created, must tidy up.
    {   shmdt(shared);
        shmctl(segid, IPC_RMID, 0);
        return aerror("Fork 1 failed");
    }
    else if (pid1 == 0)
    {   // TASK 1 created OK
        LispObject r1 = Lapply2(nil, 3, a, b, nil);
        nil = C_nil;
//
// If the evaluation failed I will exit indicating a failure.
//
        if (exception_pending())
        {   strcpy(shared, "Failed");
            exit(1);
        }
//
// Write result from first task into the first half of the shared memory block.
//
        write_result(nil, r1, shared);
//
// Exiting from the sub-task would in fact detach from the shared data
// segment, but I do the detaching explictly to feel tidy.
//
        shmdt(shared);
        exit(0);
    }
    else
    {
//
// This is the continuation of the main process. Create a second task in
// much the same way.
//
        pid2 = fork();
        if (pid2 < 0)    // If task 2 can not be created then kill task 1
        {   kill(pid1, SIGKILL);
            waitpid(pid1, &status, 0);
            shmdt(shared);
            shmctl(segid, IPC_RMID, 0);
            return aerror("Fork 2 failed");
        }
        else if (pid2 == 0)
        {   // TASK 2
            LispObject r2 = Lapply2(nil, 3, a, b, lisp_true);
            nil = C_nil;
            if (exception_pending())
            {   strcpy(shared, "Failed");
                exit(1);
            }
            write_result(nil, r2, shared+PARSIZE);
            shmdt(shared);
            exit(0);
        }
        else
        {
//
// Wait for whichever of the two sub-tasks finishes first. Then kill the
// other one, and return the result left by the winner.
//
            pidx = wait(&status);
//          term_printf("First signal was from task %d\n", pidx);
            if (!WIFEXITED(status) ||
                WEXITSTATUS(status) != 0)
            {
//
// If the first task to complete in fact failed rather than exited cleanly
// I will count it as an overall failure and cancel everything. This
// covers aborting (in which case WIFEXITED will return false) or
// exiting cleanly but with a non-zero return code.
//
                kill(pid1, SIGKILL);
                kill(pid2, SIGKILL);
                waitpid(pid1, &status, 0);
                waitpid(pid2, &status, 0);
                shmdt(shared);
                shmctl(segid, IPC_RMID, 0);
                return aerror("Task did not exit cleanly");
            }
            if (pidx == pid1)
            {   w = shared;
                pidy = pid2;
                overflow = 1;
            }
            else
            {   w = shared+PARSIZE;
                pidy = pid1;
                overflow = 2;
            }
            kill(pidy, SIGKILL);        // Kill alternate task
            waitpid(pidy, &status, 0);
//
// If the first character of the buffer is a blank then there was no
// overflow and all is well.
//
            if (w[0] == ' ') r = read_from_vector(w + 1);
            else
            {   overflow = -overflow;
                r = make_string(w + 1);
            }
//
// Need to tidy up the shared segment at the end.
//
            shmdt(shared);
            shmctl(segid, IPC_RMID, 0);
            errexit();
            r = cons(fixnum_of_int(overflow), r);
            errexit();
            return onevalue(r);
        }
    }
}

#else

LispObject Lparallel(LispObject nil, LispObject a, LispObject b)
{   return aerror("parallel not supported on this platform");
}

#endif

LispObject Lsleep(LispObject nil, LispObject a)
{   int n;
    if (is_fixnum(a)) n = int_of_fixnum(a);
    else n = 1;
#ifdef WIN32
    Sleep(1000*n);
#else
    sleep(n);
#endif
    return onevalue(nil);
}

setup_type const eval1_setup[] =
{   {"bytecounts",              bytecounts1, wrong_no_nb, bytecounts},
//
// PSL has a function idapply that is, as best I understand, just the
// same as apply apart from the fact that it expects an identifier as
// its first argument. But it them says it tests for that and moans if
// given a list, so I find it hard to understand how or why it is liable
// to be faster than plain apply! However to ease portability I provide
// that name here...  I think I should mention funcall as a possible
// optimisation in this area...
//
    {"idapply",                 Lapply_1, Lapply_2, Lapply_n},
    {"apply",                   Lapply_1, Lapply_2, Lapply_n},
    {"apply0",                  Lapply0, too_many_1, wrong_no_1},
    {"apply1",                  too_few_2, Lapply1, wrong_no_2},
    {"apply2",                  wrong_no_na, wrong_no_nb, Lapply2},
    {"apply3",                  wrong_no_na, wrong_no_nb, Lapply3},
    {"evlis",                   Levlis, too_many_1, wrong_no_1},
    {"funcall",                 Lfuncall1, Lfuncall2, Lfuncalln},
    {"funcall*",                Lfuncall1, Lfuncall2, Lfuncalln},
    {"parallel",                too_few_2, Lparallel, wrong_no_2},
    {"sleep",                   Lsleep, too_many_1, wrong_no_1},
#ifdef COMMON
    {"values",                  Lvalues_1, Lvalues_2, Lvalues},
    {"macroexpand",             Lmacroexpand, Lmacroexpand_2, wrong_no_1},
    {"macroexpand-1",           Lmacroexpand_1, Lmacroexpand_1_2, wrong_no_1},
#else
    {"macroexpand",             Lmacroexpand, too_many_1, wrong_no_1},
    {"macroexpand-1",           Lmacroexpand_1, too_many_1, wrong_no_1},
#endif
    {NULL,                      0, 0, 0}
};

// end of eval1.cpp
