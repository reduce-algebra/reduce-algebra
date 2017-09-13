// cslread.cpp                             Copyright (C) 1990-2017 Codemist

//
// Reading and symbol-table support.
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

#include "headers.h"

#ifdef SOCKETS
#include "sockhdr.h"
#endif

//
// At present CSL is single threaded - at least as regards file IO - and
// using the unlocked versions of putc and getc can be a MAJOR saving.
//

#ifdef HAVE_GETC_UNLOCKED
#define GETC(x) getc_unlocked((x))
#else
#ifdef HAVE__GETC_NOLOCK
#define GETC(x) _getc_nolock((x))
#else
#define GETC(x) getc((x))
#endif
#endif

#ifdef HAVE_PUTC_UNLOCKED
#define PUTC(x, y) putc_unlocked((x), (y))
#else
#ifdef HAVE__PUTC_NOLOCK
#define PUTC(x, y) _putc_nolock((x), (y))
#else
#define PUTC(x, y) putc((x), (y))
#endif
#endif

#define CTRL_C    3
#define CTRL_D    4

int first_char(LispObject ch)
{   // ch is a symbol. Get the first character of its name.
    ch = characterify(ch);
    return code_of_char(ch);
}

//
//      Basic version of Lisp reader.
//

static int curchar = NOT_CHAR;
FILE *non_terminal_input;

size_t boffop;

LispObject make_string(const char *b)
//
// Given a C string, create a Lisp (simple-) string.
//
{   size_t n = strlen(b);
    LispObject r = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    char *s = (char *)r - TAG_VECTOR;
    size_t k = doubleword_align_up(CELL+n);
    memcpy(s + CELL, b, (size_t)n);
    while (n < k) s[CELL+n++] = 0;
    validate_string(r);
    return r;
}

void validate_string_fn(LispObject s, const char *file, int line)
{   if (is_vector(s) && is_string_header(vechdr(s)))
    {   size_t len = length_of_byteheader(vechdr(s));
        size_t len1 = doubleword_align_up((uintptr_t)len);
        while (len < len1)
        {   if (celt(s, len-CELL) != 0)
            {   char *p = (char *)(s - TAG_VECTOR);
                size_t i;
                if (strrchr(file, '/') != NULL) file = strrchr(file, '/')+1;
                fprintf(stderr, "\n+++ Bad string at %s %d\n", file, line);
                fprintf(stderr, "Header = %" PRIxPTR "\n", vechdr(s));
                fprintf(stderr, "length = %d bytelength = %d\n",
                    (int)length_of_header(vechdr(s)),
                    (int)length_of_byteheader(vechdr(s)));
                fprintf(stderr, "messed at len:%d len1:%d [%x]\n",
                        (int)len, (int)len1, celt(s, len-CELL));
                for (i=0; i<len1; i++)
                {   fprintf(stderr, "%3d %p: %.2x   (%c)\n", (int)i, p, *p, *p);
                    p++;
                }
                fflush(stderr);
                *(int *)(LispObject)(-1) = 0x55555555;  // I hope this aborts
            }
            len++;
        }
        return;
    }
    fprintf(stderr, "\n+++ Not even a string at %s %d\n", file, line);
    fprintf(stderr, "Header = %" PRIxMAX "\n", (intmax_t)vechdr(s));
    fflush(stderr);
    *(int *)(LispObject)(-1) = 0x55555555;  // I hope this aborts
}

LispObject copy_string(LispObject str, size_t n)
//
// Given a Lisp string, plus its length, create a Lisp (simple-) string.
// NOTE that the "string" passed in may not in fact have the length
// you think it has - it may be boffo which is used as a string buffer.
//
{   LispObject r;
    char *s;
    size_t k;
    push(str);
    r = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
    pop(str);
    s = (char *)r - TAG_VECTOR;
    memcpy(s + CELL, (char *)str + (CELL-TAG_VECTOR), (size_t)n);
    k = doubleword_align_up(CELL+n)-CELL;
    while (n < k) s[CELL+n++] = 0;
    validate_string(r);
    return r;
}

LispObject Lbatchp(LispObject env)
{
//
// If the user had specified input files on the command line I will say that
// we are in batch mode even if there is a terminal present somewhere. So
// a run of the form
//     csl inputfile.lsp
// is a "batch" run, while
//     csl < inputfile.lsp
// will MAYBE also be noticed as batch, but do not count on it!
//
    if (non_terminal_input != NULL)
        return onevalue(batch_flag ? nil : lisp_true);
//
// "sysxxx.c" now decides if we are in "batch processing" context,
// in general by asking "isatty(fileno(stdin))" to see if stdin is
// attached to an interactive terminal.  Ideally this will say we are in
// batch mode if the user has redirected input from a file, as in
//       csl < xxx.lsp
// but catching such cases may be HARD with some operating systems.
// With some operating systems we will NEVER report ourselves as "batch".
//
    return onevalue(Lispify_predicate(batch_flag ? !batchp() : batchp()));
}

LispObject Lgetenv(LispObject env, LispObject a)
{   char parmname[LONGEST_LEGAL_FILENAME];
    Header h;
    memset(parmname, 0, sizeof(parmname));
#ifdef COMMON
    if (complex_stringp(a) a = simplify_string(a);
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        h = vechdr(a);
    }
    else if (!is_vector(a) || !is_string_header(h = vechdr(a)))
        aerror1("getenv", a);
    size_t len = length_of_byteheader(h) - CELL;
    memcpy(parmname, (char *)a + (CELL-TAG_VECTOR), (size_t)len);
    parmname[len] = 0;
    const char *w = my_getenv(parmname);
    if (w == NULL) return onevalue(nil);    // not available
    return onevalue(make_string(w));
}

LispObject Lsystem(LispObject env, LispObject a)
{   char parmname[LONGEST_LEGAL_FILENAME];
    Header h;
    memset(parmname, 0, sizeof(parmname));
    if (a == nil)            // enquire if command processor is available
    {   int w = my_system(NULL);
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
        aerror1("system", a);
    size_t len = length_of_byteheader(h) - CELL;
    memcpy(parmname, (char *)a + (CELL-TAG_VECTOR), (size_t)len);
    parmname[len] = 0;
    ensure_screen();
    int w = my_system(parmname);
    ensure_screen();
    return onevalue(fixnum_of_int(w));
}

#ifdef WIN32
//
// On Windows this version takes the trouble to avoid letting the
// application that you are running pop up a visible console window.
//

static LispObject Lsilent_system(LispObject env, LispObject a)
{   char cmd[LONGEST_LEGAL_FILENAME];
#ifdef SHELL_EXECUTE
    char args[LONGEST_LEGAL_FILENAME];
#endif
    Header h;
    memset(cmd, 0, sizeof(cmd));
#ifdef SHELL_EXECUTE
    memset(args, 0, sizeof(args));
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
        aerror1("system", a);
    ensure_screen();
    size_t len = length_of_byteheader(h) - CELL;
    memcpy(cmd, (char *)a + (CELL-TAG_VECTOR), (size_t)len);
    cmd[len] = 0;
#ifdef SHELL_EXECUTE
//
// ShellExecute works for me and allows me to launch an application with
// its console hidden - but it does not give an opportunity to wait until
// the command that was executed has completed. I will leave this code
// here for now since I may find I want to re-use it (eg for opening
// documents). But the code below that explicitly creates a process is
// what I really need here.
//
    size_t i = 0;
    while (cmd[i]!=' ' && cmd[i]!=0) i++;
    if (cmd[i]==0) args[0] = 0;
    else
    {   cmd[i] = 0;
        strcpy(args, &cmd[i+1]);
    }
    int rc = ShellExecute(NULL,
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
        memset(&startup, 0, sizeof(startup));
        startup.cb = sizeof(startup);
        startup.dwFlags = STARTF_USESHOWWINDOW;
        startup.wShowWindow = SW_HIDE;
        memset(&process, 0, sizeof(process));
        if (!CreateProcess(NULL, cmd, NULL, NULL, FALSE,
                           CREATE_NEW_CONSOLE,
                           NULL, NULL, &startup, &process))
        {   return onevalue(nil);
        }
        WaitForSingleObject(process.hProcess, INFINITE);
//
// If I fail to retrieve a true exit code I will return the value 1000. This
// is pretty arbitrary, but I expect 0 to denote success and 1000 to be an
// unusual "genuine" return code
//
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
//
// Other than on Windows I do not see any risk of "consoles" getting created
// when I do not want them, so this just does what the normal execution code
// does.
//
    return Lsystem(nil, a);
}

#endif

// This will only hash basic strings, not extended ones.

static uint64_t hash_lisp_string_with_length(LispObject s, size_t n)
{   uint64_t h = crc64(n-CELL, &basic_celt(s, 0), n-CELL);
// crc64 will produce a 64-bit hash value that is expected to be pretty
// reasonable, however the way I use this will be to look at just some
// number of low bits. The raw CRC does not cascade information evenly into
// all bits. To get the low-order bits better scrambled I will mix in some
// informationm from higher up. The shift amounts I use are chosen so they
// are not obvious multiples of 8, since the character sequences that I
// hash are streams of BYTES not BITS. The use of "+" rather than "^" to
// merge in information from high order bits lets carry propagation mix
// things up just a little more.
    h += h >> 31;
    h += h >> 7;
    h += h >> 15;
    return h + (h >> 12);    
}

uint64_t hash_lisp_string(LispObject s)
//
// Argument is a (lisp) string.  Return a 64 bit hash value.
//
{   return hash_lisp_string_with_length(s, length_of_byteheader(vechdr(s)));
}

static int value_in_radix(int c, int radix)
{   if (c < 0 || c > 0xff) return -1;
    if (isdigit(c)) c = c - '0';    // Assumes digit codes are consecutive
    else if (isalpha(c)) c = tolower(c) - 'a' + 10;
    else return -1;
    if (c < radix) return c;
    else return -1;
}

LispObject intern(size_t len, bool escaped)
//
// This takes whatever is in the first len characters of
// the Lisp string boffo, and maps it into a number, string
// or symbol as relevant.
//
{   size_t i;
    int numberp = escaped ? -1 : 0;
    int fplength = 2;
    bool explicit_fp_format = false;
    stackcheck0();
    for (i=0; i<len; i++)
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
                if (c <= 0xff && isdigit(c)) // Inspect *read-base* ?
                {   numberp = 2;
                    continue;
                }
                numberp = -1;
                break;
            case 2:
                if (c <= 0xff && isdigit(c)) continue;   // *read-base*
                switch (c)
                {   case '/':   numberp = 3;    continue;
                    case '.':   numberp = 5;    continue;
                    case 'e': case 'E':
//
// I now allow various exponent signifiers as per Common Lisp:
//   1.23e34    default (which is usually double)
//   1.23s34    short float - 28 bits
//   1.23f34    single float - 32 bits
//   1.23d34    double float - 64 bits
//   1.23l34    long float - 128 bits
//
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
                if (c <= 0xff && isdigit(c))   // *read-base*
                {   numberp = 4;
                    continue;
                }
                numberp = -1;
                break;
            case 5:
            case 8:
                if (c <= 0xff && isdigit(c))
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
                if (c <= 0xff && isdigit(c))
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
                if (c <= 0xff && isdigit(c))
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
{       default:
// Not a number... look up in package system
#ifdef COMMON
            if (!escaped && boffo_char(0) == ':')
            {   size_t i = 0;
                for (i = 0; i<boffop; i++) boffo_char(i) = boffo_char(i+1);
                boffop--;
                return iintern(boffo, boffop, qvalue(keyword_package), 0);
            }
#endif
            return iintern(boffo, boffop, CP, 0);


        case 5:         // Integer written as 12345.    (note trailing ".")
            boffo_char(--boffop) = 0; // ... trim off the trailing dot
        // drop through
        case 2:
//
// I speed up reading by working 7 digits at a time (using C integer
// arithmetic to gobble them) and only resorting to Lisp generic
// arithmetic to combine the chunks.
//
            if (boffo_char(0) == '+')
            {   for (size_t i = 0; i<boffop; i++)
                    boffo_char(i) = boffo_char(i+1);
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
//
// Beware bignum issue here... but take view that ratios are not used!
// I think I am expressing concern that a this ONLY deals with rational
// number input where both numerator and denominator are small enough to
// end up as fixnums, and it does not check for overflow. Thus 22/7 will
// be OK but 12345678987654321/3 will not. This is laziness I guess and
// some time ideally I would come and fix this so it uses the same
// strategy as used for bignums to read ratios with big numerators and/or
// denominators.
//
            boffo_char(boffop) = 0;
// p and q were made int not int32_t to match up with the %d in scanf ...
            sscanf((char *)&boffo_char(0), "%d/%d", &p, &q);
// Limit myself to fixnums here
            g = (int)int_of_fixnum(gcd(fixnum_of_int((int32_t)p),
                                       fixnum_of_int((int32_t)q)));
            p /= g;
            q /= g;
            if (q < 0)
            {   p = -p;
                q = -q;
            }
            r = get_basic_vector(TAG_NUMBERS, TYPE_RATNUM, sizeof(Rational_Number));
            numerator(r) = fixnum_of_int((int32_t)p);
            denominator(r) = fixnum_of_int((int32_t)q);
            return r;
        }
        case 8:
        case 11:
        {
//
// I want to enable this all the time, but if I am not in COMMON mode
// then before I do I need to get read_float_format set up properly.
//
#ifdef COMMON
            if (!explicit_fp_format && is_symbol(read_float_format))
            {   LispObject w = qvalue(read_float_format);
                if (w == short_float) fplength = 0;
                else if (w == single_float) fplength = 1;
                else if (w == double_float) fplength = 2;
                else if (w == long_float) fplength = 3;
            }
#else
            (void)explicit_fp_format;
#endif
            boffo_char(boffop) = 0;
            switch (fplength)
            {   case 0:
                    return pack_short_float(atof((char *)&boffo_char(0)));
                case 1:
                    return pack_single_float(atof((char *)&boffo_char(0)));
                default:
                case 2:
                    return make_boxfloat(atof((char *)&boffo_char(0)),
                                         TYPE_DOUBLE_FLOAT);
                case 3:
                    return make_boxfloat128(atof128((char *)&boffo_char(0)));
            }
        }
    }
}

LispObject make_undefined_symbol(char const *s)
{   return make_symbol(s, 0, undefined_0, undefined_1, undefined_2,
                             undefined_3, undefined_4up);
}

LispObject make_symbol(char const *s, int restartp,
                       no_args *f0, one_arg *f1, two_args *f2,
                       three_args *f3, fourup_args *f4up)
// Used from the startup code to create an interned symbol and (maybe)
// put something in its function cell.
{   LispObject v, v0 = nil;
    bool first_try = true;
//
// Here I blandly assume that boffo is long enough to hold the string
// that I am about to copy into it.  All is guaranteed well for
// symbols predefined in Lisp in the normal way, but ones established
// using command-line options like -Dname could cause trouble?
//
#ifdef COMMON
//
// For COMMON Lisp I will make all the built-in symbols upper case, unless
// the "2" bit of restartp is set...
//
    char const *p1 = s;
    char *p2 = (char *)&boffo_char(0);
    int c;
    if ((restartp & 2) == 0)
    {   while ((c = *p1++) != 0)
        {   c = toupper(c);
            *p2++ = c;
        }
        *p2 = 0;
    }
    else
#endif
        strcpy((char *)&boffo_char(0), s);
start_again:
    v = iintern(boffo, strlen((char *)&boffo_char(0)), CP, 0);
    if (first_try) v0 = v;
//
// I instate the definition given if (a) the definition is a real
// one (ie not for an undefined function) and if (b) either I am doing a cold
// start or the name is still marked as having a definition in the form
// of C code (or if I gave first_try false which is when I am going round
// again and doing rather curious things...)
//
    if (f1 != undefined_1)
    {   if ((restartp & 1)==0 || (qheader(v) & SYM_C_DEF) != 0 || !first_try)
        {   ifn0(v) = (intptr_t)f0;
            ifn1(v) = (intptr_t)f1;
            ifn2(v) = (intptr_t)f2;
            ifn3(v) = (intptr_t)f3;
            ifn4up(v) = (intptr_t)f4up;
            qheader(v) |= SYM_C_DEF;
        }
        else
        {   int l = strlen((char *)&boffo_char(0));
//
// Another piece of curious behaviour here, intend to make it easier to
// survive when the CSL/CCL kernel is extended. If a function that the
// (new) kernel would like to define as a C-coded thing is already in
// the current image either as undefined or with some other (byte-coded)
// definition, I map the name of the new function, and XYZ goes to ~XYZ etc
// by prefixing a '~'. The image as loaded can then access the new C coded
// function by this name, and possibly transfer it across to the normal
// name it was originally expected to have.  Since this is a symptom of
// somebody having done either a curious over-riding redefinition of something
// in the kernel or not having re-build to get new symbols properly available,
// I print a message about it. Note also that I only rename once, so if there
// were to be existing symbols with names that started with "~" that could
// make my attempts here less than fully effective.
//
// I am no longer certain that this is really a great help, and I may
// remove it soon!
//
            if (init_flags & INIT_VERBOSE)
                term_printf(
                    "+++ Built-in \"%s\" clashes with image file: => \"~%s\"\n",
                    &boffo_char(0), &boffo_char(0));
            while (l >= 0) boffo_char(l+1) = boffo_char(l), l--;
            boffo_char(0) = '~';
            first_try = false;
            goto start_again;
        }
//
// All things that have been set up as copies of this symbol must be
// initialised with the definition too. This happens even if the original
// symbol has been redefined and is not longer nice C code...
//
        if ((restartp & 1) != 0)
        {
//
// Note that I want to scan based on the ORIGINAL name of the function
// not on any version that has been renamed with a "~".
//
            LispObject v1 = get(v0, work_symbol, nil);
            while (consp(v1))
            {   LispObject w = qcar(v1);
                v1 = qcdr(v1);
                ifn0(w) = (intptr_t)f0;
                ifn1(w) = (intptr_t)f1;
                ifn2(w) = (intptr_t)f2;
                ifn3(w) = (intptr_t)f3;
                ifn4up(w) = (intptr_t)f4up;
            }
        }
    }
    return v;
}

static bool add_to_hash(LispObject s, LispObject vector, uint64_t hash)
//
// Adds an item into a hash table given that it is known that it is not
// already there.
//
{   size_t size = cells_in_vector(vector);
    size_t i = (size_t)(hash & (size-1));
//
// I have arranged (elsewhere) that the hash table will be a power of two
// in size, so I can avoid primary clustering by stepping on by any odd
// number.  Furthermore I might replace the (perhaps expensive) remaindering
// operations by (perhaps cheap) bitwise "AND" when I reduce my hash value
// to the right range to be an index into the table.
//
    size_t step = 1 | ((hash >> 10) & (size - 1));
    size_t probes = 0;
//
// size is expected to be a power of 2 here.
//
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

static LispObject rehash(LispObject v, int grow)
{
// If (grow) is +1 this enlarges the table. If -1 it shrinks it. In the
// case that the table is to shrink I should guarantee that the next smaller
// table size down will have enough space for the number of active items
// present. grow=0 leaves the table size alone but still rehashes.
    size_t h = cells_in_vector(v);
    if (grow > 0) h = 2*h;
    else if (grow < 0 && h > 64) h = h/2;
    stackcheck1(v);
    push(v);
    LispObject new_obvec = get_vector_init((h+1)*CELL, fixnum_of_int(0));
    v = stack[0];
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
    popv(1);
    return new_obvec;
}

#ifdef COMMON

static LispObject add_to_externals(LispObject s,
                                   LispObject p, uint64_t hash)
{   LispObject n = packnext_(p);
    LispObject v = packext_(p);
    size_t used = cells_in_vector(v);
//
// n is (16*sym_count+TAG_FIXNUM)             [Lisp fixnum for sym_count]
// used = CELL*(spaces+TAG_FIXNUM)
// The effect is that I trigger a re-hash if the table reaches 62%
// loading.  For small vectors when I re-hash I will double the
// table size, for large ones I will roughly multiply the amount of
// allocated space by 1.5.
// The effect will be that small packages will often be fairly lightly
// loaded (down to 31% just after an expansion) while very large ones will
// be kept at least a bit closer to the 62% mark.
//
    if ((uint32_t)n/10u > used/CELL)
    {   stackcheck3(s, p, v);
        push2(s, p);
        v = rehash(v, 1);
        pop2(p, s);
        packext_(p) = v;
    }
    packnext_(p) = n + (1<<4);      // increment as a Lisp fixnum
    add_to_hash(s, v, hash);
    return nil;
}

#endif

static LispObject add_to_internals(LispObject s,
                                   LispObject p, uint64_t hash)
{   LispObject n = packnint_(p);
    LispObject v = packint_(p);
    size_t used = cells_in_vector(v);
    if ((uint32_t)n/10u > used/CELL)
    {   stackcheck3(s, p, v);
        push2(s, p);
        v = rehash(v, 1);
        pop2(p, s);
        packint_(p) = v;
    }
    packnint_(p) = (LispObject)((int32_t)n + (1<<4));
    // increment as a Lisp fixnum
    add_to_hash(s, v, hash);
    return nil;
}

static bool rehash_pending = false;

#ifdef HASH_STATISTICS
uint64_t Nhget=0, Nhgetp=0, Nhput1=0, Nhputp1=0, Nhput2=0, Nhputp2=0, Nhputtmp=0;
uint64_t Noget=0, Nogetp=0, Noput=0, Noputp=0, Noputtmp=0;
#endif

// my_abort exists for two purposes. The first is so that it cal call
// ensure_screen() before aborting, so that buffered output at least stands
// a chance of being visible. The second is that it is a place I might
// reasonably set breakpoints.

void myabort()
{   ensure_screen();
    abort();
}

static LispObject lookup(LispObject str, size_t strsize,
                         LispObject v, uint64_t hash)
//
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
//
// January 2015: I now believe I can use a scheme hashing scheme that will
// behave much better than the one that I originally used.
// Firstly because of the misery that in CSL there is an upper limit
// on the size of vectors I still need to support segmented tables. Also
// note that the code here is quite separate from that in fns3.c where
// hash tables for direct use by users are iplemented. I ought to consolidate
// these two implementations of hashing!
//
{
#ifdef HASH_STATISTICS
    Noputtmp = 0;
#endif
    size_t size = cells_in_vector(v);
    size_t i = (size_t)(hash & (size - 1));
    size_t step = 1 | ((hash >> 10) & (size - 1));
//
// I count the probes that I make here and if there are as many as the size
// of the hash table then I allow the lookup to report that the symbol is not
// present. But at least I do not get stuck in a loop.
//
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
            Noputtmp++;  // A prob...
#endif
            if (memcmp((char *)str + (CELL-TAG_VECTOR),
                       (char *)pn + (CELL-TAG_VECTOR),
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
//
// Compare two symbols to see if they are in alphabetic order.
// Returns 0 is the symbols have the same name, otherwise
// the comparison is a lexical one on their names, with -ve if
// v1 comes alphabetically before v2.  Deals with gensyms, and in so
// doing has to allocate names for them, which seems a great misery
// since it means that this procedure can provoke garbage collection..
//
// Note that the ordering here is based on the bit-patterns that
// represent the names, and so will be driven by the utf-8 encoding of
// multibyte characters. I have not put in any adjustments that might
// make it match the expected lexical orderings in various locale-sensitive
// scenarios.
//
{   LispObject pn1 = qpname(v1), pn2 = qpname(v2);
    int c;
    size_t l1, l2;
#ifndef COMMON
    if (qheader(v1) & SYM_UNPRINTED_GENSYM)
    {   push(v2);
        pn1 = get_pname(v1);
        pop(v2);
        pn2 = qpname(v2);
    }
    if (qheader(v2) & SYM_UNPRINTED_GENSYM)
    {   push(pn1);
        pn2 = get_pname(v2);
        pop(pn1);
    }
#endif
    validate_string(pn1);
    validate_string(pn2);
    l1 = length_of_byteheader(vechdr(pn1)) - CELL;
    l2 = length_of_byteheader(vechdr(pn2)) - CELL;
    c = memcmp((char *)pn1 + (CELL-TAG_VECTOR),
               (char *)pn2 + (CELL-TAG_VECTOR),
               (size_t)(l1 < l2 ? l1 : l2));
    if (c == 0) c = (int)(l1 - l2);
    return c;
}

//
// This has been coded so that it provides the behavious that Reduce expects
// of ordp().  This is the REDUCE 3.6/3.7 version - it will need re-work
// if REDUCE is altered.  Note the curious situation that symbols are
// alphabetically ordered, EXCEPT that "nil" comes before everything else!
//
//
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
//

static int orderp(LispObject u, LispObject v);

static int ordpv(LispObject u, LispObject v)
{   Header hu = vechdr(u), hv = vechdr(v);
    size_t lu = length_of_header(hu), lv = length_of_header(hv), n = CELL;
    if (type_of_header(hu) != type_of_header(hv))
        return (type_of_header(hu) < type_of_header(hv) ? -1 : 1);
    if (vector_holds_binary(hu))
    {
// STRING, VEC8 and BPS need length_of_byteheader used here.
        switch (type_of_header(hu))
        {
        case TYPE_STRING_1:
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
        {   unsigned int eu = *(unsigned char *)(u - TAG_VECTOR + n),
                         ev = *(unsigned char *)(v - TAG_VECTOR + n);
            if (eu != ev) return (eu < ev ? -1 : 1);
            n += 1;
        }
        return (lu == lv ? 0 : lu < lv ? -1 : 1);
    }
//
// At present it is an ERROR to include mixed vectors in structures passed
// to ordering functions, and if it is done the system may crash.  Note that
// stream objects count as mixed for these purposes. I will get around to
// fixing things sometime...
//
    else
    {   while (n < lu && n < lv)
        {   LispObject eu = *(LispObject *)(u - TAG_VECTOR + n),
                       ev = *(LispObject *)(v - TAG_VECTOR + n);
            int w;
            push2(u, v);
            if (--countdown < 0) deal_with_tick();
            if (++reclaim_trigger_count == reclaim_trigger_target ||
                stack >= (LispObject *)stacklimit)
            {   push(ev);
                eu = reclaim(eu, "stack", GC_STACK, 0);
                pop(ev);
            }
            w = orderp(eu, ev);
            pop2(v, u);
            if (w != 0) return w;
            n += CELL;
        }
        return (lu == lv ? 0 : lu < lv ? -1 : 1);
    }
}

static int ordpl(LispObject u, LispObject v)
{   for (;;)
    {   int w = orderp(qcar(u), qcar(v));
        if (w != 0) return w;
        u = qcdr(u);
        v = qcdr(v);
        if (!consp(u)) return orderp(u, v);
        if (!consp(v)) return -1;
    }
}

#define flagged_noncom(v) \
    ((fv = qfastgets(v)) != nil && elt(fv, 0) != SPID_NOPROP)

static int orderp(LispObject u, LispObject v)
{   for (;;)
    {   if (u == nil) return v == nil ? 0 : 1;
        else if (v == nil) return -1;       // Special cases of NIL done
        else if (u == v) return 0;          // useful optimisation?
//
// I migrate the vectorp test inside where I have tested for atoms, since
// I expect vectors to be a somewhat uncommon case
//
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
//
// Now the objects are not symbols, vectors or numbers.  That maybe
// leaves character objects.  I compare representations to give a
// rather arbitrary ordering. Note that any comparisons that get
// down here are yielding non portable results.
//
                else return (u == v) ? 0 : (u < v) ? 1 : -1;
            }
            else return 1;
        }
        else if (!consp(v)) return -1;
        else
        {   LispObject cu = qcar(u), cv = qcar(v);
            LispObject fv;    // used by flagged_noncom
            int w;
            push2(u, v);
//          stackcheck2(cu, cv);
            if (--countdown < 0) deal_with_tick();
            if (++reclaim_trigger_count == reclaim_trigger_target ||
                stack >= (LispObject *)stacklimit)
            {   push(cv);
                cu = reclaim(cu, "stack", GC_STACK, 0);
                pop(cv);
            }
            w = orderp(cu, cv);
            pop2(v, u);
            if (w != 0)
            {   cu = qcar(u);
                if (is_symbol(cu) && flagged_noncom(cu))
                {   cv = qcar(v);
                    if (is_symbol(cv) && flagged_noncom(cv)) return w;
                    else return -1;
                }
                else
                {   cv = qcar(v);
                    if (is_symbol(cv) && flagged_noncom(cv)) return 1;
                    else return w;
                }
            }
//
// here car u = car v
//
            u = qcdr(u);
            v = qcdr(v);
            if (!consp(u)) continue;
            if (!consp(v)) return -1;
//
// The function I call ordpl here has the atom tests lifted out from
// its top...
//
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
//
// Searches a hash table for a symbol with name matching the given string,
// and remove it.
//
{   if (qheader(sym) & SYM_ANY_GENSYM) return false; // gensym case is easy!
    LispObject str = qpname(sym);
    validate_string(str);
#ifdef COMMON
// If not in any package it has no home & is not available
    qheader(sym) &= ~SYM_EXTERN_IN_HOME & ~(0xffffffff<<SYM_IN_PKG_SHIFT);
#endif
    uint64_t hash = removed_hash = hash_lisp_string(str);
//
// The search procedure used here MUST match that coded in lookup().
//
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
//
// Lisp function (make-symbol ..) creates an uninterned symbol.
//
{   LispObject s;
    stackcheck1(str);
//
// Common Lisp wants a STRING passed here, but as a matter of generosity and
// for the benefit of some of my system code I support symbols too.
//
    if (symbolp(str)) str = get_pname(str);
    else if (!is_vector(str)) aerror1("make-symbol", str);
    else if (complex_stringp(str)) str = simplify_string(str);
    else if (!is_string_header(vechdr(str))) aerror1("make-symbol", str);
    push(str);
    s = get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
    pop(str);
    qheader(s) = TAG_HDR_IMMED+TYPE_SYMBOL;
    qvalue(s) = unset_var;
    if (is_vector(str)) validate_string(str);
    qpname(s) = str;
    qplist(s) = nil;
    qfastgets(s) = nil;
    qpackage(s) = nil;
    qenv(s) = s;
    ifn0(s) = (intptr_t)undefined_0;
    ifn1(s) = (intptr_t)undefined_1;
    ifn2(s) = (intptr_t)undefined_2;
    ifn3(s) = (intptr_t)undefined_3;
    ifn4up(s) = (intptr_t)undefined_4up;
    qcount(s) = 0;      // set counts to zero to be tidy
    return onevalue(s);
}

LispObject Lgensym(LispObject env)
//
// Lisp function (gensym) creates an uninterned symbol with odd name.
//
{   LispObject id;
#ifdef COMMON
    LispObject pn;
    char genname[64];
#endif
    stackcheck0();
#ifdef COMMON
    sprintf(genname, "G%lu", (long unsigned)(uint32_t)gensym_ser++);
    pn = make_string(genname);
    push(pn);
#endif
    id = get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
#ifdef COMMON
    pop(pn);
#endif
#ifdef COMMON
    qheader(id) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM;
    qpname(id) = pn;
#else
    qheader(id) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_UNPRINTED_GENSYM+SYM_ANY_GENSYM;
    qpname(id) = gensym_base;
#endif
    qvalue(id) = unset_var;
    qplist(id) = nil;
    qfastgets(id) = nil;
    qpackage(id) = nil; // Marks it as a uninterned
    qenv(id) = id;
    ifn0(id) = (intptr_t)undefined_0;
    ifn1(id) = (intptr_t)undefined_1;
    ifn2(id) = (intptr_t)undefined_2;
    ifn3(id) = (intptr_t)undefined_3;
    ifn4up(id) = (intptr_t)undefined_4up;
    qcount(id) = 0;     // to be tidy

    return onevalue(id);
}

LispObject Lgensym0(LispObject env, LispObject a, const char *suffix)
{   LispObject id, genbase;
    size_t len, len1 = strlen(suffix);
    char genname[64];
#ifdef COMMON
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (is_vector(a) &&is_string_header(vechdr(a))) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);  // copy gensym base
    else aerror1("gensym0", a);
    push(genbase);
    stackcheck0();
    len = length_of_byteheader(vechdr(genbase)) - CELL;
    if (len > 63-len1) len = 63-len1; // Unpublished truncation of the string
    sprintf(genname, "%.*s%s", (int)len,
            (char *)genbase + (CELL-TAG_VECTOR), suffix);
    stack[0] = make_string(genname);
    id = get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
    pop(genbase);
#ifdef COMMON
    qheader(id) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM;
#else
    qheader(id) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_UNPRINTED_GENSYM+SYM_ANY_GENSYM;
#endif
    qvalue(id) = unset_var;
    qpname(id) = genbase;
    qplist(id) = nil;
    qfastgets(id) = nil;
    qpackage(id) = nil; // Marks it as a uninterned
    qenv(id) = id;
    ifn0(id) = (intptr_t)undefined_0;
    ifn1(id) = (intptr_t)undefined_1;
    ifn2(id) = (intptr_t)undefined_2;
    ifn3(id) = (intptr_t)undefined_3;
    ifn4up(id) = (intptr_t)undefined_4up;
    qcount(id) = 0;     // to be tidy
    return onevalue(id);
}

LispObject Lgensym1(LispObject env, LispObject a)
//
// Lisp function (gensym1 base) creates an uninterned symbol with odd name.
// The case (gensym <number>) is DEPRECATED by the Common Lisp standards
// committee and so I will not implement it at least for now.
//
{   LispObject id, genbase;
#ifdef COMMON
    size_t len;
    char genname[64];
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (is_vector(a) &&is_string_header(vechdr(a))) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);  // copy gensym base
    else aerror1("gensym1", a);
    push(genbase);
    stackcheck0();
#ifdef COMMON
    len = length_of_byteheader(vechdr(genbase)) - CELL;
    if (len > 60) len = 60;     // Unpublished truncation of the string
    sprintf(genname, "%.*s%lu", (int)len,
            (char *)genbase + (CELL-TAG_VECTOR),
            (long unsigned)(uint32_t)gensym_ser++);
    stack[0] = make_string(genname);
#endif
    id = get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
    pop(genbase);
#ifdef COMMON
    qheader(id) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM;
#else
    qheader(id) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_UNPRINTED_GENSYM+SYM_ANY_GENSYM;
#endif
    qvalue(id) = unset_var;
    qpname(id) = genbase;
    qplist(id) = nil;
    qfastgets(id) = nil;
    qpackage(id) = nil; // Marks it as a uninterned
    qenv(id) = id;
    ifn0(id) = (intptr_t)undefined_0;
    ifn1(id) = (intptr_t)undefined_1;
    ifn2(id) = (intptr_t)undefined_2;
    ifn3(id) = (intptr_t)undefined_3;
    ifn4up(id) = (intptr_t)undefined_4up;
    qcount(id) = 0;     // to be tidy
    return onevalue(id);
}

LispObject Lgensym2(LispObject env, LispObject a)
//
// Lisp function (gensym2 base) whose name is exactly that given by the
// argument.  This might be UNHELPFUL if one tried to print the value
// concerned, but seems to be what the Common Lisp syntax #:ggg expects
// to achieve!
//
{   LispObject id, genbase;
    size_t len;
#ifdef COMMON
    if (complex_stringp(a)) a = simplify_string(a);
#endif
    if (is_vector(a) &&is_string_header(vechdr(a))) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);
    else aerror1("gensym2", a);
    push(genbase);
    stackcheck0();
    len = length_of_byteheader(vechdr(genbase)) - CELL;
    stack[0] = copy_string(genbase, len);
    id = get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
    pop(genbase);
    qheader(id) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_ANY_GENSYM;
    qvalue(id) = unset_var;
    qpname(id) = genbase;
    qplist(id) = nil;
    qfastgets(id) = nil;
    qpackage(id) = nil; // Marks it as a uninterned
    qenv(id) = id;
    ifn0(id) = (intptr_t)undefined_0;
    ifn1(id) = (intptr_t)undefined_1;
    ifn2(id) = (intptr_t)undefined_2;
    ifn3(id) = (intptr_t)undefined_3;
    ifn4up(id) = (intptr_t)undefined_4up;
    qcount(id) = 0;     // to be tidy
    return onevalue(id);
}

static LispObject Lgensymp(LispObject env, LispObject a)
{   if (is_symbol(a) &&
        (qheader(a) & SYM_CODEPTR) == 0 &&
        (qheader(a) & SYM_ANY_GENSYM) != 0) return onevalue(lisp_true);
    else return onevalue(nil);
}

//
// Normally gensyms are displayed as G0, G1, ... in sequence.
// After (reset!=gensym 1234) thet go on from G1234.
// The function returns the previous gensym counter. So (reset!-gensym nil)
// will read that but not reset the sequence.
//

static LispObject Lreset_gensym(LispObject env, LispObject a)
{   LispObject old = gensym_ser;
    if (is_fixnum(a) && a >= 0) gensym_ser = int_of_fixnum(a) & 0x7fffffff;
    return fixnum_of_int(old);
}

LispObject iintern(LispObject str, size_t h, LispObject p, int str_is_ok)
//
// Look up the first h chars of the string str with respect to the package p.
// The last arg is a boolean that allows me to decide if (when a new symbol
// has to be created) the string must be copied.  If h differs from the
// real number of characters in arg1 then a copy MUST be made.
// If non-zero, the last arg is 1 for intern, 2 for extern, 3
// for find-symbol and 4 for "find-external-symbol" as in reader syntax p:x.
// NB in CSL mode only one value is returned.
//
{   LispObject r;
    stackcheck2(str, p);
    uint64_t hash = hash_lisp_string_with_length(str, h+CELL);
// find-external-symbol will not look at the internals
    if (str_is_ok != 4)
    {   r = lookup(str, h, packint_(p), hash);
//
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
//
        if (rehash_pending)
        {   LispObject v = packint_(p);
            push2(p, r);
            v = rehash(v, 0);
            pop2(r, p);
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
        push2(p, r);
        v = rehash(v, 0);
        pop2(r, p);
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
    for (r = packuses_(p); r!=nil; r=qcdr(r))
    {   LispObject w = qcar(r);
        w = lookup(str, h, packext_(w), hash);
        if (rehash_pending)
        {   LispObject v = packext_(p);
            push2(p, r);
            v = rehash(v, 0);
            pop2(r, p);
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
    {   LispObject s;
        push2(str, p);
// Here I was looking up a symbol and it did not exist so I need to
// create it.
#ifdef HASH_STATISTICS
        Noput++;
        Noputp += Noputtmp;
#endif
        s = (LispObject)get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
        pop(p);
        qheader(s) = TAG_HDR_IMMED+TYPE_SYMBOL;
#ifdef COMMON
        if (p == qvalue(keyword_package) && keyword_package != nil)
        {   qvalue(s) = (LispObject)s;
            qheader(s) |= SYM_KEYWORD_VAR;
        }
        else
#endif
            qvalue(s) = unset_var;
        qpname(s) = qpname(nil);    // At this stage the pname is a dummy
        qplist(s) = nil;
        qfastgets(s) = nil;
        qpackage(s) = p;
        qenv(s) = (LispObject)s;
        ifn0(s) = (intptr_t)undefined_0;
        ifn1(s) = (intptr_t)undefined_1;
        ifn2(s) = (intptr_t)undefined_2;
        ifn3(s) = (intptr_t)undefined_3;
        ifn4up(s) = (intptr_t)undefined_4up;
        qcount(s) = 0;
        push(s);
#ifdef COMMON
        if ((p == qvalue(keyword_package) && keyword_package != nil) ||
            str_is_ok == 2)
        {   add_to_externals(s, p, hash);
            qheader(s) |= SYM_EXTERN_IN_HOME;
        }
        else
#endif
            add_to_internals(s, p, hash);
        pop(s); pop(str);
// Now the symbol-head is safe enough that I can let the GC look at it
        if (str_is_ok != 0) qpname(s) = str;
        else
        {   LispObject pn;
            push(s);
            pn = copy_string(str, h);
            pop(s);
            qpname(s) = pn;
        }
        mv_2 = nil;
        return nvalues((LispObject)s, 2);
    }
}

#ifdef COMMON
static LispObject Lfind_package(LispObject env, LispObject name);
#endif

LispObject Lintern_2(LispObject env, LispObject str, LispObject pp)
{   return Lintern(env, str); // Ignores the package for now!
}

LispObject Lintern(LispObject env, LispObject str)
//
// Lisp entrypoint for (intern ..)
//
{   Header h;
    LispObject p;
#ifdef COMMON
    push(str);
    p = Lfind_package(nil, pp);
    pop(str);
#else
    p = CP;
#endif
#ifdef COMMON
    if (complex_stringp(str))
    {   push(p);
        str = simplify_string(str);
        pop(p);
    }
#endif
//
// For COMMON it is perhaps undue generosity to permit a symbol here
// rather than just a string.  However it will make life a bit easier for
// me in porting existing code.  Note that the Common Lisp book says quite
// explicitly that symbols are NOT allowed here.
//
    if (symbolp(str))
    {   push(p);
        str = get_pname(str);
        pop(p);
    }
    if (!is_vector(str) || !is_string_header(h = vechdr(str)))
        aerror1("intern (not a string)", str);
    return iintern(str, length_of_byteheader(h) - CELL, p, 1);
}

#ifdef COMMON

LispObject Lintern(LispObject env, LispObject a)
{   return Lintern_2(env, a, CP);
}

static LispObject Lfind_symbol(LispObject env, LispObject str, LispObject pp)
{   Header h;
    LispObject p;
    push(str);
    p = Lfind_package(nil, pp);
    pop(str);
    if (symbolp(str))
    {   push(p);
        str = get_pname(str);
        pop(p);
    }
    if (complex_stringp(str))
    {   push(p);
        str = simplify_string(str);
        pop(p);
    }
    if (!is_vector(str) || !is_string_header(h = vechdr(str)))
    {   aerror1("find-symbol (not a string)", str);
    }
    return iintern(str, length_of_byteheader(h) - CELL, p, 3);
}

LispObject Lfind_symbol_1(LispObject env, LispObject str)
{   return Lfind_symbol(env, str, CP);
}

static LispObject Lextern(LispObject env, LispObject sym, LispObject package)
//
// If sym is internal in given package make it external - the inside parts
// of the export function. Note that the second argument must be a real
// package object, not a package name. Higher level code must have done
// a find-package as necessary.
//
{   if (!is_symbol(sym)) return onevalue(nil);
    if (remob(sym, packint_(package)))
    {   LispObject n = packnint_(package);
        LispObject v = packint_(package);
        size_t used = length_of_header(vechdr(v)) - CELL;
//
// I will shrink a hash table if a sequence of remob-style operations,
// which will especially include the case where a symbol ceases to be
// internal to a package so that it can be external, leaves the table
// less than 25% full. Note that normal growth is supposed to leave these
// tables between 35 and 70% full, so the activity here will not be
// triggered frivolously.  However note the following oddity: if a package
// is of minimum size (8 entries in the hash table) then rehashing will not
// cause it to shrink (but it will rehash and hence tidy it up). Hence
// every remob on such a table will cause it to be re-hashed.
//
        if ((size_t)n < used && used>(CELL*INIT_OBVECI_SIZE+CELL))
        {   stackcheck3(sym, package, v);
            push2(sym, package);
            v = rehash(v), -1);
            pop2(package, sym);
            packint_(package) = v;
        }
        packnint_(package) -= (1<<4);   // decrement as fixnum
//
// removed_hash was left set up by remob, and it is known that the symbol
// was not already external, since it had been internal.
//
        if (qpackage(sym) == package) qheader(sym) |= SYM_EXTERN_IN_HOME;
        add_to_externals(sym, package, removed_hash);
        return onevalue(lisp_true);
    }
    return onevalue(nil);// no action if it was not internal in this package
}

static LispObject Lextern_1(LispObject env, LispObject str)
{   return Lextern(env, str, CP);
}

static LispObject Limport(LispObject env, LispObject sym, LispObject package)
//
// The internal part of the IMPORT and SHADOWING-IMPORT functions.
// makes sym internal in package. The symbol MUST NOT be present there
// before this function is called. The second argument must be a real
// package object, not just the name of one.
//
{   if (!is_symbol(sym)) return onevalue(nil);
    push2(sym, package);
    LispObject pn = get_pname(sym);
    uint64_t hash = hash_lisp_string(pn);
    add_to_internals(stack[-1], stack[0], hash);
    pop2(package, sym);
    if (qpackage(sym) == nil) qpackage(sym) = package;
    return onevalue(nil);
}

static LispObject Limport_1(LispObject env, LispObject str)
{   return Limport(env, str, CP);
}

#endif

LispObject ndelete(LispObject a, LispObject l)
//
// Probably useful in various places throughout the system...
//
{   if (!consp(l)) return l;
    if (a == qcar(l)) return qcdr(l);
    {   LispObject z1 = l, z2 = qcdr(l);
        while (consp(z2))
        {   if (a == qcar(z2))
            {   qcdr(z1) = qcdr(z2);
                return l;
            }
            else
            {   z1 = z2;
                z2 = qcdr(z2);
            }
        }
    }
    return l;
}

LispObject Lunintern_2(LispObject env, LispObject sym, LispObject pp)
{   LispObject package;
#ifdef COMMON
    push(sym);
    package = Lfind_package(nil, pp);
    pop(sym);
#else
    package = pp;
#endif
    if (!is_symbol(sym)) return onevalue(nil);
    if (qpackage(sym) == package) qpackage(sym) = nil;
#ifdef COMMON
    packshade_(package) = ndelete(sym, packshade_(package));
#endif
    if ((qheader(sym) & SYM_C_DEF) != 0)
        aerror1("remob on function with kernel definition", sym);
    if (remob(sym, packint_(package)))
    {   LispObject n = packnint_(package);
        LispObject v = packint_(package);
        size_t used = length_of_header(vechdr(v)) - CELL;
// I think that the next lien is playing silly whatsits wrt the representation
// of the fixnum n and its numeric meaning...
        if ((size_t)n < used && used>(CELL*INIT_OBVECI_SIZE+CELL))
        {   stackcheck2(package, v);
            push(package);
            v = rehash(v, -1);
            pop(package);
            packint_(package) = v;
        }
        packnint_(package) -= (1<<4);   // decrement as fixnum
        return onevalue(lisp_true);
    }
#ifdef COMMON
    if (remob(sym, packext_(package)))
    {   LispObject n = packnext_(package);
        LispObject v = packext_(package);
        size_t used = length_of_header(vechdr(v)) - CELL;
        else used = CHUNK_SIZE*used;
        if ((size_t)n < used && used>(CELL*INIT_OBVECX_SIZE+CELL))
        {   stackcheck2(package, v);
            push(package);
            v = rehash(v, -1);
            pop(package);
            packext_(package) = v;
        }
        packnext_(package) -= (1<<4);   // decrement as fixnum
        return onevalue(lisp_true);
    }
#endif
    return onevalue(nil);
}

LispObject Lunintern(LispObject env, LispObject str)
{   return Lunintern_2(env, str, CP);
}

//
// If I have a window system then getting characters from the keyboard
// is deemed a system-dependent activity.  On non-windowed systems I still
// do rather more than just getchar(), although under typical Unix what I
// do here may count as over-kill.
//

int tty_count;
#define TTYBUF_SIZE 1024
//
// Note: this buffer is in characters so putting either wide characters or
// EOF in it could be a problem. I make the buffer somewhat large because of
// the though of multi-byte characters.
//
static char tty_buffer[TTYBUF_SIZE];
static char *tty_pointer;

int terminal_pushed = NOT_CHAR;

static int kilo = 0;

static void wait_for_char()
{
    ensure_screen();
// I rather believe that EMBEDDED and WINDOW_SYSTEM should by mutually
// exclusive
#ifdef WINDOW_SYSTEM
    {   on_backtrace(tty_count = wimpget(tty_buffer),
            if (miscflags & HEADLINE_FLAG)
                err_printf("+++ Interrupted\n");
            exit_reason =
                (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                UNWIND_UNWIND;
            exit_value = exit_tag = nil;
            exit_count = 0);
        tty_pointer = tty_buffer;
        return;
    }
#else // WINDOW_SYSTEM
//
// Here I either do not have a window system or I have elected not to use it.
//
    fflush(stdout);
    fflush(stderr);
    for (;;) // The while loop is so I can restart after ^C
    {   errorset_msg = NULL;
        try
        {   START_SETJMP_BLOCK;
            while (tty_count<TTYBUF_SIZE && !interrupt_pending)
            {   int c;
// I really need to understand what to do here so that ^C gets processed
// properly even while I am suspended waiting for getchar() to return...
                c = getchar();
                if (c == EOF)
                {   clearerr(stdin);    // Believed to be what is wanted
                    c = CTRL_D;         // Use ASCII ^D as EOF marker
// I should perhaps use the UTF8 sequence f7/bf/bf/bf rather than 04?
                }
//
// If I fetched a wide character I would need to utf-8 encode it here...
// unless getchar has already delivered in that way.
//
                tty_buffer[tty_count++] = (char)c;
                if (c == '\n' || c == '\v' || c == CTRL_D) break;
            }
            if (interrupt_pending)
            {   interrupt_pending = false;
                interrupted(nil);
                tty_count = 0;
                continue;
            }
            break;
        }
        catch (LispSigint e)
        {   if (errorset_msg != NULL)
            {   term_printf("\n%s detected\n", errorset_msg);
                errorset_msg = NULL;
            }
            interrupt_pending = true;
            tty_count = 0;
        }
    }
    tty_pointer = tty_buffer;
#endif // WINDOW_SYSTEM
}

class RAIIpushed_clock
{
public:
    RAIIpushed_clock()
    {   push_clock();
    }
    ~RAIIpushed_clock()
    {   pop_clock();
    }
};

bool force_echo = false;

static int raw_char_from_terminal()
//
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
// some indication of an exception. Well actually ^C handling turns out to
// be WAY harder to implement nicely than I had expected, and it is not
// really under control at present.
//
//
{
    volatile int c;
    if (++kilo >= 1024)
    {   kilo = 0;
        io_now++;
    }
    if (terminal_pushed != NOT_CHAR)
    {   c = terminal_pushed;
        terminal_pushed = NOT_CHAR;
        return c;
    }
//
// I have a hook here for cases where I want to call CSL from other C
// code.  In that case the variable used here points at a function that
// reads a single character.  When I use this option I will NOT generate
// prompts.
//
    if (procedural_input != NULL) c = (*procedural_input)();
    else if (non_terminal_input != NULL)
    {   c = GETC(non_terminal_input);
    }
    else
    {   if (tty_count == 0)
        {   RAIIpushed_clock RAII_clock;
            wait_for_char();
        }
        if (tty_count == 0) c = '\n'; // ^C odd case
        else
        {   tty_count--;
            c = *tty_pointer++;
        }
    }
    inject_randomness(c);
    if (c == EOF || c == CTRL_D) return EOF;
    if (qvalue(echo_symbol) != nil || force_echo)
    {   LispObject stream = qvalue(standard_output);
        if (!is_stream(stream)) stream = qvalue(terminal_io);
        if (!is_stream(stream)) stream = lisp_terminal_io;
        ignore_error(putc_stream(c, stream));
    }
    else if (spool_file != NULL &&
             non_terminal_input == NULL) PUTC(c, spool_file);
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
    else if (!is_stream(a)) aerror1("rds", a);
    else if (stream_read_fn(a) == char_from_illegal)
        aerror("rds"); // closed stream or output stream
    qvalue(standard_input) = a;
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
//
// RTELL returns an integer that indicates the position of the current
// input stream (as selected by RDS). If the position is not available
// (as would be the case for an interactive stream) then NIL is returned.
// Otherwise the result is an integer suitable for use with rseek.  In the
// case that the file was opened in binary mode the number returned is a
// direct indication of the position in the file and arithmetic will
// behave predictably - for text streams the value returned should be
// thought of as an abstract position-tag.
//
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
    else aerror("rseek");
    other_read_action(READ_FLUSH, stream);
    if (other_read_action(n | 0x80000000, stream) != 0) return onevalue(nil);
    else return onevalue(lisp_true);
}

LispObject Lrseek(LispObject env, LispObject a)
//
// If the current input stream supports random access this re-positions
// it to a place indicated by the argument a.  If the file was opened in
// binary mode then a can be an integer indicating how far down the file
// to set the position.  For text files arguments to RSEEK should only be
// values returned by previous calls to RTELL.  RSEEK returns nil if it
// failed (and if it noticed that fact) or T if it succeeded.
//
{   return Lrseek_2(nil, qvalue(standard_input), a);
}

//
// The getc_stream() method must NEVER be able to cause garbage collection,
// since I code the reader here on the assumption that file control blocks
// do not move while individual characters are read.
//


//
// While I am in the middle of reading a whole expression the variable
// curchar will hold the most recent character (or NOT_CHAR if there is none),
// but between expressions I will push that back into the stream header.
//

static void skip_whitespace(LispObject stream)
{   for (;;)
    {   switch (curchar)
        {   case NOT_CHAR:
            case 0:    case '\v':   case '\f':
            case ' ':  case '\t':   case '\n':
            case '\r': case CTRL_C:
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
//
// There is no code here to do anything about general read-macros,
// and it will be awkward to fit it in here because of the reliance
// that the Common Lisp readmacro scheme puts on the ability to return
// no values at all using (values).  I implement ' and ; and ` since
// they seem very useful, but only simple cases of #.
// I require that when this function is called I have already done
// a skip_whitespace(), and as a result curchar will not be NOT_CHAR.
//
{   LispObject l, w;
    stackcheck0();
    if (curchar == ')')
    {   curchar = NOT_CHAR;
        return nil;
    }
    push(stream);
#ifdef COMMON
    if (curchar == '#')
    {   l = read_hash(stream);
        if (l == SPID_NOINPUT)
        {   pop(stream);
            return read_list(stream);
        }
    }
    else
#endif
        l = read_s(stream);
    l = ncons(l);
    push(l);    // this will be the final result
    for (;;)
    {   skip_whitespace(stack[-1]);
        switch (curchar)
        {

#ifndef COMMON
            case ']':
#endif
            case ')':
                curchar = NOT_CHAR;
                pop2(l, stream);
                return l;

            case EOF:
            case CTRL_D:
                pop2(l, stream);
                return l;

            // This code treats '.' as a special lexical marker, while the
            // full version of the reader has to be more subtle.
            case '.':
                curchar = NOT_CHAR;
                push(l);
                w = read_s(stack[-2]);
                pop(l);
                qcdr(l) = w;
                skip_whitespace(stack[-1]);
                if (curchar == ')') curchar = NOT_CHAR;
//          else error("missing rpar or bad dot");
                pop2(l, stream);
                return l;
#ifdef COMMON
            case '#':
                push(l);
                w = read_hash(stack[-2]);
                if (w == SPID_NOINPUT)
                {   pop(l);
                    continue;
                }
                w = ncons(w);
                pop(l);
                qcdr(l) = w;
                l = w;
                continue;
#endif
            default:
                push(l);
                w = read_s(stack[-2]);
                w = ncons(w);
                pop(l);
                qcdr(l) = w;
                l = w;
                continue;
        }
    }
}

static LispObject list_to_vector(LispObject l)
{   size_t len = 0;
    LispObject p = l;
    while (consp(p)) len++, p = qcdr(p);
    push(l);
    p = get_vector_init(CELL*(len+1), nil);
    pop(l);
    len = 0;
    while (consp(l))
    {   elt(p, len) = qcar(l);
        len++;
        l = qcdr(l);
    }
    return p;
}

#ifdef COMMON

static bool evalfeature(LispObject u)
{   LispObject w;
    if (consp(u))
    {   LispObject fn = qcar(u);
        u = qcdr(u);
        if (!consp(u)) return false;
        if (fn == not_symbol) return !evalfeature(qcar(u));
        else if (fn == and_symbol)
        {   while (consp(u))
            {   if (!evalfeature(qcar(u))) return false;
                u = qcdr(u);
            }
            return true;
        }
        else if (fn == or_symbol)
        {   while (consp(u))
            {   if (evalfeature(qcar(u))) return true;
                u = qcdr(u);
            }
            return false;
        }
        else return false;
    }
    w = qvalue(features_symbol);
    while (consp(w))
    {   if (u == qcar(w)) return true;
        w = qcdr(w);
    }
    return false;
}

static LispObject read_hash(LispObject stream)
{
//
// A small subset of the # escaped read-macros will be supported here.
// curchar must already be set to the character that follows the '#'
//
    int32_t v, w = -1;
    int radix;
    LispObject p;
    curchar = getc_stream(stream);
    if (curchar <= 0xff && isdigit(curchar))
    {   w = 0;
        do
        {   w = 10*w + curchar - '0';
//
// Observe that I do not do long arithmetic here!
//
            curchar = getc_stream(stream);
        }
        while (curchar <= 0xff && isdigit(curchar));
    }
    switch (curchar)
{       default:
//      error("Unknown # escape");
            return pack_char(0, '#');
#ifdef COMMON
        case '#':
            curchar = NOT_CHAR;
            p = reader_workspace;
            while (p != nil)
            {   LispObject k = qcar(p);
                if (fixnum_of_int(w) == qcar(k)) return qcdr(k);
                p = qcdr(p);
            }
            aerror1("Label not found with #n# syntax", fixnum_of_int(w));
        case '=':
            curchar = NOT_CHAR;
            push(stream);
//
// Hmmm - is it necessary for #nn# to refer back to the label here from
// within the value about to be read?
//
            p = read_s(stream);
            pop(stream);
            push(p);
            p = acons(fixnum_of_int(w), p, reader_workspace);
            reader_workspace = p;
            pop(p);
            return p;
#endif
        case ':':       // #:XXX reads in a gensym...
            curchar = NOT_CHAR;
            {   LispObject base = read_s(stream), al;   // The XXX bit unadorned
//
// This keeps an association list of gensyms present in this call to READ.
// Note that if you use #.(read) [or other clever things] you may get
// muddled about contexts.  Note that this is sometimes helpful with
// Standard Lisp but that for Common Lisp the more general #= and ##
// mechanism should be used and this behaviour here would count as
// WRONG.
//
                al = reader_workspace;
                while (al != nil)
                {   LispObject k = qcar(al);
                    if (base == qcar(k)) return qcdr(k);
                    al = qcdr(al);
                }
                push(base);
//
// Beware that #:ggg has just ggg as its name, with no numeric suffix.
//
                al = Lgensym2(nil, base);
                pop(base);
                al = acons(base, al, reader_workspace);
                reader_workspace = al;
                return qcdr(qcar(al));
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
//
// The character just after "#\" is read without any case folding
//
            curchar = getc_stream(stream);
            w = curchar;
#ifdef COMMON
//
// The word after "#\" is always spelt in regular ASCII so wide char support
// does not cut in here.
//
            if (w <= 0x7f && isalpha(w))
            {   char buffer[32];
                int bp = 0, w0 = w;
                while (w <= 0x7f && isalpha(w) && bp < 30)
                {   buffer[bp++] = toupper(w);  // Force word to upper case
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
//
// The next is in case the expression evaluated involves reading from
// this or another stream.
//
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
//
// In March 1988 X3J13 voted that feature names read here should be in
// the keyword package unless explicily otherwise qualified, but (I guess)
// the AND, OR and NOT operators applying to them are NOT in the keyword
// package. Thus I can not just rebind *package* here in any simple way.
// Oh dear - I hope nobody relies on what those kind experts decided!
// Meanwhile REMEMBER to go    #+ :whatever     please.
//
            push(stream);
            p = read_s(stream);
            w = evalfeature(p);
            pop(stream);
            if (w == v) read_s(stream);
//
// The following flag-value shows that read_hash() has not actually read
// anything - but it may have skipped over some unwanted stuff.
//
            return onevalue(SPID_NOINPUT);

        case 'r': case 'R':
            radix = (w>=2 && w<=36) ? (int)w : 10;
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
//
// case '_':    In OLD Standard Lisp underscore was a break character -
// these days it is classified rather oddly, in that it does not terminate
// a symbol but behaves specially if it starts one.
// What about '.', which may need to be treated specially?
//
        case '.':
#endif
            return false;
        default:
            return true;
    }
}

static LispObject backquote_expander(LispObject a)
//
// ClTl (edition 2) seems to suggest that nested backquotes are a disgusting
// morass - this code does not worry about the fine details!
//
{   LispObject w1, f;
    if (a == nil) return a;
    if (!consp(a)) return list2(quote_symbol, a);
    stackcheck1(a);
    f = qcar(a);
    if (f == comma_symbol) return qcar(qcdr(a));
    if (consp(f) && qcar(f) == comma_at_symbol)
    {   w1 = qcar(qcdr(f));
        push(w1);
        a = backquote_expander(qcdr(a));
        pop(w1);
        w1 = list2(w1, a);
        return cons(append_symbol, w1);
    }
//
// There is noticable scope for further optimisation here, with the
// introduction of uses of list, list* as well as just cons and append.
// It is also probably useful to worry about ,. as well as ,@ but for
// now I defer that until the full version of the reader is installed.
//
    push(a);
    f = backquote_expander(f);
    pop(a);
    push(f);
    a = backquote_expander(qcdr(a));
    pop(f);
    a = list2(f, a);
    return cons(cons_symbol, a);
}

static bool read_failure;

// Here c is a Unicode character - it gets expanded to UTF-8 format
// as necessary.

void packcharacter(int c)
{   size_t boffo_size = length_of_byteheader(vechdr(boffo));
//
// I expand boffo (maybe) several characters earlier than you might
// consider necessary. Some of that is to be extra certain about having
// space in it when I pack a multi-byte character.
//
    if (boffop >= boffo_size-CELL-8)
    {   LispObject new_boffo =
            get_basic_vector(TAG_VECTOR, TYPE_STRING_4, 2*boffo_size);
        memcpy((void *)((char *)new_boffo + (CELL-TAG_VECTOR)),
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
        memcpy((void *)((char *)new_boffo + (CELL-TAG_VECTOR)),
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

//
// Neither Standard nor Common Lisp make stray dots very welcome. In Common
// Lisp multiple adjacent dots are supposed to be an error. Here I just ignore
// stray dots, and hope that nobody is silly enough to have them in their code.
//
            case '.':
//          error("Bad dot");
                curchar = NOT_CHAR;
                continue;               // Ignore spurious dot

#ifdef COMMON
            case '#':
                push(stream);
                w = read_hash(stream);
                pop(stream);
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
                        {   push(stream);
                            packcharacter(curchar);
                            pop(stream);
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
                        {   push(stream);
                            packcharacter(curchar);
                            pop(stream);
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
//
// I treat numbers specially here since I want to allow '.' within
// numbers, but NOT within symbols.  Common Lisp views '.' as a
// constituent character and so does not need quite so much effort
// just here.
//
            {   boffop = 0;
                if (curchar == '+' || curchar == '-')
                {   push(stream);
                    packcharacter(curchar); // in fact char is Basic Latin
                    pop(stream);
                    curchar = getc_stream(stream);
// + or - not followed by a digit will be read as a symbol
                    if (curchar > 0xff || !isdigit(curchar))
                        return intern(boffop, false);
                }
                while (curchar <= 0xff && isdigit(curchar))
                {   push(stream);
                    packcharacter(curchar);  // Should be '0 to '9' (only)
                    pop(stream);
                    curchar = getc_stream(stream);
                }
// accept possible decimal point
                if (curchar == '.')
                {   push(stream);
                    packcharacter(curchar);
                    pop(stream);
                    curchar = getc_stream(stream);
                    while (curchar <= 0xff && isdigit(curchar))
                    {   push(stream);
                        packcharacter(curchar);
                        pop(stream);
                        curchar = getc_stream(stream);
                    }
                }
// accept possible exponent
                if (curchar == 'e' || curchar == 'E' ||
// Extend syntax to support more exponent signifiers. This is a change so
// that e.g "1.23D45" will now be parsed as one symbol not two.
                    curchar == 's' || curchar == 'S' ||
                    curchar == 'f' || curchar == 'F' ||
                    curchar == 'd' || curchar == 'D' ||
                    curchar == 'l' || curchar == 'L')
                {   push(stream);
                    packcharacter(curchar);
                    pop(stream);
                    curchar = getc_stream(stream);
                    if (curchar == '+' || curchar == '-')
                    {   push(stream);
                        packcharacter(curchar);
                        pop(stream);
                        curchar = getc_stream(stream);
                    }
                    while (curchar <= 0xff && isdigit(curchar))
                    {   push(stream);
                        packcharacter(curchar);
                        pop(stream);
                        curchar = getc_stream(stream);
                    }
                }
                return intern(boffop, false);
            }

            case '_':       // This seems to have to be a funny case for REDUCE
                boffop = 0;
                push(stream);
                packcharacter(curchar);
                pop(stream);
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
                {   stackcheck0();
                    curchar = getc_stream(stream);
                    within_vbars = !within_vbars;
//
// A funny thought arises here - maybe the characters ||123 are a potential
// number, since there are no characters inside the vertical bars to show
// otherwise! Hence I need to set escaped only when I find a genuine character
// within the vertical-bar protected region. Hence this coded as a while
// loop not a simple IF statement. Another horrid issue is that the input
// "|| " (where there are two initial vertical bars and then a terminating
// character) ought to parse as an identifier with an empty name. Thus
// if I read ahead here and find whitespace etc I need to exit here.
//
                    if (!within_vbars && !is_constituent(curchar))
                        return intern(0, true);
                }
#endif
                if (curchar == ESCAPE_CHAR)
                {   stackcheck0();
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
                                curchar = towlower(curchar);
                            else if (qvalue(raise_symbol) != nil)
                                curchar = towupper(curchar);
                        }
                    }

//
// Here is the main loop that reads an identifier. Observe the extra
// complication that Common Lisp generates with the need to support
// package markers and '|' style escapes...
//
                do
                {   push(stream);
                    packcharacter(curchar);
                    pop(stream);
                    curchar = getc_stream(stream);
#ifdef COMMON
                    if (within_vbars) escaped = true;
                    while (curchar == '|')
                    {   stackcheck0();
                        curchar = getc_stream(stream);
                        within_vbars = !within_vbars;
                    }
#endif
                    if (curchar == EOF) break;
                    else if (curchar == ESCAPE_CHAR)
                    {   stackcheck0();
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
                                curchar = towlower(curchar);
                            else if (qvalue(raise_symbol) != nil)
                                curchar = towupper(curchar);
                        }
#ifdef COMMON
                    }
                }
                while (within_vbars || is_constituent(curchar));
#else
                    } while (is_constituent(curchar));
#endif
#ifdef COMMON
//
// If there are no colons present, or if there are two but they
// are not consecutive, or of there are three or more, or if the last
// character of the symbol was a colon, I will just look it up in
// the current package.
//
                if (colon < 0 || colon+1==boffop)
                    return intern(boffop, escaped);
                if ((double_colon >= 0 && double_colon != colon+1) ||
                    double_colon+1==boffop)
                    return intern(boffop, escaped);
//
// If the first character was a colon I use the keyword package.
//
                memset(package_name, 0, sizeof(package_name));
                strncpy(package_name, &celt(boffo, 0), (size_t)colon);
                package_name[sizeof(package_name)-1] = 0;
// term_printf("Package lookup <%.*s>\n", (int)colon, &celt(boffo, 0));
                if (colon == 0) w = qvalue(keyword_package);
                else w = find_package(&celt(boffo, 0), colon);
//
// Here I rely on find_package never raising an exception and never giving
// a possible entry into a break loop (etc), since I need boffo[] intact
// after the call.
//
                if (w == nil)
                {   err_printf(
                        "+++ Package %s not found: using current package\n",
                        package_name);
//
// Similarly I assume, unreasonably, that boffo can not be disturbed by
// printing this warning message.
//
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
                    push(w);
                    wx = iintern(boffo, boffop, w, 4);
                    pop(w);
                    if (mv_2 == nil)
                    {   err_printf("+++ Symbol %.*s not external in %s\n",
                                   (int)boffop, &celt(boffo, 0), package_name);
                        err_printf("+++ Treating as internal symbol...\n");
                    }
                    else return wx;
                }
//
// Curiously I will always take keywords (as in :kkk) through the path
// that corresponds to looking up an internal symbol, ie ::kkk, since that
// way I allow the reader to create a new symbol. If I handled the keyword
// case in the usual external symbol way it would demand that the keyword
// already existed (since in all other packages nothing is external unless
// it already exists and has been exported).
//
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
    if (!is_stream(stream)) aerror1("bad synonym stream", stream);
    return getc_stream(stream);
}

int char_from_concatenated(LispObject stream)
{   LispObject l = stream_read_data(stream), s1;
    int c;
    while (consp(l))
    {   s1 = qcar(l);
        if (!is_symbol(s1))
        {   l = qcdr(l);
            stream_read_data(stream) = l;
            continue;
        }
        s1 = qvalue(s1);
        if (!is_stream(s1))
        {   l = qcdr(l);
            stream_read_data(stream) = l;
            continue;
        }
        push2(l, stream);
        c = getc_stream(s1);
        pop2(stream, l);
        if (c == EOF)
        {   l = qcdr(l);
            stream_read_data(stream) = l;
            continue;
        }
    }
    return EOF;
}

int char_from_echo(LispObject stream)
{   int c;
    LispObject stream1 = qvalue(stream_read_data(stream));
    if (!is_stream(stream1)) aerror1("bad synonym stream", stream1);
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
        aerror1("Illegal operation on stream",
                cons_no_gc(fixnum_of_int(op), stream_type(f)));
    return 0;
}

int32_t read_action_file(int32_t op, LispObject f)
{   if (op < -1) return fseek(stream_file(f), op & 0x7fffffff, SEEK_SET);
    else if (op <= 0x10ffff) return (stream_pushed_char(f) = op);
    else switch (op)
        {   case READ_CLOSE:
                if (stream_file(f) == NULL) op = 0;
                else op = fclose(stream_file(f));
                set_stream_read_fn(f, char_from_illegal);
                set_stream_read_other(f, read_action_illegal);
                set_stream_file(f, NULL);
                return op;
            case READ_FLUSH:
                stream_pushed_char(f) = NOT_CHAR;
                return 0;
            case READ_TELL:
                if ((op = stream_pushed_char(f)) != NOT_CHAR)
                {   ungetc(op, stream_file(f));
                    stream_pushed_char(f) = NOT_CHAR;
                }
                return (int32_t)ftell(stream_file(f));
            case READ_END:
                return fseek(stream_file(f), 0L, SEEK_END);
            case READ_IS_CONSOLE:
                return 0;
            default:
                return 0;
        }
}

int32_t read_action_output_file(int32_t op, LispObject f)
{   if (op < -1) return fseek(stream_file(f), op & 0x7fffffff, SEEK_SET);
    else if (op <= 0x10ffff) return 0;
    else switch (op)
        {   case READ_TELL:
                op = ftell(stream_file(f));
                return op;
            case READ_END:
                return fseek(stream_file(f), 0L, SEEK_END);
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
    if (!is_stream(f1)) aerror1("bad synonym stream", f1);
    r = other_read_action(c, f1);
    if (c == READ_CLOSE)
    {   set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, NULL);
    }
    return r;
}

int32_t read_action_concatenated(int32_t c, LispObject f)
{   int32_t r = 0, r1;
    LispObject l, f1;
    l = stream_read_data(f);
    while (consp(l))
    {   f1 = qcar(l);
        l = qcdr(l);
        if (!is_symbol(f1)) continue;
        f1 = qvalue(f1);
        if (!is_stream(f1)) continue;
        push2(l, f);
        r1 = other_read_action(c, f1);
        pop2(f, l);
        if (r == 0) r = r1;
    }
    if (c == READ_CLOSE)
    {   set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, NULL);
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
                set_stream_file(f, NULL);
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
                set_stream_file(f, NULL);
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

static inline LispObject Lread_sub(LispObject stream, int cursave)
{   if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    curchar = NOT_CHAR;
    most_recent_read_point = other_read_action(READ_TELL, stream);
    class save_stream
    {   LispObject *save;
        int cursave;
    public:
        save_stream(LispObject stream, int cs)
        {   push(stream);
            save = stack;
            cursave = cs;
        }
        ~save_stream()
        {   stack = save;
            LispObject stream;
            pop(stream);
            if (curchar != NOT_CHAR) other_read_action(curchar, stream);
            curchar = cursave;
            current_file = stream_type(stream);
        }
    };
    save_stream RAII(stream, cursave);
    return read_s(stream);
}

class save_reader_workspace
{   LispObject *save;
public:
    save_reader_workspace()
    {   push(reader_workspace);
        save = stack;
    }
    ~save_reader_workspace()
    {   stack = save;
        pop(reader_workspace);
    }
};

LispObject Lread(LispObject env)
//
// The full version of read_s() has to support extra optional args
// that deal with error and eof returns... and a recursive-p arg!
//
{   LispObject stream = qvalue(standard_input);
#ifdef COMMON
    save_reader_workspace RAII;
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
public:
    save_stream(LispObject oldstream, int curchar)
    {   push2(reader_workspace, oldstream);
        save = stack;
        cursave = curchar;
    }
    ~save_stream()
    {   stack = save;
        LispObject stream;
        curchar = cursave;
        pop2(stream, reader_workspace);
// For this to be valid it is important that Lrds can never both succeed
// and lead to garbage collection (and hence potential relocation of the
// return value from this function. By good fortune I seem to be safe! 
        Lrds(nil, stream);
    }
};

LispObject Lread_1(LispObject env, LispObject stream)
{   int cursave = curchar;
    save_stream RAII(Lrds(stream, nil), cursave);
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

//
// compress is not a Common Lisp function, but it is another on those
// things that I want within my implementation for internal purposes as
// well as for real use.
//

int char_from_list(LispObject f)
{   LispObject ch = stream_pushed_char(f);
    int r = (int)ch; // -1 for EOF else a Unicode value
    if (ch == NOT_CHAR)
    {   if (!consp(stream_read_data(f))) ch = EOF;
        else
        {   if (++kilo >= 1024)
            {   kilo = 0;
                io_now++;
            }
            ch = qcar(stream_read_data(f));
            stream_read_data(f) = qcdr(stream_read_data(f));
        }
//
// here I tend towards generosity - a symbol stands for the first character
// of its name, and character objects and numbers (representing internal
// codes) are also permitted.  Incomplete gensyms are OK here - I just
// use the first character of the base of the name. Note that by "first
// character" I need to mean "character" not "byte"... so the values
// returned here can be up to 0x0010ffff.
//
        if (is_symbol(ch)) r = first_char(ch);
        else if (is_char(ch)) r = code_of_char(ch);
        else if (is_fixnum(ch)) r = int_of_fixnum(ch);
        else r = EOF;    // Bad item in the list
    }
    else stream_pushed_char(f) = NOT_CHAR;
    return r;
}

//
// The vector here is a vector of bytes but I want to return a character
// value, so I will need to be ready to decode utf-8 stuff.
//
int char_from_vector(LispObject f)
{   LispObject ch = stream_pushed_char(f);
    if (ch == NOT_CHAR)
    {   unsigned char *v = (unsigned char *)stream_file(f);
        if (v == NULL) ch = EOF;
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
            else set_stream_file(f, (FILE *)v);
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
    set_stream_file(lisp_work_stream, (FILE *)v);
    read_failure = false;
    curchar = NOT_CHAR;
    r = read_s(lisp_work_stream);
    curchar = savecur;
    if (read_failure) aerror("read-from-vector");
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
    if (read_failure) aerror("compress");
    return onevalue(env);
}

LispObject Llist_to_string(LispObject env, LispObject stream)
{   int n = CELL, k;
    LispObject str;
    char *s;
    stream_read_data(lisp_work_stream) = stream;
    set_stream_read_fn(lisp_work_stream, char_from_list);
    set_stream_read_other(lisp_work_stream, read_action_list);
    stream_pushed_char(lisp_work_stream) = NOT_CHAR;
    while (consp(stream)) n++, stream = qcdr(stream);
    str = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, n);
    s = (char *)str + CELL - TAG_VECTOR;
    for (k=CELL; k<n; k++) *s++ = (char)char_from_list(lisp_work_stream);
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
    if (complex_stringp(a) a = simplify_string(a);
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        h = vechdr(a);
    }
    else if (!is_vector(a) || !is_string_header(h = vechdr(a)))
        aerror1("string2list", a);
    len = length_of_byteheader(h) - CELL;
    r = nil;
    for (i=0; i<len; i++)
    {   int c = ucelt(a, len-1-i);
        push(a);
        r = cons(fixnum_of_int(c), r);
        pop(a);
    }
    return r;
}

void read_eval_print(int noisy)
{   LispObject *save = stack;
    for (;;)        // Loop for each s-expression found
    {   volatile LispObject u;
#ifdef COMMON
        volatile int32_t nvals, i;
#endif
        miscflags |= (HEADLINE_FLAG | FNAME_FLAG | ARGS_FLAG);
        errorset_msg = NULL;
        try
        {   START_SETJMP_BLOCK;
            u = Lread(nil);
        }
        catch (LispSignal e)
        {   u = nil;
            if (errorset_msg != NULL)
            {   err_printf("\n%s detected\n", errorset_msg);
                errorset_msg = NULL;
            }
            unwind_stack(save, false);
            stack = save;
            signal(SIGFPE, low_level_signal_handler);
#ifdef USE_SIGALTSTACK
// SIGSEGV will be handled on the alternative stack
            {   struct sigaction sa;
                sa.sa_handler = low_level_signal_handler;
                sigemptyset(&sa.sa_mask);
                sa.sa_flags = SA_ONSTACK | SA_RESETHAND;
                if (segvtrap) sigaction(SIGSEGV, &sa, NULL);
            }
#else
            if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#endif
#ifdef SIGBUS
            if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
            if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
            err_printf("\n... read failed\n");
            errors_now++;
            if (errors_limit >= 0 && errors_now > errors_limit)
                resource_exceeded();
            else continue;
        }
        catch (LispResource e)
        {   throw;
        }
        catch (LispRestart e)
        {   throw;
        }
        catch (LispException e)
        {
//
// Maybe (stop) or (preserve) was called from a read-macro?  Otherwise
// errors reading are ignored and the system tries to read the next
// expression for evaluation.  Note that this behaviour means that
// perhaps unreasonably or unexpectedly, THROW will not be propagated
// back past a read_eval_print loop.
//
            err_printf("\n... read failed\n");
            if (stop_on_error) throw;
            continue;
        }
//
// This will stop at end of file. That could EITHER be a real proper
// end of file, or the user having #\eof in the input file.  These are NOT
// equivalent, in that #\eof is read once and then further stuff from the
// stream can be read, while a real EOF (eg typing ^D at the terminal in
// some cases) ends the stream once and for all. well actually I do not
// want to close the stream for ever in case somebody did (rdf nil), so
// I tend to reset a bit of EOF info...
//
        if (u == eof_symbol)
        {
//
// If you had gone (rdf nil) and read from the terminal - and then used ctrl-D
// to signal an "and of file" I want that to end merely the (rdf) section
// of input and not everything. The offending end of file information would
// have ended up in terminal_pushed. The easiest way to cope that I have found
// clears a terminal EOF here regardless of whether (rdf) read from terminal
// or anything else - terminal_pushed should only get set to EOF when it
// reads from the terminal! Ditto terminal_eof_seen.
//
            if (terminal_pushed == EOF) terminal_pushed = NOT_CHAR;
#ifdef WINDOW_SYSTEM
            terminal_eof_seen = 0;
#endif
            return;
        }

        if (qvalue(standard_input) == lisp_terminal_io &&
            spool_file != NULL &&
            non_terminal_input == NULL) PUTC('\n', spool_file);

        miscflags |= (HEADLINE_FLAG | FNAME_FLAG | ARGS_FLAG);
        errorset_msg = NULL;
        try
        {   START_SETJMP_BLOCK;
            try
            {   START_SETJMP_BLOCK;
                exit_count = 1; // Because I care how many results are returned
                u = eval(u, nil);
            }
            catch (LispResource e)
            {   throw;
            }
            catch (LispRestart e)
            {   throw;
            }
            catch (LispException e)
            {   err_printf("\n... continuing after error\n");
                if (spool_file != NULL) fflush(spool_file);
                if (stop_on_error) throw;
                continue;
            }
            if (noisy)
            {
#ifndef COMMON
                ignore_error(print(u));
                stdout_printf("\n");
#else
                nvals = exit_count;
//
// These days I have to push mv_2 because print can call find-symbol to
// decide if it needs to display a package qualifier, and in that case
// it alters mv_2 on the way...  But at present it should never change
// any higher multiple value. I guess if it were interrupted then a break
// loop (if one existed) could corrupt almost anything, but I will
// ignore that worry.
//
                if (nvals > 0)
                {   push(mv_2);
                    ignore_error(print(u));
                    pop(u);
                }
                mv_2 = u;
                miscflags |= (HEADLINE_FLAG | FNAME_FLAG | ARGS_FLAG);
//
// Here I will demand that the print code does not use multiple-value
// procedures because if it did it might clobber the information stored in
// mv_2[] that is accessed here.
//
                for (i=2; i<=nvals; i++)
                {   if_error(print((&mv_2)[i-2]), break);
                }
                stdout_printf("\n");
#endif
            }
        }
        catch (LispSignal e)
        {   if (errorset_msg != NULL)
            {   err_printf("\n%s detected\n", errorset_msg);
                errorset_msg = NULL;
            }
            unwind_stack(save, false);
            stack = save;
            signal(SIGFPE, low_level_signal_handler);
#ifdef USE_SIGALTSTACK
// SIGSEGV will be handled on the alternative stack
            {   struct sigaction sa;
                sa.sa_handler = low_level_signal_handler;
                sigemptyset(&sa.sa_mask);
                sa.sa_flags = SA_ONSTACK | SA_RESETHAND;
                if (segvtrap) sigaction(SIGSEGV, &sa, NULL);
            }
#else
            if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#endif
#ifdef SIGBUS
            if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
            if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
            err_printf("\n... continuing after error\n");
            if (spool_file != NULL) fflush(spool_file);
            errors_now++;
            if (stop_on_error) throw;
            if (errors_limit >= 0 && errors_now > errors_limit)
            {   resource_exceeded();
                return;
            }
            else continue;
        }
    }
}

//
// RDF is wanted as it is in Standard Lisp. In Common Lisp the corresponding
// function is LOAD. LOAD takes keyword arguments, which are decoded
// elsewhere, leaving the code here which takes a variable number of
// args, but all with definite simple interpretations. Note that
// (rdf nil) reads from whatever input is current. And (rdf) is treated
// as (rdf nil).
//

LispObject Lrdf4(LispObject env, LispObject file, LispObject noisyp,
                 LispObject verbosep, LispObject nofilep)
{   save_current_function saver(env);
    LispObject r = nil;
    int noisy = (noisyp != nil);
    int verbose = (verbosep != nil);
#ifdef COMMON
    int nofile = (nofilep != nil);
#else
    (void)nofilep;
#endif
//
// (rdf nil)/(load nil) obeys Lisp commands from the current input
//
    push3(nil, nil, file);
//
// I have a somewhat comical chunk of code here. If the file-name passed
// across ends in a suffix that is one of ".o", ".fsl" or ".fasl" then
// instead of reading a textual source file the way one might have
// expected I will subvert things and perform LOAD-MODULE instead.
//
    if (file != nil)
    {   Header h;
        char *filestring;
        char tail[8];
        int32_t i, len;
#ifdef COMMON
        if (complex_stringp(file)) file = simplify_string(file);
#endif
        if (symbolp(file))
        {   file = get_pname(file);
            h = vechdr(file);
        }
        else if (!is_vector(file) || !is_string_header(h = vechdr(file)))
            aerror1("load", file);
        len = length_of_byteheader(h) - CELL;
        filestring = (char *)file + CELL-TAG_VECTOR;
        for (i=0; i<6; i++)
        {   if (len == 0)
            {   tail[i] = 0;
                break;
            }
            else tail[i] = (char)tolower((unsigned char)filestring[--len]);
        }
        if (strncmp(tail, "lsf.", 4) == 0 ||
            strncmp(tail, "lasf.", 5) == 0 ||
            strncmp(tail, "o.", 2) == 0)
        {   stack[0] = file;
            if (verbose)
            {
#ifdef COMMON
                trace_printf("\n;; Loading module ");
#else
                trace_printf("\nReading module ");
#endif
                prin_to_trace(file); trace_printf("\n");
            }
            Lload_module(nil, stack[0]);
            if (verbose)
            {
#ifdef COMMON
                trace_printf("\n;; Loaded module ");
#else
                trace_printf("\nRead module ");
#endif
                prin_to_trace(stack[0]); trace_printf("\n");
            }
            popv(3);
#ifdef COMMON
            return onevalue(lisp_true);
#else
            return onevalue(nil);
#endif
        }

#ifdef COMMON
        stack[-1] = r = Lopen(nil, file, fixnum_of_int(1+(nofile?64:0)));
#else
        stack[-1] = r = Lopen(nil, file, fixnum_of_int(1+64));
#endif
#ifdef COMMON
//
// The test here is necessary since in Common Lisp mode an attempt to OPEN a
// file that can not be accessed returns NIL rather than raising an
// exception.
//
        if (r == nil)
        {   pop(file);
            popv(2);
            if (nofile) error(1, err_open_failed, file);
            else return onevalue(nil);
        }
#endif
        stack[-2] = r = Lrds(nil, r);
        if (verbose)
        {   file = stack[0];
#ifdef COMMON
            trace_printf("\n;; Loading "); prin_to_trace(file); trace_printf("\n");
#else
            trace_printf("\nReading "); prin_to_trace(file); trace_printf("\n");
#endif
        }
    }
    try
    {   START_SETJMP_BLOCK;
        read_eval_print(noisy);
    }
    catch (LispException e)
    {   int _reason = exit_reason;
        if (exit_reason == UNWIND_ERROR ||
            exit_reason == UNWIND_FNAME ||
            exit_reason == UNWIND_RESOURCE)
        {
#ifdef COMMON
            trace_printf("\n;; Loaded ");
#else
            trace_printf("\nFinished reading ");
#endif
            prin_to_trace(stack[0]);
            trace_printf(" (bad)\n");
            if (stop_on_error) throw;
        }
        if (stack[0] != nil)
        {   ignore_error(Lclose(nil, stack[-1]));
            Lrds(nil, stack[-2]);
        }
        popv(3);
        exit_reason = _reason;
        throw;
    }
    if (verbose)
    {
#ifdef COMMON
        trace_printf("\n;; Loaded ");
#else
        trace_printf("\nFinished reading ");
#endif
    }
    prin_to_trace(stack[0]);
    trace_printf("\n");
    if (stack[0] != nil)
    {   ignore_error(Lclose(nil, stack[-1]));
        Lrds(nil, stack[-2]);
    }
    popv(3);
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

LispObject Lrdf3(LispObject env, LispObject file, LispObject noisy, LispObject verbose)
{   return Lrdf4(env, file, noisy, verbose, lisp_true);
}

LispObject Lrdfn(LispObject env, LispObject file, LispObject noisy,
        LispObject verbose, LispObject nofile)
{   if (qcdr(nofile) != nil) aerror("too many args for rdf/load");
    nofile = qcar(nofile);
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
    memset(filename, 0, sizeof(filename));
    if (spool_file != NULL)
    {
#ifdef COMMON
        fprintf(spool_file, "\nFinished dribbling to %s.\n", spool_file_name);
#else
        fprintf(spool_file, "\n+++ End of transcript +++\n");
#endif
        fclose(spool_file);
        spool_file = NULL;
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
        aerror1(spool_name, file);
    len = length_of_byteheader(h) - CELL;
    spool_file = open_file(filename,
                           (char *)file + (CELL-TAG_VECTOR),
                           (size_t)len, "w", NULL);
    if (spool_file != NULL)
    {   time_t t0 = time(NULL);
        strncpy(spool_file_name, filename, 32);
        spool_file_name[31] = 0;
#ifdef COMMON
        fprintf(spool_file, "Starts dribbling to %s (%.24s)\n",
                spool_file_name, ctime(&t0));
#else
        fprintf(spool_file, "+++ Transcript to %s started at %.24s +++\n",
                spool_file_name, ctime(&t0));
#endif
        return onevalue(lisp_true);
    }
    return onevalue(nil);
}

static LispObject Lspool0(LispObject env)
{   return Lspool(env, nil);
}

#ifdef COMMON

// The following two must be powers of 2
#define STARTING_SIZE_X 32
#define STARTING_SIZE_I 32

LispObject make_package(LispObject name)
//
// ... assuming that there is not already one with this name. Packages
// can grow as extra symbols are inserted into them, so I can reasonably
// start off with a very small package.
//
{   LispObject p, w;
    push(name);
    p = get_vector_init(sizeof(Package), nil);
    pop(name);
    packhdr_(p) = TYPE_STRUCTURE + (packhdr_(p) & ~header_mask);
    packid_(p) = package_symbol;
    packname_(p) = name;
    push(p);
    w = get_vector_init(STARTING_SIZE_X+CELL, fixnum_of_int(0));
    pop(p);
    packext_(p) = w;
    push(p);
    w = get_vector_init(STARTING_SIZE_I+CELL, fixnum_of_int(0));
    pop(p);
    packint_(p) = w;
    packflags_(p) = fixnum_of_int(++package_bits);
    packnext_(p) = fixnum_of_int(0);
    packnint_(p) = fixnum_of_int(0);
    push(p);
    w = cons(p, all_packages);
    pop(p);
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
    else aerror1("name or string needed", name);
}

static LispObject Lfind_package(LispObject env, LispObject name)
//
// This should be given a string as an argument. If it is given a
// symbol it takes its pname as the string to be used.  It scans the list
// of all packages and returns the first that it finds where the name
// or a nickname matches the string passed in.
//
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
    for (w = all_packages; w!=nil; w=qcdr(w))
    {   LispObject nn, n = packname_(qcar(w));
        if (is_vector(n) && vechdr(n) == h &&
            memcmp((char *)name + (CELL-TAG_VECTOR),
                   (char *)n + (CELL-TAG_VECTOR), (size_t)len) == 0)
            return onevalue(qcar(w));
        for (nn = packnick_(qcar(w)); nn!=nil; nn=qcdr(nn))
        {   n = qcar(nn);
            if (!is_vector(n) || vechdr(n) != h) continue;
            if (memcmp((char *)name + (CELL-TAG_VECTOR),
                       (char *)n + (CELL-TAG_VECTOR), (size_t)len) == 0)
                return onevalue(qcar(w));
        }
    }
    return onevalue(nil);
}

LispObject find_package(char *name, int len)
//
// This is like Lfind_package but takes a C string as its arg. Note that
// this can not cause garbage collection or return an error, so is safe to
// call from the middle of other things...
//
{   LispObject w;
    for (w = all_packages; w!=nil; w=qcdr(w))
    {   LispObject nn, n = packname_(qcar(w));
        if (is_vector(n) &&
            length_of_byteheader(vechdr(n))==(uint32_t)(len+CELL) &&
            memcmp(name, (char *)n + (CELL-TAG_VECTOR), (size_t)len) == 0)
            return qcar(w);
        for (nn = packnick_(qcar(w)); nn!=nil; nn=qcdr(nn))
        {   n = qcar(nn);
            if (!is_vector(n) ||
                length_of_byteheader(vechdr(n)) != (uint32_t)(len+CELL))
                continue;
            if (memcmp(name,
                       (char *)n + (CELL-TAG_VECTOR), (size_t)len) == 0)
                return qcar(w);
        }
    }
    return nil;
}

static LispObject Luse_package(LispObject env, LispObject uses, LispObject pkg)
{   push(uses);
    pkg = Lfind_package(nil, pkg);
    pop(uses);
    if (pkg == nil) return onevalue(nil);
    if (consp(uses))
    {   while (consp(uses))
        {   push2(uses, pkg);
            Luse_package(nil, qcar(uses), pkg);
            pop2(pkg, uses);
            uses = qcdr(uses);
        }
    }
    else
    {   LispObject w, w1;
        push(pkg);
        uses = Lfind_package(nil, uses);
        pop(pkg);
        if (uses == nil || uses == pkg) return onevalue(nil);
        push2(pkg, uses);
//
// Around here I am supposed to do a large-scale check to ensure that there
// are no unexpected name conflicts between the packages that are being
// worked linked.
//
        w = cons(uses, packuses_(pkg));
        uses = stack[0];
        pkg = stack[-1];
        push(w);
        w1 = cons(pkg, packused_(uses));
        pop3(w, uses, pkg);
        packuses_(pkg) = w;
        packused_(uses) = w1;
    }
    return onevalue(lisp_true);
}

// (de make!-package (packagename &key nicknames use) ...)
// so a call can be
//  (make!-package N)
//  (make!-package N :nicknames NN)
//  (make!-package N :nicknames NN :use U)
//  (make!-package N :use U)
//  (make!-package N :use U :nicknames NN)
// and there should be 1, 3 or 5.

static LispObject Lmake_package(LispObject env, LispObject name, LispObject k1,
        LispObject v1, LispObject kv2)
{   LispObject nicknames = nil, uses = nil, w = nil
    bool has_nicknames = false, has_use = false;
    LispObject k2 = nil, v2 = nil;
    k2 = qcar(kv2);
    kv2 = qcdr(kv2);
    if (kv2 == nil) aerror("wrong number of arguments for make-package");
    v2 = qcar(kv2);
    kv2 = qcdr(kv2);
    if (kv2 != nil) aerror("wrong number of arguments for make-package");    if (k1 == nicknames_symbol) nicknames = v1;
    if (k1 == nicknames_symbol) nicknames = v1, has_nicknames = true;
    else if (k1 == use_symbol) uses = v1, has_uses = true;
// I will not permit other keys.
    else aerror1("make-package", k1);
// I will moan if a keyword is repeated.
    if (k2 == nicknames_symbol)
    {   if (hash_nicknames) aerror("make-package", k2);
        else nicknames = v2, has_nicknames = true;
    }
    else if (k2 == use_symbol)
    {   if (has_uses) aerror1("make-package", k2);
        else uses = v2, has_uses = true;
    }
    else aerror1("make-package", k2);
    if (!has_use)
    {   push2(name, nicknames);
        uses = make_string("LISP");
        uses = ncons(uses);
        pop2(nicknames, name);
    }
    push2(uses, nicknames);
//
// Now I need to ensure that the name I had for the package is
// a string...
//
    name = want_a_string(name);
    push(name);
    w = Lfind_package(nil, name);
    pop(name);
//
// It is SUPPOSED to be a continuable error if the package already exists.
// For the present I will just display a message and keep going.
//
    if (w != nil)
    {   popv(2);
        err_printf("\n+++++ package already exists: ");
        prin_to_error(name);
        err_printf("\n");
        return onevalue(w);
    }
//
// The package does not exist yet - so I will make one...
//
    name = make_package(name);
//
// ensure that NICKNAMES is a list of strings...
//
    uses = nil;
    while (consp(stack[0]))
    {   w = stack[0];
        push(uses);
        w = want_a_string(qcar(w));
        pop(uses);
        uses = cons(w, uses);
        stack[0] = qcdr(stack[0]);
    }
    nicknames = nil;
    while (uses != nil)
    {   w = uses;
        uses = qcdr(w);
        qcdr(w) = nicknames;
        nicknames = w;
    }
    popv(1);
    packnick_(name) = nicknames;
    uses = stack[0];
    stack[0] = name;
    Luse_package(nil, uses, name);
    pop(name);
    return onevalue(name);
}

static LispObject Lmake_package_3(LispObject env, LispObject a, LispObject b, LispObject c)
{   return Lmake_package(env, a, b, c, SPID_NOARG);
}

static LispObject Lmake_package_2(LispObject env, LispObject a, LispObject b)
{   aerror("wrong number of arguments for make-package");
}

static LispObject Lmake_package_1(LispObject env, LispObject a)
{   return Lmake_package(env, a, SPID_NOARG, SPID_NOARG, SPID_NOARG);
}

static LispObject Llist_all_packages(LispObject)
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
//
// If tyi reads just a byte then this is what I want.  But if I want
// a character then somewhere I need to allow for wider characters than
// this.
//
    return onevalue(pack_char(0, ch & 0xff));
}

LispObject Lreadbyte(LispObject env, LispObject stream)
{   int ch;
    LispObject save = qvalue(echo_symbol);
    bool force = force_echo;
    force_echo = nil;
    if (!is_stream(stream)) aerror0("readb requires an appropriate stream");
    qvalue(echo_symbol) = nil;
    raw_input = 1;
    ch = getc_stream(stream);
    raw_input = 0;
    force_echo = force;
    qvalue(echo_symbol) = save;
//
// At one stage this code treated ^D as an end-of file marker - that is
// most nasty for binary files! The code should now be more transparent.
//
    if (ch == EOF) return fixnum_of_int(-1);
    else return fixnum_of_int(ch & 0xff);
}

LispObject Lreadch1(LispObject env, LispObject stream)
{   LispObject w;
    int ch;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    ch = getc_stream(stream);  // may now be large value
    if (ch == EOF || ch == CTRL_D) w = eof_symbol;
    else
    {   if (ch <= 0xffff || sizeof(wchar_t)==4)
        {   if (qvalue(lower_symbol) != nil) ch = towlower(ch);
            else if (qvalue(raise_symbol) != nil) ch = towupper(ch);
        }
        w = char_to_id(ch);
    }
    return onevalue(w);
}

LispObject Lreadch(LispObject env)
{   return Lreadch1(env, qvalue(standard_input));
}

LispObject Lpeekch2(LispObject env, LispObject type, LispObject stream)
{   LispObject w;
    int ch;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (type != nil)
    {   do
        {   ch = getc_stream(stream);
        }
        while ((ch<=0xffff || sizeof(wchar_t)==4) && iswspace(ch));
    }
    else
    {   ch = getc_stream(stream);
    }
    other_read_action(ch, stream);
    if (ch == EOF || ch == CTRL_D) w = eof_symbol;
    else
    {   if (ch <= 0xffff || sizeof(wchar_t)==4)
        {   if (qvalue(lower_symbol) != nil) ch = towlower(ch);
            else if (qvalue(raise_symbol) != nil) ch = towupper(ch);
        }
        w = char_to_id(ch);
    }
    return onevalue(w);
}

LispObject Lpeekch1(LispObject env, LispObject type)
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
        ch = (char)code_of_char(a);
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
    {
        w = get_basic_vector(TAG_VECTOR, TYPE_STRING_4, CELL+n);
        s = (char *)w + CELL - TAG_VECTOR;
        memcpy(s, &boffo_char(0), n);
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
{   {"batchp",                  Lbatchp, G1W0, G2W0, G3W0, G4W0},
    {"rseek",                   G0Wother, Lrseek, Lrseek_2, G3Wother, G4Wother},
#ifdef COMMON
    {"rseekend",                G0W1, Lrseekend, G2W1, G3W1, G4W1},
#endif
    {"rtell",                   Lrtell, Lrtell_1, G2Wother, G3Wother, G4Wother},
    {"gensym1",                 G0W1, Lgensym1, G2W1, G3W1, G4W1},
    {"gensym2",                 G0W1, Lgensym2, G2W1, G3W1, G4W1},
    {"gensymp",                 G0W1, Lgensymp, G2W1, G3W1, G4W1},
    {"reset-gensym",            G0W1, Lreset_gensym, G2W1, G3W1, G4W1},
    {"getenv",                  G0W1, Lgetenv, G2W1, G3W1, G4W1},
    {"orderp",                  G0W2, G1W2, Lorderp, G3W2, G4W2},
    {"rdf",                     G0Wother, Lrdf1, Lrdf2, Lrdf3, Lrdfn},
    {"rds",                     G0W1, Lrds, G2W1, G3W1, G4W1},
    {"peekch",                  Lpeekch, Lpeekch1, Lpeekch2, G3Wother, G4Wother},
    {"readch",                  Lreadch, Lreadch1, G2Wother, G3Wother, G4Wother},
    {"readb",                   G0W1, Lreadbyte, G2W1, G3W1, G4W1},
    {"unreadch",                G0Wother, Lunreadch, Lunreadch2, G3W1, G4W1},
    {"readline",                Lreadline, Lreadline1, G2Wother, G3Wother, G4Wother},
    {"setpchar",                G0W1, Lsetpchar, G2W1, G3W1, G4W1},
    {"spool",                   Lspool0, Lspool, G2Wother, G3Wother, G4Wother},
    {"dribble",                 Lspool0, Lspool, G2Wother, G3Wother, G4Wother},
    {"system",                  G0W1, Lsystem, G2W1, G3W1, G4W1},
    {"silent-system",           G0W1, Lsilent_system, G2W1, G3W1, G4W1},
    {"~tyi",                    Ltyi, G1W0, G2W0, G3W0, G4W0},
    {"list-to-string",          G0W1, Llist_to_string, G2W1, G3W1, G4W1},
    {"list2string",             G0W1, Llist_to_string, G2W1, G3W1, G4W1},
    {"list-to-symbol",          G0W1, Llist_to_symbol, G2W1, G3W1, G4W1},
    {"string2list",             G0W1, Lstring2list, G2W1, G3W1, G4W1},
    {"where-was-that",          Lwhere_was_that, G1W0, G2W0, G3W0, G4W0},
    {"compress",                G0W1, Lcompress, G2W1, G3W1, G4W1},
    {"compress1",               G0W1, Lcompress, G2W1, G3W1, G4W1},
    {"read",                    Lread, Lread_1, G2Wother, G3Wother, G4Wother},
    {"intern",                  G0Wother, Lintern, Lintern_2, G3Wother, G4Wother},
    {"gensym",                  Lgensym, Lgensym1, G2Wother, G3Wother, G4Wother},
    {"ordp",                    G0W2, G1W2, Lorderp, G3W2, G4W2},
    {"unintern",                G0Wother, Lunintern, Lunintern_2, G3Wother, G4Wother},
    {"remob",                   G0Wother, Lunintern, Lunintern_2, G3Wother, G4Wother},
    {"make-symbol",             G0W1, Lmake_symbol, G2W1, G3W1, G4W1},
#ifdef COMMON
// The package system...
    {"extern",                  G0Wother, Lextern_1, Lextern, G3Wother, G4Wother},
    {"import*",                 G0Wother, Limport_1, Limport, G3Wother, G4Wother},
    {"find-symbol",             G0Wother, Lfind_symbol_1, Lfind_symbol, G3Wother, G4Wother},
    {"find-package",            G0W1, Lfind_package, G2W1, G3W1, G4W1},
    {"make-package",            G0Wother, Lmake_package_1, Lmake_package_2, Lmake_package_3, LMake_package_4up},
    {"use-package*",            G0W2, G1W2, Luse_package, G3W2, G4W2},
    {"list-all-packages",       Llist_all_packages, G1W0, G2W0, G3W0, G4W0},
#endif
    {NULL,                      0, 0, 0, 0, 0}
};

// end of cslread.cpp
