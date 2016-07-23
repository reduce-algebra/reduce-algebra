// unimaths.cpp                                 Copyright (C) 2015 Codemist    

// $Id$


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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "uninames.h"

// This code maps simple letters from the range A-Z and a-z onto Unicode
// codepoints corresponding to various "mathematical" styles. The converted
// values are all available in STIXGeneral-Regular so even Bold and Italic
// letters should be found there rather than in STIX_General-Bold etc.

// I have a range of "styles" here, and present one of them plus a simple
// Basic Latin code, and I get back a Unicode code-point. Note that this
// will NOT support use of characters othger than [A-Za-z0-9] in any
// clean manner.

#define MATH_REGULAR                        0
#define MATH_BOLD                           1
#define MATH_ITALIC                         2
#define MATH_BOLD_ITALIC                    3
#define MATH_SCRIPT                         4
#define MATH_BOLD_SCRIPT                    5
#define MATH_FRAKTUR                        6
#define MATH_DOUBLE_STRUCK                  7
#define MATH_BOLD_FRAKTUR                   8
#define MATH_SANS_SERIF                     9
#define MATH_SANS_SERIF_BOLD               10
#define MATH_SANS_SERIF_ITALIC             11
#define MATH_SANS_SERIF_BOLD_ITALIC        12
#define MATH_MONOSPACE                     13
#define MATH_OLDSTYLE                      14

// This all seems horribly messy! Unicode specfies a nice block of
// "mathematical" letters starting at U+1d400 but there are gaps in that
// where individual letters had already been provided in the basic
// multilingual pane. So the code here will map letters either onto this
// special range or onto one of the special cases.


// Once again the main "joy" here is that a fair number of styled
// mathematical letters had been provided in early revisions of Unicode,
// so for instance an "Math Italic small h" was provided with the Unicode
// name PLANCK_CONSTANT. Then a-g and i-z in Math Italic are then provided
// in a block somewhere above U+1d400. The code here knows about the
// special cases and allows you to ask for letters in different styles
// without needing to track the full mess of Unicode layout.


int map_math_letter(int style, int c)
{   int r;
    if ('A' <= c && c <= 'Z') r = c - 'A';
    else if ('a' <= c && c <= 'z') r = c - 'a' + 26;
    else return 0; // Return 0 if not mappable
    switch (style)
    {   case MATH_REGULAR:
            return c;
        case MATH_BOLD:
            return r+unicode_MATHEMATICAL_BOLD_CAPITAL_A;
        case MATH_ITALIC:
// MATHEMATICAL_ITALIC_SMALL_DOTLESS_I & MATHEMATICAL_ITALIC_SMALL_DOTLESS_J
// exist but will perhaps be best generated manually when needed.
            if (c == 'h') return unicode_PLANCK_CONSTANT;
            return r+unicode_MATHEMATICAL_ITALIC_CAPITAL_A;
        case MATH_BOLD_ITALIC:
            return r+unicode_MATHEMATICAL_BOLD_ITALIC_CAPITAL_A;
        case MATH_SCRIPT:
            if (c == 'B') return unicode_SCRIPT_CAPITAL_B;
            if (c == 'E') return unicode_SCRIPT_CAPITAL_E;
            if (c == 'F') return unicode_SCRIPT_CAPITAL_F;
            if (c == 'H') return unicode_SCRIPT_CAPITAL_H;
            if (c == 'I') return unicode_SCRIPT_CAPITAL_I;
            if (c == 'L') return unicode_SCRIPT_CAPITAL_L;
            if (c == 'M') return unicode_SCRIPT_CAPITAL_M;
            if (c == 'R') return unicode_SCRIPT_CAPITAL_R;
            if (c == 'e') return unicode_SCRIPT_SMALL_E;
            if (c == 'g') return unicode_SCRIPT_SMALL_G;
            if (c == 'o') return unicode_SCRIPT_SMALL_O;
            return r+unicode_MATHEMATICAL_SCRIPT_CAPITAL_A;
        case MATH_BOLD_SCRIPT:
            return r+unicode_MATHEMATICAL_BOLD_SCRIPT_CAPITAL_A;
        case MATH_FRAKTUR:
            if (c == 'C') return unicode_BLACK_LETTER_CAPITAL_C;
            if (c == 'H') return unicode_BLACK_LETTER_CAPITAL_H;
            if (c == 'I') return unicode_BLACK_LETTER_CAPITAL_I;
            if (c == 'R') return unicode_BLACK_LETTER_CAPITAL_R;
            if (c == 'Z') return unicode_BLACK_LETTER_CAPITAL_Z;
            return r+unicode_MATHEMATICAL_FRAKTUR_CAPITAL_A;
        case MATH_DOUBLE_STRUCK:
            if (c == 'C') return unicode_DOUBLE_STRUCK_CAPITAL_C;
            if (c == 'H') return unicode_DOUBLE_STRUCK_CAPITAL_H;
            if (c == 'N') return unicode_DOUBLE_STRUCK_CAPITAL_N;
            if (c == 'P') return unicode_DOUBLE_STRUCK_CAPITAL_P;
            if (c == 'Q') return unicode_DOUBLE_STRUCK_CAPITAL_Q;
            if (c == 'R') return unicode_DOUBLE_STRUCK_CAPITAL_R;
            if (c == 'Z') return unicode_DOUBLE_STRUCK_CAPITAL_Z;
            return r+unicode_MATHEMATICAL_DOUBLE_STRUCK_CAPITAL_A;
        case MATH_BOLD_FRAKTUR:
            return r+unicode_MATHEMATICAL_BOLD_FRAKTUR_CAPITAL_A;
        case MATH_SANS_SERIF:
            return r+unicode_MATHEMATICAL_SANS_SERIF_CAPITAL_A;
        case MATH_SANS_SERIF_BOLD:
            return r+unicode_MATHEMATICAL_SANS_SERIF_BOLD_CAPITAL_A;
        case MATH_SANS_SERIF_ITALIC:
            return r+unicode_MATHEMATICAL_SANS_SERIF_ITALIC_CAPITAL_A;
        case MATH_SANS_SERIF_BOLD_ITALIC:
            return r+unicode_MATHEMATICAL_SANS_SERIF_BOLD_ITALIC_CAPITAL_A;
        case MATH_MONOSPACE:
            return r+unicode_MATHEMATICAL_MONOSPACE_CAPITAL_A;
        default:
            return 0;
    }
}

// Similarly for Greek.

int map_math_greek_letter(int style, int c)
{   int r;
// This will only cope with simple letters, not any of the accented ones.
// There are also varients available, such as THETA_SYMBOL, PHI_SYMBOL,
// EPSILON_SYMBOL, KAPPA_SYMBOL, RHO_SYMBOL, PI_SYMBOL & PARTIAL_DIFFERENTIAL
// in the range of mathematical symbols, but those will have to be generated
// by hand as individual special cases. You start by passing this a regular
// Unicode Greek letter. If you ask for the MATH_REGULAR varient it gets
// returned unchanged - otherwise it maps to one of the mathematical special
// variants.
    if (unicode_GREEK_CAPITAL_LETTER_ALPHA <= c &&
        c <= unicode_GREEK_CAPITAL_LETTER_OMEGA)
        r = c - unicode_GREEK_CAPITAL_LETTER_ALPHA;
    if (unicode_GREEK_SMALL_LETTER_ALPHA <= c &&
        c <= unicode_GREEK_SMALL_LETTER_OMEGA)
        r = c - unicode_GREEK_SMALL_LETTER_ALPHA +
            (unicode_MATHEMATICAL_BOLD_SMALL_ALPHA -
             unicode_MATHEMATICAL_BOLD_CAPITAL_ALPHA);
    else return 0; // Return 0 if not mappable
    switch (style)
    {   case MATH_REGULAR:
            return c;
        case MATH_BOLD:
            return r+unicode_MATHEMATICAL_BOLD_CAPITAL_ALPHA;
        case MATH_ITALIC:
            return r+unicode_MATHEMATICAL_ITALIC_CAPITAL_ALPHA;
        case MATH_BOLD_ITALIC:
            return r+unicode_MATHEMATICAL_BOLD_ITALIC_CAPITAL_ALPHA;
        case MATH_SANS_SERIF_BOLD:
            return r+unicode_MATHEMATICAL_SANS_SERIF_BOLD_CAPITAL_ALPHA;
        case MATH_SANS_SERIF_BOLD_ITALIC:
            return r+unicode_MATHEMATICAL_SANS_SERIF_BOLD_ITALIC_CAPITAL_ALPHA;

        default:
            return 0;
    }
}

// Similarly for digits. As a matter of trying to be generous I will allow
// the input EITHER to be a code in the range '0' to '9' or a number
// in the range 0-9.

int map_math_digit(int style, int c)
{   int r;
// I will accept either a numeric value or a codepoint here!
    if ('0' <= c && c <= '9') r = c - '0';
    else if (0 <= c && c <= 9) r = c;
    else return 0; // Return 0 if not mappable
    switch (style)
    {   case MATH_REGULAR:
            return r+'0';
        case MATH_BOLD:
            return r+unicode_MATHEMATICAL_BOLD_DIGIT_ZERO;
        case MATH_DOUBLE_STRUCK:
            return r+unicode_MATHEMATICAL_DOUBLE_STRUCK_DIGIT_ZERO;
        case MATH_SANS_SERIF:
            return r+unicode_MATHEMATICAL_SANS_SERIF_DIGIT_ZERO;
        case MATH_SANS_SERIF_BOLD:
            return r+unicode_MATHEMATICAL_SANS_SERIF_BOLD_DIGIT_ZERO;
        case MATH_MONOSPACE:
            return r+unicode_MATHEMATICAL_MONOSPACE_DIGIT_ZERO;
        case MATH_OLDSTYLE:
// Just in STIXMath... and mapped onto valid codepoints in the ACN variant
// of that font!
            return r+nonstandard_OLD_STYLE_DIGIT_ZERO;
        default:
            return 0;
    }
}


// end of unimaths.cpp
