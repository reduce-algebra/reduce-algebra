// stream.h                              Copyright (C) Codemist, 1995-2021
//
// Header defining the structure of stream objects in CSL, and also
// the format for "library" files used with the fast-load mechanism.
//


/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

#ifndef header_stream_h
#define header_stream_h 1

extern std::FILE *non_terminal_input;
extern int terminal_pushed;

typedef int character_stream_reader(LispObject);
typedef int character_stream_writer(int, LispObject);
typedef int32_t other_stream_op(int32_t, LispObject);

extern LispObject Lopen(LispObject env, LispObject name, LispObject dir);

//
// The values used here are placed where characters might be, or possibly
// OR'd with character codes. They are now such that even if I am using
// 21-bit characters (Unicode) all ought to be well. Anything that can be
// treated as a character (including an end of file marker) will be limited
// to                   0x001fffff
// so these two bits are well out of the way.
//
#define ESCAPED_CHAR    0x20000000
#define NOT_CHAR        0x40000000

extern int char_to_terminal(int c, LispObject f);
extern int char_to_file(int c, LispObject f);
extern int char_to_pipeout(int c, LispObject f);
extern int char_to_synonym(int c, LispObject f);
extern int char_to_broadcast(int c, LispObject f);
extern int char_to_illegal(int c, LispObject f);
extern int char_to_list(int c, LispObject f);
extern int code_to_list(int c, LispObject f);
extern int count_character(int c, LispObject f);
extern int binary_outchar(int c, LispObject f);
extern int char_to_function(int c, LispObject f);

#if defined HAVE_LIBFOX || defined HAVE_LIBWX
extern int char_to_math(int c, LispObject f);
extern int char_to_spool(int c, LispObject f);
#endif

extern int32_t write_action_terminal(int32_t c, LispObject f);
extern int32_t write_action_file(int32_t c, LispObject f);
extern int32_t write_action_pipe(int32_t c, LispObject f);
extern int32_t write_action_synonym(int32_t c, LispObject f);
extern int32_t write_action_broadcast(int32_t c, LispObject f);
extern int32_t write_action_twoway(int32_t c, LispObject f);
extern int32_t write_action_illegal(int32_t c, LispObject f);
extern int32_t write_action_list(int32_t c, LispObject f);

#if defined HAVE_LIBFOX || defined HAVE_LIBWX
extern int32_t write_action_math(int32_t c, LispObject f);
extern int32_t write_action_spool(int32_t c, LispObject f);
#endif

extern int char_from_terminal(LispObject f);
extern int char_from_file(LispObject f);
extern int char_from_pipe(LispObject f);
extern int char_from_synonym(LispObject f);
extern int char_from_concatenated(LispObject f);
extern int char_from_echo(LispObject f);
extern int char_from_illegal(LispObject f);
extern int char_from_list(LispObject f);
extern int char_from_vector(LispObject f);

extern int32_t read_action_terminal(int32_t c, LispObject f);
extern int32_t read_action_file(int32_t c, LispObject f);
extern int32_t read_action_output_file(int32_t c, LispObject f);
extern int32_t read_action_synonym(int32_t c, LispObject f);
extern int32_t read_action_concatenated(int32_t c, LispObject f);
extern int32_t read_action_echo(int32_t c, LispObject f);
extern int32_t read_action_twoway(int32_t c, LispObject f);
extern int32_t read_action_illegal(int32_t c, LispObject f);
extern int32_t read_action_list(int32_t c, LispObject f);
extern int32_t read_action_vector(int32_t c, LispObject f);

#define MAX_PROMPT_LENGTH 80
extern char memory_print_buffer[MAX_PROMPT_LENGTH];

//
// The following typedef shows the expected layout of a Lisp_STREAM object,
// but it is not used directly because I need to insist that each field is
// exactly CELL wide. Thus when I access things that contain pointers I
// will perform horrible casts. This is essential if I am to be able to host
// this system on certain 64-bit systems.
//
//  typedef struct Lisp_STREAM
//  {
//      Header h;                              0
//      LispObject type;                       CELL
//      LispObject write_data;                 2*CELL
//      LispObject read_data;                  3*CELL
//      FILE *file;                            4*CELL
//      character_stream_writer *write_fn;     5*CELL
//      other_stream_op *write_other_fn;       6*CELL
//      intptr_t line_length;                  7*CELL
//      intptr_t byte_pos;                     8*CELL
//      intptr_t char_pos;                     9*CELL
//      character_stream_reader *read_fn;      10*CELL
//      other_stream_op *read_other_fn;        11*CELL
//      intptr_t pushed_char;                  12*CELL
//      intptr_t spare;                        13*CELL
//  } Lisp_STREAM;
//
// Now in fact I could make STREAM objects longer than this provided I
// accept that if a stream is moved from a 32 to a 64-bit world its length
// will alter. If the extra space is for use as a buffer that feels OK to me
// because the stream should not be active while it is being dumped and
// re-loaded. I can use stream_spare to tell me where the buffer begins.
// So here I am now putting STREAM_BUFFER_SIZE bytes at the end of each
// STREAM object, and that will be 64K on a 64-bit machine and 32K on
// a 32-bit one. I am not yet doing that and may not need to until and unless
// I make the code here multi-threaded.
//

#define STREAM_BUFFER_SIZE    (8192*CELL)
#define STREAM_SIZE           (14*CELL)
#define BUFFERED_STREAM_SIZE  (STREAM_SIZE+STREAM_BUFFER_SIZE)

inline atomic<LispObject> &stream_type(LispObject v)
{   return basic_elt(v, 0);
}
inline atomic<LispObject> &stream_write_data(LispObject v)
{   return basic_elt(v, 1);
}
inline atomic<LispObject> &stream_read_data(LispObject v)
{   return basic_elt(v, 2);
}
inline atomic<std::FILE *> &stream_file(LispObject v)
{   return (atomic<std::FILE *>&)basic_elt(v, 3);
}
inline atomic<character_stream_writer *> &stream_write_fn(
    LispObject v)
{   return (atomic<character_stream_writer *>&)basic_elt(v, 4);
}
inline atomic<other_stream_op *> &stream_write_other(LispObject v)
{   return (atomic<other_stream_op *>&)basic_elt(v,5);
}
inline atomic<LispObject> &stream_line_length(LispObject v)
{   return basic_elt(v, 6);
}
inline atomic<LispObject> &stream_byte_pos(LispObject v)
{   return basic_elt(v, 7);
}
inline atomic<LispObject> &stream_char_pos(LispObject v)
{   return basic_elt(v, 8);
}
inline atomic<character_stream_reader *> &stream_read_fn(LispObject v)
{   return (atomic<character_stream_reader *>&)basic_elt(v, 9);
}
inline atomic<other_stream_op *> &stream_read_other(LispObject v)
{   return (atomic<other_stream_op *>&)basic_elt(v,10);
}
inline atomic<LispObject> &stream_pushed_char(LispObject v)
{   return basic_elt(v, 11);
}
inline atomic<LispObject> &stream_spare(LispObject v)
{   return basic_elt(v, 12);
}

inline LispObject set_stream_file(LispObject v, std::FILE *x)
{   return (basic_elt(v, 3) = reinterpret_cast<LispObject>(x));
}
inline LispObject set_stream_write_fn(LispObject v,
                                      character_stream_writer *x)
{   return (basic_elt(v, 4) = reinterpret_cast<LispObject>(x));
}
inline LispObject set_stream_write_other(LispObject v,
        other_stream_op *x)
{   return (basic_elt(v, 5) = reinterpret_cast<LispObject>(x));
}
inline LispObject set_stream_read_fn(LispObject v,
                                     character_stream_reader *x)
{   return (basic_elt(v, 9) = reinterpret_cast<LispObject>(x));
}
inline LispObject set_stream_read_other(LispObject v,
                                        other_stream_op *x)
{   return (basic_elt(v, 10) = reinterpret_cast<LispObject>(x));
}

#define STREAM_HEADER (TAG_HDR_IMMED + TYPE_STREAM + (STREAM_SIZE<<(Tw+5)))
#define STREAM_FLAG_PIPE       1

inline bool is_stream(LispObject v)
{   return (is_vector(v) && vechdr(v).load() == STREAM_HEADER);
}

inline int putc_stream(int c, LispObject f)
{   character_stream_writer *fn = stream_write_fn(f);
    return (*fn)(c & 0xff, f);
}

inline int getc_stream(LispObject f)
{   character_stream_reader *fn = stream_read_fn(f);
    return (*fn)(f);
}

inline int32_t other_write_action(int32_t c, LispObject f)
{   other_stream_op *fn = stream_write_other(f);
    return (*fn)(c, f);
}

inline int32_t other_read_action(int32_t c, LispObject f)
{   other_stream_op *fn = stream_read_other(f);
    return (*fn)(c, f);
}

//
// For other_write_action if the top four bits of the operand select an
// action to be performed, while the remaining 28 are available to pass
// an operand.
//

#define WRITE_GET_INFO        0x00000000
#  define WRITE_GET_LINE_LENGTH        0
#  define WRITE_GET_COLUMN             1
#  define WRITE_IS_CONSOLE             2
#define WRITE_CLOSE                  0x10000000
#define WRITE_FLUSH                  0x20000000
#define WRITE_SET_LINELENGTH         0x30000000
#define WRITE_SET_COLUMN             0x40000000
#define WRITE_SET_LINELENGTH_DEFAULT 0x50000000

//
// For other_read_action() if the operand is in the range -1 to 0x10ffff then
// it is a character to be unread (-1 is used for EOF). Otherwise if the most
// significant bit is a "1" then the request is a seek (with a 31-bit address
// within the stream to go to).  The remaining few cases are things that do
// not need additional data passed.
//
#define READ_SEEK          0x80000000
#define READ_TELL          0x40000000
#define READ_CLOSE         0x40000001
#define READ_FLUSH         0x40000002
#define READ_IS_CONSOLE    0x40000003
#define READ_END           0x40000004

// Print options...

#define escape_yes          0x0001    // make output re-readable

#define escape_fold_down    0x0002    // force lower case output
#define escape_fold_up      0x0004    // FORCE UPPER CASE OUTPUT
#define escape_capitalize   0x0008    // Force Capitalisation (!)

#define escape_binary       0x0010    // print format for numbers
#define escape_octal        0x0020    // (including bignums)
#define escape_hex          0x0040
#define escape_nolinebreak  0x0080    // use infinite line-length
#define escape_hexwidth     0x3f00    // 6 bits to specify width of hex/bin
#define escape_width(n)     (((n) & escape_hexwidth) >> 8)
#define escape_checksum     0x4000    // doing a checksum operation
#define escape_exploding    0x8000    // in explode, exploden etc


extern LispObject make_stream_handle(void);
extern bool use_wimp;

extern character_reader *procedural_input;
extern character_writer *procedural_output;

extern directory *rootDirectory;
#define PDS_INPUT   0
#define PDS_OUTPUT  1
#define PDS_PENDING 2
extern directory *open_pds(const char *name, int mode);
extern bool finished_with(int h);

#endif // header_stream_h

// end of stream.h
