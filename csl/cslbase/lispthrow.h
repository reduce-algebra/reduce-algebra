// lispthrow.h                                      Copyright Codemist 2017

// Some exception processing stuff for CSL

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

#ifndef __lispthrow_h
#define __lispthrow_h 1


// If I know just how mant items will need removing from the stack I
// can create an instance of this class and the stack will be popped when
// that goes out of scope. I rather hope that good compilers will perform
// constant propagation if the argument is a literal constant and so there
// will be no need to store the field "n" that is shown in the class.

class stack_popper
{   int n;
public:
    stack_popper(int nn)
    {   n = nn;
    }
    ~stack_popper()
    {   popv(n);
    }
};

// Sometimes it could be that calls within the scope of a block might
// exit (eg via a throw) in a way that means that the exact state of the
// stack is uncertain. This resets it at block exit. It is liable to involve
// keeping the stackSave value around, and so stack_popper is to be
// preferred where it can be used.

class stack_restorer
{   LispObject *stackSave;
public:
    stack_restorer()
    {   stackSave = stack;
    }
    ~stack_restorer()
    {   stack = stackSave;
    }
};

// I the interpreter need to save the variable current_function at times

class save_current_function
{   LispObject *savestack;
public:
    save_current_function(LispObject newfn)
    {   push(current_function);
        savestack = stack;
        current_function = newfn;
    }
    ~save_current_function()
    {   stack = savestack;
        pop(current_function);
    }
};

// I am going to need to unbind fluids in the C++ code that I
// sometimes traslate Lisp into. Here is a helper class that will
// be useful for that.

class bind_fluid_stack
{   LispObject *savestack;
    int env_loc;
    int name_loc;
    int val_loc;
public:
    bind_fluid_stack(int e, int name, int val)
    {   savestack = stack;
        env_loc = e;
        name_loc = name;
        val_loc = val;
#ifdef TRACE_FLUID
// While I was debugging things being able to enable some printing here
// seemed a good idea!
        debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val, stack);
        debug_printf("name="); prin_to_debug(elt(savestack[e], name));
        debug_printf(" old-val="); prin_to_debug(qvalue(elt(savestack[e], name)));
        debug_printf("\n");
#endif
        savestack[val] = qvalue(elt(savestack[e], name));
    }
    ~bind_fluid_stack()
    {
#ifdef TRACE_FLUID
        debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc, savestack);
        debug_printf("name="); prin_to_debug(elt(savestack[env_loc], name_loc));
        debug_printf(" local-val="); prin_to_debug(qvalue(elt(savestack[env_loc], name_loc)));
        debug_printf(" restored-val="); prin_to_debug(savestack[val_loc]);
        debug_printf("\n");
#endif
        qvalue(elt(savestack[env_loc], name_loc)) = savestack[val_loc];
    }
};


// I will have a number of exception types. I will NOT make them carry
// Lisp data with them even though that might seem reasonable. This is
// because during the processing of a throw some finalization can occur,
// and if some time that managed to cause garbage collection I would
// not be confident that the GC could find and the excveption object to
// treat it as a list base. I will have a number of sub-classes of
// LispException just in case that ends up helping things be tidy.

// Throwing just an integer will be used as a way of stopping everything and
// returning that integer as the return-code from the application.

// LispException is rather abstract...

struct LispException : public std::exception
{   virtual const char *what() const throw()
    {   return "Generic Lisp Exception";
    }
};

// Exceptions that count as "Errors" are or inherit from LispError, and
// unwinding from one of them should lead to a backtrace.

    struct LispError : public LispException
    {   virtual const char *what() const throw()
        {   return "Lisp Error";
        }
    };

        struct LispSignal : public LispError
        {   virtual const char *what() const throw()
            {   return "Lisp Signal";
            }
        };

        struct LispResource : public LispError
        {   virtual const char *what() const throw()
            {   return "Lisp Resouce Limiter";
            }
        };

        struct LispSigint : public LispError
        {   virtual const char *what() const throw()
            {   return "Lisp Sigint";
            }
        };


// Things that are not LispErrors are exceptions used to the system to
// support Lisp features - GO, RETURN, THROW and RESTART.

    struct LispGo : public LispException
    {   virtual const char *what() const throw()
        {   return "Lisp Go";
        }
    };

    struct LispReturnFrom : public LispException
    {   virtual const char *what() const throw()
        {   return "Lisp ReturnFrom";
        }
    };

    struct LispThrow : public LispException
    {   virtual const char *what() const throw()
        {   return "Lisp Throw";
        }
    };

    struct LispRestart : public LispException
    {   virtual const char *what() const throw()
        {   return "Lisp Restart";
        }
    };


// If I build for debugging I will verify that the stack pointer is
// properly unchanged across some scopes. This will help...

class RAIIstack_sanity
{   LispObject *saveStack;
    const char *fname;
    const char *file;
    int line;
    LispObject w;
public:
    RAIIstack_sanity(const char *fn, const char *fi, int li)
    {   saveStack = stack;
        fname = fn;
        file = fi;
        line = li;
        w = nil;
    }
    RAIIstack_sanity(const char *fn, const char *fi, int li, LispObject ww)
    {   saveStack = stack;
        fname = fn;
        file = fi;
        line = li;
        w = ww;
    }
// While I am unwinding the stack because of exception handling the stack
// can remain un-restored. It is only once I have caught the exception
// that it must end up correct. Hence the use of std::uncaught_exception()
// here to avoid complaints when they are not justified.
    ~RAIIstack_sanity()
    {   if (saveStack != stack && !std::uncaught_exception())
        {   err_printf("[Stack Sanity Oddity] %p => %p in %s : %s:%d\n",
                   saveStack, stack, fname, file, line);
            err_printf("Data: ");
            prin_to_error(w);
            err_printf("\n");
            err_printf("exit_count = %d, exit_reason = %d\n",
                       exit_count, exit_reason);
        }
    }
};

static inline const char *tidy_filename(const char *a)
{   const char *b = strrchr(a, '/');
    return (b == NULL ? a : b+1);
}

// If the (Lisp) stack were to get out of step with expectations the
// consequences could be dire. To help me check against that I can use one
// of these two macros. The second takes a LispObject that would then
// appear in any diagnostics about stack confusion. If you are compiling
// production code all that is generated is a null statement. But in debug
// mode an object is created that recorsd the current stack pointer, and
// when it goes out of scope at the end of the block it checks if things
// have been put back as expected.

#ifdef DEBUG
#define STACK_SANITY                                  \
    RAIIstack_sanity stack_sanity_object(__func__,    \
        tidy_filename(__FILE__), __LINE__);
#define STACK_SANITY1(w)                              \
    RAIIstack_sanity stack_sanity_object(__func__,    \
        tidy_filename(__FILE__), __LINE__, w);
#else
#define STACK_SANITY            ;
#define STACK_SANITY1(w)        ;
#endif

// In parts of the interpreter I want to save litvec and codevec and be
// certain that I will restore them at function exit. This macro will help
// me.

class RAIIsave_codevec
{   LispObject *saveStack;
public:
    RAIIsave_codevec()
    {   push2(litvec, codevec);
        saveStack = stack;
    }
    ~RAIIsave_codevec()
    {   stack = saveStack;
        pop2(codevec, litvec);
    }
};

#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;


// First I will comment on protection for push/pop against exceptions that
// might arise, as in
//    push2(a, b);
//    <exception or sigaction triggered here>
//    pop2(b, a);
// where at present I always take care to restore the stack pointer before
// returning. In the newer model I observe that if the condition that causes
// an abrupt is either a throw or a signal (ending in a longjmp) then the
// caller of the current function is not in general going to be relying on the
// status of the stack -- because it too will be terminated. It will not be
// until the stack frame of some function that needs to recover is reached
// that the stack pointer is required. So I will arrange that the general
// code for that saves a copy of the stack pointer to return to.
//
// The places where this complexity is required include:
// (1) errorset
// (2) Places where fluid variables are re-bound
// (3) Any other place where global state is temporarily
//     reset and needs to be restored at the end of an operation.
//     Eg this may include "rdf" for the stream being read and
//     perhaps explode and compress for the same sort of reason.
// (4) Use of system resources that require finalization.
// (5) Places where data structures are temporarily corrupted and then
//     mended later.
// (6) Some places where backtrace-style reports are called for.
//
// Note that the setjmp/longjmp stuff is something I need to think about a
// a lot harder. Including it represents a run-time cost. SIGINT is for
// interrupts (i.e. ^C) and I need to handle that in my terminal handler code.
// And poll for it! Other signals (SIGSEGC, SIGBUS, SIGILL, SIGFPE) all
// represent system failures, so ANY recovery at all would be a bonus. Perhaps
// the most common or plausible circumstance for them to arise is on stack
// overflow, and typically some level of recovery or backtrace there is
// really desirable, but continuation of the computation afterwards may well
// not be possible. I believe that SIGFPE only arises on integer division
// by zero, and my code is supposed to check for and avoid that.
// I probably want to reduce my use of signal as much as I can!
//
// Let me try to comment a bit more on those.
// (1) errorset need to trap all errors. It should convert GO, RETURN-FROM
//     and THROW into errors, but be transparent to RESTART and QUIT.
// (2) fluids are bound in the interpreter code for LET, LET*, PROG,
//     PROGV and in the bytecode engine. There are implicit fluid
//     re-bindings of PACKAGE and maybe other things in some IO functions
//     such as RDF. And also the interpreter code for LAMBDA and function
//     application.
// (3) Things like the current input and output streams need to be
//     preserved across functions that use the mechanisms they involve,
//     fo EXPLODE, COMPRESS, ... need review.
// (4) Most obviously OPEN/use/CLOSE on files needs protection.
// (5) The current implementation of some binding code reverses the
//     lists of things to bind and then restores later on.
// (6) Much of the interpreter and where the bytecode execution system is
//     called needs to generate backtraces at times.
//
//
// My sketch of the protocol follows the definitions of a couple of
// RAII classes that it relies on.:
//

extern LispObject *stack;
extern jmp_buf *global_jb;
NORETURN extern void global_longjmp();

class RAIIsave_stack_and_jb
{   LispObject *saveStack;
    jmp_buf *jbsave;
public:
    RAIIsave_stack_and_jb()
    {   jbsave = global_jb;  // preserve the enclosing jmp_buff.
        saveStack = stack;   // record stack value from entry here.
    }
    ~RAIIsave_stack_and_jb()
    {   global_jb = jbsave;  // restore jmp_buf pointer
        stack = saveStack;   // restore stack
    }
};

class RAIIsave_stack
{   LispObject *saveStack;
public:
    RAIIsave_stack()
    {   saveStack = stack;   // record stack value from entry here.
    }
    ~RAIIsave_stack()
    {   stack = saveStack;   // restore stack
    }
};


//
// try
// {   jmp_buf jb;
//     RAIIsave_stack_and_jb RAII2_Object; // Save SP and setjmp stuff.
//     if (setjmp(jb) != 0) throw EEE;  // signals convert to exceptions!
//     global_jb = &jb;                 // (*) only set new jmp_buf when ready.
//     <ACTIVITY>
// }                                    // At end of block destructor is called,
//                                      // both for standard and exception exits.
// catch (EEE_t)
// {   <ERROR ACTIVITY>
// }
//
// Explanation...
//
// First the case when the setjmp stuff can be ignored this just reduces to
// "try { <ACTIVITY> } catch (EEE_t) { <ERROR_ACTIVITY> }" which is simple
// code to handle exceptions that are raised within the C++ world. The extra
// bulk and complication arises because I wish to be able to respond to
// events noticed by sigaction(). For those I will arrange that global_jb points
// at a jmp_buf structure, because regardless of official legality I will
// use longjmp to exit from event handlers. Look up "async signal safe" to
// find explanations and discussions of why this is all delicate! I believe
// that things are liable to fail if the signal arose while a system call
// was being executed, and I hope that events prompted directly by my own
// code and nor arising during system calls will be reasonably safe. But my
// official stance has to be that following an exception it is good if I
// can recover enough to produce a diagnostic, but even that is not
// guaranteed.
//
// The constructor and destructor of RAII (Resource Allocation Is
// Initialization) class save and restore global_jb across the extent of
// the try block.
// The setjmp call starts by returning normally with the value zero, and only
// when that has happened do I update global_jb to point to the new jmp_buf.
// A longjmp that is triggered before the line marked (*) just uses the
// jmp_buf from a synamically enclosing context.
//
// If during <ACTIVITY> there is an event signalled and longjmp is called code
// returns from setjmp for a second time an exception is thrown. On the way out
// of the try block towards the exception handler global_jb should be unwound.
//
// The effect should be that signalled conditions as well as C++ exceptions all
// gather together and are processed by <ERROR_ACTIVITY>.
//
// There is HOPE that the overhead from all this will be fairly low, and that
// specifically the handling of both "try" and the construction and destruction
// of RAII_Object will have almost no cost at run time (at least when compilers
// are used at reasonable optimization levels). The setjmp call does have a cost
// even when no event ends up signalled. There will be a space cost in extra
// tables needed to support unwinding, and the unwinding process itself may
// sometimes involve complicated searches in them and so may have non-trivial
// cost.
//


// The full mess I seem to want is ugly and bulky. I will try hiding it
// away in a number of macros... so the user writes
//    try
//    {   START_TRY_BLOCK;
//        <activity>
//    }
//    catch (LispException e)
//    { whatever }
// and I will make them write the catch clauses explictly since what will be
// needed there is liable to vary from case to case.

// I provide two variants. One JUST preserves the sstack pointer, the more
// costly one converts longjmp activations into throws of LispSignal or
// LispSigint.

#define START_SETJMP_BLOCK                          \
    jmp_buf jb;                                     \
    RAIIsave_stack_and_jb save_stack_Object;        \
    switch (setjmp(jb))                             \
    {   default:                                    \
        case 1: exit_reason = UNWIND_SIGNAL;        \
                if (miscflags & HEADLINE_FLAG)      \
                    err_printf("\n+++ Error %s: ", errorset_msg); \
                throw LispSignal();                 \
        case 2: exit_reason = UNWIND_SIGINT;        \
                if (miscflags & HEADLINE_FLAG)      \
                    err_printf("\n+++ Error %s: ", errorset_msg); \
                throw LispSigint();                 \
        case 0: break;                              \
    }                                               \
    global_jb = &jb;

#define START_TRY_BLOCK                             \
    RAIIsave_stack save_stack_Object;

// There are places where I need to display part of a backtrace when
// unwinding the stack because of an error.
//
//    on_backtrace(do_something(arg1, arg2, arg3); // commas between args OK
//                 do_something_mode(),            // semicolon separators OK
//                 // Now the error handler
//                 printf("Error in %s\n", "something"));

#define on_backtrace(a, b)                          \
    try                                             \
    {   START_TRY_BLOCK;                            \
        a;                                          \
    }                                               \
    catch (LispError e)                             \
    {   int _reason = exit_reason;                  \
        b;                                          \
        exit_reason = _reason;                      \
        throw;                                      \
    }

// There are also places where I want to continue after error and
// set a default value if some fragmement of computation fails, and
// others where I wish to ignore errors entirely
//
//    if_error(a = construct_a_list(), a = nil);
//    ignore_error(print_a_message());

#define if_error(a, b)                              \
    try                                             \
    {   START_TRY_BLOCK;                            \
        a;                                          \
    }                                               \
    catch (LispError e)                             \
    {   b;                                          \
    }

#define ignore_error(a)                             \
    try                                             \
    {   START_TRY_BLOCK;                            \
        a;                                          \
    }                                               \
    catch (LispError e)                             \
    {                                               \
    }

// ignore_exception() also recovers after any exception (eg SIGSEGV) gets
// raised. Well the state of non-volatile local variables may be undefined
// after recovery via a signal handler and hence via longjmp. This ignores
// all Lisp "errors" and caught signals are treated as just that. But it
// does not catch Lisp "quit", "restart", "return-from", "throw" or
// "resource-limit" exceptions.

#define ignore_exception(a)                         \
    try                                             \
    {   START_SETJMP_BLOCK;                         \
        a;                                          \
    }                                               \
    catch (LispError e)                             \
    {                                               \
    }


#endif // __lispthrow_h

// end of lispthrow.h
