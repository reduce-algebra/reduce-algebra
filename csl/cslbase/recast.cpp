// recast.cpp                                   Copyright (C) 2020 Codemist

// $Id$


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
    "float32_t",
    "float64_t",
    "float128_t",
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
    "float32_t*",
    "float64_t*",
    "float128_t*",
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
    "float32_t *",
    "float64_t *",
    "float128_t *",
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
    "LispObject",
    "Header",
    "Cons_Cell",
    "Object*",
    "Bignum*",
    "LispObject*",
    "Header*",
    "Cons_Cell*",
    "Object *",
    "Bignum *",
    "LispObject *",
    "Header *",
    "Cons_Cell *",
    "std::atomic<Object>",
    "std::atomic<Bignum>",
    "std::atomic<LispObject>",
    "std::atomic<Header>",
    "std::atomic<Object*>",
    "std::atomic<Bignum*>",
    "std::atomic<LispObject*>",
    "std::atomic<Header*>",
    "std::atomic<Object *>",
    "std::atomic<Bignum *>",
    "std::atomic<LispObject *>",
    "std::atomic<Header *>",
    "std::atomic<Object> *",
    "std::atomic<Bignum> *",
    "std::atomic<LispObject> *",
    "std::atomic<Header> *",
    "std::atomic<Object*> *",
    "std::atomic<Bignum*> *",
    "std::atomic<LispObject*> *",
    "std::atomic<Header*> *",
    "std::atomic<Object *> *",
    "std::atomic<Bignum*> *",
    "std::atomic<LispObject*> *",
    "std::atomic<Header*> *",
    "std::atomic<Object *> *",
    "std::atomic<Bignum *> *",
    "std::atomic<LispObject *> *",
    "std::atomic<Header *> *"
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
    "UINT128",
    "LispObject",
    "Header"
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
static char buffer[1000000] = "                    ";

// This tried to judge whether the string starting at p might be a
// C style cast.

char* looksLikeCast(char* p)
{   if (*p != '(') return NULL;   // No "(" at start means NO
    bool found = false;
    size_t len;
    for (const char *t:typeNames)
    {   len = std::strlen(t);
        if (std::strncmp(t, p+1, len)==0 && p[len+1]==')')
        {   found = true;
            break;
        }
    }
    if (!found) return NULL;
    if (std::strncmp(p-6, "sizeof", 6) == 0) return NULL;
// If the apparent cast is the final item in this buffer then it will not
// be proper to treat it as a cast. A case where this naturally arises is
// with a declataion like
//       extern void foo(int);
// where the formal argument is indicated by giving its type but no
// associated name.
    const char *q = p+len+2;
    while (*q == ' ') q++;
    if (*q == 0 || *q==';') return NULL;
    return p+len+2;
}

char* skipToMatching(char *p)
{   int sqdepth=0, angdepth = 0, pardepth=0;
    for (; *p!=0; p++)
    {   switch (*p)
        {
        case '[':
            sqdepth++;
            continue;
        case '<':
            angdepth++;
            continue;
        case '(':
            pardepth++;
            continue;
        case ']':
            if (sqdepth == 0) return p+1;
            sqdepth--;
            continue;
        case '>':
            if (angdepth == 0) return p+1;
            angdepth--;
            continue;
        case ')':
            if (pardepth == 0) return p+1;
            pardepth--;
            continue;
        default:
            continue;
        }
    }
    return p;
}

char* endOfCasted(char* p)
{
// If the original form is (T)(something in parens) then when I return
// from here I will not insert an extra set of parens, so I can view just
// say that the cast ends at the opening "(".
    if (*p == '(') return p+1;
// Here the cast is followed by something else. The things I must scan past
// must include
//    (T)name        (T)number     (T)floating-point-number
//    (T)name.selector
//    (T)name[subscript]
//    (T)name(args, ...)
//    (T)foo_cast<T1>(E)
//    (T)+something or (T)-something or (T)~something
// but there are some cases that could get a little close:
//      (T)1.2e+3                     vs.    (T)1.2+3
//      (T)static_cast<something...   vs.    (T)variable<something...
// At present I will not worrt about the first (and a ")" will be inserted
// just before the "+" in each case, damaging the floating point number that
// was written with an exponent). I make some attempt to cope with the second.
    char* oldp = p;
    int sqdepth=0, pardepth=0;
    for (;*p!=0; p++)
    {   switch (*p)
        {
        case '<':
            switch (p-oldp)
            {
            default:
                return p;
            case 11:
                if (std::strncmp(oldp, "static_cast", p-oldp) != 0) return p;
                break;
            case 16:
                if (std::strncmp(oldp, "reinterpret_cast", p-oldp) != 0) return p;
                break;
            case 10:
                if (std::strncmp(oldp, "const_cast", p-oldp) != 0) return p;
                break;
            case 12:
                if (std::strncmp(oldp, "dynamic_cast", p-oldp) != 0) return p;
                break;
            }
// OK here I have a mess! The start of the text after a cast that I am in the
// process of looking at contains "zzz_cast<". I need first the skip to the
// ">" that matches the "<" I have just seen, then after that slip to the end
// of a patenthesised unit (which must be there!)
            p = skipToMatching(p+1);
            if (*p != '(') return p;
            return skipToMatching(p+1);
        case '[':
            sqdepth++;
            continue;
        case '(':
            pardepth++;
            continue;
        case ']':
            if (sqdepth==0) return p;
            sqdepth--;
            continue;
        case ')':
            if (pardepth==0) return p;
            pardepth--;
            continue;
        default:
            if (sqdepth!=0 || pardepth!=0) continue;
            if (std::isalnum(*p) || *p=='_' || *p=='.') continue;
            return p;
        }
    }
    return p;
}

// Insert next text in buffer by deleting n characters and replacing then with
// the given text.
void insert(const char* text, char *buffer, std::size_t n)
{   std::size_t len = std::strlen(text);
    std::size_t bLen = std::strlen(buffer);
    std::memmove(buffer+len-n, buffer, bLen+1);
    std::memmove(buffer, text, len);
}

void flushPending()
{   std::strcpy(&buffer[16], word.c_str());
    char *b = &buffer[16];
    if (std::strlen(b) == 0) return;
    char *p, *q, *r;
    for (;;) // I will do one pass per cast that I find
    {   p = b + std::strlen(b);
        while (p!=b && (q = looksLikeCast(p)) == NULL) p--;
        if (q == NULL) break;
        size_t origLen = q-p;
        const char *castType = "reinterpret";
        for (const char *cc:staticCastable)
        {   if (std::strncmp(p+1, cc, std::strlen(cc)) == 0 &&
                p[std::strlen(cc)+1] == ')')
                castType = "static";
        }
// Now, within the buffer b, I have pointers p and q where p is the
// start of (XXX) and q is one beyond its end.
// Now I need to look beyond the cast itself and turn
//           (XXX)zzz to yyy_cast<XXX>(zzz)
// except that if zzz is already in parens I will not need to add
// another set. The item zzz might be
//    ( almost anything )
//    name.something
//    name[ almost anything ]
//    name( almost anything )
//    yyyyyy_cast<stuff>( almost anything )
//
// I will NOT go to the trouble of parsing case such as (*fptr)(args) if
// only because I think that sane programmers will have put in extra
// parens to make it quite clear whether the cast applies to the
// function expression or to the whole function call. But really mostly
// because this whole program is intended to deal with the easier cases
// and it accepts that manual clean-up of messier ones will be called for.
// Also if anybody leaves whitespace as in "(XXX)  something" I will mess up.
// I will come back to the conversion from (XXX) to yyy_cast<XXX> in a bit.
        r = endOfCasted(q);
        if (*q != '(')
        {   insert(")", r, 0);
            insert("(", q, 0);
        }
// I now turn (XXX) into yyy_cast<XXX>
        char temp[64];
        std::sprintf(temp, "%s_cast<%.*s>", castType, (q-p-2), p+1);
        insert(temp, p, origLen);
    }
    std::printf("%s", b);
    std::fflush(stdout);
    word.clear();
}

int main(int argc, char* argv[])
{   state cur = freshline;
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
            case ';':
            case '{':
            case '}':
                word.push_back(ch);
                flushPending();
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

