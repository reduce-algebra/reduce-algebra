/* preserve.c                 Copyright (c) Codemist Ltd, 1990-2008 */

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


/* Signature: 70ed9025 19-Aug-2008 */

#include "headers.h"

#include "version.h"

/*
 * The following extra includes should probably be hidden away elsewere
 * and/or abtracted away a bit. They are here so I can check if a file-name
 * refers to a directory.
 */

#include <sys/stat.h>
#include <sys/types.h>

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
 * I perform file compression when making checkpoint images.
 * This is achieved by having procedure Cfwrite and Cfread which
 * are much like fwrite and fread but which are entitled to use a
 * squashed format on the external medium.  It is fairly important that
 * Cfread should be reasonably fast - Cfwrite is just used by (preserve)
 * and is not so critical.  The overall compression strategy implemented
 * here is a variant on LZ - the compressed file is made up of 12-bit
 * characters.  The first 256 codes stand for bytes present in the original
 * data, while the remaining codes get allocated to stand for pairs of
 * characters found adjacent in the data.  Initial experiments show that
 * the simple version of the idea implemented here squashes binary image
 * files to about 60% of their original size, while more elaborate
 * schemes can not do MUCH better.
 */

int32_t compression_worth_while = 128;

#ifndef DEMO_MODE

static void Cfwrite(char *a, int32_t size)
{
/*
 * I keep a table showing how single 12-bit characters in the
 * compressed file map onto character-pairs in the original.  The
 * field "where" in this table is notionally a quite separate
 * array, used to give hashed access to compressed codes.  The table is
 * only needed at startup time and when I am dumping a checkpoint file -
 * in each case nothing else is one the stack, so since the table is
 * only 16/32 Kbytes or so I allocate it on the stack: this code is only
 * used when the stack is otherwise almost empty. Well actually
 * with the introduction of the (checkpoint) function that can be
 * used to dump images whatever else is going on the stack may not
 * be so empty after all. I will nevertheless continue to allocate
 * my buffers on it.
 */
    unsigned char pair_c[CODESIZE];                     /* 4 Kbytes   */
    unsigned short int pair_prev[CODESIZE], pair_where[CODESIZE];
                                                        /* 16 Kbytes  */
    unsigned char *p = (unsigned char *)a;
    int32_t n = size, i;
    uint32_t prev1;
    int hash, step, half;
    unsigned int next_code, prev, c;

    if (size < compression_worth_while)
    {   if (size != 0) Iwrite(a, size);
        return;
    }
/*
 * Clear the hash table and indicate that the next code to allocate is 256
 */
    memset(pair_where, 0, sizeof(pair_where));
    next_code = 256;
/*
 * I deal with the first two characters by hand since they can not be
 * subject to compression.  After these first two I can apply uniform
 * processing.
 */
    prev = *p++;
    c = *p++;
/*
 * The hash function I use is not especially scientific, but a couple of
 * exclusive-or operations and a shift will be cheap to compute, and I
 * can eventually expect prev to be fairly evenly distributed, while the
 * distribution of c depends a lot on what sort of data is in the file.
 */
    hash = prev ^ c ^ (c << 5);
    prev1 = ((uint32_t)hash << 20) | ((uint32_t)prev << 8) | c;
    Iputc(prev >> 4);
    half = prev & 0xf;
    prev = c;
    for (i=2; i<n; i++)
    {   c = *p++;
        hash = (prev ^ c ^ (c << 5)) & 0xfff;
        step = (prev - (c << 4)) | 1;
/*
 * I compute a hash value, and also a secondary hash to be used when
 * making repeated probes.  Since the table has size that is a power of
 * two I will be OK provided by step is an odd number.  When I am finished
 * the table will have 4096-256 entries in it, i.e. it will be 94% full,
 * so access to it will take about 16 probes to discover that some
 * item is not present.
 */
        for (;;)
        {   int where = pair_where[hash];
            if (where == 0) break;
            if (pair_prev[where] == prev &&
                pair_c[where] == c)
            {   prev = where;       /* squash 2 chars together            */
                hash = -1;          /* set a flag to indicate it was done */
                break;
            }
            hash = (hash + step) & 0xfff;
        }
        if (hash >= 0)
        {
/*
 * There is a delicacy here - so that the uncompression process can
 * build its decoding tables on the fly I must delay entering items into
 * the compression tables by about one character of output.  This is
 * achieved by keeping details of what is to be inserted stored in the
 * variable "prev1", which is activated here.
 * When all 4096 codes have been allocated I just flush out the
 * table and start afresh. A scheme that started with 9-bit chunks and
 * grew up to use longer ones up to (say) 15 or 16 bits could give
 * significantly better compression, but at the cost of both more
 * workspace here and (what is more to the point) seriously extra
 * overhead picking bit-fields of variable length out of the stream of
 * bytes in files.
 */
            if (next_code >= CODESIZE)
            {   memset(pair_where, 0, sizeof(pair_where));
                next_code = 256;
            }
            else
            {   pair_where[prev1 >> 20] = (unsigned short int)next_code;
                pair_prev[next_code] =
                    (unsigned short int)(prev1 >> 8) & 0xfff;
                pair_c[next_code] = (unsigned char)prev1;
                next_code++;
            }
/*
 * Now the mess of collecting 12 bit items and paching them into sequences
 * of 8 bit bytes.
 */
            if (half < 0)
            {   Iputc(prev >> 4);
                half = prev & 0xf;
            }
            else
            {   Iputc((half << 4) | ((prev >> 8) & 0xf));
                Iputc(prev);
                half = -1;
            }
/*
 * record the information that the decoder will in due course see.
 */
            prev1 = ((uint32_t)hash << 20) | ((uint32_t)prev << 8) | c;
            prev = c;
        }
    }
/*
 * Now I have to flush out the final buffered character
 */
    if (half < 0)
    {   Iputc(prev >> 4);
        Iputc(prev << 4);
    }
    else
    {   Iputc((half << 4) | ((prev >> 8) & 0xf));
        Iputc(prev);
    }
}

#endif /* DEMO_MODE */

/*
 * These routines pack multiple binary files into one big one.  The
 * good effect is that I expect fseek to be faster than fopen, and as
 * a result accessing fasl files will be faster.  The bad news is that
 * when I update files I may need to compact them, and doing so will
 * be very tedious.  In this model I do not permit arbitrary interleaving
 * of read and write operations.
 */

static void set_dirused(directory_header *h, int v)
{
    h->dirused = (unsigned char)(v & 0xff);
    h->dirext = (unsigned char)((h->dirext & 0xf0) + ((v>>8) & 0x0f));
}

static directory empty_directory =
{
/*
 * This statically allocated "directory" exists to use as a fall-back if
 * it proves impossible to allocate space for a genuine directory record.
 * Thus it only comes into play in situations when I am in the process
 * of failing fairly drastically!
 */
    {'C', MIDDLE_INITIAL, 'L', IMAGE_FORMAT_VERSION,
      0, 0, 0, 0,
      {0, 0, 0, 0}},
    NULL,
    NULL,
    "EmptyFile",
    {{"\nEmpty       ** *** not dated *** **"}}
};

/*
 * In a way that may look clumsy I store file offsets and lengths as
 * sequences of three or four characters.  The object of this
 * explicit control over memory layout is so that directories produced by
 * this code have a layout that is not sensitive to the byte-order used
 * by the computer involved.  I also put a few newline characters into
 * my directory structure so that if one uses an ordinary text editor to
 * inspect an image file the set of modules and their datestamps should
 * be easily visible.
 */

static int32_t bits32(char *v)
{
    int32_t r = v[3] & 0xff;
    r = (r << 8) | (v[2] & 0xff);
    r = (r << 8) | (v[1] & 0xff);
    return (r << 8) | (v[0] & 0xff);
}

static int32_t bits24(char *v)
{
    int32_t r = v[2] & 0xff;
    r = (r << 8) | (v[1] & 0xff);
    return (r << 8) | (v[0] & 0xff);
}

static void setbits32(char *v, int32_t r)
{
    *v++ = (char)r;
    *v++ = (char)(r >> 8);
    *v++ = (char)(r >> 16);
    *v   = (char)(r >> 24);
}

static void setbits24(char *v, int32_t r)
{
    *v++ = (char)r;
    *v++ = (char)(r >> 8);
    *v   = (char)(r >> 16);
}

static directory *current_input_directory;   /* not used! */
static int nativedir = 0;
static directory_entry *current_output_entry;
static directory *current_output_directory = NULL;
static CSLbool any_output_request;
static char would_be_output_directory[DIRNAME_LENGTH];

#define I_INACTIVE 0
#define I_READING  1
#define I_WRITING  2

static int Istatus = I_INACTIVE;

FILE *binary_read_file;
static FILE *binary_write_file;
static uint32_t subfile_checksum;
static long int read_bytes_remaining, write_bytes_written;
directory *fasl_files[MAX_FASL_PATHS];

static directory *make_empty_directory(char *name)
/*
 * The sole purpose of this empty directory is to carry with it the
 * name of the file that I had tried to open.
 */
{
    directory *d;
    d = (directory *) malloc(sizeof(directory) - sizeof(directory_entry));
    if (d == NULL) return &empty_directory;
    d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
    d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    d->h.dirsize = 0;
    d->h.dirused = 0;
    d->h.dirext = 0;
    d->h.updated = 0;   /* NB read-only */
    d->f = NULL;
    strncpy(d->filename, name, DIRNAME_LENGTH);
    d->filename[DIRNAME_LENGTH-1] = 0;
    memset(d->h.eof, 0, 4);
    return d;
}

static directory *make_pending_directory(char *name, int pds)
{
    directory *d;
    int n = sizeof(directory) + (DIRECTORY_SIZE-1)*sizeof(directory_entry);
    int l = strlen(name) + 1 -
            DIRNAME_LENGTH -
            DIRECTORY_SIZE*sizeof(directory_entry);
/*
 * Here I extend the directory header with enough extra bytes to hold the
 * full name of the file... Once the file has been opened the (potential)
 * extra data becomes unnecessary. However with room for DIRECTORY_SIZE
 * entries already it would seem bizarre if the path-name ever actually
 * overflowed here.
 */
    if (l > 0) n += l;
    d = (directory *)malloc(n);
    if (d == NULL) return &empty_directory;
    d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
    d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    d->h.dirsize = DIRECTORY_SIZE & 0xff;
    d->h.dirused = 0;
    d->h.dirext = (DIRECTORY_SIZE >> 4) & 0xf0;
    d->h.updated = D_PENDING | D_WRITE_OK;
        /* Well I HOPE that writing will be OK */
    d->f = NULL;
    strcpy(d->filename, name);  /* guaranteed enough space here */
    if (pds) d->full_filename = NULL;
    else
    {   char *s = (char *)malloc(strlen(name)+1);
/* Ought to check for NULL here */
        strcpy(s, name);
        d->full_filename = s;
    }
    memset(d->h.eof, 0, 4);
    return d;
}

static directory *make_native_directory(char *shortname, char *fullname, int ro)
{
    directory *d;
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
/* Ought to check for NULL here */
        strcpy(s, fullname);
        d->full_filename = s;
    }
    memset(d->h.eof, 0, 4);
    return d;
}

static void clear_entry(directory_entry *d)
{
    d->D_newline = NEWLINE_CHAR;
    memset(&d->D_name, ' ', name_size);
    memcpy(&d->D_name, "<Unused>", 8); 
    memset(&d->D_date, ' ', date_size);
    (&d->D_date)[0] = '-';
    memset(&d->D_position, 0, 4);
    memset(&d->D_size, 0, 3);
}

static CSLbool version_moan(int v)
{
/*
 * My intent here is to arrange that 64-bit machines can load 32-bit images
 * but I will not support the vice-versa variant on that. The top bit
 * of my "image format version" field will be used to indicate whether the
 * image is a 32 or 64-bit one. That ought only to influence the format
 * of major heap image dumps - general compiled FASL modules ought not to
 * be word-length sensitive.
 */
    if (!SIXTY_FOUR_BIT && ((v & 0x80) != 0))
    {   term_printf("+++++ This image file seems to be built for use with a 64-bit\n");
        term_printf("+++++ version of the software. Please check it by re-installing\n");
        term_printf("+++++ or re-building.\n");
        term_printf("+++++ You are at present running in a 32-bit environment.\n");
        return YES;
    }
#if defined DEMO_MODE || defined DEMO_BUILD
    if ((v & 0x7f) == 'd') return NO;
    term_printf("\n");
    term_printf("+++++ This image file is either corrupted or was not\n");
    term_printf("+++++ built for use with the Demonstration version.\n");
    term_printf("+++++ Unable to proceed - sorry.\n");
#else
    if ((v & 0x7f) == IMAGE_FORMAT_VERSION) return NO;
    term_printf("\n");
    if ((v & 0x7f) == 'd')
    {   term_printf("+++++ This image file was built for use with the Demonstration\n");
        term_printf("+++++ version of this software and can not be used with the\n");
        term_printf("+++++ full product.\n");
    }
    else
    {    }
#endif
    return YES;
}

directory *open_pds(char *name, int mode)
/*
 * Given a file-name, open the associated file, make space for
 * a directory and return same. This now has to detect if the file-name
 * should refer to a directory rather than a composite file. This case
 * arises if the file that is named already exists and is a directory OR
 * if it does not exist and its name it specified with a trailing "/".
 * The mode is one of PDS_INPUT, PDS_OUTPUT or PDS_PENDING where the last
 * sets up for an output directory that must be created on first use.
 */
{
    char expanded[LONGEST_LEGAL_FILENAME];
    directory hdr, *d;
    CSLbool write_OK = NO, fileExists, nameDir, fileDir;
    struct stat buf;
    FILE *f;
    int l, i, n;
#ifdef DEMO_MODE
    mode = PDS_INPUT;
#endif
    l = strlen(name);
    nameDir = (name[l-1] == '/') || (name[l-1] == '\\');
    f = NULL;
    process_file_name(expanded, name, l);
    i = strlen(expanded) - 1;
    if (expanded[i] == '/' ||
        expanded[i] == '\\') expanded[i] = 0; /* Trim any final "/" */
    fileExists = fileDir = NO;
    if (stat(expanded, &buf) != -1)
    {   fileExists = YES;
        if ((buf.st_mode & S_IFMT) == S_IFDIR) fileDir = YES;
    }
    if (nameDir && fileExists && !fileDir)
        return make_empty_directory(expanded);
    if (mode != PDS_INPUT)
    {   any_output_request = YES;
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
        if (f != NULL) write_OK = YES;
        else if (mode == PDS_PENDING)
        {   f = fopen(expanded, "rb");
            if (f == NULL) return make_pending_directory(expanded, !nameDir);
        }
        else
        {   f = fopen(expanded, "w+b");
            if (f != NULL) write_OK = YES;
        }
    }
/*
 * If I wanted the file for input or if I tried it for output and failed
 * then I open for input.
 */
    if (f == NULL)
    {   if (!fileExists) return make_empty_directory(expanded);
        if (fileDir) return make_native_directory(name, expanded, 1);
        f = fopen(expanded, "rb");
    }
/*
 * If the file does not exist I will just hand back a directory that shows
 * no files in it.  This seems as easy a thing to do at this stage as I can
 * think of.  Maybe I should warn the user?
 */
    if (f == NULL) return make_empty_directory(expanded);
    fseek(f, 0, SEEK_SET);     /* Ensure I am at start of the file */
    hdr.h.C = hdr.h.S = hdr.h.L = 0;
    if (fread(&hdr.h, sizeof(directory_header), 1, f) != 1 ||
        hdr.h.C != 'C' ||
        hdr.h.S != MIDDLE_INITIAL ||
        hdr.h.L != 'L' ||
/*
 * Image format versions are somewhat delicate things. I will not change
 * this format often or lightly and the tests I make will then be set up to
 * cope with updates from the immediately previous version. The testing code
 * will need review each time I consider such a change. For the current
 * upgrade I will allow opening of files from version N-1, but I will
 * specifically lock out reading an initial heap-image from such. The issue
 * of people who start with an old file and then write a fresh image back into
 * it will be viewed as too messy to worry about in detail, but I hope that
 * I have made it so that writing a new base image (via PRESERVE) updates the
 * version info.
 */
        version_moan(hdr.h.version) ||
        get_dirused(hdr.h) > get_dirsize(hdr.h) ||
        bits32(hdr.h.eof) < sizeof(directory_header))
    {
/*
 * Here I did not find a satisfactory header to the directory.  If I wanted
 * to open the file for input I just return an empty directory, otherwise I
 * need to create a new one.
 */
        if (!write_OK) return make_empty_directory(expanded);
        fseek(f, 0, SEEK_SET);
        n = DIRECTORY_SIZE;      /* Size for a directory */
        d = (directory *)
            malloc(sizeof(directory)+(n-1)*sizeof(directory_entry));
        if (d == NULL) return &empty_directory;
        d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
        d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
        d->h.dirsize = (unsigned char)(n & 0xff);
        d->h.dirused = 0;
        d->h.dirext = (unsigned char)((n >> 4) & 0xf0);
        d->h.updated = D_WRITE_OK | D_UPDATED;
        d->full_filename = NULL;  /* A PDS not a native dircetory */
        for (i=0; i<n; i++) clear_entry(&d->d[i]);
        if (fwrite(&d->h, sizeof(directory_header), 1, f) != 1)
            return make_empty_directory(expanded);
        if (fwrite(&d->d[0], sizeof(directory_entry), (size_t)n, f) != (size_t)n)
            return make_empty_directory(expanded);
        d->f = f;
        strncpy(d->filename, expanded, DIRNAME_LENGTH);
        d->filename[DIRNAME_LENGTH-1] = 0;
        if (fwrite(registration_data, REGISTRATION_SIZE, 1, f) != 1)
            return make_empty_directory(expanded);
        setbits32(d->h.eof, (int32_t)ftell(f));
        return d;
    }
    hdr.h.updated = write_OK ? D_WRITE_OK : 0;
    n = get_dirsize(hdr.h);
    d = (directory *)
        malloc(sizeof(directory)+(n-1)*sizeof(directory_entry));
    if (d == NULL) return &empty_directory;
    memcpy(&d->h, &hdr.h, sizeof(directory_header));
    if (fread(&d->d[0], sizeof(directory_entry), (size_t)n, f) != (size_t)n)
        return make_empty_directory(expanded);
/*
 * Here the directory seemed OK
 */
    d->f = f;
    strncpy(d->filename, expanded, DIRNAME_LENGTH);
    d->filename[DIRNAME_LENGTH-1] = 0;
    d->full_filename = NULL;
/*
 * For binary files ANSI specify that the values used with fseek and ftell
 * are simple counts of the number of characters in the file, and hence
 * it is proper to save ftell() values from one run to the next.
 */
    return d;
}

static int unpending(directory *d)
{
    FILE *f;
    int32_t i, n;
    if (d->full_filename != NULL)
    {   Cmkdir(d->full_filename);
        d->h.updated &= ~D_PENDING;
        d->h.updated |= D_WRITE_OK;  /* suppose directories always updatable */
        return NO;
    }
    f = fopen(d->filename, "w+b");
    if (f == NULL) return YES;
    d->f = f;
    d->filename[DIRNAME_LENGTH-1] = 0;  /* truncate the name now */
    n = DIRECTORY_SIZE;      /* Size for a directory */
/* (the next bits were done when the pending directory was first created
    d->h.C = 'C'; d->h.S = MIDDLE_INITIAL; d->h.L = 'L';
    d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    d->h.dirsize = n & 0xff;
    d->h.dirused = 0;
    d->h.dirext = (n >> 4) & 0xf0;
 */
    d->h.updated = D_WRITE_OK | D_UPDATED;
    for (i=0; i<n; i++) clear_entry(&d->d[i]);
    if (fwrite(&d->h, sizeof(directory_header), 1, f) != 1)
        return YES;
    if (fwrite(&d->d[0], sizeof(directory_entry), (size_t)n, f) != (size_t)n)
        return YES;
    if (fwrite(registration_data, REGISTRATION_SIZE, 1, f) != 1)
        return YES;
    setbits32(d->h.eof, (int32_t)ftell(f));
    return NO;
}

void Iinit(void)
{
    int i;
    Istatus = I_INACTIVE;
    current_input_directory = NULL;
    current_output_entry = NULL;
    current_output_directory = NULL;
    binary_read_file = binary_write_file = NULL;
    read_bytes_remaining = write_bytes_written = 0;
    any_output_request = NO;
    strcpy(would_be_output_directory, "<unknown>");
    for (i=0; i<number_of_fasl_paths; i++)
    {   if (0x40000000+i == output_directory)
            fasl_files[i] = open_pds(fasl_paths[i], PDS_PENDING);
        else
            fasl_files[i] = open_pds(fasl_paths[i],
                                     i == output_directory ? PDS_OUTPUT :
                                                             PDS_INPUT);
    }
    CSL_MD5_Update((unsigned char *)"Copyright 2008 Codemist Ltd", 24);
}

void Icontext(Ihandle *where)
/*
 * This and the next are used so that reading from binary files can be
 * nested, as may be needed while loading fasl files. An Ihandle should
 * be viewed as an abstract handle on the input stream.  Beware however that
 * if input is from a regular Lisp stream (indicated by read_bytes_remaining
 * being negative) that standard_input is NOT saved here. Therefore in
 * some cases it needs to be stacked elsewhere. The reason I do not save
 * it here is that it is a Lisp_Object and needs garbage collection
 * protection, which is not easily provided here.
 */
{
    switch (where->status = Istatus)
    {
case I_INACTIVE:
        break;
case I_READING:
        where->f = binary_read_file;
        if (read_bytes_remaining >= 0) where->o = ftell(binary_read_file);
        where->n = read_bytes_remaining;
        where->chk = subfile_checksum;
        where->nativedir = nativedir;
        break;
case I_WRITING:
        where->f = binary_write_file;
        where->o = ftell(binary_write_file);
        where->n = write_bytes_written;
        where->chk = subfile_checksum;
        where->nativedir = nativedir;
        break;
    }
    Istatus = I_INACTIVE;
}

void Irestore_context(Ihandle x)
{
    switch (Istatus = x.status)
    {
case I_INACTIVE:
        return;
case I_READING:
        binary_read_file = x.f;
        read_bytes_remaining = x.n;
        if (read_bytes_remaining >= 0) fseek(binary_read_file, x.o, SEEK_SET);
        subfile_checksum = x.chk;
        nativedir = x.nativedir;
        return;
case I_WRITING:
        binary_write_file = x.f;
        fseek(binary_write_file, x.o, SEEK_SET);
        write_bytes_written = x.n;
        subfile_checksum = x.chk;
        nativedir = x.nativedir;
        return;
    }
}

#define IMAGE_CODE  (-1000)
#define HELP_CODE   (-1001)
#define BANNER_CODE (-1002)

/*
 * The code here was originally written to support module names up to
 * 11 characters, but it has now been extended to support long names as
 * well.
 * The mechanism used is as follows:
 * The name field in a directory entry is 12 characters long. For system
 * special pseudo-modules all 12 characters are used for a name, and the
 * cases used at present are InitialImage and HelpDataFile. For all
 * user names the name is padded with blanks, and so user names of up
 * to 11 characters live in the field with the 12th character a blank.
 * To support long names I use values 0x80 and up in this 12th position.
 * (NB position 12 is at offset 11 because of zero-base counting!)
 * The first segment of a long name uses 11 characters of the user name
 * and puts 0x80 in the 12th. Subsequent directory entries are used
 * to hold more characters of the name. These hold 11 characters in the
 * name field and 24 in the date, and put values 0x81, 0x82 etc in
 * character 12. They will have a zero length field, but their position
 * field MUST match that of the first record. This requirement is so that
 * when I sort a directory the parts of a long name are kept both
 * together and in the correct order. The last part of a long name has
 * 0xff in position 12. The result is that I can distinguish the case
 * of
 * (.) a regular username of up to 11 chars (blank in position 12)
 * (.) a system special file (non-blank, but under 0x80 in posn 12)
 * (.) the start of a long name (0x80)
 * (.) a middle part of a long name (0x81 ...)
 * (.) the final part of a long name (0xff).
 * when I match names here I will only allow a long-name match if my
 * directory is pointing at the first part of a long name.
 * As a further minor usefulness here if I find a match the non-zero value I
 * return is the number of entries involved.
 * I will store native-compiled object code as well as my own bytecoded
 * stuff. For a module names xxx and architecture yyy I will store the
 * data under the name xxx/yyy taking the view that "/" is a character that
 * ought not to appear in the name of a module. That can mean I have (eg)
 * directory entries here for "compiler" (the byte-coded file),
 * "compiler/i386", "compiler/x86_64" and "compiler/win32" which would contain
 * object-files (*.dll or *.so) for Intel Linux, 64-bit Linux and Windows.
 */

static int samename(char *n1, directory *d, int j, int len)
/*
 * Compare the given names, given that n1 is of length len and n2 is
 * blank-padded to exactly name_size characters. The special cases
 * with n1 NULL allow len to encode what I am looking for.
 */
{
    char *n2 = &d->d[j].D_name;
    int i, n, recs;
    if (len == IMAGE_CODE)
        return (memcmp(n2, "InitialImage", 12) == 0);
    if (len == HELP_CODE)
        return (memcmp(n2, "HelpDataFile", 12) == 0);
    if (len == BANNER_CODE)
        return (memcmp(n2, "Start-Banner", 12) == 0);
    if (len < 0)
    {   char hard[16];
        sprintf(hard, "HardCode<%.2x>", (-len) & 0xff);
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
    } while ((n2[11] & 0xff) != 0xff);
#undef next_char_of_name
    if (n < len) return 0;
    else return recs;
}

static void fasl_file_name(char *nn, directory *d, char *name, int len)
{
    int np;
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
        else if (len < 0) sprintf(&nn[np], "HardCode-%.2x", (-len) & 0xff);
    }
    else
    {   memcpy(&nn[np], name, len);
        strcpy(&nn[np+len], ".fasl");
    }
}


static CSLbool open_input(directory *d, char *name, int len,
                          int32_t offset, int checked)
/*
 * Set up binary_read_file to access the given module, returning YES
 * if it was not found in the given directory. I used to pass the
 * names "InitialImage" and "HelpDataFile" directly to this function, but
 * to allow for long module names I am changing things so that these special
 * cases are indicated by passing down a NULL string for the name and giving
 * an associated length of -1 or -2 (resp).
 * If the file will have a checksum at its end then "checked" will be true
 * here.
 */
{
    int i;
    if (Istatus != I_INACTIVE || d == NULL) return YES;
    subfile_checksum = 0;
    nativedir = NO;
    if (d->full_filename != NULL) /* native directory mode */
    {   char nn[LONGEST_LEGAL_FILENAME];
        fasl_file_name(nn, d, name, len);
        if ((binary_read_file = fopen(nn, "rb")) == NULL) return YES;
        fseek(binary_read_file, 0L, SEEK_END);
        read_bytes_remaining = ftell(binary_read_file);
        if (checked) read_bytes_remaining -= 4;
        fseek(binary_read_file, (long)offset, SEEK_SET);
        Istatus = I_READING;
        nativedir = YES;
        return NO;
    }
/*
 * I use simple linear search to scan the directory - mainly because I
 * expect directories to be fairly small and once I have found a file
 * I will take a long while to process it, so any clumsiness here is
 * not critical.
 * This linear search may not be so smart any more, in that REDUCE ends
 * up with about 750 modules, and if I store machine code versions of all
 * of these for (say) 4 architectures I end up with almost 4000 directory
 * entries...
 * I will not allow myself to read from whichever file is currently open
 * for output.
 * Because samename() is careful to ensure it only reports a match when
 * pointed at the start of a long name it is OK to search in steps of 1
 * here.
 */
    for (i=0; i<get_dirused(d->h); i++)
    {   if (samename(name, d, i, len) &&
            &d->d[i] != current_output_entry)
        {   binary_read_file = d->f;
            read_bytes_remaining = bits24(&d->d[i].D_size);
            i = fseek(binary_read_file,
                      bits32(&d->d[i].D_position)+offset, SEEK_SET);
            if (i == 0)     /* If fseek succeeded  it returned zero */
            {   Istatus = I_READING;
                return NO;
            }
            else return YES;
        }
    }
    return YES;
}

void IreInit(void)
{
    CSL_MD5_Update((unsigned char *)"Copyright 2008 Codemist Ltd", 24);
    CSL_MD5_Update((unsigned char *)"memory.u", 8);
}

static int MS_CDECL for_qsort(void const *aa, void const *bb)
{
    directory_entry *a = (directory_entry *)aa,
                    *b = (directory_entry *)bb;
    long int ap = bits32(&a->D_position), bp = bits32(&b->D_position);
    if (ap < bp) return -1;
    else if (ap > bp) return 1;
/*
 * I make the position of the module in the image my primary sort key.
 * Over-long module names are coped with by giving each part of the
 * name the same position field, but marking the 12th character of the
 * name field (D_space) with 0x80, 0x81 ... in extension records. Note that
 * a regular short module name has a blank character there, while the special
 * cases of "InitialImage" and "HelpDataFile" each have 'e' there,
 * "Start-Banner" has 'r', while hard code has '>'.
 * So bytes 0x80 and up are clearly (if hackily!) distinguished.
 */
    ap = a->D_space & 0xff, bp = b->D_space & 0xff;
    if (ap < bp) return -1;
    else if (ap > bp) return 1;
    else return 0;
} 

static void sort_directory(directory *d)
{
    qsort((void *)d->d, (size_t)get_dirused(d->h),
          sizeof(directory_entry), for_qsort);
}

static directory *enlarge_directory(int current_size)
{
    nil_as_base
    int n = (3*current_size)/2;
    int newsize = sizeof(directory)+(n-1)*sizeof(directory_entry);
    int newpos = sizeof(directory_header)+n*sizeof(directory_entry);
/*
 * enlarge_directory() is only called when an output library is known
 * to exist, so I do not need to check for that here.
 */
    int dirno = library_number(qvalue(output_library));
    directory *d1 = fasl_files[dirno];
    if (n > current_size+20) n = current_size+20;
    for (;;)
    {   directory_entry *first;
        FILE *f;
        char buffer[512];  /* I hope this is not done too often, since this */
                           /* is not a very big buffer size for the copy.   */
        int32_t firstpos, firstlen, newfirst, eofpos;
        sort_directory(d1);
        first = &d1->d[0];
        firstpos = bits32(&first->D_position);
        if (firstpos >= newpos + REGISTRATION_SIZE) break;
/*
 * Here I need to copy a module up to the end of the file to make room
 * for the enlarged directory
 */
        firstlen = bits24(&first->D_size);
        newfirst = eofpos = bits32(d1->h.eof);
        f = d1->f;
        firstlen += 4;  /* Allow for the checksum */
        while (firstlen >= sizeof(buffer))
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
            } while ((first->D_space & 0xff) != 0xff);
        }
        setbits32(d1->h.eof, eofpos);
    }
    fseek(d1->f, newpos, SEEK_SET);
    fwrite(registration_data, REGISTRATION_SIZE, 1, d1->f);
    d1 = (directory *)realloc((void *)d1, newsize);
    if (d1 == NULL) return NULL;
    d1->h.dirsize = (unsigned char)(n & 0xff);
    d1->h.dirext = (unsigned char)((d1->h.dirext & 0x0f) + ((n>>4) & 0xf0));
    d1->h.updated |= D_COMPACT | D_UPDATED;
    while (n>current_size) clear_entry(&d1->d[--n]);
    fasl_files[dirno] = d1;
    return d1;
}

CSLbool open_output(char *name, int len)
/*
 * Set up binary_write_file to access the given module, returning YES
 * if anything went wrong. Remember name==NULL for initial image & help
 * data.
 */
{
#ifdef DEMO_MODE
    return YES;
#else
    nil_as_base
    int i, j, n;
    char *ct;
    char hard[16];
    directory *d;
    time_t t = time(NULL);
    Lisp_Object oo = qvalue(output_library);
    nativedir = NO;
    if (!is_library(oo)) return YES;
    d = fasl_files[library_number(oo)];
    if (d == NULL) return YES;  /* closed handle, I guess */
    if ((d->h.updated & D_WRITE_OK) == 0) return YES;
/*
 * The main effect of the next line will be to prohibit opening a new
 * FASL file while I am in the middle of reading one that already exists.
 * Indeed this is a restriction, but at present it seems a very reasonable
 * on for me to apply.
 */
    if (Istatus != I_INACTIVE) return YES;
    if (d->h.updated & D_PENDING)
    {
/*
 * See comments in fasl.c under Lbanner for why I choose to report a failure
 * rather then do and unpending() when the output module I am creating is
 * just to contain banner information. 
 */
        if (name==NULL && len==BANNER_CODE) return YES;
        if (unpending(d)) return YES;
    }
    subfile_checksum = 0;
    current_output_directory = d;
    if (d->full_filename != NULL) /* native directory mode */
    {   char nn[LONGEST_LEGAL_FILENAME];
        fasl_file_name(nn, d, name, len);
        if ((binary_write_file = fopen(nn, "wb")) == NULL) return YES;
        write_bytes_written = 0;
        Istatus = I_WRITING;
        nativedir = YES;
        return NO;
    }
/*
 * I use simple linear search to scan the directory - mainly because I
 * expect directories to be fairly small and once I have found a file
 * I will take a long while to process it, so any clumsiness here is
 * not critical. Again note it is OK to scan in steps of 1 despite the
 * fact that long-names are stored split across consecutive directory slots.
 */
    for (i=0; i<get_dirused(d->h); i++)
    {   if (samename(name, d, i, len))
        {   current_output_entry = &d->d[i];
            d->h.updated |= D_COMPACT | D_UPDATED;
            if (t == (time_t)(-1)) ct = "not dated";
            else ct = ctime(&t);
/*
 * Note that I treat the result handed back by ctime() as delicate, in that
 * I do not do any library calls between calling ctime and copying the
 * string it returns to somewhere that is under my own control.
 */
            strncpy(&d->d[i].D_date, ct, date_size);
            binary_write_file = d->f;
            write_bytes_written = 0;
            memcpy(&d->d[i].D_position, d->h.eof, 4);
/* For long names I must put the location in each record */
            if (d->d[i].D_space & 0x80)
            {   j = 0;
                do
                {   j++;
                    memcpy(&d->d[i+j].D_position, d->h.eof, 4);
                } while ((d->d[i+j].D_space & 0xff) != 0xff);
            }
            i = fseek(binary_write_file, bits32(d->h.eof), SEEK_SET);
            if (i == 0) Istatus = I_WRITING;
            else current_output_directory = NULL;
            if (name == NULL && len == IMAGE_CODE)
                d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
            return i;
        }
    }
/*
 * Here the name did not already exist, and so I will need to enter it into
 * the directory.  If I get here the variable i points to the first unused
 * directory entry.
 */
    if (len == IMAGE_CODE) 
    {   name = "InitialImage";
        n = 1;
        d->h.version = IMAGE_FORMAT_VERSION | (SIXTY_FOUR_BIT ? 0x80 : 0);
    }
    else if (len == HELP_CODE) name = "HelpDataFile", len = IMAGE_CODE, n = 1;
    else if (len == BANNER_CODE) name = "Start-Banner", len = IMAGE_CODE, n = 1;
    else if (len < 0)
    {   sprintf(hard, "HardCode<%.2x>", (-len) & 0xff);
        name = hard, len = IMAGE_CODE, n = 1;
    }
    else if (len <= 11) n = 1;
    else if (len <= 11+11+24) n = 2;
    else if (len <= 11+11+11+24+24) n = 3;
    else return YES;  /* Name longer than 81 chars not supported, sorry */
    while (i+n > (int)get_dirsize(d->h))
    {   d = enlarge_directory(i);
        current_output_directory = d;
        if (d == NULL) return YES;
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
    {   int np;
        char *p;
/*
 * First I will clear all the relevant fields to blanks.
 */
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
        return NO;
    }
    else
    {   current_output_directory = NULL;
        return YES;
    }
#endif /* DEMO_MODE */
}

static void list_one_native(const char *name, int why, long int size)
{
    struct stat statbuff;
    char shortname[100];
    char *p;
    if (why != SCAN_FILE) return;
    stat(name, &statbuff);      /* read the date on the file */
    while (*name != 0) name++;
/*
 * I need a comment about why the loop on the next line is guaranteed to
 * terminate. Well I only ought to be executing this code if the image
 * is represented as an operating-system directory, and when scan_directory
 * inspects it all the files in it are within it (gee!) and so have names
 * along the line of "csl.img/compat.fasl". So I really do expect to find
 * a directory separator character within the name.
 */
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


static void list_one_library(Lisp_Object oo, CSLbool out_only)
{
    int j;
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
/*
 * The format string used here will need adjustment if you ever change the
 * number of characters used to store names or dates.
 */
    for (j=0; j<get_dirused(d->h); j++)
    {   int n = 0;
        if (d->d[j].D_space & 0x80)
        {   trace_printf("    %.11s", &d->d[j].D_name);
            do
            {   n++;
                trace_printf("%.11s%.24s",
                    &d->d[j+n].D_name, &d->d[j+n].D_date);
            } while ((d->d[j+n].D_space & 0xff) != 0xff);
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
{
    Lisp_Object nil = C_nil;
    Lisp_Object il = qvalue(input_libraries), w;
    Lisp_Object ol = qvalue(output_library);
    while (consp(il))
    {   w = qcar(il); il = qcdr(il);
        if (!is_library(w)) continue;
        if (w == ol) ol = nil;
        list_one_library(w, NO);
    }
    if (is_library(ol)) list_one_library(ol, YES);
}

static Lisp_Object mods;

static void collect_modules(const char *name, int why, long int size)
{
    int k = 0;
    Lisp_Object nil = C_nil, v;
    char *p = (char *)&celt(boffo, 0);
    if (why != SCAN_FILE) return;
    if (exception_pending()) return;
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
    errexitv();
    mods = cons(v, mods);
    errexitv();
}

Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object oo)
{
    int i, j, k;
    directory *d = fasl_files[library_number(oo)];
    Lisp_Object v, r = C_nil;
    char *p;
    if (d->full_filename != NULL)
    {   mods = C_nil;
        scan_directory(d->full_filename, collect_modules);
        errexit();
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
            } while ((d->d[j+n].D_space & 0xff) != 0xff);
            j += n;
        }
        else
        {   if (memcmp(&d->d[j].D_name, "InitialImage", 12) == 0 ||
                memcmp(&d->d[j].D_name, "HelpDataFile", 12) == 0 ||
                memcmp(&d->d[j].D_name, "Start-Banner", 12) == 0 ||
                (memcmp(&d->d[j].D_name, "HardCode<", 9) == 0 &&
                       (&d->d[j].D_name)[11] == '>'))
                continue;  /* not user modules */
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
        errexit();
        r = cons(v, r);
        errexit();
    }
    return onevalue(r);
}

Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object nil, int nargs, ...)
/*
 * This returns a list of the modules in the first library on the current
 * search path.
 */
{
    Lisp_Object il = qvalue(input_libraries), w;
    Lisp_Object ol = qvalue(output_library);
    argcheck(nargs, 0, "library-members");
    while (consp(il))
    {   w = qcar(il); il = qcdr(il);
        if (!is_library(w)) continue;
        return Llibrary_members(nil, w);
    }
    if (is_library(ol)) return Llibrary_members(nil, ol);
    else return onevalue(nil);
}

CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                             char *expanded_name)
/*
 * Hands back information about whether the given module exists, and
 * if it does when it was written.  Code should be very similar to
 * that in Iopen.
 */
{
    int i;
    Lisp_Object nil = C_nil;
    Lisp_Object il = qvalue(input_libraries);
/*
 * nil is conditionally needed for two reasons here:
 * (a) if NILSEG_EXTERNS was not selected it is needed as a base register for
 *     access to input_libraries
 * (b) if COMMON was selected it is needed for the expansion of the
 *     consp test.
 * If neither of the above apply its is redundant, but not a very greate pain.
 */
    CSL_IGNORE(nil);
    while (consp(il))
    {   int j;
        directory *d;
        Lisp_Object oo = qcar(il); il = qcdr(il);
        if (!is_library(oo)) continue;
        i = library_number(oo);
        d = fasl_files[i];
        if (d == NULL) continue;
        if (d->full_filename != NULL)
        {   char nn[LONGEST_LEGAL_FILENAME];
            struct stat statbuff;
            fasl_file_name(nn, d, name, len);
            if (stat(nn, &statbuff) != 0) continue;   /* file not present */
            strcpy(expanded_name, nn);
            strcpy(datestamp, ctime(&(statbuff.st_mtime)));
/*
 * Note that FASL modules here will surely never even start to get towards
 * the size-limits of a 32-bit integer!
 */
            *size = (int32_t)statbuff.st_size;
            return NO;
        }
        for (j=0; j<get_dirused(d->h); j++)
        {   if (samename(name, d, j, len))
            {   char *n = fasl_files[i]->filename;
                char *p1 = "(", *p2 = ")";
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
                             "%s%s%.*s%s", n, p1, len, name, p2);
                return NO;
            }
        }
    }
    return YES;
}

CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour)
/*
 * Opens the "InitialImage" file so that it can be loaded. Note that
 * when I am about to do this I do not have a valid heap image loaded, and
 * so it would NOT be possible to use the regular search-path mechanism for
 * libraries. Therefore I will just use images as specified from the
 * command line (or by default).
 */
{
    char *n;
    int i;
    if (hard == 0) hard = IMAGE_CODE;
    for (i=0; i<number_of_fasl_paths; i++)
    {   CSLbool bad;
/* Initial image files have a checksum at their end */
        bad = open_input(fasl_files[i], NULL, hard, 0, 1);
/*
 * The name that I return (for possible display in error messages) will be
 * either that of the file that was opened, or one relating to the last
 * entry in the search path.
 */
        n = fasl_files[i]->filename;
         
        if (expanded_name != NULL)
        {   if (hard == IMAGE_CODE)
            {   if (!bad)
                {   long int pos = ftell(binary_read_file);
                    directory *d = fasl_files[i];
                    unsigned char rr[REGISTRATION_SIZE];
                    int nn = get_dirsize(d->h) * sizeof(directory_entry);
                    nn += sizeof(directory_header);
                    fseek(binary_read_file, (long int)nn, SEEK_SET);
                    fread(rr, REGISTRATION_SIZE,
                          1, binary_read_file);
                    if (memcmp(rr, REGISTRATION_VERSION, 4) == 0)
                        memcpy(registration_data, rr, REGISTRATION_SIZE);
                    fseek(binary_read_file, pos, SEEK_SET);
                }
                sprintf(expanded_name, "%s(InitialImage)", n);
            }
            else if (hard == BANNER_CODE)
                sprintf(expanded_name, "%s(InitialImage)", n);
            else sprintf(expanded_name, "%s(HardCode<%.2x>)",
                                        n, (-hard) & 0xff);
        }
        if (!bad) return NO;
    }
    return YES;
}

CSLbool Iopen(char *name, int len, int forinput, char *expanded_name)
/*
 * Make file with the given name available through this package of
 * routines.  (name) is a pointer to a string (len characters valid) that
 * names a fasl file.  (forinput) specifies the direction of the transfer
 * to set up. Returns YES if something failed.
 * name can be NULL when a module is opened for output, and then output
 * is sent to "InitialImage". I need to worry about 64-bit variants in this
 * general area... 
 * The same is done for input, but it would be more sensible to use
 * IopenRoot() to access the root image.
 */
{
    char *n;
    Lisp_Object nil = C_nil;
    CSL_IGNORE(nil);
    if (name == NULL) len = IMAGE_CODE;
    if (forinput != IOPEN_OUT)
    {   int i;
        Lisp_Object il = qvalue(input_libraries);
        while (consp(il))
        {   CSLbool bad;
            Lisp_Object oo = qcar(il); il = qcdr(il);
            if (!is_library(oo)) continue;
            i = library_number(oo);
            bad = open_input(fasl_files[i], name, len,
                             0, forinput==IOPEN_CHECKED);
/*
 * The name that I return (for possible display in error messages) will be
 * either that of the file that was opened, or one relating to the last
 * entry in the search path.
 */
            n = fasl_files[i]->filename;
            if (expanded_name != NULL)
            {   char *p1 = "(", *p2 = ")";
                if (fasl_files[i]->full_filename != NULL)
                {
#ifdef WIN32
                    p1 = "\\";
#else
                    p1 = "/";
#endif
                    p2 = "";
                }
                sprintf(expanded_name, "%s%s%.*s%s", n, p1, len, name, p2);
            }
            if (!bad) return NO;
        }
        return YES;
    }
#ifndef DEMO_MODE
    if (!any_output_request)
#endif
    {   if (expanded_name != NULL)
            strcpy(expanded_name, "<no output file specified>");
        return YES;
    }
#ifndef DEMO_MODE
    n = would_be_output_directory;
    if (expanded_name != NULL)
    {
        char *p1 = "(", *p2 = ")";
        Lisp_Object oo = qvalue(output_library);
        directory *d;
        if (!is_library(oo)) return YES;
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
        else sprintf(expanded_name, "%s%s%.*s%s", n, p1, len, name, p2);
    }
    return open_output(name, len);
#endif
}

CSLbool Iwriterootp(char *expanded_name)
/*
 * Test if it will be possible to write out an image file. Used
 * by (preserve) so it can report that this would fail without actually
 * doing anything too drastic.
 */
{
#ifdef DEMO_MODE
    strcpy(expanded_name, "<demo-system>");
    return YES;
#else
    Lisp_Object nil = C_nil;
    directory *d;
    Lisp_Object oo = qvalue(output_library);
    CSL_IGNORE(nil);
    if (!any_output_request)
    {   strcpy(expanded_name, "<no output file specified>");
        return YES;
    }
    sprintf(expanded_name, "%s(InitialImage)", would_be_output_directory);
    if (!is_library(oo)) return YES;
    d = fasl_files[library_number(oo)];
    if (d == NULL) return YES;  /* closed handle, I guess */
/*
 * At present for native directories the WRITE_OK flag is left set without
 * proper checking of file access permissions.
 */
    if ((d->h.updated & D_WRITE_OK) == 0) return YES;
    if (Istatus != I_INACTIVE) return YES;
    return NO;
#endif /* DEMO_MODE */
}

CSLbool Iopen_help(int32_t offset)
/*
 * Get ready to handle the HELP subfile.  offset >= 0 will open an
 * existing help module for input and position at the given location.
 * A negative offset indicates that the help module should be opened
 * for writing.
 */
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(nil);
    if (offset >= 0)
    {   Lisp_Object il = qvalue(input_libraries);
        while (consp(il))
        {   CSLbool bad;
            Lisp_Object oo = qcar(il); il = qcdr(il);
            if (!is_library(oo)) continue;
/* No checksum on help files */
            bad = open_input(fasl_files[library_number(oo)],
                             NULL, HELP_CODE, offset, 0);
            if (!bad) return NO;
        }
        return YES;
    }
#ifdef DEMO_MODE
    return YES;
#else
    if (!any_output_request) return YES;
    return open_output(NULL, HELP_CODE);
#endif
}

CSLbool Iopen_banner(int code)
/*
 * Get ready to handle the startup banner.
 * code = 0    open for reading
 * code = -1   open for writing
 * code = -2   delete banner file
 */
{
    Lisp_Object nil = C_nil;
    CSL_IGNORE(nil);
    if (code == -2) return Idelete(NULL, BANNER_CODE);
    else if (code == 0)
    {   Lisp_Object il = qvalue(input_libraries);
        while (consp(il))
        {   CSLbool bad;
            Lisp_Object oo = qcar(il); il = qcdr(il);
            if (!is_library(oo)) continue;
/* No checksum on the banner */
            bad = open_input(fasl_files[library_number(oo)],
                             NULL, BANNER_CODE, 0, 0);
            if (!bad) return NO;
        }
        return YES;
    }
#ifdef DEMO_MODE
    return YES;
#else
    if (!any_output_request) return YES;
    return open_output(NULL, BANNER_CODE);
#endif
}

/*
 * Set up binary_read_file to read from standard input. Return YES if
 * things fail.
 */

CSLbool Iopen_from_stdin(void)
{
    if (Istatus != I_INACTIVE) return YES;
    subfile_checksum = 0;
    binary_read_file = NULL;
    read_bytes_remaining = -1;
    Istatus = I_READING;
    return NO;
}

CSLbool Iopen_to_stdout(void)
{
    if (Istatus != I_INACTIVE) return YES;
    subfile_checksum = 0;
    Istatus = I_WRITING;
    return NO;
}

CSLbool Idelete(char *name, int len)
{
#ifdef DEMO_MODE
    return YES;
#else
    nil_as_base
    int i, nrec;
    directory *d;
    Lisp_Object oo = qvalue(output_library);
    if (!is_library(oo)) return YES;
    d = fasl_files[library_number(oo)];
    if (d == NULL ||
        (d->h.updated && D_WRITE_OK) == 0 ||
        Istatus != I_INACTIVE) return YES;
    if (d->full_filename != NULL)
    {   char nn[LONGEST_LEGAL_FILENAME];
        fasl_file_name(nn, d, name, len);
        return (remove(nn) != 0);
    }
    for (i=0; i<get_dirused(d->h); i++)
    {   if ((nrec = samename(name, d, i, len)) != 0)
        {   int j;
            set_dirused(&d->h, get_dirused(d->h)-nrec);
            for (j=i; j<get_dirused(d->h); j++)
                d->d[j] = d->d[j+nrec];
/*
 * I tidy up the now-unused entry - in some sense this is a redundant
 * operation, but I think it makes the file seem neater, which may possibly
 * help avoid confusion and ease debugging.
 */
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
            return NO;
        }
    }
    return YES;
#endif /* DEMO_MODE */
}

#define update_crc(chk, c)                      \
    chk_temp = (chk << 7);                      \
    chk = ((chk >> 25) ^                        \
           (chk_temp >> 1) ^                    \
           (chk_temp >> 4) ^                    \
           (0xff & (uint32_t)c)) & 0x7fffffff;


static int validate_checksum(FILE *f, uint32_t chk1)
{
    int c;
    uint32_t chk2 = 0;
    Lisp_Object nil = C_nil;
    if (read_bytes_remaining < 0)
    {   if ((c = Igetc()) == EOF) goto failed;
        chk2 = c & 0xff;
        if ((c = Igetc()) == EOF) goto failed;
        chk2 = (chk2 << 8) | (c & 0xff);
        if ((c = Igetc()) == EOF) goto failed;
        chk2 = (chk2 << 8) | (c & 0xff);
        if ((c = Igetc()) == EOF) goto failed;
        chk2 = (chk2 << 8) | (c & 0xff);
        if (chk1 == chk2) return NO;    /* All went well */
    }
    else
    {   if ((c = getc(f)) == EOF) goto failed;
        chk2 = c & 0xff;
        if ((c = getc(f)) == EOF) goto failed;
        chk2 = (chk2 << 8) | (c & 0xff);
        if ((c = getc(f)) == EOF) goto failed;
        chk2 = (chk2 << 8) | (c & 0xff);
        if ((c = getc(f)) == EOF) goto failed;
        chk2 = (chk2 << 8) | (c & 0xff);
        if (chk1 == chk2) return NO;    /* All went well */
    }
failed:
    if (error_output != 0)
        err_printf("\n+++ FASL module checksum failure (%.8x vs. %.8x)\n",
                   chk2, chk1);
    return YES;
}

#ifndef DEMO_MODE

static int put_checksum(FILE *f, uint32_t chk)
{
    Lisp_Object nil = C_nil;
/*
 * NB that while I am writing out the root section of a checkpoint image
 * I will have unadjusted all Lisp variables, and in particular this will
 * mean that anything that used to have the value NIL will then be
 * SPID_NIL instead. Part of what I should remember here is that
 * in consequence I can not send a main image to a Lisp stream. But I
 * think that is OK, since the only way I have of setting up fasl_stream
 * is via the FASLOUT mechanism.
 */
    if (fasl_stream != nil && fasl_stream != SPID_NIL)
    {   putc_stream((int)(chk>>24), fasl_stream);
        putc_stream((int)(chk>>16), fasl_stream);
        putc_stream((int)(chk>>8), fasl_stream);
        putc_stream((int)chk, fasl_stream);
        return NO;
    }
    if (putc((int)(chk>>24), f) == EOF) return YES;
    if (putc((int)(chk>>16), f) == EOF) return YES;
    if (putc((int)(chk>>8), f)  == EOF) return YES;
    return (putc((int)chk, f) == EOF);
}

#endif /* DEMO_MODE */

CSLbool Icopy(char *name, int len)
/*
 * Find the named module in one of the input files, and if the place that
 * it is found is not already the output file copy it to the output. These days
 * either (or neither or both!) the places could be either my own 1-file
 * image-files or they could be native directories. But for now I will just
 * ignore that and only support the older situation. That is because I am lazy!
 */
{
#ifdef DEMO_MODE
    return YES;
#else
    int i, ii, j, n;
    long int k, l, save = read_bytes_remaining;
    uint32_t chk1;
    char hard[16];
    directory *d, *id;
    Lisp_Object nil = C_nil;
    Lisp_Object il, oo = qvalue(output_library);
    CSL_IGNORE(nil);
    if (!is_library(oo)) return YES;
    d = fasl_files[library_number(oo)];
/*
 * Only valid if there is an output file and nothing else is going on.
 */
    if (d == NULL ||
        (d->h.updated & D_WRITE_OK) == 0 ||
        Istatus != I_INACTIVE) return YES;
    if (d->h.updated & D_PENDING)
    {   if (unpending(d)) return YES;
    }
/*
 * The next line refuses to copy INTO a native dirtectory...
 */
    if (d->full_filename != NULL) return YES;
/*
 * Search for a suitable input module to copy...
 */
    for (il=qvalue(input_libraries); consp(il); il = qcdr(il))
    {   oo = qcar(il);
        if (!is_library(oo)) continue;
        i = library_number(oo);
        id = fasl_files[i];
/* /* Not updated for native dirs yet */
        if (id->full_filename != NULL) continue;
        for (ii=0; ii<get_dirused(id->h); ii++)
            if (samename(name, id, ii, len)) goto found;
    }
    return YES;     /* Module to copy not found */
found:
/*
 * If the potential input module found was in the output directory exit now.
 */
    if (id == d) return NO;
/*
 * Now scan output directory to see where to put result
 */
    for (i=0; i<get_dirused(d->h); i++)
/* /* Not updated for native dirs yet */
        if (samename(name, d, i, len))
        {   d->h.updated |= D_UPDATED | D_COMPACT;
            goto ofound;
        }
/*
 * The file was not previously present in the output directory, so
 * I need to insert it. The code here is copies from open_output and is
 * now messy enoug that I should really move it to a sub-function.
 */
    if (len == IMAGE_CODE)
        name = "InitialImage", n = 1;
    else if (len == HELP_CODE)
        name = "HelpDataFile", len = IMAGE_CODE, n = 1;
    else if (len == BANNER_CODE)
        name = "Start-Banner", len = IMAGE_CODE, n = 1;
    else if (len < 0)
    {   sprintf(hard, "HardCode<%.2x>", (-len) & 0xff);
        name = hard, len = IMAGE_CODE, n = 1;
    }
    else if (len <= 11) n = 1;
    else if (len <= 11+11+24) n = 2;
    else if (len <= 11+11+11+24+24) n = 3;
    else return YES;  /* Name longer than 81 chars not supported, sorry */
    while (i+n > (int)get_dirsize(d->h))
    {   d = enlarge_directory(i);
        current_output_directory = d;
        if (d == NULL) return YES;
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
    {   int np;
        char *p;
/*
 * First I will clear all the relevant fields to blanks.
 */
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
        } while ((d->d[i+n].D_space & 0xff) != 0xff);
    }
/*
 * I provisionally set the size to zero so that if something goes wrong
 * I will still have a tolerably sensible image file.
 */
    memset(&d->d[i].D_size, 0, 3);
    d->h.updated |= D_UPDATED;
    if (fseek(d->f, bits32(&d->d[i].D_position), SEEK_SET) != 0 ||
        fseek(id->f, bits32(&id->d[ii].D_position), SEEK_SET) != 0) return YES;
    l = bits24(&id->d[ii].D_size);
    chk1 = 0;
    for (k=0; k<l; k++)
    {   int c = getc(id->f);
        uint32_t chk_temp;
/*
 * I do not have to do anything special about encryption here...
 */
        update_crc(chk1, c);
        if (c == EOF) return YES;
        putc(c, d->f);
    }
    read_bytes_remaining = 0;
    j = validate_checksum(id->f, chk1);  /* HUH? */
    read_bytes_remaining = save;
    if (j) return YES;
    if (put_checksum(d->f, chk1)) return YES;
    if (fflush(d->f) != 0) return YES;
    setbits24(&d->d[i].D_size, (int32_t)l);
    setbits32(d->h.eof, (int32_t)ftell(d->f));
    return NO;
#endif /* DEMO_MODE */
}

CSLbool IcloseInput(int check_checksum)
/*
 * Terminate processing one whatever subfile has been being processed.
 * returns nonzero if there was trouble.
 * read and verify checksum if arg is TRUE.
 */
{
    CSLbool r;
    Istatus = I_INACTIVE;
    if (check_checksum)
        r = validate_checksum(binary_read_file, subfile_checksum);
    else r = NO;
    if (nativedir)
    {   if (fclose(binary_read_file) != 0) r = YES;
    }
    return r;
}

CSLbool IcloseOutput(int plant_checksum)
/*
 * Terminate processing one whatever subfile has been being processed.
 * returns nonzero if there was trouble. Write a checksum to the file.
 * There is a jolly joke here!  I MUST NOT try to pick up the identification
 * of the output directory from the lisp-level variable output_directory
 * because (preserve) calls this AFTER it has utterly mangled the heap (to
 * put all pointers into relative form). To allow for this the variable
 * current_output_directory identifies the directory within which a file
 * was most recently opened.
 */
{
#ifdef DEMO_MODE
    return YES;
#else
    int r;
    Lisp_Object nil = C_nil;
    directory *d = current_output_directory;
    Istatus = I_INACTIVE;
    if (fasl_stream != nil && fasl_stream != SPID_NIL && plant_checksum)
    {   put_checksum(NULL, subfile_checksum);
        return NO;
    }
    current_output_directory = NULL;
/* Here I have to write a checksum to the current ouput dir */
    if (d == NULL || (d->h.updated & D_WRITE_OK) == 0) return NO;
//@@  if (plant_checksum) put_checksum(d->f, subfile_checksum);
    if (plant_checksum) put_checksum(binary_write_file, subfile_checksum);
    if (d->full_filename != NULL)
    {   r = (fclose(binary_write_file) != 0);
        binary_write_file = NULL;
        return r;
    }
    setbits24(&current_output_entry->D_size, (int32_t)write_bytes_written);
    r = fflush(d->f);
    setbits32(d->h.eof, (int32_t)ftell(d->f));
/*
 * I bring the directory at the start of the output file up to date at this
 * stage - the effect is that if things crash somehow I have a better
 * chance of resuming from where disaster hit.
 */
    fseek(d->f, 0, SEEK_SET);
    if (fwrite(&d->h, sizeof(directory_header), 1, d->f) != 1) r = YES;
    if (fwrite(&d->d[0], sizeof(directory_entry), 
                         (size_t)get_dirsize(d->h), d->f) !=
        (size_t)get_dirsize(d->h)) r = YES;
    if (fflush(d->f) != 0) r = YES;
    d->h.updated &= ~D_UPDATED;
    current_output_entry = NULL;
    return r;
#endif /* DEMO_MODE */
}

CSLbool finished_with(int j)
{
#ifdef DEMO_MODE
    return NO;
#else
    directory *d = fasl_files[j];
    fasl_files[j] = NULL;
/*
 * If the library concerned had been opened using (open-library ...) then
 * the name stored in fasl_paths[] would have been allocated using malloc(),
 * and just discarding it as here will represent a space-leak. Just for now
 * I am going to accept that as an unimportant detail.
 */
    fasl_paths[j] = NULL;
    if (d == NULL) return NO;
    if (d->h.updated & D_COMPACT)
    {   int i;
        long int hwm;
        if (d->f == NULL) return YES;
        d->h.updated |= D_UPDATED;
        sort_directory(d);
        hwm = sizeof(directory_header) +
              get_dirsize(d->h)*(long int)sizeof(directory_entry) +
              REGISTRATION_SIZE;
        for (i=0; i<get_dirused(d->h); i++)
        {   long int pos = bits32(&d->d[i].D_position);
            if (pos != hwm)
            {   char *b = 16 + (char *)stack;
                char small_buffer[64];
/* I add 4 to the length specified here to allow for checksums */
                long int len = bits24(&d->d[i].D_size) + 4L;
                long int newpos = hwm;
                while (len != 0)
                {   size_t n = 
                       (size_t)((CSL_PAGE_SIZE - 64 -
                                 ((char *)stack - (char *)stackbase)) &
                               (~(int32_t)0xff));
/*
 * I only perform compression of the file when I am in the process of stopping,
 * and in that case the Lisp stack is not in use, so I use if as a buffer.
 * WELL the above statement used to be true, but now it is not, since the
 * function CLOSE-LIBRARY does exactly what I have declared is never
 * possible. But all is not lost - I can afford to use that part of
 * the stack that remains unused. In cases where CLOSE-LIBRARY is called
 * just before a stack overflow was due the result will be utterly terrible
 * (on speed) but it should still be correct. So what you will see is that
 * I start my buffer 16 bytes above the active part of the stack, and
 * let it run to within 48 bytes of the top of the stack page, but
 * rounded down so I do transfers in multiples of 256 bytes. If there
 * is really no (Lisp) stack free I use a 64 byte local buffer.
 */
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
    {
        if (d->f == NULL || fflush(d->f) != 0) return YES;
        fseek(d->f, 0, SEEK_SET);
        if (fwrite(&d->h, sizeof(directory_header), 1, d->f) != 1) return YES;
        if (fwrite(&d->d[0], sizeof(directory_entry),
                   (size_t)get_dirsize(d->h), d->f) !=
            (size_t)get_dirsize(d->h)) return YES;
        if (fflush(d->f) != 0) return YES;
    }
    if (d->h.updated & D_PENDING) return NO;
    else if (d->f != NULL && fclose(d->f) != 0) return YES;
    else return NO;
#endif /* DEMO_MODE */
}

CSLbool Ifinished(void)
/*
 * Indicates total completion of all work on image files, and so calls
 * for things to be (finally) tidied up.  Again returns YES of anything
 * has gone wrong.
 */
{
/*
 * Need to close all files here... loads of calls to fflush and fclose.
 * Actually only output files are a real issue here. And then only
 * the ones that are flagged as needing compaction.
 */
    int j;
    CSLbool failed = NO;
    for (j=0; j<number_of_fasl_paths; j++)
        if (finished_with(j)) failed = YES;
    return failed;
}

int Igetc(void)
/*
 * Returns next byte from current image sub-file, or EOF if either
 * real end-of-file or on failure. As a special fudge here (ugh) I
 * use a negative value of read_bytes_remaining to indicate that
 * input should NOT be from the usual image-file mechanism, but from
 * the currently selected standard input. Setting things up that way
 * then supports processing of FASL files from almost arbitrary
 * sources.
 */
{
    long int n_left = read_bytes_remaining;
    int c;
    uint32_t chk_temp;
    if (n_left <= 0)
    {   if (n_left == 0) return EOF;
        else
        {   Lisp_Object nil = C_nil;
            Lisp_Object stream = qvalue(standard_input);
            if (!is_stream(stream)) return EOF;
            c = getc_stream(stream);
            nil = C_nil;
            if (exception_pending()) return EOF;
        }
    }
    else
    {   read_bytes_remaining = n_left - 1;
        c = getc(binary_read_file);
    }
    if (c == EOF) return c;
    update_crc(subfile_checksum, c);
    if (crypt_active >= 0)
    {   if (crypt_count >= CRYPT_BLOCK)
        {   crypt_get_block(crypt_buffer);
            crypt_count = 0;
        }
        c ^= crypt_buffer[crypt_count++];
    }
    return (c & 0xff);
}

int32_t Iread(void *buff, int32_t size)
/*
 * Reads (size) bytes into the indicated buffer.  Returns number of
 * bytes read. Decrypts if crypt_active >= 0.
 */
{
#if 1
/*
 * This version is going to be slower but is an alternative to the
 * block-at-a-time reading code...
 */
    unsigned char *p = (unsigned char *)buff;
    int nread = 0;
    while (size > 0)
    {   int c = Igetc();
        if (c == EOF) break;
        *p++ = c;
        nread++;
        size--;
    }
    return nread;
#else
    unsigned char *p = (unsigned char *)buff;
    uint32_t chk_temp;
    int i;
    size_t n_read;
    long int n_left = read_bytes_remaining;
    if (n_left < 0)
    {   for (i=0; i<size; i++)
        {   int c = Igetc();
            if (c == EOF) return i;
            p[i] = (char)c;
        }
        return i;
    }
    if (size > n_left) size = (int32_t)n_left; /* Do not go beyond end of file */
    if (size == 0) return 0;
    n_read = fread(p, 1, (size_t)size, binary_read_file);
/*
 * Updating the checksum here is probably a painful extra cost, but I count
 * the security it gives me as worthwhile. I compute the checksum byte at a
 * time so that it is not sensitive to the byte ordering of the machine used.
 */
    for (i=0; i<(int)n_read; i++)
    {   int c = p[i];
        update_crc(subfile_checksum, c);
        if (crypt_active >= 0)
        {   if (crypt_count >= CRYPT_BLOCK)
            {   crypt_get_block(crypt_buffer);
                crypt_count = 0;
            }
            c ^= crypt_buffer[crypt_count++];
            p[i] = (char)c;
        }
    }
    read_bytes_remaining -= n_read;
    return n_read;
#endif
}

long int Ioutsize(void)
{
    return write_bytes_written;
}

CSLbool Iputc(int ch)
/*
 * Puts one character into image system, returning YES if there
 * was trouble.
 */
{
#ifdef DEMO_MODE
    return YES;
#else
    uint32_t chk_temp;
    Lisp_Object nil = C_nil;
    write_bytes_written++;
    if (crypt_active >= 0)
    {   if (crypt_count >= CRYPT_BLOCK)
        {   crypt_get_block(crypt_buffer);
            crypt_count = 0;
        }
        ch ^= crypt_buffer[crypt_count++];
    }
    update_crc(subfile_checksum, ch);
    if (fasl_stream != nil && fasl_stream != SPID_NIL)
        putc_stream(ch, fasl_stream);
    else if (putc(ch, binary_write_file) == EOF) return YES;
    return NO;
#endif /* DEMO_MODE */
}

#define FWRITE_CHUNK 0x4000

CSLbool Iwrite(void *buff, int32_t size)
/*
 * Writes (size) bytes from the given buffer, returning YES if trouble.
 */
{
#ifdef DEMO_MODE
    return YES;
#else
    unsigned char *p = (unsigned char *)buff;
    int32_t i;
    uint32_t chk_temp;
    Lisp_Object nil = C_nil;
    if (crypt_active >= 0 ||
        (fasl_stream != nil && fasl_stream != SPID_NIL))
    {
/*
 * Note that in this case the checksum is updated within Iputc() so I do
 * not have to do anything special about it here.
 */
        for (i=0; i<size; i++) 
            if (Iputc(p[i])) return YES;
        return NO;
    }
/*
 * If encrypted writing is active I will have gone through Iputc for
 * every individual character and so will not get down to here. Thus the
 * optimised calls to fwrite() can remain intact.
 */
    for (i=0; i<size; i++)
    {   /* Beware - update_crc is a macro and the {} block here is essential */
        update_crc(subfile_checksum, p[i]);
    }
    write_bytes_written += size;
    while (size >= FWRITE_CHUNK)
    {   if (fwrite(p, 1, FWRITE_CHUNK, binary_write_file) != FWRITE_CHUNK)
            return YES;
        p += FWRITE_CHUNK;
        size -= FWRITE_CHUNK;
    }
    if (size == 0) return NO;
    else return 
       (fwrite(p, 1, (size_t)size, binary_write_file) != (size_t)size);
#endif /* DEMO_MODE */
}

/*
 * Now code that maps real pointers into references relative
 * to page numbers.  Here I will also go to the trouble of putting zero
 * bytes in unused bits of memory - that will make checkpoint files
 * compress better and will also make them independent of all actual
 * addresses used on the host machine.  Observe that the representation
 * created has to depend a bit on the current page size.
 */

#define PACK_PAGE_OFFSET(pg, of) ((pg << PAGE_BITS) + of)


static void unadjust(Lisp_Object *cp)
/*
 * If p is a pointer to an object that has moved, unadjust it.
 */
{
#ifndef DEMO_MODE
    Lisp_Object nil = C_nil, p = (*cp); /* Beware "=*" anachronism! */
    if (p == nil)
    {   *cp = SPID_NIL; /* Marks NIL in preserve files */
        return;
    }
    else if (is_cons(p))
    {   int32_t i;
        for (i=0; i<heap_pages_count; i++)
        {   void *page = heap_pages[i];
            char *base = (char *)quadword_align_up((intptr_t)page);
/*
 * The next line is pretty dodgy - I want to decide which segment a
 * pointer references, but pointer comparisons are only valid within
 * single segments.  I cast to int and cross my fingers! Actually no
 * REASONABLE C system would fail on this - it is just that ANSI specifies
 * that you can only do any address arithmetic WITHIN the area returned
 * by a single malloc() (etc).
 */
            if ((intptr_t)base <= (intptr_t)p &&
                 (intptr_t)p <= (intptr_t)(base+CSL_PAGE_SIZE))
            {   unsigned int offset = (unsigned int)((char *)p - base);
                *cp = PACK_PAGE_OFFSET(i, offset);
                return;
            }
        }
        term_printf("\n[%p] Cons address %p not found in heap\n",
                 (void *)cp, (void *)p);
        abort();
    }
    else if (!is_immed_or_cons(p))
    {   int32_t i;        /* vectors get relocated here */
        for (i=0; i<vheap_pages_count; i++)
        {   void *page = vheap_pages[i];
            char *base = (char *)doubleword_align_up((intptr_t)page);
/* see comments above re the next line */
            if ((intptr_t)base <= (intptr_t)p &&
                (intptr_t)p <= (intptr_t)(base+CSL_PAGE_SIZE))
            {   unsigned int offset = (unsigned int)((char *)p - base);
                *cp = PACK_PAGE_OFFSET(i, offset);
                return;
            }
        }
        term_printf("\n[%p] Vector address %p not found in heap\n",
                 (void *)cp, (void *)p);
        abort();
    }
#endif /* DEMO_MODE */
}

static void unadjust_consheap(void)
{
#ifndef DEMO_MODE
    int32_t page_number;
    for (page_number = 0; page_number < heap_pages_count; page_number++)
    {   void *page = heap_pages[page_number];
        char *low = (char *)quadword_align_up((intptr_t)page);
        char *start = low + CSL_PAGE_SIZE;
        char *fr = low + car32(low);
/* The next line sets unused space in the page to be zero */
        while ((fr -= sizeof(Lisp_Object)) != low) qcar(fr) = 0;
        fr = low + car32(low);
        while (fr < start)
        {   unadjust((Lisp_Object *)fr);
            fr += sizeof(Lisp_Object);
        }
    }
#endif /* DEMO_MODE */
}

static void convert_word_order(void *p)
{
/*
 * This bit seems a bit strange to me. I cope with all other
 * byte order issues by having the exporting machine dump data
 * in its own native format and then fixing things up again when
 * I re-load. Why not do that here? However what I *do* do is to keep
 * image files in a single WORD order in image files but let the bytes
 * within words fall how they do. But during the transition to support
 * of full 64-bit machines I will disable all attempts at byte correction
 * when in 64-bit mode... That may mean that in fact 64-bit images are not
 * as portable as I had thought! Floats saved on a little-endian machine
 * may get messed up if re-loaded on a big-endian system. Ugh!
 */
    if (SIXTY_FOUR_BIT) return;
    if ((current_fp_rep & FP_WORD_ORDER) != 0)
    {   uint32_t *f = (uint32_t *)p;
        uint32_t w = f[0];
        f[0] = f[1];
        f[1] = w;
    }
}

static void unadjust_vecheap(void)
{
#ifndef DEMO_MODE
    int32_t page_number, i;
    for (page_number = 0; page_number < vheap_pages_count; page_number++)
    {   void *page = vheap_pages[page_number];
        char *low = (char *)doubleword_align_up((intptr_t)page);
        char *high = low + (CSL_PAGE_SIZE - 8);
        char *fr = low + car32(low);
        low += 8;
        while (low < fr)
        {   Header h = *(Header *)low;
            if (is_symbol_header(h))
            {   Lisp_Object s = (Lisp_Object)(low+TAG_SYMBOL);
                ifn1(s) = code_up_fn1(qfn1(s));
                ifn2(s) = code_up_fn2(qfn2(s));
                ifnn(s) = code_up_fnn(qfnn(s));
                unadjust(&qvalue(s));
                unadjust(&qenv(s));
                unadjust(&qpname(s));
                unadjust(&qplist(s));
                unadjust(&qfastgets(s));
#ifdef COMMON
                unadjust(&qpackage(s));
#endif
                low += symhdr_length;
                continue;
            }
            else switch (type_of_header(h))
            {
#ifdef COMMON
        case TYPE_RATNUM:
        case TYPE_COMPLEX_NUM:
                unadjust((Lisp_Object *)(low+CELL));
                unadjust((Lisp_Object *)(low+2*CELL));
                break;
#endif
        case TYPE_HASH:
        case TYPE_SIMPLE_VEC:
        case TYPE_ARRAY:
        case TYPE_STRUCTURE:
                for (i=CELL; 
                     i<doubleword_align_up(length_of_header(h));
                     i+=CELL)
                    unadjust((Lisp_Object *)(low+i));
                break;
        case TYPE_STREAM:
                {   Lisp_Object ss = (Lisp_Object)(low+TAG_VECTOR);
/*
 * It might make rather good sense to close any file or pipe streams
 * that I come across at this stage...
 */
                    if (elt(ss, 4) == (intptr_t)char_to_file &&
                        elt(ss, 3) != 0)
                    {   fclose(stream_file(ss));
                        set_stream_write_fn(ss, char_to_illegal);
                        set_stream_write_other(ss, write_action_illegal);
                        set_stream_file(ss, NULL);
                    }
#if defined HAVE_POPEN || defined HAVE_FWIN
                    if (elt(ss, 4) == (intptr_t)char_to_pipeout &&
                        elt(ss, 3) != 0)
                    {   my_pclose(stream_file(ss));
                        set_stream_write_fn(ss, char_to_illegal);
                        set_stream_write_other(ss, write_action_illegal);
                        set_stream_file(ss, NULL);
                    }
#endif
                    if (elt(ss, 8) == (intptr_t)char_from_file &&
                        elt(ss, 3) != 0)
                    {   fclose(stream_file(ss));
                        set_stream_read_fn(ss, char_from_illegal);
                        set_stream_read_other(ss, read_action_illegal);
                        set_stream_file(ss, NULL);
                    }
                    elt(ss, 4) = code_up_io((void *)elt(ss, 4));
                    elt(ss, 5) = code_up_io((void *)elt(ss, 5));
                    elt(ss, 8) = code_up_io((void *)elt(ss, 8));
                    elt(ss, 9) = code_up_io((void *)elt(ss, 9));
                }
        case TYPE_MIXED1:
        case TYPE_MIXED2:
        case TYPE_MIXED3:
                for (i=CELL; i<4*CELL; i+=CELL)
                    unadjust((Lisp_Object *)(low+i));
                break;
        case TYPE_DOUBLE_FLOAT:
                convert_word_order((void *)(low + 8));
                break;
#ifdef COMMON
        case TYPE_SINGLE_FLOAT:
                break;
        case TYPE_LONG_FLOAT:
/* If long floats were 3 words long I might need to adjust this code... */
                convert_word_order((void *)(low + 8));
                break;
#endif
        default:
                break;
            }
            low += doubleword_align_up(length_of_header(h));
        }
/*
 * Now clean up the unused space in the page...
 */
        while (low <= high)
        {   qcar(low) = 0;
            qcdr(low) = 0;
            low += 2*sizeof(Lisp_Object);
        }
    }
#endif /* DEMO_MODE */
}

static void unadjust_bpsheap(void)
{
#ifndef DEMO_MODE
    int32_t page_number;
    for (page_number = 0; page_number < bps_pages_count; page_number++)
    {   void *page = bps_pages[page_number];
        char *low = (char *)doubleword_align_up((intptr_t)page);
        char *fr = low + car32(low);
        /* Clean up unused space */
        while ((fr -= sizeof(Lisp_Object)) != low) qcar(fr) = 0;
        fr = low + qcar(low);
        while (fr < low + CSL_PAGE_SIZE)
        {   Header h = *(Header *)fr;
#ifdef ENVIRONMENT_VECTORS_IN_BPS_HEAP
            switch (type_of_header(h))
            {
/* This option is not actually used at present... */
        case TYPE_SIMPLE_VEC:
                for (i=CELL;
                     i<doubleword_align_up(length_of_header(h));
                     i+=CELL)
                    unadjust((Lisp_Object *)(fr+i));
                break;
        default:
                break;
            }
#endif
            fr += doubleword_align_up(length_of_header(h));
        }
    }
#endif /* DEMO_MODE */
}

static void unadjust_all(void)
{
#ifndef DEMO_MODE
    int32_t i;
    Lisp_Object nil = C_nil;
    set_up_entry_lookup();
    qheader(nil)  = TAG_ODDS+TYPE_SYMBOL+SYM_SPECIAL_VAR;
    qvalue(nil)   = 0;
    qenv(nil)     = 0;
    ifn1(nil)     = 0;
    ifn2(nil)     = 0;
    ifnn(nil)     = 0;
    unadjust(&(qpname(nil)));       /* not a gensym */
    unadjust(&(qplist(nil)));
    unadjust(&(qfastgets(nil)));
#ifdef COMMON
    unadjust(&(qpackage(nil)));
#endif

    copy_into_nilseg(YES);
    eq_hash_table_list = eq_hash_tables;
    equal_hash_table_list = equal_hash_tables;

    for (i = first_nil_offset; i<last_nil_offset; i++)
        unadjust(&BASE[i]);
    copy_out_of_nilseg(YES);

    unadjust_consheap();
    unadjust_vecheap();
    unadjust_bpsheap();
#endif /* DEMO_MODE */
}


void preserve_native_code(void)
{
#ifndef DEMO_MODE
/*
 * I should maybe worry a little more here about IO errors...
 */
    int i;
    if (!native_pages_changed) return;
    if (open_output(NULL, -native_code_tag))
    {   term_printf("Failed to open module for native code storage\n");
        return;
    }
    Iputc(native_pages_count & 0xff);
    Iputc((native_pages_count>>8) & 0xff);
/*
 * The FINAL native page will in general not be full, so I put a count of
 * the number of bytes in it that are in use in its first word, and
 * zero out the parts of it beyond there. Then the file compression that
 * routinely use when writing into image files.
 */
    if (native_pages_count != 0)
    {   intptr_t p = (intptr_t)native_pages[native_pages_count-1];
        p = doubleword_align_up(p);
        car32(p) = native_fringe;
        memset((char *)p+native_fringe, 0, CSL_PAGE_SIZE-native_fringe);
    }
    for (i=0; i<native_pages_count; i++)
    {   intptr_t p = (intptr_t)native_pages[i];
        p = doubleword_align_up(p);
        Cfwrite((char *)p, CSL_PAGE_SIZE);
    }
    IcloseOutput(1);
#endif /* DEMO_MODE */
}

void preserve(char *banner)
{
#ifdef DEMO_MODE
    err_printf("\nThe demo systen can not save a checkpoint file\n");
    give_up();
    return;
#else
    int32_t i;
    CSLbool int_flag = NO;
    Lisp_Object nil = C_nil;
/*
 * I dump out any altered chunk of native code before I mangle the heap
 * up.
 */
    preserve_native_code();
    if (Iopen(NULL, 0, NO, NULL))
    {   err_printf("+++ PRESERVE failed to open image file\n");
        return;
    }
/*
 * I set a whole bunch of things to NIL here.  If spurious data is left over
 * in global list-bases from a previous calculation it could clog up the
 * heap and waste a lot of space...
 */
#ifdef NILSEG_EXTERNS
    for (i=0; i<=50; i++) workbase[i] = nil;
#else
    for (i=work_0_offset; i<last_nil_offset; i++)
        BASE[i] = nil;
#endif
    exit_tag = exit_value = catch_tags =
        codevec = litvec = B_reg = faslvec = faslgensyms = nil;

/*
 * Any new-style native code is now declared discarded and the previous
 * (and portable) bytecode version gets put back. But the list showing what
 * functions might possibly have native versions is kept around.
 */
    {   Lisp_Object w = native_defs;
        while (consp(w))
        {   Lisp_Object name = qcar(w);
            w = qcdr(w);
            Lsymbol_restore_fns(nil, name);
        }
    }

    reclaim(nil, "preserve", GC_PRESERVE, 0); /* FULL garbage collection */
    nil = C_nil;
/*
 * if the user generated a SIGINT this is where it gets noticed...
 */
    if (exception_pending())
    {   flip_exception();
        int_flag = YES;
    }
    {   char msg[128];
        time_t t0 = time(0);
        for (i=0; i<128; i++) msg[i] = ' ';
        if (banner[0] == 0) msg[0] = 0;
        else sprintf(msg, "%.60s", banner);
/* 26 bytes starting from byte 64 shows the time of the dump */
        sprintf(msg+64, "%.25s\n", ctime(&t0));
/* 16 bytes starting at byte 90 are for a checksum of the u01.c etc checks */
        get_user_files_checksum((unsigned char *)&msg[90]);
/* 106 to 109 free at present but available if checksum goes to 160 bits */
/* 1 byte at 110 marks an encrypted image (work in progress!) */
        msg[110] = 0;
/* The final byte at 111 indicates whether compression is to be used */
        {   int32_t cc = compression_worth_while;
            int fg = 0;
            while (cc > 128) fg++, cc >>= 1;
            msg[111] = (char)fg;
        }
        Cfwrite(msg, 112); /* Exactly 112 bytes in the header records */
    }

    unadjust_all();    /* Turn all pointers into base-offset form */

    Cfwrite("\nNilseg:", 8);
    copy_into_nilseg(YES);
    {   Lisp_Object saver[9];
        for (i=0; i<9; i++)
            saver[i] = BASE[i+13],
            BASE[i+13] = 0;
        /* codefringe */
        /* codelimit  */
        /* stacklimit */
        /* ... ditto  */
        /* ... ditto  */
        /* fringe     */
        /* heaplimit  */
        /* vheaplimit */
        /* vfringe    */
        Cfwrite((char *)BASE, sizeof(Lisp_Object)*last_nil_offset);
        for (i=0; i<9; i++)
            BASE[i+13] = saver[i];
    }
    Cfwrite((char *)&heap_pages_count, sizeof(heap_pages_count));
    Cfwrite((char *)&vheap_pages_count, sizeof(vheap_pages_count));
    Cfwrite((char *)&bps_pages_count, sizeof(bps_pages_count));

    Cfwrite("\nVecseg:", 8);
    for (i=0; i<vheap_pages_count; i++)
    {   intptr_t p = (intptr_t)vheap_pages[i];
        Cfwrite((char *)doubleword_align_up(p), CSL_PAGE_SIZE);
    }

    Cfwrite("\nConsseg", 8);
    for (i=0; i<heap_pages_count; i++)
    {   intptr_t p = (intptr_t)heap_pages[i];
        Cfwrite((char *)quadword_align_up(p), CSL_PAGE_SIZE);
    }

    Cfwrite("\nCodeseg", 8);
    for (i=0; i<bps_pages_count; i++)
    {   intptr_t p = (intptr_t)bps_pages[i];
        Cfwrite((char *)doubleword_align_up(p), CSL_PAGE_SIZE);
    }

#ifndef COMMON
    Cfwrite("\n\nEnd of CSL dump file\n\n", 24);
#else
    Cfwrite("\n\nEnd of CCL dump file\n\n", 24);
#endif
/*
 * Here I pad the image file to be a multiple of 4 bytes long.  Since it is a
 * binary file the '\n' characters I put in will always be just 1 byte each
 * (for text files that might have expanded).  See comments in fasl.c for
 * a diatribe about why I do this, or at least why rather a long while ago
 * this was necessary on at least one sort of computer.
 */
    {   int k = (int)((-write_bytes_written) & 3);
        while (k != 0) k--, Iputc(NEWLINE_CHAR);
    }
/*
    flip_needed = NO; Since I stop after (preserve) these lines are unnecessary?
    old_fp_rep = current_fp_rep;
*/

/*
 * I need to check for write errors here and moan if there were any...
 */
    if (IcloseOutput(1)) error(0, err_write_err);
    if (int_flag) term_printf("\nInterrupt during (preserve) was ignored\n");
    return;
#endif /* DEMO_MODE */
}

/* end of file preserve.c */

