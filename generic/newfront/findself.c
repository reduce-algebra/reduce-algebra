/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   (c) 2016 Arthur Norman
   ---------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
  
      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.
  
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "findself.h"

#define LONGEST_LEGAL_FILENAME 1000

int programNameDotCom = 0;
const char *programDir = ".";
char *programName = "redfront";
const char *fullProgramName = "./redfront";


#if defined WIN32

/*
 * I will use this version even when built using the Cygwin API
 * because I still have things like ".exe" to worry about.
 */

#include <windows.h>

static char this_executable[LONGEST_LEGAL_FILENAME];

int find_program_directory(const char *argv0)
{   char *w, *w1;
    char ww[LONGEST_LEGAL_FILENAME];
    int len, ndir, npgm;
// In older code I believed that I could rely on Windows giving me
// the full path of my executable in argv[0]. With bits of mingw/cygwin
// anywhere near me that may not be so, so I grab the information directly
// from the Windows APIs. Except that that turns out to be no good for
// a scheme I have that chains to an executable so it can pick which
// variant to use, so if argv0 looks like a fully rooted windows path
// I will use it!
//
    if (!(isalpha(argv0[0]) &&
          argv0[1] == ':' &&
          argv0[2] == '\\'))
    {   GetModuleFileName(NULL, this_executable, LONGEST_LEGAL_FILENAME-2);
        argv0 = this_executable;
    }
    strncpy(ww, argv0, sizeof(ww));
    ww[sizeof(ww)-1] = 0;
    w = ww;
//
// I turn every "\" into a "/". This make for better uniformity with other
// platforms.
//
    while (*w != 0)
    {   if (*w == '\\') *w = '/';
        w++;
    }
    programNameDotCom = 0;
    if (ww[0] == 0)      // should never happen - name is empty string!
    {   programDir = ".";
        programName = "redfront";  // nothing really known!
        fullProgramName = "./redfront.exe";
        return 0;
    }

    w = (char *)malloc(1+strlen(ww));
    if (w == NULL) return 5;           // 5 = malloc fails
    strcpy(w, ww);
    fullProgramName = w;
    len = strlen(ww);
//
// If the current program is called c:/aaa/xxx.exe, then the directory
// is just c:/aaa and the simplified program name is just xxx
//
    if (len > 4 &&
        w[len-4] == '.' &&
        ((tolower(w[len-3]) == 'e' &&
          tolower(w[len-2]) == 'x' &&
          tolower(w[len-1]) == 'e') ||
         (tolower(w[len-3]) == 'c' &&
          tolower(w[len-2]) == 'o' &&
          tolower(w[len-1]) == 'm')))
    {   programNameDotCom = (tolower(w[len-3]) == 'c');
        len -= 4;
        w[len] = 0;
    }
//
// I will strip any "win" prefix from the application name and also any
// "32" suffix.
//
    w1 = w;
    if (strlen(w) > 2)
    {   w += strlen(w) - 2;
        if (w[0] == '3' && w[1] == '2') w[0] = 0;
    }
    w = w1;
    while (*w != 0) w++;
    while (w != w1 && *w != '/'  && *w != '\\') w--;
    if (*w == '/' || *w == '\\') w++;
    if (strncmp(w, "win", 3) == 0)
    {   char *w2 = w + 3;
        while (*w2 != 0) *w++ = *w2++;
        *w = 0;
    }
    for (npgm=0; npgm<len; npgm++)
    {   int c = fullProgramName[len-npgm-1];
        if (c == '/') break;
    }
    ndir = len - npgm - 1;
    if (ndir < 0) programDir = ".";  // none really visible
    else
    {   if ((w = (char *)malloc(ndir+1)) == NULL) return 1;
        strncpy(w, fullProgramName, ndir);
        w[ndir] = 0;
        programDir = w;
    }
    if ((w = (char *)malloc(npgm+1)) == NULL) return 1;
    strncpy(w, fullProgramName + len - npgm, npgm);
    w[npgm] = 0;
    programName = w;
    return 0;
}

#else // WIN32

// Different systems put or do not put underscores in front of these
// names. My adaptation here should give me a chance to work whichever
// way round it goes.
//

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif // S_IFMT

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif // S_IFDIR

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif // S_IFREG

#ifndef S_ISLNK
# ifdef S_IFLNK
#  ifdef S_IFMT
#   define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#  endif
# endif
#endif // S_ISLNK

//
// I will not take any action at all to deal with UTF-8 or Unicode issues
// in filenames or paths. Indeed most of Linux and certainly most of my
// code will risk terribly confusion with various perfectly ordinary
// 7-bit characters such as blank (' ') within filenames, so the issue
// of international alphabets there is something I will not really fuss
// about yet.
//

int find_program_directory(const char *argv0)
{   char pgmname[LONGEST_LEGAL_FILENAME];
    const char *w;
    char *w1;
    int n, n1;
    memset(pgmname, 0, sizeof(pgmname));
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
    if (argv0 == NULL || argv0[0] == 0) // Information not there - return
    {   programDir = (const char *)"."; // some sort of default.
        programName = (const char *)"redfront";
        fullProgramName = (const char *)"./redfront";
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
    {   for (w=argv0; *w!=0 && *w!='/'; w++);   // seek a "/"
        if (*w == '/')      // treat as if relative to current dir
        {   // If the thing is actually written as "./abc/..." then
            // strip of the initial "./" here just to be tidy.
            if (argv0[0] == '.' && argv0[1] == '/') argv0 += 2;
            n = get_current_directory(pgmname, sizeof(pgmname));
            if (n < 0) return 1;    // fail! 1=current directory failure
            if (n + strlen(argv0) + 2 >= sizeof(pgmname) ||
                pgmname[0] == 0)
                return 2; // Current dir unavailable or full name too long
            else
            {   pgmname[n] = '/';
                strcpy(&pgmname[n+1], argv0);
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
            if (path != NULL)
            {   while (*path != 0)
                {   while (*path == ':') path++; // skip over ":"
                    n = 0;
                    while (*path != 0 && *path != ':')
                    {   pgmname[n++] = *path++;
                        if (n > (int)(sizeof(pgmname)-3-strlen(argv0)))
                            return 3; // fail! 3=$PATH element overlong
                    }
// Here I have separated off the next segment of my $PATH and put it at
// the start of pgmname. Observe that to avoid buffer overflow I
// exit abruptly if the entry on $PATH is itself too big for my buffer.
//
                    pgmname[n++] = '/';
                    strcpy(&pgmname[n], argv0);
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
                memset(temp, 0, sizeof(temp));
                strcpy(temp, pgmname);
                n = get_current_directory(pgmname, sizeof(pgmname));
                if (n < 0) return 1;    // fail! 1=current directory failure
                if ((n + strlen(temp) + 1) >= sizeof(pgmname)) return 9;
                pgmname[n++] = '/';
                strcpy(&pgmname[n], temp);
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
        memset(temp, 0, sizeof(temp));
        if (lstat(fullProgramName, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(fullProgramName,
                           temp, sizeof(temp)-1)) > 0)
        {   temp[n1] = 0;
            strcpy(pgmname, temp);
            fullProgramName = pgmname;
        }
    }
// Now fullProgramName is set up, but may refer to an array that
// is stack allocated. I need to make it proper!
//
    w1 = (char *)malloc(1+strlen(fullProgramName));
    if (w1 == NULL) return 5;           // 5 = malloc fails
    strcpy(w1, fullProgramName);
    fullProgramName = w1;
#ifdef __CYGWIN__
//
// Now if I built on raw cygwin I may have an unwanted ".com" or ".exe"
// suffix, so I will purge that! This code exists here because the raw
// cygwin build has a somewhat schitzo view as to whether it is a Windows
// or a Unix-like system. When I am using raw cygwin I am really not
// living in a Windows world.
//
    if (strlen(w1) > 4)
    {   char *w2 = w1 + strlen(w1) - 4;
        if (w2[0] == '.' &&
            ((tolower((unsigned char)w2[1]) == 'e' &&
              tolower((unsigned char)w2[2]) == 'x' &&
              tolower((unsigned char)w2[3]) == 'e') ||
             (tolower((unsigned char)w2[1]) == 'c' &&
              tolower((unsigned char)w2[2]) == 'o' &&
              tolower((unsigned char)w2[3]) == 'm'))) w2[0] = 0;
    }
    if (strlen(w1) > 2)
    {   char *w2 = w1 + strlen(w1) - 2;
        if (w2[0] == '3' && w2[1] == '2') w2[0] = 0;
    }
//
// If I am building a cygwin version I will remove any prefix
// "cygwin-", "cygwin64-" or "win" from the front of the name of the
// executable and also any "32" suffix.
//
    while (*w1 != 0) w1++;
    while (w1 != fullProgramName && *w1 != '/'  && *w1 != '\\') w1--;
    if (*w1 == '/' || *w1 == '\\') w1++;
    if (strncmp(w1, "cygwin-", 7) == 0)
    {   char *w2 = w1 + 7;
        while (*w2 != 0) *w1++ = *w2++;
        *w1 = 0;
    }
    else if (strncmp(w1, "cygwin64-", 9) == 0)
    {   char *w2 = w1 + 9;
        while (*w2 != 0) *w1++ = *w2++;
        *w1 = 0;
    }
    if (strncmp(w1, "win", 3) == 0)
    {   char *w2 = w1 + 3;
        while (*w2 != 0) *w1++ = *w2++;
        *w1 = 0;
    }
#endif // __CYGWIN__
// OK now I have the full name, which is of the form
//   abc/def/fgi/xyz
// and I need to split it at the final "/" (and by now I very fully expect
// there to be at least one "/".
//
    for (n=strlen(fullProgramName)-1; n>=0; n--)
        if (fullProgramName[n] == '/') break;
    if (n < 0) return 6;               // 6 = no "/" in full file path
    w1 = (char *)malloc(1+n);
    if (w1 == NULL) return 7;           // 7 = malloc fails
    strncpy(w1, fullProgramName, n);
    w1[n] = 0;
// Note that if the executable was "/foo" then programDir will end up as ""
// so that programDir + "/" + programName works out properly.
//
    programDir = w1;
    n1 = strlen(fullProgramName) - n;
    w1 = (char *)malloc(n1);
    if (w1 == NULL) return 8;           // 8 = malloc fails
    strncpy(w1, fullProgramName+n+1, n1-1);
    w1[n1-1] = 0;
    programName = w1;
    return 0;                          // whew!
}

#endif // WIN32

// end of findself.c
