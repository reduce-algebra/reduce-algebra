// wxdemo.cpp

// A sample wxWidgets application.
//

/**************************************************************************
 * Copyright (C) 2010-2025, Codemist.                    A C Norman       *
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

// This code is a small demonstration of what wxWidgets can do - but MOSTLY
// it is looking at the issues of placing characters precisely on the screen
// at various sizes.
//
// The expected output is a lilac screen.
// There is a sort of logo (taken from the wxWidgets documentation) at the
// top left. Then there are two large chunks of text which are notionally
// 1/3 and 2/3 of the way up the screen, and each underlined. They are
// positioned horizontally in a balanced way.

// The upper "Welcome to wxWidgets" is on a thin red line and has its first
// for characters overprinted with red punctuation (to test and demonstrate
// overprinting). It was produced using a wxWidgets font directly and simply.
// The lower "Welcome" was generated by creating a 3-point font and setting
// wxWidgets to scale everything up by a large factor. One could fear that
// this would lead to blocky illegible characters, but it appears that on the
// platforms I have tested letter shapes are rendered at the size they are to
// be displayed. However on Windows and Linux the placement of every character
// will be forced to a whole number of pixels in the 3-point scale, and
// so in fact to a multiple of 12 pixels in the final display. This can mess
// with  inter-character spacing and hence how well the text is centred on
// the line. Observe the (green) underlining is thick because if has been
// scaled up. Also how the thick green line and the text do not end up
// aligned the same way relative to each other on different platforms.
//
// Then there are (up to) three double lines of small letters. Each has a row
// of "e" then a row of "m". The top one uses wxGraphicsContext where placement
// and the like can be specified using floating point. The middle one uses
// a 60-point font scaled down to 10 points using the ordinary facilities
// of wxDC. The lower one first renders characters onto bitmaps at high
// resolution then shrinks that and in doing so achieves a form of anti-
// aliasing and sub-pixel placement of characters, but at the cost of being
// slower and of having the rendering utterly unaware of the display's pixel
// layout (hence characters may tend to end up blurred somewhat).

// This is what I observe on various platforms:
//
// (1) Windows: The top line using wxGraphicsContext can not be generated
//     without an ACN private extension to wxWidgets -- and so that strategy
//     will only be good if it ends up yielding a much better display
//     or running significantly faster than the other options. The issue
//     that causes delicacy is supporting custom application-specific fonts
//     with GdiPlus. I have also had some trouble with crashes when the
//     application terminates.
//     (a) The GraphicsContext characters are well-formed but both horizontal
//         and veritical character placement click to pixel positions on the
//         screen. The effect is that the row "mmmmm" shows a pair of letters
//         unduly close together every so often, and the changes in vertical
//         position have a stepped effect.
//     (b) The direct use of characters scaled down by wxWidgets in a normal
//         device context suffer similar spacing issues but also have much
//         less well-formed characters. In particular the cross-bar of the
//         letters "e" is perhaps rather thin and in pretty well every case
//         it ends up invisible. This is the worst of the three options.
//     (c) With my own anti-aliasing the characters end up lighter and perhaps
//         fuzzier than for (a), but when you step back the shapes and
//         placement are respectable.
// I do have an issue I need to note about antialiasing in this way. For some
// big delimiters I will be building up (eg) a huge "{" out of top and
// bottom hooks, a middle piece and some extension chunks. If I anti-alias
// the ends of the glyphs where they are expected to join and then write
// stuff to the output the result will be bad. So I may need to assemble
// the whole delimiter and anti-alias it as a single unit. There is perhaps
// a similar issue with rules.
//
// (2) X11: The notes here are based on a test using cygwin and X11. The
//     display shows (a) and (b) both with crisp well-formed characters,
//     but both with irregular spacing because of target-space quantization.
//     They do not slip pixels in the same place, but both suffer the same way.
//     The software anti-aliased version comes out noticably lighter on
//     the screen, but as before has good positioning.
//
// (3) Macintosh: Version (a) via a wxGraphicsWindow looks to me like good
//     horizontal character placement but steppy vertical positioning. Version
//     (b) with the simplest code looks identical (or at least very similar)
//     so again horizontally there is sub-pixel positioning but vertically
//     there is not. With my own anti-aliasing the characters are no worse
//     than on Windows or Linux, but are significantly less good than the
//     versions that the Mac can draw for itself. Another difference arises
//     because (I think) the Mac is probably thinking in terms of 72 dpi
//     and Windows in terms of 96 dpi. So when I ask for a "36 point" font
//     I end up with noticably different sizes. The issues of pixel counts,
//     default wxWidgets coordinate units and "point sizes" for fonts
//     seems to be a real can of worms. And the Macbook I am testing on has
//     a "retina" display so has more pixels to play with. which tends to
//     improve the appearance (by the application of brute force).
//     It is possible that my own anti-aliasing on the Mac is suffering
//     because with their higher resolution display I am not over-sampling
//     by anything like as large a factor as I had perhaps planned to?
//

// Having looked at other images that I have rescaled (using method (a),
// i.e. a scaled wxGraphicsContext, I see some on-screen effects that are
// really rather bad when I try to render mathematics. Specifically when I
// draw a tall delimiter using multiple glyphs patched together at some
// scales the different parts of the tower can end up with their edges
// offset from each other horizontally by one pixel (I certainly see that
// using both Windows and X11). The effect is that what should be a vertical
// stroke that would be (say) 3 pixels wide ends up ragged and really noticably
// ugly.


#include "wxfwin.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/dcgraph.h"

#if !defined __WXMSW__ && !defined __WXPM__
#include "fwin.xpm" // Icon to use in non-Windows cases
#endif

int main(int argc, const char *argv[])
{   find_program_directory(argv[0]);
    add_custom_fonts();
    display_font_information();
    wxEntry(argc, (char **)argv);
}

class wxDemo : public wxApp
{
public:
    virtual bool OnInit();
};

class DemoFrame : public wxFrame
{
public:
    DemoFrame(const wxString& title);

    void OnQuit(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);

private:
    DECLARE_EVENT_TABLE()
};

enum
{   ACN_Quit = wxID_EXIT,
    ACN_About = wxID_ABOUT
};

BEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(ACN_Quit,  DemoFrame::OnQuit)
    EVT_PAINT(          DemoFrame::OnPaint)
END_EVENT_TABLE()


IMPLEMENT_APP_NO_MAIN(wxDemo)

static wxFont *ff1 = nullptr;
static wxFont *ff2 = nullptr;
static wxFont *ff3 = nullptr;

#define FONTSIZE1 36
#define FONTSIZE2  3
#define FONTSIZE3 60

#define SCALE ((double)FONTSIZE1/(double)FONTSIZE2)

#define WIDTH    600
#define HEIGHT   400

bool wxDemo::OnInit()
{   ::wxInitAllImageHandlers();
    wxFontInfo ffi;
    ffi.FaceName("cslSTIXMath");
    ff1 = new wxFont(ffi);
    ff1->SetPointSize(FONTSIZE1);
    ff2 = new wxFont(ffi);
    ff2->SetPointSize(FONTSIZE2);
    ff3 = new wxFont(ffi);
    ff3->SetPointSize(FONTSIZE3);
#if defined WIN64
#define name "wxdemo (win64)"
#elif defined WIN32
#define name "wxdemo (win32)"
#elif defined __CYGWIN32__
#define name "wxdemo (32-bit cygwin)"
#elif defined __CYGWIN__
#define name "wxdemo (64-bit cygwin)"
#elif defined __linux__ && defined __amd64
#define name "wxdemo (64-bit linux)"
#elif defined __linux
#define name "wxdemo (linux)"
#elif defined __APPLE__
#define name "wxdemo (Macintosh)"
#elif defined unix
#define name "wxdemo (Unix)"
#else
#define name "wxdemo"
#endif
    DemoFrame *frame = new DemoFrame(name);
    frame->Show(true);
    return true;
}

DemoFrame::DemoFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{   SetIcon(wxICON(fwin));

// The size specified here is the size of the client area of the
// window, and so should lead to consistent (client area) visuals on
// all platforms. I make the window a fixed size...
    wxSize winsize(WIDTH, HEIGHT);
    SetClientSize(winsize);
    SetMinClientSize(winsize);
    SetMaxClientSize(winsize);
    Centre();
}


void DemoFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{   Close(true);
}

void DemoFrame::OnPaint(wxPaintEvent& event)
{   wxPaintDC dc(this);
// This is a fairly simple test of wxWidgets, but I am now using it
// to illustrate the SetUserScale capability.
    dc.SetUserScale(1.0,
                    1.0);  // This should be how it starts off anyway.
// First draw a pale purple background for the window.
    wxColour background_colour(230, 200, 255);
    wxBrush background_brush(background_colour);
    dc.SetBackground(background_brush);
    dc.Clear();

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if (gc == nullptr)
    {   wxPrintf("Unable to create Graphics Context\n");
        return;
    }
// make a path that contains a circle and some lines. This is from the
// wxWidgets documentation and helps confirm that the wxGraphicsContext
// is present and in order.
    gc->SetPen( *wxRED_PEN );
    wxGraphicsPath path = gc->CreatePath();
    path.AddCircle( 50.0, 50.0, 50.0 );
    path.MoveToPoint(0.0, 50.0);
    path.AddLineToPoint(100.0, 50.0);
    path.MoveToPoint(50.0, 0.0);
    path.AddLineToPoint(50.0, 100.0 );
    path.CloseSubpath();
    path.AddRectangle(25.0, 25.0, 50.0, 50.0);
    gc->StrokePath(path);


    wxDouble dwidth=99.0, dheight=99.0, ddepth=99.0, dleading=99.0;
    gc->SetFont(*ff3, *wxBLACK);
    wxString letter_X(wxT("X"));
    gc->GetTextExtent(letter_X, &dwidth, &dheight, &ddepth, &dleading);
// One thing that this reveals is that when I set a Scale in a Graphics
// Context the TextExtents show the size of the scaled item not of the
// original.
    wxPrintf("Letter 'X' in GraphicsContext w=%.2f h=%.2f d=%.2f l=%.2f\n",
             dwidth, dheight, ddepth, dleading);
    std::fflush(stdout);

    dc.SetPen(*wxRED_PEN);
    dc.DrawLine(0, HEIGHT/3, WIDTH, HEIGHT/3);

// First I will use a 36-point font and draw some text with UserScale 1.0.
// I will draw it so that the font baseline is positioned at the horizontal
// line I just drew.
    const char *msg = "Welcome to wxWidgets";
// Note that wxWidgets uses the top left hand corner of the text as its
// index point, while here I want the left hand side of the base-line. When I
// do GetTextExtent it produces a bounding box that will contain everything,
// and the reported "height" is the total height of that box. The "depth" is
// the distance from the bottom of the box to the baseline. So (h-d) is the
// amount I have to adjust by here to get the positioning I want.
    dc.SetFont(*ff1);
    wxCoord w, h, d, xl;
    dc.GetTextExtent(msg, &w, &h, &d, &xl);
    wxPrintf("Width if text measured as %d\n", w);
    dc.DrawText(msg, (WIDTH - w)/2,
                HEIGHT/3 - (h-d));
// Now to investigate overprinting... What I THINK this shows is that the
// default behaviour is that the body of letters get written but the
// background is untouched. This is as per SetBackgroundMode(wxTRANSPARENT).
    dc.SetTextForeground(*wxRED);
// Uncommenting these two lines causes background to letters to be filled with
// yellow... and by the fact it confirms that the default behaviour is
// to write letters with a transparent background.
//  dc.SetTextBackground(*wxYELLOW);
//  dc.SetBackgroundMode(wxSOLID);
// This overprints the first few characters of my message with some junk.
    dc.DrawText(".. ++", (WIDTH - w)/2,
                HEIGHT/3 - (h-d));
    dc.SetTextForeground(*wxBLACK);


//
// Now I will do something similar but using a 3-point font with a UserScale
// factor of 12.
    dc.SetUserScale(SCALE, SCALE);
// A wxPen object has an integer size, with a default of 1. That leads to
// a reasonably delicate line when drawn at UserScale 1.0, but when I
// magnify - as here - it will lead to a line with is rather broad. The
// visual effect on the display helps to confirm that scaling has been in
// effect, and I can check for consistency across platforms.
    dc.SetPen(*wxGREEN_PEN);
    dc.DrawLine(0, static_cast<int>((2*HEIGHT)/(3*SCALE)),
                static_cast<int>(WIDTH/SCALE),
                static_cast<int>((2*HEIGHT)/(3*SCALE)));

    dc.SetFont(*ff2);
// GetTextExtents gives me a width based on the 3-point size of the font,
// which means it is a much smaller integer values than I had with the
// bigger font, and so quantization effects will be greater. Perhaps the
// more important message that emerges here is that GetTextExtents does
// not consuder UserScale when it returns its measurements - they come back
// as if the text was rendered at scale 1. In that case the width here comes
// out as a small number, and it LOOKS to me as if at least on some platforms
// character placement (eg moving things to a pixel boundary) leads to
// the width of the string overall not being scaled exactly linearly with font
// size. Specifically here I find that on Windows the width I get here
// does match the previous measure merely divided by the scale factor (and
// hence there is a truncation error that has an effect on placement) but
// with the X11 version I see a bigger discrepancy.
//
// The take-away mesage is that GetTextExtent only really works the way I
// might expect when UserScale is 1.0, and that text on the screen will
// not in general scale in width as neatly as one might hope when other
// scale factors are used. So characters should usually be placed one by
// one under full user control! Oh dear!! Well discovering things like
// this is what this code is for.
    dc.GetTextExtent(msg, &w, &h, &d, &xl);
    wxPrintf("Width of text when scaled = %.2f*%d = %.2f\n", SCALE, w,
             w*SCALE);
    std::fflush(stdout);
    dc.DrawText(msg, (static_cast<int>(WIDTH/SCALE) - w)/2,
                static_cast<int>((2*HEIGHT)/(3*SCALE)) - (h-d));
    dc.SetUserScale(1.0, 1.0);

// Now I will draw a sequence is small characters across the middle of the
// screen using a large real font and using user-scaling that shrinks things
// severely so I get small items on-screen. Specifically I start with a font
// that is set up to be 60-point and scale it down to 10 point. The issue
// that I explore/demonstrate here is the cleanliness of display that results
// and whether sub-pixel character placement arises.
//


    dc.SetFont(*ff3);
    int ewidth, mwidth;
    dc.SetUserScale(1.0/6.0, 1.0/6.0);
    dc.SetPen(*wxCYAN_PEN);
    dc.DrawLine(0, HEIGHT*6/2, WIDTH*6, HEIGHT*6/2);
    dc.SetUserScale(1.0, 1.0);

    for (int y=0; y<10; y++)
        for (int x=0; x<10; x++)
        {   int x1, x2, y1, y2;
//=======================================================================
// First I draw the 60 point characters scaled down to 10 points using
// UserScale. This - as noted above leaves characters positioned at pixel
// boundaries on some platforms, and renders some characters badly when
// the font does not provide enough hinting information.
// On Windows this renders "eee" especially badly with the horizontal bar in
// the letters "e" often missing.

// I measure "e" and "m" and space by characters an odd number of pixels
// in the high resolution space, so that on-screen they do not all fall
// at natural pixel boundaries. On Windows and Unix the characters as
// drawn are clicked back onto a pixel boundary leading to irregular
// horizontal spacing.
            dc.GetTextExtent("e", &ewidth, &h, &d, &xl);
            dc.GetTextExtent("m", &mwidth, &h, &d, &xl);
            while (ewidth%2==0 || ewidth%3==0) ewidth++;
            while (mwidth%2==0 || mwidth%3==0) mwidth++;

            dc.SetUserScale(1.0/6.0, 1.0/6.0);
            dc.DrawText("e", x1=ewidth*(x+10*y), y1=HEIGHT*6/2-(h-d)+y);
            dc.DrawText("m", x2=mwidth*(x+10*y), y1+60);
            dc.SetUserScale(1.0, 1.0);

//=======================================================================
// Next, and towards the top of the screen, I will use a wxGraphicsContext
// because there I can naturally use floating point positioning and scaling.
// Unexpectedly the use of Scale on the wxGraphicsContext and SetUserScale
// on the underlying wxDC interact, so I need to take care to use
// only one scaling at a time. On Windows and Unix both x and y coordinates
// click to pixel positions. On the mac the y coordinates do.

            gc->Scale(1.0/6.0, 1.0/6.0);
            gc->DrawText(wxString("e"), x1, y2=y1-HEIGHT*6/3);
            gc->DrawText(wxString("m"), x2, y2+60);
            gc->Scale(6.0, 6.0);


//=======================================================================
//
// Now a more complicated scheme. I will explicitly draw onto a large
// bitmap then shrink it in a way that has an anti-aliasing effect. The
// result is liable to be not that sharp but (on at least some platforms) it
// may be fairer.
//
// I will want to have a bitmap that will be neatly aligned against the
// main grid when I print from it. I am coding this on the basis that my
// high resolution regime has 6 times the resolution of the low resolution
// one.
            int x1a = 6*(x1/6);
            int x2a = 6*(x2/6);
            int y1a = 6*(y1/6);
// The size needs to be big enough for the largest character in my font. I
// am not worrying about that issue JUST yet...
            wxBitmap bitmap(90, 120, 32);
            wxMemoryDC memdc;
            memdc.SelectObject(bitmap);
            memdc.SetBackground(background_brush);
            memdc.Clear();
            memdc.SetFont(*ff3);
// I will write a black letter on a standard (well in my case lilac) background.
            memdc.GetTextExtent(wxT("e"), &w, &h, &d, &xl);
            memdc.DrawText(wxT("e"), x1-x1a, y1-y1a+60-(h-d));
// I believe I need to detach the bitmap from the Device Context before
// messing around further.
            memdc.SelectObject(wxNullBitmap);
            wxImage im = bitmap.ConvertToImage();
// Rescaling at "high quality" performs averaging over the pixels in the
// source. This gives an impression of more accurate positioning and character
// shape than the simple use of DrawText direct on the output - but the cost
// is that I lose hints and tend to end up with characters that have blurry
// edges. The original character was drawn as a black charecter on a white
// background, but it may have ended up with some multi-colour fringes where
// anti-aliasing believes it knows about LCD pixel layout. That is NOT
// useful here because I am about to scale the image. But a consequence
// can be that the resulting scaled image is also colourful. To avoid any
// confusion I will map onto grayscales here...
            im.ConvertToGreyscale();
// Now I shrink the image to the size that characters should appear on the
// screen.
            im.Rescale(15, 20, wxIMAGE_QUALITY_HIGH);
// This image now has black foreground and my standard background. I need to
// give it a mask so that background bits do not get displayed...
            im.SetMaskColour(background_colour.Red(),
                             background_colour.Green(),
                             background_colour.Blue());
            wxBitmap bm2(im);
            dc.DrawBitmap(bm2, x1a/6, y1a/6+HEIGHT/3, true);


// Now basically the same stuff but without interleaved commentary, so you
// can see it is not THAT much code after all! But also so that I can see
// where it might be allocating fresh memory for each character it renders!

            memdc.SelectObject(bitmap);
            memdc.SetBackground(background_brush);
            memdc.Clear();
            memdc.GetTextExtent(wxT("m"), &w, &h, &d, &xl);
            memdc.DrawText(wxT("m"), x2-x2a, y1-y1a+60-(h-d));
            memdc.SelectObject(wxNullBitmap);
// I wamt to have a single wxImage object here rather than creating a fresh
// one every time...
            im = bitmap.ConvertToImage();
// I hope that the Grayscale convrsion is in-place.
            im.ConvertToGreyscale();
// I am concerned that Rescale might allocate fresh memory.
            im.Rescale(15, 20, wxIMAGE_QUALITY_HIGH);
// Space may be needed for the mask, and that has to be allocated at
// some stage.
            im.SetMaskColour(background_colour.Red(),
                             background_colour.Green(),
                             background_colour.Blue());
// ... and that this new bitmap may also involve extra memory management.
            wxBitmap bm3(im);
            dc.DrawBitmap(bm3, x2a/6, y1a/6+HEIGHT/3+20, true);
        }
    delete gc;
}

// A dummy definition that is needed because of wxfwin.cpp

int windowed_worker(int argc, const char *argv[],
                    fwin_entrypoint *fwin_main)
{   return 0;
}


// end of wxdemo.cpp

