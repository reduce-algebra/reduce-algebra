// wxfontdemo1.cpp                           Copyright A C Norman 2016-2017

// A sample wxWidgets application to display fonts.
//


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

// This version uses wxPaintDC and wxFont and doe snot try to use
// wxGraphicsContext. The consquence is that unlike my previous
// version it can only use integers as font sizes, but to balance that
// it does not need gciplus on Windows and should be able to use a
// standard rather than a patched version of wxWidgets.


// Driving instructions:
//
//   ./wxfontdemo1 "fontname" [--italic] [--bold] [--regular]
//
// The fontname is either the name of a font installed on the system
// or is one of the private fonts provided here (and those are the cases
// I view as more interesting). Sometimes the names you need to give the
// private fonts differ as between Macintosh and other platforms.
// Eg "CMU Typewriter Text" or "CMU Typewriter Text Regular", ...
//
// When displaying a font you can type 0-9 or a-f to move to a display
// that starts at unicode code point (eg) U+3000 (that would obviously be
// by typing a "3"). You can then type "x" to flip the U+10000 bit and
// get better access to the second plane, while "y" flips the U+100000 bit
// to get close to the end of the whole Unicode range. "+" and "-" move you
// forward and back by several blocks while "<" and ">" give finer movement.
// Other characters just move you on a section. Mouse click near the top and
// bottom on the screen also change which block of characters are displayed.
//
// The code is intended to allow me to check that I can in fact access the
// private fonts, and where necessary to confirm which codepoint corresponds
// to a particular character.

// This demonstrates attaching to private fonts, use of some bitmaps that
// show what characters are available in them, and the display of
// codes over U+FFFF (where special treatment is needed in Windows). It also
// reminds me that it SEEMS that I need to have .ttf re-coded versions of
// some .otf fonts to survive on Windows.
// It is otherwise not especially clever.

// Well I need to add more comments here as I look into the Mathematical
// Fonts in Unicode. In the block that starts at U+1d400 there are neat
// alphabets but there are very odd looking gaps. Eg in Mathematical Italic
// there is a gap where one would have expected "h" to be at U+1d455. This
// seems to be a case where you are expected to use a character from a
// quite different code block (U+2100 and on) so the "h" is U+210e. There
// are a couple of dozen oddball substututions like that. When I first
// observed the display from wxfontdemo I was worried that I had obtained
// damaged fonts, but the Unicode specification lists the gaps as
// invalid code-points. This really is deliberate! So if you spot something
// that looks truly weird be aware it may be a feature not a bug. 

// For the STIX fonts the official versions use glyphs that have to be
// accessed using advanced typography methods that I can not easily access
// in a fully cross-platform manner and with wxWidgets, so I have some
// "cslSTIX" fonts that map those glyphs to a range starting at U+108000.

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif

#include "wxfwin.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/dc.h"
//#include "wx/graphics.h"
#include "wx/filename.h"
#include "wx/fontenum.h"

#include "config.h"

#ifdef WIN32

#include <windows.h>
#include <wingdi.h>
#include <io.h>

#else
#ifdef MACINTOSH

// If I need Mac-specific includes here is where to set them up!

#else // MACINTOSH
#ifdef HAVE_LIBXFT

#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

#else   // HAVE_LIBXFT

#error Other than on Windows you must have Xft installed.

#endif  // HAVE_LIBXFT
#endif  // MACINTOSH
#endif  // WIN32

// I may be old fashioned, but I will be happier using C rather than C++
// libraries here. Hes yes I *AM* old fashioned!

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>
#include <stdint.h>
#include <inttypes.h>

#if HAVE_UNISTD_H
#include <unistd.h>
#else
extern char *getcwd(char *s, size_t n);
#endif // HAVE_UNISTD_H

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
#ifndef WIN32
#include <sys/dir.h>
#else
#include <direct.h>
#endif
#endif // HAVE_DIRENT_H

#if !defined __WXMSW__ && !defined __WXPM__
#include "fwin.xpm" // Icon to use in non-Windows cases
#endif

// I have some information about my custom fonts...
#include "charmetrics.h"

class fontApp : public wxApp
{
public:
    virtual bool OnInit();
};

class fontPanel : public wxPanel
{
public:
    fontPanel(class fontFrame *parent, const char *font, int size);

    void OnPaint(wxPaintEvent &event);
    void OnChar(wxKeyEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    void OnKeyUp(wxKeyEvent &event);
    void OnMouse(wxMouseEvent &event);

private:
    class fontFrame *frame;
    const char *fontname;
    int fontsize;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fontPanel, wxPanel)
    EVT_PAINT(           fontPanel::OnPaint)
    EVT_CHAR(            fontPanel::OnChar)
    EVT_KEY_DOWN(        fontPanel::OnKeyDown)
    EVT_KEY_UP(          fontPanel::OnKeyUp)
    EVT_LEFT_UP(         fontPanel::OnMouse)
END_EVENT_TABLE()

class fontFrame : public wxFrame
{
public:
    fontFrame(const char *font, int size);

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

private:
    fontPanel *panel;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fontFrame, wxFrame)
    EVT_CLOSE(           fontFrame::OnClose)
    EVT_MENU(wxID_EXIT,  fontFrame::OnExit)
    EVT_MENU(wxID_ABOUT, fontFrame::OnAbout)
END_EVENT_TABLE()

int page, regular, bold, italic;

IMPLEMENT_APP_NO_MAIN(fontApp)

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

int main(int argc, const char *argv[])
{
    int i;
    int usegui = 1;
// Find where I am invoked from before doing anything else
    find_program_directory(argv[0]);
    for (i=1; i<argc; i++)
    {   if (strncmp(argv[i], "-w", 2) == 0) usegui = 0;
        else if (strcmp(argv[1], "--help") == 0)
        {
            printf("wxfontdemo \"font name\"\n");
            exit(0);
        }
    }
#if !defined WIN32 && !defined MACINTOSH
// Under X11 I will demote to being a console mode application if DISPLAY
// is not set. This is not a perfect test but it will spot the simple
// cases. Eg I could look at stdin & stdout and check if it looks as if
// they are pipes of they have been redirected...
    {   const char *s = getenv("DISPLAY");
        if (s==NULL || *s == 0) usegui = 0;
    }
#endif
    if (usegui)
    {
#ifdef MACINTOSH
// If I will be wanting to use a GUI and if I have just loaded an
// executable that is not within an application bundle then I will
// use "open" to launch the corresponding application bundle. Doing this
// makes resources (eg fonts) that are within the bundle available and
// it also seems to cause things to terminate more neatly.
        char xname[LONGEST_LEGAL_FILENAME];
        sprintf(xname, "%s.app", programName);
        if (strstr(fullProgramName, xname) == NULL)
        {
// Here the binary I launched was not located as
//      ...foo.app../.../foo
// so I will view it is NOT being from an application bundle. I will
// re-launch it so it is! This may be a bit of a hacky way to decide!
            struct stat buf;
            sprintf(xname, "%s.app", fullProgramName);
            if (stat(xname, &buf) == 0 &&
                (buf.st_mode & S_IFDIR) != 0)
            {
// Well foo.app exists and is a directory, so I will try to use it
                const char **nargs =
                    (const char **)malloc(sizeof(char *)*(argc+3));
                int i;
                nargs[0] = "/usr/bin/open";
                nargs[1] = xname;
                nargs[2] = "--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
// /usr/bin/open foo.app --args [any original arguments]
                return execv(nargs[0], const_cast<char * const *>(nargs));
             }
        }
#endif
        add_custom_fonts();
        printf("Custom fonts should now be available\n");
        wxDISABLE_DEBUG_SUPPORT();
        return wxEntry(argc, (char **)argv);
    }
    printf("This program has been launched asking for use in a console\n");
    printf("type a line of text please\n");
    while ((i = getchar()) != '\n' && i != EOF) putchar(i);
    putchar('\n');
    printf("Exiting from demonstration of console mode use!\n");
    return 0;
}




bool fontApp::OnInit()
{
    display_font_information();
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;
    page = 0;
    regular = bold = italic = 0;
    const char *font = "CMU Typewriter Text";  // A default font name to ask for.
    int size = 48;           // a default size.
    for (int i=1; i<argc; i++)
    {
        printf("Arg%d: %s\n", i, myargv[i]);
        if (strcmp(myargv[i], "--regular") == 0) regular = 1;
        if (strcmp(myargv[i], "--bold") == 0) bold = 1;
        if (strcmp(myargv[i], "--italic") == 0) italic = 1;
        else if (myargv[i][0] == '-')
        {   if (sscanf(myargv[i]+1, "%d", &page) != 1) page = 0;
        }
        else font = myargv[i];
    }
// I will find the special fonts that most interest me in a location related
// to the directory that this application was launched from. So the first
// think to do is to identify that location. I then print the information I
// recover so I can debug things. I have already set up programName etc
    printf("\n%s\n%s\n%s\n", fullProgramName, programName, programDir);

    printf("Try for font \"%s\" at size=%d\n", font, size);
    fflush(stdout);

    fontFrame *frame = new fontFrame(font, size);
    frame->Show(true);
    return true;
}

#define CELLWIDTH  33
#define CELLOFFSET 45
#define CELLHEIGHT (60+CELLOFFSET)

fontFrame::fontFrame(const char *fname, int fsize)
       : wxFrame(NULL, wxID_ANY, "wxfontdemo")
{
    SetIcon(wxICON(fwin));
    panel = new fontPanel(this, fname, fsize);
    wxSize clientsize(33*CELLWIDTH, 10*CELLHEIGHT);
    wxSize winsize(ClientToWindowSize(clientsize));
    SetSize(winsize);
    SetMinSize(winsize);
    SetMaxSize(winsize);
    Centre();
}


fontPanel::fontPanel(fontFrame *parent, const char *fname, int fsize)
       : wxPanel(parent)
{
    frame = parent;
    fontname = fname;
    fontsize = fsize;
    frame->SetTitle(fontname);
}


void fontFrame::OnClose(wxCloseEvent &WXUNUSED(event))
{
    Destroy();
#ifdef WIN32
// On Windows XP I seem to have a horrid effect whereby when I try to
// close the application by closing its window there is a failure that pops
// up a rather unspecific message box, and then the application is
// re-launched. To get around that I kill the process here with extreme
// prejudice! On Windows 7 I do not observe the bad behaviour, but doing a
// heavy duty kill operation here is probably fairly harmless. What it will
// mean is that any "atexit" operations are not completed, and I might
// worry about incompletely written-out files.
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void fontFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{
    Destroy();
#ifdef WIN32
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void fontFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{
    wxMessageBox(
       wxString::Format(
           "wxfontdemo1 (A C Norman 2014-16)\n"
           "wxWidgets version: %s\n"
           "Operating system: %s\n"
           wxVERSION_STRING,
           wxGetOsDescription()),
       "About wxfontdemo",
       wxOK | wxICON_INFORMATION,
       this);
}

void fontPanel::OnChar(wxKeyEvent &event)
{
}

void fontPanel::OnKeyDown(wxKeyEvent &event)
{
    wxChar c = event.GetUnicodeKey();
    int n = -1;
    printf("Char event %#x (%c)\n", c, c); fflush(stdout);
    event.Skip();
    if ('0' <= c && c <= '9') n = c - '0';
    else if ('a' <= c && c <= 'f') n = c - 'a' + 10;
    else if ('A' <= c && c <= 'F') n = c - 'A' + 10;
    if (n >= 0) page = n*0x1000/0x80;
    else switch (c)
    {
    case 'q':
    case 'Q':
#ifdef WIN32
        TerminateProcess(GetCurrentProcess(), 1);
#else
        exit(0);
#endif

    case 'x':
    case 'X':
        page ^= 0x10000/0x80; // Second plane
        break;
    case 'y':
    case 'Y':
        page ^= 0x100000/0x80; // Final plane
        break;
    case '+':
    case '=':              // "+" key but without shift pressed...
        page = page + 8;
        break;
    case '-':
    case '_':
        page = page - 8;
        break;
    case '>':
    case '.':
        page = page + 1;
        break;
    case '<':
    case ',':
        page = page - 1;
        break;
    default:
        page++;
        break;
    }
    Refresh();
}

void fontPanel::OnKeyUp(wxKeyEvent &event)
{
}

void fontPanel::OnMouse(wxMouseEvent &event)
{
    wxWindowDC dc(this);
    wxPoint where(event.GetLogicalPosition(dc));
    if (where.y > 200) page++;
    else page--;
    printf("Mouse event. Page now %d\n", page); fflush(stdout);
    event.Skip();
    Refresh();
}

// The following function will catalogue the fonts I expect to allow
int find_fontnum(const char *s)
{
    return -1; // Ignore tables of available chars for now...
    if (strcmp(s, "CMU Typewriter Text") == 0) return F_cmuntt;
    if (strcmp(s, "odokai") == 0) return F_odokai;
// Note that Bold and Italic are picked up by options --bold and --italic
// not through the font name.
    if (strcmp(s, "STIX") == 0) return F_Regular;
    if (strcmp(s, "STIXMath") == 0) return F_Math;
    return -1;
}

static int once = 0;

void fontPanel::OnPaint(wxPaintEvent &event)
{
printf("OnPaint invoked\n");
    wxPaintDC dc(this);
    wxColour c1(230, 200, 255);
    wxColour c2(100, 220, 120);
    wxBrush b1(c1); wxBrush b2(c2);
    wxPen p1(c1);   wxPen p2(c2);
// Draw a checkerboard background
    for (int y=0; y<256+2*32; y+=32)
    {   for (int x=0; x<33; x++)
        {   int k = ((y>>5) + x) & 1;
            dc.SetBrush(k ? b2 : b1);
            dc.SetPen(k ? p2 : p1);
            dc.DrawRectangle(CELLWIDTH*x, CELLHEIGHT*(y/32), CELLWIDTH, CELLHEIGHT);
        }
    }
    if (once == 0)
    {   printf("fontname = %s\n", fontname);
        if (wxFontEnumerator::IsValidFacename(fontname))
            printf("Face name is valid\n");
        else printf("Invalid face name - font not found\n");
    }
    wxFontInfo ffi(30);
    ffi.FaceName(fontname);
    if (regular) ffi.Bold(false);
    if (bold) ffi.Bold();
    if (italic) ffi.Italic();
    wxFont ff(ffi);
    if (once == 0)
    {   if (ff.IsOk()) wxPrintf("Font seems OK\n");
        else wxPrintf("Font is *NOT* OK\n");
        wxPrintf("Face name = %s\n", ff.GetFaceName());
        wxPrintf("Native name = %s\n", ff.GetNativeFontInfoDesc());
        wxPrintf("Friendly name = %s\n", ff.GetNativeFontInfoUserDesc());
        fflush(stdout);
    }
    int fontnum = find_fontnum(fontname);
    if (fontnum >= 0) printf("Map of available codepoints found\n");
    else printf("No map of valid codepoints\n");
// Draw row and column labels
    wxFont labels(wxFontInfo(9));
    dc.SetFont(labels);
    for (int i=0; i<32; i++)
    {   char word[12];
        sprintf(word, "%02x", i);
        dc.DrawText(word, (((double)CELLWIDTH)*(i+1)) + CELLWIDTH/2.2,
            (double)CELLHEIGHT/10.0);
    }
    for (int i=0; i<8; i++)
    {   char word[12];
        sprintf(word, "%5x", 32*i + 0x80*page);
        dc.DrawText(word, CELLWIDTH/10.0,
            (double)CELLHEIGHT*(i+1) + CELLHEIGHT/2.5);
    }
    dc.SetFont(ff);
#if 0
// Check if the font appears to contain any characters at all. In some
// cases where an unrecognised name is passed it might not!
//
// When I tried the STIX fonts I seem to get crashes within GetTextExtent
// for reasons that I do not at present understand... so at least for now
// I will remove this attempt to count characters!
    if (0 && once++ == 0) // Disable just for now
    {   int howmany = 0; 
        for (int i=0; howmany<30 && i<0xffff; i++)
        {   wxString s((wchar_t)i);
            double ww, hh, dd, el;
            gc->GetTextExtent(s, &ww, &hh, &dd, &el);
            if (ww != 0.0 && hh != 0.0)
            {   printf("%#x %.1f*%.1f; ", i, ww, hh);
                howmany++;
            }
        }
        if (howmany == 0) printf("No glyphs found");
        printf("\n");
        fflush(stdout);
    }
#endif

// I will need font size information in order to position characters
// neatly.
    wxCoord w1=0, h1=0, d1=0, xl1=0;
    dc.GetTextExtent("X", &w1, &h1, &d1, &xl1);
    dc.SetTextForeground(*wxRED);
    for (int i=0; i<256; i+=32)
    {   for (int j=0; j<32; j++)
        {   dc.SetPen(*wxBLUE_PEN);
            dc.SetBrush(*wxTRANSPARENT_BRUSH);
            dc.DrawEllipse(CELLWIDTH*(j+1) - 6,
                           CELLHEIGHT*(i/32+1) + CELLHEIGHT - 6 - CELLOFFSET,
                           12, 12);
            int k = i + j;
            k += 0x80*page;
            if (k < 0 ||
                k >= 0x110000 ||
                (fontnum >= 0 && lookupchar(fontnum, k) == 0))
            {   dc.DrawRectangle(
                   CELLWIDTH*(j+1)+CELLWIDTH/3,
                   CELLHEIGHT*(i/32+1)+CELLHEIGHT/3 - CELLOFFSET,
                   CELLWIDTH/3, CELLHEIGHT/3);
                continue;
            }
            wchar_t ccc[4];
// For the benefit of Windows I need to represent code points in other
// then the basic multilingual pane as surrogate pairs.
            if (sizeof(wchar_t) == 4 ||
                k <= 0xffff)
            {   ccc[0] = k;
                ccc[1] = 0;
            }
            else
            {   k = (k - 0x10000) & 0xfffff;
                ccc[0] = 0xd800 + (k >> 10);
                ccc[1] = 0xdc00 + (k & 0x3ff);
                ccc[2] = 0;
            }
            wxString c(ccc);
            double offset = d1-h1 - CELLOFFSET;
            dc.DrawText(c,
                CELLWIDTH*(j+1),
                CELLHEIGHT*(i/32+1) + CELLHEIGHT + offset);
        }
    }
}

// A dummy definition that is needed because of wxfwin.cpp

int windowed_worker(int argc, const char *argv[],
                    fwin_entrypoint *fwin_main)
{   return 0;
}


// end of wxfontdemo1.cpp

