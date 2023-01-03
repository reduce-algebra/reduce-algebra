// winmutex.h                                   Copyright (C) 2023 Codemist

#ifndef header_winmutex_h
#define header_winmutex_h 1

/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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

// $Id: winmutex.h March 2022 arthurcnorman $


#include <mutex>
#include <cstdint>
#include <atomic>

// The class here is a wrapper for the standard C++ mutex - just supporting
// the most basic lock and unlock capabilities. The intent is that this
// can be compiled in-line into about a single atomic increment instruction
// and thus reduce costs when there is no contention.

#if !defined LIKELY && !defined UNLIKELY

#ifdef __has_cpp_attribute_likely
#define LIKELY [[likely]]
#else // __has_cpp_attribute_likely
#define LIKELY
#endif // __has_cpp_attribute_likely

#ifdef __has_cpp_attribute_unlikely
#define UNLIKELY [[unlikely]]
#else // __has_cpp_attribute_unlikely
#define UNLIKELY
#endif // __has_cpp_attribute_unlikely

#endif // LIKELY, UNLIKELY

class wrappedMutex
{
private:
    std::atomic<std::uintptr_t> counter;
    std::mutex m;
public:
    wrappedMutex()
    {   counter = 0;
        m.unlock();
    }
    void lock()
    {   if (counter.fetch_add(1) != 0) UNLIKELY m.lock();
    }
    void unlock()
    {   if (counter.fetch_sub(1) != 1) UNLIKELY m.unlock();
    }
};

// It appears that under Cygwin the us of std::mutex carries a significant
// burden even in the case that contention is very low, 

#ifdef __CYGWIN__
typedef wrappedMutex myMutex;
#else // __CYGWIN__
typedef std::mutex myMutex;
#endif // __CYGWIN__


#endif // header_winmutex_h

// end of winmutex.h
