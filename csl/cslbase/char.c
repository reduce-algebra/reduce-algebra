/*  char.c                           Copyright (C) 1989-2008 Codemist Ltd */

/*
 * Character handling.
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




/* Signature: 419913fa 24-May-2008 */

#include "headers.h"


#ifdef Kanji
#define ISalpha(a)     iswalpha(a)
#define ISdigit(a)     iswdigit(a)
#define ISalnum(a)     iswalnum(a)
#define ISspace(a)     iswspace(a)
#define ISgraph(a)     iswgraph(a)
#define ISupper(a)     iswupper(a)
#define ISlower(a)     iswlower(a)
#define TOupper(a)     towupper(a)
#define TOlower(a)     towlower(a)

int first_char(Lisp_Object ch)
{   /* ch is a symbol. Get the first character of its name. */
    int n;
    ch = qpname(ch);
    n = celt(ch, 0);
    if (is2byte(n) && length_of_header(vechdr(ch)) != CELL)
        n = (n << 8) + ucelt(ch, 1);
    return n;
}
                            
#else /* Kanji */
#define ISalpha(a)     isalpha(a)
#define ISdigit(a)     isdigit(a)
#define ISalnum(a)     isalnum(a)
#define ISspace(a)     isspace(a)
#define ISgraph(a)     isgraph(a)
#define ISupper(a)     isupper(a)
#define ISlower(a)     islower(a)
#define TOupper(a)     toupper(a)
#define TOlower(a)     tolower(a)

#define first_char(a)  celt(qpname(a), 0)

#endif /* Kanji */

/*
 * For many character functions I will permit the argument to be either
 * a character object (Common Lisp syntax #\x) or a symbol. If it is a
 * symbol the "character" tested will be the first one in the print-name,
 * and (of course) very often I will just use the symbols 'a, 'b, 'c etc
 * to stand for the characters #\a, #\b, #\c....
 * If the symbol has a print-name of length other than 1 I will not
 * count it as a valid character.
 * Common Lisp seens to say that character functions ought to be handed
 * real character objects - so extending this to permit symbols as well
 * is probably safe. If it were not I could just redefine this macro as
 * a null expansion in Common Lisp mode.
 * NB gensyms are OK here since I only need the 1st char of the base-name
 */
#ifdef Kanji
#define characterify(c)                                    \
    if (is_symbol(c) &&                                    \
        lenth_of_header(vechdr(qpname(c))) == CELL+1)      \
        c = pack_char(0,0,                                 \
            is2byte(celt(qpname(c), 0)) ?                  \
            (ucelt(qpname(c),0)<<8) + ucelt(qpname(c),1) : \
            celt(qpname(c), 0))
#else
#define characterify(c) \
    if (is_symbol(c) &&                                    \
        length_of_header(vechdr(qpname(c))) == CELL+1)     \
        c = pack_char(0,0, ucelt(qpname(c), 0))
#endif

#ifndef COMMON

static Lisp_Object char_to_id(int ch)
{
    Lisp_Object nil = C_nil;
    Lisp_Object w;
#ifdef Kanji
    if (iswchar(c))
    {   celt(boffo, 0) = c>>8;
        celt(boffo, 1) = c;
        w = iintern(boffo, 2, lisp_package, 0);
        errexit();
        return onevalue(w);
    }
#endif
    w = elt(charvec, ch & 0xff);
    if (w == nil)
    {   celt(boffo, 0) = (char)ch;
        w = iintern(boffo, 1, lisp_package, 0);
        errexit();
        elt(charvec, ch & 0xff) = w;
    }
    return onevalue(w);
}

#endif

/*
 * Characters have 8 bits of BITS, then 8 of FONT, then 8 of CODE.
 * The BITS and FONT information is only used in COMMON mode.
 * Even though Common Lisp refers to the components of a character
 * in the order BITS/FONT/CODE I store them as FONT/BITS/CODE so it
 * is then easy to store international characters as FONT/CODE16. The
 * option "Kanji" enables some use of this.
 */

static Lisp_Object Lchar_downcase(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    CSL_IGNORE(nil);
    characterify(a);
    if (!is_char(a)) return aerror("char-downcase");
    cc = code_of_char(a);
    if (ISupper(cc))        /* Caution to help non-ANSI libraries */
        cc = TOlower(cc);
#ifdef COMMON
#ifdef Kanji
#define insert_code(old, new) \
    (((old) & 0xff0000ff) | ((((int32_t)(new)) & 0xffff) << 8))
#else
#define insert_code(old, new) \
    (((old) & 0xffff00ff) | ((((int32_t)(new)) & 0xff) << 8))
#endif
    return onevalue(insert_code(a, cc));
#else
    return char_to_id(cc);
#endif
}

#ifdef COMMON

Lisp_Object Lcharacter(Lisp_Object nil, Lisp_Object a)
{
    if (is_char(a)) return onevalue(a);
    else if (is_vector(a))
    {   Header h = vechdr(a);
        if (type_of_header(h) == TYPE_STRING)
        {   if (length_of_header(h) > 4)   /* @@@@ /* 4 vs CELL */
            {   int c0 = celt(a, 0);
#ifdef Kanji
                if (length_of_header(h) > 5 && iswchar(c0))
                    c0 = (c0 << 8) + ucelt(a, 1);
#endif
                return onevalue(pack_char(0,0,c0));
            }
            else return aerror1("character", a);
        }
/*
 * /* The issue of strings (especially non-simple ones) and the ELT function
 * and wide characters has NOT BEEN THOUGHT THROUGH.
 */
        else if (stringp(a))
        {   Lisp_Object w = Lelt(nil, a, fixnum_of_int(0));
            errexit();
            return onevalue(w);
        }
        else return aerror1("character", a);
    }
    else if (is_fixnum(a))
#ifdef Kanji
        return onevalue(pack_char(0, 0, int_of_fixnum(a) & 0xffff));
#else
        return onevalue(pack_char(0, 0, int_of_fixnum(a) & 0xff));
#endif
    else if (is_symbol(a)) return Lcharacter(nil, qpname(a));
    else return aerror1("character", a);
}

static Lisp_Object Lcharacterp(Lisp_Object nil, Lisp_Object a)
{
    return onevalue(Lispify_predicate(is_char(a)));
}

static Lisp_Object Lchar_bits(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    characterify(a);
    if (!is_char(a)) return aerror("char-bits");
    return onevalue(fixnum_of_int(bits_of_char(a)));
}

static Lisp_Object Lchar_font(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    characterify(a);
    if (!is_char(a)) return aerror("char-font");
    return onevalue(fixnum_of_int(font_of_char(a)));
}

#endif

static Lisp_Object Lchar_upcase(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    CSL_IGNORE(nil);
    characterify(a);
    if (!is_char(a)) return aerror("char-upcase");
    cc = code_of_char(a);
    if (ISlower(cc))
        cc = TOupper(cc);
#ifdef COMMON
    return onevalue(insert_code(a, cc));
#else
    return char_to_id(cc);
#endif
}

Lisp_Object Lwhitespace_char_p(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF
#ifndef Kanji
        || bits_of_char(a) != 0
#endif
        ) return onevalue(nil);
    /* BITS present => not whitespace (unless Kanji) */
    cc = code_of_char(a);
    return onevalue(Lispify_predicate(ISspace(cc)));
}

Lisp_Object Lalpha_char_p(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    characterify(a);
    if (!is_char(a)) return onevalue(nil);
#ifndef Kanji
    if (bits_of_char(a) != 0) return onevalue(nil); /* BITS present */
#endif
    cc = code_of_char(a);
    return onevalue(Lispify_predicate(ISalpha(cc)));
}

#ifdef COMMON

static Lisp_Object Lgraphic_char_p(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    characterify(a);
    if (!is_char(a)) return onevalue(nil);
#ifndef Kanji
    if (bits_of_char(a) != 0) return onevalue(nil); /* BITS present */
#endif
    cc = code_of_char(a);
    return onevalue(Lispify_predicate(ISgraph(cc) || cc==' '));
}

static Lisp_Object Lupper_case_p(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    characterify(a);
    if (!is_char(a)) return onevalue(nil);
#ifndef Kanji
    if (bits_of_char(a) != 0) return onevalue(nil);
#endif
    cc = code_of_char(a);
    return onevalue(Lispify_predicate(ISupper(cc)));
}

static Lisp_Object Llower_case_p(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    characterify(a);
    if (!is_char(a)) return onevalue(nil);
#ifndef Kanji
    if (bits_of_char(a) != 0) return onevalue(nil);
#endif
    cc = code_of_char(a);
    return onevalue(Lispify_predicate(ISlower(cc)));
}

#endif

#ifdef COMMON
Lisp_Object Ldigit_char_p_2(Lisp_Object nil, Lisp_Object a, Lisp_Object radix)
{
    int cc;
    Lisp_Object r = radix;
    if (!is_fixnum(r) || r < fixnum_of_int(2) ||
        r >= fixnum_of_int(36)) return aerror("digit-char-p");
    characterify(a);
    if (!is_char(a)) return onevalue(nil);
#ifndef Kanji
    if (bits_of_char(a) != 0) return onevalue(nil);
#endif
    cc = code_of_char(a);
    if (!ISalnum(cc)) return onevalue(nil);
    if (ISupper(cc))
        cc = TOlower(cc);
/*
 * The following code is intended to cope with EBCDIC as well as ASCII
 * character codes. The effect is still notionally not portable in that
 * a yet further character code (with 'a' to 'i' non-consecutive, say)
 * would defeat it!
 */
    if ('0' <= cc && cc <= '9') cc = cc - '0';
    else if ('a' <= cc && cc <= 'i') cc = cc - 'a' + 10;
    else if ('j' <= cc && cc <= 'r') cc = cc - 'j' + 19;
    else if ('s' <= cc && cc <= 'z') cc = cc - 's' + 28;
    else cc = 255;
    if (cc >= int_of_fixnum(r)) return onevalue(nil);
    else return onevalue(fixnum_of_int((int32_t)cc));
}

Lisp_Object Ldigit_char_p_1(Lisp_Object nil, Lisp_Object a)
{
    return Ldigit_char_p_2(nil, a, fixnum_of_int(10));
}

#endif

Lisp_Object Ldigitp(Lisp_Object nil, Lisp_Object a)
{
    int cc;
    characterify(a);
    if (!is_char(a)) return onevalue(nil);
#ifndef Kanji
    if (bits_of_char(a) != 0) return onevalue(nil);
#endif
    cc = code_of_char(a);
    return onevalue(Lispify_predicate(ISdigit(cc)));
}

#ifdef COMMON

static Lisp_Object MS_CDECL Ldigit_char_n(Lisp_Object nil, int nargs, ...)
{
    va_list aa;
    Lisp_Object a, r, f;
    if (nargs != 3) return aerror("digit-char");
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    r = va_arg(aa, Lisp_Object);
    f = va_arg(aa, Lisp_Object);
    va_end(aa);
    if (!is_fixnum(a) || !is_fixnum(r) || !is_fixnum(f) ||
        a < 0 || r < fixnum_of_int(2) || f < 0 ||
        a >= r || r > fixnum_of_int(36) ||
        f > fixnum_of_int(255)) return onevalue(nil);
/*
 * The following code is intended to cope with EBCDIC as well as ASCII
 * character codes. See comment in digit_char_p().
 */
    a = int_of_fixnum(a);
    if (a <= 9) a = a + '0';
    else if (a <= 18) a = a + ('A' - 10);
    else if (a <= 27) a = a + ('J' - 19);
    else a = a + ('S' - 28);
    return onevalue(pack_char(0, int_of_fixnum(f) & 0xff, a & 0xff));
}

static Lisp_Object Ldigit_char_2(Lisp_Object nil, Lisp_Object a,
                        Lisp_Object r1)
{
    return Ldigit_char_n(nil, 3, a, r1, fixnum_of_int(0));
}

static Lisp_Object Ldigit_char_1(Lisp_Object nil, Lisp_Object a)
{
    return Ldigit_char_n(nil, 3, a, fixnum_of_int(10), fixnum_of_int(0));
}


#endif

Lisp_Object Lspecial_char(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a)) return aerror("special-char");
    switch (int_of_fixnum(a))
    {
case 0:   /* space */
        a = pack_char(0, 0, ' ');
        break;
case 1:   /* newline */
        a = pack_char(0, 0, '\n');
        break;
case 2:   /* backspace */
        a = pack_char(0, 0, '\b');
        break;
case 3:   /* tab */
        a = pack_char(0, 0, '\t');
        break;
case 4:   /* linefeed (well, I use VT, '\v' in C terms) */
        a = pack_char(0, 0, '\v');
        break;
case 5:   /* page */
        a = pack_char(0, 0, '\f');
        break;
case 6:   /* return */
        a = pack_char(0, 0, '\r');
        break;
case 7:   /* rubout: not available in EBCDIC, sorry */
        a = pack_char(0, 0, 0x7fL);
        break;
case 8:   /* end of file character */
        a = CHAR_EOF;
        break;
case 9:   /* 'attention', typically ctrl-G */
        a = pack_char(0, 0, '\a');
        break;
case 10:  /* 'ESC', not available on all computers! */
        a = pack_char(0, 0, 0x1b);
        break;
default:
        return aerror("special-char");
    }
/*
 * What about this and Standard Lisp mode???  Well it still hands back
 * a "character object", and these are generally not at all useful in
 * Standard Lisp.  Two exceptions occur - first character objects are
 * valid in lists handed to compress, and secondly the character object
 * for end-of-file is used for that in Standard Lisp mode.
 */
    return onevalue(a);
}

Lisp_Object Lchar_code(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    characterify(a);
    if (!is_char(a)) return aerror("char-code");
    return onevalue(fixnum_of_int(code_of_char(a)));
}

static Lisp_Object MS_CDECL Lcode_charn(Lisp_Object nil, int nargs, ...)
{
    va_list aa;
    Lisp_Object a, bits, font;
    int32_t av;
    argcheck(nargs, 3, "code-char");
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    bits = va_arg(aa, Lisp_Object);
    font = va_arg(aa, Lisp_Object);
    va_end(aa);
    CSL_IGNORE(nil);
    if ((int32_t)bits < 0 || (int32_t)bits >= (int32_t)fixnum_of_int(16L) ||
        (int32_t)font < 0 || (int32_t)font >= (int32_t)fixnum_of_int(256L) ||
#ifdef Kanji
        (int32_t)a < 0 || (int32_t)a >= (int32_t)fixnum_of_int(65536L)
#else
        (int32_t)a < 0 || (int32_t)a >= (int32_t)fixnum_of_int(256L)
#endif
        )
            return aerror("code-char");
#ifdef Kanji
    av = int_of_fixnum(a) & 0xffff;
#else
    av = int_of_fixnum(a) & 0xff;
#endif
#ifdef COMMON
    return onevalue(pack_char(int_of_fixnum(bits),
                              int_of_fixnum(font) & 0xff,
                              av));
#else
    return char_to_id(av);
#endif
}

static Lisp_Object Lcode_char1(Lisp_Object nil, Lisp_Object a)
{
    return Lcode_charn(nil, 3, a, fixnum_of_int(0), fixnum_of_int(0));
}

static Lisp_Object Lcode_char2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lcode_charn(nil, 3, a, b, fixnum_of_int(0));
}

#ifdef COMMON

static Lisp_Object Lchar_int(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    characterify(a);
    if (!is_char(a)) return aerror("char-int");
    return onevalue(fixnum_of_int(((uint32_t)a) >> 8));
}

static Lisp_Object Lint_char(Lisp_Object nil, Lisp_Object a)
{
    if (!is_fixnum(a) || (a & 0xff000000L) != 0) return nil;
    return onevalue(TAG_CHAR + (int_of_fixnum(a) << 8));
}

static Lisp_Object MS_CDECL Lmake_char(Lisp_Object nil, int nargs, ...)
{
    va_list aa;
    Lisp_Object a, bits, font;
    CSL_IGNORE(nil);
    if (nargs == 0 || nargs > 3) return aerror("make-char");
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    if (nargs > 1) bits = va_arg(aa, Lisp_Object);
    else bits = fixnum_of_int(0);
    if (nargs > 2) font = va_arg(aa, Lisp_Object);
    else font = fixnum_of_int(0);
    va_end(aa);
    if (bits < 0 || bits >= fixnum_of_int(16L) ||
        font < 0 || font >= fixnum_of_int(256L) ||
        !is_char(a)) return aerror("make-char");
#ifdef Kanji
    return onevalue(pack_char(int_of_fixnum(bits),
                              int_of_fixnum(font) & 0xff,
                              code_of_char(a) & 0xffff));
#else
    return onevalue(pack_char(int_of_fixnum(bits),
                              int_of_fixnum(font) & 0xff,
                              code_of_char(a) & 0xff));
#endif
}

/*
 * Character comparisons are VERY like the arithmetic ones, but need
 * only deal with character objects, which are immediate data and
 * in general terms nicer.
 */

static CSLbool chartest(Lisp_Object c)
{
    if (!is_char(c))
    {   aerror1("Character object expected", c);
        return YES;
    }
    else return NO;
}

static Lisp_Object MS_CDECL Lchar_eqn(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (chartest(r)) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        if (chartest(s)) { va_end(a); return nil; }
        if (r != s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lchar_eqn_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lchar_eqn(nil, 2, a, b);
}

static Lisp_Object Lchar_eqn_1(Lisp_Object nil, Lisp_Object a)
{
    return Lchar_eqn(nil, 1, a);
}

static Lisp_Object MS_CDECL Lchar_lessp(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (chartest(r)) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        if (chartest(s)) { va_end(a); return nil; }
        if ((uint32_t)r >= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lchar_lessp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lchar_lessp(nil, 2, a, b);
}

static Lisp_Object Lchar_lessp_1(Lisp_Object nil, Lisp_Object a)
{
    return Lchar_lessp(nil, 1, a);
}

static Lisp_Object MS_CDECL Lchar_greaterp(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (chartest(r)) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        if (chartest(s)) { va_end(a); return nil; }
        if ((uint32_t)r <= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lchar_greaterp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lchar_greaterp(nil, 2, a, b);
}

static Lisp_Object Lchar_greaterp_1(Lisp_Object nil, Lisp_Object a)
{
    return Lchar_greaterp(nil, 1, a);
}

static Lisp_Object MS_CDECL Lchar_neq_n(Lisp_Object nil, int nargs, ...)
/*
 * /= is supposed to check that NO pair of args match.
 * Because this involves multiple scanning of the vector of args it seems
 * necessary to copy the arge into a vector that I can scan more directly
 * than va_args lets me scan the arg list.
 */
{
    int i, j;
    va_list a;
    Lisp_Object *r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    r = (Lisp_Object *)&work_1;
    va_start(a, nargs);
    for (i=0; i<nargs; i++) r[i] = va_arg(a, Lisp_Object);
    va_end(a);
    if (chartest(r[0])) return nil;
    for (i = 1; i<nargs; i++)
    {   Lisp_Object n1 = r[i];
        if (chartest(n1)) return nil;
        for (j=0; j<i; j++)
        {   Lisp_Object n2 = r[j];
            if (n1 == n2) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static Lisp_Object Lchar_neq_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lchar_neq_n(nil, 2, a, b);
}

static Lisp_Object Lchar_neq_1(Lisp_Object nil, Lisp_Object a)
{
    return Lchar_neq_n(nil, 1, a);
}

static Lisp_Object MS_CDECL Lchar_geq(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (chartest(r)) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        if (chartest(s)) { va_end(a); return nil; }
        if ((uint32_t)r < (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lchar_geq_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lchar_geq(nil, 2, a, b);
}

static Lisp_Object Lchar_geq_1(Lisp_Object nil, Lisp_Object a)
{
    return Lchar_geq(nil, 1, a);
}

static Lisp_Object MS_CDECL Lchar_leq(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (chartest(r)) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        if (chartest(s)) { va_end(a); return nil; }
        if ((uint32_t)r > (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lchar_leq_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lchar_leq(nil, 2, a, b);
}

static Lisp_Object Lchar_leq_1(Lisp_Object nil, Lisp_Object a)
{
    return Lchar_leq(nil, 1, a);
}


/*
 * Character comparisons are VERY like the arithmetic ones, but need
 * only deal with character objects, which are immediate data and
 * in general terms nicer.  These versions look only at the code, not
 * at the case or the bits attributes.
 */

static Lisp_Object casefold(Lisp_Object c)
{
    int cc;
    if (!is_char(c)) return aerror("Character object expected");
    cc = code_of_char(c);   /* Character in the C sense */
    cc = TOupper(cc);
    return insert_code(c, cc);
}

static Lisp_Object MS_CDECL Lcharacter_eqn(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending()) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending()) { va_end(a); return nil; }
        if (r != s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lcharacter_eqn_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lcharacter_eqn(nil, 2, a, b);
}

static Lisp_Object Lcharacter_eqn_1(Lisp_Object nil, Lisp_Object a)
{
    return Lcharacter_eqn(nil, 1, a);
}

static Lisp_Object MS_CDECL Lcharacter_lessp(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending()) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending()) { va_end(a); return nil; }
        if ((uint32_t)r >= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lcharacter_lessp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lcharacter_lessp(nil, 2, a, b);
}

static Lisp_Object Lcharacter_lessp_1(Lisp_Object nil, Lisp_Object a)
{
    return Lcharacter_lessp(nil, 1, a);
}

static Lisp_Object MS_CDECL Lcharacter_greaterp(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending()) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending()) { va_end(a); return nil; }
        if ((uint32_t)r <= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lcharacter_greaterp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lcharacter_greaterp(nil, 2, a, b);
}

static Lisp_Object Lcharacter_greaterp_1(Lisp_Object nil, Lisp_Object a)
{
    return Lcharacter_greaterp(nil, 1, a);
}

static Lisp_Object MS_CDECL Lcharacter_neq_n(Lisp_Object nil, int nargs, ...)
/*
 * /= is supposed to check that NO pair of args match.
 * Because this involves multiple scanning of the vector of args it seems
 * necessary to copy the arge into a vector that I can scan more directly
 * than va_args lets me scan the arg list.
 */
{
    int i, j;
    va_list a;
    Lisp_Object *r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    r = (Lisp_Object *)&work_1;
    va_start(a, nargs);
    for (i=0; i<nargs; i++) r[i] = va_arg(a, Lisp_Object);
    va_end(a);
    if (chartest(r[0])) return nil;
    for (i = 1; i<nargs; i++)
    {   Lisp_Object n1 = r[i];
        n1 = casefold(n1);
        errexit();
        for (j=0; j<i; j++)
        {   Lisp_Object n2 = r[j];
            n2 = casefold(n2);  /* can not fail - this arg tested earlier */
            if (n1 == n2) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static Lisp_Object Lcharacter_neq_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lcharacter_neq_n(nil, 2, a, b);
}

static Lisp_Object Lcharacter_neq_1(Lisp_Object nil, Lisp_Object a)
{
    return Lcharacter_neq_n(nil, 1, a);
}

static Lisp_Object MS_CDECL Lcharacter_geq(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending()) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending()) { va_end(a); return nil; }
        if ((uint32_t)r < (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lcharacter_geq_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lcharacter_geq(nil, 2, a, b);
}

static Lisp_Object Lcharacter_geq_1(Lisp_Object nil, Lisp_Object a)
{
    return Lcharacter_geq(nil, 1, a);
}

static Lisp_Object MS_CDECL Lcharacter_leq(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending()) { va_end(a); return nil; }
    for (i = 1; i<nargs; i++)
    {   Lisp_Object s = va_arg(a, Lisp_Object);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending()) { va_end(a); return nil; }
        if ((uint32_t)r > (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static Lisp_Object Lcharacter_leq_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lcharacter_leq(nil, 2, a, b);
}

static Lisp_Object Lcharacter_leq_1(Lisp_Object nil, Lisp_Object a)
{
    return Lcharacter_leq(nil, 1, a);
}


/*
 * I will also put some versions of string comparisons here - the versions
 * implemented this way will have no keyword args.
 */


/*
 * get_char_vec(v, &high, &offset) is used in places where v is expected
 * to be a string or symbol. It returns a simple vector, which the celt()
 * macro can access, and sets high & offset. The string will then
 * have characters with index 0 <= n < high, but to access them the offset
 * value needs to be added. If the input is not a proper string then nil
 * will be returned.
 */

static Lisp_Object get_char_vec(Lisp_Object v, int32_t *high, int32_t *offset)
{
    Header h;
    Lisp_Object nil = C_nil, w;
    if (symbolp(v)) v = qpname(v);
    if (!is_vector(v)) return nil;
    h = vechdr(v);
    if (type_of_header(h) == TYPE_STRING)
    {   *high = length_of_header(h) - 4; /* @@@ /* 4 vs CELL */
        *offset = 0;
        return v;
    }
    if (!is_vector(v)) return nil;
    h = vechdr(v);
    if (type_of_header(h) != TYPE_ARRAY) return nil;
    w = elt(v, 1);   /* The list of dimensions */
    if (w == nil || qcdr(w) != nil) return nil;
    *high = int_of_fixnum(qcar(w));
    *offset = int_of_fixnum(elt(v, 3));
    v = elt(v, 2);
    h = vechdr(v);
    if (type_of_header(h) != TYPE_STRING) return nil;
    else return v;
}

static Lisp_Object Lstring_greaterp_2(Lisp_Object nil,
                                      Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string>", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string>", b);
    b = w;
    for (i=0;;i++)
    {   if (i == lb)
        {   if (i == la) return onevalue(nil);
            else return onevalue(fixnum_of_int(i));
        }
        else if (i == la) return onevalue(nil);
        ca = ucelt(a, i+oa);
        cb = ucelt(b, i+ob);
        if (ca == cb) continue;
        if (ca > cb) return onevalue(fixnum_of_int(i));
        else return onevalue(nil);
    }
}

static Lisp_Object Lstring_lessp_2(Lisp_Object nil,
                                   Lisp_Object a, Lisp_Object b)
{
    return Lstring_greaterp_2(nil, b, a);
}

static Lisp_Object Lstring_not_equal_2(Lisp_Object nil,
                                       Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string/=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string/=", b);
    b = w;
    for (i=0;;i++)
    {   if (i == lb)
        {   if (i == la) return onevalue(nil);
            else return onevalue(fixnum_of_int(i));
        }
        else if (i == la) return onevalue(fixnum_of_int(i));
        ca = ucelt(a, i+oa);
        cb = ucelt(b, i+ob);
        if (ca == cb) continue;
        return onevalue(fixnum_of_int(i));
    }
}

static Lisp_Object Lstring_equal_2(Lisp_Object nil,
                                   Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string=", b);
    b = w;
    for (i=0;;i++)
    {   if (i == lb)
        {   if (i == la) return onevalue(lisp_true);
            else return onevalue(nil);
        }
        else if (i == la) return onevalue(nil);
        ca = ucelt(a, i+oa);
        cb = ucelt(b, i+ob);
        if (ca == cb) continue;
        else return onevalue(nil);
    }
}

static Lisp_Object Lstring_not_greaterp_2(Lisp_Object nil,
                                          Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string<=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string<=", b);
    b = w;
    for (i=0;;i++)
    {   if (i == la) return onevalue(fixnum_of_int(i));
        else if (i == lb) return onevalue(nil);
        ca = ucelt(a, i+oa);
        cb = ucelt(b, i+ob);
        if (ca == cb) continue;
        if (ca < cb) return onevalue(fixnum_of_int(i));
        else return onevalue(nil);
    }
}

static Lisp_Object Lstring_not_lessp_2(Lisp_Object nil,
                                       Lisp_Object a, Lisp_Object b)
{
    return Lstring_not_greaterp_2(nil, b, a);
}

static Lisp_Object L_string_greaterp_2(Lisp_Object nil,
                                      Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string>", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string>", b);
    b = w;
    for (i=0;;i++)
    {   if (i == lb)
        {   if (i == la) return onevalue(nil);
            else return onevalue(fixnum_of_int(i));
        }
        else if (i == la) return onevalue(nil);
        ca = toupper(celt(a, i+oa));
        cb = toupper(celt(b, i+ob));
        if (ca == cb) continue;
        if (ca > cb) return onevalue(fixnum_of_int(i));
        else return onevalue(nil);
    }
}

static Lisp_Object L_string_lessp_2(Lisp_Object nil,
                                   Lisp_Object a, Lisp_Object b)
{
    return L_string_greaterp_2(nil, b, a);
}

static Lisp_Object L_string_not_equal_2(Lisp_Object nil,
                                       Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string/=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string/=", b);
    b = w;
    for (i=0;;i++)
    {   if (i == lb)
        {   if (i == la) return onevalue(nil);
            else return onevalue(fixnum_of_int(i));
        }
        else if (i == la) return onevalue(fixnum_of_int(i));
        ca = toupper(celt(a, i+oa));
        cb = toupper(celt(b, i+ob));
        if (ca == cb) continue;
        return onevalue(fixnum_of_int(i));
    }
}

static Lisp_Object L_string_equal_2(Lisp_Object nil,
                                   Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string=", b);
    b = w;
    for (i=0;;i++)
    {   if (i == lb)
        {   if (i == la) return onevalue(lisp_true);
            else return onevalue(nil);
        }
        else if (i == la) return onevalue(nil);
        ca = toupper(celt(a, i+oa));
        cb = toupper(celt(b, i+ob));
        if (ca == cb) continue;
        else return onevalue(nil);
    }
}

static Lisp_Object L_string_not_greaterp_2(Lisp_Object nil,
                                          Lisp_Object a, Lisp_Object b)
{
    int32_t la, oa, lb, ob, i;
    int ca, cb;
    Lisp_Object w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string<=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string<=", b);
    b = w;
    for (i=0;;i++)
    {   if (i == la) return onevalue(fixnum_of_int(i));
        else if (i == lb) return onevalue(nil);
        ca = toupper(celt(a, i+oa));
        cb = toupper(celt(b, i+ob));
        if (ca == cb) continue;
        if (ca < cb) return onevalue(fixnum_of_int(i));
        else return onevalue(nil);
    }
}

static Lisp_Object L_string_not_lessp_2(Lisp_Object nil,
                                       Lisp_Object a, Lisp_Object b)
{
    return L_string_not_greaterp_2(nil, b, a);
}

#endif

setup_type const char_setup[] =
{
    {"char-code",               Lchar_code, too_many_1, wrong_no_1},
    {"char-downcase",           Lchar_downcase, too_many_1, wrong_no_1},
    {"char-upcase",             Lchar_upcase, too_many_1, wrong_no_1},
    {"code-char",               Lcode_char1, Lcode_char2, Lcode_charn},
    {"digit",                   Ldigitp, too_many_1, wrong_no_1},
    {"special-char",            Lspecial_char, too_many_1, wrong_no_1},
#ifdef COMMON
    {"alpha-char-p",            Lalpha_char_p, too_many_1, wrong_no_1},
    {"both-case-p",             Lalpha_char_p, too_many_1, wrong_no_1},
    {"char-bits",               Lchar_bits, too_many_1, wrong_no_1},
    {"char-equal",              Lcharacter_eqn_1, Lcharacter_eqn_2, Lcharacter_eqn},
    {"char-font",               Lchar_font, too_many_1, wrong_no_1},
    {"char-greaterp",           Lcharacter_greaterp_1, Lcharacter_greaterp_2, Lcharacter_greaterp},
    {"char-int",                Lchar_int, too_many_1, wrong_no_1},
    {"char-lessp",              Lcharacter_lessp_1, Lcharacter_lessp_2, Lcharacter_lessp},
    {"char-not-equal",          Lcharacter_neq_1, Lcharacter_neq_2, Lcharacter_neq_n},
    {"char-not-greaterp",       Lcharacter_leq_1, Lcharacter_leq_2, Lcharacter_leq},
    {"char-not-lessp",          Lcharacter_geq_1, Lcharacter_geq_2, Lcharacter_geq},
    {"char/=",                  Lchar_neq_1, Lchar_neq_2, Lchar_neq_n},
    {"char<",                   Lchar_lessp_1, Lchar_lessp_2, Lchar_lessp},
    {"char<=",                  Lchar_leq_1, Lchar_leq_2, Lchar_leq},
    {"char=",                   Lchar_eqn_1, Lchar_eqn_2, Lchar_eqn},
    {"char>",                   Lchar_greaterp_1, Lchar_greaterp_2, Lchar_greaterp},
    {"char>=",                  Lchar_geq_1, Lchar_geq_2, Lchar_geq},
    {"character",               Lcharacter, too_many_1, wrong_no_1},
    {"characterp",              Lcharacterp, too_many_1, wrong_no_1},
    {"digit-char",              Ldigit_char_1, Ldigit_char_2, Ldigit_char_n},
    {"digit-char-p",            Ldigit_char_p_1, Ldigit_char_p_2, wrong_no_1},
    {"graphic-char-p",          Lgraphic_char_p, too_many_1, wrong_no_1},
    {"int-char",                Lint_char, too_many_1, wrong_no_1},
    {"lower-case-p",            Llower_case_p, too_many_1, wrong_no_1},
    {"make-char",               wrong_no_na, wrong_no_nb, Lmake_char},
    {"upper-case-p",            Lupper_case_p, too_many_1, wrong_no_1},
    {"whitespace-char-p",       Lwhitespace_char_p, too_many_1, wrong_no_1},
    {"string<2",                too_few_2, Lstring_lessp_2, wrong_no_2},
    {"string>2",                too_few_2, Lstring_greaterp_2, wrong_no_2},
    {"string=2",                too_few_2, Lstring_equal_2, wrong_no_2},
    {"string/=2",               too_few_2, Lstring_not_equal_2, wrong_no_2},
    {"string<=2",               too_few_2, Lstring_not_greaterp_2, wrong_no_2},
    {"string>=2",               too_few_2, Lstring_not_lessp_2, wrong_no_2},
    {"string-lessp2",           too_few_2, L_string_lessp_2, wrong_no_2},
    {"string-greaterp2",        too_few_2, L_string_greaterp_2, wrong_no_2},
    {"string-equal2",           too_few_2, L_string_equal_2, wrong_no_2},
    {"string-not-equal2",       too_few_2, L_string_not_equal_2, wrong_no_2},
    {"string-not-greaterp2",    too_few_2, L_string_not_greaterp_2, wrong_no_2},
    {"string-not-lessp2",       too_few_2, L_string_not_lessp_2, wrong_no_2},
#else
    {"liter",                   Lalpha_char_p, too_many_1, wrong_no_1},
    {"seprp",                   Lwhitespace_char_p, too_many_1, wrong_no_1},
#endif
    {NULL,                      0, 0, 0}
};

/* end of char.c */

