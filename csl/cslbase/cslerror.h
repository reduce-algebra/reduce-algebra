// cslerror.h                              Copyright (C) 1989-2017 Codemist

// Error codes and functions.
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

#ifndef header_cslerror_h
#define header_cslerror_h 1

extern LispObject interrupted(LispObject p);

NORETURN extern void error(int nargs, int code, ...);
NORETURN extern void cerror(int nargs, int code1, int code2, ...);

NORETURN extern void got_0_wanted_1(LispObject env);
NORETURN extern void got_0_wanted_2(LispObject env);
NORETURN extern void got_0_wanted_3(LispObject env);
NORETURN extern void got_0_wanted_4up(LispObject env);
// "other" is for use if the function could take a variable number of
// arguments, but the number actually provided is not acceptable. A case
// where this arises is with functions that have a signatire of the
// style (de foo (a !&rest r) ...) where not being passed any arguments at
// all would be an error.
NORETURN extern void got_0_wanted_other(LispObject env);

NORETURN extern void got_1_wanted_0(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_2(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_3(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_4up(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_other(LispObject env, LispObject a1);

NORETURN extern void got_2_wanted_0(LispObject env, LispObject a1,
                                        LispObject a2);
NORETURN extern void got_2_wanted_1(LispObject env, LispObject a1,
                                        LispObject a2);
NORETURN extern void got_2_wanted_3(LispObject env, LispObject a1,
                                        LispObject a2);
NORETURN extern void got_2_wanted_4up(LispObject env, LispObject a1,
                                          LispObject a2);
NORETURN extern void got_2_wanted_other(LispObject env, LispObject a1,
                                            LispObject a2);

NORETURN extern void got_3_wanted_0(LispObject env, LispObject a1,
                                        LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_1(LispObject env, LispObject a1,
                                        LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_2(LispObject env, LispObject a1,
                                        LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_4up(LispObject env, LispObject a1,
                                          LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_other(LispObject env, LispObject a1,
                                            LispObject a2, LispObject a3);

NORETURN extern void got_4up_wanted_0(LispObject env, LispObject a1,
                                          LispObject a2, LispObject a3,
                                          LispObject a4up);
NORETURN extern void got_4up_wanted_1(LispObject env, LispObject a1,
                                          LispObject a2, LispObject a3,
                                          LispObject a4up);
NORETURN extern void got_4up_wanted_2(LispObject env, LispObject a1,
                                          LispObject a2, LispObject a3,
                                          LispObject a4up);
NORETURN extern void got_4up_wanted_3(LispObject env, LispObject a1,
                                          LispObject a2, LispObject a3,
                                          LispObject a4up);
NORETURN extern void got_4up_wanted_other(LispObject env, LispObject a1,
                                              LispObject a2, LispObject a3,
                                              LispObject a4up);


// The following are put in the function cells of symbols that are special
// forms so that if by some mischance somebody calls one of them one gets
// a tolerable diagnostic.

NORETURN extern void bad_specialfn_0(LispObject env);
NORETURN extern void bad_specialfn_2(LispObject env, LispObject, LispObject);
NORETURN extern void bad_specialfn_3(LispObject env, LispObject, LispObject, LispObject);
NORETURN extern void bad_specialfn_4up(LispObject env, LispObject, LispObject, LispObject, LispObject);


// To go in a setup table the types need to look as if a value will be
// returned. So the real definitions of these error calls that are given
// a return type "NORETURN void" would be rejected. So I provide some
// more concise names that have been cast to function types that return
// a LispObject

#define G0W1           ((no_args *)got_0_wanted_1)
#define G0W2           ((no_args *)got_0_wanted_2)
#define G0W3           ((no_args *)got_0_wanted_3)
#define G0W4up         ((no_args *)got_0_wanted_4up)
#define G0Wother       ((no_args *)got_0_wanted_other)

#define G1W0           ((one_arg *)got_1_wanted_0)
#define G1W2           ((one_arg *)got_1_wanted_2)
#define G1W3           ((one_arg *)got_1_wanted_3)
#define G1W4up         ((one_arg *)got_1_wanted_4up)
#define G1Wother       ((one_arg *)got_1_wanted_other)

#define G2W0           ((two_args *)got_2_wanted_0)
#define G2W1           ((two_args *)got_2_wanted_1)
#define G2W3           ((two_args *)got_2_wanted_3)
#define G2W4up         ((two_args *)got_2_wanted_4up)
#define G2Wother       ((two_args *)got_2_wanted_other)

#define G3W0           ((three_args *)got_3_wanted_0)
#define G3W1           ((three_args *)got_3_wanted_1)
#define G3W2           ((three_args *)got_3_wanted_2)
#define G3W4up         ((three_args *)got_3_wanted_4up)
#define G3Wother       ((three_args *)got_3_wanted_other)

#define G4W0           ((fourup_args *)got_4up_wanted_0)
#define G4W1           ((fourup_args *)got_4up_wanted_1)
#define G4W2           ((fourup_args *)got_4up_wanted_2)
#define G4W3           ((fourup_args *)got_4up_wanted_3)
#define G4Wother       ((fourup_args *)got_4up_wanted_other)

#define BAD_SPECIAL_0    ((no_args *)bad_specialfn_0)
#define BAD_SPECIAL_2    ((two_args *)bad_specialfn_2)
#define BAD_SPECIAL_3    ((three_args *)bad_specialfn_3)
#define BAD_SPECIAL_4up  ((fourup_args *)bad_specialfn_4up)


NORETURN extern void aerror(const char *s);         // Called from C not Lisp
NORETURN extern void aerror0(const char *s);
NORETURN extern void aerror1(const char *s, LispObject a);
NORETURN extern void aerror2(const char *s, LispObject a, LispObject b);
NORETURN extern void aerror3(const char *s, LispObject a, LispObject b, LispObject c);
NORETURN extern void fatal_error(int code, ...);

// For the sake of Common Lisp style treatment of (car nil) and (cdr nil)
// I have these.
extern LispObject carerror(LispObject a);
extern LispObject cdrerror(LispObject a);

NORETURN extern void car_fails(LispObject a);
NORETURN extern void cdr_fails(LispObject a);
NORETURN extern void rplaca_fails(LispObject a);
NORETURN extern void rplacd_fails(LispObject a);

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

//
// It is essential that the #define values set up here are kept in
// step with the textual error messages in the array that follows...
//

#define err_bad_car               0      // + the atom
#define err_bad_cdr               1      // + the atom
#define err_no_store              2      // no extras
#define err_undefined_function_0  3      // + fn name
#define err_undefined_function_1  4      // + fn name
#define err_undefined_function_2  5      // + fn name
#define err_undefined_function_3  6      // + fn name
#define err_undefined_function_4up  7    // + fn name
#define err_wrong_no_args         8      // fn name, actual arg count
#define err_unbound_lexical       9      // + name
#define err_bad_rplac            10      // + atom
#define err_bad_arith            11      // + bad value
#define err_redef_special        12      // + name
#define err_bad_arg              13      // + offending value
#define err_bad_declare          14      // + offending value
#define err_bad_fn               15      // + offending value
#define err_unset_var            16      // + name
#define err_too_many_args0       17      // no extras
#define err_too_many_args1       18      // no extras
#define err_too_many_args2       19      // no extras
#define err_too_many_args3       20      // no extras
#define err_bad_apply            21      // + bad thing
#define err_macroex_hook         22      // what it is
#define err_block_tag            23      // bad tag
#define err_go_tag               24      // bad tag
#define err_excess_args          25
#define err_insufficient_args    26
#define err_bad_bvl              27      // + offending value
#define err_bad_keyargs          28
#define err_write_err            29
#define err_bad_endp             30      // + the non-null atom
#define err_no_fasldir           31
#define err_no_fasl              32      // plus module name
#define err_open_failed          33      // plus file name
#define err_pipe_failed          34      // plus command for execution
#define err_stack_overflow       35
#define err_top_bit              36
#define err_mem_spans_zero       37
#define err_no_longer_used       38      // available for re-use
#define err_no_tempdir           39

#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{   "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (0 args)",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function (3 args)",
    "undefined function (4 or more args)",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments for 0-arg function",
    "too many arguments for 1-arg function",
    "too many arguments for 2-arg function",
    "too many arguments for 3-arg function",
    "object not valid as a function (apply,",
    "macroexpand-hook failure",
    "block tag not found",
    "go tag not found",
    "too many arguments provided",
    "not enough arguments provided",
    "bad item in bound variable list",
    "bad keyword arguments",
    "write-error on file",
    "endp used on badly terminated list",
    "environment parameter 'fasldir' not set",
    "loadable module not found for loading",
    "file could not be opened",
    "unable to establish pipe",
    "stack overflow",
    "top bit of address has unexpected value",
    "memory block spans the zero address",
    "this error code available for re-use",
    "unable to find a directory for temporary files",
    "dummy final error message"
};
#endif

#endif // header_cslerror_h

// end of cslerror.h
