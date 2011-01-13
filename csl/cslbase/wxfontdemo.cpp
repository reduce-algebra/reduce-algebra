#define LISTFONTS 1 /* while I debug */
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

/* Signature: 581be6a5 13-Jan-2011 */



// The first few lines are essentially taken from the wxWidgets documentation
// and will be the same for almost all wxWidgets code.

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

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

static Display *dpy;
static Visual *ftVisual = NULL;
static Colormap ftColorMap;
static XRenderColor ftRenderBlack = {0,0,0,0xffff};
static XRenderColor ftRenderWhite = {0xffff,0xffff,0xffff,0xffff};
static XftColor ftBlack, ftWhite;
static XftFont *ftFont = NULL;

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
    wxFont *ff;
    bool fontScaled;
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

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

private:
    fontPanel *panel;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fontFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  fontFrame::OnExit)
    EVT_MENU(wxID_ABOUT, fontFrame::OnAbout)
END_EVENT_TABLE()

int raw, page;

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
    int len, ndir, npgm, j;
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
    j = len-1;
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

int main(int argc, char *argv[])
{
    int i;
    int usegui = 1;
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

typedef struct localFonts
{
    const char *name;
    char *path;
} localFonts;

static localFonts fontNames[] =
{
// Right now I will add in ALL the fonts from the BaKoMa collection.
// This can make sense in a font demo program but in a more serious
// application I should be a little more selective!
    {"cmuntt",          NULL},
    {"DejaVuSansMono",  NULL},
    {"fireflysung",     NULL},
    {"sazanami-gothic", NULL},
    {"sazanami-mincho", NULL},
    {"csl-cmb10",    NULL},        {"csl-cmbsy10",  NULL},
    {"csl-cmbsy6",   NULL},        {"csl-cmbsy7",   NULL},
    {"csl-cmbsy8",   NULL},        {"csl-cmbsy9",   NULL},
    {"csl-cmbx10",   NULL},        {"csl-cmbx12",   NULL},
    {"csl-cmbx5",    NULL},        {"csl-cmbx6",    NULL},
    {"csl-cmbx7",    NULL},        {"csl-cmbx8",    NULL},
    {"csl-cmbx9",    NULL},        {"csl-cmbxsl10", NULL},
    {"csl-cmbxti10", NULL},        {"csl-cmcsc10",  NULL},
    {"csl-cmcsc8",   NULL},        {"csl-cmcsc9",   NULL},
    {"csl-cmdunh10", NULL},        {"csl-cmex10",   NULL},
    {"csl-cmex7",    NULL},        {"csl-cmex8",    NULL},
    {"csl-cmex9",    NULL},        {"csl-cmff10",   NULL},
    {"csl-cmfi10",   NULL},        {"csl-cmfib8",   NULL},
    {"csl-cminch",   NULL},        {"csl-cmitt10",  NULL},
    {"csl-cmmi10",   NULL},        {"csl-cmmi12",   NULL},
    {"csl-cmmi5",    NULL},        {"csl-cmmi6",    NULL},
    {"csl-cmmi7",    NULL},        {"csl-cmmi8",    NULL},
    {"csl-cmmi9",    NULL},        {"csl-cmmib10",  NULL},
    {"csl-cmmib6",   NULL},        {"csl-cmmib7",   NULL},
    {"csl-cmmib8",   NULL},        {"csl-cmmib9",   NULL},
    {"csl-cmr10",    NULL},        {"csl-cmr12",    NULL},
    {"csl-cmr17",    NULL},        {"csl-cmr5",     NULL},
    {"csl-cmr6",     NULL},        {"csl-cmr7",     NULL},
    {"csl-cmr8",     NULL},        {"csl-cmr9",     NULL},
    {"csl-cmsl10",   NULL},        {"csl-cmsl12",   NULL},
    {"csl-cmsl8",    NULL},        {"csl-cmsl9",    NULL},
    {"csl-cmsltt10", NULL},        {"csl-cmss10",   NULL},
    {"csl-cmss12",   NULL},        {"csl-cmss17",   NULL},
    {"csl-cmss8",    NULL},        {"csl-cmss9",    NULL},
    {"csl-cmssbx10", NULL},        {"csl-cmssdc10", NULL},
    {"csl-cmssi10",  NULL},        {"csl-cmssi12",  NULL},
    {"csl-cmssi17",  NULL},        {"csl-cmssi8",   NULL},
    {"csl-cmssi9",   NULL},        {"csl-cmssq8",   NULL},
    {"csl-cmssqi8",  NULL},        {"csl-cmsy10",   NULL},
    {"csl-cmsy5",    NULL},        {"csl-cmsy6",    NULL},
    {"csl-cmsy7",    NULL},        {"csl-cmsy8",    NULL},
    {"csl-cmsy9",    NULL},        {"csl-cmtcsc10", NULL},
    {"csl-cmtex10",  NULL},        {"csl-cmtex8",   NULL},
    {"csl-cmtex9",   NULL},        {"csl-cmti10",   NULL},
    {"csl-cmti12",   NULL},        {"csl-cmti7",    NULL},
    {"csl-cmti8",    NULL},        {"csl-cmti9",    NULL},
    {"csl-cmtt10",   NULL},        {"csl-cmtt12",   NULL},
    {"csl-cmtt8",    NULL},        {"csl-cmtt9",    NULL},
    {"csl-cmu10",    NULL},        {"csl-cmvtt10",  NULL},
    {"csl-euex10",   NULL},        {"csl-euex7",    NULL},
    {"csl-euex8",    NULL},        {"csl-euex9",    NULL},
    {"csl-eufb10",   NULL},        {"csl-eufb5",    NULL},
    {"csl-eufb6",    NULL},        {"csl-eufb7",    NULL},
    {"csl-eufb8",    NULL},        {"csl-eufb9",    NULL},
    {"csl-eufm10",   NULL},        {"csl-eufm5",    NULL},
    {"csl-eufm6",    NULL},        {"csl-eufm7",    NULL},
    {"csl-eufm8",    NULL},        {"csl-eufm9",    NULL},
    {"csl-eurb10",   NULL},        {"csl-eurb5",    NULL},
    {"csl-eurb6",    NULL},        {"csl-eurb7",    NULL},
    {"csl-eurb8",    NULL},        {"csl-eurb9",    NULL},
    {"csl-eurm10",   NULL},        {"csl-eurm5",    NULL},
    {"csl-eurm6",    NULL},        {"csl-eurm7",    NULL},
    {"csl-eurm8",    NULL},        {"csl-eurm9",    NULL},
    {"csl-eusb10",   NULL},        {"csl-eusb5",    NULL},
    {"csl-eusb6",    NULL},        {"csl-eusb7",    NULL},
    {"csl-eusb8",    NULL},        {"csl-eusb9",    NULL},
    {"csl-eusm10",   NULL},        {"csl-eusm5",    NULL},
    {"csl-eusm6",    NULL},        {"csl-eusm7",    NULL},
    {"csl-eusm8",    NULL},        {"csl-eusm9",    NULL},
    {"csl-msam10",   NULL},        {"csl-msam5",    NULL},
    {"csl-msam6",    NULL},        {"csl-msam7",    NULL},
    {"csl-msam8",    NULL},        {"csl-msam9",    NULL},
    {"csl-msbm10",   NULL},        {"csl-msbm5",    NULL},
    {"csl-msbm6",    NULL},        {"csl-msbm7",    NULL},
    {"csl-msbm8",    NULL},        {"csl-msbm9",    NULL}
};

#endif

#ifdef WIN32

// The next two flags instruct AddFontResourceEx that a font should be
// available only to this application and that other application should
// not even be able to see that it exists. I provide definitions here
// in case MinGW32 does not have them in its header files.

#ifndef FR_PRIVATE
#define FR_PRIVATE   0x10
#endif

#ifndef FR_NOT_ENUM
#define FR_NOT_ENUM  0x20
#endif

/* #define PRIVATE_FONT (FR_PRIVATE | FR_NOT_ENUM) */
#define PRIVATE_FONT FR_PRIVATE

static int fontNeeded = 0;

// A brief comment here. The DEFAULT build of wxWidgets on Windows supports
// Unicode by using wide characters and strings. That causes me some pain
// but I NEED to accept it because the character that has code 0x14 in TeX
// encoding gets mapped to character code 0x2219 in the Bakoma fonts, and it
// is not at all clear that I have any way to access that glyph if I do
// not build in Unicode mode.

// You will see a load of places I explicitly call the non-Unicode versions
// of Windows functions (eg with an "A" at the end of their name) when I wish
// to pass legacy pre-unicode strings to them.

static int CALLBACK fontEnumProc(
    const LOGFONTA *lpelfe,     // logical-font data
    const TEXTMETRICA *lpntme,  // physical-font data
    DWORD FontType,             // type of font
    LPARAM lParam)              // application-defined data
{
    fontNeeded = 0;
    return 0;
}


#ifdef LISTFONTS
static char faceName[LONGEST_LEGAL_FILENAME] = "";

static int CALLBACK fontEnumProc1(
    const LOGFONTA *lpelfe,     // logical-font data
    const TEXTMETRICA *lpntme,  // physical-font data
    DWORD FontType,             // type of font
    LPARAM lParam)              // application-defined data
{
// avoid duplicated reports
    if (strcmp(lpelfe->lfFaceName, faceName) == 0) return 1;
    strcpy(faceName, lpelfe->lfFaceName);
    printf("Font \"%s\" is available\n", lpelfe->lfFaceName);
    fflush(stdout);
    return 1;
}
#endif

#endif


#ifndef fontsdir
#define fontsdir reduce.wxfonts
#endif

#define toString(x) toString1(x)
#define toString1(x) #x

int add_custom_fonts() // return 0 on success.
{
#ifdef WIN32
    HDC hDC = CreateCompatibleDC(NULL);
    LOGFONTA lf;
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   memset((void *)&lf, 0, sizeof(lf));
        strcpy(lf.lfFaceName, fontNames[i].name);
        lf.lfCharSet = DEFAULT_CHARSET;
        lf.lfPitchAndFamily = 0;
        fontNeeded = 1;
        fontNames[i].path = NULL;
// I check each of the fonts that this application wants to see if they
// are already installed. If they are then there is no merit in installing
// them for myself. Well that is maybe silly since these are private fonts
// that I really do not expect anybody to have installed before! But I will
// leave this in here at least for now.
        EnumFontFamiliesExA(hDC, &lf, fontEnumProc, 0, 0);
        if (!fontNeeded) continue;
        char nn[LONGEST_LEGAL_FILENAME];
        strcpy(nn, programDir);
        strcat(nn, "\\" toString(fontsdir) "\\");
        strcat(nn, fontNames[i].name);
// The first font used here is .oft the rest are .ttf
        if (i == 0) strcat(nn, ".otf");
        else strcat(nn, ".ttf");
        char *nn1 = (char *)malloc(strlen(nn) + 1);
        strcpy(nn1, nn);
        fontNames[i].path = nn1;
    }
// Now, for each font that was NOT already available I need to go
//       AddFontResource[Ex]("filename")
//       SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
    int newFontAdded = 0;
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   if (fontNames[i].path == NULL) continue;
        if (AddFontResourceExA(fontNames[i].path, PRIVATE_FONT, 0) == 0)
        {   printf("Failed to add font %s\n", fontNames[i].path);
            fflush(stdout);
        }
        newFontAdded = 1;
//      printf("AddFontResource %s\n", fontNames[i].path);
//      fflush(stdout);
    }

    if (newFontAdded)
    {   // This call to SendMessage may sometimes cause a long delay.
        SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
    }

// Now list all the fonts that are available...
    memset((void *)&lf, 0, sizeof(lf));
    lf.lfFaceName[0] = '\0';
    lf.lfCharSet = DEFAULT_CHARSET;
    lf.lfPitchAndFamily = 0;
#ifdef LISTFONTS
    printf("About to list all fonts that are now available\n");
    fflush(stdout);
    EnumFontFamiliesExA(hDC, &lf, fontEnumProc1, 0, 0);
    printf("Listing complete\n");
    fflush(stdout);
#endif
    DeleteDC(hDC);
    return 0;
#else // WIN32
#ifdef MACINTOSH

// Custom fonts are supported by including them in the Application Bundle
// and mentioning them in a Plist there, so I do not need and code here to
// deal with anything!
    return 1;

#else // Assume all that is left is X11, and that Xft/fontconfig are available
    int screen = 0;
    XftFontSet *fs = NULL;
    FcConfig *config = FcConfigCreate();
    dpy = XOpenDisplay(NULL);
    if (dpy == NULL)
    {   printf("Unable to access the display\n");
        exit(1);
    }
    screen = DefaultScreen(dpy);

    char fff[LONGEST_LEGAL_FILENAME];
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   int w;
        sprintf(fff,
            (i < 3 ? "%s/" toString(fontsdir) "/%s.otf" :
                     "%s/" toString(fontsdir) "/%s.ttf"),
            programDir, fontNames[i].name);
        w = FcConfigAppFontAddFile(config, (const FcChar8 *)fff);
#ifdef LISTFONTS
        printf("Adding the font from %s = %d\n", fff, w);
#endif
    }
    FcConfigSetCurrent(config);
    XftInit("");
    fs = XftListFonts(dpy, screen,
//                    XFT_FAMILY, XftTypeString, fontname,
                      NULL,
// I will ask XftListFonts to return all available information about the
// fonts that are found.
                      XFT_FAMILY, XFT_STYLE, XFT_SLANT, XFT_WEIGHT,
                      XFT_SIZE, XFT_PIXEL_SIZE, XFT_ENCODING,
                      XFT_SPACING, XFT_FOUNDRY, XFT_CORE, XFT_ANTIALIAS,
                      XFT_XLFD, XFT_FILE, XFT_INDEX, XFT_RASTERIZER,
                      XFT_OUTLINE, XFT_SCALABLE, XFT_RGBA,
                      XFT_SCALE, XFT_RENDER, XFT_MINSPACE,
                      NULL);
    printf("fontset has %d distinct fonts out of %d total\n",
           fs->nfont, fs->sfont);
// Having obtained all the fonts I will print out all the information about
// them that Xft is prepared to give me. Note that this seems not to include
// either the "true" or the "Postscript" name that I might previously have
// thought was important to me. I think that this is because all the
// information here comes directly from the font-files rather than from any
// mapping tables. The key items here are thus probably
//    family
//    style
//    slant
//    weight
    if (fs->nfont == 0)
    {   XftFontSetDestroy(fs);
        printf("Desired font not found\n");
        return 1;
    }
// Note that an XftPattern is just an Fcpattern, so either set of functions
// can be used to create or manipulate one.
    XftPattern *ftPattern = NULL;
    for (int k=0; k<fs->nfont; k++)
    {   ftPattern = fs->fonts[k];
// NameUnparse converts the name to something printable
// But BOO HISS the version of Xft shipped with openSuSE 10.2 and with some
// other versions of Linux missed it out, so just for now I will comment that
// bit out. Oh dear! A web search finds patches to gentoo to fix this for
// builds involving qt3 so it really is not just me! But I BELIEVE it will be
// a transient bug so I will not put it in the autoconf stuff just at present.
#if 0
        char buffer[1000];
        XftNameUnparse(ftPattern, buffer, sizeof(buffer));
        printf("%s\n", buffer); fflush(stdout);
#endif
// FcPatternPrint displays info over several lines - valuable for debugging!
        FcPatternPrint(ftPattern); printf("\n"); fflush(stdout);
    }

    ftVisual = DefaultVisual(dpy, screen);
    ftColorMap =  DefaultColormap(dpy, screen);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderBlack, &ftBlack);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderWhite, &ftWhite);
#if 0
// I had identified the font that I wanted earlier so now I can open it
// by just using the information collected then.
    ftFont = XftFontOpen(dpy, screen,
                         XFT_FAMILY, XftTypeString, fontname,
                         XFT_SIZE, XftTypeDouble, 24.0,
                         NULL);
#endif
    XftFontSetDestroy(fs); // Now I am done with the list of fonts.
    return 0;
#endif // MACINTOSH
#endif // WIN32
}


bool fontApp::OnInit()
{
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;
    raw = 1;
    page = 0;
    for (int i=0; i<argc; i++)
    {
        printf("Arg%d: %s\n", i, myargv[i]);
        if (strcmp(myargv[i], "--raw") == 0) raw = !raw;
        else if (myargv[i][0]!= '-' ||
                 sscanf(myargv[i]+1, "%d", &page) != 1) page = 0;
    }
// I will find the special fonts that most interest me in a location related
// to the directory that this application was launched from. So the first
// think to do is to identify that location. I then print the information I
// recover so I can debug things. I have already set up programName etc
    printf("\n%s\n%s\n%s\n", fullProgramName, programName, programDir);

    add_custom_fonts();

    const char *font = "default";  // A default font name to ask for.
    int size = 48;           // a default size.
    if (argc > 1) font = myargv[1];
    if (argc > 2)
    {   size = atoi(myargv[2]);
        if (size <= 2 || size > 200) size = 48;
    }
    printf("Try for font \"%s\" at size=%d\n", font, size);

    fontFrame *frame = new fontFrame(font, size);
    frame->Show(true);
    return true;
}

fontFrame::fontFrame(const char *fname, int fsize)
       : wxFrame(NULL, wxID_ANY, "wxfontdemo")
{
    SetIcon(wxICON(fwin));
    panel = new fontPanel(this, fname, fsize);
    wxSize clientsize(32*32, 9*64);
    wxSize winsize(ClientToWindowSize(clientsize));
    SetSize(winsize);
    SetMinSize(winsize);
    SetMaxSize(winsize);
    Centre();
}


fontPanel::fontPanel(fontFrame *parent, const char *fname, int fsize)
       : wxPanel(parent)
{
// I *think* I want to make the font have a size specified in pixels
// not points here... however that appears to be delicate. So I will
// create one at a plausible point size then adjust it later. I will
// use "fontScaled" to ensure I only adjust it once.
    frame = parent;
    fontname = fname;
    fontsize = fsize;
    ff = new wxFont();
    ff->SetFaceName(fontname);
    ff->SetPointSize(36);
    frame->SetTitle(ff->GetNativeFontInfoUserDesc());
    fontScaled = false;

}


void fontFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{
    Destroy();
    exit(0);    // I want the whole application to terminate here!
}

void fontFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{
    wxMessageBox(
       wxString::Format(
           "wxfontdemo (A C Norman 2010)\nwxWidgets version: %s\nOperating system: %s",
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
    printf("Key Up event\n"); fflush(stdout);
    event.Skip();
    page++;
    if (page == 0x1b0) page = 0x1c0; // skip surrogates
    Refresh();
}

void fontPanel::OnMouse(wxMouseEvent &event)
{
    page++;
    if (page == 0x1b0) page = 0x1c0; // skip surrogates
    printf("Mouse event. Page now %d\n", page); fflush(stdout);
    event.Skip();
    Refresh();
}

void fontPanel::OnPaint(wxPaintEvent &event)
{
    wxPaintDC dc(this);
    wxColour c1(230, 200, 255);
    wxColour c2(100, 220, 120);
    wxBrush b1(c1); wxBrush b2(c2);
    wxPen p1(c1);   wxPen p2(c2);

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
        wxPrintf("Font = %s\n", f);
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
            int k = i + j;
            if (!raw)
            {   if (k < 0xa) k = 0xa1 + k;
                else if (k == 0xa) k = 0xc5;
#ifdef UNICODE
// In Unicode mode I have access to the character at code point 0x2219. If
// not I must insist on using my private version of the fonts where it is
// at 0xb7.
                else if (k == 0x14) k = 0x2219;
#endif
                else if (k < 0x20) k = 0xa3 + k;
                else if (k == 0x20) k = 0xc3;
                else if (k == 0x7f) k = 0xc4;
                else if (k >= 0x80) k += 0x80*page;
            }
            else k += 0x80*page;
            wxString c = (wchar_t)k;
            dc.DrawText(c, 32*j, 2*i+64  -h1+d1);
        }
    }
}


// end of wxfontdemo.cpp

