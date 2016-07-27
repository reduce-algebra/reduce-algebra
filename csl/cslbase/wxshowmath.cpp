// wxshowmath.cpp                            Copyright (C) 2016, A C Norman

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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


// This is a fresh implementation of this code and will avoid use of
// wxGraphicsContext (at least for any font-related activity) so that
// it can use custom fonts with a standatd copy of wxWidgets. To achieve that
// and indeed to get accurate character placement it will use a memory buffer
// rather larger than the screen and first draw onto that, and then do
// its own scale reduction to a second buffer sized as per the real
// window I am painting in. That real window will never be larger than the
// screen size.

// So the overview plan is that "hugebitmap" is a 1-bit deep (ie monochrome)
// bitmap with width the OVERSAMPLE times as that of the screen and height
// twice OVERSAMPLE times the screen height. Well I will want to round
// the size up to give a narrow extra border because when I process things
// I will tend to read just beyond what would naturally count as the edge.
//
// "bitmap" is a bitmap with depth the same as the screen (and I am often
// going to expect that to be 24 or 32 bits) and size just matching the
// screen.
// If I have a window with client area of size w*h then a corner of bitmap
// will be used to collect what is to be displayed on it. Because the bitmap
// is thoroughtly compatible with the screen I can update bits of the
// screen using simple (and fast) Blit operations.
// I will than want to have a section of hugebitmap with the same proportions.
// I will make it (about) between OVERSAMPLE to 2*OVERSAMPLE times as wide,
// and I want to make its size a nice round number. I may arrange that
// the whenever I change it I either halve or double its size.
// Associated with hugebitmap is a font such that 80 characters fit
// neatly across the width of the active region. This probably means that
// I want the active width to be a multiple of 80.
//
// Let me first the user-interface for displaying characters and rectangles.
// I will work in a standard coordinate space which I is expressed in integers
// but has reasonably high resolution. I will make it such that 0-64000
// represents or maps to the width of the screen. That number is a neat
// multiple of 80 and fits with 16 bits. The highest standardized screen
// resolution is at present 8K UHD with a width of 7680 so this is (roughly)
// 8 times finer. I will use integer scaling to go from these user coordinates
// first to a position within hugebitmap.
//
// Then when I need to update the screen I will map from hugebitmap to
// bitmap, converting the monochrome hugebitmap to a greyscale version in
// bitmap. In general this will not be scaling by a particularly nice
// ratio! I will code that for myself. The result will not be able to
// exploit font-smoothing based on the three separate colours used by an
// LCD display.
//
// I will have to play games to arrange to be able to get just those parts of
// of the screen redrawn that I need to. When I want colour effects I will
// arrange them to having areas of my screen marked for colour in bitmap
// thoug not in hugebitmap, and I have not worke dout details of that
// either. Colour may be reqired for distinguishing prompts, inputs,
// regular output and diagnostics and for marking regions as selected.
//
// I think I have written enough here for now - I should now start to
// implement at least some parts of it!


// Without the following things like UINT64_C will not be available.
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include"wx/wx.h"
#endif

#include <wx/display.h>
#include <wx/graphics.h>
#include <wx/filename.h>
#include <wx/rawbmp.h>

#include"config.h"

#include "wxfwin.h"

#ifdef WIN32
#include <windows.h>
#endif  // WIN32

// I may be old fashioned, but I will be happier using C rather than C++
// libraries here. What me? Old fashioned????           **!!!!!!**

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
#include"fwin.xpm" // Icon to use in non-Windows cases
#endif

// I have a generated file that contains the widths of all the fonts
// that I am willing to use here.

#include"uninames.h"
#include"charmetrics.h"

static FILE *logfile = NULL;

static int logprintf(const char *fmt, ...)
{   va_list a;
    int r = 0;
    if (logfile == NULL) logfile = fopen("wxshowmath.log", "w");
    if (logfile != NULL)
    {   va_start(a, fmt);
        r = vfprintf(logfile, fmt, a);
        fflush(logfile);
        va_end(a);
    }
#ifndef MACINTOSH
// On systems other than the Mac I expect I can (sometimes!) have a console
// attached to my program, and in that case it will be convenient to sent the
// trace output there as well as to a file.
    va_start(a, fmt);
    r = vprintf(fmt, a);
    va_end(a);
    fflush(stdout);
#endif
    return r;
}

class showmathApp : public wxApp
{
public:
    virtual bool OnInit();
};

#define MAX_FONTS 16
wxFont Font[MAX_FONTS];
int Baseline[MAX_FONTS];
bool FontValid[MAX_FONTS];
int char_width;       // for fixed pitch font, as on hugebitmap.
int char_offset;      // so that I print relative to index point.
int char_linespace;   // how much to separate lines by.


class showmathPanel : public wxPanel
{
public:
    showmathPanel(class showmathFrame *parent, const char *showmathfilename);

    void OnPaint(wxPaintEvent &event);

// The event handling is not really needed for this application, but I
// am putting some in so I can experiment with it!
    void OnChar(wxKeyEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    void OnKeyUp(wxKeyEvent &event);
    void OnMouse(wxMouseEvent &event);

private:
    wxFont FixedPitch;
    int FixedPitchBaseline;

    void RenderDVI();        // sub-function used by OnPaint

    char *showmathData;  // the .showmath file's contents are stored here
    unsigned const char *stringInput;



    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(showmathPanel, wxPanel)
    EVT_PAINT(           showmathPanel::OnPaint)
    EVT_CHAR(            showmathPanel::OnChar)
//  EVT_KEY_DOWN(        showmathPanel::OnKeyDown)
//  EVT_KEY_UP(          showmathPanel::OnKeyUp)
    EVT_LEFT_UP(         showmathPanel::OnMouse)
END_EVENT_TABLE()

static const int OVERSAMPLE = 4;

int screenWidth, screenHeight;
int windowWidth, windowHeight;
wxBitmap *hugebitmap;
wxMemoryDC *hugedc;
wxFont *hugefont;

wxBitmap *bitmap;
wxMemoryDC *bitdc;

class showmathFrame : public wxFrame
{
public:
    showmathFrame(const char *showmathfilename);

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);

private:
    showmathPanel *panel;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(showmathFrame, wxFrame)
    EVT_CLOSE(           showmathFrame::OnClose)
    EVT_MENU(wxID_EXIT,  showmathFrame::OnExit)
    EVT_MENU(wxID_ABOUT, showmathFrame::OnAbout)
    EVT_SIZE(            showmathFrame::OnSize)
END_EVENT_TABLE()

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

int main(int argc, char *argv[])
{   int i;
    int usegui = 1;
#if DEBUG
    logprintf("Starting wxshowmath program\n");
#endif
// Find where I am invoked from before doing anything else
    find_program_directory(argv[0]);
// The next fragment is not very useful in THIS program but stands in for
// behaviour I want in more complicated cases.
    for (i=1; i<argc; i++)
    {   if (strncmp(argv[i],"-w", 2) == 0) usegui = 0;
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
        sprintf(xname,"%s.app", programName);
        if (strstr(fullProgramName, xname) == NULL)
        {
// Here the binary I launched was not located as
//      ...foo.app../.../foo
// so I will view it is NOT being from an application bundle. I will
// re-launch it so it is! This may be a bit of a hacky way to decide!
            struct stat buf;
            sprintf(xname,"%s.app", fullProgramName);
            if (stat(xname, &buf) == 0 &&
                (buf.st_mode & S_IFDIR) != 0)
            {
// Well foo.app exists and is a directory, so I will try to use it
                const char **nargs =
                    (const char **)malloc(sizeof(char *)*(argc+3));
                int i;
                nargs[0] ="/usr/bin/open";
                nargs[1] = xname;
                nargs[2] ="--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
// /usr/bin/open foo.app --args [any original arguments]
                return execv("/usr/bin/open", const_cast<char * const *>(nargs));
            }
        }
#endif
// I have my own "main" function and call wxEntry from it. So I need
// to call the following so that if I compiled with NDEBUG set a range of
// assertions etc will not be checked...
        wxDISABLE_DEBUG_SUPPORT();
#if DEBUG
        logprintf("calling wxEntry\n");
#endif
        add_custom_fonts();
        display_font_information();
#if DEBUG
        logprintf("fonts added\n");
#endif
        return wxEntry(argc, (char **)argv);
    }
//
// The following is a bit silly but is here to prove that I can launch this
// code in console mode if I wish to. In this case it is not very useful!
//
    printf("This program has been launched asking for use in a console\n");
    printf("type a line of text please\n");
    while ((i = getchar()) != '\n' && i != EOF) putchar(i);
    putchar('\n');
    printf("Exiting from demonstration of console mode use!\n");
    return 0;
}

IMPLEMENT_APP_NO_MAIN(showmathApp)

//=========================================================================
//
// Now that start of my code in a proper sense!
//
//

bool showmathApp::OnInit()
{
// The program can take an argument - grab that here and pass it down to
// showmathFrame - or NULL if there was none.
    char **myargv = (char **)argv;
    const char *showmathfilename = argc > 1 ? myargv[1] : NULL;
#ifdef WIN32
    static char tidyfilename[LONGEST_LEGAL_FILENAME];
    if (showmathfilename != NULL &&
        strncmp(showmathfilename, "/cygdrive/", 10) == 0 &&
        showmathfilename[11] == '/')
    {   sprintf(tidyfilename, "%c:%s",
                showmathfilename[10], showmathfilename+11);
        showmathfilename = tidyfilename;
    }
#endif
    showmathFrame *frame = new showmathFrame(showmathfilename);
    frame->Show(true);
    return true;
}

showmathFrame::showmathFrame(const char *showmathfilename)
    : wxFrame(NULL, wxID_ANY, "wxshowmath")
{   SetIcon(wxICON(fwin));
    int numDisplays = wxDisplay::GetCount(); // how many displays?
// It is not clear to me what I should do if there are several displays,
// and if there are none I am probably in a mess!
    if (numDisplays != 1)
    {   logprintf("There seem to be %d displays\n", numDisplays);
    }
    wxDisplay d0(0);                         // just look at display 0
    wxRect screenArea(d0.GetClientArea());   // omitting task bar
    screenWidth = screenArea.GetWidth();
    screenHeight = screenArea.GetHeight();
    logprintf("Usable area of screen is %d by %d\n", screenWidth, screenHeight);

    int sw = screenWidth;
    if (sw < 800) sw = 800;       // In case I encounter a really tiny screen.
// I now round the width up to be a multiple of 80 and then increase it by
// 8. Making it a multiple of 80 is to get a better chance of fitting
// exactly 80 characters across it.
    sw = OVERSAMPLE*(sw + (80 - sw%80));
    hugebitmap = new wxBitmap(sw, OVERSAMPLE*screenHeight, 1);
    hugedc = new wxMemoryDC();
    hugedc->SelectObject(*hugebitmap); // Writing to the DC writes into bitmap
    bitmap = new wxBitmap(screenWidth, screenHeight, wxBITMAP_SCREEN_DEPTH);
    bitdc = new wxMemoryDC();

// I am now going to pick a default initial size for the client area
// of my main window. The choice here is perhaps somewhat arbitrary and
// may only be good for MY screen.
    windowWidth = 1120;      // default size = 14*80
    windowHeight = 1024;
// If the default size would fill over 90% of screen width or height I scale
// down to make it fit better. The consequence of this is that on computers
// with other than HD screens the window will not end up a neat multiple
// of anything in particular in size.
    if (10*windowWidth > 9*screenWidth)
    {   windowHeight = windowHeight*95*screenWidth/(100*windowWidth);
        windowWidth = 95*screenWidth/100;
        logprintf("reset to %d by %d to fix width\n", windowWidth, windowHeight);
    }
    if (10*windowHeight > 9*screenHeight)
    {   windowWidth = windowWidth*95*screenHeight/(100*windowHeight);
        windowHeight = 95*screenHeight/100;
        logprintf("reset to %d by %d to fix height\n", windowWidth, windowHeight);
    }

    panel = new showmathPanel(this, showmathfilename);
    SetMinClientSize(wxSize(400, 100));
// What I do here allows the complete window (including its borders and
// decorations) to end up larger than my screen, but the client area is
// strictly smaller than the screen. This latter point may be important
// in that it means that hugebitmap always maps an area strictly larger than
// the window I will display in.
    SetMaxClientSize(wxSize(screenWidth-1, screenHeight-1));
    SetClientSize(windowWidth, windowHeight);
    Centre();
// I will now create a font suitable for writing into the huge
// bitmap. Well here I will just make one using "CMU Typewriter Text", a
// fixed pitch font. I start by creating a font that is 1000 points. This
// is of course ridiculously large, but maybe it lets me measure widths
// accurately.
    wxFontInfo hugefi(1000);
    hugefi.FaceName("CMU Typewriter Text");
    wxFont tempFont(hugefi);
    int w, h, d, xl;
    hugedc->SetFont(tempFont);
    hugedc->GetTextExtent("X", &w, &h, &d, &xl);
    logprintf("w=%d, h=%d, d=%d xl=%d\n", w, h, d, xl);
// Now because I happen to have a known font and a simple bitmap to write into
// I think that the font measurements I get ought to be pretty well constant,
// but I will still act as if they might not be.
    logprintf("Want to scale by %.3f to get width %d\n", sw/(80.0*w), sw);
    int pointSize = (sw*1000)/(80*w);
    logprintf("try point size = %d\n", pointSize);
    for (;;)
    {   tempFont.SetPointSize(pointSize);
        hugedc->SetFont(tempFont);
        hugedc->GetTextExtent("X", &w, &h, &d, &xl);
        logprintf("w=%d, h=%d, d=%d xl=%d\n", w, h, d, xl);
        if (80*w <= sw) break;
        pointSize--;
    }
    char_width = w;   // Width of (fixed pitch) characters on hugebitmap.
    char_offset = h - d;
    char_linespace = h + xl;
    hugefont = new wxFont(tempFont);
//
// Now so that I can see what is going in a bit I will draw a row of
// characters across the top of hugebitmap...
    hugedc->SetBackground(*wxWHITE_BRUSH);
    hugedc->Clear();
    for (int i=0; i<80; i++)
        hugedc->DrawText(wxString((wchar_t)(i+0x21)),
           i*char_width,
           char_linespace - char_offset);
// Now the above will not have any visible effect at all! 
    bitdc->SelectObject(*bitmap); // Writing to the DC writes into bitmap
    bitdc->SetBackground(*wxCYAN);
    bitdc->Clear();
    fflush(stdout);

// Copy into the smaller bitmap...
#ifdef STRETCHBLIT
// This seems to rescale things properly, but does not anti-alias and
// so the result is really crudely rendered.
    bitdc->StretchBlit(0, 0, windowWidth, windowHeight,
        hugedc, 0, 0, 80*char_width, 1+(80*char_width*windowHeight)/windowHeight); 
#endif
#if 1 //def GRAPHICSCONTEXT
    wxGraphicsContext *gg = wxGraphicsContext::Create(*bitdc);
    gg->Scale(0.123, 0.123);
    logprintf("AA mode = %d\n", gg->GetAntialiasMode());
    logprintf("AA supported = %d\n", gg->SetAntialiasMode(wxANTIALIAS_DEFAULT));
    logprintf("AA mode = %d\n", gg->GetAntialiasMode());
    gg->DrawBitmap(*hugebitmap, 0.0, 0.0, 80*char_width, windowHeight/0.123);
    delete gg;
#endif



}



static char default_data[4096] =
    "deffont 1 Regular 24;"
    "put 1 -408 0 84;"
    "put 1 14256 0 104;"
    "put 1 26256 0 101;"
    "put 1 36912 0 32;"
    "put 1 42912 0 98;"
    "put 1 54912 0 111;"
    "put 1 66384 0 121;"
    "put 1 78384 0 32;"
    "put 1 84384 0 115;"
    "put 1 93528 0 116;"
    "put 1 100152 0 111;"
    "put 1 112152 0 111;"
    "put 1 124152 0 100;"
    "put 1 136152 0 32;"
    "put 1 142152 0 111;"
    "put 1 154152 0 110;"
    "put 1 166152 0 32;"
    "put 1 172152 0 116;"
    "put 1 179016 0 104;"
    "put 1 191016 0 101;"
    "put 1 201672 0 32;"
    "put 1 207672 0 98;"
    "put 1 219672 0 117;"
    "put 1 231672 0 114;"
    "put 1 240168 0 110;"
    "put 1 252168 0 105;"
    "put 1 258840 0 110;"
    "put 1 270840 0 103;"
    "put 1 282840 0 32;"
    "put 1 288840 0 100;"
    "put 1 300840 0 101;"
    "put 1 311496 0 99;"
    "put 1 321624 0 107;"
    "put 1 333744 0 44;"
    "put 1 339744 0 32;"
    "put 1 345744 0 119;"
    "put 1 363072 0 104;"
    "put 1 375072 0 101;"
    "put 1 385728 0 110;"
    "put 1 397728 0 99;"
    "put 1 408384 0 101;"
    "put 1 419040 0 32;"
    "put 1 425040 0 97;"
    "put 1 435696 0 108;"
    "put 1 442368 0 108;"
    "put 1 449040 0 32;"
    "put 1 455040 0 98;"
    "put 1 467040 0 117;"
    "put 1 479040 0 116;"
    "put 1 485712 0 32;"
    "put 1 491712 0 104;"
    "put 1 503712 0 101;"
    "put 1 514368 0 32;"
    "put 1 520368 0 104;"
    "put 1 532368 0 97;"
    "put 1 543024 0 100;"
    "put 1 555024 0 32;"
    "put 1 561024 0 102;"
    "put 1 570072 0 108;"
    "put 1 576744 0 101;"
    "put 1 587400 0 100;"
    "put 1 599400 0 46;";

// When I construct this I must avoid the wxTAB_TRAVERSAL style since that
// tends to get characters passed to child windows not this one. Avoiding
// that is the reason behind providing so many arguments to the parent
// constructor

showmathPanel::showmathPanel(showmathFrame *parent, const char *showmathfilename)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition,
              wxDefaultSize, 0L,"showmathPanel")
{
// I will read in any data once here and put it in a character buffer.
    FILE *f = NULL;
    if (showmathfilename == NULL) showmathData = default_data;
    else
    {   int i;
        stringInput = NULL;
        f = fopen(showmathfilename,"r");
        if (f == NULL)
        {   logprintf("File \"%s\" not found\n", showmathfilename);
            exit(1);
        }
        fseek(f, (off_t)0, SEEK_END);
        off_t len = ftell(f);
        showmathData = (char *)malloc(4+(size_t)len);
        fseek(f, (off_t)0, SEEK_SET);
        for (i=0; i<len; i++) showmathData[i] = getc(f);
        showmathData[i] = 0;
        fclose(f);
    }
    for (int i=0; i<MAX_FONTS; i++)
    {   FontValid[i] = false;
        Baseline[i] = 0;
    }
}


void showmathFrame::OnClose(wxCloseEvent &WXUNUSED(event))
{   Destroy();
#ifdef WIN32
// Otherwise under XP bad things happen for me. Like the application
// re-launching. I do not think I understand, but the extreme action of
// utterly killing the process does what I need!
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void showmathFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{   Destroy();
#ifdef WIN32
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void showmathFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{
// At present this never gets activated!
    wxMessageBox(
        wxString::Format(
            "wxshowmath (A C Norman 2016)\n"
              "wxWidgets version: %s\n"
              "Operating system: %s",
            wxVERSION_STRING,
            wxGetOsDescription()),
        "About wxshowmath",
        wxOK | wxICON_INFORMATION,
        this);
}

void showmathFrame::OnSize(wxSizeEvent &WXUNUSED(event))
{   wxSize client(GetClientSize());
    panel->SetSize(client);
    panel->Refresh();
}

void showmathPanel::OnChar(wxKeyEvent &event)
{
// This merely records the character in the log file.
    const char *msg ="OnChar", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
}

void showmathPanel::OnKeyDown(wxKeyEvent &event)
{
// Again merely log the event.
    const char *msg ="OnKeyDown", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void showmathPanel::OnKeyUp(wxKeyEvent &event)
{
// Merely log the event.
    const char *msg ="OnKeyUp", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void showmathPanel::OnMouse(wxMouseEvent &event)
{
// Log but take no action.
    logprintf("Mouse event\n");
    event.Skip();
//  Refresh();     // forces redraw of everything
}

//- static int32_t convert_font_name(char *dest, char *src)
//- {
//- // The font name passed should be one of
//- //    cmuntt
//- //    odokai
//- //    math
//- //    <anything else>
//- //    <anything else>-Bold
//- //    <anything else>-Italic
//- //    <anything else>-BoldItalic
//- //
//-     int32_t r = wxFONTFLAG_DEFAULT;
//-     if (strcmp(src, "cmuntt") == 0) strcpy(dest, "CMU Typewriter Text");
//-     else if (strcmp(src, "odokai") == 0) strcpy(dest, "AR PL New Kai");
//-     else if (strcmp(src, "Math") == 0) strcpy(dest, "cslSTIXMath");
//-     else sprintf(dest, "cslSTIX");
//- // Here if the font name is suffixed as "-Bold" or "-Italic" or "-BoldItalic"
//-     if (strcmp(dest, "CMU Typewriter Text") == 0) r |= (F_cmuntt<<16);
//-     else if (strcmp(dest, "AR PL New Kai") == 0) r |= (F_odokai<<16);
//-     else if (strcmp(dest, "cslSTIXMath") == 0) r |= (F_Math<<16);
//- // I have not thought through and implemented support for bold and italic
//- // options here...
//- #ifdef PENDING_BOLD_AND_ITALIC
//-     else if ((r & (wxFONTFLAG_BOLD + wxFONTFLAG_ITALIC)) ==
//-              (wxFONTFLAG_BOLD + wxFONTFLAG_ITALIC)) r |= (F_BoldItalic<<16);
//-     else if ((r & wxFONTFLAG_BOLD) ==
//-              wxFONTFLAG_BOLD) r |= (F_Bold<<16);
//-     else if ((r & wxFONTFLAG_ITALIC) ==
//-              wxFONTFLAG_ITALIC) r |= (F_Italic<<16);
//-     else
//- #endif
//-     r |= (F_Regular<<16);
//-
//-     logprintf("Gives %s with flags %x\n", dest, r); fflush(stdout);
//-     return r;
//- }

static void allow_for_utf16(wchar_t *ccc, int cp)
{   if (sizeof(wchar_t) == 4 ||
        cp <= 0xffff)
    {   ccc[0] = cp;
        ccc[1] = 0;
    }
    else
    {   cp = (cp - 0x10000) & 0xfffff;
        ccc[0] = 0xd800 + (cp >> 10);
        ccc[1] = 0xdc00 + (cp & 0x3ff);
//      logprintf("Char mapped to %x %x\n", ccc[0], ccc[1]);
        ccc[2] = 0;
    }
}

void showmathPanel::OnPaint(wxPaintEvent &event)
{   wxPaintDC mydc(this);
    mydc.Blit(0, 0, windowWidth, windowHeight,
              bitdc, 0, 0); 
    return;

// The next could probably be done merely by setting a background colour
    wxColour c1(230, 200, 255);
    wxBrush b1(c1);
//-     gc->SetBrush(b1);
    wxSize window(mydc.GetSize());
    logprintf("Window is %d by %d\n", window.GetWidth(), window.GetHeight());
//-     gc->DrawRectangle(0.0, 0.0,
//-                       (double)window.GetWidth(),
//-                       (double)window.GetHeight());
//-
//- // The FixedPitch font will be for a line spacing of 24 pixels,
//- // but I will scale it as relevant.
//-     FixedPitch =
//-         gc->CreateFont(
//-             wxFont(wxFontInfo(24).FaceName(wxT("CMU Typewriter Text"))));
//-     double dwidth, dheight, ddepth, dleading;
//-     gc->SetFont(FixedPitch);
//-     gc->GetTextExtent(wxT("M"), &dwidth, &dheight, &ddepth, &dleading);
//-     char_width = dwidth;
//-     logprintf("char_width=%#.6g\n", char_width);
//-     logprintf("height = %#.6g total height = %#.6g leading = %#.6g\n",
//-               dheight-ddepth-dleading, dheight, dleading);
//-
//-     double screenWidth = (double)window.GetWidth();
//-     double lineWidth = 80.0*char_width;
//-     double scale = screenWidth/lineWidth;
//- // This will now scale everything so that I end up with 80 characters from
//- // that fixed-pitch font across the width of my window.
//-     gc->Scale(scale, scale);
//-     logprintf("Scale now %.6g\n", scale); fflush(stdout);
//-
//- // Now I should find how all my fonts will be arranged in terms of the
//- // distance from the index point used by wxWidgets to the font base-line
//- // as relevent in .afm metrics.
//-     for (;;)
//-     {   int ddd;
//-         wxGraphicsFont tf1 =
//-             gc->CreateFont(10000.0, "cslSTIX",
//-                            wxFONTFLAG_BOLD + wxFONTFLAG_ITALIC);
//-         gc->SetFont(tf1);
//-         gc->GetTextExtent(wxString((wchar_t)'X'),
//-                           &dwidth, &dheight, &ddepth, &dleading);
//-         logprintf("%.6g %.6g [%.6g]\n",
//-                   dheight, ddepth, dheight-ddepth);
//-         ddd = (int)((dheight - ddepth)/10.0 + 0.5);
//-         if (ddd == chardepth_WIN32[F_BoldItalic])
//-         {   chardepth = chardepth_WIN32;
//-             tf1 = FixedPitch;
//-             break;
//-         }
//-         tf1 =
//-             gc->CreateFont(10000.0, "AR PL New Kai", wxFONTFLAG_DEFAULT);
//-         gc->SetFont(tf1);
//-         gc->GetTextExtent(wxString((wchar_t)'X'),
//-                           &dwidth, &dheight, &ddepth, &dleading);
//-         logprintf("%.6g %.6g [%.6g]\n",
//-                   dheight, ddepth, dheight-ddepth);
//-         ddd = (int)((dheight - ddepth)/10.0 + 0.5);
//-         if (ddd == chardepth_X11[F_odokai])
//-         {   chardepth = chardepth_X11;
//-             tf1 = FixedPitch;
//-             break;
//-         }
//-         tf1 =
//-             gc->CreateFont(10000.0, "cslSTIXMath", wxFONTFLAG_DEFAULT);
//-         gc->SetFont(tf1);
//-         gc->GetTextExtent(wxString((wchar_t)unicode_INTEGRAL),
//-                           &dwidth, &dheight, &ddepth, &dleading);
//-         logprintf("%.6g %.6g [%.6g]\n",
//-                   dheight, ddepth, dheight-ddepth);
//-         ddd = (int)((dheight - ddepth)/10.0 + 0.5);
//-         if (ddd == chardepth_OSX[F_Math])
//-         {   chardepth = chardepth_OSX;
//-             tf1 = FixedPitch;
//-             break;
//-         }
//-         logprintf("\n+++ Character positioning not recognized\n");
//-         chardepth = chardepth_X11;
//-         tf1 = FixedPitch;
//-         break;
//-     }

//-     gc->SetFont(FixedPitch);
//-     double width, height, descent, xleading;
//-     gc->GetTextExtent(wxString((wchar_t)'x'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g fixedpitch\n", width, height, descent, xleading);
//-     FixedPitchBaseline = height - descent;
//-     logprintf("Fixed Pitch Baseline = %.6g\n", height-descent);
//- // Sort of for fun I put a row of 80 characters at the top of the screen
//- // so I can show how fixed pitch stuff might end up being rendered.
//-     gc->SetFont(FixedPitch);
//-     for (int i=0; i<80; i++)
//-         gc->DrawText(wxString((wchar_t)(i+0x21)), (double)i*char_width, 24.0-FixedPitchBaseline);
#if 0
    wxColour c2(29, 99, 25);
    wxBrush b2(c2);
    gc->SetBrush(b2);
    for (int x=0; x<1000; x+=10)
        for (int y=0; y<=1000; y+=10)
            if (((x/10)+(y/10)) & 1 != 0)
                gc->DrawRectangle((double)x, (double)y, 10.0, 10.0);
#endif


//- // Now I need to do something more serious!
//-     wxGraphicsFont regular =
//-         gc->CreateFont(wxFont(wxFontInfo(24).FaceName(wxT("cslSTIX"))));
//-     if (regular.IsNull()) logprintf("cslSTIX font not created\n");
//-     gc->SetFont(regular);
//-     gc->GetTextExtent(wxString((wchar_t)'x'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g regular\n", width, height, descent, xleading);
//-     double regularBaseline = height - descent;
//-     logprintf("regular baseline = %.6g\n", height-descent);
//-     wxGraphicsFont math =
//-         gc->CreateFont(wxFont(wxFontInfo(24).FaceName(wxT("cslSTIXMath"))));
//-     if (math.IsNull()) logprintf("cslSTIXMath font not created\n");
//-     else logprintf("Sym font should be OK\n");
//-     gc->SetFont(math);
//-     gc->GetTextExtent(wxString((wchar_t)'x'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g math\n", width, height, descent, xleading);
//-     gc->GetTextExtent(wxString((wchar_t)'M'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g math\n", width, height, descent, xleading);
//-     gc->GetTextExtent(wxString((wchar_t)'j'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g math\n", width, height, descent, xleading);
//-     double symbolsBaseline = height - descent;

// cslSTIXMath puts the glyphs used to build up huge delimiters in a
// private use area. It expects the code to use maths tables to discover
// where they are rather than mere unicode names.

#define stix_LEFT_CURLY_BRACKET_UPPER_HOOK    0x10821c
#define stix_LEFT_CURLY_BRACKET_MIDDLE_PIECE  0x10821d
#define stix_CURLY_BRACKET_EXTENSION          0x10821f
#define stix_LEFT_CURLY_BRACKET_LOWER_HOOK    0x10821e
//-     gc->SetFont(math);
//-     gc->GetTextExtent(wxT("M"), &dwidth, &dheight, &ddepth, &dleading);
//-     logprintf("(D)char_width=%#.3g\n", dwidth);
//-     logprintf("(D)height = %#.3g total height = %#.3g leading = %#.3g\n",
//-               dheight-ddepth-dleading, dheight, dleading);
//-     lookupchar(F_Math, stix_LEFT_CURLY_BRACKET_UPPER_HOOK);
//-     logprintf("upper hook   %d %d\n", c_lly, c_ury);
//-     lookupchar(F_Math, stix_LEFT_CURLY_BRACKET_MIDDLE_PIECE);
//-     logprintf("middle piece %d %d\n", c_lly, c_ury);
//-     lookupchar(F_Math, stix_LEFT_CURLY_BRACKET_LOWER_HOOK);
//-     logprintf("lower hook   %d %d\n", c_lly, c_ury);
//-     lookupchar(F_Math, stix_CURLY_BRACKET_EXTENSION);
//-     logprintf("extension    %d %d\n", c_lly, c_ury);
//- #define H (24.0)
//- #define XX 120.0
//- #define YY 100.0
//-     {   wchar_t ccc[4];
//-         allow_for_utf16(ccc, stix_LEFT_CURLY_BRACKET_UPPER_HOOK);
//-         gc->DrawText(wxString(ccc), XX, YY-H-symbolsBaseline);
//-         allow_for_utf16(ccc, stix_LEFT_CURLY_BRACKET_MIDDLE_PIECE);
//-         gc->DrawText(wxString(ccc), XX, YY-symbolsBaseline);
//-         allow_for_utf16(ccc, stix_CURLY_BRACKET_EXTENSION);
//-         gc->DrawText(wxString(ccc), XX, YY+H-symbolsBaseline);
//-         allow_for_utf16(ccc, stix_LEFT_CURLY_BRACKET_LOWER_HOOK);
//-         gc->DrawText(wxString(ccc), XX, YY+2.0*H-symbolsBaseline);
//-     }
//- // The next two have codepoints in the Basic Multilingual Plane so
//- // I do not need to mess around with encoding even on platforms like
//- // Windows that use UTF16 internally.
//-     gc->SetFont(regular);
//-     gc->DrawText(wxString((wchar_t)unicode_GREEK_SMALL_LETTER_OMEGA),        XX, YY+100.0-regularBaseline);
//-     gc->DrawText(wxString((wchar_t)unicode_RIGHT_ANGLE_WITH_DOWNWARDS_ZIGZAG_ARROW), XX+100.0, YY+100.0-regularBaseline);

    char *in = showmathData;
    logprintf("About to process data:\n\"%.70s\"... ...\n\n", in);
    do
    {   int x, y, n, cp, size;
        char name[100], name1[64];
        while (isspace(*in)) in++;
        if (*in == 0) break;
        if (*in == '#' || *in == '%')
// # ...     comments extend to the end of the line
// % ...
        {   n = 0;
            while (*in != 0 && *in != '\n')
                if (n < 99) name[n++] = *in++;
                else in++;
            name[n] = 0;
            logprintf("%s\n", name);
            if (*in == '\n') in++;
            continue;
        }
        else if (sscanf(in, "deffont %d %60s %d;", &n, name, &size) == 3 &&
// deffont number name size;   define font with given number
                 0 <= n &&
                 n < MAX_FONTS)
        {   //- int flags = convert_font_name(name1, name);
            //- int col;
            logprintf("font[%d] = \"%s\" size %d\n", n, name1, size);
//-             graphicsFont[n] = gc->CreateFont((double)size, name1, flags & 0xffff);
//-             gc->SetFont(graphicsFont[n]);
//-             gc->GetTextExtent(wxString((wchar_t)'('), &width, &height, &descent, &xleading);
//-             logprintf("( %s/%d: %.6g %.6g [%.6g]\n",
//-                       name1, size, height, descent, height-descent);
//-             col = logprintf("    %d,", (int)((height - descent)/10.0 + 0.5));
//-             while (col++ < 20) logprintf(" ");
//-             logprintf("// %s\n", name);
//-             graphicsBaseline[n] =
//-                 (double)size * (double)chardepth[(flags >> 16) & 0x1f] / 1000.0;
//-             logprintf("from table baseline offset = %.6g\n", graphicsBaseline[n]);
        }
        else if (sscanf(in, "put %d %d %d 0x%x;", &n, &x, &y, &cp) == 4 ||
                 sscanf(in, "put %d %d %d %d;", &n, &x, &y, &cp) == 4)
        {
// put fontnum xpos ypos codepoint;  dump character onto screen
// note x & y in units of 1/1000 point.
//          logprintf("Font %d (%d,%d) char %d = %#x\n", n, x, y, cp, cp);
//-             gc->SetFont(graphicsFont[n]);
            wchar_t ccc[4];
// For the benefit of Windows I need to represent code points in other
// then the basic multilingual pane as surrogate pairs. Well that will
// probably apply anywhere where sizeof(wchar_t) < 4.
            allow_for_utf16(ccc, cp);
//-             gc->DrawText(wxString(ccc),
//-                          x/1000, 400-y/1000-graphicsBaseline[n]);
        }
        else logprintf("\nLine <%.32s> unrecognised\n", in);
        in = strchr(in, ';');
        if (in != NULL) in++;
    }
    while (in != NULL);

// I will mark all the fonts I might have created as invalid now
// that the context they were set up for is being left.
    for (int i=0; i<MAX_FONTS; i++) FontValid[i] = false;
    return;
}

// A dummy definition that is needed because of wxfwin.cpp

int windowed_worker(int argc, const char *argv[],
                    fwin_entrypoint *fwin_main)
{   return 0;
}

// end of wxshowmath.cpp
