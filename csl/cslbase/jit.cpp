// jit.cpp                                      Copyright (C) 2025 Codemist

//
// Just-in-time compiler framework
//

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


#include "headers.h"

// Combinations of symbols that your C++ compiler may predefine
// to guide usage here:
//    __linux__   __x86_64__             PC Linux (Ubuntu)
//    __linux__   __aarch64__            Raspberry Pi
//    __CYGWIN__  __x86_64__             Windows/Cygwin
//    __WIN32__   __x86_64__             Windows/Native (mingw). Or __WIN64__
//    __APPLE__   __aarch64__            Macbook/ARM
//    __APPLE__   __x86_64__             Macbook/Intel
// These settings happen at least with gcc. 

#if defined __linux__
#define                     LINUX 1
#if   defined  __x86_64__
#define                     INTEL_LINUX 1
#elif defined __aarch64__
#define                     ARM64_LINUX 1
#else
#error                      Unknown Linux variant
#endif

#elif defined __APPLE__
#define                     APPLE_MACINTOSH 1
#if   defined  __x86_64__
#define                     INTEL_MACINTOSH 1
#elif defined __aarch64__
#define                     ARM64_MACINTOSH 1
#else
#error                      Unknown Apple variant
#endif

#elif defined __CYGWIN__
#define                     CYGWIN 1   // Only x86_64 version exists now

#elif defined __WIN32__
#define                     NATIVE_WINDOWS 1
#if   defined  __x86_64__
#define                     INTEL_WINDOWS 1
#elif defined __aarch64__
#define                     ARM64_WINDOWS 1
#else
#error                      Unknown Windows variant
#endif

#else
define                      UNKNOWN_SYSTEM 1
#endif


#if defined UNKNOWN_SYSTEM
void* jitcompile(const char* bytes, size_t len, LispObject env, int nargs)
{   return nullptr;  // Not available on Windows (yet??)
}
#else // UNKNOWN_SYSTEM


// At the start here I have a load of messting around because I need to
// have memory that can be written to at some times and executed from at
// others. Achieving this involves interaction with the operating system
// of of necessity there will be version for Linux, MacOS, Native Windows
// and Cygwin.

#if defined NATIVE_WINDOWS
#include <windows.h>
#elif defined APPLE_MACINTOSH
#include <sys/mman.h>
#define MAP_FLAGS MAP_ANON | MAP_PRIVATE | MAP_JIT
#include <pthread.h>
#include <libkern/OSCacheControl.h>
#elif defined LINUX || defined CYGWIN
#include <sys/mman.h>
#define MAP_FLAGS MAP_ANON | MAP_PRIVATE
#endif

static const size_t jit_chunk_size = 1024*1024; // Megabyte chunks
static size_t jit_base = 0, jit_pointer = 0;
static uint8_t* jit_chunk = nullptr;

void jit_byte(int c)
{
// I will arrange some suitable space for putting the generated
// code. I allocate this in megabyte chunks. If I am about to run off
// the end of a chunk while writing a function to it I copy the partial
// bit of code to the start of a fresh chunk.
    if (jit_chunk==nullptr ||
        jit_pointer>=jit_chunk_size)
    {   uint8_t* newchunk;
#ifdef NATIVE_WINDOWS
        newchunk = static_cast<uint8_t*>(
            VirtualAlloc(nullptr, jit_chunk_size, MEM_COMMIT, PAGE_READWRITE));
        if (newchunk == nullptr)
            my_abort("unable to allocate JIT space");
        if (jit_chunk != nullptr)
        {   DWORD oldprotection;
            my_assert(VirtualProtect(jit_chunk, jit_chunk_size,
                      PAGE_EXECUTE_READ, &oldprotection) != 0, "fix existing chunk");
            printf("protection was %04x\n", static_cast<unsigned int>(oldprotection));
        }
#else // NATIVE_WINDOWS
        newchunk = reinterpret_cast<uint8_t*>(mmap(
            NULL,
            jit_chunk_size,
            PROT_WRITE | PROT_READ | PROT_EXEC,
            MAP_FLAGS,
            -1,
            0));
        if (newchunk == MAP_FAILED)
            my_abort("unable to allocate JIT space");
#endif // NATIVE_WINDOWS
        memcpy(newchunk, jit_chunk+jit_base, jit_pointer-jit_base);
        jit_chunk = newchunk;
        jit_pointer -= jit_base;
        jit_base = 0;
    }
    jit_chunk[jit_pointer++] = c;
}

void jit_word16(uint16_t w)
{   jit_byte(w);
    jit_byte(w>>8);
}

void jit_word32(uint32_t w)
{   jit_byte(w);
    jit_byte(w>>8);
    jit_byte(w>>16);
    jit_byte(w>>24);
}

extern void plant(const char* bytes, size_t len, LispObject env, int nargs);

void* jitcompile(const char* bytes, size_t len, LispObject env, int nargs)
{
    printf("Calling jitcompile on ");
    simple_print(basic_elt(env, 0));
    for (unsigned int i=0; static_cast<size_t>(i)<len; i++)
        printf("%3u:  %02x\n", i, bytes[i]&0xff);

#if defined APPLE_MACINTOSH
    pthread_jit_write_protect_np(0);
#elif defined NATIVE_WINDOWS
    if (jit_chunk != nullptr)
    {   DWORD oldprotection;
        my_assert(VirtualProtect(jit_chunk, jit_chunk_size,
                  PAGE_READWRITE, &oldprotection) != 0, "make writable");
        printf("protection was %04x\n", static_cast<unsigned int>(oldprotection));
    }
#endif

    printf("Memory segment for generated code created...\n");
    fflush(stdout);
    jit_base = jit_pointer; // for a new function body
    plant(bytes, len, env, nargs);
    printf("Sample code inserted into memory...\n");
    fflush(stdout);

#if defined APPLE_MACINTOSH
    pthread_jit_write_protect_np(1);
    sys_icache_invalidate(jit_chunk, jit_chunk_size);
#elif defined NATIVE_WINDOWS
    {   DWORD oldprotection;
        my_assert(VirtualProtect(jit_chunk, jit_chunk_size,
                  PAGE_EXECUTE_READ, &oldprotection) != 0, "make executable");
        printf("protection was %04x\n", static_cast<unsigned int>(oldprotection));
    }
#endif
    printf("About to return executable segment...\n");
    fflush(stdout);
    return jit_chunk+jit_base;
}

void showasm(const char* which, const unsigned char* data)
{   printf("Argcount %s:", which);
#ifdef __aarch64__
// For aarch64 instructions are best viewed as 32-bit items.
    for (int i=0; i<24; i+=4)
    {   uint32_t w =
            data[i] |
            (data[i+1]<<8) |
            (data[i+2]<<16) |
            (data[i+3]<<24);
        printf(" %08x", w);
    }
#else // __aarch64__
// For other systems (well x86_64 is the only one at present) I will
// display a sequence of bytes.
    for (int i=0; i<24; i++)
        printf(" %02x", data[i]);
#endif // __aarch64__
    printf("\n");
}


// In the display for showasm I can overrun the instructions in some of
// the functions and the consequence is that after the end of asmtest0
// I will show data from asmtest1. That may look odd to start with!

LispObject Lshowasm(LispObject env)
{   printf("Show binary from my inline-written assembly code\n");
    showasm("0", reinterpret_cast<const unsigned char*>(CSLasmtest_0));
    showasm("1", reinterpret_cast<const unsigned char*>(CSLasmtest_1));
    showasm("2", reinterpret_cast<const unsigned char*>(CSLasmtest_2));
    showasm("3", reinterpret_cast<const unsigned char*>(CSLasmtest_3));
    showasm("4up", reinterpret_cast<const unsigned char*>(CSLasmtest_4up));
    return nil;
}

// Now I have the architecture-specific versions of the
// code to plant bytes or words into instruation space.

#if defined __aarch64__

#include "jit-aarch64.cpp"

#elif defined __x86_64__

#include "jit-x86-64.cpp"

#else
#error "Unknown architecture"
#endif


#endif // UNKNOWN_SYSTEM

// end of jit.cpp
