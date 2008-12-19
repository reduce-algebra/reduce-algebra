/******************************************************************************
*                                                                             *
*   D i s p l a y   o f   M a t h s   i n   a   w i n d o w .                 *
*                                                                             *
*******************************************************************************
* Copyright (C) 2003-8 by Arthur Norman, Codemist Ltd.  All Rights Reserved.  *
*******************************************************************************
* This library is free software; you can redistribute it and/or               *
* modify it under the terms of the GNU Lesser General Public                  *
* License as published by the Free Software Foundation;                       *
* version 2.1 of the License.                                                 *
*                                                                             *
* This library is distributed in the hope that it will be useful,             *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU           *
* Lesser General Public License for more details.                             *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public            *
* License along with this library; if not, write to the Free Software         *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.  *
*                                                                             *
* I would also have granted rights styled after the FOX addendum to its       *
* license, but since this requires that I make modifications elsewhere in     *
* FOX I am unable to do that, so this is subject to just LGPL 2.1.            *
******************************************************************************/

// However as a special exception to LGPL 2.1 I grant permission for my code
// to be merged or linked with other code that is subject to LGPL version 3
// or GPL version 3. This provision does not represent permission to alter the
// license of my code to be that of LGPL 3 or GPL 3 - of itself and when
// removed from any LGPL 3 context it remains LGPL 2.1 and the freedom
// enshrined by that can not be reduced by adding in the additional
// constraints that LGPL 3 views as protections. However clearly the combined
// work that then includes my work would be subject to "3". But as per LGPL
// 2.1 (and the same would be true if I had used a BSD-style license here)
// notices explaining the license terms related to my code should not be
// removed. Anybody who changes or extends my code is permitted but not
// obliged to apply this exception, and perhaps by doing do they do not lock
// out (L)GPL 3 users but guarantee continued support for (L)GPL 2.1 in a way
// that the "or later" clause does not (since that permits anybody to
// unilaterally select just one version of the library to use, to the
// potential detriment of those whose choice differs).


#ifndef FXSHOWMATH_H
#define FXSHOWMATH_H

/* Signature: 3283c351 04-Jun-2008 */

namespace FX {

// I will represent information on the screen by nests of "boxes".

typedef struct TextBox
{
    unsigned char type, flags;
    short int height, depth, width;
    int n;
    char *text;
} TextBox;

typedef struct MatrixBox
{
    unsigned char type, flags;
    short int height, depth, width;
// I will arrange a matrix as a bunch of "NestBox" structures that are
// each BoxTower. The "BoxTower-ness" is used to represent the row
// structure.  Each row will be a chain of BoxBeside NestBox structures.
// The top-level BracketBox is used when measuring to trigger measuring
// this mess so that each row and each column has a consistent size and so
// that the overall base-line of the box is half way up it.
    short int dy;   // NB this must be signed
    union Box *sub;
} MatrixBox;

typedef struct BracketBox
{
    unsigned char type, flags;
    short int height, depth, width;
// a "BracketBox" is used to represent an item enclosed within
// large delimiters. I record the left and right delimiters being used
// (from a limited range of symbols) together with the width of the
// left delimiter, which is how far the contents must be offset. Note
// that a "right vertical bar" is represented here by an exclamation
// mark so I can distinguish it from a left vertical bar.
    char leftBracket, rightBracket;
    short int dx;
    union Box *sub;
// Just for the sake of \sqrt I permit "brackets" to store an additional
// component. This is used for the "3" in "\sqrt[3]{x}"
    short int dx1, dy1;
    union Box *sub1;
} BracketBox;

typedef struct NestBox
{
    unsigned char type, flags;
    short int height, depth, width;
    short int dx1, dy1, dx2, dy2;
    union Box *sub1;
    union Box *sub2;
} NestBox;

typedef struct NestBox3
{
    unsigned char type, flags;
    short int height, depth, width;
    short int dx1, dx2, dx3, dy1, dy2, dy3;
    union Box *sub1;
    union Box *sub2;
    union Box *sub3;
} NestBox3;

typedef struct SymBox
{
    unsigned char type, flags;
    short int height, depth, width;
} SymBox;

typedef struct FrameBox
{
    unsigned char type, flags;
    short int height, depth, width;
    union Box *sub;
} FrameBox;

typedef struct TopBox
{
    unsigned char type, flags;
    short int height, depth, width;
    union Box *sub;
    void *chunk;
    int measuredSize;
} TopBox;

typedef union Box
{
    TextBox text;
    NestBox nest;
    NestBox3 nest3;
    SymBox sym;
    BracketBox bracket;
    MatrixBox matrix;
    FrameBox frame;
    TopBox top;
} Box;

extern Box *makeTextBox(const char *s, int n, int fnt);

extern void *masterFont[36];

// Some flags
#define FontMask       0x0f

#define FontFamilyMask 0x03
#define FntRoman       0x00
#define FntItalic      0x01
#define FntSymbol      0x02
#define FntExtension   0x03

#define FontSizeMask   0x0c
#define FntRegular     0x00
#define FntScript      0x04
#define FntScrScr      0x08

#define FntBig         0x10

// The 12 maths fonts currently in play are kept in this array which
// it may sometimes be necessary to inspect. The width of an "M" in the
// normal size one of these is in mathWidth again for marginal cases
// that feel they nee dit.
 
extern void *mathFont[12];
extern int mathWidth;

// The overall interface here is perhaps not too complicated!
//
// Before trying to make any use of this code you must call
// setUpShowMath, indicating the size (in decipoints) of the
// font to be used.
//
// parseTeX() is given a function that will return characters from
// TeX-line input, and a handle (called owner). It returns a reference
// to a Box structure in its own private memory. The function should
// return zero at end-of-data.
//
// Before any Box is displayed you MUST call measureBox() on it to
// get its layout established.
//
// Finally within your onPaint() method you can call paintBox() to
// display the Box at a given location.

typedef int getTeXchar();

// Get it all ready. If mainSize is positive it is the font size in decipoints,
// if negative its absolute value if the window width in pixels, and a font
// size will be selected base on that. Returns zero if the necessary fonts
// are not available. Needs a window that will be painted in.

extern int setupShowMath(FXApp *app, int mainSize, FXWindow *w);

// Call this at end to tidy up.

extern void closeShowMath(FXApp *app);

// reset the font size, using same convention as before. Returns zero
// if it was not possible to set the new size, but in that case it leaves
// any previous set of valid fonts in place.

extern int changeMathFontSize(FXApp *app, int newSize);

// at any font size formulae can be drawn at one of 5 different scales,
// and this is use dto help ensure that things fit across the page. This
// is used to indicate which should be used. Arg is 0 - 4.

extern void setMathsFontScale(int n);

// the character-reader must hand back some TeX-line stuff, which is parsed
// and a Box returned. The "owner" is an integer handle that will be
// notified if the box ever gets discarded (eg because memory gets full).

extern Box *parseTeX(getTeXchar *fn, int owner);

// this MUST be called before you rely on metrics extracted from a Box. It
// does detailed layout adjustment.

extern void measureBox(Box *b);

// measureBox1 is like measureBox but if the Box has already been measured
// and if setMathsFontScale has not changed the scale since then the
// existing measurements are left intact.

extern void measureBox1(Box *b);

// make something appear on the screen.

extern void paintBox(FXDC *dc, Box *b, int x, int y);

// It may be useful to be able to process Box pointers as handles. The
// next two map between Box pointers as created by parseTeX and integers.

extern Box *poolPointerFromHandle(int n);

extern int handleFromPoolPointer(Box *b);

// In the owner of a box changes this lets you tell it that.

extern void updateOwner(Box *b, int new_owner);

// When the memory being used by a box is about to be discarded it will notify
// the recorded owner by calling this...

extern void reportDestroy(int p);

}

#endif // FXSHOWMATH_H

// end of FXShowMath.h
 
