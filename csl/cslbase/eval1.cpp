// eval1.cpp                               Copyright (C) 1989-2025 Codemist

//
// Interpreter (part 1).
//

/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

LispObject nreverse(LispObject a)
{   LispObject b = nil;
    while (consp(a))
    {   LispObject c = a;
        a = cdr(a);
        cdr(c) =  b;
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
{   if (time_limit >= 0 &&
        read_clock()/1000 > (std::uint64_t)time_limit) resource_exceeded();
    STACK_SANITY;
    assert (env == nil || consp(env));
#ifdef DEBUG
    if (is_exception(u) || is_exception(env)) my_abort("exception value not trapped");
#endif // DEBUG
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__)) return aerror("deep stack in eval");
#endif
restart:
    int t = static_cast<int>(u) & TAG_BITS;
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
        if ((h & SYM_KEYWORD_VAR) != 0) return nvalues(qvalue(u), 1);
// If a symbol is not global or fluid then it ought to be bound locally,
// ir mentioned in the environment. This can include as a special case it
// being subject to a local declaration that it is global! This is
// "deep binding".
        else
        {   while (consp(env))
            {   LispObject p = car(env);
                if (car(p) == u)
                {   LispObject v =cdr(p);
// If a variable is lexically bound to the value work_symbol that means
// that the symbol has been (lexically) declared to be special, so its
// value cell should be inspected.
                    if (v == work_symbol)
                    {   v = qvalue(u);
// I will trigger the "unset variable" message if a variable is declared
// locally global but did not have a global value set.
                        if (v == unset_var) return error(1, err_unset_var, u);
                    }
                    return nvalues(v, 1);
                }
                env = cdr(env);
            }
// If a symbol has not been declared FLUID or GLOBAL and is not lovally
// bound then if I was feeling really cautious I would raise an error
// explaining that it should not be accessed. But that feels MEAN, and
// so I will treat it as if it had been made locally global. I COULD force
// it to be globally fluid here. There is a balance that has to be struck
// between error detection and convenience for the informal user!
            {   LispObject v = qvalue(u);
                if (v == unset_var) return error(1, err_unset_var, u);
                else return nvalues(v, 1);
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
    else if (t != TAG_CONS || u == nil) return nvalues(u, 1);
    else
    {
// The final case is that of a list (fn ...), and one case that has to
// be checked is if fn is lexically bound.
        LispObject fn, args;
        stackcheck();
        errexit();
        fn = car(u);
        args = cdr(u);
// Local function bindings must be looked for first. Well Standard Lisp
// does not have local function bindings, but Common Lisp does - hence the
// extra "fun" here.
        {   LispObject p;
            if (is_symbol(fn)) // can only be a local function if atomic.
                for (p=env; consp(p); p=cdr(p))
                {   LispObject w = car(p);
// The form (<list> . sym) is used in an environment to indicate a local
// binding of a function, either as a regular function or as a macro
// (i.e. flet or macrolet).  The structure of the list distinguishes
// between these two cases.
                    if (cdr(w) == fn && is_cons(w = car(w)) && w!=nil)
                    {   p = car(w);
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
                        on_backtrace(
                            w = cons(lambda, w);
                            errexit();
                            p = apply(qvalue(macroexpand_hook),
                                      list3(w, u, nil),
                                      nil,
                                      macroexpand_hook),
                            // now the error handler
                            if (SHOW_FNAME)
                            {   err_printf("\nMacroexpanding: ");
                                loop_print_error(u);
                            });
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
                assert(qfn1(fn) != nullptr);
                return (*qfn1(fn))(args, env);
            }
            else if (h & SYM_MACRO)
            {   STACK_SANITY;
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
                    if (SHOW_FNAME)
                    {   err_printf("\nMacroexpanding: ");
                        loop_print_error(u);
                    });
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
        {   if (!consp(args))
            {   RECORD_CALL(ncons(fn));
                return (*qfn0(fn))(fn);
            }
            LispObject a1 = car(args);
            {   on_backtrace(a1 = eval(a1, env),
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(car(args));
                    });
            }
            args = cdr(args);
            if (!consp(args))
            {   RECORD_CALL(list2(fn, a1));
                return (*qfn1(fn))(fn, a1);
            }
            LispObject a2 = car(args);
            {   on_backtrace(
                    a2 = eval(a2, env),
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(car(args));
                    });
            }
            args = cdr(args);
            if (!consp(args))
            {   RECORD_CALL(list3(fn, a1, a2));
                return (*qfn2(fn))(fn, a1, a2);
            }
            LispObject a3 = car(args);
            {   on_backtrace(
                    a3 = eval(a3, env),
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(car(args));
                    });
            }
            args = cdr(args);
            if (!consp(args))
            {   RECORD_CALL(list4(fn, a1, a2, a3));
                return (*qfn3(fn))(fn, a1, a2, a3);
            }
            eargs = list3(a3, a2, a1);
            errexit();
        }
// I have evaluated the first 3 args if the function was a symbol, so
// now I process the rest.
        {   STACK_SANITY1(u);
            while (consp(args))
            {   LispObject w;
                w = car(args);
                on_backtrace(
                    w = eval(w, env),
                    // Now the error handler
                    if (SHOW_ARGS)
                    {   err_printf("\nEvaluating: ");
                        loop_print_error(car(args));
                    });
                eargs = cons(w, eargs);
                errexit();
                args = cdr(args);
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

static bool check_no_unwanted_keys(LispObject restarg,
                                   LispObject ok_keys)
// verify that there were no unwanted keys in the actual arg list
{   bool odd_key_found = false;
    while (restarg!=nil)
    {   LispObject k = car(restarg);
        LispObject w;
        for (w=ok_keys; w!=nil; w=cdr(w))
            if (k == car(w)) goto is_ok;
        odd_key_found = true;
    is_ok:
        restarg = cdr(restarg);
        if (restarg==nil) return true;  // odd length list
        if (k == allow_key_key &&
            car(restarg) != nil) return false; // OK
        restarg = cdr(restarg);
    }
    return odd_key_found;
}

static bool check_keyargs_even(LispObject restarg)
// check that list is even length with alternate items symbols in
// the keyword package. Return true in BAD case.
{   while (restarg!=nil)
    {   LispObject q = car(restarg);
        if (!is_symbol(q) || qpackage(q) != qvalue(keyword_package))
            return true;
        restarg = cdr(restarg);
        if (restarg==nil) return true;      // Odd length is wrong
        restarg = cdr(restarg);
    }
    return false;                           // OK
}

static LispObject keywordify(LispObject v)
{   LispObject name = get_pname(v);
#ifdef COMMON
    return Lintern_2(nil, name, qvalue(keyword_package));
#else
// For Standard Lisp I will force a ":" as the first character of the
// name, and than tag it as a "keyword".
    if (basic_celt(name, 0) != ':')
    {   v = Lexplode(nil, v);
        errexit();
        v = list2star(fixnum_of_int('!'), fixnum_of_int(':'), v);
        errexit();
        v = Lcompress(nil, v);
        errexit();
    }
    Lmake_keyword(nil, v);
    return v;
#endif
}

static LispObject key_lookup(LispObject keyname, LispObject args)
{   while (args!=nil)
    {   LispObject next = cdr(args);
        if (next==nil) return nil;
        if (car(args) == keyname) return next;
        else args = cdr(next);
    }
    return nil;
}



inline LispObject instate_binding(LispObject var, LispObject val,
                                  LispObject local_decs1,
                                  LispObject &env, LispObject &specenv,
                                  LispObject &w)
{   Header h;
// Complain if the varianble that somebody is attempting to bind seems bad.
    if (!is_symbol(var) || (qheader(var) & SYM_GLOBAL_VAR)!=0)
        return error(1, err_bad_bvl, var);
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
        errexit();
    }
    else
    {
// If something is not globally special it may still have been locally
// declared special, so I scan the environment. I clobber local declarations
// when I use them so that they do not get applied multiple times.
        for (w = local_decs1; w!=nil; w = cdr(w))
        {   if (car(w) == var)
            {   car(w) = fixnum_of_int(0); // decl is used up
                env = acons(var, work_symbol, env);
                errexit();
                specenv = acons_no_gc(var, qvalue(var), specenv);
                qvalue(var) = val;
                cons_gc_test(nil);
                errexit();
            }
        }
// Finally simple lexical bindings use deep binding.
        env = acons(var, val, env);
    }
    return nil;
}

// arglist is in fact a value on the Lisp stack.

inline LispObject next_arg(LispObject &arglist)
{   LispObject r = car(arglist);
    arglist = cdr(arglist);
    return r;
}

LispObject apply_lambda(LispObject def, LispObject args,
                        LispObject env1, LispObject name1)
// Here def is a lambda expression (sans the initial lambda) that is to
// be applied.  Much horrible messing about is needed so that I can cope
// with &optional and &rest args (including initialisers and supplied-p
// variables, also &key, &allow-other-keys and &aux).  Note the need to find
// any special declarations at the head of the body of the lambda-form.
// Much of the reall mess here is because I am supporting features that
// Common Lisp introduced but that my use of Lisp does not actually use!
//
// The final argument "name1" may be used in backtrces of otherwise for
// debugging: when you are calling an interpreted function it may be the
// name of that function and if you are applying a free-standing lambda
// expression it may be the whole expression. At present it is not used.
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
    for (LispObject u=args; u!=nil; u=cdr(u)) args_left++;
    LispObject w1;
    if (!consp(def)) return nvalues(nil,1);    // Should never happen
    stackcheck();
    w1 = car(def);
// The next fragment is horrible but is here because at present I have a
// precise garbage collector and all the values set up here need to act
// as list-bases.
    RealSave save(args,                        // arglist
                  w1,                          // bvl
                  cdr(def),                    // body
                  env1,
                  name1,
                  PushCount(10));
    LispObject &arglist    = save.val(1);
    LispObject &bvl        = save.val(2);
    LispObject &body       = save.val(3);
    LispObject &env        = save.val(4);
//  LispObject &name       = save.val(5);    // not used at present!
    LispObject &local_decs = save.val(6);
    LispObject &ok_keys    = save.val(7);
    LispObject &restarg    = save.val(8);
    LispObject &specenv    = save.val(9);
    LispObject &val1       = save.val(10);
    LispObject &arg        = save.val(11);
    LispObject &v1         = save.val(12);
    LispObject &v          = save.val(13);
    LispObject &p          = save.val(14);
    LispObject &w          = save.val(15);
    for (;;)
    {   if (!consp(body)) break;
// I used to macroexpand things here in case a macro might expand into
// a DECLARE expression, but versions of the Common Lisp specification later
// than the one I originally looked at say that DECLARE may only appear
// directly and manifestly, so I can avoid that extra step.
        p = car(body);
        body = cdr(body);
        if (!consp(p))
        {   if (stringp(p) &&
                consp(body)) continue; // string is comment here.
            body = cons(p, body);  // other atoms get stuck back on body.
            break;
        }
        if (car(p) != declare_symbol)
        {   body = cons(p, body);  // something other than a "declare".
            errexit();
            break;
        }
// I have found a body that was initially something like
//   ("string" "string" (declare ...) ...)
// and I have discarded the strings and here p is the part that starts
// with the symbol DECLARE.
        for (v = cdr(p); consp(v); v = cdr(v))
        {   v1 = car(v);
// scan looking for (SPECIAL ...)
            if (!consp(v1) || car(v1) != special_symbol) continue;
            // here v1 says (special ...)
            for (v1=cdr(v1); consp(v1); v1 = cdr(v1))
            {   local_decs = cons(car(v1), local_decs);
                errexit();
            }
        }
// I keep going so that several DECLARE expressions one after the other will
// be supported. Note that the way I have coded this allows strings interleaved
// amongst the DECLARE expressions. I think that is not supposed to be
// permitted.
    }
// Next parse the BVL
    TRY
        for (p = bvl; consp(p); p=cdr(p))
        {   v = car(p);
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
                        if (check_keyargs_even(restarg)) return error(1, err_bad_keyargs, restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   if (args_left != 0) return error(0, err_excess_args);
                        opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == allow_other_keys) return error(1, err_bad_bvl, v);
                    if (args_left == 0) return error(0, err_insufficient_args);
                    arg = next_arg(arglist); // the simple case!
                    args_left--;
                    v1 = nil;       // no suppliedp mess here, I'm glad to say
                    break;

                case STATE_OPT:
                    if (v == opt_key
                        || v == rest_key
                        || v == key_key
                        || v == allow_other_keys
                        || v == aux_key
                       ) return error(1, err_bad_bvl, v);
// Here v may be a simple variable, or a list (var init suppliedp)
                    opt_rest_state = STATE_OPT1;
                process_optional_parameter:
                    if (args_left != 0)
                    {   arg = next_arg(arglist);       // Arg available for optional
                        args_left--;
                        val1 = lisp_true;
                    }
                    else
                    {   arg = nil;
                        val1 = nil;
                    }
                    v1 = nil;
                    if (!consp(v)) break;       // Simple case
                    {   w = cdr(v);
                        v = car(v);
                        if (!consp(w)) break;   // (var)
                        if (val1 == nil)        // use the init form
                        {   arg = car(w);
                            arg = eval(arg, env);
                            errexit();
                        }
                        w = cdr(w);
                        if (consp(w)) v1 = car(w); // suppliedp name
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
                        if (check_keyargs_even(restarg)) return error(1, err_bad_keyargs, restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   if (args_left != 0) return error(0, err_excess_args);
                        opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == opt_key ||
                        v == allow_other_keys) return error(1, err_bad_bvl, v);
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
                    {   if (check_keyargs_even(restarg)) return error(1, err_bad_keyargs,
                                                                   restarg);
                        opt_rest_state = STATE_KEY;
                        continue;
                    }
                    if (v == aux_key)
                    {   opt_rest_state = STATE_AUX;
                        continue;
                    }
                    return error(1, err_bad_bvl, rest_key);

                case STATE_KEY:
                    if (v == allow_other_keys)
                    {   opt_rest_state = STATE_ALLOW;
                        continue;
                    }
                    if (v == aux_key)
                    {   if (check_no_unwanted_keys(restarg, ok_keys))
                            return error(1, err_bad_keyargs, restarg);
                        opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == opt_key || v == rest_key || v == key_key)
                        return error(1, err_bad_bvl, v);
                process_keyword_parameter:
// v needs to expand to ((:kv v) init svar) in effect here.
                    {   LispObject keyname = nil;
                        w = nil;
                        if (!consp(v))
                        {   if (!is_symbol(v) || v==nil || v==lisp_true)
                                return error(1, err_bad_bvl, v);
                            keyname = keywordify(v);
                            errexit();
                        }
                        else
                        {   w = cdr(v);
                            v = car(v);
                            if (!consp(v))
                            {   if (!is_symbol(v) || v==nil || v==lisp_true)
                                    return error(1, err_bad_bvl, v);
                                keyname = keywordify(v);
                                errexit();
                            }
                            else
                            {   keyname = car(v);
                                if (!is_symbol(keyname) || v==nil || v ==lisp_true)
                                    return error(1, err_bad_bvl, v);
                                keyname = keywordify(keyname);
                                errexit();
                                v = cdr(v);
                                if (consp(v)) v = car(v);
                                else return error(1, err_bad_bvl, v);
                            }
                        }
                        ok_keys = cons(keyname, ok_keys);
                        arg = key_lookup(car(ok_keys), restarg);
                        errexit();
                        if (arg == nil) val1 = nil;
                        else
                        {   arg = car(arg);
                            val1 = lisp_true;
                        }
                        v1 = nil;
                        if (!consp(w)) break;   // (var)
                        if (val1 == nil)        // use the init form
                        {   arg = car(w);
                            arg = eval(arg, env);
                            errexit();
                        }
                        w = cdr(w);
                        if (consp(w)) v1 = car(w); // suppliedp name
                        break;
                    }

                case STATE_ALLOW:
                    if (v == aux_key)
                    {   opt_rest_state = STATE_AUX;
                        continue;
                    }
                    if (v == opt_key || v == rest_key || v == key_key ||
                        v == allow_other_keys) return error(1, err_bad_bvl, v);
                    goto process_keyword_parameter;

                case STATE_AUX:
                    if (v == opt_key || v == rest_key ||
                        v == key_key || v == allow_other_keys ||
                        v == aux_key) return error(1, err_bad_bvl, v);
                    if (consp(v))
                    {   w = cdr(v);
                        v = car(v);
                        if (consp(w))
                        {   arg = car(w);
                            arg = eval(arg, env);
                            errexit();
                        }
                    }
                    else arg = nil;
                    v1 = nil;
                    break;
            }
            instate_binding(v, arg, local_decs, env, specenv, w);
            errexit();
            if (v1 != nil)
            {   instate_binding(v1, val1, local_decs, env, specenv, w);
                errexit();
            }
        }   // End of for loop that scans BVL

// As well as local special declarations that have applied to bindings here
// there can be some that apply just to variable references within the body.
        while (local_decs!=nil)
        {   LispObject q = car(local_decs);
            local_decs=cdr(local_decs);
            if (!is_symbol(q)) continue;
            env = acons(q, work_symbol, env);
            errexit();
        }

        switch (opt_rest_state)
        {   case STATE_NULL:
            case STATE_OPT1:        // Ensure there had not been too many args
                if (args_left != 0) return error(0, err_excess_args);
                break;

            case STATE_OPT:         // error if bvl finishes here
            case STATE_REST:
                return error(1, err_bad_bvl,
                      opt_rest_state == STATE_OPT ? opt_key : rest_key);

            case STATE_KEY:         // ensure only valid keys were given
                if (check_no_unwanted_keys(restarg, ok_keys))
                    return error(1, err_bad_keyargs, restarg);
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
            errexit();
            while (specenv != nil)
            {   LispObject bv = car(specenv);
                qvalue(car(bv)) = cdr(bv);
                specenv = cdr(specenv);
            }
        }
    CATCH(LispException)
// On any exception raised above I will need to restore any fluid bindings
// that have been made.
        while (specenv != nil)
        {   LispObject bv = car(specenv);
            qvalue(car(bv)) = cdr(bv);
            specenv = cdr(specenv);
        }
        RETHROW;
    END_CATCH;
// note that exit_count has not been disturbed since I called progn_fn,
// so the number of values that will be returned remains correctly
// established.
    return def;
}

LispObject Leval(LispObject env, LispObject a)
{   save_current_function saver(eval_symbol);
    return eval(a, nil);     // Multiple values may be returned
}

LispObject Levlis(LispObject env, LispObject a)
{   SingleValued fn;
    STACK_SANITY;
    save_current_function saver(eval_symbol);
    LispObject r;
    stackcheck();
    errexit();
    r = nil;
    while (consp(a))
    {   {   LispObject a1;
            {   a1 = car(a);
                a1 = eval(a1, nil);
                errexit();
            }
            r = cons(a1, r);
            errexit();
        }
        a = cdr(a);
    }
    return nreverse(r);
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
    errexit();
    a3up = nreverse2(cdr(a3up), car(a3up));
// I have just flattened out the final argument.
    a1 = list2star(a1, a2, a3up);
    errexit();
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

LispObject Lapply_3(LispObject env, LispObject fn, LispObject a1,
                    LispObject a2)
{   save_current_function saver(apply_symbol);
    a1 = cons(a1, a2);
    errexit();
    return apply(fn, a1, nil, apply_symbol);
}

// Next I have (APPLY0 fn), (APPLY1 fn a1), (APPLY2 fr a1 a2) where the
// name of the function indicates the number of arguments to be involved.

LispObject Lapply0(LispObject env, LispObject fn)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (*qfn0(fn))(fn);
    return Lapply_2(env, fn, nil);
}

LispObject Lapply1(LispObject env, LispObject fn, LispObject a1)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (*qfn1(fn))(fn, a1);
    a1 = ncons(a1);
    errexit();
    return Lapply_2(env, fn, a1);
}

LispObject Lapply2(LispObject env, LispObject fn,
                   LispObject a1, LispObject a2)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (*qfn2(fn))(fn, a1, a2);
    a1 = list2(a1, a2);
    errexit();
    return Lapply_2(env, fn, a1);
}

LispObject Lapply3(LispObject env, LispObject fn,
                   LispObject a1, LispObject a2, LispObject a3up)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
    {   LispObject a3 = arg4("apply3", a3up);
        return (*qfn3(fn))(fn, a1, a2, a3);
    }
    LispObject a3 = arg4("apply3", a3up);
    a1 = list3(a1, a2, a3);
    errexit();
    return Lapply_2(env, fn, a1);
}

LispObject Lapply4(LispObject env, LispObject fn,
                   LispObject a1, LispObject a2, LispObject a3up)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
    {   LispObject a3, a4;
        if (a4a5("apply4", a3up, a3, a4)) return nil;
        return (*qfn4up(fn))(fn, a1, a2, a3, cdr(a3up));
    }
    LispObject a3, a4;
    if (a4a5("apply3", a3up, a3, a4)) return nil;
    a1 = list4(a1, a2, a3, a4);
    errexit();
    return Lapply_2(env, fn, a1);
}

// Finally I can have (FUNCALL fn a1 ...) which behaves like
// APPLY0, APPLY1,... for few arguments and continues passing more
// of its own arguments to the called function.

LispObject Lfuncall_1(LispObject env, LispObject fn)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (*qfn0(fn))(fn);
    return Lapply_2(env, fn, nil);
}

LispObject Lfuncall_2(LispObject env, LispObject fn, LispObject a1)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (*qfn1(fn))(fn, a1);
    a1 = ncons(a1);
    errexit();
    return Lapply_2(env, fn, a1);
}

LispObject Lfuncall_3(LispObject env, LispObject fn,
                      LispObject a1, LispObject a2)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
        return (*qfn2(fn))(fn, a1, a2);
    a1 = list2(a1, a2);
    errexit();
    return Lapply_2(env, fn, a1);
}

LispObject Lfuncall_4up(LispObject env, LispObject fn,
                        LispObject a1, LispObject a2, LispObject a3up)
{   if (is_symbol(fn) && (qheader(fn) & SYM_TRACED) == 0)
    {   if (cdr(a3up) == nil)
            return (*qfn3(fn))(fn, a1, a2, car(a3up));
        else return (*qfn4up(fn))(fn, a1, a2, car(a3up), cdr(a3up));
    }
    a1 = list2star(a1, a2, a3up);
    errexit();
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
        workbase[i] = car(a4up);
        a4up = cdr(a4up);
        n++;
    }
    return nvalues(a1, n);
}

LispObject Lvalues_3(LispObject env, LispObject a, LispObject b,
                     LispObject c)
{   mv_2 = b;
    mv_3 = c;
    return nvalues(a, 3);
}

LispObject Lvalues_2(LispObject env, LispObject a, LispObject b)
{   mv_2 = b;
    return nvalues(a, 2);
}

LispObject Lvalues_1(LispObject env, LispObject a)
{   return nvalues(a, 1);
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
    stackcheck();
    LispObject fn;
    fn = eval(car(args), env);
    errexit();
    args = cdr(args);
    LispObject xargs = nil;             // for list of eventual args
    while (consp(args))
    {   LispObject r1;
        {   RealSave save(args, env, xargs);
//          LispObject &arg1 = save.val(1);
//          LispObject &env1 = save.val(2);
            LispObject &xargs1 = save.val(3);
            r1 = car(args);
            exit_count = 1;
            r1  = eval(r1, env);
            errexit();
            if (exit_count != 0) xargs1 = cons(r1, xargs1);
            for (unsigned int i=2; i<=exit_count; i++)
            {   xargs1 = cons((&work_0)[i], xargs1);
                errexit();
            }
            save.restore(args, env, xargs);
        }
        args = cdr(args);
    }
    return apply(fn, xargs, env, mv_call_symbol);
}

LispObject interpreted_0(LispObject def)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    return apply_lambda(qenv(def), nil, nil, def);
}

LispObject interpreted_1(LispObject def, LispObject a1)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    a1 = ncons(a1);
    errexit();
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject interpreted_2(LispObject def, LispObject a1, LispObject a2)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    a1 = list2(a1, a2);
    errexit();
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject interpreted_3(LispObject def, LispObject a1, LispObject a2,
                         LispObject a3)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    a1 = list3(a1, a2, a3);
    errexit();
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject interpreted_4up(LispObject def, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4up)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    a1 = list3star(a1, a2, a3, a4up);
    errexit();
    return apply_lambda(qenv(def), a1, nil, def);
}

LispObject funarged_0(LispObject def)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    def = qenv(def);
    return apply_lambda(cdr(def), nil, car(def), cdr(def));
}

LispObject funarged_1(LispObject def, LispObject a1)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    def = qenv(def);
    a1 = ncons(a1);
    errexit();
    return apply_lambda(cdr(def), a1, car(def), cdr(def));
}

LispObject funarged_2(LispObject def, LispObject a1, LispObject a2)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    def = qenv(def);
    a1 = list2(a1, a2);
    errexit();
    return apply_lambda(cdr(def), a1, car(def), cdr(def));
}

LispObject funarged_3(LispObject def, LispObject a1, LispObject a2,
                      LispObject a3)
{   STACK_SANITY;
    save_current_function saver(def);
    stackcheck();
    errexit();
    def = qenv(def);
    a1 = list3(a1, a2, a3);
    errexit();
    return apply_lambda(cdr(def), a1, car(def), cdr(def));
}

LispObject funarged_4up(LispObject def, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4up)
{   STACK_SANITY;
    save_current_function saver(def);
    def = qenv(def);
    stackcheck();
    errexit();
    a1 = list3star(a1, a2, a3, a4up);
    errexit();
    return apply_lambda(cdr(def), a1, car(def), cdr(def));
}

static LispObject macroexpand_1(LispObject form, LispObject env)
{   // The environment here seems only necessary for macrolet
    STACK_SANITY;
    LispObject done;
    LispObject f;
    stackcheck();
    errexit();
    done = nil;
    if (consp(form))
    {   f = car(form);
// look for local macro definitions
        {   LispObject p;
            for (p=env; p!=nil; p=cdr(p))
            {   LispObject w = car(p);
                if (cdr(w) == f && is_cons(w = car(w)) && w!=nil)
                {   p = car(w);
                    if (p == funarg) // ordinary function
                    {   mv_2 = nil;
                        return nvalues(form, 2);
                    }
                    {   RealSave save(form, done);
                        {   RealSave save1(env);
                            w = cons(lambda, w);
                            errexit();
                            w = list3(w, save.val(1), nil);
                            save1.restore(env);
                        }
                        errexit();
                        on_backtrace(
                            p = apply(qvalue(macroexpand_hook),
                                      w,
                                      env,
                                      macroexpand_hook),
                            // Now the error handler
                            if (SHOW_FNAME)
                            {   err_printf("\nMacroexpanding: ");
                                loop_print_error(save.val(1));
                            });
                        save.restore(form, done);
                    }
                    mv_2 = lisp_true;
                    return nvalues(p, 2);
                }
            }
        }
// If there is no local macro definition I need to look for a global one
        if (symbolp(f) && (qheader(f) & SYM_MACRO) != 0)
        {   done = qvalue(macroexpand_hook);
            if (done == unset_var)
                return error(1, err_macroex_hook, macroexpand_hook);
            f = cons(lambda, qenv(f));
            errexit();
            f = list3(f, form, env);
            errexit();
            form = apply(done,
                         f,
                         env,
                         macroexpand_hook);
            errexit();
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
    stackcheck();
    errexit();
    done = nil;
    for (;;)
    {   form = macroexpand_1(form, env);
        errexit();
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
    {   set_fns(car(fname), undefined_0, undefined_1, undefined_2,
                undefined_3, undefined_4up);
        qenv(car(fname)) = car(fname);
        LispObject fname1 = cdr(fname);
        while (consp(fname1))
        {   Lload_module(nil, car(fname1));
            errexit();
            fname1 = cdr(fname1);
        }
    }
    return apply(car(fname), nil, nil, autoload_symbol);
}

LispObject autoload_1(LispObject fname, LispObject a1)
{   STACK_SANITY;
    fname = qenv(fname);
    set_fns(car(fname), undefined_0, undefined_1, undefined_2,
            undefined_3, undefined_4up);
    qenv(car(fname)) = car(fname);
    LispObject fname1 = cdr(fname);
    while (consp(fname1))
    {   Lload_module(nil, car(fname1));
        errexit();
        fname1 = cdr(fname1);
    }
    a1 = ncons(a1);
    errexit();
    return apply(car(fname), a1, nil, autoload_symbol);
}

LispObject autoload_2(LispObject fname, LispObject a1, LispObject a2)
{   STACK_SANITY;
    fname = qenv(fname);
    set_fns(car(fname),  undefined_0, undefined_1, undefined_2,
            undefined_3, undefined_4up);
    qenv(car(fname)) = car(fname);
    LispObject fname1 = cdr(fname);
    while (consp(fname1))
    {   Lload_module(nil, car(fname1));
        errexit();
        fname1 = cdr(fname1);
    }
    a1 = list2(a1, a2);
    errexit();
    return apply(car(fname), a1, nil, autoload_symbol);
}

LispObject autoload_3(LispObject fname, LispObject a1, LispObject a2,
                      LispObject a3)
{   STACK_SANITY;
    fname = qenv(fname);
    set_fns(car(fname),  undefined_0, undefined_1, undefined_2,
            undefined_3, undefined_4up);
    qenv(car(fname)) = car(fname);
    LispObject fname1 = cdr(fname);
    while (consp(fname1))
    {   Lload_module(nil, car(fname1));
        errexit();
        fname1 = cdr(fname1);
    }
    a1 = list3(a1, a2, a3);
    errexit();
    return apply(car(fname), a1, nil, autoload_symbol);
}

LispObject autoload_4up(LispObject fname, LispObject a1,
                        LispObject a2,
                        LispObject a3, LispObject a4up)
{   STACK_SANITY;
    fname = qenv(fname);
    set_fns(car(fname),  undefined_0, undefined_1, undefined_2,
            undefined_3, undefined_4up);
    qenv(car(fname)) = car(fname);
    LispObject fname1 = cdr(fname);
    while (consp(fname1))
    {   Lload_module(nil, car(fname1));
        fname1 = cdr(fname1);
    }
    a1 = list3star(a1, a2, a3, a4up);
    return apply(car(fname), a1, nil, autoload_symbol);
}

LispObject undefined_0(LispObject fname)
{   return error(1, err_undefined_function_0, fname);
}

LispObject undefined_1(LispObject fname, LispObject)
{
// It would be perfectly possible to grab and save the args here, and retry
// the function call after error has patched things up.  Again
// this entrypoint is for compiled code calling something that is undefined,
// and so no lexical environment is needed.
    return error(1, err_undefined_function_1, fname);
}

LispObject undefined_2(LispObject fname, LispObject, LispObject)
{   return error(1, err_undefined_function_2, fname);
}

LispObject undefined_3(LispObject fname, LispObject, LispObject,
                       LispObject)
{   return error(1, err_undefined_function_3, fname);
}

LispObject undefined_4up(LispObject fname,
                         LispObject, LispObject, LispObject, LispObject)
{   return error(1, err_undefined_function_4up, fname);
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

LispObject f3_as_1(LispObject env, LispObject a1, LispObject,
                   LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn1(env))(env, a1);
}

LispObject f2_as_2(LispObject env, LispObject a, LispObject b)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn2(env))(env, a, b);
}

LispObject f3_as_2(LispObject env, LispObject a1, LispObject a2,
                   LispObject)
{   env = qenv(env);
    debug_record_symbol(env);
    return (*qfn2(env))(env, a1, a2);
}

LispObject f3_as_3(LispObject env, LispObject a1, LispObject a2,
                   LispObject a3)
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

// As of September 2023 use of "termux" on aarch64 android perhaps needs
// to be linked with special libraries to support the shared memory APIs,
// but the easy way to get a system built there is just to disable this!

// I have simplified the conditions here so that I really just
// check for Linux but rules oit Android.

#if defined __linux__ && !defined __ANDROID__

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>

#define PARSIZE 65536

static LispObject write_result(LispObject env, LispObject r, char *shared)
{
// This converts an arbitrary result into a string so I can pass it back.
    int32_t i, len, ok = 1;
// Cyclic and re-entrant structures could lead to failure here, and
// uninterned symbols (eg gensyms) will not be coped with very well. But
// SIMPLE data types should all be safe.
    if_error(r = Lexplode(nil, r),
             // Error handler
             std::strcpy(shared, "Failed");
             my_exit());
    if_error(r = Llist_to_string(nil, r),
             // Error handler
             std::strcpy(shared, "Failed");
             my_exit());
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
    return nil;
}

LispObject Lparallel(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    STACK_SANITY;
    pid_t pid1, pid2, pidx, pidy;
// Create an identifier for a private shared segment of memory of size
// 2*PARSIZE. This will be used for passing a result from the sub-task
// to the main one. Give up if such a segment can not be allocated.
    int status, segid = shmget(IPC_PRIVATE, (size_t)(2*PARSIZE),
                               IPC_CREAT | S_IRUSR | S_IWUSR);
    char *shared, *w;
    int overflow;
    LispObject r;
    if (segid == -1) return aerror("Unable to allocate a shared segment");
// Attach to the shared segment to obtain a memory address via which it can be
// accessed. Again raise an error if this fails.
    shared = reinterpret_cast<char *>(shmat(segid, nullptr, 0));
    if (shared == reinterpret_cast<char *>(static_cast<uintptr_t>(-1)))
        return aerror("Unable to attach to shared segment");
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
        return aerror("Fork 1 failed");
    }
    else if (pid1 == 0)
    {   // TASK 1 created OK
        LispObject r1 = nil;
        if_error(r1 = Lapply2(nil, a, b, nil),
// If the evaluation failed I will exit indicating a failure.
            std::strcpy(shared, "Failed");
            my_exit());
// Write result from first task into the first half of the shared memory block.
        write_result(nil, r1, shared);
// Exiting from the sub-task would in fact detach from the shared data
// segment, but I do the detaching explictly to feel tidy.
        shmdt(shared);
// Could I get away with use of abort() rather than quick_exit given
// that the Macintosh seems to have given up on that bit of supporting
// an international standard?
        std::quick_exit(0);
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
            return aerror("Fork 2 failed");
        }
        else if (pid2 == 0)
        {   // TASK 2
            LispObject r2 = nil;
            if_error(r2 = Lapply2(nil, a, b, lisp_true),
                     // Error handler
                     std::strcpy(shared, "Failed");
                     my_exit());
            write_result(nil, r2, shared+PARSIZE);
            shmdt(shared);
            std::quick_exit(0);
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
            return cons(fixnum_of_int(overflow), r);
        }
    }
}

#else // __linux__

LispObject Lparallel(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    return aerror("parallel not supported on this platform");
}

#endif // __linux__

LispObject Lbacktrace(LispObject env)
{   SingleValued fn;
    LispObject s = callStack;
    stdout_printf("+++ backtrace +++\n");
    if (backtrace_enabled)
    {   while (s != nil)
        {   LispObject c = car(s);
            s = cdr(s);
            stdout_printf("calling: ");
            loop_print_stdout(car(c));
            stdout_printf("\n");
            c = cdr(c);
            int n = 1;
            while (c != nil)
            {   stdout_printf("Arg%d: ", n++);
                loop_print_stdout(car(c));
                stdout_printf("\n");
                c = cdr(c);
            }
        }
        stdout_printf("+++ end of backtrace +++\n");
    }
    else stdout_printf(
        "+++ You must call enable!-backtrace(N) to get a backtrace +++\n");
    return nil;
}

// sandbox-eval behaves much like eval, EXCEPT for two key differences.
// (1) The evaluation of u will not change the state of the Lisp
//     world. It can not change existing data structures (including
//     those used in the form to be evaluated. It can not change
//     fluid or global variables.
// (2) The result returned will have the characteristics of data
//     returned by the Lisp reader. So symbols named in it will
//     refer to ordinary symbols. There can not be any gensyms present
//     (any that had been present in the result a natural evaluation of
//     the form would have led to will have become simple standard
//     symbols. There will be no sharing of sub-structures either
//     within the result or with any existing data. Even if the
//     form included or introduced sharing. If cyclic data is
//     present in the result the code is liable to loop and fail.
//     And such failures are liable to mess up the whole system up
//     to and including causing it to hang.
//
// For some uses it will be proper to make the form that is to be
// evaluated using errorset and something like resource!-limit to
// get a better guarantee that things will behave. If the
// evaluated form misbehaves then the consequences are to be
// thought of as undefined, and could either involve the system
// hanging or a non-local exit propagating upwards.
//
// sandbox-apply is similar but models apply rather than eval.

// My first attempt at this facility used fork() to isolate the work that
// needed cautious evaluation. That functionality is not (readily) available
// on Windows. Even though is is provided under Cygwin the performance
// is liable to be poor and anyway my attempts to use it there have not
// been fully successful.
//
// So I abandon the fork() version and here is a notionally generic approch:
// (1) Check a withinSandbox flag and fail if it is set. Then set it
//     so that nested use of this scheme is not possible.
// (2) Make a copy of the current Lisp stack as a vector in the ordinary
//     heap. Also all listbases.
// (3) Identify all Pages that contain or may contain live data. These
//     will be consPinPages, vecPinPages, consCloggedPages, vecCloggedPages,
//     consPages and vecPages. Supposing that there are N such pages then
//     I will want there to be at least 2*N emptyPages. If there are not
//     (and indeed if there are not say at least 2.1*N emptyPages) run
//     the garbage collector and test again. If there are still not enough
//     try expanding memory by asking the OS for some more. If that fails
//     then report and "out of memory" fatal error.
// (4) Copy data from all active data to some of those emptyPages, arranging
//     that a copiedPage knows where it had been copied from and that it
//     is on a list of same.
// (5) Save all list bases that the system could possibly update and
//     also non-listbase variables that tends to change during a computation,
//     eg the stack fringes. Note that the Lisp stack will need its contents
//     saved, but the C stack will not. Record enough information about
//     memory allocation, and status preserved within any libraries.
// (6) Run eval() on the argument. It will be important that this evaluation
//     exits normally returning an s-expression. Multiple-value results
//     will not be handled.
// (7) Use something of the style of a "print-to-string" scheme to turn
//     the result into a sequence of characters. The space that is used
//     will count as belonging to the protected computation but must not
//     overlap with that which was originally in use.
// (8) Copy from the savedPages back into the places they had been copied
//     from. Copy back list bases and status variables, putting some pages
//     back on emptyPages when they are now in use but had not been at the
//     start. Now I know that there are plenty of free pages.
//     Restore non listbase variable. When that is done it will be
//     OK to compute in the restored space save that garbage collection
//     should be avoided for a while.
// (9) Copy from the borrowed page(s) into currently live pages arranging
//     that if pages need allocating to make space for this that no GC
//     intrudes. Unborrow the temporary space.
// (10)Restore the Lisp stack.  Read the final result from the string data.

bool withinSandbox = false;

// Now I have all the static values that I need to preserve across any
// sandboxed computation.

PageList sandboxConsPinPages;
PageList sandboxVecPinPages;
PageList sandboxConsCloggedPages;
PageList sandboxVecCloggedPages;
PageList sandboxConsPages;
PageList sandboxVecPages;
PageList sandboxBorrowPages;
PageList sandboxConsOldPages;
PageList sandboxVecOldPages;
Page* sandboxConsCurrent;
Page* sandboxVecCurrent;
Page* sandboxBorrowCurrent;
uintptr_t sandboxConsFringe, sandboxConsLimit, sandboxConsEnd;
uintptr_t sandboxVecFringe, sandboxVecLimit, sandboxVecEnd;
uintptr_t sandboxBorrowFringe, sandboxBorrowLimit, sandboxBorrowEnd;

void saveStatics()
{
// Note that I do not save and restore emptyPages.
    sandboxConsPinPages     .copy(consPinPages);
    sandboxVecPinPages      .copy(vecPinPages);
    sandboxConsCloggedPages .copy(consCloggedPages);
    sandboxVecCloggedPages  .copy(vecCloggedPages);
    sandboxConsPages        .copy(consPages);
    sandboxVecPages         .copy(vecPages);
    sandboxBorrowPages      .copy(borrowPages);
    sandboxConsOldPages     .copy(consOldPages);
    sandboxVecOldPages      .copy(vecOldPages);

    sandboxConsCurrent    = consCurrent;
    sandboxVecCurrent     = vecCurrent;
    sandboxBorrowCurrent  = borrowCurrent;
    sandboxConsFringe     = consFringe;
    sandboxConsLimit      = consLimit;
    sandboxConsEnd        = consEnd;
    sandboxVecFringe      = vecFringe;
    sandboxVecLimit       = vecLimit;
    sandboxVecEnd         = vecEnd;
    sandboxBorrowFringe   = borrowFringe;
    sandboxBorrowLimit    = borrowLimit;
    sandboxBorrowEnd      = borrowEnd;
// Other things to think about:
//  verbos flag
//  enable-errorset flag
//  linelength, posn
//  print precision
//  current modulus (esp if small)
//  ???

}

void restoreStatics()
{   consPinPages     .copy(sandboxConsPinPages);
    vecPinPages      .copy(sandboxVecPinPages);
    consCloggedPages .copy(sandboxConsCloggedPages);
    vecCloggedPages  .copy(sandboxVecCloggedPages);
    consPages        .copy(sandboxConsPages);
    vecPages         .copy(sandboxVecPages);
    borrowPages      .copy(sandboxBorrowPages);
    consOldPages     .copy(sandboxConsOldPages);
    vecOldPages      .copy(sandboxVecOldPages);

    consCurrent   = sandboxConsCurrent;
    vecCurrent    = sandboxVecCurrent;
    borrowCurrent = sandboxBorrowCurrent;
    consFringe    = sandboxConsFringe;
    consLimit     = sandboxConsLimit;
    consEnd       = sandboxConsEnd ;
    vecFringe     = sandboxVecFringe;
    vecLimit      = sandboxVecLimit;
    vecEnd        = sandboxVecEnd  ;
    borrowFringe  = sandboxBorrowFringe;
    borrowLimit   = sandboxBorrowLimit;
    borrowEnd     = sandboxBorrowEnd;
}

void saveOnePage(Page* p)
{   Page* np = emptyPages.pop();
    memcpy(np, p, sizeof(Page));
    np->original = p;
    np->saveChain = savedPages;
    savedPages = np;
    p->liveBeforeSandbox = true;
}

// This puts a page on the double-linked list list newFreePages. Well I do
// not put any page that is being used to hold part of the result-string,
// so they will remain on resultPages rather than newFreePages.

Page* resultPages = nullptr;
Page* newFreePages = nullptr;

void releaseOnePage(Page* p)
{   for (Page* w=resultPages; w!=nullptr; w=w->saveChain)
        if (p == w) return;
    p->chain = newFreePages;
    p->saveChain = nullptr;
    if (newFreePages!=nullptr) newFreePages->saveChain = p;
    newFreePages = p;
}

// Splice a page out from the newFreePages double-linked chain.

void unFreePage(Page* p)
{   Page* prev = p->saveChain;
    Page* next = p->chain;
    if (prev == nullptr) newFreePages = next;
    else prev->chain = next;
    if (next != nullptr) next->saveChain = prev;
}

// Put all pages on free back as begin free.

void restoreFreePages(Page* fr)
{   while (fr != nullptr)
    {   Page* next = fr->chain;
        emptyPages.push(fr);
        fr = next;
    }
}

// This must use borrow_basic_vector() when it wants to grab some
// space to store a serialized version of u. It must return something
// that gives access to that data. I must not garbage collect while
// this data is active, but I will make it using TYPE_MIXED1 so that each
// block has 3 LispObject fields at the start and one of these will be
// used for chaining.

const size_t stringBufferSize = 16384-4*8;

// printToStrings will take an S-expression u and serialize it
// to form a sequence of bytes. These will be placed in
// one or more blocks (each of which are about 16K bytes long
// and are chained via an early element). The first block in
// the chain is returned. While writing to the chain of blocks
// the listbase mv_4 will be used to store a reference to the
// current block. This is safe provided the printing routines do
// not use multiple values beyond 3 of them!
// The memory that these are put in must not overlap with any that
// was in use when sandbox-eval started its work. Such pages will
// have a flag (liveBeforeSandbox) set in them.

static size_t charCounter;
LispObject& charBlock = mv_4;

bool byteToStrings(int ch)
{   if (charCounter == stringBufferSize)
    {   LispObject newBlock;
        for (;;)
        {   newBlock = get_basic_vector(TAG_VECTOR, TYPE_MIXED1,
                           stringBufferSize+3*sizeof(LispObject));
            Page* p = pageOf(newBlock);
            if (p != resultPages)
            {   p->saveChain = resultPages;
                resultPages = p;
            }
            elt(newBlock,0) = charBlock;
            elt(newBlock,1) = nil;
            elt(newBlock,2) = nil;
            Page* p1 = pageOf(newBlock);
            if (p1->liveBeforeSandbox)
            {
// I am going to be lazy here. What I need to do here is accept that the
// current page can not be used and that I need to allocate another. It
// would be nice to create a padder from where I am right up to the end
// of the page. However the page may contain pinned sections between here
// and its end, so filling it out is a little bit messy. Instead I will
// just continue allocating 16Kbyte chunks until I end up in the next
// page. Actually that is not too bad since it only takes 256 of then to
// fill a page, so I will traverse this loop a few hundred times rather
// than many many thousands.
                continue;
            }
// Now the page that I am allocating is not one that will get overwritten
// when original pages are restored. If I fail to find a suitable page
// I may garbage collect and I may go to the operating system to expand
// memory. If those fail I will just have run out of memory in a way that
// could always be possible. Well that may not be quite true because the GC
// can discard all the padding blocks I allocated here and so it may not
// believe it is short enough of memory to take drastic action and I fear
// that this could end up looping looking for suitable pages. Ugh. I will
// comd back to that problem later on.
            break;
        }
        charBlock = newBlock;
        charCounter = 0;
    }
    char* data = reinterpret_cast<char*>(&elt(charBlock, 3));
    data[charCounter++] = ch;
    return true;
}

// Note that this ends up with the blocks (if there are several)
// chained with the last one written first. This will turn out to be
// OK because the block order gets corrected before data is read!

LispObject printToStrings(LispObject u)
{   resultPages = nullptr;
    charBlock = nil;
    charCounter = stringBufferSize;
    iputc_hook = byteToStrings;
    def_init();
    Lserialize(nil, u);
    def_finish();
    iputc_hook = nullptr;
// This is in the space used by the sandboxed task.
    return charBlock;
}

int byteFromStrings()
{   if (charCounter == stringBufferSize)
    {   charBlock = elt(charBlock,0);
        charCounter = 0;
    }
    char* data = reinterpret_cast<char*>(&elt(charBlock, 3));
    return data[charCounter++] & 0xff;
}

LispObject readFromStrings(LispObject input)
{   charBlock = input;
    charCounter = 0;
    igetc_hook = byteFromStrings;
    inf_init();
    LispObject r = Lunserialize(nil);
    igetc_hook = nullptr;
    return r;
}

LispObject sandbox(bool fg, LispObject a, LispObject b)
{
// (1) Check a withinSandbox flag and fail if it is set. Then set it
//     so that nested use of this scheme is not possible.
    if (withinSandbox) aerror("sandbox evaluation can not be nested");
    withinSandbox = true;
    LispObject r;
// (2) Make a copy of the current Lisp stack as a vector in the ordinary
//     heap. Also all listbases.
    LispObject* stackPtr = stack;
    size_t stackSize =
        (stack-reinterpret_cast<LispObject*>(stackBase)+sizeof(LispObject));
    LispObject saveStack =
        get_vector(TAG_VECTOR, TYPE_INTPTR, stackSize+sizeof(LispObject));
// Use of memcpy here would not be proper if the stack was so huge that
// the save vector had to be represented as a non-basic vector
    for (size_t i=0; i<stackSize/sizeof(LispObject); i++)
       elt(saveStack, i) = reinterpret_cast<LispObject*>(stackBase)[i];
    size_t listbasesSize = sizeof(LispObject)*
        (sizeof(list_bases)/sizeof(LispObject *));
    LispObject saveListbases =
        get_vector(TAG_VECTOR, TYPE_INTPTR, listbasesSize+sizeof(LispObject));
    size_t i = 0;
    for (LispObject* p : list_bases)
        elt(saveListbases, i++) = *p;
// (3) Identify all Pages that contain or may contain live data. These
//     will be consPinPages, vecPinPages, consCloggedPages, vecCloggedPages,
//     consPages and vecPages. Supposing that there are N such pages then
//     I will want there to be at least 2*N emptyPages. If there are not
//     (and indeed if there are not say at least 2.1*N emptyPages) run
//     the garbage collector and test again. If there are still not enough
//     try expanding memory by asking the OS for some more. If that fails
//     then report and "out of memory" fatal error.
    size_t N=0, F=0;
    for (bool first=true;;first=false)
    {   N = consPinPages.count + vecPinPages.count + consCloggedPages.count +
            vecCloggedPages.count + consPages.count + vecPages.count;
        while (pageFringe != pageEnd)
        {   Page* r = pageFringe++;
            r->type = emptyPageType;
        }
        F = emptyPages.count;
        if (F >= static_cast<size_t>(2.1*N)+1) break;
        if (first)
        {   garbage_collect();
            continue;
        }
        else if (allocateAnotherSegment()) continue;
        else fatal_error(err_no_store);
    }
// (4) Copy data from all active data to some of those emptyPages, arranging
//     that a copiedPage knows where it had been copied from and that it
//     is on a list of same.
    savedPages = nullptr;
    for (auto p:consPinPages) saveOnePage(p);
    for (auto p:vecPinPages) saveOnePage(p);
    for (auto p:consCloggedPages) saveOnePage(p);
    for (auto p:vecCloggedPages) saveOnePage(p);
    for (auto p:consPages) saveOnePage(p);
    for (auto p:vecPages) saveOnePage(p);
// (5) Save all non-listbase variables that tends to change during a
//     computation, eg the stack fringes. Note that the C stack will not
//     need its contents saved. Record enough information about
//     memory allocation, and status preserved within any libraries.
    saveStatics();
// (6) Run eval() on the argument. It will be important that this evaluation
//     exits normally returning an s-expression. Multiple-value results
//     will not be handled.
   TRY
     if (fg) r = eval(a, nil);
     else r = apply(a, b, nil, apply_symbol);
     r = ncons(r);
   CATCH_ANY()
     r = nil;
   END_CATCH
// (7) Use something of the style of a "print-to-string" scheme to turn
//     the result into a sequence of characters. The space that is used
//     will count as belonging to the protected computation but must not
//     overlap with that which was originally in use.
   LispObject resultString = printToStrings(r);
// (8) Copy from the savedPages back into the places they had been copied
//     from. Copy back list bases and status variables, putting some pages
//     back on emptyPages when they are now in use but had not been at the
//     start. Now I know that there are plenty of free pages.
//     Restore non listbase variable. When that is done it will be
//     OK to compute in the restored space save that garbage collection
//     should be avoided for a while.
// One of the things that will need to be sorted will be the chaining
// of Pages. Well those of Pages that were in use (including those
// containing pinned data) will be OK because they are restored from
// copies, but pages that were empty at the start and any additional
// pages that came into being if memory was enlarged during the protected
// calculation may not be.
// I deal with that by initially puttiing ALL pages apart from the
// ones with saved data not just on the list of empty pages but as a
// double-linked list. Then as I restore any page I can easily edit that
// out from the new list. And once I have moved data out from the page
// that saved stuff it can go on the empty page list. Ha ha neat!
    newFreePages = nullptr;
    while (!emptyPages.isEmpty())
        releaseOnePage(emptyPages.pop());
    while (!consPinPages.isEmpty())
        releaseOnePage(consPinPages.pop());
    while (!vecPinPages.isEmpty())
        releaseOnePage(vecPinPages.pop());
    while (!consCloggedPages.isEmpty())
        releaseOnePage(consCloggedPages.pop());
    while (!vecCloggedPages.isEmpty())
        releaseOnePage(vecCloggedPages.pop());
    while (!consPages.isEmpty())
        releaseOnePage(consPages.pop());
    while (!vecPages.isEmpty())
        releaseOnePage(vecPages.pop());
// Now copy saved data back to where it came from. And the Pages that
// had been used to save it go back on the chain of free Pages.
    while (savedPages != nullptr)
    {   unFreePage(savedPages->original);
        memcpy(savedPages->original, savedPages, sizeof(Page));
        Page* next = savedPages->saveChain;
        releaseOnePage(savedPages);;
        savedPages = next;
    }
// Now I can put the chain of free Pages back where it really wants to be.
    restoreFreePages(newFreePages);
    restoreStatics();
// (9) Copy result data from the result page(s) into currently live pages
//     arranging that if pages need allocating to make space for this that
//     no GC intrudes.
   withinGarbageCollector = true;
    r = nil;
    while (resultString != nil)
    {   LispObject b =
            get_basic_vector(TAG_VECTOR, TYPE_MIXED1,
                             stringBufferSize+3*sizeof(LispObject));
// The "binary data" part of r starts at elt(b, 3). Elements 0, 1 and 2
// are the LispObject fields.
        memcpy(&elt(b, 3),
               &elt(resultString, 3),
               stringBufferSize);
        elt(b, 0) = r;
        elt(b, 1) = nil;
        elt(b, 2) = nil;
        r = b;
        resultString = elt(resultString, 0);
    }
// I had arranged that the result had been put in Pages that would not
// overlap with those active at the start, and I built a list resultPages
// of them. So now I can recycle the result space as empty pages.
    restoreFreePages(resultPages);
    withinGarbageCollector = false;
// (10)Restore the Lisp stack.  Read the final result from the string data.
    for (size_t i=0; i<stackSize/sizeof(LispObject); i++)
        reinterpret_cast<LispObject*>(stackBase)[i] = elt(saveStack, i);
    stack = stackPtr;
    i = 0;
    for (LispObject* p : list_bases)
        *p = elt(saveListbases, i++);
    r = readFromStrings(r);
// If sandbox_eval crashes out in any way it can leave withinSandbox true.
// that will prevent any further use of the sandbox facility. This is a
// deliberate choice of behaviour on my part at present. I could easily
// set up a little class with a destructor ro ensure that the variable
// was reset to false on even unusual exits, but I am not doing that!
    withinSandbox = false;
    return r;
}

LispObject Lsandbox_eval(LispObject env, LispObject form)
{   SingleValued fn;
    return sandbox(true, form, nil);
}

LispObject Lsandbox_apply(LispObject env, LispObject fn, LispObject args)
{   SingleValued fn1;
    return sandbox(false, fn, args);
}

LispObject Lsleep(LispObject env, LispObject a)
{   SingleValued fn;
    int n;
    if (is_fixnum(a)) n = int_of_fixnum(a);
    else n = 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(n));
    return nil;
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
{   SingleValued fn;
    int m = 0, n = 0;
    if (is_fixnum(a1))
    {   m = int_of_fixnum(a1);
        if (m < 0 || m > 100) m = 0;
    }
    if (is_fixnum(a2))
    {   n = int_of_fixnum(a2);
        if (n > 100) n = m+10;
    }
    term_printf("Stack depth %" PRIuPTR "\n",
                reinterpret_cast<uintptr_t>(stack) - stackBase);
    for (int i=m; i<=n; i++)
    {   term_printf("%d: ", i);
        prin_to_terminal(stack[-i]);
        term_printf("\n");
        errexit();
    }
    return nil;
}

LispObject Lshow_stack_1(LispObject env, LispObject a1)
{   SingleValued fn;
    return Lshow_stack_2(env, fixnum_of_int(0), a1);
}

LispObject Lshow_stack_0(LispObject env)
{   SingleValued fn;
    return Lshow_stack_2(env, fixnum_of_int(0), fixnum_of_int(0));
}

setup_type const eval1_setup[] =
{   {"bytecounts",         Lbytecounts_0, Lbytecounts_1, G2Wother, G3Wother, G4Wother},
    {"idapply",            G0Wother, Lapply_1, Lapply_2, Lapply_3, Lapply_4up},
    DEF_1("eval",          Leval),
    {"apply",              G0Wother, Lapply_1, Lapply_2, Lapply_3, Lapply_4up},
    DEF_1("apply0",        Lapply0),
    DEF_2("apply1",        Lapply1),
    DEF_3("apply2",        Lapply2),
    DEF_4up("apply3",      Lapply3),
    DEF_4up("apply4",      Lapply4),
    DEF_1("evlis",         Levlis),
// The symbol "funcall" gets set up manually in restart.cpp, so I should not
// include it in the list here.
//  {"funcall",            G0Wother, Lfuncall_1, Lfuncall_2, Lfuncall_3, Lfuncall_4up},
    {"funcall*",           G0Wother, Lfuncall_1, Lfuncall_2, Lfuncall_3, Lfuncall_4up},
    DEF_2("parallel",      Lparallel),
    DEF_1("sandbox-eval",  Lsandbox_eval),
    DEF_2("sandbox-apply", Lsandbox_apply),
    DEF_1("sleep",         Lsleep),
    {"values",             Lvalues_0, Lvalues_1, Lvalues_2, Lvalues_3, Lvalues_4up},
    {"macroexpand",        G0Wother, Lmacroexpand, Lmacroexpand_2, G3W1, G4W1},
    {"macroexpand-1",      G0Wother, Lmacroexpand_1, Lmacroexpand_2, G3Wother, G4Wother},
    DEF_0("backtrace",     Lbacktrace),
    {"show-stack",         Lshow_stack_0, Lshow_stack_1, Lshow_stack_2, G3Wother, G4Wother},
    {nullptr,              nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of eval1.cpp
