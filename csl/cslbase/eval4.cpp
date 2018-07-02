// eval4.cpp                              Copyright (C) 1991-2017, Codemist

//
// Bytecode interpreter/main interpreter interfaces
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

//
// Here is a bit of a commentary about calling arrangements.
//
// When a Lisp function is called in the C code it will have 0, 1, 2, 3
// or 4 arguments (never more). If present the 4th argument will be a list
// of lisp-level arguments 4, 5, 6 ...
// The entrypoints such as bytecoded3() etc here are C code and will thus
// be invoked in this way. They end up transferring control to the
// bytecode interpreter. The bytecode interpreter is entered with arguments
// on the (Lisp) stack, and there can be as many as the function wants.
// If there is a &REST argument that corresponds to one argument that will
// receive a list value. Thus that amount of stack used is related to the
// number of arguments written in the function definition. Thus a case such
// as (DE foo (a1 a2 ... a1000) ...) could lead to huge stack usage, but I
// expect that not to arise.
// So in a case where the function definition has been (DE foo (a b &REST c)
// ...) and the call was (as it were) (foo A1 A2 ... A1000), the C code
// would see four arguments A1, A2, A3 and (A4 .. A1000) and would re-package
// them to put three items on the stack for the bytecode system: A1, A2 and
// (A3 A4 ... A1000).
// This means that the interface code here needs to know just how many values
// a bytecoded function expects to find on its stack. If the function
// concerned is a simple one taking 0, 1, 2 or 3 arguments that is trivial.
// If a fixed numner of arguments is involved but that is at least 4 then
// the interface code will scan its list input to count values, and the byte
// stream has an initial prefix byte indicating the desired argument
// count. This imposes a limit at 255 arguments.
// If &OPTIONAL or &REST arguments are involved then the bytestream will
// have a pair of initial bytes giving the smallest and largest number of
// direct arguments (ie ones to be used before any remaining ones get
// collected by &REST). If all the &OPTIONAL values just default to NIL then
// that conversion is done here. In more complicated cases any optional
// arguments not provided with proper values are passed using a marker
// value SPID_NOARG that the bytecode can inspect and deal with as it sees
// fit.
// &KEY arguments (to the extent that they are supported!) are merely handled
// via the &REST machanism.
// 

// I will expect most calls to be to functions with rigidly fixed known
// numbers of arguments, and the other more complicated cases may well
// be handled in ways intended to make the code easy to write even if doing
// so impacts performance.



// Each of these entrypoints to the bytecode interpreter preserves litvec
// and codevec. Just about the only place these variable are set is within
// the bytecode interpreter.

LispObject bytecoded_0(LispObject def)
{
// Note that when I have a conservative garbage collector the mess
// of SAVE_CODEVEC can be removed, and that should at least slightly
// speed things up.
    SAVE_CODEVEC;
    push(def);
    LispObject r;
// I can use START_TRY_BLOCK without "try" if there are not going to be any
// "catch" clauses at this level! And I do not need a catch here because
// that would be used to arrange to print arguments in a backtrace, and I have
// no arguments here to diaplay.
    {   START_TRY_BLOCK;
        r = bytestream_interpret(CELL-TAG_VECTOR, def, stack);
    }
    return r;
}

LispObject bytecoded_1(LispObject def, LispObject a)
{   SAVE_CODEVEC;
    push2(def, a);
    LispObject r;
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(CELL-TAG_VECTOR, def, stack-1);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
// START_TRY_BLOCK arranges to preserve the stack pointer and restore it so
// that when I get here it is just as it was at the start of "try".... But
// there is a delicacy! The argument(s) are pushed onto the stack on a
// callee-pops basis, so if I exited successfully they would have been
// discarded. But in the various exceptional exit cases this will probably not
// have happened! There may be some odd consequnces if the function I
// had been invoking did a tail-call and the exception was raised within that,
// since then the arguments for the original function are rather liable to
// have been lost.
        pop(a);
// IF something went wrong I should have displayed the name of the function
// already - what I want to do here is to display the arguments it was
// called on. Well in some cases the variables concerned may have been
// updated or overwritten, but let's still do something that will work in
// enough cases to be valuable.
        if (SHOW_ARGS)
        {   err_printf("Arg1: ");
            loop_print_error(a);
            err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
// Note that a destructor set up by SAVE_CODEVEC gets activated here and
// that restores the stack pointer and also values of codevec and litvec.
    return r;
}

LispObject bytecoded_2(LispObject def, LispObject a, LispObject b)
{   SAVE_CODEVEC;
    push3(def, a, b);
    LispObject r;
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(CELL-TAG_VECTOR, def, stack-2);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   err_printf("Arg 1: ");
            loop_print_error(stack[-1]); err_printf("\n");
            err_printf("Arg 2: ");
            loop_print_error(stack[0]); err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject bytecoded_3(LispObject def, LispObject a, LispObject b, LispObject c)
{   SAVE_CODEVEC;
    push4(def, a, b, c);
    LispObject r;
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(CELL-TAG_VECTOR, def, stack-3);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   err_printf("Arg1: ");
            loop_print_error(stack[-2]); err_printf("\n");
            err_printf("Arg2: ");
            loop_print_error(stack[-1]); err_printf("\n");
            err_printf("Arg3: ");
            loop_print_error(stack[0]); err_printf("\n");
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

static inline int countargs(LispObject a4up)
{    int r = 3;
     while (a4up != nil)
     {   r++;
         a4up = qcdr(a4up);
     }
     return r;
}

LispObject bytecoded_4up(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   SAVE_CODEVEC;
    int nargs = countargs(a4up);
    LispObject r = qcar(qenv(def));   // the vector of bytecodes
    if (nargs != ((unsigned char *)data_of_bps(r))[0])
        error(2, err_wrong_no_args, def, fixnum_of_int(nargs));
// I now know that there will be the right number of arguments.
    push(def);
    push3(a1, a2, a3);
    for (int i=4; i<=nargs; i++)
    {   push(qcar(a4up));
        a4up = qcdr(a4up);
    }
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(CELL-TAG_VECTOR+1, def, stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (int i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject nreverse2(LispObject a, LispObject b)
{   while (consp(a))
    {   LispObject c = a;
        a = qcdr(a);
        qcdr(c) = b;
        b = c;
    }
    return b;
}

// The code that follows is just used to support compiled code that
// has &optional or &rest arguments.

static LispObject byteopt(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up, LispObject defaultval, bool restp)
{   LispObject r;
    int i, wantargs, wantopts;
    SAVE_CODEVEC;
// From calls that passed a small number of arguments I will invoke this as
// 0:  byteopt(SPID_NOARG, SPID_NOARG, SPID_NOARG, nil, ...)
// 1:  byteopt(arg1, SPID_NOARG, SPID_NOARG, nil, ...)
// 2:  byteopt(arg1, arg2, SPID_NOARG, nil, ...)
// 3:  byteopt(arg1, arg2, arg3, nil, ...)
// 4:  byteopt(arg1, arg2, arg3, list(arg4), ...)
// On that basis I can work out how many arguments have actually been provided.
    int nargs;
    if (a1 == SPID_NOARG) nargs = 0;
    else if (a2 == SPID_NOARG) nargs = 1;
    else if (a3 == SPID_NOARG) nargs = 2;
    else nargs = countargs(a4up);
// In this case the first 2 bytes of the bytecode stream give and upper and
// lower bound for arguments ahead of any &REST ones.
    r = qcar(qenv(def));
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs || (!restp && nargs > wantargs+wantopts))
        error(2, err_wrong_no_args, def,
                     fixnum_of_int((int32_t)nargs));
// Now to make life easier for myself I will collect ALL the arguments as
// a list. I will keep that in a4up, which in some sense now becomes "a1up".
    switch (nargs)
    {   case 0:
            a4up = nil;
            break;
        case 1:
            a4up = ncons(a1);
            break;
        case 2:
            a4up = list2(a1, a2);
            break;
        default:
            a4up = list3star(a1, a2, a3, a4up);
            break;
    }
// I know there are enough arguments for the ones that are mandatory. I will
// now pad the list of arguments so that there is something for every
// &OPTIONAL one too. In the easy case I will just default to NIL and the
// bytecodes will not do anything more. In the complicated case I will pass
// SPID_NOARG to mark missing arguments, and the bytecode stuff must check
// for that and fill in the non-nil default.
    if (nargs < wantargs+wantopts)
    {   a4up = nreverse(a4up);
        while (nargs < wantargs+wantopts)
        {   push(def);
// Note that defaultval will be either nil or SPID_NOARG and neither
// of those change address during garbage collection, so I do not need to
// take special action to save the value.
            a4up = cons(defaultval, a4up);
            pop(def);
            nargs++;
        }
        if (restp)
        {   push2(def, a4up);
// On this path the number of actual arguments could not even supply all
// &OPTIONAL args, and so the &RESR value will definitely be nil. So stick
// a NIL on the end.
            a1 = ncons(nil);
            pop2(a4up, def);
            a4up = nreverse2(a4up, a1);
            nargs++; // allow for the &REST arg.
        }
        else a4up = nreverse(a4up);
    }
// Now I have at least the number of arguments that I need to satisfy all
// required and &OPTIONAL ones. I may still need to think about &REST.
    else if (restp) // There is an extra &REST argument
    {   LispObject ra = nil;
        a4up = nreverse(a4up);
// a4up is at present (a<n> a<n-1> ... a4 a3 a3 a1), nargs is its
// length. So I can pick off nargs-(wantargs+optargs) items to make
// a &REST argument...
        while (nargs > wantargs+wantopts)
        {   push2(def, qcdr(a4up));
            ra = cons(qcar(a4up), ra);
            pop2(a4up, def);
        }
// Here I have (eg) a4up = (a3 a2 a1) and ra = (a4 a5 ...).
        push2(def, a4up);
        a4up = ncons(ra);
        pop2(ra, def);
// Make a final extra argument out of the list, and then reverse the rest
// of the arguments back, to get (eg again) (a1 a2 a3 (a4 a5 ...)).
        a4up = nreverse2(a4up, ra);
        nargs = wantargs + wantopts + 1;
    }
// I have now handled &OPTIONAL and &REST issues, and a4up is now a list of
// length nargs.
    for (int i=0; i<nargs; i++)
    {   push(qcar(a4up));
        a4up = qcdr(a4up);
    }
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(CELL-TAG_VECTOR+2, def, stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]);
                err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject byteopt_0(LispObject def)
{   return byteopt(def, SPID_NOARG, SPID_NOARG, SPID_NOARG, nil, nil, false);
}

LispObject byteopt_1(LispObject def, LispObject a)
{   return byteopt(def, a, SPID_NOARG, SPID_NOARG, nil, nil, false);
}

LispObject byteopt_2(LispObject def, LispObject a, LispObject b)
{   return byteopt(def, a, b, SPID_NOARG, nil, nil, false);
}

LispObject byteopt_3(LispObject def, LispObject a, LispObject b, LispObject c)
{   return byteopt(def, a, b, c, nil, nil, false);
}

LispObject byteopt_4up(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   return byteopt(def, a1, a2, a3, a4up, nil, false);
}

LispObject hardopt_0(LispObject def)
{   return byteopt(def, SPID_NOARG, SPID_NOARG, SPID_NOARG, nil, SPID_NOARG, false);
}

LispObject hardopt_1(LispObject def, LispObject a)
{   return byteopt(def, a, SPID_NOARG, SPID_NOARG, nil, SPID_NOARG, false);
}

LispObject hardopt_2(LispObject def, LispObject a, LispObject b)
{   return byteopt(def, a, b, SPID_NOARG, nil, SPID_NOARG, false);
}

LispObject hardopt_3(LispObject def, LispObject a, LispObject b, LispObject c)
{   return byteopt(def, a, b, c, nil, SPID_NOARG, false);
}

LispObject hardopt_4up(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   return byteopt(def, a1, a3, a3, a4up, SPID_NOARG, false);
}


LispObject byteoptrest_0(LispObject def)
{   return byteopt(def, SPID_NOARG, SPID_NOARG, SPID_NOARG, nil, nil, true);
}

LispObject byteoptrest_1(LispObject def, LispObject a)
{   return byteopt(def, a, SPID_NOARG, SPID_NOARG, nil, nil, true);
}

LispObject byteoptrest_2(LispObject def, LispObject a, LispObject b)
{   return byteopt(def, a, b, SPID_NOARG, nil, nil, true);
}

LispObject byteoptrest_3(LispObject def, LispObject a, LispObject b, LispObject c)
{   return byteopt(def, a, b, c, nil, nil, true);
}

LispObject byteoptrest_4up(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   return byteopt(def, a1, a2, a3, a4up, nil, true);
}

LispObject hardoptrest_0(LispObject def)
{   return byteopt(def, SPID_NOARG, SPID_NOARG, SPID_NOARG, nil, SPID_NOARG, true);
}

LispObject hardoptrest_1(LispObject def, LispObject a)
{   return byteopt(def, a, SPID_NOARG, SPID_NOARG, nil, SPID_NOARG, true);
}

LispObject hardoptrest_2(LispObject def, LispObject a, LispObject b)
{   return byteopt(def, a, b, SPID_NOARG, nil, SPID_NOARG, true);
}

LispObject hardoptrest_3(LispObject def, LispObject a, LispObject b, LispObject c)
{   return byteopt(def, a, b, c, nil, SPID_NOARG, true);
}

LispObject hardoptrest_4up(LispObject def, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   return byteopt(def, a1, a2, a3, a4up, SPID_NOARG, true);
}

LispObject Lis_spid(LispObject env, LispObject a)
{   // Used in compilation for optional args
    return onevalue(Lispify_predicate(is_spid(a)));
}

LispObject Lspid_to_nil(LispObject env, LispObject a)
{   // Used in compilation for optional args
    if (is_spid(a)) a = nil;
    return onevalue(a);
}

LispObject Lload_spid(LispObject)
{   // Used in compilation of UNWIND-PROTECT
    return onevalue(SPID_PROTECT);
}

LispObject Lmv_list(LispObject env, LispObject a)
//
// This does a (multiple-value-list A) on just one form.  It must be used
// carefully so that the value-count information does not get lost between
// the evaluation of A and calling this code. For this to work the variable
// exit_count must have been set to 1 before the call that evaluated the
// argument! Ensuring that all the time may be tough and may mean that
// non-compiled code has to set exit_count rather often "just to be sure".
// It also makes the case of (apply #'mv!-list ...) seem slightly scary,
// because normally arguments only generate one value each. Hmmm maybe this
// would be best implemented as a special form.
// Haha (multiple-value-list V) may be implemented as
// (multiple-value-call #'list V) and multiple-value-call is a special form.
// so what I have here is in fact unsupportable!
//
{   LispObject r;
    int i, x = exit_count;
    if (x > 0) push(a);
    for (i=2; i<=x; i++) push((&work_0)[i]);
    r = nil;
    for (i=0; i<x; i++)
    {   LispObject w;
        pop(w);
        r = cons(w, r);
    }
    return onevalue(r);
}

//
// In these tables there are some functions that would need adjusting
// for a Common Lisp compiler, since they take different numbers of
// args in Common and Standard Lisp.
// This means, to be specific:
//
//  Lgensym     Lread       Latan       Ltruncate   Lfloat
//  Lintern     Lmacroexpand            Lmacroexpand_1
//  Lrandom     Lunintern   Lappend     Leqn        Lgcd
//  Lgeq        Lgreaterp   Llcm        Lleq        Llessp
//  Lquotient
//
// In these cases (at least!) the Common Lisp version of the compiler will
// need to avoid generating the call that uses this table.
//
// Some functions are missing from the list here because they seemed
// critical enough to be awarded single-byte opcodes or because the
// compiler always expands them away - car through cddddr are the main
// cases, together with eq and equal.
//


#define NO_ARGS \
    BI(Lbatchp,                "batchp",     0),  \
    BI(Ldate,                  "date",       1),  \
    BI(Leject,                 "eject",      2),  \
    BI((no_args *)Lerror_0,    "error0",     3),  \
    BI(Lgctime,                "gctime",     4),  \
    BI(Lgensym,                "gensym",     5),  \
    BI(Llposn,                 "lposn",      6),  \
    BI(Lnext_random,           "next-random-number", 7), \
    BI(Lposn,                  "posn",       8),  \
    BI(Lread,                  "read",       9),  \
    BI(Lreadch,                "readch",     10), \
    BI(Lterpri,                "terpri",     11), \
    BI(Ltime,                  "time",       12), \
    BI(Ltyi,                   "tyi",        13), \
    BI(Lload_spid,             "load-spid",  14), \
    BI(NULL,                   NULL,         0)

#undef BI
#define BI(a, b, c) a
no_args *no_arg_functions[] =
{
    NO_ARGS
};

#undef BI
#define BI(a, b, c) b
const char *no_arg_names[] =
{
    NO_ARGS
};

bool no_arg_traceflags[sizeof(no_arg_functions)/sizeof(no_arg_functions[0])];

#define ONE_ARGS    \
   BI(Labsval,            "absval",                  0),   \
   BI(Ladd1,              "add1",                    1),   \
   BI(Latan,              "atan",                    2),   \
   BI(Lapply_1,           "apply0",                  3),   \
   BI(Latom,              "atom",                    4),   \
   BI(Lboundp,            "boundp",                  5),   \
   BI(Lchar_code,         "char-code",               6),   \
   BI(Lclose,             "close",                   7),   \
   BI(Lcodep,             "codep",                   8),   \
   BI(Lcompress,          "compress",                9),   \
   BI(Lconstantp,         "constantp",               10),  \
   BI(Ldigitp,            "digitp",                  11),  \
   BI(Lendp,              "endp",                    12),  \
   BI(Leval,              "eval",                    13),  \
   BI(Levenp,             "evenp",                   14),  \
   BI(Levlis,             "evlis",                   15),  \
   BI(Lexplode,           "explode",                 16),  \
   BI(Lexplode2lc,        "explode2lc",              17),  \
   BI(Lexplodec,          "explodec",                18),  \
   BI(Lfixp,              "fixp",                    19),  \
   BI(Lfloat,             "float",                   20),  \
   BI(Lfloatp,            "floatp",                  21),  \
   BI(Lsymbol_specialp,   "fluidp",                  22),  \
   BI(Lgc,                "reclaim",                 23),  \
   BI(Lgensym1,           "gensym1",                 24),  \
   BI(Lgetenv,            "getenv",                  25),  \
   BI(Lsymbol_globalp,    "globalp",                 26),  \
   BI(Liadd1,             "iadd1",                   27),  \
   BI(Lsymbolp,           "symbolp",                 28),  \
   BI(Liminus,            "iminus",                  29),  \
   BI(Liminusp,           "iminusp",                 30),  \
   BI(Lindirect,          "indirect",                31),  \
   BI(Lintegerp,          "integerp",                32),  \
   BI(Lintern,            "intern",                  33),  \
   BI(Lisub1,             "isub1",                   34),  \
   BI(Llength,            "length",                  35),  \
   BI(Llengthc,           "lengthc",                 36),  \
   BI(Llinelength,        "linelength",              37),  \
   BI(Lalpha_char_p,      "liter",                   38),  \
   BI(Lload_module,       "load-module",             39),  \
   BI(Llognot,            "lognot",                  40),  \
   BI(Lmacroexpand,       "macroexpand",             41),  \
   BI(Lmacroexpand_1,     "macroexpand-1",           42),  \
   BI(Lmacro_function,    "macro-function",          43),  \
   BI(Lget_bps,           "get_bps",                 44),  \
   BI(Lmake_global,       "make-global",             45),  \
   BI(Lsmkvect,           "smkvect",                 46),  \
   BI(Lmake_special,      "make-special",            47),  \
   BI(Lminus,             "minus",                   48),  \
   BI(Lminusp,            "minusp",                  49),  \
   BI(Lmkvect,            "mkvect",                  50),  \
   BI(Lmodular_minus,     "modular-minus",           51),  \
   BI(Lmodular_number,    "modular-number",          52),  \
   BI(Lmodular_reciprocal,"modular-reciprocal",      53),  \
   BI(Lnull,              "null",                    54),  \
   BI(Loddp,              "oddp",                    55),  \
   BI(Lonep,              "onep",                    56),  \
   BI(Lpagelength,        "pagelength",              57),  \
   BI(Lconsp,             "consp",                   58),  \
   BI(Lplist,             "plist",                   59),  \
   BI(Lplusp,             "plusp",                   60),  \
   BI(Lprin,              "prin",                    61),  \
   BI(Lprinc,             "princ",                   62),  \
   BI(Lprint,             "print",                   63),  \
   BI(Lprintc,            "printc",                  64),  \
   BI(Lrandom_1,          "random",                  65),  \
   BI(Lrational,          "rational",                66),  \
   BI(Lrdf1,              "rdf1",                    67),  \
   BI(Lrds,               "rds",                     68),  \
   BI(Lremd,              "remd",                    69),  \
   BI(Lreverse,           "reverse",                 70),  \
   BI(Lnreverse,          "nreverse",                71),  \
   BI(Lwhitespace_char_p, "whitespace-char-p",       72),  \
   BI(Lset_small_modulus, "set-small-modulus",       73),  \
   BI(Lxtab,              "xtab",                    74),  \
   BI(Lspecial_char,      "special-char",            75),  \
   BI(Lspecial_form_p,    "special-form-p",          76),  \
   BI(Lspool,             "spool",                   77),  \
   BI((one_arg *)Lstop1,  "stop",                    78),  \
   BI(Lstringp,           "stringp",                 79),  \
   BI(Lsub1,              "sub1",                    80),  \
   BI(Lsymbol_env,        "symbol-env",              81),  \
   BI(Lsymbol_function,   "symbol-function",         82),  \
   BI(Lsymbol_name,       "symbol-name",             83),  \
   BI(Lsymbol_value,      "symbol-value",            84),  \
   BI(Lsystem,            "system",                  85),  \
   BI(Ltruncate,          "truncate",                86),  \
   BI(Lttab,              "ttab",                    87),  \
   BI(Ltyo,               "tyo",                     88),  \
   BI(Lunintern,          "unintern",                89),  \
   BI(Lunmake_global,     "unmake-global",           90),  \
   BI(Lunmake_special,    "unmake-special",          91),  \
   BI(Lupbv,              "upbv",                    92),  \
   BI(Lsimple_vectorp,    "simple-vectorp",          93),  \
   BI(Lverbos,            "verbos",                  94),  \
   BI(Lwrs,               "wrs",                     95),  \
   BI(Lzerop,             "zerop",                   96),  \
   BI(Lcar,               "car",                     97),  \
   BI(Lcdr,               "cdr",                     98),  \
   BI(Lcaar,              "caar",                    99),  \
   BI(Lcadr,              "cadr",                    100), \
   BI(Lcdar,              "cdar",                    101), \
   BI(Lcddr,              "cddr",                    102), \
   BI(Lcar,               "car",                     103), \
   BI(Lcdr,               "cdr",                     104), \
   BI(Lcaar,              "caar",                    105), \
   BI(Lcadr,              "cadr",                    106), \
   BI(Lcdar,              "cdar",                    107), \
   BI(Lcddr,              "cddr",                    108), \
   BI(Lncons,             "ncons",                   109), \
   BI(Lnumberp,           "numberp",                 110), \
   BI(Lis_spid,           "is-spid",                 111), \
   BI(Lspid_to_nil,       "spid-to-nil",             112), \
   BI(Lmv_list,           "mv-list",                 113), \
   BI(Lload_source,       "load-source",             114), \
   BI(quote_fn,           "quote",                   115), \
   BI(progn_fn,           "progn",                   116), \
   BI(progn_fn,           "progn",                   117), \
   BI(declare_fn,         "declare",                 118), \
   BI(function_fn,        "function",                119), \
   BI(NULL,               NULL,                      0)

#undef BI
#define BI(a, b, c) a
one_arg *one_arg_functions[] =
{
    ONE_ARGS
};

#undef BI
#define BI(a, b, c) b
const char *one_arg_names[] =
{
    ONE_ARGS
};

bool one_arg_traceflags[sizeof(one_arg_functions)/sizeof(one_arg_functions[0])];

#define TWO_ARGS \
    BI(Lappend_2,                  "append",                 0),   \
    BI(Lash,                       "ash",                    1),   \
    BI(Lassoc,                     "assoc",                  2),   \
    BI(Latsoc,                     "atsoc",                  3),   \
    BI(Ldeleq,                     "deleq",                  4),   \
    BI(Ldelete,                    "delete",                 5),   \
    BI(Ldivide_2,                  "divide",                 6),   \
    BI(Leqcar,                     "eqcar",                  7),   \
    BI(Leql,                       "eql",                    8),   \
    BI(Leqn_2,                     "eqn",                    9),   \
    BI(Lexpt,                      "expt",                   10),  \
    BI(Lflag,                      "flag",                   11),  \
    BI(Lflagpcar,                  "flagpcar",               12),  \
    BI(Lgcd_2,                     "gcd",                    13),  \
    BI(Lgeq_2,                     "geq",                    14),  \
    BI(Lgetv,                      "getv",                   15),  \
    BI(Lgreaterp_2,                "greaterp",               16),  \
    BI(Lidifference_2,             "idifference",            17),  \
    BI(Ligreaterp_2,               "igreaterp",              18),  \
    BI(Lilessp_2,                  "ilessp",                 19),  \
    BI(Limax_2,                    "imax",                   20),  \
    BI(Limin_2,                    "imin",                   21),  \
    BI(Liplus_2,                   "iplus2",                 22),  \
    BI(Liquotient_2,               "iquotient",              23),  \
    BI(Liremainder_2,              "iremainder",             24),  \
    BI(Lirightshift,               "irightshift",            25),  \
    BI(Litimes_2,                  "itimes2",                26),  \
    BI(Llcm_2,                     "lcm",                    27),  \
    BI(Lleq_2,                     "leq",                    28),  \
    BI(Llessp_2,                   "lessp",                  29),  \
    BI(Lmake_random_state,         "make-random-state",      30),  \
    BI(Lmax_2,                     "max2",                   31),  \
    BI(Lmember,                    "member",                 32),  \
    BI(Lmemq,                      "memq",                   33),  \
    BI(Lmin_2,                     "min2",                   34),  \
    BI(Lmod_2,                     "mod",                    35),  \
    BI(Lmodular_difference,        "modular-difference",     36),  \
    BI(Lmodular_expt,              "modular-expt",           37),  \
    BI(Lmodular_plus,              "modular-plus",           38),  \
    BI(Lmodular_quotient,          "modular-quotient",       39),  \
    BI(Lmodular_times,             "modular-times",          40),  \
    BI(Lnconc,                     "nconc",                  41),  \
    BI(Lneq_2,                     "neq",                    42),  \
    BI(Lorderp,                    "orderp",                 43),  \
    BI(Lquotient_2,                "quotient",               44),  \
    BI(Lrem_2,                     "rem",                    45),  \
    BI(Lremflag,                   "remflag",                46),  \
    BI(Lremprop,                   "remprop",                47),  \
    BI(Lrplaca,                    "rplaca",                 48),  \
    BI(Lrplacd,                    "rplacd",                 49),  \
    BI(Lsgetv,                     "sgetv",                  50),  \
    BI(Lset,                       "set",                    51),  \
    BI(Lsmemq,                     "smemq",                  52),  \
    BI(Lsubla,                     "subla",                  53),  \
    BI(Lsublis,                    "sublis",                 54),  \
    BI(Lsymbol_set_definition,     "symbol-set-definition",  55),  \
    BI(Lsymbol_set_env,            "symbol-set-env",         56),  \
    BI(Ltimes_2,                   "times2",                 57),  \
    BI(Lxcons,                     "xcons",                  58),  \
    BI(Lequal,                     "equal",                  59),  \
    BI(Leq,                        "eq",                     60),  \
    BI(Lcons,                      "cons",                   61),  \
    BI(Llist_2,                    "list2",                  62),  \
    BI(Lget,                       "get",                    63),  \
    BI(Lgetv,                      "getv",                   64),  \
    BI(Lflagp,                     "flagp",                  65),  \
    BI(Lapply_2,                   "apply1",                 66),  \
    BI(Ldifference_2,              "difference2",            67),  \
    BI(Lplus_2,                    "plus2",                  68),  \
    BI(Ltimes_2,                   "times2",                 69),  \
    BI(Lequalcar,                  "equalcar",               70),  \
    BI(Leq,                        "eq",                     71),  \
    BI(Lnreverse2,                 "nreverse2",              72),  \
    BI(NULL,                       NULL,                     0)

#undef BI
#define BI(a, b, c) a
two_args *two_arg_functions[] =
{
    TWO_ARGS
};

#undef BI
#define BI(a, b, c) b
const char *two_arg_names[] =
{
    TWO_ARGS
};

bool two_arg_traceflags[sizeof(two_arg_functions)/sizeof(two_arg_functions[0])];

#define THREE_ARGS \
    BI(Lbpsputv,     "bpsputv",                0),  \
    BI(Lerrorset_3,  "errorset",               1),  \
    BI(Llist_2star,  "list2*",                 2),  \
    BI(Llist_3,      "list3",                  3),  \
    BI(Lputprop,     "putprop",                4),  \
    BI(Lputv,        "putv",                   5),  \
    BI(Lsputv,       "sputv",                  6),  \
    BI(Lsubst,       "subst",                  7),  \
    BI(Lapply_3,     "apply2",                 8),  \
    BI(Lacons,       "acons",                  9),  \
    BI(NULL,         NULL,                     0)

#undef BI
#define BI(a, b, c) a
three_args *three_arg_functions[] =
{
    THREE_ARGS
};

#undef BI
#define BI(a, b, c) b
const char *three_arg_names[] =
{
    THREE_ARGS
};

bool three_arg_traceflags[sizeof(three_arg_functions)/sizeof(three_arg_functions[0])];

#define FOURUP_ARGS \
    BI(NULL,         NULL,                     0)

#undef BI
#define BI(a, b, c) a
fourup_args *fourup_arg_functions[] =
{
    FOURUP_ARGS
};

#undef BI
#define BI(a, b, c) b
const char *fourup_arg_names[] =
{
    FOURUP_ARGS
};

bool fourup_arg_traceflags[sizeof(fourup_arg_functions)/sizeof(fourup_arg_functions[0])];

// end of eval4.cpp
