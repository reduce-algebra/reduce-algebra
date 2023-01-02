// wxfontdemo.cpp                                 Copyright A C Norman 2020

// A sample wxWidgets application to display fonts.
//


// The first version of this started from the "minimal" example that
// comes with wxWidgets, and that is under the wxWidgets/wxWindows
// license, ie LGPL plus some exceptions. Some parts of the basic
// structure here is forced by the very nature of wxWidgets to follow
// that pattern, but in general the code initially taken from
// "minimal.cpp" is being removed and must count as indeed being "minimal",
// and it is on that basis that I feel able to label this with a BSD
// license. But license constraints or no, here seems a good place to
// express thanks to all the people who created and continue to develop
// wxWidgets.

/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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


// Driving instructions:
//
//   ./wxfontdemo "fontname" [--italic] [--bold] [--regular]
//
// The fontname is either the name of a font installed on the system
// or is one of the private fonts provided here (and those are the cases
// I view as more interesting). Sometimes the names you need to give the
// private fonts differ as between Macintosh and other platforms.
// Eg "CMU Typewriter Text" or "CMU Typewriter Text Regular", ...
//
// When displaying a font you can type 0-9 or a-f to move to a display
// that starts at unicode code point (eg) U+3000 (that would obviously be
// by typeing a "3"). You can then type "x" to flip the U+10000 bit and
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

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if wxUSE_GRAPHICS_CONTEXT
// I will use wxGraphicsContext so I have better capabilities to
// scale text. On Windows this means I must have gdiplus development
// stuff installed when building wxWidgets. Specifically the header
// file gdiplus.h is required at that stage that wxWidgets is configured.
#else
#error I now need wxGraphicsContext
#endif

#include "wx/dc.h"
#include "wx/graphics.h"
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

// I may be old fashioned , but I will be happier using C rather than C++
// libraries here.

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <cctype>
#include <ctime>
#include <csignal>
#include <cstdint>
#include <cinttypes>

#if HAVE_UNISTD_H
#include <unistd.h>
#else
extern char *getcwd(char *s, std::size_t n);
#endif // HAVE_UNISTD_H

#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>

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

int get_current_directory(char *s, std::size_t n)
{   if (getcwd(s, n) == 0)
    {   switch(errno)
        {   case ERANGE: return -2; // negative return value flags an error.
            case EACCES: return -3;
            default:     return -4;
        }
    }
    else return std::strlen(s);
}

//
// The next procedure is responsible for establishing information about
// both the "short-form" name of the program launched and the directory
// it was found in. This latter directory may be a good place to keep
// associated resources. Well many conventions would NOT view it as a
// good place, but it is how I organise things!
//
// The way of finding the information concerned differs between Windows and
// Unix/Linux, as one might expect.
//
// return non-zero value if failure.
//

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

const char *fullProgramName = "./wxfontdemo.exe";
const char *programName     = "wxfontdemo.exe";
const char *programDir      = ".";

//
// getenv() is a mild pain: Windows seems
// to have a strong preference for upper case names.  To allow for
// all this I do not call getenv() directly but go via the following
// code that can patch things up.
//

const char *my_getenv(const char *s)
{
#ifdef WIN32
    char uppercasename[LONGEST_LEGAL_FILENAME];
    char *p = uppercasename;
    int c;
    while ((c = *s++) != 0) *p++ = std::toupper(c);
    *p = 0;
    return std::getenv(uppercasename);
#else
    return std::getenv(s);
#endif
}

#ifdef WIN32

int programNameDotCom = 0;

static char this_executable[LONGEST_LEGAL_FILENAME];

int find_program_directory(const char *argv0)
{   char *w;
    int len, ndir, npgm;
// In older code I believed that I could rely on Windows giving me
// the full path of my executable in argv[0]. With bits of mingw/cygwin
// anywhere near me that may not be so, so I grab the information directly
// from the Windows APIs.
    char execname[LONGEST_LEGAL_FILENAME];
    GetModuleFileNameA(nullptr, execname, LONGEST_LEGAL_FILENAME-2);
    std::strcpy(this_executable, execname);
    argv0 = this_executable;
    programNameDotCom = 0;
    if (argv0[0] == 0)      // should never happen - name is empty string!
    {   programDir = ".";
        programName = "wxfontdemo";  // nothing really known!
        fullProgramName = ".\\wxfontdemo.exe";
        return 0;
    }

    fullProgramName = argv0;
    len = std::strlen(argv0);
// If the current program is called c:\aaa\xxx.exe, then the directory
// is just c:\aaa and the simplified program name is just xxx
    if (len > 4 &&
        argv0[len-4] == '.' &&
        ((std::tolower(argv0[len-3]) == 'e' &&
          std::tolower(argv0[len-2]) == 'x' &&
          std::tolower(argv0[len-1]) == 'e') ||
         (std::tolower(argv0[len-3]) == 'c' &&
          std::tolower(argv0[len-2]) == 'o' &&
          std::tolower(argv0[len-1]) == 'm')))
    {   programNameDotCom = (std::tolower(argv0[len-3]) == 'c');
        len -= 4;
    }
    for (npgm=0; npgm<len; npgm++)
    {   int c = argv0[len-npgm-1];
        if (c == '\\') break;
    }
    ndir = len - npgm - 1;
    if (ndir < 0) programDir = ".";  // none really visible
    else
    {   if ((w = new (std::nothroe) char[ndir+1]) == nullptr) return 1;
        std::strncpy(w, argv0, ndir);
        w[ndir] = 0;
        programDir = w;
    }
    if ((w = new (std::nothrow) char[npgm+1]) == nullptr) return 1;
    std::strncpy(w, argv0 + len - npgm, npgm);
    w[npgm] = 0;
    programName = w;
    return 0;
}

#else // WIN32
// Now for Unix, Linux, BSD (and hence Macintosh) worlds.


// Different systems put or do not put underscores in front of these
// names. My adaptation here should give me a chance to work whichever
// way round it goes.

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif

#ifndef S_ISLNK
# ifdef S_IFLNK
#  ifdef S_IFMT
#   define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#  endif
# endif
#endif


//
// the length set here is at least the longest length that I
// am prepared to worry about. If anybody installs the program in a
// very deep directory such that its fully rooted name is over-long
// things may not behave well. But I am not going to fuss with dynamic
// allocation of or expansion of the arrays I use here.
//

int find_program_directory(const char *argv0)
{   char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
    const char *cw;
    int n, n1;
//
// If the main reduce executable is has a full path-name /xxx/yyy/zzz then
// I will use /xxx/yyy as its directory To find this I need to find the full
// path for the executable. I ATTEMPT to follow the behaviour of "sh",
// "bash" and "csh".  But NOTE WELL that if anybody launches this code in
// an unusual manner (eg using an "exec" style function) that could confuse
// me substantially. What comes in via argv[0] is typically just the final
// component of the program name - what I am doing here is scanning to
// see what path it might have corresponded to.
//
//
// If the name of the executable starts with a "/" it is already an
// absolute path name. I believe that if the user types (to the shell)
// something like $DIR/bin/$PGMNAME or ~user/subdir/pgmname then the
// environment variables and user-name get expanded out by the shell before
// the command is actually launched.
//
    if (argv0 == nullptr ||
        argv0[0] == 0) // Information not there - return
    {   programDir = (const char *)"."; // some sort of default.
        programName = (const char *)"wxfontdemo";
        fullProgramName = (const char *)"./wxfontdemo";
        return 0;
    }
//
// I will treat 3 cases here
// (a)   /abc/def/ghi      fully rooted: already an absolute name;
// (b)   abc/def/ghi       treat as ./abc/def/ghi;
// (c)   ghi               scan $PATH to see where it may have come from.
//
    else if (argv0[0] == '/') fullProgramName = argv0;
    else
    {   for (cw=argv0; *cw!=0 && *cw!='/'; cw++);   // seek a "/"
        if (*cw == '/')      // treat as if relative to current dir
        {   // If the thing is actually written as "./abc/..." then
            // strip of the initial "./" here just to be tidy.
            if (argv0[0] == '.' && argv0[1] == '/') argv0 += 2;
            n = get_current_directory(pgmname, sizeof(pgmname));
            if (n < 0) return 1;    // fail! 1=current directory failure
            if (n + std::strlen(argv0) + 2 >= sizeof(pgmname) ||
                pgmname[0] == 0)
                return 2; // Current dir unavailable or full name too long
            else
            {   pgmname[n] = '/';
                std::strcpy(&pgmname[n+1], argv0);
                fullProgramName = pgmname;
            }
        }
        else
        {   const char *path = my_getenv("PATH");
//
// I omit checks for names of shell built-in functions, since my code is
// actually being executed by here. So I get my search path and look
// for an executable file somewhere on it. I note that the shells back this
// up with hash tables, and so in cases where "rehash" might be needed this
// code may become confused.
//
            struct stat buf;
            uid_t myuid = geteuid(), hisuid;
            gid_t mygid = getegid(), hisgid;
            int protection;
            int ok = 0;
// I expect $PATH to be a sequence of directories with ":" characters to
// separate them. I suppose it COULD be that somebody used directory names
// that had embedded colons, and quote marks or escapes in $PATH to allow
// for that. In such case this code will just fail to cope.
//
            if (path != nullptr)
            {   while (*path != 0)
                {   while (*path == ':') path++; // skip over ":"
                    n = 0;
                    while (*path != 0 && *path != ':')
                    {   pgmname[n++] = *path++;
                        if (n > static_cast<int>(sizeof(pgmname)-3-std::strlen(argv0)))
                            return 3; // fail! 3=$PATH element overlong
                    }
// Here I have separated off the next segment of my $PATH and put it at
// the start of pgmname. Observe that to avoid buffer overflow I
// exit abruptly if the entry on $PATH is itself too big for my buffer.
//
                    pgmname[n++] = '/';
                    std::strcpy(&pgmname[n], argv0);
// see if the file whose name I have just built up exists at all.
                    if (stat(pgmname, &buf) == -1) continue;
                    hisuid = buf.st_uid;
                    hisgid = buf.st_gid;
                    protection = buf.st_mode; // info about the file found
//
// I now want to check if there is a file of the right name that is
// executable by the current (effective) user.
//
                    if (protection & S_IXOTH ||
                        (mygid == hisgid && protection & S_IXGRP) ||
                        (myuid == hisuid && protection & S_IXUSR))
                    {   ok = 1;   // Haha - I have found the one we ...
                        break;    // are presumably executing!
                    }
                }
            }
            if (!ok) return 4;    // executable not found via $PATH
// Life is not yet quite easy! $PATH may contain some items that do not
// start with "/", ie that are still local paths relative to the
// current directory. I want to be able to return an absolute fully
// rooted path name! So unless the item we have at present starts with "/"
// I will stick the current directory's location in front.
//
            if (pgmname[0] != '/')
            {   char temp[LONGEST_LEGAL_FILENAME];
                std::strcpy(temp, pgmname);
                n = get_current_directory(pgmname, sizeof(pgmname));
                if (n < 0) return 1;    // fail! 1=current directory failure
                if ((n + std::strlen(temp) + 1) >= sizeof(pgmname)) return 9;
                pgmname[n++] = '/';
                std::strcpy(&pgmname[n], temp);
            }
            fullProgramName = pgmname;
        }
    }
//
// Now if I have a program name I will try to see if it is a symbolic link
// and if so I will follow it.
//
    {   struct stat buf;
        char temp[LONGEST_LEGAL_FILENAME];
        if (lstat(fullProgramName, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(fullProgramName,
                           temp, sizeof(temp)-1)) > 0)
        {   temp[n1] = 0;
            std::strcpy(pgmname, temp);
            fullProgramName = pgmname;
        }
    }
// Now fullProgramName is set up, but may refer to an array that
// is stack allocated. I need to make it proper!
//
    w = new (std::nothrow) char[1+std::strlen(fullProgramName)];
    if (w == nullptr) return 5;           // 5 = new fails
    std::strcpy(w, fullProgramName);
    fullProgramName = w;
#ifdef __CYGWIN__
//
// Now if I built on raw cygwin I may have an unwanted ".com" or ".exe"
// suffix, so I will purge that! This code exists here because the raw
// cygwin build has a somewhat schitzo view as to whether it is a Windows
// or a Unix-like system.
//
    if (std::strlen(w) > 4)
    {   w += std::strlen(w) - 4;
        if (w[0] == '.' &&
            ((std::tolower(w[1]) == 'e' &&
              std::tolower(w[2]) == 'x' &&
              std::tolower(w[3]) == 'e') ||
             (std::tolower(w[1]) == 'c' &&
              std::tolower(w[2]) == 'o' &&
              std::tolower(w[3]) == 'm'))) w[0] = 0;
    }
#endif
// OK now I have the full name, which is of the form
//   abc/def/fgi/xyz
// and I need to split it at the final "/" (and by now I very fully expect
// there to be at least one "/".
//
    for (n=std::strlen(fullProgramName)-1; n>=0; n--)
        if (fullProgramName[n] == '/') break;
    if (n < 0) return 6;               // 6 = no "/" in full file path
    w = new (std::nothrow) char[n+1];
    if (w == nullptr) return 7;           // 7 = new fails
    std::strncpy(w, fullProgramName, n);
    w[n] = 0;
// Note that if the executable was "/foo" then programDir will end up as ""
// so that programDir + "/" + programName works out properly.
//
    programDir = w;
    n1 = std::strlen(fullProgramName) - n;
    w = new (std::nothrow) char[n1];
    if (w == nullptr) return 8;           // 8 = new fails
    std::strncpy(w, fullProgramName+n+1, n1-1);
    w[n1-1] = 0;
    programName = w;
    return 0;                          // whew!
}

#endif // WIN32

extern void add_custom_fonts();

int main(int argc, const char *argv[])
{   int i;
    int usegui = 1;
// Find where I am invoked from before doing anything else
    find_program_directory(argv[0]);
    for (i=1; i<argc; i++)
    {   if (std::strncmp(argv[i], "-w", 2) == 0) usegui = 0;
        else if (std::strcmp(argv[1], "--help") == 0)
        {   std::printf("wxfontdemo \"font name\"\n");
            std::exit(0);
        }
    }
#if !defined WIN32 && !defined MACINTOSH
// Under X11 I will demote to being a console mode application if DISPLAY
// is not set. This is not a perfect test but it will spot the simple
// cases. Eg I could look at stdin & stdout and check if it looks as if
// they are pipes of they have been redirected...
    {   const char *s = my_getenv("DISPLAY");
        if (s==nullptr || *s == 0) usegui = 0;
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
        std::snprintf(xname, sizeof(xname), "%s.app", programName);
        if (std::strstr(fullProgramName, xname) == nullptr)
        {
// Here the binary I launched was not located as
//      ...foo.app../.../foo
// so I will view it is NOT being from an application bundle. I will
// re-launch it so it is! This may be a bit of a hacky way to decide!
            struct stat buf;
            std::snprintf(xname, sizeof(xname), "%s.app", fullProgramName);
            if (stat(xname, &buf) == 0 &&
                (buf.st_mode & S_IFDIR) != 0)
            {
// Well foo.app exists and is a directory, so I will try to use it
                const char **nargs = new const char *[argc+3];
                int i;
                nargs[0] = "/usr/bin/open";
                nargs[1] = xname;
                nargs[2] = "--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = nullptr;
// /usr/bin/open foo.app --args [any original arguments]
                return execv(nargs[0], const_cast<char * const *>(nargs));
            }
        }
#endif

        add_custom_fonts();
        wxDISABLE_DEBUG_SUPPORT();
        return wxEntry(argc, (char **)argv);
    }
    std::printf("This program has been launched asking for use in a console\n");
    std::printf("type a line of text please\n");
    while ((i = std::getchar()) != '\n' && i != EOF) std::putchar(i);
    std::putchar('\n');
    std::printf("Exiting from demonstration of console mode use!\n");
    return 0;
}

IMPLEMENT_APP_NO_MAIN(fontApp)


#ifndef MACINTOSH

static const char *fontNames[] =
{
// This adds the fonts that I expect to be used in my wxWidgets code.
#ifdef WIN32
    "cmuntt.ttf",          // CMU Typewriter Text
    "odokai.ttf",          // a succesor to AR PL New Sung
    "cslSTIX-Regular.ttf",
    "cslSTIX-Bold.ttf",
    "cslSTIX-Italic.ttf",
    "cslSTIX-BoldItalic.ttf",
    "cslSTIXMath-Regular.ttf"
#else
    "cmuntt.otf",          // CMU Typewriter Text
    "odokai.ttf",          // a succesor to AR PL New Sung
    "cslSTIX-Regular.otf",
    "cslSTIX-Bold.otf",
    "cslSTIX-Italic.otf",
    "cslSTIX-BoldItalic.otf",
    "cslSTIXMath-Regular.otf"
#endif
};

#endif

#ifndef fontsdir
#define fontsdir reduce.wxfonts
#endif

#define toString(x) toString1(x)
#define toString1(x) #x

void add_custom_fonts()
{
#ifndef MACINTOSH
// Note that on a Mac I put the required fonts in the Application Bundle,
// and so I do not need to take run-time action to make them available.
    for (int i=0;
         i<static_cast<int>(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   char nn[LONGEST_LEGAL_FILENAME];
        std::snprintf(nn, sizeof(nn), "%s/%s/%s",
                     programDir, toString(fontsdir), fontNames[i]);
        std::printf("Adding %s: ", nn); std::fflush(stdout);
        wxString widename(nn);
        if (wxFont::AddPrivateFont(widename))
            std::printf(" OK\n");
        else std::printf("Failed\n");
    }
    std::printf("About to activate\n"); std::fflush(stdout);
    if (wxFont::ActivatePrivateFonts())
        std::printf("Activated OK\n");
    else std::printf("Activation failed\n");
    std::fflush(stdout);
#endif // MACINTOSH
}


void display_font_information()
{   wxArrayString flist(wxFontEnumerator::GetFacenames(
                            wxFONTENCODING_SYSTEM));
    int nfonts;
    std::printf("There are %d fonts\n",
                nfonts=static_cast<int>(flist.GetCount()));
    std::fflush(stdout);
    for (int i=0; i<nfonts; i++)
        std::printf("%d) <%s>\n", i,
                    reinterpret_cast<const char *>(flist[i].mb_str()));
    std::fflush(stdout);
    std::printf("End of debug output\n");
    std::fflush(stdout);
}

bool fontApp::OnInit()
{   display_font_information();
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;
    page = 0;
    regular = bold = italic = 0;
    const char *font =
        "CMU Typewriter Text";  // A default font name to ask for.
    int size = 48;           // a default size.
    for (int i=1; i<argc; i++)
    {   std::printf("Arg%d: %s\n", i, myargv[i]);
        if (std::strcmp(myargv[i], "--regular") == 0) regular = 1;
        if (std::strcmp(myargv[i], "--bold") == 0) bold = 1;
        if (std::strcmp(myargv[i], "--italic") == 0) italic = 1;
        else if (myargv[i][0] == '-')
        {   if (std::sscanf(myargv[i]+1, "%d", &page) != 1) page = 0;
        }
        else font = myargv[i];
    }
// I will find the special fonts that most interest me in a location related
// to the directory that this application was launched from. So the first
// think to do is to identify that location. I then print the information I
// recover so I can debug things. I have already set up programName etc
    std::printf("\n%s\n%s\n%s\n", fullProgramName, programName,
                programDir);

    std::printf("Try for font \"%s\" at size=%d\n", font, size);
    std::fflush(stdout);

    fontFrame *frame = new fontFrame(font, size);
    frame->Show(true);
    return true;
}

#define CELLWIDTH  11
#define CELLHEIGHT 20

fontFrame::fontFrame(const char *fname, int fsize)
    : wxFrame(nullptr, wxID_ANY, "wxfontdemo")
{   SetIcon(wxICON(fwin));
    panel = new fontPanel(this, fname, fsize);
    wxSize clientsize(3*33*CELLWIDTH, 3*10*CELLHEIGHT);
    wxSize winsize(ClientToWindowSize(clientsize));
    SetSize(winsize);
    SetMinSize(winsize);
    SetMaxSize(winsize);
    Centre();
}


fontPanel::fontPanel(fontFrame *parent, const char *fname, int fsize)
    : wxPanel(parent)
{   frame = parent;
    fontname = fname;
    fontsize = fsize;
    frame->SetTitle(fontname);
}


void fontFrame::OnClose(wxCloseEvent &WXUNUSED(event))
{   Destroy();
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
    std::exit(0);    // I want the whole application to terminate here!
#endif
}

void fontFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{   Destroy();
#ifdef WIN32
    TerminateProcess(GetCurrentProcess(), 1);
#else
    std::exit(0);    // I want the whole application to terminate here!
#endif
}

void fontFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{   wxMessageBox(
        wxString::Format(
            "wxfontdemo (A C Norman 2014)\n"
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
{   wxChar c = event.GetUnicodeKey();
    int n = -1;
    std::printf("Char event %#x (%c)\n", c, c); std::fflush(stdout);
    event.Skip();
    if ('0' <= c && c <= '9') n = c - '0';
    else if ('a' <= c && c <= 'f') n = c - 'a' + 10;
    else if ('A' <= c && c <= 'F') n = c - 'A' + 10;
    if (n >= 0) page = n*0x1000/0x80;
    else switch (c)
        {   case 'q':
            case 'Q':
#ifdef WIN32
                TerminateProcess(GetCurrentProcess(), 1);
#else
                std::exit(0);
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
{   wxWindowDC dc(this);
    wxPoint where(event.GetLogicalPosition(dc));
    if (where.y > 200) page++;
    else page--;
    std::printf("Mouse event. Page now %d\n", page); std::fflush(stdout);
    event.Skip();
    Refresh();
}

// The following function will catalogue the fonts I expect to allow
int find_fontnum(const char *s)
{   if (std::strcmp(s, "CMU Typewriter Text") == 0) return F_cmuntt;
    if (std::strcmp(s, "odokai") == 0) return F_odokai;
// Note that Bold and Italic are picked up by options --bold and --italic
// not through the font name.
    if (std::strcmp(s, "STIX") == 0) return F_Regular;
    if (std::strcmp(s, "STIXMath") == 0) return F_Math;
    return -1;
}

static int once = 0;

void fontPanel::OnPaint(wxPaintEvent &event)
{   std::printf("OnPaint invoked\n");
    wxPaintDC dc(this);
    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if (gc)
    {   gc->Scale(3.0, 3.0);
        wxColour c1(230, 200, 255);
        wxColour c2(100, 220, 120);
        wxBrush b1(c1); wxBrush b2(c2);
        wxPen p1(c1);   wxPen p2(c2);
// Draw a checkerboard background
        for (int y=0; y<256+2*32; y+=32)
        {   for (int x=0; x<33; x++)
            {   int k = ((y>>5) + x) & 1;
                gc->SetBrush(k ? b2 : b1);
                gc->SetPen(k ? p2 : p1);
                gc->DrawRectangle(CELLWIDTH*x, CELLHEIGHT*(y/32), CELLWIDTH,
                                  CELLHEIGHT);
            }
        }
        if (once == 0)
        {   std::printf("fontname = %s\n", fontname);
            if (wxFontEnumerator::IsValidFacename(fontname))
                std::printf("Face name is valid\n");
            else std::printf("Invalid face name - font not found\n");
        }
        wxFontInfo ffi(10);
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
            std::fflush(stdout);
        }
        wxGraphicsFont gff = gc->CreateFont(ff, *wxRED);
        int fontnum = find_fontnum(fontname);
        if (fontnum >= 0) std::printf("Map of available codepoints found\n");
        else std::printf("No map of valid codepoints\n");
// Draw row and column labels
        wxFont labels(wxFontInfo(3));
        wxGraphicsFont glabels = gc->CreateFont(labels, *wxBLACK);
        gc->SetFont(glabels);
        for (int i=0; i<32; i++)
        {   char word[12];
            std::snprintf(word, sizeof(word), "%02x", i);
            gc->DrawText(word, ((static_cast<double>(CELLWIDTH))*
                                (i+1)) + CELLWIDTH/2.2,
                         static_cast<double>(CELLHEIGHT)/10.0);
        }
        for (int i=0; i<8; i++)
        {   char word[12];
            std::snprintf(word, sizeof(word), "%5x", 32*i + 0x80*page);
            gc->DrawText(word, CELLWIDTH/10.0,
                         static_cast<double>(CELLHEIGHT)*(i+1) + CELLHEIGHT/2.5);
        }

        gc->SetFont(gff);

// Check if the font appears to contain any characters at all. In some
// cases where an unrecognised name is passed it might not!
//
// When I tried the STIX fonts I seem to get crashes within GetTextExtent
// for reasions that I do not at present understand... so at least for now
// I will remove this attempt to cont characters!
        if (0 && once++ == 0) // Disable just for now
        {   int howmany = 0;
            for (int i=0; howmany<30 && i<0xffff; i++)
            {   wxString s((wchar_t)i);
                double ww, hh, dd, el;
                gc->GetTextExtent(s, &ww, &hh, &dd, &el);
                if (ww != 0.0 && hh != 0.0)
                {   std::printf("%#x %.1f*%.1f; ", i, ww, hh);
                    howmany++;
                }
            }
            if (howmany == 0) std::printf("No glyphs found");
            std::printf("\n");
            std::fflush(stdout);
        }
// I will need font size information in order to position characters
// neatly.
        wxDouble w1=0.0, h1=0.0, d1=0.0, xl1=0.0;
        gc->GetTextExtent("X", &w1, &h1, &d1, &xl1);
// To make my display match the one I had from my previous FOX-based
// version I will adjust to make it as if DrawText uses the base-line of
// the character for its reference point. I draw a little blue circle to
// show where the reference point is...
        for (int i=0; i<256; i+=32)
        {   for (int j=0; j<32; j++)
            {   wxGraphicsMatrix save = gc->GetTransform();
                gc->Scale(0.25, 0.25);
                gc->SetPen(*wxBLUE_PEN);
                gc->SetBrush(*wxTRANSPARENT_BRUSH);
                gc->DrawEllipse(4.0*((static_cast<double>(CELLWIDTH))*(j+1)-2.0),
                                4.0*((static_cast<double>(CELLHEIGHT))*(i/32+1)+
                                     (static_cast<double>(CELLHEIGHT))-2.0),
                                4.0*4.0, 4.0*4.0);
                gc->SetTransform(save);
                int k = i + j;
                k += 0x80*page;
                if (k < 0 ||
                    k >= 0x110000 ||
                    (fontnum >= 0 && lookupchar(fontnum, k) == 0))
                {   gc->DrawRectangle(
                        static_cast<double>(CELLWIDTH)*(j+1)+CELLWIDTH/3.0,
                        static_cast<double>(CELLHEIGHT)*(i/32+1)+CELLHEIGHT/3.0,
                        CELLWIDTH/3.0, CELLHEIGHT/3.0);
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
                double offset = d1-h1;
                gc->DrawText(c,
                             (static_cast<double>(CELLWIDTH))*(j+1),
                             (static_cast<double>(CELLHEIGHT))*(i/32+1)+
                             (static_cast<double>(CELLHEIGHT))+offset);
            }
        }
        delete gc;
    }
    else std::printf("gc=nullptr\n");
    return;
}

// end of wxfontdemo.cpp

