// wxdemo.cpp

// A sample wxWidgets application.
//

/**************************************************************************
 * Copyright (C) 2010, Codemist.                         A C Norman       *
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

/* $Id$ */

// This code is a small demonstration of what wxWidgets can do - but MOSTLY
// it is looking at the issues of placing characters precisely on the screen
// at various sizes.
//
// The expected output is a lilac screen. 2/3 of the way up there should be
// a thin red line with a message sitting on it.
// 1/3 of the way up there is a broader green line with the same message,
// and the difference is that the lower one was drawn at what wxWidgets
// believed were 3-point characters scaled up. A consequence is that with
// integers used as coordinates the positioning (centering here) may be
// less accurate. I see good centering on Windows and much less good using
// X11.
// Then just half way up there us a thing cyan line with a row of "e" characters
// above and "m" below. These are created by having a 60 point font and
// using the wxWidgets UserScale facility to display the text as 10-point
// characters. What I typically see is that the characters end up rendered
// quite well for their size, but at the cost of the spacing between them
// being rendered irregular by the system tending to force each character
// to be rendered starting at a coordinate that is an integral number of
// pixels.
// Finally towards the bottom there are agin rows of "e" and "m" but this
// time I first draw them at full 60-point resoluation, then I scale down to
// 10 points in a way that antialiases, and finally a transfer that version
// to the output. The scale reduction happens without any access to font
// rendering hints and so can lead to blurry characters and what one might
// describe as "the usual bad things". But it preserves sub-pixel shape and
// placement somewhat, who while the half-way-up has nicely formed characters
// but places six in a row and then leave a slightly larger space before the
// next, the low display uses blurring half-tones to get the spacing more
// uniform. At present this does not appear to work on the Macintosh, and
// I maybe should investigate - however the previous mid-line scaling works
// very well on the Mac so my private hand-done antialiasing is not actually
// needed there!
//



#include "wxfwin.h"

#include "wx/wxprec.h"
 
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !defined __WXMSW__ && !defined __WXPM__
#include "fwin.xpm" // Icon to use in non-Windows cases
#endif

int main(int argc, const char *argv[])
{
    add_custom_fonts();
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
{
    ACN_Quit = wxID_EXIT,
    ACN_About = wxID_ABOUT
};

BEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(ACN_Quit,  DemoFrame::OnQuit)
    EVT_PAINT(          DemoFrame::OnPaint)
END_EVENT_TABLE()


IMPLEMENT_APP_NO_MAIN(wxDemo)

// Pretty much everything so far has been uttery stylised and the contents
// are forced by the structure that wxWidgets requires!

static wxFont *ff1 = NULL;
static wxFont *ff2 = NULL;
static wxFont *ff3 = NULL;

#define FONTSIZE1 36
#define FONTSIZE2  3
#define FONTSIZE3 60

#define SCALE ((double)FONTSIZE1/(double)FONTSIZE2)

#define WIDTH    600
#define HEIGHT   400

bool wxDemo::OnInit()
{
    wxFontInfo ffi;
    ffi.FaceName("cslSTIXMath");
//  ffi.FaceName("CMU Typewriter Text");
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
       : wxFrame(NULL, wxID_ANY, title)
{
    SetIcon(wxICON(fwin));

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
{
    Close(true);
}

void DemoFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
// This is a fairly simple test of wxWidgets, but I am now using it
// to illustrate the SetUserScale capability.
    dc.SetUserScale(1.0, 1.0);
// First draw a pale purple background for the window.
    wxColour c1(230, 200, 255);
    wxBrush b1(c1);
    wxPen p1(c1);
    dc.SetBrush(b1);
    dc.SetPen(p1);
    dc.DrawRectangle(0, 0, WIDTH, HEIGHT);
        
    dc.SetPen(*wxRED_PEN);
    dc.DrawLine(0, HEIGHT/3, WIDTH, HEIGHT/3);

//    dc.SetBrush(*wxTRANSPARENT_BRUSH);

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
    dc.DrawText(msg, (WIDTH - w)/2,
                     HEIGHT/3 - (h-d));


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
    dc.DrawLine(0, (int)((2*HEIGHT)/(3*SCALE)),
                (int)(WIDTH/SCALE), (int)((2*HEIGHT)/(3*SCALE)));

    dc.SetFont(*ff2);
// GetTextExtents gives me a width based on the 3-point size of the font,
// which means it is a much smaller integer values than I had with the
// bigger font, and so quantization effects will be greater.
    dc.GetTextExtent(msg, &w, &h, &d, &xl);
    dc.DrawText(msg, ((int)(WIDTH/SCALE) - w)/2,
                     (int)((2*HEIGHT)/(3*SCALE)) - (h-d));

// Now I will draw a sequence is small characters across the middle of the
// screen using a large real font and using user-scaling that shrinks things
// severely so I get small items on-screen. Specifically I start with a font
// that is set up to be 60-point and scale it down to 10 point. The issue
// that I explore/demonstrate here is the cleanliness of display that results
// and whether sub-pixel character placement arises.
//
// Observed behaviour:
// Windows 10: Characters appear reasonably formed and anti-aliased, but
//             always placed to the next pixel boundary. The horizontal line
//             is drawn one-pixel wide even though scaling says it should
//             notionally be (1/6) pixel wide. On my computer if I take a
//             screen snapshot or use the on-screen magnifying glass I see
//             colour fringes on letters that are probably the "cleartype"
//             antialiasing scheme. Maybe DirectWrite could do better, but
//             wxWidgets does not support that (yet?).
//   HA HA HA. A rather more important issue becomes visible with more tests.
//             if the font I use is cslSTIXMath then I suspecc it does not
//             have too many WIndowsd-compatible hinting tables - whatever
//             else the raw display seems fairly poor - in partiicular
//             the horizontal bar of the "e" is pretty well always invisible
//             at the small scale I am using.
// Cygwin X11: Very much the same except that the antialiasing of characters
//             shows up as shades of gray rather than as colours.
// Ubuntu accessed via cygwin X server: as above for Cygwin direct.
// Ubuntu running under virtualbox: somewhat more like the Windows case with
//             colour antialiasting.
// Macbook:    dramatically better display for two reasons. The first is that
//             the raw screen resolution on my Macbook retina as much higer
//             and so there are more pixels available to shape the characters
//             even at 10-point size. Then it look as as if rendering has been
//             using sub-pixel placement for individual characters, so the
//             pixel-appearance of each instance of a letter varies, leading
//             to enhanced apparent spacing. It is plausible that the sub-pixel
//             placement would lead to characters appearing blury if I had
//             a lower resolution display.
// I think I believe that for ordinary text it will make sense to go with
// whatever the operating system provides - but for Maths I will have things
// like superscripts and subscripts that are naturally rather small characters
// and where the spacing between them and the item they attach to is
// critical enough that I will worry about it. So here I will first draw
// characters onto a big bitmap, then scale that down and finally draw
// the result. I will try that two ways...
    dc.SetUserScale(1.0, 1.0);
    dc.SetFont(*ff3);
    int ewidth, mwidth;
    for (int y=0; y<10; y++)
        for (int x=0; x<10; x++)
        {   int x1, x2, y1;
// First I draw the 60 point characters scaled down to 10 points using
// UserScale. This - as noted above leaves characters positioned at pixel
// boundaries on some platforms, and renders some characters badly when
// the font does not provide enough hinting information. At least I think
// that is what is going on.
            dc.SetUserScale(1.0/6.0, 1.0/6.0);
            dc.SetPen(*wxCYAN_PEN);
            dc.DrawLine(0, HEIGHT*6/2, WIDTH*6, HEIGHT*6/2);

            dc.GetTextExtent("e", &ewidth, &h, &d, &xl);
            dc.GetTextExtent("m", &mwidth, &h, &d, &xl);
            while (ewidth%2==0 || ewidth%3==0) ewidth++;
            while (mwidth%2==0 || mwidth%3==0) mwidth++;
            mwidth |= 1;
            dc.DrawText("e", x1=ewidth*(x+10*y), y1=HEIGHT*6/2-(h-d)+y);
            dc.DrawText("m", x2=mwidth*(x+10*y), y1+60);
// Now a more complicated scheme. I will explicitly draw onto a large
// bitmap then shrink it in a way that has an anti-aliasing effect. The
// result is liable to be not that sharp but (on at least some platforms) it
// may be fairer. 
            dc.SetUserScale(1.0, 1.0);
// I will want to have a bitmap that will be neatly aligned against the
// main grid when I print from it.
            int x1a = 6*(x1/6);
            int x2a = 6*(x2/6);
            int y1a = 6*(y1/6);
// The size needs to be big enough for the laregest character in my font. I
// am not worrying about that issue JUST yet...
            wxBitmap bitmap(60, 120, 32);
            wxMemoryDC memdc;
            memdc.SelectObject(bitmap);
            memdc.SetFont(*ff3);
            memdc.SetUserScale(1.0, 1.0);
            memdc.SetPen(*wxWHITE_PEN);
            memdc.SetBrush(*wxWHITE_BRUSH);
            memdc.DrawRectangle(0, 0, 60, 120);
            dc.GetTextExtent("e", &w, &h, &d, &xl);
            memdc.DrawText("e", x1-x1a, y1-y1a+60-(h-d));
// I believe I need to detach the bitmap from the Device Context before
// messing around further.
            memdc.SelectObject(wxNullBitmap);
            wxImage im = bitmap.ConvertToImage();
// Rescaling at "high quality" performs averaging over the pixels in the
// source. This gives an impression of more accurate positioning and character
// shape than the simple use of DrawText direct on the output - but the cost
// is that I lose hints and tend to end up with characters that have blurry
// edges.
            im.Rescale(10, 20); //, wxIMAGE_QUALITY_HIGH);
            wxBitmap bm2 = im;
#ifdef USE_DRAWBITMAP
            dc.DrawBitmap(bm2, x1a/6, y1a/6+HEIGHT/3);
#else
            memdc.SelectObject(bm2);
            dc.Blit(x1a/6, y1a/6+HEIGHT/3,     // destination coordinates
                    10, 20,                    // size to copy
                    &memdc,                    // source
                    0, 0,                      // source coordinates
                    wxAND);                    // tend to blacken
            memdc.SelectObject(wxNullBitmap);
#endif

            memdc.SelectObject(bitmap);
            memdc.DrawRectangle(0, 0, 60, 120);
            memdc.DrawText("m", x2-x2a, y1-y1a+60-(h-d));
            memdc.SelectObject(wxNullBitmap);
            im = bitmap.ConvertToImage();
            im.Rescale(10, 20); //, wxIMAGE_QUALITY_HIGH);
            wxBitmap bm3 = im;
#ifdef USE_DRAWBITMAP
            dc.DrawBitmap(bm3, x2a/6, y1a/6+HEIGHT/3+20);
#else
            memdc.SelectObject(bm3);
            dc.Blit(x2a/6, y1a/6+HEIGHT/3+20,  // destination coordinates
                    10, 20,                    // size to copy
                    &memdc,                    // source
                    0, 0,                      // source coordinates
                    wxAND);                    // tend to blacken
            memdc.SelectObject(wxNullBitmap);
#endif
       }
}

// A dummy definition that is needed because of wxfwin.cpp

int windowed_worker(int argc, const char *argv[],
                    fwin_entrypoint *fwin_main)
{   return 0;
}


// end of wxdemo.cpp

