// eval2.cpp                               Copyright (C) 1989-2025 Codemist

//
// Interpreter (part 2).  apply & some special forms
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

// After (trace-count n) each "Calling ..." line of output when a function
// is being traced will include a sequence number starting with n if n>0.
// And the matching return value will echo the same number to make it easy
// to match call and return. (trace-count t) is equivalent to (trace-count 1)
// and (trace-count nil) to (trace-count 0) which switches this feature off.

int64_t trace_count = 1;

LispObject Ltrace_count(LispObject env, LispObject n)
{  SingleValued fn;
   int64_t old = trace_count;
   if (is_fixnum(n)) trace_count = int_of_fixnum(n);
   else if (n == lisp_true) trace_count = 1;
   else if (n == nil) trace_count = 0;
   return fixnum_of_int(old);
}

// CSL is now set up so that so that functions of 0, 1, 2 and 3
// arguments are called directly via dedicated function cells. For 4 and
// up args I will pass args 1-3 naturally and the rest as a list, rather as
// if the call had been
//     (fff 1 2 3 (list 4 5 6 7 ...))
// Such a scheme supports having no (serious) limit on the number of
// arguments, and it is (internally) much tidier in this C++ code than
// my previous scheme which relied on the va_arg facility of C++ and could
// occasionally use vast amounts of stack.

LispObject apply(LispObject fn, LispObject args,
                 LispObject env, LispObject from)
{   if (time_limit >= 0 &&
        read_clock()/1000 > (std::uint64_t)time_limit) resource_exceeded();
    RECORD_CALL(cons(fn, args));
    LispObject def;
    int64_t count = trace_count;
    for (;;)
    {   if (symbolp(fn))
        {   debug_assert(1);
            debug_record_symbol(fn);
// Heer I am calling a function named by the symbol "fn" and all the arguments
// have been prepared and in the list "args"
            bool tracing = (qheader(fn) & SYM_TRACED) != 0;
            if (tracing)
            {   freshline_trace();
                errexit();
                trace_printf("Calling ");
                errexit();
                loop_print_trace(fn); // Function being called
                errexit();
                if (count > 0)
                {   trace_count = trace_count+1;
                    trace_printf(" [%" PRId64 "]", count);
                    errexit();
                }
                trace_printf(" from ");
                errexit();
                loop_print_trace(from);  // caller
                errexit();
                trace_printf("\n");
                errexit();
                LispObject p = args;
                for (int i=1; p!=nil; i++)
                {   trace_printf("Arg%d: ", i);
                    errexit();
                    loop_print_trace(car(p));
                    errexit();
                    trace_printf("\n");
                    errexit();
                    p = cdr(p);
                }
            }
            def = fn; // this is passed as arg1 to the called code
            // displays a result.
            if (args == nil)
                def = (*qfn0(fn))(def);
            else
            {   LispObject a1 = car(args);
                args = cdr(args);
                if (args == nil)
                    def = (*qfn1(fn))(def, a1);
                else
                {   LispObject a2 = car(args);
                    args = cdr(args);
                    if (args == nil)
                        def = (*qfn2(fn))(def, a1, a2);
                    else
                    {   LispObject a3 = car(args);
                        args = cdr(args);
                        if (args == nil)
                            def = (*qfn3(fn))(def, a1, a2, a3);
                        else
                            def = (*qfn4up(fn))(def, a1, a2, a3, args);
                    }
                }
            }
            errexit();
            if (tracing)
            {
// In due course I will need to worry about multiple values here
                freshline_trace();
                errexit();
                loop_print_trace(fn);
                errexit();
                if (count > 0)
                {   trace_printf(" [%" PRId64 "]", count);
                    errexit();
                }
                trace_printf(" => ");
                errexit();
                loop_print_trace(def);
                errexit();
                trace_printf("\n");
                errexit();
            }
            return def;
        }
        else if (!is_cons(fn))
        {   char message[64];
// If the object in the function position is not a symbol but is atomic I
// have an error state, and it happens that I can tell something about where
// the call was from so I will construct a half decent diagnostic.
            char name_of_caller[32];
            from = qpname(from);
            size_t len = length_of_byteheader(vechdr(from)) - CELL;
            if (len >= sizeof(name_of_caller)) len = sizeof(name_of_caller)-1;
            std::memcpy(name_of_caller, &celt(from, 0), len);
            name_of_caller[len] = 0;
            std::snprintf(message, sizeof(message),
                          "Bad function called from %s: ",
                          name_of_caller);
            return aerror1(message, fn);
        }
// apply_lambda() is the key part of calls to interpreted functions.
        if ((def = car(fn)) == lambda)
            return apply_lambda(cdr(fn), args, env, fn);
// A bytecoded funarg is stored as (cfunarg <actual fn> <env>) and any call
// to it behaves as if the actual function was called with the environment
// passed as a forced-in first argument.
        else if (def == cfunarg)
        {   def = cdr(fn);
            fn = car(def);
            args = cons(cdr(def), args);
// The "continue" here just goes back and tries again!
            continue;
        }
        else if (def == funarg)
        {   def = cdr(fn);
            if (consp(def))
                return apply_lambda(cdr(def), args, car(def), fn);
        }
        break;
    }
// I have now handled all the cases that are valid - so if I get here I need
// to generate a diagnostic.
    char message[64];
    char name_of_caller[32];
    from = qpname(from);
    size_t len = length_of_byteheader(vechdr(from)) - CELL;
    if (len >= sizeof(name_of_caller)) len = sizeof(name_of_caller)-1;
    std::memcpy(name_of_caller, &celt(from, 0), len);
    name_of_caller[len] = 0;
    std::snprintf(message, sizeof(message),
                  "Bad function called from %s: ",
                  name_of_caller);
    return aerror1(message, fn);
}


// Now for implementations of many of the special forms...

static LispObject and_fn(LispObject args, LispObject env)
// also needs to be a macro for Common Lisp
{   stackcheck();
    STACK_SANITY;
    if (!consp(args)) return lisp_true;
    for (;;)
    {   LispObject v = car(args);
        args = cdr(args);
        if (!consp(args)) return eval(v, env);
        v = eval(v, env);
        if (v == nil) return nil;
    }
}

static LispObject block_fn(LispObject iargs, LispObject ienv)
{   LispObject p;
    STACK_SANITY;
    if (!consp(iargs)) return nil;
    stackcheck();
    RealSave save(car(iargs),          // my_tag
                  cdr(iargs),          // args
                  ienv);
    LispObject &my_tag = save.val(1);
    LispObject &args = save.val(2);
    LispObject &env = save.val(3);
// I need to augment the (lexical) environment with the name of my
// tag in such a way that return-from can throw out to exactly the
// correct matching level.  This is done by pushing (0 . tag) onto
// the environment - the 0 marks this as a block name.
    my_tag = cons(fixnum_of_int(0), my_tag);
    env = cons(my_tag, env);
    p = nil;
    while (consp(args))
    {   p = car(args);
        TRY
            p = eval(p, env);
        CATCH(LispReturnFrom)
            car(my_tag) = fixnum_of_int(2); // Invalidate
            if (exit_tag == my_tag)
                return nvalues(exit_value, exit_count);
            else RETHROW;
        ANOTHER_CATCH(LispResource)
            RETHROW;
        ANOTHER_CATCH(LispSimpleError)
            int _reason = exit_reason;
            err_printf("\nEvaluating: ");
            loop_print_error(car(args));
            exit_reason = _reason;
            RETHROW;
        END_CATCH
        args = cdr(args);
    }
    return p;
}

static LispObject catch_fn(LispObject args, LispObject env)
{   LispObject tag, v;
    STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    tag = eval(car(args), env);
    errexit();
    tag = catch_tags = cons(tag, catch_tags);
    errexit();
    TRY
        v = progn_fn(cdr(args), env);
    CATCH(LispThrow)
        catch_tags = cdr(tag);
        car(tag) = tag;
        cdr(tag) = nil;        // Invalidate the catch frame
        if (exit_tag == tag) return nvalues(exit_value, exit_count);
        else RETHROW;
    ANOTHER_CATCH(LispException)
        catch_tags = cdr(tag);
        car(tag) = tag;
        cdr(tag) = nil;        // Invalidate the catch frame
        RETHROW;
    END_CATCH;
    catch_tags = cdr(tag);
    car(tag) = tag;
    cdr(tag) = nil;            // Invalidate the catch frame
    return v;
}

// let_fn_1 is used for various things that bind variables - and in CSL
// that will most commonly be PROG. In PROG there needs to be a TAGBODY
// to cope with GO as well.

#define BODY_LET            0
#define BODY_COMPILER_LET   1
#define BODY_PROG           2


class LetUnbinder
{   LispObject *saveStack;
    LispObject *specenv_p;
public:
    LetUnbinder(LispObject *ss)
    {   saveStack = stack;
        specenv_p = ss;
    }
    ~LetUnbinder()
    {   stack = saveStack;
        for (LispObject p1 = *specenv_p; p1 != nil; p1 = cdr(p1))
        {   LispObject w = car(p1);
            qvalue(car(w)) = cdr(w);
        }
    }
};

LispObject let_fn_1(LispObject bvlx, LispObject bodyx,
                    LispObject envx, int compilerp)
// This will have to look for (declare (special ...)).
// compiler-let forces all of its bindings to be locally special. In
// CSL mode I do not support local declarations, which simplifies and
// speeds things up here. Well to be more precise, I support DECLARE in
// the Compiler, but in the interpreter in non-Common mode every variable
// is SPECIAL.
{   stackcheck();
    errexit();
    RealSave save(bvlx, bodyx, envx,
                  nil, nil, envx, nil, nil);
    LispObject &bvl        = save.val(1);
    LispObject &body       = save.val(2);
    LispObject &env        = save.val(3);
    LispObject &q          = save.val(4);
    LispObject &p          = save.val(5);
    LispObject &env1       = save.val(6);
    LispObject &specenv    = save.val(7);
    LispObject &local_decs = save.val(8);
// Find local declarations - it is necessary to macro-expand
// items in the body to see if they turn into declarations.
    for (;;)
    {   if (!consp(body)) break;
        p = macroexpand(car(body), env);
        errexit();
        body = cdr(body);
        if (!consp(p))
        {   if (stringp(p) && consp(body)) continue;
            body = cons(p, body);
            errexit();
            break;
        }
        if (car(p) != declare_symbol)
        {   body = cons(p, body);
            errexit();
            break;
        }
        for (p = cdr(p); consp(p); p = cdr(p))
        {   q = car(p);
            if (!consp(q) || car(q) != special_symbol) continue;
            // here q says (special ...)
            for (q=cdr(q); consp(q); q = cdr(q))
            {   local_decs = cons(car(q), local_decs);
                errexit();
            }
        }
    }

    for (; consp(bvl); bvl=cdr(bvl))
    {   LispObject z;
        q = car(bvl);
        if (consp(q))
        {   z = cdr(q);
            q = car(q);
            if (consp(z)) z = car(z);
            else z = nil;
        }
        else z = nil;
        if (!is_symbol(q) || q==nil || q==lisp_true)
        {   LispObject qq = q;
            error(1, err_bad_bvl, qq);
            errexit();
        }
        else
        {   Header h = qheader(q);
            if (z != nil) z = eval(z, env);
            errexit();
            z = cons(q, z);
            errexit();
            if (compilerp == BODY_COMPILER_LET)
            {   specenv = cons(z, specenv);
                errexit();
                q = acons(q, work_symbol, env1);
                errexit();
                env1 = q; // Locally special
            }
            else if (h & SYM_GLOBAL_VAR) return aerror1("Attempt to bind", q);
            else if (h & SYM_SPECIAL_VAR) specenv = cons(z, specenv);
            else
            {   LispObject w;
                for (w = local_decs; w!=nil; w = cdr(w))
                {   if (q != car(w)) continue;
                    car(w) = fixnum_of_int(0);
// The next few calls to cons() maybe lose w, but that is OK!
                    specenv = cons(z, specenv);
                    q = acons(q, work_symbol, env1);
                    errexit();
                    env1 = q;
                    goto bound;
                }
                env1 = cons(z, env1);
                errexit();
            bound:  ;
            }
            errexit();
        }
    }

    while (local_decs!=nil)         // Pervasive special declarations
    {   LispObject q1 = car(local_decs);
        local_decs=cdr(local_decs);
        if (!is_symbol(q1)) continue;
        q1 = acons(q1, work_symbol, env1);
        errexit();
        env1 = q1;
    }
// I treat the case where there are no new (special) bindings specially
// because in that case I can tail-call to the next stage of evaluation, and
// that saves stack.
    if (specenv == nil)
    {   LispObject bodyx = body, env1x = env1;
// See expansion of Return() for an explanation of why body and env1 have
// been moved into new local variables before the call..
        if (compilerp == BODY_PROG)
            return tagbody_fn(bodyx, env1x);
        else return progn_fn(bodyx, env1x);
    }
// I instate the special bindings after all values to bind have been
// collected. But this is where I will need to arrange to ensure that
// when for ANY reason at all the code here is unwound that the fluid
// bindings concerned get restored.
    for (p = specenv; p != nil; p = cdr(p))
    {   LispObject w = car(p), v = car(w), z = cdr(w);
        LispObject old = qvalue(v);
        qvalue(v) = z;
        cdr(w) = old;
    }
// The above has instated bindings. Subject to not getting asynchronous
// interruptions once I start to bind any I bind all.
    {   LetUnbinder unbind(&specenv);
        if (compilerp == BODY_PROG)
            body = (tagbody_fn(body, env1));
        else body = (progn_fn(body, env1));
    }
    errexit();
    return body;
}

static LispObject compiler_let_fn(LispObject args, LispObject env)
{   if (!consp(args)) return nil;
    STACK_SANITY;
    return let_fn_1(car(args), cdr(args), env, BODY_COMPILER_LET);
}

LispObject cond_fn(LispObject args, LispObject env)
{   stackcheck();
    STACK_SANITY;
    while (consp(args))
    {   LispObject p = car(args);
        if (consp(p))
        {   LispObject p1 = eval(car(p), env);
            errexit();
            if (p1 != nil)
            {   args = cdr(car(args));
// Here I support the case "(cond (predicate) ...)" with no consequents
// as returning the non-nil value of the predicate.
                if (!consp(args)) return p1;
                else return progn_fn(args, env);
            }
        }
        args = cdr(args);
    }
    return nil;
}

LispObject declare_fn(LispObject, LispObject)
// declarations can only properly occur at the heads of various
// special forms, and so may NOT be evaluated in an ordinary manner.
// Thus I am entitled (just about) to make this a no-op.  It would
// probably be better to arrange that (declare ...) never got evaluated
// and then I could raise an error if this bit of code got activated.
// Indeed (declare ...) probably does not ever get evaluated - still
// a no-op here seems the safest bet. And in CSL mode this allows one to
// have left DECLAREs in there for the benefit of the compiler.
{   return nil;
}


#define flagged_lose(v) \
    ((fv = qfastgets(v)) != nil && static_cast<LispObject>(elt(fv, 1)) != SPID_NOPROP)

static LispObject defun_fn(LispObject args, LispObject)
{
// defun is eventually expected (required!) to be a macro rather than (maybe
// as well as?) a special form.  For bootstrap purposes it seems useful to
// build it in as a special form.  Also this special form is quite good enough
// in CSL mode
    LispObject fname;
    STACK_SANITY;
    if (consp(args))
    {   fname = car(args);
        args = cdr(args);
        if (is_symbol(fname))
        {   LispObject fv;
            if (qheader(fname) & SYM_SPECIAL_FORM)
                return error(1, err_redef_special, fname);
            if ((qheader(fname) & SYM_CODEPTR) != 0) return fname;
            if (flagged_lose(fname))
            {   debug_printf("\n+++ ");
                loop_print_debug(fname);
                debug_printf(" not defined because of LOSE flag\n");
                return nil;
            }
            qheader(fname) = qheader(fname) & ~SYM_MACRO;
            if (qfn1(fname) != undefined_1)
            {   if (qvalue(redef_msg) != nil)
                {   debug_printf("\n+++ ");
                    loop_print_debug(fname);
                    debug_printf(" redefined\n");
                }
                set_fns(fname, undefined_0, undefined_1, undefined_2, undefined_3,
                        undefined_4up);
                qenv(fname) = fname;
            }
// qfn() can contain 'interpreted' for a function defined wrt the null
// environment, or 'funarged' for one with an environment - in the latter
// case the definition (in qenv()) is a pair (<def> . <env>)
            qenv(fname) = args;         // Sort of notional lambda present
            set_fns(fname, interpreted_0, interpreted_1, interpreted_2,
                    interpreted_3, interpreted_4up);
            if (qvalue(comp_symbol) != nil &&
                qfn1(compiler_symbol) != undefined_1)
            {   args = ncons(fname);
                (*qfn1(compiler_symbol))(compiler_symbol, args);
            }
            return fname;
        }
    }
    return aerror("defun");
}

static LispObject defmacro_fn(LispObject args, LispObject)
{
// defmacro is eventually expected (required!) to be a macro rather than (maybe
// as well as?) a special form.  For bootstrap purposes it seems useful to
// build it in as a special form.
    LispObject fname;
    STACK_SANITY;
    if (consp(args))
    {   fname = car(args);
        args = cdr(args);
        if (!consp(args)) return aerror("Badly formatted use of defmacro");
        LispObject bvl = car(args);
// Here if bvl is a list such as (u) I will expand it to be (u &optional g).
        if (consp(bvl) && cdr(bvl) == nil)
            args = cons(list3(car(bvl), opt_key, Lgensym(nil)),
                        cdr(args));
        if (is_symbol(fname))
        {   if ((qheader(fname) & SYM_CODEPTR) != 0) return fname;
            qheader(fname) = qheader(fname) | SYM_MACRO;
// Note that a name can have a definition as a macro and as a special form,
// and in that case the qfn() cell gives the special form and the qenv()
// cell the macro definition.  Otherwise at present I put 'undefined'
// in the qfn() cell, but in due course I will want something else as better
// protection against compiled code improperly attempting to call a macro.
            if ((qheader(fname) & SYM_SPECIAL_FORM) == 0)
            {   if (qfn1(fname) != undefined_1 &&
                    qvalue(redef_msg) != nil)
                {   debug_printf("\n+++ ");
                    loop_print_debug(fname);
                    debug_printf(" redefined as a macro\n");
                }
                set_fns(fname, undefined_0, undefined_1, undefined_2, undefined_3,
                        undefined_4up);
            }
            qenv(fname) = args;         // Sort of notional lambda present
            if (qvalue(comp_symbol) != nil &&
                qfn1(compiler_symbol) != undefined_1)
            {   LispObject t1, t2;
                {   RealSave save(fname);
                    if (!(consp(args) &&
                          consp(cdr(args)) &&
                          cdr(cdr(args)) == nil &&
                          (t1 = car(args),
                           t2 = cdr(car(cdr(args))),
                           equal(t1, t2))))
                    {   fname = save.val(1);
                        args = ncons(fname);
                        errexit();
                        (*qfn1(compiler_symbol))(compiler_symbol, args);
                    }
                    save.restore(fname);
                }
            }
            return fname;
        }
    }
    return aerror("defmacro");
}

static LispObject eval_when_fn(LispObject args, LispObject env)
// When interpreted, eval-when just looks for the situation EVAL.
{   LispObject situations;
    STACK_SANITY;
    if (!consp(args)) return nil;
    situations = car(args);
    args = cdr(args);
    while (consp(situations))
    {   if (car(situations) == eval_symbol) return progn_fn(args, env);
        situations = cdr(situations);
    }
    return nil;
}

static LispObject flet_fn(LispObject args, LispObject env)
{   LispObject my_env, d;
    STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    my_env = env;
    d = car(args);     // The bunch of definitions
    args = cdr(args);
    while (consp(d))
    {   LispObject w = car(d);
        if (consp(w) && consp(cdr(w)))
        {   LispObject w1;
            w1 = list2star(funarg, my_env, cdr(w));
            errexit();
            w1 = cons(w1, car(w));
            errexit();
            env = cons(w1, env);
        }
        d = cdr(d);
    }
// Treat body as (let nil ...) to get (declare ...) recognized.
    return let_fn_1(nil, args, env, BODY_LET);
}

LispObject function_fn(LispObject args, LispObject env)
{
// For most things this behaves just like (quote xxx), but
// (function (lambda (x) y)) gets converted to
// (funarg env (x) y).
    STACK_SANITY;
    if (consp(args) && cdr(args) == nil)
    {   args = car(args);
        if (consp(args) && car(args) == lambda)
            args = list2star(funarg, env, cdr(args));
        return args;
    }
    return aerror("function");
}


LispObject lambda_fn(LispObject args, LispObject env)
{
// (lambda ...) evaluates to itself.
    return cons(lambda, args);
}


LispObject go_fn(LispObject args, LispObject env)
{   LispObject p, tag;
    STACK_SANITY;
    if (!consp(args)) return aerror("go");
    else tag = car(args);
    for(p=env; consp(p); p=cdr(p))
    {   LispObject w = car(p), z;
        if (!consp(w)) continue;
        if (car(w) == fixnum_of_int(1) &&
            (z = car(cdr(w)), eql(z, tag)))
        {   exit_tag = w;
            exit_reason = UNWIND_GO;
            THROW(LispGo);  // only exit_tag matters here.
        }
    }
    return error(1, err_go_tag, tag);
}

static LispObject if_fn(LispObject args, LispObject env)
{   LispObject p=nil, tr=nil, fs=nil;
    STACK_SANITY;
    if (!consp(args)) return aerror("if");
    errexit();
    p = car(args);
    args = cdr(args);
    if (!consp(args)) return aerror("if");
    errexit();
    tr = car(args);
    args = cdr(args);
    if (!consp(args)) fs = nil;
    else
    {   fs = car(args);
        args = cdr(args);
        if (args != nil) return aerror("if");
        errexit();
    }
    stackcheck();
    errexit();
    p = eval(p, env);
    errexit();
    if (p == nil) return eval(fs, env);      // tail call on result
    else return eval(tr, env);               // ... passing back values
}

static LispObject labels_fn(LispObject args, LispObject env)
{   LispObject my_env, d;
    STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    errexit();
    my_env = env;
    d = car(args);     // The bunch of definitions
    while (consp(d))
    {   LispObject w = car(d);
        if (consp(w) && consp(cdr(w)))
        {   LispObject w1;
            w1 = list2star(funarg, nil, cdr(w));
            errexit();
            w1 = cons(w1, car(w));
            errexit();
            env = cons(w1, env);
        }
        d = cdr(d);
    }
// Now patch up the environments stored with the local defs so as to
// permit mutual recursion between them all.
    for (d=env; d!=my_env; d=cdr(d))
    {   LispObject w = cdr(car(car(d)));
        car(w) = env;
    }
    return let_fn_1(nil, cdr(args), env, BODY_LET);
}

static LispObject let_fn(LispObject args, LispObject env)
{   if (!consp(args)) return nil;
    STACK_SANITY;
    return let_fn_1(car(args), cdr(args), env, BODY_LET);
}

static LispObject letstar_fn(LispObject args, LispObject ienv)
// This will have to look for (declare (special ...)), unless
// I am in CSL mode.
{   if (!consp(args)) return nil;
    STACK_SANITY;
    stackcheck();
    errexit();
    RealSave save1(car(args), cdr(args), ienv); // bvl, body, env
    RealSave save2(PushCount(4));
    LispObject &bvl        = save1.val(1);
    LispObject &body       = save1.val(2);
    LispObject &env        = save1.val(3);
    LispObject &q          = save2.val(1);
    LispObject &p          = save2.val(2);
    LispObject &specenv    = save2.val(3);
    LispObject &local_decs = save2.val(4);
    for (;;)
    {   if (!consp(body)) break;
        p = macroexpand(car(body), env);
        errexit();
        body = cdr(body);
        if (!consp(p))
        {   if (stringp(p) && consp(body)) continue;
            body = cons(p, body);
            errexit();
            break;
        }
        if (car(p) != declare_symbol)
        {   body = cons(p, body);
            errexit();
            break;
        }
        for (p = cdr(p); consp(p); p = cdr(p))
        {   q = car(p);
            if (!consp(q) || car(q) != special_symbol) continue;
            // here q says (special ...)
            for (q=cdr(q); consp(q); q = cdr(q))
            {   local_decs = cons(car(q), local_decs);
                errexit();
            }
        }
    }
// Now I will start doing some binding...
    TRY
        for (; consp(bvl); bvl=cdr(bvl))
        {   LispObject z;
            q = car(bvl);
            if (consp(q))
            {   z = cdr(q);
                q = car(q);
                if (consp(z)) z = car(z);
                else z = nil;
            }
            else z = nil;
            if (!is_symbol(q) || q==nil || q==lisp_true)
            {   return error(1, err_bad_bvl, q);
            }
            else
            {   Header h = qheader(q);
                if (z != nil)
                    z = eval(z, env);
                if (h & SYM_GLOBAL_VAR)
                    return aerror1("attempt to bind", q);
                if (h & SYM_SPECIAL_VAR)
                {   p = z;
                    z = acons(q, qvalue(q), specenv);
                    errexit();
                    specenv = z;
                    qvalue(q) = p;
                }
                else
                {   for (p = local_decs; p!=nil; p = cdr(p))
                    {   LispObject w;
                        if (q != car(p)) continue;
                        car(p) = fixnum_of_int(0);
                        w = acons(q, qvalue(q), specenv);
                        errexit();
                        specenv = w;
                        w = acons(q, work_symbol, env);
                        errexit();
                        env = w;
                        qvalue(q) = z;
                        goto bound;
                    }
                    q = acons(q, z, env);
                    errexit();
                    env = q;
                bound:  ;
                }
            }
        }
        while (local_decs!=nil)         // Pervasive special declarations
        {   q = car(local_decs);
            local_decs=cdr(local_decs);
            if (!is_symbol(q)) continue;
            q = acons(q, work_symbol, env);
            errexit();
            env = q;
        }
        body = progn_fn(body, env);
        errexit();
        for (bvl = specenv; bvl != nil; bvl = cdr(bvl))
        {   LispObject w = car(bvl), v = car(w), z = cdr(w);
            qvalue(v) = z;
        }
// WELL: the following line will just return from an inner (lambda)
// function not from the whole of letstar_fn, and the value returned
// is then ignored!
        return body;
    CATCH(LispException)
        for (bvl = specenv; bvl != nil; bvl = cdr(bvl))
        {   LispObject w = car(bvl), v = car(w), z = cdr(w);
            qvalue(v) = z;
        }
        RETHROW;
    END_CATCH;
    errexit();
// Note that body goes out of scope as the destructor for save1 runs,
// so it is important that C++ picks up its value before performing the
// destructor action!
    return body;
}

// In many ways I think it is astonishing how few special forms there are.
// OK some are listed here and some in eval3.cpp, but both the lists are
// fairly short.

setup_type const eval2_setup[] =
{   DEF_special("and",           and_fn),
    DEF_special("catch",         catch_fn),
    DEF_special("cond",          cond_fn),
    DEF_special("eval-when",     eval_when_fn),
    DEF_special("function",      function_fn),
    DEF_special("lambda",        lambda_fn),
    DEF_special("go",            go_fn),
    DEF_special("if",            if_fn),
    DEF_special("let*",          letstar_fn),
// DE and DM are used as low level primitives in the Common Lisp bootstrap
    DEF_special("de",            defun_fn),
    DEF_special("dm",            defmacro_fn),
    DEF_special("declare",       declare_fn),
    DEF_special("compiler-let",  compiler_let_fn),
    DEF_special("flet",          flet_fn),
    DEF_special("labels",        labels_fn),
// For the purposes of Reduce there is a problem with the names LET and BLOCK
// because they are used in the system, and having them as Lisp-level special
// forms would clash. I provide implementations but with names prefixed by
// "~". This is perhaps an issue that ough to get resolved some time.
//  DEF_special("block",         block_fn),
//  DEF_special("let",           let_fn),
    DEF_special("~block",        block_fn),
    DEF_special("~let",          let_fn),
    {nullptr,                    nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of eval2.cpp
