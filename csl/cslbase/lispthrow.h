// lispthrow.h                                      Copyright Codemist 2016

// Some exception processing stuff for CSL

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

// $Id: $

#ifndef __lispthrow_h
#define __lispthrow_h 1




// I will have a number of exception types. I will NOT make them carry
// Lisp data with them even though that might seem reasonable. This is
// because during the processing of a throw some finalization can occur,
// and if some time that managed to cause garbage collection I would
// not be confident that the GC could find and the excveption object to
// treat it as a list base. I will have a number of sub-classes of
// LispException just in case that ends up helping things be tidy.

// Throwing just an integer will be used as a way of stopping everything and
// returning that integer as the return-code from the application.

struct LispException : public std::exception
{   const char *what() const throw()
    {   return "Unknown Lisp Exception";
    }
};

struct LispError : public LispException
{   const char *what() const throw()
    {   return "Lisp Error";
    }
};

struct LispGo : public LispException
{   const char *what() const throw()
    {   return "Lisp Go";
    }
};

struct LispReturnFrom : public LispException
{   const char *what() const throw()
    {   return "Lisp ReturnFrom";
    }
};

struct LispThrow : public LispException
{   const char *what() const throw()
    {   return "Lisp Throw";
    }
};

struct LispRestart : public LispException
{   const char *what() const throw()
    {   return "Lisp Restart";
    }
};

struct LispSignal : public LispException
{   const char *what() const throw()
    {   return "Lisp Signal";
    }
};

struct LispSigint : public LispException
{   const char *what() const throw()
    {   return "Lisp Sigint";
    }
};


// First I will comment on protection for push/pop against exceptions that
// might arise, as in
//    push2(a, b);
//    <exception or signal triggered here>
//    pop2(b, a);
// where at present I always take care to restore the stack pointer before
// returning. In the newer model I observe that if the condition that causes
// an abrupt is either a throw or a signal (ending in a longjmp) then the
// caller of the current function is bot in general going to be relying on the
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
//
// My sketch of the protocol is as follows:
//
//
// extern LispObject *stack;
// extern jmp_buf *global_jb;
//
// try
// {   jmp_buf jb;
//     class RAII
//     {   LispObject *saveStack;       // a field in the class.
//         jmp_buf *jbsave;
//         public:
//             RAII(LispObject *ss)
//             {   jbsave = global_jb;  // preserve the enclosing jmp_buff.
//                 saveStack = ss;      // record stack value from entry here.
//             }
//             ~RAII()
//             {   global_jb = jbsave;  // restore jmp_buf pointer
//                 stack = saveStack;   // restore stack
//             }
//     } RAII_Object(stack);            // pass stack pointer to constructor.
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
// events noticed by signal(). For those I will arrange that global_jb points
// at a jmp_buf structure, because one of the few things one can do in a
// signal handler is a longjmp.
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

extern jmp_buf *global_jb;

// The full mess I seem to want is ugly and bulky. I will try hiding it
// away in a number of macros... so the user writes
//    try
//    {   START_TRY_BLOCK
//        <activity>
//    }
//    catch (LispException e)
//    { whatever }
// and I will make them write the catch clauses explictly since what will be
// needed there is liable to vary from case to case.

#define START_TRY_BLOCK                             \
    jmp_buf jb;                                     \
    class RAII                                      \
    {   LispObject *saveStack;                      \
        jmp_buf *jbsave;                            \
        public:                                     \
            RAII(LispObject *ss)                    \
            {   jbsave = global_jb;                 \
                saveStack = ss;                     \
            }                                       \
            ~RAII()                                 \
            {   global_jb = jbsave;                 \
                stack = saveStack;                  \
            }                                       \
    } RAII_Object(stack);                           \
    switch (setjmp(jb))                             \
    {   default:                                    \
        case 1: throw LispSignal();                 \
        case 2: throw LispSigint();                 \
        case 0: break;                              \
    }                                               \
    global_jb = &jb;


#endif // __lispthrow_h

// end of lispthrow.h
