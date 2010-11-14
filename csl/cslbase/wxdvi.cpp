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

/* Signature: 1dbc67bf 14-Nov-2010 */



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

// I have a generated file that contains the widths of all the fonts
// I am willing to use here.

#include "cmfont-widths.c"

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
    void RenderDVI();        // sub-function used by OnPaint
    wxPaintDC *dcp;          // pointer to device context to draw on
    int vertppi;

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
    int DVItoScreen(int n);  // map coordinates
    int DVItoScreenUP(int n);// ditto but used for rule widths

    int32_t h, v, w, x, y, z;// working values used in DVI decoding

    int32_t C[10], p;        // set by start of a page and not used!

// dvi files can call for an essentially unlimited number of distinct
// fonts - where one "font" here is not just to do with shape but also with
// size. If I pre-scanned the dvi data I could identify the largest font
// number used and allocate a table of exactly the right size. But for now
// I will use a fixed limit.
//
#define MAX_FONTS 256
    wxFont *font[MAX_FONTS];       // the fonts I use here
    font_width *fontWidth[MAX_FONTS], *currentFontWidth;
    double fontScale[MAX_FONTS], currentFontScale;

// num and den are intended to convert TeX internal units into units
// of 1.0e-7 metres. For display on a printer with some clearly known
// "DPI" this probably matters - for the purposes of on-screen display I
// will ignore it at present and just ASSUME that the values in the DVI file
// are scaled by 2^16 from points.
//
// mag is a magnification factor relative to 1000.
    int32_t num, den, mag;

// I will scale things by an extra amount mymag to get bigger displays while
// I am debugging. This will probably be set to 1.0 for any production code.
    const static double mymag = 4.0;

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

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

private:
    dviPanel *panel;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(dviFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  dviFrame::OnExit)
    EVT_MENU(wxID_ABOUT, dviFrame::OnAbout)
END_EVENT_TABLE()

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

const char *fullProgramName = "./wxdvi.exe";
const char *programName     = "wxdvi.exe";
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
        programName = "wxdvi";  /* nothing really known! */
        fullProgramName = ".\\wxdvi.exe";
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
        programName = (const char *)"wxdvi";
        fullProgramName = (const char *)"./wxdvi";
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
 * is stack allocated. I need to make it proper.
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
                char **nargs = (char **)malloc(sizeof(char *)*(argc+3));
                int i;
                nargs[0] = "/usr/bin/open";
                nargs[1] = xname;
                nargs[2] = "--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
// /usr/bin/open foo.app --args [any original arguments]
                return execv("/usr/bin/open", nargs);
            }
        }
#endif
        wxDISABLE_DEBUG_SUPPORT();
#if DEBUG
    logprintf("calling wxEntry\n");
#endif

        return wxEntry(argc, argv);
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

// It seems that when using wxWidgets that if I use the NOT_ENUM flag
// that the font can not be found at all, and hence not used! So I just
// tag it as PRIVATE.

// #define PRIVATE_FONT (FR_PRIVATE | FR_NOT_ENUM)
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
// I check each of the fonts that this application wants to see if they
// them for myself. I will ASSUME that there is no ambiguity as to what font
// is indicated by any particular name and so that any that are found read
// installed are in fact good in the context that I wish to use them.
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   memset((void *)&lf, 0, sizeof(lf));
        strcpy(lf.lfFaceName, fontNames[i].name);
        lf.lfCharSet = DEFAULT_CHARSET;
        lf.lfPitchAndFamily = 0;
        fontNeeded = 1;
        fontNames[i].path = NULL;
#if DEBUG
        logprintf("check if %s is already available\n", lf.lfFaceName);
#endif
        EnumFontFamiliesExA(hDC, &lf, fontEnumProc, 0, 0);
        if (!fontNeeded) continue;
        char nn[LONGEST_LEGAL_FILENAME];
        strcpy(nn, programDir);
        strcat(nn, "\\" toString(fontsdir) "\\");
        strcat(nn, fontNames[i].name); strcat(nn, ".ttf");
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
            logprintf("Failed to add font %s\n", fontNames[i].path);
        newFontAdded = 1;
    }

    if (newFontAdded)
    {   // This call to SendMessage may sometimes cause a long delay.
        SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
    }

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

// It might make sense to add just the fonts that I will be using rather than
// use extra resources adding all that are available. But for now I prefer
// simplicity.
    char fff[LONGEST_LEGAL_FILENAME];
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   sprintf(fff,
            "%s/" toString(fontsdir) "/%s.ttf",
            programDir, fontNames[i].name);
#if 0
        logprintf("Adding the font from %s\n", fff);
#endif
        FcConfigAppFontAddFile(config, (const FcChar8 *)fff);
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
    logprintf("fontset has %d distinct fonts out of %d total\n",
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
        logprintf("Desired font not found\n");
        return 1;
    }
// Note that an XftPattern is just an Fcpattern, so either set of functions
// can be used to create or manipulate one.
    XftPattern *ftPattern = NULL;
    for (int k=0; k<fs->nfont; k++)
    {   ftPattern = fs->fonts[k];
// FcPatternPrint displays info over several lines - valuable for debugging!
        FcPatternPrint(ftPattern); printf("\n");
    }

    ftVisual = DefaultVisual(dpy, screen);
    ftColorMap =  DefaultColormap(dpy, screen);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderBlack, &ftBlack);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderWhite, &ftWhite);
    XftFontSetDestroy(fs); // Now I am done with the list of fonts.
    return 0;
#endif // MACINTOSH
#endif // WIN32
}




//
// Now that start of my code in a proper sense!
//
//


/*
 * This is the ".dvi" file created by running LaTeX on the following
 * small input file. It is provided as a sequence of hex bytes so that
 * I have something to test and demonstrate even if there is no file
 * containig any .dvi stuff readily available.
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

#define screenDPI 72

void dviPanel::DefFont(int k)
{
#if 0
    logprintf("Define Font %d at offset %d\n", k, (int)(stringInput - dviData));
#endif
    char fontname[LONGEST_LEGAL_FILENAME];
    int32_t checksum = s4();
    int32_t size = s4();
    /* int32_t designsize = */ s4();
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
    if (font[k] != NULL) return;
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
    wxFont *f = new wxFont();
    char sizer[10];
    sprintf(sizer, " %d", (int)(p->designsize/1048576.0 + 0.5));
    strcat(fontname, sizer);
#if 1
    logprintf("Name + size = %s\n", fontname);
#endif
    f->SetNativeFontInfoUserDesc(fontname);
    int points = f->GetPointSize();  // size in points.
    int fontHeight = (int)(vertppi*points/72.27 + 0.5);
#if 1
    logprintf("Font was created as %d pixels %d points\n",
              fontHeight, points);
#endif
    double dsize = (double)size; // size in TeX units
// Now adjust into screen coordinates in the same way I do for positioning
    dsize = dsize*mymag*(double)screenDPI/(72.0*65536.0);
#if 1
    logprintf("desired pixel size on screen = %.3g\n", dsize);
#endif
// Now I feel a bit as if I am making an assumption here, viz that the
// pixel size returned in fontHeight is a fully accurate representation of
// the font size even though it has been forced to be an integer.
    f->Scale((float)(dsize*(double)mag/1000.0/(double)fontHeight));
// Well experiments show that the scaled font as set up here does NOT always
// have the pixel-height that I ideally wanted, but when I try fine-tuning the
// scaling I tend to find that I am probably as close as I can get and that
// the actual available scales fall in a discrete rather than a continuous
// sequence.
#if 1
// This is merely to display information about the font while I debug things.
    wxString s1(f->GetNativeFontInfoDesc());
    wxString s2(f->GetNativeFontInfoUserDesc());
    const char *ss1 = s1.c_str();
    const char *ss2 = s2.c_str();
    logprintf("New font %s\n%s\n", ss1, ss2);
#endif
    font[k] = f;
    fontWidth[k] = p;
    fontScale[k] = (double)size/(double)(p->designsize)*16.0;
#if 1
    logprintf("Scale factor for %s = %.3g\n", fontname, fontScale[k]);
#endif
}

void dviPanel::SelectFont(int n)
{
    if (n >= MAX_FONTS)
    {   logprintf("This code can only cope with MAX_FONTS distinct fonts\n");
        return;
    }
    if (font[n] == NULL)
    {   logprintf("font %d seems not to be set\n", n);
        return;
    }
    dcp->SetFont(*font[n]);
    currentFontWidth = fontWidth[n];
    currentFontScale = fontScale[n];
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

int dviPanel::DVItoScreen(int n)
{
// At present this is a fixed scaling. I may well want to make it variable
// at some later stage. The scaling here, which is based on an assumption
// I make about the dots-per-inch resolution of my display, will end up
// imprtant when establishing fonts.
    return (int)(mymag*(double)mag*(double)screenDPI*(double)n/
                 (72.0*65536.0*1000.0));
}

int dviPanel::DVItoScreenUP(int n)
{
// This ROUND UP to the next integer, and that is needed so that (eg)
// very thin rules end up at least one pixel wide. Well I round up by
// adding a value just under 1,0 then truncating.
    return (int)(0.999999999 + mymag*(double)mag/1000.0*
                 (double)screenDPI*(double)n/(72.0*65536.0));
}

void dviPanel::SetChar(int32_t c)
{
#ifdef DEBUG
    logprintf("Set (%f,%f) char %.2x (%c)\n",
        (double)h/(double)(1<<20), (double)v/(double)(1<<20), (int)c, (int)c);
#endif
    wxString s = (wchar_t)MapChar(c);
    wxCoord width, height, descent;
    dcp->GetTextExtent(s, &width, &height, &descent);
    dcp->DrawText(s, DVItoScreen(h), DVItoScreen(v)-(height-descent));
// Now I must increase h by the width (in scaled points) of the character
// I just set. This is not dependent at all on the way I map DVI internal
// coordinates to screen ones.
    int32_t ww = currentFontWidth->charwidth[c & 0x7f];
    int32_t design = currentFontWidth->designsize;
// ww is now the width as extracted from the .tfm file, and that applies
// to the glyph if it is set at its standard size.

    h += (int32_t)(currentFontScale*(double)design*(double)ww/(double)(1<<24) + 0.5);
}

void dviPanel::PutChar(int32_t c)
{
#ifdef DEBUG
    logprintf("Set (%f,%f) char %.2x (%c)\n",
        (double)h/(double)(1<<20), (double)v/(double)(1<<20), (int)c, (int)c);
#endif
    wxString s = (wchar_t)MapChar(c);
    wxCoord width, height, descent;
    dcp->GetTextExtent(s, &width, &height, &descent);
    dcp->DrawText(s, DVItoScreen(h), DVItoScreen(v)-(height-descent));
}

void dviPanel::SetRule(int height, int width)
{
#if 0
    logprintf("SetRule %d %.3g %d %.3g\n", width, (double)width/65536.0,
                                        height, (double)height/65537.0);
#endif
    dcp->DrawRectangle(DVItoScreen(h), DVItoScreen(v-height),
                       DVItoScreenUP(width), DVItoScreenUP(height));
}

void dviPanel::RenderDVI()
{
    wxColour c1(230, 200, 255);
    wxBrush b1(c1); 
    dcp->SetBrush(b1);
    wxPen p1(c1);
    dcp->SetPen(p1);

    wxSize window(dcp->GetSize());
    logprintf("Window size %d by %d\n", window.GetWidth(), window.GetHeight());
    dcp->DrawRectangle(wxPoint(0, 0), window);

    dcp->SetBrush(*wxBLACK_BRUSH);
    dcp->SetPen(*wxBLACK_PEN);

    wxSize PPI(dcp->GetPPI());
    logprintf("%d by %d ppi\n", PPI.GetWidth(), PPI.GetHeight());
    vertppi = PPI.GetHeight();
    wxSize displaymm(dcp->GetSizeMM());
    logprintf("display size mm %d by %d\n", displaymm.GetWidth(), displaymm.GetHeight());

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
        case 128:
                SetChar(*stringInput++);
                continue;
        case 129:
                SetChar(u2());
                continue;
        case 130:
                SetChar(u3());
                continue;
        case 131:
                SetChar(s4());
                continue;
        case 132:                           // set rule
                a = s4();
                b = s4();
                if (a > 0 && b >0) SetRule(a, b);
                h += b;
                continue;
        case 133:
                PutChar(*stringInput++);
                continue;
        case 134:
                PutChar(u2());
                continue;
        case 135:
                PutChar(u3());
                continue;
        case 136:
                PutChar(s4());
                continue;
        case 137:
                a = s4();
                b = s4();
                if (a > 0 && b >0) SetRule(a, b);
                continue;
        case 138:
                continue;                      // no operation
        case 139:                           // beginning of page
                h = v = w = x = y = z = stackp = 0;
                for (i=0; i<10; i++)
                    C[i] = s4();
                p = s4();
                continue;
        case 140:                           // end of page
                continue;
        case 141:
                push();
                continue;
        case 142:
                pop();
                continue;
        case 143:
                h += s1();
                continue;
        case 144:
                h += s2();
                continue;
        case 145:
                h += s3();
                continue;
        case 146:
                h += s4();
                continue;
        case 147:
                h += w;
                continue;
        case 148:
                h += (w = s1());
                continue;
        case 149:
                h += (w = s2());
                continue;
        case 150:
                h += (w = s3());
                continue;
        case 151:
                h += (w = s4());
                continue;
        case 152:
                h += x;
                continue;
        case 153:
                h += (x = s1());
                continue;
        case 154:
                h += (x = s2());
                continue;
        case 155:
                h += (x = s3());
                continue;
        case 156:
                h += (x = s4());
                continue;
        case 157:
                v += s1();
                continue;
        case 158:
                v += s2();
                continue;
        case 159:
                v += s3();
                continue;
        case 160:
                v += s4();
                continue;
        case 161:
                v += y;
                continue;
        case 162:
                v += (y = s1());
                continue;
        case 163:
                v += (y = s2());
                continue;
        case 164:
                v += (y = s4());
                continue;
        case 165:
                v += (y = s4());
                continue;
        case 166:
                v += z;
                continue;
        case 167:
                v += (z = s1());
                continue;
        case 168:
                v += (z = s2());
                continue;
        case 169:
                v += (z = s3());
                continue;
        case 170:
                v += (z = s4());
                continue;
        case 171:  case 172:  case 173:  case 174:
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
        case 235:
                SelectFont(*stringInput++);
                continue;
        case 236:
                SelectFont(u2());
                continue;
        case 237:
                SelectFont(u3());
                continue;
        case 238:
                SelectFont(s4());
                continue;
        case 239:
                k = *stringInput++;
                for (i=0; i<k; i++) *stringInput++;
                continue;
        case 240:
                k = u2();
                for (i=0; i<k; i++) *stringInput++;
                continue;
        case 241:
                k = u3();
                for (i=0; i<k; i++) *stringInput++;
                continue;
        case 242:
                k = s4();
                for (i=0; i<k; i++) *stringInput++;
                continue;
        case 243:                         // fnt_def1
                DefFont(*stringInput++);
                continue;
        case 244:
                DefFont(u2());
                continue;
        case 245:
                DefFont(u3());
                continue;
        case 246:
                DefFont(s4());
                continue;
        case 247:                          // pre
                i = *stringInput++;
                if (i != 2)
                {   logprintf("illegal DVI version %d\n", i);
                    break;
                }
                num = s4();
                den = s4();
                mag = s4();
                k = *stringInput++;
                for (i=0; i<k; i++) *stringInput++;
                logprintf("PRE: num=%d, den=%d, (%f) mag=%d\n",
                       num, den, (double)num/(double)den, mag);
                continue;
        case 248:                          // post
                s4(); // ignore p;
                s4(); // ignure num
                s4(); // ignore den
                s4(); // ignore mag
                s4(); // height+depth of largest page
                s4(); // width of largest page
#if 0
                logprintf("Greatest stack depth = %d\n", u2());
                logprintf("Page count = %d\n", u2());
#endif
    // The postamble will have font definitions here as well.
                continue;
        case 249:                          // post_post
                s4();
                *stringInput++;
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
    logprintf("end of file\n");
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
    panel = new dviPanel(this, dvifilename);
    SetClientSize(panel->GetSize());
    wxSize s(GetSize());
    SetMinSize(s);
    SetMaxSize(s);
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
    for (int i=0; i<MAX_FONTS; i++) font[i] = NULL;
    wxSize clientsize(1200, 600);
    wxSize winsize(ClientToWindowSize(clientsize));
    SetSize(winsize);
    Centre();
}


void dviFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{
    Destroy();
    exit(0);    // I want the whole application to terminate here!
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
    Refresh();     // forces redraw of everything
}

void dviPanel::OnPaint(wxPaintEvent &event)
{
    wxPaintDC mydc(this);
    dcp = &mydc;
    RenderDVI();
    return;
}


// end of wxdvi.cpp

