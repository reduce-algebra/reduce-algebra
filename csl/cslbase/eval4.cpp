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


#define name_from(def) elt(qcdr(def), 0)

// Each of these entrypoints to the bytecode interpreter preserves litvec
// and codevec. Just about the only place these variable are set is within
// the bytecode interpreter.

LispObject bytecoded0(LispObject def, int nargs, ...)
{   if (nargs != 0) error(2, err_wrong_no_args, name_from(def),
                                     fixnum_of_int((int32_t)nargs));
    SAVE_CODEVEC;
    LispObject r;
// I can use START_TRY_BLOCK without "try" if there are not going to be any
// "catch" clauses at this level!
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack);
    }
    return r;
}

LispObject bytecoded1(LispObject def, LispObject a)
{   SAVE_CODEVEC;
    push2(def, a);
    LispObject r;
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-1);
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

LispObject bytecoded2(LispObject def, LispObject a, LispObject b)
{   LispObject r;
    SAVE_CODEVEC;
    push3(def, a, b);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-2);
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

LispObject bytecoded3(LispObject def, int nargs, ...)
{   va_list aa;
    LispObject r, a, b, c;
    if (nargs != 3) error(2, err_wrong_no_args, name_from(def),
                                     fixnum_of_int((int32_t)nargs));
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    SAVE_CODEVEC;
    push4(def, a, b, c);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(qcar(def)), qcdr(def), stack-3);
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

LispObject bytecodedn(LispObject def, int nargs, ...)
{
//
// The messing about here is to get the (unknown number of) args
// into a nice neat vector so that they can be indexed into. If I knew
// that the args were in consecutive locations on the stack I could
// probably save a copying operation.
//
    LispObject r;
    int i;
    va_list a;
    SAVE_CODEVEC;
    push(def);
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs);
    }
    r = qcar(def);
    if (nargs != ((unsigned char *)data_of_bps(r))[0])
    {   popv(nargs+2);
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+1, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
//
// Note that in this display if a function had over 50 args then the
// final bunch of them will be bundled up in to a list (as if for &rest).
//
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject unpack_mv(LispObject env, LispObject r)
{   LispObject *p = &mv_1;
    exit_count = 0;
    *p = nil;
    while (r != nil)
    {   *p++ = qcar(r);
        r = qcdr(r);
        exit_count++;
    }
    return mv_1;
}

//
// The code that follows is just used to support compiled code that
// has &optional or &rest arguments.
//

LispObject byteopt1(LispObject def, LispObject a)
{   return byteoptn(def, 1, a);
}

LispObject byteopt2(LispObject def, LispObject a, LispObject b)
{   return byteoptn(def, 2, a, b);
}

static LispObject vbyteoptn(LispObject def, int nargs,
                            va_list a, LispObject dflt)
{   LispObject r;
    int i, wantargs, wantopts;
    SAVE_CODEVEC;
//
// Maybe I should raise an exception (continuable error) if too many args
// are provided - for now I just silently ignore the excess.
//
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs || nargs > wantargs+wantopts)
    {   popv(nargs); pop2(codevec, litvec)
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   // Provide value for all optional args
        nargs++;
    }
    r = qcar(def);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+2, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject byteoptn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyteoptn(def, nargs, a, nil);
}

LispObject hardopt1(LispObject def, LispObject a)
{   return hardoptn(def, 1, a);
}

LispObject hardopt2(LispObject def, LispObject a, LispObject b)
{   return hardoptn(def, 2, a, b);
}

LispObject hardoptn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyteoptn(def, nargs, a, SPID_NOARG);
}

LispObject byteoptrest1(LispObject def, LispObject a)
{   return byteoptrestn(def, 1, a);
}

LispObject byteoptrest2(LispObject def, LispObject a, LispObject b)
{   return byteoptrestn(def, 2, a, b);
}

static LispObject vbyterestn(LispObject def, int nargs,
                             va_list a, LispObject dflt)
{   LispObject r;
    int i, wantargs, wantopts;
    SAVE_CODEVEC;
    if (nargs != 0) push_args(a, nargs);
    else va_end(a);
    r = qcar(def);
    wantargs = ((unsigned char *)data_of_bps(r))[0];
    wantopts = ((unsigned char *)data_of_bps(r))[1];
    if (nargs < wantargs)
    {   popv(nargs+2);
        error(2, err_wrong_no_args, name_from(def),
                     fixnum_of_int((int32_t)nargs));
    }
    while (nargs < wantargs+wantopts)
    {   push(dflt);   // Provide value for all optional args
        nargs++;
    }
    {   LispObject rest = nil;
        while (nargs > wantargs+wantopts)
        {   LispObject w = stack[0];
            stack[0] = def;
            rest = cons(w, rest);
            pop(def);
            nargs--;
        }
        push(rest);
        nargs++;
    }
    r = qcar(def);
    try
    {   START_TRY_BLOCK;
        r = bytestream_interpret(data_of_bps(r)+2, qcdr(def), stack-nargs);
    }
    catch (LispError e)
    {   int _reason = exit_reason;
        if (SHOW_ARGS)
        {   for (i=1; i<=nargs; i++)
            {   err_printf("Arg%d: ", i);
                loop_print_error(stack[i-nargs]); err_printf("\n");
            }
        }
        exit_reason = _reason;
        throw;
    }
    return r;
}

LispObject byteoptrestn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyterestn(def, nargs, a, nil);
}

LispObject hardoptrest1(LispObject def, LispObject a)
{   return hardoptrestn(def, 1, a);
}

LispObject hardoptrest2(LispObject def, LispObject a, LispObject b)
{   return hardoptrestn(def, 2, a, b);
}

LispObject hardoptrestn(LispObject def, int nargs, ...)
{   va_list a;
    va_start(a, nargs);
    return vbyterestn(def, nargs, a, SPID_NOARG);
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

LispObject Lload_spid(LispObject, int, ...)
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
    BI((n_args *)Lerror0,      "error0",     3),  \
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
n_args *no_arg_functions[] =
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
   BI(Lapply0,            "apply0",                  3),   \
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
   BI(Lrandom,            "random",                  65),  \
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
   BI((one_args *)Lstop,  "stop",                    78),  \
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
one_args *one_arg_functions[] =
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
    BI(Lappend,                    "append",                 0),   \
    BI(Lash,                       "ash",                    1),   \
    BI(Lassoc,                     "assoc",                  2),   \
    BI(Latsoc,                     "atsoc",                  3),   \
    BI(Ldeleq,                     "deleq",                  4),   \
    BI(Ldelete,                    "delete",                 5),   \
    BI(Ldivide,                    "divide",                 6),   \
    BI(Leqcar,                     "eqcar",                  7),   \
    BI(Leql,                       "eql",                    8),   \
    BI(Leqn,                       "eqn",                    9),   \
    BI(Lexpt,                      "expt",                   10),  \
    BI(Lflag,                      "flag",                   11),  \
    BI(Lflagpcar,                  "flagpcar",               12),  \
    BI(Lgcd,                       "gcd",                    13),  \
    BI(Lgeq,                       "geq",                    14),  \
    BI(Lgetv,                      "getv",                   15),  \
    BI(Lgreaterp,                  "greaterp",               16),  \
    BI(Lidifference,               "idifference",            17),  \
    BI(Ligreaterp,                 "igreaterp",              18),  \
    BI(Lilessp,                    "ilessp",                 19),  \
    BI(Limax,                      "imax",                   20),  \
    BI(Limin,                      "imin",                   21),  \
    BI(Liplus2,                    "iplus2",                 22),  \
    BI(Liquotient,                 "iquotient",              23),  \
    BI(Liremainder,                "iremainder",             24),  \
    BI(Lirightshift,               "irightshift",            25),  \
    BI(Litimes2,                   "itimes2",                26),  \
    BI(Llcm,                       "lcm",                    27),  \
    BI(Lleq,                       "leq",                    28),  \
    BI(Llessp,                     "lessp",                  29),  \
    BI(Lmake_random_state,         "make-random-state",      30),  \
    BI(Lmax2,                      "max2",                   31),  \
    BI(Lmember,                    "member",                 32),  \
    BI(Lmemq,                      "memq",                   33),  \
    BI(Lmin2,                      "min2",                   34),  \
    BI(Lmod,                       "mod",                    35),  \
    BI(Lmodular_difference,        "modular-difference",     36),  \
    BI(Lmodular_expt,              "modular-expt",           37),  \
    BI(Lmodular_plus,              "modular-plus",           38),  \
    BI(Lmodular_quotient,          "modular-quotient",       39),  \
    BI(Lmodular_times,             "modular-times",          40),  \
    BI(Lnconc,                     "nconc",                  41),  \
    BI(Lneq,                       "neq",                    42),  \
    BI(Lorderp,                    "orderp",                 43),  \
    BI(Lquotient,                  "quotient",               44),  \
    BI(Lrem,                       "rem",                    45),  \
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
    BI(Ltimes2,                    "times2",                 57),  \
    BI(Lxcons,                     "xcons",                  58),  \
    BI(Lequal,                     "equal",                  59),  \
    BI(Leq,                        "eq",                     60),  \
    BI(Lcons,                      "cons",                   61),  \
    BI(Llist2,                     "list2",                  62),  \
    BI(Lget,                       "get",                    63),  \
    BI(Lgetv,                      "getv",                   64),  \
    BI(Lflagp,                     "flagp",                  65),  \
    BI(Lapply1,                    "apply1",                 66),  \
    BI(Ldifference2,               "difference2",            67),  \
    BI(Lplus2,                     "plus2",                  68),  \
    BI(Ltimes2,                    "times2",                 69),  \
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
    BI(Lerrorsetn,   "errorset",               1),  \
    BI(Llist2star,   "list2*",                 2),  \
    BI(Llist3,       "list3",                  3),  \
    BI(Lputprop,     "putprop",                4),  \
    BI(Lputv,        "putv",                   5),  \
    BI(Lsputv,       "sputv",                  6),  \
    BI(Lsubst,       "subst",                  7),  \
    BI(Lapply2,      "apply2",                 8),  \
    BI(Lacons,       "acons",                  9),  \
    BI(NULL,         NULL,                     0)

#undef BI
#define BI(a, b, c) a
n_args *three_arg_functions[] =
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

#define FOUR_ARGS \
    BI(NULL,         NULL,                     0)

#undef BI
#define BI(a, b, c) a
four_args *four_arg_functions[] =
{
    FOUR_ARGS
};

#undef BI
#define BI(a, b, c) b
const char *four_arg_names[] =
{
    FOUR_ARGS
};

bool four_arg_traceflags[sizeof(four_arg_functions)/sizeof(four_arg_functions[0])];

// end of eval4.cpp
