// "log.h"                                              2020-22, A C Norman
//
// logging...
//

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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


#ifndef header_log_h
#define header_log_h 1

#include <iostream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <cwchar>
#include <cwctype>
#include <ctime>
#include <csignal>
#include <type_traits>
#include <typeinfo>
#include <string_view>
#include <cassert>
#include <stdexcept>
#include <atomic>


#ifdef CSL

extern std::FILE *spool_file;
extern void term_close();

#endif // CSL

// An "my_assert" scheme that lets me write in my own code to print the
// diagnostics. I also "exit()" rather than "abort()" since that is slightly
// cleaner!

[[noreturn]] inline void my_abort()
{   std::fprintf(stdout, "\n\n!!! Aborting\n\n");
    std::fflush(stdout);
    std::fflush(stderr);
#ifdef CSL
    if (spool_file != nullptr)
    {   std::fprintf(spool_file, "\n\n!!! Aborting\n\n");
        std::fflush(spool_file);
    }
    term_close();
#endif
#ifdef HAVE_QUICK_EXIT
    std::quick_exit(EXIT_FAILURE);
#else // HAVE_QUICK_EXIT
    std::exit(EXIT_FAILURE);
#endif // HAVE_QUICK_EXIT
}

[[noreturn]] inline void my_abort(const char *msg)
{   std::fprintf(stdout, "\n\n!!! Aborting: %s\n\n", msg);
    std::fflush(stdout);
    std::fflush(stderr);
#ifdef CSL
    if (spool_file != nullptr)
    {   std::fprintf(spool_file, "\n\n!!! Aborting\n\n");
        std::fflush(spool_file);
    }
    term_close();
#endif
#ifdef HAVE_QUICK_EXIT
    std::quick_exit(EXIT_FAILURE);
#else // HAVE_QUICK_EXIT
    std::exit(EXIT_FAILURE);
#endif // HAVE_QUICK_EXIT
}

inline void my_assert(bool ok, const char *msg)
{   if (!ok)
    {   std::cout << "\n+++ " << msg << std::endl;
        my_abort();
    }
}

inline void my_assert(bool ok, std::string msg)
{   if (!ok)
    {   std::cout << "\n+++ " << msg << std::endl;
        my_abort();
    }
}

template <typename F>
inline void my_assert(bool ok, F&& action)
{
// Use this as in
//     my_assert(predicate, [&]{...});
// where the "..." is an arbitrary sequence of actions to be taken
// if the assertion fails.
    if (!ok)
    {   action();
        my_abort();
    }
}

inline void my_assert(bool ok)
{   if (!ok) my_abort();
}

// This is to help me in trace messages.

inline const char *where(const char *file, int line)
{   const char *p = std::strrchr(file, '/');
    if (p != nullptr) file = p+1;
    static char whereMsg[100];
    sprintf(whereMsg, "%.40s:%d", file, line);
    return whereMsg;
}

#define __WHERE__ where(__FILE__, __LINE__)

#if defined __OPTIMIZE__ || !defined __GNUC__

// These provide very concise ways of putting tracking markers in the
// code. You can prefix a line with just "D;" and then each execution
// reports the name of the source file and a line number. DS("string");
// displays the string, DX(val) the integer value while DF("format", args)
// goes the whole printf route. These send the record to stderr, which may
// of course disrupt the output you were expecting to see ob your screen.

#define D  do {} while (false)
#define DS do {} while (false)
#define DX do {} while (false)
#define DF do {} while (false)

#else // !__OPTIMIZE__

#define D do {                                                      \
          const char *_f_ = std::strrchr(__FILE__, '/');            \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');   \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;           \
          std::fprintf(stderr, "Line %d File %s\n", __LINE__, _f_); \
          std::fflush(stderr);                                      \
          } while (false)

#define DS(s) do {                                                  \
          const char *_f_ = std::strrchr(__FILE__, '/');            \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');   \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;           \
          std::fprintf(stderr, "Line %d File %s: %s\n",             \
                               __LINE__, _f_, (s));                 \
          std::fflush(stderr);                                      \
          } while (false)

#define DX(s) do {                                                       \
          const char *_f_ = std::strrchr(__FILE__, '/');                 \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');        \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;                \
          std::fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, _f_, \
                          (long long unsigned)(s));                      \
          std::fflush(stderr);                                           \
          } while (false)

#define DF(f,...) do {                                               \
          const char *_f_ = std::strrchr(__FILE__, '/');             \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');    \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;            \
          std::fprintf(stderr, "Line %d File %s: ", __LINE__, _f_);  \
          std::fprintf(stderr, f, __VA_ARGS__);                      \
          std::fprintf(stderr, "\n");                                \
          std::fflush(stderr);                                       \
          } while (false)

#endif // !__OPTIMIZE__

static const size_t LONGEST_LEGAL_FILENAME_1 = 1024;

// This is maybe a more principled scheme that sends its output to a file
// debug.log, typically in the current directory but failing that in /tmp.

#if defined __OPTIMIZE__ || !defined __GNUC__

inline void printlog(const char *s, ...)
{}

#else // __OPTIMIZE__

#define LOGFILE_NAME "debug.log"

extern const char *programDir;

inline void printlog(const char *s, ...)
{   static std::FILE *logfile = nullptr;
    std::va_list x;
    if (logfile == nullptr)
    {   char logfile_name[LONGEST_LEGAL_FILENAME_1];
        std::memset(logfile_name, 0, sizeof(logfile_name));
        if (std::strcmp(programDir, ".") == 0)
            std::sprintf(logfile_name, "/tmp/%s", LOGFILE_NAME);
        else std::sprintf(logfile_name, "%s/%s", programDir, LOGFILE_NAME);
        logfile = std::fopen(logfile_name, "a");
        if (logfile == nullptr) logfile = std::fopen("/tmp/fwin.log", "w");
        if (logfile == nullptr) return; // the file can not be used
        std::time_t now = std::time(nullptr);
        std::fprintf(logfile, "New log segment started %s",
                     std::asctime(std::localtime(&now)));
    }
    va_start(x, s);
    std::vfprintf(logfile, s, x);
    va_end(x);
    std::fflush(logfile);
}

#endif // !__OPTIMIZE__

// The following sets up "LOCATION" as a string giving file-name and
// line-number

#define CSL_STRINGIFY(x) #x
#define CSL_TOSTRING(x) CSL_STRINGIFY(x)
#define LOCATION __FILE__ ":" CSL_TOSTRING(__LINE__)

//=========================================================================

//                       "zprintf"
//
// This is a facility that is used very much like std::printf. It is
// just intended here for generation of debugging output, and so the
// implementation does not support every possible option, however
// it is expected that as extra capabilities are called for it can be
// extended.

// Usage is as in 
//   zprintf("Number %d, hex-number %x, object %s, percent %%\n", i1, i2, o);
// and that will be executed as if it has been
//   cout << "Number " << std::dec << i1 << ", hex-number "
//        << std::hex << i2 << ", object " << o << ", percent %\n";
// Observe that the use of "<<" is rather more verbose, and the compact
// nature of printf is a key motivation here. However printf is not very
// type-safe, while zprintf will ensure that if you use "%d" that the
// corresponding argument has integral type. It does not need special
// handling to cope with long or short integers or integral types such
// as size_t and ptrdiff_t - they are all handled as just "integers".
// While %d and %x insist on integers and %e, %f and %g demand floating
// point arguments, %s will accept almost anything, and by overloading
// the "<<" operator it will be possible to introduce custom formatting
// for user-defined objects. That is a second special way in which this
// may be more convenient to use then std::printf. Here for CSL I introduce
// a format "%a" that prints addresses in a segment/page/offset format.
//
// The implementation uses a combination of template expansion and
// constexpr functions so that much of the decoding of the format string is
// performed at compile time. In effect a use of zprintf() expands into
// use of the normal C++ iostream facilities... but in many use-cases it
// will be more compact. While many iostream capabilities can be accessed
// using format directives, an escape idiom illustrated here can be used:
//    zprintf("A hack! %s%s%d\n", std::hex, std::uppercase, 0xbad);
// where manipulators are passed via %s. The example prints out the message
// "A hack! BAD", and of course in this case use of "%X" would have
// inserted the manipulators more cleanly.
// The format directive supported are
//    %d      %NNd                             NN denotes a width
// [I should cnsider supporting a width specified as "*" rather than digts]
//    %x %X   %NNx %NNX   %#x %#X %#NNx %#NNX  # for "0x" prefix, X upper case
// [I should consider the full set of flags: "#+=0 " rather than just "#"]
//    %e %E   %NNe %NNE   %.NNe %.NNE %NN.NNe %NN.NNE
//    %f and %g                                similarly to %e
//    %s                                       ANY C++ argument
//    %%                                       displays a single %
//    %a  (in a CSL context only, and then only if CONSERVATIVE
//         is defined)                         funny way to display an address.
//
// This code allows printing of arguments that are of type std::atomic<T>
// and displays things as the value stored atomically. For me that feels
// like a really helpful behaviour.
//
// Format string arguments must be provided as literal strings and zprintf
// only prints to the standard output stream (but in the CSL case with
// a copy sent to a spool file if one is active). At present I am not
// certain I know how to relax wither of those limitations.


// This will provide an ostream that goes to the standard output but in
// the CSL case also to a log file if one has been requested.

template <typename Ch>
class SpoolStream : public std::ostream {
private:
    class SpoolBuffer : public std::stringbuf
    {
    public:
        SpoolBuffer() { }
        ~SpoolBuffer() {  pubsync(); }
        virtual int sync()
        {   std::cout << str();
#ifdef CSL
            if (spool_file != nullptr)
            {   std::fprintf(spool_file, "%s", str().c_str());
            }
#endif // CSL
            str("");
            return 0;
        }
    };
public:
    SpoolStream() : std::ostream(new SpoolBuffer()) {}
    ~SpoolStream() { delete rdbuf(); }
};

#if defined CSL && defined CONSERVATIVE
inline const char* Addr(uintptr_t p);
template <typename T>
inline const char* Addr(const std::atomic<T>& p);
template <typename T>
inline const char* Addr(T p);
#endif // CSL

// Avoid reliance on inline variables until I am confident that all the
// compilers I ever use support them.

inline SpoolStream<char>& zstream()
{   static SpoolStream<char> z;
    return z;
}


// If you have C++20 with "consteval" then the format strings will be
// validated at compile time. With earlier versions they are still checked
// but not until run-time.

#ifdef __cpp_consteval
#define CONSTFN consteval
// #pragma message ("consteval available")
#else // __cpp_consteval
#define CONSTFN constexpr
// #pragma message ("consteval not available: fall back to constexpr")
#endif // __cpp_consteval

// std::type_identity was introduced in C++20 but this is how it could be
// implemented... and so these two small definitions let me exploit its
// behavious even in earlier versions of C++

template<class T>
struct my_type_identity
{   using type = T;
};

template<class T>
using my_type_identity_t = typename my_type_identity<T>::type;

// I am going to scan the provided arguments and capture information about
// their types. I will pack the information into a 64-bit integer with a
// 3-bit field for each argument. That will mean I can record information
// about 21 values. I am happy for that to be a limit on the number of
// items that a single use of zprintf() can handle.
// In an initial version of this code I will characterise actual
// arguments as integers, floats and "other things". But I have provision
// within the 3-bit encoding for several more special cases. The "integer"
// case will cover bool, char, short, int, long and long long as well as
// unsigned versions of those. I also want it to cover std::atomic<T> where
// T is an integral type. Similarly floats will cover float, double and
// long double along with atomic versions of same.
// The idea is that formats such as %d and %x only accept integers, %e, %f
// and %g only floats while %s will accept anything. The "spare" codes here
// could be used in support of formatting directives keyed to other particular
// types.
// Argument codes are packed such that the first argument is in the low 3
// bits of the 64-bit encoding. argTypeEnd is zero and denotes a position
// beyond where there are actually any arguments. Note that if there are
// exactly 21 arguments the information from them fills 63 bits of the
// packed encoding, but when unpacking the top zero bit gets extended leading
// to it appearing that position 22 is argTypeEnd.

enum argTypes:uint64_t
{   argTypeEnd     = 0x0,     // Terminator for list of arguments
    argTypeInt     = 0x1,     // Argument is integral: any width, including bool
    argTypeFloat   = 0x2,     // Argument is floating point: any width
    argTypeSpare1  = 0x3,     // Not used yet
    argTypeSpare2  = 0x4,     // Not used yet
    argTypeSpare3  = 0x5,     // Not used yet
    argTypeSpare4  = 0x6,     // Not used yet
    argTypeGeneral = 0x7      // Not one of the above special cases
};

enum subTypes:uint64_t
{   subtypeNone      = 0,
    subtypeUpperCase = 1,    // converts %x to %X etc 
    subtypeDecimal   = 2,    // %d
    subtypeHex       = 4,    // %x
    subtypeHexUp     = 5,    // %X
    subtypeEformat   = 2,    // %e
    subtypeEformatUp = 3,    // %E
    subtypeFformat   = 4,    // %f
    subtypeFformatUp = 5,    // %F
    subtypeGformat   = 6,    // %g
    subtypeGformatUp = 7,    // %G
    subtypeGeneral   = 2,    // %s
    subtypeAddr      = 4,    // %a
    subtypePercent   = 6     // %%
};



// I am goint to count both "int" and "std::atomic<int>" as integral types
// and similarly for short, long and unsigned versions etc. And similarly
// floating point values may be wrapped in std::atomic.

template<typename>
struct is_atomic : std::false_type {};

template<typename T>
struct is_atomic<std::atomic<T>> : std::true_type {};

template<typename T>
struct is_atomic<const std::atomic<T>> : std::true_type {};

// This now checks if the type T is either integral or an intgral
// type wrapped by std::atomic.

template <typename T>
constexpr bool maybe_atomic_int()
{   if constexpr (std::is_integral_v<T>) return true;
    else if constexpr (is_atomic<T>::value)
        return std::is_integral_v<typename T::value_type>;
    else return false;
}

template <typename T>
constexpr bool maybe_atomic_float()
{   if constexpr (std::is_floating_point_v<T>) return true;
    else if constexpr (is_atomic<T>::value)
        return std::is_floating_point_v<typename T::value_type>;
    else return false;
}

// Now template-driven code to take a sequence of types and return
// an integer coding the sequence. Note that the input must have a
// dummy type tagged on the end - that made terminating the recursion here
// just a little cleaner. At present this detects integral and floating
// point values, but it could clearly be extended to cover a few more
// special cases if I needed that. I tends to use void* as the padder at the
// end, but since it is never used it does not matter what it is.

template <typename T>
constexpr std::uint64_t types2int()
{   return argTypeEnd;
}

template <typename T, typename T2, typename... Ts>
constexpr std::uint64_t types2int()
{   if constexpr (maybe_atomic_int<T>())
        return (types2int<T2,Ts...>()<<3) | argTypeInt;
    else if constexpr (maybe_atomic_float<T>())
        return (types2int<T2,Ts...>()<<3) | argTypeFloat;
// Insert test for other specially important types here if you like!
    else return (types2int<T2,Ts...>()<<3) | argTypeGeneral;
}

// std::isdigit is not a constexpr function and I ought not to pretend to
// know that the codes for digits are consecutive! So I write out my own
// versions in a very cautious style.

inline constexpr int digitVal(int c)
{   return (c == '0' ? 0 :
            c == '1' ? 1 :
            c == '2' ? 2 :
            c == '3' ? 3 :
            c == '4' ? 4 :
            c == '5' ? 5 :
            c == '6' ? 6 :
            c == '7' ? 7 :
            c == '8' ? 8 :
            c == '9' ? 9 : -1);
}

inline constexpr bool isDigit(int c)
{   return (digitVal(c) != -1);
}

// I parse format strings using a finite state machine whose states
// are listed here.

enum parseState
{   parseSimple,     // ...
    parsePercent,    // ...%  [#+-0 ]*
    parseStar,       // ...%[#+-0 ]*
    parseWidth,      // ...%[#+-0 ]{Digit}+
    parseDot,        // parseStar or parseWidth followed by '.'
    parsePrecStar,   // parseDot followed by '*'
    parsePrec,       // parseDot followed by {Digit}

    parseInt,        // all above then one of d, x, X
    parseFlt,        // e, E, f, F, g, G
    parseGeneral,    // s
    parseAddr,       // a
    parsePercent2    // '%' again
};

// I want to ensure that each "flag" in a format directive is used at
// most once. To achive that I use a bitmap showing which have been seen
// thus far. This function maps the flag characters onto bits within
// the map.

enum flagBit:uint64_t
{
    flaghash  = 0x01,
    flagplus  = 0x02,
    flagminus = 0x04,
    flagzero  = 0x08,
    flagblank = 0x10,
    flagnone  = 0x00
};

constexpr unsigned int flagbit(int c)
{   switch (c)
    {    
    case '#':
        return flaghash;
    case '+':
        return flagplus;
    case '-':
        return flagminus;
    case '0':
        return flagzero;
    case ' ':
        return flagblank;
    default:
        return flagnone;
    }
}

// To achieve compile-time validation of the consistency between format
// strings and actual arguments I put the code that performs checking
// within the constructor for an object representing the format. This is
// used with a temmplate that captures the types of all the values that
// are to be printed. With C++20 "consteval" the checking happens at
// compile time. With older C++ variants it only happens at run-time, and
// in that case it is perhaps a duplicate of the work that has to be done
// when actually printing. So in the pre-C++20 world I will comment almost
// all of the work out!

template <typename... Args>
class formatString
{
    const std::string_view str;
public:
    template <typename S>
    CONSTFN formatString(const S a): str(a)
    {
        // Check format validity here, using the template information in
        // Args... to reveal the types of arguments that are being passed.
        std::uint64_t sig = types2int<Args..., void*>();
        parseState state = parseSimple;
        unsigned int flags = 0;
        for (size_t i=0; i<size(); i++)
        {
            switch (state)
            {
            default:
            case parseSimple:
// Within a format string in general the only special case is when
// a '%' is seen.
                if (data()[i] == '%')
                {   flags = 0;
                    state = parsePercent;
                }
                continue;
            case parsePercent:    // ...%
// Following a '%' I can have a sequence of flag characters, or I can move
// on to specify a width, a precision or all the way to the character that
// gives instructions about the argument type expected.
                switch (data()[i])
                {
                case '#': case '+': case '-':   // Flags
                case '0': case ' ':
// I am going to prohibit repetition of format flag markers. I view the
// C++ standard as a little ambiguous regarding this, although it does
// indicate that '0' with a non-integer format leads to undefined
// behaviour. But repetition as in say "%0#+0#00-x" is at the very least
// a style I view as obnoxious!
                    if ((flags & flagbit(data()[i])) != 0)
                        throw std::invalid_argument(
                            "repeated flag character following '%'");
                    flags |= flagbit(data()[i]);
                    continue;
                case '*':
                    if ((sig & 7) != argTypeInt)
                        throw std::invalid_argument(
                            "integer value needed for '*' width");
                    sig >>= 3;
                    state = parseStar;
                    continue;
                case '1': case '2': case '3': case '4': case '5':
                case '6': case '7': case '8': case '9':
                    state = parseWidth;
                    continue;
                case '.':
                    state = parseDot;
                    continue;
                case 'd': case 'x': case 'X':
                    state = parseInt;
                    break;
                case 'e': case 'E': case 'f': case 'F': case 'g': case 'G':
                    state = parseFlt;
                    break;
                case 's':
                    state = parseGeneral;
                    break;
                case 'a':
                    state = parseAddr;
                    break;
                case '%':
                    state = parsePercent2;
                    break;
                default: 
                    throw std::invalid_argument(
                        "invalid character following '%'");
                }
                break;

            case parseStar:       // ...%[#+-0 ]*
// After "%*" it is legal to have '.' or to move all the way to the
// argument-type letter.
                switch (data()[i])
                {
                case '.':
                    state = parseDot;
                    continue;
                case 'd': case 'x': case 'X':
                    state = parseInt;
                    break;
                case 'e': case 'E': case 'f': case 'F': case 'g': case 'G':
                    state = parseFlt;
                    break;
                case 's':
                    state = parseGeneral;
                    break;
                case 'a':
                    state = parseAddr;
                    break;
                case '%':
                    state = parsePercent2;
                    break;
                default: 
                    throw std::invalid_argument(
                        "invalid character following '%*'");
                }
                break;

            case parseWidth:      // ...%[#+-0 ]{Digit}+
// I will allow an arbitrary number of digits to make up a width
// field. Well if I am keen I will change that later and make things
// more restrictive! But an explicit numeric width is termainted by a '.'
// or by an argument-type letter.
                switch (data()[i])
                {
                case '.':
                    state = parseDot;
                    continue;
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    continue;
                case 'd': case 'x': case 'X':
                    state = parseInt;
                    break;
                case 'e': case 'E': case 'f': case 'F': case 'g': case 'G':
                    state = parseFlt;
                    break;
                case 's':
                    state = parseGeneral;
                    break;
                case 'a':
                    state = parseAddr;
                    break;
                case '%':
                    state = parsePercent2;
                    break;
                default: 
                    throw std::invalid_argument(
                        "invalid character following '%'");
                }
                break;

            case parseDot:        // parseStar or parseWidth followed by '.'
                switch (data()[i])
                {
                case '*':
                    if ((sig & 7) != argTypeInt)
                        throw std::invalid_argument(
                            "integer value needed for '*' precision");
                    sig >>= 3;
                    state = parsePrecStar;
                    continue;
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    state = parsePrec;
                    continue;
                    break;
                default: 
                    throw std::invalid_argument(
                        "invalid character following '%.'");
                }

            case parsePrecStar:   // parseDot followed by '*'
// After "%N.*" I can only have an argument-type letter. 
                switch (data()[i])
                {
                case 'd': case 'x': case 'X':
                    state = parseInt;
                    break;
                case 'e': case 'E': case 'f': case 'F': case 'g': case 'G':
                    state = parseFlt;
                    break;
                case 's':
                    state = parseGeneral;
                    break;
                case 'a':
                    state = parseAddr;
                    break;
                case '%':
                    state = parsePercent2;
                    break;
                default: 
                    throw std::invalid_argument(
                        "invalid character following '%.*'");
                }
                break;

            case parsePrec:       // parseDot followed by {Digit}
// Absorb numeric precision.
                switch (data()[i])
                {
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    continue;
                case 'd': case 'x': case 'X':
                    state = parseInt;
                    break;
                case 'e': case 'E': case 'f': case 'F': case 'g': case 'G':
                    state = parseFlt;
                    break;
                case 's':
                    state = parseGeneral;
                    break;
                case 'a':
                    state = parseAddr;
                    break;
                case '%':
                    state = parsePercent2;
                    break;
                default: 
                    throw std::invalid_argument(
                        "invalid character following '%'");
                }
                break;
            }
            switch (state)
            {
            case parseInt:        // all above then one of d, x, X
                if ((sig & 7) != argTypeInt)
                    throw std::invalid_argument(
                        "integral argument type expected");
                sig >>= 3;
                break;
            case parseFlt:        // e, E, f, F, g, G
                if ((sig & 7) != argTypeFloat)
                    throw std::invalid_argument(
                        "floating point argument type expected");
                sig >>= 3;
                break;
            default:
            case parseGeneral:    // s
            case parseAddr:       // a
// I could potentially apply more test if '%a' was used.
                sig >>= 3;
                break;
            case parsePercent2:   // '%' again
                break;
            }
            state = parseSimple;
        }
        if (state != parseSimple)
            throw std::invalid_argument(
                "format string ended within a '%' sequence");
        if (sig != 0)
            throw std::invalid_argument(
                "more arguments that format directives");
    }

    constexpr const char* data() const
    {   return str.data();
    }
    constexpr std::size_t size() const
    {   return str.size();
    }

// Now I have a function that scans a format string and returns a packed
// integer code that identifies the next directive (ie sequence starting
// with '%'). It takes and argument indicating where to start its
// scan and returns a value containing:
//16  The position of the '%' found (or of the end of the format
//        string is there is no such.
//3   Information on the directive found:
//        none/int/float/general + expansion space for others
//4       extra bits there so that int->%d/%x/%X, flt->%efgEFG, gen->%s/%a
//5   flag bits for "#+-0 ".
//8   width, with special values for "not given" and "*".
//8   precision, with special values for "not given" and "*".
//16  position of character after the directive.
// In total that is 50 bits of an uint64_t value. It limits
// format strings to be no longer than 18K characters and I will limit
// explicitly given width and precision values to the range 0-99 (ie only
// 1 or 2 digits). I encode the width and precision fields with 0 standing
// for no specification, 1-100 for widths 0-99 and 255 to indicate '*'
// I might be tempted to use a struct with bitfield entries, but I need
// this to be visibly a basic integer to ensure that constexpr etc works
// nicely.
//
    enum scanWidths:size_t
    {   widthStart     = 16,
        widthType      = 3,
        widthSubType   = 4,
        widthFlags     = 5,
        widthWidth     = 8,
        widthPrecision = 8,
        widthEnd       = 16
    };
    enum scanShifts:size_t
    {   shiftStart     = 0,
        shiftType      = shiftStart+widthStart,
        shiftSubType   = shiftType+widthType,
        shiftFlags     = shiftSubType+widthSubType,
        shiftWidth     = shiftFlags+widthFlags,
        shiftPrecision = shiftWidth+widthWidth,
        shiftEnd       = shiftPrecision+widthPrecision
    };
    enum scanMasks:uint64_t
    {   maskStart     = (1u<<widthStart)-1,    
        maskType      = (1u<<widthType)-1,     
        maskSubType   = (1u<<widthSubType)-1,  
        maskFlags     = (1u<<widthFlags)-1,    
        maskWidth     = (1u<<widthWidth)-1,    
        maskPrecision = (1u<<widthPrecision)-1,
        maskEnd       = (1u<<widthEnd)-1
    };

    constexpr uint64_t nextDirective(size_t pos = 0)
    {   while (pos < size())
        {   if (data()[pos] == '%') break;
            pos++;
        }
        if (pos >= size())
            return (pos & maskStart) | ((pos&maskEnd)<<shiftEnd);
        else
        {   uint64_t start = pos, width = 0, precision = 0, end = 0;
            argTypes type = argTypeEnd;
            subTypes subtype = subtypeNone;
            flagBit flags = flagnone;
            if (++pos >= size())
                throw std::invalid_argument(
                        "Format string ends within a sequence started by '%'");
// Following a '%' I can have some of "#+-0 ", and I will insist that any
// that are present are only there a single time. These are "flags" where
// for instance '#' leads to hex numbers being displayed with a prefix "0x".
// '+' causes positive numbers to have an explicit sign. '-' leads to
// left justification in a field, '0' can get integers shown with leading
// zeros while ' ' puts a blank in front of positive numbers such that
// positive and negative values end up the same total width.
//
// There is potentially some ambiguity regarding "%001" but I will treat
// the first '0' as a flag, and the second as an invalid repeat of that flag.
// So actual widths must start with a non-zero digit, and only be 1 or 2
// digits long.
            for (;;)
            {   const int f  = flagbit(data()[pos]);
                if (f == 0) break;
                else if ((f & flags) != 0)
                    throw std::invalid_argument(
                        "Repeated flag character following '%' in format string");
                else
                {   flags = static_cast<flagBit>(flags | f);
                    if (++pos >= size())
                        throw std::invalid_argument(
                            "Format string ends within a sequence started by '%'");
                }
            }
// After any potential flags there may be a width field. That can either
// be a single '*' or one or two digits. Here I do not allow for widths
// greater than 99.
            if (data()[pos] == '*')
            {   width = 255;
                if (++pos >= size())
                    throw std::invalid_argument(
                        "Format string ends within a sequence started by '%'");
            }
            else if (digitVal(data()[pos]) >= 0)
            {   int d1 = digitVal(data()[pos]);
                if (++pos >= size())
                    throw std::invalid_argument(
                        "Format string ends within a sequence started by '%'");
                else if (digitVal(data()[pos]) >= 0)
                {   int d2 = digitVal(data()[pos]);
                    if (++pos >= size())
                        throw std::invalid_argument(
                            "Format string ends within a sequence started by '%'");
                    width = 10*d1 + d2 + 1;
                }
                else width = d1 + 1;
            }
// A precision is introduced by a '.'
            if (data()[pos] == '.')
            {   if (++pos >= size())
                    throw std::invalid_argument(
                        "Format string ends within a sequence started by '%'");
                if (data()[pos] == '*')
                {   precision = 255;
                    if (++pos >= size())
                        throw std::invalid_argument(
                            "Format string ends within a sequence started by '%'");
                }
                else if (digitVal(data()[pos]) >= 0)
                {   int d1 = digitVal(data()[pos]);
                    if (++pos >= size())
                        throw std::invalid_argument(
                            "Format string ends within a sequence started by '%'");
                    if (digitVal(data()[pos]) >= 0)
                    {   int d2 = digitVal(data()[pos]);
                        if (++pos >= size())
                            throw std::invalid_argument(
                                "Format string ends within a sequence started by '%'");
                        precision = 10*d1 + d2 + 1;
                    }
                    else precision = d1 + 1;
                }
            }
// Now all that is required is the letter indicating the style of
// conversion required. The options are "dxX", "eEfFgG" and "sa" for
// integer, floating and general conversions, and "%" for just output
// or a '%'.
// I will reserve the code subtype==0 to mark a case where there is
// no actual directive but this function terminates having found the
// end of the format string.
            switch (data()[pos])
            {
            case 'd':
                type = argTypeInt;
                subtype = subtypeDecimal;
                break;
            case 'x':
                type = argTypeInt;
                subtype = subtypeHex;
                break;
            case 'X':
                type = argTypeInt;
                subtype = subtypeHexUp;
                break;
            case 'e':
                type = argTypeFloat;
                subtype = subtypeEformat;
                break;
            case 'E':
                type = argTypeFloat;
                subtype = subtypeEformatUp;
                break;
            case 'f':
                type = argTypeFloat;
                subtype = subtypeFformat;
                break;
            case 'F':
                type = argTypeFloat;
                subtype = subtypeFformatUp;
                break;
            case 'g':
                type = argTypeFloat;
                subtype = subtypeGformat;
                break;
            case 'G':
                type = argTypeFloat;
                subtype = subtypeGformatUp;
                break;
            case 's':
                type = argTypeGeneral;
                subtype = subtypeGeneral;
                break;
            case 'a':
                type = argTypeGeneral;
                subtype = subtypeAddr;
                break;
            case '%':
                type = argTypeGeneral;
                subtype = subtypePercent; // Will not consume an argument
                break;
            default:
                throw std::invalid_argument(
                    "Invalid sequence started by '%'");
            }
            end = pos+1;
// All the casts are because all my values (and masks) here are set up
// using enumeration types and combining them directly causes g++ (in C++20
// mode) to give a "deprecated" warning. I use the C style casts because
// they are more compact than using "static_cast<uint64_t>" everywhere.
            return
              ((int64_t)start     & (uint64_t)maskStart)    <<shiftStart |
              ((int64_t)type      & (uint64_t)maskType)     <<shiftType |
              ((int64_t)subtype   & (uint64_t)maskSubType)  <<shiftSubType |
              ((int64_t)flags     & (uint64_t)maskFlags)    <<shiftFlags |
              ((int64_t)width     & (uint64_t)maskWidth)    <<shiftWidth |
              ((int64_t)precision & (uint64_t)maskPrecision)<<shiftPrecision |
              ((int64_t)end       & (uint64_t)maskEnd)      <<shiftEnd;
        }
    }

// This first overload applies when there are no more values to be printed.
// This version should only apply when the Unused pack is empty!
// The format string should then not have any '%' characters in it
// apart from ones in sequences of the form "%%", "%NN%", %-NN%.
// Well my formal validation code allows other flag characters and a
// precision specification to be present, so I will allow but then
// ignore those!
//
// The argument in simple cases is just the index in the format string to
// work from. In that case all bits above the low 16 will be zero. The
// messier cases would be if the input had been something like
//    zprintf("%*%, 5);
// so the higher level has noted the "*" and the "5". It passes n as
// a fully unpacked explanation of the directive as if it had originally
// been zprintf("%5%"); This puts information in all the width, precision,
// type, flags, subtype and end fields within n, so in that case I
// use that information rather than calling nextDirective. This would
// also apply for the case "%.*%". If the original call had been
//   zprintf("%*.*%, 5);
// than that is passed as it it had been zprintf("%5.*%"); and if that
// gets here it will naturally lead to failure.
    template <typename... Unused>
    constexpr void zprintf(uint64_t n)
    {   while (n < size())
        {   std::uint64_t dir =
                (n & ~maskStart) != 0 ? n : nextDirective(n);
            std::string_view sv(&data()[n], (dir & maskStart) - n);
            std::cout << sv; // text before the '%' (or end of format string)
            if (((dir>>shiftSubType)&maskSubType) == 0) break;
            int width = (dir>>shiftWidth)&maskWidth;
            if (width == 255)
                throw std::invalid_argument(
                    "No argument to provide width information for '*'");
// Even though precision is not relevant for "%%" formats if the user
// attempts to use "%.*%" without providing an argument that will be
// rejected.
            int precision = (dir>>shiftPrecision)&maskPrecision;
            if (precision == 255)
                throw std::invalid_argument(
                    "No argument to provide precision information for '*'");
            if (((dir>>shiftType)&maskType) != argTypeGeneral ||
                 ((dir>>shiftSubType)&maskSubType) != subtypePercent)
                throw std::invalid_argument(
                    "No argument to go with format directive that needs one");
// It is legal do include things like "%%", "%5%" and "%-5%" where the latter
// two cases left and right justify a single '%' in a field of the given
// width. The case "%*%" is not valid here because there is not argument to
// provide the width.
            if (width-1 > 1)
            {   int flags = (dir>>shiftFlags)&maskFlags;
                if ((flags & flagminus) != 0)
                    std::cout << std::setw(width-1)
                              << std::left << "%" << std::right;
                else std::cout << std::setw(width-1) << "%";
            } 
            else std::cout << "%";
// Note that the value left for further traversals of the loop can not
// have a "pending *".
            n = (dir>>shiftEnd) & maskEnd;
        }
    }

    template <typename A1, typename... Rest>
    constexpr void zprintf(uint64_t n, A1&& a1, Rest&&... rest)
    {   std::uint64_t dir =
            (n & ~maskStart) != 0 ? n : nextDirective(n);
        n &= maskStart;
        size_t start = (dir>>shiftStart)&maskStart;
        std::string_view sv(&data()[n], start - n);
        if (sv.size() > 0)
            std::cout << sv; // text before the '%' (or end of format string)

        int type  = (dir>>shiftType)&maskType;
        int subtype  = (dir>>shiftSubType)&maskSubType;
        int flags  = (dir>>shiftFlags)&maskFlags;
        int width = (dir>>shiftWidth)&maskWidth;
        int precision = (dir>>shiftPrecision)&maskPrecision;
        size_t end = (dir>>shiftEnd)&maskEnd;
        if (subtype == 0)
            throw std::invalid_argument(
                "Argument to zprintf does not have a matching '%' sequence");

// If the width or precision fields are specified as "*" I need to grab an
// integer to characterise that
        if (width == 255)
        {   if constexpr (!std::is_integral_v<A1>)
                throw std::invalid_argument(
                    "Argument provided for '*' not an integer");
            else
            {   width = (a1%100) + 1;
                n = (start     & maskStart)    <<shiftStart |
                    (type      & maskType)     <<shiftType |
                    (subtype   & maskSubType)  <<shiftSubType |
                    (flags     & maskFlags)    <<shiftFlags |
                    (width     & maskWidth)    <<shiftWidth |
                    (precision & maskPrecision)<<shiftPrecision |
                    (end       & maskEnd)      <<shiftEnd;
                zprintf(n, rest...);
                return;
            }
        }
        if (precision == 255)
        {   if constexpr (!std::is_integral_v<A1>)
                throw std::invalid_argument(
                    "Argument provided for '*' not an integer");
            else
            {   precision = (a1%100) + 1;
                n = (start     & maskStart)    <<shiftStart |
                    (type      & maskType)     <<shiftType |
                    (subtype   & maskSubType)  <<shiftSubType |
                    (flags     & maskFlags)    <<shiftFlags |
                    (width     & maskWidth)    <<shiftWidth |
                    (precision & maskPrecision)<<shiftPrecision |
                    (end       & maskEnd)      <<shiftEnd;
                zprintf(n, rest...);
                return;
            }
        }
// First I will detect the case of "%xxx%" because that does not use up a
// real argument.
        if  (type==argTypeGeneral && subtype==subtypePercent)
        {   if (width-1 > 1)
            {   if ((flags & flagminus) != 0)
                    std::cout << std::setw(width-1)
                              << std::left << "%" << std::right;
                else std::cout << std::setw(width-1) << "%";
            } 
            else std::cout << "%";
            zprintf(end, a1, rest...);
            return;        
        }
        else
        {
// I may need to issue a large number of IO manipulators!
// On '#' issue std::showbase   .. std::noshowbase
// On '+' issue std::showpos    .. std::noshowpos
// On '-' issue std::left       .. std::right
// On "XEFG"    std::uppercase  .. std::nouppercase
// On "xX"      std::hex        // std::dec
// On '0'       std::setfill('0') .. std::setfill(' ')
// On ' '       std<<cout << " " if the argument is a +ve number
// For e/f/g    std::scientific/std::fixed/std::defaultfloat
//     ???      std::showpoint/std::noshowpoint
// NN.MM        std::setw(NN) std::setprecision(MM)
            if ((flags & flaghash) != 0) std::cout << std::showbase; 
            if ((flags & flagplus) != 0) std::cout << std::showpos; 
            if ((flags & flagminus) != 0) std::cout << std::left; 
            if ((flags & flagzero) != 0) std::cout << std::setfill('0'); 
            if ((subtype & subtypeUpperCase) != 0)
                std::cout << std::uppercase;
            if (type==argTypeInt &&
                (subtype==subtypeHex || subtype==subtypeHexUp))
                std::cout << std::hex;
            if (type==argTypeFloat) switch (subtype & ~subtypeUpperCase)
            {
            case subtypeEformat:
                std::cout << std::scientific;
                break;
            case subtypeFformat:
                std::cout << std::fixed;
                break;
            default:
                std::cout << std::defaultfloat;
                break;
            }
            if (width != 0) std::cout << std::setw(width-1);
            if (precision != 0) std::cout << std::setw(precision-1);
//          if (type==argTypeInt)
//          {   if (!maybe_atomic_int<decltype(a1)>())
//                  throw std::invalid_argument(
//                      "Argument should be an integer");
//          }
//          if (type==argTypeFloat)
//          {   if (!maybe_atomic_float<A1>())
//                  throw std::invalid_argument(
//                      "Argument should be floating_point");
//          }
            if ((flags & flagblank) != 0)
            {   if constexpr (std::is_arithmetic_v<A1>)
                    if (a1 >= 0) std::cout << " ";
            }
#if defined CSL && defined CONSERVATIVE
            if (type == argTypeGeneral && subtype == subtypeAddr)
                std::cout << Addr(a1);
            else
#endif // CSL
            std::cout << a1;
// After printing the argument I need to reset the printing configuration
// to its default state. Well in very many cases none of these miserable
// options will have been used and so this will not actually have to do
// much work!
            if ((flags & flaghash) != 0) std::cout << std::noshowbase; 
            if ((flags & flagplus) != 0) std::cout << std::noshowpos; 
            if ((flags & flagminus) != 0) std::cout << std::right; 
            if ((flags & flagzero) != 0) std::cout << std::setfill(' '); 
            if ((subtype & subtypeUpperCase) != 0)
                std::cout << std::nouppercase;
            if (type==argTypeInt &&
                (subtype==subtypeHex || subtype==subtypeHexUp))
                 std::cout << std::dec;
            if (type==argTypeFloat) std::cout << std::defaultfloat;
            if (precision != 0) std::cout << std::setw(6); // system default
        }

        zprintf((dir>>shiftEnd) & maskEnd, rest...);
    }

    template <typename A1, typename... Rest>
    constexpr void zprintf(uint64_t n, std::atomic<A1>& a1, Rest&&... rest)
    {   zprintf(n, a1.load(), rest...);
    }
};


template <typename... Args>
void zprintf(formatString<my_type_identity_t<Args> ...> format,
             const Args&... args)
{   //std::cout << "nextDirective() = " << std::hex << format.nextDirective()
    //         << std::dec << "\n";
    format.zprintf(0, args...);
    //std::cout << "end of zprintf\n";
}


#endif // header_log_h

// end of "log.h"
