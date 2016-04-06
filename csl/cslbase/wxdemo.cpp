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


// The first few lines are essentially taken from the wxWidgets documentation
// and will be the same for almost all wxWidgets code.

#include "wx/wxprec.h"
 
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !defined __WXMSW__ && !defined __WXPM__
#include "fwin.xpm" // Icon to use in non-Windows cases
#endif

class wsDemo : public wxApp
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


IMPLEMENT_APP(wsDemo)

// Pretty much everything so far has been uttery stylised and the contents
// are forced by the structure that wxWidgets requires!

static wxFont *ff = NULL;

#define FONTSIZE 36
#define WIDTH    600
#define HEIGHT   400

bool wsDemo::OnInit()
{
    ff = new wxFont(FONTSIZE,
                    wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                    wxFONTWEIGHT_NORMAL);
    DemoFrame *frame = new DemoFrame("wxdemo");
    frame->Show(true);
    return true;
}

DemoFrame::DemoFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
    SetIcon(wxICON(fwin));

// The size specified here is the total size of the whole window,
// including title bar and borders...
    wxSize winsize(WIDTH, HEIGHT);
    SetSize(winsize);
    SetMinSize(winsize);
    SetMaxSize(winsize);
    Centre();
}


void DemoFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void DemoFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    wxColour c1(230, 200, 255);
    wxBrush b1(c1);
    wxPen p1(c1);
    dc.SetBrush(b1);
    dc.SetPen(p1);
    dc.DrawRectangle(0, 0, WIDTH, HEIGHT);
        
    dc.SetPen(*wxRED_PEN);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
    dc.SetFont(*ff);
    const char *msg = "Welcome to wxWidgets";
    wxSize s(dc.GetTextExtent(msg));
    dc.DrawText(msg, (WIDTH-s.GetWidth())/2, (HEIGHT-3*s.GetHeight())/2);
}


// end of wxdemo.cpp

