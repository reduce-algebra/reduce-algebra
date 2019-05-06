// lispthrow.h                                      Copyright Codemist 2019

// Some exception processing stuff for CSL

/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

// In C++ I ought to be able to have "extern thread_local" values where the
// variable is defined in one compilation unit but refereed to from others.
// However some versions of gcc from (at least) 2016 to 2018 give linker
// errors "undefined reference to `TLS init function ..." in this case. That
// is a wide enought range of gcc configurations that I need to do something!
// So here I have what can only reasonably be described as a HACK that adds
// an extra level of indirection. By removing the "#define" lines here this
// hack can be removed rather easily. Something like this may be required for
// all other extern thread_local variables! Yuk.
// I rather hope that with the "const" pointer that the C++ compiler will
// turn this into almost as good code as it would have been before.
// Furthermore within the compilation unit that happens to define the
// thread_local variable I undo the "#define" and refer to the variable
// directly thereby avoiding the extra indirection.

// BUT: "Oh dear" these changes led to an order of magnitude slowdown for
// REDUCE, and so I am removing them. I will need to be rather careful before
// I put more thread_local usage back. But one reason for hope here is that
// when I have a conservative garbage collector I will not need the separate
// Lisp stack that is at issue here!

// Later (April 2019). Access to thread_local values has low overhead on
// Linux and on Windows while compiling using msvc. On the Macintosh using
// clang it is modest. However at the time of writing there are severe costs
// on either Cygwin or compiling for native Windows using the mingw32
// compilers. This seems to be because in the favourable cases the C++
// system uses an x86 segment register, while with Cygwin and mingw a
// nasty system call is made each time. On the Raspberry pi and on the
// Macintosh there is an intermediate effect.
// Exactly what happens may be senitive to the exact release of compiler
// used etc, and so the report here should not be viewed as behaviour
// guaranteed for the future! But merely declaring a few variables to be
// thread_local can sometimes have dramatic consequences!


//extern thread_local LispObject *stack;
extern LispObject *stack;
//extern thread_local jmp_buf *global_jb;
extern  jmp_buf *global_jb;

//extern LispObject **get_stack_addr();
//extern jmp_buf **get_global_jb_addr();
// In any single compilation unit you will only scan this header file
// once, and so the static variables set up here get defined just once
// and the initialization of them should happen during thread initialization.
//static thread_local LispObject **const stack_addr = get_stack_addr();
//static thread_local jmp_buf **const global_jb_addr = get_global_jb_addr();
//#define stack (*stack_addr)
//#define global_jb (*global_jb_addr)

// End of thread_local hack.

inline void push(LispObject a)
{   *++stack = a;
}

// Since I am now using C++ I could just overload the names push, pop and
// stackcheck to cope with the number of operands rather than having so many
// distinct names. Well I will do that, but I will leave the old versions
// in place for at least a few weeks to help with a transition.

inline void push2(LispObject a, LispObject b)
{   *++stack = a;
    *++stack = b;
}

inline void push3(LispObject a, LispObject b, LispObject c)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
}

inline void push4(LispObject a, LispObject b, LispObject c,
                         LispObject d)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
}

inline void push5(LispObject a, LispObject b, LispObject c,
                         LispObject d, LispObject e)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
}

inline void push6(LispObject a, LispObject b, LispObject c,
                         LispObject d, LispObject e, LispObject f)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
    *++stack = f;
}

// Well here I provide the overloads...

inline void push(LispObject a, LispObject b)
{   *++stack = a;
    *++stack = b;
}

inline void push(LispObject a, LispObject b, LispObject c)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
}

inline void push(LispObject a, LispObject b, LispObject c, LispObject d)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e, LispObject f)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
    *++stack = f;
}

inline void pop(LispObject& a)
{   a = *stack--;
}

inline void pop(volatile LispObject& a)
{   a = *stack--;
}

inline void pop2(LispObject& a, LispObject& b)
{   a = *stack--;
    b = *stack--;
}

inline void pop3(LispObject& a, LispObject& b, LispObject& c)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
}

inline void pop4(LispObject& a, LispObject& b, LispObject& c,
                        LispObject& d)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
}

inline void pop5(LispObject& a, LispObject& b, LispObject& c,
                        LispObject& d, LispObject& e)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
    e = *stack--;
}

inline void pop6(LispObject& a, LispObject& b, LispObject& c,
                        LispObject& d, LispObject& e, LispObject& f)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
    e = *stack--;
    f = *stack--;
}

inline void pop(LispObject& a, LispObject& b)
{   a = *stack--;
    b = *stack--;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c, LispObject& d)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d, LispObject& e)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
    e = *stack--;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d, LispObject& e, LispObject& f)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
    e = *stack--;
    f = *stack--;
}

inline void popv(int n)
{   stack -= n;
}

extern volatile bool tick_pending;
extern volatile int unwind_pending;

extern void respond_to_stack_event();

inline void stackcheck0()
{   if_check_stack();                                         
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit) respond_to_stack_event();
}

inline void stackcheck1(LispObject& a1)                                   
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1);
        respond_to_stack_event();
        pop(a1);
    }
}

inline void stackcheck2(LispObject& a1, LispObject& a2)                               
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1, a2);
        respond_to_stack_event();
        pop(a2, a1);
    }
}

inline void stackcheck3(LispObject& a1, LispObject& a2, LispObject& a3)                           
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1, a2, a3);
        respond_to_stack_event();
        pop(a3, a2, a1);
    }
}

inline void stackcheck4(LispObject& a1, LispObject& a2, LispObject& a3, LispObject& a4)                       
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1, a2, a3, a4);
        respond_to_stack_event();
        pop(a4, a3, a2, a1);
    }
}

// Now overloads...

inline void stackcheck()
{   if_check_stack();                                         
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit) respond_to_stack_event();
}

inline void stackcheck(LispObject& a1)        
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1);
        respond_to_stack_event();
        pop(a1);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2)                               
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1, a2);
        respond_to_stack_event();
        pop(a2, a1);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2, LispObject& a3)                           
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1, a2, a3);
        respond_to_stack_event();
        pop(a3, a2, a1);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2,
                       LispObject& a3, LispObject& a4)                       
{   if_check_stack();                                        
    if (((uintptr_t)stack | event_flag.load()) >=
        (uintptr_t)stacklimit)
    {   push(a1, a2, a3, a4);
        respond_to_stack_event();
        pop(a4, a3, a2, a1);
    }
}

inline void respond_to_fringe_event(LispObject &r, const char *msg)
{
// One possibility is that this is a genuine case of the current part of the
// heap having become full, and so I need to invoke garbage collection to
// try to tidy up.
#ifdef BOOTSTRAP
// The bootstrap version provides a special scheme that is present to
// help me debug storage management. It is set up by calling the Lisp-level
// function gc-forcer. That sets a variable force_cons and each time
// the system checks for space that is decremented. When it becomes zero
// the respond_to_fringe_event() function is called with its second
// argument NULL. No fringes have been messed with. The system should just
// invoke the garbage collector and return. The intent here is to provide
// a way to force garbage collection at specific (if rather hard to compute!)
// moments.
    if (msg == NULL)
    {
#ifdef CONSERVATIVE
        reclaim("gc-forcer");
#else
// With a precise collector r is a variable that must be preserved.
        r = reclaim(r, "gc-forcer", GC_USER_HARD, 0);
#endif
        return;
    }
#endif // BOOTSTRAP
//
// If an asynchronous event has arisen then event_flag has an interesting
// value. I want to read and reset it atomically, and these two lines
// using compare_exchange_weak() should achieve that.
    uintptr_t f = event_flag.load();
    while (!event_flag.compare_exchange_weak(f, 0)) {}
// Now one possibility is that this is a perfectly normal ordinary case
// for garbage collection because event_flag had been zero. In that case
// just garbage collect.
    if (f == 0)
    {
#ifdef CONSERVATIVE
        reclaim(msg);
#else
        r = reclaim(r, "gc-forcer", GC_USER_HARD, 0);
#endif
        return;
    }
}

// If I know just how many items will need removing from the stack I
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

#ifndef LISPEXCEPTION_DEFINED

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

#endif // LISPEXCEPTION_DEFINED

        struct LispResource : public LispError
        {   virtual const char *what() const throw()
            {   return "Lisp Resouce Limiter";
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

// From C++17 the function uncaught_exception() is deprecated and a new
// variant uncaught_exceptions() is introduced, and from C++20 the first
// of these is expected to be removed, thereby preventing the old version
// of this code from building. The circumstances that lead to the change here
// involve exceptions raised within C++ destructors and the like - much
// more agressive use of C++ features that I tends to be into, so I will
// use uncaught_exceptions() in a rather naive manner.
// I used to have code here that could verify (Lisp) stack consistency,
// however C__17 deprecates std::uncaught_exception() and demands a change
// to use a new function std::uncaught_exceptions() not present in earlier
// versions of the standard, while it is expected that C++20 will withdraw
// the original function. I used it and rather than modify my code with ugly
// checks for whether I have C++17 or not anbd rather that put up with the
// torrent of warnings that GCC generates in response to deprecated features

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
// here to avoid complaints when they are not justified. Well C++17 recognizes
// a special challenge with nested use of exceptions, hence the move to use
// of std::uncaught_exceptions() but since the code here is just used for
// debugging and anyway because I think it is reasonable I will only report
// a problem if my software stack ends up in an odd state when I am not doing
// any unwinding at all. If I moved to having a load of Lisp code runnable
// during unwinding (well perhaps unwind-protect can lead to that) I might
// want to review this.
    ~RAIIstack_sanity()
    {
#ifdef __cpp_lib_uncaught_exceptions
        if (saveStack != stack && !std::uncaught_exceptions() != 0)
#else
        if (saveStack != stack && !std::uncaught_exception())
#endif
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

inline const char *tidy_filename(const char *a)
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
// This mess may not be required when I have a conservative garbage collector
// if I then make codevec and litvec local rather than global variables, and
// the result might be both clearer code and less overhead.

class RAIIsave_codevec
{   LispObject *saveStack;
public:
    RAIIsave_codevec()
    {   push(litvec, codevec);
        saveStack = stack;
    }
    ~RAIIsave_codevec()
    {   stack = saveStack;
        pop(codevec, litvec);
    }
};

#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;


// First I will comment on protection for push/pop against exceptions that
// might arise, as in
//    push(a, b);
//    <exception or sigaction triggered here>
//    pop(b, a);
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
// a lot harder. Including it represents a run-time cost. I really ought not
// to get any exceptions raised! SIGSEGC, SIGBUS, SIGILL, SIGFPE all
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

[[noreturn]] extern void global_longjmp();

#ifndef SAVE_STACK_AND_JB_DEFINED

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

#endif

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
//    catch (LispException &e)
//    { whatever }
// and I will make them write the catch clauses explictly since what will be
// needed there is liable to vary from case to case.

// I provide two variants. One JUST preserves the sstack pointer, the more
// costly one converts longjmp activations into throws of LispSignal.

#define START_SETJMP_BLOCK                          \
    jmp_buf jb;                                     \
    RAIIsave_stack_and_jb save_stack_Object;        \
    switch (setjmp(jb))                             \
    {   default:                                    \
        case 1: exit_reason = UNWIND_SIGNAL;        \
                if (miscflags & HEADLINE_FLAG)      \
                    err_printf("\n+++ Error %s: ", errorset_msg); \
                throw LispSignal();                 \
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
    catch (LispError &e)                            \
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
    catch (LispError &e)                            \
    {   b;                                          \
    }

#define ignore_error(a)                             \
    try                                             \
    {   START_TRY_BLOCK;                            \
        a;                                          \
    }                                               \
    catch (LispError &e)                            \
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
    catch (LispError &e)                            \
    {                                               \
    }


#endif // __lispthrow_h

// end of lispthrow.h
