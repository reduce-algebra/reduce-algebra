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

// $Id: eval4.cpp 6922 2025-01-01 11:18:24Z arthurcnorman $


#include "headers.h"

#ifdef WIN32
void* jitcompile(const char* bytes, size_t len, LispObject env, int nargs)
{   return nullptr;  // Not available on Windows (yet??)
}
#else // WIN32

#include <sys/mman.h>
#ifdef MACINTOSH
#include <pthread.h>
#include <libkern/OSCacheControl.h>
#endif // MACINTOSH

static const size_t jit_chunk_size = 1024*1024; // Megabyte chunks
static size_t jit_base = 0, jit_pointer = 0;
static uint8_t* jit_chunk = nullptr;

#ifdef MACINTOSH
#define MAP_FLAGS MAP_ANON | MAP_PRIVATE | MAP_JIT
#else // MACINTOSH
#define MAP_FLAGS MAP_ANON | MAP_PRIVATE
#endif // MACINTOSH

void jit_byte(int c)
{
// I will arrange some suitable space for putting the generated
// code. I allocate this in megabyte chunks. If I am about to run off
// the end of a chunk while writing a function to it I copy the partial
// bit of code to the start of a fresh chunk.
    if (jit_chunk==nullptr ||
        jit_pointer>=jit_chunk_size)
    {   uint8_t* newchunk = reinterpret_cast<uint8_t*>(mmap(
            NULL,
            jit_chunk_size,
            PROT_WRITE | PROT_READ | PROT_EXEC,
            MAP_FLAGS,
            -1,
            0));
        if (newchunk == MAP_FAILED)
            my_abort("unable to allocate JIT space");
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

void* jitcompile(const char* bytes, size_t len, LispObject env, int nargs)
{
    printf("Calling jitcompile on ");
    simple_print(basic_elt(env, 0));
    for (unsigned int i=0; static_cast<size_t>(i)<len; i++)
        printf("%3u:  %02x\n", i, bytes[i]&0xff);

#ifdef MACINTOSH
    pthread_jit_write_protect_np(0);
#endif // MACINTOSH

    jit_base = jit_pointer; // for a new function body

// I am NOT delivering a proper return value here so this is
// really a mess of a placeholder!
#if MACINTOSH
    jit_word32(0xd65f03c0); // "ret" instruction on aarch64
#else
    jit_word32(0xfa1e0ff3);                         // endbr64
    jit_byte(0x48); jit_byte(0x89); jit_byte(0xf0); // mov %rsi,%rax
    jit_byte(0xc3);                                 // ret
#endif

#ifdef MACINTOSH
    pthread_jit_write_protect_np(1);
    sys_icache_invalidate(jit_chunk, jit_chunk_size);
#endif // MACINTOSH

    return jit_chunk+jit_base;
}


#endif // WIN32

// end of jit.cpp
