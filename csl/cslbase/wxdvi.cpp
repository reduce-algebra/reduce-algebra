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

/* Signature: 6850fd17 08-Nov-2010 */



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

class dviApp : public wxApp
{
public:
    virtual bool OnInit();
};

class dviFrame : public wxFrame
{
public:
    dviFrame(char *dvifilename);

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnPaint(wxPaintEvent &event);

private:
    char *dvidata;
    wxFont *ff;
    bool fontScaled;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(dviFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  dviFrame::OnExit)
// Right now I do not provide a menu that lets me trigger OnAbout.
    EVT_MENU(wxID_ABOUT, dviFrame::OnAbout)
    EVT_PAINT(           dviFrame::OnPaint)
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

int find_program_directory(char *argv0)
{
    char *w;
    int len, ndir, npgm, j;
/* In older code I believed that I could rely on Windows giving me
 * the full path of my executable in argv[0]. With bits of mingw/cygwin
 * anywhere near me that may not be so, so I grab the information directly
 * from the Windows APIs.
 */
    char execname[LONGEST_LEGAL_FILENAME];
    GetModuleFileName(NULL, execname, LONGEST_LEGAL_FILENAME-2);
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

int find_program_directory(char *argv0)
{
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
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
    {   for (w=argv0; *w!=0 && *w!='/'; w++);   /* seek a "/" */
        if (*w == '/')      /* treat as if relative to current dir */
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
    {   char *s = my_getenv("DISPLAY");
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
                return execv("/usr/bin/open", nargs);
            }
        }
#endif
        wxDISABLE_DEBUG_SUPPORT();
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
    {"cmb10",    NULL},  {"cmbsy10",  NULL},  {"cmbsy6",   NULL},
    {"cmbsy7",   NULL},  {"cmbsy8",   NULL},  {"cmbsy9",   NULL},
    {"cmbx10",   NULL},  {"cmbx12",   NULL},  {"cmbx5",    NULL},
    {"cmbx6",    NULL},  {"cmbx7",    NULL},  {"cmbx8",    NULL},
    {"cmbx9",    NULL},  {"cmbxsl10", NULL},  {"cmbxti10", NULL},
    {"cmcsc10",  NULL},  {"cmcsc8",   NULL},  {"cmcsc9",   NULL},
    {"cmdunh10", NULL},  {"cmex10",   NULL},  {"cmex7",    NULL},
    {"cmex8",    NULL},  {"cmex9",    NULL},  {"cmff10",   NULL},
    {"cmfi10",   NULL},  {"cmfib8",   NULL},  {"cminch",   NULL},
    {"cmitt10",  NULL},  {"cmmi10",   NULL},  {"cmmi12",   NULL},
    {"cmmi5",    NULL},  {"cmmi6",    NULL},  {"cmmi7",    NULL},
    {"cmmi8",    NULL},  {"cmmi9",    NULL},  {"cmmib10",  NULL},
    {"cmmib6",   NULL},  {"cmmib7",   NULL},  {"cmmib8",   NULL},
    {"cmmib9",   NULL},  {"cmr10",    NULL},  {"cmr12",    NULL},
    {"cmr17",    NULL},  {"cmr5",     NULL},  {"cmr6",     NULL},
    {"cmr7",     NULL},  {"cmr8",     NULL},  {"cmr9",     NULL},
    {"cmsl10",   NULL},  {"cmsl12",   NULL},  {"cmsl8",    NULL},
    {"cmsl9",    NULL},  {"cmsltt10", NULL},  {"cmss10",   NULL},
    {"cmss12",   NULL},  {"cmss17",   NULL},  {"cmss8",    NULL},
    {"cmss9",    NULL},  {"cmssbx10", NULL},  {"cmssdc10", NULL},
    {"cmssi10",  NULL},  {"cmssi12",  NULL},  {"cmssi17",  NULL},
    {"cmssi8",   NULL},  {"cmssi9",   NULL},  {"cmssq8",   NULL},
    {"cmssqi8",  NULL},  {"cmsy10",   NULL},  {"cmsy5",    NULL},
    {"cmsy6",    NULL},  {"cmsy7",    NULL},  {"cmsy8",    NULL},
    {"cmsy9",    NULL},  {"cmtcsc10", NULL},  {"cmtex10",  NULL},
    {"cmtex8",   NULL},  {"cmtex9",   NULL},  {"cmti10",   NULL},
    {"cmti12",   NULL},  {"cmti7",    NULL},  {"cmti8",    NULL},
    {"cmti9",    NULL},  {"cmtt10",   NULL},  {"cmtt12",   NULL},
    {"cmtt8",    NULL},  {"cmtt9",    NULL},  {"cmu10",    NULL},
    {"cmvtt10",  NULL},  {"euex10",   NULL},  {"euex7",    NULL},
    {"euex8",    NULL},  {"euex9",    NULL},  {"eufb10",   NULL},
    {"eufb5",    NULL},  {"eufb6",    NULL},  {"eufb7",    NULL},
    {"eufb8",    NULL},  {"eufb9",    NULL},  {"eufm10",   NULL},
    {"eufm5",    NULL},  {"eufm6",    NULL},  {"eufm7",    NULL},
    {"eufm8",    NULL},  {"eufm9",    NULL},  {"eurb10",   NULL},
    {"eurb5",    NULL},  {"eurb6",    NULL},  {"eurb7",    NULL},
    {"eurb8",    NULL},  {"eurb9",    NULL},  {"eurm10",   NULL},
    {"eurm5",    NULL},  {"eurm6",    NULL},  {"eurm7",    NULL},
    {"eurm8",    NULL},  {"eurm9",    NULL},  {"eusb10",   NULL},
    {"eusb5",    NULL},  {"eusb6",    NULL},  {"eusb7",    NULL},
    {"eusb8",    NULL},  {"eusb9",    NULL},  {"eusm10",   NULL},
    {"eusm5",    NULL},  {"eusm6",    NULL},  {"eusm7",    NULL},
    {"eusm8",    NULL},  {"eusm9",    NULL},  {"msam10",   NULL},
    {"msam5",    NULL},  {"msam6",    NULL},  {"msam7",    NULL},
    {"msam8",    NULL},  {"msam9",    NULL},  {"msbm10",   NULL},
    {"msbm5",    NULL},  {"msbm6",    NULL},  {"msbm7",    NULL},
    {"msbm8",    NULL},  {"msbm9",    NULL}
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

#define PRIVATE_FONT (FR_PRIVATE | FR_NOT_ENUM)

static int fontNeeded = 0;

// A brief comment here. The DEFAULT build of wxWidgets on Windows supports
// Unicode by using wide characters and strings. That causes major pain to
// my legacy code that just uses simple old-style C strings everywhere and
// so uses the old-style C functions that actr on them. Sometime in the
// future it is probable that I should clean up my code to work with modern
// international character-sets through Unicode, but since I have not done
// that yet I MUST (at least on Windows) restrict myself to a non-Unicode
// build of wxWidgets.

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
    LOGFONT lf;
// I check each of the fonts that this application wants to see if they
// are already installed. If they are then there is no merit in installing
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
        EnumFontFamiliesEx(hDC, &lf, fontEnumProc, 0, 0);
        if (!fontNeeded) continue;
        char *nn = new char [strlen(programDir) +
                             strlen(toString(fontsdir)) + 16];
        strcpy(nn, programDir);
        strcat(nn, "\\" toString(fontsdir) "\\");
        strcat(nn, fontNames[i].name); strcat(nn, ".ttf");
        fontNames[i].path = nn;
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
    for (int i=0; i<sizeof(fontNames)/sizeof(fontNames[0]); i++)
    {   sprintf(fff,
            "%s/" toString(fontsdir) "/%s.ttf",
            programDir, fontNames[i].name);
        printf("Adding the font from %s\n", fff);
        FcConfigAppFontAddFile(config, (const FcChar8 *)fff);
    }
    FcConfigSetCurrent(config);
    XftInit("");
    fs = XftListFonts(dpy, screen,
//                    XFT_FAMILY, XftTypeString, fontname,
                      NULL,
                      XFT_FAMILY, XFT_STYLE, XFT_SLANT, XFT_WEIGHT,
                      XFT_SIZE, XFT_PIXEL_SIZE, XFT_ENCODING,
                      XFT_SPACING, XFT_FOUNDRY, XFT_CORE, XFT_ANTIALIAS,
                      XFT_XLFD, XFT_FILE, XFT_INDEX, XFT_RASTERIZER,
                      XFT_OUTLINE, XFT_SCALABLE, XFT_RGBA,
                      XFT_SCALE, XFT_RENDER, XFT_MINSPACE,
                      NULL);
    printf("fontset has %d distinct fonts out of %d total\n",
           fs->nfont, fs->sfont);
    char buffer[200];
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
 *  \documentclass{article}
 *  \begin{document}
 *  This is some text
 *  \[ \frac{- b \pm \sqrt{b^2 - 4ac}}{2a}\]
 *  end text
 *  \end{document}
 */

unsigned char math_dvi[] =
{
    0xf7,  0x02,  0x01,  0x83,  0x92,  0xc0,  0x1c,  0x3b,  
    0x00,  0x00,  0x00,  0x00,  0x03,  0xe8,  0x1b,  0x20,  
    0x54,  0x65,  0x58,  0x20,  0x6f,  0x75,  0x74,  0x70,  
    0x75,  0x74,  0x20,  0x32,  0x30,  0x31,  0x30,  0x2e,  
    0x31,  0x31,  0x2e,  0x30,  0x35,  0x3a,  0x32,  0x30,  
    0x33,  0x33,  0x8b,  0x00,  0x00,  0x00,  0x01,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0xff,  0xff,  0xff,  0xff,  0xa0,  
    0x02,  0x79,  0x00,  0x00,  0x8d,  0xa0,  0xfd,  0xa3,  
    0x00,  0x00,  0xa0,  0x02,  0x3f,  0x00,  0x00,  0x8d,  
    0xa0,  0xfd,  0xe4,  0x00,  0x00,  0x8d,  0x91,  0x4d,  
    0x00,  0x00,  0xf3,  0x07,  0x4b,  0xf1,  0x60,  0x79,  
    0x00,  0x0a,  0x00,  0x00,  0x00,  0x0a,  0x00,  0x00,  
    0x00,  0x05,  0x63,  0x6d,  0x72,  0x31,  0x30,  0xb2,  
    0x54,  0x68,  0x69,  0x73,  0x96,  0x03,  0x55,  0x55,  
    0x69,  0x73,  0x93,  0x73,  0x6f,  0x6d,  0x65,  0x93,  
    0x74,  0x65,  0x78,  0x74,  0x8e,  0x9f,  0x10,  0xe5,  
    0xfb,  0x8d,  0x8d,  0x8d,  0x8d,  0x9f,  0xf9,  0x3c,  
    0x24,  0x8d,  0x92,  0x00,  0xc8,  0x61,  0x7e,  0xf3,  
    0x0d,  0x21,  0x22,  0x2c,  0x9a,  0x00,  0x0a,  0x00,  
    0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  
    0x6d,  0x73,  0x79,  0x31,  0x30,  0xb8,  0x00,  0xf3,  
    0x0a,  0x0b,  0xa0,  0x62,  0x3e,  0x00,  0x0a,  0x00,  
    0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  
    0x6d,  0x6d,  0x69,  0x31,  0x30,  0xb5,  0x62,  0x96,  
    0x02,  0x38,  0xe0,  0xb8,  0x06,  0x8d,  0x8d,  0x93,  
    0x9f,  0xf7,  0xaa,  0xab,  0x70,  0x8e,  0x8d,  0x91,  
    0x0a,  0x8e,  0x37,  0x9f,  0xf7,  0xaa,  0xab,  0x89,  
    0x00,  0x00,  0x66,  0x65,  0x00,  0x23,  0x9d,  0x07,  
    0x9f,  0x08,  0x55,  0x55,  0x8d,  0xb5,  0x62,  0x8d,  
    0x9f,  0xfd,  0x1c,  0x72,  0xf3,  0x06,  0xd9,  0x93,  
    0xa0,  0x52,  0x00,  0x07,  0x00,  0x00,  0x00,  0x07,  
    0x00,  0x00,  0x00,  0x04,  0x63,  0x6d,  0x72,  0x37,  
    0xb1,  0x32,  0x8e,  0x91,  0x06,  0xb5,  0x53,  0xb8,  
    0x00,  0x93,  0xb2,  0x34,  0xb5,  0x61,  0x63,  0x8e,  
    0x8e,  0x8e,  0x8e,  0x92,  0x00,  0xc8,  0x61,  0x7e,  
    0x9f,  0x04,  0x77,  0x0e,  0x89,  0x00,  0x00,  0x66,  
    0x65,  0x00,  0x44,  0x3d,  0x04,  0x9f,  0x09,  0x28,  
    0xd6,  0x8d,  0x91,  0x1c,  0xf9,  0xea,  0xb2,  0x32,  
    0xb5,  0x61,  0x8e,  0x8e,  0x8e,  0x8e,  0x8e,  0x9f,  
    0x14,  0xcd,  0xd0,  0x8d,  0x91,  0x3e,  0x00,  0x00,  
    0xb2,  0x65,  0x6e,  0x64,  0x91,  0x03,  0x55,  0x55,  
    0x74,  0x65,  0x78,  0x74,  0x8e,  0x8e,  0x9f,  0x1e,  
    0x00,  0x00,  0x8d,  0x92,  0x00,  0xe8,  0x00,  0x00,  
    0x31,  0x8e,  0x8e,  0x8c,  0xf8,  0x00,  0x00,  0x00,  
    0x2a,  0x01,  0x83,  0x92,  0xc0,  0x1c,  0x3b,  0x00,  
    0x00,  0x00,  0x00,  0x03,  0xe8,  0x02,  0x79,  0x00,  
    0x00,  0x01,  0x97,  0x00,  0x00,  0x00,  0x0b,  0x00,  
    0x01,  0xf3,  0x0d,  0x21,  0x22,  0x2c,  0x9a,  0x00,  
    0x0a,  0x00,  0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  
    0x06,  0x63,  0x6d,  0x73,  0x79,  0x31,  0x30,  0xf3,  
    0x0a,  0x0b,  0xa0,  0x62,  0x3e,  0x00,  0x0a,  0x00,  
    0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  
    0x6d,  0x6d,  0x69,  0x31,  0x30,  0xf3,  0x07,  0x4b,  
    0xf1,  0x60,  0x79,  0x00,  0x0a,  0x00,  0x00,  0x00,  
    0x0a,  0x00,  0x00,  0x00,  0x05,  0x63,  0x6d,  0x72,  
    0x31,  0x30,  0xf3,  0x06,  0xd9,  0x93,  0xa0,  0x52,  
    0x00,  0x07,  0x00,  0x00,  0x00,  0x07,  0x00,  0x00,  
    0x00,  0x04,  0x63,  0x6d,  0x72,  0x37,  0xf9,  0x00,  
    0x00,  0x01,  0x7c,  0x02,  0xdf,  0xdf,  0xdf,  0xdf
};


// I have a generated file that contains the widths of all the fonts
// I am willing to use here.

#include "cmfont-widths.c"




// Read 1, 2 3 or 4 byte integers from the input file, with the shorter
// variants being either signed or unsigned. All are arranged in big-endian
// style, as defined by the DVI format.

unsigned char *string_input = NULL;

int mygetc(FILE *f)
{
   if (string_input != NULL) return *string_input++;
   else return getc(f);
}

int32_t u1(FILE *f)
{
    return mygetc(f) & 0xff;
}

int32_t u2(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    return ((c1 & 0xff) << 8) | (c2 & 0xff);
}

int32_t u3(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    int32_t c3 = mygetc(f);
    return ((c1 & 0xff) << 16) | ((c2 & 0xff) << 8) | (c3 & 0xff);
}

int32_t s1(FILE *f)
{
    return (int32_t)(int8_t)(mygetc(f));
}

int32_t s2(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    return (int32_t)(int16_t)(((c1 & 0xff) << 8) | (c2 & 0xff));
}

int32_t s3(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    int32_t c3 = mygetc(f);
    int32_t r = ((c1 & 0xff) << 16) | ((c2 & 0xff) << 8) | (c3 & 0xff);
    if ((r & 0x00800000) != 0) r |= 0xff000000;
    return (int32_t)r;
}

int32_t s4(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    int32_t c3 = mygetc(f);
    int32_t c4 = mygetc(f);
    return ((c1 & 0xff) << 24) | ((c2 & 0xff) << 16) |
           ((c3 & 0xff) << 8) | (c4 & 0xff);
}

int32_t h, v, w, x, y, z;

int32_t C[10], p;

int32_t checksum, size, designsize;
int arealen, namelen;
char fontname[256];

int font[256];

int32_t num, den, mag;

#define MAX_STACK 100

int32_t stack[6*MAX_STACK];
int stackp;

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

int findfont()
{
    printf("Define Font\n");
    printf("checksum = %.8x\n", checksum);
    printf("size = %d designsize = %d\n", size, designsize);
    printf("%d %d: %s\n", arealen, namelen, fontname);
    return 0;
}

void set_char(int32_t c)
{
    printf("Set (%f,%f) char %.2x (%c)\n",
        (double)h/(double)(1<<20), (double)v/(double)(1<<20), (int)c, (int)c);
}

void put_char(int32_t c)
{
    printf("Set (%f,%f) char %.2x (%c)\n",
        (double)h/(double)(1<<20), (double)v/(double)(1<<20), (int)c, (int)c);
}

void set_font(int n)
{
    printf("set font number %d\n");
}

// The code here is incomplete and not merged in properly yet!

int submain(int argc, char *argv[])
{
    FILE *f = NULL;
    string_input = NULL;
    if (argc > 1)
    {   f = fopen(argv[1], "rb");
        printf("Using data from file %s\n", argv[1]);
    }
    else
    {   string_input = &math_dvi[0];
        printf("Using built-in data\n");
    }
    int32_t a, b, c, i, k;
    for (;;)
    {   c = mygetc(f);
        if (c == EOF) break;
        c &= 0xff;
        if (c <= 127)
        {   set_char(c);
            continue;
        }
        else
        {   switch (c)
            {
        case 128:
                set_char(u1(f));
                continue;
        case 129:
                set_char(u2(f));
                continue;
        case 130:
                set_char(u3(f));
                continue;
        case 131:
                set_char(s4(f));
                continue;
        case 132:                           // set rule
                a = s4(f);
                b = s4(f);
                if (a > 0 && b >0)
                {   printf("set rule %d %d\n", (int)a, (int)b);
                    h += b;
                }
                continue;
        case 133:
                put_char(u1(f));
                continue;
        case 134:
                put_char(u2(f));
                continue;
        case 135:
                put_char(u3(f));
                continue;
        case 136:
                put_char(s4(f));
                continue;
        case 137:
                a = s4(f);
                b = s4(f);
                if (a > 0 && b >0)
                {   printf("put rule %d %d\n", (int)a, (int)b);
                }
                continue;
        case 138:
                continue;                      // no operation
        case 139:                           // beginning of page
                h = v = w = x = y = z = stackp = 0;
                for (i=0; i<10; i++)
                    C[i] = s4(f);
                p = s4(f);
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
                h += s1(f);
                continue;
        case 144:
                h += s2(f);
                continue;
        case 145:
                h += s3(f);
                continue;
        case 146:
                h += s4(f);
                continue;
        case 147:
                h += w;
                continue;
        case 148:
                h += (w = s1(f));
                continue;
        case 149:
                h += (w = s2(f));
                continue;
        case 150:
                h += (w = s3(f));
                continue;
        case 151:
                h += (w = s4(f));
                continue;
        case 152:
                h += x;
                continue;
        case 153:
                h += (x = s1(f));
                continue;
        case 154:
                h += (x = s2(f));
                continue;
        case 155:
                h += (x = s3(f));
                continue;
        case 156:
                h += (x = s4(f));
                continue;
        case 157:
                v += s1(f);
                continue;
        case 158:
                v += s2(f);
                continue;
        case 159:
                v += s3(f);
                continue;
        case 160:
                v += s4(f);
                continue;
        case 161:
                v += y;
                continue;
        case 162:
                v += (y = s1(f));
                continue;
        case 163:
                v += (y = s2(f));
                continue;
        case 164:
                v += (y = s4(f));
                continue;
        case 165:
                v += (y = s4(f));
                continue;
        case 166:
                v += z;
                continue;
        case 167:
                v += (z = s1(f));
                continue;
        case 168:
                v += (z = s2(f));
                continue;
        case 169:
                v += (z = s3(f));
                continue;
        case 170:
                v += (z = s4(f));
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
                set_font(c - 171);
                continue;
        case 235:
                set_font(u1(f));
                continue;
        case 236:
                set_font(u2(f));
                continue;
        case 237:
                set_font(u3(f));
                continue;
        case 238:
                set_font(s4(f));
                continue;
        case 239:
                k = u1(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 240:
                k = u2(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 241:
                k = u3(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 242:
                k = s4(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 243:                         // fnt_def1
                k = u1(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 244:
                k = u2(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 245:
                k = u3(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 246:
                k = s4(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 247:                          // pre
                i = u1(f);
                if (i != 2)
                {   printf("illegal DVI version %d\n", i);
                    break;
                }
                num = s4(f);
                den = s4(f);
                mag = s4(f);
                k = u1(f);
                for (i=0; i<k; i++) u1(f);
                printf("PRE: num=%d, den=%d, (%f) mag=%d\n",
                       num, den, (double)num/(double)den, mag);
                continue;
        case 248:                          // post
                s4(f); // ignore p;
                s4(f); // ignure num
                s4(f); // ignore den
                s4(f); // ignore mag
                s4(f); // height+depth of largest page
                s4(f); // width of largest page
                printf("Greatest stack depth = %d\n", u2(f));
                printf("Page count = %d\n", u2(f));
    // The postamble will have font definitions here as well.
                continue;
        case 249:                          // post_post
                s4(f);
                u1(f);
                if (u1(f) != 223) printf("Malformed DVI file\n");
                break;

        // 250-255 undefined
        default:
                printf("Unknown/undefined opcode %.2x\n", c);
                break;
            }
            break;
        }
    }
    printf("end of file\n");
}





bool dviApp::OnInit()
{
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;

    add_custom_fonts();

    char *dvifilename = "math.dvi";
    if (argc > 1) dvifilename = myargv[1];

    dviFrame *frame = new dviFrame(dvifilename);
    frame->Show(true);
    return true;
}

dviFrame::dviFrame(char *dvifilename)
       : wxFrame(NULL, wxID_ANY, "wxdvi")
{
    SetIcon(wxICON(fwin));

// I will read the DVI data once here.
    FILE *f = fopen(dvifilename, "rb");
    if (f == NULL)
    {   printf("File \"%s\" not found\n", dvifilename);
        exit(1);
    }
    fseek(f, (off_t)0, SEEK_END);
    off_t len = ftell(f);
    dvidata = (char *)malloc((size_t)len);
    fseek(f, (off_t)0, SEEK_SET);
    int i;
    for (i=0; i<len; i++) dvidata[i] = getc(f);
    fclose(f);
    ff = new wxFont();
    ff->SetNativeFontInfoUserDesc("cmr10");
    ff->SetPointSize(36);
    fontScaled = false;

// The size calculated here is the total size of the whole window,
// including title bar and borders...
    wxSize clientsize(1024, 768);
    wxSize winsize(ClientToWindowSize(clientsize));
    SetSize(winsize);
    SetMinSize(winsize);
    SetMaxSize(winsize);
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

void dviFrame::OnPaint(wxPaintEvent &event)
{
    wxPaintDC dc(this);
    wxColour c1(230, 200, 255);
    wxBrush b1(c1); 
    dc.SetBrush(b1);
    wxPen p1(c1);
    dc.SetPen(p1);
    dc.DrawRectangle(0, 0, 1024, 768);

    dc.SetFont(*ff);
    wxCoord w1, h1, d1, xl1;
    dc.GetTextExtent("X", &w1, &h1, &d1, &xl1);

#if 0
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
#endif
    for (int i=0; i<256; i+=32)
    {   for (int j=0; j<32; j++)
        {   wxString c = (wchar_t)(i+j);
            dc.DrawText(c, 32*j, 2*i+64  -h1+d1);
        }
    }
}


// end of wxdvi.cpp

