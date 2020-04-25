// thread_local.h                                 Copyright A C Norman 2019

#ifndef header_thread_local_h
#define header_thread_local_h 1

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


// There are time when I want to write
//    inline thread_local T name = value;
// where the use of the "inline" qualifier is so that I can put this in
// a header file (including the case of a header-only library). The
// "thread_local" is just there for what it normally means.
//
// I have two problems with this. The first is that inline variables are
// only available from C++17 onwards and I still wish to support compilers
// that are not that up to date. The second is that fine-grain use of items
// declared thread_local leads to severe overheads under Cygwin and Mingw32.
// However on those platforms there is a Microsoft-specific scheme for
// thread-local support that has respectable performance, but which is
// limited to storing values as "void ".
//
// The code here is to abstract over my responses to all this. I used to have
// a more elaborate scheme where I had fallen into the C++ trap of using too
// many of its facilities all at once - templates, overloading rather basic
// operators etc etc. That version avoided use of "#define" and means that
// in the end the thread-local values I introduced could be referenced (almost)
// as if they were simmple variable. However when I came to debug code that
// used it each reference to such a variable made single-stepping my code
// really bad, and on at least one occasion it seemed to crash gdb. So this is
// a simpler scheme that puts less strain on the compiler's optimizer and
// is what I am trying now.  To use it one replaces the definition of any
// thread-local with
//     declare_thread_local(name, T);
// or  declare_thread_local_ref(name, T);
// and both of those are (more or less) substitutes for
//     inline thread_local T name;
// Note that in this scheme there is no support for initializing the variable
// at its point of definition. Then in the first case where "name" would have
// been used the rest of the code has to write name::get() or name::set(value),
// and in the second case only name::get() is supported.
// The first version van be used when the type T can be converted to and from
// a "void *", and that covers (obviously) any sort of pointer type but
// also intptr_t and uintptr_t. The second case is intended for use when the
// type T is an array or class type, and so usage will be of the form
//    name::get()[index]   or name::get().field   or name::get().member(..)
//
// The macros here may introduce a class called "name_Ref", and "name" will
// end of the name of a class (with a static member get()) rather than a
// normal symbol. Tha implementation does not always make it naturally easy
// to access the value from a debugger, and so if the symbol DEBUG is defined
// at compile-time and if C++17 inline variables are supported I will arrange
// that "name::val" holds the value in the first case and a reference to it
// in the second. If you do not have inline variables supported then
// "name::val" will be a static function that has defined within itself a
// value called Val.


// What follows supports 3 cases:
// (a) Cygwin/mingsw32 using the Microsoft thread-local API and assuming
//     that the C++ compiler supports C++17 inline variables.
// (b) Other platforms but making us of C++17 inline variables.
// (c) A fallback for use with older C++ compilers and libraries.
//


#if defined __cpp_inline_variables && \
    (defined __CYGWIN__ || defined __MINGW32__)

// With Cygwin and mingw32 (as of 2019) the support of thread-local variables
// uses a mechanism "emutls". For code that makes extensive use of such
// variables in many separate little functions this can add severe overhead.
// Microsoft provides a scheme of rather different style to support
// thread-local. Direct use of it just allows the storage of "void *" values,
// and there is a limit to how many can be stored -- although for my purposes
// the limit is plenty high enough. Here I have code fragments that activate
// the Microsoft scheme. And I go beyond that and provide inline definitions
// of machine code replacements for the low-level access procedures so that
// unless the preprocessor symbol CAUTIOUS is defined you have a chance for
// yet further savings.

// Define some utility functions for the Microsoft case...

extern "C"
{

// TlsAlloc() allocates a small integer that acts as a handle for a
// fresh thread-local. Once such a handle has been allocated TlsSetValue and
// TlsGetValue can save and load void * values from a location that it
// refers to. This location will in fact by found relative to either the FS
// or GS segment register. When the handle is no longer required it will be
// proper to cell TlsFree to release it. One can certainly not allocate more
// than 1088 handles (this value is 64+1024, and access via the first 64
// handles will be slightly cheaper than via the remaining 1024). If a
// value that you want to be thread-local can not be stored in a void * using
// TlsSetValue then it is necessary to allocate space elsewhere and set the
// Microsoft slot to point to it. I really do not want to go
// "#include <windows.h>" because that can pollute my name-space with macros
// and definitions that can clash with definitions that are otherwise
// important, and so I put in my own version of the declarations that I need.

#ifdef __LP64__
    typedef unsigned int tls_handle;
#else
    typedef unsigned long tls_handle;
#endif

    extern __declspec(dllimport) tls_handle TlsAlloc(void);
    extern __declspec(dllimport) int TlsFree(tls_handle);
    extern __declspec(dllimport) void *TlsGetValue(tls_handle);
    extern __declspec(dllimport) int TlsSetValue(tls_handle, void *);
};

#ifdef CAUTIOUS

inline void *tls_load(tls_handle teb_slot)
{   return TlsGetValue(teb_slot);
}

inline void tls_store(tls_handle teb_slot, void *v)
{   TlsSetValue(teb_slot, v);
}

#else // CAUTIOUS

// The code here is intended and expected to behave exactly like a version
// that calls the Microsoft-provided functions, except (1) it does not
// do even basic sanity checks on the slot-number that is passed
// and (b) it can expand into inline code that then runs faster that the
// official version even if it does just the same thing.

// I abstract away 32 vs 64-bit Windows issues here. The offsets used are from
// www.geoffchappell.com/studies/windows/win32/ntdll/structs/teb/index.htm
// which has repeated comments about the long term stability of the memory
// layout involved.

// The basic concept is that Microsoft keep a segment register (FS on 32-bit
// systems and GS on 64) pointing to a thread-specific block of memory.
// Within that block there is a 64-bit region for user thread-locals and
// then a pointer to a larger block that provides and extended number
// of user thread-locals. TlsAlloc() allocates a "thread slot number" and
// if that is less than 64 it refers to a word in the first block, otherwise
// in the extended region.

#if __SIZEOF_POINTER__ == 4
#define MOVE_INSTRUCTION "movl"
#define SEGMENT_REGISTER "%%fs"
#define basic_TLS_offset           0xe10
#define extended_TLS_offset        0xf94
#else // Windows 32 vs 64 bit
#define MOVE_INSTRUCTION "movq"
#define SEGMENT_REGISTER "%%gs"
#define basic_TLS_offset           0x1480
#define extended_TLS_offset        0x1780
#endif // Windows 32 vs 64 bit

inline void *read_via_segment_register(tls_handle n)
{   void *r;
    asm volatile
    (   MOVE_INSTRUCTION "  " SEGMENT_REGISTER ":(%1), %0"
        : "=r" (r)
        : "r" (n)
        :
    );
    return r;
}

inline void write_via_segment_register(tls_handle n, void *v)
{   asm volatile
    (   MOVE_INSTRUCTION " %0, " SEGMENT_REGISTER ":(%1)"
        :
        : "r" (v), "r" (n)
        :
    );
}

inline void *extended_tls_load(tls_handle teb_slot)
{   void **a = (void **)read_via_segment_register(
                   extended_TLS_offset);
    return a[teb_slot - 64];
}

inline void extended_tls_store(tls_handle teb_slot, void *v)
{   void **a = (void **)read_via_segment_register(
                   extended_TLS_offset);
    a[teb_slot - 64] = v;
}

inline void *tls_load(tls_handle teb_slot)
{   if (teb_slot >= 64) return extended_tls_load(teb_slot);
    else return reinterpret_cast<void *>(read_via_segment_register(
                basic_TLS_offset + sizeof(void *)*teb_slot));
}

inline void tls_store(tls_handle teb_slot, void *v)
{   if (teb_slot >= 64) return extended_tls_store(teb_slot, v);
    else write_via_segment_register(
            basic_TLS_offset + sizeof(void *)*teb_slot, v);
}

#endif // CAUTIOUS

// The purpose of this class is to encapsulate an allocation of a slot in
// Microsoft's table of TLS locations. In declare_thread_local I create a
// static instance of it. It is guaranteed that the constructor here gets
// called before and use of the object, and that the object outlasts any
// possible use of it.

class TlsHandle
{
public:
    tls_handle h;
    TlsHandle()
    {   h = TlsAlloc();
    }
    ~TlsHandle()
    {   TlsFree(h);
    }
};

// declare_thread_local() can be used when the type passed is convertable to
// void *, so intptr_t, uintptr_t and any sort of pointer should be OK.
// Simple integers should be widened to (u)intptr_t for use here.

#ifdef DEBUG
#define declare_thread_local(name, Type)                      \
class name                                                    \
{                                                             \
    static inline TlsHandle H;                                \
    static inline thread_local Type val;                      \
public:                                                       \
    static Type get()                                         \
    {   return (Type)tls_load(H.h);                           \
    }                                                         \
    static void set(Type v)                                   \
    {   tls_store(H.h, reinterpret_cast<void *>(v));                            \
        val = v;                                              \
    }                                                         \
};
#else // DEBUG
#define declare_thread_local(name, Type)                      \
class name                                                    \
{                                                             \
    static inline TlsHandle H;                                \
public:                                                       \
    static Type get()                                         \
    {   return (Type)tls_load(H.h);                           \
    }                                                         \
    static void set(Type v)                                   \
    {   tls_store(H.h, reinterpret_cast<void *>(v));                            \
    }                                                         \
};
#endif // DEBUG

#define declare_thread_local_ref(name, Type)                  \
class name ## _Ref                                            \
{                                                             \
    static Type* get()                                        \
    {   static thread_local Type val;                         \
        return &val;                                          \
    }                                                         \
public:                                                       \
    static inline TlsHandle H;                                \
    name ## _Ref()                                            \
    {   tls_store(H.h, reinterpret_cast<void *>(get()));                        \
    }                                                         \
};                                                            \
class name                                                    \
{                                                             \
public:                                                       \
    static Type &get()                                        \
    {   static thread_local name ## _Ref val;                 \
        return *(Type *)tls_load(val.H.h);                    \
    }                                                         \
};

#elif defined __cpp_inline_variables

// Here I have inline variables but I am not going to use any Microsoft
// specialities - this is really just a simple wrapping of a plain
//     inline thread_local T name;
// declaration, with get() and set() methods solely to provide compatibility
// with the other cases that have to be more complicated.

#define declare_thread_local(name, Type)                      \
class name                                                    \
{                                                             \
    static inline thread_local Type val;                      \
public:                                                       \
    static Type& get()                                        \
    {   return val;                                           \
    }                                                         \
    static void set(Type v)                                   \
    {   val = v;                                              \
    }                                                         \
};

#define declare_thread_local_ref(name, Type)                  \
class name                                                    \
{                                                             \
    static inline thread_local Type val;                      \
public:                                                       \
    static Type& get()                                        \
    {   return val;                                           \
    }                                                         \
};

#else

// Here I do not have C++17 inline variables, and I will assume that I
// do not need to worry about Microsoft. I cope by wrapping variable
// definitions within (inline) functions. Well all the methods in a class
// are treated as inline without me needing to use that keyword.
// This may have slightly inferior performance to the version that uses
// inline variables in that the functions that encapsulate variable
// definitions may feel the need to keep a "first time" flag and initialize
// the variable on the first occasion that control traverses the definition.
//
// Well this case can also apply under Cygwin/mingw32 (and indeed elsewhere
// if you do not specify "-std=c++17" as an option for g++. I view that as
// possibly good since it lets me drop down to this simpler scheme if I
// find it easier for use with a debugger!

#define declare_thread_local(name, Type)                      \
class name                                                    \
{                                                             \
    static Type& val()                                        \
    {   static thread_local Type Val;                         \
        return Val;                                           \
    }                                                         \
public:                                                       \
    static Type& get()                                        \
    {   return val();                                         \
    }                                                         \
    static void set(Type v)                                   \
    {   val() = v;                                            \
    }                                                         \
};

#define declare_thread_local_ref(name, Type)                  \
class name                                                    \
{                                                             \
public:                                                       \
    static Type& get()                                        \
    {   static thread_local Type val;                         \
        return val;                                           \
    }                                                         \
};

#endif // __cpp_inline_variables

#endif // header_thread_local_h

// end of thread_local.h

