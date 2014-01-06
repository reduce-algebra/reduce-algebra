/* proc.h                              Copyright (C) 2010 Codemist Ltd */

#ifndef header_proc_h
#define header_proc_h 1



/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
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

/* $Id$ */


/*
 * Definitions useful for driving the procedural interface to Reduce...
 */

/*
 * These types are used for callback functions used to send and receive
 * characters.
 */

typedef int character_reader(void);
typedef int character_writer(int);

/*
 * When a handle on an expression is returned to the user this is the
 * type it has. The type should be treated as opaque, please.
 */

typedef void *PROC_handle;

/*
 * Before trying to do anything at all you must call cslstart. This will
 * allocate memory, load an initial heap image etc etc. The argc and argv
 * passed here are as per normal C startup. The key issue here is how
 * Reduce will find the file "reduce.img" that it needs to load. There are
 * two plausible ways you can achieve this.
 * (a) argv[0] should contain a (for choice) fully rooted path as in
 *     /usr/local/bin/reduce
 * or  c:\my-reduce\binaries\reduce.exe
 *     In that case the name of the supposed execitable has ".img" tagged
 *     onto it, so the image is expected to be at say /usr/local/bin/reduce.img
 *     If the application name is the name of a symbolic link then the
 *     image file is looked for in the dircetory that the link points to.
 * (b) You can put "-i" "/path/to/reduce.img" in two consecutive entries
 *     in argv to give an explicit indication of where the image file
 *     is to be found. This should override any attempt to look via
 *     argv[0].
 * Most users should not need to provide any further options, but options
 * are decoded just as for the ordinary version of the system.
 *
 * Any textual output generated during system-started is sent, character
 * by character, via the callback function. Eg pass an option "-v" in
 * argv and see a big banner.
 */

extern void cslstart(int argc, char *argv[], character_writer *wr);

/*
 * At the end of a run please call cslfinish to close down everything
 * in a reasonably orderly manner and release memory. I should cautiously
 * note that the system will have some memory leaks so cslfinish will
 * not return EVERYTHING that has been allocated - if this worries you
 * please search for and correct the defects. Again the callback function
 * is used to process any output generated during close-down.
 */

extern int cslfinish(character_writer *wr);

/*
 * As a general-purpose escape it is possible to get a Lisp function
 * (with no arguments) called. This function does that re-binding
 * what would otherwise be terminal input and output to the two
 * callback functions. By writing your own custom Lisp function and then
 * calling it this way you get almost ultimate flexibility, if not
 * convenience! For used of the Reduce algebra system I hope that the
 * suite of more specialised functions listed later on will prove
 * easier to use.
 */

extern int execute_lisp_function(char *fname,
                                 character_reader *r,
                                 character_writer *w);


/*
 * The next collection of functions provide for interaction with the
 * Reduce algebra system using a model based on a Reverse Polish
 * Calculator. You use RPN-style calls to build a fragment of parse
 * tree and can them as Reduce to "simplify" it. Having simplified it
 * you can ask for a simple prefix-form of the result to be generated and
 * returned, and there are functions for traversing that.
 */

/*
 * Example:
 *  Task:   differentiate (x+1)^2 with respect to x
 *  Method: clear_stack();
 *          push_symbol("x");
 *          push_small_integer(1);
 *          make_function_call("plus",2);   function plus has 2 arguments.
 *          push_small_integer(2);
 *          make_function_call("expt",2);
 *          push_symbol("x");
 *          make_function_call("df",2);     "df" is for differentiate.
 *                                          To use this you need to learn
 *                                          the named Reduce uses for all
 *                                          relevant operations.
 *          simplify();                     up until now the form built
 *                                          has been just the prefix form
 *                                          (expt (plus x 1) 2).
 *          dup();                          because save will pop the stack
 *          save(1);                        save in "memory number 1".
 *          make_printable();               the simplified form is in
 *                                          a Reduce internal representation,
 *                                          so this restores it to simple
 *                                          prefix form.
 *          p = get_value();
 * now p holds a handle on the result, and it can be traversed
 * using functions atom(), first(), rest() and functions that extract the
 * name of a symbol or the value of an integer. You should assume that the
 * handle becomes invalid as soon as you call one of the other functions.
 * this is because they can all trigger garbage collection and that can
 * relocate data.
 * The functions used to build expressions all return zero on success or
 * an error-code otherwise. In the initial release the error-codes are
 * not documented other than via reading the source files. Furthermore the
 * consequence of a calculation seeking input or generating output is not
 * well sorted.
 */


/*
 * After having called cslstart() you can set the I/O callback functions
 * using this. If you set one or both to NULL this indicates use of
 * stdin/stdout as per usual rather than an callback, otherwise whenever
 * anybody wants to read or write they use these procedures. It is then
 * your responsibility to cope with whatever text gets exchanged!
 */

extern int PROC_set_callbacks(character_reader *r,
                              character_writer *w);

/*
 * Load a Reduce "package".
 */

int PROC_load_package(char *name);

/*
 * Set of clear a Reduce switch. As on "on expandlogs;"
 * which you do via PROC_set_switch("expandlogs", 1);
 * Use 0 to switch something off and 1 to switch it on.
 */

int PROC_set_switch(char *name, int val);

/*
 * Set level of garbage collector noise. This might often be a bit irrelevant,
 * but
 *    0    no messages at all
 *    +1   messages whenever garbage collection happens
 *    +2   messages whenever a module of code is loaded
 *    +4   extra details in the garbage collector messages
 * Note that if an ALWAYS_NOISY option (probably set as a side effect
 * of the debugging command line option "-g") is in play then any
 * call here has +1 and +2 forced active.
 */

int PROC_gc_messages(int n);

/*
 *    stack = nil;
 */
extern int PROC_clear_stack();

/*
 *    stack = name . stack;
 */

extern int PROC_push_symbol(const char *name);

/*
 *    stack = the-string . stack;
 */

extern int PROC_push_string(const char *data);

/*
 *    stack = n . stack;
 * Small integers may be up to 28-bits of (signed) data, while
 * big integers can be almost any size and are denoted here by strings.
 * Eg:  PROC_push_small_integer(134217727);    largest positive small num
 *      PROC_push_small_integer(-134217728);   extreme negative case 
 *      PROC_push_big_integer("-12345678901234567890");
 */

extern int PROC_push_small_integer(int32_t n);

extern int PROC_push_big_integer(const char *n);

extern int PROC_push_floating(double n);

/*
 * Takes n items from the top of the stack and uses them as arguments
 * for a function as specified by the name. Leaves the result on the
 * top of the stack. Arguments will have been pushed with arg1 pushed
 * first and the last argument pushed last.
 */

extern int PROC_make_function_call(const char *name, int n);

/*
 * Save whatever is on top of the stack in memory location n. At present
 * I provide 100 memory locations, whihc ar enumbered 0 to 99.
 */

extern int PROC_save(int n);

/*
 * Push the contents of memory location n onto the stack.
 */

extern int PROC_load(int n);

/*
 * Duplicate the top stack element.
 */

extern int PROC_dup();

/*
 * Discard the top stack element.
 */

extern int PROC_pop();

/*
 * The top item on the stack is replaced with what happens when Reduce
 * is asked to "simplify" or "evaluate" it. The result can then be stored
 * or combined with other items, but it will not in general be in a format
 * directly convenient for use by humans.
 */

extern int PROC_simplify();

/*
 * Replace the top item on the stack with a version of the same expression
 * in a reasonably simple prefix notation.
 * This representation is NOT intended for re-input to any calculation -
 * it is only intended for inspecial by the client code that is using Reduce
 * via this interface. To that end it may in the future return big integers
 * in a form where they have been converted to Lisp strings and may make
 * other transformations that would hurt attempts to re-use the expression.
 */

extern int PROC_make_printable();

/*
 * Return a handle to the top item on the stack, and pop the stack. This
 * will normally be called immediately after a call to PROC_make_printable.
 * the stack is popped because I view the "printable" version as unsuitable
 * for further use.
 */

extern PROC_handle PROC_get_value();

/*
 * The next few functions are predicates that may be applied to handles.
 * An "atom" is any non-composite form. A fixnum is a small integer, and
 * a symbol is a name.
 */

extern int PROC_atom(PROC_handle p);
extern int PROC_null(PROC_handle p);
extern int PROC_fixnum(PROC_handle p);
extern int PROC_floatnum(PROC_handle p);
extern int PROC_string(PROC_handle p);
extern int PROC_symbol(PROC_handle p);

/*
 * If something is not an atom it will be a list, and the following two
 * functions return the components of it. In general non-atomic items will
 * be structured as
 *     (fname arg1 arg2 ...)
 * with "well understood" function names "plus", "difference", "minus",
 * "times", "quotient", "expt" being used to denote use of the main
 * arithmetic connectives. A Lisp fanatic would have named the following
 * two functions PROC_car and PROC_cdr!
 */

extern PROC_handle PROC_first(PROC_handle p);
extern PROC_handle PROC_rest(PROC_handle p);

/*
 * If something is an atom then these make it possible to extract details
 * of what it represents. In due course I may support floating point values
 * and big numbers, but release 1 of those code concentrates on the basics.
 */

extern int32_t PROC_integer_value(PROC_handle p);
extern double PROC_floating_value(PROC_handle p);
extern const char *PROC_symbol_name(PROC_handle p);
extern const char *PROC_string_data(PROC_handle p);

/*
 * I also provide some calls that support a sort of ultimate cop-out in
 * that they maye it possible to call Lisp code directly rather than
 * just invoking the Reduce simplifier. They also allow one to get back a
 * raw Lisp result which will have had gensym-names solidified but which
 * is otherwise unaltered. Note that the way this is achieved means that
 * things will FAIL if the Lisp result were to be a cyclic structure!
 */


/*
 * Replace the top item on the stack with whatever is obtained by using
 * the Lisp EVAL operation on it. Note that this is not intended for
 * casual use - if there is any functionality that you need PLEASE ask
 * me to put in a cleaner abstraction to support it.
 */

extern int PROC_lisp_eval();

/*
 * Return a handle to the top item on the stack, and pop the stack.
 * The value here will be a RAW LISP structure and NOT at all necessarily
 * anything neat.
 */

extern PROC_handle PROC_get_raw_value();



#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf my_exit_buffer;
#endif
#endif
extern volatile int my_return_code;

#endif /* header_proc_h */

/* end of proc.h */

