// threadloc.h                                  Copyright (C) 2024 Codemist

#ifndef header_threadloc_h
#define header_threadloc_h 1

/**************************************************************************
 * Copyright (C) 2024, Codemist.                         A C Norman       *
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

// $Id: threadloc.h 127 2024-01-05 22:03:06Z acn1 $

// Using the "thread_local" qualifier in the declaration of a variable
// imposes overheads that I found unexpected on Windows. The code here
// is intended to address that issue. I can predefined USE_CXX_TLS to
// fall back to standard code.

// The costs follow from the C++ need to support objects with non-trivial
// destructors. For my purposes I will be content to have just a thread-
// local varriable of pointer type. I can use that to point at a structure
// managed by the general and slower mechanism that contains all the
// values I need. So usage is expected to be along the lines of:

//::  struct MyThreadLocalStruct
//::  {
//::      int var1;
//::      double array[10];
//::      std::vector<std::string> vs;
//::  };
//::  inline constexpr int TL_tlStruct = 55; // Value in the range 48-63
//::  DEFINE_THREAD_LOCAL(MyThreadLocalStruct, tlStruct);
//::
//::  .. then use      tlStruct->var1    etc.
//::

// For an integer or pointer values it may be useful to save one indirection
// and go eg

//::  inline constexpr int TL_intVar = 56;
//::  DEFINE_THREAD_LOCAL_POD(int, intVar, 99);
//::  inline constexpr int TL_ptrVar = 56;
//::  DEFINE_THREAD_LOCAL_POD(const char*, ptrVar, "Some String Data");
//::
//::  .. then use intVar and ptrVar directly.


// For initialization to work every thread-function needs to start by
// calling ThreadLocal::initialize().
// This is needed (well only on Windows!) because the reference to something
// looks like a thread-local variable X is in fact a call to a function
// that does not use C++ thread support directly. It used the Microsoft API.
// That means that C++ is utterly unaware of any need for initialization
// beyond the base thread. I use trickery involving a vector of
// lambda-functions to get things initialized in subsidiary threads, and
// the call to initialize() deals with this.

// I will explain what the expansion needs to be. First in the
// non-Windows case, all of which is pretty straightforward:
//
//   DEFINE_THREAD_LOCAL(T, name) =>
//       [/static/inline] thread_local T TLDATA_name;
//       [/static/inline] T* name = &TLDATA__name;
//
//   DEFINE_THREAD_LOCAL_POD(T, name, init) =>
//       [/static/inline] T name = init;
//
// The Windows cases are different... and is messy enough that it deserves
// explantion. TL_name will be a const giving a numerical offset within the
// Microsoft TLS vector. The ThreadLocalObject is a wrapper that causes
// its instance to behave (almost) as if it is a simple thread local
// variable of type T (which must be consistent with intptr or void*) but
// that uses the slot in the Microsoft vector addressed relative to a segment
// register. When constructed it sets the slot for the thread it is running
// in to the initial value give. This is expected to be in the main thread.
// In other threads  the slots are not automatically initialized, so
// initVec is set up holding a number of zero-argument functions each of
// which initializes one of the thread local objects that have been declared
// this way. A method 
//
//   DEFINE_THREAD_LOCAL_POD(T, name, init)
//       ThreadLocal::ThreadLocalObject<T, TL_name> name(init);
//       inline bool INIT_name = [](){
//           ThreadLocal::initVec.push_back([]()
//               { name = init; });
//           return true; } ();
//
//   DEFINE_THREAD_LOCAL(T, name)
//       [/static] T TLDATA_name;
//       DEFINE_THREAD_LOCAL_POD(T*, name, &TLDATA__name);
//
//   DEFINE_INLINE_THREAD_LOCAL(T, name)
//       inline auto TLFN_name()
//       {   static thread_local T TLDATA_name;
//           return &TLDATA_name;
//       }
//       DEFINE_THREAD_DATA_POD(T*, name, &TLFN__name());


#include <cstdint>
#include <cinttypes>

namespace ThreadLocal
{
#if (defined __CYGWIN__ || defined __MINGW32__) && !defined USE_CXX_TLS

// With Cygwin and mingw32 (as of 2021) the support of thread-local variables
// uses a mechanism "emutls". For code that makes extensive use of such
// variables in many separate little functions this can add severe overhead.
// Microsoft provides a scheme of rather different style to support
// thread-local. Direct use of it just allows the storage of "void *" values,
// and there is a limit to how many can be stored -- although for my purposes
// the limit is plenty high enough. Using it tends to lead to much better
// performance (though lower flexibility) than emutls. If one has a set of
// large functions that do heavy work within them then thread_local overheads
// can be low regardless - the C++ compiler can load a base address for
// thread local data once and re-use it. So costs are only bad when one
// has SMALL functions that reference thread local values and where these
// small functions are code hot-spots. However with Reduce I found that
// making just one key variable thread_local under Windows slowed the entire
// system down by a factor of more than 2, and that led eventually to the
// dubious scheme implemented here.

// I define system entrypoints by hand here because if I were to
// include <windows.h> that would bring in many more definitions some
// of which I might really not want. Specifically it can defined some macros
// that clash with Cygwin.

extern "C"
{

// TlsAlloc() allocates a small integer that acts as a handle for a
// fresh thread-local. Once such a handle has been allocated TlsSetValue and
// TlsGetValue can save and load void* values from a location that it
// refers to. When the handle is no longer required it will be
// proper to call TlsFree to release it. One can certainly not allocate more
// than 1088 handles (this value is 64+1024, and access via the first 64
// handles will be slightly cheaper than via the remaining 1024). If a
// value that you want to be thread-local can not be stored in a void * using
// TlsSetValue then it is necessary to allocate space elsewhere and set the
// Microsoft slot to point to it.

#ifdef __LP64__
    typedef unsigned int tls_handle;
#else // __LP64__
    typedef unsigned long tls_handle;
#endif // __LP64__

    extern __declspec(dllimport) tls_handle TlsAlloc(void);
    extern __declspec(dllimport) int TlsFree(tls_handle);
};

// The first 64 TLS handles are supported with greater efficiency than
// ones beyond that. I wish to reserve 48-63 for my own use. This function
// that claims them must be run before any other part of the applications
// has grabbed enough to conflict. After it has run the Microsoft scheme
// should remain available for all other purposes.
// I am going to ASSUME that during static initialization no more than
// 48 thread handles are allocated by library and other parts of the code.
// This is not a fully safe assumption in general!

// I do things that way I do so that each user thread_local slot is
// allocated at compile time so that the run-time indexing uses a
// known value. Doing this gives a slight performance edge!

inline bool initThreadHandles()
{   static bool initialized = false;
    if (initialized) return true;     // I will only do this once.
    std::uint64_t map = -1;
// Here I rely on TlsAlloc() returning handles in the range 0-63
// before any larger ones.
    for (;;)
    {   tls_handle h = TlsAlloc();
        if (h >= 64) return false;
        map &= ~(UINT64_C(1)<<h);
        if ((map & 0xffff000000000000U) == 0) break;
    }
// I will have reserved some handles that I am not about to use, and
// those are identified in the bitmap. Free them.
    for (int i=0; i<48; i++)
        if ((map & (UINT64_C(1)<<i)) == 0) TlsFree(i);
    initialized = true;
    return true;
}

// This static initialization will guarantee that initThreadHandles is
// called before main(). If enough DLLs are linked in and use thread-local
// slots then this may fail! This initilizer must also be run before that
// of any of my ThreadLocal objects.

inline bool getThreadhandles = initThreadHandles();


// I abstract away 32 vs 64-bit Windows issues here. The offsets used are from
// www.geoffchappell.com/studies/windows/win32/ntdll/structs/teb/index.htm
// which has repeated comments about the long term stability of the memory
// layout involved. Specificall the judgement expressed there is that so
// much extant code will rely on the details of all this that it can not
// be changed.

// The basic concept is that Microsoft keep a segment register (FS on 32-bit
// systems and GS on 64) pointing to a thread-specific block of memory.
// Within that block there is a 64-bit region for user thread-locals and
// then a pointer to a larger block that provides and extended number
// of user thread-locals. TlsAlloc() allocates a "thread slot number" and
// if that is less than 64 it refers to a word in the first block, otherwise
// in the extended region. Here I will not support the extended region!

#if __SIZEOF_POINTER__ == 4
#define MOVE_INSTRUCTION "movl"
#define SEGMENT_REGISTER "%%fs"
#define TLS_offset           0xE10
#else // Windows 32 vs 64 bit
#define MOVE_INSTRUCTION "movq"
#define SEGMENT_REGISTER "%%gs"
#define TLS_offset           0x1480
#endif // Windows 32 vs 64 bit

// The next two functions access values relative to the proper
// segment register. The template argument must allow for the offset of
// the block of 64 slots in the region pointed at by the segment register
// and also the size of each slot.

// Experimentally I seem to need to put "asm volatile" in both of these
// cases to end up with code that does not fail. I do not think I
// understand why that could be vital on read_via_segmemt_register...
// But at present this seems to work!

template <int N>
inline void *read_via_segment()
{   void *r;
    asm volatile
    (   MOVE_INSTRUCTION "  " SEGMENT_REGISTER ":%c1, %0"
        : "=r" (r)
        : "i" (N)
    );
    return r;
}

template <int N>
inline void write_via_segment(void *v)
{   asm volatile
    (   MOVE_INSTRUCTION " %0, " SEGMENT_REGISTER ":%c1"
        :
        : "r" (v), "i" (N)
    );
}

// The purpose of the following class is to arrange that when you
// have declared an instance of it that then access to the value get mapped
// onto the "via_segment_register" functions above. 
// I overload and hence support those operations used within CSL, and
// will add support for others here as and when I find I need to so that
// the class instance can be used almost as if it was a simple variable
// of type T. But its address may not be taken.

// I will require the type T to be one where its data can be held
// in a "void *" location. So any pointer type will be OK and
// intptr_t/uintptr_t should work. char/short/int will probably be OK.

template <typename T, int N>
class ThreadLocalObject
{
public:
// Here I use a C style case rather than eg reinterpret_cast because I
// want to adjust the data come what may, including any case with "const"
// qualifiers.
    ThreadLocalObject(T v)
    {   write_via_segment<TLS_offset+N*sizeof(void *)>((void *)v);
    }
    T operator=(T v)
    {   write_via_segment<TLS_offset+N*sizeof(void *)>((void *)v);
        return v;
    }
    T operator ->()
    {   return reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>());
    }
    T& operator [](size_t n)
    {   return reinterpret_cast<T*>(
            read_via_segment<TLS_offset+N*sizeof(void *)>())[n];
    }
//    T& operator *()
//    {   return *reinterpret_cast<T*>(
//            read_via_segment<TLS_offset+N*sizeof(void *)>());
//    }
    operator T() const
    {   return reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>());
    }
    template <typename T1>
    operator T1() const
    {   return (T1)
            read_via_segment<TLS_offset+N*sizeof(void *)>();
    }
    T operator ++()
    {   T v = reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>())
            + 1U;
        write_via_segment<TLS_offset+N*sizeof(void *)>((void *)v);
        return v;
    }
    T operator ++(int)
    {   T v = reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>());
        write_via_segment<TLS_offset+N*sizeof(void *)>((void *)(v + 1U));
        return v;
    }
    T operator --()
    {   T v = reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>())
            - 1U;
        write_via_segment<TLS_offset+N*sizeof(void *)>((void *)v);
        return v;
    }
    T operator --(int)
    {   T v = reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>());
        write_via_segment<TLS_offset+N*sizeof(void *)>((void *)(v - 1U));
        return v;
    }
    template <typename T1>
    T operator +=(T1 n)
    {   T v = reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>()) +
            static_cast<uintptr_t>(n);
        write_via_segment<TLS_offset+N*sizeof(void *)>((void *)v);
        return v;
    }
    template <typename T1>
    T operator -=(T1 n)
    {   T v = reinterpret_cast<T>(
            read_via_segment<TLS_offset+N*sizeof(void *)>()) -
            static_cast<uintptr_t>(n);
        write_via_segment<TLS_offset+N*sizeof(void *)>((void *)(v));
        return v;
    }
// I could put in overrides for &, &= and all the other operators that C++
// lets me defined, but at present I do not really even need all that is
// included here already.
};
typedef void ZeroArgFunction();
inline std::vector <ZeroArgFunction*> initVec;

inline void initialize()
{   for (auto fn:initVec) (fn)();
}

   
#endif // MICROSOFT special version.

#if (defined __CYGWIN__ || defined __MINGW32__) && !defined USE_CXX_TLS

// The Windows cases are different... and is messy enough that it deserves
// explantion. TL_name will be a const giving a numerical offset within the
// Microsoft TLS vector. The ThreadLocalObject is a wrapper that causes
// its instance to behave (almost) as if it is a simple thread local
// variable of type T (which must be consistent with intptr or void*) but
// that uses the slot in the Microsoft vector addressed relative to a segment
// register. When constructed it sets the slot for the thread it is running
// in to the initial value give. This is expected to be in the main thread.
// In other threads  the slots are not automatically initialized, so
// initVec is set up holding a number of zero-argument functions each of
// which initializes one of the thread local objects that have been declared
// this way. A method 
//
//   DEFINE_THREAD_LOCAL_POD(T, name, init)
//       ThreadLocal::ThreadLocalObject<T, TL_name> name(init);
//       inline bool INIT_name = [](){
//           ThreadLocal::initVec.push_back([]()
//               { name = init; });
//           return true; } ();
//
//   DEFINE_THREAD_LOCAL(T, name)
//       [/static] T TLDATA_name;
//       DEFINE_THREAD_LOCAL_POD(T*, name, &TLDATA__name);
//
//   DEFINE_INLINE_THREAD_LOCAL(T, name)
//       inline auto TLFN_name()
//       {   static thread_local T TLDATA_name;
//           return &TLDATA_name;
//       }
//       DEFINE_THREAD_DATA_POD(T*, name, &TLFN__name());

#define DECLARE_THREAD_LOCAL(T, name) \
   extern ThreadLocal::ThreadLocalObject<T, TL_##name> name;

#define DEFINE_THREAD_LOCAL(T, name)              \
   thread_local T TLSTRUCT_##name;                \
   DEFINE_THREAD_LOCAL_POD(T*, name, &TLSTRUCT_##name);
   
#define DEFINE_STATIC_THREAD_LOCAL(T, name)              \
   static thread_local T TLSTRUCT_##name;                \
   DEFINE_STATIC_THREAD_LOCAL_POD(T*, name, &TLSTRUCT_##name);
   
#define DEFINE_INLINE_THREAD_LOCAL(T, name)              \
   inline T* TLFN_##name()                               \
   {   static thread_local T TLSTRUCT_##name;            \
       return &TLSTRUCT_##name;                          \
   }                                                     \
   DEFINE_INLINE_THREAD_LOCAL_POD(T*, name, TLFN_##name());
   
// The "_POD" versions are for when the payload is "Plain Old Data" and
// in particular it is a value that can be stored in a slot that is
// an intptr_t or a void*. The definitions include an initialiser.

#define DECLARE_THREAD_LOCAL_POD(T, name) \
   extern ThreadLocal::ThreadLocalObject<T, name> name;

#define DEFINE_THREAD_LOCAL_POD(T, name, init)                      \
    thread_local ThreadLocal::ThreadLocalObject<T,name> name(init); \
    bool INIT_##name = [](){                                        \
        ThreadLocal::initVec.push_back([]()                         \
            { name = init; });                                      \
        return true; } ();
   
#define DEFINE_STATIC_THREAD_LOCAL_POD(T, name, init) \
   static thread_local T name = init;
   
#define DEFINE_INLINE_THREAD_LOCAL_POD(T, name, init) \
   inline thread_local T name = init;

#else // Can use compiler-provided thread_local.

inline void initialize()
{
}

#define DECLARE_THREAD_LOCAL(T, name) \
   extern thread_local T* name;

#define DEFINE_THREAD_LOCAL(T, name)              \
   thread_local T TLSTRUCT_##name;                \
   thread_local T* name = &TLSTRUCT_##name;
   
#define DEFINE_STATIC_THREAD_LOCAL(T, name)              \
   static thread_local T TLSTRUCT_##name;                \
   static thread_local T* name = &TLSTRUCT_##name;
   
#define DEFINE_INLINE_THREAD_LOCAL(T, name)              \
   inline thread_local T TLSTRUCT_##name;                \
   inline thread_local T* name = &TLSTRUCT_##name;
   
// The "_POD" versions are for when the payload is "Plain Old Data" and
// in particular it is a value that can be stored in a slot that is
// an intptr_t or a void*. The definitions include an initialiser.

#define DECLARE_THREAD_LOCAL_POD(T, name) \
   extern T name;

#define DEFINE_THREAD_LOCAL_POD(T, name, init) \
   thread_local T name = init;
   
#define DEFINE_STATIC_THREAD_LOCAL_POD(T, name, init) \
   static thread_local T name = init;
   
#define DEFINE_INLINE_THREAD_LOCAL_POD(T, name, init) \
   inline thread_local T name = init;
   
#endif // WIN32 vs language-provided thread-local.


} // end of namespace ThreadLocal

#endif // header_threadloc_h

// end of threadloc.h
