// wxfontdemo.cpp

// A sample wxWidgets application to display fonts.
//


/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
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

/* Signature: 58ff5105 03-Nov-2010 */



// The first few lines are essentially taken from the wxWidgets documentation
// and will be the same for almost all wxWidgets code.

#include "wx/wxprec.h"
 
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !defined __WXMSW__ && !defined __WXPM__
#include "fwin.xpm" // Icon to use in non-Windows cases
#endif

class SampleApp : public wxApp
{
public:
    virtual bool OnInit();
};

class SampleFrame : public wxFrame
{
public:
    SampleFrame(const wxString& title, char *font, int size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);

private:
    char *fontname;
    int fontsize;
    wxFont *ff;
    bool fontScaled;
    DECLARE_EVENT_TABLE()
};

enum
{
    ACN_Quit = wxID_EXIT,
    ACN_About = wxID_ABOUT
};

BEGIN_EVENT_TABLE(SampleFrame, wxFrame)
    EVT_MENU(ACN_Quit,  SampleFrame::OnQuit)
    EVT_MENU(ACN_About, SampleFrame::OnAbout)
    EVT_PAINT(          SampleFrame::OnPaint)
END_EVENT_TABLE()


IMPLEMENT_APP(SampleApp)

// Pretty much everything so far has been uttery stylised and the contents
// are forced by the structure that wxWidgets requires!

bool SampleApp::OnInit()
{
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;
    for (int i=0; i<argc; i++)
    {
        printf("%d: %s\n", i, myargv[i]);
    }

    char *font = "Courier";  // A default font name to ask for.
    int size = 48;           // a default size.
    if (argc > 1) font = myargv[1];
    if (argc > 2)
    {   size = atoi(myargv[2]);
        if (size <= 2 || size > 200) size = 48;
    }
    printf("Try for font \"%s\" at size=%d\n", font, size);

    SampleFrame *frame = new SampleFrame("wxfontdemo", font, size);
    frame->Show(true);
    return true;
}

SampleFrame::SampleFrame(const wxString& title, char *fname, int fsize)
       : wxFrame(NULL, wxID_ANY, title)
{
    SetIcon(wxICON(fwin));

// I *think* I want to make the font have a size specified in pixels
// not points here... however that appears to be delicate. So I will
// create one at a plausible point size then adjust it later. I will
// use "fontScaled" to ensure I only adjust it once.
    fontname = fname;
    fontsize = fsize;
    ff = new wxFont();
    ff->SetNativeFontInfoUserDesc(fontname);
    ff->SetPointSize(36);
    fontScaled = false;

// The size specified here is the total size of the whole window,
// including title bar and borders...
    wxSize clientsize(32*32, 9*64);
    wxSize winsize(ClientToWindowSize(clientsize));
    SetSize(winsize);
    SetMinSize(winsize);
    SetMaxSize(winsize);
    Centre();
}


void SampleFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void SampleFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format
                 (
                    "Welcome to %s!\n"
                    "\n"
                    "This is wxfontdemo\n"
                    "running under %s.",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                 ),
                 "About wxfontdemo",
                 wxOK | wxICON_INFORMATION,
                 this);
}

void SampleFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    wxRegionIterator upd(GetUpdateRegion());
    wxColour c1(230, 200, 255);
    wxColour c2(100, 220, 120);
    wxBrush b1(c1);
    wxBrush b2(c2);
    wxPen p1(c1);
    wxPen p2(c2);
    for (int i=0; i<256+32; i+=32)
    {   for (int j=0; j<32; j++)
        {   int k = ((i>>5) + j) & 1;
            dc.SetBrush(k ? b2 : b1);
            dc.SetPen(k ? p2 : p1);
            dc.DrawRectangle(32*j, 2*i, 32, 64);
        }
    }
    
    dc.SetFont(*ff);
    wxCoord w1, h1, d1, xl1;
    dc.GetTextExtent("X", &w1, &h1, &d1, &xl1);

// If I have not adjusted my font size to get the PIXEL size I want.
// I will scale the height returned for "X" to be the number of pixels I
// want.
    if (!fontScaled)
    {   printf("Original w:%d h:%d d:%d xl:%d\n", w1, h1, d1, xl1);
        ff->Scale((float)fontsize/(float)h1);
        dc.SetFont(*ff);
        dc.GetTextExtent("X", &w1, &h1, &d1, &xl1);
        printf("Adjusted w:%d h:%d d:%d xl:%d\n", w1, h1, d1, xl1);
        wxString f = ff->GetNativeFontInfoDesc();
        const char *fd = f.utf8_str();
        printf("Font = %s\n", fd);
        fontScaled = true; // Do this only once!
    }
// To make my display match the one I had from my previous FOX-based
// version I will adjust to make it as if DrawText uses the base-line of
// the character for its reference point. I draw a little red circle to
// show where the reference point is...
    for (int i=0; i<256; i+=32)
    {   for (int j=0; j<32; j++)
        {   dc.SetPen(*wxRED_PEN);
            dc.SetBrush(*wxTRANSPARENT_BRUSH);
            dc.DrawCircle(32*j, 2*i+64, 8);
// If I do not make this wchar_t I get into utf_8 vs Unicode disasters
// at least on some X11 versions.
            wxString c = (wchar_t)(i+j);
            dc.DrawText(c, 32*j, 2*i+64  -h1+d1);
        }
    }
}


// end of wxfontdemo.cpp

