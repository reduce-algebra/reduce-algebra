// FXDCNativePrinter.h
//
// This was derived from a file of this name on the FOX/FXEX repository,
// and its (lack of) explicit copyright claims etc has been preserved.
// As the most recent hacker of this version, I (A C Norman, Codemist Ltd)
// contribute all my adjustments back under an MIT/BSD-style bunch of
// permissions.
//
// see associated file FXDCNativePrinter.cpp for commentary etc. and a
// more careful explanation of the licensing situation.

/* Signature: 3c7a0fa4 17-May-2008 */


#ifndef FXDCNATIVEPRINTER_H
#define FXDCNATIVEPRINTER_H

#ifndef FXDC_H
#include <fx.h>
#include <FXDC.h>
#endif

#include <FXDCPrint.h>
#include "FXPostscriptFont.h"

//
// The class described here is intended to allow FOX applications to
// print - under Windows it uses the native Windows API while on other
// operating systems and if used to print to file it generates Postscript.
//
// The basic protocol for use is
//
//   FXPrintDialog dlg(this, "");
//   dlg.execute();                   // user gets to select a printer
//   FXPrinter printer;
//   dlg.getPrinter(printer);         // find out which one!
//   FXDCNativePrinter ptr(getApp()); // printing framework
//   if (!prt.beginPrint(printer)) FAIL   // unable to print just now
//   FXFont *f1 = prt.fntGenerateFont("courier", 12); // or whatever!
//                                    // font sizes given in points (1/72in)
//   f1->create();                    // remember to make font really there!
//   for (page=1;WHENEVER;page++)
//   {   prt.beginPage(page);         // start page
//       prt.setFont(f1);
//       x = prt.getPageWidth();      // at page border, does not leave any...
//       y = prt.getPageHeight();     // margins, so leave some yourself.
//       prt.drawLine(x1, y1, x2, y2);
//       prt.setForeground(FXRGB(255,0,0)); // colours
//       prt.drawText(x, y, "string", strlen("string"));
//       int w = prt.fntGetTextWidth("string", strlen("string"));
//       etc etc                      // measurements are in units of 1/72in
//                                    // by default.
//       prt.endPage();
//   }
//   prt.endPrint();
//   delete f1;                       // remember to tidy up afterwards


#ifdef WIN32
#include <windows.h>
#endif

namespace FX {

class FXAPI FXDCNativePrinter : public FXDC { 
protected:
  FXint      pagecount;               // Number of pages printed
  FXint      dctype;
  
  enum { TYPE_PS=0, TYPE_WIN32=1 };
  
protected:
#ifdef WIN32
  HDC dc;
  DOCINFO di;
  DEVMODE devmode;
  HANDLE devmode_handle;  
// opaque hold a FXPrinterDrawable, which is an auxilliary class only
// defined in the .cpp file 
  FXObject *opaque;
#endif
  FXDC *pdc;
protected:
  FXdouble scalex,scaley;
  FXint logpixelsx, logpixelsy;
  FXfloat unitsx,unitsy;
  FXfloat fontScale, fontScaleBack, PSscale;
  FXint fontoffset;
  FXfloat pagewidth, pageheight;
  FX::FXPostscriptFont *postscriptFont;
public:

  /// Construct
  FXDCNativePrinter(FXApp *a);
  
  /// Generate print job prolog
  virtual FXbool beginPrint(FXPrinter& job);

  /// Generate print job epilog
  virtual FXbool endPrint();

  /// Generate begin of page
  virtual FXbool beginPage(FXuint page=1);

  /// Generate end of page
  virtual FXbool endPage();


  void setHorzUnitsInch(FXfloat sx);
  void setVertUnitsInch(FXfloat sy);
  FXint ScaleX(FXint x) { return (int)(x*scalex); }
  FXint ScaleY(FXint y) { return (int)(y*scaley); }
  FXfloat getHorzUnitsInch(void) { return unitsx; }
  FXfloat getVertUnitsInch(void) { return unitsy; }  
  FXint getLogPixelsX(void) { return logpixelsx; }
  FXint getLogPixelsY(void) { return logpixelsy; }

  void scalePoints(FXPoint *dst, FXPoint *src, FXuint npoints );
  void scaleRectangles(FXRectangle *dst, FXRectangle *src, FXuint nrectangles );
  void scaleSegments(FXSegment *dst, FXSegment *src, FXuint nsegments );
  void scaleArcs(FXArc *dst, FXArc *src, FXuint narcs );
  
  FXint getPageWidth(void);
  FXint getPageHeight(void);
  double doublePageWidth(void);
  double doublePageHeight(void);

  /// Draw points
  virtual void drawPoint(FXint x,FXint y);
  virtual void drawPoints(const FXPoint *points,FXuint npoints);
  virtual void drawPointsRel(const FXPoint *points,FXuint npoints);

  /// Draw lines
  virtual void drawLine(FXint x1,FXint y1,FXint x2,FXint y2);
  virtual void drawLines(const FXPoint *points,FXuint npoints);
  virtual void drawLinesRel(const FXPoint *points,FXuint npoints);
  virtual void drawLineSegments(const FXSegment *segments,FXuint nsegments);

  /// Draw rectangles
  virtual void drawRectangle(FXint x,FXint y,FXint w,FXint h);
  virtual void drawRectangles(const FXRectangle *rectangles,FXuint nrectangles);

  /// Draw arcs
  virtual void drawArc(FXint x,FXint y,FXint w,FXint h,FXint ang1,FXint ang2);
  virtual void drawArcs(const FXArc *arcs,FXuint narcs);

  /// Filled rectangles
  virtual void fillRectangle(FXint x,FXint y,FXint w,FXint h);
  virtual void fillRectangles(const FXRectangle *rectangles,FXuint nrectangles);

  /// Draw arcs
  virtual void fillArc(FXint x,FXint y,FXint w,FXint h,FXint ang1,FXint ang2);
  virtual void fillArcs(const FXArc *arcs,FXuint narcs);

  /// Filled polygon
  virtual void fillPolygon(const FXPoint *points,FXuint npoints);
  virtual void fillConcavePolygon(const FXPoint *points,FXuint npoints);
  virtual void fillComplexPolygon(const FXPoint *points,FXuint npoints);

  /// Filled polygon with relative points
  virtual void fillPolygonRel(const FXPoint *points,FXuint npoints);
  virtual void fillConcavePolygonRel(const FXPoint *points,FXuint npoints);
  virtual void fillComplexPolygonRel(const FXPoint *points,FXuint npoints);

  /// Draw hashed box
  virtual void drawHashBox(FXint x,FXint y,FXint w,FXint h,FXint b=1);

  /// Draw area from source
  virtual void drawArea(const FXDrawable *source,FXint sx,FXint sy,FXint sw,FXint sh,FXint dx,FXint dy);

  /// Draw image
  virtual void drawImage(const FXImage *image,FXint dx,FXint dy);

  /// Draw bitmap
  virtual void drawBitmap(const FXBitmap *bitmap,FXint dx,FXint dy);

  /// Draw icon
  virtual void drawIcon(const FXIcon *icon,FXint dx,FXint dy);
  virtual void drawIconShaded(const FXIcon *icon,FXint dx,FXint dy);
  virtual void drawIconSunken(const FXIcon *icon,FXint dx,FXint dy);

  /// Draw string
  virtual void drawText(FXint x, FXint y, const FXchar *string, FXuint length);
  virtual void drawImageText(FXint x, FXint y, const FXchar *string, FXuint length);

  /// Set foreground/background drawing color
  virtual void setForeground(FXColor clr);
  virtual void setBackground(FXColor clr);

  /// Set dash pattern
  virtual void setDashes(FXuint dashoffset,const FXchar *dashlist,FXuint n);

  /// Set line width
  virtual void setLineWidth(FXuint linewidth=0);

  /// Set line cap style
  virtual void setLineCap(FXCapStyle capstyle=CAP_BUTT);

  /// Set line join style
  virtual void setLineJoin(FXJoinStyle joinstyle=JOIN_MITER);

  /// Set line style
  virtual void setLineStyle(FXLineStyle linestyle=LINE_SOLID);

  /// Set fill style
  virtual void setFillStyle(FXFillStyle fillstyle=FILL_SOLID);

  /// Set fill rule
  virtual void setFillRule(FXFillRule fillrule=RULE_EVEN_ODD);

  /// Set blit function
  virtual void setFunction(FXFunction func=BLT_SRC);

  /// Set the tile
  virtual void setTile(FXImage *tile,FXint dx=0,FXint dy=0);

  /// Set the stipple pattern
  virtual void setStipple(FXBitmap *stipple,FXint dx=0,FXint dy=0);

  /// Set the stipple pattern
  virtual void setStipple(FXStipplePattern stipple,FXint dx=0,FXint dy=0);

  /// Set clip rectangle
  virtual void setClipRectangle(FXint x,FXint y,FXint w,FXint h);

  /// Set clip rectangle
  virtual void setClipRectangle(const FXRectangle& rectangle);

  /// Clear clipping
  virtual void clearClipRectangle();

  /// Set clip mask
  virtual void setClipMask(FXBitmap *mask,FXint dx=0,FXint dy=0);

  /// Clear clip mask
  virtual void clearClipMask();

  /// Set font to draw text with
  virtual void setFont(FXFont *fnt);

  /// Clip drawing by child windows
  virtual void clipChildren(FXbool yes);

  /// Cleanup
  virtual ~FXDCNativePrinter();
  
  /****** Font management ******/
#if (FOX_MINOR<=4)
  FXFont *fntGenerateFont(const FXString& face, FXuint sz,
      FXuint wt=FONTWEIGHT_NORMAL, FXuint sl=FONTSLANT_REGULAR,
      FXuint enc=FONTENCODING_DEFAULT, FXuint setw=FONTSETWIDTH_DONTCARE,
      FXuint h=0);
  FXFont *fntDoubleGenerateFont(const FXString& face, double sz,
      FXuint wt=FONTWEIGHT_NORMAL, FXuint sl=FONTSLANT_REGULAR,
      FXuint enc=FONTENCODING_DEFAULT, FXuint setw=FONTSETWIDTH_DONTCARE,
      FXuint h=0);
#else
  FXFont *fntGenerateFont(const FXString& face, FXuint sz,
      FXuint wt=FXFont::Normal, FXuint sl=FXFont::Straight,
      FXuint enc=FONTENCODING_DEFAULT, FXuint setw=FXFont::NonExpanded,
      FXuint h=0);
  FXFont *fntDoubleGenerateFont(const FXString& face, double sz,
      FXuint wt=FXFont::Normal, FXuint sl=FXFont::Straight,
      FXuint enc=FONTENCODING_DEFAULT, FXuint setw=FXFont::NonExpanded,
      FXuint h=0);
#endif
  FXString fntGetName();
  FXuint fntGetSize();
  FXuint fntGetWeight();
  FXuint fntGetSlant();
  FXuint fntGetEncoding();
  FXuint fntGetSetWidth();
  FXuint fntGetHints();
  void fntGetFontDesc(FXFontDesc& fontdesc) const;
  void fntSetFontDesc(const FXFontDesc& fontdesc);
  FXbool fntIsFontMono() const; 
  FXbool fntHasChar(FXint ch) const; 
  FXint fntGetMinChar() const;  
  FXint fntGetMaxChar() const;  
  FXint fntLeftBearing(FXchar ch) const;  
  FXint fntRightBearing(FXchar ch) const;
  FXint fntGetFontWidth() const;  
  FXint fntGetFontHeight() const;
  FXint fntGetFontAscent() const;
  FXint fntGetFontDescent() const;
  FXint fntGetFontLeading() const;
  FXint fntGetFontSpacing() const;
  FXint fntGetTextWidth(const FXchar *text,FXuint n) const;
  FXint fntGetTextHeight(const FXchar *text,FXuint n) const;
// Versions of the above that return floating point values
  double fntDoubleSize();
  double fntDoubleLeftBearing(FXchar ch) const;  
  double fntDoubleRightBearing(FXchar ch) const;
  double fntDoubleFontWidth() const;  
  double fntDoubleFontHeight() const;
  double fntDoubleFontAscent() const;
  double fntDoubleFontDescent() const;
  double fntDoubleFontLeading() const;
  double fntDoubleFontSpacing() const;
  double fntDoubleTextWidth(const FXchar *text,FXuint n) const;
  double fntDoubleTextHeight(const FXchar *text,FXuint n) const;
  };
  
}

#endif

// end of FXDCNativePrinter.h

