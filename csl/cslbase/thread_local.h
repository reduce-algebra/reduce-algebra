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
// The code here is to abstract over my responses to all this. I provide
// two templates, used as follows:
//      static ThreadLocal<int *> name;
//   or static ThreadLocalRef<std::atomic<int>> name;
// where the first case is for use if the type parameter is convertible to
// and from void* and the second for more general cases.
// The second then defined (name) as something whose type is a pointer to
// the indicated type. The expected use is then that one goes something
// along the lines of (name->load()) [or some other use of "->"]. This
// visible level of indirection is because C++ allows for overloading of
// "->" but not ".".
//
// Note that even when used in a header file (which is where you should
// generaly use this, because I do not provide an "extern" varient) and
// expecting that the variable defined will be shared across all compilation
// units you should use a "static" definition! That is because the template
// expands to a wrapper that can and should be static but that arranges to
// reference the thread-local value that is really wanted.

// All this mess would not be needed if I only ever used compilers that
// supported C++17 and also if I only ever ran on platforms where use
// of the C++ thread_local keyword had at worst minimal overhead! 


// The challenge is to make encapsulated things behave (almost) as
// if they were simple variables. The trick that I use has three parts
// the first is of the form
//      inline T& getvar()
//      {   thread_local T var;
//          return var;
//      }
// where this arranges that even if the above occurs via multiple inclusions
// of header files that only one instance per thread of (var) arises. And
// getvar() returns a reference value to it. That copes with the desire to
// have what is in effect an inline variable, but at this stage suffers
// because every reference to it needs to go "getvar()" rather than "var".
//
// The second trick (mostly) overcomes that!
//      class wrapper
//      {
//      public:
//          operator T() { return getvar(); }
//          wrapper& operator=(T value)
//          {   getvar() = value;
//              return *this;
//          }
//      }
//      static wrapper name;
// Now name is declared static and so it can be defined in multiple
// compilation units, but the wrapper class has no data members and so
// an instance of it does not consume a lot of space. If you take (name)
// and use it where it will be cast to type T then the method that uses
// getvar() is activated, while assignments to it are also intercepted
// and dealt with nicely. There are cases where explicit casts of the
// form (T)name may be required to make this happen, but very often usage
// can be as if name was a simple variable. And a sufficiently good
// compiler will render the function and method invocations inline
// leading to hardly any overhead. Well the key overhead will be in
// the function getvar() which may in principle want to do initialization
// work for var the first time it is called, and so may use a hidden
// "bool firstTime" flag to control that and so test that flag on all
// subsequent calls. An update to use of C++17 will remove that (typically
// rather modest) cost.
//
// The third thing that goes on is that on Microsoft platforms I use the
// API involving TlsAlloc, TlsSetValue and TlsGetvalue to cope with
// thread-locality - however for extra performance I provide inline
// assembly-code functions to replace TlsGetValue and TlsSetValue, so my
// version avoids the overhead of procedure calls when thread-local values
// are referenced.

#include <cinttypes>
#include <mutex>

// First define some utility functions for the Microsoft case...

#if defined __CYGWIN__ || defined __MINGW32__

#define USE_MICROSOFT_API 1

// If I go "#include <windows.h>" (well the bit I actually need seems to be
// processthreadsapi.h) that tends to define all sorts of things that can
// clash with my own code. So here I put in explicit declarations for the
// thread-local support functions I use, trying rather hard to match just
// what Windows will use.

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
// Microsoft slot to point to it.

#ifdef __LP64__
typedef unsigned int tls_handle;
#else
typedef unsigned long tls_handle;
#endif

extern __declspec(dllimport) tls_handle TlsAlloc(void);
extern __declspec(dllimport) int TlsFree(tls_handle);
// I will use my own replacements for the next two. But I include
// declarations here for reference.
extern __declspec(dllimport) void *TlsGetValue(tls_handle);
extern __declspec(dllimport) int TlsSetValue(tls_handle, void *);
};

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
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    return a[teb_slot - 64];
}

inline void extended_tls_store(tls_handle teb_slot, void *v)
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    a[teb_slot - 64] = v;
}

inline void *tls_load(tls_handle teb_slot)
{   if (teb_slot >= 64) return extended_tls_load(teb_slot);
    else return (void *)read_via_segment_register(
        basic_TLS_offset + sizeof(void *)*teb_slot);
}

inline void tls_store(tls_handle teb_slot, void *v)
{   if (teb_slot >= 64) return extended_tls_store(teb_slot, v);
    else write_via_segment_register(
        basic_TLS_offset + sizeof(void *)*teb_slot, v);
}

#endif // Microsoft case


// Usage:   static ThreadLocal<T> var;
//    acts rather like
//          inline thread_local T var;
//    or
//          static ThreadLocal<T> var(init);
//    for
//          inline thread_local T var = init;
// subject to a constraint that casting between T and void * must be valid.

template <typename T>
class ThreadLocal
{
    inline bool& initialized()
    {   static bool flag;
        return flag;
    }
    inline std::mutex& mutex()
    {   static std::mutex m;
        return m;
    }
#ifdef USE_MICROSOFT_API
#ifdef __cpp_inline_variables
// I need a single (ie not thread_local and not per-compilation-unit)
// variable slotNumber to record the number in Microsoft's thread block.
    static inline tls_handle slotNumber;
    inline tls_handle& getSlotNumber()
    {   return slotNumber;
    }
#else
    inline tls_handle& getSlotNumber()
    {   static tls_handle slotNumber;
        return slotNumber;
    }
#endif
// Simple thread-local values that can be case to and from (void *) are
// then stored directly in the Microsoft table.
    inline T getter()
    {   return (T)tls_load(getSlotNumber());
    }
    inline void setter(T value)
    {   tls_store(getSlotNumber(), (void *)value);
    }
#else // !Microsoft
// In the non-Microsoft case I want just an "inline thread_local" variable,
// but prior to C++17 I have to provide that via trickery.
#ifdef __cpp_inline_variables
    static inline thread_local T data;
    inline T& getData()
    {   return data;
    }
#else
    inline T& getData()
    {   thread_local T data;
        return data;
    }
#endif
    inline T getter()
    {   return getData();
    }
    inline void setter(T value)
    {   getData() = value;
    }
#endif // !Microsoft

public:
// Although there will be only one instance (per thread!) of the
// thread-local value that this class encapsulates there can be many
// instances of the class itself. There are no non-static fields in the
// class and so an instance should not use up much (if any) space.
// To be fully cautious I guard initialization with a mutex and with a
// flag that ensures that it is done just once.
    ThreadLocal()
    {   std::lock_guard<std::mutex> lock(mutex());
        if (!initialized())
        {   initialized() = true;
#ifdef USE_MICROSOFT_API
            getSlotNumber() = TlsAlloc();
#endif
        }
    }
    ThreadLocal(T init)
    {   std::lock_guard<std::mutex> lock(mutex());
        if (!initialized())
        {   initialized() = true;
#ifdef USE_MICROSOFT_API
            getSlotNumber() = TlsAlloc();
#endif
            setter(init);
        }
    }
    ~ThreadLocal()
    {   std::lock_guard<std::mutex> lock(mutex());
        if (initialized())
        {   initialized() = false;
#ifdef USE_MICROSOFT_API
            TlsFree(getSlotNumber());
#endif
        }
    }
    operator T() { return getter(); }
    ThreadLocal& operator=(T val)
    {   setter(val);
        return *this;
    }
    ThreadLocal& operator+=(uintptr_t val)
    {   setter(getter() + val);
        return *this;
    }
    ThreadLocal& operator-=(uintptr_t val)
    {   setter(getter() - val);
        return *this;
    }                                                 
};

// The version above can store thread_local values that can be converted
// to void *. This next one will support other types. In the Microsoft
// case it has to do that by first storing a thread_local instance
// So
//     static ThreadLocalRef<T> var;
// behaves rather like
//     inline thread_local T actual_var;
//     inline thread_local T* var = &actual_var;
// and this will perhaps most often be used when T is a class type, say with
// fields a, b and c, and then
//       var->a
// etc can be used to access those fields. The indirection involved is
// necessary in the Microsoft mapping and so is imposed in every case so
// that usage is uniform.

template <typename T>
class ThreadLocalRef
{
    inline bool& initialized()
    {   static bool flag;
        return flag;
    }
    inline std::mutex& mutex()
    {   static std::mutex m;
        return m;
    }
#ifdef USE_MICROSOFT_API
#ifdef __cpp_inline_variables
// I need a single (ie not thread_local and not per-compilation-unit)
// variable slotNumber to record the number in Microsoft's thread block.
    static inline tls_handle slotNumber;
    inline tls_handle& getSlotNumber()
    {   return slotNumber;
    }
#else
    inline tls_handle& getSlotNumber()
    {   static tls_handle slotNumber;
        return slotNumber;
    }
#endif
// Non-simple items have a pointer to them stored in the TLS slot, and
// for this to happen there has to be an item to point to.
#ifdef __cpp_inline_variables
    static inline thread_local T data;
    inline T* getData()
    {   return &data;
    }
#else
    inline T* getData()
    {   thread_local T data;
        return &data;
    }
#endif
    inline T* getter()
    {   return (T*)tls_load(getSlotNumber());
    }
    inline void setter(T value)
    {   *(T*)tls_load(getSlotNumber()) = value;
    }
#else // !Microsoft
// In the non-Microsoft case I want just an "inline thread_local" variable,
// but prior to C++17 I have to provide that via trickery.
#ifdef __cpp_inline_variables
    static inline thread_local T data;
    inline T* getData()
    {   return &data;
    }
#else
    inline T* getData()
    {   thread_local T data;
        return &data;
    }
#endif
    inline T* getter()
    {   return getData();
    }
    inline void setter(T value)
    {   *getData() = value;
    }
#endif // !Microsoft

public:
    ThreadLocalRef()
    {   std::lock_guard<std::mutex> lock(mutex());
        if (!initialized())
        {   initialized() = true;
#ifdef USE_MICROSOFT_API
            getSlotNumber() = TlsAlloc();
            tls_store(getSlotNumber(), (void *)getData());
#endif
        }
    }
    ~ThreadLocalRef()
    {   std::lock_guard<std::mutex> lock(mutex());
        if (initialized())
        {   initialized() = false;
#ifdef USE_MICROSOFT_API
            TlsFree(getSlotNumber());
#endif
        }
    }
    operator T*() { return getter(); }
    
    ThreadLocalRef& operator=(T val)
    {   setter(val);
        return *this;
    }
    T* operator->() { return getter(); }
};

// Now having set that bit of mechanism up I will provide something along
// the same line JUST for supporting inline variables.
// Thus
//     static Inline<T> var;
// may be used where if one was certain that the C++ compiler used was
// modern enough it would have been more natural to write just
//     inline T var;
// As with Thread_local one can set an initial value as in
//     static Inline<T> var(init);


template <typename T>
class Inline
{
    inline bool& initialized()
    {   static bool flag;
        return flag;
    }
    inline std::mutex& mutex()
    {   static std::mutex m;
        return m;
    }
#ifdef __cpp_inline_variables
    static inline T data;
    inline T& getData()
    {   return data;
    }
#else
    inline T& getData()
    {   static T data;
        return data;
    }
#endif
    inline T getter()
    {   return getData();
    }
    inline void setter(T value)
    {   getData() = value;
    }

public:
    Inline()
    {
    }
    Inline(T init)
    {   std::lock_guard<std::mutex> lock(mutex());
        if (!initialized())
        {   initialized() = true;
            setter(init);
        }
    }
    operator T() { return getter(); }
    Inline& operator=(T val)
    {   setter(val);
        return *this;
    }
    Inline& operator+=(uintptr_t val)
    {   setter(getter() + val);
        return *this;
    }
    Inline& operator-=(uintptr_t val)
    {   setter(getter() - val);
        return *this;
    }                                                 
};

// This is for inline variables where the type is a class.

template <typename T>
class InlineRef
{
    inline bool& initialized()
    {   static bool flag;
        return flag;
    }
    inline std::mutex& mutex()
    {   static std::mutex m;
        return m;
    }
#ifdef __cpp_inline_variables
    static inline thread_local T data;
    inline T* getData()
    {   return &data;
    }
#else
    inline T* getData()
    {   thread_local T data;
        return &data;
    }
#endif
    inline T* getter()
    {   return getData();
    }
    inline void setter(T value)
    {   *getData() = value;
    }

public:
    operator T*() { return getter(); }
    
    InlineRef& operator=(T val)
    {   setter(val);
        return *this;
    }
    T* operator->() { return getter(); }
};

#ifdef SMALL_TEST

// Some test code

#include <iostream>
#include <atomic>

// Despite these being set up as "static" the thread-local variables
// that they establish will be shared across all compilation units that
// include this definition.

static ThreadLocal<intptr_t> x(1);
static ThreadLocalRef<std::atomic<intptr_t>> y;

int main(int argc, char *argv[])
{
    std::cout << x << std::endl;
    x = 3;
    std::cout << x << std::endl;
    x += 4;
    std::cout << x << std::endl;
    x = x + 4;
    std::cout << x << std::endl;

    y->store(17);
    std::cout << y->load() << std::endl;
    std::cout << y << std::endl;
// If y had been just std::atomic<intptr_t> I could have gone
//        intptr_t val = y;
//     or std::cout << ((intptr_t)y) << std::endl;
// but, with the wrapping, I need to use ->load() or things get confused.
    return 0;
}

#endif // SMALL_TEST

#endif // header_thread_local_h

// end of thread_local.h


