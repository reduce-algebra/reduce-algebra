/********************************************************************************
*                                                                               *
*                   P o s t c r i p t   F o n t   O b j e c t                   *
*                                                                               *
*********************************************************************************
* Copyright (C) 1997,2003 by Jeroen van der Zijp.   All Rights Reserved.        *
*********************************************************************************
* This library is free software; you can redistribute it and/or                 *
* modify it under the terms of the GNU Lesser General Public                    *
* License as published by the Free Software Foundation;                         *
* version 2.1 of the License.                                                   *
*                                                                               *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU             *
* Lesser General Public License for more details.                               *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public              *
* License along with this library; if not, write to the Free Software           *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.    *
*
* I would have released this updated version under the FOX license addendum     *
* that permits static linking, but its terms make that infeasible so this is    *
* JUST under LGPL                                                               *
*********************************************************************************
* $Id: FXPostscriptFont.cpp,v 1.65 2003/10/27 23:59:21 fox Exp $                *
********************************************************************************/


// This file was written by A C Norman based on FXFont.c, for which the
// above copyright etc apply. The "FOX addendum" referred to can only apply to
// variants on FOX distributed by Jeroen, not to any modifications that he has
// not adopted, and hence does not apply here, thus this code is subject
// to just LGPL 2.1. Note that FXFont.cpp was under "LGPL 2.1 or later" but
// in making this derived work I choose just to select version 2.1.
//
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

/* Signature: 0a4910ee 04-Jun-2008 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
                                                                                

#include <fx.h>
#include "FXPostscriptFont.h"
#include <ctype.h>

using namespace FX;

namespace FX {


/*******************************************************************************/


#ifdef WANTED_AND_ACTUAL
// A bunch of field-names changed between 1.1.45 and 1.1.49 so here for
// older releases I map onto the newer names. It may be that I should be a
// lot more carefull wrt actualXxx and wantedXxx.


// version 1.1.x is SO old now that I might properly disard this...

#define actualName      name     
#define actualSize      size     
#define actualWeight    weight   
#define actualSlant     slant    
#define actualEncoding  encoding 
#define actualSetwidth  setwidth 

#endif

// Object implementation
FXIMPLEMENT(FXPostscriptFont,FXFont,NULL,0)


// Deserialization
FXPostscriptFont::FXPostscriptFont(){
  font=(void*)-1L;
  }


// Construct font from X11 font spec. Well for Postscript Fonts
// I will not support decoding X11 long-names...

FXPostscriptFont::FXPostscriptFont(FXApp* a,const FXString& nm):FXFont(a,nm){
  FXTRACE((100,"FXPostscriptFont::FXPostscriptFont %p\n",this));
  actualSize=0;
  actualWeight=0;
  actualSlant=0;
  actualEncoding=FONTENCODING_DEFAULT;
#if (FOX_MINOR<=4)
  actualSetwidth=FONTSETWIDTH_DONTCARE;
#else
  actualSetwidth=0;
#endif
  font=NULL;
  }


// Construct a font with given face name, size in points(pixels), weight, slant, character set encoding, setwidth, and hints
FXPostscriptFont::FXPostscriptFont(FXApp* a, const FXString &face, FXuint sz,
    FXuint wt, FXuint sl, FXuint enc, FXuint setw, FXuint h):FXFont(a,face){
  FXTRACE((100,"FXPostscriptFont::FXPostscriptFont %p\n",this));
  actualSize=10*sz;
  actualWeight=wt;
  actualSlant=sl;
  actualEncoding=enc;
  actualSetwidth=setw;
#if (FOX_MINOR<=4)
  hints=(h&~FONTHINT_X11);
#else
  hints=(h&~FXFont::X11);
#endif
  font=NULL;
  }


// Construct font from font description
FXPostscriptFont::FXPostscriptFont(FXApp* a,
     const FXFontDesc &fontdesc):FXFont(a, fontdesc){
  FXTRACE((100,"FXPostscriptFont::FXPostscriptFont %p\n",this));
  actualName=fontdesc.face;
  actualSize=fontdesc.size;
  actualWeight=fontdesc.weight;
  actualSlant=fontdesc.slant;
  actualEncoding=fontdesc.encoding;
  actualSetwidth=fontdesc.setwidth;
  hints=fontdesc.flags; 
  font=NULL;
  }


/*******************************************************************************/




//
// When generating Postscript I need font metrics. These can be extracted
// from "afm" files that Adobe supply. I have a program "get-adobe-metrics.c"
// that can be run on a typical Linux system to extract the (minimal) metric
// information that I need here and build a file "font-info.c". By including
// that file here I collect info about all the standard Postscript Fonts.
// I will not permit a user to use any other fonts than these!
//


//
// There are 35 standard Postscript fonts that might be used with this
// print package. They are:
//      AvantGarde-Book 
//      AvantGarde-BookOblique 
//      AvantGarde-Demi 
//      AvantGarde-DemiOblique 
//      Bookman-Demi 
//      Bookman-DemiItalic 
//      Bookman-Light 
//      Bookman-LightItalic 
// *    Courier-Bold 
// *    Courier-BoldOblique 
// *    Courier 
// *    Courier-Oblique 
// *    Helvetica-Bold 
// *    Helvetica-BoldOblique 
//      Helvetica-NarrowBold 
//      Helvetica-NarrowBoldOblique 
// *    Helvetica 
// *    Helvetica-Oblique 
//      Helvetica-Narrow 
//      Helvetica-NarrowOblique 
//      NewCenturySchlbk-Bold 
//      NewCenturySchlbk-BoldItalic 
//      NewCenturySchlbk-Italic 
//      NewCenturySchlbk-Roman 
//      Palatino-Bold 
//      Palatino-BoldItalic 
//      Palatino-Italic 
//      Palatino-Roman 
// *    Symbol 
// *    Times-Bold 
// *    Times-BoldItalic 
// *    Times-Italic 
// *    Times-Roman 
//      ZapfChancery-MediumItalic 
//      ZapfDingbats 
// [those marked * are the original 13]
//
//

// Font metrics: I extract these from .afm files so that I can have
// rapid access to the information that I need throughout this package.
// The effect is that I fill a few kilobytes of memory with font tables.
// To avoid going over the top I will not keep per-character bearing
// information.  The information in the font tables is based on having a
// nominal character cell that is 1000 units high, which means that
// integer metrics are quite accurate enough for everybody.

#include "font-info.c"

// Here is the sort of info found in "font-info.c". Each font
// listed comes with its full Adobe name.
// [It will shortly need (max)width, height, ascent, descent,
// leading, (max)left-bearing (max)right-bearing]
// The main data is then an array of 256 short integers. This contains
// -1 if the character is not present, otherwise the character width.
// Note once again that these numbers are all based on a nominal 1pt font
// with units of 1/1000. Another way to think of this is that numbers are
// in units of 1/72000in and will need to be multiplied by the point size
// of a font before use.
//
//  typedef struct font_info {
//     char *name;
//     short int isfixed, fontwidth, maxleftbearing, maxrightbearing;
//     short int capheight, xheight, ascent, descent;
//     short int charwidth[256];
//  } font_info;
//  
//  static font_info font_widths[] = {
//  {"AvantGarde-Demi", 0, 1280, 233, 234, 740, 555, 740, -185, {
//      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
//      ...
//      -1,   874,   760,   946,   771,   865,   771,   888,
//     967,   888,   831,   873,   927,   970,   918,    -1 }},
//  {(char *)0, {}}};
// 

static font_info *find_metrics(const char *name)
{
    font_info *p = font_widths;
    while (p->name != NULL && strcmp(name, p->name)!=0) p++;
    if (p->name != NULL) return p;
    return &font_widths[0];  // this should never occur!
} 


// Create font. In this case I take that to mean the process of refining
// the font name and fetching associated metrics. 

enum family {
    AvantGarde,
    Bookman,
    Courier,
    Helvetica,
    NewCenturySchlbk,
    Palatino,
    Symbol,
    Times,
    ZapfChancery,
    ZapfDingbats
};

// return true of s has p as an initial sub-string, ignoring case

static FXbool matches(const char *s, const char *p)
{
    while (*p != 0)
    {   if (*s==0 || tolower(*s)!=tolower(*p)) return FALSE;
        s++;
        p++;
    }
    return TRUE;
}

// return true if s has p as a substring, ignoring case

static FXbool contains(const char *s, const char *p)
{
    while (*s != 0)
    {   if (matches(s, p)) return TRUE;
        s++;
    }
    return FALSE;
}

void FXPostscriptFont::create()
{
// I will start by massaging the given name etc to provide me with one of the
// canonical Postscript names. Note that the tests on font families
// are done in an order so that later test acn override tentative decisions
// made by earlier ones. Eg the font with name "roman" will first be
// identified as asking for Times (roman, bold etc), but if the word
// "palatino" is see too then you get Palatino-Roman. If the name is
// not recognised at all you will get Times
    family fam = Times;    // a default family to use
    const char *n = actualName.text();
#if (FOX_MINOR<=4)
    if (contains(n, "bold")) actualWeight = FONTWEIGHT_BOLD;
    if (contains(n, "light")) actualWeight = FONTWEIGHT_LIGHT;
    if (contains(n, "italic")) actualSlant = FONTSLANT_ITALIC;
    if (contains(n, "oblique")) actualSlant = FONTSLANT_OBLIQUE;
    if (contains(n, "narrow")) actualSetwidth = FONTSETWIDTH_NARROW;
#else
    if (contains(n, "bold")) actualWeight = FXFont::Bold;
    if (contains(n, "light")) actualWeight = FXFont::Light;
    if (contains(n, "italic")) actualSlant = FXFont::Italic;
    if (contains(n, "oblique")) actualSlant = FXFont::Oblique;
    if (contains(n, "narrow")) actualSetwidth = FXFont::Condensed;
#endif
    if (contains(n, "times") ||
        contains(n, "serif") ||
        contains(n, "roman")) fam = Times;
    if (contains(n, "avant")) fam = AvantGarde;
    if (contains(n, "bookman")) fam = Bookman;
    if (contains(n, "courier") ||
        contains(n, "fixed")) fam = Courier;
    if (contains(n, "helvet") ||
        contains(n, "ariel") ||
        contains(n, "sanserif") ||
        contains(n, "swiss")) fam = Helvetica;
    if (contains(n, "newcent")) fam = NewCenturySchlbk;
    if (contains(n, "palatin")) fam = Palatino;
    if (contains(n, "symbol")) fam = Symbol;
    if (contains(n, "chancery") ||
        contains(n, "zapf")) fam = ZapfChancery;
    if (contains(n, "dingbat")) fam = ZapfDingbats;
// Now a few cases that override
#if (FOX_MINOR<=4)
    if (actualSetwidth != FONTSETWIDTH_DONTCARE &&
        actualSetwidth <= FONTSETWIDTH_COMPRESSED) fam = Helvetica;
    if (hints & (FONTPITCH_FIXED|FONTHINT_MODERN)) fam = Courier;
    else if ((hints & FONTPITCH_VARIABLE) && fam==Courier) fam = Helvetica;
 
#define four(reg, bold, ital, boldital) \
       (actualWeight<=FONTWEIGHT_NORMAL ? \
         (actualSlant<=FONTSLANT_REGULAR ? reg : ital) : \
         (actualSlant<=FONTSLANT_REGULAR ? bold : boldital))
#else
    if (actualSetwidth != 0 &&
        actualSetwidth <= FXFont::Condensed) fam = Helvetica;
    if (hints & (FXFont::Fixed|FXFont::Modern)) fam = Courier;
    else if ((hints & FXFont::Variable) && fam==Courier) fam = Helvetica;
 
#define four(reg, bold, ital, boldital) \
       (actualWeight<=FXFont::Normal ? \
         (actualSlant<=FXFont::Straight ? reg : ital) : \
         (actualSlant<=FXFont::Straight ? bold : boldital))
#endif
    switch (fam)
    {
case AvantGarde:
        actualName = four("AvantGarde-Book", "AvantGarde-Demi",
                    "AvantGarde-BookOblique", "AvantGarde-DemiOblique");
        break;
case Bookman:
        actualName = four("Bookman-Light", "Bookman-Demi",
                    "Bookman-LightItalic", "Bookman-DemiItalic");
        break;
case Courier:
        actualName = four("Courier", "Courier-Bold",
                    "Courier-Oblique", "Courier-BoldOblique");
        break;
case Helvetica:
#if (FOX_MINOR<=4)
        if (actualSetwidth == FONTSETWIDTH_NARROW)
#else
        if (actualSetwidth == FXFont::Condensed)
#endif
          actualName = four("Helvetica-Narrowi", "Helvetica-NarrowBold",
                      "Helvetica-NarrowOblique", "Helvetica-NarrowBoldOblique");
        else
          actualName = four("Helvetica", "Helvetica-Bold",
                      "Helvetica-Oblique", "Helvetica-BoldOblique");
        break;
case NewCenturySchlbk:
        actualName = four("NewCenturySchlbk", "NewCenturySchlbk-Bold",
                    "NewCenturySchlbk-Italic", "NewCenturySchlbk-BoldItalic");
        break;
case Palatino:
        actualName = four("Palatino-Roman", "Palatino-Bold",
                    "Palatino-Italic", "Palatino-BoldItalic");
        break;
case Symbol:
        actualName = "Symbol";
#if (FOX_MINOR<=4)
        actualWeight = FONTWEIGHT_NORMAL;
        actualSlant = FONTSLANT_REGULAR;
#else
        actualWeight = FXFont::Normal;
        actualSlant = FXFont::Straight;
#endif
        break;
case Times:
default:
        actualName = four("Times-Roman", "Times-Bold",
                    "Times-Italic", "Times-BoldItalic");
        break;
case ZapfChancery:
        actualName = "ZapfChancery-MediumItalic";
#if (FOX_MINOR<=4)
        actualWeight = FONTWEIGHT_NORMAL;
        actualSlant = FONTSLANT_ITALIC;
#else
        actualWeight = FXFont::Normal;
        actualSlant = FXFont::Italic;
#endif
        break;
case ZapfDingbats:
        actualName = "ZapfDingbats";
#if (FOX_MINOR<=4)
        actualWeight = FONTWEIGHT_NORMAL;
        actualSlant = FONTSLANT_REGULAR;
#else
        actualWeight = FXFont::Normal;
        actualSlant = FXFont::Straight;
#endif
    }
    metrics = find_metrics(actualName.text());
}


// Does font have given character glyph?
FXbool FXPostscriptFont::hasChar(FXint ch) const
{
    return metrics->charwidth[ch & 0xff] != -1;
}


// Get first character glyph in font
#if (FOX_MINOR<=4)
FXint FXPostscriptFont::getMinChar() const
#else
FXwchar FXPostscriptFont::getMinChar() const
#endif
{
    int i;
    for (i=0; i<256; i++)
        if (metrics->charwidth[i] != -1) return i;
    return 256;
}


// Get last character glyph in font
#if (FOX_MINOR<=4)
FXint FXPostscriptFont::getMaxChar() const 
#else
FXwchar FXPostscriptFont::getMaxChar() const 
#endif
{
    int i;
    for (i=255; i>=0; i--)
        if (metrics->charwidth[i] != -1) return i;
    return 0;
}


// Get font leading [that is lead-ing as in Pb!]
FXint FXPostscriptFont::getFontLeading() const 
{
// I use 0.2 of the point-size as my leading. Point sizes are stored in
// decipoints. I return a value in millipoints.
    return (200/10)*actualSize;
}


// Get font line spacing [height+leading]
FXint FXPostscriptFont::getFontSpacing() const 
{
    return (1200/10)*actualSize;
}


// Left bearing
FXint FXPostscriptFont::leftBearing(FXchar ch) const 
{
    return (metrics->maxleftbearing*actualSize)/10;
}


// Right bearing
FXint FXPostscriptFont::rightBearing(FXchar ch) const 
{
    return (metrics->maxrightbearing*actualSize)/10;
}


// Is it a mono space font
FXbool FXPostscriptFont::isFontMono() const 
{
    return metrics->isfixed;
}


// Get font width
FXint FXPostscriptFont::getFontWidth() const 
{
    return (metrics->fontwidth*actualSize)/10;
}


// Get font height
FXint FXPostscriptFont::getFontHeight() const 
{
    return (1000/10)*actualSize;
}


// Get font ascent
FXint FXPostscriptFont::getFontAscent() const 
{
    return (metrics->ascent*actualSize)/10;
}


// Get font descent
FXint FXPostscriptFont::getFontDescent() const 
{
    return (metrics->descent*actualSize)/10;
}


// Text width
FXint FXPostscriptFont::getTextWidth(const FXchar *text, FXuint n) const 
{
    int w = 0;
    while (*text != 0 && (n--)!=0)  // stop on null char as well as at length
    {   w += metrics->charwidth[*text & 0xff];
        text++;
    }
    return (w*actualSize)/10;
}


// Text width
FXint FXPostscriptFont::getTextWidth(const FXString &text) const 
{
    return getTextWidth(text.text(), text.length());
}


// Text height
FXint FXPostscriptFont::getTextHeight(const FXchar *text, FXuint n) const 
{
    return (1000/10)*actualSize;    // use font height
}


// Text height
FXint FXPostscriptFont::getTextHeight(const FXString &text) const 
{
    return getTextHeight(text.text(), text.length());
}


/******************************************************************************/



// Clean up
FXPostscriptFont::~FXPostscriptFont()
{
    FXTRACE((100,"FXPostscriptFont::~FXPostscriptFont %p\n",this));
    destroy();
}

}

// end of FXPostscriptFont.cpp

