// acnutil.h                               Copyright (C) 2026 Arthur Norman

/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

#ifndef __header_acnutil
#define __header_acnutil

// This is going to have any generic bits of helpfulness I would like
// to provide myself with.

#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>
#include <type_traits>
#include <utility>

// These tests see whether SSE4.2 or AVX are available and will be done
// during startup.

#if defined __x86_64__ && defined __GNUC__

[[gnu::used]] const inline bool avx_available =
   ([]()->bool
    {  __builtin_cpu_init();
       return __builtin_cpu_supports("avx");
    })();
[[gnu::used]] const inline bool sse4_available =
   ([]()->bool
    {  return __builtin_cpu_supports("sse4.2");
    })();

#endif // __x86_64__

// For parts of the code that multiplies "medium size" numbers I want
// to expand out some loops into inline code. I had started by doing that
// using the standard template-based compile-time loops, but I found
// that with some compilers that left in function calls where I had
// used lambda-expressions. So here I have support for loops that
// combined templates and constexpr and which seems to behave as I
// want it to.

// This is to provide me with compile-time "for loops" which I can
// write as
//    forloop<start, limit> ([&] (auto variableName)
//    {   BODY within which variableName is constexpr
//    });
//
// For instance
//    forloop<7,12> ([&] (auto i)
//    {   constexpr size_t ii = i;
//        std::cout << ii << "\n";
//    });
// prints the values from 7 to 11. The introduction of ii there is just
// to illustrate that the control variable is a constexpr.

// The syntax for use there is not a disaster but I provide a #define
// macro that some may fine more to their taste, used as
//    forconstexpr (i, 7, 12,
//    {   constexpr size_t ii = i;
//        std::cout << ii << "\n";
//    });

template <class T1, std::size_t V1, class T2, std::size_t V2>
[[gnu::always_inline]] inline auto add_integral_constants(
                                       std::integral_constant<T1,V1> t1,
                                       std::integral_constant<T2,V2> t2)
{   return std::integral_constant<std::size_t, t1()+t2()>{};
}

namespace acnutil
{

template<std::size_t start, std::size_t... inds, class F>
[[gnu::always_inline]] inline constexpr void loopInner(
    std::integer_sequence<std::size_t, inds...>, F&& f)
{   (f(add_integral_constants(std::integral_constant<std::size_t, start>{},
                              std::integral_constant<std::size_t, inds>{})),
       ...);
}

template<std::size_t start, std::size_t count, class F>
[[gnu::always_inline]] inline constexpr void forloop(F&& f)
{   acnutil::loopInner<start>(std::make_index_sequence<count-start>{},
                              std::forward<F>(f));
}

#define forconstexpr(_var, _init, _limit, _body) \
    forloop<_init, _limit> ([&] (auto _var) [[gnu::always_inline]] { _body }) 


// I find the extreme generality of the C++ <chrono> scheme rather
// heavy - so here I wrap it up to give me a simple function that
// reports microseconds used since this program was started. The
// length of the lines here with multiple instances of "::" illustrates
// what is involved!

// high_resolution_clock may be an alias for system_clock and that may
// sometimes not be monotonic. I believe I observe that oddity under WSL2,
// so using steady_clock seems safer,

// I have two overloads of microseconds(). Without arguments it returns
// time since the program started, with two it gives the time between
// a pair of results from now().

inline auto basetime = std::chrono::steady_clock::now();

[[gnu::used]] inline auto microseconds()
{   auto tt = std::chrono::steady_clock::now() - basetime;
    return std::chrono::duration_cast<std::chrono::microseconds>(tt).count();
}

[[gnu::used]] inline auto now()
{   return std::chrono::steady_clock::now();
}

[[gnu::used]] inline std::uint64_t microseconds(
    std::chrono::time_point<std::chrono::steady_clock> t1,
    std::chrono::time_point<std::chrono::steady_clock> t0)
{   return
        std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
}


// Given a string and an integer make a string that concatenates them,
// so that e.g. concat("sss", 123) will yield "sss123".

[[gnu::used]] inline std::string concat(std::string a, int n)
{   std::stringstream ss;
    ss << a << n;
    return ss.str();
}

} // end namespace

using acnutil::microseconds;
using acnutil::now;

#endif // __header_acnutil

// end of acnutil.h
