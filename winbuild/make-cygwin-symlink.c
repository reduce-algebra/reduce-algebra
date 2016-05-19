/*
 * make-cygwin-symlink.c                     Copyright (C) 2014-16 Codemist
 *
 * This program is intended to allow one to find a cygwin installation
 * on the current machine. It makes fairly strong assumptions about where
 * one might be!
 *
 * Usage:
 *      make-cygwin-symlink d:/installed/somewhere/foo.exe cygfoo
 * This is like
 *   ln -s /cygdrive/d/installed/somewhere.foo.exe /usr/local/bin/cygfoo
 *
 *      make-cygwin-symlink WINPATH1 WINPATH2 name-for-cygwin
 * This is much the same but it links to WINPATH1 for any 32-bit installation
 * of cygwin and WINPATH2 for any 64-bit one.
 */

/* $Id: findcygwin.c 2277 2014-01-06 10:33:50Z arthurcnorman $ */


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

#include <stdio.h>
#include <windows.h>

const char *cygname, *winname, *winname64;

int processFile(char *path)
{
    FILE *f;
    const char *p, *wname;
    DWORD a = GetFileAttributes(path);
    if (a == INVALID_FILE_ATTRIBUTES ||
        (a & (FILE_ATTRIBUTE_DEVICE | FILE_ATTRIBUTE_DIRECTORY |
              FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE)) != 0) return 0;
    printf("%s seems plausible\n", path);
/*
 * I will look for a "bash.exe" adjacant to cygwin1.dll
 */
    strcpy(path+strlen(path)-strlen("cygwin1.dll"), "bash.exe");
    printf("Now check %s\n", path);
    a = GetFileAttributes(path);
    if (a == INVALID_FILE_ATTRIBUTES ||
        (a & (FILE_ATTRIBUTE_DEVICE | FILE_ATTRIBUTE_DIRECTORY |
              FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE)) != 0) return 0;
    printf("%s seems plausible\n", path);
    if (GetBinaryType(path, &a) == 0) return 0;
    printf("Type = %d = %x\n", a, a);
    switch (a)
    {
default:  /* Not a useful type */
        return 0;
case SCS_32BIT_BINARY:
        printf("32-bit cygwin location identified\n");
        wname = winname;
        break;
case SCS_64BIT_BINARY:
        printf("64-bit cygwin location identified\n");
        wname = winname64;
        break;
    }
    sprintf(path+strlen(path)-strlen("/bin/bash.exe"),
            "/usr/local/bin/%s", cygname);
    DeleteFile(path); /* delete before trying to create it */
    f = fopen(path, "wb");
    if (f == NULL)
    {   printf("Unable to write to %s\n", path);
        return 1;
    }
    fwrite("!<symlink>", 1, 10, f);
    putc(0xff, f);
    putc(0xfe, f);
/*
 * Here I have to do two things. One is to convert the Windows name to
 * on in cygwin format.
 */
    for (p = "/cygdrive/"; *p!=0; p++)
    {   putc(*p, f);
        putc(0, f);
    }
    p = wname;   // Expected to be of form "x:\..."
    putc(*p++, f);
    putc(0, f);
    p++;           // Skip the ":"
    while(*p!=0)
    {   int c = *p++;
        if (c == '\\') c = '/';
        putc(c, f);
        putc(0, f);
    }
    putc(0, f);
    putc(0, f);
    fclose(f);
    SetFileAttributes(path, FILE_ATTRIBUTE_SYSTEM);
    return 0;
}

int processDrive(const char *drive)
{
    WIN32_FIND_DATA data;
    HANDLE h;
    char name[256];
    printf("Look in %s\n", drive);
    if (strlen(drive) > sizeof(name)-16) return 1;
/*
 * It seems that I can only put wildcards in the final component of
 * the path given to FindFirstFile, so the pattern I sort of wanted to
 * use, viz "x:\cyg*\bin\cygwin1.dll" is not acceptable. I need to find
 * directories that match "x:\cyg*" and then check within them as a
 * separtate step.
 */
    sprintf(name, "%scyg*", drive);
    printf("Pattern is %s\n", name);
    memset(&data, 0, sizeof(data));
    h = FindFirstFile(name, &data);
    if (h != INVALID_HANDLE_VALUE)
    {   for (;;)
        {   if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
            {   char path[256];
                sprintf(path, "%s%s\\bin\\cygwin1.dll", drive, data.cFileName);
                if (processFile(path)) return 1;
            }
            if (!FindNextFile(h, &data)) break;
        }
        FindClose(h);
    }
    return 0;
}

int processVolume(const char *volumeName)
{
    DWORD len = (DWORD)strlen(volumeName);
    char pathNames[4096], *p;
    if (strncmp(volumeName, "\\\\?\\", 4) != 0 ||
        volumeName[len-1] != '\\')
    {   fprintf(stderr, "Invalid volume name (%s) returned\n", volumeName);
        return 1;
    }
/*
 * A single volume may potentially have several paths mapped onto it, and
 * GetVolumePathNamesForVolumeName recovers all of them, concatenated as
 * one long string terminated with a double zero. The call here could fail
 * if the total length of all such paths exceeded the size of the buffer
 * I provide. I think that I would view that as a seriously unusual
 * situation, and I am not going to worry about it.
 */
    if (!GetVolumePathNamesForVolumeName(
        volumeName, pathNames, (DWORD)sizeof(pathNames), &len))
    {   printf("Unable to get volume path names\n");
        return 1;
    }

    for (p = pathNames; *p != 0; p += strlen(p)+1)
    {   if (processDrive(p)) return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char volumeName[100];
    HANDLE v;
#if 0
    {   int i;
        FILE *o = fopen("c:\\symlink.log", "w");
        fprintf(o, "make-cygwin-symlink %d\n", argc);
        for (i=0; i<argc; i++) fprintf(o, "%d) \"%s\"\n", i, argv[i]);
        fclose(o);
    }
#endif
    if ((argc != 3 && argc != 4) || strncmp(argv[1], "--h", 3) == 0)
    {   printf("[%d] Usage:\n", argc);
        printf("     make-cygwin-symlink winname cygname\n");
        printf("or   make-cygwin-symlink winname winname64 cygname\n");
        printf("e.g. make-cygwin-symlink \"c:/Program Files/reduce/csl-reduce/reduce.exe\" redcsl\n");
        printf("This establishes cygwin soft links in the cygwin /usr/local/bin\n");
        printf("directory to point to the specified executable\n");
        printf("Rather like\n");
        printf("\"ln -s '/cygdrive/c/Program Files/reduce/csl-reduce/reduce.exe' \\\n");
        printf("       /usr/local/bin/redcsl\"\n");
        printf("but running as a native windows task not a cygwin one. It\n");
        printf("identifes all the cygwin installations that it can find in\n");
        printf("directories whose name is of the form \"x:\\cyg*\"\n");
        return 0;
    }
/*
 * Note that the Windows name should be a fully rooted name starting with
 * drive information and it should explicitly include the ".exe" suffix
 * that the executable has: eg "C:\path\subpath\executable.exe" while the
 * cygname should be a plain word with no suffix and no embedded slashes
 * or other unusual characters.
 */
    switch (argc)
    {
case 3:
    winname = argv[1];
    winname64 = argv[1];
    cygname = argv[2];
    break;
case 4:
    winname = argv[1];
    winname64 = argv[2];
    cygname = argv[3];
    break;
    }

    v = FindFirstVolume(volumeName, (DWORD)sizeof(volumeName));
    if (v == INVALID_HANDLE_VALUE)
    {   fprintf(stderr, "No volumes found\n");
        return 1;
    }
    for (;;)
    {   if (processVolume(volumeName)) return 1;
        if (!FindNextVolume(v, volumeName, (DWORD)sizeof(volumeName)))
        {   if (GetLastError() == ERROR_NO_MORE_FILES) return 0;
            fprintf(stderr, "FindNextVolume failed\n");
            return 1;
        }
    }
}

/* end of make-cygwin-symlink.c */

