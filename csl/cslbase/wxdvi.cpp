// wxdvi.cpp

// A sample wxWidgets application to display dvi files.
// This will ONLY cope with a set of fonts that it itself
// provides, and is not (at least at first) going to worry about
// multiple pages. Indeed it will be pretty crude! But it may illustrate
// that I can display mathematics on the screen, and when I can do that
// I will then want to ensure that I can print it too. Thinking about
// editing the maths or doing cut-and-paste operations seems very hard
// and remote at present!
//


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

/* $Id$ */


// The first few lines are essentially taken from the wxWidgets documentation
// and will be the same for almost all wxWidgets code.

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/display.h>
#include <wx/graphics.h>
#include <wx/filename.h>

#include "config.h"

#include "wxfwin.h"

#ifdef WIN32
// I will need a few windows-specific headers. Mainly to let me set
// gdi+ antialiasing options. The newest versions of the i686-w64-mingw32
// toolchain provide gdiplus.h, but ones from a while back may not, so if
// necessary ensure you are fully up to date.

#include <windows.h>
#include <wingdi.h>
#include <gdiplus.h>
#include <io.h>


#endif  // WIN32

// I may be old fashioned, but I will be happier using C rather than C++
// libraries here.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>

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

// I have a generated file that contains the widths of all the fonts
// I am willing to use here.

#include "cmfont-widths.cpp"

static FILE *logfile = NULL;

static void logprintf(const char *fmt, ...)
{
    va_list a;
    if (logfile == NULL) logfile = fopen("wxdvi.log", "w");
    if (logfile != NULL)
    {   va_start(a, fmt);
        vfprintf(logfile, fmt, a);
        fflush(logfile);
        va_end(a);
    }
#ifndef MACINTOSH
// On systems other than the Mac I expect I can (sometimes!) have a console
// attached to my program, and in that case it will be convenient to sent the
// trace output there as well as to a file.
    va_start(a, fmt);
    vprintf(fmt, a);
    va_end(a);
    fflush(stdout);
#endif
}



class dviApp : public wxApp
{
public:
    virtual bool OnInit();
};

class dviPanel : public wxPanel
{
public:
    dviPanel(class dviFrame *parent, const char *dvifilename);

    void OnPaint(wxPaintEvent &event);

// The event handling is not really needed for this application, but I
// am putting some in so I can experiment with it!
    void OnChar(wxKeyEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    void OnKeyUp(wxKeyEvent &event);
    void OnMouse(wxMouseEvent &event);

private:
    wxGraphicsFont graphicsFixedPitch;
    bool fixedPitchValid;

    void RenderDVI();        // sub-function used by OnPaint
    wxGraphicsContext *gc;   // ditto but in wxGraphics mode

    unsigned char *dviData;  // the .dvi file's contents are stored here
    unsigned const char *stringInput;

    int u2();                // read 1-4 bytes as signed or unsigned value
    int u3();
    int s1();
    int s2();
    int s3();
    int s4();

    void DefFont(int k);     // dvi file font definition
    void SelectFont(int k);
    int MapChar(int c);      // map from TeX character code to BaKoMa+ one
    void SetChar(int c);     // dvi display charcter and move on
    void PutChar(int c);     // dvi just display character
    void SetRule(int height, int width);
    double DVItoScreen(int n);  // map coordinates
    double DVItoScreenUP(int n);// ditto but used for rule widths

    int32_t h, v, w, x, y, z;// working values used in DVI decoding

    int32_t C[10], p;        // set by start of a page and not used!

// dvi files can call for an essentially unlimited number of distinct
// fonts - where one "font" here is not just to do with shape but also with
// size. If I pre-scanned the dvi data I could identify the largest font
// number used and allocate a table of exactly the right size. But for now
// I will use a fixed limit.
//
#define MAX_FONTS 256
    wxGraphicsFont graphicsFont[MAX_FONTS];       // the fonts I use here
    bool graphicsFontValid[MAX_FONTS];         // the fonts I use here
    font_width *fontWidth[MAX_FONTS], *currentFontWidth;
    double em;

// dvi files use a stack, and at the end of the file is an indication of
// the greatest stack depth that will be used. I just give myself a fixed
// quota for now.
#define MAX_STACK 100
    int32_t stack[6*MAX_STACK];
    int stackp;

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(dviPanel, wxPanel)
    EVT_PAINT(           dviPanel::OnPaint)
    EVT_CHAR(            dviPanel::OnChar)
//  EVT_KEY_DOWN(        dviPanel::OnKeyDown)
//  EVT_KEY_UP(          dviPanel::OnKeyUp)
    EVT_LEFT_UP(         dviPanel::OnMouse)
END_EVENT_TABLE()

class dviFrame : public wxFrame
{
public:
    dviFrame(const char *dvifilename);

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);

private:
    int screenWidth, screenHeight;

    dviPanel *panel;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(dviFrame, wxFrame)
    EVT_CLOSE(           dviFrame::OnClose)
    EVT_MENU(wxID_EXIT,  dviFrame::OnExit)
    EVT_MENU(wxID_ABOUT, dviFrame::OnAbout)
    EVT_SIZE(            dviFrame::OnSize)
END_EVENT_TABLE()

#define LONGEST_LEGAL_FILENAME 1000

int main(int argc, const char *argv[])
{
    int i;
    int usegui = 1;
// I have had a case where my code appears to run happily when I run it
// under gdb or when I have compiled it with full debugging options, but
// where it crashes on Windows if build in "release" mode. To try to debug
// in a case like that I add explicit print statements as follows...
#if DEBUG
    logprintf("Starting wxdvi program\n");
#endif
// Find where I am invoked from before doing anything else
    find_program_directory(argv[0]);
    for (i=1; i<argc; i++)
    {   if (strncmp(argv[i], "-w", 2) == 0) usegui = 0;
    }
#if !defined WIN32 && !defined MACINTOSH
// Under X11 I will demote to being a console mode application if DISPLAY
// is not set. This is not a perfect test but it will spot the simple
// cases. Eg I could look at stdin & stdout and check if it looks as if
// they are pipes of they have been redirected...
    {   const char *s = my_getenv("DISPLAY");
        if (s==NULL || *s == 0) usegui = 0;
    }
#endif
#if DEBUG
    logprintf("usegui=%d\n", usegui);
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
                const char **nargs = (const char **)malloc(sizeof(char *)*(argc+3));
                int i;
                nargs[0] = "/usr/bin/open";
                nargs[1] = xname;
                nargs[2] = "--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
// /usr/bin/open foo.app --args [any original arguments]
                return execv("/usr/bin/open", const_cast<char * const *>(nargs));
            }
        }
#endif
        wxDISABLE_DEBUG_SUPPORT();
#if DEBUG
    logprintf("calling wxEntry\n");
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

IMPLEMENT_APP_NO_MAIN(dviApp)

// Pretty much everything so far has been uttery stylised and the contents
// are forced by the structure that wxWidgets requires!



//
// Now that start of my code in a proper sense!
//
//


/*
 * This is the ".dvi" file created by running LaTeX on the following
 * small input file. It is provided as a sequence of hex bytes so that
 * I have something to test and demonstrate even if there is no file
 * containing any .dvi stuff readily available.
 *
 * \documentclass{article}
 * \begin{document}
 * \noindent This is some text
 * \[ \left( \int_{b=0}^{\infty} \frac{- \beta \pm \sqrt{b^2 -
 *  4 \, \omega \, c}}{2\, a}\, \mathrm{d}x \right\} \]
 * end text
 * \end{document}
 */

unsigned char mathDvi[] =
{
    0xf7,  0x02,  0x01,  0x83,  0x92,  0xc0,  0x1c,  0x3b,
    0x00,  0x00,  0x00,  0x00,  0x03,  0xe8,  0x1b,  0x20,
    0x54,  0x65,  0x58,  0x20,  0x6f,  0x75,  0x74,  0x70,
    0x75,  0x74,  0x20,  0x32,  0x30,  0x31,  0x30,  0x2e,
    0x31,  0x31,  0x2e,  0x31,  0x33,  0x3a,  0x31,  0x36,
    0x31,  0x33,  0x8b,  0x00,  0x00,  0x00,  0x01,  0x00,
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
    0x00,  0x00,  0x00,  0xff,  0xff,  0xff,  0xff,  0xa0,
    0x02,  0x79,  0x00,  0x00,  0x8d,  0xa0,  0xfd,  0xa3,
    0x00,  0x00,  0xa0,  0x02,  0x3f,  0x00,  0x00,  0x8d,
    0xa0,  0xfd,  0xe4,  0x00,  0x00,  0x8d,  0x91,  0x3e,
    0x00,  0x00,  0xf3,  0x07,  0x4b,  0xf1,  0x60,  0x79,
    0x00,  0x0a,  0x00,  0x00,  0x00,  0x0a,  0x00,  0x00,
    0x00,  0x05,  0x63,  0x6d,  0x72,  0x31,  0x30,  0xb2,
    0x54,  0x68,  0x69,  0x73,  0x96,  0x03,  0x55,  0x55,
    0x69,  0x73,  0x93,  0x73,  0x6f,  0x6d,  0x65,  0x93,
    0x74,  0x65,  0x78,  0x74,  0x8e,  0x9f,  0x12,  0x80,
    0x09,  0x8d,  0x8d,  0x8d,  0x92,  0x00,  0xaa,  0xc8,
    0x51,  0x9f,  0xee,  0xe6,  0x5c,  0xf3,  0x00,  0xfa,
    0xb1,  0x75,  0x12,  0x00,  0x0a,  0x00,  0x00,  0x00,
    0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  0x6d,  0x65,
    0x78,  0x31,  0x30,  0xab,  0x20,  0x8e,  0x8d,  0x92,
    0x00,  0xb2,  0xb2,  0xfd,  0x9f,  0xf2,  0x63,  0x87,
    0x5a,  0x8e,  0x8d,  0x9f,  0xf4,  0xdc,  0x69,  0x8d,
    0x92,  0x00,  0xbc,  0xb2,  0xfe,  0xf3,  0x0c,  0x4f,
    0x21,  0xe2,  0x85,  0x00,  0x07,  0x00,  0x00,  0x00,
    0x07,  0x00,  0x00,  0x00,  0x05,  0x63,  0x6d,  0x73,
    0x79,  0x37,  0xb7,  0x31,  0x8e,  0x9f,  0x14,  0x40,
    0x10,  0x8d,  0x92,  0x00,  0xb8,  0x41,  0x37,  0xf3,
    0x09,  0x30,  0x65,  0x97,  0x72,  0x00,  0x07,  0x00,
    0x00,  0x00,  0x07,  0x00,  0x00,  0x00,  0x05,  0x63,
    0x6d,  0x6d,  0x69,  0x37,  0xb4,  0x62,  0xf3,  0x06,
    0xd9,  0x93,  0xa0,  0x52,  0x00,  0x07,  0x00,  0x00,
    0x00,  0x07,  0x00,  0x00,  0x00,  0x04,  0x63,  0x6d,
    0x72,  0x37,  0xb1,  0x3d,  0x30,  0x8e,  0x8e,  0x8d,
    0x8d,  0x8d,  0x9f,  0xf9,  0x3c,  0x24,  0x8d,  0x92,
    0x00,  0xc9,  0x43,  0x59,  0xf3,  0x0d,  0x21,  0x22,
    0x2c,  0x9a,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x0a,
    0x00,  0x00,  0x00,  0x06,  0x63,  0x6d,  0x73,  0x79,
    0x31,  0x30,  0xb8,  0x00,  0xf3,  0x0a,  0x0b,  0xa0,
    0x62,  0x3e,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x0a,
    0x00,  0x00,  0x00,  0x06,  0x63,  0x6d,  0x6d,  0x69,
    0x31,  0x30,  0xb5,  0x0c,  0x91,  0x02,  0xbf,  0xfc,
    0xb8,  0x06,  0x8d,  0x8d,  0x91,  0x02,  0x38,  0xe0,
    0x9f,  0xf7,  0xaa,  0xab,  0x70,  0x8e,  0x8d,  0x91,
    0x0a,  0x8e,  0x37,  0x9f,  0xf7,  0xaa,  0xab,  0x89,
    0x00,  0x00,  0x66,  0x65,  0x00,  0x28,  0x3e,  0x7b,
    0x9f,  0x08,  0x55,  0x55,  0x8d,  0xb5,  0x62,  0x8d,
    0x9f,  0xfd,  0x1c,  0x72,  0xb1,  0x32,  0x8e,  0x91,
    0x06,  0xb5,  0x53,  0xb8,  0x00,  0x91,  0x02,  0x38,
    0xe0,  0xb2,  0x34,  0x91,  0x01,  0xaa,  0xa8,  0xb5,
    0x21,  0x91,  0x02,  0x06,  0x81,  0x63,  0x8e,  0x8e,
    0x8e,  0x8e,  0x92,  0x00,  0xc9,  0x43,  0x59,  0x9f,
    0x04,  0x77,  0x0e,  0x89,  0x00,  0x00,  0x66,  0x65,
    0x00,  0x4a,  0xc2,  0xea,  0x9f,  0x09,  0x28,  0xd6,
    0x8d,  0x91,  0x1f,  0x67,  0x89,  0xb2,  0x32,  0x91,
    0x01,  0xaa,  0xa8,  0xb5,  0x61,  0x8e,  0x8e,  0x8e,
    0x8e,  0x92,  0x01,  0x16,  0xe4,  0x1e,  0xb2,  0x64,
    0xb5,  0x78,  0x8d,  0x9f,  0xee,  0xe6,  0x5c,  0xab,
    0x29,  0x8e,  0x8e,  0x8e,  0x9f,  0x1a,  0x71,  0xd1,
    0x8d,  0x91,  0x3e,  0x00,  0x00,  0xb2,  0x65,  0x6e,
    0x64,  0x91,  0x03,  0x55,  0x55,  0x74,  0x65,  0x78,
    0x74,  0x8e,  0x8e,  0x9f,  0x1e,  0x00,  0x00,  0x8d,
    0x92,  0x00,  0xe8,  0x00,  0x00,  0x31,  0x8e,  0x8e,
    0x8c,  0xf8,  0x00,  0x00,  0x00,  0x2a,  0x01,  0x83,
    0x92,  0xc0,  0x1c,  0x3b,  0x00,  0x00,  0x00,  0x00,
    0x03,  0xe8,  0x02,  0x79,  0x00,  0x00,  0x01,  0x97,
    0x00,  0x00,  0x00,  0x0c,  0x00,  0x01,  0xf3,  0x0d,
    0x21,  0x22,  0x2c,  0x9a,  0x00,  0x0a,  0x00,  0x00,
    0x00,  0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  0x6d,
    0x73,  0x79,  0x31,  0x30,  0xf3,  0x0c,  0x4f,  0x21,
    0xe2,  0x85,  0x00,  0x07,  0x00,  0x00,  0x00,  0x07,
    0x00,  0x00,  0x00,  0x05,  0x63,  0x6d,  0x73,  0x79,
    0x37,  0xf3,  0x0a,  0x0b,  0xa0,  0x62,  0x3e,  0x00,
    0x0a,  0x00,  0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,
    0x06,  0x63,  0x6d,  0x6d,  0x69,  0x31,  0x30,  0xf3,
    0x09,  0x30,  0x65,  0x97,  0x72,  0x00,  0x07,  0x00,
    0x00,  0x00,  0x07,  0x00,  0x00,  0x00,  0x05,  0x63,
    0x6d,  0x6d,  0x69,  0x37,  0xf3,  0x07,  0x4b,  0xf1,
    0x60,  0x79,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x0a,
    0x00,  0x00,  0x00,  0x05,  0x63,  0x6d,  0x72,  0x31,
    0x30,  0xf3,  0x06,  0xd9,  0x93,  0xa0,  0x52,  0x00,
    0x07,  0x00,  0x00,  0x00,  0x07,  0x00,  0x00,  0x00,
    0x04,  0x63,  0x6d,  0x72,  0x37,  0xf3,  0x00,  0xfa,
    0xb1,  0x75,  0x12,  0x00,  0x0a,  0x00,  0x00,  0x00,
    0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  0x6d,  0x65,
    0x78,  0x31,  0x30,  0xf9,  0x00,  0x00,  0x02,  0x19,
    0x02,  0xdf,  0xdf,  0xdf,  0xdf,  0xdf,  0xdf,  0xdf
};



// Read 1, 2 3 or 4 byte integers from the input file, with the shorter
// variants being either signed or unsigned. All are arranged in big-endian
// style, as defined by the DVI format.

int32_t dviPanel::u2()
{
    int32_t c1 = *stringInput++;
    int32_t c2 = *stringInput++;
    return (c1 << 8) | c2;
}

int32_t dviPanel::u3()
{
    int32_t c1 = *stringInput++;
    int32_t c2 = *stringInput++;
    int32_t c3 = *stringInput++;
    return (c1 << 16) | (c2 << 8) | c3;
}

int32_t dviPanel::s1()
{
    return (int32_t)(int8_t)(*stringInput++);
}

int32_t dviPanel::s2()
{
    int32_t c1 = *stringInput++;
    int32_t c2 = *stringInput++;
    return (int32_t)(int16_t)((c1 << 8) | c2);
}

int32_t dviPanel::s3()
{
    int32_t c1 = *stringInput++;
    int32_t c2 = *stringInput++;
    int32_t c3 = *stringInput++;
    int32_t r = (c1 << 16) | (c2 << 8) | c3;
    if ((r & 0x00800000) != 0) r |= 0xff000000;
    return (int32_t)r;
}

int32_t dviPanel::s4()
{
    int32_t c1 = *stringInput++;
    int32_t c2 = *stringInput++;
    int32_t c3 = *stringInput++;
    int32_t c4 = *stringInput++;
    return (c1 << 24) | (c2 << 16) |
           (c3 << 8) | c4;
}


// The following two macros are syntactically delicate - so BEWARE.

#define push()         \
  stack[stackp++] = h; \
  stack[stackp++] = v; \
  stack[stackp++] = w; \
  stack[stackp++] = x; \
  stack[stackp++] = y; \
  stack[stackp++] = z

#define pop()          \
  z = stack[--stackp]; \
  y = stack[--stackp]; \
  x = stack[--stackp]; \
  w = stack[--stackp]; \
  v = stack[--stackp]; \
  h = stack[--stackp]

void dviPanel::DefFont(int k)
{
#if 0
    logprintf("Define Font %d at offset %d\n", k, (int)(stringInput - dviData));
#endif
    char fontname[LONGEST_LEGAL_FILENAME];
    int32_t checksum = s4();
    int32_t size = s4();
// The designsize in a .dvi file is given in units of points/2^16 while
// in .tfm data it is in units of points/2^20, so I adjust here so that the
// two sources of information should match.
    int32_t designsize = s4() << 4;
    int arealen = *stringInput++;
    int namelen = *stringInput++;
    if (k >= MAX_FONTS)
    {   logprintf("This code can only cope with MAX_FONTS distinct fonts\n");
        return;
    }
    if (arealen != 0)
    {   logprintf("Fonts with an area specification are not supported\n");
        return;
    }
    strcpy(fontname, "csl-");
    for (int i=0; i<namelen; i++) fontname[i+4] = *stringInput++;
    fontname[namelen+4] = 0;
    if (graphicsFontValid[k]) return;
#if 1
    logprintf("checksum = %.8x\n", checksum);
    logprintf("size = %d %g\n", size, (double)size/65536.0);
    logprintf("%s\n", fontname);
#endif
    font_width *p = cm_font_width;
    while (p->name != NULL &&
           strcmp(p->name, fontname+4) != 0) p++;
    if (p->name == NULL)
    {   logprintf("Fonts not found in the private font-set I support\n");
        return;
    }
// I find that cmmi7 and cmmi10 (and probably others) give me a complaint
// here as between the TeX fonts I have installed on cygwin and the BaKoMa
// ones I use for Reduce. However when I used tftopl to decode the
// apparently offending .tfm files what I found was pretty harmless (at least
// in cmmi7) in that the BaKoMa version defines widths for character octal 200
// (ie 0x80 = 128) while the other version did not. All metrics for other
// characters were identical. So I display a warning here for a while but
// will NOT make this an error. Now if I used BaKoMa TeX to prepare my .dvi
// files (or copies their fonts and metrics into where my main lot live)
// all oddities might go away.
    if (p->checksum != checksum)
    {   logprintf("Font checksum issue %#o vs %#o for %s\n",
               checksum, p->checksum, fontname);
// Continue in a spirit of optimism!
    }
    if (p->designsize != designsize)
    {   logprintf("Font designsize issue %x vs %x for %s\n",
               designsize, p->designsize, fontname);
// Continue in a spirit of optimism!
    }
    logprintf("Designsize = %.4g\n", (double)designsize/1048576.0);
    graphicsFont[k] = gc->CreateFont(designsize/1048576.0, fontname);
    graphicsFontValid[k] = true;
    fontWidth[k] = p;
}

void dviPanel::SelectFont(int n)
{
    if (n >= MAX_FONTS)
    {   logprintf("This code can only cope with MAX_FONTS distinct fonts\n");
        return;
    }
    if (!graphicsFontValid[n])
    {   logprintf("font %d seems not to be set\n", n);
        return;
    }
    gc->SetFont(graphicsFont[n]);
    currentFontWidth = fontWidth[n];
}


int dviPanel::MapChar(int c)
{
// This function maps between a TeX character encoding and the one that is
// used by the fonts and rendering engine that I use.
    if (c < 0xa) return 0xa1 + c;
    else if (c == 0xa) return 0xc5;
#ifdef UNICODE
// In Unicode mode I have access to the character at code point 0x2219. If
// not I must insist on using my private version of the fonts where it is
// at 0xb7.
    else if (c == 0x14) return 0x2219;
#endif
    else if (c < 0x20) return 0xa3 + c;
    else if (c == 0x20) return 0xc3;
    else if (c == 0x7f) return 0xc4;
    else if (c >= 0x80) return 0xa0;
    else return c;
}

double dviPanel::DVItoScreen(int n)
{
// At present this is a fixed scaling. I may well want to make it variable
// at some later stage. The scaling here, which is based on an assumption
// I make about the dots-per-inch resolution of my display, will end up
// important when establishing fonts.
    return (double)n/65536.0;
}

double dviPanel::DVItoScreenUP(int n)
{
// This ROUND UP to the next integer, and that is needed so that (eg)
// very thin rules end up at least one pixel wide. Well I round up by
// adding a value just under 1.0 then truncating. That recipe works OK for
// positive arguments!
// well using wxGraphicsContext I do not need to round.
    return (double)n/65536.0;
}

static int rendered = 0;

void dviPanel::SetChar(int32_t c)
{
#if 0
    logprintf("SetChar%d [%c] %d %d\n", (int)c, (c <  0x20 || c >= 0x7f ? ' ' : (int)c), (int)h, (int)v);
#endif
    wxString s = (wchar_t)MapChar(c);
    double width, height, descent, xleading;
    gc->GetTextExtent(s, &width, &height, &descent, &xleading);
    gc->DrawText(s, DVItoScreen(h), DVItoScreen(v)-(height-descent));
// Now I must increase h by the width (in scaled points) of the character
// I just set. This is not dependent at all on the way I map DVI internal
// coordinates to screen ones.
    int32_t ww = currentFontWidth->charwidth[c & 0x7f];
    int32_t design = currentFontWidth->designsize;
// ww is now the width as extracted from the .tfm file, and that applies
// to the glyph if it is set at its standard size. So adjust for all of
// that and end up in TeX coordinate units.
    int32_t texwidth =
        (int32_t)(0.5 + (double)design*(double)ww/
                        (double)(1<<24));
    h += texwidth;
#if 0
// Now I want to compare the width that TeX thinks the character has with
// what wxWidgets thinks. So I convert the TeX width to pixels.
    double twp = (double)(1024*1024)*(double)texwidth/
                 (72.0*65536.0*1000.0);
    logprintf("TeX says %#.6g wxWidgets says %.6g (%.6g)\n",
        twp, (double)width, twp/(double)width);
#endif
}

void dviPanel::PutChar(int32_t c)
{
#ifdef DEBUG
    if (!rendered)
    logprintf("Put (%.2f,%.2f) char %.2x (%c)\n",
        (double)h/(double)(1<<20), (double)v/(double)(1<<20), (int)c,
            c < 0x20 || c > 0x7f ? ' ' :  (int)c);
#endif
    wxString s = (wchar_t)MapChar(c);
    double width, height, descent, xleading;
    gc->GetTextExtent(s, &width, &height, &descent, &xleading);
    gc->DrawText(s, DVItoScreen(h), DVItoScreen(v)-(height-descent));
#if 0
// Now I want to compare the width that TeX thinks the character has with
// what wxWidgets thinks. So I convert the TeX width to pixels.
    int32_t ww = currentFontWidth->charwidth[c & 0x7f];
    int32_t design = currentFontWidth->designsize;
    int32_t texwidth =
        (int32_t)(0.5 + (double)design*(double)ww/
                        (double)(1<<24));
    double twp = (double)96*(double)texwidth/
                 (72.0*65536.0*1000.0);
    logprintf("TeX says %#.4g wxWidgets says %d (%.3g)\n",
        twp, width, twp/(double)width);
#endif
}

void dviPanel::SetRule(int height, int width)
{
#if 0
    logprintf("SetRule %d %.3g %d %.3g\n", width, (double)width/65536.0,
                                        height, (double)height/65537.0);
#endif
// The curious re-scaling here is so that the border of the rectangle does not
// end up fatter than the rectangle itself.
    wxGraphicsMatrix xform = gc->GetTransform();
    gc->Scale(0.01, 0.01);
    gc->DrawRectangle(100.0*DVItoScreen(h), 100.0*DVItoScreen(v-height),
                      100.0*DVItoScreenUP(width), 100.0*DVItoScreenUP(height));
    gc->SetTransform(xform);
}

void dviPanel::RenderDVI()
{

    gc->SetBrush(*wxBLACK_BRUSH);
    gc->SetPen(*wxBLACK_PEN);

// This always starts afresh at the start of the DVI data, which has been
// put in an array for me.
    stringInput = dviData;
    int32_t a, b, c, i, k;
    for (;;)
    {   c = *stringInput++;
        if (c <= 127)
        {   SetChar(c);
            continue;
        }
        else
        {   switch (c)
            {
        case 128: // set1
                SetChar(*stringInput++);
                continue;
        case 129: // set2
                SetChar(u2());
                continue;
        case 130: // set3
                SetChar(u3());
                continue;
        case 131: // set4
                SetChar(s4());
                continue;
        case 132: // set rule
                a = s4();
                b = s4();
                if (a > 0 && b > 0) SetRule(a, b);
                h += b;
                continue;
        case 133: // put1
                PutChar(*stringInput++);
                continue;
        case 134: // put2
                PutChar(u2());
                continue;
        case 135: // put3
                PutChar(u3());
                continue;
        case 136: // put4
                PutChar(s4());
                continue;
        case 137: // put rule
                a = s4();
                b = s4();
                if (a > 0 && b > 0) SetRule(a, b);
                continue;
        case 138: // nop
                continue;
        case 139: // beginning of page
                h = v = w = x = y = z = stackp = 0;
                for (i=0; i<10; i++)
                    C[i] = s4();
                p = s4();
                continue;
        case 140: // end of page
                continue;
        case 141: // push
                push();
                continue;
        case 142: // pop
                pop();
                continue;
        case 143: // right1
                h += s1();
                continue;
        case 144: // right2
                h += s2();
                continue;
        case 145: // right3
                h += s3();
                continue;
        case 146: // right4
                h += s4();
                continue;
        case 147: // w0
                h += w;
                continue;
        case 148: // w1
                h += (w = s1());
                continue;
        case 149: // w2
                h += (w = s2());
                continue;
        case 150: // w3
                h += (w = s3());
                continue;
        case 151: // w4
                h += (w = s4());
                continue;
        case 152: // x0
                h += x;
                continue;
        case 153: // x1
                h += (x = s1());
                continue;
        case 154: // x2
                h += (x = s2());
                continue;
        case 155: //x3
                h += (x = s3());
                continue;
        case 156: // x4
                h += (x = s4());
                continue;
        case 157: // down1
                v += s1();
                continue;
        case 158: // down2
                v += s2();
                continue;
        case 159: // down3
                v += s3();
                continue;
        case 160: // down4
                v += s4();
                continue;
        case 161: // y0
                v += y;
                continue;
        case 162: // y1
                v += (y = s1());
                continue;
        case 163: // y2
                v += (y = s2());
                continue;
        case 164: // y3
                v += (y = s3());
                continue;
        case 165: // y4
                v += (y = s4());
                continue;
        case 166: // z0
                v += z;
                continue;
        case 167: // z1
                v += (z = s1());
                continue;
        case 168: // z2
                v += (z = s2());
                continue;
        case 169: // z3
                v += (z = s3());
                continue;
        case 170: // z4
                v += (z = s4());
                continue;
        case 171:  case 172:  case 173:  case 174: // fnt
        case 175:  case 176:  case 177:  case 178:
        case 179:  case 180:  case 181:  case 182:
        case 183:  case 184:  case 185:  case 186:
        case 187:  case 188:  case 189:  case 190:
        case 191:  case 192:  case 193:  case 194:
        case 195:  case 196:  case 197:  case 198:
        case 199:  case 200:  case 201:  case 202:
        case 203:  case 204:  case 205:  case 206:
        case 207:  case 208:  case 209:  case 210:
        case 211:  case 212:  case 213:  case 214:
        case 215:  case 216:  case 217:  case 218:
        case 219:  case 220:  case 221:  case 222:
        case 223:  case 224:  case 225:  case 226:
        case 227:  case 228:  case 229:  case 230:
        case 231:  case 232:  case 233:  case 234:
                SelectFont(c - 171);
                continue;
        case 235: // fnt1
                SelectFont(*stringInput++);
                continue;
        case 236: // fnt2
                SelectFont(u2());
                continue;
        case 237: // fnt3
                SelectFont(u3());
                continue;
        case 238: // fnt4
                SelectFont(s4());
                continue;
        case 239: // xxx1
                k = *stringInput++;
                for (i=0; i<k; i++) (void)*stringInput++;
                continue;
        case 240: // xxx2
                k = u2();
                for (i=0; i<k; i++) (void)*stringInput++;
                continue;
        case 241: // xxx3
                k = u3();
                for (i=0; i<k; i++) (void)*stringInput++;
                continue;
        case 242: // xxx4
                k = s4();
                for (i=0; i<k; i++) (void)*stringInput++;
                continue;
        case 243: // fnt_def1
                DefFont(*stringInput++);
                continue;
        case 244: // fnt_def2
                DefFont(u2());
                continue;
        case 245: // fnt_def3
                DefFont(u3());
                continue;
        case 246: // fnt_def4
                DefFont(s4());
                continue;
        case 247: // pre
                i = *stringInput++;
                if (i != 2)
                {   logprintf("illegal DVI version %d\n", i);
                    break;
                }
                (void)s4();    // ignore num
                (void)s4();    // ignore den
                (void)s4();    // ignore mag
                k = *stringInput++;
                for (i=0; i<k; i++) (void)*stringInput++;
                continue;
        case 248: // post
                (void)s4(); // ignore p;
                (void)s4(); // ignure num
                (void)s4(); // ignore den
                (void)s4(); // ignore mag
                (void)s4(); // height+depth of largest page
                (void)s4(); // width of largest page
                (void)u2(); // stack depth
                (void)u2(); // page count
    // The postamble will have font definitions here as well.
                continue;
        case 249: // post_post
                (void)s4();
                (void)*stringInput++;
                if (*stringInput++ != 223) logprintf("Malformed DVI file\n");
                break;

        // 250-255 undefined
        default:
                logprintf("Unknown/undefined opcode %.2x\n", c);
                break;
            }
            break;
        }
    }
#if 0
    logprintf("end of file\n");
#endif
    rendered = 1;
}





bool dviApp::OnInit()
{
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;

#if DEBUG
    logprintf("in dviApp::OnInit\n");
#endif
    add_custom_fonts();
#if DEBUG
    logprintf("fonts added\n");
#endif

    const char *dvifilename = NULL;
    if (argc > 1) dvifilename = myargv[1];
    
#if DEBUG
    logprintf("dvifilename=%s\n",
              dvifilename == NULL ? "<null>" : dvifilename);
#endif

    dviFrame *frame = new dviFrame(dvifilename);
    frame->Show(true);
#if DEBUG
    logprintf("OnInint complete\n");
#endif
    return true;
}

dviFrame::dviFrame(const char *dvifilename)
       : wxFrame(NULL, wxID_ANY, "wxdvi")
{
    SetIcon(wxICON(fwin));
    int numDisplays = wxDisplay::GetCount(); // how many displays?
// It is not clear to me what I should do if there are several displays,
// and if there are none I am probably in a mess!
    if (numDisplays != 1)
    {   logprintf("There seem to be %d displays\n", numDisplays);
    }
    wxDisplay d0(0);                         // just look st display 0
    wxRect screenArea(d0.GetClientArea());   // omitting task bar
    screenWidth = screenArea.GetWidth();
    screenHeight = screenArea.GetHeight();
    logprintf("Usable area of screen is %d by %d\n", screenWidth, screenHeight);
// I will want to end up saving screen size (and even position) between runs
// of this program.
    int width = 1280;      // default size.
    int height = 1024;
// If the default size would fill over 90% of screen width or height I scale
// down to make it fit better.
    if (10*width > 9*screenWidth)
    {   height = height*9*screenWidth/(10*width);
        width = 9*screenWidth/10;
        logprintf("reset to %d by %d to fix width\n", width, height);
    }
    if (10*height > 9 * screenHeight)
    {   width = width*9*screenHeight/(10*height);
        height = 9*screenHeight/10;
        logprintf("reset to %d by %d to fix height\n", width, height);
    }
    panel = new dviPanel(this, dvifilename);
    SetMinClientSize(wxSize(400, 100));
    SetSize(width, height);
    wxSize client(GetClientSize());
    int w = client.GetWidth() % 80;
    if (w != 0) SetSize(width-w, height);
    Centre();
}


// When I construct this I must avoid the wxTAB_TRAVERSAL style since that
// tend sto get characters passed to child windows not this one. Avoiding
// that is the reason behind providing so many arguments to the parent
// constructor

dviPanel::dviPanel(dviFrame *parent, const char *dvifilename)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition,
                 wxDefaultSize, 0L, "dviPanel")
{
// I will read the DVI data once here.
    FILE *f = NULL;
    if (dvifilename == NULL) dviData = mathDvi;
    else
    {   stringInput = NULL;
        f = fopen(dvifilename, "rb");
        if (f == NULL)
        {   logprintf("File \"%s\" not found\n", dvifilename);
            exit(1);
        }
        fseek(f, (off_t)0, SEEK_END);
        off_t len = ftell(f);
        dviData = (unsigned char *)malloc((size_t)len);
        fseek(f, (off_t)0, SEEK_SET);
        for (int i=0; i<len; i++) dviData[i] = getc(f);
        fclose(f);
    }
    for (int i=0; i<MAX_FONTS; i++) graphicsFontValid[i] = false;
    fixedPitchValid = false;
}


void dviFrame::OnClose(wxCloseEvent &WXUNUSED(event))
{
    Destroy();
#ifdef WIN32
// Otherwise under XP bad things happen for me. Like the application
// re-launching.
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void dviFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{
    Destroy();
#ifdef WIN32
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void dviFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{
// At present this never gets activated!
    wxMessageBox(
       wxString::Format(
           "wxdvi (A C Norman 2010)\nwxWidgets version: %s\nOperating system: %s",
           wxVERSION_STRING,
           wxGetOsDescription()),
       "About wxdvi",
       wxOK | wxICON_INFORMATION,
       this);
}

void dviFrame::OnSize(wxSizeEvent &WXUNUSED(event))
{
    wxSize client(GetClientSize());
    panel->SetSize(client);
    panel->Refresh();
}

void dviPanel::OnChar(wxKeyEvent &event)
{
    const char *msg = "OnChar", *raw = "";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw = "Raw ";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
}

void dviPanel::OnKeyDown(wxKeyEvent &event)
{
    const char *msg = "OnKeyDown", *raw = "";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw = "Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void dviPanel::OnKeyUp(wxKeyEvent &event)
{
    const char *msg = "OnKeyUp", *raw = "";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw = "Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void dviPanel::OnMouse(wxMouseEvent &event)
{
    logprintf("Mouse event\n");
    event.Skip();
//  Refresh();     // forces redraw of everything
}

void dviPanel::OnPaint(wxPaintEvent &event)
{
    wxPaintDC mydc(this);
    gc = wxGraphicsContext::Create(mydc);
    logprintf("OnPaint: graphicsContext created at %p\n", gc);
    if (gc == NULL) return;
// The next could probably be done merely by setting a background colour
    wxColour c1(230, 200, 255);
    wxBrush b1(c1);
    logprintf("colour and brush made\n");
    gc->SetBrush(b1);
    logprintf("setbrush done\n");
    wxSize window(mydc.GetSize());
    logprintf("Window is %d by %d\n", window.GetWidth(), window.GetHeight());
    gc->DrawRectangle(0.0, 0.0,
                      (double)window.GetWidth(),
                      (double)window.GetHeight());
    logprintf("background drawn\n");

#if defined WIN32 && 0
// The Windows default behaviour fails to antialias some of the cmex10
// tall characters, and so unless I force antialiasing here I get MOST
// symbols rendered nicely, but big integral signs and parentheses badly
// blocky when the display exceeds a certain size. This is clearly down to
// the system default smoothing switching off for characters over a certain
// size, but it is far from clear that there is a trivial place where I
// can adjust for that, and anyway nobody wants to have to set a system-
// wide option just for the benefit of this application.
    Gdiplus::Graphics *g = (Gdiplus::Graphics *)gc->GetNativeContext();
    g->SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAlias);
#endif
    logprintf("Need to create fixed pitch font\n");
// The graphicsFixedPitch font will be for a line spacing of exactly 10
// pixels. This is of course TINY, but I will scale it as relevant.
    graphicsFixedPitch = gc->CreateFont(10.0, wxT("csl-cmtt10"));
    double dwidth, dheight, ddepth, dleading;
    gc->SetFont(graphicsFixedPitch);
    gc->GetTextExtent(wxT("M"), &dwidth, &dheight, &ddepth, &dleading);
    em = dwidth;
    logprintf("(D)em=%#.3g\n", em);
    logprintf("(D)height = %#.3g total height = %#.3g leading = %#.3g\n",
        dheight-ddepth-dleading, dheight, dleading);

    double screenWidth = (double)window.GetWidth();
    double lineWidth = 80.0*em;
    double scale = screenWidth/lineWidth;
    gc->Scale(scale, scale);
    logprintf("Scale now %.6g\n", scale);

// Sort of for fun I put a row of 80 characters at the top of the screen
// so I can show how fixed pitch stuff might end up being rendered.
    gc->SetFont(graphicsFixedPitch);
    for (int i=0; i<80; i++)
    {   wxString c1 = (wchar_t)MapChar(i);
        gc->DrawText(c1, (double)i*em, 10.0);
    }
    RenderDVI();
// I will mark all the fonts I might have created as invalid now
// that the context they were set up for is being left.
    for (int i=0; i<MAX_FONTS; i++) graphicsFontValid[i] = false;
    logprintf("About to delete gc\n");
    delete gc;
    gc = NULL; // just to be tidy!
    return;
}


// A dummy definition that is needed because of wxfwin.cpp

int windowed_worker(int argc, const char *argv[],
                    fwin_entrypoint *fwin_main)
{   return 0;
}


// end of wxdvi.cpp

