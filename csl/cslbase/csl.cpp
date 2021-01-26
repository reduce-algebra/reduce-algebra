// csl.cpp                                 Copyright (C) 1989-2021 Codemist

//
// This is Lisp system for use when delivering Lisp applications
// (such as REDUCE) on pretty-well any computer that has an ANSI
// C++ compiler.
//

/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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


// When built using wxWidgets this code will use the Latin Modern
// fonts, which are subject to the LaTeX Project Public License. This
// comment is places somewhere I view as pretty prominent - ie at the head
// of the source of the main part of the code. I have further comments
// and explanation lower in this file such that invoking CSL or
// Reduce with an option "--help" will generate the required credits and
// notices, so if this matters to you search this file for the string
// "LaTeX" for more information.

// $Id$


// There are a number of comments here introduced with exclamation
// mark after the "/" and "*" that start them. These contain material
// to be extracted to form documentation. They MUST remain as slash-star
// style comments with format as used here so that the documentation
// extraction utility can find them.

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

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


// These flags are used to ensure that protected symbols don't get
// overwritten by default, and that the system keeps quiet about it.

bool symbol_protect_flag = true;
bool warn_about_protected_symbols = false;

// used in char_from_string
const char *proc_data_string = ";";

#ifdef USE_MPI
int32_t mpi_rank,mpi_size;
#endif

/*****************************************************************************/
//      Error reporting and recovery
/*****************************************************************************/

volatile char stack_contents_temp = 0;

#ifdef CHECK_STACK
// Some computers are notably unhelpful about their behaviour when the system
// stack overflows. As a debugging tool on such machines I can do limited
// software checking by inserting explicit calls to this function in places
// I think may be critical.  I impose an arbitrary limit on the stack size,
// but that is better than no checking and random corruption - maybe. Please
// do not enable CHECK_STACK unless it is really necessary to hunt a bug,
// since it is miserably expensive and crude. I appear to observe that on
// my Windows versions (both 32 and 64-bit) there is around 2M of stack, while
// on Linux the amount of stack is set via ulimit and is not fixed.

#define C_STACK_ALLOCATION 1000000

static int spset = 0;
static uintptr_t spbase = 0, spmin;

static uintptr_t stack_depth[C_STACK_ALLOCATION];
static int stack_line[C_STACK_ALLOCATION];
static const char *stack_file[C_STACK_ALLOCATION];
static uintptr_t c_stack_ptr = 0;

int check_stack(const char *file, int line)
{   uintptr_t temp = reinterpret_cast<intptr_t>(&temp);
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
    if (temp < stack_depth[c_stack_ptr] &&
        c_stack_ptr<C_STACK_ALLOCATION-2)
        c_stack_ptr++;
    else while (temp > stack_depth[c_stack_ptr] && c_stack_ptr>0)
            c_stack_ptr--;
    stack_depth[c_stack_ptr] = temp;
    stack_line[c_stack_ptr] = line;
    file1 = std::strrchr(file, '/');
    stack_file[c_stack_ptr] = (file1 == nullptr ? file : file1+1);
    if (temp < spmin-250)  // Only check at granularity of 250 bytes
    {   int i, j=0;
        term_printf("Stack depth %u at file %s line %d\n",
                    static_cast<unsigned int>(spbase-temp), file, line);
        term_printf("c_stack_ptr = %d\n", c_stack_ptr);
        for (i=c_stack_ptr; i>=0; i--)
        {   if (first || stack_file[i][0] != '@')
                term_printf(" %s:%d:%" PRIxPTR,
                            stack_file[i], stack_line[i], stack_depth[i]);
            if (stack_file[i][0] != '@') first = 0;
            if ((++j)%4 == 3) term_printf("\n");
        }
        term_printf("\n");
        spmin = temp;
        if (temp < spbase-C_STACK_ALLOCATION ||
            temp < (uintptr_t)C_stacklimit) return 1;
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

std::mutex debug_lock;
const char *debug_file;
int debug_line;

void DebugTrace()
{   const char *leaf = std::strrchr(debug_file, '/');
    if (leaf != nullptr) debug_file = leaf+1;
    leaf = std::strrchr(debug_file, '\\');
    if (leaf != nullptr) debug_file = leaf+1;
    std::fprintf(stderr, "Tr in file %s line %d\n", debug_file,
                 debug_line);
    std::fflush(stderr);
}

void DebugTrace(int i)
{   const char *leaf = std::strrchr(debug_file, '/');
    if (leaf != nullptr) debug_file = leaf+1;
    leaf = std::strrchr(debug_file, '\\');
    if (leaf != nullptr) debug_file = leaf+1;
    std::fprintf(stderr, "Tr in file %s line %d: %d/%x\n", debug_file,
                 debug_line, i, i);
    std::fflush(stderr);
}

void DebugTrace(const char *msg)
{   const char *leaf = std::strrchr(debug_file, '/');
    if (leaf != nullptr) debug_file = leaf+1;
    leaf = std::strrchr(debug_file, '\\');
    if (leaf != nullptr) debug_file = leaf+1;
    std::fprintf(stderr, "Tr in file %s line %d: %s\n", debug_file,
                 debug_line, msg);
    std::fflush(stderr);
}

void DebugTrace(const char *fmt, int i)
{   const char *leaf = std::strrchr(debug_file, '/');
    if (leaf != nullptr) debug_file = leaf+1;
    leaf = std::strrchr(debug_file, '\\');
    if (leaf != nullptr) debug_file = leaf+1;
    std::fprintf(stderr, "Tr in file %s line %d: ", debug_file,
                 debug_line);
    std::fprintf(stderr, fmt, i);
    std::fprintf(stderr, "\n");
    std::fflush(stderr);
}

// error_message_table was defined in cslerror.h since that way I can keep its
// contents textually close to the definitions of the message codes that it
// has to relate to.

#define errcode(n) error_message_table[n]

#define ARG_CUT_OFF 10

LispObject error(int nargs, int code, ...)
// nargs indicates how many values have been provided AFTER the
// code.  Thus nargs==0 will just display a simple message, nargs==1
// will be a message plus a value and so on.  I will expect that the
// number of actual args here is well within any limits that I ought to
// impose.
{   std::va_list a;
    int i;
    LispObject w1;
    LispObject *w = reinterpret_cast<LispObject *>(&work_1);
    if (nargs > ARG_CUT_OFF) nargs = ARG_CUT_OFF;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("\n+++ Error %s: ", errcode(code));
// There is now some painful shuffling around to get all the args
// to error() moved over onto the Lisp stack so that is garbage collection
// is triggered during printing all will be well.
        va_start(a, code);
        for (i=0; i<nargs; i++) *w++ = va_arg(a, LispObject);
        va_end(a);
        for (i=0; i<nargs; i++) *++stack = *--w;
        if (code != err_stack_overflow)  // Be cautious here!
        {   stackcheck();
        }
        for (i=0; i<nargs; i++)
        {   LispObject p = *stack--;
            loop_print_error(p);
            err_printf("\n");
        }
    }
    if ((w1 = qvalue(break_function)) != nil &&
        symbolp(w1) &&
        qfn1(w1) != undefined_1)
    {   ignore_error((*qfn1(w1))(qenv(w1), nil));
// If the break function does a (stop) or (restart) etc then that
// must be activated.
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

LispObject cerror(int nargs, int code1, int code2, ...)
// nargs indicated the number of EXTRA args after code1 & code2.
{   LispObject w1;
    std::va_list a;
    int i;
    LispObject *w = reinterpret_cast<LispObject *>(&work_1);
    if (nargs > ARG_CUT_OFF) nargs = ARG_CUT_OFF;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("\n+++ Error %s, %s: ", errcode(code1), errcode(code2));
        va_start(a, code2);
        for (i=0; i<nargs; i++) *w++ = va_arg(a, LispObject);
        va_end(a);
        for (i=0; i<nargs; i++) *++stack = *--w;
        stackcheck();
        for (i=0; i<nargs; i++)
        {   LispObject p = *stack--;
            loop_print_error(p);
            err_printf("\n");
        }
    }
    if ((w1 = qvalue(break_function)) != nil &&
        symbolp(w1) &&
        qfn1(w1) != undefined_1)
    {   ignore_error((*qfn1(w1))(qenv(w1), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

// This can be used when a resource expires...
LispObject resource_exceeded()
{   exit_reason = UNWIND_RESOURCE;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispResource);
}

LispObject interrupted()
{   LispObject w;
    char save_prompt[80];
// If I have a windowed system I expect that the mechanism for
// raising an exception will have had a menu that gave me a chance
// to decide whether to proceed or abort.  Thus the following code
// is only needed if there is no window system active.  On some systems
// this may be an active check.
    if ((fwin_windowmode() & FWIN_IN_WINDOW) == 0)
    {   term_printf("\n");
        ensure_screen();
        RealSave save(prompt_thing);
        prompt_thing = nil;  // switch off the regular prompts
        std::strncpy(save_prompt, fwin_prompt_string, sizeof(save_prompt));
        save_prompt[sizeof(save_prompt)-1] = 0;
// Well I will want this to run a break-loop, but doing what I once did will
// at least give me something to test!
        fwin_set_prompt("+++ Type C to continue, A to abort, X to exit: ");
        other_read_action(READ_FLUSH, lisp_terminal_io);
        for (;;)
        {   int c = char_from_terminal(nil);
// Note that I explicitly say "char_from_terminal()" here - this is because
// I do not expect to be interrupted unless there was a terminal available
// to send the interrupt! This is in fact a slightly marginal assumption.
            switch (c)
            {   case 'c': case 'C':         // proceed as if no interrupt
                    save.restore(prompt_thing);
                    fwin_set_prompt(save_prompt);
                    return nil;
                case 'a': case 'A':         // raise an exception
                    break;
                case 'x': case 'X':
                    my_exit();              // Rather abrupt
                    return nil;
                case '\n':
                    ensure_screen();
                    continue;
                default:                    // wait for A or C
                    continue;
            }
            break;
        }
        save.restore(prompt_thing);
        fwin_set_prompt(save_prompt);
    }
// Now for the common code to be used in all cases.
    miscflags |= HEADLINE_FLAG | FNAME_FLAG | ARGS_FLAG;
    if (miscflags & HEADLINE_FLAG)
        err_printf("+++ Interrupted\n");
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   ignore_error((*qfn1(w))(qenv(w), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

LispObject aerror(const char *s)
{   LispObject w;
    if (miscflags & HEADLINE_FLAG)
        err_printf("+++ Error bad args for %s\n", s);
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   ignore_error((*qfn1(w))(qenv(w), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

LispObject aerror0(const char *s)
{   LispObject w;
    if (miscflags & HEADLINE_FLAG)
        err_printf("+++ Error: %s\n", s);
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   ignore_error((*qfn1(w))(qenv(w), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

LispObject aerror1(const char *s, LispObject a)
{   LispObject w;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("+++ Error: %s ", s);
        loop_print_error(a);
        err_printf("\n");
    }
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   ignore_error((*qfn1(w))(qenv(w), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

LispObject aerror2(const char *s, LispObject a, LispObject b)
{   LispObject w;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("+++ Error: %s ", s);
        loop_print_error(a);
        err_printf(" ");
        loop_print_error(b);
        err_printf("\n");
    }
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   ignore_error((*qfn1(w))(qenv(w), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

LispObject aerror2(const char *s, const char *a, LispObject b)
{   LispObject w;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("+++ Error: %s %s ", s, a);
        loop_print_error(b);
        err_printf("\n");
    }
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   ignore_error((*qfn1(w))(qenv(w), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

LispObject aerror3(const char *s, LispObject a, LispObject b,
                   LispObject c)
{   LispObject w;
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("+++ Error: %s ", s);
        loop_print_error(a);
        err_printf(" ");
        loop_print_error(b);
        err_printf("\n");
        loop_print_error(c);
        err_printf("\n");
    }
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined_1)
    {   ignore_error((*qfn1(w))(qenv(w), nil));
        errexit();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    THROW(LispError);
}

static LispObject wrong(int given, int wanted, LispObject env)
{   char msg[64];
    if (wanted == 4)
        std::sprintf(msg,
                     "Function called with %d args where more then three wanted",
                     given);
    else if (given == 4)
        std::sprintf(msg,
                     "Function called with more than three args where %d wanted",
                     wanted);
    else std::sprintf(msg, "Function called with %d args where %d wanted",
                          given, wanted);
    if ((miscflags & HEADLINE_FLAG))
    {   err_printf("\nCalling ");
        loop_print_error(env);
        err_printf("\n");
    }
    return aerror(msg);
}

static LispObject wrong(int given, LispObject env)
{   char msg[64];
    if (given == 4)
        std::sprintf(msg,
                     "Function called incorrectly with more than 3 args");
    else std::sprintf(msg, "Function called incorrectly with %d args",
                          given);
    if ((miscflags & HEADLINE_FLAG))
    {   err_printf("\nCalling ");
        loop_print_error(env);
        err_printf("\n");
    }
    return aerror(msg);
}

LispObject got_0_wanted_1(LispObject env)
{   return wrong(0, 1, env);
}

LispObject got_0_wanted_2(LispObject env)
{   return wrong(0, 2, env);
}

LispObject got_0_wanted_3(LispObject env)
{   return wrong(0, 3, env);
}

LispObject got_0_wanted_4up(LispObject env)
{   return wrong(0, 4, env);
}

LispObject got_0_wanted_other(LispObject env)
{   return wrong(0, env);
}


LispObject got_1_wanted_0(LispObject env, LispObject a1)
{   return wrong(0, 1, env);
}

LispObject got_1_wanted_2(LispObject env, LispObject a1)
{   return wrong(2, 1, env);
}

LispObject got_1_wanted_3(LispObject env, LispObject a1)
{   return wrong(3, 1, env);
}

LispObject got_1_wanted_4up(LispObject env, LispObject a1)
{   return wrong(4, 1, env);
}

LispObject got_1_wanted_other(LispObject env, LispObject a1)
{   return wrong(1, env);
}


LispObject got_2_wanted_0(LispObject env, LispObject a1, LispObject a2)
{   return wrong(0, 2, env);
}

LispObject got_2_wanted_1(LispObject env, LispObject a1, LispObject a2)
{   return wrong(1, 2, env);
}

LispObject got_2_wanted_3(LispObject env, LispObject a1, LispObject a2)
{   return wrong(3, 2, env);
}

LispObject got_2_wanted_4up(LispObject env, LispObject a1, LispObject a2)
{   return wrong(4, 2, env);
}

LispObject got_2_wanted_other(LispObject env, LispObject a1, LispObject a2)
{   return wrong(2, env);
}


LispObject got_3_wanted_0(LispObject env, LispObject a1,
                          LispObject a2, LispObject a3)
{   return wrong(0, 3, env);
}

LispObject got_3_wanted_1(LispObject env, LispObject a1,
                          LispObject a2, LispObject a3)
{   return wrong(1, 3, env);
}

LispObject got_3_wanted_2(LispObject env, LispObject a1,
                          LispObject a2, LispObject a3)
{   return wrong(2, 3, env);
}

LispObject got_3_wanted_4up(LispObject env, LispObject a1,
                            LispObject a2, LispObject a3)
{   return wrong(4, 3, env);
}

LispObject got_3_wanted_other(LispObject env, LispObject a1,
                              LispObject a2, LispObject a3)
{   return wrong(3, env);
}


LispObject got_4up_wanted_0(LispObject env, LispObject a1, LispObject a2,
                            LispObject a3, LispObject a4up)
{   return wrong(0, 4, env);
}

LispObject got_4up_wanted_1(LispObject env, LispObject a1, LispObject a2,
                            LispObject a3, LispObject a4up)
{   return wrong(1, 4, env);
}

LispObject got_4up_wanted_2(LispObject env, LispObject a1, LispObject a2,
                            LispObject a3, LispObject a4up)
{   return wrong(2, 4, env);
}

LispObject got_4up_wanted_3(LispObject env, LispObject a1, LispObject a2,
                            LispObject a3, LispObject a4up)
{   return wrong(3, 4, env);
}

LispObject got_4up_wanted_other(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4up)
{   return wrong(4, env);
}

LispObject bad_specialn(LispObject, int, ...)
{   return aerror("call to special form");
}

void fatal_error(int code, ...)
{
// Note that FATAL error messages are sent to the terminal, not to the
// error output stream. This is because the error output stream may be
// corrupted in such dire circumstances.
    term_printf("+++ Fatal error %s\n", errcode(code));
    if (spool_file != nullptr)
    {
#ifdef COMMON
        std::fprintf(spool_file,
                     "\nFinished dribbling to %s.\n", spool_file_name);
#else
        std::fprintf(spool_file,
                     "\n+++ Transcript terminated after error +++\n");
#endif
        std::fclose(spool_file);
        spool_file = nullptr;
    }
    my_exit();
}

static char dependency_file[LONGEST_LEGAL_FILENAME] = {0};
static std::vector<char *> dependency_map;

void report_file(const char *s)
{   char *c;
    const char *s1;
    if (dependency_file[0] == 0) return;
// In a really odd way I will avoid recording inline-defs.dat as a
// dependency and insist that if it is to be one that the Makefile should
// list that explicitly. This helps me avoid some dependency circularities.
// but note that inline-defs.dat may not be in the current directory.
// Use of that file-name for any other purposes may cause issues!
// Here I find the final component of the path - ie the bit following the
// last "/" or "\" present if there is one of those.
    if ((s1 = std::strrchr(s, '/')) != nullptr) s1++;
    else if ((s1 = std::strrchr(s, '\\')) != nullptr) s1++;
    else s1 = s;
    if (std::strcmp(s1, "inline-defs.dat") == 0) return;
    for (char *s1 : dependency_map)
    {   if (std::strcmp(s, s1)==0) return; // already recorded
    }
    c = new (std::nothrow) char[std::strlen(s) + 1];
    if (c == nullptr) return;
    std::strcpy(c, s);
// The following could throw an exception if the Vector was getting full and
// needed to grow and if the allocation of new space failed. Such a case may
// be fatal if exceptions are not supported!
    try
    {   dependency_map.push_back(c);
    }
    catch (...)
    {}
}

static bool alphorder(const char *a, const char *b)
{   return std::strcmp(a, b) < 0;
}

static void report_dependencies()
{   std::FILE *f;
    int c;
    const char *p;
    if (dependency_file[0] == 0) return;
    f = std::fopen(dependency_file, "w");
    if (f == nullptr) return;
    p = std::strrchr(dependency_file, '.');
    std::fprintf(f, "%.*sdep = \\\n",
                 static_cast<int>(p==nullptr ? std::strlen(dependency_file) :
                                  (p - dependency_file)),
                 dependency_file);
    std::sort(dependency_map.begin(), dependency_map.end(), alphorder);
    for (char *pp : dependency_map)
    {   std::putc('\t', f);
// If I am on Windows some files may at this stage be shown with names
// of the form "X:/..." where X denotes the drive. But the dependencies I
// am creating are for the benefit of the cygwin version of GNU make, and
// that will get seriously upset by the colon, thinking it is indicating that
// I have multiple targets. So I will map "X:/" onto "/cygdrive/x/".
        if (pp[0] != 0 &&
            pp[1] == ':' &&
            (pp[2] == '/' || pp[2] == '\\'))
        {   std::fprintf(f, "/cygdrive/%c",
                         static_cast<char>(std::tolower(static_cast<unsigned char>(pp[0]))));
            pp+=2;
        }
        while ((c = *pp++) != 0)
        {   if (c == ' ') std::putc('\\', f); // for spaces in file-name
            std::putc(c == '\\' ? '/' : c, f);
        }
        std::putc(' ', f);
        std::putc('\\', f);
        std::putc('\n', f);
    }
    std::putc('\n', f);
    std::putc('\n', f);
// Now I put in empty rules for each file that was used... By having
// rules with no prerequisites and no recipes I avoid trouble
// when files get moved.
    for (char *pp : dependency_map)
    {   if (pp[0] != 0 &&
            pp[1] == ':' &&
            (pp[2] == '/' || pp[2] == '\\'))
        {   std::fprintf(f, "/cygdrive/%c",
                         static_cast<char>(std::tolower(static_cast<unsigned char>(pp[0]))));
            pp+=2;
        }
        while ((c = *pp++) != 0)
        {   if (c == ' ') std::putc('\\', f); // for spaces in file-name
            std::putc(c == '\\' ? '/' : c, f);
        }
        std::fprintf(f, ":\n");
    }
    std::putc('\n', f);
    std::fclose(f);
    for (char *pp : dependency_map)
        delete [] pp;
    dependency_map.clear();
    dependency_file[0] = 0;
}

void my_exit()
{
// There are a range of places in the code where I feel I want to quite
// abruptly because some internal failure has arisen.
// However there are a number of issues!
// (a) I am imagining that Reduce as a whole may be being run from some
// surrounding software. In that case if Reduce suffers an internal failure
// I would rather I just exited Reduce rather than causing the surrounding
// code to quit. So I do not make my_exit merely a synomym for std::exit().
// (b) Reduce may have created several threads. To exit it cleanly as a whole
// each thread must terminate. The use of my_exit() could have arisen within
// any of those threads! In general there is no clean way to force thread
// termination, and exiting with a thread still alive can lead to an ugly
// diagnostic.
// (c) For use with emscripten I may well compile eveything with support
// for C++ exception handling disabled. That is because at the time of writing
// support for exceptions can have a very severe performance impact in that
// case. The pain may go away in due course with upgrades to the specification
// of "wasm" have arrived and filtered through to all toolchains and browsers!
// Note that "not supporting exceptions" allows "throw" to happen and unwinds
// the stack. But "catch" will be ineffective and destruction of objects
// created in functions that are on the stack will not happen (so RAII will
// fail in the exception context).
//
// The approach I take is to make "my_exit()" throw std::runtime_error,
// In the emscripten canse if I have built without exception support that
// quits my application but reports the uncaught exception. I am in an error
// situation so I will not worry!
// If exceptions are being supported I will catch the exception at
// the top level of my entry point (eg often "main()") and return failure
// as a return code. Each thread will start with a try block that can catch
// this exception - if it does so it will exit in as best a way it can to
// try to get the main thread to invoke my_exit(). If I can see a decent way
// in which the main thread terminating can close down all other threads I
// will do that. It is probably very hard if some other thread is stalled
// waiting on some semaphore or external trigger!
//
// I need to distinguish between my_exit() which is called in cases that
// represent system errors from Lstop1() which is what arises if the user
// attempts to exit. Lstop1() will "throw an exception" - I put that phrase
// in quotes because for the benefit of emscripten that might be just setting
// a flag and exiting so as to have a software simulated exception scheme.
// In a thread that can terminate the thread. In the main program it has to
// led to the code as a whole stopping.
    throw std::runtime_error("CSL internal issue");
}

static int return_code = 0;
bool segvtrap = true;
bool batch_flag = false;
bool ignore_restart_fn = false;

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
{   const char *f1 = std::strrchr(file, '/');
    if (f1 != nullptr) f1++;
    else f1 = file;
    if (data != nullptr)
    {   std::strncpy(debug_trail[debug_trailp], data, 32);
        std::strncpy(debug_trail_file[debug_trailp], f1, 32);
        debug_trail_line[debug_trailp] = line;
        debug_trailp = (debug_trailp+1)%32;
    }
}

void debug_record_int_raw(const char *data, int n, const char *file,
                          int line)
{   const char *f1 = std::strrchr(file, '/');
    if (f1 != nullptr) f1++;
    else f1 = file;
    if (data != nullptr)
    {   std::sprintf(debug_trail[debug_trailp], "%s%d", data, n);
        std::strncpy(debug_trail_file[debug_trailp], f1, 32);
        debug_trail_line[debug_trailp] = line;
        debug_trailp = (debug_trailp+1)%32;
    }
}

void debug_show_trail_raw(const char *msg, const char *file, int line)
{   int i;
    const char *f1 = std::strrchr(file, '/');
    if (f1 == nullptr) f1 = "?";
    else f1++;
    std::printf("\n+++++ Debug trail %s\n", msg);
    for (i=0; i<32; i++)
    {   if (debug_trail[debug_trailp][0] == 0) continue;
        std::printf("%d: %.32s at %.32s:%d\n", i, debug_trail[debug_trailp],
                    debug_trail_file[debug_trailp], debug_trail_line[debug_trailp]);
        debug_trailp = (debug_trailp+1)%32;
    }
    std::printf("Current at %s:%d", f1, line);
    std::fflush(stdout);
}

#endif

bool stop_on_error = false;

static LispObject lisp_main()
{
// As of mid-November 2020 CSL will deliver IEEE infinity for 1.0/0.0 and
// a NaN for 0.0/0.0 rather than raising an exception.
    trap_floating_overflow = false;
    tty_count = 0;
    while (true)
// The sole purpose of the while loop here is to allow me to proceed
// for a second try if I get a (cold-start) call.
    {   errorset_msg = nullptr;
        TRY
            terminal_pushed = NOT_CHAR;
            if (supervisor != nil && !ignore_restart_fn)
            {   miscflags |= BACKTRACE_MSG_BITS;
// Here I reconstruct the argument that I passed in (restart_csl f a).
                if (exit_charvec != nullptr)
                {   LispObject a;
                    TRY
                        a = read_from_vector(exit_charvec);
// If I fail to read the saved data "a" back I will just fold it down and
// use nil instead.
                    CATCH(LispException) // all sorts of Lisp issues!
                        a = nil;
                    END_CATCH
                    delete [] exit_charvec;
                    exit_charvec = nullptr;
                    apply(supervisor, ncons(a), nil, current_function = startup_symbol);
                }
                else apply(supervisor, nil, nil, current_function = startup_symbol);
            }
// Here the default read-eval-print loop used if the user has not provided
// a supervisor function.
            else read_eval_print(lisp_true);
        CATCH(LispException)
            if (exit_reason == UNWIND_RESTART)
            {   if (exit_tag == fixnum_of_int(0))      // "stop"
                    return_code = static_cast<int>(int_of_fixnum(exit_value));
                else if (exit_tag == fixnum_of_int(1)) // "preserve"
                {   const char *msg = "";
                    int len = 0;
                    return_code = EXIT_SUCCESS;
                    if (is_vector(exit_value) &&
                        is_string(exit_value))
// celt returns a vector of atomic characters but here I need to treat that
// as just plain characters. Casting away the std<<atomic> stuff is liable
// to be evil (eg wrt strict aliasing rules)!
                    {   msg = reinterpret_cast<const char *>(&celt(exit_value, 0));
                        len = static_cast<int>(length_of_byteheader(vechdr(
                                                   exit_value)) - CELL);
                    }
                    RAIIsave_codevec save;
                    preserve(msg, len);
                }
                else if (exit_tag == fixnum_of_int(3)) // "preserve & restart"
                {   const char *msg = "";
                    int len = 0;
                    int32_t fd = stream_pushed_char(lisp_terminal_io);
                    Lrds(nil, nil);
                    Lwrs(nil, nil);
                    return_code = EXIT_SUCCESS;
                    if (is_vector(exit_value) &&
                        is_string(exit_value))
                    {   msg = reinterpret_cast<const char *>(&celt(exit_value, 0));
                        len = static_cast<int>(length_of_byteheader(vechdr(
                                                   exit_value)) - CELL);
                    }
                    {   RAIIsave_codevec save;
                        preserve(msg, len);
                    }
#ifdef CONSERVATIVE
// I believe that this is all to abandon all existing in-use pages and
// put things back as if all memory is totally empty.
// NOT DONE in the conservative case yet. @@@@@
#else
                    for (size_t i=0; i<pages_count; i++)
                    {   char *w = reinterpret_cast<char *>(pages[i]);
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            continue;
                        pages[i] = pages[--pages_count];
                        i--;
                    }
                    while (vheap_pages_count != 0)
                    {   char *w = reinterpret_cast<char *>
                                  (vheap_pages[--vheap_pages_count]);
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    while (heap_pages_count != 0)
                    {   char *w = reinterpret_cast<char *>
                                  (heap_pages[--heap_pages_count]);
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    {   char *w = big_chunk_start + NIL_SEGMENT_SIZE;
                        char *w1 = w + CSL_PAGE_SIZE;
                        while (w1 <= big_chunk_end)
                        {   if (w != reinterpret_cast<char *>(stacksegment))
                                pages[pages_count++] = w;
                            w = w1;
                            w1 = w + CSL_PAGE_SIZE;
                        }
                    }
                    IreInit();
#endif // CONSERVATIVE
                    setup(1, 0.0); // warm start mode
                    exit_tag = exit_value = nil;
                    exit_reason = UNWIND_NULL;
                    stream_pushed_char(lisp_terminal_io) = fd;
                    continue;
                }
                else                                   // "restart"
                {   int32_t fd = stream_pushed_char(lisp_terminal_io);
                    char new_module[64], new_fn[64]; // Limited name length
                    int cold_start;
                    cold_start = (exit_value == nil);
// Of course a tick may very well have happened rather recently - so
// I will flush it out now just to clear the air.
                    if ((stack+event_flag.load()) >= stackLimit) respond_to_stack_event();
                    cold_start = (exit_value == nil);
                    Lrds(nil, nil);
                    Lwrs(nil, nil);
// If either of the above two calls to rds/wrs were to fail I would
// be in a big mess.
                    if (!cold_start)
                    {   new_module[0] = 0;
                        new_fn[0] = 0;
                        if (exit_value != lisp_true)
                        {   LispObject modname = nil;
                            if (is_cons(exit_value))
                            {   modname = car(exit_value);
                                exit_value = cdr(exit_value);
                                if (is_cons(exit_value))
                                    exit_value = car(exit_value);
                            }
                            if (symbolp(modname) && modname != nil)
                            {   modname = get_pname(modname);
                                Header h = vechdr(modname);
                                int32_t len = length_of_byteheader(h) - CELL;
                                if (len > 63) len = 63;
                                std::memcpy(new_module,
                                            reinterpret_cast<char *>(modname) + (CELL - TAG_VECTOR),
                                            (size_t)len);
                                new_module[len] = 0;
                            }
                            if (symbolp(exit_value) && exit_value != nil)
                            {   exit_value = get_pname(exit_value);
                                Header h = vechdr(exit_value);
                                int32_t len = length_of_byteheader(h) - CELL;
                                if (len > 63) len = 63;
                                std::memcpy(new_fn,
                                            reinterpret_cast<char *>(exit_value) + (CELL - TAG_VECTOR),
                                            (size_t)len);
                                new_fn[len] = 0;
                            }
                        }
                    }
#ifdef CONSERVATIVE
// @@@@@
#else // CONSERVATIVE
// This puts all recorded heap pages back in the main pool.
                    for (size_t i=0; i<pages_count; i++)
                    {   char *w = reinterpret_cast<char *>(pages[i]);
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            continue;
// Here the page shown as free is one in the contiguous block. Move in
// the final page to fill the gap here and try again.
                        pages[i] = pages[--pages_count];
                        i--;
                    }
// Next recycle all the non-contiguous pages that have been in use.
                    while (vheap_pages_count != 0)
                    {   char *w = reinterpret_cast<char *>
                                  (vheap_pages[--vheap_pages_count]);
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
                    while (heap_pages_count != 0)
                    {   char *w = reinterpret_cast<char *>
                                  (heap_pages[--heap_pages_count]);
                        if (!(w > big_chunk_start && w <= big_chunk_end))
                            pages[pages_count++] = w;
                    }
// Finally rebuild a contiguous block of pages from the wholesale block.
                    {   char *w = big_chunk_start + NIL_SEGMENT_SIZE;
                        char *w1 = w + CSL_PAGE_SIZE;
                        while (w1 <= big_chunk_end)
                        {   if (w != reinterpret_cast<char *>(stacksegment))
                                pages[pages_count++] = w;
                            w = w1;
                            w1 = w + CSL_PAGE_SIZE;
                        }
                    }
#endif // CONSERVATIVE
// When I call restart-csl I will leave the random number generator where it
// was. Anybody who wants to reset if either to a freshly randomised
// configuration or to a defined condition must do so for themselves. For
// people who do not care too much what I do here is probably acceptable!
                    IreInit();
                    setup(cold_start ? 0 : 1, 0.0);
                    exit_tag = exit_value = nil;
                    exit_reason = UNWIND_NULL;
                    stream_pushed_char(lisp_terminal_io) = fd;
                    if (!cold_start && new_fn[0] != 0)
                    {   LispObject w;
                        if (new_module[0] != 0)
                        {   w = make_undefined_symbol(new_module);
                            Lload_module(nil, w);
                        }
                        supervisor = make_undefined_symbol(new_fn);
                    }
                    continue;
                }
            }
        END_CATCH
// In all normal cases when read_eval_print exits (i.e. all cases except
// if it terminates after (cold-start)) I exit here.
        break;
    }
    return nil;
}

static long int initial_random_seed;


std::vector<stringBoolString> symbolsToDefine;
std::vector<stringBoolString> stringsToDefine;
std::vector<string> stringsToEvaluate;

size_t output_directory;
character_reader *procedural_input;
character_writer *procedural_output;

int init_flags = 0;

#ifdef WITH_GUI
std::FILE *alternative_stdout = nullptr;
#endif // WITH_GUI

// standard_directory holds the name of the default image file that CSL
// would load.
const char *standard_directory;

// If non-empty the string module_enquiry is a name presenetd on the
// command line in a "-T name" request, and this will cause the system
// to behave in a totally odd manner - it does not run Lisp at all but
// performs a directory enquiry within the image file.
static string module_enquiry;

int errorset_min = 0, errorset_max = 3;

int load_count = 0, load_limit = 0x7fffffff;

int csl_argc;
const char **csl_argv;

bool restartp;

uintptr_t C_stacklimit = 0;
double max_store_size = 0.0;

#ifndef HAVE_CILK
std::thread kara_thread[2];
std::mutex kara_mutex;
std::condition_variable cv_kara_ready, cv_kara_done;
unsigned int kara_ready = 0;
int kara_done = 0;
#endif

// I am also putting the following segment in a separate file in case I want
// to use a (potentially customized) version of it elsewhere...

// Usage:
//   void setupArgs(argSpec vec[], int argc, const char *argv[]);
// where vec is a vector whose elements esch specify a possible argument
// format and provide an action to perform if it is seen in
// argv. Args that are either just "-" or that do not start with a "-"
// end up in simpleArgs while ones that do start with "-" but are not
// recognized are placed in badArgs.

// Arguments of the form "-x" for any single letter x might have an
// associated value which can be written as either "-xVAL" or "-x VAL".
// Well that is not good in the case "-w" because I want "-w" on its own to
// be valid but also "-w+" and "-w-", so what about "-w -"? Well that needs
// to be treated as "-w" on its own followed be a quite separte argument "-"
// which indicated an input source.
// Arguments written in the form "--word" can have an associated value
// either as "--word=VAL" or "--word VAL".
// As a special case "--args" terminates scanning.

typedef void argAction(string key, bool takesVal, string value);

struct argSpec
{   const char *name;      // e.g. "-x" or "--word".
    bool takesVal;         // Either "-xNN" or maybe "-x NN" will be valid.
    bool takesSeparateVal; // "-x NN" is valid as well as "-xNN".
    string help;      // e.g. "-k NN  Set memory allocation to NN."
    std::function<void(string,bool,string)>action;
    // procedure to call when this case arises.
};

static std::unordered_map<string, argSpec *> argIndex;

// All command-line items that do not begin with "-" are collected in the
// vector simpleArgs[]. They will be treated as names of files to be
// read from. Also an isolated "-" is treated this way so it can be used
// to indicate a default value.

static std::vector<string> simpleArgs;

// If an item is not recognized I will collect it here. This will also
// apply if an item does not expect an associated value but is provided
// with one. If an item is expecting a value but nothing is provided it
// will just use the empty string "".

static std::vector<string> badArgs;

void setupArgs(argSpec *v, int argc, const char *argv[])
{   argIndex.clear(); // Just to be safe!
    simpleArgs.clear();
    badArgs.clear();
// I start by putting all the key values into my unordered_map.
    for (int i=0; v[i].name != nullptr; i++)  argIndex[v[i].name] = &v[i];
// Now scan the arguments.
    for (int i=1; i<argc && argv[i]!=nullptr; i++)
    {   string a(argv[i]);       // The next argument provided
        string aSave(a);
        if (a.compare("--args") == 0) break;
        string val;
        bool hasVal = false;
        if (a[0] == '-' && a[1] != 0)
        {   if (a[1] == '-')            // Here I have "--word"
            {   auto pos = a.find('=');
                if (pos != string::npos) //       "--word=VAL"
                {   val = a.substr(pos+1);
                    hasVal = true;
                    a = a.substr(0, pos);
                }
            }
            else                 // Here I have "-x"
            {   if (a[1] != 0 && a[2] != 0)
                {   val = a.substr(2);  //             "-xVAL"
                    hasVal = true;
                    a = a.substr(0, 2);
                }
            }
        }
        else
        {   simpleArgs.push_back(a); // No initial "-" (or JUST "-").
            continue;
        }
        argSpec *aspec;
        string aLow(a);
        std::transform(aLow.begin(), aLow.end(), aLow.begin(),
                       [](int c)
                       {   return std::tolower(c);
                       });
        aspec = argIndex[aLow];
        if (aspec == nullptr)
        {   badArgs.push_back(aSave); // Item not recognized at all.
            continue;
        }
// If the keyword takes a "value" then if there is another item on the command
// line and that does not start with "-" then that will be used as the
// operand. Otherwise an empty string will be used.
        if (aspec->takesVal)
        {   if (!hasVal && aspec->takesSeparateVal)
            {   if (i+1 < argc &&
                    (argv[i+1][0] != '-' ||
                     argv[i+1][1] == 0))     // Permit "-" as value.
                {   val = argv[++i];
                    hasVal = true;
                }
                else val = "";
            }
        }
// But if you have something like "--word=VAL" and --word is not expecting
// an associated value I will put the argument on my list of bad items. The
// same is the case for "-xVAL" for a single-letter option x where  a value
// is not wanted.
        else if (hasVal)
        {   badArgs.push_back(aSave);
            continue;                  // Ignore item.
        }
// Now invoke the action that this calls for.
        (aspec->action)(a, hasVal, val);
    }
}

bool timeTestCons = false;

#ifndef AVOID_THREADS

// I have some background threads to help me, so here is the code to start
// them up. It seems to be important to terminate detached threads (or join
// with regular ones) before quitting, so I also cope with that.

// Everybody needs to create an instance of this and keep it alive until
// CSL is ready to exit.

class KaratsubaThreads
{
public:
    KaratsubaThreads()
    {
#ifndef HAVE_CILK
// If CILK is available then the concurrency is expressed using its
// higher level constructs. Otherwise I will do the thread creation
// and coordination myself.
        kara_ready = kara_done = 0;
        for (int i=0; i<2; i++)
        {   kara_thread[i] = std::thread(kara_worker, i);
            kara_thread[i].detach();
        }
#endif
    }
    ~KaratsubaThreads()
    {
#ifndef HAVE_CILK
        {   std::lock_guard<std::mutex> lk(kara_mutex);
            kara_ready = KARA_0 | KARA_1 | KARA_QUIT;
            kara_done = 0;
        }
        cv_kara_ready.notify_all();
#endif
    }
};

#endif //AVOID_THREADS

char *mystrdup(const char *s)
{   char *r = new char[std::strlen(s)+1];
    std::strcpy(r, s);
    return r;
}

// Note that I will not have my signal handlers active during the call
// to cslstart(), so 

void cslstart(int argc, const char *argv[], character_writer *wout)
{   double store_size = 0.0;
// I make "sp" volatile - it is a variable I declare here but then only use by
// taking its address to get a pointer into the current stack-frame. When it
// is volatile my compiler will not be entitled to moan about the lack of
// assignment to it and will not be entitled to optimise it out of existance
// or otherwise do things that run against my intent! But then to put its
// address in C_stackbase I need to cast away the volatile qualifier.
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    C_stacklimit = 0;
    max_store_size = 0.0;
    karatsuba_parallel = 0x7fffffff;

#ifdef EMBEDDED
// This provides a fixed limit in the embedded build
    C_stacklimit = (uintptr_t)C_stackbase - 2*1024*1024 + 0x10000;
#else // EMBEDDED
#ifdef WIN32
    {   HMODULE h = GetModuleHandle(nullptr); // For current executable
        if (h != nullptr)
        {   IMAGE_DOS_HEADER *dh = (IMAGE_DOS_HEADER*)h;
            IMAGE_NT_HEADERS *NTh =
                (IMAGE_NT_HEADERS*)((BYTE*)dh + dh->e_lfanew);
            int64_t stackLimit =
                (int64_t)NTh->OptionalHeader.SizeOfStackReserve;
// If the limit recovered above is under 200K I will pretend it is
// just plain wrong and increase it to that. The effect may be that I
// end up with an untidy stack overflow but at least I get closer to
// using all the space that I have.
            if (stackLimit < 200*1024) stackLimit = 200*1024;
// I also assume that any figure over 20 Mbytes is a mess so ignore it
            if (stackLimit <= 20*1024*1024)
            {   // I try to give myself 64K spare...
                C_stacklimit = (uintptr_t)C_stackbase - stackLimit + 0x10000;
            }
        }
    }
#else // WIN32
#ifdef HAVE_SYS_RESOURCE_H
    {   struct rlimit r;
        if (getrlimit(RLIMIT_STACK, &r) == 0)
        {   int64_t stackLimit = (int64_t)r.rlim_cur;
// If the user has used ulimit to remove all stack limits I will
// nevertheless apply one at 20 Mbytes. That is SO much higher than any
// default as to not hurt ordinary people - and if anybody NEEDS gigabytes
// of stack they need to ensure that getrlimit returns a finite indication
// of that! Results of RLIM_SAVED_MAX represent a sort of "give up" from
// getrlimit so I will treat them as failure.
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
            {   C_stacklimit = (uintptr_t)C_stackbase - stackLimit + 0x10000;
            }
        }
    }
#endif // HAVE_SYS_RESOURCE_H
#endif // WIN32
// If I can not read a value then I will set a limit at 4 Mbytes...
    if (C_stacklimit == 0)
    {   C_stacklimit = (uintptr_t)C_stackbase - 4*1024*1024 + 0x10000;
    }
#endif // EMBEDDED

#ifdef EMBEDDED
    fwin_set_lookup(look_in_lisp_variable);
#endif
    errorset_min = 0;
    errorset_max = 3;
    stack_segsize = 1;
    module_enquiry = "";
// put resource limiting info in a tidy or at least safe state
    time_base  = space_base  = io_base  = errors_base  = 0;
    time_now   = space_now   = io_now   = errors_now   = 0;
    time_limit = space_limit = io_limit = errors_limit = -1;
    base_time = read_clock();
    base_walltime = std::chrono::high_resolution_clock::now();
    gc_time = 0.0;
    fwin_pause_at_end = true;
// Now that the window manager is active I can send output through
// xx_printf() and get it on the screen neatly.
    procedural_input = nullptr;
    procedural_output = wout;
    standard_directory = find_image_directory(argc, argv);
    restartp = true;
    ignore_restart_fn = false;
    spool_file = nullptr;
    spool_file_name[0] = 0;
    output_directory = 0x80000000u;
    fasl_output_file = false;
    initial_random_seed = 0;
    init_flags = INIT_EXPANDABLE;
    return_code = EXIT_SUCCESS;
    segvtrap = true;
    batch_flag = false;
    load_count = 0;
    load_limit = 0x7fffffff;

// I save the args so that setup can make a lisp variable out of them
    csl_argc = argc;
    csl_argv = argv;

    std::vector<string> tracedFunctions;

    {   argSpec *argTableP;
        argSpec argTable[] =
        {   /*! options [--] \item [{\ttfamily --}] \index{{\ttfamily --}}
             * If the application is run in console mode then its standard output could
             * be redirected to a file using shell facilities. But the {\ttfamily --}
             * directive (followed by a file name) redirects output within the Lisp rather
             * than outside it. If this is done a very limited capability for sending
             * progress or status reports to stderr (or the title-bar when running in
             * windowed  mode) remains via the {\ttfamily report!-right} function.
             *
             * The {\ttfamily -w} option may frequently make sense in such cases,
             * but if that is not used and the system tries to run in a window it will
             * create it starting off minimised.
             */
            {   "--", true, true,
                "-- NAME  Redirect output to the given file so it does not appear\n"
                "         on the screen.",
// -- <outfile> arranges that output is sent to the indicated file. It is
// intended to behave a little like "> outfile" as command-line output
// redirection, but is for use in windowed environments (in particular
// Windows NT) where this would not work.
// So              -- filename
// redirects the standard output to the named file.
                [&](string key, bool hasVal, string val)
                {   if (!hasVal || val.length() == 0)
                    {   badArgs.push_back(key);
                        return;
                    }
                    char filename[LONGEST_LEGAL_FILENAME];
                    std::FILE *f;
                    std::memset(filename, 0, sizeof(filename));
#ifdef WITH_GUI
                    f = open_file(filename, val.c_str(), val.length(), "w", nullptr);
                    if (f == nullptr)
                    {
// Under FWIN if there is a "--" among the arguments I will start off
// with the main window minimized. Thus if an error is detected at a
// stage that the transcript file is not properly opened I need to
// maximize the window so I can see the error! Note that I will need to
// ensure that fwin only uses "-- file" not "--option" to do this...
                        fwin_restore();
                        term_printf("Unable to write to \"%s\"\n", filename);
                        return;
                    }
                    else
                    {   term_printf("Output redirected to \"%s\"\n",
                                    filename);
                    }
                    if (alternative_stdout != nullptr)
                        std::fclose(alternative_stdout);
                    alternative_stdout = f;
#else // !WITH_GUI
// I use freopen() on stdout here to get my output sent elsewhere.  Quite
// what sort of mess I am in if the freopen fails is hard to understand!
// Thus I write a message to stderr and exit promptly in case of trouble.
// I print a message explaining what I am doing BEFORE actually performing
// the redirection.
                    std::fprintf(stderr, "Output to be redirected to \"%s\"\n",
                                 val.c_str());
                    f = open_file(filename, val.c_str(), val.length(), "w", stdout);
                    if (f == nullptr)
                    {   std::fprintf(stderr, "Unable to write to \"%s\"\n",
                                     filename);
                        my_exit();
                    }
#endif // !WITH_GUI
                }
            },

            /*! options [--help] \item [{\ttfamily --help}] \index{{\ttfamily --help}}
             * It is probably obvious what this option does! Note that on Windows the
             * application was linked as a windows binary so it carefully creates a
             * console to display the help text in, and organizes a delay to give
             * people a chance to read it.
             */
            {   "--help", false, false,
                "--help   Generate this text.",
                [&](string key, bool hasVal, string val)
                {   std::vector<string>helpText;
                    for (auto a=argTableP; a->name!=nullptr; a++)
                        helpText.push_back(a->help);
                    std::sort(helpText.begin(), helpText.end());
#ifdef HAVE_LIBWX
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
                    helpText.push_back(
                        "This software contains code that is subject to the LaTeX Project\n"
                        "Public License. In accordance with Clause 6 of that (which governs\n"
                        "distribution, there are README in a directory called wxfonts or\n"
                        "reduce.wxfonts present as part of this distribution that explain\n"
                        "both changes that have been made and where to obtain copies of\n"
                        "relevant complete, unmodified original font-related material.\n");
#endif
                    term_printf("Options:\n");
                    for (auto s:helpText)
                    {   for (char &c : s) char_to_terminal(c, 0);
                        char_to_terminal('\n', 0);
                    }
                    std::exit(EXIT_SUCCESS);
                }
            },

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
            {   "-k", true, true,
                "-k nnnK or -knnnM or -knnnG Suggest heap-size to use.\n"
                "         -knnn/ss sets the Lisp stack to use ss chunks each of which\n"
                "         is large enough that this option is basically never needed!\n"
                "         Since the system auto-expands memory as it needs to it is very\n"
                "         rare to need to use this option. See also --maxmem",
                [&](string key, bool hasVal, string val)
                {   if (!hasVal || val.length() == 0)
                    {   badArgs.push_back(key);
                        return;
                    }
// val should be a string of the form
//              nnnK   nnnM or nnnG
//              nnnK/mm
// where nnn indicates (approximately) the desired amount of memory in
// kilobytes, magabytes or gigabytes (default megabytes) and mm is a feature
// that is deprecated and will be removed soon but that might set the
// size of the Lisp stack segment in the range 1-10. It to be legal to
// express nnn as a floating point value, as in 2.5G. That may lead to be
// allowing 1.0e5K as well, which would perhaps seem an eccentric way of
// providing input unless I allow plain numbers without a K, M or G suffix
// to specify amounts in bytes, so that -K1.0e9 and -K1G are treated
// as meaning the same thing. Ignore case in the specifier.
                    string valLow(val);
                    std::transform(valLow.begin(), valLow.end(), valLow.begin(),
                                   [](int c)
                    {   return std::tolower(c);
                    });
                    const char *valS = valLow.c_str();
                    double valD;
                    int valI = 1;
                    unsigned int len=std::strlen(valS), pos;
// This is not an especially tidy way of parsing this, but I think it is
// easy to understand. It uses sscanf to check each potential valid input
// format and the "%n" in there is used to confirm that sscanf had used up
// all the characters in the input.
                    if (std::sscanf(valS, "%lg%n", &valD, &pos)==1 && pos==len)
                    {
                    }
                    else if (std::sscanf(valS, "%lgk%n", &valD, &pos)==1 && pos==len)
                    {   valD *= 1024.0;
                    }
                    else if (std::sscanf(valS, "%lgm%n", &valD, &pos)==1 && pos==len)
                    {   valD *= 1024.0*1024.0;
                    }
                    else if (std::sscanf(valS, "%lgg%n", &valD, &pos)==1 && pos==len)
                    {   valD *= 1024.0*1024.0*1024.0;
                    }
                    else if (std::sscanf(valS, "%lg/%u%n", &valD, &valI, &pos)==2 &&
                             pos==len)
                    {
                    }
                    else if (std::sscanf(valS, "%lgk/%u%n", &valD, &valI, &pos)==2 &&
                             pos==len)
                    {   valD *= 1024.0;
                    }
                    else if (std::sscanf(valS, "%lgm/%u%n", &valD, &valI, &pos)==2 &&
                             pos==len)
                    {   valD *= 1024.0*1024.0;
                    }
                    else if (std::sscanf(valS, "%lgg/%u%n", &valD, &valI, &pos)==2 &&
                             pos==len)
                    {   valD *= 1024.0*1024.0*1024.0;
                    }
                    else
                    {   badArgs.push_back(key.append(val));
                        return;
                    }
// Negative requests or requests for more than 256Gbytes (or requests for
// zero or more than 10 stack chunks) will be rejected.
                    if (valD <= 0 || valD >= 256.0e9 ||
                        valI < 1 || valI > 10)
                    {   badArgs.push_back(key.append(val));
                        return;
                    }
// If a user specifies an amount without a K, M or G suffix and it is
// no greater then 32 million than I will treat it as if it has a suffix M.
// So for instance -K128 will ask for 128 Mbytes. And a value up to 32
// and without a suffix will be treated as Gigabytes
                    if (valD <= 32.0) valD *= 1024.0*1024.0*1024.0;
                    else if (valD <= 32.0e6) valD *= 1024.0*1024.0;
                    store_size = valD;
                    stack_segsize = valI;
                }
            },


            /*! options [--cygwin] \item [{\ttfamily --cygwin}] \index{{\ttfamily --cygwin}}
             * On Windows this flag is used to specify that a cygwin rather that a native
             * windows version of Reduce is needed. This can be the situation in some
             * cases where the foreign function interface is to be used.
             */
            {   "--cygwin", false, false,
                "--cygwin [on Windows] Try to use the cygwin version of Reduce rather\n"
                "         than a native Windows version, regardless of other circumstances.",
                [&](string key, bool hasVal, string val)
                {
                }
            },

            /*! options [--wait] item [{ttfamily --wait}] index{{ttfamily --wait}}
             * This displays the process number and waits for 15 seconds at the
             * start of a run. This may be useful for those who have built everything
             * with debugging options and then want to start it fairly normally and
             * then attach from gdb or some other debugger.
             */
            {   "--wait", false, false,
                "--wait   Pause for 15 second before starting anything.\n"
                "         This may be useful for those who want to attach a debugger to\n"
                "         during that time, so provided there is a console availabe\n"
                "         the process number will be displayed on the standard output.",
                [&](string key, bool hasVal, string val)
                {   std::printf("Process identifier = %d\r\n", getpid());
                    std::printf("Waiting 15 seconds in case you want to attach\r\n");
                    std::printf("from gdb or some other debugger...\r\n");
                    std::fflush(stdout);
                    std::this_thread::sleep_for(std::chrono::seconds(15));
                    std::printf("... continuing\r\n");
                    std::fflush(stdout);
                }
            },

            /*! options [-w] \item [{\ttfamily -w}] \index{{\ttfamily -w}}
             * On a typical system if the system is launched it creates a new window and uses
             * its own windowed intarface in that. If it is run such that at startup the
             * standard input or output are associated with a file or pipe, or under X the
             * variable {\ttfamily DISPLAY} is not set it will try to start up in console
             * mode. The flag {\ttfamily -w} indicates that the system should run in console
             * more regardless, while {\ttfamily -w+} attempts a window even if that seems
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
             *
             * The option is in fact processed at an earlier stage then here if windowing
             * is possible at all!
             */

            {   "-w", true, false,
                "-w or -w+ or -w- When using a platform that supports a windowed mode\n"
                "         -w or -w- forces the system to fall back to console mode, while -w+\n"
                "         forces use of the GUI even when other issues might have inhibited it.",
                [&](string key, bool hasVal, string val)
                {   // Detected and processed by the GUI layer before we get here, so
                    // no action is needed at this stage.
                }
            },

            /*! options [--texmacs] \item [{\ttfamily --texmacs}] \index{{\ttfamily --texmacs}}
             * If CSL/Reduce is launched from texmacs this command-line flag should be
             * used to arrange that the {\ttfamily texmacs} flag is set in
             * {\ttfamily lispsystem!*}, and the code may then do special things.
             */
            {   "--texmacs", false, false,
                "--texmacs Run in texmacs mode. You must use the plugin from the\n"
                "         cslbase/texmacs-plugin directory.",
                [&](string key, bool hasVal, string val)
                {   // Detected and processed by the GUI layer before we get here, so
                    // no action is needed at this stage.
                }
            },

            /*! options [--no-rcfile] \item [{\ttfamily --no-rcfile}] \index{{\ttfamily --no-rcfile}}
             * Instruct the system not to read a user-specific configuation file, which
             * make have such a names as ``{\ttfamily .reducerc}'', at startup time. This
             * can be useful during system building where utterly self-contained and
             * predictable behaviour is important.
             */
            {   "--no-rcfile", false, false,
                "--no-rcfile Sets the Lisp variable no_init_file which for Reduce arranges\n"
                "         that any file $HOME/.reducerc is ignored rather than read",
                [&](string key, bool hasVal, string val)
                {   symbolsToDefine.push_back(
                        stringBoolString("no_init_file", true, ""));
                }
            },

            /*! options [--gui] \item [{\ttfamily --gui}] \index{{\ttfamily --gui}}
             * Encourage the system to run in its own window. Similar behaviour
             * to {\ttfamily -w+}.
             */
            {   "--gui", false, false,
                "--gui    Use a windowed interface if possible. Equivalent to \"-w+\".",
                [&](string key, bool hasVal, string val)
                {
                }
            },

            /*! options [--nogui] \item [{\ttfamily --nogui}] \index{{\ttfamily --nogui}}
             * Encourage the system to run as a console-style application. Similar
             * to {\ttfamily -w-} or just simply {\ttfamily -w}.
             */
            {   "--nogui", false, false,
                "--nogui  Use a console-mode interface (not a windowed one), Equivalent to \"-w-\".",
                [&](string key, bool hasVal, string val)
                {
                }
            },

            /*! options [--guimin] \item [{\ttfamily --guimin}] \index{{\ttfamily --guimin}}
             * Encourage the system to run as in its own window, but
             * start that window off minimised. Similar
             * to {\ttfamily -w.}.
             */
            {   "--guimin", false, false,
                "--guimin Start up with window for the interface minimised. Equivalent to \"-w.\".",
                [&](string key, bool hasVal, string val)
                {
                }
            },

            /*! options [--gc-trigger] \item [{\ttfamily --gc-trigger}] \index{{\ttfamily --gc-trigger}}
             * --gc-trigger=NNNN causes a garbage collection to be forced on the NNNNth
             * occasion when that could possibly happen. This may sometimes be relevant
             * when trying to track down garbage collection related bugs. If the option
             * is set every garbage collection displays the count that it corresponds to,
             * and the intent is that these counts should be fairly deterministic.
             */
            {   "--gc-trigger", true, true,
                "--gc-trigger NN Force garbage collection to happen on the NNth time it\n"
                "         possibly could. Used when tracking garbage collection bugs and in\n"
                "         particular one that may arise when GC is triggered from some particular\n"
                "         context -- hence not useful for ordinary users.",
                [&](string key, bool hasVal, string val)
                {   char *end;
                    reclaim_trigger_target = std::strtoull(val.c_str(), &end, 10);
                }
            },

            /*! options [--stop-on-error] \item [{\ttfamily --stop-on-error}] \index{{\ttfamily --stop-on-error}}
             * This utterly defeats errorset and arranges that if there is any error that
             * after whatever backtrace might have been generated any inner errorset
             * just propagates the error out, and at the top level the system exits.
             */
            {   "--stop-on-error", false, false,
                "--stop-on-error  If any error arises then give up and stop.",
                [&](string key, bool hasVal, string val)
                {   stop_on_error=true;
                }
            },

            /*! options [--force-verbos] \item [{\ttfamily --force-verbos}] \index{{\ttfamily --force-verbos}}
             * Forces generation of messages from the garbage collector regardless of any
             * attempt from with the system to change that. Intended for use during system
             * debugging where it may be important to see when a garbage collection occurs
             * but undesirable to change the input script at all.
             */
            {   "--force-verbos", false, false,
                "--force-verbos Ensure that garbage collection messages are displayed.",
                [&](string key, bool hasVal, string val)
                {   force_verbos = true;
                }
            },

            /*! options [--force-echo] \item [{\ttfamily --force-echo}] \index{{\ttfamily --force-echo}}
             * Forces echoing of input regardless of any
             * attempt from with the system to change that. Intended for use during system
             * debugging where it may be important to observe progress through an
             * input file but undesirable to change the input script at all.
             */
            {   "--force_echo", false, false,
                "--force-echo Echo innput, regardless of system switches or other options.",
                [&](string key, bool hasVal, string val)
                {   force_echo = true;
                }
            },

            /*! options [--force-backtrace//--bt] \item [{\ttfamily --force-backtrace, --bt}] \index{{\ttfamily --force-backtrace, --bt}}
             * Forces any error to generate a backtrace regardless of any
             * attempt from with the system to change that (eg via use of errorset).
             * Intended for use during system  debugging where it may be important to
             * observe behaviour otherwise hidden by (errorset X nil nil) but when it
             * undesirable to change the input script at all.
             */
            {   "-force-backtrace", false, false,
                "--force-backtrace Always generate a backtrace after any error.",
                [&](string key, bool hasVal, string val)
                {   force_backtrace = true;
                }
            },

            {   "-force-bt", false, false,
                "--force-bt More concise version of --force-backtrace.",
                [&](string key, bool hasVal, string val)
                {   force_backtrace = true;
                }
            },

            /*! options [--version] \item [{\ttfamily --version}] \index{{\ttfamily --version}}
             * It is probably obvious what this option does! But note that there is an
             * issue here about whether one is looking at the CSL version identification or
             * one for the Lisp application from an image file (eg often Reduce).
             */
            {   "--version", false, false,
                "---version Display version information and stop.",
                [&](string key, bool hasVal, string val)
                {   term_printf(
#ifndef COMMON
                        "Codemist Standard Lisp revision %u for %s: %s\n",
#else
                        "Codemist Common Lisp revision %u for %s: %s\n",
#endif
                        REVISION, IMPNAME, __DATE__);
                    std::exit(EXIT_SUCCESS);
                }
            },

            /*! options [--maxmem] \item [{\ttfamily --maxmem}] \index{{\ttfamily --maxmem}}
             * Normally this code goes back to the operating system and requests more memory
             * at any time when it feels that would be useful.This option can be used to
             * set an approximate limit on the amount it will use. See also -k
             */
            {   "--maxmem", true, true,
                "--maxmem NNN Prevent memory expansion beyond NNN.",
                [&](string key, bool hasVal, string val)
                {   string valLow(val);
                    std::transform(valLow.begin(), valLow.end(), valLow.begin(),
                    [](int c)
                    {   return std::tolower(c);
                    });
                    const char *valS = valLow.c_str();
                    double valD;
                    unsigned int len=std::strlen(valS), pos;
// This is basically the same as the code used to decode "-kNNN".
                    if (std::sscanf(valS, "%lg%n", &valD, &pos)==1 && pos==len)
                    {
                    }
                    else if (std::sscanf(valS, "%lgk%n", &valD, &pos)==1 && pos==len)
                    {   valD *= 1024.0;
                    }
                    else if (std::sscanf(valS, "%lgm%n", &valD, &pos)==1 && pos==len)
                    {   valD *= 1024.0*1024.0;
                    }
                    else if (std::sscanf(valS, "%lgg%n", &valD, &pos)==1 && pos==len)
                    {   valD *= 1024.0*1024.0*1024.0;
                    }
                    else
                    {   badArgs.push_back(key.append(val));
                        return;
                    }
// Negative requests or requests for more than 256Gbytes (or requests for
// zero or more than 10 stack chunks) will be rejected.
                    if (valD <= 0 || valD >= 256.0e9)
                    {   badArgs.push_back(key.append(val));
                        return;
                    }
                    if (valD <= 32.0) valD *= 1024.0*1024.0*1024.0;
                    else if (valD <= 32.0e6) valD *= 1024.0*1024.0;
                    max_store_size = valD;
                }
            },

#ifndef AVOID_THREADS
            /*! options [--kara] \item [{\ttfamily --kara}] \index{{\ttfamily --kara}}
             * This it is intended for use by those maintaining CSL not for the general
             * public. By default long multiplication can use a threaded implementation
             * (to exploit multi-core machines). This happens when numbers get bigger
             * than some magic threshold.
             * This option allows one to override the default threshold so that
             * performance effects can be measured and the cut-off adjusted to suit the
             * machine involved.
             */
            {   "--kara", true, true,
                "---kara NN Set transition between single and multi-thread Karatsuba\n"
                "         multiplication.",
                [&](string key, bool hasVal, string val)
                {   char *end;
                    kparallel = static_cast<int>(
                        std::strtol(val.c_str(), &end, 10));
                    if (kparallel < KARATSUBA_CUTOFF) kparallel = KARATSUBA_CUTOFF;
                }
            },
#endif // AVOID_THREADS

            /*! options [--trace/--tr] \item [{\ttfamily --trace, --tr}] \index{{\ttfamily --trace, --tr}}
             * When followed by the name of a function this command-line option has and
             * effect as if (trace '(fname)) had been called at system start-up so that
             * all calls to the named function are reported to the user. Perhaps often to
             * be combined with --bt so that on any error a backtrace will get generated,
             * and used when an input script leads to failure and one wants to investigate
             * its behaviour without altering the script at all.
             */
            {   "--trace", true, true,
                "---trace NAME Sets up tracing on the names Lisp function.",
                [&](string key, bool hasVal, string val)
                {   tracedFunctions.push_back(val);
                }
            },

            {   "--tr", true, true,
                "---tr NAME Equivalent to \"--trace NAME\".",
                [&](string key, bool hasVal, string val)
                {   tracedFunctions.push_back(val);
                }
            },

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

            {   "-a", false, false,
                "- a       Causes the sense of the Lisp (batchp) function to be inverted.",
                [&](string key, bool hasVal, string val)
                {   batch_flag = true;
                }
            },

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
            {   "-b", true, false,
                "-b or -bCOLOURS Just \"-b\" sets black and white mode, while COLOURS\n"
                "         can be one of blacK, Red, Green, Yellow, blue, Magenta, Cyan\n"
                "         or White (with blue indicated by a lower case \"b\" and black by\n"
                "         a \"k\" for each of output, input and prompts.",
                [&](string key, bool hasVal, string val)
                {   // Processed earlier by fwin.
                }
            },

            /*! options [-c] \item [{\ttfamily -c}] \index{{\ttfamily -c}}
             * Displays a notice relating to the authorship of CSL. Note that this
             * is an authorship statement not a Copyright notice, because if any
             * (L)GPL code is involved that would place requirements on what was
             * displayed in a Copyright Notice.
             */
            {   "-c", false, false,
                "-c       Display an authorship (but not a copyright) message that documents\n"
                "         the license under which this code is distributed.",
                [&](string key, bool hasVal, string val)
                {   fwin_restore();
                    term_printf("\nCSL was coded by A C Norman, Codemist, 1988-2021\n");
                    term_printf("Distributed under the Modified BSD License\n");
                    term_printf("See also --help\n");
                }
            },

            /*! options [-d] \item [{\ttfamily -d}] \index{{\ttfamily -d}}
             * A command line entry {\ttfamily -Dname=value} or {\ttfamily -D name=value}
             * sets the value of the named lisp variable to the value as a string.
             */
            {   "-d", true, true,
                "-d       -dNAME=VAL defines the symbol NAME to have the given value,\n"
                "         Note that when a value is given it will be passed as a string,\n"
                "         so \"-dN=3\" sets the variable N to the string \"3\". Use \"--d\"\n"
                "         if you want the value interpreted and converted.",
                [&](string key, bool hasVal, string val)
                {   string name, value;
                    auto n = val.find('=');
                    if (n == string::npos)
                    {   name = val;
                        value = "t";
                    }
                    else
                    {   name = val.substr(0, n);
                        value = val.substr(n+1);
                    }
                    stringsToDefine.push_back(stringBoolString(name, true, value));
                }
            },

            /*! options [-dd] \item [{\ttfamily -dd}] \index{{\ttfamily -dd}}
             * A command line entry {\ttfamily -Dname=value} or {\ttfamily -DD name=value}
             * sets the value of the named lisp variable to the value, interpreted as a
             * name, number, string etc using normal Lisp conventions. Cf -D which always
             * leaves the value as a string.
             */
            {   "-dd", true, true,
                "-dd      -dd NAME=VAL defines the symbol NAME to have the given value,\n"
                "         Note that when a value is given it will be passed through the\n"
                "         Lisp reader, so numbers and symbols can be generated.",
                [&](string key, bool hasVal, string val)
                {   string name, value;
                    auto n = val.find('=');
                    if (n == string::npos)
                    {   name = val;
                        value = "t";
                    }
                    else
                    {   name = val.substr(0, n);
                        value = val.substr(n+1);
                    }
                    symbolsToDefine.push_back(stringBoolString(name, true, value));
                }
            },

            /*! options [-e] \item [{\ttfamily -e}] \index{{\ttfamily -e}}
             * If you follow "-e" with a Lisp form then that gets evaluated and
             * its result printed during startup. This may be useful for forcing
             * settings or other debugging.
             */
            {   "-e", true, true,
                "-e       Can be followed by a Lisp form top be evaluated during startup.",
                [&](string key, bool hasVal, string val)
                {   if (val != "") stringsToEvaluate.push_back(val);
                }
            },

            /*! options [-f] \item [{\ttfamily -f}] \index{{\ttfamily -f}}
             * At one stage CSL could run as a socket server, and {\ttfamily -f portnumber}
             * activated that mode. {\ttfamily -f-} used a default port, 1206 (a number
             * inspired by an account number on Titan that I used in the 1960s). The code
             * that supports this may be a useful foundation to others who want to make a
             * network service out of this code-base, but is currently disabled.
             */
//                     -F
// No longer used, so SPARE!
// I *ONCE* had a scheme where Reduce could run as a remote server accessed
// via the network. That has not been used for a long while now and if
// something similar becomes needed in the future it should be re-implemented
// from the ground up. Here I will not even issue a complaint if somebody
// specifies "-f".
            {   "-f", false, false,
                "-f       Not in use.",
                [&](string key, bool hasVal, string val)
                {   timeTestCons = true; // Ha ha!
                }
            },


            /*! options [-g] \item [{\ttfamily -g}] \index{{\ttfamily -g}}
             * In line with the implication of this option for C compilers, this enables
             * a debugging mode. It sets a lisp variable {\ttfamily !*backtrace} and
             * arranges that all backtraces are displayed notwithstanding use of
             * {\ttfamily errorset}.
             */

            {   "-g", true, false,
                "-g       Set various options that may help with debugging.\n"
                "         -gw not only sets the options but delays by 15 seconds.",
                [&](string key, bool hasVal, string val)
                {   symbolsToDefine.push_back(
                        stringBoolString("*backtrace", true, "t"));
                    errorset_min = 3;
                    errorset_max = 3;
// -gw switches on debugging and also causes a 5-second pause before the code
// really gets going. The intent of this pause is so that a debugger can start
// and perhaps have time to attach to the task.
                    if (val == "w")
                    {   std::printf("Process identifier = %d\r\n", getpid());
                        std::printf("Waiting 15 seconds in case you want to attach\r\n");
                        std::printf("from gdb or some other debugger...\r\n");
                        std::fflush(stdout);
                        std::this_thread::sleep_for(std::chrono::seconds(15));
                        std::printf("... continuing\r\n");
                        std::fflush(stdout);
                    }
                }
            },

            /*! options [-h] \item [{\ttfamily -h}] \index{{\ttfamily -h}}
             * This option is a left-over. When the X-windows version of the code first
             * started to use Xft it viewed that as optional and could allow a build even when
             * it was not available. And then even if Xft was detected and liable to be used
             * by default it provided this option to disable its use. The remnants of the
             * switch that disabled use of Xft (relating to fonts living on the Host or
             * the Server) used this switch, but it now has no effect.
             */
#ifndef HAVE_LIBWX
// If I am using wxWidgets this option is not supported.
#endif
// Actually, like the "-w" option, it is TOO LATE to do this here because
// lower-level parts of fwin may already have adjusted font paths using
// mechanisms based on whether Xft is to be activated or not. So fwin
// checks for "-h" and "-H" and interprets what it finds. So what I do here
// is just a redundant reminder. Ugh.
            {   "-h", false, false,
                "-h       Obsolete option!",
                [&](string key, bool hasVal, string val)
                {   fwin_use_xft = 0;
                }
            },

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
            {   "-i", true, true,
                "-i       The option \"-i xxx.img\" causes the image file named to be available\n"
                "         for reading.",
                [&](string key, bool hasVal, string val)
                {   if (val == "-") val = standard_directory;
                    const char *val1 = val.c_str();
                    char *val2 = new (std::nothrow) char[std::strlen(val1)+1];
                    if (val2 != nullptr) std::strcpy(val2, val1);
                    fasl_files.push_back(faslFileRecord(val2, false));
                }
            },

            /*! options [-j] \item [{\ttfamily -j}] \index{{\ttfamily -j}}
             * Follow this directive with a file-name, and a record of all the files read
             * during the Lisp run will be dumped there with a view that it can be included
             * in a Makefile to document dependencies.
             */
            {   "-j", true, true,
                "-j       If you go \"-j FILE\" then Reduce puts some dependency information\n"
                "         into the named file as if builds modules for you.",
                [&](string key, bool hasVal, string val)
                {   if (!val.empty()) strcpy(dependency_file, val.c_str());
                }
            },

            /*! options [-l] \item [{\ttfamily -l}] \index{{\ttfamily -l}}
             * This is to send a copy of the standard output to a named log file. It is
             * very much as if the Lisp function {\ttfamily (spool ``logfile'')} had been
             * invoked at the start of the run.
             */
            {   "-l", true, true,
                "-l FILE  Send a copy of all output to the named file. If no FILE is\n"
                "         specified try \"logfile.log\".",
                [&](string key, bool hasVal, string val)
                {   char filename[LONGEST_LEGAL_FILENAME];
                    std::memset(filename, 0, sizeof(filename));
                    const char *w = val.c_str();
                    if (std::strlen(w) == 0) w = "logfile.log";
                    spool_file = open_file(filename, w, std::strlen(w), "w", nullptr);
                    if (spool_file == nullptr)
                    {   fwin_restore();
                        term_printf("Unable to write to \"%s\"\n", filename);
                    }
                    else
                    {   std::time_t t0 = std::time(nullptr);
                        std::strncpy(spool_file_name, filename, 128);
                        spool_file_name[127] = 0;
#ifdef COMMON
                        std::fprintf(spool_file,
                                     "Starts dribbling to %s (%.24s).\n",
                                     spool_file_name, std::ctime(&t0));
#else
                        std::fprintf(spool_file,
                                     "+++ Transcript to %s started at %.24s +++\n",
                                     spool_file_name, std::ctime(&t0));
#endif
                    }
                }
            },

            /*! options [-m] \item [{\ttfamily -m}] \index{{\ttfamily -m}}
             * Not used at present.
             */
            {   "-m", false, false,
                "-m       Unused..",
                [&](string key, bool hasVal, string val)
                {
                }
            },

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
            {   "-n", false, false,
                "-n       Ignore any restart function and run a Lisp read-eval-print-loop.",
                [&](string key, bool hasVal, string val)
                {   ignore_restart_fn = true;
                }
            },


            /*! options [-o] \item [{\ttfamily -o}] \index{{\ttfamily -o}}
             * See {\ttfamily -i}. This specifies an image file used for output via
             * {\ttfamily faslout} and {\ttfamily reserve}.
             */
            {   "-o", true, true,
                "-o FILE.img Make the named file an image file that is written to.\n"
                "         See also \"-i\".",
                [&](string key, bool hasVal, string val)
                {   if (val == "-") val = standard_directory;
                    output_directory = fasl_files.size();
                    const char *val1 = val.c_str();
                    char *val2 = new (std::nothrow) char[std::strlen(val1)+1];
                    if (val2 != nullptr) std::strcpy(val2, val1);
                    fasl_files.push_back(faslFileRecord(val2, true));
                }
            },

            /*! options [-p] \item [{\ttfamily -p}] \index{{\ttfamily -p}}
             * If a suitable profile option gets implemented one day this will activate it,
             * but for now it has no effect.
             */
            {   "-p", false, false,
                "-p       Reserved for a profiling option.",
                [&](string key, bool hasVal, string val)
                {
                }
            },

            /*! options [-q] \item [{\ttfamily -q}] \index{{\ttfamily -q}}
             * This option sets {\ttfamily !*echo} to {\ttfamily nil} and switches off
             * garbage collector messages to give a slightly quieter run.
             */
            {   "-q", false, false,
                "-q       Set *echo to nil to avoid echoed input.",
                [&](string key, bool hasVal, string val)
                {   symbolsToDefine.push_back(stringBoolString("echo", true, "nil"));
                }
            },

            /*! options [-r] \item [{\ttfamily -r}] \index{{\ttfamily -r}}
             * The random-number generator in CSL is normally initialised to a value
             * that is intended not to be reproducible from run to run.
             * In many cases that behavious is desirable, but for debugging it can be useful
             * to force a seed. The directive {\ttfamily -r nnn,mmm} sets the seed to
             * up to 64 bits taken from the values nnn and mmm. The second value if optional,
             * and specifying {\ttfamily -r0}  explicitly asks for the non-reproducible
             * behaviour (I hope). Note that the main Reduce-level random number source is
             * coded at a higher level and does not get reset this way -- this is the
             * lower level CSL generator.
             */
            {   "-r", true, true,
                "-r NNN   Use NNN as an initial seed for the random number generator.\n"
                "         The case \"-r0\" which is the default asks for a random seed\n"
                "         that will depend on the date, time of day and as much genuine\n"
                "         randomness as the operating system is willing to provide.\n"
                "         Note that the Reduce-level code uses its own random source not\n"
                "         the one controlled here.",
                [&](string key, bool hasVal, string val)
                {   char *end;
                    initial_random_seed = std::strtoll(val.c_str(), &end, 10);
                }
            },

            /*! options [-s] \item [{\ttfamily -s}] \index{{\ttfamily -s}}
             * Sets the Lisp variable {\ttfamily !*plap} and hence the compiler generates
             * an assembly listing.
             */
            {   "-s", false, false,
                "-s       Sets the variable *plap to true so that Lisp compilation displays\n"
                "         the code that it generates.",
                [&](string key, bool hasVal, string val)
                {   symbolsToDefine.push_back(stringBoolString("*plap", true, "t"));
                }
            },

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
            {   "-t", true, true,
                "-t NAME  Rather than run any user code, this checks the date-stamp\n"
                "         on a loadable module with the given name. It was provided\n"
                "         in case it would be useful in scripts to remake modules\n"
                "         based on which had been updated recently enough.",
                [&](string key, bool hasVal, string val)
                {   module_enquiry = val;
                }
            },

            /*! options [-u] \item [{\ttfamily -u}] \index{{\ttfamily -u}}
             * See {\ttfamily -d}, but this forcibly undefines a symbol. There are probably
             * very very few cases where it is useful since I do not have a large
             * number of system-specific predefined names.
             */
            {   "-u", true, true,
                "-u NAME  Undefine the named symbol.",
                [&](string key, bool hasVal, string val)
                {   cout << "Undefine " << val << endl;
                    symbolsToDefine.push_back(stringBoolString(val, false, ""));
                }
            },

            /*! options [-v] \item [{\ttfamily -v}] \index{{\ttfamily -v}}
             * An option to make things mildly more verbose. It displays more of a banner
             * at startup and switches garbage collection messages on.
             */
            {   "-v", false, false,
                "-v       Print a larger startup banner and force echoing of input.",
                [&](string key, bool hasVal, string val)
                {   init_flags &= ~INIT_QUIET;
                    init_flags |= INIT_VERBOSE;
                    symbolsToDefine.push_back(stringBoolString("*echo", true, "t"));
                }
            },

            /*! options [-x] \item [{\ttfamily -x}] \index{{\ttfamily -x}}
             * {\ttfamily -x} is an option intended for use only by system
             * support experts -- it disables trapping if segment violations by
             * errorset and so makes it easier to track down low level disasters --
             * maybe!  This can be valuable when running under a debugger since if the
             * code traps signals in its usual way and tries to recover it can make it a lot
             * harder to find out just what was going wrong.
             */
            {   "-x", false, false,
                "-x       Disable trapping of signals/exceptions so that a debugger can see them.",
                [&](string key, bool hasVal, string val)
                {   segvtrap = false;
                }
            },

            /*! options [-y] \item [{\ttfamily -y}] \index{{\ttfamily -y}}
             * {\ttfamily -y } is at present unused.
             */

            {   "-y", false, false,
                "-y       Currently not used.",
                [&](string key, bool hasVal, string val)
                {
                }
            },

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
            {   "-z", false, false,
                "-z       This forces a cold start. It is for use while bootstrapping the\n"
                "         system, since with a cold start only a subset of Lisp capabilities\n"
                "         are available. For use by system-builders and sometimes during\n"
                "         debugging.",
                [&](string key, bool hasVal, string val)
                {   restartp = false;
                }
            },

// This is now the end of the table that describes arguments...
            {   nullptr, false, false,
                "[Termination record for table]",
                [&](string key, bool hasVal, string val)
                {   my_abort();   // Should never arise!
                }
            }
        };
        argTableP = &argTable[0];

        setupArgs(argTable, argc, argv);
        for (auto msg : badArgs)
            cout << "+++ " << msg << " not accepted" << endl;
    }

// I will try not to act on too many of the options and even not generate
// much output until here when decoding is complete. This is in case the
// triggered actions need to be performed in some particular order.

    if (reclaim_trigger_target != 0)
        term_printf("GC trigger set to %" PRId64 "\n",
                    reclaim_trigger_target);



    if (fasl_files.empty())
    {   const char *p = standard_directory;
        char *p1;
        char cur[LONGEST_LEGAL_FILENAME];
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
        if (standard_directory[0] == '.' &&
            (standard_directory[1] == '/' ||
             standard_directory[1] == '\\')) std::strcpy(cur, standard_directory);
        else get_current_directory(cur, sizeof(cur));
        p += std::strlen(p);
        while (p != standard_directory &&
               *--p != '/' &&
               *p != '\\') /* nothing */;
        if (std::strncmp(standard_directory, cur, p-standard_directory) != 0)
            p1 = new (std::nothrow) char[std::strlen(p)];
        else p1 = nullptr;
// If output_directory has the 0x40000000 bit set then the directory
// involved is one that should be opened now if it exists, but if
// it does not its creation should be deferred for as long as possible.
        output_directory = 0x40000000 + 0;
        if (p == standard_directory || p1 == nullptr)
        {   char *val2 =
                new (std::nothrow) char[std::strlen(standard_directory)+1];
            if (val2 != nullptr) std::strcpy(val2, standard_directory);
            fasl_files.push_back(faslFileRecord(val2, true));
            if (p1 != nullptr) delete [] p1;
        }
        else
        {   std::strcpy(p1, p+1);
            fasl_files.push_back(faslFileRecord(p1, true));
            char *val2 =
                new (std::nothrow) char[std::strlen(standard_directory)+1];
            if (val2 != nullptr) std::strcpy(val2, standard_directory);
            fasl_files.push_back(faslFileRecord(val2, false));
        }
    }

    Iinit();  // Initialise "file system" for image files

    if (module_enquiry != "")
    {   char datestamp[32], fullname[LONGEST_LEGAL_FILENAME];
        size_t size;
        bool success = false;
        for (size_t i=0; i<fasl_files.size(); i++)
        {   if (fasl_files[i].inUse)
            {   if (!Imodulep1(i, module_enquiry.c_str(),
                               module_enquiry.size(),
                               datestamp, &size, fullname))
                {   success = true;
                    break;
                }
            }
        }
        if (!success)
        {   std::strcpy(datestamp, "unknown");
            size = 0;
            std::strcpy(fullname, module_enquiry.c_str());
        }
        term_printf("%.24s   size=%" PRIuPTR " file=%s\n",
                    datestamp, (uintptr_t)size, fullname);
        init_flags &= ~INIT_VERBOSE;
        fwin_pause_at_end = true;
        std::exit(EXIT_SUCCESS);
    }
    base_time = read_clock();
    gc_time = 0;

    if (init_flags & INIT_VERBOSE)
    {
#ifdef WITHOUT_GUI
// If I do NOT have a window system I will print a newline here so that I
// can be very certain that my banner appears at the start of a line.
// With a window system I should have a brand-new fresh window for output
// and the newline would intrude as an initial blank line.
        term_printf("\n");
#endif

#ifdef COMMON
        term_printf("Codemist Common Lisp revision %d for %s: %s\n",
#else // !COMMON
        term_printf("Codemist Standard Lisp revision %d for %s: %s\n",
#endif // !COMMON
                    REVISION, IMPNAME, __DATE__);
    }
#ifdef WITH_GUI
    ensure_screen();
// If the user hits the close button here I may be in trouble
#endif // WITH_GUI

#ifndef AVOID_THREADS
// I will now ALWAYS use threads for Karatsuba even on a CPU that only has
// a single core!
    karatsuba_parallel = KARATSUBA_PARALLEL_CUTOFF;
    if (kparallel > 0) karatsuba_parallel = kparallel;
#endif // AVOID_THREADS

// Up until the time I call setup() I may only use term_printf for
// output, because the other relevant streams will not have been set up.
//    1 bit:    0 for cold, 1 for warm.
//    2 bit:    1 to request initial allocation of memory.
    setup(restartp ? 3 : 2, store_size);
    {
// If the user had used "-g" on the command line that will have set
// errorset_min and I use that to trigger during on gc and fasl messages.
        if (errorset_min == 3) miscflags |= GC_MESSAGES | FASL_MESSAGES;
    }

    fwin_menus(loadable_packages, switches, review_switch_settings);

// Now that setup is complete (and I have done any authorisation I want to)
// I will seed the random number generator as requested by the user. The
// default will be to put it in an unpredictable (well hard to predict!)
// state
    Csrand((uint32_t)initial_random_seed);

//?        uint64_t t0 = read_clock();
//?        gc_time += t0;
//?        base_time += t0;

    ensure_screen();
    procedural_output = nullptr;
// OK, if I get this far I will suppose that any messages that report utter
// disasters will have reached the user, so I can allow FWIN to terminate
// rather more promptly.
    fwin_pause_at_end = false;

    if (timeTestCons)
    {   clock_t c0 = std::clock();
        LispObject a = nil;
// This is 100M conses so on a 64-bit system that should fill up 1.6G of
// memory. CSL will need that to be less than half, so this is looking at
// a total heap size of 4G for success I think.
        for (size_t i=0; i<100000000; i++)
            a = cons(fixnum_of_int(i), a);
        clock_t c1 = std::clock();
        std::printf("Timing %.3f\n",
                    (static_cast<double>(c1) - static_cast<double>(c0))/CLOCKS_PER_SEC);
    }

// Now if --trace/--tr has been specified set up some traced functions.
    for (auto name : tracedFunctions)
    {   Ltrace(nil, ncons(make_undefined_symbol(name.c_str())));
    }
}



// I need a way that a thread that is not synchronised with this one can
// generate a Lisp-level interrupt. I achieve that by
// letting that thread reset stackLimit. Then rather soon CSL will
// do a stackcheck() and will notice it.
//
// call this with
//    arg=0 to have no effect at all (!)   QUERY_INTERRUPT
//####arg=1 for a clock tick event#########TICK_INTERRUPT
//    arg=2 for quiet unwind               QUIET_INTERRUPT
//    arg=3 for backtrace.                 NOISY_INTERRUPT
//    arg=4 for termination                QUIT_PROGRAM
//    arg=5 for a break loop               BREAK_LOOP
// in each case the result is non-zero if some event has been
// posted but not yet acknowledged. So a call with QUERY_INTERRUPT
// can be used just to check if a previously posted event had been noticed.

// The value I store in event_flag is either 0 if there is no request pending,
// or it has the bottom 8 bits as a map showing what event or events have been
// requested and all other bits set. It is used in tests of the form
//   if ((stackpointer | event_flag.load()) >= stackLimit) ...
// and for this to make sense I must have stackLimit a lower address than
// within 256 bytes of the top of my address space. Being of a neurotic
// style I ensure this by rounding stackLimit down to a multiple of 256
// when I set it! This scheme allows for 8 independent ways in which the IO
// system can report "events" or "requests" back to the code here. Having
// a couple in hand for any future thread-supporting system seems a good idea.

volatile atomic<uintptr_t> event_flag(0);

// The following function can be called from a signal handler. It just
// sets a volatile atomic variable, because basically that is the only
// think it can do and remain "safe".

const intptr_t RECEIVE_TICK       = 0x01;
const intptr_t RECEIVE_INTERRUPT  = 0x02;
const intptr_t RECEIVE_BACKTRACE  = 0x04;
const intptr_t RECEIVE_QUIT       = 0x08;
const intptr_t RECEIVE_BREAK_LOOP = 0x10;

int async_interrupt(int type)
{   uintptr_t newval;
    switch (type)
{       default:
        case QUERY_INTERRUPT:
            newval = 0;
            break;
//        case TICK_INTERRUPT:
//// The non-zero values used here have some information about what the
//// request was in their low order 4 bits, but otherwise all bits are set.
//// By having separate bits for each request it is OK to OR these together.
//           newval = INTPTR_MAX - 0xff + RECEIVE_TICK;
//           break;
        case QUIET_INTERRUPT:
            newval = INTPTR_MAX - 0xff + RECEIVE_INTERRUPT;
            break;
        case NOISY_INTERRUPT:
            newval = INTPTR_MAX - 0xff + RECEIVE_BACKTRACE;
            break;
        case QUIT_PROGRAM:
            newval = INTPTR_MAX - 0xff + RECEIVE_QUIT;
            break;
        case BREAK_LOOP:
            newval = INTPTR_MAX - 0xff + RECEIVE_BREAK_LOOP;
            break;
    }
// C++11 provides fetch_or(). Well I could have written "|=" to invoke
// it, but spelling it out helps to stress what is going on. I really want
// the implemention to be lock-free and I very much expect that given that
// the atomic value is a wrapped uintptr_t that this will be possible. However
// C++ could have been implemented with atomic<uintptr_t> as a type
// that is not lock-free - eg perhaps on a machine where the bus size
// is less than the size of an address?
    uintptr_t oldval = event_flag.fetch_or(newval);
    return static_cast<int>(oldval) & 0xff;
}

LispObject respond_to_stack_event()
{   uintptr_t f = event_flag.fetch_and(0);
    if (f == 0) return aerror("stack overflow");
// Each of the messages that I might be sent comes in a separate bit, so
// here I have to test each bit. I will test the bits in some sort of
// order because I will only perform one major operation!
    if ((f&RECEIVE_QUIT) != 0) return Lstop1(nil, fixnum_of_int(0));
    if ((f&RECEIVE_TICK) != 0)
    {   //fwin_acknowledge_tick();
#if !defined EMBEDDED && !defined WITHOUT_GUI
        uintptr_t tt = read_clock() - base_time;
        long int t = (long int)(tt/10000);
        long int gct = gc_time/100000;
        report_time(t, gct);
#endif
        time_now = read_clock()/1000;  // in milliseconds now
        if ((time_limit >= 0 && time_now > time_limit) ||
            (io_limit >= 0 && io_now > io_limit))
            return resource_exceeded();
    }
    if ((f&RECEIVE_BACKTRACE) != 0)
    {   exit_reason = UNWIND_ERROR;
        exit_value = exit_tag = nil;
        exit_count = 0;
        THROW(LispError);
    }
    if ((f&RECEIVE_INTERRUPT) != 0)
    {   exit_reason = UNWIND_UNWIND;
        exit_value = exit_tag = nil;
        exit_count = 0;
        THROW(LispError);
    }
    if ((f&RECEIVE_BREAK_LOOP) != 0)
    {
// If interrupted() returns I will just resume the calculation I had been
// doing. Well if the reading and printing within that function causes
// garbage collection I need to be GC safe here, and that will be the case
// with a conservative collector but not in the current version of the code
// with the precise collector perhaps?
        return interrupted();
    }
    return nil;
}

#ifdef HAVE_SIGACTION
static void low_level_signal_handler(int signo, siginfo_t *t, void *v);
#else // !HAVE_SIGACTION
static void low_level_signal_handler(int signo);
#endif // !HAVE_SIGACTION

void set_up_signal_handlers()
{
#ifdef USE_SIGALTSTACK
// If I get a SIGSEGV that is caused by a stack overflow then I am in
// a world of pain because the regular stack does not have space to run my
// exception handler. So where I can I will arrange that the exception
// handler runs in its own small stack. This may itself lead to pain,
// but perhaps less?
    signal_stack.ss_sp = reinterpret_cast<void *>(signal_stack_block);
    signal_stack.ss_size = SIGSTKSZ;
    signal_stack.ss_flags = 0;
    sigaltstack(&signal_stack, (stack_t *)0);
#endif
#ifdef HAVE_SIGACTION
    struct sigaction sa;
    sa.sa_sigaction = low_level_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
// (a) restart system calls after signal (if possible),
// (b) use handler that gets more information,
//
// The signals that C++ allows for are
//      SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV and SIGTERM.
// and I will assume that ig sigaction is available it will support all those.
    sigaction(SIGABRT, &sa, nullptr);
    sigaction(SIGFPE, &sa, nullptr);
    sigaction(SIGILL, &sa, nullptr);
    sigaction(SIGINT, &sa, nullptr);
    sigaction(SIGSEGV, &sa, nullptr);
    sigaction(SIGTERM, &sa, nullptr);
#else // HAVE_SIGACTION
    std::signal(SIGABRT, low_level_signal_handler);
    std::signal(SIGFPE, low_level_signal_handler);
    std::signal(SIGILL, low_level_signal_handler);
    std::signal(SIGINT, low_level_signal_handler);
    std::signal(SIGSEGV, low_level_signal_handler);
    std::signal(SIGTERM, low_level_signal_handler);
#endif // HAVE_SIGACTION
}

#ifdef HAVE_SIGACTION
static void low_level_signal_handler(int signo, siginfo_t *si,
                                     void *v)
#else // !HAVE_SIGACTION
static void low_level_signal_handler(int signo)
#endif // !HAVE_SIGACTION
{
// There are really very restrictive rules about what I can do in a
// signal handler and remain safe. And the exceptions that are trapped
// (and activate this code) are either caused by internal system failure
// or by requests from outside that the system stop at once. So I will
// call std::quick_exit(), which is allowed by the C++ standard. There will
// often be a function registered by at_quick_exit() that tries to reset the
// console from RAW to COOKED mode. The issue about whether that is formally
// async-signal safe is one that I will ignore!
#ifdef HAVE_QUICK_EXIT
// quick_exit is a C++17 feature but as of the start of 2021 the mingw
// versions of g++ and their libraries do not support it. So if it is
// not available I will try calling term_close() directly.
    std::quick_exit(EXIT_FAILURE);
#else // HAVE_QUICK_EXIT
    term_close();
// To quit I will then use _Exit() if available, but fall back to abort()
// if I have to.
#ifdef HAVE__EXIT
    std::_Exit(EXIT_FAILURE);
#else // HAVE__EXIT
    std::abort();
#endif // HAVE__EXIT
#endif // HAVE_QUICK_EXIT
}

// This is the "standard" route into CSL activity - it uses file-names
// from the decoded command-line as files to be read and processed.

static LispObject cslaction()
{   volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    errorset_msg = nullptr;
    TRY
        set_up_signal_handlers();
        non_terminal_input = nullptr;
#ifdef WITH_GUI
        terminal_eof_seen = 0;
#endif // WITH_GUI
        if (simpleArgs.empty()) lisp_main();
        else
        {   size_t i;
            for (i=0; i<simpleArgs.size(); i++)
            {   if (std::strcmp(simpleArgs[i].c_str(), "-") == 0)
                {   non_terminal_input = nullptr;
#ifdef WITH_GUI
                    terminal_eof_seen = 0;
#endif // WITH_GUI
                    lisp_main();
                }
                else
                {   char filename[LONGEST_LEGAL_FILENAME];
                    std::FILE *f;
                    std::memset(filename, 0, sizeof(filename));
                    f = open_file(filename, simpleArgs[i].c_str(),
                                  std::strlen(simpleArgs[i].c_str()), "r", nullptr);
                    if (f == nullptr)
                        err_printf("\n+++ Could not read file \"%s\"\n",
                                   simpleArgs[i].c_str());
                    else
                    {   if (init_flags & INIT_VERBOSE)
                            term_printf("\n+++ About to read file \"%s\"\n",
                                        simpleArgs[i].c_str());
                        report_file(filename);
                        non_terminal_input = f;
                        lisp_main();
                        std::fclose(f);
                    }
                }
            }
        }
    CATCH(LispException)
        return nil;
    END_CATCH;
    return nil;
}

int cslfinish(character_writer *w)
{   volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    procedural_output = w;
    if (Ifinished())
        term_printf("\n+++ Errors on checkpoint-image file\n");
#ifdef TRACED_EQUAL
    dump_equals();
#endif
    if (init_flags & INIT_VERBOSE)
    {   uint64_t t = (read_clock() -
                      base_time)/10000;  // centisecond units
        uint64_t gct = gc_time/10000;
#ifdef HASH_STATISTICS
        term_printf("oblist: found: %" PRIu64 " probes: %" PRIu64 " (%.2f)\n"
                    "        added: %" PRIu64 " probes: %" PRIu64 " (%.2f)\n",
                    Noget, Nogetp, Nogetp/static_cast<double>(Noget),
                    Noput, Noputp, Noputp/static_cast<double>(Noput));
        term_printf("hash lookup: %" PRIu64 " probes: %" PRIu64 " (%.2f)\n"
                    "   inserted: %" PRIu64 " probes: %" PRIu64 " (%.2f)\n"
                    "    updated: %" PRIu64 " probes: %" PRIu64 " (%.2f)\n",
                    Nhget, Nhgetp, Nhgetp/static_cast<double>(Nhget),
                    Nhput1, Nhputp1, Nhputp1/static_cast<double>(Nhput1),
                    Nhput2, Nhputp2, Nhputp2/static_cast<double>(Nhput2));
#endif
        term_printf("\n\nEnd of Lisp run after %" PRId64 ".%.2" PRId64
                    "+%" PRId64 ".%.2" PRId64 " seconds\n",
                    t/100, t%100, gct/100, gct%100);
    }
    drop_heap_segments();
    if (spool_file != nullptr)
    {
#ifdef COMMON
        std::fprintf(spool_file, "\nFinished dribbling to %s.\n",
                     spool_file_name);
#else
        std::fprintf(spool_file,
                     "\n+++ Transcript closed at end of run +++\n");
#endif
#ifndef DEBUG
        std::fclose(spool_file);
        spool_file = nullptr;
#endif
    }
    ensure_screen();
    procedural_output = nullptr;
    return return_code;
}

int execute_lisp_function(const char *fname,
                          character_reader *r,
                          character_writer *w)
{   LispObject ff;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(ff = make_undefined_symbol(fname),
             return 1);  // Failed to make the symbol
    procedural_input = r;
    procedural_output = w;
    if_error(Lapply0(nil, ff);
             ensure_screen(),
             // Error handler
             procedural_input = nullptr;
             procedural_output = nullptr;
             return 2);
    procedural_input = nullptr;
    procedural_output = nullptr;
    return 0;
}


#ifdef PROCEDURAL_WASM_XX
int buff_ready = 0;
const char *buffer = nullptr;
int buff_size = 0;

void PROC_insert_buffer(const char *buf, int size)
{   buffer = buf;
    buff_size = size;
    buff_ready = 1;
}

void PROC_mainloop()
{   if (buff_ready)
    {
//      std::printf("buffer is ready...buffer: %s, buff_size: %i\n", buffer, buff_size);
//      char query[buff_size+1];
//      std::strncpy(query, buffer, buff_size+1);
        std::printf("processing: %s\n", buffer);
        PROC_process_one_reduce_statement(buffer);
        while (proc_data_string && *proc_data_string != 0)
        {   PROC_process_one_reduce_statement(proc_data_string);
//          std::printf("copying proc_data_string: \"%s\" of size: %i", proc_data_string, buff_size)
//          std::strncpy(query, proc_data_string, buff_size);
        }
//      std::printf("freeing buffer...\n");
// NB in the rest of CSL I am nov moving to use NEW and DELETE rather
// then MALLOC and FREE.
        std::free((char*)buffer);
        buff_ready = 0;
        buff_size = 0;
//      std::printf("setting buff_ready=0...\n");
// let's hope we don't get preempted!
//      emscripten_cancel_main_loop();
//      std::printf("waiting...\n");
    }
    return;
}
#endif


#ifdef PROCEDURAL_WASM_SETUP
#include PROCEDURAL_WASM_SETUP
#endif

// People who want to use this in an embedded context can predefine
// NO_STARTUP_CODE and provide their own entrypoint...

#ifndef NO_STARTUP_CODE

// The next fragment of code is to help with the use of CSL (and hence
// packages written in Lisp and supported under CSL) as OEM products
// embedded within larger C-coded packages.  There is (of course) a
// significant issue about clashes between the names of external symbols
// if CSL is to be linked with anything else, but I will not worry about that
// just yet.
// The protocol for calling Lisp code from C is as follows:
//
#ifdef CONSERVATIVE
//     Create an instance of a ThreadStartup object, and keep it alive
//     while everything else is happening.
#endif
//     cslstart(argc, argv, writer);allocate memory and Lisp heap etc. Args
//                                  should be "as if" CSL was being called
//                                  directly and this was the main entrypoint.
//                                  The extra arg accepts output from this
//                                  stage.  Use nullptr to get standard I/O.
//     execute_lisp_function(fname, reader, writer);
//                                  fname is a (C) string that names a Lisp
//                                  function of 0 args.  This is called with
//                                  stdin/stdout access redirected to use the
//                                  two character-at-a-time functions passed
//                                  down.  [Value returned indicates if
//                                  the evaluation succeeded?]
//     cslfinish(writer);           Tidies up ready to stop.

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

#ifdef HAVE_CRLIBM
static unsigned long long crlibstatus = 0;

class CrlibmSetup
{
public:
    CrlibmSetup()
    {   crlibstatus = crlibm_init();
    }
    ~CrlibmSetup()
    {   crlibm_exit(crlibstatus);
    }
};
#endif

static int submain(int argc, const char *argv[])
{   volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
#ifdef CONSERVATIVE
// The next line sets threadId (in fact it should always be to zero since
// at this stage this is the first and only thread that exists!) and using
// RAII arranges to release that identifier on exit. It is part of the
// protocol that will allow other threads to get created and run later on.
    threadMap = -1;
    activeThreads = 0;
    ThreadStartup userThreads;
    stackBases[threadId::get()] = reinterpret_cast<uintptr_t>(C_stackbase);
#endif
#ifdef HAVE_CRLIBM
    CrlibmSetup crlibmVar;
#endif
#ifndef AVOID_THREADS
    KaratsubaThreads kthreads;
#endif // AVOID_THREADS
    cslstart(argc, argv, nullptr);
#ifdef SAMPLE_OF_PROCEDURAL_INTERFACE
    std::strcpy(ibuff, "(print '(a b c d))");
    execute_lisp_function("oem-supervisor", iget, iput);
    std::printf("Buffered output is <%s>\n", obuff);
#elif PROCEDURAL_WASM_XX
    // set up reduce
    PROC_prepare_for_top_level_loop();
    PROC_process_one_reduce_statement("algebraic;");
#ifdef PROCEDURAL_WASM_SETUP
    // the header you include *must* contain void setup_web_reduce(void)
    setup_web_reduce();
#endif
    emscripten_set_main_loop(PROC_mainloop, 60, 0);
#else // end PROCEDURAL_WASM_XX
    set_keyboard_callbacks(async_interrupt);
    cslaction();
#endif
    return cslfinish(nullptr);
}

#ifdef EMBEDDED
#define ENTRYPOINT main
#else

#define ENTRYPOINT fwin_main

extern int ENTRYPOINT(int argc, const char *argv[]);

int main(int argc, const char *argv[])
{   fwin_set_lookup(look_in_lisp_variable);
    return fwin_startup(argc, argv, ENTRYPOINT);
}

#endif


int ENTRYPOINT(int argc, const char *argv[])
{   int res;
#ifdef EMBEDDED
    if ((res = find_program_directory(argv[0])) != 0)
    {   std::fprintf(stderr,
                     "Unable to identify program name and directory (%d)\n", res);
        return 1;
    }
#endif
#ifdef USE_MPI
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&mpi_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&mpi_size);
    std::printf("I am mpi instance %d of %d.\n", mpi_rank+1, mpi_size);
#endif

    std::strcpy(about_box_title, "About CSL");
    std::strcpy(about_box_description, "Codemist Standard Lisp");
    try
    {   res = submain(argc, argv);
    }
    catch (std::runtime_error &e)
    {
// Here is where the EXIT exception is caught when somebody in the main
// thread obeys my_exit(). It is intended to be a fatal situation, and so if
// the "catch" here is ineffective and the application terminated not much is
// lost!
        res = EXIT_FAILURE;
    }
    report_dependencies();
#ifdef USE_MPI
    MPI_Finalize();
#endif
    ensure_screen();
    return res;
}

#endif // NO_STARTUP_CODE

// And here are some functions that may help use Reduce, as an alternative
// to the very general escape that execute_lisp_function provides... If
// these return an integer it will generally be zero for success and non-
// zero for failure.

// After having called cslstart() you can set the I/O callback functions
// using this. If you set one or both to nullptr this indicates use of
// stdin/stdout as per usual rather than an callback, otherwise whenever
// anybody wants to read or write they use these procedures. It is then
// your responsibility to cope with whatever text gets exchanged!

int PROC_set_callbacks(character_reader *r,
                       character_writer *w)
{   procedural_input = r;
    procedural_output = w;
    return 0;   // can never report failure
}

int PROC_prepare_for_top_level_loop()
{   LispObject w1 = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(w1 = make_undefined_symbol("prepare-for-top-loop");
             Lapply1(nil, w1, nil),
             // Error handler
             return 1);  // Failed one way or another
    return 0;
}

int char_from_string()
{   int c = *proc_data_string;
    if (c == 0) return EOF;
    proc_data_string++;
    return c;
}

int PROC_process_one_reduce_statement(const char *s)
{   LispObject w = nil, w1 = nil;
    volatile uintptr_t sp;
    character_reader *save_read = procedural_input;
    proc_data_string = s;
    procedural_input = char_from_string;
    C_stackbase = (uintptr_t *)&sp;
    if_error(w1 = make_undefined_symbol("process-one-reduce-statement");
             w = Lapply0(nil, w1),
             // Error handler
             procedural_input = save_read;
             return 1);  // Failed one way or another
    procedural_input = save_read;
    return w != nil;
}

int PROC_load_package(const char *name)
{   LispObject w = nil, w1 = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(w1 = make_undefined_symbol("load-package");
             Save save(w1);
             w = make_undefined_symbol(name);
             save.restore(w1);
             Lapply1(nil, w1, w),
             // Error handler
             return 1);  // Failed one way or another
    return 0;
}

int PROC_set_switch(const char *name, int val)
{   LispObject w = nil, w1 = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(w1 = make_undefined_symbol("onoff");
             errexit();
             Save save(w1);
             w = make_undefined_symbol(name);
             save.restore(w1);
             Lapply2(nil, w1, w, val == 0 ? nil : lisp_true),
             // Error handler
             return 1);  // Failed to set the switch
    return 0;
}

int PROC_gc_messages(int n)
{   Lverbos(nil, fixnum_of_int(n)); // can not fail
    return 0;
}

// Expressions are entered in Reverse Polish Notation, This call clears
// the stack. It is probably only wanted if there has been an error
// of some sort.

int PROC_clear_stack()
{   procstack = nil;
    return 0;       // can never fail!
}

// The RPN stack is used to build a prefix-form expression for
// evaluation. This code creates a Lisp symbol and pushes it.

int PROC_push_symbol(const char *name)
{   LispObject w = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(w = make_undefined_symbol(name);
             errexit();
             w = cons(w, procstack),
             return 1);
    procstack = w;
    return 0;
}


//    stack = the-string . stack;

int PROC_push_string(const char *data)
{   LispObject w = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(w = make_string(data);
             errexit();
             w = cons(w, procstack),
             return 2);  // Failed to push onto stack
    procstack = w;
    return 0;
}

// Return a handle to the top item on the stack, and pop the stack.
// The value here will be a RAW LISP structure and NOT at all necessarily
// anything neat.

// Push an integer, which should fit within the constraints of a
// 28-bit fixnum.

int PROC_push_small_integer(int32_t n)
{   LispObject w = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(w = make_lisp_integer32(n);
             errexit();
             w = cons(w, procstack),
             return 1);
    procstack = w;
    return 0;
}

int PROC_push_big_integer(const char *n)
{   LispObject w = nil;
    int len = 0;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
// Here I need to parse a C string to obtain a Lisp number.
    boffop = 0;
    if_error(
        while (*n != 0)
        {   packbyte(*n++);
            len++;
        }
        w = intern(len, 0);
        errexit();
        w = cons(w, procstack),
        return 1);
    procstack = w;
    return 0;
}

int PROC_push_floating(double n)
{   LispObject w = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
// Here I have to construct a Lisp (boxed) float
    if_error(w = make_boxfloat(n, TYPE_DOUBLE_FLOAT);
             errexit();
             w = cons(w, procstack),
             return 1);
    procstack = w;
    return 0;
}

// To make an expression
//    (f a1 a2 a3)
// you go
//       push(a1)
//       push(a2)
//       push(a3)
//       make_function_call("f", 3)

int PROC_make_function_call(const char *name, int n)
{   LispObject w = nil, w1 = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if_error(
        while (n > 0)
        {   if (procstack == nil) return 1; // Not enough args available
            w = cons(car(procstack), w);
            errexit();
            procstack = cdr(procstack);
            n--;
        }
        Save save(w);
        w1 = make_undefined_symbol(name);
        save.restore(w);
        errexit();
        w = cons(w1, w);
        errexit();
        w = cons(w, procstack),
            return 1);
    procstack = w;
    return 0;
}

// Take the top item on the stack and save it in location n (0 <= n <= 99).

int PROC_save(int n)
{   if (n < 0 || n > 99) return 1; // index out of range
    if (procstack == nil) return 2; // Nothing available to save
// On the next line I want to copy the LispObject not any atomic thing!
    elt(procmem, n) = static_cast<LispObject>(car(procstack));
    procstack = cdr(procstack);
    return 0;
}

// Push onto the stack the value saved at location n. See PROC_save.

int PROC_load(int n)
{   LispObject w = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if (n < 0 || n > 99) return 1; // index out of range
    w = elt(procmem, n);
    if_error(w = cons(w, procstack),
             return 2);  // Failed to push onto stack
    procstack = w;
    return 0;
}

// Duplicate the top item on the stack.

int PROC_dup()
{   LispObject w = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if (procstack == nil) return 1; // no item to duplicate
    w = car(procstack);
    if_error(w = cons(w, procstack),
             return 2)  // Failed to push onto stack
    procstack = w;
    return 0;
}

int PROC_pop()
{   if (procstack == nil) return 1; // stack is empty
    procstack = cdr(procstack);
    return 0;
}

// Replaces the top item on the stack with a simplified version of
// itself. For experts on Reduce internals I note that this wraps
// the simplified form up in a prefix-like "!*sq" wrapper so it can
// still be used in a prefix context.

int PROC_simplify()
{   LispObject w = nil, w1 = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if (procstack == nil) return 1; // stack is empty
    if_error(
        w = make_undefined_symbol("simp");
        errexit();
        w = Lapply1(nil, w, car(procstack));
        errexit();
        Save save(w);
        w1 = make_undefined_symbol("mk*sq");
        save.restore(w);
        errexit();
        w = Lapply1(nil, w1, w);
        errexit();
        setcar(procstack, w),
        // error exit case
        return 1);
    return 0;
}

// Replace the top item on the stack with whatever is obtained by using
// the Lisp EVAL operation on it. Note that this is not intended for
// casual use - if there is any functionality that you need PLEASE ask
// me to put in a cleaner abstraction to support it.

static void PROC_standardise_gensyms(LispObject w)
{   if (consp(w))
    {   Save save(w);
        PROC_standardise_gensyms(car(w));
        save.restore(w);
#ifdef NO_THROW
        if (exceptionPending()) return;
#endif // NO_THROW
        PROC_standardise_gensyms(cdr(w));
        return;
    }
// Now w is atomic. The only case that concerns me is if it is a gensym.
    if (symbolp(w)) get_pname(w); // allocates gensym name if needed.
}

int PROC_lisp_eval()
{   save_current_function saver(eval_symbol);
    LispObject w = nil;
    volatile uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if (procstack == nil) return 1; // stack is empty
    if_error(
        w = eval(car(procstack), nil);
        errexit();
        Save save(w);
        PROC_standardise_gensyms(w);
        save.restore(w),
        return 1);
    setcar(procstack, w);
    return 0;
}

static LispObject PROC_standardise_printed_form(LispObject w)
{   if (consp(w))
    {   LispObject w1;
        {   Save save(w);
            w1 = PROC_standardise_printed_form(car(w));
            save.restore(w);
        }
        errexit();
        {   Save save(w1);
            w =  PROC_standardise_printed_form(cdr(w));
            save.restore(w1);
        }
        errexit();
        w = cons(w1, w);
        errexit();
        return w;
    }
// Now w is atomic. There are two interesting cases - an unprinted gensym
// and a bignum.
    if (symbolp(w))
    {   Save save(w);
        get_pname(w); // allocates gensym name if needed. Otherwise cheap!
        save.restore(w);
        return w;
    }
    else if (is_numbers(w) && is_bignum(w))
    {   w = Lexplode(nil, w);        // Bignum to list of digits
        errexit();
        w = Llist_to_string(nil, w); // list to string
        return w;
    }
    else return w;
}

// Replaces the top item on the stack with version that is in
// a simple prefix form. This prefix form should be viewed as
// unsuitable for inclusion in any further expression.

int PROC_make_printable()
{   LispObject w = nil, w1 = nil;
    uintptr_t sp;
    C_stackbase = (uintptr_t *)&sp;
    if (procstack == nil) return 1; // stack is empty
// I want to use "simp" again so that I can then use prepsq!
    if_error(
        w = make_undefined_symbol("simp");
        errexit();
        w = Lapply1(nil, w, car(procstack));
        errexit();
        Save save(w);
        w1 = make_undefined_symbol("prepsq");
        errexit();
        save.restore(w);
        w = Lapply1(nil, w1, w);
        errexit();
// There are going to be two things I do next. One is to ensure that
// all gensyms have print-names, the other is to convert bignums into
// strings. Both of these could be viewed as mildly obscure!
        w = PROC_standardise_printed_form(w),
        return 1);
    setcar(procstack, w);
    return 0;
}

PROC_handle PROC_get_value()
{   LispObject w;
    if (procstack == nil) w = fixnum_of_int(0);
    else
    {   w = car(procstack);
        procstack = cdr(procstack);
    }
    return (PROC_handle)w;
}

PROC_handle PROC_get_raw_value()
{   LispObject w;
    if (procstack == nil) w = nil;
    else
    {   w = car(procstack);
        procstack = cdr(procstack);
    }
    return (PROC_handle)w;
}

// return true if the expression is atomic.

int PROC_atom(PROC_handle p)
{   return !consp(reinterpret_cast<LispObject>(p));
}

// return true if the expression is NIL.

int PROC_null(PROC_handle p)
{   return (reinterpret_cast<LispObject>(p)) == nil;
}

// Return true if it is a small integer.

int PROC_fixnum(PROC_handle p)
{   return is_fixnum(reinterpret_cast<LispObject>(p));
}

int PROC_string(PROC_handle p)
{   return is_vector(reinterpret_cast<LispObject>(p)) &&
           is_string(reinterpret_cast<LispObject>(p));
}

int PROC_floatnum(PROC_handle p)
{
// I ignore the "sfloat" representation that would be relevant in Common
// Lisp mode. It is not used with Reduce.
    return is_bfloat(reinterpret_cast<LispObject>(p));
}

// Return true if it is a symbol.

int PROC_symbol(PROC_handle p)
{   return symbolp(reinterpret_cast<LispObject>(p));
}

// Given that it is a small integer return the integer value

int32_t PROC_integer_value(PROC_handle p)
{   return static_cast<int32_t>(int_of_fixnum(
                                    reinterpret_cast<LispObject>(p)));
}

double PROC_floating_value(PROC_handle p)
{   return double_float_val(reinterpret_cast<LispObject>(p));
}

// Given that it is a symbol, return a string that is its name. Note
// that this must not be too long, and that the value returned is in
// a static buffer. Note that this would crash if the item was a
// "gensym" that had not been printed before, and so I take care to
// sort that out in PROC_make_printable.
// Hmmm the name-length restriction here is ugly _ will wait and see how
// long it is before somebody falls foul of it!

static char PROC_name[256];

const char *PROC_symbol_name(PROC_handle p)
{   LispObject w = reinterpret_cast<LispObject>(p);
    intptr_t n;
    w = qpname(w);
    n = length_of_byteheader(vechdr(w)) - CELL;
    if (n > (intptr_t)sizeof(PROC_name)-1) n = sizeof(PROC_name)-1;
    std::strncpy(PROC_name, reinterpret_cast<const char *>(&celt(w, 0)),
                 n);
    PROC_name[n] = 0;
    return &PROC_name[0];
}

const char *PROC_string_data(PROC_handle p)
{   LispObject w = reinterpret_cast<LispObject>(p);
    intptr_t n;
    n = length_of_byteheader(vechdr(w)) - CELL;
// NOTE that I truncate long strings here. Boo Hiss! This may make a mess
// of dealing with big numbers, so in due course I will need to fix it!
    if (n > (intptr_t)sizeof(PROC_name)-1) n = sizeof(PROC_name)-1;
    std::strncpy(PROC_name, reinterpret_cast<const char *>(&celt(w, 0)),
                 n);
    PROC_name[n] = 0;
    return &PROC_name[0];
}

// First and rest allow list traversal. The two-levels of cast are to
// dispose of atomic<> stuff.

PROC_handle PROC_first(PROC_handle p)
{   return reinterpret_cast<PROC_handle>(
               reinterpret_cast<LispObject>(
                   car(reinterpret_cast<LispObject>(p))));
}

PROC_handle PROC_rest(PROC_handle p)
{   return reinterpret_cast<PROC_handle>(
               reinterpret_cast<LispObject>(
                   cdr(reinterpret_cast<LispObject>(p))));
}

// End of csl.cpp
