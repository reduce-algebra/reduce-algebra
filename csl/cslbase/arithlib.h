// "arithlib.h" : Big Number arithmetic.              A C Norman, 2019-2026

#ifndef __arithlib_h
#define __arithlib_h 1

/**************************************************************************
 * Copyright (C) 2019-2026, Codemist.                    A C Norman       *
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

// There are quite a lot of bignumber packages out there on the web,
// but none of them seemed to be such that I could readily use them
// for arithmetic within a Lisp at all easily, for instance because of
// the storage management arangements used.
//
// This code uses 64-bit digits and a 2s complement representation for
// negative numbers. This means it will work best on 64-bit platforms
// (which by now are by far the most important), and it provides bitwise
// logical operations (logand and logor) as well as arithmetic. It will work
// best where the C++ compiler supports a 128-bit integral type, but does not
// need that. It should work on 32-bit systems as well, although one should
// expect performance there to be lower.
//
// The code here arranges that any integer operations that might overflow are
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
//     compilers unconditionally - testing has used versions of g++ and
//     clang on Cygwin, Mingw32, Linux/x86_64, Linux/aarch64 and Apple
//     silicon Macintosh.
// (3) arithlib is coded in C++ not C, and this allows it to leverage features
//     of C++17. For instance it can rely on the random number generation
//     facilities that C++ provides rather than needing to implement its
//     own. There are places within it where template code leads to a neater
//     implementation, and the operator overloading scheme that various other
//     C++ arithmetic packages provide fits in especially naturally. As time
//     passes it will be updated to exploit C++20 and C++23.
// (4) My initial motivation for creating arithlib was a need for a big
//     arithmetic package to form part of the run-time system of a language
//     implementation. arithlib was built with a view to keeping much of the
//     memory allocation and management somewhere else, probably supported
//     by garbage collection. I found it much harder to see how to arrange
//     that the garbage collector in the rest of my run-time system could
//     track the memory usage within GMP, although I am aware that others
//     hava managed that.
// (5) While arithlib is not a totally tiny body of code it is smaller and
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
// My versions of TOOM and FFT multiplication are less elaborate than those in
// gmp. but exploiting thread parallelism means I keep up to an extent that
// leaves me not feeing the need to apologise too much. If this concerns you
// please run your own tests rather than relying on anything I say!
// 
// The benchmark I use only tests multiplication of equally sized numbers and
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
// Finally I need at times to generate a bit-fields using code such as
// (1<<n). If the literal "1" is not introduced using a wide enough type
// this can overflow. So I will use either UINT64_C(1) or ((uint64_t)1).


// Some functions are given inline definitions here, some are merely
// declared and separate files contain the definitions. The choices are
// perhaps not entirely rational and though through, but the idea is
// (.) Functions that may be performance critical tends to be put here
//     so that they can be rendered inline for user code.
// (,) Functions that are very short may end up inline here as a matter
//     of convenience.
// (.) templated things sort of need to be given here!
// (.) There will be functions that I have just not bothered to or not
//     got round to migrating to their own file. 
//
// Cases in point are that most code for addition and logical operations
// on numbers are inline here in the expectation that the code is
// tolerably short and that arithmetic on fairly short bignums (where
// function call overhead would be most intrusive) matters. In a similar
// way the parts of code for multiplication of short numbers is inline,
// with diversion via function calls into code elsewhere reserved for
// use when the numbers get bigger. 


// There is a "version" variable keyed to subversion revision numbers.
#define ARITHLIB_VERSION 2026

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

// [[likely]] and [[unlikely]] come as part of C++20
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
#include <unordered_map>
#include <type_traits>
#include <algorithm>
#include <filesystem>

#include "int128.h"           // (u)int127_t.
#include "bitmaps.h"          // nlz() to count leading zeros.
#include "float128.h"         // FLOAT_128 and COMPLEX_128.
#include "threadloc.h"        // enhanced thread local support.
#include "cthread.h"          // work-farm style parallelism.
#include "acnutil.h"          // compile-time "for" loop etc. Nicer chrono.
#include "lvector.h"          // local vectors of unpredictable size.


namespace arithlib_implementation
{

// My (big) integers are represented with 64-bit digits in a 2s complement
// notation, so the most significant digit is signed and the rest are
// unsigned.

using Digit = std::uint64_t;
using SignedDigit = std::int64_t;

#ifdef DEBUG
using DigitPtr = vecpointer<Digit>;
using ConstDigitPtr = vecpointer<const Digit>;
#else // DEBUG
using DigitPtr = Digit*;
using ConstDigitPtr = const Digit*;
#endif // DEBUG

// At present Digit32 is only used in the code that performs FFTs
// modulo 32-bit primes...

using Digit32 = std::uint32_t;
using SignedDigit32 = std::int32_t;

#ifdef DEBUG
using DigitPtr32 = vecpointer<Digit32>;
using ConstDigitPtr32 = vecpointer<const Digit32>;
#else // DEBUG
using DigitPtr32 = Digit32*;
using ConstDigitPtr32 = const Digit32*;
#endif // DEBUG

// This version number will be the subversion revision of just this
// header file, not of other parts of the library.

inline constexpr int get_version()
{   const char* version_string =
        "$Id$";
// This extracts the subversion revision number from version_string.
    const char *s = version_string;   // "$Id: filename verno ..."
    while (*s++ != ' ');              // " filename verno ..."
    while (*s++ != ' ');              // " verno ..."
    int seq = 0;
    while (std::isdigit(*s))
        seq = 10*seq + *s++ - '0'; 
    return seq;
}

inline const int version = get_version();

// When I get to big-integer multiplication I will use two or three
// worker threads so that elapsed times for really large multiplications
// are reduced somewhat. Well ideally by a factor approaching 3. I have
// a framework of support for the threads called runInThreads.

// Each worker thread needs some data that it shares with the main thread.
// this structure encapsulates that.

// Above this length (measured in 64-bit digits) I will use fast
// multiplication based on FFT.
// The threshold here will depend on the machine you are running on,
// but this is probably close enough across the platforms that I care about.

// Ha ha - I use this startup-time to determine whether I seem to be
// running under the Windows Subbsystem for Linux. I want to know this
// because at least at present it seems that it might impact break-even
// points between various schemes for multiplication.

static bool const under_WSL =
   ([](){
     return std::filesystem::exists("/usr/bin/wslinfo");
   })();

// Multiplications where M and N are both no more than than 7
// are done by unrolled and inlined special code.
// From when the larger is at least KARASTART I will use Karatsuba,
// and from KARABIG on it will not be just Karatsuba but the top
// level decomosition will be run using multiple threads.
// Beyond FFT_THRESHOLD I will use an FFT-based scheme. That means that
// Karatsuba and Toom only ever run on smaller cases than that and so
// the amount of workspace they need is bounded and I can allocate it
// statically.

static constexpr std::size_t MUL_INLINE_LIMIT = 7;

// The thresholds at which I transition from classical multiplication
// to use of Karatsuba (and Toom-3-2) and the one where I activate
// multiple thhreads may want to differ on different machines. I have
// a range of settings with values based on measurements on machines I
// have access to, but the values may well not be quite optimal even there
// and my machines may not yield the experience that others will have!

// By predefining preprocessor symbols KARASTART and KARABIG I can
// override my defaults here.

#ifndef KARASTART

#if defined WIN32                             // Windows (x86_64)
// Tested using x86_64-w64-mingw-g++ on an Intel i7-8086K. 
static const std::size_t KARASTART = 16;

#elif defined __CYGWIN__                      // Windows (x86_64)
// Tested using Cygwin g++ on an Intel i7-8086K. 
static const std::size_t KARASTART = 16;

#elif defined __APPLE__ && defined __arm64__  // Mac m1, m2, ...
// Tested on Macbook m1.
static const std::size_t KARASTART = 25;

#elif defined __ARM_ARCH_8A                   // Raspberry Pi 5
// Measured in a Raspberry Pi 5 running Raspberry Pi OS in 64-bit mode.
static const std::size_t KARASTART = 16;

#elif defined __ARM_ARCH                      // Other Raspberry Pi etc
// Measured on a Raspberry Pi 5.
// If a 32-bit operating system is in use probably 22 would be a better
// number, but by now I will expect "everybody" to be running 64-bit.
static const std::size_t KARASTART = 16;

#else                                         // other (eg generic Linux)
// Figure rather guessed from all the above, but applicable in a Linux
// vm running on the Windows machine I test on!
static const std::size_t KARASTART = 16;
#endif

#endif // KARASTART

#ifndef KARABIG

// Measurements in December 2025 on a Windows 11 machine, with Cygwin and
// under WSL show a need for very high values here - and I do not understand
// what has changed. But eg when I use the same computer and run Linux
// directly I see a much lower cut-off as against running using WSL2.
// Hmmmmmm.

#if defined WIN32                             // Windows (x86_64)
//static const std::size_t KARABIG = 60;
static const std::size_t KARABIG = 400;
#elif defined __CYGWIN__                      // Cygwin/Windows (x86_64)
//static const std::size_t KARABIG = 65;
static const std::size_t KARABIG = 400;
#elif defined __APPLE__ && defined __arm64__  // Mac m1, m2, ...
static const std::size_t KARABIG = 352;
#elif defined __ARM_ARCH_8A                   // Raspberry p 5
static const std::size_t KARABIG = 72;
#elif defined __ARM_ARCH                      // Other Raspberry pi etc
static const std::size_t KARABIG = 50;
#else                                         // other (eg generic Linux)
static std::size_t KARABIG = ([](){ return under_WSL ? 400 : 144;})();
#endif

#endif // KARABIG


#ifndef FFT_THRESHOLD
#ifdef __arm64__
static const std::size_t FFT_THRESHOLD = 5000;
#else // __arm64__
// The next value might plausibly need to depend on whether you are running
// under WSL.
static const std::size_t FFT_THRESHOLD = 10000;
#endif // __arm64__
#endif // FFT_THRESHOLD

extern std::mt19937_64 mersenne_twister;
extern void reseed(Digit);
extern Digit uniformUint64();


extern std::size_t bignumToStringLength(std::uint64_t* a, std::size_t lena);
extern std::size_t bignumToStringHexLength(std::uint64_t* a, std::size_t lena);
extern std::size_t bignumToStringOctalLength(std::uint64_t* a, std::size_t lena);
extern std::size_t bignumToStringBinaryLength(std::uint64_t* a, std::size_t lena);

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

// Note that gcc 16 contains code to use native TLS on Windows (rather than
// the version in use up to then which I found added noticable overhead to my
// code), but as of mid 2026 it is not activated. It may be some while before
// this propagates to all the build envoronments I use.

struct MyArithlibData
{
    int someThreadLocalInteger;
    std::vector<int> someThreadLocalVector;
}; 

//#define TL_arithlibData 48
//DEFINE_INLINE_THREAD_LOCAL(MyArithlibData, arithlibData);

// On Windows there is a gcc bug at least in the Cygwin world whereby
// "inline thread_local" things that need initialization lead to complaints
// of multiple definition. However wrapping the thread_local up as a
// static within a function works OK and achieves close to the same
// effect. So that is what I do here. Well actually arithlibData is not
// (yet) used much if at all, so even if this is ugly, clumsy and a bit
// costly it is not a disaster!

#define arithlibData arithlibDataFn()

inline MyArithlibData* arithlibDataFn()
{   static thread_local MyArithlibData data;
    return &data;
}

// Now the fields within arithlibData can be accessed as in
// arithlibData->someThreadLocalInteger and this is expected to
// be reasonably cheap (even on Windows!).


// A scheme "arithlib_assert" lets me write in my own code to print the
// diagnostics. To use this version you must include arithlib.h after
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
{   const char** where;
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

inline void assert1(bool ok, const char* why, const char* location)
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

// C++20 insists that integers behave as if implemented using 2s complement,
// and that right shifts are arithmetic. So worries about 1s complement or
// sign-and-magnitude and about logical right shifts fade.


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

// I want a new io manipulator "std::bin" to select binary mode output.
// This will be used much as std::oct, std::dec and std::hex.

inline std::ostream& bin(std::ostream& os)
{   arithlib_implementation::radix::set_binary_output(os);
    return os;
}

// Declare a number of functions that might usefully be used elsewhere.

extern std::uint64_t* reserve(std::size_t n);
extern std::intptr_t confirmSize(std::uint64_t* p, std::size_t n,
                                 std::size_t final);
extern std::intptr_t confirmSize_x(std::uint64_t* p, std::size_t n,
                                   std::size_t final);
extern void abandon(std::uint64_t* p);
extern void abandon(std::intptr_t h);

#if defined LISP
typedef std::intptr_t string_handle;
#else // LISP
typedef char* string_handle;
#endif // LISP

extern string_handle confirmSizeString(char* p, std::size_t n,
                                       std::size_t final);
extern void abandonString(string_handle);

extern std::intptr_t vectorToHandle(std::uint64_t* p);
extern std::uint64_t* vectorOfHandle(std::intptr_t n);
extern std::size_t numberSize(std::uint64_t* p);
extern void setNumberSize(std::uint64_t* p, std::size_t n);

extern bool fitsIntoFixnum(SignedDigit n);
extern std::intptr_t intToHandle(SignedDigit n);
constexpr extern SignedDigit intOfHandle(std::intptr_t n);

extern std::intptr_t stringToBignum(const char* s);
extern std::intptr_t intToBignum(SignedDigit n);
extern std::intptr_t unsignedIntToBignum(Digit n);
extern std::intptr_t int128ToBignum(SignedDigit high, Digit low);
extern std::intptr_t unsignedInt128ToBignum(Digit high, Digit low);
extern std::intptr_t roundDoubleToInt(double d);
extern std::intptr_t truncDoubleToInt(double d);
extern std::intptr_t floorDoubleToInt(double d);
extern std::intptr_t ceilingDoubleToInt(double d);
extern std::intptr_t roundFloat128ToInt(FLOAT_128 d);
extern std::intptr_t truncFloat128ToInt(FLOAT_128 d);
extern std::intptr_t floorFloat128ToInt(FLOAT_128 d);
extern std::intptr_t ceilingFloat128ToInt(FLOAT_128 d);
extern std::intptr_t uniformPositive(std::size_t n);
extern std::intptr_t uniformSigned(std::size_t n);
extern std::intptr_t uniformUpto(std::intptr_t a);
extern std::intptr_t randomUptoBits(std::size_t bits);
extern std::intptr_t fudgeDistribution(std::intptr_t, int);

#include "memalloc.h"

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
    static bool op(SignedDigit, FLOAT_128);
    static bool op(std::uint64_t* , FLOAT_128);
    static bool op(FLOAT_128, SignedDigit);
    static bool op(FLOAT_128, std::uint64_t* );
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
    static bool op(SignedDigit, FLOAT_128);
    static bool op(std::uint64_t* , FLOAT_128);
    static bool op(FLOAT_128, SignedDigit);
    static bool op(FLOAT_128, std::uint64_t* );
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
    static bool op(SignedDigit, FLOAT_128);
    static bool op(std::uint64_t* , FLOAT_128);
    static bool op(FLOAT_128, SignedDigit);
    static bool op(FLOAT_128, std::uint64_t* );
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
    static bool op(SignedDigit, FLOAT_128);
    static bool op(std::uint64_t* , FLOAT_128);
    static bool op(FLOAT_128, SignedDigit);
    static bool op(FLOAT_128, std::uint64_t* );
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
    static bool op(SignedDigit, FLOAT_128);
    static bool op(std::uint64_t* , FLOAT_128);
    static bool op(FLOAT_128, SignedDigit);
    static bool op(FLOAT_128, std::uint64_t* );
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
    static bool op(SignedDigit, FLOAT_128);
    static bool op(std::uint64_t* , FLOAT_128);
    static bool op(FLOAT_128, SignedDigit);
    static bool op(FLOAT_128, std::uint64_t* );
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

class Float128
{
public:
    static FLOAT_128 op(SignedDigit w);
    static FLOAT_128 op(uint64_t* w);
};

class Frexp128
{
public:
    static FLOAT_128 op(SignedDigit, SignedDigit& x);
    static FLOAT_128 op(std::uint64_t* , SignedDigit& x);
};

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

extern string_handle bignumToString(std::intptr_t aa);
extern string_handle bignumToStringHex(std::intptr_t aa);
extern string_handle bignumToStringOctal(std::intptr_t aa);
extern string_handle bignumToStringBinary(std::intptr_t aa);

class Bignum;

inline int displayIndent = 0;
extern void display(const char* label,
                    const std::uint64_t* a,
                    std::size_t lena);
extern void display(const char* label, std::intptr_t a);
extern void display(const char* label, const Bignum& a);

extern void display(std::string label,
                    const std::uint64_t* a,
                    std::size_t lena);
extern void display(std::string label, std::intptr_t a);
extern void display(std::string label, const Bignum& a);

extern void display(const char* label,
                    SignedDigit top,
                    const std::uint64_t* a,
                    std::size_t lena);
extern void display(std::string label,
                    SignedDigit top,
                    const std::uint64_t* a,
                    std::size_t lena);
extern void display(std::string label);
extern void display(const char* label);
extern void display1(std::string label, std::size_t a);
extern void display1(const char* label, std::size_t a);
extern void display2(std::string label, std::size_t a, std::size_t b);
extern void display2(const char* label, std::size_t a, std::size_t b);


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
    Bignum(FLOAT_128 d)
    {   val = roundFloat128ToInt(d);
    }
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
    void operator = (const Bignum& x)
    {   if (this == &x) return; // assign to self - a silly case!
        abandon(val);    // See comment in the copy constructor.
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
    Bignum operator +(const T x) const
    {   return Bignum(true,
                      op_dispatch2<Plus,std::intptr_t>(val, Bignum(x).val));
    }

    Bignum operator -(const Bignum& x) const
    {   return Bignum(true,
                      op_dispatch2<Difference,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator -(const T x) const
    {   return Bignum(true, op_dispatch2<Difference,std::intptr_t>(val,
                      Bignum(x).val));
    }

    Bignum operator *(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Times,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator *(const T x) const
    {   return Bignum(true,
            op_dispatch2<Times,std::intptr_t>(val, Bignum(x).val));
    }

    Bignum operator /(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Quotient,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator /(const T x) const
    {   return Bignum(true,
            op_dispatch2<Quotient,std::intptr_t>(val, Bignum(x).val));
    }

    Bignum operator %(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Remainder,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator %(const T x) const
    {   return Bignum(true, op_dispatch2<Remainder,std::intptr_t>(val,
                      Bignum(x).val));
    }

    Bignum operator -() const
    {   return Bignum(true, op_dispatch1<Minus,std::intptr_t>(val));
    }

    Bignum operator &(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Logand,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator &(const T x) const
    {   return Bignum(true, op_dispatch2<Logand,std::intptr_t>(val,
                      Bignum(x).val));
    }

    Bignum operator |(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Logor,std::intptr_t>(val, x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator |(const T x) const
    {   return Bignum(true, op_dispatch2<Logor,std::intptr_t>(val,
                      Bignum(x).val));
    }

    Bignum operator ^(const Bignum& x) const
    {   return Bignum(true, op_dispatch2<Logxor,std::intptr_t>(val,
                      x.val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator ^(const T x) const
    {   return Bignum(true, op_dispatch2<Logxor,std::intptr_t>(val,
                      Bignum(x).val));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator <<(T n) const
    {   return Bignum(true, op_dispatch1<LeftShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    Bignum operator <<(Bignum n) const
    {   return Bignum(true, op_dispatch1<LeftShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    Bignum operator >>(T n) const
    {   return Bignum(true, op_dispatch1<RightShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    Bignum operator >>(Bignum n) const
    {   return Bignum(true, op_dispatch1<RightShift,std::intptr_t>(val,
                      static_cast<SignedDigit>(n)));
    }

    Bignum operator ~() const
    {   return Bignum(true, op_dispatch1<Lognot,std::intptr_t>(val));
    }

    bool operator ==(const Bignum& x) const
    {   return op_dispatch2<Eqn,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    bool operator ==(const T x) const
    {   return op_dispatch2<Eqn,bool>(val, Bignum(x).val);
    }

    bool operator !=(const Bignum& x) const
    {   return !op_dispatch2<Eqn,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    bool operator !=(const T x) const
    {   return !op_dispatch2<Eqn,bool>(val, Bignum(x).val);
    }

    bool operator >(const Bignum& x) const
    {   return op_dispatch2<Greaterp,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    bool operator >(const T x) const
    {   return op_dispatch2<Greaterp,bool>(val, Bignum(x).val);
    }

    bool operator >=(const Bignum& x) const
    {   return op_dispatch2<Geq,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    bool operator >=(const T x) const
    {   return op_dispatch2<Geq,bool>(val, Bignum(x).val);
    }

    bool operator <(const Bignum& x) const
    {   return op_dispatch2<Lessp,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    bool operator <(const T x) const
    {   return op_dispatch2<Lessp,bool>(val, Bignum(x).val);
    }

    bool operator <=(const Bignum& x) const
    {   return op_dispatch2<Leq,bool>(val, x.val);
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    bool operator <=(const T x) const
    {   return op_dispatch2<Leq,bool>(val, Bignum(x).val);
    }

    void operator +=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Plus,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator +=(T x)
    {   std::intptr_t r = op_dispatch2<Plus,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    void operator -=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Difference,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator -=(T x)
    {   std::intptr_t r =
            op_dispatch2<Difference,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    void operator *=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Times,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }
    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator *=(T x)
    {   std::intptr_t r =
            op_dispatch2<Times,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    void operator /=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Quotient,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator /=(T x)
    {   std::intptr_t r =
            op_dispatch2<Quotient,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    void operator %=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Remainder,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator %=(T x)
    {   std::intptr_t r = op_dispatch2<Remainder,std::intptr_t>(val,
                          Bignum(x).val);
        abandon(val);
        val = r;
    }

    void operator &=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Logand,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator &=(T x)
    {   std::intptr_t r =
            op_dispatch2<Logand,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    void operator |=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Logor,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator |=(T x)
    {   std::intptr_t r =
            op_dispatch2<Logor,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    void operator ^=(const Bignum& x)
    {   std::intptr_t r = op_dispatch2<Logxor,std::intptr_t>(val, x.val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator ^=(T x)
    {   std::intptr_t r =
            op_dispatch2<Logxor,std::intptr_t>(val, Bignum(x).val);
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator <<=(T n)
    {   std::intptr_t r =
            op_dispatch1<LeftShift,std::intptr_t>(val,
                static_cast<SignedDigit>(n));
        abandon(val);
        val = r;
    }

    template <typename T,
        typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    void operator >>=(T n)
    {   std::intptr_t r =
            op_dispatch1<RightShift,std::intptr_t>(val,
                static_cast<SignedDigit>(n));
        abandon(val);
        val = r;
    }

    Bignum operator ++()
    {   std::intptr_t r = bigplus_small(val, 1);
        abandon(val);
        val = r;
        return *this;
    }

    Bignum operator ++(int)
    {   std::intptr_t r = bigplus_small(val, 1);
// I assign explicitly to oldval.val because trying to use a constructor
// of Bignum or assigning to one would so things more complicated than I want!
        Bignum oldval;
        oldval.val = val;
        val = r;
        return oldval;
    }

    Bignum operator --()
    {   std::intptr_t r = bigplus_small(val, -1);
        abandon(val);
        val = r;
        return *this;
    }

    Bignum operator --(int)
    {   std::intptr_t r = bigplus_small(val, -1);
        Bignum oldval;
        oldval.val = val;
        val = r;
        return oldval;
    }

    Bignum lowbit() const
    {   return Bignum(true, op_dispatch1<LowBit,std::size_t>(val));
    }

    Bignum highbit() const
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
inline Bignum operator ""_Z(const char* s)
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

extern double doubleBignum(const Bignum& x);

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

inline FLOAT_128 frexp128Bignum(const Bignum& x, SignedDigit &xx)
{   return op_dispatch1<Frexp128,FLOAT_128>(x.val, xx);
}

inline FLOAT_128 longfloat6Bignum(const Bignum& x)
{   return op_dispatch1<Float128,FLOAT_128>(x.val);
}

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

// I want to annotate some trace or debug output with the identity of the
// thread involved. A C++ thread identifier is a type that does not have
// a neat printed representation, so here I arrange that when I want to
// display one I allocate a small integer.

inline unsigned int nextThreadId = 1;
inline std::unordered_map<std::thread::id, unsigned int> threadIdTable;

inline unsigned int getTidyThreadId()
{   unsigned int res;
    auto id = std::this_thread::get_id();
    if (threadIdTable.count(id) == 0)
        threadIdTable[id] = res = nextThreadId++;
    else res = threadIdTable[id];
    return res;
}

inline void display(const char* label,
                    SignedDigit top,
                    const std::uint64_t* a,
                    std::size_t lena)
{   const char** where;
    std::lock_guard<std::mutex> lock(
        arithlib_implementation::diagnostic_mutex(&where));
    std::printf("[%u]", getTidyThreadId());
    for (int i=0; i<std::min(displayIndent, 7); i++) std::printf(" ");
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
#ifdef DOTS
        if (a[i-1] == 0) len += std::printf("................"); else
#endif // DOTS
        len += std::printf("%.16" PRIx64, a[i-1]);
    }
    std::printf("$\n\n");
}

inline void display(const char* label, std::intptr_t a)
{   const char** where;
    std::lock_guard<std::mutex> lock(
        arithlib_implementation::diagnostic_mutex(&where));
    std::printf("[%u]", getTidyThreadId());
    if (storedAsFixnum(a))
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

inline void display(const char* label)
{   const char** where;
    std::lock_guard<std::mutex> lock(
        arithlib_implementation::diagnostic_mutex(&where));
    std::printf("[%u] %s\n", getTidyThreadId(), label);
}

inline void display1(const char* label, std::size_t a)
{   const char** where;
    std::lock_guard<std::mutex> lock(
        arithlib_implementation::diagnostic_mutex(&where));
    std::printf("[%u] %s %" PRIu64 "\n", getTidyThreadId(),
               label, (std::uint64_t)a);
}

inline void display2(const char* label, std::size_t a, std::size_t b)
{   const char** where;
    std::lock_guard<std::mutex> lock(
        arithlib_implementation::diagnostic_mutex(&where));
    std::printf("[%u] %s %" PRIu64 " %" PRIu64 "\n", getTidyThreadId(),
               label, (std::uint64_t)a, (std::uint64_t)b);
}


inline void display(std::string label)
{   display(label.c_str());
}

inline void display1(std::string label, std::size_t a)
{   display1(label.c_str(), a);
}

inline void display2(std::string label, std::size_t a, std::size_t b)
{   display2(label.c_str(), a, b);
}


//=========================================================================
//=========================================================================
// I will have a collection of low level functions that support the
// fundamental operations needed for implementing big-number arithmetic:
// add-with-carry, multiplication and division.
//=========================================================================
//=========================================================================

// Round a size_t integer up to the next higher power of 2.
// I do this based on counting the number of leading zeros in the
// binary representation of n-1.

inline std::size_t next_power_of_2(std::size_t n)
{   return (static_cast<std::size_t>(1)) <<
               (64-nlz(static_cast<uint64_t>(n-1)));
}

inline unsigned int logNextPowerOf2(std::size_t n)
{   return 64-nlz(static_cast<uint64_t>(n-1));
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

#if defined __GNUC__ || defined __clang__

inline Digit addWithCarry(Digit a1,
                          Digit a2,
                          Digit &r)
{   return static_cast<Digit>(__builtin_add_overflow(a1, a2, &r));
}

#else

inline Digit addWithCarry(Digit a1,
                          Digit a2,
                          Digit &r)
{   r = a1 + a2;
    return r < a1 ? 1 : 0;
}

#endif

// Now the general version with a carry-in. Note that I require that this
// can cope with a carry-in that may be bigger than 1 and that thus the
// carry out can be 0, 1 or 2. So reallt this is an "add 3 values"
// function.

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

#if defined __GNUC__ || defined __clang__

inline Digit subtractWithBorrow(Digit a1,
                                Digit a2,
                                Digit &r)
{   return static_cast<Digit>(__builtin_sub_overflow(a1, a2, &r));
}

#else

inline Digit subtractWithBorrow(Digit a1,
                                Digit a2,
                                Digit &r)
{   r = a1 - a2;
    return r > a1 ? 1 : 0;           // @@@@ is this correct? @@@@
}

#endif

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

// At least for debugging I may wish to display 128-bit integers. Here I
// only do hex printing. I could do decimal and octal if I really wanted
// but just for debugging that does not seem vital. If some C++ compiler
// already supported printing of 128-bit ints this definition might clash
// and would need commenting out.

inline std::ostream & operator << (std::ostream &out, uint128_t a)
{   out << std::hex << std::setw(16) << std::setfill('0') <<
        static_cast<Digit>(a>>64)
        << "_"
        << static_cast<Digit>(a) << std::dec << std::setfill(' ');
    return out;
}

inline uint128_t pack128(Digit hi, Digit lo)
{   return (static_cast<uint128_t>(hi)<<64) | lo;
}

inline void multiply64(Digit a, Digit b,
                       Digit &hi, Digit &lo)
{   uint128_t r = static_cast<uint128_t>(a)*static_cast<uint128_t>(b);
    hi = static_cast<Digit>(r >> 64);
    lo = static_cast<Digit>(r);
}

// Now much the same but forming a*b+c. Note that this can not overflow
// the 128-bit result. Both hi and lo are only updated at the end
// of this, and so they are allowed to be the same as other arguments.

inline void multiply64(Digit a, Digit b,
                       Digit c,
                       Digit &hi, Digit &lo)
{   uint128_t r =
        static_cast<uint128_t>(a)*static_cast<uint128_t>(b) + c;
    hi = static_cast<Digit>(r >> 64);
    lo = static_cast<Digit>(r);
}

inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             SignedDigit &hi, Digit &lo)
{   int128_t r = static_cast<int128_t>(a)*static_cast<int128_t>(b);
    hi = static_cast<SignedDigit>(static_cast<uint128_t>(r) >> 64);
    lo = static_cast<Digit>(r);
}

inline void signedMultiply64(SignedDigit a, SignedDigit b,
                             Digit c,
                             SignedDigit &hi, Digit &lo)
{   uint128_t r =
        static_cast<uint128_t>(
            static_cast<int128_t>(a)*static_cast<int128_t>(b)) + c;
    hi = static_cast<SignedDigit>(r >> 64);
    lo = static_cast<Digit>(r);
}

// divide {hi,lo} by divisor and generate a quotient and a remainder.

inline void divide64(Digit hi, Digit lo,
                     Digit divisor,
                     Digit &q, Digit &r)
{   uint128_t dividend = pack128(hi, lo);
    q = dividend / divisor;
    r = dividend % divisor;
}

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

inline void unsignedIntToBignum(Digit n, std::uint64_t* r, std::size_t &lenr)
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

inline std::intptr_t unsignedInt128ToBignum(Digit  high, Digit low)
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

// Some constants that are useful when I am dealing with FLOAT_128.
// Well maybe the file "float128.h" will contain everything I need,
// so these may be superfluous.

inline FLOAT_128
    f128_0      = FLOAT_128(UINT32_C(0x00000000), nullptr),
    f128_half   = FLOAT_128(UINT32_C(0x3ffe0000), nullptr),
    f128_mhalf  = FLOAT_128(UINT32_C(0xbffe0000), nullptr),
    f128_1      = FLOAT_128(UINT32_C(0x3fff0000), nullptr),
    f128_m1     = FLOAT_128(UINT32_C(0xbfff0000), nullptr),
    f128_N1     = FLOAT_128(UINT32_C(0x4fff0000), nullptr); // 2^4096

// When doubles (and FLOAT_128 values where available) are to be
// compared against a bignum to get proper results the double should
// (at least in effect) be converted to a bignum. If one does the comparison
// by converting both inputs to floating point (which may feel easier) there
// are multiple problems. First the bignum might have a value outside
// the range of floats, so you get overflow. Then it might differ from
// a float in a bit position several hundred betlow its most significant
// one, and converting to a float would lose that information.

// There are places where I need to shift a 128 or 192-bit number that is
// represented using several int64 values...

inline void shiftleft(SignedDigit &hi, Digit &lo, int n)
{   if (n == 0) return;
    else if (n < 64)
    {   hi = ((Digit)hi << n) | (lo >> (64-n));
        lo = lo << n;
    }
    else if (n == 64)
    {   hi = lo;
        lo = 0;
    }
    else
    {   hi = (Digit)lo << (n-64);
        lo = 0;
    }
}

inline void shiftleft(SignedDigit &hi, Digit &mid,
                      Digit &lo,
                      int n)
{   if (n == 0) return;
    else if (n < 64)
    {   hi = ((Digit)hi << n) | (mid >> (64-n));
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
    {   lo = (lo >> n) | ((Digit)hi << (64-n));
        hi = hi >> n;
    }
    else if (n == 64)
    {   lo = hi;
        hi = hi<0 ? -1 : 0;
    }
    else
    {   lo = hi >> (n-64);
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

extern void doubleTo_virtualBignum(double d,
                                   SignedDigit &top, Digit &next,
                                   std::size_t &len,
                                   RoundingMode mode);

// For a FLOAT_128 value I need to generate (up to) 3 64-bit digits for
// the way it would end up as a bignum.

extern void longfloatTo_virtualBignum(FLOAT_128 d,
                                     SignedDigit &top,
                                     Digit &mid,
                                     Digit &next,
                                     std::size_t &len,
                                     RoundingMode mode);

extern std::intptr_t doubleToInt(double d, RoundingMode mode);

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

extern std::intptr_t longfloatToInt(FLOAT_128 d, RoundingMode mode);

inline std::intptr_t roundFloat128ToInt(FLOAT_128 d)
{   return longfloatToInt(d, RoundingMode::ROUND);
}

inline std::intptr_t truncFloat128ToInt(FLOAT_128 d)
{   return longfloatToInt(d, RoundingMode::TRUNC);
}

inline std::intptr_t floorFloat128ToInt(FLOAT_128 d)
{   return longfloatToInt(d, RoundingMode::FLOOR);
}

inline std::intptr_t ceilingFloat128ToInt(FLOAT_128 d)
{   return longfloatToInt(d, RoundingMode::CEILING);
}

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

extern float castTo_float(double d);

// On Cygwin (at least) the std::ldexpf function that is part of C++11
// is hidden in the header file perhaps because of issues about thread
// safety in its implementation. I reason here that converting from a
// float to a double will never lose anything, then ldexp() can be used.
// The case back to a float can not introduxce rounding, but might notice
// overflow leading to a result that is an IEEE infinity.

inline float ldexpf(float a, int n)
{   return castTo_float(std::ldexp(static_cast<double>(a), n));
}

inline const Digit ten19 = UINT64_C(10000000000000000000);

extern std::intptr_t stringToBignum(const char* s);


extern std::size_t bignumToString(char* result, std::size_t m,
                                  std::uint64_t* a, std::size_t lena,
                                  bool asUnsigned=false);

extern string_handle bignumToString(std::uint64_t* a,
                                    std::size_t lena,
                                    bool asUnsigned=false);

extern string_handle bignumToString(std::intptr_t aa);

extern string_handle bignumToStringHex(std::intptr_t aa);

extern string_handle bignumToStringOctal(std::intptr_t aa);

extern string_handle bignumToStringBinary(std::intptr_t aa);

//@@@@

//=========================================================================
//=========================================================================
// Big number comparisons.
//=========================================================================
//=========================================================================


inline bool Zerop::op(std::uint64_t* a)
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

//@@@@

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

// The following constants are 2^112 and -2^112 and their reciprocals, which
// are used in rationalf128 because any 128-bit floating point value that
// is that large is necessarily an exact integer.

inline FLOAT_128 FP128_INT_LIMIT = FLOAT_128(UINT32_C(0x406f0000), nullptr);
inline FLOAT_128 FP128_MINUS_INT_LIMIT = FLOAT_128(UINT32_C(0xc06f0000), nullptr);

inline bool eqnbigfloat(std::uint64_t* a, std::size_t lena, FLOAT_128 b)
{   if (isnan(b)) return false;
    SignedDigit top = static_cast<SignedDigit>(a[lena-1]);
    if (top >= 0 && b < LF_C(0.0)) return false;
    if (top < 0 && b >= LF_C(0.0)) return false;
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
        if (FP128_INT_LIMIT < b ||
            b < FP128_MINUS_INT_LIMIT) return false;
// Convert a to a longfloat and compare. The conversion will not lose any
// information because the |a| <= 2^112 so it will fit within the mantissa
// bits that are available.
        FLOAT_128 aa = Float128::op(a);
        return aa == b;
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

inline bool Eqn::op(SignedDigit a, FLOAT_128 b)
{   return (FLOAT_128)a == b;
}

inline bool Eqn::op(std::uint64_t* a, FLOAT_128 b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Eqn::op(static_cast<SignedDigit>(a[0]), b);
    return eqnbigfloat(a, lena, b);
}

inline bool Eqn::op(FLOAT_128 a, SignedDigit b)
{   return Eqn::op(b, a);
}

inline bool Eqn::op(FLOAT_128 a, std::uint64_t* b)
{   return Eqn::op(b, a);
}

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

inline bool Neqn::op(SignedDigit a, FLOAT_128 b)
{   return (FLOAT_128)a != b;
}

inline bool Neqn::op(std::uint64_t* a, FLOAT_128 b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Neqn::op(static_cast<SignedDigit>(a[0]), b);
    return !eqnbigfloat(a, lena, b);
}

inline bool Neqn::op(FLOAT_128 a, SignedDigit b)
{   return Neqn::op(b, a);
}

inline bool Neqn::op(FLOAT_128 a, std::uint64_t* b)
{   return Neqn::op(b, a);
}

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

//@@ This is not sorted out yet!

// This one function does >, >=, < and <= with "great" indicating if
// the base is > or < and "ifequal" distinguishing > from >= and < from <=.

inline bool greaterpbigfloat(std::uint64_t* a, std::size_t lena,
                             FLOAT_128 b,
                             bool great, bool ifequal)
{   if (isnan(b)) return false;  // Comparisons involving a NaN => false.
    SignedDigit top = static_cast<SignedDigit>(a[lena-1]);
    if (top >= 0 && b < LF_C(0.0)) return great;
    if (top < 0 && b >= LF_C(0.0)) return !great;
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
        if (FP128_INT_LIMIT < b) return !great;
        if (b < FP128_MINUS_INT_LIMIT) return great;
// Convert a to a longfloat and compare. The conversion will not lose any
// information because the |a| <= 2^112 so it will fit within the mantissa
// bits that are available.
        FLOAT_128 aa = Float128::op(a);
        if (great)
        {   if (ifequal) return b <= aa;
            else return b < aa;
        }
        else
        {   if (ifequal) return aa <= b;
            else return aa < b;
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

inline bool Greaterp::op(SignedDigit a, FLOAT_128 b)
{   return (FLOAT_128)a > b;
}

inline bool Greaterp::op(std::uint64_t* a, FLOAT_128 b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Greaterp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, true, false);

}

inline bool Greaterp::op(FLOAT_128 a, SignedDigit b)
{   return Lessp::op(b, a);
}

inline bool Greaterp::op(FLOAT_128 a, std::uint64_t* b)
{   return Lessp::op(b, a);
}

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

inline bool Geq::op(SignedDigit a, FLOAT_128 b)
{   return (FLOAT_128)a >= b;
}

inline bool Geq::op(std::uint64_t* a, FLOAT_128 b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Greaterp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, true, true);
}

inline bool Geq::op(FLOAT_128 a, SignedDigit b)
{   return Leq::op(b, a);
}

inline bool Geq::op(FLOAT_128 a, std::uint64_t* b)
{   return Leq::op(b, a);
}

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

inline bool Lessp::op(SignedDigit a, FLOAT_128 b)
{   return (FLOAT_128)a < b;
}

inline bool Lessp::op(std::uint64_t* a, FLOAT_128 b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Lessp::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, false, false);
}

inline bool Lessp::op(FLOAT_128 a, SignedDigit b)
{   return Greaterp::op(b, a);
}

inline bool Lessp::op(FLOAT_128 a, std::uint64_t* b)
{   return Greaterp::op(b, a);
}

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

inline bool Leq::op(SignedDigit a, FLOAT_128 b)
{   return (FLOAT_128)a <= b;
}

inline bool Leq::op(std::uint64_t* a, FLOAT_128 b)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Leq::op(static_cast<SignedDigit>(a[0]), b);
    return greaterpbigfloat(a, lena, b, false, true);
}

inline bool Leq::op(FLOAT_128 a, SignedDigit b)
{   return Geq::op(b, a);
}

inline bool Leq::op(FLOAT_128 a, std::uint64_t* b)
{   return Geq::op(b, a);
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
        r[lena-words-1] = a[lena-1] >> bits;
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
        return 64-CSL_LISP::nlz(w & (-w))+r;
    }
    else if (lena==1 && a[0]==0) return 0;
    else
    {   std::size_t r=0, i=0;
        while (a[i++]==0) r += 64;
        Digit w = a[i-1];
        return 64-CSL_LISP::nlz(w & (-w))+r;
    }
}

inline std::size_t LowBit::op(SignedDigit aa)
{   Digit a;
    if (aa == 0) return 0;
    else if (aa < 0) a = ~static_cast<Digit>(aa);
    else a = aa;
    a = a & (-a); // keeps only the lowest bit
    return 64-CSL_LISP::nlz(a);
}

inline std::size_t bignumBits(const std::uint64_t* a, std::size_t lena)
{   if (lena == 0 && a[0] == 0) return 1; // say that 0 has 1 bit.
    Digit top = a[lena-1];  // top digit.
// The exact interpretation of "the length in bits of a negative number"
// is something I need to think through. Well Common Lisp counts the
// number of bits needed to store the value in 2s complement not counting
// the infinite string of leading 1s. So in this table the ":" shows
// where the leading 1s end and bits to be counted start. Well for me
// if I have a negative number I just have to apply this rule to the
// top digit (which will be negative) so if I complement it and then
// ignore leading zeros I should get what I need.
//      n      bignumBits(n)   (-n)        bignumBits(-n)
//      0           0        ..000000            0
//      1           1    1   ..111111        0 ..11111:
//      2           2   10   ..111110        1 ..1111:0
//      3           2   11   ..111101        2 ..111:01
//      4           3  100   ..111100        2 ..111:00
//      7           3  111   ..111001        3 ..11:001
//      8           4 1000   ..111000        3 ..11:000
    if (negative(top)) top = -top;
// Negative numbers never have a zero top word, but a positive value
// where the top bit of the next digit is "1" needs a zero digit
// on the front to prevent it from seeming negative.
    return 64*(lena-1) + (top==0 ? 0 : 64-nlz(top));
}

inline std::size_t IntegerLength::op(std::uint64_t* a)
{   return bignumBits(a, numberSize(a));
}

inline std::size_t IntegerLength::op(SignedDigit aa)
{   Digit a;
    if (aa == 0 || aa == -1) return 0;
    else if (aa < 0) a = -static_cast<Digit>(aa) - 1;
    else a = aa;
    return 64-CSL_LISP::nlz(a);
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
    int lz = CSL_LISP::nlz(a[n-1]);
    if (lz == 0) return a[n-1];
    return (a[n-1] << lz) | (a[n-2] >> (64-lz));
}

inline Digit Top64Bits::op(SignedDigit a)
{   if (a == 0) return 0;    // Only non-normalised case
    return static_cast<uint64_t>(a) << CSL_LISP::nlz((Digit)a);
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

extern void fftmul(ConstDigitPtr a, size_t lena,
                   ConstDigitPtr b, size_t lenb,
                   DigitPtr c);


//=========================================================================
//=========================================================================

} // end namespace arithlib_implementation

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
using arithlib_implementation::operator""_Z;
using arithlib_implementation::Bignum;

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

using arithlib_implementation::Float128;   // returns 128-bit float
using arithlib_implementation::Frexp128;
using arithlib_implementation::roundFloat128ToInt;
using arithlib_implementation::truncFloat128ToInt;
using arithlib_implementation::floorFloat128ToInt;
using arithlib_implementation::ceilingFloat128ToInt;
// These next few are just raw FLOAT_128 values and operations.
using arithlib_implementation::f128_0;
using arithlib_implementation::f128_half;
using arithlib_implementation::f128_mhalf;
using arithlib_implementation::f128_1;
using arithlib_implementation::f128_m1;

// The next few are functions I may like to use in low-level code...
//using arithlib_implementation::negative;
//using arithlib_implementation::numberSize;
//using arithlib_implementation::multiply64;

using arithlib_implementation::DigitPtr;
using arithlib_implementation::ConstDigitPtr;

using arithlib_implementation::castTo_float;
}

#endif // __arithlib_h

// end of arithlib.h
