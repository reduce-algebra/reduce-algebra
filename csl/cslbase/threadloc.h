// threadloc.h                                  Copyright (C) 2021 Codemist

#ifndef header_threadloc_h
#define header_threadloc_h 1

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

// $Id: threadloc.h March 2021 arthurcnorman $


#ifdef AVOID_THREADLOCAL
#define thread_local
#endif //AVOID_THREADLOCAL

#if defined CONSERVATIVE

// The CONSERVATIVE build of CSL will be working towards support for
// multiple threads. So this code is activated there. Prior versions do
// not have any user threads and so do not need it, and so I disable it
// to avoid introducing any overhead, even small.

#if (defined __CYGWIN__ || defined __MINGW32__) && \
    !defined USE_CXX_TLS && !defined AVOID_THREADLOCAL
#define MICROSOFT_TLS 1
#endif

#ifdef MICROSOFT_TLS

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

inline void initThreadLocals()
{   static bool initialised = false;
    if (initialised) return;
    std::uint64_t map = -1;
    for (;;)
    {   tls_handle h = TlsAlloc();
        if (h >= 64) my_abort("Failed to grab thread handles");
        map &= ~(UINT64_C(1)<<h);
        if ((map & 0xffff000000000000U) == 0) break;
    }
    for (int i=0; i<48; i++)
        if ((map & (1U<<i)) == 0) TlsFree(i);
    initialised = true;
}

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
// in the extended region. Here I will not support the extended region!

#if __SIZEOF_POINTER__ == 4
#define MOVE_INSTRUCTION "movl"
#define SEGMENT_REGISTER "%%fs"
#define basic_TLS_offset           0xE10
#else // Windows 32 vs 64 bit
#define MOVE_INSTRUCTION "movq"
#define SEGMENT_REGISTER "%%gs"
#define basic_TLS_offset           0x1480
#endif // Windows 32 vs 64 bit

// The next two functions access values relative to the proper
// segment register. The template argument must allow for the offset of
// the block of 64 slots in the region pointed at by the segment register
// and also the size of each slot.

// Experimentally I seem to need to put "asm volatile" in both of these
// cases to end up with code that does not fail. I do not think I
// understand why that could be vital on read_via_segmemt_register...

template <int N>
inline void *read_via_segment_register()
{   void *r;
    asm volatile
    (   MOVE_INSTRUCTION "  " SEGMENT_REGISTER ":%c1, %0"
        : "=r" (r)
        : "i" (N)
    );
    return r;
}

template <int N>
inline void write_via_segment_register(void *v)
{   asm volatile
    (   MOVE_INSTRUCTION " %0, " SEGMENT_REGISTER ":%c1"
        :
        : "ri" (v), "i" (N)
    );
}

// The purpose of the following class is to arrange that when you
// have declared an instance of it that access to that value get mapped
// onto the "via_segment_register" functions above. 
// I overload and hence support those operations used within CSL, and
// will add support for others here as and when I find I need to.

template <typename T, int N>
class ThreadLocal
{
public:
    T operator=(T v)
    {   write_via_segment_register<basic_TLS_offset+N*sizeof(void *)>(
            reinterpret_cast<void *>(v));
        return v;
    }
    operator T() const
    {   return reinterpret_cast<T>(
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>());
    }
    template <typename T1>
    operator T1() const
    {   return (T1)
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>();
    }
    T operator ++()
    {   T v = reinterpret_cast<T>(
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>())
            + 1U;
        write_via_segment_register<basic_TLS_offset+N*sizeof(void *)>(
            reinterpret_cast<void *>(v));
        return v;
    }
    T operator ++(int)
    {   T v = reinterpret_cast<T>(
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>());
        write_via_segment_register<basic_TLS_offset+N*sizeof(void *)>(
            reinterpret_cast<void *>(v + 1U));
        return v;
    }
    T operator --()
    {   T v = reinterpret_cast<T>(
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>())
            - 1U;
        write_via_segment_register<basic_TLS_offset+N*sizeof(void *)>(
            reinterpret_cast<void *>(v));
        return v;
    }
    T operator --(int)
    {   T v = reinterpret_cast<T>(
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>());
        write_via_segment_register<basic_TLS_offset+N*sizeof(void *)>(
            reinterpret_cast<void *>(v - 1U));
        return v;
    }
    template <typename T1>
    T operator +=(T1 n)
    {   T v = reinterpret_cast<T>(
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>()) +
            static_cast<uintptr_t>(n);
        write_via_segment_register<basic_TLS_offset+N*sizeof(void *)>(
            reinterpret_cast<void *>(v));
        return v;
    }
    template <typename T1>
    T operator -=(T1 n)
    {   T v = reinterpret_cast<T>(
            read_via_segment_register<basic_TLS_offset+N*sizeof(void *)>()) -
            static_cast<uintptr_t>(n);
        write_via_segment_register<basic_TLS_offset+N*sizeof(void *)>(
            reinterpret_cast<void *>(v));
        return v;
    }
};

// Now for the abstraction. DECLARE_THREAD_LOCAL and DEFINE_THREAD_LOCAL
// do what you might expect, save that they each take a final argument
// which must be in the range 48-63 and must be distict for each item
// declared.

#define DECLARE_THREAD_LOCAL(T, name) \
   extern ThreadLocal<T, TL_##name> name

#define DEFINE_THREAD_LOCAL(T, name) \
   ThreadLocal<T, TL_##name> name

#define DEFINE_INLINE_THREAD_LOCAL(T, name) \
   inline ThreadLocal<T, TL_##name> name

#else // MICROSOFT TLS

inline void initThreadLocals()
{
}

#define DECLARE_THREAD_LOCAL(T, name) \
   extern thread_local T name;

#define DEFINE_THREAD_LOCAL(T, name) \
   thread_local T name;
   
#define DEFINE_INLINE_THREAD_LOCAL(T, name) \
   inline thread_local T name;
   
#endif // MICROSOFT_TLS

#else // CONSERVATIVE

inline void initThreadLocals()
{
}

#define DECLARE_THREAD_LOCAL(T, name) \
   extern T name;

#define DEFINE_THREAD_LOCAL(T, name) \
   T name;
   
#define DEFINE_INLINE_THREAD_LOCAL(T, name) \
   inline T name;
   
#endif // CONSERVATIVE


#endif // header_threadloc_h

// end of threadloc.h
