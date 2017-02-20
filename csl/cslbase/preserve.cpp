#ifndef ZLIB_DEMO
// preserve.cpp                           Copyright (C) Codemist, 1990-2017
#else
// zlibdemo.cpp                           Copyright (C) Codemist, 1990-2017
#endif

// The file preserve.cpp can be preprocessed to generate zlibdemo.cpp,
// which is why the header line above is "strange".


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


#ifndef ZLIB_DEMO

// If this file is compiled with ZLIB_DEMO defined it will be a program that
// can be used as either
//     zlibdemo source dest
// to compress the source file and create the destination one, or
//     slibdemo -d source dest
// to uncompress from source to dest.
//
// I will use "unifdef" to create the separate file zlibdemo.cpp from this one
// but this is the master version...


#include "headers.h"

#include "version.h"

//
// The following extra includes should probably be hidden away elsewere
// and/or abtracted away a bit. They are here so I can check if a file-name
// refers to a directory.
//

#include <sys/stat.h>
#include <sys/types.h>
#include <zlib.h>

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

#ifdef BUILTIN_IMAGE

//
// The following included file should define
//    const unsigned char *reduce_image = "....";
//    #define REDUCE_IMAGE_SIZE nnn
// where the data is that which might otherwise have lived in a file.
//

#include "image.cpp"
#endif

#else // ZLIB_DEMO

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

#endif

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

#ifdef ZLIB_DEMO

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


#else // ZLIB_DEMO

//
// These routines pack multiple binary files into one big one.  The
// good effect is that I expect fseek to be faster than fopen, and as
// a result accessing fasl files will be faster.  The bad news is that
// when I update files I may need to compact them, and doing so will
// be very tedious.  In this model I do not permit arbitrary interleaving
// of read and write operations.
//

static void set_dirused(directory_header *h, int v)
{   h->dirused = (unsigned char)(v & 0xff);
    h->dirext = (unsigned char)((h->dirext & 0xf0) + ((v>>8) & 0x0f));
}

static directory empty_directory =
{
//
// This statically allocated "directory" exists to use as a fall-back if
// it proves impossible to allocate space for a genuine directory record.
// Thus it only comes into play in situations when I am in the process
// of failing fairly drastically!
//
    {   'C', MIDDLE_INITIAL, 'L', IMAGE_FORMAT_VERSION,
        0, 0, 0, 0,
        {0, 0, 0, 0}
    },
    NULL,
    NULL,
    "EmptyFile",
    {{"\nEmpty       ** *** not dated *** **"}}
};

//
// In a way that may look clumsy I store file offsets and lengths as
// sequences of three or four characters.  The object of this
// explicit control over memory layout is so that directories produced by
// this code have a layout that is not sensitive to the byte-order used
// by the computer involved.  I also put a few newline characters into
// my directory structure so that if one uses an ordinary text editor to
// inspect an image file the set of modules and their datestamps should
// be easily visible.
//

static int32_t bits32(char *v)
{   int32_t r = v[3] & 0xff;
    r = (r << 8) | (v[2] & 0xff);
    r = (r << 8) | (v[1] & 0xff);
    return (r << 8) | (v[0] & 0xff);
}

static int32_t bits24(char *v)
{   int32_t r = v[2] & 0xff;
    r = (r << 8) | (v[1] & 0xff);
    return (r << 8) | (v[0] & 0xff);
}

static void setbits32(char *v, int32_t r)
{   *v++ = (char)r;
    *v++ = (char)(r >> 8);
    *v++ = (char)(r >> 16);
    *v   = (char)(r >> 24);
}

static void setbits24(char *v, int32_t r)
{   *v++ = (char)r;
    *v++ = (char)(r >> 8);
    *v   = (char)(r >> 16);
}

static directory *current_input_directory;   // not used!
static int nativedir = 0;
static directory_entry *current_output_entry;
static directory *current_output_directory = NULL;
static bool any_output_request;
static char would_be_output_directory[DIRNAME_LENGTH];

#define I_INACTIVE 0
#define I_READING  1
#define I_WRITING  2

static int Istatus = I_INACTIVE;

#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
FILE *binary_read_file;
#endif
FILE *binary_write_file;
static long int read_bytes_remaining, write_bytes_written;
directory *fasl_files[MAX_FASL_PATHS];

static directory *make_empty_directory(const char *name)
//
// The sole purpose of this empty directory is to carry with it the
// name of the file that I had tried to open.
//
{   directory *d;
    d = (directory *) malloc(sizeof(directory) - sizeof(directory_entry));
    if (d == NULL) return &empty_directory;
    d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
    d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    d->h.dirsize = 0;
    d->h.dirused = 0;
    d->h.dirext = 0;
    d->h.updated = 0;   // NB read-only
    d->f = NULL;
    d->full_filename = NULL;
    strncpy(d->filename, name, DIRNAME_LENGTH);
    d->filename[DIRNAME_LENGTH-1] = 0;
    memset(d->h.eof, 0, 4);
    return d;
}

static directory *make_pending_directory(const char *name, int pds)
{   directory *d;
    int n = sizeof(directory) + (DIRECTORY_SIZE-1)*sizeof(directory_entry);
    int l = strlen(name) + 1 -
            DIRNAME_LENGTH -
            DIRECTORY_SIZE*sizeof(directory_entry);
//
// Here I extend the directory header with enough extra bytes to hold the
// full name of the file... Once the file has been opened the (potential)
// extra data becomes unnecessary. However with room for DIRECTORY_SIZE
// entries already it would seem bizarre if the path-name ever actually
// overflowed here.
//
    if (l > 0) n += l;
    d = (directory *)malloc(n);
    if (d == NULL) return &empty_directory;
    d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
    d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    d->h.dirsize = DIRECTORY_SIZE & 0xff;
    d->h.dirused = 0;
    d->h.dirext = (DIRECTORY_SIZE >> 4) & 0xf0;
    d->h.updated = D_PENDING | D_WRITE_OK;
    // Well I HOPE that writing will be OK
    d->f = NULL;
    strcpy(d->filename, name);  // guaranteed enough space here
    if (pds) d->full_filename = NULL;
    else
    {   char *s = (char *)malloc(strlen(name)+1);
// Ought to check for NULL here
        strcpy(s, name);
        d->full_filename = s;
    }
    memset(d->h.eof, 0, 4);
    return d;
}

static directory *make_native_directory(const char *shortname, const char *fullname, int ro)
{   directory *d;
    d = (directory *)malloc(sizeof(directory) - sizeof(directory_entry));
    if (d == NULL) return &empty_directory;
    d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
    d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    d->h.dirsize = DIRECTORY_SIZE & 0xff;
    d->h.dirused = 0;
    d->h.dirext = (DIRECTORY_SIZE >> 4) & 0xf0;
    d->h.updated = ro ? 0 : D_WRITE_OK;
    d->f = NULL;
    strncpy(d->filename, shortname, sizeof(d->filename));
    d->filename[DIRNAME_LENGTH-1] = 0;
    {   char *s = (char *)malloc(strlen(fullname)+1);
// Ought to check for NULL here
        strcpy(s, fullname);
        d->full_filename = s;
    }
    memset(d->h.eof, 0, 4);
    return d;
}

static void clear_entry(directory_entry *d)
{   d->D_newline = NEWLINE_CHAR;
    memset(&d->D_name, ' ', name_size);
    memcpy(&d->D_name, "<Unused>", 8);
    memset(&d->D_date, ' ', date_size);
    (&d->D_date)[0] = '-';
    memset(&d->D_position, 0, 4);
    memset(&d->D_size, 0, 3);
}

static bool version_moan(int v)
{
    if ((v & 0x7f) == IMAGE_FORMAT_VERSION) return false;
// This printing of a newline here lookes really odd to me!
//  term_printf("\n");
    return true;
}

#ifdef BUILTIN_IMAGE
static int builtinread(void *b, size_t s, size_t n)
{   size_t i;
    unsigned char *w = (unsigned char *)b;
    for (i=0; i<n*s; i++)
        *w++ = *binary_read_filep++;
    return n;
}

#endif

directory *open_pds(const char *name, int mode)
//
// Given a file-name, open the associated file, make space for
// a directory and return same. This now has to detect if the file-name
// should refer to a directory rather than a composite file. This case
// arises if the file that is named already exists and is a directory OR
// if it does not exist and its name it specified with a trailing "/".
// The mode is one of PDS_INPUT, PDS_OUTPUT or PDS_PENDING where the last
// sets up for an output directory that must be created on first use.
// Also if BUILTING_DIRECTORY is true then only one image file can be used
// and that has to be the built-in one!
//
{   char expanded[LONGEST_LEGAL_FILENAME];
    directory hdr, *d;
    bool write_OK = false, fileExists, nameDir, fileDir;
    struct stat buf;
    FILE *f;
    int l, i, n;
    memset(expanded, 0, sizeof(expanded));
    l = strlen(name);
    nameDir = (name[l-1] == '/') || (name[l-1] == '\\');
    f = NULL;
    process_file_name(expanded, name, l);
    i = strlen(expanded) - 1;
    if (expanded[i] == '/' ||
        expanded[i] == '\\') expanded[i] = 0; // Trim any final "/"
    fileExists = fileDir = false;
#ifdef BUILTIN_IMAGE
    fileExists = true;
    binary_read_filep = reduce_image;
#else
    if (stat(expanded, &buf) != -1)
    {   fileExists = true;
        if ((buf.st_mode & S_IFMT) == S_IFDIR) fileDir = true;
    }
    if (nameDir && fileExists && !fileDir)
        return make_empty_directory(expanded);
    if (mode != PDS_INPUT)
    {   any_output_request = true;
        strncpy(would_be_output_directory, expanded, DIRNAME_LENGTH-1);
        if (fileExists && fileDir)
            return make_native_directory(name, expanded, 0);
        else if (nameDir && mode == PDS_PENDING)
            return make_pending_directory(expanded, 0);
        else if (nameDir)
        {   Cmkdir(expanded);
            return make_native_directory(name, expanded, 0);
        }
        else if (fileExists) f = fopen(expanded, "r+b");
        else f = NULL;
        if (f != NULL) write_OK = true;
        else if (mode == PDS_PENDING)
        {   f = fopen(expanded, "rb");
            if (f == NULL) return make_pending_directory(expanded, !nameDir);
        }
        else
        {   f = fopen(expanded, "w+b");
            if (f != NULL) write_OK = true;
        }
    }
//
// If I wanted the file for input or if I tried it for output and failed
// then I open for input.
//
    if (f == NULL)
    {   if (!fileExists) return make_empty_directory(expanded);
        if (fileDir) return make_native_directory(name, expanded, 1);
        f = fopen(expanded, "rb");
    }
//
// If the file does not exist I will just hand back a directory that shows
// no files in it.  This seems as easy a thing to do at this stage as I can
// think of.  Maybe I should warn the user?
//
    if (f == NULL) return make_empty_directory(expanded);
    fseek(f, 0, SEEK_SET);     // Ensure I am at start of the file
#endif
    hdr.h.C = hdr.h.S = hdr.h.L = 0;
#ifdef BUILTIN_IMAGE
    if (builtinread(&hdr.h, sizeof(directory_header), 1) != 1 ||
#else
    if (fread(&hdr.h, sizeof(directory_header), 1, f) != 1 ||
#endif
        hdr.h.C != 'C' ||
        hdr.h.S != MIDDLE_INITIAL ||
        hdr.h.L != 'L' ||
//
// Image format versions are somewhat delicate things. I will not change
// this format often or lightly and the tests I make will then be set up to
// cope with updates from the immediately previous version. The testing code
// will need review each time I consider such a change. For the current
// upgrade I will allow opening of files from version N-1, but I will
// specifically lock out reading an initial heap-image from such. The issue
// of people who start with an old file and then write a fresh image back into
// it will be viewed as too messy to worry about in detail, but I hope that
// I have made it so that writing a new base image (via PRESERVE) updates the
// version info.
//
        version_moan(hdr.h.version) ||
        get_dirused(hdr.h) > get_dirsize(hdr.h) ||
        bits32(hdr.h.eof) < (int32_t)sizeof(directory_header))
    {
//
// Here I did not find a satisfactory header to the directory.  If I wanted
// to open the file for input I just return an empty directory, otherwise I
// need to create a new one.
//
        if (!write_OK) return make_empty_directory(expanded);
// This next bit is never used in the BUILTIN_DIRECTOT case
        fseek(f, 0, SEEK_SET);
        n = DIRECTORY_SIZE;      // Size for a directory
        d = (directory *)
            malloc(sizeof(directory)+(n-1)*sizeof(directory_entry));
        if (d == NULL) return &empty_directory;
        d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
        d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
        d->h.dirsize = (unsigned char)(n & 0xff);
        d->h.dirused = 0;
        d->h.dirext = (unsigned char)((n >> 4) & 0xf0);
        d->h.updated = D_WRITE_OK | D_UPDATED;
        d->full_filename = NULL;  // A PDS not a native dircetory
        for (i=0; i<n; i++) clear_entry(&d->d[i]);
        if (fwrite(&d->h, sizeof(directory_header), 1, f) != 1)
            return make_empty_directory(expanded);
        if (fwrite(&d->d[0], sizeof(directory_entry), (size_t)n, f) != (size_t)n)
            return make_empty_directory(expanded);
        d->f = f;
        strncpy(d->filename, expanded, DIRNAME_LENGTH);
        d->filename[DIRNAME_LENGTH-1] = 0;
        setbits32(d->h.eof, (int32_t)ftell(f));
        return d;
    }
    hdr.h.updated = write_OK ? D_WRITE_OK : 0;
    n = get_dirsize(hdr.h);
    d = (directory *)
        malloc(sizeof(directory)+(n-1)*sizeof(directory_entry));
    if (d == NULL) return &empty_directory;
    memcpy(&d->h, &hdr.h, sizeof(directory_header));
#ifdef BUILTIN_IMAGE
    if (builtinread(&d->d[0], sizeof(directory_entry), (size_t)n) != (size_t)n)
#else
    if (fread(&d->d[0], sizeof(directory_entry), (size_t)n, f) != (size_t)n)
#endif
        return make_empty_directory(expanded);
//
// Here the directory seemed OK
//
    d->f = f;
    strncpy(d->filename, expanded, DIRNAME_LENGTH);
    d->filename[DIRNAME_LENGTH-1] = 0;
    d->full_filename = NULL;
//
// For binary files ANSI specify that the values used with fseek and ftell
// are simple counts of the number of characters in the file, and hence
// it is proper to save ftell() values from one run to the next.
//
    return d;
}

static int unpending(directory *d)
{   FILE *f;
    int32_t i, n;
    if (d->full_filename != NULL)
    {   Cmkdir(d->full_filename);
        d->h.updated &= ~D_PENDING;
        d->h.updated |= D_WRITE_OK;  // suppose directories always updatable
        return false;
    }
    f = fopen(d->filename, "w+b");
    if (f == NULL) return true;
    d->f = f;
    d->filename[DIRNAME_LENGTH-1] = 0;  // truncate the name now
    n = DIRECTORY_SIZE;      // Size for a directory
// (the next bits were done when the pending directory was first created
//  d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
//  d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
//  d->h.dirsize = n & 0xff;
//  d->h.dirused = 0;
//  d->h.dirext = (n >> 4) & 0xf0;
//
    d->h.updated = D_WRITE_OK | D_UPDATED;
    for (i=0; i<n; i++) clear_entry(&d->d[i]);
    if (fwrite(&d->h, sizeof(directory_header), 1, f) != 1)
        return true;
    if (fwrite(&d->d[0], sizeof(directory_entry), (size_t)n, f) != (size_t)n)
        return true;
    setbits32(d->h.eof, (int32_t)ftell(f));
    return false;
}

void Iinit(void)
{   size_t i;
    Istatus = I_INACTIVE;
    current_input_directory = NULL;
    current_output_entry = NULL;
    current_output_directory = NULL;
#ifdef BUILTIN_IMAGE
    binary_read_filep = reduce_image;
#else
    binary_read_file = binary_write_file = NULL;
#endif
    read_bytes_remaining = write_bytes_written = 0;
    any_output_request = false;
    strcpy(would_be_output_directory, "<unknown>");
    for (i=0; i<number_of_fasl_paths; i++)
    {   if (0x40000000+i == output_directory)
            fasl_files[i] = open_pds(fasl_paths[i], PDS_PENDING);
        else
            fasl_files[i] = open_pds(fasl_paths[i],
                                     i == output_directory ? PDS_OUTPUT :
                                     PDS_INPUT);
    }
    CSL_MD5_Update((unsigned char *)"Copyright 2016 Codemist    ", 24);
}

//
// The code here was originally written to support module names up to
// 11 characters, but it has now been extended to support long names as
// well.
// The mechanism used is as follows:
// The name field in a directory entry is 12 characters long. For system
// special pseudo-modules all 12 characters are used for a name, and the
// cases used at present are InitialImage and HelpDataFile. For all
// user names the name is padded with blanks, and so user names of up
// to 11 characters live in the field with the 12th character a blank.
// To support long names I use values 0x80 and up in this 12th position.
// (NB position 12 is at offset 11 because of zero-base counting!)
// The first segment of a long name uses 11 characters of the user name
// and puts 0x80 in the 12th. Subsequent directory entries are used
// to hold more characters of the name. These hold 11 characters in the
// name field and 24 in the date, and put values 0x81, 0x82 etc in
// character 12. They will have a zero length field, but their position
// field MUST match that of the first record. This requirement is so that
// when I sort a directory the parts of a long name are kept both
// together and in the correct order. The last part of a long name has
// 0xff in position 12. The result is that I can distinguish the case
// of
// (.) a regular username of up to 11 chars (blank in position 12)
// (.) a system special file (non-blank, but under 0x80 in posn 12)
// (.) the start of a long name (0x80)
// (.) a middle part of a long name (0x81 ...)
// (.) the final part of a long name (0xff).
// when I match names here I will only allow a long-name match if my
// directory is pointing at the first part of a long name.
// As a further minor usefulness here if I find a match the non-zero value I
// return is the number of entries involved.
//

static int samename(const char *n1, directory *d, int j, size_t len)
//
// Compare the given names, given that n1 is of length len and n2 is
// blank-padded to exactly name_size characters. The special cases
// with n1 NULL allow len to encode what I am looking for.
//
{   const char *n2 = &d->d[j].D_name;
    size_t i, n, recs;
    if (len == IMAGE_CODE)
        return (memcmp(n2, "InitialImage", 12) == 0);
    if (len == HELP_CODE)
        return (memcmp(n2, "HelpDataFile", 12) == 0);
    if (len == BANNER_CODE)
        return (memcmp(n2, "Start-Banner", 12) == 0);
    if ((intptr_t)len < 0)   // Hard code has never been fully supported
                             // and the use of "negative length codes" for
                             // using it is dodgy!
    {   char hard[16];
        sprintf(hard, "HardCode<%.2x>", (int)((-len) & 0xff));
        return (memcmp(n2, hard, 12) == 0);
    }
    if ((n2[11] & 0xff) > 0x80) return 0;
    n = 0;
#define next_char_of_name (n++ < len ? *n1++ : ' ')
    for (i=0; i<11; i++)
        if (n2[i] != next_char_of_name) return 0;
    if ((n2[11] & 0x80) == 0) return ((n >= len) ? 1 : 0);
    recs = 1;
    do
    {   n2 = &d->d[++j].D_name;
        for (i=0; i<11; i++)
            if (n2[i] != next_char_of_name) return 0;
        for (i=12; i<36; i++)
            if (n2[i] != next_char_of_name) return 0;
        recs++;
    }
    while ((n2[11] & 0xff) != 0xff);
#undef next_char_of_name
    if (n < len) return 0;
    else return recs;
}

static void fasl_file_name(char *nn, directory *d, const char *name, size_t len)
{   size_t np;
    strcpy(nn, d->full_filename);
    np = strlen(nn);
#ifdef WIN32
    nn[np++] = '\\';
#else
    nn[np++] = '/';
#endif
    if (name == NULL)
    {   if (len == IMAGE_CODE) strcpy(&nn[np], "InitialImage");
        else if (len == HELP_CODE) strcpy(&nn[np], "HelpDataFile");
        else if (len == BANNER_CODE) strcpy(&nn[np], "Start-Banner");
        else if ((intptr_t)len < 0) sprintf(&nn[np], "HardCode-%.2x",
                                            (int)((-len) & 0xff));
    }
    else
    {   memcpy(&nn[np], name, len);
        strcpy(&nn[np+len], ".fasl");
    }
}


static bool open_input(directory *d, const char *name, size_t len,
                          size_t offset)
//
// Set up binary_read_file to access the given module, returning true
// if it was not found in the given directory. I used to pass the
// names "InitialImage" and "HelpDataFile" directly to this function, but
// to allow for long module names I am changing things so that these special
// cases are indicated by passing down a NULL string for the name and giving
// an associated length of -1 or -2 (resp).
//
{   int i;
    if (Istatus != I_INACTIVE || d == NULL) return true;
    nativedir = false;
    if (d->full_filename != NULL) // native directory mode
    {   char nn[LONGEST_LEGAL_FILENAME];
        memset(nn, 0, sizeof(nn));
        fasl_file_name(nn, d, name, len);
#ifdef BUILTIN_IMAGE
        binary_read_filep = reduce_image;
        read_bytes_remaining = REDUCE_IMAGE_SIZE;
#else
        if ((binary_read_file = fopen(nn, "rb")) == NULL) return true;
        fseek(binary_read_file, 0L, SEEK_END);
        read_bytes_remaining = ftell(binary_read_file);
#endif
#ifdef BUILTIN_IMAGE
        binary_read_filep = reduce_image + offset;
#else
        fseek(binary_read_file, (long)offset, SEEK_SET);
#endif
        Istatus = I_READING;
        nativedir = true;
        return false;
    }
//
// I use simple linear search to scan the directory - mainly because I
// expect directories to be fairly small and once I have found a file
// I will take a long while to process it, so any clumsiness here is
// not critical.
// This linear search may not be so smart any more, in that REDUCE ends
// up with about 750 modules, and if I store machine code versions of all
// of these for (say) 4 architectures I end up with almost 4000 directory
// entries...
// I will not allow myself to read from whichever file is currently open
// for output.
// Because samename() is careful to ensure it only reports a match when
// pointed at the start of a long name it is OK to search in steps of 1
// here.
//
    for (i=0; i<get_dirused(d->h); i++)
    {   if (samename(name, d, i, len) &&
            &d->d[i] != current_output_entry)
        {
#ifdef BUILTIN_IMAGE
            binary_read_filep = reduce_image;
            read_bytes_remaining = bits24(&d->d[i].D_size);
            binary_read_filep += bits32(&d->d[i].D_position)+offset;
            i = 0;
#else
            binary_read_file = d->f;
            read_bytes_remaining = bits24(&d->d[i].D_size);
            i = fseek(binary_read_file,
                      bits32(&d->d[i].D_position)+offset, SEEK_SET);
#endif
            if (i == 0)     // If fseek succeeded  it returned zero
            {   Istatus = I_READING;
                return false;
            }
            else return true;
        }
    }
    return true;
}

void IreInit(void)
{   CSL_MD5_Update((unsigned char *)"Copyright 2016 Codemist    ", 24);
    CSL_MD5_Update((unsigned char *)"memory.u", 8);
}

static int for_qsort(void const *aa, void const *bb)
{   directory_entry *a = (directory_entry *)aa,
                         *b = (directory_entry *)bb;
    long int ap = bits32(&a->D_position), bp = bits32(&b->D_position);
    if (ap < bp) return -1;
    else if (ap > bp) return 1;
//
// I make the position of the module in the image my primary sort key.
// Over-long module names are coped with by giving each part of the
// name the same position field, but marking the 12th character of the
// name field (D_space) with 0x80, 0x81 ... in extension records. Note that
// a regular short module name has a blank character there, while the special
// cases of "InitialImage" and "HelpDataFile" each have 'e' there,
// "Start-Banner" has 'r', while hard code has '>'.
// So bytes 0x80 and up are clearly (if hackily!) distinguished.
//
    ap = a->D_space & 0xff, bp = b->D_space & 0xff;
    if (ap < bp) return -1;
    else if (ap > bp) return 1;
    else return 0;
}

static void sort_directory(directory *d)
{   qsort((void *)d->d, (size_t)get_dirused(d->h),
          sizeof(directory_entry), for_qsort);
}

static directory *enlarge_directory(int current_size)
{   int n = (3*current_size)/2;
    int newsize = sizeof(directory)+(n-1)*sizeof(directory_entry);
    int newpos = sizeof(directory_header)+n*sizeof(directory_entry);
//
// enlarge_directory() is only called when an output library is known
// to exist, so I do not need to check for that here.
//
    int dirno = library_number(qvalue(output_library));
    directory *d1 = fasl_files[dirno];
    if (n > current_size+20) n = current_size+20;
    for (;;)
    {   directory_entry *first;
        FILE *f;
        char buffer[512];  // I hope this is not done too often, since this
                           // is not a very big buffer size for the copy.
        int32_t firstpos, firstlen, newfirst, eofpos;
        sort_directory(d1);
        first = &d1->d[0];
        firstpos = bits32(&first->D_position);
        if (firstpos >= newpos) break;
//
// Here I need to copy a module up to the end of the file to make room
// for the enlarged directory
//
        firstlen = bits24(&first->D_size);
        newfirst = eofpos = bits32(d1->h.eof);
        f = d1->f;
        while (firstlen >= (int32_t)sizeof(buffer))
        {   fseek(f, firstpos, SEEK_SET);
            if (fread(buffer, sizeof(buffer), 1, f) != 1) return NULL;
            fseek(f, eofpos, SEEK_SET);
            if (fwrite(buffer, sizeof(buffer), 1, f) != 1) return NULL;
            firstlen -= sizeof(buffer);
            firstpos += sizeof(buffer);
            eofpos += sizeof(buffer);
        }
        if (firstlen != 0)
        {   fseek(f, firstpos, SEEK_SET);
            if (fread(buffer, firstlen, 1, f) != 1) return NULL;
            fseek(f, eofpos, SEEK_SET);
            if (fwrite(buffer, firstlen, 1, f) != 1) return NULL;
            eofpos += firstlen;
        }
        setbits32(&first->D_position, newfirst);
        if ((first->D_space & 0xff) == 0x80)
        {   do
            {   first++;
                setbits32(&first->D_position, newfirst);
            }
            while ((first->D_space & 0xff) != 0xff);
        }
        setbits32(d1->h.eof, eofpos);
    }
    fseek(d1->f, newpos, SEEK_SET);
    d1 = (directory *)realloc((void *)d1, newsize);
    if (d1 == NULL) return NULL;
    d1->h.dirsize = (unsigned char)(n & 0xff);
    d1->h.dirext = (unsigned char)((d1->h.dirext & 0x0f) + ((n>>4) & 0xf0));
    d1->h.updated |= D_COMPACT | D_UPDATED;
    while (n>current_size) clear_entry(&d1->d[--n]);
    fasl_files[dirno] = d1;
    return d1;
}

bool open_output(const char *name, size_t len)
//
// Set up binary_write_file to access the given module, returning true
// if anything went wrong. Remember name==NULL for initial image & help
// data.
//
{   int i, j, n;
    const char *ct;
    char hard[16];
    directory *d;
    time_t t = time(NULL);
    LispObject oo = qvalue(output_library);
#ifdef BUILTIN_IMAGE
    return true;
#endif
    nativedir = false;
    if (!is_library(oo)) return true;
    d = fasl_files[library_number(oo)];
    if (d == NULL) return true;  // closed handle, I guess
    if ((d->h.updated & D_WRITE_OK) == 0) return true;
//
// The main effect of the next line will be to prohibit opening a new
// FASL file while I am in the middle of reading one that already exists.
// Indeed this is a restriction, but at present it seems a very reasonable
// on for me to apply.
//
    if (Istatus != I_INACTIVE) return true;
    if (d->h.updated & D_PENDING)
    {
//
// See comments in fasl.c under Lbanner for why I choose to report a failure
// rather then do and unpending() when the output module I am creating is
// just to contain banner information.
//
        if (name==NULL && len==BANNER_CODE) return true;
        if (unpending(d)) return true;
    }
    current_output_directory = d;
    if (d->full_filename != NULL) // native directory mode
    {   char nn[LONGEST_LEGAL_FILENAME];
        memset(nn, 0, sizeof(nn));
        fasl_file_name(nn, d, name, len);
        if ((binary_write_file = fopen(nn, "wb")) == NULL) return true;
        write_bytes_written = 0;
        Istatus = I_WRITING;
        nativedir = true;
        return false;
    }
//
// I use simple linear search to scan the directory - mainly because I
// expect directories to be fairly small and once I have found a file
// I will take a long while to process it, so any clumsiness here is
// not critical. Again note it is OK to scan in steps of 1 despite the
// fact that long-names are stored split across consecutive directory slots.
//
    for (i=0; i<get_dirused(d->h); i++)
    {   if (samename(name, d, i, len))
        {   current_output_entry = &d->d[i];
            d->h.updated |= D_COMPACT | D_UPDATED;
            if (t == (time_t)(-1)) ct = "not dated";
            else ct = ctime(&t);
//
// Note that I treat the result handed back by ctime() as delicate, in that
// I do not do any library calls between calling ctime and copying the
// string it returns to somewhere that is under my own control.
//
            strncpy(&d->d[i].D_date, ct, date_size);
            binary_write_file = d->f;
            write_bytes_written = 0;
            memcpy(&d->d[i].D_position, d->h.eof, 4);
// For long names I must put the location in each record
            if (d->d[i].D_space & 0x80)
            {   j = 0;
                do
                {   j++;
                    memcpy(&d->d[i+j].D_position, d->h.eof, 4);
                }
                while ((d->d[i+j].D_space & 0xff) != 0xff);
            }
            i = fseek(binary_write_file, bits32(d->h.eof), SEEK_SET);
            if (i == 0) Istatus = I_WRITING;
            else current_output_directory = NULL;
            if (name == NULL && len == IMAGE_CODE)
                d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
            return i;
        }
    }
//
// Here the name did not already exist, and so I will need to enter it into
// the directory.  If I get here the variable i points to the first unused
// directory entry.
//
    if (len == IMAGE_CODE)
    {   name = "InitialImage";
        n = 1;
        d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    }
    else if (len == HELP_CODE) name = "HelpDataFile", len = IMAGE_CODE, n = 1;
    else if (len == BANNER_CODE) name = "Start-Banner", len = IMAGE_CODE, n = 1;
    else if ((intptr_t)len < 0)
    {   sprintf(hard, "HardCode<%.2x>", (int)((-len) & 0xff));
        name = hard, len = IMAGE_CODE, n = 1;
    }
    else if (len <= 11) n = 1;
    else if (len <= 11+11+24) n = 2;
    else if (len <= 11+11+11+24+24) n = 3;
    else return true;  // Name longer than 81 chars not supported, sorry
    while (i+n > (int)get_dirsize(d->h))
    {   d = enlarge_directory(i);
        current_output_directory = d;
        if (d == NULL) return true;
    }
    current_output_entry = &d->d[i];
    if (len == IMAGE_CODE)
    {   d->d[i].D_newline = NEWLINE_CHAR;
        memcpy(&d->d[i].D_name, name, 12);
        memset(&d->d[i].D_date, ' ', date_size);
        memset(&d->d[i].D_size, 0, 3);
        memcpy(&d->d[i].D_position, d->h.eof, 4);
    }
    else
    {   size_t np;
        const char *p;
//
// First I will clear all the relevant fields to blanks.
//
        for (j=0; j<n; j++)
        {   d->d[i+j].D_newline = '\n';
            memset(&d->d[i+j].D_name, ' ', name_size);
            memset(&d->d[i+j].D_date, ' ', date_size);
            memset(&d->d[i+j].D_size, 0, 3);
            memcpy(&d->d[i+j].D_position, d->h.eof, 4);
        }
#define next_char_of_name (np++ >= len ? ' ' : *p++)
        np = 0;
        p = name;
        for (j=0; j<n; j++)
        {   int k;
            for (k=0; k<11; k++) (&d->d[i+j].D_name)[k] = next_char_of_name;
            if (j != 0)
                for (k=0; k<24; k++)
                    (&d->d[i+j].D_date)[k] = next_char_of_name;
            if (j == 0 && n == 1) d->d[i+j].D_space = ' ';
            else if (j == n-1) d->d[i+j].D_space = 0xff;
            else d->d[i+j].D_space = (char)(0x80+j);
#undef next_char_of_name
        }
    }
    if (t == (time_t)(-1)) ct = "** *** not dated *** ** ";
    else ct = ctime(&t);
    strncpy(&d->d[i].D_date, ct, date_size);
    set_dirused(&d->h, get_dirused(d->h)+n);
    binary_write_file = d->f;
    write_bytes_written = 0;
    d->h.updated |= D_UPDATED;
    i = fseek(binary_write_file, bits32(d->h.eof), SEEK_SET);
    if (i == 0)
    {   Istatus = I_WRITING;
        return false;
    }
    else
    {   current_output_directory = NULL;
        return true;
    }
}

static void list_one_native(const char *name, int why, long int size)
{   struct stat statbuff;
    char shortname[100];
    char *p;
    if (why != SCAN_FILE) return;
    stat(name, &statbuff);      // read the date on the file
    while (*name != 0) name++;
//
// I need a comment about why the loop on the next line is guaranteed to
// terminate. Well I only ought to be executing this code if the image
// is represented as an operating-system directory, and when scan_directory
// inspects it all the files in it are within it (gee!) and so have names
// along the line of "csl.img/compat.fasl". So I really do expect to find
// a directory separator character within the name.
//
    while (*name != '/' && *name != '\\') name--;
    strncpy(shortname, name+1, sizeof(shortname)-1);
    shortname[sizeof(shortname)-1] = 0;
    p = shortname;
    while (*p != 0 && strcmp(p, ".fasl") != 0) p++;
    *p = 0;
    if (strlen(shortname) > 12) trace_printf(
            "    %s\n                  %-24.24s    size: %ld\n",
            shortname, ctime(&(statbuff.st_mtime)),
            size);
    else trace_printf(
            "    %-12.12s  %-24.24s    size: %ld\n",
            shortname, ctime(&(statbuff.st_mtime)),
            size);
}


static void list_one_library(LispObject oo, bool out_only)
{   int j;
    directory *d = fasl_files[library_number(oo)];
    if (d->full_filename != NULL)
    {   trace_printf("Directory %s\n", d->full_filename);
        scan_directory(d->full_filename, list_one_native);
        return;
    }
    trace_printf("\nFile %s (dirsize %ld  length %ld",
                 d->filename, (long)get_dirsize(d->h), (long)bits32(d->h.eof));
    j = d->h.updated;
    if (j != 0) trace_printf(",");
    if (j & D_WRITE_OK) trace_printf(" Writable");
    if (j & D_UPDATED)  trace_printf(" Updated");
    if (j & D_COMPACT)  trace_printf(" NeedsCompaction");
    if (j & D_PENDING)  trace_printf(" Pending");
    if (out_only) trace_printf(" OutputOnly");
    trace_printf("):\n");
//
// The format string used here will need adjustment if you ever change the
// number of characters used to store names or dates.
//
    for (j=0; j<get_dirused(d->h); j++)
    {   int n = 0;
        if (d->d[j].D_space & 0x80)
        {   trace_printf("    %.11s", &d->d[j].D_name);
            do
            {   n++;
                trace_printf("%.11s%.24s",
                             &d->d[j+n].D_name, &d->d[j+n].D_date);
            }
            while ((d->d[j+n].D_space & 0xff) != 0xff);
            trace_printf(
                "\n                  %-24.24s    position %-7ld size: %ld\n",
                &d->d[j].D_date,
                (long)bits32(&d->d[j].D_position),
                (long)bits24(&d->d[j].D_size));
            j += n;
        }
        else trace_printf(
                "    %-12.12s  %-24.24s    position %-7ld size: %ld\n",
                &d->d[j].D_name, &d->d[j].D_date,
                (long)bits32(&d->d[j].D_position),
                (long)bits24(&d->d[j].D_size));
    }
}

void Ilist(void)
{   LispObject il = qvalue(input_libraries), w;
    LispObject ol = qvalue(output_library);
    while (consp(il))
    {   w = qcar(il); il = qcdr(il);
        if (!is_library(w)) continue;
        if (w == ol) ol = nil;
        list_one_library(w, false);
    }
    if (is_library(ol)) list_one_library(ol, true);
}

static LispObject mods;

static void collect_modules(const char *name, int why, long int size)
{   int k = 0;
    LispObject v;
    char *p = (char *)&celt(boffo, 0);
    if (why != SCAN_FILE) return;
    push(mods);
    while (*name != 0) name++;
    while (*name != '/' && *name != '\\') name--;
    name++;
    while (*name != '.' && *name != 0)
    {   *p++ = *name++;
        k++;
    }
    if (strcmp(name, ".fasl") != 0) return;
    v = iintern(boffo, k, lisp_package, 0);
    pop(mods);
    mods = cons(v, mods);
}

LispObject Llibrary_members(LispObject env, LispObject oo)
{   int i, j, k;
    directory *d = fasl_files[library_number(oo)];
    LispObject v, r = nil;
    char *p;
    if (d->full_filename != NULL)
    {   mods = nil;
        scan_directory(d->full_filename, collect_modules);
        return onevalue(mods);
    }
    for (j=0; j<get_dirused(d->h); j++)
    {   int n = 0;
        p = (char *)&celt(boffo, 0);
        k = 0;
        if (d->d[j].D_space & 0x80)
        {   for (i=0; i<11; i++)
            {   *p++ = (&d->d[j].D_name)[i];
                k++;
            }
            do
            {   n++;
                for (i=0; i<11; i++)
                {   *p++ = (&d->d[j+n].D_name)[i];
                    k++;
                }
            }
            while ((d->d[j+n].D_space & 0xff) != 0xff);
            j += n;
        }
        else
        {   if (memcmp(&d->d[j].D_name, "InitialImage", 12) == 0 ||
                memcmp(&d->d[j].D_name, "HelpDataFile", 12) == 0 ||
                memcmp(&d->d[j].D_name, "Start-Banner", 12) == 0 ||
                (memcmp(&d->d[j].D_name, "HardCode<", 9) == 0 &&
                 (&d->d[j].D_name)[11] == '>'))
                continue;  // not user modules
            for (i=0; i<12; i++)
            {   *p++ = (&d->d[j].D_name)[i];
                k++;
            }
        }
        while (k>0 && p[-1] == ' ') k--, p--;
        *p = 0;
        push(r);
        v = iintern(boffo, k, lisp_package, 0);
        pop(r);
        r = cons(v, r);
    }
    return onevalue(r);
}

LispObject Llibrary_members0(LispObject env, int nargs, ...)
//
// This returns a list of the modules in the first library on the current
// search path.
//
{   LispObject il = qvalue(input_libraries), w;
    LispObject ol = qvalue(output_library);
    argcheck(nargs, 0, "library-members");
    while (consp(il))
    {   w = qcar(il); il = qcdr(il);
        if (!is_library(w)) continue;
        return Llibrary_members(nil, w);
    }
    if (is_library(ol)) return Llibrary_members(nil, ol);
    else return onevalue(nil);
}

bool Imodulep(const char *name, size_t len, char *datestamp, size_t *size,
                 char *expanded_name)
//
// Hands back information about whether the given module exists, and
// if it does when it was written.  Code should be very similar to
// that in Iopen.
//
{   int i;
    LispObject il = qvalue(input_libraries);
    while (consp(il))
    {   int j;
        directory *d;
        LispObject oo = qcar(il); il = qcdr(il);
        if (!is_library(oo)) continue;
        i = library_number(oo);
        d = fasl_files[i];
        if (d == NULL) continue;
        if (d->full_filename != NULL)
        {   char nn[LONGEST_LEGAL_FILENAME];
            struct stat statbuff;
            memset(nn, 0, sizeof(nn));
            fasl_file_name(nn, d, name, len);
            if (stat(nn, &statbuff) != 0) continue;   // file not present
            strcpy(expanded_name, nn);
            strcpy(datestamp, ctime(&(statbuff.st_mtime)));
//
// Note that FASL modules here will surely never even start to get towards
// the size-limits of a 32-bit integer!
//
            *size = (int32_t)statbuff.st_size;
            return false;
        }
        for (j=0; j<get_dirused(d->h); j++)
        {   if (samename(name, d, j, len))
            {   const char *n = fasl_files[i]->filename;
                const char *p1 = "(", *p2 = ")";
                if (d->full_filename != NULL)
                {
#ifdef WIN32
                    p1 = "\\";
#else
                    p1 = "/";
#endif
                    p2 = "";
                }
                memcpy(datestamp, &d->d[j].D_date, date_size);
                *size = bits24(&d->d[j].D_size);
                if (name == NULL) sprintf(expanded_name,
                                              "%s%sInitialImage%s", n, p1, p2);
                else sprintf(expanded_name,
                                 "%s%s%.*s%s", n, p1, (int)len, name, p2);
                return false;
            }
        }
    }
    return true;
}

directory *rootDirectory = NULL;

bool IopenRoot(char *expanded_name, size_t hard, int sixtyfour)
//
// Opens the "InitialImage" file so that it can be loaded. Note that
// when I am about to do this I do not have a valid heap image loaded, and
// so it would NOT be possible to use the regular search-path mechanism for
// libraries. Therefore I will just use images as specified from the
// command line (or by default).
//
{   const char *n;
    size_t i;
    if (hard == 0) hard = IMAGE_CODE;
    for (i=0; i<number_of_fasl_paths; i++)
    {
        bool bad = open_input(fasl_files[i], NULL, hard, 0);
//
// The name that I return (for possible display in error messages) will be
// either that of the file that was opened, or one relating to the last
// entry in the search path.
//
        n = fasl_files[i]->filename;

        if (hard == IMAGE_CODE) rootDirectory = fasl_files[i];

        if (expanded_name != NULL)
        {   if (hard == IMAGE_CODE)
            {   sprintf(expanded_name, "%s(InitialImage)", n);
            }
            else if (hard == BANNER_CODE)
                sprintf(expanded_name, "%s(InitialImage)", n);
            else sprintf(expanded_name, "%s(HardCode<%.2x>)",
                             n, (int)((-hard) & 0xff));
        }
        if (!bad) return false;
    }
    return true;
}

bool Iopen(const char *name, size_t len, int forinput, char *expanded_name)
//
// Make file with the given name available through this package of
// routines.  (name) is a pointer to a string (len characters valid) that
// names a fasl file.  (forinput) specifies the direction of the transfer
// to set up. Returns true if something failed.
// name can be NULL when a module is opened for output, and then output
// is sent to "InitialImage".
// The same is done for input, but it would be more sensible to use
// IopenRoot() to access the root image.
//
{   const char *n;
    if (name == NULL) len = IMAGE_CODE;
    if (forinput != IOPEN_OUT)
    {   int i;
        LispObject il = qvalue(input_libraries);
        while (consp(il))
        {   bool bad;
            LispObject oo = qcar(il); il = qcdr(il);
            if (!is_library(oo)) continue;
            i = library_number(oo);
            bad = open_input(fasl_files[i], name, len, 0);
//
// The name that I return (for possible display in error messages) will be
// either that of the file that was opened, or one relating to the last
// entry in the search path.
//
            n = fasl_files[i]->filename;
            if (expanded_name != NULL)
            {   const char *p1 = "(", *p2 = ")";
                if (fasl_files[i]->full_filename != NULL)
                {
#ifdef WIN32
                    p1 = "\\";
#else
                    p1 = "/";
#endif
                    p2 = "";
                }
                sprintf(expanded_name, "%s%s%.*s%s", n, p1, (int)len, name, p2);
            }
            if (!bad) return false;
        }
        return true;
    }
    if (!any_output_request)
    {   if (expanded_name != NULL)
            strcpy(expanded_name, "<no output file specified>");
        return true;
    }
    n = would_be_output_directory;
    if (expanded_name != NULL)
    {   const char *p1 = "(", *p2 = ")";
        LispObject oo = qvalue(output_library);
        directory *d;
        if (!is_library(oo)) return true;
        d = fasl_files[library_number(oo)];
        if (d->full_filename != NULL)
        {
#ifdef WIN32
            p1 = "\\";
#else
            p1 = "/";
#endif
            p2 = "";
        }
        if (len == IMAGE_CODE)
            sprintf(expanded_name, "%s%sInitialImage%s", p1, n, p2);
        else sprintf(expanded_name, "%s%s%.*s%s", n, p1, (int)len, name, p2);
    }
    return open_output(name, len);
}

bool Iwriterootp(char *expanded_name)
//
// Test if it will be possible to write out an image file. Used
// by (preserve) so it can report that this would fail without actually
// doing anything too drastic.
//
{   directory *d;
    LispObject oo = qvalue(output_library);
    if (!any_output_request)
    {   strcpy(expanded_name, "<no output file specified>");
        return true;
    }
    sprintf(expanded_name, "%s(InitialImage)", would_be_output_directory);
    if (!is_library(oo)) return true;
    d = fasl_files[library_number(oo)];
    if (d == NULL) return true;  // closed handle, I guess
//
// At present for native directories the WRITE_OK flag is left set without
// proper checking of file access permissions.
//
    if ((d->h.updated & D_WRITE_OK) == 0) return true;
    if (Istatus != I_INACTIVE) return true;
    return false;
}

bool Iopen_banner(int code)
//
// Get ready to handle the startup banner.
// code = 0    open for reading
// code = -1   open for writing
// code = -2   delete banner file
//
{   if (code == -2) return Idelete(NULL, BANNER_CODE);
    else if (code == 0)
    {   LispObject il = qvalue(input_libraries);
        while (consp(il))
        {   bool bad;
            LispObject oo = qcar(il); il = qcdr(il);
            if (!is_library(oo)) continue;
            bad = open_input(fasl_files[library_number(oo)],
                             NULL, BANNER_CODE, 0);
            if (!bad) return false;
        }
        return true;
    }
    if (!any_output_request) return true;
    else return open_output(NULL, BANNER_CODE);
}

//
// Set up binary_read_file to read from standard input. Return true if
// things fail.
//

bool Iopen_from_stdin(void)
{   if (Istatus != I_INACTIVE) return true;
#ifdef BUILTIN_IMAGE
    binary_read_filep = NULL;
#else
    binary_read_file = NULL;
#endif
    read_bytes_remaining = -1;
    Istatus = I_READING;
    return false;
}

bool Iopen_to_stdout(void)
{   if (Istatus != I_INACTIVE) return true;
    Istatus = I_WRITING;
    return false;
}

bool Idelete(const char *name, size_t len)
{   int i, nrec;
    directory *d;
    LispObject oo = qvalue(output_library);
    if (!is_library(oo)) return true;
    d = fasl_files[library_number(oo)];
    if (d == NULL ||
        (d->h.updated && D_WRITE_OK) == 0 ||
        Istatus != I_INACTIVE) return true;
    if (d->full_filename != NULL)
    {   char nn[LONGEST_LEGAL_FILENAME];
        memset(nn, 0, sizeof(nn));
        fasl_file_name(nn, d, name, len);
        return (remove(nn) != 0);
    }
    for (i=0; i<get_dirused(d->h); i++)
    {   if ((nrec = samename(name, d, i, len)) != 0)
        {   int j;
            set_dirused(&d->h, get_dirused(d->h)-nrec);
            for (j=i; j<get_dirused(d->h); j++)
                d->d[j] = d->d[j+nrec];
//
// I tidy up the now-unused entry - in some sense this is a redundant
// operation, but I think it makes the file seem neater, which may possibly
// help avoid confusion and ease debugging.
//
            while (nrec-- != 0)
            {   memset(&d->d[j].D_name, ' ', name_size);
                memcpy(&d->d[j].D_name, "<Unused>", 8);
                memset(&d->d[j].D_date, ' ', date_size);
                (&d->d[j].D_date)[0] = '-';
                setbits32(&d->d[j].D_position, 0);
                setbits24(&d->d[j].D_size, 0);
                j++;
            }
            d->h.updated |= D_COMPACT | D_UPDATED;
            return false;
        }
    }
    return true;
}

bool Icopy(const char *name, size_t len)
//
// Find the named module in one of the input files, and if the place that
// it is found is not already the output file copy it to the output. These days
// either (or neither or both!) the places could be either my own 1-file
// image-files or they could be native directories. But for now I will just
// ignore that and only support the older situation. That is because I am lazy!
//
{   int i, ii, j, n;
    long int k, l, save = read_bytes_remaining;
    char hard[16];
    directory *d, *id;
    LispObject il, oo = qvalue(output_library);
    if (!is_library(oo)) return true;
    d = fasl_files[library_number(oo)];
//
// Only valid if there is an output file and nothing else is going on.
//
    if (d == NULL ||
        (d->h.updated & D_WRITE_OK) == 0 ||
        Istatus != I_INACTIVE) return true;
    if (d->h.updated & D_PENDING)
    {   if (unpending(d)) return true;
    }
//
// The next line refuses to copy INTO a native directory...
//
    if (d->full_filename != NULL) return true;
//
// Search for a suitable input module to copy...
//
    for (il=qvalue(input_libraries); consp(il); il = qcdr(il))
    {   oo = qcar(il);
        if (!is_library(oo)) continue;
        i = library_number(oo);
        id = fasl_files[i];
// Not updated for native dirs yet
        if (id->full_filename != NULL) continue;
        for (ii=0; ii<get_dirused(id->h); ii++)
            if (samename(name, id, ii, len)) goto found;
    }
    return true;     // Module to copy not found
found:
//
// If the potential input module found was in the output directory exit now.
//
    if (id == d) return false;
//
// Now scan output directory to see where to put result
//
    for (i=0; i<get_dirused(d->h); i++)
// Not updated for native dirs yet
        if (samename(name, d, i, len))
        {   d->h.updated |= D_UPDATED | D_COMPACT;
            goto ofound;
        }
//
// The file was not previously present in the output directory, so
// I need to insert it. The code here is copies from open_output and is
// now messy enoug that I should really move it to a sub-function.
//
    if (len == IMAGE_CODE)
        name = "InitialImage", n = 1;
    else if (len == HELP_CODE)
        name = "HelpDataFile", len = IMAGE_CODE, n = 1;
    else if (len == BANNER_CODE)
        name = "Start-Banner", len = IMAGE_CODE, n = 1;
    else if ((intptr_t)len < 0)
    {   sprintf(hard, "HardCode<%.2x>", (int)((-len) & 0xff));
        name = hard, len = IMAGE_CODE, n = 1;
    }
    else if (len <= 11) n = 1;
    else if (len <= 11+11+24) n = 2;
    else if (len <= 11+11+11+24+24) n = 3;
    else return true;  // Name longer than 81 chars not supported, sorry
    while (i+n > (int)get_dirsize(d->h))
    {   d = enlarge_directory(i);
        current_output_directory = d;
        if (d == NULL) return true;
    }
    current_output_entry = &d->d[i];
    if (len == IMAGE_CODE)
    {   d->d[i].D_newline = NEWLINE_CHAR;
        memcpy(&d->d[i].D_name, name, 12);
        memset(&d->d[i].D_date, ' ', date_size);
        memset(&d->d[i].D_size, 0, 3);
        memcpy(&d->d[i].D_position, d->h.eof, 4);
    }
    else
    {   size_t np;
        const char *p;
//
// First I will clear all the relevant fields to blanks.
//
        for (j=0; j<n; j++)
        {   d->d[i+j].D_newline = '\n';
            memset(&d->d[i+j].D_name, ' ', name_size);
            memset(&d->d[i+j].D_date, ' ', date_size);
            memset(&d->d[i+j].D_size, 0, 3);
            memcpy(&d->d[i+j].D_position, d->h.eof, 4);
        }
#define next_char_of_name (np++ >= len ? ' ' : *p++)
        np = 0;
        p = name;
        for (j=0; j<n; j++)
        {   for (k=0; k<11; k++) (&d->d[i+j].D_name)[k] = next_char_of_name;
            if (j != 0)
                for (k=0; k<24; k++)
                    (&d->d[i+j].D_date)[k] = next_char_of_name;
            if (j == 0 && n == 1) d->d[i+j].D_space = ' ';
            else if (j == n-1) d->d[i+j].D_space = 0xff;
            else d->d[i+j].D_space = (char)(0x80+j);
#undef next_char_of_name
        }
    }
    set_dirused(&d->h, get_dirused(d->h)+n);
ofound:
    memcpy(&d->d[i].D_date, &id->d[ii].D_date, date_size);
    trace_printf("\nCopy %.*s from %s to %s\n",
                 len, name, id->filename, d->filename);
    memcpy(&d->d[i].D_position, d->h.eof, 4);
    if (d->d[i].D_space & 0x80)
    {   n = 0;
        do
        {   n++;
            memcpy(&d->d[i+n].D_position, d->h.eof, 4);
        }
        while ((d->d[i+n].D_space & 0xff) != 0xff);
    }
//
// I provisionally set the size to zero so that if something goes wrong
// I will still have a tolerably sensible image file.
//
    memset(&d->d[i].D_size, 0, 3);
    d->h.updated |= D_UPDATED;
    if (fseek(d->f, bits32(&d->d[i].D_position), SEEK_SET) != 0 ||
        fseek(id->f, bits32(&id->d[ii].D_position), SEEK_SET) != 0) return true;
    l = bits24(&id->d[ii].D_size);
    for (k=0; k<l; k++)
    {   int c = getc(id->f);
        if (c == EOF) return true;
        putc(c, d->f);
    }
    read_bytes_remaining = 0;
    read_bytes_remaining = save;
    if (fflush(d->f) != 0) return true;
    setbits24(&d->d[i].D_size, (int32_t)l);
    setbits32(d->h.eof, (int32_t)ftell(d->f));
    return false;
}

bool IcloseInput()
//
// Terminate processing one whatever subfile has been being processed.
// returns nonzero if there was trouble.
//
{   Istatus = I_INACTIVE;
#ifndef BUILTIN_IMAGE
    if (nativedir)
    {   if (fclose(binary_read_file) != 0) return true;
    }
#endif
    return false;
}

bool IcloseOutput()
//
// Terminate processing one whatever subfile has been being processed.
// returns nonzero if there was trouble. Write a checksum to the file.
// There is a jolly joke here!  I MUST NOT try to pick up the identification
// of the output directory from the lisp-level variable output_directory
// because (preserve) calls this AFTER it has utterly mangled the heap (to
// put all pointers into relative form). To allow for this the variable
// current_output_directory identifies the directory within which a file
// was most recently opened.
//
{   int r;
    directory *d = current_output_directory;
    Istatus = I_INACTIVE;
    current_output_directory = NULL;
    if (d->full_filename != NULL)
    {   r = (fclose(binary_write_file) != 0);
        binary_write_file = NULL;
        return r;
    }
    setbits24(&current_output_entry->D_size, (int32_t)write_bytes_written);
    r = fflush(d->f);
    setbits32(d->h.eof, (int32_t)ftell(d->f));
//
// I bring the directory at the start of the output file up to date at this
// stage - the effect is that if things crash somehow I have a better
// chance of resuming from where disaster hit.
//
    fseek(d->f, 0, SEEK_SET);
    if (fwrite(&d->h, sizeof(directory_header), 1, d->f) != 1) r = true;
    if (fwrite(&d->d[0], sizeof(directory_entry),
               (size_t)get_dirsize(d->h), d->f) !=
        (size_t)get_dirsize(d->h)) r = true;
    if (fflush(d->f) != 0) r = true;
    d->h.updated &= ~D_UPDATED;
    current_output_entry = NULL;
    return r;
}

bool finished_with(int j)
{   directory *d = fasl_files[j];
    fasl_files[j] = NULL;
//
// If the library concerned had been opened using (open-library ...) then
// the name stored in fasl_paths[] would have been allocated using malloc(),
// and just discarding it as here will represent a space-leak. Just for now
// I am going to accept that as an unimportant detail.
//
    fasl_paths[j] = NULL;
    if (d == NULL) return false;
    if (d->h.updated & D_COMPACT)
    {   int i;
        long int hwm;
        if (d->f == NULL) return true;
        d->h.updated |= D_UPDATED;
        sort_directory(d);
        hwm = sizeof(directory_header) +
              get_dirsize(d->h)*(long int)sizeof(directory_entry);
        for (i=0; i<get_dirused(d->h); i++)
        {   long int pos = bits32(&d->d[i].D_position);
            if (pos != hwm)
            {   char *b = 16 + (char *)stack;
                char small_buffer[64];
                long int len = bits24(&d->d[i].D_size);
                long int newpos = hwm;
                while (len != 0)
                {   size_t n =
                        (size_t)((CSL_PAGE_SIZE - 64 -
                                  ((char *)stack - (char *)stackbase)) &
                                 (~(int32_t)0xff));
//
// I only perform compression of the file when I am in the process of stopping,
// and in that case the Lisp stack is not in use, so I use if as a buffer.
// WELL the above statement used to be true, but now it is not, since the
// function CLOSE-LIBRARY does exactly what I have declared is never
// possible. But all is not lost - I can afford to use that part of
// the stack that remains unused. In cases where CLOSE-LIBRARY is called
// just before a stack overflow was due the result will be utterly terrible
// (on speed) but it should still be correct. So what you will see is that
// I start my buffer 16 bytes above the active part of the stack, and
// let it run to within 48 bytes of the top of the stack page, but
// rounded down so I do transfers in multiples of 256 bytes. If there
// is really no (Lisp) stack free I use a 64 byte local buffer.
//
                    if (n == 0) b = small_buffer, n = sizeof(small_buffer);
                    if (len < (long int)n) n = (size_t)len;
                    fseek(d->f, pos, SEEK_SET);
                    fread(b, 1, n, d->f);
                    pos = ftell(d->f);
                    fseek(d->f, newpos, SEEK_SET);
                    fwrite(b, 1, n, d->f);
                    newpos = ftell(d->f);
                    len -= n;
                }
                setbits32(&d->d[i].D_position, (int32_t)hwm);
            }
            hwm += bits24(&d->d[i].D_size) + 4L;
        }
        fflush(d->f);
        if (hwm != bits32(d->h.eof))
        {   truncate_file(d->f, hwm);
            setbits32(d->h.eof, (int32_t)hwm);
        }
    }
    if (d->h.updated & D_UPDATED)
    {   if (d->f == NULL || fflush(d->f) != 0) return true;
        fseek(d->f, 0, SEEK_SET);
        if (fwrite(&d->h, sizeof(directory_header), 1, d->f) != 1) return true;
        if (fwrite(&d->d[0], sizeof(directory_entry),
                   (size_t)get_dirsize(d->h), d->f) !=
            (size_t)get_dirsize(d->h)) return true;
        if (fflush(d->f) != 0) return true;
    }
    if (d->h.updated & D_PENDING) return false;
    else if (d->f != NULL && fclose(d->f) != 0) return true;
    else return false;
}

bool Ifinished(void)
//
// Indicates total completion of all work on image files, and so calls
// for things to be (finally) tidied up.  Again returns true of anything
// has gone wrong.
//
{
//
// Need to close all files here... loads of calls to fflush and fclose.
// Actually only output files are a real issue here. And then only
// the ones that are flagged as needing compaction.
//
    size_t j;
    bool failed = false;
    for (j=0; j<number_of_fasl_paths; j++)
        if (finished_with(j)) failed = true;
    return failed;
}

int Igetc(void)
//
// Returns next byte from current image sub-file, or EOF if either
// real end-of-file or on failure. As a special fudge here (ugh) I
// use a negative value of read_bytes_remaining to indicate that
// input should NOT be from the usual image-file mechanism, but from
// the currently selected standard input. Setting things up that way
// then supports processing of FASL files from almost arbitrary
// sources.
//
{   long int n_left = read_bytes_remaining;
    int c;
    if (n_left <= 0)
    {   if (n_left == 0) return EOF;
        else
        {   LispObject stream = qvalue(standard_input);
            if (!is_stream(stream)) return EOF;
            if_error(c = getc_stream(stream),
                     return EOF);
        }
    }
    else
    {   read_bytes_remaining = n_left - 1;
#ifdef BUILTIN_IMAGE
        if (binary_read_filep - reduce_image == REDUCE_IMAGE_SIZE) c = -1;
        else c = *binary_read_filep++;
#else
        c = getc(binary_read_file);
#endif
    }
    if (c == EOF) return c;
    return (c & 0xff);
}

bool Iread(void *buff, size_t size)
// Reads (size) bytes into the indicated buffer.  Returns true if
// if fails to read the expected number of bytes.
{
    unsigned char *p = (unsigned char *)buff;
    while (size > 0)
    {   int c = Igetc();
        if (c == EOF) return true;
        *p++ = c;
        size--;
    }
    return false;
}

long int Ioutsize(void)
{   return write_bytes_written;
}

bool Iputc(int ch)
//
// Puts one character into image system, returning true if there
// was trouble.
// If start-module is given a Lisp stream as an argument then it will
// save that in fasl_stream and the code must write bytes to there. Otherwise
// (ie in the normal situation!) I will have used Iopen to set up the
// stream, and it will have set binary_write_file to the stream and positioned
// it at the point I should start writing.
//
{   write_bytes_written++;
    if (fasl_stream != nil && fasl_stream != SPID_NIL)
        putc_stream(ch, fasl_stream);
    else if (putc(ch, binary_write_file) == EOF) return true;
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

void preserve(const char *banner, size_t len)
{   int32_t i;
    if (Iopen(NULL, 0, IOPEN_OUT, NULL))
    {   err_printf("+++ PRESERVE failed to open image file\n");
        return;
    }
//
// I set a whole bunch of things to NIL here.  If spurious data is left over
// in global list-bases from a previous calculation it could clog up the
// heap and waste a lot of space...
//
    for (i=0; i<=50; i++) workbase[i] = nil;
    exit_tag = exit_value = catch_tags =
        codevec = litvec = B_reg = faslvec = faslgensyms = nil;
    Lmapstore(nil, fixnum_of_int(4)); // Reset all counts to zero.
    {   char msg[128];
        time_t t0 = time(0);
        for (i=0; i<128; i++) msg[i] = ' ';
        if (len > 60) len = 60; // truncate if necessary
        if (len == 0 || banner[0] == 0) msg[0] = 0;
        else sprintf(msg, "%.*s", (int)len, banner);
// 26 bytes starting from byte 64 shows the time of the dump
        sprintf(msg+64, "%.25s\n", ctime(&t0));
// 16 bytes starting at byte 90 are for a checksum of the u01.c etc checks
        get_user_files_checksum((unsigned char *)&msg[90]);
// 106 to 109 free at present but available if checksum goes to 160 bits
        msg[110] = 0;
        msg[111] = 0;
// Write initial record uncompresssed...
        Iwrite(msg, 112); // Exactly 112 bytes in the header records
    }
    def_init();  // I should check the return code...
    write_everything(); // needs a return code to report any failure?

#ifndef COMMON
    Zwrite("\n\nEnd of CSL dump file\n\n", 24);  // return code
#else
    Zwrite("\n\nEnd of CCL dump file\n\n", 24);  // return code
#endif
    def_finish();   // I should check the return code...
//
// Here I pad the image file to be a multiple of 4 bytes long.  Since it is a
// binary file the '\n' characters I put in will always be just 1 byte each
// (for text files that might have expanded).  See comments in fasl.c for
// a diatribe about why I do this, or at least why rather a long while ago
// this was necessary on at least one sort of computer.
// Note that this is writing directly to the file... not via the compression
// layer.
    {   int k = (int)((-write_bytes_written) & 3);
        while (k != 0) k--, Iputc(NEWLINE_CHAR);
    }
//
// I need to check for write errors here and moan if there were any...
//
    if (IcloseOutput()) error(0, err_write_err);
    return;
}

#endif // ZLIB_DEMO

// end of file preserve.cpp
