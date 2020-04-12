// Big Number arithmetic.                               A C Norman, 2019-20

// To use this, go "#include "arithlib.hpp".

#ifndef __arithlib_hpp
#define __arithlib_hpp 1

// To do:
//    Use newer thread-local stuff, and especially put in thread locality
//     support for the modular arithmetic.
//    Write full documentation! [Meanwhile there is a reasonably extended
//     commentary included as comments here, and a file arithtest.cpp that
//     can accompany it and illustrate its use]

/**************************************************************************
 * Copyright (C) 2019-20, Codemist.                      A C Norman       *
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
// copy in the eventual linked binary. From C++17 onwards data as well as
// code can be tagged "inline" in this sense. Until I can be confident that
// everybody will use a compiler that supports C++17 I need to go through
// quite odd-looking steps so that when this header is included from several
// compilation units I do not end up with multiply-defined entities.
//
// This code uses 64-bit digits and a 2s complement representation for
// negative numbers. This means it will work best on 64-bit platforms
// (which by now are by far the most important), and it provides bitwise
// logical operations (logand and logor) as well as arithmetic. It will work
// best where the C++ compiler supports a 128-bit integral type, but does not
// need that. It should work on 32-bit systems as well, although one should
// expect performance there to be lower.
//
// The code here tried to arrange that any operations that might overflow are
// done using unsigned types, because in C++ overflow in signed arithmetic
// yields undefined results - ie on some machines the values delivered could
// be quite unrelated to the desired ones. This means that I do plenty of
// arithmetic rather as
//     int c = (int)((unsigned)a + (unsigned)b);
// and I rely on the result being as would be seen with natural 2s complement
// working. From C++20 onwards this is likely to be guaranteed by the standard,
// but at present it is not, so although this could will work on almost all
// known machines if judged against the standard at is at best relying on
// implementation defined behaviour and avoiding undefined behaviour.
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
// call to confirm_size() to establish the exact size that is to be retained.
// A variant call confirm_size_x() is used when the vector whose size is being
// confirmed is not the one that was most recently allocated: the intent
// there was that under some schemes discarding or shortening the most
// recently allocated item might be especially easy to implement well.
// confirm_size() returns a handle for the vector, not the vector itself.
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
// variants). Space for the string will be allocated using reserve_string()
// and finalized using confirm_size_string(), with both of those indicating
// sizes in bytes. Note that when you reserve or confirm string size the
// length quoted is the number of characters that will be present excluding
// any header or termination markers - reserve_string() will allow for the
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
//   uses malloc() to obtain space. confirm_size() uses realloc() to trim
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
//   memory block), the other contains log2(block_size), ie it is a compact
//   indication of the size of the block. There will be free-chains for
//   blocks of size 2,4,8,... so that abandon() just pushes the released
//   memory onto one and reserve() can often merely retrieve a previously
//   used block. In most cases confirm_size just needs to write the actual
//   length of a number into the header word. When two large numbers are
//   subtracted the number of digits in the result may be much smaller than
//   the size of block that had to have been reserved. To allow for that sort
//   of situation confirm_size() reserves the right to notice cases where used
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
//   In this case there is an extra option DEBUG_OVERRUN which enables some
//   simple checks for memory block overflow. reserve() always arranges that
//   there will be a "spare" word just beyond the top used word in a vector,
//   and it initializes this to a slightly unlikely value. When confirm_size
//   or abandon() are used it can then verify that this guard word has not
//   been corrupted. This may not be 100% foolproof but is nevertheless helps
//   while developing or maintaining the library!
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
//   Those issue motivate the distinction between confirm_size and
//   confirm_size_x. [Note that the implementation may not (yet) do all that
//   I intended in that respect!]
//   Usually calls to memory allocation primitives are made without any special
//   concern for garbage collector safety of other pointers, and so in its
//   current form this code insists on running in a context where the garbage
//   collector is conservative, so that for instance the untagged pointers to
//   raw vectors of digits are safe. This aspect of the code may well limit
//   its direct usefulness. So too allow for a system that uses a precise
//   garbage collector I allow for a "#define PRECISE_GC 1" option and in
//   that case whenever calls to memory allocation are performed within the
//   low-level code I will use functions "push()" and "pop()" and
//   expect that they save values somewhere that the garbage collector can
//   find. Note that this scheme does not automate keeping large bignum
//   calculations expressed via operator overloading safe! It is mostly aimed
//   at making the low level code usable. A typical case where push() and
//   pop() are needed will be the code to multiply two big numbers. That can
//   work out how large its result will be and then needs to call reserve()
//   to get space for it. Across the call to reserve it will need to push
//   its two arguments, because a copying garbage collector might relocate
//   them.
//   Further though: having "push and pop" suggests that a potentially large
//   number of items might need to be saved. I suspect that the most I can
//   ever encounter here will be perhaps 3. So having a fixed number of
//   dedicated list basis to stash things in might be nicer.
//   In Lisp mode it is anticipated that as well as a tagged representation
//   of small integers that the generic arithemetic will need to support
//   floating point numbers (and possibly multiple widths of floating point
//   values, plus ratios and complex numbers) and so the dispatch on tagged
//   numbers needs to live at a higher level within the Lisp then just thise
//   code. Thus while the big-number functions here are set up so they can
//   return fixnum results and while there are entrypoints for performing
//   arithmetic between bignums and fixnums  (ie between uint64_t * and
//   int64_t values) it is the responsibility of somebody else to decide which
//   functions to call when.
//   Strings are allocated using reserve_string() and finalized using
//   confirm_size_string. For Lisp purposes they will need to have a header
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
//     your machine.
// (3) By being a header-only library, arithlib imposes a cost at program
//     build time as it all has to be processed by the compiler - but these
//     days compile-times are pretty short anyway. And by having all of
//     its souce code available when code that uses it is built there are
//     potential whole-program optimisations that can be made.
// (4) arithlib is coded in C++ not C, and this allows it to leverage features
//     of C++11. For instance it can rely on the random number generation
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
// to many casts beween  std::uint64_t*  and std::uintptr_t, and the
// unpacking of a signed value from the immediate integer case leads to
// further casts with signed integers, ie std::intptr_t.
// Finally I need at times to generate a bit-fiels using code such as
// (1<<n). If the literal "1" is not introduced using a wide enough type
// this can overflow. I might try (1LLU<<n) but I have no absolute guarantee
// that "LL" makes a 64-bit integer. I could use UINT64_C(1) and that is not
// too bad, but in many places I will in fact write the rather wordy but very
// explicit (static_cast<std::uint64_t>(1)<<n).


// I provide a default configuration, but by predefining one of the
// symbols allow other versions to be built.

#if !defined MALLOC && !defined NEW && !defined LISP
// If no explicit options have been set I will building using memory
// allocation via C++ "new".

#define NEW           1
#define DEBUG_OVERRUN 1   // Overhead is not huge: watching for error is good.

#endif

#ifdef __cpp_inline_variables

// For versions of C++ up to C++17 I will put constant values in header
// files using something along the line of "static const int VAR = VAL;".
// This should give the compiler a chance to replace the name with its value
// throughout the compilation unit, and if the compiler is clever enough it
// will avoid leaving a word of memory with the value stored if all uses
// have been dealt with more directly. However it will tend to lead to a
// lot of "static variable defined but not used" warnings.
// From C++17 onwards (and C++ mandates the __cpp_inline_variables macro to
// indicate if the feature is in place) I will use
//             inline const int VAR = VAL;
// and now if memory is allocated for the variable it will only be allocated
// once, and I hope that compilers will not feel entitled to moan about
// cases where there are no references. I will only use this idiom for things
// that are at least "almost" constant so that in the case that the variables
// end up static and there are different copies in each compilation unit
// it should not cause cconfusion.

#define INLINE_VAR inline
#define HAVE_INLINE_VARS 1
#else
#define INLINE_VAR static
#endif


// Another useful C++17 feature.... with a fallback to a GNU-specific
// way of achieving the same through use of C++11 annotations. And a final
// fall back to just not worrying.

#ifndef MAYBE_UNUSED
#ifdef __has_cpp_attribute_maybe_unused
#define MAYBE_UNUSED [[maybe_unused]]
#elif defined __GNUC__
#define MAYBE_UNUSED [[gnu::unused]]
#else
#define MAYBE_UNUSED
#endif
#endif

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
#include <thread>
#include <ctime>
#include <chrono>
#include <utility>
#include <string>
#include <chrono>
#include <mutex>
#include <atomic>
#include <vector>
#include <type_traits>

namespace arithlib_implementation
{

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
// one of if. It also sets its argument to a reference to a const char *
// pointer that will be used for transmitting the location information.

#ifdef HAVE_INLINE_VARS
inline std::mutex my_diagnostic_mutex;
inline static const char *my_diagnostic_location;
#endif // HAVE_INLINE_VARS

inline std::mutex &diagnostic_mutex(const char ***where)
{
#ifndef HAVE_INLINE_VARS
// C++11 guarantees that even if this header is included from many
// compilation units there will be a single unique mutex here. I guarantees
// that the mutex will have been constructed (ie initialized) by the time
// an execution path flows past its definition. However there can be
// overhead since the C++ run-time system may protect itself from risk of
// multiple threads triggering initialization at the same time. In doing so
// it may be that the initialization involved not just a simple boolean flag
// but some synchronization primitives. If we have C++17 then inline
// variable declarations achieve pretty well just what I want without this
// mess, so I will use it.
    static std::mutex my_diagnostic_mutex;
    static const char *my_diagnostic_location;
#endif // !HAVE_INLINE_VARS
    *where = &my_diagnostic_location;
    return my_diagnostic_mutex;
}

[[noreturn]] inline void abort1(const char *msg)
{   const char **where;
// The call to diagnostic_mutex here is just to retrieve the location of the
// const char * variable that holds the location. I am already within
// the scope of a mutex.
    static_cast<void>(diagnostic_mutex(&where));
    std::cout << std::endl << "About to abort at " << *where << ": "
              << msg << std::endl;
    std::abort();
}

[[noreturn]] inline void abort1()
{   const char **where;
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

// bacause arithlib_abort is a macro it does not live in any particular
// namespace

#define arithlib_abort(...)                                                \
    {   const char **where;                                                \
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
inline void assert1(bool ok, const char *why,
                    F&& action, const char *location)
{
// Use this as in:
//     arithlib_assert(predicate, [&]{...});
// where the "..." is an arbitrary sequence of actions to be taken
// if the assertion fails. The action will typically be to display
// extra information about what went wrong.
    if (debug_arith && !ok)
    {   action();
        const char **where;
        std::lock_guard<std::mutex> lock(diagnostic_mutex(&where));
        *where = location;
        abort1();
    }
}

inline void assert1(bool ok, const char *why, const char *location)
{
// For simple use where a customised message is not required:
//     arithlib_assert(predicate);
    if (debug_arith && !ok)
    {   const char **where;
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

inline void logprintf(const char *fmt, ...)
{
// I use a fixed name for the log file. This is another respect in which
// this has to be seen as code only suitable for temporary use. I use static
// variables that are local to this function so that even if the header is
// included from multiple source files there will not be multiple-definition
// clashes, and since this is just for diagnostics I am not worried about
// any costs that this imposes.
    static std::FILE *logfile = NULL;
    const char **where;
    std::lock_guard<std::mutex> lock(diagnostic_mutex(&where));
    if (logfile == NULL) logfile = std::fopen("arith.log", "w");
    std::va_list args;
    va_start(args, fmt);
    std::vfprintf(logfile, fmt, args);
    va_end(args);
    std::fflush(logfile);
}

inline void traceprintf(const char *fmt, ...)
{   const char **where;
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

inline std::int32_t ASR(std::int32_t a, std::int64_t n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(std::int32_t))) n=0;
    std::uint32_t r = static_cast<std::uint32_t>(a) >> n;
    std::uint32_t signbit = static_cast<std::uint32_t>(a) >> (8*sizeof(
                                std::uint32_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(std::uint32_t) - n));
    return static_cast<std::int32_t>(r);
}

inline std::int64_t ASR(std::int64_t a, std::int64_t n)
{   if (n<0 || n>=8*static_cast<int>(sizeof(std::int64_t))) n=0;
    std::uint64_t r = static_cast<std::uint64_t>(a) >> n;
    std::uint64_t signbit = static_cast<std::uint64_t>(a) >> (8*sizeof(
                                std::uint64_t)-1);
    if (n != 0) r |= ((-signbit) << (8*sizeof(std::uint64_t) - n));
    return static_cast<std::int64_t>(r);
}

inline std::uint64_t ASR(std::uint64_t a, std::int64_t n)
{   return ASR(static_cast<std::int64_t>(a), n);
}

// The behaviour of left shifts on negative (signed) values seems to be
// labelled as undefined in C/C++, so any time I am going to do a left shift
// I need to work in an unsigned type. Well at some stage in the future it
// may be that C++ will insist that signed integers are handled in 2s
// complement form and shifts on them behave "as naively expected" but at
// present that can not be relied upon.

// In the comparisons I case the sizeof value to an int so that I can compare
// it against the signed amount n.

inline std::int32_t ASL(std::int32_t a, std::int64_t n)
{   if (n < 0 || n>=8*static_cast<int>(sizeof(std::uint32_t))) n = 0;
    return static_cast<std::int32_t>(static_cast<std::uint32_t>(a) << n);
}

inline std::int64_t ASL(std::int64_t a, std::int64_t n)
{   if (n < 0 || n>=8*static_cast<int>(sizeof(std::uint64_t))) n = 0;
    return static_cast<std::int64_t>(static_cast<std::uint64_t>(a) << n);
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
    static void set_binary_output(std::ios_base &s)
    {   flag(s) = 1;
        s.unsetf(std::ios_base::dec);
        s.unsetf(std::ios_base::oct);
        s.unsetf(std::ios_base::hex);
    }
    static bool is_binary_output(std::ios_base &s)
    {   return flag(s) != 0;
    }
private:
    static long & flag(std::ios_base &s)
    {   static int n = std::ios_base::xalloc();
        return s.iword(n);
    }
};

} // temporary end of namespace arithlib

// I want a new io manipulator "std::bin" to select binary mode output.
// This will be used much as std::oct, std::dec and std::hex.

namespace std
{   inline std::ostream &bin(std::ostream &os)
{   arithlib_implementation::radix::set_binary_output(os);
    return os;
}
}

// Provide better support for thread-local values.
// I could go '#include "thread_local.h"' here if I knew that that header
// file was available, but I want arithlib.hpp to be totally freestanding.
// To achieve that I textually insert a copy of thread_local.h, including the
// guards that avoid it being scanned more than once.

#ifdef CSL
#include "thread_local.h"
#else // CSL

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

// $Id: arithlib.hpp 5182 73eba49 2020-04-07 14:21:49 +0100 arthurcnorman $


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

    extern __declspec(dllimport) tls_handle TlsAlloc();
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
    else return static_cast<void *>(read_via_segment_register(
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
    {   tls_store(H.h, (void *)v);                            \
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
    {   tls_store(H.h, (void *)v);                            \
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
    {   tls_store(H.h, (void *)get());                        \
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

#endif // CSL

// end of schemes that are to do with thread-local support


namespace arithlib_implementation
{

// When I get to big-integer multiplication I will use two worker threads
// so that elapsed times for really large multiplications are reduced
// somewhat. Well ideally by a factor approaching 3. I set up a framework
// of support for the threads here. Each main program thread will want
// its own pair of worker threads here. Each worker thread gets passed a
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
#define USE_MICROSOFT_MUTEX 1

extern "C"
{   struct SecApp
    {   std::uintptr_t nLength;
        void *lpSecurityDescriptor;
        int bINheritHandle;
    };

    extern __declspec(dllimport)  void *
    CreateMutexA(SecApp *, std::uintptr_t, const char *);
    extern __declspec(dllimport) int CloseHandle(void *h);
    extern __declspec(dllimport) int ReleaseMutex(void *m);
    extern __declspec(dllimport) void *
    WaitForSingleObject(void *, std::uintptr_t);
};

#endif // __CYGWIN__ or __MINGW32__

class Worker_data
{
public:
    std::atomic<bool> ready;
#ifdef USE_MICROSOFT_MUTEX
    void *mutex[4];
#else
    std::mutex mutex[4];
#endif
    bool quit_flag;
    const std::uint64_t *a;
    std::size_t lena;
    const std::uint64_t *b;
    std::size_t lenb;
    std::uint64_t *c;
    std::uint64_t *w;

// When I construct an instance of Worker data I set its quit_flag to
// false and lock two of the mutexes. That sets things up so that when
// it is passed to a new worker thread that thread behaves in the way I
// want it to.
    Worker_data()
    {   ready = false;
        quit_flag = false;
#ifdef USE_MICROSOFT_MUTEX
        mutex[0] = CreateMutexA(NULL, 1, NULL);
        mutex[1] = CreateMutexA(NULL, 1, NULL);
        mutex[2] = CreateMutexA(NULL, 0, NULL);
        mutex[3] = CreateMutexA(NULL, 0, NULL);
#else
// The next two must be locked by the main thread.
        mutex[0].lock();
        mutex[1].lock();
#endif
    }
#ifdef USE_MICROSOFT_MUTEX
    ~Worker_data()
    {   CloseHandle(mutex[0]);
        CloseHandle(mutex[1]);
        CloseHandle(mutex[2]);
        CloseHandle(mutex[3]);
    }
#endif
};

inline void worker_thread(Worker_data *w);

// Then each main thread will have a structure that encapsulated the
// two worker threads that it ends up with and the data it sets up for
// them and that they then access. When this structures is created it will
// cause the worker threads and the data block they need to be constructed.

class Driver_data
{
public:
    int         send_count = 0;
    Worker_data wd_0,
                wd_1;
// When an instance of Driver_data is created the two sets of Worker_data
// get constructed with two of their mutexes locked. This will mean that when
// worker threads are created and start running they will politely wait for
// work.

    std::thread w_0, w_1;
    Driver_data()
    {   w_0 = std::thread(worker_thread, &wd_0),
            w_1 = std::thread(worker_thread, &wd_1);
// I busy-wait until the two threads have both claimed the mutexes that they
// need to own at the start! Without this the main thread may post a
// multiplication, so its part of the work and try to check that the worker
// has finished (by claiming one of these mutexes) before the worker thread
// has got started up and has claimed them. This feels clumsy, but it only
// happens at system-startup.
        while (!wd_0.ready.load() && !wd_1.ready.load())
            std::this_thread::sleep_for(std::chrono::microseconds(1));
    }

// When the Driver_data object is to be destroyed it must arrange to
// stop and then join the two threads that it set up. This code that sends
// a "quit" message to each thread will be executed before the thread object
// is deleted, and the destructor of the thread object should be activated
// before that of the Worker_data and the mutexes within that.

    ~Driver_data()
    {   wd_0.quit_flag = wd_1.quit_flag = true;
        release_workers();
        w_0.join();
        w_1.join();
    }

// Using the worker threads is then rather easy: one sets up data in
// the Worker_data structures and then call release_workers(). Then
// you can do your own thing in parallel with the two workers picking up
// the tasks that they had been given. When you are ready you call
// wait_for_workers() which does what one might imagine, and the workers
// are expected to have left their results in the Worker_data object so
// you can find it.

    void release_workers()
    {
#ifdef USE_MICROSOFT_MUTEX
        ReleaseMutex(wd_0.mutex[send_count]);
        ReleaseMutex(wd_1.mutex[send_count]);
#else
        wd_0.mutex[send_count].unlock();
        wd_1.mutex[send_count].unlock();
#endif
    }

    void wait_for_workers()
    {
#ifdef USE_MICROSOFT_MUTEX
        WaitForSingleObject(wd_0.mutex[send_count^2], 0xffffffff);
        WaitForSingleObject(wd_1.mutex[send_count^2], 0xffffffff);
#else
        wd_0.mutex[send_count^2].lock();
        wd_1.mutex[send_count^2].lock();
#endif
        send_count = (send_count+1)&3;
    }

};

// I encapsulate the driver data in this function, which will ensure that
// exactly one copy gets made for each top-level thread that calls this,
// ie that uses a huge multiplication.

declare_thread_local_ref(driver_data, Driver_data);

// Declare a number of functions that might usefully be used elsewhere. If
// I declare them "inline" then it will be OK even if I include this header
// from multiple source files because only one copy should end up in the
// eventually-linked executable.

inline std::uint64_t *reserve(std::size_t n);
inline std::intptr_t confirm_size(std::uint64_t *p, std::size_t n,
                                  std::size_t final);
inline std::intptr_t confirm_size_x(std::uint64_t *p, std::size_t n,
                                    std::size_t final);
inline void abandon(std::uint64_t *p);
inline void abandon(std::intptr_t h);

#if defined LISP && !defined ZAPPA
typedef std::intptr_t string_handle;
#else
typedef char *string_handle;
#endif

inline string_handle confirm_size_string(char *p, std::size_t n,
        std::size_t final);
inline void abandon_string(string_handle);

inline std::intptr_t vector_to_handle(std::uint64_t *p);
inline std::uint64_t *vector_of_handle(std::intptr_t n);
inline std::size_t number_size(std::uint64_t *p);

inline bool fits_into_fixnum(std::int64_t n);
inline std::intptr_t int_to_handle(std::int64_t n);
constexpr inline std::int64_t int_of_handle(std::intptr_t n);

inline std::intptr_t string_to_bignum(const char *s);
inline std::intptr_t int_to_bignum(std::int64_t n);
inline std::intptr_t unsigned_int_to_bignum(std::uint64_t n);
inline std::intptr_t round_double_to_int(double d);
inline std::intptr_t trunc_double_to_int(double d);
inline std::intptr_t floor_double_to_int(double d);
inline std::intptr_t ceiling_double_to_int(double d);
#ifdef softfloat_h
inline std::intptr_t round_float128_to_int(float128_t d);
inline std::intptr_t trunc_float128_to_int(float128_t d);
inline std::intptr_t floor_float128_to_int(float128_t d);
inline std::intptr_t ceiling_float128_to_int(float128_t d);
#endif // softfloat_h
inline std::intptr_t uniform_positive(std::size_t n);
inline std::intptr_t uniform_signed(std::size_t n);
inline std::intptr_t uniform_upto(std::intptr_t a);
inline std::intptr_t random_upto_bits(std::size_t bits);
inline std::intptr_t fudge_distribution(std::intptr_t, int);

#ifdef PRECISE_GC
inline void push(std::intptr_t w);
inline void pop(std::intptr_t& w);

// In many cases where I want to save things I will have a reference to
// an array of uint64_t objects, so when I push it I must convert it back to
// a Lisp-friendly form.
inline void push(std::uint64_t *p)
{   push(vector_to_handle(p));
}
inline void pop(std::uint64_t *&p)
{   std::intptr_t w;
    pop(w);
    p = vector_of_handle(w);
}
#else
// In cases where these are not required I will just defined them as
// empty procedures and hope that the C++ compiler will inline them and
// hence lead to them not adding any overhead at all.
inline void push(std::intptr_t p)
{}
inline void pop(std::intptr_t& p)
{}

inline void push(std::uint64_t *p)
{}
inline void pop(std::uint64_t *&p)
{}

inline void push(const std::uint64_t *p)
{}
inline void pop(const std::uint64_t *&p)
{}

#endif

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

typedef void *malloc_t(size_t n);
typedef void *realloc_t(void *, std::size_t);
typedef void free_t(void *);

INLINE_VAR malloc_t  *malloc_function = std::malloc;
INLINE_VAR realloc_t *realloc_function = std::realloc;
INLINE_VAR free_t    *free_function   = std::free;

inline std::uint64_t *reserve(std::size_t n)
{   arithlib_assert(n>0);
    std::uint64_t *r = reinterpret_cast<std::uint64_t *>
                       (*malloc_function)((
                               n+1)*sizeof(std::uint64_t));
    arithlib_assert(r != NULL);
    return &r[1];
}

inline std::intptr_t confirm_size(std::uint64_t *p, std::size_t n,
                                  std::size_t final)
{   artithlib_assert(final>0 && n>=final);
    p = reinterpret_cast<std::uint64_t *>()
        (*realloc_function)((void *)&p[-1],
                            (final_n+1)*sizeof(std::uint64_t));
    arithlib_assert(p != NULL);
    p[0] = final_n;
    return vector_to_handle(&p[1]);
}

// In this model confirm_size_x() is just the same as confirm_size().

inline std::intptr_t confirm_size_x(std::uint64_t *p, std::size_t n,
                                    std::size_t final)
{   arithlib_assert(final>0 && n>=final);
    confirm_size(p, n, final);
}

inline void abandon(std::uint64_t *p)
{   (*free_function)((void *)&p[-1]);
}

// Note that I allocate space for the string data plus a NUL terminating byte.

inline char *reserve_string(std::size_t n)
{   char *r = reinterpret_cast<char *>(*malloc_function)(n+1);
    arithlib_assert(r != NULL);
    return r;
}

// When I confirm the size of a string all I do is to write a NUL byte
// to terminate it. I expect the code to have reserved an amount of memory
// that is not much longer than the amount that I will need, so using
// realloc to shrink things to the exact size that is filled would not
// be a good bargain.

inline char *confirm_size_string(char *p, std::size_t n,
                                 std::size_t final)
{   arithlib_assert(final>0 && (n+9)>final);
    r[final] = 0;
    return r;
}

inline void abandon_string(char *s)
{   (*free_function)(s);
}

// In the C/malloc model I will represent a number by the intptr_t style
// integer that is obtained from a pointer to the first digit of the bignum.

inline std::intptr_t vector_to_handle(std::uint64_t *p)
{   return reinterpret_cast<std::intptr_t>(p);
}

inline std::uint64_t *vector_of_handle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t *>(n);
}

inline std::size_t number_size(std::uint64_t *p)
{   arithlib_assert(p[-1]!=0);
    return p[-1];
}

// When I use Bignums that are allocated using malloc() and operated on
// via C++ overloaded operators I often need to copy the data. However when
// memory management uses garbage collection I can allow multiple references
// to the same object and so copying is not needed as much. I have two
// copying functions. One only copies if the system is using MALLOC or
// NEW (but leaves data sharable on systems with garbage collection) while
// the other unconditionally copies.

inline std::intptr_t always_copy_bignum(std::uint64_t *p)
{   std::size_t n = p[-1];
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::uint64_t *p)
{   std::size_t n = p[-1];
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::intptr_t pp)
{   if (stored_as_fixnum(pp)) return pp;
    std::uint64_t *p = vector_of_handle(pp);
    std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
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


inline unsigned int log_next_power_of_2(std::size_t n);

// There is a serious issue here as regards thread safety. And a subsidiary
// on about C++17.
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
#endif

// Attempts to select more that one option at once get detected and moaned
// about.

#if (defined ARITHLIB_MUTEX && defined ARITHLIB_THREAD_LOCAL) ||      \
    (defined ARITHLIB_THREAD_LOCAL && defined ARITHLIB_NO_THREADS) || \
    (defined ARITHLIB_NO_THREADS && defined ARITHLIB_MUTEX)
#error Only one thread-support policy can be selected.
#endif

#ifdef ARITHLIB_MUTEX
inline std::mutex& freechain_mutex()
{   static std::mutex m;
    return m;
}
#endif

typedef std::uint64_t *freechain_table_type[64];

#ifdef ARITHLIB_THREAD_LOCAL
declare_thread_local_ref(freechain_table, freechain_table_type);
#else // ARITHLIB_THREAD_LOCAL
#ifdef __cpp_inline_variables
class freechain_table
{   static inline freechain_table_type freechain_table_Var;
public:
    static freechain_table_type& get()
    {   return freechain_table_Var;
    }
};
#else // __cpp_inline_variables
class freechain_table
{
public:
    static freechain_table_type& get()
    {   static freechain_table_type freechain_table_Var;
        return freechain_table_Var;
    }
};
#endif // __cpp_inline_variables
#endif // ARITHLIB_THREAD_LOCAL

class Freechains
{
private:
// The following obscure line ensures that when I make an instance
// of Freechains it forces the standard streams into existence. Having
// that initilization happening early helps a LITTLE bit to reassure me
// that the standard streams should still be alive during the destructor
// for this class.
    std::ios_base::Init force_iostreams_initialization;

public:
    Freechains()
    {   for (int i=0; i<64; i++) (freechain_table::get())[i] = NULL;
    }

    ~Freechains()
    {   if (debug_arith) std::cout << "Destructor being called" <<
                                       std::endl;
        for (std::size_t i=0; i<64; i++)
        {   std::uint64_t *f = (freechain_table::get())[i];
            if (debug_arith)
// Report how many entries there are in the freechain.
            {   std::size_t n = 0;
// To arrange that double-free mistakes are detected I arrange to put -1
// in the initial word of any deleted block, so that all blocks on the
// freechains here should show that. I set and test for that in the other
// bits of code that allocate or release memory.
                for (std::uint64_t *b=f; b!=NULL; b = (std::uint64_t *)b[1])
                {   arithlib_assert(b[0] == -static_cast<std::uint64_t>(1));
                    n++;
                }
                if (n != 0)
                    std::cout << "Freechain " << i << " length: "
                          << n << " " << ((static_cast<std::size_t>(1))<<i)
                          << std::endl;
            }
            while (f != NULL)
            {   std::uint64_t w = f[1];
                delete [] f;
                f = reinterpret_cast<std::uint64_t *>(w);
            }
            (freechain_table::get())[i] = NULL;
        }
    }

    static std::uint64_t *allocate(std::size_t n)
    {
#ifdef DEBUG_OVERRUN
// If I am debugging I can allocate an extra word that will lie
// just beyond what would have been the end of my block, and I will
// fill everything with a pattern that might let me spot some cases where
// I write beyond the proper size of data. This option is only supported
// when storage allocation is using NEW.
        int bits = log_next_power_of_2(n+1);
#else
// Finding the number of bits in n is achieved by counting the leading
// zeros in the representation of n, and on many platforms an intrinsic
// function will compile this into a single machine code instruction.
        int bits = log_next_power_of_2(n);
#endif
        arithlib_assert(n<=((static_cast<std::size_t>(1))<<bits) && n>0);
        std::uint64_t *r;
#if defined ARITHLIB_THREAD_LOCAL || ARITHLIB_NO_THREADS
        r = (freechain_table::get())[bits];
        if (r != NULL)
            (freechain_table::get())[bits] = reinterpret_cast<std::uint64_t *>
                                             (r)[1];
#elif defined ARITHLIB_MUTEX
        {   std::lock_guard<std::mutex> lock(freechain_mutex());
            r = (freechain_table::get())[bits];
            if (r != NULL)
                (freechain_table::get())[bits] =
                    reinterpret_cast<std::uint64_t *>(r[1]);
        }
#else
#error Internal inconsistency in arithlib.hpp: memory allocation strategy.
#endif
// If no memory had been found on the freechain I need to allocate some
// more.
        if (r == NULL)
        {   r = new std::uint64_t[(static_cast<std::size_t>(1))<<bits];
            if (r == NULL) arithlib_abort("Run out of memory");
        }
#ifdef DEBUG_OVERRUN
// When debugging I tend to initialize all memory to a known pattern
// when it is allocated and check that the final word has not been
// overwritten when I release it. This is not foolproof but it helps me
// by being able to detect many possible cases of overrun.
        if (debug_arith)
        {   std::memset(r, 0xaa,
                (static_cast<std::size_t>(1)<<bits)*sizeof(std::uint64_t));
            r[0] = 0;
        }
#endif
// Just the first 32-bits of the header word record the block capacity.
// The casts here look (and indeed are) ugly, but when I store data into
// memory as a 32-bit value that is how I will read it later on, and the
// messy notation here does not correspond to complicated computation.
        reinterpret_cast<std::uint32_t *>(r)[0] = bits;
        return r;
    }

// When I abandon a memory block I will push it onto a relevant free chain.

    static void abandon(std::uint64_t *p)
    {   arithlib_assert(p[0] != -static_cast<std::uint64_t>(1));
        int bits = reinterpret_cast<std::uint32_t *>(p)[0];
        arithlib_assert(bits>0 && bits<48);
// Here I assume that sizeof(uint64_t) >= sizeof(intptr_t) so I am not
// going to lose information here on any platform I can consider.
        if (debug_arith) p[0] = -static_cast<std::uint64_t>(1);
#ifdef ARITHLIB_ATOMIC
        lockfree_push(p, freechain_table::get(), bits);
#else
#ifdef ARITHLIB_MUTEX
        std::lock_guard<std::mutex> lock(freechain_mutex());
#endif
        p[1] = reinterpret_cast<std::uint64_t>(freechain_table::get()[bits]);
        (freechain_table::get())[bits] = p;
#endif
    }

};

#ifdef ARITHLIB_THREAD_LOCAL
declare_thread_local_ref(freechains, Freechains);
#else // ARITHLIB_THREAD_LOCAL
#ifdef __cpp_inline_variables
class freechains
{   static inline Freechains freechains_Var;
public:
    static Freechains& get()
    {   return freechains_Var;
    }
};
#else // __cpp_inline_variables
class freechains
{
public:
    static Freechains& get()
    {   static Freechains freechains_Var;
        return freechains_Var;
    }
};
#endif // __cpp_inline_variables
#endif // ARITHLIB_THREAD_LOCAL

inline std::uint64_t *reserve(std::size_t n)
{   arithlib_assert(n>0);
    return &(freechains::get().allocate(n+1))[1];
}

inline std::intptr_t confirm_size(std::uint64_t *p, std::size_t n,
                                  std::size_t final)
{   arithlib_assert(final>0 && n>=final);
// Verify that the word just beyond where anything should have been
// stored has not been clobbered.
#ifdef DEBUG_OVERRUN
    if (debug_arith) arithlib_assert(p[n] == 0xaaaaaaaaaaaaaaaaU);
#endif
    if (final == 1 && fits_into_fixnum(static_cast<std::int64_t>(p[0])))
    {   std::intptr_t r = int_to_handle(static_cast<std::int64_t>(p[0]));
        freechains::get().abandon(&p[-1]);
        return r;
    }
// I compare the final size with the capacity and if it is a LOT smaller
// I allocate a new smaller block and copy the data across.
// That situation can most plausibly arise when two similar-values big
// numbers are subtracted.
    int bits = reinterpret_cast<std::uint32_t *>(&p[-1])[0];
    std::size_t capacity = (static_cast<std::size_t>(1))<<bits;
    if (capacity > 4*final)
    {   std::uint64_t *w =
            freechains::get().allocate(
                (static_cast<std::size_t>(1))<<log_next_power_of_2(final+1));
        std::memcpy(&w[1], p, final*sizeof(std::uint64_t));
        freechains::get().abandon(&p[-1]);
        p = &w[1];
    }
    reinterpret_cast<std::uint32_t *>(&p[-1])[1] = final;
    return vector_to_handle(p);
}

inline std::intptr_t confirm_size_x(std::uint64_t *p, std::size_t n,
                                    std::size_t final)
{   arithlib_assert(final>0 && n>=final);
    return confirm_size(p, n, final);
}

inline std::size_t number_size(std::uint64_t *p)
{   std::size_t r = reinterpret_cast<std::uint32_t *>(&p[-1])[1];
    arithlib_assert(r>0);
    return reinterpret_cast<std::uint32_t *>(&p[-1])[1];
}

inline std::intptr_t vector_to_handle(std::uint64_t *p)
{   return reinterpret_cast<std::intptr_t>(p);
}

inline std::uint64_t *vector_of_handle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t *>(n);
}

inline bool stored_as_fixnum(std::intptr_t a)
{   return (a & 1) != 0;
}

constexpr inline std::int64_t int_of_handle(std::intptr_t a)
{   return (static_cast<std::int64_t>(a) & ~static_cast<std::int64_t>
            (1))/2;
}

// This function should only ever be called in situations where the
// arithmetic indicated will not overflow.

inline std::intptr_t int_to_handle(std::int64_t n)
{   return static_cast<std::intptr_t>(2*n + 1);
}

// The following two lines are slighly delicate in that INTPTR_MIN and _MAX
// may not have the low tag bits to be proper fixnums. But if I implement
// int_of_handle so that it ignores tag bits that will be OK.

INLINE_VAR const std::int64_t MIN_FIXNUM = int_of_handle(INTPTR_MIN);
INLINE_VAR const std::int64_t MAX_FIXNUM = int_of_handle(INTPTR_MAX);

inline bool fits_into_fixnum(std::int64_t a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t *p)
{   freechains::get().abandon(&p[-1]);
}

inline void abandon(std::intptr_t p)
{   if (!stored_as_fixnum(p) && p!=0)
    {   std::uint64_t *pp = vector_of_handle(p);
        freechains::get().abandon(&pp[-1]);
    }
}

inline char *reserve_string(std::size_t n)
{   return new char[n+1];
}

inline char *confirm_size_string(char *p, std::size_t n,
                                 std::size_t final)
{   arithlib_assert(final>0 && (n+9)>final);
    p[final] = 0;
    return p;
}

inline void abandon_string(char *s)
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
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1));
    else return OP::op(vector_of_handle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::int64_t n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t *n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (stored_as_fixnum(a1))
    {   if (stored_as_fixnum(a2))
            return OP::op(int_of_handle(a1), int_of_handle(a2));
        else return OP::op(int_of_handle(a1), vector_of_handle(a2));
    }
    else
    {   if (stored_as_fixnum(a2))
            return OP::op(vector_of_handle(a1), int_of_handle(a2));
        else return OP::op(vector_of_handle(a1), vector_of_handle(a2));
    }
}

inline std::intptr_t always_copy_bignum(std::uint64_t *p)
{   std::size_t n = reinterpret_cast<std::uint32_t *>(&p[-1])[1];
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::uint64_t *p)
{   std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::intptr_t pp)
{   if (stored_as_fixnum(pp)) return pp;
    std::uint64_t *p = vector_of_handle(pp);
    std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

#elif defined LISP

//=========================================================================
//=========================================================================
// The LISP code is for incorporation in VSL or CSL or Zappa
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

inline std::uint64_t *reserve(std::size_t n)
{   arithlib_assert(n>0);
// During a transition period I will use TYPE_NEW_BIGNUM rather than
// TYPE_BIGNUM.
    LispObject a = get_basic_vector(TAG_NUMBERS, TYPE_NEW_BIGNUM,
                                    n*sizeof(std::uint64_t)+8);
    return reinterpret_cast<std::uint64_t *>(a + 8 - TAG_NUMBERS);
}

inline std::intptr_t confirm_size(std::uint64_t *p, std::size_t n,
                                  std::size_t final)
{   arithlib_assert(final>0 && n>=final);
    if (final == 1 && fits_into_fixnum(static_cast<std::int64_t>(p[0])))
    {   std::intptr_t r = int_to_handle(static_cast<std::int64_t>(p[0]));
        return r;
    }
// Note that pack_hdrlength() takes its argument measured in units of
// 32-bit words. That is because the way the length field is packed into
// an object header supported just that resolution (and special treatment is
// given to halfword, byte and bit-vectors to allow for their finer grain).
// The length also includes the size of a header-word, and on 32-bit platforms
// it has to allow for padding the data to allow the array of 64-bit digits
// to be properly aligned in memory.
    ((LispObject *)&p[-1])[0] =
        TAG_HDR_IMMED + TYPE_NEW_BIGNUM +
        pack_hdrlength((final+1)*sizeof(std::uint64_t)/sizeof(std::int32_t));
// If I am on a 32-bit system the data for a bignum is 8 bit aligned and
// that leaves a 4-byte gap after the header. In such a case I will write
// in a zero just to keep memory tidy.
    if (sizeof(LispObject) == 4)
        ((LispObject *)&p[-1])[1] = 0;
// Here I should reset fringe down by (final-n) perhaps. Think about that
// later!
    return vector_to_handle(p);
}

inline std::intptr_t confirm_size_x(std::uint64_t *p, std::size_t n,
                                    std::size_t final)
{   arithlib_assert(final>0 && n>=final);
// Here I might need to write a nice dummy object into the gap left by
// shrinking the object.
    return confirm_size(p, n, final);
}

inline std::intptr_t vector_to_handle(std::uint64_t *p)
{   return reinterpret_cast<std::intptr_t>(p) - 8 + TAG_NUMBERS;
}

inline std::uint64_t *vector_of_handle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t *>(n + 8 - TAG_NUMBERS);
}

inline std::size_t number_size(std::uint64_t *p)
{
// The odd looking cast here is because in arithlib I am passing around
// arrays of explicitly 64-bit values, however in the underlying Lisp
// I expect to be modelling memory as made up of intptr-sized items
// that I arrange to have aligned on 8-byte boundaries. So to show some
// though about strict aliasing and the like I will access memory as
// an array of LispObject things when I access the header of an item.
    Header h = (Header)*(LispObject *)&p[-1];
    std::size_t r = length_of_header(h);
// On 32-bit systems a bignum will have a wasted 32-bit word after the
// header and before the digits, so that the digits are properly aligned
// in memory. The result will be that the bignum is laid out as follows
//      |     hdr64     | digit64 | digit64 | ... |    (64-bit world)
//      | hdr32 | gap32 | digit64 | digit64 | ... |    (32-bit world)
// The length value packed into the header is the length of the vector
// including its header.
    r = (r-8)/sizeof(std::uint64_t);
    arithlib_assert(r>0);
    return r;
}

inline bool stored_as_fixnum(std::intptr_t a)
{   return is_fixnum(a);
}

constexpr inline std::int64_t int_of_handle(std::intptr_t a)
{   return int_of_fixnum(a);
}

inline std::intptr_t int_to_handle(std::int64_t n)
{   return fixnum_of_int(n);
}

INLINE_VAR const std::int64_t MIN_FIXNUM = int_of_handle(INTPTR_MIN);
INLINE_VAR const std::int64_t MAX_FIXNUM = int_of_handle(INTPTR_MAX);

inline bool fits_into_fixnum(std::int64_t a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t *p)
{   // No need to do anything! But MIGHT reset fringe pointer?
}

inline void abandon(std::intptr_t p)
{   if (!stored_as_fixnum(p) && p!=0)
    {   std::uint64_t *pp = vector_of_handle(p);
        abandon(pp);
    }
}

inline char *reserve_string(std::size_t n)
{   LispObject a = get_basic_vector(TAG_VECTOR, TYPE_STRING_4,
                                    CELL+n);
    return reinterpret_cast<char *>(a - TAG_VECTOR + sizeof(LispObject));
}

inline LispObject confirm_size_string(char *p, std::size_t n,
                                      std::size_t final)
{   LispObject *a = (LispObject *)(p - sizeof(LispObject));
    *a = TAG_HDR_IMMED + TYPE_STRING_4 + (final<<(Tw+5));
    return (LispObject)a + TAG_VECTOR;
}

inline void abandon_string(string_handle s)
{   // Do nothing.
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1));
    else return OP::op(vector_of_handle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::int64_t n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t *n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (stored_as_fixnum(a1))
    {   if (stored_as_fixnum(a2))
            return OP::op(int_of_handle(a1), int_of_handle(a2));
        else return OP::op(int_of_handle(a1), vector_of_handle(a2));
    }
    else
    {   if (stored_as_fixnum(a2))
            return OP::op(vector_of_handle(a1), int_of_handle(a2));
        else return OP::op(vector_of_handle(a1), vector_of_handle(a2));
    }
}

inline std::intptr_t always_copy_bignum(std::uint64_t *p)
{   std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::uint64_t *p)
{   std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::intptr_t pp)
{   if (stored_as_fixnum(pp)) return pp;
    std::uint64_t *p = vector_of_handle(pp);
    std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}


#elif defined ZAPPA // and end of CSL

// The code here can only make sense in the context of the Zappa sources,
// and it is assumed that all the relevant Zappa header files have already
// been #included.

inline std::uint64_t *reserve(std::size_t n)
{   arithlib_assert(n>0);
    std::uint64_t* a = binaryAllocate(n+1);
    *a = n;      // Record length of object in first word.
    return a+1;
}

inline std::intptr_t confirm_size(std::uint64_t *p, std::size_t n,
                                  std::size_t final)
{   arithlib_assert(final>0 && n>=final);
    if (final == 1 && fits_into_fixnum(static_cast<std::int64_t>(p[0])))
    {   std::intptr_t r = int_to_handle(static_cast<std::int64_t>(p[0]));
        return r;
    }
// I put the length of a bignum in stored as 2 times the number of words
// (not including the header word). This leaves valid headers even, and so
// odd values can be used for forwarding addresses.
    p[-1] = 2*final;
    return vector_to_handle(p);
}

inline std::intptr_t confirm_size_x(std::uint64_t *p, std::size_t n,
                                    std::size_t final)
{   arithlib_assert(final>0 && n>=final);
    return confirm_size(p, n, final);
}

inline std::intptr_t vector_to_handle(std::uint64_t *p)
{   return reinterpret_cast<std::intptr_t>(p) - 8 + BigInteger;
}

inline std::uint64_t *vector_of_handle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t *>(n + 8 - BigInteger);
}

inline std::size_t number_size(std::uint64_t *p)
{   std::uint64_t h = p[-1]/2;
    arithlib_assert(h>0);
    return h;
}

inline bool stored_as_fixnum(std::intptr_t a)
{   return (a & tagXMask) == SmallInteger;
}

constexpr inline std::int64_t int_of_handle(std::intptr_t a)
{   return static_cast<std::int64_t>(
               (a & ~static_cast<std::int64_t>(tagXMask)) /
               static_cast<std::int64_t>(valXMult));
}

inline std::intptr_t int_to_handle(std::int64_t n)
{   return static_cast<std::intptr_t>(n*valXMult + SmallInteger);
}

INLINE_VAR const std::int64_t MIN_FIXNUM = int_of_handle(INTPTR_MIN);
INLINE_VAR const std::int64_t MAX_FIXNUM = int_of_handle(INTPTR_MAX);

inline bool fits_into_fixnum(std::int64_t a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t *p)
{   // No need to do anything!
}

inline void abandon(std::intptr_t p)
{   // Also do not do anything!
}

inline char *reserve_string(std::size_t n)
{   std::uint64_t* a = binaryAllocate((8+n+7)/8);
    return reinterpret_cast<char *>(a) + 8;
}

// A string size is measured in bytes not words.
inline char* confirm_size_string(char *p, std::size_t n,
                                 std::size_t final)
{   p[final] = 0;
    reinterpret_cast<std::uint64_t*>(p)[-1] = 2*final;
    return p;
}

inline void abandon_string(string_handle s)
{   // Do nothing.
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1));
    else return OP::op(vector_of_handle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::int64_t n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t *n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (stored_as_fixnum(a1))
    {   if (stored_as_fixnum(a2))
            return OP::op(int_of_handle(a1), int_of_handle(a2));
        else return OP::op(int_of_handle(a1), vector_of_handle(a2));
    }
    else
    {   if (stored_as_fixnum(a2))
            return OP::op(vector_of_handle(a1), int_of_handle(a2));
        else return OP::op(vector_of_handle(a1), vector_of_handle(a2));
    }
}

inline std::intptr_t always_copy_bignum(std::uint64_t *p)
{   std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::uint64_t *p)
{   std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::intptr_t pp)
{   if (stored_as_fixnum(pp)) return pp;
    std::uint64_t *p = vector_of_handle(pp);
    std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}




#else // ZAPPA

inline std::uint64_t *reserve(std::size_t n)
{   arithlib_assert(n>0);
// I must allow for alignment padding on 32-bit platforms.
    if (sizeof(LispObject)==4) n = n*sizeof(std::uint64_t) + 4;
    else n = n*sizeof(std::uint64_t);
    LispObject a = allocateatom(n);
    return reinterpret_cast<std::uint64_t *>(a + 8 - tagATOM);
}

inline std::intptr_t confirm_size(std::uint64_t *p, std::size_t n,
                                  std::size_t final)
{   arithlib_assert(final>0 && n>=final);
    if (final == 1 && fits_into_fixnum(static_cast<std::int64_t>(p[0])))
    {   std::intptr_t r = int_to_handle(static_cast<std::int64_t>(p[0]));
        return r;
    }
    ((LispObject *)&p[-1])[0] =
        tagHDR + typeBIGNUM + packlength(final*sizeof(std::uint64_t) +
                                         (sizeof(LispObject)==4 ? 4 : 0));
// If I am on a 32-bit system the data for a bignum is 8 bit aligned and
// that leaves a 4-byte gap after the header. In such a case I will write
// in a zero just to keep memory tidy.
    if (sizeof(LispObject) == 4)
        ((LispObject *)&p[-1])[1] = 0;
// Here I should reset fringe down by (final-n) perhaps. Think about that
// later!
    return vector_to_handle(p);
}

inline std::intptr_t confirm_size_x(std::uint64_t *p, std::size_t n,
                                    std::size_t final)
{   arithlib_assert(final>0 && n>=final);
// Here I might need to write a nice dummy object into the gap left by
// shrinking the object.
    return confirm_size(p, n, final);
}

inline std::intptr_t vector_to_handle(std::uint64_t *p)
{   return reinterpret_cast<std::intptr_t>(p) - 8 + tagATOM;
}

inline std::uint64_t *vector_of_handle(std::intptr_t n)
{   return reinterpret_cast<std::uint64_t *>(n + 8 - tagATOM);
}

inline std::size_t number_size(std::uint64_t *p)
{
// The odd looking cast here is because in arithlib I am passing around
// arrays of explicitly 64-bit values, however in the underlying Lisp
// I expect to be modelling memory as made up of intptr-sized items
// that I arrange to have aligned on 8-byte boundaries. So to show some
// though about strict aliasing and the like I will access memory as
// an array of LispObject things when I access the header of an item.
    std::uintptr_t h = reinterpret_cast<std::uintptr_t>()*
                       (LispObject *)&p[-1];
    std::size_t r = veclength(h);
// On 32-bit systems a bignum will have a wasted 32-bit word after the
// header and before the digits, so that the digits are properly aligned
// in memory. The result will be that the bignum is laid out as follows
//      |     hdr64     | digit64 | digit64 | ... |    (64-bit world)
//      | hdr32 | gap32 | digit64 | digit64 | ... |    (32-bit world)
// The length value packed into the header is the length of the vector
// excluding its header.
//  if (sizeof(LispObject) == 4) r -= 4; { the remaindering does all I need! }
    r = r/sizeof(std::uint64_t);
    arithlib_assert(r>0);
    return r;
}

inline bool stored_as_fixnum(std::intptr_t a)
{   return isFIXNUM(a);
}

constexpr inline std::int64_t int_of_handle(std::intptr_t a)
{   return qfixnum(a);
}

inline std::intptr_t int_to_handle(std::int64_t n)
{   return packfixnum(n);
}

inline bool fits_into_fixnum(std::int64_t a)
{   return a>=MIN_FIXNUM && a<=MAX_FIXNUM;
}

inline void abandon(std::uint64_t *p)
{   // No need to do anything! But MIGHT reset fringe pointer?
}

inline void abandon(std::intptr_t p)
{   if (!stored_as_fixnum(p) && p!=0)
    {   std::uint64_t *pp = vector_of_handle(p);
        abandon(pp);
    }
}

inline char *reserve_string(std::size_t n)
{   LispObject a = allocateatom(n);
    return reinterpret_cast<char *>(a - tagATOM + sizeof(LispObject));
}

inline LispObject confirm_size_string(char *p, std::size_t n,
                                      std::size_t final)
{   LispObject *a = (LispObject *)(p - sizeof(LispObject));
// On 32-bit platforms I do not have a padder word before string data
// so things are simpler here than when confirming the size of a number.
    *a = tagHDR + typeSTRING + packlength(final);
    return (LispObject)a +tagATOM;
}

inline void abandon_string(string_handle s)
{   // Do nothing.
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1));
    else return OP::op(vector_of_handle(a1));
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::int64_t n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch1(std::intptr_t a1, std::uint64_t *n)
{   if (stored_as_fixnum(a1)) return OP::op(int_of_handle(a1), n);
    else return OP::op(vector_of_handle(a1), n);
}

template <class OP,class RES>
inline RES op_dispatch2(std::intptr_t a1, std::intptr_t a2)
{   if (stored_as_fixnum(a1))
    {   if (stored_as_fixnum(a2))
            return OP::op(int_of_handle(a1), int_of_handle(a2));
        else return OP::op(int_of_handle(a1), vector_of_handle(a2));
    }
    else
    {   if (stored_as_fixnum(a2))
            return OP::op(vector_of_handle(a1), int_of_handle(a2));
        else return OP::op(vector_of_handle(a1), vector_of_handle(a2));
    }
}

inline std::intptr_t always_copy_bignum(std::uint64_t *p)
{   std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::uint64_t *p)
{   std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

inline std::intptr_t copy_if_no_garbage_collector(std::intptr_t pp)
{   if (stored_as_fixnum(pp)) return pp;
    std::uint64_t *p = vector_of_handle(pp);
    std::size_t n = number_size(p);
    push(p);
    std::uint64_t *r = reserve(n);
    pop(p);
    std::memcpy(r, p, n*sizeof(std::uint64_t));
    return confirm_size(r, n, n);
}

#endif // !CSL

#else // none if MALLOC, LISP or NEW specified.
#error Unspecified memory model
#endif

// The main arithmetic operations are supported by code that can work on
// Bignums stored as vectors of digits or on Fixnums represented as (tagged)
// immediate data, or as mixtures. For each operation there is a class, and
// methods called "op" within it deal with the various cases via overloading.

class Plus
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

inline std::intptr_t bigplus_small(std::intptr_t, std::int64_t);

class Difference
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class RevDifference
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Times
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Quotient
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Remainder
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Divide
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
    static std::intptr_t op(std::int64_t, std::int64_t, std::intptr_t &);
    static std::intptr_t op(std::int64_t, std::uint64_t *,
                            std::intptr_t &);
    static std::intptr_t op(std::uint64_t *, std::int64_t,
                            std::intptr_t &);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *,
                            std::intptr_t &);
};

class Gcd
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Lcm
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Logand
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Logor
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Logxor
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Logeqv
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class Zerop
{
public:
    static bool op(std::int64_t w);
    static bool op(std::uint64_t *w);
};

class Onep
{
public:
    static bool op(std::int64_t w);
    static bool op(uint64_t *w);
};

class Minusp
{
public:
    static bool op(std::int64_t w);
    static bool op(uint64_t *w);
};

class Evenp
{
public:
    static bool op(std::int64_t w);
    static bool op(uint64_t *w);
};

class Oddp
{
public:
    static bool op(std::int64_t w);
    static bool op(uint64_t *w);
};

class Eqn
{
public:
    static bool op(std::int64_t, std::int64_t);
    static bool op(std::int64_t, std::uint64_t *);
    static bool op(std::uint64_t *, std::int64_t);
    static bool op(std::uint64_t *, std::uint64_t *);
// Even comparing a floating point number with an integer for equality
// turns out to be messier than one might have hoped!
    static bool op(std::int64_t, float);
    static bool op(std::uint64_t *, float);
    static bool op(float, std::int64_t);
    static bool op(float, std::uint64_t *);
    static bool op(std::int64_t, double);
    static bool op(std::uint64_t *, double);
    static bool op(double, std::int64_t);
    static bool op(double, std::uint64_t *);
#ifdef softfloat_h
    static bool op(std::int64_t, float128_t);
    static bool op(std::uint64_t *, float128_t);
    static bool op(float128_t, std::int64_t);
    static bool op(float128_t, std::uint64_t *);
#endif // softfloat_h
};

class Neqn
{
public:
    static bool op(std::int64_t, std::int64_t);
    static bool op(std::int64_t, std::uint64_t *);
    static bool op(std::uint64_t *, std::int64_t);
    static bool op(std::uint64_t *, std::uint64_t *);
// Even comparing a floating point number with an integer for equality
// turns out to be messier than one might have hoped!
    static bool op(std::int64_t, float);
    static bool op(std::uint64_t *, float);
    static bool op(float, std::int64_t);
    static bool op(float, std::uint64_t *);
    static bool op(std::int64_t, double);
    static bool op(std::uint64_t *, double);
    static bool op(double, std::int64_t);
    static bool op(double, std::uint64_t *);
#ifdef softfloat_h
    static bool op(std::int64_t, float128_t);
    static bool op(std::uint64_t *, float128_t);
    static bool op(float128_t, std::int64_t);
    static bool op(float128_t, std::uint64_t *);
#endif // softfloat_h
};

class Geq
{
public:
    static bool op(std::int64_t, std::int64_t);
    static bool op(std::int64_t, std::uint64_t *);
    static bool op(std::uint64_t *, std::int64_t);
    static bool op(std::uint64_t *, std::uint64_t *);
// Comparing a bignum against a floating point value has multiple cases
// to consider, but needs special implementation so that neither rounding
// nor overflow not Infinities/NaNs lead to incorrect results.
    static bool op(std::int64_t, float);
    static bool op(std::uint64_t *, float);
    static bool op(float, std::int64_t);
    static bool op(float, std::uint64_t *);
    static bool op(std::int64_t, double);
    static bool op(std::uint64_t *, double);
    static bool op(double, std::int64_t);
    static bool op(double, std::uint64_t *);
#ifdef softfloat_h
    static bool op(std::int64_t, float128_t);
    static bool op(std::uint64_t *, float128_t);
    static bool op(float128_t, std::int64_t);
    static bool op(float128_t, std::uint64_t *);
#endif // softfloat_h
};

class Greaterp
{
public:
    static bool op(std::int64_t, std::int64_t);
    static bool op(std::int64_t, std::uint64_t *);
    static bool op(std::uint64_t *, std::int64_t);
    static bool op(std::uint64_t *, std::uint64_t *);
    static bool op(std::int64_t, float);
    static bool op(std::uint64_t *, float);
    static bool op(float, std::int64_t);
    static bool op(float, std::uint64_t *);
    static bool op(std::int64_t, double);
    static bool op(std::uint64_t *, double);
    static bool op(double, std::int64_t);
    static bool op(double, std::uint64_t *);
#ifdef softfloat_h
    static bool op(std::int64_t, float128_t);
    static bool op(std::uint64_t *, float128_t);
    static bool op(float128_t, std::int64_t);
    static bool op(float128_t, std::uint64_t *);
#endif // softfloat_h
};

class Leq
{
public:
    static bool op(std::int64_t, std::int64_t);
    static bool op(std::int64_t, std::uint64_t *);
    static bool op(std::uint64_t *, std::int64_t);
    static bool op(std::uint64_t *, std::uint64_t *);
    static bool op(std::int64_t, float);
    static bool op(std::uint64_t *, float);
    static bool op(float, std::int64_t);
    static bool op(float, std::uint64_t *);
    static bool op(std::int64_t, double);
    static bool op(std::uint64_t *, double);
    static bool op(double, std::int64_t);
    static bool op(double, std::uint64_t *);
#ifdef softfloat_h
    static bool op(std::int64_t, float128_t);
    static bool op(std::uint64_t *, float128_t);
    static bool op(float128_t, std::int64_t);
    static bool op(float128_t, std::uint64_t *);
#endif // softfloat_h
};

class Lessp
{
public:
    static bool op(std::int64_t, std::int64_t);
    static bool op(std::int64_t, std::uint64_t *);
    static bool op(std::uint64_t *, std::int64_t);
    static bool op(std::uint64_t *, std::uint64_t *);
    static bool op(std::int64_t, float);
    static bool op(std::uint64_t *, float);
    static bool op(float, std::int64_t);
    static bool op(float, std::uint64_t *);
    static bool op(std::int64_t, double);
    static bool op(std::uint64_t *, double);
    static bool op(double, std::int64_t);
    static bool op(double, std::uint64_t *);
#ifdef softfloat_h
    static bool op(std::int64_t, float128_t);
    static bool op(std::uint64_t *, float128_t);
    static bool op(float128_t, std::int64_t);
    static bool op(float128_t, std::uint64_t *);
#endif // softfloat_h
};

class Add1
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class Sub1
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class Minus
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class Abs
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class Square
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class Isqrt
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class Lognot
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class Pow
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
    static double op(std::int64_t, double);
    static double op(std::uint64_t *, double);
};

class LeftShift
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class RightShift
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class IntegerLength
{
public:
    static std::size_t op(std::int64_t w);
    static std::size_t op(uint64_t *w);
};

class Low_bit
{
public:
    static std::size_t op(std::int64_t w);
    static std::size_t op(uint64_t *w);
};

class Logbitp
{
public:
    static bool op(std::int64_t, std::size_t);
    static bool op(std::uint64_t *, std::size_t);
};

class Logcount
{
public:
    static std::size_t op(std::int64_t w);
    static std::size_t op(uint64_t *w);
};

class Int64_t
{
public:
    static std::int64_t op(std::int64_t w);
    static std::int64_t op(uint64_t *w);
};

class Uint64_t
{
public:
    static std::uint64_t op(std::int64_t w);
    static std::uint64_t op(uint64_t *w);
};

class Float
{
public:
    static float op(std::int64_t w);
    static float op(uint64_t *w);
};

class Double
{
public:
    static double op(std::int64_t w);
    static double op(uint64_t *w);
};

class Frexp
{
public:
    static double op(std::int64_t, std::int64_t &x);
    static double op(std::uint64_t *, std::int64_t &x);
};

#ifdef softfloat_h

class Float128
{
public:
    static float128_t op(std::int64_t w);
    static float128_t op(uint64_t *w);
};

class Frexp128
{
public:
    static float128_t op(std::int64_t, std::int64_t &x);
    static float128_t op(std::uint64_t *, std::int64_t &x);
};

#endif // softfloat_h

#ifdef CSL

class ModularPlus
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class ModularDifference
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class ModularTimes
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class ModularExpt
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class ModularQuotient
{
public:
    static std::intptr_t op(std::int64_t, std::int64_t);
    static std::intptr_t op(std::int64_t, std::uint64_t *);
    static std::intptr_t op(std::uint64_t *, std::int64_t);
    static std::intptr_t op(std::uint64_t *, std::uint64_t *);
};

class ModularMinus
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class ModularReciprocal
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class ModularNumber
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

class SetModulus
{
public:
    static std::intptr_t op(std::int64_t w);
    static std::intptr_t op(uint64_t *w);
};

#endif // CSL

inline string_handle bignum_to_string(std::intptr_t aa);
inline string_handle bignum_to_string_hex(std::intptr_t aa);
inline string_handle bignum_to_string_octal(std::intptr_t aa);
inline string_handle bignum_to_string_binary(std::intptr_t aa);

class Bignum;

inline void display(const char *label, const std::uint64_t *a,
                    std::size_t lena);
inline void display(const char *label, std::intptr_t a);
inline void display(const char *label, const Bignum &a);


//=========================================================================
//=========================================================================
// I have a class Bignum that wraps up the representation of a number
// and then allows me to overload most operators so that big numbers can be
// used in C++ code anmost as if they were a natural proper type. The main
// big oddity will be that to denote a Bignum literal it will be necessary
// to use a constructor, with obvious constructors accepting integers of up
// to 64-bits and a perhaps less obvious one taking a string that is the
// decimal denotation of the integer concerned.
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
    Bignum(std::uint64_t *p)
    {   val = vector_to_handle(p);
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
    {   val = int_to_bignum(static_cast<std::int64_t>(n));
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
              typename std::enable_if<std::is_unsigned<T>::value>::type* = nullptr>
    Bignum(T n)
    {   val = unsigned_int_to_bignum(static_cast<std::uint64_t>(n));
    }
    Bignum(float d)
    {   val = round_double_to_int(static_cast<double>(d));
    }
    Bignum(double d)
    {   val = round_double_to_int(d);
    }
#ifdef softfloat_h
    Bignum(float128_t d)
    {   val = round_float128_to_int(d);
    }
#endif // softfloat_h
    Bignum(const char *s)
    {   val = string_to_bignum(s);
    }
    Bignum(const Bignum &a)
    {   val = copy_if_no_garbage_collector(a.val);
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
              typename std::enable_if<std::is_signed<T>::value>::type* = nullptr>
    operator T()
    {   return static_cast<T>(op_dispatch1<Int64_t, std::int64_t>(val));
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
              typename std::enable_if<std::is_unsigned<T>::value>::type* = nullptr>
    operator T()
    {   return static_cast<T>(op_dispatch1<Uint64_t, std::uint64_t>(val));
    }
    operator double()
    {   return op_dispatch1<Double, double>(val);
    }
    std::uint64_t *vec() const
    {   return vector_of_handle(val);
    }

// In a way that is BAD I make the result of an assignment void rather than
// the value that is assigned. This is so I do not make gratuitous extra
// copies of it in the common case where the value is not used, but it could
// catch out the unwary.
    inline void operator = (const Bignum &x)
    {   if (this == &x) return; // assign to self - a silly case!
        abandon(val);
// See comment in the copy constructor.
        val = copy_if_no_garbage_collector(x.val);
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
              typename std::enable_if<std::is_signed<T>::value>::type* = nullptr>
    inline void operator = (const T x)
    {   abandon(val);
        val = int_to_bignum(static_cast<std::int64_t>(x));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr,
              typename std::enable_if<std::is_unsigned<T>::value>::type* = nullptr>
    inline void operator = (const T x)
    {   abandon(val);
        val = unsigned_int_to_bignum(static_cast<std::uint64_t>(x));
    }

    inline void operator = (const char *x)
    {   abandon(val);
        val = string_to_bignum(x);
    }

    inline Bignum operator +(const Bignum &x) const
    {   return Bignum(true, op_dispatch2<Plus,std::intptr_t>(val, x.val));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator +(const T x) const
    {   return Bignum(true, op_dispatch2<Plus,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator -(const Bignum &x) const
    {   return Bignum(true, op_dispatch2<Difference,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator -(const T x) const
    {   return Bignum(true, op_dispatch2<Difference,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator *(const Bignum &x) const
    {   return Bignum(true, op_dispatch2<Times,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator *(const T x) const
    {   return Bignum(true, op_dispatch2<Times,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator /(const Bignum &x) const
    {   return Bignum(true, op_dispatch2<Quotient,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator /(const T x) const
    {   return Bignum(true, op_dispatch2<Quotient,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator %(const Bignum &x) const
    {   return Bignum(true, op_dispatch2<Remainder,std::intptr_t>(val,
                      x.val));
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

    inline Bignum operator &(const Bignum &x) const
    {   return Bignum(true, op_dispatch2<Logand,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator &(const T x) const
    {   return Bignum(true, op_dispatch2<Logand,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator |(const Bignum &x) const
    {   return Bignum(true, op_dispatch2<Logor,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator |(const T x) const
    {   return Bignum(true, op_dispatch2<Logor,std::intptr_t>(val,
                      Bignum(x).val));
    }

    inline Bignum operator ^(const Bignum &x) const
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
                      static_cast<std::int64_t>(n)));
    }

    inline Bignum operator <<(Bignum n) const
    {   return Bignum(true, op_dispatch1<LeftShift,std::intptr_t>(val,
                      static_cast<std::int64_t>(n)));
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline Bignum operator >>(T n) const
    {   return Bignum(true, op_dispatch1<RightShift,std::intptr_t>(val,
                      static_cast<std::int64_t>(n)));
    }

    inline Bignum operator >>(Bignum n) const
    {   return Bignum(true, op_dispatch1<RightShift,std::intptr_t>(val,
                      static_cast<std::int64_t>(n)));
    }

    inline Bignum operator ~() const
    {   return Bignum(true, op_dispatch1<Lognot,std::intptr_t>(val));
    }

    inline bool operator ==(const Bignum &x) const
    {   return op_dispatch2<Eqn,bool>(val, x.val);
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator ==(const T x) const
    {   return op_dispatch2<Eqn,bool>(val, Bignum(x).val);
    }

    inline bool operator !=(const Bignum &x) const
    {   return !op_dispatch2<Eqn,bool>(val, x.val);
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator !=(const T x) const
    {   return !op_dispatch2<Eqn,bool>(val, Bignum(x).val);
    }

    inline bool operator >(const Bignum &x) const
    {   return op_dispatch2<Greaterp,bool>(val, x.val);
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator >(const T x) const
    {   return op_dispatch2<Greaterp,bool>(val, Bignum(x).val);
    }

    inline bool operator >=(const Bignum &x) const
    {   return op_dispatch2<Geq,bool>(val, x.val);
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator >=(const T x) const
    {   return op_dispatch2<Geq,bool>(val, Bignum(x).val);
    }

    inline bool operator <(const Bignum &x) const
    {   return op_dispatch2<Lessp,bool>(val, x.val);
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator <(const T x) const
    {   return op_dispatch2<Lessp,bool>(val, Bignum(x).val);
    }

    inline bool operator <=(const Bignum &x) const
    {   return op_dispatch2<Leq,bool>(val, x.val);
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline bool operator <=(const T x) const
    {   return op_dispatch2<Leq,bool>(val, Bignum(x).val);
    }

    inline void operator +=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Plus,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator +=(T x)
    {   std::intptr_t r = op_dispatch2<Plus,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator -=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Difference,std::intptr_t>(val,
                          x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator -=(T x)
    {   std::intptr_t r = op_dispatch2<Difference,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator *=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Times,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator *=(T x)
    {   std::intptr_t r = op_dispatch2<Times,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }


    inline void operator /=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Quotient,std::intptr_t>(val,
                          x.val);
        abandon(val);
        val = r;
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator /=(T x)
    {   std::intptr_t r = op_dispatch2<Quotient,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }


    inline void operator %=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Remainder,std::intptr_t>(val,
                          x.val);
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

    inline void operator &=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Logand,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }
    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator &=(T x)
    {   std::intptr_t r = op_dispatch2<Logand,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator |=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Logor,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator |=(T x)
    {   std::intptr_t r = op_dispatch2<Logor,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }

    inline void operator ^=(const Bignum &x)
    {   std::intptr_t r = op_dispatch2<Logxor,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator ^=(T x)
    {   std::intptr_t r = op_dispatch2<Logxor,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator <<=(T n)
    {   std::intptr_t r = op_dispatch1<LeftShift,std::intptr_t>(val,
                          static_cast<std::int64_t>(n));
        abandon(val);
        val = r;
    }

    template <typename T,
              typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    inline void operator >>=(T n)
    {   std::intptr_t r = op_dispatch1<RightShift,std::intptr_t>(val,
                          static_cast<std::int64_t>(n));
        abandon(val);
        val = r;
    }

    inline Bignum operator ++()
    {   std::intptr_t r = bigplus_small(val, 1);
        abandon(val);
        val = r;
        return *this;
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
        return *this;
    }

    inline Bignum operator --(int)
    {   std::intptr_t r = bigplus_small(val, -1);
        Bignum oldval;
        oldval.val = val;
        val = r;
        return oldval;
    }

    friend std::ostream & operator << (std::ostream &out, const Bignum &a)
    {   std::ios_base::fmtflags fg = out.flags();
#if defined LISP && !defined ZAPPA
        LispObject s;
#else
        char *s;
#endif
        if ((static_cast<unsigned int>(fg) & std::ios_base::hex) != 0U)
            s = bignum_to_string_hex(a.val);
        else if ((static_cast<unsigned int>(fg) & std::ios_base::oct) != 0U)
            s = bignum_to_string_octal(a.val);
        else if ((static_cast<unsigned int>(fg) & std::ios_base::dec) != 0U)
            s = bignum_to_string(a.val);
        else if (radix::is_binary_output(out))
            s = bignum_to_string_binary(a.val);
        else s = bignum_to_string(a.val);
#if defined LISP && !defined ZAPPA
        std::string ss(s, length_of_byteheader(qheader(s)));
        out << ss;
#else
        out << s;
#endif
        abandon_string(s);
        return out;
    }
    friend std::istream & operator >> (std::istream &in, Bignum &a)
    {   std::int64_t n;
// What I really want to do is to read in a string of digits and then
// use string_to_bignum().
        in >> n;
        abandon(a.val);
        a.val = int_to_bignum(n);
        return in;
    }
};

// I use a suffix "_Z" for bignums, with Z chosen to reminding me that this
// gives me an Integer, the "Z" (typically written in a blackboard font)
// standing for the ring of integers.
inline Bignum operator "" _Z(const char *s)
{   return Bignum(s);
}

inline const string_handle to_string(Bignum x)
{   return bignum_to_string(x.val);
}

inline Bignum uniform_positive_bignum(std::size_t n)
{   return Bignum(true, uniform_positive(n));
}

inline Bignum uniform_signed_bignum(std::size_t n)
{   return Bignum(true, uniform_signed(n));
}

inline Bignum uniform_upto_bignum(Bignum a)
{   return Bignum(true, uniform_upto(a.val));
}

inline Bignum fudge_distribution_bignum(Bignum a, int n)
{   return Bignum(true, fudge_distribution(a.val, n));
}

inline Bignum random_upto_bits_bignum(std::size_t n)
{   return Bignum(true, random_upto_bits(n));
}

inline Bignum square(const Bignum &x)
{   return Bignum(true, op_dispatch1<Square,std::intptr_t>(x.val));
}

inline Bignum isqrt(const Bignum &x)
{   return Bignum(true, op_dispatch1<Isqrt,std::intptr_t>(x.val));
}

inline Bignum abs(const Bignum &x)
{   return Bignum(true, op_dispatch1<Abs,std::intptr_t>(x.val));
}

inline bool zerop(const Bignum &x)
{   return op_dispatch1<Zerop,bool>(x.val);
}

inline bool onep(const Bignum &x)
{   return op_dispatch1<Onep,bool>(x.val);
}

inline bool minusp(const Bignum &x)
{   return op_dispatch1<Minusp,bool>(x.val);
}

inline bool evenp(const Bignum &x)
{   return op_dispatch1<Evenp,bool>(x.val);
}

inline bool oddp(const Bignum &x)
{   return op_dispatch1<Oddp,bool>(x.val);
}
template <typename T,
          typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
inline Bignum pow(const Bignum &x, T n)
{   if (n == 0) return Bignum(true, int_to_bignum(1));
    else if (n == 1) return Bignum(true,
                                       copy_if_no_garbage_collector(x.val));
    else if (n == 2) return square(x);
    else return Bignum(true,
                           op_dispatch1<Pow,std::intptr_t>(x.val, static_cast<std::int64_t>(n)));
}

inline double double_bignum(const Bignum &x);

inline double pow(const Bignum &x, double n)
{   return std::pow(double_bignum(x), n);
}

inline Bignum gcd(const Bignum &x, const Bignum &y)
{   return Bignum(true, op_dispatch2<Gcd,std::intptr_t>(x.val,
                  y.val));
}

inline Bignum lcm(const Bignum &x, const Bignum &y)
{   return Bignum(true, op_dispatch2<Lcm,std::intptr_t>(x.val,
                  y.val));
}

inline Bignum fix_bignum(double d)
{   return Bignum(true, trunc_double_to_int(d));
}

inline Bignum round_bignum(double d)
{   return Bignum(true, round_double_to_int(d));
}

inline Bignum trunc_bignum(double d)
{   return Bignum(true, trunc_double_to_int(d));
}

inline Bignum floor_bignum(double d)
{   return Bignum(true, floor_double_to_int(d));
}

inline Bignum ceil_bignum(double d)
{   return Bignum(true, ceiling_double_to_int(d));
}

inline Bignum fix_bignum(float d)
{   return fix_bignum(static_cast<double>(d));
}

inline Bignum round_bignum(float d)
{   return round_bignum(static_cast<double>(d));
}

inline Bignum trunc_bignum(float d)
{   return trunc_bignum(static_cast<double>(d));
}

inline Bignum floor_bignum(float d)
{   return floor_bignum(static_cast<double>(d));
}

inline Bignum ceil_bignum(float d)
{   return ceil_bignum(static_cast<double>(d));
}

inline double float_bignum(const Bignum &x)
{   return op_dispatch1<Float,float>(x.val);
}

inline double double_bignum(const Bignum &x)
{   return op_dispatch1<Double,double>(x.val);
}

// This will return a normalized double and an integer exponent.
// It can be better than using frexp(double_bignum(x), ..) because it
// avoids overflow.

inline double frexp_bignum(const Bignum &x, std::int64_t &xx)
{   return op_dispatch1<Frexp,double>(x.val, xx);
}

#ifdef softfloat_h

inline float128_t frexp128_bignum(const Bignum &x, std::int64_t &xx)
{   return op_dispatch1<Frexp128,float128_t>(x.val, xx);
}

inline float128_t float128_bignum(const Bignum &x)
{   return op_dispatch1<Float128,float128_t>(x.val);
}

#endif // softfloat_h

//=========================================================================
// display() will show the internal representation of a bignum as a
// sequence of hex values. This is obviously useful while debugging!
//=========================================================================

inline void display(const char *label, const std::uint64_t *a,
                    std::size_t lena)
{   std::cout << label << " [" << static_cast<int>(lena) << "]";
    for (std::size_t i=0; i<lena; i++)
    {   if (i!=0 && i%3==0) std::cout << std::endl << "     ";
        std::cout << " "
                  << std::hex << std::setfill('0')
                  << "0x" << std::setw(16) << a[lena-i-1]
                  << std::dec << std::setfill(' ');
    }
    std::cout << std::endl;
}

// "rdisplay" is for generating trace output for use with Reduce.
// The format is    name := 0xDDDDDDD$
// which will be easy to copy and paste into Reduce.

inline void rdisplay(const char *label, const std::uint64_t *a,
                     std::size_t lena)
{   std::cout << label << " := 0x";
    for (std::size_t i=0; i<lena; i++)
    {   std::cout << std::hex << std::setfill('0')
                  << std::setw(16) << a[lena-i-1]
                  << std::dec << std::setfill(' ');
    }
    std::cout << "$" << std::endl;
}

// I provide a function that accesses (b<<shift)[n]. Note that the
// valid index values n will from from 0 up to and including lenb.

inline std::uint64_t shifted_digit(std::uint64_t *b, std::size_t lenb,
                                   int shift, std::size_t n)
{   if (n == 0) return b[0]<<shift;
    else if (n == lenb) return b[lenb-1]>>(64-shift);
    else return (b[n]<<shift) | (b[n-1]>>(64-shift));
}

inline void display(const char *label, std::uint64_t *a,
                    std::size_t lena,
                    int shift)
{   std::cout << label << " [" << static_cast<int>(lena) << "]";
    for (std::size_t i=0; i<=lena; i++)
    {   if (i!=0 && i%3==0) std::cout << std::endl << "     ";
        std::cout << " "
                  << std::hex << std::setfill('0')
                  << "0x" << std::setw(16)
                  << shifted_digit(a, lena, shift, lena-i)
                  << std::dec << std::setfill(' ');
    }
    std::cout << std::endl;
}

inline void display(const char *label, std::intptr_t a)
{   if (stored_as_fixnum(a))
    {   std::cout << label << " [fixnum] " << std::hex
                  << "0x" << a << std::dec << " = "
                  << int_of_handle(a) << std::endl;
        return;
    }
    std::uint64_t *d = vector_of_handle(a);
    std::size_t len = number_size(d);
    std::cout << label << " [" << static_cast<int>(len) << "]";
    for (std::size_t i=0; i<len; i++)
        std::cout << " "
                  << std::hex << std::setfill('0')
                  << "0x" << std::setw(16) << d[len-i-1]
                  << std::dec << std::setfill(' ');
    std::cout << std::endl;
}

inline void display(const char *label, const Bignum &a)
{   display(label, a.val);
}


//=========================================================================
//=========================================================================
// I will have a collection of low level functions that support the
// fundamental operations needed for implementing big-number arithmetic:
// add-with-carry, multiplication and division.
//=========================================================================
//=========================================================================

#ifdef __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too. This must NEVER be called
// with a zero argument.

// Count the leading zeros in a 64-bit word.

inline int nlz(std::uint64_t x)
{   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
}

inline int popcount(std::uint64_t x)
{   return __builtin_popcountll(x);
}

#else // __GNUC__

inline int nlz(std::uint64_t x)
{   int n = 0;
    if (x <= 0x00000000FFFFFFFFU)
    {   n = n +32;
        x = x <<32;
    }
    if (x <= 0x0000FFFFFFFFFFFFU)
    {   n = n +16;
        x = x <<16;
    }
    if (x <= 0x00FFFFFFFFFFFFFFU)
    {   n = n + 8;
        x = x << 8;
    }
    if (x <= 0x0FFFFFFFFFFFFFFFU)
    {   n = n + 4;
        x = x << 4;
    }
    if (x <= 0x3FFFFFFFFFFFFFFFU)
    {   n = n + 2;
        x = x << 2;
    }
    if (x <= 0x7FFFFFFFFFFFFFFFU)
    {   n = n + 1;
    }
    return n;
}

inline int popcount(std::uint64_t x)
{   x = (x & 0x5555555555555555U) + (x >> 1 & 0x5555555555555555U);
    x = (x & 0x3333333333333333U) + (x >> 2 & 0x3333333333333333U);
    x = x + (x >> 4) & 0x0f0f0f0f0f0f0f0fU;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32) & 0x7f;
}

#endif // __GNUC__

// Round a size_t integer up to the next higher power of 2.
// I do this based on counting the number of leading zeros in the
// binary representation of n-1.

inline std::size_t next_power_of_2(std::size_t n)
{   return (static_cast<std::size_t>(1)) << (64-nlz(
                static_cast<std::uint64_t>(n-1)));
}

inline unsigned int log_next_power_of_2(std::size_t n)
{   return (64-nlz(static_cast<std::uint64_t>(n-1)));
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

// I have an overload of add_with_carry for use where it is known that
// the input carry is zero. That cases saves a small amount of work.
// The code as written here seems to lead to a good compiled version using
// g++ on x86_64 and -O3.

inline std::uint64_t add_with_carry(std::uint64_t a1,
                                    std::uint64_t a2,
                                    std::uint64_t &r)
{   return ((r = a1 + a2) < a1);
}

// Now the general version with a carry-in. Note that in fact this version
// will support any value in c_in, not merely a single bit. Thus the
// carry_out can end up as 0, 1 or 2.

inline std::uint64_t add_with_carry(std::uint64_t a1,
                                    std::uint64_t a2,
                                    std::uint64_t a3, std::uint64_t &r)
{   std::uint64_t w;
    int c1 = add_with_carry(a1, a3, w);
    return c1 + add_with_carry(w, a2, r);
}

// In some places my code may be made nicer by having a version that
// adds 4 values.

inline std::uint64_t add_with_carry(std::uint64_t a1,
                                    std::uint64_t a2,
                                    std::uint64_t a3, std::uint64_t a4,
                                    std::uint64_t &r)
{   std::uint64_t w1, w2;
    int c1 = add_with_carry(a1, a2, w1);
    int c2 = add_with_carry(a3, a4, w2);
    return c1 + c2 + add_with_carry(w1, w2, r);
}

// subtract_with_borrow does
//     r = a1 - a2 - b_in;
// and returns 1 is there is a borrow out.

inline std::uint64_t subtract_with_borrow(std::uint64_t a1,
        std::uint64_t a2,
        std::uint64_t &r)
{   r = a1 - a2;
    return (r > a1);
}

inline std::uint64_t subtract_with_borrow(std::uint64_t a1,
        std::uint64_t a2,
        std::uint64_t b_in, std::uint64_t &r)
{   std::uint64_t w;
    int b1 = subtract_with_borrow(a1, b_in, w);
    return b1 + subtract_with_borrow(w, a2, r);
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
// called UNIT128.

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
        static_cast<std::uint64_t>(a>>64)
        << " "
        << static_cast<std::uint64_t>(a) << std::dec << std::setfill(' ');
    return out;
}

inline UINT128 pack128(std::uint64_t hi, std::uint64_t lo)
{   return (static_cast<UINT128>(hi)<<64) | lo;
}

inline void multiply64(std::uint64_t a, std::uint64_t b,
                       std::uint64_t &hi, std::uint64_t &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>(b);
    hi = static_cast<std::uint64_t>(r >> 64);
    lo = static_cast<std::uint64_t>(r);
}

// Now much the same but forming a*b+c. Note that this can not overflow
// the 128-bit result. Both hi and lo are only updated at the end
// of this, and so they are allowed to be the same as other arguments.

inline void multiply64(std::uint64_t a, std::uint64_t b,
                       std::uint64_t c,
                       std::uint64_t &hi, std::uint64_t &lo)
{   UINT128 r = static_cast<UINT128>(a)*static_cast<UINT128>
                (b) + static_cast<UINT128>(c);
    hi = static_cast<std::uint64_t>(r >> 64);
    lo = static_cast<std::uint64_t>(r);
}

inline void signed_multiply64(std::int64_t a, std::int64_t b,
                              std::int64_t &hi, std::uint64_t &lo)
{   INT128 r = static_cast<INT128>(a)*static_cast<INT128>(b);
    hi = static_cast<std::int64_t>(static_cast<UINT128>(r) >> 64);
    lo = static_cast<std::uint64_t>(r);
}

inline void signed_multiply64(std::int64_t a, std::int64_t b,
                              std::uint64_t c,
                              std::int64_t &hi, std::uint64_t &lo)
{   UINT128 r = static_cast<UINT128>(
                    static_cast<INT128>(a)*static_cast<INT128>(b))
                + static_cast<UINT128>(c);
    hi = static_cast<std::int64_t>(r >> 64);
    lo = static_cast<std::uint64_t>(r);
}

// divide {hi,lo} by divisor and generate a quotient and a remainder. The
// version of the code that is able to use __int128 can serve as clean
// documentation of the intent.

inline void divide64(std::uint64_t hi, std::uint64_t lo,
                     std::uint64_t divisor,
                     std::uint64_t &q, std::uint64_t &r)
{   arithlib_assert(divisor != 0 && hi < divisor);
    UINT128 dividend = pack128(hi, lo);
    q = dividend / divisor;
    r = dividend % divisor;
}

#else // __SIZEOF_INT128__

// If the C++ system I am using does not support and 128-bit integer
// type or if I have not detected it everything can still be done using
// lots of 64-bit operations, with each 64-bit value often treated as
// two 32-bit halves.

inline void multiply64(std::uint64_t a, std::uint64_t b,
                       std::uint64_t &hi, std::uint64_t &lo)
{   std::uint64_t a1 = a >> 32,           // top half
                      a0 = a & 0xFFFFFFFFU;   // low half
    std::uint64_t b1 = b >> 32,           // top half
                  b0 = b & 0xFFFFFFFFU;   // low half
    std::uint64_t u1 = a1*b1,             // top of result
                  u0 = a0*b0;             // bottom of result
// Now I need to add in the two "middle" bits a0*b1 and a1*b0
    std::uint64_t w = a0*b1;
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

inline void multiply64(std::uint64_t a, std::uint64_t b,
                       std::uint64_t c,
                       std::uint64_t &hi, std::uint64_t &lo)
{   std::uint64_t a1 = a >> 32,           // top half
                      a0 = a & 0xFFFFFFFFU;   // low half
    std::uint64_t b1 = b >> 32,           // top half
                  b0 = b & 0xFFFFFFFFU;   // low half
    std::uint64_t u1 = a1*b1,             // top of result
                  u0 = a0*b0;             // bottom of result
// Now I need to add in the two "middle" bits a0*b1 and a1*b0
    std::uint64_t w = a0*b1;
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

inline void signed_multiply64(std::int64_t a, std::int64_t b,
                              std::int64_t &hi, std::uint64_t &lo)
{   std::uint64_t h, l;
    multiply64(static_cast<std::uint64_t>(a),
               static_cast<std::uint64_t>(b), h,
               l);
    if (a < 0) h -= static_cast<std::uint64_t>(b);
    if (b < 0) h -= static_cast<std::uint64_t>(a);
    hi = static_cast<std::int64_t>(h);
    lo = l;
}

inline void signed_multiply64(std::int64_t a, std::int64_t b,
                              std::uint64_t c,
                              std::int64_t &hi, std::uint64_t &lo)
{   std::uint64_t h, l;
    multiply64(static_cast<std::uint64_t>(a),
               static_cast<std::uint64_t>(b), c, h,
               l);
    if (a < 0) h -= static_cast<std::uint64_t>(b);
    if (b < 0) h -= static_cast<std::uint64_t>(a);
    hi = static_cast<std::int64_t>(h);
    lo = l;
}

inline void divide64(std::uint64_t hi, std::uint64_t lo,
                     std::uint64_t divisor,
                     std::uint64_t &q, std::uint64_t &r)
{   arithlib_assert(divisor != 0 && hi < divisor);
    std::uint64_t u1 = hi;
    std::uint64_t u0 = lo;
    std::uint64_t c = divisor;
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
    const std::uint64_t base = 0x100000000U; // Number base (32 bits).
    std::uint64_t un1, un0,        // Norm. dividend LSD's.
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

INLINE_VAR const std::uint64_t allbits   =
    ~static_cast<std::uint64_t>(0);
INLINE_VAR const std::uint64_t topbit    = static_cast<std::uint64_t>
        (1)<<63;
INLINE_VAR const std::uint64_t allbuttop = topbit - 1;

inline bool positive(std::uint64_t a)
{   return static_cast<std::int64_t>(a) >= 0;
}

inline bool negative(std::uint64_t a)
{   return static_cast<std::int64_t>(a) < 0;
}


// This next function might be naivly written as
//    return ((a1==0 && positive(a2)) ||
//            (a1==-1 && negative(a2)));
// and it is to test if a bignum can have its top digit removed.

inline bool shrinkable(std::uint64_t a1, std::uint64_t a2)
{   return ((a1 + (a2>>63)) == 0);
}

inline void internal_copy(const std::uint64_t *a, std::size_t lena,
                          std::uint64_t *b)
{   std::memcpy(b, a, lena*sizeof(std::uint64_t));
}

// This internal functions sets b to be -a without altering its length.
// Because length is not changed it does not need a length for the
// destination passed to it.

inline void internal_negate(const std::uint64_t *a, std::size_t lena,
                            std::uint64_t *b)
{   std::uint64_t carry = 1;
    for (std::size_t i=0; i<lena; i++)
    {   std::uint64_t w = b[i] = ~a[i] + carry;
        carry = (w < carry ? 1 : 0);
    }
}

// When printing numbers in octal it will be handy to be able treat the
// data as an array of 3-bit digits, so here is an access function that
// does that. There is a messy issue about the top of a number, where it
// may not be a whole number of 3-bit octal digits. I pass in v, a vector
// of 64-bit values, n which is the length of that vector and i which
// is the index of the octal digit that I wish to extract. To help with
// that I have a function virtual_digit64() which lets me read from a
// bignum as if it has been usefully sign-extended.

inline std::uint64_t virtual_digit64(const std::uint64_t *v,
                                     std::size_t n,
                                     std::size_t j)
{   if (j < n) return v[j];
    else if (positive(v[n-1])) return 0;
    else return UINT64_C(0xffffffffffffffff);
}

// This function reads a 3-bit digit from a bignum, and is for use when
// printing in octal.

inline int read_u3(const std::uint64_t *v, std::size_t n,
                   std::size_t i)
{   std::size_t bits = 3*i;
    std::size_t n0 = bits/64;   // word with lowest bit of the 3
    std::size_t s0 =
        bits%64;   // amount to shift right to align it properly
    std::uint64_t w = virtual_digit64(v, n, n0) >> s0;
// If I needed to shift by 62 or 63 bits then the octal digit I am interested
// in needs some bits from the next word up.
    if (s0 >= 62) w |= (virtual_digit64(v, n, n0+1) << (64-s0));
    return static_cast<int>(w & 0x7);
}

//=========================================================================
//=========================================================================
// Some support for two models of memory layout. If VSL is set a number
// will be represented as an intptr_t value with its low 3 bits used as
// a tag. When the tag is removed and the intptr_t is cast to (uint64_t *)
// it points at a block of words. The first word holds a header value
// that includes (in packed form) the length of the block. Beyond that
// is the row of uint64_t values making up the bignum itself.
//
// For more direct C++ use the type is just (uint64_t *) and it refers
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
// (the current date is May 2019) I can not use "inline static int something;"
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
// such odrerings are relied upon to include copious comments in the code
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
// generators" and here even the independence of my thread-specific
// seed values is questionable.

// I perform all this setup at initialization time, but by wrapping the
// same sequence of steps as a critical region I could use it to re-seed
// generators whenever I felt the need to.
//

// The code here is explicitly aware of the prospect of threading, and
// should lead to different pseudo-random sequences in each thread.
// If you do not have C++17 inline variables then there will be a separate
// generator for each compilation unit and especially if you have an
// unreliable std::random_device about the only thing liable to keep
// things distinct in each will be the high resolution clock. Well to
// try to improve things there I will use the address of one of these
// variables as part of the seeding process, so that if they all end
// up static rather than inline that will give per-compilation-uint
// variation.

// Note that the thread local status information for a random number
// generator will be initialized in EVERY thread that is created. This
// includes the worker threads for Karatsuba multiplicatin and in a
// broader context where I use this library it will include threads that
// are used for GUI or other I/O purposes. So theer is a benefit if C++
// delays initialization of any of the variables within the following
// function until the function is first used!

inline std::mt19937_64 &ref_mersenne_twister()
{   std::random_device basic_randomness;
// Yes the static procedure-local variables here may carry some
// overhead as the system considers whether it wants to initialize them, but
// the overall cost here is already probably high as I accumulate entropy
// and so I am not going to worry.
    static thread_local std::uint64_t threadid =
        static_cast<std::uint64_t>(std::hash<std::thread::id>()(
                                       std::this_thread::get_id()));
    static std::uint64_t seed_component_1 = static_cast<std::uint64_t>
                                            (basic_randomness());
    static std::uint64_t seed_component_2 = static_cast<std::uint64_t>
                                            (basic_randomness());
    static std::uint64_t seed_component_3 = static_cast<std::uint64_t>
                                            (basic_randomness());
    static thread_local std::uint64_t time_now =
        static_cast<std::uint64_t>
        (std::time(NULL));
    static thread_local std::uint64_t chrono_now =
        static_cast<std::uint64_t>(
            std::chrono::high_resolution_clock::now().time_since_epoch().count());
// In my first draft of this library I had made the random seed directly
// from uint64_t values. However when testing on a Raspberry Pi that
// triggered a messages about bugs in gcc before gcc7 (relating to the
// alignment of some values passed as arguments in obscure cases). Building
// the seed sequence using 32-bit values avoids that issue, and since this
// is only done during initialization it is not time-critical.
//
    static thread_local std::seed_seq random_seed
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
            static_cast<std::uint64_t>(
                reinterpret_cast<std::uintptr_t>(&seed_component_1))>>32)
    };

    static thread_local std::mt19937_64 inner_mersenne_twister(
        random_seed);
// mersenne_twister() now generates 64-bit unsigned integers.
    return inner_mersenne_twister;
}

// If you are going to use vary many random numbers it may be a good
// and you might be running inder Cygwin or mingw32 it could be idea to
// use ref_mersenne_twister() once to collect the thread local instance
// relevant to you [note that it is a class object that provides operator(),
// not really a function, despite appearances!]. That way you only do the
// thread_local activity once (I hope).

MAYBE_UNUSED static std::uint64_t mersenne_twister()
{   return ref_mersenne_twister()();
}

// To re-seed I can just call this. I think that when I re-seed it will be
// to gain more repeatable behaviour, and so I am fairly happy about
// limiting the amount of input entropy here to 64-bits. If I was keen I
// could provide a reseed-method taking a bignum argument that could have
// lots of data in it. Note that this will reseed the random number
// generator associated with the thread it is called from. Note that there
// is one generator per thread, so if you have multiple threads and you reseed
// you are liable to want to reseed each of them.
//

MAYBE_UNUSED static void reseed(std::uint64_t n)
{   ref_mersenne_twister().seed(n);
}

// Now a number of functions for setting up random bignums. These may be
// useful for users, but they will also be very useful while testing this
// code.

// Return a random integer in the range 0 ... n-1.
// Given that the largest n that can be passed is UINT64_MAX the biggest
// rangs that can be generated here is 1 less than the full range of 64-bit
// values. To get a full 64-bit range merely call mersenne_twister()
// directly.

inline std::uint64_t uniform_uint64(std::uint64_t n)
{   if (n <= 1) return 0;
// I I want the remainder operation on the last line of this function to
// return a uniformly distributed result. To ensure that I want r to be
// drawn uniformly from a range that is a multiple of n.
    std::uint64_t q = UINT64_MAX/n;
    std::uint64_t w = n*q;
    std::uint64_t r;
// In the worst case here n was just over UINT64_MAX/2 and q came out
// as 1. In that case on average I will need to call mersenne_twister
// twice. Either larger or smaller inputs will behave better, and rather
// small inputs will mean I hardly ever need to re-try.
    std::mt19937_64 &mt = ref_mersenne_twister();
    do
    {   r = mt();
    }
    while (r >= w);
    return r%n;
}

// A uniform distribution across the range [0 .. (2^bits)-1], ie
// a bignum using (up to) the given number of bits. So eg uniform_positive(3)
// should return 0,1,2,3,4,5,6 or 7 each with equal probability.

inline void uniform_positive(std::uint64_t *r, std::size_t &lenr,
                             std::size_t bits)
{   if (bits == 0)
    {   r[0] = 0;
        lenr = 1;
    }
    lenr = (bits+63)/64;
// ref_mersenne_twister returns a reference to a thread_local entity and
// I hope that my cacheing its value here I reduce thread local access
// overheads.
    std::mt19937_64 &mt = ref_mersenne_twister();
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mt();
    if (bits%64 == 0) r[lenr-1] = 0;
    else r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (64-bits%64);
    while (lenr!=1 && shrinkable(r[lenr-1], r[lenr-2])) lenr--;
}

inline std::intptr_t uniform_positive(std::size_t n)
{   std::size_t lenr = (n + 63)/64;
    if (lenr == 0) lenr = 1; // special case!
    std::size_t save = lenr;
    std::uint64_t *r = reserve(lenr);
    uniform_positive(r, lenr, n);
    return confirm_size(r, save, lenr);
}

// As above but returning a value that may be negative. uniform_signed(3)
// could return -8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6 or 7.
// Note that while uniform_unsigned(0) can only return the value 0,
// uniform_signed(0) can return -1 or 0.

inline void uniform_signed(std::uint64_t *r, std::size_t &lenr,
                           std::size_t bits)
{   lenr = 1 + bits/64;
    std::mt19937_64 &mt = ref_mersenne_twister();
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mt();
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

inline std::intptr_t uniform_signed(std::size_t n)
{   std::size_t lenr = n/64+1;
    std::size_t save = lenr;
    std::uint64_t *r = reserve(lenr);
    uniform_signed(r, lenr, n);
    return confirm_size(r, save, lenr);
}

inline std::size_t bignum_bits(const std::uint64_t *a,
                               std::size_t lena);

// Generate a a value in the range 0 .. a-1 using a uniform distribution

inline void uniform_upto(std::uint64_t *a, std::size_t lena,
                         std::uint64_t *r,
                         std::size_t &lenr)
{   std::size_t n = bignum_bits(a, lena);
// I will repeatedly generate numbers that have as many bits as a until
// I get one that has a value less than a has. On average that should only
// take two tries.
    for (;;)
    {   push(a);
        uniform_positive(r, lenr, n);
        pop(a);
        if (lena > lenr) return;
        for (std::size_t len=lena;;)
        {   len--;
            if (a[len] > r[len]) return;
            if (a[len] < r[len] || len == 0) break;
        }
    }
}

inline std::intptr_t uniform_upto(std::intptr_t aa)
{   if (stored_as_fixnum(aa))
    {   std::uint64_t r = uniform_uint64(static_cast<std::uint64_t>
                                         (int_of_handle(
                                              aa)));
        return int_to_handle(r);
    }
    std::uint64_t *a = vector_of_handle(aa);
    std::size_t lena = number_size(a);
    push(a);
    std::uint64_t *r = reserve(lena);
    pop(a);
    std::size_t lenr;
    uniform_upto(a, lena, r, lenr);
    return confirm_size(r, lena, lenr);
}

inline void truncate_positive(const std::uint64_t *r, std::size_t &n)
{   while (r[n-1]==0 && n>1 && positive(r[n-2])) n--;
}

inline void truncate_negative(const std::uint64_t *r, std::size_t &n)
{   while (r[n-1]==allbits && n>1 && negative(r[n-2])) n--;
}

inline void truncate_unsigned(const std::uint64_t *r, std::size_t &n)
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

inline void fudge_distribution(const std::uint64_t *a,
                               std::size_t lena,
                               std::uint64_t *r, std::size_t &lenr, int n)
{   lenr = lena;
    switch (n&7)
    {   case 0:
        case 1:
        case 2:
            for (std::size_t i=0; i<lena+1; i++) r[i] = 0;
            if (a[lena-1] == 0)
            {   if (lena>1) r[lena-2] = static_cast<std::uint64_t>(1)<<63;
            }
            else r[lena-1] = static_cast<std::uint64_t>(1) << (63-nlz(a[lena-1]));
            if ((n&7) == 0) // decrement it
            {   if (lena!=1 || a[0]!=0) // avoid decrementing zero.
                {   std::uint64_t *p = r;
                    while (*p == 0) *p++ = static_cast<std::uint64_t>(-1);
                    (*p)--;
                }
            }
            else if ((n&7) == 2) // increment it
            {   std::uint64_t *p = r;
                while (*p == static_cast<std::uint64_t>(-1)) *p++ = 0;
                (*p)++;
            }
            break;
        default:
            for (std::size_t i=0; i<lena; i++) r[i] = a[i];
            break;
    }
    if ((n&8) != 0)
    {   std::uint64_t carry = 1;
        for (std::size_t i=0; i<lena+1; i++)
        {   carry = add_with_carry(~r[i], carry, r[i]);
        }
        truncate_negative(r, lenr);
    }
    else truncate_positive(r, lenr);
}

inline std::intptr_t fudge_distribution(std::intptr_t aa, int n)
{   std::uint64_t *a;
    std::size_t lena;
    std::uint64_t w[2];
    if (stored_as_fixnum(aa))
    {   w[1] = static_cast<std::uint64_t>(int_of_handle(aa));
        lena = 1;
        a = &w[1];
    }
    else
    {   a = vector_of_handle(aa);
        lena = number_size(a);
    }
    push(a);
    std::uint64_t *r = reserve(lena+1);
    pop(a);
    std::size_t lenr;
    fudge_distribution(a, lena, r, lenr, n);
    return confirm_size(r, lena+1, lenr);
}

// Generate a value in the range 0 .. 2^bits-1 using a distribution such
// numbers with each bit-length are equally probable. This works by
// selecting a big-length uniformly and then creating a number uniformly
// distributed across all those with that exact bit-width. This is perhaps
// not a very nice distribution from a mathematical perspective, but is is
// nevertheless a useful one to have in some test code.

inline void random_upto_bits(std::uint64_t *r, std::size_t &lenr,
                             std::size_t n)
{   std::size_t bits = static_cast<std::size_t>(uniform_uint64(n));
    if (bits == 0)
    {   r[0] = 0;
        lenr = 1;
        return;
    }
// The number will have from 1 to 64 bits in its top digit.
    lenr = (bits+63)/64;
    std::mt19937_64 &mt = ref_mersenne_twister();
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mt();
    if (n%64 != 0)
        r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (64-bits%64);
    r[lenr-1] |= UINT64_C(1) << ((bits-1)%64);
    if (bits%64 == 0) r[lenr++] = 0;
    arithlib_assert(!negative(r[lenr-1]));
}

inline std::intptr_t random_upto_bits(std::size_t bits)
{   std::size_t m = 1+bits/64;
    if (m == 0) m = 1;
    std::uint64_t *r = reserve(m);
    std::size_t lenr;
    random_upto_bits(r, lenr, bits);
    return confirm_size(r, m, lenr);
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

inline void int_to_bignum(std::int64_t n, std::uint64_t *r)
{   r[0] = static_cast<std::uint64_t>(n);
}

inline std::intptr_t int_to_bignum(std::int64_t n)
{   if (fits_into_fixnum(n)) return int_to_handle(n);
    std::uint64_t *r = reserve(1);
    int_to_bignum(n, r);
    return confirm_size(r, 1, 1);
}

inline void unsigned_int_to_bignum(std::uint64_t n, std::uint64_t *r,
                                   std::size_t &lenr)
{   r[0] = n;
    if (negative(n))
    {   r[1] = 0;
        lenr = 2;
    }
    else lenr = 1;
}

inline std::intptr_t unsigned_int_to_bignum(std::uint64_t n)
{   std::size_t w = (negative(n) ? 2 : 1);
    std::uint64_t *r = reserve(w);
    std::size_t lenr;
    unsigned_int_to_bignum(n, r, lenr);
    return confirm_size(r, w, lenr);
}

#ifdef softfloat_h
// Some constants that are useful when I am dealing with float128_t.

#ifdef LITTLEENDIAN
INLINE_VAR float128_t
f128_0      = {{0, INT64_C(0x0000000000000000)}},
f128_half   = {{0, INT64_C(0x3ffe000000000000)}},
f128_mhalf  = {{0, INT64_C(0xbffe000000000000)}},
f128_1      = {{0, INT64_C(0x3fff000000000000)}},
f128_m1     = {{0, INT64_C(0xbfff000000000000)}},
f128_N1     = {{0, INT64_C(0x4fff000000000000)}}; // 2^4096
#else // !LITTLEENDIAN
INLINE_VAR float128_t
f128_0      = {{INT64_C(0x0000000000000000), 0}},
f128_half   = {{INT64_C(0x3ffe000000000000), 0}},
f128_mhalf  = {{INT64_C(0xbffe000000000000), 0}},
f128_1      = {{INT64_C(0x3fff000000000000), 0}},
f128_m1     = {{INT64_C(0xbfff000000000000), 0}},
f128_N1     = {{INT64_C(0x4fff000000000000), 0}};
#endif // !LITTLEENDIAN

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
                      (static_cast<std::uint64_t>(x+4096) << 48);
        p = f128_div(p, f128_N1);
    }
    else p.v[HIPART] = (p.v[HIPART] & INT64_C(0x8000ffffffffffff)) |
                           (static_cast<std::uint64_t>(x) << 48);
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
                  (static_cast<std::uint64_t>(0x3ffe) << 48);
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
    {   i.v[HIPART] &= ASR(0xffff000000000000, x-1);
        i.v[LOPART] = 0;
    }
    else if (x <= 112)
    {   i.v[LOPART] &= (-static_cast<std::uint64_t>(1)) << (113-x);
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

// double_to_bits() turns a floating point value into an integer plus
// an exponent. It sets mantissa*2^exponent = d. This function will not
// give sensible output if passed an infinity or a NaN and so they should be
// filtered out before it is called.

inline void double_to_bits(double d, std::int64_t &mantissa,
                           int &exponent)
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
    mantissa = static_cast<std::int64_t>(d);
    exponent = x - 53;
}

// There are places where I need to shift a 128 or 192-bit number that is
// represented using several int64 values...

inline void shiftleft(std::int64_t &hi, std::uint64_t &lo, int n)
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

inline void shiftleft(std::int64_t &hi, std::uint64_t &mid,
                      std::uint64_t &lo,
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

inline void shiftright(std::int64_t &hi, std::uint64_t &lo, int n)
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
// |d| < 2^63 next will in fact be a signed value, len==1 and top will
// in fact be irrelevant. This should be seen as a special degenerate case.
// Whenever len>1 on output the number should be such that to make a bignum
// with value to match the float you append len-2 zero words. Note that
// for inputs in 2^63 <= d < 2^64 the result will have top==0 and next
// the integer value of d and len==2, with something similar for the
// equivalent negative range. The leading 0 or -1 is required in those
// cases. The result will be be any fractional part left over when d is
// converted to an integer, and this can only be nonzero is cases where
// |d| < 2^53.
//
// In the case that the floating point input is small its value may lie
// between two integers, and in that case I might want to adjust it in the
// sense of ROUND, TRUNC, FLOOR or CEILING. I will pass an extra argument
// to explain which I require.

enum RoundingMode {ROUND, TRUNC, FLOOR, CEILING};

inline void double_to_virtual_bignum(double d,
                                     std::int64_t &top, std::uint64_t &next, std::size_t &len,
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
// From here down I do not need to worry about zero, infinity or NaNs. But
// I may need to think about rounding!
    double intpart;
    double fracpart = std::modf(d, &intpart);
    std::int64_t mantissa;
    int exponent;
    double_to_bits(intpart, mantissa, exponent);
// Now I know intpart(d) = mantissa*2^exponent and mantissa is an integer.
    std::uint64_t lowbit = mantissa & -static_cast<std::uint64_t>
                           (mantissa);
    int lz = 63 - nlz(lowbit); // low zero bits
    mantissa = ASR(mantissa, lz);
    exponent += lz;
// Now mantissa has its least significant bit a "1". At this stage the
// input 1.0 (eg) should have turned into mantissa=1, exponent==0. And 1.5
// should have become mantissa=1, exponent=0 and fracpart = 0.5. fracpart has
// the same sign as the original input.
// So now I can apply my rounding mode...
    switch (mode)
    {   case ROUND:
            if (fracpart >= 0.5) mantissa++;
            else if (fracpart <= -0.5) mantissa--;
            break;
        case TRUNC:  // the effect of modf is this already.
            break;
        case FLOOR:
            if (fracpart != 0.0 && d < 0.0) mantissa--;
            break;
        case CEILING:
            if (fracpart != 0.0 && d > 0.0) mantissa++;
            break;
    }
    next = static_cast<std::uint64_t>(mantissa);
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
    }
}

#ifdef softfloat_h

// For int128_t the mantissa needs to be returned as a 128-bit integer, and
// I do that as a pair of 64-bit integers here. Infinities and NaNs would
// lead to nonsense output. Subnormal numbers are got wrong at present!

inline void float128_to_bits(float128_t d,
                             std::int64_t &mhi, std::uint64_t &mlo, int &exponent)
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
    mhi = (d.v[HIPART] & 0xffffffffffff) | 0x0001000000000000;;
    mlo = d.v[LOPART];
    if (static_cast<std::int64_t>(d.v[HIPART]) < 0)
    {   mlo = -mlo;
        if (mlo == 0) mhi = -mhi;
        else mhi = ~mhi;
    }
    exponent -= 113;
}

inline void inc128(std::int64_t &hi, std::uint64_t &lo)
{   if (++lo == 0) hi++;
}

inline void dec128(std::int64_t &hi, std::uint64_t &lo)
{   if (lo-- == 0) hi--;
}

// For a float128_t value I need to generate (up to) 3 64-bit digits for
// the way it would end up as a bignum.

inline void float128_to_virtual_bignum(float128_t d,
                                       std::int64_t &top, std::uint64_t &mid, std::uint64_t &next,
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
    float128_t intpart;
    float128_t fracpart = modf(d, intpart);
    std::int64_t mhi;
    std::uint64_t mlo;
    int exponent;
    float128_to_bits(intpart, mhi, mlo, exponent);
// Now I know intpart(d) = mantissa*2^exponent and mantissa is an integer.
    int lz;
    if (mlo != 0)
    {   std::uint64_t lowbit = mlo & (-mlo);
        lz = 63 - nlz(lowbit); // low zero bits
    }
    else
    {   std::uint64_t lowbit = mhi & (-static_cast<std::uint64_t>(mhi));
        lz = 64 + 63 - nlz(lowbit); // low zero bits
    }
    shiftright(mhi, mlo, lz);
    exponent += lz;
// Now mantissa has its least significant bit a "1". At this stage the
// input 1.0 (eg) should have turned into mantissa=1, exponent==0. And 1.5
// should have become mantissa=1, exponent=0 and fracpart = 0.5. fracpart has
// the same sign as the original input.
// So now I can apply my rounding mode...
    switch (mode)
    {   case ROUND:
            if (!f128_lt(fracpart, f128_half)) inc128(mhi, mlo);
            else if (f128_le(fracpart, f128_mhalf)) dec128(mhi, mlo);
            break;
        case TRUNC:  // the effect of modf is this already.
            break;
        case FLOOR:
            if (!f128_zero(fracpart) && f128_lt(d, f128_0)) dec128(mhi, mlo);
            break;
        case CEILING:
            if (!f128_zero(fracpart) && !f128_lt(d, f128_0)) inc128(mhi, mlo);
            break;
    }
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

inline std::intptr_t double_to_int(double d, RoundingMode mode)
{
// I return 0 if the input is a NaN or either +infinity or -infinity.
// This is somewhat arbitrary, but right now I am not minded to raise an
// exception.
    if (!std::isfinite(d) || d==0.0) return int_to_handle(0);
    std::int64_t top;
    std::uint64_t next;
    std::size_t len;
    double_to_virtual_bignum(d, top, next, len, mode);
    std::uint64_t *r = reserve(len);
    if (len == 1) r[0] = top;
    else
    {   for (std::size_t i=0; i<len-2; i++) r[i] = 0;
        r[len-1] = top;
        r[len-2] = next;
    }
    return confirm_size(r, len, len);
}

inline std::intptr_t round_double_to_int(double d)
{   return double_to_int(d, RoundingMode::ROUND);
}

inline std::intptr_t trunc_double_to_int(double d)
{   return double_to_int(d, RoundingMode::TRUNC);
}

inline std::intptr_t floor_double_to_int(double d)
{   return double_to_int(d, RoundingMode::FLOOR);
}

inline std::intptr_t ceiling_double_to_int(double d)
{   return double_to_int(d, RoundingMode::CEILING);
}

#ifdef softfloat_h

inline std::intptr_t float128_to_int(float128_t d, RoundingMode mode)
{   if (f128_zero(d) ||
        f128_infinite(d) ||
        f128_nan(d)) return int_to_handle(0);
    std::int64_t top;
    std::uint64_t mid, next;
    std::size_t len;
    float128_to_virtual_bignum(d, top, mid, next, len, mode);
    std::uint64_t *r = reserve(len);
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
    return confirm_size(r, len, len);
}

inline std::intptr_t round_float128_to_int(float128_t d)
{   return float128_to_int(d, RoundingMode::ROUND);
}

inline std::intptr_t trunc_float128_to_int(float128_t d)
{   return float128_to_int(d, RoundingMode::TRUNC);
}

inline std::intptr_t floor_float128_to_int(float128_t d)
{   return float128_to_int(d, RoundingMode::FLOOR);
}

inline std::intptr_t ceiling_float128_to_int(float128_t d)
{   return float128_to_int(d, RoundingMode::CEILING);
}

#endif // softfloat_h

inline std::int64_t Int64_t::op(std::int64_t a)
{   return a;
}

inline std::int64_t Int64_t::op(std::uint64_t *a)
{   return static_cast<std::int64_t>(a[0]);
}

inline std::uint64_t Uint64_t::op(std::int64_t a)
{   return static_cast<std::uint64_t>(a);
}

inline std::uint64_t Uint64_t::op(std::uint64_t *a)
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

inline float cast_to_float(double d)
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
{   return cast_to_float(std::ldexp(static_cast<double>(a), n));
}

inline float Float::op(std::int64_t a)
{
// if |a| < 2^52 I can convert to a double exactly
    if (a > -0x10000000000000 && a < 0x10000000000000)
        return cast_to_float(static_cast<double>(a));
    std::int64_t hi  = a & 0xfffffc0000000000;   // 22 bits
    std::int64_t mid = a & 0x000003fffff00000;   // 22 bits
    std::int64_t lo  = a & 0x00000000000fffff;   // 20 bits
    if (hi == 0 || hi == 0xfffffc000000000)
        return cast_to_float(static_cast<double>(hi) +
                             static_cast<double>(mid) + static_cast<double>(lo));
// This next line will move a ">0.5ulp" case so that it is visible
// within just the high 44 bits.  This is because the whole number can
// only be a 0.5ulp case if all the bits below the top 24 are zero, and
// for that to happen certainly the low 20 bits must all be zero...
    if (lo != 0) mid |= 1;
    return cast_to_float(static_cast<double>(hi) +
                         static_cast<double>(mid));
}

inline float Float::op(std::uint64_t *a)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Float::op(static_cast<std::int64_t>(a[0]));
// Now I need to do something similar to that done for the int64_t case
// but written larger. Specifically I want to split my input number into
// its top 24 bits and then all the rest. I will take separate paths
// for the positive and negative cases.
    std::uint64_t top24;
    int lz;
    bool sign = false;
    std::uint64_t top, next;
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
    arithlib_assert(top24 >= (static_cast<std::int64_t>(1))<<23 &&
                    top24 <= (static_cast<std::int64_t>(1))<<24);
    double d = static_cast<float>(top24);
    arithlib_assert(top24 == static_cast<std::uint64_t>(d));
    if (sign) d = -d;
    return ldexpf(d, static_cast<int>(128-24-lz+64*(lena-2)));
}

inline double Frexp::op(std::int64_t a, std::int64_t &x)
{
// The bad news here is that I am not confident that C++ will guarantee
// to round large integer values in any particular way when it converts
// them to floating point. So I will take careful action so that the
// conversions that I do are ones that will be exact, and I will perform
// rounding in IEEE style myself.
// First I will see if the value is small enough that I can work directly.
    const std::int64_t range = (static_cast<std::int64_t>(1))<<53;
    if (a >= -range && a <= range) return static_cast<double>(a);
// I will now drop down to a sign and magnitude representation
    bool sign = a < 0;
    std::uint64_t top53 = sign ? -static_cast<std::uint64_t>(a) : a;
// Because top53 >= 2^53 the number of leading zeros in its representation is
// at most 10. Ha ha. That guaranteed that the shift below will not overflow
// and is why I chose my range as I did.
    int lz = nlz(top53);
    std::uint64_t low = top53 << (lz+53);
    top53 = top53 >> (64-53-lz);
    if (low > 0x8000000000000000U) top53++;
    else if (low == 0x8000000000000000U) top53 += (top53 &
                1); // round to even
    arithlib_assert(top53 >= (static_cast<std::int64_t>(1))<<52 &&
                    top53 <= (static_cast<std::int64_t>(1))<<53);
// The next line should never introduce any rounding at all.
    double d = static_cast<double>(top53);
    arithlib_assert(top53 == static_cast<std::uint64_t>(d));
    if (sign) d = -d;
    x =64-53-lz;
    return d;
}

inline double Double::op(std::int64_t a)
{
// One would obviously like to go "return (double)a;" however C++ says
//  "If the value being converted is in the range of values that can
//   be represented but the value cannot be represented exactly, it is
//   an implementation-defined choice of either the next lower or higher
//   representable value."
// and I feel I should guarantee to round in IEEE style. I can do that
// by splitting the integer into two parts. Each of the two casts can deliver
// a double precision result without need for rounding
    std::int64_t hi = a & 0xffffffff00000000;
    std::int64_t lo = a & 0x00000000ffffffff;
    double d = static_cast<double>(lo);
    return d + static_cast<double>(hi);
}

inline double Frexp::op(std::uint64_t *a, std::int64_t &x)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Frexp::op(static_cast<std::int64_t>(a[0]), x);
// Now I need to do something similar to that done for the int64_t case
// but written larger. Specifically I want to split my input number into
// its top 53 bits and then all the rest. I will take separate paths
// for the positive and negative cases.
    std::uint64_t top53;
    int lz;
    bool sign = false;
    std::uint64_t top, next;
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
    arithlib_assert(top53 >= (static_cast<std::int64_t>(1))<<52 &&
                    top53 <= (static_cast<std::int64_t>(1))<<53);
    double d = static_cast<double>(top53);
    arithlib_assert(top53 == static_cast<std::uint64_t>(d));
    if (sign) d = -d;
    x = 128-53-lz+64*(lena-2);
    return d;
}

inline double Double::op(std::uint64_t *a)
{   std::int64_t x = 0;
    double d = Frexp::op(a, x);
    if (x > 10000) x = 10000;
    return std::ldexp(d, static_cast<int>(x));
}

#ifdef softfloat_h

inline float128_t Float128::op(std::int64_t a)
{   return i64_to_f128(a);
}

inline float128_t Frexp128::op(std::int64_t a, std::int64_t &x)
{   float128_t d = i64_to_f128(a), d1;
    int xi = 0;
    f128M_frexp(&d, &d1, &xi); // in the CSL sources.
    x = xi;
    return d1;
}

inline float128_t Frexp128::op(std::uint64_t *a, std::int64_t &x)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Float128::op(static_cast<std::int64_t>(a[0]));
    std::uint64_t top113, top113a;
    int lz;
    bool sign = false;
    std::uint64_t top, next1, next2;
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
        else top113 += add_with_carry(top113a, top113a&1, top113a);
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

inline float128_t Float128::op(std::uint64_t *a)
{   std::int64_t x = 0;
    float128_t d = Frexp128::op(a, x);
    if (x > 100000) x = 100000;
// There is an implementation of ldexp() for 128-bit floats in
// the CSL source file arith14.cpp.
    f128M_ldexp(&d, static_cast<int>(x));
    return d;
}

#endif // softfloat_t

INLINE_VAR const std::uint64_t ten19 = UINT64_C(10000000000000000000);

inline std::intptr_t string_to_bignum(const char *s)
{   bool sign = false;
    if (*s == '-')
    {   sign = true;
        s++;
    }
    std::size_t chars = std::strlen(s);
    std::size_t words = 1 + (108853*static_cast<std::uint64_t>
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
    std::uint64_t *r = reserve(words);
    for (std::size_t i=0; i<words; i++) r[i] = 0;
// Now for each chunk of digits NNNN in the input I want to go in effect
//     r = 10^19*r + NNNN;
// where the number 19 is used because 10^19 is the largest power of 10
// that fits in a 64-bit word.
    std::size_t next = 19*((chars-1)/19);
    while (chars != 0)
    {   std::uint64_t d = 0;
// assemble 19 digit blocks from the input into a value (d).
        while (chars != next)
        {   arithlib_assert(std::isdigit(*s));
            d = 10*d + (*s++ - '0');
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
    {   internal_negate(r, words, r);
        truncate_negative(r, n1);
    }
// However I could not have been precisely certain how many 64-bit words were
// needed and I arranged that any error was conservative - ie allocating
// more that would eventually be used.
    else truncate_positive(r, n1);
    return confirm_size(r, words, n1);
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


inline std::uint64_t short_divide_ten_19(std::uint64_t *r,
        std::size_t &n)
{   std::uint64_t hi = 0;
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

inline std::size_t bignum_bits(const std::uint64_t *a,
                               std::size_t lena)
{   if (lena == 0 && a[0] == 0) return 1; // say that 0 has 1 bit.
    std::uint64_t top = a[lena-1];  // top digit.
// The exact interpretation of "the length in bits of a negative number"
// is something I need to think through. Well Common Lisp counts the
// number of bits apart from the sign bit, so we have
//      n      bignum_bits(n)   bignum_bits(-n)
//      0           0                0
//     1           1    1           0 ..11111:
//      2           2   10           1 ..1111:0
//      3           2   11           2 ..111:01
//      4           3  100           2 ..111:00
//      7           3  111           3 ..11:001
//      8           4 1000           3 ..11:000
    if (negative(top))
    {   std::uint64_t carry = 1;
        for (std::size_t i=0; i<lena; i++)
        {   top = ~a[i] + carry;
            carry = (top < carry ? 1 : 0);
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

inline std::size_t predict_size_in_bytes(const std::uint64_t *a,
        std::size_t lena)
{
// I am first going to estimate the size in BITS and then I will
// see how that maps onto bytes.
    std::size_t r = bignum_bits(a, lena);
    r = 1 + static_cast<std::size_t>(
            (617*static_cast<std::uint64_t>(r))/2048);
    if (negative(a[lena-1])) r += 2; // allow space for a "-" sign.
    return r;
}

inline std::size_t bignum_to_string_length(std::uint64_t *a,
        std::size_t lena)
{   if (lena == 1)
    {   std::int64_t v = a[0];
// Note that the negative numbers checked against are 1 digit shorter so as
// to allow space for the "-" sign.
        if (v <= 9999999 && v >= -999999) return 7;
        else if (v <= 999999999999999 && v >= -99999999999999) return 15;
        else return 23;
    }
    else return predict_size_in_bytes(a, lena);
}

// The "as_unsigned" option here is not for general use - it is JUST for
// internal debugging because at times I work with values that are known
// to be positive and so where the top digit must be treated as unsigned...

inline std::size_t bignum_to_string(char *result, std::size_t m,
                                    std::uint64_t *a, std::size_t lena,
                                    bool as_unsigned=false)
{
// Making one-word numbers a special case simplifies things later on! It may
// also make this case go just slightly faster.
    if (lena == 1)
    {   std::uint64_t v = a[0];
        bool sign;
        if (negative(v) && !as_unsigned)
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
// I estimate that via predict_size_in_bytes(). Well the smallest bignum
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
    std::uint64_t *r = reinterpret_cast<std::uint64_t *>(result);
    std::size_t i;
// For the edge case lena==2 and m==20. I copy 2 words across. That will leave
// 4 bytes unused.
    for (i=0; i<lena; i++) r[i] = a[i];
    for (; i<m/sizeof(std::uint64_t); i++) r[i] = 0;
// Make the number positive
    bool sign = false;
    if (negative(r[lena-1]) && !as_unsigned)
    {   sign = true;
        internal_negate(r, lena, r);
    }
// Now my number is positive and is of length lena, but the vector it is
// stored in is length m with m usefully larger than lena. I will repeatedly
// divide by 10^19 and each time I do that I can store the remainder working
// down from the top of the vector. That should JUST keep up so that I
// never overwrite digits of the reducing part! I will stop when the
// number I have been working with end up < 10^19.
    std::size_t p = m/sizeof(std::uint64_t)
                    -1; // where to put next output digit
// Each value written into the vector here will stand for 19 decimal
// digits, and will use 8 bytes. So here the nastiest case will be when the
// number of decimal digits to end up with is 7 mod 8 (so that I lose as
// much space as possible) and the number is as large as possible. My
// belief is that numbers from 10^16 upwards will lead to there being enough
// space.
    while (lena > 1 || r[0] > ten19)
    {   std::uint64_t d = short_divide_ten_19(r, lena);
        r[p--] = d;
    }
    r[p] = r[0];
// Now I have the data that has to go into my result as a sequence of
// digits base 10^19, with the most significant one first. Convert
// to character data. I write in the string data just over what has been
// digits data, and I have arranged to position everything to (just)
// avoid overwriting myself.
    std::uint64_t top = r[p++];
    if (top == 0) top = r[p++]; // discard potential leading zero!
// Get a pointer into the buffer as character data...
    char *p1 = reinterpret_cast<char *>(result);
    std::size_t len = 0;
    if (sign)
    {   *p1++ = '-';
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
    {   *p1++ = buffer[--bp];
        len++;
    }
    while (bp != 0);
    arithlib_assert(len + 19*(m/sizeof(std::uint64_t)-p)<= m);
    while (p < m/sizeof(std::uint64_t))
    {
// I will always pick up the number I am going to expand before writing any
// digits into the buffer.
        top = r[p++];
// For subsequent chunks I want to print exactly 19 decimal digits.
        for (std::size_t i=0; i<18; i++)
        {   p1[18-i] = '0' + top%10;
            top = top/10;
        }
        *p1 = '0' + static_cast<int>(top);
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

inline string_handle bignum_to_string(std::uint64_t *a,
                                      std::size_t lena,
                                      bool as_unsigned=false)
{   std::size_t len = bignum_to_string_length(a, lena);
    push(a);
    char *s = reserve_string(len);
    pop(a);
    std::size_t final_len = bignum_to_string(s, len, a, lena,
                            as_unsigned);
    return confirm_size_string(s, len, final_len);
}

inline string_handle bignum_to_string(std::intptr_t aa)
{   std::uint64_t *a, v[1];
    std::size_t lena;
    if (stored_as_fixnum(aa))
    {   v[0] = int_of_handle(aa);
        a = v;
        lena = 1;
    }
    else
    {   a = vector_of_handle(aa);
        lena = number_size(a);
    }
    return bignum_to_string(a, lena);
}

// As well as converting to decimal I can do hex, octal or binary!

inline std::size_t bignum_to_string_hex_length(std::intptr_t aa)
{   return 24;
}

inline string_handle bignum_to_string_hex(std::intptr_t aa)
{   std::uint64_t *a, v[1];
    std::size_t n;
    if (stored_as_fixnum(aa))
    {   v[0] = int_of_handle(aa);
        a = v;
        n = 1;
    }
    else
    {   a = vector_of_handle(aa);
        n = number_size(a);
    }
// Making the value zero a special case simplifies things later on!
    if (n == 1 && a[0] == 0)
    {   char *r = reserve_string(1);
        std::strcpy(r, "0");
        return confirm_size_string(r, 1, 1);
    }
// printing in hexadecimal should be way easier!
    std::size_t m = 16*n;
    std::uint64_t top = a[n-1];
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
    push(a);
    char *r = reserve_string(m);
    pop(a);
    char *p = reinterpret_cast<char *>(r);
    top = a[n-1];
    if (sign)
    {   *p++ = '~';
        *p++ = 'f';
    }
    bool started = false;
    for (std::size_t i=0; i<n; i++)
    {   std::uint64_t v = a[n-i-1];
        for (int j=0; j<16; j++)
        {   int d = static_cast<int>(v >> (60-4*j)) & 0xf;
            if (!started)
            {   if ((sign && d==0xf) ||
                    (!sign && d==0)) continue;
                started = true;
            }
            *p++ = "0123456789abcdef"[d];
        }
    }
    return confirm_size_string(r, m, m);
}

inline std::size_t bignum_to_string_octal_length(std::intptr_t aa)
{   return 24;
}

inline string_handle bignum_to_string_octal(std::intptr_t aa)
{   std::uint64_t *a, v[1];
    std::size_t n;
    if (stored_as_fixnum(aa))
    {   v[0] = int_of_handle(aa);
        a = v;
        n = 1;
    }
    else
    {   a = vector_of_handle(aa);
        n = number_size(a);
    }
    std::size_t width = (64*n +
                         2)/3; // raw number of octal digits needed.
    std::uint64_t top = a[n-1];
    bool sign = negative(top);
// There is a slight misery in that 64 is not a multiple of 3 (!) and so
// the octal representation of a value has some digits that depend on a pair
// of adjacent words from the bignum.
    std::size_t
    nn;  // will be the number of characters used in the output
    if (sign)
    {   while (read_u3(a, n, width-1) == 7 && width > 1) width--;
        nn = width+2;
    }
    else
    {   while (read_u3(a, n, width-1) == 0 && width > 1) width--;
        nn = width;
    }
    push(a);
    char *r = reserve_string(nn);
    pop(a);
    char *p = reinterpret_cast<char *>(r);
    if (sign)
    {   *p++ = '~';
        *p++ = '7';
    }
    for (std::size_t i=0; i<width; i++)
        *p++ = '0' + read_u3(a, n, width-i-1);
    return confirm_size_string(r, nn, width);
}

inline std::size_t bignum_to_string_binary_length(std::intptr_t aa)
{   return 24;
}

inline string_handle bignum_to_string_binary(std::intptr_t aa)
{   std::uint64_t *a, v[1];
    std::size_t n;
    if (stored_as_fixnum(aa))
    {   v[0] = int_of_handle(aa);
        a = v;
        n = 1;
    }
    else
    {   a = vector_of_handle(aa);
        n = number_size(a);
    }
// Making the value zero a special case simplifies things later on!
    if (n == 1 && a[0] == 0)
    {   char *r = reserve_string(1);
        std::strcpy(r, "0");
        return confirm_size_string(r, 1, 1);
    }
    std::size_t m = 64*n;
    std::uint64_t top = a[n-1];
    bool sign = negative(top);
    if (sign)
    {   m += 2; // for "~1"
        while ((top>>63) == 1)
        {   top = top << 1;
            m--;
        }
    }
    else
    {   arithlib_assert(top != 0);
        while ((top>>63) == 0)
        {   top = top << 1;
            m--;
        }
    }
    push(a);
    char *r = reserve_string(m);
    pop(a);
    char *p = reinterpret_cast<char *>(r);
    top = a[n-1];
    if (sign)
    {   *p++ = '~';
        *p++ = '1';
    }
    bool started = false;
    for (std::size_t i=0; i<n; i++)
    {   std::uint64_t v = a[n-i-1];
        for (int j=0; j<64; j++)
        {   int d = static_cast<int>(v >> (63-j)) & 0x1;
            if (!started)
            {   if ((sign && d==1) ||
                    (!sign && d==0)) continue;
                started = true;
            }
            *p++ = '0' + d;
        }
    }
    return confirm_size_string(r, m, m);
}

//=========================================================================
//=========================================================================
// Big number comparisons.
//=========================================================================
//=========================================================================


inline bool Zerop::op(std::uint64_t *a)
{   return number_size(a) == 1 && a[0] == 0;
}

inline bool Zerop::op(std::int64_t a)
{   return a == 0;
}

inline bool Onep::op(std::uint64_t *a)
{   return number_size(a) == 1 && a[0] == 1;
}

inline bool Onep::op(std::int64_t a)
{   return a == 1;
}

inline bool Minusp::op(std::uint64_t *a)
{   return negative(a[number_size(a)-1]);
}

inline bool Minusp::op(std::int64_t a)
{   return a < 0;
}

inline bool Evenp::op(std::uint64_t *a)
{   return (a[0] & 1) == 0;
}

inline bool Evenp::op(std::int64_t a)
{   return (a & 1) == 0;
}

inline bool Oddp::op(std::uint64_t *a)
{   return (a[0] & 1) != 0;
}

inline bool Oddp::op(std::int64_t a)
{   return (a & 1) != 0;
}

// eqn

inline bool bigeqn(const std::uint64_t *a, std::size_t lena,
                   const std::uint64_t *b, std::size_t lenb)
{   if (lena != lenb) return false;
    return std::memcmp(a, b, lena*sizeof(std::uint64_t)) == 0;
}


inline bool Eqn::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    return bigeqn(a, lena, b, lenb);
}

inline bool Eqn::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    return lena==1 && static_cast<std::int64_t>(a[0])==b;
}

inline bool Eqn::op(std::int64_t a, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    return lenb==1 && a==static_cast<std::int64_t>(b[0]);
}

inline bool Eqn::op(std::int64_t a, std::int64_t b)
{   return (a == b);
}

inline bool Eqn::op(std::int64_t a, float b)
{   return Eqn::op(a, static_cast<double>(b));
}

inline bool Eqn::op(std::uint64_t *a, float b)
{   return Eqn::op(a, static_cast<double>(b));
}

inline bool Eqn::op(float a, std::int64_t b)
{   return Eqn::op(static_cast<double>(a), b);
}

inline bool Eqn::op(float a, std::uint64_t *b)
{   return Eqn::op(static_cast<double>(a), b);
}

inline bool Eqn::op(std::int64_t a, double b)
{   const std::int64_t range = (static_cast<std::int64_t>(1))<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) == b;
// The value on the next line is a floating point representation of 2^63,
// so any floating value at least that large is bigger than any int64_t value.
    if (b >= 9223372036854775808.0) return false;
    else if (b < -9223372036854775808.0) return false;
    if (std::isnan(b)) return false;
    return a == static_cast<std::int64_t>(b);
}

inline bool eqnfloat(std::uint64_t *a, std::size_t lena, double b)
{   if (std::isnan(b)||
        std::isinf(b)) return false;
    std::int64_t top = static_cast<std::int64_t>(a[lena-1]);
// If the signs differn than the values are certainly not equal.
    if (top >= 0 && b <= 0.0) return false;
    if (top < 0 && b >= 0.0) return false;
    double ipart;
    double fpart = std::modf(b, &ipart);
    if (fpart != 0.0) return false; // not an integer so not equal.
    std::int64_t hi;
    std::uint64_t next;
    std::size_t len;
    double_to_virtual_bignum(ipart, hi, next, len, RoundingMode::TRUNC);
    if (len != lena) return false;
    if (len == 1) return a[0] == static_cast<std::uint64_t>(top);
    if (a[len-1] != static_cast<std::uint64_t>(top) ||
        a[len-2] != next) return false;
    for (std::size_t i=0; i<len-2; i++)
        if (a[i] != 0) return false;
    return true;
}

inline bool Eqn::op(std::uint64_t *a, double b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Eqn::op(static_cast<std::int64_t>(a[0]), b);
    return eqnfloat(a, lena, b);
}

inline bool Eqn::op(double a, std::int64_t b)
{   return Eqn::op(b, a);
}

inline bool Eqn::op(double a, std::uint64_t *b)
{   return Eqn::op(b, a);
}

#ifdef softfloat_h

// The following constants are 2^112 and -2^112 and their reciprocals, which
// are used in rationalf128 because any 128-bit floating point value that
// is that large is necessarily an exact integer.

#ifdef LITTLEENDIAN

INLINE_VAR float128_t FP128_INT_LIMIT = {{0, INT64_C(0x406f000000000000)}};
INLINE_VAR float128_t FP128_MINUS_INT_LIMIT = {{0, INT64_C(0xc06f000000000000)}};

#else // !LITTLEENDIAN

INLINE_VAR float128_t FP128_INT_LIMIT = {{INT64_C(0x406f000000000000), 0}};
INLINE_VAR float128_t FP128_MINUS_INT_LIMIT = {{INT64_C(0xc06f000000000000), 0}};

#endif // !LITTLEENDIAN


inline bool eqnbigfloat(std::uint64_t *a, std::size_t lena,
                        float128_t b)
{   if (!f128_eq(b, b)) return false;  // a NaN if b!=b
    std::int64_t top = static_cast<std::int64_t>(a[lena-1]);
    if (top >= 0 && f128_lt(b, f128_0)) return false;
    if (top < 0 && !f128_lt(b, f128_0)) return false;
// Now the two inputs have the same sign.
    if (lena == 1 ||
        (lena == 2 &&
         !((a[1] > 0x0001000000000000 ||
            (a[1] == 0x0001000000000000 && a[0] != 0)) ||
           static_cast<std::int64_t>(a[1]) < -static_cast<std::int64_t>
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
        std::intptr_t bb = round_float128_to_int(b);
        return op_dispatch2<Eqn,bool>(vector_to_handle(a), bb);
    }
}

inline bool Eqn::op(std::int64_t a, float128_t b)
{   return f128_eq(i64_to_f128(a), b);
}

inline bool Eqn::op(std::uint64_t *a, float128_t b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Eqn::op(static_cast<std::int64_t>(a[0]), b);
    return eqnbigfloat(a, lena, b);
}

inline bool Eqn::op(float128_t a, std::int64_t b)
{   return Eqn::op(b, a);
}

inline bool Eqn::op(float128_t a, std::uint64_t *b)
{   return Eqn::op(b, a);
}

#endif // softfloat_h

inline bool Neqn::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    return !bigeqn(a, lena, b, lenb);
}

inline bool Neqn::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    return lena!=1 || static_cast<std::int64_t>(a[0])!=b;
}

inline bool Neqn::op(std::int64_t a, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    return lenb!=1 || a!=static_cast<std::int64_t>(b[0]);
}

inline bool Neqn::op(std::int64_t a, std::int64_t b)
{   return (a != b);
}

inline bool Neqn::op(std::int64_t a, float b)
{   return Neqn::op(a, static_cast<double>(b));
}

inline bool Neqn::op(std::uint64_t *a, float b)
{   return Neqn::op(a, static_cast<double>(b));
}

inline bool Neqn::op(float a, std::int64_t b)
{   return Neqn::op(static_cast<double>(a), b);
}

inline bool Neqn::op(float a, std::uint64_t *b)
{   return Neqn::op(static_cast<double>(a), b);
}

inline bool Neqn::op(std::int64_t a, double b)
{   const std::int64_t range = (static_cast<std::int64_t>(1))<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) != b;
// The value on the next line is a floating point representation of 2^63,
// so any floating value at least that large is bigger than any int64_t value.
    if (b >= 9223372036854775808.0) return true;
    else if (b < -9223372036854775808.0) return true;
    if (std::isnan(b)) return false;   // Ha Ha Ha!
    return a != static_cast<std::int64_t>(b);
}

inline bool Neqn::op(std::uint64_t *a, double b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Neqn::op(static_cast<std::int64_t>(a[0]), b);
    return !eqnfloat(a, lena, b);
}

inline bool Neqn::op(double a, std::int64_t b)
{   return Neqn::op(b, a);
}

inline bool Neqn::op(double a, std::uint64_t *b)
{   return Neqn::op(b, a);
}

#ifdef softfloat_h

inline bool Neqn::op(std::int64_t a, float128_t b)
{   return !f128_eq(i64_to_f128(a), b);
}

inline bool Neqn::op(std::uint64_t *a, float128_t b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Neqn::op(static_cast<std::int64_t>(a[0]), b);
    return !eqnbigfloat(a, lena, b);
}

inline bool Neqn::op(float128_t a, std::int64_t b)
{   return Neqn::op(b, a);
}

inline bool Neqn::op(float128_t a, std::uint64_t *b)
{   return Neqn::op(b, a);
}

#endif // softfloat_h

// greaterp

inline bool biggreaterp(const std::uint64_t *a, std::size_t lena,
                        const std::uint64_t *b, std::size_t lenb)
{   std::uint64_t a0 = a[lena-1], b0 = b[lenb-1];
// If one of the numbers has more digits than the other then the sign of
// the longer one gives my the answer.
    if (lena > lenb) return positive(a0);
    else if (lenb > lena) return negative(b0);
// When the two numbers are the same length but the top digits differ
// then comparing those digits tells me all I need to know.
    if (static_cast<std::int64_t>(a0) >
        static_cast<std::int64_t>(b0)) return true;
    if (static_cast<std::int64_t>(a0) <
        static_cast<std::int64_t>(b0)) return false;
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

inline bool big_unsigned_greaterp(const std::uint64_t *a,
                                  std::size_t lena,
                                  const std::uint64_t *b, std::size_t lenb)
{
// If one of the numbers has more digits than the other then it is the
// larger.
    if (lena > lenb) return true;
    else if (lenb > lena) return false;
    while (lena != 0)
    {   lena--;
        std::uint64_t a0 = a[lena];
        std::uint64_t b0 = b[lena];
        if (a0 > b0) return true;
        if (a0 < b0) return false;
    }
    return false;
}

inline bool Greaterp::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    return biggreaterp(a, lena, b, lenb);
}

inline bool Greaterp::op(std::uint64_t *a, std::int64_t bb)
{   std::uint64_t b[1] = {static_cast<std::uint64_t>(bb)};
    std::size_t lena = number_size(a);
    return biggreaterp(a, lena, b, 1);
}

inline bool Greaterp::op(std::int64_t aa, std::uint64_t *b)
{   std::uint64_t a[1] = {static_cast<std::uint64_t>(aa)};
    std::size_t lenb = number_size(b);
    return biggreaterp(a, 1, b, lenb);
}

inline bool Greaterp::op(std::int64_t a, std::int64_t b)
{   return a > b;
}

// I can always widen a float to a double without loss of any information,
// so all the cases of comparisons with floats (as distinct from with
// double) are easy to delegate.

inline bool Greaterp::op(std::int64_t a, float b)
{   return Greaterp::op(a, static_cast<double>(b));
}

inline bool Greaterp::op(std::uint64_t *a, float b)
{   return Greaterp::op(a, static_cast<double>(b));
}

inline bool Greaterp::op(float a, std::int64_t b)
{   return Greaterp::op(static_cast<double>(a), b);
}

inline bool Greaterp::op(float a, std::uint64_t *b)
{   return Greaterp::op(static_cast<double>(a), b);
}

inline bool Greaterp::op(std::int64_t a, double b)
{
// If the integer is small enough it can be converted to a double
// without any rounding, so then I can do the comparison easily.
    const std::int64_t range = static_cast<std::int64_t>(1)<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) > b;
// If the floating point value is >= 2^63 or is less < -2^63 it is beyond
// the range of int64_t, so the result is easy. This situation includes
// the case of infinities.
    if (b >= 9223372036854775808.0) return false;
    else if (b < -9223372036854775808.0) return true;
// NaNs must always return false from a comparison, so all the cases so
// far will have yielded correct results. But here I must filter out
// that situation.
    if (std::isnan(b)) return false;
// Because |b| >= 2^53 but < 2^63 it can be converted to an int64_t value
// without rounding.
    return a > static_cast<std::int64_t>(b);
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

inline bool greaterpfloat(std::uint64_t *a, std::size_t lena,
                          double b,
                          CompareMode mode)
{   if (std::isnan(b)) return false;
// If the integer is small enough it can be converted to a double
// without any rounding, so then I can do the comparison easily.
    if (lena == 1)
    {   std::int64_t aa = a[0];
        const std::int64_t range = (static_cast<std::int64_t>(1))<<53;
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
    std::int64_t top;
    std::uint64_t next;
    std::size_t len;
    double_to_virtual_bignum(b, top, next, len, RoundingMode::TRUNC);
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
    if (static_cast<std::int64_t>(a[lena-1]) < top ||
        (static_cast<std::int64_t>(a[lena-1]) == top && a[lena-2] < next))
        return (mode==CompareMode::LESSP || mode==CompareMode::LEQ);
    if (static_cast<std::int64_t>(a[lena-1]) > top ||
        (static_cast<std::int64_t>(a[lena-1]) == top && a[lena-2] > next))
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

inline bool Greaterp::op(std::uint64_t *a, double b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Greaterp::op(static_cast<std::int64_t>(a[0]),
                                           b);
    return greaterpfloat(a, lena, b, CompareMode::GREATERP);
}

inline bool Greaterp::op(double a, std::int64_t b)
{   return Lessp::op(b, a);
}

inline bool Greaterp::op(double a, std::uint64_t *b)
{   return Lessp::op(b, a);
}

#ifdef softfloat_h

//@@ This is not sorted out yet!

// This one function does >, >=, < and <= with "great" indicating if
// the base is > or < and "ifequal" distinguishing > from >= and < from <=.

inline bool greaterpbigfloat(std::uint64_t *a, std::size_t lena,
                             float128_t b,
                             bool great, bool ifequal)
{   if (f128_nan(b)) return
            false;  // Comparisons involving a NaN => false.
    std::int64_t top = static_cast<std::int64_t>(a[lena-1]);
    if (top >= 0 && f128_lt(b, f128_0)) return great;
    if (top < 0 && !f128_lt(b, f128_0)) return !great;
// Now the two inputs have the same sign.
    if (lena == 1 ||
        (lena == 2 &&
         !((a[1] > 0x0001000000000000 ||
            (a[1] == 0x0001000000000000 && a[0] != 0)) ||
           static_cast<std::int64_t>(a[1]) < -static_cast<std::int64_t>
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
        std::intptr_t bb = round_float128_to_int(b);
// At the moment I think there is a space-leak on bb here...
        if (great)
            if (ifequal)
                return op_dispatch2<Geq,bool>(vector_to_handle(a), bb);
            else return op_dispatch2<Greaterp,bool>(vector_to_handle(a), bb);
        else if (ifequal)
            return op_dispatch2<Leq,bool>(vector_to_handle(a), bb);
        else return op_dispatch2<Lessp,bool>(vector_to_handle(a), bb);
    }
}

inline bool Greaterp::op(std::int64_t a, float128_t b)
{   return f128_lt(b, i64_to_f128(a));
}

inline bool Greaterp::op(std::uint64_t *a, float128_t b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Greaterp::op(static_cast<std::int64_t>(a[0]),
                                           b);
    return greaterpbigfloat(a, lena, b, true, false);

}

inline bool Greaterp::op(float128_t a, std::int64_t b)
{   return Lessp::op(b, a);
}

inline bool Greaterp::op(float128_t a, std::uint64_t *b)
{   return Lessp::op(b, a);
}

#endif // softfloat_h

// geq

inline bool Geq::op(std::uint64_t *a, std::uint64_t *b)
{   return !Greaterp::op(b, a);
}

inline bool Geq::op(std::uint64_t *a, std::int64_t b)
{   return !Greaterp::op(b, a);
}

inline bool Geq::op(std::int64_t a, std::uint64_t *b)
{   return !Greaterp::op(b, a);
}

inline bool Geq::op(std::int64_t a, std::int64_t b)
{   return a >= b;
}

inline bool Geq::op(std::int64_t a, float b)
{   return Geq::op(a, static_cast<double>(b));
}

inline bool Geq::op(std::uint64_t *a, float b)
{   return Geq::op(a, static_cast<double>(b));
}

inline bool Geq::op(float a, std::int64_t b)
{   return Geq::op(static_cast<double>(a), b);
}

inline bool Geq::op(float a, std::uint64_t *b)
{   return Geq::op(static_cast<double>(a), b);
}

inline bool Geq::op(std::int64_t a, double b)
{   const std::int64_t range = (static_cast<std::int64_t>(1))<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) >= b;
    if (b >= 9223372036854775808.0) return false;
    else if (b < -9223372036854775808.0) return true;
    if (std::isnan(b)) return false;
    return a >= static_cast<std::int64_t>(b);
}

inline bool Geq::op(std::uint64_t *a, double b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Geq::op(static_cast<std::int64_t>(a[0]), b);
    return greaterpfloat(a, lena, b, CompareMode::GEQ);
}

inline bool Geq::op(double a, std::int64_t b)
{   return Leq::op(b, a);
}

inline bool Geq::op(double a, std::uint64_t *b)
{   return Leq::op(b, a);
}

#ifdef softfloat_h

inline bool Geq::op(std::int64_t a, float128_t b)
{   return f128_le(b, i64_to_f128(a));
    return false;
}

inline bool Geq::op(std::uint64_t *a, float128_t b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Greaterp::op(static_cast<std::int64_t>(a[0]),
                                           b);
    return greaterpbigfloat(a, lena, b, true, true);
}

inline bool Geq::op(float128_t a, std::int64_t b)
{   return Leq::op(b, a);
}

inline bool Geq::op(float128_t a, std::uint64_t *b)
{   return Leq::op(b, a);
}

#endif // softfloat_h

// lessp

inline bool Lessp::op(std::uint64_t *a, std::uint64_t *b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(std::uint64_t *a, std::int64_t b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(std::int64_t a, std::uint64_t *b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(std::int64_t a, std::int64_t b)
{   return a < b;
}

inline bool Lessp::op(std::int64_t a, float b)
{   return Lessp::op(a, static_cast<double>(b));
}

inline bool Lessp::op(std::uint64_t *a, float b)
{   return Lessp::op(a, static_cast<double>(b));
}

inline bool Lessp::op(float a, std::int64_t b)
{   return Lessp::op(static_cast<double>(a), b);
}

inline bool Lessp::op(float a, std::uint64_t *b)
{   return Lessp::op(static_cast<double>(a), b);
}

inline bool Lessp::op(std::int64_t a, double b)
{   const std::int64_t range = static_cast<std::int64_t>(1)<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) < b;
    if (b >= 9223372036854775808.0) return true;
    else if (b < -9223372036854775808.0) return false;
    if (std::isnan(b)) return false;
    return a < static_cast<std::int64_t>(b);
}

inline bool Lessp::op(std::uint64_t *a, double b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Lessp::op(static_cast<std::int64_t>(a[0]), b);
    return greaterpfloat(a, lena, b, CompareMode::LESSP);
}

inline bool Lessp::op(double a, std::int64_t b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(double a, std::uint64_t *b)
{   return Greaterp::op(b, a);
}

#ifdef softfloat_h

inline bool Lessp::op(std::int64_t a, float128_t b)
{   return f128_lt(i64_to_f128(a), b);
    return false;
}

inline bool Lessp::op(std::uint64_t *a, float128_t b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Lessp::op(static_cast<std::int64_t>(a[0]), b);
    return greaterpbigfloat(a, lena, b, false, false);

    return false;
}

inline bool Lessp::op(float128_t a, std::int64_t b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(float128_t a, std::uint64_t *b)
{   return Greaterp::op(b, a);
}

#endif // softfloat_h

// leq

inline bool Leq::op(std::uint64_t *a, std::uint64_t *b)
{   return !Greaterp::op(a, b);
}

inline bool Leq::op(std::uint64_t *a, std::int64_t b)
{   return !Greaterp::op(a, b);
}

inline bool Leq::op(std::int64_t a, std::uint64_t *b)
{   return !Greaterp::op(a, b);
}

inline bool Leq::op(std::int64_t a, std::int64_t b)
{   return a <= b;
}

inline bool Leq::op(std::int64_t a, float b)
{   return Leq::op(a, static_cast<double>(b));
}

inline bool Leq::op(std::uint64_t *a, float b)
{   return Leq::op(a, static_cast<double>(b));
}

inline bool Leq::op(float a, std::int64_t b)
{   return Leq::op(static_cast<double>(a), b);
}

inline bool Leq::op(float a, std::uint64_t *b)
{   return Leq::op(static_cast<double>(a), b);
}

inline bool Leq::op(std::int64_t a, double b)
{   const std::int64_t range = static_cast<std::int64_t>(1)<<53;
    if (a >= -range && a <= range) return static_cast<double>(a) <= b;
    if (b >= 9223372036854775808.0) return true;
    else if (b < -9223372036854775808.0) return false;
    if (std::isnan(b)) return false;
    return a <= static_cast<std::int64_t>(b);
}

inline bool Leq::op(std::uint64_t *a, double b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Lessp::op(static_cast<std::int64_t>(a[0]), b);
    return greaterpfloat(a, lena, b, CompareMode::LEQ);
}

inline bool Leq::op(double a, std::int64_t b)
{   return Geq::op(b, a);
}

inline bool Leq::op(double a, std::uint64_t *b)
{   return Geq::op(b, a);
}

#ifdef softfloat_h

inline bool Leq::op(std::int64_t a, float128_t b)
{   return f128_le(i64_to_f128(a), b);
    return false;
}

inline bool Leq::op(std::uint64_t *a, float128_t b)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Leq::op(static_cast<std::int64_t>(a[0]), b);
    return greaterpbigfloat(a, lena, b, false, true);
}

inline bool Leq::op(float128_t a, std::int64_t b)
{   return Geq::op(b, a);
}

inline bool Leq::op(float128_t a, std::uint64_t *b)
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

inline void bignegate(const std::uint64_t *a, std::size_t lena,
                      std::uint64_t *r, std::size_t &lenr)
{   internal_negate(a, lena, r);
// When I negate (-(2^(64n-1))) I will need to place a zero work ahead of the
// value that is mow positive, making the bignum one digit longer.
// If I have 2^(64n-1) it will have been represented with that padding zero
// ahead of it, but when negated the bignum can shrink.
    if (r[lena-1]==topbit) r[lena++] = 0;
    else if (r[lena-1]==UINT64_C(0xffffffffffffffff) && lena>1 &&
             negative(r[lena-2])) lena--;
    lenr = lena;
}

inline std::intptr_t Minus::op(std::uint64_t *a)
{   std::size_t n = number_size(a);
    push(a);
    std::uint64_t *p = reserve(n+1);
    pop(a);
    std::size_t final_n;
    bignegate(a, n, p, final_n);
    return confirm_size(p, n+1, final_n);
}

// The following can only be called via op_dispatch1(), and in that
// case the argument has to have started off as a fixnum. In such cases
// the result will also be a fixnum except when negating MIN_FIXNUM. But
// even in that case (-a) can not overflow 64-bit arithmetic because
// the fixnum will have had at least one tag bit.

inline std::intptr_t Minus::op(std::int64_t a)
{   if (a == MIN_FIXNUM) return int_to_bignum(-a);
    else return int_to_handle(-a);
}

inline std::intptr_t Add1::op(std::uint64_t *a)
{   return Plus::op(a, 1);
}

inline std::intptr_t Add1::op(std::int64_t a)
{   return int_to_bignum(a+1);
}

inline std::intptr_t Sub1::op(std::uint64_t *a)
{   return Plus::op(a, -1);
}

inline std::intptr_t Sub1::op(std::int64_t a)
{   return int_to_bignum(a-1);
}

inline std::intptr_t Abs::op(std::uint64_t *a)
{   std::size_t n = number_size(a);
    if (!negative(a[n-1]))
    {   push(a);
        std::uint64_t *r = reserve(n);
        pop(a);
        std::memcpy(r, a, n*sizeof(std::uint64_t));
        return confirm_size(r, n, n);
    }
    push(a);
    std::uint64_t *r = reserve(n+1);
    pop(a);
    std::size_t final_n;
    bignegate(a, n, r, final_n);
    return confirm_size(r, n+1, final_n);
}

// The following can only be called via op_dispatch1(), and in that
// case the argument has to have started off as a fixnum. In such cases
// the result will also be a fixnum except when negating MIN_FIXNUM. But
// even in that case (-a) can not overflow 64-bit arithmetic because
// the fixnum will have had at least one tag bit.

inline std::intptr_t Abs::op(std::int64_t a)
{   if (a == MIN_FIXNUM) return unsigned_int_to_bignum(-a);
    else return int_to_handle(a<0 ? -a : a);
}

// The "bitnot" operation is simple and length can not change.

inline void biglognot(const std::uint64_t *a, std::size_t lena,
                      std::uint64_t *r, std::size_t &lenr)
{   for (std::size_t i=0; i<lena; i++)
    {   r[i] = ~a[i];
    }
    lenr = lena;
}

inline std::intptr_t Lognot::op(std::uint64_t *a)
{   std::size_t n = number_size(a);
    push(a);
    std::uint64_t *p = reserve(n+1);
    pop(a);
    std::size_t final_n;
    biglognot(a, n, p, final_n);
    return confirm_size(p, n+1, final_n);
}

inline std::intptr_t Lognot::op(std::int64_t a)
{   return int_to_handle(~a);
}

// logand

inline void ordered_biglogand(const std::uint64_t *a,
                              std::size_t lena,
                              const std::uint64_t *b, std::size_t lenb,
                              std::uint64_t *r, std::size_t &lenr)
{   for (std::size_t i=0; i<lenb; i++)
        r[i] = a[i] & b[i];
    if (negative(b[lenb-1]))
    {   for (std::size_t i=lenb; i<lena; i++) r[i] = a[i];
        lenr = lena;
    }
    else lenr = lenb;
    truncate_positive(r, lenr);
}

inline void biglogand(const std::uint64_t *a, std::size_t lena,
                      const std::uint64_t *b, std::size_t lenb,
                      std::uint64_t *r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogand(a, lena, b, lenb, r,
                                 lenr);
    else return ordered_biglogand(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logand::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
    biglogand(a, lena, b, lenb, p, final_n);
    return confirm_size(p, n, final_n);
}

// The next two are not optimised - a case of (logand bignum positive-fixnum)
// is guaranteed to end up a fixnum so could be done more slickly - however
// I am not going to expect that to be on the critical performance path for
// enough programs for me to worry too much!

inline std::intptr_t Logand::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    push(a);
    std::uint64_t *p = reserve(lena);
    pop(a);
    std::size_t final_n;
    std::uint64_t bb[1] = {static_cast<std::uint64_t>(b)};
    biglogand(a, lena, bb, 1, p, final_n);
    return confirm_size(p, lena, final_n);
}

inline std::intptr_t Logand::op(std::int64_t a, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *p = reserve(lenb);
    pop(b);
    std::size_t final_n;
    std::uint64_t aa[1] = {static_cast<std::uint64_t>(a)};
    biglogand(aa, 1, b, lenb, p, final_n);
    return confirm_size(p, lenb, final_n);
}

inline std::intptr_t Logand::op(std::int64_t a, std::int64_t b)
{   return int_to_handle(a & b);
}

// logor

inline void ordered_biglogor(const std::uint64_t *a, std::size_t lena,
                             const std::uint64_t *b, std::size_t lenb,
                             std::uint64_t *r, std::size_t &lenr)
{   for (std::size_t i=0; i<lenb; i++)
        r[i] = a[i] | b[i];
    if (negative(b[lenb-1])) lenr = lenb;
    else
    {   for (std::size_t i=lenb; i<lena; i++) r[i] = a[i];
        lenr = lena;
    }
    truncate_negative(r, lenr);
}

inline void biglogor(const std::uint64_t *a, std::size_t lena,
                     const std::uint64_t *b, std::size_t lenb,
                     std::uint64_t *r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogor(a, lena, b, lenb, r,
                                 lenr);
    else return ordered_biglogor(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logor::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
    biglogor(a, lena, b, lenb, p, final_n);
    return confirm_size(p, n, final_n);
}

inline std::intptr_t Logor::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    push(a);
    std::uint64_t *p = reserve(lena);
    pop(a);
    std::size_t final_n;
    std::uint64_t bb[1] = {static_cast<std::uint64_t>(b)};
    biglogor(a, lena, bb, 1, p, final_n);
    return confirm_size(p, lena, final_n);
}

inline std::intptr_t Logor::op(std::int64_t a, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *p = reserve(lenb);
    pop(b);
    std::size_t final_n;
    std::uint64_t aa[1] = {static_cast<std::uint64_t>(a)};
    biglogor(aa, 1, b, lenb, p, final_n);
    return confirm_size(p, lenb, final_n);
}

inline std::intptr_t Logor::op(std::int64_t a, std::int64_t b)
{   return int_to_handle(a | b);
}

// logxor

inline void ordered_biglogxor(const std::uint64_t *a,
                              std::size_t lena,
                              const std::uint64_t *b, std::size_t lenb,
                              std::uint64_t *r, std::size_t &lenr)
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
    truncate_positive(r, lenr);
    truncate_negative(r, lenr);
}

inline void biglogxor(const std::uint64_t *a, std::size_t lena,
                      const std::uint64_t *b, std::size_t lenb,
                      std::uint64_t *r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogxor(a, lena, b, lenb, r,
                                 lenr);
    else return ordered_biglogxor(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logxor::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
    biglogxor(a, lena, b, lenb, p, final_n);
    return confirm_size(p, n, final_n);
}

inline std::intptr_t Logxor::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    push(a);
    std::uint64_t *p = reserve(lena);
    pop(a);
    std::size_t final_n;
    std::uint64_t bb[1] = {static_cast<std::uint64_t>(b)};
    biglogxor(a, lena, bb, 1, p, final_n);
    return confirm_size(p, lena, final_n);
}

inline std::intptr_t Logxor::op(std::int64_t a, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *p = reserve(lenb);
    pop(b);
    std::size_t final_n;
    std::uint64_t aa[1] = {static_cast<std::uint64_t>(a)};
    biglogxor(aa, 1, b, lenb, p, final_n);
    return confirm_size(p, lenb, final_n);
}

inline std::intptr_t Logxor::op(std::int64_t a, std::int64_t b)
{   return int_to_handle(a ^ b);
}


inline void ordered_biglogeqv(const std::uint64_t *a,
                              std::size_t lena,
                              const std::uint64_t *b, std::size_t lenb,
                              std::uint64_t *r, std::size_t &lenr)
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
    truncate_positive(r, lenr);
    truncate_negative(r, lenr);
}

inline void biglogeqv(const std::uint64_t *a, std::size_t lena,
                      const std::uint64_t *b, std::size_t lenb,
                      std::uint64_t *r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_biglogeqv(a, lena, b, lenb, r,
                                 lenr);
    else return ordered_biglogeqv(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Logeqv::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n;
    if (lena >= lenb) n = lena;
    else n = lenb;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
    biglogeqv(a, lena, b, lenb, p, final_n);
    return confirm_size(p, n, final_n);
}

inline std::intptr_t Logeqv::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    push(a);
    std::uint64_t *p = reserve(lena);
    pop(a);
    std::size_t final_n;
    std::uint64_t bb[1] = {static_cast<std::uint64_t>(b)};
    biglogeqv(a, lena, bb, 1, p, final_n);
    return confirm_size(p, lena, final_n);
}

inline std::intptr_t Logeqv::op(std::int64_t a, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *p = reserve(lenb);
    pop(b);
    std::size_t final_n;
    std::uint64_t aa[1] = {static_cast<std::uint64_t>(a)};
    biglogeqv(aa, 1, b, lenb, p, final_n);
    return confirm_size(p, lenb, final_n);
}

inline std::intptr_t Logeqv::op(std::int64_t a, std::int64_t b)
{   return int_to_handle(~a ^ b);
}

inline void bigrightshift(const std::uint64_t *a, std::size_t lena,
                          std::int64_t n,
                          std::uint64_t *r, std::size_t &lenr);

inline void bigleftshift(const std::uint64_t *a, std::size_t lena,
                         std::int64_t n,
                         std::uint64_t *r, std::size_t &lenr)
{   if (n == 0)
    {   internal_copy(a, lena, r);
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
                         static_cast<std::uint64_t>(-1)<<bits :
                         0) | (a[lena-1]>>(64-bits));
        lenr = lena+words+1;
    }
    truncate_positive(r, lenr);
    truncate_negative(r, lenr);
}

inline std::intptr_t rightshift_b(std::uint64_t *a, std::int64_t n);

inline std::intptr_t LeftShift::op(std::uint64_t *a, std::int64_t n)
{   if (n == 0) return copy_if_no_garbage_collector(a);
    else if (n < 0) return RightShift::op(a, -n);
    std::size_t lena = number_size(a);
    std::size_t nr = lena + (n/64) + 1;
    push(a);
    std::uint64_t *p = reserve(nr);
    pop(a);
    std::size_t final_n;
    bigleftshift(a, lena, n, p, final_n);
    return confirm_size(p, nr, final_n);
}

inline std::intptr_t LeftShift::op(std::int64_t aa, std::int64_t n)
{   if (n == 0) return int_to_handle(aa);
    else if (n < 0) return RightShift::op(aa, -n);
    std::size_t nr = (n/64) + 2;
    std::uint64_t *p = reserve(nr);
    std::size_t final_n;
    std::uint64_t a[1] = {static_cast<std::uint64_t>(aa)};
    bigleftshift(a, 1, n, p, final_n);
    return confirm_size(p, nr, final_n);
}

inline void bigrightshift(const std::uint64_t *a, std::size_t lena,
                          std::int64_t n,
                          std::uint64_t *r, std::size_t &lenr)
{   if (n == 0)
    {   internal_copy(a, lena, r);
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
    {   r[0] = negative(a[lena-1]) ? -static_cast<std::uint64_t>(1) : 0;
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
    truncate_positive(r, lenr);
    truncate_negative(r, lenr);
}

inline std::intptr_t RightShift::op(std::uint64_t *a, std::int64_t n)
{   if (n == 0) return copy_if_no_garbage_collector(a);
    else if (n < 0) return LeftShift::op(a, -n);
    std::size_t lena = number_size(a);
    std::size_t nr;
    if (lena > static_cast<std::size_t>(n)/64) nr = lena - n/64;
    else nr = 1;
    push(a);
    std::uint64_t *p = reserve(nr);
    pop(a);
    std::size_t final_n;
    bigrightshift(a, lena, n, p, final_n);
    return confirm_size(p, nr, final_n);
}

inline std::intptr_t RightShift::op(std::int64_t a, std::int64_t n)
{   if (n == 0) return int_to_handle(a);
    else if (n < 0) return LeftShift::op(a, -n);
// Shifts of 64 and up obviously lose all the input data apart from its
// sign, but so does a shift by 63.
    if (n >= 63) return int_to_handle(a>=0 ? 0 : -1);
// Because C++ does not guarantee that right shifts on signed values
// duplicate the sign bit I perform the "shift" here using division by
// a power of 2. Because I have n <= 62 here I will not get overflow.
    std::int64_t q = static_cast<std::int64_t>(1)<<n;
    return int_to_handle((a & ~(q-1))/q);
}

inline std::size_t IntegerLength::op(std::uint64_t *a)
{   return bignum_bits(a, number_size(a));
}

inline std::size_t IntegerLength::op(std::int64_t aa)
{   std::uint64_t a;
    if (aa == 0 || aa == -1) return 0;
    else if (aa < 0) a = -static_cast<std::uint64_t>(aa) - 1;
    else a = aa;
    return static_cast<std::size_t>(64-nlz(a));
}

inline std::size_t Low_bit::op(std::uint64_t *a)
{   std::size_t lena = number_size(a);
    if (negative(a[lena-1])) // count trailing 1 bits!
    {   std::size_t r=0, i=0;
        while (a[i++]==-static_cast<std::uint64_t>(1)) r += 64;
        std::uint64_t w = ~a[i-1];
        return static_cast<std::size_t>(64-nlz(w & (-w))+r);
    }
    else if (lena==1 && a[0]==0) return 0;
    else
    {   std::size_t r=0, i=0;
        while (a[i++]==0) r += 64;
        std::uint64_t w = a[i-1];
        return static_cast<std::size_t>(64-nlz(w & (-w))+r);
    }
}

inline std::size_t Low_bit::op(std::int64_t aa)
{   std::uint64_t a;
    if (aa == 0) return 0;
    else if (aa < 0) a = ~static_cast<std::uint64_t>(aa);
    else a = aa;
    a = a & (-a); // keeps only the lowest bit
    return static_cast<std::size_t>(64-nlz(a));
}

inline std::size_t Logcount::op(std::uint64_t *a)
{   std::size_t lena = number_size(a);
    std::size_t r = 0;
    if (negative(a[lena-1]))
    {   for (std::size_t i=0; i<lena; i++) r += popcount(~a[i]);
    }
    else for (std::size_t i=0; i<lena; i++) r += popcount(a[i]);
    return r;
}

inline std::size_t Logcount::op(std::int64_t a)
{   if (a < 0) return static_cast<std::size_t>(popcount(~a));
    else return static_cast<std::size_t>(popcount(a));
}

inline bool Logbitp::op(std::uint64_t *a, std::size_t n)
{   std::size_t lena = number_size(a);
    if (n >= 64*lena) return negative(a[lena-1]);
    return (a[n/64] & (static_cast<std::uint64_t>(1) << (n%64))) != 0;
}

inline bool Logbitp::op(std::int64_t a, std::size_t n)
{   if (n >= 64) return (a < 0);
    else return (a & (static_cast<std::uint64_t>(1) << n)) != 0;
}

// Addition when the length of a is art least than that of b.

inline void ordered_bigplus(const std::uint64_t *a, std::size_t lena,
                            const std::uint64_t *b, std::size_t lenb,
                            std::uint64_t *r, std::size_t &lenr)
{   arithlib_assert(lena >= lenb);
    std::uint64_t carry = 0;
    std::size_t i = 0;
// The lowest digits can be added without there being any carry-in.
    carry = add_with_carry(a[0], b[0], r[0]);
// Add the digits that (a) and (b) have in common
    for (i=1; i<lenb; i++)
        carry = add_with_carry(a[i], b[i], carry, r[i]);
// From there on up treat (b) as if it had its sign bit extended to the
// left.
    std::uint64_t topb = negative(b[lenb-1]) ? allbits : 0;
    for (; i<lena; i++)
        carry = add_with_carry(a[i], topb, carry, r[i]);
// And of course (a) must also be treated as being extended by its sign bit.
    std::uint64_t topa = negative(a[lena-1]) ? allbits : 0;
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

inline void bigplus_small(const std::uint64_t *a, std::size_t lena,
                          std::int64_t n,
                          std::uint64_t *r, std::size_t &lenr)
{   std::uint64_t w[1];
    w[0] = static_cast<std::uint64_t>(n);
    ordered_bigplus(a, lena, w, 1, r, lenr);
}

// When I do a general addition I will not know which input is longer.

inline void bigplus(const std::uint64_t *a, std::size_t lena,
                    const std::uint64_t *b, std::size_t lenb,
                    std::uint64_t *r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_bigplus(a, lena, b, lenb, r,
                                 lenr);
    else return ordered_bigplus(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Plus::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n;
    if (lena >= lenb) n = lena+1;
    else n = lenb+1;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
    bigplus(a, lena, b, lenb, p, final_n);
    return confirm_size(p, n, final_n);
}

// At present I implement the op_ii, opt_ib and opt_bi operations
// by converting the integer argument to a 1-word bignum and dropping into
// the general bignum code. This will generally be a long way from the
// most efficient implementation, so at a later stage I will want to hone
// the code to make it better!

inline std::intptr_t Plus::op(std::int64_t a, std::int64_t b)
{
// The two integer arguments will in fact each have been derived from a
// tagged representation, and a consequence of that is that I can add
// them and be certain I will not get arithmetic overflow. However the
// resulting value may no longer be representable as a fixnum.
    std::int64_t c = a + b;
    if (fits_into_fixnum(c)) return int_to_handle(c);
// Now because there had not been overflow I know that the bignum will
// only need one word.
    std::uint64_t *r = reserve(1);
    r[0] = c;
    return confirm_size(r, 1, 1);
}

inline std::intptr_t Plus::op(std::int64_t a, std::uint64_t *b)
{   std::uint64_t aa[1];
    aa[0] = a;
    std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *r = reserve(lenb+1);
    pop(b);
    std::size_t final_n;
    bigplus(aa, 1, b, lenb, r, final_n);
    return confirm_size(r, lenb+1, final_n);
}

inline std::intptr_t Plus::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    std::uint64_t bb[1];
    bb[0] = b;
    push(a);
    std::uint64_t *r = reserve(lena+1);
    pop(a);
    std::size_t final_n;
    bigplus(a, lena, bb, 1, r, final_n);
    return confirm_size(r, lena+1, final_n);
}

inline std::intptr_t bigplus_small(std::intptr_t aa, std::int64_t b)
{   std::uint64_t *a = vector_of_handle(aa);
    std::size_t lena = number_size(a);
    push(a);
    std::uint64_t *p = reserve(lena+1);
    pop(a);
    std::size_t final_n;
    bigplus_small(a, lena, b, p, final_n);
    return confirm_size(p, lena+1, final_n);
}

// For subtraction I implement both a-b and b-a. These work by
// computing a + (~b) + 1 and (~a) + b + 1 respectively.

inline void ordered_bigsubtract(const std::uint64_t *a,
                                std::size_t lena,
                                const std::uint64_t *b, std::size_t lenb,
                                std::uint64_t *r, std::size_t &lenr)
{   arithlib_assert(lena >= lenb);
    std::uint64_t carry = 1;
    std::size_t i;
// Add the digits that (a) and (b) have in common
    for (i=0; i<lenb; i++)
        carry = add_with_carry(a[i], ~b[i], carry, r[i]);
// From there on up treat (b) as if it had its sign bit extended to the
// left.
    std::uint64_t topb = negative(~b[lenb-1]) ? allbits : 0;
    for (; i<lena; i++)
        carry = add_with_carry(a[i], topb, carry, r[i]);
// And of course (a) must also be treated as being extended by its sign bit.
    std::uint64_t topa = negative(a[lena-1]) ? allbits : 0;
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

inline void ordered_bigrevsubtract(const std::uint64_t *a,
                                   std::size_t lena,
                                   const std::uint64_t *b, std::size_t lenb,
                                   std::uint64_t *r, std::size_t &lenr)
{   arithlib_assert(lena >= lenb);
    std::uint64_t carry = 1;
    std::size_t i;
// Add the digits that (a) and (b) have in common
    for (i=0; i<lenb; i++)
        carry = add_with_carry(~a[i], b[i], carry, r[i]);
// From there on up treat (b) as if it had its sign bit extended to the
// left.
    std::uint64_t topb = negative(b[lenb-1]) ? allbits : 0;
    for (; i<lena; i++)
        carry = add_with_carry(~a[i], topb, carry, r[i]);
// And of course (a) must also be treated as being extended by its sign bit.
    std::uint64_t topa = negative(~a[lena-1]) ? allbits : 0;
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

inline void bigsubtract_small(const std::uint64_t *a,
                              std::size_t lena,
                              std::int64_t n,
                              std::uint64_t *r, std::size_t &lenr)
{   std::uint64_t w[1];
    w[0] = static_cast<std::uint64_t>(n);
    ordered_bigsubtract(a, lena, w, 1, r, lenr);
}

// subtract a bignum from a small number

inline void bigrevsubtract_small(const std::uint64_t *a,
                                 std::size_t lena,
                                 std::int64_t n,
                                 std::uint64_t *r, std::size_t &lenr)
{   std::uint64_t w[1];
    w[0] = static_cast<std::uint64_t>(n);
    ordered_bigrevsubtract(a, lena, w, 1, r, lenr);
}


inline void bigsubtract(const std::uint64_t *a, std::size_t lena,
                        const std::uint64_t *b, std::size_t lenb,
                        std::uint64_t *r, std::size_t &lenr)
{   if (lena >= lenb) return ordered_bigsubtract(a, lena, b, lenb, r,
                                 lenr);
    else return ordered_bigrevsubtract(b, lenb, a, lena, r, lenr);
}

inline std::intptr_t Difference::op(std::uint64_t *a,
                                    std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n;
    if (lena >= lenb) n = lena+1;
    else n = lenb+1;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
    bigsubtract(a, lena, b, lenb, p, final_n);
    return confirm_size(p, n, final_n);
}

inline std::intptr_t Difference::op(std::int64_t a, std::int64_t b)
{   std::uint64_t aa[1], bb[1];
    aa[0] = a;
    bb[0] = b;
    std::uint64_t *r = reserve(2);
    std::size_t final_n;
    bigsubtract(aa, 1, bb, 1, r, final_n);
    return confirm_size(r, 2, final_n);
}

inline std::intptr_t Difference::op(std::int64_t a, std::uint64_t *b)
{   std::uint64_t aa[1];
    aa[0] = a;
    std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *r = reserve(lenb+1);
    pop(b);
    std::size_t final_n;
    bigsubtract(aa, 1, b, lenb, r, final_n);
    return confirm_size(r, lenb+1, final_n);
}

inline std::intptr_t Difference::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    std::uint64_t bb[1];
    bb[0] = b;
    push(a);
    std::uint64_t *r = reserve(lena+1);
    pop(a);
    std::size_t final_n;
    bigsubtract(a, lena, bb, 1, r, final_n);
    return confirm_size(r, lena+1, final_n);
}


inline std::intptr_t RevDifference::op(std::uint64_t *a,
                                       std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n;
    if (lena >= lenb) n = lena+1;
    else n = lenb+1;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
    bigsubtract(b, lenb, a, lena, p, final_n);
    return confirm_size(p, n, final_n);
}

inline std::intptr_t RevDifference::op(std::int64_t a, std::int64_t b)
{   std::uint64_t aa[1], bb[1];
    aa[0] = a;
    bb[0] = b;
    std::uint64_t *r = reserve(2);
    std::size_t final_n;
    bigsubtract(bb, 1, aa, 1, r, final_n);
    return confirm_size(r, 2, final_n);
}

inline std::intptr_t RevDifference::op(std::int64_t a,
                                       std::uint64_t *b)
{   std::uint64_t aa[1];
    aa[0] = a;
    std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *r = reserve(lenb+1);
    pop(b);
    std::size_t final_n;
    bigsubtract(b, lenb, aa, 1, r, final_n);
    return confirm_size(r, lenb+1, final_n);
}

inline std::intptr_t RevDifference::op(std::uint64_t *a,
                                       std::int64_t b)
{   std::size_t lena = number_size(a);
    std::uint64_t bb[1];
    bb[0] = b;
    push(a);
    std::uint64_t *r = reserve(lena+1);
    pop(a);
    std::size_t final_n;
    bigsubtract(bb, 1, a, lena, r, final_n);
    return confirm_size(r, lena+1, final_n);
}

//=========================================================================
//=========================================================================
// multiplication, squaring and exponentiation.
//=========================================================================
//=========================================================================

// This multiplication code took much longer to write and debug than I had
// expected. Classical multiplication was straightforward to implement,
// but then while Karatsuba is at its heart simple, fitting it into a
// framework where inputs of unequal size can be combined leaves much
// opportunity for mistakes to creep in. Along with that I view this as
// speed-critical, so I take a number of special cases and implement them
// directly rather than via the general code. The earlier drafts of this
// I had ended up with code that was even more tangled and untidy then the
// present version!
// I experimented with versions of classical multiplication that worked using
// pairs of digits at once (and that did not seem to help me), and for
// Karatsuba I tried both a version based and adding the high ane low parts
// of input numbers and the version here that subtracts them.
// Ensuring that the twos complement treatment of signs is supported adds
// further potential confusion!



//                       Karatsuba multiplication.
//                       =========================

// The multiplication code has a signature something like
//   void mult(uint64_t *a, size_t lena,
//             uint64_t *b, size_t lenb,
//             uint64_t *c,
//             uint64_t *work_vector=NULL)
// where a and b are vectors with lena and lenb words in then respectively.
// c is a vector and lena+lenb words of a product will be written into it.
// Note that sometimes the top digit will end up as either 0 or -1.
// w must be a workspace vector of length lenb+2*log(lenb) [the log is to
// the base 2]. It is not needed if lenb is very short.
//

// For use within the multiplication code I need variants on my
// addition and subtraction code.

// I want:
//    kadd(a, lena, c, lenc);          // c += a

inline std::uint64_t kadd(const std::uint64_t *a, std::size_t lena,
                          std::uint64_t *c, std::size_t lenc,
                          std::uint64_t carry=0)
{   std::size_t i;
    for (i=0; i<lena; i++)
        carry = add_with_carry(a[i], c[i], carry, c[i]);
    while (carry!=0 && i<lenc)
    {   carry = add_with_carry(c[i], carry, c[i]);
        i++;
    }
    return carry;
}

// c = a - b.   must have length(a) >= length(b).

inline std::uint64_t ksub(const std::uint64_t *a, std::size_t lena,
                          const std::uint64_t *b, std::size_t lenb,
                          std::uint64_t *c)
{   arithlib_assert(lena >= lenb);
    std::uint64_t borrow = 0;
    std::size_t i;
    for (i=0; i<lenb; i++)
        borrow = subtract_with_borrow(a[i], b[i], borrow, c[i]);
    for (; i<lena; i++)
        borrow = subtract_with_borrow(a[i], borrow, c[i]);
    return borrow;
}

inline void kneg(std::uint64_t *a, std::size_t lena)
{   std::uint64_t carry = 0;
    for (std::size_t i=0; i<lena; i++)
        a[i] = add_with_carry(~a[i], carry, a[i]);
}

// c = |a - b| and return an indication of which branch of the absolute
// value function was used, ie whether we had a>=b or a<b. If a==b so
// the result is zero the value is not terribly important. Must be
// called with the first argument at least as long as the second.

inline bool absdiff(const std::uint64_t *a, std::size_t lena,
                    const std::uint64_t *b, std::size_t lenb,
                    std::uint64_t *c)
{
// I will do a cheap comparison of a and b first, based on an understanding
// that lena >= lenb. The result will be of length lena.
    arithlib_assert(lena >= lenb);
    if (lenb < lena ||
        b[lenb-1]<=a[lena-1])
    {
// If my cheap test suggests that a is the smaller one then I form (b-a).
// If that generates a borrow my "guess" was wrong, so I negate the
// result. For fully random inputs the cheap test is liable to be reliable.
// for values that have long sequences of 0 bits in their binary
// representation, eg values that are close to a power of 2 or ones that
// have a large power of 2 as a factor, the fallback may be activated
// more frequently.
        if (ksub(a, lena, b, lenb, c) != 0)
        {   kneg(c, lena);
            return true;     // Have computed b-a
        }
        else return false;   // have computed a-b
    }
    else
    {   if (ksub(b, lenb, a, lena, c) != 0)
        {   kneg(c, lenb);
            return false;    // a-b
        }
        else return true;    // b-a
    }
}

// I will have in-line code for a number of very small case on the
// expectation that (a) these will arise expecially often in many
// applications and (b) that the inline code will end up faster
// then general loops.

// Now code that multiplies 2-digit numbers together.
// One version treats them as unsigned, the second as signed.

inline void mul2x2(std::uint64_t a1, std::uint64_t a0,
                   std::uint64_t b1, std::uint64_t b0,
                   std::uint64_t &c3, std::uint64_t &c2, std::uint64_t &c1,
                   std::uint64_t &c0)
{   std::uint64_t c1a, c2a, c2b, c3a;
    multiply64(a0, b0, c1a, c0);
    multiply64(a0, b1, c1a, c2a, c1a);
    multiply64(a1, b0, c1a, c2b, c1);
    multiply64(a1, b1, c2a, c3a, c2a);
    c3a += add_with_carry(c2a, c2b, c2);
    c3 = c3a;
}

inline void mul2x2S(std::int64_t a1, std::uint64_t a0,
                    std::int64_t b1, std::uint64_t b0,
                    std::int64_t &c3, std::uint64_t &c2, std::uint64_t &c1,
                    std::uint64_t &c0)
{   std::uint64_t c1a;
    multiply64(a0, b0, c1a, c0);
    std::uint64_t c2a;
    multiply64(a0, static_cast<std::uint64_t>(b1), c1a, c2a, c1a);
    std::uint64_t c2b;
    multiply64(static_cast<std::uint64_t>(a1), b0, c1a, c2b, c1);
    std::int64_t c3a;
    signed_multiply64(a1, b1, c2a, c3a, c2a);
    c3a = static_cast<std::int64_t>(
              static_cast<std::uint64_t>(c3a) + add_with_carry(c2a, c2b, c2a));
// Do the arithmetic in unsigned mode in case of overflow problems.
    if (a1 < 0) c3a = static_cast<std::int64_t>(
                              static_cast<std::uint64_t>(c3a) -
                              subtract_with_borrow(c2a, b0, c2a));
    if (b1 < 0) c3a = static_cast<std::int64_t>(
                              static_cast<std::uint64_t>(c3a) -
                              subtract_with_borrow(c2a, a0, c2a));
    c2 = c2a;
    c3 = c3a;
}

inline void mul3x2(std::uint64_t a2, std::uint64_t a1,
                   std::uint64_t a0,
                   std::uint64_t b1, std::uint64_t b0,
                   std::uint64_t &c4, std::uint64_t &c3, std::uint64_t &c2,
                   std::uint64_t &c1, std::uint64_t &c0)
{   std::uint64_t c3a;
    mul2x2(a1, a0, b1, b0, c3, c2, c1, c0);
    multiply64(a2, b0, c2, c3a, c2);
    std::uint64_t carry = add_with_carry(c3, c3a, c3);
    multiply64(a2, b1, c3, c4, c3);
    c4 += carry;
}

inline void mul3x3(std::uint64_t a2, std::uint64_t a1,
                   std::uint64_t a0,
                   std::uint64_t b2, std::uint64_t b1, std::uint64_t b0,
                   std::uint64_t &c5, std::uint64_t &c4, std::uint64_t &c3,
                   std::uint64_t &c2, std::uint64_t &c1, std::uint64_t &c0)
{   std::uint64_t c4a, c3a;
    mul2x2(a1, a0, b1, b0, c3, c2, c1, c0);
    multiply64(a2, b0, c2, c3a, c2);
    std::uint64_t carry = add_with_carry(c3, c3a, c3);
    multiply64(a0, b2, c2, c3a, c2);
    carry += add_with_carry(c3, c3a, c3);
    multiply64(a2, b1, c3, c4, c3);
    carry = add_with_carry(c4, carry, c4);
    multiply64(a1, b2, c3, c4a, c3);
    carry = add_with_carry(c4, c4a, c4);
    multiply64(static_cast<std::int64_t>(a2),
               static_cast<std::int64_t>(b2), c4, c5, c4);
    c5 = static_cast<std::int64_t>(static_cast<std::uint64_t>
                                   (c5) + carry);
}

inline void mul3x3S(std::uint64_t a2, std::uint64_t a1,
                    std::uint64_t a0,
                    std::uint64_t b2, std::uint64_t b1, std::uint64_t b0,
                    std::int64_t &c5, std::uint64_t &c4, std::uint64_t &c3,
                    std::uint64_t &c2, std::uint64_t &c1, std::uint64_t &c0)
{   std::uint64_t c4a, c3a;
    mul2x2(a1, a0, b1, b0, c3, c2, c1, c0);
    multiply64(a2, b0, c2, c3a, c2);
    std::uint64_t carry = add_with_carry(c3, c3a, c3);
    multiply64(a0, b2, c2, c3a, c2);
    carry += add_with_carry(c3, c3a, c3);
    multiply64(a2, b1, c3, c4, c3);
    carry = add_with_carry(c4, carry, c4);
    multiply64(a1, b2, c3, c4a, c3);
    carry += add_with_carry(c4, c4a, c4);
    signed_multiply64(static_cast<std::int64_t>(a2),
                      static_cast<std::int64_t>(b2), c4, c5, c4);
    c5 = static_cast<std::int64_t>(static_cast<std::uint64_t>
                                   (c5) + carry);
    if (negative(b2))
    {   std::uint64_t borrow = subtract_with_borrow(c3, a0, c3);
        borrow = subtract_with_borrow(c4, a1, borrow, c4);
        c5 = static_cast<std::int64_t>(
                 static_cast<std::uint64_t>(c5) - borrow);
    }
    if (negative(a2))
    {   std::uint64_t borrow = subtract_with_borrow(c3, b0, c3);
        borrow = subtract_with_borrow(c4, b1, borrow, c4);
        c5 = static_cast<std::int64_t>(
                 static_cast<std::uint64_t>(c5) - borrow);
    }
}

inline void mul4x4(std::uint64_t a3, std::uint64_t a2,
                   std::uint64_t a1,
                   std::uint64_t a0,
                   std::uint64_t b3, std::uint64_t b2, std::uint64_t b1,
                   std::uint64_t b0,
                   std::uint64_t &c7, std::uint64_t &c6, std::uint64_t &c5,
                   std::uint64_t &c4,
                   std::uint64_t &c3, std::uint64_t &c2, std::uint64_t &c1,
                   std::uint64_t &c0)
{   std::uint64_t w7, w6, w5a, w5b, w5c, w4a, w4b, w4c,
    w3a, w3b, w3c, w2a, w2b, w2c;
    mul2x2(a1, a0, b1, b0, w3a, w2a, c1, c0);
    mul2x2(a1, a0, b3, b2, w5a, w4a, w3b, w2b);
    mul2x2(a3, a2, b1, b0, w5b, w4b, w3c, w2c);
    mul2x2(a3, a2, b3, b2, w7, w6, w5c, w4c);
    std::uint64_t carry = add_with_carry(w2a, w2b, w2c, c2);
    carry = add_with_carry(w3a, w3b, w3c, carry, c3);
    carry = add_with_carry(w4a, w4b, w4c, carry, c4);
    carry = add_with_carry(w5a, w5b, w5c, carry, c5);
    carry = add_with_carry(w6, carry, c6);
    c7 = w7 + carry;
}

// c = a*b;

// This forms a product digit by digit.

inline void classical_multiply(const std::uint64_t *a,
                               std::size_t lena,
                               const std::uint64_t *b, std::size_t lenb,
                               std::uint64_t *c)
{   if (lena < lenb)
    {   std::swap(a, b);
        std::swap(lena, lenb);
    }
// (1) do the lowest degree term as a separate step
    std::uint64_t carry=0, hi, hi1, lo;
    multiply64(b[0], a[0], lo, c[0]);
// Now a sequence of stages where at each the number of terms to
// be combined grows.
    hi = 0;
    for (std::size_t i=1; i<lenb; i++)
    {   carry = 0;
        for (std::size_t j=0; j<=i; j++)
        {   multiply64(b[j], a[i-j], lo, hi1, lo);
            carry += add_with_carry(hi, hi1, hi);
        }
        c[i] = lo;
        lo = hi;
        hi = carry;
    }
// If the two inputs are not the same size I demand that lena>=lenb and
// there may be some slices to compute in the middle here.
// if lena==lenb the following loop does not get executed at all.
    for (std::size_t i=lenb; i<lena; i++)
    {   carry = 0;
        for (std::size_t j=0; j<lenb; j++)
        {   multiply64(b[j], a[i-j], lo, hi1, lo);
            carry += add_with_carry(hi, hi1, hi);
        }
        c[i] = lo;
        lo = hi;
        hi = carry;
    }
// Now I will have some stages where the number of terms to be combined
// gradually decreases. If lenb==2 the following loop is not executed.
    for (std::size_t i=1; i<lenb-1; i++)
    {   carry = 0;
        for (std::size_t j=0; j<lenb-i; j++)
        {   multiply64(b[i+j], a[lena-j-1], lo, hi1, lo);
            carry += add_with_carry(hi, hi1, hi);
        }
        c[lena+i-1] = lo;
        lo = hi;
        hi = carry;
    }
// Finally the very top term is computed.
    multiply64(b[lenb-1], a[lena-1], lo, hi1, c[lena+lenb-2]);
    c[lena+lenb-1] = hi + hi1;
}


// c = c + a*b. Potentially carry all the way up to lenc.

inline void classical_multiply_and_add(const std::uint64_t *a,
                                       std::size_t lena,
                                       const std::uint64_t *b, std::size_t lenb,
                                       std::uint64_t *c, std::size_t lenc)
{   if (lena < lenb)
    {   std::swap(a, b);
        std::swap(lena, lenb);
    }
// (1) do the lowest degree term as a separate step
    std::uint64_t carry=0, carry1, hi, hi1, lo;
    multiply64(b[0], a[0], c[0], lo, c[0]);
// Now a sequence of stages where at each the number of terms to
// be combined grows.
    hi = 0;
    for (std::size_t i=1; i<lenb; i++)
    {   carry = 0;
        for (std::size_t j=0; j<=i; j++)
        {   multiply64(b[j], a[i-j], lo, hi1, lo);
            carry += add_with_carry(hi, hi1, hi);
        }
        carry1 = add_with_carry(c[i], lo, c[i]);
        hi = add_with_carry(hi, carry1, lo) + carry;
    }
// If the two inputs are not the same size I demand that lena>=lenb and
// there may be some slices to compute in the middle here.
    for (std::size_t i=lenb; i<lena;
         i++)  //  If lenb==lena this loop is not executed
    {   carry = 0;
        for (std::size_t j=0; j<lenb; j++)
        {   multiply64(b[j], a[i-j], lo, hi1, lo);
            carry += add_with_carry(hi, hi1, hi);
        }
        carry1 = add_with_carry(c[i], lo, c[i]);
        hi = add_with_carry(hi, carry1, lo) + carry;
    }
// Now I will have some stages where the number of terms to be combined
// gradually decreases.
    for (std::size_t i=1; i<lenb-1;
         i++) //  If lenb==2 this loop is not executed
    {   carry = 0;
        for (std::size_t j=0; j<lenb-i; j++)
        {   multiply64(b[i+j], a[lena-j-1], lo, hi1, lo);
            carry += add_with_carry(hi, hi1, hi);
        }
        carry1 = add_with_carry(c[lena+i-1], lo, c[lena+i-1]);
        hi = add_with_carry(hi, carry1, lo) + carry;
    }
// Finally the very top term is computed.
    multiply64(b[lenb-1], a[lena-1], lo, hi1, lo);
    carry = add_with_carry(c[lena+lenb-2], lo, c[lena+lenb-2]);
    carry = add_with_carry(c[lena+lenb-1], hi+hi1, carry, c[lena+lenb-1]);
    for (std::size_t i=lena+lenb; carry!=0 && i<lenc; i++)
        carry = add_with_carry(c[i], carry, c[i]);
}

// Now variants that use just a single digit first argument. These may be seen
// as optimized cases.

inline void classical_multiply(std::uint64_t a,
                               const std::uint64_t *b, std::size_t lenb,
                               std::uint64_t *c)
{   std::uint64_t hi=0;
    for (std::size_t j=0; j<lenb; j++)
        multiply64(a, b[j], hi, hi, c[j]);
    c[lenb] = hi;
}

// c = c + a*b and return any carry.

inline void classical_multiply_and_add(std::uint64_t a,
                                       const std::uint64_t *b, std::size_t lenb,
                                       std::uint64_t *c, std::size_t lenc)
{   std::uint64_t hi=0, lo;
    for (std::size_t j=0; j<lenb; j++)
    {   multiply64(a, b[j], hi, hi, lo);
        hi += add_with_carry(lo, c[j], c[j]);
    }
    std::uint64_t carry = add_with_carry(hi, c[lenb], c[lenb]);
    for (std::size_t i=lenb+1; carry!=0 && i<lenc; i++)
        carry = add_with_carry(c[i], carry, c[i]);
}

// I make the variables that indicate when it is worth transitioning from
// classical multiplication to something that is assymptotically faster
// static rather than inline because if different overrides are provided
// via the command line definitions when different source files are
// being processed that could cause linker clashes otherwise.


#if !defined K && !defined K_DEFINED
// I provide a default here but can override it at compile time
static const std::size_t K=18;
#define K_DEFINED 1
#endif

// When I have completed and measured things I am liable to make this a
// "const", but for now it is a simple variable so I can tinker with the
// value during testing and tuning.

#ifndef KARATSUBA_CUTOFF
// It may be defined globally as a severe override of what happens here!
static std::size_t KARATSUBA_CUTOFF = K;
#endif

#if !defined K1 && !defined K1_DEFINED
// I provide a default here but can override it at compile time.

static const std::size_t K1=170;
#define K1_DEFINED 1
#endif

// When I have completed and measured things I am liable to make this a
// "const", but for now it is a simple variable so I can tinker with the
// value during testing and tuning.

#ifndef PARAKARA_CUTOFF
// It may be defined globally as a severe override of what happens here!
// But also if the current host computer does not support at least three
// genuine concurrent activities I will not try use of threads because it
// would not be helpful!

static std::size_t PARAKARA_CUTOFF =
    std::thread::hardware_concurrency() >= 3 ? K1 : SIZE_MAX;
#endif

inline void small_or_big_multiply(const std::uint64_t *a,
                                  std::size_t lena,
                                  const std::uint64_t *b, std::size_t lenb,
                                  std::uint64_t *c, std::uint64_t *w);

inline void small_or_big_multiply_and_add(const std::uint64_t *a,
        std::size_t lena,
        const std::uint64_t *b, std::size_t lenb,
        std::uint64_t *c, std::size_t lenc,
        std::uint64_t *w);

// The key function here multiplies two numbers that are at least almost
// the same length. The cases that can arise here are
//      2n   2n       Easy and neat sub-division
//      2n   2n-1     Treat the second number as if it has a padding zero
//      2n-1 2n-1     Treat both numbers as if padded to size 2n
// Observe that if the two numbers have different lengths then the longer
// one is an even length, so the case (eg) 2n+1,2n will not arise.
// This will also only be used if lenb >= KARATSUBA_CUTOFF.

// When one multiplies {a1,a0}*{b1,b0} the three sub-multiplications to
// be performed are
//         a1*b1, a0*b0, |a0-a1|*|b0-b1|


inline void karatsuba(const std::uint64_t *a, std::size_t lena,
                      const std::uint64_t *b, std::size_t lenb,
                      std::uint64_t *c, std::uint64_t *w)
{   arithlib_assert(lena == lenb ||
                    (lena%2 == 0 && lenb == lena-1));
    arithlib_assert(lena >= 2);
    std::size_t n = (lena+1)/2;    // size of a "half-number"
    std::size_t lenc = lena+lenb;
// lena-n and lenb-n will each be either n or n-1.
    if (absdiff(a, n, a+n, lena-n, w) !=
        absdiff(b, n, b+n, lenb-n, w+n))
    {
// Here I will collect
//    a1*b1    (a1*b0 + b1*a0 - a1*b1 - a0*b0)     a0*b0
// First write the middle part into place.
        small_or_big_multiply(w, n, w+n, n, c+n,
                              w+2*n);     // (a1-a0)*(b0-b1)
// Now I just need to add back in parts of the a1*b1 and a0*b0
        small_or_big_multiply(a+n, lena-n, b+n, lenb-n, w, w+2*n); // a1*b1
// First insert the copy at the very top. Part can just be copied because I
// have not yet put anything into c there, the low half then has to be added
// in (and carries could propagate all the way up).
        for (std::size_t i=n; i<lenc-2*n; i++) c[2*n+i] = w[i];
        kadd(w, n, c+2*n, lenc-2*n);
// Now add in the second copy
        kadd(w, lenc-2*n, c+n, lenc-n);
// Now I can deal with the a0*b0.
        small_or_big_multiply(a, n, b, n, w, w+2*n);               // a0*b0
        for (std::size_t i=0; i<n; i++) c[i] = w[i];
        kadd(w+n, n, c+n, lenc-n);
        kadd(w, 2*n, c+n, lenc-n);
    }
    else
    {
// This case is slightly more awkward because the key parts of the middle
// part are negated.
//    a1*b1    (-a1*b0 - b1*a0 + a1*b1 + a0*b0)     a0*b0
        small_or_big_multiply(w, n, w+n, n, c+n,
                              w+2*n);     // (a1-a0)*(b1-b0)
        small_or_big_multiply(a+n, lena-n, b+n, lenb-n, w, w+2*n); // a1*b1
        for (std::size_t i=n; i<lenc-2*n; i++) c[2*n+i] = w[i];
// Now I will do {c3,c2,c1} = {c3,w0,0} - {0,c2,c1) which has a mere negation
// step for the c1 digit, but is otherwise a reverse subtraction. Note I had
// just done c3 = w1 so that first term on the RHS is "really" {w1,w0,0}.
//      c1 = 0 - c1 [and generate borrow]
//      c2 = w0 - c2 - borrow [and generate borrow]
//      c3 = c3 - borrow
        std::uint64_t borrow = 0;
        for (std::size_t i=0; i<n; i++)
            borrow = subtract_with_borrow(0, c[n+i], borrow, c[n+i]);
        for (std::size_t i=0; i<n; i++)
            borrow = subtract_with_borrow(w[i], c[2*n+i], borrow, c[2*n+i]);
        for (std::size_t i=0; i<lenc-3*n && borrow!=0; i++)
            borrow = subtract_with_borrow(c[3*n+i], borrow, c[3*n+i]);
// Now I can proceed as before
        kadd(w, lenc-2*n, c+n, lenc-n);
        small_or_big_multiply(a, n, b, n, w, w+2*n);               // a0*b0
        for (std::size_t i=0; i<n; i++) c[i] = w[i];
        kadd(w+n, n, c+n, lenc-n);
        kadd(w, 2*n, c+n, lenc-n);
    }
}

// The worker_thread() function is started in each of two threads, and
// processes requests until a "quit" request is sent to it.

inline void worker_thread(Worker_data *wd)
{
#ifdef USE_MICROSOFT_MUTEX
    WaitForSingleObject(wd->mutex[2], 0xffffffff);
    WaitForSingleObject(wd->mutex[3], 0xffffffff);
#else
    wd->mutex[2].lock();
    wd->mutex[3].lock();
#endif
    wd->ready = true;
    int receive_count = 0;
    for (;;)
    {
#ifdef USE_MICROSOFT_MUTEX
        WaitForSingleObject(wd->mutex[receive_count], 0xffffffff);
#else
        wd->mutex[receive_count].lock();
#endif
        if (wd->quit_flag) return;
// This is where I do some work!
        small_or_big_multiply(wd->a, wd->lena,
                              wd->b, wd->lenb,
                              wd->c, wd->w);
#ifdef USE_MICROSOFT_MUTEX
        ReleaseMutex(wd->mutex[receive_count^2]);
#else
        wd->mutex[receive_count^2].unlock();
#endif
        receive_count = (receive_count + 1) & 3;
    }
}

inline void top_level_karatsuba(const std::uint64_t *a,
                                std::size_t lena,
                                const std::uint64_t *b, std::size_t lenb,
                                std::uint64_t *c, std::uint64_t *w,
                                std::uint64_t *w0, std::uint64_t *w1)
{
// Here I have a HUGE case and I should use threads!
    arithlib_assert(lena == lenb ||
                    (lena%2 == 0 && lenb == lena-1));
    arithlib_assert(lena >= 2);
    std::size_t n = (lena+1)/2;    // size of a "half-number"
    std::size_t lenc = lena+lenb;
// I start by arranging that the two threads that can do things in parallel
// can get access to data from here and that I will be able to retrieve
// results. And that the worker threads have workspace to make use of.
    driver_data::get().wd_0.a = a;
    driver_data::get().wd_0.lena = n;
    driver_data::get().wd_0.b = b;
    driver_data::get().wd_0.lenb = n;
    driver_data::get().wd_0.c = w0;
    driver_data::get().wd_0.w = w0+2*n;

    driver_data::get().wd_1.a = a+n;
    driver_data::get().wd_1.lena = lena-n;
    driver_data::get().wd_1.b = b+n;
    driver_data::get().wd_1.lenb = lenb-n;
    driver_data::get().wd_1.c = w1;
    driver_data::get().wd_1.w = w1+2*n;

// Now trigger the two threads to do some work for me. One will be forming
// alo*blo while the other computes ahi*bhi .
    driver_data::get().release_workers();
// Now I will work on either |ahi-alo|*|bhi-blo|
// lena-n and lenb-n will each be either n or n-1.
    bool signs_differ = absdiff(a, n, a+n, lena-n, w) !=
                        absdiff(b, n, b+n, lenb-n, w+n);
    small_or_big_multiply(w, n, w+n, n, c+n,
                          w+2*n);     // (a1-a0)*(b0-b1)
// That has the product of differences written into the middle of c.
    driver_data::get().wait_for_workers();
    if (signs_differ)
    {
// Here I have
//     w0:             ;              ;           alo*blo [2*n]
//     w1:      ahi*bhi [lenc-2*n]    ;                   ;
//     c:     ?[lenc-n];     (ahi-alo)*(blo-bhi)[2n]      ;    ?[n]
//          =         ?; ahi*blo+bhi*alo -ahi*bhi-alo*blo ;    ?[n]
// so I need to add bits from w0 and w1 into c.
//
// First deal with ahi*bhi. The top half can be copied into the very top of
// the result, then I add in the bottom half.
        for (std::size_t i=n; i<lenc-2*n; i++) c[2*n+i] = w1[i];
        kadd(w1, n, c+2*n, lenc-2*n);
// Now add in the second copy of ahi*bhi
        kadd(w1, lenc-2*n, c+n, lenc-n);
// Now something similar with alo*blo
        for (std::size_t i=0; i<n; i++) c[i] = w0[i];
        kadd(w0+n, n, c+n, lenc-n);
        kadd(w0, 2*n, c+n, lenc-n);
    }
    else
    {
// This case is slightly more awkward because the key parts of the middle
// part are negated.
//    a1*b1    (-a1*b0 - b1*a0 + a1*b1 + a0*b0)     a0*b0
// Call the desired result {c3,c2,c1,c0} then the middle product is in
// {c2,c1} and I can copy the top half of ahi*bhi into c3.
        for (std::size_t i=n; i<lenc-2*n; i++) c[2*n+i] = w1[i];
// Now I will do {c3,c2,c1} = {c3,low(ahi*bhi),0} - {0,c2,c1) which has a
// mere negation step for the c1 digit, but is otherwise a reverse
// subtraction. Note I had just done c3 = high(ahi*bhi) so that first term on
// the RHS is "really" {{ahi*bhi},0}.
//      c1 = 0 - c1 [and generate borrow]
//      c2 = low(w0) - c2 - borrow [and generate borrow]
//      c3 = c3 - borrow
        std::uint64_t borrow = 0;
        for (std::size_t i=0; i<n; i++)
            borrow = subtract_with_borrow(0, c[n+i], borrow, c[n+i]);
        for (std::size_t i=0; i<n; i++)
            borrow = subtract_with_borrow(w1[i], c[2*n+i], borrow, c[2*n+i]);
        for (std::size_t i=0; i<lenc-3*n && borrow!=0; i++)
            borrow = subtract_with_borrow(c[3*n+i], borrow, c[3*n+i]);
        kadd(w1, lenc-2*n, c+n, lenc-n);
        for (std::size_t i=0; i<n; i++) c[i] = w0[i];
        kadd(w0+n, n, c+n, lenc-n);
        kadd(w0, 2*n, c+n, lenc-n);
    }
}

inline void karatsuba_and_add(const std::uint64_t *a,
                              std::size_t lena,
                              const std::uint64_t *b, std::size_t lenb,
                              std::uint64_t *c, std::size_t lenc, std::uint64_t *w)
{   arithlib_assert(lena == lenb ||
                    (lena%2 == 0 && lenb == lena-1));
    arithlib_assert(lena >= 2);
    std::size_t n = (lena+1)/2;    // size of a "half-number"
    std::size_t lenc1 = lena+lenb;
    if (absdiff(a, n, a+n, lena-n, w) !=
        absdiff(b, n, b+n, lenb-n, w+n))
    {
// Here I will collect
//    a1*b1    (a1*b0 + b1*a0 - a1*b1 - a0*b0)     a0*b0
        small_or_big_multiply_and_add(w, n, w+n, n, c+n, lenc-n, w+2*n);
        small_or_big_multiply(a+n, lena-n, b+n, lenb-n, w, w+2*n); // a1*b1
        kadd(w, lenc1-2*n, c+2*n, lenc-2*n);
        kadd(w, lenc1-2*n, c+n, lenc-n);
        small_or_big_multiply(a, n, b, n, w, w+2*n);               // a0*b0
        kadd(w, 2*n, c, lenc);
        kadd(w, 2*n, c+n, lenc-n);
    }
    else
    {
// This case is slightly more awkward because the key parts of the middle
// part are negated.
//    a1*b1    (-a1*b0 - b1*a0 + a1*b1 + a0*b0)     a0*b0
// To perform c=c-w; I go c=~c; c=c+w; c=~c; [that is a NOT rather than
// a MINUS there!].
        for (std::size_t i=n; i<lenc; i++) c[i] = ~c[i];
        small_or_big_multiply_and_add(w, n, w+n, n, c+n, lenc-n, w+2*n);
        for (std::size_t i=n; i<lenc; i++) c[i] = ~c[i];
        small_or_big_multiply(a+n, lena-n, b+n, lenb-n, w, w+2*n); // a1*b1
        kadd(w, lenc1-2*n, c+2*n, lenc-2*n);
        kadd(w, lenc1-2*n, c+n, lenc-n);
        small_or_big_multiply(a, n, b, n, w, w+2*n);               // a0*b0
        kadd(w, 2*n, c, lenc);
        kadd(w, 2*n, c+n, lenc-n);
    }
}

// Here both inputs are of size at least KARATSUBA_CUTOFF. If their sizes
// match exactly I can use Karatsuba directly. I take the view that if
// the two are of sized (2n) and (2n-1) then I will also use Karatsuba
// directly (treating the shorter input as if it had an initial zero padding
// digit). In all other cases I need to do a sequence of multiplications
// rather along the lines of "short" multiplication treating the size of the
// smaller operand as the digit size.

inline void certainly_big_multiply(const std::uint64_t *a,
                                   std::size_t lena,
                                   const std::uint64_t *b, std::size_t lenb,
                                   std::uint64_t *c, std::uint64_t *w)
{   if (lena == lenb)
    {   karatsuba(a, lena, b, lenb, c, w);
        return;
    }
    if (lena < lenb)
    {   std::swap(a, b);
        std::swap(lena, lenb);
    }
// Now b is the shorter operand. The case (2n)*(2n-1) will be handled
// using Karatsuba merely by treating the smaller number as if padded with
// a leading zero.
    if (lena%2==0 && lenb==lena-1)
    {   karatsuba(a, lena, b, lenb, c, w);
        return;
    }
// If the two inputs are unbalanced in length I will perform multiple
// balanced operations each of which can be handled specially. I will
// try to make each subsidiary multiplication as big as possible.
// This will be lenb rounded up to an even number.
// I will be willing to do chunks that are of an even size that is
// either lenb or lenb+1.
    std::size_t len = lenb + (lenb & 1);
    const std::uint64_t *a1 = a;
    std::uint64_t *c1 = c;
    std::size_t lena1 = lena;
// Multiply-and-add will be (slightly) more expensive than just Multiply,
// so I do a sequence of multiplications where their outputs will not overlap
// first, and then do the interleaved multiplications adding in.
    for (;;)
    {
// I may have rounded the size of b up by 1, and if I have I would generate
// 2*len-1 digits not 2*len and hence risk leaving a 1-word gap between filled
// in data. I zero that here to avoid trouble. However I must not do this
// for if the multiplication I am about to do will write in the very top
// digits of the final answer, because if I did that would be a sort of
// buffer overrun.
        if (len < lena1) c1[2*len-1] = 0;
        karatsuba(a1, len, b, lenb, c1, w);
        c1 += 2*len;
// I will keep going provided the next multiplication I will do will fully fit.
        if (lena1 < 3*len) break;
        a1 += 2*len;
        lena1 -= 2*len;
    }
    if (lena1 > 2*len)
    {   a1 += 2*len;
        lena1 -= 2*len;
// Do a shorter nice Multiply (without Add) to reach the end of input a.
        small_or_big_multiply(a1, lena1, b, lenb, c1, w);
    }
    else if (lena1!=len)
    {
// I may need to pad with zeros when the top digit to be generated will be
// put there using multiply_and_add.
        for (std::size_t i=c1-c; i<lena+lenb; i++) c[i] = 0;
    }
// Now I need to do much the same for the odd numbered digits of a, but
// adding the products in rather than writing them into place.
    a1 = a + len;
    c1 = c + len;
    std::size_t lenc1 = lena+lenb-len;
// I know that I had lena>lenb at the start. This means I have at
// least a part block to process here, but there is no guarantee that
// I have a whole one.
    lena1 = lena - len;
    for (;;)
    {   if (lena1 < len) break;
        karatsuba_and_add(a1, len, b, lenb, c1, lenc1, w);
        if (lena1 <= 2*len)
        {   lena1 = 0;
            break;
        }
        c1 += 2*len;
        lenc1 -= 2*len;
        a1 += 2*len;
        lena1 -= 2*len;
    }
    if (lena1!=0)
        small_or_big_multiply_and_add(a1, lena1, b, lenb, c1, lenc1, w);
}

inline void top_level_certainly_big_multiply(const std::uint64_t *a,
        std::size_t lena,
        const std::uint64_t *b, std::size_t lenb,
        std::uint64_t *c, std::uint64_t *w,
        std::uint64_t *w0, std::uint64_t *w1)
{   if (lena == lenb)
    {   top_level_karatsuba(a, lena, b, lenb, c, w, w0, w1);
        return;
    }
    if (lena < lenb)
    {   std::swap(a, b);
        std::swap(lena, lenb);
    }
// Now b is the shorter operand. The case (2n)*(2n-1) will be handled
// using Karatsuba merely by treating the smaller number as if padded with
// a leading zero.
    if (lena%2==0 && lenb==lena-1)
    {   top_level_karatsuba(a, lena, b, lenb, c, w, w0, w1);
        return;
    }
// If the two inputs are unbalanced in length I will perform multiple
// balanced operations each of which can be handled specially. I will
// try to make each subsidiary multiplication as big as possible.
// This will be lenb rounded up to an even number.
// I will be willing to do chunks that are of an even size that is
// either lenb or lenb+1.
    std::size_t len = lenb + (lenb & 1);
    const std::uint64_t *a1 = a;
    std::uint64_t *c1 = c;
    std::size_t lena1 = lena;
// Multiply-and-add will be (slightly) more expensive than just Multiply,
// so I do a sequence of multiplications where their outputs will not overlap
// first, and then do the interleaved multiplications adding in.
    for (;;)
    {
// I may have rounded the size of b up by 1, and if I have I would generate
// 2*len-1 digits not 2*len and hence risk leaving a 1-word gap between filled
// in data. I zero that here to avoid trouble. However I must not do this
// for if the multiplication I am about to do will write in the very top
// digits of the final answer, because if I did that would be a sort of
// buffer overrun.
        if (len < lena1) c1[2*len-1] = 0;
        top_level_karatsuba(a1, len, b, lenb, c1, w, w0, w1);
        c1 += 2*len;
// I will keep going provided the next multiplication I will do will fully fit.
        if (lena1 < 3*len) break;
        a1 += 2*len;
        lena1 -= 2*len;
    }
    if (lena1 > 2*len)
    {   a1 += 2*len;
        lena1 -= 2*len;
// Do a shorter nice Multiply (without Add) to reach the end of input a.
        small_or_big_multiply(a1, lena1, b, lenb, c1, w);
    }
    else if (lena1!=len)
    {
// I may need to pad with zeros when the top digit to be generated will be
// put there using multiply_and_add.
        for (std::size_t i=c1-c; i<lena+lenb; i++) c[i] = 0;
    }
// Now I need to do much the same for the odd numbered digits of a, but
// adding the products in rather than writing them into place.
    a1 = a + len;
    c1 = c + len;
    std::size_t lenc1 = lena+lenb-len;
// I know that I had lena>lenb at the start. This means I have at
// least a part block to process here, but there is no guarantee that
// I have a whole one.
    lena1 = lena - len;
    for (;;)
    {   if (lena1 < len) break;
        karatsuba_and_add(a1, len, b, lenb, c1, lenc1, w);
        if (lena1 <= 2*len)
        {   lena1 = 0;
            break;
        }
        c1 += 2*len;
        lenc1 -= 2*len;
        a1 += 2*len;
        lena1 -= 2*len;
    }
    if (lena1!=0)
        small_or_big_multiply_and_add(a1, lena1, b, lenb, c1, lenc1, w);
}

inline void certainly_big_multiply_and_add(const std::uint64_t *a,
        std::size_t lena,
        const std::uint64_t *b, std::size_t lenb,
        std::uint64_t *c, std::size_t lenc,
        std::uint64_t *w)
{   if (lena == lenb)
    {   karatsuba_and_add(a, lena, b, lenb, c, lenc, w);
        return;
    }
    if (lena < lenb)
    {   std::swap(a, b);
        std::swap(lena, lenb);
    }
// Now b is the shorter operand. The case (2n)*(2n-1) will be handled
// using Karatsuba merely by treating the smaller number as if padded with
// a leading zero.
    if (lena%2==0 && lenb==lena-1)
    {   karatsuba_and_add(a, lena, b, lenb, c, lenc, w);
        return;
    }
// If the two inputs are unbalanced in length I will perform multiple
// balanced operations each of which can be handled specially. I will
// try to make each subsidiary multiplication as big as possible.
// This will be lenb rounded up to an even number.
// I will be willing to do chunks that are of an even size that is
// either lenb or lenb+1.
    std::size_t len = lenb + (lenb & 1);
    const std::uint64_t *a1 = a;
    std::uint64_t *c1 = c;
    std::size_t lena1 = lena, lenc1 = lenc;
// because this is "certainly big" I know I can do at least one
// Karatsuba stage.
    for (;;)
    {   karatsuba_and_add(a1, len, b, lenb, c1, lenc1, w);
        c1 += len;
        lenc1 -= len;
        a1 += len;
        lena1 -= len;
// I will keep going provided the next multiplication I will do will fully fit.
        if (lena1 < len) break;
    }
// Do a shorter nice Multiply (without Add) to reach the end of input a.
    if (lena1 != 0)
        small_or_big_multiply_and_add(a1, lena1, b, lenb, c1, lenc1, w);
}

// I am going to hope that the compiler turns this into a tail-call to
// either certainly_big_multiply or classical_multiply with very
// little overhead.

inline void small_or_big_multiply(const std::uint64_t *a,
                                  std::size_t lena,
                                  const std::uint64_t *b, std::size_t lenb,
                                  std::uint64_t *c, std::uint64_t *w)
{   if (lena < KARATSUBA_CUTOFF || lenb < KARATSUBA_CUTOFF)
    {   if (lena==1) classical_multiply(a[0], b, lenb, c);
        else if (lenb==1) classical_multiply(b[0], a, lena, c);
        else classical_multiply(a, lena, b, lenb, c);
    }
    else certainly_big_multiply(a, lena, b, lenb, c, w);
}

inline void small_or_big_multiply_and_add(const std::uint64_t *a,
        std::size_t lena,
        const std::uint64_t *b, std::size_t lenb,
        std::uint64_t *c, std::size_t lenc,
        std::uint64_t *w)
{   if (lena < KARATSUBA_CUTOFF || lenb < KARATSUBA_CUTOFF)
    {   if (lena==1) classical_multiply_and_add(a[0], b, lenb, c, lenc);
        else if (lenb==1) classical_multiply_and_add(b[0], a, lena, c, lenc);
        else classical_multiply_and_add(a, lena, b, lenb, c, lenc);
    }
    else certainly_big_multiply_and_add(a, lena, b, lenb, c, lenc, w);
}

// FIXED_LENGTH_LIMIT: Can multiply inputs with up to this number of
//                     64-bit digits using the fixed workspace.
// WORKSPACE_SIZE:     Length of the "w" work-vector needed for the above
//                     which is a bit over twice the length of the inputs.
//
// These need to be such that it is OK to put three arrays of length
// KARA_WORKSPACE_SIZE*sizeof(uint64_t) on the stack without that feeling
// embarassing. The settings I use here can use around 50 Kbytes of stack.

INLINE_VAR const std::size_t KARA_FIXED_LENGTH_LIMIT = 1000;
INLINE_VAR const std::size_t KARA_WORKSPACE_SIZE = 2050;

// These two functions allocate workspace for Karatsuba on the stack and
// are called when the inputs are short enough for that to feel reasonable.

inline void allocate_one_array(const std::uint64_t *a,
                               std::size_t lena,
                               const std::uint64_t *b, std::size_t lenb,
                               std::uint64_t *c)
{   std::uint64_t kara_workspace[KARA_WORKSPACE_SIZE];
    certainly_big_multiply(a, lena, b, lenb, c, kara_workspace);
}

inline void allocate_three_arrays(const std::uint64_t *a,
                                  std::size_t lena,
                                  const std::uint64_t *b, std::size_t lenb,
                                  std::uint64_t *c)
{   std::uint64_t kara_workspace[KARA_WORKSPACE_SIZE];
    std::uint64_t kara_workspace0[KARA_WORKSPACE_SIZE];
    std::uint64_t kara_workspace1[KARA_WORKSPACE_SIZE];
    top_level_certainly_big_multiply(a, lena, b, lenb, c,
                                     kara_workspace, kara_workspace0, kara_workspace1);
}

inline constexpr int BY(int m, int n)
{   return m + 4*n;
}

// Finally I can provide the top-level entrypoint that accepts signed
// integers that may not be the same size.

// This is the main entrypoint to the integer multiplication code. It
// takes two signed numbers and forms their product.

inline void bigmultiply(const std::uint64_t *a, std::size_t lena,
                        const std::uint64_t *b, std::size_t lenb,
                        std::uint64_t *c, std::size_t &lenc)
{
// If a and/or be are negative then I can treat their true values as
//    a = sa + va      b = sb + vb
// where sa and sb and the signs - represented here as 0 for a positive
// number and -2^(64*len) for a negative one. va and vb are then the simple
// bit-patterns for a and b but now interpreted as unsigned values. So if
// instead of using 64-bit digits I was using 8 bit ones, the value -3
// would be stored as 0xfd and that would be spit up as -128 + 253.
// Then a*b = sa*sb + sa*vb + sb*va + va*vb.
// The last item there is just the product of a and b when treated as
// unsigned values, and so is what I compute first here rather simply.
// If sa and/or sb is non-zero it is just the negative of a power of 2^64,
// and so I can correct the unsigned product into a signed one by (sometimes)
// subtracting a shifted version of a or b from it.
// If both arguments are tiny I write out the code in-line. The timings I
// have taken suggest that this makes a significant difference to costs, and
// I view it as plausible that "rather small" cases will often dominate.
    if (lena <= 4 && lenb <= 4) switch (lena + 4*lenb)
        {
// Length 2 result
            case BY(1, 1):
            {   std::int64_t c1;
                std::uint64_t c0;
                signed_multiply64(a[0], b[0], c1, c0);
                c[0] = c0;
                if (shrinkable(c1, c0)) lenc = 1;
                else
                {   c[1] = static_cast<std::uint64_t>(c1);
                    lenc = 2;
                }
                return;
            }

// Length 3 result
            case BY(1, 2):
                std::swap(a, b);
            // drop through.
            case BY(2, 1):
            {   if (b[0]==0)
                {   c[0] = 0;
                    lenc = 1;
                    return;
                }
                std::int64_t c2;
                std::uint64_t c1, c0;
                multiply64(b[0], a[0], c1, c0);
                c[0] = c0;
                signed_multiply64(b[0], a[1], c1, c2, c1);
                if (negative(b[0]))
                    c2 = static_cast<std::int64_t>(
                             static_cast<std::uint64_t>(c2) -
                             subtract_with_borrow(c1, a[0], c1));
                c[1] = c1;
// If you have an input like 2^63 it will be represented as a 2-word
// bignum {0,2^63} so that the most significant bit of the most significant
// digits is 0 to show that it is positive. If you multiply two such numbers
// the direct result you get is {0, 0, 2^62, 0} and the top non-zero digit
// now does not have its top bit set. So TWO words can be trimmed from the
// top. This issue may not arise in the length-1 by length-2 case here, but
// I leave the test in to feel safe and tidy.
                if (shrinkable(c2, c1))
                {   if (shrinkable(c1, c0)) lenc = 1;
                    else lenc = 2;
                }
                else
                {   c[2] = static_cast<std::uint64_t>(c2);
                    lenc = 3;
                }
                return;
            }

// Length 4 result
            case BY(2, 2):
            {   std::int64_t c3;
                std::uint64_t c2, c1;
                mul2x2S(static_cast<std::int64_t>(a[1]), a[0],
                        static_cast<std::int64_t>(b[1]), b[0],
                        c3, c2, c1, c[0]);
                c[1] = c1;
                c[2] = c2;
                if (shrinkable(c3, c2))
                {   if (shrinkable(c2, c1)) lenc = 2;
                    else lenc = 3;
                }
                else
                {   c[3] = static_cast<std::uint64_t>(c3);
                    lenc = 4;
                }
                return;
            }

            case BY(1, 3):
                std::swap(a, b);
            // drop through.
            case BY(3, 1):
            {   if (b[0]==0)
                {   c[0] = 0;
                    lenc = 1;
                    return;
                }
                std::int64_t c3;
                std::uint64_t c2, c1;
                multiply64(b[0], a[0], c1, c[0]);
                multiply64(b[0], a[1], c1, c2, c1);
                signed_multiply64(b[0], a[2], c2, c3, c2);
                if (negative(b[0]))
                {   std::uint64_t borrow = subtract_with_borrow(c1, a[0], c1);
                    borrow = subtract_with_borrow(c2, a[1], borrow, c2);
                    c3 = static_cast<std::int64_t>(
                             static_cast<std::uint64_t>(c3) - borrow);
                }
                c[1] = c1;
                c[2] = c2;
                if (shrinkable(c3, c2))
                {   if (shrinkable(c2, c1)) lenc = 2;
                    else lenc = 3;
                }
                else
                {   c[3] = static_cast<std::uint64_t>(c3);
                    lenc = 4;
                }
                return;
            }

// Length 5 result
            case BY(1, 4):
                std::swap(a, b);
            case BY(4, 1):
            {   if (b[0]==0)
                {   c[0] = 0;
                    lenc = 1;
                    return;
                }
                std::int64_t c4;
                std::uint64_t c3, c2, c1;
                multiply64(b[0], a[0], c1, c[0]);
                multiply64(b[0], a[1], c1, c2, c1);
                multiply64(b[0], a[2], c2, c3, c2);
                signed_multiply64(b[0], a[3], c3, c4, c3);
                if (negative(b[0]))
                {   std::uint64_t borrow = subtract_with_borrow(c1, a[0], c1);
                    borrow = subtract_with_borrow(c2, a[1], borrow, c2);
                    borrow = subtract_with_borrow(c3, a[2], borrow, c3);
                    c4 = static_cast<std::int64_t>(
                             static_cast<std::uint64_t>(c4) - borrow);
                }
                c[1] = c1;
                c[2] = c2;
                c[3] = c3;
                if (shrinkable(c4, c3))
                {   if (shrinkable(c3, c2)) lenc = 3;
                    else lenc = 4;
                }
                else
                {   c[4] = static_cast<std::uint64_t>(c4);
                    lenc = 5;
                }
                return;
            }

            case BY(2, 3):
                std::swap(a, b);
            case BY(3, 2):
            {   std::int64_t c4;
                std::uint64_t c3, c3a, c2;
                mul2x2(a[1], a[0], b[1], b[0],
                       c3, c2, c[1], c[0]);
                multiply64(a[2], b[0], c2, c3a, c2);
                std::uint64_t carry = add_with_carry(c3, c3a, c3);
                signed_multiply64(static_cast<std::int64_t>(a[2]),
                                  static_cast<std::int64_t>(b[1]), c3, c4, c3);
                c4 = static_cast<std::int64_t>(
                         static_cast<std::uint64_t>(c4) + carry);
                if (negative(b[1]))
                {   std::uint64_t borrow = subtract_with_borrow(c2, a[0], c2);
                    borrow = subtract_with_borrow(c3, a[1], borrow, c3);
                    c4 = static_cast<std::int64_t>(
                             static_cast<std::uint64_t>(c4) - borrow);
                }
                if (negative(a[2]))
                {   std::uint64_t borrow = subtract_with_borrow(c3, b[0], c3);
                    c4 = static_cast<std::int64_t>(
                             static_cast<std::uint64_t>(c4) - borrow);
                }
                c[2] = c2;
                c[3] = c3;
                if (shrinkable(c4, c3))
                {   if (shrinkable(c3, c2)) lenc = 3;
                    else lenc = 4;
                }
                else
                {   c[4] = static_cast<std::uint64_t>(c4);
                    lenc = 5;
                }
                return;
            }

// Length 6 results
            case BY(2, 4):
            case BY(4, 2):
// I do not have to implement all the cases here - any that I either choose
// not to or have not got around to can merely go "break;" and join in the
// generic path.
                break;

            case BY(3, 3):
            {   std::int64_t c5;
                std::uint64_t c4, c3, c2, c1;
                mul3x3S(a[2], a[1], a[0], b[2], b[1], b[0],
                        c5, c4, c3, c2, c1, c[0]);
                c[1] = c1;
                c[2] = c2;
                c[3] = c3;
                c[4] = c4;
                if (shrinkable(c5, c4))
                {   if (shrinkable(c4, c3)) lenc = 4;
                    else lenc = 5;
                }
                else
                {   c[5] = static_cast<std::uint64_t>(c5);
                    lenc = 6;
                }
                return;
            }

// Length 7 results
            case BY(3, 4):
            case BY(4, 3):
// As above, cases that have not been coded here do not cause failure,
// they just lead to that case being handled by the general (loopy) code.
                break;


// Length 8 result
            case BY(4, 4):
            {   std::uint64_t c7, c6, c5, c4;
                mul4x4(a[3], a[2], a[1], a[0],
                       b[3], b[2], b[1], b[0],
                       c7, c6, c5, c4, c[3], c[2], c[1], c[0]);
                if (negative(a[3]))
                {   std::uint64_t borrow = subtract_with_borrow(c4, b[0], c4);
                    borrow = subtract_with_borrow(c5, b[1], borrow, c5);
                    borrow = subtract_with_borrow(c6, b[2], borrow, c6);
                    c7 = static_cast<std::int64_t>(
                             static_cast<std::uint64_t>(c7) - b[3] - borrow);
                }
                if (negative(b[3]))
                {   std::uint64_t borrow = subtract_with_borrow(c4, a[0], c4);
                    borrow = subtract_with_borrow(c5, a[1], borrow, c5);
                    borrow = subtract_with_borrow(c6, a[2], borrow, c6);
                    c7 = static_cast<std::int64_t>(
                             static_cast<std::uint64_t>(c7) - a[3] - borrow);
                }
                c[4] = c4;
                c[5] = c5;
                c[6] = c6;
                if (shrinkable(c7, c6))
                {   if (shrinkable(c6, c5)) lenc = 6;
                    else lenc = 7;
                }
                else
                {   c[7] = static_cast<std::uint64_t>(c7);
                    lenc = 8;
                }
                return;
            }

            default:
// The default label should never be activated!
                ;
        }

// If the smaller input is reasonably small I will merely use classical
// multiplication.
// It is necessary to make a special case for multiplication by a 1-word
// bignum for two reasons. (a) multiplication by zero yields a zero result
// regardless of the magnitude of the second operand, and (b) one of
// my implementations of classical_multiplication must be called in
// a separate overloaded version to multiply by just one digit.
    if (lena < KARATSUBA_CUTOFF || lenb < KARATSUBA_CUTOFF)
    {   if (lena==1)
        {   if (a[0]==0)
            {   c[0] = 0;
                lenc = 1;
                return;
            }
            else classical_multiply(a[0], b, lenb, c);
        }
        else if (lenb==1)
        {   if (b[0]==0)
            {   c[0] = 0;
                lenc = 1;
                return;
            }
            else classical_multiply(b[0], a, lena, c);
        }
        else classical_multiply(a, lena, b, lenb, c);
// I do NOT return here because for a non-zero result I will need to adjust
// if one or both of the input numbers were negative.
    }
    else
    {
// For many smaller cases I will just use some static pre-allocated workspace
// and hence avoid potential storage management overheads.
        if (lena <= KARA_FIXED_LENGTH_LIMIT ||
            lenb <= KARA_FIXED_LENGTH_LIMIT)
        {   if (lena < PARAKARA_CUTOFF ||
                lenb < PARAKARA_CUTOFF)
                allocate_one_array(a, lena, b, lenb, c);
            else allocate_three_arrays(a, lena, b, lenb, c);
        }
        else
        {   push(a); push(b);
            std::size_t lenw;
            if (lena < lenb) lenw = lena;
            else lenw = lenb;
            for (std::size_t i=lenw; i>8; i=i/2) lenw++;
// I give myself workspace as long as the shorter input + log of that. The
// extra logarithmic bit is because each time I split a number into its top
// and bottom parts I may have an odd number and so the workspace needed
// gets rounded up by a constant amount for each level of division.
            std::uint64_t *w = reserve(2*lenw);
            if (lena < PARAKARA_CUTOFF ||
                lenb < PARAKARA_CUTOFF)
            {   pop(b); pop(a);
                certainly_big_multiply(a, lena, b, lenb, c, w);
            }
            else
            {   std::uint64_t *w0 = reserve(4*lenw);
                std::uint64_t *w1 = reserve(4*lenw);
                pop(b); pop(a);
                top_level_certainly_big_multiply(a, lena, b, lenb, c,
                                                 w, w0, w1);
                abandon(w1);
                abandon(w0);
            }
            abandon(w);
        }
    }
// Now adapt for the situation where one or both of the inputs had been
// negative.
    if (negative(a[lena-1]))
    {   std::uint64_t borrow = 0;
        for (std::size_t i=0; i<lenb; i++)
            borrow = subtract_with_borrow(c[i+lena], b[i], borrow, c[i+lena]);
    }
    if (negative(b[lenb-1]))
    {   std::uint64_t borrow = 0;
        for (std::size_t i=0; i<lena; i++)
            borrow = subtract_with_borrow(c[i+lenb], a[i], borrow, c[i+lenb]);
    }
// The actual value may be 1 or 2 words shorter than this. So test the top
// digit of c and if necessary reduce lenc.
// Also note that the pending  result is at least of length 2 here because
// various small cases had been processed in-line earlier.
// eg {0, 0x8000000000000000} times itself is {0, 0, 0x4000000000000000, 0}
// and both leading zeros can be trimmed.
    lenc = lena + lenb;
    if (lenc > 1 && shrinkable(c[lenc-1], c[lenc-2]))
    {   lenc--;
        if (lenc > 1 && shrinkable(c[lenc-1], c[lenc-2])) lenc--;
    }
}

//===========================================================================
//===========================================================================

inline std::intptr_t Times::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::size_t n = lena+lenb;
    push(a); push(b);
    std::uint64_t *p = reserve(n);
    pop(b); pop(a);
    std::size_t final_n;
// I might like to optimise the 2*2 case here or even 2*3 and 3*3?
    bigmultiply(a, lena, b, lenb, p, final_n);
    return confirm_size(p, n, final_n);
}

inline std::intptr_t Times::op(std::int64_t a, std::int64_t b)
{   std::int64_t hi;
    std::uint64_t lo;
    signed_multiply64(a, b, hi, lo);
    if ((hi==0 && positive(lo)) ||
        (hi==-1 && negative(lo)))
    {   if (fits_into_fixnum(static_cast<std::int64_t>(lo)))
            return int_to_handle(static_cast<std::int64_t>(lo));
        std::uint64_t *r = reserve(1);
        r[0] = lo;
        return confirm_size(r, 1, 1);
    }
    std::uint64_t *r = reserve(2);
    r[0] = lo;
    r[1] = hi;
    return confirm_size(r, 2, 2);
}

inline std::intptr_t Times::op(std::int64_t a, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    push(b);
    std::uint64_t *c = reserve(lenb+1);
    pop(b);
    std::uint64_t hi = 0;
    for (std::size_t i=0; i<lenb; i++)
        multiply64(a, b[i], hi, hi, c[i]);
    c[lenb] = hi;
    if (negative(a))
    {   std::uint64_t carry = 1;
        for (std::size_t i=0; i<lenb; i++)
            carry = add_with_carry(c[i+1], ~b[i], carry, c[i+1]);
    }
    if (negative(b[lenb-1])) c[lenb] -= a;
    std::size_t lenc = lenb+1;
    truncate_positive(c, lenc);
    truncate_negative(c, lenc);
    return confirm_size(c, lenb+1, lenc);
}

inline std::intptr_t Times::op(std::uint64_t *a, std::int64_t b)
{   return Times::op(b, a);
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
// simple multiplication. Just where that threshold should be i snot really
// clear to me, but for now I am setting it as 3 times the point at which
// ordinary multiplications moves on from classical methods.

inline void bigsquare(std::uint64_t *a, std::size_t lena,
                      std::uint64_t *r, std::size_t &lenr)
{   if (lena > 3*KARATSUBA_CUTOFF)
    {   bigmultiply(a, lena, a, lena, r, lenr);
        return;
    }
    for (std::size_t i=0; i<2*lena; i++) r[i] = 0;
    std::uint64_t carry;
    lenr = 2*lena;
    for (std::size_t i=0; i<lena; i++)
    {   std::uint64_t hi = 0;
// Note that all the terms I add in here will need to be doubled in the
// final accounting.
        for (std::size_t j=i+1; j<lena; j++)
        {   std::uint64_t lo;
            multiply64(a[i], a[j], hi, hi, lo);
            hi += add_with_carry(lo, r[i+j], r[i+j]);
        }
        r[i+lena] = hi;
    }
// Double the part that has been computed so far.
    carry = 0;
    for (std::size_t i=0; i<2*lena; i++)
    {   std::uint64_t w = r[i];
        r[i] = (w << 1) | carry;
        carry = w >> 63;
    }
// Now add in the bits that do not get doubled.
    carry = 0;
    std::uint64_t hi = 0;
    for (std::size_t i=0; i<lena; i++)
    {   std::uint64_t lo;
        multiply64(a[i], a[i], r[2*i], hi, lo);
        carry = add_with_carry(lo, carry, r[2*i]);
        carry = add_with_carry(hi, r[2*i+1], carry, r[2*i+1]);
    }
// Now if the input had been negative I have a correction to apply...
// I subtract 2a from the top half of the result.
    if (negative(a[lena-1]))
    {   std::uint64_t carry = 1;
        int fromprev = 0;
        for (std::size_t i=0; i<lena; i++)
        {   std::uint64_t d = a[i];
            std::uint64_t w = (d<<1) | fromprev;
            fromprev = static_cast<int>(d>>63);
            carry = add_with_carry(r[lena+i], ~w, carry, r[lena+i]);
        }
    }
// The actual value may be 1 word shorter than this.
//  test top digit or r and if necessary reduce lenr.
    truncate_positive(r, lenr);
    truncate_negative(r, lenr);
}

inline std::intptr_t Square::op(std::uint64_t *a)
{   std::size_t lena = number_size(a);
    std::size_t n = 2*lena;
    push(a);
    std::uint64_t *p = reserve(n);
    pop(a);
    std::size_t final_n;
    bigsquare(a, lena, p, final_n);
    return confirm_size(p, n, final_n);
}

inline std::intptr_t Square::op(std::int64_t a)
{   std::uint64_t hi, lo;
    multiply64(a, a, hi, lo);
    if (a < 0) hi -= 2u*static_cast<std::uint64_t>(a);
// Now I have a 128-bit product of the inputs
    if ((hi == 0 && positive(lo)) ||
        (hi == static_cast<std::uint64_t>(-1) && negative(lo)))
    {   if (fits_into_fixnum(static_cast<std::int64_t>(lo)))
            return int_to_handle(static_cast<std::int64_t>(lo));
        else
        {   std::uint64_t *p = reserve(1);
            p[0] = lo;
            return confirm_size(p, 1, 1);
        }
    }
    std::uint64_t *p = reserve(2);
    p[0] = lo;
    p[1] = hi;
    return confirm_size(p, 2, 2);
}

inline std::intptr_t Isqrt::op(std::uint64_t *a)
{   std::size_t lena = number_size(a);
    if (lena == 1) return Isqrt::op(static_cast<std::int64_t>(a[0]));
    std::size_t lenx = (lena+1)/2;
    push(a);
    std::uint64_t *x = reserve(lenx);
    pop(a);
    for (std::size_t i=0; i<lenx; i++) x[i] = 0;
    std::size_t bitstop = a[lena-1]==0 ? 0 : 64 - nlz(a[lena-1]);
    bitstop /= 2;
    if ((lena%2) == 0) bitstop += 32;
    x[lenx-1] = static_cast<std::uint64_t>(1) << bitstop;
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
    Bignum biga(true, vector_to_handle(a));
    Bignum bigx(true, confirm_size(x, lenx, lenx));
// I will do the first step outside the loop to guarantee that my
// approximation is an over-estimate before I try the end-test.
//         bigx = (bigx + biga/bigx) >> 1;
// The push/pop mess here feels extreme and I should probably re-code this
// using lower level interfaces.
    push(bigx.val); push(biga.val);
    Bignum w1 = biga/bigx;
    pop(biga.val); pop(bigx.val);
    push(bigx.val); push(biga.val);
    w1 = bigx + w1;
    pop(biga.val); pop(bigx.val);
    push(bigx.val); push(biga.val);
    bigx = w1 >> 1;
    pop(biga.val); pop(bigx.val);
    for (;;)
    {   push(bigx.val); push(biga.val);
        w1 = biga/bigx;
        pop(biga.val); pop(bigx.val);
        push(bigx.val); push(biga.val);
        w1 = bigx + w1;
        pop(biga.val); pop(bigx.val);
        push(bigx.val); push(biga.val);
        Bignum y = w1 >> 1;
        pop(biga.val); pop(bigx.val);
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

inline std::intptr_t Isqrt::op(std::int64_t aa)
{   if (aa <= 0) return int_to_bignum(0);
    std::uint64_t a = static_cast<std::uint64_t>(aa);
    std::size_t w = 64 - nlz(a);
    std::uint64_t x0 = a >> (w/2);
// The iteration here converges to sqrt(a) from above, but I believe that
// when the value stops changing it will be at floor(sqrt(a)). There are
// some cases where the sequence ends up alternating between two adjacent
// values. Because my input is at most 2^63-1 the number of iterations
// written here will always suffice.
    std::uint64_t x1 = (x0 + a/x0)/2;
    std::uint64_t x2 = (x1 + a/x1)/2;
    if (x2 >= x1) return unsigned_int_to_bignum(x1);
    std::uint64_t x3 = (x2 + a/x2)/2;
    if (x3 >= x2) return unsigned_int_to_bignum(x2);
    std::uint64_t x4 = (x3 + a/x3)/2;
    if (x4 >= x3) return unsigned_int_to_bignum(x3);
    std::uint64_t x5 = (x4 + a/x4)/2;
    if (x5 >= x4) return unsigned_int_to_bignum(x4);
    return unsigned_int_to_bignum(x5);
}

// This raises a bignum to a positive integer power. If the power is n then
// the size of the output may be n*lena. The two vectors v and w are workspace
// and must both be of size (at least) the size that the result could end
// up as. Well with greater subtlty we can see that the sum of their sizes
// must be at least the size of the result, but it is not clear that any
// useful saving spece saving can be found down that path.

inline void bigpow(std::uint64_t *a, std::size_t lena,
                   std::uint64_t n,
                   std::uint64_t *v,
                   std::uint64_t *w,
                   std::uint64_t *r, std::size_t &lenr, std::size_t maxlenr)
{   if (n == 0)
    {   r[0] = 0;
        lenr = 1;
        return;
    }
    internal_copy(a, lena, v);
    std::size_t lenv = lena;
    w[0] = 1;
    std::size_t lenw = 1;
    while (n > 1)
    {   if (n%2 == 0)
        {   bigsquare(v, lenv, r, lenr);
            arithlib_assert(lenr <= maxlenr);
            internal_copy(r, lenr, v);
            lenv = lenr;
            n = n/2;
        }
        else
        {   bigmultiply(v, lenv, w, lenw, r, lenr);
            arithlib_assert(lenr <= maxlenr);
            internal_copy(r, lenr, w);
            lenw = lenr;
            bigsquare(v, lenv, r, lenr);
            arithlib_assert(lenr <= maxlenr);
            internal_copy(r, lenr, v);
            lenv = lenr;
            n = (n-1)/2;
        }
    }
    bigmultiply(v, lenv, w, lenw, r, lenr);
}

// In cases where n is too large this can fail. At present I deal with that
// with arithlib_assert() statements rather than any comfortable scheme for
// reporting the trouble.

// The code that dispatches into here should have filtered cases such that
// the exponent n is not 0, 1 or 2 here.

inline std::intptr_t Pow::op(std::uint64_t *a, std::int64_t n)
{   std::size_t lena = number_size(a);
//  1^(-n) == 1,
//  (-1)^(-n) == 1 if n is even or -1 if n is odd.
//  a^(-n) == 0 when a is not -1, 0 or 1.
    if (n < 0)
    {   int z = 0;
        if (lena == 0)
        {   if (static_cast<std::int64_t>(a[0]) == 1) z = 1;
            else if (static_cast<std::int64_t>(a[0]) == -1)
                z = (n%1==0 ? 1 : -1);
            else arithlib_assert(a[0] != 0u);
        }
// 0^(-n) is an error
// 1^(-n) = 1
// (-1)^(-n) = +1 or -1 depending on whether n is odd or even
// x^(-n) = 0 otherwise.
        return int_to_bignum(z);
    }
// 6^n = 0
    std::size_t bitsa = bignum_bits(a, lena);
    std::uint64_t hi, bitsr;
    multiply64(n, bitsa, hi, bitsr);
    arithlib_assert(hi ==
                    0); // Check that size is at least somewhat sane!
// I estimate the largest size that my result could be, but then add
// an extra word because the internal working of multiplication can
// write a zero beyond its true result - eg if you are multiplying a pair
// of 1-word numbers together it will believe that the result could be 2
// words wide even if in fact you know it will not be.
    std::uint64_t lenr1 = 2 + bitsr/64;
    std::size_t lenr = static_cast<std::size_t>(lenr1);
// if size_t was more narrow than 64-bits I could lose information in
// truncating from uint64_t to size_t.
    arithlib_assert(lenr == lenr1);
    std::uint64_t olenr = lenr;
    push(a);
    std::uint64_t *r = reserve(lenr);
    push(r);
    std::uint64_t *v = reserve(lenr);
    push(v);
    std::uint64_t *w = reserve(lenr);
    pop(v); pop(r); pop(a);
    bigpow(a, lena, static_cast<std::uint64_t>(n), v, w, r, lenr, lenr);
    arithlib_assert(lenr <= olenr);
    abandon(w);
    abandon(v);
    return confirm_size(r, olenr, lenr);
}

// Again the cases n = 0, 1 and 2 have been filtered out

inline std::intptr_t Pow::op(std::int64_t a, std::int64_t n)
{   if (n < 0)
    {   int z = 0;
        if (a == 1) z = 1;
        else if (a == -1) z = (n%1==0 ? 1 : 0);
        else arithlib_assert(a != 0);
        return int_to_handle(z);
    }
    if (a == 0) return int_to_handle(0);
    else if (a == 1) return int_to_handle(a);
    else if (n == 0) return int_to_handle(1);
    std::uint64_t absa = (a < 0 ? -static_cast<std::uint64_t>
                          (a) : static_cast<std::uint64_t>(a));
    std::size_t bitsa = 64 - nlz(absa);
    std::uint64_t hi, bitsr;
    multiply64(n, bitsa, hi, bitsr);
    arithlib_assert(hi ==
                    0); // Check that size is at least somewhat sane!
    std::uint64_t lenr1 = 2 + bitsr/64;
    if (bitsr < 64) // Can do all the work as machine integers.
    {   std::int64_t result = 1;
        for (;;)
        {   if (n%2 != 0) result *= a;
            if ((n = n/2) == 0) break;
            a *= a;
        }
        return int_to_bignum(result);
    }
    std::size_t lenr = static_cast<std::size_t>(lenr1);
// if size_t was more narrow than 64-bits I could lose information in
// truncating from uint64_t to size_t.
    arithlib_assert(lenr == lenr1);
    std::uint64_t olenr = lenr;
    std::uint64_t *r = reserve(lenr);
    push(r);
    std::uint64_t *v = reserve(lenr);
    push(v);
    std::uint64_t *w = reserve(lenr);
    pop(v); pop(r);
    std::uint64_t aa[1] = {static_cast<std::uint64_t>(a)};
    bigpow(aa, 1, static_cast<std::uint64_t>(n), v, w, r, lenr, lenr);
    arithlib_assert(lenr <= olenr);
    abandon(w);
    abandon(v);
    return confirm_size(r, olenr, lenr);
}

inline double Pow::op(std::uint64_t *a, double n)
{   return std::pow(Double::op(a), n);
}

inline double Pow::op(std::int64_t a, double n)
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
// passed in sign and magnitide form as {b, b_negative}

inline void unsigned_short_division(std::uint64_t *a,
                                    std::size_t lena,
                                    std::uint64_t b, bool b_negative,
                                    bool want_q, std::uint64_t *&q,
                                    std::size_t &olenq, std::size_t &lenq,
                                    bool want_r, std::uint64_t *&r,
                                    std::size_t &olenr, std::size_t &lenr)
{   std::uint64_t hi = 0;
    bool a_negative = false;
    std::uint64_t *aa;
    if (negative(a[lena-1]))
    {   a_negative = true;
// Take absolute value of a if necessary.
        push(a);
        aa = reserve(lena);
        pop(a);
        internal_negate(a, lena, aa);
        a = aa;
    }
// Now both a and b are positive so I can do the division fairly simply.
// Allocate space for the quotient if I need that, and then do standard
// short division.
    std::size_t i=lena-1;
    if (want_q)
    {   olenq = lena;
        push(a);
        q = reserve(olenq);
        pop(a);
    }
    for (;;)
    {   std::uint64_t d;
        divide64(hi, a[i], b, d, hi);
        if (want_q) q[i] = d;
        if (i == 0) break;
        i--;
    }
// If the original a had been negative I allocated space to store its
// absolute value, and I can discard that now.
    if (a_negative) abandon(aa);
    if (want_q)
    {   lenq = lena;
// The quotient will be negative if divisor and dividend had different signs.
        if (a_negative != b_negative)
        {   internal_negate(q, lenq, q);
            truncate_negative(q, lenq);
        }
        else truncate_positive(q, lenq);
    }
    if (want_r)
    {
// The remainder is now present as an unsigned value in hi. The sign it
// must end up having must match the sign of a (the dividend). Furthermore
// the remainder will be strictly smaller then b, and the largest possible
// value for b is 0xffffffffffffffff. The remainder may need to be returned
// as a 2-digit bignum.
        if (want_q) push(q);
        if (a_negative)
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
        if (want_q) pop(q);
    }
}

inline void signed_short_division(std::uint64_t *a, std::size_t lena,
                                  std::int64_t b,
                                  bool want_q, std::uint64_t *&q,
                                  std::size_t &olenq, std::size_t &lenq,
                                  bool want_r, std::uint64_t *&r,
                                  std::size_t &olenr, std::size_t &lenr)
{   if (b > 0) unsigned_short_division(a, lena,
                                           static_cast<std::uint64_t>(b),
                                           false,
                                           want_q, q, olenq, lenq,
                                           want_r, r, olenr, lenr);
    else unsigned_short_division(a, lena, -static_cast<std::uint64_t>(b),
                                     true,
                                     want_q, q, olenq, lenq,
                                     want_r, r, olenr, lenr);
}

inline void unsigned_long_division(std::uint64_t *a,
                                   std::size_t &lena,
                                   std::uint64_t *b, std::size_t &lenb,
                                   bool want_q, std::uint64_t *q,
                                   std::size_t &olenq, std::size_t &lenq);

// The following is a major entrypoint to the division code. (a) and (b) are
// vectors of digits such that the top digit of a number is treated as signed
// and the lower ones as unsigned. To cope with this there will sometimes
// be a sort of initial padder digit. The two boolean values indicate whether
// either or both of quotient and remainder are required. if want_q is set
// then this creates a new vector for q and return it via q/lenq. Similarly
// for want_r. The inputs a and b can be bignums of any size and are allowed
// to be positive or negative - this sorts everything out.

// Divide a by b to obtain a quotient q and a remainder r.

inline void division(std::uint64_t *a, std::size_t lena,
                     std::uint64_t *b, std::size_t lenb,
                     bool want_q, std::uint64_t *&q, std::size_t &olenq, std::size_t &lenq,
                     bool want_r, std::uint64_t *&r, std::size_t &olenr, std::size_t &lenr)
{   arithlib_assert(want_q || want_r);
// First I will filter out a number of cases where the divisor is "small".
// I only want to proceed into the general case code if it is a "genuine"
// big number with at least two digits. This bit of the code is messier
// than one might have imagined because of the 2s complement representation
// I use and the fact that extreme values that almost fit in a single
// digit can ends up as 2-digit values with a degenerate top digit.
//
// The first case is when the single digit if b is a signed value in the
// range -2^63 to 2^63-1.
    if (lenb == 1)
    {
// At present I cause an attempt to divide by zero to crash with an
// arithlib_assert failure if I have build in debug mode or to do who
// knows what (possibly raise an exception) otherwise. This maybe needs
// review. I wonder if I should throw a "division by zero" exception?
        arithlib_assert(b[0] != 0); // would be division by zero
        signed_short_division(a, lena, static_cast<std::int64_t>(b[0]),
                              want_q, q, olenq, lenq,
                              want_r, r, olenr, lenr);
        return;
    }
// Next I have b in the range 2^63 to 2^64-1. Such values can be represented
// in uint64_t.
    else if (lenb == 2 && b[1]==0)
    {   unsigned_short_division(a, lena, b[0], false,
                                want_q, q, olenq, lenq,
                                want_r, r, olenr, lenr);
        return;
    }
// Now for b in -2^64 to -2^63-1. The 2s complement representetation will be
// of the form (-1,nnn) with nnn an unsigned 64-bit value.
    else if (lenb == 2 && b[1]==static_cast<std::uint64_t>(-1))
    {
// -b(0) is an unsigned representation of the absolute value of b. There is
// one special case when -b(0) is zero, and that corresponds to division
// by -2^64, so I will need to detect that and turn the division into a
// combination of shift and negate operations.
        if (b[0] == 0)
        {   if (want_q)
            {   lenq = lena;
                olenq = lena;
                push(a);
                q = reserve(lena);
                pop(a);
// The next line took me some while to arrive at!
                std::uint64_t carry = !negative(a[lena-1]) || a[0]==0 ? 1 : 0;
                for (std::size_t i=1; i<lena; i++)
                    carry = add_with_carry(~a[i], carry, q[i-1]);
                q[lena-1] = negative(a[lena-1]) ? 0 : -static_cast<std::uint64_t>(1);
                truncate_positive(q, lenq);
                truncate_negative(q, lenq);
            }
            if (want_r)
            {   std::uint64_t rr = a[0], padr = 0;
                lenr = 1;
                if (negative(a[lena-1]) && positive(rr))
                {   padr = -1;
                    lenr++;
                }
                else if (positive(a[lena-1]) && negative(rr))
                {   padr = 0;
                    lenr++;
                }
                if (want_q) push(q);
                r = reserve(lenr);
                if (want_q) pop(q);
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
    std::uint64_t *bb = NULL;
    std::size_t lenbb = lenb;
    bool b_negative = negative(b[lenb-1]);
    if (b_negative)
    {
// In the case that b is negative I will want its absolute value. Especially
// in a multi-thread world I must not disturb or overwrite the input vector,
// so a create a temporary copy of b to negate. In my full 2s complement
// representation negating -2^(64*n-1) would lead to what was supposed to be
// a positive value but it would have its top bit set so it would require
// and extra leading 0. Because the value I generate here is to be treated
// as unsigned this leading top bit does not matter and so the absolute value
// of b fits in the same amount of space that b did with no risk of overflow.
        push(a); push(b);
        bb = reserve(lenb);
        pop(b); pop(a);
        olenr = lenb;
        internal_negate(b, lenb, bb);
        if (bb[lenbb-1] == 0) lenbb--;
    }
    else if (b[lenb-1] == 0) lenbb--;
    arithlib_assert(lenbb >= 2);
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
        {   push(a);
            r = reserve(lena);
            pop(a);
            olenr = lena;
            internal_copy(a, lena, r);
            lenr = lena;
        }
        if (b_negative) abandon(bb);
        return;
    }
// Now lena >= lenb >= 2 and I will need to do a genuine long division. This
// will need me to allocate some workspace.
//
// Because I will scale the divisor I need that to be a copy of the
// original data even if that has been positive and so I had not copied
// it yet. I delay creation of that copy until now because that lets my
// avoid a spurious allocation in the various small cases.
    if (!b_negative)
    {   push(a); push(b);
        bb = reserve(lenb);
        pop(b); pop(a);
        olenr = lenb;
        internal_copy(b, lenbb, bb);
    }
#ifdef DEBUG_OVERRUN
    if (debug_arith) arithlib_assert(bb[olenr] == 0xaaaaaaaaaaaaaaaa);
#endif
// If I actually return the quotient I may need to add a leading 0 or -1 to
// make its 2s complement representation valid. Hence the "+2" rather than
// the more obvious "+1" here.
    if (want_q)
    {   lenq = lena - lenb + 2;
        push(a); push(b); push(bb);
        q = reserve(lenq);
        pop(bb); pop(b); pop(a);
        olenq = lenq;
    }
// I will need space where I store something that starts off as a scaled
// copy of the dividend and gradually have values subtracted from it until
// it ends up as the remainder.
    lenr = lena;
    push(a); push(b); push(bb);
    if (want_q) push(q);
    r = reserve(lenr+1);
    if (want_q) pop(q);
    pop(bb); pop(b); pop(a);
    bool a_negative = negative(a[lena-1]);
    if (a_negative) internal_negate(a, lena, r);
    else internal_copy(a, lena, r);
    unsigned_long_division(r, lenr, bb, lenbb, want_q, q, olenq, lenq);
#ifdef DEBUG_OVERRUN
    if (debug_arith) arithlib_assert(r[lena+1] == 0xaaaaaaaaaaaaaaaa);
#endif
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
    arithlib_assert(lenr<=lenb);
    if (want_r) internal_copy(r, lenr, bb);
    abandon(r);
    if (want_q)
    {   if (negative(q[lenq-1]))
        {   arithlib_assert(lenq < olenq);
            q[lenq++] = 0;
        }
        if (a_negative != b_negative)
        {   internal_negate(q, lenq, q);
            truncate_negative(q, lenq);
        }
        else truncate_positive(q, lenq);
    }
//  else abandon(q);
    if (want_r)
    {   r = bb;
        if (negative(r[lenr-1]))
        {   arithlib_assert(lenr < olenr);
            r[lenr++] = 0;
        }
        if (a_negative)
        {   internal_negate(r, lenr, r);
            truncate_negative(r, lenr);
        }
        else truncate_positive(r, lenr);
    }
    else abandon(bb);
}

// During long division I will scale my numbers by shifting left by an
// amount s. I do that in place. The shift amount will be such that
// the divisor ends up with the top bit of its top digit set. The
// dividend will need to extend into an extra digit, and I deal with that
// by returning the overflow word as a result of the scaling function. Note
// that the shift amount will be in the range 0-63.


inline std::uint64_t scale_for_division(std::uint64_t *r,
                                        std::size_t lenr,
                                        int s)
{
// There are two reasons for me to treat a shift by zero specially. The
// first is that it is cheap because no data needs moving at all. But the
// more subtle reason is that if I tried using the general code as below
// that would execute a right shift by 64, which is out of the proper range
// for C++ right shifts.
    if (s == 0) return 0;
    std::uint64_t carry = 0;
    for (std::size_t i=0; i<lenr; i++)
    {   std::uint64_t w = r[i];
        r[i] = (w << s) | carry;
        carry = w >> (64-s);
    }
    return carry;
}

// r = r - b*q*base^(lena-lenb-1).

inline void multiply_and_subtract(std::uint64_t *r, std::size_t lenr,
                                  std::uint64_t q0,
                                  std::uint64_t *b, std::size_t lenb)
{   arithlib_assert(lenr > lenb);
    std::uint64_t hi = 0, lo, carry = 1;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(b[i], q0, hi, hi, lo);
// lo is now the next digit of b*q, and hi needs to be carried up to the
// next one.
        carry = add_with_carry(r[i+lenr-lenb-1], ~lo, carry,
                               r[i+lenr-lenb-1]);
    }
    r[lenr-1] = r[lenr-1] + ~hi + carry;
}

// add_back_correction() is used when a quotient digit was mis-predicted by
// 1 and I detect that when I calculate r = r - b*q and end up with r negative
// result. I fix things up by decrementing q and going
//         r = r + (b<<(lenr-lenb-1))

inline void add_back_correction(std::uint64_t *r, std::size_t lenr,
                                std::uint64_t *b, std::size_t lenb)
{   arithlib_assert(lenr > lenb);
    std::uint64_t carry = 0;
    for (std::size_t i=0; i<lenb; i++)
        carry = add_with_carry(r[i+lenr-lenb-1], b[i], carry,
                               r[i+lenr-lenb-1]);
    r[lenr-1] += carry;
}

inline std::uint64_t next_quotient_digit(std::uint64_t *r,
        std::size_t &lenr,
        std::uint64_t *b, std::size_t lenb)
{   arithlib_assert(lenr > lenb);
    arithlib_assert(lenb >= 2);
    arithlib_assert(b[lenb-1] != 0);
    std::uint64_t q0, r0;
    if (r[lenr-1] == b[lenb-1])
    {   q0 = static_cast<std::uint64_t>(-1);
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
        std::uint64_t hi, lo;
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
        add_back_correction(r, lenr, b, lenb);
    }
    lenr--;  // a is now one digit shorter.
    return q0;
}

// r is an unsigned number. Shift right (in place) by s bits, where s
// is in the range 0 - 63. The bits shifted out to the right should all
// be zero.

inline void unscale_for_division(std::uint64_t *r, std::size_t &lenr,
                                 int s)
{   if (s != 0)
    {   std::uint64_t carry = 0;
        std::size_t i = lenr-1;
        for (;;)
        {   std::uint64_t w = r[i];
            r[i] = (w >> s) | carry;
            carry = w << (64-s);
            if (i == 0) break;
            i--;
        }
        arithlib_assert(carry==0);
    }
    truncate_unsigned(r, lenr);
}

// This function does long division on unsigned values, computing the
// quotient (a/b). In doing so it updates (a) so that at the end it holds
// the remainder. It only fills in a value for the quotient q if want_q is
// true. Note also that this code will scale (b) so that the top bit of its
// highest digit is a "1", so b must be an array that can be overwritten
// without disturbing code elsewhere.

inline void unsigned_long_division(std::uint64_t *a,
                                   std::size_t &lena,
                                   std::uint64_t *b, std::size_t &lenb,
                                   bool want_q, std::uint64_t *q,
                                   std::size_t &olenq, std::size_t &lenq)
{   arithlib_assert(lenb >= 2);
    arithlib_assert(lena >= lenb);
// I will multiply a and b by a scale factor that gets the top digit of "b"
// reasonably large. The value stored in "a" can become one digit longer,
// but there is space to store that.
//
// The scaling is done here using a shift, which seems cheaper to sort out
// then multiplication by a single-digit value.
    arithlib_assert(b[lenb-1] != 0);
    int ss = nlz(b[lenb-1]);
// When I scale the dividend expands into an extra digit but the scale
// factor has been chosen so that the divisor does not.
    a[lena] = scale_for_division(a, lena, ss);
    lena++;
    arithlib_assert(scale_for_division(b, lenb, ss) == 0);
    lenq = lena-lenb; // potential length of quotient.
    std::size_t m = lenq-1;
    for (;;)
    {   std::uint64_t qd = next_quotient_digit(a, lena, b, lenb);
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
        else truncate_unsigned(q, lenq);
    }
    if (negative(a[lena-1])) a[lena++] = 0;
    else truncate_unsigned(a, lena);
}

// Use unsigned_long_division when all that is required is the remainder.
// Here a>b and b is at least 2 words. The code corrupts b and replaces
// a with remainder(a, b).

inline void unsigned_long_remainder(std::uint64_t *a,
                                    std::size_t &lena,
                                    std::uint64_t *b, std::size_t &lenb)
{   std::size_t w;
    unsigned_long_division(a, lena, b, lenb,
                           false, NULL, w, w);
}

inline std::intptr_t Quotient::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             false, r, olenr, lenr);
    return confirm_size(q, olenq, lenq);
}

inline std::intptr_t Quotient::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    std::uint64_t bb[1] = {static_cast<std::uint64_t>(b)};
    division(a, lena, bb, 1,
             true, q, olenq, lenq,
             false, r, olenr, lenr);
    return confirm_size(q, olenq, lenq);
}

// A fixnum divided by a bignum ought always to yield 0, except that
// maybe -0x8000000000000000} / {0,0x8000000000000000) => -1

inline std::intptr_t Quotient::op(std::int64_t a, std::uint64_t *b)
{   if (number_size(b)==1 &&
        b[0]==-static_cast<std::uint64_t>(a)) return int_to_handle(-1);
    return int_to_handle(0);
}

// unpleasantly -0x8000000000000000 / -1 => a bignum

inline std::intptr_t Quotient::op(std::int64_t a, std::int64_t b)
{   if (b==-1 && a == MIN_FIXNUM) return int_to_bignum(-a);
    else return int_to_handle(a / b);
}

inline std::intptr_t Remainder::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    return confirm_size(r, olenr, lenr);
}

inline std::intptr_t Remainder::op(std::uint64_t *a, std::int64_t b)
{   std::size_t lena = number_size(a);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    std::uint64_t bb[1] = {static_cast<std::uint64_t>(b)};
    division(a, lena, bb, 1,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    return confirm_size(r, olenr, lenr);
}

inline std::intptr_t Remainder::op(std::int64_t a, std::uint64_t *b)
{   if (number_size(b)==1 &&
        b[0]==-static_cast<std::uint64_t>(a)) return int_to_handle(0);
    return int_to_handle(a);
}

inline std::intptr_t Remainder::op(std::int64_t a, std::int64_t b)
{   return int_to_handle(a % b);
}



#ifdef LISP

// In LISP mode I provide a function that returns both quotient and
// remainder. In the other two modes I support the same idea but
// as a function that delivers the quotient as its result and saves
// the remainder via an additional argument.

}

namespace arithlib_implementation
{

inline std::intptr_t Divide::op(std::uint64_t *a, std::uint64_t *b)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirm_size(r, olenr, lenr);
    std::intptr_t qq = confirm_size_x(q, olenq, lenq);
#ifdef ZAPPA
    return cons(qq, rr).v;
#else
    return cons(qq, rr);
#endif
}

inline std::intptr_t Divide::op(std::uint64_t *a, std::int64_t bb)
{   std::size_t lena = number_size(a);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    std::uint64_t b[1] = {static_cast<std::uint64_t>(bb)};
    division(a, lena, b, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirm_size(r, olenr, lenr);
    std::intptr_t qq = confirm_size_x(q, olenq, lenq);
#ifdef ZAPPA
    return cons(qq, rr).v;
#else
    return cons(qq, rr);
#endif
}

inline std::intptr_t Divide::op(std::int64_t aa, std::uint64_t *b)
{   std::size_t lenb = number_size(b);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    std::uint64_t a[1] = {static_cast<std::uint64_t>(aa)};
    division(a, 1, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirm_size(r, olenr, lenr);
    std::intptr_t qq = confirm_size_x(q, olenq, lenq);
#ifdef ZAPPA
    return cons(qq, rr).v;
#else
    return cons(qq, rr);
#endif
}

inline std::intptr_t Divide::op(std::int64_t aa, std::int64_t bb)
{   std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    std::uint64_t a[1] = {static_cast<std::uint64_t>(aa)};
    std::uint64_t b[1] = {static_cast<std::uint64_t>(bb)};
    division(a, 1, b, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirm_size(r, olenr, lenr);
    std::intptr_t qq = confirm_size_x(q, olenq, lenq);
#ifdef ZAPPA
    return cons(qq, rr).v;
#else
    return cons(qq, rr);
#endif
}

#else

inline std::intptr_t Divide::op(std::uint64_t *a, std::uint64_t *b,
                                std::intptr_t &rem)
{   std::size_t lena = number_size(a);
    std::size_t lenb = number_size(b);
    std::uint64_t *q, *r;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    rem = confirm_size(r, olenr, lenr);
    return confirm_size_x(q, olenq, lenq);
}

#endif

// a = a - b*q.

inline bool reduce_for_gcd(std::uint64_t *a, std::size_t lena,
                           std::uint64_t q,
                           std::uint64_t *b, std::size_t lenb)
{   arithlib_assert(lena == lenb || lena == lenb+1);
    std::uint64_t hi = 0, hi1, lo, borrow = 0;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(b[i], q, hi1, lo);
        hi1 += subtract_with_borrow(a[i], hi, a[i]);
        borrow = subtract_with_borrow(a[i], lo, borrow, a[i]);
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

// The next function performs a = a = b*(q<<shift), but
// it computes it more as a = a - (b<<shift)*q.
// It will be used with 0 < shift < 64, ie only when a genuine shift
// between digits is required.
inline bool shifted_reduce_for_gcd(std::uint64_t *a, std::size_t lena,
                                   std::uint64_t q,
                                   std::uint64_t *b, std::size_t lenb,
                                   int shift)
{   arithlib_assert(lena == lenb+1 || lena == lenb+2);
    std::uint64_t hi = 0, hi1, lo, borrow = 0;
    for (std::size_t i=0; i<=lenb; i++)
    {   multiply64(shifted_digit(b, lenb, shift, i), q, hi1, lo);
        hi1 += subtract_with_borrow(a[i], hi, a[i]);
        borrow = subtract_with_borrow(a[i], lo, borrow, a[i]);
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

inline bool ua_minus_vb(std::uint64_t *a, std::size_t lena,
                        std::uint64_t u,
                        std::uint64_t *b, std::size_t lenb,
                        std::uint64_t v,
                        std::uint64_t *r, std::size_t &lenr)
{   arithlib_assert(lena == lenb || lena == lenb+1);
    std::uint64_t hia, loa, ca = 0, hib, lob, cb = 0, borrow = 0;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(a[i], u, hia, loa);
// hia is the high part of a product so carrying 1 into it can not cause it
// to overflow. Just!
        hia += add_with_carry(loa, ca, loa);
        multiply64(b[i], v, hib, lob);
        hib += add_with_carry(lob, cb, lob);
        borrow = subtract_with_borrow(loa, lob, borrow, r[i]);
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
        hia += add_with_carry(loa, ca, loa);
        borrow = subtract_with_borrow(loa, cb, borrow, r[lena-1]);
        lenr = lena;
        return negative(hia - borrow);
    }
    return negative(ca - cb - borrow);
}

// Since the code here is quite short I will also provide a version
// for r = -u*a + b*v;
// Again this supposes that a is at least as long as b.

inline bool minus_ua_plus_vb(std::uint64_t *a, std::size_t lena,
                             std::uint64_t u,
                             std::uint64_t *b, std::size_t lenb,
                             std::uint64_t v,
                             std::uint64_t *r, std::size_t &lenr)
{   arithlib_assert(lena == lenb || lena == lenb+1);
    std::uint64_t hia, loa, ca = 0, hib, lob, cb = 0, borrow = 0;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(a[i], u, hia, loa);
        hia += add_with_carry(loa, ca, loa);
        multiply64(b[i], v, hib, lob);
        hib += add_with_carry(lob, cb, lob);
        borrow = subtract_with_borrow(lob, loa, borrow, r[i]);
        ca = hia;
        cb = hib;
    }
    lenr = lenb;
    if (lena > lenb)
    {   multiply64(a[lena-1], u, hia, loa);
        hia += add_with_carry(loa, ca, loa);
        borrow = subtract_with_borrow(cb, loa, borrow, r[lena-1]);
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

inline void gcd_reduction(std::uint64_t *&a, std::size_t &lena,
                          std::uint64_t *&b, std::size_t &lenb,
                          std::size_t &olena, std::size_t &olenb,
                          std::uint64_t *&temp, std::size_t &lentemp)
{
// I will start by collecting high bits from a and b. If I collect the
// contents of the top 3 words (ie 192 bits in all) then I will be able
// to normalize that to get 128 bits to work with however the top bits
// of a and b lie within the words.
    std::uint64_t a0=a[lena-1], a1=a[lena-2], a2=(lena>2 ? a[lena-3] : 0);
    int lza = nlz(a0);
    std::uint64_t b0=b[lenb-1], b1=b[lenb-2], b2=(lenb>2 ? b[lenb-3] : 0);
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
    std::int64_t diff = 64*(lena-lenb) + lzb - lza;
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
        std::int64_t ua = 1, va = 0, ub = 0, vb = 1;
        while (b0!=0 || b1!=0)
        {   std::uint64_t q;
// Here I want to set q = {a0,a1}/{b0,b1}, and I expect that the answer
// is a reasonably small integer. But it could potentially be huge.
// At least I have filtered away the possibility {b0,b1}={0,0}.
// I will grab the top 64 bits of a and the top corresponding bits of b,
// because then I can do a (cheap) 64-by-64 division.
            int lza1 = a0==0 ? 64+nlz(a1) : nlz(a0);
            int lzb1 = b0==0 ? 64+nlz(b1) : nlz(b0);
            if (lzb1 > lza1+60) break; // quotient will be too big
            std::uint64_t ahi, bhi;
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
            arithlib_assert(q != 0);
// Now I need to go
//              ua -= q*va;
//              ub -= q*vb;
//              {a0,a1} -= q*{b0,b1}
// Then if a is negative I will negate a and ua and ub.
// Finally, if (as I mostly expect) now a<b I swap a<=>b, ua<=>ub and va<=>vb
// If I would get an overflow in updating ua or ub I will break out of the
// loop.
            std::int64_t h;
            std::uint64_t l1, l2;
            signed_multiply64(q, va, h, l1);
            if (static_cast<std::uint64_t>(h) + (l1>>63) != 0) break;
// There could be overflow in the following subtraction... So I check
// if that was about to happen and break out of the loop if so.
            if (ua >= 0)
            {   if (ua - INT64_MAX > static_cast<std::int64_t>(l1)) break;
            }
            else if (ua - INT64_MIN < static_cast<std::int64_t>(l1)) break;
            signed_multiply64(q, vb, h, l2);
            if (static_cast<std::uint64_t>(h) + (l2>>63) != 0) break;
            if (ub >= 0)
            {   if (ub - INT64_MAX > static_cast<std::int64_t>(l2)) break;
            }
            else if (ub - INT64_MIN < static_cast<std::int64_t>(l2)) break;
// I must either update both or neither of ua, ub.
            ua -= l1;
            ub -= l2;
            std::uint64_t hi, lo;
            multiply64(q, b1, hi, lo);
            hi += subtract_with_borrow(a1, lo, a1);
            std::uint64_t borrow = subtract_with_borrow(a0, hi, a0);
            borrow += subtract_with_borrow(a0, q*b0, a0);
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
        if (temp == NULL)
        {   push(a);
            push(b);
            temp = reserve(lena>lenb ? lena : lenb);
            pop(b);
            pop(a);
        }
        if (ub < 0)
        {   arithlib_assert(ua >= 0);
            if (ua_minus_vb(a, lena, ua, b, lenb, -ub, temp, lentemp))
                internal_negate(temp, lentemp, temp);
        }
        else
        {   arithlib_assert(ua <= 0);
            if (minus_ua_plus_vb(a, lena, -ua, b, lenb, ub, temp, lentemp))
                internal_negate(temp, lentemp, temp);
        }
        truncate_unsigned(temp, lentemp);
        if (vb < 0)
        {   arithlib_assert(va >= 0);
            if (ua_minus_vb(a, lena, va, b, lenb, -vb, a, lena))
                internal_negate(a, lena, a);
        }
        else
        {   arithlib_assert(va <= 0);
            if (minus_ua_plus_vb(a, lena, -va, b, lenb, vb, a, lena))
                internal_negate(a, lena, a);
        }
        truncate_unsigned(a, lena);
        internal_copy(temp, lentemp, b);
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
    std::uint64_t q, r;
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
    {   std::size_t bits_to_lose = 64 - diff;
// I will shift q right, but doing so in such a way that I try to round to
// nearest.
        if (bits_to_lose != 0)
        {   q = q >> (bits_to_lose-1);
            q = (q >> 1) + (q & 1);
        }
// Now just do "a = a-q*b;", then ensure that the result is positive
// and clear away any leading zeros left in its representation.
        if (reduce_for_gcd(a, lena, q, b, lenb))
            internal_negate(a, lena, a);
        truncate_unsigned(a, lena);
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
                internal_negate(a, lena, a);
            truncate_unsigned(a, lena);
        }
        else
        {   std::size_t diffw = diff/64;
            diff = diff%64;
            if (shifted_reduce_for_gcd(a+diffw-1, lena+1-diffw,
                                       q, b, lenb, diff))
                internal_negate(a, lena, a);
            truncate_unsigned(a, lena);
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


inline std::intptr_t Gcd::op(std::uint64_t *a, std::uint64_t *b)
{   if (number_size(b) == 1) return Gcd::op(a,
                                                static_cast<std::int64_t>(b[0]));
// I will start by making copies of |a| and |b| that I can overwrite
// during the calculation and use part of in my result.
    std::size_t lena = number_size(a), lenb = number_size(b);
    std::size_t olena = lena, olenb = lenb;
    if (olena == olenb &&
        // See comments later for an explanation of this!
        negative(a[lena-1]) && negative(b[lenb-1]) &&
        a[lena-1] == b[lenb-1]) olena++;
    push(a); push(b);
    std::uint64_t *av = reserve(olena);
    pop(b); pop(a);
    if (negative(a[lena-1])) internal_negate(a, lena, av);
    else internal_copy(a, lena, av);
    push(av); push(b);
    std::uint64_t *bv = reserve(olenb);
    pop(b); pop(av);
    if (negative(b[lenb-1])) internal_negate(b, lenb, bv);
    else internal_copy(b, lenb, bv);
    a = av;
    b = bv;
    if (big_unsigned_greaterp(b, lenb, a, lena))
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
    {   std::uint64_t bb = b[0];
        std::uint64_t hi = 0, q;
        for (std::size_t i=lena-1;; i--)
        {   divide64(hi, a[i], bb, q, hi);
            if (i == 0) break;
        }
        while (hi != 0)
        {   std::uint64_t cc = bb % hi;
            bb = hi;
            hi = cc;
        }
        abandon(a);
        abandon(b);
        return unsigned_int_to_bignum(bb);
    }
// In some cases performing a reduction will require a workspace vector.
// I will only allocate this as and when first needed.
    std::uint64_t *temp = NULL;
    std::size_t lentemp = lena;
// Now at last a and b and genuine unsigned vectors without leading digits
// and with a > b. The next line is the key iteration in this whole procedure.
    while (lenb != 1)
    {   gcd_reduction(a, lena, b, lenb, olena, olenb, temp, lentemp);
        if (big_unsigned_greaterp(b, lenb, a, lena))
        {   std::swap(a, b);
            std::swap(lena, lenb);
            std::swap(olena, olenb);
        }
    }
    if (temp != NULL) abandon(temp);
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
            {   internal_copy(a, lena, b);
                abandon(a);
                a = b;
                olena = olenb;
            }
            else abandon(b);
#ifdef DEBUG_OVERRUN
            if (debug_arith)
            {   arithlib_assert(a[olena] == 0xaaaaaaaaaaaaaaaaU);
            }
#endif
            a[lena++] = 0;
#ifdef DEBUG_OVERRUN
            if (debug_arith)
            {   arithlib_assert(a[olena] == 0xaaaaaaaaaaaaaaaaU);
            }
#endif
        }
        else abandon(b);
        return confirm_size(a, olena, lena);
    }
// If b is not zero here then it represents a value up to 2^64-1, and I can
// complete the GCD by doing a long-by-short remainder and then a short-num
// GCD...
    std::uint64_t bb = b[0];
    abandon(b);
    std::uint64_t hi = 0, q;
    for (std::size_t i=lena-1;; i--)
    {   divide64(hi, a[i], bb, q, hi);
        if (i == 0) break;
    }
    abandon(a);
    while (hi != 0)
    {   std::uint64_t cc = bb % hi;
        bb = hi;
        hi = cc;
    }
    return unsigned_int_to_bignum(bb);
}

inline std::intptr_t Gcd::op(std::uint64_t *a, std::int64_t bb)
{
// This case involved doing a long-by-short remainder operation and then
// it reduces to the small-small case. The main problem is the handling of
// negative inputs.
    std::uint64_t b = bb < 0 ? -bb : bb;
    std::size_t lena = number_size(a);
    bool signa = negative(a[lena-1]);
    std::uint64_t hi = 0, q;
    for (std::size_t i=lena-1;; i--)
    {   divide64(hi, (signa ? ~a[i] : a[i]), b, q, hi);
        if (i == 0) break;
    }
// Now if a had been positive we have hi=a%b. If a had been negative we
// have (~a)%b == (-a-1)%b which is about |a|%b -1
    if (signa) hi = (hi+1)%b;
    return Gcd::op(b, hi);
}

inline std::intptr_t Gcd::op(std::int64_t a, std::uint64_t *b)
{   return Gcd::op(b, a);
}

inline std::intptr_t Gcd::op(std::int64_t a, std::int64_t b)
{
// Take absolute values of both arguments.
    std::uint64_t aa = a < 0 ? -static_cast<std::uint64_t>(a) : a;
    std::uint64_t bb = b < 0 ? -static_cast<std::uint64_t>(b) : b;
// Ensure that aa >= bb
    if (bb > aa) std::swap(aa, bb);
// Do simple Euclidean algorithm
    while (bb != 0)
    {   std::uint64_t cc = aa % bb;
        aa = bb;
        bb = cc;
    }
// A messy case is gcd(-MIX_FIXNUM, MIN_FIXNUM) which yields -MIN_FIXNUM
// which is liable to be MAX_FIXNUM+1 and so has to be returned as a bignum.
    return unsigned_int_to_bignum(aa);
}

// I think I have space-leaks within my code for LCM. For use in
// a system with garbage collection that will not matter (hoorah) but at
// some stage I need to come back here and look harder and tidy things up.

inline std::intptr_t Lcm::op(std::uint64_t *a, std::uint64_t *b)
{   push(a); push(b);
    std::intptr_t g = Gcd::op(a, b);
    pop(b);
    std::intptr_t q = op_dispatch2<Quotient,std::intptr_t>
                      (vector_to_handle(b),
                       g);
    pop(a);
    q = op_dispatch2<Times,std::intptr_t>(vector_to_handle(a), q);
    return op_dispatch1<Abs,std::intptr_t>(q);
}

inline std::intptr_t Lcm::op(std::uint64_t *a, std::int64_t b)
{   push(a);
    std::intptr_t g = Gcd::op(a, b);
    std::intptr_t q = op_dispatch2<Quotient,std::intptr_t>(int_to_handle(
                          b), g);
    pop(a);
    q = op_dispatch2<Times,std::intptr_t>(vector_to_handle(a), q);
    return op_dispatch1<Abs,std::intptr_t>(q);
}

inline std::intptr_t Lcm::op(std::int64_t a, std::uint64_t *b)
{   return Lcm::op(b, a);
}

inline std::intptr_t Lcm::op(std::int64_t a, std::int64_t b)
{   std::intptr_t g = Gcd::op(a, b);
// The GCD can only be a bignum if a = b = MIN_FIXNUM.
    if (stored_as_fixnum(g))
    {   b = b / int_of_handle(g);
        std::intptr_t q = Times::op(a, b); // possibly a bignum now
        return op_dispatch1<Abs,std::intptr_t>(q);
    }
    else return unsigned_int_to_bignum(-static_cast<std::uint64_t>
                                           (MIN_FIXNUM));
}

#ifdef CSL
// Support for calculations modulo some integer value...

// While initially developing this bit of code I will assume C++17 and I
// will not have the code thread-safe. Both of those issues can be
// addressed later!

static const int modulus_32 = 0;
static const int modulus_64 = 1;
static const int modulus_big = 2;
/*thread_local*/ inline int modulus_size = 0;
/*thread_local*/ inline std::uint64_t small_modulus = 2;
/*thread_local*/ inline std::vector<std::uint64_t>
large_modulus_vector;

inline std::uint64_t *large_modulus()
{   return 1 + reinterpret_cast<std::uint64_t *>
           (large_modulus_vector.data());
}

inline std::intptr_t value_of_current_modulus()
{   if (modulus_size == modulus_big)
    {   std::size_t n = number_size(large_modulus());
        std::uint64_t *r = reserve(n);
        std::memcpy(r, large_modulus(), n*sizeof(std::uint64_t));
        return confirm_size(r, n, n);
    }
    else return int_to_handle(small_modulus);
}

inline std::intptr_t SetModulus::op(std::int64_t n)
{   if (n <= 1) aerror1("Invalid arg to set-modulus",
                            int_to_handle(n));
    std::intptr_t r = value_of_current_modulus();
    small_modulus = n;
    if (n <= 0xffffffffU) modulus_size = modulus_32;
    else modulus_size = modulus_64;
    return r;
}

inline std::intptr_t SetModulus::op(std::uint64_t *n)
{   if (Minusp::op(n))
        aerror1("Invalid arg to set-modulus", vector_to_handle(n));
    std::intptr_t r = value_of_current_modulus();
    std::size_t lenn = number_size(n);
    std::size_t bytes = (lenn+1)*sizeof(std::uint64_t);
    if (bytes > large_modulus_vector.size())
        large_modulus_vector.resize(bytes);
    std::memcpy(large_modulus_vector.data(), &n[-1], bytes);
    modulus_size = modulus_big;
    return r;
}

inline std::intptr_t ModularNumber::op(std::int64_t a)
{   if (a >= 0)
    {   if (modulus_size == modulus_big) return int_to_handle(a);
        else return int_to_handle(a % small_modulus);
    }
    if (modulus_size == modulus_big) return Plus::op(large_modulus(), a);
    else
    {   a = a % small_modulus;
        if (a < 0) a += small_modulus;
        return int_to_handle(a);
    }
}

inline std::intptr_t ModularNumber::op(std::uint64_t *a)
{   if (Minusp::op(a))
    {   std::intptr_t r = Remainder::op(a, large_modulus());
        if (Minusp::op(r))
        {   std::intptr_t r1 = op_dispatch1<Plus,std::intptr_t>(r,
                               large_modulus());
            abandon(r);
            return r1;
        }
        else return r;
    }
    else return Remainder::op(a, large_modulus());
}

inline std::intptr_t ModularPlus::op(std::int64_t a, std::int64_t b)
{   std::uint64_t ua = a, ub = b;
// Because a and b are 64-bit signed values and they should be positive,
// their sum will fit within a 64-bit unsigned integer, but if the modulus
// is large it could be just a 1-word bignum...
    if (modulus_size == modulus_big)
    {   std::uint64_t r = ua + ub;
        if (number_size(large_modulus()) == 1 &&
            r >= large_modulus()[0]) r -= large_modulus()[0];
        return unsigned_int_to_bignum(r);
    }
    std::uint64_t r = ua + ub;
    if (r >= small_modulus) r -= small_modulus;
    return int_to_handle(static_cast<std::int64_t>(r));
}

inline std::intptr_t ModularPlus::op(std::int64_t a, std::uint64_t *b)
{
// One of the inputs here is a bignum, and that can only be valid if we
// have a large modulus.
    if (modulus_size != modulus_big) aerror1("bad arg for modular-plus",
                vector_to_handle(b));
    std::intptr_t r = Plus::op(a, b);
    if (op_dispatch1<Geq,bool>(r, large_modulus()))
    {   std::intptr_t r1 = op_dispatch1<Difference,std::intptr_t>(r,
                           large_modulus());
        abandon(r);
        return r1;
    }
    else return r;
}

inline std::intptr_t ModularPlus::op(std::uint64_t *a, std::int64_t b)
{   return ModularPlus::op(b, a);
}

inline std::intptr_t ModularPlus::op(std::uint64_t *a,
                                     std::uint64_t *b)
{   if (modulus_size != modulus_big)
        aerror1("bad arg for modular-plus",
                vector_to_handle(a));
    std::intptr_t r = Plus::op(a, b);
    if (op_dispatch1<Geq, bool>(r, large_modulus()))
    {   std::intptr_t r1 = op_dispatch1<Difference,std::intptr_t>(r,
                           large_modulus());
        abandon(r);
        return r1;
    }
    else return r;
}

inline std::intptr_t ModularDifference::op(std::int64_t a,
        std::int64_t b)
{   if (a >= b) return int_to_handle(a - b);
    if (modulus_size == modulus_big) return Plus::op(large_modulus(),
                                                a - b);
    else return int_to_handle(small_modulus - b + a);
}

inline std::intptr_t ModularDifference::op(std::int64_t a,
        std::uint64_t *b)
{   if (modulus_size != modulus_big)
        aerror1("bad arg for modular-plus",
                vector_to_handle(b));
    std::intptr_t r = Difference::op(b, a);
    std::intptr_t r1 = op_dispatch1<RevDifference,std::intptr_t>(r,
                       large_modulus());
    abandon(r);
    return r1;
}

inline std::intptr_t ModularDifference::op(std::uint64_t *a,
        std::int64_t b)
{   if (modulus_size != modulus_big)
        aerror1("bad arg for modular-plus",
                vector_to_handle(a));
    return Difference::op(a, b);
}

inline std::intptr_t ModularDifference::op(std::uint64_t *a,
        std::uint64_t *b)
{   if (modulus_size != modulus_big)
        aerror1("bad arg for modular-plus",
                vector_to_handle(a));
    if (Geq::op(a, b)) return Difference::op(a, b);
    std::intptr_t r = Difference::op(b, a);
    std::intptr_t r1 = op_dispatch1<RevDifference,std::intptr_t>(r,
                       large_modulus());
    abandon(r);
    return r1;
}


inline std::intptr_t ModularTimes::op(std::int64_t a, std::int64_t b)
{   switch (modulus_size)
    {   case modulus_32:
            return int_to_handle(static_cast<std::uint64_t>(a)
                                 *static_cast<std::uint64_t>
                                 (b) % small_modulus);
        case modulus_64:
        {   std::uint64_t hi, lo, q, r;
            multiply64(static_cast<std::uint64_t>(a),
                       static_cast<std::uint64_t>(b), hi,
                       lo);
            divide64(hi, lo, small_modulus, q, r);
            return int_to_handle(r);
        }
        default:
        case modulus_big:
        {   std::intptr_t w = Times::op(a, b);
            std::intptr_t r = op_dispatch1<Remainder,std::intptr_t>(w,
                              large_modulus());
            abandon(w);
            return r;
        }
    }
}

inline std::intptr_t ModularTimes::op(std::int64_t a,
                                      std::uint64_t *b)
{   std::intptr_t w = Times::op(a, b);
    std::intptr_t r = op_dispatch1<Remainder,std::intptr_t>(w,
                      large_modulus());
    abandon(w);
    return r;
}

inline std::intptr_t ModularTimes::op(std::uint64_t *a,
                                      std::int64_t b)
{   return ModularTimes::op(b, a);
}

inline std::intptr_t ModularTimes::op(std::uint64_t *a,
                                      std::uint64_t *b)
{   std::intptr_t w = Times::op(a, b);
    std::intptr_t r = op_dispatch1<Remainder,std::intptr_t>(w,
                      large_modulus());
    abandon(w);
    return r;
}


inline std::intptr_t ModularExpt::op(std::int64_t a, std::int64_t b)
{   aerror("incomplete");
}

inline std::intptr_t ModularExpt::op(std::int64_t a, std::uint64_t *b)
{   aerror("incomplete");
}

inline std::intptr_t ModularExpt::op(std::uint64_t *a, std::int64_t b)
{   aerror("incomplete");
}

inline std::intptr_t ModularExpt::op(std::uint64_t *a,
                                     std::uint64_t *b)
{   aerror("incomplete");
}


inline std::intptr_t ModularQuotient::op(std::int64_t a,
        std::int64_t b)
{   aerror("incomplete");
}

inline std::intptr_t ModularQuotient::op(std::int64_t a,
        std::uint64_t *b)
{   aerror("incomplete");
}

inline std::intptr_t ModularQuotient::op(std::uint64_t *a,
        std::int64_t b)
{   aerror("incomplete");
}

inline std::intptr_t ModularQuotient::op(std::uint64_t *a,
        std::uint64_t *b)
{   aerror("incomplete");
}


inline std::intptr_t ModularMinus::op(std::int64_t a)
{   if (a == 0) return int_to_handle(a);
    if (modulus_size == modulus_big)
        return Difference::op(large_modulus(), a);
    else return int_to_handle(small_modulus - a);
}

inline std::intptr_t ModularMinus::op(std::uint64_t *a)
{   if (modulus_size != modulus_big)
        aerror1("bad argument for modular-minus", vector_to_handle(a));
    return Difference::op(large_modulus(), a);
}

inline std::intptr_t general_modular_reciprocal(std::intptr_t a)
{   aerror("not coded yet");
}

inline std::intptr_t ModularReciprocal::op(std::int64_t aa)
{   if (aa <= 0) aerror1("bad argument to modular-reciprocal",
                             int_to_handle(aa));
    else if (modulus_size == modulus_big)
        return general_modular_reciprocal(int_to_handle(aa));
    std::int64_t a = small_modulus,
                 b = aa,
                 x = 0,
                 y = 1;
    while (b != 1)
    {   std::uint64_t w, t;
        if (b == 0)
            aerror2("non-prime modulus in modular-reciprocal",
                    int_to_handle(small_modulus),
                    int_to_handle(aa));
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += small_modulus;
    return int_to_handle(y);
}

inline std::intptr_t ModularReciprocal::op(std::uint64_t *a)
{   return general_modular_reciprocal(vector_to_handle(a));
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

using arithlib_implementation::mersenne_twister;
using arithlib_implementation::reseed;
using arithlib_implementation::uniform_uint64;
using arithlib_implementation::uniform_positive;
using arithlib_implementation::uniform_signed;
using arithlib_implementation::random_upto_bits_bignum;

using arithlib_implementation::display;
using arithlib_implementation::fix_bignum;
}

// I am putting in names that CSL uses here...

namespace arithlib_lowlevel
{
using arithlib_implementation::Plus;
using arithlib_implementation::Difference;
using arithlib_implementation::RevDifference;
using arithlib_implementation::Times;
using arithlib_implementation::Quotient;
using arithlib_implementation::Remainder;
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
using arithlib_implementation::IntegerLength;
using arithlib_implementation::Low_bit;
using arithlib_implementation::Logbitp;
using arithlib_implementation::Logcount;
using arithlib_implementation::Float;
using arithlib_implementation::Double;
using arithlib_implementation::Frexp;
#ifdef CSL
using arithlib_implementation::ModularPlus;
using arithlib_implementation::ModularDifference;
using arithlib_implementation::ModularTimes;
using arithlib_implementation::ModularExpt;
using arithlib_implementation::ModularQuotient;
using arithlib_implementation::ModularMinus;
using arithlib_implementation::ModularReciprocal;
using arithlib_implementation::ModularNumber;
using arithlib_implementation::SetModulus;
#endif // CSL

using arithlib_implementation::bignum_to_string;
using arithlib_implementation::bignum_to_string_length;
using arithlib_implementation::bignum_to_string_hex;
using arithlib_implementation::bignum_to_string_hex_length;
using arithlib_implementation::bignum_to_string_octal;
using arithlib_implementation::bignum_to_string_octal_length;
using arithlib_implementation::bignum_to_string_binary;
using arithlib_implementation::bignum_to_string_binary_length;

using arithlib_implementation::round_double_to_int;
using arithlib_implementation::trunc_double_to_int;
using arithlib_implementation::floor_double_to_int;
using arithlib_implementation::ceiling_double_to_int;

#ifdef softfloat_h
using arithlib_implementation::Float128;
using arithlib_implementation::Frexp128;
using arithlib_implementation::round_float128_to_int;
using arithlib_implementation::trunc_float128_to_int;
using arithlib_implementation::floor_float128_to_int;
using arithlib_implementation::ceiling_float128_to_int;
// These next few are just raw float128_t operations.
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

//using arithlib_implementation::negative;
//using arithlib_implementation::number_size;

using arithlib_implementation::cast_to_float;
}

#endif // __arithlib_hpp

// end of arithlib.hpp
