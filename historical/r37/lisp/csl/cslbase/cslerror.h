/*  cslerror.h                        Copyright (C) 1989-2002 Codemist Ltd */

/*
 * Error codes and functions.
 *
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */

/* Signature: 3cbc3365 08-Apr-2002 */

#ifndef header_cslerror_h
#define header_cslerror_h 1

extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);

extern Lisp_Object aerror(char *s);         /* Called from C not Lisp */
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);

#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07

#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20

#define verbos_flag (miscflags & GC_MSG_BITS)

/*
 * It is essential that the #define values set up here are kept in
 * step with the textual error messages in the array that follows...
 */
 
#define err_bad_car               0      /* + the atom */
#define err_bad_cdr               1      /* + the atom */
#define err_no_store              2      /* no extras */
#define err_undefined_function_1  3      /* + fn name */
#define err_undefined_function_2  4      /* + fn name */
#define err_undefined_function_n  5      /* + fn name */
#define err_wrong_no_args         6      /* fn name, actual arg count */
#define err_unbound_lexical       7      /* + name */
#define err_bad_rplac             8      /* + atom */
#define err_bad_arith             9      /* + bad value */
#define err_redef_special        10      /* + name */
#define err_bad_arg              11      /* + offending value */
#define err_bad_declare          12      /* + offending value */
#define err_bad_fn               13      /* + offending value */
#define err_unset_var            14      /* + name */
#define err_too_many_args1       15      /* no extras */
#define err_too_many_args2       16      /* no extras */
#define err_bad_apply            17      /* + bad thing */
#define err_macroex_hook         18      /* what it is */
#define err_block_tag            19      /* bad tag */
#define err_go_tag               20      /* bad tag */
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      /* + offending value */
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      /* + the non-null atom */
#define err_no_fasldir           27
#define err_no_fasl              28      /* plus module name */
#define err_open_failed          29      /* plus file name */
#define err_pipe_failed          30      /* plus command for execution */
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_registration         34
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments",
    "too many arguments",
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
    "registration code corrupt or invalid",
    "dummy final error message"
};
#endif

#endif /* header_cslerror_h */

/* end of cslerror.h */

