// lispthrow.h                                      Copyright Codemist 2020

// Some exception processing stuff for CSL

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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

//extern thread_local LispObject *stack;
extern LispObject *stack;
//extern thread_local jmp_buf *global_jb;
extern  std::jmp_buf *global_jb;

//extern LispObject **get_stack_addr();
//extern jmp_buf **get_global_jb_addr();
// In any single compilation unit you will only scan this header file
// once, and so the static variables set up here get defined just once
// and the initialization of them should happen during thread initialization.
//static thread_local LispObject **const stack_addr = get_stack_addr();
//static thread_local jmp_buf **const global_jb_addr = get_global_jb_addr();
//#define stack (*stack_addr)
//#define global_jb (*global_jb_addr)

// There is a "Lisp Stack" which is separate from the C++ stack. It has
// a number of uses:
// (1) Prior to the conservative GC all references to heap data must be
//     somewhere "safe" whenever a GC could happen. This is achieved by
//     going { push(x); <dangerous operations>; pop(x); } in many places.
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
// pointers. By and large (2) will remain. The code should now use real_push()
// in those cases where push and pop must use the Lisp stack and push()
// when the transfer is only needed for precision. So in the conservative
// case push() and pop() can become no-ops while real_push and real_pop()
// continue to behave as always.
// If at some stage the precice GC is totally removed then all calls to
// just push() and pop() can be discarded. Before that the two variants on
// stack access can be instrumented so that the cost impact of the change to
// a conservative GC can be assessed.

// Because in the precise GC model both push() and real_push() do the same
// thing (etc) I view the risk of bugs being introduced into the main-stream
// version as rather low here. But for the conservative code checking that
// every previous push that needs to be upgraded to real_push will need some
// care. However it adds a constraint that uses of push/pop MUST be in the
// style    push(v); ... pop(v);   with the SAME variable used in each
// location and that variable not having its value changed in the "..."
// section. I.e. the use of push and pop is ONLY to ensure that v is garbage
// collection safe and they should not be used to move data around.

#ifdef CONSERVATIVE
inline size_t push_count = 0;
inline size_t real_push_count = 0;
#endif

inline void real_push(LispObject a)
{   *++stack = a;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_push(LispObject a, LispObject b)
{   *++stack = a;
    *++stack = b;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_push(LispObject a, LispObject b, LispObject c)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_push(LispObject a, LispObject b, LispObject c,
                 LispObject d)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
    if (is_exception(e)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e, LispObject f)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
    *++stack = f;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
    if (is_exception(e)) my_abort();
    if (is_exception(f)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

class RealPush
{   int n;
    LispObject *v1, *v2, *v3, *v4, *v5, *v6;
// I rather hope that when I create one of these the compiler will
// remember rather than store the count from (n) and all the addresses of
// the variables that I save the values of!
public:
    RealPush(int count)
    {   n = -count;
        for (int i=0; i<count; i++)
            *++stack = nil;
    }
    RealPush(LispObject &a1)
    {   n = 1;
        v1 = &a1;
        *++stack = a1;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        real_push_count++;
#endif
    }
    RealPush(LispObject &a1, LispObject &a2)
    {   n = 2;
        v1 = &a1;
        v2 = &a2;
        *++stack = a1;
        *++stack = a2;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        real_push_count++;
#endif
    }
    RealPush(LispObject &a1, LispObject &a2, LispObject &a3)
    {   n = 3;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        real_push_count++;
#endif
    }
    RealPush(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4)
    {   n = 4;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        real_push_count++;
#endif
    }
    RealPush(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5)
    {   n = 5;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        v5 = &a5;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
        *++stack = a5;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
        if (is_exception(a5)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        real_push_count++;
#endif
    }
    RealPush(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5, LispObject &a6)
    {   n = 6;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        v5 = &a5;
        v6 = &a6;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
        *++stack = a5;
        *++stack = a6;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
        if (is_exception(a5)) my_abort();
        if (is_exception(a6)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        real_push_count++;
#endif
    }
    ~RealPush()
    {   switch (n)
        {   case 6:
                *v6 = *stack--;
            case 5:
                *v5 = *stack--;
            case 4:
                *v4 = *stack--;
            case 3:
                *v3 = *stack--;
            case 2:
                *v2 = *stack--;
            case 1:
                *v1 = *stack--;
#ifdef CONSERVATIVE
                real_push_count++;
#endif
                break;
            default:
                stack += n; // n will be negative
                break;
        }
    }
};

inline void real_pop(LispObject& a)
{   a = *stack--;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_pop(volatile LispObject& a)
{   a = *stack--;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_pop(LispObject& a, LispObject& b)
{   a = *stack--;
    b = *stack--;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_pop(LispObject& a, LispObject& b, LispObject& c)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d, LispObject& e)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
    e = *stack--;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d, LispObject& e, LispObject& f)
{   a = *stack--;
    b = *stack--;
    c = *stack--;
    d = *stack--;
    e = *stack--;
    f = *stack--;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

inline void real_popv(int n)
{   stack -= n;
#ifdef CONSERVATIVE
    real_push_count++;
#endif
}

// With a conservative GC I will want real_push and real_pop to exist and
// move things to and from a dedicated Lisp stack (eg as part of the way
// I handle some special forms or functions with huge numbers of arguments)
// but case where it used to be push/pop can replace those with no-operation.

#ifdef CONSERVATIVE

#if 1 // TEMP
inline void push(LispObject a)
{   *++stack = a;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
#endif // DEBUG
    push_count++;
}

inline void push(LispObject a, LispObject b)
{   *++stack = a;
    *++stack = b;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
#endif // DEBUG
    push_count++;
}

inline void push(LispObject a, LispObject b, LispObject c)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
#endif // DEBUG
    push_count++;
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
#endif // DEBUG
    push_count++;
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
    if (is_exception(e)) my_abort();
#endif // DEBUG
    push_count++;
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e, LispObject f)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
    *++stack = f;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
    if (is_exception(e)) my_abort();
    if (is_exception(f)) my_abort();
#endif // DEBUG
    push_count++;
}

inline void pop(LispObject& a)
{   my_assert(a == *stack);
    a = *stack--;
    push_count++;
}

inline void pop(volatile LispObject& a)
{   my_assert(a == *stack);
    a = *stack--;
    push_count++;
}

inline void pop(LispObject& a, LispObject& b)
{   my_assert(a == *stack);
    a = *stack--;
    my_assert(b == *stack);
    b = *stack--;
    push_count++;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c)
{   my_assert(a == *stack);
    a = *stack--;
    my_assert(b == *stack);
    b = *stack--;
    my_assert(c == *stack);
    c = *stack--;
    push_count++;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d)
{   my_assert(a == *stack);
    a = *stack--;
    my_assert(b == *stack);
    b = *stack--;
    my_assert(c == *stack);
    c = *stack--;
    my_assert(d == *stack);
    d = *stack--;
    push_count++;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d, LispObject& e)
{   my_assert(a == *stack);
    a = *stack--;
    my_assert(b == *stack);
    b = *stack--;
    my_assert(c == *stack);
    c = *stack--;
    my_assert(d == *stack);
    d = *stack--;
    my_assert(e == *stack);
    e = *stack--;
    push_count++;
}

inline void pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d, LispObject& e, LispObject& f)
{   my_assert(a == *stack);
    a = *stack--;
    my_assert(b == *stack);
    b = *stack--;
    my_assert(c == *stack);
    c = *stack--;
    my_assert(d == *stack);
    d = *stack--;
    my_assert(e == *stack);
    e = *stack--;
    my_assert(f == *stack);
    f = *stack--;
    push_count++;
}

inline void popv(int n)
{   stack -= n;
    push_count++;
}

class Push
{   int n;
    LispObject *v1, *v2, *v3, *v4, *v5, *v6;
// I rather hope that when I create one of these the compiler will
// remember rather than store the count from (n) and all the addresses of
// the variables that I save the values of!
public:
    Push(LispObject &a1)
    {   n = 1;
        v1 = &a1;
        *++stack = a1;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
#endif // DEBUG
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2)
    {   n = 2;
        v1 = &a1;
        v2 = &a2;
        *++stack = a1;
        *++stack = a2;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
#endif // DEBUG
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3)
    {   n = 3;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
#endif // DEBUG
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4)
    {   n = 4;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
#endif // DEBUG
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5)
    {   n = 5;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        v5 = &a5;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
        *++stack = a5;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
        if (is_exception(a5)) my_abort();
#endif // DEBUG
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5, LispObject &a6)
    {   n = 6;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        v5 = &a5;
        v6 = &a6;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
        *++stack = a5;
        *++stack = a6;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
        if (is_exception(a5)) my_abort();
        if (is_exception(a6)) my_abort();
#endif // DEBUG
        push_count++;
    }
    ~Push()
    {   switch (n)
        {   case 6:
                *v6 = *stack--;
            case 5:
                *v5 = *stack--;
            case 4:
                *v4 = *stack--;
            case 3:
                *v3 = *stack--;
            case 2:
                *v2 = *stack--;
            case 1:
                *v1 = *stack--;
                push_count++;
        }
    }
};

#else // 1, TEMP

inline void push(UNUSED_NAME LispObject a)
{
    push_count++;
}

inline void push(UNUSED_NAME LispObject a, UNUSED_NAME LispObject b)
{
    push_count++;
}

inline void push(UNUSED_NAME LispObject a, UNUSED_NAME LispObject b, UNUSED_NAME LispObject c)
{
    push_count++;
}

inline void push(UNUSED_NAME LispObject a, UNUSED_NAME LispObject b, UNUSED_NAME LispObject c,
                 UNUSED_NAME LispObject d)
{
    push_count++;
}

inline void push(UNUSED_NAME LispObject a, UNUSED_NAME LispObject b, UNUSED_NAME LispObject c,
                 UNUSED_NAME LispObject d, UNUSED_NAME LispObject e)
{
    push_count++;
}

inline void push(UNUSED_NAME LispObject a, UNUSED_NAME LispObject b, UNUSED_NAME LispObject c,
                 UNUSED_NAME LispObject d, UNUSED_NAME LispObject e, UNUSED_NAME LispObject f)
{
    push_count++;
}

inline void pop(UNUSED_NAME LispObject& a)
{
    push_count++;
}

inline void pop( UNUSED_NAME volatile LispObject& a)
{
    push_count++;
}

inline void pop(UNUSED_NAME LispObject& a, UNUSED_NAME LispObject& b)
{
    push_count++;
}

inline void pop(UNUSED_NAME LispObject& a, UNUSED_NAME LispObject& b, UNUSED_NAME LispObject& c)
{
    push_count++;
}

inline void pop(UNUSED_NAME LispObject& a, UNUSED_NAME LispObject& b, UNUSED_NAME LispObject& c,
                UNUSED_NAME LispObject& d)
{
    push_count++;
}

inline void pop(UNUSED_NAME LispObject& a, UNUSED_NAME LispObject& b, UNUSED_NAME LispObject& c,
                UNUSED_NAME LispObject& d, UNUSED_NAME LispObject& e)
{
    push_count++;
}

inline void pop(UNUSED_NAME LispObject& a, UNUSED_NAME LispObject& b, UNUSED_NAME LispObject& c,
                UNUSED_NAME LispObject& d, UNUSED_NAME LispObject& e, UNUSED_NAME LispObject& f)
{
    push_count++;
}

inline void popv(UNUSED_NAME int n)
{
    push_count++;
}

class Push
{
public:
    Push(LispObject &a1)
    {
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2)
    {
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3)
    {
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4)
    {
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5)
    {
        push_count++;
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5, LispObject &a6)
    {
        push_count++;
    }
    ~Push()
    {
        push_count++;
    }
};
#endif // 1, TEMP

#else // CONSERVATIVE

// In the non-conservative world oushing and popping must always happen.
// I just have copies of the relevant code here rather than making one
// varient call the other.

inline void push(LispObject a)
{   *++stack = a;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
#endif // DEBUG
}

inline void push(LispObject a, LispObject b)
{   *++stack = a;
    *++stack = b;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
#endif // DEBUG
}

inline void push(LispObject a, LispObject b, LispObject c)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
#endif // DEBUG
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
#endif // DEBUG
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
    if (is_exception(e)) my_abort();
#endif // DEBUG
}

inline void push(LispObject a, LispObject b, LispObject c,
                 LispObject d, LispObject e, LispObject f)
{   *++stack = a;
    *++stack = b;
    *++stack = c;
    *++stack = d;
    *++stack = e;
    *++stack = f;
#ifdef DEBUG
    if (is_exception(a)) my_abort();
    if (is_exception(b)) my_abort();
    if (is_exception(c)) my_abort();
    if (is_exception(d)) my_abort();
    if (is_exception(e)) my_abort();
    if (is_exception(f)) my_abort();
#endif // DEBUG
}

inline void pop(LispObject& a)
{   a = *stack--;
}

inline void pop(volatile LispObject& a)
{   a = *stack--;
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

inline void pop(LispObject& a, LispObject& b, LispObject& c,
                LispObject& d)
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

class Push
{   int n;
    LispObject *v1, *v2, *v3, *v4, *v5, *v6;
// I rather hope that when I create one of these the compiler will
// remember rather than store the count from (n) and all the addresses of
// the variables that I save the values of!
public:
    Push(LispObject &a1)
    {   n = 1;
        v1 = &a1;
        *++stack = a1;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        push_count++;
#endif
    }
    Push(LispObject &a1, LispObject &a2)
    {   n = 2;
        v1 = &a1;
        v2 = &a2;
        *++stack = a1;
        *++stack = a2;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        push_count++;
#endif
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3)
    {   n = 3;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        push_count++;
#endif
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4)
    {   n = 4;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        push_count++;
#endif
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5)
    {   n = 5;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        v5 = &a5;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
        *++stack = a5;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
        if (is_exception(a5)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        push_count++;
#endif
    }
    Push(LispObject &a1, LispObject &a2, LispObject &a3,
             LispObject &a4, LispObject &a5, LispObject &a6)
    {   n = 6;
        v1 = &a1;
        v2 = &a2;
        v3 = &a3;
        v4 = &a4;
        v5 = &a5;
        v6 = &a6;
        *++stack = a1;
        *++stack = a2;
        *++stack = a3;
        *++stack = a4;
        *++stack = a5;
        *++stack = a6;
#ifdef DEBUG
        if (is_exception(a1)) my_abort();
        if (is_exception(a2)) my_abort();
        if (is_exception(a3)) my_abort();
        if (is_exception(a4)) my_abort();
        if (is_exception(a5)) my_abort();
        if (is_exception(a6)) my_abort();
#endif // DEBUG
#ifdef CONSERVATIVE
        push_count++;
#endif
    }
    ~Push()
    {   switch (n)
        {   case 6:
                *v6 = *stack--;
            case 5:
                *v5 = *stack--;
            case 4:
                *v4 = *stack--;
            case 3:
                *v3 = *stack--;
            case 2:
                *v2 = *stack--;
            case 1:
                *v1 = *stack--;
#ifdef CONSERVATIVE
                push_count++;
#endif
        }
    }
};
#endif // CONSERVATIVE

extern volatile bool tick_pending;
extern volatile int unwind_pending;

extern LispObject respond_to_stack_event();

inline void stackcheck0()
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit)) respond_to_stack_event();
}

inline void stackcheck1(LispObject& a1)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   push(a1);
        respond_to_stack_event();
        pop(a1);
    }
}

inline void stackcheck2(LispObject& a1, LispObject& a2)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   push(a1, a2);
        respond_to_stack_event();
        pop(a2, a1);
    }
}

inline void stackcheck3(LispObject& a1, LispObject& a2,
                        LispObject& a3)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   push(a1, a2, a3);
        respond_to_stack_event();
        pop(a3, a2, a1);
    }
}

inline void stackcheck4(LispObject& a1, LispObject& a2,
                        LispObject& a3, LispObject& a4)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   push(a1, a2, a3, a4);
        respond_to_stack_event();
        pop(a4, a3, a2, a1);
    }
}

// Now overloads...

inline void stackcheck()
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit)) respond_to_stack_event();
}

inline void stackcheck(LispObject& a1)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   push(a1);
        respond_to_stack_event();
        pop(a1);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   push(a1, a2);
        respond_to_stack_event();
        pop(a2, a1);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2, LispObject& a3)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
    {   push(a1, a2, a3);
        respond_to_stack_event();
        pop(a3, a2, a1);
    }
}

inline void stackcheck(LispObject& a1, LispObject& a2,
                       LispObject& a3, LispObject& a4)
{   if_check_stack();
    if ((reinterpret_cast<uintptr_t>(stack) | event_flag.load()) >=
        reinterpret_cast<uintptr_t>(stackLimit))
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
    {   real_push(current_function);
        savestack = stack;
        current_function = newfn;
    }
    ~save_current_function()
    {   stack = savestack;
        real_pop(current_function);
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
        debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val,
                     stack);
        debug_printf("name="); prin_to_debug(elt(savestack[e], name));
        debug_printf(" old-val=");
        prin_to_debug(qvalue(elt(savestack[e], name)));
        debug_printf("\n");
#endif
        savestack[val] = qvalue(elt(savestack[e], name));
    }
    ~bind_fluid_stack()
    {
#ifdef TRACE_FLUID
        debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc,
                     savestack);
        debug_printf("name=");
        prin_to_debug(elt(savestack[env_loc], name_loc));
        debug_printf(" local-val=");
        prin_to_debug(qvalue(elt(savestack[env_loc], name_loc)));
        debug_printf(" restored-val="); prin_to_debug(savestack[val_loc]);
        debug_printf("\n");
#endif
        setvalue(elt(savestack[env_loc], name_loc), savestack[val_loc]);
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
    LispSignal      = 0x01,
    LispResource    = 0x02,

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
#define SPID_Signal           (SPID_ERROR+(static_cast<int>(LispSignal)<<20))
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

#define errexit()  if (exceptionPending()) return SPID_Error
#define errexitint()  if (exceptionPending()) return static_cast<int>(SPID_Error)
//#define errexitvoid()  if (exceptionPending()) return

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
   return nil;})(); if ((exceptionFlag & flavour) != 0) \
   {   [[maybe_unused]] LispExceptionTag saveException = exceptionFlag; exceptionFlag = LispNormal;

#define ANOTHER_CATCH(flavour) \
   } else if ((exceptionFlag & flavour) != 0) \
   {   [[maybe_unused]] LispExceptionTag saveException = exceptionFlag; exceptionFlag = LispNormal;

#define RETHROW do { exceptionFlag = saveException; \
                     return SPID_Error; } while(false)

#define END_CATCH } else if (exceptionPending()) return SPID_Error;

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
        if (saveStack != stack && exceptionFlag == LispNormal)
#else // NO_THROW
#ifdef __cpp_lib_uncaught_exceptions
        if (saveStack != stack && std::uncaught_exceptions() == 0)
#else // __cpp_lib_uncaught_exceptions
        if (saveStack != stack && !std::uncaught_exception())
#endif // __cpp_lib_uncaught_exceptions
#endif // NO_THROW
        {   err_printf("[Stack Consistency fails] %p => %p in %s : %s:%d\n",
                       saveStack, stack, fname, file, line);
            err_printf("Data: ");
            prin_to_error(w);
            err_printf("\n");
            err_printf("exit_count = %d, exit_reason = %d\n",
                       exit_count, exit_reason);
            my_abort();
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
    {   real_push(litvec, codevec);
        saveStack = stack;
    }
    ~RAIIsave_codevec()
    {   stack = saveStack;
        real_pop(codevec, litvec);
    }
};

#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;


// First I will comment on protection for push/pop against exceptions that
// might arise, as in
//    push(a, b);
//    <exception or sigaction triggered here>
//    pop(b, a);
// I try take care to restore the stack pointer before returning from any
// function, but it is certain that exits via longjmp will in general mess
// this up. They should only arise in the case of system-level failures and
// so I am not too upset, but I will restore the stack pointer when setjmp()
// returns via longjmp.
// Well for a time I had code that was slack about stack restoration
// especially in the face of "throw" operations. Bu using the Push class
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

[[noreturn]] extern void global_longjmp();

class RAIIsave_stack_and_jb
{   LispObject *saveStack;
    std::jmp_buf *jbsave;
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
    {
#if defined DEBUG && 0
        if (stack != saveStack) fprintf(stderr, "@@@ %d\n", (int)(stack - saveStack));
#endif
        stack = saveStack;   // restore stack
    }
};

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


// I will sketch this usinn native "try" and "throw".
//
// try
// {   jmp_buf jb;
//     RAIIsave_stack_and_jb RAII2_Object; // Save SP and setjmp stuff.
//     if (setjmp(jb) != 0) throw LispSignal();
// Signals convert to exceptions!
// Only set new jmp_buf when ready.
//     global_jb = &jb;                    // (*)
//     <ACTIVITY>
// }             // At end of block destructor is called, both for standard
//               // and exception exits, so SP and global_jb are restored.
//  
//
// Explanation...
//
// First the case when the setjmp stuff can be ignored this just like
// "try { <ACTIVITY> } catch (EEE_t) { <ERROR_ACTIVITY> }" which is simple
// code to handle exceptions that are raised within the C++ world. The extra
// bulk and complication arises because I wish to be able to respond to
// events noticed by sigaction(). I will arrange that global_jb points
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
// jmp_buf from a dynamically enclosing context.
//
// If during <ACTIVITY> there is an event signalled and longjmp is called
// code returns from setjmp for a second time an exception is thrown. On
// the way out of the try block towards the exception handler global_jb
// should be unwound.
//
// The effect should be that signalled conditions as well as C++ exceptions
// all gather together and are processed by subsequent "catch" clauses.
//
// There is HOPE that the overhead from all this will be fairly low, and that
// specifically the handling of both "try" and the construction and
// destruction of RAII_Object will have almost no cost at run time (at least
// when compilers are used at reasonable optimization levels). The setjmp
// call does have a cost even when no event ends up signalled. There will
// be a space cost in extra tables needed to support unwinding, and the
// unwinding process itself may sometimes involve complicated searches in
// them and so may have non-trivial cost.
//

// Even though I describe things in these comments using "try" and "catch"
// I may use the faked exception scheme!

// The full mess I seem to want is ugly and bulky. I will try hiding it
// away in a number of macros... so the user writes
//    TRY
//        <activity>
//    CATCH(LispException)
//        <whatever>
//    END_CATCH

// If I put START_SETJMP_BLOCK at the start of TRY activity it puts in
// recovery after low-level signals.

#define START_SETJMP_BLOCK                                \
    std::jmp_buf jb;                                      \
    RAIIsave_stack_and_jb save_stack_Object;              \
    if (setjmp(jb) != 0)                                  \
    {   exit_reason = UNWIND_SIGNAL;                      \
        if (miscflags & HEADLINE_FLAG)                    \
            err_printf("\n+++ Error %s: ", errorset_msg); \
        THROW(LispSignal);                                \
    }                                                     \
    global_jb = &jb;


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

// ignore_exception() also recovers after any exception (eg SIGSEGV) gets
// raised. Well the state of non-volatile local variables may be undefined
// after recovery via a signal handler and hence via longjmp. This ignores
// all Lisp "errors" and caught signals are treated as just that. But it
// does not catch Lisp "quit", "restart", "return-from", "throw" or
// "resource-limit" exceptions.

#define ignore_exception(a)                   \
    TRY                                       \
        START_SETJMP_BLOCK;                   \
        a;                                    \
    CATCH(LispException)                      \
    {}                                        \
    }

#endif // __lispthrow_h

// end of lispthrow.h
