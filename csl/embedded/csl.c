/*  csl.c                            Copyright (C) 1989-2008 Codemist Ltd */

/*
 * This is Lisp system for use when delivering Lisp applications
 * (such as REDUCE) on pretty-well any computer that has an ANSI
 * C compiler.
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 3a5e71d7 01-Jul-2009 */

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

#ifndef HAVE_FWIN
/*
 * During startup on a windowed system if I needed to report an error
 * but the window was minimised I need to restore it...
 */
#define fwin_restore()
#endif

#ifdef SOCKETS

static int port_number, remote_store, current_users, max_users;
SOCKET socket_server;
int sockets_ready;
clock_t cpu_timeout;
time_t elapsed_timeout;
static int char_to_socket(int c);

#endif

/*
 * These flags are used to ensure that protected symbols don't get
 * overwritten by default, and that the system keeps quiet about it.
 */

CSLbool symbol_protect_flag = YES;
CSLbool warn_about_protected_symbols = NO;

#ifdef WINDOW_SYSTEM
CSLbool use_wimp;
#endif

#ifdef USE_MPI
int32_t mpi_rank,mpi_size;
#endif

/*****************************************************************************/
/*      Error reporting and recovery                                         */
/*****************************************************************************/

#ifdef CHECK_STACK
/*
 * Some computers are notably unhelpful about their behaviour when the system
 * stack overflows. As a debugging tool on such machines I can do limited
 * software checking by inserting explicit calls to this function in places
 * I think may be critical.  I impose an arbitrary limit on the stack size,
 * but that is better than no checking and random corruption - maybe. Please
 * do not enable CHECK_STACK unless it is really necessary to hunt a bug,
 * since it is miserably expensive and crude.
 */

#define C_STACK_ALLOCATION 240000

static int spset = 0;
static int32_t spbase = 0, spmin;

static int stack_depth[C_STACK_ALLOCATION], stack_line[C_STACK_ALLOCATION];
static char *stack_file[C_STACK_ALLOCATION];
static int c_stack_ptr = 0;

int check_stack(char *file, int line)
{
    int32_t temp = (int32_t)&temp;
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
    stack_file[c_stack_ptr] = file;
    if (temp < spmin-250)  /* Only check at granularity of 250 bytes */
    {   int i;
        term_printf("Stack depth %d at file %s line %d\n",
                     spbase-temp, file, line);
        for (i=c_stack_ptr; i>=0 && i > c_stack_ptr-30; i--)
            term_printf(" %s:%d", stack_file[i], stack_line[i]);
        term_printf("\n");
        spmin = temp;
        if (temp < spbase-C_STACK_ALLOCATION) return 1;
    }
    return 0;
}
#endif

/*
 * error_message_table was defined in cslerror.h since that way I can keep its
 * contents textually close to the definitions of the message codes that it
 * has to relate to.
 */

#define errcode(n) error_message_table[n]

Lisp_Object MS_CDECL error(int nargs, int code, ...)
/*
 * nargs indicates how many values have been provided AFTER the
 * code.  Thus nargs==0 will just display a simple message, nargs==1
 * will be a message plus a value and so on.  I will expect that the
 * number of actual args here is well within any limits that I ought to
 * impose.
 */
{
    va_list a;
    int i;
    Lisp_Object nil = C_nil, w1;
    Lisp_Object *w = (Lisp_Object *)&work_1;
    if (nargs > ARG_CUT_OFF) nargs = ARG_CUT_OFF;
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
    {   err_printf("\n+++ Error %s: ", errcode(code));
/*
 * There is now some painful shuffling around to get all the args
 * to error() moved over onto the Lisp stack so that is garbage collection
 * is triggered during printing all will be well.
 */
        va_start(a, code);
        for (i=0; i<nargs; i++) *w++ = va_arg(a, Lisp_Object);
        va_end(a);
        for (i=0; i<nargs; i++) push(*--w);
        if (code != err_stack_overflow)  /* Be cautious here! */
        {   stackcheck0(nargs);
        }
        for (i=0; i<nargs; i++)
        {   Lisp_Object p;
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
/*
 * After doing this is is necessary to be VERY careful, since nil is
 * used as a base register for lots of things...  Still this is the
 * cheapest way I can see to mark the need for unwinding.
 */
    exit_reason = (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? UNWIND_ERROR :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...)
/*
 * nargs indicated the number of EXTRA args after code1 & code2.
 */
{
    Lisp_Object nil = C_nil, w1;
    va_list a;
    int i;
    Lisp_Object *w = (Lisp_Object *)&work_1;
    if (nargs > ARG_CUT_OFF) nargs = ARG_CUT_OFF;
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
    {   err_printf("\n+++ Error %s, %s: ", errcode(code1), errcode(code2));
        va_start(a, code2);
        for (i=0; i<nargs; i++) *w++ = va_arg(a, Lisp_Object);
        va_end(a);
        for (i=0; i<nargs; i++) push(*--w);
        stackcheck0(nargs-2);
        nil = C_nil;
        for (i=0; i<nargs; i++)
        {   Lisp_Object p;
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
/*
 * After doing this is is necessary to be VERY careful, since nil is
 * used as a base register for lots of things...  Still this is the
 * cheapest way I can see to mark the need for unwinding.
 */
    exit_reason = (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? UNWIND_ERROR :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

/*
 * This can be used when a resource expires...
 */
Lisp_Object resource_exceeded()
{
    Lisp_Object nil = C_nil;
    exit_reason = UNWIND_RESOURCE;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

Lisp_Object interrupted(Lisp_Object p)
/*
 * Could return onevalue(p) to proceed from the interrupt event...
 */
{
    Lisp_Object nil = C_nil, w;
/*
 * If I have a windowed system I expect that the mechanism for
 * raising an exception will have had a menu that gave me a chance
 * to decide whether to proceed or abort.  Thus the following code
 * is only needed if there is no window system active.  On some systems
 * this may be an active check.
 */
#ifdef HAVE_FWIN
    if ((fwin_windowmode() & FWIN_IN_WINDOW) == 0)
#else
#ifdef WINDOW_SYSTEM
    if (!use_wimp)
#endif
#endif
    {
        if (clock_stack == &consolidated_time[0])
        {   clock_t t0 = read_clock();
/*
 * On at least some (Unix) systems clock_t is a 32-bit signed value
 * and CLOCKS_PER_SEC = 1000000. The effect is that integer overflow
 * occurs after around 35 minutes of running. I must therefore check the
 * clock and move information into a floating point variable at least
 * every half-hour.  With luck I will do it more like 20 times per second
 * because I have code muck like this in a tick handler that is activated
 * on a rather regular basis on at least some systems. On others this
 * clock overfow issue is a bit of a pain and I really ought just to use
 * a different low-level API for timing that can not so suffer. But
 * as a bit of a fall-back I will see if the garbage collector can
 * consolidate time for me and since I ignore time spent waiting for the
 * keyboard overflows due to 35 minutes of activity there will not hurt so
 * I am probably at worst at risk if I can compute for a solid half
 * hour without triggering garbage collection.
 */
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
        prompt_thing = CHAR_EOF;
#ifdef HAVE_FWIN
        fwin_set_prompt("+++ Type C to continue, A to abort, X to exit: ");
#endif

        other_read_action(READ_FLUSH, lisp_terminal_io);
        for (;;)
        {   int c = char_from_terminal(nil);
/*
 * Note that I explicitly say "char_from_terminal()" here - this is because
 * I do not expect to be interrupted unless there was a terminal available
 * to send the interrupt! This is in fact a slightly marginal assumption.
 */
            switch (c)
            {
        case 'c': case 'C':         /* proceed as if no interrupt */
                pop(prompt_thing);
#ifdef HAVE_FWIN
                fwin_set_prompt(prompt_string);
#endif
                return onevalue(p);
        case 'a': case 'A':         /* raise an exception */
                break;
        case 'x': case 'X':
                my_exit(EXIT_FAILURE); /* Rather abrupt */
        case '\n':
#ifndef HAVE_FWIN
                term_printf("C to continue, A to abort, X to exit: ");
#endif
                ensure_screen(); nil = C_nil;
                if (exception_pending()) return nil;
                continue;
        default:                    /* wait for A or C */
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
/*
 * now for the common code to be used in all cases.
 */
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
	err_printf("+++ Interrupted\n");
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? UNWIND_ERROR :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

Lisp_Object aerror(char *s)
{
    Lisp_Object nil = C_nil, w;
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
        err_printf("+++ Error bad args for %s\n", s);
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? UNWIND_ERROR :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

Lisp_Object aerror0(char *s)
{
    Lisp_Object nil = C_nil, w;
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
        err_printf("+++ Error: %s\n", s);
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), nil);
        ignore_exception();
    }
    exit_reason = (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? UNWIND_ERROR :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
#ifdef COMMON
/*
 * This is to help me debug in the face of low level system crashes
 */
    if (spool_file) fflush(spool_file);
#endif
    return nil;
}

Lisp_Object aerror1(char *s, Lisp_Object a)
{
    Lisp_Object nil = C_nil, w;
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
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
    exit_reason = (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? UNWIND_ERROR :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
#ifdef COMMON
/*
 * This is to help me debug in the face of low level system crashes
 */
    if (spool_file) fflush(spool_file);
#endif
    return nil;
}

Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil = C_nil, w;
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
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
    exit_reason = (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? UNWIND_ERROR :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
#ifdef COMMON
/*
 * This is to help me debug in the face of low level system crashes
 */
    if (spool_file) fflush(spool_file);
#endif
    return nil;
}

static Lisp_Object wrong(int wanted, int given, Lisp_Object env)
{
    char msg[64];
    Lisp_Object nil = C_nil;
    CSL_IGNORE(nil);
    sprintf(msg, "Function called with %d args where %d wanted", given, wanted);
    if (is_cons(env)) env = qcdr(env);
    if ((miscflags & (HEADLINE_FLAG|ALWAYS_NOISY)) && is_vector(env))
    {   Lisp_Object fname = elt(env, 0);
        err_printf("\nCalling ");
        loop_print_error(fname);
        err_printf("\n");
    }
    return aerror(msg);
}

Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1)
{
    CSL_IGNORE(a1);
    return wrong(2, 1, env);
}

Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2)
{
    CSL_IGNORE(a1);
    CSL_IGNORE(a2);
    return wrong(1, 2, env);
}

Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1)
{
    CSL_IGNORE(a1);
    return wrong(0, 1, env);
}

Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2)
{
    CSL_IGNORE(a1);
    CSL_IGNORE(a2);
    return wrong(0, 2, env);
}

Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1)
{
    CSL_IGNORE(a1);
    return wrong(3, 1, env);
}

Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2)
{
    CSL_IGNORE(a1);
    CSL_IGNORE(a2);
    return wrong(3, 2, env);
}

Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1)
{
    CSL_IGNORE(a1);
    if (is_cons(env) && is_bps(qcar(env)))
        return wrong(((unsigned char *)data_of_bps(qcar(env)))[0], 1, env);
    else return aerror("function called with 1 arg when 0 or >= 3 wanted");
}

Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2)
{
    CSL_IGNORE(a1);
    CSL_IGNORE(a2);
    if (is_cons(env) && is_bps(qcar(env)))
        return wrong(((unsigned char *)data_of_bps(qcar(env)))[0], 2, env);
    else return aerror("function called with 2 args when 0 or >= 3 wanted");
}

Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...)
{
    CSL_IGNORE(env);
    CSL_IGNORE(nargs);
    return wrong(1, nargs, env);
}

Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...)
{
    CSL_IGNORE(env);
    CSL_IGNORE(nargs);
    return wrong(2, nargs, env);
}

Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2)
{
    CSL_IGNORE(env);
    CSL_IGNORE(a1);
    CSL_IGNORE(a2);
    return aerror("call to special form");
}

Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...)
{
    CSL_IGNORE(env);
    CSL_IGNORE(nargs);
    return aerror("call to special form");
}

void MS_CDECL fatal_error(int code, ...)
{
/*
 * Note that FATAL error messages are sent to the terminal, not to the
 * error output stream. This is because the error output stream may be
 * corrupted in such dire circumstances.
 */
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

static char *dependency_file = NULL;

static char **dependency_map = NULL;
static int dependency_count = 0, dependency_capacity = 0;

void report_file(const char *s)
{
    char *c;
    int i;
    if (dependency_file == NULL) return;
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
    {   if (strcmp(s, dependency_map[i]) == 0) return; /* already recorded */
    }
    c = (char *)malloc(strlen(s) + 1);
    if (c == NULL) return;
    strcpy(c, s);
    dependency_map[dependency_count++] = c;
}

static int alphorder(const void *a, const void *b)
{
    char *aa = *(char **)a;
    char *bb = *(char **)b;
    return strcmp(aa, bb);
}

static void report_dependencies()
{
    FILE *f;
    int i, c;
    char *p;
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
/*
 * If I am on Windows some files may at this stage be shown with names
 * of the form "X:/..." where X denotes the drive. But the dependencies I
 * am creating are for the benefit of the cygwin version of GNU make, and
 * that will get seriously upset by the colon, thinking it is indicating that
 * I have multiple targets. So I will map "X:/" onto "/cygdrive/x/".
 */
        if (p[0] != 0 &&
            p[1] == ':' &&
            (p[2] == '/' || p[2] == '\\'))
        {   fprintf(f, "/cygdrive/%c", p[0]);
            p+=2;
        }
        while ((c = *p++) != 0) putc(c == '\\' ? '/' : c, f);
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

#ifndef __cplusplus
static jmp_buf my_exit_buffer;
static volatile int my_return_code = 0;
#endif

void my_exit(int n)
{
/*
 * This all seems a HORRID MESS. It is here because of a general need to
 * tidy up at the end of a run, and the fact that I may be running as
 * a sub-task of some other package so I can not let atexit() take the
 * strain since although I am exiting CSL here I may not be (quite yet)
 * leaving the whole of the current application.
 */
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
#ifdef __cplusplus
    throw n;
#else
/*
 * When I am compiling in C I will be ultra-cautions and only ever use
 * "1" as the second argument to longjmp. Here, which is the only place
 * where I want to hand back a value I might (often!) want to hand back the
 * value "0", so I put it in a static variable (and make that volatile to
 * help it survive setjmp/longjmp). Doing things this was is also a valuable
 * temporary expedient for the 64-bit variant on mingw at a stage where that
 * is not fully settled!
 */
    my_return_code = n;
    longjmp(my_exit_buffer, 1);
#endif
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
CSLbool segvtrap = YES;
CSLbool batch_flag = NO;
CSLbool ignore_restart_fn = NO;

static void lisp_main(void)
{
    Lisp_Object nil;
    
#ifndef __cplusplus
/*
 * The setjmp here is to provide a long-stop for untrapped
 * floating point exceptions.
 */
    jmp_buf this_level, *save_level = errorset_buffer;
#endif
    tty_count = 0;
    while (YES)
/*
 * The sole purpose of the while loop here is to allow me to proceed
 * for a second try if I get a (cold-start) call.
 */
    {   Lisp_Object *save = stack;
        nil = C_nil;
#ifndef __cplusplus
        errorset_buffer = &this_level;
#endif
        errorset_msg = NULL;
#ifdef __cplusplus
        try
#else
        if (!setjmp(this_level))
#endif
        {   nil = C_nil;
            if (supervisor != nil && !ignore_restart_fn)
            {   miscflags |= HEADLINE_FLAG | MESSAGES_FLAG;
/*
 * Here I reconstruct the argument that I passed in (restart_csl f a).
 */
                if (exit_charvec != NULL)
                {   Lisp_Object a = read_from_vector(exit_charvec);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        a = nil;
                    }
                    free(exit_charvec);
                    exit_charvec = NULL;
                    push(a);
                    apply(supervisor, 1, nil, supervisor);
                }
                else apply(supervisor, 0, nil, supervisor);
            }
/*
 * Here the default read-eval-print loop used if the user has not provided
 * a supervisor function.
 */
            else read_eval_print(lisp_true);
        }
#ifdef __cplusplus
        catch (char *)
#else
        else
#endif
        {   nil = C_nil;
            if (errorset_msg != NULL)
            {   term_printf("\n%s detected\n", errorset_msg);
                errorset_msg = NULL;
            }
            unwind_stack(save, NO);
            exit_reason = UNWIND_ERROR;
            flip_exception();
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
        }
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            if (exit_reason == UNWIND_RESTART)
            {   if (exit_tag == fixnum_of_int(0))      /* "stop" */
                    return_code = (int)int_of_fixnum(exit_value);
                else if (exit_tag == fixnum_of_int(1)) /* "preserve" */
                {   char *msg = "";
                    return_code = EXIT_SUCCESS;
                    compression_worth_while = 128;
                    if (is_vector(exit_value) &&
                        type_of_header(vechdr(exit_value)) == TYPE_STRING)
                        msg = &celt(exit_value, 0);
                    preserve(msg);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        return_code = EXIT_FAILURE;
                    }
                }
                else                                   /* "restart" */
                {   int32_t fd = stream_pushed_char(lisp_terminal_io);
                
                    char new_module[64], new_fn[64]; /* Limited name length */
                    int cold_start;
                    cold_start = (exit_value == nil);
/*
 * Of course a tick may very well have happened rather recently - so
 * I will flush it out now just to clear the air.
 */
                    if (stack >= stacklimit)
                    {   reclaim(nil, "stack", GC_STACK, 0);
                        ignore_exception();
                    }
                    cold_start = (exit_value == nil);
                    Lrds(nil, nil);
                    Lwrs(nil, nil);
/*
 * If either of the above two calls to rds/wrs were to fail I would
 * be in a big mess.
 */
                    if (!cold_start)
                    {   new_module[0] = 0;
                        new_fn[0] = 0;
                        if (exit_value != lisp_true)
                        {   Lisp_Object modname = nil;
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
                                    int32_t len = length_of_header(h) - CELL;
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
                                    int32_t len = length_of_header(h) - CELL;
                                    if (len > 63) len = 63;
                                    memcpy(new_fn,
                                           (char *)exit_value + (CELL - TAG_VECTOR),
                                           (size_t)len);
                                    new_fn[len] = 0;
                                }
                            }
                        }
                    }
                    while (vheap_pages_count != 0)
                        pages[pages_count++] = vheap_pages[--vheap_pages_count];
                    while (heap_pages_count != 0)
                        pages[pages_count++] = heap_pages[--heap_pages_count];
                    while (bps_pages_count != 0)
                        pages[pages_count++] = bps_pages[--bps_pages_count];
/*
 * When I call restart-csl I will leave the random number generator where it
 * was. Anybody who wants to reset if either to a freshly randomised
 * configuration or to a defined condition must do so for themselves. For
 * people who do not care too much what I do here is probably acceptable!
 */
                    CSL_MD5_Init();
                    CSL_MD5_Update((unsigned char *)errcode(err_registration), 32);
                    IreInit();
                    setup(cold_start ? 0 : 1, 0.0);
                    exit_tag = exit_value = nil;
                    exit_reason = UNWIND_NULL;
                    stream_pushed_char(lisp_terminal_io) = fd;
                    interrupt_pending = already_in_gc = NO;
                    tick_pending = tick_on_gc_exit  = NO;
                    if (!cold_start && new_fn[0] != 0)
                    {   Lisp_Object w;
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
/*
 * In all normal cases when read_eval_print exits (i.e. all cases except
 * if it terminates after (cold-start)) I exit here.
 */
#ifndef __cplusplus
        errorset_buffer = save_level;
#endif
        break;
    }
}

#if !defined HAVE_FWIN || defined EMBEDDED
#ifndef UNDER_CE

CSLbool sigint_must_longjmp = NO;
#ifndef __cplusplus
jmp_buf sigint_buf;
#endif

void sigint_handler(int code)
{
/*
 * Note that the only things that I am really allowed to do in a routine
 * like this involve setting variables of type sig_atomic_t, which can not
 * be viewed as much more than boolean.  The code actually used here is
 * somewhat more ambitious (== non-portable!) so must be viewed as delicate.
 * ANSI guarantee that longjmp-ing out of a non-nested signal handler
 * is valid, but some earlier C libraries have not supported this. Note that
 * with C++ I will use throw rather than longjmp.
 */
/*
 * tick_pending etc allow a steady stream of clock events to
 * be handed to Lisp.
 */
    interrupt_pending = 1;
    signal(SIGINT, sigint_handler);
    if (sigint_must_longjmp)
    {
        sigint_must_longjmp = NO;
#ifdef __cplusplus
        throw((int *)0);
#else
        longjmp(sigint_buf, 1);
#endif
    }
/*
 * If there is not a separate regular stream of ticks I will simulate
 * the receipt of a tick here. Thus I need to be able to recognize "ticks"
 * even on systems where there are no "real" ones.
 */
    if (!tick_pending)
    {
        if (already_in_gc) tick_on_gc_exit = YES;
        else
        {
#ifndef NILSEG_EXTERNS
            Lisp_Object nil = C_nil;
            CSLbool xxx = NO;
            if (exception_pending()) flip_exception(), xxx = YES;
#endif
            tick_pending = YES;
            saveheaplimit = heaplimit;
            heaplimit = fringe;
            savevheaplimit = vheaplimit;
            vheaplimit = vfringe;
            savecodelimit = codelimit;
            codelimit = codefringe;
            savestacklimit = stacklimit;
            stacklimit = stackbase;
#ifndef NILSEG_EXTERNS
            if (xxx) flip_exception();
#endif
        }
    }
    return;
}

#endif /* UNDER_CE */
#endif /* HAVE_FWIN */

/*
 * OK, I need to write a short essay on "software ticks". A major issue
 * for me is synchronization between the worker and the GUI tasks. Lisp
 * code can not easily be unilaterally interrupted since it needs to
 * preserve GC safety. The easiest way of making progress that I have come up
 * with is to arrange that the worker thead (ie the Lisp engine) arranges
 * to poll the GUI on a fairly regular basis. I achieve this by making it
 * count down in a variable called "countdown" and when that reaches zero
 * it deems that a poll is due. I put instructions to decrement countdown in
 * a number of places that I expect to be used often enough, and would like
 * to have these within all possible loops and such that they are performed
 * uniformly over time. These are IDEALS not reality! The countdown overflow
 * may happen at somewhat irregular intervals and often at places in the
 * code where I am not GC safe. So what I do is to set heap fringes and
 * stack fringes so that the next time I try to allocate memory or check
 * the stack the situation is noticed and I enter the GC. Once there I
 * rapidly detect that this is not a genuine case of having run out of
 * memory so I do not do a full GC: I just reset the varios fringes and
 * proceed. But while there I know I am in a tidy situation and I can
 * exchange information with the GUI. Perhaps as clear-cut case of
 * consequence that can arise is that I may respond to a GUI request to
 * interrupt what I was doing.
 * I try to tune the value that I count down from to get a rate of polling
 * that I count as "reasonable" - ie a few per second.
 *
 * deal_with_tick() is called when the countdown overflows. It resets the
 * fringe variables to provoke a GC.
 *
 * handle_tick() is then a call back out from the GC and could do more
 * as required.
 */

int32_t software_ticks = 3000;
int32_t number_of_ticks = 0;
int32_t countdown = 3000;

int deal_with_tick(void)
{
#ifdef PENDING_TICK_SUPPORT
    printf("(!)"); fflush(stdout);
    number_of_ticks++;
    if (!tick_pending)
    {
        if (already_in_gc) tick_on_gc_exit = YES;
        else
        {
#ifndef NILSEG_EXTERNS
            Lisp_Object nil = C_nil;
            CSLbool xxx = NO;
            if (exception_pending()) flip_exception(), xxx = YES;
#endif
            tick_pending = YES;
            saveheaplimit = heaplimit;
            heaplimit = fringe;
            savevheaplimit = vheaplimit;
            vheaplimit = vfringe;
            savecodelimit = codelimit;
            codelimit = codefringe;
            savestacklimit = stacklimit;
            stacklimit = stackbase;
#ifndef NILSEG_EXTERNS
            if (xxx) flip_exception();
#endif
        }
    }
#endif
    countdown = software_ticks;
    return 1;
}

static long int initial_random_seed, seed2;

char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
int output_directory;
character_reader *procedural_input;
character_writer *procedural_output;

CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];

int number_of_input_files = 0,
    number_of_symbols_to_define = 0,
    number_of_fasl_paths = 0,
    init_flags = 0;

#ifdef WINDOW_SYSTEM
FILE *alternative_stdout = NULL;
#endif

/*
 * standard_directory holds the name of the default image file that CSL
 * would load.
 */
char *standard_directory;

/*
 * If non-NULL the string module_enquiry is a name presenetd on the
 * command line in a "-T name" request, and this will cause the system
 * to behave in a totally odd manner - it does not run Lisp at all but
 * performs a directory enquiry within the image file.
 */
static char *module_enquiry = NULL;

/*
 * The next lines mean that (if you can get in before cslstart is
 * called) you can get memory allocation done in a custom way.
 */

static void *CSL_malloc(size_t n)
{
    return malloc(n);
}

static void  CSL_free(void *p)
{
    free(p);
}

static void *CSL_realloc(void *p, size_t n)
{
    return realloc(p, n);
}

malloc_function  *malloc_hook = CSL_malloc;
realloc_function *realloc_hook = CSL_realloc;
free_function    *free_hook   = CSL_free;

CSLbool always_noisy = NO;

int load_count = 0, load_limit = 0x7fffffff;

void cslstart(int argc, char *argv[], character_writer *wout)
{
    int i;
    CSLbool restartp;
    double store_size = 0.0;
#ifdef CONSERVATIVE
    volatile Lisp_Object sp;
    C_stackbase = (Lisp_Object *)&sp;
#endif
    always_noisy = NO;
    stack_segsize = 1;
    module_enquiry = NULL;
    countdown = 0x7fffffff;
/* put resource limiting info in a tidy or at least safe state */
    time_base  = space_base  = io_base  = errors_base  = 0;
    time_now   = space_now   = io_now   = errors_now   = 0;
    time_limit = space_limit = io_limit = errors_limit = -1;
/*
 * Note that I will set up clock_stack AGAIN later on! The one further down
 * happens after command line options have been decoded and is where I really
 * want to consider Lisp to be starting. The setting here is because
 * if I call ensure_screen() it can push and pop the clock stack, and
 * especially if I have an error in my options I may print to the terminal
 * and then flush it. Thus I need SOMETHING set up early to prevent any
 * possible frivolous disasters in that area.
 */
    base_time = read_clock();
    consolidated_time[0] = gc_time = 0.0;
    clock_stack = &consolidated_time[0];
#ifdef WINDOW_SYSTEM
    use_wimp = YES;
#ifdef HAVE_FWIN
/*
 * On fwin the "-w" flag should disable all attempts at use of the wimp.
 */
    for (i=1; i<argc; i++)
    {   char *opt = argv[i];
        if (opt == NULL) continue;
        if (opt[0] == '-' && tolower(opt[1] == 'w'))
        {   use_wimp = !use_wimp;
            break;
        }
    }
    fwin_pause_at_end = 1;
#endif
#endif
#ifdef SOCKETS
    sockets_ready = 0;
    socket_server = 0;
#endif
/*
 * Now that the window manager is active I can send output through
 * xx_printf() and get it on the screen neatly.
 */
    procedural_input = NULL;
    procedural_output = wout;
    standard_directory = find_image_directory(argc, argv);
    restartp = YES;
    ignore_restart_fn = NO;
    spool_file = NULL;
    spool_file_name[0] = 0;
    output_directory = 0x80000000;
    number_of_input_files = 0;
    number_of_symbols_to_define = 0;
    number_of_fasl_paths = 0;
    fasl_output_file = NO;
    initial_random_seed = seed2 = 0;
    init_flags = INIT_EXPANDABLE;
    return_code = EXIT_SUCCESS;
    segvtrap = YES;
    batch_flag = NO;
    load_count = 0;
    load_limit = 0x7fffffff;
    {   char *s = REGISTRATION_VERSION;
#define hexval(c) ('0'<=c && c<='9' ? c - '0' : c - 'a' + 10)
#define gx() (s+=2, hexval(s[-1]) + 16*hexval(s[-2]))
        unsigned char *p = registration_data;
        memset(registration_data, 0, sizeof(REGISTRATION_SIZE));
        while (*s != 0) *p++ = *s++;
#ifdef REG1
        s = REG1;
        while (*s != 0) *p++ = gx();
#endif
#ifdef REG2
        s = REG2;
        while (*s != 0) *p++ = gx();
#endif
        CSL_MD5_Init();
        CSL_MD5_Update((unsigned char *)errcode(err_registration), 32);
    }
#ifdef MEMORY_TRACE
    car_counter = 0x7fffffff;
    car_low = 0;
    car_high = 0xffffffff;
#endif

    argc--;
    for (i=1; i<=argc; i++)
    {   char *opt = argv[i];
/*
 * The next line ought never to be activated, but I have sometimes seen
 * unwanted NULL args on the end of command lines so I filter them out
 * here as a matter of security.
 */
        if (opt == NULL || *opt == 0) continue;
        if (opt[0] == '-')
        {   char *w;
            int c1 = opt[1], c2 = opt[2];
            if (isupper(c1)) c1 = tolower(c1);
            switch (c1)
            {

/*
 * -- <outfile> arranges that output is sent to the indicated file. It is
 * intended to behave a little like "> outfile" as command-line output
 * redirection, but is for use in windowed environments (in particular
 * Windows NT) where this would not work.  I had intended to use "->" here,
 * but then the ">" tends to get spotted as a command-line request for
 * redirection, and I would not be using this if command-line redirection
 * worked properly! Actually use of "--" here was a BAD choice since it
 * clashes with the tradition now common elsewhere that fully spelt-out
 * options can be written as "--option". To start to mend that I will
 * now make
 *                 -- filename
 * redirect the standard output, but detect
 *                 --option
 * as an extended option. This is, I guesss, an incompatible change to CSL's
 * behaviour but I rather believe it will be a good one to make and I can
 * issue a message about unrecognised options that will help anybody caught
 * by it.
 */
        case '-':
                if (c2 != 0) 
                {   w = &opt[2];
/*
 * The option "--texmacs" has been detected earlier in fwin.c, so I just
 * detect and ignore it here.
 */
                    if (strcmp(w, "texmacs") == 0)
                    { }
/*
 * At present "--help" (and "--dump-source") are detected and processed
 * earlier - but "--help" is let through to here in case I want to generate
 * some more application-specific help... Right now I do not!
 */
                    if (strcmp(w, "help") == 0)
                    {   my_exit(0);
                    }
                    else
                    {
                        fwin_restore();
                        term_printf("Unknown extended option \"--%s\"\n", w);
                        term_printf("NB: use \"-- filename\" (with whitespace)\n");
                        term_printf("    for output redirection now.\n");
                    }
                    continue;
                }
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                {   char filename[LONGEST_LEGAL_FILENAME];
                    FILE *f;
#ifdef WINDOW_SYSTEM
                    f = open_file(filename, w, strlen(w), "w", NULL);
                    if (f == NULL)
                    {
/*
 * Under FWIN if there is a "--" among the arguments I will start off
 * with the main window minimized. Thus if an error is detected at a
 * stage that the transcript file is not properly opened I need to
 * maximize the window so I can see the error! Note that I will need to
 * ensure that fwin only uses "-- file" not "--option" to do this...
 */
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
/*
 * I use freopen() on stdout here to get my output sent elsewhere.  Quite
 * what sort of mess I am in if the freopen fails is hard to understand!
 * Thus I write a message to stderr and exit promptly in case of trouble.
 * I print a message explaining what I am doing BEFORE actually performing
 * the redirection.
 */
                    fprintf(stderr, "Output to be redirected to \"%s\"\n", w);
                    f = open_file(filename, w, strlen(w), "w", stdout);
                    if (f == NULL)
                    {   fprintf(stderr, "Unable to write to \"%s\"\n",
                                        filename);
#ifdef HAVE_FWIN
#ifdef __cplusplus
                        throw EXIT_FAILURE;
#else
                        my_return_code = EXIT_FAILURE;
                        longjmp(my_exit_buffer, 1);
#endif
#else
                        exit(EXIT_FAILURE);
#endif
                    }
#endif
                }
                continue;

/*
 * -a is a curious option, not intended for general or casual use. If given
 * it causes the (batchp) function to return the opposite result from
 * normal!  Without "-a" (batchp) returns T either if at least one file
 * was specified on the command line, or if the standard input is "not
 * a tty" (under some operating systems this makes sense - for instance
 * the standard input might not be a "tty" if it is provided via file
 * redirection).  Otherwise (ie primary input is directly from a keyboard)
 * (batchp) returns nil.  Sometimes this judgement about how "batch" the
 * current run is will be wrong or unhelpful, so "-a" allows the user to
 * coax the system into better behaviour.  I hope that this is never used!
 * At one stage this option was called "-b" not "-a" (so I will now pretend
 * that "-a" is for "alternate" or some such nonsense.
 */
        case 'a':
                batch_flag = YES;
                continue;
/*
 * -b tells the system to avoid any attempt to recolour prompts and
 * input text. It will mainly be needed on X terminals that have been set up
 * so that they use colours that make the defaults here unhelpful.
 * Specifically white-on-black and so on.
 * -b can be followed by colour specifications to make things yet
 * more specific.
 */
        case 'b':
/*
 * Actually "-b" is detected and processed by fwin (if present) before
 * this bit of the code is invoked (much as "-w" is). Thus I do not have
 * to do anything here!
 */
               continue;

/*
 * The option "-C" just prints a dull and unimaginative copyright notice -
 * having this option in there will tend to ensure that a copyright
 * message is embedded in the object code somehow, while with luck nobody
 * will be bothered too much by the fact that there is a stray option to get
 * it displayed.  Note that on some systems there is a proper character
 * for the Copyright symbol... but there is little agreement about what
 * that code is! Furthermore to avoid needing to include Copyright statements
 * on behalf of any and all LGPL components I will make this an authorship
 * statement rather than a copyright claim!
 */
        case 'c':
                fwin_restore();
                term_printf("\nCSL was coded by Codemist Ltd, 1988-2008\n");
                term_printf("Distributed under the Modified BSD License\n");
#ifdef HAVE_LIBFOX
                term_printf("See also --help and --dump-source\n");
#endif
                continue;

/*
 * -D name=val   defines a symbol at the start of a run
 * I permit either
 *                  -Dname=val
 * or               -D name=val
 */
        case 'd':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                    symbols_to_define[number_of_symbols_to_define] = w,
                    undefine_this_one[number_of_symbols_to_define++] = NO;
                else
                {
                    fwin_restore();
                    term_printf("Too many \"-D\" requests: ignored\n");
                }
                continue;

#ifndef DEMO_MODE
/*
 *                      -E
 * This option is for an EXPERIMENT.  It may do different things in different
 * releases of CSL. In most cases it will not do anything! And certainly
 * I may change what it does without notice or upwards compatibility. Right
 * now it controls a way that can limit the loading of dynamically loadable
 * native code, and I need that for performance measurement and debugging.
 */
        case 'e':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break;
                if (sscanf(w, "%d", &load_limit) != 1)
                    load_limit = 0x7fffffff;
                continue;
#endif

#ifndef DEMO_MODE
#ifdef SOCKETS
        case 'f':
/*
 *                     -F
 * This is used with syntax -Fnnn or -F nnn (with nnn a number above
 * 1000 but less than 65536) to cause the system to run not as a normal
 * interactive application but as a server listening on the indicated port.
 * The case -F- (which could of course be "-F -") indicates use of the
 * default port for CSL, which I hereby declare to be 1206. This number may
 * need to be changed later if I find it conflicts with some other common
 * package or usage, but was selected in memory of the project number
 * at one time allocated to the Archimedeans Computing Group.
 * On some systems if I want to set up a server that can serve multiple
 * clients I may need to re-invoke CSL afresh for each new client, and in
 * such cases the internally generated tasks can be passed information
 * from their parent task using -F followed by non-numeric information.
 * Any user who attempts such usage will get "what they deserve".
 */
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
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
                {
                    fwin_restore();
                    term_printf("\"%s\" is valid (want port:users:store\n", w);
                    continue;
                }
                store_size = (double)remote_store;
                init_flags &= ~INIT_EXPANDABLE;
                current_users = 0;
/*
 * The code here is probably a bit painfully system-specific, and so one
 * could argue that it should go in a separate file. However a LOT of the
 * socket interface is the same regardless of the host, or a few simple
 * macros can have made it so. So if SOCKETS has been defined I will
 * suppose I can continue here on that basis. I do quite want to put the
 * basic socket code in csl.c since it is concerned with system startup and
 * the selection of sources and sinks for IO.
 */
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
                    {
                        fwin_restore();
                        term_printf("Unable to create a socket\n");
                        continue;
                    }
                    server_address.sin_family = AF_INET;
                    server_address.sin_port = htons(port_number);
                    server_address.sin_addr.s_addr = INADDR_ANY;
                    memset((char *)&(server_address.sin_zero), 0, 8);
                    if (bind(sock1, (struct sockaddr *)&server_address,
                             sizeof(struct sockaddr)) == SOCKET_ERROR)
                    {
                        fwin_restore();
                        term_printf("Unable to bind socket to port %d\n",
                                     port_number);
                        closesocket(sock1);
                        continue;
                    }
                    if (listen(sock1, PERMITTED_BACKLOG) == SOCKET_ERROR)
                    {
                        fwin_restore();
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
                        {
                            fwin_restore();
                            term_printf("Trouble with accept()\n");
                            continue;  /* NB local continue here */
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
/*
 * Here I have a bit of a mess. Under Unix I can do a fork() so that the
 * requests that are coming in are handled by a separate process. The
 * code is pretty easy. However with Windows I can only create a fresh process
 * by re-launching CSL from the file it was originally fetched from. I
 * will try to do that in a while, but for now I will leave the
 * Windows version of this code only able to handle a single client
 * session.
 */
#ifdef WIN32
                        closesocket(sock1);
                        socket_server = sock2;
                        cpu_timeout = clock() + CLOCKS_PER_SEC*MAX_CPU_TIME;
                        elapsed_timeout = time(NULL) + 60*MAX_ELAPSED_TIME;
                        procedural_output = char_to_socket;
                        term_printf("Welcome to the Codemist server\n");
                        ensure_screen();
                        break;
#else /* WIN32 */
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
                        {   /* Child process here */
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
/*
 * This loops serving as many clients as happen to come along. Having said
 * "csl -fnnn" it will be necessary (in due course) to kill the daemon
 * by interrupting it with a ^C or some such. When the master process is
 * terminated in that way any clients that remain active may continue to
 * hang around until they have finished in the usual way.
 */
                        }
#endif /* WIN32 */
                    }
                }
/*
 * The "continue" here gets executed when I have been contacted by some
 * client and have an active socket open. It parses the rest of the
 * command line and then completes the process of getting CSL running.
 */
                continue;
#endif
#endif /* DEMO_MODE */

/*
 *                      -G
 * is a debugging option - it sets !*backtrace to true, which applications
 * may inspect when they want to do errorsets etc.  These days I will
 * make it FORCE all errors to be noisy whatever the user tries to do! The
 * rationale for that is that some user code may have said
 *            (errorset X nil nil)
 * and then errors within X become very hard to track. The "-g" option
 * overrides the "nil nil" bit!
 */
        case 'g':
                if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                    symbols_to_define[number_of_symbols_to_define] =
                        "*backtrace",
                    undefine_this_one[number_of_symbols_to_define++] = NO;
                else
                {
                    fwin_restore();
                    term_printf("Too many requests: \"-G\" ignored\n");
                }
                always_noisy = YES;
                continue;
/*
 *                      -H
 * render fonts on X host rather than X client (ie disable use of Xft and
 * and Xrender if they might otherwise have been in use). This should have
 * no effect on Windows and no effect if the system that the code was built
 * on did not support Xft.
 */
        case 'h':
                fwin_use_xft = 0;
/*
 * Actually, like the "-w" option, it is TOO LATE to do this here because
 * lower-level parts of fwin may already have adjusted font paths using
 * mechanisms based on whether Xft is to be activated or not. So fwin
 * checks for "-h" and "-H" and interprets what it finds. So what I do here
 * is just a redundant reminder. Ugh.
 */
                continue;

/*
 * -I is used to specify an image file to be used when CSL starts up.
 * The case -I- indicated the "standard" file associated with this
 * executable binary.  Several images can be given.
 */
#ifndef DEMO_MODE
        case 'i':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                if (w[0] == '-' && w[1] == 0) w = standard_directory;
                if (number_of_fasl_paths < MAX_FASL_PATHS-1)
                    fasl_paths[number_of_fasl_paths++] = w;
                else
                {
                    fwin_restore();
                    term_printf("Too many \"-I/-O\" requests: ignored\n");
                }
                continue;
#endif

/*
 * -J enabled the "track dependencies" hack that I have. Every time
 * that a file is opened for reading it records the file-name concerned
 * and at the end of everything it dumps a record of all the distinct
 * files to the named placem as in "-J fileuse.dat"
 */
        case 'j':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                dependency_file = w;
                continue;

/*
 * -K nnn sets the size of heap to be used.  If it is given then that much
 * memory will be allocated and the heap will never expand.  Without this
 * option a default amount is used, and (on many machines) it will grow
 * if space seems tight.
 * The extended version of this option is "-K nnn/ss" and then ss is the
 * number of "CSL pages" to be allocated to the Lisp stack. The default
 * value (which is 1) should suffice for almost all users, and it should
 * be noted that the C stack is separate from and independent of this one and
 * it too could overflow.
 * A form like -K6000K              indicates that many kilobytes
 *             -K200M or just -K200 indicates that many megabytes
 *             -K1.6G               indicates that many gigabytes
 */
#ifndef DEMO_MODE
        case 'k':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                {   char buffer[16];
                    int i = 0;
                    while ((*w != '/') && 
                           (*w != 'k') && (*w != 'K') &&
                           (*w != 'm') && (*w != 'M') &&
                           (*w != 'g') && (*w != 'G') &&
                           (*w != 0) &&
                           (i<sizeof(buffer)-1))
                        buffer[i++] = *w++;
                    buffer[i] = 0;
/*
 * store size gets set here: 0.0 is left if either that is specified
 * explictly or if no -K option is given. That will be treated as
 * indicating "use default, and expand memory as you go"
 */
                    store_size = atof(buffer);
                    if (store_size == 0.0) init_flags |= INIT_EXPANDABLE;
                    else
                    {   init_flags &= ~INIT_EXPANDABLE;
/*
 * If an explicit store size has been indicated I will see if it had one
 * of the letters K, M or G after it (note that I allow it to be a floating
 * point value.
 */
                        switch (*w)
                        {
                    case 'k': case 'K':
                            break;
                    case 'g': case 'G':
                            store_size *= 1024.0*1024.0;
                            break;
                    default:   /* megabytes by default */
                            store_size *= 1024.0;
                            break;
                        }
/*
 * Now the measure is adjusted so it is in units of kilobytes. I will
 * set a lower limit to how much can be asked for to try to prevent
 * utter congestion. I will also set an upper limit to provide some minor
 * protection.
 */
#if PAGE_BITS==18
                        if (store_size < 10000.0) store_size = 10000.0;
#else
                        if (store_size < 32000.0) store_size = 32000.0;
#endif
/*
 * At present I limit even 64-bit systems to 50 Gbytes.
 * ... and 32-bit systems to 1.9 Gbytes.
 */
                        if ((!SIXTY_FOUR_BIT &&
                             (store_size > 1.9*1024.0*1024.0)) ||
                            (store_size > 50*1024.0*1024.0))
                        {
                            fwin_restore();
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
#endif

/*
 * -L <logfile> arranges that a transcript of the standard output is
 * sent to the given file, just as if (spool '<logfile>) had been executed
 * at the start of the run.
 */
        case 'l':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                {   char filename[LONGEST_LEGAL_FILENAME];
                    spool_file = open_file(filename, w,
                           strlen(w), "w", NULL);
                    if (spool_file == NULL)
                    {
                        fwin_restore();
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

#ifndef DEMO_MODE
#ifdef MEMORY_TRACE
/*
 * If MEMORY_TRACE is set up then I can cause an exception by providing
 * an option -M n:l:h 
 * This interrupts after n memory records when a reference in the (inclusive)
 * range l..h is next made.
 */
        case 'm':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                switch(sscanf(w, "%ld:%lu:%lu",
                               &car_counter, &car_low, &car_high))
                {
            case 0: car_counter = 0x7fffffff;
            case 1: car_low = 0;
            case 2: car_high = 0xffffffff;
            default:break;
                }
                continue;
#endif
#endif

/*
 * -N tells CSL that even if the image being loaded contains a restart-
 * function this should be ignored, and Lisp should run the default
 * read-eval-print loop. The only expected use for this is when an image
 * has been created but it is seriously broken, so the way it would
 * usually restart would crash - then "-N" may allow a suitable expert to
 * test and diagnose the trouble at the Lisp level. Ordinary users are
 * NOT expected to want to know about this!
 */
#ifndef DEMO_MODE
        case 'n':               /* Ignore restart function (-N) */
                ignore_restart_fn = YES;
                continue;
#endif

/*
 * -O <file>  specifies an image file for output (via FASLOUT or PRESERVE).
 */
#ifndef DEMO_MODE
        case 'o':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                if (w[0] == '-' && w[1] == 0) w = standard_directory;
                if (number_of_fasl_paths < MAX_FASL_PATHS-1)
                {   output_directory = number_of_fasl_paths;
                    fasl_paths[number_of_fasl_paths++] = w;
                }
                else
                {
                    fwin_restore();
                    term_printf("Too many \"-I/-O\" requests: ignored\n");
                }
                continue;
#endif

/*
 * -P is reserved for profile options.
 */
        case 'p':
/*
 * Please implement something for your favourite system here... what I would
 * like would be a call to monitor() or some such...
 */
#ifndef DEMO_MODE
                fwin_restore();
                term_printf("Unimplemented option \"-%c\"\n", c1);
                continue;
#endif

/*
 * -Q selects "quiet" mode.  See -V for the converse.
 */
        case 'q':
                if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
/*
 *                  symbols_to_define[number_of_symbols_to_define] =
 *                      "*echo=nil",
 *                  undefine_this_one[number_of_symbols_to_define++] = NO,
 */
                    init_flags &= ~INIT_VERBOSE,
                    init_flags |= INIT_QUIET;
                else
                {
                    fwin_restore();
                    term_printf("Too many requests: \"-Q\" ignored\n");
                }
                continue;

/*
 * -R nnn   sets the initial random seed, for reproducible runs.  -R 0
 * (the default) sets the initial seed based on the time of day etc.
 * The version -R  nnn,mmm makes it possible to pass 64-bits of seed info.
 */
        case 'r':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                if (sscanf(w, "%ld,%ld", &initial_random_seed, &seed2) != 2)
                {   initial_random_seed = seed2 = 0;
                    sscanf(w, "%ld", &initial_random_seed);
                }
                continue;

/*
 * -S  sets the variable !*plap, which causes the compiler to list the
 * bytecodes that it generates. This is probably frivolous but is
 * provided inspired by the typical C compilers "cc -S" option.
 */
        case 's':
                if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                    symbols_to_define[number_of_symbols_to_define] =
                        "*plap",
                    undefine_this_one[number_of_symbols_to_define++] = NO;
                else
                {
                    fwin_restore();
                    term_printf("Too many requests: \"-S\" ignored\n");
                }
                continue;
/*
 * -T name     reports the time-stamp on the named module, and then
 *             exits. This is for use in perl scripts and the like, and is
 *             needed because the stamps on modules within an image or
 *             library file are not otherwise instantly available.
 *
 *             Note that especially on windowed systems it may be
 *             necessary to use this with "-- filename" since the information
 *             generated here goes to the default output unit, which in
 *             some cases is just the screen.
 */
#ifndef DEMO_MODE
        case 't':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                module_enquiry = w;
                continue;
#endif

/*
 * -U name     undefines the symbol <name> at the start of the run
 */
        case 'u':
                if (c2 != 0) w = &opt[2];
                else if (i != argc) w = argv[++i];
                else break; /* Illegal at end of command-line */
                if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                    symbols_to_define[number_of_symbols_to_define] = w,
                    undefine_this_one[number_of_symbols_to_define++] = YES;
                else
                {
                    fwin_restore();
                    term_printf("Too many \"-U\" requests: ignored\n");
                }
                continue;
/*
 * -V selects "verbose" options at the start of the run
 */
#ifndef DEMO_MODE
        case 'v':
                if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
/*
 *                  symbols_to_define[number_of_symbols_to_define] =
 *                      "*echo",
 *                  undefine_this_one[number_of_symbols_to_define++] = NO,
 */
                    init_flags &= ~INIT_QUIET,
                    init_flags |= INIT_VERBOSE;
                else
                {
                    fwin_restore();
                    term_printf("Too many requests: \"-V\" ignored\n");
                }
                continue;
#endif
    
#ifdef WINDOW_SYSTEM
/*
 * On systems where I can run in either windowed or command-line mode this
 * flag controls that aspect of behaviour.
 */
        case 'w':
/*
 * I need to detect and process this flag especially early, and so by the time
 * I get to regular command decoding there is nothing to be done.
 * Within fwin the option "-w" says "do NOT try to use a window, ie
 * run as a console style application", while "-w+" says "Even if
 * all the rest of the schemes that I have indicate that you should
 * run in console mode (eg if standard input is from a pipe, which it
 * will be when running under some debuggers) try to create and use a
 * window.
 */
                continue;
#endif

/*
 * -x is an "undocumented" option intended for use only by system
 * support experts - it disables trapping if segment violations by
 * errorset and so makes it easier to track down low level disasters -
 * maybe!  Only those who have access to the source code can make
 * good use of the -X option, so it is only described here!
 */
#ifndef DEMO_MODE
        case 'x':
                segvtrap = NO;
                continue;
#endif
/*
 * -Y  sets the variable !*hankaku , which causes the lisp reader convert
 * a Zenkaku code to Hankaku one when read. I leave this option decoded
 * on the command line even if the Kanji support code is not otherwise
 * compiled into CSL just so I can reduce conditional compilation.
 * This was part of the Internationalisation effort for CSL but I repeat
 * that it is no longer supported.
 */
#ifndef DEMO_MODE
        case 'y':
                if (number_of_symbols_to_define < MAX_SYMBOLS_TO_DEFINE)
                    symbols_to_define[number_of_symbols_to_define] =
                        "*hankaku",
                    undefine_this_one[number_of_symbols_to_define++] = NO;
                else
                    term_printf("Too many requests: \"-Y\" ignored\n");
                continue;
#endif

/*
 * -Z tells CSL that it should not load an initial heap image, but should
 * run in "cold start" mode.  This is only intended to be useful for
 * system builders.
 */
#ifndef DEMO_MODE
        case 'z':               /* Cold start option -z */
                restartp = NO;
                continue;
#endif

        default:
                fwin_restore();
                term_printf("Unrecognized option \"-%c\"\n", c1);
                continue;
            }
/*
 * I do a "break" out of the switch() block if a key occurs at the end
 * of the command line in an invalid manner.
 */
            fwin_restore();
            term_printf("Option \"-%c\" needs an argument: ignored\n", c1);
            break;
        }
        else files_to_read[number_of_input_files++] = opt;
    }

    if (number_of_fasl_paths == 0)
    {   char *p = standard_directory, *p1;
        char cur[LONGEST_LEGAL_FILENAME];
/*
 * If the user does not specify any image files then the behaviour
 * defaults as follows:
 *   Suppose that the current executable is xxx/yyy/zzz then the
 * system behaves as if the user had written
 *    zzz -o zzz.img -i xxx/yyy/zzz.img
 * however if the executable seemed to be in the current directory
 * already this is reduced to just
 *    zzz -o zzz.img
 * so that I do not have two different handles on the same image file
 * (with the potential muddle that that could result in).
 *
 * NOTE: this used very generally mean that you ended up with an empty image
 * file (eg csl.img or reduce.img) in whatever directory you run this
 * code from. This could be avoided by running it as
 *    xxx -i-
 * that explicitly sets up the normal image file as the one to use with
 * no extras. However these days I try to arrange that an output image file
 * only ever gets created if somebody calls FASLOUT or PRESERVE, so what
 * I describe here will usually not cause confusion....
 *
 * The "image" here can now be in onw of two forms. The one that I historically
 * used with CSL was that an image "xxx.img" was a single file that was set
 * up with internal directories so that it acted as a composite unit holding
 * many sub-files within it. That has the potential convenience that it is
 * a single file to distribute and it is hard for there to be confuson about
 * corruption or loss of the various sub-files within it. This scheme will
 * still be used if xxx.img is a single file. But if on start-up xxx.img is a
 * directory, or if it does not exist to start with and is named in the form
 * "xxx.img/" with a trailing directory separator then the various sub-items
 * will merely be stored within that directory. That moves the strain of
 * managing them onto the operating system, but means that the operating system
 * will maintain date-stamps on each sub-file and this may be useful if you
 * wish to use "make" to maintain a project. It will be possible to have both
 * a single-file and a directory based image open at the same time and copy
 * at least some modules from one to another under program control.
 *
 * At present I still view the one-file solution as neater and so it is the
 * default. The names used for files witin a directory are discussed in the
 * places where I manage them.
 */
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
/*
 * If output_directory has the 0x40000000 bit set then the directory
 * involved is one that should be opened now if it exists, but if
 * it does not its creation should be deferred for as long as possible.
 */
            output_directory = 0x40000000 + 0;
            number_of_fasl_paths = 1;
            if (p1 != NULL) (*free_hook)(p1);
        }
        else
        {   strcpy(p1, p+1);
            fasl_paths[0] = p1;
            fasl_paths[1] = standard_directory;
            output_directory = 0x40000000 + 0;
            number_of_fasl_paths = 2;
        }
    }

    Iinit();  /* Initialise "file system" for image files */

    if (module_enquiry != NULL)
    {   char datestamp[32], fullname[LONGEST_LEGAL_FILENAME];
        int32_t size;
        int i;
        Lisp_Object nil;
/*
 * Imodulep expects input_libraries to be set up. So I will fudge the
 * creation of something that looks sufficiently like a list to pass muster
 * here despite the full system not being loaded. I use references to the
 * nil-segment and cons().
 */

        nilsegment = (Lisp_Object *)my_malloc(NIL_SEGMENT_SIZE);
#ifdef COMMON
        nil = doubleword_align_up(nilsegment) + TAG_CONS + 8;
#else
        nil = doubleword_align_up(nilsegment) + TAG_SYMBOL;
#endif
        C_nil = nil;
        pages_count = heap_pages_count = vheap_pages_count =
            bps_pages_count = native_pages_count = 0;
        stacksegment = (Lisp_Object *)my_malloc(CSL_PAGE_SIZE);
/*
 * I am lazy about protection against malloc failure here.
 */
        heaplimit = doubleword_align_up(stacksegment);
        fringe = heaplimit + CSL_PAGE_SIZE - 16;
        input_libraries = heaplimit + 16 + TAG_SYMBOL;
        heaplimit += 64;
/*
 * I have now fudged up enough simulation of a Lisp heap that maybe I can
 * build the library search-list.
 */
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
/*
 * If I do NOT have a window system I will print a newline here so that I
 * can be very certain that my banner appears at the start of a line.
 * With a window system I should have a brand-new frash window for output
 * and the newline would intrude as an initial blank line.
 */
            term_printf("\n");
#endif

#ifndef COMMON
            term_printf("Codemist Standard Lisp %s for %s: %s\n",
                     VERSION, IMPNAME, __DATE__);
#else
            term_printf("Codemist Common Lisp %s for %s: %s\n",
                     VERSION, IMPNAME, __DATE__);
#endif
        }
#ifdef MEMORY_TRACE
        if (car_counter != 0x7fffffff)
            term_printf("Stop after %ld %lu..%lu\n",
                        car_counter, car_low, car_high);
#endif
#ifdef WINDOW_SYSTEM
        ensure_screen();
/* If the user hits the close button here I may be in trouble */
#endif

/*
 * Now dynamic code detects the floating point representation that is in use.
 * I thougt/hoped that doing it this way would be safer than relying on having
 * pre-defined symbols that tracked the machine architecture.
 */
        {   union fpch { double d; unsigned char c[8]; } d;
/*
 * The following looks at the floating point representation of the
 * number 1/7 (in double precision) and picks out two bytes from
 * the middle of the first word - where I hope that rounding issues
 * will be remote.  Investigation shows that these two bytes can be
 * used to discriminate among at least a worthwhile range of
 * representations, and I will exploit this to help me re-load
 * heap-images in a way that allows images to be portable across
 * different architectures.
 */
            d.d = 1.0/7.0;
            switch ((d.c[1] << 8) | d.c[2])
            {
        case 0x2449:    current_fp_rep = 0;
                        break;           /* Intel, MIPS */
        case 0x49c2:    current_fp_rep = FP_WORD_ORDER;
                        break;           /* ARM */
        case 0x4924:    current_fp_rep = FP_BYTE_ORDER;
                        break;           /* may never happen? */
        case 0xc249:    current_fp_rep = FP_WORD_ORDER|FP_BYTE_ORDER;
                        break;           /* SPARC */
/*
 * The next line is probably not very good under a window manager, but
 * it is a case that ought never to arise, so I will not bother.
 */
        default:        term_printf("Unknown floating point format\n");
                        my_exit(EXIT_FAILURE);
            }
        }

/*
 * Up until the time I call setup() I may only use term_printf for
 * output, because the other relevant streams will not have been set up.
 */
#ifdef DEMO_MODE
        setup(7, 0.0);   /* Force warm start, flag as demo mode */
#else
        setup(restartp ? 3 : 2, store_size);
#endif
/*
 * I need to set the NOISY flag after doing setup to avoid it getting
 * reloaded from a heap image
 */
        {   nil_as_base
            if (always_noisy) miscflags |= (ALWAYS_NOISY | 3);
	    else miscflags &= ~ALWAYS_NOISY;
        }

#ifndef COMMON
#ifdef HAVE_FWIN
        fwin_menus(loadable_packages, switches, review_switch_settings);
#endif
#endif

/*
 * Now that setup is complete (and I have done any authorisation I want to)
 * I will seed the random number generator as requested by the user. The
 * default will be to put it in an unpredictable (well hard to predict!)
 * state
 */
        Csrand((uint32_t)initial_random_seed, (uint32_t)seed2);

        gc_time += pop_clock();

        countdown = software_ticks;
        interrupt_pending = already_in_gc = NO;
        tick_pending = tick_on_gc_exit  = NO;

#ifndef HAVE_FWIN
/*
 * "^C" trapping and handling happens within fwin if that is available.
 */
#ifndef UNDER_CE
        sigint_must_longjmp = NO;
        signal(SIGINT, sigint_handler);
#endif
#endif
        ensure_screen();
        procedural_output = NULL;
#ifdef HAVE_FWIN
/*
 * OK, if I get this far I will suppose that any messages that report utter
 * disasters will have reached the user, so I can allow FWIN to terminate
 * rather more promptly.
 */
        fwin_pause_at_end = 0;
#endif
    }
#ifdef HAVE_FWIN
#ifdef HAVE_LIBFOX
/*
 * Activate the BREAK and BACKTRACE menu items. Note not needed unless
 * FOX is used and so there is a prospect of theer actually being menus!
 */
/*
 * The next line causes a MOAN using Sun's compiler, ending up with
 * an undefined reference to fwin_callback_to_interrupt!
 */
    fwin_callback_to_interrupt(async_interrupt);
#endif /* HAVE_LIBFOX */
#endif /* HAVE_FWIN */
}

#ifdef SOCKETS

#define SOCKET_BUFFER_SIZE 1024
/*
 * The following two "character codes" are used when CSL is run as
 * a socket server and wrap around prompt text. This could be in
 * conflict with any code that tries to use these codes for other
 * purposes or that handles prompts itself...
 */
#define CH_PROMPT          0x9a
#define CH_ENDPROMPT       0x9c

static char socket_in[SOCKET_BUFFER_SIZE], socket_out[SOCKET_BUFFER_SIZE];
static int socket_in_p = 0, socket_in_n = 0,
           socket_out_p = 0, socket_prev = '\n';

static int char_from_socket(void)
{
    int c;
    clock_t c0;
    time_t t0;
    if (socket_server == 0)
    {   socket_prev = ' ';
        return EOF;
    }
/*
 * I generate a prompt whenever I am about to read the character that
 * follows a newline. The prompt is issued surrounded by control
 * characters 0x9a and 0x9c. That curious arrangement is inherited from
 * internal behaviour in my Windows interface code and could be altered
 * if something truly better could be invented.
 */
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
            {    cpu_timeout = c0 + 20;
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
                    Sleep(1000);  /* Arg in milliseconds here */
#else
                    sleep(1);  /* Delay 1 second before re-polling */
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
{
    if (socket_server == 0) return 1;
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
{
    if (socket_server == 0) return;
    if (send(socket_server, socket_out, socket_out_p, 0) < 0)
    {   closesocket(socket_server);
        socket_server = 0;
    }
    socket_out_p = 0;
}

#endif

static void cslaction(void)
/*
 * This is the "standard" route into CSL activity - it uses file-names
 * from the decoded command-line as files to be read and processed
 * unless the system was launched with the flag that says it ought to try
 * to provide a network service on some socket.
 */
{
#ifdef CONSERVATIVE
    volatile Lisp_Object sp;
    C_stackbase = (Lisp_Object *)&sp;
#endif
#ifdef __cplusplus
    errorset_msg = NULL;
    try
#else
    jmp_buf this_level;
    errorset_buffer = &this_level;
    errorset_msg = NULL;
    if (!setjmp(this_level))
#endif
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
#ifdef SOCKETS
        if (socket_server)
        {   ensure_screen();
            procedural_input = char_from_socket;
            procedural_output = char_to_socket;
            lisp_main();
            ensure_screen();
            procedural_input = NULL;
            procedural_output = NULL;
        }
        else
#endif
        if (number_of_input_files == 0) lisp_main();
        else
        {   int i;
            for (i=0; i<number_of_input_files; i++)
            {   char filename[LONGEST_LEGAL_FILENAME];
                FILE *f = open_file(filename, files_to_read[i],
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
#ifdef __cplusplus
    catch (char *)
#else
    else
#endif
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
    volatile Lisp_Object sp;
    C_stackbase = (Lisp_Object *)&sp;
#endif
    procedural_output = w;
    if (Ifinished())
        term_printf("\n+++ Errors on checkpoint-image file\n");
#ifdef TRACED_EQUAL
    dump_equals();
#endif
/*
 * clock_t is an arithmetic type but I do not know what sort - so I
 * widen to double to do arithmetic on it. Actually what I MUST do is
 * to compute a time difference in the type clock_t and hope I never
 * get a difference that that overflows. The worst case I know of overflows
 * after 35 minutes.
 */
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

/*
 * People who want to use this in an embedded context can predefine
 * NO_STARTUP_CODE and provide their own entrypoint...
 */

#ifndef NO_STARTUP_CODE

/*
 * The next fragment of code is to help with the use of CSL (and hence
 * packages written in Lisp and supported under CSL) as OEM products
 * embedded within larger C-coded packages.  There is (of course) a
 * significant issue about clashes between the names of external symbols
 * if CSL is to be linked with anything else, but I will not worry about that
 * just yet.
 * The protocol for calling Lisp code from C is as follows:
 *
 *     cslstart(argc, argv, writer);allocate memory and Lisp heap etc. Args
 *                                  should be "as if" CSL was being called
 *                                  directly and this was the main entrypoint.
 *                                  The extra arg accepts output from this
 *                                  stage.  Use NULL to get standard I/O.
 *     execute_lisp_function(fname, reader, writer);
 *                                  fname is a (C) string that names a Lisp
 *                                  function of 0 args.  This is called with
 *                                  stdin/stdout access redirected to use the
 *                                  two character-at-a-time functions passed
 *                                  down.  [Value returned indicates if
 *                                  the evaluation succeeded?]
 *     cslfinish(writer);           Tidies up ready to stop.
 */
 
int execute_lisp_function(char *fname,
    character_reader *r, character_writer *w)
{
    Lisp_Object nil;
    Lisp_Object ff;
#ifdef CONSERVATIVE
    volatile Lisp_Object sp;
    C_stackbase = (Lisp_Object *)&sp;
#endif
    ff = make_undefined_symbol(fname);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        return 1;  /* Failed to make the symbol */
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
        return 2;  /* Failure during evaluation */
    }
    return 0;
}

#ifdef SAMPLE_OF_PROCEDURAL_INTERFACE

static char ibuff[100], obuff[100];
static int ibufp = 0, obufp = 0;
static int iget()
{
    int c = ibuff[ibufp++];
    if (c == 0) return EOF;
    else return c;
}

static void iput(int c)
{
    if (obufp < sizeof(obuff)-1)
    {   obuff[obufp++] = c;
        obuff[obufp] = 0;
    }
}

#endif

static int submain(int argc, char *argv[])
{
    cslstart(argc, argv, NULL);
#ifdef SAMPLE_OF_PROCEDURAL_INTERFACE
    strcpy(ibuff, "(print '(a b c d))");
    execute_lisp_function("oem-supervisor", iget, iput);
    printf("Buffered output is <%s>\n", obuff);
#else
    if (module_enquiry == NULL) cslaction();
#endif
    my_exit(cslfinish(NULL));
/*
 * The "return 0" here is unreachable but it still quietens down as many
 * C compilers as it causes to moan noisily!
 */
    return 0;
}

#if defined HAVE_FWIN && !defined EMBEDDED 
#define ENTRYPOINT fwin_main

extern int ENTRYPOINT(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    fwin_set_lookup(look_in_lisp_variable);
    return fwin_startup(argc, argv, ENTRYPOINT);
}

#else
#define ENTRYPOINT main
#endif


int ENTRYPOINT(int argc, char *argv[])
{
    int res;
#ifdef EMBEDDED
    if (find_program_directory(argv[0]))
    {   fprintf(stderr, "Unable to identify program name and directory\n");
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
#ifndef EMBEDDED
    strcpy(about_box_title, "About CSL");
    strcpy(about_box_description, "Codemist Standard Lisp");
#endif
#endif
#ifdef __cplusplus
    try { res = submain(argc, argv); }
    catch(int r) { res = r; }
#else
    if (!setjmp(my_exit_buffer)) res = submain(argc, argv);
    else res = my_return_code;
#endif
#ifdef USE_MPI
    MPI_Finalize();
#endif
    return res;
}

#endif /* NO_STARTUP_CODE */

/* End of csl.c */

