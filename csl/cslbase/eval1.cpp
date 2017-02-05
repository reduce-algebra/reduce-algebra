// eval1.cpp                               Copyright (C) 1989-2017 Codemist    

//
// Interpreter (part 1).
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

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

LispObject nreverse(LispObject a)
{   LispObject b = nil;
    while (consp(a))
    {   LispObject c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return b;
}

//
// Environments are represented as association lists, and have to cope
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

LispObject eval(LispObject u, LispObject env)
{   STACK_SANITY;
    int t;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__)) aerror("deep stack in eval");
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
        if ((h & SYM_KEYWORD_VAR) != 0)   // fluid and global detected too
        {   LispObject v = qvalue(u);
            if (v == unset_var) error(1, err_unset_var, u);
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
                        if (v == unset_var) error(1, err_unset_var, u);
                    }
                    return onevalue(v);
                }
                env = qcdr(env);
            }
            {   LispObject v = qvalue(u);
                if (v == unset_var) error(1, err_unset_var, u);
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
    {
//
// The final case is that of a list (fn ...), and one case that has to
// be checked is if fn is lexically bound.
//
        LispObject fn, args;
//
// The test for nil here is because although nil is a symbol the tagging
// structure tested here marks it as a list.
//
        if (u == nil) return onevalue(nil);
        stackcheck2(0, u, env);
        fn = qcar(u);
        args = qcdr(u);
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
                    on_backtrace(
                        w = cons(lambda, w);
                        p = Lfuncalln(nil, 4, qvalue(macroexpand_hook),
                                      w, u, nil),
                        // now the error handler
                        pop2(env, u);
                        if (SHOW_FNAME)
                        {   err_printf("\nMacroexpanding: ");
                            loop_print_error(u);
                        });
                    pop2(env, u);
                    u = p;
                    goto restart;
                }
            }
        }
        if (is_symbol(fn))
        {
//
// Special forms and macros are checked for next.  Special forms
// take precedence over macros.
//
            Header h = qheader(fn);
            debug_record_symbol(fn);
            if (h & SYM_SPECIAL_FORM)
            {   STACK_SANITY1(u);
#ifdef DEBUG
                if (qfn1(fn) == NULL)
                {   term_printf("Illegal special form\n");
                    my_exit(EXIT_FAILURE);
                }
#endif
                return ((Special_Form *)qfn1(fn))(args, env);
            }
            else if (h & SYM_MACRO)
            {   STACK_SANITY;
                push2(u, env);
//
// the environment passed to macroexpand should only be needed to cope
// with macrolet, I think.  Since I use just one datastructure for the
// whole environment I also pass along lexical bindings etc, but I hope that
// they will never be accessed.  I do not think that macrolet is important
// enough to call for complication and slow-down in the interpreter this
// way - but then I am not exactly what you would call a Common Lisp Fan!
//
                debug_record("About to expand a macro");
                on_backtrace(
                    fn = macroexpand(u, env);
                    debug_record("macro expanded"),
                    // now the error handler
                    pop2(env, u);
                    if (SHOW_FNAME)
                    {   err_printf("\nMacroexpanding: ");
                        loop_print_error(u);
                    });
                pop2(env, u);
                return eval(fn, env);
            }
        }
//
// Otherwise we have a regular function call.  I prepare the args and
// call APPLY.
//
    ordinary_function:
        {   int nargs = 0;
            LispObject *save_stack = stack;
            STACK_SANITY1(u);
//
// Args are built up on the stack here...
//
            while (consp(args))
            {   LispObject w;
                push3(fn, args, env);
                w = qcar(args);
                on_backtrace(
                    w = eval(w, env),
                    // Now the error handler
                    pop3(env, args, fn);
                    stack = save_stack;
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(qcar(args));
                    });
                pop3(env, args, fn);
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
            return apply(fn, nargs, env, fn);
        }
    }
}

//
// I am moving to a situation where the intepreter support &optional,
// &rest and keyword arguments and all the odd generality that Common Lisp
// introduces. This slows down the interpreter.
//

static bool check_no_unwanted_keys(LispObject restarg, LispObject ok_keys)
//
// verify that there were no unwanted keys in the actual arg list
//
{   bool odd_key_found = false;
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
// the keyword package. Return true in BAD case.
//
{   while (restarg!=nil)
    {   LispObject q = qcar(restarg);
        if (!is_symbol(q) || qpackage(q) != qvalue(keyword_package))
            return true;
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
    LispObject name = get_pname(v);
// For Standard Lisp the concept of a "keyword package" is not really
// relevant! I am going to need to invent some scheme that provides some
// sort of treatment that identifies keywords as being special.
    return Lintern_2(nil, name, qvalue(keyword_package));
}

static LispObject key_lookup(LispObject keyname, LispObject args)
{   while (args!=nil)
    {   LispObject next = qcdr(args);
        if (next==nil) return nil;
        if (qcar(args) == keyname) return next;
        else args = qcdr(next);
    }
    return nil;
}


LispObject apply_lambda(LispObject def, int nargs,
                        LispObject env, LispObject name)
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
#define ok_keys     stack[-8]
#define local_decs  stack[-9]
#define name        stack[-10]
#define env         stack[-11]
#define body        stack[-12]
#define bvl         stack[-13]
#define arg1        stack[-14]
#define stack_used ((int)(nargs + 14))
// Wow - that looks like a lot of state to be kept on the stack!

    for (;;)
    {   if (!consp(body)) break;
        p = macroexpand(qcar(body), env);
        body = qcdr(body);
        if (!consp(p))
        {   if (stringp(p) && consp(body)) continue; // string is comment here.
            body = cons(p, body);  // other atoms get stuck back on body.
            break;
        }
        if (qcar(p) != declare_symbol)
        {   body = cons(p, body);  // something other than a "declare".
            break;
        }
// I have found a body that was initially something like
//   ("string" "string" (declare ...) ...)
// and I have discarded the strings and here p is the part that starts
// with the symbol DECLARE.
        for (v = qcdr(p); consp(v); v = qcdr(v))
        {   v1 = qcar(v);
// scan looking for (SPECIAL ...)
            if (!consp(v1) || qcar(v1) != special_symbol) continue;
            // here v1 says (special ...)
            for (v1=qcdr(v1); consp(v1); v1 = qcdr(v1))
                local_decs = cons(qcar(v1), local_decs);
        }
    }
//
// Parse the BVL
//
    try
    {   START_SETJMP_BLOCK;
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
    
// #define BAD1(msg)    { error(0, msg);    }
#define BAD1(msg)    { \
err_printf("\n@@@ BAD1 "); prin_to_error(def); err_printf("\n"); \
error(0, msg);    }
#define BAD2(msg, a) { error(1, msg, a); }

#define collect_rest_arg()                                  \
    while (args_left-- != 0)                                \
        restarg = cons(next_arg[args_left], restarg);

                    if (v == rest_key)
                    {   collect_rest_arg();
                        opt_rest_state = STATE_REST;
                        continue;
                    }
                    if (v == key_key)
                    {   collect_rest_arg();
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
                    if (args_left == 0) BAD1(err_insufficient_args);
                    arg = *next_arg++;
                    args_left--;
                    v1 = nil;       // no suppliedp mess here, I'm glad to say
                    break;

                case STATE_OPT:
                    if (v == opt_key
                        || v == rest_key
                        || v == key_key
                        || v == allow_other_keys
                        || v == aux_key
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
                        }
                        w = qcdr(w);
                        if (consp(w)) v1 = qcar(w); // suppliedp name
                        break;
                    }

                case STATE_OPT1:
                    if (v == rest_key)
                    {   collect_rest_arg();
                        opt_rest_state = STATE_REST;
                        continue;
                    }
                    if (v == key_key)
                    {   collect_rest_arg();
                        if (check_keyargs_even(restarg)) BAD2(err_bad_keyargs, restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   if (args_left != 0) BAD1(err_excess_args);
                        opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == opt_key ||
                        v == allow_other_keys) BAD2(err_bad_bvl, v);
                    goto process_optional_parameter;

                case STATE_REST:
                    if (v == opt_key
                        || v == rest_key
                        || v == key_key
                        || v == allow_other_keys
                        || v == aux_key
                       ) BAD2(err_bad_bvl, v);
                    opt_rest_state = STATE_REST1;
                    arg = restarg;
                    break;

                case STATE_REST1:
                    if (v == key_key)
                    {   if (check_keyargs_even(restarg)) BAD2(err_bad_keyargs, restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   opt_rest_state = STATE_AUX;
                        continue;
                    }
                    BAD2(err_bad_bvl, rest_key);

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
                            }
                            else
                            {   keyname = qcar(v);
                                if (!is_symbol(keyname) || v==nil || v ==lisp_true)
                                    BAD2(err_bad_bvl, v);
                                keyname = keywordify(keyname);
                                v = qcdr(v);
                                if (consp(v)) v = qcar(v);
                                else BAD2(err_bad_bvl, v);
                            }
                        }
                        ok_keys = cons(keyname, ok_keys);
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
                        }
                    }
                    else arg = nil;
                    v1 = nil;
                    break;
            }
//
// This is where I get when I have one or two vars to bind.
//
#define instate_binding(var, val, local_decs1, lab)                     \
        {   Header h;                                                   \
            if (!is_symbol(var) || var==nil || var==lisp_true ||        \
                (qheader(var) & SYM_GLOBAL_VAR)!=0)                     \
                BAD2(err_bad_bvl, var);                                 \
            h = qheader(var);                                           \
            if ((h & SYM_SPECIAL_VAR) != 0)                             \
            {   w = acons(var, qvalue(var), specenv);                   \
                specenv = w;                                            \
                qvalue(var) = val;                                      \
            }                                                           \
            else                                                        \
            {   for (w = local_decs1; w!=nil; w = qcdr(w))              \
                {   if (qcar(w) == var)                                 \
                    {   qcar(w) = fixnum_of_int(0);/* decl is used up */\
                        w = acons(var, work_symbol, env);               \
                        env = w;                                        \
                        w = acons(var, qvalue(var), specenv);           \
                        specenv = w;                                    \
                        qvalue(var) = val;                              \
                        goto lab;                                       \
                    }                                                   \
                }                                                       \
                w = acons(var, val, env);                               \
                env = w;                                                \
        lab:    ;                                                       \
            }                                                           \
        }

//
// Must check about local special declarations here...
//
            instate_binding(v, arg, local_decs, label1);
            if (v1 != nil) instate_binding(v1, val1, local_decs, label2);

        }   // End of for loop that scans BVL

//
// As well as local special declarations that have applied to bindings here
// there can be some that apply just to variable references within the body.
//
        while (local_decs!=nil)
        {   LispObject q = qcar(local_decs);
            local_decs=qcdr(local_decs);
            if (!is_symbol(q)) continue;
            w = acons(q, work_symbol, env);
            env = w;
        }

        switch (opt_rest_state)
        {   case STATE_NULL:
            case STATE_OPT1:        // Ensure there had not been too many args
                if (args_left != 0) BAD1(err_excess_args);
                break;

            case STATE_OPT:         // error if bvl finishes here
            case STATE_REST:
                BAD2(err_bad_bvl, opt_rest_state == STATE_OPT ? opt_key : rest_key);

            case STATE_KEY:         // ensure only valid keys were given
                if (check_no_unwanted_keys(restarg, ok_keys))
                    BAD2(err_bad_keyargs, restarg);
                break;

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
        {   exit_count = 1;
            def = progn_fn(body, env);
            while (specenv != nil)
            {   LispObject bv = qcar(specenv);
                qvalue(qcar(bv)) = qcdr(bv);
                specenv = qcdr(specenv);
            }
        }
    }
    catch (LispException e)
    {
//
// I am having to unwind the stack, restoring special bindings as I go.
//
        while (specenv != nil)
        {   LispObject bv = qcar(specenv);
            qvalue(qcar(bv)) = qcdr(bv);
            specenv = qcdr(specenv);
        }
        throw;
    }
    popv(stack_used);
//
// note that exit_count has not been disturbed since I called progn_fn,
// so the number of values that will be returned remains correctly
// established.
//
    return def;
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

LispObject Leval(LispObject env, LispObject a)
{   return eval(a, nil);     // Multiple values may be returned
}

LispObject Levlis(LispObject env, LispObject a)
{   STACK_SANITY;
    LispObject r;
    stackcheck1(0, a);
    r = nil;
    while (consp(a))
    {   push2(qcdr(a), r);
        a = qcar(a);
        a = eval(a, nil);
        pop(r);
        r = cons(a, r);
        pop(a);
    }
    return onevalue(nreverse(r));
}

LispObject Lapply_n(LispObject env, int nargs, ...)
{   STACK_SANITY;
    va_list a;
    int i;
    LispObject last, fn = nil;
    if (nargs == 0) aerror("apply");
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
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, i, nil, fn);
}

LispObject Lapply_1(LispObject env, LispObject fn)
{   return Lapply_n(nil, 1, fn);
}

LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1)
{   return Lapply_n(nil, 2, fn, a1);
}

LispObject Lapply0(LispObject env, LispObject fn)
{   STACK_SANITY;
#ifndef DEBUG
// I avoid this optimisation if debugging...
    if (is_symbol(fn)) return (*qfnn(fn))(qenv(fn), 0);
#endif
    stackcheck1(0, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, 0, nil, fn);
}

LispObject Lapply1(LispObject env, LispObject fn, LispObject a)
{   STACK_SANITY;
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfn1(fn))(qenv(fn), a);
#endif
    push(a);
    stackcheck1(1, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "apply";
#endif
    return apply(fn, 1, nil, fn);
}

LispObject Lapply2(LispObject env, int nargs, ...)
{   STACK_SANITY;
    va_list aa;
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
    return apply(fn, 2, nil, fn);
}

LispObject Lapply3(LispObject env, int nargs, ...)
{   STACK_SANITY;
    va_list aa;
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
    return apply(fn, 3, nil, fn);
}

LispObject Lfuncall1(LispObject env, LispObject fn)
{   STACK_SANITY;
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfnn(fn))(qenv(fn), 0);
#endif
    stackcheck1(0, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "funcall";
#endif
    return apply(fn, 0, nil, fn);
}

LispObject Lfuncall2(LispObject env, LispObject fn, LispObject a1)
{   STACK_SANITY;
#ifndef DEBUG
    if (is_symbol(fn)) return (*qfn1(fn))(qenv(fn), a1);
#endif
    push(a1);
    stackcheck1(1, fn);
#ifndef NO_BYTECOUNT
    name_of_caller = "funcall";
#endif
    return apply(fn, 1, nil, fn);
}

static LispObject Lfuncalln_sub(LispObject env, int nargs, va_list a)
{   STACK_SANITY;
    LispObject fn = va_arg(a, LispObject);
    push_args_1(a, nargs);
#ifndef NO_BYTECOUNT
    name_of_caller = "funcall";
#endif
    return apply(fn, nargs-1, nil, fn);
}

LispObject Lfuncalln(LispObject env, int nargs, ...)
{   STACK_SANITY;
    va_list a;
    LispObject fn, a1, a2, a3, a4;
    va_start(a, nargs);
    switch (nargs)
    {   case 0: aerror("funcall");
        case 1: // cases 1 and 2 should go through Lfuncall1,2 not here
        case 2: aerror("funcall wrong call");
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
            return apply(fn, 2, nil, fn);
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
            return apply(fn, 3, nil, fn);
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
            return apply(fn, 4, nil, fn);
        default:
            return Lfuncalln_sub(nil, nargs, a);
    }
}

// My initial implementation of multiple values insists that every function
// set a value-count on exit. That is onerous and puts a cost almost
// everywhere. I want to move to a model where before entering a function the
// value-count variable is set to 1, and the function only changes it if it
// needs to. In the interpreter that will be easy I believe. For the compiler
// it will mean that after any call to an unknown function (or one liable to
// return multiple values) the count variable is reset on the path to any
// and before a call to any other function that could possibly (directly or
// indirectly) rely on how many values were in play. The most naive version
// of that would involve resetting the count to 1 after any call to anything
// unknown. If I go that way it will be in the future.

LispObject Lvalues(LispObject env, int nargs, ...)
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

LispObject Lvalues_2(LispObject env, LispObject a, LispObject b)
{   return Lvalues(nil, 2, a, b);
}

LispObject Lvalues_1(LispObject env, LispObject a)
{   return Lvalues(nil, 1, a);
}

LispObject mv_call_fn(LispObject args, LispObject env)
//
// here with the rest of the interpreter rather than in specforms.c
//
{   STACK_SANITY;
    int i=0;
    if (!consp(args)) return nil;       // (multiple-value-call) => nil
    stackcheck2(0, args, env);
    push2(args, env);
    LispObject fn = qcar(args);
    fn = eval(fn, env);
    pop2(env, args);
    args = qcdr(args);
    while (consp(args))
    {   LispObject r1;
        push2(args, env);
        r1 = qcar(args);
        exit_count = 1;
        r1  = eval(r1, env);
//
// It is critical here that push does not check for stack overflow and
// thus can not call the garbage collector, or otherwise lead to calculation
// that could possibly clobber the multiple results that I am working with
// here.
//
        pop2(env, args);
        push(r1);
        i++;
        for (size_t j = 2; j<=exit_count; j++)
        {   push((&work_0)[j]);
            i++;
        }
        args = qcdr(args);
    }
#ifndef NO_BYTECOUNT
    name_of_caller = "mv-call";
#endif
    return apply(fn, i, env, fn);
}

LispObject interpreted1(LispObject def, LispObject a1)
{   STACK_SANITY;
    push(a1);
    stackcheck1(1, def);
    return apply_lambda(def, 1, nil, def);
}

LispObject interpreted2(LispObject def, LispObject a1, LispObject a2)
{   STACK_SANITY;
    push2(a1, a2);
    stackcheck1(2, def);
    return apply_lambda(def, 2, nil, def);
}

LispObject interpretedn(LispObject def, int nargs, ...)
{
//
// The messing about here is to get the (unknown number of) args
// into a nice neat vector so that they can be indexed into. If I knew
// that the args were in consecutive locations on the stack I could
// probably save a copying operation.
//
    STACK_SANITY;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    return apply_lambda(def, nargs, nil, def);
}

LispObject funarged1(LispObject def, LispObject a1)
{   STACK_SANITY;
    push(a1);
    stackcheck1(1, def);
    return apply_lambda(qcdr(def), 1, qcar(def), qcdr(def));
}

LispObject funarged2(LispObject def, LispObject a1, LispObject a2)
{   STACK_SANITY;
    push2(a1, a2);
    stackcheck1(2, def);
    return apply_lambda(qcdr(def), 2, qcar(def), qcdr(def));
}

LispObject funargedn(LispObject def, int nargs, ...)
{   STACK_SANITY;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    return apply_lambda(qcdr(def), nargs, qcar(def), qcdr(def));
}

LispObject traceinterpreted1(LispObject def, LispObject a1)
//
// Like interpreted() but the definition has the fn name consed on the front
//
{   STACK_SANITY;
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
    LispObject r = apply_lambda(qcdr(def), 1, nil, def);
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
{   STACK_SANITY;
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
    LispObject r = apply_lambda(qcdr(def), 2, nil, def);
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
{   STACK_SANITY;
    int i;
    LispObject r;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
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
    r = apply_lambda(qcdr(def), nargs, nil, def);
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
{   STACK_SANITY;
    LispObject r;
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
    r = apply_lambda(qcdr(def), 1, qcar(def), qcdr(def));
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
{   STACK_SANITY;
    LispObject r;
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
    r = apply_lambda(qcdr(def), 2, qcar(def), qcdr(def));
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
{   STACK_SANITY;
    LispObject r;
    va_list a;
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    freshline_trace();
    trace_printf("Entering funarg ");
    loop_print_trace(qcar(def));
    trace_printf(" (%d args)", nargs);
#ifndef NO_BYTECOUNT
    if (name_of_caller != NULL) trace_printf(" from %s", name_of_caller);
#endif
    trace_printf("\n");
    def = qcdr(def);
    r = apply_lambda(qcdr(def), nargs, qcar(def), qcdr(def));
    push(r);
    trace_printf("Value = ");
    loop_print_trace(r);
    trace_printf("\n");
    pop(r);
    return r;
}

static LispObject macroexpand_1(LispObject form, LispObject env)
{   // The environment here seems only necessary for macrolet
    STACK_SANITY;
    LispObject done;
    LispObject f;
    stackcheck2(0, form, env);
    done = nil;
    if (consp(form))
    {   f = qcar(form);
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
                    on_backtrace(
                        p = Lfuncalln(nil, 4, qvalue(macroexpand_hook),
                                      w, stack[-1], nil),
                        // Now the error handler
                        pop2(done, form);
                        if (SHOW_FNAME)
                        {   err_printf("\nMacroexpanding: ");
                            loop_print_error(form);
                        });
                    pop2(done, form);
                    mv_2 = lisp_true;
                    return nvalues(p, 2);
                }
            }
        }
//
// If there is no local macro definition I need to look for a global one
//
        if (symbolp(f) && (qheader(f) & SYM_MACRO) != 0)
        {   done = qvalue(macroexpand_hook);
            if (done == unset_var)
                error(1, err_macroex_hook, macroexpand_hook);
            push3(form, env, done);
            f = cons(lambda, qenv(f));
            pop3(done, env, form);
            form = Lfuncalln(nil, 4, done, f, form, env);
            done = lisp_true;
        }
    }
    mv_2 = done;
    return nvalues(form, 2);    // Multiple values handed back
}

LispObject macroexpand(LispObject form, LispObject env)
{   // The environment here seems only necessary for macrolet
    STACK_SANITY;
    LispObject done;
    stackcheck2(0, form, env);
    done = nil;
    for (;;)
    {   push2(env, done);
        form = macroexpand_1(form, env);
        pop2(done, env);
        if (mv_2 == nil) break;
        done = lisp_true;
    }
    mv_2 = done;
    return nvalues(form, 2);    // Multiple values handed back
}

LispObject Lmacroexpand(LispObject env, LispObject a)
{   return macroexpand(a, nil);
}

LispObject Lmacroexpand_2(LispObject, LispObject a, LispObject b)
{   return macroexpand(a, b);
}

LispObject Lmacroexpand_1(LispObject env, LispObject a)
{   return macroexpand_1(a, nil);
}

LispObject Lmacroexpand_1_2(LispObject, LispObject a, LispObject b)
{   return macroexpand_1(a, b);
}

//
// To make something autoloadable I should set the environment cell to
//    (name-of-self module-name-1 module-name-2 ...)
// and when invoked the function will do a load-module on each of the
// modules specified and then re-attempt to call.  Loading the
// modules is expected to establish a proper definition for the
// function involved.
//

LispObject autoload1(LispObject fname, LispObject a1)
{   STACK_SANITY;
    push2(a1, qcar(fname));
// worry about 0 and 3 args special cases...
    set_fns(qcar(fname), undefined1, undefined2, undefinedn);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop(fname);
#ifndef NO_BYTECOUNT
    name_of_caller = "autoload";
#endif
    return apply(fname, 1, nil, fname);
}

LispObject autoload2(LispObject fname, LispObject a1, LispObject a2)
{   STACK_SANITY;
    push3(a1, a2, qcar(fname));
// 0 and 3 args special casess
    set_fns(qcar(fname), undefined1, undefined2, undefinedn);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop(fname);
#ifndef NO_BYTECOUNT
    name_of_caller = "autoload";
#endif
    return apply(fname, 2, nil, fname);
}

LispObject autoloadn(LispObject fname, int nargs, ...)
{   STACK_SANITY;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    push(qcar(fname));
// 0 and 3 arg special cases...
    set_fns(qcar(fname), undefined1, undefined2, undefinedn);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop(fname);
#ifndef NO_BYTECOUNT
    name_of_caller = "autoload";
#endif
    return apply(fname, nargs, nil, fname);
}

LispObject undefined0(LispObject fname)
{
    error(1, err_undefined_function_0, fname);
}

LispObject undefined1(LispObject fname, LispObject)
{
//
// It would be perfectly possible to grab and save the args here, and retry
// the function call after error has patched things up.  Again
// this entrypoint is for compiled code calling something that is undefined,
// and so no lexical environment is needed.
//
    error(1, err_undefined_function_1, fname);
}

LispObject undefined2(LispObject fname, LispObject, LispObject)
{   error(1, err_undefined_function_2, fname);
}

LispObject undefined3(LispObject fname, LispObject, LispObject, LispObject)
{   error(1, err_undefined_function_3, fname);
}

LispObject undefined4(LispObject fname, size_t,
                      LispObject, LispObject, LispObject, LispObject)
{   error(1, err_undefined_function_4, fname);
}

LispObject undefinedn(LispObject fname, int, ...)
{   error(1, err_undefined_function_n, fname);
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
{   if (nargs != 0) aerror1("wrong number of args (0->0)", env);
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
{   if (nargs != 3) aerror1("wrong number of args (3->0)", env);
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
    if (nargs != 3) aerror1("wrong number of args (3->1)", env);
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
    if (nargs != 3) aerror1("wrong number of args (3->2)", env);
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
    if (nargs != 3) aerror1("wrong number of args (3->3)", env);
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

static void write_result(LispObject env, LispObject r, char *shared)
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
    if_error(r = Lexplode(nil, r),
             // Error handler
             strcpy(shared, "Failed");
             exit(2));
    if_error(r = Llist_to_string(nil, r),
             // Error handler
             strcpy(shared, "Failed");
             exit(3));
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

LispObject Lparallel(LispObject env, LispObject a, LispObject b)
{   STACK_SANITY;
    pid_t pid1, pid2, pidx, pidy;
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
    if (segid == -1) aerror("Unable to allocate a shared segment");
//
// Attach to the shared segment to obtain a memory address via which it can be
// accessed. Again raise an error if this fails.
//
    shared = (char *)shmat(segid, NULL, 0);
    if (shared == (char *)(-1))
        aerror("Unable to attach to shared segment");
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
        aerror("Fork 1 failed");
    }
    else if (pid1 == 0)
    {   // TASK 1 created OK
        LispObject r1;
        if_error(r1 = Lapply2(nil, 3, a, b, nil),
// If the evaluation failed I will exit indicating a failure.
                 strcpy(shared, "Failed");
                 exit(1));
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
            aerror("Fork 2 failed");
        }
        else if (pid2 == 0)
        {   // TASK 2
            LispObject r2;
            if_error(r2 = Lapply2(nil, 3, a, b, lisp_true),
                     // Error handler
                     strcpy(shared, "Failed");
                     exit(1));
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
                aerror("Task did not exit cleanly");
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
            r = cons(fixnum_of_int(overflow), r);
            return onevalue(r);
        }
    }
}

#else

LispObject Lparallel(LispObject env, LispObject a, LispObject b)
{   aerror("parallel not supported on this platform");
}

#endif

LispObject Lsleep(LispObject env, LispObject a)
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
    {"eval",                    Leval, too_many_1, wrong_no_1},
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
    {"values",                  Lvalues_1, Lvalues_2, Lvalues},
    {"macroexpand",             Lmacroexpand, Lmacroexpand_2, wrong_no_1},
    {"macroexpand-1",           Lmacroexpand_1, Lmacroexpand_1_2, wrong_no_1},
    {NULL,                      0, 0, 0}
};

// end of eval1.cpp
