// "log.h"                                                 2020, A C Norman
//
// logging...
//

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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
#include <string_view>
#include <cassert>
#include <stdexcept>


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
// may be more convenient to use then std::printf.
// The implementation uses a combination of template expansion and
// constexpr functions so that all decoding of the format string is
// performed at compile time. In effect a use of zprintf() expands into
// use of the normal C++ iostream facilities... but in many use-cases it
// will be more compact. While many iostream capabilities can be accessed
// using format directives, an escape idiom illutrated here can be used:
//    zprintf("A hack! %s%s%d\n", std::hex, std::uppercase, 0xbad);
// where manipulators are passed via %s. The example prints out the message
// "A hack! BAD", and of course in this case use of "%X" would have
// inserted the manipulators more cleanly.
// The format directive supported are
//    %d      %NNd                             NN denotes a width
//    %x %X   %NNx %NNX   %#x %#X %#NNx %#NNX  # for "0x" prefix, X upper case 
//    %e %E   %NNe %NNE   %NN.NNe %NN.NNE
//    %f and %g                                similarly to %e
//    %s                                       ANY C++ argument
//    %%                                       displays a single %
//
// This code allows printing of arguments that are of type std::atomic<T>
// and displays things as the value stored atomically. For me that feels
// like a really helpful behaviour.
//
// Format string arguments must be provided as literal strings and zprintf
// only prints to the standard output stream (but in the CSL case with
// a copy sent to a spool file if one is active). At present I am not
// certain I know how to relax wither of those limitations.


// To allow all the use of constexpr I need format strings to be
// recognized as compile-time constants. To get everything able to
// be processed at compile time I pass strings as lambdas in the form
//     []{return "string";}
// and the lambda is able to carry the constexpr attribute that I need.
// I hide this mess using a macro for zprintf, but that then wants to
// be variadic, and to support the case where there are no arguments
// beyond the format string I need to worry about dangling commas.
// I also flush the ostream after each use of zprintf. There are two
// reasons for this. The first is that this facility is intended for
// use while debugging so I really want to see the output. The second is
// that the SpoolStream that I have implemented does not synchronise
// very well with std::cout otherwise!

// Trickery to detect whether the C++20 "__VA_OPT__" feature is available.
#define PP_THIRD_ARG(a,b,c,...) c
#define VA_OPT_SUPPORTED_I(...) PP_THIRD_ARG(__VA_OPT__(,),1,0,)
#define VA_OPT_SUPPORTED VA_OPT_SUPPORTED_I(?)

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

// Avoid reliance on inline variables until I am confident that all the
// compilers I ever use support them.

inline SpoolStream<char>& zstream()
{   static SpoolStream<char> z;
    return z;
}

// As of some tests on December 2021 I find g++ supporting __VA_OPT__
// but clang not - however clang supports ##__VA_ARGS__. I have commented
// out use of "#pragma message" to comment on this since in those who cases
// everything should work. But I leave in a report if a different C++
// compiler is in use where neither of those ways to cope with variadic
// macros invoked without arguments is available.

#if VA_OPT_SUPPORTED
//#pragma message ("C++20 __VA_OPT__ available")
#define zprintf(format, ...) \
   (Zprintf([]{return format;} __VA_OPT__(,) __VA_ARGS__), zstream().flush())
#elif defined __GNUC__ || defined __clang__
//#pragma message ("Using g++ clang nonstandard feature ##__VA_ARGS__")
#define zprintf(format, ...) \
   (Zprintf([]{return format;}, ##__VA_ARGS__), zstream().flush())
#else
#pragma message ("Unable to support 1-arg use of zprintf here")
#define zprintf(format, ...) \
   (Zprintf([]{return format;}, __VA_ARGS__), zstream().flush())
#endif

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

// Given a constexpr string I want to find the first "%" in it, or
// if there is no "%" I will stop at the end of the string.

template <typename F>
inline constexpr size_t findEscOrEnd(F format)
{   constexpr const char* buff = format();
    if constexpr (buff[0] == 0 || buff[0] == '%') return 0;
    else return 1+findEscOrEnd([]{return buff+1;});
}

// This overload of zprintf() is for the case where there are no (more)
// arguments to display. There can still be "%%" escapes present, but any
// uther use of "%" is an error.

template <typename F>
inline constexpr void Zprintf(F format)
{   constexpr size_t n = findEscOrEnd(format);
    constexpr const char* data = format();
    if constexpr (data[n] == 0) zstream() << std::flush << data;
    else if constexpr (data[n+1] != '%')
// In this function Zprintf() has been called with a format string but
// no arguments. The only escape sequence permitted will be "%%" and I
// am not going to implement width (etc) modifiers for that. So I will
// complain if I see a "%" followed by anything other than a second "%",
// including the case where it is the final character in the format.
        throw std::invalid_argument(
            "Format specifier but no corresponding argument");
    else
    {   {   constexpr std::string_view first = data;
            zstream() << std::flush << first.substr(0, n+1);
        }
// If a sequence "%%" is present I will send the full string to zstream() in
// one part up to the percent mark and a second beyond it. It is at least
// imaginable that I could arrange to take the string and rewrite it such
// that "%%" maps to "%" all at compile time, but I am not going to view
// that as an optimisation worth the extra complication!
        if constexpr (data[n+1] != 0)
        {   if constexpr (data[n+2] != 0)
            {   constexpr const char* tail = data+n+2;
                Zprintf([]{return tail;});
            }
        }
    }
}

template <typename T>
T plainValue(std::atomic<T>& arg)
{   return arg.load();
}

template <typename T>
T plainValue(T arg)
{   return arg;
}

// Here there is at least one argument for which the format string
// should provide a marker.

template <typename F, typename T, typename... Rest>
inline constexpr void Zprintf(F format, T&& arg1, Rest&&... rest)
{   constexpr size_t n = findEscOrEnd(format);
    constexpr const char* data = format();
    if constexpr (data[n] == 0) throw std::invalid_argument(
        "Format does not have specifiers for all arguments");
    else if constexpr (data[n+1] == 0) throw std::invalid_argument(
        "Format string has '%' as its final character");
    else
    {   constexpr std::string_view buff = data;              // Eg "v=%d\n"
        constexpr std::string_view front = buff.substr(0,n); //    "v="
        constexpr const char* back = data+n+1;               //    "d\n"
        zstream() << std::flush << front;
// I will support a subset of the full set if C++ format specifier
// options. But maybe I will try to parse all of them that are at all
// relevant just in case I get keener later. As I do this I will
// accumulate an integer value that encodes all I find as follows:
//   0x000000ff     number of characters used by the specifier
//   0x00007f00     "width" numeric value + 1
//                  or 0 if no explicit width given
//   0x00008000     set if width is "*"     
//   0x007f0000     "precision" numeric value + 1
//                  or 0 if no explicit precision given
//   0x00800000     set if precision is "*"
//   0x01000000     set if '-' flag
//   0x02000000     set if '+' flag
//   0x04000000     set if ' ' flag
//   0x08000000     set if '#' flag
//   0x10000000     set if '0' flag
// [If I was more proper I would use an enum type for all those magic
//  numbers!]
        constexpr int32_t spec0 = 0;
// detect flags, which can be one of "-+ #0"
        constexpr char c1 = back[spec0&0xff];
        constexpr int32_t spec1 =
            c1 == '-' ? spec0 + 1 + 0x01000000 :
            c1 == '+' ? spec0 + 1 + 0x02000000 :
            c1 == ' ' ? spec0 + 1 + 0x04000000 :
            c1 == '#' ? spec0 + 1 + 0x08000000 :
            c1 == '0' ? spec0 + 1 + 0x10000000 :
            spec0;
// Now look for a width, which can be either '*' or one or two
// digits. I will not support widths greater than 99.
// In the code here I have to take care not to stray beyond the end of the
// format string, and the compile-time processing may expand both branches
// of a conditional expression even when it can evaluate the predicate.
        constexpr size_t p1 = spec1 & 0xff;
        constexpr char c2 = back[p1];
        constexpr char c2a = back[c1==0 ? p1 : p1+1];
        constexpr int32_t spec2 =
            c2 == '*' ? spec1 + 1 + 0x00008000 :
            isDigit(c2) ?
                (isDigit(c2a) ?
                    spec1 + 2 +256*(10*digitVal(c2)+digitVal(c2a) + 1) :
                spec1 + 1 + 256*(digitVal(c2)+1)) :
            spec1;
// Next see if we have ".*" or ".N" or ".NN" with N denoting a digit. That
// would indicate a precision.
        constexpr size_t p2 = spec2 & 0xff;
        constexpr char c3 = back[p2];
        constexpr size_t p2a = c3==0 ? p2 : p2+1;
        constexpr char c3a = back[p2a];
        constexpr char c3b = c3a==0 ? p2a : p2a+1;
        constexpr int32_t spec3 =
            c3 != '.' ? spec2 :
            c3a == '*' ? spec2 + 2 + 0x00800000 :
            !isDigit(c3a) ? throw std::invalid_argument(
                "Format specifier contains '.' not followed by a digit") :
            isDigit(c3b) ?
                spec2 + 3 + 0x10000*(10*digitVal(c3a) + digitVal(c3b) + 1) :
            spec2 + 2 + 0x10000*(digitVal(c3a) + 1);
// In "printf" there can now be some modifiers such as "l" and "h" that
// specify things mostly about the width of the argument, so that for
// instance "%lld" may be used to print a long int. Here the type of
// the actual argument will be interrogated as part of handling "<<" to the
// output stream, so I will not need these. So all I have left is the
// indication of the sort of formatting I want. Plausible cases are
// d, x, s, e, f and g. I will use s as the catch-all that lets iostream
// decide what to do.
//
// Note that at least at present I do not support dynamic width or
// precision specifications (ie as in "%*s" and "%*.*g").
        constexpr char c4 = back[spec3&0xff];
        auto actualArg = plainValue(arg1);
        switch (c4)
        {
            case 'd':
                if constexpr (!std::is_integral_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-integral type used with %d format specifier");
                break;
            case 'x':
                if constexpr (!std::is_integral_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-integral type used with %x format specifier");
                zstream() << std::flush << std::hex;
                if (spec3 & 0x08000000) zstream() << std::flush << std::showbase;
                break;
            case 'X':
                if constexpr (!std::is_integral_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-integral type used with %d format specifier");
                zstream() << std::flush << std::hex;
                if (spec3 & 0x08000000) zstream() << std::flush << std::showbase;
                zstream() << std::flush << std::uppercase;
                break;
            case 's':
                break;
            case 'e':
                if constexpr (!std::is_floating_point_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-floating-point type used with %e format specifier");
                zstream() << std::flush << std::scientific;
                break;
            case 'f':
                if constexpr (!std::is_floating_point_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-floating-point type used with %f format specifier");
                zstream() << std::flush << std::fixed;
                break;
            case 'g':
                if constexpr (!std::is_floating_point_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-floating-point type used with %g format specifier");
                zstream() << std::flush << std::defaultfloat;
                break;
            case 'E':
                if constexpr (!std::is_floating_point_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-floating-point type used with %E format specifier");
                zstream() << std::flush << std::scientific;
                zstream() << std::flush << std::uppercase;
                break;
            case 'F':
                if constexpr (!std::is_floating_point_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-floating-point type used with %F format specifier");
                zstream() << std::flush << std::fixed;
                zstream() << std::flush << std::uppercase;
                break;
            case 'G':
                if constexpr (!std::is_floating_point_v<decltype(actualArg)>)
                    throw std::invalid_argument(
                        "Non-floating-point type used with %G format specifier");
                zstream() << std::flush << std::defaultfloat;
                zstream() << std::flush << std::uppercase;
                break;
            case '%':
                zstream() << std::flush << '%';
                Zprintf([]{return back+1;}, arg1, rest...);
                return;
            default:
                throw std::invalid_argument(
                    "Format contains unrecognised directive");
        }
        if constexpr (((spec3>>8) & 0x7f) > 0)
            zstream() << std::flush << std::setw(((spec3>>8) & 0x7f) - 1);
        if constexpr (((spec3>>16) & 0x7f) > 0)
            zstream() << std::flush << std::setprecision(((spec3>>16) & 0x7f) - 1);
// Now I can actually display the argument!
        zstream() << std::flush << actualArg;
// Some of the IO manipulators have sticky effect and so will explicitly
// cancel them. "setw()" only impacts the next displayed item and so I
// do not need to reset that.
        switch (c4)
        {
            case 'E':
            case 'F':
            case 'G':
                zstream() << std::flush << std::nouppercase;
                break;
            case 'X':
                zstream() << std::flush << std::nouppercase;
                // drop through.
            case 'x':
                if (spec3 & 0x08000000) zstream() << std::flush << std::noshowbase;
                zstream() << std::flush << std::dec;
                break;
            default:
                break;
        }
        zstream() << std::flush;
        if constexpr (back[spec3 & 0xff] != 0)
            Zprintf([]{return back+1+(spec3&0xff);}, rest...);
    }
}

#endif // header_log_h

// end of "log.h"
