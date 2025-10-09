// lispthrow.h                                 Copyright Codemist 2020-2025

// Some exception processing stuff for CSL

/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

// If NO_THROW is defined this uses a flag rather than genuine C++ exceptions!

//extern LispObject *stack;
extern uintptr_t stackBase;
extern uintptr_t stackFringe;
extern uintptr_t stackLimit;
extern uintptr_t C_stackBase;
extern uintptr_t C_stackFringe;
extern uintptr_t C_stackLimit;

// I need the Lisp stack pointer to be kept under control even in the context
// of catch and throw.
//
// The places where I may depend on the stack pointer and so where it may
// be prudent to take special care to keep a saved copy include...
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
// Let me try to comment a bit more on those.
// (1) errorset needs to trap all errors. It should convert GO, RETURN-FROM
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

class SaveStack
{   LispObject *saveStack;
public:
    SaveStack()
    {   saveStack = stack;   // record stack value from entry here.
    }
    ~SaveStack()
    {
#if defined DEBUG && 0
        if (stack != saveStack) fprintf(stderr, "@@@ %d\n", (int)(stack - saveStack));
#endif
        stack = saveStack;   // restore stack
    }
};

// There is a "Lisp Stack" which is separate from the C++ stack. It has
// a number of uses:
// (1) The bytecode interpreter is a variety of stack-based computer with
//     two accumulators (A and B). It works by pushing and popping items
//     on the stack and accessing some relative to the stack top. In the
//     case of deep recursion this naturally lead to a substantial amount
//     of stuff ending up on the Lisp stack.
// (2) When the bytecode interpreter sets up a fluid binding it has to
//     save the old value of a variable for later restoration - but what
//     is tougher is that it must arrange that if THROW or and error
//     unwinds then the restoration happens. It achieves that by putting
//     not just the saved value on the Lisp stack but also a marker that
//     unambiguously docments what it is. 
// (3) Some parts of the interpreter and the implementation of some special
//     forms used the Lisp stack either to marshall data where it is not
//     known in advance how much will be present or to keep precise pointers
//     to a significant number of values. 
//
// RealSave ALWAYS transfers values to the stack, so within the code indicated
// by the "..." you can access them via stack[-n], but use of save.val() is
// preferable.

// PushCount is merely a class wrapping int that exists so that
// it can be used to make argument-type overloading work for me in
// the context if RealSave.

class PushCount
{
public:
    int n;
    PushCount(int count)
    {   n = count;
    }
};

class RealSave
{
private:
    LispObject *ssave;
public:
    RealSave(PushCount count)
    {   ssave = stack;
// The coding here may look slightly unusual, but is written on the basis
// that on Windows having stack as a thread_local variable has a side
// effect of getting it treated as volatile, so every visible access to it
// turns into an explicit memory reference and optimisation of the code is
// inhibited to an extent that makes a significant difference to overall
// system performance!
        stack = ssave + count.n;
        for (int i=1; i<=count.n; i++)
            ssave[i] = nil;
    }
    RealSave(LispObject a1)
    {   ssave = stack;
        stack = ssave + 1;
        ssave[1] = a1;
#ifdef DEBUG
// In general after a function call that might return via an "exception"
// I should write "errexit()" so that if I build CSL in the mode where
// exceptions are simulated the simulation works. To help trap cases where
// I have failed to do this I have the concept of exception values" which
// are (mostly) delivered when a function exits "exceptionally". Such values
// ought never to end up being used. If I do see one I will abort!
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, PushCount count)
    {   ssave = stack;
        stack = ssave + count.n + 1;
        ssave[1] = a1;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
        for (int i=2; i<=count.n+1; i++)
            ssave[i] = nil;
    }
    RealSave(LispObject a1, LispObject a2)
    {   ssave = stack;
        stack = ssave + 2;
        ssave[1] = a1;
        ssave[2] = a2;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, LispObject a2, LispObject a3)
    {   ssave = stack;
        stack = ssave + 3;
        ssave[1] = a1;
        ssave[2] = a2;
        ssave[3] = a3;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a3)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4)
    {   ssave = stack;
        stack = ssave + 4;
        ssave[1] = a1;
        ssave[2] = a2;
        ssave[3] = a3;
        ssave[4] = a4;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a3)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a4)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4, LispObject a5)
    {   ssave = stack;
        stack = ssave + 5;
        ssave[1] = a1;
        ssave[2] = a2;
        ssave[3] = a3;
        ssave[4] = a4;
        ssave[5] = a5;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a3)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a4)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a5)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4, LispObject a5, PushCount count)
    {   ssave = stack;
        stack = ssave + count.n + 5;
        ssave[1] = a1;
        ssave[2] = a2;
        ssave[3] = a3;
        ssave[4] = a4;
        ssave[5] = a5;
        for (int i=0; i<count.n; i++)
            ssave[i+6] = nil;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a3)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a4)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a5)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4, LispObject a5, LispObject a6)
    {   ssave = stack;
        stack = ssave + 6;
        ssave[1] = a1;
        ssave[2] = a2;
        ssave[3] = a3;
        ssave[4] = a4;
        ssave[5] = a5;
        ssave[6] = a6;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a3)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a4)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a5)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a6)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4, LispObject a5, LispObject a6,
             LispObject a7)
    {   ssave = stack;
        stack = ssave + 7;
        ssave[1] = a1;
        ssave[2] = a2;
        ssave[3] = a3;
        ssave[4] = a4;
        ssave[5] = a5;
        ssave[6] = a6;
        ssave[7] = a7;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a3)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a4)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a5)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a6)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a7)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    RealSave(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4, LispObject a5, LispObject a6,
             LispObject a7, LispObject a8)
    {   ssave = stack;
        stack = ssave + 8;
        ssave[1] = a1;
        ssave[2] = a2;
        ssave[3] = a3;
        ssave[4] = a4;
        ssave[5] = a5;
        ssave[6] = a6;
        ssave[7] = a7;
        ssave[8] = a8;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a3)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a4)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a5)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a6)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a7)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a8)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    LispObject &val(int n)
    {   return ssave[n];
    }
    void restore(LispObject &a1)
    {   a1 = ssave[1];
    }
    void restore(LispObject &a1, LispObject &a2)
    {   a1 = ssave[1];
        a2 = ssave[2];
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3)
    {   a1 = ssave[1];
        a2 = ssave[2];
        a3 = ssave[3];
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4)
    {   a1 = ssave[1];
        a2 = ssave[2];
        a3 = ssave[3];
        a4 = ssave[4];
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4, LispObject &a5)
    {   a1 = ssave[1];
        a2 = ssave[2];
        a3 = ssave[3];
        a4 = ssave[4];
        a5 = ssave[5];
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4, LispObject &a5, LispObject &a6)
    {   a1 = ssave[1];
        a2 = ssave[2];
        a3 = ssave[3];
        a4 = ssave[4];
        a5 = ssave[5];
        a6 = ssave[6];
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4, LispObject &a5, LispObject &a6,
                 LispObject &a7)
    {   a1 = ssave[1];
        a2 = ssave[2];
        a3 = ssave[3];
        a4 = ssave[4];
        a5 = ssave[5];
        a6 = ssave[6];
        a7 = ssave[7];
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4, LispObject &a5, LispObject &a6,
                 LispObject &a7, LispObject &a8)
    {   a1 = ssave[1];
        a2 = ssave[2];
        a3 = ssave[3];
        a4 = ssave[4];
        a5 = ssave[5];
        a6 = ssave[6];
        a7 = ssave[7];
        a8 = ssave[8];
    }
    ~RealSave()
    {   stack = ssave;
    }
};

// Now I have a scheme that lets me allocate a vector of dynamic size
// on the regular C++ stack. The version I have here will support
// vectors of up to size 78 but no more! The usage is something like
//    result = withVec(size, [&](LispObject* vec){... return res;});
// so now let me review the alternatives to this somewhat odd and limited
// scheme:
// (1)    LispObject vec[n]; This is a variable length array. The
//                           syntax and behaviour is mandated for C99
//                           but not C++, although both g++ and clang++
//                           support it. But it is not standard!
// (2)    LispObject* vec = alloca(n*sizeof(LispObject));
//                           Also widely supported but again not standard!
// (3)    std::vector<LispObject> vec(n);
//                           Standard C++, but (a) for real hot-spot
//                           locations in code it will be heavyweight and
//                           (b) [much more severe for me] my garbage
//                           collector will not know where the memory that
//                           is that vector is, and so will probably end
//                           up corrupting the Lisp heap.
// (4)    A custom class that behaves somewhat like std::vector but
//        that allocates on ths Lisp heap.
//                           Probably even worse than what follows here!
// (5)    This code.         Who has any idea what overheads std::function
//                           may introduce? Limited size of vector. But
//                           this should be portable and meet official
//                           standards!

// I will probably use variable length arrays when they are available so
// that this "fun" is just a fall-back for uncommonly used C++ compilers.

#include <functional>

template <std::size_t N>
inline LispObject withVecT(std::function<LispObject(LispObject*)>& f)
{   LispObject v[N];    // Allocate the "dynamically" sized vector.
    return f(&v[0]);
}

template <std::size_t p, std::size_t q>
inline LispObject withVecS(
    std::size_t n, std::function<LispObject(LispObject*)>& f)
{
// This table controls the sizes of vectors actually allocated. My choices
// at this stage have been that I will always allocate at least 4 units
// and I want less overshoot on smaller vectors. The scheme here can allocate
// a vector of length up to 78. If I find that I need larger cases I can
// just adjust the table here to give a different trade-off between wasted
// space and maximum size. Or I could increase the table size and use
// more code space and an extra test each time through... It is all very
// flexible!
    static constexpr std::size_t vecSizes[] =
    {   4,  6,  8, 10, 12, 14, 16, 19,
       21, 25, 30, 36, 44, 54, 66, 78
    };
// Use binary search to identify the particular instantiation of the
// templated code that I want. Detect the case where I risk going beyond
// the maximum supported size and abort on failure.
    if constexpr (p==q)
    {   if constexpr (p==(sizeof(vecSizes)/sizeof(vecSizes[0]))-1)
        {   if (n > vecSizes[p]) std::abort();
        }
        return withVecT<vecSizes[p]>(f);
    }
    constexpr std::size_t m = (p+q)/2;
    if (n <= vecSizes[m]) return withVecS<p,m>(n, f);
    else return withVecS<m+1,q>(n,f);
}

inline LispObject
    withVec(std::size_t n, std::function<LispObject(LispObject*)> f)
{
// The number 15 on the next line is (one less than) the size of the
// table of vector-sizes to be used.
    return withVecS<0, 15>(n, f);
}

extern volatile bool tick_pending;
extern volatile int unwind_pending;

extern LispObject respond_to_stack_event();

inline void stackcheck()
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag) >= stackLimit)
        respond_to_stack_event();
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
// argument nullptr. No fringes have been messed with. The system should just
// invoke the garbage collector and return. The intent here is to provide
// a way to force garbage collection at specific (if rather hard to compute!)
// moments.
    if (msg == nullptr)
    {   reclaim("gc-forcer");
        return;
    }
#endif // BOOTSTRAP
//
// If an asynchronous event has arisen then event_flag has an interesting
// value. I want to read and reset it atomically, and these two lines
// using compare_exchange_weak() should achieve that.
    uintptr_t f = event_flag;
    while (!event_flag.compare_exchange_weak(f, 0)) {}
// Now one possibility is that this is a perfectly normal ordinary case
// for garbage collection because event_flag had been zero. In that case
// just garbage collect.
    if (f == 0)
    {   reclaim(msg);
        return;
    }
}

// Sometimes it could be that calls within the scope of a block might
// exit (eg via a throw) in a way that means that the exact state of the
// stack is uncertain. This resets it at block exit. It is liable to involve
// keeping the saveStack value around, and so stack_popper is to be
// preferred where it can be used.

class stack_restorer
{   LispObject *saveStack;
public:
    stack_restorer()
    {   saveStack = stack;
    }
    ~stack_restorer()
    {   stack = saveStack;
    }
};

// I the interpreter need to save the variable current_function at times

class save_current_function
{   LispObject *saveStack;
public:
    save_current_function(LispObject newfn)
    {   saveStack = stack;
        stack = saveStack + 1;
        saveStack[1] = current_function;
        current_function = newfn;
    }
    ~save_current_function()
    {   current_function = saveStack[1];
        stack = saveStack;
    }
};

// I am going to need to unbind fluids in the C++ code that I
// sometimes traslate Lisp into. Here is a helper class that will
// be useful for that.

class bind_fluid_stack
{   LispObject *saveStack;
    int env_loc;
    int name_loc;
    int val_loc;
public:
    bind_fluid_stack(int e, int name, int val)
    {   saveStack = stack;
        env_loc = e;
        name_loc = name;
        val_loc = val;
#ifdef TRACE_FLUID
// While I was debugging things being able to enable some printing here
// seemed a good idea!
        debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val,
                     stack);
        debug_printf("name="); prin_to_debug(elt(saveStack[e], name));
        debug_printf(" old-val=");
        prin_to_debug(qvalue(elt(saveStack[e], name)));
        debug_printf("\n");
#endif
        saveStack[val] = qvalue(elt(saveStack[e], name));
    }
    ~bind_fluid_stack()
    {
#ifdef TRACE_FLUID
        debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc,
                     saveStack);
        debug_printf("name=");
        prin_to_debug(elt(saveStack[env_loc], name_loc));
        debug_printf(" local-val=");
        prin_to_debug(qvalue(elt(saveStack[env_loc], name_loc)));
        debug_printf(" restored-val="); prin_to_debug(saveStack[val_loc]);
        debug_printf("\n");
#endif
        qvalue(elt(saveStack[env_loc], name_loc)) = saveStack[val_loc];
    }
};

extern bool backtrace_enabled;

class ForBacktrace
{   LispObject save;
public:
    ForBacktrace(LispObject call)
    {   if (backtrace_enabled)
        {   save = callStack;
            callStack = cons(call, callStack);
        }
        else save = nil;
    }
    ~ForBacktrace()
    {   if (backtrace_enabled) callStack = save;
    }
};

class ForBacktraceTailCall
{
public:
    ForBacktraceTailCall(LispObject call)
    {   callStack = cons(call, callStack);
    }
};

#ifdef DEBUG
// If these are enable I can get distinctly better backtraces through
// bytecoded functions - however they can lead to quite bad storage
// use.
#define RECORD_CALL(x) ForBacktrace btr(x);
#define RECORD_TAILCALL(x) ForBacktraceTailCall btr(x);
#else
#define RECORD_CALL(x)
#define RECORD_TAILCALL(x)
#endif

// I am going to have some macros that provide a level of abstraction
// around "catch" and "throw". The reason for this is that in the special
// case when I use emscripten to compile my C++ code into Webassembly and
// Javascript there are very severe performance penalties for having any
// "catch" statements, including implicit ones used by RAII. So the default
// (and in 2020 about the only sane) use of emscripten disables support
// for exceptions and the C++ keyword "catch" is mostly treated as a no-op.
//
// Well when the code here was in C not C++ it did not have exceptions
// available, and it emulated them by setting an "exceptionFlag". In relevant
// cases my macros expand to something like the old version. The usage is
//
//      TRY
//        some statements
//        if (...) ... THROW(ExceptionName);
//        more statements
//      CATCH (ExceptionName)
//        recovery code
//        RETHROW;
//      ANOTHER_CATCH(AnotherExceptionName)
//        recovery code
//      END_CATCH
//
// Note that there are no "{}" delimiters written. There are some severe
// constraints! First I have to use a limited number of "exception" types,
// and these do not carry data. System exceptions are NOT supported.
// The TRY..END_CATCH segment must be in a function that returns a value
// of type LispObject (!). The code between TRY and CATCH may not use
// control-flow statements such as return, continue or break to transfer
// beyond itself. If you use "return" beteen TRY and CATCH it will transfer
// control to where the CATCH checks for exceptions. The constrainst and
// the behaviour are because the body of the TRY is wrapped up as the
// body of a function (well a lambda-expression) so that within it THROW and
// the exception-testing macros can use "return" to escape from it. So
// if you look at the expanaion of TRY s1; CATCH(T) s2; END_CATCH it is
// along the lines of
//    ([&]()->LispObject { s1; return nil })();
//    if (exceptionFlag & T) { exceptionFlag = LispNormal; s2; }
//    else if (exceptionFlag != LispNormal) return nil;
// and I think that the term "YUK" close to applies!


// I will have a number of exception types. I will NOT make them carry
// Lisp data with them even though that might seem reasonable. This is
// because during the processing of a throw some finalization can occur,
// and if some time that managed to cause garbage collection I would
// not be confident that the GC could find and the exception object to
// treat it as a list base. I will have a number of sub-classes of
// LispException just in case that ends up helping things be tidy.

// I am assuming that from 2025 onwards C++ compilers will support
// inline variables fully.

#ifdef NO_THROW

enum LispExceptionTag
{
// LispNormal is for circumstances when no throw-like situation is in play. 
    LispNormal      = 0x00,

// The next two are varieties of error state.
    LispSimpleError = 0x01,
    LispResource    = 0x02,

// Now thee that are used to implement Lisp control structures within
// the interpreter.
    LispGo          = 0x04,
    LispReturnFrom  = 0x08,
    LispThrow       = 0x10,

// The final cases exit from everything and then sometimes restarts.
    LispRestart     = 0x20,
    LispStop        = 0x40,

// Any sort of the above.
    LispException   = 0x7f
};

// There were two ways I could have implemented software catch and thow.
// One sets a separate flag that can be checked anywhere that an exception
// might be pending, the other expands my domain of values with a special
// exception value and checks for that. I am going to do both here at least
// for the moment. The separate flag disrupts the transition less (I think)
// but returning a value SPID_ERROR as the dummy return value when an
// exception is raised os maybe a bit like having NaN for floating point:
// it can tends to persist and help me spot any cases where I failed to
// check for it.


#define SPID_LispException    (SPID_ERROR+(static_cast<int>(LispException)<<20))
#define SPID_SimpleError      (SPID_ERROR+(static_cast<int>(LispSimpleError)<<20))
#define SPID_Resource         (SPID_ERROR+(static_cast<int>(LispResource)<<20))
#define SPID_Go               (SPID_ERROR+(static_cast<int>(LispGo)<<20))
#define SPID_ReturnFrom       (SPID_ERROR+(static_cast<int>(LispReturnFrom)<<20))
#define SPID_Throw            (SPID_ERROR+(static_cast<int>(LispThrow)<<20))
#define SPID_Restart          (SPID_ERROR+(static_cast<int>(LispRestart)<<20))
#define SPID_Stop             (SPID_ERROR+(static_cast<int>(LispStop)<<20))


inline LispExceptionTag exceptionFlag = LispNormal;

inline bool exceptionPending()
{   return exceptionFlag != LispNormal;
}
#define errexit() \
    if (exceptionPending()) UNLIKELY return SPID_ERROR+(exceptionFlag<<20)
#define errexitint() \
    if (exceptionPending()) UNLIKELY return SPID_ERROR+(exceptionFlag<<20)
#define errexitvoid() \
    if (exceptionPending()) UNLIKELY return

#define TRY ([&]()->LispObject \
    { SaveStack save_stack_Object ## __LINE__;

// The next two variables are for debugging!
inline const char *exceptionFile = "none";
inline int exceptionLine = -1;

#ifdef DEBUG
#define THROW(flavour) do {     \
   JITerrflag = 1;              \
   exceptionFile = __FILE__;    \
   exceptionLine = __LINE__;    \
   exceptionFlag = flavour;     \
   return SPID_Throw; } while(false)
#define THROWVOID(flavour) do { \
   JITerrflag = 1;              \
   exceptionFile = __FILE__;    \
   exceptionLine = __LINE__;    \
   exceptionFlag = flavour;     \
   return; } while(false)
#else
#define THROW(flavour)          \
    do {                        \
       JITerrflag = 1;          \
       exceptionFlag = flavour; \
       return SPID_Throw; } while(false)
#define THROWVOID(flavour)      \
    do {                        \
       JITerrflag = 1;          \
       exceptionFlag = flavour; \
       return; } while(false)
#endif

#define CATCH(flavour)                                                  \
   return nil;})(); if ((exceptionFlag & flavour) != 0) UNLIKELY        \
   {   [[maybe_unused]] LispExceptionTag saveException = exceptionFlag; \
       jitexpectin = 0;                                                 \
       exceptionFlag = LispNormal;

#define ANOTHER_CATCH(flavour)                                          \
   } else if ((exceptionFlag & flavour) != 0) UNLIKELY                  \
   {   [[maybe_unused]] LispExceptionTag saveException = exceptionFlag; \
       JITerrflag = 0;                                                  \
       exceptionFlag = LispNormal;

#define CATCH_ANY()                                                     \
   return nil;})(); if (exceptionFlag != 0) UNLIKELY                    \
   {   [[maybe_unused]] LispExceptionTag saveException = exceptionFlag; \
       JITerrflag = 0;                                                  \
       exceptionFlag = LispNormal;

#define RETHROW do                                                      \
    { exceptionFlag = saveException;                                    \
      JITerrflag = 1;                                                   \
      return SPID_ERROR+(saveException<<20); } while(false)

#define END_CATCH } \
    else if (exceptionPending()) \
        UNLIKELY return SPID_ERROR+(exceptionFlag<<20);

#else // NO_THROW

struct LispStop : public std::exception
{   virtual const char *what() const noexcept
    {   return "Used to exit the system";
    }
};

struct LispException : public std::exception
{   virtual const char *what() const noexcept
    {   return "Lisp Generic Exception";
    }
};

struct LispError : public LispException
{   virtual const char *what() const noexcept
    {   return "Lisp Error or Resource Limit Event";
    }
};

// When one unwinds because of a LispSimpleError firstly there is a
// possibility that a backtrace will be displayed, and secondly that
// errorset() might catch the error.

struct LispSimpleError : public LispError
{   virtual const char *what() const noexcept
    {   return "Lisp Simple Error";
    }
};

// Unwinding on a LispResource will not cause a backtrace to be displayed
// and it can only be caught by resource-limit(), not by errorset().

struct LispResource : public LispError
{   virtual const char *what() const noexcept
    {   return "Lisp Resouce Limit Event";
    }
};

// Things that are not LispErrors are exceptions used to the system to
// support Lisp features - GO, RETURN, THROW and RESTART. So they do some
// unwinding but do not lead to backtraces and are caught by code associated
// with their particular purpose.

struct LispGo : public LispException
{   virtual const char *what() const noexcept
    {   return "Lisp Go";
    }
};

struct LispReturnFrom : public LispException
{   virtual const char *what() const noexcept
    {   return "Lisp ReturnFrom";
    }
};

struct LispThrow : public LispException
{   virtual const char *what() const noexcept
    {   return "Lisp Throw";
    }
};

struct LispRestart : public LispException
{   virtual const char *what() const noexcept
    {   return "Lisp Restart";
    }
};

// The following dynamic tests for exception conditions are not used in the
// version of the code that uses "catch" and "throw".

inline bool exceptionPending()
{   return false;
}
#define errexit()
#define errexitint()
#define errexitvoid()

#define TRY try { ([&]()->LispObject \
    { SaveStack save_stack_Object ## __LINE__;

#define THROW(flavour) { JITerrflag = 1; throw flavour(); }
#define THROWVOID(flavour) { JITerrflag = 1; throw flavour(); }

#define CATCH(flavour) return nil;})(); } catch (flavour &e) { JITerrflag=0;

#define ANOTHER_CATCH(flavour) } catch (flavour &e) { JITerrflag = 0;

#define CATCH_ANY() return nil;})(); } catch (...) { JITerrflag = 0;

#define RETHROW { JITerrflag = 1; throw; }
#define RETHROWVOID { JITerrflag = 1; throw; }

#define END_CATCH }

#endif // NO_THROW


// There are "jolly issues" about JIT-generated code and exception handling.
// In particular the technology for allowing for stack unwinding through
// JIT-generated code and associated treatment of exceptions is both not
// thoroughly supported by the code-generating toolkit I am using at
// present (asmjit) and it is likely to be quite delicate and hard to get
// correct across all combinations of machine architectures and compilers.
// So I sidestep at least almost all of it.
// When JIT code wants to generate a function call that I will express
// as FFF(a,b,c) I will make it use JITshim(FFF,a,b,c) instead. I will
// present one variant of JITshim here and then explain it - and then
// write out all the other versions that cope with different numbers
// of parameters:

// JITerrflag is used as a flag but I make it a 64-bit integer so that I
// do not have to wonder just how much memory your C++ compiler allocates
// to store a bool. My exception abstraction arranges that its value is
// nonzero whenever an exception is active. If "real" exceptions are in
// play I will sometimes put a value on JITerr_ptr to record
// the precise exception that is current so that it can be rethrown.

#ifndef NO_THROW
inline std::exception_ptr JITerr_ptr;
#endif // NO

// I will only implement variants of "JITshim" that I think the JIT
// compiler will really want.
typedef LispObject (*func0)();
typedef LispObject (*func1)(LispObject);
typedef LispObject (*func2)(LispObject,LispObject);
typedef LispObject (*func3)(LispObject,LispObject,LispObject);
typedef LispObject (*func4)(LispObject,LispObject,LispObject,LispObject);
typedef LispObject (*func5)(LispObject,LispObject,LispObject,
                            LispObject,LispObject);
typedef LispObject (*func6)(LispObject,LispObject,LispObject,
                            LispObject,LispObject,LispObject);
typedef LispObject (*errfunc0)(const char*);
typedef LispObject (*errfunc1)(const char*,LispObject);
typedef LispObject (*errfunc2)(const char*,LispObject,LispObject);
typedef LispObject (*errfunc2s)(const char*,const char*,LispObject);

inline LispObject JITshim1(func1 FF,
                           LispObject env)
{   LispObject r;
    TRY
// I will call FF(env) and use C++ facilities to catch any exceptions
// that arise.
        r = (*FF)(env);
    CATCH_ANY()
// If there is an exception I will return in a normal state as if
// there had been nothing special happening, save that JITerrflag
// will be set. It is the responsibility of whoever uses JITshim to
// check for this immediately and deal with it. That may involve
// doing and local tidying up and then reinstating the exception by
// doing a tail-call to jitpropagate(). It could involve handling and
// cancelling the error. At present I do not save quite enough information
// to make it easy to tell what sort of exception was involved, so
// surrport for that can be added at a later stage!
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
// If the call FF(env) did not raise an exception make sure that the flag
// is clear before returning.
    JITerrflag = 0;
    return r;
}

inline LispObject jitthrow()
{
// Put stack pointer back where it needs to be, unbinding any fluids
// encountered on the way.
    LispObject* oldsp = reinterpret_cast<LispObject*>(JITarg1);
    while (stack != oldsp)
    {   if (*stack == SPID_FBIND)
        {   do_freerstr();
        }
        else stack--;
    }
    JITarg1 = nil;
#ifndef NO_THROW
    std::rethrow_exception(JITerr_ptr);
#endif // NO_THROW
    return nil;
}

// Then the full version of the call to FFF will be
//  r = JITshim(FFF, env);
//  if (JITerrflag!=0) [TAILCALL] return jitthrow();
//
// The annotation [TAILCALL} is to explain that the call to jitthrow
// must be expressed by code that restores the stack and any callee-save
// registers that the JIT code may have changed and then takes a jump
// to jitthrow. The effect must be as if jitthrow had been called
// directly by whoever first invoked the JIT code. The tidying up must not
// do anything that could interact with JITerrflag or JITerr_ptr.

// I note that JITshim() could be used as a wrapper if there were any
// other places where stack unwindinding or exception handling was going
// to be a problem - perhaps notably or potentially across calls to some
// code written in other languages - maybe including via use of the
// foreign function interfaces. It is most liable to be applicable if
// such code can make callbacks into the body of this code.

// I now need variants of JITshim passing various numbers of arguments.

inline LispObject JITshim0(func0 FF)
{   LispObject r;
    TRY
        r = (*FF)();
    CATCH_ANY()
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
    JITerrflag = 0;
    return r;
}

inline LispObject JITshim2(func2 FF,
                           LispObject env, LispObject a1)
{   LispObject r;
    TRY
        r = (*FF)(env, a1);
    CATCH_ANY()
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
    JITerrflag = 0;
    return r;
}

inline LispObject JITshim1B(func1b FF,
                            LispObject a1)
{   bool r;
    TRY
        r = (*FF)(a1);
    CATCH_ANY()
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
    JITerrflag = 0;
    return r;        // widens result to intptr_t
}


inline LispObject JITshim2B(func2b FF,
                            LispObject a1, LispObject a2)
{   LispObject r;
    TRY
        r = (*FF)(a1, a2);
    CATCH_ANY()
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
    JITerrflag = 0;
    return r;        // widens result to intptr_t
}

inline LispObject JITshim3(func3 FF,
                           LispObject env, LispObject a1, LispObject a2)
{   LispObject r;
    TRY
        r = (*FF)(env, a1, a2);
    CATCH_ANY()
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
    JITerrflag = 0;
    return r;
}

inline LispObject JITshim4(func4 FF,
                           LispObject env, LispObject a1,
                           LispObject a2, LispObject a3)
{   LispObject r;
    TRY
        r = (*FF)(env, a1, a2, a3);
    CATCH_ANY()
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
    JITerrflag = 0;
    return r;
}

inline LispObject JITshim5(func5 FF,
                           LispObject env, LispObject a1,
                           LispObject a2, LispObject a3, LispObject a4up)
{   LispObject r;
    TRY
        r = (*FF)(env, a1, a2, a3, a4up);
    CATCH_ANY()
        JITerrflag = 1;
#ifndef NO_THROW
        JITerr_ptr = std::current_exception();
#endif // NO_THROW
        return nil;
    END_CATCH;
    JITerrflag = 0;
    return r;
}

inline auto JITshim0L = JITshim1;
inline auto JITshim1L = JITshim2;
inline auto JITshim2L = JITshim3;
inline auto JITshim3L = JITshim4;
inline auto JITshim4L = JITshim5;

// If I build for debugging I will verify that the stack pointer is
// properly unchanged across some scopes. This will help...

inline const char *tidy_filename(const char *a)
{   const char *b = std::strrchr(a, '/');
    return (b == nullptr ? a : b+1);
}

// If the (Lisp) stack were to get out of step with expectations the
// consequences could be dire. To help me check against that I can use one
// of these two macros. The second takes a LispObject that would then
// appear in any diagnostics about stack confusion. If you are compiling
// production code all that is generated is a null statement. But in debug
// mode an object is created that records the current stack pointer, and
// when it goes out of scope at the end of the block it checks if things
// have been put back as expected.

#ifdef DEBUG

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
// that it must end up correct. Hence get-out of exceptionFxlag is set.
    ~RAIIstack_sanity()
    {
#ifdef NO_THROW
        if (saveStack != stack && exceptionFlag == LispNormal) UNLIKELY
#else // NO_THROW
#ifdef __cpp_lib_uncaught_exceptions
        if (saveStack != stack && std::uncaught_exceptions() == 0) UNLIKELY
#else // __cpp_lib_uncaught_exceptions
        if (saveStack != stack && !std::uncaught_exception()) UNLIKELY
#endif // __cpp_lib_uncaught_exceptions
#endif // NO_THROW
        {   err_printf("[Stack Consistency fails] %p => %p in %s : %s:%d\n",
                       saveStack, stack, fname, file, line);
            err_printf("Data: ");
            prin_to_error(w);
            err_printf("\n");
            err_printf("exit_count = %d, exit_reason = %d\n",
                       exit_count, exit_reason);
            my_abort("stack consistency");
        }
// This was used at a stage of heavy debugging - I leave it in as comment
// in case I ever need to reinstate it.
#if defined DEBUG && !defined NO_THROW && 0
#ifdef __cpp_lib_uncaught_exceptions
        if (std::uncaught_exceptions() == 0) UNLIKELY
#else // __cpp_lib_uncaught_exceptions
        if (!std::uncaught_exception()) UNLIKELY
#endif // __cpp_lib_uncaught_exceptions
        {   printf("unwinding the stack (lispthrow.h line 1144)\n");
// I can not use trace_printf or err_prinf here because this can arise
// before the Lisp IO streams have been set up.
        }
#endif
    }
};

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

// The full mess I seem to want is ugly and bulky. I will try hiding it
// away in a number of macros... so the user writes
//    TRY
//        <activity>
//    CATCH(LispException)
//        <whatever>
//    END_CATCH

// There are places where I need to display part of a backtrace when
// unwinding the stack because of an error.
//
//    on_backtrace(do_something(arg1, arg2, arg3); // commas between args OK
//                 do_something_more(),            // semicolon separators OK
//                 // Now the error handler
//                 printf("Error in %s\n", "something"));

// In the code for both args of on_backtrace I must go
//    if (exceptionPending()) break;
// where relevant.

#define on_backtrace(a, b)                  \
    TRY                                     \
        a;                                  \
    CATCH(LispResource)                     \
        RETHROW;                            \
    ANOTHER_CATCH(LispSimpleError)          \
        int _reason = exit_reason;          \
        b;                                  \
        exit_reason = _reason;              \
        RETHROW;                            \
    END_CATCH
    
#define on_backtrace_void(a, b)             \
    TRY                                     \
        a;                                  \
    CATCH(LispResource)                     \
        RETHROW;                            \
    ANOTHER_CATCH(LispSimpleError)          \
        int _reason = exit_reason;          \
        b;                                  \
        exit_reason = _reason;              \
        RETHROWVOID;                        \
    END_CATCH
    

// There are also places where I want to continue after error and
// set a default value if some fragmement of computation fails, and
// others where I wish to ignore errors entirely
//
//    if_error(a = construct_a_list(), a = nil);
//    ignore_error(print_a_message());

#define if_error(a, b)                        \
    TRY                                       \
        a;                                    \
    CATCH(LispResource)                       \
    {   RETHROW;                              \
    }                                         \
    ANOTHER_CATCH(LispSimpleError)            \
        b;                                    \
    END_CATCH

#define ignore_error(a)                       \
    TRY                                       \
        a;                                    \
    CATCH(LispResource)                       \
    {   RETHROW;                              \
    }                                         \
    ANOTHER_CATCH(LispSimpleError)            \
    {}                                        \
    END_CATCH

#endif // __lispthrow_h

// end of lispthrow.h
