/********************************************************************************
*                                                                               *
*                               F o n t   O b j e c t                           *
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
*********************************************************************************
* $Id: FXPostscriptFont.h,v 1.28 2003/05/20 16:46:06 fox Exp $                  *
********************************************************************************/


// The above rights relate to the file FXFont upon which this is based.
// There are adjustments here by A C Norman, who is not permitted to make
// his changes available under the addendum to the LGPL that the trunk
// FOX sources benefit from, and who hence releases this under just LGPL 2.1

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


/* Signature: 3fa81b54 04-Jun-2008 */


#ifndef FXPOSTSCRIPTFONT_H
#define FXPOSTSCRIPTFONT_H

#include <FXFont.h>

namespace FX {

// I would rather like to override a bunch of things in FXFont, but they
// are not virtual. Thus I need a work-around.

// Define a version of FOX where these patches become unnecessary needed.
// This is in that hope that at some stage FOX will make more functions
// within FXFont virtual...

#define FONT_MAJOR 1
#define FONT_MINOR 6
#define FONT_LEVEL 21

#ifndef INT_VERSION
#define INT_VERSION(a,b,c) (((a*1000) + b)*1000 + c)
#endif

#if INT_VERSION(FOX_MAJOR,FOX_MAJOR,FOX_LEVEL) < \
    INT_VERSION(FONT_MAJOR,FONT_MINOR,FONT_LEVEL)

#define FONT_NOT_VIRTUAL 1

#endif

#if INT_VERSION(FOX_MAJOR,FOX_MINOR,FOX_LEVEL) < INT_VERSION(1,1,49)
// At 1.1.49 the fields in FXFont relating to font properties were split
// so that having (eg) a single "size" field there were two fields
// "wantedSize" and "actualSize". My code works in terms of the new names
// but to support the older versions of FOX It maps the old names onto the
// new ones when relevant. Beware that a crude set of #define statements
// like this is dangerous in that if other classes have fields with the
// same names references to them would suffer.
//
#define WANTED_AND_ACTUAL 1
// #define actualName     name      etc etc et
#endif

/// Font class
class FXAPI FXPostscriptFont : public FXFont {
  FXDECLARE(FXPostscriptFont)
protected:
  struct font_info *metrics;
  FXPostscriptFont();
private:
  FXPostscriptFont(const FXPostscriptFont&);
  FXPostscriptFont &operator=(const FXPostscriptFont&);
public:

  /// Construct font from font description
  FXPostscriptFont(FXApp* a,const FXFontDesc& fontdesc);

  /// Construct a font with given face name, size in points(pixels), weight, slant, character set encoding, setwidth, and hints
#if (FOX_MINOR<=4)
  FXPostscriptFont(FXApp* a,const FXString& face,FXuint sz,FXuint wt=FONTWEIGHT_NORMAL,FXuint sl=FONTSLANT_REGULAR,FXuint enc=FONTENCODING_DEFAULT,FXuint setw=FONTSETWIDTH_DONTCARE,FXuint h=0);
#else
  FXPostscriptFont(FXApp* a,const FXString& face,FXuint sz,FXuint wt=Normal,FXuint sl=Straight,FXuint enc=FONTENCODING_DEFAULT,FXuint setw=0,FXuint h=0);
#endif

  /// Construct a font with given X11 font string (not supported!)
  FXPostscriptFont(FXApp* a,const FXString& nm);

  /// Create the font
  virtual void create();

  /// Find out if the font is monotype or proportional
  FXbool isFontMono() const;

  /// See if font has glyph for ch
  virtual FXbool hasChar(FXint ch) const;

  /// Get first character glyph in font
#if (FOX_MINOR<=4)
  FXint getMinChar() const;
#else
  FXwchar getMinChar() const;
#endif

  /// Get last character glyph in font
#if (FOX_MINOR<=4)
  FXint getMaxChar() const;
#else
  FXwchar getMaxChar() const;
#endif

  /// Left bearing
  virtual FXint leftBearing(FXchar ch) const;

//
// NB a FXPostscriptFont returns measurements here in units of
// millipoints.
//

  /// Right bearing
  virtual FXint rightBearing(FXchar ch) const;

  /// Width of widest character in font
  FXint getFontWidth() const;

  /// Height of highest character in font
  FXint getFontHeight() const;

  /// Ascent from baseline
  FXint getFontAscent() const;

  /// Descent from baseline
  FXint getFontDescent() const;

  /// Get font leading [that is lead-ing as in Pb!]
  FXint getFontLeading() const;

  /// Get font line spacing
  FXint getFontSpacing() const;

  /// Calculate width of given text in this font
  FXint getTextWidth(const FXchar *text,FXuint n) const;

  /// Calculate width of given text in this font
  FXint getTextWidth(const FXString& text) const;

  /// Calculate height of given text in this font
  FXint getTextHeight(const FXchar *text,FXuint n) const;

  /// Calculate height of given text in this font
  FXint getTextHeight(const FXString& text) const;

  /**
   * List all fonts matching hints. If listFonts() returns TRUE then
   * fonts points to a newly-allocated array of length numfonts. It
   * is the caller's responsibility to free this array using FXFREE().
   */
#if (FOX_MINOR<=4)
  static FXbool listFonts(FXFontDesc*& fonts,FXuint& numfonts,const FXString& face,FXuint wt=FONTWEIGHT_DONTCARE,FXuint sl=FONTSLANT_DONTCARE,FXuint sw=FONTSETWIDTH_DONTCARE,FXuint en=FONTENCODING_DEFAULT,FXuint h=0);
#else
  static FXbool listFonts(FXFontDesc*& fonts,FXuint& numfonts,const FXString& face,FXuint wt=Normal,FXuint sl=Straight,FXuint sw=NonExpanded,FXuint en=FONTENCODING_DEFAULT,FXuint h=0);
#endif

  /// Destroy font
  virtual ~FXPostscriptFont();
  };


}

#endif

