// Bug in toom32 shown by script div.sh on may home machine as derived
//   from clprl.tst with CHECK_TIMES=1 to trap it.
// Unbalanced big multiply does not use threads
// Setting thresholds KARASTART and KARABIG


// Big Number arithmetic.                             A C Norman, 2019-2024

// To use this, go "#include "arithlib.hpp".

#ifndef __arithlib_hpp
#define __arithlib_hpp 1

// To do:
//    Write full documentation! [Meanwhile there is a reasonably extended
//     commentary included as comments here, and a file arithtest.cpp that
//     can accompany it and illustrate its use]
//    Re-work long division to approximate Karatsuba complexity.

/**************************************************************************
 * Copyright (C) 2019-2024, Codemist.                    A C Norman       *
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

// There are quite a lot of bignumber packages out there on the web,
// but none of them seemed to be such that I could readily use them
// for arithmetic within a Lisp at all easily, for instance because of
// the storage management arangements used.
//
// This code is for use as a header-only library, so just "#include" it
// to be able to use it. All the use of the word "inline" is so that if
// you #include this from several source files there will not be trouble when
// you link them together: you should still only end up with one copy of
// each function in memory. Note that until a few years ago the expectation
// was that tagging a function as "inline" was advice to the compiler to
// merge its definition into the body of functions that called it. When
// that is to be done one wants to put the function definition in a header
// file so that all compilation units gain access to it. If it was made
// "static" there would risk being a compiled copy included  along with
// every compilation uint, while if it was "extern" it could seem to be
// multiply defined. Use of "inline" resolves that, leaving just one
// copy in the eventual linked binary. I will demand C++17 style support for
// inline variables as well as functions.
//
// This code uses 64-bit digits and a 2s complement representation for
// negative numbers. This means it will work best on 64-bit platforms
// (which by now are by far the most important), and it provides bitwise
// logical operations (logand and logor) as well as arithmetic. It will work
// best where the C++ compiler supports a 128-bit integral type, but does not
// need that. It should work on 32-bit systems as well, although one should
// expect performance there to be lower.
//
// The code here tries to arrange that any operations that might overflow are
// done using unsigned types, because in C++ overflow in signed arithmetic
// yields undefined results - ie on some machines the values delivered could
// be quite unrelated to the desired ones. This means that I do plenty of
// arithmetic rather as
//     int c = (int)((unsigned)a + (unsigned)b);
// and I rely on the result being as would be seen with natural 2s complement
// working. From C++20 onwards the conversions will be guaranteed to behave
// as if everything is 2s complement. But note that a simple "a+b" still
// leads to undefined behaviour if performed in signed values, and
// optimising compilers can assume that and generate code that does not
// perform the way a naive old-fashioned reading of it would suggest.
//
// If "softfloat_h" is defined I will suppose that there is a type "float128"
// available and I will support conversions to and from that. In part because
// this type is not supported in any standard way I will be assuming that the
// version I use is as provided by the SoftFloat IEEE Floating-Point Arithmetic
// package released by John R. Hauser. That does everything in software so
// absolute speed may be modest, but it is nicely portable. For more
// information see http://www.jhauser.us/arithmetic/SoftFloat.html.
//
// I will provide two levels of access and abstraction. At the low level
// a big number is represented as and array of uint64_t digits along with
// a size_t value that indicates the number of digits in use. The most
// significant digit in any number lives in memory with type uint64_t but
// is treated as signed (ie int64_t) in the arithmetic. For the purposes
// of the bitwise operations (and, or, xor and not) negative values are
// processed as if they had an infinite number of 1 bits above their
// most significant stored digit.
// If a positive value has a top digit whose unsigned value has its top bit
// set then an additional zero digit is used ahead of that, and equivalently
// for negative values.
//
// Vectors to represent numbers are allocated using a function reserve()
// which takes an argument indicating how long the number might be. It will
// often be necessary to reserve memory in a conservative manner, ie to
// allocate more memory than will eventually prove to be needed.
// At the end of an arithmetic operation a reserved block of memory can be
// passed to abandon() when it is no longer required, or there can be a
// call to confirmSize() to establish the exact size that is to be retained.
// A variant call confirmSize_x() is used when the vector whose size is being
// confirmed is not the one that was most recently allocated: the intent
// there was that under some schemes discarding or shortening the most
// recently allocated item might be especially easy to implement well.
// confirmSize() returns a handle for the vector, not the vector itself.
// Depending on build options it is also possible that small integers will be
// represented almost directly: such cases will be referred to as fixnums.
// So for the benefit of higher levels of abstraction every number is stored
// using a "handle", where the handle can be tested to see it is holds the
// value of the number within itself as a fixnum or whether it is a pointer
// to a vector of digits. While the code here does not absolutely mandate it,
// the expectation is that all vectors will be allocated at addresses that are
// a multiple of sizeof(uint64_t) and that means that some low bits in a
// handle are available to tag fixnums.
//
// In addition to numbers I will generate strings (I have code to make a
// string representation of a number, with hex, decimal, octal and binary
// variants). Space for the string will be allocated using reserveString()
// and finalized using confirmSizeString(), with both of those indicating
// sizes in bytes. Note that when you reserve or confirm string size the
// length quoted is the number of characters that will be present excluding
// any header or termination markers - reserveString() will allow for the
// needs of suchlike.
//
// A higher level packaging represents numbers using a class Bignum. This
// has just one field which will hold a potentially encoded version of a
// pointer to a vector that is the number (ie a handle). When the handle
// identified a vector the first item in the vector will be a header word
// containing length information. That is followed by the uint64_t digits
// representing the numeric value. The representation of the header and the
// encoding of handles can be configured in one of several ways, these being
// intended to provide models of the implementation intended for different
// use cases.
//
// Overall the code has conditional compilation providing for 3 prototype
// arrangements. These are MALLOC, NEW and LISP. It is envisaged that some
// users of this code will need to modify it to allow it to interface with the
// rest of their software, and these three schemes give at least sketches of
// various possibilites. The short explanation is that MALLOC uses malloc()
// and free() for memory management and does not use fixnums, so that all
// numbers (however small) are stored as vectors. This is perhaps the simplest
// scheme, if not the highest performance. NEW exploits many more C++ features.
// Storage management uses "new" and "delete" at the lowest level, but the
// code keeps its own lists of previously used memory blocks in a manner that
// greatly reduces the call on C++ memory management work. This version stores
// handles that refer to vectors as even numbers and ones that are fixnums
// with their bottom bit set, so fixnums are 63 bits wide. The C++ class
// Bignum and a range of operator overloads lead to this being a simple
// version to use for casual C++ code, and it is the default version built.
// LISP is the version that originally motivated me to implement this. It has
// a subsidiary configuration option that allows for systems where garbage
// collection is or is not conservative. This could be a good starting point
// for a bignum system to be used as part of the run-time system for any
// language, not just Lisp. However the interface code here is liable to need
// detailed review and revision since it mediates between the data structures
// used here and whatever is present in the Lisp (or whatever!) that will
// use it. I initially developed and tested this using a Lisp called "vsl"
// and intend to migrate it for use in "csl". Both of these use low-bit
// tagging of data and the precise values for tag bits and their layout
// within header words has to be adhered to here, as has the Lisp's ideas
// about the way that header words are stored.
//
// Here is some more information about each scheme:
//
// MALLOC:
//   A bignum with n digits is held in a vector of length n+1, and the
//   "encoded pointer" to it is a native pointer to the second element.
//   If this pointer is p then the number of words (n) is kept at p[-1]
//   and the least significant digit of the number is at p[0]. reserve()
//   uses malloc() to obtain space. confirmSize() uses realloc() to trim
//   the allocated space, and abandon() maps onto use of free(). This
//   uses C rather than C++ memory management because it wants to use realloc
//   which is not supported in the tidy C++ world. Performance of the code
//   as a whole will be sensitive to the malloc/realloc/free implementation
//   on the platform that is in use. To allow for a user who wished to
//   customize allocation, all calls to the basic memory allocation primitives
//   are made indirectly so that alternative equivalents can be plugged in.
//   Strings and allocated using malloc() and returned as simple nul-terminated
//   C strings. They must be released using free() after use.
//
// NEW:
//   A bignum with n digits will be stored in a vector whose size is the
//   next power of 2 strictly larger than n. As with the MALLOC case
//   the numeric data starts one word into this block and the initial word
//   of the block contains a header of length information. Here the header
//   is split into two 32-bit parts. One contains the length of the number
//   as before (but note that in general that will not fill up the entire
//   memory block), the other contains log2(blockSize), ie it is a compact
//   indication of the size of the block. There will be free-chains for
//   blocks of size 2,4,8,... so that abandon() just pushes the released
//   memory onto one and reserve() can often merely retrieve a previously
//   used block. In most cases confirmSize just needs to write the actual
//   length of a number into the header word. When two large numbers are
//   subtracted the number of digits in the result may be much smaller than
//   the size of block that had to have been reserved. To allow for that sort
//   of situation confirmSize() reserves the right to notice cases where used
//   size in a block is much smaller than the capacity, and in such cases
//   allocate a fresh smaller block and copy information into it, allowing it
//   to abandon the overlarge chunk of memory.
//   The reference to the vector of digits is held using type intptr_t and
//   can be cast to obtain the address of the least significant digit of the
//   value. But so that this scheme as a whole provides better performance
//   for general users, small integer values will be handled specially. If
//   the "encoded pointer" has its bottom bit set than it represents a 63-bit
//   signed value. The intent here is that the class Bignum, by containing
//   just one integer-sized field, can be stored and passed around really
//   efficiently, and if in its use most arithmetic remains on values that
//   fit within 63 bits it will not do much storage allocation at all. If this
//   works well it should represent a reasonably convenient and tolerably
//   efficient C++ facility for general use.
//   Strings live in store allocated using "new char[nnn]" and are returned
//   as C style strings that must be disposed of using "delete". The use of
//   C rather than C++ style strings because I hope that makes storage
//   management interaction clearer.
//
// LISP:
//   The arrangements here are based on the arrangements I have in my VSL
//   and CSL Lisp implementations. I still hope that between the above options
//   and this one the code can be adapted reasonably easily. As before the
//   basic representation of a number with n digits is a vector of length
//   n+1, with the initial word containing a header. In VSL/CSL a header word
//   contains some tage bits identifying it as a header, then some type
//   bite that here will indicate that it is a header of a big number. Finally
//   it contains a length field. The exact bit-patterns and packing here will
//   be specific to the particular Lisp (obviously!). A reference to a big
//   number will be the address of the header word of this vector plus some
//   tag bits in the bottom 3 bits. This "low tagging" relies on all block
//   of memory being aligned to 8-byte boundaries (even on 32-bit platforms).
//   On a 32-bit system the header will only occupy the first 32-bits of the
//   initial 64-bit memory unit, and the second 32-bit region is spare and
//   would be best set to zero.
//   There are two expectations about memory management. The first is that
//   garbage collection has left a large block of contiguous memory within
//   which new material can be allocated linearly. Under this supposition the
//   most recently allocated block of memory can be shrunk or discarded by
//   simply resetting a heap-fringe pointer. The second is that it will
//   at least occasionally be desirable to perform linear scans of all memory.
//   To support that when a block that is not the most recently allocated one
//   is shrunk or discarded a header word is placed in the released space
//   leaving a valid but dummy Lisp item there.
//   Those issue motivate the distinction between confirmSize and
//   confirmSize_x. [Note that the implementation may not (yet) do all that
//   I intended in that respect!]
//   Usually calls to memory allocation primitives are made without any special
//   concern for garbage collector safety of other pointers, and so in its
//   current form this code insists on running in a context where the garbage
//   collector is conservative, so that for instance the untagged pointers to
//   raw vectors of digits are safe. 
//   In Lisp mode it is anticipated that as well as a tagged representation
//   of small integers that the generic arithemetic will need to support
//   floating point numbers (and possibly multiple widths of floating point
//   values, plus ratios and complex numbers) and so the dispatch on tagged
//   numbers needs to live at a higher level within the Lisp then just thise
//   code. Thus while the big-number functions here are set up so they can
//   return fixnum results and while there are entrypoints for performing
//   arithmetic between bignums and fixnums  (ie between uint64_t* and
//   int64_t values) it is the responsibility of somebody else to decide which
//   functions to call when.
//   Strings are allocated using reserveString() and finalized using
//   confirmSizeString. For Lisp purposes they will need to have a header
//   word containing the string length.
//
// It might be helpful if I provide my own thoughts about when you might decide
// to use this code and when you will probably not. Wikipedia lists rather
// a large number of arbitrary precision arithmetic packages on the web page
// en.wikipedia.org/wiki/List_of_arbitrary-precision_arithmetic_software.
// As well as free-stanidng libraries a range of programming languages feature
// big-number arithmetic as a standard feature. It may be fair to suggest
// that for use from C++ the most visible option is GMP with some users liking
// to use it via Boost. Given a view that GMP is the market leader I will
// set out some points comparing arithlib with it.
// First GMP is well established, it aims for top performance, it has fast
// algorithms for huge arithmetic as well as for sane-sized numbers. In
// contrast arithlib is new and neither well established nor truly heavily
// tested. It does not even try to provide algorithms that will only become
// useful for arithmetic on numbers that are many many thousands of digits
// (eg FFT-style multiplication). It can thus be expected to be generally
// slower than GMP.
// However potential advantages of arithlib are
// (1) It is subject to a permissive BSD license, while GMP is dual licensed
//     under LGPL3 or GPL2. For some users or some projects this may matter!
// (2) Rather than having assembly code versions for a wide but finite range
//     of particular hosts, arithlib follows the "Trust your Compiler" policy
//     and expects that a sufficiently modern C++ compiler will manage to
//     generate code close to the performance of all the hand-optimised
//     assembly code that GMP uses. This reduces the total size of the
//     package substantially and makes building/installing/using it especially
//     easy even when a packaged version is not instantly available for
//     your machine. However the author of this code does not trust
//     compilers unconditionally - testing has used g++-13 and up to date
//     versions of clang.
// (3) By being a header-only library, arithlib imposes a cost at program
//     build time as it all has to be processed by the compiler - but these
//     days compile-times are pretty short anyway. And by having all of
//     its souce code available when code that uses it is built there are
//     potential whole-program optimisations that can be made.
// (4) arithlib is coded in C++ not C, and this allows it to leverage features
//     of C++17. For instance it can rely on the random number generation
//     facilities that C++ provides rather than needing to implement its
//     own. There are places within it where template code leads to a neater
//     implementation, and the operator overloading scheme that various other
//     C++ arithmetic packages provide fits in especially naturally.
// (5) My initial motivation for creating arithlib was a need for a big
//     arithmetic package to form part of the run-time system of a language
//     implementation. arithlib was built with a view to keeping much of the
//     memory allocation and management somewhere else, probably supported
//     by garbage collection. I found it much harder to see how to arrange
//     that the garbage collector in the rest of my run-time system could
//     track the memory usage within GMP.
// (6) While arithlib is not a totally tiny body of code it is smaller and
//     simpler than GMP. When its capabilities cover what is needed and when
//     its speed is sufficient I would suggest that "small and tidy is good".
//
// A key use-case that arithlib is NOT set up to support is arithmetic on
// long but fixed precision numbers - this is liable to mean that it will
// not be the technlogy of choice for a range of cryptography applications!
// The code here has been tested and runs on both 32 and 64-bit machines,
// however its internal workings are almost all expressed in terms on the
// type "uint64_t". This may result in there being significant scope for
// better specialization for code to run on 32-bit targets.
//
// What about thread safety? Well the code should be thread-safe.
// with the C++ "NEW" option I provide several options and you need to
// configure one (at compile time, and by editing this file or adding
// overriding predefined symbols), choosing the one you like or that
// will run fastest on your platform. Search for "CONCURRENCY SUPPORT" to
// find the commentary.
//
// I have run some VERY SIMPLISTIC benchmark comparisons between this code
// and gmp. All that has been tested is the low-level code for multiplying
// a pair on N word unsigned integers to get a 2N word result.
// On x86_64 and compiling with "g++ -O3" I believe that this test suggests
// that up to around 100 words (ie 6400 bits, 2000 decimal digits) the speed
// ratio between gmp and arithlib is in the range 1 to 2 (on Ubuntu Linux or
// Windows 10 (64-bit)).
// Beyond that the use of "TOOM3" by gmp leads to it gradually picking
// up advantages, reaching about a factor somewhat over 3 at around 1500
// words (100000 bits, 30000 decimal digits).
// This benchmark only tests multiplication of equally sized numbers and
// its results will vary noticably across platforms, and so it is not liable
// to be representative of overall results including mixes of all the
// operations on mixed-size numbers, but at least it shows something!
// For large enough inputs I believe I see multiplication being about 4 times
// as costly on a 32-bit platform as on a 64-bit one, a result that is perhaps
// no cause for great astonishment!

// Those concerned with programming style may be minded to complain about the
// fairly large numbers of casts in this code. So here is an attempt to
// explain some major causes.
// First, in C++ signed arithmetic overflow is undefined behaviour. However I
// want to be able to tell when it would arise, and I want to be able to do
// a great deal of my big-number implementation using all 64-bits of a wide
// integer. Thus both overflow tests and a great deal of the inner arithmetic
// are done using unsigned aritmeric, but both when dealing with negative
// bignums and when interacting with the user I need to have signed integers.
// I frequently cast between signed an unsigned 64-bit values in these
// contexts. The code ASSUMES that arithmetic is twos complement. Note that
// from C++20 onwards this ceases to be an assumption and is guaranteed by
// the standard!
// Secondly in many cases I will represent a big number as an object whose
// sole data menber is of type std::uintptr_t. This will be interpreted as
// a value with its low bit or few bits as tag information and upper bits
// as either a pointer (to a vector of digits) or an immediate integer value.
// I am ASSUMING that one or more low bits in the representation of a pointer
// to an aligned item will be zero in the natural pointer, and that I can
// force information into them for tagging. Even though this is not entirely
// proper I feel that eg std::align() would not make sense if this was not
// going to work! Whatever the risks, using this sort of representation leads
// to many casts beween  std::uint64_t* and std::uintptr_t, and the
// unpacking of a signed value from the immediate integer case leads to
// further casts with signed integers, ie std::intptr_t.
// Finally I need at times to generate a bit-fiels using code such as
// (1<<n). If the literal "1" is not introduced using a wide enough type
// this can overflow. I might try (1LLU<<n) but I have no absolute guarantee
// that "LL" makes a 64-bit integer. I could use UINT64_C(1) and that is not
// too bad, but in many places I will in fact write the rather wordy but very
// explicit (1ULL<<n).

// While debugging this (or indeed anything else) it is sometimes
// helpful to embed information about filename and line number in
// trace ouput. The following supports eg
//    std::cout << ARITH_WHERE "Reached this point with x=" << x << "\n";

#define ARITHLIB_STRINGIFY(x) #x
#define ARITHLIB_TOSTRING(x) ARITHLIB_STRINGIFY(x)
#define ARITH_WHERE " " __FILE__ ":" ARITHLIB_TOSTRING(__LINE__) " "

// I provide a default configuration, but by predefining one of the
// symbols allow other versions to be built.

#if !defined MALLOC && !defined NEW && !defined LISP
// If no explicit options have been set I will building using memory
// allocation via C++ "new".

#define NEW           1

#endif // default the allocation scheme

#ifndef __cpp_inline_variables
#error "Arithlib.hpp needs __cpp_inline_variables (ie C++17 or above)"
#endif // inline_variables

// A useful C++17 feature.... with a fallback to a GNU-specific
// way of achieving the same through use of C++11 annotations. And a final
// fall back to just not worrying.

#ifndef __has_cpp_attribute
#define __has_cpp_attribute(name) 0
#endif // has_attribute

#ifndef MAYBE_UNUSED
#if __has_cpp_attribute(maybe_unused)
#define MAYBE_UNUSED [[maybe_unused]]
#elif defined __GNUC__
#define MAYBE_UNUSED [[gnu::unused]]
#else // GNUC
#define MAYBE_UNUSED
#endif // GNUC
#endif // MAYBE_UNUSED

#ifndef LIKELY
#if __has_cpp_attribute(likely)
#define LIKELY [[likely]]
#else // __has_cpp_attribute(likely)
#define LIKELY
#endif // __has_cpp_attribute(likely)
#endif // LIKELY

#ifndef UNLIKELY
#if __has_cpp_attribute(unlikely)
#define UNLIKELY [[unlikely]]
#else // __has_cpp_attribute(unlikely)
#define UNLIKELY
#endif // __has_cpp_attribute(unlikely)
#endif // UNLIKELY

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <cfloat>
#include <cctype>
#include <cinttypes>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <random>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <utility>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <type_traits>

// acnutil.h                               Copyright (C) 2024 Arthur Norman

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

// The synytax for use there is not a disaster but I provide a #define
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

namespace acnutil {

template<std::size_t start, std::size_t... inds, class F>
[[gnu::always_inline]] inline constexpr void loopInner(
    std::integer_sequence<std::size_t, inds...>, F&& f)
{   (f(add_integral_constants(std::integral_constant<std::size_t, start>{},
                              std::integral_constant<std::size_t, inds>{})),
       ...);
}

};

template<std::size_t start, std::size_t count, class F>
[[gnu::always_inline]] inline constexpr void forloop(F&& f)
{   acnutil::loopInner<start>(std::make_index_sequence<count-start>{},
                              std::forward<F>(f));
}

#define forconstexpr(_var, _init, _limit, _body) \
    forloop<_init, _limit> ([&] (auto _var) [[gnu::always_inline]] { _body }) 


// Using the high resolution clock is in many respects easy, but it is
// also pretty clumsy because the function names are so long. So here is
// a compact protocol for my own use:
//   auto t0 = now(); DO SOMETHING; auto t1 = now();
//   ... microseconds(t1, t0) ...

inline auto now()
{   return std::chrono::high_resolution_clock::now();
}

inline std::uint64_t microseconds(
    std::chrono::time_point<std::chrono::high_resolution_clock> t1,
    std::chrono::time_point<std::chrono::high_resolution_clock> t0)
{   return
        std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
}

// Given a string and an integer make a string that concatena tes them,
// so that e.g. concat("sss", 123) will yield "sss123".

inline std::string concat(std::string a, int n)
{   std::stringstream ss;
    ss << a << n;
    return ss.str();
}

#endif // __header_acnutil

// end of acnutil.h
// lvector.h                                  Copyright (C) A C Norman 2024

// This is intended to behave much as a C++ "T*" pointer except that it
// performs bound checking if DEBUG is defined at compile-time.

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

// $Id$

#ifndef __header_lvector_h
#define __header_lvector_h 1

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// BEWARE:                                                         //
// Every thread must start by calling ThreadLocal::initialize().   //
// This applies only on Windows where some special handling of     //
// thread-local values is applied here for performance reasons.    //
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// Overview
//
// There are some classes:
//   stkvector<T>   a vector of n items of type T for stack/static allocation.
//   vecpointer<T>  a pointer to one of the above.

// This is something like what I want...
//== template <typename T>
//== using stkvector<T> = T[];   used in file of block scope definitions.
//== using vecpointer<T> = T*;   pointer to one of these.
// however that can not let me establish locally defined vectors
// of dynamic size, and I want to support declarations such as
//         stkvector<int> myLocalArray(std::atoi(argv[1]));
// to set up a block scope vector where the size is not known at
// compile time. Also following
//         vecpointer<int> p = new int[100];
// this would mean I needed to discard the space explicitly.
// Ordinary code uses
//   T* p = new T[20]; ... ; delete[] p;
// here it is necessary to write
//   vecpointer<T> p = new T[20]; ... ; p.discard();
// because overriding "delete[]" suitably is not possible.
//
// I want sizeof(vecpointer<T>) == sizeof(T*). The size of the stkvector
// object is less important: in raw C++ after "int vec[N];" sizeof(vec)
// will be N*sizeof(int) but rather than supporting that I will provide
// a "size()" method to retrieve that information. And I will view
// stkvector as only suitable for use with a compilation unit or block
// scope declaration. "new stkvector" is not to be allowed.
//    ...
// stkvector<T> will need to support
//    creation via a declaration at file or block scope.
//    reclamation of all its space at block exit.
//    convert to vecpointer<T>
//    convert to vecpointer<const T> 
//    a function size() [because sizeof on it will not work]
// T must not be a "const" type.

// vecpointer<T> will need to support
//    a default constuctor that makes an uninitialized pointer.
//    a copy constructor.
//    constructor from nullptr.
//    constructor from a T*.
//    constructor from a T* but with a length specifier.
//    constructors from intptr_t and uint64_t*
//    construction from a SizedPointer.
//    constructor from an stkvector<T>.
//    a "discard" function for deleting its contents
//    operator*             indirection
//    operator[]            subscripting
//    operator=
//    operator+(integer)
//    operator-(integer)
//    operator-(vecpointer<T>)
//    operator+= and operator-=
//    operator++ and operator--  (pre and post versions of each)
//    operator== and operator!= to compare against a nullptr or
//                              another vecpointer<T>
//    casts into T* and const T* and intptr_t
//
// setSize(vecpointer<T>, n) sets a bound (only enforced with the checked
// version.
//
// I will require sizeof(vecpointer<T>) == sizeof(T*). I am going to
// assume all pointer types have the same size which C++ may not
// guarantee by all general-purpose versions arrange.

// In non-DEBUG mode I want the use of vecpointer<T> to map onto the
// use of T* so there is no overhead.
//
// In DEBUG mode when an vecpointer will be a pointer to a heap allocated
// vecpointerInfo strucure that has fields
//     T* data;        reference to underlying data
//     size_t limit;   length of the underlying data in units of T
//     size_t offset;  offset within data that is toi be used   
// Any operation that would leave offset>=limit, offset<0 or would
// attempt to access data outside those bounds will raise an exception.
// If the LPointer<T> is created directly from a T* then if no limit is
// given then SIZE_MAX is used.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class vecpointer;

#ifndef DEBUG

template <typename T>
class vecpointer
{
private:
    T* data;
public:

//    a default constuctor
    vecpointer()
    {   data = nullptr;
    }

//    a copy constructor
    vecpointer(const vecpointer<T>& a)
    {   data = a.data;
    }

//    constructor from nullptr
    vecpointer(std::nullptr_t a)
    {   data = nullptr;
    }

//    constructor from a T*
    template <typename S>
    vecpointer(S* a)
    {   data = reinterpret_cast<T*>(a);
    }

//    constructor from a T* but with a length specifier
    vecpointer(T* a, size_t n)
    {   data = a;
    }

//    constructor from a intptr_t
    vecpointer(std::intptr_t a)
    {   data = reinterpret_cast<T*>(a);
    }

//    setsize() - a no-op in this case.
    void setsize(size_t n)
    {}

//    discard()     for deleting its contents
    void discard()
    {   delete [] data;
        data = nullptr;
    }

//    operator*             indirection
    T& operator*()
    {   return *data;
    }
    T operator*() const
    {   return *data;
    }

//    operator[]            subscripting
    T& operator[](size_t n)
    {   return data[n];
    }
    T operator[](size_t n) const
    {   return data[n];
    }

//    operator=
    vecpointer<T>& operator=(const vecpointer<T> a)
    {   data = a.data;
        return *this;
    }

//    operator+(integer)
    vecpointer<T> operator+(std::ptrdiff_t n)
    {   return vecpointer<T>(data + n);
    }

//    operator-(integer)
    vecpointer<T> operator-(std::ptrdiff_t n)
    {   return vecpointer<T>(data - n);
    }

//    operator-(vecpointer<T>)
    std::ptrdiff_t operator-(vecpointer<T> a)
    {   return data - (T*)a;
    }

//    operator+= and operator-=
    vecpointer<T>& operator+=(std::ptrdiff_t n)
    {   data += n;
        return *this;
    }
    vecpointer<T>& operator-=(std::ptrdiff_t n)
    {   data -= n;
        return *this;
    }

//    operator++ and operator--  (pre and post versions of each)
    vecpointer<T>& operator++()
    {   ++data;
        return *this;
    }
    vecpointer<T>& operator--()
    {   --data;
        return *this;
    }
    vecpointer<T> operator++(int)
    {   return vecpointer<T>(data++);
    }
    vecpointer<T> operator--(int)
    {   return vecpointer<T>(data--);
    }

//    operator== and operator!= to compare against a nullptr or
//                              another vecpointer<T>
    bool operator==(std::nullptr_t a)
    {   return data == nullptr;
    }
    bool operator!=(std::nullptr_t a)
    {   return data != nullptr;
    }
    bool operator==(const vecpointer<T> a)
    {   return data == a.data;
    }
    bool operator!=(const vecpointer<T> a)
    {   return data != a.data;
    }

//    casts into T*
    operator T*()
    {   return data;
    }

//    casts into intptr_t
    operator std::intptr_t()
    {   return reinterpret_cast<std::intptr_t>(data);
    }

    operator void*()
    {   return static_cast<void*>(data);
    }

    operator const void*()
    {   return static_cast<const void*>(data);
    }

    operator vecpointer<const T>()
    {   return vecpointer<const T>(data);
    }

    void show()
    {   if (data == nullptr) std::cout << "empty pointer\n";
        else std::cout << "non-debug pointer "
                       << this << "/" << *this << " holds " << data << "\n";
    }
    void show(const char* s)
    {   std::cout << s << ": ";
        show();
    }
    friend std::ostream & operator << (std::ostream &out, const vecpointer& a)
    {   out << a.data;
        return out;
    }
};

template <typename T>
inline vecpointer<T> setSize(vecpointer<T> v, std::size_t n)
{   return v;
}

template <typename T>
inline vecpointer<T> setSize(T* v, std::size_t n)
{   return v;
}

#else // DEBUG 

inline void lvector_assert(bool b)
{   if (b) return;
    std::cerr << "\n+++ Access outside vector bound +++\n";
    std::abort();
}

inline void lvector_assert(bool b, const char* msg)
{   if (b) return;
    std::cerr << "\n+++ " << msg << " +++\n";
    std::abort();
}

template <typename T>
class vecpointerData
{
// This is a vector "T* data" with length "limit" where the reference into
// it is "offset" units from the start. So at all times we must have
// 0 <= offset < limit.
public:
    T* data;
    size_t limit;
    size_t offset;

// normal constructor
    vecpointerData(T* d, size_t l, size_t o)
    {   data = d;
        limit = l;
        offset = o;
    }

// null-pointer constructor.
    vecpointerData(std::nullptr_t d, size_t l, size_t o)
    {   data = nullptr;
        limit = l;
        offset = o;
    }
    friend std::ostream & operator << (std::ostream &out, const vecpointerData& a)
    {   out << a.data;
        return out;
    }
};

template <typename T>
class vecpointer
{
public:
    vecpointerData<T>* data;

//    a default constuctor
    vecpointer()
    {   data = new vecpointerData<T>(nullptr, 0, 0);
    }

    ~vecpointer()
    {   if (data != nullptr)
        {   delete data;
            data = nullptr;
        }
    }

//    a copy constructor
    vecpointer(const vecpointer<T>& a)
    {   data = new vecpointerData<T>(a.data->data, a.data->limit, a.data->offset);
    }

//    constructor from nullptr
    vecpointer(std::nullptr_t a)
    {   data = new vecpointerData<T>(nullptr, 0, 0);
    }

//    constructor from a T*
    template <typename S>
    vecpointer(S* a)
    {   data = new vecpointerData<T>(reinterpret_cast<T*>(a), SIZE_MAX, 0);
    }

//    constructor from a T* but with a length specifier
    vecpointer(T* a, size_t n)
    {   data = new vecpointerData<T>(a, n, 0);
    }

//    constructor from a T* but with a length specifier and an offset
    vecpointer(T* a, size_t n, size_t o)
    {   data = new vecpointerData<T>(a, n, o);
    }

//    constructor from a uint64_t*
    vecpointer(std::uint64_t* a)
    {   data = new vecpointerData((T*)a, SIZE_MAX, 0);
    }

//    constructor from a intptr_t
    vecpointer(std::intptr_t a)
    {   data = new vecpointerData<T>(reinterpret_cast<T*>(a), SIZE_MAX, 0);
    }

//    setsize() - may be useful in debug mode.
    void setsize(size_t n)
    {   data->limit = n;
    }

//    discard()     for deleting its contents
    void discard()
    {   delete [] data;
        data = nullptr;
    }

//    operator*             indirection
    T& operator*()
    {   return data->data[data->offset];
    }
    T operator*() const
    {   return data->data[data->offset];
    }

//    operator[]            subscripting
    T& operator[](size_t n)
    {   size_t nn = n + data->offset;
        lvector_assert(nn < data->limit);
        return data->data[nn];
    }
    T operator[](size_t n) const
    {   size_t nn = n + data->offset;
        lvector_assert(nn < data->limit);
        return data->data[nn];
    }

//    operator=
    vecpointer<T>& operator=(const vecpointer<T> a)
    {   data->data = a.data->data;
        data->limit = a.data->limit;
        data->offset = a.data->offset;
        return *this;
    }

//    operator+(integer)
    vecpointer<T> operator+(std::ptrdiff_t n)
    {   size_t nn = n + data->offset;
        lvector_assert(nn < data->limit);
        return vecpointer<T>(data->data, data->limit, nn);
    }

//    operator-(integer)
    vecpointer<T> operator-(std::ptrdiff_t n)
    {   size_t nn = data->offset - n;
        lvector_assert(nn < data->limit);
        return vecpointer<T>(data->data, data->limit, nn);
    }

//    operator-(vecpointer<T>)
    std::ptrdiff_t operator-(vecpointer<T> a)
    {   lvector_assert(data->data == a.data->data,
                       "illegal difference between vectors");
        return (data->offset - a.data->offset);
    }

//    operator+= and operator-=
    vecpointer<T>& operator+=(std::ptrdiff_t n)
    {   data->offset += n;
        lvector_assert(data->offset < data->limit);
        return *this;
    }
    vecpointer<T>& operator-=(std::ptrdiff_t n)
    {   data->offset -= n;
        lvector_assert(data->offset < data->limit);
        return *this;
    }

//    operator++ and operator--  (pre and post versions of each)
    vecpointer<T>& operator++()
    {   ++data->offset;
        lvector_assert(data->offset < data->limit);
        return *this;
    }
    vecpointer<T>& operator--()
    {   --data->offset;
        lvector_assert(data->offset < data->limit);
        return *this;
    }
    vecpointer<T> operator++(int)
    {   lvector_assert(data->offset+1 < data->limit);
        return vecpointer<T>(data->data, data->limit, data->offset++);
    }
    vecpointer<T> operator--(int)
    {   lvector_assert(data->offset >= 1);
        return vecpointer<T>(data->data, data->limit, data->offset--);
    }

//    operator== and operator!= to compare against a nullptr or
//                              another vecpointer<T>
    bool operator==(std::nullptr_t a)
    {   return data->data == nullptr;
    }
    bool operator!=(std::nullptr_t a)
    {   return data->data != nullptr;
    }
    bool operator==(const vecpointer<T> a)
    {   return data->data == a.data->data &&
               data->offset == a.data->offset;
    }
    bool operator!=(const vecpointer<T> a)
    {   return data->data != a.data->data ||
               data->offset != a.data->offset;
    }

//    casts into T*
    operator T*()
    {   return &data->data[data->offset];
    }

//    casts into intptr_t
    operator std::intptr_t()
    {   return reinterpret_cast<std::intptr_t>(&data->data[data->offset]);
    }

    operator void*()
    {   return static_cast<void*>(&data->data[data->offset]);
    }

    operator const void*()
    {   return static_cast<const void*>(&data->data[data->offset]);
    }

    operator vecpointer<const T>()
    {   return vecpointer<const T>(data->data, data->limit, data->offset);
    }

// show() is really just for debugging.
    void show()
    {   if (data == nullptr) std::cout << "empty pointer\n";
        else
        {   std::cout << "debug pointer " << this << "/" << *this
                      << " holds " << data << "\n";
            std::cout << data->data << " " << data->limit
                      << " " << data->offset << "\n";
        }
    }
    void show(const char* s)
    {   std::cout << s << ": ";
        show();
    }
    friend std::ostream & operator << (std::ostream &out, const vecpointer& a)
    {   out << a.data;
        return out;
    }
};

template <typename T>
inline vecpointer<T> setSize(vecpointer<T> v, std::size_t n)
{   std::size_t o = v.data->offset;
    std::size_t l = v.data->limit;
    lvector_assert(o+n <= l);
    v.data->limit = o+n;
    return v;
}


#endif // DEBUG


//=========================================================================

// Here I want to be able to allocate a vector such that it is
// automatically discarded when it goes out of scope, but I want
// as little overhead as I can manage. I could use std::unique_ptr
// to get the "auto-delete" functionality but I am not fully confident
// that the C++ storage management overheads will be truly small. What
// I do here is I allocate a vector and maintain a record of its size
// and a fringe. If an allocation request will fit I just allocate at the
// fringe. If not I will new "new" to grab a fresh vector that is at least
// twice the size of the existing one and also big enough for the request.
// I must not delete the existing chunk since data within it is still in
// use. So all allocated vectors are places in a "recycleBin" that
// arranges deletion when the program terminates. Because expansion
// allocated new blocks twice the size of a previous one even in the
// worst case will be that these orphaned vectors only take up as much
// space as the current active chunk. This could be viewed as a factor
// of 2 waste - I consider it acceptable.
// When a local vector is done with the fringe gets decreased by its
// size (so I need to have recorded its size). The case fringe==0 when
// deletion is attempted corresponds to discarding a block of memory in
// one of the vectors that are in the recycle bin, and I do not need to
// so anything.
// I allocate in bytes in an "char[]" array so that I only use one pool
// of memory across all types of object allocated, but then there may
// still need to be one pool per thread. I only support allocation
// aligned up to std::max_align_t, so anybody with over-aligned data should
// beware.

// The following structure contains everything a thread needs to manage
// its allocation. So a thread_local instance of it will cope with
// everything I do.

#include <vector>

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

// $Id$

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
#ifndef NO_THREADS
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
std::vector <ZeroArgFunction*> initVec;

inline void initialize()
{   for (auto fn:initVec) (fn)();
}

   
#endif // MICROSOFT special version.

#endif // NO_THREADS



//###########################################

#ifdef NO_THREADS

// The versions in this section are dummies in that they do nor make
// things thead_local at all. There are in case these macros are used in
// a library or a version of a program than can never need to be thread
// safe. They also perhaps serve as tidy explanations of the overall
// behaviour of all these macros.

inline void initialize()
{
}

// These versions are all about having a pointer to an object of
// the given type - which will often be a struct or class.

#define DECLARE_THREAD_LOCAL(T, name) \
   extern T* name;

#define DEFINE_THREAD_LOCAL(T, name) \
   T TLSTRUCT_##name;                \
   T* name = &TLSTRUCT_##name;
   
#define DEFINE_STATIC_THREAD_LOCAL(T, name) \
   static T TLSTRUCT_##name;                \
   static T* name = &TLSTRUCT_##name;
   
#define DEFINE_INLINE_THREAD_LOCAL(T, name) \
   inline T TLSTRUCT_##name;                \
   inline T* name = &TLSTRUCT_##name;
   
// The "_POD" versions are for when the payload is "Plain Old Data" and
// in particular it is a value that can be stored in a slot that is
// an intptr_t or a void*. The definitions include an initialiser.

#define DECLARE_THREAD_LOCAL_POD(T, name) \
   extern T name;

#define DEFINE_THREAD_LOCAL_POD(T, name, init) \
   T name = init;
   
#define DEFINE_STATIC_THREAD_LOCAL_POD(T, name, init) \
   static T name = init;
   
#define DEFINE_INLINE_THREAD_LOCAL_POD(T, name, init) \
   inline T name = init;
   
#elif (defined __CYGWIN__ || defined __MINGW32__) && !defined USE_CXX_TLS

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
   



#else

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
   
#endif





// The following relate to a CSL experiment that at present is stalled.

#ifdef NO_THREADS
#define maxThreads   1U
#define THREADID     UNUSED_NAME const uintptr_t threadId = 0
#define THREADARG    /* NOTHING */
#define THREADFORMAL /* NOTHING */
#define OPTTHREAD    /* NOTHING */
#else // NO_THREADS
#ifdef DEBUG
#define maxThreads   2U
#else // DEBUG
#define maxThreads  64U
#endif // DEBUG
#define TL_genuineThreadId  50
DECLARE_THREAD_LOCAL(uintptr_t, genuineThreadId);
#define THREADID UNUSED_NAME const uintptr_t threadId = genuineThreadId
#define THREADARG threadId,
#define THREADFORMAL uintptr_t threadId,
#define OPTTHREAD (threadId)
#endif // NO_THREADS


} // end of namespace ThreadLocal

#endif // header_threadloc_h

// end of threadloc.h

class allocationInfoStruct
{
public:
    char* chunk;
    size_t currentChunkSize;
    size_t fringe;
    std::vector<char*> listOfPointers;
    void discard(char* v) { listOfPointers.push_back(v); }
    ~allocationInfoStruct()
    {   for (auto v:listOfPointers) delete [] v;
    }
};

constexpr inline int TL_allocationInfoPtr=63;
DEFINE_INLINE_THREAD_LOCAL(allocationInfoStruct, allocationInfoPtr)

template <typename T>
class stkvector
{
private:
    size_t oldFringe;
public:
    T* data;
#ifdef DEBUG
    size_t limit;
#endif // DEBUG

// default constructor
    stkvector()
    {   data = nullptr;
#ifdef DEBUG
        limit = 0;
#endif // DEBUG
    }

// Create an stkvector of size n.
    stkvector(size_t n)
    {
#ifdef DEBUG
        limit = n;
#endif // DEBUG
        size_t nbytes = n*sizeof(T);
// Ensure that the block I allocate will have size that is a multiple of
// max_align even if T would be happy with less allignment - so that the
// next allocation will be properly aligned whatever it is.
        if constexpr (alignof(T) < alignof(std::max_align_t))
            nbytes = (nbytes+alignof(std::max_align_t)-1) & -alignof(std::max_align_t);
// If the current chunk does not have anough space I will allocate another
// bigger one.
        if (allocationInfoPtr->fringe+nbytes > allocationInfoPtr->currentChunkSize)
        {   size_t newChunkSize =
                std::max(nbytes, 2*allocationInfoPtr->currentChunkSize);
            allocationInfoPtr->chunk = new char[newChunkSize];
            allocationInfoPtr->currentChunkSize = newChunkSize;
// Arrange that the chunk will eventually be deleted... typically when the
// program terminates but in a thread context when the thread terminates.
            allocationInfoPtr->discard(allocationInfoPtr->chunk);
            allocationInfoPtr->fringe = 0;
        }
        data = reinterpret_cast<T*>(
            allocationInfoPtr->chunk+allocationInfoPtr->fringe);
        oldFringe = allocationInfoPtr->fringe;
        allocationInfoPtr->fringe = oldFringe + nbytes;
#ifdef DEBUG
        std::memset(data, 0x99, nbytes);
        limit = n;
#endif // DEBUG
    }

// new (not permitted)
    void* operator new(std::size_t n) = delete;

// delete (not permitted)
    void operator delete(void *) = delete;
    void operator delete[](void *) = delete;

// destructor
    ~stkvector()
    {
// Note that fringe could be zero if this vector is in an "old"
// chunk. fringe is just used within the current chunk.
        if (allocationInfoPtr->fringe != 0)
            allocationInfoPtr->fringe = oldFringe;
    }

// convert to vecpointer
    operator vecpointer<T>()
    {
#ifdef DEBUG
        return vecpointer<T>(data, limit, 0);
#else // DEBUG
        return vecpointer<T>(data);
#endif // DEBUG
    }
    operator vecpointer<const T>()
    {
#ifdef DEBUG
        return vecpointer<const T>(data, limit, 0);
#else // DEBUG
        return vecpointer<const T>(data);
#endif // DEBUG
    }

    vecpointer<T> operator+(size_t n)
    {
#ifdef DEBUG
        return vecpointer<T>(data, limit, n);
#else // DEBUG
        return vecpointer<T>(data+n);
#endif // DEBUG
    }

// convert to T*
    operator T*()
    {   return data;
    }
    operator const T*()
    {   return data;
    }
    operator void*()
    {   return static_cast<void*>(data);
    }

//    operator[]            subscripting
    T& operator[](size_t n)
    {
#ifdef DEBUG
        lvector_assert(n < limit);
#endif // DEBUG
        return data[n];
    }
    T operator[](size_t n) const
    {
#ifdef DEBUG
        lvector_assert(n < limit);
#endif // DEBUG
        return data[n];
    }

//    operator*            subscripting
    T& operator*()
    {
#ifdef DEBUG
        lvector_assert(limit != 0);
#endif // DEBUG
        return data[0];
    }
    T operator*() const
    {
#ifdef DEBUG
        lvector_assert(limit != 0);
#endif // DEBUG
        return data[0];
    }

// retport size
    size_t size()
    {
#ifdef DEBUG
        return limit;
#else // DEBUG
        return SIZE_MAX;
#endif // DEBUG
    }
    friend std::ostream & operator << (std::ostream &out, const stkvector& a)
    {   out << a.data;
        return out;
    }
};

#endif // __header_lvector_h

// end of lvector.h

namespace arithlib_implementation
{

using Digit = std::uint64_t;
using SignedDigit = std::int64_t;

#ifdef DEBUG
using DigitPtr = vecpointer<Digit>;
using ConstDigitPtr = vecpointer<const Digit>;
#else // DEBUG
using DigitPtr = Digit*;
using ConstDigitPtr = const Digit*;
#endif // DEBUG


inline const char* version_string =
    "$Id$";

inline int version()
{   static int seq = -1;
// This extracts the subversion revision number from version_string.
    if (seq <= 0)
    {   const char *s = version_string;   // "$Id: filename verno ..."
        while (*s++ != ' ');              // " filename verno ..."
        while (*s++ != ' ');              // " verno ..."
        seq = std::atoi(s+1);
    }
    return seq;
}

// I will provide a single thread-local pointer that
// can be accessed fast even on Windows. All value that are to be
// thread_local within this library can (eventually) be migrated to live in
// a chunk of memory referenced by this.
//
// The data involved might/should be
// (1) Information related to the worker threads for Karatsuba multiplication.
// (2) Information about the modulus used with modular arithmetic.
// Note that the allocation of memory when that is done within this library
// rather that outside it may also need to be thread local if the library is
// used from a threaded application, but that does not use the special
// treatment indicated just here.

struct MyArithlibData
{
    int someThreadLocalInteger;
    std::vector<int> someThreadLocalVector;
}; 

#define TL_arithlibData 48
DEFINE_INLINE_THREAD_LOCAL(MyArithlibData, arithlibData);

// Now the fields within arithlibData can be accessed as in
// arithlibData->someThreadLocalInteger and this is expected to
// be reasonably cheap (even on Windows!).


// A scheme "arithlib_assert" lets me write in my own code to print the
// diagnostics. To use this version you must include arithlib.hpp after
// and other header files that define assert or abort macros.

// I implement things here using #define because I want to exploit
// __FILE__ and __LINE__ to report where issues arose.

#define STRINGIFY1(x) #x
#define STRINGIFY(x) STRINGIFY1(x)

// arithlib_abort() mainly exists so I can set a breakpoint on it! Setting one
// on the system abort() function sometimes does not give me as much help
// as I might have hoped on at least some platforms, while a break-point
// on abort() does what I expect. But also the version I have here explains
// where it was called from nicely. The location gets passed in as a string
// and in a multi-file multi-thread world that could be "interesting", and
// so I will have mutex protection for the failure message (getting two
// aborts at once would be horrid, and I will be happy if ONE of the reports
// come out neatly!). The function diagnostic_muxex returns a reference
// to a mutex that can be used to protect things, and there will be just
// one of if. It also sets its argument to a reference to a const char*
// pointer that will be used for transmitting the location information.

inline std::mutex my_diagnostic_mutex;
inline const char* my_diagnostic_location;

inline std::mutex& diagnostic_mutex(const char ***where)
{   *where = &my_diagnostic_location;
    return my_diagnostic_mutex;
}

[[noreturn]] inline void abort1(const char *msg)
{
// The call to diagnostic_mutex here is just to retrieve the location of the
// const char* variable that holds the location. I am already within
// the scope of a mutex.
    const char** where;
    static_cast<void>(diagnostic_mutex(&where));
    std::cout << std::endl << "About to abort at " << *where << ": "
              << msg << std::endl;
    std::abort();
}

[[noreturn]] inline void abort1()
{
    const char** where;
    static_cast<void>(diagnostic_mutex(&where));
    std::cout << std::endl << "About to abort at " << *where << std::endl;
    std::abort();
}

// This variation on an abort() macro established a lock_guard so that only
// one part of the code can be aborting at any one time, and sets up
// information about the file and line where trouble arose. It could cope
// with arbitrary overloads of abort1() and the fact that the location
// information is not passed as an extra argument to abort1() is because
// of limitations in __VA_ARGS__ in portable code until C++2a.

// because arithlib_abort is a macro it does not live in any particular
// namespace

#define arithlib_abort(...)                                                \
    {   const char** where;                                                \
        std::lock_guard<std::mutex> lock(                                  \
            arithlib_implementation::diagnostic_mutex(&where));            \
        *where = __FILE__ " line " STRINGIFY(__LINE__);                    \
        arithlib_implementation::abort1(__VA_ARGS__);                      \
    }

// The following variable (well constant) enabled "assert" checking. The
// effect might be a (probably rather modest) slowdown. However the predefined
// macro __OPTIMIZE__ will be set up if any g++ optimizations are in force, so
// here I only activate assertions in the case of compilation subject to
// "-O0" which will often be associated with "-g".
//
// However the user can override this by predefining FORCE_DEBUG_ARITH to
// encourage debugging of FORCE_NO_DEBUG_ARITH to discourage it.

// Note I make the flags static not inline in case compilation flags for
// different files in a multi-file project differ.

#if (defined __OPTIMIZE__ && !defined FORCE_DEBUG_ARITH) || \
    defined FORCE_NO_DEBUG_ARITH
static const bool debug_arith = false;
#else  // __OPTIMIZE__
static const bool debug_arith = true;
#endif // __OPTIMIZE__

template <typename F>
inline void assert1(bool ok, const char* why,
                    F&& action, const char* location)
{
// Use this as in:
//     arithlib_assert(predicate, [&]{...});
// where the "..." is an arbitrary sequence of actions to be taken
// if the assertion fails. The action will typically be to display
// extra information about what went wrong.
    if (debug_arith && !ok)
    {   action();
        const char** where;
        std::lock_guard<std::mutex> lock(diagnostic_mutex(&where));
        *where = location;
        abort1();
    }
}

inline void assert1
(bool ok, const char* why, const char* location)
{
// For simple use where a customised message is not required:
//     arithlib_assert(predicate);
    if (debug_arith && !ok)
    {   const char** where;
        std::lock_guard<std::mutex> lock(diagnostic_mutex(&where));
        *where = location;
        abort1(why);
    }
}

#define arithlib_assert(...)                                 \
    arithlib_implementation::assert1(__VA_ARGS__,            \
                      "arithlib_assert(" #__VA_ARGS__ ")",   \
                      __FILE__ " line " STRINGIFY(__LINE__))


// At times during development it is useful to be able to send messages
// to a log file.... This should not be used in final production code
// but still may help while debugging.

// Making this "inline" avoids warning messages if it is not
// used. So even though this may somewhat waste space when it is used,
// I like this option.

inline void logprintf(const char* fmt, ...)
{
// I use a fixed name for the log file. This is another respect in which
// this has to be seen as code only suitable for temporary use. I use static
// variables that are local to this function so that even if the header is
// included from multiple source files there will not be multiple-definition
// clashes, and since this is just for diagnostics I am not worried about
// any costs that this imposes.
    static std::FILE* logfile = nullptr;
    const char** where;
    std::lock_guard<std::mutex> lock(diagnostic_mutex(&where));
    if (logfile == nullptr) logfile = std::fopen("arith.log", "w");
    std::va_list args;
    va_start(args, fmt);
    std::vfprintf(logfile, fmt, args);
    va_end(args);
    std::fflush(logfile);
}

inline void traceprintf(const char* fmt, ...)
{   const char** where;
    std::lock_guard<std::mutex> lock(diagnostic_mutex(&where));
    std::va_list args;
    va_start(args, fmt);
    std::vprintf(fmt, args);
    va_end(args);
    std::fflush(stdout);
}

// The C++ rules about shifts are not always very comfortable, in particular
// right shifts on signed values may or may not propagate the sign bit
// and a left shift on signed values might cause trouble in overflow cases.
// So here are versions that should behave consistently across all
// architectures. Well it is probable that from C++20 onwards the language
// specification will arrange that right shifts on arithmetic types
// propagate the sign in the way that I want, and it is also liable to be
// the case that g++ and clang on all the computers that interest me do things
// the "obvious way" already, so the code here is something of an exercise
// in pedantry.

inline std::int32_t ASR(std::int32_t a, SignedDigit n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(std::int32_t))) n=0;
    std::uint32_t r = static_cast<std::uint32_t>(a) >> n;
    std::uint32_t signbit = static_cast<std::uint32_t>(a) >>
                            (8*sizeof(std::uint32_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(std::uint32_t) - n));
    return static_cast<std::int32_t>(r);
}

inline SignedDigit ASR(SignedDigit a, SignedDigit n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(SignedDigit))) n=0;
    Digit r = static_cast<Digit>(a) >> n;
    Digit signbit = static_cast<Digit>(a) >> (8*sizeof(
                                Digit)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(Digit) - n));
    return static_cast<SignedDigit>(r);
}

inline Digit ASR(Digit a, SignedDigit n)
{   return ASR(static_cast<SignedDigit>(a), n);
}

// The behaviour of left shifts on negative (signed) values seems to be
// labelled as undefined in C/C++, so any time I am going to do a left shift
// I need to work in an unsigned type. Well at some stage in the future it
// may be that C++ will insist that signed integers are handled in 2s
// complement form and shifts on them behave "as naively expected" but at
// present that can not be relied upon.

// In the comparisons I case the sizeof value to an int so that I can compare
// it against the signed amount n.

inline std::int32_t ASL(std::int32_t a, SignedDigit n)
{   if (n < 0 || n>=8*static_cast<int>(sizeof(std::uint32_t))) n = 0;
    return static_cast<std::int32_t>(static_cast<std::uint32_t>(a) << n);
}

inline SignedDigit ASL(SignedDigit a, SignedDigit n)
{   if (n < 0 || n>=8*static_cast<int>(sizeof(Digit))) n = 0;
    return static_cast<SignedDigit>(static_cast<Digit>(a) << n);
}

//=========================================================================
//=========================================================================
// I want to make C++ output using the "<<" operator on an ostream cope
// with big numbers. Doing so makes their use much smoother. The particular
// aspect of this addresses here is the provision of an IO manipulator
// called "std::bin" that sets for binary display of bignums (bit not of
// other integer types).
//=========================================================================
//=========================================================================

struct radix
{
public:
// I would like setting hex or oct or dec to disable this, but at present
// I do not know how to do that. So I will arrange that binary output is
// only generated if none of those flags are set, because I can clear
// them here. Then when I restore one of them I disable the test for binary.
// I will arrange that if nobody has ever asked for binary they do not get it,
// just so I feel safe.
    static void set_binary_output(std::ios_base& s, bool state = true)
    {   flag(s) = state ? 1 : 0;
        s.unsetf(std::ios_base::dec);
        s.unsetf(std::ios_base::oct);
        s.unsetf(std::ios_base::hex);
    }
    static bool is_binary_output(std::ios_base& s)
    {   return flag(s) != 0;
    }
private:
    static long& flag(std::ios_base& s)
    {   static int n = std::ios_base::xalloc();
        return s.iword(n);
    }
};

} // temporary end of namespace arithlib

// I want a new io manipulator "std::bin" to select binary mode output.
// This will be used much as std::oct, std::dec and std::hex.

namespace std
{   inline std::ostream& bin(std::ostream& os)
    {   arithlib_implementation::radix::set_binary_output(os);
        return os;
    }
}



namespace arithlib_implementation
{

// Declare a number of functions that might usefully be used elsewhere.

inline std::uint64_t* reserve(std::size_t n);
inline std::intptr_t confirmSize(std::uint64_t* p, std::size_t n,
                                 std::size_t final);
inline std::intptr_t confirmSize_x(std::uint64_t* p, std::size_t n,
                                   std::size_t final);
inline void abandon(std::uint64_t* p);
inline void abandon(std::intptr_t h);

#if defined LISP
typedef std::intptr_t string_handle;
#else // LISP
typedef char* string_handle;
#endif // LISP

inline string_handle confirmSizeString(char* p, std::size_t n,
                                       std::size_t final);
inline void abandonString(string_handle);

inline std::intptr_t vectorToHandle(std::uint64_t* p);
inline std::uint64_t* vectorOfHandle(std::intptr_t n);
inline std::size_t numberSize(std::uint64_t* p);
inline void setNumberSize(std::uint64_t* p, std::size_t n);

inline bool fitsIntoFixnum(SignedDigit n);
inline std::intptr_t intToHandle(SignedDigit n);
constexpr inline SignedDigit intOfHandle(std::intptr_t n);

inline std::intptr_t stringToBignum(const char* s);
inline std::intptr_t intToBignum(SignedDigit n);
inline std::intptr_t unsignedIntToBignum(Digit n);
inline std::intptr_t int128ToBignum(SignedDigit high, Digit low);
inline std::intptr_t unsignedInt128ToBignum(Digit high,
                                            Digit low);
inline std::intptr_t roundDoubleToInt(double d);
inline std::intptr_t truncDoubleToInt(double d);
inline std::intptr_t floorDoubleToInt(double d);
inline std::intptr_t ceilingDoubleToInt(double d);
#ifdef softfloat_h
inline std::intptr_t roundFloat128ToInt(float128_t d);
inline std::intptr_t truncFloat128ToInt(float128_t d);
inline std::intptr_t floorFloat128ToInt(float128_t d);
inline std::intptr_t ceilingFloat128ToInt(float128_t d);
#endif // softfloat_h
inline std::intptr_t uniformPositive(std::size_t n);
inline std::intptr_t uniformSigned(std::size_t n);
inline std::intptr_t uniformUpto(std::intptr_t a);
inline std::intptr_t randomUptoBits(std::size_t bits);
inline std::intptr_t fudgeDistribution(std::intptr_t, int);

#if defined MALLOC

//=========================================================================
//=========================================================================
// The MALLOC option is perhaps the simplest! It uses C style
// malloc/realloc and free functions and the vector if turned into a
// handle by just casting it to an intptr_t value.
//=========================================================================
//=========================================================================


// The following are provided so that a user can update malloc_function,
// realloc_function and free_function to refer to their own choice of
// allocation technology. Well it is a bit uglier than that! If you compile
// using C++17 then the function pointers here are per_thread across every
// compilation unit and things behave "as you might expect". If you have an
// earlier C++ standard in play than each compilation unit gets its own static
// set of variables that can be used to divert memory allocation, and hence
// each compilation unit that includes this header is liable to need to reset
// them all.
// I view the ability to replace the allocation functions as somewhat
// specialist and to be used by people who will have the skill to modify this
// code as necessary, so this slight oddity does not worry me.

typedef void* malloc_t(size_t n);
typedef void* realloc_t(void* , std::size_t);
typedef void free_t(void* );

inline malloc_t * malloc_function = std::malloc;
inline realloc_t* realloc_function = std::realloc;
inline free_t   * free_function   = std::free;

inline std::uint64_t* reserve(std::size_t n)
{   std::uint64_t* r = reinterpret_cast<std::uint64_t*>(
        (*malloc_function)((n+1)*sizeof(Digit)));
    return &r[1];
}

inline std::intptr_t confirmSize(std::uint64_t* p, std::size_t n,
                                 std::size_t final)
{   p = reinterpret_cast<std::uint64_t*>(
        (*realloc_function)((void* )&p[-1],
                            (final_n+1)*sizeof(Digit)));
    p[0] = final_n;
    return vectorToHandle(&p[1]);
}

// In this model confirmSize_x() is just the same as confirmSize().

inline std::intptr_t confirmSize_x(std::uint64_t* p, std::size_t n,
                                   std::size_t final)
{   confirmSize(p, n, final);
}

inline void abandon(std::uint64_t* p)
{   (*free_function)((void* )&p[-1]);
}

// Note that I allocate space for the string data plus a NUL terminating byte.

inline char* reserveString(std::size_t n)
{   char* r = reinterpret_cast<char*>((*malloc_function)(n+1));
    return r;
}

// When I confirm the size of a string all I do is to write a NUL byte
// to terminate it. I expect the code to have reserved an amount of memory
// that is not much longer than the amount that I will need, so using
// realloc to shrink things to the exact size that is filled would not
// be a good bargain.

inline char* confirmSizeString(char* p, std::size_t n, std::size_t final)
{   r[final] = 0;
    return r;
}

inline void abandonString(char* s)
{   (*free_function)(s);
}

// In the C/malloc model I will represent a number by the intptr_t style
// integer that is obtained from a pointer to the first digit of the bignum.
// Note that converting to and fro between intptr_t and pointers risks
// ending up with C++ undefined behaviour.

inline std::intptr_t vectorToHandle(std::uint64_t* p)
{   return reinterpret_cast<std::intptr_t>(p);
}

inline std::uint64_t* vectorOfHandle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t*>(n);
}

inline std::size_t numberSize(std::uint64_t* p)
{   return p[-1];
}

inline void setNumberSize(std::uint64_t* p, std::size_t n)
{   p[-1] = n;
}

// When I use Bignums that are allocated using malloc() and operated on
// via C++ overloaded operators I often need to copy the data. However when
// memory management uses garbage collection I can allow multiple references
// to the same object and so copying is not needed as much. I have two
// copying functions. One only copies if the system is using MALLOC or
// NEW (but leaves data sharable on systems with garbage collection) while
// the other unconditionally copies.

inline std::intptr_t alwaysCopyBignum(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::intptr_t pp)
{   if (storedAsFixnum(pp)) return pp;
    std::uint64_t* p = vectorOfHandle(pp);
    std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

#elif defined NEW

//=========================================================================
//=========================================================================
// The NEW code is intended to be a reasonably sensible implementation for
// use of this code free-standing within C++. Memory is allocated in units
// whose size is a power of 2, and I keep track of memory that I have used
// and discarded so that I do not need to go back to the system-provided
// allocator too often.
//=========================================================================
//=========================================================================


inline unsigned int logNextPowerOf2(std::size_t n);

// There is a serious issue here as regards thread safety.
//
// As things stand if you use C++ memory allocation the local allocation
// and reallocation here is not thread safe. The result could be a disaster
// if multiple threads used big-numbers via the C++ type Bignum. Note that
// if you do not have "NEW" defined but instead use MALLOC or LISP you are
// safe.

// CONCURRENCY SUPPORT:
// I provide three options, and the selection as to which is used
// can be made by predefining a symbol.
//
// ARITHLIB_MUTEX. Use a mutex to protect memory allocation. One hope
//                 is that in situations where there is low contention the
//                 overhead will be small, and so this is the default.
// ARITHLIB_THREAD_LOCAL. Have a separate memory pool for use by each thread.
//                 This can use more memory than a scheme that uses shared
//                 allocation.
// ARITHLIB_NO_THREADS. Assume that no concurrent use of arithlib will
//                 arise and so no extra complication or overhead is needed.
//                 I do not make this the default because I can imagine
//                 people extending a program to use threads and then not
//                 looking here!
// Note that even with ARITHLIB_NO_THREADS I will use threads to speed
// up huge multiplication. The issue here is if the user calling functions
// from here is multi-threaded...
//
// I looked into having an ARITHLIB_LOCK_FREE to use compare-and-swap
// operations to maintain the freestore pool, but support via gcc on x86_64
// is uncertain (in part because not all variants on x86_64 CPUs implement
// the CMPXCHG16B instruction (though soon the ones that do not will count as
// museum pieces), and also because reports on the performance impact
// do not see quite clear-cut. I also see various unspecific comments about
// patents, but I have not followed them up.
// I could fairly happily imagine replacing the discard() code with a lock
// free "push" operation, which is simple to implement and does not suffer
// from the "ABA" issue. allocate() seems to be harder to implement and
// especially harder to implement in a way that will give reliably high
// performance across all platforms while avoiding machine depemdent
// components and especially in-line assembly code.

// If no options has been pre-defined I will default to ARITHLIB_MUTEX
#if !defined ARITHLIB_MUTEX &&        \
    !defined ARITHLIB_THREAD_LOCAL && \
    !defined ARITHLIB_NO_THREADS
#define ARITHLIB_MUTEX 1
#endif // set default thread policy

// Attempts to select more that one option at once get detected and moaned
// about.

#if (defined ARITHLIB_MUTEX && defined ARITHLIB_THREAD_LOCAL) ||      \
    (defined ARITHLIB_THREAD_LOCAL && defined ARITHLIB_NO_THREADS) || \
    (defined ARITHLIB_NO_THREADS && defined ARITHLIB_MUTEX)
#error Only one thread-support policy can be selected.
#endif // Some thread policy

#ifdef ARITHLIB_MUTEX
inline std::mutex& freechain_mutex()
{   static std::mutex m;
    return m;
}
#endif // ARITHLIB_MUTEX

typedef std::uint64_t* FreehainTable_t[64];

#ifdef ARITHLIB_THREAD_LOCAL
inline thread_local FreehainTable_t freechainTable;
#else // ARITHLIB_THREAD_LOCAL
#ifdef __cpp_inline_variables
class freechainTable
{   static inline FreehainTable_t freechainTableVar;
public:
    static FreehainTable_t& get()
    {   return freechainTableVar;
    }
};
#else // __cpp_inline_variables
class freechainTable
{
public:
    static FreehainTable_t& get()
    {   static FreehainTable_t freechainTableVar;
        return freechainTableVar;
    }
};
#endif // __cpp_inline_variables
#endif // ARITHLIB_THREAD_LOCAL

// In this case the header word at r[-1] is treated as a pair of 32-bit
// values. One indicates the size of the memory block as allocated, The
// other the number of words actually in use.
// In this model the use of a 32-bit number-length limits things so that
// the largest valid number will take up around 32Gbytes. That is because
// the size can be up to 4G (ie unsigned 32-bits) and that count is in
// terms of 8 bit digits. That does not feel like a worrying restriction
// to me!

inline uint32_t& bitSize(uint64_t* p)
{   return reinterpret_cast<std::uint32_t*>(&p[-1])[0];
}

inline std::size_t numberSize(std::uint64_t* p)
{   return reinterpret_cast<std::uint32_t*>(&p[-1])[1];
}

inline void setNumberSize(std::uint64_t* p, size_t n)
{   reinterpret_cast<std::uint32_t*>(&p[-1])[1] = static_cast<uint32_t>(n);
}
class Freechains
{
private:
// The following obscure line ensures that when I make an instance
// of Freechains it forces the standard streams into existence. Having
// that initilization happening early helps a LITTLE bit to reassure me
// that the standard streams should still be alive during the destructor
// for this class.
    std::ios_base::Init forceIOStreamsInitialization;

public:
    Freechains()
    {   for (int i=0; i<64; i++) (freechainTable::get())[i] = nullptr;
    }

    ~Freechains()
    {   for (std::size_t i=0; i<64; i++)
        {   std::uint64_t* f = (freechainTable::get())[i];
// Here I am assumung that uint64_t is at least as wide as uintptr_t.
// I think that will in reality always be the case but that the C++ standard
// will not guarantee it!
            while (f != nullptr)
            {   std::uint64_t w = f[1];
                delete [] f;
                f = reinterpret_cast<std::uint64_t*>(w);
            }
            (freechainTable::get())[i] = nullptr;
        }
    }

    static std::uint64_t* allocate(std::size_t n)
    {
// Finding the number of bits in n is achieved by counting the leading
// zeros in the representation of n, and on many platforms an intrinsic
// function will compile this into a single machine code instruction.
        int bits = logNextPowerOf2(n);
        std::uint64_t* r;
#if defined ARITHLIB_THREAD_LOCAL || ARITHLIB_NO_THREADS
        r = (freechainTable::get())[bits];
        if (r != nullptr)
            (freechainTable::get())[bits] =
                reinterpret_cast<std::uint64_t*>(r[1]);
#elif defined ARITHLIB_MUTEX
        {
            std::lock_guard<std::mutex> lock(freechain_mutex());
            r = (freechainTable::get())[bits];
            if (r != nullptr)
                (freechainTable::get())[bits] =
                    reinterpret_cast<std::uint64_t*>(r[1]);
        }
#else // ARITHLIB_MUTEX
#error Internal inconsistency in arithlib.hpp: memory allocation strategy.
#endif // ARITHLIB_MUTEX
// If no memory had been found on the freechain I need to allocate some
// more.
        if (r == nullptr)
        {   r = new std::uint64_t[(static_cast<std::size_t>(1))<<bits];
            if (r == nullptr) arithlib_abort("Run out of memory");
        }
// Just the first 32-bits of the header word record the block capacity.
// The casts here look (and indeed are) ugly, but when I store data into
// memory as a 32-bit value that is how I will read it later on, and the
// messy notation here does not correspond to complicated computation.
// The second 32-bit word in the header will be used to store the number
// of words actually used in the bignum.
        bitSize(r+1) = bits;
        return r;
    }

// When I abandon a memory block I will push it onto a relevant free chain.

    static void abandon(std::uint64_t* p)
    {   int bits = bitSize(p+1);
#ifdef ARITHLIB_ATOMIC
        lockfreePush(p, freechainTable::get(), bits);
#else // ARITHLIB_ATOMIC
#ifdef ARITHLIB_MUTEX
        std::lock_guard<std::mutex> lock(freechain_mutex());
#endif // ARITHLIB_MUTEX
        p[1] = reinterpret_cast<std::uint64_t>(freechainTable::get()[bits]);
        (freechainTable::get())[bits] = p;
#endif // ARITHLIB_ATOMIC
    }

};

#ifdef ARITHLIB_THREAD_LOCAL
inline thread_local Freechains freechain;
#else // ARITHLIB_THREAD_LOCAL
#ifdef __cpp_inline_variables
class freechains
{   static inline Freechains freechainsVar;
public:
    static Freechains& get()
    {   return freechainsVar;
    }
};
#else // __cpp_inline_variables
class freechains
{
public:
    static Freechains& get()
    {   static Freechains freechainsVar;
        return freechainsVar;
    }
};
#endif // __cpp_inline_variables
#endif // ARITHLIB_THREAD_LOCAL

inline std::uint64_t* reserve(std::size_t n)
{   return &(freechains::get().allocate(n+1))[1];
}

inline std::intptr_t confirmSize(std::uint64_t* p, std::size_t n,
                                 std::size_t final)
{
    if (final == 1 && fitsIntoFixnum(static_cast<SignedDigit>(p[0])))
    {   std::intptr_t r = intToHandle(static_cast<SignedDigit>(p[0]));
        freechains::get().abandon(&p[-1]);
        return r;
    }
// I compare the final size with the capacity and if it is a LOT smaller
// I allocate a new smaller block and copy the data across.
// That situation can most plausibly arise when two similar-values big
// numbers are subtracted.
    int bits = bitSize(p);
    std::size_t capacity = (static_cast<std::size_t>(1))<<bits;
    if (capacity > 4*final)
    {   std::uint64_t* w =
            freechains::get().allocate(
                (static_cast<std::size_t>(1))<<logNextPowerOf2(final+1));
        std::memcpy(&w[1], p, final*sizeof(std::uint64_t));
        freechains::get().abandon(&p[-1]);
        p = &w[1];
    }
    setNumberSize(p, final);
    return vectorToHandle(p);
}

inline std::intptr_t confirmSize_x(std::uint64_t* p, std::size_t n,
                                   std::size_t final)
{   return confirmSize(p, n, final);
}

inline std::intptr_t vectorToHandle(std::uint64_t* p)
{   return reinterpret_cast<std::intptr_t>(p);
}

inline std::uint64_t* vectorOfHandle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t*>(n);
}

inline bool storedAsFixnum(std::intptr_t a)
{   return (a & 1) != 0;
}

constexpr inline SignedDigit intOfHandle(std::intptr_t a)
{   return (static_cast<SignedDigit>(a) & ~1LL)/2;
}

// This function should only ever be called in situations where the
// arithmetic indicated will not overflow.

inline std::intptr_t intToHandle(SignedDigit n)
{   return static_cast<std::intptr_t>(2*n + 1);
}

// The following two lines are slighly delicate in that INTPTR_MIN and _MAX
// may not have the low tag bits to be proper fixnums. But if I implement
// intOfHandle so that it ignores tag bits that will be OK.

inline const SignedDigit MIN_FIXNUM = intOfHandle(INTPTR_MIN);
inline const SignedDigit MAX_FIXNUM = intOfHandle(INTPTR_MAX);

inline bool fitsIntoFixnum(SignedDigit a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t* p)
{   freechains::get().abandon(&p[-1]);
}

inline void abandon(std::intptr_t p)
{   if (!storedAsFixnum(p) && p!=0)
    {   std::uint64_t* pp = vectorOfHandle(p);
        freechains::get().abandon(&pp[-1]);
    }
}

inline char* reserveString(std::size_t n)
{   return new char[n+1];
}

inline char* confirmSizeString(char* p, std::size_t n, std::size_t final)
{   p[final] = 0;
    return p;
}

inline void abandonString(char* s)
{   delete [] s;
}

// In the NEW case I will want to make all operations cope with both
// shorter integers (up to 63 bits) stored as the "handle", or genuine
// big numbers where the handle yields a pointer to a vector of 64-bit
// words. I do this by having a dispatch scheme that can activate code
// for each of the mixtures of representations.
//

// Dispatch as between mixed bignum and fixnum representations using some
// template stuff and classes.

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1));
    else return OP::op(vectorOfHandle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, SignedDigit n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t* n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

// I am going to arrange that if the C++ compiler optimised it at all
// it will prefer operations on small numbers.

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (storedAsFixnum(a1))
    {   LIKELY
        if (storedAsFixnum(a2))
            LIKELY
            return OP::op(intOfHandle(a1), intOfHandle(a2));
        else return OP::op(intOfHandle(a1), vectorOfHandle(a2));
    }
    else
    {   if (storedAsFixnum(a2))
            LIKELY
            return OP::op(vectorOfHandle(a1), intOfHandle(a2));
        else return OP::op(vectorOfHandle(a1), vectorOfHandle(a2));
    }
}

inline std::intptr_t alwaysCopyBignum(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::intptr_t pp)
{   if (storedAsFixnum(pp)) return pp;
    std::uint64_t* p = vectorOfHandle(pp);
    std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

#elif defined LISP

//=========================================================================
//=========================================================================
// The LISP code is for incorporation in VSL or CSL
//=========================================================================
//=========================================================================

// The code in this region needs to be adapted to work with whatever
// language implementation you are going to use the arithmetic library from.
// In my case this will be one of two fairly closely related Lisp systems,
// where VSL is a "small" one and CSL is larger (and more complicated).
// The code here is left visible and available since it may provide some
// sort of model for anybody wanting to use this code in their own
// project.

#if defined CSL

// The code here can only make sense in the context of the CSL sources,
// and it is assumed that all the relevant CSL header files have already
// been #included.

inline std::uint64_t* reserve(std::size_t n)
{   LispObject a = get_basic_vector(TAG_NUMBERS,
                                    TYPE_NEW_BIGNUM,
                                    n*sizeof(Digit)+8);
    return reinterpret_cast<std::uint64_t*>(a + 8 - TAG_NUMBERS);
}

inline std::intptr_t confirmSize(std::uint64_t* p, std::size_t n,
                                 std::size_t final)
{   if (final == 1 && fitsIntoFixnum(static_cast<SignedDigit>(p[0])))
    {   std::intptr_t r = intToHandle(static_cast<SignedDigit>(p[0]));
// The bignum that I am abandoning was given a header word when it was
// first allocated, so it is in good order here.
        return r;
    }
// Note that pack_hdrlength() takes its argument measured in units of
// 32-bit words. That is because the way the length field is packed into
// an object header supported just that resolution (and special treatment is
// given to halfword, byte and bit-vectors to allow for their finer grain).
// The length also includes the size of a header-word, and on 32-bit platforms
// it has to allow for padding the data to allow the array of 64-bit digits
// to be properly aligned in memory. I do not use setNumberSize() here
// because the proper abstraction here belongs in a different world!
    ((LispObject* )&p[-1])[0] = make_new_bighdr(final+1);
// If I am on a 32-bit system the data for a bignum is 8 bit aligned and
// that leaves a 4-byte gap after the header. In such a case I will write
// in a zero just to keep memory tidy.
    if (sizeof(LispObject) == 4) ((LispObject* )&p[-1])[1] = 0;
// Here I could maybe reset fringe down by (final-n) if the current number
// is the most recently allocated item. Think about that later! However to
// be garbage-collector safe I fill any gaps with valid data...
    if (n != final)
    {   ((LispObject* )&p[final])[0] =
            TAG_HDR_IMMED + TYPE_PADDER + ((n-final)<<(Tw+8));
        if (sizeof(LispObject) == 4)
            ((LispObject* )&p[n])[1] = 0;
    }
    return vectorToHandle(p);
}

inline std::intptr_t confirmSize_x(std::uint64_t* p, std::size_t n,
                                   std::size_t final)
{
// Here I might need to write a nice dummy object into the gap left by
// shrinking the object.
    return confirmSize(p, n, final);
}

inline std::intptr_t vectorToHandle(std::uint64_t* p)
{   return reinterpret_cast<std::intptr_t>(p) - 8 + TAG_NUMBERS;
}

inline std::uint64_t* vectorOfHandle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t*>(n + 8 - TAG_NUMBERS);
}

inline std::size_t numberSize(std::uint64_t* p)
{
// The odd looking cast here is because in arithlib I am passing around
// arrays of explicitly 64-bit values, however in the underlying Lisp
// I expect to be modelling memory as made up of intptr-sized items
// that I arrange to have aligned on 8-byte boundaries. So to show some
// though about strict aliasing and the like I will access memory as
// an array of LispObject things when I access the header of an item.
    Header h = (Header)*(LispObject* )&p[-1];
    std::size_t r = length_of_header(h);
// On 32-bit systems a bignum will have a wasted 32-bit word after the
// header and before the digits, so that the digits are properly aligned
// in memory. The result will be that the bignum is laid out as follows
//      |     hdr64     | digit64 | digit64 | ... |    (64-bit world)
//      | hdr32 | gap32 | digit64 | digit64 | ... |    (32-bit world)
// The length value packed into the header is the length of the vector
// including its header.
    r = (r-8)/sizeof(Digit);
    return r;
}

inline bool storedAsFixnum(std::intptr_t a)
{   return is_fixnum(a);
}

constexpr inline SignedDigit intOfHandle(std::intptr_t a)
{   return int_of_fixnum(a);
}

inline std::intptr_t intToHandle(SignedDigit n)
{   return fixnum_of_int(n);
}

inline const SignedDigit MIN_FIXNUM = intOfHandle(INTPTR_MIN);
inline const SignedDigit MAX_FIXNUM = intOfHandle(INTPTR_MAX);

inline bool fitsIntoFixnum(SignedDigit a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t* p)
{   // No need to do anything! But MIGHT reset fringe pointer?
}

inline void abandon(std::intptr_t p)
{   if (!storedAsFixnum(p) && p!=0)
    {   std::uint64_t* pp = vectorOfHandle(p);
        abandon(pp);
    }
}

inline char* reserveString(std::size_t n)
{   LispObject a = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    return reinterpret_cast<char*>(a - TAG_VECTOR + sizeof(LispObject));
}

inline LispObject confirmSizeString(char* p, std::size_t n,
                                             std::size_t final)
{
// The size of the string object in memory must allow for  a Lisp header
    n += sizeof(std::uintptr_t);
    final += sizeof(std::uintptr_t);
// The object size gets padded up to a multiple of 8 bytes.
    size_t nPadded = (n+7) & -8;
    size_t finalPadded = (final+7) & -8;
    if (nPadded != finalPadded)
       * reinterpret_cast<LispObject*>(p+finalPadded) =
            TAG_HDR_IMMED + TYPE_PADDER +
            ((nPadded-finalPadded)<<(Tw+5));
    LispObject* a = reinterpret_cast<LispObject*>(p - sizeof(LispObject));
   * a = TAG_HDR_IMMED + TYPE_STRING_4 + (final<<(Tw+5));
    return (LispObject)a + TAG_VECTOR;
}

inline void abandonString(string_handle s)
{   // Do nothing.
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1));
    else return OP::op(vectorOfHandle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, SignedDigit n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t* n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (storedAsFixnum(a1))
    {   LIKELY
        if (storedAsFixnum(a2))
            LIKELY
            return OP::op(intOfHandle(a1), intOfHandle(a2));
        else return OP::op(intOfHandle(a1), vectorOfHandle(a2));
    }
    else
    {   if (storedAsFixnum(a2))
            LIKELY
            return OP::op(vectorOfHandle(a1), intOfHandle(a2));
        else return OP::op(vectorOfHandle(a1), vectorOfHandle(a2));
    }
}

inline std::intptr_t alwaysCopyBignum(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::intptr_t pp)
{   if (storedAsFixnum(pp)) return pp;
    std::uint64_t* p = vectorOfHandle(pp);
    std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

#else // CSL

inline std::uint64_t* reserve(std::size_t n)
{
// I must allow for alignment padding on 32-bit platforms.
    if (sizeof(LispObject)==4) n = n*sizeof(Digit) + 4;
    else n = n*sizeof(Digit);
    LispObject a = allocateatom(n);
    return reinterpret_cast<std::uint64_t*>(a + 8 - tagATOM);
}

inline std::intptr_t confirmSize(Digit *p, std::size_t n,
                                 std::size_t final)
{   if (final == 1 && fitsIntoFixnum(static_cast<SignedDigit>(p[0])))
    {   std::intptr_t r = intToHandle(static_cast<SignedDigit>(p[0]));
        return r;
    }
    ((LispObject* )&p[-1])[0] =
        tagHDR + typeBIGNUM + packlength(final*sizeof(Digit) +
                                         (sizeof(LispObject)==4 ? 4 : 0));
// If I am on a 32-bit system the data for a bignum is 8 bit aligned and
// that leaves a 4-byte gap after the header. In such a case I will write
// in a zero just to keep memory tidy.
    if (sizeof(LispObject) == 4)
        ((LispObject* )&p[-1])[1] = 0;
// Here I should reset fringe down by (final-n) perhaps. Think about that
// later!
    return vectorToHandle(p);
}

inline std::intptr_t confirmSize_x(std::uint64_t* p,
                                   std::size_t n, std::size_t final)
{
// Here I might need to write a nice dummy object into the gap left by
// shrinking the object.
    return confirmSize(p, n, final);
}

inline std::intptr_t vectorToHandle(std::uint64_t* p)
{   return reinterpret_cast<std::intptr_t>(p) - 8 + tagATOM;
}

inline std::uint64_t* vectorOfHandle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t*>(n + 8 - tagATOM);
}

inline std::size_t numberSize(std::uint64_t* p)
{
// The odd looking cast here is because in arithlib I am passing around
// arrays of explicitly 64-bit values, however in the underlying Lisp
// I expect to be modelling memory as made up of intptr-sized items
// that I arrange to have aligned on 8-byte boundaries. So to show some
// though about strict aliasing and the like I will access memory as
// an array of LispObject things when I access the header of an item.
    std::uintptr_t h = reinterpret_cast<std::uintptr_t>(*(LispObject*)&p[-1]);
    std::size_t r = veclength(h);
// On 32-bit systems a bignum will have a wasted 32-bit word after the
// header and before the digits, so that the digits are properly aligned
// in memory. The result will be that the bignum is laid out as follows
//      |     hdr64     | digit64 | digit64 | ... |    (64-bit world)
//      | hdr32 | gap32 | digit64 | digit64 | ... |    (32-bit world)
// The length value packed into the header is the length of the vector
// excluding its header.
//  if (sizeof(LispObject) == 4) r -= 4; { the remaindering does all I need! }
    r = r/sizeof(Digit);
    return r;
}

inline bool storedAsFixnum(std::intptr_t a)
{   return isFIXNUM(a);
}

constexpr inline SignedDigit intOfHandle(std::intptr_t a)
{   return qfixnum(a);
}

inline std::intptr_t intToHandle(SignedDigit n)
{   return packfixnum(n);
}

inline bool fitsIntoFixnum(SignedDigit a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t* p)
{   // No need to do anything! But MIGHT reset fringe pointer?
}

inline void abandon(std::intptr_t p)
{   if (!storedAsFixnum(p) && p!=0)
    {   std::uint64_t* pp = vectorOfHandle(p);
        abandon(pp);
    }
}

inline char* reserveString(std::size_t n)
{   LispObject a = allocateatom(n);
    return reinterpret_cast<char*>(a - tagATOM + sizeof(LispObject));
}

inline LispObject confirmSizeString(char* p, std::size_t n,
                                    std::size_t final)
{   LispObject* a = (LispObject* )(p - sizeof(LispObject));
// On 32-bit platforms I do not have a padder word before string data
// so things are simpler here than when confirming the size of a number.
   * a = tagHDR + typeSTRING + packlength(final);
    return (LispObject)a +tagATOM;
}

inline void abandonString(string_handle s)
{   // Do nothing.
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1));
    else return OP::op(vectorOfHandle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, SignedDigit n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t* n)
{   if (storedAsFixnum(a1)) return OP::op(intOfHandle(a1), n);
    else return OP::op(vectorOfHandle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (storedAsFixnum(a1))
    {   LIKELY
        if (storedAsFixnum(a2))
            LIKELY
            return OP::op(intOfHandle(a1), intOfHandle(a2));
        else return OP::op(intOfHandle(a1), vectorOfHandle(a2));
    }
    else
    {   if (storedAsFixnum(a2))
            LIKELY
            return OP::op(vectorOfHandle(a1), intOfHandle(a2));
        else return OP::op(vectorOfHandle(a1), vectorOfHandle(a2));
    }
}

inline std::intptr_t alwaysCopyBignum(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::uint64_t* p)
{   std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

inline std::intptr_t copyIfNoGarbageCollector(std::intptr_t pp)
{   if (storedAsFixnum(pp)) return pp;
    std::uint64_t* p = vectorOfHandle(pp);
    std::size_t n = numberSize(p);
    std::uint64_t* r = reserve(n);
    std::memcpy(r, p, n*sizeof(Digit));
    return confirmSize(r, n, n);
}

#endif // !CSL

#else // none if MALLOC, LISP or NEW specified.
#error Unspecified memory model
#endif // No memory model givem

// The main arithmetic operations are supported by code that can work on
// Bignums stored as vectors of digits or on Fixnums represented as (tagged)
// immediate data, or as mixtures. For each operation there is a class, and
// methods called "op" within it deal with the various cases via overloading.

class Plus
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

inline std::intptr_t bigplus_small(std::intptr_t, SignedDigit);

class Difference
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class RevDifference
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Times
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

// ClassicalTimes is provided just for debugging.

class ClassicalTimes
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Quotient
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Remainder
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Mod
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Floor
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Ceiling
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Divide
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
    static std::intptr_t op(SignedDigit, SignedDigit, std::intptr_t&);
    static std::intptr_t op(SignedDigit, std::uint64_t* , std::intptr_t&);
    static std::intptr_t op(std::uint64_t* , SignedDigit, std::intptr_t&);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* , std::intptr_t&);
};

class Gcd
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Lcm
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Logand
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Logor
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Logxor
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Logeqv
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Zerop
{
public:
    static bool op(SignedDigit w);
    static bool op(std::uint64_t* w);
};

class Onep
{
public:
    static bool op(SignedDigit w);
    static bool op(uint64_t* w);
};

class Minusp
{
public:
    static bool op(SignedDigit w);
    static bool op(uint64_t* w);
};

class Plusp
{
public:
    static bool op(SignedDigit w);
    static bool op(uint64_t* w);
};

class Evenp
{
public:
    static bool op(SignedDigit w);
    static bool op(uint64_t* w);
};

class Oddp
{
public:
    static bool op(SignedDigit w);
    static bool op(uint64_t* w);
};

class Eqn
{
public:
    static bool op(SignedDigit, SignedDigit);
    static bool op(SignedDigit, std::uint64_t* );
    static bool op(std::uint64_t* , SignedDigit);
    static bool op(std::uint64_t* , std::uint64_t* );
// Even comparing a floating point number with an integer for equality
// turns out to be messier than one might have hoped!
    static bool op(SignedDigit, float);
    static bool op(std::uint64_t* , float);
    static bool op(float, SignedDigit);
    static bool op(float, std::uint64_t* );
    static bool op(SignedDigit, double);
    static bool op(std::uint64_t* , double);
    static bool op(double, SignedDigit);
    static bool op(double, std::uint64_t* );
#ifdef softfloat_h
    static bool op(SignedDigit, float128_t);
    static bool op(std::uint64_t* , float128_t);
    static bool op(float128_t, SignedDigit);
    static bool op(float128_t, std::uint64_t* );
#endif // softfloat_h
};

class Neqn
{
public:
    static bool op(SignedDigit, SignedDigit);
    static bool op(SignedDigit, std::uint64_t* );
    static bool op(std::uint64_t* , SignedDigit);
    static bool op(std::uint64_t* , std::uint64_t* );
// Even comparing a floating point number with an integer for equality
// turns out to be messier than one might have hoped!
    static bool op(SignedDigit, float);
    static bool op(std::uint64_t* , float);
    static bool op(float, SignedDigit);
    static bool op(float, std::uint64_t* );
    static bool op(SignedDigit, double);
    static bool op(std::uint64_t* , double);
    static bool op(double, SignedDigit);
    static bool op(double, std::uint64_t* );
#ifdef softfloat_h
    static bool op(SignedDigit, float128_t);
    static bool op(std::uint64_t* , float128_t);
    static bool op(float128_t, SignedDigit);
    static bool op(float128_t, std::uint64_t* );
#endif // softfloat_h
};

class Geq
{
public:
    static bool op(SignedDigit, SignedDigit);
    static bool op(SignedDigit, std::uint64_t* );
    static bool op(std::uint64_t* , SignedDigit);
    static bool op(std::uint64_t* , std::uint64_t* );
// Comparing a bignum against a floating point value has multiple cases
// to consider, but needs special implementation so that neither rounding
// nor overflow not Infinities/NaNs lead to incorrect results.
    static bool op(SignedDigit, float);
    static bool op(std::uint64_t* , float);
    static bool op(float, SignedDigit);
    static bool op(float, std::uint64_t* );
    static bool op(SignedDigit, double);
    static bool op(std::uint64_t* , double);
    static bool op(double, SignedDigit);
    static bool op(double, std::uint64_t* );
#ifdef softfloat_h
    static bool op(SignedDigit, float128_t);
    static bool op(std::uint64_t* , float128_t);
    static bool op(float128_t, SignedDigit);
    static bool op(float128_t, std::uint64_t* );
#endif // softfloat_h
};

class Greaterp
{
public:
    static bool op(SignedDigit, SignedDigit);
    static bool op(SignedDigit, std::uint64_t* );
    static bool op(std::uint64_t* , SignedDigit);
    static bool op(std::uint64_t* , std::uint64_t* );
    static bool op(SignedDigit, float);
    static bool op(std::uint64_t* , float);
    static bool op(float, SignedDigit);
    static bool op(float, std::uint64_t* );
    static bool op(SignedDigit, double);
    static bool op(std::uint64_t* , double);
    static bool op(double, SignedDigit);
    static bool op(double, std::uint64_t* );
#ifdef softfloat_h
    static bool op(SignedDigit, float128_t);
    static bool op(std::uint64_t* , float128_t);
    static bool op(float128_t, SignedDigit);
    static bool op(float128_t, std::uint64_t* );
#endif // softfloat_h
};

class Leq
{
public:
    static bool op(SignedDigit, SignedDigit);
    static bool op(SignedDigit, std::uint64_t* );
    static bool op(std::uint64_t* , SignedDigit);
    static bool op(std::uint64_t* , std::uint64_t* );
    static bool op(SignedDigit, float);
    static bool op(std::uint64_t* , float);
    static bool op(float, SignedDigit);
    static bool op(float, std::uint64_t* );
    static bool op(SignedDigit, double);
    static bool op(std::uint64_t* , double);
    static bool op(double, SignedDigit);
    static bool op(double, std::uint64_t* );
#ifdef softfloat_h
    static bool op(SignedDigit, float128_t);
    static bool op(std::uint64_t* , float128_t);
    static bool op(float128_t, SignedDigit);
    static bool op(float128_t, std::uint64_t* );
#endif // softfloat_h
};

class Lessp
{
public:
    static bool op(SignedDigit, SignedDigit);
    static bool op(SignedDigit, std::uint64_t* );
    static bool op(std::uint64_t* , SignedDigit);
    static bool op(std::uint64_t* , std::uint64_t* );
    static bool op(SignedDigit, float);
    static bool op(std::uint64_t* , float);
    static bool op(float, SignedDigit);
    static bool op(float, std::uint64_t* );
    static bool op(SignedDigit, double);
    static bool op(std::uint64_t* , double);
    static bool op(double, SignedDigit);
    static bool op(double, std::uint64_t* );
#ifdef softfloat_h
    static bool op(SignedDigit, float128_t);
    static bool op(std::uint64_t* , float128_t);
    static bool op(float128_t, SignedDigit);
    static bool op(float128_t, std::uint64_t* );
#endif // softfloat_h
};

class Add1
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class Sub1
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class Minus
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class Abs
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class UniformUpto
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class Square
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class Isqrt
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class Lognot
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class Pow
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
    static double op(SignedDigit, double);
    static double op(std::uint64_t* , double);
};

class LeftShift
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class RightShift
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class Low64Bits
{
public:
    static Digit op(SignedDigit w);
    static Digit op(uint64_t* w);
};

class LowBit
{    // Index of least significant bit in the number 
public:
    static std::size_t op(SignedDigit w);
    static std::size_t op(uint64_t* w);
};

class IntegerLength
{   // Index of most significant bit in the number
public:
    static std::size_t op(SignedDigit w);
    static std::size_t op(uint64_t* w);
};

class Top64Bits
{   // For a non-zero number the top 64 bits aligned so the (1<<63) bit
    // is set. This is a bitt like a mantissa to go with IntegerLength as
    // an exponent.
public:
    static Digit op(SignedDigit w);
    static Digit op(uint64_t* w);
};

class Logbitp
{
public:
    static bool op(SignedDigit, std::size_t);
    static bool op(std::uint64_t* , std::size_t);
};

class Logcount
{
public:
    static std::size_t op(SignedDigit w);
    static std::size_t op(uint64_t* w);
};

class Int64_t
{   // Convert to 64-bit native integer.
public:
    static SignedDigit op(SignedDigit w);
    static SignedDigit op(uint64_t* w);
};

class Uint64_t
{   // Convert to 64-bit unsigned value.
public:
    static Digit op(SignedDigit w);
    static Digit op(uint64_t* w);
};

class Float
{
public:
    static float op(SignedDigit w);
    static float op(uint64_t* w);
};

class Double
{
public:
    static double op(SignedDigit w);
    static double op(uint64_t* w);
};

class Frexp
{
public:
    static double op(SignedDigit, SignedDigit& x);
    static double op(std::uint64_t* , SignedDigit& x);
};

#ifdef softfloat_h

class Float128
{
public:
    static float128_t op(SignedDigit w);
    static float128_t op(uint64_t* w);
};

class Frexp128
{
public:
    static float128_t op(SignedDigit, SignedDigit& x);
    static float128_t op(std::uint64_t* , SignedDigit& x);
};

#endif // softfloat_h

#ifdef CSL

class ModularPlus
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class ModularDifference
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class ModularTimes
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class ModularExpt
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class ModularQuotient
{
public:
    static std::intptr_t op(SignedDigit, SignedDigit);
    static std::intptr_t op(SignedDigit, std::uint64_t* );
    static std::intptr_t op(std::uint64_t* , SignedDigit);
    static std::intptr_t op(std::uint64_t* , std::uint64_t* );
};

class ModularMinus
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class ModularReciprocal
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class SafeModularReciprocal
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class ModularNumber
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

class SetModulus
{
public:
    static std::intptr_t op(SignedDigit w);
    static std::intptr_t op(uint64_t* w);
};

#endif // CSL

inline string_handle bignumToString(std::intptr_t aa);
inline string_handle bignumToStringHex(std::intptr_t aa);
inline string_handle bignumToStringOctal(std::intptr_t aa);
inline string_handle bignumToStringBinary(std::intptr_t aa);

class Bignum;

inline int displayIndent = 0;
inline void display(const char& label,
                    const std::uint64_t* a,
                    std::size_t lena);
inline void display(const char* label, std::intptr_t a);
inline void display(const char* label, const Bignum& a);

inline void display(std::string label,
                    const std::uint64_t* a,
                    std::size_t lena);
inline void display(std::string label, std::intptr_t a);
inline void display(std::string label, const Bignum& a);

inline void display(const char& label,
                    SignedDigit top,
                    const std::uint64_t* a,
                    std::size_t lena);
inline void display(std::string label,
                    SignedDigit top,
                    const std::uint64_t* a,
                    std::size_t lena);

//=========================================================================
//=========================================================================
// I have a class Bignum that wraps up the representation of a number
// and then allows me to overload most operators so that big numbers can be
// used in C++ code almost as if they were a natural proper type. The main
// big oddity will be that to denote a Bignum literal it will be necessary
// to use a constructor, with obvious constructors accepting integers of up
// to 64-bits and a perhaps less obvious one taking a string that is the
// decimal denotation of the integer concerned. Well actually I also support
// input notation like 12345_Z for Bignum. I would have liked to make
// the processing of this input syntax "constexpr" so that the work was done
// at compile time, however a big number needs some storage allocated
// and it is not obvious how I can arrange that in a constexpr context. So
// this is not really totally delightful. One can of course write
//       static Bignum vv = 12345_Z;
// and then the initialisation is done once during program startup.
//=========================================================================
//=========================================================================

class Bignum
{
public:
// a Bignum only had one data field, and that is simple plain data.
    std::intptr_t val;


// A default constructor build a Bignum with no stored data.
    Bignum()
    {   val = 0;
    }
// In the next constructor the boolean argument is not used at run time but
// serves to indicate which constructor is wanted.
    Bignum(bool set_val, std::intptr_t v)
    {   val = v;
    }
    ~Bignum()
    {   abandon(val);
        val = 0;
    }
    Bignum(std::uint64_t* p)
    {   val = vectorToHandle(p);
    }
// The code here is more complicated than I would have liked. What I want is
// that ANY sort of C++ integer can be converted to a Bignum. My first
// attempts arranges that int32_t and int64_t could be, however there is
// no guarantee that just coping with all the width-specified cases will
// then cover mere "int" and "long". So what I now use is a template
// definition filtered with magic that constrains it to only matching the
// template parameter against some sort of integer. In some cases (such as
// here) I provide one version to deal with all the signed integer cases
// and another all the unsigned ones.
// In general I will receive integers this way and cast them to 64-bit
// values. This means that if the platform happens to provide intmax_t
// that is wider than that then it will not be handled well!
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
        typename std::enable_if<std::is_signed<T>::value>::type* = nullptr>
    Bignum(T n)
    {   val = intToBignum(static_cast<SignedDigit>(n));
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
        typename std::enable_if<std::is_unsigned<T>::value>::type* = nullptr>
    Bignum(T n)
    {   val = unsignedIntToBignum(static_cast<Digit>(n));
    }
    Bignum(float d)
    {   val = roundDoubleToInt(static_cast<double>(d));
    }
    Bignum(double d)
    {   val = roundDoubleToInt(d);
    }
#ifdef softfloat_h
    Bignum(float128_t d)
    {   val = roundFloat128ToInt(d);
    }
#endif // softfloat_h
    Bignum(const char* s)
    {   val = stringToBignum(s);
    }
    Bignum(const Bignum& a)
    {   val = copyIfNoGarbageCollector(a.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
        typename std::enable_if<std::is_signed<T>::value>::type* = nullptr>
    operator T()
    {   return static_cast<T>(op_dispatch1<Int64_t, SignedDigit>(val));
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
        typename std::enable_if<std::is_unsigned<T>::value>::type* = nullptr>
    operator T()
    {   return static_cast<T>(op_dispatch1<Uint64_t, Digit>(val));
    }
    operator double()
    {   return op_dispatch1<Double, double>(val);
    }
    std::uint64_t* vec() const
    {   return vectorOfHandle(val);
    }

// In a way that is BAD I make the result of an assignment void rather than
// the value that is assigned. This is so I do not make gratuitous extra
// copies of it in the common case where the value is not used, but it could
// catch out the unwary.
    inline void operator = (const Bignum& x)
    {   if (this == &x) return; // assign to self - a silly case!
        abandon(val);
// See comment in the copy constructor.
        val = copyIfNoGarbageCollector(x.val);
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
        typename std::enable_if<std::is_signed<T>::value>::type* = nullptr>
    inline void operator = (const T x)
    {   abandon(val);
        val = intToBignum(static_cast<SignedDigit>(x));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
        typename std::enable_if<std::is_unsigned<T>::value>::type* = nullptr>
    inline void operator = (const T x)
    {   abandon(val);
        val = unsignedIntToBignum(static_cast<Digit>(x));
    }

    inline void operator = (const char* x)
    {   abandon(val);
        val = stringToBignum(x);
    }

    inline Bignum operator +(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Plus,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator +(const T x) const
    {   return Bignum(true,
                      op_dispatch2<Plus,std::intptr_t>(val, Bignum(x).val));
    }

    inline Bignum operator -(const Bignum& x) const
    {   return Bignum(true,
                      op_dispatch2<Difference,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator -(const T x) const
    {   return Bignum(true, op_dispatch2<Difference,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator *(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Times,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator *(const T x) const
    {   return Bignum(true,
            op_dispatch2<Times,std::intptr_t>(val, Bignum(x).val));
    }

    inline Bignum operator /(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Quotient,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator /(const T x) const
    {   return Bignum(true,
            op_dispatch2<Quotient,std::intptr_t>(val, Bignum(x).val));
    }

    inline Bignum operator %(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Remainder,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator %(const T x) const
    {   return Bignum(true, op_dispatch2<Remainder,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator -() const
    {   return Bignum(true, op_dispatch1<Minus,std::intptr_t>(val));
    }

    inline Bignum operator &(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Logand,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator &(const T x) const
    {   return Bignum(true, op_dispatch2<Logand,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator |(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Logor,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator |(const T x) const
    {   return Bignum(true, op_dispatch2<Logor,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator ^(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Logxor,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator ^(const T x) const
    {   return Bignum(true, op_dispatch2<Logxor,std::intptr_t>(val,
                      Bignum(x).val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator <<(T n) const
    {   return Bignum(true, op_dispatch1<LeftShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    inline Bignum operator <<(Bignum n) const
    {   return Bignum(true, op_dispatch1<LeftShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator >>(T n) const
    {   return Bignum(true, op_dispatch1<RightShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    inline Bignum operator >>(Bignum n) const
    {   return Bignum(true, op_dispatch1<RightShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    inline Bignum operator ~() const
    {   return Bignum(true, op_dispatch1<Lognot,std::intptr_t>(val));
    }

    inline bool operator ==(const Bignum& x) const
    {   return op_dispatch2<Eqn,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator ==(const T x) const
    {   return op_dispatch2<Eqn,bool>(val, Bignum(x).val);
    }

    inline bool operator !=(const Bignum& x) const
    {   return !op_dispatch2<Eqn,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator !=(const T x) const
    {   return !op_dispatch2<Eqn,bool>(val, Bignum(x).val);
    }

    inline bool operator >(const Bignum& x) const
    {   return op_dispatch2<Greaterp,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator >(const T x) const
    {   return op_dispatch2<Greaterp,bool>(val, Bignum(x).val);
    }

    inline bool operator >=(const Bignum& x) const
    {   return op_dispatch2<Geq,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator >=(const T x) const
    {   return op_dispatch2<Geq,bool>(val, Bignum(x).val);
    }

    inline bool operator <(const Bignum& x) const
    {   return op_dispatch2<Lessp,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator <(const T x) const
    {   return op_dispatch2<Lessp,bool>(val, Bignum(x).val);
    }

    inline bool operator <=(const Bignum& x) const
    {   return op_dispatch2<Leq,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator <=(const T x) const
    {   return op_dispatch2<Leq,bool>(val, Bignum(x).val);
    }

    inline void operator +=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Plus,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator +=(T x)
    {   std::intptr_t r = op_dispatch2<Plus,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator -=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Difference,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator -=(T x)
    {   std::intptr_t r =
            op_dispatch2<Difference,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator *=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Times,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator *=(T x)
    {   std::intptr_t r =
            op_dispatch2<Times,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator /=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Quotient,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator /=(T x)
    {   std::intptr_t r =
            op_dispatch2<Quotient,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator %=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Remainder,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator %=(T x)
    {   std::intptr_t r = op_dispatch2<Remainder,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator &=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Logand,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator &=(T x)
    {   std::intptr_t r =
            op_dispatch2<Logand,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator |=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Logor,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator |=(T x)
    {   std::intptr_t r =
            op_dispatch2<Logor,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator ^=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Logxor,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator ^=(T x)
    {   std::intptr_t r =
            op_dispatch2<Logxor,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator <<=(T n)
    {   std::intptr_t r =
            op_dispatch1<LeftShift,std::intptr_t>(val,
                static_cast<SignedDigit>(n));
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator >>=(T n)
    {   std::intptr_t r =
            op_dispatch1<RightShift,std::intptr_t>(val,
                static_cast<SignedDigit>(n));
        abandon(val);
        val = r;
    }

    inline Bignum operator ++()
    {   std::intptr_t r = bigplus_small(val, 1);
        abandon(val);
        val = r;
        return* this;
    }

    inline Bignum operator ++(int)
    {   std::intptr_t r = bigplus_small(val, 1);
// I assign explicitly to oldval.val because trying to use a constructor
// of Bignum or assigning to one would so things more complicated than I want!
        Bignum oldval;
        oldval.val = val;
        val = r;
        return oldval;
    }

    inline Bignum operator --()
    {   std::intptr_t r = bigplus_small(val, -1);
        abandon(val);
        val = r;
        return* this;
    }

    inline Bignum operator --(int)
    {   std::intptr_t r = bigplus_small(val, -1);
        Bignum oldval;
        oldval.val = val;
        val = r;
        return oldval;
    }

    inline Bignum lowbit() const
    {   return Bignum(true, op_dispatch1<LowBit,std::size_t>(val));
    }

    inline Bignum highbit() const
    {   return Bignum(true, op_dispatch1<IntegerLength,std::size_t>(val));
    }

    friend std::ostream & operator << (std::ostream &out, const Bignum& a)
    {   std::ios_base::fmtflags fg = out.flags();
#if defined LISP
        LispObject s;
#else // LISP
        char* s;
#endif // LISP
        if ((static_cast<unsigned int>(fg) & std::ios_base::hex) != 0U)
            s = bignumToStringHex(a.val);
        else if ((static_cast<unsigned int>(fg) & std::ios_base::oct) != 0U)
            s = bignumToStringOctal(a.val);
        else if ((static_cast<unsigned int>(fg) & std::ios_base::dec) != 0U)
            s = bignumToString(a.val);
        else if (radix::is_binary_output(out))
            s = bignumToStringBinary(a.val);
        else s = bignumToString(a.val);
#if defined LISP
        std::string ss(s, length_of_byteheader(qheader(s)) -
                          sizeof(std::uintptr_t));
        out << ss;
#else // lISP
        out << s;
#endif // LISP
        abandonString(s);
        return out;
    }
    friend std::istream & operator >> (std::istream &in, Bignum& a)
    {   SignedDigit n;
// What I really want to do is to read in a string of digits and then
// use stringToBignum().
        in >> n;
        abandon(a.val);
        a.val = intToBignum(n);
        return in;
    }
};

// I use a suffix "_Z" for bignums, with Z chosen to reminding me that this
// gives me an Integer, the "Z" (typically written in a blackboard font)
// standing for the ring of integers.
inline Bignum operator "" _Z(const char* s)
{   return Bignum(s);
}

inline const string_handle toString(Bignum x)
{   return bignumToString(x.val);
}

inline Bignum uniformPositiveBignum(std::size_t n)
{   return Bignum(true, uniformPositive(n));
}

inline Bignum uniformSignedBignum(std::size_t n)
{   return Bignum(true, uniformSigned(n));
}

inline Bignum uniformUptoBignum(Bignum a)
{   return Bignum(true, uniformUpto(a.val));
}

inline Bignum fudgeDistributionBignum(Bignum a, int n)
{   return Bignum(true, fudgeDistribution(a.val, n));
}

inline Bignum randomUptoBitsBignum(std::size_t n)
{   return Bignum(true, randomUptoBits(n));
}

inline Bignum square(const Bignum& x)
{   return Bignum(true, op_dispatch1<Square,std::intptr_t>(x.val));
}

inline Bignum isqrt(const Bignum& x)
{   return Bignum(true, op_dispatch1<Isqrt,std::intptr_t>(x.val));
}

inline Bignum abs(const Bignum& x)
{   return Bignum(true, op_dispatch1<Abs,std::intptr_t>(x.val));
}

inline bool zerop(const Bignum& x)
{   return op_dispatch1<Zerop,bool>(x.val);
}

inline bool onep(const Bignum& x)
{   return op_dispatch1<Onep,bool>(x.val);
}

inline bool minusp(const Bignum& x)
{   return op_dispatch1<Minusp,bool>(x.val);
}

inline bool plusp(const Bignum& x)
{   return op_dispatch1<Plusp,bool>(x.val);
}

inline bool evenp(const Bignum& x)
{   return op_dispatch1<Evenp,bool>(x.val);
}

inline bool oddp(const Bignum& x)
{   return op_dispatch1<Oddp,bool>(x.val);
}
template <typename T,
    typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
inline Bignum pow(const Bignum& x, T n)
{   if (n == 0) return Bignum(true, intToBignum(1));
    else if (n == 1) return Bignum(true, copyIfNoGarbageCollector(x.val));
    else if (n == 2) return square(x);
    else return Bignum(true,
        op_dispatch1<Pow,std::intptr_t>(x.val, static_cast<SignedDigit>(n)));
}

inline double doubleBignum(const Bignum& x);

inline double pow(const Bignum& x, double n)
{   return std::pow(doubleBignum(x), n);
}

inline Bignum gcd(const Bignum& x, const Bignum& y)
{   return Bignum(true, op_dispatch2<Gcd,std::intptr_t>(x.val, y.val));
}

inline Bignum lcm(const Bignum& x, const Bignum& y)
{   return Bignum(true, op_dispatch2<Lcm,std::intptr_t>(x.val, y.val));
}

inline Bignum fixBignum(double d)
{   return Bignum(true, truncDoubleToInt(d));
}

inline Bignum roundBignum(double d)
{   return Bignum(true, roundDoubleToInt(d));
}

inline Bignum truncBignum(double d)
{   return Bignum(true, truncDoubleToInt(d));
}

inline Bignum floorBignum(double d)
{   return Bignum(true, floorDoubleToInt(d));
}

inline Bignum ceilBignum(double d)
{   return Bignum(true, ceilingDoubleToInt(d));
}

inline Bignum fixBignum(float d)
{   return fixBignum(static_cast<double>(d));
}

inline Bignum roundBignum(float d)
{   return roundBignum(static_cast<double>(d));
}

inline Bignum truncBignum(float d)
{   return truncBignum(static_cast<double>(d));
}

inline Bignum floorBignum(float d)
{   return floorBignum(static_cast<double>(d));
}

inline Bignum ceilBignum(float d)
{   return ceilBignum(static_cast<double>(d));
}

inline double floatBignum(const Bignum& x)
{   return op_dispatch1<Float,float>(x.val);
}

inline double doubleBignum(const Bignum& x)
{   return op_dispatch1<Double,double>(x.val);
}

// This will return a normalized double and an integer exponent.
// It can be better than using frexp(doubleBignum(x), ..) because it
// avoids overflow.

inline double frexpBignum(const Bignum& x, SignedDigit &xx)
{   return op_dispatch1<Frexp,double>(x.val, xx);
}

#ifdef softfloat_h

inline float128_t frexp128Bignum(const Bignum& x, SignedDigit &xx)
{   return op_dispatch1<Frexp128,float128_t>(x.val, xx);
}

inline float128_t float128Bignum(const Bignum& x)
{   return op_dispatch1<Float128,float128_t>(x.val);
}

#endif // softfloat_h

//=========================================================================
// display() will show the internal representation of a bignum as a
// sequence of hex values. This is obviously useful while debugging!
// The format used is
//    label := 0xHEXVAL$
// which is something I can use especially happily using cut & paste to
// enter it into Reduce. So the HEXVAL can have embedded underscores
// followed by whitespace and I used that to keep line lengths under 80.
//=========================================================================

inline void display(const char* label,
                    const std::uint64_t* a,
                    std::size_t lena)
{   display(label, 0, a, lena);
}

inline void display(const char* label,
                    SignedDigit top,
                    const std::uint64_t* a,
                    std::size_t lena)
{   for (int i=0; i<std::min(displayIndent, 7); i++) std::printf(" ");
    int len = std::min(displayIndent, 7) + std::printf("%s := 0x", label);
    if (top >= 0)
        len += std::printf("%" PRIx64, top);
    else
    {   Digit mask = 0xf;
// I use Digit here rather than SignedDigit because C++ might view
// left shifts of signed values as being able to overflow.
        while ((top|mask) != static_cast<Digit>(-1)) mask=(mask<<4)|0xf;
        len += std::printf("~%" PRIx64, top & mask);
    }
    for (size_t i=lena; i!=0; i--)
    {   len += std::printf("_");
        if (len > 80-19)
        {   std::printf("\n");
            for (int i=0; i<std::min(displayIndent, 7); i++) std::printf(" ");
            len = std::min(displayIndent, 7);
        }
        len += std::printf("%.16" PRIx64, a[i-1]);
    }
    std::printf("$\n\n");
}

inline void display(const char* label, std::intptr_t a)
{   if (storedAsFixnum(a))
    {   for (int i=0; i<std::min(displayIndent, 7); i++) std::printf(" ");
        std::cout << label << " := " << std::hex
                  << "0x" << intOfHandle(a) << std::dec << "$\n\n";
    }
    else
    {   std::uint64_t* d = vectorOfHandle(a);
        std::size_t len = numberSize(d);
        display(label, d, len);
    }
}

inline void display(const char* label, const Bignum& a)
{   display(label, a.val);
}

inline void display(std::string label,
                    const std::uint64_t* a,
                    std::size_t lena)
{   display(label.c_str(), a, lena);
}

inline void display(std::string label,
                    SignedDigit top,
                    const std::uint64_t* a,
                    std::size_t lena)
{   display(label.c_str(), top, a, lena);
}

inline void display(std::string label, std::intptr_t a)
{   display(label.c_str(), a);
}

inline void display(std::string label, const Bignum& a)
{   display(label.c_str(), a);
}


//=========================================================================
//=========================================================================
// I will have a collection of low level functions that support the
// fundamental operations needed for implementing big-number arithmetic:
// add-with-carry, multiplication and division.
//=========================================================================
//=========================================================================

#ifndef HAVE_NLZ_AND_NTZ

#ifdef _cpp_lib_bitops

// C++20 provides functions for counting zeros. Unlike the GNU intrinsics
// they have defined behaviour when presented with a zero word.

inline int nlz(uint64_t x)
{   return countl_zero(x);
}

inline int ntz(uint64_t x)
{   return countr_zero(x);
}

inline int countBits(uint64_t x)
{   return std::popcount(x);
}

#elif defined __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too.

// Count the leading zeros in a 64-bit word.

inline int nlz(Digit x)
{   return x==0 ? 64 : __builtin_clzll(x);
}

inline int ntz(Digit x)
{   return x==0 ? 64 : __builtin_ctzll(x);
}

inline int countBits(Digit x)
{   return __builtin_popcountll(x);
}

#else // __GNUC__

inline int nlz(uint64_t x)
{   x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    x |= x>>32;
// Now x is a number with all bits up as far as its highest one set, and I
// have achieved that without performing any tests.
// 2 is a primitive root mod 67, so all the values of 2^k (0<=k<64) are
// distinct mod 67. So the same will apply for (2^k-1) which are the
// values I have here. So a simple lookup in a table of size 67 does the
// job for me. I will fill the table using code here that computes the
// relevant values since that feels safer than having a table of "magic
// numbers".
    auto nlzf = [](int n)
    {   if (n==0) return 64;
        uint64_t v = 0;
        int r = -1;
        for (int k=0; k<64; k++)
        {   v = 2*v + 1;
            if (v%67 == n) r = 63-k;
        }
        return r;
    };
// The way this is written out is tolerable because 67 is a reasonably
// small number, but it would have been neater if C++ provided a way to
// initialize arrays a bit like this. It does if one uses std::vector
// rather than a plain array. Note the use of constexpr so that the table
// is set up during compilation.
    constexpr static int8_t nlzTable[67] =
    {   nlzf( 0), nlzf( 1), nlzf( 2), nlzf( 3), nlzf( 4),
        nlzf( 5), nlzf( 6), nlzf( 7), nlzf( 8), nlzf( 9),
        nlzf(10), nlzf(11), nlzf(12), nlzf(13), nlzf(14),
        nlzf(15), nlzf(16), nlzf(17), nlzf(18), nlzf(19),
        nlzf(20), nlzf(21), nlzf(22), nlzf(23), nlzf(24),
        nlzf(25), nlzf(26), nlzf(27), nlzf(28), nlzf(29),
        nlzf(30), nlzf(31), nlzf(32), nlzf(33), nlzf(34),
        nlzf(35), nlzf(36), nlzf(37), nlzf(38), nlzf(39),
        nlzf(40), nlzf(41), nlzf(42), nlzf(43), nlzf(44),
        nlzf(45), nlzf(46), nlzf(47), nlzf(48), nlzf(49),
        nlzf(50), nlzf(51), nlzf(52), nlzf(53), nlzf(54),
        nlzf(55), nlzf(56), nlzf(57), nlzf(58), nlzf(59),
        nlzf(60), nlzf(61), nlzf(62), nlzf(63), nlzf(64),
        nlzf(65), nlzf(66)
    };
    return nlzTable[x % 67];
}

// ntz find the bit-number of the least significant bit, So here are some
// values it will return:
//    1      0
//    2      1
//    4      2
//    8      3
//   16      4
// etc. The name is for "Number of Trailing Zeros".
// If the input value is zero it returns 64, but the GNU builtin does not
// guarantee any such behaviour, so zero input should be considered illegal.

// This is related to the function intlog2() in tags.h, but that function
// is only to be applied on inputs that are a power of 2.

inline int ntz(uint64_t n)
{   auto ntzf = [](int n)
    {   if (n==0) return 64;
        uint64_t v=0;
        int r = -1;
        for (int k=0; k<64; k++)
        {   v = 1ULL<<k;
            if (v%67 == n) r = k;
        }
        return r;
    };
    constexpr static int8_t ntzTable[67] =
    {   ntzf( 0), ntzf( 1), ntzf( 2), ntzf( 3), ntzf( 4),
        ntzf( 5), ntzf( 6), ntzf( 7), ntzf( 8), ntzf( 9),
        ntzf(10), ntzf(11), ntzf(12), ntzf(13), ntzf(14),
        ntzf(15), ntzf(16), ntzf(17), ntzf(18), ntzf(19),
        ntzf(20), ntzf(21), ntzf(22), ntzf(23), ntzf(24),
        ntzf(25), ntzf(26), ntzf(27), ntzf(28), ntzf(29),
        ntzf(30), ntzf(31), ntzf(32), ntzf(33), ntzf(34),
        ntzf(35), ntzf(36), ntzf(37), ntzf(38), ntzf(39),
        ntzf(40), ntzf(41), ntzf(42), ntzf(43), ntzf(44),
        ntzf(45), ntzf(46), ntzf(47), ntzf(48), ntzf(49),
        ntzf(50), ntzf(51), ntzf(52), ntzf(53), ntzf(54),
        ntzf(55), ntzf(56), ntzf(57), ntzf(58), ntzf(59),
        ntzf(60), ntzf(61), ntzf(62), ntzf(63), ntzf(64),
        ntzf(65), ntzf(66)
    };
    return ntzTable[leastBit(n) % 67];
}


inline int countBits(Digit x)
{   x = (x & 0x5555555555555555U) + ((x >> 1) & 0x5555555555555555U);
    x = (x & 0x3333333333333333U) + ((x >> 2) & 0x3333333333333333U);
    x = x + ((x >> 4) & 0x0f0f0f0f0f0f0f0fU);
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32) & 0x7f;
}

#endif // __GNUC__

#define HAVE_NLZ_AND_NTZ 1

#endif // HAVE_NLZ_AND_NTZ

// Round a size_t integer up to the next higher power of 2.
// I do this based on counting the number of leading zeros in the
// binary representation of n-1.

inline std::size_t next_power_of_2(std::size_t n)
{   return (static_cast<std::size_t>(1)) << (64-nlz(
                static_cast<Digit>(n-1)));
}

inline unsigned int logNextPowerOf2(std::size_t n)
{   return (64-nlz(static_cast<Digit>(n-1)));
}

// I am going to represent bignums as arrays of 64-bit digits.
// Overall the representation will use 2s complement, and so all but the
// top digit will be treated as unsigned, while the top one is signed
// and the whole number must act as if it had its sign bit propagated
// indefinitely to the left. When I pass numbers to the low level
// code I will pass references to the input arrays and lengths. I will
// pass an arrange that will certainly be large enough to hold the result
// and the arithmetic functions will return the length in it that is used.
// This length will be such that the overall number does not have any
// extraneous leading zeros or leading 0xffffffffffffffff words, save that
// the value zero will be returned as a single word value not a no-word
// one. Note the word "extraneous", because the positive value 2^64-1
// will be represented as a 2-word item with 0 in the higher digit and
// 0xffffffffffffffff in the lower one - the leading zero is needed so
// that it is clear that the value is positive. A consequence of all this
// is that any bignum with length 1 can be extracted as an int64_t without
// loss.

// I want "add-with-carry" operations, and so I provide a function here to
// implement it. If the C++ compiler had a nice intrinsic I would like
// to use that! Well Intel compilers have an _addcarry_u64 that passes and
// returns the carry in an unsigned char and uses a pointer not a reference
// argument for passing back the result.

// a1 and a2 are 64-bit unsigned integers. While c_in is also that type it
// must only have one of the values 0 or 1. The effect will be to set r to
// the low 64-bits of a1+a2+c_in and return any carry that is generated.

// I have an overload of addWithCarry for use where it is known that
// the input carry is zero. That cases saves a small amount of work.


[[gnu::always_inline]]
inline Digit addWithCarry(Digit a1,
                                  Digit a2,
                                  Digit &r)
{   return static_cast<Digit>(__builtin_add_overflow(a1, a2, &r));
}

// Now the general version with a carry-in. Note that I require that this
// can cope with a carry-in that may be bigger than 1 and that thus the
// carry out can be 0, 1 or 2. So reallt this is an "add 3 values"
// function.

[[gnu::always_inline]]
inline Digit addWithCarry(Digit a1,
                                  Digit a2,
                                  Digit carry_in,
                                  Digit &r)
{   Digit w;
    Digit c1 = addWithCarry(a1, carry_in, w);
    return c1 + addWithCarry(w, a2, r);
}

// subtractWithBorrow does
//     r = a1 - a2 - b_in;
// and returns 1 is there is a borrow out.

[[gnu::always_inline]]
inline Digit subtractWithBorrow(Digit a1,
                                        Digit a2,
                                        Digit &r)
{   return static_cast<Digit>(__builtin_sub_overflow(a1, a2, &r));
}

[[gnu::always_inline]]
inline Digit subtractWithBorrow(Digit a1,
                                        Digit a2,
                                        Digit borrow_in,
                                        Digit &r)
{   Digit w;
    int b1 = subtractWithBorrow(a1, borrow_in, w);
    return b1 + subtractWithBorrow(w, a2, r);
}


// I want code that will multiply two 64-bit values and yield a 128-bit
// result. The result must be expressed as a pair of 64-bit integers.
// If I have a type "__int128", as will often be the case when using gcc,
// this is very easy to express. Otherwise I split the two inputs into
// 32-bit halves, do 4 multiplications and some additions to construct
// the result. At least I can keep the code portable, even if I can then
// worry about performance a bit.

#ifdef __SIZEOF_INT128__

// Well it seems that g++ and clang have different views about how to
// ask for unsigned 128-bit integers! So I abstract that away via a typedef
// called UINT128.

#ifdef __CLANG__
typedef __int128  INT128;
typedef __uint128 UINT128;
#else // __CLANG__
typedef __int128  INT128;
typedef unsigned __int128 UINT128;
#endif // __CLANG__

// At least for debugging I may wish to display 128-bit integers. Here I
// only do hex printing. I could do decimal and octal if I really wanted
// but just for debugging that does not seem vital. If some C++ compiler
// already supported printing of 128-bit ints this definition might clash
// and would need commenting out.

inline std::ostream & operator << (std::ostream &out, UINT128 a)
{   out << std::hex << std::setw(16) << std::setfill('0') <<
        static_cast<Digit>(a>>64)
        << " "
        << static_cast<Digit>(a) << std::dec << std::setfill(' ');
    return out;
}

inline UINT128 pack128(Digit hi, Digit lo)
{   return (static_cast<UINT128>(hi)<<64) | lo;
}

inline void multiply64(Digit a, Digit b,
                       Digit &hi, Digit &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>(b);
    hi = static_cast<Digit>(r >> 64);
    lo = static_cast<Digit>(r);
}

// Now much the same but forming a*b+c. Note that this can not overflow
// the 128-bit result. Both hi and lo are only updated at the end
// of this, and so they are allowed to be the same as other arguments.

inline void multiply64(Digit a, Digit b,
                       Digit c,
                       Digit &hi, Digit &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>(b) +
                static_cast<UINT128>(c);
    hi = static_cast<Digit>(r >> 64);
    lo = static_cast<Digit>(r);
}

inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             SignedDigit &hi, Digit &lo)
{   INT128 r = static_cast<INT128>(a)*static_cast<INT128>(b);
    hi = static_cast<SignedDigit>(static_cast<UINT128>(r) >> 64);
    lo = static_cast<Digit>(r);
}

inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             Digit c,
                             SignedDigit &hi, Digit &lo)
{   UINT128 r = static_cast<UINT128>(
                    static_cast<INT128>(a)*static_cast<INT128>(b))
                + static_cast<UINT128>(c);
    hi = static_cast<SignedDigit>(r >> 64);
    lo = static_cast<Digit>(r);
}

// divide {hi,lo} by divisor and generate a quotient and a remainder. The
// version of the code that is able to use __int128 can serve as clean
// documentation of the intent.

inline void divide64(Digit hi, Digit lo,
                     Digit divisor,
                     Digit &q, Digit &r)
{   UINT128 dividend = pack128(hi, lo);
    q = dividend / divisor;
    r = dividend % divisor;
}

#else // __SIZEOF_INT128__

// If the C++ system I am using does not support and 128-bit integer
// type or if I have not detected it everything can still be done using
// lots of 64-bit operations, with each 64-bit value often treated as
// two 32-bit halves.

inline void multiply64(Digit a, Digit b,
                       Digit &hi, Digit &lo)
{   Digit a1 = a >> 32,           // top half
                  a0 = a & 0xFFFFFFFFU;   // low half
    Digit b1 = b >> 32,           // top half
                  b0 = b & 0xFFFFFFFFU;   // low half
    Digit u1 = a1*b1,             // top of result
                  u0 = a0*b0;             // bottom of result
// Now I need to add in the two "middle" bits a0*b1 and a1*b0
    Digit w = a0*b1;
    u1 += w >> 32;
    w <<= 32;
    u0 += w;
    if (u0 < w) u1++;
// a0*b1 done
    w = a1*b0;
    u1 += w >> 32;
    w <<= 32;
    u0 += w;
    if (u0 < w) u1++;
    hi = u1;
    lo = u0;
}

// Now much the same but forming a*b+c. Note that this can not overflow
// the 128-bit result. Both hi and lo are only updated at the end
// of this, and so they are allowed to be the same as other arguments.

inline void multiply64(Digit a, Digit b,
                       Digit c,
                       Digit &hi, Digit &lo)
{   Digit a1 = a >> 32,           // top half
                  a0 = a & 0xFFFFFFFFU;   // low half
    Digit b1 = b >> 32,           // top half
                  b0 = b & 0xFFFFFFFFU;   // low half
    Digit u1 = a1*b1,             // top of result
                  u0 = a0*b0;             // bottom of result
// Now I need to add in the two "middle" bits a0*b1 and a1*b0
    Digit w = a0*b1;
    u1 += w >> 32;
    w <<= 32;
    u0 += w;
    if (u0 < w) u1++;
// a0*b1 done
    w = a1*b0;
    u1 += w >> 32;
    w <<= 32;
    u0 += w;
    if (u0 < w) u1++;
    u0 += c;                         // add in C.
    if (u0 < c) u1++;
    hi = u1;
    lo = u0;
}

inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             SignedDigit &hi, Digit &lo)
{   Digit h, l;
    multiply64(static_cast<Digit>(a),
               static_cast<Digit>(b), h, l);
    if (a < 0) h -= static_cast<Digit>(b);
    if (b < 0) h -= static_cast<Digit>(a);
    hi = static_cast<SignedDigit>(h);
    lo = l;
}

inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             Digit c,
                             SignedDigit &hi, Digit &lo)
{   Digit h, l;
    multiply64(static_cast<Digit>(a),
               static_cast<Digit>(b), c, h,
               l);
    if (a < 0) h -= static_cast<Digit>(b);
    if (b < 0) h -= static_cast<Digit>(a);
    hi = static_cast<SignedDigit>(h);
    lo = l;
}

inline void divide64(Digit hi, Digit lo,
                     Digit divisor,
                     Digit &q, Digit &r)
{   Digit u1 = hi;
    Digit u0 = lo;
    Digit c = divisor;
// See the Hacker's Delight for commentary about what follows. The associated
// web-site explains usage rights:
// "You are free to use, copy, and distribute any of the code on this web
// site (www.hackersdelight.org) , whether modified by you or not. You need
// not give attribution. This includes the algorithms (some of which appear
// in Hacker's Delight), the Hacker's Assistant, and any code submitted by
// readers. Submitters implicitly agree to this." and then "The author has
// taken care in the preparation of this material, but makes no expressed
// or implied warranty of any kind and assumes no responsibility for errors
// or omissions. No liability is assumed for incidental or consequential
// damages in connection with or arising out of the use of the information
// or programs contained herein."
// I may not be obliged to give attribution, but I view it as polite to!
// Any error that have crept in in my adapaptation of the original code
// will be my fault, but you see in the BSD license at the top of this
// file that I disclaim any possible liability for consequent loss or damage.
    const Digit base = 0x100000000U; // Number base (32 bits).
    Digit un1, un0,        // Norm. dividend LSD's.
        vn1, vn0,        // Norm. divisor digits.
        q1, q0,          // Quotient digits.
        un32, un21, un10,// Dividend digit pairs.
        rhat;            // A remainder.
// I am going to shift both operands left until the divisor has its
// most significant bit set.
    int s = nlz(c);           // Shift amount for norm. 0 <= s <= 63.
    c = c << s;               // Normalize divisor.
// Now I split the divisor from a single 64-bit number into a pair
// of 32-vit values.
    vn1 = c >> 32;            // Break divisor up into
    vn0 = c & 0xFFFFFFFFU;    // two 32-bit digits.
// Shift the dividend... and split it into parts.
    if (s == 0) un32 = u1;
    else un32 = (u1 << s) | (u0 >> (64 - s));
    un10 = u0 << s;           // Shift dividend left.
    un1 = un10 >> 32;         // Break right half of
    un0 = un10 & 0xFFFFFFFFU; // dividend into two digits.
// Predict a 32-bit quotient digit...
    q1 = un32/vn1;            // Compute the first
    rhat = un32 - q1*vn1;     // quotient digit, q1.
again1:
    if (q1 >= base || q1*vn0 > base*rhat + un1)
    {   q1 = q1 - 1;
        rhat = rhat + vn1;
        if (rhat < base) goto again1;
    }
    un21 = un32*base + un1 - q1*c;  // Multiply and subtract.
    q0 = un21/vn1;            // Compute the second
    rhat = un21 - q0*vn1;     // quotient digit, q0.
again2:
    if (q0 >= base || q0*vn0 > base*rhat + un0)
    {   q0 = q0 - 1;
        rhat = rhat + vn1;
        if (rhat < base) goto again2;
    }
    q = (q1 << 32) | q0;      // assemble and return quotient & remainder
    r = (un21*base + un0 - q0*c) >> s;
}

#endif // __SIZEOF_INT128__

// While my arithmetic is all done in uint64_t (and that is important so
// that in C++ the consequences of overflow are defined) I need to treat
// some top-digits as signed: here are values and tests relating to that.

inline const Digit allbits   = ~static_cast<Digit>(0);
inline const Digit topbit    = static_cast<Digit>(1)<<63;
inline const Digit allbuttop = topbit - 1;

inline bool positive(Digit a)
{   return static_cast<SignedDigit>(a) >= 0;
}

inline bool negative(Digit a)
{   return static_cast<SignedDigit>(a) < 0;
}

inline bool strictlyPositive(Digit a)
{   return static_cast<SignedDigit>(a) > 0;
}

inline bool negativeOrZero(Digit a)
{   return static_cast<SignedDigit>(a) <= 0;
}

// This next function might be naively written as
//    return ((a1==0 && positive(a2)) ||
//            (a1==-1 && negative(a2)));
// and it is to test if a bignum can have its top digit removed.

inline bool shrinkable(Digit a1, Digit a2)
{   return ((a1 + (a2>>63)) == 0);
}

inline void internalCopy(const std::uint64_t* a, std::size_t lena,
                         std::uint64_t* b)
{   std::memcpy(b, a, lena*sizeof(Digit));
}

// This internal functions sets b to be -a without altering its length.
// Because length is not changed it does not need a length for the
// destination passed to it.

inline void internalNegate(const std::uint64_t* a, std::size_t lena,
                           std::uint64_t* b)
{   Digit carry = 1;
    for (std::size_t i=0; i<lena; i++)
    {   Digit w = b[i] = ~a[i] + carry;
        carry = (w < carry);
    }
}

// When printing numbers in octal it will be handy to be able treat the
// data as an array of 3-bit digits, so here is an access function that
// does that. There is a messy issue about the top of a number, where it
// may not be a whole number of 3-bit octal digits. I pass in v, a vector
// of 64-bit values, n which is the length of that vector and i which
// is the index of the octal digit that I wish to extract. To help with
// that I have a function virtualDigit64() which lets me read from a
// bignum as if it has been usefully sign-extended.

inline Digit virtualDigit64(const std::uint64_t* v,
                                    std::size_t n,
                                    std::size_t j)
{   if (j < n) return v[j];
    else if (positive(v[n-1])) return 0;
    else return UINT64_C(0xffffffffffffffff);
}

// This function reads a 3-bit digit from a bignum, and is for use when
// printing in octal.

inline int readU3(const std::uint64_t* v, std::size_t n,
                  std::size_t i)
{   std::size_t bits = 3*i;
    std::size_t n0 = bits/64;   // word with lowest bit of the 3
    std::size_t s0 =
        bits%64;   // amount to shift right to align it properly
    Digit w = virtualDigit64(v, n, n0) >> s0;
// If I needed to shift by 62 or 63 bits then the octal digit I am interested
// in needs some bits from the next word up.
    if (s0 >= 62) w |= (virtualDigit64(v, n, n0+1) << (64-s0));
    return static_cast<int>(w & 0x7);
}

//=========================================================================
//=========================================================================
// Some support for two models of memory layout. If VSL is set a number
// will be represented as an intptr_t value with its low 3 bits used as
// a tag. When the tag is removed and the intptr_t is cast to (uint64_t* )
// it points at a block of words. The first word holds a header value
// that includes (in packed form) the length of the block. Beyond that
// is the row of uint64_t values making up the bignum itself.
//
// For more direct C++ use the type is just (uint64_t* ) and it refers
// directly to the row of digits of the bignum. However at the address
// just ahead of that (ie at v[-1]) there is a header word giving the
// length of the bignum.
// Sometime soon this header word will be structured as two 32-bit
// parts. One will give the number of 64-bit elements of the vector that
// are actually in ise. The other will be a small integer indicating
// a power of two that is the size of memory block that was allocated.
// Such a scheme always rounds allocated sizes up using next_power_of_2()
// and then when the actual number of digits a number occupies turns out
// to be less than it might have there is no need to recycle memory - the
// "actual length" field is just updates. Furthermore a modest sized
// table can keep freelists of discarded blocks on each size, so allocation
// is potentially speeded up.
//=========================================================================
//=========================================================================


// For a free-standing bignum application (including my test code for the
// stuff here, bignums are represented as blocks of memory (allocated using
// malloc) where the pointer that is used points to the start of the
// array of bignum digits, and the word in memory before that contains
// the length (in words) of the block.
// Strings are returned to the user as freshly malloced memory holding a
// native-style C++ string with a terminating NUL character at the end.


//=========================================================================
//=========================================================================
// Random number support
//=========================================================================
//=========================================================================

// Well this is the first place in this file where an issue arises that will
// apply in several other places. I want some data that is static and
// some that is thread_local. But I am making this a header-only library, so
// it is liable to be included from several compilation units, and so if
// I simply make variables
//     static int something;
//     thread_local int something_else;
// I will suffer from multiple-definition problems. For the next few years
// (the current date is May 2019) I can not use "inline int something;"
// which would do the trick but which is not supported by all the slightly
// older C++ implementations I want to be able to use. My resolution is
// along the lines of
//     inline int &something() { static int x = 17; return x; }
// And then I can go for instance:
//     int a = something();
//     something()++;
//     int &aref = something();
//     ... aref .. aref ... aref;
// The effect is that about the only misery is that when I refer to the value
// I need to write and extra pair of parentheses. And the last fragment of
// example shows how if I am going to make multiple uses of something I can
// do the function call just once. That minor optimization may become
// more important if I use thread_local instead of static, since it can
// make the access overhead of of thread local variable arise just once
// rather than potentially many times.
// There is (I am afraid) more to say, especially in the static value is
// a more complex type than merely "int". The initialization of x will
// happen just once. But about all you can guarantee is that it will happen
// at latest when something() is first called. This could result in the code
// for something() needing to incorporate a "has it been initialized" test.
// That though may be extra encouragement to use the "aref" idiom.
// Now if x is a class object we can also worry about when its destructor
// will be called! Well x is static it gets destroyed at program termination
// with all the usual joys regarding seqencing. If it is thread_local its
// destructor is invoked as the thread terminates. Again it will be prudent
// to avoid too many assumptions about the ordering of destruction, and when
// such orderings are relied upon to include copious comments in the code
// as to why everything will be OK. In particular it will be hard to have
// guarantees about the order in which constructors have been called.
//
// Note to self: one might believe that
//    class Something { static int x; ... }
// was going to be helpful, because that guarantees that there will only be
// a single instance of x (and if it was thread_local similarly). However
// what you have there is a declation of x not a definition, and without a
//    ?thread_local? int Something::x = 3;
// sort of definition somewhere. But without it being "inline int.." This
// would cause trouble with multiple-file scenarios. So I am not going to
// be using static members of classes to sort myself out.
//
// It is useful to be able to generate random values. C++11 is simultaneously
// very helpful and rather unhelpful. The class std::random_device is
// expected to yield genuine unpredictable values, but it is not guaranteed
// to and it fails to on some platforms, so despite the fact that when it
// works it is a really good thing I can not rely solely on it. Each time I
// use a random_device it gives me just 32 bits. For my real generator that
// is not really enough.
// So here I create 3 notionally unpredictable units and then merge in the
// identity of the current thread and two measurements related to time.
// To avoid thread safety issues with random_device I make calls to it
// global, and then the thread identifier and time of day information stands
// a prospect of arranging that each thread gets its own mersenne-twister
// with its own seeding.
// Note that Wikipedia explains "Multiple instances that differ only in
// seed value (but not other parameters) are not generally appropriate
// for Monte-Carlo simulations that require independent random number
// generators".

// The code here is explicitly aware of the prospect of threading, and
// should lead to different pseudo-random sequences in each thread.
// If you do not have C++17 inline variables then there will be a separate
// generator for each compilation unit and especially if you have an
// unreliable std::random_device about the only thing liable to keep
// things distinct in each will be the high resolution clock. Well to
// try to improve things there I will use the address of one of these
// variables as part of the seeding process, so that if they all end
// up static rather than inline that will give per-compilation-unit
// variation.

// Note that the thread local status information for a random number
// generator will be initialized in EVERY thread that is created. This
// includes the worker threads for Karatsuba multiplication and in a
// broader context where I use this library it will include threads that
// are used for GUI or other I/O purposes. So there is a benefit if C++
// delays initialization of any of the variables within the following
// function until the function is first used!

inline std::seed_seq* get_random_seed()
{   Digit threadid =
        static_cast<Digit>(std::hash<std::thread::id>()(
                                       std::this_thread::get_id()));
    std::random_device basic_randomness;
    Digit seed_component_1 = static_cast<Digit>
                                            (basic_randomness());
    Digit seed_component_2 = static_cast<Digit>
                                            (basic_randomness());
    Digit seed_component_3 = static_cast<Digit>
                                            (basic_randomness());
    Digit time_now =
        static_cast<Digit>
        (std::time(nullptr));
    Digit chrono_now =
        static_cast<Digit>(
            std::chrono::high_resolution_clock::now().
                time_since_epoch().count());
// In my first draft of this library I had made the random seed directly
// from uint64_t values. However when testing on a Raspberry Pi that
// triggered a messages about bugs in gcc before gcc7 (relating to the
// alignment of some values passed as arguments in obscure cases). Building
// the seed sequence using 32-bit values avoids that issue, and since this
// is only done during initialization it is not time-critical.
    static std::seed_seq random_seed
    {   static_cast<std::uint32_t>(threadid),
        static_cast<std::uint32_t>(seed_component_1),
        static_cast<std::uint32_t>(seed_component_2),
        static_cast<std::uint32_t>(seed_component_3),
        static_cast<std::uint32_t>(time_now),
        static_cast<std::uint32_t>(chrono_now),
        static_cast<std::uint32_t>(threadid>>32),
        static_cast<std::uint32_t>(seed_component_1>>32),
        static_cast<std::uint32_t>(seed_component_2>>32),
        static_cast<std::uint32_t>(seed_component_3>>32),
        static_cast<std::uint32_t>(time_now>>32),
        static_cast<std::uint32_t>(chrono_now>>32),
        static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&seed_component_1)),
        static_cast<std::uint32_t>(
            static_cast<Digit>(
                reinterpret_cast<std::uintptr_t>(&seed_component_1))>>32)
    };
   return &random_seed;
}

// Should this be thread_local? 
inline std::mt19937_64 mersenne_twister(*get_random_seed());

// To re-seed I can just call this. I think that when I re-seed it will
// often be to gain repeatable behaviour, and so I am fairly happy about
// limiting the amount of input entropy here to 64-bits.
// However I arrange that a new seed that is zero tries to lead to
// unpredictable and ideally genuine random behaviour.
// Note that this will reseed the random number generator associated with
// the thread it is called from. Specifically there is one generator per
// thread, so if you have multiple threads and you reseed to obtain
// determininistic "random" values you are liable to want to reseed each
// of threads.
//

MAYBE_UNUSED static void reseed(Digit n)
{   if (n == 0)
    {   std::random_device basic_randomness;
        Digit threadid =
            static_cast<Digit>(
                std::hash<std::thread::id>()(
                    std::this_thread::get_id()));
        Digit seed_component =
            static_cast<Digit>(basic_randomness());
        Digit time_now =
            static_cast<Digit>(std::time(nullptr));
        Digit chrono_now =
            static_cast<Digit>(
                std::chrono::high_resolution_clock::now().
                    time_since_epoch().count());
        n = threadid ^ seed_component ^ time_now ^ chrono_now ^
            reinterpret_cast<uint64_t>(&n);
    }
    mersenne_twister.seed(n);
}

// Now a number of functions for setting up random bignums. These may be
// useful for users, but they will also be very useful while testing this
// code.

// Return a random integer in the range 0 ... n-1.
// Given that the largest n that can be passed is UINT64_MAX the biggest
// rangs that can be generated here is 1 less than the full range of 64-bit
// values. To get a full 64-bit range merely call mersenne_twister()
// directly.

inline Digit uniformUint64(Digit n)
{   if (n <= 1) return 0;
// I I want the remainder operation on the last line of this function to
// return a uniformly distributed result. To ensure that I want r to be
// drawn uniformly from a range that is a multiple of n.
    Digit q = UINT64_MAX/n;
    Digit w = n*q;
    Digit r;
// In the worst case here n was just over UINT64_MAX/2 and q came out
// as 1. In that case on average I will need to call mersenne_twister
// twice. Either larger or smaller inputs will behave better, and rather
// small inputs will mean I hardly ever need to re-try.
    do
    {   r = mersenne_twister();
    }
    while (r >= w);
    return r%n;
}

// A uniform distribution across the range [0 .. (2^bits)-1], ie
// a bignum using (up to) the given number of bits. So eg uniformPositive(3)
// should return 0,1,2,3,4,5,6 or 7 each with equal probability.

inline void uniformPositive(std::uint64_t* r, std::size_t &lenr,
                            std::size_t bits)
{   if (bits == 0)
    {   r[0] = 0;
        lenr = 1;
    }
    lenr = (bits+63)/64;
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mersenne_twister();
    if (bits%64 == 0) r[lenr-1] = 0;
    else r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (64-bits%64);
    while (lenr!=1 && shrinkable(r[lenr-1], r[lenr-2])) lenr--;
}

inline std::intptr_t uniformPositive(std::size_t n)
{   std::size_t lenr = (n + 63)/64;
    if (lenr == 0) lenr = 1; // special case!
    std::size_t save = lenr;
    std::uint64_t* r = reserve(lenr);
    uniformPositive(r, lenr, n);
    return confirmSize(r, save, lenr);
}

// As above but returning a value that may be negative. uniformSigned(3)
// could return -8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6 or 7.
// Note that while uniform_unsigned(0) can only return the value 0,
// uniformSigned(0) can return -1 or 0.

inline void uniformSigned(std::uint64_t* r, std::size_t &lenr,
                          std::size_t bits)
{   lenr = 1 + bits/64;
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mersenne_twister();
// Now if the "extra" bit is zero my number will end up positive.
    if ((r[lenr-1] & (UINT64_C(1) << (bits%64))) == 0)
    {   r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (63-bits%64);
        while (lenr!=1 && r[lenr-1] == 0) lenr--;
    }
// Otherwise the result will end up negative.
    else
    {   r[lenr-1] |= UINT64_C(0xffffffffffffffff) << (bits%64);
        while (lenr!=1 && r[lenr-1] == UINT64_C(0xffffffffffffffff)) lenr--;
    }
}

inline std::intptr_t uniformSigned(std::size_t n)
{   std::size_t lenr = n/64+1;
    std::size_t save = lenr;
    std::uint64_t* r = reserve(lenr);
    uniformSigned(r, lenr, n);
    return confirmSize(r, save, lenr);
}

inline std::size_t bignumBits(const std::uint64_t* a, std::size_t lena);

// Generate a value in the range 0 .. a-1 using a uniform distribution

inline void uniformUpto(std::uint64_t* a, std::size_t lena,
                        std::uint64_t* r,
                        std::size_t &lenr)
{   std::size_t n = bignumBits(a, lena);
// I will repeatedly generate numbers that have as many bits as a until
// I get one that has a value less than a has. On average that should only
// take two tries.
    for (;;)
    {   uniformPositive(r, lenr, n);
        if (lena > lenr) return;
        for (std::size_t len=lena;;)
        {   len--;
            if (a[len] > r[len]) return;
            if (a[len] < r[len] || len == 0) break;
        }
    }
}

inline std::intptr_t uniformUpto(std::intptr_t aa)
{   if (storedAsFixnum(aa))
    {   Digit r = uniformUint64(static_cast<Digit>
                                         (intOfHandle(
                                              aa)));
        return intToHandle(r);
    }
    std::uint64_t* a = vectorOfHandle(aa);
    std::size_t lena = numberSize(a);
    std::uint64_t* r = reserve(lena);
    std::size_t lenr;
    uniformUpto(a, lena, r, lenr);
    return confirmSize(r, lena, lenr);
}

inline void truncatePositive(const std::uint64_t* r, std::size_t &n)
{   while (r[n-1]==0 && n>1 && positive(r[n-2])) n--;
}

inline void truncateNegative(const std::uint64_t* r, std::size_t &n)
{   while (r[n-1]==allbits && n>1 && negative(r[n-2])) n--;
}

inline void truncateUnsigned(const std::uint64_t* r, std::size_t &n)
{   while (r[n-1]==0 && n>1) n--;
}

// The following is a rather strange function. It looks at the 4 bit number n.
// It then processes its input a in accordance with the following table, where
// A is the (positive) input value and X is A rounded down to the nearest
// power of 2 less than it (ie keeping just the top bit of A):
//
//    0   X-1                     8   -(X-1)
//    1   X                       9   -X
//    2   X+1                    10   -(X+1)
//    3   A                      11   -A
//    4   A                      12   -A
//    5   A                      13   -A
//    6   A                      14   -A
//    7   A                      15   -A

// The idea behind this is that the input A will be a random value from a
// reasonably smooth distribution, and n will be a random 4 bit value. The
// output will still be random, but now half the time it will be negative.
// And a significant proportion of the time it will be a power of 2 (or one
// either side of being a power of 2). This last is something I want because
// with an internal representation that is based on 2s complement values
// close to powers of 2 can easily be "edge cases" that deserve extra attention
// during testing.

inline void fudgeDistribution(const std::uint64_t* a,
                              std::size_t lena,
                              std::uint64_t* r, std::size_t &lenr, int n)
{   lenr = lena;
    switch (n&7)
    {   case 0:
        case 1:
        case 2:
            for (std::size_t i=0; i<lena+1; i++) r[i] = 0;
            if (a[lena-1] == 0)
            {   if (lena>1) r[lena-2] = 1ULL<<63;
            }
            else r[lena-1] = 1ULL << (63-nlz(a[lena-1]));
            if ((n&7) == 0) // decrement it
            {   if (lena!=1 || a[0]!=0) // avoid decrementing zero.
                {   std::uint64_t* p = r;
                    while (*p == 0)* p++ = static_cast<Digit>(-1);
                    (*p)--;
                }
            }
            else if ((n&7) == 2) // increment it
            {   std::uint64_t* p = r;
                while (*p == static_cast<Digit>(-1))* p++ = 0;
                (*p)++;
            }
            break;
        default:
            for (std::size_t i=0; i<lena; i++) r[i] = a[i];
            break;
    }
    if ((n&8) != 0)
    {   Digit carry = 1;
        for (std::size_t i=0; i<lena+1; i++)
        {   carry = addWithCarry(~r[i], carry, r[i]);
        }
        truncateNegative(r, lenr);
    }
    else truncatePositive(r, lenr);
}

inline std::intptr_t fudgeDistribution(std::intptr_t aa, int n)
{   std::uint64_t* a;
    std::size_t lena;
    Digit w[2];
    if (storedAsFixnum(aa))
    {   w[1] = static_cast<Digit>(intOfHandle(aa));
        lena = 1;
        a = &w[1];
    }
    else
    {   a = vectorOfHandle(aa);
        lena = numberSize(a);
    }
    std::uint64_t* r = reserve(lena+1);
    std::size_t lenr;
    fudgeDistribution(a, lena, r, lenr, n);
    return confirmSize(r, lena+1, lenr);
}

// Generate a value in the range 0 .. 2^bits-1 using a distribution such
// numbers with each bit-length are equally probable. This works by
// selecting a big-length uniformly and then creating a number uniformly
// distributed across all those with that exact bit-width. This is perhaps
// not a very nice distribution from a mathematical perspective, but is is
// nevertheless a useful one to have in some test code.

inline void randomUptoBits(std::uint64_t* r, std::size_t &lenr,
                           std::size_t n)
{   std::size_t bits = static_cast<std::size_t>(uniformUint64(n));
    if (bits == 0)
    {   r[0] = 0;
        lenr = 1;
        return;
    }
// The number will have from 1 to 64 bits in its top digit.
    lenr = (bits+63)/64;
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mersenne_twister();
    if (n%64 != 0)
        r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (64-bits%64);
    r[lenr-1] |= UINT64_C(1) << ((bits-1)%64);
    if (bits%64 == 0) r[lenr++] = 0;
}

inline std::intptr_t randomUptoBits(std::size_t bits)
{   std::size_t m = 1+bits/64;
    if (m == 0) m = 1;
    std::uint64_t* r = reserve(m);
    std::size_t lenr;
    randomUptoBits(r, lenr, bits);
    return confirmSize(r, m, lenr);
}

//=========================================================================
//=========================================================================
// Here I have a few tiny conversion functions followed by code for
// conversion between big numbers and strings. All of these are rather
// important for getting data in and out of the big number format and so
// deserve to be shown early.
//=========================================================================
//=========================================================================


// Convert a 64-bit integer to a bignum.
// This can be useful when there is no special-purpose code to
// perform arithmetic between a bignum and a native int64_t integer
// directly.

inline void intToBignum(SignedDigit n, std::uint64_t* r)
{   r[0] = static_cast<Digit>(n);
}

inline std::intptr_t intToBignum(SignedDigit n)
{   if (fitsIntoFixnum(n)) return intToHandle(n);
    std::uint64_t* r = reserve(1);
    intToBignum(n, r);
    return confirmSize(r, 1, 1);
}

inline void unsignedIntToBignum(Digit n, std::uint64_t* r,
                                std::size_t &lenr)
{   r[0] = n;
    if (negative(n))
    {   r[1] = 0;
        lenr = 2;
    }
    else lenr = 1;
}

inline std::intptr_t unsignedIntToBignum(Digit n)
{   std::size_t w = (negative(n) ? 2 : 1);
    std::uint64_t* r = reserve(w);
    std::size_t lenr;
    unsignedIntToBignum(n, r, lenr);
    return confirmSize(r, w, lenr);
}

// The next two pass an 128-bit value as two 64-bit words.

inline std::intptr_t int128ToBignum(SignedDigit high, Digit low)
{   if (high == 0 &&
        !negative(low) &&
        fitsIntoFixnum(static_cast<std::intptr_t>(low)))
        return intToHandle(static_cast<std::intptr_t>(low));
    else if (high == -1 &&
        negative(low) &&
        fitsIntoFixnum(static_cast<std::intptr_t>(low)))
        return intToHandle(static_cast<std::intptr_t>(low));
    std::uint64_t* r = reserve(2);
    r[0] = low;
    r[1] = static_cast<std::uintptr_t>(high);
    return confirmSize(r, 2, 2);
}

inline std::intptr_t unsignedInt128ToBignum(Digit  high,
                                            Digit low)
{   if (high == 0 &&
        !negative(low) &&
        fitsIntoFixnum(static_cast<std::intptr_t>(low)))
        return intToHandle(static_cast<std::intptr_t>(low));
    else if (high == 0xffffffffffffffffu &&
        negative(low) &&
        fitsIntoFixnum(static_cast<std::intptr_t>(low)))
        return intToHandle(static_cast<std::intptr_t>(low));
    else if (!negative(high))
    {   std::uint64_t* r = reserve(2);
        r[0] = low;
        r[1] = static_cast<std::uintptr_t>(high);
        return confirmSize(r, 2, 2);
    }
    std::uint64_t* r = reserve(3);
    r[0] = low;
    r[1] = static_cast<std::uintptr_t>(high);
    return confirmSize(r, 2, 2);
}

#ifdef softfloat_h
// Some constants that are useful when I am dealing with float128_t.

#if HAVE_Q_LITERALS

// Observe that use of the "_Q" suffix is somewhat delicate, since the
// literal generated a QuadFloat and one then needs to access its "v"
// field to obtain the float128_t value. And the whitespace before ".v"
// seems to be necessary. Also there are parenthese so that the "-" sign is
// handled as part of the syntax of the literal.

inline float128_t
    f128_0      = 0_Q .v,
    f128_half   = 0.5_Q .v,
    f128_mhalf  = (-0.5_Q) .v,
    f128_1      = 1.0_Q .v,
    f128_m1     = (-1.0_Q) .v,
    f128_N1     = 1.04438888141315250669175271071662438258e1223_Q .v;// 2^4096

#else // HAVE_Q_LITERALS
#ifdef LITTLEENDIAN
inline float128_t
f128_0      = {{0, INT64_C(0x0000000000000000)}},
f128_half   = {{0, INT64_C(0x3ffe000000000000)}},
f128_mhalf  = {{0, INT64_C(0xbffe000000000000)}},
f128_1      = {{0, INT64_C(0x3fff000000000000)}},
f128_m1     = {{0, INT64_C(0xbfff000000000000)}},
f128_N1     = {{0, INT64_C(0x4fff000000000000)}}; // 2^4096
#else // !LITTLEENDIAN
inline float128_t
f128_0      = {{INT64_C(0x0000000000000000), 0}},
f128_half   = {{INT64_C(0x3ffe000000000000), 0}},
f128_mhalf  = {{INT64_C(0xbffe000000000000), 0}},
f128_1      = {{INT64_C(0x3fff000000000000), 0}},
f128_m1     = {{INT64_C(0xbfff000000000000), 0}},
f128_N1     = {{INT64_C(0x4fff000000000000), 0}};
#endif // !LITTLEENDIAN
#endif // HAVE_Q_LITERALS

// The following tests are not supported by the version of softfloat that
// I am using, so I implement them myself.

inline bool f128_zero(float128_t p)
{   return (p.v[HIPART] & 0x7fffffffffffffff) == 0 &&
           p.v[LOPART] == 0;
}

inline bool f128_infinite(float128_t p)
{   return (p.v[HIPART] & 0x7fffffffffffffff) == 0x7fff000000000000 &&
           p.v[LOPART] == 0;
}

inline bool f128_nan(float128_t p)
{   return (p.v[HIPART] & 0x7fff000000000000) == 0x7fff000000000000 &&
           ((p.v[HIPART] & 0x0000ffffffffffff) != 0 ||
            p.v[LOPART] != 0);
}

inline float128_t ldexp(float128_t p, int x)
{   if (f128_zero(p) ||
        f128_infinite(p) ||
        f128_nan(p)) return p;  // special cases!
// Calculate the value I expect to want to leave in the exponent field.
    x = ((p.v[HIPART] >> 48) & 0x7fff) + x;
// In case of overflow leave an infinity of the right sign. This involves
// forcing all bits of the exponent to be 1, all bits of the mantissa to be
// zero and leaving the sign bit unaltered.
    if (x >= 0x7fff)
    {   p.v[HIPART] |= INT64_C(0x7fff000000000000);
        p.v[HIPART] &= INT64_C(0xffff000000000000);
        p.v[LOPART] = 0;
        return p;
    }
// Using ldexp() to decrease an expeonent can lead to underflow. The value
// 0 in x here would be the exponent one below that of the smallest
// normal number, so a value < -114 corresponds to a number so much smaller
// that it would not even qualify as a sub-norm. But even in that case
// I need to preserve the sign bit.
    else if (x < -114)
    {   p.v[HIPART] &= INT64_C(
                           0x8000000000000000); // preserve sign of input
        p.v[LOPART] = 0;
        return p;
    }
// In the case that ldexp underflows I have to be especially careful
// because of the joys of sub-normal numbers and gradual underflow.
// I deal with this by first forcing the exponent to be one that will
// not lead to a sub-norm and then using a multiply to scale it down.
    if (x <= 0)
    {   p.v[HIPART] = (p.v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                      (static_cast<Digit>(x+4096) << 48);
        p = f128_div(p, f128_N1);
    }
    else p.v[HIPART] = (p.v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                           (static_cast<Digit>(x) << 48);
    return p;
}

inline float128_t frexp(float128_t p, int &x)
{   if (f128_zero(p) ||
        f128_infinite(p) ||
        f128_nan(p))
    {   x = 0;
        return p;
    }
    int px = ((p.v[HIPART] >> 48) & 0x7fff);
// If I had a sub-normal number I will multiply if by 2^4096 before
// extracting its exponent. Doing that will have turned any non-zero
// sub-norm into a legitimate normalized number while not getting large
// enough to risk overflow...
    if (px == 0)
    {   p = f128_mul(p, f128_N1);
        px = ((p.v[HIPART] >> 48) & 0x7fff) - 4096;
    }
// Now I can set the exponent field such that the resulting number is in
// the range 0.5 <= p < 1.0.
    p.v[HIPART] = (p.v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                  (static_cast<Digit>(0x3ffe) << 48);
// .. and adjust the exponent value that I will return so it is if the
// scaled mantissa is now exactly the same as the input.
    x = px - 0x3ffe;
    return p;
}

// return fractional part and set i to integer part. Since this is in C++
// I can use a reference argument for i now a pointer and I can overload the
// vanilla name "modf" along the style of the way C++11 does.

inline float128_t modf(float128_t d, float128_t &i)
{   i = d;
// Extract the exponent
    int x = ((d.v[HIPART] >> 48) & 0x7fff) - 0x3ffe;
// If |d| < 1.0 then the integer part is zero.
    if (x <= 0) i = f128_0;
// Next look at cases where the integer part will life entirely within
// the high word.
    else if (x <= 49)   // 49 not 48 because of hidden bit.
    {   i.v[HIPART] &=
            ASR(static_cast<SignedDigit>(0xffff000000000000), x-1);
        i.v[LOPART] = 0;
    }
    else if (x <= 112)
    {   i.v[LOPART] &= (-1ULL) << (113-x);
    }
// If the number is large enough then then it is its own integer part, and
// the fractional part will be zero.
    else return f128_0;
    return f128_sub(d, i);
}

#endif // softfloat_h

// When doubles (and float128_t values where available) are to be
// compared against a bignum to get proper results the double should
// (at least in effect) be converted to a bignum. If one does the comparison
// by converting both inputs to floating point (which may feel easier) there
// are multiple problems. First the bignum might have a value outside
// the range of floats, so you get overflow. Then it might differ from
// a float in a bit position several hundred betlow its most significant
// one, and converting to a float would lose that information.

// doubleToBits() turns a floating point value into an integer plus
// an exponent. It sets mantissa*2^exponent = d. This function will not
// give sensible output if passed an infinity or a NaN and so they should be
// filtered out before it is called.

inline void doubleToBits(double d, SignedDigit &mantissa, int &exponent)
{   if (d == 0.0)
    {   mantissa = 0;
        exponent = 0;
        return;
    }
    int x;
    d = std::frexp(d, &x);
// now |d| is in the range [0.5,1) -- note closed at the 0.5 end and open
// at the other. And x is the power of 2 that the original input was scaled
// by to achieve this.
    d = d*9007199254740992.0; // 2^53;
// The conversion to an integer here will always be exact.
    mantissa = static_cast<SignedDigit>(d);
    exponent = x - 53;
}

// There are places where I need to shift a 128 or 192-bit number that is
// represented using several int64 values...

inline void shiftleft(SignedDigit &hi, Digit &lo, int n)
{   if (n == 0) return;
    else if (n < 64)
    {   hi = ASL(hi, n) | (lo >> (64-n));
        lo = lo << n;
    }
    else if (n == 64)
    {   hi = lo;
        lo = 0;
    }
    else
    {   hi = lo << (n-64);
        lo = 0;
    }
}

inline void shiftleft(SignedDigit &hi, Digit &mid,
                      Digit &lo,
                      int n)
{   if (n == 0) return;
    else if (n < 64)
    {   hi = ASL(hi, n) | (mid >> (64-n));
        mid = (mid << n) | (lo >> (64-n));
        lo = lo << n;
    }
    else if (n == 64)
    {   hi = mid;
        mid = lo;
        lo = 0;
    }
    else if (n < 128)
    {   hi = (mid << (n-64)) | (lo >> (128-n));
        mid = lo << (n-64);
        lo = 0;
    }
    else if (n == 128)
    {   hi = lo;
        mid = lo = 0;
    }
    else
    {   hi = lo << (n-128);
        mid = lo = 0;
    }
}

inline void shiftright(SignedDigit &hi, Digit &lo, int n)
{   if (n == 0) return;
    else if (n < 64)
    {   lo = (lo >> n) | ASL(hi, 64-n);
        hi = ASR(hi, n);
    }
    else if (n == 64)
    {   lo = hi;
        hi = hi<0 ? -1 : 0;
    }
    else
    {   lo = ASR(hi, n-64);
        hi = hi<0 ? -1 : 0;
    }
}

// This next sets top and next to the two top 64-bit digits for a bignum,
// and len to the length (measured in words) of that bignum. For values
// |d| < 2^63 top will hold the signed value, len==1 and next will
// in fact be irrelevant. This should be seen as a special degenerate case.
// Whenever len>1 on output the number should be such that to make a bignum
// with value to match the float you append len-2 zero words.
// Note that for inputs in 2^63 <= d < 2^64 the result will have top==0
// and next the integer value of d, with len==2. Something similar applies
// in the equivalent negative range. The leading 0 or -1 is required in those
// cases.
//
// In the case that the floating point input is small its value may lie
// between two integers, and in that case I adjust it in the sense of ROUND,
// TRUNC, FLOOR or CEILING. I will pass an extra argument to explain which
// I require.

enum RoundingMode {ROUND, TRUNC, FLOOR, CEILING};

inline void doubleTo_virtualBignum(double d,
                                   SignedDigit &top, Digit &next,
                                   std::size_t &len,
                                   RoundingMode mode)
{   if (d == 0.0)
    {   top = next = 0;
        len = 1;
        return;
    }
// NaN leads to a returned value with zero length. Having a zero length
// for a bignum is invalid, so this marks the situation well.
    else if (std::isnan(d))
    {   top = next = 0;
        len = 0;
        return;
    }
// Infinties turn into values with maximum length and a top digit that
// captures the sign of the input.
    if (std::isinf(d))
    {   top = d < 0.0 ? -1 : 1;
        next = 0;
        len = SIZE_MAX;
        return;
    }
// If the (absolute) value is less than 2^53 I will need to consider
// rounding, but the result would not need multiple bignum digits and I
// can work with it here using simple 64-bit integers. But I will
// need to consider rounding modes since there could be a significant
// fractional part.
    if (d >= -2.0/DBL_EPSILON && d <= 2.0/DBL_EPSILON)
    {   int64_t i = static_cast<int64_t>(d);           // can leave a fraction
        double fracpart = d - static_cast<double>(i);  // will be exact
        if (fracpart != 0.0)
        {   switch (mode)
            {   case ROUND:
                    if (fracpart > 0.5 ||
                        (fracpart == 0.5 && (i&1) != 0)) i++;
                    else if (fracpart < -0.5 ||
                        (fracpart == -0.5 && (i&1) != 0)) i--;
                    break;
                case TRUNC:  // already truncated
                    break;
                case FLOOR:
                    if (d < 0.0) i--;
                    break;
                case CEILING:
                    if (d > 0.0) i++;
                    break;
            }
        }
        top = i;
        next = 0;
        len = 1;
        return;
    }
// From here down I do not need to worry about zero, infinity or NaNs,
// and there will be no rounding!
    SignedDigit mantissa;
    int exponent;
    doubleToBits(d, mantissa, exponent);
// Now I know intpart(d) = mantissa*2^exponent and mantissa is an integer.
    Digit lowbit = mantissa & -static_cast<Digit>
                           (mantissa);
    int lz = 63 - nlz(lowbit); // low zero bits
    mantissa = ASR(mantissa, lz);
    exponent += lz;
// Now mantissa has its least significant bit a "1".
    next = static_cast<Digit>(mantissa);
    top = d<0.0 && mantissa!=0 ? -1 : 0;
    if (exponent < 0)
    {   top = 0;
        len = 1;
    }
    else
    {   len = 2 + exponent/64;
        exponent = exponent%64;
// Now shift left by exponent, which is less than 64 here.
        shiftleft(top, next, exponent);
// In some cases this has still left all the bits I care about in next,
// with top not needed, so in such cases I will shrink by a word.
        if (shrinkable(top, next))
        {   top = next;
            next = 0;
            len--;
        }
        if (len <= 0)       // small enough that fixed part is zero.
        {   top = next = 0;
            len = 1;
        }
    }
}

#ifdef softfloat_h

// For float128_t the mantissa needs to be returned as a 128-bit integer, and
// I do that as a pair of 64-bit integers here. Infinities and NaNs would
// lead to nonsense output. Subnormal numbers are got wrong at present!

inline void float128ToBits(float128_t d,
                           SignedDigit &mhi, Digit &mlo,
                           int &exponent)
{   if (f128_nan(d) || f128_zero(d))
    {   mhi = mlo = 0;
        exponent = 0;
        return;
    }
    else if (f128_infinite(d))
    {   if (f128_lt(d, f128_0)) mhi = mlo = -1;
        else mhi = mlo = 0;
        exponent = INT_MAX;
        return;
    }
// With float128_t the easier way to go is to access the bit-patterns.
    exponent = ((d.v[HIPART] >> 48) & 0x7fff);
    if (exponent == 0) // subnormal number
    {   d = f128_mul(d, f128_N1);
        exponent -= 4096;
    }
    exponent -= 0x3ffe;
    mhi = (d.v[HIPART] & 0xffffffffffff) | 0x0001000000000000;
    mlo = d.v[LOPART];
    if (static_cast<SignedDigit>(d.v[HIPART]) < 0)
    {   mlo = -mlo;
        if (mlo == 0) mhi = -mhi;
        else mhi = ~mhi;
    }
    exponent -= 113;
}

inline void inc128(SignedDigit &hi, Digit &lo)
{   if (++lo == 0) hi++;
}

inline void dec128(SignedDigit &hi, Digit &lo)
{   if (lo-- == 0) hi--;
}

// For a float128_t value I need to generate (up to) 3 64-bit digits for
// the way it would end up as a bignum.

inline void float128To_virtualBignum(float128_t d,
                                     SignedDigit &top,
                                     Digit &mid,
                                     Digit &next,
                                     std::size_t &len,
                                     RoundingMode mode)
{   if (f128_zero(d))
    {   top = mid = next = 0;
        len = 1;
        return;
    }
    else if (f128_nan(d))
    {   top = mid = next = 0;
        len = 0;
        return;
    }
    else if (f128_infinite(d))
    {   if (f128_lt(d, f128_0)) top = mid = next = -1;
        else top = mid = next = 0;
        len = SIZE_MAX;
        return;
    }
    bool sign = f128_negative(d);
    SignedDigit mhi;
    Digit mlo;
    int exponent;
    float128ToBits(d, mhi, mlo, exponent);
// Here (mhi,mlo) is a 113-bit integer that must be multiplied by
// 2^exponent to yield the input value.
    uint128_t mantissa = (static_cast<uint128_t>(mhi)<<64) | mlo;
    if (exponent < 0)   // There is a fractional part to consider  
    {
// The number might have been well 
        uint128_t fracpart = exponent  < -113 ? static_cast<uint128_t>(1)
                                              : mantissa << (113+exponent);
        switch (mode)
        {   case ROUND:
                if (fracpart > 0x8000000000000000ULL ||
                    (fracpart == 0x8000000000000000 &&
                     (mantissa&1) != 0)) mantissa++;
                break;
            case TRUNC:  // the effect of modf is this already.
                break;
            case FLOOR:
                if (fracpart != 0 && f128_lt(d, f128_0)) mantissa++;
                break;
            case CEILING:
                if (fracpart != 0 && !f128_lt(d, f128_0)) mantissa++;
                break;
        }
        if (sign) mantissa = -mantissa;
        top = static_cast<int64_t>(mantissa>>64);
        mid = static_cast<uint64_t>(mantissa);
        next = 0;
        len = 2;
        if (shrinkable(top, next))
        {   top = next;
            next = 0;
            len--;
        }        
        return;
    }
    int lz;
    if (mlo != 0)
    {   Digit lowbit = mlo & (-mlo);
        lz = 63 - nlz(lowbit); // low zero bits
    }
    else
    {   Digit lowbit = mhi & (-static_cast<Digit>(mhi));
        lz = 64 + 63 - nlz(lowbit); // low zero bits
    }
    shiftright(mhi, mlo, lz);
    exponent += lz;
// Now I need to shift things left so that the number of trailing zeros
// to the right of my value is a multiple of 64. That may cause the
// mantissa to spread into parts of 3 words: (top, mid, next).
    next = mlo;
    mid = mhi;
    top = mhi<0 ? -1 : 0;
    if (exponent < 0)
    {   top = 0;
        len = 1;
    }
    else
    {   len = 3 + exponent/64;
        exponent = exponent%64;
        shiftleft(top, mid, next, exponent);
// In some cases this has still left all the bits I care about in next.
        if (shrinkable(top, mid))
        {   top = mid;
            mid = next;
            next = 0;
            len--;
        }
        if (shrinkable(top, mid))
        {   top = mid;
            mid = next;
            next = 0;
            len--;
        }
    }
}

#endif // softfloat_h

inline std::intptr_t doubleToInt(double d, RoundingMode mode)
{
// I return 0 if the input is a NaN or either +infinity or -infinity.
// This is somewhat arbitrary, but right now I am not minded to raise an
// exception.
    if (!std::isfinite(d) || d==0.0) return intToHandle(0);
    SignedDigit top;
    Digit next;
    std::size_t len;
    doubleTo_virtualBignum(d, top, next, len, mode);
    std::uint64_t* r = reserve(len);
    if (len == 1) r[0] = top;
    else
    {   for (std::size_t i=0; i<len-2; i++) r[i] = 0;
        r[len-1] = top;
        r[len-2] = next;
    }
    return confirmSize(r, len, len);
}

inline std::intptr_t roundDoubleToInt(double d)
{   return doubleToInt(d, RoundingMode::ROUND);
}

inline std::intptr_t truncDoubleToInt(double d)
{   return doubleToInt(d, RoundingMode::TRUNC);
}

inline std::intptr_t floorDoubleToInt(double d)
{   return doubleToInt(d, RoundingMode::FLOOR);
}

inline std::intptr_t ceilingDoubleToInt(double d)
{   return doubleToInt(d, RoundingMode::CEILING);
}

#ifdef softfloat_h

inline std::intptr_t float128ToInt(float128_t d, RoundingMode mode)
{   if (f128_zero(d) ||
        f128_infinite(d) ||
        f128_nan(d)) return intToHandle(0);
    SignedDigit top;
    Digit mid, next;
    std::size_t len;
    float128To_virtualBignum(d, top, mid, next, len, mode);
    std::uint64_t* r = reserve(len);
    if (len == 1) r[0] = top;
    else if (len == 2)
    {   r[1] = top;
        r[0] = mid;
    }
    else
    {   for (std::size_t i=0; i<len-3; i++) r[i] = 0;
        r[len-1] = top;
        r[len-2] = mid;
        r[len-3] = next;
    }
    return confirmSize(r, len, len);
}

inline std::intptr_t roundFloat128ToInt(float128_t d)
{   return float128ToInt(d, RoundingMode::ROUND);
}

inline std::intptr_t truncFloat128ToInt(float128_t d)
{   return float128ToInt(d, RoundingMode::TRUNC);
}

inline std::intptr_t floorFloat128ToInt(float128_t d)
{   return float128ToInt(d, RoundingMode::FLOOR);
}

inline std::intptr_t ceilingFloat128ToInt(float128_t d)
{   return float128ToInt(d, RoundingMode::CEILING);
}

#endif // softfloat_h

inline SignedDigit Int64_t::op(SignedDigit a)
{   return a;
}

inline SignedDigit Int64_t::op(std::uint64_t* a)
{   return static_cast<SignedDigit>(a[0]);
}

inline Digit Uint64_t::op(SignedDigit a)
{   return static_cast<Digit>(a);
}

inline Digit Uint64_t::op(std::uint64_t* a)
{   return a[0];
}

// A cast from a double to a float is entitled, by the C++ standard to
// make a system-defined choice as to whether to round up or down.
// I want to guarantee to follow IEEE round-to-nearest-with-tie-break-
// -to-even, and so I will write a messy function here to achieve that and
// hence end up with better portability.
//
// The two things I think are illustrated here are
// (1) How horrible this is!
// (2) That C++11 manages to provide enough facilities for me to implement it
//     in a manner that I believe is standards-conforming at least on IEEE
//     platforms with the rounding-style set normally.

inline float castTo_float(double d)
{
// If the argument is a NaN then return a NaN of type float.
    if (std::isnan(d)) return std::nanf("");
// In C++ a narrowing cast here where the result would be out of range gives
// undefined behaviour, so I need to filter that case first. I am going
// to allow double values that are up to FLT_MAX*(1+2^(-24)) to round
// down to FLT_MAX - beyond that lies overflow reported as HUGE_VALF which
// on all modern systems will be an IEEE infinity.
    double limit = static_cast<double>(FLT_MAX) +
                   static_cast<double>(FLT_MAX) /
                   static_cast<double>(0x1000000);
    if (d >= limit) return HUGE_VALF;
    else if (d <= -limit) return -HUGE_VALF;
    else if (d >= static_cast<double>(FLT_MAX)) return FLT_MAX;
    else if (d <= static_cast<double>(FLT_MIN)) return FLT_MIN;
// Now I am not going to get any overflow - whew.
    float r1 = static_cast<float>(d);
// If the conversion was exact I do not have anything more to do!
    if (static_cast<double>(r1) == d) return r1;
    double err1 = static_cast<double>(r1) - d;
    float r2;
    double err2;
// Now I am going to find the next consecutive floating point value (in
// the correct direction) so that r1 and r2 are two values with d between
// them.
    if (err1 > 0.0)
    {   r2 = std::nextafterf(r1, FLT_MIN);
        err2 = d - static_cast<double>(r2);
    }
    else
    {   r2 = std::nextafterf(r1, FLT_MAX);
        err2 = static_cast<double>(r2) - d;
        err1 = -err1;
    }
    if (err1 < err2) return r1;
    else if (err2 < err1) return r2;
// Here I am at a half-way point. Hah - can add my error to a candidate
// result and the rounding there will then follow the "rounding style" that
// is in force - which I jolly well expect to be IEEE!
    return (r1 < r2 ? r1 : r2) + static_cast<float>(err1);
}

// On Cygwin (at least) the std::ldexpf function that is part of C++11
// is hidden in the header file perhaps because of issues about thread
// safety in its implementation. I reason here that converting from a
// float to a double will never lose anything, then ldexp() can be used.
// The case back to a float can not introduxce rounding, but might notice
// overflow leading to a result that is an IEEE infinity.

inline float ldexpf(float a, int n)
{   return castTo_float(std::ldexp(static_cast<double>(a), n));
}

inline float Float::op(SignedDigit a)
{
// if |a| < 2^52 I can convert to a double exactly
    if (a > -0x10000000000000 && a < 0x10000000000000)
        return castTo_float(static_cast<double>(a));
    SignedDigit hi  = a & 0xfffffc0000000000;   // 22 bits
    SignedDigit mid = a & 0x000003fffff00000;   // 22 bits
    SignedDigit lo  = a & 0x00000000000fffff;   // 20 bits
    if (hi == 0 || hi == 0xfffffc000000000)
        return castTo_float(static_cast<double>(hi) +
                             static_cast<double>(mid) + static_cast<double>(lo));
// This next line will move a ">0.5ulp" case so that it is visible
// within just the high 44 bits.  This is because the whole number can
// only be a 0.5ulp case if all the bits below the top 24 are zero, and
// for that to happen certainly the low 20 bits must all be zero...
    if (lo != 0) mid |= 1;
    return castTo_float(static_cast<double>(hi) +
                         static_cast<double>(mid));
}

inline float Float::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Float::op(static_cast<SignedDigit>(a[0]));
// Now I need to do something similar to that done for the int64_t case
// but written larger. Specifically I want to split my input number into
// its top 24 bits and then all the rest. I will take separate paths
// for the positive and negative cases.
    Digit top24;
    int lz;
    bool sign = false;
    Digit top, next;
    bool carried = true;
    for (std::size_t i=0; i<lena-2; i++)
    {   if (a[i] != 0)
        {   carried = false;
            break;
        }
    }
// Grap the top 128 bits of the number as {top,next}.
    top = a[lena-1];
    next = a[lena-2];    // lena >= 2 here
// Take its absolute value.
    if (negative(top))
    {   sign = true;
        top = ~top;
        next = ~next;
        if (carried)
        {   next++;
            if (next == 0) top++;
        }
    }
    if (!carried) next |= 1;
// Now I need to do something very much like the code for the int64_t case.
    if (top == 0) lz = nlz(next) + 64;
    else lz = nlz(top);
//
//  uint64_t top24 = {top,next} >> (128-24-lz);
    int sh = 128-24-lz;
// Note that sh can never be zero here.
    if (sh < 64) top24 = (next >> sh) | (top << (64-sh));
    else top24 = top >> (sh-64);
//
//  {top,next} = {top,next} << lz+24; // keep only the fraction bits
    sh = lz+24;
    if (sh < 64)
    {   top = (top << sh) | (next >> (64-sh));
        next = next << sh;
    }
    else
    {   top = next << (sh - 64);
        next = 0;
    }
//
//  if ({top,next} > 0x80000000000000000000000000000000U) top24++;
//  else if ({top,next} == 0x80000000000000000000000000000000U)
//      top24 += (top24 & 1);
    if (top > 0x8000000000000000U) top24++;
    else if (top == 0x8000000000000000U)
    {   if (next != 0) top24++;
        else top24 += (top24&1);
    }
    double d = static_cast<float>(top24);
    if (sign) d = -d;
    return ldexpf(d, static_cast<int>(128-24-lz+64*(lena-2)));
}

inline double Frexp::op(SignedDigit a, SignedDigit &x)
{
// The bad news here is that I am not confident that C++ will guarantee
// to round large integer values in any particular way when it converts
// them to floating point. So I will take careful action so that the
// conversions that I do are ones that will be exact, and I will perform
// rounding in IEEE style myself.
// First I will see if the value is small enough that I can work directly.
    const SignedDigit range = 1LL<<53;
    if (a >= -range && a <= range) return static_cast<double>(a);
// I will now drop down to a sign and magnitude representation
    bool sign = a < 0;
    Digit top53 = sign ? -static_cast<Digit>(a) : a;
// Because top53 >= 2^53 the number of leading zeros in its representation is
// at most 10. Ha ha. That guaranteed that the shift below will not overflow
// and is why I chose my range as I did.
    int lz = nlz(top53);
    Digit low = top53 << (lz+53);
    top53 = top53 >> (64-53-lz);
    if (low > 0x8000000000000000U) top53++;
    else if (low == 0x8000000000000000U) top53 += (top53 &
                1); // round to even
// The next line should never introduce any rounding at all.
    double d = static_cast<double>(top53);
    if (sign) d = -d;
    x =64-53-lz;
    return d;
}

inline double Double::op(SignedDigit a)
{
// One would obviously like to go "return (double)a;" however C++ says
//  "If the value being converted is in the range of values that can
//   be represented but the value cannot be represented exactly, it is
//   an implementation-defined choice of either the next lower or higher
//   representable value."
// and I feel I should guarantee to round in IEEE style. I can do that
// by splitting the integer into two parts. Each of the two casts can deliver
// a double precision result without need for rounding
    SignedDigit hi = a & 0xffffffff00000000;
    SignedDigit lo = a & 0x00000000ffffffff;
    double d = static_cast<double>(lo);
    return d + static_cast<double>(hi);
}

inline double Frexp::op(std::uint64_t* a, SignedDigit &x)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Frexp::op(static_cast<SignedDigit>(a[0]), x);
// Now I need to do something similar to that done for the int64_t case
// but written larger. Specifically I want to split my input number into
// its top 53 bits and then all the rest. I will take separate paths
// for the positive and negative cases.
    Digit top53;
    int lz;
    bool sign = false;
    Digit top, next;
    bool carried = true;
    for (std::size_t i=0; i<lena-2; i++)
    {   if (a[i] != 0)
        {   carried = false;
            break;
        }
    }
// Grap the top 128 bits of the number as {top,next}.
    top = a[lena-1];
    next = a[lena-2];    // lena >= 2 here
// Take its absolute value.
    if (negative(top))
    {   sign = true;
        top = ~top;
        next = ~next;
        if (carried)
        {   next++;
            if (next == 0) top++;
        }
    }
    if (!carried) next |= 1;
// Now I need to do something very much like the code for the int64_t case.
    if (top == 0) lz = nlz(next) + 64;
    else lz = nlz(top);
//
//  uint64_t top53 = {top,next} >> (128-53-lz);
    int sh = 128-53-lz;
// Note that sh can never be zero here.
    if (sh < 64) top53 = (next >> sh) | (top << (64-sh));
    else top53 = top >> (sh-64);
//
//  {top,next} = {top,next} << lz+53; // keep only the fraction bits
    sh = lz+53;
    if (sh < 64)
    {   top = (top << sh) | (next >> (64-sh));
        next = next << sh;
    }
    else
    {   top = next << (sh - 64);
        next = 0;
    }
//
//  if ({top,next} > 0x80000000000000000000000000000000U) top53++;
//  else if ({top,next} == 0x80000000000000000000000000000000U)
//      top53 += (top53 & 1);
    if (top > 0x8000000000000000U) top53++;
    else if (top == 0x8000000000000000U)
    {   if (next != 0) top53++;
        else top53 += (top53&1);
    }
    double d = static_cast<double>(top53);
    if (sign) d = -d;
    x = 128-53-lz+64*(lena-2);
    return d;
}

inline double Double::op(std::uint64_t* a)
{   SignedDigit x = 0;
    double d = Frexp::op(a, x);
    if (x > 10000) x = 10000;
    return std::ldexp(d, static_cast<int>(x));
}

#ifdef softfloat_h

inline float128_t Float128::op(SignedDigit a)
{   return i64_to_f128(a);
}

inline float128_t Frexp128::op(SignedDigit a, SignedDigit &x)
{   float128_t d = i64_to_f128(a), d1;
    int xi = 0;
    f128_frexp(d, &d1, &xi); // in the CSL sources.
    x = xi;
    return d1;
}

inline float128_t Frexp128::op(std::uint64_t* a, SignedDigit &x)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Float128::op(static_cast<SignedDigit>(a[0]));
    Digit top113, top113a;
    int lz;
    bool sign = false;
    Digit top, next1, next2;
    bool carried = true;
    for (std::size_t i=0; i<lena-3; i++)
    {   if (a[i] != 0)
        {   carried = false;
            break;
        }
    }
// Grap the top 192 bits of the number as {top,next}.
    top = a[lena-1];
    next1 = a[lena-2];
    next2 = lena==2 ? 0 : a[lena-3];
// Take its absolute value.
    if (negative(top))
    {   sign = true;
        top = ~top;
        next1 = ~next1;
        next2 = ~next2;
        if (carried)
        {   next2++;
            if (next2 == 0)
            {   next1++;
                if (next1 == 0) top++;
            }
        }
    }
    if (!carried) next2 |= 1;
// I now have {top,next1,next2} the top 192 bits of my integer. top may be
// zero, but if it is then next1 will have its top bit set, and so within
// these bits I certainly have the 113 that I need to obtain an accurate
// floating point value.
    if (top == 0) lz = nlz(next1) + 64;
    else lz = nlz(top);
//
//  uint64_t {top113,top112a} = {top,next1,next2} >> (128-113-lz);
    int sh = 192-113-lz;
// Note that sh can never be zero here.
    if (sh < 64)
    {   top113 = (next1 >> sh) | (top << (64-sh));
        top113a = (next2 >> sh) | (next1 << (64-sh));
    }
    else
    {   top113 = top >> (sh-64);
        top113a = (next1 >> (sh-64)) | (top << (128-sh));
    }
//
//  {top,next} = {top,next} << lz+113; // keep only the fraction bits
    sh = lz+113;
    if (sh < 64)
    {   top = (top << sh) | (next1 >> (64-sh));
        next1 = (next1 << sh) | (next2 >> (64-sh));
        next2 = next2 << sh;
    }
    else
    {   top = next1 << (sh - 64);
        next1 = (next1 << (sh-64)) | (next2 >> (129-sh));
        next2 = 0;
    }
//
//  if ({top,next1,next2} > 0x80000000000000000000000000000000U) top113++;
//  else if ({top,next1, next2} == 0x80000000000000000000000000000000U)
//      top113 += (top113 & 1);
    if (top > 0x8000000000000000U)
    {   top113a++;
        if (top113a == 0) top113++;
    }
    else if (top == 0x8000000000000000U)
    {   if (next1 != 0 || (next1==0 && next2!=0))
        {   top113a++;
            if (top113a == 0) top113++;
        }
        else top113 += addWithCarry(top113a, top113a&1, top113a);
    }
//  float128_t d = i64_to_f128({top113, top113a});
    float128_t d = i64_to_f128(top113);
    float128_t two32 = i64_to_f128(0x100000000);
    d = f128_add(f128_mul(f128_mul(two32, two32), d),
                 ui64_to_f128(top113a));
    if (sign) d = f128_sub(i64_to_f128(0), d);
    x = 192-113-lz+64*(lena-2);
    return d;
}

inline float128_t Float128::op(std::uint64_t* a)
{   SignedDigit x = 0;
    float128_t d = Frexp128::op(a, x);
    if (x > 100000) x = 100000;
// There is an implementation of ldexp() for 128-bit floats in
// the CSL source file float128_t,h.
    f128_ldexp(&d, static_cast<int>(x));
    return d;
}

#endif // softfloat_t

inline const Digit ten19 = UINT64_C(10000000000000000000);

inline std::intptr_t stringToBignum(const char* s)
{   bool sign = false;
    if (*s == '-')
    {   sign = true;
        s++;
    }
    std::size_t chars = std::strlen(s);
    std::size_t words = 1 + (108853*static_cast<Digit>
                             (chars))/0x200000;
// I have predicted the number of 64-bit digits that will be needed to
// represent an s-digit (decimal) number based an approximation
// 108853/2^21 for log(10)/log(2^64). In 64-bit arithmetic the numerator
// here will not overflow until you have an improbable string of length
// 2^47 as input! The division by a power of 2 should be done very
// rapidly as a shift. I rather expect this calculation to give a rather
// good measure of how many 64-bit words will be needed! It must never be an
// overestimate so that the vector that I allocate never overflows. Somewhat
// rarely it will be and overestimate and it will be necessary to trim the
// vector at the end.
    std::uint64_t* r = reserve(words);
    for (std::size_t i=0; i<words; i++) r[i] = 0;
// Now for each chunk of digits NNNN in the input I want to go in effect
//     r = 10^19*r + NNNN;
// where the number 19 is used because 10^19 is the largest power of 10
// that fits in a 64-bit word.
    std::size_t next = 19*((chars-1)/19);
    while (chars != 0)
    {   Digit d = 0;
// assemble 19 digit blocks from the input into a value (d).
        while (chars != next)
        {   d = 10*d + (*s++ - '0');
            chars--;
        }
        next -= 19;
// now perform r = 10^19*r + d to consolidate into the eventual result.
        for (std::size_t i=0; i<words; i++)
            multiply64(r[i], ten19, d, d, r[i]);
    }
    std::size_t n1 = words;
// Here I may be negating a positive number, and in 2s complement that
// can never lead to a number growing in length.
    if (sign)
    {   internalNegate(r, words, r);
        truncateNegative(r, n1);
    }
// However I could not have been precisely certain how many 64-bit words were
// needed and I arranged that any error was conservative - ie allocating
// more that would eventually be used.
    else truncatePositive(r, n1);
    return confirmSize(r, words, n1);
}

// The next functions are a key one for printing values. They convert a
// bignum so that it is still stored as a sequence of digits each within
// a 64-bit work, but now each digit will be be in the range 0 - (10^19-1)
// so that the value is in effect represented base 10^19. From that state
// printing it in decimal becomes easy!


// This first one takes a number represented base 2^64 with digits
// 0 to n-1 and divides it by 10^19, returning the remainder and
// setting both the digits and its length suitably to be the quotient.
// The number is POSITIVE here. Note that the function overwrites its input
// with the quotient.


inline Digit short_divide_ten_19(std::uint64_t* r,
                                         std::size_t &n)
{   Digit hi = 0;
    std::size_t i=n-1;
    for (;;)
    {   divide64(hi, r[i], ten19, r[i], hi);
        if (i == 0) break;
        i--;
    }
    if (r[n-1] == 0) n--;
    return hi;
}

// How many bits are there in a bignum?

// Note that if a bignum occupies over 1/8 of your total memory that
// the number of bits it uses might overflow size_t. On a 32-bit system
// this might happen if the number occupies over 512 Mbytes and I view
// that as a situation I will accept as a limit for 32-bit platforms.

inline std::size_t bignumBits(const std::uint64_t* a, std::size_t lena)
{   if (lena == 0 && a[0] == 0) return 1; // say that 0 has 1 bit.
    Digit top = a[lena-1];  // top digit.
// The exact interpretation of "the length in bits of a negative number"
// is something I need to think through. Well Common Lisp counts the
// number of bits apart from the sign bit, so we have
//      n      bignumBits(n)   bignumBits(-n)
//      0           0                0
//      1           1    1           0 ..11111:
//      2           2   10           1 ..1111:0
//      3           2   11           2 ..111:01
//      4           3  100           2 ..111:00
//      7           3  111           3 ..11:001
//      8           4 1000           3 ..11:000
    if (negative(top))
    {   Digit carry = 1;
        for (std::size_t i=0; i<lena; i++)
        {   top = ~a[i] + carry;
            carry = (top < carry);
        }
        top--;
    }
    return 64*(lena-1) + (top==0 ? 0 : 64-nlz(top));
}

// I want an estimate of the number of bytes that it will take to
// represent a number when I convert it to a string.
//
// I will work through an example. Consider the input 12024932 = 0xb77c64.
// [I use this value because at one time it revealed a mistake I had made!]
// This value uses 24 bits, ie its value is at least 2^23 (8388608) and
// it is less than 2^26 (16777216). log10(2^24) is 7.2247... so in decimal
// the number will use 7.2 digits, well that must be rounded up to 8.
// log10(2^24) = 24*log10(2) = 24*0.301030.. < 24*(617/2048) [because that
// fraction = 0.30127.. > log10(2)]. So if one the number of decimal digits
// that can be generated will be ceil(24*617/2048). I will compute that by
// forming a quotient that is truncated towards zero and then adding 1, and
// in this case this yields 8 as required. For negative numbers I will add 1
// to allow for a "-" sign.

inline std::size_t predictSize_in_bytes(const std::uint64_t* a,
                                        std::size_t lena)
{
// I am first going to estimate the size in BITS and then I will
// see how that maps onto bytes.
    std::size_t r = bignumBits(a, lena);
    r = 1 + static_cast<std::size_t>(
            (617*static_cast<Digit>(r))/2048);
    if (negative(a[lena-1])) r += 2; // allow space for a "-" sign.
    return r;
}

inline std::size_t bignumToStringLength(std::uint64_t* a, std::size_t lena)
{   if (lena == 1)
    {   SignedDigit v = a[0];
// Note that the negative numbers checked against are 1 digit shorter so as
// to allow space for the "-" sign.
        if (v <= 9999999 && v >= -999999) return 7;
        else if (v <= 999999999999999 && v >= -99999999999999) return 15;
        else return 23;
    }
    else return predictSize_in_bytes(a, lena);
}

// The "asUnsigned" option here is not for general use - it is JUST for
// internal debugging because at times I work with values that are known
// to be positive and so where the top digit must be treated as unsigned...

inline std::size_t bignumToString(char* result, std::size_t m,
                                  std::uint64_t* a, std::size_t lena,
                                  bool asUnsigned=false)
{
// Making one-word numbers a special case simplifies things later on! It may
// also make this case go just slightly faster.
    if (lena == 1)
    {   Digit v = a[0];
        bool sign;
        if (negative(v) && !asUnsigned)
        {   sign = true;
            v = -v;
        }
        else sign = false;
        char buffer[24];
        std::size_t len = 0;
        while (v != 0)
        {   buffer[len++] = '0' + v%10;
            v = v/10;
        }
// Now I have the decimal digits on the number in my buffer, with the
// least significant first and the most significant last. Insert the sign bit
// if needed (and deal with the special case of zero).
        if (sign) buffer[len++] = '-';
        else if (len == 0) buffer[len++] = '0';
        for (std::size_t i=0; i<len; i++) result[i] = buffer[len-i-1];
        return len;
    }
// The size (m) for the block of memory that I put my result in is
// such that it could hold the string representation of my input, and
// I estimate that via predictSize_in_bytes(). Well the smallest bignum
// that will need 2 words will be {0,0x8000000000000000}, ie 2^63. That
// will need 19 decimal digits plus space for a sign bit, so there will be
// at least 20 bytes allocated for the printed representation of any 2-word
// bignum, and at least 40 for a 3-word value, at least 59 for a 4-word one
// etc. This means that the space I will allocate here for the result
// leaves me with plenty of workspace to use while constructing the
// output string. The case liable to be tightest will be that of the
// smallest 2-woed bignum, so if I ensure that is OK all the rest will
// certainly be safe.
//
// I am going to build up (decimal) digits of the converted number by
// repeatedly dividing by 10^19. Each time I do that the remainder I
// amd left with is the next low 19 decimal digits of my number. Doing the
// divisions needs a vector to store the number I am dividing by 10^19 and
// to put the quotient, and I do not want to corrupt my original input, so
// I will copy my input into a fresh vector. And I will force it to be
// positive. The made-positive version might have a leading digit with
// its top bit set - that will not worry me because I view it as unsigned.
//
// I have allocated the space that will be needed for the eventual string of
// characters. I will use that space to save numeric values along the way, so
// here I cast so I can use that same memory as a vector of 64-bit integers.
// I will only ever access data in the format that it was placed into memory!
// Note that this will assume that the string data was allocated so as to
// be aligned suitably for uint64_t values.
    std::uint64_t* r = reinterpret_cast<std::uint64_t*>(result);
    std::size_t i;
// For the edge case lena==2 and m==20. I copy 2 words across. That will leave
// 4 bytes unused.
    for (i=0; i<lena; i++) r[i] = a[i];
    for (; i<m/sizeof(Digit); i++) r[i] = 0;
// Make the number positive
    bool sign = false;
    if (negative(r[lena-1]) && !asUnsigned)
    {   sign = true;
        internalNegate(r, lena, r);
    }
// Now my number is positive and is of length lena, but the vector it is
// stored in is length m with m usefully larger than lena. I will repeatedly
// divide by 10^19 and each time I do that I can store the remainder working
// down from the top of the vector. That should JUST keep up so that I
// never overwrite digits of the reducing part! I will stop when the
// number I have been working with end up < 10^19.
    std::size_t p = m/sizeof(Digit)
                    -1; // where to put next output digit
// Each value written into the vector here will stand for 19 decimal
// digits, and will use 8 bytes. So here the nastiest case will be when the
// number of decimal digits to end up with is 7 mod 8 (so that I lose as
// much space as possible) and the number is as large as possible. My
// belief is that numbers from 10^16 upwards will lead to there being enough
// space.
    while (lena > 1 || r[0] > ten19)
    {   Digit d = short_divide_ten_19(r, lena);
        r[p--] = d;
    }
    r[p] = r[0];
// Now I have the data that has to go into my result as a sequence of
// digits base 10^19, with the most significant one first. Convert
// to character data. I write in the string data just over what has been
// digits data, and I have arranged to position everything to (just)
// avoid overwriting myself.
    Digit top = r[p++];
    if (top == 0) top = r[p++]; // discard potential leading zero!
// Get a pointer into the buffer as character data...
    char* p1 = reinterpret_cast<char*>(result);
    std::size_t len = 0;
    if (sign)
    {  * p1++ = '-';
        len = 1;
    }
// I am going to convert my numbers to decimal using explicit code here.
// in an earlier draft I used sprintf(), however that adds unnecessary
// overhead.
    char buffer[24];
    int bp = 0;
// The first part of the number is printed naturally so that it only
// uses as many bytes of output as it needs.
    do
    {   buffer[bp++] = '0' + top%10;
        top = top/10;
    }
    while (top != 0);
    do
    {  * p1++ = buffer[--bp];
        len++;
    }
    while (bp != 0);
    while (p < m/sizeof(Digit))
    {
// I will always pick up the number I am going to expand before writing any
// digits into the buffer.
        top = r[p++];
// For subsequent chunks I want to print exactly 19 decimal digits.
        for (std::size_t i=0; i<18; i++)
        {   p1[18-i] = '0' + top%10;
            top = top/10;
        }
       * p1 = '0' + static_cast<int>(top);
        p1 += 19;
        len += 19;
    }
// To convince myself that this is safe consider when I pick up the final
// chunk. It will turn into 19 bytes of output, so where it comes from must
// be no more than 19 bytes before the length (m) of the final string, because
// otherwise it would have got clobbered when I unpacked the previous chunk.
// But this final chunk is itself 8 bytes wide and there can be up to 7 bytes
// beyond it that are there to support proper alignment - so that last chunk
// lives within the final 15 bytes of the buffer and that is a fortiori within
// the last 19 as required.
    return len;
}

inline string_handle bignumToString(std::uint64_t* a,
                                    std::size_t lena,
                                    bool asUnsigned=false)
{   std::size_t len = bignumToStringLength(a, lena);
    char* s = reserveString(len);
    std::size_t final_len = bignumToString(s, len, a, lena,
                            asUnsigned);
    return confirmSizeString(s, len, final_len);
}

inline string_handle bignumToString(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t lena;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);   // This is sort of faking a 1-digit bignum
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        lena = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        lena = numberSize(a);
    }
    return bignumToString(a, lena);
}

// As well as converting to decimal I can do hex, octal or binary!

inline std::size_t bignumToStringHexLength(std::intptr_t aa)
{   std::size_t n = IntegerLength::op(aa);
    return (n+3)/4;
}

inline string_handle bignumToStringHex(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t n;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        n = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        n = numberSize(a);
    }
// Making the value zero a special case simplifies things later on!
    if (n == 1 && a[0] == 0)
    {   char* r = reserveString(1);
        std::strcpy(r, "0");
        return confirmSizeString(r, 1, 1);
    }
// printing in hexadecimal should be way easier!
    std::size_t m = 16*n;
    Digit top = a[n-1];
    bool sign = negative(top);
    if (sign)
    {   m += 2; // for "~f"
        while ((top>>60) == 0xf)
        {   top = top << 4;
            m--;
        }
    }
    else
    {   while (top == 0)
        {   n--;
            top = a[n-1];
        }
        while ((top>>60) == 0)
        {   top = top << 4;
            m--;
        }
    }
    char* r = reserveString(m);
    char* p = reinterpret_cast<char*>(r);
    top = a[n-1];
    if (sign)
    {  * p++ = '~';
       * p++ = 'f';
    }
    bool started = false;
    for (std::size_t i=0; i<n; i++)
    {   Digit v = a[n-i-1];
        for (int j=0; j<16; j++)
        {   int d = static_cast<int>(v >> (60-4*j)) & 0xf;
            if (!started)
            {   if ((sign && d==0xf) ||
                    (!sign && d==0)) continue;
                started = true;
            }
           * p++ = "0123456789abcdef"[d];
        }
    }
    return confirmSizeString(r, m, p-reinterpret_cast<char*>(r));
}

inline std::size_t bignumToStringOctalLength(std::intptr_t aa)
{   std::size_t n = IntegerLength::op(aa);
    return (n+2)/3;
}

inline string_handle bignumToStringOctal(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t n;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        n = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        n = numberSize(a);
    }
    std::size_t width = (64*n +
                         2)/3; // raw number of octal digits needed.
    Digit top = a[n-1];
    bool sign = negative(top);
// There is a slight misery in that 64 is not a multiple of 3 (!) and so
// the octal representation of a value has some digits that depend on a pair
// of adjacent words from the bignum.
    std::size_t
    nn;  // will be the number of characters used in the output
    if (sign)
    {   while (readU3(a, n, width-1) == 7 && width > 1) width--;
        nn = width+2;
    }
    else
    {   while (readU3(a, n, width-1) == 0 && width > 1) width--;
        nn = width;
    }
    char* r = reserveString(nn);
    char* p = reinterpret_cast<char*>(r);
    if (sign)
    {  * p++ = '~';
       * p++ = '7';
    }
    for (std::size_t i=0; i<width; i++)
       * p++ = '0' + readU3(a, n, width-i-1);
    return confirmSizeString(r, nn, p-reinterpret_cast<char*>(r));
}

inline std::size_t bignumToStringBinaryLength(std::intptr_t aa)
{   return IntegerLength::op(aa);
}

inline string_handle bignumToStringBinary(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t n;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        n = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        n = numberSize(a);
    }
// Making the value zero a special case simplifies things later on!
    if (n == 1 && a[0] == 0)
    {   char* r = reserveString(1);
        std::strcpy(r, "0");
        return confirmSizeString(r, 1, 1);
    }
    std::size_t m = 64*n;
    Digit top = a[n-1];
    bool sign = negative(top);
    if (sign)
    {   m += 2; // for "~1"
        while ((top>>63) == 1)
        {   top = top << 1;
            m--;
        }
    }
    else
    {   if (top == 0) m -= 64;
        else while ((top>>63) == 0)
        {   top = top << 1;
            m--;
        }
    }
    char* r = reserveString(m);
    char* p = r;
    top = a[n-1];
    if (sign)
    {  * p++ = '~';
       * p++ = '1';
    }
    bool started = false;
    for (std::size_t i=0; i<n; i++)
    {   Digit v = a[n-i-1];
        for (int j=0; j<64; j++)
        {   int d = static_cast<int>(v >> (63-j)) & 0x1;
            if (!started)
            {   if ((sign && d==1) ||
                    (!sign && d==0)) continue;
                started = true;
            }
           * p++ = '0' + d;
        }
    }
    return confirmSizeString(r, m, p-reinterpret_cast<char*>(r));
}

//=========================================================================
//=========================================================================
// Big number comparisons.
//=========================================================================
//=========================================================================


inline bool Zerop::op
(std::uint64_t* a)
{   return numberSize(a) == 1 && a[0] == 0;
}

inline bool Zerop::op(SignedDigit a)
{   return a == 0;
}

inline bool Onep::op(std::uint64_t* a)
{   return numberSize(a) == 1 && a[0] == 1;
}

inline bool Onep::op(SignedDigit a)
{   return a == 1;
}

inline bool Minusp::op(std::uint64_t* a)
{   return negative(a[numberSize(a)-1]);
}

inline bool Minusp::op(SignedDigit a)
{   return a < 0;
}

inline bool Plusp::op(std::uint64_t* a)
{   return !negative(a[numberSize(a)-1]); // NB a bignum can not be zero
}

inline bool Plusp::op(SignedDigit a)
{   return a > 0;
}

inline bool Evenp::op(std::uint64_t* a)
{   return (a[0] & 1) == 0;
}

inline bool Evenp::op(SignedDigit a)
{   return (a & 1) == 0;
}

inline bool Oddp::op(std::uint64_t* a)
{   return (a[0] & 1) != 0;
}

inline bool Oddp::op(SignedDigit a)
{   return (a & 1) != 0;
}

// eqn

inline bool bigeqn(const std::uint64_t* a, std::size_t lena,
                   const std::uint64_t* b, std::size_t lenb)
{   if (lena != lenb) return false;
    return std::memcmp(a, b, lena*sizeof(Digit)) == 0;
}


inline bool Eqn::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    return bigeqn(a, lena, b, lenb);
}

inline bool Eqn::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    return lena==1 && static_cast<SignedDigit>(a[0])==b;
}

inline bool Eqn::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    return lenb==1 && a==static_cast<SignedDigit>(b[0]);
}

inline bool Eqn::op(SignedDigit a, SignedDigit b)
{   return (a == b);
}

inline bool Eqn::op(SignedDigit a, float b)
{   return Eqn::op(a, static_cast<double>(b));
}

inline bool Eqn::op(std::uint64_t* a, float b)
{   return Eqn::op(a, static_cast<double>(b));
}

inline bool Eqn::op(float a, SignedDigit b)
{   return Eqn::op(static_cast<double>(a), b);
}

inline bool Eqn::op(float a, std::uint64_t* b)
{   return Eqn::op(static_cast<double>(a), b);
}

inline bool Eqn::op(SignedDigit a, double b)
{   const SignedDigit range = (1LL)<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) == b;
// The value on the next line is a floating point representation of 2^63,
// so any floating value at least that large is bigger than any int64_t value.
    if (b >= 9223372036854775808.0) return false;
    else if (b < -9223372036854775808.0) return false;
    if (std::isnan(b)) return false;
    return a == static_cast<SignedDigit>(b);
}

inline bool eqnfloat(std::uint64_t* a, std::size_t lena, double b)
{   if (std::isnan(b)||
        std::isinf(b)) return false;
    SignedDigit top = static_cast<SignedDigit>(a[lena-1]);
// If the signs differn than the values are certainly not equal.
    if (top >= 0 && b <= 0.0) return false;
    if (top < 0 && b >= 0.0) return false;
    double ipart;
    double fpart = std::modf(b, &ipart);
    if (fpart != 0.0) return false; // not an integer so not equal.
    SignedDigit hi;
    Digit next;
    std::size_t len;
    doubleTo_virtualBignum(ipart, hi, next, len, RoundingMode::TRUNC);
    if (len != lena) return false;
    if (len == 1) return a[0] == static_cast<Digit>(top);
    if (a[len-1] != static_cast<Digit>(top) ||
        a[len-2] != next) return false;
    for (std::size_t i=0; i<len-2; i++)
        if (a[i] != 0) return false;
    return true;
}

inline bool Eqn::op(std::uint64_t* a, double b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Eqn::op(static_cast<SignedDigit>(a[0]), b);
    return eqnfloat(a, lena, b);
}

inline bool Eqn::op(double a, SignedDigit b)
{   return Eqn::op(b, a);
}

inline bool Eqn::op(double a, std::uint64_t* b)
{   return Eqn::op(b, a);
}

#ifdef softfloat_h

// The following constants are 2^112 and -2^112 and their reciprocals, which
// are used in rationalf128 because any 128-bit floating point value that
// is that large is necessarily an exact integer.

#ifdef HAVE_Q_LITERALS

// Again note ugly parens around negative literal and the whitespace before
// the ".v".

inline float128_t FP128_INT_LIMIT =
    5192296858534827628530496329220096.0_Q .v;
inline float128_t FP128_MINUS_INT_LIMIT =
    (-5192296858534827628530496329220096.0_Q) .v;

#else // HAVE_Q_LITERALS

#ifdef LITTLEENDIAN

inline float128_t FP128_INT_LIMIT = {{0, INT64_C(0x406f000000000000)}};
inline float128_t FP128_MINUS_INT_LIMIT = {{0, INT64_C(0xc06f000000000000)}};

#else // !LITTLEENDIAN

inline float128_t FP128_INT_LIMIT = {{INT64_C(0x406f000000000000), 0}};
inline float128_t FP128_MINUS_INT_LIMIT = {{INT64_C(0xc06f000000000000), 0}};

#endif // !LITTLEENDIAN
#endif // HAVE_Q_LITERALS


inline bool eqnbigfloat(std::uint64_t* a, std::size_t lena, float128_t b)
{   if (!f128_eq(b, b)) return false;  // a NaN if b!=b
    SignedDigit top = static_cast<SignedDigit>(a[lena-1]);
    if (top >= 0 && f128_lt(b, f128_0)) return false;
    if (top < 0 && !f128_lt(b, f128_0)) return false;
// Now the two inputs have the same sign.
    if (lena == 1 ||
        (lena == 2 &&
         !((a[1] > 0x0001000000000000 ||
            (a[1] == 0x0001000000000000 && a[0] != 0)) ||
           static_cast<SignedDigit>(a[1]) < -static_cast<SignedDigit>
           (0x0001000000000000))))
    {
// Here the integer is of modest size - if the float is huge we can
// resolve matters cheaply.
        if (f128_lt(FP128_INT_LIMIT, b) ||
            f128_lt(b, FP128_MINUS_INT_LIMIT)) return false;
// Convert a to a float128 and compare. The conversion will not lose any
// information because the |a| <= 2^112 so it will fit within the mantissa
// bits that are available.
        float128_t aa = Float128::op(a);
        return f128_eq(aa, b);
    }
    else
    {
// Now the integer is rather big. If I was KEEN I would estimate the size of
// the float from its exponent and compare with the number of bits in the
// integer to filter out cases where their sized were very different. However
// I am not feeling very keen! I can afford to convert the float to an integer,
// and because it is large when I fix it there will not be any discarded
// fractional part...
        std::intptr_t bb = roundFloat128ToInt(b);
        return op_dispatch2<Eqn,bool>(vectorToHandle(a), bb);
    }
}

inline bool Eqn::op(SignedDigit a, float128_t b)
{   return f128_eq(i64_to_f128(a), b);
}

inline bool Eqn::op(std::uint64_t* a, float128_t b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Eqn::op(static_cast<SignedDigit>(a[0]), b);
    return eqnbigfloat(a, lena, b);
}

inline bool Eqn::op(float128_t a, SignedDigit b)
{   return Eqn::op(b, a);
}

inline bool Eqn::op(float128_t a, std::uint64_t* b)
{   return Eqn::op(b, a);
}

#endif // softfloat_h

inline bool Neqn::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    return !bigeqn(a, lena, b, lenb);
}

inline bool Neqn::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    return lena!=1 || static_cast<SignedDigit>(a[0])!=b;
}

inline bool Neqn::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    return lenb!=1 || a!=static_cast<SignedDigit>(b[0]);
}

inline bool Neqn::op(SignedDigit a, SignedDigit b)
{   return (a != b);
}

inline bool Neqn::op(SignedDigit a, float b)
{   return Neqn::op(a, static_cast<double>(b));
}

inline bool Neqn::op(std::uint64_t* a, float b)
{   return Neqn::op(a, static_cast<double>(b));
}

inline bool Neqn::op(float a, SignedDigit b)
{   return Neqn::op(static_cast<double>(a), b);
}

inline bool Neqn::op(float a, std::uint64_t* b)
{   return Neqn::op(static_cast<double>(a), b);
}

inline bool Neqn::op(SignedDigit a, double b)
{   const SignedDigit range = (1LL)<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) != b;
// The value on the next line is a floating point representation of 2^63,
// so any floating value at least that large is bigger than any int64_t value.
    if (b >= 9223372036854775808.0) return true;
    else if (b < -9223372036854775808.0) return true;
    if (std::isnan(b)) return false;   // Ha Ha Ha!
    return a != static_cast<SignedDigit>(b);
}

inline bool Neqn::op(std::uint64_t* a, double b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Neqn::op(static_cast<SignedDigit>(a[0]), b);
    return !eqnfloat(a, lena, b);
}

inline bool Neqn::op(double a, SignedDigit b)
{   return Neqn::op(b, a);
}

inline bool Neqn::op(double a, std::uint64_t* b)
{   return Neqn::op(b, a);
}

#ifdef softfloat_h

inline bool Neqn::op(SignedDigit a, float128_t b)
{   return !f128_eq(i64_to_f128(a), b);
}

inline bool Neqn::op(std::uint64_t* a, float128_t b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Neqn::op(static_cast<SignedDigit>(a[0]), b);
    return !eqnbigfloat(a, lena, b);
}

inline bool Neqn::op(float128_t a, SignedDigit b)
{   return Neqn::op(b, a);
}

inline bool Neqn::op(float128_t a, std::uint64_t* b)
{   return Neqn::op(b, a);
}

#endif // softfloat_h

// greaterp

inline bool biggreaterp(const std::uint64_t* a, std::size_t lena,
                        const std::uint64_t* b, std::size_t lenb)
{   Digit a0 = a[lena-1], b0 = b[lenb-1];
// If one of the numbers has more digits than the other then the sign of
// the longer one gives my the answer.
    if (lena > lenb) return positive(a0);
    else if (lenb > lena) return negative(b0);
// When the two numbers are the same length but the top digits differ
// then comparing those digits tells me all I need to know.
    if (static_cast<SignedDigit>(a0) >
        static_cast<SignedDigit>(b0)) return true;
    if (static_cast<SignedDigit>(a0) <
        static_cast<SignedDigit>(b0)) return false;
// Otherwise I need to scan down through digits...
    lena--;
    while (lena != 0)
    {   lena--;
        a0 = a[lena];
        b0 = b[lena];
        if (a0 > b0) return true;
        if (a0 < b0) return false;
    }
    return false;
}

// This version treats the two inputs as unsigned numbers. It is used from
// within the GCD code (at least)

inline bool bigUnsignedGreaterp(const std::uint64_t* a,
                                std::size_t lena,
                                const std::uint64_t* b, std::size_t lenb)
{
// If one of the numbers has more digits than the other then it is the
// larger.
    if (lena > lenb) return true;
    else if (lenb > lena) return false;
    while (lena != 0)
    {   lena--;
        Digit a0 = a[lena];
        Digit b0 = b[lena];
        if (a0 > b0) return true;
        if (a0 < b0) return false;
    }
    return false;
}

inline bool Greaterp::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    return biggreaterp(a, lena, b, lenb);
}

inline bool Greaterp::op(std::uint64_t* a, SignedDigit bb)
{   Digit b[1] = {static_cast<Digit>(bb)};
    std::size_t lena = numberSize(a);
    return biggreaterp(a, lena, b, 1);
}

inline bool Greaterp::op(SignedDigit aa, std::uint64_t* b)
{   Digit a[1] = {static_cast<Digit>(aa)};
    std::size_t lenb = numberSize(b);
    return biggreaterp(a, 1, b, lenb);
}

inline bool Greaterp::op(SignedDigit a, SignedDigit b)
{   return a > b;
}

// I can always widen a float to a double without loss of any information,
// so all the cases of comparisons with floats (as distinct from with
// double) are easy to delegate.

inline bool Greaterp::op(SignedDigit a, float b)
{   return Greaterp::op(a, static_cast<double>(b));
}

inline bool Greaterp::op(std::uint64_t* a, float b)
{   return Greaterp::op(a, static_cast<double>(b));
}

inline bool Greaterp::op(float a, SignedDigit b)
{   return Greaterp::op(static_cast<double>(a), b);
}

inline bool Greaterp::op(float a, std::uint64_t* b)
{   return Greaterp::op(static_cast<double>(a), b);
}

inline bool Greaterp::op(SignedDigit a, double b)
{
// If the integer is small enough it can be converted to a double
// without any rounding, so then I can do the comparison easily.
    const SignedDigit range = 1LL<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) > b;
// NaNs must always return false from a comparison, so all the cases so
// far will have yielded correct results. But here I must filter out
// that situation.
    if (std::isnan(b)) return false;
// If the floating point value is >= 2^63 or is less < -2^63 it is beyond
// the range of int64_t, so the result is easy. This situation includes
// the case of infinities.
    if (b >= 9223372036854775808.0) return false;
    else if (b < -9223372036854775808.0) return true;
// Because |b| >= 2^53 but < 2^63 it can be converted to an int64_t value
// without rounding.
    return a > static_cast<SignedDigit>(b);
}

// This compares a bignum against a double. It may in fact only be called
// in the case where it is at least a 2-word bignum, and that would render
// the first segment of code unnecessary!
//
// The code here feels ugly and perhaps repetitive to me. For now I will
// just be content to get something that works in all cases, but thinking
// about how to make it tidier will be desirable. I might perhaps also
// think if generalizing it to have EQN and NEQN options in the CompareMode
// enumeration.

enum CompareMode {GREATERP, GEQ, LESSP, LEQ};

inline bool greaterpfloat(std::uint64_t* a, std::size_t lena,
                          double b,
                          CompareMode mode)
{   if (std::isnan(b)) return false;
// If the integer is small enough it can be converted to a double
// without any rounding, so then I can do the comparison easily.
    if (lena == 1)
    {   SignedDigit aa = a[0];
        const SignedDigit range = (1LL)<<53;
        if (aa >= -range && aa <= range)
        {   double ad = static_cast<double>(aa);
            switch (mode)
            {   case CompareMode::GREATERP:
                    return static_cast<double>(ad) > b;
                case CompareMode::GEQ:
                    return static_cast<double>(ad) >= b;
                case CompareMode::LESSP:
                    return static_cast<double>(ad) < b;
                case CompareMode::LEQ:
                    return static_cast<double>(ad) <= b;
            }
        }
    }
// If b==+infinity then a<b and a<=b, while if b=-=infinity then
// a>b and a>=b.
    if (std::isinf(b))
    {   return (b > 0.0 && (mode==CompareMode::LESSP ||
                            mode==CompareMode::LEQ)) ||
               (b < 0.0 && (mode==CompareMode::GREATERP ||
                            mode==CompareMode::GEQ));
    }
// Also if a and b have different signs it is easy to resolve the issue.
    if (negative(a[lena-1]) && b >= 0.0)
        return (mode==CompareMode::LESSP || mode==CompareMode::LEQ);
    if (positive(a[lena-1]) && b <= 0.0)
        return (mode==CompareMode::GREATERP || mode==CompareMode::GEQ);
// Now if I convert b to an integer and compare I can lose a fractional
// part in the case when b is small. But given that |a| is large if I
// truncate b as I map it onto an integer the comparisons I make will still
// be valid.
    SignedDigit top;
    Digit next;
    std::size_t len;
    doubleTo_virtualBignum(b, top, next, len, RoundingMode::TRUNC);
// If the numbers now differ in length that can tell me what the result is.
    if (lena > len)
    {   if (negative(a[lena-1]))
            return (mode==CompareMode::LESSP || mode==CompareMode::LEQ);
        if (positive(a[lena-1]))
            return (mode==CompareMode::GREATERP || mode==CompareMode::GEQ);
    }
    if (lena < len)
    {   if (positive(a[lena-1]))
            return (mode==CompareMode::LESSP || mode==CompareMode::LEQ);
        if (negative(a[lena-1]))
            return (mode==CompareMode::GREATERP || mode==CompareMode::GEQ);
    }
// Now the arguments have the same length as bignums. First check for
// differences in the top two digits.
    if (static_cast<SignedDigit>(a[lena-1]) < top ||
        (static_cast<SignedDigit>(a[lena-1]) == top && a[lena-2] < next))
        return (mode==CompareMode::LESSP || mode==CompareMode::LEQ);
    if (static_cast<SignedDigit>(a[lena-1]) > top ||
        (static_cast<SignedDigit>(a[lena-1]) == top && a[lena-2] > next))
        return (mode==CompareMode::GREATERP || mode==CompareMode::GEQ);
// Now the top two digits of the two inputs match. If all lower digits of a
// are zero then the two inputs are equal.
    for (std::size_t i=0; i<len; i++)
    {   if (a[i] != 0) return (mode==CompareMode::GREATERP ||
                                   mode==CompareMode::GEQ);
    }
// Here the inputs seem to be exactly equal in value.
    return mode==CompareMode::GEQ || mode==CompareMode::LEQ;
}

inline bool Greaterp::op(std::uint64_t* a, double b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Greaterp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpfloat(a, lena, b, CompareMode::GREATERP);
}

inline bool Greaterp::op(double a, SignedDigit b)
{   return Lessp::op(b, a);
}

inline bool Greaterp::op(double a, std::uint64_t* b)
{   return Lessp::op(b, a);
}

#ifdef softfloat_h

//@@ This is not sorted out yet!

// This one function does >, >=, < and <= with "great" indicating if
// the base is > or < and "ifequal" distinguishing > from >= and < from <=.

inline bool greaterpbigfloat(std::uint64_t* a, std::size_t lena,
                             float128_t b,
                             bool great, bool ifequal)
{   if (f128_nan(b)) return
            false;  // Comparisons involving a NaN => false.
    SignedDigit top = static_cast<SignedDigit>(a[lena-1]);
    if (top >= 0 && f128_lt(b, f128_0)) return great;
    if (top < 0 && !f128_lt(b, f128_0)) return !great;
// Now the two inputs have the same sign.
    if (lena == 1 ||
        (lena == 2 &&
         !((a[1] > 0x0001000000000000 ||
            (a[1] == 0x0001000000000000 && a[0] != 0)) ||
           static_cast<SignedDigit>(a[1]) < -static_cast<SignedDigit>
           (0x0001000000000000))))
    {
// Here the integer is of modest size - if the float is huge we can
// resolve matters cheaply.
        if (f128_lt(FP128_INT_LIMIT, b)) return !great;
        if (f128_lt(b, FP128_MINUS_INT_LIMIT)) return great;
// Convert a to a float128 and compare. The conversion will not lose any
// information because the |a| <= 2^112 so it will fit within the mantissa
// bits that are available.
        float128_t aa = Float128::op(a);
        if (great)
        {   if (ifequal) return f128_le(b, aa);
            else return f128_lt(b, aa);
        }
        else
        {   if (ifequal) return f128_le(aa, b);
            else return f128_lt(aa, b);
        }
    }
    else
    {
// Now the integer is rather big. If I was KEEN I would estimate the size of
// the float from its exponent and compare with the number of bits in the
// integer to filter out cases where their sized were very different. However
// I am not feeling very keen! I can afford to convert the float to an integer,
// and because it is large when I fix it there will not be any discarded
// fractional part...
        // ...
        std::intptr_t bb = roundFloat128ToInt(b);
// At the moment I think there is a space-leak on bb here...
        if (great)
            if (ifequal)
                return op_dispatch2<Geq,bool>(vectorToHandle(a), bb);
            else return op_dispatch2<Greaterp,bool>(vectorToHandle(a), bb);
        else if (ifequal)
            return op_dispatch2<Leq,bool>(vectorToHandle(a), bb);
        else return op_dispatch2<Lessp,bool>(vectorToHandle(a), bb);
    }
}

inline bool Greaterp::op(SignedDigit a, float128_t b)
{   return f128_lt(b, i64_to_f128(a));
}

inline bool Greaterp::op(std::uint64_t* a, float128_t b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Greaterp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, true, false);

}

inline bool Greaterp::op(float128_t a, SignedDigit b)
{   return Lessp::op(b, a);
}

inline bool Greaterp::op(float128_t a, std::uint64_t* b)
{   return Lessp::op(b, a);
}

#endif // softfloat_h

// geq

inline bool Geq::op(std::uint64_t* a, std::uint64_t* b)
{   return !Greaterp::op(b, a);
}

inline bool Geq::op(std::uint64_t* a, SignedDigit b)
{   return !Greaterp::op(b, a);
}

inline bool Geq::op(SignedDigit a, std::uint64_t* b)
{   return !Greaterp::op(b, a);
}

inline bool Geq::op(SignedDigit a, SignedDigit b)
{   return a >= b;
}

inline bool Geq::op(SignedDigit a, float b)
{   return Geq::op(a, static_cast<double>(b));
}

inline bool Geq::op(std::uint64_t* a, float b)
{   return Geq::op(a, static_cast<double>(b));
}

inline bool Geq::op(float a, SignedDigit b)
{   return Geq::op(static_cast<double>(a), b);
}

inline bool Geq::op(float a, std::uint64_t* b)
{   return Geq::op(static_cast<double>(a), b);
}

inline bool Geq::op(SignedDigit a, double b)
{   const SignedDigit range = 1LL<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) >= b;
    if (std::isnan(b)) return false;
    if (b >= 9223372036854775808.0) return false;
    else if (b < -9223372036854775808.0) return true;
    return a >= static_cast<SignedDigit>(b);
}

inline bool Geq::op(std::uint64_t* a, double b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Geq::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpfloat(a, lena, b, CompareMode::GEQ);
}

inline bool Geq::op(double a, SignedDigit b)
{   return Leq::op(b, a);
}

inline bool Geq::op(double a, std::uint64_t* b)
{   return Leq::op(b, a);
}

#ifdef softfloat_h

inline bool Geq::op(SignedDigit a, float128_t b)
{   return f128_le(b, i64_to_f128(a));
    return false;
}

inline bool Geq::op(std::uint64_t* a, float128_t b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Greaterp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, true, true);
}

inline bool Geq::op(float128_t a, SignedDigit b)
{   return Leq::op(b, a);
}

inline bool Geq::op(float128_t a, std::uint64_t* b)
{   return Leq::op(b, a);
}

#endif // softfloat_h

// lessp

inline bool Lessp::op(std::uint64_t* a, std::uint64_t* b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(std::uint64_t* a, SignedDigit b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(SignedDigit a, std::uint64_t* b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(SignedDigit a, SignedDigit b)
{   return a < b;
}

inline bool Lessp::op(SignedDigit a, float b)
{   return Lessp::op(a, static_cast<double>(b));
}

inline bool Lessp::op(std::uint64_t* a, float b)
{   return Lessp::op(a, static_cast<double>(b));
}

inline bool Lessp::op(float a, SignedDigit b)
{   return Lessp::op(static_cast<double>(a), b);
}

inline bool Lessp::op(float a, std::uint64_t* b)
{   return Lessp::op(static_cast<double>(a), b);
}

inline bool Lessp::op(SignedDigit a, double b)
{   const SignedDigit range = 1LL<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) < b;
    if (std::isnan(b)) return false;
    if (b >= 9223372036854775808.0) return true;
    else if (b < -9223372036854775808.0) return false;
    return a < static_cast<SignedDigit>(b);
}

inline bool Lessp::op(std::uint64_t* a, double b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Lessp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpfloat(a, lena, b, CompareMode::LESSP);
}

inline bool Lessp::op(double a, SignedDigit b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(double a, std::uint64_t* b)
{   return Greaterp::op(b, a);
}

#ifdef softfloat_h

inline bool Lessp::op(SignedDigit a, float128_t b)
{   return f128_lt(i64_to_f128(a), b);
    return false;
}

inline bool Lessp::op(std::uint64_t* a, float128_t b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Lessp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, false, false);

    return false;
}

inline bool Lessp::op(float128_t a, SignedDigit b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(float128_t a, std::uint64_t* b)
{   return Greaterp::op(b, a);
}

#endif // softfloat_h

// leq

inline bool Leq::op(std::uint64_t* a, std::uint64_t* b)
{   return !Greaterp::op(a, b);
}

inline bool Leq::op(std::uint64_t* a, SignedDigit b)
{   return !Greaterp::op(a, b);
}

inline bool Leq::op(SignedDigit a, std::uint64_t* b)
{   return !Greaterp::op(a, b);
}

inline bool Leq::op(SignedDigit a, SignedDigit b)
{   return a <= b;
}

inline bool Leq::op(SignedDigit a, float b)
{   return Leq::op(a, static_cast<double>(b));
}

inline bool Leq::op(std::uint64_t* a, float b)
{   return Leq::op(a, static_cast<double>(b));
}

inline bool Leq::op(float a, SignedDigit b)
{   return Leq::op(static_cast<double>(a), b);
}

inline bool Leq::op(float a, std::uint64_t* b)
{   return Leq::op(static_cast<double>(a), b);
}

inline bool Leq::op(SignedDigit a, double b)
{   const SignedDigit range = 1LL<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) <= b;
    if (std::isnan(b)) return false;
    if (b >= 9223372036854775808.0) return true;
    else if (b < -9223372036854775808.0) return false;
    return a <= static_cast<SignedDigit>(b);
}

inline bool Leq::op(std::uint64_t* a, double b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Lessp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpfloat(a, lena, b, CompareMode::LEQ);
}

inline bool Leq::op(double a, SignedDigit b)
{   return Geq::op(b, a);
}

inline bool Leq::op(double a, std::uint64_t* b)
{   return Geq::op(b, a);
}

#ifdef softfloat_h

inline bool Leq::op(SignedDigit a, float128_t b)
{   return f128_le(i64_to_f128(a), b);
    return false;
}

inline bool Leq::op(std::uint64_t* a, float128_t b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Leq::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, false, true);
}

inline bool Leq::op(float128_t a, SignedDigit b)
{   return Geq::op(b, a);
}

inline bool Leq::op(float128_t a, std::uint64_t* b)
{   return Geq::op(b, a);
}

#endif // softfloat_h


// Negation, addition and subtraction. These are easy apart from a mess
// concerning the representation of positive numbers that risk having the
// most significant bit of their top word a 1, and the equivalent for
// negative numbers.
// Boolean operations all treat negative numbers as if there had been an
// unending string of 1 bits before the stop bit that is stored.
//=========================================================================
//=========================================================================


// Negation. Note that because I am using 2s complement the result could be
// one word longer or shorter than the input. For instance if you negate
// [0x8000000000000000] (a negative value) you get [0,0x8000000000000000],
// and vice versa.

inline void bignegate(const std::uint64_t* a, std::size_t lena,
                      std::uint64_t* r, std::size_t &lenr)
{   internalNegate(a, lena, r);
    r[lena] = negative(a[lena-1]) ? 0 : -1;
    lenr = lena+1;
    truncatePositive(r, lenr);
    truncateNegative(r, lenr);
}

inline std::intptr_t Minus::op(std::uint64_t* a)
{   std::size_t n = numberSize(a);
    std::uint64_t* p = reserve(n+1);
    std::size_t final_n;
    bignegate(a, n, p, final_n);
    return confirmSize(p, n+1, final_n);
}

// The following can only be called via op_dispatch1(), and in that
// case the argument has to have started off as a fixnum. In such cases
// the result will also be a fixnum except when negating MIN_FIXNUM. But
// even in that case (-a) can not overflow 64-bit arithmetic because
// the fixnum will have had at least one tag bit.

inline std::intptr_t Minus::op(SignedDigit a)
{   if (a == MIN_FIXNUM) return intToBignum(-a);
    else return intToHandle(-a);
}

inline std::intptr_t Add1::op(std::uint64_t* a)
{   return Plus::op(a, 1);
}

inline std::intptr_t Add1::op(SignedDigit a)
{   return intToBignum(a+1);
}

inline std::intptr_t Sub1::op(std::uint64_t* a)
{   return Plus::op(a, -1);
}

inline std::intptr_t Sub1::op(SignedDigit a)
{   return intToBignum(a-1);
}

inline std::intptr_t Abs::op(std::uint64_t* a)
{   std::size_t n = numberSize(a);
    if (!negative(a[n-1]))
    {   std::uint64_t* r = reserve(n);
            std::memcpy(r, a, n*sizeof(Digit));
        return confirmSize(r, n, n);
    }
    std::uint64_t* r = reserve(n+1);
    std::size_t final_n;
    bignegate(a, n, r, final_n);
    return confirmSize(r, n+1, final_n);
}

// The following can only be called via op_dispatch1(), and in that
// case the argument has to have started off as a fixnum. In such cases
// the result will also be a fixnum except when negating MIN_FIXNUM. But
// even in that case (-a) can not overflow 64-bit arithmetic because
// the fixnum will have had at least one tag bit.

inline std::intptr_t Abs::op(SignedDigit a)
{   if (a == MIN_FIXNUM) return unsignedIntToBignum(-a);
    else return intToHandle(a<0 ? -a : a);
}

// The "bitnot" operation is simple and length can not change.

inline void biglognot(const std::uint64_t* a, std::size_t lena,
                      std::uint64_t* r, std::size_t &lenr)
{   for (std::size_t i=0; i<lena; i++)
    {   r[i] = ~a[i];
    }
    lenr = lena;
}

inline std::intptr_t Lognot::op(std::uint64_t* a)
{   std::size_t n = numberSize(a);
    std::uint64_t* p = reserve(n+1);
    std::size_t final_n;
    biglognot(a, n, p, final_n);
    return confirmSize(p, n+1, final_n);
}

inline std::intptr_t Lognot::op(SignedDigit a)
{   return intToHandle(~a);
}

// logand

inline void ordered_biglogand(const std::uint64_t* a,
                              std::size_t lena,
                              const std::uint64_t* b, std::size_t lenb,
                              std::uint64_t* r, std::size_t &lenr)
{   for (std::size_t i=0; i<lenb; i++)
        r[i] = a[i] & b[i];
    if (negative(b[lenb-1]))
    {   for (std::size_t i=lenb; i<lena; i++) r[i] = a[i];
        lenr = lena;
    }
    else lenr = lenb;
    truncatePositive(r, lenr);
}

inline void biglogand(const std::uint64_t* a, std::size_t lena,
                      const std::uint64_t* b, std::size_t lenb,
                      std::uint64_t* r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogand(a, lena, b, lenb, r, lenr);
    else return ordered_biglogand(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logand::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    biglogand(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

// The next two are not optimised - a case of (logand bignum positive-fixnum)
// is guaranteed to end up a fixnum so could be done more slickly - however
// I am not going to expect that to be on the critical performance path for
// enough programs for me to worry too much!

inline std::intptr_t Logand::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    std::uint64_t* p = reserve(lena);
    std::size_t final_n;
    Digit bb[1] = {static_cast<Digit>(b)};
    biglogand(a, lena, bb, 1, p, final_n);
    return confirmSize(p, lena, final_n);
}

inline std::intptr_t Logand::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* p = reserve(lenb);
    std::size_t final_n;
    Digit aa[1] = {static_cast<Digit>(a)};
    biglogand(aa, 1, b, lenb, p, final_n);
    return confirmSize(p, lenb, final_n);
}

inline std::intptr_t Logand::op(SignedDigit a, SignedDigit b)
{   return intToHandle(a & b);
}

// logor

inline void ordered_biglogor(const std::uint64_t* a, std::size_t lena,
                             const std::uint64_t* b, std::size_t lenb,
                             std::uint64_t* r, std::size_t &lenr)
{   for (std::size_t i=0; i<lenb; i++)
        r[i] = a[i] | b[i];
    if (negative(b[lenb-1])) lenr = lenb;
    else
    {   for (std::size_t i=lenb; i<lena; i++) r[i] = a[i];
        lenr = lena;
    }
    truncateNegative(r, lenr);
}

inline void biglogor(const std::uint64_t* a, std::size_t lena,
                     const std::uint64_t* b, std::size_t lenb,
                     std::uint64_t* r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogor(a, lena, b, lenb, r, lenr);
    else return ordered_biglogor(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logor::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    biglogor(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t Logor::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    std::uint64_t* p = reserve(lena);
    std::size_t final_n;
    Digit bb[1] = {static_cast<Digit>(b)};
    biglogor(a, lena, bb, 1, p, final_n);
    return confirmSize(p, lena, final_n);
}

inline std::intptr_t Logor::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* p = reserve(lenb);
    std::size_t final_n;
    Digit aa[1] = {static_cast<Digit>(a)};
    biglogor(aa, 1, b, lenb, p, final_n);
    return confirmSize(p, lenb, final_n);
}

inline std::intptr_t Logor::op(SignedDigit a, SignedDigit b)
{   return intToHandle(a | b);
}

// logxor

inline void ordered_biglogxor(const std::uint64_t* a,
                              std::size_t lena,
                              const std::uint64_t* b, std::size_t lenb,
                              std::uint64_t* r, std::size_t &lenr)
{   std::size_t i;
    for (i=0; i<lenb; i++)
        r[i] = a[i] ^ b[i];
    if (negative(b[lenb-1]))
    {   for (; i<lena; i++)
            r[i] = ~a[i];
    }
    else
    {   for (; i<lena; i++)
            r[i] = a[i];
    }
    lenr = lena;
// The logxor operation can cause the inputs to shrink.
    truncatePositive(r, lenr);
    truncateNegative(r, lenr);
}

inline void biglogxor(const std::uint64_t* a, std::size_t lena,
                      const std::uint64_t* b, std::size_t lenb,
                      std::uint64_t* r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogxor(a, lena, b, lenb, r, lenr);
    else return ordered_biglogxor(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logxor::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    biglogxor(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t Logxor::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    std::uint64_t* p = reserve(lena);
    std::size_t final_n;
    Digit bb[1] = {static_cast<Digit>(b)};
    biglogxor(a, lena, bb, 1, p, final_n);
    return confirmSize(p, lena, final_n);
}

inline std::intptr_t Logxor::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* p = reserve(lenb);
    std::size_t final_n;
    Digit aa[1] = {static_cast<Digit>(a)};
    biglogxor(aa, 1, b, lenb, p, final_n);
    return confirmSize(p, lenb, final_n);
}

inline std::intptr_t Logxor::op(SignedDigit a, SignedDigit b)
{   return intToHandle(a ^ b);
}


inline void ordered_biglogeqv(const std::uint64_t* a,
                              std::size_t lena,
                              const std::uint64_t* b, std::size_t lenb,
                              std::uint64_t* r, std::size_t &lenr)
{   std::size_t i;
    for (i=0; i<lenb; i++)
        r[i] = ~a[i] ^ b[i];
    if (negative(b[lenb-1]))
    {   for (; i<lena; i++)
            r[i] = a[i];
    }
    else
    {   for (; i<lena; i++)
            r[i] = ~a[i];
    }
    lenr = lena;
// The logxor operation can cause the inputs to shrink.
    truncatePositive(r, lenr);
    truncateNegative(r, lenr);
}

inline void biglogeqv(const std::uint64_t* a, std::size_t lena,
                      const std::uint64_t* b, std::size_t lenb,
                      std::uint64_t* r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogeqv(a, lena, b, lenb, r, lenr);
    else return ordered_biglogeqv(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logeqv::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    biglogeqv(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t Logeqv::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    std::uint64_t* p = reserve(lena);
    std::size_t final_n;
    Digit bb[1] = {static_cast<Digit>(b)};
    biglogeqv(a, lena, bb, 1, p, final_n);
    return confirmSize(p, lena, final_n);
}

inline std::intptr_t Logeqv::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* p = reserve(lenb);
    std::size_t final_n;
    Digit aa[1] = {static_cast<Digit>(a)};
    biglogeqv(aa, 1, b, lenb, p, final_n);
    return confirmSize(p, lenb, final_n);
}

inline std::intptr_t Logeqv::op(SignedDigit a, SignedDigit b)
{   return intToHandle(~a ^ b);
}

inline void bigrightshift(const std::uint64_t* a, std::size_t lena,
                          SignedDigit n,
                          std::uint64_t* r, std::size_t &lenr);

inline void bigleftshift(const std::uint64_t* a, std::size_t lena,
                         SignedDigit n,
                         std::uint64_t* r, std::size_t &lenr)
{   if (n == 0)
    {   internalCopy(a, lena, r);
        lenr = lena;
        return;
    }
    else if (n < 0)
    {   bigrightshift(a, lena, -n, r, lenr);
        return;
    }
    std::size_t words = n/64;
    std::size_t bits = n % 64;
    for (std::size_t i=0; i<words; i++) r[i] = 0;
    if (bits == 0)
    {   for (std::size_t i=0; i<lena; i++)
            r[i+words] = a[i];
        lenr = lena+words;
    }
    else
    {   r[words] = a[0]<<bits;
        for (std::size_t i=1; i<lena; i++)
            r[i+words] = (a[i]<<bits) |
                         (a[i-1]>>(64-bits));
        r[words+lena] = (negative(a[lena-1]) ?
                         static_cast<Digit>(-1)<<bits :
                         0) | (a[lena-1]>>(64-bits));
        lenr = lena+words+1;
    }
    truncatePositive(r, lenr);
    truncateNegative(r, lenr);
}

inline std::intptr_t rightshift_b(std::uint64_t* a, SignedDigit n);

inline std::intptr_t LeftShift::op(std::uint64_t* a, SignedDigit n)
{   if (n == 0) return copyIfNoGarbageCollector(a);
    else if (n < 0) return RightShift::op(a, -n);
    std::size_t lena = numberSize(a);
    std::size_t nr = lena + (n/64) + 1;
    std::uint64_t* p = reserve(nr);
    std::size_t final_n;
    bigleftshift(a, lena, n, p, final_n);
    return confirmSize(p, nr, final_n);
}

inline std::intptr_t LeftShift::op(SignedDigit aa, SignedDigit n)
{   if (n == 0) return intToHandle(aa);
    else if (n < 0) return RightShift::op(aa, -n);
    std::size_t nr = (n/64) + 2;
    std::uint64_t* p = reserve(nr);
    std::size_t final_n;
    Digit a[1] = {static_cast<Digit>(aa)};
    bigleftshift(a, 1, n, p, final_n);
    return confirmSize(p, nr, final_n);
}

inline void bigrightshift(const std::uint64_t* a, std::size_t lena,
                          SignedDigit n,
                          std::uint64_t* r, std::size_t &lenr)
{   if (n == 0)
    {   internalCopy(a, lena, r);
        lenr = lena;
        return;
    }
    else if (n < 0)
    {   bigleftshift(a, lena, -n, r, lenr);
        return;
    }
    std::size_t words = n/64;
    std::size_t bits = n % 64;
    if (words >= lena)
    {   r[0] = negative(a[lena-1]) ? -1ULL : 0;
        lenr = 1;
    }
    else if (bits == 0)
    {   for (std::size_t i=0; i<lena-words; i++)
            r[i] = a[i+words];
        lenr = lena-words;
    }
    else
    {   for (std::size_t i=0; i<lena-words-1; i++)
            r[i] = (a[i+words]>>bits) |
                   (a[i+words+1]<<(64-bits));
        r[lena-words-1] = ASR(a[lena-1], bits);
        lenr = lena-words;
    }
    truncatePositive(r, lenr);
    truncateNegative(r, lenr);
}

inline std::intptr_t RightShift::op(std::uint64_t* a, SignedDigit n)
{   if (n == 0) return copyIfNoGarbageCollector(a);
    else if (n < 0) return LeftShift::op(a, -n);
    std::size_t lena = numberSize(a);
    std::size_t nr;
    if (lena > static_cast<std::size_t>(n)/64) nr = lena - n/64;
    else nr = 1;
    std::uint64_t* p = reserve(nr);
    std::size_t final_n;
    bigrightshift(a, lena, n, p, final_n);
    return confirmSize(p, nr, final_n);
}

inline std::intptr_t RightShift::op(SignedDigit a, SignedDigit n)
{   if (n == 0) return intToHandle(a);
    else if (n < 0) return LeftShift::op(a, -n);
// Shifts of 64 and up obviously lose all the input data apart from its
// sign, but so does a shift by 63.
    if (n >= 63) return intToHandle(a>=0 ? 0 : -1);
// Because C++ does not guarantee that right shifts on signed values
// duplicate the sign bit I perform the "shift" here using division by
// a power of 2. Because I have n <= 62 here I will not get overflow.
    SignedDigit q = 1LL<<n;
    return intToHandle((a & ~(q-1))/q);
}

inline Digit Low64Bits::op(std::uint64_t* a)
{   return a[0];
}

inline Digit Low64Bits::op(SignedDigit aa)
{   return static_cast<Digit>(aa);
}

inline std::size_t LowBit::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    if (negative(a[lena-1])) // count trailing 1 bits!
    {   std::size_t r=0, i=0;
        while (a[i++]==-1ULL) r += 64;
        Digit w = ~a[i-1];
        return 64-nlz(w & (-w))+r;
    }
    else if (lena==1 && a[0]==0) return 0;
    else
    {   std::size_t r=0, i=0;
        while (a[i++]==0) r += 64;
        Digit w = a[i-1];
        return 64-nlz(w & (-w))+r;
    }
}

inline std::size_t LowBit::op(SignedDigit aa)
{   Digit a;
    if (aa == 0) return 0;
    else if (aa < 0) a = ~static_cast<Digit>(aa);
    else a = aa;
    a = a & (-a); // keeps only the lowest bit
    return 64-nlz(a);
}

inline std::size_t IntegerLength::op(std::uint64_t* a)
{   return bignumBits(a, numberSize(a));
}

inline std::size_t IntegerLength::op(SignedDigit aa)
{   Digit a;
    if (aa == 0 || aa == -1) return 0;
    else if (aa < 0) a = -static_cast<Digit>(aa) - 1;
    else a = aa;
    return 64-nlz(a);
}

// This function should return the top 64-bits of an integer in the
// sense that the returned value should have its top bit (ie the
// 0x8000000000000000 bit) set, and the weight associated with that
// bit is as returned by IntegerLength. So this value plus IntegerLength
// sort of provide a normalised floating point renditition of the
// integer with this begin a 64-bit mantissa. This is only intended
// to be used on positive input values. If given a negative input it will
// return the whole of the top word of a bignum or the whole of a fixnum,
// viewing the leading 1 bits as important. The only intended use is
// as part of the process or converting an integer into a sign-and-magnitude
// "floating point" value with a 64-bit mantissa so I will not worry about
// that at the moment.

inline Digit Top64Bits::op(std::uint64_t* a)
{   size_t n = numberSize(a);
    if (n == 1 ||
        (n == 2 && a[2] == 0))
        return Top64Bits::op(static_cast<int64_t>(a[0]));
    if (a[n-1] == 0) n--;
    int lz = nlz(a[n-1]);
    if (lz == 0) return a[n-1];
    return (a[n-1] << lz) | (a[n-2] >> (64-lz));
}

inline Digit Top64Bits::op(SignedDigit a)
{   if (a == 0) return 0;    // Only non-normalised case
    return static_cast<uint64_t>(a) << nlz(a);
}

inline std::size_t Logcount::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    std::size_t r = 0;
    if (negative(a[lena-1]))
    {   for (std::size_t i=0; i<lena; i++) r += countBits(~a[i]);
    }
    else for (std::size_t i=0; i<lena; i++) r += countBits(a[i]);
    return r;
}

inline std::size_t Logcount::op(SignedDigit a)
{   if (a < 0) return countBits(~a);
    else return countBits(a);
}

inline bool Logbitp::op(std::uint64_t* a, std::size_t n)
{   std::size_t lena = numberSize(a);
    if (n >= 64*lena) return negative(a[lena-1]);
    return (a[n/64] & (1ULL << (n%64))) != 0;
}

inline bool Logbitp::op(SignedDigit a, std::size_t n)
{   if (n >= 64) return (a < 0);
    else return (a & (1ULL << n)) != 0;
}

// Addition when the length of a is art least than that of b.

inline void ordered_bigplus(const std::uint64_t* a, std::size_t lena,
                            const std::uint64_t* b, std::size_t lenb,
                            std::uint64_t* r, std::size_t &lenr)
{   Digit carry = 0;
    std::size_t i = 0;
// The lowest digits can be added without there being any carry-in.
    carry = addWithCarry(a[0], b[0], r[0]);
// Add the digits that (a) and (b) have in common
    for (i=1; i<lenb; i++)
        carry = addWithCarry(a[i], b[i], carry, r[i]);
// From there on up treat (b) as if it had its sign bit extended to the
// left.
    Digit topb = negative(b[lenb-1]) ? allbits : 0;
    for (; i<lena; i++)
        carry = addWithCarry(a[i], topb, carry, r[i]);
// And of course (a) must also be treated as being extended by its sign bit.
    Digit topa = negative(a[lena-1]) ? allbits : 0;
// The result calculated here is 1 word longer than (a), and addition
// can never carry further than that.
    r[i] = topa + topb + carry;
// However because I am using (2s complement) signed arithmetic the result
// could be shorter, so I will check for that and return the length that
// is actually needed.
    while (r[i]==0 && i>0 && positive(r[i-1])) i--;
    while (r[i]==allbits && i>0 && negative(r[i-1])) i--;
    lenr = i+1;
}

// Add a small number to a bignum

inline void bigplus_small(const std::uint64_t* a, std::size_t lena,
                          SignedDigit n,
                          std::uint64_t* r, std::size_t &lenr)
{   Digit w[1];
    w[0] = static_cast<Digit>(n);
    ordered_bigplus(a, lena, w, 1, r, lenr);
}

// When I do a general addition I will not know which input is longer.

inline void bigplus(const std::uint64_t* a, std::size_t lena,
                    const std::uint64_t* b, std::size_t lenb,
                    std::uint64_t* r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_bigplus(a, lena, b, lenb, r, lenr);
    else return ordered_bigplus(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Plus::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n;
    if (lena >= lenb) n = lena+1;
    else n = lenb+1;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    bigplus(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

// At present I implement the op_ii, opt_ib and opt_bi operations
// by converting the integer argument to a 1-word bignum and dropping into
// the general bignum code. This will generally be a long way from the
// most efficient implementation, so at a later stage I will want to hone
// the code to make it better!

inline std::intptr_t Plus::op(SignedDigit a, SignedDigit b)
{
// The two integer arguments will in fact each have been derived from a
// tagged representation, and a consequence of that is that I can add
// them and be certain I will not get arithmetic overflow. However the
// resulting value may no longer be representable as a fixnum.
    SignedDigit c = a + b;
    if (fitsIntoFixnum(c)) LIKELY return intToHandle(c);
// Now because there had not been overflow I know that the bignum will
// only need one word.
    std::uint64_t* r = reserve(1);
    r[0] = c;
    return confirmSize(r, 1, 1);
}

inline std::intptr_t Plus::op(SignedDigit a, std::uint64_t* b)
{   Digit aa[1];
    aa[0] = a;
    std::size_t lenb = numberSize(b);
    std::uint64_t* r = reserve(lenb+1);
    std::size_t final_n;
    bigplus(aa, 1, b, lenb, r, final_n);
    return confirmSize(r, lenb+1, final_n);
}

inline std::intptr_t Plus::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    Digit bb[1];
    bb[0] = b;
    std::uint64_t* r = reserve(lena+1);
    std::size_t final_n;
    bigplus(a, lena, bb, 1, r, final_n);
    return confirmSize(r, lena+1, final_n);
}

inline std::intptr_t bigplus_small(std::intptr_t aa, SignedDigit b)
{   std::uint64_t* a = vectorOfHandle(aa);
    std::size_t lena = numberSize(a);
    std::uint64_t* p = reserve(lena+1);
    std::size_t final_n;
    bigplus_small(a, lena, b, p, final_n);
    return confirmSize(p, lena+1, final_n);
}

// For subtraction I implement both a-b and b-a. These work by
// computing a + (~b) + 1 and (~a) + b + 1 respectively.

inline void ordered_bigsubtract(const std::uint64_t* a,
                                std::size_t lena,
                                const std::uint64_t* b, std::size_t lenb,
                                std::uint64_t* r, std::size_t &lenr)
{   Digit carry = 1;
    std::size_t i;
// Add the digits that (a) and (b) have in common
    for (i=0; i<lenb; i++)
        carry = addWithCarry(a[i], ~b[i], carry, r[i]);
// From there on up treat (b) as if it had its sign bit extended to the
// left.
    Digit topb = negative(~b[lenb-1]) ? allbits : 0;
    for (; i<lena; i++)
        carry = addWithCarry(a[i], topb, carry, r[i]);
// And of course (a) must also be treated as being extended by its sign bit.
    Digit topa = negative(a[lena-1]) ? allbits : 0;
// The result calculated here is 1 word longer than (a), and addition
// can never carry further than that.
    r[i] = topa + topb + carry;
// However because I am using (2s complement) signed arithmetic the result
// could be shorter, so I will check for that and return the length that
// is actually needed.
    while (r[i]==0 && i>0 && positive(r[i-1])) i--;
    while (r[i]==allbits && i>0 && negative(r[i-1])) i--;
    lenr = i+1;
}

inline void ordered_bigrevsubtract(const std::uint64_t* a,
                                   std::size_t lena,
                                   const std::uint64_t* b, std::size_t lenb,
                                   std::uint64_t* r, std::size_t &lenr)
{   Digit carry = 1;
    std::size_t i;
// Add the digits that (a) and (b) have in common
    for (i=0; i<lenb; i++)
        carry = addWithCarry(~a[i], b[i], carry, r[i]);
// From there on up treat (b) as if it had its sign bit extended to the
// left.
    Digit topb = negative(b[lenb-1]) ? allbits : 0;
    for (; i<lena; i++)
        carry = addWithCarry(~a[i], topb, carry, r[i]);
// And of course (a) must also be treated as being extended by its sign bit.
    Digit topa = negative(~a[lena-1]) ? allbits : 0;
// The result calculated here is 1 word longer than (a), and addition
// can never carry further than that.
    r[i] = topa + topb + carry;
// However because I am using (2s complement) signed arithmetic the result
// could be shorter, so I will check for that and return the length that
// is actually needed.
    while (r[i]==0 && i>0 && positive(r[i-1])) i--;
    while (r[i]==allbits && i>0 && negative(r[i-1])) i--;
    lenr = i+1;
}

// Subtract a small number from a bignum

inline void bigsubtract_small(const std::uint64_t* a,
                              std::size_t lena,
                              SignedDigit n,
                              std::uint64_t* r, std::size_t &lenr)
{   Digit w[1];
    w[0] = static_cast<Digit>(n);
    ordered_bigsubtract(a, lena, w, 1, r, lenr);
}

// subtract a bignum from a small number

inline void bigrevsubtract_small(const std::uint64_t* a,
                                 std::size_t lena,
                                 SignedDigit n,
                                 std::uint64_t* r, std::size_t &lenr)
{   Digit w[1];
    w[0] = static_cast<Digit>(n);
    ordered_bigrevsubtract(a, lena, w, 1, r, lenr);
}


inline void bigsubtract(const std::uint64_t* a, std::size_t lena,
                        const std::uint64_t* b, std::size_t lenb,
                        std::uint64_t* r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_bigsubtract(a, lena, b, lenb, r, lenr);
    else return ordered_bigrevsubtract(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Difference::op(std::uint64_t* a,
                                    std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n;
    if (lena >= lenb) n = lena+1;
    else n = lenb+1;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    bigsubtract(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t Difference::op(SignedDigit a, SignedDigit b)
{   Digit aa[1], bb[1];
    aa[0] = a;
    bb[0] = b;
    std::uint64_t* r = reserve(2);
    std::size_t final_n;
    bigsubtract(aa, 1, bb, 1, r, final_n);
    return confirmSize(r, 2, final_n);
}

inline std::intptr_t Difference::op(SignedDigit a, std::uint64_t* b)
{   Digit aa[1];
    aa[0] = a;
    std::size_t lenb = numberSize(b);
    std::uint64_t* r = reserve(lenb+1);
    std::size_t final_n;
    bigsubtract(aa, 1, b, lenb, r, final_n);
    return confirmSize(r, lenb+1, final_n);
}

inline std::intptr_t Difference::op(std::uint64_t* a, SignedDigit b)
{   std::size_t lena = numberSize(a);
    Digit bb[1];
    bb[0] = b;
    std::uint64_t* r = reserve(lena+1);
    std::size_t final_n;
    bigsubtract(a, lena, bb, 1, r, final_n);
    return confirmSize(r, lena+1, final_n);
}


inline std::intptr_t RevDifference::op(std::uint64_t* a,
                                       std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n;
    if (lena >= lenb) n = lena+1;
    else n = lenb+1;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    bigsubtract(b, lenb, a, lena, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t RevDifference::op(SignedDigit a, SignedDigit b)
{   Digit aa[1], bb[1];
    aa[0] = a;
    bb[0] = b;
    std::uint64_t* r = reserve(2);
    std::size_t final_n;
    bigsubtract(bb, 1, aa, 1, r, final_n);
    return confirmSize(r, 2, final_n);
}

inline std::intptr_t RevDifference::op(SignedDigit a,
                                       std::uint64_t* b)
{   Digit aa[1];
    aa[0] = a;
    std::size_t lenb = numberSize(b);
    std::uint64_t* r = reserve(lenb+1);
    std::size_t final_n;
    bigsubtract(b, lenb, aa, 1, r, final_n);
    return confirmSize(r, lenb+1, final_n);
}

inline std::intptr_t RevDifference::op(std::uint64_t* a,
                                       SignedDigit b)
{   std::size_t lena = numberSize(a);
    Digit bb[1];
    bb[0] = b;
    std::uint64_t* r = reserve(lena+1);
    std::size_t final_n;
    bigsubtract(bb, 1, a, lena, r, final_n);
    return confirmSize(r, lena+1, final_n);
}

//=========================================================================
//=========================================================================
// multiplication, squaring and exponentiation.
//=========================================================================
//=========================================================================


// I need some sub-functions that add and subtract N-digit numbers.

// increment the N-digit number x by n.

inline void increment(std::uint64_t* x, std::size_t N, Digit n=1)
{   if ((x[0] += n) >= n) return;
    for (std::size_t i=1; i<N; i++)
    {   if (++x[i] != 0) return;
    }
}

// z = x + y and return a carry, where x, y and z are N digit numbers.

inline Digit addWithCarry(const std::uint64_t* x,
                                  const std::uint64_t* y,
                                  std::uint64_t* z, std::size_t N)
{   Digit c = addWithCarry(x[0], y[0], z[0]);
    for (std::size_t i=1; i<N; i++)
        c = addWithCarry(x[i], y[i], c, z[i]);
    return c;
}

// As above except that c is a "carry in".

inline Digit addWithCarry(const std::uint64_t* x,
                                  const std::uint64_t* y,
                                  Digit c,
                                  std::uint64_t* z, std::size_t N)
{   for (std::size_t i=0; i<N; i++)
        c = addWithCarry(x[i], y[i], c, z[i]);
    return c;
}
// z = x - y and return a borrow.

inline Digit subtractWithBorrow(const std::uint64_t* x,
                                        const std::uint64_t* y,
                                        std::uint64_t* z, std::size_t N)
{   Digit b = subtractWithBorrow(x[0], y[0], z[0]);
    for (std::size_t i=1; i<N; i++)
        b = subtractWithBorrow(x[i], y[i], b, z[i]);
    return b;
}

// A second (or third!) attempt at general multiplication for large
// integers.

// Overall plan:
//    (1) Cases from 1x1 to 7x7 are dealt with using special code
//        in the hope that those small cases can be handled really
//        fast. I unroll and inline everything. Also cases of Nx1 to
//        Nx7 have their inner x1 to x7 loops unrolled.
//    (2) min(N,M)<=threshold. Use simple long multiplication because
//        anything like Karatsuba will not pay off.
//    (3) N>1.5*M or M>1.5*N and the smaller is >7. Do a sequence of
//        MxM multiplications until the residual N is small enough
//        that a different case applies.
//    (5) If N,M and less than another threshold do Karatsuba.
//    (6) Use 3-thread Karatsuba or 4-thread Toom32.
//

// So here is a more detailed commentary talking about the thresholds in
// the treatment of large cases in extra detail.
//
// Suppose I am multiplying an N digit number by an M digit one with N>=M.
// I can go classical which is straightforward and for small cases that is
// good. But for the rest there are two other base schemes:
//
// I can go Karatsuba. That will use sub-digits of size D=ceiling(N/2) and
// will demand that M>D at least since otherwise the high sub-digit of M
// will be zero and by then use of Karatsuba is surely silly.
// The calculation forms two products on D*D and one on (N-D)*(M-D). If
// things start off even slightly unbalanced this last one is more so and
// so eventually you should not use Karatsuba for it even N it is big.
// But for reasonably balanced cases it is good. My estimates are that
// I should use it up as far as N=1.25*M.
//
// Then I have Toom32 that multiplies a 3-digit number by a 2 digit one via
// evaluation at 0, +1, -1 and infinity. The sub-digit size D must be
// max((N+2)/3, (M+1)/2) to keep top sub-digits both in existence. So
// the cost is then three products D*D and one of (N-2D)*(M-D).
// That final product may be noticably out of balance if N is not very close
// to 1.5M and I will discuss that later, it being a close relative of the
// similar situation that arises in Karatsuba.
//
// So given arbitrary N,M where they are not the same value but are tolerably
// close do I use Karatsuba or Toom32? And what do I do when N and M are
// more widely different?
//
// My plan for a ramge of values of alpha=N/M (where wlog N>=M) will be
//    1 <= alpha < 1.25      Karatsuba. 1 is the best case here
//    1.25 <= alpha < 1.85    Toom32 where 1.5 is the best case
//
// So now I need to consider alpha >= 1.85.
// I will split off the low 3M/2 digits and use Toom32 to form that
/// part of the result - I am then left with the case (N-3M/2)*M. That
// can be continued until N<3M/2, which I will write as alpha<1.5.
// If alpha > 1.25 I will use a sub-optimal Toom32. For 0.85<alpha<1.25
// I will use Karatsuba (with reversed arguments in the alpha<1 case).
// Then if akpha > 0.54 (=1/1.85) I will use Toom32 with reversed arguments.
// So we are left with alpha<0.54, otherwise M>1.85*N. I reverse the
// arguments and continue until the I drop down to use of classical
// methods. 
//
// In all this there is an issue of workspace allocation. And a top-level
// use of either Toom32 or Karatsuba needs extra space because the recursive
// calls that are made run concurrently so each need separate space.
// But for all the recursive calls things are nicer and I can use and
// re-use space.
// I have made several attempts to chart how much will be used but the
// interaction between levels of call and the fact that when I "halve" the
// size of a number there has to be rounding when that number is of odd
// length make that messy enough that anything I come up with using
// calculation will not be a sharp bound and will be very fragile against
// small changes in the code. So I will work empirically. For multiplications
// of N*M with N>=M I will have (at the end of this file) some code that
// if MEASURE_WORKSPACE is defined runs comprehensive tests for N and M up
// to some threshold (initially 2000) and assesses workspace use relative
// to the smaller of those. I wish to observe both assymptotic behaviour and
// smaller cases (I will only worry about N>=M>7) so that I can allow for
// both. While I am doing that I disable the top-level distribution of work
// into threads.

inline std::size_t worstN = 0;
inline std::size_t worstM = 0;
inline std::size_t thisN = 0;
inline std::size_t thisM = 0;
inline double worstRatio = 0.0;
inline DigitPtr workspaceBase;

#include <atomic>

// When I get to big-integer multiplication I will use two or three
// worker threads so that elapsed times for really large multiplications
// are reduced somewhat. Well ideally by a factor approaching 3. I set up
// a framework of support for the threads here. A main program thread will
// want its own worker threads here. Each worker thread gets passed a
// nice object called "worker_data" that encapsulates the way it receives
// data from the caller and passes results back.

// Each worker thread needs some data that it shares with the main thread.
// this structure encapsulates that.

// Probably the most "official" way to coordinate threads would be to use
// condition variables, but doing so involves several synchronization
// primitives for each step of the transaction. For the simple level of
// coordination I need here it would be more costly that necessary. I can
// manage here with a scheme that when thread A want to allow thread B to
// proceed it unlocks a mutex that thread B was waiting on. There is some
// mess associated with ensuring that the main thread waits for results and
// that there are no race situations where all threads compete for a single
// mutex.
//
// There are 4 mutexes for each worker thread, but each synchronization step
// just involves a single mutex, transferring ownership between main and worker
// thread. Here is the patter of transfer and subsequent ownership, with "?"
// marking a muxex that has been waiting and the ">n" or <n" in the middle
// also showing which muxex has just been activated:
//       X  X  .  .         ?  .  X  X    Idle state. Worker waiting on mutex 0
// To start a transaction the main thread sets up data and unlocks mutex 0.
// That allows the worker to proceed and pick up the data.
//       .  X  .  .   >0    ?X .  X  X    first transaction
// The main thread must not alter data until the worker is finished. It waits
// on mutex 1 until the worker tells it that a result is available.
//       .  X ?X  .   <2    X  .  .  X
// The main thread is now entitles to start using the results of the activity
// just completed and setting up data for the next one. It can not release
// mutex 0 to restart the worker because the worker alread owns that. And even
// though it owns mutex 2 it had better not release that, because for that
// to make sense the worker would need to be waiting on it, and that would mean
// the worker had just done m3.unlock(); m3.lock() in quick succesion, which
// might have led it to grab m3 rather than the main program managing to. So
// use the third mutex, which the worker must be waiting on.
//       .  .  X  .   >1    X ?X  .  X    second transaction
// When it has finished its task the worker now unlocks mutex 3. This leaves
// a situation symmetric with the initial one
//       .  .  X ?X   <3    X  X  .  .
//       .  .  .  X   >2    X  X  ?X .    third transaction
//       ?X .  .  X   <0    .  X  X  .
//       X  .  .  .   >3    .  X  X ?X    fourth transaction
//       X ?X  .  .   <1    .  .  X  X    back in initial configuration!
//
// The pattern is thus that the master goes
//  [initially lock 0 and 1]
//  unlock 0  wait 2
//  unlock 1  wait 3
//  unlock 2  wait 0
//  unlock 3  wait 1
// while the worker goes
//  [initially lock 2 and 3]
//  wait 0    unlock 2
//  wait 1    unlock 3
//  wait 2    unlock 0
//  wait 3    unlock 1
// Observe that I can use (n^2) to map between the mutex number in the first
// and second columns here. That counting is what send_count and
// receive_count are doing.

// In a nice world I would use just the C++ std::mutex scheme for
// synchronization, however here I am performance critical and to save
// a bit when performing medium-sized multiplications I will use the
// Microsoft version of mutexes directly on that platform.

#if defined __CYGWIN__ || defined __MINGW32__

// It is possible that SRW locks have lower overhead than Mutex. So I will
// use them, but have an "#ifdef" so I can revert if needbe.

#define USE_MICROSOFT_SRW 1

#ifndef USE_MICROSOFT_SRW
#define USE_MICROSOFT_MUTEX 1
#endif // USE_MICROSOFT_SRW

// Going "#include <windows.h>" pollutes the name-space rather heavily
// and so despite it being somewhat despicable I declare the rather small
// number of things I need by hand. Note that some of the issues are
// macros rather than extern definitions, so it is not obvious that
// C++ "namespace" treatment can make things nice for me.

extern "C"
{
struct SecApp
{   std::uintptr_t nLength;
    void* lpSecurityDescriptor;
    int bInheritHandle;
};

typedef struct _RTL_SRWLOCK { void* Ptr; } RTL_SRWLOCK,*PRTL_SRWLOCK;
#define RTL_SRWLOCK_INIT {0}
#define SRWLOCK_INIT RTL_SRWLOCK_INIT
typedef RTL_SRWLOCK SRWLOCK, *PSRWLOCK;

extern __declspec(dllimport) void InitializeSRWLock (PSRWLOCK SRWLock);
extern __declspec(dllimport) void ReleaseSRWLockExclusive (PSRWLOCK SRWLock);
extern __declspec(dllimport) void ReleaseSRWLockShared (PSRWLOCK SRWLock);
extern __declspec(dllimport) void AcquireSRWLockExclusive (PSRWLOCK SRWLock);
extern __declspec(dllimport) void AcquireSRWLockShared (PSRWLOCK SRWLock);
extern __declspec(dllimport) bool TryAcquireSRWLockExclusive (PSRWLOCK SRWLock);
extern __declspec(dllimport) bool TryAcquireSRWLockShared (PSRWLOCK SRWLock);

extern __declspec(dllimport)  void* 
    CreateMutexA(SecApp* , std::uintptr_t, const char* );
extern __declspec(dllimport) int CloseHandle(void* h);
extern __declspec(dllimport) int ReleaseMutex(void* m);
extern __declspec(dllimport) void* 
    WaitForSingleObject(void* , std::uintptr_t);
inline const long unsigned int MICROSOFT_INFINITE = 0xffffffff;

};   // end of extern "C" scope.

#endif // __CYGWIN__ or __MINGW32__

class WorkerData
{
public:
    int which;
    std::atomic<bool> ready;
#if defined USE_MICROSOFT_SRW
    SRWLOCK mutex[4];
#elif defined USE_MICROSOFT_MUTEX
    void* mutex[4];
#else // The final case is C++ std::mutex
    std::mutex mutex[4];
#endif // end of mutex selection
    bool quit_flag;

    ConstDigitPtr a;   std::size_t lena;
    ConstDigitPtr b;   std::size_t lenb;
    DigitPtr c;
    DigitPtr w;

// When I construct an instance of Worker data I set its quit_flag to
// false and lock two of the mutexes. That sets things up so that when
// it is passed to a new worker thread that thread behaves in the way I
// want it to.
    WorkerData()
    {   ready = false;
        quit_flag = false;
#if defined USE_MICROSOFT_SRW
        InitializeSRWLock(&mutex[0]);
        InitializeSRWLock(&mutex[1]);
        AcquireSRWLockExclusive(&mutex[0]);
        AcquireSRWLockExclusive(&mutex[1]);
        InitializeSRWLock(&mutex[2]);
        InitializeSRWLock(&mutex[3]);
#elif defined USE_MICROSOFT_MUTEX
        mutex[0] = CreateMutexA(NULL, 1, NULL);
        mutex[1] = CreateMutexA(NULL, 1, NULL);
        mutex[2] = CreateMutexA(NULL, 0, NULL);
        mutex[3] = CreateMutexA(NULL, 0, NULL);
#else // use C++ std::mutex
// The next two must be locked by the main thread.
        mutex[0].lock();
        mutex[1].lock();
#endif // Mutexes now initialized and locked as needed
    }
    void setWhich(int n)
    {   which = n;
    }
#ifdef USE_MICROSOFT_MUTEX
    ~WorkerData()
    {   CloseHandle(mutex[0]);
        CloseHandle(mutex[1]);
        CloseHandle(mutex[2]);
        CloseHandle(mutex[3]);
    }
#endif // USE_MICROSOFT_MUTEX
};

// Then each main thread will have a structure that encapsulated the
// worker threads that it ends up with and the data it sets up for
// them and that they then access. When this structures is created it will
// cause the worker threads and the data block they need to be constructed.

inline void workerThread(WorkerData* wd);

class DriverData
{
public:
    int        send_count = 0;
    int        send_count2 = 0;
    WorkerData wd_0,
               wd_1,
               wd_2;
// When the instance of DriverData is created the three sets of WorkerData
// get constructed with two of their mutexes locked. This will mean that when
// worker threads are created and start running they will politely wait for
// work.

    std::thread w_0, w_1, w_2;
    DriverData()
    {   wd_0.setWhich(0);
        wd_1.setWhich(1);
        wd_2.setWhich(2);
        w_0 = std::thread(workerThread, &wd_0),
        w_1 = std::thread(workerThread, &wd_1);
        w_2 = std::thread(workerThread, &wd_2);
// I busy-wait until all the threads have both claimed the mutexes that they
// need to own at the start! Without this the main thread may post a
// multiplication, so its part of the work and try to check that the worker
// has finished (by claiming one of these mutexes) before the worker thread
// has got started up and has claimed them. This feels clumsy, but it only
// happens at system-startup.
        while (!wd_0.ready.load() &&
               !wd_1.ready.load() &&
               !wd_2.ready.load())
            std::this_thread::sleep_for(std::chrono::microseconds(1));
    }

// When the DriverData object is to be destroyed it must arrange to
// stop and then join the two threads that it set up. This code that sends
// a "quit" message to each thread will be executed before the thread object
// is deleted, and the destructor of the thread object should be activated
// before that of the WorkerData and the mutexes within that.

    ~DriverData()
    {   wd_0.quit_flag = wd_1.quit_flag = wd_2.quit_flag = true;
        releaseWorkers(true);
        w_0.join();
        w_1.join(); // These calls to join wait for the threads to shut down.
        w_2.join();
    }

// Using the worker threads is then rather easy: one sets up data in
// the WorkerData structures and then call releaseWorkers(). Then
// you can do your own thing in parallel with the two workers picking up
// the tasks that they had been given. When you are ready you call
// wait_for_workers() which does what one might imagine, and the workers
// are expected to have left their results in the WorkerData object so
// you can find it.

    void releaseWorkers(bool third)
    {
#if defined USE_MICROSOFT_SRW
        ReleaseSRWLockExclusive(&wd_0.mutex[send_count]);
        ReleaseSRWLockExclusive(&wd_1.mutex[send_count]);
        if (third) ReleaseSRWLockExclusive(&wd_2.mutex[send_count2]);
#elif defined USE_MICROSOFT_MUTEX
        ReleaseMutex(wd_0.mutex[send_count]);
        ReleaseMutex(wd_1.mutex[send_count]);
        if (third) ReleaseMutex(wd_2.mutex[send_count2]);
#else // use std::mutex
        wd_0.mutex[send_count].unlock();
        wd_1.mutex[send_count].unlock();
        if (third) wd_2.mutex[send_count2].unlock();
#endif // mutexed unlocked
    }

    void wait_for_workers(bool third)
    {
#if defined USE_MICROSOFT_SRW
        AcquireSRWLockExclusive(&wd_0.mutex[send_count^2]);
        AcquireSRWLockExclusive(&wd_1.mutex[send_count^2]);
        if (third) AcquireSRWLockExclusive(&wd_2.mutex[send_count2^2]);
#elif defined USE_MICROSOFT_MUTEX
// WaitForSingleObject takes a timeout limit measured in milliseconds as
// its second argument. I will allow waits of up to 2 seconds. There
// should be a response by then since the workere are just performing a
// multiplication and at all plausible number-sizes 2 seconds is plenty
// even on slow computers. The main case where there could be
// failure here would be when running under a debugger and with one
// of the worker threads being subject to breaks or single stepping.
        WaitForSingleObject(wd_0.mutex[send_count^2], MICROSOFT_INFINITE);
        WaitForSingleObject(wd_1.mutex[send_count^2], MICROSOFT_INFINITE);
        if (third) WaitForSingleObject(wd_2.mutex[send_count2^2], MICROSOFT_INFINITE);
#else // use std::mutex
        wd_0.mutex[send_count^2].lock();
        wd_1.mutex[send_count^2].lock();
        if (third) wd_2.mutex[send_count2^2].lock();
#endif // synchronized
        send_count = (send_count+1)&3;
        if (third) send_count2 = (send_count2+1)&3;
    }
};

// Even if there are multiple user threads I will only have a single
// instance of DriverData and hence I will always have just three
// worker threads. If multiple threads all call generalMul at (almost) the
// same time a compare-and-exchange operation arranges that only one of
// them gets to offload parts of the multiplication work to those worker
// threads and the others work sequentially. This allows me to have a fixed
// number of worker threads.

static DriverData driverData;

class ManageWorkers
{
public:
    static std::atomic<bool> threadsInUse;
    bool mayUseThreads;
    ManageWorkers()
    {   bool expected = false;
        mayUseThreads = threadsInUse.compare_exchange_weak(expected, true);
#ifdef MEASURE_WORKSPACE
        mayUseThreads = false;
#endif // MEASURE_THREADS
   }
    ~ManageWorkers()
    {   if (mayUseThreads) threadsInUse.store(false);
    }
};

class BigMultiplication
{

// I need some commentary about this! I have three worker threads
// available and a multiplication can decompose either a 2N by 2N
// multiplication into 3 tasks or a 3N by 2N one into 4 tasks.
// If the caller is a multi-threaded program then several of those
// threads might each start to perform a multiplication, but I need to
// ensure that only one of them gets to use the worker threads.
// To achieve this I have an atomic variable threadsInUse and I
// use a compare_exchange operation that will always end up with it
// having the value true, but that leaves mayUseThreads true if it had
// initially been false. The class destructor for ManageWorkers ensures
// that when a scope where use of the worker threads exits the access
// control flag is reset. Using compare_exchange_weak means that requests
// for access to the workers may spuriously fail (!) but the _strong
// version may have higher overheads. On architectures where there is
// a genuine compare-exchange function the spurious failure will not arise,
// but on machines where atomic access is supported using load-locked
// and store-conditional combinations (eg arm processors, including code
// compiled for aarch64 before version 8.1) the store conditional can be
// rejected because some other activity has touched the memory - even if
// the value in the memory is the "expected" one. This can lead the
// compare_exchange to report failure even in a case that could have been
// deemed a success. With low contention this will hardly ever happen!
// But here the worst possible consquence is that the code will drop back
// to do sub-multiplcations sequentially and quite possibly one of those
// will succeed in the compare_exchange and use concurrency only starting
// at its level.

private:

// Multiplications where M and N are both no more than than 7
// are done by unrolled and inlined special code.
// From when the larger is at least KARASTART I will use Karatsuba,
// and from KARABIG on it will not be just Karatsuba but the top
// level decomosition will be run using three threads. Also up as
// far as KARABIG I will use some stack allocated space while from
// there up I will use my "stkvector" scheme so that there is no
// serious limit to the amount that can be used.

static const std::size_t MUL_INLINE_LIMIT = 7;

#ifdef KSTART
static const std::size_t KARASTART        = KSTART;
#else
static const std::size_t KARASTART        = 15;
#endif

// I want the "half sized" multiplications to be large enough that
// there is no need to try the heavily inlined tiny-case code. I want
// this to apply to Toom as well.

static_assert((KARASTART+1)/2 > 7);

#ifdef KBIG
static const std::size_t KARABIG          = KBIG;
#else
static const std::size_t KARABIG          = 60;
#endif

static_assert((KARABIG+1)/2 > KARASTART);

// The test code activated via MEASURE_WORKSPACE shows that the
// amount of workspace is bounded by 6*M where M is the smaller of
// the two number-lengths - at least over comprehensive testing of
// a great meny small to fairly large cases. Well actually it shows a
// multiplier not much larger than 5.

static std::size_t workspaceSize(std::size_t M)
{   return 6*M;
}

// At the top level toom32() can use a little over 4*L workspace for
// itself, where L=max(N/3,M/2). But N<=1.85*M and M is large enough that
// I will ignore rounding. Then plus the need for four parallel
// sub-multiplications. I will use a rounded up 2M/3 as my bound on L.

static std::size_t topWorkspaceSize(std::size_t M)
{   size_t toomLen = (2*M+2)/3;
    return 4*toomLen + 4*workspaceSize(toomLen);
}

// Set (hi,lo) to the 128-bit product of a by b.

// Ha ha - because this is a method defined within a class the word
// "static" implies "inline" in that the class definition may be included
// in multiple compilation units but only one copy of the method is liable
// to arise.

static void oneWordMul(std::uint64_t a, std::uint64_t b,
                       std::uint64_t &hi, std::uint64_t &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>(b);
    hi = static_cast<std::uint64_t>(r >> 64);
    lo = static_cast<std::uint64_t>(r);
}

// Now much the same but forming a*b+c. Note that this can not overflow
// the 128-bit result. Both hi and lo are only updated at the end
// of this, and so they are allowed to be the same as input arguments.

static void oneWordMul(std::uint64_t a, std::uint64_t b,
                       std::uint64_t c,
                       std::uint64_t &hi, std::uint64_t &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>(b) +
                static_cast<UINT128>(c);
    hi = static_cast<std::uint64_t>(r >> 64);
    lo = static_cast<std::uint64_t>(r);
}

public:

// verySimpleMul exists ONLY for testing - specifically to generate
// reference products that the output from other more complicated code
// can be compared against.

static void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   Digit carry = 0, lo = 0, hi = 0;
    for (std::size_t k=0; k<N+M-1; k++)
    {   for (std::size_t i=0; i<N; i++)
        {   if (k < i) continue;
            if (k-i >= M) continue;
            Digit hi1;
            oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    result[N+M-1] = lo;
}

private:

// I have a general idiom I intend to use for loops where the
// body of the iteration is small. If one has
//     for (i=A; i<B; i++) { X(i); }
// I will unroll the loop, writing
//     for (i=A; i<B-1; i+=2)
//     {   X(i);
//         X(i+1);
//     }
//     if (i<B) { X(i); i++; }
// This adds to the cost if the loop is traversed only once, is broadly
// cost neutral if it is traversed twice and from there up it saves tests
// and control-flow. Of course it increases code bulk. 

// Here I have classical multiplication for the case N>=M and as
// used here M>7. This is written out as succession of 3 loops since
// that leads to each having simpler start and end conditions, and I
// hope that reduces overhead.

static void simpleMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{
// For this I will require N>=M
    Digit carry = 0, lo, hi = 0, hi1;
// The lowest Digit can be handled specially to get things going.
    oneWordMul(a[0], b[0], lo, result[0]);
    std::size_t k=1;
    for (; k<M; k++)
    {   std::size_t i;
// Here I want k<M<=N so certainly if i<k then i<N
//@@    for (i=0; i<=k; i++)
//@@    {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        for (i=0; i<=k-1; i+=2)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            oneWordMul(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<=k)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Now k>=M, I want i<=k to imply i<N so go as far as k<N
    for (; k<N; k++)
    {
//@@    for (std::size_t j=0; j<M; j++)
//@@    {
//@@ // Ha ha in this loop I iterate on j=k-i which makes the loop
//@@ // just a little nicer to express.
//@@        oneWordMul(a[k-j], b[j], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t j;
        for (j=0; j<M-1; j+=2)
        {   oneWordMul(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            oneWordMul(a[k-j-1], b[j+1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (j<M)
        {   oneWordMul(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Finally k>=N so i<N will imply i<=k
    for (; k<N+M-1; k++)
    {
//@@    for (std::size_t i=k+1-M; i<N; i++)
//@@    {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t i;
        for (i=k+1-M; i<N-1; i+=2)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            oneWordMul(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<N)
        {   oneWordMul(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// The very final digit of the result drops out here.
    result[k] = lo;
}


private:

// Now I want code for multiplying N*M digit numbers with N up to some
// small limit as fast as I can. Here I have all the cases with both
// N and M up to 7 covered. Also cases where N=M<=14 and ones where
// M<=7 but N can be arbitrary. These cases represent bulky and perhaps
// ugly in-line code but I expect them to be the most performance
// critical parts of the base for multiplication.


[[gnu::always_inline]]
static void inlineMul_1_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   oneWordMul(a[0], b[0], result[1], result[0]);
}

[[gnu::always_inline]]
static void inlineMul_2_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    result[2] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_2_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    result[3] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_3_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    result[3] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_3_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    result[4] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_3_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    result[5] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_4_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    result[4] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_4_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    result[5] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_4_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    result[6] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_4_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    result[7] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_5_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    result[5] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_5_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    result[6] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_5_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    result[7] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_5_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    result[8] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_5_5(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    result[9] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_6_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    result[6] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_6_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    result[7] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_6_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    result[8] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_6_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    result[9] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_6_5(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    result[10] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_6_6(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    result[11] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_7_1(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    result[7] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_7_2(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    result[8] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_7_3(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    result[9] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_7_4(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    result[10] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_7_5(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    result[11] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_7_6(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    result[12] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_7_7(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    result[13] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_8_8(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    result[15] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_9_9(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[15] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[8], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[16] = dlo;
    dlo = dhi;
    dhi = carry;
    result[17] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_10_10(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[15] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[16] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[8], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[17] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[9], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[18] = dlo;
    dlo = dhi;
    dhi = carry;
    result[19] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_11_11(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[15] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[16] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[17] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[8], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[18] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[9], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[19] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[10], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[20] = dlo;
    dlo = dhi;
    dhi = carry;
    result[21] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_12_12(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[15] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[16] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[17] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[18] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[8], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[19] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[9], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[20] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[10], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[21] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[11], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[22] = dlo;
    dlo = dhi;
    dhi = carry;
    result[23] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_13_13(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[15] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[16] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[17] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[18] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[19] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[8], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[20] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[9], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[21] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[10], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[22] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[11], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[23] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[12], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[24] = dlo;
    dlo = dhi;
    dhi = carry;
    result[25] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_14_14(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[15] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[16] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[17] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[18] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[19] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[20] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[8], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[21] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[9], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[22] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[10], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[23] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[11], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[24] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[12], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[25] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[13], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[26] = dlo;
    dlo = dhi;
    dhi = carry;
    result[27] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_15_15(ConstDigitPtr a,
                          ConstDigitPtr b,
                          DigitPtr result)
{   uint64_t dhi, dlo;
    oneWordMul(a[0], b[0], dlo, result[0]);
    dhi = 0;
    uint64_t whi, carry;
    carry = 0;
    oneWordMul(a[0], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[1] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[2] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[3] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[4] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[5] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[6] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[7] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[8] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[9] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[10] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[11] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[12] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[13] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[0], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[1], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[0], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[14] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[1], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[2], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[1], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[15] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[2], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[3], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[2], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[16] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[3], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[4], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[3], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[17] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[4], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[5], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[4], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[18] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[5], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[6], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[5], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[19] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[6], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[7], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[6], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[20] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[7], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[8], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[7], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[21] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[8], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[9], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[8], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[22] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[9], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[10], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[9], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[23] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[10], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[11], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[10], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[24] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[11], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[12], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[11], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[25] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[12], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[13], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[12], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[26] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[13], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    oneWordMul(a[14], b[13], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[27] = dlo;
    dlo = dhi;
    dhi = carry;
    carry = 0;
    oneWordMul(a[14], b[14], dlo, whi, dlo);
    carry += addWithCarry(dhi, whi, dhi);
    result[28] = dlo;
    dlo = dhi;
    dhi = carry;
    result[29] = dlo;
}

[[gnu::always_inline]]
static void inlineMul_1(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    oneWordMul(a[0], b[0], lo, result[0]);
    for (std::size_t k=1; k<N; k++)
    {
        oneWordMul(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    result[N+0] = lo;
}

[[gnu::always_inline]]
static void inlineMul_2(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    oneWordMul(a[0], b[0], lo, result[0]);
    oneWordMul(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=2; k<N; k++)
    {
        oneWordMul(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    oneWordMul(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+1] = lo;
}

[[gnu::always_inline]]
static void inlineMul_3(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    oneWordMul(a[0], b[0], lo, result[0]);
    oneWordMul(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=3; k<N; k++)
    {
        oneWordMul(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-2], b[2], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    oneWordMul(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+2] = lo;
}

[[gnu::always_inline]]
static void inlineMul_4(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    oneWordMul(a[0], b[0], lo, result[0]);
    oneWordMul(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=4; k<N; k++)
    {
        oneWordMul(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-2], b[2], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-3], b[3], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    oneWordMul(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+3] = lo;
}

[[gnu::always_inline]]
static void inlineMul_5(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    oneWordMul(a[0], b[0], lo, result[0]);
    oneWordMul(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[4], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[4] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=5; k<N; k++)
    {
        oneWordMul(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-2], b[2], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-3], b[3], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-4], b[4], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    oneWordMul(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-4], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+4] = lo;
}

[[gnu::always_inline]]
static void inlineMul_6(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    oneWordMul(a[0], b[0], lo, result[0]);
    oneWordMul(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[4], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[4] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[4], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[5], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[5] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=6; k<N; k++)
    {
        oneWordMul(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-2], b[2], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-3], b[3], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-4], b[4], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-5], b[5], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    oneWordMul(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-4], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-5], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-4], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+4] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+5] = lo;
}

[[gnu::always_inline]]
static void inlineMul_7(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b,
                        DigitPtr result)
{   Digit carry = 0, lo, hi = 0, hi1;
    oneWordMul(a[0], b[0], lo, result[0]);
    oneWordMul(a[0], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[4], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[4] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[4], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[5], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[5] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[0], b[6], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[1], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[2], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[3], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[4], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[5], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[6], b[0], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[6] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    for (std::size_t k=7; k<N; k++)
    {
        oneWordMul(a[k-0], b[0], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-1], b[1], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-2], b[2], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-3], b[3], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-4], b[4], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-5], b[5], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        oneWordMul(a[k-6], b[6], lo, hi1, lo);
        carry += addWithCarry(hi, hi1, hi);
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    oneWordMul(a[N-1], b[1], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-4], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-5], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-6], b[6], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+0] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[2], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-4], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-5], b[6], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+1] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[3], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-4], b[6], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+2] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[4], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-3], b[6], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+3] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[5], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    oneWordMul(a[N-2], b[6], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+4] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    oneWordMul(a[N-1], b[6], lo, hi1, lo);
    carry += addWithCarry(hi, hi1, hi);
    result[N+5] = lo;
    lo = hi;
    hi = carry;
    carry = 0;
    result[N+6] = lo;
}
static void smallCaseMul(ConstDigitPtr a, std::size_t N,
                         ConstDigitPtr b, std::size_t M,
                         DigitPtr result)
{
// For this I will already have checked that both M and N are at most
// 7 and so that switch statement will cover all the possibilities and
// everything should then expand to inline code.
    switch (MUL_INLINE_LIMIT*N + M)
    {
        case 7*1+2:
            std::swap(a, b);
        case 7*2+1:
            inlineMul_2_1(a, b, result);
            return;
        case 7*2+2:
            inlineMul_2_2(a, b, result);
            return;
        case 7*1+3:
            std::swap(a, b);
        case 7*3+1:
            inlineMul_3_1(a, b, result);
            return;
        case 7*2+3:
            std::swap(a, b);
        case 7*3+2:
            inlineMul_3_2(a, b, result);
            return;
        case 7*3+3:
            inlineMul_3_3(a, b, result);
            return;
        case 7*1+4:
            std::swap(a, b);
        case 7*4+1:
            inlineMul_4_1(a, b, result);
            return;
        case 7*2+4:
            std::swap(a, b);
        case 7*4+2:
            inlineMul_4_2(a, b, result);
            return;
        case 7*3+4:
            std::swap(a, b);
        case 7*4+3:
            inlineMul_4_3(a, b, result);
            return;
        case 7*4+4:
            inlineMul_4_4(a, b, result);
            return;
        case 7*1+5:
            std::swap(a, b);
        case 7*5+1:
            inlineMul_5_1(a, b, result);
            return;
        case 7*2+5:
            std::swap(a, b);
        case 7*5+2:
            inlineMul_5_2(a, b, result);
            return;
        case 7*3+5:
            std::swap(a, b);
        case 7*5+3:
            inlineMul_5_3(a, b, result);
            return;
        case 7*4+5:
            std::swap(a, b);
        case 7*5+4:
            inlineMul_5_4(a, b, result);
            return;
        case 7*5+5:
            inlineMul_5_5(a, b, result);
            return;
        case 7*1+6:
            std::swap(a, b);
        case 7*6+1:
            inlineMul_6_1(a, b, result);
            return;
        case 7*2+6:
            std::swap(a, b);
        case 7*6+2:
            inlineMul_6_2(a, b, result);
            return;
        case 7*3+6:
            std::swap(a, b);
        case 7*6+3:
            inlineMul_6_3(a, b, result);
            return;
        case 7*4+6:
            std::swap(a, b);
        case 7*6+4:
            inlineMul_6_4(a, b, result);
            return;
        case 7*5+6:
            std::swap(a, b);
        case 7*6+5:
            inlineMul_6_5(a, b, result);
            return;
        case 7*6+6:
            inlineMul_6_6(a, b, result);
            return;
        case 7*1+7:
            std::swap(a, b);
        case 7*7+1:
            inlineMul_7_1(a, b, result);
            return;
        case 7*2+7:
            std::swap(a, b);
        case 7*7+2:
            inlineMul_7_2(a, b, result);
            return;
        case 7*3+7:
            std::swap(a, b);
        case 7*7+3:
            inlineMul_7_3(a, b, result);
            return;
        case 7*4+7:
            std::swap(a, b);
        case 7*7+4:
            inlineMul_7_4(a, b, result);
            return;
        case 7*5+7:
            std::swap(a, b);
        case 7*7+5:
            inlineMul_7_5(a, b, result);
            return;
        case 7*6+7:
            std::swap(a, b);
        case 7*7+6:
            inlineMul_7_6(a, b, result);
            return;
        case 7*7+7:
            inlineMul_7_7(a, b, result);
            return;
    }
}

static void bigBySmallMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   switch (M)
    {
        case 1:
            inlineMul_1(a, N, b, result); return;
        case 2:
            inlineMul_2(a, N, b, result); return;
        case 3:
            inlineMul_3(a, N, b, result); return;
        case 4:
            inlineMul_4(a, N, b, result); return;
        case 5:
            inlineMul_5(a, N, b, result); return;
        case 6:
            inlineMul_6(a, N, b, result); return;
        case 7:
            inlineMul_7(a, N, b, result); return;
    }
}
static void balancedMul(ConstDigitPtr a, ConstDigitPtr b, std::size_t N,
                       DigitPtr result)
{   switch (N)
    {   default: simpleMul(a, N, b, N, result); return;
        case 1:  inlineMul_1_1(a, b, result);   return;
        case 2:  inlineMul_2_2(a, b, result);   return;
        case 3:  inlineMul_3_3(a, b, result);   return;
        case 4:  inlineMul_4_4(a, b, result);   return;
        case 5:  inlineMul_5_5(a, b, result);   return;
        case 6:  inlineMul_6_6(a, b, result);   return;
        case 7:  inlineMul_7_7(a, b, result);   return;
        case 8:  inlineMul_8_8(a, b, result);   return;
        case 9:  inlineMul_9_9(a, b, result);   return;
        case 10:  inlineMul_10_10(a, b, result);   return;
        case 11:  inlineMul_11_11(a, b, result);   return;
        case 12:  inlineMul_12_12(a, b, result);   return;
        case 13:  inlineMul_13_13(a, b, result);   return;
        case 14:  inlineMul_14_14(a, b, result);   return;
    }
}

// The vector a has M digits and result has N (with N>=M). Add the
// value in a into result and return any carry.

static Digit addMdigits(ConstDigitPtr a, std::size_t M, DigitPtr result, std::size_t N)
{   Digit carry = addWithCarry(a[0], result[0], result[0]);
    std::size_t i=1;
//@@for (; i<M; i++)
//@@    carry = addWithCarry(a[i], result[i], carry, result[i]);
    for (; i<M-1; i+=2)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        carry = addWithCarry(a[i+1], result[i+1], carry, result[i+1]);
    }
    if (i<M)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        i++;
    }
    while (carry != 0 && i<N)
    {   carry = addWithCarry(result[i], 1, result[i]);
        i++;
    }
    return carry;
}

// result = a + b with a carry-in

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     Digit carry,
                     DigitPtr result)
{   std::size_t i;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    for (i=0; i<lenB-1; i+=2)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        carry = addWithCarry(a[i+1], b[i+1], carry, result[i+1]);
    }
    if (i<lenB)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        carry = addWithCarry(a[i], carry, result[i]);
    return carry;
}

// result = a + b

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     DigitPtr result)
{   return karaAdd(a, lenA, b, lenB, 0, result);
}

// result = a - b

[[gnu::always_inline]]
static Digit karaSubtract(ConstDigitPtr a, std::size_t lenA,
                          ConstDigitPtr b, std::size_t lenB,
                          DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        borrow = subtractWithBorrow(a[i+1], b[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        borrow = subtractWithBorrow(a[i], 0, borrow, result[i]);
    return borrow;
}

// result = b - a;

[[gnu::always_inline]]
static Digit karaRevSubtract(ConstDigitPtr a, std::size_t lenA,
                             ConstDigitPtr b, std::size_t lenB,
                             DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        borrow = subtractWithBorrow(b[i+1], a[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        borrow = subtractWithBorrow(0, a[i], borrow, result[i]);
    return borrow;
}

// Replace a and b with a-b and a+b.

[[gnu::always_inline]]
static void karaDifferenceAndSum(DigitPtr a, DigitPtr b,
                                 std::size_t len,
                                 Digit& carry,
                                 Digit& borrow)
{   carry = borrow = 0;
    for (std::size_t i=0; i<len; i++)
    {   Digit aa = a[i], bb = b[i];
        borrow = subtractWithBorrow(aa, bb, borrow, a[i]);
        carry = addWithCarry(aa, bb, carry, b[i]);
    }
}

// Propogate a carry.

[[gnu::always_inline]]
static void karaCarry(Digit carry, DigitPtr v)
{   size_t i = 0;
    while (carry != 0)
    {   carry = addWithCarry(v[i], carry, v[i]);
        i++;
    }
}

// Propogate a borrow.

[[gnu::always_inline]]
static void karaBorrow(Digit borrow, DigitPtr v)
{   size_t i = 0;
    while (borrow != 0)
    {   borrow = subtractWithBorrow(v[i], borrow, v[i]);
        i++;
    }
}

// This divides a value by 2, where the value has a signed top digit
// and a vector of unsigned additional digits.

static SignedDigit karaHalve(SignedDigit top, DigitPtr a, std::size_t len)
{   Digit carry = top & 1;
    top = top - carry;
    for (size_t i=len-1; i!=0; i--)
    {   Digit w = a[i];
        a[i] = (w>>1) | (carry<<63);
        carry = w & 1;
    }
    a[0] = (a[0]>>1) | (carry<<63);
    return top/2;
}

[[gnu::always_inline]]
static void differenceLengthsMatch(ConstDigitPtr low, std::size_t length,
                                   ConstDigitPtr high, DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
//@@for (std::size_t i=1; i<length; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    std::size_t i;
    for (i=1; i<length-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<length)
        borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
}

[[gnu::always_inline]]
static bool differenceLengthsDiffer(ConstDigitPtr low, std::size_t lenLow,
                                    ConstDigitPtr high, std::size_t lenHigh,
                                    DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
    std::size_t i=1;
//@@for (; i<lenHigh; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    for (; i<lenHigh-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<lenHigh)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        i++;
    }
// I will not unwind this loop because I expect that lenHigh will usually
// be very close to lenLow so there will be little to save.
    for (; i<lenLow; i++)
        borrow = subtractWithBorrow(low[i], borrow, result[i]);
    if (borrow == 0) return false;
// If necessary negate the result. This case arises if low has at least one
// zero leading digit and is less that high in magnitide.
    borrow = 0;
    for (i=0; i<lenLow; i++)
        borrow = subtractWithBorrow(0, result[i], borrow, result[i]);
    return true;
}

// set result = |low-high| and return true if high>low.
// A special feature here is that the "low" values here can have
// leading zeros - for instance consider the partitioned form of
// the number 1234_5678:0000_0234_5678 where I have used ":" to mark
// where the whole number is split into high and low parts. The high
// part has 2 digits and the low has 3, however the low part has the
// smaller value. So in that case the correct absolute value of
// the differenfce will be 0000_1000_0000

[[gnu::always_inline]]
static bool absDifference(ConstDigitPtr low, std::size_t lenLow,
                          ConstDigitPtr high, std::size_t lenHigh,
                          DigitPtr result)
{   if (lenHigh != lenLow)
        return differenceLengthsDiffer(low, lenLow, high, lenHigh, result);
// Here the two numbers both have the same number of digits. I need to
// work out which is the larger. Usually I will only need to look at
// the top digit. On that basis I make the code capable of scanning all
// the way down the number.
// An alternative stretegy would be do compute (low-high) always, detect
// a borrow at the end (ie that the difference was negative) and in that
// case negate the answer. That might do a full linear-cost negation about
// half the time where what I do here frequently only tests one digit.
    std::size_t i = lenLow-1; 
    for (;;)
    {   if (high[i] < low[i])
        {   differenceLengthsMatch(low, lenLow, high, result);
            return false;
        }
        else if (high[i] > low[i])
        {   differenceLengthsMatch(high, lenLow, low, result);
            return true;
        }
        if (i == 0)   // Here the two numbers are equal.
        {   std::memset(result, 0, lenLow*sizeof(Digit));
            return false;
        }
        i--;
    }
}

//=========================================================================

// Some of the functions here have are templated with a boolean
// called "thread". When this is true the code is entitled to cause
// worker threads to be launched to perform subsidiary multiplications.
// The multi-thread decomposition may only happen once, and that is enforced
// by making thread=false for all the lower level calls.

// Now the main entrypoint to my new code for multiplying
// unsigned values. It tries to put simple cheap tests to spot
// cheap cases inline and then dispatch to the separate procedures
// that apply in each case.
// The small cases covered here are liable to get expanded in line
// in rather extreme manners!

public:

[[gnu::always_inline]]
static void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{
#ifdef MEASURE_WORKSPACE
//@@    std::cout << N << "*" << M << ". ";
    thisN = N;
    thisM = M;
#endif // MEASURE_WOREKSPACE
// I take a view that case of single word multiplication as both so
// special and so important that I do that in-line here.
    if ((N|M) == 1)
    {   oneWordMul(a[0], b[0], 0, result[1], result[0]);
        return;
    }
// I next have special treatment for all the cases where both M and N are
// at most 7. I make the cut off there because I can test if either N
// or M exceeds the bound using a bitwide OR here which I expect to be
// nice and cheap! Also because I expect small cases like this to be
// especially commonly used, and to be ones where loop overheads might
// intrude.
    if ((N|M) <= 7)
    {   LIKELY
        smallCaseMul(a, N, b, M, result);
        return;
    }
    if (N < M)
    {   std::swap(a, b);
        std::swap(N, M);
    }
// If the smaller number is fairly small I again use classical long
// multiplication, but with the inner loop unrolled.
    if (M <= 7)
    {   bigBySmallMul(a, N, b, M, result);
        return;
    }
    if (M < KARASTART)    // Too small for Karatsuba.
    {   if (N==M && N<=14) balancedMul(a, b, N, result);
        else simpleMul(a, N, b, M, result);
    }
    else biggerMul(a, N, b, M, result);
}

private:

static void biggerMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{   ManageWorkers manager;
// Now manager.mayUseThreads will be true if I am allowed to use the
// worker threads.
//
// Now look at out-of balance cases. Here I take the view that if N>1.5M
// I will hive off toom32 multiplications as much as I can. They will each
// be (3*M)/2xM and I need M space to keep some digits already computed that I
// will need to combine with the output from the next square multiply.
#ifdef TRACE_TIMES
    display("a", a, N);
    display("b", b, M);
#endif // TRACE_TIMES
    if (4*N <= 5*M)
    {   stkvector<Digit> workspace(topWorkspaceSize(M));
#ifdef MEASURE_WORKSPACE
        workspaceBase = workspace;
#endif // MEASURE_WORKSPACE
        if (N < KARABIG || !manager.mayUseThreads)
            kara(a, N, b, M, result, workspace);
        else kara<true>(a, N, b, M, result, workspace);
    }
    else if (20*N <= 37*M)
    {   stkvector<Digit> workspace(topWorkspaceSize(M));
#ifdef MEASURE_WORKSPACE
        workspaceBase = workspace;
#endif // MEASURE_WORKSPACE
        if (N < KARABIG || !manager.mayUseThreads)
            toom32(a, N, b, M, result, workspace);
        else toom32<true>(a, N, b, M, result, workspace);
    }
    else 
    {   stkvector<Digit> workspace(topWorkspaceSize(M));
#ifdef MEASURE_WORKSPACE
        workspaceBase = workspace;
#endif // MEASURE_WORKSPACE
        if (manager.mayUseThreads)
            unbalancedMul<true>(a, N, b, M, result, workspace);
        else unbalancedMul(a, N, b, M, result, workspace);
    }
}

// The following overload is the one used in recursive calls (it has
// workspace as its final argument). It is called when Kara or Toom32
// recurses and so most of the time we will have M==N>KARASTART/2

// @@@ [[gnu::always_inline]]
static void innerGeneralMul(ConstDigitPtr a, std::size_t N,
                            ConstDigitPtr b, std::size_t M,
                            DigitPtr result,
                            DigitPtr workspace)
{
#ifdef TRACE_TIMES
    displayIndent += 2;
#endif // TRACE_TIMES
    if (N < M)
    {   std::swap(a, b);
        std::swap(N, M);
    }
#ifdef MEASURE_WORKSPACE
// This is where the recursion can stop, so I update info on how much
// workspace has been used.
    std::size_t workspaceUsed = workspace - workspaceBase;
    if (workspaceUsed > 900000)
    {   std::cout << "\nnot converging\n";
        arithlib_abort();
    }
    double ratio = workspaceUsed/(double)thisM;
    if (ratio > worstRatio)
    {   std::cout << worstRatio << " -> " << ratio
                  << " : " << (ratio/std::log(thisM))
                  << " at " << thisN << "*" << thisM << "\n";
        worstRatio= ratio;
        worstM = thisM;
        worstN = thisN;
    }
#endif
    if (M <= 7)
    {
        bigBySmallMul(a, N, b, M, result);
#ifdef TRACE_TIMES
        displayIndent -= 2;
#endif // TRACE_TIMES
        return;
    }
    else if (M < KARASTART)
    {   if (N==M &&  N<=11) balancedMul(a, b, N, result);
        else simpleMul(a, N, b, M, result);
#ifdef TRACE_TIMES
        displayIndent -= 2;
#endif // TRACE_TIMES
        return;
    }
#ifdef TRACE_TIMES
    display("a", a, N);
    display("b", b, M);
#endif // TRACE_TIMES
// Here I will call Kara if N <= 1.25*M.
    if (4*N <= 5*M) kara(a, N, b, M, result, workspace);
// If N <= 1.85*M I will use toom32.
    else if (20*N <= 37*M) toom32(a, N, b, M, result, workspace);
    else
    {   DigitPtr save = setSize(workspace, M);
        workspace += M;
        size_t step = (3*M)/2;
        toom32(a, step, b, M, result, workspace);
        a += step;
        N -= step;
        result += step;
        workspace += M;
        for (;;)
        {   while (N >= step)
            {   std::memcpy(save, result, M*sizeof(Digit));
                toom32(a, step, b, M, result, workspace);
                addMdigits(workspace, M, result, step+M);
                a += step;
                N -= step;
                result += step;
            }
            if (N == 0) return;
// Here N < 1.5*M. If N>=M I can finish the job using a single step that
// is either Toom32 or Karatsuba. And I should also take this case
// if N<KARASTART. Also if N>=M/1.25 I can finish with Karatsuba. This
// set of end conditions is more complicated than I had originally thought!
            if (5*N >= 4*M || N < KARASTART)
            {   std::memcpy(save, result, M*sizeof(Digit));
                if (4*N > 5*M) toom32(a, N, b, M, result, workspace);
                else if (N >= M) kara(a, N, b, M, result, workspace);
                else if (N < KARASTART) simpleMul(a, N, b, M, result);
                else kara(b, M, a, N, result, workspace);
                addMdigits(workspace, M, result, step+M);
#ifdef TRACE_TIMES
                displayIndent -= 2;
#endif // TRACE_TIMES
                return;
            }
            else
            {
// If N<M I flip the order of the arguments (and recompute step).
                std::swap(a, b);
                std::swap(N, M);
                step = (3*M)/2;
            }
        }
    }
}

template <bool threads=false>
[[gnu::always_inline]]
static void unbalancedMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result,
                          DigitPtr workspace)
{
    innerGeneralMul(a, N, b, M, result, workspace);
    return;


//@@@@
// Here N is (much) bigger than M
    innerGeneralMul(a, M, b, M, result, workspace);
    N -= M;
    a += M;
    result += M;
    while (2*N > 3*M)
    {   std::memcpy(workspace, result, M*sizeof(Digit));
        innerGeneralMul(a, M, b, M, result, workspace+M);
// Now add M digits from workspace into the 2M digit number in result. There
// can not be an overflow.
        addMdigits(workspace, M, result, 2*M);
        N -= M;
        a += M;
        result += M;
    }
    if (N != 0)
    {   std::memcpy(workspace, result, M*sizeof(Digit));
        innerGeneralMul(a, N, b, M, result, workspace+M);
// Now add M digits from workspace into the M+N digit number in result. There
// can not be an overflow.
        addMdigits(workspace, M, result, M+N);
    }
}

// I have code for multiplying N*M numbers when N is about
// 1.5 times M. This splits the big number into 3 chunks and the
// smaller into two.
//
// Here is a description of the procedure in a somewhat readable compact form.
//
// a := ahigh*x^2 + amid*x + alow;
// b :=            bhigh*x + blow;      
//
// x^3 * (ahigh*bhigh) +
// x^2 * (ahigh*blow + amid*bhigh) +
// x   * (alow*bhigh + amid*blow) +
//       (alow*blow)
//
// asum := ahigh+amid+alow;    preserve carry
// bsum := bhigh+blow;         preserve carry
// adiff := ahigh-amid+alow;   preserve carry or borrow
// bdiff := blow-bhigh;        preserve borrow
// d0 := alow*blow;
// d1 := asum*bsum;            adjust for carries, borrows in asum, bsum,
// d2 := adiff*bdiff;          adiff, bdiff and generate carries or borrows.
// d3 := ahigh*bhigh;
//
// d0                                alow*blow
// (d1,d2) = (d1-d2,d1+d2)           record carries
// d1 := d1/2 - p3;                  alow*bhigh + amid*blow   record carry etc
// d2 := d2/2 - p0;                  ahigh*blow + amid*bhigh  record carry etc
// d3                                ahigh*bhigh
//
// merge d1, d2 in accounting for how they overlap each other and d0, d3.

template <bool thread=false>
static void toom32(ConstDigitPtr a, std::size_t N,
                   ConstDigitPtr b, std::size_t M,
                   DigitPtr res,
                   DigitPtr workspace)
{
// I will start by viewing a as (ahigh, amid, alow) and b as (bhigh, blow)
// where amid, alow, blow all have the same size (toomLen). Then
// ahigh and bhigh need to have at least some digits but may not have more
// then toomLen.
// I let a(t) = ahigh*t^2 + amid*t + alow and b(t) = bhigh*t + blow.
// then I evaluate a() and b() at 0, +1, -1 and infinity - then I can
// interpolate through products of those values to get digits for my result.
// A classical 3x2 multiplication would use 6 partial products - this uses
// just 4 but obviously a bunch of extra additions and subtractions together
// with some general overhead. 
    size_t toomLen = std::max((N+2)/3, (M+1)/2);
#ifdef DEBUG
    assert(3*toomLen >= N && N > 2*toomLen);
    assert(2*toomLen >= M && M > toomLen);
    assert(N > 2*toomLen);
#endif // DEBUG
    size_t aHighLen = N-2*toomLen;
    size_t bHighLen = M-toomLen;
#ifdef DEBUG
    assert(aHighLen <= toomLen);
#endif // DEBUG
    ConstDigitPtr aLow = a;
    ConstDigitPtr aMid = a + toomLen;
    ConstDigitPtr aHigh = aMid + toomLen;
    ConstDigitPtr bLow = b;
    ConstDigitPtr bHigh = b + toomLen;

    DigitPtr aSum, aDiff, bSum, bDiff, D0, D1, D2, D3;
    Digit aSumTop, bSumTop;
    SignedDigit aDiffTop, bDiffTop, D1Top, D2Top;
    if constexpr (thread)
    {   aSum = setSize(workspace+4*toomLen, toomLen);
        aDiff = setSize(workspace+5*toomLen, toomLen);
        bSum = setSize(workspace+6*toomLen, toomLen);
        bDiff = setSize(res+2*toomLen, toomLen);
        D0 = setSize(res, 2*toomLen);
        D1 = setSize(workspace, 2*toomLen);
        D2 = setSize(workspace + 2*toomLen, 2*toomLen);
        D3 = setSize(res + 3*toomLen, N+M-3*toomLen);
        workspace = setSize(workspace + 7*toomLen, 4*workspaceSize(toomLen));
    }
    else
    {   aSum = setSize(res, toomLen);
        aDiff = setSize(res+toomLen, toomLen);
        bSum = setSize(res+2*toomLen, toomLen);
        bDiff = setSize(res+3*toomLen, toomLen);
        D0 = setSize(res, 2*toomLen);
        D1 = setSize(workspace, 2*toomLen);
        D2 = setSize(workspace + 2*toomLen, 2*toomLen);
        D3 = setSize(res + 3*toomLen, N+M-3*toomLen);
        workspace = setSize(workspace + 4*toomLen, workspaceSize(toomLen));
    }
    aSumTop = karaAdd(aLow, toomLen, aHigh, aHighLen, aSum);
    aDiffTop = aSumTop - karaSubtract(aSum, toomLen, aMid, toomLen, aDiff);
    aSumTop += karaAdd(aMid, toomLen, aSum, toomLen, aSum);
    bSumTop = karaAdd(bLow, toomLen, bHigh, bHighLen, bSum);
    bDiffTop = -karaSubtract(bLow, toomLen, bHigh, bHighLen, bDiff);
    if constexpr (thread)
    {   std::size_t wsize = workspaceSize(toomLen);
        setupKara(driverData.wd_2, aLow, toomLen, bLow, toomLen, D0,
                                   setSize(workspace, wsize));
        setupKara(driverData.wd_0, aSum, toomLen, bSum, toomLen, D1,
                                   setSize(workspace+wsize, wsize));
        setupKara(driverData.wd_1, aDiff, toomLen, bDiff, toomLen, D2,
                                   setSize(workspace+2*wsize, wsize));
        driverData.releaseWorkers(true);
        if (bHighLen <= 7)
            bigBySmallMul(aHigh, aHighLen, bHigh, bHighLen, D3);
        if (aHighLen <= 7)
            bigBySmallMul(bHigh, bHighLen, aHigh, aHighLen, D3);
        else innerGeneralMul(aHigh, aHighLen, bHigh, bHighLen, D3,
                             setSize(workspace+3*wsize, wsize));
        driverData.wait_for_workers(true);
#ifdef CHECK_TIMES
// Here I will repeat each of the thread-run multiplications to check them.
        stkvector<Digit> TD0(2*toomLen);
        stkvector<Digit> TD1(2*toomLen);
        stkvector<Digit> TD2(2*toomLen);
        stkvector<Digit> TD3(2*toomLen);
        simpleMul(aLow, toomLen, bLow, toomLen, TD0);
        simpleMul(aSum, toomLen, bSum, toomLen, TD1);
        simpleMul(aDiff, toomLen, bDiff, toomLen, TD2);
        simpleMul(aHigh, aHighLen, bHigh, bHighLen, TD3);
        int errcount = 0;
        for (size_t i=0; i<2*toomLen;i++)
        {   if (D0[i] != TD0[i])
            {   if (errcount < 5) std::printf("lowprod digit %d\n", (int)i);
                errcount++;
            }
            if (D1[i] != TD1[i])
            {   if (errcount < 5) std::printf("D1 digit %d\n", (int)i);
                errcount++;
            }
            if (D2[i] != TD2[i])
            {   if (errcount < 5) std::printf("D2 digit %d\n", (int)i);
                errcount++;
            }
            if (i < aHighLen+bHighLen && D3[i] != TD3[i])
            {   if (errcount < 5) std::printf("highprod digit %d\n", (int)i);
                errcount++;
            }
        }
        if (errcount != 0)
        {   std::printf("\n%%%%@@@ %d FAILURES\n", errcount);
            display("a", a, N);
            display("b", b, M);
            display("alow", a, toomLen);
            display("amid", aMid, toomLen);
            display("ahigh", aHigh, aHighLen);
            display("asum", aSum, toomLen);
            display("adiff", aDiff, toomLen);
            display("blow", b, toomLen);
            display("bhigh", bHigh, bHighLen);
            display("bsum", bSum, toomLen);
            display("bdiff", bDiff, toomLen);
            display("D0", D0, 2*toomLen);
            display("D1", D1, 2*toomLen);
            display("D2", D2, 2*toomLen);
            display("D3",  D3, aHighLen+bHighLen);
            display("TD0", TD0, 2*toomLen);
            display("TD1", TD1, 2*toomLen);
            display("TD2", TD2, 2*toomLen);
            display("TD3", TD3, aHighLen+bHighLen);
            std::abort();
        }
#endif // CHECK_TIMES
    }
    else
    {   innerGeneralMul(aSum, toomLen, bSum, toomLen, D1, workspace);
//      + aSumTop*bSum + bSumTop*aSum + aSumTop*bSumTop
        innerGeneralMul(aDiff, toomLen, bDiff, toomLen, D2, workspace);
//      + aDiffTop*bDiff + bDiffTop*aDiff + aDiffTop*bDiffTop
// noting that aDiffTop and bDiffTop are signed values.
    }
    D1Top = 0;
    switch (aSumTop)
    {   case 2:
            D1Top = karaAdd(bSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
            [[fallthrough]];
        case 1:
            D1Top += karaAdd(bSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
            break;
        case 0:
            break;
    }
    if (bSumTop != 0)
        D1Top += karaAdd(aSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
    D1Top += aSumTop*bSumTop;   
    D2Top = 0;
    switch (aDiffTop)
    {   case 1:
            D2Top = karaAdd(bDiff, toomLen, D2+toomLen, toomLen, D2+toomLen);
            break;
        case -1:
            D2Top = -karaSubtract(D2+toomLen, toomLen,
                                  bDiff, toomLen, D2+toomLen);
            break;
        case 0:
            break;
    }        
    switch (bDiffTop)
    {   case -1:
            D2Top -= karaSubtract(D2+toomLen, toomLen,
                                  aDiff, toomLen, D2+toomLen);
        break;
    }
    D2Top += aDiffTop*bDiffTop;   
// Now set D1 = D1-D2, D2=D1+D2
    Digit carry, borrow;
    karaDifferenceAndSum(D1, D2, 2*toomLen, carry, borrow);
    SignedDigit tempD1Top = D1Top - D2Top - borrow;
    D2Top = D1Top + D2Top + carry;
    D1Top = tempD1Top;
// Halve both of these
    D1Top = karaHalve(D1Top, D1, 2*toomLen);
    D2Top = karaHalve(D2Top, D2, 2*toomLen);
    if constexpr (!thread) // These already computed in the threaded version
    {   innerGeneralMul(aLow, toomLen, bLow, toomLen, D0, workspace);
        innerGeneralMul(aHigh, aHighLen, bHigh, bHighLen, D3, workspace);
    }
// I need to D1 -= D3; D2 -= D0;
    D1Top -= karaSubtract(D1, 2*toomLen, D3, aHighLen+bHighLen, D1);
    D2Top -= karaSubtract(D2, 2*toomLen, D0, 2*toomLen, D2);
// Now to assemble the final result I just need to cope with the fact
// the the partial products P0, D1, D1 and P3 overlap.
// So now I have
//   res:   D3hi  D3lo   xxx   D0Hi D0Lo
//                D1Top  D1Hi  D1Lo
//          D2Top D2Hi   D2Low
    carry = karaAdd(D1, toomLen,                    // D1Lo
                    res+toomLen, toomLen,           // D0Hi
                    res+toomLen);
    carry = karaAdd(D1+toomLen, toomLen,            // D1Hi
                    D2, toomLen, carry,             // D2Lo
                    res+2*toomLen);
    carry = karaAdd(D2+toomLen, toomLen,            // D2Hi
                    res+3*toomLen, toomLen, carry,  // D3Lo
                    res+3*toomLen);
    // karaCarry(carry, res+4*toomLen); by adding carry into D2Top I do this
    D2Top += carry;
// I need to merge in D1Top and D2TOP. Note that either could be positive
// or negative, and that is part of why I did not merge them in earlier.
    if (D1Top > 0)      karaCarry(D1Top, res+3*toomLen);
    else if (D1Top < 0) karaBorrow(-D1Top, res+3*toomLen);
    if (D2Top > 0)      karaCarry(D2Top, res+4*toomLen);
    else if (D2Top < 0) karaBorrow(-D2Top, res+4*toomLen);
}

[[gnu::always_inline]]
static void setupKara(arithlib_implementation::WorkerData& wd,
                      ConstDigitPtr a, std::size_t lena,
                      ConstDigitPtr b, std::size_t lenb,
                      DigitPtr result,
                      DigitPtr workspace)
{   wd.a = a;
    wd.lena = lena;
    wd.b = b;
    wd.lenb = lenb;
    wd.c = result;
    wd.w = workspace;
}

// This is the entrypoint for Karatsuba multiplication, and it
// will be called with N>=M amd with a workspace vector big enough for
// its needs.

// a := ahigh*x + alow;
// b := bhigh*x + blow;
//
// x^2 * (ahigh*bhigh) +
// x   * (alow*bhigh + ahigh*blow) +
//       (alow*blow)
//
// adiff := alow-ahigh;
// bdiff := blow-bhigh;
// p0 := alow*blow;
// p1 := adiff*bdiff;       ahigh*bhigh + alow*blow - alow*bhigh - ahigh*blow
// p2 := ahigh*bhigh;
//
// d0 := p0;                alow*blow
// d1 := p0 + p2 - p1;      alow*bhigh + amid*blow
// d2 := p2;                ahigh*bhigh
//
// Well sometimes adiff and/or bdiff are computed with the subtraction
// the other way round so as to leave a positive value there. In which
// case we need
// d1 := p1 - p0 - p2;      alow*bhigh + amid*blow

template <bool thread=false>
static void kara(ConstDigitPtr a, std::size_t N,
                 ConstDigitPtr b, std::size_t M,
                 DigitPtr result,
                 DigitPtr workspace)
{   std::size_t lowSize = (N+1)/2;
    std::size_t aHighLen = N-lowSize;
    std::size_t bHighLen = M-lowSize;
    ConstDigitPtr aHigh = a+lowSize;
    ConstDigitPtr bHigh = b+lowSize;
#ifdef TRACE_TIMES
    display("ahigh", aHigh, aHighLen);
    display("alow", a, lowSize);
    display("bhigh", bHigh, bHighLen);
    display("blow", b, lowSize);
#endif // TRACE_TIMES
// I have now split a and b into low and and high parts where the two
// low parts are half the size of the larger input (rounded up if that
// was odd). I now want to form |aHigh - aLow| and similarly for b
// keeping track of whether taking the absolute values involved a sign flip.
    DigitPtr aDiff, bDiff;
    DigitPtr ws;
    std::size_t wsize = workspaceSize(lowSize);
    if constexpr (thread)
    {   aDiff = workspace+2*lowSize;
        bDiff = workspace+3*lowSize;
        ws = workspace+4*lowSize;
    }
    else
    {   aDiff = result;
        bDiff = result+lowSize;
        ws = workspace+2*lowSize;
    }
    bool sign = absDifference(a, lowSize, aHigh, aHighLen, aDiff);
    if (absDifference(b, lowSize, bHigh, bHighLen, bDiff)) sign = !sign;
#ifdef TRACE_TIMES
    display("adiff", aDiff, lowSize);
    display("bdiff", bDiff, lowSize);
    std::cout << "% sign = " << sign << "\n";
#endif // TRACE_TIMES
    if constexpr (thread)
    {   setupKara(driverData.wd_0, aDiff, lowSize,
                                   bDiff, lowSize, workspace,
                                   setSize(ws, wsize));
        setupKara(driverData.wd_1, a, lowSize,
                                   b, lowSize, result,
                                   setSize(ws+wsize, wsize));
// Let the threads run while I do aHigh*bHigh. I expect that I will only
// launch threads when the inputs are rather large, and in particular large
// enough that the half-sized multiplications triggered here will be
// Karatsuba rather than classical.
        driverData.releaseWorkers(false);
        // Do this while worker threads do their stuff.
        innerGeneralMul(aHigh, aHighLen,
                        bHigh, bHighLen, result+2*lowSize,
                        setSize(ws+2*wsize, wsize));
        driverData.wait_for_workers(false);
#ifdef CHECK_TIMES
// Here I will repeat each of the thread-run multiplications to check them.
        stkvector<Digit> TD0(2*lowSize);
        stkvector<Digit> TD1(2*lowSize);
        stkvector<Digit> TD2(2*lowSize);
        simpleMul(a, lowSize, b, lowSize, TD0);
        simpleMul(aDiff, lowSize, bDiff, lowSize, TD1);
        if (aHighLen<=7 || bHighLen <= 7) std::printf("\n@@@ too small size\n");
        simpleMul(aHigh, aHighLen, bHigh, bHighLen, TD2);
        int errcount = 0;
        for (size_t i=0; i<2*lowSize;i++)
        {   if (result[i] != TD0[i])
            {   if (errcount < 5) std::printf("lowprod digit %d\n", (int)i);
                errcount++;
            }
            if(workspace[i] != TD1[i])
            {   if (errcount < 5) std::printf("midprod digit %d\n", (int)i);
                errcount++;
            }
            if (i < aHighLen+bHighLen && result[2*lowSize+i] != TD2[i])
            {   if (errcount < 5) std::printf("highprod digit %d\n", (int)i);
                errcount++;
            }
        }
        if (errcount != 0)
        {   std::printf("\n%%%%@@@ %d FAILURES\n", errcount);
            display("alow", a, lowSize);
            display("blow", b, lowSize);
            display("ahigh", aHigh, aHighLen);
            display("bhigh", bHigh, bHighLen);
            display("adiff", aDiff, lowSize);
            display("bdiff", bDiff, lowSize);
            display("lowprod", result, 2*lowSize);
            display("midprod", workspace, 2*lowSize);
            display("hiprod",  result+2*lowSize, aHighLen+bHighLen);
            display("TD0", TD0, 2*lowSize);
            display("TD1", TD1, 2*lowSize);
            display("TD2", TD2, aHighLen+bHighLen);
            std::abort();
        }
#endif
    }
    else
    {   innerGeneralMul(aDiff, lowSize,
                        bDiff, lowSize, workspace, ws);
        innerGeneralMul(a, lowSize,
                        b, lowSize, result, ws);
        innerGeneralMul(aHigh, aHighLen,
                        bHigh, bHighLen, result+2*lowSize, ws);
    }
#ifdef TRACE_TIMES
    display("lowprod", result, 2*lowSize);
    display("midprod", workspace, 2*lowSize);
    display("highprod", result+2*lowSize, aHighLen+bHighLen);
#endif // TRACE_TIMES
// At this stage result has aHigh*bHigh in its top half and aLow*bLow
// in its bottom half. Then workspace hold aDiff*bDiff. I now need to
// combine these to get my final result. 
// If sign is false workspace holds aHigh*bHigh+aLow*bLow-middleTerms
// so I want to go
// 1.    workspace = aHigh*bHigh - workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// Step 1 can generate a borrow and step 2 a carry, so on input to step 3
// there is an extra -1, 0 or +1 to deal with.
// If sign is true I want
// 1.    workspace = aHigh*bHigh + workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// and now each of steps 1 and 2 may generate a carry, so step 3 starts
// with an extra 0, +1 or +2.
    int extra = 0;
    if (sign) extra =
        karaAdd(workspace, 2*lowSize,
                result+2*lowSize, aHighLen+bHighLen,
                workspace);
    else extra =
        -karaRevSubtract(workspace, 2*lowSize,
                         result+2*lowSize, aHighLen+bHighLen,
                         workspace);
    extra += karaAdd(result, 2*lowSize,
                     workspace, 2*lowSize, workspace);
// extra can now be -1, 0, 1 or 2
    Digit carry = karaAdd(workspace, 2*lowSize,
                          result+lowSize, 2*lowSize, result+lowSize);
    karaCarry(carry, result+3*lowSize);
    if (extra > 0) karaCarry(extra, result+3*lowSize);
    else if (extra < 0) karaBorrow(-extra, result+3*lowSize);
#ifdef TRACE_TIMES
    display("result", result, M+N);
#endif // TRACE_TIMES
}  

public:

#if defined USE_MICROSOFT_SRW

static void workerThread(WorkerData* wd)
{   ThreadLocal::initialize();
    AcquireSRWLockExclusive(&wd->mutex[2]);
    AcquireSRWLockExclusive(&wd->mutex[3]);
    wd->ready = true;
    int receive_count = 0;
    for (;;)
    {   AcquireSRWLockExclusive(&wd->mutex[receive_count]);
        if (wd->quit_flag) return;
// This is where I do some work! I think it would in general have been
// silly to launch a thread if the sub-multiplication was small enough to
// call for classical multiplication... so I always use Karatsuba here.
        BigMultiplication::kara(wd->a, wd->lena,
                                wd->b, wd->lenb,
                                wd->c,
                                wd->w);
        ReleaseSRWLockExclusive(&wd->mutex[receive_count^2]);
        receive_count = (receive_count + 1) & 3;
    }
}

#elif defined USE_MICROSOFT_MUTEX

static void workerThread(WorkerData* wd)
{   WaitForSingleObject(wd->mutex[2], MICROSOFT_INFINITE);
    WaitForSingleObject(wd->mutex[3], MICROSOFT_INFINITE);
    wd->ready = true;
    int receive_count = 0;
    for (;;)
    {
// This WaitFor could wait for the entire Reduce run any only be signalled
// during close-down, so putting a timeout on it would nor make sense.
        WaitForSingleObject(wd->mutex[receive_count], MICROSOFT_INFINITE);
        if (wd->quit_flag) return;
// This is where I do some work! I think it would in general have been
// silly to launch a thread if the sub-multiplication was small enough to
// call for classical multiplication... so I always use Karatsuba here.
        BigMultiplication::kara(wd->a, wd->lena,
                                wd->b, wd->lenb,
                                wd->c,
                                wd->w);
        ReleaseMutex(wd->mutex[receive_count^2]);
        receive_count = (receive_count + 1) & 3;
    }
}

#else // Here I use C++ std::mutex

static void workerThread(WorkerData* wd)
{   wd->mutex[2].lock();
    wd->mutex[3].lock();
    wd->ready = true;
    int receive_count = 0;
    for (;;)
    {   wd->mutex[receive_count].lock();
        if (wd->quit_flag) return;
// This is where I do some work! I think it would in general have been
// silly to launch a thread if the sub-multiplication was small enough to
// call for classical multiplication... so I always use Karatsuba here.
        BigMultiplication::kara(wd->a, wd->lena,
                                wd->b, wd->lenb,
                                wd->c,
                                wd->w);
        wd->mutex[receive_count^2].unlock();
        receive_count = (receive_count + 1) & 3;
    }
}

#endif // definition of workerThread

}; // end of BigMultiplication class

inline void workerThread(WorkerData* wd)
{   BigMultiplication::workerThread(wd);
}

inline std::atomic<bool> ManageWorkers::threadsInUse(false);

// Now the external world needs access to the entrypoint "generalMul"
// so I provide a shim that calls it so that others do not need to
// fuss about the class name.

[[gnu::always_inline]]
inline void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{   BigMultiplication::generalMul(a, N, b, M, result);
}

// verySimpleMul is intended to deliver the same results as generalMul
// but using clear (if less efficient code) so it can be use as a
// reference implementation during testing.

inline void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   BigMultiplication::verySimpleMul(a, N, b, M, result);
}

#ifdef MEASURE_WORKSPACE

int main()
{
    const std::size_t limit = 4000;
    Digit a[10*limit];
    Digit b[10*limit];
    Digit res[20*limit];
    for (int i=0; i<limit; i++) a[i] = b[i] = 0xbad999bad999bad9;
    worstN = worstM = 0;
    worstRatio = 0.0;
    for (std::size_t M=8; M<limit; M++)
    for (std::size_t N=M; N<limit; N++)
    {   if (N==limit-1) N = 10*limit-1;
        generalMul(a, N, b, M, res);
    }
    std::cout << "worst ratio = " << worstRatio
              << " : " << (worstRatio/std::log(worstM))
              << " with N=" << worstN << " M=" << worstM << "\n";
    return 0;
}

#endif // MEASURE_WORKSPACE

// End of integer multiplication code.
//=========================================================================


// Now some code that delivers just some of the digits from a product.

// Return (in w) the digits from "from" to "to" (inclusive) from
// the product of u by v. "from" defaults to zero and "to" to a high
// value - the product runs from 0 (inclusive) to N+M (exclusive)
// and if "to" is overlarge no output data beyond the real digits of
// the product are put into w.
// When "from" is non-zero the lowest result in w may be incorrect by
// being low by up to [maybe] min(N,M). That is because in the perfect
// result there may have been carries passed on up from lower partial
// products.

// Note that the digit correspoding to "from" is put in the first
// location in the output vector, and that vector should be
// (min(N+M-1, to)-from) in length.

// The "reference" version does a full multiplication (which may use
// Karatsuba) and then keeps just some of the digits. If only a small
// slice of the result is needed the full multiplication will generate
// many unnecessary digits. But the code here is very simple and
// can be used to document the intent of everything else. I will also use
// it when the sizes M and N are very different.

inline void referencePartMul(const std::uint64_t* u, size_t N,
                             const std::uint64_t* v, size_t M,
                             std::uint64_t* w,
                             size_t from=0, size_t to=SIZE_MAX)
{   stkvector<Digit> temp(N+M);
// This reference implementation just forms the full product and then
// copies the words [from..to] to where they are needed. It needs
// workspace for the full product to calculated, and
// stkvector<Digit> temp(N+M) arranges for that one way or another.
    generalMul(u, N, v, M, temp);
    to = std::min(to, N+M-1);
    for (size_t i=from; i<=to; i++) w[i-from] = temp[i];
}

// The "classical" version is what will be used for multiplications
// involving not too many digits, and is pretty straightforward.

inline void classicalPartMul(const std::uint64_t* u, size_t N,
                             const std::uint64_t* v, size_t M,
                             std::uint64_t* w,
                             size_t from=0, size_t to=SIZE_MAX)
{   Digit lo=0, hi=0, carry=0, hi1;
    to = std::min(to, N+M-1);
// The curious expression here is intended to lead to branch-free code
// that sets the range of digits to be combined forming partial
// products. The idea is that ((-boolVal) & X will) yield the
// same result as (boolVal ? X : 0). So here we have
//     k < M :    imin = 0
//     k >= M :   imin = k - kenv + 1
//     k < N :    imax = k
//     k >= N :   imax = N - 1
    if (from != 0)
    {
        size_t imin = (-(from>=M+1)) & (from - M);
        size_t imax = N - 1 - ((-(from<N+1)) & (N - from));
        for (size_t i=imin; i<=imax; i++)
        {   arithlib_assert(from>=i+1);
            multiply64(u[i], v[from-i-1], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
// I form the partial products for one earlier row because the high
// parts of them contribute fully to the digits that I want. But I discard
// the result apart from keeping anything that has carried out from it.
        // w[-1] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    for (size_t k=from; k<=to; k++)
    {   size_t imin = (-(k>=M)) & (k - M + 1);
        size_t imax = N - 1 - ((-(k<N)) & (N - 1 - k));
        for (size_t i=imin; i<=imax; i++)
        {   multiply64(u[i], v[k-i], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
        w[k-from] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
}

// A "fast" multiply decomposes the calculation in a way based on
// work by Mulder.
//
// See Mulder, T. "On Short Multiplications and Divisions." AAECC 11,
// 6988 (2000). https://doi.org/10.1007/s002000000037
// and also see
// G Henriot and P Zimmermanm, "A long note on Mulder's Short Product"
// Journal of Symbolic Computation Volume 37, 3, March 2004, Pages 391-401

inline Digit fastPartMulAdd(const std::uint64_t* u, size_t N,
                            const std::uint64_t* v, size_t M,
                            std::uint64_t* w,
                            size_t from, size_t to);

// This forms a sub-product and adds it in. This is made into
// a separate function allowing for a shift by uShift, vShift
// because from, to and w need adjustment and the calculations that
// set their values seemed most easily expressed here.

inline Digit shiftedFastPartMulAdd(const std::uint64_t* u, size_t N,
                                   const std::uint64_t* v, size_t M,
                                   std::uint64_t* w,
                                   size_t from, size_t to,
                                   size_t uShift, size_t vShift)
{   size_t h = uShift + vShift;
    if (to <= h) return 0;
    to -= h;
    if (from < h)
    {   w = w + (h-from);
        from = 0;
    }
    else
    {   from -= h;
    }
    return fastPartMulAdd(u+uShift, N,
                          v+vShift, M,
                          w,
                          from, to);
}

// This computes the product of two numbers each of which are N digits long
// and where "to" is such that quite a lot of the high digits of the
// result are not wanted.

inline void lowPartMul(const std::uint64_t* u,
                       const std::uint64_t* v, size_t N,
                       std::uint64_t*  w,
                       size_t from, size_t to)
{   size_t split = std::min(N, ((7*to)/10 + 1) & ~1);
    size_t gap = N-split;
    if (gap <= 3) split = N;
    referencePartMul(u, split,
                     v, split,
                     w,
                     from, to);
    if (split == N) return;
    shiftedFastPartMulAdd(u, N,
                          v, gap,
                          w,
                          from, to,
                          0, split);
    shiftedFastPartMulAdd(u, split,
                          v, gap,
                          w,
                          from, to,
                          split, 0);
}

// I code this so that w does not overshoot the end of the vector w,
// even though in C++ it is legal to have a pointer to the location
// one beyond a vector.

inline Digit propagateCarry(Digit carry, std::uint64_t* w, size_t len)
{   if (carry==0 || len==0) return carry;
    for (;;)
    {   carry = addWithCarry(*w, carry, *w);
        if (carry==0) return 0;
        len--;
        if (len==0) return carry;
        w++;
    }
}

inline const size_t midmul_threshold = 20;

inline void fastPartMul(const std::uint64_t* u, size_t N,
                        const std::uint64_t* v, size_t M,
                        std::uint64_t* w,
                        size_t from=0, size_t to=SIZE_MAX)
{
// Any digits in either u or v beyond "to" can be discarded since they can
// not contribute to the desired part of the result.
    if (to<N-1) N = to+1;
    if (to<M-1) M = to+1;
    if (N > M)          // ensure that u is the shorter argument
    {   std::swap(u, v);
        std::swap(N, M);
    }
    if (from>N-1)
    {   size_t shift = from-(N-1);
        if (M-shift >= N)
        {   v += shift;
            M -= shift;
            to -= shift;
            from -= shift;
        }
    }
    to = std::min(to, N+M-1);
// If either the smaller operand is small or if the slice of the result
// I want is narrow I fall back to classical long multiplication.
    if ((to-from) < midmul_threshold || N < midmul_threshold)
    {   classicalPartMul(u, N, v, M, w, from, to);
        return;
    }
    if (3*N < M)
    {
// This special case will apply if the two input integers are very
// different in size. It is here because a previous revision of this
// code could end up recursing ridiculously deeply in such cases when
// in fact almost all of the product needed computing so calculating
// it all as is done here was not a severe overhead.
        referencePartMul(u, N, v, M, w, from, to);
        return;
    }
// The following rather strange calculation decide how to split the
// full product calculation into parts. The ideas built into it
// are:
// . We can never split off a balanced multiplication larger than NxN.
// . When we split one off it should have an even size since we hope
//   to be able to use Karatsuba on it.
// . The size should be such that the split-off square multiplication
//   uses input data beyond the "from" threshold. Here I set things
//   such that if I will want K high digits in my result I form the
//   product of two 0.7K digit numbers for form a 1.4K digit intermediate
//   result and then ignore the low 0.4K digits of that. The fraction 0.7
//   is not going to be optimal - even more in the case of unbalanced
//   lengths of inputs, but is probably a reasonable approximation to the
//   best and so is what I use. If one was in a situation where both
//   arguments were the same fixed size and the fraction of the output
//   needed was fixed it would be proper to tune this carefully.
    size_t split = std::min(N, ((7*(N+M-from))/10 + 1) & ~1);
// Do the first square multiplication... This is always done as by forming a
// full 2*split digit product and the intent is that it always uses
// Karatsuba.
// Well if "to" is a significant limit on how many digits are required
// this might be improved upon by doing Mulder-like decompostion upwards
// towards "to" as well as downwards towards "from".
    size_t shift = N+M-2*split;
// I will generally need to add in components of the final result, and
// so I zero out parts of w that will not be set by filling in the first
// product.
    for (size_t i=from; i<shift && i<=to; i++) w[i-from] = 0;
    lowPartMul(u+(N-split), v+(M-split), split,
               from>shift ? w : w + (shift-from),
               from>shift ? from-shift : 0,
               to-shift);
    size_t P = N+M-1-split;     // higest digit from lower parts
    if (from > P) return;
    Digit carry;
    if (split == N)
    {   if (N == M) return;
        carry = fastPartMulAdd(u, N, v, M-split, w, from, to);
    }
    else
    {   shift = M-split;
// This can recurse and as such is ugly - but at an earlier stage I have
// ensured that M can only be a modest multiple of N so the recursion
// depth here can never be deep enough to worry me.
        carry = fastPartMulAdd(u, N,
                               v, shift,
                               w,
                               from, to);
        carry += shiftedFastPartMulAdd(u, N-split,
                                       v, split,
                                       w,
                                       from, to,
                                       0, shift);
    }
    if (to > P) propagateCarry(carry, w+(P-from+1), to-P);
}

// Note that default values for from and to were set up in the declaration
// and must not be repeated here.

inline Digit fastPartMulAdd(const std::uint64_t* u, size_t N,
                            const std::uint64_t* v, size_t M,
                            std::uint64_t* w,
                            size_t from, size_t to)
{   to = std::min(to, N+M-1);
// A special case here is when M is much larger then N, since with
// naive code this can end up allocating a really big temporary vector
// and calling fastMul to fill it in - and that will hive of a chunk
// of size N at the top and then recurse to get here again. The effect
// can be both very deep recursion and use of a quite unreasonable
// amount of working space. But I avoid getting here in that case!
    stkvector<Digit> temp(to-from+1);
    fastPartMul(u, N, v, M, temp, from, to);
    Digit carry = 0;
    for (size_t i=0; i<N+M-from+1 && i<=to-from; i++)
        carry = addWithCarry(w[i], temp[i], carry, w[i]);
    return carry;
}

// Returns the digit at position "from:bits" from the product of u by v.
// Some low bits of the result may be incorrect with the result being
// potentially less than the ideal result by at most min(M,N).
// This is because in the perfect result there may have been carries
// passed on up from lower partial products.

inline Digit fastSlice(const std::uint64_t* u, size_t N,
                       const std::uint64_t* v, size_t M,
                       size_t from=0, size_t bits = 0)
{   stkvector<Digit> shiftedU(N+1);
    if (bits != 0)
    {   Digit carry = 0;
        for (size_t i=N; i!=0; i--)
        {   Digit d = u[i-1];
            shiftedU[i] = (d>>bits) | (carry<<(64-bits));
            carry = d;
        }
        shiftedU[0] = carry<<(64-bits);
        u = shiftedU;
        N++;
        from++;
    }
    Digit lo=0, hi=0, hi1;
// The curious expression here is intended to lead to branch-free code
// that sets the range of digits to be combined forming partial
// products. The idea is that ((-boolVal) & X will) yield the
// same result as (boolVal ? X : 0). So here we have
//     k < M :    imin = 0
//     k >= M :   imin = k - kenv + 1
//     k < N :    imax = k
//     k >= N :   imax = N - 1
//
// First generate high parts of the partial products from the row
// below "from" and leave that in hi.
    size_t imin = (-(from>=M+1)) & (from - M);
    size_t imax = N - 1 - ((-(from<N+1)) & (N - from));
    for (size_t i=imin; i<=imax; i++)
    {   multiply64(u[i], v[from-i-1], lo, hi1, lo);
        hi += hi1;
    }
// Now add in the low parts of the partial products in row "from".
    imin = (-(from>=M)) & (from - M + 1);
    imax = N - 1 - ((-(from<N)) & (N - 1 - from));
    for (size_t i=imin; i<=imax; i++)
        multiply64(u[i], v[from-i], hi, hi1, hi);
    return hi;
}

// This is the main entrypoint to the integer multiplication code. It
// takes two signed numbers and forms their product.

inline void bigmultiply(const std::uint64_t* a, std::size_t lena,
                        const std::uint64_t* b, std::size_t lenb,
                        std::uint64_t* c, std::size_t &lenc)
{
// For this a and b must be treated as 2s complement signed numbers,
// and the length lenc returned but ensure that the top digit of the
// product is not a redundant zero or -1.
    generalMul(a, lena, b, lenb, c);
    if (negative(a[lena-1])) subtractWithBorrow(c+lena, b, c+lena, lenb);
    if (negative(b[lenb-1])) subtractWithBorrow(c+lenb, a, c+lenb, lena);
    lena += lenb;
// A case like {0,0x80000...} times the same leads at this stage to
// {0, 0, 0x40000...} and the length needs to be shrunk by two words. The
// way I code this is intended to have a chance of compiling into branch-
// free code and execute faster than "if (shrinkable(..)) lena--;".
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lenc = lena;
}

inline void classicalbigmultiply(const std::uint64_t* a, std::size_t lena,
                                 const std::uint64_t* b, std::size_t lenb,
                                 std::uint64_t* c, std::size_t &lenc)
{
// For this a and b must be treated as 2s complement signed numbers,
// and the length lenc returned but ensure that the top digit of the
// product is not a redundant zero or -1.
    if (lena < lenb)
    {   std::swap(a, b);
        std::swap(lena, lenb);
    }
    verySimpleMul(a, lena, b, lenb, c);
    if (negative(a[lena-1])) subtractWithBorrow(c+lena, b, c+lena, lenb);
    if (negative(b[lenb-1])) subtractWithBorrow(c+lenb, a, c+lenb, lena);
    lena += lenb;
// A case like {0,0x80000...} times the same leads at this stage to
// {0, 0, 0x40000...} and the length needs to be shrunk by two words. The
// way I code this is intended to have a chance of compiling into branch-
// free code and execute faster than "if (shrinkable(..)) lena--;".
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lenc = lena;
}

//===========================================================================
//===========================================================================

inline std::intptr_t Times::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n = lena+lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
// bigmultiply already tries to detect and handle small cases specially,
// but it could be that detecting some very small cases here - ie even
// earlier - would be worthwhile.
    bigmultiply(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t Times::op(SignedDigit a, SignedDigit b)
{   SignedDigit hi;
    Digit lo;
    signedMultiply64(a, b, hi, lo);
    if ((hi==0 && positive(lo)) ||
        (hi==-1 && negative(lo)))
    {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
            LIKELY
            return intToHandle(static_cast<SignedDigit>(lo));
        std::uint64_t* r = reserve(1);
        r[0] = lo;
        return confirmSize(r, 1, 1);
    }
    std::uint64_t* r = reserve(2);
    r[0] = lo;
    r[1] = hi;
    return confirmSize(r, 2, 2);
}

inline std::intptr_t Times::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* c = reserve(lenb+1);
    Digit hi = 0;
    for (std::size_t i=0; i<lenb; i++)
        multiply64(a, b[i], hi, hi, c[i]);
    c[lenb] = hi;
    if (negative(a))
    {   Digit carry = 1;
        for (std::size_t i=0; i<lenb; i++)
            carry = addWithCarry(c[i+1], ~b[i], carry, c[i+1]);
    }
    if (negative(b[lenb-1])) c[lenb] -= a;
    std::size_t lenc = lenb+1;
    truncatePositive(c, lenc);
    truncateNegative(c, lenc);
    return confirmSize(c, lenb+1, lenc);
}

inline std::intptr_t Times::op(std::uint64_t* a, SignedDigit b)
{   return Times::op(b, a);
}

inline std::intptr_t ClassicalTimes::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n = lena+lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
// bigmultiply already tries to detect and handle small cases specially,
// but it could be that detecting some very small cases here - ie even
// earlier - would be worthwhile.
    classicalbigmultiply(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t ClassicalTimes::op(SignedDigit a, SignedDigit b)
{   SignedDigit hi;
    Digit lo;
    signedMultiply64(a, b, hi, lo);
    if ((hi==0 && positive(lo)) ||
        (hi==-1 && negative(lo)))
    {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
            LIKELY
            return intToHandle(static_cast<SignedDigit>(lo));
        std::uint64_t* r = reserve(1);
        r[0] = lo;
        return confirmSize(r, 1, 1);
    }
    std::uint64_t* r = reserve(2);
    r[0] = lo;
    r[1] = hi;
    return confirmSize(r, 2, 2);
}

inline std::intptr_t ClassicalTimes::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* c = reserve(lenb+1);
    Digit hi = 0;
    for (std::size_t i=0; i<lenb; i++)
        multiply64(a, b[i], hi, hi, c[i]);
    c[lenb] = hi;
    if (negative(a))
    {   Digit carry = 1;
        for (std::size_t i=0; i<lenb; i++)
            carry = addWithCarry(c[i+1], ~b[i], carry, c[i+1]);
    }
    if (negative(b[lenb-1])) c[lenb] -= a;
    std::size_t lenc = lenb+1;
    truncatePositive(c, lenc);
    truncateNegative(c, lenc);
    return confirmSize(c, lenb+1, lenc);
}

inline std::intptr_t ClassicalTimes::op(std::uint64_t* a, SignedDigit b)
{   return ClassicalTimes::op(b, a);
}

// For big multi-digit numbers squaring can be done almost twice as fast
// as general multiplication.
// eg (a0,a1,a2,a3)^2 can be expressed as
// a0^2+a1^2+a2^2+a3^2 + 2*(a0*a1+a0*a2+a0*a3+a1*a2+a1*a3+a2*a3)
// where the part that has been doubled uses symmetry to reduce the work.
//
// For negative inputs I can form the product first treating the inputs
// as if they had been unsigned, and then subtract 2*2^w*a from the result.
//
// I think my view here is that I should still be willing to move across
// to Karatsuba, but only at a distinctly larger threshold than for
// simple multiplication. Just where that threshold should be is not really
// clear to me, but for now I am setting it as 3 times the point at which
// ordinary multiplications moves on from classical methods.

inline void bigsquare(std::uint64_t* a, std::size_t lena,
                      std::uint64_t* r, std::size_t &lenr)
{   if (lena > 24)
    {   bigmultiply(a, lena, a, lena, r, lenr);
        return;
    }
    for (std::size_t i=0; i<2*lena; i++) r[i] = 0;
    Digit carry;
    lenr = 2*lena;
    for (std::size_t i=0; i<lena; i++)
    {   Digit hi = 0;
// Note that all the terms I add in here will need to be doubled in the
// final accounting.
        for (std::size_t j=i+1; j<lena; j++)
        {   Digit lo;
            multiply64(a[i], a[j], hi, hi, lo);
            hi += addWithCarry(lo, r[i+j], r[i+j]);
        }
        r[i+lena] = hi;
    }
// Double the part that has been computed so far.
    carry = 0;
    for (std::size_t i=0; i<2*lena; i++)
    {   Digit w = r[i];
        r[i] = (w << 1) | carry;
        carry = w >> 63;
    }
// Now add in the bits that do not get doubled.
    carry = 0;
    Digit hi = 0;
    for (std::size_t i=0; i<lena; i++)
    {   Digit lo;
        multiply64(a[i], a[i], r[2*i], hi, lo);
        carry = addWithCarry(lo, carry, r[2*i]);
        carry = addWithCarry(hi, r[2*i+1], carry, r[2*i+1]);
    }
// Now if the input had been negative I have a correction to apply...
// I subtract 2a from the top half of the result.
    if (negative(a[lena-1]))
    {   Digit carry = 1;
        int fromprev = 0;
        for (std::size_t i=0; i<lena; i++)
        {   Digit d = a[i];
            Digit w = (d<<1) | fromprev;
            fromprev = static_cast<int>(d>>63);
            carry = addWithCarry(r[lena+i], ~w, carry, r[lena+i]);
        }
    }
// The actual value may be 1 word shorter than this.
//  test top digit or r and if necessary reduce lenr.
    truncatePositive(r, lenr);
    truncateNegative(r, lenr);
}

inline std::intptr_t Square::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    std::size_t n = 2*lena;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    bigsquare(a, lena, p, final_n);
    return confirmSize(p, n, final_n);
}

inline std::intptr_t Square::op(SignedDigit a)
{   Digit hi, lo;
    multiply64(a, a, hi, lo);
    if (a < 0) hi -= 2u*static_cast<Digit>(a);
// Now I have a 128-bit product of the inputs
    if ((hi == 0 && positive(lo)) ||
        (hi == static_cast<Digit>(-1) && negative(lo)))
    {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
            LIKELY
            return intToHandle(static_cast<SignedDigit>(lo));
        else
        {   std::uint64_t* p = reserve(1);
            p[0] = lo;
            return confirmSize(p, 1, 1);
        }
    }
    std::uint64_t* p = reserve(2);
    p[0] = lo;
    p[1] = hi;
    return confirmSize(p, 2, 2);
}

inline std::intptr_t Isqrt::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Isqrt::op(static_cast<SignedDigit>(a[0]));
    std::size_t lenx = (lena+1)/2;
    std::uint64_t* x = reserve(lenx);
    for (std::size_t i=0; i<lenx; i++) x[i] = 0;
    std::size_t bitstop = a[lena-1]==0 ? 0 : 64 - nlz(a[lena-1]);
    bitstop /= 2;
    if ((lena%2) == 0) bitstop += 32;
    x[lenx-1] = 1ULL << bitstop;
    if (bitstop == 63) x[lenx-1]--; // ensure it is still positive!
// I now have a first approximation to the square root as a number that is
// a power of 2 with about half the bit-length of a. I will degenerate into
// using generic arithmetic here even though that may have extra costs.
//
// I could perhaps reasonably use uint64_t arithmetic for a first few
// iterations, only looking at the most significant digit of the input.
// That would save time, however at present I do not expect this function
// to be time critical in any plausible application, and so I will keep
// things simple(er).
    Bignum biga(true, vectorToHandle(a));
    Bignum bigx(true, confirmSize(x, lenx, lenx));
// I will do the first step outside the loop to guarantee that my
// approximation is an over-estimate before I try the end-test.
//         bigx = (bigx + biga/bigx) >> 1;
// The push/pop mess here feels extreme and I should probably re-code this
// using lower level interfaces.
    Bignum w1 = biga/bigx;
    w1 = bigx + w1;
    bigx = w1 >> 1;
    for (;;)
    {   w1 = biga/bigx;
        w1 = bigx + w1;
        Bignum y = w1 >> 1;
        if (y >= bigx) break;
        bigx = y;
    }
// The Bignum "biga" encapsulated my argument: when its destructor is called
// I do not want the input vector "a" to be clobbered, so I clobber the
// bignum first to break the link. Ditto bigx.
    biga.val = 0;
    std::intptr_t r = bigx.val;
    bigx.val = 0;
    return r;
}

inline std::intptr_t Isqrt::op(SignedDigit aa)
{   if (aa <= 0) return intToBignum(0);
    Digit a = static_cast<Digit>(aa);
    std::size_t w = 64 - nlz(a);
    Digit x0 = a >> (w/2);
// The iteration here converges to sqrt(a) from above, but I believe that
// when the value stops changing it will be at floor(sqrt(a)). There are
// some cases where the sequence ends up alternating between two adjacent
// values. Because my input is at most 2^63-1 the number of iterations
// written here will always suffice.
    Digit x1 = (x0 + a/x0)/2;
    Digit x2 = (x1 + a/x1)/2;
    if (x2 >= x1) return unsignedIntToBignum(x1);
    Digit x3 = (x2 + a/x2)/2;
    if (x3 >= x2) return unsignedIntToBignum(x2);
    Digit x4 = (x3 + a/x3)/2;
    if (x4 >= x3) return unsignedIntToBignum(x3);
    Digit x5 = (x4 + a/x4)/2;
    if (x5 >= x4) return unsignedIntToBignum(x4);
    return unsignedIntToBignum(x5);
}

// This raises a bignum to a positive integer power. If the power is n then
// the size of the output may be n*lena. The two vectors v and w are workspace
// and must both be of size (at least) the size that the result could end
// up as. Well with greater subtlty we can see that the sum of their sizes
// must be at least the size of the result, but it is not clear that any
// useful saving spece saving can be found down that path.

inline void bigpow(std::uint64_t* a, std::size_t lena,
                   Digit n,
                   std::uint64_t* v,
                   std::uint64_t* w,
                   std::uint64_t* r, std::size_t &lenr, std::size_t maxlenr)
{   if (n == 0)
    {   r[0] = 0;
        lenr = 1;
        return;
    }
//  LispObject r = fixnum_of_int(1);
//  while (n != 1)
//  {   if ((n & 1) != 0) r = Times::op(r, a);
//      a = Square::op(a);
//      n = n/2;
//  }
//  return Times::op(r, a);
    internalCopy(a, lena, v);
    std::size_t lenv = lena, lenw;
    r[0] = 1;
    lenr = 1;
    while (n != 1)
    {   if ((n & 1) != 0)
        {   bigmultiply(r, lenr, v, lenv, w, lenw);
            internalCopy(w, lenr=lenw, r);
        }
        bigsquare(v, lenv, w, lenw);
        internalCopy(w, lenv=lenw, v);
        n = n/2;
    }
    bigmultiply(r, lenr, v, lenv, w, lenw);
    internalCopy(w, lenr=lenw, r);
}

// In cases where n is too large this can fail. At present I deal with that
// with arithlib_assert() statements rather than any comfortable scheme for
// reporting the trouble.

// The code that dispatches into here should have filtered cases such that
// the exponent n is not 0, 1 or 2 here.

inline std::intptr_t Pow::op(std::uint64_t* a, SignedDigit n)
{   std::size_t lena = numberSize(a);
//  1^(-n) == 1,
//  (-1)^(-n) == 1 if n is even or -1 if n is odd.
//  a^(-n) == 0 when a is not -1, 0 or 1.
    if (n < 0)
    {   int z = 0;
        if (lena == 0)
        {   if (static_cast<SignedDigit>(a[0]) == 1) z = 1;
            else if (static_cast<SignedDigit>(a[0]) == -1)
                z = (n%1==0 ? 1 : -1);
            else arithlib_assert(a[0] != 0u);
        }
// 0^(-n) is an error
// 1^(-n) = 1
// (-1)^(-n) = +1 or -1 depending on whether n is odd or even
// x^(-n) = 0 otherwise.
        return intToBignum(z);
    }
// 6^n = 0
    std::size_t bitsa = bignumBits(a, lena);
    Digit hi, bitsr;
    multiply64(n, bitsa, hi, bitsr);
    arithlib_assert(hi==0); // Check that size is at least somewhat sane!
// I estimate the largest size that my result could be, but then add
// an extra word because the internal working of multiplication can
// write a zero beyond its true result - eg if you are multiplying a pair
// of 1-word numbers together it will believe that the result could be 2
// words wide even if in fact you know it will not be.
    Digit lenr1 = 2 + bitsr/64;
    std::size_t lenr = static_cast<std::size_t>(lenr1);
// if size_t was more narrow than 64-bits I could lose information in
// truncating from uint64_t to size_t.
    Digit olenr = lenr;
    std::uint64_t* r = reserve(lenr);
    std::uint64_t* v = reserve(lenr);
    std::uint64_t* w = reserve(lenr);
    bigpow(a, lena, static_cast<Digit>(n), v, w, r, lenr, lenr);
    abandon(w);
    abandon(v);
    return confirmSize(r, olenr, lenr);
}

// Again the cases n = 0, 1 and 2 have been filtered out

inline std::intptr_t Pow::op(SignedDigit a, SignedDigit n)
{   if (n < 0)
    {   int z = 0;
        if (a == 1) z = 1;
        else if (a == -1) z = (n%1==0);
        else arithlib_assert(a != 0);
        return intToHandle(z);
    }
    if (a == 0) return intToHandle(0);
    else if (a == 1) return intToHandle(a);
    else if (n == 0) return intToHandle(1);
    Digit absa = (a < 0 ? -static_cast<Digit>
                          (a) : static_cast<Digit>(a));
    std::size_t bitsa = 64 - nlz(absa);
    Digit hi, bitsr;
    multiply64(n, bitsa, hi, bitsr);
    Digit lenr1 = 2 + bitsr/64;
    if (bitsr < 64) // Can do all the work as machine integers.
    {   SignedDigit result = 1;
        for (;;)
        {   if (n%2 != 0) result *= a;
            if ((n = n/2) == 0) break;
            a *= a;
        }
        return intToBignum(result);
    }
    std::size_t lenr = static_cast<std::size_t>(lenr1);
// if size_t was more narrow than 64-bits I could lose information in
// truncating from uint64_t to size_t.
    Digit olenr = lenr;
    std::uint64_t* r = reserve(lenr);
    std::uint64_t* v = reserve(lenr);
    std::uint64_t* w = reserve(lenr);
    Digit aa[1] = {static_cast<Digit>(a)};
    bigpow(aa, 1, static_cast<Digit>(n), v, w, r, lenr, lenr);
    abandon(w);
    abandon(v);
    return confirmSize(r, olenr, lenr);
}

inline double Pow::op(std::uint64_t* a, double n)
{   return std::pow(Double::op(a), n);
}

inline double Pow::op(SignedDigit a, double n)
{   return std::pow(Double::op(a), n);
}

//=========================================================================
//=========================================================================


//
// Division with the main number representation being 2s complement
// turns out to have many messy special cases! Here are some of the
// underlying issues:
// . Inputs may have had initial 0 or -1 digits pre-pended to allow
//   for positive values with their top bit set and negative ones with
//   it clear. So if I had 8-bit words the number 128 would have an
//   unsigned representation of [0x80], but it has to be stored as a
//   two digit number [0x00,0x80]. Similarly some negative numbers
//   need an initial 0xff attached just so that it can be seen that they
//   are negative.
// . If a result (quotient or remainder) is as above then space can be
//   needed for the prefix digit.
// . Long division needs to have a dividend with at least 3 digits
//   (after scaling) and a divisor with at least 2. That means that various
//   small cases have to be treated specially.
// . An operation as basic as taking the absolute value of an integer
//   generally involves allocating memory, and I would like to avoid that
//   as much as I can.
// . quotient and remainder operations are very similar indeed, but I ought
//   to be able to safe memory allocation in one or the other. Specifically
//   if I am computing a remainder I can discard quotient digits as I go
//   rather than having anywhere to put them.
// . On many useful platforms I will have an integer type that is 128 bits
//   wide and I can use that for a 128-by-64 division operation that is
//   really helpful when working with 64-bit digits. It is possible that
//   if I do not have 128-bit arithmetic available it would be best to
//   treat my numbers as being in base 2^32 so that 64-by-32 division is
//   the order of the day as a basic primitive.
// . For Lisp purposes I will have "fixnums" as well as "bignums" so special
//   paths for arithmetic that involves values -2^59 to 2^59-1 will be
//   required.
//
// Well perhaps I am fussing about all the above. But my first drafts of this
// code has not thought through all the cases carefully enough!


// Divide the bignum a by the b, returning a quotient or a remainder or
// both. Note that at this stage a may still be negative! The value b is
// passed in sign and magnitide form as {b, bNegative}

inline void unsigned_short_division(std::uint64_t* a,
                                    std::size_t lena,
                                    Digit b, bool bNegative,
                                    bool want_q, std::uint64_t*& q,
                                    std::size_t &olenq, std::size_t &lenq,
                                    bool want_r, std::uint64_t*& r,
                                    std::size_t &olenr, std::size_t &lenr)
{   Digit hi = 0;
    bool aNegative = false;
    std::uint64_t* aa;
    if (negative(a[lena-1]))
    {   aNegative = true;
// Take absolute value of a if necessary.
        aa = reserve(lena);
            internalNegate(a, lena, aa);
        a = aa;
    }
// Now both a and b are positive so I can do the division fairly simply.
// Allocate space for the quotient if I need that, and then do standard
// short division.
    std::size_t i=lena-1;
    if (want_q)
    {   olenq = lena;
        q = reserve(olenq);
        }
    for (;;)
    {   Digit d;
        divide64(hi, a[i], b, d, hi);
        if (want_q) q[i] = d;
        if (i == 0) break;
        i--;
    }
// If the original a had been negative I allocated space to store its
// absolute value, and I can discard that now.
    if (aNegative) abandon(aa);
    if (want_q)
    {   lenq = lena;
// The quotient will be negative if divisor and dividend had different signs.
        if (aNegative != bNegative) internalNegate(q, lenq, q);
// Things here are sort of amazing in that eg if internalNegate is called
// on the previous line then q can still end up positive and so need
// a call to truncatePositive. That happens if it is zero. So I call BOTH
// truncatePositive and truncateNegative to ensure I cover all situations.
        truncateNegative(q, lenq);
        truncatePositive(q, lenq);
    }
    if (want_r)
    {
// The remainder is now present as an unsigned value in hi. The sign it
// must end up having must match the sign of a (the dividend). Furthermore
// the remainder will be strictly smaller then b, and the largest possible
// value for b is 0xffffffffffffffff. The remainder may need to be returned
// as a 2-digit bignum.
        if (aNegative)
        {   hi = -hi;
            if (positive(hi) && hi!=0)
            {   olenr = lenr = 2;
                r = reserve(olenr);
                r[0] = hi;
                r[1] = -1;
            }
            else
            {   olenr = lenr = 1;
                r = reserve(olenr);
                r[0] = hi;
            }
        }
        else
        {   if (negative(hi))
            {   olenr = lenr = 2;
                r = reserve(olenr);
                r[0] = hi;
                r[1] = 0;
            }
            else
            {   olenr = lenr = 1;
                r = reserve(olenr);
                r[0] = hi;
            }
        }
    }
}

inline void signed_short_division(std::uint64_t* a, std::size_t lena,
                                  SignedDigit b,
                                  bool want_q, std::uint64_t*& q,
                                  std::size_t &olenq, std::size_t &lenq,
                                  bool want_r, std::uint64_t*& r,
                                  std::size_t &olenr, std::size_t &lenr)
{   if (b > 0) unsigned_short_division(a, lena,
                                       static_cast<Digit>(b),
                                       false,
                                       want_q, q, olenq, lenq,
                                       want_r, r, olenr, lenr);
    else unsigned_short_division(a, lena, -static_cast<Digit>(b),
                                 true,
                                 want_q, q, olenq, lenq,
                                 want_r, r, olenr, lenr);
}

inline void unsigned_long_division(std::uint64_t* a,
                                   std::size_t &lena,
                                   std::uint64_t* b, std::size_t &lenb,
                                   bool want_q, std::uint64_t* q,
                                   std::size_t &olenq, std::size_t &lenq);

#ifdef FASTDIVISION
inline void fastDivision(std::uint64_t* a,
                         std::size_t &lena,
                         std::uint64_t* b, std::size_t &lenb,
                         bool want_q, std::uint64_t* q,
                         std::size_t &olenq, std::size_t &lenq);
#endif // FASTDIVISION

// The following is a major entrypoint to the division code. (a) and (b) are
// vectors of digits such that the top digit of a number is treated as signed
// and the lower ones as unsigned. To cope with this there will sometimes
// be a sort of initial padder digit. The two boolean values indicate whether
// either or both of quotient and remainder are required. if want_q is set
// then this creates a new vector for q and return it via q/lenq. Similarly
// for want_r. The inputs a and b can be bignums of any size and are allowed
// to be positive or negative - this sorts everything out.

// Divide a by b to obtain a quotient q and a remainder r.

inline void division(std::uint64_t* a, std::size_t lena,
                     std::uint64_t* b, std::size_t lenb,
                     bool want_q, std::uint64_t*& q, std::size_t &olenq, std::size_t &lenq,
                     bool want_r, std::uint64_t*& r, std::size_t &olenr, std::size_t &lenr)
// First I will filter out a number of cases where the divisor is "small".
// I only want to proceed into the general case code if it is a "genuine"
// big number with at least two digits. This bit of the code is messier
// than one might have imagined because of the 2s complement representation
// I use and the fact that extreme values that almost fit in a single
// digit can ends up as 2-digit values with a degenerate top digit.
//
// The first case is when the single digit if b is a signed value in the
// range -2^63 to 2^63-1.
{   if (lenb == 1)
    {
// At present I cause an attempt to divide by zero to crash with an
// arithlib_assert failure if I have build in debug mode or to do who
// knows what (possibly raise an exception) otherwise. This maybe needs
// review. I wonder if I should throw a "division by zero" exception?
        arithlib_assert(b[0] != 0); // would be division by zero
        signed_short_division(a, lena, static_cast<SignedDigit>(b[0]),
                              want_q, q, olenq, lenq,
                              want_r, r, olenr, lenr);
        return;
    }
// Next I have b in the range 2^63 to 2^64-1. Such values can be represented
// in uint64_t. These values have had to have a leading zero in the bignum
// representation so that the value as a whold is not interpreted as being
// negative and although they are stored using 2 Digits they are "really"
// just 1-Digit values.
    else if (lenb == 2 && b[1]==0)
    {   unsigned_short_division(a, lena, b[0], false,
                                want_q, q, olenq, lenq,
                                want_r, r, olenr, lenr);
        return;
    }
// Now for b in -2^64 to -2^63-1. The 2s complement representetation will be
// of the form (-1,nnn) with nnn an unsigned 64-bit value. It is ALMOST the
// case that this can be handled using a short division by -nnn, but there
// is a special case where the value stored in the Digit there is zero and
// the value represented is exactly -2^64. I handle that individually!
    else if (lenb == 2 && b[1]==static_cast<Digit>(-1))
    {   if (b[0] == 0)
        {   if (want_q)
            {   lenq = lena;
                olenq = lena;
                q = reserve(lena);
            // I will now take cases based on the sign of a.
                if (negative(a[lena-1]))
                {
// Here I have a<0 being divided by -2^64. I will compute (-a)>>64 and
// in the worst case that can use as many Digits as a originally did.
                    MAYBE_UNUSED Digit notUsed;
                    Digit carry = addWithCarry(~a[0], 1, notUsed);
                    for (std::size_t i=1; i<lena; i++)
                        carry = addWithCarry(~a[i], carry, q[i-1]);
                    q[lena-1] = carry;
                    lenq = lena;
                    truncatePositive(q, lenq);
                }
                else
                {
// With a>=0 I want to compute -(a>>64) and this will always be shorter
// than a.
                    Digit carry = 1;
                    q[0] = 0; // in case lena==1!
                    for (std::size_t i=1; i<lena; i++)
                        carry = addWithCarry(~a[i], carry, q[i-1]);
                    addWithCarry(-1, carry, q[lena-1]);
                    lenq = lena;
                    truncateNegative(q, lenq);
                    truncatePositive(q, lenq);
                }
            }
            if (want_r)
            {
// The remainder will be essentially the bottom digit of a. But sometimes
// an additional digit that will be either 0 or -1 must be placed ahead of
// it.
                Digit rr = a[0], padr = 0;
                lenr = 1;
                if (negative(a[lena-1]) && strictlyPositive(rr))
                {   padr = -1;
                    lenr++;
                }
                else if (positive(a[lena-1]) && negative(rr))
                {   padr = 0;
                    lenr++;
                }
                r = reserve(lenr);
                olenr = lenr;
                r[0] = rr;
                if (lenr != 1) r[1] = padr;
            }
            return;
        }
        unsigned_short_division(a, lena, -b[0], true,
                                want_q, q, olenq, lenq,
                                want_r, r, olenr, lenr);
        return;
    }
// Now the absolute value of b will be at least 2 digits of 64-bits with the
// high digit non-zero. I need to make a copy of it because I will scale
// it during long division.
    std::uint64_t* bb = nullptr;
    std::size_t lenbb = lenb;
    bool bNegative = negative(b[lenb-1]);
    if (bNegative)
    {
// In the case that b is negative I will want its absolute value. Especially
// in a multi-thread world I must not disturb or overwrite the input vector,
// so a create a temporary copy of b to negate. In my full 2s complement
// representation negating -2^(64*n-1) would lead to what was supposed to be
// a positive value but it would have its top bit set so it would require
// and extra leading 0. Because the value I generate here is to be treated
// as unsigned this leading top bit does not matter and so the absolute value
// of b fits in the same amount of space that b did with no risk of overflow.
        bb = reserve(lenb);
        olenr = lenb;
        internalNegate(b, lenb, bb);
        if (bb[lenbb-1] == 0) lenbb--;
    }
    else if (b[lenb-1] == 0) lenbb--;
// Now I should look at the dividend. If it is shorter than the divisor
// then I know that the quotient will be zero and the dividend will be the
// remainder. If I had made this test before normalizing the divisor I could
// have needed to worry about the case of (-2^(64n-1))/(2^(64n-1)) where the
// divisor would have had an initial padding zero so would have shown up
// as longer than the dividend but the quotient would have needed to come out
// as 1. But here with the divisor made tidy this test is safe!
    if (lena < lenbb)
    {   if (want_q)
        {   q = reserve(1);
            olenq = 1;
            q[0] = 0;
            lenq = 1;
        }
        if (want_r)
        {   r = reserve(lena);
                    olenr = lena;
            internalCopy(a, lena, r);
            lenr = lena;
        }
        if (bNegative) abandon(bb);
        return;
    }
// Now lena >= lenb >= 2 and I will need to do a genuine long division. This
// will need me to allocate some workspace.
//
// Because I will scale the divisor I need that to be a copy of the
// original data even if that has been positive and so I had not copied
// it yet. I delay creation of that copy until now because that lets my
// avoid a spurious allocation in the various small cases.
    if (!bNegative)
    {   bb = reserve(lenb);
        olenr = lenb;
        internalCopy(b, lenbb, bb);
    }
// If I actually return the quotient I may need to add a leading 0 or -1 to
// make its 2s complement representation valid. Hence the "+2" rather than
// the more obvious "+1" here.
    if (want_q)
    {   lenq = lena - lenb + 2;
        q = reserve(lenq);
        olenq = lenq;
    }
// I will need space where I store something that starts off as a scaled
// copy of the dividend and gradually have values subtracted from it until
// it ends up as the remainder.
    lenr = lena;
    r = reserve(lenr+1);
    bool aNegative = negative(a[lena-1]);
    if (aNegative) internalNegate(a, lena, r);
    else internalCopy(a, lena, r);
#ifdef FASTDIVISION
// Only for an experinment at present!
    fastDivision(r, lenr, bb, lenbb, want_q, q, olenq, lenq);
#else // FASTDIVISION
    unsigned_long_division(r, lenr, bb, lenbb, want_q, q, olenq, lenq);
#endif // FASTDIVISION
// While performing the long division I will have had three vectors that
// were newly allocated. r starts off containing a copy of a but ends up
// holding the remainder. It is rather probable that this remainder will
// often be a distinctly shorter vector than a was. The vector q is only
// created and used if want_q was set, and it ends up holding the quotient.
// finally bb holds the absolute value of the divisor but scaled up by a
// power of 2 so that its leading digit has its top bit set. Well the actual
// remainder is smaller than the divisor and so it will be a closer fit into
// bb than r. So copy it into there so that the allocate/abandon and
// size confirmation code is given less extreme things to cope with.
    if (want_r) internalCopy(r, lenr, bb);
    abandon(r);
    if (want_q)
    {   if (negative(q[lenq-1]))
            q[lenq++] = 0;
        if (aNegative != bNegative) internalNegate(q, lenq, q);
        truncateNegative(q, lenq);
        truncatePositive(q, lenq);
    }
//  else abandon(q);
    if (want_r)
    {   r = bb;
        if (negative(r[lenr-1]))
            r[lenr++] = 0;
        if (aNegative) internalNegate(r, lenr, r);
        truncateNegative(r, lenr);
        truncatePositive(r, lenr);
    }
    else abandon(bb);
}

// During long division I will scale my numbers by shifting left by an
// amount s. I do that in place. The shift amount will be such that
// the divisor ends up with the top bit of its top digit set. The
// dividend will need to extend into an extra digit, and I deal with that
// by returning the overflow word as a result of the scaling function. Note
// that the shift amount will be in the range 0-63.


inline Digit scale_for_division(std::uint64_t* r,
                                        std::size_t lenr,
                                        int s)
{
// There are two reasons for me to treat a shift by zero specially. The
// first is that it is cheap because no data needs moving at all. But the
// more subtle reason is that if I tried using the general code as below
// that would execute a right shift by 64, which is out of the proper range
// for C++ right shifts. But NOTE that if I shift by zero (which happens if
// my divisor already has the top bit of its top word set) I do not alter
// any memory.
    if (s == 0) return 0;
    Digit carry = 0;
    for (std::size_t i=0; i<lenr; i++)
    {   Digit w = r[i];
        r[i] = (w << s) | carry;
        carry = w >> (64-s);
    }
    return carry;
}

// r = r - b*q*base^(lena-lenb-1).

inline void multiply_and_subtract(std::uint64_t* r, std::size_t lenr,
                                  Digit q0,
                                  std::uint64_t* b, std::size_t lenb)
{   Digit hi = 0, lo, carry = 1;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(b[i], q0, hi, hi, lo);
// lo is now the next digit of b*q, and hi needs to be carried up to the
// next one.
        carry = addWithCarry(r[i+lenr-lenb-1], ~lo, carry,
                               r[i+lenr-lenb-1]);
    }
    r[lenr-1] = r[lenr-1] + ~hi + carry;
}

// addBackCorrection() is used when a quotient digit was mis-predicted by
// 1 and I detect that when I calculate r = r - b*q and end up with r negative
// result. I fix things up by decrementing q and going
//         r = r + (b<<(lenr-lenb-1))

inline void addBackCorrection(std::uint64_t* r, std::size_t lenr,
                              std::uint64_t* b, std::size_t lenb)
{   Digit carry = 0;
    for (std::size_t i=0; i<lenb; i++)
        carry = addWithCarry(r[i+lenr-lenb-1], b[i], carry,
                             r[i+lenr-lenb-1]);
    r[lenr-1] += carry;
}

inline Digit nextQuotientDigit(std::uint64_t* r,
                               std::size_t &lenr,
                               std::uint64_t* b, std::size_t lenb)
{   Digit q0, r0;
    if (r[lenr-1] == b[lenb-1])
    {   q0 = static_cast<Digit>(-1);
        r0 = r[lenr-2] + b[lenb-1];
// Here perhaps q0 is still an over-estimate by 1?
    }
    else
    {   divide64(r[lenr-1], r[lenr-2], b[lenb-1], q0, r0);
// At this stage q0 may be correct or it may be an over-estimate by 1 or 2,
// but never any worse than that.
//
// The tests on the next lines should detect all case where q0 was in error
// by 2 and most when it was in error by 1.
        Digit hi, lo;
        multiply64(q0, b[lenb-2], hi, lo);
        if (hi > r0 ||
            (hi == r0 && lo > r[lenr-3])) q0--;
    }
//
// Now I want to go "r = r - b*q0*2^(64*(lenr-lenb));" so that r
// is set to an accurate remainder after using q0 as (part of) the
// quotient. This may carry an overshoot into atop and if so I will need
// to reduce q0 again and compensate.
//
    multiply_and_subtract(r, lenr, q0, b, lenb);
    if (negative(r[lenr-1]))
    {   q0--;
        addBackCorrection(r, lenr, b, lenb);
    }
    lenr--;  // a is now one digit shorter.
    return q0;
}

// r is an unsigned number. Shift right (in place) by s bits, where s
// is in the range 0 - 63. The bits shifted out to the right should all
// be zero.

inline void unscale_for_division(std::uint64_t* r, std::size_t &lenr, int s)
{   if (s != 0)
    {   Digit carry = 0;
        std::size_t i = lenr-1;
        for (;;)
        {   Digit w = r[i];
            r[i] = (w >> s) | carry;
            carry = w << (64-s);
            if (i == 0) break;
            i--;
        }
    }
    truncateUnsigned(r, lenr);
}

// This function does long division on unsigned values, computing the
// quotient (a/b). In doing so it updates (a) so that at the end it holds
// the remainder. It only fills in a value for the quotient q if want_q is
// true. Note also that this code will scale (b) so that the top bit of its
// highest digit is a "1", so b must be an array that can be overwritten
// without disturbing code elsewhere. Well if the top bit is already set
// I promise I will not corrupt it, so in that case b still has to be
// uint64_t* not const uint64_t* but it will not be overwritten.

inline void unsigned_long_division(std::uint64_t* a,
                                   std::size_t &lena,
                                   std::uint64_t* b, std::size_t &lenb,
                                   bool want_q, std::uint64_t* q,
                                   std::size_t &olenq, std::size_t &lenq)
{
// I will multiply a and b by a scale factor that gets the top digit of "b"
// reasonably large. The value stored in "a" can become one digit longer,
// but there is space to store that.
//
// The scaling is done here using a shift, which seems cheaper to sort out
// then multiplication by a single-digit value.
    int ss = nlz(b[lenb-1]);
// When I scale the dividend expands into an extra digit but the scale
// factor has been chosen so that the divisor does not.
    a[lena] = scale_for_division(a, lena, ss);
    lena++;
    uint64_t w = scale_for_division(b, lenb, ss);
    arithlib_assert(w == 0);
    lenq = lena-lenb; // potential length of quotient.
    std::size_t m = lenq-1;
    for (;;)
    {   Digit qd = nextQuotientDigit(a, lena, b, lenb);
// If I am only computing the remainder I do not need to store the quotient
// digit that I have just found.
        if (want_q) q[m] = qd;
        if (m == 0) break;
        m--;
    }
    unscale_for_division(a, lena, ss);
// The quotient is OK correct now but has been computed as an unsigned value
// so if its top digit has its top bit set I need to prepend a zero;
    if (want_q)
    {   if (negative(q[lenq-1])) q[lenq++] = 0;
        else truncateUnsigned(q, lenq);
    }
    if (negative(a[lena-1])) a[lena++] = 0;
    else truncateUnsigned(a, lena);
}

// Use unsigned_long_division when all that is required is the remainder.
// Here a>b and b is at least 2 words. The code corrupts b and replaces
// a with remainder(a, b).

inline void unsigned_long_remainder(std::uint64_t* a,
                                    std::size_t &lena,
                                    std::uint64_t* b, std::size_t &lenb)
{   std::size_t w;
    unsigned_long_division(a, lena, b, lenb,
                           false, nullptr, w, w);
}

inline std::intptr_t Quotient::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             false, r, olenr, lenr);
    return confirmSize(q, olenq, lenq);
}

inline std::intptr_t Quotient::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
// Making division by 1 a special case is merely optimisation. However
// I have to copy the bignum (because I do not keep reference counts).
    {   std::size_t n = numberSize(a);
        std::uint64_t* p = reserve(n);
        std::memcpy(p, a, n*sizeof(Digit));
        return confirmSize(p, n, n);
    }
    case -1:
// Making division by -1 a special case tidies up the code within
// the function division() because when -2^(64*K) is divided by -1 the
// resulting bignum needs to be one word longer than the input. That is the
// only case where division causes a number to grow, so disposing of it
// early makes storage allocation for all the other cases just a little
// easier.
        return Minus::op(a);
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             true, q, olenq, lenq,
             false, r, olenr, lenr);
    return confirmSize(q, olenq, lenq);
}

// A fixnum divided by a bignum ought always to yield 0, except that
// maybe -0x8000000000000000} / {0,0x8000000000000000) => -1

inline std::intptr_t Quotient::op(SignedDigit a, std::uint64_t* b)
{   if (numberSize(b)==1 &&
        b[0]==-static_cast<Digit>(a))
        UNLIKELY
        return intToHandle(-1);
    return intToHandle(0);
}

// unpleasantly -0x8000000000000000 / -1 => a bignum

inline std::intptr_t Quotient::op(SignedDigit a, SignedDigit b)
{   if (b==-1 && a == MIN_FIXNUM) UNLIKELY return intToBignum(-a);
    else return intToHandle(a / b);
}

inline std::intptr_t Remainder::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    return confirmSize(r, olenr, lenr);
}

inline std::intptr_t Remainder::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
    case -1:   // avoid calling division() in this case.
        return intToHandle(0);
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    return confirmSize(r, olenr, lenr);
}

inline std::intptr_t Remainder::op(SignedDigit a, std::uint64_t* b)
{   if (numberSize(b)==1 &&
        b[0]==-static_cast<Digit>(a)) return intToHandle(0);
    return intToHandle(a);
}

inline std::intptr_t Remainder::op(SignedDigit a, SignedDigit b)
{   return intToHandle(a % b);
}

inline std::intptr_t Mod::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w = confirmSize(r, olenr, lenr);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = negative(b[lenb-1]);
    if (w != intToHandle(0) &&
        ((a_neg && !b_neg) || (!a_neg && b_neg)))
    {   if (storedAsFixnum(w)) return Plus::op(intOfHandle(w), b);
        else return Plus::op(vectorOfHandle(w), b);
    }
    else return w;
}

// When b is positive Mod uses directed rounding as for Floor, while if
// b is negative it is as for Ceiling, so that the sign of (P mod Q) always
// matches that of Q.

inline std::intptr_t Mod::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
    case -1:
        return intToHandle(0);
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w = confirmSize(r, olenr, lenr);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = (b < 0);
    if (w != intToHandle(0) &&
        ((a_neg && !b_neg) || (!a_neg && b_neg)))
    {   if (storedAsFixnum(w)) return Plus::op(intOfHandle(w), b);
        else return Plus::op(vectorOfHandle(w), b);
    }
    else return w;
}

inline std::intptr_t Mod::op(SignedDigit a, std::uint64_t* b)
{   if (a==0 ||
        (numberSize(b)==1 &&
         b[0]==-static_cast<Digit>(a))) return intToHandle(0);
    bool a_neg = (a < 0);
    bool b_neg = negative(b[numberSize(b)-1]);
    if ((a_neg && !b_neg) || (!a_neg && b_neg))
        return Plus::op(a, b);
    else return intToHandle(a);
}

inline std::intptr_t Mod::op(SignedDigit a, SignedDigit b)
{   int64_t r = a%b;
    if (r!=0 &&((a<0 && b>0) || (a>0 && b<0))) r += b;
    return intToHandle(r);
}

// Here if division is not exact the quotient is rounded towards -infinity. 

inline std::intptr_t Floor::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = negative(b[lenb-1]);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && a_neg != b_neg) return Sub1::op(w1);
    else return w1;
}

inline std::intptr_t Floor::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
        return vectorToHandle(a);
    case -1:
        return Minus::op(a);
    }
    std::size_t lena = numberSize(a);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = b < 0;
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && a_neg != b_neg) return Sub1::op(w1);
    else return w1;
}

// An edge case here is a-=2^63 and b=+2^63 where the exact quotient
// is -1. In all other cases the absolute value of a is less than that
// of be and the truncated quotient is zero. Then if a and b have the
// same signs the required result is zero, otherwise it will be -1.
// Hah - happily the edge case comes out right in the wash!

inline std::intptr_t Floor::op(SignedDigit a, std::uint64_t* b)
{   bool a_neg = (a < 0);
    bool b_neg = negative(b[numberSize(b)-1]);
    if (a_neg == b_neg) return intToHandle(0);
    else return intToHandle(-1);
}

inline std::intptr_t Floor::op(SignedDigit a, SignedDigit b)
{   int64_t q = a/b;
    int64_t r = a%b;
    if (r == 0 ||
        (a < 0) == (b < 0)) return intToHandle(q);
// q-1 can not overflow here because the only way that q could have
// ended up as INT64_MIN would be for that to have been the value of
// a and b bad been +1. But then the remainder would have been zero
// so the easier exit would have been taken.
    else return intToHandle(q-1);
}

inline std::intptr_t Ceiling::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = negative(b[lenb-1]);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && (a_neg == b_neg)) return Add1::op(w1);
    else return w1;
}

inline std::intptr_t Ceiling::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
        return vectorToHandle(a);
    case -1:
        return Minus::op(a);
    }
    std::size_t lena = numberSize(a);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = b < 0;
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && (a_neg == b_neg)) return Add1::op(w1);
    else return w1;
}

inline std::intptr_t Ceiling::op(SignedDigit a, std::uint64_t* b)
{   if (numberSize(b) == 1 &&
        a == -static_cast<int64_t>(b[0])) return intToHandle(-1);
    bool a_neg = (a < 0);
    bool b_neg = negative(b[numberSize(b)-1]);
    if (a_neg == b_neg) return intToHandle(1);
    else return intToHandle(0);
}

inline std::intptr_t Ceiling::op(SignedDigit a, SignedDigit b)
{   int64_t q = a/b;
    int64_t r = a%b;
// if b=-1 or b=+1 then the remainder will be zero. In all other
// cases q will be small enough not to overflow when incremented.
    if (r!=0 && (a<0)==(b<0)) q++;
    return intToHandle(q);
}


#ifdef LISP

// In LISP mode I provide a function that returns both quotient and
// remainder. In the other two modes I support the same idea but
// as a function that delivers the quotient as its result and saves
// the remainder via an additional argument.

}

namespace arithlib_implementation
{

inline std::intptr_t Divide::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

inline std::intptr_t Divide::op(std::uint64_t* a, SignedDigit bb)
{   switch (bb)
    {
    case 1:
        return cons(vectorToHandle(a), intToHandle(0));
    case -1:
        return cons(Minus::op(a), intToHandle(0));
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit b[1] = {static_cast<Digit>(bb)};
    division(a, lena, b, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

inline std::intptr_t Divide::op(SignedDigit aa, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit a[1] = {static_cast<Digit>(aa)};
    division(a, 1, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

inline std::intptr_t Divide::op(SignedDigit aa, SignedDigit bb)
{   std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    Digit a[1] = {static_cast<Digit>(aa)};
    Digit b[1] = {static_cast<Digit>(bb)};
    division(a, 1, b, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

#else // LISP

inline std::intptr_t Divide::op(std::uint64_t* a, std::uint64_t* b,
                                std::intptr_t &rem)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q;
    std::uint64_t* r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    rem = confirmSize(r, olenr, lenr);
    return confirmSize_x(q, olenq, lenq);
}

#endif // LISP

// a = a - b*q.

inline bool reduce_for_gcd(std::uint64_t* a, std::size_t lena,
                           Digit q,
                           std::uint64_t* b, std::size_t lenb)
{   Digit hi = 0, hi1, lo, borrow = 0;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(b[i], q, hi1, lo);
        hi1 += subtractWithBorrow(a[i], hi, a[i]);
        borrow = subtractWithBorrow(a[i], lo, borrow, a[i]);
        hi = hi1;
    }
// In the cases where this is used the difference |a - q*b| should be
// less than a. Well if q was computed accurately then it will be less
// than b. And if q is large it will at least me much less than a. So I
// am confident that testing the top bit if a[lena-1] after the subtraction
// will be a reliable test for overshoot. I might want to formalize this
// argument a bit better!
    if (lena > lenb) a[lena-1] = a[lena-1] - hi - borrow;
    return negative(a[lena-1]);
}

// I provide a function that accesses (b<<shift)[n]. Note that the
// valid index values n will from from 0 up to and including lenb.

inline Digit shiftedDigit(std::uint64_t* b, std::size_t lenb,
                                  int shift, std::size_t n)
{   if (n == 0) return b[0]<<shift;
    else if (n == lenb) return b[lenb-1]>>(64-shift);
    else return (b[n]<<shift) | (b[n-1]>>(64-shift));
}

// The next function performs a = a = b*(q<<shift), but
// it computes it more as a = a - (b<<shift)*q.
// It will be used with 0 < shift < 64, ie only when a genuine shift
// between digits is required.
inline bool shifted_reduce_for_gcd(std::uint64_t* a, std::size_t lena,
                                   Digit q,
                                   std::uint64_t* b, std::size_t lenb,
                                   int shift)
{   Digit hi = 0, hi1, lo, borrow = 0;
    for (std::size_t i=0; i<=lenb; i++)
    {   multiply64(shiftedDigit(b, lenb, shift, i), q, hi1, lo);
        hi1 += subtractWithBorrow(a[i], hi, a[i]);
        borrow = subtractWithBorrow(a[i], lo, borrow, a[i]);
        hi = hi1;
    }
// In the cases where this is used the difference |a - q*b| should be
// less than a. Well if q was computed accurately then it will be less
// than b. And if q is large it will at least me much less than a. So I
// am confident that testing the top bit if a[lena-1] after the subtraction
// will be a reliable test for overshoot. I might want to formalize this
// argument a bit better!
    if (lena > lenb+1) a[lena-1] = a[lena-1] - hi - borrow;
    return negative(a[lena-1]);
}

// Here we compute r = u*a - v*b, where lenr >= min(lena, lenb). This
// is for use in Lehmer reductions.
// In general this will be used as in
//    ua_minus_vb(a, u1, b, v1, temp);
//    ua_minus_vb(a, u2, b, v2, a);
//    copy from temp to b
// so note that the destination may be the same vector as one of the inputs.
// This will only be used when a and b are almost the same length. I leave
// a result of length lena even though I very much expect that in at least
// almost all cases the result will be almost 128 bits smaller!

inline bool ua_minus_vb(std::uint64_t* a, std::size_t lena,
                        Digit u,
                        std::uint64_t* b, std::size_t lenb,
                        Digit v,
                        std::uint64_t* r, std::size_t &lenr)
{   Digit hia, loa, ca = 0, hib, lob, cb = 0, borrow = 0;
// I wish to compute r = u A - v B where all values are treated as
// unsigned save that if the result underflows (ie would be negative if
// computed perfectly) I must return a "borrow" value.
//
// At one stage I called this going in effect
//   if (v < 0) ua_minus_vb(..., -v, ...);
// and in an extra case v started off as INT64_MIN. As an unsigned value
// (-v) is properly in range, but if I performed the negation as signed
// arithmetic it counted as an overflow since the result has just the
// top bit set and has value (INT64_MAX+1). In that case a "sufficiently
// clever" C++ compiler could and did argue that the value of v passed here
// would have its top bit zero (since the only way that might not be the
// case would involve overflow and hence represented undefined behavious).
// So in some sense V simultaneously had the value 0x8000000000000000 and
// also for the purposes of optimisation could be assumed to have its top
// bit zero. In a manner that at present I do not fully understand this
// could lead the code here to return a result that was not the one I
// wanted. Altering the call to read
//   if (v < 0) ua_minus_ub(..., -static_cast<uint64_t>(v), ...);
// so that the negation was performed on an unsigned value where C++
// does consider the result defined left my code behaving as it had
// with earlier released of the C++ compiler that were less clever.
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(a[i], u, hia, loa);
// hia is the high part of a product so carrying 1 into it can not cause it
// to overflow. Just!
        hia += addWithCarry(loa, ca, loa);
        multiply64(b[i], v, hib, lob);
        hib += addWithCarry(lob, cb, lob);
        borrow = subtractWithBorrow(loa, lob, borrow, r[i]);
        ca = hia;
        cb = hib;
    }
    lenr = lenb;
// I want to report in whether u*a-v*b was negative. To do that I will
// first note that the result that I am computing should be less than the
// value of a, so I do not get too much messy overflow. I will look at the
// borrow out from the top word of the result.
    if (lena > lenb)
    {   multiply64(a[lena-1], u, hia, loa);
        hia += addWithCarry(loa, ca, loa);
        borrow = subtractWithBorrow(loa, cb, borrow, r[lena-1]);
        lenr = lena;
        return negative(hia - borrow);
    }
    return negative(ca - cb - borrow);
}

// Since the code here is quite short I will also provide a version
// for r = -u*a + b*v;
// Again this supposes that a is at least as long as b.

inline bool minus_ua_plus_vb(std::uint64_t* a, std::size_t lena,
                             Digit u,
                             std::uint64_t* b, std::size_t lenb,
                             Digit v,
                             std::uint64_t* r, std::size_t &lenr)
{   Digit hia, loa, ca = 0, hib, lob, cb = 0, borrow = 0;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(a[i], u, hia, loa);
        hia += addWithCarry(loa, ca, loa);
        multiply64(b[i], v, hib, lob);
        hib += addWithCarry(lob, cb, lob);
        borrow = subtractWithBorrow(lob, loa, borrow, r[i]);
        ca = hia;
        cb = hib;
    }
    lenr = lenb;
    if (lena > lenb)
    {   multiply64(a[lena-1], u, hia, loa);
        hia += addWithCarry(loa, ca, loa);
        borrow = subtractWithBorrow(cb, loa, borrow, r[lena-1]);
        lenr = lena;
// It will be perfectly reasonable for hia to be zero and borrow to be zero
// and hence the overall result positive.
        return negative(- hia - borrow);
    }
    return negative(cb - ca - borrow);
}

// gcd_reduction starts with a > b and |b| >=2. It must reset a and
// b (and their lengths) to be smaller. The basic Euclidean algorithm
// would go
//    a = a % b;   // otherwise a = a-q*b; for some useful value of q
//                 // and then if q was "too large" go a = |a|;
//    swap(a, b);
// but a Lehmer-style scheme can go distinctly faster overall.

inline void gcd_reduction(std::uint64_t*& a, std::size_t &lena,
                          std::uint64_t*& b, std::size_t &lenb,
                          std::size_t &olena, std::size_t &olenb,
                          std::uint64_t*& temp, std::size_t &lentemp)
{
// I will start by collecting high bits from a and b. If I collect the
// contents of the top 3 words (ie 192 bits in all) then I will be able
// to normalize that to get 128 bits to work with however the top bits
// of a and b lie within the words.
    Digit a0=a[lena-1], a1=a[lena-2], a2=(lena>2 ? a[lena-3] : 0);
    int lza = nlz(a0);
    Digit b0=b[lenb-1], b1=b[lenb-2], b2=(lenb>2 ? b[lenb-3] : 0);
    int lzb = nlz(b0);
// I will sort out how many more bits are involved in a than in b. If
// this number is large I will invent a number q of the form q=q0*2^q1
// with q0 using almost all of 64 bits and go "a = a - q*b;". This
// will involve "virtually shifting" b left by q1 bits so what I actually
// do is "a = a = q0*(b<<q1);". It will be obvious that the idea is that
// q should be chosen so that the new value of a is as small as possible.
// Given that q will be an estimate for the correct quotient and so may
// occasionally be incorrect I will allow that it might in fact be
// too large. In such a case the value of a computed will end up negative,
// in which caseI do a final step that goes "a = -a;" to fix that. If I
// manage to make q a round-to-nearest approximation to the quotient this
// might happen a significant fraction of the time, ideally getting me
// 1 extra bit in reduction in the size of a for each step.
// If the estimated quotient is accurate enough the this will leave
// a < b and by swapping a and b we have a new pair ready to continue from.
    SignedDigit diff = 64*(lena-lenb) + lzb - lza;
// If however the length-difference between a and b is small a subtraction
// "a = a - q0*(b<<0);" would often find q0 rather small and completing
// the remainder sequence would take many steps. So in such cases I take
// the top 128 bits of a and (128-diff) bits from b and start forming
// a remainder sequence using 128-bit arithmetic until a term in it
// fits in 64-bits. If the last 2 terms in that remainder sequence are
// p and q (with p having >64 bits and q <= 64 bits) I can have
//    p = |Ua - Vb|,    q = |-Wa + Xb|.
// where U, V, W and X should all fit in 64-bits. That gives me a new
// pair of values - expected to be up to 128-bits shorter - to continue
// my remainder sequence. Because my stopping condition for the
// approximate remainder sequence is not guaranteed perfect I can not
// be certain that q < p, so I will need to compare the values and
// swap as appropriate.
//
    if (diff < 60)
    {
// Try for Lehmer. The pair of values that will be 2-word surrogates
// for a and b here will be the top 128 bits of a and however many bits of
// b align with that. However if a has only 2 digits then I must NOT shift it
// left, because that would make it seem to have a power of 2 as a factor
// beyond any real such factors.
// It could be that lenb < lena, but because a and b different in lengths
// by at most 60 bits in that case lenb==lena-1. So adjust values so as to
// align.
        if (lena != lenb)
        {   b2 = b1;
            b1 = b0;
            b0 = 0;
        }
        if (lena > 2)
        {   a0 = a0<<lza;
            if (lza!=0) a0 |= (a1>>(64-lza));
            a1 = a1<<lza;
            if (lza!=0) a1 |= (a2>>(64-lza));
            b0 = b0<<lza;
            if (lza!=0) b0 |= (b1>>(64-lza));
            b1 = b1<<lza;
            if (lza!=0) b1 |= (b2>>(64-lza));
        }
// I will maintain an identity
//          a = ua*A + va*B
//          b = ub*A + vb*B
// where A and B are the initial values in my remainder sequence and a and b
// are working ones calculated along the way. Note horribly well here that
// I am keeping these values as signed... but the code U have above that
// calculates u*a-b*v will take unsigned inputs!
        SignedDigit ua = 1, va = 0, ub = 0, vb = 1;
        while (b0!=0 || b1!=0)
        {   Digit q;
// Here I want to set q = {a0,a1}/{b0,b1}, and I expect that the answer
// is a reasonably small integer. But it could potentially be huge.
// At least I have filtered away the possibility {b0,b1}={0,0}.
// I will grab the top 64 bits of a and the top corresponding bits of b,
// because then I can do a (cheap) 64-by-64 division.
            int lza1 = a0==0 ? 64+nlz(a1) : nlz(a0);
            int lzb1 = b0==0 ? 64+nlz(b1) : nlz(b0);
            if (lzb1 > lza1+60) break; // quotient will be too big
            Digit ahi, bhi;
            if (lza1 == 0) ahi = a0;
            else if (lza1 < 64) ahi = (a0<<lza1) | (a1>>(64-lza1));
            else if (lza1 == 64) ahi = a1;
            else ahi = a1<<(lza1-64);
            if (lza1 == 0) bhi = b0;
            else if (lza1 < 64) bhi = (b0<<lza1) | (b1>>(64-lza1));
            else if (lza1 == 64) bhi = b1;
            else bhi = b1<<(lza1-64);
            if (bhi == 0) break;
// q could end up and over-estimate for the true quotient because bhi has
// been truncated and so under-represents b. If that happens then a-q*b will
// end up negative.
            q = ahi/bhi;
            if (negative(q)) break;
// Now I need to go
//              ua -= q*va;
//              ub -= q*vb;
//              {a0,a1} -= q*{b0,b1}
// Then if a is negative I will negate a and ua and ub.
// Finally, if (as I mostly expect) now a<b I swap a<=>b, ua<=>ub and va<=>vb
// If I would get an overflow in updating ua or ub I will break out of the
// loop.
            SignedDigit h;
            Digit l1, l2;
            signedMultiply64(q, va, h, l1);
            if (static_cast<Digit>(h) + (l1>>63) != 0) break;
// There could be overflow in the following subtraction... So I check
// if that was about to happen and break out of the loop if so.
            if (ua >= 0)
            {   if (ua - INT64_MAX >= static_cast<SignedDigit>(l1)) break;
            }
            else if (ua - INT64_MIN <= static_cast<SignedDigit>(l1)) break;
            signedMultiply64(q, vb, h, l2);
            if (static_cast<Digit>(h) + (l2>>63) != 0) break;
            if (ub >= 0)
            {   if (ub - INT64_MAX > static_cast<SignedDigit>(l2)) break;
            }
            else if (ub - INT64_MIN < static_cast<SignedDigit>(l2)) break;
// I must either update both or neither of ua, ub.
            ua -= l1;
            ub -= l2;
            Digit hi, lo;
            multiply64(q, b1, hi, lo);
            hi += subtractWithBorrow(a1, lo, a1);
            Digit borrow = subtractWithBorrow(a0, hi, a0);
            borrow += subtractWithBorrow(a0, q*b0, a0);
// Now borrow!=0 if a had become negative
            if (borrow != 0)
            {   if ((a1 = -a1) == 0) a0 = -a0;
                else a0 = ~a0;
                ua = -ua;
                ub = -ub;
            }
            if (b0 > a0 ||
                (b0 == a0 && b1 > a1))
            {   std::swap(a0, b0);
                std::swap(a1, b1);
                std::swap(ua, va);
                std::swap(ub, vb);
            }
        }
// Ahah now I am almost done. I want to go
//          a' = |ua*a + ub*b|;
//          b' = |va*a + vb*b|;
//          if (a' > b') [a, b] = [a', b'];
//          else [a, b] = [b', a'];
// and in the first two lines I need to be aware that one or the other
// (but not both) or ua and ub will be negative so I really have a subtraction,
// and similarly for v1, vb.
        if (temp == nullptr)
        {   temp = reserve(lena>lenb ? lena : lenb);
                        }
// The static cast here is in case ua (etc) have the negative value INT64_MIN
// because if I negate that before turning to an unsigned value to pass
// to the sub-function that would count as overflow and in consequence the
// behaviour of everthing here would become undefined.
        if (ub < 0)
        {   if (ua_minus_vb(a, lena, ua, b, lenb,
                            -static_cast<uint64_t>(ub), temp, lentemp))
                internalNegate(temp, lentemp, temp);
        }
        else
        {   if (minus_ua_plus_vb(a, lena, -static_cast<uint64_t>(ua),
                                 b, lenb, ub, temp, lentemp))
                internalNegate(temp, lentemp, temp);
        }
        truncateUnsigned(temp, lentemp);
        if (vb < 0)
        {   if (ua_minus_vb(a, lena, va, b, lenb,
                            -static_cast<uint64_t>(vb), a, lena))
                internalNegate(a, lena, a);
        }
        else
        {   if (minus_ua_plus_vb(a, lena, -static_cast<uint64_t>(va),
                                 b, lenb, vb, a, lena))
                internalNegate(a, lena, a);
        }
        truncateUnsigned(a, lena);
        internalCopy(temp, lentemp, b);
        lenb = lentemp;
        return;
    }
// If I drop through to here I will do a simple reduction. This happens
// either if the initial quotient a/b is huge (over 2^60) or if as I start
// setting up for the Lehmer step I find I can not make enough progress
// with that to be useful. For instance if the next two steps would have
// q=1 and then q=<huge> I can not combine in the huge step to make Lehmer
// style progress and I should drop down and do the "q=1" reduction first
// (followed by the next huge one).
//
// This is the "a = a - q*b;" case.
// Collect the top 128 bits of both a and b.
    b0 = b0<<lzb;
    if (lzb!=0) b0 |= (b1>>(64-lzb));
    b1 = b1<<lzb;
    if (lzb!=0) b1 |= (b2>>(64-lzb));
    a0 = a0<<lza;
    if (lza!=0) a0 |= (a1>>(64-lza));
    a1 = a1<<lza;
    if (lza!=0) a1 |= (a2>>(64-lza));
    a2 = a2<<lza;
// When I have done this b0 will have its top bit set and I will
// want to have a0<b0 because I will be dividing {a0,a1}/b0 and I want the
// quotient to fit within a single 64-bit word.
    if (a0 >= b0)
    {   a2 = (a2>>1) | (a1<<63);
        a1 = (a1>>1) | (a0<<63);
        a0 = a0>>1;
        lza = lza-1;
        diff = diff+1;
    }
    Digit q, r;
// I want to get as close an approximation to the full quotient as I can,
// and a "correction" of the form {a0,a1} -= a0*b1/b0 should do the trick.
    multiply64(a0, b1, q, r);
    divide64(q, r, b0, q, r);
    r = a1 - q;
    if (r > a1) a0--;
    a1 = r;
    divide64(a0, a1, b0, q, r);
// Now I want to go "a = a - q*b*2^(diff-64);". The "-64" there is because
// the quotient I computed in q is essentially to be viewed as a fraction.
// So if diff<=64 I will need to do something special.
    if (diff <= 64)
    {   std::size_t bitsTo_lose = 64 - diff;
// I will shift q right, but doing so in such a way that I try to round to
// nearest.
        if (bitsTo_lose != 0)
        {   q = q >> (bitsTo_lose-1);
            q = (q >> 1) + (q & 1);
        }
// Now just do "a = a-q*b;", then ensure that the result is positive
// and clear away any leading zeros left in its representation.
        if (reduce_for_gcd(a, lena, q, b, lenb))
            internalNegate(a, lena, a);
        truncateUnsigned(a, lena);
    }
    else
    {
// Here I need to do a reduction but the quotient in the step is very large
// so I will use the value of q I have as basically the top 60+ bits of the
// quotient I need but with "diff" bits stuck on the end. If diff is a
// multiple of 64 then this is merely a shift by some whole number of words.
        if ((diff%64) == 0)
        {   std::size_t diffw = diff/64;
            if (reduce_for_gcd(a+diffw-1, lena+1-diffw, q, b, lenb))
                internalNegate(a, lena, a);
            truncateUnsigned(a, lena);
        }
        else
        {   std::size_t diffw = diff/64;
            diff = diff%64;
            if (shifted_reduce_for_gcd(a+diffw-1, lena+1-diffw,
                                       q, b, lenb, diff))
                internalNegate(a, lena, a);
            truncateUnsigned(a, lena);
        }
    }
}

// A bit of stray commentary here:
// The simplest GCD scheme is direct Euclidean with the central loop
// being
//     q = a/b;
//     {a, b} = {b, a - q*b};
// There are those who observe that on average the quotient q will be
// small, so they replace this with
//     {a, b} = {a, a - b};
//     swap a and b if necessary so that a>=b.
// This takes more steps but each is a subtraction not a division/remainder
// operation and so might sometimes be a win.
// A "least-remainder" scheme is
//     q = (a + b/2)/b;
//     {a, b} = {b, |a - q*b|};
// where the calculation of q just means round the quotient to nearest
// rather than truncate it towards zero. At the cost of the extra absolute
// value calculation this will reduce the number of steps. I believe that
// using the Euclidean scheme each step shrinks the inputs by an average of
// about 1.7 bits, while the least remainder scheme shrinks values by
// 2.4 or 2.5 bits per step, ie it saves around 30% of the steps, albeit at
// the cost of some absolute value calculations, which could go some way to
// balance out the savings.
// The quotient q will in general be small. In the case where it is very large
// then calculating it becomes tedious. So in such cases it will make sense
// to calculate a leading-digit approximation to it and reduce using that. A
// step of that nature would be essentially what wa happening in long division
// anyway, but now if the guessed quotient is not perfect all will be well
// because subsequent reduction steps will correct for it automatically.
// A Lehmer-style scheme will be useful when the firts several quotients in a
// sequence will all be small - it consolidates big-number arithmetic over
// what are logically multiple individual reduction steps.


inline std::intptr_t Gcd::op(std::uint64_t* a, std::uint64_t* b)
{   if (numberSize(b) == 1)
        return Gcd::op(a, static_cast<SignedDigit>(b[0]));
// I will start by making copies of |a| and |b| that I can overwrite
// during the calculation and use part of in my result.
    std::size_t lena = numberSize(a), lenb = numberSize(b);
    std::size_t olena = lena, olenb = lenb;
    if (olena == olenb &&
        // See comments later for an explanation of this!
        negative(a[lena-1]) && negative(b[lenb-1]) &&
        a[lena-1] == b[lenb-1]) olena++;
    std::uint64_t* av = reserve(olena);
    if (negative(a[lena-1])) internalNegate(a, lena, av);
    else internalCopy(a, lena, av);
    std::uint64_t* bv = reserve(olenb);
    if (negative(b[lenb-1])) internalNegate(b, lenb, bv);
    else internalCopy(b, lenb, bv);
    a = av;
    b = bv;
    if (bigUnsignedGreaterp(b, lenb, a, lena))
    {   std::swap(a, b);
        std::swap(lena, lenb);
        std::swap(olena, olenb);
    }
// Now a >= b and both numbers are in freshly allocated memory. I will
// remember the sizes of these two arrays.
// Remove any leading zero digits, and if that reduces the situation to
// a 1-word case handle that specially..
    if (b[lenb-1] == 0) lenb--;
    if (a[lena-1] == 0) lena--;
    if (lenb == 1)
    {   Digit bb = b[0];
        Digit hi = 0, q;
        for (std::size_t i=lena-1;; i--)
        {   divide64(hi, a[i], bb, q, hi);
            if (i == 0) break;
        }
        while (hi != 0)
        {   Digit cc = bb % hi;
            bb = hi;
            hi = cc;
        }
        abandon(a);
        abandon(b);
        return unsignedIntToBignum(bb);
    }
// In some cases performing a reduction will require a workspace vector.
// I will only allocate this as and when first needed.
    std::uint64_t* temp = nullptr;
    std::size_t lentemp = lena;
// Now at last a and b and genuine unsigned vectors without leading digits
// and with a > b. The next line is the key iteration in this whole procedure.
    while (lenb != 1)
    {   gcd_reduction(a, lena, b, lenb, olena, olenb, temp, lentemp);
        if (bigUnsignedGreaterp(b, lenb, a, lena))
        {   std::swap(a, b);
            std::swap(lena, lenb);
            std::swap(olena, olenb);
        }
    }
    if (temp != nullptr) abandon(temp);
// One possibility is that b==0 and then a holds the GCD. There is a
// pathological case where an input was -2^(64*n-1), which fits within n
// words, and the GCD ends up as +2^(64*n-1) which needs an extra word.
// If the other input had been bigger I can copy my result into it and
// survive.. the very messy situation would be if both inputs were
// -2^(64*n-1) so had I worked in the obvious way I would not have enough
// space for the result. To allow for this I arrange that if both inputs
// start off the same size (and ideally I would check if both had a value
// of the form -2^(64*n-1), but doing that check is probably more expensive
// that occasionally over-allocating memory!) I enlarge one of the inputs by
// one word.
    if (b[0] == 0)
    {   if (negative(a[lena-1]))
        {   if (lena == olena)
            {   internalCopy(a, lena, b);
                abandon(a);
                a = b;
                olena = olenb;
            }
            else abandon(b);
            a[lena++] = 0;
        }
        else abandon(b);
        return confirmSize(a, olena, lena);
    }
// If b is not zero here then it represents a value up to 2^64-1, and I can
// complete the GCD by doing a long-by-short remainder and then a short-num
// GCD...
    Digit bb = b[0];
    abandon(b);
    Digit hi = 0, q;
    for (std::size_t i=lena-1;; i--)
    {   divide64(hi, a[i], bb, q, hi);
        if (i == 0) break;
    }
    abandon(a);
    while (hi != 0)
    {   Digit cc = bb % hi;
        bb = hi;
        hi = cc;
    }
    return unsignedIntToBignum(bb);
}

inline std::intptr_t Gcd::op(std::uint64_t* a, SignedDigit bb)
{
// This case involved doing a long-by-short remainder operation and then
// it reduces to the small-small case. The main problem is the handling of
// negative inputs.
    if (bb == 0)
    {   if (Minusp::op(a)) return Minus::op(a);
        else return vectorToHandle(a);
    }
    Digit b = bb < 0 ? -bb : bb;
    std::size_t lena = numberSize(a);
    bool signa = negative(a[lena-1]);
    Digit hi = 0, q;
    for (std::size_t i=lena-1;; i--)
    {   divide64(hi, (signa ? ~a[i] : a[i]), b, q, hi);
        if (i == 0) break;
    }
// Now if a had been positive we have hi=a%b. If a had been negative we
// have (~a)%b == (-a-1)%b which is about |a|%b -1
    if (signa) hi = (hi+1)%b;
    return Gcd::op(b, hi);
}

inline std::intptr_t Gcd::op(SignedDigit a, std::uint64_t* b)
{   return Gcd::op(b, a);
}

inline std::intptr_t Gcd::op(SignedDigit a, SignedDigit b)
{
// Take absolute values of both arguments.
    Digit aa = a < 0 ? -static_cast<Digit>(a) : a;
    Digit bb = b < 0 ? -static_cast<Digit>(b) : b;
// Ensure that aa >= bb
    if (bb > aa) std::swap(aa, bb);
// Do simple Euclidean algorithm
    while (bb != 0)
    {   Digit cc = aa % bb;
        aa = bb;
        bb = cc;
    }
// A messy case is gcd(-MIX_FIXNUM, MIN_FIXNUM) which yields -MIN_FIXNUM
// which is liable to be MAX_FIXNUM+1 and so has to be returned as a bignum.
    return unsignedIntToBignum(aa);
}

// I think I have space-leaks within my code for LCM. For use in
// a system with garbage collection that will not matter (hoorah) but at
// some stage I need to come back here and look harder and tidy things up.

inline std::intptr_t Lcm::op(std::uint64_t* a, std::uint64_t* b)
{   std::intptr_t g = Gcd::op(a, b);
    std::intptr_t q = op_dispatch2<Quotient,std::intptr_t>
                      (vectorToHandle(b),
                       g);
    q = op_dispatch2<Times,std::intptr_t>(vectorToHandle(a), q);
    return op_dispatch1<Abs,std::intptr_t>(q);
}

inline std::intptr_t Lcm::op(std::uint64_t* a, SignedDigit b)
{   std::intptr_t g = Gcd::op(a, b);
    std::intptr_t q = op_dispatch2<Quotient,std::intptr_t>(intToHandle(
                          b), g);
    q = op_dispatch2<Times,std::intptr_t>(vectorToHandle(a), q);
    return op_dispatch1<Abs,std::intptr_t>(q);
}

inline std::intptr_t Lcm::op(SignedDigit a, std::uint64_t* b)
{   return Lcm::op(b, a);
}

inline std::intptr_t Lcm::op(SignedDigit a, SignedDigit b)
{   std::intptr_t g = Gcd::op(a, b);
// The GCD can only be a bignum if a = b = MIN_FIXNUM.
    if (storedAsFixnum(g))
    {   b = b / intOfHandle(g);
        std::intptr_t q = Times::op(a, b); // possibly a bignum now
        return op_dispatch1<Abs,std::intptr_t>(q);
    }
    else return unsignedIntToBignum(-static_cast<Digit>
                                           (MIN_FIXNUM));
}

#ifdef CSL
// Support for calculations modulo some integer value...

// Some of these NEED to be inline, so that they are shared across all
// uses...

inline const int modulus_32 = 0;
inline const int modulus_64 = 1;
inline const int modulus_big = 2;
// On Windows these thread-locals may introduce serious overhead. I
// will worry about that later if needbe.
thread_local inline int modulusSize = 0;
thread_local inline Digit smallModulus = 2;

// When I tried "thread_local inline std::vector<T> V;" I got complaints
// about the TLS init function being multiply defined at least on one of
// the platforms I was interested in, so I use a slightly more contorted
// code style that seems to survive better...

inline std::vector<Digit>& largeModulusVector()
{   static thread_local std::vector<Digit> v;
    return v;
}

inline std::uint64_t* largeModulus()
{   return 1 + reinterpret_cast<std::uint64_t*>(largeModulusVector().data());
}

inline std::intptr_t value_of_currentModulus()
{   if (modulusSize == modulus_big)
    {   std::size_t n = numberSize(largeModulus());
        std::uint64_t* r = reserve(n);
        std::memcpy(r, largeModulus(), n*sizeof(Digit));
        return confirmSize(r, n, n);
    }
    else return intToHandle(smallModulus);
}

inline std::intptr_t SetModulus::op(SignedDigit n)
{   if (n < 1)
        UNLIKELY
        return (std::intptr_t)aerror1("Invalid arg to set-modulus",
                                      intToHandle(n));
    std::intptr_t r = value_of_currentModulus();
    smallModulus = n;
    if (n <= 0xffffffffU) modulusSize = modulus_32;
    else modulusSize = modulus_64;
    return r;
}

inline std::intptr_t SetModulus::op(std::uint64_t* n)
{   if (!Plusp::op(n))
        UNLIKELY
        return (std::intptr_t)aerror1("Invalid arg to set-modulus",
                                      vectorToHandle(n));
    std::intptr_t r = value_of_currentModulus();
    std::size_t lenn = numberSize(n);
    std::size_t bytes = (lenn+1)*sizeof(Digit);
    if (bytes > largeModulusVector().size())
        largeModulusVector().resize(bytes);
    std::memcpy(largeModulusVector().data(), &n[-1], bytes);
    modulusSize = modulus_big;
    return r;
}

inline std::intptr_t ModularNumber::op(SignedDigit a)
{   if (a >= 0)
    {   if (modulusSize == modulus_big) return intToHandle(a);
        else return intToHandle(a % smallModulus);
    }
    if (modulusSize == modulus_big) return Plus::op(largeModulus(), a);
    else
    {   a = a % smallModulus;
        if (a < 0) a += smallModulus;
        return intToHandle(a);
    }
}

inline std::intptr_t ModularNumber::op(std::uint64_t* a)
{   if (Minusp::op(a))
    {   std::intptr_t r = Remainder::op(a, largeModulus());
        if (Minusp::op(r))
        {   std::intptr_t r1 =
                op_dispatch1<Plus,std::intptr_t>(r, largeModulus());
            abandon(r);
            return r1;
        }
        else return r;
    }
    else return Remainder::op(a, largeModulus());
}

inline std::intptr_t ModularPlus::op(SignedDigit a, SignedDigit b)
{   Digit ua = a, ub = b;
// Because a and b are 64-bit signed values and they should be positive,
// their sum will fit within a 64-bit unsigned integer, but if the modulus
// is large it could be just a 1-word bignum...
    if (modulusSize == modulus_big)
    {   Digit r = ua + ub;
        if (numberSize(largeModulus()) == 1 &&
            r >= largeModulus()[0]) r -= largeModulus()[0];
        return unsignedIntToBignum(r);
    }
    Digit r = ua + ub;
    if (r >= smallModulus) r -= smallModulus;
    return intToHandle(static_cast<SignedDigit>(r));
}

inline std::intptr_t ModularPlus::op(SignedDigit a, std::uint64_t* b)
{
// One of the inputs here is a bignum, and that can only be valid if we
// have a large modulus.
    if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror1("bad arg for modular-plus",
                                      vectorToHandle(b));
    std::intptr_t r = Plus::op(a, b);
    if (op_dispatch1<Geq,bool>(r, largeModulus()))
    {   std::intptr_t r1 =
            op_dispatch1<Difference,std::intptr_t>(r, largeModulus());
        abandon(r);
        return r1;
    }
    else return r;
}

inline std::intptr_t ModularPlus::op(std::uint64_t* a, SignedDigit b)
{   return ModularPlus::op(b, a);
}

inline std::intptr_t ModularPlus::op(std::uint64_t* a,
                                     std::uint64_t* b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror1("bad arg for modular-plus",
                                      vectorToHandle(a));
    std::intptr_t r = Plus::op(a, b);
    if (op_dispatch1<Geq, bool>(r, largeModulus()))
    {   std::intptr_t r1 =
            op_dispatch1<Difference,std::intptr_t>(r, largeModulus());
        abandon(r);
        return r1;
    }
    else return r;
}

inline std::intptr_t ModularDifference::op(SignedDigit a, SignedDigit b)
{   if (a >= b) return intToHandle(a - b);
    if (modulusSize == modulus_big) return Plus::op(largeModulus(), a - b);
    else return intToHandle(smallModulus - b + a);
}

inline std::intptr_t ModularDifference::op(SignedDigit a, std::uint64_t* b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror1("bad arg for modular-plus",
                                      vectorToHandle(b));
    std::intptr_t r = Difference::op(b, a);
    std::intptr_t r1 =
        op_dispatch1<RevDifference,std::intptr_t>(r, largeModulus());
    abandon(r);
    return r1;
}

inline std::intptr_t ModularDifference::op(std::uint64_t* a, SignedDigit b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror1("bad arg for modular-plus",
                                      vectorToHandle(a));
    return Difference::op(a, b);
}

inline std::intptr_t ModularDifference::op(std::uint64_t* a, std::uint64_t* b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror1("bad arg for modular-plus",
                                      vectorToHandle(a));
    if (Geq::op(a, b)) return Difference::op(a, b);
    std::intptr_t r = Difference::op(b, a);
    std::intptr_t r1 =
        op_dispatch1<RevDifference,std::intptr_t>(r, largeModulus());
    abandon(r);
    return r1;
}


inline std::intptr_t ModularTimes::op(SignedDigit a, SignedDigit b)
{   switch (modulusSize)
    {   case modulus_32:
            return intToHandle((static_cast<Digit>(a)* 
                                  static_cast<Digit>(b)) %
                                 smallModulus);
        case modulus_64:
        {   Digit hi, lo, q, r;
            multiply64(static_cast<Digit>(a),
                       static_cast<Digit>(b),
                       hi, lo);
            divide64(hi, lo, smallModulus, q, r);
            return intToHandle(r);
        }
        default:
        case modulus_big:
        {   std::intptr_t w = Times::op(a, b);
            std::intptr_t r =
                op_dispatch1<Remainder,std::intptr_t>(w, largeModulus());
            abandon(w);
            return r;
        }
    }
}

inline std::intptr_t ModularTimes::op(SignedDigit a, std::uint64_t* b)
{   std::intptr_t w = Times::op(a, b);
    std::intptr_t r =
        op_dispatch1<Remainder,std::intptr_t>(w, largeModulus());
    abandon(w);
    return r;
}

inline std::intptr_t ModularTimes::op(std::uint64_t* a, SignedDigit b)
{   return ModularTimes::op(b, a);
}

inline std::intptr_t ModularTimes::op(std::uint64_t* a, std::uint64_t* b)
{   std::intptr_t w = Times::op(a, b);
    std::intptr_t r =
        op_dispatch1<Remainder,std::intptr_t>(w, largeModulus());
    abandon(w);
    return r;
}


inline std::intptr_t ModularExpt::op(SignedDigit a, SignedDigit b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}

inline std::intptr_t ModularExpt::op(SignedDigit a, std::uint64_t* b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}

inline std::intptr_t ModularExpt::op(std::uint64_t* a, SignedDigit b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}

inline std::intptr_t ModularExpt::op(std::uint64_t* a, std::uint64_t* b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}


inline std::intptr_t ModularQuotient::op(SignedDigit a, SignedDigit b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}

inline std::intptr_t ModularQuotient::op(SignedDigit a, std::uint64_t* b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}

inline std::intptr_t ModularQuotient::op(std::uint64_t* a, SignedDigit b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}

inline std::intptr_t ModularQuotient::op(std::uint64_t* a, std::uint64_t* b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}


inline std::intptr_t ModularMinus::op(SignedDigit a)
{   if (a == 0) return intToHandle(a);
    if (modulusSize == modulus_big)
        return Difference::op(largeModulus(), a);
    else return intToHandle(smallModulus - a);
}

inline std::intptr_t ModularMinus::op(std::uint64_t* a)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror1("bad argument for modular-minus",
                                      vectorToHandle(a));
    return Difference::op(largeModulus(), a);
}

inline std::intptr_t generalModularReciprocal(std::intptr_t aa,
                                              bool safe=false)
{
// I believe that this could be speeded up significantly in cases where
// the modulus is huge by using a Lehmer-style process as in the simpler
// GCD code. Also it could save memory turnover by re-using the space
// from intermediate results. At least for now I will be happy if I just
// implement a version that actually works!
    intptr_t a = vectorToHandle(largeModulus());
    intptr_t b = aa;
    intptr_t x = intToHandle(0);
    intptr_t y = intToHandle(1);
    while (b != intToHandle(1))
    {   intptr_t w, t;
        if (b == intToHandle(0))
        {   if (safe) return nil;
            else
                UNLIKELY
                return (std::intptr_t)aerror(
                    "non-prime modulus in modular-reciprocal");
        }
        w = Quotient::op(a, b);
        t = b;
        b = Difference::op(a, Times::op(a, w));
        a = t;
        t = y;
        y = Difference::op(x, Times::op(y, w));
        x = t;
    }
    if (Minusp::op(y)) y = Plus::op(y, vectorToHandle(largeModulus()));
    return y;
}

inline std::intptr_t ModularReciprocal::op(SignedDigit aa)
{   if (aa <= 0)
        UNLIKELY
        return (std::intptr_t)aerror1("bad argument to modular-reciprocal",
                                      intToHandle(aa));
    else if (modulusSize == modulus_big)
        return generalModularReciprocal(intToHandle(aa));
    SignedDigit a = smallModulus,
                 b = aa,
                 x = 0,
                 y = 1;
    while (b != 1)
    {   Digit w, t;
        if (b == 0)
            UNLIKELY
            return (std::intptr_t)aerror2(
                    "non-prime modulus in modular-reciprocal",
                    intToHandle(smallModulus),
                    intToHandle(aa));
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += smallModulus;
    return intToHandle(y);
}

inline std::intptr_t ModularReciprocal::op(std::uint64_t* a)
{   return generalModularReciprocal(vectorToHandle(a));
}

inline std::intptr_t SafeModularReciprocal::op(SignedDigit aa)
{   if (aa <= 0)
        UNLIKELY
        return (std::intptr_t)aerror1(
            "bad argument to safe-modular-reciprocal",
            intToHandle(aa));
    else if (modulusSize == modulus_big)
        UNLIKELY
        return generalModularReciprocal(intToHandle(aa), true);
    SignedDigit a = smallModulus,
                 b = aa,
                 x = 0,
                 y = 1;
    while (b != 1)
    {   Digit w, t;
        if (b == 0) return nil;
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += smallModulus;
    return intToHandle(y);
}

inline std::intptr_t SafeModularReciprocal::op(std::uint64_t* a)
{   return generalModularReciprocal(vectorToHandle(a), true);
}

#endif // CSL

} // end of namespace arithlib_implementation

// I want a namespace that the user can activate via "using" that only
// gives access to things that ought to be exported by this library. So
// arithlib_implementation is to be thought of as somewhat low level and
// private, while just plain arithlib may be enough for the typical C++
// user who is just going to be using the "Bignum" type.
//
// [The issue of whether I have everything I need included in this list
//  remains uncertain, however a user can either add to the section here
//  or use the arithlib_implementation namespace directly in case of upset]

namespace arithlib
{
using arithlib_implementation::operator"" _Z;
using arithlib_implementation::Bignum;

using arithlib_implementation::version_string;
using arithlib_implementation::version;

using arithlib_implementation::mersenne_twister;
using arithlib_implementation::reseed;
using arithlib_implementation::uniformUint64;
using arithlib_implementation::uniformPositive;
using arithlib_implementation::uniformSigned;
using arithlib_implementation::uniformPositiveBignum;
using arithlib_implementation::uniformSignedBignum;
using arithlib_implementation::randomUptoBitsBignum;

using arithlib_implementation::display;
using arithlib_implementation::fixBignum;
}

// I am putting in names that CSL uses here...

namespace arithlib_lowlevel
{
using arithlib_implementation::Plus;
using arithlib_implementation::Difference;
using arithlib_implementation::RevDifference;
using arithlib_implementation::Times;
using arithlib_implementation::ClassicalTimes;
using arithlib_implementation::Quotient;
using arithlib_implementation::Remainder;
using arithlib_implementation::Mod;
using arithlib_implementation::Floor;
using arithlib_implementation::Ceiling;
using arithlib_implementation::Divide;
using arithlib_implementation::Gcd;
using arithlib_implementation::Lcm;
using arithlib_implementation::Logand;
using arithlib_implementation::Logor;
using arithlib_implementation::Logxor;
using arithlib_implementation::Logeqv;
using arithlib_implementation::Zerop;
using arithlib_implementation::Onep;
using arithlib_implementation::Minusp;
using arithlib_implementation::Plusp;
using arithlib_implementation::Evenp;
using arithlib_implementation::Oddp;
using arithlib_implementation::Eqn;
using arithlib_implementation::Neqn;
using arithlib_implementation::Geq;
using arithlib_implementation::Greaterp;
using arithlib_implementation::Leq;
using arithlib_implementation::Lessp;
using arithlib_implementation::Add1;
using arithlib_implementation::Sub1;
using arithlib_implementation::Minus;
using arithlib_implementation::Abs;
using arithlib_implementation::Square;
using arithlib_implementation::Isqrt;
using arithlib_implementation::Lognot;
using arithlib_implementation::Pow;
using arithlib_implementation::LeftShift;
using arithlib_implementation::RightShift;
using arithlib_implementation::Low64Bits;
using arithlib_implementation::LowBit;
using arithlib_implementation::IntegerLength;
using arithlib_implementation::Top64Bits;
using arithlib_implementation::Logbitp;
using arithlib_implementation::Logcount;
using arithlib_implementation::Float;    // returns 32-bit float
using arithlib_implementation::Double;   // returns 64-bit float
using arithlib_implementation::Frexp;
#ifdef CSL
using arithlib_implementation::ModularPlus;
using arithlib_implementation::ModularDifference;
using arithlib_implementation::ModularTimes;
using arithlib_implementation::ModularExpt;
using arithlib_implementation::ModularQuotient;
using arithlib_implementation::ModularMinus;
using arithlib_implementation::ModularReciprocal;
using arithlib_implementation::SafeModularReciprocal;
using arithlib_implementation::ModularNumber;
using arithlib_implementation::SetModulus;
#endif // CSL

using arithlib_implementation::intToBignum;
using arithlib_implementation::unsignedIntToBignum;
using arithlib_implementation::int128ToBignum;
using arithlib_implementation::unsignedInt128ToBignum;

using arithlib_implementation::bignumToString;
using arithlib_implementation::bignumToStringLength;
using arithlib_implementation::bignumToStringHex;
using arithlib_implementation::bignumToStringHexLength;
using arithlib_implementation::bignumToStringOctal;
using arithlib_implementation::bignumToStringOctalLength;
using arithlib_implementation::bignumToStringBinary;
using arithlib_implementation::bignumToStringBinaryLength;

using arithlib_implementation::roundDoubleToInt;
using arithlib_implementation::truncDoubleToInt;
using arithlib_implementation::floorDoubleToInt;
using arithlib_implementation::ceilingDoubleToInt;

using arithlib_implementation::reseed;
using arithlib_implementation::uniformUpto;

#ifdef softfloat_h
using arithlib_implementation::Float128;   // returns 128-bit float
using arithlib_implementation::Frexp128;
using arithlib_implementation::roundFloat128ToInt;
using arithlib_implementation::truncFloat128ToInt;
using arithlib_implementation::floorFloat128ToInt;
using arithlib_implementation::ceilingFloat128ToInt;
// These next few are just raw float128_t values and operations.
using arithlib_implementation::f128_0;
using arithlib_implementation::f128_half;
using arithlib_implementation::f128_mhalf;
using arithlib_implementation::f128_1;
using arithlib_implementation::f128_m1;
using arithlib_implementation::f128_zero;
using arithlib_implementation::f128_infinite;
using arithlib_implementation::f128_nan;
using arithlib_implementation::frexp;
using arithlib_implementation::ldexp;
using arithlib_implementation::modf;
#endif // softfloat_h

// The next few are functions I may like to use in low-level code...
//using arithlib_implementation::negative;
//using arithlib_implementation::numberSize;
//using arithlib_implementation::multiply64;

using arithlib_implementation::castTo_float;

}

#ifdef MEASURE_WORKSPACE

int main(int argc, char* argv[])
{   arithlib_implementation::main();
    return 0;
}

#endif // MEASURE_WORKSPACE

#endif // __arithlib_hpp

// end of arithlib.hpp
