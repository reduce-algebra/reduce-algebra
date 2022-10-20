// cslread.cpp                             Copyright (C) 1990-2022 Codemist

//
// Reading and symbol-table support.
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

#define DEFINE_GOODPRIMES 1

#include "headers.h"

#ifdef SOCKETS
#include "sockhdr.h"
#endif

// At present CSL is single threaded - at least as regards file IO - and
// using the unlocked versions of putc and getc can be a MAJOR saving.

#ifdef HAVE_GETC_UNLOCKED
#define GETC(x) getc_unlocked((FILE *)(x))
#else
#ifdef HAVE__GETC_NOLOCK
#define GETC(x) _getc_nolock((FILE *)(x))
#else
#define GETC(x) getc((FILE *)(x))
#endif
#endif

#ifdef HAVE_PUTC_UNLOCKED
#define PUTC(x, y) putc_unlocked((x), (FILE *)(y))
#else
#ifdef HAVE__PUTC_NOLOCK
#define PUTC(x, y) _putc_nolock((x), (FILE *)(y))
#else
#define PUTC(x, y) putc((x), (FILE *)(y))
#endif
#endif

#define CTRL_C    3
#define CTRL_D    4
#define CTRL_G    7

int first_char(LispObject ch)
{   // ch is a symbol. Get the first character of its name.
    ch = characterify(ch);
    return code_of_char(ch);
}

//      Basic version of Lisp reader.

static int curchar = NOT_CHAR;
std::FILE *non_terminal_input;

size_t boffop;

LispObject make_string(const char *b)
// Given a C string, create a Lisp (simple-) string.
{   size_t n = std::strlen(b);
    LispObject r = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    char *s = bit_cast<char *>(r) - TAG_VECTOR;
    size_t k = doubleword_align_up(CELL+n);
// The final word of the string must be zero, and get_basic_vector has
// not arranged that. On a 32-bit system there can be a padding word beyond
// the last one that contains characters and that too ought to be set to
// zero if only to be tidy. So in that cases eg strings with 0, 1, 2 or 3
// characters fit (including their header word) within a 64-bit unit while
// those with 4, 5, 6 or 7 spill into a second pair of words and the second
// of those is the padder. Using memset probably leads to compilation that
// writes the zeros with a word memory access but avoids C++ worries
// about strict aliasing.
    if (SIXTY_FOUR_BIT || n%8 >= 4)
        std::memset(s+k-8, 0, 8);
    else std::memset(s+k-4, 0, 4);
    std::memcpy(s + CELL, b, (size_t)n);
    validate_string(r);
    return r;
}

void validate_string_fn(LispObject s, const char *file, int line)
{   if (is_vector(s) && is_string_header(vechdr(s)))
    {   size_t len = length_of_byteheader(vechdr(s));
        size_t len1 = doubleword_align_up((uintptr_t)len);
        while (len < len1)
        {   if (celt(s, len-CELL) != 0)
            {   char *p = bit_cast<char *>(s - TAG_VECTOR);
                size_t i;
                if (std::strrchr(file, '/') != nullptr) file = std::strrchr(file,
                            '/')+1;
                std::fprintf(stderr, "\n+++ Bad string at %s %d\n", file, line);
                std::fprintf(stderr, "Header = %" PRIx64 "\n",
                    static_cast<uint64_t>(vechdr(s)));
                std::fprintf(stderr, "length = %d bytelength = %d\n",
                             static_cast<int>(length_of_header(vechdr(s))),
                             static_cast<int>(length_of_byteheader(vechdr(s))));
                std::fprintf(stderr, "messed at len:%d len1:%d [%x]\n",
                             static_cast<int>(len), static_cast<int>(len1),
                             static_cast<int>(celt(s, len-CELL)));
                for (i=0; i<len1; i++)
                {   std::fprintf(stderr, "%3d %p: %.2x   (%c)\n", static_cast<int>(i),
                                 p, *p, *p);
                    p++;
                }
                std::fflush(stderr);
                my_abort("string format invalid");
            }
            len++;
        }
        return;
    }
    std::fprintf(stderr, "\n+++ Not even a string at %s %d\n", file,
                 line);
    std::fprintf(stderr, "Header = %" PRIxMAX "\n",
                 (std::intmax_t)vechdr(s));
    std::fflush(stderr);
    my_abort("string format invalid");
}

LispObject copy_string(LispObject str, size_t n)
// Given a Lisp string, plus its length, create a Lisp (simple-) string.
// NOTE that the "string" passed in may not in fact have the length
// you think it has - it may be boffo which is used as a string buffer.
{   LispObject r;
    char *s;
    size_t k;
    THREADID;
    Save save(THREADARG str);
    r = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    errexit();
    save.restore(str);
    s = bit_cast<char *>(r) - TAG_VECTOR;
    std::memcpy(s + CELL,
                bit_cast<char *>(str) + (CELL-TAG_VECTOR), (size_t)n);
    k = doubleword_align_up(CELL+n)-CELL;
    while (n < k) s[CELL+n++] = 0;
    validate_string(r);
    return r;
}

LispObject Lvalidate_package(LispObject env, LispObject p)
{   std::printf("package = %p\n", bit_cast<void *>(p));
    Lprint(env, p);
    std::printf("%p\n", bit_cast<void *>(packhdr_(p)));
    Lprint(env, packid_(p));
    Lprint(env, packint_(p));
    Lprint(env, packnint_(p));
    Lprint(env, packflags_(p));
    std::printf("Done\n");
    return onevalue(nil);
}

LispObject Lvalidate_package(LispObject env)
{   return Lvalidate_package(env, CP);
}

extern bool always(LispObject);
typedef bool symbol_processor_predicate(LispObject);
extern bool push_symbols(symbol_processor_predicate *pp,
                         LispObject p);

LispObject Lsymbols_in(LispObject env, LispObject a)
{   THREADID;
    LispObject *stacksave = stack;
    push_symbols(always, a);
    LispObject r = nil;
    while (stack != stacksave)
    {   LispObject w = *stack--;
        r = cons(w, r);
    }
    return onevalue(r);
}

LispObject Lbatchp(LispObject env)
{
// If the user had specified input files on the command line I will say that
// we are in batch mode even if there is a terminal present somewhere. So
// a run of the form
//     csl inputfile.lsp
// is a "batch" run, while
//     csl < inputfile.lsp
// will MAYBE also be noticed as batch, but do not count on it!
    if (non_terminal_input != nullptr)
        return onevalue(batch_flag ? nil : lisp_true);
// "sysxxx.c" now decides if we are in "batch processing" context,
// in general by asking "isatty(fileno(stdin))" to see if stdin is
// attached to an interactive terminal.  Ideally this will say we are in
// batch mode if the user has redirected input from a file, as in
//       csl < xxx.lsp
// but catching such cases may be HARD with some operating systems.
// With some operating systems we will NEVER report ourselves as "batch".
    return onevalue(Lispify_predicate(batch_flag ? !batchp() : batchp()));
}

LispObject Lgetenv(LispObject env, LispObject a)
{   char parmname[LONGEST_LEGAL_FILENAME];
    Header h;
    std::memset(parmname, 0, sizeof(parmname));
#ifdef COMMON
    if (complex_stringp(a) a = simplify_string(a);
#endif
        if (symbolp(a))
    {   a = get_pname(a);
            h = vechdr(a);
        }
        else if (!is_vector(a) || !is_string_header(h = vechdr(a)))
        return aerror1("getenv", a);
        size_t len = length_of_byteheader(h) - CELL;
                     std::memcpy(parmname, bit_cast<char *>(a) + (CELL-TAG_VECTOR),
                                 (size_t)len);
                     parmname[len] = 0;
                     const char *w = my_getenv(parmname);
                     if (w == nullptr) return onevalue(nil);    // not available
                         return onevalue(make_string(w));
        }

LispObject Lsystem(LispObject env, LispObject a)
{   char parmname[LONGEST_LEGAL_FILENAME];
    Header h;
    std::memset(parmname, 0, sizeof(parmname));
    if (a == nil)            // enquire if command processor is available
    {   int w = my_system(nullptr);
        return onevalue(Lispify_predicate(w != 0));
    }
#ifdef COMMON
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        h = vechdr(a);
    }
    else if (!is_vector(a) || !is_string_header(h = vechdr(a)))
        return aerror1("system", a);
    size_t len = length_of_byteheader(h) - CELL;
    if (len+1 > sizeof(parmname)) return aerror1("argument too long", a);
    std::memcpy(parmname, bit_cast<char *>(a) + (CELL-TAG_VECTOR),
                (size_t)len);
    parmname[len] = 0;
    ensure_screen();
    int w = my_system(parmname);
    ensure_screen();
    return onevalue(fixnum_of_int(w));
}

#ifdef WIN32
// On Windows this version takes the trouble to avoid letting the
// application that you are running pop up a visible console window.

static LispObject Lsilent_system(LispObject env, LispObject a)
{   char cmd[LONGEST_LEGAL_FILENAME];
#ifdef SHELL_EXECUTE
    char args[LONGEST_LEGAL_FILENAME];
#endif
    Header h;
    std::memset(cmd, 0, sizeof(cmd));
#ifdef SHELL_EXECUTE
    std::memset(args, 0, sizeof(args));
#endif
    if (a == nil)            // enquire if command processor is available
        return onevalue(lisp_true); // always is on Windows!
    ensure_screen();
#ifdef COMMON
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        h = vechdr(a);
    }
    else if (!is_vector(a) || !is_string_header(h = vechdr(a)))
        return aerror1("system", a);
    ensure_screen();
    size_t len = length_of_byteheader(h) - CELL;
    std::memcpy(cmd, bit_cast<char *>(a) + (CELL-TAG_VECTOR),
                (size_t)len);
    cmd[len] = 0;
#ifdef SHELL_EXECUTE
// ShellExecute works for me and allows me to launch an application with
// its console hidden - but it does not give an opportunity to wait until
// the command that was executed has completed. I will leave this code
// here for now since I may find I want to re-use it (eg for opening
// documents). But the code below that explicitly creates a process is
// what I really need here.
    size_t i = 0;
    while (cmd[i]!=' ' && cmd[i]!=0) i++;
    if (cmd[i]==0) args[0] = 0;
    else
    {   cmd[i] = 0;
        std::strcpy(args, &cmd[i+1]);
    }
    int rc = ShellExecute(nullptr,
                          "open",
                          cmd,
                          args,
                          ".",
                          SW_HIDE);
    ensure_screen();
    return onevalue(fixnum_of_int(rc));
#else
    {   STARTUPINFO startup;
        PROCESS_INFORMATION process;
        DWORD rc;
        std::memset(&startup, 0, sizeof(startup));
        startup.cb = sizeof(startup);
        startup.dwFlags = STARTF_USESHOWWINDOW;
        startup.wShowWindow = SW_HIDE;
        std::memset(&process, 0, sizeof(process));
        if (!CreateProcess(nullptr, cmd, nullptr, nullptr, FALSE,
                           CREATE_NEW_CONSOLE,
                           nullptr, nullptr, &startup, &process))
        {   return onevalue(nil);
        }
        WaitForSingleObject(process.hProcess, INFINITE);
// If I fail to retrieve a true exit code I will return the value 1000. This
// is pretty arbitrary, but I expect 0 to denote success and 1000 to be an
// unusual "genuine" return code
        if (!GetExitCodeProcess(process.hProcess, &rc)) rc = 1000;
        CloseHandle(process.hProcess);
        CloseHandle(process.hThread);
        ensure_screen();
        return onevalue(fixnum_of_int(rc));
    }
#endif
}

#else

static LispObject Lsilent_system(LispObject env, LispObject a)
{
// Other than on Windows I do not see any risk of "consoles" getting created
// when I do not want them, so this just does what the normal execution code
// does.
    return Lsystem(nil, a);
}

#endif

// This will only hash basic strings, not extended ones.

// Here I will hash the string in units of 64 bits on a 64-bit machine
// and 32-bits on a 32-bit one. I take care with the final word of data
// so that I do not assume that the string is nul-padded. Also the "string"
// passed might be the string-buffer "boffo" and in that case its header
// word indicates the buffer size and the amount of data really in play
// is just n, with no certainty that bytes beyond n are zero. So while
// I make the hash value depend on the string length I use n for that not the
// header word.

static uint64_t hash_lisp_string(LispObject s, size_t n)
{   uint64_t h = n;
// Here I will hash sizeof(intptr_t) bytes at a time.
    uintptr_t *p = bit_cast<uintptr_t *>(s-TAG_VECTOR+CELL);
    n -= CELL;
//  fprintf(stderr, "About to hash <%.*s> length %d\n", (int)n, (char *)p, (int)n);
    while (n >= sizeof(uintptr_t))
    {   // fprintf(stderr, "%" PRIx64 " ", static_cast<uint64_t>(*p));
        h = h*0x800000020001U + *p++; // The multiplier is prime but
                                      // multiply can be shift & add.
        n -= sizeof(uintptr_t);
    }
    if (n != 0) // Here I need to get rid of data from beyond the end
                // of the string.
    {   uint64_t final = *p;
        int shift = 8*(sizeof(uintptr_t) - n);
        uint64_t mask = -static_cast<uintptr_t>(1);
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        mask = mask >> shift;
#else // __ORDER__LITTLE_ENDIAN__
        mask = mask << shift;
#endif // __ORDER_LITTLE__ENDIAN__
        final &= mask;
//      fprintf(stderr, "%" PRIx64 " ", final);
        h = h*0x800000020001U + final;
    }
// The calculation thus far will have tended to concentrate entropy in the
// high bits of h, so I will distribute them just a bit better.
    h -= (h >> 37);
    h *= 141592653589U; // A rather arbitrary prime
    h -= (h >> 31);
//  fprintf(stderr, " => %" PRIx64 "\n", h);
    return h;
}

uint64_t hash_lisp_string(LispObject s)
// Argument is a (lisp) string.  Return a 64 bit hash value.
{   return hash_lisp_string(s, length_of_byteheader(vechdr(s)));
}

static int value_in_radix(int c, int radix)
{   if (c < 0 || c > 0xff) return -1;
    if (std::isdigit(c)) c = c - '0'; // Assumes digit codes are consecutive
    else if (std::isalpha(c)) c = std::tolower(c) - 'a' + 10;
    else return -1;
    if (c < radix) return c;
    else return -1;
}

LispObject intern(size_t len, bool escaped, int startAddr)
// This takes whatever is in the first len characters of
// the Lisp string boffo, and maps it into a number, string
// or symbol as relevant.
{   size_t i;
    int numberp = escaped ? -1 : 0;
    int fplength = 2;
    bool explicit_fp_format = false;
    THREADID;
#ifdef NO_THREADS
    stackcheck();
#else // NO_THREADS
    stackcheck(threadId);
#endif // NO_THREADS
    for (i=startAddr; i<len; i++)
    {   int c = boffo_char(i);
        switch (numberp)
        {   default:
                break;
            case 0:
                if (c == '+' || c == '-')
                {   numberp = 1;
                    continue;
                }
            // drop through
            case 1:
                if (c == '.')
                {   numberp = 6;
                    continue;
                }
// only basic characters can possibly be digits
                if (c <= 0xff && std::isdigit(c)) // Inspect *read-base* ?
                {   numberp = 2;
                    continue;
                }
                numberp = -1;
                break;
            case 2:
                if (c <= 0xff && std::isdigit(c)) continue;   // *read-base*
                switch (c)
                {   case '/':   numberp = 3;    continue;
                    case '.':   numberp = 5;    continue;
                    case 'e': case 'E':
// I now allow various exponent signifiers as per Common Lisp:
//   1.23e34    default (which is usually double)
//   1.23s34    short float - 28 bits
//   1.23f34    single float - 32 bits
//   1.23d34    double float - 64 bits
//   1.23l34    long float - 128 bits
                        numberp = 9;
                        continue;
                    case 's': case 'S':
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        fplength = 0;
                        numberp = 9;
                        continue;
                    case 'f': case 'F':
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        fplength = 1;
                        numberp = 9;
                        continue;
                    case 'd': case 'D':
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        numberp = 9;
                        continue;
                    case 'l': case 'L':
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        fplength = 3;
                        numberp = 9;
                        continue;
                    default:
                        numberp = -1;
                        break;
                }
                break;
            case 3:
            case 4:
                if (c <= 0xff && std::isdigit(c))   // *read-base*
                {   numberp = 4;
                    continue;
                }
                numberp = -1;
                break;
            case 5:
            case 8:
                if (c <= 0xff && std::isdigit(c))
                {   numberp = 8;
                    continue;
                }
                switch (c)
                {   case 'e': case 'E':
                        numberp = 9;
                        continue;
                    case 's': case 'S':
// Clobbering the string is a DISASTER if it is not in fact numeric
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        fplength = 0;
                        numberp = 9;
                        continue;
                    case 'f': case 'F':
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        fplength = 1;
                        numberp = 9;
                        continue;
                    case 'd': case 'D':
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        numberp = 9;
                        continue;
                    case 'l': case 'L':
                        boffo_char(i) = 'e';
                        explicit_fp_format = true;
                        fplength = 3;
                        numberp = 9;
                        continue;
                    default:
                        numberp = -1;
                        break;
                }
                break;
            case 6:
                if (c <= 0xff && std::isdigit(c))
                {   numberp = 8;
                    continue;
                }
                numberp = -1;
                break;
            case 9:
                if (c == '+' || c == '-')
                {   numberp = 10;
                    continue;
                }
            // Drop through
            case 10:
            case 11:
                if (c <= 0xff && std::isdigit(c))
                {   numberp = 11;
                    continue;
                }
                numberp = -1;
                break;
        }
        break;
    }
// Here the item has been scanned, and it is known if it is numeric!
    switch (numberp)
    {   default:
// Not a number... look up in package system
#ifdef COMMON
            if (!escaped && boffo_char(0) == ':')
            {   size_t i = 0;
                for (i = 0; i<boffop; i++)
                    boffo_char(i) = static_cast<char>(boffo_char(i+1));
                boffop--;
                return iintern(boffo, boffop, qvalue(keyword_package), 0);
            }
#endif
            return iintern(boffo, boffop, CP, 0);


        case 5:         // Integer written as 12345.    (note trailing ".")
            boffo_char(--boffop) = 0; // ... trim off the trailing dot
        // drop through
        case 2:
// I speed up reading by working 7 digits at a time (using C integer
// arithmetic to gobble them) and only resorting to Lisp generic
// arithmetic to combine the chunks.
            if (boffo_char(0) == '+')
            {   for (size_t i = 0; i<boffop; i++)
                    boffo_char(i) = static_cast<char>(boffo_char(i+1));
                boffop--;
            }
            {   LispObject v = fixnum_of_int(0);
                bool sign = false;
                int32_t d = 0, d1 = 10;
                for (i=0; i<boffop; i++)
                {   if (i==0 && boffo_char(i) == '-') sign = true;
                    else if (d1 == 10000000 || i == boffop-1)
                    {   d = 10*d + (int32_t)value_in_radix(boffo_char(i), 10);
                        v = times2(v, fixnum_of_int(d1));
                        v = plus2(v, fixnum_of_int(d));
                        d = 0;
                        d1 = 10;
                    }
                    else
                    {   d = 10*d + (int32_t)value_in_radix(boffo_char(i), 10);
                        d1 = 10*d1;
                    }
                }
                if (sign) v = negate(v);
                return v;
            }

        case 4:
        {   int p, q, g;
            LispObject r;
// Beware bignum issue here... but take view that ratios are not used!
// I think I am expressing concern that a this ONLY deals with rational
// number input where both numerator and denominator are small enough to
// end up as fixnums, and it does not check for overflow. Thus 22/7 will
// be OK but 12345678987654321/3 will not. This is laziness I guess and
// some time ideally I would come and fix this so it uses the same
// strategy as used for bignums to read ratios with big numerators and/or
// denominators.
            boffo_char(boffop) = 0;
// p and q were made int not int32_t to match up with the %d in scanf ...
            std::sscanf(bit_cast<char *>(&boffo_char(0)), "%d/%d", &p,
                        &q);
// Limit myself to fixnums here
            g = static_cast<int>(int_of_fixnum(gcd(fixnum_of_int((int32_t)p),
                                                   fixnum_of_int((int32_t)q))));
            p /= g;
            q /= g;
            if (q < 0)
            {   p = -p;
                q = -q;
            }
            r = get_basic_vector(TAG_NUMBERS, TYPE_RATNUM,
                                 sizeof(Rational_Number));
            setnumerator(r, fixnum_of_int((int32_t)p));
            setdenominator(r, fixnum_of_int((int32_t)q));
            return r;
        }
        case 8:
        case 11:
        {
// I want to enable this all the time, but if I am not in COMMON mode
// then before I do I need to get read_float_format set up properly.
#ifdef COMMON
            if (!explicit_fp_format && is_symbol(read_float_format))
            {   LispObject w = qvalue(read_float_format);
                if (w == short_float) fplength = 0;
                else if (w == single_float) fplength = 1;
                else if (w == double_float) fplength = 2;
                else if (w == long_float) fplength = 3;
            }
#else
            static_cast<void>(explicit_fp_format);
#endif
            boffo_char(boffop) = 0;
            switch (fplength)
            {   case 0:
                    return pack_short_float(
                        std::atof(bit_cast<char *>(&boffo_char(0))));
                case 1:
                    return pack_single_float(
                        std::atof(bit_cast<char *>(&boffo_char(0))));
                default:
                case 2:
                    return make_boxfloat(
                        std::atof(bit_cast<char *>(&boffo_char(0))),
                        TYPE_DOUBLE_FLOAT);
#ifdef HAVE_SOFTFLOAT
                case 3:
                    return make_boxfloat128(atof128(
                        bit_cast<char *>(&boffo_char(0))));
#endif // HAVE_SOFTFLOAT
            }
        }
    }
}

LispObject intern_hex_old(size_t len)
{   size_t i;
    LispObject v = fixnum_of_int(0);
    int32_t d = 0, d1 = 16;
    for (i=2; i<boffop; i++)
    {   if (d1 == 0x1000000 || i == boffop-1)
        {   d = 16*d + (int32_t)value_in_radix(boffo_char(i), 16);
            v = times2(v, fixnum_of_int(d1));
            v = plus2(v, fixnum_of_int(d));
            d = 0;
            d1 = 16;
        }
        else
        {   d = 16*d + (int32_t)value_in_radix(boffo_char(i), 16);
            d1 = 16*d1;
        }
    }
    return v;
}

#ifdef ARITHLIB

#include "dispatch.h"

LispObject intern_new(size_t len)
{   size_t i;
    LispObject v = fixnum_of_int(0);
    int32_t d = 0, d1 = 10;
    for (i=0; i<boffop; i++)
    {   if (d1 == 10000000 || i == boffop-1)
        {   d = 10*d + (int32_t)value_in_radix(boffo_char(i), 10);
            v = Times::op(v, fixnum_of_int(d1));
            v = Plus::op(v, fixnum_of_int(d));
            d = 0;
            d1 = 10;
        }
        else
        {   d = 10*d + (int32_t)value_in_radix(boffo_char(i), 10);
            d1 = 10*d1;
        }
    }
    return v;
}

LispObject intern_hex_new(size_t len)
{   size_t i;
    LispObject v = fixnum_of_int(0);
    int32_t d = 0, d1 = 16;
    for (i=2; i<boffop; i++)
    {   if (d1 == 0x1000000 || i == boffop-1)
        {   d = 16*d + (int32_t)value_in_radix(boffo_char(i), 16);
            v = Times::op(v, fixnum_of_int(d1));
            v = Plus::op(v, fixnum_of_int(d));
            d = 0;
            d1 = 16;
        }
        else
        {   d = 16*d + (int32_t)value_in_radix(boffo_char(i), 16);
            d1 = 16*d1;
        }
    }
    return v;
}

#endif // ARITHLIB

LispObject make_undefined_symbol(char const *s)
{   return make_symbol(s, 0, undefined_0, undefined_1, undefined_2,
                       undefined_3, undefined_4up);
}

LispObject make_symbol(char const *s, int restartp,
                       no_args *f0, one_arg *f1, two_args *f2,
                       three_args *f3, fourup_args *f4up)
// Used from the startup code to create an interned symbol and (maybe)
// put something in its function cell.
{   LispObject v;
// Here I blandly assume that boffo is long enough to hold the string
// that I am about to copy into it.  All is guaranteed well for
// symbols predefined in Lisp in the normal way, but ones established
// using command-line options like -Dname could cause trouble?
#ifdef DEBUG
    if (!valid_address((void *)s))
    {   my_abort("s is not a valid address");
    }
    if (!valid_address((void *)&boffo_char(0)))
    {   my_abort("boffo is not a valid address");
    }
    if (std::strlen(s) > 200)
    {   my_abort("over-long string");
    }
#endif // DEBUG
#ifdef COMMON
// For COMMON Lisp I will make all the built-in symbols upper case, unless
// the "2" bit of restartp is set...
    char const *p1 = s;
    char *p2 = bit_cast<char *>(&boffo_char(0));
    int c;
    if ((restartp & 2) == 0)
    {   while ((c = *p1++) != 0)
        {   c = std::toupper(c);
            *p2++ = c;
        }
        *p2 = 0;
    }
    else
#endif
        std::strcpy(bit_cast<char *>(&boffo_char(0)), s);
    size_t len = std::strlen(bit_cast<char *>(&boffo_char(0)));
    if (len == 0) len = 1; // Special case so I can create symbol for U+00
    v = iintern(boffo, len, CP, 0);
// I instate the definition given if (a) the definition is a real
// one (ie not for an undefined function) and if (b) either I am doing a cold
// start or if I gave first_try false which is when I am going round
// again and doing rather curious things...
    if (f1 != undefined_1)
    {   if ((restartp & 1)==0)
        {   qfn0(v) = f0;
            qfn1(v) = f1;
            qfn2(v) = f2;
            qfn3(v) = f3;
            qfn4up(v) = f4up;
        }
// All things that have been set up as copies of this symbol must be
// initialised with the definition too. This happens even if the original
// symbol has been redefined and is not longer nice C code...
        if ((restartp & 1) != 0)
        {   LispObject v1 = get(v, work_symbol, nil);
            while (consp(v1))
            {   LispObject w = car(v1);
                v1 = cdr(v1);
                qfn0(w) = f0;
                qfn1(w) = f1;
                qfn2(w) = f2;
                qfn3(w) = f3;
                qfn4up(w) = f4up;
            }
        }
    }
    return v;
}

static bool add_to_hash(LispObject s, LispObject vector, uint64_t hash)
// Adds an item into a hash table given that it is known that it is not
// already there.
{   size_t size = cells_in_vector(vector);
    size_t i = (size_t)(hash % size);
// I have arranged (elsewhere) that the hash table size will be prime
// so I can avoid primary clustering by stepping on by almost any
// number.
    size_t step = 1 + ((hash >> 10)%(size-1));
    size_t probes = 0;
// When I *know* I am inserting in a table I do not need to do any
// key comparisons - I just scan until I find an empty slot in the table.
    while (++probes <= size)
    {   if (is_fixnum(elt(vector, i)))
        {   elt(vector, i) = s;
            return true;                 // Success
        }
        i = i + step;
        if (i >= size) i -= size;
    }
    return false;                          // Table is totally full
}

// cslread.h and through that isprime.h provide a way of identifying
// primes that are just below powers of 2, and I use those as the size
// for my table.

static LispObject rehash(LispObject v, int grow)
{
// If (grow) is +1 this enlarges the table. If -1 it shrinks it. In the
// case that the table is to shrink I should guarantee that the next smaller
// table size down will have enough space for the number of active items
// present. grow=0 leaves the table size alone but still rehashes.
    size_t h = cells_in_vector(v);
    if (grow > 0 && h < MAX_OBVEC_SIZE) h = nextGoodPrime(h);
    else if (grow < 0 && h > INITIAL_OBVEC_SIZE) h = previousGoodPrime(h);
    THREADID;
    stackcheck(THREADARG v);
    STACK_SANITY;
    LispObject new_obvec;
    {   Save save(THREADARG v);
        new_obvec = get_vector_init((h+1)*CELL, fixnum_of_int(0));
        errexit();
        save.restore(v);
    }
    h = cells_in_vector(v);
    while (h != 0)
    {   h--;
        LispObject s = elt(v, h);
        if (is_fixnum(s)) continue;
        LispObject p = qpname(s);
        validate_string(p);
        uint64_t hash = hash_lisp_string(p);
        add_to_hash(s, new_obvec, hash);
    }
    return new_obvec;
}

#ifdef COMMON

static LispObject add_to_externals(LispObject s, LispObject p, uint64_t hash)
{   LispObject n = packnext_(p);
    LispObject v = packext_(p);
    size_t used = cells_in_vector(v);
// I trigger a re-hash if the table reaches 50% loading.  Then I (approx)
// double its size. The effect is that it will remain between 25 and 50%
// full - really rather lightly loaded.
    if (static_cast<size_t>(2*int_of_fixnum(n)) > used)
    {   THREADID;
        stackcheck(THREADARG s, p);
        Save save(THREADARG s, p);
        v = rehash(v, 1);
// Hmm - if rehash fails then I might be in a real mess!
        errexit();
        save.restore(s, p);
        packext_(p) = v;
    }
    packnext_(p) = n + (1<<4);      // increment as a Lisp fixnum
    add_to_hash(s, v, hash);
    return nil;
}

#endif

static LispObject add_to_internals(LispObject s, LispObject p, uint64_t hash)
{   LispObject n = packnint_(p);
    LispObject v = packint_(p);
    size_t used = cells_in_vector(v);
    THREADID;
    if (static_cast<size_t>(2*int_of_fixnum(n)) > used)
    {   stackcheck(THREADARG s, p, v);
        Save save(THREADARG s, p);
        v = rehash(v, 1);
        errexit();
        save.restore(s, p);
        packint_(p) = v;
    }
    packnint_(p) = n + (1<<4);
#ifdef DEBUG
    if ((size_t)int_of_fixnum(packnint_(p)) > fullest_package)
        fullest_package = int_of_fixnum(packnint_(p));
#endif
    // increment as a Lisp fixnum
    add_to_hash(s, v, hash);
    return nil;
}

static bool rehash_pending = false;

#ifdef HASH_STATISTICS
uint64_t Nhget=0, Nhgetp=0, Nhput1=0, Nhputp1=0, Nhput2=0, Nhputp2=0,
         Nhputtmp=0;
uint64_t Noget=0, Nogetp=0, Noput=0, Noputp=0, Noputtmp=0;
#endif

static LispObject lookup(LispObject str, size_t strsize,
                         LispObject v, uint64_t hash)
// Searches a hash table for a symbol with name matching the given string,
// and NOTE that the string passed down here is to be treated as having
// just strsize characters in it.  Return Lisp number 0 if not found.
// Sets rehash_pending if the number of probes used to find the item is
// at least half the size of the table. This case might arise in the following
// way:
//    insert items into the table until it is just under 70% full.
//    remob (eg via EXPORT) items until the table is just over 25% full.
// note that so far there will have been no need to rehash
//    insert more items, but select them so that their hash values are all
//    different from the ones used before. You should be able to end up
//    with 70% of the table full of valid symbols and 30% left as the value
//    fixnum_of_int(1) which represents a place where a deleted symbol used
//    to be. There is now false really empty space.
// Now looking up symbols must keep searching past tombstones, and hence
// here it will be necessary to scan the entire table before it is
// possible to assert that a symbol is not present. Inserting new symbols
// does not suffer in this way - only lookup.  To help with this horror I set
// rehash_pending if the lookup uses a number of probes > 75% of the table
// size. This should only arise in degenerate cases!
//
// January 2015: I now believe I can use a scheme hashing scheme that will
// behave much better than the one that I originally used.
// Firstly because of the misery that in CSL there is an upper limit
// on the size of vectors I still need to support segmented tables. Also
// note that the code here is quite separate from that in fns3.c where
// hash tables for direct use by users are iplemented. I ought to consolidate
// these two implementations of hashing!
{
#ifdef HASH_STATISTICS
    Noputtmp = 0;
#endif
    size_t size = cells_in_vector(v);
    size_t i = (size_t)(hash%size);
    size_t step = 1 + ((hash >> 10)%(size-1));
// I count the probes that I make here and if there are as many as the size
// of the hash table then I allow the lookup to report that the symbol is not
// present. But at least I do not get stuck in a loop.
    for (size_t n=0; n<size; n++)
    {   LispObject w = elt(v, i);
        LispObject pn;
        if (w == fixnum_of_int(0))
        {   if (4*n > 3*size) rehash_pending = true;
            return w;  // Not found
        }
        if (w != fixnum_of_int(1))
        {   pn = qpname(w);
            validate_string(pn);
// v comes out of a package so has a proper pname
#ifdef HASH_STATISTICS
            Noputtmp++;  // A probe...
#endif
            if (std::memcmp(bit_cast<char *>(str) + (CELL-TAG_VECTOR),
                            bit_cast<char *>(pn) + (CELL-TAG_VECTOR),
                            (size_t)strsize) == 0 &&
                length_of_byteheader(vechdr(pn)) == (size_t)strsize+CELL)
            {   if (4*n > 3*size) rehash_pending = true;
#ifdef HASH_STATISTICS
// If the symbol was already present I count up in (Noget, Nogetp)
                Noget++;
                Nogetp += Noputtmp;
#endif
                return w;
            }
        }
        i = i + step;
        if (i >= size) i -= size;
    }
    rehash_pending = true;
    return fixnum_of_int(0);
}

static int ordersymbol(LispObject v1, LispObject v2)
// Compare two symbols to see if they are in alphabetic order.
// Returns 0 is the symbols have the same name, otherwise
// the comparison is a lexical one on their names, with -ve if
// v1 comes alphabetically before v2.  Deals with gensyms, and in so
// doing has to allocate names for them, which seems a great misery
// since it means that this procedure can provoke garbage collection..
// Note that the ordering here is based on the bit-patterns that
// represent the names, and so will be driven by the utf-8 encoding of
// multibyte characters. I have not put in any adjustments that might
// make it match the expected lexical orderings in various locale-sensitive
// scenarios.
{   LispObject pn1 = qpname(v1), pn2 = qpname(v2);
    int c;
    size_t l1, l2;
#ifndef COMMON
    if (qheader(v1) & SYM_UNPRINTED_GENSYM)
    {   THREADID;
        Save save(THREADARG v2);
        pn1 = get_pname(v1);
        errexit();
        save.restore(v2);
        pn2 = qpname(v2);
    }
    if (qheader(v2) & SYM_UNPRINTED_GENSYM)
    {   THREADID;
        Save save(THREADARG pn1);
        pn2 = get_pname(v2);
        errexit();
        save.restore(pn1);
    }
#endif
    validate_string(pn1);
    validate_string(pn2);
    l1 = length_of_byteheader(vechdr(pn1)) - CELL;
    l2 = length_of_byteheader(vechdr(pn2)) - CELL;
    c = std::memcmp(bit_cast<char *>(pn1) + (CELL-TAG_VECTOR),
                    bit_cast<char *>(pn2) + (CELL-TAG_VECTOR),
                    (size_t)(l1 < l2 ? l1 : l2));
    if (c == 0) c = static_cast<int>(l1 - l2);
    return c;
}

// This has been coded so that it provides the behavious that Reduce expects
// of ordp().  This is the REDUCE 3.6/3.7 version - it will need re-work
// if REDUCE is altered.  Note the curious situation that symbols are
// alphabetically ordered, EXCEPT that "nil" comes before everything else!
//
//  symbolic procedure ordp(u,v);
//     if null u then null v
//      else if null v then t
//      else if vectorp u then if vectorp v then ordpv(u,v) else atom v
//      else if atom u
//       then if atom v
//              then if numberp u then numberp v and not (u<v)
//                    else if idp v then orderp(u,v)
//                    else numberp v
//             else nil
//      else if atom v then t
//      else if car u=car v then ordpl(cdr u, cdr v)                          *** 8 Feb 1999
//      else if flagp(car u,'noncom)
//       then if flagp(car v,'noncom) then ordp(car u,car v) else t
//      else if flagp(car v,'noncom) then nil
//      else ordp(car u,car v);
//
//  symbolic procedure ordpl(u,v)
//     if atom u then ordp(u,v)
//      else if atom v then t
//      else if car u=car v then ordpl(cdr u,cdr v)
//      else ordp(car u, car v);
//

static int orderp(LispObject u, LispObject v);

static int ordpv(LispObject u, LispObject v)
{   Header hu = vechdr(u), hv = vechdr(v);
    size_t lu = length_of_header(hu), lv = length_of_header(hv), n = CELL;
    if (type_of_header(hu) != type_of_header(hv))
        return (type_of_header(hu) < type_of_header(hv) ? -1 : 1);
    if (vector_header_of_binary(hu))
    {
// STRING, VEC8 and BPS need length_of_byteheader used here.
        switch (type_of_header(hu))
        {   case TYPE_STRING_1:
            case TYPE_STRING_2:
            case TYPE_STRING_3:
            case TYPE_STRING_4:
            case TYPE_VEC8_1:
            case TYPE_VEC8_2:
            case TYPE_VEC8_3:
            case TYPE_VEC8_4:
            case TYPE_BPS_1:
            case TYPE_BPS_2:
            case TYPE_BPS_3:
            case TYPE_BPS_4:
                lu = length_of_byteheader(hu);
                lv = length_of_byteheader(hv);
                break;
// Bitvectors are pending for now!
            default:
                break;
        }
        while (n < lu && n < lv)
        {   unsigned int eu = *bit_cast<unsigned char *>
                              (u - TAG_VECTOR + n),
                              ev = *bit_cast<unsigned char *>(v - TAG_VECTOR + n);
            if (eu != ev) return (eu < ev ? -1 : 1);
            n += 1;
        }
        return (lu == lv ? 0 : lu < lv ? -1 : 1);
    }
// At present it is an ERROR to include mixed vectors in structures passed
// to ordering functions, and if it is done the system may crash.  Note that
// stream objects count as mixed for these purposes. I will get around to
// fixing things sometime...
    else
    {   THREADID;
        while (n < lu && n < lv)
        {   LispObject eu = *bit_cast<LispObject *>
                            (u - TAG_VECTOR + n),
                            ev = *bit_cast<LispObject *>(v - TAG_VECTOR + n);
            int w;
            Save save(THREADARG u, v);
            if (bit_cast<uintptr_t>(stack) >= stackLimit)
                respond_to_stack_event();
            w = orderp(eu, ev);
            errexit();
            save.restore(u, v);
            if (w != 0) return w;
            n += CELL;
        }
        return (lu == lv ? 0 : lu < lv ? -1 : 1);
    }
}

static int ordpl(LispObject u, LispObject v)
{   for (;;)
    {   int w = orderp(car(u), car(v));
        if (w != 0) return w;
        u = cdr(u);
        v = cdr(v);
        if (!consp(u)) return orderp(u, v);
        if (!consp(v)) return -1;
    }
}

bool flagged_noncom(LispObject v)
{   LispObject fv = qfastgets(v);
    return fv != nil &&
           static_cast<LispObject>(elt(fv, 0)) != SPID_NOPROP;
}

static int orderp(LispObject u, LispObject v)
{   for (;;)
    {   if (u == nil) return v == nil ? 0 : 1;
        else if (v == nil) return -1;       // Special cases of NIL done
        else if (u == v) return 0;          // useful optimisation?
// I migrate the vectorp test inside where I have tested for atoms, since
// I expect vectors to be a somewhat uncommon case
        else if (!consp(u))
        {   if (!consp(v))
            {   if (is_vector(u))
                {   if (is_vector(v)) return ordpv(u, v);
                    else return -1;
                }
                else if (is_number(u))
                {   if (is_number(v)) return lessp2(u, v) ? 1 :
                                                 eql(u, v) ? 0 : -1;
                    else return 1;
                }
                else if (is_number(v)) return -1;
                else if (is_symbol(u))
                {   if (is_symbol(v)) return ordersymbol(u, v);
                    else return 1;
                }
                else if (is_symbol(v)) return -1;
// Now the objects are not symbols, vectors or numbers.  That maybe
// leaves character objects.  I compare representations to give a
// rather arbitrary ordering. Note that any comparisons that get
// down here are yielding non portable results.
                else return (u == v) ? 0 : (u < v) ? 1 : -1;
            }
            else return 1;
        }
        else if (!consp(v)) return -1;
        else
        {   LispObject cu = car(u), cv = car(v);
            int w;
            THREADID;
            Save save(THREADARG u, v);
//          stackcheck(threadId);
            if (bit_cast<uintptr_t>(stack) >= stackLimit)
                respond_to_stack_event();
            w = orderp(cu, cv);
            errexit();
            save.restore(u, v);
            if (w != 0)
            {   cu = car(u);
                if (is_symbol(cu) && flagged_noncom(cu))
                {   cv = car(v);
                    if (is_symbol(cv) && flagged_noncom(cv)) return w;
                    else return -1;
                }
                else
                {   cv = car(v);
                    if (is_symbol(cv) && flagged_noncom(cv)) return 1;
                    else return w;
                }
            }
// here car u = car v
            u = cdr(u);
            v = cdr(v);
            if (!consp(u)) continue;
            if (!consp(v)) return -1;
// The function I call ordpl here has the atom tests lifted out from
// its top...
            return ordpl(u, v);
        }
    }
}

LispObject Lorderp(LispObject env, LispObject a, LispObject b)
{   int w = orderp(a, b);
    return onevalue(Lispify_predicate(w <= 0));
}

static uint64_t removed_hash;

static bool remob(LispObject sym, LispObject v)
// Searches a hash table for a symbol with name matching the given string,
// and remove it from the package-hashtable v.
{   if (qheader(sym) & SYM_ANY_GENSYM ||
        qpackage(sym) == nil) return false; // gensym case is easy!
    setpackage(sym, nil);
    LispObject str = qpname(sym);
    validate_string(str);
#ifdef COMMON
// If not in any package it has no home & is not available
    qheader(sym) &= ~SYM_EXTERN_IN_HOME & ~(0xffffffff<<SYM_IN_PKG_SHIFT);
#endif
    uint64_t hash = removed_hash = hash_lisp_string(str);
// The search procedure used here MUST match that coded in lookup().
    size_t size = cells_in_vector(v);
    size_t i = hash & (size - 1);
    size_t step = 1 | ((hash >> 10) & (size - 1));
    for (size_t n=0; n<size; n++)
    {   LispObject w = elt(v, i);
        if (w == fixnum_of_int(0)) return false;  // Not found
        if (w == sym)
        {   elt(v, i) = fixnum_of_int(1);
            return true;
        }
        i = i + step;
        if (i >= size) i -= size;
    }
    return false;
}

static LispObject Lmake_symbol(LispObject env, LispObject str)
// Lisp function (make-symbol ..) creates an uninterned symbol.
{   THREADID;
    stackcheck(THREADARG str);
// Common Lisp wants a STRING passed here, but as a matter of generosity and
// for the benefit of some of my system code I support symbols too.
    if (symbolp(str)) str = get_pname(str);
    else if (!is_vector(str)) return aerror1("make-symbol", str);
    else if (complex_stringp(str)) str = simplify_string(str);
    else if (!is_string_header(vechdr(str))) return aerror1("make-symbol", str);
    LispObject s;
    {   Save save(THREADARG str);
        s = get_symbol(false);
        errexit();
        save.restore(str);
    }
    setheader(s, TAG_HDR_IMMED+TYPE_SYMBOL);
    setvalue(s, unset_var);
    if (is_vector(str)) validate_string(str);
    setpname(s, str);
    setplist(s, nil);
    setfastgets(s, nil);
    setpackage(s, nil);
    setenv(s, s);
    qfn0(s) = undefined_0;
    qfn1(s) = undefined_1;
    qfn2(s) = undefined_2;
    qfn3(s) = undefined_3;
    qfn4up(s) = undefined_4up;
// If a symbol is created uninterned it will not have a serial number to
// start with. If somebody calls id2int on it I will allocate a serial
// number. If then it gets interned then that number ought to persist, and
// if a regular symbol is remob'd its serial number should persist.
// I will view having the low 22 bits of qcountLow all zero and not being
// the item char_0_symbol as the mark of something that has not yet been
// allocated a sequence number.
    qcountLow(s) = 0;
    qcountHigh(s) = 0;
    return onevalue(s);
}

LispObject Lgensym(LispObject env)
// Lisp function (gensym) creates an uninterned symbol with odd name.
{
#ifdef COMMON
    LispObject pn;
    char genname[64];
#endif
    THREADID;
    stackcheck(THREADARG env);
#ifdef COMMON
    std::sprintf(genname, "G%lu", (long unsigned)(uint32_t)gensym_ser++);
    pn = make_string(genname);
    errexit();
    Save save(THREADARG pn);
#endif
    LispObject id = get_symbol(true);
#ifdef COMMON
    save.restore(pn);
#endif
#ifdef COMMON
    setheader(id, TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM);
    setpname(id, pn);
#else
    setheader(id, TAG_HDR_IMMED+TYPE_SYMBOL+SYM_UNPRINTED_GENSYM
              +SYM_ANY_GENSYM);
    setpname(id, gensym_base);
#endif
    setvalue(id, unset_var);
    setplist(id, nil);
    setfastgets(id, nil);
    setpackage(id, nil); // Marks it as a uninterned
    setenv(id, id);
    qfn0(id) = undefined_0;
    qfn1(id) = undefined_1;
    qfn2(id) = undefined_2;
    qfn3(id) = undefined_3;
    qfn4up(id) = undefined_4up;
    qcountLow(id) = 0;
    qcountHigh(id) = 0;
    return onevalue(id);
}

LispObject Lgensym0(LispObject env, LispObject a, const char *suffix)
{   LispObject genbase;
    size_t len, len1 = std::strlen(suffix);
    char genname[64];
#ifdef COMMON
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (is_vector(a) &&is_string_header(vechdr(a))) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);  // copy gensym base
    else return aerror1("gensym0", a);
    THREADID;
    STACK_SANITY;
    stackcheck(THREADARG env);
    errexit();
    len = length_of_byteheader(vechdr(genbase)) - CELL;
    if (len > 63-len1) len = 63-len1; // Unpublished truncation of the string
    std::sprintf(genname, "%.*s%s", static_cast<int>(len),
        bit_cast<char *>(genbase) + (CELL-TAG_VECTOR), suffix);
    genbase = make_string(genname);
    errexit();
    LispObject id;
    {   Save save(THREADARG genbase);
        id = get_symbol(true);
        errexit();
        save.restore(genbase);
    }
#ifdef COMMON
    setheader(id, TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM);
#else
    setheader(id, TAG_HDR_IMMED+TYPE_SYMBOL+
                  SYM_UNPRINTED_GENSYM+SYM_ANY_GENSYM);
#endif
    setvalue(id, unset_var);
    setpname(id, genbase);
    setplist(id, nil);
    setfastgets(id, nil);
    setpackage(id, nil); // Marks it as a uninterned
    setenv(id, id);
    qfn0(id) = undefined_0;
    qfn1(id) = undefined_1;
    qfn2(id) = undefined_2;
    qfn3(id) = undefined_3;
    qfn4up(id) = undefined_4up;
    qcountLow(id) = 0;
    qcountHigh(id) = 0;
    return onevalue(id);
}

LispObject Lgensym(LispObject env, LispObject a)
// Lisp function (gensym1 base) creates an uninterned symbol with odd name.
// The case (gensym <number>) is DEPRECATED by the Common Lisp standards
// committee and so I will not implement it at least for now.
{   LispObject genbase;
#ifdef COMMON
    size_t len;
    char genname[64];
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (is_vector(a) &&is_string_header(vechdr(a))) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);  // copy gensym base
    else return aerror1("gensym1", a);
    THREADID;
    STACK_SANITY;
    stackcheck(THREADARG env);
    errexit();
#ifdef COMMON
    len = length_of_byteheader(vechdr(genbase)) - CELL;
    if (len > 60) len = 60;     // Unpublished truncation of the string
    std::sprintf(genname, "%.*s%lu", static_cast<int>(len),
                 bit_cast<char *>(genbase) + (CELL-TAG_VECTOR),
                 (long unsigned)(uint32_t)gensym_ser++);
    genbase = make_string(genname);
#endif
    LispObject id;
    {   Save save(THREADARG genbase);
        id = get_symbol(true);
        errexit();
        save.restore(genbase);
    }
#ifdef COMMON
    setheader(id, TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM);
#else
    setheader(id, TAG_HDR_IMMED+TYPE_SYMBOL+
                  SYM_UNPRINTED_GENSYM+SYM_ANY_GENSYM);
#endif
    setvalue(id, unset_var);
    setpname(id, genbase);
    setplist(id, nil);
    setfastgets(id, nil);
    setpackage(id, nil); // Marks it as a uninterned
    setenv(id, id);
    qfn0(id) = undefined_0;
    qfn1(id) = undefined_1;
    qfn2(id) = undefined_2;
    qfn3(id) = undefined_3;
    qfn4up(id) = undefined_4up;
    qcountLow(id) = 0;
    qcountHigh(id) = 0;
    return onevalue(id);
}

LispObject Lgensym1(LispObject env, LispObject a)
{   return Lgensym(env, a);
}

LispObject Lgensym2(LispObject env, LispObject a)
// Lisp function (gensym2 base) whose name is exactly that given by the
// argument.  This might be UNHELPFUL if one tried to print the value
// concerned, but seems to be what the Common Lisp syntax #:ggg expects
// to achieve!
{   LispObject genbase;
    size_t len;
#ifdef COMMON
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (is_vector(a) &&is_string_header(vechdr(a))) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);
    else return aerror1("gensym2", a);
    THREADID;
    STACK_SANITY;
    stackcheck(THREADARG env);
    len = length_of_byteheader(vechdr(genbase)) - CELL;
    genbase = copy_string(genbase, len);
    errexit();
    LispObject id;
    {   Save save(THREADARG genbase);
        id  = get_symbol(true);
        errexit();
        save.restore(genbase);
    }
    setheader(id, TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM);
    setvalue(id, unset_var);
    setpname(id, genbase);
    setplist(id, nil);
    setfastgets(id, nil);
    setpackage(id, nil); // Marks it as a uninterned
    setenv(id, id);
    qfn0(id) = undefined_0;
    qfn1(id) = undefined_1;
    qfn2(id) = undefined_2;
    qfn3(id) = undefined_3;
    qfn4up(id) = undefined_4up;
    qcountLow(id) = 0;
    qcountHigh(id) = 0;
    return onevalue(id);
}

static LispObject Lgensymp(LispObject env, LispObject a)
{   if (is_symbol(a) &&
        (qheader(a) & SYM_CODEPTR) == 0 &&
        (qheader(a) & SYM_ANY_GENSYM) != 0) return onevalue(lisp_true);
    else return onevalue(nil);
}

// Normally gensyms are displayed as G0, G1, ... in sequence.
// After (reset!=gensym 1234) thet go on from G1234.
// The function returns the previous gensym counter. So (reset!-gensym nil)
// will read that but not reset the sequence.

static LispObject Lreset_gensym(LispObject env, LispObject a)
{   LispObject old = gensym_ser;
    if (is_fixnum(a) &&
        a >= 0) gensym_ser = int_of_fixnum(a) & 0x7fffffff;
    return fixnum_of_int(old);
}

uint32_t symbol_sequence = 0;

LispObject iintern(LispObject str, size_t h, LispObject p, int str_is_ok)
// Look up the first h chars of the string str with respect to the package p.
// The last arg is a boolean that allows me to decide if (when a new symbol
// has to be created) the string must be copied.  If h differs from the
// real number of characters in arg1 then a copy MUST be made.
// If non-zero, the last arg is 1 for intern, 2 for extern, 3
// for find-symbol and 4 for "find-external-symbol" as in reader syntax p:x.
// NB in CSL mode only one value is returned.
{   LispObject r;
    THREADID;
    stackcheck(THREADARG str, p);
    uint64_t hash = hash_lisp_string(str, h+CELL);
// find-external-symbol will not look at the internals
    if (str_is_ok != 4)
    {   r = lookup(str, h, packint_(p), hash);
// rehash_pending is intended to deal with horrible cases that involve
// lots of remobs. But in the worst possible scenario one could have
// a symbol table where all symbols clashed on hashing, and then by
// restricting further use to just the last few symbols entered it would be
// possible for all lookup operations to take a number of probes that
// was almost 70% of the table size. In such cases rehashing (without
// expanding the table size at the same time) would leave the table
// unaltered and would not mend things.  To avoid such repeated fruitless
// rehashing I only set rehash_pending if the number of probes was over
// 75% of the table size, and this should be impossible if there are no
// tombstones present.
        if (rehash_pending)
        {   LispObject v = packint_(p);
            Save save(THREADARG p, r, str);
            v = rehash(v, 0);
            errexit();
            save.restore(p, r, str);
            packint_(p) = v;
            rehash_pending = false;
        }
        if (r != fixnum_of_int(0))
        {   mv_2 = internal_symbol;
            return nvalues(r, 2);
        }
    }
#ifdef COMMON
    r = lookup(str, h, packext_(p), hash);
    if (rehash_pending)
    {   LispObject v = packext_(p);
        Save save(THREADARG p, r, str);
        v = rehash(v, 0);
        errexit();
        save.restore(p, r, str);
        packext_(p) = v;
        rehash_pending = false;
    }
    if (r != fixnum_of_int(0))
    {   mv_2 = external_symbol;
        return nvalues(r, 2);
    }
    if (str_is_ok == 4)
    {   mv_2 = nil;
        return nvalues(nil, 2);
    }
    for (r = packuses_(p); r!=nil; r=cdr(r))
    {   LispObject w = car(r);
        w = lookup(str, h, packext_(w), hash);
        if (rehash_pending)
        {   LispObject v = packext_(p);
            Save save(THREADARG p, r, str);
            v = rehash(v, 0);
            errexit();
            save.restore(p, r, str);
            packext_(p) = v;
            rehash_pending = false;
        }
        if (w != fixnum_of_int(0))
        {   mv_2 = inherited_symbol;
            return nvalues(w, 2);
        }
    }
#endif
    if (str_is_ok == 3)
    {   mv_2 = nil;
        return nvalues(nil, 2);
    }
    LispObject s;
    {   Save save(THREADARG str, p);
// Here I was looking up a symbol and it did not exist so I need to
// create it.
#ifdef HASH_STATISTICS
        Noput++;
        Noputp += Noputtmp;
#endif
        s = get_symbol(false);
        errexit();
        save.restore(str, p);
    }
    setheader(s, TAG_HDR_IMMED+TYPE_SYMBOL);
#ifdef COMMON
    if (p == qvalue(keyword_package) && keyword_package != nil)
    {   setvalue(s, s);
        setheader(s, qheader(s) | SYM_KEYWORD_VAR);
    }
    else
#endif
        setvalue(s, unset_var);
    setpname(s, qpname(nil)); // At this stage pname is a dummy
    setplist(s, nil);
    setfastgets(s, nil);
    setpackage(s, p);
    setenv(s, s);
    qfn0(s) = undefined_0;
    qfn1(s) = undefined_1;
    qfn2(s) = undefined_2;
    qfn3(s) = undefined_3;
    qfn4up(s) = undefined_4up;
    qcountLow(s) = (symbol_sequence++ & 0x3fffff);
    qcountHigh(s) = 0;
    Save save(THREADARG s, str);
#ifdef COMMON
    if ((p == qvalue(keyword_package) && keyword_package != nil) ||
        str_is_ok == 2)
    {   add_to_externals(s, p, hash);
        qheader(s) |= SYM_EXTERN_IN_HOME;
    }
    else
#endif
        add_to_internals(s, p, hash);
    save.restore(s, str);
// Now the symbol-head is safe enough that I can let the GC look at it
    if (str_is_ok != 0) setpname(s, str);
    else
    {   LispObject pn;
        Save save1(THREADARG s);
        pn = copy_string(str, h);
        save1.restore(s);
        setpname(s, pn);
    }
    mv_2 = nil;
    return nvalues(static_cast<LispObject>(s), 2);
}

#ifdef COMMON
static LispObject Lfind_package(LispObject env, LispObject name);
#endif

LispObject Lintern_2(LispObject env, LispObject str, LispObject pp)
{   return Lintern(env, str); // Ignores the package for now!
}

#ifdef DEBUG
size_t intern_count = 0;
size_t fullest_package = 0;
#endif

LispObject Lintern(LispObject env, LispObject str)
// Lisp entrypoint for (intern ..)
{   Header h;
    LispObject p;
#ifdef DEBUG
    intern_count++;
#endif
    THREADID;
#ifdef COMMON
    Save save(THREADARG str);
    p = Lfind_package(nil, pp);
    errexit();
    save.restore(str);
#else
    p = CP;
#endif
// If you try to intern a symbol and it is already present in the
// package you are trying to intern it in then just return it without
// needing to do anything to it.
    if (symbolp(str) && qpackage(str) == p) return onevalue(str);
#ifdef COMMON
    if (complex_stringp(str))
    {   Save save1(THREADARG p);
        str = simplify_string(str);
        errexit();
        save1.restore(p);
    }
#endif
// For COMMON it is perhaps undue generosity to permit a symbol here
// rather than just a string.  However it will make life a bit easier for
// me in porting existing code.  Note that the Common Lisp book says quite
// explicitly that symbols are NOT allowed here.
    if (symbolp(str))
    {   Save save1(THREADARG p);
        str = get_pname(str);
        errexit();
        save1.restore(p);
    }
    if (!is_vector(str) || !is_string_header(h = vechdr(str)))
        return aerror1("intern (not a string)", str);
    return iintern(str, length_of_byteheader(h) - CELL, p, 1);
}

#ifdef COMMON

LispObject Lintern(LispObject env, LispObject a)
{   return Lintern_2(env, a, CP);
}

static LispObject Lfind_symbol(LispObject env, LispObject str,
                               LispObject pp)
{   Header h;
    LispObject p;
    THREADID;
    Save save(THREADARG str);
    p = Lfind_package(nil, pp);
    errexit();
    save.restore(str);
    if (symbolp(str))
    {   Save save1(THREADARG p);
        str = get_pname(str);
        save1.restore(p);
    }
    if (complex_stringp(str))
    {   Save save1(THREADARG p);
        str = simplify_string(str);
        errexit();
        save1.restore(p);
    }
    if (!is_vector(str) || !is_string_header(h = vechdr(str)))
    {   return aerror1("find-symbol (not a string)", str);
    }
    return iintern(str, length_of_byteheader(h) - CELL, p, 3);
}

LispObject Lfind_symbol(LispObject env, LispObject str)
{   return Lfind_symbol(env, str, CP);
}

static LispObject Lextern(LispObject env, LispObject sym,
                          LispObject package)
// If sym is internal in given package make it external - the inside parts
// of the export function. Note that the second argument must be a real
// package object, not a package name. Higher level code must have done
// a find-package as necessary.
{   if (!is_symbol(sym)) return onevalue(nil);
    if (remob(sym, packint_(package)))
    {
// I will shrink a hash table if a sequence of remob-style operations,
// which will especially include the case where a symbol ceases to be
// internal to a package so that it can be external, leaves the table
// distinctly empty.
        size_t n = int_of_fixnum(packnint_(package));
        LispObject v = packint_(package);
        size_t used = cells_in_vector(v);
        if (n < used/6 && used>INITIAL_OBVEC_SIZE)
        {   stackcheck(THREADARG sym, package, v);
            THREADID;
            Save save(THREADARG sym, package);
            v = rehash(v, -1);
            save.restore(sym, package);
            packint_(package) = v;
        }
        packnint_(package) -= (1<<4);   // decrement as fixnum
// removed_hash was left set up by remob, and it is known that the symbol
// was not already external, since it had been internal.
        if (qpackage(sym) == package) qheader(sym) |= SYM_EXTERN_IN_HOME;
        add_to_externals(sym, package, removed_hash);
        return onevalue(lisp_true);
    }
    return onevalue(nil);// no action if it was not internal in this package
}

static LispObject Lextern(LispObject env, LispObject str)
{   return Lextern(env, str, CP);
}

static LispObject Limport(LispObject env, LispObject sym,
                          LispObject package)
// The internal part of the IMPORT and SHADOWING-IMPORT functions.
// makes sym internal in package. The symbol MUST NOT be present there
// before this function is called. The second argument must be a real
// package object, not just the name of one.
{   if (!is_symbol(sym)) return onevalue(nil);
    STACK_SANITY;
    THREADID;
    Save save(THREADARG sym, package);
    LispObject pn = get_pname(sym);
    uint64_t hash = hash_lisp_string(pn);
    save.restore(sym, package);
    Save save1(THREADARG sym, package);
    add_to_internals(sym, package, hash);
    save1.restore(sym, package);
    if (qpackage(sym) == nil) qpackage(sym) = package;
    return onevalue(nil);
}

static LispObject Limport(LispObject env, LispObject str)
{   return Limport(env, str, CP);
}

#endif

LispObject ndelete(LispObject a, LispObject l)
// Probably useful in various places throughout the system...
{   if (!consp(l)) return l;
    if (a == car(l)) return cdr(l);
    {   LispObject z1 = l, z2 = cdr(l);
        while (consp(z2))
        {   if (a == car(z2))
            {   write_barrier(cdraddr(z1), cdr(z2));
                return l;
            }
            else
            {   z1 = z2;
                z2 = cdr(z2);
            }
        }
    }
    return l;
}

LispObject Lunintern(LispObject env, LispObject sym, LispObject pp)
{   LispObject package;
    THREADID;
#ifdef COMMON
    {   Save save(THREADARG sym);
        package = Lfind_package(nil, pp);
        errexit();
        save.restore(sym);
    }
#else
    package = pp;
#endif
    if (!is_symbol(sym)) return onevalue(nil);
    if (qpackage(sym) == nil) return onevalue(nil);
    if (qpackage(sym) == package) setpackage(sym,nil);
#ifdef COMMON
    packshade_(package) = ndelete(sym, packshade_(package));
#endif
    if (remob(sym, packint_(package)))
    {   size_t n = int_of_fixnum(packnint_(package));
        LispObject v = packint_(package);
        size_t used = cells_in_vector(v);
        if (n < used/6 && used>INITIAL_OBVEC_SIZE)
        {   stackcheck(THREADARG package, v);
            Save save(THREADARG package);
            v = rehash(v, -1);
            errexit();
            save.restore(package);
            packint_(package) = v;
        }
        packnint_(package) -= (1<<4);   // decrement as fixnum
        return onevalue(lisp_true);
    }
#ifdef COMMON
    if (remob(sym, packext_(package)))
    {
#if 0
#endif
        size_t n = int_of_fixnum(packnext_(package));
        LispObject v = packext_(package);
        size_t used = cells_in_vector(v);
        if (n < used/6 && used>INITIAL_OBVEC_SIZE)
        {   stackcheck(THREADARG package, v);
            Save save(THREADARG package);
            v = rehash(v, -1);
            errexit();
            save.restore(package);
            packext_(package) = v;
        }
        packnext_(package) -= (1<<4);   // decrement as fixnum
        return onevalue(lisp_true);
    }
#endif
    return onevalue(nil);
}

LispObject Lunintern(LispObject env, LispObject str)
{   return Lunintern(env, str, CP);
}

// If I have a window system then getting characters from the keyboard
// is deemed a system-dependent activity.  On non-windowed systems I still
// do rather more than just getchar(), although under typical Unix what I
// do here may count as over-kill.

int tty_count;
#define TTYBUF_SIZE 1024
// Note: this buffer is in characters so putting either wide characters or
// EOF in it could be a problem. I make the buffer somewhat large because of
// the though of multi-byte characters.
static char tty_buffer[TTYBUF_SIZE];
static char *tty_pointer;

int terminal_pushed = NOT_CHAR;

static int kilo = 0;

static LispObject wait_for_char()
{   ensure_screen();
// I rather believe that EMBEDDED and WINDOW_SYSTEM should by mutually
// exclusive
#ifndef EMBEDDED
    {   THREADID;
        on_backtrace(tty_count = wimpget(tty_buffer),
                     if (miscflags & HEADLINE_FLAG)
                     err_printf("+++ Interrupted\n");
                     exit_reason =
                         (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                         (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                         UNWIND_UNWIND;
                     exit_value = exit_tag = nil;
                     exit_count = 0);
        tty_pointer = tty_buffer;
    }
#else // EMBEDDED
// Here is for the EMBEDDED case.
    std::fflush(stdout);
    std::fflush(stderr);
    errorset_msg = nullptr;
    while (tty_count<TTYBUF_SIZE)
    {   int c;
// I really need to understand what to do here so that ^C gets processed
// properly even while I am suspended waiting for getchar() to return...
// However basically handling of interrupts here will be really uncertain!
        c = std::getchar();
        if (c == '\r') c = '\n';
        if (c == EOF)
        {   std::clearerr(stdin);    // Believed to be what is wanted
            c = CTRL_D;         // Use ASCII ^D as EOF marker
// I should perhaps use the UTF8 sequence f7/bf/bf/bf rather than 04?
        }
// If I fetched a wide character I would need to utf-8 encode it here...
// unless getchar has already delivered in that way.
        tty_buffer[tty_count++] = static_cast<char>(c);
        if (c == '\n' || c == '\v' || c == CTRL_D) break;
    }
    tty_pointer = tty_buffer;
#endif // EMBEDDED
    return nil;
}

bool force_echo = false;

static int raw_char_from_terminal()
// "What ..." you might ask, "is the meaning of this mess?".  Well the answer
// is that when input is directly from the terminal I buffer up to 256
// characters in a private buffer, and I discount the time spent filling this
// buffer. On some miserable systems this will succeed in ensuring that the
// time reported at the end of a run reflects time that CSL spends computing
// and not time it spends waiting for the user to type something at it.  Note
// that it is only stdin input that I intercept in this way, so the full cost
// of getting characters from disc files will be accounted.  I also (rather
// improperly) map EOF onto a code (4) which will fit in a byte-sized buffer.
// I fill by buffer up as far as a newline or a vertical tab (or end of file),
// and hope that that will not seriously hurt any interactions with CSL.
// After all the operating system may well line-buffer input anyway, so that
// it can deal with the delete key on your keyboard for you.
//
// Furthermore here is where I display prompt strings to the user -
// in a way that Standard Lisp does not define, but PSL implements and
// some REDUCE programmers have come to expect... (in some cases I will
// let lower level code deal with prompts).
//
// If the user provokes an interrupt (^C, or ESC or whatever) while I am
// in here I will try to return promptly with an empty buffer and
// some indication of an exception.
{   int c;
    if (++kilo >= 1024)
    {   kilo = 0;
        io_now++;
    }
    if (terminal_pushed != NOT_CHAR)
    {   c = terminal_pushed;
        terminal_pushed = NOT_CHAR;
        return c;
    }
// I have a hook here for cases where I want to call CSL from other C
// code.  In that case the variable used here points at a function that
// reads a single character.  When I use this option I will NOT generate
// prompts.
    if (procedural_input != nullptr) c = (*procedural_input)();
    else if (non_terminal_input != nullptr)
    {   c = GETC(non_terminal_input);
    }
    else
    {   if (tty_count == 0) wait_for_char();
        if (tty_count == 0) c = '\n'; // ^C odd case
        else
        {   tty_count--;
            c = *tty_pointer++;
        }
    }
    if (c == EOF || c == CTRL_D) return EOF;
    if (c == CTRL_C || c == CTRL_G)
    {   exit_reason = (c == CTRL_G) ? UNWIND_ERROR : UNWIND_UNWIND;
        exit_value = exit_tag = nil;
        exit_count = 0;
// I am liable to have set up a pending stack event - given that
// I am about to respond here by doing a "throw" I will cancel it.
        event_flag = 0;
        THROW(LispSimpleError);
    }
    if (qvalue(echo_symbol) != nil || force_echo)
    {   LispObject stream = qvalue(standard_output);
        if (!is_stream(stream)) stream = qvalue(terminal_io);
        if (!is_stream(stream)) stream = lisp_terminal_io;
        THREADID;
        ignore_error(putc_stream(c, stream));
    }
    else if (spool_file != nullptr &&
             non_terminal_input == nullptr) PUTC(c, spool_file);
    return c;
}

int char_from_terminal(LispObject dummy)
{   int ch = raw_char_from_terminal();
    if (ch == EOF) return ch;
    ch &= 0xff;
    if (ch >= 0xf0)
    {   ch = ((ch & 0x07) << 6) | (raw_char_from_terminal() & 0x3f);
        ch = (ch << 6) | (raw_char_from_terminal() & 0x3f);
        ch = (ch << 6) | (raw_char_from_terminal() & 0x3f);
    }
    else if (ch >= 0xe0)
    {   ch = ((ch & 0x0f) << 6) | (raw_char_from_terminal() & 0x3f);
        ch = (ch << 6) | (raw_char_from_terminal() & 0x3f);
    }
    else if (ch >= 0xc0)
    {   ch = ((ch & 0x1f) << 6) | (raw_char_from_terminal() & 0x3f);
    }
    else if (ch >= 0x80) ch = '?'; // badly formated utf-8 input
    return ch;
}

LispObject Lrds(LispObject env, LispObject a)
{   LispObject old = qvalue(standard_input);
    if (a == nil) a = qvalue(terminal_io);
    if (a == old) return onevalue(old);
    else if (!is_stream(a)) return aerror1("rds", a);
    else if ((character_stream_reader *)stream_read_fn(
                 a) == char_from_illegal)
        return aerror("rds"); // closed stream or output stream
    setvalue(standard_input, a);
    return onevalue(old);
}

LispObject Lrtell_1(LispObject env, LispObject stream)
{   int32_t n;
    if (!is_stream(stream)) return onevalue(nil);
    n = other_read_action(READ_TELL, stream);
    if (n == -1) return onevalue(nil);
    else return onevalue(fixnum_of_int(n));
}

LispObject Lrtell(LispObject env)
// RTELL returns an integer that indicates the position of the current
// input stream (as selected by RDS). If the position is not available
// (as would be the case for an interactive stream) then NIL is returned.
// Otherwise the result is an integer suitable for use with rseek.  In the
// case that the file was opened in binary mode the number returned is a
// direct indication of the position in the file and arithmetic will
// behave predictably - for text streams the value returned should be
// thought of as an abstract position-tag.
{   return Lrtell_1(nil, qvalue(standard_input));
}

LispObject Lrseekend(LispObject env, LispObject stream)
{   if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    other_read_action(READ_FLUSH, stream);
    if (other_read_action(READ_END, stream) != 0) return onevalue(nil);
    else return onevalue(lisp_true);
}

LispObject Lrseek_2(LispObject env, LispObject stream, LispObject a)
{   size_t n;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (is_fixnum(a)) n = (size_t)int_of_fixnum(a);
    else return aerror("rseek");
    other_read_action(READ_FLUSH, stream);
    if (other_read_action(n | 0x80000000,
                          stream) != 0) return onevalue(nil);
    else return onevalue(lisp_true);
}

LispObject Lrseek(LispObject env, LispObject a)
// If the current input stream supports random access this re-positions
// it to a place indicated by the argument a.  If the file was opened in
// binary mode then a can be an integer indicating how far down the file
// to set the position.  For text files arguments to RSEEK should only be
// values returned by previous calls to RTELL.  RSEEK returns nil if it
// failed (and if it noticed that fact) or T if it succeeded.
{   return Lrseek_2(nil, qvalue(standard_input), a);
}

// The getc_stream() method must NEVER be able to cause garbage collection,
// since I code the reader here on the assumption that file control blocks
// do not move while individual characters are read.


// While I am in the middle of reading a whole expression the variable
// curchar will hold the most recent character (or NOT_CHAR if there is none),
// but between expressions I will push that back into the stream header.

static void skip_whitespace(LispObject stream)
{   for (;;)
    {   switch (curchar)
        {   case NOT_CHAR:
            case 0:    case '\v':   case '\f':
            case ' ':  case '\t':   case '\n':
            case '\r': case CTRL_C: case CTRL_G:
                curchar = getc_stream(stream);
                continue;

#ifndef COMMON
            case '%':
#else
            case ';':
#endif
                while (curchar != '\n' &&
                       curchar != EOF &&
                       curchar != CTRL_D)
                {   curchar = getc_stream(stream);
                }
                continue;

            default:
                return;
        }
    }
}

static LispObject read_s(LispObject stream);

#ifdef COMMON
static LispObject read_hash(LispObject stream);
#endif

static LispObject read_list(LispObject stream)
// There is no code here to do anything about general read-macros,
// and it will be awkward to fit it in here because of the reliance
// that the Common Lisp readmacro scheme puts on the ability to return
// no values at all using (values).  I implement ' and ; and ` since
// they seem very useful, but only simple cases of #.
// I require that when this function is called I have already done
// a skip_whitespace(), and as a result curchar will not be NOT_CHAR.
{   LispObject l, w;
    THREADID;
    stackcheck(THREADARG stream);
    if (curchar == ')')
    {   curchar = NOT_CHAR;
        return nil;
    }
    STACK_SANITY;
    Save save(THREADARG stream);
#ifdef COMMON
    if (curchar == '#')
    {   l = read_hash(stream);
        errexit();
        if (l == SPID_NOINPUT)
        {   save.restore(stream);
            return read_list(stream);
        }
    }
    else
#endif
        l = read_s(stream);
    errexit();
    l = ncons(l);
    LispObject r = l;
    Save save0(THREADARG r);
    for (;;)
    {   {   Save save1(THREADARG l);
            skip_whitespace(stream);
            errexit();
            save1.restore(l);
            save.restore(stream);
        }
        switch (curchar)
        {

#ifndef COMMON
            case ']':
#endif
            case ')':
                curchar = NOT_CHAR;
                save0.restore(r);
                return r;

            case EOF:
            case CTRL_D:
                return l;

            // This code treats '.' as a special lexical marker, while the
            // full version of the reader has to be more subtle.
            case '.':
                curchar = NOT_CHAR;
                {   Save save1(THREADARG l);
                    w = read_s(stream);
                    errexit();
                    save1.restore(l);
                    write_barrier(cdraddr(l), w);
                    save.restore(stream);
                    skip_whitespace(stream);
                    if (curchar == ')') curchar = NOT_CHAR;
                    save0.restore(r);
                    return r;
                }
#ifdef COMMON
            case '#':
                {   Save save1(THREADARG l);
                    w = read_hash(stream);
                    errexit();
                    if (w == SPID_NOINPUT)
                    {   save1.restore(l);
                        save.restore(stream);
                        continue;
                    }
                    w = ncons(w);
                    errexit();
                    save1.restore(l);
                }
                write_barrier(cdraddr(l), w);
                l = w;
                save.restore(stream);
                continue;
#endif
            default:
                {   Save save1(THREADARG l);
                    w = read_s(stream);
                    errexit();
                    w = ncons(w);
                    errexit();
                    save1.restore(l);
                    write_barrier(cdraddr(l), w);
                }
                l = w;
                save.restore(stream);
                continue;
        }
    }
}

static LispObject list_to_vector(LispObject l)
{   size_t len = 0;
    LispObject p = l;
    while (consp(p)) len++, p = cdr(p);
    THREADID;
    Save save(THREADARG l);
    p = get_vector_init(CELL*(len+1), nil);
    errexit();
    save.restore(l);
    len = 0;
    while (consp(l))
    {   elt(p, len) = static_cast<LispObject>(car(l));
        len++;
        l = cdr(l);
    }
    return p;
}

#ifdef COMMON

static bool evalfeature(LispObject u)
{   LispObject w;
    if (consp(u))
    {   LispObject fn = car(u);
        u = cdr(u);
        if (!consp(u)) return false;
        if (fn == not_symbol) return !evalfeature(car(u));
        else if (fn == and_symbol)
        {   while (consp(u))
            {   if (!evalfeature(car(u))) return false;
                u = cdr(u);
            }
            return true;
        }
        else if (fn == or_symbol)
        {   while (consp(u))
            {   if (evalfeature(car(u))) return true;
                u = cdr(u);
            }
            return false;
        }
        else return false;
    }
    w = qvalue(features_symbol);
    while (consp(w))
    {   if (u == car(w)) return true;
        w = cdr(w);
    }
    return false;
}

static LispObject read_hash(LispObject stream)
{
// A small subset of the # escaped read-macros will be supported here.
// curchar must already be set to the character that follows the '#'
    int32_t v, w = -1;
    int radix;
    LispObject p;
    THREADID;
    curchar = getc_stream(stream);
    if (curchar <= 0xff && std::isdigit(curchar))
    {   w = 0;
        do
        {   w = 10*w + curchar - '0';
// Observe that I do not do long arithmetic here!
            curchar = getc_stream(stream);
        }
        while (curchar <= 0xff && std::isdigit(curchar));
    }
    switch (curchar)
    {   default:
//      error("Unknown # escape");
            return pack_char(0, '#');
#ifdef COMMON
        case '#':
            curchar = NOT_CHAR;
            p = reader_workspace;
            while (p != nil)
            {   LispObject k = car(p);
                if (fixnum_of_int(w) == car(k)) return cdr(k);
                p = cdr(p);
            }
            return aerror1("Label not found with #n# syntax", fixnum_of_int(w));
        case '=':
            curchar = NOT_CHAR;
            Save save(THREADARG stream);
// Hmmm - is it necessary for #nn# to refer back to the label here from
// within the value about to be read?
            p = read_s(stream);
            save.restore(stream);
            Save save1(THREADARG p);
            reader_workspace = acons(fixnum_of_int(w), p, reader_workspace);
            save1.restore(p);
            return p;
#endif
        case ':':       // #:XXX reads in a gensym...
            curchar = NOT_CHAR;
            {   LispObject base = read_s(stream), al;   // The XXX bit unadorned
// This keeps an association list of gensyms present in this call to READ.
// Note that if you use #.(read) [or other clever things] you may get
// muddled about contexts.  Note that this is sometimes helpful with
// Standard Lisp but that for Common Lisp the more general #= and ##
// mechanism should be used and this behaviour here would count as
// WRONG.
                al = reader_workspace;
                while (al != nil)
                {   LispObject k = car(al);
                    if (base == car(k)) return cdr(k);
                    al = cdr(al);
                }
                Save save(THREADARG base);
// Beware that #:ggg has just ggg as its name, with no numeric suffix.
                al = Lgensym2(nil, base);
                save.restore(base);
                al = acons(base, al, reader_workspace);
                reader_workspace = al;
                return cdr(car(al));
            }

        case '(':       // Simple vector
            curchar = getc_stream(stream);
            skip_whitespace(stream);
            {   LispObject l = read_list(stream);
                return list_to_vector(l);
            }
        case '\'':
            curchar = NOT_CHAR;
            p = read_s(stream);
            return list2(function_symbol, p);
        case '\\':
// The character just after "#\" is read without any case folding
            curchar = getc_stream(stream);
            w = curchar;
#ifdef COMMON
// The word after "#\" is always spelt in regular ASCII so wide char support
// does not cut in here.
            if (w <= 0x7f && std::isalpha(w))
            {   char buffer[32];
                int bp = 0, w0 = w;
                while (w <= 0x7f && std::isalpha(w) && bp < 30)
                {   buffer[bp++] = std::toupper(w);  // Force word to upper case
                    curchar = getc_stream(stream);
                    w = curchar;
                }
                if (bp == 1) return pack_char(0, w0 & 0x001fffff);
                buffer[bp] = 0;
                p = make_string(buffer);
                p = Lintern_2(nil, p, qvalue(keyword_package));
                p = get(p, named_character, nil);
                return p;
            }
#endif
            curchar = NOT_CHAR;
            return pack_char(0, w & 0x001fffff);
        case '.':
            curchar = NOT_CHAR;
            p = read_s(stream);
// The next is in case the expression evaluated involves reading from
// this or another stream.
            if (curchar != NOT_CHAR)
            {   other_read_action(curchar, stream);
                curchar = NOT_CHAR;
            }
            p = eval(p, nil);
            return onevalue(p);
        case '+':
        case '-':
            v = (curchar == '-');
            curchar = NOT_CHAR;
// In March 1988 X3J13 voted that feature names read here should be in
// the keyword package unless explicily otherwise qualified, but (I guess)
// the AND, OR and NOT operators applying to them are NOT in the keyword
// package. Thus I can not just rebind *package* here in any simple way.
// Oh dear - I hope nobody relies on what those kind experts decided!
// Meanwhile REMEMBER to go    #+ :whatever     please.
            {   Save save(THREADARG stream);
                p = read_s(stream);
                errexit();
                w = evalfeature(p);
                errexit();
                save.restore(stream);
            }
            if (w == v) read_s(stream);
// The following flag-value shows that read_hash() has not actually read
// anything - but it may have skipped over some unwanted stuff.
            return onevalue(SPID_NOINPUT);

        case 'r': case 'R':
            radix = (w>=2 && w<=36) ? static_cast<int>(w) : 10;
            break;
        case 'b': case 'B':
            radix = 2;
            break;
        case 'o': case 'O':
            radix = 8;
            break;
        case 'x': case 'X':
            radix = 16;
            break;
    }
// Here I have a number specified in some unusual radix
    w = fixnum_of_int(0);
    curchar = getc_stream(stream);
    while ((v = value_in_radix(curchar, radix)) >= 0)
    {   w = times2(w, fixnum_of_int((int32_t)radix));
        w = plus2(w, fixnum_of_int(v));
        curchar = getc_stream(stream);
    }
    return w;
}

#endif // COMMON

bool is_constituent(int c)
{   if (c == EOF) return false;
    if (c & ESCAPED_CHAR) return true;   // escaped
    switch (c)
    {
// The following characters terminate symbols
        case ' ':   case '\n':  case '\t':  case '\v':  case '\f':  case 0:
        case '(':   case ')':   case '\'':  case ';':   case '"':   case '`':
        case ',':   case '\r':
        case CTRL_D:     // character 4 is EOF in ASCII
#ifndef COMMON
        case '+':   case '-':   case '*':   case '/':   case '~':   case '\\':
        case '@':   case '#':   case '$':   case '%':   case '^':   case '&':
        case '=':   case '{':   case '}':   case '[':   case ']':   case ':':
        case '<':   case '>':   case '?':   case '!':   case '|':
// case '_':    In OLD Standard Lisp underscore was a break character -
// these days it is classified rather oddly, in that it does not terminate
// a symbol but behaves specially if it starts one.
// What about '.', which may need to be treated specially?
        case '.':
#endif
            return false;
        default:
            return true;
    }
}

static LispObject backquote_expander(LispObject a)
{   LispObject w1, f;
    if (a == nil) return a;
    if (!consp(a)) return list2(quote_symbol, a);
    THREADID;
    stackcheck(THREADARG a);
    f = car(a);
#if 0
// For quite some while I did not understand what I was supposed to do with
// nested backquotes, but PSL showed me what was required. Excet that since I
// expand backquotes while reading I do not need to do this here!
    if (f == backquote_symbol)
    {   a = backquote_expander(car(cdr(a)));
        if (a == nil) return a;
        if (!consp(a)) return list2(quote_symbol, a);
        f = car(a);
    }
#endif
    if (f == comma_symbol) return car(cdr(a));
    if (consp(f) && car(f) == comma_at_symbol)
    {   w1 = car(cdr(f));
        Save save(THREADARG w1);
        a = backquote_expander(cdr(a));
        errexit();
        save.restore(w1);
        w1 = list2(w1, a);
        errexit();
        return cons(append_symbol, w1);
    }
// There is noticable scope for further optimisation here, with the
// introduction of uses of list, list* as well as just cons and append.
// It is also probably useful to worry about ,. as well as ,@ but for
// now I defer that until the full version of the reader is installed.
    {   Save save(THREADARG a);
        f = backquote_expander(f);
        errexit();
        save.restore(a);
    }
    {   Save save(THREADARG f);
        a = backquote_expander(cdr(a));
        errexit();
        save.restore(f);
    }
    a = list2(f, a);
    errexit();
    return cons(cons_symbol, a);
}

static bool read_failure;

// Here c is a Unicode character - it gets expanded to UTF-8 format
// as necessary.

void packcharacter(int c)
{   size_t boffo_size = length_of_byteheader(vechdr(boffo));
// I expand boffo (maybe) several characters earlier than you might
// consider necessary. Some of that is to be extra certain about having
// space in it when I pack a multi-byte character.
    if (boffop >= boffo_size-CELL-8)
    {   LispObject new_boffo =
            get_basic_vector(TAG_VECTOR, TYPE_STRING_4, 2*boffo_size);
        std::memcpy(bit_cast<void *>(bit_cast<char *>
                                             (new_boffo) + (CELL-TAG_VECTOR)),
                    &boffo_char(0), boffop);
        boffo = new_boffo;
    }
    c &= 0x001fffff;
    if (c > 0xffff)
    {   boffo_char(boffop++) = 0xf0 + ((c >> 18) & 0x07);
        boffo_char(boffop++) = 0x80 + ((c >> 12) & 0x3f);
        boffo_char(boffop++) = 0x80 + ((c >> 6) & 0x3f);
        boffo_char(boffop++) = 0x80 + (c & 0x3f);
    }
    else if (c > 0x7ff)
    {   boffo_char(boffop++) = 0xe0 + ((c >> 12) & 0x0f);
        boffo_char(boffop++) = 0x80 + ((c >> 6) & 0x3f);
        boffo_char(boffop++) = 0x80 + (c & 0x3f);
    }
    else if (c > 0x7f)
    {   boffo_char(boffop++) = 0xc0 + ((c >> 6) & 0x1f);
        boffo_char(boffop++) = 0x80 + (c & 0x3f);
    }
    else boffo_char(boffop++) = c;
}

// packbyte() packs a BYTE not a CHARACTER so the material packed
// must already be in UTF-8 format.

void packbyte(int c)
{   size_t boffo_size = length_of_byteheader(vechdr(boffo));
    if (boffop >= boffo_size-CELL-8)
    {   LispObject new_boffo =
            get_basic_vector(TAG_VECTOR, TYPE_STRING_4, 2*boffo_size);
        std::memcpy(bit_cast<void *>(bit_cast<char *>
                                             (new_boffo) + (CELL-TAG_VECTOR)),
                    &boffo_char(0), boffop);
        boffo = new_boffo;
    }
    boffo_char(boffop++) = c;
}

#ifdef COMMON
static char package_name[32];
#endif

static LispObject read_s(LispObject stream)
{   LispObject w;
    THREADID;
    for (;;)
    {   skip_whitespace(stream);
        switch (curchar)
        {   case EOF:
            case CTRL_D:
                return eof_symbol;

            case '(':
                curchar = NOT_CHAR;
                skip_whitespace(stream);
                return read_list(stream);

#ifndef COMMON
            case '[':
                curchar = NOT_CHAR;
                skip_whitespace(stream);
                w = read_list(stream);
                return list_to_vector(w);

            case ']':
#endif
            case ')':
                curchar = NOT_CHAR;
                continue;               // Ignore spurious rpar

            case '\'':
                curchar = NOT_CHAR;
                w = read_s(stream);
                return list2(quote_symbol, w);

            case '`':
                curchar = NOT_CHAR;
                w = read_s(stream);
                return backquote_expander(w);

            case ',':
                curchar = getc_stream(stream);
                if (curchar == '@')
                {   curchar = NOT_CHAR;
                    w = read_s(stream);
                    return list2(comma_at_symbol, w);
                }
                else
                {   w = read_s(stream);
                    return list2(comma_symbol, w);
                }

// Neither Standard nor Common Lisp make stray dots very welcome. In Common
// Lisp multiple adjacent dots are supposed to be an error. Here I just ignore
// stray dots, and hope that nobody is silly enough to have them in their code.
            case '.':
//          error("Bad dot");
                curchar = NOT_CHAR;
                continue;               // Ignore spurious dot

#ifdef COMMON
            case '#':
                {   Save save(THREADARG stream);
                    w = read_hash(stream);
                    errexit();
                    save.restore(stream);
                }
                if (w != SPID_NOINPUT) return w;
                else return read_s(stream);
#endif
            case '"':
                boffop = 0;
                {   for (;;)    // Used to cope with "abc""def"
                    {   curchar = getc_stream(stream);
#ifdef COMMON
                        if (curchar == ESCAPE_CHAR)
                        {   curchar = getc_stream(stream);
                            if (curchar!=EOF) curchar |= ESCAPED_CHAR;
                        }
#endif
                        if (curchar == EOF || curchar == CTRL_D)
                            return eof_symbol;
                        while (curchar != '"' &&
                               curchar != EOF &&
                               curchar != CTRL_D)
                        {   Save save(THREADARG stream);
                            packcharacter(curchar);
                            errexit();
                            save.restore(stream);
                            curchar = getc_stream(stream);
#ifdef COMMON
                            if (curchar == ESCAPE_CHAR)
                            {   curchar = getc_stream(stream);
                                if (curchar!=EOF) curchar |= ESCAPED_CHAR;
                            }
#endif
                        }
#ifndef COMMON
                        curchar = getc_stream(stream);
                        if (curchar == '"')
                        {   Save save(THREADARG stream);
                            packcharacter(curchar);
                            errexit();
                            save.restore(stream);
                            continue;    // Handle "abc""def" for Standard Lisp
                        }
#else
                        curchar = NOT_CHAR;
#endif
                        return copy_string(boffo, boffop);
                    }
                }

#ifndef COMMON
            case '+':   case '-':
            case '0':   case '1':   case '2':   case '3':   case '4':
            case '5':   case '6':   case '7':   case '8':   case '9':
// I treat numbers specially here since I want to allow '.' within
// numbers, but NOT within symbols.  Common Lisp views '.' as a
// constituent character and so does not need quite so much effort
// just here.
            {   boffop = 0;
                if (curchar == '+' || curchar == '-')
                {   Save save(THREADARG stream);
                    packcharacter(curchar); // in fact char is Basic Latin
                    errexit();
                    save.restore(stream);
                    curchar = getc_stream(stream);
// + or - not followed by a digit will be read as a symbol
                    if (curchar > 0xff || !std::isdigit(curchar))
                        return intern(boffop, false);
                }
                bool ishex = false, isold = false;
// The mess here should allow  nnnnnn  0Xxxxxxxx 0Znnnnnnn where n denotes
// 0..9 and x denotes 0..9a..fA..F.
// The "0z" notation is a TEMPORARY provision while I work on an upgraded
// arithmetic package. It causes the OLD code and bignum representation to be
// used.
                while (curchar <= 0xff &&
                       (std::isdigit(curchar) ||
                        ((boffop == 1 &&
                          boffo_char(0)=='0' &&
                          (((curchar=='x' || curchar=='X') && (ishex=true)) ||
                           ((curchar=='z' || curchar=='Z') && (isold=true))))) ||
                        (ishex && (('a'<=curchar && curchar<='f') ||
                                   ('A'<=curchar && curchar<='F')))))
                {   Save save(THREADARG stream);
                    packcharacter(curchar);  // Should be '0 to '9' (only)
                    errexit();
                    save.restore(stream);
                    curchar = getc_stream(stream);
                }
// accept possible decimal point
                if (!ishex && curchar == '.')
                {   Save save(THREADARG stream);
                    packcharacter(curchar);
                    errexit();
                    save.restore(stream);
                    curchar = getc_stream(stream);
                    while (curchar <= 0xff && std::isdigit(curchar))
                    {   Save save1(THREADARG stream);
                        packcharacter(curchar);
                        errexit();
                        save1.restore(stream);
                        curchar = getc_stream(stream);
                    }
                }
// accept possible exponent
                if (!ishex &&
                    (curchar == 'e' || curchar == 'E' ||
// Extend syntax to support more exponent signifiers. This is a change so
// that e.g "1.23D45" will now be parsed as one symbol not two.
                     curchar == 's' || curchar == 'S' ||
                     curchar == 'f' || curchar == 'F' ||
                     curchar == 'd' || curchar == 'D' ||
                     curchar == 'l' || curchar == 'L'))
                {   Save save(THREADARG stream);
                    packcharacter(curchar);
                    errexit();
                    save.restore(stream);
                    curchar = getc_stream(stream);
                    if (curchar == '+' || curchar == '-')
                    {   Save save1(THREADARG stream);
                        packcharacter(curchar);
                        errexit();
                        save1.restore(stream);
                        curchar = getc_stream(stream);
                    }
                    while (curchar <= 0xff && std::isdigit(curchar))
                    {   Save save1(THREADARG stream);
                        packcharacter(curchar);
                        errexit();
                        save1.restore(stream);
                        curchar = getc_stream(stream);
                    }
                }
#ifdef ARITHLIB
                if (ishex) return intern_hex_new(boffop);
                else if (!isold) return intern_new(boffop);
                else return intern(boffop, false, 2);
#else // ARITHLIB
                if (ishex) return intern_hex_old(boffop);
                else return intern(boffop, false);
#endif // ARITHLIB
            }

            case '_':       // This seems to have to be a funny case for REDUCE
                boffop = 0;
                {   Save save(THREADARG stream);
                    packcharacter(curchar);
                    errexit();
                    save.restore(stream);
                }
                curchar = getc_stream(stream);
                return intern(boffop, false);
#endif

            default:
            {   bool escaped = false;
#ifdef COMMON
                bool within_vbars = false;
                int colon = -1, double_colon = -1, i;
#endif
                boffop = 0;
#ifdef COMMON
                while (curchar == '|')
                {   stackcheck(THREADARG stream);
                    curchar = getc_stream(stream);
                    within_vbars = !within_vbars;
// A funny thought arises here - maybe the characters ||123 are a potential
// number, since there are no characters inside the vertical bars to show
// otherwise! Hence I need to set escaped only when I find a genuine character
// within the vertical-bar protected region. Hence this coded as a while
// loop not a simple IF statement. Another horrid issue is that the input
// "|| " (where there are two initial vertical bars and then a terminating
// character) ought to parse as an identifier with an empty name. Thus
// if I read ahead here and find whitespace etc I need to exit here.
                    if (!within_vbars && !is_constituent(curchar))
                        return intern(0, true);
                }
#endif
                if (curchar == ESCAPE_CHAR)
                {   stackcheck(THREADARG stream);
                    curchar = getc_stream(stream);
// However, any character escaped with '\' means we do not have a number
                    escaped = true;
                }
                else
#ifdef COMMON
                    if (!within_vbars)
                    {   if (curchar == ':') colon = boffop, escaped = true;
#else
                    {
#endif
                        if (curchar != EOF &&
                            (curchar<=0xffff || sizeof(wchar_t)==4))
                        {   if (qvalue(lower_symbol) != nil)
                                curchar = std::towlower(curchar);
                            else if (qvalue(raise_symbol) != nil)
                                curchar = std::towupper(curchar);
                        }
                    }

// Here is the main loop that reads an identifier. Observe the extra
// complication that Common Lisp generates with the need to support
// package markers and '|' style escapes...
                do
                {   {   Save save(THREADARG stream);
                        packcharacter(curchar);
                        errexit();
                        save.restore(stream);
                    }
                    curchar = getc_stream(stream);
#ifdef COMMON
                    if (within_vbars) escaped = true;
                    while (curchar == '|')
                    {   stackcheck(THREADARG stream);
                        curchar = getc_stream(stream);
                        within_vbars = !within_vbars;
                    }
#endif
                    if (curchar == EOF) break;
                    else if (curchar == ESCAPE_CHAR)
                    {   stackcheck(THREADARG stream);
                        curchar = getc_stream(stream);
                        curchar |= ESCAPED_CHAR;
                        escaped = true;
                    }
#ifdef COMMON
                    else if (!within_vbars)
                    {   if (curchar == ':')
                        {   if (colon >= 0) double_colon = boffop;
                            else colon = boffop, escaped = true;
                        }
#endif
                        else if (curchar<=0xffff || sizeof(wchar_t)==4)
                        {   if (qvalue(lower_symbol) != nil)
                                curchar = std::towlower(curchar);
                            else if (qvalue(raise_symbol) != nil)
                                curchar = std::towupper(curchar);
                        }
#ifdef COMMON
                    }
                }
                while (within_vbars || is_constituent(curchar));
#else
                    } while (is_constituent(curchar));
#endif
#ifdef COMMON
// If there are no colons present, or if there are two but they
// are not consecutive, or of there are three or more, or if the last
// character of the symbol was a colon, I will just look it up in
// the current package.
                if (colon < 0 || colon+1==boffop)
                    return intern(boffop, escaped);
                if ((double_colon >= 0 && double_colon != colon+1) ||
                    double_colon+1==boffop)
                    return intern(boffop, escaped);
// If the first character was a colon I use the keyword package.
                std::memset(package_name, 0, sizeof(package_name));
                std::strncpy(package_name, &celt(boffo, 0), (size_t)colon);
                package_name[sizeof(package_name)-1] = 0;
// term_printf("Package lookup <%.*s>\n", (int)colon, &celt(boffo, 0));
                if (colon == 0) w = qvalue(keyword_package);
                else w = find_package(&celt(boffo, 0), colon);
// Here I rely on find_package never raising an exception and never giving
// a possible entry into a break loop (etc), since I need boffo[] intact
// after the call.
                if (w == nil)
                {   err_printf(
                        "+++ Package %s not found: using current package\n",
                        package_name);
// Similarly I assume, unreasonably, that boffo can not be disturbed by
// printing this warning message.
                    w = CP; // default behaviour: unknown package
                }
                if (double_colon >= 0) colon = double_colon;
                i = 0;
                colon++;
                while (colon < boffop)
                    boffo_char(i++) = boffo_char(colon++);
                boffop = i;
// term_printf("Name within package <%.*s>\n", (int)boffop, &celt(boffo, 0));
                if (double_colon < 0 && w != qvalue(keyword_package))
                {   // In the case ppp:sss it MUST be external in ppp
                    LispObject wx;
                    Save save(THREADARG w);
                    wx = iintern(boffo, boffop, w, 4);
                    save.restore(w);
                    if (mv_2 == nil)
                    {   err_printf("+++ Symbol %.*s not external in %s\n",
                                   static_cast<int>(boffop), &celt(boffo, 0), package_name);
                        err_printf("+++ Treating as internal symbol...\n");
                    }
                    else return wx;
                }
// Curiously I will always take keywords (as in :kkk) through the path
// that corresponds to looking up an internal symbol, ie ::kkk, since that
// way I allow the reader to create a new symbol. If I handled the keyword
// case in the usual external symbol way it would demand that the keyword
// already existed (since in all other packages nothing is external unless
// it already exists and has been exported).
                return iintern(boffo, boffop, w, 0);
#else
                return intern(boffop, escaped);
#endif
            }
        }
    }
}

int char_from_synonym(LispObject stream)
{   stream = qvalue(stream_read_data(stream));
    if (!is_stream(stream)) return aerror1("bad synonym stream", stream);
    return getc_stream(stream);
}

int char_from_concatenated(LispObject stream)
{   LispObject l = stream_read_data(stream), s1;
    int c;
    THREADID;
    while (consp(l))
    {   s1 = car(l);
        if (!is_symbol(s1))
        {   l = cdr(l);
            stream_read_data(stream) = l;
            continue;
        }
        s1 = qvalue(s1);
        if (!is_stream(s1))
        {   l = cdr(l);
            stream_read_data(stream) = l;
            continue;
        }
        Save save(THREADARG l, stream);
        c = getc_stream(s1);
        if (exceptionPending()) return EOF;
        save.restore(l, stream);
        if (c == EOF)
        {   l = cdr(l);
            stream_read_data(stream) = l;
            continue;
        }
    }
    return EOF;
}

int char_from_echo(LispObject stream)
{   int c;
    LispObject stream1 = qvalue(stream_read_data(stream));
    if (!is_stream(stream1)) return aerror1("bad synonym stream", stream1);
    c = getc_stream(stream1);
    char_to_synonym(c, stream);
    return c;
}

static int raw_input = 0;

static int raw_char_from_file(LispObject stream)
{   int ch;
    if (++kilo >= 1024)
    {   kilo = 0;
        io_now++;
    }
    ch = GETC(stream_file(stream));
    if (ch == EOF) return EOF;
    if (qvalue(echo_symbol) != nil || force_echo)
    {   LispObject stream1 = qvalue(standard_output);
        if (!is_stream(stream1)) stream1 = qvalue(terminal_io);
        if (!is_stream(stream1)) stream1 = lisp_terminal_io;
        THREADID;
        ignore_error(putc_stream(ch, stream1));
    }
    return ch;
}

int char_from_file(LispObject stream)
{   int ch = stream_pushed_char(stream);
    if (ch == NOT_CHAR)
    {   ch = raw_char_from_file(stream);
        if (ch == EOF) return EOF;
        ch &= 0xff;
        if (ch >= 0xf0)
        {   ch = ((ch & 0x07) << 6) | (raw_char_from_file(stream) & 0x3f);
            ch = (ch << 6) | (raw_char_from_file(stream) & 0x3f);
            ch = (ch << 6) | (raw_char_from_file(stream) & 0x3f);
        }
        else if (ch >= 0xe0)
        {   ch = ((ch & 0x0f) << 6) | (raw_char_from_file(stream) & 0x3f);
            ch = (ch << 6) | (raw_char_from_file(stream) & 0x3f);
        }
        else if (ch >= 0xc0)
        {   ch = ((ch & 0x1f) << 6) | (raw_char_from_file(stream) & 0x3f);
        }
        else if (ch >= 0x80) ch = '?'; // badly formated utf-8 input
    }
    else stream_pushed_char(stream) = NOT_CHAR;
    return ch;
}

int32_t read_action_illegal(int32_t op, LispObject f)
{   if (op != READ_CLOSE && op != READ_IS_CONSOLE)
        return aerror1("Illegal operation on stream",
                cons_no_gc(fixnum_of_int(op), stream_type(f)));
    return 0;
}

int32_t read_action_file(int32_t op, LispObject f)
{   if (op < -1) return std::fseek(stream_file(f), op & 0x7fffffff,
                                       SEEK_SET);
    else if (op <= 0x10ffff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                if ((std::FILE *)stream_file(f) == nullptr) op = 0;
                else op = std::fclose(stream_file(f));
                set_stream_read_fn(f, char_from_illegal);
                set_stream_read_other(f, read_action_illegal);
                set_stream_file(f, nullptr);
                return op;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
                return 0;
            case READ_TELL:
                if ((op = stream_pushed_char(f)) != NOT_CHAR)
                {   std::ungetc(op, stream_file(f));
                    stream_pushed_char(f) = NOT_CHAR;
                }
                return (int32_t)std::ftell(stream_file(f));
            case READ_END:
                return std::fseek(stream_file(f), 0L, SEEK_END);
            case READ_IS_CONSOLE:
                return 0;
            default:
                return 0;
        }
}

int32_t read_action_output_file(int32_t op, LispObject f)
{   if (op < -1) return std::fseek(stream_file(f), op & 0x7fffffff,
                                       SEEK_SET);
    else if (op <= 0x10ffff) return 0;
    else switch (op)
        {   case READ_TELL:
                op = std::ftell(stream_file(f));
                return op;
            case READ_END:
                return std::fseek(stream_file(f), 0L, SEEK_END);
            default:
                return 0;
        }
}

int32_t read_action_terminal(int32_t op, LispObject)
{   if (op < -1) return 1;
    else if (op <= 0x10ffff) return (terminal_pushed = op);
    else switch (op)
        {   case READ_CLOSE:
                return 0;
            case READ_FLUSH:
                terminal_pushed = NOT_CHAR;
                tty_count = 0;
                return 0;
            case READ_TELL:
                return -1;
            case READ_IS_CONSOLE:
                return 1;
            default:
                return 0;
        }
}

int32_t read_action_synonym(int32_t c, LispObject f)
{   int32_t r;
    LispObject f1;
    f1 = qvalue(stream_read_data(f));
//@@@    if (!is_stream(f1)) return aerror1("bad synonym stream", f1);
    if (!is_stream(f1))
    {
#if defined CONSERVATIVE && defined DEBUG
        cout << "bad synonym stream " << Addr(f1) << "\n";
        cout << "header = " << std::hex << static_cast<Header>(vechdr(f1))
             << std::dec << "\n";
        simple_print(stream_type(f));
        simple_print(stream_write_data(f));
#endif
        return aerror("bad synonym stream");
    }
    r = other_read_action(c, f1);
    if (c == READ_CLOSE)
    {   set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, nullptr);
    }
    return r;
}

int32_t read_action_concatenated(int32_t c, LispObject f)
{   int32_t r = 0, r1;
    LispObject l, f1;
    l = stream_read_data(f);
    THREADID;
    while (consp(l))
    {   f1 = car(l);
        l = cdr(l);
        if (!is_symbol(f1)) continue;
        f1 = qvalue(f1);
        if (!is_stream(f1)) continue;
        Save save(THREADARG l, f);
        r1 = other_read_action(c, f1);
        if (exceptionPending()) return r;
        save.restore(l, f);
        if (r == 0) r = r1;
    }
    if (c == READ_CLOSE)
    {   set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, nullptr);
    }
    return r;
}

int32_t read_action_list(int32_t op, LispObject f)
{   if (op < -1) return 1;
    else if (op <= 0x10ffff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                set_stream_read_fn(f, char_from_illegal);
                set_stream_read_other(f, read_action_illegal);
                set_stream_file(f, nullptr);
                stream_read_data(f) = nil;
                return 0;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
                return 0;
            case READ_TELL:
                return -1;
            case READ_IS_CONSOLE:
                return 0;
            default:
                return 0;
        }
}

int32_t read_action_vector(int32_t op, LispObject f)
{   if (op < -1) return 1;
    else if (op <= 0x10ffff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                set_stream_read_fn(f, char_from_illegal);
                set_stream_read_other(f, read_action_illegal);
                set_stream_file(f, nullptr);
                stream_read_data(f) = nil;
                return 0;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
                return 0;
            case READ_TELL:
                return -1;
            case READ_IS_CONSOLE:
                return 0;
            default:
                return 0;
        }
}

static int most_recent_read_point = 0;

inline LispObject Lread_sub(LispObject stream, int cursave)
{   if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    curchar = NOT_CHAR;
    most_recent_read_point = other_read_action(READ_TELL, stream);
    class save_stream_1
    {   LispObject *save;
        int cursave;
        DECLARETHREADID
    public:
        save_stream_1(DECLAREID LispObject stream, int cs) SETTHREADID
        {   *++stack = stream;
            save = stack;
            cursave = cs;
        }
        ~save_stream_1()
        {   stack = save;
            LispObject stream = *stack--;
            if (curchar != NOT_CHAR) other_read_action(curchar, stream);
            curchar = cursave;
            current_file = stream_type(stream);
        }
    };
    THREADID;
    save_stream_1 RAII(THREADARG stream, cursave);
    return read_s(stream);
}

// This class is rather like "Save" except that it specialises on where
// things should be restored to.

class save_reader_workspace
{   LispObject *save;
    DECLARETHREADID
public:
#ifdef NO_THREADS
    save_reader_workspace()
#else // NO_THREADS
    save_reader_workspace(uintptr_t id) : threadId(id)
#endif // NO_THREADS
    {   *++stack = reader_workspace;
        save = stack;
    }
    ~save_reader_workspace()
    {   stack = save;
        reader_workspace = *stack--;
    }
};

LispObject Lread(LispObject env)
// The full version of read_s() has to support extra optional args
// that deal with error and eof returns... and a recursive-p arg!
{   LispObject stream = qvalue(standard_input);
#ifdef COMMON
    THREADID;
    save_reader_workspace RAII OPTTHREAD;
    reader_workspace = nil;
    return Lread_sub(stream, curchar),
#else
    return Lread_sub(stream, curchar);
#endif
}

// This is an odd function that may help with diagnostics sometimes. Whenever
// READ is called it should make a record of the line number. If there is an
// issue (eg caused by mis-matched parentheses) then where-was-that can
// retrieve thsi information.

static LispObject Lwhere_was_that(LispObject env)
{   LispObject w;
#ifdef COMMON
    w = list3(current_file, fixnum_of_int(most_recent_read_point),
              packname_(CP));
#else
    w = list2(current_file, fixnum_of_int(most_recent_read_point));
#endif
    return onevalue(w);
}

class save_stream
{   LispObject *save;
    int cursave;
    DECLARETHREADID
public:
    save_stream(DECLAREID LispObject oldstream, int curchar) SETTHREADID
    {   *++stack = reader_workspace;
        *++stack = oldstream;
        save = stack;
        cursave = curchar;
    }
    ~save_stream()
    {   stack = save;
        LispObject stream;
        curchar = cursave;
        stream = *stack--;
        reader_workspace = *stack--;
// For this to be valid it is important that Lrds can never both succeed
// and lead to garbage collection (and hence potential relocation of the
// return value from this function. By good fortune I seem to be safe!
        Lrds(nil, stream);
    }
};

LispObject Lread(LispObject env, LispObject stream)
{   int cursave = curchar;
    THREADID;
    save_stream saver(THREADARG Lrds(stream, nil), cursave);
    reader_workspace = nil;
    read_failure = false;
    stream = qvalue(standard_input);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    curchar = NOT_CHAR;
    LispObject w = read_s(stream);
    if (curchar != NOT_CHAR) other_read_action(curchar, stream);
    return onevalue(w);
}

// compress is not a Common Lisp function, but it is another on those
// things that I want within my implementation for internal purposes as
// well as for real use.

int char_from_list(LispObject f)
{   LispObject ch = stream_pushed_char(f);
    int r = static_cast<int>(ch); // -1 for EOF else a Unicode value
    if (ch == NOT_CHAR)
    {   if (!consp(stream_read_data(f))) ch = EOF;
        else
        {   if (++kilo >= 1024)
            {   kilo = 0;
                io_now++;
            }
            ch = car(stream_read_data(f));
            stream_read_data(f) =
                static_cast<LispObject>(cdr(stream_read_data(f)));
        }
// here I tend towards generosity - a symbol stands for the first character
// of its name, and character objects and numbers (representing internal
// codes) are also permitted.  Incomplete gensyms are OK here - I just
// use the first character of the base of the name. Note that by "first
// character" I need to mean "character" not "byte"... so the values
// returned here can be up to 0x0010ffff.
        if (is_symbol(ch)) r = first_char(ch);
        else if (is_char(ch)) r = code_of_char(ch);
        else if (is_fixnum(ch)) r = int_of_fixnum(ch);
        else r = EOF;    // Bad item in the list
    }
    else stream_pushed_char(f) = NOT_CHAR;
    return r;
}

// The vector here is a vector of bytes but I want to return a character
// value, so I will need to be ready to decode utf-8 stuff.
int char_from_vector(LispObject f)
{   LispObject ch = stream_pushed_char(f);
    if (ch == NOT_CHAR)
    {   unsigned char *v = bit_cast<unsigned char *>(
                               static_cast<std::FILE *>(stream_file(f)));
        if (v == nullptr) ch = EOF;
        else
        {   if (++kilo >= 1024)
            {   kilo = 0;
                io_now++;
            }
            ch = *v++;
            if (ch >= 0xf0)
            {   ch = ((ch & 0x07) << 6) + (*v++ & 0x3f);
                ch = (ch << 6) + (*v++ & 0x3f);
                ch = (ch << 6) + (*v++ & 0x3f);
            }
            else if (ch >= 0xe0)
            {   ch = ((ch & 0x0f) << 6) + (*v++ & 0x3f);
                ch = (ch << 6) + (*v++ & 0x3f);
            }
            else if (ch > 0xc0)
            {   ch = ((ch & 0x1f) << 6) + (*v++ & 0x3f);
            }
            else if (ch >= 0x80) ch = '?'; // Invalid case
            if (ch == 0) ch = EOF;
            else set_stream_file(f, (std::FILE *)v);
        }
    }
    else stream_pushed_char(f) = NOT_CHAR;
    return ch;
}

LispObject read_from_vector(char *v)
{   int savecur = curchar;
    LispObject r;
    stream_read_data(lisp_work_stream) = nil;
    set_stream_read_fn(lisp_work_stream, char_from_vector);
    set_stream_read_other(lisp_work_stream, read_action_vector);
    stream_pushed_char(lisp_work_stream) = NOT_CHAR;
    set_stream_file(lisp_work_stream, (std::FILE *)v);
    read_failure = false;
    curchar = NOT_CHAR;
    r = read_s(lisp_work_stream);
    curchar = savecur;
    if (read_failure) return aerror("read-from-vector");
    return onevalue(r);
}

LispObject Lcompress(LispObject env, LispObject stream)
{   int savecur = curchar;
    stream_read_data(lisp_work_stream) = stream;
    set_stream_read_fn(lisp_work_stream, char_from_list);
    set_stream_read_other(lisp_work_stream, read_action_list);
    stream_pushed_char(lisp_work_stream) = NOT_CHAR;
    read_failure = false;
    curchar = NOT_CHAR;
    env = read_s(lisp_work_stream);
    stream_read_data(lisp_work_stream) = nil;
    curchar = savecur;
    if (read_failure) return aerror("compress");
    return onevalue(env);
}

// As against the old version this folds much of the internal working into
// this function to try to avoid overhead...

LispObject Llist_to_string(LispObject env, LispObject stream)
{   size_t n = 0;
    LispObject str;
    for (str=stream; consp(str); str=cdr(str)) n++;
    str = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    char *s = &celt(str, 0);
    size_t k;
    for (k=0; k<n; k++)
    {   LispObject ch = car(stream);
        stream = cdr(stream);
        int r;
        if (is_symbol(ch))
        {   ch = qpname(ch);
            switch (length_of_byteheader(vechdr(ch)))
            {   case CELL:
                    r = '?';
                    break;
// This is optimised for the situation where the symbol name is of length 1
// and the (single) character there is in the range U+00 to U+7f
                case CELL+1:
                    r = ucelt(ch, 0);
                    if (r <= 0x7f) break;
                    // drop-through
                default:
                    r = code_of_char(characterify_string(ch));
            }
        }
        else if (is_vector(ch) && is_string(ch))
        {   switch (length_of_byteheader(vechdr(ch)))
            {   case CELL:
                    r = '?';
                    break;
                case CELL+1:
                    r = ucelt(ch, 0);
                    if (r <= 0x7f) break;
                    // drop-through
                default:
                    r = code_of_char(characterify_string(ch));
            }
        }
        else if (is_char(ch)) r = code_of_char(ch);
        else if (is_fixnum(ch)) r = int_of_fixnum(ch);
        else r = '?';    // Bad item in the list
        *s++ = r;
    }
    for (; (k&7) != 0; k++) *s++ = 0; // zero-pad final doubleword
    return onevalue(str);
}

LispObject Llist_to_symbol(LispObject env, LispObject stream)
{   stream = Llist_to_string(nil, stream);
#ifdef COMMON
    stream = Lintern_2(nil, stream, CP);
    return onevalue(stream);  // NB intern would have returned 2 values
#else
    return Lintern(nil, stream);
#endif
}

LispObject Lstring2list(LispObject env, LispObject a)
{   Header h;
    LispObject r;
    size_t i, len;
#ifdef COMMON
    if (complex_stringp(a)
    {   a = simplify_string(a);
        errexit();
    }
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        errexit();
        h = vechdr(a);
    }
    else if (!is_vector(a) || !is_string_header(h = vechdr(a)))
        return aerror1("string2list", a);
    len = length_of_byteheader(h) - CELL;
    r = nil;
    THREADID;
    for (i=0; i<len; i++)
    {   int c = ucelt(a, len-1-i);
        Save save(THREADARG a);
        r = cons(fixnum_of_int(c), r);
        errexit();
        save.restore(a);
    }
    return r;
}

LispObject read_eval_print(int noisy)
{   THREADID;
    SaveStack stack_saver OPTTHREAD;
    for (;;)        // Loop for each s-expression found
    {   LispObject u;
#ifdef COMMON
        int32_t nvals, i;
#endif
        miscflags |= (HEADLINE_FLAG | FNAME_FLAG | ARGS_FLAG);
        errorset_msg = nullptr;
        bool keepGoing = false;
        TRY
            u = Lread(nil);
        CATCH(LispResource)
            RETHROW;
        ANOTHER_CATCH(LispRestart)
            RETHROW;
        ANOTHER_CATCH(LispException)
            err_printf("\n... read failed\n");
            if (stop_on_error) RETHROW;
            keepGoing = true;
        END_CATCH;
        if (keepGoing) continue;
// This will stop at end of file. That could EITHER be a real proper
// end of file, or the user having #\eof in the input file.  These are NOT
// equivalent, in that #\eof is read once and then further stuff from the
// stream can be read, while a real EOF (eg typing ^D at the terminal in
// some cases) ends the stream once and for all. well actually I do not
// want to close the stream for ever in case somebody did (rdf nil), so
// I tend to reset a bit of EOF info...
        if (u == eof_symbol)
        {
// If you had gone (rdf nil) and read from the terminal - and then used ctrl-D
// to signal an "and of file" I want that to end merely the (rdf) section
// of input and not everything. The offending end of file information would
// have ended up in terminal_pushed. The easiest way to cope that I have found
// clears a terminal EOF here regardless of whether (rdf) read from terminal
// or anything else - terminal_pushed should only get set to EOF when it
// reads from the terminal! Ditto terminal_eof_seen.
            if (terminal_pushed == EOF) terminal_pushed = NOT_CHAR;
            terminal_eof_seen = 0;
            return nil;
        }

        if (qvalue(standard_input) == lisp_terminal_io &&
            spool_file != nullptr &&
            non_terminal_input == nullptr) PUTC('\n', spool_file);

        miscflags |= (HEADLINE_FLAG | FNAME_FLAG | ARGS_FLAG);
        errorset_msg = nullptr;
        TRY
            exit_count = 1; // Because I care how many results are returned
            u = eval(u, nil);
        CATCH(LispResource)
            RETHROW;
        ANOTHER_CATCH(LispRestart)
            RETHROW;
        ANOTHER_CATCH(LispException)
            if (!stop_on_error) err_printf("\n... continuing after error\n");
            if (spool_file != nullptr) std::fflush(spool_file);
            if (stop_on_error) RETHROW;
            keepGoing = true;
        END_CATCH;
        if (keepGoing) continue;
        if (noisy)
        {
#ifndef COMMON
            ignore_error(print(u));
            stdout_printf("\n");
#else
            nvals = exit_count;
// These days I have to push mv_2 because print can call find-symbol to
// decide if it needs to display a package qualifier, and in that case
// it alters mv_2 on the way...  But at present it should never change
// any higher multiple value. I guess if it were interrupted then a break
// loop (if one existed) could corrupt almost anything, but I will
// ignore that worry.
            if (nvals > 0)
            {   Save save(THREADARG mv_2);
                ignore_error(print(u));
                save.restore(mv_2);
            }
            miscflags |= (HEADLINE_FLAG | FNAME_FLAG | ARGS_FLAG);
// Here I will demand that the print code does not use multiple-value
// procedures because if it did it might clobber the information stored in
// mv_2[] that is accessed here.
            for (i=2; i<=nvals; i++)
            {   Save save(THREADARG mv_2);
                if_error(print((&mv_2)[i-2]), break);
                save.restore(mv_2);
            }
            stdout_printf("\n");
#endif
        }
    }
    return nil;
}

// RDF is wanted as it is in Standard Lisp. In Common Lisp the corresponding
// function is LOAD. LOAD takes keyword arguments, which are decoded
// elsewhere, leaving the code here which takes a variable number of
// args, but all with definite simple interpretations. Note that
// (rdf nil) reads from whatever input is current. And (rdf) is treated
// as (rdf nil).

LispObject Lrdf4(LispObject env, LispObject file, LispObject noisyp,
                 LispObject verbosep, LispObject nofilep)
{   THREADID;
    save_current_function saver(THREADARG env);
    LispObject r = nil;
    int noisy = (noisyp != nil);
    int verbose = (verbosep != nil);
#ifdef COMMON
    int nofile = (nofilep != nil);
#else
    static_cast<void>(nofilep);
#endif
// (rdf nil)/(load nil) obeys Lisp commands from the current input
    STACK_SANITY;
// I have a somewhat comical chunk of code here. If the file-name passed
// across ends in a suffix that is one of ".o", ".fsl" or ".fasl" then
// instead of reading a textual source file the way one might have
// expected I will subvert things and perform LOAD-MODULE instead.
    LispObject stream=nil, oldstream = nil;
    if (file != nil)
    {   Header h;
        char *filestring;
        char tail[8];
        int32_t i, len;
#ifdef COMMON
        if (complex_stringp(file))
        {   file = simplify_string(file);
            errexit();
        }
#endif
        if (symbolp(file))
        {   file = get_pname(file);
            errexit();
            h = vechdr(file);
        }
        else if (!is_vector(file) || !is_string_header(h = vechdr(file)))
            return aerror1("load", file);
        len = length_of_byteheader(h) - CELL;
        filestring = bit_cast<char *>(file) + CELL-TAG_VECTOR;
        for (i=0; i<6; i++)
        {   if (len == 0)
            {   tail[i] = 0;
                break;
            }
            else tail[i] =
                static_cast<char>(std::tolower(
                    static_cast<unsigned char>(filestring[--len])));
        }
        if (std::strncmp(tail, "lsf.", 4) == 0 ||
            std::strncmp(tail, "lasf.", 5) == 0 ||
            std::strncmp(tail, "o.", 2) == 0)
        {   if (verbose)
            {   Save save(THREADARG file);
#ifdef COMMON
                trace_printf("\n;; Loading module ");
#else
                trace_printf("\nReading module ");
#endif
                errexit();
                prin_to_trace(file);
                errexit();
                trace_printf("\n");
                errexit();
                save.restore(file);
            }
            {   Save save(THREADARG file);
                Lload_module(nil, file);
                errexit();
                save.restore(file);
            }
            if (verbose)
            {
#ifdef COMMON
                trace_printf("\n;; Loaded module ");
#else
                trace_printf("\nRead module ");
#endif
                errexit();
                prin_to_trace(file);
                errexit();
                trace_printf("\n");
            }
#ifdef COMMON
            return onevalue(lisp_true);
#else
            return onevalue(nil);
#endif
        }
        {   Save save(THREADARG file);
#ifdef COMMON
            stream = r = Lopen(nil, file, fixnum_of_int(1+(nofile?64:0)));
#else
            stream = r = Lopen(nil, file, fixnum_of_int(1+64));
#endif
            errexit();
            save.restore(file);
#ifdef COMMON
// The test here is necessary since in Common Lisp mode an attempt to OPEN a
// file that can not be accessed returns NIL rather than raising an
// exception.
            if (r == nil)
            {   if (nofile) return error(1, err_open_failed, file);
                else return onevalue(nil);
            }
#endif
        }
        {   Save save(THREADARG file, stream);
            oldstream = r = Lrds(nil, r);
            save.restore(file, stream);
            if (verbose)
            {   Save save(THREADARG file, stream, oldstream);
#ifdef COMMON
                {   Save save1(THREADARG file);
                    trace_printf("\n;; Loading ");
                    errexit();
                    save1.restore(file);
                    prin_to_trace(file);
                    errexit();
                    trace_printf("\n");
                    errexit();
                }
#else
                {   Save save1(THREADARG file);
                    trace_printf("\nReading ");
                    errexit();
                    save1.restore(file);
                    prin_to_trace(file);
                    errexit();
                    trace_printf("\n");
                    errexit();
                }
#endif
                save.restore(file, stream, oldstream);
            }
        }
    }
    RealSave save(THREADARG file, stream, oldstream);
    LispObject &file1 = save.val(1);
    LispObject &stream1 = save.val(2);
    LispObject &oldstream1 = save.val(3);
    TRY
        read_eval_print(noisy);
    CATCH(LispException)
        int _reason = exit_reason;
        if (exit_reason == UNWIND_ERROR ||
            exit_reason == UNWIND_FNAME ||
            exit_reason == UNWIND_RESOURCE)
        {
#ifdef COMMON
            trace_printf("\n;; Loaded ");
#else
            trace_printf("\nFinished reading ");
#endif
            prin_to_trace(file1);
            trace_printf(" (bad)\n");
            if (stop_on_error) RETHROW;
        }
        if (file1 != nil)
        {   ignore_error(Lclose(nil, stream1));
            Lrds(nil, oldstream1);
        }
        exit_reason = _reason;
        RETHROW;
    END_CATCH
    if (verbose)
    {
#ifdef COMMON
        trace_printf("\n;; Loaded ");
#else
        trace_printf("\nFinished reading ");
#endif
    }
    prin_to_trace(file1);
    trace_printf("\n");
    if (file1 != nil)
    {   ignore_error(Lclose(nil, stream1));
        Lrds(nil, oldstream1);
    }
#ifdef COMMON
    return onevalue(lisp_true);
#else
    return onevalue(nil);
#endif
}

LispObject Lrdf0(LispObject env)
{   return Lrdf4(nil, nil, lisp_true, lisp_true, lisp_true);
}

LispObject Lrdf1(LispObject env, LispObject file)
{   return Lrdf4(env, file, lisp_true, lisp_true, lisp_true);
}

LispObject Lrdf2(LispObject env, LispObject file, LispObject noisy)
{   return Lrdf4(env, file, noisy, lisp_true, lisp_true);
}

LispObject Lrdf3(LispObject env, LispObject file, LispObject noisy,
                 LispObject verbose)
{   return Lrdf4(env, file, noisy, verbose, lisp_true);
}

LispObject Lrdfn(LispObject env, LispObject file, LispObject noisy,
                 LispObject verbose, LispObject nofile)
{   if (cdr(nofile) != nil) return aerror("too many args for rdf/load");
    nofile = car(nofile);
    return Lrdf4(env, file, noisy, verbose, nofile);
}

#ifdef COMMON
#define spool_name "dribble"
#else
#define spool_name "spool"
#endif

LispObject Lspool(LispObject env, LispObject file)
{   char filename[LONGEST_LEGAL_FILENAME];
    Header h;
    int32_t len;
    std::memset(filename, 0, sizeof(filename));
    if (spool_file != nullptr)
    {
#ifdef COMMON
        std::fprintf(spool_file, "\nFinished dribbling to %s.\n",
                     spool_file_name);
#else
        std::fprintf(spool_file, "\n+++ End of transcript +++\n");
#endif
        std::fclose(spool_file);
        spool_file = nullptr;
    }
    if (file == nil) return onevalue(lisp_true);
#ifdef COMMON
    if (complex_stringp(file)) file = simplify_string(file);
#endif
    if (symbolp(file))
    {   file = get_pname(file);
        h = vechdr(file);
    }
    if (!is_vector(file) || !is_string_header(h = vechdr(file)))
        return aerror1(spool_name, file);
    len = length_of_byteheader(h) - CELL;
    spool_file = open_file(filename,
                           bit_cast<char *>(file) + (CELL-TAG_VECTOR),
                           (size_t)len, "w", nullptr);
    if (spool_file != nullptr)
    {   std::time_t t0 = std::time(nullptr);
        std::strncpy(spool_file_name, filename, 32);
        spool_file_name[31] = 0;
#ifdef COMMON
        std::fprintf(spool_file, "Starts dribbling to %s (%.24s)\n",
                     spool_file_name, std::ctime(&t0));
#else
        std::fprintf(spool_file,
                     "+++ Transcript to %s started at %.24s +++\n",
                     spool_file_name, std::ctime(&t0));
#endif
        return onevalue(lisp_true);
    }
    return onevalue(nil);
}

static LispObject Lspool(LispObject env)
{   return Lspool(env, nil);
}

#ifdef COMMON

// The following two must be powers of 2
#define STARTING_SIZE_X 32
#define STARTING_SIZE_I 32

LispObject make_package(LispObject name)
// ... assuming that there is not already one with this name. Packages
// can grow as extra symbols are inserted into them, so I can reasonably
// start off with a very small package.
{   LispObject p, w;
    THREADID;
    {   Save save(THREADARG name);
        p = get_vector_init(sizeof(Package), nil);
        errexit();
        save.restore(name);
    }
    packhdr_(p) = TYPE_STRUCTURE + (packhdr_(p) & ~header_mask);
    packid_(p) = package_symbol;
    packname_(p) = name;
    {   Save save(THREADARG p);
        w = get_vector_init(STARTING_SIZE_X+CELL, fixnum_of_int(0));
        errexit();
        save.restore(p);
    }
    packext_(p) = w;
    {   Save save(THREADARG p);
        w = get_vector_init(STARTING_SIZE_I+CELL, fixnum_of_int(0));
        errexit();
        save.restore(p);
    }
    packint_(p) = w;
    packflags_(p) = fixnum_of_int(++package_bits);
    packnext_(p) = fixnum_of_int(0);
    packnint_(p) = fixnum_of_int(0);
    {   Save save(THREADARG p);
        w = cons(p, all_packages);
        errexit();
        save.restore(p);
    }
    all_packages = w;
    return onevalue(p);
}

static LispObject want_a_string(LispObject name)
{
#ifdef COMMON
    if (complex_stringp(name)) return simplify_string(name);
#endif
    if (symbolp(name)) return get_pname(name);
    else if (is_vector(name) &&
             is_string_header(vechdr(name))) return name;
    else return aerror1("name or string needed", name);
}

static LispObject Lfind_package(LispObject env, LispObject name)
// This should be given a string as an argument. If it is given a
// symbol it takes its pname as the string to be used.  It scans the list
// of all packages and returns the first that it finds where the name
// or a nickname matches the string passed in.
{   LispObject w;
    Header h;
    int32_t len;
    if (is_vector(name))
    {   h = vechdr(name);
        if (type_of_header(h) == TYPE_STRUCTURE &&
            packid_(name) == package_symbol) return onevalue(name);
    }
    name = want_a_string(name);
    h = vechdr(name);
    len = length_of_byteheader(h) - CELL;
    for (w = all_packages; w!=nil; w=cdr(w))
    {   LispObject nn, n = packname_(car(w));
        if (is_vector(n) && vechdr(n) == h &&
            std::memcmp(bit_cast<char *>(name) + (CELL-TAG_VECTOR),
                        bit_cast<char *>(n) + (CELL-TAG_VECTOR), (size_t)len) == 0)
            return onevalue(car(w));
        for (nn = packnick_(car(w)); nn!=nil; nn=cdr(nn))
        {   n = car(nn);
            if (!is_vector(n) || vechdr(n) != h) continue;
            if (std::memcmp(bit_cast<char *>(name) + (CELL-TAG_VECTOR),
                            bit_cast<char *>(n) + (CELL-TAG_VECTOR), (size_t)len) == 0)
                return onevalue(car(w));
        }
    }
    return onevalue(nil);
}

LispObject find_package(char *name, int len)
// This is like Lfind_package but takes a C string as its arg. Note that
// this can not cause garbage collection or return an error, so is safe to
// call from the middle of other things...
{   LispObject w;
    for (w = all_packages; w!=nil; w=cdr(w))
    {   LispObject nn, n = packname_(car(w));
        if (is_vector(n) &&
            length_of_byteheader(vechdr(n))==(uint32_t)(len+CELL) &&
            std::memcmp(name, bit_cast<char *>(n) + (CELL-TAG_VECTOR),
                        (size_t)len) == 0)
            return car(w);
        for (nn = packnick_(car(w)); nn!=nil; nn=cdr(nn))
        {   n = car(nn);
            if (!is_vector(n) ||
                length_of_byteheader(vechdr(n)) != (uint32_t)(len+CELL))
                continue;
            if (std::memcmp(name,
                            bit_cast<char *>(n) + (CELL-TAG_VECTOR), (size_t)len) == 0)
                return car(w);
        }
    }
    return nil;
}

static LispObject Luse_package(LispObject env, LispObject uses,
                               LispObject pkg)
{   THREADID;
    {   Save save(THREADARG uses);
        pkg = Lfind_package(nil, pkg);
        errexit();
        save.restore(uses);
    }
    if (pkg == nil) return onevalue(nil);
    if (consp(uses))
    {   while (consp(uses))
        {   Save save(THREADARG uses, pkg);
            Luse_package(nil, car(uses), pkg);
            errexit();
            save.restore(uses, pkg);
            uses = cdr(uses);
        }
    }
    else
    {   LispObject w, w1;
        Save save(THREADARG pkg);
        uses = Lfind_package(nil, uses);
        errexit();
        save.restore(pkg);
        if (uses == nil || uses == pkg) return onevalue(nil);
        {   Save save1(THREADARG pkg, uses);
// Around here I am supposed to do a large-scale check to ensure that there
// are no unexpected name conflicts between the packages that are being
// worked linked.
            w = cons(uses, packuses_(pkg));
            errexit();
            save1.restore(pkg, uses);
        }
        {   Save save1(THREADARG pkg, uses, w);
            w1 = cons(pkg, packused_(uses));
            errexit();
            save.restore(pkg, uses, w);
        }
        packuses_(pkg) = w;
        packused_(uses) = w1;
    }
    return onevalue(lisp_true);
}

LispObject ensureListOfStrings(LispObject l)
{   LispObject r = nil;
    THREADID;
    while (consp(l))
    {   Save save(THREADARG l, r);
        LispObject w = want_a_string(car(l));
        errexit();
        save.restore(l, r);
        Save save1(THREADARG l);
        r = cons(w, r);
        errexit();
        save1.restore(l);
        l = cdr(l);
    }
    l = nil;
    while (r != nil)
    {   LispObject w = r;
        r = cdr(w);
        cdr(w) = l;
        l = w;
    }
    return l;
}

// (de make!-package (packagename &key nicknames use) ...)
// so a call can be
//  (make!-package N)
//  (make!-package N :nicknames NN)
//  (make!-package N :nicknames NN :use U)
//  (make!-package N :use U)
//  (make!-package N :use U :nicknames NN)
// and there should be 1, 3 or 5 actual arguments.

static LispObject Lmake_package(LispObject env, LispObject name,
                                LispObject k1,
                                LispObject v1, LispObject kv2)
{   LispObject nicknames = nil, uses = nil, w = nil;
    bool has_nicknames = false, has_use = false;
    LispObject k2 = nil, v2 = nil;
    k2 = car(kv2);
    kv2 = cdr(kv2);
    if (kv2 == nil) return aerror("wrong number of arguments for make-package");
    v2 = car(kv2);
    kv2 = cdr(kv2);
    if (kv2 != nil) return aerror("wrong number of arguments for make-package");

    if (k1 == nicknames_symbol) nicknames = v1, has_nicknames = true;
    else if (k1 == use_symbol) uses = v1, has_uses = true;
// I will not permit other keys as k1.
    else return aerror1("make-package", k1);
// I will moan if a keyword is repeated.
    if (k2 == nicknames_symbol)
    {   if (has_nicknames) return aerror("make-package", k2);
        else nicknames = v2, has_nicknames = true;
    }
    else if (k2 == use_symbol)
    {   if (has_uses) return aerror1("make-package", k2);
        else uses = v2, has_uses = true;
    }
    else return aerror1("make-package", k2);
// Now name, nicknames and uses are set up. I will let uses default to the
// LISP package.
    THREADID;
    if (!has_use)
    {   Save save(THREADARG name, nicknames);
        uses = make_string("LISP");
        errexit();
        uses = ncons(uses);
        errexit();
        save.restore(name, nicknames);
    }
// Now I can begin the real work!
    STACK_SANITY;
// Now I need to ensure that the name I had for the package is
// a string...
    name = want_a_string(name);
    {   Save save(THREADARG name, nicknames, uses);
        w = Lfind_package(nil, name);
        errexit();
        save.restore(name, nicknames, uses);
    }
// It is SUPPOSED to be a continuable error if the package already exists.
// For the present I will just display a message and keep going.
    if (w != nil)
    {   Save save(THREADARG w, name);
        err_printf("\n+++++ package already exists: ");
        errexit();
        save.restore(w, name);
        Save.save1(THREADARG w, name);
        prin_to_error(name);
        errexit();
        err_printf("\n");
        errexit();
        save.restore(w, name);
        return onevalue(w);
    }
// The package does not exist yet - so I will make one...
    {   Save save(THREADARG nicknames, uses);
        name = make_package(name);
        errexit();
        save.restore(uses);
    }
// ensure that NICKNAMES is a list of strings...
    Save save(THREADARG name, uses);
    nickname = ensureListOfStrings(nicknames);
    errexit();
    save.restore(name, uses);
    packnick_(name) = nicknames;
    Save save1(THREADARG name);
    Luse_package(nil, uses, name);
    save1.restore(name);
    return onevalue(name);
}

static LispObject Lmake_package_3(LispObject env, LispObject a,
                                  LispObject b, LispObject c)
{   return Lmake_package(env, a, b, c, SPID_NOARG);
}

static LispObject Lmake_package_2(LispObject env, LispObject a,
                                  LispObject b)
{   return aerror("wrong number of arguments for make-package");
}

static LispObject Lmake_package_1(LispObject env, LispObject a)
{   return Lmake_package(env, a, SPID_NOARG, SPID_NOARG, SPID_NOARG);
}

static LispObject Llist_all_packagesstatic_cast<LispObject>()
{   return onevalue(all_packages);
}

#endif

LispObject Ltyi(LispObject env)
{   int ch;
    if (curchar == NOT_CHAR)
    {   LispObject stream = qvalue(standard_input);
        if (!is_stream(stream)) stream = qvalue(terminal_io);
        if (!is_stream(stream)) stream = lisp_terminal_io;
        ch = getc_stream(stream);
    }
    else
    {   ch = curchar;
        curchar = NOT_CHAR;
    }
    if (ch == EOF || ch == CTRL_D) return onevalue(CHAR_EOF);
// If tyi reads just a byte then this is what I want.  But if I want
// a character then somewhere I need to allow for wider characters than
// this.
    return onevalue(pack_char(0, ch & 0xff));
}

LispObject Lreadbyte(LispObject env, LispObject stream)
{   int ch;
    LispObject save = qvalue(echo_symbol);
    bool force = force_echo;
    force_echo = nil;
    if (!is_stream(stream))
        return aerror0("readb requires an appropriate stream");
    setvalue(echo_symbol, nil);
    raw_input = 1;
    ch = getc_stream(stream);
    raw_input = 0;
    force_echo = force;
    setvalue(echo_symbol, save);
// At one stage this code treated ^D as an end-of file marker - that is
// most nasty for binary files! The code should now be more transparent.
    if (ch == EOF) return fixnum_of_int(-1);
    else return fixnum_of_int(ch & 0xff);
}

LispObject Lreadch(LispObject env, LispObject stream)
{   LispObject w;
    int ch;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    ch = getc_stream(stream);  // may now be large value
    if (ch == EOF || ch == CTRL_D) w = eof_symbol;
    else
    {   if (ch <= 0xffff || sizeof(wchar_t)==4)
        {   if (qvalue(lower_symbol) != nil) ch = std::towlower(ch);
            else if (qvalue(raise_symbol) != nil) ch = std::towupper(ch);
        }
        w = char_to_id(ch);
    }
    return onevalue(w);
}

LispObject Lreadch(LispObject env)
{   return Lreadch(env, qvalue(standard_input));
}

LispObject Lpeekch2(LispObject env, LispObject type,
                    LispObject stream)
{   LispObject w;
    int ch;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (type != nil)
    {   do
        {   ch = getc_stream(stream);
        }
        while ((ch<=0xffff || sizeof(wchar_t)==4) && std::iswspace(ch));
    }
    else
    {   ch = getc_stream(stream);
    }
    other_read_action(ch, stream);
    if (ch == EOF || ch == CTRL_D) w = eof_symbol;
    else
    {   if (ch <= 0xffff || sizeof(wchar_t)==4)
        {   if (qvalue(lower_symbol) != nil) ch = std::towlower(ch);
            else if (qvalue(raise_symbol) != nil) ch = std::towupper(ch);
        }
        w = char_to_id(ch);
    }
    return onevalue(w);
}

LispObject Lpeekch(LispObject env, LispObject type)
{   return Lpeekch2(env, type, qvalue(standard_input));
}

LispObject Lpeekch(LispObject env)
{   return Lpeekch2(env, nil, qvalue(standard_input));
}

LispObject Lunreadch2(LispObject, LispObject a, LispObject stream)
{   int ch;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (a == eof_symbol || a == CHAR_EOF) ch = EOF;
    else
    {   if (is_symbol(a)) a = pack_char(0, first_char(a));
        ch = static_cast<char>(code_of_char(a));
    }
    other_read_action(ch, stream);
    return onevalue(a);
}

LispObject Lunreadch(LispObject env, LispObject a)
{   return Lunreadch2(env, a, qvalue(standard_input));
}

LispObject Lreadline1(LispObject env, LispObject stream)
{   LispObject w;
    int ch, n = 0;
    char *s;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    boffop = 0;
    while ((ch = getc_stream(stream)) != EOF && ch != '\n')
    {   if (ch != '\r') packcharacter(ch);
        n++;
    }
    if (ch == EOF && n == 0) w = eof_symbol;
    else
    {   w = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
        s = bit_cast<char *>(w) + CELL - TAG_VECTOR;
        std::memcpy(s, &boffo_char(0), n);
        while ((n&7) != 0) s[n++] = 0;
    }
#ifdef COMMON
    mv_2 = Lispify_predicate(ch == EOF);
#endif
    return nvalues(w, 2);
}

LispObject Lreadline(LispObject env)
{   return Lreadline1(env, qvalue(standard_input));
}

setup_type const read_setup[] =
{   DEF_0("batchp",         Lbatchp),
    {"rseek",               G0Wother, Lrseek, Lrseek_2, G3Wother, G4Wother},
#ifdef COMMON
    DEF_1("rseekend",       Lrseekend),
#endif
    {"rtell",               Lrtell, Lrtell_1, G2Wother, G3Wother, G4Wother},
    DEF_1("gensym1",        Lgensym),
    DEF_1("gensym2",        Lgensym2),
    DEF_1("gensymp",        Lgensymp),
    DEF_1("reset-gensym",   Lreset_gensym),
    DEF_1("getenv",         Lgetenv),
    DEF_2("orderp",         Lorderp),
    {"rdf",                 G0Wother, Lrdf1, Lrdf2, Lrdf3, Lrdfn},
    DEF_1("rds",            Lrds),
    {"peekch",              Lpeekch, Lpeekch, Lpeekch2, G3Wother, G4Wother},
    {"readch",              Lreadch, Lreadch, G2Wother, G3Wother, G4Wother},
    DEF_1("readb",          Lreadbyte),
    {"unreadch",            G0Wother, Lunreadch, Lunreadch2, G3W1, G4W1},
    {"readline",            Lreadline, Lreadline1, G2Wother, G3Wother, G4Wother},
    DEF_1("setpchar",       Lsetpchar),
    {"spool",               Lspool, Lspool, G2Wother, G3Wother, G4Wother},
    {"dribble",             Lspool, Lspool, G2Wother, G3Wother, G4Wother},
    DEF_1("system",         Lsystem),
    DEF_1("silent-system",  Lsilent_system),
    DEF_0("~tyi",           Ltyi),
    DEF_1("list-to-string", Llist_to_string),
    DEF_1("list2string",    Llist_to_string),
    DEF_1("list-to-symbol", Llist_to_symbol),
    DEF_1("string2list",    Lstring2list),
    DEF_0("where-was-that", Lwhere_was_that),
    DEF_1("compress",       Lcompress),
    DEF_1("compress1",      Lcompress),
    {"read",                Lread, Lread, G2Wother, G3Wother, G4Wother},
    {"intern",              G0Wother, Lintern, Lintern_2, G3Wother, G4Wother},
    {"gensym",              Lgensym, Lgensym, G2Wother, G3Wother, G4Wother},
    DEF_2("ordp",           Lorderp),
    {"unintern",            G0Wother, Lunintern, Lunintern, G3Wother, G4Wother},
    {"remob",               G0Wother, Lunintern, Lunintern, G3Wother, G4Wother},
    DEF_1("make-symbol",    Lmake_symbol),
    DEF_1("symbols-in",     Lsymbols_in),
    {"validate-package",    Lvalidate_package, Lvalidate_package, G2Wother, G3Wother, G4Wother},
#ifdef COMMON
// The package system...
    {"extern",              G0Wother, Lextern, Lextern, G3Wother, G4Wother},
    {"import*",             G0Wother, Limport, Limport, G3Wother, G4Wother},
    {"find-symbol",         G0Wother, Lfind_symbol, Lfind_symbol, G3Wother, G4Wother},
    DEF_1("find-package",   Lfind_package),
    {"make-package",        G0Wother, Lmake_package_1, Lmake_package_2, Lmake_package_3, LMake_package_4up},
    DEF_2("use-package*",   Luse_package),
    DEF_0("list-all-packages", Llist_all_packages),
#endif
    {nullptr,               nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of cslread.cpp
