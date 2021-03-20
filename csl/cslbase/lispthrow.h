// lispthrow.h                                 Copyright Codemist 2020-2021

// Some exception processing stuff for CSL

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

// $Id$

#ifndef __lispthrow_h
#define __lispthrow_h 1

// If NO_THROW is defined this uses a flag rather than genuine C++ exceptions!

#define TL_stack 49
DECLARE_THREAD_LOCAL(LispObject *, stack);

// There is a "Lisp Stack" which is separate from the C++ stack. It has
// a number of uses:
// (1) Prior to the conservative GC all references to heap data must be
//     somewhere "safe" whenever a GC could happen. This is achieved by
//     going { Save save(x); <dangerous operations>; save.restore(x); }
//     in many places.
//     This keeps the identification of heap pointers "precise".
// (2) The bytecode interpreter is a variety of stack-based computer with
//     two accumulators (A and B). It works by pushing and popping items
//     on the stack and accessing some relative to the stack top. In the
//     case of deep recursion this naturally lead to a substantial amount
//     of stuff ending up on the Lisp stack.
// (3) Some parts of the interpreter and the implementation of some special
//     forms used the Lisp stack either to marshall data where it is not
//     known in advance how much will be present or to keep precise pointers
//     to a significant number of values.
// When a conservative collector is in use case (1) above becomes an out of
// date constraint (that adds a level of inefficiency) and come cases of (3)
// could be reworked to have tidier code when there is no need for precise
// pointers. By and large (2) will remain. The code should now use RealSave
// in those cases where push and pop must use the Lisp stack and Save
// when the transfer is only needed for precision. So in the conservative
// case Save can represent a no-op while RealSave does something.
// If at some stage the precice GC is totally removed then all calls to
// just Save can be discarded.
//
// RealSave ALWAYS transfers values to the stack, so within the code indicated
// by the "..." you can access them via stack[-n], but use of save.val() is
// preferable.
// For the version of CSL before there is a conservative garbage collector
// Save tranfers values to the stack, but it would be bad to try to access
// them there. When there is a conservative garbage collector both the
// constructors for Save and its restore() method will become no-ops because
// values can be kept safely in simple C++ variables. As a debugging help
// over the transition the conservative scheme does save values but then
// arranges that restore() verifies that the stacked value and the one in the
// simple variable have not got out of step.

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

// With a conservative GC I will want real_push and real_pop to exist and
// move things to and from a dedicated Lisp stack (eg as part of the way
// I handle some special forms or functions with huge numbers of arguments)
// but case where it used to be push/pop can replace those with no-operation.

#ifdef CONSERVATIVE

#if 1 // TEMP

// The version here actually saves things to the stack although that ought
// not to be necessary.

class Save
{
private:
    LispObject *ssave;
public:
//  Save(PushCount count)
//  {   ssave = stack;
//      stack = ssave + count.n;
//      for (int i=1; i<=count.n; i++)
//          ssave[i] = nil;
//  }
    Save(LispObject a1)
    {   ssave = stack;
        stack = ssave + 1;
        ssave[1] = a1;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    Save(LispObject a1, LispObject a2)
    {   ssave = stack;
        stack = ssave + 2;
        ssave[1] = a1;
        ssave[2] = a2;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    Save(LispObject a1, LispObject a2, LispObject a3)
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
    Save(LispObject a1, LispObject a2, LispObject a3,
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
    Save(LispObject a1, LispObject a2, LispObject a3,
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
    Save(LispObject a1, LispObject a2, LispObject a3,
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
    ~Save()
    {   stack = ssave;
    }
};

#else // 1, TEMP

// Here is the pure noop version which shoudl eventually be used while I am
// in the process of textually removing mention of Save all together!

class Save
{
public:
    Save(LispObject a1)
    {
    }
    Save(LispObject a1, LispObject a2)
    {
    }
    Save(LispObject a1, LispObject a2, LispObject a3)
    {
    }
    Save(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4)
    {
    }
    Save(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4, LispObject a5)
    {
    }
    Save(LispObject a1, LispObject a2, LispObject a3,
             LispObject a4, LispObject a5, LispObject a6)
    {
    }
    void restore(LispObject &a1)
    {
    }
    void restore(LispObject &a1, LispObject &a2)
    {
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3)
    {
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4)
    {
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4, LispObject &a5)
    {
    }
    void restore(LispObject &a1, LispObject &a2, LispObject &a3,
                 LispObject &a4, LispObject &a5, LispObject &a6)
    {
    }
    ~Save()
    {
    }
};
#endif // 1, TEMP

#else // CONSERVATIVE

class Save
{
private:
    LispObject *ssave;
public:
//  Save(PushCount count)
//  {   ssave = stack;
//      stack = ssave + count.n;
//      for (int i=1; i<=count.n; i++)
//          ssave[i] = nil;
//  }
    Save(LispObject a1)
    {   ssave = stack;
        stack = ssave + 1;
        ssave[1] = a1;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    Save(LispObject a1, LispObject a2)
    {   ssave = stack;
        stack = ssave + 2;
        ssave[1] = a1;
        ssave[2] = a2;
#ifdef DEBUG
        if (is_exception(a1)) UNLIKELY my_abort("exception value not trapped");
        if (is_exception(a2)) UNLIKELY my_abort("exception value not trapped");
#endif // DEBUG
    }
    Save(LispObject a1, LispObject a2, LispObject a3)
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
    Save(LispObject a1, LispObject a2, LispObject a3,
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
    Save(LispObject a1, LispObject a2, LispObject a3,
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
    Save(LispObject a1, LispObject a2, LispObject a3,
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
    ~Save()
    {   stack = ssave;
    }
};

#endif // CONSERVATIVE

extern volatile bool tick_pending;
extern volatile int unwind_pending;

extern LispObject respond_to_stack_event();

inline void stackcheck()
{   if_check_stack();
// The next line uses a C style cast because at least in an experimental
// version of the code "stack" is an instance of a class not an item
// with basic type, and the generality provided by C style casts copes
// while use of (eg) reinterpret_cast does not.
    if (((uintptr_t)stack | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit)) respond_to_stack_event();
}

inline void stackcheck(LispObject& a1)
{   if_check_stack();
    if (((uintptr_t)stack | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   Save saver(a1);
        respond_to_stack_event();
        saver.restore(a1);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2)
{   if_check_stack();
    if (((uintptr_t)stack | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   Save saver(a1, a2);
        respond_to_stack_event();
        saver.restore(a1, a2);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2, LispObject& a3)
{   if_check_stack();
    if (((uintptr_t)stack | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   Save saver(a1, a2, a3);
        respond_to_stack_event();
        saver.restore(a1, a2, a3);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2,
                       LispObject& a3, LispObject& a4)
{   if_check_stack();
    if (((uintptr_t)stack | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   Save saver(a1, a2, a3, a4);
        respond_to_stack_event();
        saver.restore(a1, a2, a3, a4);
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
// argument nullptr. No fringes have been messed with. The system should just
// invoke the garbage collector and return. The intent here is to provide
// a way to force garbage collection at specific (if rather hard to compute!)
// moments.
    if (msg == nullptr)
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
        setvalue(elt(saveStack[env_loc], name_loc), saveStack[val_loc]);
// atomic????
    }
};



// I am going ti have some macros that provide a level of abstraction
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
//      END_CATCH;
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
// if you look at the expanaion of TRY s1; CATCH(T) s2; END_CATCH; it is
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

#ifdef NO_THROW

enum LispExceptionTag
{
// LispNormal is for circumstances when no throw-like situation is in play. 
    LispNormal      = 0x00,

// The next three are all varieties of error states.
    LispError       = 0x03,
    LispResource    = 0x01,

// Now thee that are used to implement Lisp control structures within
// the interpreter.
    LispGo          = 0x04,
    LispReturnFrom  = 0x08,
    LispThrow       = 0x10,

// A final case exits from everything and then sometimes restarts.
    LispRestart     = 0x20,

// Any sort of the above.
    LispException   = 0x3f
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
#define SPID_Error            (SPID_ERROR+(static_cast<int>(LispError)<<20))
#define SPID_Resource         (SPID_ERROR+(static_cast<int>(LispResource)<<20))
#define SPID_Go               (SPID_ERROR+(static_cast<int>(LispGo)<<20))
#define SPID_ReturnFrom       (SPID_ERROR+(static_cast<int>(LispReturnFrom)<<20))
#define SPID_Throw            (SPID_ERROR+(static_cast<int>(LispThrow)<<20))
#define SPID_Restart          (SPID_ERROR+(static_cast<int>(LispRestart)<<20))


inline LispExceptionTag exceptionFlag = LispNormal;

inline bool errorState()
{   return (exceptionFlag & LispError) != 0;
}
inline bool exceptionPending()
{   return exceptionFlag != LispNormal;
}

#define errexit()  if (exceptionPending()) UNLIKELY return SPID_Error
#define errexitint()  if (exceptionPending()) UNLIKELY return static_cast<int>(SPID_Error)
//#define errexitvoid()  if (exceptionPending()) UNLIKELY return

#define TRY ([&]()->LispObject { SaveStack save_stack_Object ## __LINE__;

// The next two variables are for debugging!
inline const char *exceptionFile = "none";
inline int exceptionLine = -1;

#ifdef DEBUG
#define THROW(flavour) do {     \
   exceptionFile = __FILE__;    \
   exceptionLine = __LINE__;    \
   exceptionFlag = flavour;     \
   return SPID_Throw; } while(false)
#else
#define THROW(flavour)          \
    do { exceptionFlag = flavour; return SPID_Throw; } while(false)
#endif

#define CATCH(flavour) \
   return nil;})(); if ((exceptionFlag & flavour) != 0) UNLIKELY \
   {   [[maybe_unused]] LispExceptionTag saveException = exceptionFlag; exceptionFlag = LispNormal;

#define ANOTHER_CATCH(flavour) \
   } else if ((exceptionFlag & flavour) != 0) UNLIKELY \
   {   [[maybe_unused]] LispExceptionTag saveException = exceptionFlag; exceptionFlag = LispNormal;

#define RETHROW do { exceptionFlag = saveException; \
                     return SPID_Error; } while(false)

#define END_CATCH } else if (exceptionPending()) UNLIKELY return SPID_Error;

#else // NO_THROW

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

// The following dynamic tests for exception conditions are not used in the
// version of the code that uses "catch" and "throw".

inline bool exceptionPending()
{   return false;
}
#define errexit()
#define errexitint()
#define errexitvoid()

#define TRY try { ([&]()->LispObject { SaveStack save_stack_Object ## __LINE__;

#define THROW(flavour) throw flavour()

#define CATCH(flavour) return nil;})(); } catch (flavour &e) {

#define ANOTHER_CATCH(flavour) } catch (flavour &e) {

#define RETHROW throw
#define RETHROWVOID throw

#define END_CATCH }

#endif // NO_THROW


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
// mode an object is created that recordsthe current stack pointer, and
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
    RAIIstack_sanity(const char *fn, const char *fi, int li,
                     LispObject ww)
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
    {   saveStack = stack;
        stack = saveStack + 2;
        saveStack[1] = litvec;
        saveStack[2] = codevec;
    }
    ~RAIIsave_codevec()
    {   litvec = saveStack[1];
        codevec = saveStack[2];
        stack = saveStack;
    }
};

#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;


// First I will comment on protection for push/pop against exceptions that
// might arise, as in
//    push(a, b);
//    <exception or sigaction triggered here>
//    pop(b, a);
// I try take care to restore the stack pointer before returning from any
// function.
// Well for a time I had code that was slack about stack restoration
// especially in the face of "throw" operations. But using the Save class
// and RAII I hope I am repairing things.
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
    CATCH(LispError)                        \
        int _reason = exit_reason;          \
        b;                                  \
        exit_reason = _reason;              \
        RETHROW;                            \
    END_CATCH
    
#define on_backtrace_void(a, b)             \
    TRY                                     \
        a;                                  \
    CATCH(LispError)                        \
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

#define if_error(a, b)                       \
    TRY                                      \
        a;                                   \
    CATCH(LispError)                         \
        b;                                   \
    END_CATCH

#define ignore_error(a)                       \
    TRY                                       \
        a;                                    \
    CATCH(LispError)                          \
    {}                                        \
    END_CATCH

#endif // __lispthrow_h

// end of lispthrow.h
