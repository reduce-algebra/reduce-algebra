//  char.cpp                         Copyright (C) 1989-2015 Codemist    

//
// Character handling.
//

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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

//
// I am now situation where all internal data is Unicode,
// stored in strings in utf-8 format.
//

//
// For many character functions I will permit the argument to be either
// a character object (Common Lisp syntax #\x) or a symbol. If it is a
// symbol the "character" tested will be the first one in the print-name,
// and (of course) very often I will just use the symbols 'a, 'b, 'c etc
// to stand for the characters #\a, #\b, #\c....
// If the symbol has a print-name of length other than 1 I will not
// count it as a valid character. But note that that has to be counting
// in characters not bytes... so you see messy utf-8 conversion here.
// Common Lisp seens to say that character functions ought to be handed
// real character objects - so extending this to permit symbols as well
// is probably safe. If it were not I could just redefine this as
// a null expansion in Common Lisp mode.
// NB gensyms are OK here since I only need the 1st char of the base-name
//

LispObject characterify_string(LispObject pn)
{   int n, w, len = length_of_byteheader(vechdr(pn)) - CELL;
    if (len == 0) return pn; // empty name
    w = ucelt(pn, 0);
    if (w <= 0x7f && len == 1) return pack_char(0, w);
    else if ((w & 0xe0) == 0xc0 && len == 2)
    {   w = (w & 0x1f) << 6;
        n = ucelt(pn, 1);
        if ((n & 0xc0) == 0x80) return pack_char(0, w + (n & 0x3f));
        else return pn;
    }
    else if ((w & 0xf0) == 0xe0 && len == 3)
    {   w = (w & 0x0f) << 12;
        n = ucelt(pn, 1);
        if ((n & 0xc0) != 0x80) return pn;
        w = w + ((n & 0x3f) << 6);
        n = ucelt(pn, 2);
        if ((n & 0xc0) == 0x80) return pack_char(0, w + (n & 0x3f));
        else return pn;
    }
    else if ((w & 0xf8) == 0xf0 && len == 4)
    {   w = (w & 0x07) << 18;
        n = ucelt(pn, 1);
        if ((n & 0xc0) != 0x80) return pn;
        w = w + ((n & 0x3f) << 2);
        n = ucelt(pn, 2);
        if ((n & 0xc0) != 0x80) return pn;
        w = w + ((n & 0x3f) << 6);
        n = ucelt(pn, 3);
        if ((n & 0xc0) == 0x80) return pack_char(0, w + (n & 0x3f));
        else return pn;
    }
    else return pn;
}

LispObject characterify(LispObject c)
{   if (is_symbol(c)) return characterify_string(qpname(c));
    else if (is_vector(c) && is_string(c))
        return characterify_string(c);
    else if (is_fixnum(c)) return pack_char(0, int_of_fixnum(c));
    else return c;
}

LispObject char_to_id(int ch)
{   LispObject nil = C_nil;
    LispObject w;
    int n;
    if (ch == -1) return onevalue(eof_symbol);
    ch &= 0x001fffff;
    if (ch <= 0xff &&
        ((w = elt(charvec, ch)) != nil)) return onevalue(w);
    if (ch <= 0x7f)
    {   celt(boffo, 0) = ch;
        n = 1;
    }
    else if (ch <= 0x7ff)
    {   celt(boffo, 0) = 0xc0 + (ch>>6);
        celt(boffo, 1) = 0x80 + (ch & 0x3f);
        n = 2;
    }
    else if (ch <= 0xffff)
    {   celt(boffo, 0) = 0xe0 + (ch>>12);
        celt(boffo, 1) = 0x80 + ((ch>>6) & 0x3f);
        celt(boffo, 2) = 0x80 + (ch & 0x3f);
        n = 3;
    }
    else
    {   celt(boffo, 0) = 0xf0 + (ch>>18);
        celt(boffo, 1) = 0x80 + ((ch>>12) & 0x3f);
        celt(boffo, 2) = 0x80 + ((ch>>6) & 0x3f);
        celt(boffo, 3) = 0x80 + (ch & 0x3f);
        n = 4;
    }
    w = iintern(boffo, n, lisp_package, 0);
    errexit();
    if (ch <= 0xff) elt(charvec, ch) = w;
    return onevalue(w);
}


//
// Characters have 3 bits of FONT, then 21 of CODE.
// FONT information is only used in COMMON mode, if then.
// Indeed newer released on the Common Lisp standard give up on font
// as part of a character object.
//

static LispObject Lchar_downcase(LispObject, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return aerror("char-downcase");
#ifdef COMMON
    if (a == CHAR_EOF) return onevalue(a);
#else
    if (a == CHAR_EOF) return onevalue(eof_symbol);
#endif
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t)==4)
    {   if (iswupper(cc)) cc = towlower(cc);
    }
#ifdef COMMON
    return = pack_char(font_of_char(a), cc);
#else
    return char_to_id(cc);
#endif
}

#ifdef COMMON

LispObject Lcharacter(LispObject nil, LispObject a)
{   if (is_char(a)) return onevalue(a);
    else if (is_vector(a))
    {   Header h = vechdr(a);
        if (is_string_header(h))
            return onevalue(characterify_string(a));
//
// /* The issue of strings (especially non-simple ones) and the ELT function
// and wide characters has NOT BEEN THOUGHT THROUGH. So this bit is a
// mess.
//
        else if (stringp(a))
        {   LispObject w = Lelt(nil, a, fixnum_of_int(0));
            errexit();
            return onevalue(w);
        }
        else return aerror1("character", a);
    }
    else if (is_fixnum(a))
        return onevalue(pack_char(0, int_of_fixnum(a) & 0x001fffff));
    else if (is_symbol(a)) return onevalue(characterify_string(qpname(a));
                                               else return aerror1("character", a);
        }

                              static LispObject Lcharacterp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(is_char(a)));
}

static LispObject Lchar_bits(LispObject, LispObject a)
{
// "bits" are no longer supported (or needed).
    a = characterify(a);
    if (!is_char(a)) return aerror("char-bits");
    return onevalue(fixnum_of_int(0));
}

static LispObject Lchar_font(LispObject, LispObject a)
{   a = characterify(a);
    if (!is_char(a)) return aerror("char-font");
    return onevalue(fixnum_of_int(font_of_char(a)));
}

#endif

static LispObject Lchar_upcase(LispObject, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return aerror("char-upcase");
#ifdef COMMON
    if (a == CHAR_EOF) return onevalue(a);
#else
    if (a == CHAR_EOF) return onevalue(eof_symbol);
#endif
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
        cc = towupper(cc);
#ifdef COMMON
    return onevalue(pack_char(font_of_char(a), cc));
#else
    return char_to_id(cc);
#endif
}

LispObject Lwhitespace_char_p(LispObject nil, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
    {   if (iswspace(cc)) return onevalue(lisp_true);
    }
    return onevalue(nil);
}

LispObject Lalpha_char_p(LispObject nil, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
    {   if (iswalpha(cc)) return onevalue(lisp_true);
    }
    return onevalue(nil);
}

#ifdef COMMON

static LispObject Lgraphic_char_p(LispObject nil, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
    {   if (iswgraph(cc) || cc==' ') return onevalue(lisp_true);
    }
    return onevalue(nil);
    return onevalue(Lispify_predicate(ISgraph(cc) || cc==' '));
}

static LispObject Lupper_case_p(LispObject nil, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
    {   if (iswupper(cc) || cc==' ') return onevalue(lisp_true);
    }
    return onevalue(nil);
}

static LispObject Llower_case_p(LispObject nil, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
    {   if (iswlower(cc) || cc==' ') return onevalue(lisp_true);
    }
    return onevalue(nil);
}

#endif

#ifdef COMMON
LispObject Ldigit_char_p_2(LispObject nil, LispObject a, LispObject radix)
{   int cc;
    LispObject r = radix;
    if (!is_fixnum(r) || r < fixnum_of_int(2) ||
        r >= fixnum_of_int(36)) return aerror("digit-char-p");
    a = characterify(a);
    if (!is_char(a) || a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if ((cc > 0xffff && sizeof(wchar_t) < 4) ||
        !iswalnum(cc)) return onevalue(nil);
// If I get here then cc is a valid argument of iswupper etc
    if (iswupper(cc)) cc = towlower(cc);
    if ('0' <= cc && cc <= '9') cc = cc - '0';
    else if ('a' <= cc && cc <= 'z') cc = cc - 'a' + 10;
    else cc = 255;
    if (cc >= int_of_fixnum(r)) return onevalue(nil);
    else return onevalue(fixnum_of_int((int32_t)cc));
}

LispObject Ldigit_char_p_1(LispObject nil, LispObject a)
{   return Ldigit_char_p_2(nil, a, fixnum_of_int(10));
}

#endif

LispObject Ldigitp(LispObject nil, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc > 0xffff && sizeof(wchar_t) < 4) return onevalue(nil);
    return onevalue(Lispify_predicate(iswdigit(cc)));
}

#ifdef COMMON

static LispObject Ldigit_char_n(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject a, r, f;
    if (nargs != 3) return aerror("digit-char");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    r = va_arg(aa, LispObject);
    f = va_arg(aa, LispObject);
    va_end(aa);
    if (!is_fixnum(a) || !is_fixnum(r) || !is_fixnum(f) ||
        a < 0 || r < fixnum_of_int(2) || f < 0 ||
        a >= r || r > fixnum_of_int(36) ||
        f > fixnum_of_int(255)) return onevalue(nil);
    a = int_of_fixnum(a);
    if (a <= 9) a = a + '0';
    else a = a + ('A' - 10);
    return onevalue(pack_char(int_of_fixnum(f) & 0x7, a & 0xff));
}

static LispObject Ldigit_char_2(LispObject nil, LispObject a,
                                LispObject r1)
{   return Ldigit_char_n(nil, 3, a, r1, fixnum_of_int(0));
}

static LispObject Ldigit_char_1(LispObject nil, LispObject a)
{   return Ldigit_char_n(nil, 3, a, fixnum_of_int(10), fixnum_of_int(0));
}


#endif

LispObject Lspecial_char(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror("special-char");
    switch (int_of_fixnum(a))
    {   case 0:   // space
            a = pack_char(0, ' ');
            break;
        case 1:   // newline
            a = pack_char(0, '\n');
            break;
        case 2:   // backspace
            a = pack_char(0, '\b');
            break;
        case 3:   // tab
            a = pack_char(0, '\t');
            break;
        case 4:   // linefeed (well, I use VT, '\v' in C terms)
            a = pack_char(0, '\v');
            break;
        case 5:   // page
            a = pack_char(0, '\f');
            break;
        case 6:   // return
            a = pack_char(0, '\r');
            break;
        case 7:   // rubout
            a = pack_char(0, 0x7fL);
            break;
        case 8:   // end of file character
            a = pack_char(0, 0x001fffff);
            break;
        case 9:   // 'attention', typically ctrl-G
            a = pack_char(0, '\a');
            break;
        case 10:  // 'ESC'
            a = pack_char(0, 0x1b);
            break;
        default:
            return aerror("special-char");
    }
//
// What about this and Standard Lisp mode???  Well it still hands back
// a "character object", and these are generally not at all useful in
// Standard Lisp.  Two exceptions occur - first character objects are
// valid in lists handed to compress, and secondly the character object
// for end-of-file is used for that in Standard Lisp mode. Well no - I am
// now moving to use a symbol for end-of-file...
//
    return onevalue(a);
}

//
// Given an integer this returns a list of bytes that are the utf-8 encoding
// for that value.
//
LispObject Lutf8_encode(LispObject nil, LispObject a)
{   int c;
    if (!is_fixnum(a)) return aerror1("utf8-encode", a);
    c = int_of_fixnum(a) & 0x001fffff;
    if (c <= 0x7f) return onevalue(ncons(fixnum_of_int(c)));
    else if (c <= 0x7ff) return onevalue(
                                        list2(fixnum_of_int(0xc0 | (c>>6)), fixnum_of_int(0x80 | (c & 0x3f))));
    else if (c <= 0xffff) return onevalue(
                                         list3(fixnum_of_int(0xe0 | (c>>12)),
                                               fixnum_of_int(0x80 | ((c>>6) & 0x3f)),
                                               fixnum_of_int(0x80 | (c & 0x3f))));
    else return onevalue(
                        list4(fixnum_of_int(0xf0 | (c>>18)),
                              fixnum_of_int(0x80 | ((c>>12) & 0x3f)),
                              fixnum_of_int(0x80 | ((c>>6) & 0x3f)),
                              fixnum_of_int(0x80 | (c & 0x3f))));
}

//
// Given four unsigned byte values this should reconstruct the value
// indicated by the utf-8 sequence ofthem.
//
static LispObject utf8_decode(int c1, int c2, int c3, int c4)
{   int32_t n;
    switch (c1 & 0xf0)
{       default:
            if ((c2&0x80)==0) return aerror("utf8-decode");
            return onevalue(fixnum_of_int(c1));
        case 0x80:
        case 0x90:
        case 0xa0:
        case 0xb0:
            return aerror("utf8-decode");
        case 0xc0:
        case 0xd0:
            if ((c2&0x80)==0) return aerror("utf8-decode");
            return onevalue(fixnum_of_int(((c1 & 0x1f)<<6) |
                                          (c2 & 0x3f)));
        case 0xe0:
            if ((c2&0x80)==0 || (c3&0x80)==0) return aerror("utf8-decode");
            return onevalue(fixnum_of_int(((c1 & 0x0f)<<12) |
                                          ((c2 & 0x3f)<<6) |
                                          (c3 & 0x3f)));
        case 0xf0:
            if ((c1 & 0x08) != 0 || (c2&0x80)==0 || (c3&0x80)==0 || (c4&0x80)==0)
                return aerror("utf8-decode");
            n = ((c1 & 0x07)<<18) |
                ((c2 & 0x3f)<<12) |
                ((c3 & 0x3f)<<6) |
                (c4 & 0x3f);
            if (n == 0x001fffff) n = -1; // special for EOF
            return onevalue(fixnum_of_int(n));
    }
}

LispObject Lutf8_decoden(LispObject nil, int nargs, ...)
{   LispObject a, b, c, d;
    va_list aa;
    if (nargs != 3 && nargs != 4) return aerror("utf8-decode");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    if (nargs == 4) d = va_arg(aa, LispObject);
    else d = fixnum_of_int(0);
    va_end(aa);
    if (!is_fixnum(a)) return aerror1("utf8-decode", a);
    if (!is_fixnum(b)) return aerror1("utf8-decode", b);
    if (!is_fixnum(c)) return aerror1("utf8-decode", c);
    if (!is_fixnum(d)) return aerror1("utf8-decode", d);
    return utf8_decode(int_of_fixnum(a) & 0xff,
                       int_of_fixnum(b) & 0xff,
                       int_of_fixnum(c) & 0xff,
                       nargs == 4 ? int_of_fixnum(d) & 0xff : -1);
}

LispObject Lutf8_decode2(LispObject nil, LispObject a, LispObject b)
{   if (!is_fixnum(a)) return aerror1("utf8-decode", a);
    if (!is_fixnum(b)) return aerror1("utf8-decode", b);
    return utf8_decode(int_of_fixnum(a) & 0xff, int_of_fixnum(b) & 0xff,
                       -1, -1);
}

LispObject Lutf8_decode1(LispObject nil, LispObject a)
{   if (car_legal(a))  // I allow for a list of ints too
    {   LispObject b=qcdr(a);
        a = qcar(a);
        if (car_legal(b))
        {   LispObject c = qcdr(b);
            b = qcar(b);
            if (car_legal(c))
            {   LispObject d = qcdr(c);
                c = qcar(c);
                if (car_legal(d))
                {   if (car_legal(qcdr(d)))
                        return aerror1("utf8-decode", qcdr(d));
                    else return Lutf8_decoden(nil, 4, a, b, c, qcar(d));
                }
                else return Lutf8_decoden(nil, 3, a, b, c);
            }
            else return Lutf8_decode2(nil, a, b);
        }
        else return Lutf8_decode1(nil, a);
    }
    if (!is_fixnum(a)) return aerror1("utf8-decode", a);
    return utf8_decode(int_of_fixnum(a) & 0xff, -1, -1, -1);
}

LispObject Lchar_code(LispObject, LispObject a)
{   a = characterify(a);
    if (!is_char(a)) return aerror("char-code");
//
// Note the special treatment of EOF here, and that characterify accepts
// integers, symbols and strings and disentangled UTF-8 encoding to return
// something that encapsulated the codepoint that is wanted.
//
    if (a == CHAR_EOF) return onevalue(fixnum_of_int(-1));
    return onevalue(fixnum_of_int(code_of_char(a)));
}

static LispObject Lcode_charn(LispObject, int nargs, ...)
{   va_list aa;
    LispObject a, font;
    int32_t av;
    argcheck(nargs, 3, "code-char");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    (void)va_arg(aa, LispObject);
    font = va_arg(aa, LispObject);
    va_end(aa);
    if ((int32_t)font < 0 || (int32_t)font > (int32_t)fixnum_of_int(7) ||
        (int32_t)a < 0 || (int32_t)a > (int32_t)fixnum_of_int(0x001fffff))
        return aerror("code-char");
    av = int_of_fixnum(a) & 0x001fffff;
#ifdef COMMON
    return onevalue(pack_char(int_of_fixnum(font) & 0x7, av));
#else
    return char_to_id(av);
#endif
}

static LispObject Lcode_char1(LispObject nil, LispObject a)
{   return Lcode_charn(nil, 3, a, fixnum_of_int(0), fixnum_of_int(0));
}

static LispObject Lcode_char2(LispObject nil, LispObject a, LispObject b)
{   return Lcode_charn(nil, 3, a, b, fixnum_of_int(0));
}

#ifdef COMMON

static LispObject Lchar_int(LispObject, LispObject a)
{   a = characterify(a);
    if (!is_char(a)) return aerror("char-int");
    else if (a == CHAR_EOF) return onevalue(fixnum_of_int(-1));
    else return onevalue(fixnum_of_int(code_of_char(a)));
}

static LispObject Lint_char(LispObject nil, LispObject a)
{   int32_t n;
    if (!is_fixnum(a)) return nil;
    n = int_of_fixnum(a);
    if (n == -1) n = 0x001fffff;
    return onevalue(pack_char(0, n));
}

static LispObject Lmake_char(LispObject, int nargs, ...)
{   va_list aa;
    LispObject a, bits, font;
    if (nargs == 0 || nargs > 3) return aerror("make-char");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    if (nargs > 1) bits = va_arg(aa, LispObject);
    else bits = fixnum_of_int(0);
    if (nargs > 2) font = va_arg(aa, LispObject);
    else font = fixnum_of_int(0);
    va_end(aa);
    a = characterify(a);
    if (font < 0 || font > fixnum_of_int(3L) ||
        !is_char(a)) return aerror("make-char");
    return onevalue(pack_char(int_of_fixnum(font) & 0x3,
                              code_of_char(a)));
}

//
// Character comparisons are VERY like the arithmetic ones, but need
// only deal with character objects, which are immediate data and
// in general terms nicer.
//

static bool chartest(LispObject c)
{   if (!is_char(c))
    {   aerror1("Character object expected", c);
        return true;
    }
    else return false;
}

static LispObject Lchar_eqn(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (chartest(r))
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        if (chartest(s))
        {   va_end(a);
            return nil;
        }
        if (r != s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lchar_eqn_2(LispObject nil, LispObject a, LispObject b)
{   return Lchar_eqn(nil, 2, a, b);
}

static LispObject Lchar_eqn_1(LispObject nil, LispObject a)
{   return Lchar_eqn(nil, 1, a);
}

static LispObject Lchar_lessp(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (chartest(r))
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        if (chartest(s))
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r >= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lchar_lessp_2(LispObject nil, LispObject a, LispObject b)
{   return Lchar_lessp(nil, 2, a, b);
}

static LispObject Lchar_lessp_1(LispObject nil, LispObject a)
{   return Lchar_lessp(nil, 1, a);
}

static LispObject Lchar_greaterp(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (chartest(r))
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        if (chartest(s))
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r <= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lchar_greaterp_2(LispObject nil, LispObject a, LispObject b)
{   return Lchar_greaterp(nil, 2, a, b);
}

static LispObject Lchar_greaterp_1(LispObject nil, LispObject a)
{   return Lchar_greaterp(nil, 1, a);
}

static LispObject Lchar_neq_n(LispObject nil, int nargs, ...)
//
// /= is supposed to check that NO pair of args match.
// Because this involves multiple scanning of the vector of args it seems
// necessary to copy the args into a vector that I can scan more directly
// than va_args lets me scan the arg list.
//
{   int i, j;
    va_list a;
    LispObject *r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    r = (LispObject *)&work_1;
    va_start(a, nargs);
    for (i=0; i<nargs; i++) r[i] = va_arg(a, LispObject);
    va_end(a);
    if (chartest(r[0])) return nil;
    for (i = 1; i<nargs; i++)
    {   LispObject n1 = r[i];
        if (chartest(n1)) return nil;
        for (j=0; j<i; j++)
        {   LispObject n2 = r[j];
            if (n1 == n2) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Lchar_neq_2(LispObject nil, LispObject a, LispObject b)
{   return Lchar_neq_n(nil, 2, a, b);
}

static LispObject Lchar_neq_1(LispObject nil, LispObject a)
{   return Lchar_neq_n(nil, 1, a);
}

static LispObject Lchar_geq(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (chartest(r))
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        if (chartest(s))
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r < (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lchar_geq_2(LispObject nil, LispObject a, LispObject b)
{   return Lchar_geq(nil, 2, a, b);
}

static LispObject Lchar_geq_1(LispObject nil, LispObject a)
{   return Lchar_geq(nil, 1, a);
}

static LispObject Lchar_leq(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (chartest(r))
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        if (chartest(s))
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r > (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lchar_leq_2(LispObject nil, LispObject a, LispObject b)
{   return Lchar_leq(nil, 2, a, b);
}

static LispObject Lchar_leq_1(LispObject nil, LispObject a)
{   return Lchar_leq(nil, 1, a);
}


//
// Character comparisons are VERY like the arithmetic ones, but need
// only deal with character objects, which are immediate data and
// in general terms nicer.  These versions look only at the code, not
// at the case or the bits attributes.
//

static LispObject casefold(LispObject c)
{   int cc;
    if (!is_char(c)) return aerror("Character object expected");
    if (c == CHAR_EOF) return onevalue(c);

    cc = code_of_char(c);   // Character in the C sense
    if (cc <= 0xffff || sizeof(wchar_t)== 4) cc = towupper(cc);
    return onevalue(pack_char(font_of_char(c), cc));
}

static LispObject Lcharacter_eqn(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending())
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending())
        {   va_end(a);
            return nil;
        }
        if (r != s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_eqn_2(LispObject nil, LispObject a, LispObject b)
{   return Lcharacter_eqn(nil, 2, a, b);
}

static LispObject Lcharacter_eqn_1(LispObject nil, LispObject a)
{   return Lcharacter_eqn(nil, 1, a);
}

static LispObject Lcharacter_lessp(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending())
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending())
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r >= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_lessp_2(LispObject nil, LispObject a, LispObject b)
{   return Lcharacter_lessp(nil, 2, a, b);
}

static LispObject Lcharacter_lessp_1(LispObject nil, LispObject a)
{   return Lcharacter_lessp(nil, 1, a);
}

static LispObject Lcharacter_greaterp(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending())
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending())
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r <= (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_greaterp_2(LispObject nil, LispObject a, LispObject b)
{   return Lcharacter_greaterp(nil, 2, a, b);
}

static LispObject Lcharacter_greaterp_1(LispObject nil, LispObject a)
{   return Lcharacter_greaterp(nil, 1, a);
}

static LispObject Lcharacter_neq_n(LispObject nil, int nargs, ...)
//
// /= is supposed to check that NO pair of args match.
// Because this involves multiple scanning of the vector of args it seems
// necessary to copy the args into a vector that I can scan more directly
// than va_args lets me scan the arg list.
//
{   int i, j;
    va_list a;
    LispObject *r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    r = (LispObject *)&work_1;
    va_start(a, nargs);
    for (i=0; i<nargs; i++) r[i] = va_arg(a, LispObject);
    va_end(a);
    if (chartest(r[0])) return nil;
    for (i = 1; i<nargs; i++)
    {   LispObject n1 = r[i];
        n1 = casefold(n1);
        errexit();
        for (j=0; j<i; j++)
        {   LispObject n2 = r[j];
            n2 = casefold(n2);  // can not fail - this arg tested earlier
            if (n1 == n2) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Lcharacter_neq_2(LispObject nil, LispObject a, LispObject b)
{   return Lcharacter_neq_n(nil, 2, a, b);
}

static LispObject Lcharacter_neq_1(LispObject nil, LispObject a)
{   return Lcharacter_neq_n(nil, 1, a);
}

static LispObject Lcharacter_geq(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending())
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending())
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r < (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_geq_2(LispObject nil, LispObject a, LispObject b)
{   return Lcharacter_geq(nil, 2, a, b);
}

static LispObject Lcharacter_geq_1(LispObject nil, LispObject a)
{   return Lcharacter_geq(nil, 1, a);
}

static LispObject Lcharacter_leq(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF)
        return aerror("too many args for character comparison");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    r = casefold(r);
    nil = C_nil;
    if (exception_pending())
    {   va_end(a);
        return nil;
    }
    for (i = 1; i<nargs; i++)
    {   LispObject s = va_arg(a, LispObject);
        s = casefold(s);
        nil = C_nil;
        if (exception_pending())
        {   va_end(a);
            return nil;
        }
        if ((uint32_t)r > (uint32_t)s)
        {   va_end(a);
            return onevalue(nil);
        }
        r = s;
    }
    va_end(a);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_leq_2(LispObject nil, LispObject a, LispObject b)
{   return Lcharacter_leq(nil, 2, a, b);
}

static LispObject Lcharacter_leq_1(LispObject nil, LispObject a)
{   return Lcharacter_leq(nil, 1, a);
}


//
// I will also put some versions of string comparisons here - the versions
// implemented this way will have no keyword args.
//


//
// get_char_vec(v, &high, &offset) is used in places where v is expected
// to be a string or symbol. It returns a simple vector, which the celt()
// macro can access, and sets high & offset. The string will then
// have characters with index 0 <= n < high, but to access them the offset
// value needs to be added. If the input is not a proper string then nil
// will be returned. THIS HAS NOT BEEN REVIEWED for issues of utf=8
// packing.
//

static LispObject get_char_vec(LispObject v, int32_t *high, int32_t *offset)
{   Header h;
    LispObject nil = C_nil, w;
    if (symbolp(v)) v = qpname(v);
    if (!is_vector(v)) return nil;
    h = vechdr(v);
    if (is_string_header(h))
    {   *high = length_of_byteheader(h) - 4; // @@@ /* 4 vs CELL
        *offset = 0;
        return v;
    }
    if (!is_vector(v)) return nil;
    h = vechdr(v);
    if (type_of_header(h) != TYPE_ARRAY) return nil;
    w = elt(v, 1);   // The list of dimensions
    if (w == nil || qcdr(w) != nil) return nil;
    *high = int_of_fixnum(qcar(w));
    *offset = int_of_fixnum(elt(v, 3));
    v = elt(v, 2);
    h = vechdr(v);
    if (!is_string_header(h)) return nil;
    else return v;
}

static LispObject Lstring_greaterp_2(LispObject nil,
                                     LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string>", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string>", b);
    b = w;
    for (i=0;; i++)
    {   if (i == lb)
        {   if (i == la) return onevalue(nil);
            else return onevalue(fixnum_of_int(i));
        }
        else if (i == la) return onevalue(nil);
//
// String comparisons here go byte by byte. I believe that this is
// actually OK despite utf-8 packing.
//
        ca = ucelt(a, i+oa);
        cb = ucelt(b, i+ob);
        if (ca == cb) continue;
        if (ca > cb) return onevalue(fixnum_of_int(i));
        else return onevalue(nil);
    }
}

static LispObject Lstring_lessp_2(LispObject nil,
                                  LispObject a, LispObject b)
{   return Lstring_greaterp_2(nil, b, a);
}

static LispObject Lstring_not_equal_2(LispObject nil,
                                      LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string/=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string/=", b);
    b = w;
    for (i=0;; i++)
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

static LispObject Lstring_equal_2(LispObject nil,
                                  LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string=", b);
    b = w;
    for (i=0;; i++)
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

static LispObject Lstring_not_greaterp_2(LispObject nil,
        LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string<=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string<=", b);
    b = w;
    for (i=0;; i++)
    {   if (i == la) return onevalue(fixnum_of_int(i));
        else if (i == lb) return onevalue(nil);
        ca = ucelt(a, i+oa);
        cb = ucelt(b, i+ob);
        if (ca == cb) continue;
        if (ca < cb) return onevalue(fixnum_of_int(i));
        else return onevalue(nil);
    }
}

static LispObject Lstring_not_lessp_2(LispObject nil,
                                      LispObject a, LispObject b)
{   return Lstring_not_greaterp_2(nil, b, a);
}

static LispObject L_string_greaterp_2(LispObject nil,
                                      LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string>", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string>", b);
    b = w;
    for (i=0;; i++)
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

static LispObject L_string_lessp_2(LispObject nil,
                                   LispObject a, LispObject b)
{   return L_string_greaterp_2(nil, b, a);
}

static LispObject L_string_not_equal_2(LispObject nil,
                                       LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string/=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string/=", b);
    b = w;
    for (i=0;; i++)
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

static LispObject L_string_equal_2(LispObject nil,
                                   LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string=", b);
    b = w;
    for (i=0;; i++)
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

static LispObject L_string_not_greaterp_2(LispObject nil,
        LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) return aerror1("string<=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) return aerror1("string<=", b);
    b = w;
    for (i=0;; i++)
    {   if (i == la) return onevalue(fixnum_of_int(i));
        else if (i == lb) return onevalue(nil);
        ca = toupper(celt(a, i+oa));
        cb = toupper(celt(b, i+ob));
        if (ca == cb) continue;
        if (ca < cb) return onevalue(fixnum_of_int(i));
        else return onevalue(nil);
    }
}

static LispObject L_string_not_lessp_2(LispObject nil,
                                       LispObject a, LispObject b)
{   return L_string_not_greaterp_2(nil, b, a);
}

#endif

setup_type const char_setup[] =
{   {"char-code",               Lchar_code, too_many_1, wrong_no_1},
    {"char-downcase",           Lchar_downcase, too_many_1, wrong_no_1},
    {"char-upcase",             Lchar_upcase, too_many_1, wrong_no_1},
    {"code-char",               Lcode_char1, Lcode_char2, Lcode_charn},
    {"digit",                   Ldigitp, too_many_1, wrong_no_1},
    {"special-char",            Lspecial_char, too_many_1, wrong_no_1},
    {"utf8-encode",             Lutf8_encode, too_many_1, wrong_no_1},
    {"utf8-decode",             Lutf8_decode1, Lutf8_decode2, Lutf8_decoden},
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

// end of char.cpp
