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

// An "my_assert" scheme that lets me write in my own code to print the
// diagnostics. I also "exit()" rather than "abort()" since that is slightly
// cleaner!

[[noreturn]] inline void my_abort()
{   std::exit(EXIT_FAILURE);
}

[[noreturn]] inline void my_abort(const char *msg)
{   std::fprintf(stderr, "\n\n!!! Aborting: %s\n\n", msg);
    std::fflush(stderr);
    std::exit(EXIT_FAILURE);
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

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif // LONGEST_LEGAL_FILENAME

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
    {   char logfile_name[LONGEST_LEGAL_FILENAME];
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

#endif // header_log_h

// end of "log.h"
