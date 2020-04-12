// recast.h                                     Copyright (C) 2020 Codemist

// $Id: stdify.cpp 5179 2019-10-31 16:20:08Z arthurcnorman $


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

//
// This is a utility that is intended to map
//                  (T)x
// to       reinterpret_cast<T>(x)
// for a range of cases T, These will start off as
//       int, unsigned int, long, unsigned long,
//       float, double, void
//       std::int32_t, std::uint32_t,
//       std::int64_t, std::uint64_t,
//       std::intptr_t, std::uintptr_t,
//       std::size_t
// and all of those followed by "*".
// I will also allow myself to add some custom user-defined class names
// and here Object and Bignum will be the top cases.
//
// I will convert all of these into reinterpret_cast<> where some ought to
// turn into eg static_cast (for unchecked changing the type of a class
// referred to and for type conversions among plain old data types),
// dynamic_cast (checked conversion between classes), reinterpret_cast
// messing with pointers in a thoroughly old fashioned and disgraceful
// manner) or const_cast (adding or removing a const qualifier).
// Well maybe for (int), (float) and (double) I will generate static_cast
// as a decent guess. But the code will need manual inspection afterwards.
// So this should not be viewed as 100% automatic, but it does a large
// fraction of the work needed to update code.
// What a messy thing to feel I need to do!


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;

// What I need here is a list of all the types I can imagine anybody
// ever casting to. Eg I have not put the specializations of std::vector<>
// in because I find it hard to imagine casts involving them. Indeed some
//
// User types also need listing. If the test here is XXX I will scan the
// source file looking for (XXX).
// I have (in an ugly way) written "T" and "T*" and "T *" in this list
// and will jook for those exact strings of characters. So alternative
// whitespace etc will cause confusion.
// It also looks as if I will want to detect and discount the spacial
// case of "sizeof(XXX)" because the parens there are not indicating a
// cast!

const char *typeNames[] =
{
    "char",
    "signed char",
    "unsigned char",
    "short",
    "unsigned short",
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "long long",
    "unsigned long long",
    "float",
    "double",
    "long double",
    "void",
    "std::int8_t",
    "std::uint8_t",
    "std::int16_t",
    "std::uint16_t",
    "std::int32_t",
    "std::uint32_t",
    "std::int64_t",
    "std::uint64_t",
    "std::intptr_t",
    "std::uintptr_t",
    "std::size_t",
    "int128_t",
    "uint128_t",
    "INT128",
    "UINT128",
    "char*",
    "signed char*",
    "unsigned char*",
    "short*",
    "unsigned short*",
    "int*",
    "unsigned int*",
    "long*",
    "unsigned long*",
    "long long*",
    "unsigned long long*",
    "float*",
    "double*",
    "long double*",
    "void*",
    "std::int8_t*",
    "std::uint8_t*",
    "std::int16_t*",
    "std::uint16_t*",
    "std::int32_t*",
    "std::uint32_t*",
    "std::int64_t*",
    "std::uint64_t*",
    "std::intptr_t*",
    "std::uintptr_t*",
    "std::size_t*",
    "char *",
    "signed char *",
    "unsigned char *",
    "short *",
    "unsigned short *",
    "int *",
    "unsigned int *",
    "long *",
    "unsigned long *",
    "long long *",
    "unsigned long long *",
    "float *",
    "double *",
    "long double *",
    "void *",
    "std::int8_t *",
    "std::uint8_t *",
    "std::int16_t *",
    "std::uint16_t *",
    "std::int32_t *",
    "std::uint32_t *",
    "std::int64_t *",
    "std::uint64_t *",
    "std::intptr_t *",
    "std::uintptr_t *",
    "std::size_t *",
    "std::atomic<char>",
    "std::atomic<signed char>",
    "std::atomic<unsigned char>",
    "std::atomic<short>",
    "std::atomic<unsigned short>",
    "std::atomic<int>",
    "std::atomic<unsigned int>",
    "std::atomic<long>",
    "std::atomic<unsigned long>",
    "std::atomic<long long>",
    "std::atomic<unsigned long long>",
    "std::atomic<float>",
    "std::atomic<double>",
    "std::atomic<long double>",
    "std::atomic<void>",
    "std::atomic<std::int8_t>",
    "std::atomic<std::uint8_t>",
    "std::atomic<std::int16_t>",
    "std::atomic<std::uint16_t>",
    "std::atomic<std::int32_t>",
    "std::atomic<std::uint32_t>",
    "std::atomic<std::int64_t>",
    "std::atomic<std::uint64_t>",
    "std::atomic<std::intptr_t>",
    "std::atomic<std::uintptr_t>",
    "std::atomic<std::size_t>",
    "std::atomic<char *>",
    "std::atomic<signed char *>",
    "std::atomic<unsigned char *>",
    "std::atomic<short *>",
    "std::atomic<unsigned short *>",
    "std::atomic<int *>",
    "std::atomic<unsigned int *>",
    "std::atomic<long *>",
    "std::atomic<unsigned long *>",
    "std::atomic<long long *>",
    "std::atomic<unsigned long long *>",
    "std::atomic<float *>",
    "std::atomic<double *>",
    "std::atomic<long double *>",
    "std::atomic<void *>",
    "std::atomic<std::int8_t *>",
    "std::atomic<std::uint8_t *>",
    "std::atomic<std::int16_t *>",
    "std::atomic<std::uint16_t *>",
    "std::atomic<std::int32_t *>",
    "std::atomic<std::uint32_t *>",
    "std::atomic<std::int64_t *>",
    "std::atomic<std::uint64_t *>",
    "std::atomic<std::intptr_t *>",
    "std::atomic<std::uintptr_t *>",
    "std::atomic<std::size_t *>",
    "const char*",
    "const signed char*",
    "const unsigned char*",
    "const short*",
    "const unsigned short*",
    "const int*",
    "const unsigned int*",
    "const long*",
    "const unsigned long*",
    "const long long*",
    "const unsigned long long*",
    "const float*",
    "const double*",
    "const long double*",
    "const void*",
    "const std::int8_t*",
    "const std::uint8_t*",
    "const std::int16_t*",
    "const std::uint16_t*",
    "const std::int32_t*",
    "const std::uint32_t*",
    "const std::int64_t*",
    "const std::uint64_t*",
    "const std::intptr_t*",
    "const std::uintptr_t*",
    "const std::size_t*",
    "const char *",
    "const signed char *",
    "const unsigned char *",
    "const short *",
    "const unsigned short *",
    "const int *",
    "const unsigned int *",
    "const long *",
    "const unsigned long *",
    "const long long *",
    "const unsigned long long *",
    "const float *",
    "const double *",
    "const long double *",
    "const void *",
    "const std::int8_t *",
    "const std::uint8_t *",
    "const std::int16_t *",
    "const std::uint16_t *",
    "const std::int32_t *",
    "const std::uint32_t *",
    "const std::int64_t *",
    "const std::uint64_t *",
    "const std::intptr_t *",
    "const std::uintptr_t *",
    "const std::size_t *",
// Add any more type-names you like here
    "Object",
    "Bignum",
    "Object*",
    "Bignum*",
    "Object *",
    "Bignum *"
};

// If you cast to any of the following I will make it a static_cast not
// a reinterpret_cast. Note that I have not put intptr_t in this list
// and I have not put any pointer types.

const char *staticCastable[] =
{   "char",
    "signed char",
    "unsigned char",
    "short",
    "unsigned short",
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "long long",
    "unsigned long long",
    "float",
    "double",
    "long double",
    "void",
    "int8_t",
    "uint8_t",
    "int16_t",
    "uint16_t",
    "int32_t",
    "uint32_t",
    "int64_t",
    "uint64_t",
    "size_t",
    "std::int8_t",
    "std::uint8_t",
    "std::int16_t",
    "std::uint16_t",
    "std::int32_t",
    "std::uint32_t",
    "std::int64_t",
    "std::uint64_t",
    "std::size_t",
    "int128_t",
    "uint128_t",
    "INT128",
    "UINT128"
};


// I am going to be pretty sloppy about parsing, but I do want to detect
// preprocessor stuff, comments, character literals and strings because
// stuff within those should not be a candidate for conversion. I will take
// a view that I will not support casts where there are any of those
// interleaved, so a case such as "(/*cast to*/double)X" will not be
// recognised. As I scan I will send any of those special parts direct
// to the output but collect "generic" material in a buffer and when
// I move beyond it I will scan and process that further.

enum state
{   generic,
    freshline,
    slash,
    slashslash,
    slashstar,
    slashstarstar,
    quote,
    quoteback,
    dquote,
    dquoteback
};

static std::string word("");


void flushPending()
{   // cout << "{@" << word << "@}";
    const char *s = word.c_str();    // At present I like scanning C strings!
    const char *p = s;
    for (;;)
    {
// Find the first '(' - if any and subject to it not following the
// characters "sizeof". Note that this is crudely done so "xsizeof(" would
// ignore the inconvenient "x" and still believe it has a use of "sizeof"!
        while (*p != 0 &&
               (*p != '(' ||
                (p-s>=6 && std::strncmp(p-6, "sizeof", 6)==0))) p++;
        std::printf("%.*s", (int)(p-s), s); std::fflush(stdout);
        if (*p == 0) break;
        s = p;   // print all that comes before the "(".
        const char *q = s+1;
        int qq;
        while ((qq = *q++) != 0)
        {   if (qq == '(')
            {   //std::printf("%.*s", q-s, s); std::fflush(stdout);
                s = q;
            }
            else if (qq == ')') break;
        }
        if (qq == 0)
        {   std::printf("%s", p); std::fflush(stdout);
            break;
        }
// At this stage p is a segment enclosed in parens.
        bool found = false;
        for (const char *t:typeNames)
        {   if (std::strlen(t) == q-p-2 &&
                std::strncmp(t, p+1, q-p-2)==0)
            {   found = true;
                break;
            }
        }
        if (found)
        {   const char *r = q;
            int depth = 0;
            int any = false;
            for (;;)
            {   qq = *r++;
                if (!any && qq == ' ') continue;
                any++;
                if (qq == '(') depth++;
                else if (qq == ')')
                {   depth--;
                    if (depth <= 0) break;
                }
                else if (qq = 0 ||
                    (depth==0 && !std::isalnum(qq) && qq!='_')) break;
            }
            if (qq != ')') r--;
            const char *castType = "reinterpret";
            for (const char *cc:staticCastable)
            {   if (std::strncmp(p+1, cc, std::strlen(cc)) == 0)
                    castType = "static";
            }
            std::printf("%s_cast<%.*s>", castType, (int)(q-p-2), p+1); std::fflush(stdout);
            while (*q==' ') q++;
            if (*q=='(') std::printf("%.*s", (int)(r-q), q);
            else std::printf("(%.*s)", r-q, q);
            std::fflush(stdout);
            q = r;
        }
        else std::printf("%.*s", (int)(q-p), p);
        std::fflush(stdout);
        p = s = q;  // Continue with the rest of the segment
    }
    word.clear();
}

int main(int argc, char *argv[])
{
    state cur = freshline;
    int ch;
    FILE* input = stdin;
    if (argc > 1) input = std::fopen(argv[1], "r");
    word.clear();
    while ((ch = std::getc(input)) != EOF)
    {   switch (cur)
        {
// Being at the start of a line is only special in that if I see a
// "#" with at most whitespace before it I have a pre-processor directive.
        case freshline:
            if (ch == '#')         // ignore preprocessor stuff
            {   cur = slashslash;  // Ha Ha treat it as a comments, so
                flushPending();
                std::putchar(ch);  // "#XXX ..." is treated just like
                std::fflush(stdout);
                continue;          // "// ..." would be.
            }
            if (ch != ' ' && ch != '\t') cur = generic;
            // drop through
        case generic:
        general:
            switch (ch)
            {
            default:
                word.push_back(ch);
                continue;
            case '\n':
                word.push_back(ch);
                cur = freshline;
                continue;
            case '/':
                cur = slash;
                word.push_back(ch);
                continue;
            case '\'':
                cur = quote;
                flushPending();
                std::putchar(ch);
                std::fflush(stdout);
                continue;
            case '"':
                cur = dquote;
                flushPending();
                std::putchar(ch);
                std::fflush(stdout);
                continue;
            }
        case slash:
            switch (ch)
            {
            default:
                cur = generic;
                if (ch == '\n') cur = freshline;
                word.push_back(ch);
                continue;
            case '/':
                cur = slashslash;
                flushPending();
                std::putchar(ch);
                std::fflush(stdout);
                continue;
            case '*':
                cur = slashstar;
                flushPending();
                std::putchar(ch);
                std::fflush(stdout);
                continue;
            case '\'':
                cur = quote;
                flushPending();
                std::putchar(ch);
                std::fflush(stdout);
                continue;
            case '"':
                cur = dquote;
                flushPending();
                std::putchar(ch);
                std::fflush(stdout);
                continue;
            }
        case slashslash:
            if (ch == '\n') cur = freshline;
            std::putchar(ch);
            continue;
        case slashstar:
            if (ch == '*') cur = slashstarstar;
            std::putchar(ch);
            std::fflush(stdout);
            continue;
        case slashstarstar:
            if (ch == '/')
            {   word.clear();
                cur = generic;
            }
            else if (ch != '*') cur = slashstar;
            std::putchar(ch);
            std::fflush(stdout);
            continue;
        case quote:
            flushPending();
            std::putchar(ch);
            std::fflush(stdout);
            if (ch == '\'')
            {   word.clear();
                cur = generic;
            }
            else if (ch == '\\') cur = quoteback;
            continue;
        case quoteback:
            cur = quote;
            std::putchar(ch);
            std::fflush(stdout);
            continue;
        case dquote:
            if (ch == '"')
            {   word.clear();
                cur = generic;
            }
            else if (ch == '\\') cur = dquoteback;
            std::putchar(ch);
            std::fflush(stdout);
            continue;
        case dquoteback:
            cur = dquote;
            std::putchar(ch);
            std::fflush(stdout);
            continue;
        }
    }
    flushPending();
    return 0;
}

// end of recast.cpp

