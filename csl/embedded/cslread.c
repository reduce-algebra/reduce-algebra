/* cslread.c                        Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Reading and symbol-table support.
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 2e9bdce2 01-Jul-2009 */

#include "headers.h"

#ifdef COMMON
#include "clsyms.h"
#endif

#ifdef SOCKETS
#include "sockhdr.h"
#endif

#ifdef WIN32
#include <windows.h>
#endif

#define CTRL_C    3
#define CTRL_D    4

#ifdef Kanji
#define ISalpha(a)     iswalpha(a)
#define ISdigit(a)     iswdigit(a)
#define ISspace(a)     iswspace(a)
#define TOupper(a)     towupper(a)
#define TOlower(a)     towlower(a)

int first_char(Lisp_Object ch)
{   /* ch is a symbol. Get the first character of its name. */
    int n;
    intptr_t l;
    ch = qpname(ch);
    l = length_of_header(vechdr(ch)) - CELL;
    if (l == 0) return 0;
    n = celt(ch, 0);
    if (is2byte(n) && l != 1)
        n = (n << 8) + ucelt(ch, 1);
    return n;
}

#else /* Kanji */
#define ISalpha(a)     isalpha(a)
#define ISdigit(a)     isdigit(a)
#define ISspace(a)     isspace(a)
#define TOupper(a)     toupper(a)
#define TOlower(a)     tolower(a)
#define first_char(ch) ucelt(qpname(ch), 0)
#endif /* Kanji */


/*
 *      Basic version of Lisp reader.
 */

static int curchar = NOT_CHAR;
FILE *non_terminal_input;

static int boffop;
#define boffo_char(i) ucelt(boffo, i)


Lisp_Object make_string(const char *b)
/*
 * Given a C string, create a Lisp (simple-) string.
 */
{
    int32_t n = strlen(b);
    Lisp_Object r = getvector(TAG_VECTOR, TYPE_STRING, CELL+n);
    char *s = (char *)r - TAG_VECTOR;
    int32_t k = (n + 3) & ~(int32_t)7;
    Lisp_Object nil;
    errexit();
/* Here I go to some trouble to zero out the last doubleword of the vector */
    if (SIXTY_FOUR_BIT)
    {   if (k != 0)
        {   *(int32_t *)(s + k + 4) = 0;
            *(int32_t *)(s + k) = 0;
        }
    }
    else
    {   *(int32_t *)(s + k + 4) = 0;
        if (k != 0) *(int32_t *)(s + k) = 0;
    }
    memcpy(s + CELL, b, (size_t)n);
    return r;
}

static Lisp_Object copy_string(Lisp_Object str, int32_t n)
/*
 * Given a Lisp string, plus its length, create a Lisp (simple-) string.
 * NOTE that the "string" passed in may not in fact have the length
 * you think it has - it may be boffo which is used as a string buffer.
 */
{
    Lisp_Object nil, r;
    char *s;
    int32_t k;
    push(str);
    r = getvector(TAG_VECTOR, TYPE_STRING, CELL+n);
    pop(str);
    s = (char *)r - TAG_VECTOR;
    k = (n + 3) & ~(int32_t)7;
    errexit();
/* Here I go to some trouble to zero out the last doubleword of the vector */
    if (SIXTY_FOUR_BIT)
    {   if (k != 0)
        {   *(int32_t *)(s + k + 4) = 0;
            *(int32_t *)(s + k) = 0;
        }
    }
    else
    {   *(int32_t *)(s + k + 4) = 0;
        if (k != 0) *(int32_t *)(s + k) = 0;
    }
    memcpy(s + CELL, (char *)str + (CELL-TAG_VECTOR), (size_t)n);
    return r;
}

Lisp_Object MS_CDECL Lbatchp(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "batchp");
#ifdef SOCKETS
/*
 * If CSL is being run as a service (ie accessed via a socket) then I will
 * deem it to be in "interactive" mode. This leaves responsibility for stopping
 * after errors (if that is what is wanted) with the other end of the
 * communications link.
 */
    if (socket_server != 0) return onevalue(nil);
#endif
/*
 * If the user had specified input files on the command line I will say that
 * we are in batch mode even if there is a terminal present somewhere. So
 * a run of the form
 *     csl inputfile.lsp
 * is a "batch" run, while
 *     csl < inputfile.lsp
 * will MAYBE also be noticed as batch, but do not count on it!
 */
    if (non_terminal_input != NULL)
        return onevalue(batch_flag ? nil : lisp_true);
/*
 * "sysxxx.c" now decides if we are in "batch processing" context,
 * in general by asking "isatty(fileno(stdin))" to see if stdin is
 * attached to an interactive terminal.  Ideally this will say we are in
 * batch mode if the user has redirected input from a file, as in
 *       csl < xxx.lsp
 * but catching such cases may be HARD with some operating systems.
 * With some operating systems we will NEVER report ourselves as "batch".
 */
    return onevalue(Lispify_predicate(batch_flag ? !batchp() : batchp()));
}

Lisp_Object Lgetenv(Lisp_Object nil, Lisp_Object a)
{
    char parmname[LONGEST_LEGAL_FILENAME];
    Header h;
    Lisp_Object r;
    int32_t len;
    char *w;
#ifdef COMMON
    if (complex_stringp(a))
    {   a = simplify_string(a);
        errexit();
    }
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        errexit();
        h = vechdr(a);
    }
    else if (!is_vector(a) ||
         type_of_header(h = vechdr(a)) != TYPE_STRING)
        return aerror1("getenv", a);
    len = length_of_header(h) - CELL;
    memcpy(parmname, (char *)a + (CELL-TAG_VECTOR), (size_t)len);
    parmname[len] = 0;
    w = my_getenv(parmname);
    if (w == NULL) return onevalue(nil);    /* not available */
    r = make_string(w);
    errexit();
    return onevalue(r);
}

Lisp_Object Lsystem(Lisp_Object nil, Lisp_Object a)
{
    char parmname[LONGEST_LEGAL_FILENAME];
    Header h;
    int32_t len;
    int w;
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "system"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
    if (a == nil)            /* enquire if command processor is available */
    {   w = my_system(NULL);
        return onevalue(Lispify_predicate(w != 0));
    }
#ifdef COMMON
    if (complex_stringp(a))
    {   a = simplify_string(a);
        errexit();
    }
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        errexit();nil = C_nil;
        h = vechdr(a);
    }
    else if (!is_vector(a) ||
         type_of_header(h = vechdr(a)) != TYPE_STRING)
        return aerror1("system", a);
    len = length_of_header(h) - CELL;
    memcpy(parmname, (char *)a + (CELL-TAG_VECTOR), (size_t)len);
    parmname[len] = 0;
    ensure_screen();
    w = my_system(parmname);
    ensure_screen();
    return onevalue(fixnum_of_int((int32_t)w));
}

#ifdef WIN32
/*
 * On Windows this version takes the trouble to avoid letting the
 * application that you are running pop up a visible console window.
 */

static Lisp_Object Lsilent_system(Lisp_Object nil, Lisp_Object a)
{
    char cmd[LONGEST_LEGAL_FILENAME];
#ifdef SHELL_EXECUTE
    char args[LONGEST_LEGAL_FILENAME];
#endif
    Header h;
    int32_t len;
    int i;
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "system"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
    if (a == nil)            /* enquire if command processor is available */
        return onevalue(lisp_true); /* always is on Windows! */
    ensure_screen();
#ifdef COMMON
    if (complex_stringp(a))
    {   a = simplify_string(a);
        errexit();
    }
#endif
    if (symbolp(a))
    {   a = get_pname(a);
        errexit();nil = C_nil;
        h = vechdr(a);
    }
    else if (!is_vector(a) ||
         type_of_header(h = vechdr(a)) != TYPE_STRING)
        return aerror1("system", a);
    ensure_screen();
    len = length_of_header(h) - CELL;
    memcpy(cmd, (char *)a + (CELL-TAG_VECTOR), (size_t)len);
    cmd[len] = 0;
#ifdef SHELL_EXECUTE
/*
 * ShellExecute works for me and allows me to launch an application with
 * its console hidden - but it does not give an opportunity to wait until
 * the command that was executed has completed. I will leave this code
 * here for now since I may find I want to re-use it (eg for opening
 * documents). But the code bwlow that explicitly creates a process is
 * what I reaaly need here.
 */
    i = 0;
    while (cmd[i]!=' ' && cmd[i]!=0) i++;
    if (cmd[i]==0) args[0] = 0;
    else
    {   cmd[i] = 0;
        strcpy(args, &cmd[i+1]);
    }
    i = (int)ShellExecute(NULL,
                          "open",
                          cmd,
                          args,
                          ".",
                          SW_HIDE);
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
/*
 * If I fail to retrieve a true exit code I will return the value 1000. This
 * is pretty arbitrary, but I expect 0 to denote success and 1000 to be an
 * unusual "genuine" return code
 */
        if (!GetExitCodeProcess(process.hProcess, &rc)) rc = 1000;
        CloseHandle(process.hProcess);
        CloseHandle(process.hThread);
        i = (int)rc;
    }
#endif
    ensure_screen();
    return onevalue(fixnum_of_int(i));
}

#else

static Lisp_Object Lsilent_system(Lisp_Object nil, Lisp_Object a)
{
/*
 * Other than on Windows I do not see any risk of "consoles" getting created
 * when I do not want them, so this just does what the normal execution code
 * does.
 */
    return Lsystem(nil, a);
}

#endif

static uint32_t hash_lisp_string_with_length(Lisp_Object s, int32_t n)
{
/*
 * I start off the hash calculation with something that depends on the
 * length of the string n.
 */
    uint32_t hh = 0x01000000 + n;
    uint32_t *b = (uint32_t *)((char *)s + (CELL-TAG_VECTOR));
    char *b1;
    while (n >= CELL+4)  /* Do as much as is possible word at a time */
    {
        uint32_t temp;
/*
 * The next few lines take a 32-bit value with digits PQRS and for a value
 * with digits Q^R and P^Q^R^S.  Note that this is invariant under the change
 * to SRQP, and thus even though I fetched a whole word and the order of bytes
 * in that word is hard to know the hash value will not depend on the byte
 * order involved.  By that time I have done all this and thereby lost any
 * chance of ABCD and DCBA not clashing maybe a simple byte at a time hash
 * procedure would have been more sense?  Some day I should take comparative
 * timings and measurements of hash-table conflicts.
 */
        uint32_t a = *b++;      /* P      Q        R        S       */
        a = a ^ (a << 8);         /* P^Q    Q^R      R^S      S       */
        a = a ^ (a >> 16);        /* P^Q    Q^R      P^Q^R^S  Q^R^S   */
        a = a << 8;               /* Q^R    P^Q^R^S  Q^R^S    0       */
/*
 * And now compute a hash value using a CRC that has a period of
 * 0x7fffffff (i.e. maximum period in 31 bits). And at least if shift
 * operations are cheap on your computer it can be evaluated rapidly as well.
 */
        temp = hh << 7;
        hh = ((hh >> 25) ^
              (temp >> 1) ^
              (temp >> 4) ^
              (a >> 16)) & 0x7fffffff;
        n -= 4;
    }
    b1 = (char *)b;
/*
 * Finish off the hash value byte-at-a-time.  If I could be certain that
 * strings being hashed would always be zero-padded in their last word I
 * could avoid the need for this, but at present I can not.
 */
    while (n > CELL)
    {   uint32_t temp;
        temp = hh << 7;
        hh = ((hh >> 25) ^
              (temp >> 1) ^
              (temp >> 4) ^
              (uint32_t)*b1++) & 0x7fffffff;
        n -= 1;
    }
/*
 * At the end I multiply by 139 so that at least symbols that differ
 * by just having adjacent last letters will be better spread out.
 */
    return ((139*hh) & 0x7fffffff);
}

uint32_t hash_lisp_string(Lisp_Object s)
/*
 * Argument is a (lisp) string.  Return a 31 bit hash value.
 */
{
    return hash_lisp_string_with_length(s, length_of_header(vechdr(s)));
}

static int value_in_radix(int c, int radix)
{
    if (ISdigit(c)) c = c - '0';    /* Assumes digit codes are consecutive */
/*
 * The next section tries hard not to depend on any particular character
 * code - this may slow it down a little bit but reading numbers that
 * have an explicit radix will not usually matter that much.
 */
    else if (ISalpha(c))
    {   char *v = "abcdefghijklmnopqrstuvwxyz";
        int n = 0;
        c = tolower(c);
        while (*v++ != c)
            if (++n >= 26) return -1;   /* break on unrecognized letter */
        c = n + 10;
    }
    else return -1;
    if (c < radix) return c;
    else return -1;
}

Lisp_Object intern(int len, CSLbool escaped)
/*
 * This takes whatever is in the first len characters of
 * the Lisp string boffo, and maps it into a number, string
 * or symbol as relevant.
 */
{
    int i, numberp = escaped ? -1 : 0;
#ifdef COMMON
    int fplength = 2, explicit_fp_format = 0;
#endif
    Lisp_Object nil = C_nil;
    stackcheck0(0);
    for (i=0; i<len; i++)
    {   int c = boffo_char(i);
        switch (numberp)
        {
    default:
            break;
    case 0:
            if (c == '+' || c == '-')
            {   numberp = 1;
                continue;
            }
            /* drop through */
    case 1:
            if (c == '.')
            {   numberp = 6;
                continue;
            }
            if (ISdigit(c))        /* Really wants to inspect *read-base* */
            {   numberp = 2;
                continue;
            }
            numberp = -1;
            break;
    case 2:
            if (ISdigit(c)) continue;   /* *read-base* */
            switch (c)
            {
#ifdef COMMON
        case '/':   numberp = 3;    continue;
#endif
        case '.':   numberp = 5;    continue;
        case 'e': case 'E':
/*
 * in CSL mode I will read all floating point numbers as if they had been
 * double-precision, so I disable recognition of s,f,d and l exponent
 * markers and force the length. In Common Lisp mode I have to look at the
 * value of *read-default-float-format* to see what to do.
 */
                    numberp = 9;
                    continue;
#ifdef COMMON
        case 's': case 'S':
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    fplength = 0;
                    numberp = 9;
                    continue;
        case 'f': case 'F':
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    fplength = 1;
                    numberp = 9;
                    continue;
        case 'd': case 'D':
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    numberp = 9;
                    continue;
        case 'l': case 'L':
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    fplength = 3;
                    numberp = 9;
                    continue;
#endif
        default:
                    numberp = -1;
                    break;
            }
            break;
#ifdef COMMON
    case 3:
    case 4:
            if (ISdigit(c))   /* *read-base* */
            {   numberp = 4;
                continue;
            }
            numberp = -1;
            break;
#endif
    case 5:
    case 8:
            if (ISdigit(c))
            {   numberp = 8;
                continue;
            }
            switch (c)
            {
        case 'e': case 'E':
                    numberp = 9;
                    continue;
#ifdef COMMON
        case 's': case 'S':
     /* Clobbering the string is a DISASTER if it is not in fact numeric */
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    fplength = 0;
                    numberp = 9;
                    continue;
        case 'f': case 'F':
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    fplength = 1;
                    numberp = 9;
                    continue;
        case 'd': case 'D':
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    numberp = 9;
                    continue;
        case 'l': case 'L':
                    boffo_char(i) = 'e';
                    explicit_fp_format = 1;
                    fplength = 3;
                    numberp = 9;
                    continue;
#endif
        default:
                    numberp = -1;
                    break;
            }
            break;
    case 6:
            if (ISdigit(c))
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
            /* Drop through */
    case 10:
    case 11:
            if (ISdigit(c))
            {   numberp = 11;
                continue;
            }
            numberp = -1;
            break;
        }
        break;
    }
/* Here the item has been scanned, and it is known if it is numeric! */
    switch (numberp)
    {
default:
/* Not a number... look up in package system */
#ifdef COMMON
        if (!escaped && boffo_char(0) == ':')
        {   int i = 0;
            for (i = 0; i<boffop; i++) boffo_char(i) = boffo_char(i+1);
            boffop--;
            return iintern(boffo, (int32_t)boffop, qvalue(keyword_package), 0);
        }
#endif
        return iintern(boffo, (int32_t)boffop, CP, 0);


case 5:         /* Integer written as 12345.    (note trailing ".") */
        boffo_char(--boffop) = 0; /* ... trim off the trailing dot */
        /* drop through */
case 2:
/*
 * I speed up reading by working 7 digits at a time (using C integer
 * arithmetic to gobble them) and only resorting to Lisp generic
 * arithmetic to combine the chunks.
 */
        if (boffo_char(0) == '+')
        {   int i = 0;
            for (i = 0; i<boffop; i++) boffo_char(i) = boffo_char(i+1);
            boffop--;
        }
        {   Lisp_Object v = fixnum_of_int(0);
            CSLbool sign = NO;
            int32_t d = 0, d1 = 10;
            for (i=0; i<boffop; i++)
            {   if (i==0 && boffo_char(i) == '-') sign = YES;
                else if (d1 == 10000000 || i == boffop-1)
                {   d = 10*d + (int32_t)value_in_radix(boffo_char(i), 10);
                    v = times2(v, fixnum_of_int(d1));
                    errexit();
                    v = plus2(v, fixnum_of_int(d));
                    d = 0;
                    d1 = 10;
                    errexit();
                }
                else
                {   d = 10*d + (int32_t)value_in_radix(boffo_char(i), 10);
                    d1 = 10*d1;
                }
            }
            if (sign) v = negate(v);
            return v;
        }

#ifdef COMMON
case 4:
        {   int p, q, g;
            Lisp_Object r;
/* Beware bignum issue here... but take view that ratios are not used! */
            boffo_char(boffop) = 0;
/* p and q were made int not int32_t to match up with the %d in scanf ... */
            sscanf((char *)&boffo_char(0), "%d/%d", &p, &q);
/* Limit myself to fixnums here */
            g = (int)int_of_fixnum(gcd(fixnum_of_int((int32_t)p),
                                       fixnum_of_int((int32_t)q)));
            p /= g;
            q /= g;
            if (q < 0)
            {   p = -p;
                q = -q;
            }
            r = getvector(TAG_NUMBERS, TYPE_RATNUM, sizeof(Rational_Number));
            errexit();
            numerator(r) = fixnum_of_int((int32_t)p);
            denominator(r) = fixnum_of_int((int32_t)q);
            return r;
        }
#endif
case 8:
case 11:
        {   double d;
            Lisp_Object r;
#ifdef COMMON
            float f;
            if (!explicit_fp_format && is_symbol(read_float_format))
            {   Lisp_Object w = qvalue(read_float_format);
                if (w == short_float) fplength = 0;
                else if (w == single_float) fplength = 1;
/*              else if (w == double_float) fplength = 2; */
                else if (w == long_float) fplength = 3;
            }
#endif
            boffo_char(boffop) = 0;
            d = atof((char *)&boffo_char(0));
#ifdef COMMON
            switch (fplength)
            {
        case 0:
                {   Float_union ff;
                    ff.f = (float)d;
                    return TAG_SFLOAT + (ff.i & ~(int32_t)0xf);
                }
        case 1:
                f = (float)d;
                r = getvector(TAG_BOXFLOAT, TYPE_SINGLE_FLOAT,
                              sizeof(Single_Float));
                errexit();
                single_float_val(r) = f;
                return r;
        default:
/*      case 2: case 3:  */
                r = getvector(TAG_BOXFLOAT, TYPE_DOUBLE_FLOAT,
                              SIZEOF_DOUBLE_FLOAT);
                errexit();
                double_float_val(r) = d;
                return r;
            }
#else
/*
 * Only support double precision in CSL mode
 */
            r = getvector(TAG_BOXFLOAT, TYPE_DOUBLE_FLOAT,
                          SIZEOF_DOUBLE_FLOAT);
            errexit();
            double_float_val(r) = d;
            return r;
#endif
        }
    }
}

Lisp_Object make_undefined_symbol(char const *s)
{
    return make_symbol(s, 0, undefined1, undefined2, undefinedn);
}

Lisp_Object make_symbol(char const *s, int restartp,
                        one_args *f1, two_args *f2, n_args *fn)
/*
 * Used from the startup code to create an interned symbol and (maybe)
 * put something in its function cell.
 */
{
    Lisp_Object v, v0 = C_nil, nil = C_nil;
    int first_try = 1;
/*
 * Here I blandly assume that boffo is long enough to hold the string
 * that I am about to copy into it.  All is guaranteed well for
 * symbols predefined in Lisp in the normal way, but ones established
 * using command-line options like -Dname could cause trouble?
 */
#ifdef COMMON
/*
 * For COMMON Lisp I will make all the built-in symbols upper case, unless
 * the "2" bit of restartp is set...
 */
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
    v = iintern(boffo, (int32_t)strlen((char *)&boffo_char(0)), CP, 0);
    errexit();
    if (first_try) v0 = v;
/*
 * I instate the definition given if (a) the definition is a real
 * one (ie not for an undefined function) and if (b) either I am doing a cold
 * start or the name is still marked as having a definition in the form
 * of C code (or if I gace first_try false which is when I am going round
 * again and doing rather curious things...)
 */
    if (f1 != undefined1)
    {   if ((restartp & 1)==0 || (qheader(v) & SYM_C_DEF) != 0 || !first_try)
        {   if (qenv(v) == v) qenv(v) = nil;
/* only set env field to nil if it was otherwise not in use */
            ifn1(v) = (intptr_t)f1; ifn2(v) = (intptr_t)f2; ifnn(v) = (intptr_t)fn;
            qheader(v) |= SYM_C_DEF;
        }
        else
        {   int l = strlen((char *)&boffo_char(0));
/*
 * Another piece of curious behaviour here, intend to make it easier to
 * survive when the CSL/CCL kernel is extended. If a function that the
 * (new) kernel would like to define as a C-coded thing is already in
 * the current image either as undefined or with some other (byte-coded)
 * definition, I map the name of the new function, and XYZ goes to ~XYZ etc
 * by prefixing a '~'. The image as loaded can then access the new C coded
 * function by this name, and possibly transfer it across to the normal
 * name it was originally expected to have.  Since this is a symptom of
 * somebody having done either a curious over-riding redefinition of something
 * in the kernel or not having re-build to get new symbols properly available,
 * I print a message about it. Note also that I only rename once, so if there
 * were to be existing symbols with names that started with "~" that could
 * make my attempts here less than fully effective.
 */
            if (init_flags & INIT_VERBOSE)
              term_printf(
                "+++ Built-in \"%s\" clashes with image file: => \"~%s\"\n",
                &boffo_char(0), &boffo_char(0));
            while (l >= 0) boffo_char(l+1) = boffo_char(l), l--;
            boffo_char(0) = '~';
            first_try = 0;
            goto start_again;
        }
/*
 * All things that have been set up as copies of this symbol must be
 * initialised with the definition too. This happens even if the original
 * symbol has been redefined and is not longer nice C code...
 */
        if ((restartp & 1) != 0)
        {
/*
 * Note that I want to scan based on the ORIGINAL name of the function
 * not on any version that has been renamed with a "~".
 */
#ifdef COMMON
            Lisp_Object v1 = get(v0, work_symbol, nil);
#else
            Lisp_Object v1 = get(v0, work_symbol);
#endif
            while (consp(v1))
            {   Lisp_Object w = qcar(v1);
                v1 = qcdr(v1);
                ifn1(w) = (intptr_t)f1; ifn2(w) = (intptr_t)f2; ifnn(w) = (intptr_t)fn;
                qenv(w) = qenv(v);       /* Copy across environment too */
                qheader(w) |= SYM_C_DEF;
            }
        }
    }
    return v;
}

static CSLbool add_to_hash(Lisp_Object s, Lisp_Object vector, uint32_t hash)
/*
 * Adds an item into a hash table given that it is known that it is not
 * already there.
 */
{
    Header h = vechdr(vector);
    int32_t size = (length_of_header(h) - CELL)/CELL;
    int32_t i = (int32_t)(hash & (size-1));
/*
 * I have arranged (elsewhere) that the hash table will be a power of two
 * in size, so I can avoid primary clustering by stepping on by any odd
 * number.  Furthermore I might replace the (perhaps expensive) remaindering
 * operations by (perhaps cheap) bitwise "AND" when I reduce my hash value
 * to the right range to be an index into the table.
 */
    int32_t step = 1 | ((hash >> 10) & (size - 1));
    int32_t probes = 0;
/*
 * size is expected to be a power of 2 here.
 */
    while (++probes <= size)
    {   if (is_fixnum(elt(vector, i)))
        {   elt(vector, i) = s;
            return YES;                 /* Success */
        }
        i = i + step;
        if (i >= size) i -= size;
    }
    return NO;                          /* Table is totally full */
}

static int32_t number_of_chunks;

static Lisp_Object rehash(Lisp_Object v, Lisp_Object chunks, int grow)
{
/*
 * If (grow) is +1 this enlarges the table. If -1 it shrinks it. In the
 * case that the table is to shrink I should guarantee that the next smaller
 * table size down will have enough space for the number of active items
 * present. grow=0 leaves the table size alone but still rehashes.
 */
    int32_t h = 16384, i;
    Lisp_Object new_obvec, nil;
    number_of_chunks = int_of_fixnum(chunks);
/*
 * Now I decide how to format the new structure.  To grow, If I had a single
 * vector at present I try to double its size.  If that would give something
 * with over 40Kbytes I go to 48K, formatted as three chunks each of 16K.
 */
    if (grow > 0)
    {   if (number_of_chunks == 1)
        {   h = length_of_header(vechdr(v)) - CELL;
            if (h > 20480)
            {   h = 16384;
                number_of_chunks = 3;
            }
            else h = 2*h;
        }
        else number_of_chunks++;
/*
 * NB the linear growth of the hash table from this point on gives
 * bad performance for very large symbol tables due to excessive need
 * for rehashing.
 */
    }
    else if (grow < 0)
    {   if (number_of_chunks == 1)
        {   h = length_of_header(vechdr(v)) - CELL;
/*
 * When shrinking, I will not permit the hash table to have room for
 * less than 8 entries.
 */
            if (h > 64) h = h / 2;
        }
        else if (number_of_chunks <= 3)
        {   h = 32768;
            number_of_chunks = 1;
        }
        else number_of_chunks--;
    }
    nil = C_nil;
    stackcheck1(0, v);
    push(v);
try_again:
    if (number_of_chunks == 1)
    {   new_obvec = getvector_init(h+CELL, fixnum_of_int(0));
        errexitn(1);
    }
    else
    {   new_obvec = nil;
        for (i=0; i<number_of_chunks; i++)
        {   Lisp_Object w;
            push(new_obvec);
            w = getvector_init(h+CELL, fixnum_of_int(0));
            errexitn(2);
            pop(new_obvec);
            new_obvec = cons(w, new_obvec);
            errexitn(1);
        }
    }
    v = stack[0];
    while (v != nil)
    {   Lisp_Object vv;
        if (is_vector(v))
        {   vv = v;
            v = nil;
        }
        else
        {   vv = qcar(v);
            v = qcdr(v);
        }
        h = (length_of_header(vechdr(vv)) - CELL)/CELL;
        while (h != 0)
        {   Lisp_Object s, p, n = new_obvec;
            uint32_t hash;
            h--;
            s = elt(vv, h);
            if (is_fixnum(s)) continue;
            p = qpname(s);
            hash = hash_lisp_string(p);
            if (number_of_chunks != 1)
            {   int32_t i = (hash ^ (hash >> 16)) % number_of_chunks;
                while (i-- != 0) n = qcdr(n);
                n = qcar(n);
            }
            if (!add_to_hash(s, n, hash))
            {   number_of_chunks++;
/*
 * In the grossly improbable case that clustering leads to one of the
 * sub-vectors overflowing I will go back and re-start the expansion
 * process but with yet more space available.  This can ONLY happen
 * if I already had multiple sub-hash-tables.
 */
                goto try_again;
            }
        }
    }
    popv(1);
    return new_obvec;
}

#ifdef COMMON

static Lisp_Object add_to_externals(Lisp_Object s,
                                    Lisp_Object p, uint32_t hash)
{
    Lisp_Object n = packnext_(p);
    Lisp_Object v = packext_(p);
    Lisp_Object nil = C_nil;
    int32_t used = int_of_fixnum(packvext_(p));
    if (used == 1) used = length_of_header(vechdr(v));
    else used = 16384*used;
/*
 * n is (16*sym_count+1)             [Lisp fixnum for sym_count]
 * used = CELL*(spaces+1)
 * The effect is that I trigger a re-hash if the table reaches 62%
 * loading.  For small vectors when I re-hash I will double the
 * table size, for large ones I will add another 16Kbytes (i.e. 4K
 * table entries on a 32-bit machine).  The effect will be that small
 * packages will often be fairly lightly loaded (down to 31% just after
 * an expansion) while very large ones will be kept close to the 62% mark.
 * If I start off all tables with size that is a power of 2 that state
 * will persist.
 */
try_again:
    if (CELL*(uint32_t)n >= 10u*used)
    {   stackcheck3(0, s, p, v);
        push2(s, p);
        v = rehash(v, packvext_(p), 1);
        pop2(p, s);
        errexit();
        packext_(p) = v;
        packvext_(p) = fixnum_of_int(number_of_chunks);
    }
    packnext_(p) = n + (1<<4);      /* increment as a Lisp fixnum */
    {   int32_t nv = int_of_fixnum(packvext_(p));
        if (nv == 1) add_to_hash(s, v, hash);
        else
        {   nv = (hash ^ (hash >> 16)) % nv;
/*
 * There is a systematic nasty problem here that I maybe ought to deal with
 * some time.  Large packages are represented as a collection of smaller
 * hash tables, and part of the hash value of a symbol decides which of these
 * sub-tables any particular string will be placed in.  I enlarge the whole
 * system when the set of tables (treated as a whole) is 70% full.  But
 * clustering COULD potentially lead to one of the sub-tables becoming
 * totally full before then, and that would give a loop here if I was not
 * careful.  To avoid the possibility I make add_to_hash() report any
 * trouble and if I have difficulty I go back and re-enlarge the tables.
 * This is not guaranteed safe, but I will be VERY unlucky if it ever bites
 * me!
 */
            while (nv-- != 0) v = qcdr(v);
            if (!add_to_hash(s, qcar(v), hash))
            {   n = used = 0;
                goto try_again;
            }
        }
    }
    return nil;
}

#endif

static Lisp_Object add_to_internals(Lisp_Object s,
                                    Lisp_Object p, uint32_t hash)
{
    Lisp_Object n = packnint_(p);
    Lisp_Object v = packint_(p);
    Lisp_Object nil = C_nil;
    int32_t used = int_of_fixnum(packvint_(p));
    if (used == 1) used = length_of_header(vechdr(v));
    else used = 16384*used;
try_again:
    if (CELL*(uint32_t)n >= 10u*used)
    {   stackcheck3(0, s, p, v);
        push2(s, p);
        v = rehash(v, packvint_(p), 1);
        pop2(p, s);
        errexit();
        packint_(p) = v;
        packvint_(p) = fixnum_of_int(number_of_chunks);
    }
    packnint_(p) = (Lisp_Object)((int32_t)n + (1<<4));
                    /* increment as a Lisp fixnum */
    {   int32_t nv = int_of_fixnum(packvint_(p));
        if (nv == 1) add_to_hash(s, v, hash);
        else
        {   nv = (hash ^ (hash >> 16)) % nv;
            while (nv-- != 0) v = qcdr(v);
            if (!add_to_hash(s, qcar(v), hash))
            {   n = used = 0;
                goto try_again;
            }
        }
    }
    return nil;
}

static CSLbool rehash_pending = NO;

static Lisp_Object lookup(Lisp_Object str, int32_t strsize,
                          Lisp_Object v, Lisp_Object nv, int32_t hash)
/*
 * Searches a hash table for a symbol with name matching the given string,
 * and NOTE that the string passed down here is to be treated as having
 * just strsize characters in it.  Return Lisp number 0 if not found.
 * Sets rehash_pending if the number of probes used to find the item is
 * at least half the size of the table. This case might arise in the following
 * way:
 *    insert items into the table until it is just under 70% full.
 *    remob (eg via EXPORT) items until the table is just over 25% full.
 * note that so far there will have been no need to rehash
 *    insert more items, but select them so that thir hash values are all
 *    different from the ones used before. You should be able to end up
 *    with 70% of the table full of valid symbols and 30% left as the value
 *    fixnum_of_int(1) which represents a place where a deleted symbol used
 *    to be. There is now NO really empty space.
 * Now looking up symbols must keep searching past tombstones, and hence
 * here it will be necessary to scan the entire table before it is
 * possible to assert that a symbol is not present. Inserting new symbols
 * does not suffer in this way - only lookup.  To help with this horror I set
 * rehash_pending if the lookup uses a number of probes > 75% of the table
 * size. This should only arise in degenerate cases!
 */
{
    Header h;
    int32_t size;
    int32_t i = int_of_fixnum(nv), step, n;
    if (i != 1)
    {   i = (hash ^ (hash >> 16)) % i; /* Segmented - find correct segment */
        while (i-- != 0) v = qcdr(v);
        v = qcar(v);
    }
    h = vechdr(v);
    size = (length_of_header(h) - CELL)/CELL;
    i = (int32_t)(hash & (size - 1));
    step = 1 | ((hash >> 10) & (size - 1));
/*
 * I count the probes that I make here and if there are as many as the size
 * of the hash table then I allow the lookup to report that the symbol is not
 * present. But at least I do not get stuck in a loop.
 */
    for (n=0; n<size; n++)
    {   Lisp_Object w = elt(v, i);
        Lisp_Object pn;
        if (w == fixnum_of_int(0))
        {   if (4*n > 3*size) rehash_pending = YES;
            return w;  /* Not found */
        }
        if (w != fixnum_of_int(1))
        {   pn = qpname(w);
/* v comes out of a package so has a proper pname */
            if (memcmp((char *)str + (CELL-TAG_VECTOR),
                       (char *)pn + (CELL-TAG_VECTOR),
                       (size_t)strsize) == 0 &&
                (uint32_t)length_of_header(vechdr(pn)) == strsize+CELL)
            {   if (4*n > 3*size) rehash_pending = YES;
                return w;
            }
        }
        i = i + step;
        if (i >= size) i -= size;
    }
    rehash_pending = YES;
    return fixnum_of_int(0);
}

static int ordersymbol(Lisp_Object v1, Lisp_Object v2)
/*
 * Compare two symbols to see if they are in alphabetic order.
 * Returns 0 is the symbols have the same name, otherwise
 * the comparison is a lexical one on their names, with -ve if
 * v1 comes alphabetically before v2.  Deals with gensyms, and in so
 * doing has to allocate names for them, which seems a great misery
 * since it means that this procedure can provoke garbage collection..
 *
 * Note that the ordering here is based on the bit-patterns that
 * represent the names, so Kanji (etc) symbols may not come out in
 * an order that is especially useful.
 */
{
    Lisp_Object pn1 = qpname(v1), pn2 = qpname(v2);
    int c;
    int32_t l1, l2;
#ifndef COMMON
    if (qheader(v1) & SYM_UNPRINTED_GENSYM)
    {   Lisp_Object nil;
        push(v2);
        pn1 = get_pname(v1);
        pop(v2);
        nil = C_nil;
        if (exception_pending()) return 0;
        pn2 = qpname(v2);
    }
    if (qheader(v2) & SYM_UNPRINTED_GENSYM)
    {   Lisp_Object nil;
        push(pn1);
        pn2 = get_pname(v2);
        pop(pn1);
        nil = C_nil;
        if (exception_pending()) return 0;
    }
#endif
    l1 = length_of_header(vechdr(pn1)) - CELL;
    l2 = length_of_header(vechdr(pn2)) - CELL;
    c = memcmp((char *)pn1 + (CELL-TAG_VECTOR),
               (char *)pn2 + (CELL-TAG_VECTOR),
               (size_t)(l1 < l2 ? l1 : l2));
    if (c == 0) c = (int)(l1 - l2);
    return c;
}

/*
 * This has been coded so that it provides the behavious that Reduce expects
 * of ordp().  This is the REDUCE 3.6/3.7 version - it will need re-work
 * if REDUCE is altered.  Note the curious situation that symbols are
 * alphabetically ordered, EXCEPT that "nil" comes before everything else!
 * (NB for 3.6 this is as provided in a patch file rather than the original
 * release. The places with *** represent updates since 3.6 and the initial
 * version of 3.6)
 *
 *  symbolic procedure ordp(u,v);
 *     if null u then null v
 *      else if null v then t
 *      else if vectorp u then if vectorp v then ordpv(u,v) else atom v
 *      else if atom u
 *       then if atom v
 *              then if numberp u then numberp v and not (u<v)
 *                    else if idp v then orderp(u,v)
 *                    else numberp v
 *             else nil
 *      else if atom v then t
 *      else if car u=car v then %%% ordp(cdr u,cdr v)
 ***          ordpl(cdr u, cdr v)                          *** 8 Feb 1999
 ***          %% flagp(car u,'noncom) or ordpl(cdr u,cdr v)   ***
 *      else if flagp(car u,'noncom)
 *       then if flagp(car v,'noncom) then ordp(car u,car v) else t
 *      else if flagp(car v,'noncom) then nil
 *      else ordp(car u,car v);
 *
 ***  symbolic procedure ordpl(u,v)
 ***     if atom u then ordp(u,v)
 ***      else if atom v then t
 ***      else if car u=car v then ordpl(cdr u,cdr v)
 ***      else ordp(car u, car v);
 *
 */

static int orderp(Lisp_Object u, Lisp_Object v);

static int ordpv(Lisp_Object u, Lisp_Object v)
{
    Header hu = vechdr(u), hv = vechdr(v);
    int32_t lu = length_of_header(hu), lv = length_of_header(hv), n = CELL;
    if (type_of_header(hu) != type_of_header(hv))
        return (type_of_header(hu) < type_of_header(hv) ? -1 : 1);
    if (vector_holds_binary(hu))
    {   while (n < lu && n < lv)
        {   unsigned int eu = *(unsigned char *)(u - TAG_VECTOR + n),
                         ev = *(unsigned char *)(v - TAG_VECTOR + n);
            if (eu != ev) return (eu < ev ? -1 : 1);
            n += 1;
        }
        return (lu == lv ? 0 : lu < lv ? -1 : 1);
    }
/*
 * At present it is an ERROR to include mixed vectors in structures passed
 * to ordering functions, and if it is done the system may crash.  Note that
 * stream objects count as mixed for these purposes. I will get around to
 * fixing things sometime...
 */
    else
    {   while (n < lu && n < lv)
        {   Lisp_Object eu = *(Lisp_Object *)(u - TAG_VECTOR + n),
                        ev = *(Lisp_Object *)(v - TAG_VECTOR + n),
                        nil = C_nil;
            int w;
            push2(u, v);
            if (--countdown < 0) deal_with_tick();
            if (stack >= (Lisp_Object *)stacklimit)
            {   push(ev);
                eu = reclaim(eu, "stack", GC_STACK, 0);
                pop(ev);
                nil = C_nil;
/* stackcheck expanded by hand here to return an int, not nil, in bad case */
                if (exception_pending()) { popv(2); return 0; }
            }
            w = orderp(eu, ev);
            pop2(v, u);
            nil = C_nil;
            if (exception_pending()) return 0;
            if (w != 0) return w;
            n += CELL;
        }
        return (lu == lv ? 0 : lu < lv ? -1 : 1);
    }
}

static int ordpl(Lisp_Object u, Lisp_Object v)
{
#ifdef COMMON
    Lisp_Object nil = C_nil;
#endif
    for (;;)
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

static int orderp(Lisp_Object u, Lisp_Object v)
{
    Lisp_Object nil = C_nil;
    for (;;)
    {   if (u == nil) return v == nil ? 0 : 1;
        else if (v == nil) return -1;       /* Special cases of NIL done */
        else if (u == v) return 0;          /* useful optimisation? */
/*
 * I migrate the vectorp test inside where I have tested for atoms, since
 * I expect vectors to be a somewhat uncommon case
 */
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
/*
 * Now the objects are not symbols, vectors or numbers.  That maybe
 * leaves character objects.  I compare representations to give a
 * rather arbitrary ordering. Note that any comparisons that get
 * down here are yielding non portable results.
 */
                else return (u == v) ? 0 : (u < v) ? 1 : -1;
            }
            else return 1;
        }
        else if (!consp(v)) return -1;
        else
        {   Lisp_Object cu = qcar(u), cv = qcar(v);
            Lisp_Object fv;   /* used by flagged_noncom */
            int w;
            push2(u, v);
/*          stackcheck2(2, cu, cv); */
            if (--countdown < 0) deal_with_tick();
            if (stack >= (Lisp_Object *)stacklimit)
            {   push(cv);
                cu = reclaim(cu, "stack", GC_STACK, 0);
                pop(cv);
                nil = C_nil;
/* stackcheck expanded by hand here to return an int, not nil, in bad case */
                if (exception_pending()) { popv(2); return 0; }
            }
            w = orderp(cu, cv);
            pop2(v, u);
            nil = C_nil;
            if (exception_pending()) return 0;
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
/*
 * here car u = car v
 */
            u = qcdr(u);
            v = qcdr(v);
            if (!consp(u)) continue;
            if (!consp(v)) return -1;
/*
 * The function I call ordpl here has the atom tests lifted out from
 * its top...
 */
            return ordpl(u, v);
        }
    }
}

Lisp_Object Lorderp(Lisp_Object nil,
                           Lisp_Object a, Lisp_Object b)
{
    int w;
    w = orderp(a, b);
    errexit();
    return onevalue(Lispify_predicate(w <= 0));
}

static uint32_t removed_hash;

static CSLbool remob(Lisp_Object sym, Lisp_Object v, Lisp_Object nv)
/*
 * Searches a hash table for a symbol with name matching the given string,
 * and remove it.
 */
{
    Lisp_Object str = qpname(sym);
    Header h;
    uint32_t hash;
    int32_t i = int_of_fixnum(nv), size, step, n;
    if (qheader(sym) & SYM_ANY_GENSYM) return NO; /* gensym case is easy! */
#ifdef COMMON
/* If not in any package it has no home & is not available */
    qheader(sym) &= ~SYM_EXTERN_IN_HOME & ~(0xffffffff<<SYM_IN_PKG_SHIFT);
#endif
    removed_hash = hash = hash_lisp_string(str);
/*
 * The search procedure used here MUST match that coded in lookup().
 */
    if (i != 1)
    {   i = (hash ^ (hash >> 16)) % i;
        while (i-- != 0) v = qcdr(v);
        v = qcar(v);
    }
    h = vechdr(v);
    size = (length_of_header(h) - CELL)/CELL;
    i = (int32_t)(hash & (size - 1));
    step = 1 | ((hash >> 10) & (size - 1));
    for (n=0; n<size; n++)
    {   Lisp_Object w = elt(v, i);
        if (w == fixnum_of_int(0)) return NO;  /* Not found */
        if (w == sym)
        {   elt(v, i) = fixnum_of_int(1);
/*
 * I will shrink the hash table if it becomes less than 25% full,
 * but not in this bit of code... because I want this internal
 * remob() function to avoid any possible failure or garbage collection
 * so I can call it from C code without any formality. Thus I should do
 * any tidying up afterwards.
 */
            return YES;
        }
        i = i + step;
        if (i >= size) i -= size;
    }
    return NO;
}

#ifdef COMMON

static Lisp_Object Lmake_symbol(Lisp_Object nil, Lisp_Object str)
/*
 * Lisp function (make-symbol ..) creates an uninterned symbol.
 */
{
    Lisp_Object s;
    stackcheck1(0, str);
/*
 * Common Lisp wants a STRING passed here, but as a matter of generosity and
 * for the benefit of some of my system code I support symbols too.
 */
    if (symbolp(str))
    {   str = get_pname(str);
        errexit();
    }
    else if (!is_vector(str)) return aerror1("make-symbol", str);
    else if (complex_stringp(str))
    {   str = simplify_string(str);
        errexit();
    }
    else if (type_of_header(vechdr(str)) != TYPE_STRING)
        return aerror1("make-symbol", str);
    push(str);
    s = getvector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
    errexitn(1);
    pop(str);
    qheader(s) = TAG_ODDS+TYPE_SYMBOL;
    qvalue(s) = unset_var;
    qpname(s) = str;
    qplist(s) = nil;
    qfastgets(s) = nil;
    qpackage(s) = nil;
    qenv(s) = s;
    ifn1(s) = (intptr_t)undefined1;
    ifn2(s) = (intptr_t)undefined2;
    ifnn(s) = (intptr_t)undefinedn;
    qcount(s) = 0;      /* set counts to zero to be tidy */
    return onevalue(s);
}

#endif

Lisp_Object MS_CDECL Lgensym(Lisp_Object nil, int nargs, ...)
/*
 * Lisp function (gensym) creates an uninterned symbol with odd name.
 */
{
    Lisp_Object id;
#ifdef COMMON
    Lisp_Object pn;
    char genname[64];
#endif
    argcheck(nargs, 0, "gensym");
    stackcheck0(0);
    nil = C_nil;
#ifdef COMMON
    sprintf(genname, "G%lu", (long unsigned)gensym_ser++);
    pn = make_string(genname);
    errexit();
    push(pn);
#endif
    id = getvector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
#ifdef COMMON
    pop(pn);
#endif
    errexit();
#ifdef COMMON
    qheader(id) = TAG_ODDS+TYPE_SYMBOL+SYM_ANY_GENSYM;
    qpname(id) = pn;
#else
    qheader(id) = TAG_ODDS+TYPE_SYMBOL+SYM_UNPRINTED_GENSYM+SYM_ANY_GENSYM;
    qpname(id) = gensym_base;
#endif
    qvalue(id) = unset_var;
    qplist(id) = nil;
    qfastgets(id) = nil;
#ifdef COMMON
    qpackage(id) = nil; /* Marks it as a uninterned */
#endif
    qenv(id) = id;
    ifn1(id) = (intptr_t)undefined1;
    ifn2(id) = (intptr_t)undefined2;
    ifnn(id) = (intptr_t)undefinedn;
    qcount(id) = 0;     /* to be tidy */

    return onevalue(id);
}

Lisp_Object Lgensym1(Lisp_Object nil, Lisp_Object a)
/*
 * Lisp function (gensym1 base) creates an uninterned symbol with odd name.
 * The case (gensym <number>) is DEPRECATED by the Common Lisp standards
 * committee and so I will not implement it at least for now.
 */
{
    Lisp_Object id, genbase;
#ifdef COMMON
    uint32_t len;
    char genname[64];
    if (complex_stringp(a))
    {   a = simplify_string(a);
        errexit();
    }
#endif
    if (is_vector(a) &&
         type_of_header(vechdr(a)) == TYPE_STRING) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);  /* copy gensym base */
    else return aerror1("gensym1", a);
    push(genbase);
    stackcheck0(0);
#ifdef COMMON
    len = length_of_header(vechdr(genbase)) - CELL;
    if (len > 60) len = 60;     /* Unpublished truncation of the string */
    sprintf(genname, "%.*s%lu", (int)len,
            (char *)genbase + (CELL-TAG_VECTOR), (long unsigned)gensym_ser++);
    stack[0] = make_string(genname);
    errexitn(1);
#endif
    id = getvector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
    errexitn(1);
    pop(genbase);
#ifdef COMMON
    qheader(id) = TAG_ODDS+TYPE_SYMBOL+SYM_ANY_GENSYM;
#else
    qheader(id) = TAG_ODDS+TYPE_SYMBOL+SYM_UNPRINTED_GENSYM+SYM_ANY_GENSYM;
#endif
    qvalue(id) = unset_var;
    qpname(id) = genbase;
    qplist(id) = nil;
    qfastgets(id) = nil;
#ifdef COMMON
    qpackage(id) = nil; /* Marks it as a uninterned */
#endif
    qenv(id) = id;
    ifn1(id) = (intptr_t)undefined1;
    ifn2(id) = (intptr_t)undefined2;
    ifnn(id) = (intptr_t)undefinedn;
    qcount(id) = 0;     /* to be tidy */
    return onevalue(id);
}

Lisp_Object Lgensym2(Lisp_Object nil, Lisp_Object a)
/*
 * Lisp function (gensym2 base) whose name is exactly that given by the
 * argument.  This might be UNHELPFUL if one tried to print the value
 * concerned, but seems to be what the Common Lisp syntax #:ggg expects
 * to achieve!
 */
{
    Lisp_Object id, genbase;
    uint32_t len;
#ifdef COMMON
    if (complex_stringp(a))
    {   a = simplify_string(a);
        errexit();
    }
#endif
    if (is_vector(a) &&
         type_of_header(vechdr(a)) == TYPE_STRING) genbase = a;
    else if (symbolp(a)) genbase = qpname(a);
    else return aerror1("gensym2", a);
    push(genbase);
    stackcheck0(0);
    len = length_of_header(vechdr(genbase)) - CELL;
    stack[0] = copy_string(genbase, len);
    errexitn(1);
    id = getvector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
    errexitn(1);
    pop(genbase);
    qheader(id) = TAG_ODDS+TYPE_SYMBOL+SYM_ANY_GENSYM;
    qvalue(id) = unset_var;
    qpname(id) = genbase;
    qplist(id) = nil;
    qfastgets(id) = nil;
#ifdef COMMON
    qpackage(id) = nil; /* Marks it as a uninterned */
#endif
    qenv(id) = id;
    ifn1(id) = (intptr_t)undefined1;
    ifn2(id) = (intptr_t)undefined2;
    ifnn(id) = (intptr_t)undefinedn;
    qcount(id) = 0;     /* to be tidy */
    return onevalue(id);
}

static Lisp_Object Lgensymp(Lisp_Object nil, Lisp_Object a)
{
    if (is_symbol(a) &&
        (qheader(a) & SYM_CODEPTR) == 0 &&
        (qheader(a) & SYM_ANY_GENSYM) != 0) return onevalue(lisp_true);
    else return onevalue(nil);
}

Lisp_Object iintern(Lisp_Object str, int32_t h, Lisp_Object p, int str_is_ok)
/*
 * Look up the first h chars of the string str with respect to the package p.
 * The last arg is a boolean that allows me to decide if (when a new symbol
 * has to be created) the string must be copied.  If h differs from the
 * real number of characters in arg1 then a copy MUST be made.
 * If non-zero, the last arg is 1 for intern, 2 for extern, 3
 * for find-symbol and 4 for "find-external-symbol" as in reader syntax p:x.
 * NB in CSL mode only one value is returned.
 */
{
    Lisp_Object r, nil = C_nil;
    uint32_t hash;
    stackcheck2(0, str, p);
    hash = hash_lisp_string_with_length(str, h+CELL);
/* find-external-symbol will not look at the internals */
    if (str_is_ok != 4)
    {   r = lookup(str, h, packint_(p), packvint_(p), hash);
/*
 * rehash_pending is intended to deal with horrible cases that involve
 * lots of remobs. But in the worst possible scenario one could have
 * a symbol table where all symbols clashed on hashing, and then by
 * restricting further use to just the last few symbols entered it would be
 * possible for all lookup operations to take a number of probes that
 * was almost 70% of the table size. In such cases rehashing (without
 * expanding the table size at the same time) would leave the table
 * unaltered and would not mend things.  To avoid such repeated fruitless
 * rehashing I only set rehash_pending if the number of probes was over
 * 75% of the table size, and this should be impossible if there are no
 * tombstones present.
 */
        if (rehash_pending)
        {   Lisp_Object v = packint_(p);
            push2(p, r);
            v = rehash(v, packvint_(p), 0);
            pop2(r, p);
            errexit();
            packint_(p) = v;
            packvint_(p) = fixnum_of_int(number_of_chunks);
            rehash_pending = NO;
        }
        nil = C_nil;
        if (r != fixnum_of_int(0))
        {
#ifdef COMMON
            mv_2 = internal_symbol;
#endif
            return nvalues(r, 2);
        }
    }
#ifdef COMMON
    r = lookup(str, h, packext_(p), packvext_(p), hash);
    if (rehash_pending)
    {   Lisp_Object v = packext_(p);
        push2(p, r);
        v = rehash(v, packvext_(p), 0);
        pop2(r, p);
        errexit();
        packext_(p) = v;
        packvext_(p) = fixnum_of_int(number_of_chunks);
        rehash_pending = NO;
    }
    if (r != fixnum_of_int(0))
    {
        mv_2 = external_symbol;
        return nvalues(r, 2);
    }
    if (str_is_ok == 4)
    {
#ifdef COMMON
        mv_2 = nil;
#endif
        return nvalues(nil, 2);
    }
    for (r = packuses_(p); r!=nil; r=qcdr(r))
    {   Lisp_Object w = qcar(r);
        w = lookup(str, h, packext_(w), packvext_(w), hash);
        if (rehash_pending)
        {   Lisp_Object v = packext_(p);
            push2(p, r);
            v = rehash(v, packvext_(p), 0);
            pop2(r, p);
            errexit();
            packext_(p) = v;
            packvext_(p) = fixnum_of_int(number_of_chunks);
            rehash_pending = NO;
        }
        if (w != fixnum_of_int(0))
        {
            mv_2 = inherited_symbol;
            return nvalues(w, 2);
        }
    }
#endif
    if (str_is_ok == 3)
    {
#ifdef COMMON
        mv_2 = nil;
#endif
        return nvalues(nil, 2);
    }
    {   Lisp_Object s;
        push2(str, p);
        s = (Lisp_Object)getvector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
        pop(p);
        errexit();
        qheader(s) = TAG_ODDS+TYPE_SYMBOL;
#ifdef COMMON
        if (p == qvalue(keyword_package) && keyword_package != nil)
        {   qvalue(s) = (Lisp_Object)s;
            qheader(s) |= SYM_SPECIAL_VAR;
        }
        else
#endif
        qvalue(s) = unset_var;
        qpname(s) = qpname(nil);    /* At this stage the pname is a dummy */
        qplist(s) = nil;
        qfastgets(s) = nil;
#ifdef COMMON
        qpackage(s) = p;
#endif
        qenv(s) = (Lisp_Object)s;
        ifn1(s) = (intptr_t)undefined1;
        ifn2(s) = (intptr_t)undefined2;
        ifnn(s) = (intptr_t)undefinedn;
        qcount(s) = 0;
        push(s);
#ifdef COMMON
        if ((p == qvalue(keyword_package) && keyword_package != nil) ||
             str_is_ok == 2)
        {   add_to_externals(s, p, hash);
            errexitn(2);
            qheader(s) |= SYM_EXTERN_IN_HOME;
        }
        else
#endif
        add_to_internals(s, p, hash);
        pop(s); pop(str);
        errexit();
/* Now the symbol-head is safe enough that I can let the GC look at it */
        if (str_is_ok != 0) qpname(s) = str;
        else
        {   Lisp_Object pn;
            push(s);
            pn = copy_string(str, h);
            pop(s);
            qpname(s) = pn;
        }
        errexit();
#ifdef COMMON
        mv_2 = nil;
#endif
        return nvalues((Lisp_Object)s, 2);
    }
}

#ifdef COMMON
static Lisp_Object Lfind_package(Lisp_Object nil, Lisp_Object name);

Lisp_Object Lintern_2(Lisp_Object nil, Lisp_Object str, Lisp_Object pp)
#else
Lisp_Object Lintern(Lisp_Object nil, Lisp_Object str)
#endif
/*
 * Lisp entrypoint for (intern ..)
 */
{
    Header h;
    Lisp_Object p;
#ifdef COMMON
    push(str);
    p = Lfind_package(nil, pp);
    pop(str);
    errexit();
#else
    p = CP;
#endif
#ifdef COMMON
    if (complex_stringp(str))
    {   push(p);
        str = simplify_string(str);
        pop(p);
        errexit();
    }
#endif
/*
 * For COMMON it is perhaps undue generosity to permit a symbol here
 * rather than just a string.  However it will make life a bit easier for
 * me in porting existing code.  Note that the Common Lisp book says quite
 * explicitly that symbols are NOT allowed here.
 */
    if (symbolp(str))
    {   str = get_pname(str);
        errexit();
    }
    if (!is_vector(str) ||
        type_of_header(h = vechdr(str)) != TYPE_STRING)
        return aerror1("intern (not a string)", str);
    return iintern(str, length_of_header(h) - CELL, p, 1);
}

#ifdef COMMON

Lisp_Object Lintern(Lisp_Object nil, Lisp_Object a)
{
    return Lintern_2(nil, a, CP);
}

static Lisp_Object Lfind_symbol(Lisp_Object nil,
                                Lisp_Object str, Lisp_Object pp)
{
    Header h;
    Lisp_Object p;
    push(str);
    p = Lfind_package(nil, pp);
    pop(str);
    errexit();
    if (symbolp(str))
    {   push(p);
        str = get_pname(str);
        pop(p);
        errexit();
    }
    if (complex_stringp(str))
    {   push(p);
        str = simplify_string(str);
        pop(p);
        errexit();
    }
    if (!is_vector(str) ||
        type_of_header(h = vechdr(str)) != TYPE_STRING)
    {
        return aerror1("find-symbol (not a string)", str);
    }
    return iintern(str, length_of_header(h) - CELL, p, 3);
}

Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str)
{
    return Lfind_symbol(nil, str, CP);
}

static Lisp_Object Lextern(Lisp_Object nil,
                           Lisp_Object sym, Lisp_Object package)
/*
 * If sym is internal in given package make it external - the inside parts
 * of the export function. Note that the second argument must be a real
 * package object, not a package name. Higher level code must have done
 * a find-package as necessary.
 */
{
    if (!is_symbol(sym)) return onevalue(nil);
    if (remob(sym, packint_(package), packvint_(package)))
    {   Lisp_Object n = packnint_(package);
        Lisp_Object v = packint_(package);
        int32_t used = int_of_fixnum(packvint_(package));
        if (used == 1) used = length_of_header(vechdr(v));
        else used = 16384*used;
/*
 * I will shrink a hash table if a sequence of remob-style operations,
 * which will especially include the case where a symbol ceases to be
 * internal to a package so that it can be external, leaves the table
 * less than 25% full. Note that normal growth is supposed to leave these
 * tables between 35 and 70% full, so the activity here will not be
 * triggered frivolously.  However note the following oddity: if a package
 * is of minimum size (8 entries in the hash table) then rehashing will not
 * cause it to shrink (but it will rehash and hence tidy it up). Hence
 * every remob on such a table will cause it to be re-hashed.
 */
        if ((int32_t)n < used && used>INIT_OBVECI_SIZE+CELL)
        {   stackcheck3(0, sym, package, v);
            push2(sym, package);
            v = rehash(v, packvint_(package), -1);
            pop2(package, sym);
            errexit();
            packint_(package) = v;
            packvint_(package) = fixnum_of_int(number_of_chunks);
        }
        packnint_(package) -= (1<<4);   /* decrement as fixnum */
/*
 * removed_hash was left set up by remob, and it is known that the symbol
 * was not already external, since it had been internal.
 */
        if (qpackage(sym) == package) qheader(sym) |= SYM_EXTERN_IN_HOME;
        add_to_externals(sym, package, removed_hash);
        errexit();
        return onevalue(lisp_true);
    }
    return onevalue(nil);/* no action if it was not internal in this package */
}

static Lisp_Object Lextern_1(Lisp_Object nil, Lisp_Object str)
{
    return Lextern(nil, str, CP);
}

static Lisp_Object Limport(Lisp_Object nil,
                           Lisp_Object sym, Lisp_Object package)
/*
 * The internal part of the IMPORT and SHADOWING-IMPORT functions.
 * makes sym internal in package. The symbol MUST NOT be present there
 * before this function is called. The second argument must be a real
 * package object, not just the name of one.
 */
{
    uint32_t hash;
    Lisp_Object pn;
    if (!is_symbol(sym)) return onevalue(nil);
    push2(sym, package);
    pn = get_pname(sym);
    errexitn(2);
    hash = hash_lisp_string(pn);
    add_to_internals(stack[-1], stack[0], hash);
    pop2(package, sym);
    errexit();
    if (qpackage(sym) == nil) qpackage(sym) = package;
    return onevalue(nil);
}

static Lisp_Object Limport_1(Lisp_Object nil, Lisp_Object str)
{
    return Limport(nil, str, CP);
}

#endif

Lisp_Object ndelete(Lisp_Object a, Lisp_Object l)
/*
 * Probably useful in various places throughout the system...
 */
{
#ifdef COMMON
    Lisp_Object nil = C_nil;
#endif
    if (!consp(l)) return l;
    if (a == qcar(l)) return qcdr(l);
    {   Lisp_Object z1 = l, z2 = qcdr(l);
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

Lisp_Object Lunintern_2(Lisp_Object nil, Lisp_Object sym, Lisp_Object pp)
{
    Lisp_Object package;
#ifdef COMMON
    push(sym);
    package = Lfind_package(nil, pp);
    pop(sym);
    errexit();
#else
    package = pp;
#endif
    if (!is_symbol(sym)) return onevalue(nil);
#ifdef COMMON
    if (qpackage(sym) == package) qpackage(sym) = nil;
    packshade_(package) = ndelete(sym, packshade_(package));
#endif
    if ((qheader(sym) & SYM_C_DEF) != 0)
        return aerror1("remob on function with kernel definition", sym);
    if (remob(sym, packint_(package), packvint_(package)))
    {   Lisp_Object n = packnint_(package);
        Lisp_Object v = packint_(package);
        int32_t used = int_of_fixnum(packvint_(package));
        if (used == 1) used = length_of_header(vechdr(v));
        else used = 16384*used;
        if ((int32_t)n < used && used>INIT_OBVECI_SIZE+CELL)
        {   stackcheck2(0, package, v);
            push(package);
            v = rehash(v, packvint_(package), -1);
            pop(package);
            errexit();
            packint_(package) = v;
            packvint_(package) = fixnum_of_int(number_of_chunks);
        }
        packnint_(package) -= (1<<4);   /* decrement as fixnum */
        return onevalue(lisp_true);
    }
#ifdef COMMON
    if (remob(sym, packext_(package), packvext_(package)))
    {   Lisp_Object n = packnext_(package);
        Lisp_Object v = packext_(package);
        int32_t used = int_of_fixnum(packvext_(package));
        if (used == 1) used = length_of_header(vechdr(v));
        else used = 16384*used;
        if ((int32_t)n < used && used>INIT_OBVECX_SIZE+CELL)
        {   stackcheck2(0, package, v);
            push(package);
            v = rehash(v, packvext_(package), -1);
            pop(package);
            errexit();
            packext_(package) = v;
            packvext_(package) = fixnum_of_int(number_of_chunks);
        }
        packnext_(package) -= (1<<4);   /* decrement as fixnum */
        return onevalue(lisp_true);
    }
#endif
    return onevalue(nil);
}

Lisp_Object Lunintern(Lisp_Object nil, Lisp_Object str)
{
    return Lunintern_2(nil, str, CP);
}

#ifdef COMMON

static Lisp_Object Lkeywordp(Lisp_Object nil, Lisp_Object a)
{
    if (!symbolp(a)) return onevalue(nil);
    return onevalue(Lispify_predicate(qpackage(a) == qvalue(keyword_package)));
}

#endif

/*
 * If I have a window system then getting characters from the keyboard
 * is deemed a system-dependent activity.  On non-windowed systems I still
 * do rather more than just getchar(), although under typical Unix what I
 * do here may count as over-kill.
 */

int tty_count;
#define TTYBUF_SIZE 256
#ifdef Kanji
static kchar_t tty_buffer[TTYBUF_SIZE];
static kchar_t *tty_pointer;
#else
/*
 * Note: I should never have an END_OF_FILE in the buffere here: if I see
 * this condition I pack in the character CTRL-D instead.
 */
static char tty_buffer[TTYBUF_SIZE];
static char *tty_pointer;
#endif

#if !defined HAVE_FWIN || defined EMBEDDED
static CSLbool int_nest = NO;
#endif

#ifndef HAVE_FWIN
static int prevchar = '\n';
#endif

int terminal_pushed = NOT_CHAR;

static int kilo = 0;

int char_from_terminal(Lisp_Object dummy)
/*
 * "What ..." you might ask, "is the meaning of this mess?".  Well the answer
 * is that when input is directly from the terminal I buffer up to 256
 * characters in a private buffer, and I discount the time spent filling this
 * buffer. On some miserable systems this will succeed in ensuring that the
 * time reported at the end of a run reflects time that CSL spends computing
 * and not time it spends waiting for the user to type something at it.  Note
 * that it is only stdin input that I intercept in this way, so the full cost
 * of getting characters from disc files will be accounted.  I also (rather
 * improperly) map EOF onto a code (4) which will fit in a byte-sized buffer.
 * I fill by buffer up as far as a newline or a vertical tab (or end of file),
 * and hope that that will not seriously hurt any interactions with CSL.
 * After all the operating system may well line-buffer input anyway, so that
 * it can deal with the delete key on your keyboard for you.
 *
 * Furthermore here is where I display prompt strings to the user -
 * in a way that Standard Lisp does not define, but PSL implements and
 * some REDUCE programmers have come to expect... (in some cases I will
 * let lower level code deal with prompts).
 *
 * If the user provokes an interrupt (^C, or ESC or whatever) while I am
 * in here I will try to return promptly with an empty buffer and
 * some indication of an exception.
 */
{
/*
 * I have a hook here for cases where I want to call CSL from other C
 * code.  In that case the variable used here points at a function that
 * reads a single character.  When I use this option I will NOT generate
 * prompts.
 */
    int c;
    Lisp_Object nil = C_nil;
    CSL_IGNORE(dummy);
    if (++kilo >= 1024)
    {   kilo = 0;
        io_now++;
    }
    if (terminal_pushed != NOT_CHAR)
    {   c = terminal_pushed;
        terminal_pushed = NOT_CHAR;
        return c;
    }
    if (procedural_input != NULL) c = (*procedural_input)();
    else if (non_terminal_input != NULL)
    {
#ifdef Kanji
        c = getwc(non_terminal_input);
#else
        c = getc(non_terminal_input);
#endif
    }
    else
    {   if (tty_count == 0)
        {
/*
 * Time spent waiting for keyboard input is not counted against the user.
 */
            push_clock();
#ifdef HAVE_FWIN
/* Under FWIN I will arrange prompts at a lower level. */
#else
            if (prevchar == '\n')
            {   escaped_printing = 0;
                if (prompt_thing != nil)
                {   push(active_stream);
                    active_stream = qvalue(terminal_io);
                    if (!is_stream(active_stream))
                        active_stream = lisp_terminal_io;
                    internal_prin(prompt_thing, NO);
                    nil = C_nil;
                    if (exception_pending()) flip_exception();
                    pop(active_stream);
                }
            }
            ensure_screen();
            if (exception_pending()) 
            {   pop_clock();
                return EOF;
            }
#endif
#ifdef WINDOW_SYSTEM
#ifndef HAVE_FWIN
            if (use_wimp)
#endif
            {   tty_count = wimpget(tty_buffer);
#ifdef HAVE_FWIN
/*
 * With FWIN, wimpget() always returns, but sometimes it will have set
 * a stack overflow condition to mark that the user has tried to
 * signal an exception via ^C or ^G. In which case I just want to
 * return promptly.
 */
                if (stack >= stacklimit)
                {   reclaim(nil, "stack", GC_STACK, 0);
                    nil = C_nil;
                    if (exception_pending())
                    {   pop_clock();
                        return (0x1f & 'C');
                    }
                }
            }
#else /* HAVE_FWIN */
                if (exception_pending())
                {   pop_clock();
                    return EOF;
                }
                if (interrupt_pending)
                {   interrupt_pending = 0;
                    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
                        err_printf("+++ Interrupted\n");
                    exit_reason = 
                        (miscflags & (MESSAGES_FLAG|ALWAYS_NOISY)) ? 
                        UNWIND_ERROR : UNWIND_UNWIND;
                    exit_value = exit_tag = nil;
                    exit_count = 0;
                    flip_exception();
                }
            }
            else
#endif /* HAVE_FWIN */
#endif /* WINDOW_SYSTEM */
#if !defined HAVE_FWIN || defined EMBEDDED
/*
 * Here I either do not have a window system or I have elected not to use it.
 * but note that with fwin I am simplifying things and always do the calls
 * as if windowing was going on even when it is not!
 */
            for (;;) /* The while loop is so I can restart after ^C */
            {
/*
 * The setjmp here can not mask any bindings of fluid variables...
 */
                errorset_msg = NULL;
#ifdef __cplusplus
                try
#else
                if (!setjmp(sigint_buf))
#endif
                {   while (tty_count<TTYBUF_SIZE && !interrupt_pending)
                    {   int c;
                        sigint_must_longjmp = YES;
#ifdef Kanji
                        c = getwc(stdin);
#else
                        c = getchar();
#endif
                        sigint_must_longjmp = NO;
                        if (c == EOF)
                        {   clearerr(stdin);    /* Believed to be what is wanted */
                            c = CTRL_D;         /* Use ASCII ^D as EOF marker */
                        }
                        tty_buffer[tty_count++] = (char)c;
                        if (c == '\n' || c == '\v' || c == CTRL_D) break;
                    }
                    if (interrupt_pending)
                    {   push_clock();
/*
 * Time spent in the interrupt handler here will not be counted as CPU
 * time used.
 */
                        interrupt_pending = NO;
                        if (int_nest)
                        {   err_printf("\n+++ Nested interrupt ignored\n");
                            tty_count = 0;
                            break;
                        }
                        else
                        {   int_nest = YES;
                            interrupted(nil);
                            int_nest = NO;
                        }
                        pop_clock();
                        tty_count = 0;
                        nil = C_nil;
                        if (!exception_pending()) continue;
                    }
                    break;
                }
#ifdef __cplusplus
                catch (int *)
#else
                else
#endif
                {   if (errorset_msg != NULL)
                    {   term_printf("\n%s detected\n", errorset_msg);
                        errorset_msg = NULL;
                    }
                    sigint_must_longjmp = NO;
                    interrupt_pending = YES;
                    tty_count = 0;
                }
            }
#endif /* HAVE_FWIN */
            pop_clock();
            tty_pointer = tty_buffer;
        }
        if (tty_count == 0) c = '\n'; /* ^C odd case */
        else
        {   tty_count--;
            c = *tty_pointer++;
#ifndef Kanji
            c &= 0xff;
#endif
        }
    }
    inject_randomness(c);
    if (c == EOF || c == CTRL_D) return EOF;
    if (qvalue(echo_symbol) != nil)
    {   Lisp_Object stream = qvalue(standard_output);
        if (!is_stream(stream)) stream = qvalue(terminal_io);
        if (!is_stream(stream)) stream = lisp_terminal_io;
        putc_stream(c, stream);
        if (exception_pending()) flip_exception();
    }
    else if (spool_file != NULL) putc(c, spool_file);
    return c;
}


Lisp_Object Lrds(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object old = qvalue(standard_input);
    if (a == nil) a = qvalue(terminal_io);
    if (a == old) return onevalue(old);
    else if (!is_stream(a)) return aerror1("rds", a);
    else if (stream_read_fn(a) == char_from_illegal)
        return aerror("rds"); /* closed stream or output stream */
    qvalue(standard_input) = a;
    return onevalue(old);
}

Lisp_Object Lrtell_1(Lisp_Object nil, Lisp_Object stream)
{
    int32_t n;
    if (!is_stream(stream)) return onevalue(nil);
    n = other_read_action(READ_TELL, stream);
    if (n == -1) return onevalue(nil);
    else return onevalue(fixnum_of_int(n));
}

Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...)
/*
 * RTELL returns an integer that indicates the position of the current
 * input stream (as selected by RDS). If the position is not available
 * (as would be the case for an interactive stream) then NIL is returned.
 * Otherwise the result is an integer suitable for use with rseek.  In the
 * case that the file was opened in binary mode the number returned is a
 * direct indication of the position in the file and arithmetic will
 * behave predictably - for text streams the value returned should be
 * thought of as an abstract position-tag.
 */
{
    argcheck(nargs, 0, "rtell");
    return Lrtell_1(nil, qvalue(standard_input));
}

Lisp_Object Lrseekend(Lisp_Object nil, Lisp_Object stream)
{
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    other_read_action(READ_FLUSH, stream);
    if (other_read_action(READ_END, stream) != 0) return onevalue(nil);
    else return onevalue(lisp_true);
}

Lisp_Object Lrseek_2(Lisp_Object nil, Lisp_Object stream, Lisp_Object a)
{
    int32_t n;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (is_fixnum(a)) n = (int32_t)int_of_fixnum(a);
    else return aerror("rseek");
    other_read_action(READ_FLUSH, stream);
    if (other_read_action(n | 0x80000000, stream) != 0) return onevalue(nil);
    else return onevalue(lisp_true);
}

Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a)
/*
 * If the current input stream supports random access this re-positions
 * it to a place indicated by the argument a.  If the file was opened in
 * binary mode then a can be an integer indicating how far down the file
 * to set the position.  For text files arguments to RSEEK should only be
 * values returned by previous calls to RTELL.  RSEEK returns nil if it
 * failed (and if it noticed that fact) or T if it succeeded.
 */
{
    return Lrseek_2(nil, qvalue(standard_input), a);
}

/*
 * The getc_stream() method must NEVER be able to cause garbage collection,
 * since I code the reader here on the assumption that file control blocks
 * do not move while individual characters are read.
 */


/*
 * While I am in the middle of reading a whole expression the variable
 * curchar will hold the most recent character (or NOT_CHAR if there is none),
 * but between expressions I will push that back into the stream header.
 */

static void skip_whitespace(Lisp_Object stream)
{
    Lisp_Object nil;
    for (;;)
    {   switch (curchar)
        {
    case NOT_CHAR:
    case 0:    case '\v':   case '\f':
    case ' ':  case '\t':   case '\n':
    case '\r': case CTRL_C:
            curchar = getc_stream(stream);
            errexitv();
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
                errexitv();
            }
            continue;

    default:
            return;
        }
    }
}

static Lisp_Object read_s(Lisp_Object stream);

#ifdef COMMON
static Lisp_Object read_hash(Lisp_Object stream);
#endif

static Lisp_Object read_list(Lisp_Object stream)
/*
 * There is no code here to do anything about general read-macros,
 * and it will be awkward to fit it in here because of the reliance
 * that the Common Lisp readmacro scheme puts on the ability to return
 * no values at all using (values).  I implement ' and ; and ` since
 * they seem very useful, but only simple cases of #.
 * I require that when this function is called I have already done
 * a skip_whitespace(), and as a result curchar will not be NOT_CHAR.
 */
{
    Lisp_Object l, w, nil = C_nil;
    stackcheck0(0);
    if (curchar == ')')
    {   curchar = NOT_CHAR;
        return C_nil;
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
    errexitn(1);
    l = ncons(l);
    errexitn(1);
    push(l);    /* this will be the final result */
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

    /* This code treats '.' as a special lexical marker, while the */
    /* full version of the reader has to be more subtle.           */
    case '.':
            curchar = NOT_CHAR;
            push(l);
            w = read_s(stack[-2]);
            pop(l);
            errexitn(2);
            qcdr(l) = w;
            skip_whitespace(stack[-1]);
            if (curchar == ')') curchar = NOT_CHAR;
/*          else error("missing rpar or bad dot");               */
            pop2(l, stream);
            return l;
#ifdef COMMON
    case '#':
            push(l);
            w = read_hash(stack[-2]);
            errexitn(3);
            if (w == SPID_NOINPUT)
            {   pop(l);
                continue;
            }
            w = ncons(w);
            errexitn(3);
            pop(l);
            qcdr(l) = w;
            l = w;
            continue;
#endif
    default:
            push(l);
            w = read_s(stack[-2]);
            errexitn(3);
            w = ncons(w);
            errexitn(3);
            pop(l);
            qcdr(l) = w;
            l = w;
            continue;
        }
    }
}

static Lisp_Object list_to_vector(Lisp_Object l)
{
    int32_t len = 0;
    Lisp_Object p = l, nil = C_nil;
    while (consp(p)) len++, p = qcdr(p);
    push(l);
    p = getvector_init(CELL*(len+1), nil);
    pop(l);
    errexit();
    len = 0;
    while (consp(l))
    {   elt(p, len) = qcar(l);
        len++;
        l = qcdr(l);
    }
    return p;
}

#ifdef COMMON

static CSLbool evalfeature(Lisp_Object u)
{
    Lisp_Object w, nil = C_nil;
    if (consp(u))
    {   Lisp_Object fn = qcar(u);
        u = qcdr(u);
        if (!consp(u)) return NO;
        if (fn == not_symbol) return !evalfeature(qcar(u));
        else if (fn == and_symbol)
        {   while (consp(u))
            {   if (!evalfeature(qcar(u))) return NO;
                nil = C_nil;
                if (exception_pending()) return NO;
                u = qcdr(u);
            }
            return YES;
        }
        else if (fn == or_symbol)
        {   while (consp(u))
            {   if (evalfeature(qcar(u))) return YES;
                nil = C_nil;
                if (exception_pending()) return NO;
                u = qcdr(u);
            }
            return NO;
        }
        else return NO;
    }
    w = qvalue(features_symbol);
    while (consp(w))
    {   if (u == qcar(w)) return YES;
        w = qcdr(w);
    }
    return NO;
}

static Lisp_Object read_hash(Lisp_Object stream)
{
/*
 * A small subset of the # escaped read-macros will be supported here.
 * curchar must already be set to the character that follows the '#'
 */
    int32_t v, w = -1;
    int radix;
    Lisp_Object nil = C_nil;
    Lisp_Object p;
    curchar = getc_stream(stream);
    errexit();
    if (ISdigit(curchar))
    {   w = 0;
        do
        {   w = 10*w + curchar - '0';
/*
 * Observe that I do not do long arithmetic here!
 */
            curchar = getc_stream(stream);
            errexit();
        } while (ISdigit(curchar));
    }
    switch (curchar)
    {
default:
/*      error("Unknown # escape");  */
        return pack_char(0, 0, '#');
#ifdef COMMON
case '#':
        curchar = NOT_CHAR;
        p = reader_workspace;
        while (p != nil)
        {   Lisp_Object k = qcar(p);
            if (fixnum_of_int(w) == qcar(k)) return qcdr(k);
            p = qcdr(p);
        }
        return aerror1("Label not found with #n# syntax", fixnum_of_int(w));
case '=':
        curchar = NOT_CHAR;
        push(stream);
/*
 * Hmmm - is it necessary for #nn# to refer back to the label here from
 * within the value about to be read?
 */
        p = read_s(stream);
        pop(stream);
        errexit();
        push(p);
        p = acons(fixnum_of_int(w), p, reader_workspace);
        errexitn(1);
        reader_workspace = p;
        pop(p);
        return p;
#endif
case ':':       /* #:XXX reads in a gensym... */
        curchar = NOT_CHAR;
        {   Lisp_Object base = read_s(stream), al;  /* The XXX bit unadorned */
            errexit();
/*
 * This keeps an association list of gensyms present in this call to READ.
 * Note that if you use #.(read) [or other clever things] you may get
 * muddled about contexts.  Note that this is sometimes helpful with
 * Standard Lisp but that for Common Lisp the more general #= and ##
 * mechanism should be used and this behaviour here would count as
 * WRONG.
 */
            al = reader_workspace;
            while (al != nil)
            {   Lisp_Object k = qcar(al);
                if (base == qcar(k)) return qcdr(k);
                al = qcdr(al);
            }
            push(base);
/*
 * Beware that #:ggg has just ggg as its name, with no numeric suffix.
 */
            al = Lgensym2(nil, base);
            pop(base);
            errexit();
            al = acons(base, al, reader_workspace);
            errexit();
            reader_workspace = al;
            return qcdr(qcar(al));
        }
            
case '(':       /* Simple vector */
        curchar = getc_stream(stream);
        errexit();
        skip_whitespace(stream);
        errexit();
        {   Lisp_Object l = read_list(stream);
            errexit();
            return list_to_vector(l);
        }
case '\'':
        curchar = NOT_CHAR;
        p = read_s(stream);
        errexit();
        return list2(function_symbol, p);
case '\\':
/*
 * The character just after "#\" is read without any case folding
 */
        curchar = getc_stream(stream);
        errexit();
        w = curchar;
#ifdef COMMON
/*
 * The word after "#\" is always spelt in regular ASCII so Kanji support
 * does not cut in here.
 */
        if (isalpha(w))
        {   char buffer[32];
            int bp = 0, w0 = w;
            while (isalpha(w) && bp < 30)
            {   buffer[bp++] = toupper(w);  /* Force word to upper case */
                curchar = getc_stream(stream);
                errexit();
                w = curchar;
            }
            if (bp == 1) 
#ifdef Kanji
                return pack_char(0, 0, w0 & 0xffff);
#else
                return pack_char(0, 0, w0 & 0xff);
#endif
            buffer[bp] = 0;
            p = make_string(buffer);
            errexit();
            p = Lintern_2(nil, p, qvalue(keyword_package));
            errexit();
            p = get(p, named_character, nil);
            errexit();
            return p;
        }
#endif
        curchar = NOT_CHAR;
        errexit();
#ifdef Kanji
        return pack_char(0, 0, w & 0xffff);
#else
        return pack_char(0, 0, w & 0xff);
#endif
case '.':
        curchar = NOT_CHAR;
        p = read_s(stream);
        errexit();
/*
 * The next is in case the expression evaluated involves reading from
 * this or another stream.
 */
        if (curchar != NOT_CHAR)
        {   other_read_action(curchar, stream);
            curchar = NOT_CHAR;
        }
        p = eval(p, nil);
        errexit();
        return onevalue(p);
case '+':
case '-':
        v = (curchar == '-');
        curchar = NOT_CHAR;
/*
 * In March 1988 X3J13 voted that feature names read here should be in
 * the keyword package unless explicily otherwise qualified, but (I guess)
 * the AND, OR and NOT operators applying to them are NOT in the keyword
 * package. Thus I can not just rebind *package* here in any simple way.
 * Oh dear - I hope nobody relies on what those kind experts decided!
 * Meanwhile REMEMBER to go    #+ :whatever     please.
 */
        push(stream);
        p = read_s(stream);
        errexitn(1);
        w = evalfeature(p);
        pop(stream);
        errexit();
        if (w == v)
        {   read_s(stream);
            errexit();
        }
/*
 * The following flag-value shows that read_hash() has not actually read
 * anything - but it may have skipped over some unwanted stuff.
 */
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
/* Here I have a number specified in some unusual radix */
    w = fixnum_of_int(0);
    curchar = getc_stream(stream);
    errexit();
    while ((v = value_in_radix(curchar, radix)) >= 0)
    {   w = times2(w, fixnum_of_int((int32_t)radix));
        errexit();
        w = plus2(w, fixnum_of_int(v));
        errexit();
        curchar = getc_stream(stream);
        errexit();
    }
    return w;
}

#endif /* COMMON */

CSLbool is_constituent(int c)
{
    if (c == EOF) return NO;
    if (c & ESCAPED_CHAR) return YES;   /* escaped */
    switch (c)
    {
/* The following characters terminate symbols */
case ' ':   case '\n':  case '\t':  case '\v':  case '\f':  case 0:
case '(':   case ')':   case '\'':  case ';':   case '"':   case '`':
case ',':   case '\r':
case CTRL_D:     /* character 4 is EOF in ASCII */
#ifndef COMMON
case '+':   case '-':   case '*':   case '/':   case '~':   case '\\':
case '@':   case '#':   case '$':   case '%':   case '^':   case '&':
case '=':   case '{':   case '}':   case '[':   case ']':   case ':':
case '<':   case '>':   case '?':   case '!':   case '|':
/*
 * case '_':    In OLD Standard Lisp underscore was a break character -
 * these days it is classified rather oddly, in that it does not terminate
 * a symbol but behaves specially if it starts one.
 * What about '.', which may need to be treated specially?
 */
case '.':
#endif
        return NO;
default:
        return YES;
    }
}

static Lisp_Object backquote_expander(Lisp_Object a)
/*
 * ClTl (edition 2) seems to suggest that nested backquotes are a disgusting
 * morass - this code does not worry about the fine details!
 */
{
    Lisp_Object w1, f, nil = C_nil;
    if (a == nil) return a;
    if (!consp(a)) return list2(quote_symbol, a);
    stackcheck1(0, a);
    nil = C_nil;
    f = qcar(a);
    if (f == comma_symbol) return qcar(qcdr(a));
    if (consp(f) && qcar(f) == comma_at_symbol)
    {   w1 = qcar(qcdr(f));
        push(w1);
        a = backquote_expander(qcdr(a));
        errexit();
        pop(w1);
        w1 = list2(w1, a);
        errexit();
        return cons(append_symbol, w1);
    }
/*
 * There is noticable scope for further optimisation here, with the
 * introduction of uses of list, list* as well as just cons and append.
 * It is also probably useful to worry about ,. as well as ,@ but for
 * now I defer that until the full version of the reader is installed.
 */
    push(a);
    f = backquote_expander(f);
    pop(a);
    errexit();
    push(f);
    a = backquote_expander(qcdr(a));
    pop(f);
    errexit();
    a = list2(f, a);
    errexit();
    return cons(cons_symbol, a);
}

static CSLbool read_failure;

static void packbyte(int c)
{
    Lisp_Object nil = C_nil;
    int32_t boffo_size = length_of_header(vechdr(boffo));
/*
 * I expand boffo (maybe) several characters earlier than you might
 * consider necessary. Some of that is to be extra certain about having
 * space in it when I pack a multi-byte (eg Kanji) character.
 */
    if (boffop >= (int)boffo_size-(int)CELL-8)
    {   Lisp_Object new_boffo =
            getvector(TAG_VECTOR, TYPE_STRING, 2*boffo_size);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
/*
 * What should I do if I fail to expand boffo - for present I silently
 * truncate the object I am reading.  But I set a flag that will be checked
 * on the way out of read/compress, so the user will know.
 */
            read_failure = YES;
            return;
        }
        memcpy((void *)((char *)new_boffo + (CELL-TAG_VECTOR)),
               &boffo_char(0), boffop);
        boffo = new_boffo;
    }
#ifdef Kanji
    if (iswchar(c)) boffo_char(boffop++) = c >> 8;
#endif
    boffo_char(boffop) = (char)c;
    boffop++;
}

#ifdef COMMON
static char package_name[32];
#endif

static Lisp_Object read_s(Lisp_Object stream)
{
    Lisp_Object w, nil = C_nil;
    for (;;)
    {   skip_whitespace(stream);
        errexit();
        switch (curchar)
        {
    case EOF:
    case CTRL_D:
            return CHAR_EOF;

    case '(':
            curchar = NOT_CHAR;
            skip_whitespace(stream);
            errexit();
            return read_list(stream);

#ifndef COMMON
    case '[':
            curchar = NOT_CHAR;
            skip_whitespace(stream);
            errexit();
            w = read_list(stream);
            errexit();
            return list_to_vector(w);

    case ']':
#endif
    case ')':
            curchar = NOT_CHAR;
            continue;               /* Ignore spurious rpar */

    case '\'':
            curchar = NOT_CHAR;
            w = read_s(stream);
            errexit();
            return list2(quote_symbol, w);

    case '`':
            curchar = NOT_CHAR;
            w = read_s(stream);
            errexit();
            return backquote_expander(w);

    case ',':
            curchar = getc_stream(stream);
            errexit();
            if (curchar == '@')
            {   curchar = NOT_CHAR;
                w = read_s(stream);
                errexit();
                return list2(comma_at_symbol, w);
            }
            else
            {   w = read_s(stream);
                errexit();
                return list2(comma_symbol, w);
            }

/*
 * Neither Standard nor Common Lisp make stray dots very welcome. In Common
 * Lisp multiple adjacent dots are supposed to be an error. Here I just ignore
 * stray dots, and hope that nobody is silly enough to have them in their code.
 */
    case '.':
/*          error("Bad dot");       */
            curchar = NOT_CHAR;
            continue;               /* Ignore spurious dot */

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
            {   for (;;)    /* Used to cope with "abc""def" */
                {   curchar = getc_stream(stream);
                    errexit();
#ifdef COMMON
                    if (curchar == ESCAPE_CHAR)
                    {   curchar = getc_stream(stream);
                        errexit();
                        if (curchar!=EOF) curchar |= ESCAPED_CHAR;
                    }
#endif
                    if (curchar == EOF || curchar == CTRL_D)
                        return CHAR_EOF;
                    while (curchar != '"' &&
                           curchar != EOF &&
                           curchar != CTRL_D)
                    {   push(stream);
                        packbyte(curchar);
                        pop(stream);
                        curchar = getc_stream(stream);
                        errexit();
#ifdef COMMON
                        if (curchar == ESCAPE_CHAR)
                        {   curchar = getc_stream(stream);
                            errexit();
                            if (curchar!=EOF) curchar |= ESCAPED_CHAR;
                        }
#endif
                    }
#ifndef COMMON
                    curchar = getc_stream(stream);
                    errexit();
                    if (curchar == '"')
                    {   push(stream);
                        packbyte(curchar);
                        pop(stream);
                        continue;    /* Handle "abc""def" for Standard Lisp */
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
/*
 * I treat numbers specially here since I want to allow '.' within
 * numbers, but NOT within symbols.  Common Lisp views '.' as a
 * constituent character and so does not need quite so much effort
 * just here.
 */
            {   boffop = 0;
                if (curchar == '+' || curchar == '-')
                {   push(stream);
                    packbyte(curchar);
                    pop(stream);
                    curchar = getc_stream(stream);
                    errexit();
/* + or - not followed by a digit will be read as a symbol */
                    if (!ISdigit(curchar)) return intern(boffop, NO);
                }
                while (ISdigit(curchar))
                {   push(stream);
                    packbyte(curchar);
                    pop(stream);
                    curchar = getc_stream(stream);
                    errexit();
                }
/* accept possible decimal point */
                if (curchar == '.')
                {   push(stream);
                    packbyte(curchar);
                    pop(stream);
                    curchar = getc_stream(stream);
                    errexit();
                    while (ISdigit(curchar))
                    {   push(stream);
                        packbyte(curchar);
                        pop(stream);
                        curchar = getc_stream(stream);
                        errexit();
                    }
                }
/* accept possible exponent */
                if (curchar == 'e' || curchar == 'E')
                {   push(stream);
                    packbyte('e');
                    pop(stream);
                    curchar = getc_stream(stream);
                    errexit();
                    if (curchar == '+' || curchar == '-')
                    {   push(stream);
                        packbyte(curchar);
                        pop(stream);
                        curchar = getc_stream(stream);
                        errexit();
                    }
                    while (ISdigit(curchar))
                    {   push(stream);
                        packbyte(curchar);
                        pop(stream);
                        curchar = getc_stream(stream);
                        errexit();
                    }
                }
                return intern(boffop, NO);
            }

    case '_':       /* This seems to have to be a funny case for REDUCE */
            boffop = 0;
            push(stream);
            packbyte(curchar);
            pop(stream);
            curchar = getc_stream(stream);
            errexit();
            return intern(boffop, NO);
#endif

    default:
            {   CSLbool escaped = NO;
#ifdef COMMON
                CSLbool within_vbars = NO;
                int colon = -1, double_colon = -1, i;
#endif
                boffop = 0;
#ifdef COMMON
                while (curchar == '|')
                {   nil = C_nil;
                    stackcheck0(0);
                    curchar = getc_stream(stream);
                    errexit();
                    within_vbars = !within_vbars;
/*
 * A funny thought arises here - maybe the characters ||123 are a potential
 * number, since there are no characters inside the vertical bars to show
 * otherwise! Hence I need to set escaped only when I find a genuine character
 * within the vertical-bar protected region. Hence this coded as a while
 * loop not a simple IF statement. Another horrid issue is that the input
 * "|| " (where there are two initial vertical bars and then a terminating
 * character) ought to parse as an identifier with an empty name. Thus
 * if I read ahead here and find whitespace etc I need to exit here.
 */
                    if (!within_vbars && !is_constituent(curchar))
                        return intern(0, YES);
                }
#endif
                if (curchar == ESCAPE_CHAR)
                {   nil = C_nil;
                    stackcheck0(0);
                    curchar = getc_stream(stream);
                    errexit();
/* However, any character escaped with '\' means we do not have a number */
                    escaped = YES;
                }
                else
#ifdef COMMON
                if (!within_vbars)
                {   if (curchar == ':') colon = boffop, escaped = YES;
#else
                {
#endif
                    if (curchar != EOF)
                    {   if (qvalue(lower_symbol) != nil)
                            curchar = TOlower(curchar);
                        else if (qvalue(raise_symbol) != nil)
                            curchar = TOupper(curchar);
#ifdef Kanji
                        if (qvalue(hankaku_symbol) != nil)
                            is (iszenkaku(curchar))
                                curchar = tohankaku(curchar);
#endif
                    }
                }

/*
 * Here is the main loop that reads an identifier. Observe the extra
 * complication that Common Lisp generates with the need to support
 * package markers and '|' style escapes...
 */
                do
                {   push(stream);
                    packbyte(curchar);
                    pop(stream);
                    curchar = getc_stream(stream);
                    errexit();
#ifdef COMMON
                    if (within_vbars) escaped = YES;
                    while (curchar == '|')
                    {   nil = C_nil;
                        stackcheck0(0);
                        curchar = getc_stream(stream);
                        errexit();
                        within_vbars = !within_vbars;
                    }
#endif
                    if (curchar == EOF) break;
                    else if (curchar == ESCAPE_CHAR)
                    {   nil = C_nil;
                        stackcheck0(0);
                        curchar = getc_stream(stream);
                        errexit();
                        curchar |= ESCAPED_CHAR;
                        escaped = YES;
                    }
#ifdef COMMON
                    else if (!within_vbars)
                    {   if (curchar == ':')
                        {   if (colon >= 0) double_colon = boffop;
                            else colon = boffop, escaped = YES;
                        }
#endif
                        else if (qvalue(lower_symbol) != nil)
                            curchar = TOlower(curchar);
                        else if (qvalue(raise_symbol) != nil)
                            curchar = TOupper(curchar);
#ifdef Kanji
                        if (qvalue(hankaku_symbol) != nil)
                            is (iszenkaku(curchar))
                                curchar = tohankaku(curchar);
#endif
#ifdef COMMON
                    }
                } while (within_vbars || is_constituent(curchar));
#else
                } while (is_constituent(curchar));
#endif
#ifdef COMMON
/*
 * If there are no colons present, or if there are two but they
 * are not consecutive, or of there are three or more, or if the last
 * character of the symbol was a colon, I will just look it up in
 * the current package.
 */
                if (colon < 0 || colon+1==boffop)
                    return intern(boffop, escaped);
                if ((double_colon >= 0 && double_colon != colon+1) ||
                    double_colon+1==boffop)
                    return intern(boffop, escaped);
/*
 * If the first character was a colon I use the keyword package.
 */
                memset(package_name, 0, sizeof(package_name));
                strncpy(package_name, &celt(boffo, 0), (size_t)colon);
                package_name[sizeof(package_name)-1] = 0;
/* term_printf("Package lookup <%.*s>\n", (int)colon, &celt(boffo, 0)); */
                if (colon == 0) w = qvalue(keyword_package);
                else w = find_package(&celt(boffo, 0), colon);
/*
 * Here I rely on find_package never raising an exception and never giving
 * a possible entry into a break loop (etc), since I need boffo[] intact
 * after the call.
 */
                if (w == nil)
                {   err_printf(
                        "+++ Package %s not found: using current package\n",
                        package_name);
/*
 * Similarly I assume, unreasonably, that boffo can not be disturbed by
 * printing this warning message.
 */
                    w = CP; /* default behaviour: unknown package */
                }
                if (double_colon >= 0) colon = double_colon;
                i = 0;
                colon++;
                while (colon < boffop)
                    boffo_char(i++) = boffo_char(colon++);
                boffop = i;
/* term_printf("Name within package <%.*s>\n", (int)boffop, &celt(boffo, 0)); */
                if (double_colon < 0 && w != qvalue(keyword_package))
                {   /* In the case ppp:sss it MUST be external in ppp */
                    Lisp_Object wx;
                    push(w);
                    wx = iintern(boffo, (int32_t)boffop, w, 4);
                    pop(w);
                    errexit();
                    if (mv_2 == nil)
                    {   err_printf("+++ Symbol %.*s not external in %s\n",
                            (int)boffop, &celt(boffo, 0), package_name);
                        err_printf("+++ Treating as internal symbol...\n");
                    }
                    else return wx;
                }
/*
 * Curiously I will always take keywords (as in :kkk) through the path
 * that corresponds to looking up an internal symbol, ie ::kkk, since that
 * way I allow the reader to create a new symbol. If I handled the keyword
 * case in the usual external symbol way it would demand that the keyword
 * already existed (since in all other packages nothing is external unless
 * it already exists and has been exported).
 */
                return iintern(boffo, (int32_t)boffop, w, 0);
#else
                return intern(boffop, escaped);
#endif
            }
        }
    }
}

int char_from_synonym(Lisp_Object stream)
{
    stream = qvalue(stream_read_data(stream));
    if (!is_stream(stream)) return aerror1("bad synonym stream", stream);
    return getc_stream(stream);
}

int char_from_concatenated(Lisp_Object stream)
{
    Lisp_Object l = stream_read_data(stream), s1;
    Lisp_Object nil = C_nil;
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
        errexit();
        if (c == EOF)
        {   l = qcdr(l);
            stream_read_data(stream) = l;
            continue;
        }
    }
    return EOF;
}

int char_from_echo(Lisp_Object stream)
{
    int c;
    Lisp_Object stream1 = qvalue(stream_read_data(stream));
    if (!is_stream(stream1)) return aerror1("bad synonym stream", stream1);
    c = getc_stream(stream1);
    char_to_synonym(c, stream);
    return c;
}

int char_from_file(Lisp_Object stream)
{
    Lisp_Object nil = C_nil;
    int ch = stream_pushed_char(stream);
    if (ch == NOT_CHAR)
    {
        if (++kilo >= 1024)
        {   kilo = 0;
            io_now++;
        }
#ifdef Kanji
        ch = getwc(stream_file(stream));
#else
        ch = getc(stream_file(stream));
#endif
        if (ch == EOF
          /*    || ch == CTRL_D             */
           ) return EOF;
        if (qvalue(echo_symbol) != nil)
        {   Lisp_Object stream1 = qvalue(standard_output);
            if (!is_stream(stream1)) stream1 = qvalue(terminal_io);
            if (!is_stream(stream1)) stream1 = lisp_terminal_io;
            putc_stream(ch, stream1);
            if (exception_pending()) flip_exception();
        }
    }
    else stream_pushed_char(stream) = NOT_CHAR;
    return ch;
}

int32_t read_action_illegal(int32_t op, Lisp_Object f)
{
    CSL_IGNORE(f);
    if (op != READ_CLOSE && op != READ_IS_CONSOLE)
        aerror1("Illegal operation on stream",
                cons_no_gc(fixnum_of_int(op), stream_type(f)));
    return 0;
}

int32_t read_action_file(int32_t op, Lisp_Object f)
{
    if (op < -1) return fseek(stream_file(f), op & 0x7fffffff, SEEK_SET);
    else if (op <= 0xffff) return (stream_pushed_char(f) = op);
    else switch (op)
    {
case READ_CLOSE:
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

int32_t read_action_output_file(int32_t op, Lisp_Object f)
{
    if (op < -1) return fseek(stream_file(f), op & 0x7fffffff, SEEK_SET);
    else if (op <= 0xffff) return 0;
    else switch (op)
    {
case READ_TELL:
        op = ftell(stream_file(f));
        return op;
case READ_END:
        return fseek(stream_file(f), 0L, SEEK_END);
default:
        return 0;
    }
}

int32_t read_action_terminal(int32_t op, Lisp_Object f)
{
    CSL_IGNORE(f);
    if (op < -1) return 1;
    else if (op <= 0xffff) return (terminal_pushed = op);
    else switch (op)
    {
case READ_CLOSE:
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

int32_t read_action_synonym(int32_t c, Lisp_Object f)
{
    int32_t r;
    Lisp_Object f1;
    f1 = qvalue(stream_read_data(f));
    if (!is_stream(f1)) return aerror1("bad synonym stream", f1);
    r = other_read_action(c, f1);
    if (c == READ_CLOSE)
    {   set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, NULL);
    }
    return r;
}

int32_t read_action_concatenated(int32_t c, Lisp_Object f)
{
    int32_t r = 0, r1;
    Lisp_Object l, f1;
#ifdef COMMON
    Lisp_Object nil = C_nil;
#endif
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

int32_t read_action_list(int32_t op, Lisp_Object f)
{
    if (op < -1) return 1;
    else if (op <= 0xffff) return (stream_pushed_char(f) = op);
    else switch (op)
    {
case READ_CLOSE:
        set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, NULL);
        stream_read_data(f) = C_nil;
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

int32_t read_action_vector(int32_t op, Lisp_Object f)
{
    if (op < -1) return 1;
    else if (op <= 0xffff) return (stream_pushed_char(f) = op);
    else switch (op)
    {
case READ_CLOSE:
        set_stream_read_fn(f, char_from_illegal);
        set_stream_read_other(f, read_action_illegal);
        set_stream_file(f, NULL);
        stream_read_data(f) = C_nil;
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

Lisp_Object MS_CDECL Lread(Lisp_Object nil, int nargs, ...)
/*
 * The full version of read_s() has to support extra optional args
 * that deal with error and eof returns... and a recursive-p arg!
 */
{
    Lisp_Object w, stream = qvalue(standard_input);
    int cursave = curchar;
    argcheck(nargs, 0, "read");
#ifdef COMMON
    push(reader_workspace);
    reader_workspace = nil;
#endif
    read_failure = NO;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    curchar = NOT_CHAR;
    most_recent_read_point = other_read_action(READ_TELL, stream);
    push(stream);
    w = read_s(stream);
    pop(stream);
    if (curchar != NOT_CHAR) other_read_action(curchar, stream);
    curchar = cursave;
    current_file = stream_type(stream);
#ifdef COMMON
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        pop(reader_workspace);
        flip_exception();
        return nil;
    }
    pop(reader_workspace);
#else
    errexit();
#endif
    if (read_failure) return aerror("read");
    
    return onevalue(w);
}

static Lisp_Object MS_CDECL Lwhere_was_that(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object w;
    argcheck(nargs, 0, "where-was-that");
#ifdef COMMON
    w = list3(current_file, fixnum_of_int(most_recent_read_point),
              packname_(CP));
#else
    w = list2(current_file, fixnum_of_int(most_recent_read_point));
#endif
    errexit();
    return onevalue(w);
}

#ifdef COMMON

Lisp_Object Lread_1(Lisp_Object nil, Lisp_Object stream)
{
    int cursave = curchar;
    Lisp_Object w;
    Lisp_Object save = Lrds(nil, stream);
    errexit();
    push2(reader_workspace, save);
    reader_workspace = nil;
    read_failure = NO;
    stream = qvalue(standard_input);
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    curchar = NOT_CHAR;
    w = read_s(stream);
    if (curchar != NOT_CHAR) other_read_action(curchar, stream);
    curchar = cursave;
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        pop2(save, reader_workspace);
        Lrds(nil, save);
        errexit();
        flip_exception();
        return nil;
    }
    pop2(save, reader_workspace);
    push(w);
    Lrds(nil, save);
    pop(w);
    errexit();
    if (read_failure) return aerror("read");
    return onevalue(w);
}

#endif

/*
 * compress is not a Common Lisp function, but it is another on those
 * things that I want within my implementation for internal purposes as
 * well as for real use.
 */

int char_from_list(Lisp_Object f)
{
#ifdef COMMON
    Lisp_Object nil = C_nil;
#endif
    Lisp_Object ch = stream_pushed_char(f);
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
/*
 * here I tend towards generosity - a symbol stands for the first character
 * of its name, and character objects and numbers (representing internal
 * codes) are also permitted.  Incomplete gensyms are OK here - I just
 * use the first character of the base of the name.
 */
        if (is_symbol(ch)) ch = first_char(ch);
        else if (is_char(ch)) ch = (char)code_of_char(ch);
        else if (is_fixnum(ch)) ch = (char)int_of_fixnum(ch);
        else ch = EOF;    /* Bad item in the list */
    }
    else stream_pushed_char(f) = NOT_CHAR;
    return ch;
}

int char_from_vector(Lisp_Object f)
{
#ifdef COMMON
    Lisp_Object nil = C_nil;
#endif
    Lisp_Object ch = stream_pushed_char(f);
    if (ch == NOT_CHAR)
    {   char *v = (char *)stream_file(f);
        if (v == NULL) ch = EOF;
        else
        {   if (++kilo >= 1024)
            {   kilo = 0;
                io_now++;
            }
            ch = *v++;
            if (ch == 0) ch = EOF;
            else set_stream_file(f, (FILE *)v);
        }
    }
    else stream_pushed_char(f) = NOT_CHAR;
    return ch;
}

Lisp_Object read_from_vector(char *v)
{
    int savecur = curchar;
    Lisp_Object nil = C_nil, r;
    stream_read_data(lisp_work_stream) = nil;
    set_stream_read_fn(lisp_work_stream, char_from_vector);
    set_stream_read_other(lisp_work_stream, read_action_vector);
    stream_pushed_char(lisp_work_stream) = NOT_CHAR;
    set_stream_file(lisp_work_stream, (FILE *)v);
    read_failure = NO;
    curchar = NOT_CHAR;
    r = read_s(lisp_work_stream);
    errexit();
    curchar = savecur;
    if (read_failure) return aerror("read-from-vector");
    return onevalue(r);
}

Lisp_Object Lcompress(Lisp_Object env, Lisp_Object stream)
{
    int savecur = curchar;
    Lisp_Object nil = C_nil;
    stream_read_data(lisp_work_stream) = stream;
    set_stream_read_fn(lisp_work_stream, char_from_list);
    set_stream_read_other(lisp_work_stream, read_action_list);
    stream_pushed_char(lisp_work_stream) = NOT_CHAR;
    read_failure = NO;
    curchar = NOT_CHAR;
    env = read_s(lisp_work_stream);
    errexit();
    stream_read_data(lisp_work_stream) = C_nil;
    curchar = savecur;
    if (read_failure) return aerror("compress");
    return onevalue(env);
}

Lisp_Object Llist_to_string(Lisp_Object nil, Lisp_Object stream)
{
    int n = CELL, k;
    Lisp_Object str;
    char *s;
    stream_read_data(lisp_work_stream) = stream;
    set_stream_read_fn(lisp_work_stream, char_from_list);
    set_stream_read_other(lisp_work_stream, read_action_list);
    stream_pushed_char(lisp_work_stream) = NOT_CHAR;
    while (consp(stream)) n++, stream = qcdr(stream);
    str = getvector(TAG_VECTOR, TYPE_STRING, n);
    errexit();
    s = (char *)str + CELL - TAG_VECTOR;
    for (k=CELL; k<n; k++) *s++ = (char)char_from_list(lisp_work_stream);
    for (;(k&7) != 0; k++) *s++ = 0; /* zero-pad final doubleword */    
    return onevalue(str);
}

Lisp_Object Llist_to_symbol(Lisp_Object nil, Lisp_Object stream)
{
    stream = Llist_to_string(nil, stream);
    errexit();
#ifdef COMMON
    stream = Lintern_2(nil, stream, CP);
    errexit();
    return onevalue(stream);  /* NB intern would have returned 2 values */
#else
    return Lintern(nil, stream);
#endif
}

void read_eval_print(int noisy)
{
    Lisp_Object nil = C_nil, *save = stack;
#ifndef __cplusplus
    jmp_buf this_level, *saved_buffer = errorset_buffer;
#endif
    push2(codevec, litvec);
    for (;;)        /* Loop for each s-expression found */
    {   Lisp_Object u;
#ifdef COMMON
        int32_t nvals, i;
#endif
        miscflags |= (HEADLINE_FLAG | MESSAGES_FLAG);
        errorset_msg = NULL;
#ifdef __cplusplus
        try
#else
        if (!setjmp(this_level))
#endif
        {
#ifndef __cplusplus
            errorset_buffer = &this_level;
#endif
            u = Lread(nil, 0);
        }
#ifdef __cplusplus
        catch (char *)
#else
        else
#endif
        {   nil = u = C_nil;
            if (errorset_msg != NULL)
            {   term_printf("\n%s detected\n", errorset_msg);
                errorset_msg = NULL;
            }
            unwind_stack(save, NO);
            stack = save;
#ifndef UNDER_CE
            signal(SIGFPE, low_level_signal_handler);
            if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#ifdef SIGBUS
            if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
            if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
#endif
            err_printf("\n... read failed\n");
            errors_now++;
            if (errors_limit >= 0 && errors_now > errors_limit)
                resource_exceeded();
            else continue;
        }
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
/*
 * Maybe (stop) or (preserve) was called from a read-macro?  Otherwise
 * errors reading are ignored and the system tries to read the next
 * expression for evaluation.  Note that this behaviour means that
 * perhaps unreasonably or unexpectedly, THROW will not be propagated
 * back past a read_eval_print loop.
 */
            if (exit_reason == UNWIND_RESTART ||
                exit_reason == UNWIND_RESOURCE)
            {
#ifndef __cplusplus
                errorset_buffer = saved_buffer;
#endif
                pop2(litvec, codevec);
                flip_exception();
                return;
            }
            err_printf("\n... read failed\n");
            continue;
        }
/*
 * This will stop at end of file. That could EITHER be a real proper
 * end of file, or the user having #\eof in the input file.  These are NOT
 * equivalent, in that #\eof is read once and then further stuff from the
 * stream can be read, while a real EOF (eg typing ^D at the terminal in
 * some cases) ends the stream once and for all.
 */
        if (u == CHAR_EOF)
        {
#ifndef __cplusplus
            errorset_buffer = saved_buffer;
#endif
            pop2(litvec, codevec);
            return;
        }

        if (qvalue(standard_input) == lisp_terminal_io &&
            spool_file != NULL) putc('\n', spool_file);

        miscflags |= (HEADLINE_FLAG | MESSAGES_FLAG);
        errorset_msg = NULL;
#ifdef __cplusplus
        try
#else
        if (!setjmp(this_level))
#endif
        {
            u = eval(u, nil);
            nil = C_nil;
            if (exception_pending())
            {   flip_exception(); /* safe again! */
                if (exit_reason == UNWIND_RESTART ||
                    exit_reason == UNWIND_RESOURCE)
                {
#ifndef __cplusplus
                    errorset_buffer = saved_buffer;
#endif
                    pop2(litvec, codevec);
                    flip_exception();
                    return;
                }
                err_printf("\n... continuing after error\n");
                if (spool_file != NULL) fflush(spool_file);
                continue;
            }
            if (noisy)
            {
#ifndef COMMON
                print(u);   /* Always exactly one value */
                stdout_printf("\n");
                nil = C_nil;
                if (exception_pending()) flip_exception();
#else
                nvals = exit_count;
/*
 * These days I have to push mv_2 because print can call find-symbol to
 * decide if it needs to display a package qualifier, and in that case
 * it alters mv_2 on the way...  But at present it should never change
 * any higher multiple value. I guess if it were interrupted then a break
 * loop (if one existed) could corrupt almost anything, but I will
 * ignore that worry.
 */
                if (nvals > 0)
                {   push(mv_2);
                    print(u);
                    pop(u);
                }
                nil = C_nil;
                if (exception_pending()) flip_exception();
                mv_2 = u;
                miscflags |= (HEADLINE_FLAG | MESSAGES_FLAG);
                for (i=2; i<=nvals; i++)
                {   print((&mv_2)[i-2]);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        break;
                    }
                }
                stdout_printf("\n");
#endif
            }
        }
#ifdef __cplusplus
        catch (char *)
#else
        else
#endif
        {   if (errorset_msg != NULL)
            {   term_printf("\n%s detected\n", errorset_msg);
                errorset_msg = NULL;
            }
            unwind_stack(save, NO);
            stack = save;
#ifndef UNDER_CE
            signal(SIGFPE, low_level_signal_handler);
            if (segvtrap) signal(SIGSEGV, low_level_signal_handler);
#ifdef SIGBUS
            if (segvtrap) signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
            if (segvtrap) signal(SIGILL, low_level_signal_handler);
#endif
#endif
            err_printf("\n... continuing after error\n");
            if (spool_file != NULL) fflush(spool_file);
            errors_now++;
            if (errors_limit >= 0 && errors_now > errors_limit)
            {   resource_exceeded();
                return;
            }
            else continue;
        }
    }
}

/*
 * RDF is wanted as it is in Standard Lisp. In Common Lisp the corresponding
 * function is LOAD. LOAD takes keyword arguments, which are decoded
 * elsewhere, leaving the code here which takes a variable number of
 * args, but all with definite simple interpretations.
 */

Lisp_Object Lrdf4(Lisp_Object nil, Lisp_Object file, Lisp_Object noisyp,
                  Lisp_Object verbosep, Lisp_Object nofilep)
{
    Lisp_Object r = nil;
    int noisy = (noisyp != nil),
#ifdef COMMON
        nofile = (nofilep != nil),
#endif
        verbose = (verbosep != nil);
#ifndef COMMON
    CSL_IGNORE(nofilep);
#endif
/*
 * (rdf nil)/(load nil) obeys Lisp commands from the current input
 */
    push3(nil, nil, file);
/*
 * I have a somewhat comical chunk of code here. If the file-name passed
 * across ends in a suffix that is one of ".o", ".fsl" or ".fasl" then
 * instead of reading a textual source file the way one might have
 * expected I will subvert things and perform LOAD-MODULE instead.
 */
    if (file != nil)
    {   Header h;
        char *filestring;
        char tail[8];
        int32_t i, len;
#ifdef COMMON
        if (complex_stringp(file))
        {   file = simplify_string(file);
            errexitn(3);
        }
#endif
        if (symbolp(file))
        {   file = get_pname(file);
            errexitn(3);
            h = vechdr(file);
        }
        else if (!is_vector(file) ||
             type_of_header(h = vechdr(file)) != TYPE_STRING)
            return aerror1("load", file);
        len = length_of_header(h) - CELL;
        filestring = (char *)file + CELL-TAG_VECTOR;
        for (i=0; i<6; i++)
        {   if (len == 0)
            {   tail[i] = 0;
                break;
            }
            else tail[i] = (char)tolower(filestring[--len]);
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
                loop_print_trace(file); trace_printf("\n");
            }
            Lload_module(nil, stack[0]);
            errexitn(3);
            if (verbose)
            {
#ifdef COMMON
                trace_printf("\n;; Loaded module ");
#else
                trace_printf("\nRead module ");
#endif
                loop_print_trace(stack[0]); trace_printf("\n");
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
        errexitn(3);
#ifdef COMMON
/*
 * The test here is necessary since in Common Lisp mode an attempt to OPEN a
 * file that can not be accessed returns NIL rather than raising an
 * exception.
 */
        if (r == nil)
        {   pop(file);
            popv(2);
            if (nofile) return error(1, err_open_failed, file);
            else return onevalue(nil);
        }
#endif
        stack[-2] = r = Lrds(nil, r);
        errexitn(3);
        if (verbose)
        {   file = stack[0];
#ifdef COMMON
            trace_printf("\n;; Loading "); loop_print_trace(file); trace_printf("\n");
#else
            trace_printf("\nReading "); loop_print_trace(file); trace_printf("\n");
#endif
        }
        errexitn(3);
    }
    read_eval_print(noisy);
    nil = C_nil;
    if (exception_pending())
    {   flip_exception();
        if (exit_reason == UNWIND_ERROR ||
            exit_reason == UNWIND_RESOURCE)
        {
#ifdef COMMON
            trace_printf("\n;; Loaded ");
#else
            trace_printf("\nFinished reading ");
#endif
            loop_print_trace(stack[0]);
            trace_printf(" (bad)\n");
        }
        if (stack[0] != nil)
        {   Lclose(nil, stack[-1]);
            nil = C_nil;
            if (exception_pending()) flip_exception();
            Lrds(nil, stack[-2]);
            errexitn(3);
        }
        flip_exception();
        popv(3);
        return nil;
    }
    if (verbose) 
    {
#ifdef COMMON
        trace_printf("\n;; Loaded ");
#else
        trace_printf("\nRead ");
#endif
    }
    loop_print_trace(stack[0]);
    trace_printf("\n");
    if (stack[0] != nil)
    {
        Lclose(nil, stack[-1]);
        nil = C_nil;
        if (exception_pending()) flip_exception();
        Lrds(nil, stack[-2]);
        errexitn(3);
    }
    popv(3);
#ifdef COMMON
    return onevalue(lisp_true);
#else
    return onevalue(nil);
#endif
}

Lisp_Object Lrdf1(Lisp_Object nil, Lisp_Object file)
{
    return Lrdf4(nil, file, lisp_true, lisp_true, lisp_true);
}

Lisp_Object Lrdf2(Lisp_Object nil, Lisp_Object file, Lisp_Object noisy)
{
    return Lrdf4(nil, file, noisy, lisp_true, lisp_true);
}

Lisp_Object MS_CDECL Lrdfn(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object file, noisy, verbose, nofile = lisp_true;
    if (nargs < 3 || nargs > 4) return aerror("load");
    va_start(a, nargs);
    file = va_arg(a, Lisp_Object);
    noisy = va_arg(a, Lisp_Object);
    verbose = va_arg(a, Lisp_Object);
    if (nargs > 3) nofile = va_arg(a, Lisp_Object);
    va_end(a);
    return Lrdf4(nil, file, noisy, verbose, nofile);
}

#ifdef COMMON
#define spool_name "dribble"
#else
#define spool_name "spool"
#endif

Lisp_Object Lspool(Lisp_Object nil, Lisp_Object file)
{
    char filename[LONGEST_LEGAL_FILENAME];
    Header h;
    int32_t len;
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "spool"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
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
    if (!is_vector(file) ||
         type_of_header(h = vechdr(file)) != TYPE_STRING)
        return aerror1(spool_name, file);
    len = length_of_header(h) - CELL;
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

static Lisp_Object MS_CDECL Lspool0(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, spool_name);
    return Lspool(nil, nil);
}

#ifdef COMMON

#define STARTING_SIZE_X 32
#define STARTING_SIZE_I 32

Lisp_Object make_package(Lisp_Object name)
/*
 * ... assuming that there is not already one with this name. Packages
 * can grow as extra symbols are inserted into them, so I can reasonably
 * start off with a very small package.
 */
{
    Lisp_Object nil = C_nil;
    Lisp_Object p = getvector_init(sizeof(Package), nil), w;
    errexit();
    packhdr_(p) = TYPE_STRUCTURE + (packhdr_(p) & ~header_mask);
    packid_(p) = package_symbol;
    packname_(p) = name;
    packext_(p) = getvector_init(STARTING_SIZE_X+CELL, fixnum_of_int(0));
    errexit();
    packint_(p) = getvector_init(STARTING_SIZE_I+CELL, fixnum_of_int(0));
    errexit();
    packflags_(p) = fixnum_of_int(++package_bits);
    packvext_(p) = fixnum_of_int(1);
    packvint_(p) = fixnum_of_int(1);
    packnext_(p) = fixnum_of_int(0);
    packnint_(p) = fixnum_of_int(0);
    w = cons(p, all_packages);
    errexit();
    all_packages = w;
    return onevalue(p);
}

static Lisp_Object want_a_string(Lisp_Object name)
{
#ifdef COMMON
    Lisp_Object nil = C_nil;
    if (complex_stringp(name)) return simplify_string(name);
#else
    nil_as_base
#endif
    if (symbolp(name)) return get_pname(name);
    else if (is_vector(name) &&
         type_of_header(vechdr(name)) == TYPE_STRING) return name;
    else return aerror1("name or string needed", name);
}

static Lisp_Object Lfind_package(Lisp_Object nil, Lisp_Object name)
/*
 * This should be given a string as an argument. If it is given a
 * symbol it takes its pname as the string to be used.  It scans the list
 * of all packages and returns the first that it finds where the name
 * or a nickname matches the string passed in.
 */
{
    Lisp_Object w;
    Header h;
    int32_t len;
    CSL_IGNORE(nil);
    if (is_vector(name))
    {   h = vechdr(name);
        if (type_of_header(h) == TYPE_STRUCTURE &&
            packid_(name) == package_symbol) return onevalue(name);
    }
    name = want_a_string(name);
    errexit();
    h = vechdr(name);
    len = length_of_header(h) - CELL;
    for (w = all_packages; w!=nil; w=qcdr(w))
    {   Lisp_Object nn, n = packname_(qcar(w));
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

Lisp_Object find_package(char *name, int len)
/*
 * This is like Lfind_package but takes a C string as its arg. Note that
 * this can not cause garbage collection or return an error, so is safe to
 * call from the middle of other things...
 */
{
    Lisp_Object w, nil = C_nil;
    for (w = all_packages; w!=nil; w=qcdr(w))
    {   Lisp_Object nn, n = packname_(qcar(w));
        if (is_vector(n) &&
            length_of_header(vechdr(n))==(uint32_t)(len+CELL) &&
            memcmp(name, (char *)n + (CELL-TAG_VECTOR), (size_t)len) == 0)
            return qcar(w);
        for (nn = packnick_(qcar(w)); nn!=nil; nn=qcdr(nn))
        {   n = qcar(nn);
            if (!is_vector(n) ||
                length_of_header(vechdr(n)) != (uint32_t)(len+CELL))
                continue;
            if (memcmp(name,
                       (char *)n + (CELL-TAG_VECTOR), (size_t)len) == 0)
                return qcar(w);
        }
    }
    return nil;
}

static Lisp_Object Luse_package(Lisp_Object nil, Lisp_Object uses,
                                                 Lisp_Object pkg)
{
    CSL_IGNORE(nil);
    push(uses);
    pkg = Lfind_package(nil, pkg);
    pop(uses);
    errexit();
    if (pkg == nil) return onevalue(nil);
    if (consp(uses))
    {   while (consp(uses))
        {   push2(uses, pkg);
            Luse_package(nil, qcar(uses), pkg);
            errexitn(2);
            pop2(pkg, uses);
            uses = qcdr(uses);
        }
    }
    else
    {   Lisp_Object w, w1;
        push(pkg);
        uses = Lfind_package(nil, uses);
        pop(pkg);
        errexit();
        if (uses == nil || uses == pkg) return onevalue(nil);
        push2(pkg, uses);
/*
 * Around here I am supposed to do a large-scale check to ensure that there
 * are no unexpected name conflicts between the packages that are being
 * worked linked.
 */
        w = cons(uses, packuses_(pkg));
        errexitn(2);
        uses = stack[0];
        pkg = stack[-1];
        push(w);
        w1 = cons(pkg, packused_(uses));
        errexitn(3);
        pop3(w, uses, pkg);
        packuses_(pkg) = w;
        packused_(uses) = w1;
    }
    return onevalue(lisp_true);
}

static Lisp_Object MS_CDECL Lmake_package(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object name, nicknames = nil, uses = nil, w = nil, k;
    CSLbool has_use = NO;
    va_list a;
    int i;
    if (nargs == 0) return aerror("make-package");
/*
 * First I scan the arguments - there may be a lot of them - looking for
 * any relevant keyword parameters
 */
    va_start(a, nargs);
    push_args(a, nargs);
    name = stack[1-nargs];
    if ((nargs & 1) == 0)
    {   popv(1);
        nargs--;
    }
    for (i=1; i<nargs; i+=2)
    {   pop2(k, w);
        if (w == nicknames_symbol) nicknames = k;
        else if (w == use_symbol) has_use = YES, uses = k;
    }
    popv(1);
/*
 * I provide a default value for the ":use" argument
 */
    if (!has_use)
    {   push2(name, nicknames);
        uses = make_string("LISP");
        errexitn(2);
        uses = ncons(uses);
        errexitn(2);
        pop2(nicknames, name);
    }
    push2(uses, nicknames);
/*
 * Now I need to ensure that the name I had for the package is
 * a string...
 */
    name = want_a_string(name);
    errexitn(2);
    push(name);
    w = Lfind_package(nil, name);
    pop(name);
    errexitn(2);
/*
 * It is SUPPOSED to be a continuable error if the package already exists.
 * For the present I will just display a message and keep going.
 */
    if (w != nil)
    {   popv(2);
        err_printf("\n+++++ package already exists: ");
        prin_to_error(name);
        err_printf("\n");
        return onevalue(w);
    }
/*
 * The package does not exist yet - so I will make one...
 */
    name = make_package(name);
    errexitn(2);
/*
 * ensure that NICKNAMES is a list of strings...
 */
    uses = nil;
    while (consp(stack[0]))
    {   w = stack[0];
        push(uses);
        w = want_a_string(qcar(w));
        errexitn(3);
        pop(uses);
        uses = cons(w, uses);
        errexitn(2);
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
    errexitn(1);
    pop(name);
    return onevalue(name);
}

static Lisp_Object Lmake_package_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lmake_package(nil, 2, a, b);
}

static Lisp_Object Lmake_package_1(Lisp_Object nil, Lisp_Object a)
{
    return Lmake_package(nil, 1, a);
}

static Lisp_Object MS_CDECL Llist_all_packages(Lisp_Object nil, int nargs, ...)
{
    CSL_IGNORE(nargs);
    CSL_IGNORE(nil);
    return onevalue(all_packages);
}

#endif

Lisp_Object MS_CDECL Ltyi(Lisp_Object nil, int nargs, ...)
{
    int ch;
    argcheck(nargs, 0, "tyi");
    if (curchar == NOT_CHAR)
    {   Lisp_Object stream = qvalue(standard_input);
        if (!is_stream(stream)) stream = qvalue(terminal_io);
        if (!is_stream(stream)) stream = lisp_terminal_io;
        ch = getc_stream(stream);
        errexit();
    }
    else
    {   ch = curchar;
        curchar = NOT_CHAR;
    }
    if (ch == EOF || ch == CTRL_D) return onevalue(CHAR_EOF);
#ifdef Kanji
    return onevalue(pack_char(0, 0, ch & 0xffff));
#else
    return onevalue(pack_char(0, 0, ch & 0xff));
#endif
}

Lisp_Object Lreadbyte(Lisp_Object nil, Lisp_Object stream)
{
    int ch;
    Lisp_Object save = qvalue(echo_symbol);
    if (!is_stream(stream)) aerror0("readb requires an appropriate stream");
    qvalue(echo_symbol) = nil;
    ch = getc_stream(stream);
    qvalue(echo_symbol) = save;
    errexit();
/*
 * At one stage this code treated ^D as an end-of file marker - that is
 * most nasty for binary files! The code should now be more transparent.
 */
    if (ch == EOF) return onevalue(CHAR_EOF);
    else return fixnum_of_int(ch & 0xff);
}

Lisp_Object Lreadch1(Lisp_Object nil, Lisp_Object stream)
{
    Lisp_Object w;
    int ch;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    ch = getc_stream(stream);
    errexit();
    if (ch == EOF || ch == CTRL_D) w = CHAR_EOF;
    else
    {
        if (qvalue(lower_symbol) != nil) ch = TOlower(ch);
        else if (qvalue(raise_symbol) != nil) ch = TOupper(ch);
#ifdef Kanji
        if (qvalue(hankaku_symbol) != nil)
            is (iszenkaku(curchar)) curchar = tohankaku(curchar);
        if (iswchar(ch))
        {   boffo_char(0) = ch >> 8;
            boffo_char(1) = ch;
            w = iintern(boffo, 2, lisp_package, 1);
            errexit();
        }
        else
        {   w = elt(charvec, ch & 0xff);
            if (w == nil)
            {   boffo_char(0) = ch;
/* NB I always want to intern in the LISP package here */
                w = iintern(boffo, 1, lisp_package, 0);
                errexit();
                elt(charvec, ch & 0xff) = w;
            }
        }
#else
        w = elt(charvec, ch & 0xff);
        if (w == nil)
        {   boffo_char(0) = (char)ch;
/* NB I always want to intern in the LISP package here */
            w = iintern(boffo, 1, lisp_package, 0);
            errexit();
            elt(charvec, ch & 0xff) = w;
        }
#endif
    }
    return onevalue(w);
}

Lisp_Object MS_CDECL Lreadch(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "readch");
    return Lreadch1(nil, qvalue(standard_input));
}

Lisp_Object Lpeekch2(Lisp_Object nil, Lisp_Object type, Lisp_Object stream)
{
    Lisp_Object w;
    int ch;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (type != nil)
    {   do
        {   ch = getc_stream(stream);
            errexit();
        } while (ISspace(ch));
    }
    else
    {   ch = getc_stream(stream);
        errexit();
    }
    other_read_action(ch, stream);
    errexit();
    if (ch == EOF || ch == CTRL_D) w = CHAR_EOF;
    else
    {   if (qvalue(lower_symbol) != nil) ch = TOlower(ch);
        else if (qvalue(raise_symbol) != nil) ch = TOupper(ch);
#ifdef Kanji
        if (qvalue(hankaku_symbol) != nil)
            is (iszenkaku(curchar)) curchar = tohankaku(curchar);
        if (iswchar(curchar))
        {   boffo_char(0) = curchar >> 8;
            boffo_char(1) = curchar;
            w = iintern(boffo, 2, lisp_package, 0);
            errexit();
        }
        else
        {   w = elt(charvec, ch & 0xff);
            if (w == nil)
            {   boffo_char(0) = ch;
/* NB I always want to intern in the LISP package here */
                w = iintern(boffo, 1, lisp_package, 0);
                errexit();
                elt(charvec, ch & 0xff) = w;
            }
        }
#else
        w = elt(charvec, ch & 0xff);
        if (w == nil)
        {   boffo_char(0) = (char)ch;
/* NB I always want to intern in the LISP package here */
            w = iintern(boffo, 1, lisp_package, 0);
            errexit();
            elt(charvec, ch & 0xff) = w;
        }
#endif
    }
    return onevalue(w);
}

Lisp_Object Lpeekch1(Lisp_Object nil, Lisp_Object type)
{
    return Lpeekch2(nil, type, qvalue(standard_input));
}

Lisp_Object MS_CDECL Lpeekch(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "peekch");
    return Lpeekch2(nil, nil, qvalue(standard_input));
}

Lisp_Object Lunreadch2(Lisp_Object nil, Lisp_Object a, Lisp_Object stream)
{
    int ch;
    CSL_IGNORE(nil);
     if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    if (a == CHAR_EOF) ch = EOF;
    else
    {   if (is_symbol(a)) a = pack_char(0, 0, first_char(a));
        ch = (char)code_of_char(a);
    }
    other_read_action(ch, stream);
    return onevalue(a);
}

Lisp_Object Lunreadch(Lisp_Object nil, Lisp_Object a)
{
    return Lunreadch2(nil, a, qvalue(standard_input));
}

Lisp_Object Lreadline1(Lisp_Object nil, Lisp_Object stream)
{
    Lisp_Object w;
    int ch, n = 0;
    char *s;
    if (!is_stream(stream)) stream = qvalue(terminal_io);
    if (!is_stream(stream)) stream = lisp_terminal_io;
    boffop = 0;
    while ((ch = getc_stream(stream)) != EOF && ch != '\n')
    {   errexit();
        if (ch != '\r') packbyte(ch);
        n++;
    }
    errexit();
    if (ch == EOF && n == 0) w = CHAR_EOF;
    else
    {   w = getvector(TAG_VECTOR, TYPE_STRING, CELL+n);
        errexit();
        s = (char *)w + CELL - TAG_VECTOR;
        memcpy(s, &boffo_char(0), n);
        while ((n&7) != 0) s[n++] = 0;
    }
#ifdef COMMON
    mv_2 = Lispify_predicate(ch == EOF);
#endif
    return nvalues(w, 2);
}

Lisp_Object MS_CDECL Lreadline(Lisp_Object nil, int nargs, ...)
{
    argcheck(nargs, 0, "readline");
    return Lreadline1(nil, qvalue(standard_input));
}

setup_type const read_setup[] =
{
    {"batchp",                  wrong_no_na, wrong_no_nb, Lbatchp},
    {"rseek",                   Lrseek, Lrseek_2, wrong_no_1},
#ifdef COMMON
    {"rseekend",                Lrseekend, too_many_1, wrong_no_1},
#endif
    {"rtell",                   Lrtell_1, wrong_no_nb, Lrtell},
    {"gensym1",                 Lgensym1, too_many_1, wrong_no_1},
    {"gensym2",                 Lgensym2, too_many_1, wrong_no_1},
    {"gensymp",                 Lgensymp, too_many_1, wrong_no_1},
    {"getenv",                  Lgetenv, too_many_1, wrong_no_1},
    {"orderp",                  too_few_2, Lorderp, wrong_no_2},
    {"rdf",                     Lrdf1, Lrdf2, Lrdfn},
    {"rds",                     Lrds, too_many_1, wrong_no_1},
    {"peekch",                  Lpeekch1, Lpeekch2, Lpeekch},
    {"readch",                  Lreadch1, wrong_no_nb, Lreadch},
    {"readb",                   Lreadbyte, too_many_1, wrong_no_1},
    {"unreadch",                Lunreadch, Lunreadch2, wrong_no_1},
    {"readline",                Lreadline1, wrong_no_nb, Lreadline},
    {"setpchar",                Lsetpchar, too_many_1, wrong_no_1},
    {"spool",                   Lspool, too_many_1, Lspool0},
    {"system",                  Lsystem, too_many_1, wrong_no_1},
    {"silent-system",           Lsilent_system, too_many_1, wrong_no_1},
    {"~tyi",                    wrong_no_na, wrong_no_nb, Ltyi},
    {"list-to-string",          Llist_to_string, too_many_1, wrong_no_1},
    {"list-to-symbol",          Llist_to_symbol, too_many_1, wrong_no_1},
    {"where-was-that",          wrong_no_na, wrong_no_nb, Lwhere_was_that},
#ifdef COMMON
    {"compress1",               Lcompress, too_many_1, wrong_no_1},
    {"dribble",                 Lspool, too_many_1, Lspool0},
    {"read",                    Lread_1, wrong_no_nb, Lread},
    {"intern",                  Lintern, Lintern_2, wrong_no_1},
    {"gensym",                  Lgensym1, wrong_no_nb, Lgensym},
    {"extern",                  Lextern_1, Lextern, wrong_no_1},
    {"import*",                 Limport_1, Limport, wrong_no_1},
    {"find-symbol",             Lfind_symbol_1, Lfind_symbol, wrong_no_1},
    {"keywordp",                Lkeywordp, too_many_1, wrong_no_1},
    {"find-package",            Lfind_package, too_many_1, wrong_no_1},
    {"make-package",            Lmake_package_1, Lmake_package_2, Lmake_package},
    {"use-package*",            too_few_2, Luse_package, wrong_no_2},
    {"list-all-packages",       wrong_no_na, wrong_no_nb, Llist_all_packages},
    {"make-symbol",             Lmake_symbol, too_many_1, wrong_no_1},
    {"unintern",                Lunintern, Lunintern_2, wrong_no_1},
#else
    {"compress",                Lcompress, too_many_1, wrong_no_1},
    {"read",                    wrong_no_na, wrong_no_nb, Lread},
    {"intern",                  Lintern, too_many_1, wrong_no_1},
    {"gensym",                  Lgensym1, wrong_no_nb, Lgensym},
    {"ordp",                    too_few_2, Lorderp, wrong_no_2},
    {"remob",                   Lunintern, too_many_1, wrong_no_1},
#endif
    {NULL,                      0, 0, 0}
};

/* end of read.c */
