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
//  (1)       (funarg env bvl ...)    flet and labels for local function
//  (2)       (bvl ...)               macrolet
//                                    Note that 'funarg is not valid as a bvl
//                                    and indeed in this case bvl is a list
//                                    and can never be an atom.

LispObject eval(LispObject u, LispObject env)
{   STACK_SANITY;
    assert (env == nil || consp(env));
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__)) aerror("deep stack in eval");
#endif
restart:
    int t = (int)u & TAG_BITS;
// The first case considered is of symbols - lexical and special bindings
// have to be allowed for.
    if (t == TAG_SYMBOL)
    {   Header h = qheader(u);
        debug_record_symbol(u);
// I detect FLUID and GLOBAL variables because each of those situation is
// marked with a big in the symbol header. Both bits are set to mark
// a KEYWORD. In all such cases the value is in the symbol's value cell.
// If the symbol was fluid or global its value cell should have been
// initialized when it got declared, so I will not cgeck for "unset_var"
// again here.
        if ((h & SYM_KEYWORD_VAR) != 0) return onevalue(qvalue(u));
// If a symbol is not global or fluid then it ought to be bound locally,
// ir mentioned in the environment. This can include as a special case it
// being subject to a local declaration that it is global! This is
// "deep binding".
        else
        {   while (env != nil)
            {   LispObject p = qcar(env);
                if (qcar(p) == u)
                {   LispObject v =qcdr(p);
// If a variable is lexically bound to the value work_symbol that means
// that the symbol has been (lexically) declared to be special, so its
// value cell should be inspected.
                    if (v == work_symbol)
                    {   v = qvalue(u);
// I will trigger the "unset variable" message if a variable is declared
// locally global but did not have a global value set.
                        if (v == unset_var) error(1, err_unset_var, u);
                    }
                    return onevalue(v);
                }
                env = qcdr(env);
            }
// If a symbol has not been declared FLUID or GLOBAL and is not lovally
// bound then if I was feeling really cautious I would raise an error
// explaining that it should not be accessed. But that feels MEAN, and
// so I will treat it as if it had been made locally global. I COULD force
// it to be globally fluid here. There is a balance that has to be struck
// between error detection and convenience for the informal user!
            {   LispObject v = qvalue(u);
                if (v == unset_var) error(1, err_unset_var, u);
                else return onevalue(v);
            }
        }
    }
// Things that are neither symbols nor lists evaluate to themselves,
// e.g. numbers, characters, string and vectors. The special test for nil
// here is a throw-back to times when NIL was tagged as if a CONS. That
// happened in Common Lisp mode so that (car nil) and (cdr nil) could
// both yield nil without there needing to be any special treatment.
// My forward looking idea is that NIL will always be tagged as a symbol
// but in Common Lisp mode every CAR or CDR access will be checked for
// validity, and in the error case a special check for (CAR NIL) or
// (CDR NIL) will be made... In Standard Lisp mode there is no special
// issue to worry about here.
    else if (t != TAG_CONS || u == nil) return onevalue(u);
    else
    {
// The final case is that of a list (fn ...), and one case that has to
// be checked is if fn is lexically bound.
        LispObject fn, args;
        stackcheck2(u, env);
        fn = qcar(u);
        args = qcdr(u);
// Local function bindings must be looked for first. Well Standard Lisp
// does not have local function bindings, but Common Lisp does - hence the
// extra "fun" here.
        {   LispObject p;
            if (is_symbol(fn)) // can only be a local function if atomic.
            for (p=env; p!=nil; p=qcdr(p))
            {   LispObject w = qcar(p);
// The form (<list> . sym) is used in an environment to indicate a local
// binding of a function, either as a regular function or as a macro
// (i.e. flet or macrolet).  The structure of the list distinguishes
// between these two cases.
                if (qcdr(w) == fn && is_cons(w = qcar(w)) && w!=nil)
                {   p = qcar(w);
// p will now be (funarg env bvl ...body...) for a simple local
// function definition, or (bvl ...body...) with the bvl non-atomic
// for a local macro introduced using MACROLET.
                    if (p == funarg) // ordinary function
                    {   fn = w;      // (funarg ...) is OK to apply
                        goto ordinary_function;
                    }
// Here it is a local macro. Observe that the macroexpansion is done
// with respect to an empty environment.  Macros that are defined at the same
// time may seem to be mutually recursive but there is a sense in which they
// are not (as well as a sense in which they are) - self and cross references
// only happen AFTER an expansion and can not happen during one.
                    push2(u, env);
                    on_backtrace(
                        w = cons(lambda, w);
                        p = apply(qvalue(macroexpand_hook),
                                  list3(w, u, nil),
                                  nil,
                                  macroexpand_hook),
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
// Here I have dropped out from the search for a local definition of the
// function, so a global interpretation is needed.
        if (is_symbol(fn))
        {
// Special forms and (global) macros are checked for next.  Special forms
// take precedence over macros.
            Header h = qheader(fn);
            debug_record_symbol(fn);
            if (h & SYM_SPECIAL_FORM)
            {   STACK_SANITY1(u);
                assert(qfn1(fn) != NULL);
                return (qfn1(fn))(args, env);
            }
            else if (h & SYM_MACRO)
            {   STACK_SANITY;
                push2(u, env);
// the environment passed to macroexpand should only be needed to cope
// with macrolet, I think.  Since I use just one datastructure for the
// whole environment I also pass along lexical bindings etc, but I hope that
// they will never be accessed.  I do not think that macrolet is important
// enough to call for complication and slow-down in the interpreter this
// way - but then I am not exactly what you would call a Common Lisp Fan!
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
// Otherwise we have a regular function call.  I prepare the args and
// call APPLY. In the Lisp 1.5 manual there was a call to EVLIS here.
// I want the same sort of effect, but will avoid any recursion as I
// evaluate all the arguments!
    ordinary_function:
// Here I might reasonably unwind the process of evaluating arguments
// so that if I have at most 3 and if the function is a symbol I do
// things rather directly.
        LispObject eargs = nil;
        if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        {   if (args == nil) return (*qfn0(fn))(fn);
            LispObject a1 = qcar(args);
            push3(fn, args, env);
            on_backtrace(
                a1 = eval(a1, env),
                pop3(env, args, fn);
                if (SHOW_ARGS)
                {   err_printf("\nEvaluating: ");
                    loop_print_error(qcar(args));
                });
            pop3(env, args, fn);
            args = qcdr(args);
            if (args == nil) return (*qfn1(fn))(fn, a1);
            LispObject a2 = qcar(args);
            push4(fn, args, env, a1);
            on_backtrace(
                a2 = eval(a2, env),
                pop4(a1, env, args, fn);
                if (SHOW_ARGS)
                {   err_printf("\nEvaluating: ");
                    loop_print_error(qcar(args));
                });
            pop4(a1, env, args, fn);
            args = qcdr(args);
            if (args == nil) return (*qfn2(fn))(fn, a1, a2);
            LispObject a3 = qcar(args);
            push5(fn, args, env, a1, a2);
            on_backtrace(
                a3 = eval(a3, env),
                pop5(a2, a1, env, args, fn);
                if (SHOW_ARGS)
                {   err_printf("\nEvaluating: ");
                    loop_print_error(qcar(args));
                });
            pop5(a2, a1, env, args, fn);
            args = qcdr(args);
            if (args == nil) return (*qfn3(fn))(fn, a1, a2, a3);
            push3(fn, env, args);
            eargs = list3(a3, a2, a1);
            pop3(args, env, fn);
        }
// I have evaluated the first 3 args if the function was a symbol, so
// now I process the rest.
        {   STACK_SANITY1(u);
            while (consp(args))
            {   LispObject w;
                push4(fn, args, env, eargs);
                w = qcar(args);
                on_backtrace(
                    w = eval(w, env),
                    // Now the error handler
                    pop4(eargs, env, args, fn);
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(qcar(args));
                    });
                pop(eargs);
                eargs = cons(w, eargs);
                pop3(env, args, fn);
                args = qcdr(args);
            }
            eargs = nreverse(eargs);
// I pass the environment down to apply() because it will be used if the
// function was a simple lambda expression.  If the function is a symbol
// or a closure, env will be irrelevant.  The arguments are in a list.
            return apply(fn, eargs, env, current_function);
        }
    }
}

// I am moving to a situation where the intepreter support &optional,
// &rest and keyword arguments and all the odd generality that Common Lisp
// introduces. This slows down the interpreter.

static bool check_no_unwanted_keys(LispObject restarg, LispObject ok_keys)
// verify that there were no unwanted keys in the actual arg list
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
// check that list is even length with alternate items symbols in
// the keyword package. Return true in BAD case.
{   while (restarg!=nil)
    {   LispObject q = qcar(restarg);
        if (!is_symbol(q) || qpackage(q) != qvalue(keyword_package))
            return true;
        restarg = qcdr(restarg);
        if (restarg==nil) return true;      // Odd length is wrong
        restarg = qcdr(restarg);
    }
    return false;                           // OK
}

static LispObject keywordify(LispObject v)
{
    LispObject name = get_pname(v);
#ifdef COMMON
    return Lintern_2(nil, name, qvalue(keyword_package));
#else
// For Standard Lisp I will force a ":" as the first character of the
// name, and than tag it as a "keyword".
    if (basic_celt(name, 0) != ':')
    {   v = Lexplode(nil, v);
        v = list2star(fixnum_of_int('!'), fixnum_of_int(':'), v);
        v = Lcompress(nil, v);
    }
    Lmake_keyword(nil, v);
    return v;
#endif
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


// Within apply_lambda I have a fairly large amount of state that needs
// to be kept on the Lisp stack so that it is GC safe. Here I introduce
// names so I can access the information as if it was ordinary data. Note
// that I MUST NOT use push or pop operations while referencing these!

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
#define arglist     stack[-14]
#define stack_used  15
// Wow - that looks like a lot of state to be kept on the stack!

static inline void instate_binding(LispObject var, LispObject val,
        LispObject local_decs1)
{   Header h;
// Complain if the varianble that somebody is attempting to bind seems bad.
    if (!is_symbol(var) || (qheader(var) & SYM_GLOBAL_VAR)!=0)
        error(1, err_bad_bvl, var);
    h = qheader(var);
// Special variables have their old value saved in the association list
// specenv, and then get updated.
    if ((h & SYM_SPECIAL_VAR) != 0)
    {
// Wow messy. var and val need to be made GC safe across the call to acons,
// but it would not be valid to use push and pop because the name "specenv"
// expands to a rerefence relative to the top of the stack.
        specenv = acons_no_gc(var, qvalue(var), specenv);
        qvalue(var) = val;
        cons_gc_test(nil);
    }
    else
    {
// If something is not globally special it may still have been locally
// declared special, so I scan the environment. I clobber local declarations
// when I use them so that they do not get applied multiple times.
        for (w = local_decs1; w!=nil; w = qcdr(w))
        {   if (qcar(w) == var)
            {   qcar(w) = fixnum_of_int(0); // decl is used up
                env = acons(var, work_symbol, env);
                specenv = acons_no_gc(var, qvalue(var), specenv);
                qvalue(var) = val;
                cons_gc_test(nil);
                return;
            }
        }
// Finally simple lexical bindings use deep binding.
        env = acons(var, val, env);
    }
}

static inline LispObject next_arg()
{   LispObject r = qcar(arglist);
    arglist = qcdr(arglist);
    return r;
}

LispObject apply_lambda(LispObject def, LispObject args,
                        LispObject env1, LispObject name1)
// Here def is a lambda expression (sans the initial lambda) that is to
// be applied.  Much horrible messing about is needed so that I can cope
// with &optional and &rest args (including initialisers and supplied-p
// variables, also &key, &allow-other-keys and &aux).  Note the need to find
// any special declarations at the head of the body of the lambda-form.
{

// lambda-lists are parsed using a finite state engine with the
// following states, plus an exit state.
#define STATE_NULL     0        // at start and during regular args
#define STATE_OPT      1        // after &optional
#define STATE_OPT1     2        // after &optional + at least one var
#define STATE_REST     3        // immediately after &rest
#define STATE_REST1    4        // after &rest vv
#define STATE_KEY      5        // &key with no &rest
#define STATE_ALLOW    6        // &allow-other-keys
#define STATE_AUX      7        // &aux

    int opt_rest_state = STATE_NULL;
    int args_left = 0;
    for (LispObject u=args; u!=nil; u=qcdr(u)) args_left++;
    LispObject w1;
    if (!consp(def)) return onevalue(nil);    // Should never happen
    stackcheck4(def, args, env1, name1);
    w1 = qcar(def);
    push(args);                         // arglist
    push4(w1,                           // bvl
          qcdr(def),                    // body
          env1, name1);
    push5(nil, nil,                     // local_decs, ok_keys
          nil, nil, nil);               // restarg, specenv, val1
    push5(nil, nil,                     // arg, v1
          nil, nil, nil);               // v, p, w
// Now I am entitled to reference the names that resolve to the above
// stack offsets.
    for (;;)
    {   if (!consp(body)) break;
// I used to macroexpand things here in case a macro might expand into
// a DECLARE expression, but versions of the Common Lisp specification later
// than the one I originally looked at say that DECLARE may only appear
// directly and manifestly, so I can avoid that extra step.
        p = qcar(body);
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
// I keep going so that several DECLARE expressions one after the other will
// be supported. Note that the way I have coded this allows strings interleaved
// amongst the DECLARE expressions. I think that is not supposed to be
// permitted.
    }
// Next parse the BVL
    LispObject *stacksave = stack;
    try
    {   START_SETJMP_BLOCK;
        for (p = bvl; consp(p); p=qcdr(p))
        {   v = qcar(p);
            v1 = nil;
            arg = nil;
            val1 = nil;
// I can break from this switch statement with v a variable to bind
// and arg the value to bind to it, also v1 (if not nil) is a second
// variable to be bound (a supplied-p value) and val1 the value to bind it to.
// If I see &rest or &key the remaining actual args get collected into
// restarg, which takes the place of arg in some respects.
            switch (opt_rest_state)
            {   case STATE_NULL:
                    if (v == opt_key)
                    {   opt_rest_state = STATE_OPT;
                        continue;
                    }
                    if (v == rest_key)
                    {   restarg = arglist;
                        opt_rest_state = STATE_REST;
                        continue;
                    }
                    if (v == key_key)
                    {   restarg = arglist;
                        if (check_keyargs_even(restarg)) error(1, err_bad_keyargs, restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   if (args_left != 0) error(0, err_excess_args);
                        opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == allow_other_keys) error(1, err_bad_bvl, v);
                    if (args_left == 0) error(0, err_insufficient_args);
                    arg = next_arg(); // the simple case!
                    args_left--;
                    v1 = nil;       // no suppliedp mess here, I'm glad to say
                    break;

                case STATE_OPT:
                    if (v == opt_key
                        || v == rest_key
                        || v == key_key
                        || v == allow_other_keys
                        || v == aux_key
                       ) error(1, err_bad_bvl, v);
// Here v may be a simple variable, or a list (var init suppliedp)
                    opt_rest_state = STATE_OPT1;
                process_optional_parameter:
                    if (args_left != 0)
                    {   arg = next_arg();       // Arg available for optional
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
                    {   restarg = arglist;
                        opt_rest_state = STATE_REST;
                        continue;
                    }
                    if (v == key_key)
                    {   restarg = arglist;
                        if (check_keyargs_even(restarg)) error(1, err_bad_keyargs, restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   if (args_left != 0) error(0, err_excess_args);
                        opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == opt_key ||
                        v == allow_other_keys) error(1, err_bad_bvl, v);
                    goto process_optional_parameter;

                case STATE_REST:
                    if (v == opt_key
                        || v == rest_key
                        || v == key_key
                        || v == allow_other_keys
                        || v == aux_key
                       ) error(1, err_bad_bvl, v);
                    opt_rest_state = STATE_REST1;
                    arg = restarg;
                    break;

                case STATE_REST1:
                    if (v == key_key)
                    {   if (check_keyargs_even(restarg)) error(1, err_bad_keyargs, restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   opt_rest_state = STATE_AUX;
                        continue;
                    }
                    error(1, err_bad_bvl, rest_key);

                case STATE_KEY:
                    if (v == allow_other_keys)
                    {   opt_rest_state = STATE_ALLOW;
                        continue;
                    }
                    if (v == aux_key)
                    {   if (check_no_unwanted_keys(restarg, ok_keys))
                            error(1, err_bad_keyargs, restarg);
                        opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == opt_key || v == rest_key || v == key_key)
                        error(1, err_bad_bvl, v);
                process_keyword_parameter:
// v needs to expand to ((:kv v) init svar) in effect here.
                    {   LispObject keyname = nil;
                        w = nil;
                        if (!consp(v))
                        {   if (!is_symbol(v) || v==nil || v==lisp_true)
                                error(1, err_bad_bvl, v);
                            keyname = keywordify(v);
                        }
                        else
                        {   w = qcdr(v);
                            v = qcar(v);
                            if (!consp(v))
                            {   if (!is_symbol(v) || v==nil || v==lisp_true)
                                    error(1, err_bad_bvl, v);
                                keyname = keywordify(v);
                            }
                            else
                            {   keyname = qcar(v);
                                if (!is_symbol(keyname) || v==nil || v ==lisp_true)
                                    error(1, err_bad_bvl, v);
                                keyname = keywordify(keyname);
                                v = qcdr(v);
                                if (consp(v)) v = qcar(v);
                                else error(1, err_bad_bvl, v);
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
                        v == allow_other_keys) error(1, err_bad_bvl, v);
                    goto process_keyword_parameter;

                case STATE_AUX:
                    if (v == opt_key || v == rest_key ||
                        v == key_key || v == allow_other_keys ||
                        v == aux_key) error(1, err_bad_bvl, v);
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
            instate_binding(v, arg, local_decs);
            if (v1 != nil) instate_binding(v1, val1, local_decs);
        }   // End of for loop that scans BVL

// As well as local special declarations that have applied to bindings here
// there can be some that apply just to variable references within the body.
        while (local_decs!=nil)
        {   LispObject q = qcar(local_decs);
            local_decs=qcdr(local_decs);
            if (!is_symbol(q)) continue;
            env = acons(q, work_symbol, env);
        }

        switch (opt_rest_state)
        {   case STATE_NULL:
            case STATE_OPT1:        // Ensure there had not been too many args
                if (args_left != 0) error(0, err_excess_args);
                break;

            case STATE_OPT:         // error if bvl finishes here
            case STATE_REST:
                error(1, err_bad_bvl, opt_rest_state == STATE_OPT ? opt_key : rest_key);

            case STATE_KEY:         // ensure only valid keys were given
                if (check_no_unwanted_keys(restarg, ok_keys))
                    error(1, err_bad_keyargs, restarg);
                break;

            default:
//case STATE_REST1:
//case STATE_ALLOW:
//case STATE_AUX:
                break;
        }

// Now all the argument bindings have been performed - it remains to
// process the body of the lambda-expression.
        {   exit_count = 1;
            def = progn_fn(body, env);
            while (specenv != nil)
            {   LispObject bv = qcar(specenv);
                qvalue(qcar(bv)) = qcdr(bv);
                specenv = qcdr(specenv);
            }
        }
    }
    catch (LispException &e)
    {   stack = stacksave;
// On any exception raised above I will need to restore any fluid bindings
// that have been made.
        while (specenv != nil)
        {   LispObject bv = qcar(specenv);
            qvalue(qcar(bv)) = qcdr(bv);
            specenv = qcdr(specenv);
        }
        throw;
    }
    popv(stack_used);
// note that exit_count has not been disturbed since I called progn_fn,
// so the number of values that will be returned remains correctly
// established.
    return def;
}

// Get rid of the stack reference short names.

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

LispObject Leval(LispObject env, LispObject a)
{   save_current_function saver(eval_symbol);
    return eval(a, nil);     // Multiple values may be returned
}

LispObject Levlis(LispObject env, LispObject a)
{   STACK_SANITY;
    save_current_function saver(eval_symbol);
    LispObject r;
    stackcheck1(a);
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

// The Lisp-level APPLY functions could potentially confuse. What we have is
//
//   (APPLY fn a1 a2 .. an)
// The simple form of this is just (APPLY fn a1) where a1 is a list of
// all the arguments to be passed,. All the cases where more arguments are
// given behave rather like
//   (APPLY fn (LIST* a1 a2 ... an)).
// In my C code here these cases are Lapply_1, Lapply_2 etc.

LispObject Lapply_4up(LispObject env, LispObject fn, LispObject a1,
        LispObject a2, LispObject a3up)
{   STACK_SANITY;
    save_current_function saver(apply_symbol);
// Here I have something like
//   (APPLY fn a1 a2 (a3 a4 a5up))
// where a5up will be a list (a5 a6 ...).
    a3up = Lreverse(nil, a3up);
    a3up = nreverse2(qcdr(a3up), qcar(a3up));
// I have just flattened out the final argument.
    push(fn);
    a1 = list2star(a1, a2, a3up);
    pop(fn);
    return apply(fn, a1, nil, apply_symbol);
}

// This may look odd at first sight, but what is happening is that the
// basic case is (APPLY f arglist) where arglist is a list of arguments.
// As a concession (APPLY f) is treated as if it had been (APPLY f nil), ie
// no arguments are passed. For more arguments (APPLY f a1 a2 .. rest)
// treates all but the final argument as being individual actual arguments,
// and the last one passed is a list of extras.

LispObject Lapply_1(LispObject env, LispObject fn)
{   save_current_function saver(apply_symbol);
    return apply(fn, nil, nil, apply_symbol);
}

LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1)
{   save_current_function saver(apply_symbol);
    return apply(fn, a1, nil, apply_symbol);
}

LispObject Lapply_3(LispObject env, LispObject fn, LispObject a1, LispObject a2)
{   save_current_function saver(apply_symbol);
    push(fn);
    a1 = cons(a1, a2);
    pop(fn);
    return apply(fn, a1, nil, apply_symbol);
}

// Next I have (APPLY0 fn), (APPLY1 fn a1), (APPLY2 fr a1 a2) where the
// name of the function indicates the number of arguments to be involved.

LispObject Lapply0(LispObject env, LispObject fn)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (qfn0(fn))(fn);
    return Lapply_2(env, fn, nil);
}

LispObject Lapply1(LispObject env, LispObject fn, LispObject a1)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (qfn1(fn))(fn, a1);
    push2(env, fn);
    a1 = ncons(a1);
    pop2(fn, env);
    return Lapply_2(env, fn, a1);
}

LispObject Lapply2(LispObject env, LispObject fn,
        LispObject a1, LispObject a2)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (qfn2(fn))(fn, a1, a2);
    push2(env, fn);
    a1 = list2(a1, a2);
    pop2(fn, env);
    return Lapply_2(env, fn, a1);
}

LispObject Lapply3(LispObject env, LispObject fn,
        LispObject a1, LispObject a2, LispObject a3up)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
    {   LispObject a3 = arg4("apply3", a3up);
        return (qfn3(fn))(fn, a1, a2, a3);
    }
    LispObject a3 = arg4("apply3", a3up);
    push2(env, fn);
    a1 = list3(a1, a2, a3);
    pop2(fn, env);
    return Lapply_2(env, fn, a1);
}

// Finally I can have (FUNCALL fn a1 ...) which behaves like
// APPLY0, APPLY1,... for few arguments and continues passing more
// of its own arguments to the called function.

LispObject Lfuncall_1(LispObject env, LispObject fn)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (qfn0(fn))(fn);
    return Lapply_2(env, fn, nil);
}

LispObject Lfuncall_2(LispObject env, LispObject fn, LispObject a1)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (qfn1(fn))(fn, a1);
    push2(env, fn);
    a1 = ncons(a1);
    pop2(fn, env);
    return Lapply_2(env, fn, a1);
}

LispObject Lfuncall_3(LispObject env, LispObject fn,
        LispObject a1, LispObject a2)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (qfn2(fn))(fn, a1, a2);
    push2(env, fn);
    a1 = list2(a1, a2);
    pop2(fn, env);
    return Lapply_2(env, fn, a1);
}

LispObject Lfuncall_4up(LispObject env, LispObject fn,
        LispObject a1, LispObject a2, LispObject a3up)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
    {   if (qcdr(a3up) == nil) return (qfn3(fn))(fn, a1, a2, qcar(a3up));
        else return (qfn4up(fn))(fn, a1, a2, qcar(a3up), qcdr(a3up));
    }
    push2(env, fn);
    a1 = list2star(a1, a2, a3up);
    pop2(fn, env);
    return Lapply_2(env, fn, a1);
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
// Well the scheme indicated above favours leaf procedures and so is
// liable to clean up the C++-coded kernel a fair deal. But it looks to
// me as if for non-leaf things it is less help.

LispObject Lvalues_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   mv_2 = a2;
    mv_3 = a3;
// Because multiple-values get passed back in static storage there is
// a fixed upper limit to how many I can handle - truncate here to allow
// for that.
    int n = 3;
    for (int i=4; i<=50; i++)
    {   if (a4up == nil) break;
        workbase[i] = qcar(a4up);
        a4up = qcdr(a4up);
        n++;
    }
    return nvalues(a1, n);
}

LispObject Lvalues_3(LispObject env, LispObject a, LispObject b, LispObject c)
{   mv_2 = b;
    mv_3 = c;
    return nvalues(a, 3);
}

LispObject Lvalues_2(LispObject env, LispObject a, LispObject b)
{   mv_2 = b;
    return nvalues(a, 2);
}

LispObject Lvalues_1(LispObject env, LispObject a)
{   return onevalue(a);
}

LispObject Lvalues_0(LispObject env)
{   return nvalues(nil, 0);
}

LispObject mv_call_fn(LispObject args, LispObject env)
// Here with the rest of the interpreter rather than with other
// special forms because this is so closely related to APPLY.
//   (MULTIPLE-VALUE-CALL 'fn (values a1 a2)
//                            (values a3 a4 a5) a6 (values a7 a8))
// (for example) is rather like
//   (FUNCALL 'fn a1 a2 a3 a4 a5 a6 a7 a8)
{   STACK_SANITY;
    save_current_function saver(mv_call_symbol);
    if (!consp(args)) return nil;       // (multiple-value-call) => nil
    stackcheck2(args, env);
    push2(args, env);
    LispObject fn = qcar(args);
    fn = eval(fn, env);
    pop2(env, args);
    args = qcdr(args);
    push(fn);
    LispObject xargs = nil;             // for list of eventual args
    while (consp(args))
    {   LispObject r1;
        push3(args, env, xargs);
        r1 = qcar(args);
        exit_count = 1;
        r1  = eval(r1, env);
        if (exit_count != 0) stack[0] = cons(r1, stack[0]);
        for (unsigned int i=2; i<=exit_count; i++)
            stack[0] = cons((&work_0)[i], stack[0]);
        pop3(xargs, env, args);
        args = qcdr(args);
    }
    return apply(fn, xargs, env, mv_call_symbol);
}

LispObject interpreted_0(LispObject def)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    return apply_lambda(qenv(def), nil, nil, def);
}

LispObject interpreted_1(LispObject def, LispObject a1)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    push(def);
    a1 = ncons(a1);
    pop(def);
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject interpreted_2(LispObject def, LispObject a1, LispObject a2)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    push(def);
    a1 = list2(a1, a2);
    pop(def);
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject interpreted_3(LispObject def, LispObject a1, LispObject a2, LispObject a3)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    push(def);
    a1 = list3(a1, a2, a3);
    pop(def);
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject interpreted_4up(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    push(def);
    a1 = list3star(a1, a2, a3, a4up);
    pop(def);
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject funarged_0(LispObject def)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    def = qenv(def);
    return apply_lambda(qcdr(def), nil, qcar(def), qcdr(def));
}

LispObject funarged_1(LispObject def, LispObject a1)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    def = qenv(def);
    push(def);
    a1 = ncons(a1);
    pop(def);
    return apply_lambda(qcdr(def), a1, qcar(def), qcdr(def));
}

LispObject funarged_2(LispObject def, LispObject a1, LispObject a2)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    def = qenv(def);
    push(def);
    a1 = list2(a1, a2);
    pop(def);
    return apply_lambda(qcdr(def), a1, qcar(def), qcdr(def));
}

LispObject funarged_3(LispObject def, LispObject a1, LispObject a2, LispObject a3)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    def = qenv(def);
    push(def);
    a1 = list3(a1, a2, a3);
    pop(def);
    return apply_lambda(qcdr(def), a1, qcar(def), qcdr(def));
}

LispObject funarged_4up(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck1(def);
    def = qenv(def);
    push(def);
    a1 = list3star(a1, a2, a3, a4up);
    pop(def);
    return apply_lambda(qcdr(def), a1, qcar(def), qcdr(def));
}

static LispObject macroexpand_1(LispObject form, LispObject env)
{   // The environment here seems only necessary for macrolet
    STACK_SANITY;
    LispObject done;
    LispObject f;
    stackcheck2(form, env);
    done = nil;
    if (consp(form))
    {   f = qcar(form);
// look for local macro definitions
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
                    push(env);
                    w = cons(lambda, w);
                    w = list3(w, stack[-1], nil);
                    pop(env);
                    on_backtrace(
                        p = apply(qvalue(macroexpand_hook),
                                  w,
                                  env,
                                  macroexpand_hook),
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
// If there is no local macro definition I need to look for a global one
        if (symbolp(f) && (qheader(f) & SYM_MACRO) != 0)
        {   done = qvalue(macroexpand_hook);
            if (done == unset_var)
                error(1, err_macroex_hook, macroexpand_hook);
            push3(form, env, done);
            f = cons(lambda, qenv(f));
            pop3(done, env, form);
            push2(done, env);
            f = list3(f, form, env);
            pop2(env, done);
            form = apply(done,
                         f,
                         env,
                         macroexpand_hook);
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
    stackcheck2(form, env);
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

// To make something autoloadable I should set the environment cell to
//    (name-of-self module-name-1 module-name-2 ...)
// and when invoked the function will do a load-module on each of the
// modules specified and then re-attempt to call.  Loading the
// modules is expected to establish a proper definition for the
// function involved.

LispObject autoload_0(LispObject fname)
{   STACK_SANITY;
    fname = qenv(fname);
    push(qcar(fname));
    set_fns(qcar(fname), undefined_0, undefined_1, undefined_2, undefined_3, undefined_4up);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop(fname);
    return apply(fname, nil, nil, autoload_symbol);
}

LispObject autoload_1(LispObject fname, LispObject a1)
{   STACK_SANITY;
    fname = qenv(fname);
    push2(qcar(fname), a1);
    set_fns(qcar(fname), undefined_0, undefined_1, undefined_2, undefined_3, undefined_4up);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop(a1);
    a1 = ncons(a1);
    pop(fname);
    return apply(fname, a1, nil, autoload_symbol);
}

LispObject autoload_2(LispObject fname, LispObject a1, LispObject a2)
{   STACK_SANITY;
    fname = qenv(fname);
    push3(qcar(fname), a1, a2);
    set_fns(qcar(fname),  undefined_0, undefined_1, undefined_2, undefined_3, undefined_4up);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop2(a2, a1);
    a1 = list2(a1, a2);
    pop(fname);
    return apply(fname, a1, nil, autoload_symbol);
}

LispObject autoload_3(LispObject fname, LispObject a1, LispObject a2, LispObject a3)
{   STACK_SANITY;
    fname = qenv(fname);
    push4(qcar(fname), a1, a2, a3);
    set_fns(qcar(fname),  undefined_0, undefined_1, undefined_2, undefined_3, undefined_4up);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop3(a3, a2, a1);
    a1 = list3(a1, a2, a3);
    pop(fname);
    return apply(fname, a1, nil, autoload_symbol);
}

LispObject autoload_4up(LispObject fname, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   STACK_SANITY;
    fname = qenv(fname);
    push5(fname, a1, a2, a3, a4up);
    set_fns(qcar(fname),  undefined_0, undefined_1, undefined_2, undefined_3, undefined_4up);
    qenv(qcar(fname)) = qcar(fname);
    fname = qcdr(fname);
    while (consp(fname))
    {   push(qcdr(fname));
        Lload_module(nil, qcar(fname));
        pop(fname);
    }
    pop4(a4up, a3, a2, a1);
    a1 = list3star(a1, a2, a3, a4up);
    pop(fname);
    return apply(fname, a1, nil, autoload_symbol);
}

LispObject undefined_0(LispObject fname)
{
    error(1, err_undefined_function_0, fname);
}

LispObject undefined_1(LispObject fname, LispObject)
{
// It would be perfectly possible to grab and save the args here, and retry
// the function call after error has patched things up.  Again
// this entrypoint is for compiled code calling something that is undefined,
// and so no lexical environment is needed.
    error(1, err_undefined_function_1, fname);
}

LispObject undefined_2(LispObject fname, LispObject, LispObject)
{   error(1, err_undefined_function_2, fname);
}

LispObject undefined_3(LispObject fname, LispObject, LispObject, LispObject)
{   error(1, err_undefined_function_3, fname);
}

LispObject undefined_4up(LispObject fname,
                      LispObject, LispObject, LispObject, LispObject)
{   error(1, err_undefined_function_4up, fname);
}

// The next few functions allow me to create variants on things! The
// entrypoint fX_as_Y goes in the function cell of a symbol, and the name
// of a function with Y arguments goes in is environment cell. The result will
// be a function that accepts X arguments and discards all but the first Y of
// them, then chains to the other function. The purpose is to support good
// compilation of things like
//   (de funny_equal (a b c) (equal a b))

LispObject f0_as_0(LispObject env)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn0(env))(env);
}

LispObject f1_as_0(LispObject env, LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn0(env))(env);
}

LispObject f2_as_0(LispObject env, LispObject, LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn0(env))(env);
}

LispObject f3_as_0(LispObject env, LispObject, LispObject, LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn0(env))(env);
}

LispObject f1_as_1(LispObject env, LispObject a)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn1(env))(env, a);
}

LispObject f2_as_1(LispObject env, LispObject a, LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn1(env))(env, a);
}

LispObject f3_as_1(LispObject env, LispObject a1, LispObject, LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn1(env))(env, a1);
}

LispObject f2_as_2(LispObject env, LispObject a, LispObject b)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn2(env))(env, a, b);
}

LispObject f3_as_2(LispObject env, LispObject a1, LispObject a2, LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn2(env))(env, a1, a2);
}

LispObject f3_as_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn3(env))(env, a1, a2, a3);
}

// The next function is EXPERIMENTAL and is only available if there is
// a "fork" function available. It is probably only even partially useful
// if the operating system and libraries used implement that using a
// "copy on write" strategy. This is the case with Linux, and I believe it to
// be so in MacOSX. But Windows does not provide that sort of functionality
// comfortably, so this stuff will not be available there. Observe that I
// make fairly extreme use of the autoconf detection stuff to try to avoid
// trying this where it might not make sense!

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
// This converts an arbitrary result into a string so I can pass it back.
    int32_t i, len, ok = 1;
// Cyclic and re-entrant structures could lead to failure here, and
// uninterned symbols (eg gensyms) will not be coped with very well. But
// SIMPLE data types should all be safe.
    if_error(r = Lexplode(nil, r),
             // Error handler
             strcpy(shared, "Failed");
             exit(2));
    if_error(r = Llist_to_string(nil, r),
             // Error handler
             strcpy(shared, "Failed");
             exit(3));
    len = length_of_byteheader(vechdr(r)) - CELL;
// If the displayed form ou the output was too long I just truncate it
// at present. A more agressive attitude would be to count that as a form
// of failure. As an intermediate step I use the first character in my
// buffer as an "overflow flag" and leave a blank in it if all is well.
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
// Create an identifier for a private shared segment of memory of size
// 2*PARSIZE. This will be used for passing a result from the sub-task
// to the main one. Give up if such a segment can not be allocated.
    int status, segid = shmget(IPC_PRIVATE, (size_t)(2*PARSIZE),
                               IPC_CREAT | S_IRUSR | S_IWUSR);
    char *shared, *w;
    int overflow;
    LispObject r;
    if (segid == -1) aerror("Unable to allocate a shared segment");
// Attach to the shared segment to obtain a memory address via which it can be
// accessed. Again raise an error if this fails.
    shared = (char *)shmat(segid, NULL, 0);
    if (shared == (char *)(-1))
        aerror("Unable to attach to shared segment");
// the shared segment is set up to contain null strings in the two places
// where it might be used to hold return values.
    shared[0] = shared[PARSIZE] = 0;
// Split off a clone of the current process that can be used to do the
// first evaluation. If this succeeds call a(b, nil) in it. Note that
// processes created via "fork" inherit shared memory segments from their
// parent.
    pid1 = fork();
    if (pid1 < 0)     // Task not created, must tidy up.
    {   shmdt(shared);
        shmctl(segid, IPC_RMID, 0);
        aerror("Fork 1 failed");
    }
    else if (pid1 == 0)
    {   // TASK 1 created OK
        LispObject r1;
        if_error(r1 = Lapply2(nil, a, b, nil),
// If the evaluation failed I will exit indicating a failure.
                 strcpy(shared, "Failed");
                 exit(1));
// Write result from first task into the first half of the shared memory block.
        write_result(nil, r1, shared);
// Exiting from the sub-task would in fact detach from the shared data
// segment, but I do the detaching explictly to feel tidy.
        shmdt(shared);
        exit(0);
    }
    else
    {
// This is the continuation of the main process. Create a second task in
// much the same way.
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
            if_error(r2 = Lapply2(nil, a, b, lisp_true),
                     // Error handler
                     strcpy(shared, "Failed");
                     exit(1));
            write_result(nil, r2, shared+PARSIZE);
            shmdt(shared);
            exit(0);
        }
        else
        {
// Wait for whichever of the two sub-tasks finishes first. Then kill the
// other one, and return the result left by the winner.
            pidx = wait(&status);
//          term_printf("First signal was from task %d\n", pidx);
            if (!WIFEXITED(status) ||
                WEXITSTATUS(status) != 0)
            {
// If the first task to complete in fact failed rather than exited cleanly
// I will count it as an overall failure and cancel everything. This
// covers aborting (in which case WIFEXITED will return false) or
// exiting cleanly but with a non-zero return code.
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
// If the first character of the buffer is a blank then there was no
// overflow and all is well.
            if (w[0] == ' ') r = read_from_vector(w + 1);
            else
            {   overflow = -overflow;
                r = make_string(w + 1);
            }
// Need to tidy up the shared segment at the end.
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

// This is intended for use when debugging!
// (show-stack m n) displays stack locations from m to n (inclusive)
// where the top item on the stack has number 0.
// (show-stack n) is equivalent to (show-stack 0 n)
// (show-stack) is equivalent to (show-stack 0 0), ie it shows just the
// top item on the stack.
// If m > n then this just reports stack depth.
// This will refuse to handle arguments larger than 100.

LispObject Lshow_stack_2(LispObject env, LispObject a1, LispObject a2)
{   int m = 0, n = 0;
    if (is_fixnum(a1))
    {   m = int_of_fixnum(a1);
        if (m < 0 || m > 100) m = 0;
    }
    if (is_fixnum(a2))
    {   n = int_of_fixnum(a2);
        if (n > 100) n = m+10;
    }
    term_printf("Stack depth %d\n", (int)(stack-stackbase));
    for (int i=m; i<=n; i++)
    {   term_printf("%d: ", i);
        prin_to_terminal(stack[-i]);
        term_printf("\n");
    }
    return onevalue(nil);
}

LispObject Lshow_stack_1(LispObject env, LispObject a1)
{   return Lshow_stack_2(env, fixnum_of_int(0), a1);
}

LispObject Lshow_stack_0(LispObject env)
{   return Lshow_stack_2(env, fixnum_of_int(0), fixnum_of_int(0));
}

setup_type const eval1_setup[] =
{   {"bytecounts",              Lbytecounts_0, Lbytecounts_1, G2Wother, G3Wother, G4Wother},
    {"idapply",                 G0Wother, Lapply_1, Lapply_2, Lapply_3, Lapply_4up},
    {"eval",                    G0W1, Leval, G2W1, G3W1, G4W1},
    {"apply",                   G0Wother, Lapply_1, Lapply_2, Lapply_3, Lapply_4up},
    {"apply0",                  G0W1, Lapply0, G2W1, G3W1, G4W1},
    {"apply1",                  G0W2, G1W2, Lapply1, G3W2, G4W2},
    {"apply2",                  G0W3, G1W3, G2W3, Lapply2, G4W3},
    {"apply3",                  G0W4up, G1W4up, G2W4up, G3W4up, Lapply3},
    {"evlis",                   G0W1, Levlis, G2W1, G3W1, G4W1},
    {"funcall",                 G0Wother, Lfuncall_1, Lfuncall_2, Lfuncall_3, Lfuncall_4up},
    {"funcall*",                G0Wother, Lfuncall_1, Lfuncall_2, Lfuncall_3, Lfuncall_4up},
    {"parallel",                G0W2, G1W2, Lparallel, G3W2, G4W2},
    {"sleep",                   G0W1, Lsleep, G2W1, G3W1, G4W1},
    {"values",                  Lvalues_0, Lvalues_1, Lvalues_2, Lvalues_3, Lvalues_4up},
    {"macroexpand",             G0Wother, Lmacroexpand, Lmacroexpand_2, G3W1, G4W1},
    {"macroexpand-1",           G0Wother, Lmacroexpand_1, Lmacroexpand_2, G3Wother, G4Wother},
    {"show-stack",              Lshow_stack_0, Lshow_stack_1, Lshow_stack_2, G3Wother, G4Wother},
    {NULL,                      0, 0, 0, 0, 0}
};

// end of eval1.cpp
