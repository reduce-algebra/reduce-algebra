// stdify.h                                     Copyright (C) 2019 Codemist

// $Id$


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

// If you have code that you are converting from C to C++ style one issue
// that arises is that of the names of library functions. In the old world
// you went
//    #include <stdio.h>
//    ... printf(...); ...
// but in the new world you should probably start with
//    #include <cstdio>
// and then to be proper you need to go either
//    using std::printf;
// or ... std::printf(...) ...
//
// The use of "using" is convenient for a small number of functions but
// becomes pretty gross if applied to everything. And it could be held to be
// giving up on the benefits of C++ namespaces and polluting the global
// namespace.
// When you include <cstdio> it MIGHT in fact inject all names into the global
// namespace as well as define things in std::. So it MIGHT still be possible
// to use just plain "printf". But to rely on that is not safe. Unfortunately
// it seems hard to find a good way to detect when that is being done, eg
// because g++ and associated libraries do define things in the global
// namespace - which is of course convenient for typical use but makes it hard
// to check for strict conformance.
//
// This code takes a source file and has a list of names that are defined
// in a C++ library's set of headers. If unqualified use of any of these
// names is found it inserts a "std::" prefix. This ought to make code
// properly standard conforming.
//
// If a symbol is already written as std::xxx then it will be left alone,
// but symbols in other packages or classes whose names match a library name
// will end up double-qualified, so for instance my::printf would get
// turned into my::std::printf and ::printf into ::std::printf. Such
// cases will lead to compiler diagnostics that will make them easy to fix!
// Also if you have variable names that match library function names those
// get unhelpfully converted, so eg "int sin, sout;" will be turned into
// "int std::sin, sout;" even though there are no maths/trig functions anywhere
// around. Again I leave those to be patched by hand. After this is used it
// is also important to use the C++-style headers such as <cstdio> because
// mere <stdio.h> may not put definitions in the std:: namespace.
//
// So this should not be viewed as 100% automatic, but it does a large fraction
// of the work needed to update code.
// What a messy thing to feel I need to do!

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <unordered_set>


const char *names[] =
{   "isalnum",
    "isalpha",
    "isblank",
    "iscntrl",
    "isdigit",
    "isgraph",
    "islower",
    "isprint",
    "ispunct",
    "isspace",
    "isupper",
    "isxdigit",
    "tolower",
    "toupper",
    "fenv_t",
    "fexcept_t",
    "feclearexcept",
    "fegetexceptflag",
    "feraiseexcept",
    "fesetexceptflag",
    "fetestexcept",
    "fegetround",
    "fesetround",
    "fegetenv",
    "feholdexcept",
    "fesetenv",
    "feupdateenv",
    "imaxdiv_t",
    "imaxabs",
    "imaxdiv",
    "strtoimax",
    "strtoumax",
    "wcstoimax",
    "wcstoumax",
    "signbit",
    "fpclassify",
    "isfinite",
    "isinf",
    "isnan",
    "isnormal",
    "isgreater",
    "isgreaterequal",
    "isless",
    "islessequal",
    "islessgreater",
    "isunordered",
    "isunordered",
    "float_t",
    "double_t",
    "abs",
    "acos",
    "acosf",
    "asin",
    "asinf",
    "atan",
    "atanf",
    "atan2",
    "atan2f",
    "ceil",
    "ceilf",
    "cos",
    "cosf",
    "cosh",
    "coshf",
    "exp",
    "expf",
    "fabs",
    "fabsf",
    "floor",
    "floorf",
    "fmod",
    "fmodf",
    "frexp",
    "frexpf",
    "ldexp",
    "ldexpf",
    "log",
    "logf",
    "log10",
    "log10f",
    "modf",
    "modff",
    "pow",
    "powf",
    "sin",
    "sinf",
    "sinh",
    "sinhf",
    "sqrt",
    "sqrtf",
    "tan",
    "tanf",
    "tanh",
    "tanhf",
    "acosh",
    "acoshf",
    "asinh",
    "asinhf",
    "atanh",
    "atanhf",
    "cbrt",
    "cbrtf",
    "copysign",
    "copysignf",
    "erf",
    "erff",
    "erfc",
    "erfcf",
    "exp2",
    "exp2f",
    "expm1",
    "expm1f",
    "fdim",
    "fdimf",
    "fmaf",
    "fma",
    "fmax",
    "fmaxf",
    "fmin",
    "fminf",
    "hypot",
    "hypotf",
    "ilogb",
    "ilogbf",
    "lgamma",
    "lgammaf",
    "llrint",
    "llrintf",
    "llround",
    "llroundf",
    "log1p",
    "log1pf",
    "log2",
    "log2f",
    "logb",
    "logbf",
    "lrint",
    "lrintf",
    "lround",
    "lroundf",
    "nan",
    "nanf",
    "nearbyint",
    "nearbyintf",
    "nextafter",
    "nextafterf",
    "nexttoward",
    "nexttowardf",
    "remainder",
    "remainderf",
    "remquo",
    "remquof",
    "rint",
    "rintf",
    "round",
    "roundf",
    "scalbln",
    "scalblnf",
    "scalbn",
    "scalbnf",
    "tgamma",
    "tgammaf",
    "trunc",
    "truncf",
    "acosl",
    "asinl",
    "atanl",
    "atan2l",
    "ceill",
    "cosl",
    "coshl",
    "expl",
    "fabsl",
    "floorl",
    "fmodl",
    "frexpl",
    "ldexpl",
    "logl",
    "log10l",
    "modfl",
    "powl",
    "sinl",
    "sinhl",
    "sqrtl",
    "tanl",
    "tanhl",
    "acoshl",
    "asinhl",
    "atanhl",
    "cbrtl",
    "copysignl",
    "erfl",
    "erfcl",
    "exp2l",
    "expm1l",
    "fdiml",
    "fmal",
    "fmaxl",
    "fminl",
    "hypotl",
    "ilogbl",
    "lgammal",
    "llrintl",
    "llroundl",
    "log1pl",
    "log2l",
    "logbl",
    "lrintl",
    "lroundl",
    "nanl",
    "nearbyintl",
    "nextafterl",
    "nexttowardl",
    "remainderl",
    "remquol",
    "rintl",
    "roundl",
    "scalblnl",
    "scalbnl",
    "tgammal",
    "truncl",
    "jmp_buf",
    "longjmp",
    "sig_atomic_t",
    "signal",
    "raise",
    "va_list",
    "ptrdiff_t",
    "size_t",
    "max_align_t",
    "int8_t",
    "int16_t",
    "int32_t",
    "int64_t",
    "uint8_t",
    "uint16_t",
    "uint32_t",
    "uint64_t",
    "int_least8_t",
    "int_least16_t",
    "int_least32_t",
    "int_least64_t",
    "uint_least8_t",
    "uint_least16_t",
    "uint_least32_t",
    "uint_least64_t",
    "int_fast8_t",
    "int_fast16_t",
    "int_fast32_t",
    "int_fast64_t",
    "uint_fast8_t",
    "uint_fast16_t",
    "uint_fast32_t",
    "uint_fast64_t",
    "intptr_t",
    "uintptr_t",
    "intmax_t",
    "uintmax_t",
    "FILE",
    "fpos_t",
    "size_t",
    "fclose",
    "fflush",
    "setbuf",
    "setvbuf",
    "fprintf",
    "fscanf",
    "snprintf",
    "sprintf",
    "sscanf",
    "vfprintf",
    "vfscanf",
    "vsscanf",
    "vsnprintf",
    "vsprintf",
    "fgetc",
    "fgets",
    "fputc",
    "fputs",
    "getc",
    "putc",
    "ungetc",
    "fread",
    "fwrite",
    "fgetpos",
    "fseek",
    "fsetpos",
    "ftell",
    "rewind",
    "clearerr",
    "feof",
    "ferror",
    "perror",
    "fopen",
    "freopen",
    "remove",
    "rename",
    "tmpfile",
    "tmpnam",
    "getchar",
    "gets",
    "scanf",
    "vscanf",
    "printf",
    "putchar",
    "puts",
    "vprintf",
    "size_t",
    "div_t",
    "ldiv_t",
    "lldiv_t",
    "atof",
    "atoi",
    "atol",
    "atoll",
    "strtod",
    "strtof",
    "strtold",
    "strtol",
    "strtoll",
    "strtoul",
    "strtoull",
    "rand",
    "srand",
    "calloc",
    "free",
    "malloc",
    "realloc",
    "abort",
    "atexit",
    "exit",
    "getenv",
    "system",
    "bsearch",
    "qsort",
    "abs",
    "labs",
    "llabs",
    "div",
    "ldiv",
    "lldiv",
    "mblen",
    "mbtowc",
    "wctomb",
    "mbstowcs",
    "wcstombs",
    "aligned_alloc",
    "size_t",
    "memcpy",
    "memmove",
    "strcpy",
    "strncpy",
    "strcat",
    "strncat",
    "memcmp",
    "strcmp",
    "strncmp",
    "strcoll",
    "strxfrm",
    "memchr",
    "strchr",
    "strcspn",
    "strpbrk",
    "strrchr",
    "strspn",
    "strstr",
    "strtok",
    "memset",
    "strerror",
    "strlen",
    "clock_t",
    "size_t",
    "time_t",
    "tm",
    "timespec",
    "clock",
    "difftime",
    "mktime",
    "time",
    "asctime",
    "ctime",
    "gmtime",
    "localtime",
    "strftime",
    "timespec_get",
    "mbstate_t",
    "size_t",
    "tm",
    "wint_t",
    "FILE",
    "fwprintf",
    "fwscanf",
    "swprintf",
    "vfwprintf",
    "vswprintf",
    "swscanf",
    "vfwscanf",
    "vswscanf",
    "fgetwc",
    "fgetws",
    "fputwc",
    "fputws",
    "fwide",
    "getwc",
    "putwc",
    "ungetwc",
    "wcstod",
    "wcstof",
    "wcstold",
    "wcstol",
    "wcstoll",
    "wcstoul",
    "wcstoull",
    "wcscpy",
    "wcsncpy",
    "wcscat",
    "wcsncat",
    "wcscmp",
    "wcscoll",
    "wcsncmp",
    "wcsxfrm",
    "wcschr",
    "wcspbrk",
    "wcsrchr",
    "wcsstr",
    "wmemchr",
    "wcscspn",
    "wcslen",
    "wcsspn",
    "wcstok",
    "wmemcmp",
    "wmemcpy",
    "wmemmove",
    "wmemset",
    "wcsftime",
    "btowc",
    "wctob",
    "mbsinit",
    "mbrlen",
    "mbrtowc",
    "wcrtomb",
    "mbsrtowcs",
    "wcsrtombs",
    "getwchar",
    "vwscanf",
    "wscanf",
    "putwchar",
    "vwprintf",
    "wprintf",
    "wint_t",
    "wctrans_t",
    "wctype_t",
    "iswalnum",
    "iswalpha",
    "iswblank",
    "iswcntrl",
    "iswdigit",
    "iswgraph",
    "iswlower",
    "iswprint",
    "iswpunct",
    "iswspace",
    "iswupper",
    "iswxdigit",
    "iswctype",
    "wctype",
    "towlower",
    "towupper",
    "towctrans",
    "wctrans"
};

std::unordered_set<std::string> words;

enum state
{   generic,
    freshline,
    withinword,
    stdcolon,
    stdcoloncolon,
    stdcoloncolonword,
    slash,
    slashslash,
    slashstar,
    slashstarstar,
    quote,
    quoteback,
    dquote,
    dquoteback
};

int main(int argc, char *argv[])
{   for (auto s : names)
        words.emplace(s);
// I will have a state machine for tokenizing the input
    state cur = freshline;
    int ch;
    std::string word("");
    while ((ch = std::getchar()) != EOF)
    {   switch (cur)
        {
        case stdcolon:
            if (ch == ':') cur = stdcoloncolon;
            else cur = generic;
            goto general;
        case stdcoloncolon:
            if (('A' <= ch && ch <= 'Z') ||
                ('a' <= ch && ch <= 'z') ||
                ch == '_')
            {   cur = stdcoloncolonword;
                std::putchar(ch);
                continue;
            }
            cur = generic;
            goto general;
        case stdcoloncolonword:
            if (('A' <= ch && ch <= 'Z') ||
                ('a' <= ch && ch <= 'z') ||
                ('0' <= ch && ch <= '9') ||
                ch == '_')
            {   std::putchar(ch);
                continue;
            }
            cur = generic;
            goto general;
        case freshline:
            if (ch == '#')         // ignore preprocessor stuff
            {   cur = slashslash;
                std::putchar(ch);
                continue;
            }
            if (ch != ' ' && ch != '\t') cur = generic;
            // drop through
        case generic:
        general:
            switch (ch)
            {
            default:
                if (('A' <= ch && ch <= 'Z') ||
                    ('a' <= ch && ch <= 'z') ||
                    ch == '_')
                {   word.clear();
                    word.push_back(ch);
                    cur = withinword;
                    continue;
                }
                else if (ch == '\n') cur = freshline;
                std::putchar(ch);
                continue;
            case '/':
                cur = slash;
                std::putchar(ch);
                continue;
            case '\'':
                cur = quote;
                std::putchar(ch);
                continue;
            case '"':
                cur = dquote;
                std::putchar(ch);
                continue;
            }
        case withinword:
            if (('A' <= ch && ch <= 'Z') ||
                ('a' <= ch && ch <= 'z') ||
                ('0' <= ch && ch <= '9') ||
                ch == '_')
            {   word.push_back(ch);
                continue;
            }
            if (words.count(word) != 0) std::printf("std::");
            std::printf("%s", word.c_str());
            std::putchar(ch);
            if (ch == ':' && word == "std") cur = stdcolon;
            else cur = generic;
            if (ch == '\n') cur = freshline;
            else if (ch == '/') cur = slash;
            else if (ch == '\'') cur = quote;
            else if (ch == '"') cur = dquote;
            continue;
        case slash:
            switch (ch)
            {
            default:
                cur = generic;
                if (('A' <= ch && ch <= 'Z') ||
                    ('a' <= ch && ch <= 'z') ||
                    ch == '_')
                {   word.clear();
                    word.push_back(ch);
                    cur = withinword;
                    continue;
                }
                else if (ch == '\n') cur = freshline;
                std::putchar(ch);
                continue;
            case '/':
                cur = slashslash;
                std::putchar(ch);
                continue;
            case '*':
                cur = slashstar;
                std::putchar(ch);
                continue;
            case '\'':
                cur = quote;
                std::putchar(ch);
                continue;
            case '"':
                cur = dquote;
                std::putchar(ch);
                continue;
            }
        case slashslash:
            if (ch == '\n') cur = freshline;
            std::putchar(ch);
            continue;
        case slashstar:
            if (ch == '*') cur = slashstarstar;
            std::putchar(ch);
            continue;
        case slashstarstar:
            if (ch == '/') cur = generic;
            else cur = slashstar;
            std::putchar(ch);
            continue;
        case quote:
            std::putchar(ch);
            if (ch == '\'')
            {   cur = generic;
                if (('A' <= ch && ch <= 'Z') ||
                    ('a' <= ch && ch <= 'z') ||
                    ch == '_')
                {   word.clear();
                    word.push_back(ch);
                    cur = withinword;
                }
            }
            else if (ch == '\\') cur = quoteback;
            continue;
        case quoteback:
            cur = quote;
            std::putchar(ch);
            continue;
        case dquote:
            if (ch == '"')
            {   cur = generic;
                if (('A' <= ch && ch <= 'Z') ||
                    ('a' <= ch && ch <= 'z') ||
                    ch == '_')
                {   word.clear();
                    word.push_back(ch);
                    cur = withinword;
                    continue;
                }
            }
            else if (ch == '\\') cur = dquoteback;
            std::putchar(ch);
            continue;
        case dquoteback:
            cur = dquote;
            std::putchar(ch);
            continue;
        }
    }
    return 0;
}

// end of stdify.cpp
