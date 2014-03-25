// addresources.c                          Copyright (C) 2014 Codemist Ltd


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

// $Id$


//
// The purpose of this code is to add a data resource to the end of an
// executable file. It just sticks the resource on the end of the
// file with a trailer that is a pair of signature words with the
// address and length of the data squished between. It can cope with
// up to 16 resources.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

// This is a utility program only used on Windows and only used by
// system builders, so I will maybe not be as conservative in its
// construction as I would be with code intendes for everybody. I will
// requite that zlib is available.

#include <zlib.h>


//
// The compression parts of this code are modelled on.......
//
// zpipe.c: example of proper use of zlib's inflate() and deflate()
// Not copyrighted -- provided to the public domain
// Version 1.4  11 December 2005  Mark Adler
//

#define CHUNK 0x40000

//
// Compress from file source to file dest until EOF on source.
// def() returns Z_OK on success, Z_MEM_ERROR if memory could not be
// allocated for processing, Z_STREAM_ERROR if an invalid compression
// level is supplied, Z_VERSION_ERROR if the version of zlib.h and the
// version of the library linked do not match, or Z_ERRNO if there is
// an error reading or writing the files.
//

int def(FILE *source, FILE *dest, int level)
{
    int ret, flush;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];  // uses 512K of buffer space...
    unsigned char out[CHUNK]; // ... between these two.

    // allocate deflate state
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, level);
    if (ret != Z_OK) return ret;

    // compress until end of file
    do
    {   strm.avail_in = fread(in, 1, CHUNK, source);
        if (ferror(source))
        {   (void)deflateEnd(&strm);
            return Z_ERRNO;
        }
        flush = feof(source) ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = in;

        // run deflate() on input until output buffer not full, finish
        // compression if all of source has been read in
        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = deflate(&strm, flush);    // no bad return value
            assert(ret != Z_STREAM_ERROR);  // state not clobbered
            have = CHUNK - strm.avail_out;
            if (fwrite(out, 1, have, dest) != have || ferror(dest))
            {   (void)deflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);
        assert(strm.avail_in == 0);     // all input will be used

        // done when last data in file processed
    } while (flush != Z_FINISH);
    assert(ret == Z_STREAM_END);        // stream will be complete

    // clean up and return
    (void)deflateEnd(&strm);
    return Z_OK;
}

static void put8(FILE *f, int64_t w)
{
    int i;
    for (i=0; i<8; i++)
    {   putc((int)(w & 0xff), f);
        w >>= 8;
    }
}

#define MAX_RESOURCE_COUNT 16

int64_t resourcebase[MAX_RESOURCE_COUNT];
int64_t resourcesize[MAX_RESOURCE_COUNT];
int resourcecount = 0;

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    int i, n, w;
    int64_t pos, pos1, pos2;
    if (argc < 2)
    {   fprintf(stderr, "Usage: addresources executable [extrafiles...]\n");
        exit(1);
    }
    f1 = fopen(argv[1], "ab");  // append in binary mode
    if (f1 == NULL)
    {   fprintf(stderr, "Unable to access %s\n", argv[1]);
        exit(1);
    }
    w = fseek(f1, 0L, SEEK_END);
    if (w != 0)
    {   fprintf(stderr, "Seeking to end of %s failed with code %d\n", argv[1], w);
        exit(1);
    }
    pos = (int64_t)ftell(f1);
    while ((pos & 7) != 0)  // Pad to multiple of 8 bytes
    {   putc(0, f1);
        pos++;
    }
    resourcecount = 0;
// Now copy the resources
    for (i=2; i<argc; i++)
    {   f2 = fopen(argv[i], "rb");
        if (f2 == NULL)
        {   fprintf(stderr, "Unable to access %s\n", argv[i]);
            fclose(f1);
            exit(1);
        }
        def(f2, f1, 9);
        pos1 = (int64_t)ftell(f1);
        pos2 = pos1;
        while ((pos2 & 7) != 0)  // Pad to multiple of 8 bytes
        {   putc(0, f1);
            pos2++;
        }
        resourcebase[resourcecount] = pos;
        resourcesize[resourcecount] = ftell(f2);
        printf("resource %d at %" PRIx64 " length %" PRId64
               " compressed to %" PRId64 "\n",
            i-2, pos, resourcesize[resourcecount], pos1-pos);
        pos = pos2;
        resourcecount++;
        fclose(f2);
    } 
// Finally put a trailer record with an index
    put8(f1, 0x1234567887654321LL);
    for (i=0; i<resourcecount; i++)
    {   put8(f1, resourcebase[i]);
        put8(f1, resourcesize[i]);
    }
    put8(f1, 0x8765432112345678LL);
    printf("Final length of file = %" PRId64 "\n", (int64_t)ftell(f1));
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
    return 0; 
}

// end of addresources.c
