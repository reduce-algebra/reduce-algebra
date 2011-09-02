/* stream.h                        Copyright (C) Codemist Ltd, 1995-2002 */

/*
 * Header defining the structure of stream objects in CSL, and also
 * the format for "library" files used with the fast-load mechanism.
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */



/* Signature: 60bfaf41 08-Apr-2002 */

#ifndef header_stream_h
#define header_stream_h 1

extern FILE *non_terminal_input;

typedef int character_reader(void); /* used only with procedural IO */
typedef int character_writer(int);  /* ditto */

typedef int character_stream_reader(Lisp_Object);
typedef int character_stream_writer(int, Lisp_Object);
typedef int32 other_stream_op(int32, Lisp_Object);

extern Lisp_Object Lopen(Lisp_Object nil, Lisp_Object name, Lisp_Object dir);

/*
 * The values used here are placed where characters might be, or possibly
 * OR'd with character codes. They are now such that even if I am using
 * 16-bit characters (Unicode of Kanji) all ought to be well.
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

extern int32 write_action_terminal(int32 c, Lisp_Object f);
extern int32 write_action_file(int32 c, Lisp_Object f);
extern int32 write_action_pipe(int32 c, Lisp_Object f);
extern int32 write_action_synonym(int32 c, Lisp_Object f);
extern int32 write_action_broadcast(int32 c, Lisp_Object f);
extern int32 write_action_twoway(int32 c, Lisp_Object f);
extern int32 write_action_illegal(int32 c, Lisp_Object f);
extern int32 write_action_list(int32 c, Lisp_Object f);

extern int char_from_terminal(Lisp_Object f);
extern int char_from_file(Lisp_Object f);
extern int char_from_synonym(Lisp_Object f);
extern int char_from_concatenated(Lisp_Object f);
extern int char_from_echo(Lisp_Object f);
extern int char_from_illegal(Lisp_Object f);
extern int char_from_list(Lisp_Object f);
extern int char_from_vector(Lisp_Object f);

extern int32 read_action_terminal(int32 c, Lisp_Object f);
extern int32 read_action_file(int32 c, Lisp_Object f);
extern int32 read_action_output_file(int32 c, Lisp_Object f);
extern int32 read_action_synonym(int32 c, Lisp_Object f);
extern int32 read_action_concatenated(int32 c, Lisp_Object f);
extern int32 read_action_echo(int32 c, Lisp_Object f);
extern int32 read_action_twoway(int32 c, Lisp_Object f);
extern int32 read_action_illegal(int32 c, Lisp_Object f);
extern int32 read_action_list(int32 c, Lisp_Object f);
extern int32 read_action_vector(int32 c, Lisp_Object f);

extern char memory_print_buffer[32];

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
 *      intxx line_length;                      7*CELL
 *      intxx char_pos;                         8*CELL
 *      character_stream_reader *read_fn;       9*CELL
 *      other_stream_op *read_other_fn;        10*CELL
 *      intxx pushed_char;                     11*CELL
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
#define putc_stream(c, f)          (!is_stream(f) || stream_write_fn(f)==0 ? term_printf("putc %s %d\n", \
        __FILE__, __LINE__), ensure_screen(), my_exit(1), 0 : \
         stream_write_fn(f)(c, f))
#define getc_stream(f)             (!is_stream(f) || stream_read_fn(f)==0 ? term_printf("putc %s %d\n", \
        __FILE__, __LINE__), ensure_screen(), my_exit(1), 0 : \
         stream_read_fn(f)(f))
#define other_write_action(c, f)   (!is_stream(f) || stream_write_other(f)==0 ? term_printf("putc %s %d\n", \
        __FILE__, __LINE__), ensure_screen(), my_exit(1), 0 : \
         stream_write_other(f)(c, f))
#define other_read_action(c, f)    (!is_stream(f) || stream_read_other(f)==0 ? term_printf("putc %s %d\n", \
        __FILE__, __LINE__), ensure_screen(), my_exit(1), 0 : \
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
 * This version of the directory structure can cope with up to 2047
 * modules in any single library.
 */

#if defined DEMO_BUILD || defined DEMO_MODE
#define IMAGE_FORMAT_VERSION       'd'
#else
#define IMAGE_FORMAT_VERSION       '4'
#endif

#ifndef DIRECTORY_SIZE
#  define DIRECTORY_SIZE            8    /* Initial directory size */
#endif

typedef struct directory_header
{
    char C, S, L, version;  /* Identification                       */
    unsigned char dirext,   /* Extra bits for dirused, dirsize      */
                  dirsize,  /* Number of directory entries provided */
                  dirused,  /* Number currently in use              */
                  updated;  /* In need of compaction & other flags  */
    char eof[4];            /* fseek/ftell location of end of file  */
} directory_header;

#define get_dirused(d) ((int)((d).dirused + (((d).dirext & 0x0f)<<8)))
#define get_dirsize(d) ((int)((d).dirsize + (((d).dirext & 0xf0)<<4)))

typedef struct directory_entry
{
    char data[44];
/*
    char newline;                * Makes file easier to read as a text file! *
                                 * but also used to indicate encryption *
    char name[12];               * blank padded to 12 characters *
                                 * but with special rules for root image etc *
    char date[24];
    char position[4];            * Machine byte-order insensitive format *
    char size[3];                * Ditto *
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

#define DIRNAME_LENGTH  64
#define NEWLINE_CHAR    0x0a
/*
 * The D_newline location in a directory originally held a newline,
 * because doing so resulted in image files being a little bit easier
 * to interpret when looked at with a simple text editor. But then
 * it turned out that the C value `\n' was not the same on all computers,
 * and so I used a literal hex value 0x0a instead, expecting it to
 * be the same as '\n' on "most" systems. Yet later I wanted a backwards-
 * compatible way to extend dierctory entries to indicate that some files
 * are stored encrypted. The route follows is that unencrypted files
 * have NEWLINE_CHAR in the D_newline position, while values that + n
 * indicate files encrypted with key number n. Note that if I try to
 * read an encrypted sub-file but my key is wrong I will just get garbage
 * bytes back, so all code that handles files from the image will need
 * to be prepared to respond tolerably gracefully to such a situation.
 * I already have a CRC check at the end of every sub-file, but often
 * that will be too late, and anyway I may need to review that to ensure that
 * it actually checksums the plain-text not the cipher text.
 */

typedef struct directory
{
    directory_header h;
    FILE *f;
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
extern directory *open_pds(char *name, CSLbool forinput);
extern CSLbool finished_with(int h);

#endif /* header_stream_h */

/* end of stream.h */
