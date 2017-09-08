// objtype.cpp                             Copyright (C) 2005-2017 Codemist    


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

//
// Decodes the type of an object file and generates a small source
// file that gives information about it and that can also be used to
// give information about a compiler command. Typical usage:
//   objtype foo.o - $CC $CFLAGS
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>

//
// In some cases I may end up passing a file-name of the form
//     /cygdrive/d/path.../leaf
// here. For things to behave I need to map that onto
//     d:/...path/leaf
//

static FILE *myfopen(const char *name, const char *mode)
{   char newname[256];
    if (strncmp(name, "/cygdrive/", 10) != 0)
        return fopen(name, mode);
    newname[0] = name[10];
    newname[1] = ':';
    strcpy(&newname[2], &name[11]);
    return fopen(newname, mode);
}

int main(int argc, const char *argv[])
{   FILE *f1, *f2;
    time_t t = time(NULL);
    unsigned char hdr[20];
    int sixtyFourBit = 0, byteOrder = 0, machine = 0;
    const char *s = NULL;
    int i;
    if (argc < 3)
    {   fprintf(stderr, "Usage: objtype xx.obj dest.c $CC $CFLAGS\n");
        return 1;
    }
    if (strcmp(argv[1], "-") == 0) f1 = stdin;
    else f1 = myfopen(argv[1], "rb");
    if (f1 == NULL)
    {   fprintf(stderr, "File \"%s\" not found\n", argv[1]);
        return 1;
    }
    if (strcmp(argv[2], "-") == 0) f2 = stdout;
    else f2 = myfopen(argv[2], "w");
    if (f2 == NULL)
    {   fprintf(stderr, "File \"%s\" can not be written to\n", argv[2]);
        fclose(f1);
        return 1;
    }
    if (fread(hdr, 20, 1, f1) != 1)
    {   fprintf(stderr, "Unable to read header from input file\n");
        fclose(f1);
        fclose(f2);
        return 1;
    }
    fprintf(f2, "/*\n * Created %s */\n\n", asctime(localtime(&t)));
    fprintf(f2, "\nconst char *linker_type = \"");
    if (hdr[0] == 0xfe &&
        hdr[1] == 0xed &&
        hdr[2] == 0xfa &&
        hdr[3] == 0xce) fprintf(f2, "mac-darwin");
    else if (hdr[0] == 0x7f &&
             hdr[1] == 'E' &&
             hdr[2] == 'L' &&
             hdr[3] == 'F')      // ELF-format file
    {   switch (hdr[4])
        {   case 1:                 // 32-bit ELF
                sixtyFourBit = 0;
                break;
            case 2:                 // 64-bit ELF
                sixtyFourBit = 1;
                break;
            default:
                goto invalidObjectFormat;
        }
        // hdr[5] is 1 for LSB, 2 for MSB data format
        if (hdr[5] == 0 || hdr[5] > 2) goto invalidObjectFormat;
        byteOrder = hdr[5] - 1;
        // hdr[6] had BETTER be 1, for "current ELT version"
        if (hdr[6] != 1) goto invalidObjectFormat;
        // hdr[7] & hdr[8] ought to be 0 to indicate "ordinary" ELF.
        // (hdr[7] can be 1 for HP Unix?)
        if (byteOrder == 0)
            machine = hdr[18] | (hdr[19]<<8);
        else machine = (hdr[18]<<8) | hdr[19];
//
// A few sample machine types...
//   386    3
//   ppc    20
//   ppc64  21
//   arm    40
//   x86_64 62
// I will detect and name those ones explicitly
//
        switch (machine)
        {   case 3: if (!sixtyFourBit && byteOrder == 0) s = "i386";
                break;
            case 20:if (!sixtyFourBit) s = "ppc";
                break;
            case 21:if (sixtyFourBit) s = "ppc64";
                break;
            case 62:if (sixtyFourBit) s = "x86_64";
                break;
        }
        if (s != NULL) fprintf(f2, "%s", s);
        else fprintf(f2, "ELF-%d-%d", 2*sixtyFourBit+byteOrder, machine);
    }
    else
    {
//
// If the file is not ELF I will suppose that it is COFF, and
// in that case the first two bytes identify a machine-type. Notable values
// are
//   386     0x14c
//   arm     0x1c0
//   x86_64  0x8664     note that these are given LSB
// This format is what is used by Windows.
//
        machine = hdr[0] + (hdr[1]<<8);
        switch (machine)
        {   case 0x14c: fprintf(f2, "win32");
                break;
            case 0x1c0: fprintf(f2, "arm-coff");
                break;
            case 0x8664:fprintf(f2, "win64");
                break;
            default:    // eg Itanium Windows could hit this case, I guess
                fprintf(f2, "COFF-%x", hdr[0] | (hdr[1]<<8));
                break;
        }
    }
    fprintf(f2, "\";\n\nconst char *compiler_command[] = {\n    \"%s\"",
           argv[3]);
    for (i=4; i<argc; i++)
    {   const char *a = argv[i];
//
// I filter out some options that I do not think I will need in the
// particular context of compiling the machine-genarated code that I
// will be using here...
//
        if (a[0]=='-' && a[1]=='I' && a[2]=='.') continue;
        if (strcmp(a, "-Wall") == 0) continue;
        if (strcmp(a, "-DHAVE_CONFIG_H") == 0) continue;
        fprintf(f2, ",\n    \"%s\"", a);
    }
    fprintf(f2, "\n};\n\n");
    fclose(f1);
    fclose(f2);
    return 0;
invalidObjectFormat:
    fprintf(stderr, "Object file appears to be corrupt\n");
    fclose(f1);
    fclose(f2);
    return 1;
}

// end of objtype.cpp
