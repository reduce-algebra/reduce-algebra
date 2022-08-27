// cslerror.h                              Copyright (C) 1989-2022 Codemist

// Error codes and functions.
//


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

#ifndef header_cslerror_h
#define header_cslerror_h 1

extern LispObject interrupted(bool noisy);

extern LispObject error(int nargs, int code, ...);
extern LispObject cerror(int nargs, int code1, int code2, ...);

extern LispObject got_0_wanted_1(LispObject env);
extern LispObject got_0_wanted_2(LispObject env);
extern LispObject got_0_wanted_3(LispObject env);
extern LispObject got_0_wanted_4up(LispObject env);
// "other" is for use if the function could take a variable number of
// arguments, but the number actually provided is not acceptable. A case
// where this arises is with functions that have a signatire of the
// style (de foo (a !&rest r) ...) where not being passed any arguments at
// all would be an error.
extern LispObject got_0_wanted_other(LispObject env);

extern LispObject got_1_wanted_0(LispObject env,
                                        LispObject a1);
extern LispObject got_1_wanted_2(LispObject env,
                                        LispObject a1);
extern LispObject got_1_wanted_3(LispObject env,
                                        LispObject a1);
extern LispObject got_1_wanted_4up(LispObject env,
        LispObject a1);
extern LispObject got_1_wanted_other(LispObject env,
        LispObject a1);

extern LispObject got_2_wanted_0(LispObject env, LispObject a1,
                                        LispObject a2);
extern LispObject got_2_wanted_1(LispObject env, LispObject a1,
                                        LispObject a2);
extern LispObject got_2_wanted_3(LispObject env, LispObject a1,
                                        LispObject a2);
extern LispObject got_2_wanted_4up(LispObject env,
        LispObject a1,
        LispObject a2);
extern LispObject got_2_wanted_other(LispObject env,
        LispObject a1,
        LispObject a2);

extern LispObject got_3_wanted_0(LispObject env, LispObject a1,
                                        LispObject a2, LispObject a3);
extern LispObject got_3_wanted_1(LispObject env, LispObject a1,
                                        LispObject a2, LispObject a3);
extern LispObject got_3_wanted_2(LispObject env, LispObject a1,
                                        LispObject a2, LispObject a3);
extern LispObject got_3_wanted_4up(LispObject env,
        LispObject a1,
        LispObject a2, LispObject a3);
extern LispObject got_3_wanted_other(LispObject env,
        LispObject a1,
        LispObject a2, LispObject a3);

extern LispObject got_4up_wanted_0(LispObject env,
        LispObject a1,
        LispObject a2, LispObject a3,
        LispObject a4up);
extern LispObject got_4up_wanted_1(LispObject env,
        LispObject a1,
        LispObject a2, LispObject a3,
        LispObject a4up);
extern LispObject got_4up_wanted_2(LispObject env,
        LispObject a1,
        LispObject a2, LispObject a3,
        LispObject a4up);
extern LispObject got_4up_wanted_3(LispObject env,
        LispObject a1,
        LispObject a2, LispObject a3,
        LispObject a4up);
extern LispObject got_4up_wanted_other(LispObject env,
        LispObject a1,
        LispObject a2, LispObject a3,
        LispObject a4up);


// The following are put in the function cells of symbols that are special
// forms so that if by some mischance somebody calls one of them one gets
// a tolerable diagnostic.

extern LispObject bad_specialfn_0(LispObject env);
extern LispObject bad_specialfn_2(LispObject env, LispObject,
        LispObject);
extern LispObject bad_specialfn_3(LispObject env, LispObject,
        LispObject, LispObject);
extern LispObject bad_specialfn_4up(LispObject env, LispObject,
        LispObject, LispObject, LispObject);


// The following are just abbreviations to make the setup tables in the
// code less bulky.

#define G0W1           got_0_wanted_1
#define G0W2           got_0_wanted_2
#define G0W3           got_0_wanted_3
#define G0W4up         got_0_wanted_4up
#define G0Wother       got_0_wanted_other

#define G1W0           got_1_wanted_0
#define G1W2           got_1_wanted_2
#define G1W3           got_1_wanted_3
#define G1W4up         got_1_wanted_4up
#define G1Wother       got_1_wanted_other

#define G2W0           got_2_wanted_0
#define G2W1           got_2_wanted_1
#define G2W3           got_2_wanted_3
#define G2W4up         got_2_wanted_4up
#define G2Wother       got_2_wanted_other

#define G3W0           got_3_wanted_0
#define G3W1           got_3_wanted_1
#define G3W2           got_3_wanted_2
#define G3W4up         got_3_wanted_4up
#define G3Wother       got_3_wanted_other

#define G4W0           got_4up_wanted_0
#define G4W1           got_4up_wanted_1
#define G4W2           got_4up_wanted_2
#define G4W3           got_4up_wanted_3
#define G4Wother       got_4up_wanted_other

extern LispObject display_backtrace();

extern LispObject aerror(const char *s);         // Called from C not Lisp
extern LispObject aerror0(const char *s);
extern LispObject aerror1(const char *s, LispObject a);
extern LispObject aerror2(const char *s, LispObject a, LispObject b);
extern LispObject aerror2(const char *s, const char *a, LispObject b);
extern LispObject aerror3(const char *s,
                          LispObject a, LispObject b, LispObject c);

[[noreturn]] extern void fatal_error(int code, ...);

// For the sake of Common Lisp style treatment of (car nil) and (cdr nil)
// I have these. In the CL case they can return nil if the arg is nil or
// raise an exception otherwise.
extern LispObject carerror(LispObject a);
extern LispObject cdrerror(LispObject a);

extern LispObject car_fails(LispObject a);
extern LispObject cdr_fails(LispObject a);
extern LispObject rplaca_fails(LispObject a);
extern LispObject rplacd_fails(LispObject a);

//
// Since miscflags is treated as a set of bits the issue of whether it
// is signed or not will never arise!
//
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04

#define GC_MSG_BITS   0x07
#define verbos_flag (miscflags & GC_MSG_BITS)

//
// In a backtrace I can get
//    +++ Error EXPLANATION               HEADLINE_FLAG
//    Calling: FUNCTION                   FNAME_FLAG
//    Arg1: DATA                          ARGS_FLAG
//
//

#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20

#define BACKTRACE_MSG_BITS 0x38

// I need a bunch of numeric codes (eg err_bad_car) and I then need a
// table of strings that has to stey in step. The code here achieves
// this using a fairly standarf hack that uses macros. Note that by
// defining the codes using enum the definitions are all processed at
// compile time. 

#define ERROR_MESSAGES                                                      \
X(err_bad_car,                "attempt to take car of an atom")             \
X(err_bad_cdr,                "attempt to take cdr of an atom")             \
X(err_no_store,               "insufficient freestore to run this package") \
X(err_undefined_function_0,   "undefined function (0 args)")                \
X(err_undefined_function_1,   "undefined function (1 arg)")                 \
X(err_undefined_function_2,   "undefined function (2 args)")                \
X(err_undefined_function_3,   "undefined function (3 args)")                \
X(err_undefined_function_4up, "undefined function (4 or more args)")        \
X(err_wrong_no_args,          "wrong number of arguments")                  \
X(err_unbound_lexical,        "unbound lexical variable")                   \
X(err_bad_rplac,              "bad rplaca/rplacd")                          \
X(err_bad_arith,              "bad argument for an arithmetic function")    \
X(err_redef_special,          "attempt to redefine a special form")         \
X(err_bad_arg,                "not a variable")                             \
X(err_bad_declare,            "bad use of declare")                         \
X(err_bad_fn,                 "attempt to apply non-function")              \
X(err_unset_var,              "unset variable")                             \
X(err_too_many_args0,         "too many arguments for 0-arg function")      \
X(err_too_many_args1,         "too many arguments for 1-arg function")      \
X(err_too_many_args2,         "too many arguments for 2-arg function")      \
X(err_too_many_args3,         "too many arguments for 3-arg function")      \
X(err_bad_apply,              "object not valid as a function (apply,")     \
X(err_macroex_hook,           "macroexpand-hook failure")                   \
X(err_block_tag,              "block tag not found")                        \
X(err_go_tag,                 "go tag not found")                           \
X(err_excess_args,            "too many arguments provided")                \
X(err_insufficient_args,      "not enough arguments provided")              \
X(err_bad_bvl,                "bad item in bound variable list")            \
X(err_bad_keyargs,            "bad keyword arguments")                      \
X(err_write_err,              "write-error on file")                        \
X(err_bad_endp,               "endp used on badly terminated list")         \
X(err_no_fasldir,             "environment parameter 'fasldir' not set")    \
X(err_no_fasl,                "loadable module not found for loading")      \
X(err_open_failed,            "file could not be opened")                   \
X(err_pipe_failed,            "unable to establish pipe")                   \
X(err_stack_overflow,         "stack overflow")                             \
X(err_top_bit,                "top bit of address has unexpected value")    \
X(err_mem_spans_zero,         "memory block spans the zero address")        \
X(err_read_failure,           "failure reading from an image file")         \
X(err_no_tempdir,             "unable to find a directory for temporary files")

#define X(name, text) name,
enum
{
    ERROR_MESSAGES
};
#undef X

#define X(name, text) text,
INLINE_VAR const char *error_message_table[] =
{
    ERROR_MESSAGES
    "dummy final error message"
};
#undef X

#endif //  header_cslerror_h

// end of cslerror.h
