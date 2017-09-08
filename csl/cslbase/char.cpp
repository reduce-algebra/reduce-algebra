//  char.cpp                               Copyright (C) 1989-2017 Codemist    

//
// Character handling.
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
{   LispObject w;
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
    if (!is_char(a)) aerror("char-downcase");
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

LispObject Lcharacter(LispObject env, LispObject a)
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
            return onevalue(w);
        }
        else aerror1("character", a);
    }
    else if (is_fixnum(a))
        return onevalue(pack_char(0, int_of_fixnum(a) & 0x001fffff));
    else if (is_symbol(a)) return onevalue(characterify_string(qpname(a)));
    else aerror1("character", a);
}

static LispObject Lcharacterp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(is_char(a)));
}

static LispObject Lchar_bits(LispObject, LispObject a)
{
// "bits" are no longer supported (or needed).
    a = characterify(a);
    if (!is_char(a)) aerror("char-bits");
    return onevalue(fixnum_of_int(0));
}

static LispObject Lchar_font(LispObject, LispObject a)
{
// "font" is no longer really sensible, but I will (for now) allow
// people to pack 3 bits of information in with a character, and I will
// hope that they never do.
    a = characterify(a);
    if (!is_char(a)) aerror("char-font");
    return onevalue(fixnum_of_int(font_of_char(a)));
}

static LispObject Lchar_upcase(LispObject, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) aerror("char-upcase");
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

LispObject Lwhitespace_char_p(LispObject env, LispObject a)
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

LispObject Lalpha_char_p(LispObject env, LispObject a)
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

static LispObject Lgraphic_char_p(LispObject env, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
// What is goin on here is that I am expecting the if sizeof(wchar_t) is 4
// (ie I have 32-bit wide characters) then the iswgraph() test is generally
// valid. If sizeof(wchar_t) is only 2 then I should only try to use it
// on codepoints up to U+FFFF, and I am going to declare that all codepoints
// above that will record as "not graphics chatacters".
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
    {   if (iswgraph(cc) || cc==' ') return onevalue(lisp_true);
    }
    return onevalue(nil);
}

static LispObject Lupper_case_p(LispObject env, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc <= 0xffff || sizeof(wchar_t) == 4)
    {   if (iswupper(cc)) return onevalue(lisp_true);
        else return onevalue(nil);
    }
    return onevalue(nil);
}

static LispObject Llower_case_p(LispObject env, LispObject a)
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


LispObject Ldigit_char_p_2(LispObject env, LispObject a, LispObject radix)
{   int cc;
    LispObject r = radix;
    if (!is_fixnum(r) || r < fixnum_of_int(2) ||
        r >= fixnum_of_int(36)) aerror1("digit-char-p", r);
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

LispObject Ldigit_char_p_1(LispObject env, LispObject a)
{   return Ldigit_char_p_2(nil, a, fixnum_of_int(10));
}

LispObject Ldigitp(LispObject env, LispObject a)
{   int cc;
    a = characterify(a);
    if (!is_char(a)) return onevalue(nil);
    if (a == CHAR_EOF) return onevalue(nil);
    cc = code_of_char(a);
    if (cc > 0xffff && sizeof(wchar_t) < 4) return onevalue(nil);
    return onevalue(Lispify_predicate(iswdigit(cc)));
}

static LispObject Ldigit_char_3(LispObject env, LispObject a,
        LispObject r, LispObject f)
{   if (!is_fixnum(a) || !is_fixnum(r) || !is_fixnum(f) ||
        a < 0 || r < fixnum_of_int(2) || f < 0 ||
        a >= r || r > fixnum_of_int(36) ||
        f > fixnum_of_int(255)) return onevalue(nil);
    a = int_of_fixnum(a);
    if (a <= 9) a = a + '0';
    else a = a + ('A' - 10);
    return onevalue(pack_char(int_of_fixnum(f) & 0x7, a & 0xff));
}

static LispObject Ldigit_char_2(LispObject env, LispObject a,
                                LispObject r1)
{   return Ldigit_char_3(nil, a, r1, fixnum_of_int(0));
}

static LispObject Ldigit_char_1(LispObject env, LispObject a)
{   return Ldigit_char_3(nil, a, fixnum_of_int(10), fixnum_of_int(0));
}

LispObject Lspecial_char(LispObject, LispObject a)
{   if (!is_fixnum(a)) aerror("special-char");
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
            aerror("special-char");
    }
//
// What about this and Standard Lisp mode?  Well it still hands back
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
LispObject Lutf8_encode(LispObject env, LispObject a)
{   int c;
    if (!is_fixnum(a)) aerror1("utf8-encode", a);
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
    {   default:
            if ((c2&0x80)==0) aerror("utf8-decode");
            return onevalue(fixnum_of_int(c1));
        case 0x80:
        case 0x90:
        case 0xa0:
        case 0xb0:
            aerror("utf8-decode");
        case 0xc0:
        case 0xd0:
            if ((c2&0x80)==0) aerror("utf8-decode");
            return onevalue(fixnum_of_int(((c1 & 0x1f)<<6) |
                                          (c2 & 0x3f)));
        case 0xe0:
            if ((c2&0x80)==0 || (c3&0x80)==0) aerror("utf8-decode");
            return onevalue(fixnum_of_int(((c1 & 0x0f)<<12) |
                                          ((c2 & 0x3f)<<6) |
                                          (c3 & 0x3f)));
        case 0xf0:
            if ((c1 & 0x08) != 0 || (c2&0x80)==0 || (c3&0x80)==0 || (c4&0x80)==0)
                aerror("utf8-decode");
            n = ((c1 & 0x07)<<18) |
                ((c2 & 0x3f)<<12) |
                ((c3 & 0x3f)<<6) |
                (c4 & 0x3f);
            if (n == 0x001fffff) n = -1; // special for EOF
            return onevalue(fixnum_of_int(n));
    }
}

LispObject Lutf8_decode_4up(LispObject env, LispObject a, LispObject b,
        LispObject c, LispObject d)
{   if (qcdr(d) != nil) aerror("utf8-decode");
    d = qcar(d);
    if (!is_fixnum(a)) aerror1("utf8-decode", a);
    if (!is_fixnum(b)) aerror1("utf8-decode", b);
    if (!is_fixnum(c)) aerror1("utf8-decode", c);
    if (!is_fixnum(d)) aerror1("utf8-decode", d);
    return utf8_decode(int_of_fixnum(a) & 0xff,
                       int_of_fixnum(b) & 0xff,
                       int_of_fixnum(c) & 0xff,
                       int_of_fixnum(d) & 0xff);
}

LispObject Lutf8_decode_3(LispObject env, LispObject a, LispObject b, LispObject c)
{   if (!is_fixnum(a)) aerror1("utf8-decode", a);
    if (!is_fixnum(b)) aerror1("utf8-decode", b);
    if (!is_fixnum(c)) aerror1("utf8-decode", c);
    return utf8_decode(int_of_fixnum(a) & 0xff, int_of_fixnum(b) & 0xff,
                       int_of_fixnum(c) & 0xff, -1);
}

LispObject Lutf8_decode_2(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a)) aerror1("utf8-decode", a);
    if (!is_fixnum(b)) aerror1("utf8-decode", b);
    return utf8_decode(int_of_fixnum(a) & 0xff, int_of_fixnum(b) & 0xff,
                       -1, -1);
}

LispObject Lutf8_decode_1(LispObject env, LispObject a)
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
                        aerror1("utf8-decode", qcdr(d));
                    else return Lutf8_decode_4up(nil, a, b, c, d);
                }
                else return Lutf8_decode_3(nil, a, b, c);
            }
            else return Lutf8_decode_2(nil, a, b);
        }
        else return Lutf8_decode_1(nil, a);
    }
    if (!is_fixnum(a)) aerror1("utf8-decode", a);
    return utf8_decode(int_of_fixnum(a) & 0xff, -1, -1, -1);
}

LispObject Lchar_code(LispObject, LispObject a)
{   a = characterify(a);
    if (!is_char(a)) aerror("char-code");
//
// Note the special treatment of EOF here, and that characterify accepts
// integers, symbols and strings and disentangled UTF-8 encoding to return
// something that encapsulated the codepoint that is wanted.
//
    if (a == CHAR_EOF) return onevalue(fixnum_of_int(-1));
    return onevalue(fixnum_of_int(code_of_char(a)));
}

static LispObject Lcode_char_3(LispObject, LispObject code, LispObject bits,
        LispObject font )
{   if ((intptr_t)font < 0 || (intptr_t)font > (intptr_t)fixnum_of_int(7) ||
        (intptr_t)code < 0 || (intptr_t)code > (intptr_t)fixnum_of_int(0x001fffff))
        aerror("code-char");
    uintptr_t icode = int_of_fixnum(code) & 0x001fffff;
#ifdef COMMON
    return onevalue(pack_char(int_of_fixnum(font) & 0x7, icode));
#else
    return char_to_id(icode);
#endif
}

static LispObject Lcode_char_1(LispObject env, LispObject a)
{   return Lcode_char_3(nil, a, fixnum_of_int(0), fixnum_of_int(0));
}

static LispObject Lcode_char_2(LispObject env, LispObject a, LispObject b)
{   return Lcode_char_3(nil, a, b, fixnum_of_int(0));
}

static LispObject Lchar_int(LispObject, LispObject a)
{   a = characterify(a);
    if (!is_char(a)) aerror("char-int");
    else if (a == CHAR_EOF) return onevalue(fixnum_of_int(-1));
    else return onevalue(fixnum_of_int(code_of_char(a)));
}

static LispObject Lint_char(LispObject env, LispObject a)
{   intptr_t n;
    if (!is_fixnum(a)) return nil;
    n = int_of_fixnum(a);
    if (n == -1) n = 0x001fffff;
    return onevalue(pack_char(0, n));
}

static LispObject Lmake_char_3(LispObject, LispObject a,
        LispObject bits, LispObject font)
{   a = characterify(a);
// bits are ignores these days. They represented an attempt by Common Lisp
// to put extra information into character objects that has not really
// survived very well.
    if ((intptr_t)font < 0 || (intptr_t)font > fixnum_of_int(3L) ||
        !is_char(a)) aerror("make-char");
    return onevalue(pack_char(int_of_fixnum(font) & 0x3,
                              code_of_char(a)));
}

static LispObject Lmake_char_2(LispObject, LispObject a, LispObject bits)
{   return Lmake_char_3(nil, a, bits, fixnum_of_int(0));
}

static LispObject Lmake_char_1(LispObject, LispObject a)
{   return Lmake_char_3(nil, a, fixnum_of_int(0), fixnum_of_int(0));
}

//
// Character comparisons are VERY like the arithmetic ones, but need
// only deal with character objects, which are immediate data and
// in general terms nicer.
//

static void chartest(LispObject c)
{   if (!is_char(c)) aerror1("Character object expected", c);
}

static LispObject Lchar_eqn_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    if (a1 != a2) return onevalue(nil);
    chartest(a3);
    if (a2 != a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        if (a3 != a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lchar_eqn_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    if (a1 != a2) return onevalue(nil);
    chartest(a3);
    if (a2 != a3) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_eqn_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    if (a1 != a2) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_eqn_1(LispObject env, LispObject a)
{   return onevalue(lisp_true);
}

static LispObject Lchar_eqn_0(LispObject env)
{   return onevalue(lisp_true);
}

static LispObject Lchar_lessp_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    if (a1 >= a2) return onevalue(nil);
    chartest(a3);
    if (a2 >= a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        if (a3 >= a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lchar_lessp_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    if (a1 >= a2) return onevalue(nil);
    chartest(a3);
    if (a2 >= a3) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_lessp_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    if (a1 >= a2) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_lessp_1(LispObject env, LispObject a)
{   return onevalue(lisp_true);
}

static LispObject Lchar_lessp_0(LispObject env)
{   return onevalue(lisp_true);
}


static LispObject Lchar_greaterp_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    if (a1 <= a2) return onevalue(nil);
    chartest(a3);
    if (a2 <= a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        if (a3 <= a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lchar_greaterp_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    if (a1 <= a2) return onevalue(nil);
    chartest(a3);
    if (a2 <= a3) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_greaterp_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    if (a1 <= a2) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_greaterp_1(LispObject env, LispObject a)
{   return onevalue(lisp_true);
}

static LispObject Lchar_greaterp_0(LispObject env)
{   return onevalue(lisp_true);
}


static LispObject Lchar_neq_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    if (a1 == a2) return onevalue(nil);
    chartest(a3);
    if (a1 == a3 || a2 == a3) return onevalue(nil);
    while (a4up != nil)
    {   LispObject a4 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a4);
        if (a1 == a4 || a2 == a4 || a3 == a4) return onevalue(nil);
        for (LispObject a5up=a4up; a5up!=nil; a5up=qcdr(a5up))
        {   LispObject a5 = qcar(a5up);
            a5up = qcdr(a5up);
            chartest(a5);
            if (a4 == a5) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Lchar_neq_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    if (a1 == a2) return onevalue(nil);
    chartest(a3);
    if (a2 == a3) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_neq_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    if (a1 == a2) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_neq_1(LispObject env, LispObject a)
{   return onevalue(lisp_true);
}

static LispObject Lchar_neq_0(LispObject env)
{   return onevalue(lisp_true);
}


static LispObject Lchar_geq_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    if (a1 < a2) return onevalue(nil);
    chartest(a3);
    if (a2 < a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        if (a3 < a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lchar_geq_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    if (a1 < a2) return onevalue(nil);
    chartest(a3);
    if (a2 < a3) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_geq_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    if (a1 < a2) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_geq_1(LispObject env, LispObject a)
{   return onevalue(lisp_true);
}

static LispObject Lchar_geq_0(LispObject env)
{   return onevalue(lisp_true);
}


static LispObject Lchar_leq_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    if (a1 > a2) return onevalue(nil);
    chartest(a3);
    if (a2 > a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        if (a3 > a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lchar_leq_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    if (a1 > a2) return onevalue(nil);
    chartest(a3);
    if (a2 > a3) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_leq_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    if (a1 > a2) return onevalue(nil);
    return onevalue(lisp_true);
}

static LispObject Lchar_leq_1(LispObject env, LispObject a)
{   return onevalue(lisp_true);
}

static LispObject Lchar_leq_0(LispObject env)
{   return onevalue(lisp_true);
}


//
// Character comparisons are VERY like the arithmetic ones, but need
// only deal with character objects, which are immediate data and
// in general terms nicer.  These versions look only at the code, not
// at the case or the bits attributes.
//

static LispObject casefold(LispObject c)
{   int cc;
    if (!is_char(c)) aerror("Character object expected");
    if (c == CHAR_EOF) return onevalue(c);

    cc = code_of_char(c);   // Character in the C sense
    if (cc <= 0xffff || sizeof(wchar_t)== 4) cc = towupper(cc);
    return onevalue(pack_char(font_of_char(c), cc));
}

static LispObject Lcharacter_eqn_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 != a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    if (a2 != a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        a1 = casefold(a1);
        if (a3 != a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lcharacter_eqn_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 != a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    return onevalue(Lispify_predicate(a2 == a3));
}

static LispObject Lcharacter_eqn_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    return onevalue(Lispify_predicate(a1 == a2));
}

static LispObject Lcharacter_eqn_1(LispObject env, LispObject a1)
{   chartest(a1);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_eqn_0(LispObject env)
{   return onevalue(lisp_true);
}

static LispObject Lcharacter_lessp_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 >= a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    if (a2 >= a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        a1 = casefold(a1);
        if (a3 >= a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lcharacter_lessp_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 >= a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    return onevalue(Lispify_predicate(a2 < a3));
}

static LispObject Lcharacter_lessp_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    return onevalue(Lispify_predicate(a1 < a2));
}

static LispObject Lcharacter_lessp_1(LispObject env, LispObject a1)
{   chartest(a1);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_lessp_0(LispObject env)
{   return onevalue(lisp_true);
}


static LispObject Lcharacter_greaterp_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 <= a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    if (a2 <= a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        a1 = casefold(a1);
        if (a3 <= a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lcharacter_greaterp_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 <= a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    return onevalue(Lispify_predicate(a2 > a3));
}

static LispObject Lcharacter_greaterp_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    return onevalue(Lispify_predicate(a1 > a2));
}

static LispObject Lcharacter_greaterp_1(LispObject env, LispObject a1)
{   chartest(a1);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_greaterp_0(LispObject env)
{   return onevalue(lisp_true);
}

static LispObject Lcharacter_neq_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 == a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    if (a1 == a3 || a2 == a3) return onevalue(nil);
    while (a4up != nil)
    {   LispObject a4 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a4);
        a4 = casefold(a4);
        if (a1 == a4 || a2 == a4 || a3 == a4) return onevalue(nil);
        for (LispObject a5up=a4up; a5up!=nil; a5up=qcdr(a5up))
        {   LispObject a5 = qcar(a5up);
            a5up = qcdr(a5up);
            chartest(a5);
            a5 = casefold(a5);
            if (a4 == a5) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Lcharacter_neq_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 == a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    return onevalue(Lispify_predicate(a2 != a3));
}

static LispObject Lcharacter_neq_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    return onevalue(Lispify_predicate(a1 != a2));
}

static LispObject Lcharacter_neq_1(LispObject env, LispObject a1)
{   chartest(a1);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_neq_0(LispObject env)
{   return onevalue(lisp_true);
}

static LispObject Lcharacter_geq_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 < a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    if (a2 < a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        a1 = casefold(a1);
        if (a3 < a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lcharacter_geq_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 < a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    return onevalue(Lispify_predicate(a2 >= a3));
}

static LispObject Lcharacter_geq_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    return onevalue(Lispify_predicate(a1 >= a2));
}

static LispObject Lcharacter_geq_1(LispObject env, LispObject a1)
{   chartest(a1);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_geq_0(LispObject env)
{   return onevalue(lisp_true);
}

static LispObject Lcharacter_leq_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 > a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    if (a2 > a3) return onevalue(nil);
    while (a4up != nil)
    {   a1 = qcar(a4up);
        a4up = qcdr(a4up);
        chartest(a1);
        a1 = casefold(a1);
        if (a3 > a1) return onevalue(nil);
        a3 = a1;
    }
    return onevalue(lisp_true);
}

static LispObject Lcharacter_leq_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    if (a1 > a2) return onevalue(nil);
    chartest(a3);
    a3 = casefold(a3);
    return onevalue(Lispify_predicate(a2 <= a3));
}

static LispObject Lcharacter_leq_2(LispObject env, LispObject a1, LispObject a2)
{   chartest(a1);
    chartest(a2);
    a1 = casefold(a1);
    a2 = casefold(a2);
    return onevalue(Lispify_predicate(a1 <= a2));
}

static LispObject Lcharacter_leq_1(LispObject env, LispObject a1)
{   chartest(a1);
    return onevalue(lisp_true);
}

static LispObject Lcharacter_leq_0(LispObject env)
{   return onevalue(lisp_true);
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
    LispObject w;
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

static LispObject Lstring_greaterp_2(LispObject env,
                                     LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string>", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string>", b);
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

static LispObject Lstring_lessp_2(LispObject env,
                                  LispObject a, LispObject b)
{   return Lstring_greaterp_2(nil, b, a);
}

static LispObject Lstring_not_equal_2(LispObject env,
                                      LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string/=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string/=", b);
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

static LispObject Lstring_equal_2(LispObject env, LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string=", b);
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

static LispObject Lstring_not_greaterp_2(LispObject env,
                                         LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string<=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string<=", b);
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

static LispObject Lstring_not_lessp_2(LispObject env,
                                      LispObject a, LispObject b)
{   return Lstring_not_greaterp_2(nil, b, a);
}

static LispObject L_string_greaterp_2(LispObject env,
                                      LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string>", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string>", b);
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

static LispObject L_string_lessp_2(LispObject env,
                                   LispObject a, LispObject b)
{   return L_string_greaterp_2(nil, b, a);
}

static LispObject L_string_not_equal_2(LispObject env,
                                       LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string/=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string/=", b);
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

static LispObject L_string_equal_2(LispObject env,
                                   LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string=", b);
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

static LispObject L_string_not_greaterp_2(LispObject env,
        LispObject a, LispObject b)
{   int32_t la, oa, lb, ob, i;
    int ca, cb;
    LispObject w;
    w = get_char_vec(a, &la, &oa);
    if (w == nil) aerror1("string<=", a);
    a = w;
    w = get_char_vec(b, &lb, &ob);
    if (w == nil) aerror1("string<=", b);
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

static LispObject L_string_not_lessp_2(LispObject env,
                                       LispObject a, LispObject b)
{   return L_string_not_greaterp_2(nil, b, a);
}


setup_type const char_setup[] =
{   {"char-code",               G0W1, Lchar_code, G2W1, G3W1, G4W1},
    {"char-downcase",           G0W1, Lchar_downcase, G2W1, G3W1, G4W1},
    {"char-upcase",             G0W1, Lchar_upcase, G2W1, G3W1, G4W1},
    {"code-char",               G0Wother, Lcode_char_1, Lcode_char_2, Lcode_char_3, G4Wother},
    {"digit",                   G0W1, Ldigitp, G2W1, G3W1, G4W1},
    {"liter",                   G0W1, Lalpha_char_p, G2W1, G3W1, G4W1},
    {"seprp",                   G0W1, Lwhitespace_char_p, G2W1, G3W1, G4W1},
    {"special-char",            G0W1, Lspecial_char, G2W1, G3W1, G4W1},
    {"utf8-encode",             G0W1, Lutf8_encode, G2W1, G3W1, G4W1},
    {"utf8-decode",             G0Wother, Lutf8_decode_1, Lutf8_decode_2, Lutf8_decode_3, Lutf8_decode_4up},
    {"alpha-char-p",            G0W1, Lalpha_char_p, G2W1, G3W1, G4W1},
    {"both-case-p",             G0W1, Lalpha_char_p, G2W1, G3W1, G4W1},
    {"char-bits",               G0W1, Lchar_bits, G2W1, G3W1, G4W1},
    {"char-equal",              Lcharacter_eqn_0, Lcharacter_eqn_1, Lcharacter_eqn_2, Lcharacter_eqn_3, Lcharacter_eqn_4up},
    {"char-font",               G0W1, Lchar_font, G2W1, G3W1, G4W1},
    {"char-greaterp",           Lcharacter_greaterp_0, Lcharacter_greaterp_1, Lcharacter_greaterp_2, Lcharacter_greaterp_3, Lcharacter_greaterp_4up},
    {"char-int",                G0W1, Lchar_int, G2W1, G3W1, G4W1},
    {"char-lessp",              Lcharacter_lessp_0, Lcharacter_lessp_1, Lcharacter_lessp_2, Lcharacter_lessp_3, Lcharacter_lessp_4up},
    {"char-not-equal",          Lcharacter_neq_0, Lcharacter_neq_1, Lcharacter_neq_2, Lcharacter_neq_3, Lcharacter_neq_4up},
    {"char-not-greaterp",       Lcharacter_leq_0, Lcharacter_leq_1, Lcharacter_leq_2, Lcharacter_leq_3, Lcharacter_leq_4up},
    {"char-not-lessp",          Lcharacter_geq_0, Lcharacter_geq_1, Lcharacter_geq_2, Lcharacter_geq_3, Lcharacter_geq_4up},
    {"char/=",                  Lchar_neq_0, Lchar_neq_1, Lchar_neq_2, Lchar_neq_3, Lchar_neq_4up},
    {"char<",                   Lchar_lessp_0, Lchar_lessp_1, Lchar_lessp_2, Lchar_lessp_3, Lchar_lessp_4up},
    {"char<=",                  Lchar_leq_0, Lchar_leq_1, Lchar_leq_2, Lchar_leq_3, Lchar_leq_4up},
    {"char=",                   Lchar_eqn_0, Lchar_eqn_1, Lchar_eqn_2, Lchar_eqn_3, Lchar_eqn_4up},
    {"char>",                   Lchar_greaterp_0, Lchar_greaterp_1, Lchar_greaterp_2, Lchar_greaterp_3, Lchar_greaterp_4up},
    {"char>=",                  Lchar_geq_0, Lchar_geq_1, Lchar_geq_2, Lchar_geq_3, Lchar_geq_4up},
    {"character",               G0W1, Lcharacter, G2W1, G3W1, G4W1},
    {"characterp",              G0W1, Lcharacterp, G2W1, G3W1, G4W1},
    {"digit-char",              G0Wother, Ldigit_char_1, Ldigit_char_2, Ldigit_char_3, G4Wother},
    {"digit-char-p",            G0Wother, Ldigit_char_p_1, Ldigit_char_p_2, G3Wother, G4Wother},
    {"graphic-char-p",          G0W1, Lgraphic_char_p, G2W1, G3W1, G4W1},
    {"int-char",                G0W1, Lint_char, G2W1, G3W1, G4W1},
    {"lower-case-p",            G0W1, Llower_case_p, G2W1, G3W1, G4W1},
    {"make-char",               G0Wother, Lmake_char_1, Lmake_char_2, Lmake_char_3, G4Wother},
    {"upper-case-p",            G0W1, Lupper_case_p, G2W1, G3W1, G4W1},
    {"whitespace-char-p",       G0W1, Lwhitespace_char_p, G2W1, G3W1, G4W1},
    {"string<2",                G0W2, G1W2, Lstring_lessp_2, G3W2, G4W2},
    {"string>2",                G0W2, G1W2, Lstring_greaterp_2, G3W2, G4W2},
    {"string=2",                G0W2, G1W2, Lstring_equal_2, G3W2, G4W2},
    {"string/=2",               G0W2, G1W2, Lstring_not_equal_2, G3W2, G4W2},
    {"string<=2",               G0W2, G1W2, Lstring_not_greaterp_2, G3W2, G4W2},
    {"string>=2",               G0W2, G1W2, Lstring_not_lessp_2, G3W2, G4W2},
    {"string-lessp2",           G0W2, G1W2, L_string_lessp_2, G3W2, G4W2},
    {"string-greaterp2",        G0W2, G1W2, L_string_greaterp_2, G3W2, G4W2},
    {"string-equal2",           G0W2, G1W2, L_string_equal_2, G3W2, G4W2},
    {"string-not-equal2",       G0W2, G1W2, L_string_not_equal_2, G3W2, G4W2},
    {"string-not-greaterp2",    G0W2, G1W2, L_string_not_greaterp_2, G3W2, G4W2},
    {"string-not-lessp2",       G0W2, G1W2, L_string_not_lessp_2, G3W2, G4W2},
    {NULL,                      0, 0, 0, 0, 0}
};

// end of char.cpp
