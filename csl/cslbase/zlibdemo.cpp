// zlibdemo.cpp                       Copyright (c) Codemist    , 1990-2016

// The file preserve.cpp can be preprocessed to generate zlibdemo.cpp,
// which is why the header line above is "strange".


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

// $Id$



// Free-standing demonstration of how I use zlib to compress image files.

#include <stdio.h>
#include <zlib.h>
#include <string.h>
#include <assert.h>


FILE *src, *dest;

static int Igetc()
{   return getc(src);
}

static bool Iputc(int ch)
{   return (putc(ch, dest) == EOF);
}

bool Iread(void *buff, size_t size)
// Reads (size) bytes into the indicated buffer.  Returns true if
// if fails to read the expected number of bytes.
{
    unsigned char *p = (unsigned char *)buff;
    while (size > 0)
    {   int c;
        if ((c = Igetc()) == EOF) return true;
        *p++ = c;
        size--;
    }
    return false;
}

bool Iwrite(const void *buff, size_t size)
//
// Writes (size) bytes from the given buffer, returning true if trouble.
//
{   const unsigned char *p = (const unsigned char *)buff;
    for (size_t i=0; i<size; i++)
        if (Iputc(p[i])) return true;
    return false;
}


// I will use zlib to compress image files. The code here arranges to
// buffer chunks of data for compressing or decompressing and adds
// CRC checking so that corrupted data can be noticed.

#define CHUNK ((size_t)16384)

static z_stream strm;
static unsigned char in[CHUNK];
static unsigned char out[CHUNK];

const char *Zreturncode(int rc)
{   switch (rc)
    {
    default:
        return "Unknown return code from zlib";
    case Z_OK:
        return "OK";
    case Z_STREAM_END:
        return "STREAM_END";
    case Z_NEED_DICT:
        return "NEED_DICT";
    case Z_ERRNO:
        return "ERRNO";
    case Z_STREAM_ERROR:
        return "STREAM_ERROR";
    case Z_DATA_ERROR:
        return "DATA_ERROR";
    case Z_MEM_ERROR:
        return "MEM_ERROR";
    case Z_BUF_ERROR:
        return "BUF_ERROR";
    case Z_VERSION_ERROR:
        return "VERSION_ERROR";
    }
}

bool def_init()
{   strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    int rc = deflateInit(&strm, Z_BEST_COMPRESSION);
    strm.avail_in = 0;
    return (rc != Z_OK);
}

// Zputc will return true if it FAILS.

bool Zputc(int ch)
{   in[strm.avail_in++] = ch;
    if (strm.avail_in != CHUNK) return false; // Just buffer the data
    strm.next_in = in;
    do
    {   strm.next_out = out;
        strm.avail_out = CHUNK;
// Here I know I have plenty of space in the output buffer, and furthermore
// I should have CHUNK of data in the input buffer. So progress should be
// possible and hence Z_BUF_ERROR should never be returned. Z_STREAM_END
// can only arise if Z_FINISH had been passed as the flush input to deflate,
// and Z_STREAM_ERROR is a genuine error...
        int rc = deflate(&strm, Z_NO_FLUSH);
        if (rc != Z_OK) return true;
        unsigned int n = CHUNK - strm.avail_out;
// Sometimes even though I have provided a whole chunk of input there
// will not (yet) be any output available. I do not want to emit a block
// of length zero both because that would be silly and because I use a
// block-length of zero to signify end of stream.
        if (n != 0)
        {
// Write the length of the block as 2 bytes.
            if (Iputc(n >> 8)) return true;
            if (Iputc(n)) return true;
// Calculate and write a CRC for this block.
            int crc_out = crc32(crc32(0, NULL, 0), out, n);
            if (Iputc(crc_out>>24)) return true;
            if (Iputc(crc_out>>16)) return true;
            if (Iputc(crc_out>>8)) return true;
            if (Iputc(crc_out)) return true;
            if (Iwrite(out, n)) return true;
        }
// I will keep going until I have used up all this input block.
    } while (strm.avail_in != 0);
    return false;
}

bool def_finish()
{   do
    {   strm.next_in = in;
        strm.avail_out = CHUNK;
        strm.next_out = out;
        int rc;
        if ((rc = deflate(&strm, Z_FINISH)) != Z_OK &&
             rc != Z_STREAM_END) return true;
        size_t n = CHUNK - strm.avail_out;
        if (n != 0)
        {   if (Iputc(n >> 8)) return true;
            if (Iputc(n)) return true;
            int crc_out = crc32(crc32(0, NULL, 0), out, n);
            if (Iputc(crc_out>>24)) return true;
            if (Iputc(crc_out>>16)) return true;
            if (Iputc(crc_out>>8)) return true;
            if (Iputc(crc_out)) return true;
            if (Iwrite(out, n)) return true;
        }
    } while (strm.avail_out == 0);
    int rc = deflateEnd(&strm);
    if (rc != Z_OK) return true;
    if (Iputc(0)) return true;  // Termination bytes
    if (Iputc(0)) return true;
    return false;
}

bool Zwrite(const void *b, size_t n)
{   const char *c = (const char *)b;
    while (n-- != 0) if (Zputc(*c++)) return true;
    return false;
}

static size_t n_out;
static unsigned char *p_out;
static int z_eof;

bool inf_init()
{   strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    n_out = 0;
    p_out = out;
    z_eof = 0;
    int rc = inflateInit(&strm);
    strm.avail_in = 0;
    strm.next_in = in;
    return (rc != Z_OK);
}

// Although the value of EOF on *many* systems will be -1, the standards do
// not guarantee that. So for Zgetc() I will arrange that I explictly return
// (-1) for end-of-file and error conditions, so that I can rely on that.

int Zgetc()
{   for (;;)
    {   if (n_out != 0)    // Use byte from the current decompressed chunk.
        {   n_out--;
            return *p_out++;
        }
        if (z_eof != 0) return (z_eof = -1);
// Here the zlib output buffer is empty. If the input buffer contains anything
// at all I will just call inflate() again. 
// I do not believe that inflate can ever leave input untouched in its input
// buffer while there is space in the output buffer.
        if (strm.avail_in == 0)
        {
// The compressed material is arrabnged in blocks. Each block starts with
// a 2-byte length field.
            int ch, n = Igetc();
// If I get an end of file (or error) report when trying to read part of the
// length information then the stream is corrupted, and I just return and end
// of file marker. When I do so I set z_eof so that further calls to Zgetc()
// will also return (-1).
            if (n == EOF) return (z_eof = -1);
            ch = Igetc();
            if (ch == EOF) return (z_eof = -1);
            n = (n << 8) | ch;
// If the block-length is 0 we have reached the end of the stream. Because
// I am trying to read data here I must have already emitted all the bytes
// that could be generated from everything that had been seen earlier, so
// I can return an end-of-file marker.
            if (n == 0) return (z_eof = -1);
// Following the 2-byte length there is a 4-byte CRC. Again I watch carefully
// so that an EOF while trying to read this will be reported back to the
// caller (just as and end of file condition).
            int crc_needed = Igetc();
            if (crc_needed == EOF) return (z_eof = -1);
            for (int i=0; i<3; i++)
            {   int w = Igetc();
                if (w == EOF) return (z_eof = -1);
                crc_needed = (crc_needed << 8) | w;
            }
// Now I read the number of bytes I have been told to expect. If I am not
// able to read thet many it is an error.
            if (Iread(in, n)) return (z_eof = -1);
// Compute a CRC on the block just read and complain if it is not as
// expected.
            int crc = crc32(crc32(0, NULL, 0), in, n);
            if (crc != crc_needed) return (z_eof = -1);
// Set the zlib input buffer information so that this new block can be
// processed. There will be at least 1 new byte of data!
            strm.next_in = in;
            strm.avail_in = n;
        }
        strm.next_out = out;
        strm.avail_out = CHUNK;
// Inflate whatever data is in the input buffer. I require that this EITHER
// removes at least one byte from the input buffer OR puts at least one
// byte in the output buffer, or that it return Z_STREAM_END. If it grabs
// input then it will eventually empty the input buffer so more will be read.
// Whenever it generates output that is offered to the caller.
        int rc = inflate(&strm, Z_SYNC_FLUSH);
// I check the return code and exit if something has gone wrong.
        if (rc != Z_OK &&
            rc != Z_STREAM_END &&
            rc != Z_BUF_ERROR) return (z_eof = -1);
        if (rc == Z_STREAM_END) z_eof = (-1);
        p_out = out;
        n_out = CHUNK - strm.avail_out;
    }
}

bool Zread(void *b, size_t n)
{   char *c = (char *)b;
    while (n-- != 0)
    {   int n = Zgetc();
        if (n == -1) return true;
        *c++ = n;
    }
    return false;
}

bool inf_finish()
{   return (inflateEnd(&strm) != Z_OK);
}


// compress or decompress from src to dest

int main(int argc, char **argv)
{
// Check argument number and format. I expect either
//      zlibdemo src compressed-dest
// OR   zlibdemo -d compressed-src dest
//
    if (argc < 3 ||
        (argc == 3 && strcmp(argv[1] , "-d") == 0) ||
        (argc == 4 && strcmp(argv[1], "-d") != 0) ||
        argc > 4)
    {   fputs("Usage: zlibdemo [-d] source dest\n", stderr);
        return 1;
    }

    if (argc == 3)
    {   src = strcmp(argv[1], "-") == 0 ? stdin : fopen(argv[1], "r");
        assert(src != NULL);
        dest = fopen(argv[2], "wb");
        assert(dest != NULL);
        def_init();
        int ch;
        while ((ch = getc(src)) != EOF) Zputc(ch);
        def_finish();
        fclose(src);
        fclose(dest);
        return 0;
     }

    else
    {   src = fopen(argv[2], "rb");
        assert(src != NULL);
        dest = strcmp(argv[3], "-") == 0 ? stdout : fopen(argv[3], "w");
        assert(dest != NULL);
        inf_init();
        int ch;
        while ((ch = Zgetc()) != -1) putc(ch, dest);
        inf_finish();
        fclose(src);
        fclose(dest);
        return 0;
    }
}

// end of zlibdemo.cpp



// end of file preserve.cpp
