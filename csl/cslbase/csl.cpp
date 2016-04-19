// csl.cpp                            Copyright (C) 1989-2016 Codemist    

//
// This is Lisp system for use when delivering Lisp applications
// (such as REDUCE) on pretty-well any computer that has an ANSI
// C compiler.
//

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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


//
// When built using wxWidgets this code will use the Latin Modern
// fonts, which are subject to the LaTeX Project Public License. This
// comment is places somewhere I view as pretty prominent - ie at the head
// of the source of the main part of the code. I have further comments
// and explanation lower in this file such that invoking CSL or
// Reduce with an option "--help" will generate the required credits and
// notices, so if this matters to you search this file for the string
// "LaTeX" for more information.
//

// $Id$


//
// There are a number of comments here introduced with exclamation
// mark after the "/" and "*" that start them. These contain material
// to be extracted to form documentation. They MUST remain as slash-star
// style comments with format as used here so that the documentation
// extraction utility can find them.
//

/*!!! csl
 * \documentclass[a4paper,11pt]{article}
 * \title{CSL reference}
 * \author{A C Norman}
 * \usepackage{makeidx}
 * \makeindex
 * \begin{document}
 * \maketitle
 */

/*!! intro [00] \section{Introduction}
 * This is reference material for CSL. The Lisp identifiers mentioned here
 * are the ones that are initially present in a raw CSL image. Some
 * proportion of them are not really intended to be used by end-users but
 * are merely the internal components of some feature.
 */

/*!! options [01] \section{Command-line options}
 * The items shown here are the ones that are recognized on the CSL command
 * line. In general an option that requires an argument can be written as either
 * {\ttfamily -x yyy} or as {\ttfamily -xyyy}. Arguments should be case
 * insensitive.
 * \begin{description}
 */

/*! options [~~~~~~~~] \end{description} % end of options section [csl.c]
 */

/*!! predef [02] \section{Predefined variables}
 * \begin{description}
 */

/*! predef [~~~~~~~~] \end{description} % end of predef section [csl.c]
 */

/*!! flags [04] \section{Flags and Properties}
 *
 * Most of tags here are probably not much use to end-users, but I am
 * noting them as a matter of completeness.
 *
 * \begin{description}
 */

/*! flags [~~~~~~~~] \end{description} % end of flags section [csl.c]
 */

/*!! index [~~~~~~~~] % The index will go here
 * \printindex
 * \end{document}
 */


#define  INCLUDE_ERROR_STRING_TABLE 1
#include "headers.h"
#undef   INCLUDE_ERROR_STRING_TABLE

#include "version.h"

#ifdef SOCKETS
#include "sockhdr.h"
#endif

#ifndef WIN32
#include <sys/wait.h>
#endif

#ifdef HAVE_UNISTD_H
#include <sys/unistd.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif

#ifndef HAVE_FWIN
//
// During startup on a windowed system if I needed to report an error
// but the window was minimised I need to restore it...
//
#define fwin_restore()
#endif

#ifdef SOCKETS

#if 0
// Being removed
static int port_number, remote_store, current_users, max_users;
SOCKET socket_server;
clock_t cpu_timeout;
time_t elapsed_timeout;
static int char_to_socket(int c);
#endif

int sockets_ready = 0;

#endif

//
// These flags are used to ensure that protected symbols don't get
// overwritten by default, and that the system keeps quiet about it.
//

bool symbol_protect_flag = true;
bool warn_about_protected_symbols = false;

#if defined WINDOW_SYSTEM && !defined EMBEDDED
bool use_wimp;
#endif

#ifdef USE_MPI
int32_t mpi_rank,mpi_size;
#endif

/*****************************************************************************/
//      Error reporting and recovery
/*****************************************************************************/

volatile char stack_contents_temp = 0;

#ifdef CHECK_STACK
//
// Some computers are notably unhelpful about their behaviour when the system
// stack overflows. As a debugging tool on such machines I can do limited
// software checking by inserting explicit calls to this function in places
// I think may be critical.  I impose an arbitrary limit on the stack size,
// but that is better than no checking and random corruption - maybe. Please
// do not enable CHECK_STACK unless it is really necessary to hunt a bug,
// since it is miserably expensive and crude. I appear to observe that on
// my Windows versions (both 32 and 64-bit) there is around 2M of stack, while
// on Linux the amount of stack is set via ulimit and is not fixed.
//

#define C_STACK_ALLOCATION 1000000

static int spset = 0;
static intptr_t spbase = 0, spmin;

static uintptr_t stack_depth[C_STACK_ALLOCATION];
static int stack_line[C_STACK_ALLOCATION];
static char *stack_file[C_STACK_ALLOCATION];
static uintptr_t c_stack_ptr = 0;

int check_stack(char *file, int line)
{   uintptr_t temp = (intptr_t)&temp;
    char *file1;
    int first = 1;
    if (!spset)
    {   spbase = spmin = temp;
        spset = 1;
        c_stack_ptr = 0;
        stack_depth[0] = temp;
        stack_line[0] = line;
        stack_file[0] = file;
    }
    if (temp < stack_depth[c_stack_ptr] && c_stack_ptr<C_STACK_ALLOCATION-2)
        c_stack_ptr++;
    else while (temp > stack_depth[c_stack_ptr] && c_stack_ptr>0)
            c_stack_ptr--;
    stack_depth[c_stack_ptr] = temp;
    stack_line[c_stack_ptr] = line;
    file1 = strrchr(file, '/');
    stack_file[c_stack_ptr] = (file1 == NULL ? file : file1+1);
    if (temp < spmin-250)  // Only check at granularity of 250 bytes
    {   int i, j=0;
        term_printf("Stack depth %u at file %s line %d\n",
                    (unsigned int)(spbase-temp), file, line);
        term_printf("c_stack_ptr = %d\n", c_stack_ptr);
        for (i=c_stack_ptr; i>=0; i--)
        {   if (first || stack_file[i][0] != '@')
                term_printf(" %s:%d:%" PRIxPTR,
                            stack_file[i], stack_line[i], stack_depth[i]);
            if (stack_file[i][0] != '@') first = 0;
            if ((++j)%5 ==4) term_printf("\n");
        }
        term_printf("\n");
        spmin = temp;
        if (temp < spbase-C_STACK_ALLOCATION ||
            temp < (uintptr_t)C_stack_limit) return 1;
    }
    return 0;
}

void show_stack()
{   int i, j=0;
    term_printf("\n+++ Stack overflow traceback...\n");
    for (i=c_stack_ptr; i>=0; i--)
    {   if (j++ > 10)
        {   term_printf("\n");
            j = 0;
        }
        term_printf(" %d) %s:%d", i, stack_file[i], stack_line[i]);
    }
    term_printf("\n");
}

#endif

//
// error_message_table was defined in cslerror.h since that way I can keep its
// contents textually close to the definitions of the message codes that it
// has to relate to.
//

#define errcode(n) error_message_table[n]

LispObject error(int nargs, int code, ...)
//
// nargs indicates how many values have been provided AFTER the
// code.  Thus nargs==0 will just display a simple message, nargs==1
// will be a message plus a value and so on.  I will expect that the
// number of actual args here is well within any limits that I ought to
// impose.
//
{   va_list a;
    int i;
    LispObject nil = C_nil, w1;
    LispObject *w = (LispObject *)&work_1;
    if (nargs > ARG_CUT_OFF) nargs = ARG_CUT_OFF;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("\n+++ Error %s: ", errcode(code));
//
// There is now some painful shuffling around to get all the args
// to error() moved over onto the Lisp stack so that is garbage collection
// is triggered during printing all will be well.
//
        va_start(a, code);
        for (i=0; i<nargs; i++) *w++ = va_arg(a, LispObject);
        va_end(a);
        for (i=0; i<nargs; i++) push(*--w);
        if (code != err_stack_overflow)  // Be cautious here!
        {   stackcheck0(nargs);
        }
        for (i=0; i<nargs; i++)
        {   LispObject p;
            pop(p);
            loop_print_error(p);
            err_printf("\n");
        }
    }
    if ((w1 = qvalue(break_function)) != nil &&
        symbolp(w1) &&
        qfn1(w1) != undefined1)
    {   (*qfn1(w1))(qenv(w1), nil);
        ignore_exception();
    }
//
// After doing this is is necessary to be VERY careful, since nil is
// used as a base register for lots of things...  Still this is the
// cheapest way I can see to mark the need for unwinding.
//
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

LispObject cerror(int nargs, int code1, int code2, ...)
//
// nargs indicated the number of EXTRA args after code1 & code2.
//
{   LispObject nil = C_nil, w1;
    va_list a;
    int i;
    LispObject *w = (LispObject *)&work_1;
    if (nargs > ARG_CUT_OFF) nargs = ARG_CUT_OFF;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("\n+++ Error %s, %s: ", errcode(code1), errcode(code2));
        va_start(a, code2);
        for (i=0; i<nargs; i++) *w++ = va_arg(a, LispObject);
        va_end(a);
        for (i=0; i<nargs; i++) push(*--w);
        stackcheck0(nargs-2);
        nil = C_nil;
        for (i=0; i<nargs; i++)
        {   LispObject p;
            pop(p);
            loop_print_error(p);
            err_printf("\n");
        }
    }
    if ((w1 = qvalue(break_function)) != nil &&
        symbolp(w1) &&
        qfn1(w1) != undefined1)
    {   (*qfn1(w1))(qenv(w1), nil);
        ignore_exception();
    }
//
// After doing this is is necessary to be VERY careful, since nil is
// used as a base register for lots of things...  Still this is the
// cheapest way I can see to mark the need for unwinding.
//
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

//
// This can be used when a resource expires...
//
LispObject resource_exceeded()
{   LispObject nil = C_nil;
    exit_reason = UNWIND_RESOURCE;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

LispObject interrupted(LispObject p)
//
// Could return onevalue(p) to proceed from the interrupt event...
//
{   LispObject nil = C_nil, w;
//
// If I have a windowed system I expect that the mechanism for
// raising an exception will have had a menu that gave me a chance
// to decide whether to proceed or abort.  Thus the following code
// is only needed if there is no window system active.  On some systems
// this may be an active check.
//
#ifdef HAVE_FWIN
    if ((fwin_windowmode() & FWIN_IN_WINDOW) == 0)
#else
#if defined WINDOW_SYSTEM && !defined EMBEDDED
    if (!use_wimp)
#endif
#endif
    {   if (clock_stack == &consolidated_time[0])
        {   clock_t t0 = read_clock();
//
// On at least some (Unix) systems clock_t is a 32-bit signed value
// and CLOCKS_PER_SEC = 1000000. The effect is that integer overflow
// occurs after around 35 minutes of running. I must therefore check the
// clock and move information into a floating point variable at least
// every half-hour.  With luck I will do it more like 20 times per second
// because I have code muck like this in a tick handler that is activated
// on a rather regular basis on at least some systems. On others this
// clock overfow issue is a bit of a pain and I really ought just to use
// a different low-level API for timing that can not so suffer. But
// as a bit of a fall-back I will see if the garbage collector can
// consolidate time for me and since I ignore time spent waiting for the
// keyboard overflows due to 35 minutes of activity there will not hurt so
// I am probably at worst at risk if I can compute for a solid half
// hour without triggering garbage collection.
//
            double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
            base_time = t0;
            consolidated_time[0] += delta;
        }
#ifndef NAG
#ifdef HAVE_FWIN
        term_printf("\n");
#else
        term_printf(
            "\n+++ [%.2f+%.2f] Type C to continue, A to abort, X to exit\n",
            consolidated_time[0], gc_time);
#endif
        ensure_screen(); nil = C_nil;
        if (exception_pending()) return nil;
        push(prompt_thing);
        prompt_thing = nil;  // switch off the regular prompts
#ifdef HAVE_FWIN
        fwin_set_prompt("+++ Type C to continue, A to abort, X to exit: ");
#endif

        other_read_action(READ_FLUSH, lisp_terminal_io);
        for (;;)
        {   int c = char_from_terminal(nil);
//
// Note that I explicitly say "char_from_terminal()" here - this is because
// I do not expect to be interrupted unless there was a terminal available
// to send the interrupt! This is in fact a slightly marginal assumption.
//
            switch (c)
            {   case 'c': case 'C':         // proceed as if no interrupt
                    pop(prompt_thing);
#ifdef HAVE_FWIN
                    fwin_set_prompt(prompt_string);
#endif
                    return onevalue(p);
                case 'a': case 'A':         // raise an exception
                    break;
                case 'x': case 'X':
                    my_exit(EXIT_FAILURE); // Rather abrupt
                case '\n':
#ifndef HAVE_FWIN
                    term_printf("C to continue, A to abort, X to exit: ");
#endif
                    ensure_screen(); nil = C_nil;
                    if (exception_pending()) return nil;
                    continue;
                default:                    // wait for A or C
                    continue;
            }
            break;
        }
        pop(prompt_thing);
#ifdef HAVE_FWIN
        fwin_set_prompt(prompt_string);
#endif
#endif
    }
//
// now for the common code to be used in all cases.
//
    if (miscflags & HEADLINE_FLAG)
        err_printf("+++ Interrupted\n");
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

LispObject aerror(const char *s)
{   LispObject nil = C_nil, w;
    if (miscflags & HEADLINE_FLAG)
        err_printf("+++ Error bad args for %s\n", s);
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

LispObject aerror0(const char *s)
{   LispObject nil = C_nil, w;
    if (miscflags & HEADLINE_FLAG)
        err_printf("+++ Error: %s\n", s);
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
#ifdef COMMON
//
// This is to help me debug in the face of low level system crashes
//
    if (spool_file) fflush(spool_file);
#endif
    return nil;
}

LispObject aerror1(const char *s, LispObject a)
{   LispObject nil = C_nil, w;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("+++ Error: %s ", s);
        loop_print_error(a);
        err_printf("\n");
    }
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
#ifdef COMMON
//
// This is to help me debug in the face of low level system crashes
//
    if (spool_file) fflush(spool_file);
#endif
    return nil;
}

LispObject aerror2(const char *s, LispObject a, LispObject b)
{   LispObject nil = C_nil, w;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("+++ Error: %s ", s);
        loop_print_error(a);
        err_printf(" ");
        loop_print_error(b);
        err_printf("\n");
    }
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
#ifdef COMMON
//
// This is to help me debug in the face of low level system crashes
//
    if (spool_file) fflush(spool_file);
#endif
    return nil;
}

static LispObject wrong(int wanted, int given, LispObject env)
{   char msg[64];
    sprintf(msg, "Function called with %d args where %d wanted", given, wanted);
    if (is_cons(env)) env = qcdr(env);
    if ((miscflags & HEADLINE_FLAG) && is_vector(env))
    {   LispObject fname = elt(env, 0);
        err_printf("\nCalling ");
        loop_print_error(fname);
        err_printf("\n");
    }
    return aerror(msg);
}

LispObject too_few_2(LispObject env, LispObject)
{   return wrong(2, 1, env);
}

LispObject too_many_1(LispObject env, LispObject, LispObject)
{   return wrong(1, 2, env);
}

LispObject wrong_no_0a(LispObject env, LispObject)
{   return wrong(0, 1, env);
}

LispObject wrong_no_0b(LispObject env, LispObject, LispObject)
{   return wrong(0, 2, env);
}

LispObject wrong_no_3a(LispObject env, LispObject)
{   return wrong(3, 1, env);
}

LispObject wrong_no_3b(LispObject env, LispObject, LispObject)
{   return wrong(3, 2, env);
}

LispObject wrong_no_na(LispObject env, LispObject)
{   if (is_cons(env) && is_bps(qcar(env)))
        return wrong(((unsigned char *)data_of_bps(qcar(env)))[0], 1, env);
    else return aerror("function called with 1 arg when 0 or >= 3 wanted");
}

LispObject wrong_no_nb(LispObject env, LispObject, LispObject)
{   if (is_cons(env) && is_bps(qcar(env)))
        return wrong(((unsigned char *)data_of_bps(qcar(env)))[0], 2, env);
    else return aerror("function called with 2 args when 0 or >= 3 wanted");
}

LispObject wrong_no_1(LispObject env, int nargs, ...)
{   return wrong(1, nargs, env);
}

LispObject wrong_no_2(LispObject env, int nargs, ...)
{   return wrong(2, nargs, env);
}

LispObject bad_specialn(LispObject, int, ...)
{   return aerror("call to special form");
}

void fatal_error(int code, ...)
{
//
// Note that FATAL error messages are sent to the terminal, not to the
// error output stream. This is because the error output stream may be
// corrupted in such dire circumstances.
//
    term_printf("+++ Fatal error %s\n", errcode(code));
    if (spool_file != NULL)
    {
#ifdef COMMON
        fprintf(spool_file, "\nFinished dribbling to %s.\n", spool_file_name);
#else
        fprintf(spool_file, "\n+++ Transcript terminated after error +++\n");
#endif
        fclose(spool_file);
        spool_file = NULL;
    }
    my_exit(EXIT_FAILURE);
}

static const char *dependency_file = NULL;

static char **dependency_map = NULL;
static int dependency_count = 0, dependency_capacity = 0;

void report_file(const char *s)
{   char *c;
    const char *s1;
    int i;
    if (dependency_file == NULL) return;
//
// In a really odd way I will avoid recording inline-defs.dat as a
// dependency and insist that if it is to be one that the Makefile should
// list that explicitly. This helps me avoid some dependency circularities.
// but note that inline-defs.dat may not be in the current directory.
// Use of that file-name for any other purposes may cause issues!
// Here I find the final component of the path - ie the bit following the
// last "/" or "\" present if there is one of those.
//
    if ((s1 = strrchr(s, '/')) != NULL) s1++;
    else if ((s1 = strrchr(s, '\\')) != NULL) s1++;
    else s1 = s;
    if (strcmp(s1, "inline-defs.dat") == 0) return;
    if (dependency_count >= dependency_capacity)
    {   dependency_capacity = 2*dependency_capacity + 40;
        dependency_map = (char **)realloc(dependency_map,
                                          dependency_capacity*sizeof(char *));
        if (dependency_map == NULL)
        {   dependency_capacity = dependency_count = 0;
            return;
        }
    }
    for (i=0; i<dependency_count; i++)
    {   if (strcmp(s, dependency_map[i]) == 0) return; // already recorded
    }
    c = (char *)malloc(strlen(s) + 1);
    if (c == NULL) return;
    strcpy(c, s);
    dependency_map[dependency_count++] = c;
}

static int alphorder(const void *a, const void *b)
{   char *aa = *(char **)a;
    char *bb = *(char **)b;
    return strcmp(aa, bb);
}

static void report_dependencies()
{   FILE *f;
    int i, c;
    const char *p;
    if (dependency_file == NULL) return;
    f = fopen(dependency_file, "w");
    if (f == NULL) return;
    p = strrchr(dependency_file, '.');
    fprintf(f, "%.*sdep = \\\n", (int)(p==NULL ? strlen(dependency_file) :
                                       (p - dependency_file)),
            dependency_file);
    qsort(dependency_map, dependency_count,
          sizeof(char *), alphorder);
    for (i=0; i<dependency_count; i++)
    {   p = dependency_map[i];
        putc('\t', f);
//
// If I am on Windows some files may at this stage be shown with names
// of the form "X:/..." where X denotes the drive. But the dependencies I
// am creating are for the benefit of the cygwin version of GNU make, and
// that will get seriously upset by the colon, thinking it is indicating that
// I have multiple targets. So I will map "X:/" onto "/cygdrive/x/".
//
        if (p[0] != 0 &&
            p[1] == ':' &&
            (p[2] == '/' || p[2] == '\\'))
        {   fprintf(f, "/cygdrive/%c", (char)tolower((unsigned char)p[0]));
            p+=2;
        }
        while ((c = *p++) != 0)
        {   if (c == ' ') putc('\\', f); // for spaces in file-name
            putc(c == '\\' ? '/' : c, f);
        }
        if (i < dependency_count-1)
        {   putc(' ', f);
            putc('\\', f);
        }
        putc('\n', f);
    }
    putc('\n', f);
    fclose(f);
    dependency_file = NULL;
}

void my_exit(int n)
{
//
// This all seems a HORRID MESS. It is here because of a general need to
// tidy up at the end of a run, and the fact that I may be running as
// a sub-task of some other package so I can not let atexit() take the
// strain since although I am exiting CSL here I may not be (quite yet)
// leaving the whole of the current application.
//
    report_dependencies();
#ifdef USE_MPI
    MPI_Finalize();
#endif
    ensure_screen();
#ifdef SOCKETS
    if (sockets_ready) WSACleanup();
#endif
#ifdef WINDOW_SYSTEM
    pause_for_user();
#endif
#ifdef HAVE_FWIN
    throw n;
#else
#if defined(WIN32) && defined(NAG)
    {   extern void sys_abort(int);
        sys_abort(n);
    }
#else
    exit(n);
#endif
#endif
}

static int return_code = 0;
bool segvtrap = true;
bool batch_flag = false;
bool ignore_restart_fn = false;

#ifdef USE_SIGALTSTACK

static unsigned char signal_stack_block[SIGSTKSZ];

stack_t signal_stack;

#endif

#ifdef HAVE_CRLIBM
static unsigned long long crlibstatus = 0;

static void tidy_up_crlibm()
{   crlibm_exit(crlibstatus);
}
#endif

#if defined __linux__ && defined DEBUG
//
// This is an experiment as to a possible return to generating a
// tick-stream using a system timer rather than "software ticks".
//
volatile int blipflag = 0;
int64_t blipcount = 0, startblip = 0;

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void alarm_handler(int signum)
{   blipflag = 1;
}
#endif

#ifdef DEBUG

char debug_trail[32][32] =
{   "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", ""
};

char debug_trail_file[32][32] =
{   "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", ""
};

int debug_trail_line[32] =
{   0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

int debug_trailp = 0;

void debug_record_raw(const char *data, const char *file, int line)
{   const char *f1 = strrchr(file, '/');
    if (f1 != NULL) f1++;
    else f1 = file;
    if (data != NULL)
    {   strncpy(debug_trail[debug_trailp], data, 32);
        strncpy(debug_trail_file[debug_trailp], f1, 32);
        debug_trail_line[debug_trailp] = line;
        debug_trailp = (debug_trailp+1)%32;
    }
}

void debug_record_int_raw(const char *data, int n, const char *file, int line)
{   const char *f1 = strrchr(file, '/');
    if (f1 != NULL) f1++;
    else f1 = file;
    if (data != NULL)
    {   sprintf(debug_trail[debug_trailp], "%s%d", data, n);
        strncpy(debug_trail_file[debug_trailp], f1, 32);
        debug_trail_line[debug_trailp] = line;
        debug_trailp = (debug_trailp+1)%32;
    }
}

void debug_show_trail_raw(const char *msg, const char *file, int line)
{   int i;
    const char *f1 = strrchr(file, '/');
    if (f1 == NULL) f1 = "?";
    else f1++;
    printf("\n+++++ Debug trail %s\n", msg);
    for (i=0; i<32; i++)
    {   if (debug_trail[debug_trailp][0] == 0) continue;
        printf("%d: %.32s at %.32s:%d\n", i, debug_trail[debug_trailp],
               debug_trail_file[debug_trailp], debug_trail_line[debug_trailp]);
        debug_trailp = (debug_trailp+1)%32;
    }
    printf("Current at %s:%d", f1, line);
    fflush(stdout);
}

#endif

static void lisp_main(void)
{
    volatile LispObject nil;
    volatile int i;
#if defined __linux__ && defined DEBUG
    struct itimerval tv;
    blipflag = 0;
    blipcount = 0;
    signal(SIGALRM, alarm_handler);
    tv.it_interval.tv_usec = 900000;
    tv.it_interval.tv_sec = 0;
    tv.it_value.tv_usec = 900000;
    tv.it_value.tv_sec = 0;
    setitimer(ITIMER_REAL, &tv, NULL);
#endif
#ifdef USE_SIGALTSTACK
//
// If I get a SIGSEGV that is caused by a stack overflow then I am in
// a world of pain because the regular stack does not have space to run my
// exception handler. So where I can I will arrange that the exception
// handler runs in its own small stack. This may itself lead to pain,
// but perhaps less?
//
    signal_stack.ss_sp = (void *)signal_stack_block;
    signal_stack.ss_size = SIGSTKSZ;
    signal_stack.ss_flags = 0;
    sigaltstack(&signal_stack, (stack_t *)0);
#endif
#ifdef HAVE_CRLIBM
    crlibstatus = crlibm_init();
    atexit(tidy_up_crlibm);
#endif
    trap_floating_overflow = true;
    tty_count = 0;
    while (true)
//
// The sole purpose of the while loop here is to allow me to proceed
// for a second try if I get a (cold-start) call.
//
    {   LispObject * volatile save = stack;
        nil = C_nil;
        errorset_msg = NULL;
        try
        {   nil = C_nil;
            terminal_pushed = NOT_CHAR;
            if (supervisor != nil && !ignore_restart_fn)
            {   miscflags |= BACKTRACE_MSG_BITS;
//
// Here I reconstruct the argument that I passed in (restart_csl f a).
//
                if (exit_charvec != NULL)
                {   LispObject a = read_from_vector(exit_charvec);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        a = nil;
                    }
                    free(exit_charvec);
                    exit_charvec = NULL;
                    push(a);
#ifndef NO_BYTECOUNT
                    name_of_caller = "restart function";
#endif
                    apply(supervisor, 1, nil, supervisor, 0);
                }
                else
                {
#ifndef NO_BYTECOUNT
                    name_of_caller = "restart function";
#endif
                    apply(supervisor, 0, nil, supervisor, 0);
                }
            }
//
// Here the default read-eval-print loop used if the user has not provided
// a supervisor function.
//
            else read_eval_print(lisp_true);
        }
        catch (const char *)
        {   nil = C_nil;
            if (errorset_msg != NULL)
            {   term_printf("\n%s detected\n", errorset_msg);
                errorset_msg = NULL;
            }
            unwind_stack(save, false);
            exit_reason = UNWIND_ERROR;
            flip_exception();
#ifndef UNDER_CE
            signal(SIGFPE, low_level_signal_handler);
#ifdef USE_SIGALTSTACK
// SIGSEGV will be handled on the alternative stack
            {   struct sigaction sa;
                sa.sa_handler = low_level_signal_handler;
                sigemptyset(&sa.sa_mask);
                sa.sa_flags = SA_ONSTACK | SA_RESETHAND;
                if (segvtrap) sigaction(SIGSEGV, &sa, NULL);
            }
#else
            if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#endif
#ifdef SIGBUS
            if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
            if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
#endif
        }
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            if (exit_reason == UNWIND_RESTART)
            {   if (exit_tag == fixnum_of_int(0))      // "stop"
                    return_code = (int)int_of_fixnum(exit_value);
                else if (exit_tag == fixnum_of_int(1)) // "preserve"
                {   const char *msg = "";
                    int len = 0;
                    return_code = EXIT_SUCCESS;
                    compression_worth_while = 128;
                    if (is_vector(exit_value) &&
                        is_string(exit_value))
                    {   msg = &celt(exit_value, 0);
                        len = (int)(length_of_byteheader(vechdr(exit_value)) - CELL);
                    }
                    preserve(msg, len);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        return_code = EXIT_FAILURE;
                    }
                }
                else if (exit_tag == fixnum_of_int(3)) // "preserve & restart"
                {   const char *msg = "";
                    int len = 0;
                    int32_t fd = stream_pushed_char(lisp_terminal_io);
                    Lrds(nil, nil);
                    Lwrs(nil, nil);
                    return_code = EXIT_SUCCESS;
                    compression_worth_while = 128;
                    if (is_vector(exit_value) &&
                        is_string(exit_value))
                    {   msg = &celt(exit_value, 0);
                        len = (int)(length_of_byteheader(vechdr(exit_value)) - CELL);
                    }
                    preserve(msg, len);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        return_code = EXIT_FAILURE;
                    }
                    for (i=0; i<pages_count; i++)
                    {   char *w = (char *)pages[i];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            continue;
                        pages[i] = pages[--pages_count];
                        i--;
                    }
                    while (vheap_pages_count != 0)
                    {   char *w = (char *)vheap_pages[--vheap_pages_count];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    while (heap_pages_count != 0)
                    {   char *w = (char *)heap_pages[--heap_pages_count];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    while (bps_pages_count != 0)
                    {   char *w = (char *)bps_pages[--bps_pages_count];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    {   char *w = big_chunk_start + NIL_SEGMENT_SIZE;
                        char *w1 = w + CSL_PAGE_SIZE + 16;
                        while (w1 <= big_chunk_end)
                        {   if (w != (char *)stacksegment)
                                pages[pages_count++] = w;
                            w = w1;
                            w1 = w + CSL_PAGE_SIZE + 16;
                        }
                    }
                    CSL_MD5_Init();
                    CSL_MD5_Update((unsigned char *)"Initial State", 13);
                    IreInit();
                    setup(1, 0.0); // warm start mode
                    exit_tag = exit_value = nil;
                    exit_reason = UNWIND_NULL;
                    stream_pushed_char(lisp_terminal_io) = fd;
                    interrupt_pending = already_in_gc = false;
                    tick_pending = tick_on_gc_exit  = false;
                    continue;
                }
                else                                   // "restart"
                {   int32_t fd = stream_pushed_char(lisp_terminal_io);
                    char new_module[64], new_fn[64]; // Limited name length
                    int cold_start;
                    cold_start = (exit_value == nil);
//
// Of course a tick may very well have happened rather recently - so
// I will flush it out now just to clear the air.
//
                    if (stack >= stacklimit)
                    {   reclaim(nil, "stack", GC_STACK, 0);
                        ignore_exception();
                    }
                    cold_start = (exit_value == nil);
                    Lrds(nil, nil);
                    Lwrs(nil, nil);
//
// If either of the above two calls to rds/wrs were to fail I would
// be in a big mess.
//
                    if (!cold_start)
                    {   new_module[0] = 0;
                        new_fn[0] = 0;
                        if (exit_value != lisp_true)
                        {   LispObject modname = nil;
                            if (is_cons(exit_value))
                            {   modname = qcar(exit_value);
                                exit_value = qcdr(exit_value);
                                if (is_cons(exit_value))
                                    exit_value = qcar(exit_value);
                            }
                            if (symbolp(modname) && modname != nil)
                            {   modname = get_pname(modname);
                                if (exception_pending()) ignore_exception();
                                else
                                {   Header h = vechdr(modname);
                                    int32_t len = length_of_byteheader(h) - CELL;
                                    if (len > 63) len = 63;
                                    memcpy(new_module,
                                           (char *)modname + (CELL - TAG_VECTOR),
                                           (size_t)len);
                                    new_module[len] = 0;
                                }
                            }
                            if (symbolp(exit_value) && exit_value != nil)
                            {   exit_value = get_pname(exit_value);
                                if (exception_pending()) ignore_exception();
                                else
                                {   Header h = vechdr(exit_value);
                                    int32_t len = length_of_byteheader(h) - CELL;
                                    if (len > 63) len = 63;
                                    memcpy(new_fn,
                                           (char *)exit_value + (CELL - TAG_VECTOR),
                                           (size_t)len);
                                    new_fn[len] = 0;
                                }
                            }
                        }
                    }
//
// This puts all recorded heap pages back in the main pool, but there is
// as of March 2010 a concern in the case that an initial heap image came
// from a 32-bit machine and I am now running on a 64-bit one. That concerns
// both extra pages allocated at the first startup to give the effect of
// temporarily double-sized pages (there is a space leak there that may
// lose all those pages!) and the expectation there that pages in the map
// are neatly contiguous in memory (and when returned to the pool here that
// expectation usually fails). Oh dear!
// As a rather grungy recovery what I will do is to recycle all of the
// pages that are NOT in the contiguous chunk and then re-create a neat
// map of contiguous space from the bits that are. So first I must remove
// any contiguous pages from the list of ones marked as free...
//
                    for (i=0; i<pages_count; i++)
                    {   char *w = (char *)pages[i];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            continue;
//
// Here the page shown as free is one in the contiguous block. Move in
// the final page to fill the gap here and try again.
//
                        pages[i] = pages[--pages_count];
                        i--;
                    }
//
// Next recycle all the non-contiguous pages that have been in use.
//
                    while (vheap_pages_count != 0)
                    {   char *w = (char *)vheap_pages[--vheap_pages_count];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    while (heap_pages_count != 0)
                    {   char *w = (char *)heap_pages[--heap_pages_count];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    while (bps_pages_count != 0)
                    {   char *w = (char *)bps_pages[--bps_pages_count];
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
//
// Finally rebuild a contiguous block of pages from the wholesale block.
//
                    {   char *w = big_chunk_start + NIL_SEGMENT_SIZE;
                        char *w1 = w + CSL_PAGE_SIZE + 16;
                        while (w1 <= big_chunk_end)
                        {   if (w != (char *)stacksegment)
                                pages[pages_count++] = w;
                            w = w1;
                            w1 = w + CSL_PAGE_SIZE + 16;
                        }
                    }
//
// When I call restart-csl I will leave the random number generator where it
// was. Anybody who wants to reset if either to a freshly randomised
// configuration or to a defined condition must do so for themselves. For
// people who do not care too much what I do here is probably acceptable!
//
                    CSL_MD5_Init();
                    CSL_MD5_Update((unsigned char *)"Initial State", 13);
                    IreInit();
                    setup(cold_start ? 0 : 1, 0.0);
                    exit_tag = exit_value = nil;
                    exit_reason = UNWIND_NULL;
                    stream_pushed_char(lisp_terminal_io) = fd;
                    interrupt_pending = already_in_gc = false;
                    tick_pending = tick_on_gc_exit  = false;
                    if (!cold_start && new_fn[0] != 0)
                    {   LispObject w;
                        if (new_module[0] != 0)
                        {   w = make_undefined_symbol(new_module);
                            Lload_module(nil, w);
                            ignore_exception();
                        }
                        w = make_undefined_symbol(new_fn);
                        nil = C_nil;
                        if (exception_pending()) ignore_exception();
                        else supervisor = w;
                    }
                    continue;
                }
            }
        }
//
// In all normal cases when read_eval_print exits (i.e. all cases except
// if it terminates after (cold-start)) I exit here.
//
        break;
    }
}

#if !defined HAVE_FWIN || defined EMBEDDED
#ifndef UNDER_CE

bool sigint_must_throw = false;

// Note that this version is only used if fwin is not in use (including the
// case of the embedded medule) so there is no clash between this definition
// of sigint_handler and one in fwin.cpp.

void sigint_handler(int code)
{
//
// Note that the only things that I am really allowed to do in a routine
// like this involve setting variables of type sig_atomic_t, which can not
// be viewed as much more than boolean.  The code actually used here is
// somewhat more ambitious (== non-portable!) so must be viewed as delicate.
// ANSI guarantee that throw-ing out of a non-nested signal handler
// is valid.
//
// tick_pending etc allow a steady stream of clock events to
// be handed to Lisp.
//
    interrupt_pending = 1;
    signal(SIGINT, sigint_handler);
    if (sigint_must_throw)
    {   sigint_must_throw = false;
        throw((int *)0);
    }
//
// If there is not a separate regular stream of ticks I will simulate
// the receipt of a tick here. Thus I need to be able to recognize "ticks"
// even on systems where there are no "real" ones.
//
    if (!tick_pending)
    {   if (already_in_gc) tick_on_gc_exit = true;
        else
        {   tick_pending = true;
            saveheaplimit = heaplimit;
            heaplimit = fringe;
            savevheaplimit = vheaplimit;
            vheaplimit = vfringe;
            savecodelimit = codelimit;
            codelimit = codefringe;
            savestacklimit = stacklimit;
            stacklimit = stackbase;
        }
    }
    return;
}

#endif // UNDER_CE
#endif // HAVE_FWIN

//
// OK, I need to write a short essay on "software ticks". A major issue
// for me is synchronization between the worker and the GUI tasks. Lisp
// code can not easily be unilaterally interrupted since it needs to
// preserve GC safety. The easiest way of making progress that I have come up
// with is to arrange that the worker thead (ie the Lisp engine) arranges
// to poll the GUI on a fairly regular basis. I achieve this by making it
// count down in a variable called "countdown" and when that reaches zero
// it deems that a poll is due. I put instructions to decrement countdown in
// a number of places that I expect to be used often enough, and would like
// to have these within all possible loops and such that they are performed
// uniformly over time. These are IDEALS not reality! The countdown overflow
// may happen at somewhat irregular intervals and often at places in the
// code where I am not GC safe. So what I do is to set heap fringes and
// stack fringes so that the next time I try to allocate memory or check
// the stack the situation is noticed and I enter the GC. Once there I
// rapidly detect that this is not a genuine case of having run out of
// memory so I do not do a full GC: I just reset the varios fringes and
// proceed. But while there I know I am in a tidy situation and I can
// exchange information with the GUI. Perhaps as clear-cut case of
// consequence that can arise is that I may respond to a GUI request to
// interrupt what I was doing.
// I try to tune the value that I count down from to get a rate of polling
// that I count as "reasonable" - ie a few per second.
//
// deal_with_tick() is called when the countdown overflows. It resets the
// fringe variables to provoke a GC.
//
// handle_tick() is then a call back out from the GC and could do more
// as required.
//

int32_t software_ticks = 3000;
int32_t number_of_ticks = 0;
int32_t countdown = 3000;

int deal_with_tick(void)
{
#ifdef PENDING_TICK_SUPPORT
    printf("(!)"); fflush(stdout);
    number_of_ticks++;
    if (!tick_pending)
    {   if (already_in_gc) tick_on_gc_exit = true;
        else
        {   tick_pending = true;
            saveheaplimit = heaplimit;
            heaplimit = fringe;
            savevheaplimit = vheaplimit;
            vheaplimit = vfringe;
            savecodelimit = codelimit;
            codelimit = codefringe;
            savestacklimit = stacklimit;
            stacklimit = stackbase;
        }
    }
#endif
    countdown = software_ticks;
    return 1;
}

static long int initial_random_seed, seed2;

const char *files_to_read[MAX_INPUT_FILES],
           *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
           *fasl_paths[MAX_FASL_PATHS];
int output_directory;
character_reader *procedural_input;
character_writer *procedural_output;

bool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];

int number_of_input_files = 0,
    number_of_symbols_to_define = 0,
    number_of_fasl_paths = 0,
    init_flags = 0;

#ifdef WINDOW_SYSTEM
FILE *alternative_stdout = NULL;
#endif

//
// standard_directory holds the name of the default image file that CSL
// would load.
//
const char *standard_directory;

//
// If non-NULL the string module_enquiry is a name presenetd on the
// command line in a "-T name" request, and this will cause the system
// to behave in a totally odd manner - it does not run Lisp at all but
// performs a directory enquiry within the image file.
//
static const char *module_enquiry = NULL;

//
// The next lines mean that (if you can get in before cslstart is
// called) you can get memory allocation done in a custom way.
//

static void *CSL_malloc(size_t n)
{   return malloc(n);
}

static void  CSL_free(void *p)
{   free(p);
}

static void *CSL_realloc(void *p, size_t n)
{   return realloc(p, n);
}

malloc_function  *malloc_hook = CSL_malloc;
realloc_function *realloc_hook = CSL_realloc;
free_function    *free_hook   = CSL_free;

int errorset_min = 0, errorset_max = 3;

int load_count = 0, load_limit = 0x7fffffff;

int csl_argc;
const char **csl_argv;

bool restartp;

char *C_stack_base = NULL, *C_stack_limit = NULL;
double max_store_size = 0.0;

#ifndef HAVE_CILK
#ifdef WIN32
HANDLE kara_thread1, kara_thread2;
#elif defined HAVE_LIBPTHREAD
pthread_t kara_thread1, kara_thread2;
#endif
#endif

static int kparallel = -1;

void cslstart(int argc, const char *argv[], character_writer *wout)
{   int i;
    double store_size = 0.0;
//
// I make "sp" volatile - it is a variable I declare here but then only use by
// taking its address to get a pointer into the current stack-frame. When it
// is volatile my compiler will not be entitles to moan about the lack of
// assignment to it and will not be entitles to optimise it out of existance
// or otherwise do things that run against my intent!
//
    volatile LispObject sp;
#ifdef CONSERVATIVE
    C_stackbase = (LispObject *)&sp;
#endif
    C_stack_base = (char *)&sp;
    C_stack_limit = NULL;
    max_store_size = 0.0;
#if (defined HAVE_LIBPTHREAD || defined WIN32) && !HAVE_CILK
    if (number_of_processors() >= 3)
    {
#ifdef MACINTOSH
        sem_unlink("/sem1a");
        if ((kara_sem1a = sem_open("/sem1a", O_CREAT, 0644, 0)) == SEM_FAILED)
        {   perror("sem_open");
            exit(EXIT_FAILURE);
        }
        sem_unlink("/sem1b");
        if ((kara_sem1b = sem_open("/sem1b", O_CREAT, 0644, 0)) == SEM_FAILED)
        {   perror("sem_open");
            exit(EXIT_FAILURE);
        }
        sem_unlink("/sem1c");
        if ((kara_sem1c = sem_open("/sem1c", O_CREAT, 0644, 0)) == SEM_FAILED)
        {   perror("sem_open");
            exit(EXIT_FAILURE);
        }
        sem_unlink("/sem2a");
        if ((kara_sem2a = sem_open("/sem2a", O_CREAT, 0644, 0)) == SEM_FAILED)
        {   perror("sem_open");
            exit(EXIT_FAILURE);
        }
        sem_unlink("/sem2b");
        if ((kara_sem2b = sem_open("/sem2b", O_CREAT, 0644, 0)) == SEM_FAILED)
        {   perror("sem_open");
            exit(EXIT_FAILURE);
        }
        sem_unlink("/sem2c");
        if ((kara_sem2c = sem_open("/sem2c", O_CREAT, 0644, 0)) == SEM_FAILED)
        {   perror("sem_open");
            exit(EXIT_FAILURE);
        }
#else // MACINTOSH
        sem_init(&kara_sem1a, 0, 0);
        sem_init(&kara_sem1b, 0, 0);
        sem_init(&kara_sem1c, 0, 0);
        sem_init(&kara_sem2a, 0, 0);
        sem_init(&kara_sem2b, 0, 0);
        sem_init(&kara_sem2c, 0, 0);
#endif // MACINTOSH
#ifdef WIN32
        kara_thread1 = CreateThread(NULL, 0, kara_worker1, NULL, 0, NULL);
        kara_thread2 = CreateThread(NULL, 0, kara_worker2, NULL, 0, NULL);
#else
        pthread_create(&kara_thread1, NULL, kara_worker1, NULL);
        pthread_create(&kara_thread2, NULL, kara_worker2, NULL);
#endif
    }
    karatsuba_parallel = 0x7fffffff;
#elif defined HAVE_CILK
    karatsuba_parallel = 0x7fffffff;
#endif // thread support

#ifdef EMBEDDED
// This provides a fixed limit in the embedded build
    C_stack_limit = C_stack_base - 2*1024*1024 + 0x10000;
#else // EMBEDDED
#ifdef WIN32
    {   HMODULE h = GetModuleHandle(NULL); // For current executable
        if (h != NULL)
        {   IMAGE_DOS_HEADER *dh = (IMAGE_DOS_HEADER*)h;
            IMAGE_NT_HEADERS *NTh =
                (IMAGE_NT_HEADERS*)((BYTE*)dh + dh->e_lfanew);
            int64_t stackLimit =
                (int64_t)NTh->OptionalHeader.SizeOfStackReserve;
//
// If the limit recovered above is under 200K I will pretend it is
// just plain wrong and increase it to that. The effect may be that I
// end up with an untidy stack overflow but at least I get closer to
// using all the space that I have.
//
            if (stackLimit < 200*1024) stackLimit = 200*1024;
// I also assume that any figure over 20 Mbytes is a mess so ignore it
            if (stackLimit <= 20*1024*1024)
            {   // I try to give myself 64K spare...
                C_stack_limit = C_stack_base - stackLimit + 0x10000;
#ifdef DEBUG
                fprintf(stderr, "[debug] stack %dK\n", (int)(stackLimit/1024));
#endif
            }
        }
    }
#else // WIN32
#ifdef HAVE_SYS_RESOURCE_H
    {   struct rlimit r;
        if (getrlimit(RLIMIT_STACK, &r) == 0)
        {   int64_t stackLimit = (int64_t)r.rlim_cur;
//
// If the user has used ulimit to remove all stack limits I will
// nevertheless apply one at 20 Mbytes. That is SO much higher than any
// default as to not hurt ordinary people - and if anybody NEEDS gigabytes
// of stack they need to ensure that getrlimit returns a finite indication
// of that! Results of RLIM_SAVED_MAX represent a sort of "give up" from
// getrlimit so I will treat them as failure.
//
#if HAVE_DECL_RLIM_SAVED_MAX
            if (stackLimit == (int64_t)RLIM_SAVED_MAX &&
                RLIM_SAVED_MAX != RLIM_INFINITY)
            {   /* do nothing */
            }
            else
#endif
#if HAVE_DECL_RLIM_SAVED_CUR
                if (stackLimit == (int64_t)RLIM_SAVED_CUR &&
                    RLIM_SAVED_CUR != RLIM_INFINITY)
                {   /* do nothing */
                }
                else
#endif
                    if (stackLimit == (int64_t)RLIM_INFINITY)
                        stackLimit = 20*1024*1024;
// I view values under 200K as silly and ignore them!
            if (stackLimit >= 200*1024)
            {   C_stack_limit = C_stack_base - stackLimit + 0x10000;
#ifdef DEBUG
                fprintf(stderr, "[debug] stack %dK\n", (int)(stackLimit/1024));
#endif
            }
        }
    }
#endif // HAVE_SYS_RESOURCE_H
#endif // WIN32
// If I can not read a value then I will set a limit at 4 Mbytes...
    if (C_stack_limit == NULL)
    {   C_stack_limit = C_stack_base - 4*1024*1024 + 0x10000;
#ifdef DEBUG
        fprintf(stderr, "[debug] stack defaulting to 4Mb\n");
#endif
    }
#endif // EMBEDDED

#ifdef EMBEDDED
    fwin_set_lookup(look_in_lisp_variable);
#endif
    errorset_min = 0;
    errorset_max = 3;
    stack_segsize = 1;
    module_enquiry = NULL;
    countdown = 0x7fffffff;
// put resource limiting info in a tidy or at least safe state
    time_base  = space_base  = io_base  = errors_base  = 0;
    time_now   = space_now   = io_now   = errors_now   = 0;
    time_limit = space_limit = io_limit = errors_limit = -1;
//
// Note that I will set up clock_stack AGAIN later on! The one further down
// happens after command line options have been decoded and is where I really
// want to consider Lisp to be starting. The setting here is because
// if I call ensure_screen() it can push and pop the clock stack, and
// especially if I have an error in my options I may print to the terminal
// and then flush it. Thus I need SOMETHING set up early to prevent any
// possible frivolous disasters in that area.
//
    base_time = read_clock();
    consolidated_time[0] = gc_time = 0.0;
    clock_stack = &consolidated_time[0];
#if defined WINDOW_SYSTEM && !defined EMBEDDED
    use_wimp = true;
#endif
#ifdef HAVE_FWIN
//
// On fwin the "-w" flag should disable all attempts at use of the wimp.
//
    for (i=1; i<argc; i++)
    {   const char *opt = argv[i];
        if (opt == NULL) continue;
        else if (strcmp(argv[i], "--args")==0) break;
#if defined WINDOW_SYSTEM && !defined EMBEDDED
        if (opt[0] == '-' && (char)tolower((unsigned char)opt[1]) == 'w')
        {   use_wimp = !use_wimp;
            break;
        }
#endif
    }
    fwin_pause_at_end = 1;
#endif
#ifdef SOCKETS
#if 0
    sockets_ready = 0;
    socket_server = 0;
#endif
#endif
//
// Now that the window manager is active I can send output through
// xx_printf() and get it on the screen neatly.
//
    procedural_input = NULL;
    procedural_output = wout;
    standard_directory = find_image_directory(argc, argv);
    restartp = true;
    ignore_restart_fn = false;
    spool_file = NULL;
    spool_file_name[0] = 0;
    output_directory = 0x80000000;
    number_of_input_files = 0;
    number_of_symbols_to_define = 0;
    number_of_fasl_paths = 0;
    fasl_output_file = false;
    initial_random_seed = seed2 = 0;
    init_flags = INIT_EXPANDABLE;
    return_code = EXIT_SUCCESS;
    segvtrap = true;
    batch_flag = false;
    load_count = 0;
    load_limit = 0x7fffffff;

    CSL_MD5_Init();
    CSL_MD5_Update((unsigned char *)"Initial State", 13);
#ifdef MEMORY_TRACE
    car_counter = 0x7fffffff;
    car_low = 0;
    car_high = 0xffffffff;
#endif
// I save the args so that setup can make a lisp variable out of them
    csl_argc = argc;
    csl_argv = argv;
    argc--;
    for (i=1; i<=argc; i++)
    {   const char *opt = argv[i];
//
// The next line ought never to be activated, but I have sometimes seen
// unwanted NULL args on the end of command lines so I filter them out
// here as a matter of security.
//
        if (opt == NULL || *opt == 0) continue;
//
// The keyword "--args" terminates CSL's scanning of the arguments so any
// material beyond there is merely for use by the application code.
//
        else if (strcmp(opt, "--args")==0) break;
//
// Note that I do not treat an isolated "-" as introducing an "option".
// Instead it is treated as a file-name and it indicates the "standard"
// input. There may be amusing consequences for using this several times
// in one call, but I hope it will make sense in several sane cases.
//
        if (opt[0] == '-' && opt[1] != 0)
        {   const char *w;
            int c1 = opt[1], c2 = opt[2];
            if (isupper((unsigned char)c1))
                c1 = (char)tolower((unsigned char)c1);
            switch (c1)
            {

//
// -- <outfile> arranges that output is sent to the indicated file. It is
// intended to behave a little like "> outfile" as command-line output
// redirection, but is for use in windowed environments (in particular
// Windows NT) where this would not work.  I had intended to use "->" here,
// but then the ">" tends to get spotted as a command-line request for
// redirection, and I would not be using this if command-line redirection
// worked properly! Actually use of "--" here was a BAD choice since it
// clashes with the tradition now common elsewhere that fully spelt-out
// options can be written as "--option". To start to mend that I will
// now make
//                 -- filename
// redirect the standard output, but detect
//                 --option
// as an extended option. This is, I guesss, an incompatible change to CSL's
// behaviour but I rather believe it will be a good one to make and I can
// issue a message about unrecognised options that will help anybody caught
// by it.
//
/*! options [--] \item [{\ttfamily --}] \index{{\ttfamily --}}
 * If the application is run in console mode then its standard output could
 * be redirected to a file using shell facilities. But the {\ttfamily --}
 * directive (followed by a file name) redirects output within the Lisp rather
 * than outside it. If this is done a very limited capability for sending
 * progress or status reports to stderr (or the title-bar when running in windowed
 * mode) remains via the {\ttfamily report!-right} function.
 *
 * The {\ttfamily -w} option may frequently make sense in such cases, but if that
 * is not used and the system tries to run in a window it will create it
 * starting off minimised.
 */
                case '-':
                    if (c2 != 0)
                    {   w = &opt[2];
/*! options [--cygwin] \item [{\ttfamily --cygwin}] \index{{\ttfamily --cygwin}}
 * On Windows this flag is used to specify that a cygwin rather that a native
 * windows version of Reduce is needed. This can be the situation in some
 * cases where the foreign function interface is to be used.
 */
                        if (strcmp(w, "cygwin") == 0)
                        { }
/*! options [--texmacs] \item [{\ttfamily --texmacs}] \index{{\ttfamily --texmacs}}
 * If CSL/Reduce is launched from texmacs this command-line flag should be
 * used to arrange that the {\ttfamily texmacs} flag is set in
 * {\ttfamily lispsystem!*}, and the code may then do special things.
 */
                        else if (strcmp(w, "texmacs") == 0)
                        { }
/*! options [--no-rcfile] \item [{\ttfamily --no-rcfile}] \index{{\ttfamily --no-rcfile}}
 * Instruct the system not to read a user-specific configuation file, which
 * make have such a names as ``{\ttfamily .reducerc}'', at startup time. This
 * can be useful during system building where utterly self-contained and
 * predictable behaviour is important.
 */
                        if (strcmp(w, "no-rcfile") == 0)
                        {   if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                                symbols_to_define[number_of_symbols_to_define] =
                                    "no_init_file",
                                undefine_this_one[number_of_symbols_to_define++] = false;
                            else
                            {   fwin_restore();
                                term_printf("Too many requests: \"--no-rcfile\" ignored\n");
                            }
                        }
/*! options [--gui] \item [{\ttfamily --gui}] \index{{\ttfamily --gui}}
 * Encourage the system to run in its own window. Similar behaviour
 * to {\ttfamily -w+}.
 */
                        else if (strcmp(w, "gui") == 0)
                        { }
/*! options [--nogui] \item [{\ttfamily --nogui}] \index{{\ttfamily --nogui}}
 * Encourage the system to run as a console-style application. Similar
 * to {\ttfamily -w-} or just simply {\ttfamily -w}.
 */
                        else if (strcmp(w, "nogui") == 0)
                        { }
/*! options [--guimin] \item [{\ttfamily --guimin}] \index{{\ttfamily --guimin}}
 * Encourage the system to run as in its own window, but
 * start that window off minimised. Similar
 * to {\ttfamily -w.}.
 */
                        else if (strcmp(w, "guimin") == 0)
                        { }
/*! options [--help] \item [{\ttfamily --help}] \index{{\ttfamily --help}}
 * It is probably obvious what this option does! Note that on Windows the
 * application was linked as a windows binary so it carefully creates a
 * console to display the help text in, and organizes a delay to give
 * people a chance to read it.
 */
                        else if (strcmp(w, "help") == 0)
                        {
//
// A comments here as a horrible warning. For dubious reasons term_printf
// can ONLY cope when the output it generates is at most 256 bytes long.
// Beyond that there can be an internal buffer overflow. Hence each line
// of text here is printed as a separate call. If I was certain that
// a vsnprintf function was ALWAYS available the internal behaviour could
// at least be a bit safer...
//
                            term_printf(
                                "Options:\n");
                            term_printf(
                                "-a   do not use. Flips meaning of the Lisp \"batchp\" function.\n");
                            term_printf(
                                "-b   do not colour prompts. -bOIP sets colours for output,\n");
                            term_printf(
                                "                            input and prompt, using rgbcmyk\n");
                            term_printf(
                                "                            for Red, Green, Blue, Cyan etc.\n");
                            term_printf(
                                "-c   display something that is not a Copyright statement (because of LGPL).\n");
                            term_printf(
                                "-d VVV or  -d VVV=VVV define a Lisp symbol as the system start\n");
                            term_printf(
                                "-e   enable some feature that is at present an experiment. Not for users!\n");
                            term_printf(
                                "-f or -f nnn  listen on socket 1206 or nnn to run a remote session.\n");
                            term_printf(
                                "              This option is not for normal users.\n");
                            term_printf(
                                "-g   enable some options that help when debugging. You get backtraces.\n");
                            term_printf(
                                "-h   on X windows this may use x-terminal fonts rather than ones\n");
                            term_printf(
                                "     used via Xft that live with the application. Not recommended.\n");
                            term_printf(
                                "-i <image file> specific the location of the initial image file explicitly\n");
                            term_printf(
                                "                You may have multiple image files, seached for modules in\n");
                            term_printf(
                                "                the order listed.\n");
                            term_printf(
                                "-j   used for depencency tracking. '-j fileuse.dat' notes what files\n");
                            term_printf(
                                "     are accessed during this run in the indicated place.\n");
                            term_printf(
                                "-k nnnK or -knnnM or -knnnG suggest heap-size to use. Often not needed\n");
                            term_printf(
                                "-l logfile   keep transcript of session for you.\n");
                            term_printf(
                                "-m   a memory trace option not for ordinary use.\n");
                            term_printf(
                                "-n   ignore the restart function in an image file so that the system.\n");
                            term_printf(
                                "     starts up in raw Lisp. Sometimes useful if image file is broken.\n");
                            term_printf(
                                "-o <image file> specified where newly created compiled  modules and\n");
                            term_printf(
                                "     saved heap images should go. Default is in the standard image.\n");
                            term_printf(
                                "-p   reserved for a potential profile option.\n");
                            term_printf(
                                "-q   tend to be Quiet. see also -v.\n");
                            term_printf(
                                "-r nnn or -r nnn,mmm sets initial random seed. Passing 0 means use\n");
                            term_printf(
                                "     current time of day and similar nonrepeatable stuff. May be\n");
                            term_printf(
                                "     used to force repeatability of code that uses randomness.\n");
                            term_printf(
                                "-s   causes compiler to display \"assembly code\".\n");
                            term_printf(
                                "-t modulename  prints the timestamp of the given module and exits.\n");
                            term_printf(
                                "-u VVV undefines the Lisp symbol VVV at the start of the run.\n");
                            term_printf(
                                "-v   runs in a slighly more verbose mode.\n");
                            term_printf(
                                "-w   controls if code runs in a window or in console. Also -w+ and -w-\n");
                            term_printf(
                                "     can override cases where the system really wants to go one way.\n");
                            term_printf(
                                "     Prefered usage is --gui, --nogui or --guimin rather than the\n");
                            term_printf(
                                "     short-form versions.\n");
                            term_printf(
                                "-x   avoid trapping exceptions so you can use a low-level debugger\n");
                            term_printf(
                                "     to sort out errors in the kernel.\n");
                            term_printf(
                                "-y   At one stage this enabled Japanese character support. Not now\n");
                            term_printf(
                                "     maintained.\n");
                            term_printf(
                                "-z   when the code starts up it is just a basic raw Lisp core without\n");
                            term_printf(
                                "     even a compiler. Used to bootstrap the system.\n");
                            term_printf(
                                "-- filename  redirect output to the given file so it does not appear\n");
                            term_printf(
                                "     on the screen.\n");
                            term_printf(
                                "--cygwin [on Windows] try to use the cygwin version of Reduce rather\n");
                            term_printf(
                                "     than a native Windows version, regardless of other circumstances.\n");
                            term_printf(
                                "--texmacs run in texmacs mode. You must use the plugin from the\n");
                            term_printf(
                                "     cslbase/texmacs-plugin directory.\n");
                            term_printf(
                                "--<other> reserved for additional extended options.\n");
                            term_printf(
                                "--version display some version information then exit.\n");
                            term_printf(
                                "--help this output!\n");
#ifdef WX
//
// NOTE that the LaTeX Project Public License requires that every
// component of a derived work contain priminent notices logging
// changes of LPPL material and that it also provides information
// sufficient to obtain complete, unmodified versions of the original.
// Having text that can be displated via the "--help" command-line option
// will (I hope) satisfy these requirements for binary versions of this
// code. Those who read the source can find this comment as well, which
// notes that csl/support-packages contains original archives of
// font-related files that I have used, and that csl/cslbase/wxfonts
// contains both fonts and documentation explaining what might have
// changed. And in case anybody receives this file separate from
// other parts of the code, I will note that all these files can be
// downloaded from reduce-algebra.sf.net.
//
                            term_printf(
                                "This software contains code that is subject to the LaTeX Project\n");
                            term_printf(
                                "Public License. In accordance with Clause 6 of that (which governs\n");
                            term_printf(
                                "distribution, there are README in a directory called wxfonts or\n");
                            term_printf(
                                "reduce.wxfonts present as part of this distribution that explain\n");
                            term_printf(
                                "both changes that have been made and where to obtain copies of\n");
                            term_printf(
                                "relevant complete, unmodified original font-related material.\n");
#endif
                            my_exit(0);
                        }
/*! options [--version] \item [{\ttfamily --version}] \index{{\ttfamily --version}}
 * It is probably obvious what this option does! But note that there is an
 * issue here about whether one is looking at the CSL version identification or
 * one for the Lisp application from an image file (eg often Reduce).
 */
                        else if (strcmp(w, "version") == 0)
                        {   term_printf(
#ifndef COMMON
                        "Codemist Standard Lisp %s revision %d for %s: %s\n",
#else
                        "Codemist Common Lisp %s revision %d for %s: %s\n",
#endif
                                VERSION, REVISION, IMPNAME, __DATE__);
                            my_exit(0);
                        }
                        else if (strcmp(w, "maxmem") == 0)
                        {   if (i != argc) w = argv[++i];
                            else break; // Illegal at end of command-line
                            {   char buffer[16];
                                int i = 0;
                                while ((*w != '/') &&
                                       (*w != 'k') && (*w != 'K') &&
                                       (*w != 'm') && (*w != 'M') &&
                                       (*w != 'g') && (*w != 'G') &&
                                       (*w != 0) &&
                                       (i<(int)sizeof(buffer)-1))
                                    buffer[i++] = *w++;
                                buffer[i] = 0;
                                max_store_size = atof(buffer);
                                switch (*w)
                                {   case 'k': case 'K':
                                        break;
                                    case 'g': case 'G':
                                        max_store_size *= 1024.0*1024.0;
                                        break;
                                    default:   // megabytes by default
                                        max_store_size *= 1024.0;
                                        break;
                                }
#if PAGE_BITS==18
                                if (max_store_size < 10000.0) max_store_size = 10000.0;
#else
                                if (max_store_size < 32000.0) store_size = 32000.0;
#endif
                                if ((!SIXTY_FOUR_BIT &&
                                     (max_store_size > 2.0*1024.0*1024.0)) ||
                                    (max_store_size > 500.0*1024.0*1024.0))
                                {   fwin_restore();
                                    term_printf(
                                        "Memory specifier \"--maxmem %s%s\" is too large (= %.4g)\n",
                                        buffer, w, max_store_size/1024.0);
                                    term_printf("Please specify as -KnnnK, -KnnnM or -KnnnG\n");
                                    term_printf("for Kilobytes, Megabytes or Gigabytes\n");
                                }
                            }
                        }
//
// I do not really want this options heavily documented, since it is intended
// for use by those maintaining CSL not for the general public. By default
// log multiplication can use a threaded implementation (to exploit multi-core
// machines). This happens when numbers get bigger than about
// 2^(31*KARATSUBA_PARALLEL_CUTOFF). This option allows one to override the
// default threshold so that performance effects can be measured and the
// cut-off adjusted to suit the machine involved.
//
                        else if (strcmp(w, "kara") == 0)
                        {   if (i != argc) w = argv[++i];
                            else break; // Illegal at end of command-line
                            kparallel = atoi(w);
                            if (kparallel < KARATSUBA_CUTOFF)
                                kparallel = KARATSUBA_CUTOFF;
                        }
                        else
                        {   fwin_restore();
                            term_printf("Unknown extended option \"--%s\"\n", w);
                            term_printf("NB: use \"-- filename\" (with whitespace)\n");
                            term_printf("    for output redirection now.\n");
                        }
                        continue;
                    }
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    {   char filename[LONGEST_LEGAL_FILENAME];
                        FILE *f;
                        memset(filename, 0, sizeof(filename));
#ifdef WINDOW_SYSTEM
                        f = open_file(filename, w, strlen(w), "w", NULL);
                        if (f == NULL)
                        {
//
// Under FWIN if there is a "--" among the arguments I will start off
// with the main window minimized. Thus if an error is detected at a
// stage that the transcript file is not properly opened I need to
// maximize the window so I can see the error! Note that I will need to
// ensure that fwin only uses "-- file" not "--option" to do this...
//
                            fwin_restore();
                            term_printf("Unable to write to \"%s\"\n", filename);
                            continue;
                        }
                        else
                        {   term_printf("Output redirected to \"%s\"\n",
                                        filename);
                        }
                        if (alternative_stdout != NULL)
                            fclose(alternative_stdout);
                        alternative_stdout = f;
#else
//
// I use freopen() on stdout here to get my output sent elsewhere.  Quite
// what sort of mess I am in if the freopen fails is hard to understand!
// Thus I write a message to stderr and exit promptly in case of trouble.
// I print a message explaining what I am doing BEFORE actually performing
// the redirection.
//
                        fprintf(stderr, "Output to be redirected to \"%s\"\n", w);
                        f = open_file(filename, w, strlen(w), "w", stdout);
                        if (f == NULL)
                        {   fprintf(stderr, "Unable to write to \"%s\"\n",
                                    filename);
#ifdef HAVE_FWIN
                            throw EXIT_FAILURE;
#else
                            exit(EXIT_FAILURE);
#endif
                        }
#endif
                    }
                    continue;

/*! options [--my-path] \item [{\ttfamily --my-path}] \index{{\ttfamily --my-path}}
 * At some time I had felt the need for this option, but I now forget what I
 * expected to use it for! It leads the executable to display the fully
 * rooted name of the directory it was in and then terminate. It may be useful
 * in some script?
 */



/*! options [-a] \item [{\ttfamily -a}] \index{{\ttfamily -a}}
 * {\ttfamily -a} is a curious option, not intended for general or casual use.
 * If given it causes the {\ttfamily (batchp)} function to return the opposite
 * result from normal!  Without ``{attfamily -a}'' {\ttfamily (batchp)} returns
 * {\ttfamily T} either if at least one file was specified on the command line,
 * or if the standard input is ``not a tty'' (under some operating systems this
 * makes sense -- for instance the standard input might not be a ``tty'' if it
 * is provided via file redirection).  Otherwise (ie primary input is directly
 * from a keyboard) {\ttfamily (batchp)} returns {\ttfamily nil}.  Sometimes
 * this judgement about how ``batch'' the current run is will be wrong or
 * unhelpful, so {\ttfamily -a} allows the user to coax the system into better
 * behaviour.  I hope that this is never used!
 */
                case 'a':
                    batch_flag = true;
                    continue;
/*! options [-b] \item [{\ttfamily -b}] \index{{\ttfamily -b}}
 * {\ttfamily -b} tells the system to avoid any attempt to recolour prompts
 * and input text. It will mainly be needed on X terminals that have been
 * set up so that they use colours that make the defaults here unhelpful.
 * Specifically white-on-black and so on.
 * {\ttfamily -b} can be followed by colour specifications to make things yet
 * more specific. It is supposed to be the idea that three colours can be
 * specified after it for output, input and prompts, with the letters KRGYbMCW
 * standing for blacK, Red, Green, Yellow, blue, Magenta, Cyan and White.
 * This may not fully work yet!
 */


                case 'b':
//
// Actually "-b" is detected and processed by fwin (if present) before
// this bit of the code is invoked (much as "-w" is). Thus I do not have
// to do anything here!
//
                    continue;

/*! options [-c] \item [{\ttfamily -c}] \index{{\ttfamily -c}}
 * Displays a notice relating to the authorship of CSL. Note that this
 * is an authorship statement not a Copyright notice, because if any
 * (L)GPL code is involved that would place requirements on what was
 * displayed in a Copyright Notice.
 */

                case 'c':
                    fwin_restore();
                    term_printf("\nCSL was coded by Codemist    , 1988-2012\n");
                    term_printf("Distributed under the Modified BSD License\n");
                    term_printf("See also --help\n");
                    continue;

/*! options [-d] \item [{\ttfamily -d}] \index{{\ttfamily -d}}
 * A command line entry {\ttfamily -Dname=value} or {\ttfamily -D name=value}
 * sets the value of the named lisp variable to the value (as a string).
 * Note that the value set is a {\em string} so if you wish to retrieve
 * it and use it as a symbold or number within your code you will have to
 * perform some conversion.
 */

                case 'd':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                        symbols_to_define[number_of_symbols_to_define] = w,
                        undefine_this_one[number_of_symbols_to_define++] = false;
                    else
                    {   fwin_restore();
                        term_printf("Too many \"-D\" requests: ignored\n");
                    }
                    continue;

/*! options [-e] \item [{\ttfamily -e}] \index{{\ttfamily -e}}
 * A ``spare'' option used from time to time to activate experiments within
 * CSL.
 */

                case 'e':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break;
                    if (sscanf(w, "%d", &load_limit) != 1)
                        load_limit = 0x7fffffff;
                    continue;

#if 0

/*! options [-f] \item [{\ttfamily -f}] \index{{\ttfamily -f}}
 * At one stage CSL could run as a socket server, and {\ttfamily -f portnumber}
 * activated that mode. {\ttfamily -f-} used a default port, 1206 (a number
 * inspired by an account number on Titan that I used in the 1960s). The code
 * that supports this may be a useful foundation to others who want to make a
 * network service out of this code-base, but is currently disabled.
 */



#ifdef SOCKETS
                case 'f':
//
//                     -F
// This is used with syntax -Fnnn or -F nnn (with nnn a number above
// 1000 but less than 65536) to cause the system to run not as a normal
// interactive application but as a server listening on the indicated port.
// The case -F- (which could of course be "-F -") indicates use of the
// default port for CSL, which I hereby declare to be 1206. This number may
// need to be changed later if I find it conflicts with some other common
// package or usage, but was selected in memory of the project number
// at one time allocated to the Archimedeans Computing Group.
// On some systems if I want to set up a server that can serve multiple
// clients I may need to re-invoke CSL afresh for each new client, and in
// such cases the internally generated tasks can be passed information
// from their parent task using -F followed by non-numeric information.
// Any user who attempts such usage will get "what they deserve".
//
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    port_number = default_csl_server_port;
                    remote_store = REMOTE_STORE;
                    max_users = MAX_USERS;
                    if (strcmp(w, "-") == 0)
                        port_number = default_csl_server_port;
                    else if (sscanf(w, "%d:%d:%d",
                                    &port_number, &max_users, &remote_store) < 1 ||
                             port_number <= 1000 ||
                             port_number >= 65536 ||
                             max_users < 2 || max_users > 50 ||
                             remote_store < 4000 || remote_store > 20000)
                    {   fwin_restore();
                        term_printf("\"%s\" is valid (want port:users:store\n", w);
                        continue;
                    }
                    store_size = (double)remote_store;
                    init_flags &= ~INIT_EXPANDABLE;
                    current_users = 0;
//
// The code here is probably a bit painfully system-specific, and so one
// could argue that it should go in a separate file. However a LOT of the
// socket interface is the same regardless of the host, or a few simple
// macros can have made it so. So if SOCKETS has been defined I will
// suppose I can continue here on that basis. I do quite want to put the
// basic socket code in csl.c since it is concerned with system startup and
// the selection of sources and sinks for IO.
//
                    if (ensure_sockets_ready() == 0)
                    {   SOCKET sock1, sock2;
                        struct sockaddr_in server_address, client_address;
#ifdef HAVE_SOCKLEN_T
                        socklen_t sin_size;
#else
                        int sin_size;
#endif
                        sock1 = socket(AF_INET, SOCK_STREAM, 0);
                        if (sock1 == SOCKET_ERROR)
                        {   fwin_restore();
                            term_printf("Unable to create a socket\n");
                            continue;
                        }
                        server_address.sin_family = AF_INET;
                        server_address.sin_port = htons(port_number);
                        server_address.sin_addr.s_addr = INADDR_ANY;
                        memset((char *)&(server_address.sin_zero), 0, 8);
                        if (bind(sock1, (struct sockaddr *)&server_address,
                                 sizeof(struct sockaddr)) == SOCKET_ERROR)
                        {   fwin_restore();
                            term_printf("Unable to bind socket to port %d\n",
                                        port_number);
                            closesocket(sock1);
                            continue;
                        }
                        if (listen(sock1, PERMITTED_BACKLOG) == SOCKET_ERROR)
                        {   fwin_restore();
                            term_printf("Failure in listen() on port %d\n",
                                        port_number);
                            closesocket(sock1);
                            continue;
                        }
                        for (;;)
                        {   struct hostent *h;
                            time_t t0;
                            sin_size = sizeof(struct sockaddr_in);
                            sock2 = accept(sock1,
                                           (struct sockaddr *)&client_address,
                                           &sin_size);
                            if (sock2 == SOCKET_ERROR)
                            {   fwin_restore();
                                term_printf("Trouble with accept()\n");
                                continue;  // NB local continue here
                            }
                            t0 = time(NULL);
                            term_printf("%.24s from %s",
                                        ctime(&t0),
                                        inet_ntoa(client_address.sin_addr));
                            h = gethostbyaddr((char *)&client_address.sin_addr,
                                              sizeof(client_address.sin_addr), AF_INET);
                            if (h != NULL)
                                term_printf(" = %s", h->h_name);
                            else term_printf(" [unknown host]");
//
// Here I have a bit of a mess. Under Unix I can do a fork() so that the
// requests that are coming in are handled by a separate process. The
// code is pretty easy. However with Windows I can only create a fresh process
// by re-launching CSL from the file it was originally fetched from. I
// will try to do that in a while, but for now I will leave the
// Windows version of this code only able to handle a single client
// session.
//
#ifdef WIN32
                            closesocket(sock1);
                            socket_server = sock2;
                            cpu_timeout = clock() + CLOCKS_PER_SEC*MAX_CPU_TIME;
                            elapsed_timeout = time(NULL) + 60*MAX_ELAPSED_TIME;
                            procedural_output = char_to_socket;
                            term_printf("Welcome to the Codemist server\n");
                            ensure_screen();
                            break;
#else // WIN32
                            while (waitpid(-1, NULL, WNOHANG) > 0) current_users--;
                            if (current_users >= max_users)
                            {   term_printf(" refused\n");
                                socket_server = sock2;
                                ensure_screen();
                                procedural_output = char_to_socket;
                                term_printf(
                                    "\nSorry, there are already %d people using this service\n",
                                    current_users);
                                term_printf("Please try again later.\n");
                                ensure_screen();
                                procedural_output = NULL;
                                closesocket(socket_server);
                                socket_server = 0;
                                continue;
                            }
                            else term_printf(" %d of %d\n",
                                                 ++current_users, max_users);
                            ensure_screen();
                            if (!fork())
                            {   // Child process here
                                closesocket(sock1);
                                fcntl(sock2, F_SETFL, O_NONBLOCK);
                                socket_server = sock2;
                                cpu_timeout = clock() + CLOCKS_PER_SEC*MAX_CPU_TIME;
                                elapsed_timeout = time(NULL) + 60*MAX_ELAPSED_TIME;
                                ensure_screen();
                                procedural_output = char_to_socket;
                                term_printf("Welcome, you are user %d of %d\n",
                                            current_users, max_users);
                                term_printf(
                                    "You have been allocated %d seconds CPU time"
                                    " and %d minutes elapsed time\n",
                                    MAX_CPU_TIME, MAX_ELAPSED_TIME);
                                break;
                            }
                            else
                            {   closesocket(sock2);
                                if (current_users < 0) current_users = 0;
                                continue;
//
// This loops serving as many clients as happen to come along. Having said
// "csl -fnnn" it will be necessary (in due course) to kill the daemon
// by interrupting it with a ^C or some such. When the master process is
// terminated in that way any clients that remain active may continue to
// hang around until they have finished in the usual way.
//
                            }
#endif // WIN32
                        }
                    }
//
// The "continue" here gets executed when I have been contacted by some
// client and have an active socket open. It parses the rest of the
// command line and then completes the process of getting CSL running.
//
                    continue;
#endif // SOCKETS
#endif // 0

/*! options [-g] \item [{\ttfamily -g}] \index{{\ttfamily -g}}
 * In line with the implication of this option for C compilers, this enables
 * a debugging mode. It sets a lisp variable {\ttfamily !*backtrace} and
 * arranges that all backtraces are displayed notwithstanding use of
 * {\ttfamily errorset}.
 */

                case 'g':
                    if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                        symbols_to_define[number_of_symbols_to_define] =
                            "*backtrace",
                        undefine_this_one[number_of_symbols_to_define++] = false;
                    else
                    {   fwin_restore();
                        term_printf("Too many requests: \"-G\" ignored\n");
                    }
                    errorset_min = 3;
                    errorset_max = 3;
                    continue;

/*! options [-h] \item [{\ttfamily -h}] \index{{\ttfamily -h}}
 * This option is a left-over. When the X-windows version of the code first
 * started to use Xft it viewed that as optional and could allow a build even when
 * it was not available. And then even if Xft was detected and liable to be used
 * by default it provided this option to disable its use. The remnants of the
 * switch that disabled use of Xft (relating to fonts living on the Host or
 * the Server) used this switch, but it now has no effect.
 */

                case 'h':
#ifndef HAVE_LIBWX
//
// If I am using wxWidgets this option is not supported.
//
                    fwin_use_xft = 0;
#endif
//
// Actually, like the "-w" option, it is TOO LATE to do this here because
// lower-level parts of fwin may already have adjusted font paths using
// mechanisms based on whether Xft is to be activated or not. So fwin
// checks for "-h" and "-H" and interprets what it finds. So what I do here
// is just a redundant reminder. Ugh.
//
                    continue;

/*! options [-i] \item [{\ttfamily -i}] \index{{\ttfamily -i}}
 * CSL and Reduce use image files to keep both initial heap images and
 * ``fasl'' loadable modules. By default if the executable launched has some name,
 * say xxx, then an image file xxx.img is used. But to support greater
 * generality {\ttfamily -i} introduces a new image, {\ttfamily -i-} indicates
 * the default one and a sequence of such directives list image files that are
 * searched in the order given. These are read-only. The similar option
 * {\ttfamily -o} equally introduces image files that are scanned for input, but
 * that can also be used for output. Normally there would only be one
 * {\ttfamily -o} directive.
 */

                case 'i':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    if (w[0] == '-' && w[1] == 0) w = standard_directory;
                    if (number_of_fasl_paths < MAX_FASL_PATHS-1)
                        fasl_paths[number_of_fasl_paths++] = w;
                    else
                    {   fwin_restore();
                        term_printf("Too many \"-I/-O\" requests: ignored\n");
                    }
                    continue;

/*! options [-j] \item [{\ttfamily -j}] \index{{\ttfamily -j}}
 * Follow this directive with a file-name, and a record of all the files read
 * during the Lisp run will be dumped there with a view that it can be included
 * in a Makefile to document dependencies.
 */

                case 'j':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    dependency_file = w;
                    continue;

/*! options [-k] \item [{\ttfamily -k}] \index{{\ttfamily -k}}
 * {\ttfamily -K nnn} sets the size of heap to be used.  If it is given then that much
 * memory will be allocated and the heap will never expand.  Without this
 * option a default amount is used, and (on many machines) it will grow
 * if space seems tight.
 *
 * The extended version of this option is {\ttfamily -K nnn/ss} and then ss is the
 * number of ``CSL pages'' to be allocated to the Lisp stack. The default
 * value (which is 1) should suffice for almost all users, and it should
 * be noted that the C stack is separate from and independent of this one and
 * it too could overflow.
 *
 * A suffix K, M or G on the number indicates units of kilobytes, megabytes or
 * gigabytes, with megabytes being the default. So {\ttfamily -K200M} might
 * represent typical usage for common-sized computations. In general CSL
 * will automatically expand its heap, and so it should normally never be
 * necessary to use this option.
 */

                case 'k':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    {   char buffer[16];
                        int i = 0;
                        while ((*w != '/') &&
                               (*w != 'k') && (*w != 'K') &&
                               (*w != 'm') && (*w != 'M') &&
                               (*w != 'g') && (*w != 'G') &&
                               (*w != 0) &&
                               (i<(int)sizeof(buffer)-1))
                            buffer[i++] = *w++;
                        buffer[i] = 0;
//
// store size gets set here: 0.0 is left if either that is specified
// explictly or if no -K option is given. That will be treated as
// indicating "use default, and expand memory as you go"
//
                        store_size = atof(buffer);
                        if (store_size == 0.0) init_flags |= INIT_EXPANDABLE;
                        else
                        {   init_flags &= ~INIT_EXPANDABLE;
//
// If an explicit store size has been indicated I will see if it had one
// of the letters K, M or G after it (note that I allow it to be a floating
// point value.
//
                            switch (*w)
                            {   case 'k': case 'K':
                                    break;
                                case 'g': case 'G':
                                    store_size *= 1024.0*1024.0;
                                    break;
                                default:   // megabytes by default
                                    store_size *= 1024.0;
                                    break;
                            }
//
// Now the measure is adjusted so it is in units of kilobytes. I will
// set a lower limit to how much can be asked for to try to prevent
// utter congestion. I will also set an upper limit to provide some minor
// protection.
//
#if PAGE_BITS==18
                            if (store_size < 10000.0) store_size = 10000.0;
#else
                            if (store_size < 32000.0) store_size = 32000.0;
#endif
//
// At present I limit even 64-bit systems to 500 Gbytes. I do not guarantee
// that things will behave sensibly if you approach that ...
// ... and 32-bit systems to 2.0 Gbytes because I need to have all my
// addresses having the same sign bit, so 2G is an ABSOLUTE limit to my heap
// size on a 32-bit machine.
//
                            if ((!SIXTY_FOUR_BIT &&
                                 (store_size > 2.0*1024.0*1024.0)) ||
                                (store_size > 500.0*1024.0*1024.0))
                            {   fwin_restore();
                                term_printf(
                                    "Memory specifier \"-K%s%s\" is too large (= %.4g)\n",
                                    buffer, w, store_size/1024.0);
                                term_printf("Please specify as -KnnnK, -KnnnM or -KnnnG\n");
                                term_printf("for Kilobytes, Megabytes or Gigabytes\n");
                            }
                        }
                        while (*w!=0 && *w!='/') w++;
                        if (*w == '/')
                        {   stack_segsize = atoi(w+1);
                            if (stack_segsize < 1 || stack_segsize > 10)
                                stack_segsize = 1;
                        }
                    }
                    continue;

/*! options [-l] \item [{\ttfamily -l}] \index{{\ttfamily -l}}
 * This is to send a copy of the standard output to a named log file. It is
 * very much as if the Lisp function {\ttfamily (spool ``logfile'')} had been
 * invoked at the start of the run.
 */

                case 'l':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    {   char filename[LONGEST_LEGAL_FILENAME];
                        memset(filename, 0, sizeof(filename));
                        spool_file = open_file(filename, w,
                                               strlen(w), "w", NULL);
                        if (spool_file == NULL)
                        {   fwin_restore();
                            term_printf("Unable to write to \"%s\"\n", filename);
                        }
                        else
                        {   time_t t0 = time(NULL);
                            strncpy(spool_file_name, filename, 32);
                            spool_file_name[31] = 0;
#ifdef COMMON
                            fprintf(spool_file,
                                    "Starts dribbling to %s (%.24s).\n",
                                    spool_file_name, ctime(&t0));
#else
                            fprintf(spool_file,
                                    "+++ Transcript to %s started at %.24s +++\n",
                                    spool_file_name, ctime(&t0));
#endif
                        }
                    }
                    continue;

#ifdef MEMORY_TRACE
//
// If MEMORY_TRACE is set up then I can cause an exception by providing
// an option -M n:l:h
// This interrupts after n memory records when a reference in the (inclusive)
// range l..h is next made.
//
/*! options [-m] \item [{\ttfamily -m}] \index{{\ttfamily -m}}
 * Memory trace mode. An option that represents an experiment from the past,
 * and no longer reliably in use. It make it possible to force an
 * exception at stages whene reference to a specified part of memory was made
 * and that could be useful for some low level debugging. It is not supported
 * at present.
 */

                case 'm':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    switch(sscanf(w, "%ld:%lu:%lu",
                                  &car_counter, &car_low, &car_high))
                    {   case 0: car_counter = 0x7fffffff;
                        case 1: car_low = 0;
                        case 2: car_high = 0xffffffff;
                        default:break;
                    }
                    continue;
#endif


/*! options [-n] \item [{\ttfamily -n}] \index{{\ttfamily -n}}
 * Normally when the system is started it will run a ``restart function'' as
 * indicated in its heap image. There can be cases where a heap image has been
 * created in a bad way such that the saved restart function always fails
 * abruptly, and hence working out what was wrong becomes hard. In such cases
 * it may be useful to give the {\ttfamily -n} option that forces CSL to
 * ignore any startup function and merely always begin in a minimal Lisp-style
 * read-eval-print loop. This is intended for experts to do disaster recovery
 * and diagnosis of damaged image files.
 */

                case 'n':               // Ignore restart function (-N)
                    ignore_restart_fn = true;
                    continue;

/*! options [-o] \item [{\ttfamily -o}] \index{{\ttfamily -o}}
 * See {\ttfamily -i}. This specifies an image file used for output via
 * {\ttfamily faslout} and {\ttfamily reserve}.
 */

                case 'o':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    if (w[0] == '-' && w[1] == 0) w = standard_directory;
                    if (number_of_fasl_paths < MAX_FASL_PATHS-1)
                    {   output_directory = number_of_fasl_paths;
                        fasl_paths[number_of_fasl_paths++] = w;
                    }
                    else
                    {   fwin_restore();
                        term_printf("Too many \"-I/-O\" requests: ignored\n");
                    }
                    continue;

/*! options [-p] \item [{\ttfamily -p}] \index{{\ttfamily -p}}
 * If a suitable profile option gets implemented one day this will activate it,
 * but for now it has no effect.
 */

                case 'p':
//
// Please implement something for your favourite system here... what I would
// like would be a call to monitor() or some such...
//
                    fwin_restore();
                    term_printf("Unimplemented option \"-%c\"\n", c1);
                    continue;

/*! options [-q] \item [{\ttfamily -q}] \index{{\ttfamily -q}}
 * This option sets {\ttfamily !*echo} to {\ttfamily nil} and switches off
 * garbage collector messages to give a slightly quieter run.
 */

                case 'q':
                    if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
//
//                  symbols_to_define[number_of_symbols_to_define] =
//                      "*echo=nil",
//                  undefine_this_one[number_of_symbols_to_define++] = false,
//
                        init_flags &= ~INIT_VERBOSE,
                                      init_flags |= INIT_QUIET;
                    else
                    {   fwin_restore();
                        term_printf("Too many requests: \"-Q\" ignored\n");
                    }
                    continue;

/*! options [-r] \item [{\ttfamily -r}] \index{{\ttfamily -r}}
 * The random-number generator in CSL is normally initialised to a value
 * based on the time of day and is hence not reproducible from run to run.
 * In many cases that behavious is desirable, but for debugging it can be useful
 * to force a seed. The directive {\ttfamily -r nnn,mmm} sets the seed to
 * up to 64 bits taken from the values nnn and mmm. The second value if optional,
 * and specifying {\ttfamily -r0}  explicitly asks for the non-reproducible
 * behaviour (I hope). Note that the main Reduce-level random number source is
 * coded at a higher level and does not get reset this way -- this is the
 * lower level CSL generator.
 */

                case 'r':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    if (sscanf(w, "%ld,%ld", &initial_random_seed, &seed2) != 2)
                    {   initial_random_seed = seed2 = 0;
                        sscanf(w, "%ld", &initial_random_seed);
                    }
                    continue;

/*! options [-s] \item [{\ttfamily -s}] \index{{\ttfamily -s}}
 * Sets the Lisp variable {\ttfamily !*plap} and hence the compiler generates
 * an assembly listing.
 */

                case 's':
                    if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                        symbols_to_define[number_of_symbols_to_define] =
                            "*plap",
                            undefine_this_one[number_of_symbols_to_define++] = false;
                    else
                    {   fwin_restore();
                        term_printf("Too many requests: \"-S\" ignored\n");
                    }
                    continue;
/*! options [-t] \item [{\ttfamily -t}] \index{{\ttfamily -t}}
 * {\ttfamily -t name} reports the time-stamp on the named module, and then
 * exits. This is for use in perl scripts and the like, and is
 * needed because the stamps on modules within an image or
 * library file are not otherwise instantly available.
 *
 * Note that especially on windowed systems it may be necessary to use this
 * with {\ttfamily -- filename} since the information generated here goes to
 * the default output, which in some cases is just the screen.
 */

                case 't':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    module_enquiry = w;
                    continue;

/*! options [-u] \item [{\ttfamily -u}] \index{{\ttfamily -u}}
 * See {\ttfamily -d}, but this forcibly undefines a symbol. There are probably
 * very very few cases where it is useful since I do not have a large
 * number of system-specific predefined names.
 */

                case 'u':
                    if (c2 != 0) w = &opt[2];
                    else if (i != argc) w = argv[++i];
                    else break; // Illegal at end of command-line
                    if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                        symbols_to_define[number_of_symbols_to_define] = w,
                                undefine_this_one[number_of_symbols_to_define++] = true;
                    else
                    {   fwin_restore();
                        term_printf("Too many \"-U\" requests: ignored\n");
                    }
                    continue;
/*! options [-v] \item [{\ttfamily -v}] \index{{\ttfamily -v}}
 * An option to make things mildly more verbose. It displays more of a banner
 * at startup and switches garbage collection messages on.
 */

                case 'v':
                    if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
//
//                  symbols_to_define[number_of_symbols_to_define] =
//                      "*echo",
//                  undefine_this_one[number_of_symbols_to_define++] = false,
//
                        init_flags &= ~INIT_QUIET,
                                      init_flags |= INIT_VERBOSE;
                    else
                    {   fwin_restore();
                        term_printf("Too many requests: \"-V\" ignored\n");
                    }
                    continue;

#ifdef WINDOW_SYSTEM
/*! options [-w] \item [{\ttfamily -w}] \index{{\ttfamily -w}}
 * On a typical system if the system is launched it creates a new window and uses
 * its own windowed intarface in that. If it is run such that at startup the
 * standard input or output are associated with a file or pipe, or under X the
 * variable {\ttfamily DISPLAY} is not set it will try to start up in console
 * mode. The flag {\ttfamily -w} indicates that the system should run in console
 * more regadless, while {\ttfamily -w+} attempts a window even if that seems
 * doomed to failure. When running the system to obey a script it will often make
 * sense to use the {\ttfamily -w} option. Note that on Windows the system is
 * provided as two separate (but almost identical) binaries. For example the
 * file {\ttfamily csl.exe} is linked in windows mode. A result is that if
 * launched from the command line it detaches from its console, and if launched
 * by double-clicking it does not create a console. It is in fact very ugly when
 * double clicking on an application causes an unwanted console window to appear.
 * In contrast {\ttfamily csl.com} is a console mode version of just the same
 * program, so when launched from a command line it can communicate with the
 * console in the ordinary expected manner.
 */

                case 'w':
//
// I need to detect and process this flag especially early, and so by the time
// I get to regular command decoding there is nothing to be done.
// Within fwin the option "-w" says "do NOT try to use a window, ie
// run as a console style application", while "-w+" says "Even if
// all the rest of the schemes that I have indicate that you should
// run in console mode (eg if standard input is from a pipe, which it
// will be when running under some debuggers) try to create and use a
// window.
//
                    continue;
#endif

/*! options [-x] \item [{\ttfamily -x}] \index{{\ttfamily -x}}
 * {\ttfamily -x} is an option intended for use only by system
 * support experts -- it disables trapping if segment violations by
 * errorset and so makes it easier to track down low level disasters --
 * maybe!  This can be valuable when running under a debugger since if the
 * code traps signals in its usual way and tries to recover it can make it a lot
 * harder to find out just what was going wrong.
 */

                case 'x':
                    segvtrap = false;
                    continue;
//
// -Y  currently unused!
//
/*! options [-y] \item [{\ttfamily -y}] \index{{\ttfamily -y}}
 * {\ttfamily -y } is at present unused.
 */

                case 'y':
                    if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                        symbols_to_define[number_of_symbols_to_define] =
                            "*hankaku",
                            undefine_this_one[number_of_symbols_to_define++] = false;
                    else
                        term_printf("Too many requests: \"-Y\" ignored\n");
                    continue;

/*! options [-z] \item [{\ttfamily -z}] \index{{\ttfamily -z}}
 * When bootstrapping it is necessary to start up the system for one initial time
 * without the benefit of any image file at all. The option {\ttfamily -z} makes
 * this happen, so when it is specified the system starts up with a minimal
 * environment and only those capabilities that are present in the CSL
 * kernel. It will normally make sense to start loading some basic Lisp
 * definitions rather rapidly. The files {\ttfamily compat.lsp},
 * {\ttfamily extras.lsp} and {\ttfamily compiler.lsp} have Lisp source for the
 * main things I use, and once they are loaded the Lisp compiler can be used
 * to compile itself.
 */

                case 'z':               // Cold start option -z
                    restartp = false;
                    continue;

                default:
                    fwin_restore();
                    term_printf("Unrecognized option \"-%c\"\n", c1);
                    continue;
            }
//
// I do a "break" out of the switch() block if a key occurs at the end
// of the command line in an invalid manner.
//
            fwin_restore();
            term_printf("Option \"-%c\" needs an argument: ignored\n", c1);
            break;
        }
        else files_to_read[number_of_input_files++] = opt;
    }

    if (number_of_fasl_paths == 0)
    {   const char *p = standard_directory;
        char *p1;
        char cur[LONGEST_LEGAL_FILENAME];
//
// If the user does not specify any image files then the behaviour
// defaults as follows:
//   Suppose that the current executable is xxx/yyy/zzz then the
// system behaves as if the user had written
//    zzz -o zzz.img -i xxx/yyy/zzz.img
// however if the executable seemed to be in the current directory
// already this is reduced to just
//    zzz -o zzz.img
// so that I do not have two different handles on the same image file
// (with the potential muddle that that could result in).
//
// NOTE: this used very generally mean that you ended up with an empty image
// file (eg csl.img or reduce.img) in whatever directory you run this
// code from. This could be avoided by running it as
//    xxx -i-
// that explicitly sets up the normal image file as the one to use with
// no extras. However these days I try to arrange that an output image file
// only ever gets created if somebody calls FASLOUT or PRESERVE, so what
// I describe here will usually not cause confusion....
//
// The "image" here can now be in onw of two forms. The one that I historically
// used with CSL was that an image "xxx.img" was a single file that was set
// up with internal directories so that it acted as a composite unit holding
// many sub-files within it. That has the potential convenience that it is
// a single file to distribute and it is hard for there to be confuson about
// corruption or loss of the various sub-files within it. This scheme will
// still be used if xxx.img is a single file. But if on start-up xxx.img is a
// directory, or if it does not exist to start with and is named in the form
// "xxx.img/" with a trailing directory separator then the various sub-items
// will merely be stored within that directory. That moves the strain of
// managing them onto the operating system, but means that the operating system
// will maintain date-stamps on each sub-file and this may be useful if you
// wish to use "make" to maintain a project. It will be possible to have both
// a single-file and a directory based image open at the same time and copy
// at least some modules from one to another under program control.
//
// At present I still view the one-file solution as neater and so it is the
// default. The names used for files within a directory are discussed in the
// places where I manage them.
//
        if (standard_directory[0] == '.' &&
            (standard_directory[1] == '/' ||
             standard_directory[1] == '\\')) strcpy(cur, standard_directory);
        else get_current_directory(cur, sizeof(cur));
        p += strlen(p);
        while (p != standard_directory &&
               *--p != '/' &&
               *p != '\\') /* nothing */;
        if (strncmp(standard_directory, cur, p-standard_directory) != 0)
            p1 = (char *)(*malloc_hook)(strlen(p));
        else p1 = NULL;
        if (p == standard_directory || p1 == NULL)
        {   fasl_paths[0] = standard_directory;
//
// If output_directory has the 0x40000000 bit set then the directory
// involved is one that should be opened now if it exists, but if
// it does not its creation should be deferred for as long as possible.
//
            output_directory = 0x40000000 + 0;
            number_of_fasl_paths = 1;
            if (p1 != NULL) (*free_hook)(p1);
        }
        else
        {   strcpy(p1, p+1);
            fasl_paths[0] = p1;
            fasl_paths[1] = standard_directory;
            number_of_fasl_paths = 2;
        }
    }

    Iinit();  // Initialise "file system" for image files

    if (module_enquiry != NULL)
    {   char datestamp[32], fullname[LONGEST_LEGAL_FILENAME];
        int32_t size;
        int i;
        LispObject nil;
        memset(fullname, 0, sizeof(fullname));
//
// Imodulep expects input_libraries to be set up. So I will fudge the
// creation of something that looks sufficiently like a list to pass muster
// here despite the full system not being loaded. I use references to the
// nil-segment and cons().
//

        nilsegment = (LispObject *)my_malloc(NIL_SEGMENT_SIZE);
#ifdef COMMON
        nil = doubleword_align_up(nilsegment) + TAG_CONS + 8;
#else
        nil = doubleword_align_up(nilsegment) + TAG_SYMBOL;
#endif
        C_nil = nil;
        pages_count = heap_pages_count = vheap_pages_count =
                                             bps_pages_count = native_pages_count = 0;
        stacksegment = (LispObject *)my_malloc(CSL_PAGE_SIZE);
//
// I am lazy about protection against malloc failure here.
//
        heaplimit = doubleword_align_up(stacksegment);
        fringe = heaplimit + CSL_PAGE_SIZE - 16;
        input_libraries = heaplimit + 16 + TAG_SYMBOL;
        heaplimit += 64;
//
// I have now fudged up enough simulation of a Lisp heap that maybe I can
// build the library search-list.
//
        qheader(input_libraries)  |= SYM_SPECIAL_FORM;
        qvalue(input_libraries) = nil;
        for (i=number_of_fasl_paths-1; i>=0; i--)
            qvalue(input_libraries) = cons(SPID_LIBRARY + (((int32_t)i)<<20),
                                           qvalue(input_libraries));

        if (Imodulep(module_enquiry, strlen(module_enquiry),
                     datestamp, &size, fullname))
        {   strcpy(datestamp, "unknown");
            size = 0;
            strcpy(fullname, module_enquiry);
        }
        term_printf("%.24s   size=%ld file=%s\n",
                    datestamp, (long)size, fullname);
        init_flags &= ~INIT_VERBOSE;
#ifdef HAVE_FWIN
        fwin_pause_at_end = 0;
#endif
    }
    else
    {   base_time = read_clock();
        consolidated_time[0] = gc_time = 0.0;
        clock_stack = &consolidated_time[0];
        push_clock();

        if (init_flags & INIT_VERBOSE)
        {
#ifndef WINDOW_SYSTEM
//
// If I do NOT have a window system I will print a newline here so that I
// can be very certain that my banner appears at the start of a line.
// With a window system I should have a brand-new fresh window for output
// and the newline would intrude as an initial blank line.
//
            term_printf("\n");
#endif

#ifndef COMMON
            term_printf("Codemist Standard Lisp %s revision %d for %s: %s\n",
#else
            term_printf("Codemist Common Lisp %s revision %d for %s: %s\n",
#endif
                        VERSION, REVISION, IMPNAME, __DATE__);
        }
#ifdef MEMORY_TRACE
        if (car_counter != 0x7fffffff)
            term_printf("Stop after %ld %lu..%lu\n",
                        car_counter, car_low, car_high);
#endif
#ifdef WINDOW_SYSTEM
        ensure_screen();
// If the user hits the close button here I may be in trouble
#endif

#if defined HAVE_LIBPTHREAD || defined WIN32 || defined HAVE_CILK
        if (number_of_processors() >= 3)
        {   karatsuba_parallel = KARATSUBA_PARALLEL_CUTOFF;
            if (kparallel > 0) karatsuba_parallel = kparallel;
        }
#endif

//
// Now dynamic code detects the floating point representation that is in use.
// I thought/hoped that doing it this way would be safer than relying on having
// pre-defined symbols that tracked the machine architecture.
//
        {   union fpch
            {   double d;
                unsigned char c[8];
            } d;
//
// The following looks at the floating point representation of the
// number 1/7 (in double precision) and picks out two bytes from
// the middle of the first word - where I hope that rounding issues
// will be remote.  Investigation shows that these two bytes can be
// used to discriminate among at least a worthwhile range of
// representations, and I will exploit this to help me re-load
// heap-images in a way that allows images to be portable across
// different architectures.
//
            int w;
            d.d = 1.0/7.0;
// The coding here was adjusted to survive a Debian ARM Linux port.
            w = ((d.c[1] & 0xff) << 8) | (d.c[2] & 0xff);
            switch (w)
            {
//
// At one stage I detected (on of the) VAX representations and the one used
// by the IBM s60/s370. These days I am only going to recognise cases that
// use IEEE layout. Even with that the example machines noted here reveal
// that even though IEEE explains what bits should be in the floating point
// value different manufacturers pack the words and bytes in a variety of
// ways! Well the mere shuffling of bytes is something I can deal with. If I
// really needed to make image files portable to old-style IBM mainframes
// or on a xArch machine set up to use hexadecimal floating point mode then
// what I have here would moan. But if I just override the moan I will
// be able to build images and reload them on that particular machine.
//
// It seems that REALLY OLD version of ARM software - possibly before
// hardware floating point was generally installed there, used little endian
// representations except that the two 32-bit units of a 64-bit float were
// stored with the more significant one first. A test in 2016 on a Raspberry
// Pi indicates that things are now such that the ARM seems to match the Intel
// layout. That means that the only two orders I am now aware of arising are
// fully little endian and fully big endian. In the notation used here this
// is either nothing or is both byte and words swapped.
                case 0x2449:    current_fp_rep = 0;
                    break;           // Intel, MIPS, modern ARM
                case 0x49c2:    current_fp_rep = FP_WORD_ORDER;
                    break;           // ancient ARM!!!
                case 0x4924:    current_fp_rep = FP_BYTE_ORDER;
                    break;           // may never happen?
                case 0xc249:    current_fp_rep = FP_WORD_ORDER|FP_BYTE_ORDER;
                    break;           // SPARC
//
// The next line is probably not very good under a window manager, but
// it is a case that ought never to arise, so I will not bother.
//
                default:        term_printf("Unknown floating point format %.4x\n", w);
                    my_exit(EXIT_FAILURE);
            }
        }

//
// Up until the time I call setup() I may only use term_printf for
// output, because the other relevant streams will not have been set up.
//    1 bit:    0 for cold, 1 for warm.
//    2 bit:    1 to request initial allocation of memory.
//
        setup(restartp ? 3 : 2, store_size);
        {
//
// If the user had used "-g" on the command line that will have set
// errorset_min and I use that to trigger during on gc and fasl messages.
//
            if (errorset_min == 3) miscflags |= GC_MESSAGES | FASL_MESSAGES;
        }

#ifdef HAVE_FWIN
        fwin_menus(loadable_packages, switches, review_switch_settings);
#endif

//
// Now that setup is complete (and I have done any authorisation I want to)
// I will seed the random number generator as requested by the user. The
// default will be to put it in an unpredictable (well hard to predict!)
// state
//
        Csrand((uint32_t)initial_random_seed, (uint32_t)seed2);

        gc_time += pop_clock();

        countdown = software_ticks;
        interrupt_pending = already_in_gc = false;
        tick_pending = tick_on_gc_exit  = false;

#ifndef HAVE_FWIN
//
// "^C" trapping and handling happens within fwin if that is available.
//
#ifndef UNDER_CE
        sigint_must_throw = false;
        signal(SIGINT, sigint_handler);
#endif
#endif
        ensure_screen();
        procedural_output = NULL;
#ifdef HAVE_FWIN
//
// OK, if I get this far I will suppose that any messages that report utter
// disasters will have reached the user, so I can allow FWIN to terminate
// rather more promptly.
//
        fwin_pause_at_end = 0;
#endif
    }
#ifdef HAVE_FWIN
#ifdef HAVE_LIBFOX
//
// Activate the BREAK and BACKTRACE menu items. Note not needed unless
// FOX is used and so there is a prospect of theer actually being menus!
//
//
// The next line causes a MOAN using Sun's compiler, ending up with
// an undefined reference to fwin_callback_to_interrupt!
//
    fwin_callback_to_interrupt(async_interrupt);
#endif // HAVE_LIBFOX
#endif // HAVE_FWIN
}

#if 0
#ifdef SOCKETS

#define SOCKET_BUFFER_SIZE 1024
//
// The following two "character codes" are used when CSL is run as
// a socket server and wrap around prompt text. This could be in
// conflict with any code that tries to use these codes for other
// purposes or that handles prompts itself...
//
#define CH_PROMPT          0x9a
#define CH_ENDPROMPT       0x9c

static char socket_in[SOCKET_BUFFER_SIZE], socket_out[SOCKET_BUFFER_SIZE];
static int socket_in_p = 0, socket_in_n = 0,
           socket_out_p = 0, socket_prev = '\n';

static int char_from_socket(void)
{   int c;
    clock_t c0;
    time_t t0;
    if (socket_server == 0)
    {   socket_prev = ' ';
        return EOF;
    }
//
// I generate a prompt whenever I am about to read the character that
// follows a newline. The prompt is issued surrounded by control
// characters 0x9a and 0x9c. That curious arrangement is inherited from
// internal behaviour in my Windows interface code and could be altered
// if something truly better could be invented.
//
    if (socket_prev == '\n')
    {   term_printf("%c%s%c", CH_PROMPT, prompt_string, CH_ENDPROMPT);
        ensure_screen();
    }
    if (socket_in_n == 0)
    {   for (;;)
        {   socket_in_n = recv(socket_server, socket_in, SOCKET_BUFFER_SIZE, 0);
            c0 = clock();
            t0 = time(NULL);
            if (c0 > cpu_timeout || t0 > elapsed_timeout)
            {   cpu_timeout = c0 + 20;
                elapsed_timeout = t0 + 20;
                term_printf(
                    "\nSorry: timeout on this session. Closing down.\n");
                socket_prev = ' ';
                return EOF;
            }
            if (socket_in_n <= 0)
#ifndef EWOULDBLOCK
#  define EWOULDBLOCK WSAEWOULDBLOCK
#endif
            {   if (errno == EWOULDBLOCK)
                {
#ifdef WIN32
                    Sleep(1000);  // Arg in milliseconds here
#else
                    sleep(1);  // Delay 1 second before re-polling
#endif
                    continue;
                }
                closesocket(socket_server);
                socket_server = 0;
                socket_prev = ' ';
                return EOF;
            }
            else break;
        }
        socket_in_p = 0;
    }
    c = socket_in[socket_in_p++];
    if (c == 0x0a || c == 0x0d) c = '\n';
    socket_in_n--;
    socket_prev = c;
    return c & 0xff;
}

static int char_to_socket(int c)
{   if (socket_server == 0) return 1;
    socket_out[socket_out_p++] = (char)c;
    if (c == '\n' || socket_out_p == SOCKET_BUFFER_SIZE)
    {   if (send(socket_server, socket_out, socket_out_p, 0) < 0)
        {   closesocket(socket_server);
            socket_server = 0;
            return 1;
        }
        socket_out_p = 0;
    }
    return 0;
}

void flush_socket(void)
{   if (socket_server == 0) return;
    if (send(socket_server, socket_out, socket_out_p, 0) < 0)
    {   closesocket(socket_server);
        socket_server = 0;
    }
    socket_out_p = 0;
}

#endif
#endif

static void cslaction(void)
//
// This is the "standard" route into CSL activity - it uses file-names
// from the decoded command-line as files to be read and processed
// unless the system was launched with the flag that says it ought to try
// to provide a network service on some socket.
//
{
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    errorset_msg = NULL;
    try
    {
#ifndef UNDER_CE
        signal(SIGFPE, low_level_signal_handler);
        if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#ifdef SIGBUS
        if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
        if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
#endif
        non_terminal_input = NULL;
#ifdef WINDOW_SYSTEM
        terminal_eof_seen = 0;
#endif
        if (number_of_input_files == 0) lisp_main();
        else
        {   int i;
            for (i=0; i<number_of_input_files; i++)
            {   if (strcmp(files_to_read[i], "-") == 0)
                {   non_terminal_input = NULL;
#ifdef WINDOW_SYSTEM
                    terminal_eof_seen = 0;
#endif
                    lisp_main();
                }
                else
                {   char filename[LONGEST_LEGAL_FILENAME];
                    FILE *f;
                    memset(filename, 0, sizeof(filename));
                    f = open_file(filename, files_to_read[i],
                                  strlen(files_to_read[i]), "r", NULL);
                    if (f == NULL)
                        err_printf("\n+++ Could not read file \"%s\"\n",
                                   files_to_read[i]);
                    else
                    {   if (init_flags & INIT_VERBOSE)
                            term_printf("\n+++ About to read file \"%s\"\n",
                                        files_to_read[i]);
                        report_file(filename);
                        non_terminal_input = f;
                        lisp_main();
                        fclose(f);
                    }
                }
            }
        }
    }
    catch (const char *)
    {   if (errorset_msg != NULL)
        {   term_printf("\n%s detected\n", errorset_msg);
            errorset_msg = NULL;
        }
        return;
    }
}

int cslfinish(character_writer *w)
{
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    procedural_output = w;
    if (Ifinished())
        term_printf("\n+++ Errors on checkpoint-image file\n");
#ifdef TRACED_EQUAL
    dump_equals();
#endif
//
// clock_t is an arithmetic type but I do not know what sort - so I
// widen to double to do arithmetic on it. Actually what I MUST do is
// to compute a time difference in the type clock_t and hope I never
// get a difference that that overflows. The worst case I know of overflows
// after 35 minutes.
//
    if (init_flags & INIT_VERBOSE)
    {   long int t = (long int)(100.0 * (consolidated_time[0] +
                                         (double)(read_clock() - base_time)/
                                         (double)CLOCKS_PER_SEC));
        long int gct = (long int)(100.0 * gc_time);
        term_printf("\n\nEnd of Lisp run after %ld.%.2ld+%ld.%.2ld seconds\n",
                    t/100, t%100, gct/100, gct%100);
    }
#ifdef DEBUG_SOFTWARE_TICKS
    term_printf("%d ticks processed (%d)\n",
                number_of_ticks, SOFTWARE_TICKS);
#endif
    drop_heap_segments();
    if (spool_file != NULL)
    {
#ifdef COMMON
        fprintf(spool_file, "\nFinished dribbling to %s.\n", spool_file_name);
#else
        fprintf(spool_file, "\n+++ Transcript closed at end of run +++\n");
#endif
#ifndef DEBUG
        fclose(spool_file);
        spool_file = NULL;
#endif
    }
    ensure_screen();
    procedural_output = NULL;
    return return_code;
}

int execute_lisp_function(const char *fname,
                          character_reader *r,
                          character_writer *w)
{   LispObject nil;
    LispObject ff;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    ff = make_undefined_symbol(fname);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  // Failed to make the symbol
    }
    procedural_input = r;
    procedural_output = w;
    Lapply0(nil, ff);
    ensure_screen();
    procedural_input = NULL;
    procedural_output = NULL;
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failure during evaluation
    }
    return 0;
}

//
// People who want to use this in an embedded context can predefine
// NO_STARTUP_CODE and provide their own entrypoint...
//

#ifndef NO_STARTUP_CODE

//
// The next fragment of code is to help with the use of CSL (and hence
// packages written in Lisp and supported under CSL) as OEM products
// embedded within larger C-coded packages.  There is (of course) a
// significant issue about clashes between the names of external symbols
// if CSL is to be linked with anything else, but I will not worry about that
// just yet.
// The protocol for calling Lisp code from C is as follows:
//
//     cslstart(argc, argv, writer);allocate memory and Lisp heap etc. Args
//                                  should be "as if" CSL was being called
//                                  directly and this was the main entrypoint.
//                                  The extra arg accepts output from this
//                                  stage.  Use NULL to get standard I/O.
//     execute_lisp_function(fname, reader, writer);
//                                  fname is a (C) string that names a Lisp
//                                  function of 0 args.  This is called with
//                                  stdin/stdout access redirected to use the
//                                  two character-at-a-time functions passed
//                                  down.  [Value returned indicates if
//                                  the evaluation succeeded?]
//     cslfinish(writer);           Tidies up ready to stop.
//

#ifdef SAMPLE_OF_PROCEDURAL_INTERFACE

static char ibuff[100], obuff[100];
static int ibufp = 0, obufp = 0;
static int iget()
{   int c = ibuff[ibufp++];
    if (c == 0) return EOF;
    else return c;
}

static void iput(int c)
{   if (obufp < sizeof(obuff)-1)
    {   obuff[obufp++] = c;
        obuff[obufp] = 0;
    }
}

#endif

static int submain(int argc, const char *argv[])
{   cslstart(argc, argv, NULL);
#ifdef SAMPLE_OF_PROCEDURAL_INTERFACE
    strcpy(ibuff, "(print '(a b c d))");
    execute_lisp_function("oem-supervisor", iget, iput);
    printf("Buffered output is <%s>\n", obuff);
#else
    if (module_enquiry == NULL) cslaction();
#endif
    my_exit(cslfinish(NULL));
//
// The "return 0" here is unreachable but it still quietens down as many
// C compilers as it causes to moan noisily!
//
    return 0;
}

#if defined HAVE_FWIN && !defined EMBEDDED
#define ENTRYPOINT fwin_main

extern int ENTRYPOINT(int argc, const char *argv[]);

int main(int argc, const char *argv[])
{   fwin_set_lookup(look_in_lisp_variable);
    return fwin_startup(argc, argv, ENTRYPOINT);
}

#else
#define ENTRYPOINT main
#endif


int ENTRYPOINT(int argc, const char *argv[])
{   int res;
#ifdef EMBEDDED
    if ((res = find_program_directory(argv[0])) != 0)
    {   fprintf(stderr, "Unable to identify program name and directory (%d)\n", res);
        return 1;
    }
#endif
#ifdef USE_MPI
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&mpi_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&mpi_size);
    printf("I am mpi instance %d of %d.\n", mpi_rank+1, mpi_size);
#endif

#ifdef HAVE_FWIN
    strcpy(about_box_title, "About CSL");
    strcpy(about_box_description, "Codemist Standard Lisp");
#endif
    try
    {   res = submain(argc, argv);
    }
    catch(int r)
    {   res = r;
    }
#ifdef USE_MPI
    MPI_Finalize();
#endif
    return res;
}

#endif // NO_STARTUP_CODE

//
// And here are some functions that may help use Reduce, as an alternative
// to the very general escape that execute_lisp_function provides... If
// these return an integer it will genarlly be zero for success and non-
// zero for failure.
//

//
// After having called cslstart() you can set the I/O callback functions
// using this. If you set one or both to NULL this indicates use of
// stdin/stdout as per usual rather than an callback, otherwise whenever
// anybody wants to read or write they use these procedures. It is then
// your responsibility to cope with whatever text gets exchanged!
//

int PROC_set_callbacks(character_reader *r,
                       character_writer *w)
{   procedural_input = r;
    procedural_output = w;
    return 0;   // can never report failure
}

int PROC_load_package(const char *name)
{   LispObject nil = C_nil;
    LispObject w = nil, w1 = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    w1 = make_undefined_symbol("load-package");
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  // Failed to make the load-package
    }
    push(w1);
    w = make_undefined_symbol(name);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to make name
    }
    pop(w1);
    Lapply1(nil, w1, w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 3;  // Failed to load the package
    }
    return 0;
}

int PROC_set_switch(const char *name, int val)
{   LispObject nil = C_nil;
    LispObject w = nil, w1 = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    w1 = make_undefined_symbol("onoff");
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  // Failed to make the onoff
    }
    push(w1);
    w = make_undefined_symbol(name);
    pop(w1);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to make name
    }
    Lapply2(nil, 3, w1, w, val == 0 ? nil : lisp_true);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 3;  // Failed to set the switch
    }
    return 0;
}

int PROC_gc_messages(int n)
{   LispObject nil = C_nil;
    Lverbos(nil, fixnum_of_int(n)); // can not fail
    return 0;
}

//
// Expressions are entered in Reverse Polish Notation, This call clears
// the stack. It is probably only wanted if there has been an error
// of some sort.
//

int PROC_clear_stack()
{   LispObject nil = C_nil;
    procstack = nil;
    return 0;       // can never fail!
}

//
// The RPN stack is used to build a prefix-form expression for
// evaluation. This code creates a Lisp symbol and pushes it.
//

int PROC_push_symbol(const char *name)
{   LispObject nil = C_nil;
    LispObject w = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    w = make_undefined_symbol(name);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  // Failed to make the symbol
    }
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}


//
//    stack = the-string . stack;
//

int PROC_push_string(const char *data)
{   LispObject nil = C_nil;
    LispObject w = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    w = make_string(data);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  // Failed to make the string
    }
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}

//
// Return a handle to the top item on the stack, and pop the stack.
// The value here will be a RAW LISP structure and NOT at all necessarily
// anything neat.
//

//
// Push an integer, which should fit within the constraints of a
// 28-bit fixnum.
//

int PROC_push_small_integer(int32_t n)
{   LispObject nil = C_nil;
    LispObject w = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    w = make_lisp_integer32(n);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  // Failed to create number
    }
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}

int PROC_push_big_integer(const char *n)
{   LispObject nil = C_nil;
    LispObject w = nil;
    int len = 0;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
// Here I need to parse a C string to obtain a Lisp number.
    boffop = 0;
    while (*n != 0)
    {   packbyte(*n++);
        len++;
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            return 1;  // boffo trouble
        }
    }
    w = intern(len, 0);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // conversion to number
    }
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 3;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}

int PROC_push_floating(double n)
{   LispObject nil = C_nil;
    LispObject w = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
// Here I have to construct a Lisp (boxed) float
    w = make_boxfloat(n, TYPE_DOUBLE_FLOAT);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  // Failed to create the float
    }
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}

//
// To make an expression
//    (f a1 a2 a3)
// you go
//       push(a1)
//       push(a2)
//       push(a3)
//       make_function_call("f", 3)
//

int PROC_make_function_call(const char *name, int n)
{   LispObject nil = C_nil;
    LispObject w = nil, w1 = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    while (n > 0)
    {   if (procstack == nil) return 1; // Not enough args available
        w = cons(qcar(procstack), w);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            return 2;  // Failed to push onto stack
        }
        procstack = qcdr(procstack);
        n--;
    }
    push(w);
    w1 = make_undefined_symbol(name);
    pop(w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 3;  // Failed to create function name
    }
    w = cons(w1, w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 4;  // Failed to cons on function name
    }
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 5;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}

//
// Take the top item on the stack and save it in location n (0 <= n <= 99).
//

int PROC_save(int n)
{   LispObject nil = C_nil;
    if (n < 0 || n > 99) return 1; // index out of range
    if (procstack == nil) return 2; // Nothing available to save
    elt(procmem, n) = qcar(procstack);
    procstack = qcdr(procstack);
    return 0;
}

//
// Push onto the stack the value saved at location n. See PROC_save.
//

int PROC_load(int n)
{   LispObject nil = C_nil;
    LispObject w = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    if (n < 0 || n > 99) return 1; // index out of range
    w = elt(procmem, n);
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}

//
// Duplicate the top item on the stack.
//

int PROC_dup()
{   LispObject nil = C_nil;
    LispObject w = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    if (procstack == nil) return 1; // no item to duplicate
    w = qcar(procstack);
    w = cons(w, procstack);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed to push onto stack
    }
    procstack = w;
    return 0;
}

int PROC_pop()
{   LispObject nil = C_nil;
    if (procstack == nil) return 1; // stack is empty
    procstack = qcdr(procstack);
    return 0;
}

//
// Replaces the top item on the stack with a simplified version of
// itself. For experts on Reduce internals I note that this wraps
// the simplified form up in a prefix-like "!*sq" wrapper so it can
// still be used in a prefix context.
//

int PROC_simplify()
{   LispObject nil = C_nil;
    LispObject w = nil, w1 = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    if (procstack == nil) return 1; // stack is empty
    w = make_undefined_symbol("simp");
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed find "simp"
    }
    w = Lapply1(nil, w, qcar(procstack));
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 3;  // Call to simp failed
    }
    push(w);
    w1 = make_undefined_symbol("mk*sq");
    pop(w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 4;  // Failed to find "mk!*sq"
    }
    w = Lapply1(nil, w1, w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 5;  // Call to mk!*sq failed
    }
    qcar(procstack) = w;
    return 0;
}

//
// Replace the top item on the stack with whatever is obtained by using
// the Lisp EVAL operatio on it. Note that this is not intended for
// casual use - if there is any functionality that you need PLEASE ask
// me to put in a cleaner abstraction to support it.
//

static void PROC_standardise_gensyms(LispObject w)
{   LispObject nil = C_nil;
    if (consp(w))
    {   push(qcdr(w));
        PROC_standardise_gensyms(qcar(w));
        pop(w);
        errexitv();
        PROC_standardise_gensyms(w);
        return;
    }
//
// Now w is atomic. The only case that concerns me is if it is a gensym.
//
    if (symbolp(w)) get_pname(w); // allocates gensym name if needed.
}

int PROC_lisp_eval()
{   LispObject nil = C_nil;
    LispObject w = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    if (procstack == nil) return 1; // stack is empty
    w = Ceval(qcar(procstack), nil);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Evaluation failed
    }
    push(w);
    PROC_standardise_gensyms(w);
    pop(w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 3;  // gensym patchup failed
    }
    qcar(procstack) = w;
    return 0;
}

static LispObject PROC_standardise_printed_form(LispObject w)
{   LispObject nil = C_nil, w1;
    if (consp(w))
    {   push(qcdr(w));
        w1 = PROC_standardise_printed_form(qcar(w));
        pop(w);
        errexit();
        push(w1);
        w =  PROC_standardise_printed_form(w);
        pop(w1);
        errexit();
        return cons(w1, w);
    }
//
// Now w is atomic. There are two interesting cases - an unprinted gensym
// and a bignum.
//
    if (symbolp(w))
    {   push(w);
        get_pname(w); // allocates gensym name if needed. Otherwise cheap!
        pop(w);
        errexit();
        return w;
    }
    else if (is_numbers(w) && is_bignum(w))
    {   w = Lexplode(nil, w);        // Bignum to list of digits
        errexit();
        w = Llist_to_string(nil, w); // list to string
        errexit();
        return w;
    }
    else return w;
}

//
// Replaces the top item on the stack with version that is in
// a simple prefix form. This prefix form should be viewed as
// unsuitable for inclusion in any further expression.
//

int PROC_make_printable()
{   LispObject nil = C_nil;
    LispObject w = nil, w1 = nil;
#ifdef CONSERVATIVE
    volatile LispObject sp;
    C_stackbase = (LispObject *)&sp;
#endif
    if (procstack == nil) return 1; // stack is empty
//
// I want to use "simp" again so that I can then use prepsq!
//
    w = make_undefined_symbol("simp");
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 2;  // Failed find "simp"
    }
    w = Lapply1(nil, w, qcar(procstack));
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 3;  // Call to simp failed
    }
    push(w);
    w1 = make_undefined_symbol("prepsq");
    pop(w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 4;  // Failed to find "prepsq"
    }
    w = Lapply1(nil, w1, w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 5;  // Call to prepsq failed
    }
//
// There are going to be two things I do next. One is to ensure that
// all gensyms have print-names, the other is to convert bignums into
// strings. Both of these could be viewed as mildly obscure!
//
    w = PROC_standardise_printed_form(w);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 6;  // standardise_printed_form failed
    }
    qcar(procstack) = w;
    return 0;
}

PROC_handle PROC_get_value()
{   LispObject nil = C_nil;
    LispObject w;
    if (procstack == nil) w = fixnum_of_int(0);
    else
    {   w = qcar(procstack);
        procstack = qcdr(procstack);
    }
    return (PROC_handle)w;
}

PROC_handle PROC_get_raw_value()
{   LispObject nil = C_nil;
    LispObject w;
    if (procstack == C_nil) w = nil;
    else
    {   w = qcar(procstack);
        procstack = qcdr(procstack);
    }
    return (PROC_handle)w;
}

//
// return true if the expression is atomic.
//

int PROC_atom(PROC_handle p)
{   return !consp((LispObject)p);
}

//
// return true if the expression is NIL.
//

int PROC_null(PROC_handle p)
{   return ((LispObject)p) == C_nil;
}

//
// Return true if it is a small integer.
//

int PROC_fixnum(PROC_handle p)
{   return is_fixnum((LispObject)p);
}

int PROC_string(PROC_handle p)
{   return is_vector((LispObject)p) &&
           is_string((LispObject)p);
}

int PROC_floatnum(PROC_handle p)
{
//
// I ignore the "sfloat" representation that would be relevant in Common
// Lisp mode. It is not used with Reduce.
//
    return is_bfloat((LispObject)p);
}

//
// Return true if it is a symbol.
//

int PROC_symbol(PROC_handle p)
{   return symbolp((LispObject)p);
}

//
// Given that it is a small integer return the integer value
//

int32_t PROC_integer_value(PROC_handle p)
{   return (int32_t)int_of_fixnum((LispObject)p);
}

double PROC_floating_value(PROC_handle p)
{   return double_float_val((LispObject)p);
}

//
// Given that it is a symbol, return a string that is its name. Note
// that this must not be too long, and that the value returned is in
// a static buffer. Note that this would crash if the item was a
// "gensym" that had not been printed before, and so I take care to
// sort that out in PROC_make_printable.
// Hmmm the name-length restriction here is ugly _ will wait and see how
// long it is before somebody falls foul of it!
//

static char PROC_name[256];

const char *PROC_symbol_name(PROC_handle p)
{   LispObject w = (LispObject)p;
    intptr_t n;
    w = qpname(w);
    n = length_of_byteheader(vechdr(w)) - CELL;
    if (n > (intptr_t)sizeof(PROC_name)-1) n = sizeof(PROC_name)-1;
    strncpy(PROC_name, &celt(w, 0), n);
    PROC_name[n] = 0;
    return &PROC_name[0];
}

const char *PROC_string_data(PROC_handle p)
{   LispObject w = (LispObject)p;
    intptr_t n;
    n = length_of_byteheader(vechdr(w)) - CELL;
//
// NOTE that I truncate long strings here. Boo Hiss! This may make a mess
// of dealing with big numbers, so in due course I will need to fix it!
//
    if (n > (intptr_t)sizeof(PROC_name)-1) n = sizeof(PROC_name)-1;
    strncpy(PROC_name, &celt(w, 0), n);
    PROC_name[n] = 0;
    return &PROC_name[0];
}

//
// First and rest allow list traversal.
//

PROC_handle PROC_first(PROC_handle p)
{   return (PROC_handle)qcar((LispObject)p);
}

PROC_handle PROC_rest(PROC_handle p)
{   return (PROC_handle)qcdr((LispObject)p);
}

// End of csl.cpp
