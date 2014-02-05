// wxfontdemo.cpp

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
 * Copyright (C) 2014, Codemist Ltd.                     A C Norman       *
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
// I will need windows-specific functions so I can set up private fonts
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
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
#ifndef _MSC_VER
extern char *getcwd(char *s, size_t n);
#endif
#endif /* HAVE_UNISTD_H */

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
#endif /* HAVE_DIRENT_H */

#if !defined __WXMSW__ && !defined __WXPM__
#include "fwin.xpm" // Icon to use in non-Windows cases
#endif

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

int raw, page, bold, italic;

int get_current_directory(char *s, int n)
{
    if (getcwd(s, n) == 0)
    {   switch(errno)
        {
    case ERANGE: return -2; /* negative return value flags an error. */
    case EACCES: return -3;
    default:     return -4;
        }
    }
    else return strlen(s);
}

/*
 * The next procedure is responsible for establishing information about
 * both the "short-form" name of the program launched and the directory
 * it was found in. This latter directory may be a good place to keep
 * associated resources. Well many conventions would NOT view it as a
 * good place, but it is how I organise things!
 *
 * The way of finding the information concerned differs between Windows and
 * Unix/Linux, as one might expect.
 *
 * return non-zero value if failure.
 */

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

const char *fullProgramName = "./wxfontdemo.exe";
const char *programName     = "wxfontdemo.exe";
const char *programDir      = ".";

/*
 * getenv() is a mild pain: Windows seems
 * to have a strong preference for upper case names.  To allow for
 * all this I do not call getenv() directly but go via the following
 * code that can patch things up.
 */

const char *my_getenv(const char *s)
{
#ifdef WIN32
    char uppercasename[LONGEST_LEGAL_FILENAME];
    char *p = uppercasename;
    int c;
    while ((c = *s++) != 0) *p++ = toupper(c);
    *p = 0;
    return getenv(uppercasename);
#else
    return getenv(s);
#endif
}

#ifdef WIN32

int program_name_dot_com = 0;

static char this_executable[LONGEST_LEGAL_FILENAME];

int find_program_directory(const char *argv0)
{
    char *w;
    int len, ndir, npgm;
/* In older code I believed that I could rely on Windows giving me
 * the full path of my executable in argv[0]. With bits of mingw/cygwin
 * anywhere near me that may not be so, so I grab the information directly
 * from the Windows APIs.
 */
    char execname[LONGEST_LEGAL_FILENAME];
    GetModuleFileNameA(NULL, execname, LONGEST_LEGAL_FILENAME-2);
    strcpy(this_executable, execname);
    argv0 = this_executable;
    program_name_dot_com = 0;
    if (argv0[0] == 0)      /* should never happen - name is empty string! */
    {   programDir = ".";
        programName = "wxfontdemo";  /* nothing really known! */
        fullProgramName = ".\\wxfontdemo.exe";
        return 0;
    }

    fullProgramName = argv0;
    len = strlen(argv0);
/*
 * If the current program is called c:\aaa\xxx.exe, then the directory
 * is just c:\aaa and the simplified program name is just xxx
 */
    if (len > 4 &&
        argv0[len-4] == '.' &&
        ((tolower(argv0[len-3]) == 'e' &&
          tolower(argv0[len-2]) == 'x' &&
          tolower(argv0[len-1]) == 'e') ||
         (tolower(argv0[len-3]) == 'c' &&
          tolower(argv0[len-2]) == 'o' &&
          tolower(argv0[len-1]) == 'm')))
    {   program_name_dot_com = (tolower(argv0[len-3]) == 'c');
        len -= 4;
    }
    for (npgm=0; npgm<len; npgm++)
    {   int c = argv0[len-npgm-1];
        if (c == '\\') break;
    }
    ndir = len - npgm - 1;
    if (ndir < 0) programDir = ".";  /* none really visible */
    else
    {   if ((w = (char *)malloc(ndir+1)) == NULL) return 1;
        strncpy(w, argv0, ndir);
        w[ndir] = 0;
        programDir = w;
    }
    if ((w = (char *)malloc(npgm+1)) == NULL) return 1;
    strncpy(w, argv0 + len - npgm, npgm);
    w[npgm] = 0;
    programName = w;
    return 0;
}

#else /* WIN32 */
// Now for Unix, Linux, BSD (and hence Macintosh) worlds.


/* Different systems put or do not put underscores in front of these
 * names. My adaptation here should give me a chance to work whichever
 * way round it goes.
 */

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


/*
 * the length set here is at least the longest length that I
 * am prepared to worry about. If anybody installs the program in a
 * very deep directory such that its fully rooted name is over-long
 * things may not behave well. But I am not going to fuss with dynamic
 * allocation of or expansion of the arrays I use here.
 */

int find_program_directory(const char *argv0)
{
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
    const char *cw;
    int n, n1;
/*
 * If the main reduce executable is has a full path-name /xxx/yyy/zzz then
 * I will use /xxx/yyy as its directory To find this I need to find the full
 * path for the executable. I ATTEMPT to follow the behaviour of "sh",
 * "bash" and "csh".  But NOTE WELL that if anybody launches this code in
 * an unusual manner (eg using an "exec" style function) that could confuse
 * me substantially. What comes in via argv[0] is typically just the final
 * component of the program name - what I am doing here is scanning to
 * see what path it might have corresponded to.
 *
 *
 * If the name of the executable starts with a "/" it is already an
 * absolute path name. I believe that if the user types (to the shell)
 * something like $DIR/bin/$PGMNAME or ~user/subdir/pgmname then the
 * environment variables and user-name get expanded out by the shell before
 * the command is actually launched.
 */
    if (argv0 == NULL || argv0[0] == 0) /* Information not there - return */
    {   programDir = (const char *)"."; /* some sort of default. */
        programName = (const char *)"wxfontdemo";
        fullProgramName = (const char *)"./wxfontdemo";
        return 0;
    }
/*
 * I will treat 3 cases here
 * (a)   /abc/def/ghi      fully rooted: already an absolute name;
 * (b)   abc/def/ghi       treat as ./abc/def/ghi;
 * (c)   ghi               scan $PATH to see where it may have come from.
 */
    else if (argv0[0] == '/') fullProgramName = argv0;
    else
    {   for (cw=argv0; *cw!=0 && *cw!='/'; cw++);   /* seek a "/" */
        if (*cw == '/')      /* treat as if relative to current dir */
        {   /* If the thing is actually written as "./abc/..." then */
            /* strip of the initial "./" here just to be tidy. */
            if (argv0[0] == '.' && argv0[1] == '/') argv0 += 2;
            n = get_current_directory(pgmname, sizeof(pgmname));
            if (n < 0) return 1;    /* fail! 1=current directory failure */
            if (n + strlen(argv0) + 2 >= sizeof(pgmname) ||
                pgmname[0] == 0)
                return 2; /* Current dir unavailable or full name too long */
            else
            {   pgmname[n] = '/';
                strcpy(&pgmname[n+1], argv0);
                fullProgramName = pgmname;
            }
        }
        else
        {   const char *path = my_getenv("PATH");
/*
 * I omit checks for names of shell built-in functions, since my code is
 * actually being executed by here. So I get my search path and look
 * for an executable file somewhere on it. I note that the shells back this
 * up with hash tables, and so in cases where "rehash" might be needed this
 * code may become confused.
 */
            struct stat buf;
            uid_t myuid = geteuid(), hisuid;
            gid_t mygid = getegid(), hisgid;
            int protection;
            int ok = 0;
/* I expect $PATH to be a sequence of directories with ":" characters to
 * separate them. I suppose it COULD be that somebody used directory names
 * that had embedded colons, and quote marks or escapes in $PATH to allow
 * for that. In such case this code will just fail to cope.
 */
            if (path != NULL)
            {   while (*path != 0)
                {   while (*path == ':') path++; /* skip over ":" */
                    n = 0;
                    while (*path != 0 && *path != ':')
                    {   pgmname[n++] = *path++;
                        if (n > (int)(sizeof(pgmname)-3-strlen(argv0)))
                            return 3; /* fail! 3=$PATH element overlong */
                    }
/* Here I have separated off the next segment of my $PATH and put it at
 * the start of pgmname. Observe that to avoid buffer overflow I
 * exit abruptly if the entry on $PATH is itself too big for my buffer.
 */
                    pgmname[n++] = '/';
                    strcpy(&pgmname[n], argv0);
/* see if the file whose name I have just built up exists at all. */
                    if (stat(pgmname, &buf) == -1) continue;
                    hisuid = buf.st_uid;
                    hisgid = buf.st_gid;
                    protection = buf.st_mode; /* info about the file found */
/*
 * I now want to check if there is a file of the right name that is
 * executable by the current (effective) user.
 */
                    if (protection & S_IXOTH ||
                        (mygid == hisgid && protection & S_IXGRP) ||
                        (myuid == hisuid && protection & S_IXUSR))
                    {   ok = 1;   /* Haha - I have found the one we ... */
                        break;    /* are presumably executing! */
                    }
                }
            }
            if (!ok) return 4;    /* executable not found via $PATH */
/* Life is not yet quite easy! $PATH may contain some items that do not
 * start with "/", ie that are still local paths relative to the
 * current directory. I want to be able to return an absolute fully
 * rooted path name! So unless the item we have at present starts with "/"
 * I will stick the current directory's location in front.
 */
            if (pgmname[0] != '/')
            {   char temp[LONGEST_LEGAL_FILENAME];
                strcpy(temp, pgmname);
                n = get_current_directory(pgmname, sizeof(pgmname));
                if (n < 0) return 1;    /* fail! 1=current directory failure */
                if ((n + strlen(temp) + 1) >= sizeof(pgmname)) return 9;
                pgmname[n++] = '/';
                strcpy(&pgmname[n], temp);
            }
            fullProgramName = pgmname;
        }
    }
/*
 * Now if I have a program name I will try to see if it is a symbolic link
 * and if so I will follow it.
 */
    {   struct stat buf;
        char temp[LONGEST_LEGAL_FILENAME];
        if (lstat(fullProgramName, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(fullProgramName,
                           temp, sizeof(temp)-1)) > 0)
        {   temp[n1] = 0;
            strcpy(pgmname, temp);
            fullProgramName = pgmname;
        }
    }
/* Now fullProgramName is set up, but may refer to an array that
 * is stack allocated. I need to make it proper!
 */
    w = (char *)malloc(1+strlen(fullProgramName));
    if (w == NULL) return 5;           /* 5 = malloc fails */
    strcpy(w, fullProgramName);
    fullProgramName = w;
#ifdef RAW_CYGWIN
/*
 * Now if I built on raw cygwin I may have an unwanted ".com" or ".exe"
 * suffix, so I will purge that! This code exists here because the raw
 * cygwin build has a somewhat schitzo view as to whether it is a Windows
 * or a Unix-like system.
 */
    if (strlen(w) > 4)
    {   w += strlen(w) - 4;
        if (w[0] == '.' &&
            ((tolower(w[1]) == 'e' &&
              tolower(w[2]) == 'x' &&
              tolower(w[3]) == 'e') ||
             (tolower(w[1]) == 'c' &&
              tolower(w[2]) == 'o' &&
              tolower(w[3]) == 'm'))) w[0] = 0;
    }
#endif
/* OK now I have the full name, which is of the form
 *   abc/def/fgi/xyz
 * and I need to split it at the final "/" (and by now I very fully expect
 * there to be at least one "/".
 */
    for (n=strlen(fullProgramName)-1; n>=0; n--)
        if (fullProgramName[n] == '/') break;
    if (n < 0) return 6;               /* 6 = no "/" in full file path */
    w = (char *)malloc(1+n);
    if (w == NULL) return 7;           /* 7 = malloc fails */
    strncpy(w, fullProgramName, n);
    w[n] = 0;
/* Note that if the executable was "/foo" then programDir will end up as ""
 * so that programDir + "/" + programName works out properly.
 */
    programDir = w;
    n1 = strlen(fullProgramName) - n;
    w = (char *)malloc(n1);
    if (w == NULL) return 8;           /* 8 = malloc fails */
    strncpy(w, fullProgramName+n+1, n1-1);
    w[n1-1] = 0;
    programName = w;
    return 0;                          /* whew! */
}

#endif /* WIN32 */

extern void add_custom_fonts();

int main(int argc, char *argv[])
{
    int i;
    int usegui = 1;
// Find where I am invoked from before doing anything else
    find_program_directory(argv[0]);
    for (i=1; i<argc; i++)
    {   if (strncmp(argv[i], "-w", 2) == 0) usegui = 0;
        else if (strcmp(argv[1], "--help") == 0)
        {
printf("This program contains bitmaps that show font coverage of some of\n");
printf("the Latin Modern Fonts. The license terms of those fonts mean that\n");
printf("any derived information falls under the LaTeX Project Public\n");
printf("License which requires prominent notice of how to find the orininal\n");
printf("fonts and full information about transformations made. This information\n");
printf("should be in the wxfonts or reduce.wxfonts directory associated with\n");
printf("this program and if necessary copies of everything relevant are in the\n");
printf("trunk/csl/cslbase/wxfonts and trunk/csl/cslbase/glyphinfo.c locations\n");
printf("in the subversion repositary at reduce-algebra.sf.net.\n");
            exit(0);   
        }
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
                char **nargs = (char **)malloc(sizeof(char *)*(argc+3));
                int i;
                nargs[0] = "/usr/bin/open";
                nargs[1] = xname;
                nargs[2] = "--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
// /usr/bin/open foo.app --args [any original arguments]
                return execv(nargs[0], nargs);
            }
        }
#endif

        add_custom_fonts();
        wxDISABLE_DEBUG_SUPPORT();
        return wxEntry(argc, argv);
    }
    printf("This program has been launched asking for use in a console\n");
    printf("type a line of text please\n");
    while ((i = getchar()) != '\n' && i != EOF) putchar(i);
    putchar('\n');
    printf("Exiting from demonstration of console mode use!\n");
    return 0;
}

IMPLEMENT_APP_NO_MAIN(fontApp)

// Pretty much everything so far has been uttery stylised and the contents
// are forced by the structure that wxWidgets requires!


#ifndef MACINTOSH

static const char *fontNames[] =
{
// Right now I will add in ALL the fonts I have collected!
// This can make sense in a font demo program but in a more serious
// application I should be a little more selective.
    "cmuntt.ttf",           "DejaVuSansMono.otf",  
    "fireflysung.ttf",      "sazanami-gothic.ttf",  "sazanami-mincho.ttf", 
    "csl-cmb10.ttf",        "csl-cmbsy10.ttf",      "csl-cmbsy6.ttf",       "csl-cmbsy7.ttf",   
    "csl-cmbsy8.ttf",       "csl-cmbsy9.ttf",       "csl-cmbx10.ttf",       "csl-cmbx12.ttf",   
    "csl-cmbx5.ttf",        "csl-cmbx6.ttf",        "csl-cmbx7.ttf",        "csl-cmbx8.ttf",    
    "csl-cmbx9.ttf",        "csl-cmbxsl10.ttf",     "csl-cmbxti10.ttf",     "csl-cmcsc10.ttf",  
    "csl-cmcsc8.ttf",       "csl-cmcsc9.ttf",       "csl-cmdunh10.ttf",     "csl-cmex10.ttf",   
    "csl-cmex7.ttf",        "csl-cmex8.ttf",        "csl-cmex9.ttf",        "csl-cmff10.ttf",   
    "csl-cmfi10.ttf",       "csl-cmfib8.ttf",       "csl-cminch.ttf",       "csl-cmitt10.ttf",  
    "csl-cmmi10.ttf",       "csl-cmmi12.ttf",       "csl-cmmi5.ttf",        "csl-cmmi6.ttf",    
    "csl-cmmi7.ttf",        "csl-cmmi8.ttf",        "csl-cmmi9.ttf",        "csl-cmmib10.ttf",  
    "csl-cmmib6.ttf",       "csl-cmmib7.ttf",       "csl-cmmib8.ttf",       "csl-cmmib9.ttf",   
    "csl-cmr10.ttf",        "csl-cmr12.ttf",        "csl-cmr17.ttf",        "csl-cmr5.ttf",     
    "csl-cmr6.ttf",         "csl-cmr7.ttf",         "csl-cmr8.ttf",         "csl-cmr9.ttf",     
    "csl-cmsl10.ttf",       "csl-cmsl12.ttf",       "csl-cmsl8.ttf",        "csl-cmsl9.ttf",    
    "csl-cmsltt10.ttf",     "csl-cmss10.ttf",       "csl-cmss12.ttf",       "csl-cmss17.ttf",   
    "csl-cmss8.ttf",        "csl-cmss9.ttf",        "csl-cmssbx10.ttf",     "csl-cmssdc10.ttf", 
    "csl-cmssi10.ttf",      "csl-cmssi12.ttf",      "csl-cmssi17.ttf",      "csl-cmssi8.ttf",   
    "csl-cmssi9.ttf",       "csl-cmssq8.ttf",       "csl-cmssqi8.ttf",      "csl-cmsy10.ttf",   
    "csl-cmsy5.ttf",        "csl-cmsy6.ttf",        "csl-cmsy7.ttf",        "csl-cmsy8.ttf",    
    "csl-cmsy9.ttf",        "csl-cmtcsc10.ttf",     "csl-cmtex10.ttf",      "csl-cmtex8.ttf",   
    "csl-cmtex9.ttf",       "csl-cmti10.ttf",       "csl-cmti12.ttf",       "csl-cmti7.ttf",    
    "csl-cmti8.ttf",        "csl-cmti9.ttf",        "csl-cmtt10.ttf",       "csl-cmtt12.ttf",   
    "csl-cmtt8.ttf",        "csl-cmtt9.ttf",        "csl-cmu10.ttf",        "csl-cmvtt10.ttf",  
    "csl-euex10.ttf",       "csl-euex7.ttf",        "csl-euex8.ttf",        "csl-euex9.ttf",    
    "csl-eufb10.ttf",       "csl-eufb5.ttf",        "csl-eufb6.ttf",        "csl-eufb7.ttf",    
    "csl-eufb8.ttf",        "csl-eufb9.ttf",        "csl-eufm10.ttf",       "csl-eufm5.ttf",    
    "csl-eufm6.ttf",        "csl-eufm7.ttf",        "csl-eufm8.ttf",        "csl-eufm9.ttf",    
    "csl-eurb10.ttf",       "csl-eurb5.ttf",        "csl-eurb6.ttf",        "csl-eurb7.ttf",    
    "csl-eurb8.ttf",        "csl-eurb9.ttf",        "csl-eurm10.ttf",       "csl-eurm5.ttf",    
    "csl-eurm6.ttf",        "csl-eurm7.ttf",        "csl-eurm8.ttf",        "csl-eurm9.ttf",    
    "csl-eusb10.ttf",       "csl-eusb5.ttf",        "csl-eusb6.ttf",        "csl-eusb7.ttf",    
    "csl-eusb8.ttf",        "csl-eusb9.ttf",        "csl-eusm10.ttf",       "csl-eusm5.ttf",    
    "csl-eusm6.ttf",        "csl-eusm7.ttf",        "csl-eusm8.ttf",        "csl-eusm9.ttf",    
    "csl-msam10.ttf",       "csl-msam5.ttf",        "csl-msam6.ttf",        "csl-msam7.ttf",    
    "csl-msam8.ttf",        "csl-msam9.ttf",        "csl-msbm10.ttf",       "csl-msbm5.ttf",    
    "csl-msbm6.ttf",        "csl-msbm7.ttf",        "csl-msbm8.ttf",        "csl-msbm9.ttf",
#ifdef WIN32
    "latinmodern-math.ttf",       "lmmono10-italic.ttf",         "lmmono10-regular.ttf",
    "lmmono12-regular.ttf",       "lmmono8-regular.ttf",         "lmmono9-regular.ttf",
    "lmmonocaps10-oblique.ttf",   "lmmonocaps10-regular.ttf",    "lmmonolt10-bold.ttf",
    "lmmonolt10-boldoblique.ttf", "lmmonolt10-oblique.ttf",      "lmmonolt10-regular.ttf",
    "lmmonoltcond10-oblique.ttf", "lmmonoltcond10-regular.ttf",  "lmmonoprop10-oblique.ttf",
    "lmmonoprop10-regular.ttf",   "lmmonoproplt10-bold.ttf",     "lmmonoproplt10-boldoblique.ttf",
    "lmmonoproplt10-oblique.ttf", "lmmonoproplt10-regular.ttf",  "lmmonoslant10-regular.ttf",
    "lmroman10-bold.ttf",         "lmroman10-bolditalic.ttf",    "lmroman10-italic.ttf",
    "lmroman10-regular.ttf",      "lmroman12-bold.ttf",          "lmroman12-italic.ttf",
    "lmroman12-regular.ttf",      "lmroman17-regular.ttf",       "lmroman5-bold.ttf",
    "lmroman5-regular.ttf",       "lmroman6-bold.ttf",           "lmroman6-regular.ttf",
    "lmroman7-bold.ttf",          "lmroman7-italic.ttf",         "lmroman7-regular.ttf",
    "lmroman8-bold.ttf",          "lmroman8-italic.ttf",         "lmroman8-regular.ttf",
    "lmroman9-bold.ttf",          "lmroman9-italic.ttf",         "lmroman9-regular.ttf",
    "lmromancaps10-oblique.ttf",  "lmromancaps10-regular.ttf",   "lmromandemi10-oblique.ttf",
    "lmromandemi10-regular.ttf",  "lmromandunh10-oblique.ttf",   "lmromandunh10-regular.ttf",
    "lmromanslant10-bold.ttf",    "lmromanslant10-regular.ttf",  "lmromanslant12-regular.ttf",
    "lmromanslant17-regular.ttf", "lmromanslant8-regular.ttf",   "lmromanslant9-regular.ttf",
    "lmromanunsl10-regular.ttf",  "lmsans10-bold.ttf",           "lmsans10-boldoblique.ttf",
    "lmsans10-oblique.ttf",       "lmsans10-regular.ttf",        "lmsans12-oblique.ttf",
    "lmsans12-regular.ttf",       "lmsans17-oblique.ttf",        "lmsans17-regular.ttf",
    "lmsans8-oblique.ttf",        "lmsans8-regular.ttf",         "lmsans9-oblique.ttf",
    "lmsans9-regular.ttf",        "lmsansdemicond10-oblique.ttf","lmsansdemicond10-regular.ttf",
    "lmsansquot8-bold.ttf",       "lmsansquot8-boldoblique.ttf", "lmsansquot8-oblique.ttf",
    "lmsansquot8-regular.ttf"
#else
    "latinmodern-math.oft",       "lmmono10-italic.oft",         "lmmono10-regular.oft",
    "lmmono12-regular.oft",       "lmmono8-regular.oft",         "lmmono9-regular.oft",
    "lmmonocaps10-oblique.oft",   "lmmonocaps10-regular.oft",    "lmmonolt10-bold.oft",
    "lmmonolt10-boldoblique.oft", "lmmonolt10-oblique.oft",      "lmmonolt10-regular.oft",
    "lmmonoltcond10-oblique.oft", "lmmonoltcond10-regular.oft",  "lmmonoprop10-oblique.oft",
    "lmmonoprop10-regular.oft",   "lmmonoproplt10-bold.oft",     "lmmonoproplt10-boldoblique.oft",
    "lmmonoproplt10-oblique.oft", "lmmonoproplt10-regular.oft",  "lmmonoslant10-regular.oft",
    "lmroman10-bold.oft",         "lmroman10-bolditalic.oft",    "lmroman10-italic.oft",
    "lmroman10-regular.oft",      "lmroman12-bold.oft",          "lmroman12-italic.oft",
    "lmroman12-regular.oft",      "lmroman17-regular.oft",       "lmroman5-bold.oft",
    "lmroman5-regular.oft",       "lmroman6-bold.oft",           "lmroman6-regular.oft",
    "lmroman7-bold.oft",          "lmroman7-italic.oft",         "lmroman7-regular.oft",
    "lmroman8-bold.oft",          "lmroman8-italic.oft",         "lmroman8-regular.oft",
    "lmroman9-bold.oft",          "lmroman9-italic.oft",         "lmroman9-regular.oft",
    "lmromancaps10-oblique.oft",  "lmromancaps10-regular.oft",   "lmromandemi10-oblique.oft",
    "lmromandemi10-regular.oft",  "lmromandunh10-oblique.oft",   "lmromandunh10-regular.oft",
    "lmromanslant10-bold.oft",    "lmromanslant10-regular.oft",  "lmromanslant12-regular.oft",
    "lmromanslant17-regular.oft", "lmromanslant8-regular.oft",   "lmromanslant9-regular.oft",
    "lmromanunsl10-regular.oft",  "lmsans10-bold.oft",           "lmsans10-boldoblique.oft",
    "lmsans10-oblique.oft",       "lmsans10-regular.oft",        "lmsans12-oblique.oft",
    "lmsans12-regular.oft",       "lmsans17-oblique.oft",        "lmsans17-regular.oft",
    "lmsans8-oblique.oft",        "lmsans8-regular.oft",         "lmsans9-oblique.oft",
    "lmsans9-regular.oft",        "lmsansdemicond10-oblique.oft","lmsansdemicond10-regular.oft",
    "lmsansquot8-bold.oft",       "lmsansquot8-boldoblique.oft", "lmsansquot8-oblique.oft",
    "lmsansquot8-regular.oft"
#endif
};

#endif


// A brief comment here. The DEFAULT build of wxWidgets on Windows supports
// Unicode by using wide characters and strings. That causes me some pain
// but I NEED to accept it because the character that has code 0x14 in TeX
// encoding gets mapped to character code 0x2219 in the Bakoma fonts, and it
// is not at all clear that I have any way to access that glyph if I do
// not build in Unicode mode.


#ifndef fontsdir
#define fontsdir reduce.wxfonts
#endif

#define toString(x) toString1(x)
#define toString1(x) #x

void add_custom_fonts()
{
#ifndef MACINTOSH
// Note that on a Mac I put the required fonts in the Application Bundle.
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   char nn[LONGEST_LEGAL_FILENAME];
        sprintf(nn, "%s/%s/%s",
                    programDir, toString(fontsdir), fontNames[i]);
        printf("Adding %s: ", nn); fflush(stdout);
        wxString widename(nn);
        if (wxFont::AddPrivateFont(widename))
            printf(" OK\n");
        else printf("Failed\n");
    }
    printf("About to activate\n"); fflush(stdout);
    if (wxFont::ActivatePrivateFonts())
        printf("Activated OK\n");
    else printf("Activation failed\n");
    fflush(stdout);
#endif // MACINTOSH
// I find that the following commented out enumerations crash for me
// at least on some platforms.
    fflush(stdout);
}


void display_font_information()
{
    wxArrayString flist(wxFontEnumerator::GetFacenames(wxFONTENCODING_SYSTEM));
    int nfonts;
    printf("There are %d fonts\n", nfonts=(int)flist.GetCount());
    fflush(stdout);
    for (int i=0; i<nfonts; i++)
        printf("%d) <%s>\n", i, (const char *)flist[i].mb_str());
    fflush(stdout);
//    wxArrayString enclist(wxFontEnumerator::GetEncodings());
//    printf("There are %d encodings\n", (int)enclist.GetCount());
//    fflush(stdout);
//    for (unsigned int i=0; i<enclist.GetCount(); i++)
//        wxPrintf(L"Encoding (%d) <%s>\n", i, enclist[i]);
    printf("End of debug output\n");
    fflush(stdout);
}

bool fontApp::OnInit()
{
    display_font_information();
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
//
    char **myargv = (char **)argv;
    raw = 1;
    page = 0;
    bold = italic = 0;
    const char *font = "default";  // A default font name to ask for.
    int size = 48;           // a default size.
    for (int i=0; i<argc; i++)
    {
        printf("Arg%d: %s\n", i, myargv[i]);
        if (strcmp(myargv[i], "--raw") == 0) raw = !raw;
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

#define CELLWIDTH  11
#define CELLHEIGHT 20

fontFrame::fontFrame(const char *fname, int fsize)
       : wxFrame(NULL, wxID_ANY, "wxfontdemo")
{
    SetIcon(wxICON(fwin));
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
           "wxfontdemo (A C Norman 2014)\n"
           "wxWidgets version: %s\n"
           "Operating system: %s\n"
           "full Latin Modern Font details available via\n"
           "reduce-algebra.sourcefoge.net in csl/support-packages\n"
           "subdirectory of source archive",
           wxVERSION_STRING,
           wxGetOsDescription()),
       "About wxfontdemo",
       wxOK | wxICON_INFORMATION,
       this);
}

void fontPanel::OnChar(wxKeyEvent &event)
{
    printf("Char event\n"); fflush(stdout);
    event.Skip();
    page++;
    if (page == 0x1b0) page = 0x1c0; // skip surrogates
    Refresh();
}

void fontPanel::OnKeyDown(wxKeyEvent &event)
{
    printf("Key Down event\n"); fflush(stdout);
    page++;
    if (page == 0x1b0) page = 0x1c0; // skip surrogates
    event.Skip();
    Refresh();
}

void fontPanel::OnKeyUp(wxKeyEvent &event)
{
}

void fontPanel::OnMouse(wxMouseEvent &event)
{
    wxWindowDC dc(this);
    wxPoint where(event.GetLogicalPosition(dc));
    if (where.y > 200)
    {   page++;
        if (page == 0x1b0) page = 0x1c0; // skip surrogates
    }
    else
    {   page--;
        if (page == 0x1b0) page = 0x1a0; // skip surrogates
    }
    printf("Mouse event. Page now %d\n", page); fflush(stdout);
    event.Skip();
    Refresh();
}

//
// Maps showing character coverage of the private fonts I may use...
//

#include "fontmap.c"

static int once = 0;

void fontPanel::OnPaint(wxPaintEvent &event)
{
    wxPaintDC dc(this);
    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if (gc)
    {   gc->Scale(3.0, 3.0);
        wxColour c1(230, 200, 255);
        wxColour c2(100, 220, 120);
        wxBrush b1(c1); wxBrush b2(c2);
        wxPen p1(c1);   wxPen p2(c2);
        for (int y=0; y<256+2*32; y+=32)
        {   for (int x=0; x<33; x++)
            {   int k = ((y>>5) + x) & 1;
                gc->SetBrush(k ? b2 : b1);
                gc->SetPen(k ? p2 : p1);
                gc->DrawRectangle(CELLWIDTH*x, CELLHEIGHT*(y/32), CELLWIDTH, CELLHEIGHT);
            }
        }
        printf("fontname = %s\n", fontname);
        if (wxFontEnumerator::IsValidFacename(fontname))
            printf("Face name is valid\n");
        else
        {   printf("Invalid face name - font not found\n");
// Some sort of fall-back font may be used...
        }
        wxFontInfo ffi(10);
        ffi.FaceName(fontname);
        if (bold) ffi.Bold();
        if (italic) ffi.Italic();
        wxFont ff(ffi);
        if (ff.IsOk()) wxPrintf("Font seems OK\n");
        else wxPrintf("Font is *NOT* OK\n");
        wxPrintf("Face name = %s\n", ff.GetFaceName());
        wxPrintf("Native name = %s\n", ff.GetNativeFontInfoDesc());
        wxPrintf("Friendly name = %s\n", ff.GetNativeFontInfoUserDesc());
        fflush(stdout);
//        char fullfriendly[200];
//        sprintf(fullfriendly, "'%s'", fontname);
//        ff.SetNativeFontInfoUserDesc(fullfriendly);
//        if (ff.IsOk()) wxPrintf("Font seems OK after new name\n");
//        else wxPrintf("Font is *NOT* OK\n");
//        wxPrintf("Face name = %s\n", ff.GetFaceName());
//        wxPrintf("Native name = %s\n", ff.GetNativeFontInfoDesc());
//        wxPrintf("Friendly name = %s\n", ff.GetNativeFontInfoUserDesc());
//        wxPrintf("Encoding = %x\n", ff.GetDefaultEncoding());
//        fflush(stdout);
        wxGraphicsFont gff = gc->CreateFont(ff, *wxRED);
        uint32_t *map = find_glyphmap(fontname);
        wxFont labels(wxFontInfo(3));
        wxGraphicsFont glabels = gc->CreateFont(labels, *wxBLACK);
        gc->SetFont(glabels);
        for (int i=0; i<32; i++)
        {   char word[12];
            sprintf(word, "%02x", i);
            gc->DrawText(word, (((double)CELLWIDTH)*(i+1)) + CELLWIDTH/2.2,
                (double)CELLHEIGHT/10.0);
        }
        for (int i=0; i<8; i++)
        {   char word[12];
            sprintf(word, "%04x", 32*i + 0x80*page);
            gc->DrawText(word, CELLWIDTH/10.0,
                (double)CELLHEIGHT*(i+1) + CELLHEIGHT/2.5);
        }

        gc->SetFont(gff);

        if (once++ == 0)
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

// If I initialise all these to 999.0 then if GetTextExtent fails maybe I will
// still see something sensible?
        wxDouble w1=999.0, h1=999.0, d1=999.0, xl1=999.0;
        gc->GetTextExtent("X", &w1, &h1, &d1, &xl1);
        printf("letter X w:%.3g h:%.3g d:%.3g xl:%.3g\n", w1, h1, d1, xl1);
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
                gc->DrawEllipse(4.0*(((double)CELLWIDTH)*(j+1)-2.0),
                                4.0*(((double)CELLHEIGHT)*(i/32+1)+
                                     ((double)CELLHEIGHT)-2.0),
                                4.0*4.0, 4.0*4.0);
                gc->SetTransform(save);
                int k = i + j;
                if (!raw)
                {   if (k < 0xa) k = 0xa1 + k;
                    else if (k == 0xa) k = 0xc5;
#ifdef UNICODE
// In Unicode mode I have access to the character at code point 0x2219. If
// not I must insist on using my private version of the fonts where it is
// at 0xb7.
                    else if (k == 0x14) k = 0x2219;
#else
#error Old version
#endif
                    else if (k < 0x20) k = 0xa3 + k;
                    else if (k == 0x20) k = 0xc3;
                    else if (k == 0x7f) k = 0xc4;
                    else if (k >= 0x80) k += 0x80*page;
                }
                else k += 0x80*page;
// here I will use the coverage table to decide if I need to draw anything.
// I have not added that logic yet!
                wxString c = (wchar_t)k;
                double ww, hh, dd, el;
                gc->GetTextExtent(c, &ww, &hh, &dd, &el);
                if (ww == 0.0 || hh == 0.0) continue;
                if (map != NULL &&
                    char_present(k, map) == 0)
                {   gc->DrawRectangle(
                       (double)CELLWIDTH*(j+1)+CELLWIDTH/3.0,
                       (double)CELLHEIGHT*(i/32+1)+CELLHEIGHT/3.0,
                       CELLWIDTH/3.0, CELLHEIGHT/3.0);
                }
                else gc->DrawText(c,
                    ((double)CELLWIDTH)*(j+1),
                    ((double)CELLHEIGHT)*(i/32+1)+
                     ((double)CELLHEIGHT)-h1+d1);
            }
        }
#if 0
        printf("compmode = %x\n", gc->GetCompositionMode());
        printf("antialias = %x\n", gc->GetAntialiasMode());
        printf("interpqual = %x\n", gc->GetInterpolationQuality());
#endif
        delete gc;
    }
    else printf("gc=NULL\n");
    return;
}


// end of wxfontdemo.cpp

