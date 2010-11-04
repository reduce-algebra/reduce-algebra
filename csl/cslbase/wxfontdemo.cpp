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

/* Signature: 6974f426 04-Nov-2010 */



// The first few lines are essentially taken from the wxWidgets documentation
// and will be the same for almost all wxWidgets code.

#include "wx/wxprec.h"
 
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

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
#else
// I will expect that what is left here is X11.
// Again I need some headers so that I can establish private fonts
#include <X11/Xlib.h>
#endif
#endif

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

class fontFrame : public wxFrame
{
public:
    fontFrame(char *font, int size);

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnPaint(wxPaintEvent &event);

private:
    char *fontname;
    int fontsize;
    wxFont *ff;
    bool fontScaled;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fontFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  fontFrame::OnExit)
    EVT_MENU(wxID_ABOUT, fontFrame::OnAbout)
    EVT_PAINT(           fontFrame::OnPaint)
END_EVENT_TABLE()


IMPLEMENT_APP(fontApp)

// Pretty much everything so far has been uttery stylised and the contents
// are forced by the structure that wxWidgets requires!


#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

typedef struct localFonts
{
    const char *name;
    char *path;
} localFonts;

static localFonts fontNames[] =
{
    {"cmex10", NULL},
    {"cmmi10", NULL},
    {"cmr10",  NULL},
    {"cmsy10", NULL}
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

/* #define PRIVATE_FONT (FR_PRIVATE | FR_NOT_ENUM) */
#define PRIVATE_FONT FR_PRIVATE

static int fontNeeded = 0;

static int CALLBACK fontEnumProc(
    const LOGFONTA *lpelfe,     // logical-font data
    const TEXTMETRICA *lpntme,  // physical-font data
    DWORD FontType,             // type of font
    LPARAM lParam)              // application-defined data
{
    fontNeeded = 0;
    return 0;
}

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

const char *fwin_full_program_name = "./wxfwin.exe";
const char *programName            = "wxfwin.exe";
const char *programDir             = ".";

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
    TCHAR execname[LONGEST_LEGAL_FILENAME];
    GetModuleFileName(NULL, execname, LONGEST_LEGAL_FILENAME-2);
    {   TCHAR *p1 = execname;
        char *p2 = this_executable;
        while (*p1 != 0) *p2++ = *p1++;
        *p2 = 0;
    }
    argv0 = this_executable;
    program_name_dot_com = 0;
    if (argv0[0] == 0)      /* should never happen - name is empty string! */
    {   programDir = ".";
        programName = "wxfwin";  /* nothing really known! */
        fwin_full_program_name = ".\\wxfwin.exe";
        return 0;
    }

    fwin_full_program_name = argv0;
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
        programName = (const char *)"wxfwin";
        fwin_full_program_name = (const char *)"./wxfwin";
        return 0;
    }
/*
 * I will treat 3 cases here
 * (a)   /abc/def/ghi      fully rooted: already an absolute name;
 * (b)   abc/def/ghi       treat as ./abc/def/ghi;
 * (c)   ghi               scan $PATH to see where it may have come from.
 */
    else if (argv0[0] == '/') fwin_full_program_name = argv0;
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
                fwin_full_program_name = pgmname;
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
            fwin_full_program_name = pgmname;
        }
    }       
/*
 * Now if I have a program name I will try to see if it is a symbolic link
 * and if so I will follow it.
 */
    {   struct stat buf;
        char temp[LONGEST_LEGAL_FILENAME];
        if (lstat(fwin_full_program_name, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(fwin_full_program_name,
                           temp, sizeof(temp)-1)) > 0)
        {   temp[n1] = 0;
            strcpy(pgmname, temp);
            fwin_full_program_name = pgmname;
        }
    }
/* Now fwin_full_program_name is set up, but may refer to an array that
 * is stack allocated. I need to make it proper!
 */
    w = (char *)malloc(1+strlen(fwin_full_program_name));
    if (w == NULL) return 5;           /* 5 = malloc fails */
    strcpy(w, fwin_full_program_name);
    fwin_full_program_name = w;
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
    for (n=strlen(fwin_full_program_name)-1; n>=0; n--)
        if (fwin_full_program_name[n] == '/') break;
    if (n < 0) return 6;               /* 6 = no "/" in full file path */
    w = (char *)malloc(1+n);
    if (w == NULL) return 7;           /* 7 = malloc fails */
    strncpy(w, fwin_full_program_name, n);
    w[n] = 0;
/* Note that if the executable was "/foo" then programDir will end up as ""
 * so that programDir + "/" + programName works out properly.
 */
    programDir = w;
    n1 = strlen(fwin_full_program_name) - n;
    w = (char *)malloc(n1);
    if (w == NULL) return 8;           /* 8 = malloc fails */
    strncpy(w, fwin_full_program_name+n+1, n1-1);
    w[n1-1] = 0;
    programName = w;
    return 0;                          /* whew! */
}

#endif /* WIN32 */

#if 0
// unmerged code here

#ifdef WIN32
    HDC hDC = CreateCompatibleDC(NULL);
    LOGFONT lf;
// I check each of the fonts that this application wants to see if they
// are already installed. If they are then there is no merit in installing
// them for myself.
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
        printf("AddFontResource %s\n", fontNames[i].path);
        fflush(stdout);
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
    printf("About to list all fonts that are now available\n");
    fflush(stdout);
    EnumFontFamiliesEx(hDC, &lf, fontEnumProc1, 0, 0);
    printf("Listing complete\n");
    fflush(stdout);
    DeleteDC(hDC);

#else // WIN32

    int screen = 0;
    XftFontSet *fs = NULL;
    ftDraw = NULL;
    FcConfig *config = FcConfigCreate();
    dpy = (Display *)appl->getDisplay();
    screen = DefaultScreen(dpy);

// I will add exactly and only the fonts that I will be using.
    char fff[256];
    for (int i=0; i<4; i++)
    {   sprintf(fff,
            "%s/" toString(fontsdir) "/%s.pfb",
            programDir, fontNames[i].name);
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
    ftDraw = XftDrawCreate(dpy, w->canvas->id(), ftVisual, ftColorMap);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderBlack, &ftBlack);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderWhite, &ftWhite);
// I had identified the font that I wanted earlier so now I can open it
// by just using the information collected then.
    ftFont = XftFontOpen(dpy, screen,
                         XFT_FAMILY, XftTypeString, fontname,
                         XFT_SIZE, XftTypeDouble, 24.0,
                         NULL);
    XftFontSetDestroy(fs); // Now I am done with the list of fonts.

#endif // WIN32

    FXFontDesc fd;
    memset(&fd, 0, sizeof(fd));
    strcpy(fd.face, fontname);
    printf("Will try to view %s\n", fontname);
    fd.size = 240;               // NB size is in DECIPOINTS here
    fd.weight = 0;
    fd.slant = 0;
    fd.setwidth = 0;
    fd.encoding = FONTENCODING_DEFAULT;
    fd.flags = 0;
    ff = new FXFont(appl, fd);
    if (ff == NULL) printf("Font could not be created\n");
    else ff->create();

    application.create();
    return application.run();
}


#endif /* 0 */



bool fontApp::OnInit()
{
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;
    find_program_directory(myargv[0]);
    for (int i=0; i<argc; i++)
    {
        printf("Arg%d: %s\n", i, myargv[i]);
    }
    printf("\n%s\n%s\n%s\n", fwin_full_program_name, programName, programDir);


    char *font = "default";  // A default font name to ask for.
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

fontFrame::fontFrame(char *fname, int fsize)
       : wxFrame(NULL, wxID_ANY, "wxfontdemo")
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

// The size calculated here is the total size of the whole window,
// including title bar and borders...
    wxSize clientsize(32*32, 9*64);
    wxSize winsize(ClientToWindowSize(clientsize));
    SetSize(winsize);
    SetMinSize(winsize);
    SetMaxSize(winsize);
    Centre();
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

void fontFrame::OnPaint(wxPaintEvent &event)
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

