/* stream.h                        Copyright (C) Codemist Ltd, 1995-2008 */

/*
 * Header defining the structure of stream objects in CSL, and also
 * the format for "library" files used with the fast-load mechanism.
 */



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



/* Signature: 7f781434 18-Aug-2008 */

#ifndef header_stream_h
#define header_stream_h 1

extern FILE *non_terminal_input;

typedef int character_reader(void); /* used only with procedural IO */
typedef int character_writer(int);  /* ditto */

typedef int character_stream_reader(Lisp_Object);
typedef int character_stream_writer(int, Lisp_Object);
typedef int32_t other_stream_op(int32_t, Lisp_Object);

extern Lisp_Object Lopen(Lisp_Object nil, Lisp_Object name, Lisp_Object dir);

/*
 * The values used here are placed where characters might be, or possibly
 * OR'd with character codes. They are now such that even if I am using
 * 16-bit characters (Unicode of Kanji) all ought to be well. Anybody who says
 * "32-bit Unicode" to me can go away for now - I do not really cope with
 * 16-bit chars yet!
 */
#define ESCAPED_CHAR    0x20000
#define NOT_CHAR        0x40000

extern int char_to_terminal(int c, Lisp_Object f);
extern int char_to_file(int c, Lisp_Object f);
extern int char_to_pipeout(int c, Lisp_Object f);
extern int char_to_synonym(int c, Lisp_Object f);
extern int char_to_broadcast(int c, Lisp_Object f);
extern int char_to_illegal(int c, Lisp_Object f);
extern int char_to_list(int c, Lisp_Object f);
extern int code_to_list(int c, Lisp_Object f);
extern int count_character(int c, Lisp_Object f);
extern int binary_outchar(int c, Lisp_Object f);
extern int char_to_function(int c, Lisp_Object f);
#ifdef HAVE_LIBFOX
extern int char_to_math(int c, Lisp_Object f);
extern int char_to_spool(int c, Lisp_Object f);
#endif

extern int32_t write_action_terminal(int32_t c, Lisp_Object f);
extern int32_t write_action_file(int32_t c, Lisp_Object f);
extern int32_t write_action_pipe(int32_t c, Lisp_Object f);
extern int32_t write_action_synonym(int32_t c, Lisp_Object f);
extern int32_t write_action_broadcast(int32_t c, Lisp_Object f);
extern int32_t write_action_twoway(int32_t c, Lisp_Object f);
extern int32_t write_action_illegal(int32_t c, Lisp_Object f);
extern int32_t write_action_list(int32_t c, Lisp_Object f);
#ifdef HAVE_LIBFOX
extern int32_t write_action_math(int32_t c, Lisp_Object f);
extern int32_t write_action_spool(int32_t c, Lisp_Object f);
#endif

extern int char_from_terminal(Lisp_Object f);
extern int char_from_file(Lisp_Object f);
extern int char_from_synonym(Lisp_Object f);
extern int char_from_concatenated(Lisp_Object f);
extern int char_from_echo(Lisp_Object f);
extern int char_from_illegal(Lisp_Object f);
extern int char_from_list(Lisp_Object f);
extern int char_from_vector(Lisp_Object f);

extern int32_t read_action_terminal(int32_t c, Lisp_Object f);
extern int32_t read_action_file(int32_t c, Lisp_Object f);
extern int32_t read_action_output_file(int32_t c, Lisp_Object f);
extern int32_t read_action_synonym(int32_t c, Lisp_Object f);
extern int32_t read_action_concatenated(int32_t c, Lisp_Object f);
extern int32_t read_action_echo(int32_t c, Lisp_Object f);
extern int32_t read_action_twoway(int32_t c, Lisp_Object f);
extern int32_t read_action_illegal(int32_t c, Lisp_Object f);
extern int32_t read_action_list(int32_t c, Lisp_Object f);
extern int32_t read_action_vector(int32_t c, Lisp_Object f);

#ifndef MAX_PROMPT_LENGTH
#  define MAX_PROMPT_LENGTH 256
#endif
extern char memory_print_buffer[MAX_PROMPT_LENGTH];

/*
 * The following typedef shows the expected layout of a Lisp_STREAM object,
 * but it is not used directly because I need to insist that each field is
 * exactly 4 bytes wide. Thus when I access things that contain pointers I
 * will perform horrible casts. This is essential if I am to be able to host
 * this system on certain 64-bit systems.
 *
 *  typedef struct Lisp_STREAM
 *  {
 *      Header h;                               0
 *      Lisp_Object type;                       CELL
 *      Lisp_Object write_data;                 2*CELL
 *      Lisp_Object read_data;                  3*CELL
 *      FILE *file;                             4*CELL
 *      character_stream_writer *write_fn;      5*CELL
 *      other_stream_op *write_other_fn;        6*CELL
 *      intptr_t line_length;                   7*CELL
 *      intptr_t char_pos;                      8*CELL
 *      character_stream_reader *read_fn;       9*CELL
 *      other_stream_op *read_other_fn;        10*CELL
 *      intptr_t pushed_char;                  11*CELL
 *  } Lisp_STREAM;
 */

#define STREAM_SIZE           (12*CELL)

#define stream_type(v)        elt(v, 0)
#define stream_write_data(v)  elt(v, 1)
#define stream_read_data(v)   elt(v, 2)
#define stream_file(v)        ((FILE *)elt(v, 3))
#define stream_write_fn(v)    ((character_stream_writer *)elt(v, 4))
#define stream_write_other(v) ((other_stream_op *)elt(v,5))
#define stream_line_length(v) elt(v, 6)
#define stream_char_pos(v)    elt(v, 7)
#define stream_read_fn(v)     ((character_stream_reader *)elt(v, 8))
#define stream_read_other(v)  ((other_stream_op *)elt(v,9))
#define stream_pushed_char(v) elt(v, 10)

#define set_stream_file(v, x)           (elt(v, 3) = (Lisp_Object)(x))
#define set_stream_write_fn(v, x)       (elt(v, 4) = (Lisp_Object)(x))
#define set_stream_write_other(v, x)    (elt(v, 5) = (Lisp_Object)(x))
#define set_stream_read_fn(v, x)        (elt(v, 8) = (Lisp_Object)(x))
#define set_stream_read_other(v, x)     (elt(v, 9) = (Lisp_Object)(x))

#define STREAM_HEADER (TAG_ODDS + TYPE_STREAM + (STREAM_SIZE<<10))
#define STREAM_FLAG_PIPE       1

#define is_stream(v)      (is_vector(v) && vechdr(v) == STREAM_HEADER)

#ifdef DEBUG
#define putc_stream(c, f)          (!is_stream(f) || \
                                    stream_write_fn(f)==0 ? \
                                    term_printf("putc %s %d\n", \
                                                __FILE__, __LINE__), \
                                    ensure_screen(), my_exit(1), 0 : \
                                    stream_write_fn(f)(c, f))
#define getc_stream(f)             (!is_stream(f) || \
                                    stream_read_fn(f)==0 ? \
                                    term_printf("putc %s %d\n", \
                                                __FILE__, __LINE__), \
                                    ensure_screen(), my_exit(1), 0 : \
                                    stream_read_fn(f)(f))
#define other_write_action(c, f)   (!is_stream(f) || \
                                    stream_write_other(f)==0 ? \
                                    term_printf("putc %s %d\n", \
                                                __FILE__, __LINE__), \
                                    ensure_screen(), my_exit(1), 0 : \
                                    stream_write_other(f)(c, f))
#define other_read_action(c, f)    (!is_stream(f) || \
                                    stream_read_other(f)==0 ? \
                                    term_printf("putc %s %d\n", \
                                                __FILE__, __LINE__), \
                                    ensure_screen(), my_exit(1), 0 : \
                                    stream_read_other(f)(c, f))
#else
#define putc_stream(c, f)          (stream_write_fn(f)(c, f))
#define getc_stream(f)             (stream_read_fn(f)(f))
#define other_write_action(c, f)   (stream_write_other(f)(c, f))
#define other_read_action(c, f)    (stream_read_other(f)(c, f))
#endif

/*
 * For other_write_action if the top four bits of the operand select an
 * action to be performed, while the remaining 28 are available to pass
 * an operand.
 */
 
#define WRITE_GET_INFO        0x00000000
#  define WRITE_GET_LINE_LENGTH        0
#  define WRITE_GET_COLUMN             1
#  define WRITE_IS_CONSOLE             2
#define WRITE_CLOSE                  0x10000000
#define WRITE_FLUSH                  0x20000000
#define WRITE_SET_LINELENGTH         0x30000000
#define WRITE_SET_COLUMN             0x40000000
#define WRITE_SET_LINELENGTH_DEFAULT 0x50000000

/*
 * For other_read_action() if the operand is in the range -1 to 65535 then 
 * it is a character to be unread (-1 is used for EOF). Otherwise if the most
 * significant bit is a "1" then the request is a seek (with a 31-bit address
 * within the stream to go to).  The remaining few cases are things that do
 * not need additional data passed.
 */
#define READ_SEEK          0x80000000
#define READ_TELL          0x00010000
#define READ_CLOSE         0x00010001
#define READ_FLUSH         0x00010002
#define READ_IS_CONSOLE    0x00010003
#define READ_END           0x00010004

extern Lisp_Object make_stream_handle(void);
extern CSLbool use_wimp, sigint_must_longjmp;
extern jmp_buf sigint_buf;

extern character_reader *procedural_input;
extern character_writer *procedural_output;

/*
 * Now support for the structure of image files....
 */


/*
 * This version of the directory structure can cope with up to 2047
 * modules in any single library. It can also cope with a directory
 * being mapped onto an operating-system directory rather than my own
 * sub-structure packed within a file.
 */

#if defined DEMO_BUILD || defined DEMO_MODE
#define IMAGE_FORMAT_VERSION       'd'
#else
#define IMAGE_FORMAT_VERSION       '4'
#endif

#define DIRECTORY_SIZE              8    /* Initial directory size */

typedef struct directory_header
{
    char C, S, L, version;  /* Identification                         */
    unsigned char dirext,   /* Extra bits for dirused, dirsize        */
                  dirsize,  /* Number of directory entries provided   */
                  dirused,  /* Number currently in use                */
                  updated;  /* In need of compaction & other flags    */
    char eof[4];            /* fseek/ftell location of end of file    */
} directory_header;

#define get_dirused(d) ((int)((d).dirused + (((d).dirext & 0x0f)<<8)))
#define get_dirsize(d) ((int)((d).dirsize + (((d).dirext & 0xf0)<<4)))

typedef struct directory_entry
{
    char data[44];
/*
    char newline;                * Makes file easier to read as a text file! *
                                 * but also used to indicate encryption      *
    char name[12];               * blank padded to 12 characters             *
                                 * but with special rules for root image etc *
    char date[24];
    char position[4];            * Machine byte-order insensitive format     *
    char size[3];                * Ditto                                     *
*/
} directory_entry;

/*
 * I use these macros rather than just the structure definition shown above
 * so that the behaviour of the code is not sensitive to attempts by a C
 * compiler to align things for me.  Think C 5.0 on the Macintosh (and
 * probably many other C compilers) put padder bytes in the original
 * structure to give word-alignment.
 */
#define D_newline     data[0]
#define D_name        data[1]
#define D_space       data[12]
#define D_date        data[13]
#define D_position    data[37]
#define D_size        data[41]

#define name_size     12
#define date_size     24

/*
 * The limit set here to the length of the name of a directory should only
 * have an effect on cosmetics not functionality.
 */
#define DIRNAME_LENGTH  256
#define NEWLINE_CHAR    0x0a

/*
 * The D_newline location in a directory originally held a newline,
 * because doing so resulted in image files being a little bit easier
 * to interpret when looked at with a simple text editor. But then
 * it turned out that the C value `\n' was not the same on all computers,
 * and so I used a literal hex value 0x0a instead, expecting it to
 * be the same as '\n' on "most" systems. Yet later I wanted a backwards-
 * compatible way to extend directory entries to indicate that some files
 * are stored encrypted. The route follows is that unencrypted files
 * have NEWLINE_CHAR in the D_newline position, while values ('\n' + n)
 * indicate files encrypted with key number n. Note that if I try to
 * read an encrypted sub-file but my key is wrong I will just get garbage
 * bytes back, so all code that handles files from the image will need
 * to be prepared to respond tolerably gracefully to such a situation.
 * I already have a CRC check at the end of every sub-file, but often
 * that will be too late, and anyway I may need to review that to ensure that
 * it actually checksums the plain-text not the cipher text.
 *
 * Well probably encrypted sub-files are going away now so the above is
 * close to irrelevant!
 */

typedef struct directory
{
    directory_header h;
    FILE *f;
    char *full_filename;    /* NULL unless native directory */
/*
 * It is unexpectedly and unpleasantly the case that the "filename"
 * field here must be the last one before the array of directory
 * entries. This is because in the case where an image file is
 * left pending at startup the structure is extended overlapping where the
 * directory entries will end up to hold a full-length file name not merely
 * one truncated to DIRNAME_LENGTH.
 */
    char filename[DIRNAME_LENGTH];
    directory_entry d[1];   /* Will usually have many more entries  */
} directory;

#ifdef COMMON
#  define MIDDLE_INITIAL   'C'
#else
#  define MIDDLE_INITIAL   'S'
#endif

/*
 * Flags for the UPDATED field
 */

#define D_WRITE_OK  1
#define D_UPDATED   2
#define D_COMPACT   4
#define D_PENDING   8

extern directory *fasl_files[MAX_FASL_PATHS];
#define PDS_INPUT   0
#define PDS_OUTPUT  1
#define PDS_PENDING 2
extern directory *open_pds(char *name, int mode);
extern CSLbool finished_with(int h);

#endif /* header_stream_h */

/* end of stream.h */
