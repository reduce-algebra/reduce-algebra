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


// Cygwin and mingw32 both seem to use "emutls" to support the C++11
// keyword "thread_local". This can have severe performance consequences
// in the sort of use I wish to make of it where rather small leaf functions
// access thread_local values.
//

#if defined __CYGWIN__ || defined __MINGW32__
extern void *tls_load();
extern void tls_store(void *v);
#endif // __CYGWIN__ || __MINGW32__

#ifdef CSL

// All values that are to be thread-local are collected and kept within
// a single class object.

class ThreadLocals
{
public:
    int thread_id;
    size_t Xboffo_size;
    size_t Xboffop;
    char *Xboffo;
   
    size_t fluid_values_size;
    size_t fluid_values_count;
    LispObject *fluid_values[1]; // will in fact be much longer

#if defined __CYGWIN__ || defined __MINGW32__
// On Microsoft platforms the construction of this object causes its
// address to be stored in an offset relative to a segment register. The
// offset concerned gets allocated by the time tls_store makes use of it.
    ThreadLocals()
    {   tls_store(reinterpret_cast<void *>(this));
    }
#endif // __CYGWIN__ || __MINGW32__
};

#if defined __CYGWIN__ || defined __MINGW32__

inline ThreadLocals *myThreadLocals()
{   thread_local ThreadLocals mine;
    return reinterpret_cast<ThreadLocals *>(tls_load());
}

#else // __CYGWIN__ || __MINGW32__

// If I was certain that I had C++17 fully supported I would use
//   inline thread_local ThreadLocals myThreadLocals;
// here so I got just one instance of the structure. But until that is
// universally available I will just wrap the definition of the instance
// of the structure up within an inline function. This will guarantee that
// just one copy of it exists even though this header may be included by
// many compilation units. And with modern compilers there is amazingly
// little overhead.

inline ThreadLocals *myThreadLocals()
{   thread_local ThreadLocals mine;
    return &mine;
}

#endif // __CYGWIN__ || __MINGW32__

// The collection of reference declarations here in effect leave the
// plain names buffo_size and so on as aliases for the more elaborate
// recipies needed to access them, so the bulk of the source code
// can look clean and tidy. An ugly situation here is that I have to have
// two copies of declarations - one set to establish members of the structure
// and the other here to provide short-name access.

// The C++ standard explicitly says that it is undefined whether a reference
// uses storage. If on some platform refernces did use storage then perhaps
// if this header was icnluded from multiple source files one could end up
// with multiply defined items. By making the declarations here static
// I should avoid that.

#define thread_id          (myThreadLocals()->thread_id)
#define Xboffo_size        (myThreadLocals()->Xboffo_size)
#define Xboffop            (myThreadLocals()->Xboffop)
#define Xboffo             (myThreadLocals()->Xboffo)
#define fluid_values_size  (myThreadLocals()->fluid_values_size)
#define fluid_values_count (myThreadLocals()->fluid_values_count)
#define fluid_values       (myThreadLocals()->fluid_values)

#endif // CSL

// Timings I collected for very tight loops accessing thread-local
// values in various ways were as follows (on Windows 10):
//     simple non-thread-local case     1
//     inline code working via GS       1.5
//     use of TlsGetValue()             3     (ie CAUTIOUS)
//     use of C++11 thread_local       30 Cygwin, 15 Mingw


// I have two versions of the code here - one uses the proper Windows API
// calls. These do at least a bit of validity checking on their arguments
// and will generally involve an out-of-line call into the Windows libraries.
// The other expands what is intended to be just the same activity (sans
// a couple of checks) in such a way that it can be compiled in-line, thus
// saving a little.

// The key to all this is that Windows maintains a segment register (FS for
// 32-bit systems and GS for 64-bit ones) pointing to a vblock of memory
// specific to the current thread. The layout within this block is not very
// officially guaranteed, but has been stable for a long time and if it did
// change it is believed that MANY applications would suffer!

#if defined __CYGWIN__ || defined __MINGW32__
#define ON_WINDOWS 1
#if __SIZEOF_POINTER__ == 4
#define ON_WINDOWS_32 1
#endif
#endif // __CYGWIN__ || __MINGW32__

#ifdef ON_WINDOWS

// I do not want to include <windows.h> here because if I do so it
// defines various things that clash against some of my Cygwin code. So
// I will put in relevant declarations individually and manually.

#include <cinttypes>

// The declarations for TlsAlloc and TlsFree given here are intended to
// match what Windows will use, but without needing to include <windows.h>
// to provide all the more elaborate names for the types and qualifiers
// that are used.

extern uint32_t myTlsAlloc();
extern void myTlsFree(uint32_t);

// This class exists so that its constructor and destructor can manage
// allocation of a slot in the Windows vector of thread local values.

class TLS_slot_container
{
public:
    int32_t mine;
    TLS_slot_container()
    {   mine = myTlsAlloc();
    }
    ~TLS_slot_container()
    {   myTlsFree(mine);
    }
};

// On or before the first call of this the constructor for the
// TLS_slot_container will be activated and that will allocate a slot.
// These days I expect the C compiler to turn the implementation of this
// into little more that a load from a static location in memory. It may
// also have a test to see if the call is a first one so it can in that
// case do the initialization.
// Just one slot-number is needed for my entire program - the same value is
// used by every thread.

inline int get_my_TEB_slot()
{   static TLS_slot_container w;
    return w.mine;
}

#ifdef CAUTIOUS
// The CAUTIOUS option uses the Microsoft API to access thread-local slots,
// and so should be robust against potential changes in Windows.

extern void *myTlsGetValue(uint32_t);
extern void myTlsSetValue(uint32_t, void *);

inline void *tls_load()
{   return myTlsGetValue(get_my_TEB_slot());
}

inline void tls_store(void *v)
{   myTlsSetValue(get_my_TEB_slot(), v);
}

#else // CAUTIOUS
// The version is intended and expected to behave exactly like the version
// that calls the Microsoft-provided functions, except (1) it does not
// do even basic sanity checks on the slot-number saved via get_my_TAB_slot()
// and (b) it can expand into inline code that then runs faster that the
// official version even if it does just the same thing.

// I abstract away 32 vs 64-bit Windows issues here. The offsets used are from
// www.geoffchappell.com/studies/windows/win32/ntdll/structs/teb/index.htm
// which has repeated comments about the long term stability of the memory
// layout involved.

#ifdef ON_WINDOWS_32

inline void *read_via_segment_register(uint32_t n)
{   void *r;
    asm volatile
    (   "movl %%fs:(%1), %0"
        : "=r" (r)
        : "r" (n)
        :
    );
    return r;
}
inline void write_via_segment_register(uint32_t n, void *v)
{   asm volatile
    (   "movl %0, %%fs:(%1)"
        :
        : "r" (v), "r" (n)
        :
    );
}

#define basic_TLS_offset           0xe10
#define extended_TLS_offset        0xf94

#else

inline void *read_via_segment_register(uint32_t n)
{   void *r;
    asm volatile
    (   "movq %%gs:(%1), %0"
        : "=r" (r)
        : "r" (n)
        :
    );
    return r;
}
inline void write_via_segment_register(uint32_t n, void *v)
{   asm volatile
    (   "movq %0, %%gs:(%1)"
        :
        : "r" (v), "r" (n)
        :
    );
}

#define basic_TLS_offset           0x1480
#define extended_TLS_offset        0x1780

#endif // Windows 32 vs 64 bit

inline void *extended_tls_load()
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    return a[get_my_TEB_slot() - 64];
}

inline void extended_tls_store(void *v)
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    a[get_my_TEB_slot() - 64] = v;
}

inline void *tls_load()
{   if (get_my_TEB_slot() >= 64) return extended_tls_load();
    else return (void *)read_via_segment_register(
        basic_TLS_offset + sizeof(void *)*get_my_TEB_slot());
}

inline void tls_store(void *v)
{   if (get_my_TEB_slot() >= 64) return extended_tls_store(v);
    else write_via_segment_register(
        basic_TLS_offset + sizeof(void *)*get_my_TEB_slot(), v);
}

#endif // CAUTIOUS
#endif // ON_WINDOWS

#endif // header_thread_local_h

// end of thread_local.h


