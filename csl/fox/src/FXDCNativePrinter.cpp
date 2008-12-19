//
// FXDCNativePrinter.cpp
//
// cf FXDCPrint but this version can use a native WIN32 printer
//    and also provides richer scaling capabilities. It also
//    uses FXPostscriptFont when printing Postscript so that it gets
//    metrics right (at least for the standard 35 fonts).
//
// Contributed to FOX project by Manuel (address@te...) who
// made a deliberate choice not to add a copyright notice, so that
// the code could be added to FOX (and hence released under the FOX
// relaxed version of the LGPL).
//


// Here is a message that he sent in October 2002, and point (c) explains
// that it can be used for any purpose... whihc includes use within a
// larger body of code that is subject to LGPL.

/*
 *I will try to address some of the problems you have (I am the author of the
 *code, btw).
 *
 *a) Portrait/landscape: This is controlled by the FXPrinter you use to
 *initialize printing. You can either let the user choose on the Printing
 *Dialog or just set it with the methods provided by FXPrinter. If you are
 *already doing it and fails, let me know so I can have a deeper look at the
 *problem. There are some examples on the zip file. I suppose you are using
 *printing-release2.zip from the download area at http://www.fox-toolkit.org (just
 *to make sure).
 *
 *b) Local vs Remote printing: I have no access to remote printers, so I
 *couldnt test that. Since you can print, it seems a glitch on the safety
 *checks.
 *
 *c) Including it in FOX: I havent put any copyright notice on the code so it
 *could be used for any purpose. If Jeroen wants to incorporate it or a
 *derivative work, it is fine with me.
 *
 *d) Printing in Linux: On UNIX the class is just a wrapper that provides unit
 *scaling around FXDCPrint. If you never use any scaling other than the
 *default 72x72 ppi, you would have the same effect if you decided using
 *directly FXDCPrint. Look at FOX source code if you want to know how printing
 *is handled by FXDCPrint.
 *
 *Thanks for the feedback,
 *Manuel
 *
 */

// This version worked on by Arthur Norman mainly to make the
// behaviour under Linux more robust, but also to clean up some
// oddities etc. and add bits of functionality. I view this as a derived
// work of FOX and I had intended to explicitly include the FOX addendum
// in the license terms that apply, but the copyright holders of FOX
// have clarified that only they may do that, hence this code has to fall
// under just LGPL, and any changes I have made I release under LGPL 2.1.

/* Signature: 5bd5cfcf 22-May-2008 */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <string.h>
#include <ctype.h>
#include <fx.h>
#include <FXDC.h>
#include <FXDCPrint.h>
#include <FXDCWindow.h>

#include "FXPostscriptFont.h"

//////////////////////////////////////////////////////////////////////////////
// The following implements two minorish patches to the FXDCPrint class
// that make it handle Postscript better for me. I mark the changes
// with "@@@"
//

// define a version of FOX where these patches become unnecessary needed
#define PRINT_MAJOR 1
#define PRINT_MINOR 1
#define PRINT_LEVEL 21

namespace FX {

#if (FOX_MAJOR<PRINT_MAJOR || (FOX_MAJOR==PRINT_MAJOR && \
    (FOX_MINOR<PRINT_MINOR || (FOX_MINOR==PRINT_MINOR && \
    (FOX_LEVEL<PRINT_LEVEL)))))

class FXAPI FXDCPatchedPrint : public FXDCPrint {
public:
  FXDCPatchedPrint(FXApp* a);
  ~FXDCPatchedPrint();
  FXbool beginPage(FXuint page);   // NB not virtual in FXDCPrint
  virtual void drawText(FXint x,FXint y,const FXchar* string,FXuint len);
  };


// Construct
FXDCPatchedPrint::FXDCPatchedPrint(FXApp* a) : FXDCPrint(a){
  }


// Destruct
FXDCPatchedPrint::~FXDCPatchedPrint(){
  }


// Generate begin of page
FXbool FXDCPatchedPrint::beginPage(FXuint page){

  // Output page number
  outf("%%%%Page: %d %d\n",page,page);   // @@@ 2 values after "%%Page:"

  // Reset page bounding box
  if(flags&PRINT_NOBOUNDS){
    pagebb.xmin= 1000000;
    pagebb.xmax=-1000000;
    pagebb.ymin= 1000000;
    pagebb.ymax=-1000000;
    outf("%%%%PageBoundingBox: (atend)\n");
    }

  // Use the doc bounding box
  else{
    pagebb.xmin=docbb.xmin;
    pagebb.xmax=docbb.xmax;
    pagebb.ymin=docbb.ymin;
    pagebb.ymax=docbb.ymax;
    outf("%%%%PageBoundingBox: %d %d %d %d\n",(int)pagebb.xmin,(int)pagebb.ymin,(int)pagebb.xmax,(int)pagebb.ymax);
    }

  // Page setup
  outf("%%%%BeginPageSetup\n");
  outf("%%%%EndPageSetup\n");
  outf("gsave\n");

  // Maybe in landscape?
  if(flags&PRINT_LANDSCAPE){
    outf("%g %g translate\n",mediawidth,0.0);
    outf("90 rotate\n");
    }

  return TRUE;
  }


// Draw string (only foreground bits)
// Contributed by S. Ancelot <sancelot@online.fr>
virtual void FXDCPatchedPrint::drawText(FXint x,FXint y,const FXchar* string,FXuint len){
  FXfloat xx,yy;
  tfm(xx,yy,(FXfloat)x,(FXfloat)y);
  bbox(xx,yy);
  FXFontDesc fontdesc;
  font->getFontDesc(fontdesc);
  outf("gsave /%s findfont\n",font->getName().text());
// @@@ Support fractions of a point in font sizes by using float not int here
  outf("%g scalefont\n",(double)font->getSize()/10.0);
  outf("setfont\n");
  outf("newpath\n%g %g moveto\n(",xx,yy);
  for(FXuint i=0; i<len; i++){
    if(string[i]=='(') outf("\\050");
    else if(string[i]==')') outf("\\051");
    else outf("%c",string[i]);
    }
  outf(") show\n");
  outf("grestore\n");
  }

// The macro here subverts all FXPrintDC instances that follow into
// being the patched variety.

#define FXDCPrint FXDCPatchedPrint

// end of patches to FXDCPrint.

#endif // version check in PRINT_MAJOR, PRINT_MINOR and PRINT_LEVEL

//////////////////////////////////////////////////////////////////////////////


}

#include "FXDCNativePrinter.h"
#include "FXPostscriptFont.h"

namespace FX {

//
// When generating Postscript I need font metrics. These can be extracted
// from "afm" files that Adobe supply. I have a program "get-adobe-metrics.c"
// that can be run on a typical Linux system to extract the (minimal) metric
// information that I need here and build a file "font-info.c". By including
// that file here I collect info about all the standard Postscript Fonts.
// I will not permit a user to use any other fonts than these!
//


#ifdef WIN32
//
// The WIN32 version here works by mapping the printer much as if it
// was a window. A Postscript version will generate Postscript directly
// from the print requests that the user makes.
//
class FXAPI FXPrinterVisual : public FXVisual 
{
public:
    FXPrinterVisual();
    void create() { xid=(void *)1; }
    void detach() { xid=(void *)0; }
    void destroy() { xid=(void *)0; }
    FXPixel getPixel(FXColor clr)
    { return RGB( FXREDVAL(clr), FXGREENVAL(clr), FXBLUEVAL(clr) ); }
    FXColor getColor(FXPixel pix)
    { return FXRGB( GetRValue(pix), GetGValue(pix), GetBValue(pix) ); }
};

FXPrinterVisual::FXPrinterVisual():FXVisual() 
{
    depth=24;
    numred=numgreen=numblue=256;
    numcolors=256*256*256;
    type=(FXVisualType)VISUALTYPE_TRUE;
    xid=(void *)0;
//  hPalette = NULL;  // not available in FOX 1.1.49 and unclear whether needed here anyway!
};

class FXAPI FXPrinterDrawable : public FXDrawable 
{
protected:
    FXID dc;
public:
    FXPrinterDrawable(FXID gc);
    FXPrinterDrawable();
    ~FXPrinterDrawable();
    void SetDC(FXID gc);
    virtual FXID GetDC() const { return (FXID)dc; }
    virtual int ReleaseDC(FXID) const { return 0; }
};

FXPrinterDrawable::~FXPrinterDrawable()
{
    delete visual;
}

FXPrinterDrawable::FXPrinterDrawable()
{
    FXPrinterDrawable(0);
}

FXPrinterDrawable::FXPrinterDrawable(FXID gc) : FXDrawable()
{
    dc = gc;
    visual=new FXPrinterVisual();
    xid=(FXID)1;
}

void FXPrinterDrawable::SetDC(FXID gc)
{
    dc = (HDC)gc;
}

#endif // end of WIN32-specific stuff

// Construct

FXDCNativePrinter::FXDCNativePrinter(FXApp *a):FXDC(a)
{
#ifdef WIN32
    opaque = (FXObject *)NULL;
    dctype=TYPE_WIN32;
#else
    dctype=TYPE_PS;
#endif
#ifdef FONT_NOT_VIRTUAL
    postscriptFont = NULL;
#endif
    pageheight = 0.0;   // report this until the print job starts
    pagewidth = 0.0;
    fontoffset = 0;     // Baseline of font
    fontScaleBack = 1.0;
    fontScale = 1.0;
    PSscale = 1.0;
    logpixelsx = 72;
    logpixelsy = 72;
    scalex = 1.0;
    scaley = 1.0;
    unitsx = 72.0;
    unitsy = 72.0;
    pdc = (FXDC *)NULL;
    pagecount=0;
}


// Destruct

FXDCNativePrinter::~FXDCNativePrinter()
{
}

// Generate print job prolog, return TRUE if all is OK

FXbool FXDCNativePrinter::beginPrint(FXPrinter &job)
{
    pagecount=0;

#ifdef WIN32
// on Windows printing to file uses Postscript but anything direct to
// a printer goes via the Windows drivers.
    if (job.flags&PRINT_DEST_FILE) dctype = TYPE_PS;
    else dctype=TYPE_WIN32;
#else
// On other than WIN32 the only print mode supported is Postscript
    dctype=TYPE_PS;
#endif

    switch (dctype)
    {
#ifdef WIN32
case TYPE_WIN32:
        devmode_handle=0;
        FXPrinterDrawable *prn;
// TODO: Paper size
        memset(&devmode, 0, sizeof(devmode));
        devmode.dmFields = DM_ORIENTATION | DM_COLOR;
        devmode.dmSize = sizeof(devmode);
        devmode.dmOrientation = (job.flags&PRINT_LANDSCAPE) ?
                                DMORIENT_LANDSCAPE : DMORIENT_PORTRAIT;
        devmode.dmColor = (job.flags&PRINT_COLOR) ?
                          DMCOLOR_COLOR : DMCOLOR_MONOCHROME;
        char devicename[256];
// Note: Under Win 9x/ME   "WINSPOOL" should be replaced by NULL,
//       but this seems to work anyway!
        strcpy(devicename, job.name.text());
        dc = CreateDC("WINSPOOL", devicename, NULL, &devmode);
        if (dc==(HANDLE)NULL) return FALSE;

// Initialize the members of a DOCINFO structure.
        memset((void *)&di, 0, sizeof(di));
        di.cbSize = sizeof(DOCINFO);
        di.lpszDocName = "Document";  // FIXME: API to support document name?
        di.lpszOutput = (LPTSTR) NULL;
        di.fwType = 0;

// Start document
        if (::StartDoc(dc, &di)==SP_ERROR)
        {   ::DeleteDC(dc);
            dc=0;
            return FALSE;
        }

        SetMapMode(dc, MM_TEXT);

// get pixels per inch, usually 600x600 or 300x300
        logpixelsy = ::GetDeviceCaps(dc, LOGPIXELSY);
        logpixelsx = ::GetDeviceCaps(dc, LOGPIXELSX);
#ifdef OLD
        fontScale = logpixelsy / 96.0;
        fontScaleBack = 96.0 / logpixelsy;
#else
// The font size I need to create under Windows will be related to the
// pixel-pitch on my output device. My reading of the Windows documentation
// is that the scaling shown here is what is wanted, but the alternative
// scaling by 96 not 72 was present in the original code so I leave it as
// a comment for now in case there is something I do not understand.
        fontScale = logpixelsy / 72.0;
        fontScaleBack = 72.0 / logpixelsy;
#endif
        setHorzUnitsInch(72.0);
        setVertUnitsInch(72.0);

// Create drawable
        prn = new FXPrinterDrawable((FXID)dc);
        opaque= (FXObject *)prn;
        FXdouble dx, dy;
        dx = (FXdouble)job.mediawidth;
        dy = (FXdouble)job.mediaheight;
        if (job.flags&PRINT_LANDSCAPE)
        {   FXdouble kk=dx;
            dx=dy;
            dy=kk;
        }
        pageheight = dy * scaley;   /* Store size in pixels */
        pagewidth = dx * scalex;
        prn->resize( (FXint)(scalex * dx) , (FXint)(scaley * dy) );
// Create a WIN32 FXDC from our drawable
        pdc = (FXDC *)new FXDCWindow(prn);
        SetTextAlign(dc, TA_TOP|TA_LEFT); // TA_BASLINE fails in some printers
        pdc->setForeground(FXRGB(0,0,0));
        pdc->setBackground(FXRGB(255,255,255));
        return TRUE;
#endif

default:      // case TYPE_PS:
// Postscript printing delegates to the existing FXDCPrint class.
//  But note that until metric-returning things in FXFont are virtual
//  I have a HACK whenever I extract measurements here.
        pdc = (FXDC *)new FXDCPrint(getApp());
        if (((FXDCPrint *)pdc)->beginPrint(job) == 0) return FALSE;
        logpixelsx = 72;
        logpixelsy = 72;
        scalex = 1.0;
        scaley = 1.0;
        PSscale = 0.001;  // see usage later on for explanation
// There is an uncertainty here about who is supposed to be
// responsible for margins. The FXPrinter that I was passed has
// given me some suggestions but I ignore them here! What is done here
// is at least compatible with what is done in the WIN32 case.
        pagewidth = (FXfloat)job.mediawidth;
        pageheight = (FXfloat)job.mediaheight;
        if (job.flags&PRINT_LANDSCAPE)
        {   FXdouble kk=pagewidth;
            pagewidth=pageheight;
            pageheight=kk;
        }
// The following 2 lines may not be needed for Postscript printing but
// are harmless anyway.
        pdc->setForeground(FXRGB(0,0,0));
        pdc->setBackground(FXRGB(255,255,255));
        return TRUE;
    }
}

// Generate print job epilog

FXbool FXDCNativePrinter::endPrint()
{
    switch (dctype)
    {
#ifdef WIN32
case TYPE_WIN32:      // End of Document
        if (dc!=0)
        {   ::EndDoc(dc);
            FXDCWindow *pd=(FXDCWindow *)pdc;
            delete pd;
            FXPrinterDrawable *prn=(FXPrinterDrawable *)opaque;
            delete prn;
            ::DeleteDC(dc);
            dc=0;
            opaque=(FXObject *)NULL;
            pdc=(FXDC*)NULL;
        }
        return 1;
#endif
default:              // case TYPE_PS:
        FXDCPrint *pd=(FXDCPrint *)pdc;
        FXbool v=pd->endPrint();
        delete pd;
        pdc=(FXDC *)NULL;
        return v;
    }
}

// Generate begin of page

FXbool FXDCNativePrinter::beginPage(FXuint page)
{
    switch (dctype)
    {
#ifdef WIN32
case TYPE_WIN32:
        if (::StartPage(dc)<=0)
        {   endPrint();
            return 0;
        }
        return 1;
#endif
default:                  // case TYPE_PS:
// Note that if I had to apply my patch then it gets activated here.
        FXDCPrint *pd=(FXDCPrint *)pdc;
        return pd->beginPage(page);
    }
}

// Generate end of page

FXbool FXDCNativePrinter::endPage()
{
    switch (dctype)
    {
#ifdef WIN32
case TYPE_WIN32:
        ::EndPage(dc);
        pagecount++;
        return TRUE;
#endif
default:                  // case TYPE_PS:
        FXDCPrint *pd=(FXDCPrint *)pdc;
        return pd->endPage();
    }
}

// Draw a point in the current pen color

void FXDCNativePrinter::drawPoint(FXint x, FXint y)
{
    pdc->drawPoint(ScaleX(x), ScaleY(y));
}

// I need an array of points, arcs, rectangles into which I can scale things.
// By keeping a single array here I can extend it by need in a reasonably
// tidy way.

static void *dst = NULL;
static int dst_buffer_size = 0;
#define DST_BUFFER_INCREMENT 128

static void check_dst_buffer(int n, int sz)
{
    int len = n*sz;
    if (dst_buffer_size >= len) return;
    if (dst_buffer_size!=0) free((void *)dst);
// I keep the buffer size a multiple of 128 bytes, and any time I have to
// extend it I round up the needed size to a multiple of that.
    dst_buffer_size = len + (DST_BUFFER_INCREMENT - len%DST_BUFFER_INCREMENT);
    void *p = (void *)malloc(len);
// my treatment of failure here is somewhat abrupt, and perhaps I should
// just do less drawing. But for now I intend to be fierce on this count.
    if (p == NULL)
    {   fprintf(stderr, "Fatal error: ran out of memory\n");
        exit(1);
    }
    dst = p;
}

// Draw points in the current pen color.
// Each point's position is relative to the drawable's origin (as usual).

void FXDCNativePrinter::drawPoints(const FXPoint* points,FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->drawPoints((FXPoint *)dst, npoints);
}

// Draw points in the current pen color. The first point's position is
// relative to the drawable's origin, but each subsequent point's position
// is relative to the previous point's position; each FXPoint defines
// the relative coordinates. Think LOGO.

void FXDCNativePrinter::drawPointsRel(const FXPoint*points,FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->drawPointsRel((FXPoint *)dst, npoints);
}

// Draw a line

void FXDCNativePrinter::drawLine(FXint x1, FXint y1, FXint x2, FXint y2)
{
    pdc->drawLine(ScaleX(x1), ScaleY(y1), ScaleX(x2), ScaleY(y2));
}

// Draw multiple lines. All points are drawn connected.
// Each point is specified relative to Drawable's origin.

void FXDCNativePrinter::drawLines(const FXPoint* points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->drawLines((FXPoint *)dst, npoints);
}

// Draw multiple lines. All points are drawn connected.
// First point's coordinate is relative to drawable's origin, but
// subsequent points' coordinates are relative to previous point.

void FXDCNativePrinter::drawLinesRel(const FXPoint* points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->drawLinesRel((FXPoint *)dst, npoints);
}

// Draw unconnected line segments

void FXDCNativePrinter::drawLineSegments(const FXSegment* segments, FXuint nsegments)
{
    check_dst_buffer(nsegments, sizeof(FXSegment));
    scaleSegments((FXSegment *)dst, (FXSegment *)segments, nsegments);
    pdc->drawLineSegments((FXSegment *)dst, nsegments);
}

// Draw unfilled rectangle

void FXDCNativePrinter::drawRectangle(FXint x, FXint y, FXint w, FXint h)
{
    pdc->drawRectangle(ScaleX(x), ScaleY(y), ScaleX(w), ScaleY(h));
}

// Draw unfilled rectangles

void FXDCNativePrinter::drawRectangles(const FXRectangle* rectangles,FXuint nrectangles)
{
    check_dst_buffer(nrectangles, sizeof(FXRectangle));
    scaleRectangles((FXRectangle *)dst, (FXRectangle *)rectangles, nrectangles);
    pdc->drawRectangles((FXRectangle *)dst, nrectangles);
}

// Draw arc

void FXDCNativePrinter::drawArc(FXint x, FXint y, FXint w,
                                FXint h, FXint ang1, FXint ang2)
{
    pdc->drawArc(ScaleX(x), ScaleY(y), ScaleX(w), ScaleY(h), ang1, ang2);
}

// Draw arcs

void FXDCNativePrinter::drawArcs(const FXArc* arcs,FXuint narcs)
{
    check_dst_buffer(narcs, sizeof(FXArc));
    scaleArcs((FXArc *)dst, (FXArc *)arcs, narcs);
    pdc->drawArcs((FXArc *)dst, narcs);
}

// Filled rectangle

void FXDCNativePrinter::fillRectangle(FXint x, FXint y, FXint w, FXint h)
{
    pdc->fillRectangle(ScaleX(x), ScaleY(y), ScaleX(w), ScaleY(h));
}

// Filled rectangles

void FXDCNativePrinter::fillRectangles(const FXRectangle* rectangles,
                                       FXuint nrectangles)
{
    check_dst_buffer(nrectangles, sizeof(FXRectangle));
    scaleRectangles((FXRectangle *)dst, (FXRectangle *)rectangles, nrectangles);
    pdc->fillRectangles((FXRectangle *)dst, nrectangles);
}

// Fill arc

void FXDCNativePrinter::fillArc(FXint x, FXint y, FXint w,
                                FXint h, FXint ang1, FXint ang2)
{
    pdc->fillArc(ScaleX(x), ScaleY(y), ScaleX(w), ScaleY(h), ang1, ang2);
}


// Fill arcs

void FXDCNativePrinter::fillArcs(const FXArc *arcs, FXuint narcs)
{
    check_dst_buffer(narcs, sizeof(FXArc));
    scaleArcs((FXArc *)dst, (FXArc *)arcs, narcs);
    pdc->fillArcs((FXArc *)dst, narcs);
}

// Filled simple polygon

void FXDCNativePrinter::fillPolygon(const FXPoint* points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->fillPolygon((FXPoint *)dst, npoints);
}

// Fill concave polygon

void FXDCNativePrinter::fillConcavePolygon(const FXPoint *points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->fillConcavePolygon((FXPoint *)dst, npoints);
}

// Fill complex (self-intersecting) polygon

void FXDCNativePrinter::fillComplexPolygon(const FXPoint *points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->fillComplexPolygon((FXPoint *)dst, npoints);
}


// Filled simple polygon with relative points

void FXDCNativePrinter::fillPolygonRel(const FXPoint *points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->fillPolygonRel((FXPoint *)dst, npoints);
}

// Fill concave polygon

void FXDCNativePrinter::fillConcavePolygonRel(const FXPoint *points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->fillConcavePolygonRel((FXPoint *)dst, npoints);
}

// Fill complex (self-intersecting) polygon

void FXDCNativePrinter::fillComplexPolygonRel(const FXPoint *points, FXuint npoints)
{
    check_dst_buffer(npoints, sizeof(FXPoint));
    scalePoints((FXPoint *)dst, (FXPoint *)points, npoints);
    pdc->fillComplexPolygonRel((FXPoint *)dst, npoints);
}

// Draw string (only foreground bits)

void FXDCNativePrinter::drawText(FXint x, FXint y,
                                 const FXchar *string, FXuint len)
{
/* TA_BASELINE does not work reliably with printers, so we need to adjust by hand */
    pdc->drawText(ScaleX(x), ScaleY(y)-fontoffset, string, len);
}

// Draw string (both foreground and background bits)

void FXDCNativePrinter::drawImageText(FXint x, FXint y,
                                      const FXchar*string,FXuint len)
{
    pdc->drawImageText(ScaleX(x), ScaleY(y)-fontoffset, string, len);
}

// Draw area from source

void FXDCNativePrinter::drawArea(const FXDrawable *source,
                                 FXint sx, FXint sy, FXint sw, FXint sh,
                                 FXint dx, FXint dy)
{
    pdc->drawArea(source, sx, sy, sw, sh, ScaleX(dx), ScaleY(dy));
}

// Draw image

void FXDCNativePrinter::drawImage(const FXImage *img, FXint dx, FXint dy)
{
    pdc->drawImage(img, ScaleX(dx), ScaleY(dy));
}

// Draw bitmap

void FXDCNativePrinter::drawBitmap(const FXBitmap *bitmap, FXint dx, FXint dy)
{
    pdc->drawBitmap(bitmap, ScaleX(dx), ScaleY(dy));
}


// Draw icon

void FXDCNativePrinter::drawIcon(const FXIcon *icon, FXint dx, FXint dy)
{
    pdc->drawIcon(icon, ScaleX(dx), ScaleY(dy));
}

// Draw icon shaded

void FXDCNativePrinter::drawIconShaded(const FXIcon *icon, FXint dx, FXint dy)
{
    pdc->drawIconShaded(icon, ScaleX(dx), ScaleY(dy));
}

// Draw icon sunken

void FXDCNativePrinter::drawIconSunken(const FXIcon *icon, FXint dx, FXint dy)
{
    pdc->drawIconSunken(icon, ScaleX(dx), ScaleY(dy));
}

// Draw hashed box

void FXDCNativePrinter::drawHashBox(FXint x, FXint y, FXint w, FXint h,
                                    FXint b)
{
  // FIXME: Scaling border by horizontal resolution,
  // what when logpixelsx != logpixelsy ??
    pdc->drawHashBox(ScaleX(x), ScaleY(y), ScaleX(w), ScaleY(h), ScaleX(b));
}

// Set foreground drawing color (brush)

void FXDCNativePrinter::setForeground(FXColor clr)
{
    pdc->setForeground(clr);
}

// Set background drawing color (brush)

void FXDCNativePrinter::setBackground(FXColor clr)
{
    pdc->setBackground(clr);
}

// Set dash pattern

void FXDCNativePrinter::setDashes(FXuint dashoffset, const FXchar *dashpattern, FXuint dashlength)
{
    pdc->setDashes(dashoffset, dashpattern, dashlength);
}

// Set line width

void FXDCNativePrinter::setLineWidth(FXuint linewidth)
{
    // FIXME: Scaling by X resolution, what if Xdpi != Ydpi ????
    pdc->setLineWidth(ScaleX(linewidth));
}

// Set line cap style

void FXDCNativePrinter::setLineCap(FXCapStyle capstyle)
{
    pdc->setLineCap(capstyle);
}

// Set line join style

void FXDCNativePrinter::setLineJoin(FXJoinStyle joinstyle)
{
    pdc->setLineJoin(joinstyle);
}

// Set line style

void FXDCNativePrinter::setLineStyle(FXLineStyle linestyle)
{
    pdc->setLineStyle(linestyle);
}

// Set fill style

void FXDCNativePrinter::setFillStyle(FXFillStyle fillstyle)
{
    pdc->setFillStyle(fillstyle);
}

// Set fill rule

void FXDCNativePrinter::setFillRule(FXFillRule fillrule)
{
    pdc->setFillRule(fillrule);
}

// Set blit function

void FXDCNativePrinter::setFunction(FXFunction func)
{
    pdc->setFunction(func);
}

// Set tile image

void FXDCNativePrinter::setTile(FXImage *image, FXint dx, FXint dy)
{
    pdc->setTile(image, dx, dy);  // TODO: Check if dx,dy should be scaled
}

// Set stipple pattern

void FXDCNativePrinter::setStipple(FXBitmap *bitmap, FXint dx, FXint dy)
{
    pdc->setStipple(bitmap, dx, dy); // TODO: Check if dx,dy should be scaled
}

// Set stipple pattern

void FXDCNativePrinter::setStipple(FXStipplePattern pat, FXint dx, FXint dy)
{
    pdc->setStipple(pat, dx, dy); // TODO: Check if dx,dy should be scaled
}

// Set clip rectangle

void FXDCNativePrinter::setClipRectangle(FXint x, FXint y, FXint w, FXint h)
{
    pdc->setClipRectangle(ScaleX(x), ScaleY(y), ScaleX(w), ScaleY(h));
}

// Set clip rectangle

void FXDCNativePrinter::setClipRectangle(const FXRectangle &rectangle)
{
    pdc->setClipRectangle(ScaleX(rectangle.x), ScaleY(rectangle.y),
                          ScaleX(rectangle.w), ScaleY(rectangle.h));
}

// Clear clipping

void FXDCNativePrinter::clearClipRectangle()
{
    pdc->clearClipRectangle();
}

// Set clip mask

void FXDCNativePrinter::setClipMask(FXBitmap *bitmap, FXint dx, FXint dy)
{
    pdc->setClipMask(bitmap, dx, dy);  // TODO: Check if dx,dy should be scaled
}

// Clear clip mask

void FXDCNativePrinter::clearClipMask()
{
    pdc->clearClipMask();
}

// Set font to draw text with

void FXDCNativePrinter::setFont(FXFont *fnt)
{
    font=fnt;
#if FOX_MAJOR==1 && FOX_MINOR==0
    pdc->setTextFont(fnt);
#else
    pdc->setFont(fnt);
#endif
    fontoffset=0;
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) postscriptFont = (FX::FXPostscriptFont *)font;
#endif
    if (dctype==TYPE_WIN32) fontoffset = font->getFontAscent();
}

// Change clip-against-child windows mode

void FXDCNativePrinter::clipChildren(FXbool yes)
{
   // Do nothing
}

//
// Now the helper code that scales vectors of stuff for me.
//

void FXDCNativePrinter::scalePoints(FXPoint *dst, FXPoint *src, FXuint npoints)
{
    for (;npoints>0;npoints--,dst++,src++)
    {   dst->x = ScaleX(src->x);
        dst->y = ScaleY(src->y);
    }
}

void FXDCNativePrinter::scaleRectangles(FXRectangle *dst, FXRectangle *src, FXuint nrectangles)
{
    for (;nrectangles>0;nrectangles--,dst++,src++)
    {   dst->x = ScaleX(src->x);
        dst->y = ScaleY(src->y);
        dst->w = ScaleX(src->w);
        dst->h = ScaleY(src->h);
    }
}

void FXDCNativePrinter::scaleSegments(FXSegment *dst, FXSegment *src, FXuint nsegments)
{
    for (;nsegments>0;nsegments--,dst++,src++)
    {   dst->x1 = ScaleX(src->x1);
        dst->y1 = ScaleY(src->y1);
        dst->x2 = ScaleX(src->x2);
        dst->y2 = ScaleY(src->y2);
    }
}

void FXDCNativePrinter::scaleArcs(FXArc *dst, FXArc *src, FXuint narcs)
{
    for (;narcs>0;narcs--,dst++,src++)
    {   dst->x = ScaleX(src->x);
        dst->y = ScaleY(src->y);
        dst->w = ScaleX(src->w);
        dst->h = ScaleY(src->h);
        dst->a = src->a;
        dst->b = src->b;
    }
}


void FXDCNativePrinter::setHorzUnitsInch(FXfloat sx)
{
    scalex = logpixelsx / sx;
    unitsx = sx;
}

void FXDCNativePrinter::setVertUnitsInch(FXfloat sy)
{
    scaley = logpixelsy / sy;
    unitsx = sy;
}

// Create a font, paying attention to the scaling currently in force.

FXFont *FXDCNativePrinter::fntGenerateFont(const FXString &face,
    FXuint sz, FXuint wt, FXuint sl, FXuint enc, FXuint setw, FXuint h)
{
    return fntDoubleGenerateFont(face, (double)sz, wt, sl, enc, setw, h);
}

// The next version takes the desired point size as a double not an
// int. Because windows printer fonts actually exist at pixel-size based on
// printer resolution they can exist in visible sizes that vary much
// more finely than integer point sizes would allow one to express. And
// both with Postscript and Truetype fonts utterly arbitrary scaling
// can be applied. With Postscript my font's size will be specified
// internally in decipoints so at least we can have sizes 5.1, 5.2, 5.3 etc.

FXFont *FXDCNativePrinter::fntDoubleGenerateFont(const FXString &face,
    double sz, FXuint wt, FXuint sl, FXuint enc, FXuint setw, FXuint h)
{
    if (dctype == TYPE_WIN32)
        return new FXFont(getApp(), face, (int)(sz * fontScale), wt,
                          sl, enc, setw, h);
    else  // otherwise I am to generate Postscript
    {   FXFontDesc fdd;
        memset((void *)&fdd, 0, sizeof(fdd));
        strcpy(fdd.face, face.text());
// The whole purpose of constructing via FXFontDesc is to give size in
// decipoints not points. I can not use the fontScale trick here without
// re-working how FXDCPrint prints things...
        fdd.size = (int)(10.0*sz + 0.5);
        fdd.weight = wt;
        fdd.slant = sl;
        fdd.encoding = enc;
        fdd.setwidth = setw;
        fdd.flags = h;
// the explicit FX:: on the next line is needed to allow this code to
// compile using both FOX 1.0 and FOX 1.1!!!
        return new FX::FXPostscriptFont(getApp(), fdd);
    }
}

//
// Most of the stuff that follows is just delegating actions to an
// underlying DC, possibly applying scaling. The scaling is so that the
// user can select the (integer-based) unit of measurement... in some cases
// the default unit of 1pt (= 1/72in here) would be too coarse. It is
// STRONGLY suggested that anybody changing units should use the same
// ones for both X and Y, since otherwise indicating sizes for values
// not keyed to axis direction (eg line width) gets very questionable indeed.
// I think maybe the API would be safer with just a single scaling option
// not two.  Note also that font sizes are always specified in points
// regardless of other options being set.

FXString FXDCNativePrinter::fntGetName()
{
// the font-name returned will be the full Postscript font name. Handing it
// back to try to create a new font will NOT be a good idea, since it has
// Bold and Italic/Oblique info muddled up in it.
    return font->getName();
}

FXuint FXDCNativePrinter::fntGetSize()
{
// NOTE that this returns the size in decipoints not points.
    return (FXuint)(fontScaleBack * (FXfloat)font->getSize());
}

// return font size (in points) as a double not an integer, so that
// fractional point sizes can be handled better.

double FXDCNativePrinter::fntDoubleSize()
{
// NOTE that this returns the size in decipoints not points.
    return (double)(fontScaleBack * (FXfloat)font->getSize());
}

FXuint FXDCNativePrinter::fntGetWeight()
{
    return font->getWeight();
}

FXuint FXDCNativePrinter::fntGetSlant()
{
    return font->getSlant();
}

FXuint FXDCNativePrinter::fntGetEncoding()
{
    return font->getEncoding();
}

FXuint FXDCNativePrinter::fntGetSetWidth()
{
    return font->getSetWidth();
}

FXuint FXDCNativePrinter::fntGetHints()
{
    return font->getHints();
}

void FXDCNativePrinter::fntGetFontDesc(FXFontDesc &fontdesc) const
{
    font->getFontDesc(fontdesc);
}

void FXDCNativePrinter::fntSetFontDesc(const FXFontDesc &fontdesc)
{
    font->setFontDesc(fontdesc);
}

FXbool FXDCNativePrinter::fntIsFontMono() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return postscriptFont->isFontMono();
#endif
    return font->isFontMono();
}

FXbool FXDCNativePrinter::fntHasChar(FXint ch) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return postscriptFont->hasChar(ch);
#endif
    return font->hasChar(ch);
}

FXint FXDCNativePrinter::fntGetMinChar() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return postscriptFont->getMinChar();
#endif
    return (FXint)font->getMinChar();
}

FXint FXDCNativePrinter::fntGetMaxChar() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return postscriptFont->getMaxChar();
#endif
    return (FXint)font->getMaxChar();
}

//
// There is a big ugly issue about fonts and measurements here. For Windows
// fonts will have been created internally at some huge point size based
// on the actual resolution of the printer. The factor scalex includes
// allowance for that and so enough precision is kept.
// For Postscript generation the font thinks (at an internal level) that
// it is the point size you actually want it to appear at. The effect is
// that character heights and widths are often quite small values (eg
// for a 10pt pont they are comparable with 10. Returning measurements as
// integers in such a case would give severe truncation effects.
// To work around this I arrange that the FXPostScriptFont class returns
// font measurements scaled by 1000. I have to undo this here. The
// multiplication by PSscale is to do that.
//

// For Postscript generation (and on X) the bearings that I return will be
// the maximum values across the font.

FXint FXDCNativePrinter::fntLeftBearing(FXchar ch) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->leftBearing(ch) / scalex);
#endif
    return (FXint)(PSscale * font->leftBearing(ch) / scalex);
}

double FXDCNativePrinter::fntDoubleLeftBearing(FXchar ch) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->leftBearing(ch) / scalex);
#endif
    return (double)(PSscale * font->leftBearing(ch) / scalex);
}

FXint FXDCNativePrinter::fntRightBearing(FXchar ch) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->rightBearing(ch) / scalex);
#endif
    return (FXint)(PSscale * font->rightBearing(ch) / scalex);
}

double FXDCNativePrinter::fntDoubleRightBearing(FXchar ch) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->rightBearing(ch) / scalex);
#endif
    return (double)(PSscale * font->rightBearing(ch) / scalex);
}

//
// If one has left the UnitsInch at its default of 72 then
// measurements are only precise to 1pt. This is generally not good
// enough when laying out a line. To get better accuracy you can either
// reset your units to say 1/3600in or use floating point values here.
//

FXint FXDCNativePrinter::fntGetFontWidth() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getFontWidth() / scalex);
#endif
    return (FXint)(PSscale * font->getFontWidth() / scalex);
}

double FXDCNativePrinter::fntDoubleFontWidth() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getFontWidth() / scalex);
#endif
    return (double)(PSscale * font->getFontWidth() / scalex);
}

FXint FXDCNativePrinter::fntGetFontHeight() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getFontHeight() / scaley);
#endif
    return (FXint)(PSscale * font->getFontHeight() / scaley);
}

double FXDCNativePrinter::fntDoubleFontHeight() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getFontHeight() / scaley);
#endif
    return (double)(PSscale * font->getFontHeight() / scaley);
}

FXint FXDCNativePrinter::fntGetFontAscent() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getFontAscent() / scaley);
#endif
    return (FXint)(PSscale * font->getFontAscent() / scaley);
}

double FXDCNativePrinter::fntDoubleFontAscent() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getFontAscent() / scaley);
#endif
    return (double)(PSscale * font->getFontAscent() / scaley);
}

FXint FXDCNativePrinter::fntGetFontDescent() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getFontDescent() / scaley);
#endif
    return (FXint)(PSscale * font->getFontDescent() / scaley);
}

double FXDCNativePrinter::fntDoubleFontDescent() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getFontDescent() / scaley);
#endif
    return (double)(PSscale * font->getFontDescent() / scaley);
}

FXint FXDCNativePrinter::fntGetFontLeading() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getFontLeading() / scaley);
#endif
    return (FXint)(PSscale * font->getFontLeading() / scaley);
}

double FXDCNativePrinter::fntDoubleFontLeading() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getFontLeading() / scaley);
#endif
    return (FXint)(PSscale * font->getFontLeading() / scaley);
}

FXint FXDCNativePrinter::fntGetFontSpacing() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getFontSpacing() / scaley);
#endif
    return (FXint)(PSscale * font->getFontSpacing() / scaley);
}

double FXDCNativePrinter::fntDoubleFontSpacing() const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getFontSpacing() / scaley);
#endif
    return (double)(PSscale * font->getFontSpacing() / scaley);
}

FXint FXDCNativePrinter::fntGetTextWidth(const FXchar *text, FXuint n) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getTextWidth(text, n) / scalex);
#endif
    return (FXint)(PSscale * font->getTextWidth(text, n) / scalex);
}

double FXDCNativePrinter::fntDoubleTextWidth(const FXchar *text, FXuint n) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getTextWidth(text, n) / scalex);
#endif
    return (double)(PSscale * font->getTextWidth(text, n) / scalex);
}

FXint FXDCNativePrinter::fntGetTextHeight(const FXchar *text, FXuint n) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (FXint)(PSscale * postscriptFont->getTextHeight(text, n) / scaley);
#endif
    return (FXint)(PSscale * font->getTextHeight(text, n) / scaley);
}

double FXDCNativePrinter::fntDoubleTextHeight(const FXchar *text, FXuint n) const
{
#ifdef FONT_NOT_VIRTUAL
    if (dctype==TYPE_PS) return (double)(PSscale * postscriptFont->getTextHeight(text, n) / scaley);
#endif
    return (double)(PSscale * font->getTextHeight(text, n) / scaley);
}

FXint FXDCNativePrinter::getPageWidth(void)
{
    return (FXint)(pagewidth / scalex);
}

double FXDCNativePrinter::doublePageWidth(void)
{
    return (double)(pagewidth / scalex);
}

FXint FXDCNativePrinter::getPageHeight(void)
{
    return (FXint)(pageheight / scaley);
}

double FXDCNativePrinter::doublePageHeight(void)
{
    return (double)(pageheight / scaley);
}

}

// end of FXDCNativePrinter.cpp
