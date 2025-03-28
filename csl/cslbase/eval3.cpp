// eval3.cpp                               Copyright (C) 1991-2025 Codemist

//
// Interpreter (part 3).
// Implementations of special forms (interpreted versions).
//
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


#define BODY_LET            0
#define BODY_COMPILER_LET   1
#define BODY_PROG           2

static LispObject macrolet_fn(LispObject args, LispObject env)
{   LispObject d;
    STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    d = car(args);     // The bunch of definitions
    while (consp(d))
    {   LispObject w = car(d);     // w = (name bvl ...)
        if (consp(w) && consp(cdr(w)))
        {
// Here I need to call (expand-definer <form> nil) to map
// macro specifications with all the possible magic options into ones
// which just take 2 args, a form and an environment.
            w = cons(expand_def_symbol, w);
            errexit();
            w = Lfuncall_3(nil, expand_def_symbol, w, nil);
            errexit();
// I expect expand-definer to return either
//     (~~defmacro name bvl ...)
// OR  (progn XXX (~~defmacro name bvl ...))
//     where XXX is exactly one form.
            if (car(w) == progn_symbol)
                w = car(cdr(cdr(w)));
            w = cdr(w);
            w = cons(cdr(w), car(w));
            errexit();
            env = cons(w, env);
            errexit();
        }
        d = cdr(d);
    }
    return let_fn_1(nil, cdr(args), env, BODY_LET);
}

static LispObject mv_prog1_fn(LispObject args, LispObject env)
{   LispObject r, rl;
    STACK_SANITY;
    int nargs, i;
    if (!consp(args)) return nil;
    stackcheck();
    {   r = eval(car(args), env);
        errexit();
    }
    rl = nil;
    nargs = exit_count;
    {
// I could use the Lisp stack to save things here, but I hope that this
// function is not used much and performance will not matter.
        for (i=nargs; i>=2; i--)
            rl = cons_no_gc((&mv_2)[i-2], rl);
        rl = cons_gc_test(rl);
        errexit();
        {   while (is_cons(args = cdr(args)) && args!=nil)
            {   eval(car(args), env);
                errexit();
            }
        }
        for (i = 2; i<=nargs; i++)
        {   (&mv_2)[i-2] = car(rl);
            rl = cdr(rl);
        }
    }
    return nvalues(r, nargs);
}

static LispObject or_fn(LispObject args, LispObject env)
// also needs to be a macro for Common Lisp
{   if (!consp(args)) return nil;
    stackcheck();
    STACK_SANITY;
    for (;;)
    {   LispObject v = car(args);
        args = cdr(args);
        if (!consp(args)) return eval(v, env);
        v = eval(v, env);
        errexit();
        if (v != nil) return v;
    }
}

// Note that (BLOCK ...) also catches LispReturnFrom exceptions, and that
// Common Lisp really thinks of PROG as a combination of LET, BLOCK and
// TAGBODY.

static LispObject prog_fn(LispObject args, LispObject env)
{   if (!consp(args) || !consp(cdr(args))) return nil;
    stackcheck();
    LispObject my_tag = nil;
// I need to augment the (lexical) environment with a null block
// tag so that (return ..) will work as required. See block_fn for
// further elaboration since (block ..) is the main way of introducing
// new block tags.
    my_tag = cons(fixnum_of_int(0), nil);
    errexit();
    env = cons(my_tag, env);
    errexit();
    TRY
        let_fn_1(car(args), cdr(args), env, BODY_PROG);
    CATCH(LispReturnFrom)
        car(my_tag) = fixnum_of_int(2);    // Invalidate
        if (exit_tag == my_tag)
            return exit_value;  // exit_count already OK here
// It could be that the RETURN(-FROM) is heading to be handled by some
// enclosing block.
        else RETHROW;
    ANOTHER_CATCH(LispResource)
        RETHROW;
    ANOTHER_CATCH(LispSimpleError)
        int _reason = exit_reason;
        if (SHOW_FNAME)
        {   err_printf("\nEvaluating: "); // A bit of backtrace on errors
            errexit();
            loop_print_error(args);
            errexit();
        }
        exit_reason = _reason;
        RETHROW;
    END_CATCH;
    return nil;
}

LispObject progn_fn(LispObject args, LispObject env)
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    f = nil;
    for (;;)
    {   f = car(args);
        args = cdr(args);
        if (!consp(args)) break;
        on_backtrace(
            static_cast<void>(eval(f, env)),
            errexit();
            // Action for backtrace here...
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(f);
            });
    }
    errexit();
    return eval(f, env);    // tail call on last item in the progn
}

static LispObject prog1_fn(LispObject args, LispObject env)
// prog1 and prog2 will be implemented as macros for Common Lisp,
// and are here implemented as special forms too in the expectation
// that that will be good for performance.
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return nil; // (prog1) -> nil
    stackcheck();
    errexit();
    {   f = car(args);
        f = eval(f, env);              // first arg
        errexit();
    }
    for (;;)
    {   args = cdr(args);
        if (!consp(args)) break;
        static_cast<void>(eval(car(args), env));
        errexit();
    }
    return f;     // always hands back just 1 value
}

static LispObject prog2_fn(LispObject args, LispObject env)
{   LispObject f;
    STACK_SANITY;
    if (!consp(args)) return nil; // (prog2) -> nil
    stackcheck();
    errexit();
    {   static_cast<void>(eval(car(args), env));  // eval & discard first arg
        errexit();
    }
    errexit();
    args = cdr(args);
    if (!consp(args)) return nil; // (prog2 x) -> nil
    {   f = eval(car(args), env);                       // second arg
        errexit();
    }
    for (;;)
    {   args = cdr(args);
        if (!consp(args)) break;
        {   static_cast<void>(eval(car(args), env));
            errexit();
        }
    }
    return f;     // always hands back just 1 value
}

#define specenv save.val(5)
#define vals    save.val(4)
#define syms    save.val(3)
#define env     save.val(2)
#define args    save.val(1)

class Unbind_progv_specials
{   LispObject *saveStack;
    LispObject *specenv_p;
public:
    Unbind_progv_specials(LispObject *ss)
    {   saveStack = stack;
        specenv_p = ss;
    }
    ~Unbind_progv_specials()
    {   stack = saveStack;
        while (*specenv_p != nil)
        {   LispObject p = car(*specenv_p);
            qvalue(car(p)) = cdr(p);
            *specenv_p = cdr(*specenv_p);
        }
    }
};

static LispObject progv_fn(LispObject args_x, LispObject env_x)
{   LispObject syms_x, vals_x, specenv_x, w;
    STACK_SANITY;
    if (!consp(args_x)) return nil;
    stackcheck();
    errexit();
    syms_x = vals_x = specenv_x = nil;
    syms_x = car(args_x);
    args_x = cdr(args_x);
    RealSave save(args_x, env_x, syms_x, vals_x, specenv_x);
    syms = eval(syms, env);
    errexit();
    if (!consp(args)) return nil;
    w = car(args);
    args = cdr(args);
    vals = eval(w, env);
    errexit();
    if (!consp(args)) return nil;
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
        errexit();
// If I were to take the error exit here then some variables would have
// been set to their new values and some not. That would be a mess! So if the
// above CONS fails and triggers an exit things are bad. I may need to
// pre-allocate the space, but because PROGV is esoteric (and not used by
// Reduce) I am not going to go to the trouble YET.
        qvalue(v) = w;
        specenv = cons(w1, specenv);
    }
    {   Unbind_progv_specials unbind_progv_variables(&specenv);
        args = progn_fn(args, env);
    }
    return specenv;
}

#undef specenv
#undef vals
#undef syms
#undef env
#undef args

LispObject quote_fn(LispObject args, LispObject)
{   if (consp(args) && cdr(args) == nil) return car(args);
    return aerror("quote");
}

static LispObject return_fn(LispObject args, LispObject env)
{
// First check that the block name (nil in this case) is lexically available
    STACK_SANITY;
    LispObject p;
    stackcheck();
    errexit();
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
    {   env = eval(car(args), env);
        errexit();
        exit_value = env;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    THROW(LispReturnFrom);
}

static LispObject return_from_fn(LispObject args, LispObject env)
{   LispObject p, tag;
    stackcheck();
    errexit();
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
    {   env = eval(car(args), env);
        errexit();
        exit_value = env;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_RETURN;
    THROW(LispReturnFrom);
}

static LispObject setq_fn(LispObject args, LispObject env)
{   LispObject var, val = nil;
    STACK_SANITY;
    stackcheck();
    errexit();
    while (consp(args))
    {   var = car(args);
        if (!is_symbol(var) || var == nil || var == lisp_true ||
            (qheader(var) & SYM_KEYWORD_VAR) == SYM_KEYWORD_VAR)
        {   return aerror1("setq (bad variable)", var);
        }
        args = cdr(args);
        if (consp(args))
        {   {   val = car(args);
                val = eval(val, env);
                errexit();
            }
            errexit();
            args = cdr(args);
        }
        else val = nil;
        if ((qheader(current_function) & SYM_TRACESET) != 0)
        {   freshline_trace();
            errexit();
// I want loop_print_trace to avoid exiting with errors!
            loop_print_trace(current_function);
            errexit();
            trace_printf(":  ");
            errexit();
            loop_print_trace(var);
            errexit();
            trace_printf(" := ");
            errexit();
            loop_print_trace(val);
            errexit();
            trace_printf("\n");
            errexit();
        }
        if ((qheader(var) & SYM_KEYWORD_VAR) == SYM_SPECIAL_VAR ||
            (qheader(var) & SYM_KEYWORD_VAR) == SYM_GLOBAL_VAR)
            qvalue(var) = val;
        else
        {   LispObject p = env, w;   // Here it seems to be a local variable,
            // or it could be locally FLUID.
            for (;;)
            {   if (!consp(p))
                {   qheader(var) = qheader(var) | SYM_SPECIAL_VAR;
#ifdef SOME_TIME_LATER
// If I display this message - which could be viewed as a proper error report -
// it leds to multiple failures in the Reduce regressions where scripting
// assumes that assignment to a variable is valid without any declaration.
                    debug_printf("\n+++++ ");
                    errexit();
                    loop_print_debug(var);
                    errexit();
                    debug_printf(" proclaimed SPECIAL by SETQ\n");
                    errexit();
#endif
                    qvalue(var) = val;
                    break;
                }
                w = car(p);
                if (car(w) == var)
                {   if (cdr(w) == work_symbol) qvalue(var) = val;
                    else cdr(w) = val;
                    break;
                }
                p = cdr(p);
            }
        }
    }
    return val;
}

// tagbody does the bit of PROG that covers labels.

LispObject tagbody_fn(LispObject args, LispObject env)
{
// Bind the labels that occur in this block.  Note that I invalidate
// these bindings if I ever exit from this block, so that nobody
// even thinks that they can use (go xx) to get back in.
    stackcheck();
    errexit();
    STACK_SANITY;
    LispObject p    = nil;
    LispObject oldenv = env;
    for (p=args; consp(p); p=cdr(p))
    {   LispObject w = car(p);
        if (!consp(w))
        {   w = cons(fixnum_of_int(1), p);
            env = cons(w, env);
            errexit();
        }
    }
// That has put my new version of env with bindings of the form
//    (1 . <location in the tagbody>)
// for each label present. In other words it goes
//    env = ( ... (1 labelname <continuation>) ... )
// where bindings for variable in the environment would have a symbol
// so the integer 1 here distinguishes these as label bindings.
// (go xx) sets exit_tag to xx, which is then noticed next time tagbody
// is about to do anything.
    for (p=args; consp(p); p = cdr(p))
    {
// Within this block args will store the particular statement being
// processed.
        args = car(p);
        if (!is_cons(args)) continue; // Do not evaluate labels
        TRY
            eval(args, env);
        CATCH(LispGo)
            int _reason = exit_reason;
// I need to do this search. Well in the code that implemented GO I checked
// that the destination label was bound as a label. That was so that I could
// give a decent diagnostic if it was not. The scan here is to see if it is
// a label in THIS level of a tagbody... and if not I will hand it upwards.
            for (p=env; p!=oldenv; p=cdr(p)) // scan label bindings
            {   LispObject w = car(p);
                if (w != exit_tag) continue;
// Now I have found the label I needed to jump to. Hoorah.
                p = cdr(w);
                break;
            }
// At the end of the loop either p==oldenv in which case I had not found
// the desired label as one associated with this particular tagbody, or
// it is the new place within the tagbody for me to resume execution.
            if (p != oldenv) continue; // take the GOTO
// If I drop out of the loop that means that the target label was
// not present in this block. Tidy up the label bindings to be very
// certain nobody can re-use them. The risk here would be if within a
// tagbody somebody has saved the closure of (eg) a lambda-expression that
// contained a relevent GO. This is not something that could every happen
// in Standard Lisp, but it could in Common Lisp!
            while (env != oldenv)
            {   car(car(env)) = fixnum_of_int(2);
                env = cdr(env);
            }
// Because this is a sort of error I will display a message. Well with
// Common Lisp one would be entitled to perform a GO that exited through
// multiple levels, and a message here would not be appropriate
#ifndef COMMON
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(args);
            }
#endif // COMMON
// Re-throw the LispGo exception to try again at some outer level.
            exit_reason = _reason;
            RETHROW;
        ANOTHER_CATCH(LispResource)
            RETHROW;
        ANOTHER_CATCH(LispSimpleError)
            int _reason = exit_reason;
            if (SHOW_FNAME)
            {   err_printf("\nEvaluating: ");
                loop_print_error(args);
            }
// Re-throw some other exception that counted as an error.
            exit_reason = _reason;
            RETHROW;
        END_CATCH;
    }
// This is where I drop off the end of the tagbody, so I tidy up and
// return nil.
    while (env != oldenv)
    {   car(car(env)) = fixnum_of_int(2);
        env = cdr(env);
    }
    return nil;
}

static LispObject the_fn(LispObject args, LispObject env)
// in effect an identity function for the present
{   if (!consp(args)) return nil;
    args = cdr(args);
    if (!consp(args)) return nil;
    args = car(args);
    return eval(args, env);
}

// In Common Lisp mode THROW has to be a special form because of the
// case where the information being thrown involves multiple values. For
// Standard Lisp I can perfectly well provide a simple function.

static LispObject throw_fn(LispObject args, LispObject env)
{   LispObject tag, p;
    STACK_SANITY;
    if (!consp(args)) return aerror("throw");
    stackcheck();
    errexit();
    tag = car(args);
    args = cdr(args);
    {   tag = eval(tag, env);
        errexit();
    }
    for (p = catch_tags; p!=nil; p=cdr(p))
        if (tag == car(p)) goto tag_found;
    return aerror("throw: tag not found");
tag_found:
    if (consp(args))
    {   tag = car(args);
        tag = eval(tag, env);
        errexit();
        exit_value = tag;
    }
    else
    {   exit_value = nil;
        exit_count = 1;
    }
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    THROW(LispThrow);
}

LispObject Lthrow_one_value(LispObject env, LispObject tag, LispObject val)
{   SingleValued fn;
    LispObject p;
    STACK_SANITY;
    for (p = catch_tags; p!=nil; p=cdr(p))
        if (tag == car(p)) goto tag_found;
    return aerror("throw: tag not found");
tag_found:
    exit_value = val;
    exit_count = 1;
    exit_tag = p;
    exit_reason = UNWIND_THROW;
    THROW(LispThrow);
}

LispObject Lthrow_nil(LispObject env, LispObject tag)
{   SingleValued fn;
    return Lthrow_one_value(nil, tag, nil);
}

static LispObject unless_fn(LispObject args, LispObject env)
{   LispObject w;
    STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    errexit();
    {   w = eval(car(args), env);
        errexit();
    }
    if (w != nil) return nil;
    else return progn_fn(cdr(args), env);
}

static LispObject unwind_protect_fn(LispObject args, LispObject env)
{   STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    LispObject r;
    TRY
        r = eval(car(args), env);
    CATCH(LispException)
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
        LispObject savetraptime = qvalue(trap_time);
        qvalue(trap_time) = nil; // No timeouts in recovery code
        xv = exit_value;
        xt = exit_tag;
        xc = exit_count;
        xr = exit_reason;
        LispObject rl = nil;
        for (int i=xc; i>=2; i--)
        {   rl = cons((&mv_2)[i-2], rl);
            errexit();
        }
// I am going to take the view that if there is a failure during execution
// of the cleanup forms then full cleanup will not be complete, and this
// can include the case of "cons" failing right before anything else.
// Now I will obey the cleanup 
        while (is_cons(args = cdr(args)) && args!=nil)
        {   eval(car(args), env);
            errexit();
        }
        for (int i = 2; i<=xc; i++)
        {   (&mv_2)[i-2] = car(rl);
            rl = cdr(rl);
        }
        exit_value = xv;
        exit_tag   = xt;
        exit_count = xc;
        exit_reason = xr;
        qvalue(trap_time) = savetraptime;
        RETHROW;                   // reinstate the exception
    END_CATCH;
// Now code (just like multiple-value-prog1) that evaluates the
// cleanup forms in the case that the protected form exits normally.
    int nargs = exit_count;
    LispObject rl = nil;
    for (int i=nargs; i>=2; i--)
    {   rl = cons((&mv_2)[i-2], rl);
        errexit();
    }
    while (is_cons(args = cdr(args)) && args!=nil)
    {   eval(car(args), env);
        errexit();
    }
    for (int i=2; i<=nargs; i++)
    {   (&mv_2)[i-2] = car(rl);
        rl = cdr(rl);
    }
    return nvalues(r, nargs);
}

// Errorset is not defined as part of COMMON Lisp but I want it in
// any Lisp system that I use notwithstanding that.

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
// Here I have found some fluid binding that need to be unwound. The code
// here is similar to that for FREERSTR.
            bv = *sp--;
            n = length_of_header(vechdr(bv));
            while (n>CELL)
            {   LispObject v = *reinterpret_cast<LispObject *>(
                                   (intptr_t)bv + n - (CELL + TAG_VECTOR));
                n -= CELL;
                qvalue(v) = *sp--;
            }
        }
        else if (w == static_cast<LispObject>(SPID_PVBIND))
        {   bv = *sp--;
            while (bv != nil)
            {   LispObject w = car(bv);
                qvalue(car(w)) = cdr(w);
                bv = cdr(bv);
            }
        }
    }
// If "findcatch" is true this code must actually update the stack pointer -
// otherwise it must not. Ugly! The only use with findcatch set true is
// from the bytecode interpreter (bytes1.c)
    if (findcatch) stack = sp;
}

bool force_backtrace = false;

static LispObject errorset3(LispObject env,
                            LispObject form,
                            LispObject fg1,
                            LispObject fg2)
{   LispObject r;
    STACK_SANITY;
    uint32_t flags = miscflags;
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
    errorset_msg = nullptr;
    TRY
        r = eval(form, nil);
    CATCH(LispResource)
        RETHROW;
    ANOTHER_CATCH(LispSimpleError)
        if (miscflags & FNAME_FLAG) err_printf("Inside: errorset\n");
        if (stop_on_error) RETHROW;
// I am not going to catch exceptions such as the ones that restart the
// system - only ones that couunt as "errors".
        miscflags = (flags & BACKTRACE_MSG_BITS) |
                    (miscflags & ~BACKTRACE_MSG_BITS);
// Now if within this errorset somebody had gone (enable-errorset min max)
// I must reset flags on the way out...
        miscflags = (miscflags&~BACKTRACE_MSG_BITS) |
                    (flags&BACKTRACE_MSG_BITS); 
        if (consp(exit_value)) exit_value = nil;
        return exit_value;
    END_CATCH;
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
    return r;
}

LispObject Lerrorset_3(LispObject env, LispObject form,
                       LispObject fg1, LispObject fg2)
// This is not a special form, but is put into the code here because,
// like unwind-protect, it has to re-gain control after an evaluation
// error.
{   SingleValued fn;
    STACK_SANITY;
    return errorset3(env, form, fg1, fg2);
}

LispObject Lerrorset_1(LispObject env, LispObject form)
{   SingleValued fn;
    return errorset3(env, form, nil, nil);
}


LispObject Lerrorset_2(LispObject env, LispObject form, LispObject ffg1)
{   SingleValued fn;
    return errorset3(env, form, ffg1, nil);
}

// (resource!-limit form time space io errors C_stack Lisp_stack)
//   Evaluate the given form and if it succeeds return a
//   list whose first item is its value. If it fails in the ordinary manner
//   then its failure (error/throw/restart etc) gets passed back through
//   here in a transparent manner. But if it runs out of resources this
//   function catches that fact and returns an atomic value.
//   Resource limits are not precise, and are specified by the
//   subsequent arguments here:
//      time:  an integer giving a time allowance in seconds. Note that the
//             shorted limit supported is 2 seconds and if you say "1" it
//             is increased to 2 for you.
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
// Note that code within CSL can call the C function resource_exceeded() to
// note that resources have expired.

uint64_t time_base = 0, time_now = 0;
int64_t                  space_base = 0,   io_base = 0,   errors_base = 0;
int64_t                  space_now = 0,    io_now = 0,    errors_now = 0;
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
{   SingleValued fn;
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
// [ (3) It fails because it raises a C-level signal. ... maybe no longer!]
// (4) It fails by raising a resource-exhausted complaint.
    time_now = read_clock()/1000;  // Now expressed in milliseconds
    TRY
        time_base   = time_now;
        space_base  = space_now;
        io_base     = io_now;
        errors_base = errors_now;
        if (lltime >= 0)
        {   int w;
// I make 2 seconds the smallest I can specify as a timeout because
// I could do so just a smidgin before the clock time and end up with no
// slack at all.
            if (lltime < 2) lltime = 2;
            w = time_base + 1000*lltime;
            if (time_limit >= 0 && time_limit < w) w = time_limit;
// This sets time_limit to an absolute time expressed in milliseconds.
            time_limit = w;
        }
        if (llspace >= 0)
        {   int w;
// Ok, the USER specified things in megaconses, but internally I will
// count in "CSL pages". The standard CSL page size is 4Mbytes, ie 0.5 or
// 0.25 megaconses so I multiply by 2 or 4 here (for 32 or 64-bit systems).
            llspace *= (2*sizeof(LispObject)*1024*1024)/PAGE_POWER_OF_TWO;
            if (llspace < 2) llspace = 2;
            w = space_base + llspace;
            if (space_limit >= 0 && space_limit < w) w = space_limit;
// keep going until space_base reaches space_limit. This counts in CSL pages.
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
    CATCH(LispResource)
// It is really important that the code here does not repeat the
// raising of the resource overflow!
        time_limit = -1; space_limit = -1; io_limit = -1; errors_limit = 0;
        form = list4(fixnum_of_int(r0),
                     fixnum_of_int(r1),
                     fixnum_of_int(r2),
                     fixnum_of_int(r3));
        errexit();
        qvalue(resources) = form;
// Here I had a resource limit trap
        return nil;
    END_CATCH;
// The guarded code may have exited with some other exception!
    errexit(); 
// I would like the result to show what resources had been used, but for now
// I just use ncons to wrap the resuult up.
    r = ncons(r);
    errexit(); 
    {   form = list4(fixnum_of_int(r0),
                     fixnum_of_int(r1),
                     fixnum_of_int(r2),
                     fixnum_of_int(r3));
        errexit(); 
    }
    qvalue(resources) = form;
    return r;
}

LispObject Lresource_limit_4up(LispObject env, LispObject form,
                               LispObject ltime,
                               LispObject lspace, LispObject a4up)
{   SingleValued fn;
    LispObject lio, lerrors, Csk, Lsk;
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
{   SingleValued fn;
    return resource_limit7(env, form, ltime,
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1));
}

LispObject Lresource_limit_3(LispObject env, LispObject form,
                             LispObject ltime, LispObject lspace)
{   SingleValued fn;
    return resource_limit7(env, form, ltime, lspace,
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1),
                           fixnum_of_int(-1));
}


static LispObject when_fn(LispObject args, LispObject env)
{   LispObject w;
    STACK_SANITY;
    if (!consp(args)) return nil;
    stackcheck();
    {   w = eval(car(args), env);
        errexit();
    }
    if (w == nil) return nil;
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
{   DEF_special("or",                   or_fn),
    DEF_special("prog",                 prog_fn),
    DEF_special("prog1",                prog1_fn),
    DEF_special("prog2",                prog2_fn),
    DEF_special("progn",                progn_fn),
    DEF_special("quote",                quote_fn),
    DEF_special("return",               return_fn),
    DEF_special("setq",                 setq_fn),
    DEF_special("tagbody",              tagbody_fn),
    DEF_special("unless",               unless_fn),
    DEF_special("unwind-protect",       unwind_protect_fn),
    DEF_special("when",                 when_fn),
    DEF_special("macrolet",             macrolet_fn),
    DEF_special("multiple-value-call",  mv_call_fn),
    DEF_special("multiple-value-prog1", mv_prog1_fn),
    DEF_special("progv",                progv_fn),
    DEF_special("return-from",          return_from_fn),
    DEF_special("the",                  the_fn),
    DEF_special("throw",                throw_fn),
    {nullptr,                           nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of eval3.cpp
