/* addresources.c                    Copyright (C) 2008 Codemist Ltd */


/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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

/* Signature: 48ea3701 04-Jun-2008 */


/*
 * The purpose of this code is to add a data resource to the end of an
 * executable file. This ought to work on either Windows or Linux or
 * Unix or BSD. It does not provide very great security, but uses some
 * rather simple guard words to check for at least basic sanity. It will
 * generally be legal to use this code repeatedly, and if a "resource"
 * is already present then it will get replaced. This facility relies on
 * the last few bytes of any normal executable file not matching the
 * rather crude signature that I use to identify a resource directory!
 *
 * Well the "update" option is not yet coded...
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void put8(FILE *f, long long int w)
{
    int i;
    for (i=0; i<8; i++)
    {   putc((int)(w & 0xff), f);
        w >>= 8;
    }
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    int n, w;
    long long int pos, len, len1;
    if (argc < 2)
    {   fprintf(stderr, "Usage: addresources executable files...\n");
        exit(1);
    }
    f1 = fopen(argv[1], "ab");  /* append in binary mode */
    if (f1 == NULL)
    {   fprintf(stderr, "Unable to access %s\n", argv[1]);
        exit(1);
    }
    w = fseek(f1, 0L, SEEK_END);
    if (w != 0)
    {   fprintf(stderr, "Seeking to end of %s failed with code %d\n", argv[1], w);
        exit(1);
    }
    pos = (long long int)ftell(f1);
    while ((pos & 7) != 0)  /* Pad to multiple of 8 bytes */
    {   putc(0, f1);
        pos++;
    }
/* Now copy the resource */
    f2 = fopen(argv[2], "rb");
    if (f2 == NULL)
    {   fprintf(stderr, "Unable to access %s\n", argv[2]);
        fclose(f1);
        exit(1);
    }
    len = 0;
    while ((n = getc(f2)) != EOF)
    {   putc(n, f1);
        len++;
    }
    len1 = len;
    while ((len1 & 7) != 0)  /* Pad to multiple of 8 bytes */
    {   putc(0, f1);
        len1++;
    }
/* Finally put a trailer record that notes where the boundary was */
    put8(f1, 0x1234567887654321LL);
    put8(f1, pos);
    put8(f1, len);
    put8(f1, 0x8765432112345678LL);
    if (ferror(f1) || ferror(f2))
    {   fprintf(stderr, "Copying failed\n");
        fclose(f1);
        fclose(f2);
        exit(1);
    }
    if (fclose(f1) != 0)
    {   fprintf(stderr, "Closing  %s failed\n", argv[0]);
        fclose(f2);
        exit(1);
    }
    fclose(f2);  /* Do not worry if this fails! */
/* Now as a pretty gross act of amazing oddness I will have a delay loop
 * here. This is because on one platform after ruiing this I have seen
 * "Clock skew" moans with the time stamp of one of the files just a
 * trifle in the future!
 */
    clock_t c1 = clock() + CLOCKS_PER_SEC/3;
    while (clock() < c1);
    return 0; 
}


/* end of addresources.c */
